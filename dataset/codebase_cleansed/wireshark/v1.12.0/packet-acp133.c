static int
dissect_acp133_ACPPreferredDelivery(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_acp133_ALType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_acp133_Community(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_acp133_OnSupported(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
OnSupported_bits, hf_index, ett_acp133_OnSupported,
NULL);
return offset;
}
static int
dissect_acp133_ACPLegacyFormat(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_acp133_ACPNoAttachments(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_acp133_Active(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_acp133_PrintableString_SIZE_1_55(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_acp133_Addressees(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Addressees_sequence_of, hf_index, ett_acp133_Addressees);
return offset;
}
static int
dissect_acp133_Classification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_acp133_DistributionCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_acp133_EmConCapability(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_acp133_EmConState(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_acp133_JPEG(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_acp133_MaxMessageSize(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_acp133_Kmid(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_acp133_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_acp133_UTCTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_UTCTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_acp133_PairwiseTag(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PairwiseTag_sequence, hf_index, ett_acp133_PairwiseTag);
return offset;
}
static int
dissect_acp133_OCTET_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_acp133_UKMEntry(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
UKMEntry_sequence, hf_index, ett_acp133_UKMEntry);
return offset;
}
static int
dissect_acp133_SEQUENCE_OF_UKMEntry(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_UKMEntry_sequence_of, hf_index, ett_acp133_SEQUENCE_OF_UKMEntry);
return offset;
}
static int
dissect_acp133_BIT_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_acp133_MonthlyUKMs(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MonthlyUKMs_sequence, hf_index, ett_acp133_MonthlyUKMs);
return offset;
}
static int
dissect_acp133_MsgProtocolInfoCapability(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_acp133_PrintableString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_acp133_Remarks(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Remarks_sequence_of, hf_index, ett_acp133_Remarks);
return offset;
}
static int
dissect_acp133_T_rIType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_acp133_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_acp133_RIParametersDeprecated(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
RIParametersDeprecated_set, hf_index, ett_acp133_RIParametersDeprecated);
return offset;
}
static int
dissect_acp133_RIParameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
RIParameters_choice, hf_index, ett_acp133_RIParameters,
NULL);
return offset;
}
static int
dissect_acp133_WebAccessCapability(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_acp133_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_acp133_SEQUENCE_OF_GeneralNames(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_GeneralNames_sequence_of, hf_index, ett_acp133_SEQUENCE_OF_GeneralNames);
return offset;
}
static int
dissect_acp133_MLReceiptPolicy(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
MLReceiptPolicy_choice, hf_index, ett_acp133_MLReceiptPolicy,
NULL);
return offset;
}
static int
dissect_acp133_ORNamePattern(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p1_ORName(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_acp133_DLSubmitPermission(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
DLSubmitPermission_choice, hf_index, ett_acp133_DLSubmitPermission,
NULL);
return offset;
}
static int
dissect_acp133_T_report_propagation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_acp133_T_report_from_dl(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_acp133_T_originating_MTA_report(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_acp133_T_originator_report(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_acp133_T_return_of_content(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_acp133_T_priority(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_acp133_T_disclosure_of_other_recipients(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_acp133_T_implicit_conversion_prohibited(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_acp133_T_conversion_with_loss_prohibited(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_acp133_T_proof_of_delivery(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_acp133_T_requested_delivery_method(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_requested_delivery_method_choice, hf_index, ett_acp133_T_requested_delivery_method,
NULL);
return offset;
}
static int
dissect_acp133_AlgorithmInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AlgorithmInformation_sequence, hf_index, ett_acp133_AlgorithmInformation);
return offset;
}
static int
dissect_acp133_SEQUENCE_OF_AlgorithmInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_AlgorithmInformation_sequence_of, hf_index, ett_acp133_SEQUENCE_OF_AlgorithmInformation);
return offset;
}
static int
dissect_acp133_DLPolicy(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
DLPolicy_set, hf_index, ett_acp133_DLPolicy);
return offset;
}
static int
dissect_acp133_GeneralString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_GeneralString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_acp133_SET_OF_ExtendedContentType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_ExtendedContentType_set_of, hf_index, ett_acp133_SET_OF_ExtendedContentType);
return offset;
}
static int
dissect_acp133_Capability(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
Capability_set, hf_index, ett_acp133_Capability);
return offset;
}
static int
dissect_acp133_SET_OF_Capability(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_Capability_set_of, hf_index, ett_acp133_SET_OF_Capability);
return offset;
}
static int
dissect_acp133_AddressCapabilities(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AddressCapabilities_sequence, hf_index, ett_acp133_AddressCapabilities);
return offset;
}
static void dissect_ACPPreferredDelivery_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_acp133_ACPPreferredDelivery(FALSE, tvb, 0, &asn1_ctx, tree, hf_acp133_ACPPreferredDelivery_PDU);
}
static void dissect_ALType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_acp133_ALType(FALSE, tvb, 0, &asn1_ctx, tree, hf_acp133_ALType_PDU);
}
static void dissect_Community_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_acp133_Community(FALSE, tvb, 0, &asn1_ctx, tree, hf_acp133_Community_PDU);
}
static void dissect_OnSupported_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_acp133_OnSupported(FALSE, tvb, 0, &asn1_ctx, tree, hf_acp133_OnSupported_PDU);
}
static void dissect_ACPLegacyFormat_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_acp133_ACPLegacyFormat(FALSE, tvb, 0, &asn1_ctx, tree, hf_acp133_ACPLegacyFormat_PDU);
}
static void dissect_ACPNoAttachments_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_acp133_ACPNoAttachments(FALSE, tvb, 0, &asn1_ctx, tree, hf_acp133_ACPNoAttachments_PDU);
}
static void dissect_Active_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_acp133_Active(FALSE, tvb, 0, &asn1_ctx, tree, hf_acp133_Active_PDU);
}
static void dissect_Addressees_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_acp133_Addressees(FALSE, tvb, 0, &asn1_ctx, tree, hf_acp133_Addressees_PDU);
}
static void dissect_Classification_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_acp133_Classification(FALSE, tvb, 0, &asn1_ctx, tree, hf_acp133_Classification_PDU);
}
static void dissect_DistributionCode_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_acp133_DistributionCode(FALSE, tvb, 0, &asn1_ctx, tree, hf_acp133_DistributionCode_PDU);
}
static void dissect_EmConCapability_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_acp133_EmConCapability(FALSE, tvb, 0, &asn1_ctx, tree, hf_acp133_EmConCapability_PDU);
}
static void dissect_EmConState_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_acp133_EmConState(FALSE, tvb, 0, &asn1_ctx, tree, hf_acp133_EmConState_PDU);
}
static void dissect_JPEG_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_acp133_JPEG(FALSE, tvb, 0, &asn1_ctx, tree, hf_acp133_JPEG_PDU);
}
static void dissect_MaxMessageSize_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_acp133_MaxMessageSize(FALSE, tvb, 0, &asn1_ctx, tree, hf_acp133_MaxMessageSize_PDU);
}
static void dissect_MonthlyUKMs_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_acp133_MonthlyUKMs(FALSE, tvb, 0, &asn1_ctx, tree, hf_acp133_MonthlyUKMs_PDU);
}
static void dissect_MsgProtocolInfoCapability_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_acp133_MsgProtocolInfoCapability(FALSE, tvb, 0, &asn1_ctx, tree, hf_acp133_MsgProtocolInfoCapability_PDU);
}
static void dissect_Remarks_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_acp133_Remarks(FALSE, tvb, 0, &asn1_ctx, tree, hf_acp133_Remarks_PDU);
}
static void dissect_RIParameters_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_acp133_RIParameters(FALSE, tvb, 0, &asn1_ctx, tree, hf_acp133_RIParameters_PDU);
}
static void dissect_WebAccessCapability_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_acp133_WebAccessCapability(FALSE, tvb, 0, &asn1_ctx, tree, hf_acp133_WebAccessCapability_PDU);
}
static void dissect_Kmid_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_acp133_Kmid(FALSE, tvb, 0, &asn1_ctx, tree, hf_acp133_Kmid_PDU);
}
static void dissect_MLReceiptPolicy_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_acp133_MLReceiptPolicy(FALSE, tvb, 0, &asn1_ctx, tree, hf_acp133_MLReceiptPolicy_PDU);
}
static void dissect_DLSubmitPermission_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_acp133_DLSubmitPermission(FALSE, tvb, 0, &asn1_ctx, tree, hf_acp133_DLSubmitPermission_PDU);
}
static void dissect_DLPolicy_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_acp133_DLPolicy(FALSE, tvb, 0, &asn1_ctx, tree, hf_acp133_DLPolicy_PDU);
}
static void dissect_AddressCapabilities_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_acp133_AddressCapabilities(FALSE, tvb, 0, &asn1_ctx, tree, hf_acp133_AddressCapabilities_PDU);
}
static void dissect_Capability_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_acp133_Capability(FALSE, tvb, 0, &asn1_ctx, tree, hf_acp133_Capability_PDU);
}
void proto_register_acp133(void) {
static hf_register_info hf[] =
{
#line 1 "../../asn1/acp133/packet-acp133-hfarr.c"
{ &hf_acp133_ACPPreferredDelivery_PDU,
{ "ACPPreferredDelivery", "acp133.ACPPreferredDelivery",
FT_UINT32, BASE_DEC, VALS(acp133_ACPPreferredDelivery_vals), 0,
NULL, HFILL }},
{ &hf_acp133_ALType_PDU,
{ "ALType", "acp133.ALType",
FT_INT32, BASE_DEC, VALS(acp133_ALType_vals), 0,
NULL, HFILL }},
{ &hf_acp133_Community_PDU,
{ "Community", "acp133.Community",
FT_UINT32, BASE_DEC, VALS(acp133_Community_vals), 0,
NULL, HFILL }},
{ &hf_acp133_OnSupported_PDU,
{ "OnSupported", "acp133.OnSupported",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_acp133_ACPLegacyFormat_PDU,
{ "ACPLegacyFormat", "acp133.ACPLegacyFormat",
FT_INT32, BASE_DEC, VALS(acp133_ACPLegacyFormat_vals), 0,
NULL, HFILL }},
{ &hf_acp133_ACPNoAttachments_PDU,
{ "ACPNoAttachments", "acp133.ACPNoAttachments",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_acp133_Active_PDU,
{ "Active", "acp133.Active",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_acp133_Addressees_PDU,
{ "Addressees", "acp133.Addressees",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_acp133_Classification_PDU,
{ "Classification", "acp133.Classification",
FT_UINT32, BASE_DEC, VALS(acp133_Classification_vals), 0,
NULL, HFILL }},
{ &hf_acp133_DistributionCode_PDU,
{ "DistributionCode", "acp133.DistributionCode",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_acp133_EmConCapability_PDU,
{ "EmConCapability", "acp133.EmConCapability",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_acp133_EmConState_PDU,
{ "EmConState", "acp133.EmConState",
FT_UINT32, BASE_DEC, VALS(acp133_EmConState_vals), 0,
NULL, HFILL }},
{ &hf_acp133_JPEG_PDU,
{ "JPEG", "acp133.JPEG",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_acp133_MaxMessageSize_PDU,
{ "MaxMessageSize", "acp133.MaxMessageSize",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_acp133_MonthlyUKMs_PDU,
{ "MonthlyUKMs", "acp133.MonthlyUKMs_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_acp133_MsgProtocolInfoCapability_PDU,
{ "MsgProtocolInfoCapability", "acp133.MsgProtocolInfoCapability",
FT_UINT32, BASE_DEC, VALS(acp133_MsgProtocolInfoCapability_vals), 0,
NULL, HFILL }},
{ &hf_acp133_Remarks_PDU,
{ "Remarks", "acp133.Remarks",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_acp133_RIParameters_PDU,
{ "RIParameters", "acp133.RIParameters",
FT_UINT32, BASE_DEC, VALS(acp133_RIParameters_vals), 0,
NULL, HFILL }},
{ &hf_acp133_WebAccessCapability_PDU,
{ "WebAccessCapability", "acp133.WebAccessCapability",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_acp133_Kmid_PDU,
{ "Kmid", "acp133.Kmid",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_acp133_MLReceiptPolicy_PDU,
{ "MLReceiptPolicy", "acp133.MLReceiptPolicy",
FT_UINT32, BASE_DEC, VALS(acp133_MLReceiptPolicy_vals), 0,
NULL, HFILL }},
{ &hf_acp133_DLSubmitPermission_PDU,
{ "DLSubmitPermission", "acp133.DLSubmitPermission",
FT_UINT32, BASE_DEC, VALS(acp133_DLSubmitPermission_vals), 0,
NULL, HFILL }},
{ &hf_acp133_DLPolicy_PDU,
{ "DLPolicy", "acp133.DLPolicy_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_acp133_AddressCapabilities_PDU,
{ "AddressCapabilities", "acp133.AddressCapabilities_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_acp133_Capability_PDU,
{ "Capability", "acp133.Capability_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_acp133_Addressees_item,
{ "Addressees item", "acp133.Addressees_item",
FT_STRING, BASE_NONE, NULL, 0,
"PrintableString_SIZE_1_55", HFILL }},
{ &hf_acp133_ukm_entries,
{ "ukm-entries", "acp133.ukm_entries",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_UKMEntry", HFILL }},
{ &hf_acp133_ukm_entries_item,
{ "UKMEntry", "acp133.UKMEntry_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_acp133_algorithm_identifier,
{ "algorithm-identifier", "acp133.algorithm_identifier_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_acp133_encrypted,
{ "encrypted", "acp133.encrypted",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_acp133_Remarks_item,
{ "Remarks item", "acp133.Remarks_item",
FT_STRING, BASE_NONE, NULL, 0,
"PrintableString", HFILL }},
{ &hf_acp133_ri_parameters,
{ "ri-parameters", "acp133.ri_parameters",
FT_UINT32, BASE_DEC, VALS(x509sat_DirectoryString_vals), 0,
"DirectoryString", HFILL }},
{ &hf_acp133_ri_parameters_deprecated,
{ "ri-parameters-deprecated", "acp133.ri_parameters_deprecated_element",
FT_NONE, BASE_NONE, NULL, 0,
"RIParametersDeprecated", HFILL }},
{ &hf_acp133_rI,
{ "rI", "acp133.rI",
FT_STRING, BASE_NONE, NULL, 0,
"PrintableString", HFILL }},
{ &hf_acp133_rIType,
{ "rIType", "acp133.rIType",
FT_UINT32, BASE_DEC, VALS(acp133_T_rIType_vals), 0,
NULL, HFILL }},
{ &hf_acp133_minimize,
{ "minimize", "acp133.minimize",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_acp133_sHD,
{ "sHD", "acp133.sHD",
FT_STRING, BASE_NONE, NULL, 0,
"PrintableString", HFILL }},
{ &hf_acp133_classification,
{ "classification", "acp133.classification",
FT_UINT32, BASE_DEC, VALS(acp133_Classification_vals), 0,
NULL, HFILL }},
{ &hf_acp133_tag,
{ "tag", "acp133.tag_element",
FT_NONE, BASE_NONE, NULL, 0,
"PairwiseTag", HFILL }},
{ &hf_acp133_ukm,
{ "ukm", "acp133.ukm",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_acp133_kmid,
{ "kmid", "acp133.kmid",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_acp133_edition,
{ "edition", "acp133.edition",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_acp133_date,
{ "date", "acp133.date",
FT_STRING, BASE_NONE, NULL, 0,
"UTCTime", HFILL }},
{ &hf_acp133_none,
{ "none", "acp133.none_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_acp133_insteadOf,
{ "insteadOf", "acp133.insteadOf",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_GeneralNames", HFILL }},
{ &hf_acp133_insteadOf_item,
{ "GeneralNames", "acp133.GeneralNames",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_acp133_inAdditionTo,
{ "inAdditionTo", "acp133.inAdditionTo",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_GeneralNames", HFILL }},
{ &hf_acp133_inAdditionTo_item,
{ "GeneralNames", "acp133.GeneralNames",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_acp133_individual,
{ "individual", "acp133.individual_element",
FT_NONE, BASE_NONE, NULL, 0,
"ORName", HFILL }},
{ &hf_acp133_member_of_dl,
{ "member-of-dl", "acp133.member_of_dl_element",
FT_NONE, BASE_NONE, NULL, 0,
"ORName", HFILL }},
{ &hf_acp133_pattern_match,
{ "pattern-match", "acp133.pattern_match_element",
FT_NONE, BASE_NONE, NULL, 0,
"ORNamePattern", HFILL }},
{ &hf_acp133_member_of_group,
{ "member-of-group", "acp133.member_of_group",
FT_UINT32, BASE_DEC, VALS(x509if_Name_vals), 0,
"Name", HFILL }},
{ &hf_acp133_report_propagation,
{ "report-propagation", "acp133.report_propagation",
FT_INT32, BASE_DEC, VALS(acp133_T_report_propagation_vals), 0,
"T_report_propagation", HFILL }},
{ &hf_acp133_report_from_dl,
{ "report-from-dl", "acp133.report_from_dl",
FT_INT32, BASE_DEC, VALS(acp133_T_report_from_dl_vals), 0,
"T_report_from_dl", HFILL }},
{ &hf_acp133_originating_MTA_report,
{ "originating-MTA-report", "acp133.originating_MTA_report",
FT_INT32, BASE_DEC, VALS(acp133_T_originating_MTA_report_vals), 0,
NULL, HFILL }},
{ &hf_acp133_originator_report,
{ "originator-report", "acp133.originator_report",
FT_INT32, BASE_DEC, VALS(acp133_T_originator_report_vals), 0,
NULL, HFILL }},
{ &hf_acp133_return_of_content,
{ "return-of-content", "acp133.return_of_content",
FT_UINT32, BASE_DEC, VALS(acp133_T_return_of_content_vals), 0,
NULL, HFILL }},
{ &hf_acp133_priority,
{ "priority", "acp133.priority",
FT_INT32, BASE_DEC, VALS(acp133_T_priority_vals), 0,
NULL, HFILL }},
{ &hf_acp133_disclosure_of_other_recipients,
{ "disclosure-of-other-recipients", "acp133.disclosure_of_other_recipients",
FT_UINT32, BASE_DEC, VALS(acp133_T_disclosure_of_other_recipients_vals), 0,
NULL, HFILL }},
{ &hf_acp133_implicit_conversion_prohibited,
{ "implicit-conversion-prohibited", "acp133.implicit_conversion_prohibited",
FT_UINT32, BASE_DEC, VALS(acp133_T_implicit_conversion_prohibited_vals), 0,
"T_implicit_conversion_prohibited", HFILL }},
{ &hf_acp133_conversion_with_loss_prohibited,
{ "conversion-with-loss-prohibited", "acp133.conversion_with_loss_prohibited",
FT_UINT32, BASE_DEC, VALS(acp133_T_conversion_with_loss_prohibited_vals), 0,
NULL, HFILL }},
{ &hf_acp133_further_dl_expansion_allowed,
{ "further-dl-expansion-allowed", "acp133.further_dl_expansion_allowed",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_acp133_originator_requested_alternate_recipient_removed,
{ "originator-requested-alternate-recipient-removed", "acp133.originator_requested_alternate_recipient_removed",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_acp133_proof_of_delivery,
{ "proof-of-delivery", "acp133.proof_of_delivery",
FT_INT32, BASE_DEC, VALS(acp133_T_proof_of_delivery_vals), 0,
NULL, HFILL }},
{ &hf_acp133_requested_delivery_method,
{ "requested-delivery-method", "acp133.requested_delivery_method",
FT_UINT32, BASE_DEC, VALS(acp133_T_requested_delivery_method_vals), 0,
NULL, HFILL }},
{ &hf_acp133_unchanged,
{ "unchanged", "acp133.unchanged_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_acp133_removed,
{ "removed", "acp133.removed_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_acp133_replaced,
{ "replaced", "acp133.replaced",
FT_UINT32, BASE_DEC, NULL, 0,
"RequestedDeliveryMethod", HFILL }},
{ &hf_acp133_token_encryption_algorithm_preference,
{ "token-encryption-algorithm-preference", "acp133.token_encryption_algorithm_preference",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AlgorithmInformation", HFILL }},
{ &hf_acp133_token_encryption_algorithm_preference_item,
{ "AlgorithmInformation", "acp133.AlgorithmInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_acp133_token_signature_algorithm_preference,
{ "token-signature-algorithm-preference", "acp133.token_signature_algorithm_preference",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AlgorithmInformation", HFILL }},
{ &hf_acp133_token_signature_algorithm_preference_item,
{ "AlgorithmInformation", "acp133.AlgorithmInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_acp133_originator_certificate_selector,
{ "originator-certificate-selector", "acp133.originator_certificate_selector_element",
FT_NONE, BASE_NONE, NULL, 0,
"CertificateAssertion", HFILL }},
{ &hf_acp133_recipient_certificate_selector,
{ "recipient-certificate-selector", "acp133.recipient_certificate_selector_element",
FT_NONE, BASE_NONE, NULL, 0,
"CertificateAssertion", HFILL }},
{ &hf_acp133_description,
{ "description", "acp133.description",
FT_STRING, BASE_NONE, NULL, 0,
"GeneralString", HFILL }},
{ &hf_acp133_address,
{ "address", "acp133.address_element",
FT_NONE, BASE_NONE, NULL, 0,
"ORAddress", HFILL }},
{ &hf_acp133_capabilities,
{ "capabilities", "acp133.capabilities",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_Capability", HFILL }},
{ &hf_acp133_capabilities_item,
{ "Capability", "acp133.Capability_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_acp133_content_types,
{ "content-types", "acp133.content_types",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_ExtendedContentType", HFILL }},
{ &hf_acp133_content_types_item,
{ "ExtendedContentType", "acp133.ExtendedContentType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_acp133_maximum_content_length,
{ "maximum-content-length", "acp133.maximum_content_length",
FT_UINT32, BASE_DEC, NULL, 0,
"ContentLength", HFILL }},
{ &hf_acp133_encoded_information_types_constraints,
{ "encoded-information-types-constraints", "acp133.encoded_information_types_constraints_element",
FT_NONE, BASE_NONE, NULL, 0,
"EncodedInformationTypesConstraints", HFILL }},
{ &hf_acp133_security_labels,
{ "security-labels", "acp133.security_labels",
FT_UINT32, BASE_DEC, NULL, 0,
"SecurityContext", HFILL }},
{ &hf_acp133_OnSupported_acp127_nn,
{ "acp127-nn", "acp133.acp127-nn",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_acp133_OnSupported_acp127_pn,
{ "acp127-pn", "acp133.acp127-pn",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_acp133_OnSupported_acp127_tn,
{ "acp127-tn", "acp133.acp127-tn",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
#line 68 "../../asn1/acp133/packet-acp133-template.c"
};
static gint *ett[] = {
&ett_acp133,
#line 1 "../../asn1/acp133/packet-acp133-ettarr.c"
&ett_acp133_OnSupported,
&ett_acp133_Addressees,
&ett_acp133_MonthlyUKMs,
&ett_acp133_SEQUENCE_OF_UKMEntry,
&ett_acp133_Remarks,
&ett_acp133_RIParameters,
&ett_acp133_RIParametersDeprecated,
&ett_acp133_UKMEntry,
&ett_acp133_PairwiseTag,
&ett_acp133_MLReceiptPolicy,
&ett_acp133_SEQUENCE_OF_GeneralNames,
&ett_acp133_DLSubmitPermission,
&ett_acp133_DLPolicy,
&ett_acp133_T_requested_delivery_method,
&ett_acp133_SEQUENCE_OF_AlgorithmInformation,
&ett_acp133_AlgorithmInformation,
&ett_acp133_AddressCapabilities,
&ett_acp133_SET_OF_Capability,
&ett_acp133_Capability,
&ett_acp133_SET_OF_ExtendedContentType,
#line 74 "../../asn1/acp133/packet-acp133-template.c"
};
proto_acp133 = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_acp133, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_acp133(void) {
#line 1 "../../asn1/acp133/packet-acp133-dis-tab.c"
register_ber_oid_dissector("2.6.5.2.4", dissect_DLSubmitPermission_PDU, proto_acp133, "id-at-mhs-dl-submit-permissions");
register_ber_oid_dissector("2.6.5.2.13", dissect_DLPolicy_PDU, proto_acp133, "id-at-mhs-dl-policy");
register_ber_oid_dissector("2.6.5.2.16", dissect_AddressCapabilities_PDU, proto_acp133, "id-at-mhs-or-addresses-with-capabilities");
register_ber_oid_dissector("2.6.5.2.19", dissect_Capability_PDU, proto_acp133, "id-at-mhs-deliverable-classes");
register_ber_oid_dissector("2.16.840.1.101.2.1.5.14", dissect_Kmid_PDU, proto_acp133, "id-at-alid");
register_ber_oid_dissector("2.16.840.1.101.2.1.5.20", dissect_MonthlyUKMs_PDU, proto_acp133, "id-at-janUKMs");
register_ber_oid_dissector("2.16.840.1.101.2.1.5.21", dissect_MonthlyUKMs_PDU, proto_acp133, "id-at-febUKMs");
register_ber_oid_dissector("2.16.840.1.101.2.1.5.22", dissect_MonthlyUKMs_PDU, proto_acp133, "id-at-marUKMs");
register_ber_oid_dissector("2.16.840.1.101.2.1.5.23", dissect_MonthlyUKMs_PDU, proto_acp133, "id-at-aprUKMs");
register_ber_oid_dissector("2.16.840.1.101.2.1.5.24", dissect_MonthlyUKMs_PDU, proto_acp133, "id-at-mayUKMs");
register_ber_oid_dissector("2.16.840.1.101.2.1.5.25", dissect_MonthlyUKMs_PDU, proto_acp133, "id-at-junUKMs");
register_ber_oid_dissector("2.16.840.1.101.2.1.5.26", dissect_MonthlyUKMs_PDU, proto_acp133, "id-at-julUKMs");
register_ber_oid_dissector("2.16.840.1.101.2.1.5.27", dissect_MonthlyUKMs_PDU, proto_acp133, "id-at-augUKMs");
register_ber_oid_dissector("2.16.840.1.101.2.1.5.28", dissect_MonthlyUKMs_PDU, proto_acp133, "id-at-sepUKMs");
register_ber_oid_dissector("2.16.840.1.101.2.1.5.29", dissect_MonthlyUKMs_PDU, proto_acp133, "id-at-octUKMs");
register_ber_oid_dissector("2.16.840.1.101.2.1.5.30", dissect_MonthlyUKMs_PDU, proto_acp133, "id-at-novUKMs");
register_ber_oid_dissector("2.16.840.1.101.2.1.5.31", dissect_MonthlyUKMs_PDU, proto_acp133, "id-at-decUKMs");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.46", dissect_Addressees_PDU, proto_acp133, "id-at-actionAddressees");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.47", dissect_Addressees_PDU, proto_acp133, "id-at-additionalAddressees");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.48", dissect_Addressees_PDU, proto_acp133, "id-at-additionalSecondPartyAddressees");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.50", dissect_Addressees_PDU, proto_acp133, "id-at-allowableOriginators");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.52", dissect_Community_PDU, proto_acp133, "id-at-community");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.56", dissect_Classification_PDU, proto_acp133, "id-at-entryClassification");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.59", dissect_Addressees_PDU, proto_acp133, "id-at-infoAddressees");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.67", dissect_Classification_PDU, proto_acp133, "id-at-nameClassification");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.71", dissect_Addressees_PDU, proto_acp133, "id-at-plaAddressees");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.76", dissect_Remarks_PDU, proto_acp133, "id-at-remarks");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.78", dissect_Classification_PDU, proto_acp133, "id-at-rIClassification");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.79", dissect_RIParameters_PDU, proto_acp133, "id-at-rIInfo");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.80", dissect_Addressees_PDU, proto_acp133, "id-at-secondPartyAddressees");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.104", dissect_DistributionCode_PDU, proto_acp133, "id-at-distributionCodeAction");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.105", dissect_DistributionCode_PDU, proto_acp133, "id-at-distributionCodeInfo");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.108", dissect_ACPPreferredDelivery_PDU, proto_acp133, "id-at-aCPPreferredDelivery");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.112", dissect_ALType_PDU, proto_acp133, "id-at-aLType");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.123", dissect_OnSupported_PDU, proto_acp133, "id-at-onSupported");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.135", dissect_MLReceiptPolicy_PDU, proto_acp133, "id-at-aLReceiptPolicy");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.142", dissect_ACPLegacyFormat_PDU, proto_acp133, "id-at-aCPLegacyFormat");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.146", dissect_JPEG_PDU, proto_acp133, "id-at-aCPNetwAccessSchemaEdB");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.147", dissect_JPEG_PDU, proto_acp133, "id-at-aCPNetworkSchemaEdB");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.162", dissect_MaxMessageSize_PDU, proto_acp133, "id-at-maxMessageSize");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.163", dissect_MsgProtocolInfoCapability_PDU, proto_acp133, "id-at-msgProtocolInfoCapability");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.164", dissect_Active_PDU, proto_acp133, "id-at-active");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.165", dissect_EmConCapability_PDU, proto_acp133, "id-at-emConCapability");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.166", dissect_EmConState_PDU, proto_acp133, "id-at-emConState");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.167", dissect_WebAccessCapability_PDU, proto_acp133, "id-at-webAccessCapability");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.168", dissect_DistributionCode_PDU, proto_acp133, "id-at-distributionExemptAction");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.169", dissect_DistributionCode_PDU, proto_acp133, "id-at-distributionExemptInfo");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.170", dissect_DistributionCode_PDU, proto_acp133, "id-at-distributionKeywordAction");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.171", dissect_DistributionCode_PDU, proto_acp133, "id-at-distributionKeywordInfo");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.189", dissect_ACPNoAttachments_PDU, proto_acp133, "id-at-aCPNoAttachments");
#line 90 "../../asn1/acp133/packet-acp133-template.c"
oid_add_from_string("id-oc-mhs-distribution-list","2.6.5.1.0");
oid_add_from_string("id-oc-mhs-message-store","2.6.5.1.1");
oid_add_from_string("id-oc-mhs-message-transfer-agent","2.6.5.1.2");
oid_add_from_string("id-oc-mhs-user","2.6.5.1.3");
oid_add_from_string("id-oc-secure-user","2.16.840.1.101.2.1.4.13");
oid_add_from_string("id-oc-ukms","2.16.840.1.101.2.1.4.16");
oid_add_from_string("id-oc-plaData","2.16.840.1.101.2.2.3.26");
oid_add_from_string("id-oc-cadACP127","2.16.840.1.101.2.2.3.28");
oid_add_from_string("id-oc-mLA","2.16.840.1.101.2.2.3.31");
oid_add_from_string("id-oc-orgACP127","2.16.840.1.101.2.2.3.34");
oid_add_from_string("id-oc-plaCollectiveACP127","2.16.840.1.101.2.2.3.35");
oid_add_from_string("id-oc-routingIndicator","2.16.840.1.101.2.2.3.37");
oid_add_from_string("id-oc-sigintPLA","2.16.840.1.101.2.2.3.38");
oid_add_from_string("id-oc-sIPLA","2.16.840.1.101.2.2.3.39");
oid_add_from_string("id-oc-spotPLA","2.16.840.1.101.2.2.3.40");
oid_add_from_string("id-oc-taskForceACP127","2.16.840.1.101.2.2.3.41");
oid_add_from_string("id-oc-tenantACP127","2.16.840.1.101.2.2.3.42");
oid_add_from_string("id-oc-plaACP127","2.16.840.1.101.2.2.3.47");
oid_add_from_string("id-oc-aliasCommonName","2.16.840.1.101.2.2.3.52");
oid_add_from_string("id-oc-aliasOrganizationalUnit","2.16.840.1.101.2.2.3.53");
oid_add_from_string("id-oc-distributionCodesHandled","2.16.840.1.101.2.2.3.54");
oid_add_from_string("id-oc-distributionCodeDescription","2.16.840.1.101.2.2.3.55");
oid_add_from_string("id-oc-plaUser","2.16.840.1.101.2.2.3.56");
oid_add_from_string("id-oc-addressList","2.16.840.1.101.2.2.3.57");
oid_add_from_string("id-oc-altSpellingACP127","2.16.840.1.101.2.2.3.58");
oid_add_from_string("id-oc-messagingGateway","2.16.840.1.101.2.2.3.59");
oid_add_from_string("id-oc-network","2.16.840.1.101.2.2.3.60");
oid_add_from_string("id-oc-networkInstructions","2.16.840.1.101.2.2.3.61");
oid_add_from_string("id-oc-otherContactInformation","2.16.840.1.101.2.2.3.62");
oid_add_from_string("id-oc-releaseAuthorityPerson","2.16.840.1.101.2.2.3.63");
oid_add_from_string("id-oc-mLAgent","2.16.840.1.101.2.2.3.64");
oid_add_from_string("id-oc-releaseAuthorityPersonA","2.16.840.1.101.2.2.3.65");
oid_add_from_string("id-oc-securePkiUser","2.16.840.1.101.2.2.3.66");
oid_add_from_string("id-oc-dSSCSPLA","2.16.840.1.101.2.2.3.67");
oid_add_from_string("id-oc-aCPNetworkEdB","2.16.840.1.101.2.2.3.68");
oid_add_from_string("id-oc-aCPNetworkInstructionsEdB","2.16.840.1.101.2.2.3.69");
oid_add_from_string("id-oc-aCPAddressList","2.16.840.1.101.2.2.3.70");
oid_add_from_string("id-oc-aCPAliasCommonName","2.16.840.1.101.2.2.3.71");
oid_add_from_string("id-oc-aCPAliasOrganizationalUnit","2.16.840.1.101.2.2.3.72");
oid_add_from_string("id-oc-aCPDevice","2.16.840.1.101.2.2.3.73");
oid_add_from_string("id-oc-aCPDistributionCodeDescription","2.16.840.1.101.2.2.3.74");
oid_add_from_string("id-oc-aCPGroupOfNames","2.16.840.1.101.2.2.3.75");
oid_add_from_string("id-oc-aCPLocality","2.16.840.1.101.2.2.3.76");
oid_add_from_string("id-oc-aCPOrganization","2.16.840.1.101.2.2.3.77");
oid_add_from_string("id-oc-aCPOrganizationalPerson","2.16.840.1.101.2.2.3.78");
oid_add_from_string("id-oc-aCPOrganizationalRole","2.16.840.1.101.2.2.3.79");
oid_add_from_string("id-oc-aCPOrganizationalUnit","2.16.840.1.101.2.2.3.80");
oid_add_from_string("id-oc-aCPDistributionCodesHandled","2.16.840.1.101.2.2.3.81");
oid_add_from_string("id-oc-aCPMhsCapabilitiesInformation","2.16.840.1.101.2.2.3.82");
oid_add_from_string("id-oc-aCPOtherContactInformation","2.16.840.1.101.2.2.3.83");
oid_add_from_string("id-oc-aCPPlaUser","2.16.840.1.101.2.2.3.84");
oid_add_from_string("id-oc-aCPCRLDistributionPoint","2.16.840.1.101.2.2.3.85");
oid_add_from_string("id-oc-aCPSecurePKIUser","2.16.840.1.101.2.2.3.86");
oid_add_from_string("id-oc-aCPAltSpellingACP127","2.16.840.1.101.2.2.3.87");
oid_add_from_string("id-oc-aCPCadACP127","2.16.840.1.101.2.2.3.88");
oid_add_from_string("id-oc-aCPDSSCSPLA","2.16.840.1.101.2.2.3.89");
oid_add_from_string("id-oc-aCPOrgACP127","2.16.840.1.101.2.2.3.90");
oid_add_from_string("id-oc-aCPPLACollectiveACP127","2.16.840.1.101.2.2.3.91");
oid_add_from_string("id-oc-aCPRoutingIndicator","2.16.840.1.101.2.2.3.92");
oid_add_from_string("id-oc-aCPSigIntPLA","2.16.840.1.101.2.2.3.93");
oid_add_from_string("id-oc-aCPSIPLA","2.16.840.1.101.2.2.3.94");
oid_add_from_string("id-oc-aCPSpotPLA","2.16.840.1.101.2.2.3.95");
oid_add_from_string("id-oc-aCPTaskForceACP127","2.16.840.1.101.2.2.3.96");
oid_add_from_string("id-oc-aCPTenantACP127","2.16.840.1.101.2.2.3.97");
oid_add_from_string("id-oc-aCPPlaACP127","2.16.840.1.101.2.2.3.98");
oid_add_from_string("id-oc-aCPPlaData","2.16.840.1.101.2.2.3.99");
oid_add_from_string("id-oc-aCPEntryAdmin","2.16.840.1.101.2.2.3.102");
oid_add_from_string("id-oc-aCPOrganizationalLocation","2.16.840.1.101.2.2.3.103");
oid_add_from_string("id-oc-aCPEntryCharacteristics","2.16.840.1.101.2.2.3.104");
oid_add_from_string("id-oc-aCPPrivilege","2.16.840.1.101.2.2.3.105");
oid_add_from_string("acp120-acp127","2.16.840.1.101.2.2.5.0");
oid_add_from_string("acp120-janap128","2.16.840.1.101.2.2.5.1");
oid_add_from_string("acp120-mhs","2.16.840.1.101.2.2.5.2");
oid_add_from_string("acp120-mmhs","2.16.840.1.101.2.2.5.3");
oid_add_from_string("acp120-rfc822","2.16.840.1.101.2.2.5.4");
oid_add_from_string("boundaryMTA","2.16.840.1.101.2.2.5.5");
oid_add_from_string("mmhs-mhs","2.16.840.1.101.2.2.5.6");
oid_add_from_string("mmhs-rfc822","2.16.840.1.101.2.2.5.7");
oid_add_from_string("mta-acp127","2.16.840.1.101.2.2.5.8");
}
