int BN_mod_mul(BIGNUM *ret, BIGNUM *a, BIGNUM *b, const BIGNUM *m, BN_CTX *ctx)
{
BIGNUM *t;
int r=0;
bn_check_top(a);
bn_check_top(b);
bn_check_top(m);
BN_CTX_start(ctx);
if ((t = BN_CTX_get(ctx)) == NULL) goto err;
if (a == b)
{ if (!BN_sqr(t,a,ctx)) goto err; }
else
{ if (!BN_mul(t,a,b,ctx)) goto err; }
if (!BN_mod(ret,t,m,ctx)) goto err;
r=1;
err:
BN_CTX_end(ctx);
return(r);
}
int BN_exp(BIGNUM *r, BIGNUM *a, BIGNUM *p, BN_CTX *ctx)
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
void atalla_initialize_accelerator_handle(void)
{
void *dl_handle;
int status;
unsigned int config_buf[1024];
static int tested;
if(tested)
return;
tested=1;
bzero((void *)config_buf, 1024);
dl_handle = dlopen("atasi.so", RTLD_NOW);
if (dl_handle == (void *) NULL)
{
return;
}
ptr_ASI_GetHardwareConfig =
(tfnASI_GetHardwareConfig *)dlsym(dl_handle,"ASI_GetHardwareConfig");
if (ptr_ASI_GetHardwareConfig)
{
status = (*ptr_ASI_GetHardwareConfig)(0L, config_buf);
if (status != 0)
{
printf("atasi.so library is present but not initialized\n");
printf("No HW acceleration available\n");
return;
}
}
else
{
return ;
}
ptr_ASI_RSAPrivateKeyOpFn=
(tfnASI_RSAPrivateKeyOpFn *)dlsym(dl_handle, "ASI_RSAPrivateKeyOpFn");
if (ptr_ASI_RSAPrivateKeyOpFn == NULL)
{
return;
}
ptr_ASI_GetPerformanceStatistics =
(tfnASI_GetPerformanceStatistics *)dlsym(dl_handle, "ASI_GetPerformanceStatistics");
if (ptr_ASI_GetPerformanceStatistics == NULL)
{
return;
}
asi_accelerator_present = 1;
return;
}
int BN_mod_exp_atalla(BIGNUM *r, BIGNUM *a, const BIGNUM *p, const BIGNUM *m)
{
unsigned char *abin;
unsigned char *pbin;
unsigned char *mbin;
unsigned char *rbin;
int an,pn,mn,ret;
RSAPrivateKey keydata;
atalla_initialize_accelerator_handle();
if(!asi_accelerator_present)
return 0;
# define ASIZE 128
an=BN_num_bytes(a);
pn=BN_num_bytes(p);
mn=BN_num_bytes(m);
if(an <= ASIZE && pn <= ASIZE && mn <= ASIZE)
{
int size=mn;
assert(an <= mn);
abin=alloca(size);
memset(abin,'\0',mn);
BN_bn2bin(a,abin+size-an);
pbin=alloca(pn);
BN_bn2bin(p,pbin);
mbin=alloca(size);
memset(mbin,'\0',mn);
BN_bn2bin(m,mbin+size-mn);
rbin=alloca(size);
memset(&keydata,'\0',sizeof keydata);
keydata.privateExponent.data=pbin;
keydata.privateExponent.len=pn;
keydata.modulus.data=mbin;
keydata.modulus.len=size;
ret=(*ptr_ASI_RSAPrivateKeyOpFn)(&keydata,rbin,abin,keydata.modulus.len);
if(!ret)
{
BN_bin2bn(rbin,keydata.modulus.len,r);
return 1;
}
}
return 0;
}
int BN_mod_exp(BIGNUM *r, BIGNUM *a, const BIGNUM *p, const BIGNUM *m,
BN_CTX *ctx)
{
int ret;
bn_check_top(a);
bn_check_top(p);
bn_check_top(m);
#ifdef ATALLA
if(BN_mod_exp_atalla(r,a,p,m))
return 1;
tried_atalla=1;
#endif
#ifdef MONT_MUL_MOD
if (BN_is_odd(m))
{ ret=BN_mod_exp_mont(r,a,p,m,ctx,NULL); }
else
#endif
#ifdef RECP_MUL_MOD
{ ret=BN_mod_exp_recp(r,a,p,m,ctx); }
#else
{ ret=BN_mod_exp_simple(r,a,p,m,ctx); }
#endif
#ifdef ATALLA
tried_atalla=0;
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
BN_one(r);
return(1);
}
BN_CTX_start(ctx);
if ((aa = BN_CTX_get(ctx)) == NULL) goto err;
BN_RECP_CTX_init(&recp);
if (BN_RECP_CTX_set(&recp,m,ctx) <= 0) goto err;
BN_init(&(val[0]));
ts=1;
if (!BN_mod(&(val[0]),a,m,ctx)) goto err;
if (!BN_mod_mul_reciprocal(aa,&(val[0]),&(val[0]),&recp,ctx))
goto err;
if (bits <= 17)
window=1;
else if (bits >= 256)
window=5;
else if (bits >= 128)
window=4;
else
window=3;
j=1<<(window-1);
for (i=1; i<j; i++)
{
BN_init(&val[i]);
if (!BN_mod_mul_reciprocal(&(val[i]),&(val[i-1]),aa,&recp,ctx))
goto err;
}
ts=i;
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
int BN_mod_exp_mont(BIGNUM *rr, BIGNUM *a, const BIGNUM *p,
const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *in_mont)
{
int i,j,bits,ret=0,wstart,wend,window,wvalue;
int start=1,ts=0;
BIGNUM *d,*r;
BIGNUM *aa;
BIGNUM val[TABLE_SIZE];
BN_MONT_CTX *mont=NULL;
bn_check_top(a);
bn_check_top(p);
bn_check_top(m);
#ifdef ATALLA
if(!tried_atalla && BN_mod_exp_atalla(rr,a,p,m))
return 1;
#endif
if (!(m->d[0] & 1))
{
BNerr(BN_F_BN_MOD_EXP_MONT,BN_R_CALLED_WITH_EVEN_MODULUS);
return(0);
}
bits=BN_num_bits(p);
if (bits == 0)
{
BN_one(rr);
return(1);
}
BN_CTX_start(ctx);
d = BN_CTX_get(ctx);
r = BN_CTX_get(ctx);
if (d == NULL || r == NULL) goto err;
#if 1
if (in_mont != NULL)
mont=in_mont;
else
#endif
{
if ((mont=BN_MONT_CTX_new()) == NULL) goto err;
if (!BN_MONT_CTX_set(mont,m,ctx)) goto err;
}
BN_init(&val[0]);
ts=1;
if (BN_ucmp(a,m) >= 0)
{
BN_mod(&(val[0]),a,m,ctx);
aa= &(val[0]);
}
else
aa=a;
if (!BN_to_montgomery(&(val[0]),aa,mont,ctx)) goto err;
if (!BN_mod_mul_montgomery(d,&(val[0]),&(val[0]),mont,ctx)) goto err;
if (bits <= 20)
window=1;
else if (bits >= 256)
window=5;
else if (bits >= 128)
window=4;
else
window=3;
j=1<<(window-1);
for (i=1; i<j; i++)
{
BN_init(&(val[i]));
if (!BN_mod_mul_montgomery(&(val[i]),&(val[i-1]),d,mont,ctx))
goto err;
}
ts=i;
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
BN_from_montgomery(rr,r,mont,ctx);
ret=1;
err:
if ((in_mont == NULL) && (mont != NULL)) BN_MONT_CTX_free(mont);
BN_CTX_end(ctx);
for (i=0; i<ts; i++)
BN_clear_free(&(val[i]));
return(ret);
}
int BN_mod_exp_simple(BIGNUM *r, BIGNUM *a, BIGNUM *p, BIGNUM *m,
BN_CTX *ctx)
{
int i,j,bits,ret=0,wstart,wend,window,wvalue,ts=0;
int start=1;
BIGNUM *d;
BIGNUM val[TABLE_SIZE];
bits=BN_num_bits(p);
if (bits == 0)
{
BN_one(r);
return(1);
}
BN_CTX_start(ctx);
if ((d = BN_CTX_get(ctx)) == NULL) goto err;
BN_init(&(val[0]));
ts=1;
if (!BN_mod(&(val[0]),a,m,ctx)) goto err;
if (!BN_mod_mul(d,&(val[0]),&(val[0]),m,ctx))
goto err;
if (bits <= 17)
window=1;
else if (bits >= 256)
window=5;
else if (bits >= 128)
window=4;
else
window=3;
j=1<<(window-1);
for (i=1; i<j; i++)
{
BN_init(&(val[i]));
if (!BN_mod_mul(&(val[i]),&(val[i-1]),d,m,ctx))
goto err;
}
ts=i;
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
