long ssl3_default_timeout(void)
{
return(60*60*2);
}
int ssl3_num_ciphers(void)
{
return(SSL3_NUM_CIPHERS);
}
const SSL_CIPHER *ssl3_get_cipher(unsigned int u)
{
if (u < SSL3_NUM_CIPHERS)
return(&(ssl3_ciphers[SSL3_NUM_CIPHERS-1-u]));
else
return(NULL);
}
int ssl3_pending(const SSL *s)
{
if (s->rstate == SSL_ST_READ_BODY)
return 0;
return (s->s3->rrec.type == SSL3_RT_APPLICATION_DATA) ? s->s3->rrec.length : 0;
}
int ssl3_new(SSL *s)
{
SSL3_STATE *s3;
if ((s3=OPENSSL_malloc(sizeof *s3)) == NULL) goto err;
memset(s3,0,sizeof *s3);
memset(s3->rrec.seq_num,0,sizeof(s3->rrec.seq_num));
memset(s3->wrec.seq_num,0,sizeof(s3->wrec.seq_num));
s->s3=s3;
s->method->ssl_clear(s);
return(1);
err:
return(0);
}
void ssl3_free(SSL *s)
{
if(s == NULL)
return;
#ifdef TLSEXT_TYPE_opaque_prf_input
if (s->s3->client_opaque_prf_input != NULL)
OPENSSL_free(s->s3->client_opaque_prf_input);
if (s->s3->server_opaque_prf_input != NULL)
OPENSSL_free(s->s3->server_opaque_prf_input);
#endif
ssl3_cleanup_key_block(s);
if (s->s3->rbuf.buf != NULL)
ssl3_release_read_buffer(s);
if (s->s3->wbuf.buf != NULL)
ssl3_release_write_buffer(s);
if (s->s3->rrec.comp != NULL)
OPENSSL_free(s->s3->rrec.comp);
#ifndef OPENSSL_NO_DH
if (s->s3->tmp.dh != NULL)
DH_free(s->s3->tmp.dh);
#endif
#ifndef OPENSSL_NO_ECDH
if (s->s3->tmp.ecdh != NULL)
EC_KEY_free(s->s3->tmp.ecdh);
#endif
if (s->s3->tmp.ca_names != NULL)
sk_X509_NAME_pop_free(s->s3->tmp.ca_names,X509_NAME_free);
if (s->s3->handshake_buffer) {
BIO_free(s->s3->handshake_buffer);
}
if (s->s3->handshake_dgst) ssl3_free_digest_list(s);
OPENSSL_cleanse(s->s3,sizeof *s->s3);
OPENSSL_free(s->s3);
s->s3=NULL;
}
void ssl3_clear(SSL *s)
{
unsigned char *rp,*wp;
size_t rlen, wlen;
#ifdef TLSEXT_TYPE_opaque_prf_input
if (s->s3->client_opaque_prf_input != NULL)
OPENSSL_free(s->s3->client_opaque_prf_input);
s->s3->client_opaque_prf_input = NULL;
if (s->s3->server_opaque_prf_input != NULL)
OPENSSL_free(s->s3->server_opaque_prf_input);
s->s3->server_opaque_prf_input = NULL;
#endif
ssl3_cleanup_key_block(s);
if (s->s3->tmp.ca_names != NULL)
sk_X509_NAME_pop_free(s->s3->tmp.ca_names,X509_NAME_free);
if (s->s3->rrec.comp != NULL)
{
OPENSSL_free(s->s3->rrec.comp);
s->s3->rrec.comp=NULL;
}
#ifndef OPENSSL_NO_DH
if (s->s3->tmp.dh != NULL)
DH_free(s->s3->tmp.dh);
#endif
#ifndef OPENSSL_NO_ECDH
if (s->s3->tmp.ecdh != NULL)
EC_KEY_free(s->s3->tmp.ecdh);
#endif
rp = s->s3->rbuf.buf;
wp = s->s3->wbuf.buf;
rlen = s->s3->rbuf.len;
wlen = s->s3->wbuf.len;
if (s->s3->handshake_buffer) {
BIO_free(s->s3->handshake_buffer);
s->s3->handshake_buffer = NULL;
}
if (s->s3->handshake_dgst) {
ssl3_free_digest_list(s);
}
memset(s->s3,0,sizeof *s->s3);
s->s3->rbuf.buf = rp;
s->s3->wbuf.buf = wp;
s->s3->rbuf.len = rlen;
s->s3->wbuf.len = wlen;
ssl_free_wbio_buffer(s);
s->packet_length=0;
s->s3->renegotiate=0;
s->s3->total_renegotiations=0;
s->s3->num_renegotiations=0;
s->s3->in_read_app_data=0;
s->version=SSL3_VERSION;
}
long ssl3_ctrl(SSL *s, int cmd, long larg, void *parg)
{
int ret=0;
#if !defined(OPENSSL_NO_DSA) || !defined(OPENSSL_NO_RSA)
if (
#ifndef OPENSSL_NO_RSA
cmd == SSL_CTRL_SET_TMP_RSA ||
cmd == SSL_CTRL_SET_TMP_RSA_CB ||
#endif
#ifndef OPENSSL_NO_DSA
cmd == SSL_CTRL_SET_TMP_DH ||
cmd == SSL_CTRL_SET_TMP_DH_CB ||
#endif
0)
{
if (!ssl_cert_inst(&s->cert))
{
SSLerr(SSL_F_SSL3_CTRL, ERR_R_MALLOC_FAILURE);
return(0);
}
}
#endif
switch (cmd)
{
case SSL_CTRL_GET_SESSION_REUSED:
ret=s->hit;
break;
case SSL_CTRL_GET_CLIENT_CERT_REQUEST:
break;
case SSL_CTRL_GET_NUM_RENEGOTIATIONS:
ret=s->s3->num_renegotiations;
break;
case SSL_CTRL_CLEAR_NUM_RENEGOTIATIONS:
ret=s->s3->num_renegotiations;
s->s3->num_renegotiations=0;
break;
case SSL_CTRL_GET_TOTAL_RENEGOTIATIONS:
ret=s->s3->total_renegotiations;
break;
case SSL_CTRL_GET_FLAGS:
ret=(int)(s->s3->flags);
break;
#ifndef OPENSSL_NO_RSA
case SSL_CTRL_NEED_TMP_RSA:
if ((s->cert != NULL) && (s->cert->rsa_tmp == NULL) &&
((s->cert->pkeys[SSL_PKEY_RSA_ENC].privatekey == NULL) ||
(EVP_PKEY_size(s->cert->pkeys[SSL_PKEY_RSA_ENC].privatekey) > (512/8))))
ret = 1;
break;
case SSL_CTRL_SET_TMP_RSA:
{
RSA *rsa = (RSA *)parg;
if (rsa == NULL)
{
SSLerr(SSL_F_SSL3_CTRL, ERR_R_PASSED_NULL_PARAMETER);
return(ret);
}
if ((rsa = RSAPrivateKey_dup(rsa)) == NULL)
{
SSLerr(SSL_F_SSL3_CTRL, ERR_R_RSA_LIB);
return(ret);
}
if (s->cert->rsa_tmp != NULL)
RSA_free(s->cert->rsa_tmp);
s->cert->rsa_tmp = rsa;
ret = 1;
}
break;
case SSL_CTRL_SET_TMP_RSA_CB:
{
SSLerr(SSL_F_SSL3_CTRL, ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED);
return(ret);
}
break;
#endif
#ifndef OPENSSL_NO_DH
case SSL_CTRL_SET_TMP_DH:
{
DH *dh = (DH *)parg;
if (dh == NULL)
{
SSLerr(SSL_F_SSL3_CTRL, ERR_R_PASSED_NULL_PARAMETER);
return(ret);
}
if ((dh = DHparams_dup(dh)) == NULL)
{
SSLerr(SSL_F_SSL3_CTRL, ERR_R_DH_LIB);
return(ret);
}
if (!(s->options & SSL_OP_SINGLE_DH_USE))
{
if (!DH_generate_key(dh))
{
DH_free(dh);
SSLerr(SSL_F_SSL3_CTRL, ERR_R_DH_LIB);
return(ret);
}
}
if (s->cert->dh_tmp != NULL)
DH_free(s->cert->dh_tmp);
s->cert->dh_tmp = dh;
ret = 1;
}
break;
case SSL_CTRL_SET_TMP_DH_CB:
{
SSLerr(SSL_F_SSL3_CTRL, ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED);
return(ret);
}
break;
#endif
#ifndef OPENSSL_NO_ECDH
case SSL_CTRL_SET_TMP_ECDH:
{
EC_KEY *ecdh = NULL;
if (parg == NULL)
{
SSLerr(SSL_F_SSL3_CTRL, ERR_R_PASSED_NULL_PARAMETER);
return(ret);
}
if (!EC_KEY_up_ref((EC_KEY *)parg))
{
SSLerr(SSL_F_SSL3_CTRL,ERR_R_ECDH_LIB);
return(ret);
}
ecdh = (EC_KEY *)parg;
if (!(s->options & SSL_OP_SINGLE_ECDH_USE))
{
if (!EC_KEY_generate_key(ecdh))
{
EC_KEY_free(ecdh);
SSLerr(SSL_F_SSL3_CTRL,ERR_R_ECDH_LIB);
return(ret);
}
}
if (s->cert->ecdh_tmp != NULL)
EC_KEY_free(s->cert->ecdh_tmp);
s->cert->ecdh_tmp = ecdh;
ret = 1;
}
break;
case SSL_CTRL_SET_TMP_ECDH_CB:
{
SSLerr(SSL_F_SSL3_CTRL, ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED);
return(ret);
}
break;
#endif
#ifndef OPENSSL_NO_TLSEXT
case SSL_CTRL_SET_TLSEXT_HOSTNAME:
if (larg == TLSEXT_NAMETYPE_host_name)
{
if (s->tlsext_hostname != NULL)
OPENSSL_free(s->tlsext_hostname);
s->tlsext_hostname = NULL;
ret = 1;
if (parg == NULL)
break;
if (strlen((char *)parg) > TLSEXT_MAXLEN_host_name)
{
SSLerr(SSL_F_SSL3_CTRL, SSL_R_SSL3_EXT_INVALID_SERVERNAME);
return 0;
}
if ((s->tlsext_hostname = BUF_strdup((char *)parg)) == NULL)
{
SSLerr(SSL_F_SSL3_CTRL, ERR_R_INTERNAL_ERROR);
return 0;
}
}
else
{
SSLerr(SSL_F_SSL3_CTRL, SSL_R_SSL3_EXT_INVALID_SERVERNAME_TYPE);
return 0;
}
break;
case SSL_CTRL_SET_TLSEXT_DEBUG_ARG:
s->tlsext_debug_arg=parg;
ret = 1;
break;
#ifdef TLSEXT_TYPE_opaque_prf_input
case SSL_CTRL_SET_TLSEXT_OPAQUE_PRF_INPUT:
if (larg > 12288)
{
SSLerr(SSL_F_SSL3_CTRL, SSL_R_OPAQUE_PRF_INPUT_TOO_LONG);
break;
}
if (s->tlsext_opaque_prf_input != NULL)
OPENSSL_free(s->tlsext_opaque_prf_input);
if ((size_t)larg == 0)
s->tlsext_opaque_prf_input = OPENSSL_malloc(1);
else
s->tlsext_opaque_prf_input = BUF_memdup(parg, (size_t)larg);
if (s->tlsext_opaque_prf_input != NULL)
{
s->tlsext_opaque_prf_input_len = (size_t)larg;
ret = 1;
}
else
s->tlsext_opaque_prf_input_len = 0;
break;
#endif
case SSL_CTRL_SET_TLSEXT_STATUS_REQ_TYPE:
s->tlsext_status_type=larg;
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
if (s->tlsext_ocsp_resp)
OPENSSL_free(s->tlsext_ocsp_resp);
s->tlsext_ocsp_resp = parg;
s->tlsext_ocsp_resplen = larg;
ret = 1;
break;
#endif
default:
break;
}
return(ret);
}
long ssl3_callback_ctrl(SSL *s, int cmd, void (*fp)(void))
{
int ret=0;
#if !defined(OPENSSL_NO_DSA) || !defined(OPENSSL_NO_RSA)
if (
#ifndef OPENSSL_NO_RSA
cmd == SSL_CTRL_SET_TMP_RSA_CB ||
#endif
#ifndef OPENSSL_NO_DSA
cmd == SSL_CTRL_SET_TMP_DH_CB ||
#endif
0)
{
if (!ssl_cert_inst(&s->cert))
{
SSLerr(SSL_F_SSL3_CALLBACK_CTRL, ERR_R_MALLOC_FAILURE);
return(0);
}
}
#endif
switch (cmd)
{
#ifndef OPENSSL_NO_RSA
case SSL_CTRL_SET_TMP_RSA_CB:
{
s->cert->rsa_tmp_cb = (RSA *(*)(SSL *, int, int))fp;
}
break;
#endif
#ifndef OPENSSL_NO_DH
case SSL_CTRL_SET_TMP_DH_CB:
{
s->cert->dh_tmp_cb = (DH *(*)(SSL *, int, int))fp;
}
break;
#endif
#ifndef OPENSSL_NO_ECDH
case SSL_CTRL_SET_TMP_ECDH_CB:
{
s->cert->ecdh_tmp_cb = (EC_KEY *(*)(SSL *, int, int))fp;
}
break;
#endif
#ifndef OPENSSL_NO_TLSEXT
case SSL_CTRL_SET_TLSEXT_DEBUG_CB:
s->tlsext_debug_cb=(void (*)(SSL *,int ,int,
unsigned char *, int, void *))fp;
break;
#endif
default:
break;
}
return(ret);
}
long ssl3_ctx_ctrl(SSL_CTX *ctx, int cmd, long larg, void *parg)
{
CERT *cert;
cert=ctx->cert;
switch (cmd)
{
#ifndef OPENSSL_NO_RSA
case SSL_CTRL_NEED_TMP_RSA:
if ( (cert->rsa_tmp == NULL) &&
((cert->pkeys[SSL_PKEY_RSA_ENC].privatekey == NULL) ||
(EVP_PKEY_size(cert->pkeys[SSL_PKEY_RSA_ENC].privatekey) > (512/8)))
)
return(1);
else
return(0);
case SSL_CTRL_SET_TMP_RSA:
{
RSA *rsa;
int i;
rsa=(RSA *)parg;
i=1;
if (rsa == NULL)
i=0;
else
{
if ((rsa=RSAPrivateKey_dup(rsa)) == NULL)
i=0;
}
if (!i)
{
SSLerr(SSL_F_SSL3_CTX_CTRL,ERR_R_RSA_LIB);
return(0);
}
else
{
if (cert->rsa_tmp != NULL)
RSA_free(cert->rsa_tmp);
cert->rsa_tmp=rsa;
return(1);
}
}
case SSL_CTRL_SET_TMP_RSA_CB:
{
SSLerr(SSL_F_SSL3_CTX_CTRL, ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED);
return(0);
}
break;
#endif
#ifndef OPENSSL_NO_DH
case SSL_CTRL_SET_TMP_DH:
{
DH *new=NULL,*dh;
dh=(DH *)parg;
if ((new=DHparams_dup(dh)) == NULL)
{
SSLerr(SSL_F_SSL3_CTX_CTRL,ERR_R_DH_LIB);
return 0;
}
if (!(ctx->options & SSL_OP_SINGLE_DH_USE))
{
if (!DH_generate_key(new))
{
SSLerr(SSL_F_SSL3_CTX_CTRL,ERR_R_DH_LIB);
DH_free(new);
return 0;
}
}
if (cert->dh_tmp != NULL)
DH_free(cert->dh_tmp);
cert->dh_tmp=new;
return 1;
}
case SSL_CTRL_SET_TMP_DH_CB:
{
SSLerr(SSL_F_SSL3_CTX_CTRL, ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED);
return(0);
}
break;
#endif
#ifndef OPENSSL_NO_ECDH
case SSL_CTRL_SET_TMP_ECDH:
{
EC_KEY *ecdh = NULL;
if (parg == NULL)
{
SSLerr(SSL_F_SSL3_CTX_CTRL,ERR_R_ECDH_LIB);
return 0;
}
ecdh = EC_KEY_dup((EC_KEY *)parg);
if (ecdh == NULL)
{
SSLerr(SSL_F_SSL3_CTX_CTRL,ERR_R_EC_LIB);
return 0;
}
if (!(ctx->options & SSL_OP_SINGLE_ECDH_USE))
{
if (!EC_KEY_generate_key(ecdh))
{
EC_KEY_free(ecdh);
SSLerr(SSL_F_SSL3_CTX_CTRL,ERR_R_ECDH_LIB);
return 0;
}
}
if (cert->ecdh_tmp != NULL)
{
EC_KEY_free(cert->ecdh_tmp);
}
cert->ecdh_tmp = ecdh;
return 1;
}
case SSL_CTRL_SET_TMP_ECDH_CB:
{
SSLerr(SSL_F_SSL3_CTX_CTRL, ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED);
return(0);
}
break;
#endif
#ifndef OPENSSL_NO_TLSEXT
case SSL_CTRL_SET_TLSEXT_SERVERNAME_ARG:
ctx->tlsext_servername_arg=parg;
break;
case SSL_CTRL_SET_TLSEXT_TICKET_KEYS:
case SSL_CTRL_GET_TLSEXT_TICKET_KEYS:
{
unsigned char *keys = parg;
if (!keys)
return 48;
if (larg != 48)
{
SSLerr(SSL_F_SSL3_CTX_CTRL, SSL_R_INVALID_TICKET_KEYS_LENGTH);
return 0;
}
if (cmd == SSL_CTRL_SET_TLSEXT_TICKET_KEYS)
{
memcpy(ctx->tlsext_tick_key_name, keys, 16);
memcpy(ctx->tlsext_tick_hmac_key, keys + 16, 16);
memcpy(ctx->tlsext_tick_aes_key, keys + 32, 16);
}
else
{
memcpy(keys, ctx->tlsext_tick_key_name, 16);
memcpy(keys + 16, ctx->tlsext_tick_hmac_key, 16);
memcpy(keys + 32, ctx->tlsext_tick_aes_key, 16);
}
return 1;
}
#ifdef TLSEXT_TYPE_opaque_prf_input
case SSL_CTRL_SET_TLSEXT_OPAQUE_PRF_INPUT_CB_ARG:
ctx->tlsext_opaque_prf_input_callback_arg = parg;
return 1;
#endif
case SSL_CTRL_SET_TLSEXT_STATUS_REQ_CB_ARG:
ctx->tlsext_status_arg=parg;
return 1;
break;
#endif
case SSL_CTRL_EXTRA_CHAIN_CERT:
if (ctx->extra_certs == NULL)
{
if ((ctx->extra_certs=sk_X509_new_null()) == NULL)
return(0);
}
sk_X509_push(ctx->extra_certs,(X509 *)parg);
break;
default:
return(0);
}
return(1);
}
long ssl3_ctx_callback_ctrl(SSL_CTX *ctx, int cmd, void (*fp)(void))
{
CERT *cert;
cert=ctx->cert;
switch (cmd)
{
#ifndef OPENSSL_NO_RSA
case SSL_CTRL_SET_TMP_RSA_CB:
{
cert->rsa_tmp_cb = (RSA *(*)(SSL *, int, int))fp;
}
break;
#endif
#ifndef OPENSSL_NO_DH
case SSL_CTRL_SET_TMP_DH_CB:
{
cert->dh_tmp_cb = (DH *(*)(SSL *, int, int))fp;
}
break;
#endif
#ifndef OPENSSL_NO_ECDH
case SSL_CTRL_SET_TMP_ECDH_CB:
{
cert->ecdh_tmp_cb = (EC_KEY *(*)(SSL *, int, int))fp;
}
break;
#endif
#ifndef OPENSSL_NO_TLSEXT
case SSL_CTRL_SET_TLSEXT_SERVERNAME_CB:
ctx->tlsext_servername_callback=(int (*)(SSL *,int *,void *))fp;
break;
#ifdef TLSEXT_TYPE_opaque_prf_input
case SSL_CTRL_SET_TLSEXT_OPAQUE_PRF_INPUT_CB:
ctx->tlsext_opaque_prf_input_callback = (int (*)(SSL *,void *, size_t, void *))fp;
break;
#endif
case SSL_CTRL_SET_TLSEXT_STATUS_REQ_CB:
ctx->tlsext_status_cb=(int (*)(SSL *,void *))fp;
break;
case SSL_CTRL_SET_TLSEXT_TICKET_KEY_CB:
ctx->tlsext_ticket_key_cb=(int (*)(SSL *,unsigned char *,
unsigned char *,
EVP_CIPHER_CTX *,
HMAC_CTX *, int))fp;
break;
#endif
default:
return(0);
}
return(1);
}
const SSL_CIPHER *ssl3_get_cipher_by_char(const unsigned char *p)
{
SSL_CIPHER c;
const SSL_CIPHER *cp;
unsigned long id;
id=0x03000000L|((unsigned long)p[0]<<8L)|(unsigned long)p[1];
c.id=id;
cp = OBJ_bsearch_ssl_cipher_id(&c, ssl3_ciphers, SSL3_NUM_CIPHERS);
if (cp == NULL || cp->valid == 0)
return NULL;
else
return cp;
}
int ssl3_put_cipher_by_char(const SSL_CIPHER *c, unsigned char *p)
{
long l;
if (p != NULL)
{
l=c->id;
if ((l & 0xff000000) != 0x03000000) return(0);
p[0]=((unsigned char)(l>> 8L))&0xFF;
p[1]=((unsigned char)(l ))&0xFF;
}
return(2);
}
int ssl3_get_req_cert_type(SSL *s, unsigned char *p)
{
int ret=0;
unsigned long alg_k;
alg_k = s->s3->tmp.new_cipher->algorithm_mkey;
#ifndef OPENSSL_NO_GOST
if (s->version >= TLS1_VERSION)
{
if (alg_k & SSL_kGOST)
{
p[ret++]=TLS_CT_GOST94_SIGN;
p[ret++]=TLS_CT_GOST01_SIGN;
return(ret);
}
}
#endif
#ifndef OPENSSL_NO_DH
if (alg_k & (SSL_kDHr|SSL_kEDH))
{
# ifndef OPENSSL_NO_RSA
p[ret++]=SSL3_CT_RSA_FIXED_DH;
# endif
# ifndef OPENSSL_NO_DSA
p[ret++]=SSL3_CT_DSS_FIXED_DH;
# endif
}
if ((s->version == SSL3_VERSION) &&
(alg_k & (SSL_kEDH|SSL_kDHd|SSL_kDHr)))
{
# ifndef OPENSSL_NO_RSA
p[ret++]=SSL3_CT_RSA_EPHEMERAL_DH;
# endif
# ifndef OPENSSL_NO_DSA
p[ret++]=SSL3_CT_DSS_EPHEMERAL_DH;
# endif
}
#endif
#ifndef OPENSSL_NO_RSA
p[ret++]=SSL3_CT_RSA_SIGN;
#endif
#ifndef OPENSSL_NO_DSA
p[ret++]=SSL3_CT_DSS_SIGN;
#endif
#ifndef OPENSSL_NO_ECDH
if ((alg_k & (SSL_kECDHr|SSL_kECDHe)) && (s->version >= TLS1_VERSION))
{
p[ret++]=TLS_CT_RSA_FIXED_ECDH;
p[ret++]=TLS_CT_ECDSA_FIXED_ECDH;
}
#endif
#ifndef OPENSSL_NO_ECDSA
if (s->version >= TLS1_VERSION)
{
p[ret++]=TLS_CT_ECDSA_SIGN;
}
#endif
return(ret);
}
int ssl3_shutdown(SSL *s)
{
int ret;
if ((s->quiet_shutdown) || (s->state == SSL_ST_BEFORE))
{
s->shutdown=(SSL_SENT_SHUTDOWN|SSL_RECEIVED_SHUTDOWN);
return(1);
}
if (!(s->shutdown & SSL_SENT_SHUTDOWN))
{
s->shutdown|=SSL_SENT_SHUTDOWN;
#if 1
ssl3_send_alert(s,SSL3_AL_WARNING,SSL_AD_CLOSE_NOTIFY);
#endif
if (s->s3->alert_dispatch)
return(-1);
}
else if (s->s3->alert_dispatch)
{
#if 1
ret=s->method->ssl_dispatch_alert(s);
if(ret == -1)
{
return(ret);
}
#endif
}
else if (!(s->shutdown & SSL_RECEIVED_SHUTDOWN))
{
s->method->ssl_read_bytes(s,0,NULL,0,0);
if(!(s->shutdown & SSL_RECEIVED_SHUTDOWN))
{
return(-1);
}
}
if ((s->shutdown == (SSL_SENT_SHUTDOWN|SSL_RECEIVED_SHUTDOWN)) &&
!s->s3->alert_dispatch)
return(1);
else
return(0);
}
int ssl3_write(SSL *s, const void *buf, int len)
{
int ret,n;
#if 0
if (s->shutdown & SSL_SEND_SHUTDOWN)
{
s->rwstate=SSL_NOTHING;
return(0);
}
#endif
clear_sys_error();
if (s->s3->renegotiate) ssl3_renegotiate_check(s);
if ((s->s3->flags & SSL3_FLAGS_POP_BUFFER) && (s->wbio == s->bbio))
{
if (s->s3->delay_buf_pop_ret == 0)
{
ret=ssl3_write_bytes(s,SSL3_RT_APPLICATION_DATA,
buf,len);
if (ret <= 0) return(ret);
s->s3->delay_buf_pop_ret=ret;
}
s->rwstate=SSL_WRITING;
n=BIO_flush(s->wbio);
if (n <= 0) return(n);
s->rwstate=SSL_NOTHING;
ssl_free_wbio_buffer(s);
s->s3->flags&= ~SSL3_FLAGS_POP_BUFFER;
ret=s->s3->delay_buf_pop_ret;
s->s3->delay_buf_pop_ret=0;
}
else
{
ret=s->method->ssl_write_bytes(s,SSL3_RT_APPLICATION_DATA,
buf,len);
if (ret <= 0) return(ret);
}
return(ret);
}
static int ssl3_read_internal(SSL *s, void *buf, int len, int peek)
{
int ret;
clear_sys_error();
if (s->s3->renegotiate) ssl3_renegotiate_check(s);
s->s3->in_read_app_data=1;
ret=s->method->ssl_read_bytes(s,SSL3_RT_APPLICATION_DATA,buf,len,peek);
if ((ret == -1) && (s->s3->in_read_app_data == 2))
{
s->in_handshake++;
ret=s->method->ssl_read_bytes(s,SSL3_RT_APPLICATION_DATA,buf,len,peek);
s->in_handshake--;
}
else
s->s3->in_read_app_data=0;
return(ret);
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
return(1);
if (s->s3->flags & SSL3_FLAGS_NO_RENEGOTIATE_CIPHERS)
return(0);
s->s3->renegotiate=1;
return(1);
}
int ssl3_renegotiate_check(SSL *s)
{
int ret=0;
if (s->s3->renegotiate)
{
if ( (s->s3->rbuf.left == 0) &&
(s->s3->wbuf.left == 0) &&
!SSL_in_init(s))
{
s->state=SSL_ST_RENEGOTIATE;
s->s3->renegotiate=0;
s->s3->num_renegotiations++;
s->s3->total_renegotiations++;
ret=1;
}
}
return(ret);
}
