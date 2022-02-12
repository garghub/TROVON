RSA_METHOD *RSA_PKCS1_SSLeay(void)
{
return(&rsa_pkcs1_eay_meth);
}
static int RSA_eay_public_encrypt(int flen, unsigned char *from,
unsigned char *to, RSA *rsa, int padding)
{
BIGNUM f,ret;
int i,j,k,num=0,r= -1;
unsigned char *buf=NULL;
BN_CTX *ctx=NULL;
BN_init(&f);
BN_init(&ret);
if ((ctx=BN_CTX_new()) == NULL) goto err;
num=BN_num_bytes(rsa->n);
if ((buf=(unsigned char *)Malloc(num)) == NULL)
{
RSAerr(RSA_F_RSA_EAY_PUBLIC_ENCRYPT,ERR_R_MALLOC_FAILURE);
goto err;
}
switch (padding)
{
case RSA_PKCS1_PADDING:
i=RSA_padding_add_PKCS1_type_2(buf,num,from,flen);
break;
#ifndef NO_SHA
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
if (BN_bin2bn(buf,num,&f) == NULL) goto err;
if ((rsa->_method_mod_n == NULL) && (rsa->flags & RSA_FLAG_CACHE_PUBLIC))
{
if ((rsa->_method_mod_n=BN_MONT_CTX_new()) != NULL)
if (!BN_MONT_CTX_set(rsa->_method_mod_n,rsa->n,ctx))
goto err;
}
if (!rsa->meth->bn_mod_exp(&ret,&f,rsa->e,rsa->n,ctx,
rsa->_method_mod_n)) goto err;
j=BN_num_bytes(&ret);
i=BN_bn2bin(&ret,&(to[num-j]));
for (k=0; k<(num-i); k++)
to[k]=0;
r=num;
err:
if (ctx != NULL) BN_CTX_free(ctx);
BN_clear_free(&f);
BN_clear_free(&ret);
if (buf != NULL)
{
memset(buf,0,num);
Free(buf);
}
return(r);
}
static int RSA_eay_private_encrypt(int flen, unsigned char *from,
unsigned char *to, RSA *rsa, int padding)
{
BIGNUM f,ret;
int i,j,k,num=0,r= -1;
unsigned char *buf=NULL;
BN_CTX *ctx=NULL;
BN_init(&f);
BN_init(&ret);
if ((ctx=BN_CTX_new()) == NULL) goto err;
num=BN_num_bytes(rsa->n);
if ((buf=(unsigned char *)Malloc(num)) == NULL)
{
RSAerr(RSA_F_RSA_EAY_PRIVATE_ENCRYPT,ERR_R_MALLOC_FAILURE);
goto err;
}
switch (padding)
{
case RSA_PKCS1_PADDING:
i=RSA_padding_add_PKCS1_type_1(buf,num,from,flen);
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
if (BN_bin2bn(buf,num,&f) == NULL) goto err;
if ((rsa->flags & RSA_FLAG_BLINDING) && (rsa->blinding == NULL))
RSA_blinding_on(rsa,ctx);
if (rsa->flags & RSA_FLAG_BLINDING)
if (!BN_BLINDING_convert(&f,rsa->blinding,ctx)) goto err;
if ( (rsa->p != NULL) &&
(rsa->q != NULL) &&
(rsa->dmp1 != NULL) &&
(rsa->dmq1 != NULL) &&
(rsa->iqmp != NULL))
{ if (!rsa->meth->rsa_mod_exp(&ret,&f,rsa)) goto err; }
else
{
if (!rsa->meth->bn_mod_exp(&ret,&f,rsa->d,rsa->n,ctx,NULL)) goto err;
}
if (rsa->flags & RSA_FLAG_BLINDING)
if (!BN_BLINDING_invert(&ret,rsa->blinding,ctx)) goto err;
j=BN_num_bytes(&ret);
i=BN_bn2bin(&ret,&(to[num-j]));
for (k=0; k<(num-i); k++)
to[k]=0;
r=num;
err:
if (ctx != NULL) BN_CTX_free(ctx);
BN_clear_free(&ret);
BN_clear_free(&f);
if (buf != NULL)
{
memset(buf,0,num);
Free(buf);
}
return(r);
}
static int RSA_eay_private_decrypt(int flen, unsigned char *from,
unsigned char *to, RSA *rsa, int padding)
{
BIGNUM f,ret;
int j,num=0,r= -1;
unsigned char *p;
unsigned char *buf=NULL;
BN_CTX *ctx=NULL;
BN_init(&f);
BN_init(&ret);
ctx=BN_CTX_new();
if (ctx == NULL) goto err;
num=BN_num_bytes(rsa->n);
if ((buf=(unsigned char *)Malloc(num)) == NULL)
{
RSAerr(RSA_F_RSA_EAY_PRIVATE_DECRYPT,ERR_R_MALLOC_FAILURE);
goto err;
}
if (flen > num)
{
RSAerr(RSA_F_RSA_EAY_PRIVATE_DECRYPT,RSA_R_DATA_GREATER_THAN_MOD_LEN);
goto err;
}
if (BN_bin2bn(from,(int)flen,&f) == NULL) goto err;
if ((rsa->flags & RSA_FLAG_BLINDING) && (rsa->blinding == NULL))
RSA_blinding_on(rsa,ctx);
if (rsa->flags & RSA_FLAG_BLINDING)
if (!BN_BLINDING_convert(&f,rsa->blinding,ctx)) goto err;
if ( (rsa->p != NULL) &&
(rsa->q != NULL) &&
(rsa->dmp1 != NULL) &&
(rsa->dmq1 != NULL) &&
(rsa->iqmp != NULL))
{ if (!rsa->meth->rsa_mod_exp(&ret,&f,rsa)) goto err; }
else
{
if (!rsa->meth->bn_mod_exp(&ret,&f,rsa->d,rsa->n,ctx,NULL))
goto err;
}
if (rsa->flags & RSA_FLAG_BLINDING)
if (!BN_BLINDING_invert(&ret,rsa->blinding,ctx)) goto err;
p=buf;
j=BN_bn2bin(&ret,p);
switch (padding)
{
case RSA_PKCS1_PADDING:
r=RSA_padding_check_PKCS1_type_2(to,num,buf,j,num);
break;
#ifndef NO_SHA
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
if (ctx != NULL) BN_CTX_free(ctx);
BN_clear_free(&f);
BN_clear_free(&ret);
if (buf != NULL)
{
memset(buf,0,num);
Free(buf);
}
return(r);
}
static int RSA_eay_public_decrypt(int flen, unsigned char *from,
unsigned char *to, RSA *rsa, int padding)
{
BIGNUM f,ret;
int i,num=0,r= -1;
unsigned char *p;
unsigned char *buf=NULL;
BN_CTX *ctx=NULL;
BN_init(&f);
BN_init(&ret);
ctx=BN_CTX_new();
if (ctx == NULL) goto err;
num=BN_num_bytes(rsa->n);
buf=(unsigned char *)Malloc(num);
if (buf == NULL)
{
RSAerr(RSA_F_RSA_EAY_PUBLIC_DECRYPT,ERR_R_MALLOC_FAILURE);
goto err;
}
if (flen > num)
{
RSAerr(RSA_F_RSA_EAY_PUBLIC_DECRYPT,RSA_R_DATA_GREATER_THAN_MOD_LEN);
goto err;
}
if (BN_bin2bn(from,flen,&f) == NULL) goto err;
if ((rsa->_method_mod_n == NULL) && (rsa->flags & RSA_FLAG_CACHE_PUBLIC))
{
if ((rsa->_method_mod_n=BN_MONT_CTX_new()) != NULL)
if (!BN_MONT_CTX_set(rsa->_method_mod_n,rsa->n,ctx))
goto err;
}
if (!rsa->meth->bn_mod_exp(&ret,&f,rsa->e,rsa->n,ctx,
rsa->_method_mod_n)) goto err;
p=buf;
i=BN_bn2bin(&ret,p);
switch (padding)
{
case RSA_PKCS1_PADDING:
r=RSA_padding_check_PKCS1_type_1(to,num,buf,i,num);
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
if (ctx != NULL) BN_CTX_free(ctx);
BN_clear_free(&f);
BN_clear_free(&ret);
if (buf != NULL)
{
memset(buf,0,num);
Free(buf);
}
return(r);
}
static int RSA_eay_mod_exp(BIGNUM *r0, BIGNUM *I, RSA *rsa)
{
BIGNUM r1,m1;
int ret=0;
BN_CTX *ctx;
if ((ctx=BN_CTX_new()) == NULL) goto err;
BN_init(&m1);
BN_init(&r1);
if (rsa->flags & RSA_FLAG_CACHE_PRIVATE)
{
if (rsa->_method_mod_p == NULL)
{
if ((rsa->_method_mod_p=BN_MONT_CTX_new()) != NULL)
if (!BN_MONT_CTX_set(rsa->_method_mod_p,rsa->p,
ctx))
goto err;
}
if (rsa->_method_mod_q == NULL)
{
if ((rsa->_method_mod_q=BN_MONT_CTX_new()) != NULL)
if (!BN_MONT_CTX_set(rsa->_method_mod_q,rsa->q,
ctx))
goto err;
}
}
if (!BN_mod(&r1,I,rsa->q,ctx)) goto err;
if (!rsa->meth->bn_mod_exp(&m1,&r1,rsa->dmq1,rsa->q,ctx,
rsa->_method_mod_q)) goto err;
if (!BN_mod(&r1,I,rsa->p,ctx)) goto err;
if (!rsa->meth->bn_mod_exp(r0,&r1,rsa->dmp1,rsa->p,ctx,
rsa->_method_mod_p)) goto err;
if (!BN_sub(r0,r0,&m1)) goto err;
if (r0->neg)
if (!BN_add(r0,r0,rsa->p)) goto err;
if (!BN_mul(&r1,r0,rsa->iqmp,ctx)) goto err;
if (!BN_mod(r0,&r1,rsa->p,ctx)) goto err;
if (r0->neg)
if (!BN_add(r0,r0,rsa->p)) goto err;
if (!BN_mul(&r1,r0,rsa->q,ctx)) goto err;
if (!BN_add(r0,&r1,&m1)) goto err;
ret=1;
err:
BN_clear_free(&m1);
BN_clear_free(&r1);
BN_CTX_free(ctx);
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
