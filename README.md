# Package Distribution System

This project compares the performance of single-thread and multi-thread approaches for handling concurrent simulated transactions. Implemented in C, it evaluates execution time and synchronization behavior using both `pthread` (threads) and `fork` (processes).

## 📘 Table of Contents

[🚀 Project Overview](#🧪-objective)

[📁 Project Structure](#📁-project-structure)

[⚙️ Requirements](#⚙️-requirements)

[🔧 How to Run](#🔧-how-to-run)

[👀 Example](#👀-example)

[📊 Performance Comparison ](#📈-output)

[📌 When to Use Threads vs Processes](#🧠-analysis)

[🔐 Synchronization Issues and Solutions](#🔐-synchronization-issues-and-solutions)

[🧑‍💻 Team Members](#🧑‍💻-authors)

[📄 License](#📄-license)

## 🧪 Objective

Explore, through a practical case study in C, the execution time differences between single-threaded processes and multi-thread implementations for handling multiple transactions. The goal is to empirically demonstrate the advantages of using threads over traditional processes.

## 📁 Project Structure

```
package_distribution_system/
├── include/              # Header files
│   ├── transactions.h
│   └── utils.h
├── results/              # Output results (created automatically)
│   ├── thread_output.txt
│   └── process_output.txt
├── src/                  # Source code
│   ├── thread.c
│   ├── process.c
│   ├── transactions.c
│   └── utils.c
├── run.sh                # Script to compile and execute both versions
├── Makefile              # Compilation rules
└── README.md             # Project documentation
```

## ⚙️ Requirements

- A Linux environment is required to compile and run this project. You can use one of the following methods:

  - 🔗 [WSL (Windows Subsystem for Linux)](https://learn.microsoft.com/en-us/windows/wsl/install)
  - 🔗 [Virtual Machine (e.g., Ubuntu with VirtualBox)](https://ubuntu.com/download/desktop)
  - 🔗 [Docker](https://docs.docker.com/get-docker/)

- GCC compiler
- pthread library
- make

To install required tools on Debian/Ubuntu:

```bash
sudo apt update
sudo apt install build-essential
```

## 🔧 How to Run

1. Clone or copy the repository to your Linux environment.
2. Navigate to the project directory.

```bash
cd package_distribution_system
```

3. Run the execution script:

```bash
./run.sh
```

This script will:

- Clean previous builds
- Compile both thread and process versions
- Execute both
- Save their output in the `results/` folder

## 📈 Output

After execution, two output files will be generated:

- `results/thread_output.txt` — Output of the thread-based version
- `results/process_output.txt` — Output of the process-based version

Each file includes:

- Time per group (A–P)
- Total execution time

## 👀 Example

![Project execution output example](/resources/example.png)

#### 📌 Comparing Execution Times

In this example, the thread-based version completed in 0.001793 seconds, while the process-based version took 0.007484 seconds. Threads were significantly faster due to reduced context switching and shared memory space.

#### 📌 Observed Differences

- Threads benefit from shared memory space and lower overhead when spawning.

- Processes are slower due to memory isolation and system call overhead.

- Threads are more efficient for tightly coupled, high-volume parallel tasks.

## 🧠 Analysis

### ✅ When to Use Threads

- When tasks share memory and require lightweight communication
- When the overhead of creating full processes is unjustified
- When concurrency is fine-grained and context switching needs to be minimal

### ✅ When to Use Processes

- When tasks require memory isolation (e.g., different users)
- When stability is critical (crashes in one process won't affect others)
- When working with multiprocessing on multi-core machines for CPU-bound tasks

## 🔐 Synchronization Issues And Solutions

| Issue                                      | Solution                                                      |
| ------------------------------------------ | ------------------------------------------------------------- |
| Race conditions accessing shared resources | Used `pthread_mutex_t` in the thread version                  |
| Output timing inconsistencies              | Used `clock_gettime(CLOCK_MONOTONIC, ...)` for precise timing |

## 🧑‍💻 Authors

- Franciss Cartagena
- Mayerli Chávez
- Jenner Simbaña
- Franciel Tipantuña
- Sebastián Guerrero

## 📄 License

This project is released under the MIT License.
