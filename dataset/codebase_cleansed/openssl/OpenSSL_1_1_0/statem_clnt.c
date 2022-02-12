static ossl_inline int cert_req_allowed(SSL *s)
{
if ((s->version > SSL3_VERSION
&& (s->s3->tmp.new_cipher->algorithm_auth & SSL_aNULL))
|| (s->s3->tmp.new_cipher->algorithm_auth & (SSL_aSRP | SSL_aPSK)))
return 0;
return 1;
}
static int key_exchange_expected(SSL *s)
{
long alg_k = s->s3->tmp.new_cipher->algorithm_mkey;
if (alg_k & (SSL_kDHE | SSL_kECDHE | SSL_kDHEPSK | SSL_kECDHEPSK
| SSL_kSRP)) {
return 1;
}
return 0;
}
int ossl_statem_client_read_transition(SSL *s, int mt)
{
OSSL_STATEM *st = &s->statem;
int ske_expected;
switch (st->hand_state) {
case TLS_ST_CW_CLNT_HELLO:
if (mt == SSL3_MT_SERVER_HELLO) {
st->hand_state = TLS_ST_CR_SRVR_HELLO;
return 1;
}
if (SSL_IS_DTLS(s)) {
if (mt == DTLS1_MT_HELLO_VERIFY_REQUEST) {
st->hand_state = DTLS_ST_CR_HELLO_VERIFY_REQUEST;
return 1;
}
}
break;
case TLS_ST_CR_SRVR_HELLO:
if (s->hit) {
if (s->tlsext_ticket_expected) {
if (mt == SSL3_MT_NEWSESSION_TICKET) {
st->hand_state = TLS_ST_CR_SESSION_TICKET;
return 1;
}
} else if (mt == SSL3_MT_CHANGE_CIPHER_SPEC) {
st->hand_state = TLS_ST_CR_CHANGE;
return 1;
}
} else {
if (SSL_IS_DTLS(s) && mt == DTLS1_MT_HELLO_VERIFY_REQUEST) {
st->hand_state = DTLS_ST_CR_HELLO_VERIFY_REQUEST;
return 1;
} else if (s->version >= TLS1_VERSION
&& s->tls_session_secret_cb != NULL
&& s->session->tlsext_tick != NULL
&& mt == SSL3_MT_CHANGE_CIPHER_SPEC) {
s->hit = 1;
st->hand_state = TLS_ST_CR_CHANGE;
return 1;
} else if (!(s->s3->tmp.new_cipher->algorithm_auth
& (SSL_aNULL | SSL_aSRP | SSL_aPSK))) {
if (mt == SSL3_MT_CERTIFICATE) {
st->hand_state = TLS_ST_CR_CERT;
return 1;
}
} else {
ske_expected = key_exchange_expected(s);
if (ske_expected
|| ((s->s3->tmp.new_cipher->algorithm_mkey & SSL_PSK)
&& mt == SSL3_MT_SERVER_KEY_EXCHANGE)) {
if (mt == SSL3_MT_SERVER_KEY_EXCHANGE) {
st->hand_state = TLS_ST_CR_KEY_EXCH;
return 1;
}
} else if (mt == SSL3_MT_CERTIFICATE_REQUEST
&& cert_req_allowed(s)) {
st->hand_state = TLS_ST_CR_CERT_REQ;
return 1;
} else if (mt == SSL3_MT_SERVER_DONE) {
st->hand_state = TLS_ST_CR_SRVR_DONE;
return 1;
}
}
}
break;
case TLS_ST_CR_CERT:
if (s->tlsext_status_expected && mt == SSL3_MT_CERTIFICATE_STATUS) {
st->hand_state = TLS_ST_CR_CERT_STATUS;
return 1;
}
case TLS_ST_CR_CERT_STATUS:
ske_expected = key_exchange_expected(s);
if (ske_expected || ((s->s3->tmp.new_cipher->algorithm_mkey & SSL_PSK)
&& mt == SSL3_MT_SERVER_KEY_EXCHANGE)) {
if (mt == SSL3_MT_SERVER_KEY_EXCHANGE) {
st->hand_state = TLS_ST_CR_KEY_EXCH;
return 1;
}
goto err;
}
case TLS_ST_CR_KEY_EXCH:
if (mt == SSL3_MT_CERTIFICATE_REQUEST) {
if (cert_req_allowed(s)) {
st->hand_state = TLS_ST_CR_CERT_REQ;
return 1;
}
goto err;
}
case TLS_ST_CR_CERT_REQ:
if (mt == SSL3_MT_SERVER_DONE) {
st->hand_state = TLS_ST_CR_SRVR_DONE;
return 1;
}
break;
case TLS_ST_CW_FINISHED:
if (s->tlsext_ticket_expected) {
if (mt == SSL3_MT_NEWSESSION_TICKET) {
st->hand_state = TLS_ST_CR_SESSION_TICKET;
return 1;
}
} else if (mt == SSL3_MT_CHANGE_CIPHER_SPEC) {
st->hand_state = TLS_ST_CR_CHANGE;
return 1;
}
break;
case TLS_ST_CR_SESSION_TICKET:
if (mt == SSL3_MT_CHANGE_CIPHER_SPEC) {
st->hand_state = TLS_ST_CR_CHANGE;
return 1;
}
break;
case TLS_ST_CR_CHANGE:
if (mt == SSL3_MT_FINISHED) {
st->hand_state = TLS_ST_CR_FINISHED;
return 1;
}
break;
default:
break;
}
err:
ssl3_send_alert(s, SSL3_AL_FATAL, SSL3_AD_UNEXPECTED_MESSAGE);
SSLerr(SSL_F_OSSL_STATEM_CLIENT_READ_TRANSITION, SSL_R_UNEXPECTED_MESSAGE);
return 0;
}
WRITE_TRAN ossl_statem_client_write_transition(SSL *s)
{
OSSL_STATEM *st = &s->statem;
switch (st->hand_state) {
case TLS_ST_OK:
case TLS_ST_BEFORE:
st->hand_state = TLS_ST_CW_CLNT_HELLO;
return WRITE_TRAN_CONTINUE;
case TLS_ST_CW_CLNT_HELLO:
return WRITE_TRAN_FINISHED;
case DTLS_ST_CR_HELLO_VERIFY_REQUEST:
st->hand_state = TLS_ST_CW_CLNT_HELLO;
return WRITE_TRAN_CONTINUE;
case TLS_ST_CR_SRVR_DONE:
if (s->s3->tmp.cert_req)
st->hand_state = TLS_ST_CW_CERT;
else
st->hand_state = TLS_ST_CW_KEY_EXCH;
return WRITE_TRAN_CONTINUE;
case TLS_ST_CW_CERT:
st->hand_state = TLS_ST_CW_KEY_EXCH;
return WRITE_TRAN_CONTINUE;
case TLS_ST_CW_KEY_EXCH:
if (s->s3->tmp.cert_req == 1) {
st->hand_state = TLS_ST_CW_CERT_VRFY;
} else {
st->hand_state = TLS_ST_CW_CHANGE;
}
if (s->s3->flags & TLS1_FLAGS_SKIP_CERT_VERIFY) {
st->hand_state = TLS_ST_CW_CHANGE;
}
return WRITE_TRAN_CONTINUE;
case TLS_ST_CW_CERT_VRFY:
st->hand_state = TLS_ST_CW_CHANGE;
return WRITE_TRAN_CONTINUE;
case TLS_ST_CW_CHANGE:
#if defined(OPENSSL_NO_NEXTPROTONEG)
st->hand_state = TLS_ST_CW_FINISHED;
#else
if (!SSL_IS_DTLS(s) && s->s3->next_proto_neg_seen)
st->hand_state = TLS_ST_CW_NEXT_PROTO;
else
st->hand_state = TLS_ST_CW_FINISHED;
#endif
return WRITE_TRAN_CONTINUE;
#if !defined(OPENSSL_NO_NEXTPROTONEG)
case TLS_ST_CW_NEXT_PROTO:
st->hand_state = TLS_ST_CW_FINISHED;
return WRITE_TRAN_CONTINUE;
#endif
case TLS_ST_CW_FINISHED:
if (s->hit) {
st->hand_state = TLS_ST_OK;
ossl_statem_set_in_init(s, 0);
return WRITE_TRAN_CONTINUE;
} else {
return WRITE_TRAN_FINISHED;
}
case TLS_ST_CR_FINISHED:
if (s->hit) {
st->hand_state = TLS_ST_CW_CHANGE;
return WRITE_TRAN_CONTINUE;
} else {
st->hand_state = TLS_ST_OK;
ossl_statem_set_in_init(s, 0);
return WRITE_TRAN_CONTINUE;
}
default:
return WRITE_TRAN_ERROR;
}
}
WORK_STATE ossl_statem_client_pre_work(SSL *s, WORK_STATE wst)
{
OSSL_STATEM *st = &s->statem;
switch (st->hand_state) {
case TLS_ST_CW_CLNT_HELLO:
s->shutdown = 0;
if (SSL_IS_DTLS(s)) {
if (!ssl3_init_finished_mac(s)) {
ossl_statem_set_error(s);
return WORK_ERROR;
}
}
break;
case TLS_ST_CW_CHANGE:
if (SSL_IS_DTLS(s)) {
if (s->hit) {
st->use_timer = 0;
}
#ifndef OPENSSL_NO_SCTP
if (BIO_dgram_is_sctp(SSL_get_wbio(s)))
return dtls_wait_for_dry(s);
#endif
}
return WORK_FINISHED_CONTINUE;
case TLS_ST_OK:
return tls_finish_handshake(s, wst);
default:
break;
}
return WORK_FINISHED_CONTINUE;
}
WORK_STATE ossl_statem_client_post_work(SSL *s, WORK_STATE wst)
{
OSSL_STATEM *st = &s->statem;
s->init_num = 0;
switch (st->hand_state) {
case TLS_ST_CW_CLNT_HELLO:
if (wst == WORK_MORE_A && statem_flush(s) != 1)
return WORK_MORE_A;
if (SSL_IS_DTLS(s)) {
s->first_packet = 1;
}
break;
case TLS_ST_CW_KEY_EXCH:
if (tls_client_key_exchange_post_work(s) == 0)
return WORK_ERROR;
break;
case TLS_ST_CW_CHANGE:
s->session->cipher = s->s3->tmp.new_cipher;
#ifdef OPENSSL_NO_COMP
s->session->compress_meth = 0;
#else
if (s->s3->tmp.new_compression == NULL)
s->session->compress_meth = 0;
else
s->session->compress_meth = s->s3->tmp.new_compression->id;
#endif
if (!s->method->ssl3_enc->setup_key_block(s))
return WORK_ERROR;
if (!s->method->ssl3_enc->change_cipher_state(s,
SSL3_CHANGE_CIPHER_CLIENT_WRITE))
return WORK_ERROR;
if (SSL_IS_DTLS(s)) {
#ifndef OPENSSL_NO_SCTP
if (s->hit) {
BIO_ctrl(SSL_get_wbio(s), BIO_CTRL_DGRAM_SCTP_NEXT_AUTH_KEY,
0, NULL);
}
#endif
dtls1_reset_seq_numbers(s, SSL3_CC_WRITE);
}
break;
case TLS_ST_CW_FINISHED:
#ifndef OPENSSL_NO_SCTP
if (wst == WORK_MORE_A && SSL_IS_DTLS(s) && s->hit == 0) {
BIO_ctrl(SSL_get_wbio(s), BIO_CTRL_DGRAM_SCTP_NEXT_AUTH_KEY,
0, NULL);
}
#endif
if (statem_flush(s) != 1)
return WORK_MORE_B;
break;
default:
break;
}
return WORK_FINISHED_CONTINUE;
}
int ossl_statem_client_construct_message(SSL *s)
{
OSSL_STATEM *st = &s->statem;
switch (st->hand_state) {
case TLS_ST_CW_CLNT_HELLO:
return tls_construct_client_hello(s);
case TLS_ST_CW_CERT:
return tls_construct_client_certificate(s);
case TLS_ST_CW_KEY_EXCH:
return tls_construct_client_key_exchange(s);
case TLS_ST_CW_CERT_VRFY:
return tls_construct_client_verify(s);
case TLS_ST_CW_CHANGE:
if (SSL_IS_DTLS(s))
return dtls_construct_change_cipher_spec(s);
else
return tls_construct_change_cipher_spec(s);
#if !defined(OPENSSL_NO_NEXTPROTONEG)
case TLS_ST_CW_NEXT_PROTO:
return tls_construct_next_proto(s);
#endif
case TLS_ST_CW_FINISHED:
return tls_construct_finished(s,
s->method->
ssl3_enc->client_finished_label,
s->method->
ssl3_enc->client_finished_label_len);
default:
break;
}
return 0;
}
unsigned long ossl_statem_client_max_message_size(SSL *s)
{
OSSL_STATEM *st = &s->statem;
switch (st->hand_state) {
case TLS_ST_CR_SRVR_HELLO:
return SERVER_HELLO_MAX_LENGTH;
case DTLS_ST_CR_HELLO_VERIFY_REQUEST:
return HELLO_VERIFY_REQUEST_MAX_LENGTH;
case TLS_ST_CR_CERT:
return s->max_cert_list;
case TLS_ST_CR_CERT_STATUS:
return SSL3_RT_MAX_PLAIN_LENGTH;
case TLS_ST_CR_KEY_EXCH:
return SERVER_KEY_EXCH_MAX_LENGTH;
case TLS_ST_CR_CERT_REQ:
return s->max_cert_list;
case TLS_ST_CR_SRVR_DONE:
return SERVER_HELLO_DONE_MAX_LENGTH;
case TLS_ST_CR_CHANGE:
if (s->version == DTLS1_BAD_VER)
return 3;
return CCS_MAX_LENGTH;
case TLS_ST_CR_SESSION_TICKET:
return SSL3_RT_MAX_PLAIN_LENGTH;
case TLS_ST_CR_FINISHED:
return FINISHED_MAX_LENGTH;
default:
break;
}
return 0;
}
MSG_PROCESS_RETURN ossl_statem_client_process_message(SSL *s, PACKET *pkt)
{
OSSL_STATEM *st = &s->statem;
switch (st->hand_state) {
case TLS_ST_CR_SRVR_HELLO:
return tls_process_server_hello(s, pkt);
case DTLS_ST_CR_HELLO_VERIFY_REQUEST:
return dtls_process_hello_verify(s, pkt);
case TLS_ST_CR_CERT:
return tls_process_server_certificate(s, pkt);
case TLS_ST_CR_CERT_STATUS:
return tls_process_cert_status(s, pkt);
case TLS_ST_CR_KEY_EXCH:
return tls_process_key_exchange(s, pkt);
case TLS_ST_CR_CERT_REQ:
return tls_process_certificate_request(s, pkt);
case TLS_ST_CR_SRVR_DONE:
return tls_process_server_done(s, pkt);
case TLS_ST_CR_CHANGE:
return tls_process_change_cipher_spec(s, pkt);
case TLS_ST_CR_SESSION_TICKET:
return tls_process_new_session_ticket(s, pkt);
case TLS_ST_CR_FINISHED:
return tls_process_finished(s, pkt);
default:
break;
}
return MSG_PROCESS_ERROR;
}
WORK_STATE ossl_statem_client_post_process_message(SSL *s, WORK_STATE wst)
{
OSSL_STATEM *st = &s->statem;
switch (st->hand_state) {
case TLS_ST_CR_CERT_REQ:
return tls_prepare_client_certificate(s, wst);
#ifndef OPENSSL_NO_SCTP
case TLS_ST_CR_SRVR_DONE:
if (BIO_dgram_sctp_msg_waiting(SSL_get_rbio(s))) {
s->s3->in_read_app_data = 2;
s->rwstate = SSL_READING;
BIO_clear_retry_flags(SSL_get_rbio(s));
BIO_set_retry_read(SSL_get_rbio(s));
ossl_statem_set_sctp_read_sock(s, 1);
return WORK_MORE_A;
}
ossl_statem_set_sctp_read_sock(s, 0);
return WORK_FINISHED_STOP;
#endif
default:
break;
}
return WORK_ERROR;
}
int tls_construct_client_hello(SSL *s)
{
unsigned char *buf;
unsigned char *p, *d;
int i;
int protverr;
unsigned long l;
int al = 0;
#ifndef OPENSSL_NO_COMP
int j;
SSL_COMP *comp;
#endif
SSL_SESSION *sess = s->session;
buf = (unsigned char *)s->init_buf->data;
protverr = ssl_set_client_hello_version(s);
if (protverr != 0) {
SSLerr(SSL_F_TLS_CONSTRUCT_CLIENT_HELLO, protverr);
goto err;
}
if ((sess == NULL) || !ssl_version_supported(s, sess->ssl_version) ||
(!sess->session_id_length && !sess->tlsext_tick) ||
(sess->not_resumable)) {
if (!ssl_get_new_session(s, 0))
goto err;
}
p = s->s3->client_random;
if (SSL_IS_DTLS(s)) {
size_t idx;
i = 1;
for (idx = 0; idx < sizeof(s->s3->client_random); idx++) {
if (p[idx]) {
i = 0;
break;
}
}
} else
i = 1;
if (i && ssl_fill_hello_random(s, 0, p, sizeof(s->s3->client_random)) <= 0)
goto err;
d = p = ssl_handshake_start(s);
*(p++) = s->client_version >> 8;
*(p++) = s->client_version & 0xff;
memcpy(p, s->s3->client_random, SSL3_RANDOM_SIZE);
p += SSL3_RANDOM_SIZE;
if (s->new_session)
i = 0;
else
i = s->session->session_id_length;
*(p++) = i;
if (i != 0) {
if (i > (int)sizeof(s->session->session_id)) {
SSLerr(SSL_F_TLS_CONSTRUCT_CLIENT_HELLO, ERR_R_INTERNAL_ERROR);
goto err;
}
memcpy(p, s->session->session_id, i);
p += i;
}
if (SSL_IS_DTLS(s)) {
if (s->d1->cookie_len > sizeof(s->d1->cookie)) {
SSLerr(SSL_F_TLS_CONSTRUCT_CLIENT_HELLO, ERR_R_INTERNAL_ERROR);
goto err;
}
*(p++) = s->d1->cookie_len;
memcpy(p, s->d1->cookie, s->d1->cookie_len);
p += s->d1->cookie_len;
}
i = ssl_cipher_list_to_bytes(s, SSL_get_ciphers(s), &(p[2]));
if (i == 0) {
SSLerr(SSL_F_TLS_CONSTRUCT_CLIENT_HELLO, SSL_R_NO_CIPHERS_AVAILABLE);
goto err;
}
#ifdef OPENSSL_MAX_TLS1_2_CIPHER_LENGTH
if (TLS1_get_version(s) >= TLS1_2_VERSION
&& i > OPENSSL_MAX_TLS1_2_CIPHER_LENGTH)
i = OPENSSL_MAX_TLS1_2_CIPHER_LENGTH & ~1;
#endif
s2n(i, p);
p += i;
#ifdef OPENSSL_NO_COMP
*(p++) = 1;
#else
if (!ssl_allow_compression(s) || !s->ctx->comp_methods)
j = 0;
else
j = sk_SSL_COMP_num(s->ctx->comp_methods);
*(p++) = 1 + j;
for (i = 0; i < j; i++) {
comp = sk_SSL_COMP_value(s->ctx->comp_methods, i);
*(p++) = comp->id;
}
#endif
*(p++) = 0;
if (ssl_prepare_clienthello_tlsext(s) <= 0) {
SSLerr(SSL_F_TLS_CONSTRUCT_CLIENT_HELLO, SSL_R_CLIENTHELLO_TLSEXT);
goto err;
}
if ((p =
ssl_add_clienthello_tlsext(s, p, buf + SSL3_RT_MAX_PLAIN_LENGTH,
&al)) == NULL) {
ssl3_send_alert(s, SSL3_AL_FATAL, al);
SSLerr(SSL_F_TLS_CONSTRUCT_CLIENT_HELLO, ERR_R_INTERNAL_ERROR);
goto err;
}
l = p - d;
if (!ssl_set_handshake_header(s, SSL3_MT_CLIENT_HELLO, l)) {
ssl3_send_alert(s, SSL3_AL_FATAL, SSL_AD_HANDSHAKE_FAILURE);
SSLerr(SSL_F_TLS_CONSTRUCT_CLIENT_HELLO, ERR_R_INTERNAL_ERROR);
goto err;
}
return 1;
err:
ossl_statem_set_error(s);
return 0;
}
MSG_PROCESS_RETURN dtls_process_hello_verify(SSL *s, PACKET *pkt)
{
int al;
unsigned int cookie_len;
PACKET cookiepkt;
if (!PACKET_forward(pkt, 2)
|| !PACKET_get_length_prefixed_1(pkt, &cookiepkt)) {
al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_DTLS_PROCESS_HELLO_VERIFY, SSL_R_LENGTH_MISMATCH);
goto f_err;
}
cookie_len = PACKET_remaining(&cookiepkt);
if (cookie_len > sizeof(s->d1->cookie)) {
al = SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_DTLS_PROCESS_HELLO_VERIFY, SSL_R_LENGTH_TOO_LONG);
goto f_err;
}
if (!PACKET_copy_bytes(&cookiepkt, s->d1->cookie, cookie_len)) {
al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_DTLS_PROCESS_HELLO_VERIFY, SSL_R_LENGTH_MISMATCH);
goto f_err;
}
s->d1->cookie_len = cookie_len;
return MSG_PROCESS_FINISHED_READING;
f_err:
ssl3_send_alert(s, SSL3_AL_FATAL, al);
ossl_statem_set_error(s);
return MSG_PROCESS_ERROR;
}
MSG_PROCESS_RETURN tls_process_server_hello(SSL *s, PACKET *pkt)
{
STACK_OF(SSL_CIPHER) *sk;
const SSL_CIPHER *c;
PACKET session_id;
size_t session_id_len;
const unsigned char *cipherchars;
int i, al = SSL_AD_INTERNAL_ERROR;
unsigned int compression;
unsigned int sversion;
int protverr;
#ifndef OPENSSL_NO_COMP
SSL_COMP *comp;
#endif
if (!PACKET_get_net_2(pkt, &sversion)) {
al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_SERVER_HELLO, SSL_R_LENGTH_MISMATCH);
goto f_err;
}
protverr = ssl_choose_client_version(s, sversion);
if (protverr != 0) {
al = SSL_AD_PROTOCOL_VERSION;
SSLerr(SSL_F_TLS_PROCESS_SERVER_HELLO, protverr);
goto f_err;
}
if (!PACKET_copy_bytes(pkt, s->s3->server_random, SSL3_RANDOM_SIZE)) {
al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_SERVER_HELLO, SSL_R_LENGTH_MISMATCH);
goto f_err;
}
s->hit = 0;
if (!PACKET_get_length_prefixed_1(pkt, &session_id)) {
al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_SERVER_HELLO, SSL_R_LENGTH_MISMATCH);
goto f_err;
}
session_id_len = PACKET_remaining(&session_id);
if (session_id_len > sizeof s->session->session_id
|| session_id_len > SSL3_SESSION_ID_SIZE) {
al = SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_TLS_PROCESS_SERVER_HELLO, SSL_R_SSL3_SESSION_ID_TOO_LONG);
goto f_err;
}
if (!PACKET_get_bytes(pkt, &cipherchars, TLS_CIPHER_LEN)) {
SSLerr(SSL_F_TLS_PROCESS_SERVER_HELLO, SSL_R_LENGTH_MISMATCH);
al = SSL_AD_DECODE_ERROR;
goto f_err;
}
if (s->version >= TLS1_VERSION && s->tls_session_secret_cb &&
s->session->tlsext_tick) {
const SSL_CIPHER *pref_cipher = NULL;
s->session->master_key_length = sizeof(s->session->master_key);
if (s->tls_session_secret_cb(s, s->session->master_key,
&s->session->master_key_length,
NULL, &pref_cipher,
s->tls_session_secret_cb_arg)) {
s->session->cipher = pref_cipher ?
pref_cipher : ssl_get_cipher_by_char(s, cipherchars);
} else {
SSLerr(SSL_F_TLS_PROCESS_SERVER_HELLO, ERR_R_INTERNAL_ERROR);
al = SSL_AD_INTERNAL_ERROR;
goto f_err;
}
}
if (session_id_len != 0 && session_id_len == s->session->session_id_length
&& memcmp(PACKET_data(&session_id), s->session->session_id,
session_id_len) == 0) {
if (s->sid_ctx_length != s->session->sid_ctx_length
|| memcmp(s->session->sid_ctx, s->sid_ctx, s->sid_ctx_length)) {
al = SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_TLS_PROCESS_SERVER_HELLO,
SSL_R_ATTEMPT_TO_REUSE_SESSION_IN_DIFFERENT_CONTEXT);
goto f_err;
}
s->hit = 1;
} else {
if (s->session->session_id_length > 0) {
s->ctx->stats.sess_miss++;
if (!ssl_get_new_session(s, 0)) {
goto f_err;
}
}
s->session->ssl_version = s->version;
s->session->session_id_length = session_id_len;
memcpy(s->session->session_id, PACKET_data(&session_id),
session_id_len);
}
if (s->version != s->session->ssl_version) {
al = SSL_AD_PROTOCOL_VERSION;
SSLerr(SSL_F_TLS_PROCESS_SERVER_HELLO,
SSL_R_SSL_SESSION_VERSION_MISMATCH);
goto f_err;
}
c = ssl_get_cipher_by_char(s, cipherchars);
if (c == NULL) {
al = SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_TLS_PROCESS_SERVER_HELLO, SSL_R_UNKNOWN_CIPHER_RETURNED);
goto f_err;
}
s->s3->tmp.min_ver = s->version;
s->s3->tmp.max_ver = s->version;
if (ssl_cipher_disabled(s, c, SSL_SECOP_CIPHER_CHECK)) {
al = SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_TLS_PROCESS_SERVER_HELLO, SSL_R_WRONG_CIPHER_RETURNED);
goto f_err;
}
sk = ssl_get_ciphers_by_id(s);
i = sk_SSL_CIPHER_find(sk, c);
if (i < 0) {
al = SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_TLS_PROCESS_SERVER_HELLO, SSL_R_WRONG_CIPHER_RETURNED);
goto f_err;
}
if (s->session->cipher)
s->session->cipher_id = s->session->cipher->id;
if (s->hit && (s->session->cipher_id != c->id)) {
al = SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_TLS_PROCESS_SERVER_HELLO,
SSL_R_OLD_SESSION_CIPHER_NOT_RETURNED);
goto f_err;
}
s->s3->tmp.new_cipher = c;
if (!PACKET_get_1(pkt, &compression)) {
SSLerr(SSL_F_TLS_PROCESS_SERVER_HELLO, SSL_R_LENGTH_MISMATCH);
al = SSL_AD_DECODE_ERROR;
goto f_err;
}
#ifdef OPENSSL_NO_COMP
if (compression != 0) {
al = SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_TLS_PROCESS_SERVER_HELLO,
SSL_R_UNSUPPORTED_COMPRESSION_ALGORITHM);
goto f_err;
}
if (s->session->compress_meth != 0) {
SSLerr(SSL_F_TLS_PROCESS_SERVER_HELLO, SSL_R_INCONSISTENT_COMPRESSION);
goto f_err;
}
#else
if (s->hit && compression != s->session->compress_meth) {
al = SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_TLS_PROCESS_SERVER_HELLO,
SSL_R_OLD_SESSION_COMPRESSION_ALGORITHM_NOT_RETURNED);
goto f_err;
}
if (compression == 0)
comp = NULL;
else if (!ssl_allow_compression(s)) {
al = SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_TLS_PROCESS_SERVER_HELLO, SSL_R_COMPRESSION_DISABLED);
goto f_err;
} else {
comp = ssl3_comp_find(s->ctx->comp_methods, compression);
}
if (compression != 0 && comp == NULL) {
al = SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_TLS_PROCESS_SERVER_HELLO,
SSL_R_UNSUPPORTED_COMPRESSION_ALGORITHM);
goto f_err;
} else {
s->s3->tmp.new_compression = comp;
}
#endif
if (!ssl_parse_serverhello_tlsext(s, pkt)) {
SSLerr(SSL_F_TLS_PROCESS_SERVER_HELLO, SSL_R_PARSE_TLSEXT);
goto err;
}
if (PACKET_remaining(pkt) != 0) {
al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_SERVER_HELLO, SSL_R_BAD_PACKET_LENGTH);
goto f_err;
}
#ifndef OPENSSL_NO_SCTP
if (SSL_IS_DTLS(s) && s->hit) {
unsigned char sctpauthkey[64];
char labelbuffer[sizeof(DTLS1_SCTP_AUTH_LABEL)];
memcpy(labelbuffer, DTLS1_SCTP_AUTH_LABEL,
sizeof(DTLS1_SCTP_AUTH_LABEL));
if (SSL_export_keying_material(s, sctpauthkey,
sizeof(sctpauthkey),
labelbuffer,
sizeof(labelbuffer), NULL, 0, 0) <= 0)
goto err;
BIO_ctrl(SSL_get_wbio(s),
BIO_CTRL_DGRAM_SCTP_ADD_AUTH_KEY,
sizeof(sctpauthkey), sctpauthkey);
}
#endif
return MSG_PROCESS_CONTINUE_READING;
f_err:
ssl3_send_alert(s, SSL3_AL_FATAL, al);
err:
ossl_statem_set_error(s);
return MSG_PROCESS_ERROR;
}
MSG_PROCESS_RETURN tls_process_server_certificate(SSL *s, PACKET *pkt)
{
int al, i, ret = MSG_PROCESS_ERROR, exp_idx;
unsigned long cert_list_len, cert_len;
X509 *x = NULL;
const unsigned char *certstart, *certbytes;
STACK_OF(X509) *sk = NULL;
EVP_PKEY *pkey = NULL;
if ((sk = sk_X509_new_null()) == NULL) {
SSLerr(SSL_F_TLS_PROCESS_SERVER_CERTIFICATE, ERR_R_MALLOC_FAILURE);
goto err;
}
if (!PACKET_get_net_3(pkt, &cert_list_len)
|| PACKET_remaining(pkt) != cert_list_len) {
al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_SERVER_CERTIFICATE, SSL_R_LENGTH_MISMATCH);
goto f_err;
}
while (PACKET_remaining(pkt)) {
if (!PACKET_get_net_3(pkt, &cert_len)
|| !PACKET_get_bytes(pkt, &certbytes, cert_len)) {
al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_SERVER_CERTIFICATE,
SSL_R_CERT_LENGTH_MISMATCH);
goto f_err;
}
certstart = certbytes;
x = d2i_X509(NULL, (const unsigned char **)&certbytes, cert_len);
if (x == NULL) {
al = SSL_AD_BAD_CERTIFICATE;
SSLerr(SSL_F_TLS_PROCESS_SERVER_CERTIFICATE, ERR_R_ASN1_LIB);
goto f_err;
}
if (certbytes != (certstart + cert_len)) {
al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_SERVER_CERTIFICATE,
SSL_R_CERT_LENGTH_MISMATCH);
goto f_err;
}
if (!sk_X509_push(sk, x)) {
SSLerr(SSL_F_TLS_PROCESS_SERVER_CERTIFICATE, ERR_R_MALLOC_FAILURE);
goto err;
}
x = NULL;
}
i = ssl_verify_cert_chain(s, sk);
if ((s->verify_mode & SSL_VERIFY_PEER) && i <= 0) {
al = ssl_verify_alarm_type(s->verify_result);
SSLerr(SSL_F_TLS_PROCESS_SERVER_CERTIFICATE,
SSL_R_CERTIFICATE_VERIFY_FAILED);
goto f_err;
}
ERR_clear_error();
if (i > 1) {
SSLerr(SSL_F_TLS_PROCESS_SERVER_CERTIFICATE, i);
al = SSL_AD_HANDSHAKE_FAILURE;
goto f_err;
}
s->session->peer_chain = sk;
x = sk_X509_value(sk, 0);
sk = NULL;
pkey = X509_get0_pubkey(x);
if (pkey == NULL || EVP_PKEY_missing_parameters(pkey)) {
x = NULL;
al = SSL3_AL_FATAL;
SSLerr(SSL_F_TLS_PROCESS_SERVER_CERTIFICATE,
SSL_R_UNABLE_TO_FIND_PUBLIC_KEY_PARAMETERS);
goto f_err;
}
i = ssl_cert_type(x, pkey);
if (i < 0) {
x = NULL;
al = SSL3_AL_FATAL;
SSLerr(SSL_F_TLS_PROCESS_SERVER_CERTIFICATE,
SSL_R_UNKNOWN_CERTIFICATE_TYPE);
goto f_err;
}
exp_idx = ssl_cipher_get_cert_index(s->s3->tmp.new_cipher);
if (exp_idx >= 0 && i != exp_idx
&& (exp_idx != SSL_PKEY_GOST_EC ||
(i != SSL_PKEY_GOST12_512 && i != SSL_PKEY_GOST12_256
&& i != SSL_PKEY_GOST01))) {
x = NULL;
al = SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_TLS_PROCESS_SERVER_CERTIFICATE,
SSL_R_WRONG_CERTIFICATE_TYPE);
goto f_err;
}
s->session->peer_type = i;
X509_free(s->session->peer);
X509_up_ref(x);
s->session->peer = x;
s->session->verify_result = s->verify_result;
x = NULL;
ret = MSG_PROCESS_CONTINUE_READING;
goto done;
f_err:
ssl3_send_alert(s, SSL3_AL_FATAL, al);
err:
ossl_statem_set_error(s);
done:
X509_free(x);
sk_X509_pop_free(sk, X509_free);
return ret;
}
static int tls_process_ske_psk_preamble(SSL *s, PACKET *pkt, int *al)
{
#ifndef OPENSSL_NO_PSK
PACKET psk_identity_hint;
if (!PACKET_get_length_prefixed_2(pkt, &psk_identity_hint)) {
*al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_SKE_PSK_PREAMBLE, SSL_R_LENGTH_MISMATCH);
return 0;
}
if (PACKET_remaining(&psk_identity_hint) > PSK_MAX_IDENTITY_LEN) {
*al = SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_TLS_PROCESS_SKE_PSK_PREAMBLE, SSL_R_DATA_LENGTH_TOO_LONG);
return 0;
}
if (PACKET_remaining(&psk_identity_hint) == 0) {
OPENSSL_free(s->session->psk_identity_hint);
s->session->psk_identity_hint = NULL;
} else if (!PACKET_strndup(&psk_identity_hint,
&s->session->psk_identity_hint)) {
*al = SSL_AD_INTERNAL_ERROR;
return 0;
}
return 1;
#else
SSLerr(SSL_F_TLS_PROCESS_SKE_PSK_PREAMBLE, ERR_R_INTERNAL_ERROR);
*al = SSL_AD_INTERNAL_ERROR;
return 0;
#endif
}
static int tls_process_ske_srp(SSL *s, PACKET *pkt, EVP_PKEY **pkey, int *al)
{
#ifndef OPENSSL_NO_SRP
PACKET prime, generator, salt, server_pub;
if (!PACKET_get_length_prefixed_2(pkt, &prime)
|| !PACKET_get_length_prefixed_2(pkt, &generator)
|| !PACKET_get_length_prefixed_1(pkt, &salt)
|| !PACKET_get_length_prefixed_2(pkt, &server_pub)) {
*al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_SKE_SRP, SSL_R_LENGTH_MISMATCH);
return 0;
}
if ((s->srp_ctx.N =
BN_bin2bn(PACKET_data(&prime),
PACKET_remaining(&prime), NULL)) == NULL
|| (s->srp_ctx.g =
BN_bin2bn(PACKET_data(&generator),
PACKET_remaining(&generator), NULL)) == NULL
|| (s->srp_ctx.s =
BN_bin2bn(PACKET_data(&salt),
PACKET_remaining(&salt), NULL)) == NULL
|| (s->srp_ctx.B =
BN_bin2bn(PACKET_data(&server_pub),
PACKET_remaining(&server_pub), NULL)) == NULL) {
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_SKE_SRP, ERR_R_BN_LIB);
return 0;
}
if (!srp_verify_server_param(s, al)) {
*al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_SKE_SRP, SSL_R_BAD_SRP_PARAMETERS);
return 0;
}
if (s->s3->tmp.new_cipher->algorithm_auth & (SSL_aRSA | SSL_aDSS))
*pkey = X509_get0_pubkey(s->session->peer);
return 1;
#else
SSLerr(SSL_F_TLS_PROCESS_SKE_SRP, ERR_R_INTERNAL_ERROR);
*al = SSL_AD_INTERNAL_ERROR;
return 0;
#endif
}
static int tls_process_ske_dhe(SSL *s, PACKET *pkt, EVP_PKEY **pkey, int *al)
{
#ifndef OPENSSL_NO_DH
PACKET prime, generator, pub_key;
EVP_PKEY *peer_tmp = NULL;
DH *dh = NULL;
BIGNUM *p = NULL, *g = NULL, *bnpub_key = NULL;
if (!PACKET_get_length_prefixed_2(pkt, &prime)
|| !PACKET_get_length_prefixed_2(pkt, &generator)
|| !PACKET_get_length_prefixed_2(pkt, &pub_key)) {
*al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_SKE_DHE, SSL_R_LENGTH_MISMATCH);
return 0;
}
peer_tmp = EVP_PKEY_new();
dh = DH_new();
if (peer_tmp == NULL || dh == NULL) {
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_SKE_DHE, ERR_R_MALLOC_FAILURE);
goto err;
}
p = BN_bin2bn(PACKET_data(&prime), PACKET_remaining(&prime), NULL);
g = BN_bin2bn(PACKET_data(&generator), PACKET_remaining(&generator), NULL);
bnpub_key = BN_bin2bn(PACKET_data(&pub_key), PACKET_remaining(&pub_key),
NULL);
if (p == NULL || g == NULL || bnpub_key == NULL) {
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_SKE_DHE, ERR_R_BN_LIB);
goto err;
}
if (BN_is_zero(p) || BN_is_zero(g) || BN_is_zero(bnpub_key)) {
*al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_SKE_DHE, SSL_R_BAD_DH_VALUE);
goto err;
}
if (!DH_set0_pqg(dh, p, NULL, g)) {
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_SKE_DHE, ERR_R_BN_LIB);
goto err;
}
p = g = NULL;
if (!DH_set0_key(dh, bnpub_key, NULL)) {
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_SKE_DHE, ERR_R_BN_LIB);
goto err;
}
bnpub_key = NULL;
if (!ssl_security(s, SSL_SECOP_TMP_DH, DH_security_bits(dh), 0, dh)) {
*al = SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_TLS_PROCESS_SKE_DHE, SSL_R_DH_KEY_TOO_SMALL);
goto err;
}
if (EVP_PKEY_assign_DH(peer_tmp, dh) == 0) {
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_SKE_DHE, ERR_R_EVP_LIB);
goto err;
}
s->s3->peer_tmp = peer_tmp;
if (s->s3->tmp.new_cipher->algorithm_auth & (SSL_aRSA | SSL_aDSS))
*pkey = X509_get0_pubkey(s->session->peer);
return 1;
err:
BN_free(p);
BN_free(g);
BN_free(bnpub_key);
DH_free(dh);
EVP_PKEY_free(peer_tmp);
return 0;
#else
SSLerr(SSL_F_TLS_PROCESS_SKE_DHE, ERR_R_INTERNAL_ERROR);
*al = SSL_AD_INTERNAL_ERROR;
return 0;
#endif
}
static int tls_process_ske_ecdhe(SSL *s, PACKET *pkt, EVP_PKEY **pkey, int *al)
{
#ifndef OPENSSL_NO_EC
PACKET encoded_pt;
const unsigned char *ecparams;
int curve_nid;
unsigned int curve_flags;
EVP_PKEY_CTX *pctx = NULL;
if (!PACKET_get_bytes(pkt, &ecparams, 3)) {
*al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_SKE_ECDHE, SSL_R_LENGTH_TOO_SHORT);
return 0;
}
if (!tls1_check_curve(s, ecparams, 3)) {
*al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_SKE_ECDHE, SSL_R_WRONG_CURVE);
return 0;
}
curve_nid = tls1_ec_curve_id2nid(*(ecparams + 2), &curve_flags);
if (curve_nid == 0) {
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_SKE_ECDHE,
SSL_R_UNABLE_TO_FIND_ECDH_PARAMETERS);
return 0;
}
if ((curve_flags & TLS_CURVE_TYPE) == TLS_CURVE_CUSTOM) {
EVP_PKEY *key = EVP_PKEY_new();
if (key == NULL || !EVP_PKEY_set_type(key, curve_nid)) {
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_SKE_ECDHE, ERR_R_EVP_LIB);
EVP_PKEY_free(key);
return 0;
}
s->s3->peer_tmp = key;
} else {
pctx = EVP_PKEY_CTX_new_id(EVP_PKEY_EC, NULL);
if (pctx == NULL
|| EVP_PKEY_paramgen_init(pctx) <= 0
|| EVP_PKEY_CTX_set_ec_paramgen_curve_nid(pctx, curve_nid) <= 0
|| EVP_PKEY_paramgen(pctx, &s->s3->peer_tmp) <= 0) {
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_SKE_ECDHE, ERR_R_EVP_LIB);
EVP_PKEY_CTX_free(pctx);
return 0;
}
EVP_PKEY_CTX_free(pctx);
pctx = NULL;
}
if (!PACKET_get_length_prefixed_1(pkt, &encoded_pt)) {
*al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_SKE_ECDHE, SSL_R_LENGTH_MISMATCH);
return 0;
}
if (!EVP_PKEY_set1_tls_encodedpoint(s->s3->peer_tmp,
PACKET_data(&encoded_pt),
PACKET_remaining(&encoded_pt))) {
*al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_SKE_ECDHE, SSL_R_BAD_ECPOINT);
return 0;
}
if (s->s3->tmp.new_cipher->algorithm_auth & SSL_aECDSA)
*pkey = X509_get0_pubkey(s->session->peer);
else if (s->s3->tmp.new_cipher->algorithm_auth & SSL_aRSA)
*pkey = X509_get0_pubkey(s->session->peer);
return 1;
#else
SSLerr(SSL_F_TLS_PROCESS_SKE_ECDHE, ERR_R_INTERNAL_ERROR);
*al = SSL_AD_INTERNAL_ERROR;
return 0;
#endif
}
MSG_PROCESS_RETURN tls_process_key_exchange(SSL *s, PACKET *pkt)
{
int al = -1;
long alg_k;
EVP_PKEY *pkey = NULL;
PACKET save_param_start, signature;
alg_k = s->s3->tmp.new_cipher->algorithm_mkey;
save_param_start = *pkt;
#if !defined(OPENSSL_NO_EC) || !defined(OPENSSL_NO_DH)
EVP_PKEY_free(s->s3->peer_tmp);
s->s3->peer_tmp = NULL;
#endif
if (alg_k & SSL_PSK) {
if (!tls_process_ske_psk_preamble(s, pkt, &al))
goto err;
}
if (alg_k & (SSL_kPSK | SSL_kRSAPSK)) {
} else if (alg_k & SSL_kSRP) {
if (!tls_process_ske_srp(s, pkt, &pkey, &al))
goto err;
} else if (alg_k & (SSL_kDHE | SSL_kDHEPSK)) {
if (!tls_process_ske_dhe(s, pkt, &pkey, &al))
goto err;
} else if (alg_k & (SSL_kECDHE | SSL_kECDHEPSK)) {
if (!tls_process_ske_ecdhe(s, pkt, &pkey, &al))
goto err;
} else if (alg_k) {
al = SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_TLS_PROCESS_KEY_EXCHANGE, SSL_R_UNEXPECTED_MESSAGE);
goto err;
}
if (pkey != NULL) {
PACKET params;
int maxsig;
const EVP_MD *md = NULL;
EVP_MD_CTX *md_ctx;
if (!PACKET_get_sub_packet(&save_param_start, &params,
PACKET_remaining(&save_param_start) -
PACKET_remaining(pkt))) {
al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_KEY_EXCHANGE, ERR_R_INTERNAL_ERROR);
goto err;
}
if (SSL_USE_SIGALGS(s)) {
const unsigned char *sigalgs;
int rv;
if (!PACKET_get_bytes(pkt, &sigalgs, 2)) {
al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_KEY_EXCHANGE, SSL_R_LENGTH_TOO_SHORT);
goto err;
}
rv = tls12_check_peer_sigalg(&md, s, sigalgs, pkey);
if (rv == -1) {
al = SSL_AD_INTERNAL_ERROR;
goto err;
} else if (rv == 0) {
al = SSL_AD_DECODE_ERROR;
goto err;
}
#ifdef SSL_DEBUG
fprintf(stderr, "USING TLSv1.2 HASH %s\n", EVP_MD_name(md));
#endif
} else if (EVP_PKEY_id(pkey) == EVP_PKEY_RSA) {
md = EVP_md5_sha1();
} else {
md = EVP_sha1();
}
if (!PACKET_get_length_prefixed_2(pkt, &signature)
|| PACKET_remaining(pkt) != 0) {
al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_KEY_EXCHANGE, SSL_R_LENGTH_MISMATCH);
goto err;
}
maxsig = EVP_PKEY_size(pkey);
if (maxsig < 0) {
al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_KEY_EXCHANGE, ERR_R_INTERNAL_ERROR);
goto err;
}
if (PACKET_remaining(&signature) > (size_t)maxsig) {
al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_KEY_EXCHANGE,
SSL_R_WRONG_SIGNATURE_LENGTH);
goto err;
}
md_ctx = EVP_MD_CTX_new();
if (md_ctx == NULL) {
al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_KEY_EXCHANGE, ERR_R_MALLOC_FAILURE);
goto err;
}
if (EVP_VerifyInit_ex(md_ctx, md, NULL) <= 0
|| EVP_VerifyUpdate(md_ctx, &(s->s3->client_random[0]),
SSL3_RANDOM_SIZE) <= 0
|| EVP_VerifyUpdate(md_ctx, &(s->s3->server_random[0]),
SSL3_RANDOM_SIZE) <= 0
|| EVP_VerifyUpdate(md_ctx, PACKET_data(&params),
PACKET_remaining(&params)) <= 0) {
EVP_MD_CTX_free(md_ctx);
al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_KEY_EXCHANGE, ERR_R_EVP_LIB);
goto err;
}
if (EVP_VerifyFinal(md_ctx, PACKET_data(&signature),
PACKET_remaining(&signature), pkey) <= 0) {
EVP_MD_CTX_free(md_ctx);
al = SSL_AD_DECRYPT_ERROR;
SSLerr(SSL_F_TLS_PROCESS_KEY_EXCHANGE, SSL_R_BAD_SIGNATURE);
goto err;
}
EVP_MD_CTX_free(md_ctx);
} else {
if (!(s->s3->tmp.new_cipher->algorithm_auth & (SSL_aNULL | SSL_aSRP))
&& !(alg_k & SSL_PSK)) {
if (ssl3_check_cert_and_algorithm(s)) {
al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_KEY_EXCHANGE, ERR_R_INTERNAL_ERROR);
} else {
al = SSL_AD_DECODE_ERROR;
}
goto err;
}
if (PACKET_remaining(pkt) != 0) {
al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_KEY_EXCHANGE, SSL_R_EXTRA_DATA_IN_MESSAGE);
goto err;
}
}
return MSG_PROCESS_CONTINUE_READING;
err:
if (al != -1)
ssl3_send_alert(s, SSL3_AL_FATAL, al);
ossl_statem_set_error(s);
return MSG_PROCESS_ERROR;
}
MSG_PROCESS_RETURN tls_process_certificate_request(SSL *s, PACKET *pkt)
{
int ret = MSG_PROCESS_ERROR;
unsigned int list_len, ctype_num, i, name_len;
X509_NAME *xn = NULL;
const unsigned char *data;
const unsigned char *namestart, *namebytes;
STACK_OF(X509_NAME) *ca_sk = NULL;
if ((ca_sk = sk_X509_NAME_new(ca_dn_cmp)) == NULL) {
SSLerr(SSL_F_TLS_PROCESS_CERTIFICATE_REQUEST, ERR_R_MALLOC_FAILURE);
goto err;
}
if (!PACKET_get_1(pkt, &ctype_num)
|| !PACKET_get_bytes(pkt, &data, ctype_num)) {
ssl3_send_alert(s, SSL3_AL_FATAL, SSL_AD_DECODE_ERROR);
SSLerr(SSL_F_TLS_PROCESS_CERTIFICATE_REQUEST, SSL_R_LENGTH_MISMATCH);
goto err;
}
OPENSSL_free(s->cert->ctypes);
s->cert->ctypes = NULL;
if (ctype_num > SSL3_CT_NUMBER) {
s->cert->ctypes = OPENSSL_malloc(ctype_num);
if (s->cert->ctypes == NULL) {
SSLerr(SSL_F_TLS_PROCESS_CERTIFICATE_REQUEST, ERR_R_MALLOC_FAILURE);
goto err;
}
memcpy(s->cert->ctypes, data, ctype_num);
s->cert->ctype_num = (size_t)ctype_num;
ctype_num = SSL3_CT_NUMBER;
}
for (i = 0; i < ctype_num; i++)
s->s3->tmp.ctype[i] = data[i];
if (SSL_USE_SIGALGS(s)) {
if (!PACKET_get_net_2(pkt, &list_len)
|| !PACKET_get_bytes(pkt, &data, list_len)) {
ssl3_send_alert(s, SSL3_AL_FATAL, SSL_AD_DECODE_ERROR);
SSLerr(SSL_F_TLS_PROCESS_CERTIFICATE_REQUEST,
SSL_R_LENGTH_MISMATCH);
goto err;
}
for (i = 0; i < SSL_PKEY_NUM; i++) {
s->s3->tmp.md[i] = NULL;
s->s3->tmp.valid_flags[i] = 0;
}
if ((list_len & 1) || !tls1_save_sigalgs(s, data, list_len)) {
ssl3_send_alert(s, SSL3_AL_FATAL, SSL_AD_DECODE_ERROR);
SSLerr(SSL_F_TLS_PROCESS_CERTIFICATE_REQUEST,
SSL_R_SIGNATURE_ALGORITHMS_ERROR);
goto err;
}
if (!tls1_process_sigalgs(s)) {
ssl3_send_alert(s, SSL3_AL_FATAL, SSL_AD_INTERNAL_ERROR);
SSLerr(SSL_F_TLS_PROCESS_CERTIFICATE_REQUEST, ERR_R_MALLOC_FAILURE);
goto err;
}
} else {
ssl_set_default_md(s);
}
if (!PACKET_get_net_2(pkt, &list_len)
|| PACKET_remaining(pkt) != list_len) {
ssl3_send_alert(s, SSL3_AL_FATAL, SSL_AD_DECODE_ERROR);
SSLerr(SSL_F_TLS_PROCESS_CERTIFICATE_REQUEST, SSL_R_LENGTH_MISMATCH);
goto err;
}
while (PACKET_remaining(pkt)) {
if (!PACKET_get_net_2(pkt, &name_len)
|| !PACKET_get_bytes(pkt, &namebytes, name_len)) {
ssl3_send_alert(s, SSL3_AL_FATAL, SSL_AD_DECODE_ERROR);
SSLerr(SSL_F_TLS_PROCESS_CERTIFICATE_REQUEST,
SSL_R_LENGTH_MISMATCH);
goto err;
}
namestart = namebytes;
if ((xn = d2i_X509_NAME(NULL, (const unsigned char **)&namebytes,
name_len)) == NULL) {
ssl3_send_alert(s, SSL3_AL_FATAL, SSL_AD_DECODE_ERROR);
SSLerr(SSL_F_TLS_PROCESS_CERTIFICATE_REQUEST, ERR_R_ASN1_LIB);
goto err;
}
if (namebytes != (namestart + name_len)) {
ssl3_send_alert(s, SSL3_AL_FATAL, SSL_AD_DECODE_ERROR);
SSLerr(SSL_F_TLS_PROCESS_CERTIFICATE_REQUEST,
SSL_R_CA_DN_LENGTH_MISMATCH);
goto err;
}
if (!sk_X509_NAME_push(ca_sk, xn)) {
SSLerr(SSL_F_TLS_PROCESS_CERTIFICATE_REQUEST, ERR_R_MALLOC_FAILURE);
goto err;
}
xn = NULL;
}
s->s3->tmp.cert_req = 1;
s->s3->tmp.ctype_num = ctype_num;
sk_X509_NAME_pop_free(s->s3->tmp.ca_names, X509_NAME_free);
s->s3->tmp.ca_names = ca_sk;
ca_sk = NULL;
ret = MSG_PROCESS_CONTINUE_PROCESSING;
goto done;
err:
ossl_statem_set_error(s);
done:
X509_NAME_free(xn);
sk_X509_NAME_pop_free(ca_sk, X509_NAME_free);
return ret;
}
static int ca_dn_cmp(const X509_NAME *const *a, const X509_NAME *const *b)
{
return (X509_NAME_cmp(*a, *b));
}
MSG_PROCESS_RETURN tls_process_new_session_ticket(SSL *s, PACKET *pkt)
{
int al;
unsigned int ticklen;
unsigned long ticket_lifetime_hint;
if (!PACKET_get_net_4(pkt, &ticket_lifetime_hint)
|| !PACKET_get_net_2(pkt, &ticklen)
|| PACKET_remaining(pkt) != ticklen) {
al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_NEW_SESSION_TICKET, SSL_R_LENGTH_MISMATCH);
goto f_err;
}
if (ticklen == 0)
return MSG_PROCESS_CONTINUE_READING;
if (s->session->session_id_length > 0) {
int i = s->session_ctx->session_cache_mode;
SSL_SESSION *new_sess;
if (i & SSL_SESS_CACHE_CLIENT) {
SSL_CTX_remove_session(s->session_ctx, s->session);
}
if ((new_sess = ssl_session_dup(s->session, 0)) == 0) {
al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_NEW_SESSION_TICKET, ERR_R_MALLOC_FAILURE);
goto f_err;
}
SSL_SESSION_free(s->session);
s->session = new_sess;
}
OPENSSL_free(s->session->tlsext_tick);
s->session->tlsext_ticklen = 0;
s->session->tlsext_tick = OPENSSL_malloc(ticklen);
if (s->session->tlsext_tick == NULL) {
SSLerr(SSL_F_TLS_PROCESS_NEW_SESSION_TICKET, ERR_R_MALLOC_FAILURE);
goto err;
}
if (!PACKET_copy_bytes(pkt, s->session->tlsext_tick, ticklen)) {
al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_NEW_SESSION_TICKET, SSL_R_LENGTH_MISMATCH);
goto f_err;
}
s->session->tlsext_tick_lifetime_hint = ticket_lifetime_hint;
s->session->tlsext_ticklen = ticklen;
if (!EVP_Digest(s->session->tlsext_tick, ticklen,
s->session->session_id, &s->session->session_id_length,
EVP_sha256(), NULL)) {
SSLerr(SSL_F_TLS_PROCESS_NEW_SESSION_TICKET, ERR_R_EVP_LIB);
goto err;
}
return MSG_PROCESS_CONTINUE_READING;
f_err:
ssl3_send_alert(s, SSL3_AL_FATAL, al);
err:
ossl_statem_set_error(s);
return MSG_PROCESS_ERROR;
}
MSG_PROCESS_RETURN tls_process_cert_status(SSL *s, PACKET *pkt)
{
int al;
unsigned long resplen;
unsigned int type;
if (!PACKET_get_1(pkt, &type)
|| type != TLSEXT_STATUSTYPE_ocsp) {
al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CERT_STATUS, SSL_R_UNSUPPORTED_STATUS_TYPE);
goto f_err;
}
if (!PACKET_get_net_3(pkt, &resplen)
|| PACKET_remaining(pkt) != resplen) {
al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CERT_STATUS, SSL_R_LENGTH_MISMATCH);
goto f_err;
}
s->tlsext_ocsp_resp = OPENSSL_malloc(resplen);
if (s->tlsext_ocsp_resp == NULL) {
al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CERT_STATUS, ERR_R_MALLOC_FAILURE);
goto f_err;
}
if (!PACKET_copy_bytes(pkt, s->tlsext_ocsp_resp, resplen)) {
al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CERT_STATUS, SSL_R_LENGTH_MISMATCH);
goto f_err;
}
s->tlsext_ocsp_resplen = resplen;
return MSG_PROCESS_CONTINUE_READING;
f_err:
ssl3_send_alert(s, SSL3_AL_FATAL, al);
ossl_statem_set_error(s);
return MSG_PROCESS_ERROR;
}
MSG_PROCESS_RETURN tls_process_server_done(SSL *s, PACKET *pkt)
{
if (PACKET_remaining(pkt) > 0) {
ssl3_send_alert(s, SSL3_AL_FATAL, SSL_AD_DECODE_ERROR);
SSLerr(SSL_F_TLS_PROCESS_SERVER_DONE, SSL_R_LENGTH_MISMATCH);
ossl_statem_set_error(s);
return MSG_PROCESS_ERROR;
}
#ifndef OPENSSL_NO_SRP
if (s->s3->tmp.new_cipher->algorithm_mkey & SSL_kSRP) {
if (SRP_Calc_A_param(s) <= 0) {
SSLerr(SSL_F_TLS_PROCESS_SERVER_DONE, SSL_R_SRP_A_CALC);
ssl3_send_alert(s, SSL3_AL_FATAL, SSL_AD_INTERNAL_ERROR);
ossl_statem_set_error(s);
return MSG_PROCESS_ERROR;
}
}
#endif
if (!ssl3_check_cert_and_algorithm(s)) {
ssl3_send_alert(s, SSL3_AL_FATAL, SSL_AD_HANDSHAKE_FAILURE);
ossl_statem_set_error(s);
return MSG_PROCESS_ERROR;
}
if (s->tlsext_status_type != -1 && s->ctx->tlsext_status_cb != NULL) {
int ret;
ret = s->ctx->tlsext_status_cb(s, s->ctx->tlsext_status_arg);
if (ret == 0) {
ssl3_send_alert(s, SSL3_AL_FATAL,
SSL_AD_BAD_CERTIFICATE_STATUS_RESPONSE);
SSLerr(SSL_F_TLS_PROCESS_SERVER_DONE,
SSL_R_INVALID_STATUS_RESPONSE);
return MSG_PROCESS_ERROR;
}
if (ret < 0) {
ssl3_send_alert(s, SSL3_AL_FATAL, SSL_AD_INTERNAL_ERROR);
SSLerr(SSL_F_TLS_PROCESS_SERVER_DONE, ERR_R_MALLOC_FAILURE);
return MSG_PROCESS_ERROR;
}
}
#ifndef OPENSSL_NO_CT
if (s->ct_validation_callback != NULL) {
if (!ssl_validate_ct(s) && (s->verify_mode & SSL_VERIFY_PEER)) {
ssl3_send_alert(s, SSL3_AL_FATAL, SSL_AD_HANDSHAKE_FAILURE);
return MSG_PROCESS_ERROR;
}
}
#endif
#ifndef OPENSSL_NO_SCTP
if (SSL_IS_DTLS(s) && BIO_dgram_is_sctp(SSL_get_wbio(s))
&& s->renegotiate != 0)
return MSG_PROCESS_CONTINUE_PROCESSING;
else
#endif
return MSG_PROCESS_FINISHED_READING;
}
static int tls_construct_cke_psk_preamble(SSL *s, unsigned char **p,
size_t *pskhdrlen, int *al)
{
#ifndef OPENSSL_NO_PSK
int ret = 0;
char identity[PSK_MAX_IDENTITY_LEN + 1];
size_t identitylen = 0;
unsigned char psk[PSK_MAX_PSK_LEN];
unsigned char *tmppsk = NULL;
char *tmpidentity = NULL;
size_t psklen = 0;
if (s->psk_client_callback == NULL) {
SSLerr(SSL_F_TLS_CONSTRUCT_CKE_PSK_PREAMBLE, SSL_R_PSK_NO_CLIENT_CB);
*al = SSL_AD_INTERNAL_ERROR;
goto err;
}
memset(identity, 0, sizeof(identity));
psklen = s->psk_client_callback(s, s->session->psk_identity_hint,
identity, sizeof(identity) - 1,
psk, sizeof(psk));
if (psklen > PSK_MAX_PSK_LEN) {
SSLerr(SSL_F_TLS_CONSTRUCT_CKE_PSK_PREAMBLE, ERR_R_INTERNAL_ERROR);
*al = SSL_AD_HANDSHAKE_FAILURE;
goto err;
} else if (psklen == 0) {
SSLerr(SSL_F_TLS_CONSTRUCT_CKE_PSK_PREAMBLE,
SSL_R_PSK_IDENTITY_NOT_FOUND);
*al = SSL_AD_HANDSHAKE_FAILURE;
goto err;
}
identitylen = strlen(identity);
if (identitylen > PSK_MAX_IDENTITY_LEN) {
SSLerr(SSL_F_TLS_CONSTRUCT_CKE_PSK_PREAMBLE, ERR_R_INTERNAL_ERROR);
*al = SSL_AD_HANDSHAKE_FAILURE;
goto err;
}
tmppsk = OPENSSL_memdup(psk, psklen);
tmpidentity = OPENSSL_strdup(identity);
if (tmppsk == NULL || tmpidentity == NULL) {
SSLerr(SSL_F_TLS_CONSTRUCT_CKE_PSK_PREAMBLE, ERR_R_MALLOC_FAILURE);
*al = SSL_AD_INTERNAL_ERROR;
goto err;
}
OPENSSL_free(s->s3->tmp.psk);
s->s3->tmp.psk = tmppsk;
s->s3->tmp.psklen = psklen;
tmppsk = NULL;
OPENSSL_free(s->session->psk_identity);
s->session->psk_identity = tmpidentity;
tmpidentity = NULL;
s2n(identitylen, *p);
memcpy(*p, identity, identitylen);
*pskhdrlen = 2 + identitylen;
*p += identitylen;
ret = 1;
err:
OPENSSL_cleanse(psk, psklen);
OPENSSL_cleanse(identity, sizeof(identity));
OPENSSL_clear_free(tmppsk, psklen);
OPENSSL_clear_free(tmpidentity, identitylen);
return ret;
#else
SSLerr(SSL_F_TLS_CONSTRUCT_CKE_PSK_PREAMBLE, ERR_R_INTERNAL_ERROR);
*al = SSL_AD_INTERNAL_ERROR;
return 0;
#endif
}
static int tls_construct_cke_rsa(SSL *s, unsigned char **p, int *len, int *al)
{
#ifndef OPENSSL_NO_RSA
unsigned char *q;
EVP_PKEY *pkey = NULL;
EVP_PKEY_CTX *pctx = NULL;
size_t enclen;
unsigned char *pms = NULL;
size_t pmslen = 0;
if (s->session->peer == NULL) {
SSLerr(SSL_F_TLS_CONSTRUCT_CKE_RSA, ERR_R_INTERNAL_ERROR);
return 0;
}
pkey = X509_get0_pubkey(s->session->peer);
if (EVP_PKEY_get0_RSA(pkey) == NULL) {
SSLerr(SSL_F_TLS_CONSTRUCT_CKE_RSA, ERR_R_INTERNAL_ERROR);
return 0;
}
pmslen = SSL_MAX_MASTER_KEY_LENGTH;
pms = OPENSSL_malloc(pmslen);
if (pms == NULL) {
SSLerr(SSL_F_TLS_CONSTRUCT_CKE_RSA, ERR_R_MALLOC_FAILURE);
*al = SSL_AD_INTERNAL_ERROR;
return 0;
}
pms[0] = s->client_version >> 8;
pms[1] = s->client_version & 0xff;
if (RAND_bytes(pms + 2, pmslen - 2) <= 0) {
goto err;
}
q = *p;
if (s->version > SSL3_VERSION)
*p += 2;
pctx = EVP_PKEY_CTX_new(pkey, NULL);
if (pctx == NULL || EVP_PKEY_encrypt_init(pctx) <= 0
|| EVP_PKEY_encrypt(pctx, NULL, &enclen, pms, pmslen) <= 0) {
SSLerr(SSL_F_TLS_CONSTRUCT_CKE_RSA, ERR_R_EVP_LIB);
goto err;
}
if (EVP_PKEY_encrypt(pctx, *p, &enclen, pms, pmslen) <= 0) {
SSLerr(SSL_F_TLS_CONSTRUCT_CKE_RSA, SSL_R_BAD_RSA_ENCRYPT);
goto err;
}
*len = enclen;
EVP_PKEY_CTX_free(pctx);
pctx = NULL;
# ifdef PKCS1_CHECK
if (s->options & SSL_OP_PKCS1_CHECK_1)
(*p)[1]++;
if (s->options & SSL_OP_PKCS1_CHECK_2)
tmp_buf[0] = 0x70;
# endif
if (s->version > SSL3_VERSION) {
s2n(*len, q);
*len += 2;
}
s->s3->tmp.pms = pms;
s->s3->tmp.pmslen = pmslen;
return 1;
err:
OPENSSL_clear_free(pms, pmslen);
EVP_PKEY_CTX_free(pctx);
return 0;
#else
SSLerr(SSL_F_TLS_CONSTRUCT_CKE_RSA, ERR_R_INTERNAL_ERROR);
*al = SSL_AD_INTERNAL_ERROR;
return 0;
#endif
}
static int tls_construct_cke_dhe(SSL *s, unsigned char **p, int *len, int *al)
{
#ifndef OPENSSL_NO_DH
DH *dh_clnt = NULL;
const BIGNUM *pub_key;
EVP_PKEY *ckey = NULL, *skey = NULL;
skey = s->s3->peer_tmp;
if (skey == NULL) {
SSLerr(SSL_F_TLS_CONSTRUCT_CKE_DHE, ERR_R_INTERNAL_ERROR);
return 0;
}
ckey = ssl_generate_pkey(skey);
dh_clnt = EVP_PKEY_get0_DH(ckey);
if (dh_clnt == NULL || ssl_derive(s, ckey, skey) == 0) {
SSLerr(SSL_F_TLS_CONSTRUCT_CKE_DHE, ERR_R_INTERNAL_ERROR);
EVP_PKEY_free(ckey);
return 0;
}
DH_get0_key(dh_clnt, &pub_key, NULL);
*len = BN_num_bytes(pub_key);
s2n(*len, *p);
BN_bn2bin(pub_key, *p);
*len += 2;
EVP_PKEY_free(ckey);
return 1;
#else
SSLerr(SSL_F_TLS_CONSTRUCT_CKE_DHE, ERR_R_INTERNAL_ERROR);
*al = SSL_AD_INTERNAL_ERROR;
return 0;
#endif
}
static int tls_construct_cke_ecdhe(SSL *s, unsigned char **p, int *len, int *al)
{
#ifndef OPENSSL_NO_EC
unsigned char *encodedPoint = NULL;
int encoded_pt_len = 0;
EVP_PKEY *ckey = NULL, *skey = NULL;
skey = s->s3->peer_tmp;
if (skey == NULL) {
SSLerr(SSL_F_TLS_CONSTRUCT_CKE_ECDHE, ERR_R_INTERNAL_ERROR);
return 0;
}
ckey = ssl_generate_pkey(skey);
if (ssl_derive(s, ckey, skey) == 0) {
SSLerr(SSL_F_TLS_CONSTRUCT_CKE_ECDHE, ERR_R_EVP_LIB);
goto err;
}
encoded_pt_len = EVP_PKEY_get1_tls_encodedpoint(ckey, &encodedPoint);
if (encoded_pt_len == 0) {
SSLerr(SSL_F_TLS_CONSTRUCT_CKE_ECDHE, ERR_R_EC_LIB);
goto err;
}
EVP_PKEY_free(ckey);
ckey = NULL;
*len = encoded_pt_len;
**p = *len;
*p += 1;
memcpy(*p, encodedPoint, *len);
*len += 1;
OPENSSL_free(encodedPoint);
return 1;
err:
EVP_PKEY_free(ckey);
return 0;
#else
SSLerr(SSL_F_TLS_CONSTRUCT_CKE_ECDHE, ERR_R_INTERNAL_ERROR);
*al = SSL_AD_INTERNAL_ERROR;
return 0;
#endif
}
static int tls_construct_cke_gost(SSL *s, unsigned char **p, int *len, int *al)
{
#ifndef OPENSSL_NO_GOST
EVP_PKEY_CTX *pkey_ctx = NULL;
X509 *peer_cert;
size_t msglen;
unsigned int md_len;
unsigned char shared_ukm[32], tmp[256];
EVP_MD_CTX *ukm_hash = NULL;
int dgst_nid = NID_id_GostR3411_94;
unsigned char *pms = NULL;
size_t pmslen = 0;
if ((s->s3->tmp.new_cipher->algorithm_auth & SSL_aGOST12) != 0)
dgst_nid = NID_id_GostR3411_2012_256;
peer_cert = s->session->peer;
if (!peer_cert) {
*al = SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_TLS_CONSTRUCT_CKE_GOST,
SSL_R_NO_GOST_CERTIFICATE_SENT_BY_PEER);
return 0;
}
pkey_ctx = EVP_PKEY_CTX_new(X509_get0_pubkey(peer_cert), NULL);
if (pkey_ctx == NULL) {
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_CONSTRUCT_CKE_GOST, ERR_R_MALLOC_FAILURE);
return 0;
}
pmslen = 32;
pms = OPENSSL_malloc(pmslen);
if (pms == NULL) {
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_CONSTRUCT_CKE_GOST, ERR_R_MALLOC_FAILURE);
goto err;
}
if (EVP_PKEY_encrypt_init(pkey_ctx) <= 0
|| RAND_bytes(pms, pmslen) <= 0) {
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_CONSTRUCT_CKE_GOST, ERR_R_INTERNAL_ERROR);
goto err;
};
if (s->s3->tmp.cert_req && s->cert->key->privatekey) {
if (EVP_PKEY_derive_set_peer(pkey_ctx, s->cert->key->privatekey) <= 0) {
ERR_clear_error();
}
}
ukm_hash = EVP_MD_CTX_new();
if (ukm_hash == NULL
|| EVP_DigestInit(ukm_hash, EVP_get_digestbynid(dgst_nid)) <= 0
|| EVP_DigestUpdate(ukm_hash, s->s3->client_random,
SSL3_RANDOM_SIZE) <= 0
|| EVP_DigestUpdate(ukm_hash, s->s3->server_random,
SSL3_RANDOM_SIZE) <= 0
|| EVP_DigestFinal_ex(ukm_hash, shared_ukm, &md_len) <= 0) {
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_CONSTRUCT_CKE_GOST, ERR_R_INTERNAL_ERROR);
goto err;
}
EVP_MD_CTX_free(ukm_hash);
ukm_hash = NULL;
if (EVP_PKEY_CTX_ctrl(pkey_ctx, -1, EVP_PKEY_OP_ENCRYPT,
EVP_PKEY_CTRL_SET_IV, 8, shared_ukm) < 0) {
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_CONSTRUCT_CKE_GOST, SSL_R_LIBRARY_BUG);
goto err;
}
*((*p)++) = V_ASN1_SEQUENCE | V_ASN1_CONSTRUCTED;
msglen = 255;
if (EVP_PKEY_encrypt(pkey_ctx, tmp, &msglen, pms, pmslen) <= 0) {
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_CONSTRUCT_CKE_GOST, SSL_R_LIBRARY_BUG);
goto err;
}
if (msglen >= 0x80) {
*((*p)++) = 0x81;
*((*p)++) = msglen & 0xff;
*len = msglen + 3;
} else {
*((*p)++) = msglen & 0xff;
*len = msglen + 2;
}
memcpy(*p, tmp, msglen);
if (EVP_PKEY_CTX_ctrl(pkey_ctx, -1, -1, EVP_PKEY_CTRL_PEER_KEY, 2,
NULL) > 0) {
s->s3->flags |= TLS1_FLAGS_SKIP_CERT_VERIFY;
}
EVP_PKEY_CTX_free(pkey_ctx);
s->s3->tmp.pms = pms;
s->s3->tmp.pmslen = pmslen;
return 1;
err:
EVP_PKEY_CTX_free(pkey_ctx);
OPENSSL_clear_free(pms, pmslen);
EVP_MD_CTX_free(ukm_hash);
return 0;
#else
SSLerr(SSL_F_TLS_CONSTRUCT_CKE_GOST, ERR_R_INTERNAL_ERROR);
*al = SSL_AD_INTERNAL_ERROR;
return 0;
#endif
}
static int tls_construct_cke_srp(SSL *s, unsigned char **p, int *len, int *al)
{
#ifndef OPENSSL_NO_SRP
if (s->srp_ctx.A != NULL) {
*len = BN_num_bytes(s->srp_ctx.A);
s2n(*len, *p);
BN_bn2bin(s->srp_ctx.A, *p);
*len += 2;
} else {
SSLerr(SSL_F_TLS_CONSTRUCT_CKE_SRP, ERR_R_INTERNAL_ERROR);
return 0;
}
OPENSSL_free(s->session->srp_username);
s->session->srp_username = OPENSSL_strdup(s->srp_ctx.login);
if (s->session->srp_username == NULL) {
SSLerr(SSL_F_TLS_CONSTRUCT_CKE_SRP, ERR_R_MALLOC_FAILURE);
return 0;
}
return 1;
#else
SSLerr(SSL_F_TLS_CONSTRUCT_CKE_SRP, ERR_R_INTERNAL_ERROR);
*al = SSL_AD_INTERNAL_ERROR;
return 0;
#endif
}
int tls_construct_client_key_exchange(SSL *s)
{
unsigned char *p;
int len;
size_t pskhdrlen = 0;
unsigned long alg_k;
int al = -1;
alg_k = s->s3->tmp.new_cipher->algorithm_mkey;
p = ssl_handshake_start(s);
if ((alg_k & SSL_PSK)
&& !tls_construct_cke_psk_preamble(s, &p, &pskhdrlen, &al))
goto err;
if (alg_k & SSL_kPSK) {
len = 0;
} else if (alg_k & (SSL_kRSA | SSL_kRSAPSK)) {
if (!tls_construct_cke_rsa(s, &p, &len, &al))
goto err;
} else if (alg_k & (SSL_kDHE | SSL_kDHEPSK)) {
if (!tls_construct_cke_dhe(s, &p, &len, &al))
goto err;
} else if (alg_k & (SSL_kECDHE | SSL_kECDHEPSK)) {
if (!tls_construct_cke_ecdhe(s, &p, &len, &al))
goto err;
} else if (alg_k & SSL_kGOST) {
if (!tls_construct_cke_gost(s, &p, &len, &al))
goto err;
} else if (alg_k & SSL_kSRP) {
if (!tls_construct_cke_srp(s, &p, &len, &al))
goto err;
} else {
ssl3_send_alert(s, SSL3_AL_FATAL, SSL_AD_HANDSHAKE_FAILURE);
SSLerr(SSL_F_TLS_CONSTRUCT_CLIENT_KEY_EXCHANGE, ERR_R_INTERNAL_ERROR);
goto err;
}
len += pskhdrlen;
if (!ssl_set_handshake_header(s, SSL3_MT_CLIENT_KEY_EXCHANGE, len)) {
ssl3_send_alert(s, SSL3_AL_FATAL, SSL_AD_HANDSHAKE_FAILURE);
SSLerr(SSL_F_TLS_CONSTRUCT_CLIENT_KEY_EXCHANGE, ERR_R_INTERNAL_ERROR);
goto err;
}
return 1;
err:
if (al != -1)
ssl3_send_alert(s, SSL3_AL_FATAL, al);
OPENSSL_clear_free(s->s3->tmp.pms, s->s3->tmp.pmslen);
s->s3->tmp.pms = NULL;
#ifndef OPENSSL_NO_PSK
OPENSSL_clear_free(s->s3->tmp.psk, s->s3->tmp.psklen);
s->s3->tmp.psk = NULL;
#endif
ossl_statem_set_error(s);
return 0;
}
int tls_client_key_exchange_post_work(SSL *s)
{
unsigned char *pms = NULL;
size_t pmslen = 0;
pms = s->s3->tmp.pms;
pmslen = s->s3->tmp.pmslen;
#ifndef OPENSSL_NO_SRP
if (s->s3->tmp.new_cipher->algorithm_mkey & SSL_kSRP) {
if (!srp_generate_client_master_secret(s)) {
SSLerr(SSL_F_TLS_CLIENT_KEY_EXCHANGE_POST_WORK,
ERR_R_INTERNAL_ERROR);
goto err;
}
return 1;
}
#endif
if (pms == NULL && !(s->s3->tmp.new_cipher->algorithm_mkey & SSL_kPSK)) {
ssl3_send_alert(s, SSL3_AL_FATAL, SSL_AD_INTERNAL_ERROR);
SSLerr(SSL_F_TLS_CLIENT_KEY_EXCHANGE_POST_WORK, ERR_R_MALLOC_FAILURE);
goto err;
}
if (!ssl_generate_master_secret(s, pms, pmslen, 1)) {
ssl3_send_alert(s, SSL3_AL_FATAL, SSL_AD_INTERNAL_ERROR);
SSLerr(SSL_F_TLS_CLIENT_KEY_EXCHANGE_POST_WORK, ERR_R_INTERNAL_ERROR);
pms = NULL;
pmslen = 0;
goto err;
}
pms = NULL;
pmslen = 0;
#ifndef OPENSSL_NO_SCTP
if (SSL_IS_DTLS(s)) {
unsigned char sctpauthkey[64];
char labelbuffer[sizeof(DTLS1_SCTP_AUTH_LABEL)];
memcpy(labelbuffer, DTLS1_SCTP_AUTH_LABEL,
sizeof(DTLS1_SCTP_AUTH_LABEL));
if (SSL_export_keying_material(s, sctpauthkey,
sizeof(sctpauthkey), labelbuffer,
sizeof(labelbuffer), NULL, 0, 0) <= 0)
goto err;
BIO_ctrl(SSL_get_wbio(s), BIO_CTRL_DGRAM_SCTP_ADD_AUTH_KEY,
sizeof(sctpauthkey), sctpauthkey);
}
#endif
return 1;
err:
OPENSSL_clear_free(pms, pmslen);
s->s3->tmp.pms = NULL;
return 0;
}
int tls_construct_client_verify(SSL *s)
{
unsigned char *p;
EVP_PKEY *pkey;
const EVP_MD *md = s->s3->tmp.md[s->cert->key - s->cert->pkeys];
EVP_MD_CTX *mctx;
unsigned u = 0;
unsigned long n = 0;
long hdatalen = 0;
void *hdata;
mctx = EVP_MD_CTX_new();
if (mctx == NULL) {
SSLerr(SSL_F_TLS_CONSTRUCT_CLIENT_VERIFY, ERR_R_MALLOC_FAILURE);
goto err;
}
p = ssl_handshake_start(s);
pkey = s->cert->key->privatekey;
hdatalen = BIO_get_mem_data(s->s3->handshake_buffer, &hdata);
if (hdatalen <= 0) {
SSLerr(SSL_F_TLS_CONSTRUCT_CLIENT_VERIFY, ERR_R_INTERNAL_ERROR);
goto err;
}
if (SSL_USE_SIGALGS(s)) {
if (!tls12_get_sigandhash(p, pkey, md)) {
SSLerr(SSL_F_TLS_CONSTRUCT_CLIENT_VERIFY, ERR_R_INTERNAL_ERROR);
goto err;
}
p += 2;
n = 2;
}
#ifdef SSL_DEBUG
fprintf(stderr, "Using client alg %s\n", EVP_MD_name(md));
#endif
if (!EVP_SignInit_ex(mctx, md, NULL)
|| !EVP_SignUpdate(mctx, hdata, hdatalen)
|| (s->version == SSL3_VERSION
&& !EVP_MD_CTX_ctrl(mctx, EVP_CTRL_SSL3_MASTER_SECRET,
s->session->master_key_length,
s->session->master_key))
|| !EVP_SignFinal(mctx, p + 2, &u, pkey)) {
SSLerr(SSL_F_TLS_CONSTRUCT_CLIENT_VERIFY, ERR_R_EVP_LIB);
goto err;
}
#ifndef OPENSSL_NO_GOST
{
int pktype = EVP_PKEY_id(pkey);
if (pktype == NID_id_GostR3410_2001
|| pktype == NID_id_GostR3410_2012_256
|| pktype == NID_id_GostR3410_2012_512)
BUF_reverse(p + 2, NULL, u);
}
#endif
s2n(u, p);
n += u + 2;
if (!ssl3_digest_cached_records(s, 0))
goto err;
if (!ssl_set_handshake_header(s, SSL3_MT_CERTIFICATE_VERIFY, n)) {
SSLerr(SSL_F_TLS_CONSTRUCT_CLIENT_VERIFY, ERR_R_INTERNAL_ERROR);
goto err;
}
EVP_MD_CTX_free(mctx);
return 1;
err:
EVP_MD_CTX_free(mctx);
return 0;
}
static int ssl3_check_client_certificate(SSL *s)
{
if (!s->cert || !s->cert->key->x509 || !s->cert->key->privatekey)
return 0;
if (SSL_USE_SIGALGS(s) && !s->s3->tmp.md[s->cert->key - s->cert->pkeys])
return 0;
if (s->cert->cert_flags & SSL_CERT_FLAGS_CHECK_TLS_STRICT &&
!tls1_check_chain(s, NULL, NULL, NULL, -2))
return 0;
return 1;
}
WORK_STATE tls_prepare_client_certificate(SSL *s, WORK_STATE wst)
{
X509 *x509 = NULL;
EVP_PKEY *pkey = NULL;
int i;
if (wst == WORK_MORE_A) {
if (s->cert->cert_cb) {
i = s->cert->cert_cb(s, s->cert->cert_cb_arg);
if (i < 0) {
s->rwstate = SSL_X509_LOOKUP;
return WORK_MORE_A;
}
if (i == 0) {
ssl3_send_alert(s, SSL3_AL_FATAL, SSL_AD_INTERNAL_ERROR);
ossl_statem_set_error(s);
return 0;
}
s->rwstate = SSL_NOTHING;
}
if (ssl3_check_client_certificate(s))
return WORK_FINISHED_CONTINUE;
wst = WORK_MORE_B;
}
if (wst == WORK_MORE_B) {
i = ssl_do_client_cert_cb(s, &x509, &pkey);
if (i < 0) {
s->rwstate = SSL_X509_LOOKUP;
return WORK_MORE_B;
}
s->rwstate = SSL_NOTHING;
if ((i == 1) && (pkey != NULL) && (x509 != NULL)) {
if (!SSL_use_certificate(s, x509) || !SSL_use_PrivateKey(s, pkey))
i = 0;
} else if (i == 1) {
i = 0;
SSLerr(SSL_F_TLS_PREPARE_CLIENT_CERTIFICATE,
SSL_R_BAD_DATA_RETURNED_BY_CALLBACK);
}
X509_free(x509);
EVP_PKEY_free(pkey);
if (i && !ssl3_check_client_certificate(s))
i = 0;
if (i == 0) {
if (s->version == SSL3_VERSION) {
s->s3->tmp.cert_req = 0;
ssl3_send_alert(s, SSL3_AL_WARNING, SSL_AD_NO_CERTIFICATE);
return WORK_FINISHED_CONTINUE;
} else {
s->s3->tmp.cert_req = 2;
if (!ssl3_digest_cached_records(s, 0)) {
ssl3_send_alert(s, SSL3_AL_FATAL, SSL_AD_INTERNAL_ERROR);
ossl_statem_set_error(s);
return 0;
}
}
}
return WORK_FINISHED_CONTINUE;
}
return WORK_ERROR;
}
int tls_construct_client_certificate(SSL *s)
{
if (!ssl3_output_cert_chain(s,
(s->s3->tmp.cert_req ==
2) ? NULL : s->cert->key)) {
SSLerr(SSL_F_TLS_CONSTRUCT_CLIENT_CERTIFICATE, ERR_R_INTERNAL_ERROR);
ssl3_send_alert(s, SSL3_AL_FATAL, SSL_AD_INTERNAL_ERROR);
ossl_statem_set_error(s);
return 0;
}
return 1;
}
int ssl3_check_cert_and_algorithm(SSL *s)
{
int i;
#ifndef OPENSSL_NO_EC
int idx;
#endif
long alg_k, alg_a;
EVP_PKEY *pkey = NULL;
int al = SSL_AD_HANDSHAKE_FAILURE;
alg_k = s->s3->tmp.new_cipher->algorithm_mkey;
alg_a = s->s3->tmp.new_cipher->algorithm_auth;
if ((alg_a & SSL_aNULL) || (alg_k & SSL_kPSK))
return (1);
#ifndef OPENSSL_NO_EC
idx = s->session->peer_type;
if (idx == SSL_PKEY_ECC) {
if (ssl_check_srvr_ecc_cert_and_alg(s->session->peer, s) == 0) {
SSLerr(SSL_F_SSL3_CHECK_CERT_AND_ALGORITHM, SSL_R_BAD_ECC_CERT);
goto f_err;
} else {
return 1;
}
} else if (alg_a & SSL_aECDSA) {
SSLerr(SSL_F_SSL3_CHECK_CERT_AND_ALGORITHM,
SSL_R_MISSING_ECDSA_SIGNING_CERT);
goto f_err;
}
#endif
pkey = X509_get0_pubkey(s->session->peer);
i = X509_certificate_type(s->session->peer, pkey);
if ((alg_a & SSL_aRSA) && !has_bits(i, EVP_PK_RSA | EVP_PKT_SIGN)) {
SSLerr(SSL_F_SSL3_CHECK_CERT_AND_ALGORITHM,
SSL_R_MISSING_RSA_SIGNING_CERT);
goto f_err;
}
#ifndef OPENSSL_NO_DSA
else if ((alg_a & SSL_aDSS) && !has_bits(i, EVP_PK_DSA | EVP_PKT_SIGN)) {
SSLerr(SSL_F_SSL3_CHECK_CERT_AND_ALGORITHM,
SSL_R_MISSING_DSA_SIGNING_CERT);
goto f_err;
}
#endif
#ifndef OPENSSL_NO_RSA
if (alg_k & (SSL_kRSA | SSL_kRSAPSK) &&
!has_bits(i, EVP_PK_RSA | EVP_PKT_ENC)) {
SSLerr(SSL_F_SSL3_CHECK_CERT_AND_ALGORITHM,
SSL_R_MISSING_RSA_ENCRYPTING_CERT);
goto f_err;
}
#endif
#ifndef OPENSSL_NO_DH
if ((alg_k & SSL_kDHE) && (s->s3->peer_tmp == NULL)) {
al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_SSL3_CHECK_CERT_AND_ALGORITHM, ERR_R_INTERNAL_ERROR);
goto f_err;
}
#endif
return (1);
f_err:
ssl3_send_alert(s, SSL3_AL_FATAL, al);
return (0);
}
int tls_construct_next_proto(SSL *s)
{
unsigned int len, padding_len;
unsigned char *d;
len = s->next_proto_negotiated_len;
padding_len = 32 - ((len + 2) % 32);
d = (unsigned char *)s->init_buf->data;
d[4] = len;
memcpy(d + 5, s->next_proto_negotiated, len);
d[5 + len] = padding_len;
memset(d + 6 + len, 0, padding_len);
*(d++) = SSL3_MT_NEXT_PROTO;
l2n3(2 + len + padding_len, d);
s->init_num = 4 + 2 + len + padding_len;
s->init_off = 0;
return 1;
}
int ssl_do_client_cert_cb(SSL *s, X509 **px509, EVP_PKEY **ppkey)
{
int i = 0;
#ifndef OPENSSL_NO_ENGINE
if (s->ctx->client_cert_engine) {
i = ENGINE_load_ssl_client_cert(s->ctx->client_cert_engine, s,
SSL_get_client_CA_list(s),
px509, ppkey, NULL, NULL, NULL);
if (i != 0)
return i;
}
#endif
if (s->ctx->client_cert_cb)
i = s->ctx->client_cert_cb(s, px509, ppkey);
return i;
}
