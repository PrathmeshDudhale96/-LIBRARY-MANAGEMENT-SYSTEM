# 📚 Library Management System (C Project)

![Language](https://img.shields.io/badge/Language-C-blue)

---

## 📌 Project Overview

The **Library Management System** is a console-based application developed using the **C Programming Language**.

This system is designed to manage books in a small library by applying fundamental C programming concepts such as:

- Structures  
- Arrays  
- Functions  
- File Handling  
- Loops and Conditional Statements  

It provides a simple and user-friendly menu-driven interface that allows users to:

- Add new books  
- Search books  
- Issue books  
- Return books  
- View all book records  

This project is suitable for beginners who want to understand how real-world applications are built using core C concepts.

---

## 🛠 Technologies Used

### 💻 Programming Language
- C Programming Language

### 📚 Standard Libraries
- `stdio.h`
- `stdlib.h`
- `string.h`

---

## 🚀 Features of the System

When you run the program, the following menu appears:

```
----- MENU -----
1. Add New Book
2. Display All Books
3. Search Book
4. Issue Book
5. Return Book
6. Exit
```

### ✅ Functional Features

✔ Add new books with automatic Book ID  
✔ Display all available and issued books  
✔ Search books by title  
✔ Issue books using Book ID  
✔ Return issued books  
✔ Save data before exiting  

---

## 💾 Data Storage (File Handling)

The system stores all book records in a file named:

```
library_data.txt
```

- Data is automatically saved when exiting the program  
- Data is loaded when the program starts  
- Ensures no data loss between executions  

---

## 📂 Project Structure

```
📁 Library-Management-System
 ┣ 📄 library.c
 ┣ 📄 library_data.txt
 ┗ 📄 README.md
```

---


## 🖥 Sample Program Output

```
LIBRARY MANAGEMENT SYSTEM

----- MENU -----
1. Add New Book
2. Display All Books
3. Search Book
4. Issue Book
5. Return Book
6. Exit
Enter your choice: 1

--- Add New Book ---
Enter book title: Atomic Habits
Enter author name: James Clear

Book added successfully! Book ID: 1

----- MENU -----
Enter your choice: 2

LIBRARY BOOK RECORDS

Book ID: 1
Title: Atomic Habits
Author: James Clear
Status: Available
----------------------------------------

Enter your choice: 1

--- Add New Book ---
Enter book title: Wings of Fire
Enter author name: Dr. A. P. J. Abdul Kalam

Book added successfully! Book ID: 2

Enter your choice: 3

Search Book
Enter book title to search: Wings of Fire

Book Found!
Book ID: 2
Title: Wings of Fire
Author: Dr. A. P. J. Abdul Kalam
Status: Available

Enter your choice: 4

--- Issue Book ---
Enter Book ID to issue: 2
Enter borrower name: Prathmesh Dudhale

Book issued successfully to Prathmesh Dudhale!

Enter your choice: 5

--- Return Book ---
Enter Book ID to return: 2

Book returned by: Prathmesh Dudhale
Book returned successfully!

Enter your choice: 6

Data saved successfully!
Thank you for using Library System!
```

---
---

## 👨‍💻 Author

Developed as a C Programming practice project.

---

<p align="center">
⭐ Made By Prathmesh D ⭐
</p>
