#ifndef RangeFilter__h
#define RangeFilter__h
#include "Filter.h"

typedef std::vector<double> array1D;

class RangeFilter: public Filter {
	double max_range, min_range;
public:
	RangeFilter(double high, double low); // initialize filter properties while constructing filter

	void setProperty(double high, double low); // change filter properties

	array1D update(array1D value); // returns the cliped values of the data

	double getMaxRange(); // returns the upper cut off of filter

	double getMinRange(); // returns the lower cut off of filter
};

#endif
