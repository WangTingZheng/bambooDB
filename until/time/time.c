#include <stddef.h>
#include <stdlib.h>
#include "time.h"
struct timeval time_start_struct;
struct timeval time_end_struct;

void 
time_start(){
	gettimeofday(&time_start_struct, NULL);
}

void 
time_end(){
	gettimeofday(&time_end_struct, NULL);
}

long long
time_gettime(){
	return (1000000 * (time_end_struct.tv_sec - time_start_struct.tv_sec) +
		   time_end_struct.tv_usec - time_start_struct.tv_usec);
}

DataSpeed *
time_get_dataspeed(){
	DataSpeed *dataSpeed = (DataSpeed *)malloc(sizeof(DataSpeed));
	dataSpeed->time = time_gettime();
	
	return dataSpeed;
}