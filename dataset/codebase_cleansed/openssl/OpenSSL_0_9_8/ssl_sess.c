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
ss->time=time(NULL);
ss->prev=NULL;
ss->next=NULL;
ss->compress_meth=0;
CRYPTO_new_ex_data(CRYPTO_EX_INDEX_SSL_SESSION, ss, &ss->ex_data);
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
if (s->ctx->session_timeout == 0)
ss->timeout=SSL_get_default_timeout(s);
else
ss->timeout=s->ctx->session_timeout;
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
CRYPTO_r_lock(CRYPTO_LOCK_SSL_CTX);
if(s->generate_session_id)
cb = s->generate_session_id;
else if(s->ctx->generate_session_id)
cb = s->ctx->generate_session_id;
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
int ssl_get_prev_session(SSL *s, unsigned char *session_id, int len)
{
SSL_SESSION *ret=NULL,data;
int fatal = 0;
data.ssl_version=s->version;
data.session_id_length=len;
if (len > SSL_MAX_SSL_SESSION_ID_LENGTH)
goto err;
memcpy(data.session_id,session_id,len);
if (!(s->ctx->session_cache_mode & SSL_SESS_CACHE_NO_INTERNAL_LOOKUP))
{
CRYPTO_r_lock(CRYPTO_LOCK_SSL_CTX);
ret=(SSL_SESSION *)lh_retrieve(s->ctx->sessions,&data);
if (ret != NULL)
CRYPTO_add(&ret->references,1,CRYPTO_LOCK_SSL_SESSION);
CRYPTO_r_unlock(CRYPTO_LOCK_SSL_CTX);
}
if (ret == NULL)
{
int copy=1;
s->ctx->stats.sess_miss++;
ret=NULL;
if (s->ctx->get_session_cb != NULL
&& (ret=s->ctx->get_session_cb(s,session_id,len,&copy))
!= NULL)
{
s->ctx->stats.sess_cb_hit++;
if (copy)
CRYPTO_add(&ret->references,1,CRYPTO_LOCK_SSL_SESSION);
if(!(s->ctx->session_cache_mode & SSL_SESS_CACHE_NO_INTERNAL_STORE))
SSL_CTX_add_session(s->ctx,ret);
}
if (ret == NULL)
goto err;
}
if((s->verify_mode&SSL_VERIFY_PEER)
&& (!s->sid_ctx_length || ret->sid_ctx_length != s->sid_ctx_length
|| memcmp(ret->sid_ctx,s->sid_ctx,ret->sid_ctx_length)))
{
if (s->sid_ctx_length == 0)
{
SSLerr(SSL_F_SSL_GET_PREV_SESSION,SSL_R_SESSION_ID_CONTEXT_UNINITIALIZED);
fatal = 1;
goto err;
}
else
{
#if 0
SSLerr(SSL_F_SSL_GET_PREV_SESSION,SSL_R_ATTEMPT_TO_REUSE_SESSION_IN_DIFFERENT_CONTEXT);
#endif
goto err;
}
}
if (ret->cipher == NULL)
{
unsigned char buf[5],*p;
unsigned long l;
p=buf;
l=ret->cipher_id;
l2n(l,p);
if ((ret->ssl_version>>8) == SSL3_VERSION_MAJOR)
ret->cipher=ssl_get_cipher_by_char(s,&(buf[2]));
else
ret->cipher=ssl_get_cipher_by_char(s,&(buf[1]));
if (ret->cipher == NULL)
goto err;
}
#if 0
CRYPTO_add(&ret->references,1,CRYPTO_LOCK_SSL_SESSION);
#endif
if ((long)(ret->time+ret->timeout) < (long)time(NULL))
{
s->ctx->stats.sess_timeout++;
SSL_CTX_remove_session(s->ctx,ret);
goto err;
}
s->ctx->stats.sess_hit++;
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
s=(SSL_SESSION *)lh_insert(ctx->sessions,c);
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
if ((r = (SSL_SESSION *)lh_retrieve(ctx->sessions,c)) == c)
{
ret=1;
r=(SSL_SESSION *)lh_delete(ctx->sessions,c);
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
OPENSSL_cleanse(ss,sizeof(*ss));
OPENSSL_free(ss);
}
int SSL_set_session(SSL *s, SSL_SESSION *session)
{
int ret=0;
SSL_METHOD *meth;
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
s->kssl_ctx->client_princ = (char *)malloc(session->krb5_client_princ_len + 1);
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
static void timeout(SSL_SESSION *s, TIMEOUT_PARAM *p)
{
if ((p->time == 0) || (p->time > (s->time+s->timeout)))
{
lh_delete(p->cache,s);
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
