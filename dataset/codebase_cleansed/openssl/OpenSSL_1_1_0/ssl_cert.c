int SSL_get_ex_data_X509_STORE_CTX_idx(void)
{
if (!RUN_ONCE(&ssl_x509_store_ctx_once, ssl_x509_store_ctx_init))
return -1;
return ssl_x509_store_ctx_idx;
}
CERT *ssl_cert_new(void)
{
CERT *ret = OPENSSL_zalloc(sizeof(*ret));
if (ret == NULL) {
SSLerr(SSL_F_SSL_CERT_NEW, ERR_R_MALLOC_FAILURE);
return NULL;
}
ret->key = &(ret->pkeys[SSL_PKEY_RSA_ENC]);
ret->references = 1;
ret->sec_cb = ssl_security_default_callback;
ret->sec_level = OPENSSL_TLS_SECURITY_LEVEL;
ret->sec_ex = NULL;
ret->lock = CRYPTO_THREAD_lock_new();
if (ret->lock == NULL) {
SSLerr(SSL_F_SSL_CERT_NEW, ERR_R_MALLOC_FAILURE);
OPENSSL_free(ret);
return NULL;
}
return ret;
}
CERT *ssl_cert_dup(CERT *cert)
{
CERT *ret = OPENSSL_zalloc(sizeof(*ret));
int i;
if (ret == NULL) {
SSLerr(SSL_F_SSL_CERT_DUP, ERR_R_MALLOC_FAILURE);
return NULL;
}
ret->references = 1;
ret->key = &ret->pkeys[cert->key - cert->pkeys];
ret->lock = CRYPTO_THREAD_lock_new();
if (ret->lock == NULL) {
SSLerr(SSL_F_SSL_CERT_DUP, ERR_R_MALLOC_FAILURE);
OPENSSL_free(ret);
return NULL;
}
#ifndef OPENSSL_NO_DH
if (cert->dh_tmp != NULL) {
ret->dh_tmp = cert->dh_tmp;
EVP_PKEY_up_ref(ret->dh_tmp);
}
ret->dh_tmp_cb = cert->dh_tmp_cb;
ret->dh_tmp_auto = cert->dh_tmp_auto;
#endif
for (i = 0; i < SSL_PKEY_NUM; i++) {
CERT_PKEY *cpk = cert->pkeys + i;
CERT_PKEY *rpk = ret->pkeys + i;
if (cpk->x509 != NULL) {
rpk->x509 = cpk->x509;
X509_up_ref(rpk->x509);
}
if (cpk->privatekey != NULL) {
rpk->privatekey = cpk->privatekey;
EVP_PKEY_up_ref(cpk->privatekey);
}
if (cpk->chain) {
rpk->chain = X509_chain_up_ref(cpk->chain);
if (!rpk->chain) {
SSLerr(SSL_F_SSL_CERT_DUP, ERR_R_MALLOC_FAILURE);
goto err;
}
}
if (cert->pkeys[i].serverinfo != NULL) {
ret->pkeys[i].serverinfo =
OPENSSL_malloc(cert->pkeys[i].serverinfo_length);
if (ret->pkeys[i].serverinfo == NULL) {
SSLerr(SSL_F_SSL_CERT_DUP, ERR_R_MALLOC_FAILURE);
goto err;
}
ret->pkeys[i].serverinfo_length = cert->pkeys[i].serverinfo_length;
memcpy(ret->pkeys[i].serverinfo,
cert->pkeys[i].serverinfo, cert->pkeys[i].serverinfo_length);
}
}
if (cert->conf_sigalgs) {
ret->conf_sigalgs = OPENSSL_malloc(cert->conf_sigalgslen);
if (ret->conf_sigalgs == NULL)
goto err;
memcpy(ret->conf_sigalgs, cert->conf_sigalgs, cert->conf_sigalgslen);
ret->conf_sigalgslen = cert->conf_sigalgslen;
} else
ret->conf_sigalgs = NULL;
if (cert->client_sigalgs) {
ret->client_sigalgs = OPENSSL_malloc(cert->client_sigalgslen);
if (ret->client_sigalgs == NULL)
goto err;
memcpy(ret->client_sigalgs, cert->client_sigalgs,
cert->client_sigalgslen);
ret->client_sigalgslen = cert->client_sigalgslen;
} else
ret->client_sigalgs = NULL;
ret->shared_sigalgs = NULL;
if (cert->ctypes) {
ret->ctypes = OPENSSL_malloc(cert->ctype_num);
if (ret->ctypes == NULL)
goto err;
memcpy(ret->ctypes, cert->ctypes, cert->ctype_num);
ret->ctype_num = cert->ctype_num;
}
ret->cert_flags = cert->cert_flags;
ret->cert_cb = cert->cert_cb;
ret->cert_cb_arg = cert->cert_cb_arg;
if (cert->verify_store) {
X509_STORE_up_ref(cert->verify_store);
ret->verify_store = cert->verify_store;
}
if (cert->chain_store) {
X509_STORE_up_ref(cert->chain_store);
ret->chain_store = cert->chain_store;
}
ret->sec_cb = cert->sec_cb;
ret->sec_level = cert->sec_level;
ret->sec_ex = cert->sec_ex;
if (!custom_exts_copy(&ret->cli_ext, &cert->cli_ext))
goto err;
if (!custom_exts_copy(&ret->srv_ext, &cert->srv_ext))
goto err;
#ifndef OPENSSL_NO_PSK
if (cert->psk_identity_hint) {
ret->psk_identity_hint = OPENSSL_strdup(cert->psk_identity_hint);
if (ret->psk_identity_hint == NULL)
goto err;
}
#endif
return ret;
err:
ssl_cert_free(ret);
return NULL;
}
void ssl_cert_clear_certs(CERT *c)
{
int i;
if (c == NULL)
return;
for (i = 0; i < SSL_PKEY_NUM; i++) {
CERT_PKEY *cpk = c->pkeys + i;
X509_free(cpk->x509);
cpk->x509 = NULL;
EVP_PKEY_free(cpk->privatekey);
cpk->privatekey = NULL;
sk_X509_pop_free(cpk->chain, X509_free);
cpk->chain = NULL;
OPENSSL_free(cpk->serverinfo);
cpk->serverinfo = NULL;
cpk->serverinfo_length = 0;
}
}
void ssl_cert_free(CERT *c)
{
int i;
if (c == NULL)
return;
CRYPTO_atomic_add(&c->references, -1, &i, c->lock);
REF_PRINT_COUNT("CERT", c);
if (i > 0)
return;
REF_ASSERT_ISNT(i < 0);
#ifndef OPENSSL_NO_DH
EVP_PKEY_free(c->dh_tmp);
#endif
ssl_cert_clear_certs(c);
OPENSSL_free(c->conf_sigalgs);
OPENSSL_free(c->client_sigalgs);
OPENSSL_free(c->shared_sigalgs);
OPENSSL_free(c->ctypes);
X509_STORE_free(c->verify_store);
X509_STORE_free(c->chain_store);
custom_exts_free(&c->cli_ext);
custom_exts_free(&c->srv_ext);
#ifndef OPENSSL_NO_PSK
OPENSSL_free(c->psk_identity_hint);
#endif
CRYPTO_THREAD_lock_free(c->lock);
OPENSSL_free(c);
}
int ssl_cert_add0_chain_cert(SSL *s, SSL_CTX *ctx, X509 *x)
{
int r;
CERT_PKEY *cpk = s ? s->cert->key : ctx->cert->key;
if (!cpk)
return 0;
r = ssl_security_cert(s, ctx, x, 0, 0);
if (r != 1) {
SSLerr(SSL_F_SSL_CERT_ADD0_CHAIN_CERT, r);
return 0;
}
if (!cpk->chain)
cpk->chain = sk_X509_new_null();
if (!cpk->chain || !sk_X509_push(cpk->chain, x))
return 0;
return 1;
}
int ssl_cert_add1_chain_cert(SSL *s, SSL_CTX *ctx, X509 *x)
{
if (!ssl_cert_add0_chain_cert(s, ctx, x))
return 0;
X509_up_ref(x);
return 1;
}
int ssl_cert_select_current(CERT *c, X509 *x)
{
int i;
if (x == NULL)
return 0;
for (i = 0; i < SSL_PKEY_NUM; i++) {
CERT_PKEY *cpk = c->pkeys + i;
if (cpk->x509 == x && cpk->privatekey) {
c->key = cpk;
return 1;
}
}
for (i = 0; i < SSL_PKEY_NUM; i++) {
CERT_PKEY *cpk = c->pkeys + i;
if (cpk->privatekey && cpk->x509 && !X509_cmp(cpk->x509, x)) {
c->key = cpk;
return 1;
}
}
return 0;
}
int ssl_cert_set_current(CERT *c, long op)
{
int i, idx;
if (!c)
return 0;
if (op == SSL_CERT_SET_FIRST)
idx = 0;
else if (op == SSL_CERT_SET_NEXT) {
idx = (int)(c->key - c->pkeys + 1);
if (idx >= SSL_PKEY_NUM)
return 0;
} else
return 0;
for (i = idx; i < SSL_PKEY_NUM; i++) {
CERT_PKEY *cpk = c->pkeys + i;
if (cpk->x509 && cpk->privatekey) {
c->key = cpk;
return 1;
}
}
return 0;
}
void ssl_cert_set_cert_cb(CERT *c, int (*cb) (SSL *ssl, void *arg), void *arg)
{
c->cert_cb = cb;
c->cert_cb_arg = arg;
}
int SSL_add_client_CA(SSL *ssl, X509 *x)
{
return (add_client_CA(&(ssl->client_CA), x));
}
int SSL_CTX_add_client_CA(SSL_CTX *ctx, X509 *x)
{
return (add_client_CA(&(ctx->client_CA), x));
}
static int xname_sk_cmp(const X509_NAME *const *a, const X509_NAME *const *b)
{
return (X509_NAME_cmp(*a, *b));
}
static int xname_cmp(const X509_NAME *a, const X509_NAME *b)
{
return X509_NAME_cmp(a, b);
}
static unsigned long xname_hash(const X509_NAME *a)
{
return X509_NAME_hash((X509_NAME *)a);
}
static int ssl_add_cert_to_buf(BUF_MEM *buf, unsigned long *l, X509 *x)
{
int n;
unsigned char *p;
n = i2d_X509(x, NULL);
if (n < 0 || !BUF_MEM_grow_clean(buf, (int)(n + (*l) + 3))) {
SSLerr(SSL_F_SSL_ADD_CERT_TO_BUF, ERR_R_BUF_LIB);
return 0;
}
p = (unsigned char *)&(buf->data[*l]);
l2n3(n, p);
n = i2d_X509(x, &p);
if (n < 0) {
SSLerr(SSL_F_SSL_ADD_CERT_TO_BUF, ERR_R_BUF_LIB);
return 0;
}
*l += n + 3;
return 1;
}
int ssl_add_cert_chain(SSL *s, CERT_PKEY *cpk, unsigned long *l)
{
BUF_MEM *buf = s->init_buf;
int i, chain_count;
X509 *x;
STACK_OF(X509) *extra_certs;
STACK_OF(X509) *chain = NULL;
X509_STORE *chain_store;
if (!BUF_MEM_grow_clean(buf, 10)) {
SSLerr(SSL_F_SSL_ADD_CERT_CHAIN, ERR_R_BUF_LIB);
return 0;
}
if (!cpk || !cpk->x509)
return 1;
x = cpk->x509;
if (cpk->chain)
extra_certs = cpk->chain;
else
extra_certs = s->ctx->extra_certs;
if ((s->mode & SSL_MODE_NO_AUTO_CHAIN) || extra_certs)
chain_store = NULL;
else if (s->cert->chain_store)
chain_store = s->cert->chain_store;
else
chain_store = s->ctx->cert_store;
if (chain_store) {
X509_STORE_CTX *xs_ctx = X509_STORE_CTX_new();
if (xs_ctx == NULL) {
SSLerr(SSL_F_SSL_ADD_CERT_CHAIN, ERR_R_MALLOC_FAILURE);
return (0);
}
if (!X509_STORE_CTX_init(xs_ctx, chain_store, x, NULL)) {
X509_STORE_CTX_free(xs_ctx);
SSLerr(SSL_F_SSL_ADD_CERT_CHAIN, ERR_R_X509_LIB);
return (0);
}
(void)X509_verify_cert(xs_ctx);
ERR_clear_error();
chain = X509_STORE_CTX_get0_chain(xs_ctx);
i = ssl_security_cert_chain(s, chain, NULL, 0);
if (i != 1) {
#if 0
SSLerr(SSL_F_SSL_ADD_CERT_CHAIN, SSL_R_EE_KEY_TOO_SMALL);
SSLerr(SSL_F_SSL_ADD_CERT_CHAIN, SSL_R_CA_KEY_TOO_SMALL);
SSLerr(SSL_F_SSL_ADD_CERT_CHAIN, SSL_R_CA_MD_TOO_WEAK);
#endif
X509_STORE_CTX_free(xs_ctx);
SSLerr(SSL_F_SSL_ADD_CERT_CHAIN, i);
return 0;
}
chain_count = sk_X509_num(chain);
for (i = 0; i < chain_count; i++) {
x = sk_X509_value(chain, i);
if (!ssl_add_cert_to_buf(buf, l, x)) {
X509_STORE_CTX_free(xs_ctx);
return 0;
}
}
X509_STORE_CTX_free(xs_ctx);
} else {
i = ssl_security_cert_chain(s, extra_certs, x, 0);
if (i != 1) {
SSLerr(SSL_F_SSL_ADD_CERT_CHAIN, i);
return 0;
}
if (!ssl_add_cert_to_buf(buf, l, x))
return 0;
for (i = 0; i < sk_X509_num(extra_certs); i++) {
x = sk_X509_value(extra_certs, i);
if (!ssl_add_cert_to_buf(buf, l, x))
return 0;
}
}
return 1;
}
int ssl_build_cert_chain(SSL *s, SSL_CTX *ctx, int flags)
{
CERT *c = s ? s->cert : ctx->cert;
CERT_PKEY *cpk = c->key;
X509_STORE *chain_store = NULL;
X509_STORE_CTX *xs_ctx = NULL;
STACK_OF(X509) *chain = NULL, *untrusted = NULL;
X509 *x;
int i, rv = 0;
unsigned long error;
if (!cpk->x509) {
SSLerr(SSL_F_SSL_BUILD_CERT_CHAIN, SSL_R_NO_CERTIFICATE_SET);
goto err;
}
if (flags & SSL_BUILD_CHAIN_FLAG_CHECK) {
chain_store = X509_STORE_new();
if (chain_store == NULL)
goto err;
for (i = 0; i < sk_X509_num(cpk->chain); i++) {
x = sk_X509_value(cpk->chain, i);
if (!X509_STORE_add_cert(chain_store, x)) {
error = ERR_peek_last_error();
if (ERR_GET_LIB(error) != ERR_LIB_X509 ||
ERR_GET_REASON(error) != X509_R_CERT_ALREADY_IN_HASH_TABLE)
goto err;
ERR_clear_error();
}
}
if (!X509_STORE_add_cert(chain_store, cpk->x509)) {
error = ERR_peek_last_error();
if (ERR_GET_LIB(error) != ERR_LIB_X509 ||
ERR_GET_REASON(error) != X509_R_CERT_ALREADY_IN_HASH_TABLE)
goto err;
ERR_clear_error();
}
} else {
if (c->chain_store)
chain_store = c->chain_store;
else if (s)
chain_store = s->ctx->cert_store;
else
chain_store = ctx->cert_store;
if (flags & SSL_BUILD_CHAIN_FLAG_UNTRUSTED)
untrusted = cpk->chain;
}
xs_ctx = X509_STORE_CTX_new();
if (xs_ctx == NULL) {
SSLerr(SSL_F_SSL_BUILD_CERT_CHAIN, ERR_R_MALLOC_FAILURE);
goto err;
}
if (!X509_STORE_CTX_init(xs_ctx, chain_store, cpk->x509, untrusted)) {
SSLerr(SSL_F_SSL_BUILD_CERT_CHAIN, ERR_R_X509_LIB);
goto err;
}
X509_STORE_CTX_set_flags(xs_ctx,
c->cert_flags & SSL_CERT_FLAG_SUITEB_128_LOS);
i = X509_verify_cert(xs_ctx);
if (i <= 0 && flags & SSL_BUILD_CHAIN_FLAG_IGNORE_ERROR) {
if (flags & SSL_BUILD_CHAIN_FLAG_CLEAR_ERROR)
ERR_clear_error();
i = 1;
rv = 2;
}
if (i > 0)
chain = X509_STORE_CTX_get1_chain(xs_ctx);
if (i <= 0) {
SSLerr(SSL_F_SSL_BUILD_CERT_CHAIN, SSL_R_CERTIFICATE_VERIFY_FAILED);
i = X509_STORE_CTX_get_error(xs_ctx);
ERR_add_error_data(2, "Verify error:",
X509_verify_cert_error_string(i));
goto err;
}
x = sk_X509_shift(chain);
X509_free(x);
if (flags & SSL_BUILD_CHAIN_FLAG_NO_ROOT) {
if (sk_X509_num(chain) > 0) {
x = sk_X509_value(chain, sk_X509_num(chain) - 1);
if (X509_get_extension_flags(x) & EXFLAG_SS) {
x = sk_X509_pop(chain);
X509_free(x);
}
}
}
for (i = 0; i < sk_X509_num(chain); i++) {
x = sk_X509_value(chain, i);
rv = ssl_security_cert(s, ctx, x, 0, 0);
if (rv != 1) {
SSLerr(SSL_F_SSL_BUILD_CERT_CHAIN, rv);
sk_X509_pop_free(chain, X509_free);
rv = 0;
goto err;
}
}
sk_X509_pop_free(cpk->chain, X509_free);
cpk->chain = chain;
if (rv == 0)
rv = 1;
err:
if (flags & SSL_BUILD_CHAIN_FLAG_CHECK)
X509_STORE_free(chain_store);
X509_STORE_CTX_free(xs_ctx);
return rv;
}
int ssl_cert_set_cert_store(CERT *c, X509_STORE *store, int chain, int ref)
{
X509_STORE **pstore;
if (chain)
pstore = &c->chain_store;
else
pstore = &c->verify_store;
X509_STORE_free(*pstore);
*pstore = store;
if (ref && store)
X509_STORE_up_ref(store);
return 1;
}
static int ssl_security_default_callback(const SSL *s, const SSL_CTX *ctx,
int op, int bits, int nid, void *other,
void *ex)
{
int level, minbits;
static const int minbits_table[5] = { 80, 112, 128, 192, 256 };
if (ctx)
level = SSL_CTX_get_security_level(ctx);
else
level = SSL_get_security_level(s);
if (level <= 0) {
if (op == SSL_SECOP_TMP_DH && bits < 80)
return 0;
return 1;
}
if (level > 5)
level = 5;
minbits = minbits_table[level - 1];
switch (op) {
case SSL_SECOP_CIPHER_SUPPORTED:
case SSL_SECOP_CIPHER_SHARED:
case SSL_SECOP_CIPHER_CHECK:
{
const SSL_CIPHER *c = other;
if (bits < minbits)
return 0;
if (c->algorithm_auth & SSL_aNULL)
return 0;
if (c->algorithm_mac & SSL_MD5)
return 0;
if (minbits > 160 && c->algorithm_mac & SSL_SHA1)
return 0;
if (level >= 2 && c->algorithm_enc == SSL_RC4)
return 0;
if (level >= 3 && !(c->algorithm_mkey & (SSL_kEDH | SSL_kEECDH)))
return 0;
break;
}
case SSL_SECOP_VERSION:
if (!SSL_IS_DTLS(s)) {
if (nid <= SSL3_VERSION && level >= 2)
return 0;
if (nid <= TLS1_VERSION && level >= 3)
return 0;
if (nid <= TLS1_1_VERSION && level >= 4)
return 0;
} else {
if (DTLS_VERSION_LT(nid, DTLS1_2_VERSION) && level >= 4)
return 0;
}
break;
case SSL_SECOP_COMPRESSION:
if (level >= 2)
return 0;
break;
case SSL_SECOP_TICKET:
if (level >= 3)
return 0;
break;
default:
if (bits < minbits)
return 0;
}
return 1;
}
int ssl_security(const SSL *s, int op, int bits, int nid, void *other)
{
return s->cert->sec_cb(s, NULL, op, bits, nid, other, s->cert->sec_ex);
}
int ssl_ctx_security(const SSL_CTX *ctx, int op, int bits, int nid, void *other)
{
return ctx->cert->sec_cb(NULL, ctx, op, bits, nid, other,
ctx->cert->sec_ex);
}
