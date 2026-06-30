# AAPT Memory Management Simulator

## Overview

This project is an Operating Systems simulator that compares two memory allocation techniques:

- First-Fit Contiguous Memory Allocation
- Paging Memory Allocation

The simulator evaluates both techniques using randomly generated workloads and compares them based on:

- Allocation Success Rate
- Memory Utilization
- External Fragmentation
- Execution Time


## Features

- First-Fit memory allocation
- Paging memory allocation
- Dynamic process allocation/deallocation
- Bursty workload simulation
- Memory utilization analysis
- External fragmentation calculation
- Execution time benchmarking
- Page table visualization


## Project Structure

aapt-memory-management-simulator
│
├── src
│   ├── main.c
│   ├── memory.c
│   ├── first_fit.c
│   ├── paging.c
│   ├── workload.c
│   ├── metrics.c
│   └── *.h
│
├── results
│   └── results.txt
│
├── docs
│
├── README.md
└── .gitignore

## Build

```bash
gcc src/*.c -o aapt


Windows

```bash
gcc src/*.c -o aapt.exe

## Run

```bash
./aapt
or
```bash
aapt.exe

## Future Improvements

- Best-Fit Allocation
- Worst-Fit Allocation
- Buddy Memory Allocation
- Graphical Memory Visualization
- Virtual Memory Simulation


