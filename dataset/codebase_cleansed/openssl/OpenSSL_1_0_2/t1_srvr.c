static const SSL_METHOD *tls1_get_server_method(int ver)
{
if (ver == TLS1_2_VERSION)
return TLSv1_2_server_method();
if (ver == TLS1_1_VERSION)
return TLSv1_1_server_method();
if (ver == TLS1_VERSION)
return TLSv1_server_method();
return NULL;
}
