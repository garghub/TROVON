static const SSL_METHOD *ssl2_get_method(int ver)
{
if (ver == SSL2_VERSION)
return (SSLv2_method());
else
return (NULL);
}
