#ifndef __TEST_H
#define __TEST_H

#include <stdbool.h>
#include "../until/set/set.h"

void test_init();
bool test_insert_search(KVArray *kva, KVArray *kva_res);
bool test_update_search(KVArray *kva, KVArray *kva_res);
bool test_delete_search(KVArray *kva, KVArray *kva_res);
void test_exit();

#endif