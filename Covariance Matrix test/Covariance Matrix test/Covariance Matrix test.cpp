#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//contains length, width, and height with 5 data points each
	//in the future, make this a dynamic array if you want to continously update the data inside
	double data[3][5] = { { 4.0, 4.2, 3.9, 4.3, 4.1 },{ 2.0, 2.1, 2.0, 2.1, 2.3 },{ 0.6, 0.59, 0.56, 0.62, .63 } };

	//create average function here

	//calculate the lengths of our array for use with the for-loop
	int rows = sizeof(data) / sizeof(data[0]);  //array size / column size
	int cols = sizeof(data[0]) / sizeof(data[0][0]);  //column size / element size

	//x * column size = array size
	//y * element size = column size

	/*
	cout << "total bytes of whole array: " << sizeof(dimensions) << endl;
	cout << "total bytes of each column: " << sizeof(dimensions[0]) << endl;
	cout << "total bytes of each element: " << sizeof(dimensions[0][0]) << endl;
	*/

	cout << "\t data" << endl;

	for (int j = 0; j < cols; j++) {
		for (int i = 0; i < rows; i++) {
			cout << setprecision(4) << fixed << data[i][j] << "  ";
		}
		cout << endl;

	}


	double sum1[3] = { 0, 0, 0 };
	double avg[3] = { 0, 0, 0 };

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			//we can calculate the average in this loop by multiplying by 1/N, however we can factor out 1/N and avoid redundant multiplications
			//this saves processing time (remember Direct Form from 306?)
			sum1[i] += data[i][j];
		}

		//reduce amount of multiplication operations to 1 by factoring out 1/N
		avg[i] = sum1[i] / cols;
	}

	
	//need print array function
	cout << "\t average" << endl;

	for (int i = 0; i < 3; i++) {
		cout << avg[i] << "  ";
	}

	cout << endl;

	//variance
	double sum2[3] = { 0, 0, 0 };
	double var[3] = { 0, 0, 0 };

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			sum2[i] += pow(avg[i] - data[i][j], 2);
		}

		var[i] = sum2[i] / cols;
	}

	cout << "\t variance" << endl;

	for (int i = 0; i < 3; i++) {
		cout << var[i] << "  ";  //expect small decimal numbers (need to see at least 4 decimal points)
	}

	cout << endl;

	//from this point on, not optimized (i'm using magic numbers)

	//covariance
	double cov1_2 = 0;
	double cov1_3 = 0;
	double cov2_3 = 0;

	for (int j = 0; j < cols; j++) {
		cov1_2 += (avg[0] - data[0][j]) * (avg[1] - data[1][j]) / cols;
		cov1_3 += (avg[0] - data[0][j]) * (avg[2] - data[2][j]) / cols;
		cov2_3 += (avg[1] - data[1][j]) * (avg[2] - data[2][j]) / cols;
	}

	double cov[3] = { cov1_2, cov1_3, cov2_3 };


	cout << "\t covariance" << endl;

	for (int i = 0; i < 3; i++) {
		cout << cov[i] << "  ";
	}

	cout << endl;

	//now the finished product, the covariance matrix
	double c[3][3] = { {var[0], cov1_2, cov1_3} , {cov1_2, var[1], cov2_3}, {cov1_3, cov2_3, var[2]} };

	cout << "\t covariance matrix" << endl;

	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			cout << c[i][j] << "  ";
		}
		cout << endl;

	}

	//still here? well I have bad news. This is the hard? way.  The alternative way involves multiplying matrices and transposing.  This code is more of an explanation on how to derive the alternative method



	return 0;

}