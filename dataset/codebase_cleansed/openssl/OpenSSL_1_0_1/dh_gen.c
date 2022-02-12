int DH_generate_parameters_ex(DH *ret, int prime_len, int generator, BN_GENCB *cb)
{
#ifdef OPENSSL_FIPS
if (FIPS_mode() && !(ret->meth->flags & DH_FLAG_FIPS_METHOD)
&& !(ret->flags & DH_FLAG_NON_FIPS_ALLOW))
{
DHerr(DH_F_DH_GENERATE_PARAMETERS_EX, DH_R_NON_FIPS_METHOD);
return 0;
}
#endif
if(ret->meth->generate_params)
return ret->meth->generate_params(ret, prime_len, generator, cb);
#ifdef OPENSSL_FIPS
if (FIPS_mode())
return FIPS_dh_generate_parameters_ex(ret, prime_len,
generator, cb);
#endif
return dh_builtin_genparams(ret, prime_len, generator, cb);
}
static int dh_builtin_genparams(DH *ret, int prime_len, int generator, BN_GENCB *cb)
{
BIGNUM *t1,*t2;
int g,ok= -1;
BN_CTX *ctx=NULL;
ctx=BN_CTX_new();
if (ctx == NULL) goto err;
BN_CTX_start(ctx);
t1 = BN_CTX_get(ctx);
t2 = BN_CTX_get(ctx);
if (t1 == NULL || t2 == NULL) goto err;
if(!ret->p && ((ret->p = BN_new()) == NULL)) goto err;
if(!ret->g && ((ret->g = BN_new()) == NULL)) goto err;
if (generator <= 1)
{
DHerr(DH_F_DH_BUILTIN_GENPARAMS, DH_R_BAD_GENERATOR);
goto err;
}
if (generator == DH_GENERATOR_2)
{
if (!BN_set_word(t1,24)) goto err;
if (!BN_set_word(t2,11)) goto err;
g=2;
}
#if 0
else if (generator == DH_GENERATOR_3)
{
if (!BN_set_word(t1,12)) goto err;
if (!BN_set_word(t2,5)) goto err;
g=3;
}
#endif
else if (generator == DH_GENERATOR_5)
{
if (!BN_set_word(t1,10)) goto err;
if (!BN_set_word(t2,3)) goto err;
g=5;
}
else
{
if (!BN_set_word(t1,2)) goto err;
if (!BN_set_word(t2,1)) goto err;
g=generator;
}
if(!BN_generate_prime_ex(ret->p,prime_len,1,t1,t2,cb)) goto err;
if(!BN_GENCB_call(cb, 3, 0)) goto err;
if (!BN_set_word(ret->g,g)) goto err;
ok=1;
err:
if (ok == -1)
{
DHerr(DH_F_DH_BUILTIN_GENPARAMS,ERR_R_BN_LIB);
ok=0;
}
if (ctx != NULL)
{
BN_CTX_end(ctx);
BN_CTX_free(ctx);
}
return ok;
}
