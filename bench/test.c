#include "bench.h"
#include "../until/clean/clean.h"

void 
main(){
	bench_init();
	
	KVArray *kva_insert = set_generate_array(1000, 1000);
	KVArray *kva_update = set_generate_array(1002, 1000);
	clean_kvarray(kva_insert);
	
	for(int i=0; i<kva_update->num;i++){
		kva_update->kv[i].key = kva_insert->kv[i].key;
	}
	
	DataSet *insert = bench_insert_search(kva_insert);
	DataSet *update = bench_update_search(kva_update);
	DataSet *delete = bench_delete_search(kva_update);
	
	set_print_dataset("insert", insert);
	set_print_dataset("update", update);
	set_print_dataset("delete", delete);
}