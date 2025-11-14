# C++ Matrix Operations

A C++ program that implements a Matrix class with basic matrix operations including addition, subtraction, multiplication, and scalar multiplication.

## Description

This project contains implementations of matrix operations in C++. The program allows users to create two matrices by specifying their dimensions and values, then performs various mathematical operations on them. The results are displayed in a readable format.

## Features

- **Matrix Addition**: Add two matrices element-wise
- **Matrix Subtraction**: Subtract one matrix from another element-wise
- **Matrix Multiplication**: Multiply two matrices (standard matrix multiplication)
- **Scalar Multiplication**: Multiply a matrix by a scalar value
- **Dynamic Memory Management**: Proper allocation and deallocation of matrix memory

## Project Structure

```
.
├── CMakeLists.txt              # CMake build configuration
├── matrix_template.cpp         # Main matrix operations program (Program 1.1)
├── Homework1/
│   ├── matrix_template.cpp     # Matrix operations implementation
│   └── matrix_ops_template.cpp # Additional matrix operations
├── H1p2/
│   ├── main.cpp                # Simple Hello World program
│   ├── matrix_ops_template.cpp # Matrix operations template
│   └── CMakeLists.txt          # Build configuration for H1p2
└── homework1.pdf               # Problem statement/assignment details
```

## Requirements

- C++ Compiler with C++14 support or later
- CMake 3.21 or higher

## Building the Project

### Using CMake (Recommended)

```bash
# Create a build directory
mkdir build
cd build

# Configure the project
cmake ..

# Build the executable
make
```

The compiled executable will be named `HW1` and located in the `build/` directory.

### Alternative Build Methods

You can also compile directly using g++:

```bash
g++ -std=c++14 matrix_template.cpp -o matrix_program
```

## Usage

Run the program and follow the interactive prompts:

```bash
./build/HW1
```

### Input Format

The program will prompt you for:
1. Number of rows for Matrix 1
2. Number of columns for Matrix 1
3. Values for Matrix 1 (entered row by row)
4. Number of rows for Matrix 2
5. Number of columns for Matrix 2
6. Values for Matrix 2 (entered row by row)
7. Scalar value for scalar multiplication

### Example Session

```
Number of Rows in Matrix 1: 2
Number of Columns in Matrix 1: 2
Values of Matrix 1 (expecting 4): 
1 2 3 4

Number of Rows in Matrix 2: 2
Number of Columns in Matrix 2: 2
Values of Matrix 2 (expecting 4): 
5 6 7 8
```

The program will then display:
- Matrix addition result
- Matrix subtraction result
- Matrix multiplication result
- Scalar multiplication result

## Implementation Details

### Matrix Class

The program uses a `Matrix` class with:
- **Private members**: rows, columns, and a 2D array pointer
- **Constructor**: Allocates memory for the matrix based on dimensions
- **Destructor**: Properly deallocates memory to prevent memory leaks
- **Utility methods**: 
  - `setElement(row, col, value)`: Set a specific matrix element
  - `addMatrix(other)`: Add another matrix
  - `subtractMatrix(other)`: Subtract another matrix
  - `multiplyMatrix(other)`: Multiply by another matrix
  - `scalarMultiply(scalar)`: Multiply by a scalar value
  - `printMatrix()`: Display the matrix

## Author

**Robert Bennethum**
- Email: rmb6287@psu.edu
- Class: CMPSC 122, Section 2
- Institution: Penn State University

## Academic Context

This project was created as part of CMPSC 122 coursework at Penn State University. Original due date: February 20, 2020.

## License

This is an academic project created for educational purposes.

## Notes

- The repository name "cpp-student-database-cli" is a misnomer; this project focuses on matrix operations rather than student database management.
- Memory is dynamically allocated using `new` and deallocated using `delete` to demonstrate proper C++ memory management.
- The implementation follows object-oriented programming principles with proper encapsulation.
