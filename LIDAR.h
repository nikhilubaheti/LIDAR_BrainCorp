#ifndef LIDAR__h
#define LIDAR__h
#include <vector>
#define noOfScans_min 200
#define noOfScans_max 1000

typedef std::vector<double> array1D;

class LIDAR
{
	array1D data;
	int noOfScans;
	const float read_max = 50, read_min = 0.03;// every reading lies in range [read_max,read_min]
public:
	LIDAR();//constructor
	
	LIDAR(int value); // sets noOfScans to value
	
	void setData(); //random initializes n-scans 200<=n<=1000
	
	void setData(array1D value);// sets data to value
	
	array1D getData(); //returns data

	void displayData(); // displays the current data
	
	bool setScans(int value); // returns false if value outside range; else sets noOfScans to value
	
	int getScan();

	void clearData();
};
#endif
