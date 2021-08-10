#ifndef __INDEX_H
#define __INDEX_H

#define ARRAY_LENGTH 10000

#include "../until/iterator/iterator.h"
#include "../until/set/set.h"


void    idx_init();
bool    idx_isExist(Key key);
void    idx_insert(Key key, Value value);
void    idx_delete(Key key);
void    idx_update(Key key, Value value);
Value   idx_search(Key key);
KVArray idx_iterat();
void    idx_free();

#endif