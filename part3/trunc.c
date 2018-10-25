#include "list.h"
#include <stdio.h>
#include <malloc.h>
#include <ctype.h>
#include <string.h>

void print_s(element_t ev){
    char* e = ev;
    printf("%s\n", e);
}


void check_digit (element_t* rv, element_t av) {
    char* a = av;
    int **r = (int**) rv;
    if (*r == NULL)
        *r = malloc(sizeof(int));
    if(isdigit(a[0])){
        **r = strtol(a,NULL,10);
    }else{
        **r = -1;
    }
}

void check_string(element_t* rv, element_t av){
	char* a = av;
	char **r = (char**)rv;
	if (r == NULL)
		r = malloc(sizeof(element_t));
	if (isdigit(a[0])) {
		*r = NULL;
	}
	else {
		*r = a;
	}
}

int is_positive(element_t ev){
    int* v = ev;
    return *v>0;
}
int is_not_null(element_t ev){
    char* v = ev;
    return v!=NULL;
}

void truncate (element_t* rv, element_t av, element_t bv) {
    int *a = av;
    char *b = bv, **r = (char**) rv;
    if (r == NULL)
        r = malloc(sizeof(element_t));
    b[*a] = '\0';
    *r = b;
}

void join (element_t* rv, element_t av, element_t bv) {
    char *a = av, *b = bv, **r = (char**) rv;
    if (r == NULL)
        r = malloc(sizeof(char*));
    char *rs = (char *) malloc(strlen(a) + strlen(b));
    rs[0] = '\0';
    strcat(rs, a);
    strcat(rs, b);
    strcat(rs, " ");
    *r = rs;
}

void count (element_t* rv, element_t av, element_t bv) {
    int* a = av;
    int** r = (int**)rv;
    **r = *a+1;
}

int main(int argc, char **argv) {
    struct list* l0 = list_create();
    list_append_array(l0, (element_t*)argv+1, argc-1);

    struct list* number_list = list_create();
    list_map1(check_digit, number_list, l0);
    struct list* positive_number_list = list_create();
    list_filter(is_positive, positive_number_list, number_list);

    struct list* string_list = list_create();
    list_map1(check_string, string_list, l0);
    struct list* no_null_string_list = list_create();
    list_filter(is_not_null, no_null_string_list, string_list);

    struct list* truncate_list = list_create();
    list_map2(truncate, truncate_list, positive_number_list, no_null_string_list);

    list_foreach(print_s, truncate_list);

    char* s = "";
    char**sp = &s;
    list_foldl(join, (element_t*)sp, truncate_list);
    printf("%s", s);

    int sum = 0;
    int* sump = &sum;
    list_foldl(count, (element_t*)&sump, truncate_list);
    printf("\n%d", sum);


	list_destroy(l0);
	list_destroy(number_list);
	list_destroy(positive_number_list);
	list_destroy(string_list);
	list_destroy(no_null_string_list);
	list_destroy(truncate_list);

}