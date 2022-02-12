static const SSL_METHOD *tls1_get_server_method(int ver)
{
if (ver == TLS1_VERSION)
return(TLSv1_server_method());
else
return(NULL);
}
