int RSA_size(const RSA *r)
{
return(BN_num_bytes(r->n));
}
int RSA_public_encrypt(int flen, const unsigned char *from, unsigned char *to,
RSA *rsa, int padding)
{
#ifdef OPENSSL_FIPS
if (FIPS_mode() && !(rsa->meth->flags & RSA_FLAG_FIPS_METHOD)
&& !(rsa->flags & RSA_FLAG_NON_FIPS_ALLOW))
{
RSAerr(RSA_F_RSA_PUBLIC_ENCRYPT, RSA_R_NON_FIPS_RSA_METHOD);
return -1;
}
#endif
return(rsa->meth->rsa_pub_enc(flen, from, to, rsa, padding));
}
int RSA_private_encrypt(int flen, const unsigned char *from, unsigned char *to,
RSA *rsa, int padding)
{
#ifdef OPENSSL_FIPS
if (FIPS_mode() && !(rsa->meth->flags & RSA_FLAG_FIPS_METHOD)
&& !(rsa->flags & RSA_FLAG_NON_FIPS_ALLOW))
{
RSAerr(RSA_F_RSA_PRIVATE_ENCRYPT, RSA_R_NON_FIPS_RSA_METHOD);
return -1;
}
#endif
return(rsa->meth->rsa_priv_enc(flen, from, to, rsa, padding));
}
int RSA_private_decrypt(int flen, const unsigned char *from, unsigned char *to,
RSA *rsa, int padding)
{
#ifdef OPENSSL_FIPS
if (FIPS_mode() && !(rsa->meth->flags & RSA_FLAG_FIPS_METHOD)
&& !(rsa->flags & RSA_FLAG_NON_FIPS_ALLOW))
{
RSAerr(RSA_F_RSA_PRIVATE_DECRYPT, RSA_R_NON_FIPS_RSA_METHOD);
return -1;
}
#endif
return(rsa->meth->rsa_priv_dec(flen, from, to, rsa, padding));
}
int RSA_public_decrypt(int flen, const unsigned char *from, unsigned char *to,
RSA *rsa, int padding)
{
#ifdef OPENSSL_FIPS
if (FIPS_mode() && !(rsa->meth->flags & RSA_FLAG_FIPS_METHOD)
&& !(rsa->flags & RSA_FLAG_NON_FIPS_ALLOW))
{
RSAerr(RSA_F_RSA_PUBLIC_DECRYPT, RSA_R_NON_FIPS_RSA_METHOD);
return -1;
}
#endif
return(rsa->meth->rsa_pub_dec(flen, from, to, rsa, padding));
}
int RSA_flags(const RSA *r)
{
return((r == NULL)?0:r->meth->flags);
}
void RSA_blinding_off(RSA *rsa)
{
if (rsa->blinding != NULL)
{
BN_BLINDING_free(rsa->blinding);
rsa->blinding=NULL;
}
rsa->flags &= ~RSA_FLAG_BLINDING;
rsa->flags |= RSA_FLAG_NO_BLINDING;
}
int RSA_blinding_on(RSA *rsa, BN_CTX *ctx)
{
int ret=0;
if (rsa->blinding != NULL)
RSA_blinding_off(rsa);
rsa->blinding = RSA_setup_blinding(rsa, ctx);
if (rsa->blinding == NULL)
goto err;
rsa->flags |= RSA_FLAG_BLINDING;
rsa->flags &= ~RSA_FLAG_NO_BLINDING;
ret=1;
err:
return(ret);
}
static BIGNUM *rsa_get_public_exp(const BIGNUM *d, const BIGNUM *p,
const BIGNUM *q, BN_CTX *ctx)
{
BIGNUM *ret = NULL, *r0, *r1, *r2;
if (d == NULL || p == NULL || q == NULL)
return NULL;
BN_CTX_start(ctx);
r0 = BN_CTX_get(ctx);
r1 = BN_CTX_get(ctx);
r2 = BN_CTX_get(ctx);
if (r2 == NULL)
goto err;
if (!BN_sub(r1, p, BN_value_one())) goto err;
if (!BN_sub(r2, q, BN_value_one())) goto err;
if (!BN_mul(r0, r1, r2, ctx)) goto err;
ret = BN_mod_inverse(NULL, d, r0, ctx);
err:
BN_CTX_end(ctx);
return ret;
}
BN_BLINDING *RSA_setup_blinding(RSA *rsa, BN_CTX *in_ctx)
{
BIGNUM local_n;
BIGNUM *e,*n;
BN_CTX *ctx;
BN_BLINDING *ret = NULL;
if (in_ctx == NULL)
{
if ((ctx = BN_CTX_new()) == NULL) return 0;
}
else
ctx = in_ctx;
BN_CTX_start(ctx);
e = BN_CTX_get(ctx);
if (e == NULL)
{
RSAerr(RSA_F_RSA_SETUP_BLINDING, ERR_R_MALLOC_FAILURE);
goto err;
}
if (rsa->e == NULL)
{
e = rsa_get_public_exp(rsa->d, rsa->p, rsa->q, ctx);
if (e == NULL)
{
RSAerr(RSA_F_RSA_SETUP_BLINDING, RSA_R_NO_PUBLIC_EXPONENT);
goto err;
}
}
else
e = rsa->e;
if ((RAND_status() == 0) && rsa->d != NULL && rsa->d->d != NULL)
{
RAND_add(rsa->d->d, rsa->d->dmax * sizeof rsa->d->d[0], 0.0);
}
if (!(rsa->flags & RSA_FLAG_NO_CONSTTIME))
{
n = &local_n;
BN_with_flags(n, rsa->n, BN_FLG_CONSTTIME);
}
else
n = rsa->n;
ret = BN_BLINDING_create_param(NULL, e, n, ctx,
rsa->meth->bn_mod_exp, rsa->_method_mod_n);
if (ret == NULL)
{
RSAerr(RSA_F_RSA_SETUP_BLINDING, ERR_R_BN_LIB);
goto err;
}
CRYPTO_THREADID_current(BN_BLINDING_thread_id(ret));
err:
BN_CTX_end(ctx);
if (in_ctx == NULL)
BN_CTX_free(ctx);
if(rsa->e == NULL)
BN_free(e);
return ret;
}
