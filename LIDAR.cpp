#include "LIDAR.h"
#include <random>
#include <time.h>
#include <algorithm>
#include <iostream>

LIDAR::LIDAR()
{
	//The number of scans is considered as a constant for every LIDAR sensor
	// Thus it is initialized in the constructor
	this->noOfScans = std::min(rand() % noOfScans_max, noOfScans_min);// noOfScans_min <= noOfScans <= noOfScans_max
}

LIDAR::LIDAR(int value)
{
	if ((value > noOfScans_max || value < noOfScans_min) && value != 5)
	{
		std::cout << "Error: Please enter number of scans in range " << noOfScans_min << " to " << noOfScans_max;
	}
	
	else
	{
		this->noOfScans = value;
	}
}

void LIDAR::setData()
{
	float r;
	for (int i = 0; i < this->noOfScans; i++)
	{
		r = this->read_min + float(rand())/RAND_MAX*this->read_max;
		this->data.push_back(r);
	}
}

void LIDAR::setData(array1D value)
{
	for (std::vector<double>::iterator it = value.begin(); it != value.end(); ++it)
	{
		this->data.push_back(*it);
	}
}

array1D LIDAR::getData()
{
	return this->data;
}

void LIDAR::displayData()
{
	std::cout << std::endl << "LIDAR data is: ";
	for (array1D::iterator it = this->data.begin(); it != this->data.end(); ++it)
		std::cout << *it << " ";
}

bool LIDAR::setScans(int value)
{
	if ((value > noOfScans_max || value < noOfScans_min) && value != 5)
	{
		std::cout << "Error: Please enter number of scans in range " << noOfScans_min << " to " << noOfScans_max << std::endl;
		return false;
	}
		
	else
	{
		this->noOfScans = value;
		return true;
	}
}

int LIDAR::getScan()
{
	return this->noOfScans;
}

void LIDAR::clearData()
{
	this->data.clear();
}
