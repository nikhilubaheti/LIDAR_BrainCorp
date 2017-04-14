#ifndef Filter__h
#define Filter__h
#include "LIDAR.h"

typedef std::vector<double> array1D;

//Abstract class
class Filter {
public:
	virtual array1D update(array1D value) = 0;
};

#endif
