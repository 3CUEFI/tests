#include <stdlib_tainted.h>
#include <stdio.h>
#include <string.h>

typedef Tstruct Sample{
	_TPtr<int> ptr1;
	_TPtr<char> name;
	double val;
}SP;

int main()
{
	_TPtr<SP> sp_val = (_TPtr<SP>)t_malloc(sizeof(Tstruct Sample));
	_TPtr<int> ptr1_val = t_malloc(10*sizeof(int));
	_TPtr<char> name_val = t_malloc(11*sizeof(char));
	char* my_name = "Arunkumar";
	*ptr1_val = 100;
	sp_val->ptr1 = ptr1_val;
	
	strncpy(sp_val->name, my_name, strlen(my_name));
	sp_val->val = 32953253.193239;

	        // Print the values
        printf("Value pointed to by ptr1: %d\n", *(sp_val->ptr1));
        printf("Name: %s\n", sp_val->name);
        printf("Val: %lf\n", sp_val->val);

        // Free allocated memory
        t_free(ptr1_val);
        t_free(name_val);
        t_free(sp_val);

	return 0;
}
