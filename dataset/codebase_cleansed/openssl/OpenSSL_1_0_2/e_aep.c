static int bind_aep(ENGINE *e)
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
if (!ENGINE_set_id(e, engine_aep_id) ||
!ENGINE_set_name(e, engine_aep_name) ||
# ifndef OPENSSL_NO_RSA
!ENGINE_set_RSA(e, &aep_rsa) ||
# endif
# ifndef OPENSSL_NO_DSA
!ENGINE_set_DSA(e, &aep_dsa) ||
# endif
# ifndef OPENSSL_NO_DH
!ENGINE_set_DH(e, &aep_dh) ||
# endif
# ifdef AEPRAND
!ENGINE_set_RAND(e, &aep_random) ||
# endif
!ENGINE_set_init_function(e, aep_init) ||
!ENGINE_set_destroy_function(e, aep_destroy) ||
!ENGINE_set_finish_function(e, aep_finish) ||
!ENGINE_set_ctrl_function(e, aep_ctrl) ||
!ENGINE_set_cmd_defns(e, aep_cmd_defns))
return 0;
# ifndef OPENSSL_NO_RSA
meth1 = RSA_PKCS1_SSLeay();
aep_rsa.rsa_pub_enc = meth1->rsa_pub_enc;
aep_rsa.rsa_pub_dec = meth1->rsa_pub_dec;
aep_rsa.rsa_priv_enc = meth1->rsa_priv_enc;
aep_rsa.rsa_priv_dec = meth1->rsa_priv_dec;
# endif
# ifndef OPENSSL_NO_DSA
meth2 = DSA_OpenSSL();
aep_dsa.dsa_do_sign = meth2->dsa_do_sign;
aep_dsa.dsa_sign_setup = meth2->dsa_sign_setup;
aep_dsa.dsa_do_verify = meth2->dsa_do_verify;
aep_dsa = *DSA_get_default_method();
aep_dsa.dsa_mod_exp = aep_dsa_mod_exp;
aep_dsa.bn_mod_exp = aep_mod_exp_dsa;
# endif
# ifndef OPENSSL_NO_DH
meth3 = DH_OpenSSL();
aep_dh.generate_key = meth3->generate_key;
aep_dh.compute_key = meth3->compute_key;
aep_dh.bn_mod_exp = meth3->bn_mod_exp;
# endif
ERR_load_AEPHK_strings();
return 1;
}
static int bind_helper(ENGINE *e, const char *id)
{
if (id && (strcmp(id, engine_aep_id) != 0))
return 0;
if (!bind_aep(e))
return 0;
return 1;
}
static ENGINE *engine_aep(void)
{
ENGINE *ret = ENGINE_new();
if (!ret)
return NULL;
if (!bind_aep(ret)) {
ENGINE_free(ret);
return NULL;
}
return ret;
}
void ENGINE_load_aep(void)
{
ENGINE *toadd = engine_aep();
if (!toadd)
return;
ENGINE_add(toadd);
ENGINE_free(toadd);
ERR_clear_error();
}
static const char *get_AEP_LIBNAME(void)
{
if (AEP_LIBNAME)
return AEP_LIBNAME;
return "aep";
}
static void free_AEP_LIBNAME(void)
{
if (AEP_LIBNAME)
OPENSSL_free((void *)AEP_LIBNAME);
AEP_LIBNAME = NULL;
}
static long set_AEP_LIBNAME(const char *name)
{
free_AEP_LIBNAME();
return ((AEP_LIBNAME = BUF_strdup(name)) != NULL ? 1 : 0);
}
static int aep_init(ENGINE *e)
{
t_AEP_ModExp *p1;
t_AEP_ModExpCrt *p2;
# ifdef AEPRAND
t_AEP_GenRandom *p3;
# endif
t_AEP_Finalize *p4;
t_AEP_Initialize *p5;
t_AEP_OpenConnection *p6;
t_AEP_SetBNCallBacks *p7;
t_AEP_CloseConnection *p8;
int to_return = 0;
if (aep_dso != NULL) {
AEPHKerr(AEPHK_F_AEP_INIT, AEPHK_R_ALREADY_LOADED);
goto err;
}
aep_dso = DSO_load(NULL, get_AEP_LIBNAME(), NULL, 0);
if (aep_dso == NULL) {
AEPHKerr(AEPHK_F_AEP_INIT, AEPHK_R_NOT_LOADED);
goto err;
}
if (!(p1 = (t_AEP_ModExp *) DSO_bind_func(aep_dso, AEP_F1)) ||
!(p2 = (t_AEP_ModExpCrt *) DSO_bind_func(aep_dso, AEP_F2)) ||
# ifdef AEPRAND
!(p3 = (t_AEP_GenRandom *) DSO_bind_func(aep_dso, AEP_F3)) ||
# endif
!(p4 = (t_AEP_Finalize *) DSO_bind_func(aep_dso, AEP_F4)) ||
!(p5 = (t_AEP_Initialize *) DSO_bind_func(aep_dso, AEP_F5)) ||
!(p6 = (t_AEP_OpenConnection *) DSO_bind_func(aep_dso, AEP_F6)) ||
!(p7 = (t_AEP_SetBNCallBacks *) DSO_bind_func(aep_dso, AEP_F7)) ||
!(p8 = (t_AEP_CloseConnection *) DSO_bind_func(aep_dso, AEP_F8))) {
AEPHKerr(AEPHK_F_AEP_INIT, AEPHK_R_NOT_LOADED);
goto err;
}
p_AEP_ModExp = p1;
p_AEP_ModExpCrt = p2;
# ifdef AEPRAND
p_AEP_GenRandom = p3;
# endif
p_AEP_Finalize = p4;
p_AEP_Initialize = p5;
p_AEP_OpenConnection = p6;
p_AEP_SetBNCallBacks = p7;
p_AEP_CloseConnection = p8;
to_return = 1;
return to_return;
err:
if (aep_dso)
DSO_free(aep_dso);
aep_dso = NULL;
p_AEP_OpenConnection = NULL;
p_AEP_ModExp = NULL;
p_AEP_ModExpCrt = NULL;
# ifdef AEPRAND
p_AEP_GenRandom = NULL;
# endif
p_AEP_Initialize = NULL;
p_AEP_Finalize = NULL;
p_AEP_SetBNCallBacks = NULL;
p_AEP_CloseConnection = NULL;
return to_return;
}
static int aep_destroy(ENGINE *e)
{
free_AEP_LIBNAME();
ERR_unload_AEPHK_strings();
return 1;
}
static int aep_finish(ENGINE *e)
{
int to_return = 0, in_use;
AEP_RV rv;
if (aep_dso == NULL) {
AEPHKerr(AEPHK_F_AEP_FINISH, AEPHK_R_NOT_LOADED);
goto err;
}
rv = aep_close_all_connections(0, &in_use);
if (rv != AEP_R_OK) {
AEPHKerr(AEPHK_F_AEP_FINISH, AEPHK_R_CLOSE_HANDLES_FAILED);
goto err;
}
if (in_use) {
AEPHKerr(AEPHK_F_AEP_FINISH, AEPHK_R_CONNECTIONS_IN_USE);
goto err;
}
rv = p_AEP_Finalize();
if (rv != AEP_R_OK) {
AEPHKerr(AEPHK_F_AEP_FINISH, AEPHK_R_FINALIZE_FAILED);
goto err;
}
if (!DSO_free(aep_dso)) {
AEPHKerr(AEPHK_F_AEP_FINISH, AEPHK_R_UNIT_FAILURE);
goto err;
}
aep_dso = NULL;
p_AEP_CloseConnection = NULL;
p_AEP_OpenConnection = NULL;
p_AEP_ModExp = NULL;
p_AEP_ModExpCrt = NULL;
# ifdef AEPRAND
p_AEP_GenRandom = NULL;
# endif
p_AEP_Initialize = NULL;
p_AEP_Finalize = NULL;
p_AEP_SetBNCallBacks = NULL;
to_return = 1;
err:
return to_return;
}
static int aep_ctrl(ENGINE *e, int cmd, long i, void *p, void (*f) (void))
{
int initialised = ((aep_dso == NULL) ? 0 : 1);
switch (cmd) {
case AEP_CMD_SO_PATH:
if (p == NULL) {
AEPHKerr(AEPHK_F_AEP_CTRL, ERR_R_PASSED_NULL_PARAMETER);
return 0;
}
if (initialised) {
AEPHKerr(AEPHK_F_AEP_CTRL, AEPHK_R_ALREADY_LOADED);
return 0;
}
return set_AEP_LIBNAME((const char *)p);
default:
break;
}
AEPHKerr(AEPHK_F_AEP_CTRL, AEPHK_R_CTRL_COMMAND_NOT_IMPLEMENTED);
return 0;
}
static int aep_mod_exp(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
const BIGNUM *m, BN_CTX *ctx)
{
int to_return = 0;
int r_len = 0;
AEP_CONNECTION_HNDL hConnection;
AEP_RV rv;
r_len = BN_num_bits(m);
if (r_len > max_key_len) {
AEPHKerr(AEPHK_F_AEP_MOD_EXP, AEPHK_R_SIZE_TOO_LARGE_OR_TOO_SMALL);
return BN_mod_exp(r, a, p, m, ctx);
}
rv = aep_get_connection(&hConnection);
if (rv != AEP_R_OK) {
AEPHKerr(AEPHK_F_AEP_MOD_EXP, AEPHK_R_GET_HANDLE_FAILED);
return BN_mod_exp(r, a, p, m, ctx);
}
rv = p_AEP_ModExp(hConnection, (void *)a, (void *)p, (void *)m, (void *)r,
NULL);
if (rv != AEP_R_OK) {
AEPHKerr(AEPHK_F_AEP_MOD_EXP, AEPHK_R_MOD_EXP_FAILED);
rv = aep_close_connection(hConnection);
return BN_mod_exp(r, a, p, m, ctx);
}
rv = aep_return_connection(hConnection);
if (rv != AEP_R_OK) {
AEPHKerr(AEPHK_F_AEP_MOD_EXP, AEPHK_R_RETURN_CONNECTION_FAILED);
goto err;
}
to_return = 1;
err:
return to_return;
}
static AEP_RV aep_mod_exp_crt(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
const BIGNUM *q, const BIGNUM *dmp1,
const BIGNUM *dmq1, const BIGNUM *iqmp,
BN_CTX *ctx)
{
AEP_RV rv = AEP_R_OK;
AEP_CONNECTION_HNDL hConnection;
rv = aep_get_connection(&hConnection);
if (rv != AEP_R_OK) {
AEPHKerr(AEPHK_F_AEP_MOD_EXP_CRT, AEPHK_R_GET_HANDLE_FAILED);
return FAIL_TO_SW;
}
rv = p_AEP_ModExpCrt(hConnection, (void *)a, (void *)p, (void *)q,
(void *)dmp1, (void *)dmq1, (void *)iqmp, (void *)r,
NULL);
if (rv != AEP_R_OK) {
AEPHKerr(AEPHK_F_AEP_MOD_EXP_CRT, AEPHK_R_MOD_EXP_CRT_FAILED);
rv = aep_close_connection(hConnection);
return FAIL_TO_SW;
}
rv = aep_return_connection(hConnection);
if (rv != AEP_R_OK) {
AEPHKerr(AEPHK_F_AEP_MOD_EXP_CRT, AEPHK_R_RETURN_CONNECTION_FAILED);
goto err;
}
err:
return rv;
}
static int aep_rand(unsigned char *buf, int len)
{
AEP_RV rv = AEP_R_OK;
AEP_CONNECTION_HNDL hConnection;
CRYPTO_w_lock(CRYPTO_LOCK_RAND);
if (len <= rand_block_bytes) {
memcpy(buf, &rand_block[RAND_BLK_SIZE - rand_block_bytes], len);
rand_block_bytes -= len;
CRYPTO_w_unlock(CRYPTO_LOCK_RAND);
} else
{
CRYPTO_w_unlock(CRYPTO_LOCK_RAND);
rv = aep_get_connection(&hConnection);
if (rv != AEP_R_OK) {
AEPHKerr(AEPHK_F_AEP_RAND, AEPHK_R_GET_HANDLE_FAILED);
goto err_nounlock;
}
if (len > RAND_BLK_SIZE) {
rv = p_AEP_GenRandom(hConnection, len, 2, buf, NULL);
if (rv != AEP_R_OK) {
AEPHKerr(AEPHK_F_AEP_RAND, AEPHK_R_GET_RANDOM_FAILED);
goto err_nounlock;
}
} else {
CRYPTO_w_lock(CRYPTO_LOCK_RAND);
rv = p_AEP_GenRandom(hConnection, RAND_BLK_SIZE, 2,
&rand_block[0], NULL);
if (rv != AEP_R_OK) {
AEPHKerr(AEPHK_F_AEP_RAND, AEPHK_R_GET_RANDOM_FAILED);
goto err;
}
rand_block_bytes = RAND_BLK_SIZE;
memcpy(buf, &rand_block[RAND_BLK_SIZE - rand_block_bytes], len);
rand_block_bytes -= len;
CRYPTO_w_unlock(CRYPTO_LOCK_RAND);
}
rv = aep_return_connection(hConnection);
if (rv != AEP_R_OK) {
AEPHKerr(AEPHK_F_AEP_RAND, AEPHK_R_RETURN_CONNECTION_FAILED);
goto err_nounlock;
}
}
return 1;
err:
CRYPTO_w_unlock(CRYPTO_LOCK_RAND);
err_nounlock:
return 0;
}
static int aep_rand_status(void)
{
return 1;
}
static int aep_rsa_mod_exp(BIGNUM *r0, const BIGNUM *I, RSA *rsa, BN_CTX *ctx)
{
int to_return = 0;
AEP_RV rv = AEP_R_OK;
if (!aep_dso) {
AEPHKerr(AEPHK_F_AEP_RSA_MOD_EXP, AEPHK_R_NOT_LOADED);
goto err;
}
if (rsa->q && rsa->dmp1 && rsa->dmq1 && rsa->iqmp) {
rv = aep_mod_exp_crt(r0, I, rsa->p, rsa->q, rsa->dmp1, rsa->dmq1,
rsa->iqmp, ctx);
if (rv == FAIL_TO_SW) {
const RSA_METHOD *meth = RSA_PKCS1_SSLeay();
to_return = (*meth->rsa_mod_exp) (r0, I, rsa, ctx);
goto err;
} else if (rv != AEP_R_OK)
goto err;
} else {
if (!rsa->d || !rsa->n) {
AEPHKerr(AEPHK_F_AEP_RSA_MOD_EXP, AEPHK_R_MISSING_KEY_COMPONENTS);
goto err;
}
rv = aep_mod_exp(r0, I, rsa->d, rsa->n, ctx);
if (rv != AEP_R_OK)
goto err;
}
to_return = 1;
err:
return to_return;
}
static int aep_dsa_mod_exp(DSA *dsa, BIGNUM *rr, BIGNUM *a1,
BIGNUM *p1, BIGNUM *a2, BIGNUM *p2, BIGNUM *m,
BN_CTX *ctx, BN_MONT_CTX *in_mont)
{
BIGNUM t;
int to_return = 0;
BN_init(&t);
if (!aep_mod_exp(rr, a1, p1, m, ctx))
goto end;
if (!aep_mod_exp(&t, a2, p2, m, ctx))
goto end;
if (!BN_mod_mul(rr, rr, &t, m, ctx))
goto end;
to_return = 1;
end:
BN_free(&t);
return to_return;
}
static int aep_mod_exp_dsa(DSA *dsa, BIGNUM *r, BIGNUM *a,
const BIGNUM *p, const BIGNUM *m, BN_CTX *ctx,
BN_MONT_CTX *m_ctx)
{
return aep_mod_exp(r, a, p, m, ctx);
}
static int aep_mod_exp_mont(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *m_ctx)
{
return aep_mod_exp(r, a, p, m, ctx);
}
static int aep_mod_exp_dh(const DH *dh, BIGNUM *r, const BIGNUM *a,
const BIGNUM *p, const BIGNUM *m, BN_CTX *ctx,
BN_MONT_CTX *m_ctx)
{
return aep_mod_exp(r, a, p, m, ctx);
}
static AEP_RV aep_get_connection(AEP_CONNECTION_HNDL_PTR phConnection)
{
int count;
AEP_RV rv = AEP_R_OK;
pid_t curr_pid;
CRYPTO_w_lock(CRYPTO_LOCK_ENGINE);
curr_pid = getpid();
if (recorded_pid != curr_pid) {
recorded_pid = curr_pid;
p_AEP_Finalize();
rv = p_AEP_Initialize(NULL);
if (rv != AEP_R_OK) {
AEPHKerr(AEPHK_F_AEP_GET_CONNECTION, AEPHK_R_INIT_FAILURE);
recorded_pid = 0;
goto end;
}
rv = p_AEP_SetBNCallBacks(&GetBigNumSize, &MakeAEPBigNum,
&ConvertAEPBigNum);
if (rv != AEP_R_OK) {
AEPHKerr(AEPHK_F_AEP_GET_CONNECTION,
AEPHK_R_SETBNCALLBACK_FAILURE);
recorded_pid = 0;
goto end;
}
# ifdef AEPRAND
rand_block_bytes = 0;
# endif
for (count = 0; count < MAX_PROCESS_CONNECTIONS; count++) {
aep_app_conn_table[count].conn_state = NotConnected;
aep_app_conn_table[count].conn_hndl = 0;
}
rv = p_AEP_OpenConnection(phConnection);
if (rv != AEP_R_OK) {
AEPHKerr(AEPHK_F_AEP_GET_CONNECTION, AEPHK_R_UNIT_FAILURE);
recorded_pid = 0;
goto end;
}
aep_app_conn_table[0].conn_state = InUse;
aep_app_conn_table[0].conn_hndl = *phConnection;
goto end;
}
for (count = 0; count < MAX_PROCESS_CONNECTIONS; count++) {
if (aep_app_conn_table[count].conn_state == Connected) {
aep_app_conn_table[count].conn_state = InUse;
*phConnection = aep_app_conn_table[count].conn_hndl;
goto end;
}
}
for (count = 0; count < MAX_PROCESS_CONNECTIONS; count++) {
if (aep_app_conn_table[count].conn_state == NotConnected) {
rv = p_AEP_OpenConnection(phConnection);
if (rv != AEP_R_OK) {
AEPHKerr(AEPHK_F_AEP_GET_CONNECTION, AEPHK_R_UNIT_FAILURE);
goto end;
}
aep_app_conn_table[count].conn_state = InUse;
aep_app_conn_table[count].conn_hndl = *phConnection;
goto end;
}
}
rv = AEP_R_GENERAL_ERROR;
end:
CRYPTO_w_unlock(CRYPTO_LOCK_ENGINE);
return rv;
}
static AEP_RV aep_return_connection(AEP_CONNECTION_HNDL hConnection)
{
int count;
CRYPTO_w_lock(CRYPTO_LOCK_ENGINE);
for (count = 0; count < MAX_PROCESS_CONNECTIONS; count++) {
if (aep_app_conn_table[count].conn_hndl == hConnection) {
aep_app_conn_table[count].conn_state = Connected;
break;
}
}
CRYPTO_w_unlock(CRYPTO_LOCK_ENGINE);
return AEP_R_OK;
}
static AEP_RV aep_close_connection(AEP_CONNECTION_HNDL hConnection)
{
int count;
AEP_RV rv = AEP_R_OK;
CRYPTO_w_lock(CRYPTO_LOCK_ENGINE);
for (count = 0; count < MAX_PROCESS_CONNECTIONS; count++) {
if (aep_app_conn_table[count].conn_hndl == hConnection) {
rv = p_AEP_CloseConnection(aep_app_conn_table[count].conn_hndl);
if (rv != AEP_R_OK)
goto end;
aep_app_conn_table[count].conn_state = NotConnected;
aep_app_conn_table[count].conn_hndl = 0;
break;
}
}
end:
CRYPTO_w_unlock(CRYPTO_LOCK_ENGINE);
return rv;
}
static AEP_RV aep_close_all_connections(int use_engine_lock, int *in_use)
{
int count;
AEP_RV rv = AEP_R_OK;
*in_use = 0;
if (use_engine_lock)
CRYPTO_w_lock(CRYPTO_LOCK_ENGINE);
for (count = 0; count < MAX_PROCESS_CONNECTIONS; count++) {
switch (aep_app_conn_table[count].conn_state) {
case Connected:
rv = p_AEP_CloseConnection(aep_app_conn_table[count].conn_hndl);
if (rv != AEP_R_OK)
goto end;
aep_app_conn_table[count].conn_state = NotConnected;
aep_app_conn_table[count].conn_hndl = 0;
break;
case InUse:
(*in_use)++;
break;
case NotConnected:
break;
}
}
end:
if (use_engine_lock)
CRYPTO_w_unlock(CRYPTO_LOCK_ENGINE);
return rv;
}
static AEP_RV GetBigNumSize(AEP_VOID_PTR ArbBigNum, AEP_U32 *BigNumSize)
{
BIGNUM *bn;
bn = (BIGNUM *)ArbBigNum;
# ifdef SIXTY_FOUR_BIT_LONG
*BigNumSize = bn->top << 3;
# else
*BigNumSize = bn->top << 2;
# endif
return AEP_R_OK;
}
static AEP_RV MakeAEPBigNum(AEP_VOID_PTR ArbBigNum, AEP_U32 BigNumSize,
unsigned char *AEP_BigNum)
{
BIGNUM *bn;
# ifndef SIXTY_FOUR_BIT_LONG
unsigned char *buf;
int i;
# endif
bn = (BIGNUM *)ArbBigNum;
# ifdef SIXTY_FOUR_BIT_LONG
memcpy(AEP_BigNum, bn->d, BigNumSize);
# else
for (i = 0; i < bn->top; i++) {
buf = (unsigned char *)&bn->d[i];
*((AEP_U32 *)AEP_BigNum) = (AEP_U32)
((unsigned)buf[1] << 8 | buf[0]) |
((unsigned)buf[3] << 8 | buf[2]) << 16;
AEP_BigNum += 4;
}
# endif
return AEP_R_OK;
}
static AEP_RV ConvertAEPBigNum(void *ArbBigNum, AEP_U32 BigNumSize,
unsigned char *AEP_BigNum)
{
BIGNUM *bn;
# ifndef SIXTY_FOUR_BIT_LONG
int i;
# endif
bn = (BIGNUM *)ArbBigNum;
bn_expand(bn, (int)(BigNumSize << 3));
# ifdef SIXTY_FOUR_BIT_LONG
bn->top = BigNumSize >> 3;
if ((BigNumSize & 7) != 0)
bn->top++;
memset(bn->d, 0, bn->top << 3);
memcpy(bn->d, AEP_BigNum, BigNumSize);
# else
bn->top = BigNumSize >> 2;
for (i = 0; i < bn->top; i++) {
bn->d[i] = (AEP_U32)
((unsigned)AEP_BigNum[3] << 8 | AEP_BigNum[2]) << 16 |
((unsigned)AEP_BigNum[1] << 8 | AEP_BigNum[0]);
AEP_BigNum += 4;
}
# endif
return AEP_R_OK;
}
