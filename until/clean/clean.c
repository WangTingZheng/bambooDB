#include "clean.h"
#include "../libbloom/bloom.h"

void 
clean_kvarray(KVArray *kva){
	struct bloom bloom;
	int seed = 0;
	bloom_init(&bloom, 1000000, 0.01);
	for(int i=0;i<kva->num; i++){
		while(bloom_check(&bloom,  (void *)&(kva->kv[i].key), sizeof(kva->kv[i].key))){
			kva->kv[i].key = set_generate_key(seed);
			seed ++;
		}
		bloom_add(&bloom, (void *)&(kva->kv[i].key), sizeof(kva->kv[i].key));
	}
}