static SSL_METHOD *ssl3_get_method(int ver)
{
if (ver == SSL3_VERSION)
return(SSLv3_method());
else
return(NULL);
}
SSL_METHOD *SSLv3_method(void)
{
static int init=1;
static SSL_METHOD SSLv3_data;
if (init)
{
memcpy((char *)&SSLv3_data,(char *)sslv3_base_method(),
sizeof(SSL_METHOD));
SSLv3_data.ssl_connect=ssl3_connect;
SSLv3_data.ssl_accept=ssl3_accept;
SSLv3_data.get_ssl_method=ssl3_get_method;
init=0;
}
return(&SSLv3_data);
}
