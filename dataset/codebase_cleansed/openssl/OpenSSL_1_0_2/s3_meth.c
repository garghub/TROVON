static const SSL_METHOD *ssl3_get_method(int ver)
{
if (ver == SSL3_VERSION)
return (SSLv3_method());
else
return (NULL);
}
