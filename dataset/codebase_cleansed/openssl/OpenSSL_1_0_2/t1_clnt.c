static const SSL_METHOD *tls1_get_client_method(int ver)
{
if (ver == TLS1_2_VERSION)
return TLSv1_2_client_method();
if (ver == TLS1_1_VERSION)
return TLSv1_1_client_method();
if (ver == TLS1_VERSION)
return TLSv1_client_method();
return NULL;
}
