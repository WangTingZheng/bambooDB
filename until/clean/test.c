#include <stdio.h>
#include "clean.h"
#include "../set/set.h"

void
main(){
	KVArray *kva = set_generate_array(1002, 100);
	
	for(int i=0; i<kva->num; i++){
		printf("key = %d\n", kva->kv[i].key);
	}
	
	printf("\n");
	clean_kvarray(kva);
	
	for(int i=0; i<kva->num; i++){
		printf("key = %d\n", kva->kv[i].key);
	}
}