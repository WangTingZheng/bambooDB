#include <stdio.h>
#include "index.h"

void 
main(){
	//169
	//01656M0aH5fClkBg6Gb1L5670z2547N9sI4eDmjAh7Fc2K4709y3438O8rJ3dEniMi8Ed3J3818x4329P7qK2,
	//01656301856J01B5690145670125w
	idx_init();
	idx_insert(10000, "123411111");
	idx_insert(10000, "4321ABC");
	printf("res = %s", idx_search(10000));
}