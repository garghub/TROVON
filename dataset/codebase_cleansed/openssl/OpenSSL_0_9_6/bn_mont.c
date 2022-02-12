int BN_mod_mul_montgomery(BIGNUM *r, BIGNUM *a, BIGNUM *b,
BN_MONT_CTX *mont, BN_CTX *ctx)
{
BIGNUM *tmp,*tmp2;
int ret=0;
BN_CTX_start(ctx);
tmp = BN_CTX_get(ctx);
tmp2 = BN_CTX_get(ctx);
if (tmp == NULL || tmp2 == NULL) goto err;
bn_check_top(tmp);
bn_check_top(tmp2);
if (a == b)
{
if (!BN_sqr(tmp,a,ctx)) goto err;
}
else
{
if (!BN_mul(tmp,a,b,ctx)) goto err;
}
if (!BN_from_montgomery(r,tmp,mont,ctx)) goto err;
ret=1;
err:
BN_CTX_end(ctx);
return(ret);
}
int BN_from_montgomery(BIGNUM *ret, BIGNUM *a, BN_MONT_CTX *mont,
BN_CTX *ctx)
{
int retn=0;
#ifdef MONT_WORD
BIGNUM *n,*r;
BN_ULONG *ap,*np,*rp,n0,v,*nrp;
int al,nl,max,i,x,ri;
BN_CTX_start(ctx);
if ((r = BN_CTX_get(ctx)) == NULL) goto err;
if (!BN_copy(r,a)) goto err;
n= &(mont->N);
ap=a->d;
al=ri=mont->ri/BN_BITS2;
nl=n->top;
if ((al == 0) || (nl == 0)) { r->top=0; return(1); }
max=(nl+al+1);
if (bn_wexpand(r,max) == NULL) goto err;
if (bn_wexpand(ret,max) == NULL) goto err;
r->neg=a->neg^n->neg;
np=n->d;
rp=r->d;
nrp= &(r->d[nl]);
#if 1
for (i=r->top; i<max; i++)
r->d[i]=0;
#else
memset(&(r->d[r->top]),0,(max-r->top)*sizeof(BN_ULONG));
#endif
r->top=max;
n0=mont->n0;
#ifdef BN_COUNT
printf("word BN_from_montgomery %d * %d\n",nl,nl);
#endif
for (i=0; i<nl; i++)
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
nrp++;
rp++;
if (((nrp[-1]+=v)&BN_MASK2) >= v)
continue;
else
{
if (((++nrp[0])&BN_MASK2) != 0) continue;
if (((++nrp[1])&BN_MASK2) != 0) continue;
for (x=2; (((++nrp[x])&BN_MASK2) == 0); x++) ;
}
}
bn_fix_top(r);
#if 0
BN_rshift(ret,r,mont->ri);
#else
ret->neg = r->neg;
x=ri;
rp=ret->d;
ap= &(r->d[x]);
if (r->top < x)
al=0;
else
al=r->top-x;
ret->top=al;
al-=4;
for (i=0; i<al; i+=4)
{
BN_ULONG t1,t2,t3,t4;
t1=ap[i+0];
t2=ap[i+1];
t3=ap[i+2];
t4=ap[i+3];
rp[i+0]=t1;
rp[i+1]=t2;
rp[i+2]=t3;
rp[i+3]=t4;
}
al+=4;
for (; i<al; i++)
rp[i]=ap[i];
#endif
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
BN_rshift(ret,t2,mont->ri);
#endif
if (BN_ucmp(ret, &(mont->N)) >= 0)
{
BN_usub(ret,ret,&(mont->N));
}
retn=1;
err:
BN_CTX_end(ctx);
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
BIGNUM Ri,*R;
BN_init(&Ri);
R= &(mont->RR);
BN_copy(&(mont->N),mod);
#ifdef MONT_WORD
{
BIGNUM tmod;
BN_ULONG buf[2];
mont->ri=(BN_num_bits(mod)+(BN_BITS2-1))/BN_BITS2*BN_BITS2;
BN_zero(R);
BN_set_bit(R,BN_BITS2);
buf[0]=mod->d[0];
buf[1]=0;
tmod.d=buf;
tmod.top=1;
tmod.dmax=2;
tmod.neg=mod->neg;
if ((BN_mod_inverse(&Ri,R,&tmod,ctx)) == NULL)
goto err;
BN_lshift(&Ri,&Ri,BN_BITS2);
if (!BN_is_zero(&Ri))
BN_sub_word(&Ri,1);
else
BN_set_word(&Ri,BN_MASK2);
BN_div(&Ri,NULL,&Ri,&tmod,ctx);
mont->n0=Ri.d[0];
BN_free(&Ri);
}
#else
{
mont->ri=BN_num_bits(mod);
BN_zero(R);
BN_set_bit(R,mont->ri);
if ((BN_mod_inverse(&Ri,R,mod,ctx)) == NULL)
goto err;
BN_lshift(&Ri,&Ri,mont->ri);
BN_sub_word(&Ri,1);
BN_div(&(mont->Ni),NULL,&Ri,mod,ctx);
BN_free(&Ri);
}
#endif
BN_zero(&(mont->RR));
BN_set_bit(&(mont->RR),mont->ri*2);
BN_mod(&(mont->RR),&(mont->RR),&(mont->N),ctx);
return(1);
err:
return(0);
}
BN_MONT_CTX *BN_MONT_CTX_copy(BN_MONT_CTX *to, BN_MONT_CTX *from)
{
if (to == from) return(to);
BN_copy(&(to->RR),&(from->RR));
BN_copy(&(to->N),&(from->N));
BN_copy(&(to->Ni),&(from->Ni));
to->ri=from->ri;
to->n0=from->n0;
return(to);
}
