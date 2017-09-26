#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vec.h"

vector_t *vec_push(vector_t *q, const char *str) {
	vector_t *p = NULL;
	static size_t size = 1;

	if (!q) {
		p = (vector_t*)malloc(sizeof(*p));
		p->_str = (char**)malloc(sizeof(*(p->_str))*size);
		p->_str[size-1] = malloc(sizeof(*str)*(strlen(str)+1));
		strcpy(p->_str[size-1], str);
		p->_size = size++;
		return p;
	} else {
		q->_str = (char**)realloc(q->_str, sizeof(*(q->_str))*size);
		q->_str[size-1] = malloc(sizeof(*str)*(strlen(str)+1));
		strcpy(q->_str[size-1], str);
		q->_size = size++;
		return q;
	}

}

char *vec_pop(vector_t *p)
{
	char *str = NULL;
	size_t size = p->_size;
	
	if (size == 0)
		return NULL;
	
	str = strdup(p->_str[size-1]);
	free(p->_str[size-1]);
	p->_size--;
	p->_str = (char**)realloc(p->_str, sizeof(*(p->_str))*size);
	return str;
}

void vec_show(vector_t *p)
{
	size_t size = p->_size;
	int i;
	for (i=0; i<size; i++)
		printf("vec[%d]: address: %p: %s\n", i, &p->_str[i], p->_str[i]);
}

void vec_clear(vector_t *p)
{
	int i;
	size_t size = p->_size;
	for (i=0; i<size; i++) {
		free(p->_str[i]);
	}
	free(p->_str);
	free(p);
}
