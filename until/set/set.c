#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "set.h"

/*
* 初始化value，本质上是初始化一个字符串，分为两步
* 	1.初始化内存空间，长度为字符长度加1，1是\0的长度
* 	2.在内存空间的末尾填入\0
* int@length: 字符串长度
* return Value(char *): 初始化好的字符串
*/
Value
set_init_value(int length){
	Value value = (Value)malloc(sizeof(char) * (length + 1));
	value[length] = '\0';
	return value;
}

/*
* 初始化KV键值对，主要是申请内存空间
* return KV*: 初始化好的KV键值对
*/
KV*
set_init_kv(){
	KV *kv = (KV*)malloc(sizeof(KV));
	
	return kv;
}

/*
* 初始化KV数组，主要是三步
* 	1.申请数组结构体空间
* 	2.申请数组空间
* 	3.填充数组大小
*/
KVArray*
set_init_kvarray(int num){
	KVArray *kva = (KVArray *)malloc(sizeof(KVArray));
	kva->kv = (KV **)malloc(sizeof(KV*) * num);
	kva->num = num;
	
	for(int i=0;i<num; i++){
		kva->kv[i] = (KV*)malloc(sizeof(KV));
		kva->kv[i]->key   = 0;
		kva->kv[i]->value = NULL;
	}
	
	return kva;
}

Key 
set_generate_key(Seed seed){
	int num = 0;
	
	srand(seed);
	num = rand();
	
	return num % MAX_KEY_LENGTH;
}

/*
* 48-57 0-9
* 65-90 A-Z
* 97-122 a-z
*/
Value
set_generate_value(Seed seed){
	int num = 0;
	int length = 0;
	int ascii = 0;
	
	Value value;
	
	srand(seed);
	num = rand();
	
	length = num % MAX_VALUE_LENGTH;
	value = set_init_value(length);
	
	for(int i=0; i< length; i++){
		ascii = i * num;
	    if(ascii < 0)
			ascii = -1 * ascii;
		ascii %= 128;
		if(ascii < 48)
			ascii = ascii % 10 + 48;
		else if(ascii> 57 && ascii < 65)
			ascii = ascii % 26 + 65;
		else if(ascii > 90 && ascii < 97)
			ascii = ascii % 26 + 97;
		else if(ascii > 122)
			ascii = ascii - 5;
		
		value[i] = (char)(ascii);
		while(value[i] == '\0'){
			value[i] ++;
			value[i] %= 128;
		}
	}
	
	return value;
}

KV* 
set_generate_kv(Seed seed){
	KV *kv = set_init_kv();
	kv->key = set_generate_key(seed);
	kv->value = set_generate_value(seed);
	
	return kv;
}

KVArray* 
set_generate_array(Seed seed, int num){
	KVArray* kva = set_init_kvarray(num);
		
	for(int i=0; i<num; i++){
		kva->kv[i] = set_generate_kv(i * seed);
	}

	kva->num = num;
	return kva;
}

void 
set_free_kv(KV **kv, int num){
	assert(num >=0);

	for(int i=0; i<num; i++){
		if(kv[i] != NULL){
			if(kv[i]->value != NULL)
				free(kv[i]->value);
			free(&kv[i]);
		}
	}
	
	free(kv);
}


void
set_free_array(KVArray *kva){
	set_free_kv(kva->kv, kva->num);
	free(kva);
}

long double
set_long_double_mod(long double value, int mod){
	long reslut = (long)(value / mod);
	return value - reslut * mod;
}

DataUnit*
set_calculate_dataUnit(long double size){
	DataUnit *dataUnitRes = (DataUnit*)malloc(sizeof(DataUnit));
	double value = 0;
	dataUnitRes->type = DT_B;
	
	// size < 1024 || (type = GB && size >=1024)
	while(size >= 1024 && (dataUnitRes->type < DT_NUM - 1 || size < 1024)){
		value = set_long_double_mod(size, 1024); 
		size /= 1024;
		if(size < 1024)
			size = value;
		dataUnitRes->type ++;
	}
	
	dataUnitRes->value = size;
	return dataUnitRes;
}

void
set_calculate_dataSize(DataSize *dataSize){
	DataUnit *dataUnit = set_calculate_dataUnit((long double)(dataSize->BValue));
	dataSize->value = dataUnit->value;
	dataSize->type  = dataUnit->type;
}

void
set_calculate_dataSpeed(long long size, DataSpeed *dataSpeed){
	DataUnit *dataUnit = set_calculate_dataUnit((long double)(1000000*size/dataSpeed->time));
	dataSpeed->value = dataUnit->value;
	dataSpeed->type  = dataUnit->type;
}

DataSize*
set_array_size(KVArray* kva){
	DataSize *dataSize = (DataSize *)malloc(sizeof(DataSize));
	dataSize->BValue = 0;
	
	for(int i=0; i<kva->num; i++){
		dataSize->BValue += sizeof(char) * (strlen((kva->kv[i]->value)) + 1) + sizeof(kva->kv[i]->key);
	}
	
	return dataSize;
} 

char*
set_array_size_type_char(DataType dataType){
	switch(dataType){
		case DT_B:
			return "B";
		case DT_KB:
			return "KB";
		case DT_MB:
			return "MB";
		case DT_GB:
			return "GB";
		default:
			return "Invaild";
	}
	
	return "NULL";
}

void
set_print_dataset(char *name, DataSet *insert){
	printf("%s size = %f%s, speed = %f%s/s\n", 
				name,
				insert->dataSize->value, 
				set_array_size_type_char(insert->dataSize->type),
				insert->dataSpeed->value,
				set_array_size_type_char(insert->dataSpeed->type));
}