#include <string.h>
#include <stdlib.h>
#include "index.h"

char **array;

void   
idx_init(){
	array = (char **)malloc(sizeof(char*) * ARRAY_LENGTH);
	for(int i=0; i < ARRAY_LENGTH; i++){
		array[i] = NULL;
	}
}

void   
idx_insert(Key key, Value value){
	int len = strlen(value) + 1;
	if(array[key]){
		free(array[key]);
		array[key] = NULL;
	}
	array[key] = (char *)malloc(sizeof(char) * (len + 1));
	memcpy(array[key], value, len + 1);
}

void
idx_delete(Key key){
	free(array[key]);
	array[key] = NULL;
}

void   
idx_update(Key key, Value value){
	idx_insert(key, value);
}

Value  
idx_search(Key key){
	return array[key];
}

KVArray
idx_iterat(){
	int num = 0;
	int len =0;
	KVArray kva;
	
	kva.kv = (KV *)malloc(sizeof(KV) * ARRAY_LENGTH);
	
	for(int i=0; i< ARRAY_LENGTH; i++){
		if(array[i] != NULL){
			num ++;
			len = strlen(array[i]);
			kva.kv[i].key = i;
			kva.kv[i].value = (Value)malloc(sizeof(char) * len);
			memcpy(kva.kv[i].value, array[i], len + 1);
		}
	}
	
	kva.num = num;
	return kva;
}

void   
idx_free(){
	for(int i=0; i< ARRAY_LENGTH; i++){
		free(array[i]);
	}
	
	free(array);
}