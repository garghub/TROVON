static const SSL_METHOD *tls1_get_method(int ver)
{
if (ver == TLS1_VERSION)
return(TLSv1_method());
else
return(NULL);
}
