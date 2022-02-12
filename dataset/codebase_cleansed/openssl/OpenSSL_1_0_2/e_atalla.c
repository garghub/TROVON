static int bind_helper(ENGINE *e)
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
if (!ENGINE_set_id(e, engine_atalla_id) ||
!ENGINE_set_name(e, engine_atalla_name) ||
# ifndef OPENSSL_NO_RSA
!ENGINE_set_RSA(e, &atalla_rsa) ||
# endif
# ifndef OPENSSL_NO_DSA
!ENGINE_set_DSA(e, &atalla_dsa) ||
# endif
# ifndef OPENSSL_NO_DH
!ENGINE_set_DH(e, &atalla_dh) ||
# endif
!ENGINE_set_destroy_function(e, atalla_destroy) ||
!ENGINE_set_init_function(e, atalla_init) ||
!ENGINE_set_finish_function(e, atalla_finish) ||
!ENGINE_set_ctrl_function(e, atalla_ctrl) ||
!ENGINE_set_cmd_defns(e, atalla_cmd_defns))
return 0;
# ifndef OPENSSL_NO_RSA
meth1 = RSA_PKCS1_SSLeay();
atalla_rsa.rsa_pub_enc = meth1->rsa_pub_enc;
atalla_rsa.rsa_pub_dec = meth1->rsa_pub_dec;
atalla_rsa.rsa_priv_enc = meth1->rsa_priv_enc;
atalla_rsa.rsa_priv_dec = meth1->rsa_priv_dec;
# endif
# ifndef OPENSSL_NO_DSA
meth2 = DSA_OpenSSL();
atalla_dsa.dsa_do_sign = meth2->dsa_do_sign;
atalla_dsa.dsa_sign_setup = meth2->dsa_sign_setup;
atalla_dsa.dsa_do_verify = meth2->dsa_do_verify;
# endif
# ifndef OPENSSL_NO_DH
meth3 = DH_OpenSSL();
atalla_dh.generate_key = meth3->generate_key;
atalla_dh.compute_key = meth3->compute_key;
# endif
ERR_load_ATALLA_strings();
return 1;
}
static ENGINE *engine_atalla(void)
{
ENGINE *ret = ENGINE_new();
if (!ret)
return NULL;
if (!bind_helper(ret)) {
ENGINE_free(ret);
return NULL;
}
return ret;
}
void ENGINE_load_atalla(void)
{
ENGINE *toadd = engine_atalla();
if (!toadd)
return;
ENGINE_add(toadd);
ENGINE_free(toadd);
ERR_clear_error();
}
static const char *get_ATALLA_LIBNAME(void)
{
if (ATALLA_LIBNAME)
return ATALLA_LIBNAME;
return "atasi";
}
static void free_ATALLA_LIBNAME(void)
{
if (ATALLA_LIBNAME)
OPENSSL_free((void *)ATALLA_LIBNAME);
ATALLA_LIBNAME = NULL;
}
static long set_ATALLA_LIBNAME(const char *name)
{
free_ATALLA_LIBNAME();
return (((ATALLA_LIBNAME = BUF_strdup(name)) != NULL) ? 1 : 0);
}
static int atalla_destroy(ENGINE *e)
{
free_ATALLA_LIBNAME();
ERR_unload_ATALLA_strings();
return 1;
}
static int atalla_init(ENGINE *e)
{
tfnASI_GetHardwareConfig *p1;
tfnASI_RSAPrivateKeyOpFn *p2;
tfnASI_GetPerformanceStatistics *p3;
unsigned int config_buf[1024];
if (atalla_dso != NULL) {
ATALLAerr(ATALLA_F_ATALLA_INIT, ATALLA_R_ALREADY_LOADED);
goto err;
}
atalla_dso = DSO_load(NULL, get_ATALLA_LIBNAME(), NULL, 0);
if (atalla_dso == NULL) {
ATALLAerr(ATALLA_F_ATALLA_INIT, ATALLA_R_NOT_LOADED);
goto err;
}
if (!
(p1 =
(tfnASI_GetHardwareConfig *) DSO_bind_func(atalla_dso, ATALLA_F1))
|| !(p2 = (tfnASI_RSAPrivateKeyOpFn *) DSO_bind_func(atalla_dso, ATALLA_F2))
|| !(p3 =
(tfnASI_GetPerformanceStatistics *) DSO_bind_func(atalla_dso,
ATALLA_F3))) {
ATALLAerr(ATALLA_F_ATALLA_INIT, ATALLA_R_NOT_LOADED);
goto err;
}
p_Atalla_GetHardwareConfig = p1;
p_Atalla_RSAPrivateKeyOpFn = p2;
p_Atalla_GetPerformanceStatistics = p3;
if (p1(0L, config_buf) != 0) {
ATALLAerr(ATALLA_F_ATALLA_INIT, ATALLA_R_UNIT_FAILURE);
goto err;
}
return 1;
err:
if (atalla_dso)
DSO_free(atalla_dso);
atalla_dso = NULL;
p_Atalla_GetHardwareConfig = NULL;
p_Atalla_RSAPrivateKeyOpFn = NULL;
p_Atalla_GetPerformanceStatistics = NULL;
return 0;
}
static int atalla_finish(ENGINE *e)
{
free_ATALLA_LIBNAME();
if (atalla_dso == NULL) {
ATALLAerr(ATALLA_F_ATALLA_FINISH, ATALLA_R_NOT_LOADED);
return 0;
}
if (!DSO_free(atalla_dso)) {
ATALLAerr(ATALLA_F_ATALLA_FINISH, ATALLA_R_UNIT_FAILURE);
return 0;
}
atalla_dso = NULL;
p_Atalla_GetHardwareConfig = NULL;
p_Atalla_RSAPrivateKeyOpFn = NULL;
p_Atalla_GetPerformanceStatistics = NULL;
return 1;
}
static int atalla_ctrl(ENGINE *e, int cmd, long i, void *p, void (*f) (void))
{
int initialised = ((atalla_dso == NULL) ? 0 : 1);
switch (cmd) {
case ATALLA_CMD_SO_PATH:
if (p == NULL) {
ATALLAerr(ATALLA_F_ATALLA_CTRL, ERR_R_PASSED_NULL_PARAMETER);
return 0;
}
if (initialised) {
ATALLAerr(ATALLA_F_ATALLA_CTRL, ATALLA_R_ALREADY_LOADED);
return 0;
}
return set_ATALLA_LIBNAME((const char *)p);
default:
break;
}
ATALLAerr(ATALLA_F_ATALLA_CTRL, ATALLA_R_CTRL_COMMAND_NOT_IMPLEMENTED);
return 0;
}
static int atalla_mod_exp(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
const BIGNUM *m, BN_CTX *ctx)
{
BIGNUM *modulus;
BIGNUM *exponent;
BIGNUM *argument;
BIGNUM *result;
RSAPrivateKey keydata;
int to_return, numbytes;
modulus = exponent = argument = result = NULL;
to_return = 0;
if (!atalla_dso) {
ATALLAerr(ATALLA_F_ATALLA_MOD_EXP, ATALLA_R_NOT_LOADED);
goto err;
}
BN_CTX_start(ctx);
modulus = BN_CTX_get(ctx);
exponent = BN_CTX_get(ctx);
argument = BN_CTX_get(ctx);
result = BN_CTX_get(ctx);
if (!result) {
ATALLAerr(ATALLA_F_ATALLA_MOD_EXP, ATALLA_R_BN_CTX_FULL);
goto err;
}
if (!bn_wexpand(modulus, m->top) || !bn_wexpand(exponent, m->top) ||
!bn_wexpand(argument, m->top) || !bn_wexpand(result, m->top)) {
ATALLAerr(ATALLA_F_ATALLA_MOD_EXP, ATALLA_R_BN_EXPAND_FAIL);
goto err;
}
memset(&keydata, 0, sizeof keydata);
numbytes = BN_num_bytes(m);
memset(exponent->d, 0, numbytes);
memset(modulus->d, 0, numbytes);
BN_bn2bin(p, (unsigned char *)exponent->d + numbytes - BN_num_bytes(p));
BN_bn2bin(m, (unsigned char *)modulus->d + numbytes - BN_num_bytes(m));
keydata.privateExponent.data = (unsigned char *)exponent->d;
keydata.privateExponent.len = numbytes;
keydata.modulus.data = (unsigned char *)modulus->d;
keydata.modulus.len = numbytes;
memset(argument->d, 0, numbytes);
memset(result->d, 0, numbytes);
BN_bn2bin(a, (unsigned char *)argument->d + numbytes - BN_num_bytes(a));
if (p_Atalla_RSAPrivateKeyOpFn(&keydata, (unsigned char *)result->d,
(unsigned char *)argument->d,
keydata.modulus.len) != 0) {
ATALLAerr(ATALLA_F_ATALLA_MOD_EXP, ATALLA_R_REQUEST_FAILED);
goto err;
}
BN_bin2bn((unsigned char *)result->d, numbytes, r);
to_return = 1;
err:
BN_CTX_end(ctx);
return to_return;
}
static int atalla_rsa_mod_exp(BIGNUM *r0, const BIGNUM *I, RSA *rsa,
BN_CTX *ctx)
{
int to_return = 0;
if (!atalla_dso) {
ATALLAerr(ATALLA_F_ATALLA_RSA_MOD_EXP, ATALLA_R_NOT_LOADED);
goto err;
}
if (!rsa->d || !rsa->n) {
ATALLAerr(ATALLA_F_ATALLA_RSA_MOD_EXP,
ATALLA_R_MISSING_KEY_COMPONENTS);
goto err;
}
to_return = atalla_mod_exp(r0, I, rsa->d, rsa->n, ctx);
err:
return to_return;
}
static int atalla_dsa_mod_exp(DSA *dsa, BIGNUM *rr, BIGNUM *a1,
BIGNUM *p1, BIGNUM *a2, BIGNUM *p2, BIGNUM *m,
BN_CTX *ctx, BN_MONT_CTX *in_mont)
{
BIGNUM t;
int to_return = 0;
BN_init(&t);
if (!atalla_mod_exp(rr, a1, p1, m, ctx))
goto end;
if (!atalla_mod_exp(&t, a2, p2, m, ctx))
goto end;
if (!BN_mod_mul(rr, rr, &t, m, ctx))
goto end;
to_return = 1;
end:
BN_free(&t);
return to_return;
}
static int atalla_mod_exp_dsa(DSA *dsa, BIGNUM *r, BIGNUM *a,
const BIGNUM *p, const BIGNUM *m, BN_CTX *ctx,
BN_MONT_CTX *m_ctx)
{
return atalla_mod_exp(r, a, p, m, ctx);
}
static int atalla_mod_exp_mont(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
const BIGNUM *m, BN_CTX *ctx,
BN_MONT_CTX *m_ctx)
{
return atalla_mod_exp(r, a, p, m, ctx);
}
static int atalla_mod_exp_dh(const DH *dh, BIGNUM *r,
const BIGNUM *a, const BIGNUM *p,
const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *m_ctx)
{
return atalla_mod_exp(r, a, p, m, ctx);
}
static int bind_fn(ENGINE *e, const char *id)
{
if (id && (strcmp(id, engine_atalla_id) != 0))
return 0;
if (!bind_helper(e))
return 0;
return 1;
}
