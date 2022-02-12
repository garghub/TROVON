const ASN1_OBJECT *CMS_get0_type(CMS_ContentInfo *cms)
{
return cms->contentType;
}
CMS_ContentInfo *cms_Data_create(void)
{
CMS_ContentInfo *cms;
cms = CMS_ContentInfo_new();
if (cms) {
cms->contentType = OBJ_nid2obj(NID_pkcs7_data);
CMS_set_detached(cms, 0);
}
return cms;
}
BIO *cms_content_bio(CMS_ContentInfo *cms)
{
ASN1_OCTET_STRING **pos = CMS_get0_content(cms);
if (!pos)
return NULL;
if (!*pos)
return BIO_new(BIO_s_null());
if (!*pos || ((*pos)->flags == ASN1_STRING_FLAG_CONT))
return BIO_new(BIO_s_mem());
return BIO_new_mem_buf((*pos)->data, (*pos)->length);
}
BIO *CMS_dataInit(CMS_ContentInfo *cms, BIO *icont)
{
BIO *cmsbio, *cont;
if (icont)
cont = icont;
else
cont = cms_content_bio(cms);
if (!cont) {
CMSerr(CMS_F_CMS_DATAINIT, CMS_R_NO_CONTENT);
return NULL;
}
switch (OBJ_obj2nid(cms->contentType)) {
case NID_pkcs7_data:
return cont;
case NID_pkcs7_signed:
cmsbio = cms_SignedData_init_bio(cms);
break;
case NID_pkcs7_digest:
cmsbio = cms_DigestedData_init_bio(cms);
break;
#ifdef ZLIB
case NID_id_smime_ct_compressedData:
cmsbio = cms_CompressedData_init_bio(cms);
break;
#endif
case NID_pkcs7_encrypted:
cmsbio = cms_EncryptedData_init_bio(cms);
break;
case NID_pkcs7_enveloped:
cmsbio = cms_EnvelopedData_init_bio(cms);
break;
default:
CMSerr(CMS_F_CMS_DATAINIT, CMS_R_UNSUPPORTED_TYPE);
return NULL;
}
if (cmsbio)
return BIO_push(cmsbio, cont);
if (!icont)
BIO_free(cont);
return NULL;
}
int CMS_dataFinal(CMS_ContentInfo *cms, BIO *cmsbio)
{
ASN1_OCTET_STRING **pos = CMS_get0_content(cms);
if (!pos)
return 0;
if (*pos && ((*pos)->flags & ASN1_STRING_FLAG_CONT)) {
BIO *mbio;
unsigned char *cont;
long contlen;
mbio = BIO_find_type(cmsbio, BIO_TYPE_MEM);
if (!mbio) {
CMSerr(CMS_F_CMS_DATAFINAL, CMS_R_CONTENT_NOT_FOUND);
return 0;
}
contlen = BIO_get_mem_data(mbio, &cont);
BIO_set_flags(mbio, BIO_FLAGS_MEM_RDONLY);
BIO_set_mem_eof_return(mbio, 0);
ASN1_STRING_set0(*pos, cont, contlen);
(*pos)->flags &= ~ASN1_STRING_FLAG_CONT;
}
switch (OBJ_obj2nid(cms->contentType)) {
case NID_pkcs7_data:
case NID_pkcs7_enveloped:
case NID_pkcs7_encrypted:
case NID_id_smime_ct_compressedData:
return 1;
case NID_pkcs7_signed:
return cms_SignedData_final(cms, cmsbio);
case NID_pkcs7_digest:
return cms_DigestedData_do_final(cms, cmsbio, 0);
default:
CMSerr(CMS_F_CMS_DATAFINAL, CMS_R_UNSUPPORTED_TYPE);
return 0;
}
}
ASN1_OCTET_STRING **CMS_get0_content(CMS_ContentInfo *cms)
{
switch (OBJ_obj2nid(cms->contentType)) {
case NID_pkcs7_data:
return &cms->d.data;
case NID_pkcs7_signed:
return &cms->d.signedData->encapContentInfo->eContent;
case NID_pkcs7_enveloped:
return &cms->d.envelopedData->encryptedContentInfo->encryptedContent;
case NID_pkcs7_digest:
return &cms->d.digestedData->encapContentInfo->eContent;
case NID_pkcs7_encrypted:
return &cms->d.encryptedData->encryptedContentInfo->encryptedContent;
case NID_id_smime_ct_authData:
return &cms->d.authenticatedData->encapContentInfo->eContent;
case NID_id_smime_ct_compressedData:
return &cms->d.compressedData->encapContentInfo->eContent;
default:
if (cms->d.other->type == V_ASN1_OCTET_STRING)
return &cms->d.other->value.octet_string;
CMSerr(CMS_F_CMS_GET0_CONTENT, CMS_R_UNSUPPORTED_CONTENT_TYPE);
return NULL;
}
}
static ASN1_OBJECT **cms_get0_econtent_type(CMS_ContentInfo *cms)
{
switch (OBJ_obj2nid(cms->contentType)) {
case NID_pkcs7_signed:
return &cms->d.signedData->encapContentInfo->eContentType;
case NID_pkcs7_enveloped:
return &cms->d.envelopedData->encryptedContentInfo->contentType;
case NID_pkcs7_digest:
return &cms->d.digestedData->encapContentInfo->eContentType;
case NID_pkcs7_encrypted:
return &cms->d.encryptedData->encryptedContentInfo->contentType;
case NID_id_smime_ct_authData:
return &cms->d.authenticatedData->encapContentInfo->eContentType;
case NID_id_smime_ct_compressedData:
return &cms->d.compressedData->encapContentInfo->eContentType;
default:
CMSerr(CMS_F_CMS_GET0_ECONTENT_TYPE, CMS_R_UNSUPPORTED_CONTENT_TYPE);
return NULL;
}
}
const ASN1_OBJECT *CMS_get0_eContentType(CMS_ContentInfo *cms)
{
ASN1_OBJECT **petype;
petype = cms_get0_econtent_type(cms);
if (petype)
return *petype;
return NULL;
}
int CMS_set1_eContentType(CMS_ContentInfo *cms, const ASN1_OBJECT *oid)
{
ASN1_OBJECT **petype, *etype;
petype = cms_get0_econtent_type(cms);
if (!petype)
return 0;
if (!oid)
return 1;
etype = OBJ_dup(oid);
if (!etype)
return 0;
ASN1_OBJECT_free(*petype);
*petype = etype;
return 1;
}
int CMS_is_detached(CMS_ContentInfo *cms)
{
ASN1_OCTET_STRING **pos;
pos = CMS_get0_content(cms);
if (!pos)
return -1;
if (*pos)
return 0;
return 1;
}
int CMS_set_detached(CMS_ContentInfo *cms, int detached)
{
ASN1_OCTET_STRING **pos;
pos = CMS_get0_content(cms);
if (!pos)
return 0;
if (detached) {
if (*pos) {
ASN1_OCTET_STRING_free(*pos);
*pos = NULL;
}
return 1;
}
if (!*pos)
*pos = ASN1_OCTET_STRING_new();
if (*pos) {
(*pos)->flags |= ASN1_STRING_FLAG_CONT;
return 1;
}
CMSerr(CMS_F_CMS_SET_DETACHED, ERR_R_MALLOC_FAILURE);
return 0;
}
void cms_DigestAlgorithm_set(X509_ALGOR *alg, const EVP_MD *md)
{
int param_type;
if (md->flags & EVP_MD_FLAG_DIGALGID_ABSENT)
param_type = V_ASN1_UNDEF;
else
param_type = V_ASN1_NULL;
X509_ALGOR_set0(alg, OBJ_nid2obj(EVP_MD_type(md)), param_type, NULL);
}
BIO *cms_DigestAlgorithm_init_bio(X509_ALGOR *digestAlgorithm)
{
BIO *mdbio = NULL;
ASN1_OBJECT *digestoid;
const EVP_MD *digest;
X509_ALGOR_get0(&digestoid, NULL, NULL, digestAlgorithm);
digest = EVP_get_digestbyobj(digestoid);
if (!digest) {
CMSerr(CMS_F_CMS_DIGESTALGORITHM_INIT_BIO,
CMS_R_UNKNOWN_DIGEST_ALGORIHM);
goto err;
}
mdbio = BIO_new(BIO_f_md());
if (!mdbio || !BIO_set_md(mdbio, digest)) {
CMSerr(CMS_F_CMS_DIGESTALGORITHM_INIT_BIO, CMS_R_MD_BIO_INIT_ERROR);
goto err;
}
return mdbio;
err:
if (mdbio)
BIO_free(mdbio);
return NULL;
}
int cms_DigestAlgorithm_find_ctx(EVP_MD_CTX *mctx, BIO *chain,
X509_ALGOR *mdalg)
{
int nid;
ASN1_OBJECT *mdoid;
X509_ALGOR_get0(&mdoid, NULL, NULL, mdalg);
nid = OBJ_obj2nid(mdoid);
for (;;) {
EVP_MD_CTX *mtmp;
chain = BIO_find_type(chain, BIO_TYPE_MD);
if (chain == NULL) {
CMSerr(CMS_F_CMS_DIGESTALGORITHM_FIND_CTX,
CMS_R_NO_MATCHING_DIGEST);
return 0;
}
BIO_get_md_ctx(chain, &mtmp);
if (EVP_MD_CTX_type(mtmp) == nid
|| EVP_MD_pkey_type(EVP_MD_CTX_md(mtmp)) == nid)
return EVP_MD_CTX_copy_ex(mctx, mtmp);
chain = BIO_next(chain);
}
}
int CMS_add1_cert(CMS_ContentInfo *cms, X509 *cert)
{
int r;
r = CMS_add0_cert(cms, cert);
if (r > 0)
CRYPTO_add(&cert->references, 1, CRYPTO_LOCK_X509);
return r;
}
int CMS_add1_crl(CMS_ContentInfo *cms, X509_CRL *crl)
{
int r;
r = CMS_add0_crl(cms, crl);
if (r > 0)
CRYPTO_add(&crl->references, 1, CRYPTO_LOCK_X509_CRL);
return r;
}
int cms_keyid_cert_cmp(ASN1_OCTET_STRING *keyid, X509 *cert)
{
X509_check_purpose(cert, -1, -1);
if (!cert->skid)
return -1;
return ASN1_OCTET_STRING_cmp(keyid, cert->skid);
}
int cms_set1_ias(CMS_IssuerAndSerialNumber **pias, X509 *cert)
{
CMS_IssuerAndSerialNumber *ias;
ias = M_ASN1_new_of(CMS_IssuerAndSerialNumber);
if (!ias)
goto err;
if (!X509_NAME_set(&ias->issuer, X509_get_issuer_name(cert)))
goto err;
if (!ASN1_STRING_copy(ias->serialNumber, X509_get_serialNumber(cert)))
goto err;
if (*pias)
M_ASN1_free_of(*pias, CMS_IssuerAndSerialNumber);
*pias = ias;
return 1;
err:
if (ias)
M_ASN1_free_of(ias, CMS_IssuerAndSerialNumber);
CMSerr(CMS_F_CMS_SET1_IAS, ERR_R_MALLOC_FAILURE);
return 0;
}
int cms_set1_keyid(ASN1_OCTET_STRING **pkeyid, X509 *cert)
{
ASN1_OCTET_STRING *keyid = NULL;
X509_check_purpose(cert, -1, -1);
if (!cert->skid) {
CMSerr(CMS_F_CMS_SET1_KEYID, CMS_R_CERTIFICATE_HAS_NO_KEYID);
return 0;
}
keyid = ASN1_STRING_dup(cert->skid);
if (!keyid) {
CMSerr(CMS_F_CMS_SET1_KEYID, ERR_R_MALLOC_FAILURE);
return 0;
}
if (*pkeyid)
ASN1_OCTET_STRING_free(*pkeyid);
*pkeyid = keyid;
return 1;
}
