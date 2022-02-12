static const SSL_METHOD *dtls1_get_server_method(int ver)
{
if (ver == DTLS1_VERSION)
return(DTLSv1_server_method());
else
return(NULL);
}
int dtls1_accept(SSL *s)
{
BUF_MEM *buf;
unsigned long Time=(unsigned long)time(NULL);
void (*cb)(const SSL *ssl,int type,int val)=NULL;
unsigned long alg_k;
int ret= -1;
int new_state,state,skip=0;
RAND_add(&Time,sizeof(Time),0);
ERR_clear_error();
clear_sys_error();
if (s->info_callback != NULL)
cb=s->info_callback;
else if (s->ctx->info_callback != NULL)
cb=s->ctx->info_callback;
s->in_handshake++;
if (!SSL_in_init(s) || SSL_in_before(s)) SSL_clear(s);
if (s->cert == NULL)
{
SSLerr(SSL_F_DTLS1_ACCEPT,SSL_R_NO_CERTIFICATE_SET);
return(-1);
}
for (;;)
{
state=s->state;
switch (s->state)
{
case SSL_ST_RENEGOTIATE:
s->new_session=1;
case SSL_ST_BEFORE:
case SSL_ST_ACCEPT:
case SSL_ST_BEFORE|SSL_ST_ACCEPT:
case SSL_ST_OK|SSL_ST_ACCEPT:
s->server=1;
if (cb != NULL) cb(s,SSL_CB_HANDSHAKE_START,1);
if ((s->version & 0xff00) != (DTLS1_VERSION & 0xff00))
{
SSLerr(SSL_F_DTLS1_ACCEPT, ERR_R_INTERNAL_ERROR);
return -1;
}
s->type=SSL_ST_ACCEPT;
if (s->init_buf == NULL)
{
if ((buf=BUF_MEM_new()) == NULL)
{
ret= -1;
goto end;
}
if (!BUF_MEM_grow(buf,SSL3_RT_MAX_PLAIN_LENGTH))
{
ret= -1;
goto end;
}
s->init_buf=buf;
}
if (!ssl3_setup_buffers(s))
{
ret= -1;
goto end;
}
s->init_num=0;
if (s->state != SSL_ST_RENEGOTIATE)
{
if (!ssl_init_wbio_buffer(s,1)) { ret= -1; goto end; }
ssl3_init_finished_mac(s);
s->state=SSL3_ST_SR_CLNT_HELLO_A;
s->ctx->stats.sess_accept++;
}
else
{
s->ctx->stats.sess_accept_renegotiate++;
s->state=SSL3_ST_SW_HELLO_REQ_A;
}
break;
case SSL3_ST_SW_HELLO_REQ_A:
case SSL3_ST_SW_HELLO_REQ_B:
s->shutdown=0;
dtls1_start_timer(s);
ret=dtls1_send_hello_request(s);
if (ret <= 0) goto end;
s->s3->tmp.next_state=SSL3_ST_SW_HELLO_REQ_C;
s->state=SSL3_ST_SW_FLUSH;
s->init_num=0;
ssl3_init_finished_mac(s);
break;
case SSL3_ST_SW_HELLO_REQ_C:
s->state=SSL_ST_OK;
break;
case SSL3_ST_SR_CLNT_HELLO_A:
case SSL3_ST_SR_CLNT_HELLO_B:
case SSL3_ST_SR_CLNT_HELLO_C:
s->shutdown=0;
ret=ssl3_get_client_hello(s);
if (ret <= 0) goto end;
dtls1_stop_timer(s);
if (ret == 1 && (SSL_get_options(s) & SSL_OP_COOKIE_EXCHANGE))
s->state = DTLS1_ST_SW_HELLO_VERIFY_REQUEST_A;
else
s->state = SSL3_ST_SW_SRVR_HELLO_A;
s->init_num=0;
if (s->d1->listen && s->state == SSL3_ST_SW_SRVR_HELLO_A)
{
ret = 2;
s->d1->listen = 0;
goto end;
}
break;
case DTLS1_ST_SW_HELLO_VERIFY_REQUEST_A:
case DTLS1_ST_SW_HELLO_VERIFY_REQUEST_B:
dtls1_start_timer(s);
ret = dtls1_send_hello_verify_request(s);
if ( ret <= 0) goto end;
s->state=SSL3_ST_SW_FLUSH;
s->s3->tmp.next_state=SSL3_ST_SR_CLNT_HELLO_A;
if (s->version != DTLS1_BAD_VER)
ssl3_init_finished_mac(s);
break;
case SSL3_ST_SW_SRVR_HELLO_A:
case SSL3_ST_SW_SRVR_HELLO_B:
s->new_session = 2;
dtls1_start_timer(s);
ret=dtls1_send_server_hello(s);
if (ret <= 0) goto end;
#ifndef OPENSSL_NO_TLSEXT
if (s->hit)
{
if (s->tlsext_ticket_expected)
s->state=SSL3_ST_SW_SESSION_TICKET_A;
else
s->state=SSL3_ST_SW_CHANGE_A;
}
#else
if (s->hit)
s->state=SSL3_ST_SW_CHANGE_A;
#endif
else
s->state=SSL3_ST_SW_CERT_A;
s->init_num=0;
break;
case SSL3_ST_SW_CERT_A:
case SSL3_ST_SW_CERT_B:
if (!(s->s3->tmp.new_cipher->algorithm_auth & SSL_aNULL)
&& !(s->s3->tmp.new_cipher->algorithm_mkey & SSL_kPSK))
{
dtls1_start_timer(s);
ret=dtls1_send_server_certificate(s);
if (ret <= 0) goto end;
#ifndef OPENSSL_NO_TLSEXT
if (s->tlsext_status_expected)
s->state=SSL3_ST_SW_CERT_STATUS_A;
else
s->state=SSL3_ST_SW_KEY_EXCH_A;
}
else
{
skip = 1;
s->state=SSL3_ST_SW_KEY_EXCH_A;
}
#else
}
else
skip=1;
s->state=SSL3_ST_SW_KEY_EXCH_A;
#endif
s->init_num=0;
break;
case SSL3_ST_SW_KEY_EXCH_A:
case SSL3_ST_SW_KEY_EXCH_B:
alg_k = s->s3->tmp.new_cipher->algorithm_mkey;
if ((s->options & SSL_OP_EPHEMERAL_RSA)
#ifndef OPENSSL_NO_KRB5
&& !(alg_k & SSL_kKRB5)
#endif
)
s->s3->tmp.use_rsa_tmp=1;
else
s->s3->tmp.use_rsa_tmp=0;
if (s->s3->tmp.use_rsa_tmp
#ifndef OPENSSL_NO_PSK
|| ((alg_k & SSL_kPSK) && s->ctx->psk_identity_hint)
#endif
|| (alg_k & (SSL_kEDH|SSL_kDHr|SSL_kDHd))
|| (alg_k & SSL_kEECDH)
|| ((alg_k & SSL_kRSA)
&& (s->cert->pkeys[SSL_PKEY_RSA_ENC].privatekey == NULL
|| (SSL_C_IS_EXPORT(s->s3->tmp.new_cipher)
&& EVP_PKEY_size(s->cert->pkeys[SSL_PKEY_RSA_ENC].privatekey)*8 > SSL_C_EXPORT_PKEYLENGTH(s->s3->tmp.new_cipher)
)
)
)
)
{
dtls1_start_timer(s);
ret=dtls1_send_server_key_exchange(s);
if (ret <= 0) goto end;
}
else
skip=1;
s->state=SSL3_ST_SW_CERT_REQ_A;
s->init_num=0;
break;
case SSL3_ST_SW_CERT_REQ_A:
case SSL3_ST_SW_CERT_REQ_B:
if (
!(s->verify_mode & SSL_VERIFY_PEER) ||
((s->session->peer != NULL) &&
(s->verify_mode & SSL_VERIFY_CLIENT_ONCE)) ||
((s->s3->tmp.new_cipher->algorithm_auth & SSL_aNULL) &&
!(s->verify_mode & SSL_VERIFY_FAIL_IF_NO_PEER_CERT)) ||
(s->s3->tmp.new_cipher->algorithm_auth & SSL_aKRB5)
|| (s->s3->tmp.new_cipher->algorithm_mkey & SSL_kPSK))
{
skip=1;
s->s3->tmp.cert_request=0;
s->state=SSL3_ST_SW_SRVR_DONE_A;
}
else
{
s->s3->tmp.cert_request=1;
dtls1_start_timer(s);
ret=dtls1_send_certificate_request(s);
if (ret <= 0) goto end;
#ifndef NETSCAPE_HANG_BUG
s->state=SSL3_ST_SW_SRVR_DONE_A;
#else
s->state=SSL3_ST_SW_FLUSH;
s->s3->tmp.next_state=SSL3_ST_SR_CERT_A;
#endif
s->init_num=0;
}
break;
case SSL3_ST_SW_SRVR_DONE_A:
case SSL3_ST_SW_SRVR_DONE_B:
dtls1_start_timer(s);
ret=dtls1_send_server_done(s);
if (ret <= 0) goto end;
s->s3->tmp.next_state=SSL3_ST_SR_CERT_A;
s->state=SSL3_ST_SW_FLUSH;
s->init_num=0;
break;
case SSL3_ST_SW_FLUSH:
s->rwstate=SSL_WRITING;
if (BIO_flush(s->wbio) <= 0)
{
ret= -1;
goto end;
}
s->rwstate=SSL_NOTHING;
s->state=s->s3->tmp.next_state;
break;
case SSL3_ST_SR_CERT_A:
case SSL3_ST_SR_CERT_B:
ret = ssl3_check_client_hello(s);
if (ret <= 0)
goto end;
dtls1_stop_timer(s);
if (ret == 2)
s->state = SSL3_ST_SR_CLNT_HELLO_C;
else {
ret=ssl3_get_client_certificate(s);
if (ret <= 0) goto end;
dtls1_stop_timer(s);
s->init_num=0;
s->state=SSL3_ST_SR_KEY_EXCH_A;
}
break;
case SSL3_ST_SR_KEY_EXCH_A:
case SSL3_ST_SR_KEY_EXCH_B:
ret=ssl3_get_client_key_exchange(s);
if (ret <= 0) goto end;
dtls1_stop_timer(s);
s->state=SSL3_ST_SR_CERT_VRFY_A;
s->init_num=0;
if (ret == 2)
{
s->state=SSL3_ST_SR_FINISHED_A;
s->init_num = 0;
}
else
{
s->state=SSL3_ST_SR_CERT_VRFY_A;
s->init_num=0;
s->method->ssl3_enc->cert_verify_mac(s,
NID_md5,
&(s->s3->tmp.cert_verify_md[0]));
s->method->ssl3_enc->cert_verify_mac(s,
NID_sha1,
&(s->s3->tmp.cert_verify_md[MD5_DIGEST_LENGTH]));
}
break;
case SSL3_ST_SR_CERT_VRFY_A:
case SSL3_ST_SR_CERT_VRFY_B:
s->d1->change_cipher_spec_ok = 1;
ret=ssl3_get_cert_verify(s);
if (ret <= 0) goto end;
dtls1_stop_timer(s);
s->state=SSL3_ST_SR_FINISHED_A;
s->init_num=0;
break;
case SSL3_ST_SR_FINISHED_A:
case SSL3_ST_SR_FINISHED_B:
s->d1->change_cipher_spec_ok = 1;
ret=ssl3_get_finished(s,SSL3_ST_SR_FINISHED_A,
SSL3_ST_SR_FINISHED_B);
if (ret <= 0) goto end;
dtls1_stop_timer(s);
if (s->hit)
s->state=SSL_ST_OK;
#ifndef OPENSSL_NO_TLSEXT
else if (s->tlsext_ticket_expected)
s->state=SSL3_ST_SW_SESSION_TICKET_A;
#endif
else
s->state=SSL3_ST_SW_CHANGE_A;
s->init_num=0;
break;
#ifndef OPENSSL_NO_TLSEXT
case SSL3_ST_SW_SESSION_TICKET_A:
case SSL3_ST_SW_SESSION_TICKET_B:
ret=dtls1_send_newsession_ticket(s);
if (ret <= 0) goto end;
s->state=SSL3_ST_SW_CHANGE_A;
s->init_num=0;
break;
case SSL3_ST_SW_CERT_STATUS_A:
case SSL3_ST_SW_CERT_STATUS_B:
ret=ssl3_send_cert_status(s);
if (ret <= 0) goto end;
s->state=SSL3_ST_SW_KEY_EXCH_A;
s->init_num=0;
break;
#endif
case SSL3_ST_SW_CHANGE_A:
case SSL3_ST_SW_CHANGE_B:
s->session->cipher=s->s3->tmp.new_cipher;
if (!s->method->ssl3_enc->setup_key_block(s))
{ ret= -1; goto end; }
ret=dtls1_send_change_cipher_spec(s,
SSL3_ST_SW_CHANGE_A,SSL3_ST_SW_CHANGE_B);
if (ret <= 0) goto end;
s->state=SSL3_ST_SW_FINISHED_A;
s->init_num=0;
if (!s->method->ssl3_enc->change_cipher_state(s,
SSL3_CHANGE_CIPHER_SERVER_WRITE))
{
ret= -1;
goto end;
}
dtls1_reset_seq_numbers(s, SSL3_CC_WRITE);
break;
case SSL3_ST_SW_FINISHED_A:
case SSL3_ST_SW_FINISHED_B:
ret=dtls1_send_finished(s,
SSL3_ST_SW_FINISHED_A,SSL3_ST_SW_FINISHED_B,
s->method->ssl3_enc->server_finished_label,
s->method->ssl3_enc->server_finished_label_len);
if (ret <= 0) goto end;
s->state=SSL3_ST_SW_FLUSH;
if (s->hit)
s->s3->tmp.next_state=SSL3_ST_SR_FINISHED_A;
else
s->s3->tmp.next_state=SSL_ST_OK;
s->init_num=0;
break;
case SSL_ST_OK:
ssl3_cleanup_key_block(s);
#if 0
BUF_MEM_free(s->init_buf);
s->init_buf=NULL;
#endif
ssl_free_wbio_buffer(s);
s->init_num=0;
if (s->new_session == 2)
{
s->new_session=0;
ssl_update_cache(s,SSL_SESS_CACHE_SERVER);
s->ctx->stats.sess_accept_good++;
s->handshake_func=dtls1_accept;
if (cb != NULL) cb(s,SSL_CB_HANDSHAKE_DONE,1);
}
ret = 1;
s->d1->handshake_read_seq = 0;
s->d1->handshake_write_seq = 0;
s->d1->next_handshake_write_seq = 0;
goto end;
default:
SSLerr(SSL_F_DTLS1_ACCEPT,SSL_R_UNKNOWN_STATE);
ret= -1;
goto end;
}
if (!s->s3->tmp.reuse_message && !skip)
{
if (s->debug)
{
if ((ret=BIO_flush(s->wbio)) <= 0)
goto end;
}
if ((cb != NULL) && (s->state != state))
{
new_state=s->state;
s->state=state;
cb(s,SSL_CB_ACCEPT_LOOP,1);
s->state=new_state;
}
}
skip=0;
}
int dtls1_send_hello_verify_request(SSL *s)
{
unsigned int msg_len;
unsigned char *msg, *buf, *p;
if (s->state == DTLS1_ST_SW_HELLO_VERIFY_REQUEST_A)
{
buf = (unsigned char *)s->init_buf->data;
msg = p = &(buf[DTLS1_HM_HEADER_LENGTH]);
*(p++) = s->version >> 8;
*(p++) = s->version & 0xFF;
if (s->ctx->app_gen_cookie_cb == NULL ||
s->ctx->app_gen_cookie_cb(s, s->d1->cookie,
&(s->d1->cookie_len)) == 0)
{
SSLerr(SSL_F_DTLS1_SEND_HELLO_VERIFY_REQUEST,ERR_R_INTERNAL_ERROR);
return 0;
}
*(p++) = (unsigned char) s->d1->cookie_len;
memcpy(p, s->d1->cookie, s->d1->cookie_len);
p += s->d1->cookie_len;
msg_len = p - msg;
dtls1_set_message_header(s, buf,
DTLS1_MT_HELLO_VERIFY_REQUEST, msg_len, 0, msg_len);
s->state=DTLS1_ST_SW_HELLO_VERIFY_REQUEST_B;
s->init_num=p-buf;
s->init_off=0;
dtls1_buffer_message(s, 0);
}
return(dtls1_do_write(s,SSL3_RT_HANDSHAKE));
}
int dtls1_send_server_hello(SSL *s)
{
unsigned char *buf;
unsigned char *p,*d;
int i;
unsigned int sl;
unsigned long l,Time;
if (s->state == SSL3_ST_SW_SRVR_HELLO_A)
{
buf=(unsigned char *)s->init_buf->data;
p=s->s3->server_random;
Time=(unsigned long)time(NULL);
l2n(Time,p);
RAND_pseudo_bytes(p,SSL3_RANDOM_SIZE-sizeof(Time));
d=p= &(buf[DTLS1_HM_HEADER_LENGTH]);
*(p++)=s->version>>8;
*(p++)=s->version&0xff;
memcpy(p,s->s3->server_random,SSL3_RANDOM_SIZE);
p+=SSL3_RANDOM_SIZE;
if (!(s->ctx->session_cache_mode & SSL_SESS_CACHE_SERVER))
s->session->session_id_length=0;
sl=s->session->session_id_length;
if (sl > sizeof s->session->session_id)
{
SSLerr(SSL_F_DTLS1_SEND_SERVER_HELLO, ERR_R_INTERNAL_ERROR);
return -1;
}
*(p++)=sl;
memcpy(p,s->session->session_id,sl);
p+=sl;
if (s->s3->tmp.new_cipher == NULL)
return -1;
i=ssl3_put_cipher_by_char(s->s3->tmp.new_cipher,p);
p+=i;
#ifdef OPENSSL_NO_COMP
*(p++)=0;
#else
if (s->s3->tmp.new_compression == NULL)
*(p++)=0;
else
*(p++)=s->s3->tmp.new_compression->id;
#endif
#ifndef OPENSSL_NO_TLSEXT
if ((p = ssl_add_serverhello_tlsext(s, p, buf+SSL3_RT_MAX_PLAIN_LENGTH)) == NULL)
{
SSLerr(SSL_F_DTLS1_SEND_SERVER_HELLO,ERR_R_INTERNAL_ERROR);
return -1;
}
#endif
l=(p-d);
d=buf;
d = dtls1_set_message_header(s, d, SSL3_MT_SERVER_HELLO, l, 0, l);
s->state=SSL3_ST_SW_SRVR_HELLO_B;
s->init_num=p-buf;
s->init_off=0;
dtls1_buffer_message(s, 0);
}
return(dtls1_do_write(s,SSL3_RT_HANDSHAKE));
}
int dtls1_send_server_done(SSL *s)
{
unsigned char *p;
if (s->state == SSL3_ST_SW_SRVR_DONE_A)
{
p=(unsigned char *)s->init_buf->data;
p = dtls1_set_message_header(s, p, SSL3_MT_SERVER_DONE, 0, 0, 0);
s->state=SSL3_ST_SW_SRVR_DONE_B;
s->init_num=DTLS1_HM_HEADER_LENGTH;
s->init_off=0;
dtls1_buffer_message(s, 0);
}
return(dtls1_do_write(s,SSL3_RT_HANDSHAKE));
}
int dtls1_send_server_key_exchange(SSL *s)
{
#ifndef OPENSSL_NO_RSA
unsigned char *q;
int j,num;
RSA *rsa;
unsigned char md_buf[MD5_DIGEST_LENGTH+SHA_DIGEST_LENGTH];
unsigned int u;
#endif
#ifndef OPENSSL_NO_DH
DH *dh=NULL,*dhp;
#endif
#ifndef OPENSSL_NO_ECDH
EC_KEY *ecdh=NULL, *ecdhp;
unsigned char *encodedPoint = NULL;
int encodedlen = 0;
int curve_id = 0;
BN_CTX *bn_ctx = NULL;
#endif
EVP_PKEY *pkey;
unsigned char *p,*d;
int al,i;
unsigned long type;
int n;
CERT *cert;
BIGNUM *r[4];
int nr[4],kn;
BUF_MEM *buf;
EVP_MD_CTX md_ctx;
EVP_MD_CTX_init(&md_ctx);
if (s->state == SSL3_ST_SW_KEY_EXCH_A)
{
type=s->s3->tmp.new_cipher->algorithm_mkey;
cert=s->cert;
buf=s->init_buf;
r[0]=r[1]=r[2]=r[3]=NULL;
n=0;
#ifndef OPENSSL_NO_RSA
if (type & SSL_kRSA)
{
rsa=cert->rsa_tmp;
if ((rsa == NULL) && (s->cert->rsa_tmp_cb != NULL))
{
rsa=s->cert->rsa_tmp_cb(s,
SSL_C_IS_EXPORT(s->s3->tmp.new_cipher),
SSL_C_EXPORT_PKEYLENGTH(s->s3->tmp.new_cipher));
if(rsa == NULL)
{
al=SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_DTLS1_SEND_SERVER_KEY_EXCHANGE,SSL_R_ERROR_GENERATING_TMP_RSA_KEY);
goto f_err;
}
RSA_up_ref(rsa);
cert->rsa_tmp=rsa;
}
if (rsa == NULL)
{
al=SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_DTLS1_SEND_SERVER_KEY_EXCHANGE,SSL_R_MISSING_TMP_RSA_KEY);
goto f_err;
}
r[0]=rsa->n;
r[1]=rsa->e;
s->s3->tmp.use_rsa_tmp=1;
}
else
#endif
#ifndef OPENSSL_NO_DH
if (type & SSL_kEDH)
{
dhp=cert->dh_tmp;
if ((dhp == NULL) && (s->cert->dh_tmp_cb != NULL))
dhp=s->cert->dh_tmp_cb(s,
SSL_C_IS_EXPORT(s->s3->tmp.new_cipher),
SSL_C_EXPORT_PKEYLENGTH(s->s3->tmp.new_cipher));
if (dhp == NULL)
{
al=SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_DTLS1_SEND_SERVER_KEY_EXCHANGE,SSL_R_MISSING_TMP_DH_KEY);
goto f_err;
}
if (s->s3->tmp.dh != NULL)
{
DH_free(dh);
SSLerr(SSL_F_DTLS1_SEND_SERVER_KEY_EXCHANGE, ERR_R_INTERNAL_ERROR);
goto err;
}
if ((dh=DHparams_dup(dhp)) == NULL)
{
SSLerr(SSL_F_DTLS1_SEND_SERVER_KEY_EXCHANGE,ERR_R_DH_LIB);
goto err;
}
s->s3->tmp.dh=dh;
if ((dhp->pub_key == NULL ||
dhp->priv_key == NULL ||
(s->options & SSL_OP_SINGLE_DH_USE)))
{
if(!DH_generate_key(dh))
{
SSLerr(SSL_F_DTLS1_SEND_SERVER_KEY_EXCHANGE,
ERR_R_DH_LIB);
goto err;
}
}
else
{
dh->pub_key=BN_dup(dhp->pub_key);
dh->priv_key=BN_dup(dhp->priv_key);
if ((dh->pub_key == NULL) ||
(dh->priv_key == NULL))
{
SSLerr(SSL_F_DTLS1_SEND_SERVER_KEY_EXCHANGE,ERR_R_DH_LIB);
goto err;
}
}
r[0]=dh->p;
r[1]=dh->g;
r[2]=dh->pub_key;
}
else
#endif
#ifndef OPENSSL_NO_ECDH
if (type & SSL_kEECDH)
{
const EC_GROUP *group;
ecdhp=cert->ecdh_tmp;
if ((ecdhp == NULL) && (s->cert->ecdh_tmp_cb != NULL))
{
ecdhp=s->cert->ecdh_tmp_cb(s,
SSL_C_IS_EXPORT(s->s3->tmp.new_cipher),
SSL_C_EXPORT_PKEYLENGTH(s->s3->tmp.new_cipher));
}
if (ecdhp == NULL)
{
al=SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_DTLS1_SEND_SERVER_KEY_EXCHANGE,SSL_R_MISSING_TMP_ECDH_KEY);
goto f_err;
}
if (s->s3->tmp.ecdh != NULL)
{
EC_KEY_free(s->s3->tmp.ecdh);
SSLerr(SSL_F_DTLS1_SEND_SERVER_KEY_EXCHANGE, ERR_R_INTERNAL_ERROR);
goto err;
}
if (ecdhp == NULL)
{
SSLerr(SSL_F_DTLS1_SEND_SERVER_KEY_EXCHANGE,ERR_R_ECDH_LIB);
goto err;
}
if (!EC_KEY_up_ref(ecdhp))
{
SSLerr(SSL_F_DTLS1_SEND_SERVER_KEY_EXCHANGE,ERR_R_ECDH_LIB);
goto err;
}
ecdh = ecdhp;
s->s3->tmp.ecdh=ecdh;
if ((EC_KEY_get0_public_key(ecdh) == NULL) ||
(EC_KEY_get0_private_key(ecdh) == NULL) ||
(s->options & SSL_OP_SINGLE_ECDH_USE))
{
if(!EC_KEY_generate_key(ecdh))
{
SSLerr(SSL_F_DTLS1_SEND_SERVER_KEY_EXCHANGE,ERR_R_ECDH_LIB);
goto err;
}
}
if (((group = EC_KEY_get0_group(ecdh)) == NULL) ||
(EC_KEY_get0_public_key(ecdh) == NULL) ||
(EC_KEY_get0_private_key(ecdh) == NULL))
{
SSLerr(SSL_F_DTLS1_SEND_SERVER_KEY_EXCHANGE,ERR_R_ECDH_LIB);
goto err;
}
if (SSL_C_IS_EXPORT(s->s3->tmp.new_cipher) &&
(EC_GROUP_get_degree(group) > 163))
{
SSLerr(SSL_F_DTLS1_SEND_SERVER_KEY_EXCHANGE,SSL_R_ECGROUP_TOO_LARGE_FOR_CIPHER);
goto err;
}
if ((curve_id =
tls1_ec_nid2curve_id(EC_GROUP_get_curve_name(group)))
== 0)
{
SSLerr(SSL_F_DTLS1_SEND_SERVER_KEY_EXCHANGE,SSL_R_UNSUPPORTED_ELLIPTIC_CURVE);
goto err;
}
encodedlen = EC_POINT_point2oct(group,
EC_KEY_get0_public_key(ecdh),
POINT_CONVERSION_UNCOMPRESSED,
NULL, 0, NULL);
encodedPoint = (unsigned char *)
OPENSSL_malloc(encodedlen*sizeof(unsigned char));
bn_ctx = BN_CTX_new();
if ((encodedPoint == NULL) || (bn_ctx == NULL))
{
SSLerr(SSL_F_DTLS1_SEND_SERVER_KEY_EXCHANGE,ERR_R_MALLOC_FAILURE);
goto err;
}
encodedlen = EC_POINT_point2oct(group,
EC_KEY_get0_public_key(ecdh),
POINT_CONVERSION_UNCOMPRESSED,
encodedPoint, encodedlen, bn_ctx);
if (encodedlen == 0)
{
SSLerr(SSL_F_DTLS1_SEND_SERVER_KEY_EXCHANGE,ERR_R_ECDH_LIB);
goto err;
}
BN_CTX_free(bn_ctx); bn_ctx=NULL;
n = 4 + encodedlen;
r[0]=NULL;
r[1]=NULL;
r[2]=NULL;
r[3]=NULL;
}
else
#endif
#ifndef OPENSSL_NO_PSK
if (type & SSL_kPSK)
{
n+=2+strlen(s->ctx->psk_identity_hint);
}
else
#endif
{
al=SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_DTLS1_SEND_SERVER_KEY_EXCHANGE,SSL_R_UNKNOWN_KEY_EXCHANGE_TYPE);
goto f_err;
}
for (i=0; r[i] != NULL; i++)
{
nr[i]=BN_num_bytes(r[i]);
n+=2+nr[i];
}
if (!(s->s3->tmp.new_cipher->algorithm_auth & SSL_aNULL)
&& !(s->s3->tmp.new_cipher->algorithm_mkey & SSL_kPSK))
{
if ((pkey=ssl_get_sign_pkey(s,s->s3->tmp.new_cipher))
== NULL)
{
al=SSL_AD_DECODE_ERROR;
goto f_err;
}
kn=EVP_PKEY_size(pkey);
}
else
{
pkey=NULL;
kn=0;
}
if (!BUF_MEM_grow_clean(buf,n+DTLS1_HM_HEADER_LENGTH+kn))
{
SSLerr(SSL_F_DTLS1_SEND_SERVER_KEY_EXCHANGE,ERR_LIB_BUF);
goto err;
}
d=(unsigned char *)s->init_buf->data;
p= &(d[DTLS1_HM_HEADER_LENGTH]);
for (i=0; r[i] != NULL; i++)
{
s2n(nr[i],p);
BN_bn2bin(r[i],p);
p+=nr[i];
}
#ifndef OPENSSL_NO_ECDH
if (type & SSL_kEECDH)
{
*p = NAMED_CURVE_TYPE;
p += 1;
*p = 0;
p += 1;
*p = curve_id;
p += 1;
*p = encodedlen;
p += 1;
memcpy((unsigned char*)p,
(unsigned char *)encodedPoint,
encodedlen);
OPENSSL_free(encodedPoint);
p += encodedlen;
}
#endif
#ifndef OPENSSL_NO_PSK
if (type & SSL_kPSK)
{
s2n(strlen(s->ctx->psk_identity_hint), p);
strncpy((char *)p, s->ctx->psk_identity_hint, strlen(s->ctx->psk_identity_hint));
p+=strlen(s->ctx->psk_identity_hint);
}
#endif
if (pkey != NULL)
{
#ifndef OPENSSL_NO_RSA
if (pkey->type == EVP_PKEY_RSA)
{
q=md_buf;
j=0;
for (num=2; num > 0; num--)
{
EVP_DigestInit_ex(&md_ctx,(num == 2)
?s->ctx->md5:s->ctx->sha1, NULL);
EVP_DigestUpdate(&md_ctx,&(s->s3->client_random[0]),SSL3_RANDOM_SIZE);
EVP_DigestUpdate(&md_ctx,&(s->s3->server_random[0]),SSL3_RANDOM_SIZE);
EVP_DigestUpdate(&md_ctx,&(d[DTLS1_HM_HEADER_LENGTH]),n);
EVP_DigestFinal_ex(&md_ctx,q,
(unsigned int *)&i);
q+=i;
j+=i;
}
if (RSA_sign(NID_md5_sha1, md_buf, j,
&(p[2]), &u, pkey->pkey.rsa) <= 0)
{
SSLerr(SSL_F_DTLS1_SEND_SERVER_KEY_EXCHANGE,ERR_LIB_RSA);
goto err;
}
s2n(u,p);
n+=u+2;
}
else
#endif
#if !defined(OPENSSL_NO_DSA)
if (pkey->type == EVP_PKEY_DSA)
{
EVP_SignInit_ex(&md_ctx,EVP_dss1(), NULL);
EVP_SignUpdate(&md_ctx,&(s->s3->client_random[0]),SSL3_RANDOM_SIZE);
EVP_SignUpdate(&md_ctx,&(s->s3->server_random[0]),SSL3_RANDOM_SIZE);
EVP_SignUpdate(&md_ctx,&(d[DTLS1_HM_HEADER_LENGTH]),n);
if (!EVP_SignFinal(&md_ctx,&(p[2]),
(unsigned int *)&i,pkey))
{
SSLerr(SSL_F_DTLS1_SEND_SERVER_KEY_EXCHANGE,ERR_LIB_DSA);
goto err;
}
s2n(i,p);
n+=i+2;
}
else
#endif
#if !defined(OPENSSL_NO_ECDSA)
if (pkey->type == EVP_PKEY_EC)
{
EVP_SignInit_ex(&md_ctx,EVP_ecdsa(), NULL);
EVP_SignUpdate(&md_ctx,&(s->s3->client_random[0]),SSL3_RANDOM_SIZE);
EVP_SignUpdate(&md_ctx,&(s->s3->server_random[0]),SSL3_RANDOM_SIZE);
EVP_SignUpdate(&md_ctx,&(d[4]),n);
if (!EVP_SignFinal(&md_ctx,&(p[2]),
(unsigned int *)&i,pkey))
{
SSLerr(SSL_F_DTLS1_SEND_SERVER_KEY_EXCHANGE,ERR_LIB_ECDSA);
goto err;
}
s2n(i,p);
n+=i+2;
}
else
#endif
{
al=SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_DTLS1_SEND_SERVER_KEY_EXCHANGE,SSL_R_UNKNOWN_PKEY_TYPE);
goto f_err;
}
}
d = dtls1_set_message_header(s, d,
SSL3_MT_SERVER_KEY_EXCHANGE, n, 0, n);
s->init_num=n+DTLS1_HM_HEADER_LENGTH;
s->init_off=0;
dtls1_buffer_message(s, 0);
}
s->state = SSL3_ST_SW_KEY_EXCH_B;
EVP_MD_CTX_cleanup(&md_ctx);
return(dtls1_do_write(s,SSL3_RT_HANDSHAKE));
f_err:
ssl3_send_alert(s,SSL3_AL_FATAL,al);
err:
#ifndef OPENSSL_NO_ECDH
if (encodedPoint != NULL) OPENSSL_free(encodedPoint);
BN_CTX_free(bn_ctx);
#endif
EVP_MD_CTX_cleanup(&md_ctx);
return(-1);
}
int dtls1_send_certificate_request(SSL *s)
{
unsigned char *p,*d;
int i,j,nl,off,n;
STACK_OF(X509_NAME) *sk=NULL;
X509_NAME *name;
BUF_MEM *buf;
unsigned int msg_len;
if (s->state == SSL3_ST_SW_CERT_REQ_A)
{
buf=s->init_buf;
d=p=(unsigned char *)&(buf->data[DTLS1_HM_HEADER_LENGTH]);
p++;
n=ssl3_get_req_cert_type(s,p);
d[0]=n;
p+=n;
n++;
off=n;
p+=2;
n+=2;
sk=SSL_get_client_CA_list(s);
nl=0;
if (sk != NULL)
{
for (i=0; i<sk_X509_NAME_num(sk); i++)
{
name=sk_X509_NAME_value(sk,i);
j=i2d_X509_NAME(name,NULL);
if (!BUF_MEM_grow_clean(buf,DTLS1_HM_HEADER_LENGTH+n+j+2))
{
SSLerr(SSL_F_DTLS1_SEND_CERTIFICATE_REQUEST,ERR_R_BUF_LIB);
goto err;
}
p=(unsigned char *)&(buf->data[DTLS1_HM_HEADER_LENGTH+n]);
if (!(s->options & SSL_OP_NETSCAPE_CA_DN_BUG))
{
s2n(j,p);
i2d_X509_NAME(name,&p);
n+=2+j;
nl+=2+j;
}
else
{
d=p;
i2d_X509_NAME(name,&p);
j-=2; s2n(j,d); j+=2;
n+=j;
nl+=j;
}
}
}
p=(unsigned char *)&(buf->data[DTLS1_HM_HEADER_LENGTH+off]);
s2n(nl,p);
d=(unsigned char *)buf->data;
*(d++)=SSL3_MT_CERTIFICATE_REQUEST;
l2n3(n,d);
s2n(s->d1->handshake_write_seq,d);
s->d1->handshake_write_seq++;
s->init_num=n+DTLS1_HM_HEADER_LENGTH;
s->init_off=0;
#ifdef NETSCAPE_HANG_BUG
p=(unsigned char *)s->init_buf->data + s->init_num;
*(p++)=SSL3_MT_SERVER_DONE;
*(p++)=0;
*(p++)=0;
*(p++)=0;
s->init_num += 4;
#endif
msg_len = s->init_num - DTLS1_HM_HEADER_LENGTH;
dtls1_set_message_header(s, (void *)s->init_buf->data,
SSL3_MT_CERTIFICATE_REQUEST, msg_len, 0, msg_len);
dtls1_buffer_message(s, 0);
s->state = SSL3_ST_SW_CERT_REQ_B;
}
return(dtls1_do_write(s,SSL3_RT_HANDSHAKE));
err:
return(-1);
}
int dtls1_send_server_certificate(SSL *s)
{
unsigned long l;
X509 *x;
if (s->state == SSL3_ST_SW_CERT_A)
{
x=ssl_get_server_send_cert(s);
if (x == NULL)
{
if ((s->s3->tmp.new_cipher->algorithm_mkey != SSL_kKRB5) ||
(s->s3->tmp.new_cipher->algorithm_auth != SSL_aKRB5))
{
SSLerr(SSL_F_DTLS1_SEND_SERVER_CERTIFICATE,ERR_R_INTERNAL_ERROR);
return(0);
}
}
l=dtls1_output_cert_chain(s,x);
s->state=SSL3_ST_SW_CERT_B;
s->init_num=(int)l;
s->init_off=0;
dtls1_buffer_message(s, 0);
}
return(dtls1_do_write(s,SSL3_RT_HANDSHAKE));
}
int dtls1_send_newsession_ticket(SSL *s)
{
if (s->state == SSL3_ST_SW_SESSION_TICKET_A)
{
unsigned char *p, *senc, *macstart;
int len, slen;
unsigned int hlen, msg_len;
EVP_CIPHER_CTX ctx;
HMAC_CTX hctx;
SSL_CTX *tctx = s->initial_ctx;
unsigned char iv[EVP_MAX_IV_LENGTH];
unsigned char key_name[16];
slen = i2d_SSL_SESSION(s->session, NULL);
if (slen > 0xFF00)
return -1;
if (!BUF_MEM_grow(s->init_buf,
DTLS1_HM_HEADER_LENGTH + 22 + EVP_MAX_IV_LENGTH +
EVP_MAX_BLOCK_LENGTH + EVP_MAX_MD_SIZE + slen))
return -1;
senc = OPENSSL_malloc(slen);
if (!senc)
return -1;
p = senc;
i2d_SSL_SESSION(s->session, &p);
p=(unsigned char *)&(s->init_buf->data[DTLS1_HM_HEADER_LENGTH]);
EVP_CIPHER_CTX_init(&ctx);
HMAC_CTX_init(&hctx);
if (tctx->tlsext_ticket_key_cb)
{
if (tctx->tlsext_ticket_key_cb(s, key_name, iv, &ctx,
&hctx, 1) < 0)
{
OPENSSL_free(senc);
return -1;
}
}
else
{
RAND_pseudo_bytes(iv, 16);
EVP_EncryptInit_ex(&ctx, EVP_aes_128_cbc(), NULL,
tctx->tlsext_tick_aes_key, iv);
HMAC_Init_ex(&hctx, tctx->tlsext_tick_hmac_key, 16,
tlsext_tick_md(), NULL);
memcpy(key_name, tctx->tlsext_tick_key_name, 16);
}
l2n(s->session->tlsext_tick_lifetime_hint, p);
p += 2;
macstart = p;
memcpy(p, key_name, 16);
p += 16;
memcpy(p, iv, EVP_CIPHER_CTX_iv_length(&ctx));
p += EVP_CIPHER_CTX_iv_length(&ctx);
EVP_EncryptUpdate(&ctx, p, &len, senc, slen);
p += len;
EVP_EncryptFinal(&ctx, p, &len);
p += len;
EVP_CIPHER_CTX_cleanup(&ctx);
HMAC_Update(&hctx, macstart, p - macstart);
HMAC_Final(&hctx, p, &hlen);
HMAC_CTX_cleanup(&hctx);
p += hlen;
len = p - (unsigned char *)(s->init_buf->data);
p=(unsigned char *)&(s->init_buf->data[DTLS1_HM_HEADER_LENGTH]) + 4;
s2n(len - DTLS1_HM_HEADER_LENGTH - 6, p);
s->init_num= len;
s->state=SSL3_ST_SW_SESSION_TICKET_B;
s->init_off=0;
OPENSSL_free(senc);
msg_len = s->init_num - DTLS1_HM_HEADER_LENGTH;
dtls1_set_message_header(s, (void *)s->init_buf->data,
SSL3_MT_NEWSESSION_TICKET, msg_len, 0, msg_len);
dtls1_buffer_message(s, 0);
}
return(dtls1_do_write(s,SSL3_RT_HANDSHAKE));
}
