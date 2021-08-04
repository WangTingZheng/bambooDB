#ifndef __ITERATOR_H
#define __ITERATOR_H

#include "../set/set.h"

typedef struct NODE* KVNode;
struct NODE{
	KV kv;
	KVNode* next;
};

KVNode iter_next(KVNode kvnode);

#endif