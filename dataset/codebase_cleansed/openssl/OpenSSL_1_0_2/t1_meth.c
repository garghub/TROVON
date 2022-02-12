static const SSL_METHOD *tls1_get_method(int ver)
{
if (ver == TLS1_2_VERSION)
return TLSv1_2_method();
if (ver == TLS1_1_VERSION)
return TLSv1_1_method();
if (ver == TLS1_VERSION)
return TLSv1_method();
return NULL;
}
