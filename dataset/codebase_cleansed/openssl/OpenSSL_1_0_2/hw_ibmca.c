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
if (!ENGINE_set_id(e, engine_ibmca_id) ||
!ENGINE_set_name(e, engine_ibmca_name) ||
# ifndef OPENSSL_NO_RSA
!ENGINE_set_RSA(e, &ibmca_rsa) ||
# endif
# ifndef OPENSSL_NO_DSA
!ENGINE_set_DSA(e, &ibmca_dsa) ||
# endif
# ifndef OPENSSL_NO_DH
!ENGINE_set_DH(e, &ibmca_dh) ||
# endif
!ENGINE_set_RAND(e, &ibmca_rand) ||
!ENGINE_set_destroy_function(e, ibmca_destroy) ||
!ENGINE_set_init_function(e, ibmca_init) ||
!ENGINE_set_finish_function(e, ibmca_finish) ||
!ENGINE_set_ctrl_function(e, ibmca_ctrl) ||
!ENGINE_set_cmd_defns(e, ibmca_cmd_defns))
return 0;
# ifndef OPENSSL_NO_RSA
meth1 = RSA_PKCS1_SSLeay();
ibmca_rsa.rsa_pub_enc = meth1->rsa_pub_enc;
ibmca_rsa.rsa_pub_dec = meth1->rsa_pub_dec;
ibmca_rsa.rsa_priv_enc = meth1->rsa_priv_enc;
ibmca_rsa.rsa_priv_dec = meth1->rsa_priv_dec;
# endif
# ifndef OPENSSL_NO_DSA
meth2 = DSA_OpenSSL();
ibmca_dsa.dsa_do_sign = meth2->dsa_do_sign;
ibmca_dsa.dsa_sign_setup = meth2->dsa_sign_setup;
ibmca_dsa.dsa_do_verify = meth2->dsa_do_verify;
# endif
# ifndef OPENSSL_NO_DH
meth3 = DH_OpenSSL();
ibmca_dh.generate_key = meth3->generate_key;
ibmca_dh.compute_key = meth3->compute_key;
# endif
ERR_load_IBMCA_strings();
return 1;
}
static ENGINE *engine_ibmca(void)
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
static
# endif
void ENGINE_load_ibmca(void)
{
ENGINE *toadd = engine_ibmca();
if (!toadd)
return;
ENGINE_add(toadd);
ENGINE_free(toadd);
ERR_clear_error();
}
static int ibmca_destroy(ENGINE *e)
{
ERR_unload_IBMCA_strings();
return 1;
}
static int get_context(ICA_ADAPTER_HANDLE * p_handle)
{
unsigned int status = 0;
status = p_icaOpenAdapter(0, p_handle);
if (status != 0)
return 0;
return 1;
}
static void release_context(ICA_ADAPTER_HANDLE handle)
{
p_icaCloseAdapter(handle);
}
static int ibmca_init(ENGINE *e)
{
void (*p1) ();
void (*p2) ();
void (*p3) ();
void (*p4) ();
void (*p5) ();
if (ibmca_dso != NULL) {
IBMCAerr(IBMCA_F_IBMCA_INIT, IBMCA_R_ALREADY_LOADED);
goto err;
}
ibmca_dso = DSO_load(NULL, IBMCA_LIBNAME, NULL,
0);
if (ibmca_dso == NULL) {
IBMCAerr(IBMCA_F_IBMCA_INIT, IBMCA_R_DSO_FAILURE);
goto err;
}
if (!(p1 = DSO_bind_func(ibmca_dso, IBMCA_F1)) ||
!(p2 = DSO_bind_func(ibmca_dso, IBMCA_F2)) ||
!(p3 = DSO_bind_func(ibmca_dso, IBMCA_F3)) ||
!(p4 = DSO_bind_func(ibmca_dso, IBMCA_F4)) ||
!(p5 = DSO_bind_func(ibmca_dso, IBMCA_F5))) {
IBMCAerr(IBMCA_F_IBMCA_INIT, IBMCA_R_DSO_FAILURE);
goto err;
}
p_icaOpenAdapter = (unsigned int (ICA_CALL *) ())p1;
p_icaCloseAdapter = (unsigned int (ICA_CALL *) ())p2;
p_icaRsaModExpo = (unsigned int (ICA_CALL *) ())p3;
p_icaRandomNumberGenerate = (unsigned int (ICA_CALL *) ())p4;
p_icaRsaCrt = (unsigned int (ICA_CALL *) ())p5;
if (!get_context(&handle)) {
IBMCAerr(IBMCA_F_IBMCA_INIT, IBMCA_R_UNIT_FAILURE);
goto err;
}
return 1;
err:
if (ibmca_dso)
DSO_free(ibmca_dso);
p_icaOpenAdapter = NULL;
p_icaCloseAdapter = NULL;
p_icaRsaModExpo = NULL;
p_icaRandomNumberGenerate = NULL;
return 0;
}
static int ibmca_finish(ENGINE *e)
{
if (ibmca_dso == NULL) {
IBMCAerr(IBMCA_F_IBMCA_FINISH, IBMCA_R_NOT_LOADED);
return 0;
}
release_context(handle);
if (!DSO_free(ibmca_dso)) {
IBMCAerr(IBMCA_F_IBMCA_FINISH, IBMCA_R_DSO_FAILURE);
return 0;
}
ibmca_dso = NULL;
return 1;
}
static int ibmca_ctrl(ENGINE *e, int cmd, long i, void *p, void (*f) ())
{
int initialised = ((ibmca_dso == NULL) ? 0 : 1);
switch (cmd) {
case IBMCA_CMD_SO_PATH:
if (p == NULL) {
IBMCAerr(IBMCA_F_IBMCA_CTRL, ERR_R_PASSED_NULL_PARAMETER);
return 0;
}
if (initialised) {
IBMCAerr(IBMCA_F_IBMCA_CTRL, IBMCA_R_ALREADY_LOADED);
return 0;
}
IBMCA_LIBNAME = (const char *)p;
return 1;
default:
break;
}
IBMCAerr(IBMCA_F_IBMCA_CTRL, IBMCA_R_CTRL_COMMAND_NOT_IMPLEMENTED);
return 0;
}
static int ibmca_mod_exp(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
const BIGNUM *m, BN_CTX *ctx)
{
BIGNUM *argument = NULL;
BIGNUM *result = NULL;
BIGNUM *key = NULL;
int to_return;
int inLen, outLen, tmpLen;
ICA_KEY_RSA_MODEXPO *publKey = NULL;
unsigned int rc;
to_return = 0;
if (!ibmca_dso) {
IBMCAerr(IBMCA_F_IBMCA_MOD_EXP, IBMCA_R_NOT_LOADED);
goto err;
}
BN_CTX_start(ctx);
argument = BN_CTX_get(ctx);
result = BN_CTX_get(ctx);
key = BN_CTX_get(ctx);
if (!argument || !result || !key) {
IBMCAerr(IBMCA_F_IBMCA_MOD_EXP, IBMCA_R_BN_CTX_FULL);
goto err;
}
if (!bn_wexpand(argument, m->top) || !bn_wexpand(result, m->top) ||
!bn_wexpand(key, sizeof(*publKey) / BN_BYTES)) {
IBMCAerr(IBMCA_F_IBMCA_MOD_EXP, IBMCA_R_BN_EXPAND_FAIL);
goto err;
}
publKey = (ICA_KEY_RSA_MODEXPO *)key->d;
if (publKey == NULL) {
goto err;
}
memset(publKey, 0, sizeof(ICA_KEY_RSA_MODEXPO));
publKey->keyType = CORRECT_ENDIANNESS(ME_KEY_TYPE);
publKey->keyLength = CORRECT_ENDIANNESS(sizeof(ICA_KEY_RSA_MODEXPO));
publKey->expOffset = (char *)publKey->keyRecord - (char *)publKey;
outLen = BN_num_bytes(m);
if (outLen > 256) {
IBMCAerr(IBMCA_F_IBMCA_MOD_EXP, IBMCA_R_MEXP_LENGTH_TO_LARGE);
goto err;
}
publKey->expLength = publKey->nLength = outLen;
if (outLen < BN_num_bytes(p)) {
IBMCAerr(IBMCA_F_IBMCA_MOD_EXP, IBMCA_R_UNDERFLOW_KEYRECORD);
goto err;
}
BN_bn2bin(p, &publKey->keyRecord[publKey->expLength - BN_num_bytes(p)]);
BN_bn2bin(m, &publKey->keyRecord[publKey->expLength]);
publKey->modulusBitLength = CORRECT_ENDIANNESS(publKey->nLength * 8);
publKey->nOffset = CORRECT_ENDIANNESS(publKey->expOffset +
publKey->expLength);
publKey->expOffset = CORRECT_ENDIANNESS((char *)publKey->keyRecord -
(char *)publKey);
tmpLen = outLen;
publKey->expLength = publKey->nLength = CORRECT_ENDIANNESS(tmpLen);
memset(argument->d, 0, outLen);
BN_bn2bin(a, (unsigned char *)argument->d + outLen - BN_num_bytes(a));
inLen = outLen;
if ((rc = p_icaRsaModExpo(handle, inLen, (unsigned char *)argument->d,
publKey, &outLen, (unsigned char *)result->d))
!= 0) {
printf("rc = %d\n", rc);
IBMCAerr(IBMCA_F_IBMCA_MOD_EXP, IBMCA_R_REQUEST_FAILED);
goto err;
}
BN_bin2bn((unsigned char *)result->d, outLen, r);
to_return = 1;
err:
BN_CTX_end(ctx);
return to_return;
}
static int ibmca_rsa_mod_exp(BIGNUM *r0, const BIGNUM *I, RSA *rsa)
{
BN_CTX *ctx;
int to_return = 0;
if ((ctx = BN_CTX_new()) == NULL)
goto err;
if (!rsa->p || !rsa->q || !rsa->dmp1 || !rsa->dmq1 || !rsa->iqmp) {
if (!rsa->d || !rsa->n) {
IBMCAerr(IBMCA_F_IBMCA_RSA_MOD_EXP,
IBMCA_R_MISSING_KEY_COMPONENTS);
goto err;
}
to_return = ibmca_mod_exp(r0, I, rsa->d, rsa->n, ctx);
} else {
to_return = ibmca_mod_exp_crt(r0, I, rsa->p, rsa->q, rsa->dmp1,
rsa->dmq1, rsa->iqmp, ctx);
}
err:
if (ctx)
BN_CTX_free(ctx);
return to_return;
}
static int ibmca_mod_exp_crt(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
const BIGNUM *q, const BIGNUM *dmp1,
const BIGNUM *dmq1, const BIGNUM *iqmp,
BN_CTX *ctx)
{
BIGNUM *argument = NULL;
BIGNUM *result = NULL;
BIGNUM *key = NULL;
int to_return = 0;
char *pkey = NULL;
ICA_KEY_RSA_CRT *privKey = NULL;
int inLen, outLen;
int rc;
unsigned int offset, pSize, qSize;
unsigned int keyRecordSize;
unsigned int pbytes = BN_num_bytes(p);
unsigned int qbytes = BN_num_bytes(q);
unsigned int dmp1bytes = BN_num_bytes(dmp1);
unsigned int dmq1bytes = BN_num_bytes(dmq1);
unsigned int iqmpbytes = BN_num_bytes(iqmp);
BN_CTX_start(ctx);
argument = BN_CTX_get(ctx);
result = BN_CTX_get(ctx);
key = BN_CTX_get(ctx);
if (!argument || !result || !key) {
IBMCAerr(IBMCA_F_IBMCA_MOD_EXP_CRT, IBMCA_R_BN_CTX_FULL);
goto err;
}
if (!bn_wexpand(argument, p->top + q->top) ||
!bn_wexpand(result, p->top + q->top) ||
!bn_wexpand(key, sizeof(*privKey) / BN_BYTES)) {
IBMCAerr(IBMCA_F_IBMCA_MOD_EXP_CRT, IBMCA_R_BN_EXPAND_FAIL);
goto err;
}
privKey = (ICA_KEY_RSA_CRT *)key->d;
keyRecordSize = pbytes + qbytes + dmp1bytes + dmq1bytes + iqmpbytes;
if (keyRecordSize > sizeof(privKey->keyRecord)) {
IBMCAerr(IBMCA_F_IBMCA_MOD_EXP_CRT, IBMCA_R_OPERANDS_TO_LARGE);
goto err;
}
if ((qbytes + dmq1bytes) > 256) {
IBMCAerr(IBMCA_F_IBMCA_MOD_EXP_CRT, IBMCA_R_OPERANDS_TO_LARGE);
goto err;
}
if (pbytes + dmp1bytes > 256) {
IBMCAerr(IBMCA_F_IBMCA_MOD_EXP_CRT, IBMCA_R_OPERANDS_TO_LARGE);
goto err;
}
memset(privKey, 0, sizeof(ICA_KEY_RSA_CRT));
privKey->keyType = CORRECT_ENDIANNESS(CRT_KEY_TYPE);
privKey->keyLength = CORRECT_ENDIANNESS(sizeof(ICA_KEY_RSA_CRT));
privKey->modulusBitLength = CORRECT_ENDIANNESS(BN_num_bytes(q) * 2 * 8);
privKey->pLength = CORRECT_ENDIANNESS(BN_num_bytes(p) + 8);
privKey->qLength = CORRECT_ENDIANNESS(BN_num_bytes(q));
privKey->dpLength = CORRECT_ENDIANNESS(BN_num_bytes(dmp1) + 8);
privKey->dqLength = CORRECT_ENDIANNESS(BN_num_bytes(dmq1));
privKey->qInvLength = CORRECT_ENDIANNESS(BN_num_bytes(iqmp) + 8);
offset = (char *)privKey->keyRecord - (char *)privKey;
qSize = BN_num_bytes(q);
pSize = qSize + 8;
if ((pbytes > pSize) || (dmp1bytes > pSize) ||
(iqmpbytes > pSize) || (qbytes > qSize) || (dmq1bytes > qSize)) {
IBMCAerr(IBMCA_F_IBMCA_MOD_EXP_CRT, IBMCA_R_OPERANDS_TO_LARGE);
goto err;
}
privKey->dpOffset = CORRECT_ENDIANNESS(offset);
offset += pSize;
privKey->dqOffset = CORRECT_ENDIANNESS(offset);
offset += qSize;
privKey->pOffset = CORRECT_ENDIANNESS(offset);
offset += pSize;
privKey->qOffset = CORRECT_ENDIANNESS(offset);
offset += qSize;
privKey->qInvOffset = CORRECT_ENDIANNESS(offset);
pkey = (char *)privKey->keyRecord;
if (pSize < pbytes) {
IBMCAerr(IBMCA_F_IBMCA_MOD_EXP_CRT, IBMCA_R_UNDERFLOW_CONDITION);
goto err;
}
pkey += pSize - BN_num_bytes(dmp1);
BN_bn2bin(dmp1, pkey);
pkey += BN_num_bytes(dmp1);
BN_bn2bin(dmq1, pkey);
pkey += qSize;
pkey += pSize - BN_num_bytes(p);
BN_bn2bin(p, pkey);
pkey += BN_num_bytes(p);
BN_bn2bin(q, pkey);
pkey += qSize;
pkey += pSize - BN_num_bytes(iqmp);
BN_bn2bin(iqmp, pkey);
outLen = CORRECT_ENDIANNESS(privKey->qLength) * 2;
if (outLen > 256) {
IBMCAerr(IBMCA_F_IBMCA_MOD_EXP_CRT, IBMCA_R_OUTLEN_TO_LARGE);
goto err;
}
if (outLen < BN_num_bytes(a)) {
IBMCAerr(IBMCA_F_IBMCA_MOD_EXP_CRT, IBMCA_R_UNDERFLOW_CONDITION);
goto err;
}
BN_bn2bin(a, (unsigned char *)argument->d + outLen - BN_num_bytes(a));
inLen = outLen;
memset(result->d, 0, outLen);
if ((rc = p_icaRsaCrt(handle, inLen, (unsigned char *)argument->d,
privKey, &outLen, (unsigned char *)result->d)) != 0)
{
printf("rc = %d\n", rc);
IBMCAerr(IBMCA_F_IBMCA_MOD_EXP_CRT, IBMCA_R_REQUEST_FAILED);
goto err;
}
BN_bin2bn((unsigned char *)result->d, outLen, r);
to_return = 1;
err:
BN_CTX_end(ctx);
return to_return;
}
static int ibmca_dsa_mod_exp(DSA *dsa, BIGNUM *rr, BIGNUM *a1,
BIGNUM *p1, BIGNUM *a2, BIGNUM *p2, BIGNUM *m,
BN_CTX *ctx, BN_MONT_CTX *in_mont)
{
BIGNUM t;
int to_return = 0;
BN_init(&t);
if (!ibmca_mod_exp(rr, a1, p1, m, ctx))
goto end;
if (!ibmca_mod_exp(&t, a2, p2, m, ctx))
goto end;
if (!BN_mod_mul(rr, rr, &t, m, ctx))
goto end;
to_return = 1;
end:
BN_free(&t);
return to_return;
}
static int ibmca_mod_exp_dsa(DSA *dsa, BIGNUM *r, BIGNUM *a,
const BIGNUM *p, const BIGNUM *m, BN_CTX *ctx,
BN_MONT_CTX *m_ctx)
{
return ibmca_mod_exp(r, a, p, m, ctx);
}
static int ibmca_mod_exp_mont(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
const BIGNUM *m, BN_CTX *ctx,
BN_MONT_CTX *m_ctx)
{
return ibmca_mod_exp(r, a, p, m, ctx);
}
static int ibmca_mod_exp_dh(DH const *dh, BIGNUM *r,
const BIGNUM *a, const BIGNUM *p,
const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *m_ctx)
{
return ibmca_mod_exp(r, a, p, m, ctx);
}
static int ibmca_rand_bytes(unsigned char *buf, int num)
{
int to_return = 0;
unsigned int ret;
if (handle == 0) {
IBMCAerr(IBMCA_F_IBMCA_RAND_BYTES, IBMCA_R_NOT_INITIALISED);
goto err;
}
ret = p_icaRandomNumberGenerate(handle, num, buf);
if (ret < 0) {
IBMCAerr(IBMCA_F_IBMCA_RAND_BYTES, IBMCA_R_REQUEST_FAILED);
goto err;
}
to_return = 1;
err:
return to_return;
}
static int ibmca_rand_status(void)
{
return 1;
}
static int bind_fn(ENGINE *e, const char *id)
{
if (id && (strcmp(id, engine_ibmca_id) != 0))
return 0;
if (!bind_helper(e))
return 0;
return 1;
}
