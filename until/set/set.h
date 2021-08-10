#ifndef __SET_H
#define __SET_H

#define MAX_KEY_LENGTH   1024
#define MAX_VALUE_LENGTH 100

typedef unsigned int Seed;
typedef int Key;
typedef char* Value;

typedef struct{
	Key key;
	Value value;
}KV;

typedef struct{
	KV **kv;
	int num;
}KVArray;

typedef enum {DT_B, DT_KB, DT_MB, DT_GB, DT_NUM}DataType;

typedef struct{
    double value;
	DataType type;
}DataUnit;

typedef struct{
	long long BValue;
	double value;
	DataType type;
}DataSize;

typedef struct{
	double value;
	DataType type;
	long long time; //us
}DataSpeed;

typedef struct{
	DataSize  *dataSize;
	DataSpeed *dataSpeed;
}DataSet;

Value     set_init_value(int length);
KV*       set_init_kv();
KVArray*  set_init_kvarray(int num);
Key       set_generate_key(Seed seed);
Value     set_generate_value(Seed seed);
KV*       set_generate_kv(Seed seed);
KVArray*  set_generate_array(Seed seed, int num);

void      set_free_kv(KV *	*kv, int num);
void      set_free_array(KVArray *kva);

DataUnit* set_calculate_dataUnit(long double size);
void      set_calculate_dataSize(DataSize *dataSize);
void      set_calculate_dataSpeed(long long size, DataSpeed *dataSpeed);
DataSize* set_array_size(KVArray* kva);
char*     set_array_size_type_char(DataType dataType);
void      set_print_dataset(char *name, DataSet *insert);

#endif