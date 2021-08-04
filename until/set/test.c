#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "set.h"

bool 
test_key(int test_num){
	for(int i = 0; i<test_num; i++){
		if(set_generate_key(i) >= MAX_KEY_LENGTH)
			return false;
	}
	
	return true;
}

bool
test_value(int test_num){
	for(int i=0; i < test_num; i++){
		if(strlen(set_generate_value(i)) >= MAX_VALUE_LENGTH)
			return false;
	}
	
	return true;
}

bool
test_kv(int test_num){
	KV kv;
	for(int i=0; i < test_num; i++){
		kv = set_generate_kv(i);
		if(kv.key >= MAX_KEY_LENGTH || strlen(kv.value) >= MAX_VALUE_LENGTH)
			return false;
	}
	
	return true;
}

bool
test_array(int test_num){
	KVArray kva = set_generate_Array(1202, test_num);
	for(int i=0; i< test_num; i++){
		if(kva.kv[i].key >= MAX_KEY_LENGTH || strlen(kva.kv[i].value) >= MAX_VALUE_LENGTH)
		return false;
	}
	
	return true;
}

void main(){
	int test_num = 100;
	
	assert(test_key(test_num));
	assert(test_value(test_num));
	assert(test_kv(test_num));
	assert(test_array(test_num));
}