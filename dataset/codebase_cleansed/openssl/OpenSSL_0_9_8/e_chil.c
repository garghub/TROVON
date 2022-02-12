static int bind_helper(ENGINE *e)
{
#ifndef OPENSSL_NO_RSA
const RSA_METHOD *meth1;
#endif
#ifndef OPENSSL_NO_DH
const DH_METHOD *meth2;
#endif
if(!ENGINE_set_id(e, engine_hwcrhk_id) ||
!ENGINE_set_name(e, engine_hwcrhk_name) ||
#ifndef OPENSSL_NO_RSA
!ENGINE_set_RSA(e, &hwcrhk_rsa) ||
#endif
#ifndef OPENSSL_NO_DH
!ENGINE_set_DH(e, &hwcrhk_dh) ||
#endif
!ENGINE_set_RAND(e, &hwcrhk_rand) ||
!ENGINE_set_destroy_function(e, hwcrhk_destroy) ||
!ENGINE_set_init_function(e, hwcrhk_init) ||
!ENGINE_set_finish_function(e, hwcrhk_finish) ||
!ENGINE_set_ctrl_function(e, hwcrhk_ctrl) ||
!ENGINE_set_load_privkey_function(e, hwcrhk_load_privkey) ||
!ENGINE_set_load_pubkey_function(e, hwcrhk_load_pubkey) ||
!ENGINE_set_cmd_defns(e, hwcrhk_cmd_defns))
return 0;
#ifndef OPENSSL_NO_RSA
meth1 = RSA_PKCS1_SSLeay();
hwcrhk_rsa.rsa_pub_enc = meth1->rsa_pub_enc;
hwcrhk_rsa.rsa_pub_dec = meth1->rsa_pub_dec;
hwcrhk_rsa.rsa_priv_enc = meth1->rsa_priv_enc;
hwcrhk_rsa.rsa_priv_dec = meth1->rsa_priv_dec;
#endif
#ifndef OPENSSL_NO_DH
meth2 = DH_OpenSSL();
hwcrhk_dh.generate_key = meth2->generate_key;
hwcrhk_dh.compute_key = meth2->compute_key;
#endif
ERR_load_HWCRHK_strings();
return 1;
}
static ENGINE *engine_chil(void)
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
void ENGINE_load_chil(void)
{
ENGINE *toadd = engine_chil();
if(!toadd) return;
ENGINE_add(toadd);
ENGINE_free(toadd);
ERR_clear_error();
}
static void free_HWCRHK_LIBNAME(void)
{
if(HWCRHK_LIBNAME)
OPENSSL_free((void*)HWCRHK_LIBNAME);
HWCRHK_LIBNAME = NULL;
}
static const char *get_HWCRHK_LIBNAME(void)
{
if(HWCRHK_LIBNAME)
return HWCRHK_LIBNAME;
return "nfhwcrhk";
}
static long set_HWCRHK_LIBNAME(const char *name)
{
free_HWCRHK_LIBNAME();
return (((HWCRHK_LIBNAME = BUF_strdup(name)) != NULL) ? 1 : 0);
}
static int get_context(HWCryptoHook_ContextHandle *hac,
HWCryptoHook_CallerContext *cac)
{
char tempbuf[1024];
HWCryptoHook_ErrMsgBuf rmsg;
rmsg.buf = tempbuf;
rmsg.size = sizeof(tempbuf);
*hac = p_hwcrhk_Init(&hwcrhk_globals, sizeof(hwcrhk_globals), &rmsg,
cac);
if (!*hac)
return 0;
return 1;
}
static void release_context(HWCryptoHook_ContextHandle hac)
{
p_hwcrhk_Finish(hac);
}
static int hwcrhk_destroy(ENGINE *e)
{
free_HWCRHK_LIBNAME();
ERR_unload_HWCRHK_strings();
return 1;
}
static int hwcrhk_init(ENGINE *e)
{
HWCryptoHook_Init_t *p1;
HWCryptoHook_Finish_t *p2;
HWCryptoHook_ModExp_t *p3;
#ifndef OPENSSL_NO_RSA
HWCryptoHook_RSA_t *p4;
HWCryptoHook_RSALoadKey_t *p5;
HWCryptoHook_RSAGetPublicKey_t *p6;
HWCryptoHook_RSAUnloadKey_t *p7;
#endif
HWCryptoHook_RandomBytes_t *p8;
HWCryptoHook_ModExpCRT_t *p9;
if(hwcrhk_dso != NULL)
{
HWCRHKerr(HWCRHK_F_HWCRHK_INIT,HWCRHK_R_ALREADY_LOADED);
goto err;
}
hwcrhk_dso = DSO_load(NULL, get_HWCRHK_LIBNAME(), NULL, 0);
if(hwcrhk_dso == NULL)
{
HWCRHKerr(HWCRHK_F_HWCRHK_INIT,HWCRHK_R_DSO_FAILURE);
goto err;
}
if(!(p1 = (HWCryptoHook_Init_t *)
DSO_bind_func(hwcrhk_dso, n_hwcrhk_Init)) ||
!(p2 = (HWCryptoHook_Finish_t *)
DSO_bind_func(hwcrhk_dso, n_hwcrhk_Finish)) ||
!(p3 = (HWCryptoHook_ModExp_t *)
DSO_bind_func(hwcrhk_dso, n_hwcrhk_ModExp)) ||
#ifndef OPENSSL_NO_RSA
!(p4 = (HWCryptoHook_RSA_t *)
DSO_bind_func(hwcrhk_dso, n_hwcrhk_RSA)) ||
!(p5 = (HWCryptoHook_RSALoadKey_t *)
DSO_bind_func(hwcrhk_dso, n_hwcrhk_RSALoadKey)) ||
!(p6 = (HWCryptoHook_RSAGetPublicKey_t *)
DSO_bind_func(hwcrhk_dso, n_hwcrhk_RSAGetPublicKey)) ||
!(p7 = (HWCryptoHook_RSAUnloadKey_t *)
DSO_bind_func(hwcrhk_dso, n_hwcrhk_RSAUnloadKey)) ||
#endif
!(p8 = (HWCryptoHook_RandomBytes_t *)
DSO_bind_func(hwcrhk_dso, n_hwcrhk_RandomBytes)) ||
!(p9 = (HWCryptoHook_ModExpCRT_t *)
DSO_bind_func(hwcrhk_dso, n_hwcrhk_ModExpCRT)))
{
HWCRHKerr(HWCRHK_F_HWCRHK_INIT,HWCRHK_R_DSO_FAILURE);
goto err;
}
p_hwcrhk_Init = p1;
p_hwcrhk_Finish = p2;
p_hwcrhk_ModExp = p3;
#ifndef OPENSSL_NO_RSA
p_hwcrhk_RSA = p4;
p_hwcrhk_RSALoadKey = p5;
p_hwcrhk_RSAGetPublicKey = p6;
p_hwcrhk_RSAUnloadKey = p7;
#endif
p_hwcrhk_RandomBytes = p8;
p_hwcrhk_ModExpCRT = p9;
if (disable_mutex_callbacks == 0)
{
if (CRYPTO_get_dynlock_create_callback() != NULL &&
CRYPTO_get_dynlock_lock_callback() != NULL &&
CRYPTO_get_dynlock_destroy_callback() != NULL)
{
hwcrhk_globals.mutex_init = hwcrhk_mutex_init;
hwcrhk_globals.mutex_acquire = hwcrhk_mutex_lock;
hwcrhk_globals.mutex_release = hwcrhk_mutex_unlock;
hwcrhk_globals.mutex_destroy = hwcrhk_mutex_destroy;
}
else if (CRYPTO_get_locking_callback() != NULL)
{
HWCRHKerr(HWCRHK_F_HWCRHK_INIT,HWCRHK_R_LOCKING_MISSING);
ERR_add_error_data(1,"You HAVE to add dynamic locking callbacks via CRYPTO_set_dynlock_{create,lock,destroy}_callback()");
goto err;
}
}
if(!get_context(&hwcrhk_context, &password_context))
{
HWCRHKerr(HWCRHK_F_HWCRHK_INIT,HWCRHK_R_UNIT_FAILURE);
goto err;
}
#ifndef OPENSSL_NO_RSA
if (hndidx_rsa == -1)
hndidx_rsa = RSA_get_ex_new_index(0,
"nFast HWCryptoHook RSA key handle",
NULL, NULL, hwcrhk_ex_free);
#endif
return 1;
err:
if(hwcrhk_dso)
DSO_free(hwcrhk_dso);
hwcrhk_dso = NULL;
p_hwcrhk_Init = NULL;
p_hwcrhk_Finish = NULL;
p_hwcrhk_ModExp = NULL;
#ifndef OPENSSL_NO_RSA
p_hwcrhk_RSA = NULL;
p_hwcrhk_RSALoadKey = NULL;
p_hwcrhk_RSAGetPublicKey = NULL;
p_hwcrhk_RSAUnloadKey = NULL;
#endif
p_hwcrhk_ModExpCRT = NULL;
p_hwcrhk_RandomBytes = NULL;
return 0;
}
static int hwcrhk_finish(ENGINE *e)
{
int to_return = 1;
free_HWCRHK_LIBNAME();
if(hwcrhk_dso == NULL)
{
HWCRHKerr(HWCRHK_F_HWCRHK_FINISH,HWCRHK_R_NOT_LOADED);
to_return = 0;
goto err;
}
release_context(hwcrhk_context);
if(!DSO_free(hwcrhk_dso))
{
HWCRHKerr(HWCRHK_F_HWCRHK_FINISH,HWCRHK_R_DSO_FAILURE);
to_return = 0;
goto err;
}
err:
if (logstream)
BIO_free(logstream);
hwcrhk_dso = NULL;
p_hwcrhk_Init = NULL;
p_hwcrhk_Finish = NULL;
p_hwcrhk_ModExp = NULL;
#ifndef OPENSSL_NO_RSA
p_hwcrhk_RSA = NULL;
p_hwcrhk_RSALoadKey = NULL;
p_hwcrhk_RSAGetPublicKey = NULL;
p_hwcrhk_RSAUnloadKey = NULL;
#endif
p_hwcrhk_ModExpCRT = NULL;
p_hwcrhk_RandomBytes = NULL;
return to_return;
}
static int hwcrhk_ctrl(ENGINE *e, int cmd, long i, void *p, void (*f)(void))
{
int to_return = 1;
switch(cmd)
{
case HWCRHK_CMD_SO_PATH:
if(hwcrhk_dso)
{
HWCRHKerr(HWCRHK_F_HWCRHK_CTRL,HWCRHK_R_ALREADY_LOADED);
return 0;
}
if(p == NULL)
{
HWCRHKerr(HWCRHK_F_HWCRHK_CTRL,ERR_R_PASSED_NULL_PARAMETER);
return 0;
}
return set_HWCRHK_LIBNAME((const char *)p);
case ENGINE_CTRL_SET_LOGSTREAM:
{
BIO *bio = (BIO *)p;
CRYPTO_w_lock(CRYPTO_LOCK_ENGINE);
if (logstream)
{
BIO_free(logstream);
logstream = NULL;
}
if (CRYPTO_add(&bio->references,1,CRYPTO_LOCK_BIO) > 1)
logstream = bio;
else
HWCRHKerr(HWCRHK_F_HWCRHK_CTRL,HWCRHK_R_BIO_WAS_FREED);
}
CRYPTO_w_unlock(CRYPTO_LOCK_ENGINE);
break;
case ENGINE_CTRL_SET_PASSWORD_CALLBACK:
CRYPTO_w_lock(CRYPTO_LOCK_ENGINE);
password_context.password_callback = (pem_password_cb *)f;
CRYPTO_w_unlock(CRYPTO_LOCK_ENGINE);
break;
case ENGINE_CTRL_SET_USER_INTERFACE:
case HWCRHK_CMD_SET_USER_INTERFACE:
CRYPTO_w_lock(CRYPTO_LOCK_ENGINE);
password_context.ui_method = (UI_METHOD *)p;
CRYPTO_w_unlock(CRYPTO_LOCK_ENGINE);
break;
case ENGINE_CTRL_SET_CALLBACK_DATA:
case HWCRHK_CMD_SET_CALLBACK_DATA:
CRYPTO_w_lock(CRYPTO_LOCK_ENGINE);
password_context.callback_data = p;
CRYPTO_w_unlock(CRYPTO_LOCK_ENGINE);
break;
case ENGINE_CTRL_CHIL_SET_FORKCHECK:
case HWCRHK_CMD_FORK_CHECK:
CRYPTO_w_lock(CRYPTO_LOCK_ENGINE);
if(i)
hwcrhk_globals.flags |=
HWCryptoHook_InitFlags_SimpleForkCheck;
else
hwcrhk_globals.flags &=
~HWCryptoHook_InitFlags_SimpleForkCheck;
CRYPTO_w_unlock(CRYPTO_LOCK_ENGINE);
break;
case ENGINE_CTRL_CHIL_NO_LOCKING:
CRYPTO_w_lock(CRYPTO_LOCK_ENGINE);
disable_mutex_callbacks = 1;
CRYPTO_w_unlock(CRYPTO_LOCK_ENGINE);
break;
case HWCRHK_CMD_THREAD_LOCKING:
CRYPTO_w_lock(CRYPTO_LOCK_ENGINE);
disable_mutex_callbacks = ((i == 0) ? 0 : 1);
CRYPTO_w_unlock(CRYPTO_LOCK_ENGINE);
break;
default:
HWCRHKerr(HWCRHK_F_HWCRHK_CTRL,
HWCRHK_R_CTRL_COMMAND_NOT_IMPLEMENTED);
to_return = 0;
break;
}
return to_return;
}
static EVP_PKEY *hwcrhk_load_privkey(ENGINE *eng, const char *key_id,
UI_METHOD *ui_method, void *callback_data)
{
#ifndef OPENSSL_NO_RSA
RSA *rtmp = NULL;
#endif
EVP_PKEY *res = NULL;
#ifndef OPENSSL_NO_RSA
HWCryptoHook_MPI e, n;
HWCryptoHook_RSAKeyHandle *hptr;
#endif
#if !defined(OPENSSL_NO_RSA)
char tempbuf[1024];
HWCryptoHook_ErrMsgBuf rmsg;
#endif
HWCryptoHook_PassphraseContext ppctx;
#if !defined(OPENSSL_NO_RSA)
rmsg.buf = tempbuf;
rmsg.size = sizeof(tempbuf);
#endif
if(!hwcrhk_context)
{
HWCRHKerr(HWCRHK_F_HWCRHK_LOAD_PRIVKEY,
HWCRHK_R_NOT_INITIALISED);
goto err;
}
#ifndef OPENSSL_NO_RSA
hptr = OPENSSL_malloc(sizeof(HWCryptoHook_RSAKeyHandle));
if (!hptr)
{
HWCRHKerr(HWCRHK_F_HWCRHK_LOAD_PRIVKEY,
ERR_R_MALLOC_FAILURE);
goto err;
}
ppctx.ui_method = ui_method;
ppctx.callback_data = callback_data;
if (p_hwcrhk_RSALoadKey(hwcrhk_context, key_id, hptr,
&rmsg, &ppctx))
{
HWCRHKerr(HWCRHK_F_HWCRHK_LOAD_PRIVKEY,
HWCRHK_R_CHIL_ERROR);
ERR_add_error_data(1,rmsg.buf);
goto err;
}
if (!*hptr)
{
HWCRHKerr(HWCRHK_F_HWCRHK_LOAD_PRIVKEY,
HWCRHK_R_NO_KEY);
goto err;
}
#endif
#ifndef OPENSSL_NO_RSA
rtmp = RSA_new_method(eng);
RSA_set_ex_data(rtmp, hndidx_rsa, (char *)hptr);
rtmp->e = BN_new();
rtmp->n = BN_new();
rtmp->flags |= RSA_FLAG_EXT_PKEY;
MPI2BN(rtmp->e, e);
MPI2BN(rtmp->n, n);
if (p_hwcrhk_RSAGetPublicKey(*hptr, &n, &e, &rmsg)
!= HWCRYPTOHOOK_ERROR_MPISIZE)
{
HWCRHKerr(HWCRHK_F_HWCRHK_LOAD_PRIVKEY,HWCRHK_R_CHIL_ERROR);
ERR_add_error_data(1,rmsg.buf);
goto err;
}
bn_expand2(rtmp->e, e.size/sizeof(BN_ULONG));
bn_expand2(rtmp->n, n.size/sizeof(BN_ULONG));
MPI2BN(rtmp->e, e);
MPI2BN(rtmp->n, n);
if (p_hwcrhk_RSAGetPublicKey(*hptr, &n, &e, &rmsg))
{
HWCRHKerr(HWCRHK_F_HWCRHK_LOAD_PRIVKEY,
HWCRHK_R_CHIL_ERROR);
ERR_add_error_data(1,rmsg.buf);
goto err;
}
rtmp->e->top = e.size / sizeof(BN_ULONG);
bn_fix_top(rtmp->e);
rtmp->n->top = n.size / sizeof(BN_ULONG);
bn_fix_top(rtmp->n);
res = EVP_PKEY_new();
EVP_PKEY_assign_RSA(res, rtmp);
#endif
if (!res)
HWCRHKerr(HWCRHK_F_HWCRHK_LOAD_PRIVKEY,
HWCRHK_R_PRIVATE_KEY_ALGORITHMS_DISABLED);
return res;
err:
if (res)
EVP_PKEY_free(res);
#ifndef OPENSSL_NO_RSA
if (rtmp)
RSA_free(rtmp);
#endif
return NULL;
}
static EVP_PKEY *hwcrhk_load_pubkey(ENGINE *eng, const char *key_id,
UI_METHOD *ui_method, void *callback_data)
{
EVP_PKEY *res = NULL;
#ifndef OPENSSL_NO_RSA
res = hwcrhk_load_privkey(eng, key_id,
ui_method, callback_data);
#endif
if (res)
switch(res->type)
{
#ifndef OPENSSL_NO_RSA
case EVP_PKEY_RSA:
{
RSA *rsa = NULL;
CRYPTO_w_lock(CRYPTO_LOCK_EVP_PKEY);
rsa = res->pkey.rsa;
res->pkey.rsa = RSA_new();
res->pkey.rsa->n = rsa->n;
res->pkey.rsa->e = rsa->e;
rsa->n = NULL;
rsa->e = NULL;
CRYPTO_w_unlock(CRYPTO_LOCK_EVP_PKEY);
RSA_free(rsa);
}
break;
#endif
default:
HWCRHKerr(HWCRHK_F_HWCRHK_LOAD_PUBKEY,
HWCRHK_R_CTRL_COMMAND_NOT_IMPLEMENTED);
goto err;
}
return res;
err:
if (res)
EVP_PKEY_free(res);
return NULL;
}
static int hwcrhk_mod_exp(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
const BIGNUM *m, BN_CTX *ctx)
{
char tempbuf[1024];
HWCryptoHook_ErrMsgBuf rmsg;
HWCryptoHook_MPI m_a, m_p, m_n, m_r;
int to_return, ret;
to_return = 0;
rmsg.buf = tempbuf;
rmsg.size = sizeof(tempbuf);
if(!hwcrhk_context)
{
HWCRHKerr(HWCRHK_F_HWCRHK_MOD_EXP,HWCRHK_R_NOT_INITIALISED);
goto err;
}
bn_expand2(r, m->top);
BN2MPI(m_a, a);
BN2MPI(m_p, p);
BN2MPI(m_n, m);
MPI2BN(r, m_r);
ret = p_hwcrhk_ModExp(hwcrhk_context, m_a, m_p, m_n, &m_r, &rmsg);
r->top = m_r.size / sizeof(BN_ULONG);
bn_fix_top(r);
if (ret < 0)
{
if(ret == HWCRYPTOHOOK_ERROR_FALLBACK)
{
HWCRHKerr(HWCRHK_F_HWCRHK_MOD_EXP,HWCRHK_R_REQUEST_FALLBACK);
}
else
{
HWCRHKerr(HWCRHK_F_HWCRHK_MOD_EXP,HWCRHK_R_REQUEST_FAILED);
}
ERR_add_error_data(1,rmsg.buf);
goto err;
}
to_return = 1;
err:
return to_return;
}
static int hwcrhk_rsa_mod_exp(BIGNUM *r, const BIGNUM *I, RSA *rsa, BN_CTX *ctx)
{
char tempbuf[1024];
HWCryptoHook_ErrMsgBuf rmsg;
HWCryptoHook_RSAKeyHandle *hptr;
int to_return = 0, ret;
rmsg.buf = tempbuf;
rmsg.size = sizeof(tempbuf);
if(!hwcrhk_context)
{
HWCRHKerr(HWCRHK_F_HWCRHK_RSA_MOD_EXP,HWCRHK_R_NOT_INITIALISED);
goto err;
}
if ((hptr = (HWCryptoHook_RSAKeyHandle *) RSA_get_ex_data(rsa, hndidx_rsa))
!= NULL)
{
HWCryptoHook_MPI m_a, m_r;
if(!rsa->n)
{
HWCRHKerr(HWCRHK_F_HWCRHK_RSA_MOD_EXP,
HWCRHK_R_MISSING_KEY_COMPONENTS);
goto err;
}
bn_expand2(r, rsa->n->top);
BN2MPI(m_a, I);
MPI2BN(r, m_r);
ret = p_hwcrhk_RSA(m_a, *hptr, &m_r, &rmsg);
r->top = m_r.size / sizeof(BN_ULONG);
bn_fix_top(r);
if (ret < 0)
{
if(ret == HWCRYPTOHOOK_ERROR_FALLBACK)
{
HWCRHKerr(HWCRHK_F_HWCRHK_RSA_MOD_EXP,
HWCRHK_R_REQUEST_FALLBACK);
}
else
{
HWCRHKerr(HWCRHK_F_HWCRHK_RSA_MOD_EXP,
HWCRHK_R_REQUEST_FAILED);
}
ERR_add_error_data(1,rmsg.buf);
goto err;
}
}
else
{
HWCryptoHook_MPI m_a, m_p, m_q, m_dmp1, m_dmq1, m_iqmp, m_r;
if(!rsa->p || !rsa->q || !rsa->dmp1 || !rsa->dmq1 || !rsa->iqmp)
{
HWCRHKerr(HWCRHK_F_HWCRHK_RSA_MOD_EXP,
HWCRHK_R_MISSING_KEY_COMPONENTS);
goto err;
}
bn_expand2(r, rsa->n->top);
BN2MPI(m_a, I);
BN2MPI(m_p, rsa->p);
BN2MPI(m_q, rsa->q);
BN2MPI(m_dmp1, rsa->dmp1);
BN2MPI(m_dmq1, rsa->dmq1);
BN2MPI(m_iqmp, rsa->iqmp);
MPI2BN(r, m_r);
ret = p_hwcrhk_ModExpCRT(hwcrhk_context, m_a, m_p, m_q,
m_dmp1, m_dmq1, m_iqmp, &m_r, &rmsg);
r->top = m_r.size / sizeof(BN_ULONG);
bn_fix_top(r);
if (ret < 0)
{
if(ret == HWCRYPTOHOOK_ERROR_FALLBACK)
{
HWCRHKerr(HWCRHK_F_HWCRHK_RSA_MOD_EXP,
HWCRHK_R_REQUEST_FALLBACK);
}
else
{
HWCRHKerr(HWCRHK_F_HWCRHK_RSA_MOD_EXP,
HWCRHK_R_REQUEST_FAILED);
}
ERR_add_error_data(1,rmsg.buf);
goto err;
}
}
to_return = 1;
err:
return to_return;
}
static int hwcrhk_mod_exp_mont(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *m_ctx)
{
return hwcrhk_mod_exp(r, a, p, m, ctx);
}
static int hwcrhk_mod_exp_dh(const DH *dh, BIGNUM *r,
const BIGNUM *a, const BIGNUM *p,
const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *m_ctx)
{
return hwcrhk_mod_exp(r, a, p, m, ctx);
}
static int hwcrhk_rand_bytes(unsigned char *buf, int num)
{
char tempbuf[1024];
HWCryptoHook_ErrMsgBuf rmsg;
int to_return = 0;
int ret;
rmsg.buf = tempbuf;
rmsg.size = sizeof(tempbuf);
if(!hwcrhk_context)
{
HWCRHKerr(HWCRHK_F_HWCRHK_RAND_BYTES,HWCRHK_R_NOT_INITIALISED);
goto err;
}
ret = p_hwcrhk_RandomBytes(hwcrhk_context, buf, num, &rmsg);
if (ret < 0)
{
if(ret == HWCRYPTOHOOK_ERROR_FALLBACK)
{
HWCRHKerr(HWCRHK_F_HWCRHK_RAND_BYTES,
HWCRHK_R_REQUEST_FALLBACK);
}
else
{
HWCRHKerr(HWCRHK_F_HWCRHK_RAND_BYTES,
HWCRHK_R_REQUEST_FAILED);
}
ERR_add_error_data(1,rmsg.buf);
goto err;
}
to_return = 1;
err:
return to_return;
}
static int hwcrhk_rand_status(void)
{
return 1;
}
static void hwcrhk_ex_free(void *obj, void *item, CRYPTO_EX_DATA *ad,
int ind,long argl, void *argp)
{
char tempbuf[1024];
HWCryptoHook_ErrMsgBuf rmsg;
#ifndef OPENSSL_NO_RSA
HWCryptoHook_RSAKeyHandle *hptr;
#endif
#if !defined(OPENSSL_NO_RSA)
int ret;
#endif
rmsg.buf = tempbuf;
rmsg.size = sizeof(tempbuf);
#ifndef OPENSSL_NO_RSA
hptr = (HWCryptoHook_RSAKeyHandle *) item;
if(hptr)
{
ret = p_hwcrhk_RSAUnloadKey(*hptr, NULL);
OPENSSL_free(hptr);
}
#endif
}
static int hwcrhk_mutex_init(HWCryptoHook_Mutex* mt,
HWCryptoHook_CallerContext *cactx)
{
mt->lockid = CRYPTO_get_new_dynlockid();
if (mt->lockid == 0)
return 1;
return 0;
}
static int hwcrhk_mutex_lock(HWCryptoHook_Mutex *mt)
{
CRYPTO_w_lock(mt->lockid);
return 0;
}
static void hwcrhk_mutex_unlock(HWCryptoHook_Mutex * mt)
{
CRYPTO_w_unlock(mt->lockid);
}
static void hwcrhk_mutex_destroy(HWCryptoHook_Mutex *mt)
{
CRYPTO_destroy_dynlockid(mt->lockid);
}
static int hwcrhk_get_pass(const char *prompt_info,
int *len_io, char *buf,
HWCryptoHook_PassphraseContext *ppctx,
HWCryptoHook_CallerContext *cactx)
{
pem_password_cb *callback = NULL;
void *callback_data = NULL;
UI_METHOD *ui_method = NULL;
if (cactx)
{
if (cactx->ui_method)
ui_method = cactx->ui_method;
if (cactx->password_callback)
callback = cactx->password_callback;
if (cactx->callback_data)
callback_data = cactx->callback_data;
}
if (ppctx)
{
if (ppctx->ui_method)
{
ui_method = ppctx->ui_method;
callback = NULL;
}
if (ppctx->callback_data)
callback_data = ppctx->callback_data;
}
if (callback == NULL && ui_method == NULL)
{
HWCRHKerr(HWCRHK_F_HWCRHK_GET_PASS,HWCRHK_R_NO_CALLBACK);
return -1;
}
if (ui_method)
{
UI *ui = UI_new_method(ui_method);
if (ui)
{
int ok;
char *prompt = UI_construct_prompt(ui,
"pass phrase", prompt_info);
ok = UI_add_input_string(ui,prompt,
UI_INPUT_FLAG_DEFAULT_PWD,
buf,0,(*len_io) - 1);
UI_add_user_data(ui, callback_data);
UI_ctrl(ui, UI_CTRL_PRINT_ERRORS, 1, 0, 0);
if (ok >= 0)
do
{
ok=UI_process(ui);
}
while (ok < 0 && UI_ctrl(ui, UI_CTRL_IS_REDOABLE, 0, 0, 0));
if (ok >= 0)
*len_io = strlen(buf);
UI_free(ui);
OPENSSL_free(prompt);
}
}
else
{
*len_io = callback(buf, *len_io, 0, callback_data);
}
if(!*len_io)
return -1;
return 0;
}
static int hwcrhk_insert_card(const char *prompt_info,
const char *wrong_info,
HWCryptoHook_PassphraseContext *ppctx,
HWCryptoHook_CallerContext *cactx)
{
int ok = -1;
UI *ui;
void *callback_data = NULL;
UI_METHOD *ui_method = NULL;
if (cactx)
{
if (cactx->ui_method)
ui_method = cactx->ui_method;
if (cactx->callback_data)
callback_data = cactx->callback_data;
}
if (ppctx)
{
if (ppctx->ui_method)
ui_method = ppctx->ui_method;
if (ppctx->callback_data)
callback_data = ppctx->callback_data;
}
if (ui_method == NULL)
{
HWCRHKerr(HWCRHK_F_HWCRHK_INSERT_CARD,
HWCRHK_R_NO_CALLBACK);
return -1;
}
ui = UI_new_method(ui_method);
if (ui)
{
char answer;
char buf[BUFSIZ];
if (wrong_info)
BIO_snprintf(buf, sizeof(buf)-1,
"Current card: \"%s\"\n", wrong_info);
ok = UI_dup_info_string(ui, buf);
if (ok >= 0 && prompt_info)
{
BIO_snprintf(buf, sizeof(buf)-1,
"Insert card \"%s\"", prompt_info);
ok = UI_dup_input_boolean(ui, buf,
"\n then hit <enter> or C<enter> to cancel\n",
"\r\n", "Cc", UI_INPUT_FLAG_ECHO, &answer);
}
UI_add_user_data(ui, callback_data);
if (ok >= 0)
ok = UI_process(ui);
UI_free(ui);
if (ok == -2 || (ok >= 0 && answer == 'C'))
ok = 1;
else if (ok < 0)
ok = -1;
else
ok = 0;
}
return ok;
}
static void hwcrhk_log_message(void *logstr, const char *message)
{
BIO *lstream = NULL;
CRYPTO_w_lock(CRYPTO_LOCK_BIO);
if (logstr)
lstream=*(BIO **)logstr;
if (lstream)
{
BIO_printf(lstream, "%s\n", message);
}
CRYPTO_w_unlock(CRYPTO_LOCK_BIO);
}
static int bind_fn(ENGINE *e, const char *id)
{
if(id && (strcmp(id, engine_hwcrhk_id) != 0) &&
(strcmp(id, engine_hwcrhk_id_alt) != 0))
return 0;
if(!bind_helper(e))
return 0;
return 1;
}
