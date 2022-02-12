RSA *RSA_generate_key(int bits, unsigned long e_value,
void (*callback)(int,int,void *), void *cb_arg)
{
RSA *rsa=NULL;
BIGNUM *r0=NULL,*r1=NULL,*r2=NULL,*r3=NULL,*tmp;
int bitsp,bitsq,ok= -1,n=0,i;
BN_CTX *ctx=NULL,*ctx2=NULL;
ctx=BN_CTX_new();
if (ctx == NULL) goto err;
ctx2=BN_CTX_new();
if (ctx2 == NULL) goto err;
r0= &(ctx->bn[0]);
r1= &(ctx->bn[1]);
r2= &(ctx->bn[2]);
r3= &(ctx->bn[3]);
ctx->tos+=4;
bitsp=(bits+1)/2;
bitsq=bits-bitsp;
rsa=RSA_new();
if (rsa == NULL) goto err;
rsa->e=BN_new();
if (rsa->e == NULL) goto err;
#if 1
for (i=0; i<sizeof(unsigned long)*8; i++)
{
if (e_value & (1<<i))
BN_set_bit(rsa->e,i);
}
#else
if (!BN_set_word(rsa->e,e_value)) goto err;
#endif
for (;;)
{
rsa->p=BN_generate_prime(NULL,bitsp,0,NULL,NULL,callback,cb_arg);
if (rsa->p == NULL) goto err;
if (!BN_sub(r2,rsa->p,BN_value_one())) goto err;
if (!BN_gcd(r1,r2,rsa->e,ctx)) goto err;
if (BN_is_one(r1)) break;
if (callback != NULL) callback(2,n++,cb_arg);
BN_free(rsa->p);
}
if (callback != NULL) callback(3,0,cb_arg);
for (;;)
{
rsa->q=BN_generate_prime(NULL,bitsq,0,NULL,NULL,callback,cb_arg);
if (rsa->q == NULL) goto err;
if (!BN_sub(r2,rsa->q,BN_value_one())) goto err;
if (!BN_gcd(r1,r2,rsa->e,ctx)) goto err;
if (BN_is_one(r1) && (BN_cmp(rsa->p,rsa->q) != 0))
break;
if (callback != NULL) callback(2,n++,cb_arg);
BN_free(rsa->q);
}
if (callback != NULL) callback(3,1,cb_arg);
if (BN_cmp(rsa->p,rsa->q) < 0)
{
tmp=rsa->p;
rsa->p=rsa->q;
rsa->q=tmp;
}
rsa->n=BN_new();
if (rsa->n == NULL) goto err;
if (!BN_mul(rsa->n,rsa->p,rsa->q,ctx)) goto err;
if (!BN_sub(r1,rsa->p,BN_value_one())) goto err;
if (!BN_sub(r2,rsa->q,BN_value_one())) goto err;
if (!BN_mul(r0,r1,r2,ctx)) goto err;
rsa->d=BN_mod_inverse(NULL,rsa->e,r0,ctx2);
if (rsa->d == NULL) goto err;
rsa->dmp1=BN_new();
if (rsa->dmp1 == NULL) goto err;
if (!BN_mod(rsa->dmp1,rsa->d,r1,ctx)) goto err;
rsa->dmq1=BN_new();
if (rsa->dmq1 == NULL) goto err;
if (!BN_mod(rsa->dmq1,rsa->d,r2,ctx)) goto err;
rsa->iqmp=BN_mod_inverse(NULL,rsa->q,rsa->p,ctx2);
if (rsa->iqmp == NULL) goto err;
ok=1;
err:
if (ok == -1)
{
RSAerr(RSA_F_RSA_GENERATE_KEY,ERR_LIB_BN);
ok=0;
}
BN_CTX_free(ctx);
BN_CTX_free(ctx2);
if (!ok)
{
if (rsa != NULL) RSA_free(rsa);
return(NULL);
}
else
return(rsa);
}
