static SSL_METHOD *ssl2_get_method(int ver)
{
if (ver == SSL2_VERSION)
return(SSLv2_method());
else
return(NULL);
}
SSL_METHOD *SSLv2_method(void)
{
static int init=1;
static SSL_METHOD SSLv2_data;
if (init)
{
CRYPTO_w_lock(CRYPTO_LOCK_SSL_METHOD);
if (init)
{
memcpy((char *)&SSLv2_data,(char *)sslv2_base_method(),
sizeof(SSL_METHOD));
SSLv2_data.ssl_connect=ssl2_connect;
SSLv2_data.ssl_accept=ssl2_accept;
SSLv2_data.get_ssl_method=ssl2_get_method;
init=0;
}
CRYPTO_w_unlock(CRYPTO_LOCK_SSL_METHOD);
}
return(&SSLv2_data);
}
