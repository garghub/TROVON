int BN_exp(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, BN_CTX *ctx)
{
int i,bits,ret=0;
BIGNUM *v,*rr;
BN_CTX_start(ctx);
if ((r == a) || (r == p))
rr = BN_CTX_get(ctx);
else
rr = r;
if ((v = BN_CTX_get(ctx)) == NULL) goto err;
if (BN_copy(v,a) == NULL) goto err;
bits=BN_num_bits(p);
if (BN_is_odd(p))
{ if (BN_copy(rr,a) == NULL) goto err; }
else { if (!BN_one(rr)) goto err; }
for (i=1; i<bits; i++)
{
if (!BN_sqr(v,v,ctx)) goto err;
if (BN_is_bit_set(p,i))
{
if (!BN_mul(rr,rr,v,ctx)) goto err;
}
}
ret=1;
err:
if (r != rr) BN_copy(r,rr);
BN_CTX_end(ctx);
return(ret);
}
int BN_mod_exp(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, const BIGNUM *m,
BN_CTX *ctx)
{
int ret;
bn_check_top(a);
bn_check_top(p);
bn_check_top(m);
#define MONT_MUL_MOD
#define MONT_EXP_WORD
#define RECP_MUL_MOD
#ifdef MONT_MUL_MOD
if (BN_is_odd(m))
{
# ifdef MONT_EXP_WORD
if (a->top == 1 && !a->neg)
{
BN_ULONG A = a->d[0];
ret=BN_mod_exp_mont_word(r,A,p,m,ctx,NULL);
}
else
# endif
ret=BN_mod_exp_mont(r,a,p,m,ctx,NULL);
}
else
#endif
#ifdef RECP_MUL_MOD
{ ret=BN_mod_exp_recp(r,a,p,m,ctx); }
#else
{ ret=BN_mod_exp_simple(r,a,p,m,ctx); }
#endif
return(ret);
}
int BN_mod_exp_recp(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
const BIGNUM *m, BN_CTX *ctx)
{
int i,j,bits,ret=0,wstart,wend,window,wvalue;
int start=1,ts=0;
BIGNUM *aa;
BIGNUM val[TABLE_SIZE];
BN_RECP_CTX recp;
bits=BN_num_bits(p);
if (bits == 0)
{
ret = BN_one(r);
return ret;
}
BN_CTX_start(ctx);
if ((aa = BN_CTX_get(ctx)) == NULL) goto err;
BN_RECP_CTX_init(&recp);
if (m->neg)
{
if (!BN_copy(aa, m)) goto err;
aa->neg = 0;
if (BN_RECP_CTX_set(&recp,aa,ctx) <= 0) goto err;
}
else
{
if (BN_RECP_CTX_set(&recp,m,ctx) <= 0) goto err;
}
BN_init(&(val[0]));
ts=1;
if (!BN_nnmod(&(val[0]),a,m,ctx)) goto err;
if (BN_is_zero(&(val[0])))
{
ret = BN_zero(r);
goto err;
}
window = BN_window_bits_for_exponent_size(bits);
if (window > 1)
{
if (!BN_mod_mul_reciprocal(aa,&(val[0]),&(val[0]),&recp,ctx))
goto err;
j=1<<(window-1);
for (i=1; i<j; i++)
{
BN_init(&val[i]);
if (!BN_mod_mul_reciprocal(&(val[i]),&(val[i-1]),aa,&recp,ctx))
goto err;
}
ts=i;
}
start=1;
wvalue=0;
wstart=bits-1;
wend=0;
if (!BN_one(r)) goto err;
for (;;)
{
if (BN_is_bit_set(p,wstart) == 0)
{
if (!start)
if (!BN_mod_mul_reciprocal(r,r,r,&recp,ctx))
goto err;
if (wstart == 0) break;
wstart--;
continue;
}
j=wstart;
wvalue=1;
wend=0;
for (i=1; i<window; i++)
{
if (wstart-i < 0) break;
if (BN_is_bit_set(p,wstart-i))
{
wvalue<<=(i-wend);
wvalue|=1;
wend=i;
}
}
j=wend+1;
if (!start)
for (i=0; i<j; i++)
{
if (!BN_mod_mul_reciprocal(r,r,r,&recp,ctx))
goto err;
}
if (!BN_mod_mul_reciprocal(r,r,&(val[wvalue>>1]),&recp,ctx))
goto err;
wstart-=wend+1;
wvalue=0;
start=0;
if (wstart < 0) break;
}
ret=1;
err:
BN_CTX_end(ctx);
for (i=0; i<ts; i++)
BN_clear_free(&(val[i]));
BN_RECP_CTX_free(&recp);
return(ret);
}
int BN_mod_exp_mont(BIGNUM *rr, const BIGNUM *a, const BIGNUM *p,
const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *in_mont)
{
int i,j,bits,ret=0,wstart,wend,window,wvalue;
int start=1,ts=0;
BIGNUM *d,*r;
const BIGNUM *aa;
BIGNUM val[TABLE_SIZE];
BN_MONT_CTX *mont=NULL;
bn_check_top(a);
bn_check_top(p);
bn_check_top(m);
if (!(m->d[0] & 1))
{
BNerr(BN_F_BN_MOD_EXP_MONT,BN_R_CALLED_WITH_EVEN_MODULUS);
return(0);
}
bits=BN_num_bits(p);
if (bits == 0)
{
ret = BN_one(rr);
return ret;
}
BN_CTX_start(ctx);
d = BN_CTX_get(ctx);
r = BN_CTX_get(ctx);
if (d == NULL || r == NULL) goto err;
if (in_mont != NULL)
mont=in_mont;
else
{
if ((mont=BN_MONT_CTX_new()) == NULL) goto err;
if (!BN_MONT_CTX_set(mont,m,ctx)) goto err;
}
BN_init(&val[0]);
ts=1;
if (a->neg || BN_ucmp(a,m) >= 0)
{
if (!BN_nnmod(&(val[0]),a,m,ctx))
goto err;
aa= &(val[0]);
}
else
aa=a;
if (BN_is_zero(aa))
{
ret = BN_zero(rr);
goto err;
}
if (!BN_to_montgomery(&(val[0]),aa,mont,ctx)) goto err;
window = BN_window_bits_for_exponent_size(bits);
if (window > 1)
{
if (!BN_mod_mul_montgomery(d,&(val[0]),&(val[0]),mont,ctx)) goto err;
j=1<<(window-1);
for (i=1; i<j; i++)
{
BN_init(&(val[i]));
if (!BN_mod_mul_montgomery(&(val[i]),&(val[i-1]),d,mont,ctx))
goto err;
}
ts=i;
}
start=1;
wvalue=0;
wstart=bits-1;
wend=0;
if (!BN_to_montgomery(r,BN_value_one(),mont,ctx)) goto err;
for (;;)
{
if (BN_is_bit_set(p,wstart) == 0)
{
if (!start)
{
if (!BN_mod_mul_montgomery(r,r,r,mont,ctx))
goto err;
}
if (wstart == 0) break;
wstart--;
continue;
}
j=wstart;
wvalue=1;
wend=0;
for (i=1; i<window; i++)
{
if (wstart-i < 0) break;
if (BN_is_bit_set(p,wstart-i))
{
wvalue<<=(i-wend);
wvalue|=1;
wend=i;
}
}
j=wend+1;
if (!start)
for (i=0; i<j; i++)
{
if (!BN_mod_mul_montgomery(r,r,r,mont,ctx))
goto err;
}
if (!BN_mod_mul_montgomery(r,r,&(val[wvalue>>1]),mont,ctx))
goto err;
wstart-=wend+1;
wvalue=0;
start=0;
if (wstart < 0) break;
}
if (!BN_from_montgomery(rr,r,mont,ctx)) goto err;
ret=1;
err:
if ((in_mont == NULL) && (mont != NULL)) BN_MONT_CTX_free(mont);
BN_CTX_end(ctx);
for (i=0; i<ts; i++)
BN_clear_free(&(val[i]));
return(ret);
}
int BN_mod_exp_mont_word(BIGNUM *rr, BN_ULONG a, const BIGNUM *p,
const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *in_mont)
{
BN_MONT_CTX *mont = NULL;
int b, bits, ret=0;
int r_is_one;
BN_ULONG w, next_w;
BIGNUM *d, *r, *t;
BIGNUM *swap_tmp;
#define BN_MOD_MUL_WORD(r, w, m) \
(BN_mul_word(r, (w)) && \
( \
(BN_mod(t, r, m, ctx) && (swap_tmp = r, r = t, t = swap_tmp, 1))))
#define BN_TO_MONTGOMERY_WORD(r, w, mont) \
(BN_set_word(r, (w)) && BN_to_montgomery(r, r, (mont), ctx))
bn_check_top(p);
bn_check_top(m);
if (m->top == 0 || !(m->d[0] & 1))
{
BNerr(BN_F_BN_MOD_EXP_MONT_WORD,BN_R_CALLED_WITH_EVEN_MODULUS);
return(0);
}
if (m->top == 1)
a %= m->d[0];
bits = BN_num_bits(p);
if (bits == 0)
{
ret = BN_one(rr);
return ret;
}
if (a == 0)
{
ret = BN_zero(rr);
return ret;
}
BN_CTX_start(ctx);
d = BN_CTX_get(ctx);
r = BN_CTX_get(ctx);
t = BN_CTX_get(ctx);
if (d == NULL || r == NULL || t == NULL) goto err;
if (in_mont != NULL)
mont=in_mont;
else
{
if ((mont = BN_MONT_CTX_new()) == NULL) goto err;
if (!BN_MONT_CTX_set(mont, m, ctx)) goto err;
}
r_is_one = 1;
w = a;
for (b = bits-2; b >= 0; b--)
{
next_w = w*w;
if ((next_w/w) != w)
{
if (r_is_one)
{
if (!BN_TO_MONTGOMERY_WORD(r, w, mont)) goto err;
r_is_one = 0;
}
else
{
if (!BN_MOD_MUL_WORD(r, w, m)) goto err;
}
next_w = 1;
}
w = next_w;
if (!r_is_one)
{
if (!BN_mod_mul_montgomery(r, r, r, mont, ctx)) goto err;
}
if (BN_is_bit_set(p, b))
{
next_w = w*a;
if ((next_w/a) != w)
{
if (r_is_one)
{
if (!BN_TO_MONTGOMERY_WORD(r, w, mont)) goto err;
r_is_one = 0;
}
else
{
if (!BN_MOD_MUL_WORD(r, w, m)) goto err;
}
next_w = a;
}
w = next_w;
}
}
if (w != 1)
{
if (r_is_one)
{
if (!BN_TO_MONTGOMERY_WORD(r, w, mont)) goto err;
r_is_one = 0;
}
else
{
if (!BN_MOD_MUL_WORD(r, w, m)) goto err;
}
}
if (r_is_one)
{
if (!BN_one(rr)) goto err;
}
else
{
if (!BN_from_montgomery(rr, r, mont, ctx)) goto err;
}
ret = 1;
err:
if ((in_mont == NULL) && (mont != NULL)) BN_MONT_CTX_free(mont);
BN_CTX_end(ctx);
return(ret);
}
int BN_mod_exp_simple(BIGNUM *r,
const BIGNUM *a, const BIGNUM *p, const BIGNUM *m,
BN_CTX *ctx)
{
int i,j,bits,ret=0,wstart,wend,window,wvalue,ts=0;
int start=1;
BIGNUM *d;
BIGNUM val[TABLE_SIZE];
bits=BN_num_bits(p);
if (bits == 0)
{
ret = BN_one(r);
return ret;
}
BN_CTX_start(ctx);
if ((d = BN_CTX_get(ctx)) == NULL) goto err;
BN_init(&(val[0]));
ts=1;
if (!BN_nnmod(&(val[0]),a,m,ctx)) goto err;
if (BN_is_zero(&(val[0])))
{
ret = BN_zero(r);
goto err;
}
window = BN_window_bits_for_exponent_size(bits);
if (window > 1)
{
if (!BN_mod_mul(d,&(val[0]),&(val[0]),m,ctx))
goto err;
j=1<<(window-1);
for (i=1; i<j; i++)
{
BN_init(&(val[i]));
if (!BN_mod_mul(&(val[i]),&(val[i-1]),d,m,ctx))
goto err;
}
ts=i;
}
start=1;
wvalue=0;
wstart=bits-1;
wend=0;
if (!BN_one(r)) goto err;
for (;;)
{
if (BN_is_bit_set(p,wstart) == 0)
{
if (!start)
if (!BN_mod_mul(r,r,r,m,ctx))
goto err;
if (wstart == 0) break;
wstart--;
continue;
}
j=wstart;
wvalue=1;
wend=0;
for (i=1; i<window; i++)
{
if (wstart-i < 0) break;
if (BN_is_bit_set(p,wstart-i))
{
wvalue<<=(i-wend);
wvalue|=1;
wend=i;
}
}
j=wend+1;
if (!start)
for (i=0; i<j; i++)
{
if (!BN_mod_mul(r,r,r,m,ctx))
goto err;
}
if (!BN_mod_mul(r,r,&(val[wvalue>>1]),m,ctx))
goto err;
wstart-=wend+1;
wvalue=0;
start=0;
if (wstart < 0) break;
}
ret=1;
err:
BN_CTX_end(ctx);
for (i=0; i<ts; i++)
BN_clear_free(&(val[i]));
return(ret);
}
