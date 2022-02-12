int SSL_get_ex_data_X509_STORE_CTX_idx(void)
{
static volatile int ssl_x509_store_ctx_idx = -1;
int got_write_lock = 0;
if (((size_t)&ssl_x509_store_ctx_idx &
(sizeof(ssl_x509_store_ctx_idx) - 1))
== 0) {
int ret;
if ((ret = ssl_x509_store_ctx_idx) < 0) {
CRYPTO_w_lock(CRYPTO_LOCK_SSL_CTX);
if ((ret = ssl_x509_store_ctx_idx) < 0) {
ret = ssl_x509_store_ctx_idx =
X509_STORE_CTX_get_ex_new_index(0,
"SSL for verify callback",
NULL, NULL, NULL);
}
CRYPTO_w_unlock(CRYPTO_LOCK_SSL_CTX);
}
return ret;
} else {
CRYPTO_r_lock(CRYPTO_LOCK_SSL_CTX);
if (ssl_x509_store_ctx_idx < 0) {
CRYPTO_r_unlock(CRYPTO_LOCK_SSL_CTX);
CRYPTO_w_lock(CRYPTO_LOCK_SSL_CTX);
got_write_lock = 1;
if (ssl_x509_store_ctx_idx < 0) {
ssl_x509_store_ctx_idx =
X509_STORE_CTX_get_ex_new_index(0,
"SSL for verify callback",
NULL, NULL, NULL);
}
}
if (got_write_lock)
CRYPTO_w_unlock(CRYPTO_LOCK_SSL_CTX);
else
CRYPTO_r_unlock(CRYPTO_LOCK_SSL_CTX);
return ssl_x509_store_ctx_idx;
}
}
void ssl_cert_set_default_md(CERT *cert)
{
#ifndef OPENSSL_NO_DSA
cert->pkeys[SSL_PKEY_DSA_SIGN].digest = EVP_sha1();
#endif
#ifndef OPENSSL_NO_RSA
cert->pkeys[SSL_PKEY_RSA_SIGN].digest = EVP_sha1();
cert->pkeys[SSL_PKEY_RSA_ENC].digest = EVP_sha1();
#endif
#ifndef OPENSSL_NO_ECDSA
cert->pkeys[SSL_PKEY_ECC].digest = EVP_sha1();
#endif
}
CERT *ssl_cert_new(void)
{
CERT *ret;
ret = (CERT *)OPENSSL_malloc(sizeof(CERT));
if (ret == NULL) {
SSLerr(SSL_F_SSL_CERT_NEW, ERR_R_MALLOC_FAILURE);
return (NULL);
}
memset(ret, 0, sizeof(CERT));
ret->key = &(ret->pkeys[SSL_PKEY_RSA_ENC]);
ret->references = 1;
ssl_cert_set_default_md(ret);
return (ret);
}
CERT *ssl_cert_dup(CERT *cert)
{
CERT *ret;
int i;
ret = (CERT *)OPENSSL_malloc(sizeof(CERT));
if (ret == NULL) {
SSLerr(SSL_F_SSL_CERT_DUP, ERR_R_MALLOC_FAILURE);
return (NULL);
}
memset(ret, 0, sizeof(CERT));
ret->key = &ret->pkeys[cert->key - &cert->pkeys[0]];
ret->valid = cert->valid;
ret->mask_k = cert->mask_k;
ret->mask_a = cert->mask_a;
ret->export_mask_k = cert->export_mask_k;
ret->export_mask_a = cert->export_mask_a;
#ifndef OPENSSL_NO_RSA
if (cert->rsa_tmp != NULL) {
RSA_up_ref(cert->rsa_tmp);
ret->rsa_tmp = cert->rsa_tmp;
}
ret->rsa_tmp_cb = cert->rsa_tmp_cb;
#endif
#ifndef OPENSSL_NO_DH
if (cert->dh_tmp != NULL) {
ret->dh_tmp = DHparams_dup(cert->dh_tmp);
if (ret->dh_tmp == NULL) {
SSLerr(SSL_F_SSL_CERT_DUP, ERR_R_DH_LIB);
goto err;
}
if (cert->dh_tmp->priv_key) {
BIGNUM *b = BN_dup(cert->dh_tmp->priv_key);
if (!b) {
SSLerr(SSL_F_SSL_CERT_DUP, ERR_R_BN_LIB);
goto err;
}
ret->dh_tmp->priv_key = b;
}
if (cert->dh_tmp->pub_key) {
BIGNUM *b = BN_dup(cert->dh_tmp->pub_key);
if (!b) {
SSLerr(SSL_F_SSL_CERT_DUP, ERR_R_BN_LIB);
goto err;
}
ret->dh_tmp->pub_key = b;
}
}
ret->dh_tmp_cb = cert->dh_tmp_cb;
#endif
#ifndef OPENSSL_NO_ECDH
if (cert->ecdh_tmp) {
ret->ecdh_tmp = EC_KEY_dup(cert->ecdh_tmp);
if (ret->ecdh_tmp == NULL) {
SSLerr(SSL_F_SSL_CERT_DUP, ERR_R_EC_LIB);
goto err;
}
}
ret->ecdh_tmp_cb = cert->ecdh_tmp_cb;
ret->ecdh_tmp_auto = cert->ecdh_tmp_auto;
#endif
for (i = 0; i < SSL_PKEY_NUM; i++) {
CERT_PKEY *cpk = cert->pkeys + i;
CERT_PKEY *rpk = ret->pkeys + i;
if (cpk->x509 != NULL) {
rpk->x509 = cpk->x509;
CRYPTO_add(&rpk->x509->references, 1, CRYPTO_LOCK_X509);
}
if (cpk->privatekey != NULL) {
rpk->privatekey = cpk->privatekey;
CRYPTO_add(&cpk->privatekey->references, 1, CRYPTO_LOCK_EVP_PKEY);
}
if (cpk->chain) {
rpk->chain = X509_chain_up_ref(cpk->chain);
if (!rpk->chain) {
SSLerr(SSL_F_SSL_CERT_DUP, ERR_R_MALLOC_FAILURE);
goto err;
}
}
rpk->valid_flags = 0;
#ifndef OPENSSL_NO_TLSEXT
if (cert->pkeys[i].serverinfo != NULL) {
ret->pkeys[i].serverinfo =
OPENSSL_malloc(cert->pkeys[i].serverinfo_length);
if (ret->pkeys[i].serverinfo == NULL) {
SSLerr(SSL_F_SSL_CERT_DUP, ERR_R_MALLOC_FAILURE);
return NULL;
}
ret->pkeys[i].serverinfo_length =
cert->pkeys[i].serverinfo_length;
memcpy(ret->pkeys[i].serverinfo,
cert->pkeys[i].serverinfo,
cert->pkeys[i].serverinfo_length);
}
#endif
}
ret->references = 1;
ssl_cert_set_default_md(ret);
ret->peer_sigalgs = NULL;
ret->peer_sigalgslen = 0;
if (cert->conf_sigalgs) {
ret->conf_sigalgs = OPENSSL_malloc(cert->conf_sigalgslen);
if (!ret->conf_sigalgs)
goto err;
memcpy(ret->conf_sigalgs, cert->conf_sigalgs, cert->conf_sigalgslen);
ret->conf_sigalgslen = cert->conf_sigalgslen;
} else
ret->conf_sigalgs = NULL;
if (cert->client_sigalgs) {
ret->client_sigalgs = OPENSSL_malloc(cert->client_sigalgslen);
if (!ret->client_sigalgs)
goto err;
memcpy(ret->client_sigalgs, cert->client_sigalgs,
cert->client_sigalgslen);
ret->client_sigalgslen = cert->client_sigalgslen;
} else
ret->client_sigalgs = NULL;
ret->shared_sigalgs = NULL;
if (cert->ctypes) {
ret->ctypes = OPENSSL_malloc(cert->ctype_num);
if (!ret->ctypes)
goto err;
memcpy(ret->ctypes, cert->ctypes, cert->ctype_num);
ret->ctype_num = cert->ctype_num;
}
ret->cert_flags = cert->cert_flags;
ret->cert_cb = cert->cert_cb;
ret->cert_cb_arg = cert->cert_cb_arg;
if (cert->verify_store) {
CRYPTO_add(&cert->verify_store->references, 1,
CRYPTO_LOCK_X509_STORE);
ret->verify_store = cert->verify_store;
}
if (cert->chain_store) {
CRYPTO_add(&cert->chain_store->references, 1, CRYPTO_LOCK_X509_STORE);
ret->chain_store = cert->chain_store;
}
ret->ciphers_raw = NULL;
#ifndef OPENSSL_NO_TLSEXT
if (!custom_exts_copy(&ret->cli_ext, &cert->cli_ext))
goto err;
if (!custom_exts_copy(&ret->srv_ext, &cert->srv_ext))
goto err;
#endif
return (ret);
#if !defined(OPENSSL_NO_DH) || !defined(OPENSSL_NO_ECDH)
err:
#endif
#ifndef OPENSSL_NO_RSA
if (ret->rsa_tmp != NULL)
RSA_free(ret->rsa_tmp);
#endif
#ifndef OPENSSL_NO_DH
if (ret->dh_tmp != NULL)
DH_free(ret->dh_tmp);
#endif
#ifndef OPENSSL_NO_ECDH
if (ret->ecdh_tmp != NULL)
EC_KEY_free(ret->ecdh_tmp);
#endif
#ifndef OPENSSL_NO_TLSEXT
custom_exts_free(&ret->cli_ext);
custom_exts_free(&ret->srv_ext);
#endif
ssl_cert_clear_certs(ret);
return NULL;
}
void ssl_cert_clear_certs(CERT *c)
{
int i;
if (c == NULL)
return;
for (i = 0; i < SSL_PKEY_NUM; i++) {
CERT_PKEY *cpk = c->pkeys + i;
if (cpk->x509) {
X509_free(cpk->x509);
cpk->x509 = NULL;
}
if (cpk->privatekey) {
EVP_PKEY_free(cpk->privatekey);
cpk->privatekey = NULL;
}
if (cpk->chain) {
sk_X509_pop_free(cpk->chain, X509_free);
cpk->chain = NULL;
}
#ifndef OPENSSL_NO_TLSEXT
if (cpk->serverinfo) {
OPENSSL_free(cpk->serverinfo);
cpk->serverinfo = NULL;
cpk->serverinfo_length = 0;
}
#endif
cpk->valid_flags &= CERT_PKEY_EXPLICIT_SIGN;
}
}
void ssl_cert_free(CERT *c)
{
int i;
if (c == NULL)
return;
i = CRYPTO_add(&c->references, -1, CRYPTO_LOCK_SSL_CERT);
#ifdef REF_PRINT
REF_PRINT("CERT", c);
#endif
if (i > 0)
return;
#ifdef REF_CHECK
if (i < 0) {
fprintf(stderr, "ssl_cert_free, bad reference count\n");
abort();
}
#endif
#ifndef OPENSSL_NO_RSA
if (c->rsa_tmp)
RSA_free(c->rsa_tmp);
#endif
#ifndef OPENSSL_NO_DH
if (c->dh_tmp)
DH_free(c->dh_tmp);
#endif
#ifndef OPENSSL_NO_ECDH
if (c->ecdh_tmp)
EC_KEY_free(c->ecdh_tmp);
#endif
ssl_cert_clear_certs(c);
if (c->peer_sigalgs)
OPENSSL_free(c->peer_sigalgs);
if (c->conf_sigalgs)
OPENSSL_free(c->conf_sigalgs);
if (c->client_sigalgs)
OPENSSL_free(c->client_sigalgs);
if (c->shared_sigalgs)
OPENSSL_free(c->shared_sigalgs);
if (c->ctypes)
OPENSSL_free(c->ctypes);
if (c->verify_store)
X509_STORE_free(c->verify_store);
if (c->chain_store)
X509_STORE_free(c->chain_store);
if (c->ciphers_raw)
OPENSSL_free(c->ciphers_raw);
#ifndef OPENSSL_NO_TLSEXT
custom_exts_free(&c->cli_ext);
custom_exts_free(&c->srv_ext);
#endif
OPENSSL_free(c);
}
int ssl_cert_inst(CERT **o)
{
if (o == NULL) {
SSLerr(SSL_F_SSL_CERT_INST, ERR_R_PASSED_NULL_PARAMETER);
return (0);
}
if (*o == NULL) {
if ((*o = ssl_cert_new()) == NULL) {
SSLerr(SSL_F_SSL_CERT_INST, ERR_R_MALLOC_FAILURE);
return (0);
}
}
return (1);
}
int ssl_cert_add0_chain_cert(CERT *c, X509 *x)
{
CERT_PKEY *cpk = c->key;
if (!cpk)
return 0;
if (!cpk->chain)
cpk->chain = sk_X509_new_null();
if (!cpk->chain || !sk_X509_push(cpk->chain, x))
return 0;
return 1;
}
int ssl_cert_add1_chain_cert(CERT *c, X509 *x)
{
if (!ssl_cert_add0_chain_cert(c, x))
return 0;
CRYPTO_add(&x->references, 1, CRYPTO_LOCK_X509);
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
SESS_CERT *ssl_sess_cert_new(void)
{
SESS_CERT *ret;
ret = OPENSSL_malloc(sizeof *ret);
if (ret == NULL) {
SSLerr(SSL_F_SSL_SESS_CERT_NEW, ERR_R_MALLOC_FAILURE);
return NULL;
}
memset(ret, 0, sizeof *ret);
ret->peer_key = &(ret->peer_pkeys[SSL_PKEY_RSA_ENC]);
ret->references = 1;
return ret;
}
void ssl_sess_cert_free(SESS_CERT *sc)
{
int i;
if (sc == NULL)
return;
i = CRYPTO_add(&sc->references, -1, CRYPTO_LOCK_SSL_SESS_CERT);
#ifdef REF_PRINT
REF_PRINT("SESS_CERT", sc);
#endif
if (i > 0)
return;
#ifdef REF_CHECK
if (i < 0) {
fprintf(stderr, "ssl_sess_cert_free, bad reference count\n");
abort();
}
#endif
if (sc->cert_chain != NULL)
sk_X509_pop_free(sc->cert_chain, X509_free);
for (i = 0; i < SSL_PKEY_NUM; i++) {
if (sc->peer_pkeys[i].x509 != NULL)
X509_free(sc->peer_pkeys[i].x509);
#if 0
if (sc->peer_pkeys[i].privatekey != NULL)
EVP_PKEY_free(sc->peer_pkeys[i].privatekey);
#endif
}
#ifndef OPENSSL_NO_RSA
if (sc->peer_rsa_tmp != NULL)
RSA_free(sc->peer_rsa_tmp);
#endif
#ifndef OPENSSL_NO_DH
if (sc->peer_dh_tmp != NULL)
DH_free(sc->peer_dh_tmp);
#endif
#ifndef OPENSSL_NO_ECDH
if (sc->peer_ecdh_tmp != NULL)
EC_KEY_free(sc->peer_ecdh_tmp);
#endif
OPENSSL_free(sc);
}
int ssl_set_peer_cert_type(SESS_CERT *sc, int type)
{
sc->peer_cert_type = type;
return (1);
}
int SSL_add_client_CA(SSL *ssl, X509 *x)
{
return (add_client_CA(&(ssl->client_CA), x));
}
int SSL_CTX_add_client_CA(SSL_CTX *ctx, X509 *x)
{
return (add_client_CA(&(ctx->client_CA), x));
}
static int xname_cmp(const X509_NAME *const *a, const X509_NAME *const *b)
{
return (X509_NAME_cmp(*a, *b));
}
static int ssl_add_cert_to_buf(BUF_MEM *buf, unsigned long *l, X509 *x)
{
int n;
unsigned char *p;
n = i2d_X509(x, NULL);
if (!BUF_MEM_grow_clean(buf, (int)(n + (*l) + 3))) {
SSLerr(SSL_F_SSL_ADD_CERT_TO_BUF, ERR_R_BUF_LIB);
return 0;
}
p = (unsigned char *)&(buf->data[*l]);
l2n3(n, p);
i2d_X509(x, &p);
*l += n + 3;
return 1;
}
int ssl_add_cert_chain(SSL *s, CERT_PKEY *cpk, unsigned long *l)
{
BUF_MEM *buf = s->init_buf;
int no_chain;
int i;
X509 *x;
STACK_OF(X509) *extra_certs;
X509_STORE *chain_store;
if (cpk)
x = cpk->x509;
else
x = NULL;
if (s->cert->chain_store)
chain_store = s->cert->chain_store;
else
chain_store = s->ctx->cert_store;
if (cpk && cpk->chain)
extra_certs = cpk->chain;
else
extra_certs = s->ctx->extra_certs;
if ((s->mode & SSL_MODE_NO_AUTO_CHAIN) || extra_certs)
no_chain = 1;
else
no_chain = 0;
if (!BUF_MEM_grow_clean(buf, 10)) {
SSLerr(SSL_F_SSL_ADD_CERT_CHAIN, ERR_R_BUF_LIB);
return 0;
}
if (x != NULL) {
if (no_chain) {
if (!ssl_add_cert_to_buf(buf, l, x))
return 0;
} else {
X509_STORE_CTX xs_ctx;
if (!X509_STORE_CTX_init(&xs_ctx, chain_store, x, NULL)) {
SSLerr(SSL_F_SSL_ADD_CERT_CHAIN, ERR_R_X509_LIB);
return (0);
}
X509_verify_cert(&xs_ctx);
ERR_clear_error();
for (i = 0; i < sk_X509_num(xs_ctx.chain); i++) {
x = sk_X509_value(xs_ctx.chain, i);
if (!ssl_add_cert_to_buf(buf, l, x)) {
X509_STORE_CTX_cleanup(&xs_ctx);
return 0;
}
}
X509_STORE_CTX_cleanup(&xs_ctx);
}
}
for (i = 0; i < sk_X509_num(extra_certs); i++) {
x = sk_X509_value(extra_certs, i);
if (!ssl_add_cert_to_buf(buf, l, x))
return 0;
}
return 1;
}
int ssl_build_cert_chain(CERT *c, X509_STORE *chain_store, int flags)
{
CERT_PKEY *cpk = c->key;
X509_STORE_CTX xs_ctx;
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
if (!chain_store)
goto err;
for (i = 0; i < sk_X509_num(cpk->chain); i++) {
x = sk_X509_value(cpk->chain, i);
if (!X509_STORE_add_cert(chain_store, x)) {
error = ERR_peek_last_error();
if (ERR_GET_LIB(error) != ERR_LIB_X509 ||
ERR_GET_REASON(error) !=
X509_R_CERT_ALREADY_IN_HASH_TABLE)
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
if (flags & SSL_BUILD_CHAIN_FLAG_UNTRUSTED)
untrusted = cpk->chain;
}
if (!X509_STORE_CTX_init(&xs_ctx, chain_store, cpk->x509, untrusted)) {
SSLerr(SSL_F_SSL_BUILD_CERT_CHAIN, ERR_R_X509_LIB);
goto err;
}
X509_STORE_CTX_set_flags(&xs_ctx,
c->cert_flags & SSL_CERT_FLAG_SUITEB_128_LOS);
i = X509_verify_cert(&xs_ctx);
if (i <= 0 && flags & SSL_BUILD_CHAIN_FLAG_IGNORE_ERROR) {
if (flags & SSL_BUILD_CHAIN_FLAG_CLEAR_ERROR)
ERR_clear_error();
i = 1;
rv = 2;
}
if (i > 0)
chain = X509_STORE_CTX_get1_chain(&xs_ctx);
if (i <= 0) {
SSLerr(SSL_F_SSL_BUILD_CERT_CHAIN, SSL_R_CERTIFICATE_VERIFY_FAILED);
i = X509_STORE_CTX_get_error(&xs_ctx);
ERR_add_error_data(2, "Verify error:",
X509_verify_cert_error_string(i));
X509_STORE_CTX_cleanup(&xs_ctx);
goto err;
}
X509_STORE_CTX_cleanup(&xs_ctx);
if (cpk->chain)
sk_X509_pop_free(cpk->chain, X509_free);
x = sk_X509_shift(chain);
X509_free(x);
if (flags & SSL_BUILD_CHAIN_FLAG_NO_ROOT) {
if (sk_X509_num(chain) > 0) {
x = sk_X509_value(chain, sk_X509_num(chain) - 1);
X509_check_purpose(x, -1, 0);
if (x->ex_flags & EXFLAG_SS) {
x = sk_X509_pop(chain);
X509_free(x);
}
}
}
cpk->chain = chain;
if (rv == 0)
rv = 1;
err:
if (flags & SSL_BUILD_CHAIN_FLAG_CHECK)
X509_STORE_free(chain_store);
return rv;
}
int ssl_cert_set_cert_store(CERT *c, X509_STORE *store, int chain, int ref)
{
X509_STORE **pstore;
if (chain)
pstore = &c->chain_store;
else
pstore = &c->verify_store;
if (*pstore)
X509_STORE_free(*pstore);
*pstore = store;
if (ref && store)
CRYPTO_add(&store->references, 1, CRYPTO_LOCK_X509_STORE);
return 1;
}
