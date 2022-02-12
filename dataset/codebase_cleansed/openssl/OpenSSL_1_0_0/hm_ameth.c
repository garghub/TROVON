static int hmac_size(const EVP_PKEY *pkey)
{
return EVP_MAX_MD_SIZE;
}
static void hmac_key_free(EVP_PKEY *pkey)
{
ASN1_OCTET_STRING *os = (ASN1_OCTET_STRING *)pkey->pkey.ptr;
if (os)
{
if (os->data)
OPENSSL_cleanse(os->data, os->length);
ASN1_OCTET_STRING_free(os);
}
}
static int hmac_pkey_ctrl(EVP_PKEY *pkey, int op, long arg1, void *arg2)
{
switch (op)
{
case ASN1_PKEY_CTRL_DEFAULT_MD_NID:
*(int *)arg2 = NID_sha1;
return 1;
default:
return -2;
}
}
static int old_hmac_decode(EVP_PKEY *pkey,
const unsigned char **pder, int derlen)
{
ASN1_OCTET_STRING *os;
os = ASN1_OCTET_STRING_new();
if (!os || !ASN1_OCTET_STRING_set(os, *pder, derlen))
return 0;
EVP_PKEY_assign(pkey, EVP_PKEY_HMAC, os);
return 1;
}
static int old_hmac_encode(const EVP_PKEY *pkey, unsigned char **pder)
{
int inc;
ASN1_OCTET_STRING *os = (ASN1_OCTET_STRING *)pkey->pkey.ptr;
if (pder)
{
if (!*pder)
{
*pder = OPENSSL_malloc(os->length);
inc = 0;
}
else inc = 1;
memcpy(*pder, os->data, os->length);
if (inc)
*pder += os->length;
}
return os->length;
}
