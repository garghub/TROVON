int ssl3_do_write(SSL *s, int type)
{
int ret;
ret = ssl3_write_bytes(s, type, &s->init_buf->data[s->init_off],
s->init_num);
if (ret < 0)
return (-1);
if (type == SSL3_RT_HANDSHAKE)
ssl3_finish_mac(s, (unsigned char *)&s->init_buf->data[s->init_off],
ret);
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
int ssl3_send_finished(SSL *s, int a, int b, const char *sender, int slen)
{
unsigned char *p;
int i;
unsigned long l;
if (s->state == a) {
p = ssl_handshake_start(s);
i = s->method->ssl3_enc->final_finish_mac(s,
sender, slen,
s->s3->tmp.finish_md);
if (i == 0)
return 0;
s->s3->tmp.finish_md_len = i;
memcpy(p, s->s3->tmp.finish_md, i);
l = i;
if (s->type == SSL_ST_CONNECT) {
OPENSSL_assert(i <= EVP_MAX_MD_SIZE);
memcpy(s->s3->previous_client_finished, s->s3->tmp.finish_md, i);
s->s3->previous_client_finished_len = i;
} else {
OPENSSL_assert(i <= EVP_MAX_MD_SIZE);
memcpy(s->s3->previous_server_finished, s->s3->tmp.finish_md, i);
s->s3->previous_server_finished_len = i;
}
#ifdef OPENSSL_SYS_WIN16
l &= 0xffff;
#endif
ssl_set_handshake_header(s, SSL3_MT_FINISHED, l);
s->state = b;
}
return ssl_do_write(s);
}
static void ssl3_take_mac(SSL *s)
{
const char *sender;
int slen;
if (s->s3->tmp.new_cipher == NULL)
return;
if (s->state & SSL_ST_CONNECT) {
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
int ssl3_get_finished(SSL *s, int a, int b)
{
int al, i, ok;
long n;
unsigned char *p;
#ifdef OPENSSL_NO_NEXTPROTONEG
#endif
n = s->method->ssl_get_message(s, a, b, SSL3_MT_FINISHED, 64, &ok);
if (!ok)
return ((int)n);
if (!s->s3->change_cipher_spec) {
al = SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_SSL3_GET_FINISHED, SSL_R_GOT_A_FIN_BEFORE_A_CCS);
goto f_err;
}
s->s3->change_cipher_spec = 0;
p = (unsigned char *)s->init_msg;
i = s->s3->tmp.peer_finish_md_len;
if (i != n) {
al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_SSL3_GET_FINISHED, SSL_R_BAD_DIGEST_LENGTH);
goto f_err;
}
if (CRYPTO_memcmp(p, s->s3->tmp.peer_finish_md, i) != 0) {
al = SSL_AD_DECRYPT_ERROR;
SSLerr(SSL_F_SSL3_GET_FINISHED, SSL_R_DIGEST_CHECK_FAILED);
goto f_err;
}
if (s->type == SSL_ST_ACCEPT) {
OPENSSL_assert(i <= EVP_MAX_MD_SIZE);
memcpy(s->s3->previous_client_finished, s->s3->tmp.peer_finish_md, i);
s->s3->previous_client_finished_len = i;
} else {
OPENSSL_assert(i <= EVP_MAX_MD_SIZE);
memcpy(s->s3->previous_server_finished, s->s3->tmp.peer_finish_md, i);
s->s3->previous_server_finished_len = i;
}
return (1);
f_err:
ssl3_send_alert(s, SSL3_AL_FATAL, al);
return (0);
}
int ssl3_send_change_cipher_spec(SSL *s, int a, int b)
{
unsigned char *p;
if (s->state == a) {
p = (unsigned char *)s->init_buf->data;
*p = SSL3_MT_CCS;
s->init_num = 1;
s->init_off = 0;
s->state = b;
}
return (ssl3_do_write(s, SSL3_RT_CHANGE_CIPHER_SPEC));
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
ssl_set_handshake_header(s, SSL3_MT_CERTIFICATE, l);
return l + SSL_HM_HEADER_LENGTH(s);
}
long ssl3_get_message(SSL *s, int st1, int stn, int mt, long max, int *ok)
{
unsigned char *p;
unsigned long l;
long n;
int i, al;
if (s->s3->tmp.reuse_message) {
s->s3->tmp.reuse_message = 0;
if ((mt >= 0) && (s->s3->tmp.message_type != mt)) {
al = SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_SSL3_GET_MESSAGE, SSL_R_UNEXPECTED_MESSAGE);
goto f_err;
}
*ok = 1;
s->state = stn;
s->init_msg = s->init_buf->data + 4;
s->init_num = (int)s->s3->tmp.message_size;
return s->init_num;
}
p = (unsigned char *)s->init_buf->data;
if (s->state == st1) {
int skip_message;
do {
while (s->init_num < 4) {
i = s->method->ssl_read_bytes(s, SSL3_RT_HANDSHAKE,
&p[s->init_num],
4 - s->init_num, 0);
if (i <= 0) {
s->rwstate = SSL_READING;
*ok = 0;
return i;
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
p, 4, s, s->msg_callback_arg);
}
}
while (skip_message);
if ((mt >= 0) && (*p != mt)) {
al = SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_SSL3_GET_MESSAGE, SSL_R_UNEXPECTED_MESSAGE);
goto f_err;
}
s->s3->tmp.message_type = *(p++);
n2l3(p, l);
if (l > (unsigned long)max) {
al = SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_SSL3_GET_MESSAGE, SSL_R_EXCESSIVE_MESSAGE_SIZE);
goto f_err;
}
if (l > (INT_MAX - 4)) {
al = SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_SSL3_GET_MESSAGE, SSL_R_EXCESSIVE_MESSAGE_SIZE);
goto f_err;
}
if (l && !BUF_MEM_grow_clean(s->init_buf, (int)l + 4)) {
SSLerr(SSL_F_SSL3_GET_MESSAGE, ERR_R_BUF_LIB);
goto err;
}
s->s3->tmp.message_size = l;
s->state = stn;
s->init_msg = s->init_buf->data + 4;
s->init_num = 0;
}
p = s->init_msg;
n = s->s3->tmp.message_size - s->init_num;
while (n > 0) {
i = s->method->ssl_read_bytes(s, SSL3_RT_HANDSHAKE, &p[s->init_num],
n, 0);
if (i <= 0) {
s->rwstate = SSL_READING;
*ok = 0;
return i;
}
s->init_num += i;
n -= i;
}
#ifndef OPENSSL_NO_NEXTPROTONEG
if (*s->init_buf->data == SSL3_MT_FINISHED)
ssl3_take_mac(s);
#endif
ssl3_finish_mac(s, (unsigned char *)s->init_buf->data, s->init_num + 4);
if (s->msg_callback)
s->msg_callback(0, s->version, SSL3_RT_HANDSHAKE, s->init_buf->data,
(size_t)s->init_num + 4, s, s->msg_callback_arg);
*ok = 1;
return s->init_num;
f_err:
ssl3_send_alert(s, SSL3_AL_FATAL, al);
err:
*ok = 0;
return (-1);
}
int ssl_cert_type(X509 *x, EVP_PKEY *pkey)
{
EVP_PKEY *pk;
int ret = -1, i;
if (pkey == NULL)
pk = X509_get_pubkey(x);
else
pk = pkey;
if (pk == NULL)
goto err;
i = pk->type;
if (i == EVP_PKEY_RSA) {
ret = SSL_PKEY_RSA_ENC;
} else if (i == EVP_PKEY_DSA) {
ret = SSL_PKEY_DSA_SIGN;
}
#ifndef OPENSSL_NO_EC
else if (i == EVP_PKEY_EC) {
ret = SSL_PKEY_ECC;
}
#endif
else if (i == NID_id_GostR3410_94 || i == NID_id_GostR3410_94_cc) {
ret = SSL_PKEY_GOST94;
} else if (i == NID_id_GostR3410_2001 || i == NID_id_GostR3410_2001_cc) {
ret = SSL_PKEY_GOST01;
} else if (x && (i == EVP_PKEY_DH || i == EVP_PKEY_DHX)) {
i = X509_certificate_type(x, pk);
if (i & EVP_PKS_RSA)
ret = SSL_PKEY_DH_RSA;
else if (i & EVP_PKS_DSA)
ret = SSL_PKEY_DH_DSA;
}
err:
if (!pkey)
EVP_PKEY_free(pk);
return (ret);
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
case X509_V_ERR_OUT_OF_MEM:
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
static void *freelist_extract(SSL_CTX *ctx, int for_read, int sz)
{
SSL3_BUF_FREELIST *list;
SSL3_BUF_FREELIST_ENTRY *ent = NULL;
void *result = NULL;
CRYPTO_w_lock(CRYPTO_LOCK_SSL_CTX);
list = for_read ? ctx->rbuf_freelist : ctx->wbuf_freelist;
if (list != NULL && sz == (int)list->chunklen)
ent = list->head;
if (ent != NULL) {
list->head = ent->next;
result = ent;
if (--list->len == 0)
list->chunklen = 0;
}
CRYPTO_w_unlock(CRYPTO_LOCK_SSL_CTX);
if (!result)
result = OPENSSL_malloc(sz);
return result;
}
static void freelist_insert(SSL_CTX *ctx, int for_read, size_t sz, void *mem)
{
SSL3_BUF_FREELIST *list;
SSL3_BUF_FREELIST_ENTRY *ent;
CRYPTO_w_lock(CRYPTO_LOCK_SSL_CTX);
list = for_read ? ctx->rbuf_freelist : ctx->wbuf_freelist;
if (list != NULL &&
(sz == list->chunklen || list->chunklen == 0) &&
list->len < ctx->freelist_max_len && sz >= sizeof(*ent)) {
list->chunklen = sz;
ent = mem;
ent->next = list->head;
list->head = ent;
++list->len;
mem = NULL;
}
CRYPTO_w_unlock(CRYPTO_LOCK_SSL_CTX);
if (mem)
OPENSSL_free(mem);
}
int ssl3_setup_read_buffer(SSL *s)
{
unsigned char *p;
size_t len, align = 0, headerlen;
if (SSL_version(s) == DTLS1_VERSION || SSL_version(s) == DTLS1_BAD_VER)
headerlen = DTLS1_RT_HEADER_LENGTH;
else
headerlen = SSL3_RT_HEADER_LENGTH;
#if defined(SSL3_ALIGN_PAYLOAD) && SSL3_ALIGN_PAYLOAD!=0
align = (-SSL3_RT_HEADER_LENGTH) & (SSL3_ALIGN_PAYLOAD - 1);
#endif
if (s->s3->rbuf.buf == NULL) {
len = SSL3_RT_MAX_PLAIN_LENGTH
+ SSL3_RT_MAX_ENCRYPTED_OVERHEAD + headerlen + align;
if (s->options & SSL_OP_MICROSOFT_BIG_SSLV3_BUFFER) {
s->s3->init_extra = 1;
len += SSL3_RT_MAX_EXTRA;
}
#ifndef OPENSSL_NO_COMP
if (!(s->options & SSL_OP_NO_COMPRESSION))
len += SSL3_RT_MAX_COMPRESSED_OVERHEAD;
#endif
if ((p = freelist_extract(s->ctx, 1, len)) == NULL)
goto err;
s->s3->rbuf.buf = p;
s->s3->rbuf.len = len;
}
s->packet = &(s->s3->rbuf.buf[0]);
return 1;
err:
SSLerr(SSL_F_SSL3_SETUP_READ_BUFFER, ERR_R_MALLOC_FAILURE);
return 0;
}
int ssl3_setup_write_buffer(SSL *s)
{
unsigned char *p;
size_t len, align = 0, headerlen;
if (SSL_version(s) == DTLS1_VERSION || SSL_version(s) == DTLS1_BAD_VER)
headerlen = DTLS1_RT_HEADER_LENGTH + 1;
else
headerlen = SSL3_RT_HEADER_LENGTH;
#if defined(SSL3_ALIGN_PAYLOAD) && SSL3_ALIGN_PAYLOAD!=0
align = (-SSL3_RT_HEADER_LENGTH) & (SSL3_ALIGN_PAYLOAD - 1);
#endif
if (s->s3->wbuf.buf == NULL) {
len = s->max_send_fragment
+ SSL3_RT_SEND_MAX_ENCRYPTED_OVERHEAD + headerlen + align;
#ifndef OPENSSL_NO_COMP
if (!(s->options & SSL_OP_NO_COMPRESSION))
len += SSL3_RT_MAX_COMPRESSED_OVERHEAD;
#endif
if (!(s->options & SSL_OP_DONT_INSERT_EMPTY_FRAGMENTS))
len += headerlen + align + SSL3_RT_SEND_MAX_ENCRYPTED_OVERHEAD;
if ((p = freelist_extract(s->ctx, 0, len)) == NULL)
goto err;
s->s3->wbuf.buf = p;
s->s3->wbuf.len = len;
}
return 1;
err:
SSLerr(SSL_F_SSL3_SETUP_WRITE_BUFFER, ERR_R_MALLOC_FAILURE);
return 0;
}
int ssl3_setup_buffers(SSL *s)
{
if (!ssl3_setup_read_buffer(s))
return 0;
if (!ssl3_setup_write_buffer(s))
return 0;
return 1;
}
int ssl3_release_write_buffer(SSL *s)
{
if (s->s3->wbuf.buf != NULL) {
freelist_insert(s->ctx, 0, s->s3->wbuf.len, s->s3->wbuf.buf);
s->s3->wbuf.buf = NULL;
}
return 1;
}
int ssl3_release_read_buffer(SSL *s)
{
if (s->s3->rbuf.buf != NULL) {
freelist_insert(s->ctx, 1, s->s3->rbuf.len, s->s3->rbuf.buf);
s->s3->rbuf.buf = NULL;
}
return 1;
}
