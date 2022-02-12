void RC4_set_key(RC4_KEY *key, int len, const unsigned char *data)
{
#ifdef OPENSSL_FIPS
fips_cipher_abort(RC4);
#endif
private_RC4_set_key(key, len, data);
}
