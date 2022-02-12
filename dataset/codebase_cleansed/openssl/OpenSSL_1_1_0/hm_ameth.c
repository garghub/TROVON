static int hmac_size(const EVP_PKEY *pkey)
{
return EVP_MAX_MD_SIZE;
}
static void hmac_key_free(EVP_PKEY *pkey)
{
ASN1_OCTET_STRING *os = EVP_PKEY_get0(pkey);
if (os) {
if (os->data)
OPENSSL_cleanse(os->data, os->length);
ASN1_OCTET_STRING_free(os);
}
}
static int hmac_pkey_ctrl(EVP_PKEY *pkey, int op, long arg1, void *arg2)
{
switch (op) {
case ASN1_PKEY_CTRL_DEFAULT_MD_NID:
*(int *)arg2 = NID_sha256;
return 1;
default:
return -2;
}
}
static int hmac_pkey_public_cmp(const EVP_PKEY *a, const EVP_PKEY *b)
{
return ASN1_OCTET_STRING_cmp(EVP_PKEY_get0(a), EVP_PKEY_get0(b));
}
static int old_hmac_decode(EVP_PKEY *pkey,
const unsigned char **pder, int derlen)
{
ASN1_OCTET_STRING *os;
os = ASN1_OCTET_STRING_new();
if (os == NULL || !ASN1_OCTET_STRING_set(os, *pder, derlen))
goto err;
if (!EVP_PKEY_assign(pkey, EVP_PKEY_HMAC, os))
goto err;
return 1;
err:
ASN1_OCTET_STRING_free(os);
return 0;
}
static int old_hmac_encode(const EVP_PKEY *pkey, unsigned char **pder)
{
int inc;
ASN1_OCTET_STRING *os = EVP_PKEY_get0(pkey);
if (pder) {
if (!*pder) {
*pder = OPENSSL_malloc(os->length);
if (*pder == NULL)
return -1;
inc = 0;
} else
inc = 1;
memcpy(*pder, os->data, os->length);
if (inc)
*pder += os->length;
}
return os->length;
}
