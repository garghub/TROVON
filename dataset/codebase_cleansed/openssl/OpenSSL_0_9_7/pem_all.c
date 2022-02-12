static RSA *pkey_get_rsa(EVP_PKEY *key, RSA **rsa)
{
RSA *rtmp;
if(!key) return NULL;
rtmp = EVP_PKEY_get1_RSA(key);
EVP_PKEY_free(key);
if(!rtmp) return NULL;
if(rsa) {
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
RSA *PEM_read_RSAPrivateKey(FILE *fp, RSA **rsa, pem_password_cb *cb,
void *u)
{
EVP_PKEY *pktmp;
pktmp = PEM_read_PrivateKey(fp, NULL, cb, u);
return pkey_get_rsa(pktmp, rsa);
}
static DSA *pkey_get_dsa(EVP_PKEY *key, DSA **dsa)
{
DSA *dtmp;
if(!key) return NULL;
dtmp = EVP_PKEY_get1_DSA(key);
EVP_PKEY_free(key);
if(!dtmp) return NULL;
if(dsa) {
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
DSA *PEM_read_DSAPrivateKey(FILE *fp, DSA **dsa, pem_password_cb *cb,
void *u)
{
EVP_PKEY *pktmp;
pktmp = PEM_read_PrivateKey(fp, NULL, cb, u);
return pkey_get_dsa(pktmp, dsa);
}
