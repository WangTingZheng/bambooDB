#ifndef __BENCH_H
#define __BENCH_H

#include <stdbool.h>
#include "../until/set/set.h"

void     bench_init();
DataSet *bench_insert_search(KVArray *kva);
DataSet *bench_update_search(KVArray *kva);
DataSet *bench_delete_search(KVArray *kva);
void     bench_exit();

#endif