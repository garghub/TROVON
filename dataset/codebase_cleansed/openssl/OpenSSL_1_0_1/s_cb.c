int MS_CALLBACK verify_callback(int ok, X509_STORE_CTX *ctx)
{
X509 *err_cert;
int err,depth;
err_cert=X509_STORE_CTX_get_current_cert(ctx);
err= X509_STORE_CTX_get_error(ctx);
depth= X509_STORE_CTX_get_error_depth(ctx);
BIO_printf(bio_err,"depth=%d ",depth);
if (err_cert)
{
X509_NAME_print_ex(bio_err, X509_get_subject_name(err_cert),
0, XN_FLAG_ONELINE);
BIO_puts(bio_err, "\n");
}
else
BIO_puts(bio_err, "<no cert>\n");
if (!ok)
{
BIO_printf(bio_err,"verify error:num=%d:%s\n",err,
X509_verify_cert_error_string(err));
if (verify_depth >= depth)
{
if (!verify_return_error)
ok=1;
verify_error=X509_V_OK;
}
else
{
ok=0;
verify_error=X509_V_ERR_CERT_CHAIN_TOO_LONG;
}
}
switch (err)
{
case X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT:
BIO_puts(bio_err,"issuer= ");
X509_NAME_print_ex(bio_err, X509_get_issuer_name(err_cert),
0, XN_FLAG_ONELINE);
BIO_puts(bio_err, "\n");
break;
case X509_V_ERR_CERT_NOT_YET_VALID:
case X509_V_ERR_ERROR_IN_CERT_NOT_BEFORE_FIELD:
BIO_printf(bio_err,"notBefore=");
ASN1_TIME_print(bio_err,X509_get_notBefore(err_cert));
BIO_printf(bio_err,"\n");
break;
case X509_V_ERR_CERT_HAS_EXPIRED:
case X509_V_ERR_ERROR_IN_CERT_NOT_AFTER_FIELD:
BIO_printf(bio_err,"notAfter=");
ASN1_TIME_print(bio_err,X509_get_notAfter(err_cert));
BIO_printf(bio_err,"\n");
break;
case X509_V_ERR_NO_EXPLICIT_POLICY:
policies_print(bio_err, ctx);
break;
}
if (err == X509_V_OK && ok == 2)
policies_print(bio_err, ctx);
BIO_printf(bio_err,"verify return:%d\n",ok);
return(ok);
}
int set_cert_stuff(SSL_CTX *ctx, char *cert_file, char *key_file)
{
if (cert_file != NULL)
{
if (SSL_CTX_use_certificate_file(ctx,cert_file,
SSL_FILETYPE_PEM) <= 0)
{
BIO_printf(bio_err,"unable to get certificate from '%s'\n",cert_file);
ERR_print_errors(bio_err);
return(0);
}
if (key_file == NULL) key_file=cert_file;
if (SSL_CTX_use_PrivateKey_file(ctx,key_file,
SSL_FILETYPE_PEM) <= 0)
{
BIO_printf(bio_err,"unable to get private key from '%s'\n",key_file);
ERR_print_errors(bio_err);
return(0);
}
if (!SSL_CTX_check_private_key(ctx))
{
BIO_printf(bio_err,"Private key does not match the certificate public key\n");
return(0);
}
}
return(1);
}
int set_cert_key_stuff(SSL_CTX *ctx, X509 *cert, EVP_PKEY *key)
{
if (cert == NULL)
return 1;
if (SSL_CTX_use_certificate(ctx,cert) <= 0)
{
BIO_printf(bio_err,"error setting certificate\n");
ERR_print_errors(bio_err);
return 0;
}
if (SSL_CTX_use_PrivateKey(ctx,key) <= 0)
{
BIO_printf(bio_err,"error setting private key\n");
ERR_print_errors(bio_err);
return 0;
}
if (!SSL_CTX_check_private_key(ctx))
{
BIO_printf(bio_err,"Private key does not match the certificate public key\n");
return 0;
}
return 1;
}
long MS_CALLBACK bio_dump_callback(BIO *bio, int cmd, const char *argp,
int argi, long argl, long ret)
{
BIO *out;
out=(BIO *)BIO_get_callback_arg(bio);
if (out == NULL) return(ret);
if (cmd == (BIO_CB_READ|BIO_CB_RETURN))
{
BIO_printf(out,"read from %p [%p] (%lu bytes => %ld (0x%lX))\n",
(void *)bio,argp,(unsigned long)argi,ret,ret);
BIO_dump(out,argp,(int)ret);
return(ret);
}
else if (cmd == (BIO_CB_WRITE|BIO_CB_RETURN))
{
BIO_printf(out,"write to %p [%p] (%lu bytes => %ld (0x%lX))\n",
(void *)bio,argp,(unsigned long)argi,ret,ret);
BIO_dump(out,argp,(int)ret);
}
return(ret);
}
void MS_CALLBACK apps_ssl_info_callback(const SSL *s, int where, int ret)
{
const char *str;
int w;
w=where& ~SSL_ST_MASK;
if (w & SSL_ST_CONNECT) str="SSL_connect";
else if (w & SSL_ST_ACCEPT) str="SSL_accept";
else str="undefined";
if (where & SSL_CB_LOOP)
{
BIO_printf(bio_err,"%s:%s\n",str,SSL_state_string_long(s));
}
else if (where & SSL_CB_ALERT)
{
str=(where & SSL_CB_READ)?"read":"write";
BIO_printf(bio_err,"SSL3 alert %s:%s:%s\n",
str,
SSL_alert_type_string_long(ret),
SSL_alert_desc_string_long(ret));
}
else if (where & SSL_CB_EXIT)
{
if (ret == 0)
BIO_printf(bio_err,"%s:failed in %s\n",
str,SSL_state_string_long(s));
else if (ret < 0)
{
BIO_printf(bio_err,"%s:error in %s\n",
str,SSL_state_string_long(s));
}
}
}
void MS_CALLBACK msg_cb(int write_p, int version, int content_type, const void *buf, size_t len, SSL *ssl, void *arg)
{
BIO *bio = arg;
const char *str_write_p, *str_version, *str_content_type = "", *str_details1 = "", *str_details2= "";
str_write_p = write_p ? ">>>" : "<<<";
switch (version)
{
case SSL2_VERSION:
str_version = "SSL 2.0";
break;
case SSL3_VERSION:
str_version = "SSL 3.0 ";
break;
case TLS1_VERSION:
str_version = "TLS 1.0 ";
break;
case TLS1_1_VERSION:
str_version = "TLS 1.1 ";
break;
case TLS1_2_VERSION:
str_version = "TLS 1.2 ";
break;
case DTLS1_VERSION:
str_version = "DTLS 1.0 ";
break;
case DTLS1_BAD_VER:
str_version = "DTLS 1.0 (bad) ";
break;
default:
str_version = "???";
}
if (version == SSL2_VERSION)
{
str_details1 = "???";
if (len > 0)
{
switch (((const unsigned char*)buf)[0])
{
case 0:
str_details1 = ", ERROR:";
str_details2 = " ???";
if (len >= 3)
{
unsigned err = (((const unsigned char*)buf)[1]<<8) + ((const unsigned char*)buf)[2];
switch (err)
{
case 0x0001:
str_details2 = " NO-CIPHER-ERROR";
break;
case 0x0002:
str_details2 = " NO-CERTIFICATE-ERROR";
break;
case 0x0004:
str_details2 = " BAD-CERTIFICATE-ERROR";
break;
case 0x0006:
str_details2 = " UNSUPPORTED-CERTIFICATE-TYPE-ERROR";
break;
}
}
break;
case 1:
str_details1 = ", CLIENT-HELLO";
break;
case 2:
str_details1 = ", CLIENT-MASTER-KEY";
break;
case 3:
str_details1 = ", CLIENT-FINISHED";
break;
case 4:
str_details1 = ", SERVER-HELLO";
break;
case 5:
str_details1 = ", SERVER-VERIFY";
break;
case 6:
str_details1 = ", SERVER-FINISHED";
break;
case 7:
str_details1 = ", REQUEST-CERTIFICATE";
break;
case 8:
str_details1 = ", CLIENT-CERTIFICATE";
break;
}
}
}
if (version == SSL3_VERSION ||
version == TLS1_VERSION ||
version == DTLS1_VERSION ||
version == DTLS1_BAD_VER)
{
switch (content_type)
{
case 20:
str_content_type = "ChangeCipherSpec";
break;
case 21:
str_content_type = "Alert";
break;
case 22:
str_content_type = "Handshake";
break;
}
if (content_type == 21)
{
str_details1 = ", ???";
if (len == 2)
{
switch (((const unsigned char*)buf)[0])
{
case 1:
str_details1 = ", warning";
break;
case 2:
str_details1 = ", fatal";
break;
}
str_details2 = " ???";
switch (((const unsigned char*)buf)[1])
{
case 0:
str_details2 = " close_notify";
break;
case 10:
str_details2 = " unexpected_message";
break;
case 20:
str_details2 = " bad_record_mac";
break;
case 21:
str_details2 = " decryption_failed";
break;
case 22:
str_details2 = " record_overflow";
break;
case 30:
str_details2 = " decompression_failure";
break;
case 40:
str_details2 = " handshake_failure";
break;
case 42:
str_details2 = " bad_certificate";
break;
case 43:
str_details2 = " unsupported_certificate";
break;
case 44:
str_details2 = " certificate_revoked";
break;
case 45:
str_details2 = " certificate_expired";
break;
case 46:
str_details2 = " certificate_unknown";
break;
case 47:
str_details2 = " illegal_parameter";
break;
case 48:
str_details2 = " unknown_ca";
break;
case 49:
str_details2 = " access_denied";
break;
case 50:
str_details2 = " decode_error";
break;
case 51:
str_details2 = " decrypt_error";
break;
case 60:
str_details2 = " export_restriction";
break;
case 70:
str_details2 = " protocol_version";
break;
case 71:
str_details2 = " insufficient_security";
break;
case 80:
str_details2 = " internal_error";
break;
case 90:
str_details2 = " user_canceled";
break;
case 100:
str_details2 = " no_renegotiation";
break;
case 110:
str_details2 = " unsupported_extension";
break;
case 111:
str_details2 = " certificate_unobtainable";
break;
case 112:
str_details2 = " unrecognized_name";
break;
case 113:
str_details2 = " bad_certificate_status_response";
break;
case 114:
str_details2 = " bad_certificate_hash_value";
break;
case 115:
str_details2 = " unknown_psk_identity";
break;
}
}
}
if (content_type == 22)
{
str_details1 = "???";
if (len > 0)
{
switch (((const unsigned char*)buf)[0])
{
case 0:
str_details1 = ", HelloRequest";
break;
case 1:
str_details1 = ", ClientHello";
break;
case 2:
str_details1 = ", ServerHello";
break;
case 3:
str_details1 = ", HelloVerifyRequest";
break;
case 11:
str_details1 = ", Certificate";
break;
case 12:
str_details1 = ", ServerKeyExchange";
break;
case 13:
str_details1 = ", CertificateRequest";
break;
case 14:
str_details1 = ", ServerHelloDone";
break;
case 15:
str_details1 = ", CertificateVerify";
break;
case 16:
str_details1 = ", ClientKeyExchange";
break;
case 20:
str_details1 = ", Finished";
break;
}
}
}
#ifndef OPENSSL_NO_HEARTBEATS
if (content_type == 24)
{
str_details1 = ", Heartbeat";
if (len > 0)
{
switch (((const unsigned char*)buf)[0])
{
case 1:
str_details1 = ", HeartbeatRequest";
break;
case 2:
str_details1 = ", HeartbeatResponse";
break;
}
}
}
#endif
}
BIO_printf(bio, "%s %s%s [length %04lx]%s%s\n", str_write_p, str_version, str_content_type, (unsigned long)len, str_details1, str_details2);
if (len > 0)
{
size_t num, i;
BIO_printf(bio, " ");
num = len;
#if 0
if (num > 16)
num = 16;
#endif
for (i = 0; i < num; i++)
{
if (i % 16 == 0 && i > 0)
BIO_printf(bio, "\n ");
BIO_printf(bio, " %02x", ((const unsigned char*)buf)[i]);
}
if (i < len)
BIO_printf(bio, " ...");
BIO_printf(bio, "\n");
}
(void)BIO_flush(bio);
}
void MS_CALLBACK tlsext_cb(SSL *s, int client_server, int type,
unsigned char *data, int len,
void *arg)
{
BIO *bio = arg;
char *extname;
switch(type)
{
case TLSEXT_TYPE_server_name:
extname = "server name";
break;
case TLSEXT_TYPE_max_fragment_length:
extname = "max fragment length";
break;
case TLSEXT_TYPE_client_certificate_url:
extname = "client certificate URL";
break;
case TLSEXT_TYPE_trusted_ca_keys:
extname = "trusted CA keys";
break;
case TLSEXT_TYPE_truncated_hmac:
extname = "truncated HMAC";
break;
case TLSEXT_TYPE_status_request:
extname = "status request";
break;
case TLSEXT_TYPE_user_mapping:
extname = "user mapping";
break;
case TLSEXT_TYPE_client_authz:
extname = "client authz";
break;
case TLSEXT_TYPE_server_authz:
extname = "server authz";
break;
case TLSEXT_TYPE_cert_type:
extname = "cert type";
break;
case TLSEXT_TYPE_elliptic_curves:
extname = "elliptic curves";
break;
case TLSEXT_TYPE_ec_point_formats:
extname = "EC point formats";
break;
case TLSEXT_TYPE_srp:
extname = "SRP";
break;
case TLSEXT_TYPE_signature_algorithms:
extname = "signature algorithms";
break;
case TLSEXT_TYPE_use_srtp:
extname = "use SRTP";
break;
case TLSEXT_TYPE_heartbeat:
extname = "heartbeat";
break;
case TLSEXT_TYPE_session_ticket:
extname = "session ticket";
break;
case TLSEXT_TYPE_renegotiate:
extname = "renegotiation info";
break;
#ifdef TLSEXT_TYPE_opaque_prf_input
case TLSEXT_TYPE_opaque_prf_input:
extname = "opaque PRF input";
break;
#endif
#ifdef TLSEXT_TYPE_next_proto_neg
case TLSEXT_TYPE_next_proto_neg:
extname = "next protocol";
break;
#endif
default:
extname = "unknown";
break;
}
BIO_printf(bio, "TLS %s extension \"%s\" (id=%d), len=%d\n",
client_server ? "server": "client",
extname, type, len);
BIO_dump(bio, (char *)data, len);
(void)BIO_flush(bio);
}
int MS_CALLBACK generate_cookie_callback(SSL *ssl, unsigned char *cookie, unsigned int *cookie_len)
{
unsigned char *buffer, result[EVP_MAX_MD_SIZE];
unsigned int length, resultlength;
union {
struct sockaddr sa;
struct sockaddr_in s4;
#if OPENSSL_USE_IPV6
struct sockaddr_in6 s6;
#endif
} peer;
if (!cookie_initialized)
{
if (!RAND_bytes(cookie_secret, COOKIE_SECRET_LENGTH))
{
BIO_printf(bio_err,"error setting random cookie secret\n");
return 0;
}
cookie_initialized = 1;
}
(void)BIO_dgram_get_peer(SSL_get_rbio(ssl), &peer);
length = 0;
switch (peer.sa.sa_family)
{
case AF_INET:
length += sizeof(struct in_addr);
length += sizeof(peer.s4.sin_port);
break;
#if OPENSSL_USE_IPV6
case AF_INET6:
length += sizeof(struct in6_addr);
length += sizeof(peer.s6.sin6_port);
break;
#endif
default:
OPENSSL_assert(0);
break;
}
buffer = OPENSSL_malloc(length);
if (buffer == NULL)
{
BIO_printf(bio_err,"out of memory\n");
return 0;
}
switch (peer.sa.sa_family)
{
case AF_INET:
memcpy(buffer,
&peer.s4.sin_port,
sizeof(peer.s4.sin_port));
memcpy(buffer + sizeof(peer.s4.sin_port),
&peer.s4.sin_addr,
sizeof(struct in_addr));
break;
#if OPENSSL_USE_IPV6
case AF_INET6:
memcpy(buffer,
&peer.s6.sin6_port,
sizeof(peer.s6.sin6_port));
memcpy(buffer + sizeof(peer.s6.sin6_port),
&peer.s6.sin6_addr,
sizeof(struct in6_addr));
break;
#endif
default:
OPENSSL_assert(0);
break;
}
HMAC(EVP_sha1(), cookie_secret, COOKIE_SECRET_LENGTH,
buffer, length, result, &resultlength);
OPENSSL_free(buffer);
memcpy(cookie, result, resultlength);
*cookie_len = resultlength;
return 1;
}
int MS_CALLBACK verify_cookie_callback(SSL *ssl, unsigned char *cookie, unsigned int cookie_len)
{
unsigned char *buffer, result[EVP_MAX_MD_SIZE];
unsigned int length, resultlength;
union {
struct sockaddr sa;
struct sockaddr_in s4;
#if OPENSSL_USE_IPV6
struct sockaddr_in6 s6;
#endif
} peer;
if (!cookie_initialized)
return 0;
(void)BIO_dgram_get_peer(SSL_get_rbio(ssl), &peer);
length = 0;
switch (peer.sa.sa_family)
{
case AF_INET:
length += sizeof(struct in_addr);
length += sizeof(peer.s4.sin_port);
break;
#if OPENSSL_USE_IPV6
case AF_INET6:
length += sizeof(struct in6_addr);
length += sizeof(peer.s6.sin6_port);
break;
#endif
default:
OPENSSL_assert(0);
break;
}
buffer = OPENSSL_malloc(length);
if (buffer == NULL)
{
BIO_printf(bio_err,"out of memory\n");
return 0;
}
switch (peer.sa.sa_family)
{
case AF_INET:
memcpy(buffer,
&peer.s4.sin_port,
sizeof(peer.s4.sin_port));
memcpy(buffer + sizeof(peer.s4.sin_port),
&peer.s4.sin_addr,
sizeof(struct in_addr));
break;
#if OPENSSL_USE_IPV6
case AF_INET6:
memcpy(buffer,
&peer.s6.sin6_port,
sizeof(peer.s6.sin6_port));
memcpy(buffer + sizeof(peer.s6.sin6_port),
&peer.s6.sin6_addr,
sizeof(struct in6_addr));
break;
#endif
default:
OPENSSL_assert(0);
break;
}
HMAC(EVP_sha1(), cookie_secret, COOKIE_SECRET_LENGTH,
buffer, length, result, &resultlength);
OPENSSL_free(buffer);
if (cookie_len == resultlength && memcmp(result, cookie, resultlength) == 0)
return 1;
return 0;
}
