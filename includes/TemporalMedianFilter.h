#ifndef TemporalMedianFilter__h
#define TemporalMedianFilter__h
#include "Filter.h"
#include <vector>
#define D_max 10

typedef std::vector<std::vector<double>> array2D;
typedef std::vector<double> array1D;

class TemporalMedianFilter: public Filter {
	int D,N,T;
	array2D *data;
public:
	TemporalMedianFilter(int d, int n); //always set the memory when constructing filter

	TemporalMedianFilter(int n); //randomly choose D
	
	void setProperty(int d, int n);// change memory length of filter and reset filter data
	
	array1D update(array1D value); //returns the median of current and past D values

	int getD();
};

#endif
