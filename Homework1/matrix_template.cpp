//---------------------------------------------------------------------
// Name: Robert Bennethum
// Email: rmb6287@psu.edu
// Class: CMPSC 122, Section 2
// Program 1.1
// Due Date: February 20 2020, 11:59 PM
//
// Description: This program collects information from the user
// to create two matrices using a Matrix class definition, and 
// performs several calculations using those matrices.
// The results of each calculation are retrieved and displayed
// to the user in a readable format.
//
// Acknowledgements:
// 1. Please use this portion of the banner comment to list
// any resources or individuals you consulted on the creation
// of this program.
//https://youtu.be/2spTnAiQg4M
//https://youtu.be/QXUbFzEd3Ww
//---------------------------------------------------------------------

#include <iostream>

using namespace std;

class Matrix
{
private:
	// declare member fields for row, columns
    int rows;
    int columns;
    int **matrix;
public:
	// declare member field for matrix data (int **), It would be better practice putting this under
	// private and create a getter for it.

	// declare non-default constructor, two parameters for row and column size
    Matrix(int rows, int columns) {
        this->rows=rows;
        this->columns=columns;

        matrix = new int *[rows];
        for (int i=0; i<rows; i++) {
            matrix[i] = new int[columns];
        }
    }

	// declare destructor
    ~Matrix() {
        for (int i=0; i<rows; i++) {
            matrix[i]= nullptr;
            delete[] matrix[i];
        }
        matrix = nullptr;
        delete[] matrix;
    }
	// declare accessor functions ("getter" functions)
    int getColumns() const {
        return columns;
    }
    int getRows() const {
        return rows;
    }
    int getInt(int getRow, int getColumn) const {
        return matrix[getRow][getColumn];
    }
    void setMatrix(int setRow, int setColumn, int setValue) {
        matrix[setRow][setColumn]=setValue;
    }
	// declare functions to perform calculations and display output
    void printMatrix() {
        for (int i=0; i<rows; i++) {
            for (int j=0; j<columns; j++) {
                //matrix[i][j]=1;
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
	Matrix* add(const Matrix&); // const is optional, but good practice. if you choose not to use it, make sure you update the definition below.
	// as detailed in assignment
    Matrix* subtract(const Matrix&);
    Matrix* multiply(const Matrix&);
    Matrix* intMultiply(int);
};

// Write function bodies for all public Matrix functions 
//

// constructor dynamically  allocates 2D array to hold matrix data based on row/col size

// destructor free up dynamically allocated memory using delete [], remember the "inside-out" rule

// add member function

Matrix* Matrix::add(const Matrix& m)
{
	Matrix *sum = new Matrix(rows, columns); // pass in correction information to invoke our constructor

	// do calculations
    for (int i=0;i<m.getRows();i++){
        for (int j=0;j<m.getColumns();j++){
            int f1, f2, S;
            f1= getInt(i,j);
            f2=m.getInt(i,j);
            S=f1+f2;
            sum->setMatrix(i,j,S);
            cout << f1 << " + " << f2 << "  ";
        }
        cout << endl;
    }
	return sum;
}
// remainder of calculations and member functions (like print)
Matrix* Matrix::subtract(const Matrix& m) {
    Matrix *subtract = new Matrix(rows, columns); // pass in correction information to invoke our constructor

    // do calculations
    for (int i=0;i<m.getRows();i++){
        for (int j=0;j<m.getColumns();j++){
            int f1, f2, S;
            f1= getInt(i,j);
            f2=m.getInt(i,j);
            S=f1-f2;
            subtract->setMatrix(i,j,S);
            cout << f1 << " - " << f2 << "  ";
        }
        cout << endl;
    }
    return subtract;
}
Matrix* Matrix::multiply(const Matrix& m) {
    Matrix *multiply = new Matrix(getRows(), m.getColumns());
    for (int i=0; i<multiply->getRows(); i++) {
        for (int j = 0; j < multiply->getColumns(); j++) multiply->setMatrix(i,j,0);
    }
    for (int i=0;i<getRows();i++) {
        for (int j=0;j<m.getColumns();j++) {
            for (int z=0;z<getColumns();z++) {
                int multi = getInt(i,j)*m.getInt(j,z);
                cout << getInt(i,j) << " * " << m.getInt(j,z) << " ";
                int val = multiply->getInt(i,z)+multi;
                cout << multiply->getInt(i,z) << " + " << multi << "; " << endl;
                multiply->setMatrix(i,z,val);
                multiply->printMatrix();
            }
        }
    }
    cout << endl;
    return multiply;
}
Matrix* Matrix::intMultiply(const int num) {
    Matrix *intMultiply = new Matrix(getRows(), getColumns());
    for (int i=0; i<getRows(); i++) {
        for (int j=0; j<getColumns(); j++) {
            int newNum = getInt(i, j)*num;
            cout << getInt(i, j) << " * " << num << "  ";
            intMultiply->setMatrix(i,j,newNum);
        }
        cout << endl;
    }
    return intMultiply;
}


int main()
{
	// Prompt user for information for first matrix
	// Collect input and create instance of Matrix
    int rows;
    int columns;
    //int *nums;
    cout << "Number of Rows in Matrix 1: ";
    cin >> rows;
    cout << "Number of Columns in Matrix 1: ";
    cin >> columns;
    Matrix m1(rows, columns);
    cout << "Values of Matrix 1 (expecting " << m1.getColumns() * m1.getRows() <<"): ";
    //nums = new int[m1.getColumns()*m1.getRows()];
    for (int i=0;i<m1.getRows();i++) {
        for (int j=0;j<m1.getColumns();j++){
            int value;
            cin >> value;
            m1.setMatrix(i,j,value);
        }
    }
    m1.printMatrix();

	// Prompt user for information for second matrix
	// Collect input and create second instance of Matrix
    cout << "Number of Rows in Matrix 2: ";
    cin >> rows;
    cout << "Number of Columns in Matrix 2: ";
    cin >> columns;
    Matrix m2(rows, columns);
    cout << "Values of Matrix 2 (expecting " << m2.getColumns() * m2.getRows() <<"): ";
    //nums = new int[m1.getColumns()*m1.getRows()];
    for (int i=0;i<m2.getRows();i++) {
        for (int j=0;j<m2.getColumns();j++){
            int value;
            cin >> value;
            m2.setMatrix(i,j,value);
        }
    }
    m2.printMatrix();
	// Perform calculations as described in assignment using member functions
	// Be sure to check matrices size for add/sub, and then multiply

    if (m1.getColumns()==m2.getColumns()&&m1.getRows()==m2.getRows()){
        //add
        cout << endl << "Add" << endl;
        Matrix *sum = m1.add(m2); // invoke add function here
        sum->printMatrix();
        //subtract
        cout << endl << "Subtract" << endl;
        Matrix *subtract = m1.subtract(m2);
        subtract->printMatrix();
    }
    else {
        cout << "Add and Subtract Skipped Due to Matrices Not Being the Same Size" << endl;
    }
    //check if you can multiply
    cout << endl << "Multiply" << endl;
    if (m1.getColumns()==m2.getRows()) {
        Matrix *multiply = m1.multiply(m2);
        multiply->printMatrix();
    }
    else {
        cout << "Multiplication Skipped Due to Matrices Not Able to be Multiplied" << endl;
    }

    cout << endl << "Scalar Multiplication" << endl;
    cout << "Enter an Integer to Multiply By: ";
    int scalar;
    cin >> scalar;
    Matrix *intMultiply = m1.intMultiply(scalar);
    intMultiply->printMatrix();



	// Be sure to output details about calculation being performed and the results

	return 0;
}