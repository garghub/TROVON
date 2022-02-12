SCT_CTX *SCT_CTX_new(void)
{
SCT_CTX *sctx = OPENSSL_zalloc(sizeof(*sctx));
if (sctx == NULL)
CTerr(CT_F_SCT_CTX_NEW, ERR_R_MALLOC_FAILURE);
return sctx;
}
void SCT_CTX_free(SCT_CTX *sctx)
{
if (sctx == NULL)
return;
EVP_PKEY_free(sctx->pkey);
OPENSSL_free(sctx->pkeyhash);
OPENSSL_free(sctx->ihash);
OPENSSL_free(sctx->certder);
OPENSSL_free(sctx->preder);
OPENSSL_free(sctx);
}
static int ct_x509_get_ext(X509 *cert, int nid, int *is_duplicated)
{
int ret = X509_get_ext_by_NID(cert, nid, -1);
if (is_duplicated != NULL)
*is_duplicated = ret >= 0 && X509_get_ext_by_NID(cert, nid, ret) >= 0;
return ret;
}
__owur static int ct_x509_cert_fixup(X509 *cert, X509 *presigner)
{
int preidx, certidx;
int pre_akid_ext_is_dup, cert_akid_ext_is_dup;
if (presigner == NULL)
return 1;
preidx = ct_x509_get_ext(presigner, NID_authority_key_identifier,
&pre_akid_ext_is_dup);
certidx = ct_x509_get_ext(cert, NID_authority_key_identifier,
&cert_akid_ext_is_dup);
if (preidx < -1 || certidx < -1)
return 0;
if (pre_akid_ext_is_dup || cert_akid_ext_is_dup)
return 0;
if (preidx >= 0 && certidx == -1)
return 0;
if (preidx == -1 && certidx >= 0)
return 0;
if (!X509_set_issuer_name(cert, X509_get_issuer_name(presigner)))
return 0;
if (preidx != -1) {
X509_EXTENSION *preext = X509_get_ext(presigner, preidx);
X509_EXTENSION *certext = X509_get_ext(cert, certidx);
ASN1_OCTET_STRING *preextdata;
if (preext == NULL || certext == NULL)
return 0;
preextdata = X509_EXTENSION_get_data(preext);
if (preextdata == NULL ||
!X509_EXTENSION_set_data(certext, preextdata))
return 0;
}
return 1;
}
int SCT_CTX_set1_cert(SCT_CTX *sctx, X509 *cert, X509 *presigner)
{
unsigned char *certder = NULL, *preder = NULL;
X509 *pretmp = NULL;
int certderlen = 0, prederlen = 0;
int idx = -1;
int poison_ext_is_dup, sct_ext_is_dup;
int poison_idx = ct_x509_get_ext(cert, NID_ct_precert_poison, &poison_ext_is_dup);
if (poison_ext_is_dup)
goto err;
if (poison_idx == -1) {
if (presigner != NULL)
goto err;
certderlen = i2d_X509(cert, &certder);
if (certderlen < 0)
goto err;
}
idx = ct_x509_get_ext(cert, NID_ct_precert_scts, &sct_ext_is_dup);
if (sct_ext_is_dup)
goto err;
if (idx >= 0 && poison_idx >= 0) {
goto err;
}
if (idx == -1) {
idx = poison_idx;
}
if (idx >= 0) {
X509_EXTENSION *ext;
pretmp = X509_dup(cert);
if (pretmp == NULL)
goto err;
ext = X509_delete_ext(pretmp, idx);
X509_EXTENSION_free(ext);
if (!ct_x509_cert_fixup(pretmp, presigner))
goto err;
prederlen = i2d_re_X509_tbs(pretmp, &preder);
if (prederlen <= 0)
goto err;
}
X509_free(pretmp);
OPENSSL_free(sctx->certder);
sctx->certder = certder;
sctx->certderlen = certderlen;
OPENSSL_free(sctx->preder);
sctx->preder = preder;
sctx->prederlen = prederlen;
return 1;
err:
OPENSSL_free(certder);
OPENSSL_free(preder);
X509_free(pretmp);
return 0;
}
__owur static int ct_public_key_hash(X509_PUBKEY *pkey, unsigned char **hash,
size_t *hash_len)
{
int ret = 0;
unsigned char *md = NULL, *der = NULL;
int der_len;
unsigned int md_len;
if (*hash != NULL && *hash_len >= SHA256_DIGEST_LENGTH) {
md = *hash;
} else {
md = OPENSSL_malloc(SHA256_DIGEST_LENGTH);
if (md == NULL)
goto err;
}
der_len = i2d_X509_PUBKEY(pkey, &der);
if (der_len <= 0)
goto err;
if (!EVP_Digest(der, der_len, md, &md_len, EVP_sha256(), NULL))
goto err;
if (md != *hash) {
OPENSSL_free(*hash);
*hash = md;
*hash_len = SHA256_DIGEST_LENGTH;
}
md = NULL;
ret = 1;
err:
OPENSSL_free(md);
OPENSSL_free(der);
return ret;
}
int SCT_CTX_set1_issuer(SCT_CTX *sctx, const X509 *issuer)
{
return SCT_CTX_set1_issuer_pubkey(sctx, X509_get_X509_PUBKEY(issuer));
}
int SCT_CTX_set1_issuer_pubkey(SCT_CTX *sctx, X509_PUBKEY *pubkey)
{
return ct_public_key_hash(pubkey, &sctx->ihash, &sctx->ihashlen);
}
int SCT_CTX_set1_pubkey(SCT_CTX *sctx, X509_PUBKEY *pubkey)
{
EVP_PKEY *pkey = X509_PUBKEY_get(pubkey);
if (pkey == NULL)
return 0;
if (!ct_public_key_hash(pubkey, &sctx->pkeyhash, &sctx->pkeyhashlen)) {
EVP_PKEY_free(pkey);
return 0;
}
EVP_PKEY_free(sctx->pkey);
sctx->pkey = pkey;
return 1;
}
