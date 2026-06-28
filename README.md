# AAPT: Advanced Attention-based Paging Technique

AAPT is a C-based memory management simulator that compares traditional contiguous memory allocation with a modern paging-based allocation strategy inspired by PagedAttention and contemporary AI infrastructure.

## Overview

Traditional memory allocation techniques such as First-Fit suffer from external fragmentation, reducing memory utilization and increasing allocation failures under dynamic workloads.

AAPT demonstrates how paging can overcome these limitations by allocating memory in fixed-size frames and maintaining logical-to-physical mappings through page tables.

## Features

- Physical Memory Simulation
- First-Fit Contiguous Allocation
- Paging-Based Allocation
- Page Table Management
- Fragmentation Analysis
- Throughput Measurement
- Allocation Latency Tracking
- Bursty Workload Simulation

## Project Structure

```
aapt-memory-management-simulator/
│
├── README.md
├── .gitignore
│
├── src/
├── data/
├── docs/
└── results/
```

## Tech Stack

- C Programming Language
- GCC Compiler
- Git & GitHub

## Future Goals

- Compare allocation success rates
- Measure memory utilization
- Analyze fragmentation
- Benchmark paging against First-Fit allocation

## References

- PagedAttention (SOSP 2023)
- vAttention (2024)
- Operating System Concepts – Silberschatz