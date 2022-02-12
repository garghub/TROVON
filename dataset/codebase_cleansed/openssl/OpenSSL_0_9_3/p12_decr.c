unsigned char * PKCS12_pbe_crypt (X509_ALGOR *algor, const char *pass,
int passlen, unsigned char *in, int inlen, unsigned char **data,
int *datalen, int en_de)
{
unsigned char *out;
int outlen, i;
EVP_CIPHER_CTX ctx;
if(!(out = Malloc (inlen + 8))) {
PKCS12err(PKCS12_F_PKCS12_PBE_CRYPT,ERR_R_MALLOC_FAILURE);
return NULL;
}
if (!EVP_PBE_ALGOR_CipherInit (algor, pass, passlen, &ctx, en_de)) {
PKCS12err(PKCS12_F_PKCS12_PBE_CRYPT,PKCS12_R_PKCS12_ALGOR_CIPHERINIT_ERROR);
return NULL;
}
EVP_CipherUpdate (&ctx, out, &i, in, inlen);
outlen = i;
if(!EVP_CipherFinal (&ctx, out + i, &i)) {
Free (out);
PKCS12err(PKCS12_F_PKCS12_PBE_CRYPT,PKCS12_R_PKCS12_CIPHERFINAL_ERROR);
return NULL;
}
outlen += i;
if (datalen) *datalen = outlen;
if (data) *data = out;
return out;
}
char * PKCS12_decrypt_d2i (X509_ALGOR *algor, char * (*d2i)(),
void (*free_func)(), const char *pass, int passlen,
ASN1_OCTET_STRING *oct, int seq)
{
unsigned char *out, *p;
char *ret;
int outlen;
if (!PKCS12_pbe_crypt (algor, pass, passlen, oct->data, oct->length,
&out, &outlen, 0)) {
PKCS12err(PKCS12_F_PKCS12_DECRYPT_D2I,PKCS12_R_PKCS12_PBE_CRYPT_ERROR);
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
if (seq & 1) ret = (char *) d2i_ASN1_SET(NULL, &p, outlen, d2i,
free_func, V_ASN1_SEQUENCE, V_ASN1_UNIVERSAL);
else ret = d2i(NULL, &p, outlen);
if (seq & 2) memset(out, 0, outlen);
if(!ret) PKCS12err(PKCS12_F_PKCS12_DECRYPT_D2I,PKCS12_R_DECODE_ERROR);
Free (out);
return ret;
}
ASN1_OCTET_STRING *PKCS12_i2d_encrypt (X509_ALGOR *algor, int (*i2d)(),
const char *pass, int passlen,
char *obj, int seq)
{
ASN1_OCTET_STRING *oct;
unsigned char *in, *p;
int inlen;
if (!(oct = ASN1_OCTET_STRING_new ())) {
PKCS12err(PKCS12_F_PKCS12_I2D_ENCRYPT,ERR_R_MALLOC_FAILURE);
return NULL;
}
if (seq) inlen = i2d_ASN1_SET((STACK *)obj, NULL, i2d, V_ASN1_SEQUENCE,
V_ASN1_UNIVERSAL, IS_SEQUENCE);
else inlen = i2d (obj, NULL);
if (!inlen) {
PKCS12err(PKCS12_F_PKCS12_I2D_ENCRYPT,PKCS12_R_ENCODE_ERROR);
return NULL;
}
if (!(in = Malloc (inlen))) {
PKCS12err(PKCS12_F_PKCS12_I2D_ENCRYPT,ERR_R_MALLOC_FAILURE);
return NULL;
}
p = in;
if (seq) i2d_ASN1_SET((STACK *)obj, &p, i2d, V_ASN1_SEQUENCE,
V_ASN1_UNIVERSAL, IS_SEQUENCE);
else i2d (obj, &p);
if (!PKCS12_pbe_crypt (algor, pass, passlen, in, inlen, &oct->data,
&oct->length, 1)) {
PKCS12err(PKCS12_F_PKCS12_I2D_ENCRYPT,PKCS12_R_ENCRYPT_ERROR);
Free(in);
return NULL;
}
Free (in);
return oct;
}
