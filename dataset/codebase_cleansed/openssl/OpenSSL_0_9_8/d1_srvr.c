static SSL_METHOD *dtls1_get_server_method(int ver)
{
if (ver == DTLS1_VERSION)
return(DTLSv1_server_method());
else
return(NULL);
}
SSL_METHOD *DTLSv1_server_method(void)
{
static int init=1;
static SSL_METHOD DTLSv1_server_data;
if (init)
{
CRYPTO_w_lock(CRYPTO_LOCK_SSL_METHOD);
if (init)
{
memcpy((char *)&DTLSv1_server_data,(char *)dtlsv1_base_method(),
sizeof(SSL_METHOD));
DTLSv1_server_data.ssl_accept=dtls1_accept;
DTLSv1_server_data.get_ssl_method=dtls1_get_server_method;
init=0;
}
CRYPTO_w_unlock(CRYPTO_LOCK_SSL_METHOD);
}
return(&DTLSv1_server_data);
}
int dtls1_accept(SSL *s)
{
BUF_MEM *buf;
unsigned long l,Time=time(NULL);
void (*cb)(const SSL *ssl,int type,int val)=NULL;
long num1;
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
if ( (SSL_get_options(s) & SSL_OP_COOKIE_EXCHANGE))
s->d1->send_cookie = 1;
else
s->d1->send_cookie = 0;
break;
case SSL3_ST_SW_HELLO_REQ_A:
case SSL3_ST_SW_HELLO_REQ_B:
s->shutdown=0;
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
s->new_session = 2;
if ( s->d1->send_cookie)
s->state = DTLS1_ST_SW_HELLO_VERIFY_REQUEST_A;
else
s->state = SSL3_ST_SW_SRVR_HELLO_A;
s->init_num=0;
break;
case DTLS1_ST_SW_HELLO_VERIFY_REQUEST_A:
case DTLS1_ST_SW_HELLO_VERIFY_REQUEST_B:
ret = dtls1_send_hello_verify_request(s);
if ( ret <= 0) goto end;
s->d1->send_cookie = 0;
s->state=SSL3_ST_SW_FLUSH;
s->s3->tmp.next_state=SSL3_ST_SR_CLNT_HELLO_A;
break;
case SSL3_ST_SW_SRVR_HELLO_A:
case SSL3_ST_SW_SRVR_HELLO_B:
ret=dtls1_send_server_hello(s);
if (ret <= 0) goto end;
if (s->hit)
s->state=SSL3_ST_SW_CHANGE_A;
else
s->state=SSL3_ST_SW_CERT_A;
s->init_num=0;
break;
case SSL3_ST_SW_CERT_A:
case SSL3_ST_SW_CERT_B:
if (!(s->s3->tmp.new_cipher->algorithms & SSL_aNULL))
{
ret=dtls1_send_server_certificate(s);
if (ret <= 0) goto end;
}
else
skip=1;
s->state=SSL3_ST_SW_KEY_EXCH_A;
s->init_num=0;
break;
case SSL3_ST_SW_KEY_EXCH_A:
case SSL3_ST_SW_KEY_EXCH_B:
l=s->s3->tmp.new_cipher->algorithms;
if ((s->options & SSL_OP_EPHEMERAL_RSA)
#ifndef OPENSSL_NO_KRB5
&& !(l & SSL_KRB5)
#endif
)
s->s3->tmp.use_rsa_tmp=1;
else
s->s3->tmp.use_rsa_tmp=0;
if (s->s3->tmp.use_rsa_tmp
|| (l & (SSL_DH|SSL_kFZA))
|| ((l & SSL_kRSA)
&& (s->cert->pkeys[SSL_PKEY_RSA_ENC].privatekey == NULL
|| (SSL_C_IS_EXPORT(s->s3->tmp.new_cipher)
&& EVP_PKEY_size(s->cert->pkeys[SSL_PKEY_RSA_ENC].privatekey)*8 > SSL_C_EXPORT_PKEYLENGTH(s->s3->tmp.new_cipher)
)
)
)
)
{
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
((s->s3->tmp.new_cipher->algorithms & SSL_aNULL) &&
!(s->verify_mode & SSL_VERIFY_FAIL_IF_NO_PEER_CERT)) ||
(s->s3->tmp.new_cipher->algorithms & SSL_aKRB5))
{
skip=1;
s->s3->tmp.cert_request=0;
s->state=SSL3_ST_SW_SRVR_DONE_A;
}
else
{
s->s3->tmp.cert_request=1;
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
ret=dtls1_send_server_done(s);
if (ret <= 0) goto end;
s->s3->tmp.next_state=SSL3_ST_SR_CERT_A;
s->state=SSL3_ST_SW_FLUSH;
s->init_num=0;
break;
case SSL3_ST_SW_FLUSH:
num1=BIO_ctrl(s->wbio,BIO_CTRL_INFO,0,NULL);
if (num1 > 0)
{
s->rwstate=SSL_WRITING;
num1=BIO_flush(s->wbio);
if (num1 <= 0) { ret= -1; goto end; }
s->rwstate=SSL_NOTHING;
}
s->state=s->s3->tmp.next_state;
break;
case SSL3_ST_SR_CERT_A:
case SSL3_ST_SR_CERT_B:
ret = ssl3_check_client_hello(s);
if (ret <= 0)
goto end;
if (ret == 2)
s->state = SSL3_ST_SR_CLNT_HELLO_C;
else {
ret=ssl3_get_client_certificate(s);
if (ret <= 0) goto end;
s->init_num=0;
s->state=SSL3_ST_SR_KEY_EXCH_A;
}
break;
case SSL3_ST_SR_KEY_EXCH_A:
case SSL3_ST_SR_KEY_EXCH_B:
ret=ssl3_get_client_key_exchange(s);
if (ret <= 0) goto end;
s->state=SSL3_ST_SR_CERT_VRFY_A;
s->init_num=0;
s->method->ssl3_enc->cert_verify_mac(s,
&(s->s3->finish_dgst1),
&(s->s3->tmp.cert_verify_md[0]));
s->method->ssl3_enc->cert_verify_mac(s,
&(s->s3->finish_dgst2),
&(s->s3->tmp.cert_verify_md[MD5_DIGEST_LENGTH]));
break;
case SSL3_ST_SR_CERT_VRFY_A:
case SSL3_ST_SR_CERT_VRFY_B:
ret=ssl3_get_cert_verify(s);
if (ret <= 0) goto end;
s->state=SSL3_ST_SR_FINISHED_A;
s->init_num=0;
break;
case SSL3_ST_SR_FINISHED_A:
case SSL3_ST_SR_FINISHED_B:
ret=ssl3_get_finished(s,SSL3_ST_SR_FINISHED_A,
SSL3_ST_SR_FINISHED_B);
if (ret <= 0) goto end;
if (s->hit)
s->state=SSL_ST_OK;
else
s->state=SSL3_ST_SW_CHANGE_A;
s->init_num=0;
break;
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
end:
s->in_handshake--;
if (cb != NULL)
cb(s,SSL_CB_ACCEPT_EXIT,ret);
return(ret);
}
int dtls1_send_hello_request(SSL *s)
{
unsigned char *p;
if (s->state == SSL3_ST_SW_HELLO_REQ_A)
{
p=(unsigned char *)s->init_buf->data;
p = dtls1_set_message_header(s, p, SSL3_MT_HELLO_REQUEST, 0, 0, 0);
s->state=SSL3_ST_SW_HELLO_REQ_B;
s->init_num=DTLS1_HM_HEADER_LENGTH;
s->init_off=0;
}
return(dtls1_do_write(s,SSL3_RT_HANDSHAKE));
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
*(p++) = (unsigned char) s->d1->cookie_len;
if ( s->ctx->app_gen_cookie_cb != NULL &&
s->ctx->app_gen_cookie_cb(s, s->d1->cookie,
&(s->d1->cookie_len)) == 0)
{
SSLerr(SSL_F_DTLS1_SEND_HELLO_VERIFY_REQUEST,ERR_R_INTERNAL_ERROR);
return 0;
}
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
int i,sl;
unsigned long l,Time;
if (s->state == SSL3_ST_SW_SRVR_HELLO_A)
{
buf=(unsigned char *)s->init_buf->data;
p=s->s3->server_random;
Time=time(NULL);
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
i=ssl3_put_cipher_by_char(s->s3->tmp.new_cipher,p);
p+=i;
if (s->s3->tmp.new_compression == NULL)
*(p++)=0;
else
*(p++)=s->s3->tmp.new_compression->id;
l=(p-d);
d=buf;
d = dtls1_set_message_header(s, d, SSL3_MT_SERVER_HELLO, l, 0, l);
s->state=SSL3_ST_CW_CLNT_HELLO_B;
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
type=s->s3->tmp.new_cipher->algorithms & SSL_MKEY_MASK;
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
if (!(s->s3->tmp.new_cipher->algorithms & SSL_aNULL))
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
if (x == NULL &&
(s->s3->tmp.new_cipher->algorithms
& (SSL_MKEY_MASK|SSL_AUTH_MASK))
!= (SSL_aKRB5|SSL_kKRB5))
{
SSLerr(SSL_F_DTLS1_SEND_SERVER_CERTIFICATE,ERR_R_INTERNAL_ERROR);
return(0);
}
l=dtls1_output_cert_chain(s,x);
s->state=SSL3_ST_SW_CERT_B;
s->init_num=(int)l;
s->init_off=0;
dtls1_buffer_message(s, 0);
}
return(dtls1_do_write(s,SSL3_RT_HANDSHAKE));
}
