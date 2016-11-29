// UnitsMoving.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//
/*
Definition
    	
Class:	UnitsMoving
Method:	bestTime
Parameters:	array[], array[]
Returns:	double
Method signature:	double bestTime(array[] start, array[] finish)
(be sure your method is public)
    
	Constraints
	-	start will contain between 1 and 50 elements, inclusive.
	-	finish will contain the same number of elements as start.
	-	Each element of start will be formatted as "X Y V", where X, Y and V are integers without leading zeroes.
	-	Each element of finish will be formatted as "X Y", where X and Y are integers without leading zeroes.
	-	All X and Y will be between 0 and 1000, inclusive.
	-	All V will be between 1 and 10, inclusive.
	-	All elements of finish will be different.
*/

#include "stdafx.h"
#include <array>
#include <iostream>
#include <algorithm>
#include <typeinfo>
#include <math.h>
using namespace std;

class UnitsMoving
{
private:


public:
	int startingPoints[50][3];
	int finishPoints[50][2];
	double times[50][1];
	void setPoint(int position, int(&point)[3], int(&startingPoints)[50][3]);
	void setPoint(int position, int(&point)[2], int(&finishPoints)[50][2]);
	void printPoints(double(&points)[50][1]);
	void printPoints(int(&points)[50][2]);
	void printPoints(int(&points)[50][3]);
	void calculateTimes(int(&startingPoints)[50][3], int(&finishPoints)[50][2], double(&times)[50][1]);
	double getIndividualTime(int (&startingPoint)[3], int (&finishingPoint)[2]);
	double bestTime();
};
void UnitsMoving::printPoints(int(&points)[50][2])
{
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << *&points[i][j]<<" ";
		}
		cout << endl;
	}
	return;
}
void UnitsMoving::printPoints(int(&points)[50][3])
{
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << *&points[i][j] <<" ";
		}
		cout << endl;
	}
	return;
}
void UnitsMoving::printPoints(double(&points)[50][1])
{
	for (int i = 0; i < 50; i++)
	{
		cout << *&points[i] << " ";
		cout << endl;
	}
	return;
}
void UnitsMoving::setPoint(int pos, int(&point)[3], int(&startingPoints)[50][3]) // sets the coordinates of a point to those of the input point 
{
	for (int i = 0; i < 3; i++)
	{
		startingPoints[pos][i] = point[i];
	}
	return;
}
void UnitsMoving::setPoint(int pos, int(&point)[2], int(&finishPoints)[50][2]) // sets the coordinates of a point to those of the input point 
{
	for (int i = 0; i < 2; i++)
	{
		finishPoints[pos][i] = point[i];
	}
	return;
}

double UnitsMoving::getIndividualTime(int (&startingPoint)[3], int(&finishingPoint)[2])
{
	double distance = 0;
	double time = 0;
	int startX = *(&startingPoint)[0];
	int startY = *(&startingPoint)[1];
	int velocity = *(&startingPoint)[2];
	int finishX = *(&finishingPoint)[0];
	int finishY = *(&finishingPoint)[1];
	double distanceX = finishX-startX;
	double distanceY = finishY - startY;
	distance = sqrt(exp(distanceX) + exp(distanceY));
	if (velocity !=0)
	{
		time = distance / velocity;
	}
	else{
		time = -1;
	}

	return time;
}
void UnitsMoving::calculateTimes(int(&startingPoints)[50][3], int(&finishPoints)[50][2], double(&times)[50][1]) 
{
	for (int i = 0; i < 50; i++)
	{
		*(&times)[i][0]=getIndividualTime((&startingPoints)[i][3],(&finishPoints)[i][2]);
	}

}
double UnitsMoving::bestTime()
{
	return 0.0;
}


int main()
{
	int blub=0;
	UnitsMoving units{};
	int start00[3] = {1,1,1};
	int start01[3] = { 0,1,1 };
	int start02[3] = { 5,7,3 };
	int finish00[2] = { 1,1 };
	int finish01[2] = { 1,1 };
	int finish02[2] = { 1,1 };

	//cout << typeid(point01).name()<<endl;
	units.setPoint(0, start00, units.startingPoints);
	units.setPoint(1, start01, units.startingPoints);
	units.setPoint(2, start02, units.startingPoints);
	units.setPoint(0, finish00, units.finishPoints);
	units.setPoint(1, finish01, units.finishPoints);
	units.setPoint(2, finish02, units.finishPoints);
	units.calculateTimes(units.startingPoints , units.finishPoints, units.times);
	units.printPoints(units.times);
	//units.printPoints(units.startingPoints);
	//units.printPoints(units.finishPoints);
	cin >> blub;
    return 0;
}
