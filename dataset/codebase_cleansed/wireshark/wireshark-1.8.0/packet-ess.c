static void *
ess_copy_cb(void *dest, const void *orig, size_t len _U_)
{
ess_category_attributes_t *u = dest;
const ess_category_attributes_t *o = orig;
u->oid = g_strdup(o->oid);
u->lacv = o->lacv;
u->name = g_strdup(o->name);
return dest;
}
static void
ess_free_cb(void *r)
{
ess_category_attributes_t *u = r;
g_free(u->oid);
g_free(u->name);
}
static void
ess_dissect_attribute (guint32 value, asn1_ctx_t *actx)
{
guint i;
for (i = 0; i < num_ess_category_attributes; i++) {
ess_category_attributes_t *u = &(ess_category_attributes[i]);
if ((strcmp (u->oid, object_identifier_id) == 0) &&
(u->lacv == value))
{
proto_item_append_text (actx->created_item, " (%s)", u->name);
break;
}
}
}
static void
ess_dissect_attribute_flags (tvbuff_t *tvb, asn1_ctx_t *actx)
{
proto_tree *tree;
guint8 *value;
guint i;
tree = proto_item_add_subtree (actx->created_item, ett_Category_attributes);
value = tvb_get_ephemeral_string (tvb, 0, tvb_length (tvb));
for (i = 0; i < num_ess_category_attributes; i++) {
ess_category_attributes_t *u = &(ess_category_attributes[i]);
if ((strcmp (u->oid, object_identifier_id) == 0) &&
((u->lacv / 8) < tvb_length (tvb)) &&
(value[u->lacv / 8] & (1 << (7 - (u->lacv % 8)))))
{
proto_tree_add_string_format (tree, hf_ess_Category_attribute, tvb,
u->lacv / 8, 1, u->name,
"%s (%d)", u->name, u->lacv);
}
}
}
static int
dissect_ess_ContentIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ess_AllOrFirstTier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ess_SEQUENCE_OF_GeneralNames(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_GeneralNames_sequence_of, hf_index, ett_ess_SEQUENCE_OF_GeneralNames);
return offset;
}
static int
dissect_ess_ReceiptsFrom(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ReceiptsFrom_choice, hf_index, ett_ess_ReceiptsFrom,
NULL);
return offset;
}
static int
dissect_ess_SEQUENCE_SIZE_1_ub_receiptsTo_OF_GeneralNames(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_sequence_of(implicit_tag, actx, tree, tvb, offset,
1, ub_receiptsTo, SEQUENCE_SIZE_1_ub_receiptsTo_OF_GeneralNames_sequence_of, hf_index, ett_ess_SEQUENCE_SIZE_1_ub_receiptsTo_OF_GeneralNames);
return offset;
}
static int
dissect_ess_ReceiptRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ReceiptRequest_sequence, hf_index, ett_ess_ReceiptRequest);
return offset;
}
static int
dissect_ess_ESSVersion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ess_OCTET_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ess_Receipt(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 102 "../../asn1/ess/ess.cnf"
col_set_str(actx->pinfo->cinfo, COL_PROTOCOL, "ESS");
col_set_str(actx->pinfo->cinfo, COL_INFO, "Signed Receipt");
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Receipt_sequence, hf_index, ett_ess_Receipt);
return offset;
}
static int
dissect_ess_UTF8String_SIZE_1_MAX(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_restricted_string(implicit_tag, BER_UNI_TAG_UTF8String,
actx, tree, tvb, offset,
1, NO_BOUND, hf_index, NULL);
return offset;
}
static int
dissect_ess_ContentHints(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ContentHints_sequence, hf_index, ett_ess_ContentHints);
return offset;
}
static int
dissect_ess_MsgSigDigest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ess_ContentReference(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ContentReference_sequence, hf_index, ett_ess_ContentReference);
return offset;
}
static int
dissect_ess_SecurityPolicyIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_ess_SecurityClassification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_integer(implicit_tag, actx, tree, tvb, offset,
0U, ub_integer_options, hf_index, NULL);
return offset;
}
static int
dissect_ess_PrintableString_SIZE_1_ub_privacy_mark_length(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset,
1, ub_privacy_mark_length, hf_index, NULL);
return offset;
}
static int
dissect_ess_ESSPrivacyMark(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ESSPrivacyMark_choice, hf_index, ett_ess_ESSPrivacyMark,
NULL);
return offset;
}
static int
dissect_ess_T_type(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_ess_SecurityCategory_type_OID, &object_identifier_id);
return offset;
}
static int
dissect_ess_T_value(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 51 "../../asn1/ess/ess.cnf"
offset=call_ber_oid_callback(object_identifier_id, tvb, offset, actx->pinfo, tree);
return offset;
}
static int
dissect_ess_SecurityCategory(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SecurityCategory_sequence, hf_index, ett_ess_SecurityCategory);
return offset;
}
static int
dissect_ess_SecurityCategories(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_set_of(implicit_tag, actx, tree, tvb, offset,
1, ub_security_categories, SecurityCategories_set_of, hf_index, ett_ess_SecurityCategories);
return offset;
}
static int
dissect_ess_ESSSecurityLabel(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ESSSecurityLabel_set, hf_index, ett_ess_ESSSecurityLabel);
return offset;
}
static int
dissect_ess_T_restrictiveTagName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &object_identifier_id);
return offset;
}
static int
dissect_ess_T_restrictiveAttributeFlags(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 78 "../../asn1/ess/ess.cnf"
tvbuff_t *attributes;
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
&attributes);
ess_dissect_attribute_flags (attributes, actx);
return offset;
}
static int
dissect_ess_RestrictiveTag(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RestrictiveTag_sequence, hf_index, ett_ess_RestrictiveTag);
return offset;
}
static int
dissect_ess_T_tagName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &object_identifier_id);
return offset;
}
static int
dissect_ess_SecurityAttribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 69 "../../asn1/ess/ess.cnf"
guint32 attribute;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&attribute);
ess_dissect_attribute (attribute, actx);
return offset;
}
static int
dissect_ess_SET_OF_SecurityAttribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_SecurityAttribute_set_of, hf_index, ett_ess_SET_OF_SecurityAttribute);
return offset;
}
static int
dissect_ess_EnumeratedTag(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EnumeratedTag_sequence, hf_index, ett_ess_EnumeratedTag);
return offset;
}
static int
dissect_ess_T_permissiveTagName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &object_identifier_id);
return offset;
}
static int
dissect_ess_T_permissiveAttributeFlags(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 87 "../../asn1/ess/ess.cnf"
tvbuff_t *attributes;
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
&attributes);
ess_dissect_attribute_flags (attributes, actx);
return offset;
}
static int
dissect_ess_PermissiveTag(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PermissiveTag_sequence, hf_index, ett_ess_PermissiveTag);
return offset;
}
static int
dissect_ess_T_informativeTagName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &object_identifier_id);
return offset;
}
static int
dissect_ess_T_informativeAttributeFlags(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 96 "../../asn1/ess/ess.cnf"
tvbuff_t *attributes;
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
&attributes);
ess_dissect_attribute_flags (attributes, actx);
return offset;
}
static int
dissect_ess_FreeFormField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
FreeFormField_choice, hf_index, ett_ess_FreeFormField,
NULL);
return offset;
}
static int
dissect_ess_InformativeTag(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
InformativeTag_sequence, hf_index, ett_ess_InformativeTag);
return offset;
}
static int
dissect_ess_EquivalentLabels(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
EquivalentLabels_sequence_of, hf_index, ett_ess_EquivalentLabels);
return offset;
}
static int
dissect_ess_EntityIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
EntityIdentifier_choice, hf_index, ett_ess_EntityIdentifier,
NULL);
return offset;
}
static int
dissect_ess_GeneralizedTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_GeneralizedTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_ess_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_ess_SEQUENCE_SIZE_1_MAX_OF_GeneralNames(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_sequence_of(implicit_tag, actx, tree, tvb, offset,
1, NO_BOUND, SEQUENCE_SIZE_1_MAX_OF_GeneralNames_sequence_of, hf_index, ett_ess_SEQUENCE_SIZE_1_MAX_OF_GeneralNames);
return offset;
}
static int
dissect_ess_MLReceiptPolicy(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
MLReceiptPolicy_choice, hf_index, ett_ess_MLReceiptPolicy,
NULL);
return offset;
}
static int
dissect_ess_MLData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MLData_sequence, hf_index, ett_ess_MLData);
return offset;
}
static int
dissect_ess_MLExpansionHistory(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_sequence_of(implicit_tag, actx, tree, tvb, offset,
1, ub_ml_expansion_history, MLExpansionHistory_sequence_of, hf_index, ett_ess_MLExpansionHistory);
return offset;
}
static int
dissect_ess_Hash(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ess_IssuerSerial(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IssuerSerial_sequence, hf_index, ett_ess_IssuerSerial);
return offset;
}
static int
dissect_ess_ESSCertID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ESSCertID_sequence, hf_index, ett_ess_ESSCertID);
return offset;
}
static int
dissect_ess_SEQUENCE_OF_ESSCertID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_ESSCertID_sequence_of, hf_index, ett_ess_SEQUENCE_OF_ESSCertID);
return offset;
}
static int
dissect_ess_SEQUENCE_OF_PolicyInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_PolicyInformation_sequence_of, hf_index, ett_ess_SEQUENCE_OF_PolicyInformation);
return offset;
}
static int
dissect_ess_SigningCertificate(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SigningCertificate_sequence, hf_index, ett_ess_SigningCertificate);
return offset;
}
static int
dissect_ess_ESSCertIDv2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ESSCertIDv2_sequence, hf_index, ett_ess_ESSCertIDv2);
return offset;
}
static int
dissect_ess_SEQUENCE_OF_ESSCertIDv2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_ESSCertIDv2_sequence_of, hf_index, ett_ess_SEQUENCE_OF_ESSCertIDv2);
return offset;
}
static int
dissect_ess_SigningCertificateV2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SigningCertificateV2_sequence, hf_index, ett_ess_SigningCertificateV2);
return offset;
}
static void dissect_ReceiptRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_ess_ReceiptRequest(FALSE, tvb, 0, &asn1_ctx, tree, hf_ess_ReceiptRequest_PDU);
}
static void dissect_ContentIdentifier_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_ess_ContentIdentifier(FALSE, tvb, 0, &asn1_ctx, tree, hf_ess_ContentIdentifier_PDU);
}
static void dissect_Receipt_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_ess_Receipt(FALSE, tvb, 0, &asn1_ctx, tree, hf_ess_Receipt_PDU);
}
static void dissect_ContentHints_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_ess_ContentHints(FALSE, tvb, 0, &asn1_ctx, tree, hf_ess_ContentHints_PDU);
}
static void dissect_MsgSigDigest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_ess_MsgSigDigest(FALSE, tvb, 0, &asn1_ctx, tree, hf_ess_MsgSigDigest_PDU);
}
static void dissect_ContentReference_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_ess_ContentReference(FALSE, tvb, 0, &asn1_ctx, tree, hf_ess_ContentReference_PDU);
}
void dissect_ess_ESSSecurityLabel_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_ess_ESSSecurityLabel(FALSE, tvb, 0, &asn1_ctx, tree, hf_ess_ess_ESSSecurityLabel_PDU);
}
static void dissect_RestrictiveTag_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_ess_RestrictiveTag(FALSE, tvb, 0, &asn1_ctx, tree, hf_ess_RestrictiveTag_PDU);
}
static void dissect_EnumeratedTag_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_ess_EnumeratedTag(FALSE, tvb, 0, &asn1_ctx, tree, hf_ess_EnumeratedTag_PDU);
}
static void dissect_PermissiveTag_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_ess_PermissiveTag(FALSE, tvb, 0, &asn1_ctx, tree, hf_ess_PermissiveTag_PDU);
}
static void dissect_InformativeTag_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_ess_InformativeTag(FALSE, tvb, 0, &asn1_ctx, tree, hf_ess_InformativeTag_PDU);
}
static void dissect_EquivalentLabels_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_ess_EquivalentLabels(FALSE, tvb, 0, &asn1_ctx, tree, hf_ess_EquivalentLabels_PDU);
}
static void dissect_MLExpansionHistory_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_ess_MLExpansionHistory(FALSE, tvb, 0, &asn1_ctx, tree, hf_ess_MLExpansionHistory_PDU);
}
static void dissect_SigningCertificate_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_ess_SigningCertificate(FALSE, tvb, 0, &asn1_ctx, tree, hf_ess_SigningCertificate_PDU);
}
static void dissect_SigningCertificateV2_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_ess_SigningCertificateV2(FALSE, tvb, 0, &asn1_ctx, tree, hf_ess_SigningCertificateV2_PDU);
}
void proto_register_ess(void) {
static hf_register_info hf[] = {
{ &hf_ess_SecurityCategory_type_OID,
{ "type", "ess.type_OID", FT_STRING, BASE_NONE, NULL, 0,
"Type of Security Category", HFILL }},
{ &hf_ess_Category_attribute,
{ "Attribute", "ess.attribute", FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
#line 1 "../../asn1/ess/packet-ess-hfarr.c"
{ &hf_ess_ReceiptRequest_PDU,
{ "ReceiptRequest", "ess.ReceiptRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ess_ContentIdentifier_PDU,
{ "ContentIdentifier", "ess.ContentIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ess_Receipt_PDU,
{ "Receipt", "ess.Receipt",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ess_ContentHints_PDU,
{ "ContentHints", "ess.ContentHints",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ess_MsgSigDigest_PDU,
{ "MsgSigDigest", "ess.MsgSigDigest",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ess_ContentReference_PDU,
{ "ContentReference", "ess.ContentReference",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ess_ess_ESSSecurityLabel_PDU,
{ "ESSSecurityLabel", "ess.ESSSecurityLabel",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ess_RestrictiveTag_PDU,
{ "RestrictiveTag", "ess.RestrictiveTag",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ess_EnumeratedTag_PDU,
{ "EnumeratedTag", "ess.EnumeratedTag",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ess_PermissiveTag_PDU,
{ "PermissiveTag", "ess.PermissiveTag",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ess_InformativeTag_PDU,
{ "InformativeTag", "ess.InformativeTag",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ess_EquivalentLabels_PDU,
{ "EquivalentLabels", "ess.EquivalentLabels",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ess_MLExpansionHistory_PDU,
{ "MLExpansionHistory", "ess.MLExpansionHistory",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ess_SigningCertificate_PDU,
{ "SigningCertificate", "ess.SigningCertificate",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ess_SigningCertificateV2_PDU,
{ "SigningCertificateV2", "ess.SigningCertificateV2",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ess_signedContentIdentifier,
{ "signedContentIdentifier", "ess.signedContentIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
"ContentIdentifier", HFILL }},
{ &hf_ess_receiptsFrom,
{ "receiptsFrom", "ess.receiptsFrom",
FT_UINT32, BASE_DEC, VALS(ess_ReceiptsFrom_vals), 0,
NULL, HFILL }},
{ &hf_ess_receiptsTo,
{ "receiptsTo", "ess.receiptsTo",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_ub_receiptsTo_OF_GeneralNames", HFILL }},
{ &hf_ess_receiptsTo_item,
{ "GeneralNames", "ess.GeneralNames",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ess_allOrFirstTier,
{ "allOrFirstTier", "ess.allOrFirstTier",
FT_INT32, BASE_DEC, VALS(ess_AllOrFirstTier_vals), 0,
NULL, HFILL }},
{ &hf_ess_receiptList,
{ "receiptList", "ess.receiptList",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_GeneralNames", HFILL }},
{ &hf_ess_receiptList_item,
{ "GeneralNames", "ess.GeneralNames",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ess_version,
{ "version", "ess.version",
FT_INT32, BASE_DEC, VALS(ess_ESSVersion_vals), 0,
"ESSVersion", HFILL }},
{ &hf_ess_contentType,
{ "contentType", "ess.contentType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ess_originatorSignatureValue,
{ "originatorSignatureValue", "ess.originatorSignatureValue",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_ess_contentDescription,
{ "contentDescription", "ess.contentDescription",
FT_STRING, BASE_NONE, NULL, 0,
"UTF8String_SIZE_1_MAX", HFILL }},
{ &hf_ess_security_policy_identifier,
{ "security-policy-identifier", "ess.security_policy_identifier",
FT_OID, BASE_NONE, NULL, 0,
"SecurityPolicyIdentifier", HFILL }},
{ &hf_ess_security_classification,
{ "security-classification", "ess.security_classification",
FT_UINT32, BASE_DEC, VALS(ess_SecurityClassification_vals), 0,
"SecurityClassification", HFILL }},
{ &hf_ess_privacy_mark,
{ "privacy-mark", "ess.privacy_mark",
FT_UINT32, BASE_DEC, VALS(ess_ESSPrivacyMark_vals), 0,
"ESSPrivacyMark", HFILL }},
{ &hf_ess_security_categories,
{ "security-categories", "ess.security_categories",
FT_UINT32, BASE_DEC, NULL, 0,
"SecurityCategories", HFILL }},
{ &hf_ess_pString,
{ "pString", "ess.pString",
FT_STRING, BASE_NONE, NULL, 0,
"PrintableString_SIZE_1_ub_privacy_mark_length", HFILL }},
{ &hf_ess_utf8String,
{ "utf8String", "ess.utf8String",
FT_STRING, BASE_NONE, NULL, 0,
"UTF8String_SIZE_1_MAX", HFILL }},
{ &hf_ess_SecurityCategories_item,
{ "SecurityCategory", "ess.SecurityCategory",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ess_type,
{ "type", "ess.type",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ess_value,
{ "value", "ess.value",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ess_restrictiveTagName,
{ "tagName", "ess.tagName",
FT_OID, BASE_NONE, NULL, 0,
"T_restrictiveTagName", HFILL }},
{ &hf_ess_restrictiveAttributeFlags,
{ "attributeFlags", "ess.attributeFlags",
FT_BYTES, BASE_NONE, NULL, 0,
"T_restrictiveAttributeFlags", HFILL }},
{ &hf_ess_tagName,
{ "tagName", "ess.tagName",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ess_attributeList,
{ "attributeList", "ess.attributeList",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_SecurityAttribute", HFILL }},
{ &hf_ess_attributeList_item,
{ "SecurityAttribute", "ess.SecurityAttribute",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ess_permissiveTagName,
{ "tagName", "ess.tagName",
FT_OID, BASE_NONE, NULL, 0,
"T_permissiveTagName", HFILL }},
{ &hf_ess_permissiveAttributeFlags,
{ "attributeFlags", "ess.attributeFlags",
FT_BYTES, BASE_NONE, NULL, 0,
"T_permissiveAttributeFlags", HFILL }},
{ &hf_ess_informativeTagName,
{ "tagName", "ess.tagName",
FT_OID, BASE_NONE, NULL, 0,
"T_informativeTagName", HFILL }},
{ &hf_ess_attributes,
{ "attributes", "ess.attributes",
FT_UINT32, BASE_DEC, VALS(ess_FreeFormField_vals), 0,
"FreeFormField", HFILL }},
{ &hf_ess_informativeAttributeFlags,
{ "bitSetAttributes", "ess.bitSetAttributes",
FT_BYTES, BASE_NONE, NULL, 0,
"T_informativeAttributeFlags", HFILL }},
{ &hf_ess_securityAttributes,
{ "securityAttributes", "ess.securityAttributes",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_SecurityAttribute", HFILL }},
{ &hf_ess_securityAttributes_item,
{ "SecurityAttribute", "ess.SecurityAttribute",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ess_EquivalentLabels_item,
{ "ESSSecurityLabel", "ess.ESSSecurityLabel",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ess_MLExpansionHistory_item,
{ "MLData", "ess.MLData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ess_mailListIdentifier,
{ "mailListIdentifier", "ess.mailListIdentifier",
FT_UINT32, BASE_DEC, VALS(ess_EntityIdentifier_vals), 0,
"EntityIdentifier", HFILL }},
{ &hf_ess_expansionTime,
{ "expansionTime", "ess.expansionTime",
FT_STRING, BASE_NONE, NULL, 0,
"GeneralizedTime", HFILL }},
{ &hf_ess_mlReceiptPolicy,
{ "mlReceiptPolicy", "ess.mlReceiptPolicy",
FT_UINT32, BASE_DEC, VALS(ess_MLReceiptPolicy_vals), 0,
NULL, HFILL }},
{ &hf_ess_issuerAndSerialNumber,
{ "issuerAndSerialNumber", "ess.issuerAndSerialNumber",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ess_subjectKeyIdentifier,
{ "subjectKeyIdentifier", "ess.subjectKeyIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ess_none,
{ "none", "ess.none",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ess_insteadOf,
{ "insteadOf", "ess.insteadOf",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_GeneralNames", HFILL }},
{ &hf_ess_insteadOf_item,
{ "GeneralNames", "ess.GeneralNames",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ess_inAdditionTo,
{ "inAdditionTo", "ess.inAdditionTo",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_GeneralNames", HFILL }},
{ &hf_ess_inAdditionTo_item,
{ "GeneralNames", "ess.GeneralNames",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ess_certs,
{ "certs", "ess.certs",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ESSCertID", HFILL }},
{ &hf_ess_certs_item,
{ "ESSCertID", "ess.ESSCertID",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ess_policies,
{ "policies", "ess.policies",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_PolicyInformation", HFILL }},
{ &hf_ess_policies_item,
{ "PolicyInformation", "ess.PolicyInformation",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ess_certsV2,
{ "certs", "ess.certs",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ESSCertIDv2", HFILL }},
{ &hf_ess_certsV2_item,
{ "ESSCertIDv2", "ess.ESSCertIDv2",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ess_hashAlgorithm,
{ "hashAlgorithm", "ess.hashAlgorithm",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_ess_certHash,
{ "certHash", "ess.certHash",
FT_BYTES, BASE_NONE, NULL, 0,
"Hash", HFILL }},
{ &hf_ess_issuerSerial,
{ "issuerSerial", "ess.issuerSerial",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ess_issuer,
{ "issuer", "ess.issuer",
FT_UINT32, BASE_DEC, NULL, 0,
"GeneralNames", HFILL }},
{ &hf_ess_serialNumber,
{ "serialNumber", "ess.serialNumber",
FT_INT32, BASE_DEC, NULL, 0,
"CertificateSerialNumber", HFILL }},
#line 155 "../../asn1/ess/packet-ess-template.c"
};
static gint *ett[] = {
&ett_Category_attributes,
#line 1 "../../asn1/ess/packet-ess-ettarr.c"
&ett_ess_ReceiptRequest,
&ett_ess_SEQUENCE_SIZE_1_ub_receiptsTo_OF_GeneralNames,
&ett_ess_ReceiptsFrom,
&ett_ess_SEQUENCE_OF_GeneralNames,
&ett_ess_Receipt,
&ett_ess_ContentHints,
&ett_ess_ContentReference,
&ett_ess_ESSSecurityLabel,
&ett_ess_ESSPrivacyMark,
&ett_ess_SecurityCategories,
&ett_ess_SecurityCategory,
&ett_ess_RestrictiveTag,
&ett_ess_EnumeratedTag,
&ett_ess_SET_OF_SecurityAttribute,
&ett_ess_PermissiveTag,
&ett_ess_InformativeTag,
&ett_ess_FreeFormField,
&ett_ess_EquivalentLabels,
&ett_ess_MLExpansionHistory,
&ett_ess_MLData,
&ett_ess_EntityIdentifier,
&ett_ess_MLReceiptPolicy,
&ett_ess_SEQUENCE_SIZE_1_MAX_OF_GeneralNames,
&ett_ess_SigningCertificate,
&ett_ess_SEQUENCE_OF_ESSCertID,
&ett_ess_SEQUENCE_OF_PolicyInformation,
&ett_ess_SigningCertificateV2,
&ett_ess_SEQUENCE_OF_ESSCertIDv2,
&ett_ess_ESSCertIDv2,
&ett_ess_ESSCertID,
&ett_ess_IssuerSerial,
#line 161 "../../asn1/ess/packet-ess-template.c"
};
static uat_field_t attributes_flds[] = {
UAT_FLD_CSTRING(ess_category_attributes,oid, "Tag Set", "Category Tag Set (Object Identifier)"),
UAT_FLD_DEC(ess_category_attributes,lacv, "Value", "Label And Cert Value"),
UAT_FLD_CSTRING(ess_category_attributes,name, "Name", "Category Name"),
UAT_END_FIELDS
};
uat_t *attributes_uat = uat_new("ESS Category Attributes",
sizeof(ess_category_attributes_t),
"ess_category_attributes",
TRUE,
(void*) &ess_category_attributes,
&num_ess_category_attributes,
UAT_CAT_PORTS,
"ChEssCategoryAttributes",
ess_copy_cb,
NULL,
ess_free_cb,
NULL,
attributes_flds);
static module_t *ess_module;
proto_ess = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_ess, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
ess_module = prefs_register_protocol(proto_ess, NULL);
prefs_register_uat_preference(ess_module, "attributes_table",
"ESS Category Attributes",
"ESS category attributes translation table",
attributes_uat);
}
void proto_reg_handoff_ess(void) {
#line 1 "../../asn1/ess/packet-ess-dis-tab.c"
register_ber_oid_dissector("1.2.840.113549.1.9.16.2.1", dissect_ReceiptRequest_PDU, proto_ess, "id-aa-receiptRequest");
register_ber_oid_dissector("1.2.840.113549.1.9.16.2.7", dissect_ContentIdentifier_PDU, proto_ess, "id-aa-contentIdentifier");
register_ber_oid_dissector("1.2.840.113549.1.9.16.1.1", dissect_Receipt_PDU, proto_ess, "id-ct-receipt");
register_ber_oid_dissector("1.2.840.113549.1.9.16.2.4", dissect_ContentHints_PDU, proto_ess, "id-aa-contentHint");
register_ber_oid_dissector("1.2.840.113549.1.9.16.2.5", dissect_MsgSigDigest_PDU, proto_ess, "id-aa-msgSigDigest");
register_ber_oid_dissector("1.2.840.113549.1.9.16.2.10", dissect_ContentReference_PDU, proto_ess, "id-aa-contentReference");
register_ber_oid_dissector("1.2.840.113549.1.9.16.2.2", dissect_ess_ESSSecurityLabel_PDU, proto_ess, "id-aa-securityLabel");
register_ber_oid_dissector("1.2.840.113549.1.9.16.2.9", dissect_EquivalentLabels_PDU, proto_ess, "id-aa-equivalentLabels");
register_ber_oid_dissector("1.2.840.113549.1.9.16.2.3", dissect_MLExpansionHistory_PDU, proto_ess, "id-aa-mlExpandHistory");
register_ber_oid_dissector("1.2.840.113549.1.9.16.2.12", dissect_SigningCertificate_PDU, proto_ess, "id-aa-signingCertificate");
register_ber_oid_dissector("1.2.840.113549.1.9.16.2.47", dissect_SigningCertificateV2_PDU, proto_ess, "id-aa-signingCertificateV2");
register_ber_oid_dissector("2.16.840.1.101.2.1.8.3.0", dissect_RestrictiveTag_PDU, proto_ess, "id-restrictiveAttributes");
register_ber_oid_dissector("2.16.840.1.101.2.1.8.3.1", dissect_EnumeratedTag_PDU, proto_ess, "id-enumeratedPermissiveAttributes");
register_ber_oid_dissector("2.16.840.1.101.2.1.8.3.2", dissect_PermissiveTag_PDU, proto_ess, "id-permissiveAttributes");
register_ber_oid_dissector("2.16.840.1.101.2.1.8.3.3", dissect_InformativeTag_PDU, proto_ess, "id-informativeAttributes");
register_ber_oid_dissector("2.16.840.1.101.2.1.8.3.4", dissect_EnumeratedTag_PDU, proto_ess, "id-enumeratedRestrictiveAttributes");
#line 206 "../../asn1/ess/packet-ess-template.c"
}
