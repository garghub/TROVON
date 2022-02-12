OSSL_HANDSHAKE_STATE SSL_get_state(const SSL *ssl)
{
return ssl->statem.hand_state;
}
int SSL_in_init(SSL *s)
{
return s->statem.in_init;
}
int SSL_is_init_finished(SSL *s)
{
return !(s->statem.in_init) && (s->statem.hand_state == TLS_ST_OK);
}
int SSL_in_before(SSL *s)
{
return (s->statem.hand_state == TLS_ST_BEFORE)
&& (s->statem.state == MSG_FLOW_UNINITED);
}
void ossl_statem_clear(SSL *s)
{
s->statem.state = MSG_FLOW_UNINITED;
s->statem.hand_state = TLS_ST_BEFORE;
s->statem.in_init = 1;
s->statem.no_cert_verify = 0;
}
void ossl_statem_set_renegotiate(SSL *s)
{
s->statem.state = MSG_FLOW_RENEGOTIATE;
s->statem.in_init = 1;
}
void ossl_statem_set_error(SSL *s)
{
s->statem.state = MSG_FLOW_ERROR;
}
int ossl_statem_in_error(const SSL *s)
{
if (s->statem.state == MSG_FLOW_ERROR)
return 1;
return 0;
}
void ossl_statem_set_in_init(SSL *s, int init)
{
s->statem.in_init = init;
}
int ossl_statem_get_in_handshake(SSL *s)
{
return s->statem.in_handshake;
}
void ossl_statem_set_in_handshake(SSL *s, int inhand)
{
if (inhand)
s->statem.in_handshake++;
else
s->statem.in_handshake--;
}
void ossl_statem_set_hello_verify_done(SSL *s)
{
s->statem.state = MSG_FLOW_UNINITED;
s->statem.in_init = 1;
s->statem.hand_state = TLS_ST_SR_CLNT_HELLO;
}
int ossl_statem_connect(SSL *s)
{
return state_machine(s, 0);
}
int ossl_statem_accept(SSL *s)
{
return state_machine(s, 1);
}
static info_cb get_callback(SSL *s)
{
if (s->info_callback != NULL)
return s->info_callback;
else if (s->ctx->info_callback != NULL)
return s->ctx->info_callback;
return NULL;
}
static int state_machine(SSL *s, int server)
{
BUF_MEM *buf = NULL;
unsigned long Time = (unsigned long)time(NULL);
void (*cb) (const SSL *ssl, int type, int val) = NULL;
OSSL_STATEM *st = &s->statem;
int ret = -1;
int ssret;
if (st->state == MSG_FLOW_ERROR) {
return -1;
}
RAND_add(&Time, sizeof(Time), 0);
ERR_clear_error();
clear_sys_error();
cb = get_callback(s);
st->in_handshake++;
if (!SSL_in_init(s) || SSL_in_before(s)) {
if (!SSL_clear(s))
return -1;
}
#ifndef OPENSSL_NO_SCTP
if (SSL_IS_DTLS(s)) {
BIO_ctrl(SSL_get_wbio(s), BIO_CTRL_DGRAM_SCTP_SET_IN_HANDSHAKE,
st->in_handshake, NULL);
}
#endif
#ifndef OPENSSL_NO_HEARTBEATS
if (s->tlsext_hb_pending) {
if (SSL_IS_DTLS(s))
dtls1_stop_timer(s);
s->tlsext_hb_pending = 0;
s->tlsext_hb_seq++;
}
#endif
if (st->state == MSG_FLOW_RENEGOTIATE) {
s->renegotiate = 1;
if (!server)
s->ctx->stats.sess_connect_renegotiate++;
}
if (st->state == MSG_FLOW_UNINITED || st->state == MSG_FLOW_RENEGOTIATE) {
if (st->state == MSG_FLOW_UNINITED) {
st->hand_state = TLS_ST_BEFORE;
}
s->server = server;
if (cb != NULL)
cb(s, SSL_CB_HANDSHAKE_START, 1);
if (SSL_IS_DTLS(s)) {
if ((s->version & 0xff00) != (DTLS1_VERSION & 0xff00) &&
(server || (s->version & 0xff00) != (DTLS1_BAD_VER & 0xff00))) {
SSLerr(SSL_F_STATE_MACHINE, ERR_R_INTERNAL_ERROR);
goto end;
}
} else {
if ((s->version >> 8) != SSL3_VERSION_MAJOR) {
SSLerr(SSL_F_STATE_MACHINE, ERR_R_INTERNAL_ERROR);
goto end;
}
}
if (!ssl_security(s, SSL_SECOP_VERSION, 0, s->version, NULL)) {
SSLerr(SSL_F_STATE_MACHINE, SSL_R_VERSION_TOO_LOW);
goto end;
}
if (s->init_buf == NULL) {
if ((buf = BUF_MEM_new()) == NULL) {
goto end;
}
if (!BUF_MEM_grow(buf, SSL3_RT_MAX_PLAIN_LENGTH)) {
goto end;
}
s->init_buf = buf;
buf = NULL;
}
if (!ssl3_setup_buffers(s)) {
goto end;
}
s->init_num = 0;
s->s3->change_cipher_spec = 0;
#ifndef OPENSSL_NO_SCTP
if (!SSL_IS_DTLS(s) || !BIO_dgram_is_sctp(SSL_get_wbio(s)))
#endif
if (!ssl_init_wbio_buffer(s)) {
goto end;
}
if (!server || st->state != MSG_FLOW_RENEGOTIATE) {
if (!ssl3_init_finished_mac(s)) {
ossl_statem_set_error(s);
goto end;
}
}
if (server) {
if (st->state != MSG_FLOW_RENEGOTIATE) {
s->ctx->stats.sess_accept++;
} else if (!s->s3->send_connection_binding &&
!(s->options &
SSL_OP_ALLOW_UNSAFE_LEGACY_RENEGOTIATION)) {
SSLerr(SSL_F_STATE_MACHINE,
SSL_R_UNSAFE_LEGACY_RENEGOTIATION_DISABLED);
ssl3_send_alert(s, SSL3_AL_FATAL, SSL_AD_HANDSHAKE_FAILURE);
ossl_statem_set_error(s);
goto end;
} else {
s->ctx->stats.sess_accept_renegotiate++;
}
} else {
s->ctx->stats.sess_connect++;
memset(s->s3->client_random, 0, sizeof(s->s3->client_random));
s->hit = 0;
s->s3->tmp.cert_request = 0;
if (SSL_IS_DTLS(s)) {
st->use_timer = 1;
}
}
st->state = MSG_FLOW_WRITING;
init_write_state_machine(s);
st->read_state_first_init = 1;
}
while (st->state != MSG_FLOW_FINISHED) {
if (st->state == MSG_FLOW_READING) {
ssret = read_state_machine(s);
if (ssret == SUB_STATE_FINISHED) {
st->state = MSG_FLOW_WRITING;
init_write_state_machine(s);
} else {
goto end;
}
} else if (st->state == MSG_FLOW_WRITING) {
ssret = write_state_machine(s);
if (ssret == SUB_STATE_FINISHED) {
st->state = MSG_FLOW_READING;
init_read_state_machine(s);
} else if (ssret == SUB_STATE_END_HANDSHAKE) {
st->state = MSG_FLOW_FINISHED;
} else {
goto end;
}
} else {
ossl_statem_set_error(s);
goto end;
}
}
st->state = MSG_FLOW_UNINITED;
ret = 1;
end:
st->in_handshake--;
#ifndef OPENSSL_NO_SCTP
if (SSL_IS_DTLS(s)) {
BIO_ctrl(SSL_get_wbio(s), BIO_CTRL_DGRAM_SCTP_SET_IN_HANDSHAKE,
st->in_handshake, NULL);
}
#endif
BUF_MEM_free(buf);
if (cb != NULL) {
if (server)
cb(s, SSL_CB_ACCEPT_EXIT, ret);
else
cb(s, SSL_CB_CONNECT_EXIT, ret);
}
return ret;
}
static void init_read_state_machine(SSL *s)
{
OSSL_STATEM *st = &s->statem;
st->read_state = READ_STATE_HEADER;
}
static SUB_STATE_RETURN read_state_machine(SSL *s)
{
OSSL_STATEM *st = &s->statem;
int ret, mt;
unsigned long len = 0;
int (*transition) (SSL *s, int mt);
PACKET pkt;
MSG_PROCESS_RETURN(*process_message) (SSL *s, PACKET *pkt);
WORK_STATE(*post_process_message) (SSL *s, WORK_STATE wst);
unsigned long (*max_message_size) (SSL *s);
void (*cb) (const SSL *ssl, int type, int val) = NULL;
cb = get_callback(s);
if (s->server) {
transition = ossl_statem_server_read_transition;
process_message = ossl_statem_server_process_message;
max_message_size = ossl_statem_server_max_message_size;
post_process_message = ossl_statem_server_post_process_message;
} else {
transition = ossl_statem_client_read_transition;
process_message = ossl_statem_client_process_message;
max_message_size = ossl_statem_client_max_message_size;
post_process_message = ossl_statem_client_post_process_message;
}
if (st->read_state_first_init) {
s->first_packet = 1;
st->read_state_first_init = 0;
}
while (1) {
switch (st->read_state) {
case READ_STATE_HEADER:
if (SSL_IS_DTLS(s)) {
ret = dtls_get_message(s, &mt, &len);
} else {
ret = tls_get_message_header(s, &mt);
}
if (ret == 0) {
return SUB_STATE_ERROR;
}
if (cb != NULL) {
if (s->server)
cb(s, SSL_CB_ACCEPT_LOOP, 1);
else
cb(s, SSL_CB_CONNECT_LOOP, 1);
}
if (!transition(s, mt)) {
ossl_statem_set_error(s);
return SUB_STATE_ERROR;
}
if (s->s3->tmp.message_size > max_message_size(s)) {
ssl3_send_alert(s, SSL3_AL_FATAL, SSL_AD_ILLEGAL_PARAMETER);
SSLerr(SSL_F_READ_STATE_MACHINE, SSL_R_EXCESSIVE_MESSAGE_SIZE);
return SUB_STATE_ERROR;
}
st->read_state = READ_STATE_BODY;
case READ_STATE_BODY:
if (!SSL_IS_DTLS(s)) {
ret = tls_get_message_body(s, &len);
if (ret == 0) {
return SUB_STATE_ERROR;
}
}
s->first_packet = 0;
if (!PACKET_buf_init(&pkt, s->init_msg, len)) {
ssl3_send_alert(s, SSL3_AL_FATAL, SSL_AD_INTERNAL_ERROR);
SSLerr(SSL_F_READ_STATE_MACHINE, ERR_R_INTERNAL_ERROR);
return SUB_STATE_ERROR;
}
ret = process_message(s, &pkt);
s->init_num = 0;
if (ret == MSG_PROCESS_ERROR) {
return SUB_STATE_ERROR;
}
if (ret == MSG_PROCESS_FINISHED_READING) {
if (SSL_IS_DTLS(s)) {
dtls1_stop_timer(s);
}
return SUB_STATE_FINISHED;
}
if (ret == MSG_PROCESS_CONTINUE_PROCESSING) {
st->read_state = READ_STATE_POST_PROCESS;
st->read_state_work = WORK_MORE_A;
} else {
st->read_state = READ_STATE_HEADER;
}
break;
case READ_STATE_POST_PROCESS:
st->read_state_work = post_process_message(s, st->read_state_work);
switch (st->read_state_work) {
default:
return SUB_STATE_ERROR;
case WORK_FINISHED_CONTINUE:
st->read_state = READ_STATE_HEADER;
break;
case WORK_FINISHED_STOP:
if (SSL_IS_DTLS(s)) {
dtls1_stop_timer(s);
}
return SUB_STATE_FINISHED;
}
break;
default:
ssl3_send_alert(s, SSL3_AL_FATAL, SSL_AD_INTERNAL_ERROR);
SSLerr(SSL_F_READ_STATE_MACHINE, ERR_R_INTERNAL_ERROR);
ossl_statem_set_error(s);
return SUB_STATE_ERROR;
}
}
}
static int statem_do_write(SSL *s)
{
OSSL_STATEM *st = &s->statem;
if (st->hand_state == TLS_ST_CW_CHANGE
|| st->hand_state == TLS_ST_SW_CHANGE) {
if (SSL_IS_DTLS(s))
return dtls1_do_write(s, SSL3_RT_CHANGE_CIPHER_SPEC);
else
return ssl3_do_write(s, SSL3_RT_CHANGE_CIPHER_SPEC);
} else {
return ssl_do_write(s);
}
}
static void init_write_state_machine(SSL *s)
{
OSSL_STATEM *st = &s->statem;
st->write_state = WRITE_STATE_TRANSITION;
}
static SUB_STATE_RETURN write_state_machine(SSL *s)
{
OSSL_STATEM *st = &s->statem;
int ret;
WRITE_TRAN(*transition) (SSL *s);
WORK_STATE(*pre_work) (SSL *s, WORK_STATE wst);
WORK_STATE(*post_work) (SSL *s, WORK_STATE wst);
int (*construct_message) (SSL *s);
void (*cb) (const SSL *ssl, int type, int val) = NULL;
cb = get_callback(s);
if (s->server) {
transition = ossl_statem_server_write_transition;
pre_work = ossl_statem_server_pre_work;
post_work = ossl_statem_server_post_work;
construct_message = ossl_statem_server_construct_message;
} else {
transition = ossl_statem_client_write_transition;
pre_work = ossl_statem_client_pre_work;
post_work = ossl_statem_client_post_work;
construct_message = ossl_statem_client_construct_message;
}
while (1) {
switch (st->write_state) {
case WRITE_STATE_TRANSITION:
if (cb != NULL) {
if (s->server)
cb(s, SSL_CB_ACCEPT_LOOP, 1);
else
cb(s, SSL_CB_CONNECT_LOOP, 1);
}
switch (transition(s)) {
case WRITE_TRAN_CONTINUE:
st->write_state = WRITE_STATE_PRE_WORK;
st->write_state_work = WORK_MORE_A;
break;
case WRITE_TRAN_FINISHED:
return SUB_STATE_FINISHED;
break;
default:
return SUB_STATE_ERROR;
}
break;
case WRITE_STATE_PRE_WORK:
switch (st->write_state_work = pre_work(s, st->write_state_work)) {
default:
return SUB_STATE_ERROR;
case WORK_FINISHED_CONTINUE:
st->write_state = WRITE_STATE_SEND;
break;
case WORK_FINISHED_STOP:
return SUB_STATE_END_HANDSHAKE;
}
if (construct_message(s) == 0)
return SUB_STATE_ERROR;
case WRITE_STATE_SEND:
if (SSL_IS_DTLS(s) && st->use_timer) {
dtls1_start_timer(s);
}
ret = statem_do_write(s);
if (ret <= 0) {
return SUB_STATE_ERROR;
}
st->write_state = WRITE_STATE_POST_WORK;
st->write_state_work = WORK_MORE_A;
case WRITE_STATE_POST_WORK:
switch (st->write_state_work = post_work(s, st->write_state_work)) {
default:
return SUB_STATE_ERROR;
case WORK_FINISHED_CONTINUE:
st->write_state = WRITE_STATE_TRANSITION;
break;
case WORK_FINISHED_STOP:
return SUB_STATE_END_HANDSHAKE;
}
break;
default:
return SUB_STATE_ERROR;
}
}
}
int statem_flush(SSL *s)
{
s->rwstate = SSL_WRITING;
if (BIO_flush(s->wbio) <= 0) {
return 0;
}
s->rwstate = SSL_NOTHING;
return 1;
}
int ossl_statem_app_data_allowed(SSL *s)
{
OSSL_STATEM *st = &s->statem;
if (st->state == MSG_FLOW_UNINITED || st->state == MSG_FLOW_RENEGOTIATE)
return 0;
if (!s->s3->in_read_app_data || (s->s3->total_renegotiations == 0))
return 0;
if (s->server) {
if (st->hand_state == TLS_ST_BEFORE
|| st->hand_state == TLS_ST_SR_CLNT_HELLO)
return 1;
} else {
if (st->hand_state == TLS_ST_CW_CLNT_HELLO)
return 1;
}
return 0;
}
void ossl_statem_set_sctp_read_sock(SSL *s, int read_sock)
{
s->statem.in_sctp_read_sock = read_sock;
}
int ossl_statem_in_sctp_read_sock(SSL *s)
{
return s->statem.in_sctp_read_sock;
}
