const char *AES_options(void)
{
#ifdef FULL_UNROLL
return "aes(full)";
#else
return "aes(partial)";
#endif
}
int AES_set_encrypt_key(const unsigned char *userKey, const int bits,
AES_KEY *key)
{
#ifdef OPENSSL_FIPS
fips_cipher_abort(AES);
#endif
return private_AES_set_encrypt_key(userKey, bits, key);
}
int AES_set_decrypt_key(const unsigned char *userKey, const int bits,
AES_KEY *key)
{
#ifdef OPENSSL_FIPS
fips_cipher_abort(AES);
#endif
return private_AES_set_decrypt_key(userKey, bits, key);
}
