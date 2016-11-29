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
using namespace std;

class UnitsMoving
{
private:


public:
	int startingPoints[50][3];
	int finishPoints[50][2];
	void setPoint(int position,  int (&point)[3], int (&startingPoints)[50][3]);
	double individualTime(int *start, int *finish);
	double bestTime();
};

void UnitsMoving::setPoint(int pos, int (&point)[3], int (&startingPoints)[50][3]) 
{

	for (int i = 0; i < 3; i++)
	{
		startingPoints[pos][i] = point[i];
	}
	return;
}

double UnitsMoving::individualTime(int *start, int *finish)
{
	double distance = 0;
	cout << start;
	return 0.0;
}
double UnitsMoving::bestTime()
{
	return 0.0;
}


int main()
{
	int blub=0;
	UnitsMoving units{};
	int point[3] = {1,1,1};
	cout << typeid(point).name()<<endl;
	units.setPoint(0, point, units.startingPoints);
	cout << units.startingPoints;
	cin >> blub;
    return 0;
}
