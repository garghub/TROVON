static SSL_METHOD *tls1_get_server_method(int ver)
{
if (ver == TLS1_VERSION)
return(TLSv1_server_method());
else
return(NULL);
}
SSL_METHOD *TLSv1_server_method(void)
{
static int init=1;
static SSL_METHOD TLSv1_server_data;
if (init)
{
memcpy((char *)&TLSv1_server_data,(char *)tlsv1_base_method(),
sizeof(SSL_METHOD));
TLSv1_server_data.ssl_accept=ssl3_accept;
TLSv1_server_data.get_ssl_method=tls1_get_server_method;
init=0;
}
return(&TLSv1_server_data);
}
