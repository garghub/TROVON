static SSL_METHOD *tls1_get_method(int ver)
{
if (ver == TLS1_VERSION)
return(TLSv1_method());
else
return(NULL);
}
SSL_METHOD *TLSv1_method(void)
{
static int init=1;
static SSL_METHOD TLSv1_data;
if (init)
{
memcpy((char *)&TLSv1_data,(char *)tlsv1_base_method(),
sizeof(SSL_METHOD));
TLSv1_data.ssl_connect=ssl3_connect;
TLSv1_data.ssl_accept=ssl3_accept;
TLSv1_data.get_ssl_method=tls1_get_method;
init=0;
}
return(&TLSv1_data);
}
