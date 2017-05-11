#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	bool skip = false;
	double x_old, vx_old, ax = 0;

	//someone clean my code pls
	//NOTE: this is not complete (only did the 1D motion part)
	//for now, kalman pretty much useless compared kinematics equation because I haven't included the noise factor or Kgain (uncertainties and variances not filtered yet)

	while (true)
	{


		cout << "Enter time elapsed between sensor readings: ";
		double t;  //time
		cin >> t;



		if (!skip) {
			cout << "Enter current distance: ";
			//double x_old;  //x position
			cin >> x_old;

			cout << "Enter current x velocity: ";
			//double vx_old = 0;  //x velocity
			cin >> vx_old;


			cout << "Enter current x acceleration: ";
			//double ax = 0;  //x acceleration
			cin >> ax;
		}

		double A[2][2] = { {1, t}, {0, 1} };  //multiply by State matrix
		double S[2][1] = { { x_old }, { vx_old } };  //State matrix


		double B[2][1] = { {0.5 * t * t}, {t} };  //multiply by Control matrix
		double u = ax;  //Control Matrix

		double w = 0;  //noise

		//need function to multiply 2 arrays
		//double K = A*S + B*u;

		//skip the above bullshit and hope this works
		double k_short[2][1] = { { x_old + (vx_old * t) + (0.5 * ax * t*t) }, { vx_old + ax*t } };  //bypass multiplication, delivers new x & new vx
		/*
		double x_new = k_short[0][0];
		double vx_new = k_short[1][0];

		cout << "new x: " << setprecision(1) << fixed << x_new << endl;
		cout << "new vx: " << setprecision(1) << fixed << vx_new << endl;
		*/

		x_old = k_short[0][0];
		vx_old = k_short[1][0];
		skip = true;

		cout << "new x: " << setprecision(3) << fixed << x_old << endl;
		cout << "new vx: " << setprecision(3) << fixed << vx_old << endl;

		//now time for covariance matrix (measurement correction part of kalman)
		double lengths[3][5] = { {4.0, 4.2, 3.9, 4.3, 4.1}, {2.0, 2.1, 2.0, 2.1, 2.3}, {0.6, 0.59, 0.56, 0.62, 0.63} };  //L, W, & H loaded with sample data

		/*
		double average[3][1];

		for (int i = 0; i < sizeof(lengths[0]); i++) {
			average[0][1] += sizeof(lengths[0]) * lengths[0][i];
		}

		*/

		double average[3][1] = { { 4.1 }, { 2.1 }, { 0.6 } };  //precalculated by hand instead of through for loop

		//covariance matrix made out of variance, covariance, and standar deviation

		double test[3][3] = { { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 } };

		int rows = sizeof(test) / sizeof(test[0]);  //x
		int cols = sizeof(test[0]) / sizeof(test[0][0]);  //y
		
		double sum = 0;

		cout << "x: " << rows << endl;
		cout << "y: " << cols << endl;

		for (int j = 0; j < cols; j++) {
			sum += test[0][j];
			
		}


		//average
		double avg[3][1];
		avg[0][0] = sum / cols;
		cout << avg[0][0] << endl;


		double sum_dev = 0;

		//variance
		for (int j = 0; j < cols; j++) {
			sum_dev += (avg[0][0] - test[0][j]) * (avg[0][0] - test[0][j]);

		}

		double dev[3][1];
		dev[0][0] = sum_dev / cols;
		cout << dev[0][0] << endl;

		//standard deviation
		double std_dev[3][1];
		std_dev[0][0] = sqrt(dev[0][0]);
		cout << std_dev[0][0] << endl;

		//covariance here??
		//used for more than 1 measurement (ex: position and velocity)
		//used to compare variances between 2 variables instead of each data type individually

	}

		return 0;
	
}