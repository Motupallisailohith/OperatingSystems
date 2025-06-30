# 🚀 Multi-Level Queue (MLQ) Scheduling Algorithm – C Implementation

> 💡 *Experience the inner workings of OS-level process management, brought to life in C!*

---

## 📚 Concept Overview

**Multi-Level Queue Scheduling (MLQ)** is a powerful CPU scheduling algorithm where:
- Processes are grouped into **separate queues** based on their types (e.g., system, interactive, batch).
- Each queue can have **its own scheduling strategy** (like FCFS, Round Robin).
- **Queue priorities** define which set of processes gets CPU time first.

This model mimics **real-world CPU scheduling** where system responsiveness and resource optimization matter.

> 🧠 Think of it as a society of processes—each with rank, rules, and rotation.

---

## 🌟 Project Highlights

- ✅ Developed in **C Language**
- 🧭 Implements **multi-level queues** with priority and Round Robin logic
- 🧵 Simulates **process arrival, execution, and switching**
- ⏱️ Captures **Waiting Time**, **Turnaround Time**
- 📈 Displays **Gantt Chart**-style output for better clarity

---

## 🛠️ Compilation & Execution

### 🔧 Compile
```bash
gcc multilevel_queue.c -o mlq_scheduler
./mlq_scheduler
+------------------------------------------+
|       Multi-Level Queue Scheduler        |
+------------------------------------------+

Enter total number of processes: 4

--- Queue 1: System Processes (Priority Scheduling) ---
Enter priority and burst time for each process:
P1: Priority=1 Burst=4
P2: Priority=2 Burst=3

--- Queue 2: User Processes (Round Robin) ---
Time Quantum: 2
P3: Burst=6
P4: Burst=4

📊 Gantt Chart:
| P1 | P2 | P3 | P4 | P3 | P4 |

📄 Process Summary:
PID | Queue | Burst | Waiting | Turnaround
----|-------|-------|---------|-----------
P1  | Q1    |   4   |   0     |    4
P2  | Q1    |   3   |   4     |    7
P3  | Q2    |   6   |   7     |   13
P4  | Q2    |   4   |   9     |   13

📌 Average Waiting Time: 5.0  
📌 Average Turnaround Time: 9.25
                  +----------------------------+
                  |        Master Queue        |
                  +-------------+--------------+
                                |
        +-----------------------+------------------------+
        |                                                |
+-------------------+                        +-------------------------+
|  Queue 1: SYSTEM   |                        |   Queue 2: USER         |
|  Scheduling:       |                        |   Scheduling:           |
|  Priority (lower #)|                        |   Round Robin (TQ=2)    |
+-------------------+                        +-------------------------+
        |                                                |
+-------v--------+                              +--------v---------+
| Sorted by Prio |                              | Cycles via TQ     |
| Preemptive     |                              | Rotates until done|
+----------------+                              +-------------------+



