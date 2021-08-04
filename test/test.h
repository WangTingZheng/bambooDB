#ifndef __TEST_H
#define __TEST_H

#include <stdbool.h>
#include "../until/set/set.h"

void test_init();
bool test_insert_search(KVArray *kva);
bool test_update_search(KVArray *kva);
bool test_delete_search(KVArray *kva);
bool test_all(KVArray *kva_insert, KVArray *kva_update, KVArray *kva_delete);
void test_exit();

#endif