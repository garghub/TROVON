static const SSL_METHOD *ssl23_get_method(int ver)
{
#ifndef OPENSSL_NO_SSL2
if (ver == SSL2_VERSION)
return (SSLv2_method());
else
#endif
#ifndef OPENSSL_NO_SSL3
if (ver == SSL3_VERSION)
return (SSLv3_method());
else
#endif
#ifndef OPENSSL_NO_TLS1
if (ver == TLS1_VERSION)
return (TLSv1_method());
else if (ver == TLS1_1_VERSION)
return (TLSv1_1_method());
else if (ver == TLS1_2_VERSION)
return (TLSv1_2_method());
else
#endif
return (NULL);
}
