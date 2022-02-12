int ossl_statem_server_read_transition(SSL *s, int mt)
{
OSSL_STATEM *st = &s->statem;
switch (st->hand_state) {
case TLS_ST_BEFORE:
case DTLS_ST_SW_HELLO_VERIFY_REQUEST:
if (mt == SSL3_MT_CLIENT_HELLO) {
st->hand_state = TLS_ST_SR_CLNT_HELLO;
return 1;
}
break;
case TLS_ST_SW_SRVR_DONE:
if (mt == SSL3_MT_CLIENT_KEY_EXCHANGE) {
if (s->s3->tmp.cert_request) {
if (s->version == SSL3_VERSION) {
if ((s->verify_mode & SSL_VERIFY_PEER)
&& (s->verify_mode & SSL_VERIFY_FAIL_IF_NO_PEER_CERT)) {
ssl3_send_alert(s, SSL3_AL_FATAL,
SSL3_AD_HANDSHAKE_FAILURE);
SSLerr(SSL_F_OSSL_STATEM_SERVER_READ_TRANSITION,
SSL_R_PEER_DID_NOT_RETURN_A_CERTIFICATE);
return 0;
}
st->hand_state = TLS_ST_SR_KEY_EXCH;
return 1;
}
} else {
st->hand_state = TLS_ST_SR_KEY_EXCH;
return 1;
}
} else if (s->s3->tmp.cert_request) {
if (mt == SSL3_MT_CERTIFICATE) {
st->hand_state = TLS_ST_SR_CERT;
return 1;
}
}
break;
case TLS_ST_SR_CERT:
if (mt == SSL3_MT_CLIENT_KEY_EXCHANGE) {
st->hand_state = TLS_ST_SR_KEY_EXCH;
return 1;
}
break;
case TLS_ST_SR_KEY_EXCH:
if (s->session->peer == NULL || st->no_cert_verify) {
if (mt == SSL3_MT_CHANGE_CIPHER_SPEC) {
st->hand_state = TLS_ST_SR_CHANGE;
return 1;
}
} else {
if (mt == SSL3_MT_CERTIFICATE_VERIFY) {
st->hand_state = TLS_ST_SR_CERT_VRFY;
return 1;
}
}
break;
case TLS_ST_SR_CERT_VRFY:
if (mt == SSL3_MT_CHANGE_CIPHER_SPEC) {
st->hand_state = TLS_ST_SR_CHANGE;
return 1;
}
break;
case TLS_ST_SR_CHANGE:
#ifndef OPENSSL_NO_NEXTPROTONEG
if (s->s3->next_proto_neg_seen) {
if (mt == SSL3_MT_NEXT_PROTO) {
st->hand_state = TLS_ST_SR_NEXT_PROTO;
return 1;
}
} else {
#endif
if (mt == SSL3_MT_FINISHED) {
st->hand_state = TLS_ST_SR_FINISHED;
return 1;
}
#ifndef OPENSSL_NO_NEXTPROTONEG
}
#endif
break;
#ifndef OPENSSL_NO_NEXTPROTONEG
case TLS_ST_SR_NEXT_PROTO:
if (mt == SSL3_MT_FINISHED) {
st->hand_state = TLS_ST_SR_FINISHED;
return 1;
}
break;
#endif
case TLS_ST_SW_FINISHED:
if (mt == SSL3_MT_CHANGE_CIPHER_SPEC) {
st->hand_state = TLS_ST_SR_CHANGE;
return 1;
}
break;
default:
break;
}
ssl3_send_alert(s, SSL3_AL_FATAL, SSL3_AD_UNEXPECTED_MESSAGE);
SSLerr(SSL_F_OSSL_STATEM_SERVER_READ_TRANSITION, SSL_R_UNEXPECTED_MESSAGE);
return 0;
}
static int send_server_key_exchange(SSL *s)
{
unsigned long alg_k = s->s3->tmp.new_cipher->algorithm_mkey;
if (alg_k & (SSL_kDHE | SSL_kECDHE)
#ifndef OPENSSL_NO_PSK
|| ((alg_k & (SSL_kPSK | SSL_kRSAPSK))
&& s->cert->psk_identity_hint)
|| (alg_k & (SSL_PSK & (SSL_kDHEPSK | SSL_kECDHEPSK)))
#endif
#ifndef OPENSSL_NO_SRP
|| (alg_k & SSL_kSRP)
#endif
) {
return 1;
}
return 0;
}
static int send_certificate_request(SSL *s)
{
if (
s->verify_mode & SSL_VERIFY_PEER
&& ((s->session->peer == NULL) ||
!(s->verify_mode & SSL_VERIFY_CLIENT_ONCE))
&& (!(s->s3->tmp.new_cipher->algorithm_auth & SSL_aNULL)
|| (s->verify_mode & SSL_VERIFY_FAIL_IF_NO_PEER_CERT))
&& !(s->s3->tmp.new_cipher->algorithm_auth & SSL_aSRP)
&& !(s->s3->tmp.new_cipher->algorithm_auth & SSL_aPSK)) {
return 1;
}
return 0;
}
WRITE_TRAN ossl_statem_server_write_transition(SSL *s)
{
OSSL_STATEM *st = &s->statem;
switch (st->hand_state) {
case TLS_ST_BEFORE:
return WRITE_TRAN_FINISHED;
case TLS_ST_OK:
st->hand_state = TLS_ST_SW_HELLO_REQ;
return WRITE_TRAN_CONTINUE;
case TLS_ST_SW_HELLO_REQ:
st->hand_state = TLS_ST_OK;
ossl_statem_set_in_init(s, 0);
return WRITE_TRAN_CONTINUE;
case TLS_ST_SR_CLNT_HELLO:
if (SSL_IS_DTLS(s) && !s->d1->cookie_verified
&& (SSL_get_options(s) & SSL_OP_COOKIE_EXCHANGE))
st->hand_state = DTLS_ST_SW_HELLO_VERIFY_REQUEST;
else
st->hand_state = TLS_ST_SW_SRVR_HELLO;
return WRITE_TRAN_CONTINUE;
case DTLS_ST_SW_HELLO_VERIFY_REQUEST:
return WRITE_TRAN_FINISHED;
case TLS_ST_SW_SRVR_HELLO:
if (s->hit) {
if (s->tlsext_ticket_expected)
st->hand_state = TLS_ST_SW_SESSION_TICKET;
else
st->hand_state = TLS_ST_SW_CHANGE;
} else {
if (!(s->s3->tmp.new_cipher->algorithm_auth &
(SSL_aNULL | SSL_aSRP | SSL_aPSK))) {
st->hand_state = TLS_ST_SW_CERT;
} else if (send_server_key_exchange(s)) {
st->hand_state = TLS_ST_SW_KEY_EXCH;
} else if (send_certificate_request(s)) {
st->hand_state = TLS_ST_SW_CERT_REQ;
} else {
st->hand_state = TLS_ST_SW_SRVR_DONE;
}
}
return WRITE_TRAN_CONTINUE;
case TLS_ST_SW_CERT:
if (s->tlsext_status_expected) {
st->hand_state = TLS_ST_SW_CERT_STATUS;
return WRITE_TRAN_CONTINUE;
}
case TLS_ST_SW_CERT_STATUS:
if (send_server_key_exchange(s)) {
st->hand_state = TLS_ST_SW_KEY_EXCH;
return WRITE_TRAN_CONTINUE;
}
case TLS_ST_SW_KEY_EXCH:
if (send_certificate_request(s)) {
st->hand_state = TLS_ST_SW_CERT_REQ;
return WRITE_TRAN_CONTINUE;
}
case TLS_ST_SW_CERT_REQ:
st->hand_state = TLS_ST_SW_SRVR_DONE;
return WRITE_TRAN_CONTINUE;
case TLS_ST_SW_SRVR_DONE:
return WRITE_TRAN_FINISHED;
case TLS_ST_SR_FINISHED:
if (s->hit) {
st->hand_state = TLS_ST_OK;
ossl_statem_set_in_init(s, 0);
return WRITE_TRAN_CONTINUE;
} else if (s->tlsext_ticket_expected) {
st->hand_state = TLS_ST_SW_SESSION_TICKET;
} else {
st->hand_state = TLS_ST_SW_CHANGE;
}
return WRITE_TRAN_CONTINUE;
case TLS_ST_SW_SESSION_TICKET:
st->hand_state = TLS_ST_SW_CHANGE;
return WRITE_TRAN_CONTINUE;
case TLS_ST_SW_CHANGE:
st->hand_state = TLS_ST_SW_FINISHED;
return WRITE_TRAN_CONTINUE;
case TLS_ST_SW_FINISHED:
if (s->hit) {
return WRITE_TRAN_FINISHED;
}
st->hand_state = TLS_ST_OK;
ossl_statem_set_in_init(s, 0);
return WRITE_TRAN_CONTINUE;
default:
return WRITE_TRAN_ERROR;
}
}
WORK_STATE ossl_statem_server_pre_work(SSL *s, WORK_STATE wst)
{
OSSL_STATEM *st = &s->statem;
switch (st->hand_state) {
case TLS_ST_SW_HELLO_REQ:
s->shutdown = 0;
if (SSL_IS_DTLS(s))
dtls1_clear_sent_buffer(s);
break;
case DTLS_ST_SW_HELLO_VERIFY_REQUEST:
s->shutdown = 0;
if (SSL_IS_DTLS(s)) {
dtls1_clear_sent_buffer(s);
st->use_timer = 0;
}
break;
case TLS_ST_SW_SRVR_HELLO:
if (SSL_IS_DTLS(s)) {
st->use_timer = 1;
}
break;
case TLS_ST_SW_SRVR_DONE:
#ifndef OPENSSL_NO_SCTP
if (SSL_IS_DTLS(s) && BIO_dgram_is_sctp(SSL_get_wbio(s)))
return dtls_wait_for_dry(s);
#endif
return WORK_FINISHED_CONTINUE;
case TLS_ST_SW_SESSION_TICKET:
if (SSL_IS_DTLS(s)) {
st->use_timer = 0;
}
break;
case TLS_ST_SW_CHANGE:
s->session->cipher = s->s3->tmp.new_cipher;
if (!s->method->ssl3_enc->setup_key_block(s)) {
ossl_statem_set_error(s);
return WORK_ERROR;
}
if (SSL_IS_DTLS(s)) {
st->use_timer = 0;
}
return WORK_FINISHED_CONTINUE;
case TLS_ST_OK:
return tls_finish_handshake(s, wst);
default:
break;
}
return WORK_FINISHED_CONTINUE;
}
WORK_STATE ossl_statem_server_post_work(SSL *s, WORK_STATE wst)
{
OSSL_STATEM *st = &s->statem;
s->init_num = 0;
switch (st->hand_state) {
case TLS_ST_SW_HELLO_REQ:
if (statem_flush(s) != 1)
return WORK_MORE_A;
if (!ssl3_init_finished_mac(s)) {
ossl_statem_set_error(s);
return WORK_ERROR;
}
break;
case DTLS_ST_SW_HELLO_VERIFY_REQUEST:
if (statem_flush(s) != 1)
return WORK_MORE_A;
if (s->version != DTLS1_BAD_VER && !ssl3_init_finished_mac(s)) {
ossl_statem_set_error(s);
return WORK_ERROR;
}
s->first_packet = 1;
break;
case TLS_ST_SW_SRVR_HELLO:
#ifndef OPENSSL_NO_SCTP
if (SSL_IS_DTLS(s) && s->hit) {
unsigned char sctpauthkey[64];
char labelbuffer[sizeof(DTLS1_SCTP_AUTH_LABEL)];
memcpy(labelbuffer, DTLS1_SCTP_AUTH_LABEL,
sizeof(DTLS1_SCTP_AUTH_LABEL));
if (SSL_export_keying_material(s, sctpauthkey,
sizeof(sctpauthkey), labelbuffer,
sizeof(labelbuffer), NULL, 0,
0) <= 0) {
ossl_statem_set_error(s);
return WORK_ERROR;
}
BIO_ctrl(SSL_get_wbio(s), BIO_CTRL_DGRAM_SCTP_ADD_AUTH_KEY,
sizeof(sctpauthkey), sctpauthkey);
}
#endif
break;
case TLS_ST_SW_CHANGE:
#ifndef OPENSSL_NO_SCTP
if (SSL_IS_DTLS(s) && !s->hit) {
BIO_ctrl(SSL_get_wbio(s), BIO_CTRL_DGRAM_SCTP_NEXT_AUTH_KEY,
0, NULL);
}
#endif
if (!s->method->ssl3_enc->change_cipher_state(s,
SSL3_CHANGE_CIPHER_SERVER_WRITE))
{
ossl_statem_set_error(s);
return WORK_ERROR;
}
if (SSL_IS_DTLS(s))
dtls1_reset_seq_numbers(s, SSL3_CC_WRITE);
break;
case TLS_ST_SW_SRVR_DONE:
if (statem_flush(s) != 1)
return WORK_MORE_A;
break;
case TLS_ST_SW_FINISHED:
if (statem_flush(s) != 1)
return WORK_MORE_A;
#ifndef OPENSSL_NO_SCTP
if (SSL_IS_DTLS(s) && s->hit) {
BIO_ctrl(SSL_get_wbio(s), BIO_CTRL_DGRAM_SCTP_NEXT_AUTH_KEY,
0, NULL);
}
#endif
break;
default:
break;
}
return WORK_FINISHED_CONTINUE;
}
int ossl_statem_server_construct_message(SSL *s)
{
OSSL_STATEM *st = &s->statem;
switch (st->hand_state) {
case DTLS_ST_SW_HELLO_VERIFY_REQUEST:
return dtls_construct_hello_verify_request(s);
case TLS_ST_SW_HELLO_REQ:
return tls_construct_hello_request(s);
case TLS_ST_SW_SRVR_HELLO:
return tls_construct_server_hello(s);
case TLS_ST_SW_CERT:
return tls_construct_server_certificate(s);
case TLS_ST_SW_KEY_EXCH:
return tls_construct_server_key_exchange(s);
case TLS_ST_SW_CERT_REQ:
return tls_construct_certificate_request(s);
case TLS_ST_SW_SRVR_DONE:
return tls_construct_server_done(s);
case TLS_ST_SW_SESSION_TICKET:
return tls_construct_new_session_ticket(s);
case TLS_ST_SW_CERT_STATUS:
return tls_construct_cert_status(s);
case TLS_ST_SW_CHANGE:
if (SSL_IS_DTLS(s))
return dtls_construct_change_cipher_spec(s);
else
return tls_construct_change_cipher_spec(s);
case TLS_ST_SW_FINISHED:
return tls_construct_finished(s,
s->method->
ssl3_enc->server_finished_label,
s->method->
ssl3_enc->server_finished_label_len);
default:
break;
}
return 0;
}
unsigned long ossl_statem_server_max_message_size(SSL *s)
{
OSSL_STATEM *st = &s->statem;
switch (st->hand_state) {
case TLS_ST_SR_CLNT_HELLO:
return CLIENT_HELLO_MAX_LENGTH;
case TLS_ST_SR_CERT:
return s->max_cert_list;
case TLS_ST_SR_KEY_EXCH:
return CLIENT_KEY_EXCH_MAX_LENGTH;
case TLS_ST_SR_CERT_VRFY:
return SSL3_RT_MAX_PLAIN_LENGTH;
#ifndef OPENSSL_NO_NEXTPROTONEG
case TLS_ST_SR_NEXT_PROTO:
return NEXT_PROTO_MAX_LENGTH;
#endif
case TLS_ST_SR_CHANGE:
return CCS_MAX_LENGTH;
case TLS_ST_SR_FINISHED:
return FINISHED_MAX_LENGTH;
default:
break;
}
return 0;
}
MSG_PROCESS_RETURN ossl_statem_server_process_message(SSL *s, PACKET *pkt)
{
OSSL_STATEM *st = &s->statem;
switch (st->hand_state) {
case TLS_ST_SR_CLNT_HELLO:
return tls_process_client_hello(s, pkt);
case TLS_ST_SR_CERT:
return tls_process_client_certificate(s, pkt);
case TLS_ST_SR_KEY_EXCH:
return tls_process_client_key_exchange(s, pkt);
case TLS_ST_SR_CERT_VRFY:
return tls_process_cert_verify(s, pkt);
#ifndef OPENSSL_NO_NEXTPROTONEG
case TLS_ST_SR_NEXT_PROTO:
return tls_process_next_proto(s, pkt);
#endif
case TLS_ST_SR_CHANGE:
return tls_process_change_cipher_spec(s, pkt);
case TLS_ST_SR_FINISHED:
return tls_process_finished(s, pkt);
default:
break;
}
return MSG_PROCESS_ERROR;
}
WORK_STATE ossl_statem_server_post_process_message(SSL *s, WORK_STATE wst)
{
OSSL_STATEM *st = &s->statem;
switch (st->hand_state) {
case TLS_ST_SR_CLNT_HELLO:
return tls_post_process_client_hello(s, wst);
case TLS_ST_SR_KEY_EXCH:
return tls_post_process_client_key_exchange(s, wst);
case TLS_ST_SR_CERT_VRFY:
#ifndef OPENSSL_NO_SCTP
if (
BIO_dgram_is_sctp(SSL_get_wbio(s))
&& s->renegotiate && BIO_dgram_sctp_msg_waiting(SSL_get_rbio(s))) {
s->s3->in_read_app_data = 2;
s->rwstate = SSL_READING;
BIO_clear_retry_flags(SSL_get_rbio(s));
BIO_set_retry_read(SSL_get_rbio(s));
ossl_statem_set_sctp_read_sock(s, 1);
return WORK_MORE_A;
} else {
ossl_statem_set_sctp_read_sock(s, 0);
}
#endif
return WORK_FINISHED_CONTINUE;
default:
break;
}
return WORK_ERROR;
}
static int ssl_check_srp_ext_ClientHello(SSL *s, int *al)
{
int ret = SSL_ERROR_NONE;
*al = SSL_AD_UNRECOGNIZED_NAME;
if ((s->s3->tmp.new_cipher->algorithm_mkey & SSL_kSRP) &&
(s->srp_ctx.TLS_ext_srp_username_callback != NULL)) {
if (s->srp_ctx.login == NULL) {
ret = SSL3_AL_FATAL;
*al = SSL_AD_UNKNOWN_PSK_IDENTITY;
} else {
ret = SSL_srp_server_param_with_username(s, al);
}
}
return ret;
}
int tls_construct_hello_request(SSL *s)
{
if (!ssl_set_handshake_header(s, SSL3_MT_HELLO_REQUEST, 0)) {
SSLerr(SSL_F_TLS_CONSTRUCT_HELLO_REQUEST, ERR_R_INTERNAL_ERROR);
ossl_statem_set_error(s);
return 0;
}
return 1;
}
unsigned int dtls_raw_hello_verify_request(unsigned char *buf,
unsigned char *cookie,
unsigned char cookie_len)
{
unsigned int msg_len;
unsigned char *p;
p = buf;
*(p++) = DTLS1_VERSION >> 8;
*(p++) = DTLS1_VERSION & 0xFF;
*(p++) = (unsigned char)cookie_len;
memcpy(p, cookie, cookie_len);
p += cookie_len;
msg_len = p - buf;
return msg_len;
}
int dtls_construct_hello_verify_request(SSL *s)
{
unsigned int len;
unsigned char *buf;
buf = (unsigned char *)s->init_buf->data;
if (s->ctx->app_gen_cookie_cb == NULL ||
s->ctx->app_gen_cookie_cb(s, s->d1->cookie,
&(s->d1->cookie_len)) == 0 ||
s->d1->cookie_len > 255) {
SSLerr(SSL_F_DTLS_CONSTRUCT_HELLO_VERIFY_REQUEST,
SSL_R_COOKIE_GEN_CALLBACK_FAILURE);
ossl_statem_set_error(s);
return 0;
}
len = dtls_raw_hello_verify_request(&buf[DTLS1_HM_HEADER_LENGTH],
s->d1->cookie, s->d1->cookie_len);
dtls1_set_message_header(s, DTLS1_MT_HELLO_VERIFY_REQUEST, len, 0, len);
len += DTLS1_HM_HEADER_LENGTH;
s->init_num = len;
s->init_off = 0;
return 1;
}
MSG_PROCESS_RETURN tls_process_client_hello(SSL *s, PACKET *pkt)
{
int i, al = SSL_AD_INTERNAL_ERROR;
unsigned int j, complen = 0;
unsigned long id;
const SSL_CIPHER *c;
#ifndef OPENSSL_NO_COMP
SSL_COMP *comp = NULL;
#endif
STACK_OF(SSL_CIPHER) *ciphers = NULL;
int protverr;
PACKET session_id, cipher_suites, compression, extensions, cookie;
int is_v2_record;
static const unsigned char null_compression = 0;
is_v2_record = RECORD_LAYER_is_sslv2_record(&s->rlayer);
PACKET_null_init(&cookie);
if (is_v2_record) {
unsigned int version;
unsigned int mt;
if (!PACKET_get_1(pkt, &mt)
|| mt != SSL2_MT_CLIENT_HELLO) {
SSLerr(SSL_F_TLS_PROCESS_CLIENT_HELLO, ERR_R_INTERNAL_ERROR);
goto err;
}
if (!PACKET_get_net_2(pkt, &version)) {
SSLerr(SSL_F_TLS_PROCESS_CLIENT_HELLO, SSL_R_UNKNOWN_PROTOCOL);
goto err;
}
if (version == 0x0002) {
SSLerr(SSL_F_TLS_PROCESS_CLIENT_HELLO, SSL_R_UNKNOWN_PROTOCOL);
goto err;
} else if ((version & 0xff00) == (SSL3_VERSION_MAJOR << 8)) {
s->client_version = version;
} else {
SSLerr(SSL_F_TLS_PROCESS_CLIENT_HELLO, SSL_R_UNKNOWN_PROTOCOL);
goto err;
}
} else {
if (!PACKET_get_net_2(pkt, (unsigned int *)&s->client_version)) {
al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CLIENT_HELLO, SSL_R_LENGTH_TOO_SHORT);
goto f_err;
}
}
if (!SSL_IS_DTLS(s)) {
protverr = ssl_choose_server_version(s);
} else if (s->method->version != DTLS_ANY_VERSION &&
DTLS_VERSION_LT(s->client_version, s->version)) {
protverr = SSL_R_VERSION_TOO_LOW;
} else {
protverr = 0;
}
if (protverr) {
SSLerr(SSL_F_TLS_PROCESS_CLIENT_HELLO, protverr);
if ((!s->enc_write_ctx && !s->write_hash)) {
s->version = s->client_version;
}
al = SSL_AD_PROTOCOL_VERSION;
goto f_err;
}
if (is_v2_record) {
unsigned int cipher_len, session_id_len, challenge_len;
PACKET challenge;
if (!PACKET_get_net_2(pkt, &cipher_len)
|| !PACKET_get_net_2(pkt, &session_id_len)
|| !PACKET_get_net_2(pkt, &challenge_len)) {
SSLerr(SSL_F_TLS_PROCESS_CLIENT_HELLO,
SSL_R_RECORD_LENGTH_MISMATCH);
al = SSL_AD_DECODE_ERROR;
goto f_err;
}
if (session_id_len > SSL_MAX_SSL_SESSION_ID_LENGTH) {
al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CLIENT_HELLO, SSL_R_LENGTH_MISMATCH);
goto f_err;
}
if (!PACKET_get_sub_packet(pkt, &cipher_suites, cipher_len)
|| !PACKET_get_sub_packet(pkt, &session_id, session_id_len)
|| !PACKET_get_sub_packet(pkt, &challenge, challenge_len)
|| PACKET_remaining(pkt) != 0) {
SSLerr(SSL_F_TLS_PROCESS_CLIENT_HELLO,
SSL_R_RECORD_LENGTH_MISMATCH);
al = SSL_AD_DECODE_ERROR;
goto f_err;
}
challenge_len = challenge_len > SSL3_RANDOM_SIZE ? SSL3_RANDOM_SIZE :
challenge_len;
memset(s->s3->client_random, 0, SSL3_RANDOM_SIZE);
if (!PACKET_copy_bytes(&challenge,
s->s3->client_random + SSL3_RANDOM_SIZE -
challenge_len, challenge_len)
|| !PACKET_buf_init(&compression, &null_compression, 1)) {
SSLerr(SSL_F_TLS_PROCESS_CLIENT_HELLO, ERR_R_INTERNAL_ERROR);
al = SSL_AD_INTERNAL_ERROR;
goto f_err;
}
PACKET_null_init(&extensions);
} else {
if (!PACKET_copy_bytes(pkt, s->s3->client_random, SSL3_RANDOM_SIZE)
|| !PACKET_get_length_prefixed_1(pkt, &session_id)) {
al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CLIENT_HELLO, SSL_R_LENGTH_MISMATCH);
goto f_err;
}
if (PACKET_remaining(&session_id) > SSL_MAX_SSL_SESSION_ID_LENGTH) {
al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CLIENT_HELLO, SSL_R_LENGTH_MISMATCH);
goto f_err;
}
if (SSL_IS_DTLS(s)) {
if (!PACKET_get_length_prefixed_1(pkt, &cookie)) {
al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CLIENT_HELLO, SSL_R_LENGTH_MISMATCH);
goto f_err;
}
if (SSL_get_options(s) & SSL_OP_COOKIE_EXCHANGE) {
if (PACKET_remaining(&cookie) == 0)
return 1;
}
}
if (!PACKET_get_length_prefixed_2(pkt, &cipher_suites)
|| !PACKET_get_length_prefixed_1(pkt, &compression)) {
al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CLIENT_HELLO, SSL_R_LENGTH_MISMATCH);
goto f_err;
}
extensions = *pkt;
}
if (SSL_IS_DTLS(s)) {
if (SSL_get_options(s) & SSL_OP_COOKIE_EXCHANGE) {
if (s->ctx->app_verify_cookie_cb != NULL) {
if (s->ctx->app_verify_cookie_cb(s, PACKET_data(&cookie),
PACKET_remaining(&cookie)) ==
0) {
al = SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_TLS_PROCESS_CLIENT_HELLO,
SSL_R_COOKIE_MISMATCH);
goto f_err;
}
} else if (!PACKET_equal(&cookie, s->d1->cookie, s->d1->cookie_len)) {
al = SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_TLS_PROCESS_CLIENT_HELLO, SSL_R_COOKIE_MISMATCH);
goto f_err;
}
s->d1->cookie_verified = 1;
}
if (s->method->version == DTLS_ANY_VERSION) {
protverr = ssl_choose_server_version(s);
if (protverr != 0) {
SSLerr(SSL_F_TLS_PROCESS_CLIENT_HELLO, protverr);
s->version = s->client_version;
al = SSL_AD_PROTOCOL_VERSION;
goto f_err;
}
}
}
s->hit = 0;
if (is_v2_record ||
(s->new_session &&
(s->options & SSL_OP_NO_SESSION_RESUMPTION_ON_RENEGOTIATION))) {
if (!ssl_get_new_session(s, 1))
goto err;
} else {
i = ssl_get_prev_session(s, &extensions, &session_id);
if (i == 1 && s->version == s->session->ssl_version) {
s->hit = 1;
} else if (i == -1) {
goto err;
} else {
if (!ssl_get_new_session(s, 1))
goto err;
}
}
if (ssl_bytes_to_cipher_list(s, &cipher_suites, &(ciphers),
is_v2_record, &al) == NULL) {
goto f_err;
}
if (s->hit) {
j = 0;
id = s->session->cipher->id;
#ifdef CIPHER_DEBUG
fprintf(stderr, "client sent %d ciphers\n", sk_SSL_CIPHER_num(ciphers));
#endif
for (i = 0; i < sk_SSL_CIPHER_num(ciphers); i++) {
c = sk_SSL_CIPHER_value(ciphers, i);
#ifdef CIPHER_DEBUG
fprintf(stderr, "client [%2d of %2d]:%s\n",
i, sk_SSL_CIPHER_num(ciphers), SSL_CIPHER_get_name(c));
#endif
if (c->id == id) {
j = 1;
break;
}
}
if (j == 0) {
al = SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_TLS_PROCESS_CLIENT_HELLO,
SSL_R_REQUIRED_CIPHER_MISSING);
goto f_err;
}
}
complen = PACKET_remaining(&compression);
for (j = 0; j < complen; j++) {
if (PACKET_data(&compression)[j] == 0)
break;
}
if (j >= complen) {
al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CLIENT_HELLO, SSL_R_NO_COMPRESSION_SPECIFIED);
goto f_err;
}
if (s->version >= SSL3_VERSION) {
if (!ssl_parse_clienthello_tlsext(s, &extensions)) {
SSLerr(SSL_F_TLS_PROCESS_CLIENT_HELLO, SSL_R_PARSE_TLSEXT);
goto err;
}
}
{
unsigned char *pos;
pos = s->s3->server_random;
if (ssl_fill_hello_random(s, 1, pos, SSL3_RANDOM_SIZE) <= 0) {
goto f_err;
}
}
if (!s->hit && s->version >= TLS1_VERSION && s->tls_session_secret_cb) {
const SSL_CIPHER *pref_cipher = NULL;
s->session->master_key_length = sizeof(s->session->master_key);
if (s->tls_session_secret_cb(s, s->session->master_key,
&s->session->master_key_length, ciphers,
&pref_cipher,
s->tls_session_secret_cb_arg)) {
s->hit = 1;
s->session->ciphers = ciphers;
s->session->verify_result = X509_V_OK;
ciphers = NULL;
pref_cipher =
pref_cipher ? pref_cipher : ssl3_choose_cipher(s,
s->
session->ciphers,
SSL_get_ciphers
(s));
if (pref_cipher == NULL) {
al = SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_TLS_PROCESS_CLIENT_HELLO, SSL_R_NO_SHARED_CIPHER);
goto f_err;
}
s->session->cipher = pref_cipher;
sk_SSL_CIPHER_free(s->cipher_list);
s->cipher_list = sk_SSL_CIPHER_dup(s->session->ciphers);
sk_SSL_CIPHER_free(s->cipher_list_by_id);
s->cipher_list_by_id = sk_SSL_CIPHER_dup(s->session->ciphers);
}
}
s->s3->tmp.new_compression = NULL;
#ifndef OPENSSL_NO_COMP
if (s->session->compress_meth != 0) {
int m, comp_id = s->session->compress_meth;
unsigned int k;
if (!ssl_allow_compression(s)) {
SSLerr(SSL_F_TLS_PROCESS_CLIENT_HELLO,
SSL_R_INCONSISTENT_COMPRESSION);
goto f_err;
}
for (m = 0; m < sk_SSL_COMP_num(s->ctx->comp_methods); m++) {
comp = sk_SSL_COMP_value(s->ctx->comp_methods, m);
if (comp_id == comp->id) {
s->s3->tmp.new_compression = comp;
break;
}
}
if (s->s3->tmp.new_compression == NULL) {
SSLerr(SSL_F_TLS_PROCESS_CLIENT_HELLO,
SSL_R_INVALID_COMPRESSION_ALGORITHM);
goto f_err;
}
for (k = 0; k < complen; k++) {
if (PACKET_data(&compression)[k] == comp_id)
break;
}
if (k >= complen) {
al = SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_TLS_PROCESS_CLIENT_HELLO,
SSL_R_REQUIRED_COMPRESSION_ALGORITHM_MISSING);
goto f_err;
}
} else if (s->hit)
comp = NULL;
else if (ssl_allow_compression(s) && s->ctx->comp_methods) {
int m, nn, v, done = 0;
unsigned int o;
nn = sk_SSL_COMP_num(s->ctx->comp_methods);
for (m = 0; m < nn; m++) {
comp = sk_SSL_COMP_value(s->ctx->comp_methods, m);
v = comp->id;
for (o = 0; o < complen; o++) {
if (v == PACKET_data(&compression)[o]) {
done = 1;
break;
}
}
if (done)
break;
}
if (done)
s->s3->tmp.new_compression = comp;
else
comp = NULL;
}
#else
if (s->session->compress_meth != 0) {
SSLerr(SSL_F_TLS_PROCESS_CLIENT_HELLO, SSL_R_INCONSISTENT_COMPRESSION);
goto f_err;
}
#endif
if (!s->hit) {
#ifdef OPENSSL_NO_COMP
s->session->compress_meth = 0;
#else
s->session->compress_meth = (comp == NULL) ? 0 : comp->id;
#endif
sk_SSL_CIPHER_free(s->session->ciphers);
s->session->ciphers = ciphers;
if (ciphers == NULL) {
al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CLIENT_HELLO, ERR_R_INTERNAL_ERROR);
goto f_err;
}
ciphers = NULL;
if (!tls1_set_server_sigalgs(s)) {
SSLerr(SSL_F_TLS_PROCESS_CLIENT_HELLO, SSL_R_CLIENTHELLO_TLSEXT);
goto err;
}
}
sk_SSL_CIPHER_free(ciphers);
return MSG_PROCESS_CONTINUE_PROCESSING;
f_err:
ssl3_send_alert(s, SSL3_AL_FATAL, al);
err:
ossl_statem_set_error(s);
sk_SSL_CIPHER_free(ciphers);
return MSG_PROCESS_ERROR;
}
WORK_STATE tls_post_process_client_hello(SSL *s, WORK_STATE wst)
{
int al = SSL_AD_HANDSHAKE_FAILURE;
const SSL_CIPHER *cipher;
if (wst == WORK_MORE_A) {
if (!s->hit) {
if (s->cert->cert_cb) {
int rv = s->cert->cert_cb(s, s->cert->cert_cb_arg);
if (rv == 0) {
al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_POST_PROCESS_CLIENT_HELLO,
SSL_R_CERT_CB_ERROR);
goto f_err;
}
if (rv < 0) {
s->rwstate = SSL_X509_LOOKUP;
return WORK_MORE_A;
}
s->rwstate = SSL_NOTHING;
}
cipher =
ssl3_choose_cipher(s, s->session->ciphers, SSL_get_ciphers(s));
if (cipher == NULL) {
SSLerr(SSL_F_TLS_POST_PROCESS_CLIENT_HELLO,
SSL_R_NO_SHARED_CIPHER);
goto f_err;
}
s->s3->tmp.new_cipher = cipher;
if (s->not_resumable_session_cb != NULL)
s->session->not_resumable = s->not_resumable_session_cb(s,
((cipher->algorithm_mkey & (SSL_kDHE | SSL_kECDHE)) != 0));
if (s->session->not_resumable)
s->tlsext_ticket_expected = 0;
} else {
s->s3->tmp.new_cipher = s->session->cipher;
}
if (!(s->verify_mode & SSL_VERIFY_PEER)) {
if (!ssl3_digest_cached_records(s, 0)) {
al = SSL_AD_INTERNAL_ERROR;
goto f_err;
}
}
if (s->version >= SSL3_VERSION) {
if (!ssl_check_clienthello_tlsext_late(s, &al)) {
SSLerr(SSL_F_TLS_POST_PROCESS_CLIENT_HELLO,
SSL_R_CLIENTHELLO_TLSEXT);
goto f_err;
}
}
wst = WORK_MORE_B;
}
#ifndef OPENSSL_NO_SRP
if (wst == WORK_MORE_B) {
int ret;
if ((ret = ssl_check_srp_ext_ClientHello(s, &al)) < 0) {
s->rwstate = SSL_X509_LOOKUP;
return WORK_MORE_B;
}
if (ret != SSL_ERROR_NONE) {
if (al != TLS1_AD_UNKNOWN_PSK_IDENTITY)
SSLerr(SSL_F_TLS_POST_PROCESS_CLIENT_HELLO,
SSL_R_CLIENTHELLO_TLSEXT);
goto f_err;
}
}
#endif
s->renegotiate = 2;
return WORK_FINISHED_STOP;
f_err:
ssl3_send_alert(s, SSL3_AL_FATAL, al);
ossl_statem_set_error(s);
return WORK_ERROR;
}
int tls_construct_server_hello(SSL *s)
{
unsigned char *buf;
unsigned char *p, *d;
int i, sl;
int al = 0;
unsigned long l;
buf = (unsigned char *)s->init_buf->data;
d = p = ssl_handshake_start(s);
*(p++) = s->version >> 8;
*(p++) = s->version & 0xff;
memcpy(p, s->s3->server_random, SSL3_RANDOM_SIZE);
p += SSL3_RANDOM_SIZE;
if (s->session->not_resumable ||
(!(s->ctx->session_cache_mode & SSL_SESS_CACHE_SERVER)
&& !s->hit))
s->session->session_id_length = 0;
sl = s->session->session_id_length;
if (sl > (int)sizeof(s->session->session_id)) {
SSLerr(SSL_F_TLS_CONSTRUCT_SERVER_HELLO, ERR_R_INTERNAL_ERROR);
ossl_statem_set_error(s);
return 0;
}
*(p++) = sl;
memcpy(p, s->session->session_id, sl);
p += sl;
i = ssl3_put_cipher_by_char(s->s3->tmp.new_cipher, p);
p += i;
#ifdef OPENSSL_NO_COMP
*(p++) = 0;
#else
if (s->s3->tmp.new_compression == NULL)
*(p++) = 0;
else
*(p++) = s->s3->tmp.new_compression->id;
#endif
if (ssl_prepare_serverhello_tlsext(s) <= 0) {
SSLerr(SSL_F_TLS_CONSTRUCT_SERVER_HELLO, SSL_R_SERVERHELLO_TLSEXT);
ossl_statem_set_error(s);
return 0;
}
if ((p =
ssl_add_serverhello_tlsext(s, p, buf + SSL3_RT_MAX_PLAIN_LENGTH,
&al)) == NULL) {
ssl3_send_alert(s, SSL3_AL_FATAL, al);
SSLerr(SSL_F_TLS_CONSTRUCT_SERVER_HELLO, ERR_R_INTERNAL_ERROR);
ossl_statem_set_error(s);
return 0;
}
l = (p - d);
if (!ssl_set_handshake_header(s, SSL3_MT_SERVER_HELLO, l)) {
SSLerr(SSL_F_TLS_CONSTRUCT_SERVER_HELLO, ERR_R_INTERNAL_ERROR);
ossl_statem_set_error(s);
return 0;
}
return 1;
}
int tls_construct_server_done(SSL *s)
{
if (!ssl_set_handshake_header(s, SSL3_MT_SERVER_DONE, 0)) {
SSLerr(SSL_F_TLS_CONSTRUCT_SERVER_DONE, ERR_R_INTERNAL_ERROR);
ossl_statem_set_error(s);
return 0;
}
if (!s->s3->tmp.cert_request) {
if (!ssl3_digest_cached_records(s, 0)) {
ossl_statem_set_error(s);
}
}
return 1;
}
int tls_construct_server_key_exchange(SSL *s)
{
#ifndef OPENSSL_NO_DH
EVP_PKEY *pkdh = NULL;
int j;
#endif
#ifndef OPENSSL_NO_EC
unsigned char *encodedPoint = NULL;
int encodedlen = 0;
int curve_id = 0;
#endif
EVP_PKEY *pkey;
const EVP_MD *md = NULL;
unsigned char *p, *d;
int al, i;
unsigned long type;
int n;
const BIGNUM *r[4];
int nr[4], kn;
BUF_MEM *buf;
EVP_MD_CTX *md_ctx = EVP_MD_CTX_new();
if (md_ctx == NULL) {
SSLerr(SSL_F_TLS_CONSTRUCT_SERVER_KEY_EXCHANGE, ERR_R_MALLOC_FAILURE);
al = SSL_AD_INTERNAL_ERROR;
goto f_err;
}
type = s->s3->tmp.new_cipher->algorithm_mkey;
buf = s->init_buf;
r[0] = r[1] = r[2] = r[3] = NULL;
n = 0;
#ifndef OPENSSL_NO_PSK
if (type & SSL_PSK) {
n += 2;
if (s->cert->psk_identity_hint)
n += strlen(s->cert->psk_identity_hint);
}
if (type & (SSL_kPSK | SSL_kRSAPSK)) {
} else
#endif
#ifndef OPENSSL_NO_DH
if (type & (SSL_kDHE | SSL_kDHEPSK)) {
CERT *cert = s->cert;
EVP_PKEY *pkdhp = NULL;
DH *dh;
if (s->cert->dh_tmp_auto) {
DH *dhp = ssl_get_auto_dh(s);
pkdh = EVP_PKEY_new();
if (pkdh == NULL || dhp == NULL) {
DH_free(dhp);
al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_CONSTRUCT_SERVER_KEY_EXCHANGE,
ERR_R_INTERNAL_ERROR);
goto f_err;
}
EVP_PKEY_assign_DH(pkdh, dhp);
pkdhp = pkdh;
} else {
pkdhp = cert->dh_tmp;
}
if ((pkdhp == NULL) && (s->cert->dh_tmp_cb != NULL)) {
DH *dhp = s->cert->dh_tmp_cb(s, 0, 1024);
pkdh = ssl_dh_to_pkey(dhp);
if (pkdh == NULL) {
al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_CONSTRUCT_SERVER_KEY_EXCHANGE,
ERR_R_INTERNAL_ERROR);
goto f_err;
}
pkdhp = pkdh;
}
if (pkdhp == NULL) {
al = SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_TLS_CONSTRUCT_SERVER_KEY_EXCHANGE,
SSL_R_MISSING_TMP_DH_KEY);
goto f_err;
}
if (!ssl_security(s, SSL_SECOP_TMP_DH,
EVP_PKEY_security_bits(pkdhp), 0, pkdhp)) {
al = SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_TLS_CONSTRUCT_SERVER_KEY_EXCHANGE,
SSL_R_DH_KEY_TOO_SMALL);
goto f_err;
}
if (s->s3->tmp.pkey != NULL) {
SSLerr(SSL_F_TLS_CONSTRUCT_SERVER_KEY_EXCHANGE,
ERR_R_INTERNAL_ERROR);
goto err;
}
s->s3->tmp.pkey = ssl_generate_pkey(pkdhp);
if (s->s3->tmp.pkey == NULL) {
SSLerr(SSL_F_TLS_CONSTRUCT_SERVER_KEY_EXCHANGE, ERR_R_EVP_LIB);
goto err;
}
dh = EVP_PKEY_get0_DH(s->s3->tmp.pkey);
EVP_PKEY_free(pkdh);
pkdh = NULL;
DH_get0_pqg(dh, &r[0], NULL, &r[1]);
DH_get0_key(dh, &r[2], NULL);
} else
#endif
#ifndef OPENSSL_NO_EC
if (type & (SSL_kECDHE | SSL_kECDHEPSK)) {
int nid;
if (s->s3->tmp.pkey != NULL) {
SSLerr(SSL_F_TLS_CONSTRUCT_SERVER_KEY_EXCHANGE,
ERR_R_INTERNAL_ERROR);
goto err;
}
nid = tls1_shared_curve(s, -2);
curve_id = tls1_ec_nid2curve_id(nid);
if (curve_id == 0) {
SSLerr(SSL_F_TLS_CONSTRUCT_SERVER_KEY_EXCHANGE,
SSL_R_UNSUPPORTED_ELLIPTIC_CURVE);
goto err;
}
s->s3->tmp.pkey = ssl_generate_pkey_curve(curve_id);
if (s->s3->tmp.pkey == NULL) {
al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_CONSTRUCT_SERVER_KEY_EXCHANGE, ERR_R_EVP_LIB);
goto f_err;
}
encodedlen = EVP_PKEY_get1_tls_encodedpoint(s->s3->tmp.pkey,
&encodedPoint);
if (encodedlen == 0) {
SSLerr(SSL_F_TLS_CONSTRUCT_SERVER_KEY_EXCHANGE, ERR_R_EC_LIB);
goto err;
}
n += 4 + encodedlen;
r[0] = NULL;
r[1] = NULL;
r[2] = NULL;
r[3] = NULL;
} else
#endif
#ifndef OPENSSL_NO_SRP
if (type & SSL_kSRP) {
if ((s->srp_ctx.N == NULL) ||
(s->srp_ctx.g == NULL) ||
(s->srp_ctx.s == NULL) || (s->srp_ctx.B == NULL)) {
SSLerr(SSL_F_TLS_CONSTRUCT_SERVER_KEY_EXCHANGE,
SSL_R_MISSING_SRP_PARAM);
goto err;
}
r[0] = s->srp_ctx.N;
r[1] = s->srp_ctx.g;
r[2] = s->srp_ctx.s;
r[3] = s->srp_ctx.B;
} else
#endif
{
al = SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_TLS_CONSTRUCT_SERVER_KEY_EXCHANGE,
SSL_R_UNKNOWN_KEY_EXCHANGE_TYPE);
goto f_err;
}
for (i = 0; i < 4 && r[i] != NULL; i++) {
nr[i] = BN_num_bytes(r[i]);
#ifndef OPENSSL_NO_SRP
if ((i == 2) && (type & SSL_kSRP))
n += 1 + nr[i];
else
#endif
#ifndef OPENSSL_NO_DH
if ((i == 2) && (type & (SSL_kDHE | SSL_kDHEPSK)))
n += 2 + nr[0];
else
#endif
n += 2 + nr[i];
}
if (!(s->s3->tmp.new_cipher->algorithm_auth & (SSL_aNULL | SSL_aSRP))
&& !(s->s3->tmp.new_cipher->algorithm_mkey & SSL_PSK)) {
if ((pkey = ssl_get_sign_pkey(s, s->s3->tmp.new_cipher, &md))
== NULL) {
al = SSL_AD_DECODE_ERROR;
goto f_err;
}
kn = EVP_PKEY_size(pkey);
if (SSL_USE_SIGALGS(s))
kn += 2;
kn += 2;
} else {
pkey = NULL;
kn = 0;
}
if (!BUF_MEM_grow_clean(buf, n + SSL_HM_HEADER_LENGTH(s) + kn)) {
SSLerr(SSL_F_TLS_CONSTRUCT_SERVER_KEY_EXCHANGE, ERR_LIB_BUF);
goto err;
}
d = p = ssl_handshake_start(s);
#ifndef OPENSSL_NO_PSK
if (type & SSL_PSK) {
if (s->cert->psk_identity_hint) {
size_t len = strlen(s->cert->psk_identity_hint);
if (len > PSK_MAX_IDENTITY_LEN) {
SSLerr(SSL_F_TLS_CONSTRUCT_SERVER_KEY_EXCHANGE,
ERR_R_INTERNAL_ERROR);
goto err;
}
s2n(len, p);
memcpy(p, s->cert->psk_identity_hint, len);
p += len;
} else {
s2n(0, p);
}
}
#endif
for (i = 0; i < 4 && r[i] != NULL; i++) {
#ifndef OPENSSL_NO_SRP
if ((i == 2) && (type & SSL_kSRP)) {
*p = nr[i];
p++;
} else
#endif
#ifndef OPENSSL_NO_DH
if ((i == 2) && (type & (SSL_kDHE | SSL_kDHEPSK))) {
s2n(nr[0], p);
for (j = 0; j < (nr[0] - nr[2]); ++j) {
*p = 0;
++p;
}
} else
#endif
s2n(nr[i], p);
BN_bn2bin(r[i], p);
p += nr[i];
}
#ifndef OPENSSL_NO_EC
if (type & (SSL_kECDHE | SSL_kECDHEPSK)) {
*p = NAMED_CURVE_TYPE;
p += 1;
*p = 0;
p += 1;
*p = curve_id;
p += 1;
*p = encodedlen;
p += 1;
memcpy(p, encodedPoint, encodedlen);
OPENSSL_free(encodedPoint);
encodedPoint = NULL;
p += encodedlen;
}
#endif
if (pkey != NULL) {
if (md) {
if (SSL_USE_SIGALGS(s)) {
if (!tls12_get_sigandhash(p, pkey, md)) {
al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_CONSTRUCT_SERVER_KEY_EXCHANGE,
ERR_R_INTERNAL_ERROR);
goto f_err;
}
p += 2;
}
#ifdef SSL_DEBUG
fprintf(stderr, "Using hash %s\n", EVP_MD_name(md));
#endif
if (EVP_SignInit_ex(md_ctx, md, NULL) <= 0
|| EVP_SignUpdate(md_ctx, &(s->s3->client_random[0]),
SSL3_RANDOM_SIZE) <= 0
|| EVP_SignUpdate(md_ctx, &(s->s3->server_random[0]),
SSL3_RANDOM_SIZE) <= 0
|| EVP_SignUpdate(md_ctx, d, n) <= 0
|| EVP_SignFinal(md_ctx, &(p[2]),
(unsigned int *)&i, pkey) <= 0) {
SSLerr(SSL_F_TLS_CONSTRUCT_SERVER_KEY_EXCHANGE, ERR_LIB_EVP);
al = SSL_AD_INTERNAL_ERROR;
goto f_err;
}
s2n(i, p);
n += i + 2;
if (SSL_USE_SIGALGS(s))
n += 2;
} else {
al = SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_TLS_CONSTRUCT_SERVER_KEY_EXCHANGE,
SSL_R_UNKNOWN_PKEY_TYPE);
goto f_err;
}
}
if (!ssl_set_handshake_header(s, SSL3_MT_SERVER_KEY_EXCHANGE, n)) {
al = SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_TLS_CONSTRUCT_SERVER_KEY_EXCHANGE, ERR_R_INTERNAL_ERROR);
goto f_err;
}
EVP_MD_CTX_free(md_ctx);
return 1;
f_err:
ssl3_send_alert(s, SSL3_AL_FATAL, al);
err:
#ifndef OPENSSL_NO_DH
EVP_PKEY_free(pkdh);
#endif
#ifndef OPENSSL_NO_EC
OPENSSL_free(encodedPoint);
#endif
EVP_MD_CTX_free(md_ctx);
ossl_statem_set_error(s);
return 0;
}
int tls_construct_certificate_request(SSL *s)
{
unsigned char *p, *d;
int i, j, nl, off, n;
STACK_OF(X509_NAME) *sk = NULL;
X509_NAME *name;
BUF_MEM *buf;
buf = s->init_buf;
d = p = ssl_handshake_start(s);
p++;
n = ssl3_get_req_cert_type(s, p);
d[0] = n;
p += n;
n++;
if (SSL_USE_SIGALGS(s)) {
const unsigned char *psigs;
unsigned char *etmp = p;
nl = tls12_get_psigalgs(s, &psigs);
p += 2;
nl = tls12_copy_sigalgs(s, p, psigs, nl);
s2n(nl, etmp);
p += nl;
n += nl + 2;
}
off = n;
p += 2;
n += 2;
sk = SSL_get_client_CA_list(s);
nl = 0;
if (sk != NULL) {
for (i = 0; i < sk_X509_NAME_num(sk); i++) {
name = sk_X509_NAME_value(sk, i);
j = i2d_X509_NAME(name, NULL);
if (!BUF_MEM_grow_clean(buf, SSL_HM_HEADER_LENGTH(s) + n + j + 2)) {
SSLerr(SSL_F_TLS_CONSTRUCT_CERTIFICATE_REQUEST, ERR_R_BUF_LIB);
goto err;
}
p = ssl_handshake_start(s) + n;
s2n(j, p);
i2d_X509_NAME(name, &p);
n += 2 + j;
nl += 2 + j;
}
}
p = ssl_handshake_start(s) + off;
s2n(nl, p);
if (!ssl_set_handshake_header(s, SSL3_MT_CERTIFICATE_REQUEST, n)) {
SSLerr(SSL_F_TLS_CONSTRUCT_CERTIFICATE_REQUEST, ERR_R_INTERNAL_ERROR);
goto err;
}
s->s3->tmp.cert_request = 1;
return 1;
err:
ossl_statem_set_error(s);
return 0;
}
static int tls_process_cke_psk_preamble(SSL *s, PACKET *pkt, int *al)
{
#ifndef OPENSSL_NO_PSK
unsigned char psk[PSK_MAX_PSK_LEN];
size_t psklen;
PACKET psk_identity;
if (!PACKET_get_length_prefixed_2(pkt, &psk_identity)) {
*al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CKE_PSK_PREAMBLE, SSL_R_LENGTH_MISMATCH);
return 0;
}
if (PACKET_remaining(&psk_identity) > PSK_MAX_IDENTITY_LEN) {
*al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CKE_PSK_PREAMBLE, SSL_R_DATA_LENGTH_TOO_LONG);
return 0;
}
if (s->psk_server_callback == NULL) {
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CKE_PSK_PREAMBLE, SSL_R_PSK_NO_SERVER_CB);
return 0;
}
if (!PACKET_strndup(&psk_identity, &s->session->psk_identity)) {
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CKE_PSK_PREAMBLE, ERR_R_INTERNAL_ERROR);
return 0;
}
psklen = s->psk_server_callback(s, s->session->psk_identity,
psk, sizeof(psk));
if (psklen > PSK_MAX_PSK_LEN) {
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CKE_PSK_PREAMBLE, ERR_R_INTERNAL_ERROR);
return 0;
} else if (psklen == 0) {
*al = SSL_AD_UNKNOWN_PSK_IDENTITY;
SSLerr(SSL_F_TLS_PROCESS_CKE_PSK_PREAMBLE,
SSL_R_PSK_IDENTITY_NOT_FOUND);
return 0;
}
OPENSSL_free(s->s3->tmp.psk);
s->s3->tmp.psk = OPENSSL_memdup(psk, psklen);
OPENSSL_cleanse(psk, psklen);
if (s->s3->tmp.psk == NULL) {
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CKE_PSK_PREAMBLE, ERR_R_MALLOC_FAILURE);
return 0;
}
s->s3->tmp.psklen = psklen;
return 1;
#else
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CKE_PSK_PREAMBLE, ERR_R_INTERNAL_ERROR);
return 0;
#endif
}
static int tls_process_cke_rsa(SSL *s, PACKET *pkt, int *al)
{
#ifndef OPENSSL_NO_RSA
unsigned char rand_premaster_secret[SSL_MAX_MASTER_KEY_LENGTH];
int decrypt_len;
unsigned char decrypt_good, version_good;
size_t j, padding_len;
PACKET enc_premaster;
RSA *rsa = NULL;
unsigned char *rsa_decrypt = NULL;
int ret = 0;
rsa = EVP_PKEY_get0_RSA(s->cert->pkeys[SSL_PKEY_RSA_ENC].privatekey);
if (rsa == NULL) {
*al = SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_TLS_PROCESS_CKE_RSA, SSL_R_MISSING_RSA_CERTIFICATE);
return 0;
}
if (s->version == SSL3_VERSION || s->version == DTLS1_BAD_VER) {
enc_premaster = *pkt;
} else {
if (!PACKET_get_length_prefixed_2(pkt, &enc_premaster)
|| PACKET_remaining(pkt) != 0) {
*al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CKE_RSA, SSL_R_LENGTH_MISMATCH);
return 0;
}
}
if (RSA_size(rsa) < SSL_MAX_MASTER_KEY_LENGTH) {
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CKE_RSA, RSA_R_KEY_SIZE_TOO_SMALL);
return 0;
}
rsa_decrypt = OPENSSL_malloc(RSA_size(rsa));
if (rsa_decrypt == NULL) {
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CKE_RSA, ERR_R_MALLOC_FAILURE);
return 0;
}
if (RAND_bytes(rand_premaster_secret, sizeof(rand_premaster_secret)) <= 0)
goto err;
decrypt_len = RSA_private_decrypt(PACKET_remaining(&enc_premaster),
PACKET_data(&enc_premaster),
rsa_decrypt, rsa, RSA_NO_PADDING);
if (decrypt_len < 0)
goto err;
if (decrypt_len < 11 + SSL_MAX_MASTER_KEY_LENGTH) {
*al = SSL_AD_DECRYPT_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CKE_RSA, SSL_R_DECRYPTION_FAILED);
goto err;
}
padding_len = decrypt_len - SSL_MAX_MASTER_KEY_LENGTH;
decrypt_good = constant_time_eq_int_8(rsa_decrypt[0], 0) &
constant_time_eq_int_8(rsa_decrypt[1], 2);
for (j = 2; j < padding_len - 1; j++) {
decrypt_good &= ~constant_time_is_zero_8(rsa_decrypt[j]);
}
decrypt_good &= constant_time_is_zero_8(rsa_decrypt[padding_len - 1]);
version_good =
constant_time_eq_8(rsa_decrypt[padding_len],
(unsigned)(s->client_version >> 8));
version_good &=
constant_time_eq_8(rsa_decrypt[padding_len + 1],
(unsigned)(s->client_version & 0xff));
if (s->options & SSL_OP_TLS_ROLLBACK_BUG) {
unsigned char workaround_good;
workaround_good = constant_time_eq_8(rsa_decrypt[padding_len],
(unsigned)(s->version >> 8));
workaround_good &=
constant_time_eq_8(rsa_decrypt[padding_len + 1],
(unsigned)(s->version & 0xff));
version_good |= workaround_good;
}
decrypt_good &= version_good;
for (j = 0; j < sizeof(rand_premaster_secret); j++) {
rsa_decrypt[padding_len + j] =
constant_time_select_8(decrypt_good,
rsa_decrypt[padding_len + j],
rand_premaster_secret[j]);
}
if (!ssl_generate_master_secret(s, rsa_decrypt + padding_len,
sizeof(rand_premaster_secret), 0)) {
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CKE_RSA, ERR_R_INTERNAL_ERROR);
goto err;
}
ret = 1;
err:
OPENSSL_free(rsa_decrypt);
return ret;
#else
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CKE_RSA, ERR_R_INTERNAL_ERROR);
return 0;
#endif
}
static int tls_process_cke_dhe(SSL *s, PACKET *pkt, int *al)
{
#ifndef OPENSSL_NO_DH
EVP_PKEY *skey = NULL;
DH *cdh;
unsigned int i;
BIGNUM *pub_key;
const unsigned char *data;
EVP_PKEY *ckey = NULL;
int ret = 0;
if (!PACKET_get_net_2(pkt, &i) || PACKET_remaining(pkt) != i) {
*al = SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_TLS_PROCESS_CKE_DHE,
SSL_R_DH_PUBLIC_VALUE_LENGTH_IS_WRONG);
goto err;
}
skey = s->s3->tmp.pkey;
if (skey == NULL) {
*al = SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_TLS_PROCESS_CKE_DHE, SSL_R_MISSING_TMP_DH_KEY);
goto err;
}
if (PACKET_remaining(pkt) == 0L) {
*al = SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_TLS_PROCESS_CKE_DHE, SSL_R_MISSING_TMP_DH_KEY);
goto err;
}
if (!PACKET_get_bytes(pkt, &data, i)) {
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CKE_DHE, ERR_R_INTERNAL_ERROR);
goto err;
}
ckey = EVP_PKEY_new();
if (ckey == NULL || EVP_PKEY_copy_parameters(ckey, skey) == 0) {
SSLerr(SSL_F_TLS_PROCESS_CKE_DHE, SSL_R_BN_LIB);
goto err;
}
cdh = EVP_PKEY_get0_DH(ckey);
pub_key = BN_bin2bn(data, i, NULL);
if (pub_key == NULL || !DH_set0_key(cdh, pub_key, NULL)) {
SSLerr(SSL_F_TLS_PROCESS_CKE_DHE, ERR_R_INTERNAL_ERROR);
if (pub_key != NULL)
BN_free(pub_key);
goto err;
}
if (ssl_derive(s, skey, ckey) == 0) {
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CKE_DHE, ERR_R_INTERNAL_ERROR);
goto err;
}
ret = 1;
EVP_PKEY_free(s->s3->tmp.pkey);
s->s3->tmp.pkey = NULL;
err:
EVP_PKEY_free(ckey);
return ret;
#else
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CKE_DHE, ERR_R_INTERNAL_ERROR);
return 0;
#endif
}
static int tls_process_cke_ecdhe(SSL *s, PACKET *pkt, int *al)
{
#ifndef OPENSSL_NO_EC
EVP_PKEY *skey = s->s3->tmp.pkey;
EVP_PKEY *ckey = NULL;
int ret = 0;
if (PACKET_remaining(pkt) == 0L) {
*al = SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_TLS_PROCESS_CKE_ECDHE, SSL_R_MISSING_TMP_ECDH_KEY);
goto err;
} else {
unsigned int i;
const unsigned char *data;
if (!PACKET_get_1(pkt, &i) || !PACKET_get_bytes(pkt, &data, i)
|| PACKET_remaining(pkt) != 0) {
*al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CKE_ECDHE, SSL_R_LENGTH_MISMATCH);
goto err;
}
ckey = EVP_PKEY_new();
if (ckey == NULL || EVP_PKEY_copy_parameters(ckey, skey) <= 0) {
SSLerr(SSL_F_TLS_PROCESS_CKE_ECDHE, ERR_R_EVP_LIB);
goto err;
}
if (EVP_PKEY_set1_tls_encodedpoint(ckey, data, i) == 0) {
*al = SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_TLS_PROCESS_CKE_ECDHE, ERR_R_EC_LIB);
goto err;
}
}
if (ssl_derive(s, skey, ckey) == 0) {
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CKE_ECDHE, ERR_R_INTERNAL_ERROR);
goto err;
}
ret = 1;
EVP_PKEY_free(s->s3->tmp.pkey);
s->s3->tmp.pkey = NULL;
err:
EVP_PKEY_free(ckey);
return ret;
#else
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CKE_ECDHE, ERR_R_INTERNAL_ERROR);
return 0;
#endif
}
static int tls_process_cke_srp(SSL *s, PACKET *pkt, int *al)
{
#ifndef OPENSSL_NO_SRP
unsigned int i;
const unsigned char *data;
if (!PACKET_get_net_2(pkt, &i)
|| !PACKET_get_bytes(pkt, &data, i)) {
*al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CKE_SRP, SSL_R_BAD_SRP_A_LENGTH);
return 0;
}
if ((s->srp_ctx.A = BN_bin2bn(data, i, NULL)) == NULL) {
SSLerr(SSL_F_TLS_PROCESS_CKE_SRP, ERR_R_BN_LIB);
return 0;
}
if (BN_ucmp(s->srp_ctx.A, s->srp_ctx.N) >= 0 || BN_is_zero(s->srp_ctx.A)) {
*al = SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_TLS_PROCESS_CKE_SRP, SSL_R_BAD_SRP_PARAMETERS);
return 0;
}
OPENSSL_free(s->session->srp_username);
s->session->srp_username = OPENSSL_strdup(s->srp_ctx.login);
if (s->session->srp_username == NULL) {
SSLerr(SSL_F_TLS_PROCESS_CKE_SRP, ERR_R_MALLOC_FAILURE);
return 0;
}
if (!srp_generate_server_master_secret(s)) {
SSLerr(SSL_F_TLS_PROCESS_CKE_SRP, ERR_R_INTERNAL_ERROR);
return 0;
}
return 1;
#else
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CKE_SRP, ERR_R_INTERNAL_ERROR);
return 0;
#endif
}
static int tls_process_cke_gost(SSL *s, PACKET *pkt, int *al)
{
#ifndef OPENSSL_NO_GOST
EVP_PKEY_CTX *pkey_ctx;
EVP_PKEY *client_pub_pkey = NULL, *pk = NULL;
unsigned char premaster_secret[32];
const unsigned char *start;
size_t outlen = 32, inlen;
unsigned long alg_a;
int Ttag, Tclass;
long Tlen;
long sess_key_len;
const unsigned char *data;
int ret = 0;
alg_a = s->s3->tmp.new_cipher->algorithm_auth;
if (alg_a & SSL_aGOST12) {
pk = s->cert->pkeys[SSL_PKEY_GOST12_512].privatekey;
if (pk == NULL) {
pk = s->cert->pkeys[SSL_PKEY_GOST12_256].privatekey;
}
if (pk == NULL) {
pk = s->cert->pkeys[SSL_PKEY_GOST01].privatekey;
}
} else if (alg_a & SSL_aGOST01) {
pk = s->cert->pkeys[SSL_PKEY_GOST01].privatekey;
}
pkey_ctx = EVP_PKEY_CTX_new(pk, NULL);
if (pkey_ctx == NULL) {
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CKE_GOST, ERR_R_MALLOC_FAILURE);
return 0;
}
if (EVP_PKEY_decrypt_init(pkey_ctx) <= 0) {
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CKE_GOST, ERR_R_INTERNAL_ERROR);
return 0;
}
client_pub_pkey = X509_get0_pubkey(s->session->peer);
if (client_pub_pkey) {
if (EVP_PKEY_derive_set_peer(pkey_ctx, client_pub_pkey) <= 0)
ERR_clear_error();
}
sess_key_len = PACKET_remaining(pkt);
if (!PACKET_get_bytes(pkt, &data, sess_key_len)) {
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CKE_GOST, ERR_R_INTERNAL_ERROR);
goto err;
}
if (ASN1_get_object((const unsigned char **)&data, &Tlen, &Ttag,
&Tclass, sess_key_len) != V_ASN1_CONSTRUCTED
|| Ttag != V_ASN1_SEQUENCE || Tclass != V_ASN1_UNIVERSAL) {
*al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CKE_GOST, SSL_R_DECRYPTION_FAILED);
goto err;
}
start = data;
inlen = Tlen;
if (EVP_PKEY_decrypt
(pkey_ctx, premaster_secret, &outlen, start, inlen) <= 0) {
*al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CKE_GOST, SSL_R_DECRYPTION_FAILED);
goto err;
}
if (!ssl_generate_master_secret(s, premaster_secret,
sizeof(premaster_secret), 0)) {
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CKE_GOST, ERR_R_INTERNAL_ERROR);
goto err;
}
if (EVP_PKEY_CTX_ctrl
(pkey_ctx, -1, -1, EVP_PKEY_CTRL_PEER_KEY, 2, NULL) > 0)
s->statem.no_cert_verify = 1;
ret = 1;
err:
EVP_PKEY_CTX_free(pkey_ctx);
return ret;
#else
*al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CKE_GOST, ERR_R_INTERNAL_ERROR);
return 0;
#endif
}
MSG_PROCESS_RETURN tls_process_client_key_exchange(SSL *s, PACKET *pkt)
{
int al = -1;
unsigned long alg_k;
alg_k = s->s3->tmp.new_cipher->algorithm_mkey;
if ((alg_k & SSL_PSK) && !tls_process_cke_psk_preamble(s, pkt, &al))
goto err;
if (alg_k & SSL_kPSK) {
if (PACKET_remaining(pkt) != 0) {
al = SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_TLS_PROCESS_CLIENT_KEY_EXCHANGE,
SSL_R_LENGTH_MISMATCH);
goto err;
}
if (!ssl_generate_master_secret(s, NULL, 0, 0)) {
al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CLIENT_KEY_EXCHANGE, ERR_R_INTERNAL_ERROR);
goto err;
}
} else if (alg_k & (SSL_kRSA | SSL_kRSAPSK)) {
if (!tls_process_cke_rsa(s, pkt, &al))
goto err;
} else if (alg_k & (SSL_kDHE | SSL_kDHEPSK)) {
if (!tls_process_cke_dhe(s, pkt, &al))
goto err;
} else if (alg_k & (SSL_kECDHE | SSL_kECDHEPSK)) {
if (!tls_process_cke_ecdhe(s, pkt, &al))
goto err;
} else if (alg_k & SSL_kSRP) {
if (!tls_process_cke_srp(s, pkt, &al))
goto err;
} else if (alg_k & SSL_kGOST) {
if (!tls_process_cke_gost(s, pkt, &al))
goto err;
} else {
al = SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_TLS_PROCESS_CLIENT_KEY_EXCHANGE,
SSL_R_UNKNOWN_CIPHER_TYPE);
goto err;
}
return MSG_PROCESS_CONTINUE_PROCESSING;
err:
if (al != -1)
ssl3_send_alert(s, SSL3_AL_FATAL, al);
#ifndef OPENSSL_NO_PSK
OPENSSL_clear_free(s->s3->tmp.psk, s->s3->tmp.psklen);
s->s3->tmp.psk = NULL;
#endif
ossl_statem_set_error(s);
return MSG_PROCESS_ERROR;
}
WORK_STATE tls_post_process_client_key_exchange(SSL *s, WORK_STATE wst)
{
#ifndef OPENSSL_NO_SCTP
if (wst == WORK_MORE_A) {
if (SSL_IS_DTLS(s)) {
unsigned char sctpauthkey[64];
char labelbuffer[sizeof(DTLS1_SCTP_AUTH_LABEL)];
memcpy(labelbuffer, DTLS1_SCTP_AUTH_LABEL,
sizeof(DTLS1_SCTP_AUTH_LABEL));
if (SSL_export_keying_material(s, sctpauthkey,
sizeof(sctpauthkey), labelbuffer,
sizeof(labelbuffer), NULL, 0,
0) <= 0) {
ossl_statem_set_error(s);
return WORK_ERROR;;
}
BIO_ctrl(SSL_get_wbio(s), BIO_CTRL_DGRAM_SCTP_ADD_AUTH_KEY,
sizeof(sctpauthkey), sctpauthkey);
}
wst = WORK_MORE_B;
}
if ((wst == WORK_MORE_B)
&& BIO_dgram_is_sctp(SSL_get_wbio(s))
&& s->renegotiate
&& (s->session->peer == NULL || s->statem.no_cert_verify)
&& BIO_dgram_sctp_msg_waiting(SSL_get_rbio(s))) {
s->s3->in_read_app_data = 2;
s->rwstate = SSL_READING;
BIO_clear_retry_flags(SSL_get_rbio(s));
BIO_set_retry_read(SSL_get_rbio(s));
ossl_statem_set_sctp_read_sock(s, 1);
return WORK_MORE_B;
} else {
ossl_statem_set_sctp_read_sock(s, 0);
}
#endif
if (s->statem.no_cert_verify || !s->session->peer) {
if (!ssl3_digest_cached_records(s, 0)) {
ossl_statem_set_error(s);
return WORK_ERROR;
}
return WORK_FINISHED_CONTINUE;
} else {
if (!s->s3->handshake_buffer) {
SSLerr(SSL_F_TLS_POST_PROCESS_CLIENT_KEY_EXCHANGE,
ERR_R_INTERNAL_ERROR);
ossl_statem_set_error(s);
return WORK_ERROR;
}
if (!ssl3_digest_cached_records(s, 1)) {
ossl_statem_set_error(s);
return WORK_ERROR;
}
}
return WORK_FINISHED_CONTINUE;
}
MSG_PROCESS_RETURN tls_process_cert_verify(SSL *s, PACKET *pkt)
{
EVP_PKEY *pkey = NULL;
const unsigned char *sig, *data;
#ifndef OPENSSL_NO_GOST
unsigned char *gost_data = NULL;
#endif
int al, ret = MSG_PROCESS_ERROR;
int type = 0, j;
unsigned int len;
X509 *peer;
const EVP_MD *md = NULL;
long hdatalen = 0;
void *hdata;
EVP_MD_CTX *mctx = EVP_MD_CTX_new();
if (mctx == NULL) {
SSLerr(SSL_F_TLS_PROCESS_CERT_VERIFY, ERR_R_MALLOC_FAILURE);
al = SSL_AD_INTERNAL_ERROR;
goto f_err;
}
peer = s->session->peer;
pkey = X509_get0_pubkey(peer);
type = X509_certificate_type(peer, pkey);
if (!(type & EVP_PKT_SIGN)) {
SSLerr(SSL_F_TLS_PROCESS_CERT_VERIFY,
SSL_R_SIGNATURE_FOR_NON_SIGNING_CERTIFICATE);
al = SSL_AD_ILLEGAL_PARAMETER;
goto f_err;
}
#ifndef OPENSSL_NO_GOST
if (PACKET_remaining(pkt) == 64
&& EVP_PKEY_id(pkey) == NID_id_GostR3410_2001) {
len = 64;
} else
#endif
{
if (SSL_USE_SIGALGS(s)) {
int rv;
if (!PACKET_get_bytes(pkt, &sig, 2)) {
al = SSL_AD_DECODE_ERROR;
goto f_err;
}
rv = tls12_check_peer_sigalg(&md, s, sig, pkey);
if (rv == -1) {
al = SSL_AD_INTERNAL_ERROR;
goto f_err;
} else if (rv == 0) {
al = SSL_AD_DECODE_ERROR;
goto f_err;
}
#ifdef SSL_DEBUG
fprintf(stderr, "USING TLSv1.2 HASH %s\n", EVP_MD_name(md));
#endif
} else {
int idx = ssl_cert_type(NULL, pkey);
if (idx >= 0)
md = s->s3->tmp.md[idx];
if (md == NULL) {
al = SSL_AD_INTERNAL_ERROR;
goto f_err;
}
}
if (!PACKET_get_net_2(pkt, &len)) {
SSLerr(SSL_F_TLS_PROCESS_CERT_VERIFY, SSL_R_LENGTH_MISMATCH);
al = SSL_AD_DECODE_ERROR;
goto f_err;
}
}
j = EVP_PKEY_size(pkey);
if (((int)len > j) || ((int)PACKET_remaining(pkt) > j)
|| (PACKET_remaining(pkt) == 0)) {
SSLerr(SSL_F_TLS_PROCESS_CERT_VERIFY, SSL_R_WRONG_SIGNATURE_SIZE);
al = SSL_AD_DECODE_ERROR;
goto f_err;
}
if (!PACKET_get_bytes(pkt, &data, len)) {
SSLerr(SSL_F_TLS_PROCESS_CERT_VERIFY, SSL_R_LENGTH_MISMATCH);
al = SSL_AD_DECODE_ERROR;
goto f_err;
}
hdatalen = BIO_get_mem_data(s->s3->handshake_buffer, &hdata);
if (hdatalen <= 0) {
SSLerr(SSL_F_TLS_PROCESS_CERT_VERIFY, ERR_R_INTERNAL_ERROR);
al = SSL_AD_INTERNAL_ERROR;
goto f_err;
}
#ifdef SSL_DEBUG
fprintf(stderr, "Using client verify alg %s\n", EVP_MD_name(md));
#endif
if (!EVP_VerifyInit_ex(mctx, md, NULL)
|| !EVP_VerifyUpdate(mctx, hdata, hdatalen)) {
SSLerr(SSL_F_TLS_PROCESS_CERT_VERIFY, ERR_R_EVP_LIB);
al = SSL_AD_INTERNAL_ERROR;
goto f_err;
}
#ifndef OPENSSL_NO_GOST
{
int pktype = EVP_PKEY_id(pkey);
if (pktype == NID_id_GostR3410_2001
|| pktype == NID_id_GostR3410_2012_256
|| pktype == NID_id_GostR3410_2012_512) {
if ((gost_data = OPENSSL_malloc(len)) == NULL) {
SSLerr(SSL_F_TLS_PROCESS_CERT_VERIFY, ERR_R_MALLOC_FAILURE);
al = SSL_AD_INTERNAL_ERROR;
goto f_err;
}
BUF_reverse(gost_data, data, len);
data = gost_data;
}
}
#endif
if (s->version == SSL3_VERSION
&& !EVP_MD_CTX_ctrl(mctx, EVP_CTRL_SSL3_MASTER_SECRET,
s->session->master_key_length,
s->session->master_key)) {
SSLerr(SSL_F_TLS_PROCESS_CERT_VERIFY, ERR_R_EVP_LIB);
al = SSL_AD_INTERNAL_ERROR;
goto f_err;
}
if (EVP_VerifyFinal(mctx, data, len, pkey) <= 0) {
al = SSL_AD_DECRYPT_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CERT_VERIFY, SSL_R_BAD_SIGNATURE);
goto f_err;
}
ret = MSG_PROCESS_CONTINUE_PROCESSING;
if (0) {
f_err:
ssl3_send_alert(s, SSL3_AL_FATAL, al);
ossl_statem_set_error(s);
}
BIO_free(s->s3->handshake_buffer);
s->s3->handshake_buffer = NULL;
EVP_MD_CTX_free(mctx);
#ifndef OPENSSL_NO_GOST
OPENSSL_free(gost_data);
#endif
return ret;
}
MSG_PROCESS_RETURN tls_process_client_certificate(SSL *s, PACKET *pkt)
{
int i, al = SSL_AD_INTERNAL_ERROR, ret = MSG_PROCESS_ERROR;
X509 *x = NULL;
unsigned long l, llen;
const unsigned char *certstart, *certbytes;
STACK_OF(X509) *sk = NULL;
PACKET spkt;
if ((sk = sk_X509_new_null()) == NULL) {
SSLerr(SSL_F_TLS_PROCESS_CLIENT_CERTIFICATE, ERR_R_MALLOC_FAILURE);
goto f_err;
}
if (!PACKET_get_net_3(pkt, &llen)
|| !PACKET_get_sub_packet(pkt, &spkt, llen)
|| PACKET_remaining(pkt) != 0) {
al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CLIENT_CERTIFICATE, SSL_R_LENGTH_MISMATCH);
goto f_err;
}
while (PACKET_remaining(&spkt) > 0) {
if (!PACKET_get_net_3(&spkt, &l)
|| !PACKET_get_bytes(&spkt, &certbytes, l)) {
al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CLIENT_CERTIFICATE,
SSL_R_CERT_LENGTH_MISMATCH);
goto f_err;
}
certstart = certbytes;
x = d2i_X509(NULL, (const unsigned char **)&certbytes, l);
if (x == NULL) {
SSLerr(SSL_F_TLS_PROCESS_CLIENT_CERTIFICATE, ERR_R_ASN1_LIB);
goto f_err;
}
if (certbytes != (certstart + l)) {
al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_TLS_PROCESS_CLIENT_CERTIFICATE,
SSL_R_CERT_LENGTH_MISMATCH);
goto f_err;
}
if (!sk_X509_push(sk, x)) {
SSLerr(SSL_F_TLS_PROCESS_CLIENT_CERTIFICATE, ERR_R_MALLOC_FAILURE);
goto f_err;
}
x = NULL;
}
if (sk_X509_num(sk) <= 0) {
if (s->version == SSL3_VERSION) {
al = SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_TLS_PROCESS_CLIENT_CERTIFICATE,
SSL_R_NO_CERTIFICATES_RETURNED);
goto f_err;
}
else if ((s->verify_mode & SSL_VERIFY_PEER) &&
(s->verify_mode & SSL_VERIFY_FAIL_IF_NO_PEER_CERT)) {
SSLerr(SSL_F_TLS_PROCESS_CLIENT_CERTIFICATE,
SSL_R_PEER_DID_NOT_RETURN_A_CERTIFICATE);
al = SSL_AD_HANDSHAKE_FAILURE;
goto f_err;
}
if (s->s3->handshake_buffer && !ssl3_digest_cached_records(s, 0)) {
goto f_err;
}
} else {
EVP_PKEY *pkey;
i = ssl_verify_cert_chain(s, sk);
if (i <= 0) {
al = ssl_verify_alarm_type(s->verify_result);
SSLerr(SSL_F_TLS_PROCESS_CLIENT_CERTIFICATE,
SSL_R_CERTIFICATE_VERIFY_FAILED);
goto f_err;
}
if (i > 1) {
SSLerr(SSL_F_TLS_PROCESS_CLIENT_CERTIFICATE, i);
al = SSL_AD_HANDSHAKE_FAILURE;
goto f_err;
}
pkey = X509_get0_pubkey(sk_X509_value(sk, 0));
if (pkey == NULL) {
al = SSL3_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_TLS_PROCESS_CLIENT_CERTIFICATE,
SSL_R_UNKNOWN_CERTIFICATE_TYPE);
goto f_err;
}
}
X509_free(s->session->peer);
s->session->peer = sk_X509_shift(sk);
s->session->verify_result = s->verify_result;
sk_X509_pop_free(s->session->peer_chain, X509_free);
s->session->peer_chain = sk;
sk = NULL;
ret = MSG_PROCESS_CONTINUE_READING;
goto done;
f_err:
ssl3_send_alert(s, SSL3_AL_FATAL, al);
ossl_statem_set_error(s);
done:
X509_free(x);
sk_X509_pop_free(sk, X509_free);
return ret;
}
int tls_construct_server_certificate(SSL *s)
{
CERT_PKEY *cpk;
cpk = ssl_get_server_send_pkey(s);
if (cpk == NULL) {
SSLerr(SSL_F_TLS_CONSTRUCT_SERVER_CERTIFICATE, ERR_R_INTERNAL_ERROR);
ossl_statem_set_error(s);
return 0;
}
if (!ssl3_output_cert_chain(s, cpk)) {
SSLerr(SSL_F_TLS_CONSTRUCT_SERVER_CERTIFICATE, ERR_R_INTERNAL_ERROR);
ossl_statem_set_error(s);
return 0;
}
return 1;
}
int tls_construct_new_session_ticket(SSL *s)
{
unsigned char *senc = NULL;
EVP_CIPHER_CTX *ctx;
HMAC_CTX *hctx = NULL;
unsigned char *p, *macstart;
const unsigned char *const_p;
int len, slen_full, slen;
SSL_SESSION *sess;
unsigned int hlen;
SSL_CTX *tctx = s->initial_ctx;
unsigned char iv[EVP_MAX_IV_LENGTH];
unsigned char key_name[TLSEXT_KEYNAME_LENGTH];
int iv_len;
slen_full = i2d_SSL_SESSION(s->session, NULL);
if (slen_full == 0 || slen_full > 0xFF00) {
ossl_statem_set_error(s);
return 0;
}
senc = OPENSSL_malloc(slen_full);
if (senc == NULL) {
ossl_statem_set_error(s);
return 0;
}
ctx = EVP_CIPHER_CTX_new();
hctx = HMAC_CTX_new();
p = senc;
if (!i2d_SSL_SESSION(s->session, &p))
goto err;
const_p = senc;
sess = d2i_SSL_SESSION(NULL, &const_p, slen_full);
if (sess == NULL)
goto err;
sess->session_id_length = 0;
slen = i2d_SSL_SESSION(sess, NULL);
if (slen == 0 || slen > slen_full) {
SSL_SESSION_free(sess);
goto err;
}
p = senc;
if (!i2d_SSL_SESSION(sess, &p)) {
SSL_SESSION_free(sess);
goto err;
}
SSL_SESSION_free(sess);
if (!BUF_MEM_grow(s->init_buf,
SSL_HM_HEADER_LENGTH(s) + 6 + sizeof(key_name) +
EVP_MAX_IV_LENGTH + EVP_MAX_BLOCK_LENGTH +
EVP_MAX_MD_SIZE + slen))
goto err;
p = ssl_handshake_start(s);
if (tctx->tlsext_ticket_key_cb) {
int ret = tctx->tlsext_ticket_key_cb(s, key_name, iv, ctx,
hctx, 1);
if (ret == 0) {
l2n(0, p);
s2n(0, p);
if (!ssl_set_handshake_header
(s, SSL3_MT_NEWSESSION_TICKET, p - ssl_handshake_start(s)))
goto err;
OPENSSL_free(senc);
EVP_CIPHER_CTX_free(ctx);
HMAC_CTX_free(hctx);
return 1;
}
if (ret < 0)
goto err;
iv_len = EVP_CIPHER_CTX_iv_length(ctx);
} else {
const EVP_CIPHER *cipher = EVP_aes_256_cbc();
iv_len = EVP_CIPHER_iv_length(cipher);
if (RAND_bytes(iv, iv_len) <= 0)
goto err;
if (!EVP_EncryptInit_ex(ctx, cipher, NULL,
tctx->tlsext_tick_aes_key, iv))
goto err;
if (!HMAC_Init_ex(hctx, tctx->tlsext_tick_hmac_key,
sizeof(tctx->tlsext_tick_hmac_key),
EVP_sha256(), NULL))
goto err;
memcpy(key_name, tctx->tlsext_tick_key_name,
sizeof(tctx->tlsext_tick_key_name));
}
l2n(s->hit ? 0 : s->session->timeout, p);
p += 2;
macstart = p;
memcpy(p, key_name, sizeof(key_name));
p += sizeof(key_name);
memcpy(p, iv, iv_len);
p += iv_len;
if (!EVP_EncryptUpdate(ctx, p, &len, senc, slen))
goto err;
p += len;
if (!EVP_EncryptFinal(ctx, p, &len))
goto err;
p += len;
if (!HMAC_Update(hctx, macstart, p - macstart))
goto err;
if (!HMAC_Final(hctx, p, &hlen))
goto err;
EVP_CIPHER_CTX_free(ctx);
HMAC_CTX_free(hctx);
ctx = NULL;
hctx = NULL;
p += hlen;
len = p - ssl_handshake_start(s);
p = ssl_handshake_start(s) + 4;
s2n(len - 6, p);
if (!ssl_set_handshake_header(s, SSL3_MT_NEWSESSION_TICKET, len))
goto err;
OPENSSL_free(senc);
return 1;
err:
OPENSSL_free(senc);
EVP_CIPHER_CTX_free(ctx);
HMAC_CTX_free(hctx);
ossl_statem_set_error(s);
return 0;
}
int tls_construct_cert_status(SSL *s)
{
unsigned char *p;
if (!BUF_MEM_grow(s->init_buf, 8 + s->tlsext_ocsp_resplen)) {
ossl_statem_set_error(s);
return 0;
}
p = (unsigned char *)s->init_buf->data;
*(p++) = SSL3_MT_CERTIFICATE_STATUS;
l2n3(s->tlsext_ocsp_resplen + 4, p);
*(p++) = s->tlsext_status_type;
l2n3(s->tlsext_ocsp_resplen, p);
memcpy(p, s->tlsext_ocsp_resp, s->tlsext_ocsp_resplen);
s->init_num = 8 + s->tlsext_ocsp_resplen;
s->init_off = 0;
return 1;
}
MSG_PROCESS_RETURN tls_process_next_proto(SSL *s, PACKET *pkt)
{
PACKET next_proto, padding;
size_t next_proto_len;
if (!PACKET_get_length_prefixed_1(pkt, &next_proto)
|| !PACKET_get_length_prefixed_1(pkt, &padding)
|| PACKET_remaining(pkt) > 0) {
SSLerr(SSL_F_TLS_PROCESS_NEXT_PROTO, SSL_R_LENGTH_MISMATCH);
goto err;
}
if (!PACKET_memdup(&next_proto, &s->next_proto_negotiated, &next_proto_len)) {
s->next_proto_negotiated_len = 0;
goto err;
}
s->next_proto_negotiated_len = (unsigned char)next_proto_len;
return MSG_PROCESS_CONTINUE_READING;
err:
ossl_statem_set_error(s);
return MSG_PROCESS_ERROR;
}
