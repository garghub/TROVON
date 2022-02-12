void BN_RECP_CTX_init(BN_RECP_CTX *recp)
{
BN_init(&(recp->N));
BN_init(&(recp->Nr));
recp->num_bits=0;
recp->flags=0;
}
BN_RECP_CTX *BN_RECP_CTX_new(void)
{
BN_RECP_CTX *ret;
if ((ret=(BN_RECP_CTX *)OPENSSL_malloc(sizeof(BN_RECP_CTX))) == NULL)
return(NULL);
BN_RECP_CTX_init(ret);
ret->flags=BN_FLG_MALLOCED;
return(ret);
}
void BN_RECP_CTX_free(BN_RECP_CTX *recp)
{
if(recp == NULL)
return;
BN_free(&(recp->N));
BN_free(&(recp->Nr));
if (recp->flags & BN_FLG_MALLOCED)
OPENSSL_free(recp);
}
int BN_RECP_CTX_set(BN_RECP_CTX *recp, const BIGNUM *d, BN_CTX *ctx)
{
BN_copy(&(recp->N),d);
BN_zero(&(recp->Nr));
recp->num_bits=BN_num_bits(d);
recp->shift=0;
return(1);
}
int BN_mod_mul_reciprocal(BIGNUM *r, BIGNUM *x, BIGNUM *y, BN_RECP_CTX *recp,
BN_CTX *ctx)
{
int ret=0;
BIGNUM *a;
BN_CTX_start(ctx);
if ((a = BN_CTX_get(ctx)) == NULL) goto err;
if (y != NULL)
{
if (x == y)
{ if (!BN_sqr(a,x,ctx)) goto err; }
else
{ if (!BN_mul(a,x,y,ctx)) goto err; }
}
else
a=x;
BN_div_recp(NULL,r,a,recp,ctx);
ret=1;
err:
BN_CTX_end(ctx);
return(ret);
}
int BN_div_recp(BIGNUM *dv, BIGNUM *rem, BIGNUM *m, BN_RECP_CTX *recp,
BN_CTX *ctx)
{
int i,j,ret=0;
BIGNUM *a,*b,*d,*r;
BN_CTX_start(ctx);
a=BN_CTX_get(ctx);
b=BN_CTX_get(ctx);
if (dv != NULL)
d=dv;
else
d=BN_CTX_get(ctx);
if (rem != NULL)
r=rem;
else
r=BN_CTX_get(ctx);
if (a == NULL || b == NULL || d == NULL || r == NULL) goto err;
if (BN_ucmp(m,&(recp->N)) < 0)
{
BN_zero(d);
BN_copy(r,m);
BN_CTX_end(ctx);
return(1);
}
i=BN_num_bits(m);
j=recp->num_bits<<1;
if (j>i) i=j;
j>>=1;
if (i != recp->shift)
recp->shift=BN_reciprocal(&(recp->Nr),&(recp->N),
i,ctx);
if (!BN_rshift(a,m,j)) goto err;
if (!BN_mul(b,a,&(recp->Nr),ctx)) goto err;
if (!BN_rshift(d,b,i-j)) goto err;
d->neg=0;
if (!BN_mul(b,&(recp->N),d,ctx)) goto err;
if (!BN_usub(r,m,b)) goto err;
r->neg=0;
#if 1
j=0;
while (BN_ucmp(r,&(recp->N)) >= 0)
{
if (j++ > 2)
{
BNerr(BN_F_BN_MOD_MUL_RECIPROCAL,BN_R_BAD_RECIPROCAL);
goto err;
}
if (!BN_usub(r,r,&(recp->N))) goto err;
if (!BN_add_word(d,1)) goto err;
}
#endif
r->neg=BN_is_zero(r)?0:m->neg;
d->neg=m->neg^recp->N.neg;
ret=1;
err:
BN_CTX_end(ctx);
return(ret);
}
int BN_reciprocal(BIGNUM *r, BIGNUM *m, int len, BN_CTX *ctx)
{
int ret= -1;
BIGNUM t;
BN_init(&t);
BN_zero(&t);
if (!BN_set_bit(&t,len)) goto err;
if (!BN_div(r,NULL,&t,m,ctx)) goto err;
ret=len;
err:
BN_free(&t);
return(ret);
}
