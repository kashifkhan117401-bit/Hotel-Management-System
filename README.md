<div align="center">

# 🏨 Hotel Management System

### A Console-Based OOP Simulation in C++

*Booking · Billing · Customer Management · Admin Control*

![C++](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![OOP](https://img.shields.io/badge/Paradigm-OOP-6C3EF4?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen?style=for-the-badge)
![License](https://img.shields.io/badge/License-Academic-orange?style=for-the-badge)

</div>

<br>

> A console-based Hotel Management System built to demonstrate core **Object-Oriented Programming** principles — abstraction, inheritance, polymorphism, composition, and encapsulation — through a realistic hotel booking workflow.

<br>

## 📋 Project Overview

This project simulates the core operations of a hotel — room booking, customer management, billing, and administrative access control — all through a simple, menu-driven console interface.

<div align="center">

| Field | Detail |
|:---|:---|
| 🏷️ **Topic** | Hotel Management System |
| 📚 **Subject** | Object-Oriented Programming (OOP) |
| 👨‍🎓 **Student** | Kashif Hafeez |
| 🆔 **ID** | F2024376314 |
| 🧩 **Section** | A1 |
| 👨‍🏫 **Teacher** | Sir Arman Sohail |
| 📅 **Submission Date** | 22 June 2025 |

</div>

<br>

---

## ✨ Key Functionalities

<table>
<tr>
<td width="50%" valign="top">

### 🛏️ Room Booking & Management
- Room categories: **Standard**, **Deluxe**, **Suite**
- Unique features per type (Smart Lock, Ocean View, Mini Bar)
- Dynamic pricing with taxes/service fees

### 👤 Customer Handling
- Personal details & ID verification
- Loyalty points tracking
- Booking linkage and duration tracking

</td>
<td width="50%" valign="top">

### 💳 Billing System
- Tiered billing based on room type
- Automatic loyalty discounts
- Dynamic invoice generation

### 🔐 Admin Controls
- Login-based access control
- View/manage rooms
- Checkout flow to free up rooms

</td>
</tr>
</table>

### 💾 Persistence
Room status is maintained throughout the session, with booking data structured for easy extension via file handling.

### ⚠️ Exception Handling
Invalid inputs (e.g., text in numeric fields) and booking clashes are validated and handled gracefully.

<br>

---

## 🧱 OOP Concepts Demonstrated

<div align="center">

| Concept | Where It's Used |
|:---|:---|
| 🧩 **Abstraction & Pure Virtual Functions** | `Room` is an abstract base class with pure virtual `calculateBill()` and `displayInfo()` |
| 🔀 **Inheritance & Polymorphism** | `StandardRoom`, `DeluxeRoom`, and `SuiteRoom` inherit from `Room` and override its behavior |
| 🔒 **Encapsulation** | Private/protected data members exposed through public getter/setter methods |
| 🧬 **Composition** | `Hotel` manages collections of `Room`, `Booking`, and `Customer` objects |

</div>

<br>

---

## 🗂️ Class Structure

```
Room (abstract)
 ├── roomNumber, type, basePrice, available
 ├── DeluxeRoom    → $150/day + $20 service fee   | Smart Lock, Ocean View
 ├── SuiteRoom     → $200/day + $50 luxury tax     | Smart Lock, Ocean View, Mini Bar
 └── StandardRoom  → $100/day                      | Smart Lock

Customer   → guest details, stay duration, loyalty points
Booking    → links Customer ↔ Room, auto ID, status tracking
Admin      → login-based access control
Hotel      → composes Room + Booking + Customer, exposes core operations
```

<br>

---

## 📐 UML Class Diagram

The project includes a UML class diagram (`UML_Diagram.png`) illustrating the relationships between `Room`, `Customer`, `Booking`, `Hotel`, and `Admin` classes, along with their attributes and methods.

<br>

---

## 🖥️ How to Run

```bash
g++ main.cpp -o hotel_system
./hotel_system
```

<div align="center">

| 🔑 Default Admin Credentials | |
|:---|:---|
| Username | `admin` |
| Password | `1234` |

</div>

### 📖 Menu Options

| # | Option |
|:---:|:---|
| 1 | List Available Rooms |
| 2 | Book Room |
| 3 | Generate Invoice |
| 4 | Checkout |
| 5 | Exit |

<br>

---

## 🎯 Highlights

✅ Easy-to-use console interface
✅ Reusable and scalable code structure
✅ Demonstrates real-world application of OOP principles

<br>

---

## 🚀 Conclusion

The Hotel Management System project is a successful demonstration of advanced OOP concepts applied in a real-world simulation. It not only manages hotel operations but also ensures modularity and scalability for future enhancements such as a GUI, file-based persistence, and networking.

<br>

---

<div align="center">

## 👤 Author

### Kashif Hafeez

[![Email](https://img.shields.io/badge/Email-kashif.hafeez.dev%40gmail.com-D14836?style=for-the-badge&logo=gmail&logoColor=white)](mailto:kashif.hafeez.dev@gmail.com)

[![Portfolio](https://img.shields.io/badge/Portfolio-Visit-000000?style=for-the-badge&logo=vercel&logoColor=white)](https://kashifhafeez-portfolio1.vercel.app/)
[![ORCID](https://img.shields.io/badge/ORCID-0009--0002--5604--3264-A6CE39?style=for-the-badge&logo=orcid&logoColor=white)](https://orcid.org/0009-0002-5604-3264)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-Connect-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://linkedin.com/in/kashif-hafeez-545794330)
[![Instagram](https://img.shields.io/badge/Instagram-Follow-E4405F?style=for-the-badge&logo=instagram&logoColor=white)](https://www.instagram.com/i_kashiif?igsh=MTUwaTEzNTFocWs2eQ==)
[![Facebook](https://img.shields.io/badge/Facebook-Connect-1877F2?style=for-the-badge&logo=facebook&logoColor=white)](https://www.facebook.com/share/1AZ6rpfhxb/)

</div>

<br>

<div align="center">

*Submitted as part of the Object-Oriented Programming (OOP) coursework, Section A1.*

</div>


