DH *DH_generate_parameters(int prime_len, int generator,
void (*callback)(int,int,void *), void *cb_arg)
{
BIGNUM *p=NULL,*t1,*t2;
DH *ret=NULL;
int g,ok= -1;
BN_CTX *ctx=NULL;
ret=DH_new();
if (ret == NULL) goto err;
ctx=BN_CTX_new();
if (ctx == NULL) goto err;
BN_CTX_start(ctx);
t1 = BN_CTX_get(ctx);
t2 = BN_CTX_get(ctx);
if (t1 == NULL || t2 == NULL) goto err;
if (generator <= 1)
{
DHerr(DH_F_DH_GENERATE_PARAMETERS, DH_R_BAD_GENERATOR);
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
p=BN_generate_prime(NULL,prime_len,1,t1,t2,callback,cb_arg);
if (p == NULL) goto err;
if (callback != NULL) callback(3,0,cb_arg);
ret->p=p;
ret->g=BN_new();
if (!BN_set_word(ret->g,g)) goto err;
ok=1;
err:
if (ok == -1)
{
DHerr(DH_F_DH_GENERATE_PARAMETERS,ERR_R_BN_LIB);
ok=0;
}
if (ctx != NULL)
{
BN_CTX_end(ctx);
BN_CTX_free(ctx);
}
if (!ok && (ret != NULL))
{
DH_free(ret);
ret=NULL;
}
return(ret);
}
