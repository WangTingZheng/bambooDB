#ifndef __TIME_H
#define __TIME_H
#include "../set/set.h"
#include <sys/time.h>

void time_start();
void time_end();
long long time_gettime();
DataSpeed *time_get_dataspeed();

#endif