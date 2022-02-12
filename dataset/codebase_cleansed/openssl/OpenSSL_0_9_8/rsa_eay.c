const RSA_METHOD *RSA_PKCS1_SSLeay(void)
{
return(&rsa_pkcs1_eay_meth);
}
static int RSA_eay_public_encrypt(int flen, const unsigned char *from,
unsigned char *to, RSA *rsa, int padding)
{
BIGNUM *f,*ret;
int i,j,k,num=0,r= -1;
unsigned char *buf=NULL;
BN_CTX *ctx=NULL;
if ((ctx=BN_CTX_new()) == NULL) goto err;
BN_CTX_start(ctx);
f = BN_CTX_get(ctx);
ret = BN_CTX_get(ctx);
num=BN_num_bytes(rsa->n);
buf = OPENSSL_malloc(num);
if (!f || !ret || !buf)
{
RSAerr(RSA_F_RSA_EAY_PUBLIC_ENCRYPT,ERR_R_MALLOC_FAILURE);
goto err;
}
switch (padding)
{
case RSA_PKCS1_PADDING:
i=RSA_padding_add_PKCS1_type_2(buf,num,from,flen);
break;
#ifndef OPENSSL_NO_SHA
case RSA_PKCS1_OAEP_PADDING:
i=RSA_padding_add_PKCS1_OAEP(buf,num,from,flen,NULL,0);
break;
#endif
case RSA_SSLV23_PADDING:
i=RSA_padding_add_SSLv23(buf,num,from,flen);
break;
case RSA_NO_PADDING:
i=RSA_padding_add_none(buf,num,from,flen);
break;
default:
RSAerr(RSA_F_RSA_EAY_PUBLIC_ENCRYPT,RSA_R_UNKNOWN_PADDING_TYPE);
goto err;
}
if (i <= 0) goto err;
if (BN_bin2bn(buf,num,f) == NULL) goto err;
if (BN_ucmp(f, rsa->n) >= 0)
{
RSAerr(RSA_F_RSA_EAY_PUBLIC_ENCRYPT,RSA_R_DATA_TOO_LARGE_FOR_MODULUS);
goto err;
}
MONT_HELPER(rsa, ctx, n, rsa->flags & RSA_FLAG_CACHE_PUBLIC, goto err);
if (!rsa->meth->bn_mod_exp(ret,f,rsa->e,rsa->n,ctx,
rsa->_method_mod_n)) goto err;
j=BN_num_bytes(ret);
i=BN_bn2bin(ret,&(to[num-j]));
for (k=0; k<(num-i); k++)
to[k]=0;
r=num;
err:
if (ctx != NULL)
{
BN_CTX_end(ctx);
BN_CTX_free(ctx);
}
if (buf != NULL)
{
OPENSSL_cleanse(buf,num);
OPENSSL_free(buf);
}
return(r);
}
static BN_BLINDING *rsa_get_blinding(RSA *rsa, BIGNUM **r, int *local, BN_CTX *ctx)
{
BN_BLINDING *ret;
if (rsa->blinding == NULL)
{
if (rsa->blinding == NULL)
{
CRYPTO_w_lock(CRYPTO_LOCK_RSA);
if (rsa->blinding == NULL)
rsa->blinding = RSA_setup_blinding(rsa, ctx);
CRYPTO_w_unlock(CRYPTO_LOCK_RSA);
}
}
ret = rsa->blinding;
if (ret == NULL)
return NULL;
if (BN_BLINDING_get_thread_id(ret) != CRYPTO_thread_id())
{
*local = 0;
if (rsa->mt_blinding == NULL)
{
CRYPTO_w_lock(CRYPTO_LOCK_RSA);
if (rsa->mt_blinding == NULL)
rsa->mt_blinding = RSA_setup_blinding(rsa, ctx);
CRYPTO_w_unlock(CRYPTO_LOCK_RSA);
}
ret = rsa->mt_blinding;
}
else
*local = 1;
return ret;
}
static int rsa_blinding_convert(BN_BLINDING *b, int local, BIGNUM *f,
BIGNUM *r, BN_CTX *ctx)
{
if (local)
return BN_BLINDING_convert_ex(f, NULL, b, ctx);
else
{
int ret;
CRYPTO_w_lock(CRYPTO_LOCK_RSA_BLINDING);
ret = BN_BLINDING_convert_ex(f, r, b, ctx);
CRYPTO_w_unlock(CRYPTO_LOCK_RSA_BLINDING);
return ret;
}
}
static int rsa_blinding_invert(BN_BLINDING *b, int local, BIGNUM *f,
BIGNUM *r, BN_CTX *ctx)
{
if (local)
return BN_BLINDING_invert_ex(f, NULL, b, ctx);
else
{
int ret;
CRYPTO_r_lock(CRYPTO_LOCK_RSA_BLINDING);
ret = BN_BLINDING_invert_ex(f, r, b, ctx);
CRYPTO_r_unlock(CRYPTO_LOCK_RSA_BLINDING);
return ret;
}
}
static int RSA_eay_private_encrypt(int flen, const unsigned char *from,
unsigned char *to, RSA *rsa, int padding)
{
BIGNUM *f, *ret, *br, *res;
int i,j,k,num=0,r= -1;
unsigned char *buf=NULL;
BN_CTX *ctx=NULL;
int local_blinding = 0;
BN_BLINDING *blinding = NULL;
if ((ctx=BN_CTX_new()) == NULL) goto err;
BN_CTX_start(ctx);
f = BN_CTX_get(ctx);
br = BN_CTX_get(ctx);
ret = BN_CTX_get(ctx);
num = BN_num_bytes(rsa->n);
buf = OPENSSL_malloc(num);
if(!f || !ret || !buf)
{
RSAerr(RSA_F_RSA_EAY_PRIVATE_ENCRYPT,ERR_R_MALLOC_FAILURE);
goto err;
}
switch (padding)
{
case RSA_PKCS1_PADDING:
i=RSA_padding_add_PKCS1_type_1(buf,num,from,flen);
break;
case RSA_X931_PADDING:
i=RSA_padding_add_X931(buf,num,from,flen);
break;
case RSA_NO_PADDING:
i=RSA_padding_add_none(buf,num,from,flen);
break;
case RSA_SSLV23_PADDING:
default:
RSAerr(RSA_F_RSA_EAY_PRIVATE_ENCRYPT,RSA_R_UNKNOWN_PADDING_TYPE);
goto err;
}
if (i <= 0) goto err;
if (BN_bin2bn(buf,num,f) == NULL) goto err;
if (BN_ucmp(f, rsa->n) >= 0)
{
RSAerr(RSA_F_RSA_EAY_PRIVATE_ENCRYPT,RSA_R_DATA_TOO_LARGE_FOR_MODULUS);
goto err;
}
if (!(rsa->flags & RSA_FLAG_NO_BLINDING))
{
blinding = rsa_get_blinding(rsa, &br, &local_blinding, ctx);
if (blinding == NULL)
{
RSAerr(RSA_F_RSA_EAY_PRIVATE_ENCRYPT, ERR_R_INTERNAL_ERROR);
goto err;
}
}
if (blinding != NULL)
if (!rsa_blinding_convert(blinding, local_blinding, f, br, ctx))
goto err;
if ( (rsa->flags & RSA_FLAG_EXT_PKEY) ||
((rsa->p != NULL) &&
(rsa->q != NULL) &&
(rsa->dmp1 != NULL) &&
(rsa->dmq1 != NULL) &&
(rsa->iqmp != NULL)) )
{
if (!rsa->meth->rsa_mod_exp(ret, f, rsa, ctx)) goto err;
}
else
{
BIGNUM local_d;
BIGNUM *d = NULL;
if (!(rsa->flags & RSA_FLAG_NO_EXP_CONSTTIME))
{
BN_init(&local_d);
d = &local_d;
BN_with_flags(d, rsa->d, BN_FLG_EXP_CONSTTIME);
}
else
d = rsa->d;
MONT_HELPER(rsa, ctx, n, rsa->flags & RSA_FLAG_CACHE_PUBLIC, goto err);
if (!rsa->meth->bn_mod_exp(ret,f,d,rsa->n,ctx,
rsa->_method_mod_n)) goto err;
}
if (blinding)
if (!rsa_blinding_invert(blinding, local_blinding, ret, br, ctx))
goto err;
if (padding == RSA_X931_PADDING)
{
BN_sub(f, rsa->n, ret);
if (BN_cmp(ret, f))
res = f;
else
res = ret;
}
else
res = ret;
j=BN_num_bytes(res);
i=BN_bn2bin(res,&(to[num-j]));
for (k=0; k<(num-i); k++)
to[k]=0;
r=num;
err:
if (ctx != NULL)
{
BN_CTX_end(ctx);
BN_CTX_free(ctx);
}
if (buf != NULL)
{
OPENSSL_cleanse(buf,num);
OPENSSL_free(buf);
}
return(r);
}
static int RSA_eay_private_decrypt(int flen, const unsigned char *from,
unsigned char *to, RSA *rsa, int padding)
{
BIGNUM *f, *ret, *br;
int j,num=0,r= -1;
unsigned char *p;
unsigned char *buf=NULL;
BN_CTX *ctx=NULL;
int local_blinding = 0;
BN_BLINDING *blinding = NULL;
if((ctx = BN_CTX_new()) == NULL) goto err;
BN_CTX_start(ctx);
f = BN_CTX_get(ctx);
br = BN_CTX_get(ctx);
ret = BN_CTX_get(ctx);
num = BN_num_bytes(rsa->n);
buf = OPENSSL_malloc(num);
if(!f || !ret || !buf)
{
RSAerr(RSA_F_RSA_EAY_PRIVATE_DECRYPT,ERR_R_MALLOC_FAILURE);
goto err;
}
if (flen > num)
{
RSAerr(RSA_F_RSA_EAY_PRIVATE_DECRYPT,RSA_R_DATA_GREATER_THAN_MOD_LEN);
goto err;
}
if (BN_bin2bn(from,(int)flen,f) == NULL) goto err;
if (BN_ucmp(f, rsa->n) >= 0)
{
RSAerr(RSA_F_RSA_EAY_PRIVATE_DECRYPT,RSA_R_DATA_TOO_LARGE_FOR_MODULUS);
goto err;
}
if (!(rsa->flags & RSA_FLAG_NO_BLINDING))
{
blinding = rsa_get_blinding(rsa, &br, &local_blinding, ctx);
if (blinding == NULL)
{
RSAerr(RSA_F_RSA_EAY_PRIVATE_DECRYPT, ERR_R_INTERNAL_ERROR);
goto err;
}
}
if (blinding != NULL)
if (!rsa_blinding_convert(blinding, local_blinding, f, br, ctx))
goto err;
if ( (rsa->flags & RSA_FLAG_EXT_PKEY) ||
((rsa->p != NULL) &&
(rsa->q != NULL) &&
(rsa->dmp1 != NULL) &&
(rsa->dmq1 != NULL) &&
(rsa->iqmp != NULL)) )
{
if (!rsa->meth->rsa_mod_exp(ret, f, rsa, ctx)) goto err;
}
else
{
BIGNUM local_d;
BIGNUM *d = NULL;
if (!(rsa->flags & RSA_FLAG_NO_EXP_CONSTTIME))
{
d = &local_d;
BN_with_flags(d, rsa->d, BN_FLG_EXP_CONSTTIME);
}
else
d = rsa->d;
MONT_HELPER(rsa, ctx, n, rsa->flags & RSA_FLAG_CACHE_PUBLIC, goto err);
if (!rsa->meth->bn_mod_exp(ret,f,d,rsa->n,ctx,
rsa->_method_mod_n))
goto err;
}
if (blinding)
if (!rsa_blinding_invert(blinding, local_blinding, ret, br, ctx))
goto err;
p=buf;
j=BN_bn2bin(ret,p);
switch (padding)
{
case RSA_PKCS1_PADDING:
r=RSA_padding_check_PKCS1_type_2(to,num,buf,j,num);
break;
#ifndef OPENSSL_NO_SHA
case RSA_PKCS1_OAEP_PADDING:
r=RSA_padding_check_PKCS1_OAEP(to,num,buf,j,num,NULL,0);
break;
#endif
case RSA_SSLV23_PADDING:
r=RSA_padding_check_SSLv23(to,num,buf,j,num);
break;
case RSA_NO_PADDING:
r=RSA_padding_check_none(to,num,buf,j,num);
break;
default:
RSAerr(RSA_F_RSA_EAY_PRIVATE_DECRYPT,RSA_R_UNKNOWN_PADDING_TYPE);
goto err;
}
if (r < 0)
RSAerr(RSA_F_RSA_EAY_PRIVATE_DECRYPT,RSA_R_PADDING_CHECK_FAILED);
err:
if (ctx != NULL)
{
BN_CTX_end(ctx);
BN_CTX_free(ctx);
}
if (buf != NULL)
{
OPENSSL_cleanse(buf,num);
OPENSSL_free(buf);
}
return(r);
}
static int RSA_eay_public_decrypt(int flen, const unsigned char *from,
unsigned char *to, RSA *rsa, int padding)
{
BIGNUM *f,*ret;
int i,num=0,r= -1;
unsigned char *p;
unsigned char *buf=NULL;
BN_CTX *ctx=NULL;
if((ctx = BN_CTX_new()) == NULL) goto err;
BN_CTX_start(ctx);
f = BN_CTX_get(ctx);
ret = BN_CTX_get(ctx);
num=BN_num_bytes(rsa->n);
buf = OPENSSL_malloc(num);
if(!f || !ret || !buf)
{
RSAerr(RSA_F_RSA_EAY_PUBLIC_DECRYPT,ERR_R_MALLOC_FAILURE);
goto err;
}
if (flen > num)
{
RSAerr(RSA_F_RSA_EAY_PUBLIC_DECRYPT,RSA_R_DATA_GREATER_THAN_MOD_LEN);
goto err;
}
if (BN_bin2bn(from,flen,f) == NULL) goto err;
if (BN_ucmp(f, rsa->n) >= 0)
{
RSAerr(RSA_F_RSA_EAY_PUBLIC_DECRYPT,RSA_R_DATA_TOO_LARGE_FOR_MODULUS);
goto err;
}
MONT_HELPER(rsa, ctx, n, rsa->flags & RSA_FLAG_CACHE_PUBLIC, goto err);
if (!rsa->meth->bn_mod_exp(ret,f,rsa->e,rsa->n,ctx,
rsa->_method_mod_n)) goto err;
if ((padding == RSA_X931_PADDING) && ((ret->d[0] & 0xf) != 12))
BN_sub(ret, rsa->n, ret);
p=buf;
i=BN_bn2bin(ret,p);
switch (padding)
{
case RSA_PKCS1_PADDING:
r=RSA_padding_check_PKCS1_type_1(to,num,buf,i,num);
break;
case RSA_X931_PADDING:
r=RSA_padding_check_X931(to,num,buf,i,num);
break;
case RSA_NO_PADDING:
r=RSA_padding_check_none(to,num,buf,i,num);
break;
default:
RSAerr(RSA_F_RSA_EAY_PUBLIC_DECRYPT,RSA_R_UNKNOWN_PADDING_TYPE);
goto err;
}
if (r < 0)
RSAerr(RSA_F_RSA_EAY_PUBLIC_DECRYPT,RSA_R_PADDING_CHECK_FAILED);
err:
if (ctx != NULL)
{
BN_CTX_end(ctx);
BN_CTX_free(ctx);
}
if (buf != NULL)
{
OPENSSL_cleanse(buf,num);
OPENSSL_free(buf);
}
return(r);
}
static int RSA_eay_mod_exp(BIGNUM *r0, const BIGNUM *I, RSA *rsa, BN_CTX *ctx)
{
BIGNUM *r1,*m1,*vrfy;
BIGNUM local_dmp1, local_dmq1;
BIGNUM *dmp1, *dmq1;
int ret=0;
BN_CTX_start(ctx);
r1 = BN_CTX_get(ctx);
m1 = BN_CTX_get(ctx);
vrfy = BN_CTX_get(ctx);
MONT_HELPER(rsa, ctx, p, rsa->flags & RSA_FLAG_CACHE_PRIVATE, goto err);
MONT_HELPER(rsa, ctx, q, rsa->flags & RSA_FLAG_CACHE_PRIVATE, goto err);
MONT_HELPER(rsa, ctx, n, rsa->flags & RSA_FLAG_CACHE_PUBLIC, goto err);
if (!BN_mod(r1,I,rsa->q,ctx)) goto err;
if (!(rsa->flags & RSA_FLAG_NO_EXP_CONSTTIME))
{
dmq1 = &local_dmq1;
BN_with_flags(dmq1, rsa->dmq1, BN_FLG_EXP_CONSTTIME);
}
else
dmq1 = rsa->dmq1;
if (!rsa->meth->bn_mod_exp(m1,r1,dmq1,rsa->q,ctx,
rsa->_method_mod_q)) goto err;
if (!BN_mod(r1,I,rsa->p,ctx)) goto err;
if (!(rsa->flags & RSA_FLAG_NO_EXP_CONSTTIME))
{
dmp1 = &local_dmp1;
BN_with_flags(dmp1, rsa->dmp1, BN_FLG_EXP_CONSTTIME);
}
else
dmp1 = rsa->dmp1;
if (!rsa->meth->bn_mod_exp(r0,r1,dmp1,rsa->p,ctx,
rsa->_method_mod_p)) goto err;
if (!BN_sub(r0,r0,m1)) goto err;
if (BN_is_negative(r0))
if (!BN_add(r0,r0,rsa->p)) goto err;
if (!BN_mul(r1,r0,rsa->iqmp,ctx)) goto err;
if (!BN_mod(r0,r1,rsa->p,ctx)) goto err;
if (BN_is_negative(r0))
if (!BN_add(r0,r0,rsa->p)) goto err;
if (!BN_mul(r1,r0,rsa->q,ctx)) goto err;
if (!BN_add(r0,r1,m1)) goto err;
if (rsa->e && rsa->n)
{
if (!rsa->meth->bn_mod_exp(vrfy,r0,rsa->e,rsa->n,ctx,rsa->_method_mod_n)) goto err;
if (!BN_sub(vrfy, vrfy, I)) goto err;
if (!BN_mod(vrfy, vrfy, rsa->n, ctx)) goto err;
if (BN_is_negative(vrfy))
if (!BN_add(vrfy, vrfy, rsa->n)) goto err;
if (!BN_is_zero(vrfy))
{
BIGNUM local_d;
BIGNUM *d = NULL;
if (!(rsa->flags & RSA_FLAG_NO_EXP_CONSTTIME))
{
d = &local_d;
BN_with_flags(d, rsa->d, BN_FLG_EXP_CONSTTIME);
}
else
d = rsa->d;
if (!rsa->meth->bn_mod_exp(r0,I,d,rsa->n,ctx,
rsa->_method_mod_n)) goto err;
}
}
ret=1;
err:
BN_CTX_end(ctx);
return(ret);
}
static int RSA_eay_init(RSA *rsa)
{
rsa->flags|=RSA_FLAG_CACHE_PUBLIC|RSA_FLAG_CACHE_PRIVATE;
return(1);
}
static int RSA_eay_finish(RSA *rsa)
{
if (rsa->_method_mod_n != NULL)
BN_MONT_CTX_free(rsa->_method_mod_n);
if (rsa->_method_mod_p != NULL)
BN_MONT_CTX_free(rsa->_method_mod_p);
if (rsa->_method_mod_q != NULL)
BN_MONT_CTX_free(rsa->_method_mod_q);
return(1);
}
