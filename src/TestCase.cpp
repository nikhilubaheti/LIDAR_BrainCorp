#include "includes/TestCase.h"
#include "includes/LIDAR.h"
#include "includes/RangeFilter.h"
#include "includes/TemporalMedianFilter.h"
#include <iostream>

typedef std::vector<double> array1D;

void TestCaseUserDefined()
{
	LIDAR L1;
	
	int noOfScan = 0, D, R_max,R_min;
	float ScanValue = 0.0;
	array1D data;
	
	// get number of scans from user
	
	do {
		std::cout << "Enter number of scans per LIDAR reading(200 to 1000):";
		std::cin >> noOfScan;
	} while (!L1.setScans(noOfScan));
	
	//get filter properties
	std::cout << "Enter R_max(upper cut off of Range filter):";
	std::cin >> R_max;

	std::cout << "Enter R_min(lower cut off of Range filter):";
	std::cin >> R_min;

	std::cout << "Enter D(size of filter depth):";
	std::cin >> D;


	RangeFilter RF(R_max,R_min);
	TemporalMedianFilter TMF(D, L1.getScan());

	while (1)
	{
		// initialize data
		data.clear(); //to delete previous loop data
		for (int i = 0; i < L1.getScan(); i++)
		{
			std::cout << std::endl << "Enter Data " << i <<"/" << L1.getScan() << ": ";
			std::cin >> ScanValue;
			data.push_back(ScanValue);
		}
		L1.setData(data);
		L1.displayData();

		//process filter
		array1D RFOutput = RF.update(L1.getData());
		array1D TMFOutput = TMF.update(L1.getData());

		//Print updates
		std::cout <<std::endl<< "Output of Range Filter is: ";
		for (array1D::iterator it = RFOutput.begin(); it != RFOutput.end(); ++it)
			std::cout << *it << " ";

		std::cout << std::endl << "Output of Temporal Median Filter with " << TMF.getD() << " is: ";
		for (array1D::iterator it = TMFOutput.begin(); it != TMFOutput.end(); ++it)
			std::cout << *it << " ";

		//clear data so that available for next iteration
		L1.clearData();

		//break if no
		char c;
		std::cout << std::endl << "Do you want to continue? (y/n)";
		std::cin >> c;
		if (c == 'n' || c == 'N')
			break;
		
	}
}

void TestCaseRandom()
{
	LIDAR L1;
	RangeFilter RF(40, 5);
	TemporalMedianFilter TMF(L1.getScan());

	//print filter properties
	std::cout << "Default Filter Properties: " << std::endl;
	std::cout << "N: " << L1.getScan();
	std::cout << " R_max: " << RF.getMaxRange();
	std::cout << " R_min: " << RF.getMinRange();
	std::cout << " D: " << TMF.getD();

	while (1)
	{
		// initialize data
		L1.setData();
		L1.displayData();

		//process filter
		array1D RFOutput = RF.update(L1.getData());
		array1D TMFOutput = TMF.update(L1.getData());

		//Print updates
		std::cout << std::endl << "Output of Range Filter is: ";
		for (array1D::iterator it = RFOutput.begin(); it != RFOutput.end(); ++it)
			std::cout << *it << " ";

		std::cout << std::endl << "Output of Temporal Median Filter with " << TMF.getD() << " is: ";
		for (array1D::iterator it = TMFOutput.begin(); it != TMFOutput.end(); ++it)
			std::cout << *it << " ";

		//clear data for next iteration
		L1.clearData();

		//break if no
		char c;
		std::cout << std:: endl << "Do you want to continue? (y/n)";
		std::cin >> c;
		if (c == 'n' || c == 'N')
			break;

	}
}

void DefaultTestCase()
{
	LIDAR L1(5);
	RangeFilter RF(6, 1);
	TemporalMedianFilter TMF(3,L1.getScan());

	//print filter properties
	std::cout << "Default Filter Properties: " << std::endl;
	std::cout << "N: " << L1.getScan();
	std::cout << " R_max: " << RF.getMaxRange();
	std::cout << " R_min: " << RF.getMinRange();
	std::cout << " D: " << TMF.getD();

	//LIDAR data
	double d[5][5] = { {0,1,2,1,3},
					{1,5,7,1,3},
					{2,3,4,1,0},
					{3,3,3,1,3},
					{10,2,4,0,0} };

	for(int i = 0; i < 5; i++)
	{
		// initialize data
		array1D X(d[i], d[i] + 5);
		L1.setData(X);
		L1.displayData();

		//process filter
		array1D RFOutput = RF.update(L1.getData());
		array1D TMFOutput = TMF.update(L1.getData());

		//Print updates
		std::cout << std::endl << "Output of Range Filter is: ";
		for (array1D::iterator it = RFOutput.begin(); it != RFOutput.end(); ++it)
			std::cout << *it << " ";

		std::cout << std::endl << "Output of Temporal Median Filter with " << TMF.getD() << " is: ";
		for (array1D::iterator it = TMFOutput.begin(); it != TMFOutput.end(); ++it)
			std::cout << *it << " ";

		//clear data for next iteration
		L1.clearData();

		//break if no
		char c;
		std::cout << std::endl << "Do you want to continue? (y/n)";
		std::cin >> c;
		if (c == 'n' || c == 'N')
			break;

	}
}
