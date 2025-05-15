# Hotel Management System (C++)

This is a simple **Hotel Management System** project written in **C++**. It demonstrates Object-Oriented Programming (OOP) concepts like inheritance, polymorphism, and dynamic memory management using destructors.

## 🛠️ Features

- Show all rooms (Standard and Deluxe)
- Show available rooms
- Book a room for a customer
- Show all customers
- Place food orders via menu
- Console-based menu system

## 🧱 OOP Concepts Used

- **Encapsulation**: Using classes to group data and related methods.
- **Inheritance**: `DeluxeRoom` and `StandardRoom` inherit from `Room`.
- **Polymorphism**: `displayInfo()` and `getRoomType()` functions are overridden in child classes.
- **Destructor**: Proper memory cleanup using `~Hotel()` destructor.

## 📋 Menu Example

```plaintext
====================================
      Welcome to Hotel Management
====================================
1. Show All Rooms
2. Show Available Rooms
3. Book a Room
4. Show All Customers
5. Place an Order
0. Exit
