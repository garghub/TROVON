int ssl_add_clienthello_renegotiate_ext(SSL *s, unsigned char *p, int *len,
int maxlen)
{
if(p)
{
if((s->s3->previous_client_finished_len+1) > maxlen)
{
SSLerr(SSL_F_SSL_ADD_CLIENTHELLO_RENEGOTIATE_EXT,SSL_R_RENEGOTIATE_EXT_TOO_LONG);
return 0;
}
*p = s->s3->previous_client_finished_len;
p++;
memcpy(p, s->s3->previous_client_finished,
s->s3->previous_client_finished_len);
#ifdef OPENSSL_RI_DEBUG
fprintf(stderr, "%s RI extension sent by client\n",
s->s3->previous_client_finished_len ? "Non-empty" : "Empty");
#endif
}
*len=s->s3->previous_client_finished_len + 1;
return 1;
}
int ssl_parse_clienthello_renegotiate_ext(SSL *s, unsigned char *d, int len,
int *al)
{
int ilen;
if(len < 1)
{
SSLerr(SSL_F_SSL_PARSE_CLIENTHELLO_RENEGOTIATE_EXT,SSL_R_RENEGOTIATION_ENCODING_ERR);
*al=SSL_AD_ILLEGAL_PARAMETER;
return 0;
}
ilen = *d;
d++;
if((ilen+1) != len)
{
SSLerr(SSL_F_SSL_PARSE_CLIENTHELLO_RENEGOTIATE_EXT,SSL_R_RENEGOTIATION_ENCODING_ERR);
*al=SSL_AD_ILLEGAL_PARAMETER;
return 0;
}
if(ilen != s->s3->previous_client_finished_len)
{
SSLerr(SSL_F_SSL_PARSE_CLIENTHELLO_RENEGOTIATE_EXT,SSL_R_RENEGOTIATION_MISMATCH);
*al=SSL_AD_HANDSHAKE_FAILURE;
return 0;
}
if(memcmp(d, s->s3->previous_client_finished,
s->s3->previous_client_finished_len))
{
SSLerr(SSL_F_SSL_PARSE_CLIENTHELLO_RENEGOTIATE_EXT,SSL_R_RENEGOTIATION_MISMATCH);
*al=SSL_AD_HANDSHAKE_FAILURE;
return 0;
}
#ifdef OPENSSL_RI_DEBUG
fprintf(stderr, "%s RI extension received by server\n",
ilen ? "Non-empty" : "Empty");
#endif
s->s3->send_connection_binding=1;
return 1;
}
int ssl_add_serverhello_renegotiate_ext(SSL *s, unsigned char *p, int *len,
int maxlen)
{
if(p)
{
if((s->s3->previous_client_finished_len +
s->s3->previous_server_finished_len + 1) > maxlen)
{
SSLerr(SSL_F_SSL_ADD_SERVERHELLO_RENEGOTIATE_EXT,SSL_R_RENEGOTIATE_EXT_TOO_LONG);
return 0;
}
*p = s->s3->previous_client_finished_len + s->s3->previous_server_finished_len;
p++;
memcpy(p, s->s3->previous_client_finished,
s->s3->previous_client_finished_len);
p += s->s3->previous_client_finished_len;
memcpy(p, s->s3->previous_server_finished,
s->s3->previous_server_finished_len);
#ifdef OPENSSL_RI_DEBUG
fprintf(stderr, "%s RI extension sent by server\n",
s->s3->previous_client_finished_len ? "Non-empty" : "Empty");
#endif
}
*len=s->s3->previous_client_finished_len
+ s->s3->previous_server_finished_len + 1;
return 1;
}
int ssl_parse_serverhello_renegotiate_ext(SSL *s, unsigned char *d, int len,
int *al)
{
int expected_len=s->s3->previous_client_finished_len
+ s->s3->previous_server_finished_len;
int ilen;
OPENSSL_assert(!expected_len || s->s3->previous_client_finished_len);
OPENSSL_assert(!expected_len || s->s3->previous_server_finished_len);
if(len < 1)
{
SSLerr(SSL_F_SSL_PARSE_SERVERHELLO_RENEGOTIATE_EXT,SSL_R_RENEGOTIATION_ENCODING_ERR);
*al=SSL_AD_ILLEGAL_PARAMETER;
return 0;
}
ilen = *d;
d++;
if(ilen+1 != len)
{
SSLerr(SSL_F_SSL_PARSE_SERVERHELLO_RENEGOTIATE_EXT,SSL_R_RENEGOTIATION_ENCODING_ERR);
*al=SSL_AD_ILLEGAL_PARAMETER;
return 0;
}
if(ilen != expected_len)
{
SSLerr(SSL_F_SSL_PARSE_SERVERHELLO_RENEGOTIATE_EXT,SSL_R_RENEGOTIATION_MISMATCH);
*al=SSL_AD_HANDSHAKE_FAILURE;
return 0;
}
if(memcmp(d, s->s3->previous_client_finished,
s->s3->previous_client_finished_len))
{
SSLerr(SSL_F_SSL_PARSE_SERVERHELLO_RENEGOTIATE_EXT,SSL_R_RENEGOTIATION_MISMATCH);
*al=SSL_AD_HANDSHAKE_FAILURE;
return 0;
}
d += s->s3->previous_client_finished_len;
if(memcmp(d, s->s3->previous_server_finished,
s->s3->previous_server_finished_len))
{
SSLerr(SSL_F_SSL_PARSE_SERVERHELLO_RENEGOTIATE_EXT,SSL_R_RENEGOTIATION_MISMATCH);
*al=SSL_AD_ILLEGAL_PARAMETER;
return 0;
}
#ifdef OPENSSL_RI_DEBUG
fprintf(stderr, "%s RI extension received by client\n",
ilen ? "Non-empty" : "Empty");
#endif
s->s3->send_connection_binding=1;
return 1;
}
