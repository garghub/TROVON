int ssl_add_clienthello_renegotiate_ext(SSL *s, unsigned char *p, int *len,
int maxlen)
{
if (p) {
if ((s->s3->previous_client_finished_len + 1) > maxlen) {
SSLerr(SSL_F_SSL_ADD_CLIENTHELLO_RENEGOTIATE_EXT,
SSL_R_RENEGOTIATE_EXT_TOO_LONG);
return 0;
}
*p = s->s3->previous_client_finished_len;
p++;
memcpy(p, s->s3->previous_client_finished,
s->s3->previous_client_finished_len);
}
*len = s->s3->previous_client_finished_len + 1;
return 1;
}
int ssl_parse_clienthello_renegotiate_ext(SSL *s, PACKET *pkt, int *al)
{
unsigned int ilen;
const unsigned char *d;
if (!PACKET_get_1(pkt, &ilen)
|| !PACKET_get_bytes(pkt, &d, ilen)) {
SSLerr(SSL_F_SSL_PARSE_CLIENTHELLO_RENEGOTIATE_EXT,
SSL_R_RENEGOTIATION_ENCODING_ERR);
*al = SSL_AD_ILLEGAL_PARAMETER;
return 0;
}
if (ilen != s->s3->previous_client_finished_len) {
SSLerr(SSL_F_SSL_PARSE_CLIENTHELLO_RENEGOTIATE_EXT,
SSL_R_RENEGOTIATION_MISMATCH);
*al = SSL_AD_HANDSHAKE_FAILURE;
return 0;
}
if (memcmp(d, s->s3->previous_client_finished,
s->s3->previous_client_finished_len)) {
SSLerr(SSL_F_SSL_PARSE_CLIENTHELLO_RENEGOTIATE_EXT,
SSL_R_RENEGOTIATION_MISMATCH);
*al = SSL_AD_HANDSHAKE_FAILURE;
return 0;
}
s->s3->send_connection_binding = 1;
return 1;
}
int ssl_add_serverhello_renegotiate_ext(SSL *s, unsigned char *p, int *len,
int maxlen)
{
if (p) {
if ((s->s3->previous_client_finished_len +
s->s3->previous_server_finished_len + 1) > maxlen) {
SSLerr(SSL_F_SSL_ADD_SERVERHELLO_RENEGOTIATE_EXT,
SSL_R_RENEGOTIATE_EXT_TOO_LONG);
return 0;
}
*p = s->s3->previous_client_finished_len +
s->s3->previous_server_finished_len;
p++;
memcpy(p, s->s3->previous_client_finished,
s->s3->previous_client_finished_len);
p += s->s3->previous_client_finished_len;
memcpy(p, s->s3->previous_server_finished,
s->s3->previous_server_finished_len);
}
*len = s->s3->previous_client_finished_len
+ s->s3->previous_server_finished_len + 1;
return 1;
}
int ssl_parse_serverhello_renegotiate_ext(SSL *s, PACKET *pkt, int *al)
{
unsigned int expected_len = s->s3->previous_client_finished_len
+ s->s3->previous_server_finished_len;
unsigned int ilen;
const unsigned char *data;
OPENSSL_assert(!expected_len || s->s3->previous_client_finished_len);
OPENSSL_assert(!expected_len || s->s3->previous_server_finished_len);
if (!PACKET_get_1(pkt, &ilen)) {
SSLerr(SSL_F_SSL_PARSE_SERVERHELLO_RENEGOTIATE_EXT,
SSL_R_RENEGOTIATION_ENCODING_ERR);
*al = SSL_AD_ILLEGAL_PARAMETER;
return 0;
}
if (PACKET_remaining(pkt) != ilen) {
SSLerr(SSL_F_SSL_PARSE_SERVERHELLO_RENEGOTIATE_EXT,
SSL_R_RENEGOTIATION_ENCODING_ERR);
*al = SSL_AD_ILLEGAL_PARAMETER;
return 0;
}
if (ilen != expected_len) {
SSLerr(SSL_F_SSL_PARSE_SERVERHELLO_RENEGOTIATE_EXT,
SSL_R_RENEGOTIATION_MISMATCH);
*al = SSL_AD_HANDSHAKE_FAILURE;
return 0;
}
if (!PACKET_get_bytes(pkt, &data, s->s3->previous_client_finished_len)
|| memcmp(data, s->s3->previous_client_finished,
s->s3->previous_client_finished_len) != 0) {
SSLerr(SSL_F_SSL_PARSE_SERVERHELLO_RENEGOTIATE_EXT,
SSL_R_RENEGOTIATION_MISMATCH);
*al = SSL_AD_HANDSHAKE_FAILURE;
return 0;
}
if (!PACKET_get_bytes(pkt, &data, s->s3->previous_server_finished_len)
|| memcmp(data, s->s3->previous_server_finished,
s->s3->previous_server_finished_len) != 0) {
SSLerr(SSL_F_SSL_PARSE_SERVERHELLO_RENEGOTIATE_EXT,
SSL_R_RENEGOTIATION_MISMATCH);
*al = SSL_AD_ILLEGAL_PARAMETER;
return 0;
}
s->s3->send_connection_binding = 1;
return 1;
}
