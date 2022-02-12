int SSL_clear(SSL *s)
{
if (s->method == NULL)
{
SSLerr(SSL_F_SSL_CLEAR,SSL_R_NO_METHOD_SPECIFIED);
return(0);
}
if (ssl_clear_bad_session(s))
{
SSL_SESSION_free(s->session);
s->session=NULL;
}
s->error=0;
s->hit=0;
s->shutdown=0;
#if 0
if (s->new_session) return(1);
#else
if (s->new_session)
{
SSLerr(SSL_F_SSL_CLEAR,ERR_R_INTERNAL_ERROR);
return 0;
}
#endif
s->type=0;
s->state=SSL_ST_BEFORE|((s->server)?SSL_ST_ACCEPT:SSL_ST_CONNECT);
s->version=s->method->version;
s->client_version=s->version;
s->rwstate=SSL_NOTHING;
s->rstate=SSL_ST_READ_HEADER;
#if 0
s->read_ahead=s->ctx->read_ahead;
#endif
if (s->init_buf != NULL)
{
BUF_MEM_free(s->init_buf);
s->init_buf=NULL;
}
ssl_clear_cipher_ctx(s);
s->first_packet=0;
#if 1
if (!s->in_handshake && (s->session == NULL) && (s->method != s->ctx->method))
{
s->method->ssl_free(s);
s->method=s->ctx->method;
if (!s->method->ssl_new(s))
return(0);
}
else
#endif
s->method->ssl_clear(s);
return(1);
}
int SSL_CTX_set_ssl_version(SSL_CTX *ctx,SSL_METHOD *meth)
{
STACK_OF(SSL_CIPHER) *sk;
ctx->method=meth;
sk=ssl_create_cipher_list(ctx->method,&(ctx->cipher_list),
&(ctx->cipher_list_by_id),SSL_DEFAULT_CIPHER_LIST);
if ((sk == NULL) || (sk_SSL_CIPHER_num(sk) <= 0))
{
SSLerr(SSL_F_SSL_CTX_SET_SSL_VERSION,SSL_R_SSL_LIBRARY_HAS_NO_CIPHERS);
return(0);
}
return(1);
}
SSL *SSL_new(SSL_CTX *ctx)
{
SSL *s;
if (ctx == NULL)
{
SSLerr(SSL_F_SSL_NEW,SSL_R_NULL_SSL_CTX);
return(NULL);
}
if (ctx->method == NULL)
{
SSLerr(SSL_F_SSL_NEW,SSL_R_SSL_CTX_HAS_NO_DEFAULT_SSL_VERSION);
return(NULL);
}
s=(SSL *)OPENSSL_malloc(sizeof(SSL));
if (s == NULL) goto err;
memset(s,0,sizeof(SSL));
#ifndef OPENSSL_NO_KRB5
s->kssl_ctx = kssl_ctx_new();
#endif
s->options=ctx->options;
s->mode=ctx->mode;
s->max_cert_list=ctx->max_cert_list;
if (ctx->cert != NULL)
{
s->cert = ssl_cert_dup(ctx->cert);
if (s->cert == NULL)
goto err;
}
else
s->cert=NULL;
s->read_ahead=ctx->read_ahead;
s->msg_callback=ctx->msg_callback;
s->msg_callback_arg=ctx->msg_callback_arg;
s->verify_mode=ctx->verify_mode;
#if 0
s->verify_depth=ctx->verify_depth;
#endif
s->sid_ctx_length=ctx->sid_ctx_length;
OPENSSL_assert(s->sid_ctx_length <= sizeof s->sid_ctx);
memcpy(&s->sid_ctx,&ctx->sid_ctx,sizeof(s->sid_ctx));
s->verify_callback=ctx->default_verify_callback;
s->generate_session_id=ctx->generate_session_id;
s->param = X509_VERIFY_PARAM_new();
if (!s->param)
goto err;
X509_VERIFY_PARAM_inherit(s->param, ctx->param);
#if 0
s->purpose = ctx->purpose;
s->trust = ctx->trust;
#endif
s->quiet_shutdown=ctx->quiet_shutdown;
CRYPTO_add(&ctx->references,1,CRYPTO_LOCK_SSL_CTX);
s->ctx=ctx;
s->verify_result=X509_V_OK;
s->method=ctx->method;
if (!s->method->ssl_new(s))
goto err;
s->references=1;
s->server=(ctx->method->ssl_accept == ssl_undefined_function)?0:1;
SSL_clear(s);
CRYPTO_new_ex_data(CRYPTO_EX_INDEX_SSL, s, &s->ex_data);
return(s);
err:
if (s != NULL)
{
if (s->cert != NULL)
ssl_cert_free(s->cert);
if (s->ctx != NULL)
SSL_CTX_free(s->ctx);
OPENSSL_free(s);
}
SSLerr(SSL_F_SSL_NEW,ERR_R_MALLOC_FAILURE);
return(NULL);
}
int SSL_CTX_set_session_id_context(SSL_CTX *ctx,const unsigned char *sid_ctx,
unsigned int sid_ctx_len)
{
if(sid_ctx_len > sizeof ctx->sid_ctx)
{
SSLerr(SSL_F_SSL_CTX_SET_SESSION_ID_CONTEXT,SSL_R_SSL_SESSION_ID_CONTEXT_TOO_LONG);
return 0;
}
ctx->sid_ctx_length=sid_ctx_len;
memcpy(ctx->sid_ctx,sid_ctx,sid_ctx_len);
return 1;
}
int SSL_set_session_id_context(SSL *ssl,const unsigned char *sid_ctx,
unsigned int sid_ctx_len)
{
if(sid_ctx_len > SSL_MAX_SID_CTX_LENGTH)
{
SSLerr(SSL_F_SSL_SET_SESSION_ID_CONTEXT,SSL_R_SSL_SESSION_ID_CONTEXT_TOO_LONG);
return 0;
}
ssl->sid_ctx_length=sid_ctx_len;
memcpy(ssl->sid_ctx,sid_ctx,sid_ctx_len);
return 1;
}
int SSL_CTX_set_generate_session_id(SSL_CTX *ctx, GEN_SESSION_CB cb)
{
CRYPTO_w_lock(CRYPTO_LOCK_SSL_CTX);
ctx->generate_session_id = cb;
CRYPTO_w_unlock(CRYPTO_LOCK_SSL_CTX);
return 1;
}
int SSL_set_generate_session_id(SSL *ssl, GEN_SESSION_CB cb)
{
CRYPTO_w_lock(CRYPTO_LOCK_SSL);
ssl->generate_session_id = cb;
CRYPTO_w_unlock(CRYPTO_LOCK_SSL);
return 1;
}
int SSL_has_matching_session_id(const SSL *ssl, const unsigned char *id,
unsigned int id_len)
{
SSL_SESSION r, *p;
if(id_len > sizeof r.session_id)
return 0;
r.ssl_version = ssl->version;
r.session_id_length = id_len;
memcpy(r.session_id, id, id_len);
if((r.ssl_version == SSL2_VERSION) &&
(id_len < SSL2_SSL_SESSION_ID_LENGTH))
{
memset(r.session_id + id_len, 0,
SSL2_SSL_SESSION_ID_LENGTH - id_len);
r.session_id_length = SSL2_SSL_SESSION_ID_LENGTH;
}
CRYPTO_r_lock(CRYPTO_LOCK_SSL_CTX);
p = (SSL_SESSION *)lh_retrieve(ssl->ctx->sessions, &r);
CRYPTO_r_unlock(CRYPTO_LOCK_SSL_CTX);
return (p != NULL);
}
int SSL_CTX_set_purpose(SSL_CTX *s, int purpose)
{
return X509_VERIFY_PARAM_set_purpose(s->param, purpose);
}
int SSL_set_purpose(SSL *s, int purpose)
{
return X509_VERIFY_PARAM_set_purpose(s->param, purpose);
}
int SSL_CTX_set_trust(SSL_CTX *s, int trust)
{
return X509_VERIFY_PARAM_set_trust(s->param, trust);
}
int SSL_set_trust(SSL *s, int trust)
{
return X509_VERIFY_PARAM_set_trust(s->param, trust);
}
void SSL_free(SSL *s)
{
int i;
if(s == NULL)
return;
i=CRYPTO_add(&s->references,-1,CRYPTO_LOCK_SSL);
#ifdef REF_PRINT
REF_PRINT("SSL",s);
#endif
if (i > 0) return;
#ifdef REF_CHECK
if (i < 0)
{
fprintf(stderr,"SSL_free, bad reference count\n");
abort();
}
#endif
if (s->param)
X509_VERIFY_PARAM_free(s->param);
CRYPTO_free_ex_data(CRYPTO_EX_INDEX_SSL, s, &s->ex_data);
if (s->bbio != NULL)
{
if (s->bbio == s->wbio)
{
s->wbio=BIO_pop(s->wbio);
}
BIO_free(s->bbio);
s->bbio=NULL;
}
if (s->rbio != NULL)
BIO_free_all(s->rbio);
if ((s->wbio != NULL) && (s->wbio != s->rbio))
BIO_free_all(s->wbio);
if (s->init_buf != NULL) BUF_MEM_free(s->init_buf);
if (s->cipher_list != NULL) sk_SSL_CIPHER_free(s->cipher_list);
if (s->cipher_list_by_id != NULL) sk_SSL_CIPHER_free(s->cipher_list_by_id);
if (s->session != NULL)
{
ssl_clear_bad_session(s);
SSL_SESSION_free(s->session);
}
ssl_clear_cipher_ctx(s);
if (s->cert != NULL) ssl_cert_free(s->cert);
if (s->ctx) SSL_CTX_free(s->ctx);
if (s->client_CA != NULL)
sk_X509_NAME_pop_free(s->client_CA,X509_NAME_free);
if (s->method != NULL) s->method->ssl_free(s);
#ifndef OPENSSL_NO_KRB5
if (s->kssl_ctx != NULL)
kssl_ctx_free(s->kssl_ctx);
#endif
OPENSSL_free(s);
}
void SSL_set_bio(SSL *s,BIO *rbio,BIO *wbio)
{
if (s->bbio != NULL)
{
if (s->wbio == s->bbio)
{
s->wbio=s->wbio->next_bio;
s->bbio->next_bio=NULL;
}
}
if ((s->rbio != NULL) && (s->rbio != rbio))
BIO_free_all(s->rbio);
if ((s->wbio != NULL) && (s->wbio != wbio) && (s->rbio != s->wbio))
BIO_free_all(s->wbio);
s->rbio=rbio;
s->wbio=wbio;
}
BIO *SSL_get_rbio(const SSL *s)
{ return(s->rbio); }
BIO *SSL_get_wbio(const SSL *s)
{ return(s->wbio); }
int SSL_get_fd(const SSL *s)
{
return(SSL_get_rfd(s));
}
int SSL_get_rfd(const SSL *s)
{
int ret= -1;
BIO *b,*r;
b=SSL_get_rbio(s);
r=BIO_find_type(b,BIO_TYPE_DESCRIPTOR);
if (r != NULL)
BIO_get_fd(r,&ret);
return(ret);
}
int SSL_get_wfd(const SSL *s)
{
int ret= -1;
BIO *b,*r;
b=SSL_get_wbio(s);
r=BIO_find_type(b,BIO_TYPE_DESCRIPTOR);
if (r != NULL)
BIO_get_fd(r,&ret);
return(ret);
}
int SSL_set_fd(SSL *s,int fd)
{
int ret=0;
BIO *bio=NULL;
bio=BIO_new(BIO_s_socket());
if (bio == NULL)
{
SSLerr(SSL_F_SSL_SET_FD,ERR_R_BUF_LIB);
goto err;
}
BIO_set_fd(bio,fd,BIO_NOCLOSE);
SSL_set_bio(s,bio,bio);
ret=1;
err:
return(ret);
}
int SSL_set_wfd(SSL *s,int fd)
{
int ret=0;
BIO *bio=NULL;
if ((s->rbio == NULL) || (BIO_method_type(s->rbio) != BIO_TYPE_SOCKET)
|| ((int)BIO_get_fd(s->rbio,NULL) != fd))
{
bio=BIO_new(BIO_s_socket());
if (bio == NULL)
{ SSLerr(SSL_F_SSL_SET_WFD,ERR_R_BUF_LIB); goto err; }
BIO_set_fd(bio,fd,BIO_NOCLOSE);
SSL_set_bio(s,SSL_get_rbio(s),bio);
}
else
SSL_set_bio(s,SSL_get_rbio(s),SSL_get_rbio(s));
ret=1;
err:
return(ret);
}
int SSL_set_rfd(SSL *s,int fd)
{
int ret=0;
BIO *bio=NULL;
if ((s->wbio == NULL) || (BIO_method_type(s->wbio) != BIO_TYPE_SOCKET)
|| ((int)BIO_get_fd(s->wbio,NULL) != fd))
{
bio=BIO_new(BIO_s_socket());
if (bio == NULL)
{
SSLerr(SSL_F_SSL_SET_RFD,ERR_R_BUF_LIB);
goto err;
}
BIO_set_fd(bio,fd,BIO_NOCLOSE);
SSL_set_bio(s,bio,SSL_get_wbio(s));
}
else
SSL_set_bio(s,SSL_get_wbio(s),SSL_get_wbio(s));
ret=1;
err:
return(ret);
}
size_t SSL_get_finished(const SSL *s, void *buf, size_t count)
{
size_t ret = 0;
if (s->s3 != NULL)
{
ret = s->s3->tmp.finish_md_len;
if (count > ret)
count = ret;
memcpy(buf, s->s3->tmp.finish_md, count);
}
return ret;
}
size_t SSL_get_peer_finished(const SSL *s, void *buf, size_t count)
{
size_t ret = 0;
if (s->s3 != NULL)
{
ret = s->s3->tmp.peer_finish_md_len;
if (count > ret)
count = ret;
memcpy(buf, s->s3->tmp.peer_finish_md, count);
}
return ret;
}
int SSL_get_verify_mode(const SSL *s)
{
return(s->verify_mode);
}
int SSL_get_verify_depth(const SSL *s)
{
return X509_VERIFY_PARAM_get_depth(s->param);
}
int SSL_CTX_get_verify_mode(const SSL_CTX *ctx)
{
return(ctx->verify_mode);
}
int SSL_CTX_get_verify_depth(const SSL_CTX *ctx)
{
return X509_VERIFY_PARAM_get_depth(ctx->param);
}
void SSL_set_verify(SSL *s,int mode,
int (*callback)(int ok,X509_STORE_CTX *ctx))
{
s->verify_mode=mode;
if (callback != NULL)
s->verify_callback=callback;
}
void SSL_set_verify_depth(SSL *s,int depth)
{
X509_VERIFY_PARAM_set_depth(s->param, depth);
}
void SSL_set_read_ahead(SSL *s,int yes)
{
s->read_ahead=yes;
}
int SSL_get_read_ahead(const SSL *s)
{
return(s->read_ahead);
}
int SSL_pending(const SSL *s)
{
return(s->method->ssl_pending(s));
}
X509 *SSL_get_peer_certificate(const SSL *s)
{
X509 *r;
if ((s == NULL) || (s->session == NULL))
r=NULL;
else
r=s->session->peer;
if (r == NULL) return(r);
CRYPTO_add(&r->references,1,CRYPTO_LOCK_X509);
return(r);
}
int SSL_CTX_check_private_key(const SSL_CTX *ctx)
{
if ( (ctx == NULL) ||
(ctx->cert == NULL) ||
(ctx->cert->key->x509 == NULL))
{
SSLerr(SSL_F_SSL_CTX_CHECK_PRIVATE_KEY,SSL_R_NO_CERTIFICATE_ASSIGNED);
return(0);
}
if (ctx->cert->key->privatekey == NULL)
{
SSLerr(SSL_F_SSL_CTX_CHECK_PRIVATE_KEY,SSL_R_NO_PRIVATE_KEY_ASSIGNED);
return(0);
}
return(X509_check_private_key(ctx->cert->key->x509, ctx->cert->key->privatekey));
}
int SSL_check_private_key(const SSL *ssl)
{
if (ssl == NULL)
{
SSLerr(SSL_F_SSL_CHECK_PRIVATE_KEY,ERR_R_PASSED_NULL_PARAMETER);
return(0);
}
if (ssl->cert == NULL)
{
SSLerr(SSL_F_SSL_CHECK_PRIVATE_KEY,SSL_R_NO_CERTIFICATE_ASSIGNED);
return 0;
}
if (ssl->cert->key->x509 == NULL)
{
SSLerr(SSL_F_SSL_CHECK_PRIVATE_KEY,SSL_R_NO_CERTIFICATE_ASSIGNED);
return(0);
}
if (ssl->cert->key->privatekey == NULL)
{
SSLerr(SSL_F_SSL_CHECK_PRIVATE_KEY,SSL_R_NO_PRIVATE_KEY_ASSIGNED);
return(0);
}
return(X509_check_private_key(ssl->cert->key->x509,
ssl->cert->key->privatekey));
}
int SSL_accept(SSL *s)
{
if (s->handshake_func == 0)
SSL_set_accept_state(s);
return(s->method->ssl_accept(s));
}
int SSL_connect(SSL *s)
{
if (s->handshake_func == 0)
SSL_set_connect_state(s);
return(s->method->ssl_connect(s));
}
long SSL_get_default_timeout(const SSL *s)
{
return(s->method->get_timeout());
}
int SSL_read(SSL *s,void *buf,int num)
{
if (s->handshake_func == 0)
{
SSLerr(SSL_F_SSL_READ, SSL_R_UNINITIALIZED);
return -1;
}
if (s->shutdown & SSL_RECEIVED_SHUTDOWN)
{
s->rwstate=SSL_NOTHING;
return(0);
}
return(s->method->ssl_read(s,buf,num));
}
int SSL_peek(SSL *s,void *buf,int num)
{
if (s->handshake_func == 0)
{
SSLerr(SSL_F_SSL_PEEK, SSL_R_UNINITIALIZED);
return -1;
}
if (s->shutdown & SSL_RECEIVED_SHUTDOWN)
{
return(0);
}
return(s->method->ssl_peek(s,buf,num));
}
int SSL_write(SSL *s,const void *buf,int num)
{
if (s->handshake_func == 0)
{
SSLerr(SSL_F_SSL_WRITE, SSL_R_UNINITIALIZED);
return -1;
}
if (s->shutdown & SSL_SENT_SHUTDOWN)
{
s->rwstate=SSL_NOTHING;
SSLerr(SSL_F_SSL_WRITE,SSL_R_PROTOCOL_IS_SHUTDOWN);
return(-1);
}
return(s->method->ssl_write(s,buf,num));
}
int SSL_shutdown(SSL *s)
{
if (s->handshake_func == 0)
{
SSLerr(SSL_F_SSL_SHUTDOWN, SSL_R_UNINITIALIZED);
return -1;
}
if ((s != NULL) && !SSL_in_init(s))
return(s->method->ssl_shutdown(s));
else
return(1);
}
int SSL_renegotiate(SSL *s)
{
if (s->new_session == 0)
{
s->new_session=1;
}
return(s->method->ssl_renegotiate(s));
}
int SSL_renegotiate_pending(SSL *s)
{
return (s->new_session != 0);
}
long SSL_ctrl(SSL *s,int cmd,long larg,void *parg)
{
long l;
switch (cmd)
{
case SSL_CTRL_GET_READ_AHEAD:
return(s->read_ahead);
case SSL_CTRL_SET_READ_AHEAD:
l=s->read_ahead;
s->read_ahead=larg;
return(l);
case SSL_CTRL_SET_MSG_CALLBACK_ARG:
s->msg_callback_arg = parg;
return 1;
case SSL_CTRL_OPTIONS:
return(s->options|=larg);
case SSL_CTRL_MODE:
return(s->mode|=larg);
case SSL_CTRL_GET_MAX_CERT_LIST:
return(s->max_cert_list);
case SSL_CTRL_SET_MAX_CERT_LIST:
l=s->max_cert_list;
s->max_cert_list=larg;
return(l);
case SSL_CTRL_SET_MTU:
if (SSL_version(s) == DTLS1_VERSION)
{
s->d1->mtu = larg;
return larg;
}
return 0;
default:
return(s->method->ssl_ctrl(s,cmd,larg,parg));
}
}
long SSL_callback_ctrl(SSL *s, int cmd, void (*fp)(void))
{
switch(cmd)
{
case SSL_CTRL_SET_MSG_CALLBACK:
s->msg_callback = (void (*)(int write_p, int version, int content_type, const void *buf, size_t len, SSL *ssl, void *arg))(fp);
return 1;
default:
return(s->method->ssl_callback_ctrl(s,cmd,fp));
}
}
struct lhash_st *SSL_CTX_sessions(SSL_CTX *ctx)
{
return ctx->sessions;
}
long SSL_CTX_ctrl(SSL_CTX *ctx,int cmd,long larg,void *parg)
{
long l;
switch (cmd)
{
case SSL_CTRL_GET_READ_AHEAD:
return(ctx->read_ahead);
case SSL_CTRL_SET_READ_AHEAD:
l=ctx->read_ahead;
ctx->read_ahead=larg;
return(l);
case SSL_CTRL_SET_MSG_CALLBACK_ARG:
ctx->msg_callback_arg = parg;
return 1;
case SSL_CTRL_GET_MAX_CERT_LIST:
return(ctx->max_cert_list);
case SSL_CTRL_SET_MAX_CERT_LIST:
l=ctx->max_cert_list;
ctx->max_cert_list=larg;
return(l);
case SSL_CTRL_SET_SESS_CACHE_SIZE:
l=ctx->session_cache_size;
ctx->session_cache_size=larg;
return(l);
case SSL_CTRL_GET_SESS_CACHE_SIZE:
return(ctx->session_cache_size);
case SSL_CTRL_SET_SESS_CACHE_MODE:
l=ctx->session_cache_mode;
ctx->session_cache_mode=larg;
return(l);
case SSL_CTRL_GET_SESS_CACHE_MODE:
return(ctx->session_cache_mode);
case SSL_CTRL_SESS_NUMBER:
return(ctx->sessions->num_items);
case SSL_CTRL_SESS_CONNECT:
return(ctx->stats.sess_connect);
case SSL_CTRL_SESS_CONNECT_GOOD:
return(ctx->stats.sess_connect_good);
case SSL_CTRL_SESS_CONNECT_RENEGOTIATE:
return(ctx->stats.sess_connect_renegotiate);
case SSL_CTRL_SESS_ACCEPT:
return(ctx->stats.sess_accept);
case SSL_CTRL_SESS_ACCEPT_GOOD:
return(ctx->stats.sess_accept_good);
case SSL_CTRL_SESS_ACCEPT_RENEGOTIATE:
return(ctx->stats.sess_accept_renegotiate);
case SSL_CTRL_SESS_HIT:
return(ctx->stats.sess_hit);
case SSL_CTRL_SESS_CB_HIT:
return(ctx->stats.sess_cb_hit);
case SSL_CTRL_SESS_MISSES:
return(ctx->stats.sess_miss);
case SSL_CTRL_SESS_TIMEOUTS:
return(ctx->stats.sess_timeout);
case SSL_CTRL_SESS_CACHE_FULL:
return(ctx->stats.sess_cache_full);
case SSL_CTRL_OPTIONS:
return(ctx->options|=larg);
case SSL_CTRL_MODE:
return(ctx->mode|=larg);
default:
return(ctx->method->ssl_ctx_ctrl(ctx,cmd,larg,parg));
}
}
long SSL_CTX_callback_ctrl(SSL_CTX *ctx, int cmd, void (*fp)(void))
{
switch(cmd)
{
case SSL_CTRL_SET_MSG_CALLBACK:
ctx->msg_callback = (void (*)(int write_p, int version, int content_type, const void *buf, size_t len, SSL *ssl, void *arg))(fp);
return 1;
default:
return(ctx->method->ssl_ctx_callback_ctrl(ctx,cmd,fp));
}
}
int ssl_cipher_id_cmp(const SSL_CIPHER *a, const SSL_CIPHER *b)
{
long l;
l=a->id-b->id;
if (l == 0L)
return(0);
else
return((l > 0)?1:-1);
}
int ssl_cipher_ptr_id_cmp(const SSL_CIPHER * const *ap,
const SSL_CIPHER * const *bp)
{
long l;
l=(*ap)->id-(*bp)->id;
if (l == 0L)
return(0);
else
return((l > 0)?1:-1);
}
char *SSL_get_cipher_list(const SSL *s,int n)
{
SSL_CIPHER *c;
STACK_OF(SSL_CIPHER) *sk;
if (s == NULL) return(NULL);
sk=SSL_get_ciphers(s);
if ((sk == NULL) || (sk_SSL_CIPHER_num(sk) <= n))
return(NULL);
c=sk_SSL_CIPHER_value(sk,n);
if (c == NULL) return(NULL);
return(c->name);
}
int SSL_CTX_set_cipher_list(SSL_CTX *ctx, const char *str)
{
STACK_OF(SSL_CIPHER) *sk;
sk=ssl_create_cipher_list(ctx->method,&ctx->cipher_list,
&ctx->cipher_list_by_id,str);
if (sk == NULL)
return 0;
else if (sk_SSL_CIPHER_num(sk) == 0)
{
SSLerr(SSL_F_SSL_CTX_SET_CIPHER_LIST, SSL_R_NO_CIPHER_MATCH);
return 0;
}
return 1;
}
int SSL_set_cipher_list(SSL *s,const char *str)
{
STACK_OF(SSL_CIPHER) *sk;
sk=ssl_create_cipher_list(s->ctx->method,&s->cipher_list,
&s->cipher_list_by_id,str);
if (sk == NULL)
return 0;
else if (sk_SSL_CIPHER_num(sk) == 0)
{
SSLerr(SSL_F_SSL_SET_CIPHER_LIST, SSL_R_NO_CIPHER_MATCH);
return 0;
}
return 1;
}
char *SSL_get_shared_ciphers(const SSL *s,char *buf,int len)
{
char *p;
const char *cp;
STACK_OF(SSL_CIPHER) *sk;
SSL_CIPHER *c;
int i;
if ((s->session == NULL) || (s->session->ciphers == NULL) ||
(len < 2))
return(NULL);
p=buf;
sk=s->session->ciphers;
for (i=0; i<sk_SSL_CIPHER_num(sk); i++)
{
len--;
c=sk_SSL_CIPHER_value(sk,i);
for (cp=c->name; *cp; )
{
if (len-- == 0)
{
*p='\0';
return(buf);
}
else
*(p++)= *(cp++);
}
*(p++)=':';
}
p[-1]='\0';
return(buf);
}
long SSL_SESSION_hash(const SSL_SESSION *a)
{
unsigned long l;
l=(unsigned long)
((unsigned int) a->session_id[0] )|
((unsigned int) a->session_id[1]<< 8L)|
((unsigned long)a->session_id[2]<<16L)|
((unsigned long)a->session_id[3]<<24L);
return(l);
}
int SSL_SESSION_cmp(const SSL_SESSION *a,const SSL_SESSION *b)
{
if (a->ssl_version != b->ssl_version)
return(1);
if (a->session_id_length != b->session_id_length)
return(1);
return(memcmp(a->session_id,b->session_id,a->session_id_length));
}
void SSL_CTX_set_default_passwd_cb(SSL_CTX *ctx, pem_password_cb *cb)
{
ctx->default_passwd_callback=cb;
}
void SSL_CTX_set_default_passwd_cb_userdata(SSL_CTX *ctx,void *u)
{
ctx->default_passwd_callback_userdata=u;
}
void SSL_CTX_set_cert_verify_callback(SSL_CTX *ctx, int (*cb)(X509_STORE_CTX *,void *), void *arg)
{
ctx->app_verify_callback=cb;
ctx->app_verify_arg=arg;
}
void SSL_CTX_set_verify(SSL_CTX *ctx,int mode,int (*cb)(int, X509_STORE_CTX *))
{
ctx->verify_mode=mode;
ctx->default_verify_callback=cb;
}
void SSL_CTX_set_verify_depth(SSL_CTX *ctx,int depth)
{
X509_VERIFY_PARAM_set_depth(ctx->param, depth);
}
void ssl_set_cert_masks(CERT *c, SSL_CIPHER *cipher)
{
CERT_PKEY *cpk;
int rsa_enc,rsa_tmp,rsa_sign,dh_tmp,dh_rsa,dh_dsa,dsa_sign;
int rsa_enc_export,dh_rsa_export,dh_dsa_export;
int rsa_tmp_export,dh_tmp_export,kl;
unsigned long mask,emask;
int have_ecc_cert, have_ecdh_tmp, ecdh_ok, ecdsa_ok, ecc_pkey_size;
X509 *x = NULL;
EVP_PKEY *ecc_pkey = NULL;
int signature_nid = 0;
if (c == NULL) return;
kl=SSL_C_EXPORT_PKEYLENGTH(cipher);
#ifndef OPENSSL_NO_RSA
rsa_tmp=(c->rsa_tmp != NULL || c->rsa_tmp_cb != NULL);
rsa_tmp_export=(c->rsa_tmp_cb != NULL ||
(rsa_tmp && RSA_size(c->rsa_tmp)*8 <= kl));
#else
rsa_tmp=rsa_tmp_export=0;
#endif
#ifndef OPENSSL_NO_DH
dh_tmp=(c->dh_tmp != NULL || c->dh_tmp_cb != NULL);
dh_tmp_export=(c->dh_tmp_cb != NULL ||
(dh_tmp && DH_size(c->dh_tmp)*8 <= kl));
#else
dh_tmp=dh_tmp_export=0;
#endif
#ifndef OPENSSL_NO_ECDH
have_ecdh_tmp=(c->ecdh_tmp != NULL || c->ecdh_tmp_cb != NULL);
#endif
cpk= &(c->pkeys[SSL_PKEY_RSA_ENC]);
rsa_enc= (cpk->x509 != NULL && cpk->privatekey != NULL);
rsa_enc_export=(rsa_enc && EVP_PKEY_size(cpk->privatekey)*8 <= kl);
cpk= &(c->pkeys[SSL_PKEY_RSA_SIGN]);
rsa_sign=(cpk->x509 != NULL && cpk->privatekey != NULL);
cpk= &(c->pkeys[SSL_PKEY_DSA_SIGN]);
dsa_sign=(cpk->x509 != NULL && cpk->privatekey != NULL);
cpk= &(c->pkeys[SSL_PKEY_DH_RSA]);
dh_rsa= (cpk->x509 != NULL && cpk->privatekey != NULL);
dh_rsa_export=(dh_rsa && EVP_PKEY_size(cpk->privatekey)*8 <= kl);
cpk= &(c->pkeys[SSL_PKEY_DH_DSA]);
dh_dsa= (cpk->x509 != NULL && cpk->privatekey != NULL);
dh_dsa_export=(dh_dsa && EVP_PKEY_size(cpk->privatekey)*8 <= kl);
cpk= &(c->pkeys[SSL_PKEY_ECC]);
have_ecc_cert= (cpk->x509 != NULL && cpk->privatekey != NULL);
mask=0;
emask=0;
#ifdef CIPHER_DEBUG
printf("rt=%d rte=%d dht=%d re=%d ree=%d rs=%d ds=%d dhr=%d dhd=%d\n",
rsa_tmp,rsa_tmp_export,dh_tmp,
rsa_enc,rsa_enc_export,rsa_sign,dsa_sign,dh_rsa,dh_dsa);
#endif
if (rsa_enc || (rsa_tmp && rsa_sign))
mask|=SSL_kRSA;
if (rsa_enc_export || (rsa_tmp_export && (rsa_sign || rsa_enc)))
emask|=SSL_kRSA;
#if 0
if ( (dh_tmp || dh_rsa || dh_dsa) &&
(rsa_enc || rsa_sign || dsa_sign))
mask|=SSL_kEDH;
if ((dh_tmp_export || dh_rsa_export || dh_dsa_export) &&
(rsa_enc || rsa_sign || dsa_sign))
emask|=SSL_kEDH;
#endif
if (dh_tmp_export)
emask|=SSL_kEDH;
if (dh_tmp)
mask|=SSL_kEDH;
if (dh_rsa) mask|=SSL_kDHr;
if (dh_rsa_export) emask|=SSL_kDHr;
if (dh_dsa) mask|=SSL_kDHd;
if (dh_dsa_export) emask|=SSL_kDHd;
if (rsa_enc || rsa_sign)
{
mask|=SSL_aRSA;
emask|=SSL_aRSA;
}
if (dsa_sign)
{
mask|=SSL_aDSS;
emask|=SSL_aDSS;
}
mask|=SSL_aNULL;
emask|=SSL_aNULL;
#ifndef OPENSSL_NO_KRB5
mask|=SSL_kKRB5|SSL_aKRB5;
emask|=SSL_kKRB5|SSL_aKRB5;
#endif
if (have_ecc_cert)
{
x = (c->pkeys[SSL_PKEY_ECC]).x509;
X509_check_purpose(x, -1, 0);
ecdh_ok = (x->ex_flags & EXFLAG_KUSAGE) ?
(x->ex_kusage & X509v3_KU_KEY_AGREEMENT) : 1;
ecdsa_ok = (x->ex_flags & EXFLAG_KUSAGE) ?
(x->ex_kusage & X509v3_KU_DIGITAL_SIGNATURE) : 1;
ecc_pkey = X509_get_pubkey(x);
ecc_pkey_size = (ecc_pkey != NULL) ?
EVP_PKEY_bits(ecc_pkey) : 0;
EVP_PKEY_free(ecc_pkey);
if ((x->sig_alg) && (x->sig_alg->algorithm))
signature_nid = OBJ_obj2nid(x->sig_alg->algorithm);
#ifndef OPENSSL_NO_ECDH
if (ecdh_ok)
{
if ((signature_nid == NID_md5WithRSAEncryption) ||
(signature_nid == NID_md4WithRSAEncryption) ||
(signature_nid == NID_md2WithRSAEncryption))
{
mask|=SSL_kECDH|SSL_aRSA;
if (ecc_pkey_size <= 163)
emask|=SSL_kECDH|SSL_aRSA;
}
if (signature_nid == NID_ecdsa_with_SHA1)
{
mask|=SSL_kECDH|SSL_aECDSA;
if (ecc_pkey_size <= 163)
emask|=SSL_kECDH|SSL_aECDSA;
}
}
#endif
#ifndef OPENSSL_NO_ECDSA
if (ecdsa_ok)
{
mask|=SSL_aECDSA;
emask|=SSL_aECDSA;
}
#endif
}
#ifndef OPENSSL_NO_ECDH
if (have_ecdh_tmp)
{
mask|=SSL_kECDHE;
emask|=SSL_kECDHE;
}
#endif
c->mask=mask;
c->export_mask=emask;
c->valid=1;
}
int check_srvr_ecc_cert_and_alg(X509 *x, SSL_CIPHER *cs)
{
unsigned long alg = cs->algorithms;
EVP_PKEY *pkey = NULL;
int keysize = 0;
int signature_nid = 0;
if (SSL_C_IS_EXPORT(cs))
{
pkey = X509_get_pubkey(x);
if (pkey == NULL) return 0;
keysize = EVP_PKEY_bits(pkey);
EVP_PKEY_free(pkey);
if (keysize > 163) return 0;
}
X509_check_purpose(x, -1, 0);
if ((x->sig_alg) && (x->sig_alg->algorithm))
signature_nid = OBJ_obj2nid(x->sig_alg->algorithm);
if (alg & SSL_kECDH)
{
if (ku_reject(x, X509v3_KU_KEY_AGREEMENT))
{
return 0;
}
if (alg & SSL_aECDSA)
{
if (signature_nid != NID_ecdsa_with_SHA1)
{
return 0;
}
}
if (alg & SSL_aRSA)
{
if ((signature_nid != NID_md5WithRSAEncryption) &&
(signature_nid != NID_md4WithRSAEncryption) &&
(signature_nid != NID_md2WithRSAEncryption))
{
return 0;
}
}
}
else if (alg & SSL_aECDSA)
{
if (ku_reject(x, X509v3_KU_DIGITAL_SIGNATURE))
{
return 0;
}
}
return 1;
}
X509 *ssl_get_server_send_cert(SSL *s)
{
unsigned long alg,mask,kalg;
CERT *c;
int i,is_export;
c=s->cert;
ssl_set_cert_masks(c, s->s3->tmp.new_cipher);
alg=s->s3->tmp.new_cipher->algorithms;
is_export=SSL_C_IS_EXPORT(s->s3->tmp.new_cipher);
mask=is_export?c->export_mask:c->mask;
kalg=alg&(SSL_MKEY_MASK|SSL_AUTH_MASK);
if (kalg & SSL_kECDH)
{
i=SSL_PKEY_ECC;
}
else if (kalg & SSL_aECDSA)
{
i=SSL_PKEY_ECC;
}
else if (kalg & SSL_kDHr)
i=SSL_PKEY_DH_RSA;
else if (kalg & SSL_kDHd)
i=SSL_PKEY_DH_DSA;
else if (kalg & SSL_aDSS)
i=SSL_PKEY_DSA_SIGN;
else if (kalg & SSL_aRSA)
{
if (c->pkeys[SSL_PKEY_RSA_ENC].x509 == NULL)
i=SSL_PKEY_RSA_SIGN;
else
i=SSL_PKEY_RSA_ENC;
}
else if (kalg & SSL_aKRB5)
{
return(NULL);
}
else
{
SSLerr(SSL_F_SSL_GET_SERVER_SEND_CERT,ERR_R_INTERNAL_ERROR);
return(NULL);
}
if (c->pkeys[i].x509 == NULL) return(NULL);
return(c->pkeys[i].x509);
}
EVP_PKEY *ssl_get_sign_pkey(SSL *s,SSL_CIPHER *cipher)
{
unsigned long alg;
CERT *c;
alg=cipher->algorithms;
c=s->cert;
if ((alg & SSL_aDSS) &&
(c->pkeys[SSL_PKEY_DSA_SIGN].privatekey != NULL))
return(c->pkeys[SSL_PKEY_DSA_SIGN].privatekey);
else if (alg & SSL_aRSA)
{
if (c->pkeys[SSL_PKEY_RSA_SIGN].privatekey != NULL)
return(c->pkeys[SSL_PKEY_RSA_SIGN].privatekey);
else if (c->pkeys[SSL_PKEY_RSA_ENC].privatekey != NULL)
return(c->pkeys[SSL_PKEY_RSA_ENC].privatekey);
else
return(NULL);
}
else if ((alg & SSL_aECDSA) &&
(c->pkeys[SSL_PKEY_ECC].privatekey != NULL))
return(c->pkeys[SSL_PKEY_ECC].privatekey);
else
{
SSLerr(SSL_F_SSL_GET_SIGN_PKEY,ERR_R_INTERNAL_ERROR);
return(NULL);
}
}
void ssl_update_cache(SSL *s,int mode)
{
int i;
if (s->session->session_id_length == 0) return;
i=s->ctx->session_cache_mode;
if ((i & mode) && (!s->hit)
&& ((i & SSL_SESS_CACHE_NO_INTERNAL_STORE)
|| SSL_CTX_add_session(s->ctx,s->session))
&& (s->ctx->new_session_cb != NULL))
{
CRYPTO_add(&s->session->references,1,CRYPTO_LOCK_SSL_SESSION);
if (!s->ctx->new_session_cb(s,s->session))
SSL_SESSION_free(s->session);
}
if ((!(i & SSL_SESS_CACHE_NO_AUTO_CLEAR)) &&
((i & mode) == mode))
{
if ( (((mode & SSL_SESS_CACHE_CLIENT)
?s->ctx->stats.sess_connect_good
:s->ctx->stats.sess_accept_good) & 0xff) == 0xff)
{
SSL_CTX_flush_sessions(s->ctx,time(NULL));
}
}
}
SSL_METHOD *SSL_get_ssl_method(SSL *s)
{
return(s->method);
}
int SSL_set_ssl_method(SSL *s,SSL_METHOD *meth)
{
int conn= -1;
int ret=1;
if (s->method != meth)
{
if (s->handshake_func != NULL)
conn=(s->handshake_func == s->method->ssl_connect);
if (s->method->version == meth->version)
s->method=meth;
else
{
s->method->ssl_free(s);
s->method=meth;
ret=s->method->ssl_new(s);
}
if (conn == 1)
s->handshake_func=meth->ssl_connect;
else if (conn == 0)
s->handshake_func=meth->ssl_accept;
}
return(ret);
}
int SSL_get_error(const SSL *s,int i)
{
int reason;
unsigned long l;
BIO *bio;
if (i > 0) return(SSL_ERROR_NONE);
if ((l=ERR_peek_error()) != 0)
{
if (ERR_GET_LIB(l) == ERR_LIB_SYS)
return(SSL_ERROR_SYSCALL);
else
return(SSL_ERROR_SSL);
}
if ((i < 0) && SSL_want_read(s))
{
bio=SSL_get_rbio(s);
if (BIO_should_read(bio))
return(SSL_ERROR_WANT_READ);
else if (BIO_should_write(bio))
return(SSL_ERROR_WANT_WRITE);
else if (BIO_should_io_special(bio))
{
reason=BIO_get_retry_reason(bio);
if (reason == BIO_RR_CONNECT)
return(SSL_ERROR_WANT_CONNECT);
else if (reason == BIO_RR_ACCEPT)
return(SSL_ERROR_WANT_ACCEPT);
else
return(SSL_ERROR_SYSCALL);
}
}
if ((i < 0) && SSL_want_write(s))
{
bio=SSL_get_wbio(s);
if (BIO_should_write(bio))
return(SSL_ERROR_WANT_WRITE);
else if (BIO_should_read(bio))
return(SSL_ERROR_WANT_READ);
else if (BIO_should_io_special(bio))
{
reason=BIO_get_retry_reason(bio);
if (reason == BIO_RR_CONNECT)
return(SSL_ERROR_WANT_CONNECT);
else if (reason == BIO_RR_ACCEPT)
return(SSL_ERROR_WANT_ACCEPT);
else
return(SSL_ERROR_SYSCALL);
}
}
if ((i < 0) && SSL_want_x509_lookup(s))
{
return(SSL_ERROR_WANT_X509_LOOKUP);
}
if (i == 0)
{
if (s->version == SSL2_VERSION)
{
return(SSL_ERROR_ZERO_RETURN);
}
else
{
if ((s->shutdown & SSL_RECEIVED_SHUTDOWN) &&
(s->s3->warn_alert == SSL_AD_CLOSE_NOTIFY))
return(SSL_ERROR_ZERO_RETURN);
}
}
return(SSL_ERROR_SYSCALL);
}
int SSL_do_handshake(SSL *s)
{
int ret=1;
if (s->handshake_func == NULL)
{
SSLerr(SSL_F_SSL_DO_HANDSHAKE,SSL_R_CONNECTION_TYPE_NOT_SET);
return(-1);
}
s->method->ssl_renegotiate_check(s);
if (SSL_in_init(s) || SSL_in_before(s))
{
ret=s->handshake_func(s);
}
return(ret);
}
void SSL_set_accept_state(SSL *s)
{
s->server=1;
s->shutdown=0;
s->state=SSL_ST_ACCEPT|SSL_ST_BEFORE;
s->handshake_func=s->method->ssl_accept;
ssl_clear_cipher_ctx(s);
}
void SSL_set_connect_state(SSL *s)
{
s->server=0;
s->shutdown=0;
s->state=SSL_ST_CONNECT|SSL_ST_BEFORE;
s->handshake_func=s->method->ssl_connect;
ssl_clear_cipher_ctx(s);
}
int ssl_undefined_function(SSL *s)
{
SSLerr(SSL_F_SSL_UNDEFINED_FUNCTION,ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED);
return(0);
}
int ssl_undefined_void_function(void)
{
SSLerr(SSL_F_SSL_UNDEFINED_VOID_FUNCTION,ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED);
return(0);
}
int ssl_undefined_const_function(const SSL *s)
{
SSLerr(SSL_F_SSL_UNDEFINED_CONST_FUNCTION,ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED);
return(0);
}
SSL_METHOD *ssl_bad_method(int ver)
{
SSLerr(SSL_F_SSL_BAD_METHOD,ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED);
return(NULL);
}
const char *SSL_get_version(const SSL *s)
{
if (s->version == TLS1_VERSION)
return("TLSv1");
else if (s->version == SSL3_VERSION)
return("SSLv3");
else if (s->version == SSL2_VERSION)
return("SSLv2");
else
return("unknown");
}
SSL *SSL_dup(SSL *s)
{
STACK_OF(X509_NAME) *sk;
X509_NAME *xn;
SSL *ret;
int i;
if ((ret=SSL_new(SSL_get_SSL_CTX(s))) == NULL)
return(NULL);
ret->version = s->version;
ret->type = s->type;
ret->method = s->method;
if (s->session != NULL)
{
SSL_copy_session_id(ret,s);
}
else
{
ret->method->ssl_free(ret);
ret->method = s->method;
ret->method->ssl_new(ret);
if (s->cert != NULL)
{
if (ret->cert != NULL)
{
ssl_cert_free(ret->cert);
}
ret->cert = ssl_cert_dup(s->cert);
if (ret->cert == NULL)
goto err;
}
SSL_set_session_id_context(ret,
s->sid_ctx, s->sid_ctx_length);
}
ret->options=s->options;
ret->mode=s->mode;
SSL_set_max_cert_list(ret,SSL_get_max_cert_list(s));
SSL_set_read_ahead(ret,SSL_get_read_ahead(s));
ret->msg_callback = s->msg_callback;
ret->msg_callback_arg = s->msg_callback_arg;
SSL_set_verify(ret,SSL_get_verify_mode(s),
SSL_get_verify_callback(s));
SSL_set_verify_depth(ret,SSL_get_verify_depth(s));
ret->generate_session_id = s->generate_session_id;
SSL_set_info_callback(ret,SSL_get_info_callback(s));
ret->debug=s->debug;
if (!CRYPTO_dup_ex_data(CRYPTO_EX_INDEX_SSL, &ret->ex_data, &s->ex_data))
goto err;
if (s->rbio != NULL)
{
if (!BIO_dup_state(s->rbio,(char *)&ret->rbio))
goto err;
}
if (s->wbio != NULL)
{
if (s->wbio != s->rbio)
{
if (!BIO_dup_state(s->wbio,(char *)&ret->wbio))
goto err;
}
else
ret->wbio=ret->rbio;
}
ret->rwstate = s->rwstate;
ret->in_handshake = s->in_handshake;
ret->handshake_func = s->handshake_func;
ret->server = s->server;
ret->new_session = s->new_session;
ret->quiet_shutdown = s->quiet_shutdown;
ret->shutdown=s->shutdown;
ret->state=s->state;
ret->rstate=s->rstate;
ret->init_num = 0;
ret->hit=s->hit;
X509_VERIFY_PARAM_inherit(ret->param, s->param);
if (s->cipher_list != NULL)
{
if ((ret->cipher_list=sk_SSL_CIPHER_dup(s->cipher_list)) == NULL)
goto err;
}
if (s->cipher_list_by_id != NULL)
if ((ret->cipher_list_by_id=sk_SSL_CIPHER_dup(s->cipher_list_by_id))
== NULL)
goto err;
if (s->client_CA != NULL)
{
if ((sk=sk_X509_NAME_dup(s->client_CA)) == NULL) goto err;
ret->client_CA=sk;
for (i=0; i<sk_X509_NAME_num(sk); i++)
{
xn=sk_X509_NAME_value(sk,i);
if (sk_X509_NAME_set(sk,i,X509_NAME_dup(xn)) == NULL)
{
X509_NAME_free(xn);
goto err;
}
}
}
if (0)
{
err:
if (ret != NULL) SSL_free(ret);
ret=NULL;
}
return(ret);
}
void ssl_clear_cipher_ctx(SSL *s)
{
if (s->enc_read_ctx != NULL)
{
EVP_CIPHER_CTX_cleanup(s->enc_read_ctx);
OPENSSL_free(s->enc_read_ctx);
s->enc_read_ctx=NULL;
}
if (s->enc_write_ctx != NULL)
{
EVP_CIPHER_CTX_cleanup(s->enc_write_ctx);
OPENSSL_free(s->enc_write_ctx);
s->enc_write_ctx=NULL;
}
if (s->expand != NULL)
{
COMP_CTX_free(s->expand);
s->expand=NULL;
}
if (s->compress != NULL)
{
COMP_CTX_free(s->compress);
s->compress=NULL;
}
}
X509 *SSL_get_certificate(const SSL *s)
{
if (s->cert != NULL)
return(s->cert->key->x509);
else
return(NULL);
}
EVP_PKEY *SSL_get_privatekey(SSL *s)
{
if (s->cert != NULL)
return(s->cert->key->privatekey);
else
return(NULL);
}
SSL_CIPHER *SSL_get_current_cipher(const SSL *s)
{
if ((s->session != NULL) && (s->session->cipher != NULL))
return(s->session->cipher);
return(NULL);
}
const COMP_METHOD *SSL_get_current_compression(SSL *s)
{
if (s->compress != NULL)
return(s->compress->meth);
return(NULL);
}
const COMP_METHOD *SSL_get_current_expansion(SSL *s)
{
if (s->expand != NULL)
return(s->expand->meth);
return(NULL);
}
int ssl_init_wbio_buffer(SSL *s,int push)
{
BIO *bbio;
if (s->bbio == NULL)
{
bbio=BIO_new(BIO_f_buffer());
if (bbio == NULL) return(0);
s->bbio=bbio;
}
else
{
bbio=s->bbio;
if (s->bbio == s->wbio)
s->wbio=BIO_pop(s->wbio);
}
(void)BIO_reset(bbio);
if (!BIO_set_read_buffer_size(bbio,1))
{
SSLerr(SSL_F_SSL_INIT_WBIO_BUFFER,ERR_R_BUF_LIB);
return(0);
}
if (push)
{
if (s->wbio != bbio)
s->wbio=BIO_push(bbio,s->wbio);
}
else
{
if (s->wbio == bbio)
s->wbio=BIO_pop(bbio);
}
return(1);
}
void ssl_free_wbio_buffer(SSL *s)
{
if (s->bbio == NULL) return;
if (s->bbio == s->wbio)
{
s->wbio=BIO_pop(s->wbio);
#ifdef REF_CHECK
assert(s->wbio != NULL);
#endif
}
BIO_free(s->bbio);
s->bbio=NULL;
}
void SSL_CTX_set_quiet_shutdown(SSL_CTX *ctx,int mode)
{
ctx->quiet_shutdown=mode;
}
int SSL_CTX_get_quiet_shutdown(const SSL_CTX *ctx)
{
return(ctx->quiet_shutdown);
}
void SSL_set_quiet_shutdown(SSL *s,int mode)
{
s->quiet_shutdown=mode;
}
int SSL_get_quiet_shutdown(const SSL *s)
{
return(s->quiet_shutdown);
}
void SSL_set_shutdown(SSL *s,int mode)
{
s->shutdown=mode;
}
int SSL_get_shutdown(const SSL *s)
{
return(s->shutdown);
}
int SSL_version(const SSL *s)
{
return(s->version);
}
SSL_CTX *SSL_get_SSL_CTX(const SSL *ssl)
{
return(ssl->ctx);
}
int SSL_CTX_set_default_verify_paths(SSL_CTX *ctx)
{
return(X509_STORE_set_default_paths(ctx->cert_store));
}
int SSL_CTX_load_verify_locations(SSL_CTX *ctx, const char *CAfile,
const char *CApath)
{
return(X509_STORE_load_locations(ctx->cert_store,CAfile,CApath));
}
void SSL_set_info_callback(SSL *ssl,
void (*cb)(const SSL *ssl,int type,int val))
{
ssl->info_callback=cb;
}
int SSL_state(const SSL *ssl)
{
return(ssl->state);
}
void SSL_set_verify_result(SSL *ssl,long arg)
{
ssl->verify_result=arg;
}
long SSL_get_verify_result(const SSL *ssl)
{
return(ssl->verify_result);
}
int SSL_get_ex_new_index(long argl,void *argp,CRYPTO_EX_new *new_func,
CRYPTO_EX_dup *dup_func,CRYPTO_EX_free *free_func)
{
return CRYPTO_get_ex_new_index(CRYPTO_EX_INDEX_SSL, argl, argp,
new_func, dup_func, free_func);
}
int SSL_set_ex_data(SSL *s,int idx,void *arg)
{
return(CRYPTO_set_ex_data(&s->ex_data,idx,arg));
}
void *SSL_get_ex_data(const SSL *s,int idx)
{
return(CRYPTO_get_ex_data(&s->ex_data,idx));
}
int SSL_CTX_get_ex_new_index(long argl,void *argp,CRYPTO_EX_new *new_func,
CRYPTO_EX_dup *dup_func,CRYPTO_EX_free *free_func)
{
return CRYPTO_get_ex_new_index(CRYPTO_EX_INDEX_SSL_CTX, argl, argp,
new_func, dup_func, free_func);
}
int SSL_CTX_set_ex_data(SSL_CTX *s,int idx,void *arg)
{
return(CRYPTO_set_ex_data(&s->ex_data,idx,arg));
}
void *SSL_CTX_get_ex_data(const SSL_CTX *s,int idx)
{
return(CRYPTO_get_ex_data(&s->ex_data,idx));
}
int ssl_ok(SSL *s)
{
return(1);
}
X509_STORE *SSL_CTX_get_cert_store(const SSL_CTX *ctx)
{
return(ctx->cert_store);
}
void SSL_CTX_set_cert_store(SSL_CTX *ctx,X509_STORE *store)
{
if (ctx->cert_store != NULL)
X509_STORE_free(ctx->cert_store);
ctx->cert_store=store;
}
int SSL_want(const SSL *s)
{
return(s->rwstate);
}
void SSL_CTX_set_tmp_rsa_callback(SSL_CTX *ctx,RSA *(*cb)(SSL *ssl,
int is_export,
int keylength))
{
SSL_CTX_callback_ctrl(ctx,SSL_CTRL_SET_TMP_RSA_CB,(void (*)(void))cb);
}
void SSL_set_tmp_rsa_callback(SSL *ssl,RSA *(*cb)(SSL *ssl,
int is_export,
int keylength))
{
SSL_callback_ctrl(ssl,SSL_CTRL_SET_TMP_RSA_CB,(void (*)(void))cb);
}
RSA *cb(SSL *ssl,int is_export,int keylength)
{}
void SSL_CTX_set_tmp_dh_callback(SSL_CTX *ctx,DH *(*dh)(SSL *ssl,int is_export,
int keylength))
{
SSL_CTX_callback_ctrl(ctx,SSL_CTRL_SET_TMP_DH_CB,(void (*)(void))dh);
}
void SSL_set_tmp_dh_callback(SSL *ssl,DH *(*dh)(SSL *ssl,int is_export,
int keylength))
{
SSL_callback_ctrl(ssl,SSL_CTRL_SET_TMP_DH_CB,(void (*)(void))dh);
}
void SSL_CTX_set_tmp_ecdh_callback(SSL_CTX *ctx,EC_KEY *(*ecdh)(SSL *ssl,int is_export,
int keylength))
{
SSL_CTX_callback_ctrl(ctx,SSL_CTRL_SET_TMP_ECDH_CB,(void (*)(void))ecdh);
}
void SSL_set_tmp_ecdh_callback(SSL *ssl,EC_KEY *(*ecdh)(SSL *ssl,int is_export,
int keylength))
{
SSL_callback_ctrl(ssl,SSL_CTRL_SET_TMP_ECDH_CB,(void (*)(void))ecdh);
}
void SSL_CTX_set_msg_callback(SSL_CTX *ctx, void (*cb)(int write_p, int version, int content_type, const void *buf, size_t len, SSL *ssl, void *arg))
{
SSL_CTX_callback_ctrl(ctx, SSL_CTRL_SET_MSG_CALLBACK, (void (*)(void))cb);
}
void SSL_set_msg_callback(SSL *ssl, void (*cb)(int write_p, int version, int content_type, const void *buf, size_t len, SSL *ssl, void *arg))
{
SSL_callback_ctrl(ssl, SSL_CTRL_SET_MSG_CALLBACK, (void (*)(void))cb);
}
