# 📅 Event Management System (DSA Project in C)

This project is a simple **Event Management System** implemented in **C language** using **Singly Linked Lists** and **Queue data structures**. Designed as a Data Structures and Algorithms (DSA) semester project, it simulates event planning, cost estimation, and queue processing based on user-defined events.

---

## 📌 Features

- 📋 Add new events with name, date, and base cost
- 🏷️ Add multiple custom attributes to each event (e.g., decoration, catering, etc.)
- ❗ Detect and warn about date clashes
- 💸 Estimate total event cost (base + all attributes)
- 🧾 View all events and their details
- 🔄 Queue-based processing of events (FIFO)
- 🧹 Graceful memory deallocation to avoid leaks

---

## 🧠 Concepts Used

- Singly Linked Lists
- Queues (custom implementation)
- Structs and Dynamic Memory Allocation (`malloc`, `free`)
- Menu-driven programming
- String handling and pointer management

---

## 🛠️ Tech Stack

| Component     | Technology     |
|---------------|----------------|
| Language      | C              |
| IDE/Compiler  | GCC / Code::Blocks / VS Code / Turbo C++ |
| Data Structure| Linked List, Queue |
| Platform      | Command Line Interface (CLI) |

---


---
📸 Sample Output

📋 Menu Options

===== Event Management System =====
1. Add Event
2. Display Events
3. Process Event Queue
4. Exit

🔍 Sample Use Case
Input:

Event Name: "Tech Fest"

Date: "25-08-2025"

Base Cost: ₹10,000

Attributes:

Stage Setup: ₹5,000

Sound System: ₹2,000

📅 Event: Tech Fest
   Date: 25-08-2025
   Base Cost: 10000.00
   Attributes:
     - Stage Setup (Cost: 5000.00)
     - Sound System (Cost: 2000.00)
   Estimated Total Cost: 17000.00

♻️ Future Enhancements
Add file I/O support to save/load event data

Add sorting options (by date, cost, name)

Add login-based access for admin/students

Use doubly linked list for reverse traversal

GUI-based frontend using GTK or C++ Qt

🙋‍♀️ Author
Samrah Sayyed
3rd Year Undergraduate
Department of Electrical and Electronics Engineering
