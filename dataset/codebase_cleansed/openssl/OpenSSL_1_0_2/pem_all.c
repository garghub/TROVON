static RSA *pkey_get_rsa(EVP_PKEY *key, RSA **rsa)
{
RSA *rtmp;
if (!key)
return NULL;
rtmp = EVP_PKEY_get1_RSA(key);
EVP_PKEY_free(key);
if (!rtmp)
return NULL;
if (rsa) {
RSA_free(*rsa);
*rsa = rtmp;
}
return rtmp;
}
RSA *PEM_read_bio_RSAPrivateKey(BIO *bp, RSA **rsa, pem_password_cb *cb,
void *u)
{
EVP_PKEY *pktmp;
pktmp = PEM_read_bio_PrivateKey(bp, NULL, cb, u);
return pkey_get_rsa(pktmp, rsa);
}
RSA *PEM_read_RSAPrivateKey(FILE *fp, RSA **rsa, pem_password_cb *cb, void *u)
{
EVP_PKEY *pktmp;
pktmp = PEM_read_PrivateKey(fp, NULL, cb, u);
return pkey_get_rsa(pktmp, rsa);
}
int PEM_write_bio_RSAPrivateKey(BIO *bp, RSA *x, const EVP_CIPHER *enc,
unsigned char *kstr, int klen,
pem_password_cb *cb, void *u)
{
if (FIPS_mode()) {
EVP_PKEY *k;
int ret;
k = EVP_PKEY_new();
if (!k)
return 0;
EVP_PKEY_set1_RSA(k, x);
ret = PEM_write_bio_PrivateKey(bp, k, enc, kstr, klen, cb, u);
EVP_PKEY_free(k);
return ret;
} else
return PEM_ASN1_write_bio((i2d_of_void *)i2d_RSAPrivateKey,
PEM_STRING_RSA, bp, x, enc, kstr, klen, cb,
u);
}
int PEM_write_RSAPrivateKey(FILE *fp, RSA *x, const EVP_CIPHER *enc,
unsigned char *kstr, int klen,
pem_password_cb *cb, void *u)
{
if (FIPS_mode()) {
EVP_PKEY *k;
int ret;
k = EVP_PKEY_new();
if (!k)
return 0;
EVP_PKEY_set1_RSA(k, x);
ret = PEM_write_PrivateKey(fp, k, enc, kstr, klen, cb, u);
EVP_PKEY_free(k);
return ret;
} else
return PEM_ASN1_write((i2d_of_void *)i2d_RSAPrivateKey,
PEM_STRING_RSA, fp, x, enc, kstr, klen, cb, u);
}
static DSA *pkey_get_dsa(EVP_PKEY *key, DSA **dsa)
{
DSA *dtmp;
if (!key)
return NULL;
dtmp = EVP_PKEY_get1_DSA(key);
EVP_PKEY_free(key);
if (!dtmp)
return NULL;
if (dsa) {
DSA_free(*dsa);
*dsa = dtmp;
}
return dtmp;
}
DSA *PEM_read_bio_DSAPrivateKey(BIO *bp, DSA **dsa, pem_password_cb *cb,
void *u)
{
EVP_PKEY *pktmp;
pktmp = PEM_read_bio_PrivateKey(bp, NULL, cb, u);
return pkey_get_dsa(pktmp, dsa);
}
int PEM_write_bio_DSAPrivateKey(BIO *bp, DSA *x, const EVP_CIPHER *enc,
unsigned char *kstr, int klen,
pem_password_cb *cb, void *u)
{
if (FIPS_mode()) {
EVP_PKEY *k;
int ret;
k = EVP_PKEY_new();
if (!k)
return 0;
EVP_PKEY_set1_DSA(k, x);
ret = PEM_write_bio_PrivateKey(bp, k, enc, kstr, klen, cb, u);
EVP_PKEY_free(k);
return ret;
} else
return PEM_ASN1_write_bio((i2d_of_void *)i2d_DSAPrivateKey,
PEM_STRING_DSA, bp, x, enc, kstr, klen, cb,
u);
}
int PEM_write_DSAPrivateKey(FILE *fp, DSA *x, const EVP_CIPHER *enc,
unsigned char *kstr, int klen,
pem_password_cb *cb, void *u)
{
if (FIPS_mode()) {
EVP_PKEY *k;
int ret;
k = EVP_PKEY_new();
if (!k)
return 0;
EVP_PKEY_set1_DSA(k, x);
ret = PEM_write_PrivateKey(fp, k, enc, kstr, klen, cb, u);
EVP_PKEY_free(k);
return ret;
} else
return PEM_ASN1_write((i2d_of_void *)i2d_DSAPrivateKey,
PEM_STRING_DSA, fp, x, enc, kstr, klen, cb, u);
}
DSA *PEM_read_DSAPrivateKey(FILE *fp, DSA **dsa, pem_password_cb *cb, void *u)
{
EVP_PKEY *pktmp;
pktmp = PEM_read_PrivateKey(fp, NULL, cb, u);
return pkey_get_dsa(pktmp, dsa);
}
static EC_KEY *pkey_get_eckey(EVP_PKEY *key, EC_KEY **eckey)
{
EC_KEY *dtmp;
if (!key)
return NULL;
dtmp = EVP_PKEY_get1_EC_KEY(key);
EVP_PKEY_free(key);
if (!dtmp)
return NULL;
if (eckey) {
EC_KEY_free(*eckey);
*eckey = dtmp;
}
return dtmp;
}
EC_KEY *PEM_read_bio_ECPrivateKey(BIO *bp, EC_KEY **key, pem_password_cb *cb,
void *u)
{
EVP_PKEY *pktmp;
pktmp = PEM_read_bio_PrivateKey(bp, NULL, cb, u);
return pkey_get_eckey(pktmp, key);
}
int PEM_write_bio_ECPrivateKey(BIO *bp, EC_KEY *x, const EVP_CIPHER *enc,
unsigned char *kstr, int klen,
pem_password_cb *cb, void *u)
{
if (FIPS_mode()) {
EVP_PKEY *k;
int ret;
k = EVP_PKEY_new();
if (!k)
return 0;
EVP_PKEY_set1_EC_KEY(k, x);
ret = PEM_write_bio_PrivateKey(bp, k, enc, kstr, klen, cb, u);
EVP_PKEY_free(k);
return ret;
} else
return PEM_ASN1_write_bio((i2d_of_void *)i2d_ECPrivateKey,
PEM_STRING_ECPRIVATEKEY,
bp, x, enc, kstr, klen, cb, u);
}
int PEM_write_ECPrivateKey(FILE *fp, EC_KEY *x, const EVP_CIPHER *enc,
unsigned char *kstr, int klen,
pem_password_cb *cb, void *u)
{
if (FIPS_mode()) {
EVP_PKEY *k;
int ret;
k = EVP_PKEY_new();
if (!k)
return 0;
EVP_PKEY_set1_EC_KEY(k, x);
ret = PEM_write_PrivateKey(fp, k, enc, kstr, klen, cb, u);
EVP_PKEY_free(k);
return ret;
} else
return PEM_ASN1_write((i2d_of_void *)i2d_ECPrivateKey,
PEM_STRING_ECPRIVATEKEY,
fp, x, enc, kstr, klen, cb, u);
}
EC_KEY *PEM_read_ECPrivateKey(FILE *fp, EC_KEY **eckey, pem_password_cb *cb,
void *u)
{
EVP_PKEY *pktmp;
pktmp = PEM_read_PrivateKey(fp, NULL, cb, u);
return pkey_get_eckey(pktmp, eckey);
}
