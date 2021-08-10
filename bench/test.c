#include "bench.h"
#include "../until/clean/clean.h"

void 
main(){
	bench_init();
	
	KVArray *kva_insert = set_generate_array(1000, 1000);
	KVArray *kva_update = set_generate_array(1002, 1000);
	clean_kvarray(kva_insert);
	
	for(int i=0; i<kva_update->num;i++){
		kva_update->kv[i]->key = kva_insert->kv[i]->key;
	}
	KVArray *kva_insert_res = set_init_kvarray(kva_insert->num);
	KVArray *kva_update_res = set_init_kvarray(kva_insert->num);
	KVArray *kva_delete_res = set_init_kvarray(kva_insert->num);
	
	DataSet *insert_dataSet = bench_insert_search(kva_insert, kva_insert_res);
	DataSet *update_dataSet = bench_update_search(kva_update, kva_insert_res);
	DataSet *delete_dataSet = bench_delete_search(kva_update, kva_insert_res);
	
	set_print_dataset("insert", insert_dataSet);
	set_print_dataset("update", update_dataSet);
	set_print_dataset("delete", delete_dataSet);
}