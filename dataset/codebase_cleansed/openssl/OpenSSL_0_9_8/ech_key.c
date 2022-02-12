int ECDH_compute_key(void *out, size_t outlen, const EC_POINT *pub_key,
EC_KEY *eckey,
void *(*KDF)(const void *in, size_t inlen, void *out, size_t *outlen))
{
ECDH_DATA *ecdh = ecdh_check(eckey);
if (ecdh == NULL)
return 0;
return ecdh->meth->compute_key(out, outlen, pub_key, eckey, KDF);
}
