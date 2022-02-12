BIGNUM *BN_generate_prime(BIGNUM *ret, int bits, int strong, BIGNUM *add,
BIGNUM *rem, void (*callback)(int,int,char *), char *cb_arg)
{
BIGNUM *rnd=NULL;
BIGNUM t;
int i,j,c1=0;
BN_CTX *ctx;
ctx=BN_CTX_new();
if (ctx == NULL) goto err;
if (ret == NULL)
{
if ((rnd=BN_new()) == NULL) goto err;
}
else
rnd=ret;
BN_init(&t);
loop:
if (add == NULL)
{
if (!probable_prime(rnd,bits)) goto err;
}
else
{
if (strong)
{
if (!probable_prime_dh_strong(rnd,bits,add,rem,ctx))
goto err;
}
else
{
if (!probable_prime_dh(rnd,bits,add,rem,ctx))
goto err;
}
}
if (callback != NULL) callback(0,c1++,cb_arg);
if (!strong)
{
i=BN_is_prime(rnd,BN_prime_checks,callback,ctx,cb_arg);
if (i == -1) goto err;
if (i == 0) goto loop;
}
else
{
if (!BN_rshift1(&t,rnd)) goto err;
for (i=0; i<BN_prime_checks; i++)
{
j=BN_is_prime(rnd,1,callback,ctx,cb_arg);
if (j == -1) goto err;
if (j == 0) goto loop;
j=BN_is_prime(&t,1,callback,ctx,cb_arg);
if (j == -1) goto err;
if (j == 0) goto loop;
if (callback != NULL) callback(2,c1-1,cb_arg);
}
}
ret=rnd;
err:
if ((ret == NULL) && (rnd != NULL)) BN_free(rnd);
BN_free(&t);
if (ctx != NULL) BN_CTX_free(ctx);
return(ret);
}
int BN_is_prime(BIGNUM *a, int checks, void (*callback)(int,int,char *),
BN_CTX *ctx_passed, char *cb_arg)
{
int i,j,c2=0,ret= -1;
BIGNUM *check;
BN_CTX *ctx=NULL,*ctx2=NULL;
BN_MONT_CTX *mont=NULL;
if (!BN_is_odd(a))
return(0);
if (ctx_passed != NULL)
ctx=ctx_passed;
else
if ((ctx=BN_CTX_new()) == NULL) goto err;
if ((ctx2=BN_CTX_new()) == NULL) goto err;
if ((mont=BN_MONT_CTX_new()) == NULL) goto err;
check= &(ctx->bn[ctx->tos++]);
if (!BN_MONT_CTX_set(mont,a,ctx2)) goto err;
for (i=0; i<checks; i++)
{
if (!BN_rand(check,BN_num_bits(a)-1,0,0)) goto err;
j=witness(check,a,ctx,ctx2,mont);
if (j == -1) goto err;
if (j)
{
ret=0;
goto err;
}
if (callback != NULL) callback(1,c2++,cb_arg);
}
ret=1;
err:
ctx->tos--;
if ((ctx_passed == NULL) && (ctx != NULL))
BN_CTX_free(ctx);
if (ctx2 != NULL)
BN_CTX_free(ctx2);
if (mont != NULL) BN_MONT_CTX_free(mont);
return(ret);
}
static int witness(BIGNUM *a, BIGNUM *n, BN_CTX *ctx, BN_CTX *ctx2,
BN_MONT_CTX *mont)
{
int k,i,ret= -1,good;
BIGNUM *d,*dd,*tmp,*d1,*d2,*n1;
BIGNUM *mont_one,*mont_n1,*mont_a;
d1= &(ctx->bn[ctx->tos]);
d2= &(ctx->bn[ctx->tos+1]);
n1= &(ctx->bn[ctx->tos+2]);
ctx->tos+=3;
mont_one= &(ctx2->bn[ctx2->tos]);
mont_n1= &(ctx2->bn[ctx2->tos+1]);
mont_a= &(ctx2->bn[ctx2->tos+2]);
ctx2->tos+=3;
d=d1;
dd=d2;
if (!BN_one(d)) goto err;
if (!BN_sub(n1,n,d)) goto err;
k=BN_num_bits(n1);
if (!BN_to_montgomery(mont_one,BN_value_one(),mont,ctx2)) goto err;
if (!BN_to_montgomery(mont_n1,n1,mont,ctx2)) goto err;
if (!BN_to_montgomery(mont_a,a,mont,ctx2)) goto err;
BN_copy(d,mont_one);
for (i=k-1; i>=0; i--)
{
if ( (BN_cmp(d,mont_one) != 0) &&
(BN_cmp(d,mont_n1) != 0))
good=1;
else
good=0;
BN_mod_mul_montgomery(dd,d,d,mont,ctx2);
if (good && (BN_cmp(dd,mont_one) == 0))
{
ret=1;
goto err;
}
if (BN_is_bit_set(n1,i))
{
BN_mod_mul_montgomery(d,dd,mont_a,mont,ctx2);
}
else
{
tmp=d;
d=dd;
dd=tmp;
}
}
if (BN_cmp(d,mont_one) == 0)
i=0;
else i=1;
ret=i;
err:
ctx->tos-=3;
ctx2->tos-=3;
return(ret);
}
static int probable_prime(BIGNUM *rnd, int bits)
{
int i;
MS_STATIC BN_ULONG mods[NUMPRIMES];
BN_ULONG delta,d;
again:
if (!BN_rand(rnd,bits,1,1)) return(0);
for (i=1; i<NUMPRIMES; i++)
mods[i]=BN_mod_word(rnd,(BN_ULONG)primes[i]);
delta=0;
loop: for (i=1; i<NUMPRIMES; i++)
{
if (((mods[i]+delta)%primes[i]) <= 1)
{
d=delta;
delta+=2;
if (delta < d) goto again;
goto loop;
}
}
if (!BN_add_word(rnd,delta)) return(0);
return(1);
}
static int probable_prime_dh(BIGNUM *rnd, int bits, BIGNUM *add, BIGNUM *rem,
BN_CTX *ctx)
{
int i,ret=0;
BIGNUM *t1;
t1= &(ctx->bn[ctx->tos++]);
if (!BN_rand(rnd,bits,0,1)) goto err;
if (!BN_mod(t1,rnd,add,ctx)) goto err;
if (!BN_sub(rnd,rnd,t1)) goto err;
if (rem == NULL)
{ if (!BN_add_word(rnd,1)) goto err; }
else
{ if (!BN_add(rnd,rnd,rem)) goto err; }
loop: for (i=1; i<NUMPRIMES; i++)
{
if (BN_mod_word(rnd,(BN_ULONG)primes[i]) <= 1)
{
if (!BN_add(rnd,rnd,add)) goto err;
goto loop;
}
}
ret=1;
err:
ctx->tos--;
return(ret);
}
static int probable_prime_dh_strong(BIGNUM *p, int bits, BIGNUM *padd,
BIGNUM *rem, BN_CTX *ctx)
{
int i,ret=0;
BIGNUM *t1,*qadd=NULL,*q=NULL;
bits--;
t1= &(ctx->bn[ctx->tos++]);
q= &(ctx->bn[ctx->tos++]);
qadd= &(ctx->bn[ctx->tos++]);
if (!BN_rshift1(qadd,padd)) goto err;
if (!BN_rand(q,bits,0,1)) goto err;
if (!BN_mod(t1,q,qadd,ctx)) goto err;
if (!BN_sub(q,q,t1)) goto err;
if (rem == NULL)
{ if (!BN_add_word(q,1)) goto err; }
else
{
if (!BN_rshift1(t1,rem)) goto err;
if (!BN_add(q,q,t1)) goto err;
}
if (!BN_lshift1(p,q)) goto err;
if (!BN_add_word(p,1)) goto err;
loop: for (i=1; i<NUMPRIMES; i++)
{
if ( (BN_mod_word(p,(BN_ULONG)primes[i]) == 0) ||
(BN_mod_word(q,(BN_ULONG)primes[i]) == 0))
{
if (!BN_add(p,p,padd)) goto err;
if (!BN_add(q,q,qadd)) goto err;
goto loop;
}
}
ret=1;
err:
ctx->tos-=3;
return(ret);
}
