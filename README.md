# get_next_line – 42 Project

Implementation of **get_next_line**, a function that reads a line from a file descriptor, one call at a time.  
This project is part of the 42 cursus and is focused on **file I/O, buffer management, and dynamic memory allocation in C**.

---

## 📚 What’s inside?

- **Core function:**
  - `get_next_line(int fd)` → reads from a given file descriptor and returns the next line (including the newline character `\n` if present).

- **Features:**
  - Works with **files, standard input, and even pipes**.
  - Handles **different buffer sizes** defined at compile time via `-D BUFFER_SIZE=xx`.
  - Manages memory dynamically to handle arbitrarily long lines.
  - Supports **multiple file descriptors at once**.

---

## 🧑‍💻 What I learned

- How to properly use **read()** system call and handle its return values.  
- The importance of **buffering** and reusing leftover data between function calls.  
- Managing **static variables** to store persistent state between executions of the function.  
- Handling **edge cases**:
  - Empty files.  
  - Files without newline characters at the end.  
  - Large files with very long lines.  
- Improved my skills in **dynamic memory allocation** (`malloc`, `free`) and **string manipulation** in C.  

---

Thank you for checking out my get_next_line project — it was a huge step in learning how to control data flow and memory at a low level in C!
