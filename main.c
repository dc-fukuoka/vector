#include <stdio.h>
#include <stdlib.h>
#include "vec.h"

int main(int argc, char **argv)
{
	int i;
	vector_t *p = NULL;
	/* char *str; */

	if (argc == 1) {
		fprintf(stderr, "usage: %s <arbitrary strings>\n", argv[0]);
		return -1;
	}

	for (i=1; i<argc; i++) {
		p = vec_push(p, argv[i]);
	}

	/*
        for (i=p->_size-1; i>=0; i--) {
                str = vec_pop(p);
                printf("vec[%d]: address: %p: %s\n", i, p->_str[i], str);
                free(str);
        }
        */
	vec_show(p);
	vec_clear(p);
	return 0;
}
