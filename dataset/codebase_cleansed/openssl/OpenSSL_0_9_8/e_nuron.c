static const char *get_NURON_LIBNAME(void)
{
if(NURON_LIBNAME)
return NURON_LIBNAME;
return "nuronssl";
}
static void free_NURON_LIBNAME(void)
{
if(NURON_LIBNAME)
OPENSSL_free((void*)NURON_LIBNAME);
NURON_LIBNAME = NULL;
}
static long set_NURON_LIBNAME(const char *name)
{
free_NURON_LIBNAME();
return (((NURON_LIBNAME = BUF_strdup(name)) != NULL) ? 1 : 0);
}
static int nuron_destroy(ENGINE *e)
{
free_NURON_LIBNAME();
ERR_unload_NURON_strings();
return 1;
}
static int nuron_init(ENGINE *e)
{
if(pvDSOHandle != NULL)
{
NURONerr(NURON_F_NURON_INIT,NURON_R_ALREADY_LOADED);
return 0;
}
pvDSOHandle = DSO_load(NULL, get_NURON_LIBNAME(), NULL,
DSO_FLAG_NAME_TRANSLATION_EXT_ONLY);
if(!pvDSOHandle)
{
NURONerr(NURON_F_NURON_INIT,NURON_R_DSO_NOT_FOUND);
return 0;
}
pfnModExp = (tfnModExp *)DSO_bind_func(pvDSOHandle, NURON_F1);
if(!pfnModExp)
{
NURONerr(NURON_F_NURON_INIT,NURON_R_DSO_FUNCTION_NOT_FOUND);
return 0;
}
return 1;
}
static int nuron_finish(ENGINE *e)
{
free_NURON_LIBNAME();
if(pvDSOHandle == NULL)
{
NURONerr(NURON_F_NURON_FINISH,NURON_R_NOT_LOADED);
return 0;
}
if(!DSO_free(pvDSOHandle))
{
NURONerr(NURON_F_NURON_FINISH,NURON_R_DSO_FAILURE);
return 0;
}
pvDSOHandle=NULL;
pfnModExp=NULL;
return 1;
}
static int nuron_ctrl(ENGINE *e, int cmd, long i, void *p, void (*f)(void))
{
int initialised = ((pvDSOHandle == NULL) ? 0 : 1);
switch(cmd)
{
case NURON_CMD_SO_PATH:
if(p == NULL)
{
NURONerr(NURON_F_NURON_CTRL,ERR_R_PASSED_NULL_PARAMETER);
return 0;
}
if(initialised)
{
NURONerr(NURON_F_NURON_CTRL,NURON_R_ALREADY_LOADED);
return 0;
}
return set_NURON_LIBNAME((const char *)p);
default:
break;
}
NURONerr(NURON_F_NURON_CTRL,NURON_R_CTRL_COMMAND_NOT_IMPLEMENTED);
return 0;
}
static int nuron_mod_exp(BIGNUM *r,const BIGNUM *a,const BIGNUM *p,
const BIGNUM *m,BN_CTX *ctx)
{
if(!pvDSOHandle)
{
NURONerr(NURON_F_NURON_MOD_EXP,NURON_R_NOT_LOADED);
return 0;
}
return pfnModExp(r,a,p,m);
}
static int nuron_rsa_mod_exp(BIGNUM *r0, const BIGNUM *I, RSA *rsa, BN_CTX *ctx)
{
return nuron_mod_exp(r0,I,rsa->d,rsa->n,ctx);
}
static int nuron_dsa_mod_exp(DSA *dsa, BIGNUM *rr, BIGNUM *a1,
BIGNUM *p1, BIGNUM *a2, BIGNUM *p2, BIGNUM *m,
BN_CTX *ctx, BN_MONT_CTX *in_mont)
{
BIGNUM t;
int to_return = 0;
BN_init(&t);
if (!nuron_mod_exp(rr,a1,p1,m,ctx))
goto end;
if (!nuron_mod_exp(&t,a2,p2,m,ctx))
goto end;
if (!BN_mod_mul(rr,rr,&t,m,ctx))
goto end;
to_return = 1;
end:
BN_free(&t);
return to_return;
}
static int nuron_mod_exp_dsa(DSA *dsa, BIGNUM *r, BIGNUM *a,
const BIGNUM *p, const BIGNUM *m, BN_CTX *ctx,
BN_MONT_CTX *m_ctx)
{
return nuron_mod_exp(r, a, p, m, ctx);
}
static int nuron_mod_exp_mont(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *m_ctx)
{
return nuron_mod_exp(r, a, p, m, ctx);
}
static int nuron_mod_exp_dh(const DH *dh, BIGNUM *r,
const BIGNUM *a, const BIGNUM *p,
const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *m_ctx)
{
return nuron_mod_exp(r, a, p, m, ctx);
}
static int bind_helper(ENGINE *e)
{
#ifndef OPENSSL_NO_RSA
const RSA_METHOD *meth1;
#endif
#ifndef OPENSSL_NO_DSA
const DSA_METHOD *meth2;
#endif
#ifndef OPENSSL_NO_DH
const DH_METHOD *meth3;
#endif
if(!ENGINE_set_id(e, engine_nuron_id) ||
!ENGINE_set_name(e, engine_nuron_name) ||
#ifndef OPENSSL_NO_RSA
!ENGINE_set_RSA(e, &nuron_rsa) ||
#endif
#ifndef OPENSSL_NO_DSA
!ENGINE_set_DSA(e, &nuron_dsa) ||
#endif
#ifndef OPENSSL_NO_DH
!ENGINE_set_DH(e, &nuron_dh) ||
#endif
!ENGINE_set_destroy_function(e, nuron_destroy) ||
!ENGINE_set_init_function(e, nuron_init) ||
!ENGINE_set_finish_function(e, nuron_finish) ||
!ENGINE_set_ctrl_function(e, nuron_ctrl) ||
!ENGINE_set_cmd_defns(e, nuron_cmd_defns))
return 0;
#ifndef OPENSSL_NO_RSA
meth1=RSA_PKCS1_SSLeay();
nuron_rsa.rsa_pub_enc=meth1->rsa_pub_enc;
nuron_rsa.rsa_pub_dec=meth1->rsa_pub_dec;
nuron_rsa.rsa_priv_enc=meth1->rsa_priv_enc;
nuron_rsa.rsa_priv_dec=meth1->rsa_priv_dec;
#endif
#ifndef OPENSSL_NO_DSA
meth2=DSA_OpenSSL();
nuron_dsa.dsa_do_sign=meth2->dsa_do_sign;
nuron_dsa.dsa_sign_setup=meth2->dsa_sign_setup;
nuron_dsa.dsa_do_verify=meth2->dsa_do_verify;
#endif
#ifndef OPENSSL_NO_DH
meth3=DH_OpenSSL();
nuron_dh.generate_key=meth3->generate_key;
nuron_dh.compute_key=meth3->compute_key;
#endif
ERR_load_NURON_strings();
return 1;
}
static ENGINE *engine_nuron(void)
{
ENGINE *ret = ENGINE_new();
if(!ret)
return NULL;
if(!bind_helper(ret))
{
ENGINE_free(ret);
return NULL;
}
return ret;
}
void ENGINE_load_nuron(void)
{
ENGINE *toadd = engine_nuron();
if(!toadd) return;
ENGINE_add(toadd);
ENGINE_free(toadd);
ERR_clear_error();
}
static int bind_fn(ENGINE *e, const char *id)
{
if(id && (strcmp(id, engine_nuron_id) != 0))
return 0;
if(!bind_helper(e))
return 0;
return 1;
}
