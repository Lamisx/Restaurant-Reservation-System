# Restaurant Reservation System (RRS)

## Overview
The **Restaurant Reservation System (RRS)** is a C++ project developed as part of a Data Structures course. It simulates a restaurant table reservation and payment system using linked lists to manage reservation data and table availability. The system allows users to create reservations, check table availability, cancel bookings, make payments, and calculate daily profits, with input validation for phone numbers, dates, and times.

This project demonstrates the application of fundamental data structures (linked lists) and object-oriented programming principles to solve a real-world problem.

---

## Features
1. **Reservation Management**
   - Add a new reservation with details such as name, phone number, date, time, and number of people.
   - Validate phone numbers (must start with "05" and be 10 digits), dates (YYYY-MM-DD format), and times (4 PM to 12 AM).
   - Automatically calculate the required number of tables based on the number of people.

2. **Table Availability**
   - Check and reserve tables for a specific date and time (4 PM to 12 AM, with 10 tables available per hour).
   - Cancel reservations and restore table availability.

3. **Payment System**
   - Process payments for reservations with a minimum bill of 250 SAR (deducting a 150 SAR deposit).
   - Update reservation status to "Completed" upon successful payment.

4. **Search and Cancellation**
   - Search for reservations by phone number and display reservation details.
   - Cancel reservations and refund deposits if applicable.

5. **Daily Profit Calculation**
   - Calculate total profit for a specific date based on completed reservations.

---

## File Structure
- **`tables.h`**: Header file for the `tables` class, which manages table availability using a linked list.
- **`tables.cpp`**: Implementation of the `tables` class, including functions to create nodes, reserve/cancel tables, and check availability.
- **`Reservation.h`**: Header file for the `Reservation` class, defining the structure and methods for managing reservations.
- **`Reservation.cpp`**: Implementation of the `Reservation` class, including reservation creation, payment, cancellation, and profit calculation.
- **`main.cpp`**: Main program file with a menu-driven interface to interact with the system.

---

## Prerequisites
- A C++ compiler (e.g., GCC, Visual Studio, Dev-C++).
- Basic knowledge of linked lists and object-oriented programming.

---

## How to Use
1. **Compile the Program**
   - Compile all `.cpp` files together using a C++ compiler. For example:
     ```
     g++ main.cpp tables.cpp Reservation.cpp -o RRS
     ```
2. **Run the Program**
   - Execute the compiled file:
     ```
     ./RRS
     ```
3. **Interact with the Menu**
   - Choose from the following options:
     1. Add a reservation.
     2. Search for a reservation.
     3. Make a payment.
     4. Cancel a reservation.
     5. Calculate daily income.
     6. Exit.

4. **Input Guidelines**
   - Phone numbers must start with "05" and be 10 digits (e.g., 0512345678).
   - Dates must follow the "YYYY-MM-DD" format (e.g., 2025-02-23).
   - Reservation times must be between 4 PM and 12 AM (enter as 4 to 12).

---

## Example Usage
```
Welcome to the Restaurant Reservation System (RRS)....
Please choose from the following menu:
1-Add reservation.
2-Search for a reservation.
3-Make a payment.
4-Cancel a reservation.
5-Daily income.
6-Exit.

Enter your choice: 1
Enter your name: Ali
Enter your phone number (starting with 05,10 digits): 0512345678
Enter date of reservation (e.g., YYYY-MM-DD): 2025-02-23
Enter number of people: 8
Enter hour of reservation (4 PM to 12 AM): 6
Enter deposit amount: 150
Deposit of 150 successfully made.
----------------------------------------------------------------
|                    Reservation Information                    |
----------------------------------------------------------------
|Name: Ali
|Phone Number: 0512345678
|Date: 2025-02-23
|Time: 6
|Number of People: 8
|Status: Confirmed
 ---------------------------------------------------------------
```

---

## Notes
- The system assumes a fixed number of 10 tables per hour from 4 PM to 12 AM.
- Reservations require a minimum deposit of 150 SAR, and payments must be at least 250 SAR to complete.
- The project uses linked lists to store reservation and table data, showcasing dynamic memory allocation and traversal.
- Some functions (e.g., `calculateDailyProfit`) rely on completed reservations having a valid `thepay` value set during payment.

---

## Future Improvements
- Add file I/O to save and load reservation data.
- Implement a graphical user interface (GUI) for better usability.
- Support multiple restaurants or table types (e.g., small, large).
- Add error handling for edge cases like duplicate reservations.

---

Credits
Developed by the following team from Qassim University under the supervision of Dr. Samar Al-Duaiji for the Data Structures course:


(Waad Al-Anzi) - [GitHub]
Hanan Al-Rashidi - GitHub
Joury Al-Muhaimid - GitHub
Lamis Al-Harbi - GitHub
Layan Al-Suwailim - GitHub
 - [Rawan Al-Shammasan](https://github.com/rawana1)
---
