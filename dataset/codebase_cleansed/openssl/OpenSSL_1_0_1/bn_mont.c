int BN_mod_mul_montgomery(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
BN_MONT_CTX *mont, BN_CTX *ctx)
{
BIGNUM *tmp;
int ret=0;
#if defined(OPENSSL_BN_ASM_MONT) && defined(MONT_WORD)
int num = mont->N.top;
if (num>1 && a->top==num && b->top==num)
{
if (bn_wexpand(r,num) == NULL) return(0);
if (bn_mul_mont(r->d,a->d,b->d,mont->N.d,mont->n0,num))
{
r->neg = a->neg^b->neg;
r->top = num;
bn_correct_top(r);
return(1);
}
}
#endif
BN_CTX_start(ctx);
tmp = BN_CTX_get(ctx);
if (tmp == NULL) goto err;
bn_check_top(tmp);
if (a == b)
{
if (!BN_sqr(tmp,a,ctx)) goto err;
}
else
{
if (!BN_mul(tmp,a,b,ctx)) goto err;
}
#ifdef MONT_WORD
if (!BN_from_montgomery_word(r,tmp,mont)) goto err;
#else
if (!BN_from_montgomery(r,tmp,mont,ctx)) goto err;
#endif
bn_check_top(r);
ret=1;
err:
BN_CTX_end(ctx);
return(ret);
}
static int BN_from_montgomery_word(BIGNUM *ret, BIGNUM *r, BN_MONT_CTX *mont)
{
BIGNUM *n;
BN_ULONG *ap,*np,*rp,n0,v,carry;
int nl,max,i;
n= &(mont->N);
nl=n->top;
if (nl == 0) { ret->top=0; return(1); }
max=(2*nl);
if (bn_wexpand(r,max) == NULL) return(0);
r->neg^=n->neg;
np=n->d;
rp=r->d;
#if 1
for (i=r->top; i<max; i++)
rp[i]=0;
#else
memset(&(rp[r->top]),0,(max-r->top)*sizeof(BN_ULONG));
#endif
r->top=max;
n0=mont->n0[0];
#ifdef BN_COUNT
fprintf(stderr,"word BN_from_montgomery_word %d * %d\n",nl,nl);
#endif
for (carry=0, i=0; i<nl; i++, rp++)
{
#ifdef __TANDEM
{
long long t1;
long long t2;
long long t3;
t1 = rp[0] * (n0 & 0177777);
t2 = 037777600000l;
t2 = n0 & t2;
t3 = rp[0] & 0177777;
t2 = (t3 * t2) & BN_MASK2;
t1 = t1 + t2;
v=bn_mul_add_words(rp,np,nl,(BN_ULONG) t1);
}
#else
v=bn_mul_add_words(rp,np,nl,(rp[0]*n0)&BN_MASK2);
#endif
v = (v+carry+rp[nl])&BN_MASK2;
carry |= (v != rp[nl]);
carry &= (v <= rp[nl]);
rp[nl]=v;
}
if (bn_wexpand(ret,nl) == NULL) return(0);
ret->top=nl;
ret->neg=r->neg;
rp=ret->d;
ap=&(r->d[nl]);
#define BRANCH_FREE 1
#if BRANCH_FREE
{
BN_ULONG *nrp;
size_t m;
v=bn_sub_words(rp,ap,np,nl)-carry;
m=(0-(size_t)v);
nrp=(BN_ULONG *)(((PTR_SIZE_INT)rp&~m)|((PTR_SIZE_INT)ap&m));
for (i=0,nl-=4; i<nl; i+=4)
{
BN_ULONG t1,t2,t3,t4;
t1=nrp[i+0];
t2=nrp[i+1];
t3=nrp[i+2]; ap[i+0]=0;
t4=nrp[i+3]; ap[i+1]=0;
rp[i+0]=t1; ap[i+2]=0;
rp[i+1]=t2; ap[i+3]=0;
rp[i+2]=t3;
rp[i+3]=t4;
}
for (nl+=4; i<nl; i++)
rp[i]=nrp[i], ap[i]=0;
}
#else
if (bn_sub_words (rp,ap,np,nl)-carry)
memcpy(rp,ap,nl*sizeof(BN_ULONG));
#endif
bn_correct_top(r);
bn_correct_top(ret);
bn_check_top(ret);
return(1);
}
int BN_from_montgomery(BIGNUM *ret, const BIGNUM *a, BN_MONT_CTX *mont,
BN_CTX *ctx)
{
int retn=0;
#ifdef MONT_WORD
BIGNUM *t;
BN_CTX_start(ctx);
if ((t = BN_CTX_get(ctx)) && BN_copy(t,a))
retn = BN_from_montgomery_word(ret,t,mont);
BN_CTX_end(ctx);
#else
BIGNUM *t1,*t2;
BN_CTX_start(ctx);
t1 = BN_CTX_get(ctx);
t2 = BN_CTX_get(ctx);
if (t1 == NULL || t2 == NULL) goto err;
if (!BN_copy(t1,a)) goto err;
BN_mask_bits(t1,mont->ri);
if (!BN_mul(t2,t1,&mont->Ni,ctx)) goto err;
BN_mask_bits(t2,mont->ri);
if (!BN_mul(t1,t2,&mont->N,ctx)) goto err;
if (!BN_add(t2,a,t1)) goto err;
if (!BN_rshift(ret,t2,mont->ri)) goto err;
if (BN_ucmp(ret, &(mont->N)) >= 0)
{
if (!BN_usub(ret,ret,&(mont->N))) goto err;
}
retn=1;
bn_check_top(ret);
err:
BN_CTX_end(ctx);
#endif
return(retn);
}
BN_MONT_CTX *BN_MONT_CTX_new(void)
{
BN_MONT_CTX *ret;
if ((ret=(BN_MONT_CTX *)OPENSSL_malloc(sizeof(BN_MONT_CTX))) == NULL)
return(NULL);
BN_MONT_CTX_init(ret);
ret->flags=BN_FLG_MALLOCED;
return(ret);
}
void BN_MONT_CTX_init(BN_MONT_CTX *ctx)
{
ctx->ri=0;
BN_init(&(ctx->RR));
BN_init(&(ctx->N));
BN_init(&(ctx->Ni));
ctx->n0[0] = ctx->n0[1] = 0;
ctx->flags=0;
}
void BN_MONT_CTX_free(BN_MONT_CTX *mont)
{
if(mont == NULL)
return;
BN_free(&(mont->RR));
BN_free(&(mont->N));
BN_free(&(mont->Ni));
if (mont->flags & BN_FLG_MALLOCED)
OPENSSL_free(mont);
}
int BN_MONT_CTX_set(BN_MONT_CTX *mont, const BIGNUM *mod, BN_CTX *ctx)
{
int ret = 0;
BIGNUM *Ri,*R;
BN_CTX_start(ctx);
if((Ri = BN_CTX_get(ctx)) == NULL) goto err;
R= &(mont->RR);
if (!BN_copy(&(mont->N),mod)) goto err;
mont->N.neg = 0;
#ifdef MONT_WORD
{
BIGNUM tmod;
BN_ULONG buf[2];
BN_init(&tmod);
tmod.d=buf;
tmod.dmax=2;
tmod.neg=0;
mont->ri=(BN_num_bits(mod)+(BN_BITS2-1))/BN_BITS2*BN_BITS2;
#if defined(OPENSSL_BN_ASM_MONT) && (BN_BITS2<=32)
BN_zero(R);
if (!(BN_set_bit(R,2*BN_BITS2))) goto err;
tmod.top=0;
if ((buf[0] = mod->d[0])) tmod.top=1;
if ((buf[1] = mod->top>1 ? mod->d[1] : 0)) tmod.top=2;
if ((BN_mod_inverse(Ri,R,&tmod,ctx)) == NULL)
goto err;
if (!BN_lshift(Ri,Ri,2*BN_BITS2)) goto err;
if (!BN_is_zero(Ri))
{
if (!BN_sub_word(Ri,1)) goto err;
}
else
{
if (bn_expand(Ri,(int)sizeof(BN_ULONG)*2) == NULL)
goto err;
Ri->neg=0;
Ri->d[0]=BN_MASK2;
Ri->d[1]=BN_MASK2;
Ri->top=2;
}
if (!BN_div(Ri,NULL,Ri,&tmod,ctx)) goto err;
mont->n0[0] = (Ri->top > 0) ? Ri->d[0] : 0;
mont->n0[1] = (Ri->top > 1) ? Ri->d[1] : 0;
#else
BN_zero(R);
if (!(BN_set_bit(R,BN_BITS2))) goto err;
buf[0]=mod->d[0];
buf[1]=0;
tmod.top = buf[0] != 0 ? 1 : 0;
if ((BN_mod_inverse(Ri,R,&tmod,ctx)) == NULL)
goto err;
if (!BN_lshift(Ri,Ri,BN_BITS2)) goto err;
if (!BN_is_zero(Ri))
{
if (!BN_sub_word(Ri,1)) goto err;
}
else
{
if (!BN_set_word(Ri,BN_MASK2)) goto err;
}
if (!BN_div(Ri,NULL,Ri,&tmod,ctx)) goto err;
mont->n0[0] = (Ri->top > 0) ? Ri->d[0] : 0;
mont->n0[1] = 0;
#endif
}
#else
{
mont->ri=BN_num_bits(&mont->N);
BN_zero(R);
if (!BN_set_bit(R,mont->ri)) goto err;
if ((BN_mod_inverse(Ri,R,&mont->N,ctx)) == NULL)
goto err;
if (!BN_lshift(Ri,Ri,mont->ri)) goto err;
if (!BN_sub_word(Ri,1)) goto err;
if (!BN_div(&(mont->Ni),NULL,Ri,&mont->N,ctx)) goto err;
}
#endif
BN_zero(&(mont->RR));
if (!BN_set_bit(&(mont->RR),mont->ri*2)) goto err;
if (!BN_mod(&(mont->RR),&(mont->RR),&(mont->N),ctx)) goto err;
ret = 1;
err:
BN_CTX_end(ctx);
return ret;
}
BN_MONT_CTX *BN_MONT_CTX_copy(BN_MONT_CTX *to, BN_MONT_CTX *from)
{
if (to == from) return(to);
if (!BN_copy(&(to->RR),&(from->RR))) return NULL;
if (!BN_copy(&(to->N),&(from->N))) return NULL;
if (!BN_copy(&(to->Ni),&(from->Ni))) return NULL;
to->ri=from->ri;
to->n0[0]=from->n0[0];
to->n0[1]=from->n0[1];
return(to);
}
BN_MONT_CTX *BN_MONT_CTX_set_locked(BN_MONT_CTX **pmont, int lock,
const BIGNUM *mod, BN_CTX *ctx)
{
int got_write_lock = 0;
BN_MONT_CTX *ret;
CRYPTO_r_lock(lock);
if (!*pmont)
{
CRYPTO_r_unlock(lock);
CRYPTO_w_lock(lock);
got_write_lock = 1;
if (!*pmont)
{
ret = BN_MONT_CTX_new();
if (ret && !BN_MONT_CTX_set(ret, mod, ctx))
BN_MONT_CTX_free(ret);
else
*pmont = ret;
}
}
ret = *pmont;
if (got_write_lock)
CRYPTO_w_unlock(lock);
else
CRYPTO_r_unlock(lock);
return ret;
}
