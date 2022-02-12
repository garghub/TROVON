int X509_issuer_and_serial_cmp(const X509 *a, const X509 *b)
{
int i;
const X509_CINF *ai, *bi;
ai = &a->cert_info;
bi = &b->cert_info;
i = ASN1_INTEGER_cmp(&ai->serialNumber, &bi->serialNumber);
if (i)
return (i);
return (X509_NAME_cmp(ai->issuer, bi->issuer));
}
unsigned long X509_issuer_and_serial_hash(X509 *a)
{
unsigned long ret = 0;
EVP_MD_CTX *ctx = EVP_MD_CTX_new();
unsigned char md[16];
char *f;
if (ctx == NULL)
goto err;
f = X509_NAME_oneline(a->cert_info.issuer, NULL, 0);
if (!EVP_DigestInit_ex(ctx, EVP_md5(), NULL))
goto err;
if (!EVP_DigestUpdate(ctx, (unsigned char *)f, strlen(f)))
goto err;
OPENSSL_free(f);
if (!EVP_DigestUpdate
(ctx, (unsigned char *)a->cert_info.serialNumber.data,
(unsigned long)a->cert_info.serialNumber.length))
goto err;
if (!EVP_DigestFinal_ex(ctx, &(md[0]), NULL))
goto err;
ret = (((unsigned long)md[0]) | ((unsigned long)md[1] << 8L) |
((unsigned long)md[2] << 16L) | ((unsigned long)md[3] << 24L)
) & 0xffffffffL;
err:
EVP_MD_CTX_free(ctx);
return (ret);
}
int X509_issuer_name_cmp(const X509 *a, const X509 *b)
{
return (X509_NAME_cmp(a->cert_info.issuer, b->cert_info.issuer));
}
int X509_subject_name_cmp(const X509 *a, const X509 *b)
{
return (X509_NAME_cmp(a->cert_info.subject, b->cert_info.subject));
}
int X509_CRL_cmp(const X509_CRL *a, const X509_CRL *b)
{
return (X509_NAME_cmp(a->crl.issuer, b->crl.issuer));
}
int X509_CRL_match(const X509_CRL *a, const X509_CRL *b)
{
return memcmp(a->sha1_hash, b->sha1_hash, 20);
}
X509_NAME *X509_get_issuer_name(const X509 *a)
{
return (a->cert_info.issuer);
}
unsigned long X509_issuer_name_hash(X509 *x)
{
return (X509_NAME_hash(x->cert_info.issuer));
}
unsigned long X509_issuer_name_hash_old(X509 *x)
{
return (X509_NAME_hash_old(x->cert_info.issuer));
}
X509_NAME *X509_get_subject_name(const X509 *a)
{
return (a->cert_info.subject);
}
ASN1_INTEGER *X509_get_serialNumber(X509 *a)
{
return &a->cert_info.serialNumber;
}
const ASN1_INTEGER *X509_get0_serialNumber(const X509 *a)
{
return &a->cert_info.serialNumber;
}
unsigned long X509_subject_name_hash(X509 *x)
{
return (X509_NAME_hash(x->cert_info.subject));
}
unsigned long X509_subject_name_hash_old(X509 *x)
{
return (X509_NAME_hash_old(x->cert_info.subject));
}
int X509_cmp(const X509 *a, const X509 *b)
{
int rv;
X509_check_purpose((X509 *)a, -1, 0);
X509_check_purpose((X509 *)b, -1, 0);
rv = memcmp(a->sha1_hash, b->sha1_hash, SHA_DIGEST_LENGTH);
if (rv)
return rv;
if (!a->cert_info.enc.modified && !b->cert_info.enc.modified) {
if (a->cert_info.enc.len < b->cert_info.enc.len)
return -1;
if (a->cert_info.enc.len > b->cert_info.enc.len)
return 1;
return memcmp(a->cert_info.enc.enc, b->cert_info.enc.enc,
a->cert_info.enc.len);
}
return rv;
}
int X509_NAME_cmp(const X509_NAME *a, const X509_NAME *b)
{
int ret;
if (!a->canon_enc || a->modified) {
ret = i2d_X509_NAME((X509_NAME *)a, NULL);
if (ret < 0)
return -2;
}
if (!b->canon_enc || b->modified) {
ret = i2d_X509_NAME((X509_NAME *)b, NULL);
if (ret < 0)
return -2;
}
ret = a->canon_enclen - b->canon_enclen;
if (ret)
return ret;
return memcmp(a->canon_enc, b->canon_enc, a->canon_enclen);
}
unsigned long X509_NAME_hash(X509_NAME *x)
{
unsigned long ret = 0;
unsigned char md[SHA_DIGEST_LENGTH];
i2d_X509_NAME(x, NULL);
if (!EVP_Digest(x->canon_enc, x->canon_enclen, md, NULL, EVP_sha1(),
NULL))
return 0;
ret = (((unsigned long)md[0]) | ((unsigned long)md[1] << 8L) |
((unsigned long)md[2] << 16L) | ((unsigned long)md[3] << 24L)
) & 0xffffffffL;
return (ret);
}
unsigned long X509_NAME_hash_old(X509_NAME *x)
{
EVP_MD_CTX *md_ctx = EVP_MD_CTX_new();
unsigned long ret = 0;
unsigned char md[16];
if (md_ctx == NULL)
return ret;
i2d_X509_NAME(x, NULL);
EVP_MD_CTX_set_flags(md_ctx, EVP_MD_CTX_FLAG_NON_FIPS_ALLOW);
if (EVP_DigestInit_ex(md_ctx, EVP_md5(), NULL)
&& EVP_DigestUpdate(md_ctx, x->bytes->data, x->bytes->length)
&& EVP_DigestFinal_ex(md_ctx, md, NULL))
ret = (((unsigned long)md[0]) | ((unsigned long)md[1] << 8L) |
((unsigned long)md[2] << 16L) | ((unsigned long)md[3] << 24L)
) & 0xffffffffL;
EVP_MD_CTX_free(md_ctx);
return (ret);
}
EVP_PKEY *X509_get0_pubkey(const X509 *x)
{
if (x == NULL)
return NULL;
return X509_PUBKEY_get0(x->cert_info.key);
}
EVP_PKEY *X509_get_pubkey(X509 *x)
{
if (x == NULL)
return NULL;
return X509_PUBKEY_get(x->cert_info.key);
}
int X509_check_private_key(const X509 *x, const EVP_PKEY *k)
{
const EVP_PKEY *xk;
int ret;
xk = X509_get0_pubkey(x);
if (xk)
ret = EVP_PKEY_cmp(xk, k);
else
ret = -2;
switch (ret) {
case 1:
break;
case 0:
X509err(X509_F_X509_CHECK_PRIVATE_KEY, X509_R_KEY_VALUES_MISMATCH);
break;
case -1:
X509err(X509_F_X509_CHECK_PRIVATE_KEY, X509_R_KEY_TYPE_MISMATCH);
break;
case -2:
X509err(X509_F_X509_CHECK_PRIVATE_KEY, X509_R_UNKNOWN_KEY_TYPE);
}
if (ret > 0)
return 1;
return 0;
}
static int check_suite_b(EVP_PKEY *pkey, int sign_nid, unsigned long *pflags)
{
const EC_GROUP *grp = NULL;
int curve_nid;
if (pkey && EVP_PKEY_id(pkey) == EVP_PKEY_EC)
grp = EC_KEY_get0_group(EVP_PKEY_get0_EC_KEY(pkey));
if (!grp)
return X509_V_ERR_SUITE_B_INVALID_ALGORITHM;
curve_nid = EC_GROUP_get_curve_name(grp);
if (curve_nid == NID_secp384r1) {
if (sign_nid != -1 && sign_nid != NID_ecdsa_with_SHA384)
return X509_V_ERR_SUITE_B_INVALID_SIGNATURE_ALGORITHM;
if (!(*pflags & X509_V_FLAG_SUITEB_192_LOS))
return X509_V_ERR_SUITE_B_LOS_NOT_ALLOWED;
*pflags &= ~X509_V_FLAG_SUITEB_128_LOS_ONLY;
} else if (curve_nid == NID_X9_62_prime256v1) {
if (sign_nid != -1 && sign_nid != NID_ecdsa_with_SHA256)
return X509_V_ERR_SUITE_B_INVALID_SIGNATURE_ALGORITHM;
if (!(*pflags & X509_V_FLAG_SUITEB_128_LOS_ONLY))
return X509_V_ERR_SUITE_B_LOS_NOT_ALLOWED;
} else
return X509_V_ERR_SUITE_B_INVALID_CURVE;
return X509_V_OK;
}
int X509_CRL_check_suiteb(X509_CRL *crl, EVP_PKEY *pk, unsigned long flags)
{
int sign_nid;
if (!(flags & X509_V_FLAG_SUITEB_128_LOS))
return X509_V_OK;
sign_nid = OBJ_obj2nid(crl->crl.sig_alg.algorithm);
return check_suite_b(pk, sign_nid, &flags);
}
int X509_CRL_check_suiteb(X509_CRL *crl, EVP_PKEY *pk, unsigned long flags)
{
return 0;
}
