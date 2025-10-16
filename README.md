# Small-Scale-Chat-Network-Application-
# 🗨️ Simple UDP Chat App

This is a lightweight, terminal-based chat program written in C that lets two people talk to each other over a network using **UDP**. It's designed to be simple, fast, and easy to run — just give it an IP address and start chatting!

---

## 📋 What It Does

- Sends and receives messages over UDP
- Lets you chat in real time from the terminal
- Displays sent and received messages side by side
- Automatically ends the chat when someone types `QUIT`

Perfect for learning basic networking or testing out UDP communication.

---

## 🛠 How to Use It

### 1. Compile the Program
```bash
gcc -o chat chat.c

### 2. Run it on both machines
./chat <REMOTE_IPV4_ADDRESS>
