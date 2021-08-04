#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include "../src/index.h"
#include "../until/set/set.h"
#include "test.h"

void 
test_init(){
	idx_init();
}

bool 
test_insert_search(KVArray *kva){
	KVArray *kva_res =  set_init_kvarray(kva->num);
	int notPassed = 0;	
	
	for(int i=0; i<kva->num; i++){
		idx_insert(kva->kv[i].key, kva->kv[i].value);
	}
	
	for(int i=0; i<kva->num; i++){
		kva_res->kv[i].key = kva->kv[i].key;
		kva_res->kv[i].value = idx_search(kva->kv[i].key);
		if(strcmp(kva_res->kv[i].value, kva->kv[i].value) != 0){
			printf("key = %d, origin value = %s, result value = %s\n", 
					kva->kv[i].key, 
					kva->kv[i].value,
					kva_res->kv[i].value);
			notPassed += 1;
		}
	}
	
	printf("success: %d/%d\n", kva->num - notPassed, kva->num);
	return notPassed == 0;
}

bool
test_update_search(KVArray *kva){
	KVArray *kva_res =  set_init_kvarray(kva->num);
	int notPassed = 0;	
	
	for(int i=0; i<kva->num; i++){
		idx_update(kva->kv[i].key, kva->kv[i].value);
	}
	
	for(int i=0; i<kva->num; i++){
		kva_res->kv[i].key = kva->kv[i].key;
		kva_res->kv[i].value = idx_search(kva_res->kv[i].key);
		if(strcmp(kva_res->kv[i].value, kva->kv[i].value) != 0){
			printf("key = %d, origin value = %s, result value = %s\n", 
					kva->kv[i].key, 
					kva->kv[i].value,
					kva_res->kv[i].value);
			notPassed += 1;
		}
	}
	
	printf("success: %d/%d\n", kva->num - notPassed, kva->num);
	return notPassed == 0;
}


bool
test_delete_search(KVArray *kva){
	KVArray *kva_res =  set_init_kvarray(kva->num);	
	int notPassed = 0;	
	
	for(int i=0; i<kva->num; i++){
		idx_delete(kva->kv[i].key);
	}
	
	for(int i=0; i<kva->num; i++){
		kva_res->kv[i].key = kva->kv[i].key;
		kva_res->kv[i].value = idx_search(kva_res->kv[i].key);
		if(kva_res->kv[i].value != NULL){
			printf("key = %d, origin value = %s, result value = %s\n", 
					kva->kv[i].key, 
					kva->kv[i].value,
					kva_res->kv[i].value);
			notPassed += 1;
		}
	}
	
	printf("success: %d/%d\n", kva->num - notPassed, kva->num);
	return notPassed == 0;
}

bool
test_all(KVArray *kva_insert, KVArray *kva_update, KVArray *kva_delete){
	return test_insert_search(kva_insert) && test_update_search(kva_update) && test_delete_search(kva_delete);
}

void
test_exit(){
	idx_free();
}