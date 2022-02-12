int CMS_RecipientInfo_set0_password(CMS_RecipientInfo *ri,
unsigned char *pass, ossl_ssize_t passlen)
{
CMS_PasswordRecipientInfo *pwri;
if (ri->type != CMS_RECIPINFO_PASS) {
CMSerr(CMS_F_CMS_RECIPIENTINFO_SET0_PASSWORD, CMS_R_NOT_PWRI);
return 0;
}
pwri = ri->d.pwri;
pwri->pass = pass;
if (pass && passlen < 0)
passlen = strlen((char *)pass);
pwri->passlen = passlen;
return 1;
}
CMS_RecipientInfo *CMS_add0_recipient_password(CMS_ContentInfo *cms,
int iter, int wrap_nid,
int pbe_nid,
unsigned char *pass,
ossl_ssize_t passlen,
const EVP_CIPHER *kekciph)
{
CMS_RecipientInfo *ri = NULL;
CMS_EnvelopedData *env;
CMS_PasswordRecipientInfo *pwri;
EVP_CIPHER_CTX ctx;
X509_ALGOR *encalg = NULL;
unsigned char iv[EVP_MAX_IV_LENGTH];
int ivlen;
env = cms_get0_enveloped(cms);
if (!env)
return NULL;
if (wrap_nid <= 0)
wrap_nid = NID_id_alg_PWRI_KEK;
if (pbe_nid <= 0)
pbe_nid = NID_id_pbkdf2;
if (kekciph == NULL)
kekciph = env->encryptedContentInfo->cipher;
if (kekciph == NULL) {
CMSerr(CMS_F_CMS_ADD0_RECIPIENT_PASSWORD, CMS_R_NO_CIPHER);
return NULL;
}
if (wrap_nid != NID_id_alg_PWRI_KEK) {
CMSerr(CMS_F_CMS_ADD0_RECIPIENT_PASSWORD,
CMS_R_UNSUPPORTED_KEY_ENCRYPTION_ALGORITHM);
return NULL;
}
encalg = X509_ALGOR_new();
EVP_CIPHER_CTX_init(&ctx);
if (EVP_EncryptInit_ex(&ctx, kekciph, NULL, NULL, NULL) <= 0) {
CMSerr(CMS_F_CMS_ADD0_RECIPIENT_PASSWORD, ERR_R_EVP_LIB);
goto err;
}
ivlen = EVP_CIPHER_CTX_iv_length(&ctx);
if (ivlen > 0) {
if (RAND_pseudo_bytes(iv, ivlen) <= 0)
goto err;
if (EVP_EncryptInit_ex(&ctx, NULL, NULL, NULL, iv) <= 0) {
CMSerr(CMS_F_CMS_ADD0_RECIPIENT_PASSWORD, ERR_R_EVP_LIB);
goto err;
}
encalg->parameter = ASN1_TYPE_new();
if (!encalg->parameter) {
CMSerr(CMS_F_CMS_ADD0_RECIPIENT_PASSWORD, ERR_R_MALLOC_FAILURE);
goto err;
}
if (EVP_CIPHER_param_to_asn1(&ctx, encalg->parameter) <= 0) {
CMSerr(CMS_F_CMS_ADD0_RECIPIENT_PASSWORD,
CMS_R_CIPHER_PARAMETER_INITIALISATION_ERROR);
goto err;
}
}
encalg->algorithm = OBJ_nid2obj(EVP_CIPHER_CTX_type(&ctx));
EVP_CIPHER_CTX_cleanup(&ctx);
ri = M_ASN1_new_of(CMS_RecipientInfo);
if (!ri)
goto merr;
ri->d.pwri = M_ASN1_new_of(CMS_PasswordRecipientInfo);
if (!ri->d.pwri)
goto merr;
ri->type = CMS_RECIPINFO_PASS;
pwri = ri->d.pwri;
X509_ALGOR_free(pwri->keyEncryptionAlgorithm);
pwri->keyEncryptionAlgorithm = X509_ALGOR_new();
if (!pwri->keyEncryptionAlgorithm)
goto merr;
pwri->keyEncryptionAlgorithm->algorithm = OBJ_nid2obj(wrap_nid);
pwri->keyEncryptionAlgorithm->parameter = ASN1_TYPE_new();
if (!pwri->keyEncryptionAlgorithm->parameter)
goto merr;
if (!ASN1_item_pack(encalg, ASN1_ITEM_rptr(X509_ALGOR),
&pwri->keyEncryptionAlgorithm->parameter->
value.sequence))
goto merr;
pwri->keyEncryptionAlgorithm->parameter->type = V_ASN1_SEQUENCE;
X509_ALGOR_free(encalg);
encalg = NULL;
pwri->keyDerivationAlgorithm = PKCS5_pbkdf2_set(iter, NULL, 0, -1, -1);
if (!pwri->keyDerivationAlgorithm)
goto err;
CMS_RecipientInfo_set0_password(ri, pass, passlen);
pwri->version = 0;
if (!sk_CMS_RecipientInfo_push(env->recipientInfos, ri))
goto merr;
return ri;
merr:
CMSerr(CMS_F_CMS_ADD0_RECIPIENT_PASSWORD, ERR_R_MALLOC_FAILURE);
err:
EVP_CIPHER_CTX_cleanup(&ctx);
if (ri)
M_ASN1_free_of(ri, CMS_RecipientInfo);
if (encalg)
X509_ALGOR_free(encalg);
return NULL;
}
static int kek_unwrap_key(unsigned char *out, size_t *outlen,
const unsigned char *in, size_t inlen,
EVP_CIPHER_CTX *ctx)
{
size_t blocklen = EVP_CIPHER_CTX_block_size(ctx);
unsigned char *tmp;
int outl, rv = 0;
if (inlen < 2 * blocklen) {
return 0;
}
if (inlen % blocklen) {
return 0;
}
tmp = OPENSSL_malloc(inlen);
EVP_DecryptUpdate(ctx, tmp + inlen - 2 * blocklen, &outl,
in + inlen - 2 * blocklen, blocklen * 2);
EVP_DecryptUpdate(ctx, tmp, &outl, tmp + inlen - blocklen, blocklen);
EVP_DecryptUpdate(ctx, tmp, &outl, in, inlen - blocklen);
EVP_DecryptInit_ex(ctx, NULL, NULL, NULL, NULL);
EVP_DecryptUpdate(ctx, tmp, &outl, tmp, inlen);
if (((tmp[1] ^ tmp[4]) & (tmp[2] ^ tmp[5]) & (tmp[3] ^ tmp[6])) != 0xff) {
goto err;
}
if (inlen < (size_t)(tmp[0] - 4)) {
goto err;
}
*outlen = (size_t)tmp[0];
memcpy(out, tmp + 4, *outlen);
rv = 1;
err:
OPENSSL_cleanse(tmp, inlen);
OPENSSL_free(tmp);
return rv;
}
static int kek_wrap_key(unsigned char *out, size_t *outlen,
const unsigned char *in, size_t inlen,
EVP_CIPHER_CTX *ctx)
{
size_t blocklen = EVP_CIPHER_CTX_block_size(ctx);
size_t olen;
int dummy;
olen = (inlen + 4 + blocklen - 1) / blocklen;
olen *= blocklen;
if (olen < 2 * blocklen) {
return 0;
}
if (inlen > 0xFF) {
return 0;
}
if (out) {
out[0] = (unsigned char)inlen;
out[1] = in[0] ^ 0xFF;
out[2] = in[1] ^ 0xFF;
out[3] = in[2] ^ 0xFF;
memcpy(out + 4, in, inlen);
if (olen > inlen + 4)
RAND_pseudo_bytes(out + 4 + inlen, olen - 4 - inlen);
EVP_EncryptUpdate(ctx, out, &dummy, out, olen);
EVP_EncryptUpdate(ctx, out, &dummy, out, olen);
}
*outlen = olen;
return 1;
}
int cms_RecipientInfo_pwri_crypt(CMS_ContentInfo *cms, CMS_RecipientInfo *ri,
int en_de)
{
CMS_EncryptedContentInfo *ec;
CMS_PasswordRecipientInfo *pwri;
const unsigned char *p = NULL;
int plen;
int r = 0;
X509_ALGOR *algtmp, *kekalg = NULL;
EVP_CIPHER_CTX kekctx;
const EVP_CIPHER *kekcipher;
unsigned char *key = NULL;
size_t keylen;
ec = cms->d.envelopedData->encryptedContentInfo;
pwri = ri->d.pwri;
EVP_CIPHER_CTX_init(&kekctx);
if (!pwri->pass) {
CMSerr(CMS_F_CMS_RECIPIENTINFO_PWRI_CRYPT, CMS_R_NO_PASSWORD);
return 0;
}
algtmp = pwri->keyEncryptionAlgorithm;
if (!algtmp || OBJ_obj2nid(algtmp->algorithm) != NID_id_alg_PWRI_KEK) {
CMSerr(CMS_F_CMS_RECIPIENTINFO_PWRI_CRYPT,
CMS_R_UNSUPPORTED_KEY_ENCRYPTION_ALGORITHM);
return 0;
}
if (algtmp->parameter->type == V_ASN1_SEQUENCE) {
p = algtmp->parameter->value.sequence->data;
plen = algtmp->parameter->value.sequence->length;
kekalg = d2i_X509_ALGOR(NULL, &p, plen);
}
if (kekalg == NULL) {
CMSerr(CMS_F_CMS_RECIPIENTINFO_PWRI_CRYPT,
CMS_R_INVALID_KEY_ENCRYPTION_PARAMETER);
return 0;
}
kekcipher = EVP_get_cipherbyobj(kekalg->algorithm);
if (!kekcipher) {
CMSerr(CMS_F_CMS_RECIPIENTINFO_PWRI_CRYPT, CMS_R_UNKNOWN_CIPHER);
goto err;
}
if (!EVP_CipherInit_ex(&kekctx, kekcipher, NULL, NULL, NULL, en_de))
goto err;
EVP_CIPHER_CTX_set_padding(&kekctx, 0);
if (EVP_CIPHER_asn1_to_param(&kekctx, kekalg->parameter) < 0) {
CMSerr(CMS_F_CMS_RECIPIENTINFO_PWRI_CRYPT,
CMS_R_CIPHER_PARAMETER_INITIALISATION_ERROR);
goto err;
}
algtmp = pwri->keyDerivationAlgorithm;
if (EVP_PBE_CipherInit(algtmp->algorithm,
(char *)pwri->pass, pwri->passlen,
algtmp->parameter, &kekctx, en_de) < 0) {
CMSerr(CMS_F_CMS_RECIPIENTINFO_PWRI_CRYPT, ERR_R_EVP_LIB);
goto err;
}
if (en_de) {
if (!kek_wrap_key(NULL, &keylen, ec->key, ec->keylen, &kekctx))
goto err;
key = OPENSSL_malloc(keylen);
if (!key)
goto err;
if (!kek_wrap_key(key, &keylen, ec->key, ec->keylen, &kekctx))
goto err;
pwri->encryptedKey->data = key;
pwri->encryptedKey->length = keylen;
} else {
key = OPENSSL_malloc(pwri->encryptedKey->length);
if (!key) {
CMSerr(CMS_F_CMS_RECIPIENTINFO_PWRI_CRYPT, ERR_R_MALLOC_FAILURE);
goto err;
}
if (!kek_unwrap_key(key, &keylen,
pwri->encryptedKey->data,
pwri->encryptedKey->length, &kekctx)) {
CMSerr(CMS_F_CMS_RECIPIENTINFO_PWRI_CRYPT, CMS_R_UNWRAP_FAILURE);
goto err;
}
ec->key = key;
ec->keylen = keylen;
}
r = 1;
err:
EVP_CIPHER_CTX_cleanup(&kekctx);
if (!r && key)
OPENSSL_free(key);
X509_ALGOR_free(kekalg);
return r;
}
