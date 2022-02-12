int BN_mul(BIGNUM *r, BIGNUM *a, BIGNUM *b)
{
BN_ULONG *ap,*bp,*rp;
BIGNUM *sk;
int i,n,ret;
int max,al,bl;
BN_CTX ctx;
bn_check_top(a);
bn_check_top(b);
al=a->top;
bl=b->top;
if ((al == 0) || (bl == 0))
{
r->top=0;
return(1);
}
#ifdef BN_MUL_DEBUG
printf("BN_mul(%d,%d)\n",a->top,b->top);
#endif
if ( (bn_limit_bits > 0) &&
(bl > bn_limit_num) && (al > bn_limit_num))
{
n=(BN_num_bits_word(al|bl)-bn_limit_bits);
n*=2;
sk=(BIGNUM *)Malloc(sizeof(BIGNUM)*n);
memset(sk,0,sizeof(BIGNUM)*n);
memset(&ctx,0,sizeof(ctx));
ret=bn_mm(r,a,b,&(sk[0]),&ctx);
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
r->top=max;
r->neg=a->neg^b->neg;
ap=a->d;
bp=b->d;
rp=r->d;
rp[al]=bn_mul_words(rp,ap,al,*(bp++));
rp++;
for (i=1; i<bl; i++)
{
rp[al]=bn_mul_add_words(rp,ap,al,*(bp++));
rp++;
}
if ((max > 0) && (r->d[max-1] == 0)) r->top--;
return(1);
}
int bn_mm(BIGNUM *m, BIGNUM *A, BIGNUM *B, BIGNUM *sk, BN_CTX *ctx)
{
int n,num,sqr=0;
int an,bn;
BIGNUM ah,al,bh,bl;
an=A->top;
bn=B->top;
#ifdef BN_MUL_DEBUG
printf("bn_mm(%d,%d)\n",A->top,B->top);
#endif
if (A == B) sqr=1;
num=(an>bn)?an:bn;
n=(num+1)/2;
BN_init(&ah);
BN_init(&al);
BN_init(&bh);
BN_init(&bl);
bn_set_low (&al,A,n);
bn_set_high(&ah,A,n);
bn_set_low (&bl,B,n);
bn_set_high(&bh,B,n);
BN_sub(&ahal,&ah,&al);
BN_sub(&blbh,&bl,&bh);
if (num <= (bn_limit_num+bn_limit_num))
{
BN_mul(m,&ahal,&blbh);
if (sqr)
{
BN_sqr(&ahal,&al,ctx);
BN_sqr(&blbh,&ah,ctx);
}
else
{
BN_mul(&ahal,&al,&bl);
BN_mul(&blbh,&ah,&bh);
}
}
else
{
bn_mm(m,&ahal,&blbh,&(sk[2]),ctx);
bn_mm(&ahal,&al,&bl,&(sk[2]),ctx);
bn_mm(&blbh,&ah,&bh,&(sk[2]),ctx);
}
BN_add(m,m,&ahal);
BN_add(m,m,&blbh);
BN_lshift(m,m,n*BN_BITS2);
BN_lshift(&blbh,&blbh,n*BN_BITS2*2);
BN_add(m,m,&ahal);
BN_add(m,m,&blbh);
m->neg=A->neg^B->neg;
return(1);
}
