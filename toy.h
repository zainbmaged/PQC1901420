#include <stdlib.h>
#include<string.h>
#include <stdio.h>
#include <stdint.h>

#define TK_K 3
#define TK_N 4
#define TK_Q 97
//polynomial multiplication in Z97[X]/(X^4+1)
static void toy_polmul_naive(
short *dst,
const short *a,
const short *b,
int add //if true: dst += a*b; if false: dst = a*b;
);

void toy_gen(short *A, short *t, short *s);
void toy_enc(const short *A, const short *t, int plain, short *u, short *v);
int toy_dec(const short *s, const short *u, const short *v);