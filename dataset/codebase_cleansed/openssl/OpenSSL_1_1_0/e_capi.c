static int capi_ctrl(ENGINE *e, int cmd, long i, void *p, void (*f) (void))
{
int ret = 1;
CAPI_CTX *ctx;
BIO *out;
LPSTR tmpstr;
if (capi_idx == -1) {
CAPIerr(CAPI_F_CAPI_CTRL, CAPI_R_ENGINE_NOT_INITIALIZED);
return 0;
}
ctx = ENGINE_get_ex_data(e, capi_idx);
out = BIO_new_fp(stdout, BIO_NOCLOSE);
if (out == NULL) {
CAPIerr(CAPI_F_CAPI_CTRL, CAPI_R_FILE_OPEN_ERROR);
return 0;
}
switch (cmd) {
case CAPI_CMD_LIST_CSPS:
ret = capi_list_providers(ctx, out);
break;
case CAPI_CMD_LIST_CERTS:
ret = capi_list_certs(ctx, out, NULL);
break;
case CAPI_CMD_LOOKUP_CERT:
ret = capi_list_certs(ctx, out, p);
break;
case CAPI_CMD_LIST_CONTAINERS:
ret = capi_list_containers(ctx, out);
break;
case CAPI_CMD_STORE_NAME:
tmpstr = OPENSSL_strdup(p);
if (tmpstr != NULL) {
OPENSSL_free(ctx->storename);
ctx->storename = tmpstr;
CAPI_trace(ctx, "Setting store name to %s\n", p);
} else {
CAPIerr(CAPI_F_CAPI_CTRL, ERR_R_MALLOC_FAILURE);
ret = 0;
}
break;
case CAPI_CMD_STORE_FLAGS:
if (i & 1) {
ctx->store_flags |= CERT_SYSTEM_STORE_LOCAL_MACHINE;
ctx->store_flags &= ~CERT_SYSTEM_STORE_CURRENT_USER;
} else {
ctx->store_flags |= CERT_SYSTEM_STORE_CURRENT_USER;
ctx->store_flags &= ~CERT_SYSTEM_STORE_LOCAL_MACHINE;
}
CAPI_trace(ctx, "Setting flags to %d\n", i);
break;
case CAPI_CMD_DEBUG_LEVEL:
ctx->debug_level = (int)i;
CAPI_trace(ctx, "Setting debug level to %d\n", ctx->debug_level);
break;
case CAPI_CMD_DEBUG_FILE:
tmpstr = OPENSSL_strdup(p);
if (tmpstr != NULL) {
ctx->debug_file = tmpstr;
CAPI_trace(ctx, "Setting debug file to %s\n", ctx->debug_file);
} else {
CAPIerr(CAPI_F_CAPI_CTRL, ERR_R_MALLOC_FAILURE);
ret = 0;
}
break;
case CAPI_CMD_KEYTYPE:
ctx->keytype = i;
CAPI_trace(ctx, "Setting key type to %d\n", ctx->keytype);
break;
case CAPI_CMD_SET_CSP_IDX:
ret = capi_ctx_set_provname_idx(ctx, i);
break;
case CAPI_CMD_LIST_OPTIONS:
ctx->dump_flags = i;
break;
case CAPI_CMD_LOOKUP_METHOD:
if (i < 1 || i > 3) {
CAPIerr(CAPI_F_CAPI_CTRL, CAPI_R_INVALID_LOOKUP_METHOD);
BIO_free(out);
return 0;
}
ctx->lookup_method = i;
break;
case CAPI_CMD_SET_CSP_NAME:
ret = capi_ctx_set_provname(ctx, p, ctx->csptype, 1);
break;
case CAPI_CMD_SET_CSP_TYPE:
ctx->csptype = i;
break;
default:
CAPIerr(CAPI_F_CAPI_CTRL, CAPI_R_UNKNOWN_COMMAND);
ret = 0;
}
BIO_free(out);
return ret;
}
static int capi_init(ENGINE *e)
{
CAPI_CTX *ctx;
const RSA_METHOD *ossl_rsa_meth;
# ifndef OPENSSL_NO_DSA
const DSA_METHOD *ossl_dsa_meth;
# endif
HCRYPTPROV hprov;
if (capi_idx < 0) {
capi_idx = ENGINE_get_ex_new_index(0, NULL, NULL, NULL, 0);
if (capi_idx < 0)
goto memerr;
cert_capi_idx = X509_get_ex_new_index(0, NULL, NULL, NULL, 0);
rsa_capi_idx = RSA_get_ex_new_index(0, NULL, NULL, NULL, 0);
ossl_rsa_meth = RSA_PKCS1_OpenSSL();
if ( !RSA_meth_set_pub_enc(capi_rsa_method,
RSA_meth_get_pub_enc(ossl_rsa_meth))
|| !RSA_meth_set_pub_dec(capi_rsa_method,
RSA_meth_get_pub_dec(ossl_rsa_meth))
|| !RSA_meth_set_priv_enc(capi_rsa_method, capi_rsa_priv_enc)
|| !RSA_meth_set_priv_dec(capi_rsa_method, capi_rsa_priv_dec)
|| !RSA_meth_set_mod_exp(capi_rsa_method,
RSA_meth_get_mod_exp(ossl_rsa_meth))
|| !RSA_meth_set_bn_mod_exp(capi_rsa_method,
RSA_meth_get_bn_mod_exp(ossl_rsa_meth))
|| !RSA_meth_set_finish(capi_rsa_method, capi_rsa_free)
|| !RSA_meth_set_sign(capi_rsa_method, capi_rsa_sign)) {
goto memerr;
}
# ifndef OPENSSL_NO_DSA
dsa_capi_idx = DSA_get_ex_new_index(0, NULL, NULL, NULL, 0);
ossl_dsa_meth = DSA_OpenSSL();
if ( !DSA_meth_set_sign(capi_dsa_method, capi_dsa_do_sign)
|| !DSA_meth_set_verify(capi_dsa_method,
DSA_meth_get_verify(ossl_dsa_meth))
|| !DSA_meth_set_finish(capi_dsa_method, capi_dsa_free)
|| !DSA_meth_set_mod_exp(capi_dsa_method,
DSA_meth_get_mod_exp(ossl_dsa_meth))
|| !DSA_meth_set_bn_mod_exp(capi_dsa_method,
DSA_meth_get_bn_mod_exp(ossl_dsa_meth))) {
goto memerr;
}
# endif
}
ctx = capi_ctx_new();
if (ctx == NULL)
goto memerr;
ENGINE_set_ex_data(e, capi_idx, ctx);
# ifdef OPENSSL_CAPIENG_DIALOG
{
HMODULE cryptui = LoadLibrary(TEXT("CRYPTUI.DLL"));
HMODULE kernel = GetModuleHandle(TEXT("KERNEL32.DLL"));
if (cryptui)
ctx->certselectdlg =
(CERTDLG) GetProcAddress(cryptui,
"CryptUIDlgSelectCertificateFromStore");
if (kernel)
ctx->getconswindow =
(GETCONSWIN) GetProcAddress(kernel, "GetConsoleWindow");
if (cryptui && !OPENSSL_isservice())
ctx->client_cert_select = cert_select_dialog;
}
# endif
if (CryptAcquireContext(&hprov, NULL, NULL, PROV_RSA_AES,
CRYPT_VERIFYCONTEXT)) {
use_aes_csp = 1;
CryptReleaseContext(hprov, 0);
}
return 1;
memerr:
CAPIerr(CAPI_F_CAPI_INIT, ERR_R_MALLOC_FAILURE);
return 0;
return 1;
}
static int capi_destroy(ENGINE *e)
{
RSA_meth_free(capi_rsa_method);
capi_rsa_method = NULL;
# ifndef OPENSSL_NO_DSA
DSA_meth_free(capi_dsa_method);
capi_dsa_method = NULL;
# endif
ERR_unload_CAPI_strings();
return 1;
}
static int capi_finish(ENGINE *e)
{
CAPI_CTX *ctx;
ctx = ENGINE_get_ex_data(e, capi_idx);
capi_ctx_free(ctx);
ENGINE_set_ex_data(e, capi_idx, NULL);
return 1;
}
static int bind_capi(ENGINE *e)
{
capi_rsa_method = RSA_meth_new("CryptoAPI RSA method", 0);
if (capi_rsa_method == NULL)
return 0;
# ifndef OPENSSL_NO_DSA
capi_dsa_method = DSA_meth_new("CryptoAPI DSA method", 0);
if (capi_dsa_method == NULL)
goto memerr;
# endif
if (!ENGINE_set_id(e, engine_capi_id)
|| !ENGINE_set_name(e, engine_capi_name)
|| !ENGINE_set_flags(e, ENGINE_FLAGS_NO_REGISTER_ALL)
|| !ENGINE_set_init_function(e, capi_init)
|| !ENGINE_set_finish_function(e, capi_finish)
|| !ENGINE_set_destroy_function(e, capi_destroy)
|| !ENGINE_set_RSA(e, capi_rsa_method)
# ifndef OPENSSL_NO_DSA
|| !ENGINE_set_DSA(e, capi_dsa_method)
# endif
|| !ENGINE_set_load_privkey_function(e, capi_load_privkey)
|| !ENGINE_set_load_ssl_client_cert_function(e,
capi_load_ssl_client_cert)
|| !ENGINE_set_cmd_defns(e, capi_cmd_defns)
|| !ENGINE_set_ctrl_function(e, capi_ctrl))
goto memerr;
ERR_load_CAPI_strings();
return 1;
memerr:
RSA_meth_free(capi_rsa_method);
capi_rsa_method = NULL;
# ifndef OPENSSL_NO_DSA
DSA_meth_free(capi_dsa_method);
capi_dsa_method = NULL;
# endif
return 0;
}
static int bind_helper(ENGINE *e, const char *id)
{
if (id && (strcmp(id, engine_capi_id) != 0))
return 0;
if (!bind_capi(e))
return 0;
return 1;
}
static ENGINE *engine_capi(void)
{
ENGINE *ret = ENGINE_new();
if (ret == NULL)
return NULL;
if (!bind_capi(ret)) {
ENGINE_free(ret);
return NULL;
}
return ret;
}
void engine_load_capi_int(void)
{
ENGINE *toadd = engine_capi();
if (!toadd)
return;
ENGINE_add(toadd);
ENGINE_free(toadd);
ERR_clear_error();
}
static int lend_tobn(BIGNUM *bn, unsigned char *bin, int binlen)
{
int i;
for (i = 0; i < binlen / 2; i++) {
unsigned char c;
c = bin[i];
bin[i] = bin[binlen - i - 1];
bin[binlen - i - 1] = c;
}
if (!BN_bin2bn(bin, binlen, bn))
return 0;
return 1;
}
static EVP_PKEY *capi_get_pkey(ENGINE *eng, CAPI_KEY * key)
{
unsigned char *pubkey = NULL;
DWORD len;
BLOBHEADER *bh;
RSA *rkey = NULL;
DSA *dkey = NULL;
EVP_PKEY *ret = NULL;
if (!CryptExportKey(key->key, 0, PUBLICKEYBLOB, 0, NULL, &len)) {
CAPIerr(CAPI_F_CAPI_GET_PKEY, CAPI_R_PUBKEY_EXPORT_LENGTH_ERROR);
capi_addlasterror();
return NULL;
}
pubkey = OPENSSL_malloc(len);
if (pubkey == NULL)
goto memerr;
if (!CryptExportKey(key->key, 0, PUBLICKEYBLOB, 0, pubkey, &len)) {
CAPIerr(CAPI_F_CAPI_GET_PKEY, CAPI_R_PUBKEY_EXPORT_ERROR);
capi_addlasterror();
goto err;
}
bh = (BLOBHEADER *) pubkey;
if (bh->bType != PUBLICKEYBLOB) {
CAPIerr(CAPI_F_CAPI_GET_PKEY, CAPI_R_INVALID_PUBLIC_KEY_BLOB);
goto err;
}
if (bh->aiKeyAlg == CALG_RSA_SIGN || bh->aiKeyAlg == CALG_RSA_KEYX) {
RSAPUBKEY *rp;
DWORD rsa_modlen;
BIGNUM *e = NULL, *n = NULL;
unsigned char *rsa_modulus;
rp = (RSAPUBKEY *) (bh + 1);
if (rp->magic != 0x31415352) {
char magstr[10];
BIO_snprintf(magstr, 10, "%lx", rp->magic);
CAPIerr(CAPI_F_CAPI_GET_PKEY,
CAPI_R_INVALID_RSA_PUBLIC_KEY_BLOB_MAGIC_NUMBER);
ERR_add_error_data(2, "magic=0x", magstr);
goto err;
}
rsa_modulus = (unsigned char *)(rp + 1);
rkey = RSA_new_method(eng);
if (!rkey)
goto memerr;
e = BN_new();
n = BN_new();
if (e == NULL || n == NULL) {
BN_free(e);
BN_free(n);
goto memerr;
}
RSA_set0_key(rkey, n, e, NULL);
if (!BN_set_word(e, rp->pubexp))
goto memerr;
rsa_modlen = rp->bitlen / 8;
if (!lend_tobn(n, rsa_modulus, rsa_modlen))
goto memerr;
RSA_set_ex_data(rkey, rsa_capi_idx, key);
if ((ret = EVP_PKEY_new()) == NULL)
goto memerr;
EVP_PKEY_assign_RSA(ret, rkey);
rkey = NULL;
# ifndef OPENSSL_NO_DSA
} else if (bh->aiKeyAlg == CALG_DSS_SIGN) {
DSSPUBKEY *dp;
DWORD dsa_plen;
unsigned char *btmp;
BIGNUM *p, *q, *g, *pub_key;
dp = (DSSPUBKEY *) (bh + 1);
if (dp->magic != 0x31535344) {
char magstr[10];
BIO_snprintf(magstr, 10, "%lx", dp->magic);
CAPIerr(CAPI_F_CAPI_GET_PKEY,
CAPI_R_INVALID_DSA_PUBLIC_KEY_BLOB_MAGIC_NUMBER);
ERR_add_error_data(2, "magic=0x", magstr);
goto err;
}
dsa_plen = dp->bitlen / 8;
btmp = (unsigned char *)(dp + 1);
dkey = DSA_new_method(eng);
if (!dkey)
goto memerr;
p = BN_new();
q = BN_new();
g = BN_new();
pub_key = BN_new();
if (p == NULL || q == NULL || g == NULL || pub_key == NULL) {
BN_free(p);
BN_free(q);
BN_free(g);
BN_free(pub_key);
goto memerr;
}
DSA_set0_pqg(dkey, p, q, g);
DSA_set0_key(dkey, pub_key, NULL);
if (!lend_tobn(p, btmp, dsa_plen))
goto memerr;
btmp += dsa_plen;
if (!lend_tobn(q, btmp, 20))
goto memerr;
btmp += 20;
if (!lend_tobn(g, btmp, dsa_plen))
goto memerr;
btmp += dsa_plen;
if (!lend_tobn(pub_key, btmp, dsa_plen))
goto memerr;
btmp += dsa_plen;
DSA_set_ex_data(dkey, dsa_capi_idx, key);
if ((ret = EVP_PKEY_new()) == NULL)
goto memerr;
EVP_PKEY_assign_DSA(ret, dkey);
dkey = NULL;
# endif
} else {
char algstr[10];
BIO_snprintf(algstr, 10, "%ux", bh->aiKeyAlg);
CAPIerr(CAPI_F_CAPI_GET_PKEY,
CAPI_R_UNSUPPORTED_PUBLIC_KEY_ALGORITHM);
ERR_add_error_data(2, "aiKeyAlg=0x", algstr);
goto err;
}
err:
OPENSSL_free(pubkey);
if (!ret) {
RSA_free(rkey);
# ifndef OPENSSL_NO_DSA
DSA_free(dkey);
# endif
}
return ret;
memerr:
CAPIerr(CAPI_F_CAPI_GET_PKEY, ERR_R_MALLOC_FAILURE);
goto err;
}
static EVP_PKEY *capi_load_privkey(ENGINE *eng, const char *key_id,
UI_METHOD *ui_method, void *callback_data)
{
CAPI_CTX *ctx;
CAPI_KEY *key;
EVP_PKEY *ret;
ctx = ENGINE_get_ex_data(eng, capi_idx);
if (!ctx) {
CAPIerr(CAPI_F_CAPI_LOAD_PRIVKEY, CAPI_R_CANT_FIND_CAPI_CONTEXT);
return NULL;
}
key = capi_find_key(ctx, key_id);
if (!key)
return NULL;
ret = capi_get_pkey(eng, key);
if (!ret)
capi_free_key(key);
return ret;
}
int capi_rsa_priv_enc(int flen, const unsigned char *from,
unsigned char *to, RSA *rsa, int padding)
{
CAPIerr(CAPI_F_CAPI_RSA_PRIV_ENC, CAPI_R_FUNCTION_NOT_SUPPORTED);
return -1;
}
int capi_rsa_sign(int dtype, const unsigned char *m, unsigned int m_len,
unsigned char *sigret, unsigned int *siglen, const RSA *rsa)
{
ALG_ID alg;
HCRYPTHASH hash;
DWORD slen;
unsigned int i;
int ret = -1;
CAPI_KEY *capi_key;
CAPI_CTX *ctx;
ctx = ENGINE_get_ex_data(RSA_get0_engine(rsa), capi_idx);
CAPI_trace(ctx, "Called CAPI_rsa_sign()\n");
capi_key = RSA_get_ex_data(rsa, rsa_capi_idx);
if (!capi_key) {
CAPIerr(CAPI_F_CAPI_RSA_SIGN, CAPI_R_CANT_GET_KEY);
return -1;
}
switch (dtype) {
case NID_sha256:
alg = CALG_SHA_256;
break;
case NID_sha384:
alg = CALG_SHA_384;
break;
case NID_sha512:
alg = CALG_SHA_512;
break;
case NID_sha1:
alg = CALG_SHA1;
break;
case NID_md5:
alg = CALG_MD5;
break;
case NID_md5_sha1:
alg = CALG_SSL3_SHAMD5;
break;
default:
{
char algstr[10];
BIO_snprintf(algstr, 10, "%x", dtype);
CAPIerr(CAPI_F_CAPI_RSA_SIGN, CAPI_R_UNSUPPORTED_ALGORITHM_NID);
ERR_add_error_data(2, "NID=0x", algstr);
return -1;
}
}
if (!CryptCreateHash(capi_key->hprov, alg, 0, 0, &hash)) {
CAPIerr(CAPI_F_CAPI_RSA_SIGN, CAPI_R_CANT_CREATE_HASH_OBJECT);
capi_addlasterror();
return -1;
}
if (!CryptSetHashParam(hash, HP_HASHVAL, (unsigned char *)m, 0)) {
CAPIerr(CAPI_F_CAPI_RSA_SIGN, CAPI_R_CANT_SET_HASH_VALUE);
capi_addlasterror();
goto err;
}
slen = RSA_size(rsa);
if (!CryptSignHash(hash, capi_key->keyspec, NULL, 0, sigret, &slen)) {
CAPIerr(CAPI_F_CAPI_RSA_SIGN, CAPI_R_ERROR_SIGNING_HASH);
capi_addlasterror();
goto err;
} else {
ret = 1;
for (i = 0; i < slen / 2; i++) {
unsigned char c;
c = sigret[i];
sigret[i] = sigret[slen - i - 1];
sigret[slen - i - 1] = c;
}
*siglen = slen;
}
err:
CryptDestroyHash(hash);
return ret;
}
int capi_rsa_priv_dec(int flen, const unsigned char *from,
unsigned char *to, RSA *rsa, int padding)
{
int i;
unsigned char *tmpbuf;
CAPI_KEY *capi_key;
CAPI_CTX *ctx;
DWORD dlen;
if (flen <= 0)
return flen;
ctx = ENGINE_get_ex_data(RSA_get0_engine(rsa), capi_idx);
CAPI_trace(ctx, "Called capi_rsa_priv_dec()\n");
capi_key = RSA_get_ex_data(rsa, rsa_capi_idx);
if (!capi_key) {
CAPIerr(CAPI_F_CAPI_RSA_PRIV_DEC, CAPI_R_CANT_GET_KEY);
return -1;
}
if (padding != RSA_PKCS1_PADDING) {
char errstr[10];
BIO_snprintf(errstr, 10, "%d", padding);
CAPIerr(CAPI_F_CAPI_RSA_PRIV_DEC, CAPI_R_UNSUPPORTED_PADDING);
ERR_add_error_data(2, "padding=", errstr);
return -1;
}
if ((tmpbuf = OPENSSL_malloc(flen)) == NULL) {
CAPIerr(CAPI_F_CAPI_RSA_PRIV_DEC, ERR_R_MALLOC_FAILURE);
return -1;
}
for (i = 0; i < flen; i++)
tmpbuf[flen - i - 1] = from[i];
dlen = flen;
if (!CryptDecrypt(capi_key->key, 0, TRUE, 0, tmpbuf, &dlen)) {
CAPIerr(CAPI_F_CAPI_RSA_PRIV_DEC, CAPI_R_DECRYPT_ERROR);
capi_addlasterror();
OPENSSL_free(tmpbuf);
return -1;
} else
memcpy(to, tmpbuf, (flen = (int)dlen));
OPENSSL_free(tmpbuf);
return flen;
}
static int capi_rsa_free(RSA *rsa)
{
CAPI_KEY *capi_key;
capi_key = RSA_get_ex_data(rsa, rsa_capi_idx);
capi_free_key(capi_key);
RSA_set_ex_data(rsa, rsa_capi_idx, 0);
return 1;
}
static DSA_SIG *capi_dsa_do_sign(const unsigned char *digest, int dlen,
DSA *dsa)
{
HCRYPTHASH hash;
DWORD slen;
DSA_SIG *ret = NULL;
CAPI_KEY *capi_key;
CAPI_CTX *ctx;
unsigned char csigbuf[40];
ctx = ENGINE_get_ex_data(DSA_get0_engine(dsa), capi_idx);
CAPI_trace(ctx, "Called CAPI_dsa_do_sign()\n");
capi_key = DSA_get_ex_data(dsa, dsa_capi_idx);
if (!capi_key) {
CAPIerr(CAPI_F_CAPI_DSA_DO_SIGN, CAPI_R_CANT_GET_KEY);
return NULL;
}
if (dlen != 20) {
CAPIerr(CAPI_F_CAPI_DSA_DO_SIGN, CAPI_R_INVALID_DIGEST_LENGTH);
return NULL;
}
if (!CryptCreateHash(capi_key->hprov, CALG_SHA1, 0, 0, &hash)) {
CAPIerr(CAPI_F_CAPI_DSA_DO_SIGN, CAPI_R_CANT_CREATE_HASH_OBJECT);
capi_addlasterror();
return NULL;
}
if (!CryptSetHashParam(hash, HP_HASHVAL, (unsigned char *)digest, 0)) {
CAPIerr(CAPI_F_CAPI_DSA_DO_SIGN, CAPI_R_CANT_SET_HASH_VALUE);
capi_addlasterror();
goto err;
}
slen = sizeof(csigbuf);
if (!CryptSignHash(hash, capi_key->keyspec, NULL, 0, csigbuf, &slen)) {
CAPIerr(CAPI_F_CAPI_DSA_DO_SIGN, CAPI_R_ERROR_SIGNING_HASH);
capi_addlasterror();
goto err;
} else {
BIGNUM *r = BN_new(), *s = BN_new();
if (r == NULL || s == NULL
|| !lend_tobn(r, csigbuf, 20)
|| !lend_tobn(s, csigbuf + 20, 20)
|| (ret = DSA_SIG_new()) == NULL) {
BN_free(r);
BN_free(s);
goto err;
}
DSA_SIG_set0(ret, r, s);
}
err:
OPENSSL_cleanse(csigbuf, 40);
CryptDestroyHash(hash);
return ret;
}
static int capi_dsa_free(DSA *dsa)
{
CAPI_KEY *capi_key;
capi_key = DSA_get_ex_data(dsa, dsa_capi_idx);
capi_free_key(capi_key);
DSA_set_ex_data(dsa, dsa_capi_idx, 0);
return 1;
}
static void capi_vtrace(CAPI_CTX * ctx, int level, char *format,
va_list argptr)
{
BIO *out;
if (!ctx || (ctx->debug_level < level) || (!ctx->debug_file))
return;
out = BIO_new_file(ctx->debug_file, "a+");
if (out == NULL) {
CAPIerr(CAPI_F_CAPI_VTRACE, CAPI_R_FILE_OPEN_ERROR);
return;
}
BIO_vprintf(out, format, argptr);
BIO_free(out);
}
static void CAPI_trace(CAPI_CTX * ctx, char *format, ...)
{
va_list args;
va_start(args, format);
capi_vtrace(ctx, CAPI_DBG_TRACE, format, args);
va_end(args);
}
static void capi_addlasterror(void)
{
capi_adderror(GetLastError());
}
static void capi_adderror(DWORD err)
{
char errstr[10];
BIO_snprintf(errstr, 10, "%lX", err);
ERR_add_error_data(2, "Error code= 0x", errstr);
}
static char *wide_to_asc(LPCWSTR wstr)
{
char *str;
int len_0, sz;
if (!wstr)
return NULL;
len_0 = (int)wcslen(wstr) + 1;
sz = WideCharToMultiByte(CP_ACP, 0, wstr, len_0, NULL, 0, NULL, NULL);
if (!sz) {
CAPIerr(CAPI_F_WIDE_TO_ASC, CAPI_R_WIN32_ERROR);
return NULL;
}
str = OPENSSL_malloc(sz);
if (str == NULL) {
CAPIerr(CAPI_F_WIDE_TO_ASC, ERR_R_MALLOC_FAILURE);
return NULL;
}
if (!WideCharToMultiByte(CP_ACP, 0, wstr, len_0, str, sz, NULL, NULL)) {
OPENSSL_free(str);
CAPIerr(CAPI_F_WIDE_TO_ASC, CAPI_R_WIN32_ERROR);
return NULL;
}
return str;
}
static int capi_get_provname(CAPI_CTX * ctx, LPSTR * pname, DWORD * ptype,
DWORD idx)
{
DWORD len, err;
LPTSTR name;
CAPI_trace(ctx, "capi_get_provname, index=%d\n", idx);
if (!CryptEnumProviders(idx, NULL, 0, ptype, NULL, &len)) {
err = GetLastError();
if (err == ERROR_NO_MORE_ITEMS)
return 2;
CAPIerr(CAPI_F_CAPI_GET_PROVNAME, CAPI_R_CRYPTENUMPROVIDERS_ERROR);
capi_adderror(err);
return 0;
}
name = OPENSSL_malloc(len);
if (name == NULL) {
CAPIerr(CAPI_F_CAPI_GET_PROVNAME, ERR_R_MALLOC_FAILURE);
return 0;
}
if (!CryptEnumProviders(idx, NULL, 0, ptype, name, &len)) {
err = GetLastError();
OPENSSL_free(name);
if (err == ERROR_NO_MORE_ITEMS)
return 2;
CAPIerr(CAPI_F_CAPI_GET_PROVNAME, CAPI_R_CRYPTENUMPROVIDERS_ERROR);
capi_adderror(err);
return 0;
}
if (sizeof(TCHAR) != sizeof(char)) {
*pname = wide_to_asc((WCHAR *)name);
OPENSSL_free(name);
if (*pname == NULL)
return 0;
} else
*pname = (char *)name;
CAPI_trace(ctx, "capi_get_provname, returned name=%s, type=%d\n", *pname,
*ptype);
return 1;
}
static int capi_list_providers(CAPI_CTX * ctx, BIO *out)
{
DWORD idx, ptype;
int ret;
LPSTR provname = NULL;
CAPI_trace(ctx, "capi_list_providers\n");
BIO_printf(out, "Available CSPs:\n");
for (idx = 0;; idx++) {
ret = capi_get_provname(ctx, &provname, &ptype, idx);
if (ret == 2)
break;
if (ret == 0)
break;
BIO_printf(out, "%lu. %s, type %lu\n", idx, provname, ptype);
OPENSSL_free(provname);
}
return 1;
}
static int capi_list_containers(CAPI_CTX * ctx, BIO *out)
{
int ret = 1;
HCRYPTPROV hprov;
DWORD err, idx, flags, buflen = 0, clen;
LPSTR cname;
LPTSTR cspname = NULL;
CAPI_trace(ctx, "Listing containers CSP=%s, type = %d\n", ctx->cspname,
ctx->csptype);
if (ctx->cspname && sizeof(TCHAR) != sizeof(char)) {
if ((clen =
MultiByteToWideChar(CP_ACP, 0, ctx->cspname, -1, NULL, 0))) {
cspname = alloca(clen * sizeof(WCHAR));
MultiByteToWideChar(CP_ACP, 0, ctx->cspname, -1, (WCHAR *)cspname,
clen);
}
if (!cspname) {
CAPIerr(CAPI_F_CAPI_LIST_CONTAINERS, ERR_R_MALLOC_FAILURE);
capi_addlasterror();
return 0;
}
} else
cspname = (TCHAR *)ctx->cspname;
if (!CryptAcquireContext
(&hprov, NULL, cspname, ctx->csptype, CRYPT_VERIFYCONTEXT)) {
CAPIerr(CAPI_F_CAPI_LIST_CONTAINERS,
CAPI_R_CRYPTACQUIRECONTEXT_ERROR);
capi_addlasterror();
return 0;
}
if (!CryptGetProvParam
(hprov, PP_ENUMCONTAINERS, NULL, &buflen, CRYPT_FIRST)) {
CAPIerr(CAPI_F_CAPI_LIST_CONTAINERS, CAPI_R_ENUMCONTAINERS_ERROR);
capi_addlasterror();
CryptReleaseContext(hprov, 0);
return 0;
}
CAPI_trace(ctx, "Got max container len %d\n", buflen);
if (buflen == 0)
buflen = 1024;
cname = OPENSSL_malloc(buflen);
if (cname == NULL) {
CAPIerr(CAPI_F_CAPI_LIST_CONTAINERS, ERR_R_MALLOC_FAILURE);
goto err;
}
for (idx = 0;; idx++) {
clen = buflen;
cname[0] = 0;
if (idx == 0)
flags = CRYPT_FIRST;
else
flags = 0;
if (!CryptGetProvParam
(hprov, PP_ENUMCONTAINERS, (BYTE *) cname, &clen, flags)) {
err = GetLastError();
if (err == ERROR_NO_MORE_ITEMS)
goto done;
CAPIerr(CAPI_F_CAPI_LIST_CONTAINERS, CAPI_R_ENUMCONTAINERS_ERROR);
capi_adderror(err);
goto err;
}
CAPI_trace(ctx, "Container name %s, len=%d, index=%d, flags=%d\n",
cname, clen, idx, flags);
if (!cname[0] && (clen == buflen)) {
CAPI_trace(ctx, "Enumerate bug: using workaround\n");
goto done;
}
BIO_printf(out, "%lu. %s\n", idx, cname);
}
err:
ret = 0;
done:
OPENSSL_free(cname);
CryptReleaseContext(hprov, 0);
return ret;
}
static CRYPT_KEY_PROV_INFO *capi_get_prov_info(CAPI_CTX * ctx, PCCERT_CONTEXT cert)
{
DWORD len;
CRYPT_KEY_PROV_INFO *pinfo;
if (!CertGetCertificateContextProperty
(cert, CERT_KEY_PROV_INFO_PROP_ID, NULL, &len))
return NULL;
pinfo = OPENSSL_malloc(len);
if (pinfo == NULL) {
CAPIerr(CAPI_F_CAPI_GET_PROV_INFO, ERR_R_MALLOC_FAILURE);
return NULL;
}
if (!CertGetCertificateContextProperty
(cert, CERT_KEY_PROV_INFO_PROP_ID, pinfo, &len)) {
CAPIerr(CAPI_F_CAPI_GET_PROV_INFO,
CAPI_R_ERROR_GETTING_KEY_PROVIDER_INFO);
capi_addlasterror();
OPENSSL_free(pinfo);
return NULL;
}
return pinfo;
}
static void capi_dump_prov_info(CAPI_CTX * ctx, BIO *out,
CRYPT_KEY_PROV_INFO * pinfo)
{
char *provname = NULL, *contname = NULL;
if (!pinfo) {
BIO_printf(out, " No Private Key\n");
return;
}
provname = wide_to_asc(pinfo->pwszProvName);
contname = wide_to_asc(pinfo->pwszContainerName);
if (!provname || !contname)
goto err;
BIO_printf(out, " Private Key Info:\n");
BIO_printf(out, " Provider Name: %s, Provider Type %lu\n", provname,
pinfo->dwProvType);
BIO_printf(out, " Container Name: %s, Key Type %lu\n", contname,
pinfo->dwKeySpec);
err:
OPENSSL_free(provname);
OPENSSL_free(contname);
}
static char *capi_cert_get_fname(CAPI_CTX * ctx, PCCERT_CONTEXT cert)
{
LPWSTR wfname;
DWORD dlen;
CAPI_trace(ctx, "capi_cert_get_fname\n");
if (!CertGetCertificateContextProperty
(cert, CERT_FRIENDLY_NAME_PROP_ID, NULL, &dlen))
return NULL;
wfname = OPENSSL_malloc(dlen);
if (wfname == NULL)
return NULL;
if (CertGetCertificateContextProperty
(cert, CERT_FRIENDLY_NAME_PROP_ID, wfname, &dlen)) {
char *fname = wide_to_asc(wfname);
OPENSSL_free(wfname);
return fname;
}
CAPIerr(CAPI_F_CAPI_CERT_GET_FNAME, CAPI_R_ERROR_GETTING_FRIENDLY_NAME);
capi_addlasterror();
OPENSSL_free(wfname);
return NULL;
}
static void capi_dump_cert(CAPI_CTX * ctx, BIO *out, PCCERT_CONTEXT cert)
{
X509 *x;
const unsigned char *p;
unsigned long flags = ctx->dump_flags;
if (flags & CAPI_DMP_FNAME) {
char *fname;
fname = capi_cert_get_fname(ctx, cert);
if (fname) {
BIO_printf(out, " Friendly Name \"%s\"\n", fname);
OPENSSL_free(fname);
} else
BIO_printf(out, " <No Friendly Name>\n");
}
p = cert->pbCertEncoded;
x = d2i_X509(NULL, &p, cert->cbCertEncoded);
if (!x)
BIO_printf(out, " <Can't parse certificate>\n");
if (flags & CAPI_DMP_SUMMARY) {
BIO_printf(out, " Subject: ");
X509_NAME_print_ex(out, X509_get_subject_name(x), 0, XN_FLAG_ONELINE);
BIO_printf(out, "\n Issuer: ");
X509_NAME_print_ex(out, X509_get_issuer_name(x), 0, XN_FLAG_ONELINE);
BIO_printf(out, "\n");
}
if (flags & CAPI_DMP_FULL)
X509_print_ex(out, x, XN_FLAG_ONELINE, 0);
if (flags & CAPI_DMP_PKEYINFO) {
CRYPT_KEY_PROV_INFO *pinfo;
pinfo = capi_get_prov_info(ctx, cert);
capi_dump_prov_info(ctx, out, pinfo);
OPENSSL_free(pinfo);
}
if (flags & CAPI_DMP_PEM)
PEM_write_bio_X509(out, x);
X509_free(x);
}
static HCERTSTORE capi_open_store(CAPI_CTX * ctx, char *storename)
{
HCERTSTORE hstore;
if (!storename)
storename = ctx->storename;
if (!storename)
storename = "MY";
CAPI_trace(ctx, "Opening certificate store %s\n", storename);
hstore = CertOpenStore(CERT_STORE_PROV_SYSTEM_A, 0, 0,
ctx->store_flags, storename);
if (!hstore) {
CAPIerr(CAPI_F_CAPI_OPEN_STORE, CAPI_R_ERROR_OPENING_STORE);
capi_addlasterror();
}
return hstore;
}
int capi_list_certs(CAPI_CTX * ctx, BIO *out, char *id)
{
char *storename;
int idx;
int ret = 1;
HCERTSTORE hstore;
PCCERT_CONTEXT cert = NULL;
storename = ctx->storename;
if (!storename)
storename = "MY";
CAPI_trace(ctx, "Listing certs for store %s\n", storename);
hstore = capi_open_store(ctx, storename);
if (!hstore)
return 0;
if (id) {
cert = capi_find_cert(ctx, id, hstore);
if (!cert) {
ret = 0;
goto err;
}
capi_dump_cert(ctx, out, cert);
CertFreeCertificateContext(cert);
} else {
for (idx = 0;; idx++) {
cert = CertEnumCertificatesInStore(hstore, cert);
if (!cert)
break;
BIO_printf(out, "Certificate %d\n", idx);
capi_dump_cert(ctx, out, cert);
}
}
err:
CertCloseStore(hstore, 0);
return ret;
}
static PCCERT_CONTEXT capi_find_cert(CAPI_CTX * ctx, const char *id,
HCERTSTORE hstore)
{
PCCERT_CONTEXT cert = NULL;
char *fname = NULL;
int match;
switch (ctx->lookup_method) {
case CAPI_LU_SUBSTR:
return CertFindCertificateInStore(hstore,
X509_ASN_ENCODING, 0,
CERT_FIND_SUBJECT_STR_A, id, NULL);
case CAPI_LU_FNAME:
for (;;) {
cert = CertEnumCertificatesInStore(hstore, cert);
if (!cert)
return NULL;
fname = capi_cert_get_fname(ctx, cert);
if (fname) {
if (strcmp(fname, id))
match = 0;
else
match = 1;
OPENSSL_free(fname);
if (match)
return cert;
}
}
default:
return NULL;
}
}
static CAPI_KEY *capi_get_key(CAPI_CTX * ctx, const TCHAR *contname,
TCHAR *provname, DWORD ptype, DWORD keyspec)
{
DWORD dwFlags = 0;
CAPI_KEY *key = OPENSSL_malloc(sizeof(*key));
if (key == NULL)
return NULL;
if (ptype == PROV_RSA_FULL && use_aes_csp) {
provname = NULL;
ptype = PROV_RSA_AES;
CAPI_trace(ctx, "capi_get_key, contname=%s, RSA_AES_CSP\n", contname);
} else if (sizeof(TCHAR) == sizeof(char)) {
CAPI_trace(ctx, "capi_get_key, contname=%s, provname=%s, type=%d\n",
contname, provname, ptype);
} else if (ctx && ctx->debug_level >= CAPI_DBG_TRACE && ctx->debug_file) {
char *_contname = wide_to_asc((WCHAR *)contname);
char *_provname = wide_to_asc((WCHAR *)provname);
CAPI_trace(ctx, "capi_get_key, contname=%s, provname=%s, type=%d\n",
_contname, _provname, ptype);
OPENSSL_free(_provname);
OPENSSL_free(_contname);
}
if (ctx->store_flags & CERT_SYSTEM_STORE_LOCAL_MACHINE)
dwFlags = CRYPT_MACHINE_KEYSET;
if (!CryptAcquireContext(&key->hprov, contname, provname, ptype, dwFlags)) {
CAPIerr(CAPI_F_CAPI_GET_KEY, CAPI_R_CRYPTACQUIRECONTEXT_ERROR);
capi_addlasterror();
goto err;
}
if (!CryptGetUserKey(key->hprov, keyspec, &key->key)) {
CAPIerr(CAPI_F_CAPI_GET_KEY, CAPI_R_GETUSERKEY_ERROR);
capi_addlasterror();
CryptReleaseContext(key->hprov, 0);
goto err;
}
key->keyspec = keyspec;
key->pcert = NULL;
return key;
err:
OPENSSL_free(key);
return NULL;
}
static CAPI_KEY *capi_get_cert_key(CAPI_CTX * ctx, PCCERT_CONTEXT cert)
{
CAPI_KEY *key = NULL;
CRYPT_KEY_PROV_INFO *pinfo = NULL;
char *provname = NULL, *contname = NULL;
pinfo = capi_get_prov_info(ctx, cert);
if (!pinfo)
goto err;
if (sizeof(TCHAR) != sizeof(char))
key = capi_get_key(ctx, (TCHAR *)pinfo->pwszContainerName,
(TCHAR *)pinfo->pwszProvName,
pinfo->dwProvType, pinfo->dwKeySpec);
else {
provname = wide_to_asc(pinfo->pwszProvName);
contname = wide_to_asc(pinfo->pwszContainerName);
if (!provname || !contname)
goto err;
key = capi_get_key(ctx, (TCHAR *)contname, (TCHAR *)provname,
pinfo->dwProvType, pinfo->dwKeySpec);
}
err:
OPENSSL_free(pinfo);
OPENSSL_free(provname);
OPENSSL_free(contname);
return key;
}
CAPI_KEY *capi_find_key(CAPI_CTX * ctx, const char *id)
{
PCCERT_CONTEXT cert;
HCERTSTORE hstore;
CAPI_KEY *key = NULL;
switch (ctx->lookup_method) {
case CAPI_LU_SUBSTR:
case CAPI_LU_FNAME:
hstore = capi_open_store(ctx, NULL);
if (!hstore)
return NULL;
cert = capi_find_cert(ctx, id, hstore);
if (cert) {
key = capi_get_cert_key(ctx, cert);
CertFreeCertificateContext(cert);
}
CertCloseStore(hstore, 0);
break;
case CAPI_LU_CONTNAME:
if (sizeof(TCHAR) != sizeof(char)) {
WCHAR *contname, *provname;
DWORD len;
if ((len = MultiByteToWideChar(CP_ACP, 0, id, -1, NULL, 0)) &&
(contname = alloca(len * sizeof(WCHAR)),
MultiByteToWideChar(CP_ACP, 0, id, -1, contname, len)) &&
(len =
MultiByteToWideChar(CP_ACP, 0, ctx->cspname, -1, NULL, 0))
&& (provname =
alloca(len * sizeof(WCHAR)), MultiByteToWideChar(CP_ACP,
0,
ctx->cspname,
-1,
provname,
len)))
key =
capi_get_key(ctx, (TCHAR *)contname, (TCHAR *)provname,
ctx->csptype, ctx->keytype);
} else
key = capi_get_key(ctx, (TCHAR *)id,
(TCHAR *)ctx->cspname,
ctx->csptype, ctx->keytype);
break;
}
return key;
}
void capi_free_key(CAPI_KEY * key)
{
if (!key)
return;
CryptDestroyKey(key->key);
CryptReleaseContext(key->hprov, 0);
if (key->pcert)
CertFreeCertificateContext(key->pcert);
OPENSSL_free(key);
}
static CAPI_CTX *capi_ctx_new(void)
{
CAPI_CTX *ctx = OPENSSL_zalloc(sizeof(*ctx));
if (ctx == NULL) {
CAPIerr(CAPI_F_CAPI_CTX_NEW, ERR_R_MALLOC_FAILURE);
return NULL;
}
ctx->csptype = PROV_RSA_FULL;
ctx->dump_flags = CAPI_DMP_SUMMARY | CAPI_DMP_FNAME;
ctx->keytype = AT_KEYEXCHANGE;
ctx->store_flags = CERT_STORE_OPEN_EXISTING_FLAG |
CERT_STORE_READONLY_FLAG | CERT_SYSTEM_STORE_CURRENT_USER;
ctx->lookup_method = CAPI_LU_SUBSTR;
ctx->client_cert_select = cert_select_simple;
return ctx;
}
static void capi_ctx_free(CAPI_CTX * ctx)
{
CAPI_trace(ctx, "Calling capi_ctx_free with %lx\n", ctx);
if (!ctx)
return;
OPENSSL_free(ctx->cspname);
OPENSSL_free(ctx->debug_file);
OPENSSL_free(ctx->storename);
OPENSSL_free(ctx->ssl_client_store);
OPENSSL_free(ctx);
}
static int capi_ctx_set_provname(CAPI_CTX * ctx, LPSTR pname, DWORD type,
int check)
{
LPSTR tmpcspname;
CAPI_trace(ctx, "capi_ctx_set_provname, name=%s, type=%d\n", pname, type);
if (check) {
HCRYPTPROV hprov;
LPTSTR name = NULL;
if (sizeof(TCHAR) != sizeof(char)) {
DWORD len;
if ((len = MultiByteToWideChar(CP_ACP, 0, pname, -1, NULL, 0))) {
name = alloca(len * sizeof(WCHAR));
MultiByteToWideChar(CP_ACP, 0, pname, -1, (WCHAR *)name, len);
}
} else
name = (TCHAR *)pname;
if (!name || !CryptAcquireContext(&hprov, NULL, name, type,
CRYPT_VERIFYCONTEXT)) {
CAPIerr(CAPI_F_CAPI_CTX_SET_PROVNAME,
CAPI_R_CRYPTACQUIRECONTEXT_ERROR);
capi_addlasterror();
return 0;
}
CryptReleaseContext(hprov, 0);
}
tmpcspname = OPENSSL_strdup(pname);
if (tmpcspname == NULL) {
CAPIerr(CAPI_F_CAPI_CTX_SET_PROVNAME, ERR_R_MALLOC_FAILURE);
return 0;
}
OPENSSL_free(ctx->cspname);
ctx->cspname = tmpcspname;
ctx->csptype = type;
return 1;
}
static int capi_ctx_set_provname_idx(CAPI_CTX * ctx, int idx)
{
LPSTR pname;
DWORD type;
int res;
if (capi_get_provname(ctx, &pname, &type, idx) != 1)
return 0;
res = capi_ctx_set_provname(ctx, pname, type, 0);
OPENSSL_free(pname);
return res;
}
OPENSSL_EXPORT
int bind_engine(ENGINE *e, const char *id, const dynamic_fns *fns)
{
return 0;
}
void engine_load_capi_int(void)
{
}
