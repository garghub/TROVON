static const SSL_METHOD *dtls1_get_client_method(int ver)
{
if (ver == DTLS1_VERSION || ver == DTLS1_BAD_VER)
return (DTLSv1_client_method());
else if (ver == DTLS1_2_VERSION)
return (DTLSv1_2_client_method());
else
return (NULL);
}
int dtls1_connect(SSL *s)
{
BUF_MEM *buf = NULL;
unsigned long Time = (unsigned long)time(NULL);
void (*cb) (const SSL *ssl, int type, int val) = NULL;
int ret = -1;
int new_state, state, skip = 0;
#ifndef OPENSSL_NO_SCTP
unsigned char sctpauthkey[64];
char labelbuffer[sizeof(DTLS1_SCTP_AUTH_LABEL)];
#endif
RAND_add(&Time, sizeof(Time), 0);
ERR_clear_error();
clear_sys_error();
if (s->info_callback != NULL)
cb = s->info_callback;
else if (s->ctx->info_callback != NULL)
cb = s->ctx->info_callback;
s->in_handshake++;
if (!SSL_in_init(s) || SSL_in_before(s))
SSL_clear(s);
#ifndef OPENSSL_NO_SCTP
BIO_ctrl(SSL_get_wbio(s), BIO_CTRL_DGRAM_SCTP_SET_IN_HANDSHAKE,
s->in_handshake, NULL);
#endif
#ifndef OPENSSL_NO_HEARTBEATS
if (s->tlsext_hb_pending) {
dtls1_stop_timer(s);
s->tlsext_hb_pending = 0;
s->tlsext_hb_seq++;
}
#endif
for (;;) {
state = s->state;
switch (s->state) {
case SSL_ST_RENEGOTIATE:
s->renegotiate = 1;
s->state = SSL_ST_CONNECT;
s->ctx->stats.sess_connect_renegotiate++;
case SSL_ST_BEFORE:
case SSL_ST_CONNECT:
case SSL_ST_BEFORE | SSL_ST_CONNECT:
case SSL_ST_OK | SSL_ST_CONNECT:
s->server = 0;
if (cb != NULL)
cb(s, SSL_CB_HANDSHAKE_START, 1);
if ((s->version & 0xff00) != (DTLS1_VERSION & 0xff00) &&
(s->version & 0xff00) != (DTLS1_BAD_VER & 0xff00)) {
SSLerr(SSL_F_DTLS1_CONNECT, ERR_R_INTERNAL_ERROR);
ret = -1;
goto end;
}
s->type = SSL_ST_CONNECT;
if (s->init_buf == NULL) {
if ((buf = BUF_MEM_new()) == NULL) {
ret = -1;
goto end;
}
if (!BUF_MEM_grow(buf, SSL3_RT_MAX_PLAIN_LENGTH)) {
ret = -1;
goto end;
}
s->init_buf = buf;
buf = NULL;
}
if (!ssl3_setup_buffers(s)) {
ret = -1;
goto end;
}
if (!ssl_init_wbio_buffer(s, 0)) {
ret = -1;
goto end;
}
s->state = SSL3_ST_CW_CLNT_HELLO_A;
s->ctx->stats.sess_connect++;
s->init_num = 0;
memset(s->s3->client_random, 0, sizeof(s->s3->client_random));
s->d1->send_cookie = 0;
s->hit = 0;
s->d1->change_cipher_spec_ok = 0;
s->s3->change_cipher_spec = 0;
break;
#ifndef OPENSSL_NO_SCTP
case DTLS1_SCTP_ST_CR_READ_SOCK:
if (BIO_dgram_sctp_msg_waiting(SSL_get_rbio(s))) {
s->s3->in_read_app_data = 2;
s->rwstate = SSL_READING;
BIO_clear_retry_flags(SSL_get_rbio(s));
BIO_set_retry_read(SSL_get_rbio(s));
ret = -1;
goto end;
}
s->state = s->s3->tmp.next_state;
break;
case DTLS1_SCTP_ST_CW_WRITE_SOCK:
ret = BIO_dgram_sctp_wait_for_dry(SSL_get_wbio(s));
if (ret < 0)
goto end;
if (ret == 0) {
s->s3->in_read_app_data = 2;
s->rwstate = SSL_READING;
BIO_clear_retry_flags(SSL_get_rbio(s));
BIO_set_retry_read(SSL_get_rbio(s));
ret = -1;
goto end;
}
s->state = s->d1->next_state;
break;
#endif
case SSL3_ST_CW_CLNT_HELLO_A:
case SSL3_ST_CW_CLNT_HELLO_B:
s->shutdown = 0;
ssl3_init_finished_mac(s);
dtls1_start_timer(s);
ret = ssl3_client_hello(s);
if (ret <= 0)
goto end;
if (s->d1->send_cookie) {
s->state = SSL3_ST_CW_FLUSH;
s->s3->tmp.next_state = SSL3_ST_CR_SRVR_HELLO_A;
} else
s->state = SSL3_ST_CR_SRVR_HELLO_A;
s->init_num = 0;
#ifndef OPENSSL_NO_SCTP
if (!BIO_dgram_is_sctp(SSL_get_wbio(s))) {
#endif
if (s->bbio != s->wbio)
s->wbio = BIO_push(s->bbio, s->wbio);
#ifndef OPENSSL_NO_SCTP
}
#endif
break;
case SSL3_ST_CR_SRVR_HELLO_A:
case SSL3_ST_CR_SRVR_HELLO_B:
ret = ssl3_get_server_hello(s);
if (ret <= 0)
goto end;
else {
if (s->hit) {
#ifndef OPENSSL_NO_SCTP
snprintf((char *)labelbuffer,
sizeof(DTLS1_SCTP_AUTH_LABEL),
DTLS1_SCTP_AUTH_LABEL);
SSL_export_keying_material(s, sctpauthkey,
sizeof(sctpauthkey),
labelbuffer,
sizeof(labelbuffer), NULL, 0,
0);
BIO_ctrl(SSL_get_wbio(s),
BIO_CTRL_DGRAM_SCTP_ADD_AUTH_KEY,
sizeof(sctpauthkey), sctpauthkey);
#endif
s->state = SSL3_ST_CR_FINISHED_A;
} else
s->state = DTLS1_ST_CR_HELLO_VERIFY_REQUEST_A;
}
s->init_num = 0;
break;
case DTLS1_ST_CR_HELLO_VERIFY_REQUEST_A:
case DTLS1_ST_CR_HELLO_VERIFY_REQUEST_B:
ret = dtls1_get_hello_verify(s);
if (ret <= 0)
goto end;
dtls1_stop_timer(s);
if (s->d1->send_cookie)
s->state = SSL3_ST_CW_CLNT_HELLO_A;
else
s->state = SSL3_ST_CR_CERT_A;
s->init_num = 0;
break;
case SSL3_ST_CR_CERT_A:
case SSL3_ST_CR_CERT_B:
if (!(s->s3->tmp.new_cipher->algorithm_auth & SSL_aNULL) &&
!(s->s3->tmp.new_cipher->algorithm_mkey & SSL_kPSK)) {
ret = ssl3_get_server_certificate(s);
if (ret <= 0)
goto end;
#ifndef OPENSSL_NO_TLSEXT
if (s->tlsext_status_expected)
s->state = SSL3_ST_CR_CERT_STATUS_A;
else
s->state = SSL3_ST_CR_KEY_EXCH_A;
} else {
skip = 1;
s->state = SSL3_ST_CR_KEY_EXCH_A;
}
#else
} else
skip = 1;
s->state = SSL3_ST_CR_KEY_EXCH_A;
#endif
s->init_num = 0;
break;
case SSL3_ST_CR_KEY_EXCH_A:
case SSL3_ST_CR_KEY_EXCH_B:
ret = ssl3_get_key_exchange(s);
if (ret <= 0)
goto end;
s->state = SSL3_ST_CR_CERT_REQ_A;
s->init_num = 0;
if (!ssl3_check_cert_and_algorithm(s)) {
ret = -1;
goto end;
}
break;
case SSL3_ST_CR_CERT_REQ_A:
case SSL3_ST_CR_CERT_REQ_B:
ret = ssl3_get_certificate_request(s);
if (ret <= 0)
goto end;
s->state = SSL3_ST_CR_SRVR_DONE_A;
s->init_num = 0;
break;
case SSL3_ST_CR_SRVR_DONE_A:
case SSL3_ST_CR_SRVR_DONE_B:
ret = ssl3_get_server_done(s);
if (ret <= 0)
goto end;
dtls1_stop_timer(s);
if (s->s3->tmp.cert_req)
s->s3->tmp.next_state = SSL3_ST_CW_CERT_A;
else
s->s3->tmp.next_state = SSL3_ST_CW_KEY_EXCH_A;
s->init_num = 0;
#ifndef OPENSSL_NO_SCTP
if (BIO_dgram_is_sctp(SSL_get_wbio(s)) &&
state == SSL_ST_RENEGOTIATE)
s->state = DTLS1_SCTP_ST_CR_READ_SOCK;
else
#endif
s->state = s->s3->tmp.next_state;
break;
case SSL3_ST_CW_CERT_A:
case SSL3_ST_CW_CERT_B:
case SSL3_ST_CW_CERT_C:
case SSL3_ST_CW_CERT_D:
dtls1_start_timer(s);
ret = ssl3_send_client_certificate(s);
if (ret <= 0)
goto end;
s->state = SSL3_ST_CW_KEY_EXCH_A;
s->init_num = 0;
break;
case SSL3_ST_CW_KEY_EXCH_A:
case SSL3_ST_CW_KEY_EXCH_B:
dtls1_start_timer(s);
ret = ssl3_send_client_key_exchange(s);
if (ret <= 0)
goto end;
#ifndef OPENSSL_NO_SCTP
snprintf((char *)labelbuffer, sizeof(DTLS1_SCTP_AUTH_LABEL),
DTLS1_SCTP_AUTH_LABEL);
SSL_export_keying_material(s, sctpauthkey,
sizeof(sctpauthkey), labelbuffer,
sizeof(labelbuffer), NULL, 0, 0);
BIO_ctrl(SSL_get_wbio(s), BIO_CTRL_DGRAM_SCTP_ADD_AUTH_KEY,
sizeof(sctpauthkey), sctpauthkey);
#endif
if (s->s3->tmp.cert_req == 1) {
s->state = SSL3_ST_CW_CERT_VRFY_A;
} else {
#ifndef OPENSSL_NO_SCTP
if (BIO_dgram_is_sctp(SSL_get_wbio(s))) {
s->d1->next_state = SSL3_ST_CW_CHANGE_A;
s->state = DTLS1_SCTP_ST_CW_WRITE_SOCK;
} else
#endif
s->state = SSL3_ST_CW_CHANGE_A;
}
s->init_num = 0;
break;
case SSL3_ST_CW_CERT_VRFY_A:
case SSL3_ST_CW_CERT_VRFY_B:
dtls1_start_timer(s);
ret = ssl3_send_client_verify(s);
if (ret <= 0)
goto end;
#ifndef OPENSSL_NO_SCTP
if (BIO_dgram_is_sctp(SSL_get_wbio(s))) {
s->d1->next_state = SSL3_ST_CW_CHANGE_A;
s->state = DTLS1_SCTP_ST_CW_WRITE_SOCK;
} else
#endif
s->state = SSL3_ST_CW_CHANGE_A;
s->init_num = 0;
break;
case SSL3_ST_CW_CHANGE_A:
case SSL3_ST_CW_CHANGE_B:
if (!s->hit)
dtls1_start_timer(s);
ret = dtls1_send_change_cipher_spec(s,
SSL3_ST_CW_CHANGE_A,
SSL3_ST_CW_CHANGE_B);
if (ret <= 0)
goto end;
s->state = SSL3_ST_CW_FINISHED_A;
s->init_num = 0;
s->session->cipher = s->s3->tmp.new_cipher;
#ifdef OPENSSL_NO_COMP
s->session->compress_meth = 0;
#else
if (s->s3->tmp.new_compression == NULL)
s->session->compress_meth = 0;
else
s->session->compress_meth = s->s3->tmp.new_compression->id;
#endif
if (!s->method->ssl3_enc->setup_key_block(s)) {
ret = -1;
goto end;
}
if (!s->method->ssl3_enc->change_cipher_state(s,
SSL3_CHANGE_CIPHER_CLIENT_WRITE))
{
ret = -1;
goto end;
}
#ifndef OPENSSL_NO_SCTP
if (s->hit) {
BIO_ctrl(SSL_get_wbio(s), BIO_CTRL_DGRAM_SCTP_NEXT_AUTH_KEY,
0, NULL);
}
#endif
dtls1_reset_seq_numbers(s, SSL3_CC_WRITE);
break;
case SSL3_ST_CW_FINISHED_A:
case SSL3_ST_CW_FINISHED_B:
if (!s->hit)
dtls1_start_timer(s);
ret = ssl3_send_finished(s,
SSL3_ST_CW_FINISHED_A,
SSL3_ST_CW_FINISHED_B,
s->method->
ssl3_enc->client_finished_label,
s->method->
ssl3_enc->client_finished_label_len);
if (ret <= 0)
goto end;
s->state = SSL3_ST_CW_FLUSH;
s->s3->flags &= ~SSL3_FLAGS_POP_BUFFER;
if (s->hit) {
s->s3->tmp.next_state = SSL_ST_OK;
#ifndef OPENSSL_NO_SCTP
if (BIO_dgram_is_sctp(SSL_get_wbio(s))) {
s->d1->next_state = s->s3->tmp.next_state;
s->s3->tmp.next_state = DTLS1_SCTP_ST_CW_WRITE_SOCK;
}
#endif
if (s->s3->flags & SSL3_FLAGS_DELAY_CLIENT_FINISHED) {
s->state = SSL_ST_OK;
#ifndef OPENSSL_NO_SCTP
if (BIO_dgram_is_sctp(SSL_get_wbio(s))) {
s->d1->next_state = SSL_ST_OK;
s->state = DTLS1_SCTP_ST_CW_WRITE_SOCK;
}
#endif
s->s3->flags |= SSL3_FLAGS_POP_BUFFER;
s->s3->delay_buf_pop_ret = 0;
}
} else {
#ifndef OPENSSL_NO_SCTP
BIO_ctrl(SSL_get_wbio(s), BIO_CTRL_DGRAM_SCTP_NEXT_AUTH_KEY,
0, NULL);
#endif
#ifndef OPENSSL_NO_TLSEXT
if (s->tlsext_ticket_expected)
s->s3->tmp.next_state = SSL3_ST_CR_SESSION_TICKET_A;
else
#endif
s->s3->tmp.next_state = SSL3_ST_CR_FINISHED_A;
}
s->init_num = 0;
break;
#ifndef OPENSSL_NO_TLSEXT
case SSL3_ST_CR_SESSION_TICKET_A:
case SSL3_ST_CR_SESSION_TICKET_B:
ret = ssl3_get_new_session_ticket(s);
if (ret <= 0)
goto end;
s->state = SSL3_ST_CR_FINISHED_A;
s->init_num = 0;
break;
case SSL3_ST_CR_CERT_STATUS_A:
case SSL3_ST_CR_CERT_STATUS_B:
ret = ssl3_get_cert_status(s);
if (ret <= 0)
goto end;
s->state = SSL3_ST_CR_KEY_EXCH_A;
s->init_num = 0;
break;
#endif
case SSL3_ST_CR_FINISHED_A:
case SSL3_ST_CR_FINISHED_B:
s->d1->change_cipher_spec_ok = 1;
ret = ssl3_get_finished(s, SSL3_ST_CR_FINISHED_A,
SSL3_ST_CR_FINISHED_B);
if (ret <= 0)
goto end;
dtls1_stop_timer(s);
if (s->hit)
s->state = SSL3_ST_CW_CHANGE_A;
else
s->state = SSL_ST_OK;
#ifndef OPENSSL_NO_SCTP
if (BIO_dgram_is_sctp(SSL_get_wbio(s)) &&
state == SSL_ST_RENEGOTIATE) {
s->d1->next_state = s->state;
s->state = DTLS1_SCTP_ST_CW_WRITE_SOCK;
}
#endif
s->init_num = 0;
break;
case SSL3_ST_CW_FLUSH:
s->rwstate = SSL_WRITING;
if (BIO_flush(s->wbio) <= 0) {
if (!BIO_should_retry(s->wbio)) {
s->rwstate = SSL_NOTHING;
s->state = s->s3->tmp.next_state;
}
ret = -1;
goto end;
}
s->rwstate = SSL_NOTHING;
s->state = s->s3->tmp.next_state;
break;
case SSL_ST_OK:
ssl3_cleanup_key_block(s);
#if 0
if (s->init_buf != NULL) {
BUF_MEM_free(s->init_buf);
s->init_buf = NULL;
}
#endif
if (!(s->s3->flags & SSL3_FLAGS_POP_BUFFER))
ssl_free_wbio_buffer(s);
s->init_num = 0;
s->renegotiate = 0;
s->new_session = 0;
ssl_update_cache(s, SSL_SESS_CACHE_CLIENT);
if (s->hit)
s->ctx->stats.sess_hit++;
ret = 1;
s->handshake_func = dtls1_connect;
s->ctx->stats.sess_connect_good++;
if (cb != NULL)
cb(s, SSL_CB_HANDSHAKE_DONE, 1);
s->d1->handshake_read_seq = 0;
s->d1->next_handshake_write_seq = 0;
goto end;
default:
SSLerr(SSL_F_DTLS1_CONNECT, SSL_R_UNKNOWN_STATE);
ret = -1;
goto end;
}
if (!s->s3->tmp.reuse_message && !skip) {
if (s->debug) {
if ((ret = BIO_flush(s->wbio)) <= 0)
goto end;
}
if ((cb != NULL) && (s->state != state)) {
new_state = s->state;
s->state = state;
cb(s, SSL_CB_CONNECT_LOOP, 1);
s->state = new_state;
}
}
skip = 0;
}
int dtls1_get_hello_verify(SSL *s)
{
int n, al, ok = 0;
unsigned char *data;
unsigned int cookie_len;
s->first_packet = 1;
n = s->method->ssl_get_message(s,
DTLS1_ST_CR_HELLO_VERIFY_REQUEST_A,
DTLS1_ST_CR_HELLO_VERIFY_REQUEST_B,
-1, s->max_cert_list, &ok);
s->first_packet = 0;
if (!ok)
return ((int)n);
if (s->s3->tmp.message_type != DTLS1_MT_HELLO_VERIFY_REQUEST) {
s->d1->send_cookie = 0;
s->s3->tmp.reuse_message = 1;
return (1);
}
data = (unsigned char *)s->init_msg;
#if 0
if (s->method->version != DTLS_ANY_VERSION &&
((data[0] != (s->version >> 8)) || (data[1] != (s->version & 0xff))))
{
SSLerr(SSL_F_DTLS1_GET_HELLO_VERIFY, SSL_R_WRONG_SSL_VERSION);
s->version = (s->version & 0xff00) | data[1];
al = SSL_AD_PROTOCOL_VERSION;
goto f_err;
}
#endif
data += 2;
cookie_len = *(data++);
if (cookie_len > sizeof(s->d1->cookie)) {
al = SSL_AD_ILLEGAL_PARAMETER;
goto f_err;
}
memcpy(s->d1->cookie, data, cookie_len);
s->d1->cookie_len = cookie_len;
s->d1->send_cookie = 1;
return 1;
f_err:
ssl3_send_alert(s, SSL3_AL_FATAL, al);
return -1;
}
