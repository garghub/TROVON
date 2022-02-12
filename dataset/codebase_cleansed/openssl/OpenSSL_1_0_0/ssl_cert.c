int SSL_get_ex_data_X509_STORE_CTX_idx(void)
{
static volatile int ssl_x509_store_ctx_idx= -1;
int got_write_lock = 0;
CRYPTO_r_lock(CRYPTO_LOCK_SSL_CTX);
if (ssl_x509_store_ctx_idx < 0)
{
CRYPTO_r_unlock(CRYPTO_LOCK_SSL_CTX);
CRYPTO_w_lock(CRYPTO_LOCK_SSL_CTX);
got_write_lock = 1;
if (ssl_x509_store_ctx_idx < 0)
{
ssl_x509_store_ctx_idx=X509_STORE_CTX_get_ex_new_index(
0,"SSL for verify callback",NULL,NULL,NULL);
}
}
if (got_write_lock)
CRYPTO_w_unlock(CRYPTO_LOCK_SSL_CTX);
else
CRYPTO_r_unlock(CRYPTO_LOCK_SSL_CTX);
return ssl_x509_store_ctx_idx;
}
CERT *ssl_cert_new(void)
{
CERT *ret;
ret=(CERT *)OPENSSL_malloc(sizeof(CERT));
if (ret == NULL)
{
SSLerr(SSL_F_SSL_CERT_NEW,ERR_R_MALLOC_FAILURE);
return(NULL);
}
memset(ret,0,sizeof(CERT));
ret->key= &(ret->pkeys[SSL_PKEY_RSA_ENC]);
ret->references=1;
return(ret);
}
CERT *ssl_cert_dup(CERT *cert)
{
CERT *ret;
int i;
ret = (CERT *)OPENSSL_malloc(sizeof(CERT));
if (ret == NULL)
{
SSLerr(SSL_F_SSL_CERT_DUP, ERR_R_MALLOC_FAILURE);
return(NULL);
}
memset(ret, 0, sizeof(CERT));
ret->key = &ret->pkeys[cert->key - &cert->pkeys[0]];
ret->valid = cert->valid;
ret->mask_k = cert->mask_k;
ret->mask_a = cert->mask_a;
ret->export_mask_k = cert->export_mask_k;
ret->export_mask_a = cert->export_mask_a;
#ifndef OPENSSL_NO_RSA
if (cert->rsa_tmp != NULL)
{
RSA_up_ref(cert->rsa_tmp);
ret->rsa_tmp = cert->rsa_tmp;
}
ret->rsa_tmp_cb = cert->rsa_tmp_cb;
#endif
#ifndef OPENSSL_NO_DH
if (cert->dh_tmp != NULL)
{
ret->dh_tmp = DHparams_dup(cert->dh_tmp);
if (ret->dh_tmp == NULL)
{
SSLerr(SSL_F_SSL_CERT_DUP, ERR_R_DH_LIB);
goto err;
}
if (cert->dh_tmp->priv_key)
{
BIGNUM *b = BN_dup(cert->dh_tmp->priv_key);
if (!b)
{
SSLerr(SSL_F_SSL_CERT_DUP, ERR_R_BN_LIB);
goto err;
}
ret->dh_tmp->priv_key = b;
}
if (cert->dh_tmp->pub_key)
{
BIGNUM *b = BN_dup(cert->dh_tmp->pub_key);
if (!b)
{
SSLerr(SSL_F_SSL_CERT_DUP, ERR_R_BN_LIB);
goto err;
}
ret->dh_tmp->pub_key = b;
}
}
ret->dh_tmp_cb = cert->dh_tmp_cb;
#endif
#ifndef OPENSSL_NO_ECDH
if (cert->ecdh_tmp)
{
ret->ecdh_tmp = EC_KEY_dup(cert->ecdh_tmp);
if (ret->ecdh_tmp == NULL)
{
SSLerr(SSL_F_SSL_CERT_DUP, ERR_R_EC_LIB);
goto err;
}
}
ret->ecdh_tmp_cb = cert->ecdh_tmp_cb;
#endif
for (i = 0; i < SSL_PKEY_NUM; i++)
{
if (cert->pkeys[i].x509 != NULL)
{
ret->pkeys[i].x509 = cert->pkeys[i].x509;
CRYPTO_add(&ret->pkeys[i].x509->references, 1,
CRYPTO_LOCK_X509);
}
if (cert->pkeys[i].privatekey != NULL)
{
ret->pkeys[i].privatekey = cert->pkeys[i].privatekey;
CRYPTO_add(&ret->pkeys[i].privatekey->references, 1,
CRYPTO_LOCK_EVP_PKEY);
switch(i)
{
case SSL_PKEY_RSA_ENC:
case SSL_PKEY_RSA_SIGN:
break;
case SSL_PKEY_DSA_SIGN:
break;
case SSL_PKEY_DH_RSA:
case SSL_PKEY_DH_DSA:
break;
case SSL_PKEY_ECC:
break;
default:
SSLerr(SSL_F_SSL_CERT_DUP, SSL_R_LIBRARY_BUG);
}
}
}
ret->references=1;
return(ret);
#if !defined(OPENSSL_NO_DH) || !defined(OPENSSL_NO_ECDH)
err:
#endif
#ifndef OPENSSL_NO_RSA
if (ret->rsa_tmp != NULL)
RSA_free(ret->rsa_tmp);
#endif
#ifndef OPENSSL_NO_DH
if (ret->dh_tmp != NULL)
DH_free(ret->dh_tmp);
#endif
#ifndef OPENSSL_NO_ECDH
if (ret->ecdh_tmp != NULL)
EC_KEY_free(ret->ecdh_tmp);
#endif
for (i = 0; i < SSL_PKEY_NUM; i++)
{
if (ret->pkeys[i].x509 != NULL)
X509_free(ret->pkeys[i].x509);
if (ret->pkeys[i].privatekey != NULL)
EVP_PKEY_free(ret->pkeys[i].privatekey);
}
return NULL;
}
void ssl_cert_free(CERT *c)
{
int i;
if(c == NULL)
return;
i=CRYPTO_add(&c->references,-1,CRYPTO_LOCK_SSL_CERT);
#ifdef REF_PRINT
REF_PRINT("CERT",c);
#endif
if (i > 0) return;
#ifdef REF_CHECK
if (i < 0)
{
fprintf(stderr,"ssl_cert_free, bad reference count\n");
abort();
}
#endif
#ifndef OPENSSL_NO_RSA
if (c->rsa_tmp) RSA_free(c->rsa_tmp);
#endif
#ifndef OPENSSL_NO_DH
if (c->dh_tmp) DH_free(c->dh_tmp);
#endif
#ifndef OPENSSL_NO_ECDH
if (c->ecdh_tmp) EC_KEY_free(c->ecdh_tmp);
#endif
for (i=0; i<SSL_PKEY_NUM; i++)
{
if (c->pkeys[i].x509 != NULL)
X509_free(c->pkeys[i].x509);
if (c->pkeys[i].privatekey != NULL)
EVP_PKEY_free(c->pkeys[i].privatekey);
#if 0
if (c->pkeys[i].publickey != NULL)
EVP_PKEY_free(c->pkeys[i].publickey);
#endif
}
OPENSSL_free(c);
}
int ssl_cert_inst(CERT **o)
{
if (o == NULL)
{
SSLerr(SSL_F_SSL_CERT_INST, ERR_R_PASSED_NULL_PARAMETER);
return(0);
}
if (*o == NULL)
{
if ((*o = ssl_cert_new()) == NULL)
{
SSLerr(SSL_F_SSL_CERT_INST, ERR_R_MALLOC_FAILURE);
return(0);
}
}
return(1);
}
SESS_CERT *ssl_sess_cert_new(void)
{
SESS_CERT *ret;
ret = OPENSSL_malloc(sizeof *ret);
if (ret == NULL)
{
SSLerr(SSL_F_SSL_SESS_CERT_NEW, ERR_R_MALLOC_FAILURE);
return NULL;
}
memset(ret, 0 ,sizeof *ret);
ret->peer_key = &(ret->peer_pkeys[SSL_PKEY_RSA_ENC]);
ret->references = 1;
return ret;
}
void ssl_sess_cert_free(SESS_CERT *sc)
{
int i;
if (sc == NULL)
return;
i = CRYPTO_add(&sc->references, -1, CRYPTO_LOCK_SSL_SESS_CERT);
#ifdef REF_PRINT
REF_PRINT("SESS_CERT", sc);
#endif
if (i > 0)
return;
#ifdef REF_CHECK
if (i < 0)
{
fprintf(stderr,"ssl_sess_cert_free, bad reference count\n");
abort();
}
#endif
if (sc->cert_chain != NULL)
sk_X509_pop_free(sc->cert_chain, X509_free);
for (i = 0; i < SSL_PKEY_NUM; i++)
{
if (sc->peer_pkeys[i].x509 != NULL)
X509_free(sc->peer_pkeys[i].x509);
#if 0
if (sc->peer_pkeys[i].privatekey != NULL)
EVP_PKEY_free(sc->peer_pkeys[i].privatekey);
#endif
}
#ifndef OPENSSL_NO_RSA
if (sc->peer_rsa_tmp != NULL)
RSA_free(sc->peer_rsa_tmp);
#endif
#ifndef OPENSSL_NO_DH
if (sc->peer_dh_tmp != NULL)
DH_free(sc->peer_dh_tmp);
#endif
#ifndef OPENSSL_NO_ECDH
if (sc->peer_ecdh_tmp != NULL)
EC_KEY_free(sc->peer_ecdh_tmp);
#endif
OPENSSL_free(sc);
}
int ssl_set_peer_cert_type(SESS_CERT *sc,int type)
{
sc->peer_cert_type = type;
return(1);
}
int SSL_add_client_CA(SSL *ssl,X509 *x)
{
return(add_client_CA(&(ssl->client_CA),x));
}
int SSL_CTX_add_client_CA(SSL_CTX *ctx,X509 *x)
{
return(add_client_CA(&(ctx->client_CA),x));
}
static int xname_cmp(const X509_NAME * const *a, const X509_NAME * const *b)
{
return(X509_NAME_cmp(*a,*b));
}
