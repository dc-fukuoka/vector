#ifndef VEC_H
#define VEC_H

#include "vec_priv.h"

vector_t *vec_push(vector_t *q, const char *str);
char     *vec_pop(vector_t *p);
void      vec_show(vector_t *p);
void      vec_clear(vector_t *p);

#endif /* VEC_H */
