long ssl23_default_timeout(void)
{
return (300);
}
int ssl23_num_ciphers(void)
{
return (ssl3_num_ciphers()
#ifndef OPENSSL_NO_SSL2
+ ssl2_num_ciphers()
#endif
);
}
const SSL_CIPHER *ssl23_get_cipher(unsigned int u)
{
unsigned int uu = ssl3_num_ciphers();
if (u < uu)
return (ssl3_get_cipher(u));
else
#ifndef OPENSSL_NO_SSL2
return (ssl2_get_cipher(u - uu));
#else
return (NULL);
#endif
}
const SSL_CIPHER *ssl23_get_cipher_by_char(const unsigned char *p)
{
const SSL_CIPHER *cp;
cp = ssl3_get_cipher_by_char(p);
#ifndef OPENSSL_NO_SSL2
if (cp == NULL)
cp = ssl2_get_cipher_by_char(p);
#endif
return (cp);
}
int ssl23_put_cipher_by_char(const SSL_CIPHER *c, unsigned char *p)
{
long l;
if (c->algorithm_mkey == SSL_kECDHr ||
c->algorithm_mkey == SSL_kECDHe ||
c->algorithm_mkey == SSL_kEECDH ||
c->algorithm_auth == SSL_aECDH || c->algorithm_auth == SSL_aECDSA)
return 0;
if (p != NULL) {
l = c->id;
p[0] = ((unsigned char)(l >> 16L)) & 0xFF;
p[1] = ((unsigned char)(l >> 8L)) & 0xFF;
p[2] = ((unsigned char)(l)) & 0xFF;
}
return (3);
}
int ssl23_read(SSL *s, void *buf, int len)
{
int n;
clear_sys_error();
if (SSL_in_init(s) && (!s->in_handshake)) {
n = s->handshake_func(s);
if (n < 0)
return (n);
if (n == 0) {
SSLerr(SSL_F_SSL23_READ, SSL_R_SSL_HANDSHAKE_FAILURE);
return (-1);
}
return (SSL_read(s, buf, len));
} else {
ssl_undefined_function(s);
return (-1);
}
}
int ssl23_peek(SSL *s, void *buf, int len)
{
int n;
clear_sys_error();
if (SSL_in_init(s) && (!s->in_handshake)) {
n = s->handshake_func(s);
if (n < 0)
return (n);
if (n == 0) {
SSLerr(SSL_F_SSL23_PEEK, SSL_R_SSL_HANDSHAKE_FAILURE);
return (-1);
}
return (SSL_peek(s, buf, len));
} else {
ssl_undefined_function(s);
return (-1);
}
}
int ssl23_write(SSL *s, const void *buf, int len)
{
int n;
clear_sys_error();
if (SSL_in_init(s) && (!s->in_handshake)) {
n = s->handshake_func(s);
if (n < 0)
return (n);
if (n == 0) {
SSLerr(SSL_F_SSL23_WRITE, SSL_R_SSL_HANDSHAKE_FAILURE);
return (-1);
}
return (SSL_write(s, buf, len));
} else {
ssl_undefined_function(s);
return (-1);
}
}
