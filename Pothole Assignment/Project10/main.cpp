#include "BagInterface.h"
#include "ArrayBag.h"
#include "LinkedBag.h"
#include "Point.h"
#include <iostream>
#include <fstream>

using namespace std;

void bagTester(BagInterface<Point<double>>* bagPtr)
{
	ifstream myFile;
	double longitude=0, latitude=0;
	double otherLongitude = 0, otherLatitude = 0;
	char userChoice;

	myFile.open("potholesNY.txt");
	if (!myFile) { //Failsafe in case the file is not found
		cout << "Error: File Not Found" << endl;
	}

	cout << "isEmpty: returns " << bagPtr->isEmpty()
		<< "; should be 1 (true)" << endl;


	while (!myFile.eof()) {		
		myFile >> latitude >> longitude;
		Point <double> aPothole(latitude, longitude);
		bagPtr->add(aPothole);
	} 
	
	cout << "Anymore potholes to add? (Y/N)?" << endl;
	cin >> userChoice;
	while (userChoice == 'Y'|| userChoice == 'y' )
	{
		cout << "Enter the latitude." << endl;
		cin >> otherLatitude;
		cout << "Enter the longitude." << endl;
		cin>> otherLongitude;
		Point <double> examinePothole(otherLatitude, otherLongitude);

		if (bagPtr->contains(examinePothole))
		{
			cout << "These coordinates have already recorded." << endl;
		}
		else
		{
			cout << "Recording...Recorded. Thank you." << endl;
		}

		cout << "Anymore potholes to add? (Y/N)?" << endl;
		cin >> userChoice;

	}
	if (userChoice=='n' || userChoice == 'N')
	{
		cout << "Have a good day!" << endl;
	}

} // end bagTester

int main() {


	ifstream myFile;

	myFile.open("potholesNY.txt");
	if (!myFile) { //Failsafe in case the file is not found
		cout << "Error: File Not Found" << endl;
	}

	BagInterface<Point<double>>* bagPtr = nullptr;
	char userChoice;
	std::cout << "Enter 'A' to test the array-based implementation\n"
		<< " or 'L' to test the link-based implementation: ";
	std::cin >> userChoice;
	if (toupper(userChoice) == 'A')
	{
		bagPtr = new ArrayBag <Point<double>>();
		std::cout << "Testing the Array-Based Bag:" << std::endl;
	}
	else
	{
		bagPtr = new LinkedBag <Point<double>>();
		std::cout << "Testing the Link-Based Bag:" << std::endl;
	} // end if

	bagTester(bagPtr);

	system("PAUSE");
	return 0;
}