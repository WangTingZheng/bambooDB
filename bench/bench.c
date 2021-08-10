#include "../until/time/time.h"
#include "../until/set/set.h"
#include "../test/test.h"
#include <stdlib.h>
#include <stdio.h>

void
bench_init(){
	test_init();
}

DataSet*
bench_prepare(){
	DataSet   *dataSet = (DataSet *)malloc(sizeof(DataSet));
	time_start();
	
	return dataSet;
}

DataSet* 
bench_return(DataSet *dataSet, KVArray *kva){
	time_end();
	
	DataSize  *dataSize = set_array_size(kva);
	DataSpeed *dataSpeed = time_get_dataspeed();
	
	set_calculate_dataSize(dataSize);
	set_calculate_dataSpeed(dataSize->BValue ,dataSpeed);
	
	dataSet->dataSize  = dataSize;
	dataSet->dataSpeed = dataSpeed;
	
	return dataSet;
}

DataSet* 
bench_insert_search(KVArray *kva, KVArray *kva_insert_res){
	DataSet *dataSet = bench_prepare();
	
	if(!test_insert_search(kva, kva_insert_res)){
		printf("test do not passed\n");
		return NULL;
	}
	return bench_return(dataSet, kva);
}


DataSet* 
bench_update_search(KVArray *kva, KVArray *kva_update_res){
	DataSet *dataSet = bench_prepare();
	
	if(!test_update_search(kva, kva_update_res)){
		printf("test do not passed\n");
		return NULL;
	}
	return bench_return(dataSet, kva);
}


DataSet* 
bench_delete_search(KVArray *kva, KVArray *kva_delete_res){
	DataSet *dataSet = bench_prepare();

	if(!test_delete_search(kva, kva_delete_res)){
		printf("test do not passed\n");
		return NULL;
	}
	return bench_return(dataSet, kva);
}

void
bench_exit(){
	test_exit();
}