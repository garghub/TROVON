static int cipher_compare(const void *a, const void *b)
{
const SSL_CIPHER *ap = (const SSL_CIPHER *)a;
const SSL_CIPHER *bp = (const SSL_CIPHER *)b;
return ap->id - bp->id;
}
void ssl_sort_cipher_list(void)
{
qsort(ssl3_ciphers, OSSL_NELEM(ssl3_ciphers), sizeof ssl3_ciphers[0],
cipher_compare);
}
long ssl3_default_timeout(void)
{
return (60 * 60 * 2);
}
int ssl3_num_ciphers(void)
{
return (SSL3_NUM_CIPHERS);
}
const SSL_CIPHER *ssl3_get_cipher(unsigned int u)
{
if (u < SSL3_NUM_CIPHERS)
return (&(ssl3_ciphers[SSL3_NUM_CIPHERS - 1 - u]));
else
return (NULL);
}
int ssl3_set_handshake_header(SSL *s, int htype, unsigned long len)
{
unsigned char *p = (unsigned char *)s->init_buf->data;
*(p++) = htype;
l2n3(len, p);
s->init_num = (int)len + SSL3_HM_HEADER_LENGTH;
s->init_off = 0;
return 1;
}
int ssl3_handshake_write(SSL *s)
{
return ssl3_do_write(s, SSL3_RT_HANDSHAKE);
}
int ssl3_new(SSL *s)
{
SSL3_STATE *s3;
if ((s3 = OPENSSL_zalloc(sizeof(*s3))) == NULL)
goto err;
s->s3 = s3;
#ifndef OPENSSL_NO_SRP
if (!SSL_SRP_CTX_init(s))
goto err;
#endif
s->method->ssl_clear(s);
return (1);
err:
return (0);
}
void ssl3_free(SSL *s)
{
if (s == NULL || s->s3 == NULL)
return;
ssl3_cleanup_key_block(s);
#if !defined(OPENSSL_NO_EC) || !defined(OPENSSL_NO_DH)
EVP_PKEY_free(s->s3->peer_tmp);
s->s3->peer_tmp = NULL;
EVP_PKEY_free(s->s3->tmp.pkey);
s->s3->tmp.pkey = NULL;
#endif
sk_X509_NAME_pop_free(s->s3->tmp.ca_names, X509_NAME_free);
OPENSSL_free(s->s3->tmp.ciphers_raw);
OPENSSL_clear_free(s->s3->tmp.pms, s->s3->tmp.pmslen);
OPENSSL_free(s->s3->tmp.peer_sigalgs);
ssl3_free_digest_list(s);
OPENSSL_free(s->s3->alpn_selected);
OPENSSL_free(s->s3->alpn_proposed);
#ifndef OPENSSL_NO_SRP
SSL_SRP_CTX_free(s);
#endif
OPENSSL_clear_free(s->s3, sizeof(*s->s3));
s->s3 = NULL;
}
void ssl3_clear(SSL *s)
{
ssl3_cleanup_key_block(s);
sk_X509_NAME_pop_free(s->s3->tmp.ca_names, X509_NAME_free);
OPENSSL_free(s->s3->tmp.ciphers_raw);
OPENSSL_clear_free(s->s3->tmp.pms, s->s3->tmp.pmslen);
OPENSSL_free(s->s3->tmp.peer_sigalgs);
#if !defined(OPENSSL_NO_EC) || !defined(OPENSSL_NO_DH)
EVP_PKEY_free(s->s3->tmp.pkey);
EVP_PKEY_free(s->s3->peer_tmp);
#endif
ssl3_free_digest_list(s);
OPENSSL_free(s->s3->alpn_selected);
OPENSSL_free(s->s3->alpn_proposed);
memset(s->s3, 0, sizeof(*s->s3));
ssl_free_wbio_buffer(s);
s->version = SSL3_VERSION;
#if !defined(OPENSSL_NO_NEXTPROTONEG)
OPENSSL_free(s->next_proto_negotiated);
s->next_proto_negotiated = NULL;
s->next_proto_negotiated_len = 0;
#endif
}
static char *srp_password_from_info_cb(SSL *s, void *arg)
{
return OPENSSL_strdup(s->srp_ctx.info);
}
long ssl3_ctrl(SSL *s, int cmd, long larg, void *parg)
{
int ret = 0;
switch (cmd) {
case SSL_CTRL_GET_CLIENT_CERT_REQUEST:
break;
case SSL_CTRL_GET_NUM_RENEGOTIATIONS:
ret = s->s3->num_renegotiations;
break;
case SSL_CTRL_CLEAR_NUM_RENEGOTIATIONS:
ret = s->s3->num_renegotiations;
s->s3->num_renegotiations = 0;
break;
case SSL_CTRL_GET_TOTAL_RENEGOTIATIONS:
ret = s->s3->total_renegotiations;
break;
case SSL_CTRL_GET_FLAGS:
ret = (int)(s->s3->flags);
break;
#ifndef OPENSSL_NO_DH
case SSL_CTRL_SET_TMP_DH:
{
DH *dh = (DH *)parg;
EVP_PKEY *pkdh = NULL;
if (dh == NULL) {
SSLerr(SSL_F_SSL3_CTRL, ERR_R_PASSED_NULL_PARAMETER);
return (ret);
}
pkdh = ssl_dh_to_pkey(dh);
if (pkdh == NULL) {
SSLerr(SSL_F_SSL3_CTRL, ERR_R_MALLOC_FAILURE);
return 0;
}
if (!ssl_security(s, SSL_SECOP_TMP_DH,
EVP_PKEY_security_bits(pkdh), 0, pkdh)) {
SSLerr(SSL_F_SSL3_CTRL, SSL_R_DH_KEY_TOO_SMALL);
EVP_PKEY_free(pkdh);
return ret;
}
EVP_PKEY_free(s->cert->dh_tmp);
s->cert->dh_tmp = pkdh;
ret = 1;
}
break;
case SSL_CTRL_SET_TMP_DH_CB:
{
SSLerr(SSL_F_SSL3_CTRL, ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED);
return (ret);
}
case SSL_CTRL_SET_DH_AUTO:
s->cert->dh_tmp_auto = larg;
return 1;
#endif
#ifndef OPENSSL_NO_EC
case SSL_CTRL_SET_TMP_ECDH:
{
const EC_GROUP *group = NULL;
int nid;
if (parg == NULL) {
SSLerr(SSL_F_SSL3_CTRL, ERR_R_PASSED_NULL_PARAMETER);
return 0;
}
group = EC_KEY_get0_group((const EC_KEY *)parg);
if (group == NULL) {
SSLerr(SSL_F_SSL3_CTRL, EC_R_MISSING_PARAMETERS);
return 0;
}
nid = EC_GROUP_get_curve_name(group);
if (nid == NID_undef)
return 0;
return tls1_set_curves(&s->tlsext_ellipticcurvelist,
&s->tlsext_ellipticcurvelist_length,
&nid, 1);
}
break;
#endif
case SSL_CTRL_SET_TLSEXT_HOSTNAME:
if (larg == TLSEXT_NAMETYPE_host_name) {
size_t len;
OPENSSL_free(s->tlsext_hostname);
s->tlsext_hostname = NULL;
ret = 1;
if (parg == NULL)
break;
len = strlen((char *)parg);
if (len == 0 || len > TLSEXT_MAXLEN_host_name) {
SSLerr(SSL_F_SSL3_CTRL, SSL_R_SSL3_EXT_INVALID_SERVERNAME);
return 0;
}
if ((s->tlsext_hostname = OPENSSL_strdup((char *)parg)) == NULL) {
SSLerr(SSL_F_SSL3_CTRL, ERR_R_INTERNAL_ERROR);
return 0;
}
} else {
SSLerr(SSL_F_SSL3_CTRL, SSL_R_SSL3_EXT_INVALID_SERVERNAME_TYPE);
return 0;
}
break;
case SSL_CTRL_SET_TLSEXT_DEBUG_ARG:
s->tlsext_debug_arg = parg;
ret = 1;
break;
case SSL_CTRL_GET_TLSEXT_STATUS_REQ_TYPE:
ret = s->tlsext_status_type;
break;
case SSL_CTRL_SET_TLSEXT_STATUS_REQ_TYPE:
s->tlsext_status_type = larg;
ret = 1;
break;
case SSL_CTRL_GET_TLSEXT_STATUS_REQ_EXTS:
*(STACK_OF(X509_EXTENSION) **)parg = s->tlsext_ocsp_exts;
ret = 1;
break;
case SSL_CTRL_SET_TLSEXT_STATUS_REQ_EXTS:
s->tlsext_ocsp_exts = parg;
ret = 1;
break;
case SSL_CTRL_GET_TLSEXT_STATUS_REQ_IDS:
*(STACK_OF(OCSP_RESPID) **)parg = s->tlsext_ocsp_ids;
ret = 1;
break;
case SSL_CTRL_SET_TLSEXT_STATUS_REQ_IDS:
s->tlsext_ocsp_ids = parg;
ret = 1;
break;
case SSL_CTRL_GET_TLSEXT_STATUS_REQ_OCSP_RESP:
*(unsigned char **)parg = s->tlsext_ocsp_resp;
return s->tlsext_ocsp_resplen;
case SSL_CTRL_SET_TLSEXT_STATUS_REQ_OCSP_RESP:
OPENSSL_free(s->tlsext_ocsp_resp);
s->tlsext_ocsp_resp = parg;
s->tlsext_ocsp_resplen = larg;
ret = 1;
break;
#ifndef OPENSSL_NO_HEARTBEATS
case SSL_CTRL_DTLS_EXT_SEND_HEARTBEAT:
if (SSL_IS_DTLS(s))
ret = dtls1_heartbeat(s);
break;
case SSL_CTRL_GET_DTLS_EXT_HEARTBEAT_PENDING:
if (SSL_IS_DTLS(s))
ret = s->tlsext_hb_pending;
break;
case SSL_CTRL_SET_DTLS_EXT_HEARTBEAT_NO_REQUESTS:
if (SSL_IS_DTLS(s)) {
if (larg)
s->tlsext_heartbeat |= SSL_DTLSEXT_HB_DONT_RECV_REQUESTS;
else
s->tlsext_heartbeat &= ~SSL_DTLSEXT_HB_DONT_RECV_REQUESTS;
ret = 1;
}
break;
#endif
case SSL_CTRL_CHAIN:
if (larg)
return ssl_cert_set1_chain(s, NULL, (STACK_OF(X509) *)parg);
else
return ssl_cert_set0_chain(s, NULL, (STACK_OF(X509) *)parg);
case SSL_CTRL_CHAIN_CERT:
if (larg)
return ssl_cert_add1_chain_cert(s, NULL, (X509 *)parg);
else
return ssl_cert_add0_chain_cert(s, NULL, (X509 *)parg);
case SSL_CTRL_GET_CHAIN_CERTS:
*(STACK_OF(X509) **)parg = s->cert->key->chain;
break;
case SSL_CTRL_SELECT_CURRENT_CERT:
return ssl_cert_select_current(s->cert, (X509 *)parg);
case SSL_CTRL_SET_CURRENT_CERT:
if (larg == SSL_CERT_SET_SERVER) {
CERT_PKEY *cpk;
const SSL_CIPHER *cipher;
if (!s->server)
return 0;
cipher = s->s3->tmp.new_cipher;
if (!cipher)
return 0;
if (cipher->algorithm_auth & (SSL_aNULL | SSL_aSRP))
return 2;
cpk = ssl_get_server_send_pkey(s);
if (!cpk)
return 0;
s->cert->key = cpk;
return 1;
}
return ssl_cert_set_current(s->cert, larg);
#ifndef OPENSSL_NO_EC
case SSL_CTRL_GET_CURVES:
{
unsigned char *clist;
size_t clistlen;
if (!s->session)
return 0;
clist = s->session->tlsext_ellipticcurvelist;
clistlen = s->session->tlsext_ellipticcurvelist_length / 2;
if (parg) {
size_t i;
int *cptr = parg;
unsigned int cid, nid;
for (i = 0; i < clistlen; i++) {
n2s(clist, cid);
nid = tls1_ec_curve_id2nid(cid, NULL);
if (nid != 0)
cptr[i] = nid;
else
cptr[i] = TLSEXT_nid_unknown | cid;
}
}
return (int)clistlen;
}
case SSL_CTRL_SET_CURVES:
return tls1_set_curves(&s->tlsext_ellipticcurvelist,
&s->tlsext_ellipticcurvelist_length, parg, larg);
case SSL_CTRL_SET_CURVES_LIST:
return tls1_set_curves_list(&s->tlsext_ellipticcurvelist,
&s->tlsext_ellipticcurvelist_length, parg);
case SSL_CTRL_GET_SHARED_CURVE:
return tls1_shared_curve(s, larg);
#endif
case SSL_CTRL_SET_SIGALGS:
return tls1_set_sigalgs(s->cert, parg, larg, 0);
case SSL_CTRL_SET_SIGALGS_LIST:
return tls1_set_sigalgs_list(s->cert, parg, 0);
case SSL_CTRL_SET_CLIENT_SIGALGS:
return tls1_set_sigalgs(s->cert, parg, larg, 1);
case SSL_CTRL_SET_CLIENT_SIGALGS_LIST:
return tls1_set_sigalgs_list(s->cert, parg, 1);
case SSL_CTRL_GET_CLIENT_CERT_TYPES:
{
const unsigned char **pctype = parg;
if (s->server || !s->s3->tmp.cert_req)
return 0;
if (s->cert->ctypes) {
if (pctype)
*pctype = s->cert->ctypes;
return (int)s->cert->ctype_num;
}
if (pctype)
*pctype = (unsigned char *)s->s3->tmp.ctype;
return s->s3->tmp.ctype_num;
}
case SSL_CTRL_SET_CLIENT_CERT_TYPES:
if (!s->server)
return 0;
return ssl3_set_req_cert_type(s->cert, parg, larg);
case SSL_CTRL_BUILD_CERT_CHAIN:
return ssl_build_cert_chain(s, NULL, larg);
case SSL_CTRL_SET_VERIFY_CERT_STORE:
return ssl_cert_set_cert_store(s->cert, parg, 0, larg);
case SSL_CTRL_SET_CHAIN_CERT_STORE:
return ssl_cert_set_cert_store(s->cert, parg, 1, larg);
case SSL_CTRL_GET_PEER_SIGNATURE_NID:
if (SSL_USE_SIGALGS(s)) {
if (s->session) {
const EVP_MD *sig;
sig = s->s3->tmp.peer_md;
if (sig) {
*(int *)parg = EVP_MD_type(sig);
return 1;
}
}
return 0;
}
else
return 0;
case SSL_CTRL_GET_SERVER_TMP_KEY:
#if !defined(OPENSSL_NO_DH) || !defined(OPENSSL_NO_EC)
if (s->server || s->session == NULL || s->s3->peer_tmp == NULL) {
return 0;
} else {
EVP_PKEY_up_ref(s->s3->peer_tmp);
*(EVP_PKEY **)parg = s->s3->peer_tmp;
return 1;
}
#else
return 0;
#endif
#ifndef OPENSSL_NO_EC
case SSL_CTRL_GET_EC_POINT_FORMATS:
{
SSL_SESSION *sess = s->session;
const unsigned char **pformat = parg;
if (!sess || !sess->tlsext_ecpointformatlist)
return 0;
*pformat = sess->tlsext_ecpointformatlist;
return (int)sess->tlsext_ecpointformatlist_length;
}
#endif
default:
break;
}
return (ret);
}
long ssl3_callback_ctrl(SSL *s, int cmd, void (*fp) (void))
{
int ret = 0;
switch (cmd) {
#ifndef OPENSSL_NO_DH
case SSL_CTRL_SET_TMP_DH_CB:
{
s->cert->dh_tmp_cb = (DH *(*)(SSL *, int, int))fp;
}
break;
#endif
case SSL_CTRL_SET_TLSEXT_DEBUG_CB:
s->tlsext_debug_cb = (void (*)(SSL *, int, int,
const unsigned char *, int, void *))fp;
break;
case SSL_CTRL_SET_NOT_RESUMABLE_SESS_CB:
{
s->not_resumable_session_cb = (int (*)(SSL *, int))fp;
}
break;
default:
break;
}
return (ret);
}
long ssl3_ctx_ctrl(SSL_CTX *ctx, int cmd, long larg, void *parg)
{
switch (cmd) {
#ifndef OPENSSL_NO_DH
case SSL_CTRL_SET_TMP_DH:
{
DH *dh = (DH *)parg;
EVP_PKEY *pkdh = NULL;
if (dh == NULL) {
SSLerr(SSL_F_SSL3_CTX_CTRL, ERR_R_PASSED_NULL_PARAMETER);
return 0;
}
pkdh = ssl_dh_to_pkey(dh);
if (pkdh == NULL) {
SSLerr(SSL_F_SSL3_CTX_CTRL, ERR_R_MALLOC_FAILURE);
return 0;
}
if (!ssl_ctx_security(ctx, SSL_SECOP_TMP_DH,
EVP_PKEY_security_bits(pkdh), 0, pkdh)) {
SSLerr(SSL_F_SSL3_CTX_CTRL, SSL_R_DH_KEY_TOO_SMALL);
EVP_PKEY_free(pkdh);
return 1;
}
EVP_PKEY_free(ctx->cert->dh_tmp);
ctx->cert->dh_tmp = pkdh;
return 1;
}
case SSL_CTRL_SET_TMP_DH_CB:
{
SSLerr(SSL_F_SSL3_CTX_CTRL, ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED);
return (0);
}
case SSL_CTRL_SET_DH_AUTO:
ctx->cert->dh_tmp_auto = larg;
return 1;
#endif
#ifndef OPENSSL_NO_EC
case SSL_CTRL_SET_TMP_ECDH:
{
const EC_GROUP *group = NULL;
int nid;
if (parg == NULL) {
SSLerr(SSL_F_SSL3_CTX_CTRL, ERR_R_PASSED_NULL_PARAMETER);
return 0;
}
group = EC_KEY_get0_group((const EC_KEY *)parg);
if (group == NULL) {
SSLerr(SSL_F_SSL3_CTX_CTRL, EC_R_MISSING_PARAMETERS);
return 0;
}
nid = EC_GROUP_get_curve_name(group);
if (nid == NID_undef)
return 0;
return tls1_set_curves(&ctx->tlsext_ellipticcurvelist,
&ctx->tlsext_ellipticcurvelist_length,
&nid, 1);
}
#endif
case SSL_CTRL_SET_TLSEXT_SERVERNAME_ARG:
ctx->tlsext_servername_arg = parg;
break;
case SSL_CTRL_SET_TLSEXT_TICKET_KEYS:
case SSL_CTRL_GET_TLSEXT_TICKET_KEYS:
{
unsigned char *keys = parg;
long tlsext_tick_keylen = (sizeof(ctx->tlsext_tick_key_name) +
sizeof(ctx->tlsext_tick_hmac_key) +
sizeof(ctx->tlsext_tick_aes_key));
if (keys == NULL)
return tlsext_tick_keylen;
if (larg != tlsext_tick_keylen) {
SSLerr(SSL_F_SSL3_CTX_CTRL, SSL_R_INVALID_TICKET_KEYS_LENGTH);
return 0;
}
if (cmd == SSL_CTRL_SET_TLSEXT_TICKET_KEYS) {
memcpy(ctx->tlsext_tick_key_name, keys,
sizeof(ctx->tlsext_tick_key_name));
memcpy(ctx->tlsext_tick_hmac_key,
keys + sizeof(ctx->tlsext_tick_key_name),
sizeof(ctx->tlsext_tick_hmac_key));
memcpy(ctx->tlsext_tick_aes_key,
keys + sizeof(ctx->tlsext_tick_key_name) +
sizeof(ctx->tlsext_tick_hmac_key),
sizeof(ctx->tlsext_tick_aes_key));
} else {
memcpy(keys, ctx->tlsext_tick_key_name,
sizeof(ctx->tlsext_tick_key_name));
memcpy(keys + sizeof(ctx->tlsext_tick_key_name),
ctx->tlsext_tick_hmac_key,
sizeof(ctx->tlsext_tick_hmac_key));
memcpy(keys + sizeof(ctx->tlsext_tick_key_name) +
sizeof(ctx->tlsext_tick_hmac_key),
ctx->tlsext_tick_aes_key,
sizeof(ctx->tlsext_tick_aes_key));
}
return 1;
}
case SSL_CTRL_GET_TLSEXT_STATUS_REQ_TYPE:
return ctx->tlsext_status_type;
case SSL_CTRL_SET_TLSEXT_STATUS_REQ_TYPE:
ctx->tlsext_status_type = larg;
break;
case SSL_CTRL_SET_TLSEXT_STATUS_REQ_CB_ARG:
ctx->tlsext_status_arg = parg;
return 1;
case SSL_CTRL_GET_TLSEXT_STATUS_REQ_CB_ARG:
*(void**)parg = ctx->tlsext_status_arg;
break;
case SSL_CTRL_GET_TLSEXT_STATUS_REQ_CB:
*(int (**)(SSL*, void*))parg = ctx->tlsext_status_cb;
break;
#ifndef OPENSSL_NO_SRP
case SSL_CTRL_SET_TLS_EXT_SRP_USERNAME:
ctx->srp_ctx.srp_Mask |= SSL_kSRP;
OPENSSL_free(ctx->srp_ctx.login);
ctx->srp_ctx.login = NULL;
if (parg == NULL)
break;
if (strlen((const char *)parg) > 255 || strlen((const char *)parg) < 1) {
SSLerr(SSL_F_SSL3_CTX_CTRL, SSL_R_INVALID_SRP_USERNAME);
return 0;
}
if ((ctx->srp_ctx.login = OPENSSL_strdup((char *)parg)) == NULL) {
SSLerr(SSL_F_SSL3_CTX_CTRL, ERR_R_INTERNAL_ERROR);
return 0;
}
break;
case SSL_CTRL_SET_TLS_EXT_SRP_PASSWORD:
ctx->srp_ctx.SRP_give_srp_client_pwd_callback =
srp_password_from_info_cb;
ctx->srp_ctx.info = parg;
break;
case SSL_CTRL_SET_SRP_ARG:
ctx->srp_ctx.srp_Mask |= SSL_kSRP;
ctx->srp_ctx.SRP_cb_arg = parg;
break;
case SSL_CTRL_SET_TLS_EXT_SRP_STRENGTH:
ctx->srp_ctx.strength = larg;
break;
#endif
#ifndef OPENSSL_NO_EC
case SSL_CTRL_SET_CURVES:
return tls1_set_curves(&ctx->tlsext_ellipticcurvelist,
&ctx->tlsext_ellipticcurvelist_length,
parg, larg);
case SSL_CTRL_SET_CURVES_LIST:
return tls1_set_curves_list(&ctx->tlsext_ellipticcurvelist,
&ctx->tlsext_ellipticcurvelist_length,
parg);
#endif
case SSL_CTRL_SET_SIGALGS:
return tls1_set_sigalgs(ctx->cert, parg, larg, 0);
case SSL_CTRL_SET_SIGALGS_LIST:
return tls1_set_sigalgs_list(ctx->cert, parg, 0);
case SSL_CTRL_SET_CLIENT_SIGALGS:
return tls1_set_sigalgs(ctx->cert, parg, larg, 1);
case SSL_CTRL_SET_CLIENT_SIGALGS_LIST:
return tls1_set_sigalgs_list(ctx->cert, parg, 1);
case SSL_CTRL_SET_CLIENT_CERT_TYPES:
return ssl3_set_req_cert_type(ctx->cert, parg, larg);
case SSL_CTRL_BUILD_CERT_CHAIN:
return ssl_build_cert_chain(NULL, ctx, larg);
case SSL_CTRL_SET_VERIFY_CERT_STORE:
return ssl_cert_set_cert_store(ctx->cert, parg, 0, larg);
case SSL_CTRL_SET_CHAIN_CERT_STORE:
return ssl_cert_set_cert_store(ctx->cert, parg, 1, larg);
case SSL_CTRL_EXTRA_CHAIN_CERT:
if (ctx->extra_certs == NULL) {
if ((ctx->extra_certs = sk_X509_new_null()) == NULL) {
SSLerr(SSL_F_SSL3_CTX_CTRL, ERR_R_MALLOC_FAILURE);
return 0;
}
}
if (!sk_X509_push(ctx->extra_certs, (X509 *)parg)) {
SSLerr(SSL_F_SSL3_CTX_CTRL, ERR_R_MALLOC_FAILURE);
return 0;
}
break;
case SSL_CTRL_GET_EXTRA_CHAIN_CERTS:
if (ctx->extra_certs == NULL && larg == 0)
*(STACK_OF(X509) **)parg = ctx->cert->key->chain;
else
*(STACK_OF(X509) **)parg = ctx->extra_certs;
break;
case SSL_CTRL_CLEAR_EXTRA_CHAIN_CERTS:
sk_X509_pop_free(ctx->extra_certs, X509_free);
ctx->extra_certs = NULL;
break;
case SSL_CTRL_CHAIN:
if (larg)
return ssl_cert_set1_chain(NULL, ctx, (STACK_OF(X509) *)parg);
else
return ssl_cert_set0_chain(NULL, ctx, (STACK_OF(X509) *)parg);
case SSL_CTRL_CHAIN_CERT:
if (larg)
return ssl_cert_add1_chain_cert(NULL, ctx, (X509 *)parg);
else
return ssl_cert_add0_chain_cert(NULL, ctx, (X509 *)parg);
case SSL_CTRL_GET_CHAIN_CERTS:
*(STACK_OF(X509) **)parg = ctx->cert->key->chain;
break;
case SSL_CTRL_SELECT_CURRENT_CERT:
return ssl_cert_select_current(ctx->cert, (X509 *)parg);
case SSL_CTRL_SET_CURRENT_CERT:
return ssl_cert_set_current(ctx->cert, larg);
default:
return (0);
}
return (1);
}
long ssl3_ctx_callback_ctrl(SSL_CTX *ctx, int cmd, void (*fp) (void))
{
switch (cmd) {
#ifndef OPENSSL_NO_DH
case SSL_CTRL_SET_TMP_DH_CB:
{
ctx->cert->dh_tmp_cb = (DH *(*)(SSL *, int, int))fp;
}
break;
#endif
case SSL_CTRL_SET_TLSEXT_SERVERNAME_CB:
ctx->tlsext_servername_callback = (int (*)(SSL *, int *, void *))fp;
break;
case SSL_CTRL_SET_TLSEXT_STATUS_REQ_CB:
ctx->tlsext_status_cb = (int (*)(SSL *, void *))fp;
break;
case SSL_CTRL_SET_TLSEXT_TICKET_KEY_CB:
ctx->tlsext_ticket_key_cb = (int (*)(SSL *, unsigned char *,
unsigned char *,
EVP_CIPHER_CTX *,
HMAC_CTX *, int))fp;
break;
#ifndef OPENSSL_NO_SRP
case SSL_CTRL_SET_SRP_VERIFY_PARAM_CB:
ctx->srp_ctx.srp_Mask |= SSL_kSRP;
ctx->srp_ctx.SRP_verify_param_callback = (int (*)(SSL *, void *))fp;
break;
case SSL_CTRL_SET_TLS_EXT_SRP_USERNAME_CB:
ctx->srp_ctx.srp_Mask |= SSL_kSRP;
ctx->srp_ctx.TLS_ext_srp_username_callback =
(int (*)(SSL *, int *, void *))fp;
break;
case SSL_CTRL_SET_SRP_GIVE_CLIENT_PWD_CB:
ctx->srp_ctx.srp_Mask |= SSL_kSRP;
ctx->srp_ctx.SRP_give_srp_client_pwd_callback =
(char *(*)(SSL *, void *))fp;
break;
#endif
case SSL_CTRL_SET_NOT_RESUMABLE_SESS_CB:
{
ctx->not_resumable_session_cb = (int (*)(SSL *, int))fp;
}
break;
default:
return (0);
}
return (1);
}
const SSL_CIPHER *ssl3_get_cipher_by_char(const unsigned char *p)
{
SSL_CIPHER c;
const SSL_CIPHER *cp;
uint32_t id;
id = 0x03000000 | ((uint32_t)p[0] << 8L) | (uint32_t)p[1];
c.id = id;
cp = OBJ_bsearch_ssl_cipher_id(&c, ssl3_ciphers, SSL3_NUM_CIPHERS);
return cp;
}
int ssl3_put_cipher_by_char(const SSL_CIPHER *c, unsigned char *p)
{
long l;
if (p != NULL) {
l = c->id;
if ((l & 0xff000000) != 0x03000000)
return (0);
p[0] = ((unsigned char)(l >> 8L)) & 0xFF;
p[1] = ((unsigned char)(l)) & 0xFF;
}
return (2);
}
int ssl3_get_req_cert_type(SSL *s, unsigned char *p)
{
int ret = 0;
uint32_t alg_k, alg_a = 0;
if (s->cert->ctypes) {
memcpy(p, s->cert->ctypes, s->cert->ctype_num);
return (int)s->cert->ctype_num;
}
ssl_set_sig_mask(&alg_a, s, SSL_SECOP_SIGALG_MASK);
alg_k = s->s3->tmp.new_cipher->algorithm_mkey;
#ifndef OPENSSL_NO_GOST
if (s->version >= TLS1_VERSION) {
if (alg_k & SSL_kGOST) {
p[ret++] = TLS_CT_GOST01_SIGN;
p[ret++] = TLS_CT_GOST12_SIGN;
p[ret++] = TLS_CT_GOST12_512_SIGN;
return (ret);
}
}
#endif
if ((s->version == SSL3_VERSION) && (alg_k & SSL_kDHE)) {
#ifndef OPENSSL_NO_DH
# ifndef OPENSSL_NO_RSA
p[ret++] = SSL3_CT_RSA_EPHEMERAL_DH;
# endif
# ifndef OPENSSL_NO_DSA
p[ret++] = SSL3_CT_DSS_EPHEMERAL_DH;
# endif
#endif
}
#ifndef OPENSSL_NO_RSA
if (!(alg_a & SSL_aRSA))
p[ret++] = SSL3_CT_RSA_SIGN;
#endif
#ifndef OPENSSL_NO_DSA
if (!(alg_a & SSL_aDSS))
p[ret++] = SSL3_CT_DSS_SIGN;
#endif
#ifndef OPENSSL_NO_EC
if (s->version >= TLS1_VERSION) {
if (!(alg_a & SSL_aECDSA))
p[ret++] = TLS_CT_ECDSA_SIGN;
}
#endif
return (ret);
}
static int ssl3_set_req_cert_type(CERT *c, const unsigned char *p, size_t len)
{
OPENSSL_free(c->ctypes);
c->ctypes = NULL;
if (!p || !len)
return 1;
if (len > 0xff)
return 0;
c->ctypes = OPENSSL_malloc(len);
if (c->ctypes == NULL)
return 0;
memcpy(c->ctypes, p, len);
c->ctype_num = len;
return 1;
}
int ssl3_shutdown(SSL *s)
{
int ret;
if (s->quiet_shutdown || SSL_in_before(s)) {
s->shutdown = (SSL_SENT_SHUTDOWN | SSL_RECEIVED_SHUTDOWN);
return (1);
}
if (!(s->shutdown & SSL_SENT_SHUTDOWN)) {
s->shutdown |= SSL_SENT_SHUTDOWN;
ssl3_send_alert(s, SSL3_AL_WARNING, SSL_AD_CLOSE_NOTIFY);
if (s->s3->alert_dispatch)
return (-1);
} else if (s->s3->alert_dispatch) {
ret = s->method->ssl_dispatch_alert(s);
if (ret == -1) {
return (ret);
}
} else if (!(s->shutdown & SSL_RECEIVED_SHUTDOWN)) {
s->method->ssl_read_bytes(s, 0, NULL, NULL, 0, 0);
if (!(s->shutdown & SSL_RECEIVED_SHUTDOWN)) {
return (-1);
}
}
if ((s->shutdown == (SSL_SENT_SHUTDOWN | SSL_RECEIVED_SHUTDOWN)) &&
!s->s3->alert_dispatch)
return (1);
else
return (0);
}
int ssl3_write(SSL *s, const void *buf, int len)
{
clear_sys_error();
if (s->s3->renegotiate)
ssl3_renegotiate_check(s);
return s->method->ssl_write_bytes(s, SSL3_RT_APPLICATION_DATA, buf, len);
}
static int ssl3_read_internal(SSL *s, void *buf, int len, int peek)
{
int ret;
clear_sys_error();
if (s->s3->renegotiate)
ssl3_renegotiate_check(s);
s->s3->in_read_app_data = 1;
ret =
s->method->ssl_read_bytes(s, SSL3_RT_APPLICATION_DATA, NULL, buf, len,
peek);
if ((ret == -1) && (s->s3->in_read_app_data == 2)) {
ossl_statem_set_in_handshake(s, 1);
ret =
s->method->ssl_read_bytes(s, SSL3_RT_APPLICATION_DATA, NULL, buf,
len, peek);
ossl_statem_set_in_handshake(s, 0);
} else
s->s3->in_read_app_data = 0;
return (ret);
}
int ssl3_read(SSL *s, void *buf, int len)
{
return ssl3_read_internal(s, buf, len, 0);
}
int ssl3_peek(SSL *s, void *buf, int len)
{
return ssl3_read_internal(s, buf, len, 1);
}
int ssl3_renegotiate(SSL *s)
{
if (s->handshake_func == NULL)
return (1);
if (s->s3->flags & SSL3_FLAGS_NO_RENEGOTIATE_CIPHERS)
return (0);
s->s3->renegotiate = 1;
return (1);
}
int ssl3_renegotiate_check(SSL *s)
{
int ret = 0;
if (s->s3->renegotiate) {
if (!RECORD_LAYER_read_pending(&s->rlayer)
&& !RECORD_LAYER_write_pending(&s->rlayer)
&& !SSL_in_init(s)) {
ossl_statem_set_renegotiate(s);
s->s3->renegotiate = 0;
s->s3->num_renegotiations++;
s->s3->total_renegotiations++;
ret = 1;
}
}
return (ret);
}
long ssl_get_algorithm2(SSL *s)
{
long alg2;
if (s->s3 == NULL || s->s3->tmp.new_cipher == NULL)
return -1;
alg2 = s->s3->tmp.new_cipher->algorithm2;
if (s->method->ssl3_enc->enc_flags & SSL_ENC_FLAG_SHA256_PRF) {
if (alg2 == (SSL_HANDSHAKE_MAC_DEFAULT | TLS1_PRF))
return SSL_HANDSHAKE_MAC_SHA256 | TLS1_PRF_SHA256;
} else if (s->s3->tmp.new_cipher->algorithm_mkey & SSL_PSK) {
if (alg2 == (SSL_HANDSHAKE_MAC_SHA384 | TLS1_PRF_SHA384))
return SSL_HANDSHAKE_MAC_DEFAULT | TLS1_PRF;
}
return alg2;
}
int ssl_fill_hello_random(SSL *s, int server, unsigned char *result, int len)
{
int send_time = 0;
if (len < 4)
return 0;
if (server)
send_time = (s->mode & SSL_MODE_SEND_SERVERHELLO_TIME) != 0;
else
send_time = (s->mode & SSL_MODE_SEND_CLIENTHELLO_TIME) != 0;
if (send_time) {
unsigned long Time = (unsigned long)time(NULL);
unsigned char *p = result;
l2n(Time, p);
return RAND_bytes(p, len - 4);
} else
return RAND_bytes(result, len);
}
int ssl_generate_master_secret(SSL *s, unsigned char *pms, size_t pmslen,
int free_pms)
{
unsigned long alg_k = s->s3->tmp.new_cipher->algorithm_mkey;
if (alg_k & SSL_PSK) {
#ifndef OPENSSL_NO_PSK
unsigned char *pskpms, *t;
size_t psklen = s->s3->tmp.psklen;
size_t pskpmslen;
if (alg_k & SSL_kPSK)
pmslen = psklen;
pskpmslen = 4 + pmslen + psklen;
pskpms = OPENSSL_malloc(pskpmslen);
if (pskpms == NULL) {
s->session->master_key_length = 0;
goto err;
}
t = pskpms;
s2n(pmslen, t);
if (alg_k & SSL_kPSK)
memset(t, 0, pmslen);
else
memcpy(t, pms, pmslen);
t += pmslen;
s2n(psklen, t);
memcpy(t, s->s3->tmp.psk, psklen);
OPENSSL_clear_free(s->s3->tmp.psk, psklen);
s->s3->tmp.psk = NULL;
s->session->master_key_length =
s->method->ssl3_enc->generate_master_secret(s,
s->session->master_key,
pskpms, pskpmslen);
OPENSSL_clear_free(pskpms, pskpmslen);
#else
s->session->master_key_length = 0;
goto err;
#endif
} else {
s->session->master_key_length =
s->method->ssl3_enc->generate_master_secret(s,
s->session->master_key,
pms, pmslen);
}
err:
if (pms) {
if (free_pms)
OPENSSL_clear_free(pms, pmslen);
else
OPENSSL_cleanse(pms, pmslen);
}
if (s->server == 0)
s->s3->tmp.pms = NULL;
return s->session->master_key_length >= 0;
}
EVP_PKEY *ssl_generate_pkey(EVP_PKEY *pm)
{
EVP_PKEY_CTX *pctx = NULL;
EVP_PKEY *pkey = NULL;
if (pm == NULL)
return NULL;
pctx = EVP_PKEY_CTX_new(pm, NULL);
if (pctx == NULL)
goto err;
if (EVP_PKEY_keygen_init(pctx) <= 0)
goto err;
if (EVP_PKEY_keygen(pctx, &pkey) <= 0) {
EVP_PKEY_free(pkey);
pkey = NULL;
}
err:
EVP_PKEY_CTX_free(pctx);
return pkey;
}
EVP_PKEY *ssl_generate_pkey_curve(int id)
{
EVP_PKEY_CTX *pctx = NULL;
EVP_PKEY *pkey = NULL;
unsigned int curve_flags;
int nid = tls1_ec_curve_id2nid(id, &curve_flags);
if (nid == 0)
goto err;
if ((curve_flags & TLS_CURVE_TYPE) == TLS_CURVE_CUSTOM) {
pctx = EVP_PKEY_CTX_new_id(nid, NULL);
nid = 0;
} else {
pctx = EVP_PKEY_CTX_new_id(EVP_PKEY_EC, NULL);
}
if (pctx == NULL)
goto err;
if (EVP_PKEY_keygen_init(pctx) <= 0)
goto err;
if (nid != 0 && EVP_PKEY_CTX_set_ec_paramgen_curve_nid(pctx, nid) <= 0)
goto err;
if (EVP_PKEY_keygen(pctx, &pkey) <= 0) {
EVP_PKEY_free(pkey);
pkey = NULL;
}
err:
EVP_PKEY_CTX_free(pctx);
return pkey;
}
int ssl_derive(SSL *s, EVP_PKEY *privkey, EVP_PKEY *pubkey)
{
int rv = 0;
unsigned char *pms = NULL;
size_t pmslen = 0;
EVP_PKEY_CTX *pctx;
if (privkey == NULL || pubkey == NULL)
return 0;
pctx = EVP_PKEY_CTX_new(privkey, NULL);
if (EVP_PKEY_derive_init(pctx) <= 0
|| EVP_PKEY_derive_set_peer(pctx, pubkey) <= 0
|| EVP_PKEY_derive(pctx, NULL, &pmslen) <= 0) {
goto err;
}
pms = OPENSSL_malloc(pmslen);
if (pms == NULL)
goto err;
if (EVP_PKEY_derive(pctx, pms, &pmslen) <= 0)
goto err;
if (s->server) {
rv = ssl_generate_master_secret(s, pms, pmslen, 1);
pms = NULL;
} else {
s->s3->tmp.pms = pms;
s->s3->tmp.pmslen = pmslen;
pms = NULL;
rv = 1;
}
err:
OPENSSL_clear_free(pms, pmslen);
EVP_PKEY_CTX_free(pctx);
return rv;
}
EVP_PKEY *ssl_dh_to_pkey(DH *dh)
{
EVP_PKEY *ret;
if (dh == NULL)
return NULL;
ret = EVP_PKEY_new();
if (EVP_PKEY_set1_DH(ret, dh) <= 0) {
EVP_PKEY_free(ret);
return NULL;
}
return ret;
}
