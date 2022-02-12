SSL_SESSION *SSL_get_session(const SSL *ssl)
{
return(ssl->session);
}
SSL_SESSION *SSL_get1_session(SSL *ssl)
{
SSL_SESSION *sess;
CRYPTO_w_lock(CRYPTO_LOCK_SSL_SESSION);
sess = ssl->session;
if(sess)
sess->references++;
CRYPTO_w_unlock(CRYPTO_LOCK_SSL_SESSION);
return(sess);
}
int SSL_SESSION_get_ex_new_index(long argl, void *argp, CRYPTO_EX_new *new_func,
CRYPTO_EX_dup *dup_func, CRYPTO_EX_free *free_func)
{
return CRYPTO_get_ex_new_index(CRYPTO_EX_INDEX_SSL_SESSION, argl, argp,
new_func, dup_func, free_func);
}
int SSL_SESSION_set_ex_data(SSL_SESSION *s, int idx, void *arg)
{
return(CRYPTO_set_ex_data(&s->ex_data,idx,arg));
}
void *SSL_SESSION_get_ex_data(const SSL_SESSION *s, int idx)
{
return(CRYPTO_get_ex_data(&s->ex_data,idx));
}
SSL_SESSION *SSL_SESSION_new(void)
{
SSL_SESSION *ss;
ss=(SSL_SESSION *)OPENSSL_malloc(sizeof(SSL_SESSION));
if (ss == NULL)
{
SSLerr(SSL_F_SSL_SESSION_NEW,ERR_R_MALLOC_FAILURE);
return(0);
}
memset(ss,0,sizeof(SSL_SESSION));
ss->verify_result = 1;
ss->references=1;
ss->timeout=60*5+4;
ss->time=(unsigned long)time(NULL);
ss->prev=NULL;
ss->next=NULL;
ss->compress_meth=0;
#ifndef OPENSSL_NO_TLSEXT
ss->tlsext_hostname = NULL;
#ifndef OPENSSL_NO_EC
ss->tlsext_ecpointformatlist_length = 0;
ss->tlsext_ecpointformatlist = NULL;
ss->tlsext_ellipticcurvelist_length = 0;
ss->tlsext_ellipticcurvelist = NULL;
#endif
#endif
CRYPTO_new_ex_data(CRYPTO_EX_INDEX_SSL_SESSION, ss, &ss->ex_data);
#ifndef OPENSSL_NO_PSK
ss->psk_identity_hint=NULL;
ss->psk_identity=NULL;
#endif
return(ss);
}
const unsigned char *SSL_SESSION_get_id(const SSL_SESSION *s, unsigned int *len)
{
if(len)
*len = s->session_id_length;
return s->session_id;
}
static int def_generate_session_id(const SSL *ssl, unsigned char *id,
unsigned int *id_len)
{
unsigned int retry = 0;
do
if (RAND_pseudo_bytes(id, *id_len) <= 0)
return 0;
while(SSL_has_matching_session_id(ssl, id, *id_len) &&
(++retry < MAX_SESS_ID_ATTEMPTS));
if(retry < MAX_SESS_ID_ATTEMPTS)
return 1;
return 0;
}
int ssl_get_new_session(SSL *s, int session)
{
unsigned int tmp;
SSL_SESSION *ss=NULL;
GEN_SESSION_CB cb = def_generate_session_id;
if ((ss=SSL_SESSION_new()) == NULL) return(0);
if (s->session_ctx->session_timeout == 0)
ss->timeout=SSL_get_default_timeout(s);
else
ss->timeout=s->session_ctx->session_timeout;
if (s->session != NULL)
{
SSL_SESSION_free(s->session);
s->session=NULL;
}
if (session)
{
if (s->version == SSL2_VERSION)
{
ss->ssl_version=SSL2_VERSION;
ss->session_id_length=SSL2_SSL_SESSION_ID_LENGTH;
}
else if (s->version == SSL3_VERSION)
{
ss->ssl_version=SSL3_VERSION;
ss->session_id_length=SSL3_SSL_SESSION_ID_LENGTH;
}
else if (s->version == TLS1_VERSION)
{
ss->ssl_version=TLS1_VERSION;
ss->session_id_length=SSL3_SSL_SESSION_ID_LENGTH;
}
else if (s->version == DTLS1_BAD_VER)
{
ss->ssl_version=DTLS1_BAD_VER;
ss->session_id_length=SSL3_SSL_SESSION_ID_LENGTH;
}
else if (s->version == DTLS1_VERSION)
{
ss->ssl_version=DTLS1_VERSION;
ss->session_id_length=SSL3_SSL_SESSION_ID_LENGTH;
}
else
{
SSLerr(SSL_F_SSL_GET_NEW_SESSION,SSL_R_UNSUPPORTED_SSL_VERSION);
SSL_SESSION_free(ss);
return(0);
}
#ifndef OPENSSL_NO_TLSEXT
if (s->tlsext_ticket_expected)
{
ss->session_id_length = 0;
goto sess_id_done;
}
#endif
CRYPTO_r_lock(CRYPTO_LOCK_SSL_CTX);
if(s->generate_session_id)
cb = s->generate_session_id;
else if(s->session_ctx->generate_session_id)
cb = s->session_ctx->generate_session_id;
CRYPTO_r_unlock(CRYPTO_LOCK_SSL_CTX);
tmp = ss->session_id_length;
if(!cb(s, ss->session_id, &tmp))
{
SSLerr(SSL_F_SSL_GET_NEW_SESSION,
SSL_R_SSL_SESSION_ID_CALLBACK_FAILED);
SSL_SESSION_free(ss);
return(0);
}
if(!tmp || (tmp > ss->session_id_length))
{
SSLerr(SSL_F_SSL_GET_NEW_SESSION,
SSL_R_SSL_SESSION_ID_HAS_BAD_LENGTH);
SSL_SESSION_free(ss);
return(0);
}
if((tmp < ss->session_id_length) && (s->version == SSL2_VERSION))
memset(ss->session_id + tmp, 0, ss->session_id_length - tmp);
else
ss->session_id_length = tmp;
if(SSL_has_matching_session_id(s, ss->session_id,
ss->session_id_length))
{
SSLerr(SSL_F_SSL_GET_NEW_SESSION,
SSL_R_SSL_SESSION_ID_CONFLICT);
SSL_SESSION_free(ss);
return(0);
}
#ifndef OPENSSL_NO_TLSEXT
sess_id_done:
if (s->tlsext_hostname) {
ss->tlsext_hostname = BUF_strdup(s->tlsext_hostname);
if (ss->tlsext_hostname == NULL) {
SSLerr(SSL_F_SSL_GET_NEW_SESSION, ERR_R_INTERNAL_ERROR);
SSL_SESSION_free(ss);
return 0;
}
}
#ifndef OPENSSL_NO_EC
if (s->tlsext_ecpointformatlist)
{
if (ss->tlsext_ecpointformatlist != NULL) OPENSSL_free(ss->tlsext_ecpointformatlist);
if ((ss->tlsext_ecpointformatlist = OPENSSL_malloc(s->tlsext_ecpointformatlist_length)) == NULL)
{
SSLerr(SSL_F_SSL_GET_NEW_SESSION, ERR_R_MALLOC_FAILURE);
SSL_SESSION_free(ss);
return 0;
}
ss->tlsext_ecpointformatlist_length = s->tlsext_ecpointformatlist_length;
memcpy(ss->tlsext_ecpointformatlist, s->tlsext_ecpointformatlist, s->tlsext_ecpointformatlist_length);
}
if (s->tlsext_ellipticcurvelist)
{
if (ss->tlsext_ellipticcurvelist != NULL) OPENSSL_free(ss->tlsext_ellipticcurvelist);
if ((ss->tlsext_ellipticcurvelist = OPENSSL_malloc(s->tlsext_ellipticcurvelist_length)) == NULL)
{
SSLerr(SSL_F_SSL_GET_NEW_SESSION, ERR_R_MALLOC_FAILURE);
SSL_SESSION_free(ss);
return 0;
}
ss->tlsext_ellipticcurvelist_length = s->tlsext_ellipticcurvelist_length;
memcpy(ss->tlsext_ellipticcurvelist, s->tlsext_ellipticcurvelist, s->tlsext_ellipticcurvelist_length);
}
#endif
#endif
}
else
{
ss->session_id_length=0;
}
if (s->sid_ctx_length > sizeof ss->sid_ctx)
{
SSLerr(SSL_F_SSL_GET_NEW_SESSION, ERR_R_INTERNAL_ERROR);
SSL_SESSION_free(ss);
return 0;
}
memcpy(ss->sid_ctx,s->sid_ctx,s->sid_ctx_length);
ss->sid_ctx_length=s->sid_ctx_length;
s->session=ss;
ss->ssl_version=s->version;
ss->verify_result = X509_V_OK;
return(1);
}
int ssl_get_prev_session(SSL *s, unsigned char *session_id, int len,
const unsigned char *limit)
{
SSL_SESSION *ret=NULL;
int fatal = 0;
#ifndef OPENSSL_NO_TLSEXT
int r;
#endif
if (len > SSL_MAX_SSL_SESSION_ID_LENGTH)
goto err;
#ifndef OPENSSL_NO_TLSEXT
r = tls1_process_ticket(s, session_id, len, limit, &ret);
if (r == -1)
{
fatal = 1;
goto err;
}
else if (r == 0 || (!ret && !len))
goto err;
else if (!ret && !(s->session_ctx->session_cache_mode & SSL_SESS_CACHE_NO_INTERNAL_LOOKUP))
#else
if (len == 0)
goto err;
if (!(s->session_ctx->session_cache_mode & SSL_SESS_CACHE_NO_INTERNAL_LOOKUP))
#endif
{
SSL_SESSION data;
data.ssl_version=s->version;
data.session_id_length=len;
if (len == 0)
return 0;
memcpy(data.session_id,session_id,len);
CRYPTO_r_lock(CRYPTO_LOCK_SSL_CTX);
ret=lh_SSL_SESSION_retrieve(s->session_ctx->sessions,&data);
if (ret != NULL)
CRYPTO_add(&ret->references,1,CRYPTO_LOCK_SSL_SESSION);
CRYPTO_r_unlock(CRYPTO_LOCK_SSL_CTX);
}
if (ret == NULL)
{
int copy=1;
s->session_ctx->stats.sess_miss++;
ret=NULL;
if (s->session_ctx->get_session_cb != NULL
&& (ret=s->session_ctx->get_session_cb(s,session_id,len,&copy))
!= NULL)
{
s->session_ctx->stats.sess_cb_hit++;
if (copy)
CRYPTO_add(&ret->references,1,CRYPTO_LOCK_SSL_SESSION);
if(!(s->session_ctx->session_cache_mode & SSL_SESS_CACHE_NO_INTERNAL_STORE))
SSL_CTX_add_session(s->session_ctx,ret);
}
if (ret == NULL)
goto err;
}
if (ret->sid_ctx_length != s->sid_ctx_length
|| memcmp(ret->sid_ctx,s->sid_ctx,ret->sid_ctx_length))
{
#if 0
SSLerr(SSL_F_SSL_GET_PREV_SESSION,SSL_R_ATTEMPT_TO_REUSE_SESSION_IN_DIFFERENT_CONTEXT);
#endif
goto err;
}
if((s->verify_mode & SSL_VERIFY_PEER) && s->sid_ctx_length == 0)
{
SSLerr(SSL_F_SSL_GET_PREV_SESSION,SSL_R_SESSION_ID_CONTEXT_UNINITIALIZED);
fatal = 1;
goto err;
}
if (ret->cipher == NULL)
{
unsigned char buf[5],*p;
unsigned long l;
p=buf;
l=ret->cipher_id;
l2n(l,p);
if ((ret->ssl_version>>8) >= SSL3_VERSION_MAJOR)
ret->cipher=ssl_get_cipher_by_char(s,&(buf[2]));
else
ret->cipher=ssl_get_cipher_by_char(s,&(buf[1]));
if (ret->cipher == NULL)
goto err;
}
#if 0
CRYPTO_add(&ret->references,1,CRYPTO_LOCK_SSL_SESSION);
#endif
if (ret->timeout < (long)(time(NULL) - ret->time))
{
s->session_ctx->stats.sess_timeout++;
SSL_CTX_remove_session(s->session_ctx,ret);
goto err;
}
s->session_ctx->stats.sess_hit++;
if (s->session != NULL)
SSL_SESSION_free(s->session);
s->session=ret;
s->verify_result = s->session->verify_result;
return(1);
err:
if (ret != NULL)
SSL_SESSION_free(ret);
if (fatal)
return -1;
else
return 0;
}
int SSL_CTX_add_session(SSL_CTX *ctx, SSL_SESSION *c)
{
int ret=0;
SSL_SESSION *s;
CRYPTO_add(&c->references,1,CRYPTO_LOCK_SSL_SESSION);
CRYPTO_w_lock(CRYPTO_LOCK_SSL_CTX);
s=lh_SSL_SESSION_insert(ctx->sessions,c);
if (s != NULL && s != c)
{
SSL_SESSION_list_remove(ctx,s);
SSL_SESSION_free(s);
s = NULL;
}
if (s == NULL)
SSL_SESSION_list_add(ctx,c);
if (s != NULL)
{
SSL_SESSION_free(s);
ret=0;
}
else
{
ret=1;
if (SSL_CTX_sess_get_cache_size(ctx) > 0)
{
while (SSL_CTX_sess_number(ctx) >
SSL_CTX_sess_get_cache_size(ctx))
{
if (!remove_session_lock(ctx,
ctx->session_cache_tail, 0))
break;
else
ctx->stats.sess_cache_full++;
}
}
}
CRYPTO_w_unlock(CRYPTO_LOCK_SSL_CTX);
return(ret);
}
int SSL_CTX_remove_session(SSL_CTX *ctx, SSL_SESSION *c)
{
return remove_session_lock(ctx, c, 1);
}
static int remove_session_lock(SSL_CTX *ctx, SSL_SESSION *c, int lck)
{
SSL_SESSION *r;
int ret=0;
if ((c != NULL) && (c->session_id_length != 0))
{
if(lck) CRYPTO_w_lock(CRYPTO_LOCK_SSL_CTX);
if ((r = lh_SSL_SESSION_retrieve(ctx->sessions,c)) == c)
{
ret=1;
r=lh_SSL_SESSION_delete(ctx->sessions,c);
SSL_SESSION_list_remove(ctx,c);
}
if(lck) CRYPTO_w_unlock(CRYPTO_LOCK_SSL_CTX);
if (ret)
{
r->not_resumable=1;
if (ctx->remove_session_cb != NULL)
ctx->remove_session_cb(ctx,r);
SSL_SESSION_free(r);
}
}
else
ret=0;
return(ret);
}
void SSL_SESSION_free(SSL_SESSION *ss)
{
int i;
if(ss == NULL)
return;
i=CRYPTO_add(&ss->references,-1,CRYPTO_LOCK_SSL_SESSION);
#ifdef REF_PRINT
REF_PRINT("SSL_SESSION",ss);
#endif
if (i > 0) return;
#ifdef REF_CHECK
if (i < 0)
{
fprintf(stderr,"SSL_SESSION_free, bad reference count\n");
abort();
}
#endif
CRYPTO_free_ex_data(CRYPTO_EX_INDEX_SSL_SESSION, ss, &ss->ex_data);
OPENSSL_cleanse(ss->key_arg,sizeof ss->key_arg);
OPENSSL_cleanse(ss->master_key,sizeof ss->master_key);
OPENSSL_cleanse(ss->session_id,sizeof ss->session_id);
if (ss->sess_cert != NULL) ssl_sess_cert_free(ss->sess_cert);
if (ss->peer != NULL) X509_free(ss->peer);
if (ss->ciphers != NULL) sk_SSL_CIPHER_free(ss->ciphers);
#ifndef OPENSSL_NO_TLSEXT
if (ss->tlsext_hostname != NULL) OPENSSL_free(ss->tlsext_hostname);
if (ss->tlsext_tick != NULL) OPENSSL_free(ss->tlsext_tick);
#ifndef OPENSSL_NO_EC
ss->tlsext_ecpointformatlist_length = 0;
if (ss->tlsext_ecpointformatlist != NULL) OPENSSL_free(ss->tlsext_ecpointformatlist);
ss->tlsext_ellipticcurvelist_length = 0;
if (ss->tlsext_ellipticcurvelist != NULL) OPENSSL_free(ss->tlsext_ellipticcurvelist);
#endif
#endif
#ifndef OPENSSL_NO_PSK
if (ss->psk_identity_hint != NULL)
OPENSSL_free(ss->psk_identity_hint);
if (ss->psk_identity != NULL)
OPENSSL_free(ss->psk_identity);
#endif
OPENSSL_cleanse(ss,sizeof(*ss));
OPENSSL_free(ss);
}
int SSL_set_session(SSL *s, SSL_SESSION *session)
{
int ret=0;
const SSL_METHOD *meth;
if (session != NULL)
{
meth=s->ctx->method->get_ssl_method(session->ssl_version);
if (meth == NULL)
meth=s->method->get_ssl_method(session->ssl_version);
if (meth == NULL)
{
SSLerr(SSL_F_SSL_SET_SESSION,SSL_R_UNABLE_TO_FIND_SSL_METHOD);
return(0);
}
if (meth != s->method)
{
if (!SSL_set_ssl_method(s,meth))
return(0);
if (s->ctx->session_timeout == 0)
session->timeout=SSL_get_default_timeout(s);
else
session->timeout=s->ctx->session_timeout;
}
#ifndef OPENSSL_NO_KRB5
if (s->kssl_ctx && !s->kssl_ctx->client_princ &&
session->krb5_client_princ_len > 0)
{
s->kssl_ctx->client_princ = (char *)OPENSSL_malloc(session->krb5_client_princ_len + 1);
memcpy(s->kssl_ctx->client_princ,session->krb5_client_princ,
session->krb5_client_princ_len);
s->kssl_ctx->client_princ[session->krb5_client_princ_len] = '\0';
}
#endif
CRYPTO_add(&session->references,1,CRYPTO_LOCK_SSL_SESSION);
if (s->session != NULL)
SSL_SESSION_free(s->session);
s->session=session;
s->verify_result = s->session->verify_result;
ret=1;
}
else
{
if (s->session != NULL)
{
SSL_SESSION_free(s->session);
s->session=NULL;
}
meth=s->ctx->method;
if (meth != s->method)
{
if (!SSL_set_ssl_method(s,meth))
return(0);
}
ret=1;
}
return(ret);
}
long SSL_SESSION_set_timeout(SSL_SESSION *s, long t)
{
if (s == NULL) return(0);
s->timeout=t;
return(1);
}
long SSL_SESSION_get_timeout(const SSL_SESSION *s)
{
if (s == NULL) return(0);
return(s->timeout);
}
long SSL_SESSION_get_time(const SSL_SESSION *s)
{
if (s == NULL) return(0);
return(s->time);
}
long SSL_SESSION_set_time(SSL_SESSION *s, long t)
{
if (s == NULL) return(0);
s->time=t;
return(t);
}
long SSL_CTX_set_timeout(SSL_CTX *s, long t)
{
long l;
if (s == NULL) return(0);
l=s->session_timeout;
s->session_timeout=t;
return(l);
}
long SSL_CTX_get_timeout(const SSL_CTX *s)
{
if (s == NULL) return(0);
return(s->session_timeout);
}
int SSL_set_session_ticket_ext_cb(SSL *s, tls_session_ticket_ext_cb_fn cb,
void *arg)
{
if (s == NULL) return(0);
s->tls_session_ticket_ext_cb = cb;
s->tls_session_ticket_ext_cb_arg = arg;
return(1);
}
int SSL_set_session_ticket_ext(SSL *s, void *ext_data, int ext_len)
{
if (s->version >= TLS1_VERSION)
{
if (s->tlsext_session_ticket)
{
OPENSSL_free(s->tlsext_session_ticket);
s->tlsext_session_ticket = NULL;
}
s->tlsext_session_ticket = OPENSSL_malloc(sizeof(TLS_SESSION_TICKET_EXT) + ext_len);
if (!s->tlsext_session_ticket)
{
SSLerr(SSL_F_SSL_SET_SESSION_TICKET_EXT, ERR_R_MALLOC_FAILURE);
return 0;
}
if (ext_data)
{
s->tlsext_session_ticket->length = ext_len;
s->tlsext_session_ticket->data = s->tlsext_session_ticket + 1;
memcpy(s->tlsext_session_ticket->data, ext_data, ext_len);
}
else
{
s->tlsext_session_ticket->length = 0;
s->tlsext_session_ticket->data = NULL;
}
return 1;
}
return 0;
}
static void timeout_doall_arg(SSL_SESSION *s, TIMEOUT_PARAM *p)
{
if ((p->time == 0) || (p->time > (s->time+s->timeout)))
{
(void)lh_SSL_SESSION_delete(p->cache,s);
SSL_SESSION_list_remove(p->ctx,s);
s->not_resumable=1;
if (p->ctx->remove_session_cb != NULL)
p->ctx->remove_session_cb(p->ctx,s);
SSL_SESSION_free(s);
}
}
static void SSL_SESSION_list_remove(SSL_CTX *ctx, SSL_SESSION *s)
{
if ((s->next == NULL) || (s->prev == NULL)) return;
if (s->next == (SSL_SESSION *)&(ctx->session_cache_tail))
{
if (s->prev == (SSL_SESSION *)&(ctx->session_cache_head))
{
ctx->session_cache_head=NULL;
ctx->session_cache_tail=NULL;
}
else
{
ctx->session_cache_tail=s->prev;
s->prev->next=(SSL_SESSION *)&(ctx->session_cache_tail);
}
}
else
{
if (s->prev == (SSL_SESSION *)&(ctx->session_cache_head))
{
ctx->session_cache_head=s->next;
s->next->prev=(SSL_SESSION *)&(ctx->session_cache_head);
}
else
{
s->next->prev=s->prev;
s->prev->next=s->next;
}
}
s->prev=s->next=NULL;
}
static void SSL_SESSION_list_add(SSL_CTX *ctx, SSL_SESSION *s)
{
if ((s->next != NULL) && (s->prev != NULL))
SSL_SESSION_list_remove(ctx,s);
if (ctx->session_cache_head == NULL)
{
ctx->session_cache_head=s;
ctx->session_cache_tail=s;
s->prev=(SSL_SESSION *)&(ctx->session_cache_head);
s->next=(SSL_SESSION *)&(ctx->session_cache_tail);
}
else
{
s->next=ctx->session_cache_head;
s->next->prev=s;
s->prev=(SSL_SESSION *)&(ctx->session_cache_head);
ctx->session_cache_head=s;
}
}
void SSL_CTX_sess_set_new_cb(SSL_CTX *ctx,
int (*cb)(struct ssl_st *ssl,SSL_SESSION *sess))
{
ctx->new_session_cb=cb;
}
void SSL_CTX_sess_set_remove_cb(SSL_CTX *ctx,
void (*cb)(SSL_CTX *ctx,SSL_SESSION *sess))
{
ctx->remove_session_cb=cb;
}
void SSL_CTX_sess_set_get_cb(SSL_CTX *ctx,
SSL_SESSION *(*cb)(struct ssl_st *ssl,
unsigned char *data,int len,int *copy))
{
ctx->get_session_cb=cb;
}
void SSL_CTX_set_info_callback(SSL_CTX *ctx,
void (*cb)(const SSL *ssl,int type,int val))
{
ctx->info_callback=cb;
}
void SSL_CTX_set_client_cert_cb(SSL_CTX *ctx,
int (*cb)(SSL *ssl, X509 **x509, EVP_PKEY **pkey))
{
ctx->client_cert_cb=cb;
}
int SSL_CTX_set_client_cert_engine(SSL_CTX *ctx, ENGINE *e)
{
if (!ENGINE_init(e))
{
SSLerr(SSL_F_SSL_CTX_SET_CLIENT_CERT_ENGINE, ERR_R_ENGINE_LIB);
return 0;
}
if(!ENGINE_get_ssl_client_cert_function(e))
{
SSLerr(SSL_F_SSL_CTX_SET_CLIENT_CERT_ENGINE, SSL_R_NO_CLIENT_CERT_METHOD);
ENGINE_finish(e);
return 0;
}
ctx->client_cert_engine = e;
return 1;
}
void SSL_CTX_set_cookie_generate_cb(SSL_CTX *ctx,
int (*cb)(SSL *ssl, unsigned char *cookie, unsigned int *cookie_len))
{
ctx->app_gen_cookie_cb=cb;
}
void SSL_CTX_set_cookie_verify_cb(SSL_CTX *ctx,
int (*cb)(SSL *ssl, unsigned char *cookie, unsigned int cookie_len))
{
ctx->app_verify_cookie_cb=cb;
}
