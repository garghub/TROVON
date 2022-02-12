int PKCS5_PBKDF2_HMAC(const char *pass, int passlen,
const unsigned char *salt, int saltlen, int iter,
const EVP_MD *digest,
int keylen, unsigned char *out)
{
unsigned char digtmp[EVP_MAX_MD_SIZE], *p, itmp[4];
int cplen, j, k, tkeylen, mdlen;
unsigned long i = 1;
HMAC_CTX hctx;
mdlen = EVP_MD_size(digest);
if (mdlen < 0)
return 0;
HMAC_CTX_init(&hctx);
p = out;
tkeylen = keylen;
if(!pass)
passlen = 0;
else if(passlen == -1)
passlen = strlen(pass);
while(tkeylen)
{
if(tkeylen > mdlen)
cplen = mdlen;
else
cplen = tkeylen;
itmp[0] = (unsigned char)((i >> 24) & 0xff);
itmp[1] = (unsigned char)((i >> 16) & 0xff);
itmp[2] = (unsigned char)((i >> 8) & 0xff);
itmp[3] = (unsigned char)(i & 0xff);
HMAC_Init_ex(&hctx, pass, passlen, digest, NULL);
HMAC_Update(&hctx, salt, saltlen);
HMAC_Update(&hctx, itmp, 4);
HMAC_Final(&hctx, digtmp, NULL);
memcpy(p, digtmp, cplen);
for(j = 1; j < iter; j++)
{
HMAC(digest, pass, passlen,
digtmp, mdlen, digtmp, NULL);
for(k = 0; k < cplen; k++)
p[k] ^= digtmp[k];
}
tkeylen-= cplen;
i++;
p+= cplen;
}
HMAC_CTX_cleanup(&hctx);
#ifdef DEBUG_PKCS5V2
fprintf(stderr, "Password:\n");
h__dump (pass, passlen);
fprintf(stderr, "Salt:\n");
h__dump (salt, saltlen);
fprintf(stderr, "Iteration count %d\n", iter);
fprintf(stderr, "Key:\n");
h__dump (out, keylen);
#endif
return 1;
}
int PKCS5_PBKDF2_HMAC_SHA1(const char *pass, int passlen,
const unsigned char *salt, int saltlen, int iter,
int keylen, unsigned char *out)
{
return PKCS5_PBKDF2_HMAC(pass, passlen, salt, saltlen, iter, EVP_sha1(),
keylen, out);
}
main()
{
unsigned char out[4];
unsigned char salt[] = {0x12, 0x34, 0x56, 0x78};
PKCS5_PBKDF2_HMAC_SHA1("password", -1, salt, 4, 5, 4, out);
fprintf(stderr, "Out %02X %02X %02X %02X\n",
out[0], out[1], out[2], out[3]);
}
int PKCS5_v2_PBE_keyivgen(EVP_CIPHER_CTX *ctx, const char *pass, int passlen,
ASN1_TYPE *param, const EVP_CIPHER *c, const EVP_MD *md,
int en_de)
{
unsigned char *salt, key[EVP_MAX_KEY_LENGTH];
const unsigned char *pbuf;
int saltlen, iter, plen;
unsigned int keylen;
PBE2PARAM *pbe2 = NULL;
const EVP_CIPHER *cipher;
PBKDF2PARAM *kdf = NULL;
const EVP_MD *prfmd;
int prf_nid, hmac_md_nid;
if (param == NULL || param->type != V_ASN1_SEQUENCE ||
param->value.sequence == NULL) {
EVPerr(EVP_F_PKCS5_V2_PBE_KEYIVGEN,EVP_R_DECODE_ERROR);
return 0;
}
pbuf = param->value.sequence->data;
plen = param->value.sequence->length;
if(!(pbe2 = d2i_PBE2PARAM(NULL, &pbuf, plen))) {
EVPerr(EVP_F_PKCS5_V2_PBE_KEYIVGEN,EVP_R_DECODE_ERROR);
return 0;
}
if(OBJ_obj2nid(pbe2->keyfunc->algorithm) != NID_id_pbkdf2) {
EVPerr(EVP_F_PKCS5_V2_PBE_KEYIVGEN,
EVP_R_UNSUPPORTED_KEY_DERIVATION_FUNCTION);
goto err;
}
cipher = EVP_get_cipherbyobj(pbe2->encryption->algorithm);
if(!cipher) {
EVPerr(EVP_F_PKCS5_V2_PBE_KEYIVGEN,
EVP_R_UNSUPPORTED_CIPHER);
goto err;
}
EVP_CipherInit_ex(ctx, cipher, NULL, NULL, NULL, en_de);
if(EVP_CIPHER_asn1_to_param(ctx, pbe2->encryption->parameter) < 0) {
EVPerr(EVP_F_PKCS5_V2_PBE_KEYIVGEN,
EVP_R_CIPHER_PARAMETER_ERROR);
goto err;
}
keylen = EVP_CIPHER_CTX_key_length(ctx);
OPENSSL_assert(keylen <= sizeof key);
if(!pbe2->keyfunc->parameter ||
(pbe2->keyfunc->parameter->type != V_ASN1_SEQUENCE))
{
EVPerr(EVP_F_PKCS5_V2_PBE_KEYIVGEN,EVP_R_DECODE_ERROR);
goto err;
}
pbuf = pbe2->keyfunc->parameter->value.sequence->data;
plen = pbe2->keyfunc->parameter->value.sequence->length;
if(!(kdf = d2i_PBKDF2PARAM(NULL, &pbuf, plen)) ) {
EVPerr(EVP_F_PKCS5_V2_PBE_KEYIVGEN,EVP_R_DECODE_ERROR);
goto err;
}
PBE2PARAM_free(pbe2);
pbe2 = NULL;
if(kdf->keylength && (ASN1_INTEGER_get(kdf->keylength) != (int)keylen)){
EVPerr(EVP_F_PKCS5_V2_PBE_KEYIVGEN,
EVP_R_UNSUPPORTED_KEYLENGTH);
goto err;
}
if (kdf->prf)
prf_nid = OBJ_obj2nid(kdf->prf->algorithm);
else
prf_nid = NID_hmacWithSHA1;
if (!EVP_PBE_find(EVP_PBE_TYPE_PRF, prf_nid, NULL, &hmac_md_nid, 0))
{
EVPerr(EVP_F_PKCS5_V2_PBE_KEYIVGEN, EVP_R_UNSUPPORTED_PRF);
goto err;
}
prfmd = EVP_get_digestbynid(hmac_md_nid);
if (prfmd == NULL)
{
EVPerr(EVP_F_PKCS5_V2_PBE_KEYIVGEN, EVP_R_UNSUPPORTED_PRF);
goto err;
}
if(kdf->salt->type != V_ASN1_OCTET_STRING) {
EVPerr(EVP_F_PKCS5_V2_PBE_KEYIVGEN,
EVP_R_UNSUPPORTED_SALT_TYPE);
goto err;
}
salt = kdf->salt->value.octet_string->data;
saltlen = kdf->salt->value.octet_string->length;
iter = ASN1_INTEGER_get(kdf->iter);
if(!PKCS5_PBKDF2_HMAC(pass, passlen, salt, saltlen, iter, prfmd,
keylen, key))
goto err;
EVP_CipherInit_ex(ctx, NULL, NULL, key, NULL, en_de);
OPENSSL_cleanse(key, keylen);
PBKDF2PARAM_free(kdf);
return 1;
err:
PBE2PARAM_free(pbe2);
PBKDF2PARAM_free(kdf);
return 0;
}
static void h__dump (const unsigned char *p, int len)
{
for (; len --; p++) fprintf(stderr, "%02X ", *p);
fprintf(stderr, "\n");
}
