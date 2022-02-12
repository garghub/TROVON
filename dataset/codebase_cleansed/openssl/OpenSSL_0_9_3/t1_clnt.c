static SSL_METHOD *tls1_get_client_method(int ver)
{
if (ver == TLS1_VERSION)
return(TLSv1_client_method());
else
return(NULL);
}
SSL_METHOD *TLSv1_client_method(void)
{
static int init=1;
static SSL_METHOD TLSv1_client_data;
if (init)
{
memcpy((char *)&TLSv1_client_data,(char *)tlsv1_base_method(),
sizeof(SSL_METHOD));
TLSv1_client_data.ssl_connect=ssl3_connect;
TLSv1_client_data.get_ssl_method=tls1_get_client_method;
init=0;
}
return(&TLSv1_client_data);
}
