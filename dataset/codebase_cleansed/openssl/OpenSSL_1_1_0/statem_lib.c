int ssl3_do_write(SSL *s, int type)
{
int ret;
ret = ssl3_write_bytes(s, type, &s->init_buf->data[s->init_off],
s->init_num);
if (ret < 0)
return (-1);
if (type == SSL3_RT_HANDSHAKE)
if (!ssl3_finish_mac(s,
(unsigned char *)&s->init_buf->data[s->init_off],
ret))
return -1;
if (ret == s->init_num) {
if (s->msg_callback)
s->msg_callback(1, s->version, type, s->init_buf->data,
(size_t)(s->init_off + s->init_num), s,
s->msg_callback_arg);
return (1);
}
s->init_off += ret;
s->init_num -= ret;
return (0);
}
int tls_construct_finished(SSL *s, const char *sender, int slen)
{
unsigned char *p;
int i;
unsigned long l;
p = ssl_handshake_start(s);
i = s->method->ssl3_enc->final_finish_mac(s,
sender, slen,
s->s3->tmp.finish_md);
if (i <= 0)
return 0;
s->s3->tmp.finish_md_len = i;
memcpy(p, s->s3->tmp.finish_md, i);
l = i;
if (!s->server) {
OPENSSL_assert(i <= EVP_MAX_MD_SIZE);
memcpy(s->s3->previous_client_finished, s->s3->tmp.finish_md, i);
s->s3->previous_client_finished_len = i;
} else {
OPENSSL_assert(i <= EVP_MAX_MD_SIZE);
memcpy(s->s3->previous_server_finished, s->s3->tmp.finish_md, i);
s->s3->previous_server_finished_len = i;
}
if (!ssl_set_handshake_header(s, SSL3_MT_FINISHED, l)) {
SSLerr(SSL_F_TLS_CONSTRUCT_FINISHED, ERR_R_INTERNAL_ERROR);
return 0;
}
return 1;
}
static void ssl3_take_mac(SSL *s)
{
const char *sender;
int slen;
if (s->s3->tmp.new_cipher == NULL)
return;
if (!s->server) {
sender = s->method->ssl3_enc->server_finished_label;
slen = s->method->ssl3_enc->server_finished_label_len;
} else {
sender = s->method->ssl3_enc->client_finished_label;
slen = s->method->ssl3_enc->client_finished_label_len;
}
s->s3->tmp.peer_finish_md_len = s->method->ssl3_enc->final_finish_mac(s,
sender,
slen,
s->s3->tmp.peer_finish_md);
}
MSG_PROCESS_RETURN tls_process_change_cipher_spec(SSL *s, PACKET *pkt)
{
int al;
long remain;
remain = PACKET_remaining(pkt);
if (SSL_IS_DTLS(s)) {
if ((s->version == DTLS1_BAD_VER
&& remain != DTLS1_CCS_HEADER_LENGTH + 1)
|| (s->version != DTLS1_BAD_VER
&& remain != DTLS1_CCS_HEADER_LENGTH - 1)) {
al = SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_TLS_PROCESS_CHANGE_CIPHER_SPEC,
SSL_R_BAD_CHANGE_CIPHER_SPEC);
goto f_err;
}
} else {
if (remain != 0) {
al = SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_TLS_PROCESS_CHANGE_CIPHER_SPEC,
SSL_R_BAD_CHANGE_CIPHER_SPEC);
goto f_err;
}
}
if (s->s3->tmp.new_cipher == NULL) {
al = SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_TLS_PROCESS_CHANGE_CIPHER_SPEC, SSL_R_CCS_RECEIVED_EARLY);
goto f_err;
}
s->s3->change_cipher_spec = 1;
if (!ssl3_do_change_cipher_spec(s)) {
al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CHANGE_CIPHER_SPEC, ERR_R_INTERNAL_ERROR);
goto f_err;
}
if (SSL_IS_DTLS(s)) {
dtls1_reset_seq_numbers(s, SSL3_CC_READ);
if (s->version == DTLS1_BAD_VER)
s->d1->handshake_read_seq++;
#ifndef OPENSSL_NO_SCTP
BIO_ctrl(SSL_get_wbio(s), BIO_CTRL_DGRAM_SCTP_AUTH_CCS_RCVD, 1, NULL);
#endif
}
return MSG_PROCESS_CONTINUE_READING;
f_err:
ssl3_send_alert(s, SSL3_AL_FATAL, al);
ossl_statem_set_error(s);
return MSG_PROCESS_ERROR;
}
MSG_PROCESS_RETURN tls_process_finished(SSL *s, PACKET *pkt)
{
int al, i;
if (!s->s3->change_cipher_spec) {
al = SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_TLS_PROCESS_FINISHED, SSL_R_GOT_A_FIN_BEFORE_A_CCS);
goto f_err;
}
s->s3->change_cipher_spec = 0;
i = s->s3->tmp.peer_finish_md_len;
if ((unsigned long)i != PACKET_remaining(pkt)) {
al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_FINISHED, SSL_R_BAD_DIGEST_LENGTH);
goto f_err;
}
if (CRYPTO_memcmp(PACKET_data(pkt), s->s3->tmp.peer_finish_md, i) != 0) {
al = SSL_AD_DECRYPT_ERROR;
SSLerr(SSL_F_TLS_PROCESS_FINISHED, SSL_R_DIGEST_CHECK_FAILED);
goto f_err;
}
if (s->server) {
OPENSSL_assert(i <= EVP_MAX_MD_SIZE);
memcpy(s->s3->previous_client_finished, s->s3->tmp.peer_finish_md, i);
s->s3->previous_client_finished_len = i;
} else {
OPENSSL_assert(i <= EVP_MAX_MD_SIZE);
memcpy(s->s3->previous_server_finished, s->s3->tmp.peer_finish_md, i);
s->s3->previous_server_finished_len = i;
}
return MSG_PROCESS_FINISHED_READING;
f_err:
ssl3_send_alert(s, SSL3_AL_FATAL, al);
ossl_statem_set_error(s);
return MSG_PROCESS_ERROR;
}
int tls_construct_change_cipher_spec(SSL *s)
{
unsigned char *p;
p = (unsigned char *)s->init_buf->data;
*p = SSL3_MT_CCS;
s->init_num = 1;
s->init_off = 0;
return 1;
}
unsigned long ssl3_output_cert_chain(SSL *s, CERT_PKEY *cpk)
{
unsigned char *p;
unsigned long l = 3 + SSL_HM_HEADER_LENGTH(s);
if (!ssl_add_cert_chain(s, cpk, &l))
return 0;
l -= 3 + SSL_HM_HEADER_LENGTH(s);
p = ssl_handshake_start(s);
l2n3(l, p);
l += 3;
if (!ssl_set_handshake_header(s, SSL3_MT_CERTIFICATE, l)) {
SSLerr(SSL_F_SSL3_OUTPUT_CERT_CHAIN, ERR_R_INTERNAL_ERROR);
return 0;
}
return l + SSL_HM_HEADER_LENGTH(s);
}
WORK_STATE tls_finish_handshake(SSL *s, WORK_STATE wst)
{
void (*cb) (const SSL *ssl, int type, int val) = NULL;
#ifndef OPENSSL_NO_SCTP
if (SSL_IS_DTLS(s) && BIO_dgram_is_sctp(SSL_get_wbio(s))) {
WORK_STATE ret;
ret = dtls_wait_for_dry(s);
if (ret != WORK_FINISHED_CONTINUE)
return ret;
}
#endif
ssl3_cleanup_key_block(s);
if (!SSL_IS_DTLS(s)) {
BUF_MEM_free(s->init_buf);
s->init_buf = NULL;
}
ssl_free_wbio_buffer(s);
s->init_num = 0;
if (!s->server || s->renegotiate == 2) {
s->renegotiate = 0;
s->new_session = 0;
if (s->server) {
ssl_update_cache(s, SSL_SESS_CACHE_SERVER);
s->ctx->stats.sess_accept_good++;
s->handshake_func = ossl_statem_accept;
} else {
ssl_update_cache(s, SSL_SESS_CACHE_CLIENT);
if (s->hit)
s->ctx->stats.sess_hit++;
s->handshake_func = ossl_statem_connect;
s->ctx->stats.sess_connect_good++;
}
if (s->info_callback != NULL)
cb = s->info_callback;
else if (s->ctx->info_callback != NULL)
cb = s->ctx->info_callback;
if (cb != NULL)
cb(s, SSL_CB_HANDSHAKE_DONE, 1);
if (SSL_IS_DTLS(s)) {
s->d1->handshake_read_seq = 0;
s->d1->handshake_write_seq = 0;
s->d1->next_handshake_write_seq = 0;
dtls1_clear_received_buffer(s);
}
}
return WORK_FINISHED_STOP;
}
int tls_get_message_header(SSL *s, int *mt)
{
int skip_message, i, recvd_type, al;
unsigned char *p;
unsigned long l;
p = (unsigned char *)s->init_buf->data;
do {
while (s->init_num < SSL3_HM_HEADER_LENGTH) {
i = s->method->ssl_read_bytes(s, SSL3_RT_HANDSHAKE, &recvd_type,
&p[s->init_num],
SSL3_HM_HEADER_LENGTH - s->init_num,
0);
if (i <= 0) {
s->rwstate = SSL_READING;
return 0;
}
if (recvd_type == SSL3_RT_CHANGE_CIPHER_SPEC) {
if (s->init_num != 0 || i != 1 || p[0] != SSL3_MT_CCS) {
al = SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_TLS_GET_MESSAGE_HEADER,
SSL_R_BAD_CHANGE_CIPHER_SPEC);
goto f_err;
}
s->s3->tmp.message_type = *mt = SSL3_MT_CHANGE_CIPHER_SPEC;
s->init_num = i - 1;
s->s3->tmp.message_size = i;
return 1;
} else if (recvd_type != SSL3_RT_HANDSHAKE) {
al = SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_TLS_GET_MESSAGE_HEADER, SSL_R_CCS_RECEIVED_EARLY);
goto f_err;
}
s->init_num += i;
}
skip_message = 0;
if (!s->server)
if (p[0] == SSL3_MT_HELLO_REQUEST)
if (p[1] == 0 && p[2] == 0 && p[3] == 0) {
s->init_num = 0;
skip_message = 1;
if (s->msg_callback)
s->msg_callback(0, s->version, SSL3_RT_HANDSHAKE,
p, SSL3_HM_HEADER_LENGTH, s,
s->msg_callback_arg);
}
} while (skip_message);
*mt = *p;
s->s3->tmp.message_type = *(p++);
if (RECORD_LAYER_is_sslv2_record(&s->rlayer)) {
l = RECORD_LAYER_get_rrec_length(&s->rlayer)
+ SSL3_HM_HEADER_LENGTH;
if (l && !BUF_MEM_grow_clean(s->init_buf, (int)l)) {
SSLerr(SSL_F_TLS_GET_MESSAGE_HEADER, ERR_R_BUF_LIB);
goto err;
}
s->s3->tmp.message_size = l;
s->init_msg = s->init_buf->data;
s->init_num = SSL3_HM_HEADER_LENGTH;
} else {
n2l3(p, l);
if (l > (INT_MAX - SSL3_HM_HEADER_LENGTH)) {
al = SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_TLS_GET_MESSAGE_HEADER, SSL_R_EXCESSIVE_MESSAGE_SIZE);
goto f_err;
}
if (l && !BUF_MEM_grow_clean(s->init_buf,
(int)l + SSL3_HM_HEADER_LENGTH)) {
SSLerr(SSL_F_TLS_GET_MESSAGE_HEADER, ERR_R_BUF_LIB);
goto err;
}
s->s3->tmp.message_size = l;
s->init_msg = s->init_buf->data + SSL3_HM_HEADER_LENGTH;
s->init_num = 0;
}
return 1;
f_err:
ssl3_send_alert(s, SSL3_AL_FATAL, al);
err:
return 0;
}
int tls_get_message_body(SSL *s, unsigned long *len)
{
long n;
unsigned char *p;
int i;
if (s->s3->tmp.message_type == SSL3_MT_CHANGE_CIPHER_SPEC) {
*len = (unsigned long)s->init_num;
return 1;
}
p = s->init_msg;
n = s->s3->tmp.message_size - s->init_num;
while (n > 0) {
i = s->method->ssl_read_bytes(s, SSL3_RT_HANDSHAKE, NULL,
&p[s->init_num], n, 0);
if (i <= 0) {
s->rwstate = SSL_READING;
*len = 0;
return 0;
}
s->init_num += i;
n -= i;
}
#ifndef OPENSSL_NO_NEXTPROTONEG
if (*s->init_buf->data == SSL3_MT_FINISHED)
ssl3_take_mac(s);
#endif
if (RECORD_LAYER_is_sslv2_record(&s->rlayer)) {
if (!ssl3_finish_mac(s, (unsigned char *)s->init_buf->data,
s->init_num)) {
SSLerr(SSL_F_TLS_GET_MESSAGE_BODY, ERR_R_EVP_LIB);
ssl3_send_alert(s, SSL3_AL_FATAL, SSL_AD_INTERNAL_ERROR);
*len = 0;
return 0;
}
if (s->msg_callback)
s->msg_callback(0, SSL2_VERSION, 0, s->init_buf->data,
(size_t)s->init_num, s, s->msg_callback_arg);
} else {
if (!ssl3_finish_mac(s, (unsigned char *)s->init_buf->data,
s->init_num + SSL3_HM_HEADER_LENGTH)) {
SSLerr(SSL_F_TLS_GET_MESSAGE_BODY, ERR_R_EVP_LIB);
ssl3_send_alert(s, SSL3_AL_FATAL, SSL_AD_INTERNAL_ERROR);
*len = 0;
return 0;
}
if (s->msg_callback)
s->msg_callback(0, s->version, SSL3_RT_HANDSHAKE, s->init_buf->data,
(size_t)s->init_num + SSL3_HM_HEADER_LENGTH, s,
s->msg_callback_arg);
}
if (s->init_num < 0) {
SSLerr(SSL_F_TLS_GET_MESSAGE_BODY, ERR_R_INTERNAL_ERROR);
ssl3_send_alert(s, SSL3_AL_FATAL, SSL_AD_INTERNAL_ERROR);
*len = 0;
return 0;
}
*len = (unsigned long)s->init_num;
return 1;
}
int ssl_cert_type(const X509 *x, const EVP_PKEY *pk)
{
if (pk == NULL && (pk = X509_get0_pubkey(x)) == NULL)
return -1;
switch (EVP_PKEY_id(pk)) {
default:
return -1;
case EVP_PKEY_RSA:
return SSL_PKEY_RSA_ENC;
case EVP_PKEY_DSA:
return SSL_PKEY_DSA_SIGN;
#ifndef OPENSSL_NO_EC
case EVP_PKEY_EC:
return SSL_PKEY_ECC;
#endif
#ifndef OPENSSL_NO_GOST
case NID_id_GostR3410_2001:
return SSL_PKEY_GOST01;
case NID_id_GostR3410_2012_256:
return SSL_PKEY_GOST12_256;
case NID_id_GostR3410_2012_512:
return SSL_PKEY_GOST12_512;
#endif
}
}
int ssl_verify_alarm_type(long type)
{
int al;
switch (type) {
case X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT:
case X509_V_ERR_UNABLE_TO_GET_CRL:
case X509_V_ERR_UNABLE_TO_GET_CRL_ISSUER:
al = SSL_AD_UNKNOWN_CA;
break;
case X509_V_ERR_UNABLE_TO_DECRYPT_CERT_SIGNATURE:
case X509_V_ERR_UNABLE_TO_DECRYPT_CRL_SIGNATURE:
case X509_V_ERR_UNABLE_TO_DECODE_ISSUER_PUBLIC_KEY:
case X509_V_ERR_ERROR_IN_CERT_NOT_BEFORE_FIELD:
case X509_V_ERR_ERROR_IN_CERT_NOT_AFTER_FIELD:
case X509_V_ERR_ERROR_IN_CRL_LAST_UPDATE_FIELD:
case X509_V_ERR_ERROR_IN_CRL_NEXT_UPDATE_FIELD:
case X509_V_ERR_CERT_NOT_YET_VALID:
case X509_V_ERR_CRL_NOT_YET_VALID:
case X509_V_ERR_CERT_UNTRUSTED:
case X509_V_ERR_CERT_REJECTED:
case X509_V_ERR_HOSTNAME_MISMATCH:
case X509_V_ERR_EMAIL_MISMATCH:
case X509_V_ERR_IP_ADDRESS_MISMATCH:
case X509_V_ERR_DANE_NO_MATCH:
case X509_V_ERR_EE_KEY_TOO_SMALL:
case X509_V_ERR_CA_KEY_TOO_SMALL:
case X509_V_ERR_CA_MD_TOO_WEAK:
al = SSL_AD_BAD_CERTIFICATE;
break;
case X509_V_ERR_CERT_SIGNATURE_FAILURE:
case X509_V_ERR_CRL_SIGNATURE_FAILURE:
al = SSL_AD_DECRYPT_ERROR;
break;
case X509_V_ERR_CERT_HAS_EXPIRED:
case X509_V_ERR_CRL_HAS_EXPIRED:
al = SSL_AD_CERTIFICATE_EXPIRED;
break;
case X509_V_ERR_CERT_REVOKED:
al = SSL_AD_CERTIFICATE_REVOKED;
break;
case X509_V_ERR_UNSPECIFIED:
case X509_V_ERR_OUT_OF_MEM:
case X509_V_ERR_INVALID_CALL:
case X509_V_ERR_STORE_LOOKUP:
al = SSL_AD_INTERNAL_ERROR;
break;
case X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT:
case X509_V_ERR_SELF_SIGNED_CERT_IN_CHAIN:
case X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT_LOCALLY:
case X509_V_ERR_UNABLE_TO_VERIFY_LEAF_SIGNATURE:
case X509_V_ERR_CERT_CHAIN_TOO_LONG:
case X509_V_ERR_PATH_LENGTH_EXCEEDED:
case X509_V_ERR_INVALID_CA:
al = SSL_AD_UNKNOWN_CA;
break;
case X509_V_ERR_APPLICATION_VERIFICATION:
al = SSL_AD_HANDSHAKE_FAILURE;
break;
case X509_V_ERR_INVALID_PURPOSE:
al = SSL_AD_UNSUPPORTED_CERTIFICATE;
break;
default:
al = SSL_AD_CERTIFICATE_UNKNOWN;
break;
}
return (al);
}
int ssl_allow_compression(SSL *s)
{
if (s->options & SSL_OP_NO_COMPRESSION)
return 0;
return ssl_security(s, SSL_SECOP_COMPRESSION, 0, 0, NULL);
}
static int version_cmp(const SSL *s, int a, int b)
{
int dtls = SSL_IS_DTLS(s);
if (a == b)
return 0;
if (!dtls)
return a < b ? -1 : 1;
return DTLS_VERSION_LT(a, b) ? -1 : 1;
}
static int ssl_method_error(const SSL *s, const SSL_METHOD *method)
{
int version = method->version;
if ((s->min_proto_version != 0 &&
version_cmp(s, version, s->min_proto_version) < 0) ||
ssl_security(s, SSL_SECOP_VERSION, 0, version, NULL) == 0)
return SSL_R_VERSION_TOO_LOW;
if (s->max_proto_version != 0 &&
version_cmp(s, version, s->max_proto_version) > 0)
return SSL_R_VERSION_TOO_HIGH;
if ((s->options & method->mask) != 0)
return SSL_R_UNSUPPORTED_PROTOCOL;
if ((method->flags & SSL_METHOD_NO_SUITEB) != 0 && tls1_suiteb(s))
return SSL_R_AT_LEAST_TLS_1_2_NEEDED_IN_SUITEB_MODE;
else if ((method->flags & SSL_METHOD_NO_FIPS) != 0 && FIPS_mode())
return SSL_R_AT_LEAST_TLS_1_0_NEEDED_IN_FIPS_MODE;
return 0;
}
int ssl_version_supported(const SSL *s, int version)
{
const version_info *vent;
const version_info *table;
switch (s->method->version) {
default:
return version_cmp(s, version, s->version) == 0;
case TLS_ANY_VERSION:
table = tls_version_table;
break;
case DTLS_ANY_VERSION:
table = dtls_version_table;
break;
}
for (vent = table;
vent->version != 0 && version_cmp(s, version, vent->version) <= 0;
++vent) {
if (vent->cmeth != NULL &&
version_cmp(s, version, vent->version) == 0 &&
ssl_method_error(s, vent->cmeth()) == 0) {
return 1;
}
}
return 0;
}
int ssl_check_version_downgrade(SSL *s)
{
const version_info *vent;
const version_info *table;
if (s->version == s->ctx->method->version)
return 1;
if (s->ctx->method->version == TLS_method()->version)
table = tls_version_table;
else if (s->ctx->method->version == DTLS_method()->version)
table = dtls_version_table;
else {
return 0;
}
for (vent = table; vent->version != 0; ++vent) {
if (vent->smeth != NULL && ssl_method_error(s, vent->smeth()) == 0)
return s->version == vent->version;
}
return 0;
}
int ssl_set_version_bound(int method_version, int version, int *bound)
{
if (version == 0) {
*bound = version;
return 1;
}
switch (method_version) {
default:
return 0;
case TLS_ANY_VERSION:
if (version < SSL3_VERSION || version > TLS_MAX_VERSION)
return 0;
break;
case DTLS_ANY_VERSION:
if (DTLS_VERSION_GT(version, DTLS_MAX_VERSION) ||
DTLS_VERSION_LT(version, DTLS1_BAD_VER))
return 0;
break;
}
*bound = version;
return 1;
}
int ssl_choose_server_version(SSL *s)
{
int server_version = s->method->version;
int client_version = s->client_version;
const version_info *vent;
const version_info *table;
int disabled = 0;
switch (server_version) {
default:
if (version_cmp(s, client_version, s->version) < 0)
return SSL_R_WRONG_SSL_VERSION;
return 0;
case TLS_ANY_VERSION:
table = tls_version_table;
break;
case DTLS_ANY_VERSION:
table = dtls_version_table;
break;
}
for (vent = table; vent->version != 0; ++vent) {
const SSL_METHOD *method;
if (vent->smeth == NULL ||
version_cmp(s, client_version, vent->version) < 0)
continue;
method = vent->smeth();
if (ssl_method_error(s, method) == 0) {
s->version = vent->version;
s->method = method;
return 0;
}
disabled = 1;
}
return disabled ? SSL_R_UNSUPPORTED_PROTOCOL : SSL_R_VERSION_TOO_LOW;
}
int ssl_choose_client_version(SSL *s, int version)
{
const version_info *vent;
const version_info *table;
switch (s->method->version) {
default:
if (version != s->version)
return SSL_R_WRONG_SSL_VERSION;
return 0;
case TLS_ANY_VERSION:
table = tls_version_table;
break;
case DTLS_ANY_VERSION:
table = dtls_version_table;
break;
}
for (vent = table; vent->version != 0; ++vent) {
const SSL_METHOD *method;
int err;
if (version != vent->version)
continue;
if (vent->cmeth == NULL)
break;
method = vent->cmeth();
err = ssl_method_error(s, method);
if (err != 0)
return err;
s->method = method;
s->version = version;
return 0;
}
return SSL_R_UNSUPPORTED_PROTOCOL;
}
int ssl_get_client_min_max_version(const SSL *s, int *min_version,
int *max_version)
{
int version;
int hole;
const SSL_METHOD *single = NULL;
const SSL_METHOD *method;
const version_info *table;
const version_info *vent;
switch (s->method->version) {
default:
*min_version = *max_version = s->version;
return 0;
case TLS_ANY_VERSION:
table = tls_version_table;
break;
case DTLS_ANY_VERSION:
table = dtls_version_table;
break;
}
*min_version = version = 0;
hole = 1;
for (vent = table; vent->version != 0; ++vent) {
if (vent->cmeth == NULL) {
hole = 1;
continue;
}
method = vent->cmeth();
if (ssl_method_error(s, method) != 0) {
hole = 1;
} else if (!hole) {
single = NULL;
*min_version = method->version;
} else {
version = (single = method)->version;
*min_version = version;
hole = 0;
}
}
*max_version = version;
if (version == 0)
return SSL_R_NO_PROTOCOLS_AVAILABLE;
return 0;
}
int ssl_set_client_hello_version(SSL *s)
{
int ver_min, ver_max, ret;
ret = ssl_get_client_min_max_version(s, &ver_min, &ver_max);
if (ret != 0)
return ret;
s->client_version = s->version = ver_max;
return 0;
}
