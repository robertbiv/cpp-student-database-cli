//---------------------------------------------------------------------
// Name: Robert Bennethum
// Email: rmb6287@psu.edu
// Class: CMPSC 122, Section 2
// Program 1.2
// Due Date: February 15 2020, 11:59 PM
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
	// declare member field for matrix data (int **), It would be better practice to put this under
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

	// declare operator overloads using friend to perform calcuations as well as fill the matrix data and display output
	friend Matrix* operator+(const Matrix&, const Matrix&);
    friend Matrix* operator-(const Matrix&, const Matrix&);
    friend Matrix* operator*(const Matrix&, const Matrix&);
    friend Matrix* operator*(const int, const Matrix&);
    friend Matrix* operator*(const Matrix&, const int);
	// ...
	friend istream& operator<<(istream&,const Matrix&);
    friend ostream& operator>>(ostream&,const Matrix&);
	// as detailed in assignment
};

// Write function bodies for all public Matrix functions 
//

// constructor dynamically  allocates 2D array to hold matrix data based on row/col size

// destructor free up dynamically allocated memory using delete [], remember the "inside-out" rule

// define operator overloads

Matrix* operator+(const Matrix& mLeft, const Matrix& mRight)
{
	Matrix *sum = new Matrix(mLeft.getRows(), mLeft.getColumns()); // pass in correction information to invoke our constructor
	// do calculations
    for (int i=0;i<mLeft.getRows();i++){
        for (int j=0;j<mLeft.getColumns();j++){
            int f1, f2, S;
            f1=mLeft.getInt(i,j);
            f2=mRight.getInt(i,j);
            S=f1+f2;
            sum->setMatrix(i,j,S);
            cout << f1 << " + " << f2 << "  ";
        }
        cout << endl;
    }
    cout << endl;

	return sum;
}
Matrix* operator-(const Matrix& mLeft, const Matrix& mRight) {
    Matrix *subtract = new Matrix(mLeft.getRows(), mLeft.getColumns()); // pass in correction information to invoke our constructor
    // do calculations
    for (int i=0;i<mLeft.getRows();i++){
        for (int j=0;j<mLeft.getColumns();j++){
            int f1, f2, S;
            f1= mLeft.getInt(i,j);
            f2=mRight.getInt(i,j);
            S=f1-f2;
            subtract->setMatrix(i,j,S);
            cout << f1 << " - " << f2 << "  ";
        }
        cout << endl;
    }
    cout << endl;
    return subtract;
}
Matrix* operator*(const Matrix& mLeft, const Matrix& mRight) {
    Matrix *multiply = new Matrix(mLeft.getRows(), mRight.getColumns());
    for (int i=0; i<multiply->getRows(); i++) {
        for (int j = 0; j < multiply->getColumns(); j++) multiply->setMatrix(i,j,0);
    }
    for (int i=0;i<mLeft.getRows();i++) {
        for (int j=0;j<mRight.getColumns();j++) {
            for (int z=0;z<mLeft.getColumns();z++) {
                int multi = mLeft.getInt(i,j)*mRight.getInt(j,z);
                cout << mLeft.getInt(i,j) << " * " << mRight.getInt(j,z) << " ";
                int val = multiply->getInt(i,z)+multi;
                cout << multiply->getInt(i,z) << " + " << multi << "; " << endl;
                multiply->setMatrix(i,z,val);
                cout << multiply;
            }
        }
    }
    cout << endl;
    return multiply;
}
Matrix* operator*(const int num, const Matrix& m) {
    Matrix *intMultiply = new Matrix(m.getRows(), m.getColumns());
    for (int i=0; i<m.getRows(); i++) {
        for (int j=0; j<m.getColumns(); j++) {
            int newNum = m.getInt(i, j)*num;
            cout << num << " * " << m.getInt(i, j) << "  ";
            intMultiply->setMatrix(i,j,newNum);
        }
        cout << endl;
    }
    cout << endl;
    return intMultiply;
}
Matrix* operator*(const Matrix& m, const int num) {
    Matrix *intMultiply = new Matrix(m.getRows(), m.getColumns());
    for (int i=0; i<m.getRows(); i++) {
        for (int j=0; j<m.getColumns(); j++) {
            int newNum = m.getInt(i, j)*num;
            cout << m.getInt(i, j) << " * " << num << "  ";
            intMultiply->setMatrix(i,j,newNum);
        }
        cout << endl;
    }
    cout << endl;
    return intMultiply;
}
// remainder of operator overloads for calculations friended in the Matrix class
// 
ostream& operator<<(ostream& os,const Matrix& m) {
    for (int i=0; i<m.getRows(); i++) {
        for (int j=0; j<m.getColumns(); j++) {
            cout << m.getInt(i,j) << " ";
        }
        cout << endl;
    }
    cout << endl;
    return os;
}

istream& operator>>(istream& os, Matrix& m)
{
    cout << "Values of Matrix (expecting " << m.getColumns() * m.getRows() <<"): ";
    //nums = new int[m1.getColumns()*m1.getRows()];
    for (int i=0;i<m.getRows();i++) {
        for (int j=0;j<m.getColumns();j++){
            int value;
            cin >> value;
            m.setMatrix(i,j,value);
        }
    }
	return os; // passing back the ostream reference we are given via os parameter
}

// define overloaded >>, receives and returns istream instead of ostream

int main()
{
	// Remember you have to use >> and << to your matrix object instances to fill and print them

	// When you print Matrix pointers (object pointers), remember to dereference
	// the pointer when you invoke << (output), and it accepts an object reference, not an object pointers
    // code
    int rows;
    int columns;
    cout << "Number of Rows in Matrix 1: ";
    cin >> rows;
    cout << "Number of Columns in Matrix 1: ";
    cin >> columns;
    Matrix m1(rows, columns);

	// Prompt user for information for first matrix
	// Collect input and create instance of Matrix 
    cin>>m1;
    cout<<m1;
	// Prompt user for information for second matrix
	// Collect input and create second instance of Matrix
    cout << "Number of Rows in Matrix 2: ";
    cin >> rows;
    cout << "Number of Columns in Matrix 2: ";
    cin >> columns;
    Matrix m2(rows, columns);
    cin>>m2;
    cout<<m2;
	// Perform calculations as described in assignment using member functions
	// Be sure to check matrices size for add/sub, and then mult
    if (m1.getColumns()==m2.getColumns()&&m1.getRows()==m2.getRows()) {
        cout << "Add" << endl;
        Matrix *sum = m1 + m2; // invoke + operator here
        cout << *sum;
        cout << "Subtract" << endl;
        Matrix *subtract = m1 - m2;
        cout << *subtract;
    }
    else {
        cout << "Matrices Unable to be Added or Subtracted" << endl;
    }

    if (m1.getColumns()==m2.getRows()) {
        cout << "Multiply" << endl;
        Matrix *multiply = m1*m2;
        cout << *multiply;
    }
    int num;
    cout << "Enter a Number: ";
    cin >> num;
    cout << "Int Multiply 1" << endl;
    Matrix *intMultiply1 = num*m1;
    cout << *intMultiply1;
    cout << "Int Multiply 2" << endl;
    Matrix *intMultiply2 = m1*num;
    cout << *intMultiply2;

	// Be sure to output details about calculation being performed and the results
	// When you print Matrix pointers (object pointers), remember to dereference
	// the pointer when you invoke << (output), and it accepts an object reference, not an object pointers

	return 0;
}