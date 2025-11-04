# 🔗 Linked List Implementation in C

This repository contains a **menu-driven program** written in **C language** to perform various operations on a **singly linked list**.  
The program dynamically allocates memory for each node and allows insertion, deletion, searching, and display operations.

---

## 🚀 Features

- ✅ Insert node at the **beginning**
- ✅ Insert node at a **specific (random) position**
- ✅ Insert node at the **end**
- ✅ Delete node from the **beginning**
- ✅ Delete node from a **specific position**
- ✅ Delete node from the **end**
- ✅ **Search** for a node by value
- ✅ **Display** all nodes in the list

---

## 🧠 Data Structure Used

Each node of the linked list contains:
```c
struct Node {
    int data;
    struct Node *next;
};
