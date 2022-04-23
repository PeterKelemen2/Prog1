#include "std_lib_facilities.h"
#include "Matrix.h"
#include "MatrixIO.h"
#include <complex.h>
using namespace Numeric_lib;

void sqrt_from_input(){
    int input;
    cout << "Please enter az integer: ";
    cin >> input;

    if(input < 0)
        cout << "No square root." << endl;
    else
        cout << "Root of " << input << " is: " << sqrt(input) << endl;
}

int main()
{
    // 1
    cout << "Size of char: " << sizeof(char) << endl;
    cout << "Size of short: " << sizeof(short) << endl;
    cout << "Size of int: " << sizeof(int) << endl;
    cout << "Size of long: " << sizeof(long) << endl;
    cout << "Size of float: " << sizeof(float) << endl;
    cout << "Size of double: " << sizeof(double) << endl;
    cout << "Size of int*: " << sizeof(int*) << endl;
    cout << "Size of double*: " << sizeof(double*) << endl;

    cout << endl;

    // 2
    Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int,2> d(10,10);
	Matrix<int,3> e(10,10,10);
	cout << "Size of Matrix<int> a(10): " << sizeof(a) << endl;
	cout << "Size of Matrix<int> b(100): " << sizeof(b) << endl;
	cout << "Size of Matrix<double> c(10): " << sizeof(c) << endl;
	cout << "Size of Matrix<int,2> d(10,10): " << sizeof(d) << endl;
	cout << "Size of Matrix<int,3> e(10,10,10): " << sizeof(e) << endl;

    cout << endl;
    // 3
	cout << "Number of elements in Matrix<int> a(10): " << a.size()<<endl;
	cout << "Number of elements in Matrix<int> b(100): " << b.size()<<endl;
	cout << "Number of elements in Matrix<double> c(10): " << c.size()<<endl;
	cout << "Number of elements in Matrix<int,2> d(10,10): " << d.size()<<endl;
	cout << "Number of elements in Matrix<int,3> e(10,10,10): " << e.size()<<endl;

	cout << endl;

    // 4
    sqrt_from_input();

    cout << endl;

    // 5
    Matrix<double> doubles(10);
    for(int i=0; i<10; i++){
        cout << i+1 << ". item of doubles: ";
        cin >> doubles(i);
    }
    cout << doubles << endl;

    cout << endl;

    // 6
    int n,m;
    cout << "Enter the dimensions (x,j): ";
    cin >> n >> m;

    Matrix<double,2> table(n,m);

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            table(i,j) = i*j;

    for(int i=0; i<n; i++){
        cout << endl;
            for(int j=0; j<m; j++)
                cout << table(i,j) << " ";
    }

    cout << endl << endl;

    // 7
    Matrix<complex<double>> c_matrix(10);
    cout << "Enter 10 complex numbers: " << endl;
    for(int i=0; i<10; i++){
        cout << i+1 << ". item: ";
        cin >> c_matrix(i);
    }
    cout << c_matrix << endl;

    complex<double> sum = accumulate(c_matrix.data(),c_matrix.data()+c_matrix.size(),complex<double>{});

    cout << endl << endl;

    // 8
    Matrix<int,2> p_m(2,3);
    for(int i=0; i<2; i++)
        for(int j=0; j<3; j++){
            cout << "m(" << i << "," << j << ")=";
            cin >> p_m(i,j);
        }
    for(int i=0; i<2; i++){
        cout << endl;
            for(int j=0; j<3; j++)
                cout << p_m(i,j) << " ";
    }
    return 0;
}
