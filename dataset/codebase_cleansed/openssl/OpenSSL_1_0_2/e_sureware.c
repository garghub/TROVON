static int surewarehk_mod_exp_mont(BIGNUM *r, const BIGNUM *a,
const BIGNUM *p, const BIGNUM *m,
BN_CTX *ctx, BN_MONT_CTX *m_ctx)
{
return surewarehk_modexp(r, a, p, m, ctx);
}
static int surewarehk_modexp_dh(const DH *dh, BIGNUM *r, const BIGNUM *a,
const BIGNUM *p, const BIGNUM *m, BN_CTX *ctx,
BN_MONT_CTX *m_ctx)
{
return surewarehk_modexp(r, a, p, m, ctx);
}
static int surewarehk_dsa_mod_exp(DSA *dsa, BIGNUM *rr, BIGNUM *a1,
BIGNUM *p1, BIGNUM *a2, BIGNUM *p2,
BIGNUM *m, BN_CTX *ctx,
BN_MONT_CTX *in_mont)
{
BIGNUM t;
int to_return = 0;
BN_init(&t);
if (!surewarehk_modexp(rr, a1, p1, m, ctx))
goto end;
if (!surewarehk_modexp(&t, a2, p2, m, ctx))
goto end;
if (!BN_mod_mul(rr, rr, &t, m, ctx))
goto end;
to_return = 1;
end:
BN_free(&t);
return to_return;
}
static int bind_sureware(ENGINE *e)
{
# ifndef OPENSSL_NO_RSA
const RSA_METHOD *meth1;
# endif
# ifndef OPENSSL_NO_DSA
const DSA_METHOD *meth2;
# endif
# ifndef OPENSSL_NO_DH
const DH_METHOD *meth3;
# endif
if (!ENGINE_set_id(e, engine_sureware_id) ||
!ENGINE_set_name(e, engine_sureware_name) ||
# ifndef OPENSSL_NO_RSA
!ENGINE_set_RSA(e, &surewarehk_rsa) ||
# endif
# ifndef OPENSSL_NO_DSA
!ENGINE_set_DSA(e, &surewarehk_dsa) ||
# endif
# ifndef OPENSSL_NO_DH
!ENGINE_set_DH(e, &surewarehk_dh) ||
# endif
!ENGINE_set_RAND(e, &surewarehk_rand) ||
!ENGINE_set_destroy_function(e, surewarehk_destroy) ||
!ENGINE_set_init_function(e, surewarehk_init) ||
!ENGINE_set_finish_function(e, surewarehk_finish) ||
!ENGINE_set_ctrl_function(e, surewarehk_ctrl) ||
!ENGINE_set_load_privkey_function(e, surewarehk_load_privkey) ||
!ENGINE_set_load_pubkey_function(e, surewarehk_load_pubkey))
return 0;
# ifndef OPENSSL_NO_RSA
meth1 = RSA_PKCS1_SSLeay();
if (meth1) {
surewarehk_rsa.rsa_pub_enc = meth1->rsa_pub_enc;
surewarehk_rsa.rsa_pub_dec = meth1->rsa_pub_dec;
}
# endif
# ifndef OPENSSL_NO_DSA
meth2 = DSA_OpenSSL();
if (meth2) {
surewarehk_dsa.dsa_do_verify = meth2->dsa_do_verify;
}
# endif
# ifndef OPENSSL_NO_DH
meth3 = DH_OpenSSL();
if (meth3) {
surewarehk_dh.generate_key = meth3->generate_key;
surewarehk_dh.compute_key = meth3->compute_key;
}
# endif
ERR_load_SUREWARE_strings();
return 1;
}
static int bind_helper(ENGINE *e, const char *id)
{
if (id && (strcmp(id, engine_sureware_id) != 0))
return 0;
if (!bind_sureware(e))
return 0;
return 1;
}
static ENGINE *engine_sureware(void)
{
ENGINE *ret = ENGINE_new();
if (!ret)
return NULL;
if (!bind_sureware(ret)) {
ENGINE_free(ret);
return NULL;
}
return ret;
}
void ENGINE_load_sureware(void)
{
ENGINE *toadd = engine_sureware();
if (!toadd)
return;
ENGINE_add(toadd);
ENGINE_free(toadd);
ERR_clear_error();
}
static int surewarehk_ctrl(ENGINE *e, int cmd, long i, void *p,
void (*f) (void))
{
int to_return = 1;
switch (cmd) {
case ENGINE_CTRL_SET_LOGSTREAM:
{
BIO *bio = (BIO *)p;
CRYPTO_w_lock(CRYPTO_LOCK_ENGINE);
if (logstream) {
BIO_free(logstream);
logstream = NULL;
}
if (CRYPTO_add(&bio->references, 1, CRYPTO_LOCK_BIO) > 1)
logstream = bio;
else
SUREWAREerr(SUREWARE_F_SUREWAREHK_CTRL,
SUREWARE_R_BIO_WAS_FREED);
}
CRYPTO_w_unlock(CRYPTO_LOCK_ENGINE);
break;
case ENGINE_CTRL_CHIL_NO_LOCKING:
CRYPTO_w_lock(CRYPTO_LOCK_ENGINE);
threadsafe = 0;
CRYPTO_w_unlock(CRYPTO_LOCK_ENGINE);
break;
default:
SUREWAREerr(SUREWARE_F_SUREWAREHK_CTRL,
ENGINE_R_CTRL_COMMAND_NOT_IMPLEMENTED);
to_return = 0;
break;
}
return to_return;
}
static int surewarehk_destroy(ENGINE *e)
{
ERR_unload_SUREWARE_strings();
return 1;
}
static int surewarehk_init(ENGINE *e)
{
char msg[64] = "ENGINE_init";
SureWareHook_Init_t *p1 = NULL;
SureWareHook_Finish_t *p2 = NULL;
SureWareHook_Rand_Bytes_t *p3 = NULL;
SureWareHook_Rand_Seed_t *p4 = NULL;
SureWareHook_Load_Privkey_t *p5 = NULL;
SureWareHook_Load_Rsa_Pubkey_t *p6 = NULL;
SureWareHook_Free_t *p7 = NULL;
SureWareHook_Rsa_Priv_Dec_t *p8 = NULL;
SureWareHook_Rsa_Sign_t *p9 = NULL;
SureWareHook_Dsa_Sign_t *p12 = NULL;
SureWareHook_Info_Pubkey_t *p13 = NULL;
SureWareHook_Load_Dsa_Pubkey_t *p14 = NULL;
SureWareHook_Mod_Exp_t *p15 = NULL;
if (surewarehk_dso != NULL) {
SUREWAREerr(SUREWARE_F_SUREWAREHK_INIT, ENGINE_R_ALREADY_LOADED);
goto err;
}
surewarehk_dso = DSO_load(NULL, surewarehk_LIBNAME, NULL, 0);
if (surewarehk_dso == NULL) {
SUREWAREerr(SUREWARE_F_SUREWAREHK_INIT, ENGINE_R_DSO_FAILURE);
goto err;
}
if (!
(p1 =
(SureWareHook_Init_t *) DSO_bind_func(surewarehk_dso,
n_surewarehk_Init))
|| !(p2 =
(SureWareHook_Finish_t *) DSO_bind_func(surewarehk_dso,
n_surewarehk_Finish))
|| !(p3 =
(SureWareHook_Rand_Bytes_t *) DSO_bind_func(surewarehk_dso,
n_surewarehk_Rand_Bytes))
|| !(p4 =
(SureWareHook_Rand_Seed_t *) DSO_bind_func(surewarehk_dso,
n_surewarehk_Rand_Seed))
|| !(p5 =
(SureWareHook_Load_Privkey_t *) DSO_bind_func(surewarehk_dso,
n_surewarehk_Load_Privkey))
|| !(p6 =
(SureWareHook_Load_Rsa_Pubkey_t *) DSO_bind_func(surewarehk_dso,
n_surewarehk_Load_Rsa_Pubkey))
|| !(p7 =
(SureWareHook_Free_t *) DSO_bind_func(surewarehk_dso, n_surewarehk_Free))
|| !(p8 =
(SureWareHook_Rsa_Priv_Dec_t *) DSO_bind_func(surewarehk_dso,
n_surewarehk_Rsa_Priv_Dec))
|| !(p9 =
(SureWareHook_Rsa_Sign_t *) DSO_bind_func(surewarehk_dso,
n_surewarehk_Rsa_Sign))
|| !(p12 =
(SureWareHook_Dsa_Sign_t *) DSO_bind_func(surewarehk_dso,
n_surewarehk_Dsa_Sign))
|| !(p13 =
(SureWareHook_Info_Pubkey_t *) DSO_bind_func(surewarehk_dso,
n_surewarehk_Info_Pubkey))
|| !(p14 =
(SureWareHook_Load_Dsa_Pubkey_t *) DSO_bind_func(surewarehk_dso,
n_surewarehk_Load_Dsa_Pubkey))
|| !(p15 =
(SureWareHook_Mod_Exp_t *) DSO_bind_func(surewarehk_dso,
n_surewarehk_Mod_Exp))) {
SUREWAREerr(SUREWARE_F_SUREWAREHK_INIT, ENGINE_R_DSO_FAILURE);
goto err;
}
p_surewarehk_Init = p1;
p_surewarehk_Finish = p2;
p_surewarehk_Rand_Bytes = p3;
p_surewarehk_Rand_Seed = p4;
p_surewarehk_Load_Privkey = p5;
p_surewarehk_Load_Rsa_Pubkey = p6;
p_surewarehk_Free = p7;
p_surewarehk_Rsa_Priv_Dec = p8;
p_surewarehk_Rsa_Sign = p9;
p_surewarehk_Dsa_Sign = p12;
p_surewarehk_Info_Pubkey = p13;
p_surewarehk_Load_Dsa_Pubkey = p14;
p_surewarehk_Mod_Exp = p15;
if (p_surewarehk_Init(msg, threadsafe) == SUREWAREHOOK_ERROR_UNIT_FAILURE) {
SUREWAREerr(SUREWARE_F_SUREWAREHK_INIT, SUREWARE_R_UNIT_FAILURE);
goto err;
}
if (p_surewarehk_Init(msg, threadsafe) == SUREWAREHOOK_ERROR_UNIT_FAILURE) {
SUREWAREerr(SUREWARE_F_SUREWAREHK_INIT, SUREWARE_R_UNIT_FAILURE);
goto err;
}
surewarehk_load_privkey(e, NULL, NULL, NULL);
# ifndef OPENSSL_NO_RSA
if (rsaHndidx == -1)
rsaHndidx = RSA_get_ex_new_index(0,
"SureWareHook RSA key handle",
NULL, NULL, surewarehk_ex_free);
# endif
# ifndef OPENSSL_NO_DSA
if (dsaHndidx == -1)
dsaHndidx = DSA_get_ex_new_index(0,
"SureWareHook DSA key handle",
NULL, NULL, surewarehk_ex_free);
# endif
return 1;
err:
if (surewarehk_dso)
DSO_free(surewarehk_dso);
surewarehk_dso = NULL;
p_surewarehk_Init = NULL;
p_surewarehk_Finish = NULL;
p_surewarehk_Rand_Bytes = NULL;
p_surewarehk_Rand_Seed = NULL;
p_surewarehk_Load_Privkey = NULL;
p_surewarehk_Load_Rsa_Pubkey = NULL;
p_surewarehk_Free = NULL;
p_surewarehk_Rsa_Priv_Dec = NULL;
p_surewarehk_Rsa_Sign = NULL;
p_surewarehk_Dsa_Sign = NULL;
p_surewarehk_Info_Pubkey = NULL;
p_surewarehk_Load_Dsa_Pubkey = NULL;
p_surewarehk_Mod_Exp = NULL;
return 0;
}
static int surewarehk_finish(ENGINE *e)
{
int to_return = 1;
if (surewarehk_dso == NULL) {
SUREWAREerr(SUREWARE_F_SUREWAREHK_FINISH, ENGINE_R_NOT_LOADED);
to_return = 0;
goto err;
}
p_surewarehk_Finish();
if (!DSO_free(surewarehk_dso)) {
SUREWAREerr(SUREWARE_F_SUREWAREHK_FINISH, ENGINE_R_DSO_FAILURE);
to_return = 0;
goto err;
}
err:
if (logstream)
BIO_free(logstream);
surewarehk_dso = NULL;
p_surewarehk_Init = NULL;
p_surewarehk_Finish = NULL;
p_surewarehk_Rand_Bytes = NULL;
p_surewarehk_Rand_Seed = NULL;
p_surewarehk_Load_Privkey = NULL;
p_surewarehk_Load_Rsa_Pubkey = NULL;
p_surewarehk_Free = NULL;
p_surewarehk_Rsa_Priv_Dec = NULL;
p_surewarehk_Rsa_Sign = NULL;
p_surewarehk_Dsa_Sign = NULL;
p_surewarehk_Info_Pubkey = NULL;
p_surewarehk_Load_Dsa_Pubkey = NULL;
p_surewarehk_Mod_Exp = NULL;
return to_return;
}
static void surewarehk_error_handling(char *const msg, int func, int ret)
{
switch (ret) {
case SUREWAREHOOK_ERROR_UNIT_FAILURE:
ENGINEerr(func, SUREWARE_R_UNIT_FAILURE);
break;
case SUREWAREHOOK_ERROR_FALLBACK:
ENGINEerr(func, SUREWARE_R_REQUEST_FALLBACK);
break;
case SUREWAREHOOK_ERROR_DATA_SIZE:
ENGINEerr(func, SUREWARE_R_SIZE_TOO_LARGE_OR_TOO_SMALL);
break;
case SUREWAREHOOK_ERROR_INVALID_PAD:
ENGINEerr(func, SUREWARE_R_PADDING_CHECK_FAILED);
break;
default:
ENGINEerr(func, SUREWARE_R_REQUEST_FAILED);
break;
case 1:
msg[0] = '\0';
}
if (*msg) {
ERR_add_error_data(1, msg);
if (logstream) {
CRYPTO_w_lock(CRYPTO_LOCK_BIO);
BIO_write(logstream, msg, strlen(msg));
CRYPTO_w_unlock(CRYPTO_LOCK_BIO);
}
}
}
static int surewarehk_rand_bytes(unsigned char *buf, int num)
{
int ret = 0;
char msg[64] = "ENGINE_rand_bytes";
if (!p_surewarehk_Rand_Bytes) {
SUREWAREerr(SUREWARE_F_SUREWAREHK_RAND_BYTES,
ENGINE_R_NOT_INITIALISED);
} else {
ret = p_surewarehk_Rand_Bytes(msg, buf, num);
surewarehk_error_handling(msg, SUREWARE_F_SUREWAREHK_RAND_BYTES, ret);
}
return ret == 1 ? 1 : 0;
}
static void surewarehk_rand_seed(const void *buf, int num)
{
int ret = 0;
char msg[64] = "ENGINE_rand_seed";
if (!p_surewarehk_Rand_Seed) {
SUREWAREerr(SUREWARE_F_SUREWAREHK_RAND_SEED,
ENGINE_R_NOT_INITIALISED);
} else {
ret = p_surewarehk_Rand_Seed(msg, buf, num);
surewarehk_error_handling(msg, SUREWARE_F_SUREWAREHK_RAND_SEED, ret);
}
}
static void surewarehk_rand_add(const void *buf, int num, double entropy)
{
surewarehk_rand_seed(buf, num);
}
static EVP_PKEY *sureware_load_public(ENGINE *e, const char *key_id,
char *hptr, unsigned long el,
char keytype)
{
EVP_PKEY *res = NULL;
# ifndef OPENSSL_NO_RSA
RSA *rsatmp = NULL;
# endif
# ifndef OPENSSL_NO_DSA
DSA *dsatmp = NULL;
# endif
char msg[64] = "sureware_load_public";
int ret = 0;
if (!p_surewarehk_Load_Rsa_Pubkey || !p_surewarehk_Load_Dsa_Pubkey) {
SUREWAREerr(SUREWARE_F_SUREWARE_LOAD_PUBLIC,
ENGINE_R_NOT_INITIALISED);
goto err;
}
switch (keytype) {
# ifndef OPENSSL_NO_RSA
case 1:
rsatmp = RSA_new_method(e);
RSA_set_ex_data(rsatmp, rsaHndidx, hptr);
rsatmp->flags |= RSA_FLAG_EXT_PKEY;
rsatmp->e = BN_new();
rsatmp->n = BN_new();
bn_expand2(rsatmp->e, el / sizeof(BN_ULONG));
bn_expand2(rsatmp->n, el / sizeof(BN_ULONG));
if (!rsatmp->e || rsatmp->e->dmax != (int)(el / sizeof(BN_ULONG)) ||
!rsatmp->n || rsatmp->n->dmax != (int)(el / sizeof(BN_ULONG)))
goto err;
ret = p_surewarehk_Load_Rsa_Pubkey(msg, key_id, el,
(unsigned long *)rsatmp->n->d,
(unsigned long *)rsatmp->e->d);
surewarehk_error_handling(msg, SUREWARE_F_SUREWARE_LOAD_PUBLIC, ret);
if (ret != 1) {
SUREWAREerr(SUREWARE_F_SUREWARE_LOAD_PUBLIC,
ENGINE_R_FAILED_LOADING_PUBLIC_KEY);
goto err;
}
rsatmp->e->top = el / sizeof(BN_ULONG);
bn_fix_top(rsatmp->e);
rsatmp->n->top = el / sizeof(BN_ULONG);
bn_fix_top(rsatmp->n);
res = EVP_PKEY_new();
EVP_PKEY_assign_RSA(res, rsatmp);
break;
# endif
# ifndef OPENSSL_NO_DSA
case 2:
dsatmp = DSA_new_method(e);
DSA_set_ex_data(dsatmp, dsaHndidx, hptr);
dsatmp->pub_key = BN_new();
dsatmp->p = BN_new();
dsatmp->q = BN_new();
dsatmp->g = BN_new();
bn_expand2(dsatmp->pub_key, el / sizeof(BN_ULONG));
bn_expand2(dsatmp->p, el / sizeof(BN_ULONG));
bn_expand2(dsatmp->q, 20 / sizeof(BN_ULONG));
bn_expand2(dsatmp->g, el / sizeof(BN_ULONG));
if (!dsatmp->pub_key
|| dsatmp->pub_key->dmax != (int)(el / sizeof(BN_ULONG))
|| !dsatmp->p || dsatmp->p->dmax != (int)(el / sizeof(BN_ULONG))
|| !dsatmp->q || dsatmp->q->dmax != 20 / sizeof(BN_ULONG)
|| !dsatmp->g || dsatmp->g->dmax != (int)(el / sizeof(BN_ULONG)))
goto err;
ret = p_surewarehk_Load_Dsa_Pubkey(msg, key_id, el,
(unsigned long *)dsatmp->
pub_key->d,
(unsigned long *)dsatmp->p->d,
(unsigned long *)dsatmp->q->d,
(unsigned long *)dsatmp->g->d);
surewarehk_error_handling(msg, SUREWARE_F_SUREWARE_LOAD_PUBLIC, ret);
if (ret != 1) {
SUREWAREerr(SUREWARE_F_SUREWARE_LOAD_PUBLIC,
ENGINE_R_FAILED_LOADING_PUBLIC_KEY);
goto err;
}
dsatmp->pub_key->top = el / sizeof(BN_ULONG);
bn_fix_top(dsatmp->pub_key);
dsatmp->p->top = el / sizeof(BN_ULONG);
bn_fix_top(dsatmp->p);
dsatmp->q->top = 20 / sizeof(BN_ULONG);
bn_fix_top(dsatmp->q);
dsatmp->g->top = el / sizeof(BN_ULONG);
bn_fix_top(dsatmp->g);
res = EVP_PKEY_new();
EVP_PKEY_assign_DSA(res, dsatmp);
break;
# endif
default:
SUREWAREerr(SUREWARE_F_SUREWARE_LOAD_PUBLIC,
ENGINE_R_FAILED_LOADING_PRIVATE_KEY);
goto err;
}
return res;
err:
# ifndef OPENSSL_NO_RSA
if (rsatmp)
RSA_free(rsatmp);
# endif
# ifndef OPENSSL_NO_DSA
if (dsatmp)
DSA_free(dsatmp);
# endif
return NULL;
}
static EVP_PKEY *surewarehk_load_privkey(ENGINE *e, const char *key_id,
UI_METHOD *ui_method,
void *callback_data)
{
EVP_PKEY *res = NULL;
int ret = 0;
unsigned long el = 0;
char *hptr = NULL;
char keytype = 0;
char msg[64] = "ENGINE_load_privkey";
if (!p_surewarehk_Load_Privkey) {
SUREWAREerr(SUREWARE_F_SUREWAREHK_LOAD_PRIVKEY,
ENGINE_R_NOT_INITIALISED);
} else {
ret = p_surewarehk_Load_Privkey(msg, key_id, &hptr, &el, &keytype);
if (ret != 1) {
SUREWAREerr(SUREWARE_F_SUREWAREHK_LOAD_PRIVKEY,
ENGINE_R_FAILED_LOADING_PRIVATE_KEY);
ERR_add_error_data(1, msg);
} else
res = sureware_load_public(e, key_id, hptr, el, keytype);
}
return res;
}
static EVP_PKEY *surewarehk_load_pubkey(ENGINE *e, const char *key_id,
UI_METHOD *ui_method,
void *callback_data)
{
EVP_PKEY *res = NULL;
int ret = 0;
unsigned long el = 0;
char *hptr = NULL;
char keytype = 0;
char msg[64] = "ENGINE_load_pubkey";
if (!p_surewarehk_Info_Pubkey) {
SUREWAREerr(SUREWARE_F_SUREWAREHK_LOAD_PUBKEY,
ENGINE_R_NOT_INITIALISED);
} else {
ret = p_surewarehk_Info_Pubkey(msg, key_id, &el, &keytype);
if (ret != 1) {
SUREWAREerr(SUREWARE_F_SUREWAREHK_LOAD_PUBKEY,
ENGINE_R_FAILED_LOADING_PUBLIC_KEY);
ERR_add_error_data(1, msg);
} else
res = sureware_load_public(e, key_id, hptr, el, keytype);
}
return res;
}
static void surewarehk_ex_free(void *obj, void *item, CRYPTO_EX_DATA *ad,
int idx, long argl, void *argp)
{
if (!p_surewarehk_Free) {
SUREWAREerr(SUREWARE_F_SUREWAREHK_EX_FREE, ENGINE_R_NOT_INITIALISED);
} else
p_surewarehk_Free((char *)item, 0);
}
static int surewarehk_rsa_priv_dec(int flen, const unsigned char *from,
unsigned char *to, RSA *rsa, int padding)
{
int ret = 0, tlen;
char *buf = NULL, *hptr = NULL;
char msg[64] = "ENGINE_rsa_priv_dec";
if (!p_surewarehk_Rsa_Priv_Dec) {
SUREWAREerr(SUREWARE_F_SUREWAREHK_RSA_PRIV_DEC,
ENGINE_R_NOT_INITIALISED);
}
else if (!(hptr = RSA_get_ex_data(rsa, rsaHndidx))) {
SUREWAREerr(SUREWARE_F_SUREWAREHK_RSA_PRIV_DEC,
SUREWARE_R_MISSING_KEY_COMPONENTS);
goto err;
}
if (padding == RSA_PKCS1_PADDING) {
ret =
p_surewarehk_Rsa_Priv_Dec(msg, flen, (unsigned char *)from, &tlen,
to, hptr, SUREWARE_PKCS1_PAD);
surewarehk_error_handling(msg, SUREWARE_F_SUREWAREHK_RSA_PRIV_DEC,
ret);
if (ret != 1)
goto err;
ret = tlen;
} else {
ret =
p_surewarehk_Rsa_Priv_Dec(msg, flen, (unsigned char *)from, &tlen,
to, hptr, SUREWARE_NO_PAD);
surewarehk_error_handling(msg, SUREWARE_F_SUREWAREHK_RSA_PRIV_DEC,
ret);
if (ret != 1)
goto err;
if ((buf = OPENSSL_malloc(tlen)) == NULL) {
SUREWAREerr(SUREWARE_F_SUREWAREHK_RSA_PRIV_DEC,
ERR_R_MALLOC_FAILURE);
goto err;
}
memcpy(buf, to, tlen);
switch (padding) {
# ifndef OPENSSL_NO_SHA
case RSA_PKCS1_OAEP_PADDING:
ret =
RSA_padding_check_PKCS1_OAEP(to, tlen, (unsigned char *)buf,
tlen, tlen, NULL, 0);
break;
# endif
case RSA_SSLV23_PADDING:
ret =
RSA_padding_check_SSLv23(to, tlen, (unsigned char *)buf, flen,
tlen);
break;
case RSA_NO_PADDING:
ret =
RSA_padding_check_none(to, tlen, (unsigned char *)buf, flen,
tlen);
break;
default:
SUREWAREerr(SUREWARE_F_SUREWAREHK_RSA_PRIV_DEC,
SUREWARE_R_UNKNOWN_PADDING_TYPE);
goto err;
}
if (ret < 0)
SUREWAREerr(SUREWARE_F_SUREWAREHK_RSA_PRIV_DEC,
SUREWARE_R_PADDING_CHECK_FAILED);
}
err:
if (buf) {
OPENSSL_cleanse(buf, tlen);
OPENSSL_free(buf);
}
return ret;
}
static int surewarehk_rsa_sign(int flen, const unsigned char *from,
unsigned char *to, RSA *rsa, int padding)
{
int ret = 0, tlen;
char *hptr = NULL;
char msg[64] = "ENGINE_rsa_sign";
if (!p_surewarehk_Rsa_Sign) {
SUREWAREerr(SUREWARE_F_SUREWAREHK_RSA_SIGN, ENGINE_R_NOT_INITIALISED);
}
else if (!(hptr = RSA_get_ex_data(rsa, rsaHndidx))) {
SUREWAREerr(SUREWARE_F_SUREWAREHK_RSA_SIGN,
SUREWARE_R_MISSING_KEY_COMPONENTS);
} else {
switch (padding) {
case RSA_PKCS1_PADDING:
ret =
p_surewarehk_Rsa_Sign(msg, flen, (unsigned char *)from, &tlen,
to, hptr, SUREWARE_PKCS1_PAD);
surewarehk_error_handling(msg, SUREWARE_F_SUREWAREHK_RSA_SIGN,
ret);
break;
case RSA_NO_PADDING:
default:
SUREWAREerr(SUREWARE_F_SUREWAREHK_RSA_SIGN,
SUREWARE_R_UNKNOWN_PADDING_TYPE);
}
}
return ret == 1 ? tlen : ret;
}
static DSA_SIG *surewarehk_dsa_do_sign(const unsigned char *from, int flen,
DSA *dsa)
{
int ret = 0;
char *hptr = NULL;
DSA_SIG *psign = NULL;
char msg[64] = "ENGINE_dsa_do_sign";
if (!p_surewarehk_Dsa_Sign) {
SUREWAREerr(SUREWARE_F_SUREWAREHK_DSA_DO_SIGN,
ENGINE_R_NOT_INITIALISED);
goto err;
}
else if (!(hptr = DSA_get_ex_data(dsa, dsaHndidx))) {
SUREWAREerr(SUREWARE_F_SUREWAREHK_DSA_DO_SIGN,
SUREWARE_R_MISSING_KEY_COMPONENTS);
goto err;
} else {
if ((psign = DSA_SIG_new()) == NULL) {
SUREWAREerr(SUREWARE_F_SUREWAREHK_DSA_DO_SIGN,
ERR_R_MALLOC_FAILURE);
goto err;
}
psign->r = BN_new();
psign->s = BN_new();
bn_expand2(psign->r, 20 / sizeof(BN_ULONG));
bn_expand2(psign->s, 20 / sizeof(BN_ULONG));
if (!psign->r || psign->r->dmax != 20 / sizeof(BN_ULONG) ||
!psign->s || psign->s->dmax != 20 / sizeof(BN_ULONG))
goto err;
ret = p_surewarehk_Dsa_Sign(msg, flen, from,
(unsigned long *)psign->r->d,
(unsigned long *)psign->s->d, hptr);
surewarehk_error_handling(msg, SUREWARE_F_SUREWAREHK_DSA_DO_SIGN,
ret);
}
psign->r->top = 20 / sizeof(BN_ULONG);
bn_fix_top(psign->r);
psign->s->top = 20 / sizeof(BN_ULONG);
bn_fix_top(psign->s);
err:
if (psign) {
DSA_SIG_free(psign);
psign = NULL;
}
return psign;
}
static int surewarehk_modexp(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
const BIGNUM *m, BN_CTX *ctx)
{
int ret = 0;
char msg[64] = "ENGINE_modexp";
if (!p_surewarehk_Mod_Exp) {
SUREWAREerr(SUREWARE_F_SUREWAREHK_MODEXP, ENGINE_R_NOT_INITIALISED);
} else {
bn_expand2(r, m->top);
if (r && r->dmax == m->top) {
ret = p_surewarehk_Mod_Exp(msg,
m->top * sizeof(BN_ULONG),
(unsigned long *)m->d,
p->top * sizeof(BN_ULONG),
(unsigned long *)p->d,
a->top * sizeof(BN_ULONG),
(unsigned long *)a->d,
(unsigned long *)r->d);
surewarehk_error_handling(msg, SUREWARE_F_SUREWAREHK_MODEXP, ret);
if (ret == 1) {
r->top = m->top;
bn_fix_top(r);
}
}
}
return ret;
}
