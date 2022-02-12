static SSL_METHOD *ssl23_get_method(int ver)
{
if (ver == SSL2_VERSION)
return(SSLv2_method());
else if (ver == SSL3_VERSION)
return(SSLv3_method());
else if (ver == TLS1_VERSION)
return(TLSv1_method());
else
return(NULL);
}
SSL_METHOD *SSLv23_method(void)
{
static int init=1;
static SSL_METHOD SSLv23_data;
if (init)
{
CRYPTO_w_lock(CRYPTO_LOCK_SSL_METHOD);
if (init)
{
memcpy((char *)&SSLv23_data,(char *)sslv23_base_method(),
sizeof(SSL_METHOD));
SSLv23_data.ssl_connect=ssl23_connect;
SSLv23_data.ssl_accept=ssl23_accept;
SSLv23_data.get_ssl_method=ssl23_get_method;
init=0;
}
CRYPTO_w_unlock(CRYPTO_LOCK_SSL_METHOD);
}
return(&SSLv23_data);
}
