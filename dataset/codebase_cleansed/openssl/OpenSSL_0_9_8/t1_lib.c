static long tls1_default_timeout(void)
{
return(60*60*2);
}
SSL_METHOD *tlsv1_base_method(void)
{
return(&TLSv1_data);
}
int tls1_new(SSL *s)
{
if (!ssl3_new(s)) return(0);
s->method->ssl_clear(s);
return(1);
}
void tls1_free(SSL *s)
{
ssl3_free(s);
}
void tls1_clear(SSL *s)
{
ssl3_clear(s);
s->version=TLS1_VERSION;
}
