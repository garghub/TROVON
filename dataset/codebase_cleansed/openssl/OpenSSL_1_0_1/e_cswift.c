static int bind_helper(ENGINE *e)
{
#ifndef OPENSSL_NO_RSA
const RSA_METHOD *meth1;
#endif
#ifndef OPENSSL_NO_DH
const DH_METHOD *meth2;
#endif
if(!ENGINE_set_id(e, engine_cswift_id) ||
!ENGINE_set_name(e, engine_cswift_name) ||
#ifndef OPENSSL_NO_RSA
!ENGINE_set_RSA(e, &cswift_rsa) ||
#endif
#ifndef OPENSSL_NO_DSA
!ENGINE_set_DSA(e, &cswift_dsa) ||
#endif
#ifndef OPENSSL_NO_DH
!ENGINE_set_DH(e, &cswift_dh) ||
#endif
!ENGINE_set_RAND(e, &cswift_random) ||
!ENGINE_set_destroy_function(e, cswift_destroy) ||
!ENGINE_set_init_function(e, cswift_init) ||
!ENGINE_set_finish_function(e, cswift_finish) ||
!ENGINE_set_ctrl_function(e, cswift_ctrl) ||
!ENGINE_set_cmd_defns(e, cswift_cmd_defns))
return 0;
#ifndef OPENSSL_NO_RSA
meth1 = RSA_PKCS1_SSLeay();
cswift_rsa.rsa_pub_enc = meth1->rsa_pub_enc;
cswift_rsa.rsa_pub_dec = meth1->rsa_pub_dec;
cswift_rsa.rsa_priv_enc = meth1->rsa_priv_enc;
cswift_rsa.rsa_priv_dec = meth1->rsa_priv_dec;
#endif
#ifndef OPENSSL_NO_DH
meth2 = DH_OpenSSL();
cswift_dh.generate_key = meth2->generate_key;
cswift_dh.compute_key = meth2->compute_key;
#endif
ERR_load_CSWIFT_strings();
return 1;
}
static ENGINE *engine_cswift(void)
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
void ENGINE_load_cswift(void)
{
ENGINE *toadd = engine_cswift();
if(!toadd) return;
ENGINE_add(toadd);
ENGINE_free(toadd);
ERR_clear_error();
}
static const char *get_CSWIFT_LIBNAME(void)
{
if(CSWIFT_LIBNAME)
return CSWIFT_LIBNAME;
return "swift";
}
static void free_CSWIFT_LIBNAME(void)
{
if(CSWIFT_LIBNAME)
OPENSSL_free((void*)CSWIFT_LIBNAME);
CSWIFT_LIBNAME = NULL;
}
static long set_CSWIFT_LIBNAME(const char *name)
{
free_CSWIFT_LIBNAME();
return (((CSWIFT_LIBNAME = BUF_strdup(name)) != NULL) ? 1 : 0);
}
static int get_context(SW_CONTEXT_HANDLE *hac)
{
SW_STATUS status;
status = p_CSwift_AcquireAccContext(hac);
if(status != SW_OK)
return 0;
return 1;
}
static void release_context(SW_CONTEXT_HANDLE hac)
{
p_CSwift_ReleaseAccContext(hac);
}
static int cswift_destroy(ENGINE *e)
{
free_CSWIFT_LIBNAME();
ERR_unload_CSWIFT_strings();
return 1;
}
static int cswift_init(ENGINE *e)
{
SW_CONTEXT_HANDLE hac;
t_swAcquireAccContext *p1;
t_swAttachKeyParam *p2;
t_swSimpleRequest *p3;
t_swReleaseAccContext *p4;
if(cswift_dso != NULL)
{
CSWIFTerr(CSWIFT_F_CSWIFT_INIT,CSWIFT_R_ALREADY_LOADED);
goto err;
}
cswift_dso = DSO_load(NULL, get_CSWIFT_LIBNAME(), NULL, 0);
if(cswift_dso == NULL)
{
CSWIFTerr(CSWIFT_F_CSWIFT_INIT,CSWIFT_R_NOT_LOADED);
goto err;
}
if(!(p1 = (t_swAcquireAccContext *)
DSO_bind_func(cswift_dso, CSWIFT_F1)) ||
!(p2 = (t_swAttachKeyParam *)
DSO_bind_func(cswift_dso, CSWIFT_F2)) ||
!(p3 = (t_swSimpleRequest *)
DSO_bind_func(cswift_dso, CSWIFT_F3)) ||
!(p4 = (t_swReleaseAccContext *)
DSO_bind_func(cswift_dso, CSWIFT_F4)))
{
CSWIFTerr(CSWIFT_F_CSWIFT_INIT,CSWIFT_R_NOT_LOADED);
goto err;
}
p_CSwift_AcquireAccContext = p1;
p_CSwift_AttachKeyParam = p2;
p_CSwift_SimpleRequest = p3;
p_CSwift_ReleaseAccContext = p4;
if(!get_context(&hac))
{
CSWIFTerr(CSWIFT_F_CSWIFT_INIT,CSWIFT_R_UNIT_FAILURE);
goto err;
}
release_context(hac);
return 1;
err:
if(cswift_dso)
{
DSO_free(cswift_dso);
cswift_dso = NULL;
}
p_CSwift_AcquireAccContext = NULL;
p_CSwift_AttachKeyParam = NULL;
p_CSwift_SimpleRequest = NULL;
p_CSwift_ReleaseAccContext = NULL;
return 0;
}
static int cswift_finish(ENGINE *e)
{
free_CSWIFT_LIBNAME();
if(cswift_dso == NULL)
{
CSWIFTerr(CSWIFT_F_CSWIFT_FINISH,CSWIFT_R_NOT_LOADED);
return 0;
}
if(!DSO_free(cswift_dso))
{
CSWIFTerr(CSWIFT_F_CSWIFT_FINISH,CSWIFT_R_UNIT_FAILURE);
return 0;
}
cswift_dso = NULL;
p_CSwift_AcquireAccContext = NULL;
p_CSwift_AttachKeyParam = NULL;
p_CSwift_SimpleRequest = NULL;
p_CSwift_ReleaseAccContext = NULL;
return 1;
}
static int cswift_ctrl(ENGINE *e, int cmd, long i, void *p, void (*f)(void))
{
int initialised = ((cswift_dso == NULL) ? 0 : 1);
switch(cmd)
{
case CSWIFT_CMD_SO_PATH:
if(p == NULL)
{
CSWIFTerr(CSWIFT_F_CSWIFT_CTRL,ERR_R_PASSED_NULL_PARAMETER);
return 0;
}
if(initialised)
{
CSWIFTerr(CSWIFT_F_CSWIFT_CTRL,CSWIFT_R_ALREADY_LOADED);
return 0;
}
return set_CSWIFT_LIBNAME((const char *)p);
default:
break;
}
CSWIFTerr(CSWIFT_F_CSWIFT_CTRL,CSWIFT_R_CTRL_COMMAND_NOT_IMPLEMENTED);
return 0;
}
static int cswift_mod_exp(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
const BIGNUM *m, BN_CTX *ctx)
{
BIGNUM *modulus;
BIGNUM *exponent;
BIGNUM *argument;
BIGNUM *result;
SW_STATUS sw_status;
SW_LARGENUMBER arg, res;
SW_PARAM sw_param;
SW_CONTEXT_HANDLE hac;
int to_return, acquired;
modulus = exponent = argument = result = NULL;
to_return = 0;
acquired = 0;
if(!get_context(&hac))
{
CSWIFTerr(CSWIFT_F_CSWIFT_MOD_EXP,CSWIFT_R_UNIT_FAILURE);
goto err;
}
acquired = 1;
BN_CTX_start(ctx);
modulus = BN_CTX_get(ctx);
exponent = BN_CTX_get(ctx);
argument = BN_CTX_get(ctx);
result = BN_CTX_get(ctx);
if(!result)
{
CSWIFTerr(CSWIFT_F_CSWIFT_MOD_EXP,CSWIFT_R_BN_CTX_FULL);
goto err;
}
if(!bn_wexpand(modulus, m->top) || !bn_wexpand(exponent, p->top) ||
!bn_wexpand(argument, a->top) || !bn_wexpand(result, m->top))
{
CSWIFTerr(CSWIFT_F_CSWIFT_MOD_EXP,CSWIFT_R_BN_EXPAND_FAIL);
goto err;
}
sw_param.type = SW_ALG_EXP;
sw_param.up.exp.modulus.nbytes = BN_bn2bin(m,
(unsigned char *)modulus->d);
sw_param.up.exp.modulus.value = (unsigned char *)modulus->d;
sw_param.up.exp.exponent.nbytes = BN_bn2bin(p,
(unsigned char *)exponent->d);
sw_param.up.exp.exponent.value = (unsigned char *)exponent->d;
sw_status = p_CSwift_AttachKeyParam(hac, &sw_param);
switch(sw_status)
{
case SW_OK:
break;
case SW_ERR_INPUT_SIZE:
CSWIFTerr(CSWIFT_F_CSWIFT_MOD_EXP,CSWIFT_R_BAD_KEY_SIZE);
goto err;
default:
{
char tmpbuf[DECIMAL_SIZE(sw_status)+1];
CSWIFTerr(CSWIFT_F_CSWIFT_MOD_EXP,CSWIFT_R_REQUEST_FAILED);
sprintf(tmpbuf, "%ld", sw_status);
ERR_add_error_data(2, "CryptoSwift error number is ",tmpbuf);
}
goto err;
}
arg.nbytes = BN_bn2bin(a, (unsigned char *)argument->d);
arg.value = (unsigned char *)argument->d;
res.nbytes = BN_num_bytes(m);
memset(result->d, 0, res.nbytes);
res.value = (unsigned char *)result->d;
if((sw_status = p_CSwift_SimpleRequest(hac, SW_CMD_MODEXP, &arg, 1,
&res, 1)) != SW_OK)
{
char tmpbuf[DECIMAL_SIZE(sw_status)+1];
CSWIFTerr(CSWIFT_F_CSWIFT_MOD_EXP,CSWIFT_R_REQUEST_FAILED);
sprintf(tmpbuf, "%ld", sw_status);
ERR_add_error_data(2, "CryptoSwift error number is ",tmpbuf);
goto err;
}
BN_bin2bn((unsigned char *)result->d, res.nbytes, r);
to_return = 1;
err:
if(acquired)
release_context(hac);
BN_CTX_end(ctx);
return to_return;
}
int cswift_bn_32copy(SW_LARGENUMBER * out, const BIGNUM * in)
{
int mod;
int numbytes = BN_num_bytes(in);
mod = 0;
while( ((out->nbytes = (numbytes+mod)) % 32) )
{
mod++;
}
out->value = (unsigned char*)OPENSSL_malloc(out->nbytes);
if(!out->value)
{
return 0;
}
BN_bn2bin(in, &out->value[mod]);
if(mod)
memset(out->value, 0, mod);
return 1;
}
static int cswift_mod_exp_crt(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
const BIGNUM *q, const BIGNUM *dmp1,
const BIGNUM *dmq1, const BIGNUM *iqmp, BN_CTX *ctx)
{
SW_STATUS sw_status;
SW_LARGENUMBER arg, res;
SW_PARAM sw_param;
SW_CONTEXT_HANDLE hac;
BIGNUM *result = NULL;
BIGNUM *argument = NULL;
int to_return = 0;
int acquired = 0;
sw_param.up.crt.p.value = NULL;
sw_param.up.crt.q.value = NULL;
sw_param.up.crt.dmp1.value = NULL;
sw_param.up.crt.dmq1.value = NULL;
sw_param.up.crt.iqmp.value = NULL;
if(!get_context(&hac))
{
CSWIFTerr(CSWIFT_F_CSWIFT_MOD_EXP_CRT,CSWIFT_R_UNIT_FAILURE);
goto err;
}
acquired = 1;
argument = BN_new();
result = BN_new();
if(!result || !argument)
{
CSWIFTerr(CSWIFT_F_CSWIFT_MOD_EXP_CRT,CSWIFT_R_BN_CTX_FULL);
goto err;
}
sw_param.type = SW_ALG_CRT;
if(!cswift_bn_32copy(&sw_param.up.crt.p, p))
{
CSWIFTerr(CSWIFT_F_CSWIFT_MOD_EXP_CRT,CSWIFT_R_BN_EXPAND_FAIL);
goto err;
}
if(!cswift_bn_32copy(&sw_param.up.crt.q, q))
{
CSWIFTerr(CSWIFT_F_CSWIFT_MOD_EXP_CRT,CSWIFT_R_BN_EXPAND_FAIL);
goto err;
}
if(!cswift_bn_32copy(&sw_param.up.crt.dmp1, dmp1))
{
CSWIFTerr(CSWIFT_F_CSWIFT_MOD_EXP_CRT,CSWIFT_R_BN_EXPAND_FAIL);
goto err;
}
if(!cswift_bn_32copy(&sw_param.up.crt.dmq1, dmq1))
{
CSWIFTerr(CSWIFT_F_CSWIFT_MOD_EXP_CRT,CSWIFT_R_BN_EXPAND_FAIL);
goto err;
}
if(!cswift_bn_32copy(&sw_param.up.crt.iqmp, iqmp))
{
CSWIFTerr(CSWIFT_F_CSWIFT_MOD_EXP_CRT,CSWIFT_R_BN_EXPAND_FAIL);
goto err;
}
if( !bn_wexpand(argument, a->top) ||
!bn_wexpand(result, p->top + q->top))
{
CSWIFTerr(CSWIFT_F_CSWIFT_MOD_EXP_CRT,CSWIFT_R_BN_EXPAND_FAIL);
goto err;
}
sw_status = p_CSwift_AttachKeyParam(hac, &sw_param);
switch(sw_status)
{
case SW_OK:
break;
case SW_ERR_INPUT_SIZE:
CSWIFTerr(CSWIFT_F_CSWIFT_MOD_EXP_CRT,CSWIFT_R_BAD_KEY_SIZE);
goto err;
default:
{
char tmpbuf[DECIMAL_SIZE(sw_status)+1];
CSWIFTerr(CSWIFT_F_CSWIFT_MOD_EXP_CRT,CSWIFT_R_REQUEST_FAILED);
sprintf(tmpbuf, "%ld", sw_status);
ERR_add_error_data(2, "CryptoSwift error number is ",tmpbuf);
}
goto err;
}
arg.nbytes = BN_bn2bin(a, (unsigned char *)argument->d);
arg.value = (unsigned char *)argument->d;
res.nbytes = 2 * BN_num_bytes(p);
memset(result->d, 0, res.nbytes);
res.value = (unsigned char *)result->d;
if((sw_status = p_CSwift_SimpleRequest(hac, SW_CMD_MODEXP_CRT, &arg, 1,
&res, 1)) != SW_OK)
{
char tmpbuf[DECIMAL_SIZE(sw_status)+1];
CSWIFTerr(CSWIFT_F_CSWIFT_MOD_EXP_CRT,CSWIFT_R_REQUEST_FAILED);
sprintf(tmpbuf, "%ld", sw_status);
ERR_add_error_data(2, "CryptoSwift error number is ",tmpbuf);
goto err;
}
BN_bin2bn((unsigned char *)result->d, res.nbytes, r);
to_return = 1;
err:
if(sw_param.up.crt.p.value)
OPENSSL_free(sw_param.up.crt.p.value);
if(sw_param.up.crt.q.value)
OPENSSL_free(sw_param.up.crt.q.value);
if(sw_param.up.crt.dmp1.value)
OPENSSL_free(sw_param.up.crt.dmp1.value);
if(sw_param.up.crt.dmq1.value)
OPENSSL_free(sw_param.up.crt.dmq1.value);
if(sw_param.up.crt.iqmp.value)
OPENSSL_free(sw_param.up.crt.iqmp.value);
if(result)
BN_free(result);
if(argument)
BN_free(argument);
if(acquired)
release_context(hac);
return to_return;
}
static int cswift_rsa_mod_exp(BIGNUM *r0, const BIGNUM *I, RSA *rsa, BN_CTX *ctx)
{
int to_return = 0;
const RSA_METHOD * def_rsa_method;
if(!rsa->p || !rsa->q || !rsa->dmp1 || !rsa->dmq1 || !rsa->iqmp)
{
CSWIFTerr(CSWIFT_F_CSWIFT_RSA_MOD_EXP,CSWIFT_R_MISSING_KEY_COMPONENTS);
goto err;
}
if(BN_num_bytes(rsa->p) > 128 ||
BN_num_bytes(rsa->q) > 128 ||
BN_num_bytes(rsa->dmp1) > 128 ||
BN_num_bytes(rsa->dmq1) > 128 ||
BN_num_bytes(rsa->iqmp) > 128)
{
#ifdef RSA_NULL
def_rsa_method=RSA_null_method();
#else
#if 0
def_rsa_method=RSA_PKCS1_RSAref();
#else
def_rsa_method=RSA_PKCS1_SSLeay();
#endif
#endif
if(def_rsa_method)
return def_rsa_method->rsa_mod_exp(r0, I, rsa, ctx);
}
to_return = cswift_mod_exp_crt(r0, I, rsa->p, rsa->q, rsa->dmp1,
rsa->dmq1, rsa->iqmp, ctx);
err:
return to_return;
}
static int cswift_mod_exp_mont(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *m_ctx)
{
const RSA_METHOD * def_rsa_method;
if(BN_num_bytes(r) > 256 ||
BN_num_bytes(a) > 256 ||
BN_num_bytes(m) > 256)
{
#ifdef RSA_NULL
def_rsa_method=RSA_null_method();
#else
#if 0
def_rsa_method=RSA_PKCS1_RSAref();
#else
def_rsa_method=RSA_PKCS1_SSLeay();
#endif
#endif
if(def_rsa_method)
return def_rsa_method->bn_mod_exp(r, a, p, m, ctx, m_ctx);
}
return cswift_mod_exp(r, a, p, m, ctx);
}
static DSA_SIG *cswift_dsa_sign(const unsigned char *dgst, int dlen, DSA *dsa)
{
SW_CONTEXT_HANDLE hac;
SW_PARAM sw_param;
SW_STATUS sw_status;
SW_LARGENUMBER arg, res;
BN_CTX *ctx;
BIGNUM *dsa_p = NULL;
BIGNUM *dsa_q = NULL;
BIGNUM *dsa_g = NULL;
BIGNUM *dsa_key = NULL;
BIGNUM *result = NULL;
DSA_SIG *to_return = NULL;
int acquired = 0;
if((ctx = BN_CTX_new()) == NULL)
goto err;
if(!get_context(&hac))
{
CSWIFTerr(CSWIFT_F_CSWIFT_DSA_SIGN,CSWIFT_R_UNIT_FAILURE);
goto err;
}
acquired = 1;
BN_CTX_start(ctx);
dsa_p = BN_CTX_get(ctx);
dsa_q = BN_CTX_get(ctx);
dsa_g = BN_CTX_get(ctx);
dsa_key = BN_CTX_get(ctx);
result = BN_CTX_get(ctx);
if(!result)
{
CSWIFTerr(CSWIFT_F_CSWIFT_DSA_SIGN,CSWIFT_R_BN_CTX_FULL);
goto err;
}
if(!bn_wexpand(dsa_p, dsa->p->top) ||
!bn_wexpand(dsa_q, dsa->q->top) ||
!bn_wexpand(dsa_g, dsa->g->top) ||
!bn_wexpand(dsa_key, dsa->priv_key->top) ||
!bn_wexpand(result, dsa->p->top))
{
CSWIFTerr(CSWIFT_F_CSWIFT_DSA_SIGN,CSWIFT_R_BN_EXPAND_FAIL);
goto err;
}
sw_param.type = SW_ALG_DSA;
sw_param.up.dsa.p.nbytes = BN_bn2bin(dsa->p,
(unsigned char *)dsa_p->d);
sw_param.up.dsa.p.value = (unsigned char *)dsa_p->d;
sw_param.up.dsa.q.nbytes = BN_bn2bin(dsa->q,
(unsigned char *)dsa_q->d);
sw_param.up.dsa.q.value = (unsigned char *)dsa_q->d;
sw_param.up.dsa.g.nbytes = BN_bn2bin(dsa->g,
(unsigned char *)dsa_g->d);
sw_param.up.dsa.g.value = (unsigned char *)dsa_g->d;
sw_param.up.dsa.key.nbytes = BN_bn2bin(dsa->priv_key,
(unsigned char *)dsa_key->d);
sw_param.up.dsa.key.value = (unsigned char *)dsa_key->d;
sw_status = p_CSwift_AttachKeyParam(hac, &sw_param);
switch(sw_status)
{
case SW_OK:
break;
case SW_ERR_INPUT_SIZE:
CSWIFTerr(CSWIFT_F_CSWIFT_DSA_SIGN,CSWIFT_R_BAD_KEY_SIZE);
goto err;
default:
{
char tmpbuf[DECIMAL_SIZE(sw_status)+1];
CSWIFTerr(CSWIFT_F_CSWIFT_DSA_SIGN,CSWIFT_R_REQUEST_FAILED);
sprintf(tmpbuf, "%ld", sw_status);
ERR_add_error_data(2, "CryptoSwift error number is ",tmpbuf);
}
goto err;
}
arg.nbytes = dlen;
arg.value = (unsigned char *)dgst;
res.nbytes = BN_num_bytes(dsa->p);
memset(result->d, 0, res.nbytes);
res.value = (unsigned char *)result->d;
sw_status = p_CSwift_SimpleRequest(hac, SW_CMD_DSS_SIGN, &arg, 1,
&res, 1);
if(sw_status != SW_OK)
{
char tmpbuf[DECIMAL_SIZE(sw_status)+1];
CSWIFTerr(CSWIFT_F_CSWIFT_DSA_SIGN,CSWIFT_R_REQUEST_FAILED);
sprintf(tmpbuf, "%ld", sw_status);
ERR_add_error_data(2, "CryptoSwift error number is ",tmpbuf);
goto err;
}
if((to_return = DSA_SIG_new()) == NULL)
goto err;
to_return->r = BN_bin2bn((unsigned char *)result->d, 20, NULL);
to_return->s = BN_bin2bn((unsigned char *)result->d + 20, 20, NULL);
err:
if(acquired)
release_context(hac);
if(ctx)
{
BN_CTX_end(ctx);
BN_CTX_free(ctx);
}
return to_return;
}
static int cswift_dsa_verify(const unsigned char *dgst, int dgst_len,
DSA_SIG *sig, DSA *dsa)
{
SW_CONTEXT_HANDLE hac;
SW_PARAM sw_param;
SW_STATUS sw_status;
SW_LARGENUMBER arg[2], res;
unsigned long sig_result;
BN_CTX *ctx;
BIGNUM *dsa_p = NULL;
BIGNUM *dsa_q = NULL;
BIGNUM *dsa_g = NULL;
BIGNUM *dsa_key = NULL;
BIGNUM *argument = NULL;
int to_return = -1;
int acquired = 0;
if((ctx = BN_CTX_new()) == NULL)
goto err;
if(!get_context(&hac))
{
CSWIFTerr(CSWIFT_F_CSWIFT_DSA_VERIFY,CSWIFT_R_UNIT_FAILURE);
goto err;
}
acquired = 1;
BN_CTX_start(ctx);
dsa_p = BN_CTX_get(ctx);
dsa_q = BN_CTX_get(ctx);
dsa_g = BN_CTX_get(ctx);
dsa_key = BN_CTX_get(ctx);
argument = BN_CTX_get(ctx);
if(!argument)
{
CSWIFTerr(CSWIFT_F_CSWIFT_DSA_VERIFY,CSWIFT_R_BN_CTX_FULL);
goto err;
}
if(!bn_wexpand(dsa_p, dsa->p->top) ||
!bn_wexpand(dsa_q, dsa->q->top) ||
!bn_wexpand(dsa_g, dsa->g->top) ||
!bn_wexpand(dsa_key, dsa->pub_key->top) ||
!bn_wexpand(argument, 40))
{
CSWIFTerr(CSWIFT_F_CSWIFT_DSA_VERIFY,CSWIFT_R_BN_EXPAND_FAIL);
goto err;
}
sw_param.type = SW_ALG_DSA;
sw_param.up.dsa.p.nbytes = BN_bn2bin(dsa->p,
(unsigned char *)dsa_p->d);
sw_param.up.dsa.p.value = (unsigned char *)dsa_p->d;
sw_param.up.dsa.q.nbytes = BN_bn2bin(dsa->q,
(unsigned char *)dsa_q->d);
sw_param.up.dsa.q.value = (unsigned char *)dsa_q->d;
sw_param.up.dsa.g.nbytes = BN_bn2bin(dsa->g,
(unsigned char *)dsa_g->d);
sw_param.up.dsa.g.value = (unsigned char *)dsa_g->d;
sw_param.up.dsa.key.nbytes = BN_bn2bin(dsa->pub_key,
(unsigned char *)dsa_key->d);
sw_param.up.dsa.key.value = (unsigned char *)dsa_key->d;
sw_status = p_CSwift_AttachKeyParam(hac, &sw_param);
switch(sw_status)
{
case SW_OK:
break;
case SW_ERR_INPUT_SIZE:
CSWIFTerr(CSWIFT_F_CSWIFT_DSA_VERIFY,CSWIFT_R_BAD_KEY_SIZE);
goto err;
default:
{
char tmpbuf[DECIMAL_SIZE(sw_status)+1];
CSWIFTerr(CSWIFT_F_CSWIFT_DSA_VERIFY,CSWIFT_R_REQUEST_FAILED);
sprintf(tmpbuf, "%ld", sw_status);
ERR_add_error_data(2, "CryptoSwift error number is ",tmpbuf);
}
goto err;
}
arg[0].nbytes = dgst_len;
arg[0].value = (unsigned char *)dgst;
arg[1].nbytes = 40;
arg[1].value = (unsigned char *)argument->d;
memset(arg[1].value, 0, 40);
BN_bn2bin(sig->r, arg[1].value + 20 - BN_num_bytes(sig->r));
BN_bn2bin(sig->s, arg[1].value + 40 - BN_num_bytes(sig->s));
res.nbytes = 4;
res.value = (unsigned char *)(&sig_result);
sw_status = p_CSwift_SimpleRequest(hac, SW_CMD_DSS_VERIFY, arg, 2,
&res, 1);
if(sw_status != SW_OK)
{
char tmpbuf[DECIMAL_SIZE(sw_status)+1];
CSWIFTerr(CSWIFT_F_CSWIFT_DSA_VERIFY,CSWIFT_R_REQUEST_FAILED);
sprintf(tmpbuf, "%ld", sw_status);
ERR_add_error_data(2, "CryptoSwift error number is ",tmpbuf);
goto err;
}
to_return = ((sig_result == 0) ? 0 : 1);
err:
if(acquired)
release_context(hac);
if(ctx)
{
BN_CTX_end(ctx);
BN_CTX_free(ctx);
}
return to_return;
}
static int cswift_mod_exp_dh(const DH *dh, BIGNUM *r,
const BIGNUM *a, const BIGNUM *p,
const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *m_ctx)
{
return cswift_mod_exp(r, a, p, m, ctx);
}
static int cswift_rand_bytes(unsigned char *buf, int num)
{
SW_CONTEXT_HANDLE hac;
SW_STATUS swrc;
SW_LARGENUMBER largenum;
int acquired = 0;
int to_return = 0;
unsigned char buf32[1024];
if (!get_context(&hac))
{
CSWIFTerr(CSWIFT_F_CSWIFT_RAND_BYTES, CSWIFT_R_UNIT_FAILURE);
goto err;
}
acquired = 1;
while(num >= (int)sizeof(buf32))
{
largenum.value = buf;
largenum.nbytes = sizeof(buf32);
swrc = p_CSwift_SimpleRequest(hac, SW_CMD_RAND, NULL, 0, &largenum, 1);
if (swrc != SW_OK)
{
char tmpbuf[20];
CSWIFTerr(CSWIFT_F_CSWIFT_RAND_BYTES, CSWIFT_R_REQUEST_FAILED);
sprintf(tmpbuf, "%ld", swrc);
ERR_add_error_data(2, "CryptoSwift error number is ", tmpbuf);
goto err;
}
buf += sizeof(buf32);
num -= sizeof(buf32);
}
if(num)
{
largenum.nbytes = sizeof(buf32);
largenum.value = buf32;
swrc = p_CSwift_SimpleRequest(hac, SW_CMD_RAND, NULL, 0, &largenum, 1);
if (swrc != SW_OK)
{
char tmpbuf[20];
CSWIFTerr(CSWIFT_F_CSWIFT_RAND_BYTES, CSWIFT_R_REQUEST_FAILED);
sprintf(tmpbuf, "%ld", swrc);
ERR_add_error_data(2, "CryptoSwift error number is ", tmpbuf);
goto err;
}
memcpy(buf, largenum.value, num);
}
to_return = 1;
err:
if (acquired)
release_context(hac);
return to_return;
}
static int cswift_rand_status(void)
{
return 1;
}
static int bind_fn(ENGINE *e, const char *id)
{
if(id && (strcmp(id, engine_cswift_id) != 0))
return 0;
if(!bind_helper(e))
return 0;
return 1;
}
