static SSL_METHOD *dtls1_get_method(int ver)
{
if (ver == DTLS1_VERSION)
return(DTLSv1_method());
else
return(NULL);
}
SSL_METHOD *DTLSv1_method(void)
{
static int init=1;
static SSL_METHOD DTLSv1_data;
if (init)
{
CRYPTO_w_lock(CRYPTO_LOCK_SSL_METHOD);
if (init)
{
memcpy((char *)&DTLSv1_data,(char *)dtlsv1_base_method(),
sizeof(SSL_METHOD));
DTLSv1_data.ssl_connect=dtls1_connect;
DTLSv1_data.ssl_accept=dtls1_accept;
DTLSv1_data.get_ssl_method=dtls1_get_method;
init=0;
}
CRYPTO_w_unlock(CRYPTO_LOCK_SSL_METHOD);
}
return(&DTLSv1_data);
}
