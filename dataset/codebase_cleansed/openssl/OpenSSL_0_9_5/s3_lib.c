static long ssl3_default_timeout(void)
{
return(60*60*2);
}
SSL_METHOD *sslv3_base_method(void)
{
return(&SSLv3_data);
}
int ssl3_num_ciphers(void)
{
return(SSL3_NUM_CIPHERS);
}
SSL_CIPHER *ssl3_get_cipher(unsigned int u)
{
if (u < SSL3_NUM_CIPHERS)
return(&(ssl3_ciphers[SSL3_NUM_CIPHERS-1-u]));
else
return(NULL);
}
int ssl3_pending(SSL *s)
{
return(s->s3->rrec.length);
}
int ssl3_new(SSL *s)
{
SSL3_STATE *s3;
if ((s3=Malloc(sizeof *s3)) == NULL) goto err;
memset(s3,0,sizeof *s3);
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
ssl3_cleanup_key_block(s);
if (s->s3->rbuf.buf != NULL)
Free(s->s3->rbuf.buf);
if (s->s3->wbuf.buf != NULL)
Free(s->s3->wbuf.buf);
if (s->s3->rrec.comp != NULL)
Free(s->s3->rrec.comp);
#ifndef NO_DH
if (s->s3->tmp.dh != NULL)
DH_free(s->s3->tmp.dh);
#endif
if (s->s3->tmp.ca_names != NULL)
sk_X509_NAME_pop_free(s->s3->tmp.ca_names,X509_NAME_free);
memset(s->s3,0,sizeof *s->s3);
Free(s->s3);
s->s3=NULL;
}
void ssl3_clear(SSL *s)
{
unsigned char *rp,*wp;
ssl3_cleanup_key_block(s);
if (s->s3->tmp.ca_names != NULL)
sk_X509_NAME_pop_free(s->s3->tmp.ca_names,X509_NAME_free);
if (s->s3->rrec.comp != NULL)
{
Free(s->s3->rrec.comp);
s->s3->rrec.comp=NULL;
}
#ifndef NO_DH
if (s->s3->tmp.dh != NULL)
DH_free(s->s3->tmp.dh);
#endif
rp=s->s3->rbuf.buf;
wp=s->s3->wbuf.buf;
memset(s->s3,0,sizeof *s->s3);
if (rp != NULL) s->s3->rbuf.buf=rp;
if (wp != NULL) s->s3->wbuf.buf=wp;
ssl_free_wbio_buffer(s);
s->packet_length=0;
s->s3->renegotiate=0;
s->s3->total_renegotiations=0;
s->s3->num_renegotiations=0;
s->s3->in_read_app_data=0;
s->version=SSL3_VERSION;
}
long ssl3_ctrl(SSL *s, int cmd, long larg, char *parg)
{
int ret=0;
#if !defined(NO_DSA) || !defined(NO_RSA)
if (
#ifndef NO_RSA
cmd == SSL_CTRL_SET_TMP_RSA ||
cmd == SSL_CTRL_SET_TMP_RSA_CB ||
#endif
#ifndef NO_DSA
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
#ifndef NO_RSA
case SSL_CTRL_NEED_TMP_RSA:
if ((s->cert != NULL) && (s->cert->rsa_tmp == NULL) &&
((s->cert->pkeys[SSL_PKEY_RSA_ENC].privatekey == NULL) ||
(EVP_PKEY_size(s->cert->pkeys[SSL_PKEY_RSA_ENC].privatekey) > (512/8))))
ret = 1;
break;
case SSL_CTRL_SET_TMP_RSA:
{
RSA *rsa = (RSA *)parg;
if (rsa == NULL) {
SSLerr(SSL_F_SSL3_CTRL, ERR_R_PASSED_NULL_PARAMETER);
return(ret);
}
if ((rsa = RSAPrivateKey_dup(rsa)) == NULL) {
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
#ifndef NO_DH
case SSL_CTRL_SET_TMP_DH:
{
DH *dh = (DH *)parg;
if (dh == NULL) {
SSLerr(SSL_F_SSL3_CTRL, ERR_R_PASSED_NULL_PARAMETER);
return(ret);
}
if ((dh = DHparams_dup(dh)) == NULL) {
SSLerr(SSL_F_SSL3_CTRL, ERR_R_DH_LIB);
return(ret);
}
if (!DH_generate_key(dh)) {
DH_free(dh);
SSLerr(SSL_F_SSL3_CTRL, ERR_R_DH_LIB);
return(ret);
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
default:
break;
}
return(ret);
}
long ssl3_callback_ctrl(SSL *s, int cmd, void (*fp)())
{
int ret=0;
#if !defined(NO_DSA) || !defined(NO_RSA)
if (
#ifndef NO_RSA
cmd == SSL_CTRL_SET_TMP_RSA_CB ||
#endif
#ifndef NO_DSA
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
#ifndef NO_RSA
case SSL_CTRL_SET_TMP_RSA_CB:
{
s->cert->rsa_tmp_cb = (RSA *(*)(SSL *, int, int))fp;
}
break;
#endif
#ifndef NO_DH
case SSL_CTRL_SET_TMP_DH_CB:
{
s->cert->dh_tmp_cb = (DH *(*)(SSL *, int, int))fp;
}
break;
#endif
default:
break;
}
return(ret);
}
long ssl3_ctx_ctrl(SSL_CTX *ctx, int cmd, long larg, char *parg)
{
CERT *cert;
cert=ctx->cert;
switch (cmd)
{
#ifndef NO_RSA
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
#ifndef NO_DH
case SSL_CTRL_SET_TMP_DH:
{
DH *new=NULL,*dh;
int rret=0;
dh=(DH *)parg;
if ( ((new=DHparams_dup(dh)) == NULL) ||
(!DH_generate_key(new)))
{
SSLerr(SSL_F_SSL3_CTX_CTRL,ERR_R_DH_LIB);
if (new != NULL) DH_free(new);
}
else
{
if (cert->dh_tmp != NULL)
DH_free(cert->dh_tmp);
cert->dh_tmp=new;
rret=1;
}
return(rret);
}
case SSL_CTRL_SET_TMP_DH_CB:
{
SSLerr(SSL_F_SSL3_CTX_CTRL, ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED);
return(0);
}
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
long ssl3_ctx_callback_ctrl(SSL_CTX *ctx, int cmd, void (*fp)())
{
CERT *cert;
cert=ctx->cert;
switch (cmd)
{
#ifndef NO_RSA
case SSL_CTRL_SET_TMP_RSA_CB:
{
cert->rsa_tmp_cb = (RSA *(*)(SSL *, int, int))fp;
}
break;
#endif
#ifndef NO_DH
case SSL_CTRL_SET_TMP_DH_CB:
{
cert->dh_tmp_cb = (DH *(*)(SSL *, int, int))fp;
}
break;
#endif
default:
return(0);
}
return(1);
}
SSL_CIPHER *ssl3_get_cipher_by_char(const unsigned char *p)
{
static int init=1;
static SSL_CIPHER *sorted[SSL3_NUM_CIPHERS];
SSL_CIPHER c,*cp= &c,**cpp;
unsigned long id;
int i;
if (init)
{
CRYPTO_w_lock(CRYPTO_LOCK_SSL);
for (i=0; i<SSL3_NUM_CIPHERS; i++)
sorted[i]= &(ssl3_ciphers[i]);
qsort( (char *)sorted,
SSL3_NUM_CIPHERS,sizeof(SSL_CIPHER *),
FP_ICC ssl_cipher_ptr_id_cmp);
CRYPTO_w_unlock(CRYPTO_LOCK_SSL);
init=0;
}
id=0x03000000L|((unsigned long)p[0]<<8L)|(unsigned long)p[1];
c.id=id;
cpp=(SSL_CIPHER **)OBJ_bsearch((char *)&cp,
(char *)sorted,
SSL3_NUM_CIPHERS,sizeof(SSL_CIPHER *),
(int (*)())ssl_cipher_ptr_id_cmp);
if ((cpp == NULL) || !(*cpp)->valid)
return(NULL);
else
return(*cpp);
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
unsigned long alg;
alg=s->s3->tmp.new_cipher->algorithms;
#ifndef NO_DH
if (alg & (SSL_kDHr|SSL_kEDH))
{
# ifndef NO_RSA
p[ret++]=SSL3_CT_RSA_FIXED_DH;
# endif
# ifndef NO_DSA
p[ret++]=SSL3_CT_DSS_FIXED_DH;
# endif
}
if ((s->version == SSL3_VERSION) &&
(alg & (SSL_kEDH|SSL_kDHd|SSL_kDHr)))
{
# ifndef NO_RSA
p[ret++]=SSL3_CT_RSA_EPHEMERAL_DH;
# endif
# ifndef NO_DSA
p[ret++]=SSL3_CT_DSS_EPHEMERAL_DH;
# endif
}
#endif
#ifndef NO_RSA
p[ret++]=SSL3_CT_RSA_SIGN;
#endif
#ifndef NO_DSA
p[ret++]=SSL3_CT_DSS_SIGN;
#endif
return(ret);
}
int ssl3_shutdown(SSL *s)
{
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
}
else if (s->s3->alert_dispatch)
{
#if 1
ssl3_dispatch_alert(s);
#endif
}
else if (!(s->shutdown & SSL_RECEIVED_SHUTDOWN))
{
ssl3_read_bytes(s,0,NULL,0);
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
ret=ssl3_write_bytes(s,SSL3_RT_APPLICATION_DATA,
buf,len);
if (ret <= 0) return(ret);
}
return(ret);
}
int ssl3_read(SSL *s, void *buf, int len)
{
int ret;
clear_sys_error();
if (s->s3->renegotiate) ssl3_renegotiate_check(s);
s->s3->in_read_app_data=1;
ret=ssl3_read_bytes(s,SSL3_RT_APPLICATION_DATA,buf,len);
if ((ret == -1) && (s->s3->in_read_app_data == 0))
{
s->in_handshake++;
ret=ssl3_read_bytes(s,SSL3_RT_APPLICATION_DATA,buf,len);
s->in_handshake--;
}
else
s->s3->in_read_app_data=0;
return(ret);
}
int ssl3_peek(SSL *s, char *buf, int len)
{
SSL3_RECORD *rr;
int n;
rr= &(s->s3->rrec);
if ((rr->length == 0) || (rr->type != SSL3_RT_APPLICATION_DATA))
{
n=ssl3_read(s,buf,1);
if (n <= 0) return(n);
rr->length++;
rr->off--;
}
if ((unsigned int)len > rr->length)
n=rr->length;
else
n=len;
memcpy(buf,&(rr->data[rr->off]),(unsigned int)n);
return(n);
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
