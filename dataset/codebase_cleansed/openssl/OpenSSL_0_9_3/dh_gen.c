DH *DH_generate_parameters(int prime_len, int generator,
void (*callback)(int,int,char *), char *cb_arg)
{
BIGNUM *p=NULL,*t1,*t2;
DH *ret=NULL;
int g,ok= -1;
BN_CTX *ctx=NULL;
ret=DH_new();
ctx=BN_CTX_new();
if (ctx == NULL) goto err;
t1= &(ctx->bn[0]);
t2= &(ctx->bn[1]);
ctx->tos=2;
if (generator == DH_GENERATOR_2)
{
BN_set_word(t1,24);
BN_set_word(t2,11);
g=2;
}
#ifdef undef
else if (generator == DH_GENERATOR_3)
{
BN_set_word(t1,12);
BN_set_word(t2,5);
g=3;
}
#endif
else if (generator == DH_GENERATOR_5)
{
BN_set_word(t1,10);
BN_set_word(t2,3);
g=5;
}
else
g=generator;
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
if (ctx != NULL) BN_CTX_free(ctx);
if (!ok && (ret != NULL))
{
DH_free(ret);
ret=NULL;
}
return(ret);
}
