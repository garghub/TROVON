int i2d_SSL_SESSION(SSL_SESSION *in, unsigned char **pp)
{
SSL_SESSION_ASN1 as;
ASN1_OCTET_STRING cipher;
unsigned char cipher_data[2];
ASN1_OCTET_STRING master_key, session_id, sid_ctx;
#ifndef OPENSSL_NO_COMP
ASN1_OCTET_STRING comp_id;
unsigned char comp_id_data;
#endif
ASN1_OCTET_STRING tlsext_hostname, tlsext_tick;
#ifndef OPENSSL_NO_SRP
ASN1_OCTET_STRING srp_username;
#endif
#ifndef OPENSSL_NO_PSK
ASN1_OCTET_STRING psk_identity, psk_identity_hint;
#endif
long l;
if ((in == NULL) || ((in->cipher == NULL) && (in->cipher_id == 0)))
return 0;
memset(&as, 0, sizeof(as));
as.version = SSL_SESSION_ASN1_VERSION;
as.ssl_version = in->ssl_version;
if (in->cipher == NULL)
l = in->cipher_id;
else
l = in->cipher->id;
cipher_data[0] = ((unsigned char)(l >> 8L)) & 0xff;
cipher_data[1] = ((unsigned char)(l)) & 0xff;
ssl_session_oinit(&as.cipher, &cipher, cipher_data, 2);
#ifndef OPENSSL_NO_COMP
if (in->compress_meth) {
comp_id_data = (unsigned char)in->compress_meth;
ssl_session_oinit(&as.comp_id, &comp_id, &comp_id_data, 1);
}
#endif
ssl_session_oinit(&as.master_key, &master_key,
in->master_key, in->master_key_length);
ssl_session_oinit(&as.session_id, &session_id,
in->session_id, in->session_id_length);
ssl_session_oinit(&as.session_id_context, &sid_ctx,
in->sid_ctx, in->sid_ctx_length);
as.time = in->time;
as.timeout = in->timeout;
as.verify_result = in->verify_result;
as.peer = in->peer;
ssl_session_sinit(&as.tlsext_hostname, &tlsext_hostname,
in->tlsext_hostname);
if (in->tlsext_tick) {
ssl_session_oinit(&as.tlsext_tick, &tlsext_tick,
in->tlsext_tick, in->tlsext_ticklen);
}
if (in->tlsext_tick_lifetime_hint > 0)
as.tlsext_tick_lifetime_hint = in->tlsext_tick_lifetime_hint;
#ifndef OPENSSL_NO_PSK
ssl_session_sinit(&as.psk_identity_hint, &psk_identity_hint,
in->psk_identity_hint);
ssl_session_sinit(&as.psk_identity, &psk_identity, in->psk_identity);
#endif
#ifndef OPENSSL_NO_SRP
ssl_session_sinit(&as.srp_username, &srp_username, in->srp_username);
#endif
as.flags = in->flags;
return i2d_SSL_SESSION_ASN1(&as, pp);
}
static int ssl_session_strndup(char **pdst, ASN1_OCTET_STRING *src)
{
OPENSSL_free(*pdst);
*pdst = NULL;
if (src == NULL)
return 1;
*pdst = OPENSSL_strndup((char *)src->data, src->length);
if (*pdst == NULL)
return 0;
return 1;
}
static int ssl_session_memcpy(unsigned char *dst, unsigned int *pdstlen,
ASN1_OCTET_STRING *src, int maxlen)
{
if (src == NULL) {
*pdstlen = 0;
return 1;
}
if (src->length > maxlen)
return 0;
memcpy(dst, src->data, src->length);
*pdstlen = src->length;
return 1;
}
SSL_SESSION *d2i_SSL_SESSION(SSL_SESSION **a, const unsigned char **pp,
long length)
{
long id;
unsigned int tmpl;
const unsigned char *p = *pp;
SSL_SESSION_ASN1 *as = NULL;
SSL_SESSION *ret = NULL;
as = d2i_SSL_SESSION_ASN1(NULL, &p, length);
if (as == NULL)
goto err;
if (!a || !*a) {
ret = SSL_SESSION_new();
if (ret == NULL)
goto err;
} else {
ret = *a;
}
if (as->version != SSL_SESSION_ASN1_VERSION) {
SSLerr(SSL_F_D2I_SSL_SESSION, SSL_R_UNKNOWN_SSL_VERSION);
goto err;
}
if ((as->ssl_version >> 8) != SSL3_VERSION_MAJOR
&& (as->ssl_version >> 8) != DTLS1_VERSION_MAJOR
&& as->ssl_version != DTLS1_BAD_VER) {
SSLerr(SSL_F_D2I_SSL_SESSION, SSL_R_UNSUPPORTED_SSL_VERSION);
goto err;
}
ret->ssl_version = (int)as->ssl_version;
if (as->cipher->length != 2) {
SSLerr(SSL_F_D2I_SSL_SESSION, SSL_R_CIPHER_CODE_WRONG_LENGTH);
goto err;
}
p = as->cipher->data;
id = 0x03000000L | ((unsigned long)p[0] << 8L) | (unsigned long)p[1];
ret->cipher = NULL;
ret->cipher_id = id;
if (!ssl_session_memcpy(ret->session_id, &ret->session_id_length,
as->session_id, SSL3_MAX_SSL_SESSION_ID_LENGTH))
goto err;
if (!ssl_session_memcpy(ret->master_key, &tmpl,
as->master_key, SSL_MAX_MASTER_KEY_LENGTH))
goto err;
ret->master_key_length = tmpl;
if (as->time != 0)
ret->time = as->time;
else
ret->time = (unsigned long)time(NULL);
if (as->timeout != 0)
ret->timeout = as->timeout;
else
ret->timeout = 3;
X509_free(ret->peer);
ret->peer = as->peer;
as->peer = NULL;
if (!ssl_session_memcpy(ret->sid_ctx, &ret->sid_ctx_length,
as->session_id_context, SSL_MAX_SID_CTX_LENGTH))
goto err;
ret->verify_result = as->verify_result;
if (!ssl_session_strndup(&ret->tlsext_hostname, as->tlsext_hostname))
goto err;
#ifndef OPENSSL_NO_PSK
if (!ssl_session_strndup(&ret->psk_identity_hint, as->psk_identity_hint))
goto err;
if (!ssl_session_strndup(&ret->psk_identity, as->psk_identity))
goto err;
#endif
ret->tlsext_tick_lifetime_hint = as->tlsext_tick_lifetime_hint;
if (as->tlsext_tick) {
ret->tlsext_tick = as->tlsext_tick->data;
ret->tlsext_ticklen = as->tlsext_tick->length;
as->tlsext_tick->data = NULL;
} else {
ret->tlsext_tick = NULL;
}
#ifndef OPENSSL_NO_COMP
if (as->comp_id) {
if (as->comp_id->length != 1) {
SSLerr(SSL_F_D2I_SSL_SESSION, SSL_R_BAD_LENGTH);
goto err;
}
ret->compress_meth = as->comp_id->data[0];
} else {
ret->compress_meth = 0;
}
#endif
#ifndef OPENSSL_NO_SRP
if (!ssl_session_strndup(&ret->srp_username, as->srp_username))
goto err;
#endif
ret->flags = as->flags;
M_ASN1_free_of(as, SSL_SESSION_ASN1);
if ((a != NULL) && (*a == NULL))
*a = ret;
*pp = p;
return ret;
err:
M_ASN1_free_of(as, SSL_SESSION_ASN1);
if ((a == NULL) || (*a != ret))
SSL_SESSION_free(ret);
return NULL;
}
