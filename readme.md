# 42 Push_swap Project

## Table of Contents

- [Introduction](#introduction)
- [Description](#description)
- [Algorithm Overview](#algorithm-overview)
  - [1. Stacks Initialization](#1-stacks-initialization)
  - [2. Indexing the Stack](#2-indexing-the-stack)
  - [3. Longest Increasing Subsequence (LIS)](#3-longest-increasing-subsequence-lis)
  - [4. Cost Calculation](#4-cost-calculation)
  - [5. Executing the Operations](#5-executing-the-operations)
  - [6. Special Cases](#6-special-cases)
- [Compilation](#compilation)
- [Usage](#usage)
- [File Structure](#file-structure)
- [Functions](#functions)
- [Bonus Features](#bonus-features)
- [Examples](#examples)
- [Authors](#authors)

## Introduction

The Push_swap project is a sorting program that works with two stacks: `a` (the main stack) and `b` (the secondary stack). The allowed operations to manipulate the stacks are limited to:

- **`sa`**: Swap the first two elements of stack `a`.
- **`sb`**: Swap the first two elements of stack `b`.
- **`ss`**: Swap the first two elements of both stacks.
- **`pa`**: Push the top element of stack `b` onto stack `a`.
- **`pb`**: Push the top element of stack `a` onto stack `b`.
- **`ra`**: Rotate stack `a` upwards (the first element becomes the last).
- **`rb`**: Rotate stack `b` upwards (the first element becomes the last).
- **`rr`**: Rotate both stacks upwards.
- **`rra`**: Rotate stack `a` downwards (the last element becomes the first).
- **`rrb`**: Rotate stack `b` downwards (the last element becomes the first).
- **`rrr`**: Rotate both stacks downwards.

The goal of the program is to minimize the number of operations required to sort the stack.

## Description

This project is divided into two main components:

1. **Push_swap**: The sorting algorithm, which takes a series of integers as input and sorts them using the least number of operations.

2. **Checker** (Bonus): A program to verify whether a series of operations correctly sorts the stack.

The project must be optimized to minimize the number of operations performed, which is the core challenge.

## Algorithm Overview

### 1. Stacks Initialization

When the program starts, it takes a series of integers as command-line arguments and pushes them onto the stack `a`. Stack `b` is initialized as empty.

### 2. Indexing the Stack

To facilitate sorting, each element in `a` is indexed based on its position in a sorted version of the stack. This index will be used to determine the correct order of elements, making it easier to compare elements during sorting.

### 3. Longest Increasing Subsequence (LIS)

The core idea behind the sorting algorithm is to identify the **Longest Increasing Subsequence (LIS)** in stack `a`. Elements in the LIS are already sorted and remain in stack `a`. The elements not in the LIS will be pushed to stack `b` to be sorted.

The LIS is found using dynamic programming techniques. After identifying the LIS, we aim to move the remaining elements into stack `b` in the most efficient way, using the fewest operations.

### 4. Cost Calculation

For each element in stack `b`, we calculate the "cost" of moving it into its correct position in stack `a`. The cost is based on two factors:

Rotating stack `a` or `b`: The number of rotations needed to position an element correctly.

Pushing an element from stack `b` to stack `a`: This includes any necessary rotations to align both stacks.

The goal is to calculate the minimal cost for each operation and perform the one that results in the least overall cost.

### 5. Executing the Operations

Once the best operations are identified, they are executed in sequence to sort the stack. The program outputs the sequence of operations that sort the stack with the fewest moves.

### 6. Special Cases

Small Stacks: If the stack contains fewer than 6 elements, simpler sorting algorithms (like bubble sort) are used to directly sort the stack with fewer operations.

Already Sorted Stacks: The program recognizes when the stack is already sorted and avoids unnecessary operations.

## Compilation

To compile the project, use the following command:

```bash
make
```

This will generate two executables:

**push_swap**: The sorting program.

**checker**: The bonus program to check the operations.

Make Commands:

**`make`**: Compiles the project.

**`make bonus`**: Compiles both push_swap and the bonus checker program.

**`make clean`**: Removes object files.

**`make fclean`**: Removes object files and executables.

**`make re`**: Cleans and rebuilds the project.

### Usage
**Push_swap**

To run the push_swap program, provide a list of integers as arguments:

```bash
./push_swap 5 2 3 8 1
```

This will sort the stack using the least number of operations and print the sequence of operations performed.

**Checker**

To use the checker program, provide a list of integers, followed by a series of operations. For example:

```bash
./checker 5 2 3 8 1
```

Then input a series of operations like:

```bash
pb
sa
ra
```

The program will output:

`OK` if the stack is sorted correctly.

`KO` if the stack is not sorted correctly.

Testing with **`test.sh`**

Use the **`test.sh`** script to test the program with a variety of input cases. It runs both the **push_swap** and **checker** programs, comparing the results to ensure correctness.

## File Structure
.
├── bonus                  
│   ├── checker.c               
│   ├── checker_utils.c             
│   └── checker.h                
├── mandatory                 
│   ├── push_swap.c                  
│   ├── push_swap_utils.c                 
│   ├── sort_small.c                   
│   ├── stack.c                         
│   ├── ft_split.c                        
│   ├── push.c                              
│   ├── reverse_rotate.c             
│   ├── rotate.c              
│   ├── swap.c                     
│   ├── index_stack.c                     
│   ├── find_lis.c                      
│   ├── calculate_costs.c                   
│   ├── push_back.c                    
│   ├── parse_args.c                      
│   ├── main.c                        
│   ├── push_swap.h                       
├── Makefile                         
├── test.sh                         
├── README.md                      

- **`bonus/`**: Contains the checker program and utilities.
  - `checker.c`: The implementation of the checker program.
  - `checker_utils.c`: Helper functions for the checker program.
  - `checker.h`: Header file containing necessary definitions for the checker program.

- **`mandatory/`**: Contains the core sorting program and helper functions.
  - `push_swap.c`: The main sorting program.
  - `push_swap_utils.c`: Helper functions used by the sorting program.
  - `main.c`: The entry point of the program.
  - `push_swap.h`: Header file containing necessary definitions for the sorting program.

- **`Makefile`**: Defines how to compile the project.

- **`test.sh`**: A shell script for testing the program with various input cases.

- **`README.md`**: This documentation file.

## Functions
Stack Operations:

-**`create_node()`**: Creates a new node in the stack.

-**`push_front()`**: Pushes a node to the front of the stack.

-**`push_back()`**: Pushes a node to the back of the stack.

-**`pop_front()`**: Pops a node from the front of the stack.

-**`pop_back()`**: Pops a node from the back of the stack.

Sorting:

-**`index_stack()`**: Assigns an index to each element in stack a.

-**`find_lis()`**: Finds the longest increasing subsequence (LIS).

-**`calculate_cost()`**: Calculates the cost for each move.

-**`push_back_and_sor()`**: Insert the elements in stack `b` back to stack `a` and final sort stack `a`

Operations:

-**`rotate()`**, **`reverse_rotate()`**, **`swap()`**: Perform the respective operations on the stacks.

-**`push()`**: Pushes elements from b to a.

## Bonus Features
### Checker Program

The **checker** program allows you to test whether a series of operations will correctly sort a stack. You can input a list of operations (such as **`sa`**, **`pb`**, **`ra`**) and check if the stack is sorted correctly by the end of the sequence.The program will output `OK` if the stack is sorted or `KO` if it is not.

## Examples
### Example 1: Sorting with Push_swap
```bash
./push_swap 5 2 3 8 1
```

Output: The program will sort the stack and print the series of operations used to sort the integers.

### Example 2: Testing with Checker
```bash
./checker 5 2 3 8 1
```

Input the operations:
```bash
pb
sa
ra
```

Output: `OK` if the stack is sorted correctly.

## Author
**Jiemin (Jenny) Zhang**  
42 Login: jiezhang