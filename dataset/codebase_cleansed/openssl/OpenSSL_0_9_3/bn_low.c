int BN_mul_low(BIGNUM *r, BIGNUM *a, BIGNUM *b, int num)
{
BN_ULONG *ap,*bp,*rp;
BIGNUM *sk;
int j,i,n,ret;
int max,al,bl;
BN_CTX ctx;
bn_check_top(a);
bn_check_top(b);
#ifdef BN_MUL_DEBUG
printf("BN_mul_low(%d,%d,%d)\n",a->top,b->top,num);
#endif
al=a->top;
bl=b->top;
if ((al == 0) || (bl == 0))
{
r->top=0;
return(1);
}
if ((bn_limit_bits_low > 0) && (num > bn_limit_num_low))
{
n=BN_num_bits_word(num*2)-bn_limit_bits_low;
n*=2;
sk=(BIGNUM *)Malloc(sizeof(BIGNUM)*n);
memset(sk,0,sizeof(BIGNUM)*n);
memset(&ctx,0,sizeof(ctx));
ret=bn_mm_low(r,a,b,num,&(sk[0]),&ctx);
for (i=0; i<n; i+=2)
{
BN_clear_free(&sk[i]);
BN_clear_free(&sk[i+1]);
}
Free(sk);
return(ret);
}
max=(al+bl);
if (bn_wexpand(r,max) == NULL) return(0);
r->neg=a->neg^b->neg;
ap=a->d;
bp=b->d;
rp=r->d;
r->top=(max > num)?num:max;
rp[al]=bn_mul_words(rp,ap,al,*(bp++));
rp++;
j=bl;
for (i=1; i<j; i++)
{
if (al >= num--)
{
al--;
if (al <= 0) break;
}
rp[al]=bn_mul_add_words(rp,ap,al,*(bp++));
rp++;
}
while ((r->top > 0) && (r->d[r->top-1] == 0))
r->top--;
return(1);
}
int bn_mm_low(BIGNUM *m, BIGNUM *A, BIGNUM *B, int num, BIGNUM *sk,
BN_CTX *ctx)
{
int n;
int an,bn;
BIGNUM ah,al,bh,bl;
bn_wexpand(m,num+3);
an=A->top;
bn=B->top;
#ifdef BN_MUL_DEBUG
printf("bn_mm_low(%d,%d,%d)\n",A->top,B->top,num);
#endif
n=(num+1)/2;
BN_init(&ah); BN_init(&al); BN_init(&bh); BN_init(&bl);
bn_set_low( &al,A,n);
bn_set_high(&ah,A,n);
bn_set_low( &bl,B,n);
bn_set_high(&bh,B,n);
if (num <= (bn_limit_num_low+bn_limit_num_low))
{
BN_mul(m,&al,&bl);
BN_mul_low(&t1,&al,&bh,n);
BN_mul_low(&t2,&ah,&bl,n);
}
else
{
bn_mm(m ,&al,&bl,&(sk[2]),ctx);
bn_mm_low(&t1,&al,&bh,n,&(sk[2]),ctx);
bn_mm_low(&t2,&ah,&bl,n,&(sk[2]),ctx);
}
BN_add(&t1,&t1,&t2);
bn_set_high(&ah,m,n); ah.max=num+2;
BN_add(&ah,&ah,&t1);
m->top=num;
m->neg=A->neg^B->neg;
return(1);
}
