X509_ALGOR *PKCS5_pbe2_set_scrypt(const EVP_CIPHER *cipher,
const unsigned char *salt, int saltlen,
unsigned char *aiv, uint64_t N, uint64_t r,
uint64_t p)
{
X509_ALGOR *scheme = NULL, *kalg = NULL, *ret = NULL;
int alg_nid;
size_t keylen = 0;
EVP_CIPHER_CTX *ctx = NULL;
unsigned char iv[EVP_MAX_IV_LENGTH];
PBE2PARAM *pbe2 = NULL;
ASN1_OBJECT *obj;
if (!cipher) {
ASN1err(ASN1_F_PKCS5_PBE2_SET_SCRYPT, ERR_R_PASSED_NULL_PARAMETER);
goto err;
}
if (EVP_PBE_scrypt(NULL, 0, NULL, 0, N, r, p, 0, NULL, 0) == 0) {
ASN1err(ASN1_F_PKCS5_PBE2_SET_SCRYPT,
ASN1_R_INVALID_SCRYPT_PARAMETERS);
goto err;
}
alg_nid = EVP_CIPHER_type(cipher);
if (alg_nid == NID_undef) {
ASN1err(ASN1_F_PKCS5_PBE2_SET_SCRYPT,
ASN1_R_CIPHER_HAS_NO_OBJECT_IDENTIFIER);
goto err;
}
obj = OBJ_nid2obj(alg_nid);
pbe2 = PBE2PARAM_new();
if (pbe2 == NULL)
goto merr;
scheme = pbe2->encryption;
scheme->algorithm = obj;
scheme->parameter = ASN1_TYPE_new();
if (scheme->parameter == NULL)
goto merr;
if (EVP_CIPHER_iv_length(cipher)) {
if (aiv)
memcpy(iv, aiv, EVP_CIPHER_iv_length(cipher));
else if (RAND_bytes(iv, EVP_CIPHER_iv_length(cipher)) < 0)
goto err;
}
ctx = EVP_CIPHER_CTX_new();
if (ctx == NULL)
goto merr;
if (EVP_CipherInit_ex(ctx, cipher, NULL, NULL, iv, 0) == 0)
goto err;
if (EVP_CIPHER_param_to_asn1(ctx, scheme->parameter) < 0) {
ASN1err(ASN1_F_PKCS5_PBE2_SET_SCRYPT,
ASN1_R_ERROR_SETTING_CIPHER_PARAMS);
goto err;
}
EVP_CIPHER_CTX_free(ctx);
ctx = NULL;
if (alg_nid == NID_rc2_cbc)
keylen = EVP_CIPHER_key_length(cipher);
X509_ALGOR_free(pbe2->keyfunc);
pbe2->keyfunc = pkcs5_scrypt_set(salt, saltlen, keylen, N, r, p);
if (pbe2->keyfunc == NULL)
goto merr;
ret = X509_ALGOR_new();
if (ret == NULL)
goto merr;
ret->algorithm = OBJ_nid2obj(NID_pbes2);
if (ASN1_TYPE_pack_sequence(ASN1_ITEM_rptr(PBE2PARAM), pbe2,
&ret->parameter) == NULL)
goto merr;
PBE2PARAM_free(pbe2);
pbe2 = NULL;
return ret;
merr:
ASN1err(ASN1_F_PKCS5_PBE2_SET_SCRYPT, ERR_R_MALLOC_FAILURE);
err:
PBE2PARAM_free(pbe2);
X509_ALGOR_free(kalg);
X509_ALGOR_free(ret);
EVP_CIPHER_CTX_free(ctx);
return NULL;
}
static X509_ALGOR *pkcs5_scrypt_set(const unsigned char *salt, size_t saltlen,
size_t keylen, uint64_t N, uint64_t r,
uint64_t p)
{
X509_ALGOR *keyfunc = NULL;
SCRYPT_PARAMS *sparam = NULL;
sparam = SCRYPT_PARAMS_new();
if (sparam == NULL)
goto merr;
if (!saltlen)
saltlen = PKCS5_SALT_LEN;
if (ASN1_STRING_set(sparam->salt, salt, saltlen) == 0)
goto merr;
if (salt == NULL && RAND_bytes(sparam->salt->data, saltlen) <= 0)
goto err;
if (ASN1_INTEGER_set_uint64(sparam->costParameter, N) == 0)
goto merr;
if (ASN1_INTEGER_set_uint64(sparam->blockSize, r) == 0)
goto merr;
if (ASN1_INTEGER_set_uint64(sparam->parallelizationParameter, p) == 0)
goto merr;
if (keylen > 0) {
sparam->keyLength = ASN1_INTEGER_new();
if (sparam->keyLength == NULL)
goto merr;
if (ASN1_INTEGER_set_int64(sparam->keyLength, keylen) == 0)
goto merr;
}
keyfunc = X509_ALGOR_new();
if (keyfunc == NULL)
goto merr;
keyfunc->algorithm = OBJ_nid2obj(NID_id_scrypt);
if (ASN1_TYPE_pack_sequence(ASN1_ITEM_rptr(SCRYPT_PARAMS), sparam,
&keyfunc->parameter) == NULL)
goto merr;
SCRYPT_PARAMS_free(sparam);
return keyfunc;
merr:
ASN1err(ASN1_F_PKCS5_SCRYPT_SET, ERR_R_MALLOC_FAILURE);
err:
SCRYPT_PARAMS_free(sparam);
X509_ALGOR_free(keyfunc);
return NULL;
}
int PKCS5_v2_scrypt_keyivgen(EVP_CIPHER_CTX *ctx, const char *pass,
int passlen, ASN1_TYPE *param,
const EVP_CIPHER *c, const EVP_MD *md, int en_de)
{
unsigned char *salt, key[EVP_MAX_KEY_LENGTH];
uint64_t p, r, N;
size_t saltlen;
size_t keylen = 0;
int rv = 0;
SCRYPT_PARAMS *sparam = NULL;
if (EVP_CIPHER_CTX_cipher(ctx) == NULL) {
EVPerr(EVP_F_PKCS5_V2_SCRYPT_KEYIVGEN, EVP_R_NO_CIPHER_SET);
goto err;
}
sparam = ASN1_TYPE_unpack_sequence(ASN1_ITEM_rptr(SCRYPT_PARAMS), param);
if (sparam == NULL) {
EVPerr(EVP_F_PKCS5_V2_SCRYPT_KEYIVGEN, EVP_R_DECODE_ERROR);
goto err;
}
keylen = EVP_CIPHER_CTX_key_length(ctx);
if (sparam->keyLength) {
uint64_t spkeylen;
if ((ASN1_INTEGER_get_uint64(&spkeylen, sparam->keyLength) == 0)
|| (spkeylen != keylen)) {
EVPerr(EVP_F_PKCS5_V2_SCRYPT_KEYIVGEN,
EVP_R_UNSUPPORTED_KEYLENGTH);
goto err;
}
}
if (ASN1_INTEGER_get_uint64(&N, sparam->costParameter) == 0
|| ASN1_INTEGER_get_uint64(&r, sparam->blockSize) == 0
|| ASN1_INTEGER_get_uint64(&p, sparam->parallelizationParameter) == 0
|| EVP_PBE_scrypt(NULL, 0, NULL, 0, N, r, p, 0, NULL, 0) == 0) {
EVPerr(EVP_F_PKCS5_V2_SCRYPT_KEYIVGEN,
EVP_R_ILLEGAL_SCRYPT_PARAMETERS);
goto err;
}
salt = sparam->salt->data;
saltlen = sparam->salt->length;
if (EVP_PBE_scrypt(pass, passlen, salt, saltlen, N, r, p, 0, key, keylen)
== 0)
goto err;
rv = EVP_CipherInit_ex(ctx, NULL, NULL, key, NULL, en_de);
err:
if (keylen)
OPENSSL_cleanse(key, keylen);
SCRYPT_PARAMS_free(sparam);
return rv;
}
