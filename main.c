#include "toy.h"
#include "toy.c"

static void print_b(int x,int n){
    for(int i=0;i<n;i++){
        printf("%d",x>>(n-1-i)&1);
    }
}

int main(int argc, char** argv){

short A[TK_K*TK_K*TK_N ];//public key

short t[TK_K*TK_N];
short s[TK_K*TK_N];//private key

toy_gen(A, t, s);
for(int msg=0;msg<16;++msg){
    short u[TK_K*TK_N];
    short v[TK_N];

    toy_enc(A, t, msg, u, v);
    short m2=toy_dec(s, u, v);
    printf("%2d %2d ",msg,m2);
    print_b(msg, TK_N);
    printf("  ");
    print_b(m2, TK_N);
    printf("  ");
    print_b(msg^m2, TK_N);
    
    printf("\n");
}
printf("well done\n");
return 0;
}