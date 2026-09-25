# Railway Reservation System 🚆

A console-based **Railway Reservation System developed in C++** as a beginner-level college project. The project demonstrates the use of classes, structures, arrays, functions, pointers, loops, conditional statements, and basic data management in C++.

## Features

* 🚆 View all available trains
* 🔍 Search trains using train ID
* 💺 Check seat availability by class
* 🎫 Book railway tickets
* 👤 Store passenger information
* 🪑 Assign seat numbers based on selected class
* 💰 Calculate total fare according to ticket quantity
* 🎟️ Generate and display railway tickets
* 🔎 View tickets using ticket number
* ❌ Cancel booked tickets
* 📋 View active booking history
* 🔢 Generate unique ticket numbers
* 📊 Maintain separate seat availability for Sleeper, 3AC, and 2AC classes

## Technologies Used

* **Language:** C++
* **Concepts:** Classes, Structures, Arrays, Functions, Pointers, Loops, Conditional Statements, Switch Cases, Strings, Random Number Generation
* **Environment:** Console / Terminal

## Project Structure

The system maintains information about:

* Train details
* Passenger details
* Seat availability
* Ticket information
* Booking history
* Ticket collections for individual trains

The project currently uses arrays for storing train and ticket information, making it suitable for understanding fundamental C++ programming and basic data management.

## How It Works

When the program starts, it initializes the available trains and displays a menu with different operations:

```text
1. View all Trains
2. Search Train
3. Check Seat Availability
4. Book Ticket
5. View Ticket
6. Cancel Ticket
7. View Booking History
8. Exit
```

During booking, the user selects a train, chooses a class, enters the required number of seats, and provides passenger information. The system then generates a ticket number, assigns a seat number, calculates the total fare, updates the available seats, and displays the generated ticket.

## Purpose

This project was created to practice and apply fundamental **C++ programming concepts** by developing a practical console-based application resembling a basic railway reservation system.

## Future Improvements

Possible improvements include:

* Persistent storage using files or a database
* Multiple passenger details under a single booking
* More realistic seat allocation
* Improved cancellation and seat reassignment
* Login and user authentication
* Admin functionality for managing trains
* Better input validation
* Graphical user interface
* Dynamic train and route management
