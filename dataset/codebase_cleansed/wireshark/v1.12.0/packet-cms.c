static void
cms_verify_msg_digest(proto_item *pi, tvbuff_t *content, const char *alg, tvbuff_t *tvb, int offset)
{
sha1_context sha1_ctx;
md5_state_t md5_ctx;
int i= 0, buffer_size = 0;
if(strcmp(alg, HASH_SHA1) == 0) {
sha1_starts(&sha1_ctx);
sha1_update(&sha1_ctx, tvb_get_ptr(content, 0, tvb_length(content)),
tvb_length(content));
sha1_finish(&sha1_ctx, digest_buf);
buffer_size = SHA1_BUFFER_SIZE;
} else if(strcmp(alg, HASH_MD5) == 0) {
md5_init(&md5_ctx);
md5_append(&md5_ctx, tvb_get_ptr(content, 0, tvb_length(content)),
tvb_length(content));
md5_finish(&md5_ctx, digest_buf);
buffer_size = MD5_BUFFER_SIZE;
}
if(buffer_size) {
if(tvb_bytes_exist(tvb, offset, buffer_size) &&
(tvb_memeql(tvb, offset, digest_buf, buffer_size) != 0)) {
proto_item_append_text(pi, " [incorrect, should be ");
for(i = 0; i < buffer_size; i++)
proto_item_append_text(pi, "%02X", digest_buf[i]);
proto_item_append_text(pi, "]");
}
else
proto_item_append_text(pi, " [correct]");
} else {
proto_item_append_text(pi, " [unable to verify]");
}
}
int
dissect_cms_ContentType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 88 "../../asn1/cms/cms.cnf"
const char *name = NULL;
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &object_identifier_id);
if(object_identifier_id) {
name = oid_resolved_from_string(object_identifier_id);
proto_item_append_text(tree, " (%s)", name ? name : object_identifier_id);
}
return offset;
}
static int
dissect_cms_T_content(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 98 "../../asn1/cms/cms.cnf"
offset=call_ber_oid_callback(object_identifier_id, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
int
dissect_cms_ContentInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 79 "../../asn1/cms/cms.cnf"
top_tree = tree;
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ContentInfo_sequence, hf_index, ett_cms_ContentInfo);
content_tvb = NULL;
top_tree = NULL;
return offset;
}
static int
dissect_cms_CMSVersion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_cms_DigestAlgorithmIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_x509af_AlgorithmIdentifier(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
int
dissect_cms_DigestAlgorithmIdentifiers(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
DigestAlgorithmIdentifiers_set_of, hf_index, ett_cms_DigestAlgorithmIdentifiers);
return offset;
}
static int
dissect_cms_T_eContent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 102 "../../asn1/cms/cms.cnf"
offset = dissect_ber_octet_string(FALSE, actx, tree, tvb, offset, hf_index, &content_tvb);
proto_item_set_text(actx->created_item, "eContent (%u bytes)", tvb_length (content_tvb));
call_ber_oid_callback(object_identifier_id, content_tvb, 0, actx->pinfo, top_tree ? top_tree : tree, NULL);
return offset;
}
int
dissect_cms_EncapsulatedContentInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EncapsulatedContentInfo_sequence, hf_index, ett_cms_EncapsulatedContentInfo);
return offset;
}
static int
dissect_cms_T_attrType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 129 "../../asn1/cms/cms.cnf"
const char *name = NULL;
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_cms_attrType, &object_identifier_id);
if(object_identifier_id) {
name = oid_resolved_from_string(object_identifier_id);
proto_item_append_text(tree, " (%s)", name ? name : object_identifier_id);
}
return offset;
}
static int
dissect_cms_AttributeValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 139 "../../asn1/cms/cms.cnf"
offset=call_ber_oid_callback(object_identifier_id, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_cms_SET_OF_AttributeValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_AttributeValue_set_of, hf_index, ett_cms_SET_OF_AttributeValue);
return offset;
}
static int
dissect_cms_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Attribute_sequence, hf_index, ett_cms_Attribute);
return offset;
}
static int
dissect_cms_UnauthAttributes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, NO_BOUND, UnauthAttributes_set_of, hf_index, ett_cms_UnauthAttributes);
return offset;
}
static int
dissect_cms_ExtendedCertificateInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ExtendedCertificateInfo_sequence, hf_index, ett_cms_ExtendedCertificateInfo);
return offset;
}
static int
dissect_cms_SignatureAlgorithmIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_x509af_AlgorithmIdentifier(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_cms_Signature(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_cms_ExtendedCertificate(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ExtendedCertificate_sequence, hf_index, ett_cms_ExtendedCertificate);
return offset;
}
static int
dissect_cms_AttCertVersionV1(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_cms_T_subject(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_subject_choice, hf_index, ett_cms_T_subject,
NULL);
return offset;
}
static int
dissect_cms_SEQUENCE_OF_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_Attribute_sequence_of, hf_index, ett_cms_SEQUENCE_OF_Attribute);
return offset;
}
static int
dissect_cms_AttributeCertificateInfoV1(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AttributeCertificateInfoV1_sequence, hf_index, ett_cms_AttributeCertificateInfoV1);
return offset;
}
static int
dissect_cms_BIT_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_cms_AttributeCertificateV1(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AttributeCertificateV1_sequence, hf_index, ett_cms_AttributeCertificateV1);
return offset;
}
static int
dissect_cms_AttributeCertificateV2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_x509af_AttributeCertificate(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_cms_CertificateChoices(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
CertificateChoices_choice, hf_index, ett_cms_CertificateChoices,
NULL);
return offset;
}
static int
dissect_cms_CertificateSet(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
CertificateSet_set_of, hf_index, ett_cms_CertificateSet);
return offset;
}
static int
dissect_cms_T_otherRevInfoFormat(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &object_identifier_id);
return offset;
}
static int
dissect_cms_T_otherRevInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 123 "../../asn1/cms/cms.cnf"
offset=call_ber_oid_callback(object_identifier_id, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_cms_OtherRevocationInfoFormat(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
OtherRevocationInfoFormat_sequence, hf_index, ett_cms_OtherRevocationInfoFormat);
return offset;
}
static int
dissect_cms_RevocationInfoChoice(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
RevocationInfoChoice_choice, hf_index, ett_cms_RevocationInfoChoice,
NULL);
return offset;
}
static int
dissect_cms_RevocationInfoChoices(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
RevocationInfoChoices_set_of, hf_index, ett_cms_RevocationInfoChoices);
return offset;
}
int
dissect_cms_IssuerAndSerialNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IssuerAndSerialNumber_sequence, hf_index, ett_cms_IssuerAndSerialNumber);
return offset;
}
static int
dissect_cms_SubjectKeyIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_cms_SignerIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
SignerIdentifier_choice, hf_index, ett_cms_SignerIdentifier,
NULL);
return offset;
}
int
dissect_cms_SignedAttributes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, NO_BOUND, SignedAttributes_set_of, hf_index, ett_cms_SignedAttributes);
return offset;
}
int
dissect_cms_SignatureValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_cms_UnsignedAttributes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, NO_BOUND, UnsignedAttributes_set_of, hf_index, ett_cms_UnsignedAttributes);
return offset;
}
int
dissect_cms_SignerInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SignerInfo_sequence, hf_index, ett_cms_SignerInfo);
return offset;
}
int
dissect_cms_SignerInfos(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SignerInfos_set_of, hf_index, ett_cms_SignerInfos);
return offset;
}
int
dissect_cms_SignedData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SignedData_sequence, hf_index, ett_cms_SignedData);
return offset;
}
static int
dissect_cms_OriginatorInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
OriginatorInfo_sequence, hf_index, ett_cms_OriginatorInfo);
return offset;
}
static int
dissect_cms_RecipientIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
RecipientIdentifier_choice, hf_index, ett_cms_RecipientIdentifier,
NULL);
return offset;
}
static int
dissect_cms_KeyEncryptionAlgorithmIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_x509af_AlgorithmIdentifier(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_cms_EncryptedKey(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_cms_KeyTransRecipientInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
KeyTransRecipientInfo_sequence, hf_index, ett_cms_KeyTransRecipientInfo);
return offset;
}
static int
dissect_cms_OriginatorPublicKey(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
OriginatorPublicKey_sequence, hf_index, ett_cms_OriginatorPublicKey);
return offset;
}
static int
dissect_cms_OriginatorIdentifierOrKey(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
OriginatorIdentifierOrKey_choice, hf_index, ett_cms_OriginatorIdentifierOrKey,
NULL);
return offset;
}
static int
dissect_cms_UserKeyingMaterial(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_cms_GeneralizedTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_GeneralizedTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_cms_T_keyAttrId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_cms_ci_contentType, &object_identifier_id);
return offset;
}
static int
dissect_cms_T_keyAttr(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 118 "../../asn1/cms/cms.cnf"
offset=call_ber_oid_callback(object_identifier_id, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_cms_OtherKeyAttribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
OtherKeyAttribute_sequence, hf_index, ett_cms_OtherKeyAttribute);
return offset;
}
static int
dissect_cms_RecipientKeyIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RecipientKeyIdentifier_sequence, hf_index, ett_cms_RecipientKeyIdentifier);
return offset;
}
static int
dissect_cms_KeyAgreeRecipientIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
KeyAgreeRecipientIdentifier_choice, hf_index, ett_cms_KeyAgreeRecipientIdentifier,
NULL);
return offset;
}
static int
dissect_cms_RecipientEncryptedKey(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RecipientEncryptedKey_sequence, hf_index, ett_cms_RecipientEncryptedKey);
return offset;
}
static int
dissect_cms_RecipientEncryptedKeys(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
RecipientEncryptedKeys_sequence_of, hf_index, ett_cms_RecipientEncryptedKeys);
return offset;
}
static int
dissect_cms_KeyAgreeRecipientInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
KeyAgreeRecipientInfo_sequence, hf_index, ett_cms_KeyAgreeRecipientInfo);
return offset;
}
static int
dissect_cms_OCTET_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_cms_KEKIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
KEKIdentifier_sequence, hf_index, ett_cms_KEKIdentifier);
return offset;
}
static int
dissect_cms_KEKRecipientInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
KEKRecipientInfo_sequence, hf_index, ett_cms_KEKRecipientInfo);
return offset;
}
static int
dissect_cms_KeyDerivationAlgorithmIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_x509af_AlgorithmIdentifier(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_cms_PasswordRecipientInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PasswordRecipientInfo_sequence, hf_index, ett_cms_PasswordRecipientInfo);
return offset;
}
static int
dissect_cms_T_oriType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &object_identifier_id);
return offset;
}
static int
dissect_cms_T_oriValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 112 "../../asn1/cms/cms.cnf"
offset=call_ber_oid_callback(object_identifier_id, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_cms_OtherRecipientInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
OtherRecipientInfo_sequence, hf_index, ett_cms_OtherRecipientInfo);
return offset;
}
static int
dissect_cms_RecipientInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
RecipientInfo_choice, hf_index, ett_cms_RecipientInfo,
NULL);
return offset;
}
static int
dissect_cms_RecipientInfos(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, NO_BOUND, RecipientInfos_set_of, hf_index, ett_cms_RecipientInfos);
return offset;
}
static int
dissect_cms_ContentEncryptionAlgorithmIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_x509af_AlgorithmIdentifier(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_cms_EncryptedContent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 189 "../../asn1/cms/cms.cnf"
tvbuff_t *encrypted_tvb;
proto_item *item;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&encrypted_tvb);
#line 194 "../../asn1/cms/cms.cnf"
item = actx->created_item;
PBE_decrypt_data(object_identifier_id, encrypted_tvb, actx, item);
return offset;
}
static int
dissect_cms_EncryptedContentInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EncryptedContentInfo_sequence, hf_index, ett_cms_EncryptedContentInfo);
return offset;
}
static int
dissect_cms_UnprotectedAttributes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, NO_BOUND, UnprotectedAttributes_set_of, hf_index, ett_cms_UnprotectedAttributes);
return offset;
}
int
dissect_cms_EnvelopedData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EnvelopedData_sequence, hf_index, ett_cms_EnvelopedData);
return offset;
}
int
dissect_cms_Digest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_cms_DigestedData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DigestedData_sequence, hf_index, ett_cms_DigestedData);
return offset;
}
static int
dissect_cms_EncryptedData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EncryptedData_sequence, hf_index, ett_cms_EncryptedData);
return offset;
}
static int
dissect_cms_MessageAuthenticationCodeAlgorithm(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_x509af_AlgorithmIdentifier(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_cms_AuthAttributes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, NO_BOUND, AuthAttributes_set_of, hf_index, ett_cms_AuthAttributes);
return offset;
}
static int
dissect_cms_MessageAuthenticationCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_cms_AuthenticatedData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AuthenticatedData_sequence, hf_index, ett_cms_AuthenticatedData);
return offset;
}
static int
dissect_cms_MessageDigest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 143 "../../asn1/cms/cms.cnf"
proto_item *pi;
int old_offset = offset;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
pi = actx->created_item;
old_offset = get_ber_identifier(tvb, old_offset, NULL, NULL, NULL);
old_offset = get_ber_length(tvb, old_offset, NULL, NULL);
if(content_tvb)
cms_verify_msg_digest(pi, content_tvb, x509af_get_last_algorithm_id(), tvb, old_offset);
return offset;
}
static int
dissect_cms_UTCTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_UTCTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_cms_Time(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Time_choice, hf_index, ett_cms_Time,
NULL);
return offset;
}
static int
dissect_cms_SigningTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_cms_Time(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
int
dissect_cms_Countersignature(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_cms_SignerInfo(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_cms_RC2ParameterVersion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 179 "../../asn1/cms/cms.cnf"
guint32 length = 0;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&length);
if(cap_tree != NULL)
proto_item_append_text(cap_tree, " (%d bits)", length);
return offset;
}
static int
dissect_cms_RC2WrapParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_cms_RC2ParameterVersion(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_cms_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_cms_RC2CBCParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RC2CBCParameter_sequence, hf_index, ett_cms_RC2CBCParameter);
return offset;
}
static int
dissect_cms_T_capability(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 161 "../../asn1/cms/cms.cnf"
const char *name = NULL;
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_cms_attrType, &object_identifier_id);
if(object_identifier_id) {
name = oid_resolved_from_string(object_identifier_id);
proto_item_append_text(tree, " %s", name ? name : object_identifier_id);
cap_tree = tree;
}
return offset;
}
static int
dissect_cms_T_parameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 172 "../../asn1/cms/cms.cnf"
offset=call_ber_oid_callback(object_identifier_id, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_cms_SMIMECapability(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SMIMECapability_sequence, hf_index, ett_cms_SMIMECapability);
return offset;
}
static int
dissect_cms_SMIMECapabilities(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SMIMECapabilities_sequence_of, hf_index, ett_cms_SMIMECapabilities);
return offset;
}
static int
dissect_cms_SMIMEEncryptionKeyPreference(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
SMIMEEncryptionKeyPreference_choice, hf_index, ett_cms_SMIMEEncryptionKeyPreference,
NULL);
return offset;
}
static int
dissect_cms_RC2CBCParameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
RC2CBCParameters_choice, hf_index, ett_cms_RC2CBCParameters,
NULL);
return offset;
}
static void dissect_ContentInfo_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_cms_ContentInfo(FALSE, tvb, 0, &asn1_ctx, tree, hf_cms_ContentInfo_PDU);
}
static void dissect_ContentType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_cms_ContentType(FALSE, tvb, 0, &asn1_ctx, tree, hf_cms_ContentType_PDU);
}
static void dissect_SignedData_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_cms_SignedData(FALSE, tvb, 0, &asn1_ctx, tree, hf_cms_SignedData_PDU);
}
static void dissect_EnvelopedData_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_cms_EnvelopedData(FALSE, tvb, 0, &asn1_ctx, tree, hf_cms_EnvelopedData_PDU);
}
static void dissect_DigestedData_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_cms_DigestedData(FALSE, tvb, 0, &asn1_ctx, tree, hf_cms_DigestedData_PDU);
}
static void dissect_EncryptedData_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_cms_EncryptedData(FALSE, tvb, 0, &asn1_ctx, tree, hf_cms_EncryptedData_PDU);
}
static void dissect_AuthenticatedData_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_cms_AuthenticatedData(FALSE, tvb, 0, &asn1_ctx, tree, hf_cms_AuthenticatedData_PDU);
}
static void dissect_IssuerAndSerialNumber_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_cms_IssuerAndSerialNumber(FALSE, tvb, 0, &asn1_ctx, tree, hf_cms_IssuerAndSerialNumber_PDU);
}
static void dissect_MessageDigest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_cms_MessageDigest(FALSE, tvb, 0, &asn1_ctx, tree, hf_cms_MessageDigest_PDU);
}
static void dissect_SigningTime_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_cms_SigningTime(FALSE, tvb, 0, &asn1_ctx, tree, hf_cms_SigningTime_PDU);
}
static void dissect_Countersignature_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_cms_Countersignature(FALSE, tvb, 0, &asn1_ctx, tree, hf_cms_Countersignature_PDU);
}
static void dissect_RC2WrapParameter_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_cms_RC2WrapParameter(FALSE, tvb, 0, &asn1_ctx, tree, hf_cms_RC2WrapParameter_PDU);
}
static void dissect_SMIMECapabilities_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_cms_SMIMECapabilities(FALSE, tvb, 0, &asn1_ctx, tree, hf_cms_SMIMECapabilities_PDU);
}
static void dissect_SMIMEEncryptionKeyPreference_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_cms_SMIMEEncryptionKeyPreference(FALSE, tvb, 0, &asn1_ctx, tree, hf_cms_SMIMEEncryptionKeyPreference_PDU);
}
static void dissect_RC2CBCParameters_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_cms_RC2CBCParameters(FALSE, tvb, 0, &asn1_ctx, tree, hf_cms_RC2CBCParameters_PDU);
}
void proto_register_cms(void) {
static hf_register_info hf[] = {
{ &hf_cms_ci_contentType,
{ "contentType", "cms.contentInfo.contentType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
#line 1 "../../asn1/cms/packet-cms-hfarr.c"
{ &hf_cms_ContentInfo_PDU,
{ "ContentInfo", "cms.ContentInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_ContentType_PDU,
{ "ContentType", "cms.ContentType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_SignedData_PDU,
{ "SignedData", "cms.SignedData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_EnvelopedData_PDU,
{ "EnvelopedData", "cms.EnvelopedData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_DigestedData_PDU,
{ "DigestedData", "cms.DigestedData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_EncryptedData_PDU,
{ "EncryptedData", "cms.EncryptedData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_AuthenticatedData_PDU,
{ "AuthenticatedData", "cms.AuthenticatedData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_IssuerAndSerialNumber_PDU,
{ "IssuerAndSerialNumber", "cms.IssuerAndSerialNumber_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_MessageDigest_PDU,
{ "MessageDigest", "cms.MessageDigest",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_SigningTime_PDU,
{ "SigningTime", "cms.SigningTime",
FT_UINT32, BASE_DEC, VALS(cms_Time_vals), 0,
NULL, HFILL }},
{ &hf_cms_Countersignature_PDU,
{ "Countersignature", "cms.Countersignature_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_RC2WrapParameter_PDU,
{ "RC2WrapParameter", "cms.RC2WrapParameter",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_cms_SMIMECapabilities_PDU,
{ "SMIMECapabilities", "cms.SMIMECapabilities",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_cms_SMIMEEncryptionKeyPreference_PDU,
{ "SMIMEEncryptionKeyPreference", "cms.SMIMEEncryptionKeyPreference",
FT_UINT32, BASE_DEC, VALS(cms_SMIMEEncryptionKeyPreference_vals), 0,
NULL, HFILL }},
{ &hf_cms_RC2CBCParameters_PDU,
{ "RC2CBCParameters", "cms.RC2CBCParameters",
FT_UINT32, BASE_DEC, VALS(cms_RC2CBCParameters_vals), 0,
NULL, HFILL }},
{ &hf_cms_contentType,
{ "contentType", "cms.contentType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_content,
{ "content", "cms.content_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_version,
{ "version", "cms.version",
FT_INT32, BASE_DEC, VALS(cms_CMSVersion_vals), 0,
"CMSVersion", HFILL }},
{ &hf_cms_digestAlgorithms,
{ "digestAlgorithms", "cms.digestAlgorithms",
FT_UINT32, BASE_DEC, NULL, 0,
"DigestAlgorithmIdentifiers", HFILL }},
{ &hf_cms_encapContentInfo,
{ "encapContentInfo", "cms.encapContentInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
"EncapsulatedContentInfo", HFILL }},
{ &hf_cms_certificates,
{ "certificates", "cms.certificates",
FT_UINT32, BASE_DEC, NULL, 0,
"CertificateSet", HFILL }},
{ &hf_cms_crls,
{ "crls", "cms.crls",
FT_UINT32, BASE_DEC, NULL, 0,
"RevocationInfoChoices", HFILL }},
{ &hf_cms_signerInfos,
{ "signerInfos", "cms.signerInfos",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_cms_DigestAlgorithmIdentifiers_item,
{ "DigestAlgorithmIdentifier", "cms.DigestAlgorithmIdentifier_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_SignerInfos_item,
{ "SignerInfo", "cms.SignerInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_eContentType,
{ "eContentType", "cms.eContentType",
FT_OID, BASE_NONE, NULL, 0,
"ContentType", HFILL }},
{ &hf_cms_eContent,
{ "eContent", "cms.eContent",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_sid,
{ "sid", "cms.sid",
FT_UINT32, BASE_DEC, VALS(cms_SignerIdentifier_vals), 0,
"SignerIdentifier", HFILL }},
{ &hf_cms_digestAlgorithm,
{ "digestAlgorithm", "cms.digestAlgorithm_element",
FT_NONE, BASE_NONE, NULL, 0,
"DigestAlgorithmIdentifier", HFILL }},
{ &hf_cms_signedAttrs,
{ "signedAttrs", "cms.signedAttrs",
FT_UINT32, BASE_DEC, NULL, 0,
"SignedAttributes", HFILL }},
{ &hf_cms_signatureAlgorithm,
{ "signatureAlgorithm", "cms.signatureAlgorithm_element",
FT_NONE, BASE_NONE, NULL, 0,
"SignatureAlgorithmIdentifier", HFILL }},
{ &hf_cms_signatureValue,
{ "signature", "cms.signature",
FT_BYTES, BASE_NONE, NULL, 0,
"SignatureValue", HFILL }},
{ &hf_cms_unsignedAttrs,
{ "unsignedAttrs", "cms.unsignedAttrs",
FT_UINT32, BASE_DEC, NULL, 0,
"UnsignedAttributes", HFILL }},
{ &hf_cms_issuerAndSerialNumber,
{ "issuerAndSerialNumber", "cms.issuerAndSerialNumber_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_subjectKeyIdentifier,
{ "subjectKeyIdentifier", "cms.subjectKeyIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_SignedAttributes_item,
{ "Attribute", "cms.Attribute_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_UnsignedAttributes_item,
{ "Attribute", "cms.Attribute_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_attrType,
{ "attrType", "cms.attrType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_attrValues,
{ "attrValues", "cms.attrValues",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_AttributeValue", HFILL }},
{ &hf_cms_attrValues_item,
{ "AttributeValue", "cms.AttributeValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_originatorInfo,
{ "originatorInfo", "cms.originatorInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_recipientInfos,
{ "recipientInfos", "cms.recipientInfos",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_cms_encryptedContentInfo,
{ "encryptedContentInfo", "cms.encryptedContentInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_unprotectedAttrs,
{ "unprotectedAttrs", "cms.unprotectedAttrs",
FT_UINT32, BASE_DEC, NULL, 0,
"UnprotectedAttributes", HFILL }},
{ &hf_cms_certs,
{ "certs", "cms.certs",
FT_UINT32, BASE_DEC, NULL, 0,
"CertificateSet", HFILL }},
{ &hf_cms_RecipientInfos_item,
{ "RecipientInfo", "cms.RecipientInfo",
FT_UINT32, BASE_DEC, VALS(cms_RecipientInfo_vals), 0,
NULL, HFILL }},
{ &hf_cms_encryptedContentType,
{ "contentType", "cms.contentType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_contentEncryptionAlgorithm,
{ "contentEncryptionAlgorithm", "cms.contentEncryptionAlgorithm_element",
FT_NONE, BASE_NONE, NULL, 0,
"ContentEncryptionAlgorithmIdentifier", HFILL }},
{ &hf_cms_encryptedContent,
{ "encryptedContent", "cms.encryptedContent",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_UnprotectedAttributes_item,
{ "Attribute", "cms.Attribute_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_ktri,
{ "ktri", "cms.ktri_element",
FT_NONE, BASE_NONE, NULL, 0,
"KeyTransRecipientInfo", HFILL }},
{ &hf_cms_kari,
{ "kari", "cms.kari_element",
FT_NONE, BASE_NONE, NULL, 0,
"KeyAgreeRecipientInfo", HFILL }},
{ &hf_cms_kekri,
{ "kekri", "cms.kekri_element",
FT_NONE, BASE_NONE, NULL, 0,
"KEKRecipientInfo", HFILL }},
{ &hf_cms_pwri,
{ "pwri", "cms.pwri_element",
FT_NONE, BASE_NONE, NULL, 0,
"PasswordRecipientInfo", HFILL }},
{ &hf_cms_ori,
{ "ori", "cms.ori_element",
FT_NONE, BASE_NONE, NULL, 0,
"OtherRecipientInfo", HFILL }},
{ &hf_cms_rid,
{ "rid", "cms.rid",
FT_UINT32, BASE_DEC, VALS(cms_RecipientIdentifier_vals), 0,
"RecipientIdentifier", HFILL }},
{ &hf_cms_keyEncryptionAlgorithm,
{ "keyEncryptionAlgorithm", "cms.keyEncryptionAlgorithm_element",
FT_NONE, BASE_NONE, NULL, 0,
"KeyEncryptionAlgorithmIdentifier", HFILL }},
{ &hf_cms_encryptedKey,
{ "encryptedKey", "cms.encryptedKey",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_originator,
{ "originator", "cms.originator",
FT_UINT32, BASE_DEC, VALS(cms_OriginatorIdentifierOrKey_vals), 0,
"OriginatorIdentifierOrKey", HFILL }},
{ &hf_cms_ukm,
{ "ukm", "cms.ukm",
FT_BYTES, BASE_NONE, NULL, 0,
"UserKeyingMaterial", HFILL }},
{ &hf_cms_recipientEncryptedKeys,
{ "recipientEncryptedKeys", "cms.recipientEncryptedKeys",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_cms_originatorKey,
{ "originatorKey", "cms.originatorKey_element",
FT_NONE, BASE_NONE, NULL, 0,
"OriginatorPublicKey", HFILL }},
{ &hf_cms_algorithm,
{ "algorithm", "cms.algorithm_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_cms_publicKey,
{ "publicKey", "cms.publicKey",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_cms_RecipientEncryptedKeys_item,
{ "RecipientEncryptedKey", "cms.RecipientEncryptedKey_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_rekRid,
{ "rid", "cms.rid",
FT_UINT32, BASE_DEC, VALS(cms_KeyAgreeRecipientIdentifier_vals), 0,
"KeyAgreeRecipientIdentifier", HFILL }},
{ &hf_cms_rKeyId,
{ "rKeyId", "cms.rKeyId_element",
FT_NONE, BASE_NONE, NULL, 0,
"RecipientKeyIdentifier", HFILL }},
{ &hf_cms_date,
{ "date", "cms.date",
FT_STRING, BASE_NONE, NULL, 0,
"GeneralizedTime", HFILL }},
{ &hf_cms_other,
{ "other", "cms.other_element",
FT_NONE, BASE_NONE, NULL, 0,
"OtherKeyAttribute", HFILL }},
{ &hf_cms_kekid,
{ "kekid", "cms.kekid_element",
FT_NONE, BASE_NONE, NULL, 0,
"KEKIdentifier", HFILL }},
{ &hf_cms_keyIdentifier,
{ "keyIdentifier", "cms.keyIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_cms_keyDerivationAlgorithm,
{ "keyDerivationAlgorithm", "cms.keyDerivationAlgorithm_element",
FT_NONE, BASE_NONE, NULL, 0,
"KeyDerivationAlgorithmIdentifier", HFILL }},
{ &hf_cms_oriType,
{ "oriType", "cms.oriType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_oriValue,
{ "oriValue", "cms.oriValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_digest,
{ "digest", "cms.digest",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_macAlgorithm,
{ "macAlgorithm", "cms.macAlgorithm_element",
FT_NONE, BASE_NONE, NULL, 0,
"MessageAuthenticationCodeAlgorithm", HFILL }},
{ &hf_cms_authAttrs,
{ "authAttrs", "cms.authAttrs",
FT_UINT32, BASE_DEC, NULL, 0,
"AuthAttributes", HFILL }},
{ &hf_cms_mac,
{ "mac", "cms.mac",
FT_BYTES, BASE_NONE, NULL, 0,
"MessageAuthenticationCode", HFILL }},
{ &hf_cms_unauthAttrs,
{ "unauthAttrs", "cms.unauthAttrs",
FT_UINT32, BASE_DEC, NULL, 0,
"UnauthAttributes", HFILL }},
{ &hf_cms_AuthAttributes_item,
{ "Attribute", "cms.Attribute_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_UnauthAttributes_item,
{ "Attribute", "cms.Attribute_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_RevocationInfoChoices_item,
{ "RevocationInfoChoice", "cms.RevocationInfoChoice",
FT_UINT32, BASE_DEC, VALS(cms_RevocationInfoChoice_vals), 0,
NULL, HFILL }},
{ &hf_cms_crl,
{ "crl", "cms.crl_element",
FT_NONE, BASE_NONE, NULL, 0,
"CertificateList", HFILL }},
{ &hf_cms_otherRIC,
{ "other", "cms.other_element",
FT_NONE, BASE_NONE, NULL, 0,
"OtherRevocationInfoFormat", HFILL }},
{ &hf_cms_otherRevInfoFormat,
{ "otherRevInfoFormat", "cms.otherRevInfoFormat",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_otherRevInfo,
{ "otherRevInfo", "cms.otherRevInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_certificate,
{ "certificate", "cms.certificate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_extendedCertificate,
{ "extendedCertificate", "cms.extendedCertificate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_v1AttrCert,
{ "v1AttrCert", "cms.v1AttrCert_element",
FT_NONE, BASE_NONE, NULL, 0,
"AttributeCertificateV1", HFILL }},
{ &hf_cms_v2AttrCert,
{ "v2AttrCert", "cms.v2AttrCert_element",
FT_NONE, BASE_NONE, NULL, 0,
"AttributeCertificateV2", HFILL }},
{ &hf_cms_CertificateSet_item,
{ "CertificateChoices", "cms.CertificateChoices",
FT_UINT32, BASE_DEC, VALS(cms_CertificateChoices_vals), 0,
NULL, HFILL }},
{ &hf_cms_issuer,
{ "issuer", "cms.issuer",
FT_UINT32, BASE_DEC, VALS(x509if_Name_vals), 0,
"Name", HFILL }},
{ &hf_cms_serialNumber,
{ "serialNumber", "cms.serialNumber",
FT_INT32, BASE_DEC, NULL, 0,
"CertificateSerialNumber", HFILL }},
{ &hf_cms_keyAttrId,
{ "keyAttrId", "cms.keyAttrId",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_keyAttr,
{ "keyAttr", "cms.keyAttr_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_utcTime,
{ "utcTime", "cms.utcTime",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_generalTime,
{ "generalTime", "cms.generalTime",
FT_STRING, BASE_NONE, NULL, 0,
"GeneralizedTime", HFILL }},
{ &hf_cms_rc2ParameterVersion,
{ "rc2ParameterVersion", "cms.rc2ParameterVersion",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_cms_iv,
{ "iv", "cms.iv",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_cms_extendedCertificateInfo,
{ "extendedCertificateInfo", "cms.extendedCertificateInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_signature,
{ "signature", "cms.signature",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_attributes,
{ "attributes", "cms.attributes",
FT_UINT32, BASE_DEC, NULL, 0,
"UnauthAttributes", HFILL }},
{ &hf_cms_SMIMECapabilities_item,
{ "SMIMECapability", "cms.SMIMECapability_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_capability,
{ "capability", "cms.capability",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_parameters,
{ "parameters", "cms.parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_recipientKeyId,
{ "recipientKeyId", "cms.recipientKeyId_element",
FT_NONE, BASE_NONE, NULL, 0,
"RecipientKeyIdentifier", HFILL }},
{ &hf_cms_subjectAltKeyIdentifier,
{ "subjectAltKeyIdentifier", "cms.subjectAltKeyIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
"SubjectKeyIdentifier", HFILL }},
{ &hf_cms_rc2WrapParameter,
{ "rc2WrapParameter", "cms.rc2WrapParameter",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_cms_rc2CBCParameter,
{ "rc2CBCParameter", "cms.rc2CBCParameter_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_acInfo,
{ "acInfo", "cms.acInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
"AttributeCertificateInfoV1", HFILL }},
{ &hf_cms_signatureAlgorithm_v1,
{ "signatureAlgorithm", "cms.signatureAlgorithm_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_cms_signatureValue_v1,
{ "signature", "cms.signature",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_cms_version_v1,
{ "version", "cms.version",
FT_INT32, BASE_DEC, VALS(cms_AttCertVersionV1_vals), 0,
"AttCertVersionV1", HFILL }},
{ &hf_cms_subject,
{ "subject", "cms.subject",
FT_UINT32, BASE_DEC, VALS(cms_T_subject_vals), 0,
NULL, HFILL }},
{ &hf_cms_baseCertificateID,
{ "baseCertificateID", "cms.baseCertificateID_element",
FT_NONE, BASE_NONE, NULL, 0,
"IssuerSerial", HFILL }},
{ &hf_cms_subjectName,
{ "subjectName", "cms.subjectName",
FT_UINT32, BASE_DEC, NULL, 0,
"GeneralNames", HFILL }},
{ &hf_cms_issuer_v1,
{ "issuer", "cms.issuer",
FT_UINT32, BASE_DEC, NULL, 0,
"GeneralNames", HFILL }},
{ &hf_cms_signature_v1,
{ "signature", "cms.signature_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_cms_attCertValidityPeriod,
{ "attCertValidityPeriod", "cms.attCertValidityPeriod_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_attributes_v1,
{ "attributes", "cms.attributes",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_Attribute", HFILL }},
{ &hf_cms_attributes_v1_item,
{ "Attribute", "cms.Attribute_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cms_issuerUniqueID,
{ "issuerUniqueID", "cms.issuerUniqueID",
FT_BYTES, BASE_NONE, NULL, 0,
"UniqueIdentifier", HFILL }},
{ &hf_cms_extensions,
{ "extensions", "cms.extensions",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
#line 149 "../../asn1/cms/packet-cms-template.c"
};
static gint *ett[] = {
#line 1 "../../asn1/cms/packet-cms-ettarr.c"
&ett_cms_ContentInfo,
&ett_cms_SignedData,
&ett_cms_DigestAlgorithmIdentifiers,
&ett_cms_SignerInfos,
&ett_cms_EncapsulatedContentInfo,
&ett_cms_SignerInfo,
&ett_cms_SignerIdentifier,
&ett_cms_SignedAttributes,
&ett_cms_UnsignedAttributes,
&ett_cms_Attribute,
&ett_cms_SET_OF_AttributeValue,
&ett_cms_EnvelopedData,
&ett_cms_OriginatorInfo,
&ett_cms_RecipientInfos,
&ett_cms_EncryptedContentInfo,
&ett_cms_UnprotectedAttributes,
&ett_cms_RecipientInfo,
&ett_cms_KeyTransRecipientInfo,
&ett_cms_RecipientIdentifier,
&ett_cms_KeyAgreeRecipientInfo,
&ett_cms_OriginatorIdentifierOrKey,
&ett_cms_OriginatorPublicKey,
&ett_cms_RecipientEncryptedKeys,
&ett_cms_RecipientEncryptedKey,
&ett_cms_KeyAgreeRecipientIdentifier,
&ett_cms_RecipientKeyIdentifier,
&ett_cms_KEKRecipientInfo,
&ett_cms_KEKIdentifier,
&ett_cms_PasswordRecipientInfo,
&ett_cms_OtherRecipientInfo,
&ett_cms_DigestedData,
&ett_cms_EncryptedData,
&ett_cms_AuthenticatedData,
&ett_cms_AuthAttributes,
&ett_cms_UnauthAttributes,
&ett_cms_RevocationInfoChoices,
&ett_cms_RevocationInfoChoice,
&ett_cms_OtherRevocationInfoFormat,
&ett_cms_CertificateChoices,
&ett_cms_CertificateSet,
&ett_cms_IssuerAndSerialNumber,
&ett_cms_OtherKeyAttribute,
&ett_cms_Time,
&ett_cms_RC2CBCParameter,
&ett_cms_ExtendedCertificate,
&ett_cms_ExtendedCertificateInfo,
&ett_cms_SMIMECapabilities,
&ett_cms_SMIMECapability,
&ett_cms_SMIMEEncryptionKeyPreference,
&ett_cms_RC2CBCParameters,
&ett_cms_AttributeCertificateV1,
&ett_cms_AttributeCertificateInfoV1,
&ett_cms_T_subject,
&ett_cms_SEQUENCE_OF_Attribute,
#line 154 "../../asn1/cms/packet-cms-template.c"
};
proto_cms = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_cms, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_ber_syntax_dissector("ContentInfo", proto_cms, dissect_ContentInfo_PDU);
register_ber_syntax_dissector("SignedData", proto_cms, dissect_SignedData_PDU);
register_ber_oid_syntax(".p7s", NULL, "ContentInfo");
register_ber_oid_syntax(".p7m", NULL, "ContentInfo");
register_ber_oid_syntax(".p7c", NULL, "ContentInfo");
}
void proto_reg_handoff_cms(void) {
#line 1 "../../asn1/cms/packet-cms-dis-tab.c"
register_ber_oid_dissector("1.2.840.113549.1.9.16.1.6", dissect_ContentInfo_PDU, proto_cms, "id-ct-contentInfo");
register_ber_oid_dissector("1.2.840.113549.1.7.2", dissect_SignedData_PDU, proto_cms, "id-signedData");
register_ber_oid_dissector("1.2.840.113549.1.7.3", dissect_EnvelopedData_PDU, proto_cms, "id-envelopedData");
register_ber_oid_dissector("1.2.840.113549.1.7.5", dissect_DigestedData_PDU, proto_cms, "id-digestedData");
register_ber_oid_dissector("1.2.840.113549.1.7.6", dissect_EncryptedData_PDU, proto_cms, "id-encryptedData");
register_ber_oid_dissector("1.2.840.113549.1.9.16.1.2", dissect_AuthenticatedData_PDU, proto_cms, "id-ct-authenticatedData");
register_ber_oid_dissector("1.2.840.113549.1.9.3", dissect_ContentType_PDU, proto_cms, "id-contentType");
register_ber_oid_dissector("1.2.840.113549.1.9.4", dissect_MessageDigest_PDU, proto_cms, "id-messageDigest");
register_ber_oid_dissector("1.2.840.113549.1.9.5", dissect_SigningTime_PDU, proto_cms, "id-signingTime");
register_ber_oid_dissector("1.2.840.113549.1.9.6", dissect_Countersignature_PDU, proto_cms, "id-counterSignature");
register_ber_oid_dissector("2.6.1.4.18", dissect_ContentInfo_PDU, proto_cms, "id-et-pkcs7");
register_ber_oid_dissector("1.3.6.1.4.1.311.16.4", dissect_IssuerAndSerialNumber_PDU, proto_cms, "ms-oe-encryption-key-preference");
register_ber_oid_dissector("1.2.840.113549.1.9.15", dissect_SMIMECapabilities_PDU, proto_cms, "id-smime-capabilities");
register_ber_oid_dissector("1.2.840.113549.1.9.16.2.11", dissect_SMIMEEncryptionKeyPreference_PDU, proto_cms, "id-encryption-key-preference");
register_ber_oid_dissector("1.2.840.113549.3.2", dissect_RC2CBCParameters_PDU, proto_cms, "id-alg-rc2-cbc");
register_ber_oid_dissector("1.2.840.113549.3.4", dissect_RC2CBCParameters_PDU, proto_cms, "id-alg-rc4");
register_ber_oid_dissector("1.2.840.113549.1.9.16.3.7", dissect_RC2WrapParameter_PDU, proto_cms, "id-alg-cmsrc2-wrap");
register_ber_oid_dissector("2.16.840.1.113730.3.1.40", dissect_SignedData_PDU, proto_cms, "userSMIMECertificate");
#line 176 "../../asn1/cms/packet-cms-template.c"
oid_add_from_string("id-data","1.2.840.113549.1.7.1");
oid_add_from_string("id-alg-des-ede3-cbc","1.2.840.113549.3.7");
oid_add_from_string("id-alg-des-cbc","1.3.14.3.2.7");
}
