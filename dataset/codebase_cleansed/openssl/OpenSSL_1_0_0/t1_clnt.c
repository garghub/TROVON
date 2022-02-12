static const SSL_METHOD *tls1_get_client_method(int ver)
{
if (ver == TLS1_VERSION)
return(TLSv1_client_method());
else
return(NULL);
}
