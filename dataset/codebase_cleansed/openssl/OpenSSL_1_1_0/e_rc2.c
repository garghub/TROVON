const EVP_CIPHER *EVP_rc2_64_cbc(void)
{
return (&r2_64_cbc_cipher);
}
const EVP_CIPHER *EVP_rc2_40_cbc(void)
{
return (&r2_40_cbc_cipher);
}
static int rc2_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
RC2_set_key(&data(ctx)->ks, EVP_CIPHER_CTX_key_length(ctx),
key, data(ctx)->key_bits);
return 1;
}
static int rc2_meth_to_magic(EVP_CIPHER_CTX *e)
{
int i;
EVP_CIPHER_CTX_ctrl(e, EVP_CTRL_GET_RC2_KEY_BITS, 0, &i);
if (i == 128)
return (RC2_128_MAGIC);
else if (i == 64)
return (RC2_64_MAGIC);
else if (i == 40)
return (RC2_40_MAGIC);
else
return (0);
}
static int rc2_magic_to_meth(int i)
{
if (i == RC2_128_MAGIC)
return 128;
else if (i == RC2_64_MAGIC)
return 64;
else if (i == RC2_40_MAGIC)
return 40;
else {
EVPerr(EVP_F_RC2_MAGIC_TO_METH, EVP_R_UNSUPPORTED_KEY_SIZE);
return (0);
}
}
static int rc2_get_asn1_type_and_iv(EVP_CIPHER_CTX *c, ASN1_TYPE *type)
{
long num = 0;
int i = 0;
int key_bits;
unsigned int l;
unsigned char iv[EVP_MAX_IV_LENGTH];
if (type != NULL) {
l = EVP_CIPHER_CTX_iv_length(c);
OPENSSL_assert(l <= sizeof(iv));
i = ASN1_TYPE_get_int_octetstring(type, &num, iv, l);
if (i != (int)l)
return -1;
key_bits = rc2_magic_to_meth((int)num);
if (!key_bits)
return -1;
if (i > 0 && !EVP_CipherInit_ex(c, NULL, NULL, NULL, iv, -1))
return -1;
EVP_CIPHER_CTX_ctrl(c, EVP_CTRL_SET_RC2_KEY_BITS, key_bits, NULL);
if (EVP_CIPHER_CTX_set_key_length(c, key_bits / 8) <= 0)
return -1;
}
return i;
}
static int rc2_set_asn1_type_and_iv(EVP_CIPHER_CTX *c, ASN1_TYPE *type)
{
long num;
int i = 0, j;
if (type != NULL) {
num = rc2_meth_to_magic(c);
j = EVP_CIPHER_CTX_iv_length(c);
i = ASN1_TYPE_set_int_octetstring(type, num,
(unsigned char *)EVP_CIPHER_CTX_original_iv(c),
j);
}
return (i);
}
static int rc2_ctrl(EVP_CIPHER_CTX *c, int type, int arg, void *ptr)
{
switch (type) {
case EVP_CTRL_INIT:
data(c)->key_bits = EVP_CIPHER_CTX_key_length(c) * 8;
return 1;
case EVP_CTRL_GET_RC2_KEY_BITS:
*(int *)ptr = data(c)->key_bits;
return 1;
case EVP_CTRL_SET_RC2_KEY_BITS:
if (arg > 0) {
data(c)->key_bits = arg;
return 1;
}
return 0;
# ifdef PBE_PRF_TEST
case EVP_CTRL_PBE_PRF_NID:
*(int *)ptr = NID_hmacWithMD5;
return 1;
# endif
default:
return -1;
}
}
