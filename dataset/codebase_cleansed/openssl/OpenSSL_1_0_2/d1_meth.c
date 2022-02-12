static const SSL_METHOD *dtls1_get_method(int ver)
{
if (ver == DTLS1_VERSION)
return (DTLSv1_method());
else if (ver == DTLS1_2_VERSION)
return (DTLSv1_2_method());
else
return (NULL);
}
