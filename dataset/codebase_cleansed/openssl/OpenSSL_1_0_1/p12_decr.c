unsigned char * PKCS12_pbe_crypt(X509_ALGOR *algor, const char *pass,
int passlen, unsigned char *in, int inlen, unsigned char **data,
int *datalen, int en_de)
{
unsigned char *out;
int outlen, i;
EVP_CIPHER_CTX ctx;
EVP_CIPHER_CTX_init(&ctx);
if (!EVP_PBE_CipherInit(algor->algorithm, pass, passlen,
algor->parameter, &ctx, en_de)) {
PKCS12err(PKCS12_F_PKCS12_PBE_CRYPT,PKCS12_R_PKCS12_ALGOR_CIPHERINIT_ERROR);
return NULL;
}
if(!(out = OPENSSL_malloc(inlen + EVP_CIPHER_CTX_block_size(&ctx)))) {
PKCS12err(PKCS12_F_PKCS12_PBE_CRYPT,ERR_R_MALLOC_FAILURE);
goto err;
}
if (!EVP_CipherUpdate(&ctx, out, &i, in, inlen))
{
OPENSSL_free(out);
out = NULL;
PKCS12err(PKCS12_F_PKCS12_PBE_CRYPT,ERR_R_EVP_LIB);
goto err;
}
outlen = i;
if(!EVP_CipherFinal_ex(&ctx, out + i, &i)) {
OPENSSL_free(out);
out = NULL;
PKCS12err(PKCS12_F_PKCS12_PBE_CRYPT,PKCS12_R_PKCS12_CIPHERFINAL_ERROR);
goto err;
}
outlen += i;
if (datalen) *datalen = outlen;
if (data) *data = out;
err:
EVP_CIPHER_CTX_cleanup(&ctx);
return out;
}
void * PKCS12_item_decrypt_d2i(X509_ALGOR *algor, const ASN1_ITEM *it,
const char *pass, int passlen, ASN1_OCTET_STRING *oct, int zbuf)
{
unsigned char *out;
const unsigned char *p;
void *ret;
int outlen;
if (!PKCS12_pbe_crypt(algor, pass, passlen, oct->data, oct->length,
&out, &outlen, 0)) {
PKCS12err(PKCS12_F_PKCS12_ITEM_DECRYPT_D2I,PKCS12_R_PKCS12_PBE_CRYPT_ERROR);
return NULL;
}
p = out;
#ifdef DEBUG_DECRYPT
{
FILE *op;
char fname[30];
static int fnm = 1;
sprintf(fname, "DER%d", fnm++);
op = fopen(fname, "wb");
fwrite (p, 1, outlen, op);
fclose(op);
}
#endif
ret = ASN1_item_d2i(NULL, &p, outlen, it);
if (zbuf) OPENSSL_cleanse(out, outlen);
if(!ret) PKCS12err(PKCS12_F_PKCS12_ITEM_DECRYPT_D2I,PKCS12_R_DECODE_ERROR);
OPENSSL_free(out);
return ret;
}
ASN1_OCTET_STRING *PKCS12_item_i2d_encrypt(X509_ALGOR *algor, const ASN1_ITEM *it,
const char *pass, int passlen,
void *obj, int zbuf)
{
ASN1_OCTET_STRING *oct;
unsigned char *in = NULL;
int inlen;
if (!(oct = M_ASN1_OCTET_STRING_new ())) {
PKCS12err(PKCS12_F_PKCS12_ITEM_I2D_ENCRYPT,ERR_R_MALLOC_FAILURE);
return NULL;
}
inlen = ASN1_item_i2d(obj, &in, it);
if (!in) {
PKCS12err(PKCS12_F_PKCS12_ITEM_I2D_ENCRYPT,PKCS12_R_ENCODE_ERROR);
return NULL;
}
if (!PKCS12_pbe_crypt(algor, pass, passlen, in, inlen, &oct->data,
&oct->length, 1)) {
PKCS12err(PKCS12_F_PKCS12_ITEM_I2D_ENCRYPT,PKCS12_R_ENCRYPT_ERROR);
OPENSSL_free(in);
return NULL;
}
if (zbuf) OPENSSL_cleanse(in, inlen);
OPENSSL_free(in);
return oct;
}
