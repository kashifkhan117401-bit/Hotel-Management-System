#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

// Abstract Room class
class Room {
protected:
    int roomNumber;
    string type;
    double basePrice;
    bool available;
    vector<string> features;

public:
    Room(int rn, string t, double bp) : roomNumber(rn), type(t), basePrice(bp), available(true) {}

    virtual double calculateBill(int days) const = 0;
    virtual void displayInfo() const = 0;

    void bookRoom() { available = false; }
    void vacateRoom() { available = true; }
    bool isRoomAvailable() const { return available; }
    int getRoomNumber() const { return roomNumber; }
    string getType() const { return type; }
    double getBasePrice() const { return basePrice; }
};

class DeluxeRoom : public Room {
public:
    DeluxeRoom(int rn) : Room(rn, "Deluxe", 150.0) {
        features = {"Smart Lock", "Ocean View"};
    }
    double calculateBill(int days) const override {
        return days * (basePrice + 20.0); // includes service fee
    }
    void displayInfo() const override {
        cout << "Room " << roomNumber << " (Deluxe) - $" << basePrice << "/day\nFeatures: Smart Lock, Ocean View\n";
    }
};

class SuiteRoom : public Room {
public:
    SuiteRoom(int rn) : Room(rn, "Suite", 200.0) {
        features = {"Smart Lock", "Ocean View", "Mini Bar"};
    }
    double calculateBill(int days) const override {
        return days * (basePrice + 50.0); // includes luxury tax
    }
    void displayInfo() const override {
        cout << "Room " << roomNumber << " (Suite) - $" << basePrice << "/day\nFeatures: Smart Lock, Ocean View, Mini Bar\n";
    }
};

class StandardRoom : public Room {
public:
    StandardRoom(int rn) : Room(rn, "Standard", 100.0) {
        features = {"Smart Lock"};
    }
    double calculateBill(int days) const override {
        return days * basePrice;
    }
    void displayInfo() const override {
        cout << "Room " << roomNumber << " (Standard) - $" << basePrice << "/day\nFeatures: Smart Lock\n";
    }
};

// Customer class
class Customer {
public:
    string name, contact, idNumber;
    int bookedRoomNumber, daysOfStay;
    string checkInDate, checkOutDate;
    int loyaltyPoints;

    Customer() : loyaltyPoints(0), bookedRoomNumber(-1) {}

    void assignRoom(int rn, int days) {
        bookedRoomNumber = rn;
        daysOfStay = days;
        updateLoyaltyPoints();
    }

    void updateLoyaltyPoints() {
        loyaltyPoints += daysOfStay * 5;
    }

    void displayCustomerDetails() const {
        cout << "Customer: " << name << "\nRoom No: " << bookedRoomNumber << "\nDays: " << daysOfStay << "\nPoints: " << loyaltyPoints << "\n";
    }
};

// Booking class
class Booking {
public:
    static int nextID;
    int bookingID;
    Customer customer;
    Room* room;
    string bookingDate;
    string status;

    Booking(Customer c, Room* r, string date)
        : customer(c), room(r), bookingDate(date), status("Confirmed") {
        bookingID = nextID++;
    }

    void displayBookingDetails() const {
        cout << "Booking ID: " << bookingID << "\nDate: " << bookingDate << "\nStatus: " << status << "\n";
        customer.displayCustomerDetails();
        room->displayInfo();
    }
};

int Booking::nextID = 1000;

// Admin class
class Admin {
    string username = "admin";
    string password = "1234";

public:
    bool login() {
        string u, p;
        cout << "Enter Admin Username: "; cin >> u;
        cout << "Enter Admin Password: "; cin >> p;
        return (u == username && p == password);
    }
};

// Hotel class
class Hotel {
    vector<Room*> rooms;
    vector<Booking> bookings;
    vector<Customer> customers;

public:
    Hotel() {
        for (int i = 1; i <= 3; ++i) rooms.push_back(new DeluxeRoom(i));
        for (int i = 4; i <= 6; ++i) rooms.push_back(new SuiteRoom(i));
        for (int i = 7; i <= 10; ++i) rooms.push_back(new StandardRoom(i));
    }

    ~Hotel() {
        for (auto r : rooms) delete r;
    }

    void listAvailableRooms() const {
        cout << "\n--- Available Rooms ---\n";
        for (auto r : rooms)
            if (r->isRoomAvailable()) r->displayInfo();
    }

    Room* findAvailableRoomByType(const string& type) {
        for (auto r : rooms)
            if (r->isRoomAvailable() && r->getType() == type)
                return r;
        return nullptr;
    }

    void bookRoom() {
        string type;
        cout << "Enter Room Type to Book (Standard/Deluxe/Suite): ";
        cin >> type;
        Room* room = findAvailableRoomByType(type);

        if (!room) {
            cout << "No " << type << " rooms available right now.\n";
            return;
        }

        Customer cust;
        cout << "Enter Name: "; cin >> cust.name;
        cout << "Enter Contact: "; cin >> cust.contact;
        cout << "Enter ID Number: "; cin >> cust.idNumber;
        int days;
        cout << "Days of stay: "; cin >> days;
        cust.assignRoom(room->getRoomNumber(), days);
        room->bookRoom();
        bookings.emplace_back(cust, room, "2025-06-20");
        customers.push_back(cust);
        cout << "Room Booked Successfully!\n";
    }

    void generateInvoice() const {
        int roomNo;
        cout << "Enter Room Number for Invoice: "; cin >> roomNo;
        for (auto& b : bookings) {
            if (b.room->getRoomNumber() == roomNo) {
                double cost = b.room->calculateBill(b.customer.daysOfStay);
                cout << fixed << setprecision(2);
                cout << "\n--- Invoice ---\nRoom: " << roomNo << "\nBase Cost: $" << cost;
                cout << "\nLoyalty Discount: -$" << (b.customer.loyaltyPoints > 50 ? 20 : 0);
                cout << "\nFinal Amount: $" << (cost - (b.customer.loyaltyPoints > 50 ? 20 : 0)) << "\n";
                return;
            }
        }
        cout << "No booking found for that room.\n";
    }

    void checkOut() {
        int roomNo;
        cout << "Enter Room Number to Checkout: "; cin >> roomNo;
        for (auto& r : rooms) {
            if (r->getRoomNumber() == roomNo && !r->isRoomAvailable()) {
                r->vacateRoom();
                cout << "Checked out. Room now available.\n";
                return;
            }
        }
        cout << "Room not found or already available.\n";
    }
};

int main() {
    Hotel hotel;
    Admin admin;
    if (!admin.login()) {
        cout << "Access Denied.\n";
        return 0;
    }

    int choice;
    do {
        cout << "\n--- HOTEL MENU ---\n1. List Available Rooms\n2. Book Room\n3. Invoice\n4. Checkout\n5. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: hotel.listAvailableRooms(); break;
            case 2: hotel.bookRoom(); break;
            case 3: hotel.generateInvoice(); break;
            case 4: hotel.checkOut(); break;
            case 5: cout << "Goodbye!\n"; break;
            default: cout << "Invalid option.\n";
        }
    } while (choice != 5);

    return 0;
}
