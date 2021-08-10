#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "test.h"
#include "../until/set/set.h"
#include "../src/index.h"
#include "../until/clean/clean.h"

void
main(){
	int len = 0;
	test_init();
	KVArray *kva_insert = set_generate_array(1000, 100);
	KVArray *kva_update = set_generate_array(1002, 100);
	clean_kvarray(kva_insert);
	//clean_kvarray(kva_update);
	
	KVArray *kva_insert_res =  set_init_kvarray(kva_insert->num);	
	test_insert_search(kva_insert, kva_insert_res);

	for(int i=0; i<kva_update->num;i++){
		kva_update->kv[i]->key = kva_insert->kv[i]->key;
	}
	
	KVArray *kva_update_res =  set_init_kvarray(kva_update->num);	
	KVArray *kva_delete_res =  set_init_kvarray(kva_insert->num);	

	test_update_search(kva_update, kva_update_res);
	test_delete_search(kva_insert, kva_delete_res);
	
	//set_free_array(kva_insert_res);
	//set_free_array(kva_update_res);
	//set_free_array(kva_delete_res);
	
	test_exit();
}