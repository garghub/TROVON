BIGNUM *BN_generate_prime(BIGNUM *ret, int bits, int safe, BIGNUM *add,
BIGNUM *rem, void (*callback)(int,int,void *), void *cb_arg)
{
BIGNUM *rnd=NULL;
BIGNUM t;
int found=0;
int i,j,c1=0;
BN_CTX *ctx;
int checks = BN_prime_checks_for_size(bits);
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
if (safe)
{
if (!probable_prime_dh_safe(rnd,bits,add,rem,ctx))
goto err;
}
else
{
if (!probable_prime_dh(rnd,bits,add,rem,ctx))
goto err;
}
}
if (callback != NULL) callback(0,c1++,cb_arg);
if (!safe)
{
i=BN_is_prime_fasttest(rnd,checks,callback,ctx,cb_arg,0);
if (i == -1) goto err;
if (i == 0) goto loop;
}
else
{
if (!BN_rshift1(&t,rnd)) goto err;
for (i=0; i<checks; i++)
{
j=BN_is_prime_fasttest(rnd,1,callback,ctx,cb_arg,0);
if (j == -1) goto err;
if (j == 0) goto loop;
j=BN_is_prime_fasttest(&t,1,callback,ctx,cb_arg,0);
if (j == -1) goto err;
if (j == 0) goto loop;
if (callback != NULL) callback(2,c1-1,cb_arg);
}
}
found = 1;
err:
if (!found && (ret == NULL) && (rnd != NULL)) BN_free(rnd);
BN_free(&t);
if (ctx != NULL) BN_CTX_free(ctx);
return(found ? rnd : NULL);
}
int BN_is_prime(const BIGNUM *a, int checks, void (*callback)(int,int,void *),
BN_CTX *ctx_passed, void *cb_arg)
{
return BN_is_prime_fasttest(a, checks, callback, ctx_passed, cb_arg, 0);
}
int BN_is_prime_fasttest(const BIGNUM *a, int checks,
void (*callback)(int,int,void *),
BN_CTX *ctx_passed, void *cb_arg,
int do_trial_division)
{
int i, j, ret = -1;
int k;
BN_CTX *ctx = NULL;
BIGNUM *A1, *A1_odd, *check;
BN_MONT_CTX *mont = NULL;
const BIGNUM *A = NULL;
if (checks == BN_prime_checks)
checks = BN_prime_checks_for_size(BN_num_bits(a));
if (!BN_is_odd(a))
return(0);
if (do_trial_division)
{
for (i = 1; i < NUMPRIMES; i++)
if (BN_mod_word(a, primes[i]) == 0)
return 0;
if (callback != NULL) callback(1, -1, cb_arg);
}
if (ctx_passed != NULL)
ctx = ctx_passed;
else
if ((ctx=BN_CTX_new()) == NULL)
goto err;
BN_CTX_start(ctx);
if (a->neg)
{
BIGNUM *t;
if ((t = BN_CTX_get(ctx)) == NULL) goto err;
BN_copy(t, a);
t->neg = 0;
A = t;
}
else
A = a;
A1 = BN_CTX_get(ctx);
A1_odd = BN_CTX_get(ctx);
check = BN_CTX_get(ctx);
if (check == NULL) goto err;
if (!BN_copy(A1, A))
goto err;
if (!BN_sub_word(A1, 1))
goto err;
if (BN_is_zero(A1))
{
ret = 0;
goto err;
}
k = 1;
while (!BN_is_bit_set(A1, k))
k++;
if (!BN_rshift(A1_odd, A1, k))
goto err;
mont = BN_MONT_CTX_new();
if (mont == NULL)
goto err;
if (!BN_MONT_CTX_set(mont, A, ctx))
goto err;
for (i = 0; i < checks; i++)
{
if (!BN_pseudo_rand(check, BN_num_bits(A1), 0, 0))
goto err;
if (BN_cmp(check, A1) >= 0)
if (!BN_sub(check, check, A1))
goto err;
if (!BN_add_word(check, 1))
goto err;
j = witness(check, A, A1, A1_odd, k, ctx, mont);
if (j == -1) goto err;
if (j)
{
ret=0;
goto err;
}
if (callback != NULL) callback(1,i,cb_arg);
}
ret=1;
err:
if (ctx != NULL)
{
BN_CTX_end(ctx);
if (ctx_passed == NULL)
BN_CTX_free(ctx);
}
if (mont != NULL)
BN_MONT_CTX_free(mont);
return(ret);
}
static int witness(BIGNUM *w, const BIGNUM *a, const BIGNUM *a1,
const BIGNUM *a1_odd, int k, BN_CTX *ctx, BN_MONT_CTX *mont)
{
if (!BN_mod_exp_mont(w, w, a1_odd, a, ctx, mont))
return -1;
if (BN_is_one(w))
return 0;
if (BN_cmp(w, a1) == 0)
return 0;
while (--k)
{
if (!BN_mod_mul(w, w, w, a, ctx))
return -1;
if (BN_is_one(w))
return 1;
if (BN_cmp(w, a1) == 0)
return 0;
}
return 1;
}
static int probable_prime(BIGNUM *rnd, int bits)
{
int i;
BN_ULONG mods[NUMPRIMES];
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
BN_CTX_start(ctx);
if ((t1 = BN_CTX_get(ctx)) == NULL) goto err;
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
BN_CTX_end(ctx);
return(ret);
}
static int probable_prime_dh_safe(BIGNUM *p, int bits, BIGNUM *padd,
BIGNUM *rem, BN_CTX *ctx)
{
int i,ret=0;
BIGNUM *t1,*qadd,*q;
bits--;
BN_CTX_start(ctx);
t1 = BN_CTX_get(ctx);
q = BN_CTX_get(ctx);
qadd = BN_CTX_get(ctx);
if (qadd == NULL) goto err;
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
BN_CTX_end(ctx);
return(ret);
}
