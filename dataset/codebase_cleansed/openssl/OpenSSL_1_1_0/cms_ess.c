int CMS_get1_ReceiptRequest(CMS_SignerInfo *si, CMS_ReceiptRequest **prr)
{
ASN1_STRING *str;
CMS_ReceiptRequest *rr = NULL;
if (prr)
*prr = NULL;
str = CMS_signed_get0_data_by_OBJ(si,
OBJ_nid2obj
(NID_id_smime_aa_receiptRequest), -3,
V_ASN1_SEQUENCE);
if (!str)
return 0;
rr = ASN1_item_unpack(str, ASN1_ITEM_rptr(CMS_ReceiptRequest));
if (!rr)
return -1;
if (prr)
*prr = rr;
else
CMS_ReceiptRequest_free(rr);
return 1;
}
int CMS_add1_ReceiptRequest(CMS_SignerInfo *si, CMS_ReceiptRequest *rr)
{
unsigned char *rrder = NULL;
int rrderlen, r = 0;
rrderlen = i2d_CMS_ReceiptRequest(rr, &rrder);
if (rrderlen < 0)
goto merr;
if (!CMS_signed_add1_attr_by_NID(si, NID_id_smime_aa_receiptRequest,
V_ASN1_SEQUENCE, rrder, rrderlen))
goto merr;
r = 1;
merr:
if (!r)
CMSerr(CMS_F_CMS_ADD1_RECEIPTREQUEST, ERR_R_MALLOC_FAILURE);
OPENSSL_free(rrder);
return r;
}
static int cms_msgSigDigest(CMS_SignerInfo *si,
unsigned char *dig, unsigned int *diglen)
{
const EVP_MD *md;
md = EVP_get_digestbyobj(si->digestAlgorithm->algorithm);
if (md == NULL)
return 0;
if (!ASN1_item_digest(ASN1_ITEM_rptr(CMS_Attributes_Verify), md,
si->signedAttrs, dig, diglen))
return 0;
return 1;
}
int cms_msgSigDigest_add1(CMS_SignerInfo *dest, CMS_SignerInfo *src)
{
unsigned char dig[EVP_MAX_MD_SIZE];
unsigned int diglen;
if (!cms_msgSigDigest(src, dig, &diglen)) {
CMSerr(CMS_F_CMS_MSGSIGDIGEST_ADD1, CMS_R_MSGSIGDIGEST_ERROR);
return 0;
}
if (!CMS_signed_add1_attr_by_NID(dest, NID_id_smime_aa_msgSigDigest,
V_ASN1_OCTET_STRING, dig, diglen)) {
CMSerr(CMS_F_CMS_MSGSIGDIGEST_ADD1, ERR_R_MALLOC_FAILURE);
return 0;
}
return 1;
}
int cms_Receipt_verify(CMS_ContentInfo *cms, CMS_ContentInfo *req_cms)
{
int r = 0, i;
CMS_ReceiptRequest *rr = NULL;
CMS_Receipt *rct = NULL;
STACK_OF(CMS_SignerInfo) *sis, *osis;
CMS_SignerInfo *si, *osi = NULL;
ASN1_OCTET_STRING *msig, **pcont;
ASN1_OBJECT *octype;
unsigned char dig[EVP_MAX_MD_SIZE];
unsigned int diglen;
osis = CMS_get0_SignerInfos(req_cms);
sis = CMS_get0_SignerInfos(cms);
if (!osis || !sis)
goto err;
if (sk_CMS_SignerInfo_num(sis) != 1) {
CMSerr(CMS_F_CMS_RECEIPT_VERIFY, CMS_R_NEED_ONE_SIGNER);
goto err;
}
if (OBJ_obj2nid(CMS_get0_eContentType(cms)) != NID_id_smime_ct_receipt) {
CMSerr(CMS_F_CMS_RECEIPT_VERIFY, CMS_R_NOT_A_SIGNED_RECEIPT);
goto err;
}
pcont = CMS_get0_content(cms);
if (!pcont || !*pcont) {
CMSerr(CMS_F_CMS_RECEIPT_VERIFY, CMS_R_NO_CONTENT);
goto err;
}
rct = ASN1_item_unpack(*pcont, ASN1_ITEM_rptr(CMS_Receipt));
if (!rct) {
CMSerr(CMS_F_CMS_RECEIPT_VERIFY, CMS_R_RECEIPT_DECODE_ERROR);
goto err;
}
for (i = 0; i < sk_CMS_SignerInfo_num(osis); i++) {
osi = sk_CMS_SignerInfo_value(osis, i);
if (!ASN1_STRING_cmp(osi->signature, rct->originatorSignatureValue))
break;
}
if (i == sk_CMS_SignerInfo_num(osis)) {
CMSerr(CMS_F_CMS_RECEIPT_VERIFY, CMS_R_NO_MATCHING_SIGNATURE);
goto err;
}
si = sk_CMS_SignerInfo_value(sis, 0);
msig = CMS_signed_get0_data_by_OBJ(si,
OBJ_nid2obj
(NID_id_smime_aa_msgSigDigest), -3,
V_ASN1_OCTET_STRING);
if (!msig) {
CMSerr(CMS_F_CMS_RECEIPT_VERIFY, CMS_R_NO_MSGSIGDIGEST);
goto err;
}
if (!cms_msgSigDigest(osi, dig, &diglen)) {
CMSerr(CMS_F_CMS_RECEIPT_VERIFY, CMS_R_MSGSIGDIGEST_ERROR);
goto err;
}
if (diglen != (unsigned int)msig->length) {
CMSerr(CMS_F_CMS_RECEIPT_VERIFY, CMS_R_MSGSIGDIGEST_WRONG_LENGTH);
goto err;
}
if (memcmp(dig, msig->data, diglen)) {
CMSerr(CMS_F_CMS_RECEIPT_VERIFY,
CMS_R_MSGSIGDIGEST_VERIFICATION_FAILURE);
goto err;
}
octype = CMS_signed_get0_data_by_OBJ(osi,
OBJ_nid2obj(NID_pkcs9_contentType),
-3, V_ASN1_OBJECT);
if (!octype) {
CMSerr(CMS_F_CMS_RECEIPT_VERIFY, CMS_R_NO_CONTENT_TYPE);
goto err;
}
if (OBJ_cmp(octype, rct->contentType)) {
CMSerr(CMS_F_CMS_RECEIPT_VERIFY, CMS_R_CONTENT_TYPE_MISMATCH);
goto err;
}
if (CMS_get1_ReceiptRequest(osi, &rr) <= 0) {
CMSerr(CMS_F_CMS_RECEIPT_VERIFY, CMS_R_NO_RECEIPT_REQUEST);
goto err;
}
if (ASN1_STRING_cmp(rr->signedContentIdentifier,
rct->signedContentIdentifier)) {
CMSerr(CMS_F_CMS_RECEIPT_VERIFY, CMS_R_CONTENTIDENTIFIER_MISMATCH);
goto err;
}
r = 1;
err:
CMS_ReceiptRequest_free(rr);
M_ASN1_free_of(rct, CMS_Receipt);
return r;
}
ASN1_OCTET_STRING *cms_encode_Receipt(CMS_SignerInfo *si)
{
CMS_Receipt rct;
CMS_ReceiptRequest *rr = NULL;
ASN1_OBJECT *ctype;
ASN1_OCTET_STRING *os = NULL;
if (CMS_get1_ReceiptRequest(si, &rr) <= 0) {
CMSerr(CMS_F_CMS_ENCODE_RECEIPT, CMS_R_NO_RECEIPT_REQUEST);
goto err;
}
ctype = CMS_signed_get0_data_by_OBJ(si,
OBJ_nid2obj(NID_pkcs9_contentType),
-3, V_ASN1_OBJECT);
if (!ctype) {
CMSerr(CMS_F_CMS_ENCODE_RECEIPT, CMS_R_NO_CONTENT_TYPE);
goto err;
}
rct.version = 1;
rct.contentType = ctype;
rct.signedContentIdentifier = rr->signedContentIdentifier;
rct.originatorSignatureValue = si->signature;
os = ASN1_item_pack(&rct, ASN1_ITEM_rptr(CMS_Receipt), NULL);
err:
CMS_ReceiptRequest_free(rr);
return os;
}
