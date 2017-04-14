#include "TemporalMedianFilter.h"
#include <algorithm>
#include <random>
#include <iostream>

TemporalMedianFilter::TemporalMedianFilter(int d, int n)
{
	this->D = d;
	this->N = n;
	this->T = 0;

	this->data = new array2D(this->N,array1D(this->D+1,0));
}

TemporalMedianFilter::TemporalMedianFilter(int n)
{

	this->D = rand() % D_max;
	this->N = n;
	this->T = 0;

	this->data = new array2D(this->N, array1D(this->D + 1, 0));
}

void TemporalMedianFilter::setProperty(int d, int n)
{
	this->D = d;
	this->N = n;
	this->T = 0;

	this->data = new array2D(this->N, array1D(this->D + 1, 0)); 		
}

array1D TemporalMedianFilter::update(array1D value)
{
	array1D median(this->N, 0);
	this->T++;

	//add elements to data and delete last element
	for (int i = 0; i < this->N; ++i)
	{
		this->data[0][i].insert(this->data[0][i].begin(),value[i]);
		this->data[0][i].pop_back();

		//find median
		array1D temp(this->data[0][i]); //copy the array
		int length = std::min(this->T, this->D + 1);
		std::sort(temp.begin(), temp.begin()+length); // sort the array
		
		if (length % 2 == 0)
			median[i] = (temp[length / 2 - 1] + temp[length / 2]) / 2;
		else
			median[i] = temp[length / 2];

	}
	return median;
}

int TemporalMedianFilter::getD()
{
	return this->D;
}
