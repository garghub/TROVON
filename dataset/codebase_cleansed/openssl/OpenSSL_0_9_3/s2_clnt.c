static SSL_METHOD *ssl2_get_client_method(int ver)
{
if (ver == SSL2_VERSION)
return(SSLv2_client_method());
else
return(NULL);
}
SSL_METHOD *SSLv2_client_method(void)
{
static int init=1;
static SSL_METHOD SSLv2_client_data;
if (init)
{
memcpy((char *)&SSLv2_client_data,(char *)sslv2_base_method(),
sizeof(SSL_METHOD));
SSLv2_client_data.ssl_connect=ssl2_connect;
SSLv2_client_data.get_ssl_method=ssl2_get_client_method;
init=0;
}
return(&SSLv2_client_data);
}
int ssl2_connect(SSL *s)
{
unsigned long l=time(NULL);
BUF_MEM *buf=NULL;
int ret= -1;
void (*cb)()=NULL;
int new_state,state;
RAND_seed(&l,sizeof(l));
ERR_clear_error();
clear_sys_error();
if (s->info_callback != NULL)
cb=s->info_callback;
else if (s->ctx->info_callback != NULL)
cb=s->ctx->info_callback;
if (!SSL_in_init(s) || SSL_in_before(s)) SSL_clear(s);
s->in_handshake++;
for (;;)
{
state=s->state;
switch (s->state)
{
case SSL_ST_BEFORE:
case SSL_ST_CONNECT:
case SSL_ST_BEFORE|SSL_ST_CONNECT:
case SSL_ST_OK|SSL_ST_CONNECT:
s->server=0;
if (cb != NULL) cb(s,SSL_CB_HANDSHAKE_START,1);
s->version=SSL2_VERSION;
s->type=SSL_ST_CONNECT;
buf=s->init_buf;
if ((buf == NULL) && ((buf=BUF_MEM_new()) == NULL))
{
ret= -1;
goto end;
}
if (!BUF_MEM_grow(buf,
SSL2_MAX_RECORD_LENGTH_3_BYTE_HEADER))
{
ret= -1;
goto end;
}
s->init_buf=buf;
s->init_num=0;
s->state=SSL2_ST_SEND_CLIENT_HELLO_A;
s->ctx->stats.sess_connect++;
s->handshake_func=ssl2_connect;
BREAK;
case SSL2_ST_SEND_CLIENT_HELLO_A:
case SSL2_ST_SEND_CLIENT_HELLO_B:
s->shutdown=0;
ret=client_hello(s);
if (ret <= 0) goto end;
s->init_num=0;
s->state=SSL2_ST_GET_SERVER_HELLO_A;
BREAK;
case SSL2_ST_GET_SERVER_HELLO_A:
case SSL2_ST_GET_SERVER_HELLO_B:
ret=get_server_hello(s);
if (ret <= 0) goto end;
s->init_num=0;
if (!s->hit)
{
s->state=SSL2_ST_SEND_CLIENT_MASTER_KEY_A;
BREAK;
}
else
{
s->state=SSL2_ST_CLIENT_START_ENCRYPTION;
break;
}
case SSL2_ST_SEND_CLIENT_MASTER_KEY_A:
case SSL2_ST_SEND_CLIENT_MASTER_KEY_B:
ret=client_master_key(s);
if (ret <= 0) goto end;
s->init_num=0;
s->state=SSL2_ST_CLIENT_START_ENCRYPTION;
break;
case SSL2_ST_CLIENT_START_ENCRYPTION:
if (!ssl2_enc_init(s,1))
{
ret= -1;
goto end;
}
s->s2->clear_text=0;
s->state=SSL2_ST_SEND_CLIENT_FINISHED_A;
break;
case SSL2_ST_SEND_CLIENT_FINISHED_A:
case SSL2_ST_SEND_CLIENT_FINISHED_B:
ret=client_finished(s);
if (ret <= 0) goto end;
s->init_num=0;
s->state=SSL2_ST_GET_SERVER_VERIFY_A;
break;
case SSL2_ST_GET_SERVER_VERIFY_A:
case SSL2_ST_GET_SERVER_VERIFY_B:
ret=get_server_verify(s);
if (ret <= 0) goto end;
s->init_num=0;
s->state=SSL2_ST_GET_SERVER_FINISHED_A;
break;
case SSL2_ST_GET_SERVER_FINISHED_A:
case SSL2_ST_GET_SERVER_FINISHED_B:
ret=get_server_finished(s);
if (ret <= 0) goto end;
break;
case SSL2_ST_SEND_CLIENT_CERTIFICATE_A:
case SSL2_ST_SEND_CLIENT_CERTIFICATE_B:
case SSL2_ST_SEND_CLIENT_CERTIFICATE_C:
case SSL2_ST_SEND_CLIENT_CERTIFICATE_D:
case SSL2_ST_X509_GET_CLIENT_CERTIFICATE:
ret=client_certificate(s);
if (ret <= 0) goto end;
s->init_num=0;
s->state=SSL2_ST_GET_SERVER_FINISHED_A;
break;
case SSL_ST_OK:
if (s->init_buf != NULL)
{
BUF_MEM_free(s->init_buf);
s->init_buf=NULL;
}
s->init_num=0;
ssl_update_cache(s,SSL_SESS_CACHE_CLIENT);
if (s->hit) s->ctx->stats.sess_hit++;
ret=1;
s->ctx->stats.sess_connect_good++;
if (cb != NULL) cb(s,SSL_CB_HANDSHAKE_DONE,1);
goto end;
default:
SSLerr(SSL_F_SSL2_CONNECT,SSL_R_UNKNOWN_STATE);
return(-1);
}
if ((cb != NULL) && (s->state != state))
{
new_state=s->state;
s->state=state;
cb(s,SSL_CB_CONNECT_LOOP,1);
s->state=new_state;
}
}
end:
s->in_handshake--;
if (cb != NULL)
cb(s,SSL_CB_CONNECT_EXIT,ret);
return(ret);
}
static int get_server_hello(SSL *s)
{
unsigned char *buf;
unsigned char *p;
int i,j;
STACK_OF(SSL_CIPHER) *sk=NULL,*cl;
buf=(unsigned char *)s->init_buf->data;
p=buf;
if (s->state == SSL2_ST_GET_SERVER_HELLO_A)
{
i=ssl2_read(s,(char *)&(buf[s->init_num]),11-s->init_num);
if (i < (11-s->init_num))
return(ssl2_part_read(s,SSL_F_GET_SERVER_HELLO,i));
if (*(p++) != SSL2_MT_SERVER_HELLO)
{
if (p[-1] != SSL2_MT_ERROR)
{
ssl2_return_error(s,SSL2_PE_UNDEFINED_ERROR);
SSLerr(SSL_F_GET_SERVER_HELLO,
SSL_R_READ_WRONG_PACKET_TYPE);
}
else
SSLerr(SSL_F_GET_SERVER_HELLO,
SSL_R_PEER_ERROR);
return(-1);
}
s->hit=(*(p++))?1:0;
s->s2->tmp.cert_type= *(p++);
n2s(p,i);
if (i < s->version) s->version=i;
n2s(p,i); s->s2->tmp.cert_length=i;
n2s(p,i); s->s2->tmp.csl=i;
n2s(p,i); s->s2->tmp.conn_id_length=i;
s->state=SSL2_ST_GET_SERVER_HELLO_B;
s->init_num=0;
}
j=s->s2->tmp.cert_length+s->s2->tmp.csl+s->s2->tmp.conn_id_length
- s->init_num;
i=ssl2_read(s,(char *)&(buf[s->init_num]),j);
if (i != j) return(ssl2_part_read(s,SSL_F_GET_SERVER_HELLO,i));
p=buf;
if (s->hit)
{
if (s->s2->tmp.cert_length != 0)
{
SSLerr(SSL_F_GET_SERVER_HELLO,SSL_R_REUSE_CERT_LENGTH_NOT_ZERO);
return(-1);
}
if (s->s2->tmp.cert_type != 0)
{
if (!(s->options &
SSL_OP_SSLREF2_REUSE_CERT_TYPE_BUG))
{
SSLerr(SSL_F_GET_SERVER_HELLO,SSL_R_REUSE_CERT_TYPE_NOT_ZERO);
return(-1);
}
}
if (s->s2->tmp.csl != 0)
{
SSLerr(SSL_F_GET_SERVER_HELLO,SSL_R_REUSE_CIPHER_LIST_NOT_ZERO);
return(-1);
}
}
else
{
#ifdef undef
memset(s->session->session_id,0,
SSL_MAX_SSL_SESSION_ID_LENGTH_IN_BYTES);
s->session->session_id_length=0;
*/
#endif
if (s->session->session_id_length > 0)
{
if (!ssl_get_new_session(s,0))
{
ssl2_return_error(s,SSL2_PE_UNDEFINED_ERROR);
return(-1);
}
}
if (ssl2_set_certificate(s,s->s2->tmp.cert_type,
s->s2->tmp.cert_length,p) <= 0)
{
ssl2_return_error(s,SSL2_PE_BAD_CERTIFICATE);
return(-1);
}
p+=s->s2->tmp.cert_length;
if (s->s2->tmp.csl == 0)
{
ssl2_return_error(s,SSL2_PE_NO_CIPHER);
SSLerr(SSL_F_GET_SERVER_HELLO,SSL_R_NO_CIPHER_LIST);
return(-1);
}
sk=ssl_bytes_to_cipher_list(s,p,s->s2->tmp.csl,
&s->session->ciphers);
p+=s->s2->tmp.csl;
if (sk == NULL)
{
ssl2_return_error(s,SSL2_PE_UNDEFINED_ERROR);
SSLerr(SSL_F_GET_SERVER_HELLO,ERR_R_MALLOC_FAILURE);
return(-1);
}
sk_SSL_CIPHER_set_cmp_func(sk,ssl_cipher_ptr_id_cmp);
cl=ssl_get_ciphers_by_id(s);
for (i=0; i<sk_SSL_CIPHER_num(cl); i++)
{
if (sk_SSL_CIPHER_find(sk,
sk_SSL_CIPHER_value(cl,i)) >= 0)
break;
}
if (i >= sk_SSL_CIPHER_num(cl))
{
ssl2_return_error(s,SSL2_PE_NO_CIPHER);
SSLerr(SSL_F_GET_SERVER_HELLO,SSL_R_NO_CIPHER_MATCH);
return(-1);
}
s->session->cipher=sk_SSL_CIPHER_value(cl,i);
}
if (s->session->peer != NULL)
X509_free(s->session->peer);
#if 0
CRYPTO_w_lock(CRYPTO_LOCK_X509);
s->session->peer=s->session->sess_cert->key->x509;
s->session->peer->references++;
CRYPTO_w_unlock(CRYPTO_LOCK_X509);
#else
s->session->peer = s->session->sess_cert->peer_key->x509;
CRYPTO_add(&s->session->peer->references, 1, CRYPTO_LOCK_X509);
#endif
s->s2->conn_id_length=s->s2->tmp.conn_id_length;
memcpy(s->s2->conn_id,p,s->s2->tmp.conn_id_length);
return(1);
}
static int client_hello(SSL *s)
{
unsigned char *buf;
unsigned char *p,*d;
int i,n,j;
buf=(unsigned char *)s->init_buf->data;
if (s->state == SSL2_ST_SEND_CLIENT_HELLO_A)
{
if ((s->session == NULL) ||
(s->session->ssl_version != s->version))
{
if (!ssl_get_new_session(s,0))
{
ssl2_return_error(s,SSL2_PE_UNDEFINED_ERROR);
return(-1);
}
}
p=buf;
d=p+9;
*(p++)=SSL2_MT_CLIENT_HELLO;
s2n(SSL2_VERSION,p);
n=j=0;
n=ssl_cipher_list_to_bytes(s,SSL_get_ciphers(s),d);
d+=n;
if (n == 0)
{
SSLerr(SSL_F_CLIENT_HELLO,SSL_R_NO_CIPHERS_AVAILABLE);
return(-1);
}
s2n(n,p);
if ((s->session->session_id_length > 0) &&
(s->session->session_id_length <=
SSL2_MAX_SSL_SESSION_ID_LENGTH))
{
i=s->session->session_id_length;
s2n(i,p);
memcpy(d,s->session->session_id,(unsigned int)i);
d+=i;
}
else
{
s2n(0,p);
}
s->s2->challenge_length=SSL2_CHALLENGE_LENGTH;
s2n(SSL2_CHALLENGE_LENGTH,p);
RAND_bytes(s->s2->challenge,SSL2_CHALLENGE_LENGTH);
memcpy(d,s->s2->challenge,SSL2_CHALLENGE_LENGTH);
d+=SSL2_CHALLENGE_LENGTH;
s->state=SSL2_ST_SEND_CLIENT_HELLO_B;
s->init_num=d-buf;
s->init_off=0;
}
return(ssl2_do_write(s));
}
static int client_master_key(SSL *s)
{
unsigned char *buf;
unsigned char *p,*d;
int clear,enc,karg,i;
SSL_SESSION *sess;
const EVP_CIPHER *c;
const EVP_MD *md;
buf=(unsigned char *)s->init_buf->data;
if (s->state == SSL2_ST_SEND_CLIENT_MASTER_KEY_A)
{
if (!ssl_cipher_get_evp(s->session,&c,&md,NULL))
{
ssl2_return_error(s,SSL2_PE_NO_CIPHER);
SSLerr(SSL_F_CLIENT_MASTER_KEY,SSL_R_PROBLEMS_MAPPING_CIPHER_FUNCTIONS);
return(-1);
}
sess=s->session;
p=buf;
d=p+10;
*(p++)=SSL2_MT_CLIENT_MASTER_KEY;
i=ssl_put_cipher_by_char(s,sess->cipher,p);
p+=i;
i=EVP_CIPHER_iv_length(c);
sess->key_arg_length=i;
if (i > 0) RAND_bytes(sess->key_arg,i);
i=EVP_CIPHER_key_length(c);
sess->master_key_length=i;
if (i > 0) RAND_bytes(sess->master_key,i);
if (sess->cipher->algorithm2 & SSL2_CF_8_BYTE_ENC)
enc=8;
else if (SSL_C_IS_EXPORT(sess->cipher))
enc=5;
else
enc=i;
if (i < enc)
{
ssl2_return_error(s,SSL2_PE_UNDEFINED_ERROR);
SSLerr(SSL_F_CLIENT_MASTER_KEY,SSL_R_CIPHER_TABLE_SRC_ERROR);
return(-1);
}
clear=i-enc;
s2n(clear,p);
memcpy(d,sess->master_key,(unsigned int)clear);
d+=clear;
enc=ssl_rsa_public_encrypt(sess->sess_cert,enc,
&(sess->master_key[clear]),d,
(s->s2->ssl2_rollback)?RSA_SSLV23_PADDING:RSA_PKCS1_PADDING);
if (enc <= 0)
{
ssl2_return_error(s,SSL2_PE_UNDEFINED_ERROR);
SSLerr(SSL_F_CLIENT_MASTER_KEY,SSL_R_PUBLIC_KEY_ENCRYPT_ERROR);
return(-1);
}
#ifdef PKCS1_CHECK
if (s->options & SSL_OP_PKCS1_CHECK_1) d[1]++;
if (s->options & SSL_OP_PKCS1_CHECK_2)
sess->master_key[clear]++;
#endif
s2n(enc,p);
d+=enc;
karg=sess->key_arg_length;
s2n(karg,p);
memcpy(d,sess->key_arg,(unsigned int)karg);
d+=karg;
s->state=SSL2_ST_SEND_CLIENT_MASTER_KEY_B;
s->init_num=d-buf;
s->init_off=0;
}
return(ssl2_do_write(s));
}
static int client_finished(SSL *s)
{
unsigned char *p;
if (s->state == SSL2_ST_SEND_CLIENT_FINISHED_A)
{
p=(unsigned char *)s->init_buf->data;
*(p++)=SSL2_MT_CLIENT_FINISHED;
memcpy(p,s->s2->conn_id,(unsigned int)s->s2->conn_id_length);
s->state=SSL2_ST_SEND_CLIENT_FINISHED_B;
s->init_num=s->s2->conn_id_length+1;
s->init_off=0;
}
return(ssl2_do_write(s));
}
static int client_certificate(SSL *s)
{
unsigned char *buf;
unsigned char *p,*d;
int i;
unsigned int n;
int cert_ch_len=0;
unsigned char *cert_ch;
buf=(unsigned char *)s->init_buf->data;
cert_ch= &(buf[2]);
if (s->state == SSL2_ST_SEND_CLIENT_CERTIFICATE_A)
{
i=ssl2_read(s,(char *)&(buf[s->init_num]),
SSL2_MAX_CERT_CHALLENGE_LENGTH+1-s->init_num);
if (i<(SSL2_MIN_CERT_CHALLENGE_LENGTH+1-s->init_num))
return(ssl2_part_read(s,SSL_F_CLIENT_CERTIFICATE,i));
if (buf[1] != SSL2_AT_MD5_WITH_RSA_ENCRYPTION)
{
ssl2_return_error(s,SSL2_PE_UNSUPPORTED_CERTIFICATE_TYPE);
SSLerr(SSL_F_CLIENT_CERTIFICATE,SSL_R_BAD_AUTHENTICATION_TYPE);
return(-1);
}
cert_ch_len=i-1;
if ((s->cert == NULL) ||
(s->cert->key->x509 == NULL) ||
(s->cert->key->privatekey == NULL))
{
s->state=SSL2_ST_X509_GET_CLIENT_CERTIFICATE;
}
else
s->state=SSL2_ST_SEND_CLIENT_CERTIFICATE_C;
}
if (s->state == SSL2_ST_X509_GET_CLIENT_CERTIFICATE)
{
X509 *x509=NULL;
EVP_PKEY *pkey=NULL;
i=0;
if (s->ctx->client_cert_cb != NULL)
{
i=s->ctx->client_cert_cb(s,&(x509),&(pkey));
}
if (i < 0)
{
s->rwstate=SSL_X509_LOOKUP;
return(-1);
}
s->rwstate=SSL_NOTHING;
if ((i == 1) && (pkey != NULL) && (x509 != NULL))
{
s->state=SSL2_ST_SEND_CLIENT_CERTIFICATE_C;
if ( !SSL_use_certificate(s,x509) ||
!SSL_use_PrivateKey(s,pkey))
{
i=0;
}
X509_free(x509);
EVP_PKEY_free(pkey);
}
else if (i == 1)
{
if (x509 != NULL) X509_free(x509);
if (pkey != NULL) EVP_PKEY_free(pkey);
SSLerr(SSL_F_CLIENT_CERTIFICATE,SSL_R_BAD_DATA_RETURNED_BY_CALLBACK);
i=0;
}
if (i == 0)
{
s->state=SSL2_ST_SEND_CLIENT_CERTIFICATE_B;
p=buf;
*(p++)=SSL2_MT_ERROR;
s2n(SSL2_PE_NO_CERTIFICATE,p);
s->init_off=0;
s->init_num=3;
}
}
if (s->state == SSL2_ST_SEND_CLIENT_CERTIFICATE_B)
{
return(ssl2_do_write(s));
}
if (s->state == SSL2_ST_SEND_CLIENT_CERTIFICATE_C)
{
EVP_MD_CTX ctx;
p=buf;
EVP_SignInit(&ctx,s->ctx->rsa_md5);
EVP_SignUpdate(&ctx,s->s2->key_material,
(unsigned int)s->s2->key_material_length);
EVP_SignUpdate(&ctx,cert_ch,(unsigned int)cert_ch_len);
n=i2d_X509(s->session->sess_cert->peer_key->x509,&p);
EVP_SignUpdate(&ctx,buf,(unsigned int)n);
p=buf;
d=p+6;
*(p++)=SSL2_MT_CLIENT_CERTIFICATE;
*(p++)=SSL2_CT_X509_CERTIFICATE;
n=i2d_X509(s->cert->key->x509,&d);
s2n(n,p);
if (!EVP_SignFinal(&ctx,d,&n,s->cert->key->privatekey))
{
}
memset(&ctx,0,sizeof(ctx));
s2n(n,p);
d+=n;
s->state=SSL2_ST_SEND_CLIENT_CERTIFICATE_D;
s->init_num=d-buf;
s->init_off=0;
}
return(ssl2_do_write(s));
}
static int get_server_verify(SSL *s)
{
unsigned char *p;
int i;
p=(unsigned char *)s->init_buf->data;
if (s->state == SSL2_ST_GET_SERVER_VERIFY_A)
{
i=ssl2_read(s,(char *)&(p[s->init_num]),1-s->init_num);
if (i < (1-s->init_num))
return(ssl2_part_read(s,SSL_F_GET_SERVER_VERIFY,i));
s->state= SSL2_ST_GET_SERVER_VERIFY_B;
s->init_num=0;
if (*p != SSL2_MT_SERVER_VERIFY)
{
if (p[0] != SSL2_MT_ERROR)
{
ssl2_return_error(s,SSL2_PE_UNDEFINED_ERROR);
SSLerr(SSL_F_GET_SERVER_VERIFY,
SSL_R_READ_WRONG_PACKET_TYPE);
}
else
SSLerr(SSL_F_GET_SERVER_VERIFY,
SSL_R_PEER_ERROR);
return(-1);
}
}
p=(unsigned char *)s->init_buf->data;
i=ssl2_read(s,(char *)&(p[s->init_num]),
(unsigned int)s->s2->challenge_length-s->init_num);
if (i < ((int)s->s2->challenge_length-s->init_num))
return(ssl2_part_read(s,SSL_F_GET_SERVER_VERIFY,i));
if (memcmp(p,s->s2->challenge,(unsigned int)s->s2->challenge_length) != 0)
{
ssl2_return_error(s,SSL2_PE_UNDEFINED_ERROR);
SSLerr(SSL_F_GET_SERVER_VERIFY,SSL_R_CHALLENGE_IS_DIFFERENT);
return(-1);
}
return(1);
}
static int get_server_finished(SSL *s)
{
unsigned char *buf;
unsigned char *p;
int i;
buf=(unsigned char *)s->init_buf->data;
p=buf;
if (s->state == SSL2_ST_GET_SERVER_FINISHED_A)
{
i=ssl2_read(s,(char *)&(buf[s->init_num]),1-s->init_num);
if (i < (1-s->init_num))
return(ssl2_part_read(s,SSL_F_GET_SERVER_FINISHED,i));
s->init_num=i;
if (*p == SSL2_MT_REQUEST_CERTIFICATE)
{
s->state=SSL2_ST_SEND_CLIENT_CERTIFICATE_A;
return(1);
}
else if (*p != SSL2_MT_SERVER_FINISHED)
{
if (p[0] != SSL2_MT_ERROR)
{
ssl2_return_error(s,SSL2_PE_UNDEFINED_ERROR);
SSLerr(SSL_F_GET_SERVER_FINISHED,SSL_R_READ_WRONG_PACKET_TYPE);
}
else
SSLerr(SSL_F_GET_SERVER_FINISHED,SSL_R_PEER_ERROR);
return(-1);
}
s->state=SSL_ST_OK;
s->init_num=0;
}
i=ssl2_read(s,(char *)&(buf[s->init_num]),
SSL2_SSL_SESSION_ID_LENGTH-s->init_num);
if (i < (SSL2_SSL_SESSION_ID_LENGTH-s->init_num))
return(ssl2_part_read(s,SSL_F_GET_SERVER_FINISHED,i));
if (!s->hit)
{
s->session->session_id_length=SSL2_SSL_SESSION_ID_LENGTH;
memcpy(s->session->session_id,p,SSL2_SSL_SESSION_ID_LENGTH);
}
else
{
if (!(s->options & SSL_OP_MICROSOFT_SESS_ID_BUG))
{
if (memcmp(buf,s->session->session_id,
(unsigned int)s->session->session_id_length) != 0)
{
ssl2_return_error(s,SSL2_PE_UNDEFINED_ERROR);
SSLerr(SSL_F_GET_SERVER_FINISHED,SSL_R_SSL_SESSION_ID_IS_DIFFERENT);
return(-1);
}
}
}
return(1);
}
int ssl2_set_certificate(SSL *s, int type, int len, unsigned char *data)
{
STACK_OF(X509) *sk=NULL;
EVP_PKEY *pkey=NULL;
SESS_CERT *sc=NULL;
int i;
X509 *x509=NULL;
int ret=0;
x509=d2i_X509(NULL,&data,(long)len);
if (x509 == NULL)
{
SSLerr(SSL_F_SSL2_SET_CERTIFICATE,ERR_R_X509_LIB);
goto err;
}
if ((sk=sk_X509_new_null()) == NULL || !sk_X509_push(sk,x509))
{
SSLerr(SSL_F_SSL2_SET_CERTIFICATE,ERR_R_MALLOC_FAILURE);
goto err;
}
i=ssl_verify_cert_chain(s,sk);
if ((s->verify_mode != SSL_VERIFY_NONE) && (!i))
{
SSLerr(SSL_F_SSL2_SET_CERTIFICATE,SSL_R_CERTIFICATE_VERIFY_FAILED);
goto err;
}
sc=ssl_sess_cert_new();
if (sc == NULL)
{
ret= -1;
goto err;
}
if (s->session->sess_cert) ssl_sess_cert_free(s->session->sess_cert);
s->session->sess_cert=sc;
sc->peer_pkeys[SSL_PKEY_RSA_ENC].x509=x509;
sc->peer_key= &(sc->peer_pkeys[SSL_PKEY_RSA_ENC]);
pkey=X509_get_pubkey(x509);
x509=NULL;
if (pkey == NULL)
{
SSLerr(SSL_F_SSL2_SET_CERTIFICATE,SSL_R_UNABLE_TO_EXTRACT_PUBLIC_KEY);
goto err;
}
if (pkey->type != EVP_PKEY_RSA)
{
SSLerr(SSL_F_SSL2_SET_CERTIFICATE,SSL_R_PUBLIC_KEY_NOT_RSA);
goto err;
}
if (!ssl_set_peer_cert_type(sc,SSL2_CT_X509_CERTIFICATE))
goto err;
ret=1;
err:
sk_X509_free(sk);
X509_free(x509);
EVP_PKEY_free(pkey);
return(ret);
}
static int ssl_rsa_public_encrypt(SESS_CERT *sc, int len, unsigned char *from,
unsigned char *to, int padding)
{
EVP_PKEY *pkey=NULL;
int i= -1;
if ((sc == NULL) || (sc->peer_key->x509 == NULL) ||
((pkey=X509_get_pubkey(sc->peer_key->x509)) == NULL))
{
SSLerr(SSL_F_SSL_RSA_PUBLIC_ENCRYPT,SSL_R_NO_PUBLICKEY);
return(-1);
}
if (pkey->type != EVP_PKEY_RSA)
{
SSLerr(SSL_F_SSL_RSA_PUBLIC_ENCRYPT,SSL_R_PUBLIC_KEY_IS_NOT_RSA);
goto end;
}
i=RSA_public_encrypt(len,from,to,pkey->pkey.rsa,padding);
if (i < 0)
SSLerr(SSL_F_SSL_RSA_PUBLIC_ENCRYPT,ERR_R_RSA_LIB);
end:
EVP_PKEY_free(pkey);
return(i);
}
