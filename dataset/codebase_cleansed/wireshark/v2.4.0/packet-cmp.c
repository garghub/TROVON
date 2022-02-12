int
dissect_cmp_CMPCertificate(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
CMPCertificate_choice, hf_index, ett_cmp_CMPCertificate,
NULL);
return offset;
}
static int
dissect_cmp_T_pvno(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_cmp_GeneralizedTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_GeneralizedTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_cmp_OCTET_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_cmp_UTF8String(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_UTF8String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_cmp_PKIFreeText(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
PKIFreeText_sequence_of, hf_index, ett_cmp_PKIFreeText);
return offset;
}
static int
dissect_cmp_T_infoType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_cmp_type_oid, &actx->external.direct_reference);
return offset;
}
static int
dissect_cmp_T_infoValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 88 "./asn1/cmp/cmp.cnf"
offset=call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
int
dissect_cmp_InfoTypeAndValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
InfoTypeAndValue_sequence, hf_index, ett_cmp_InfoTypeAndValue);
return offset;
}
static int
dissect_cmp_SEQUENCE_SIZE_1_MAX_OF_InfoTypeAndValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_MAX_OF_InfoTypeAndValue_sequence_of, hf_index, ett_cmp_SEQUENCE_SIZE_1_MAX_OF_InfoTypeAndValue);
return offset;
}
int
dissect_cmp_PKIHeader(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PKIHeader_sequence, hf_index, ett_cmp_PKIHeader);
return offset;
}
static int
dissect_cmp_SEQUENCE_SIZE_1_MAX_OF_CMPCertificate(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_MAX_OF_CMPCertificate_sequence_of, hf_index, ett_cmp_SEQUENCE_SIZE_1_MAX_OF_CMPCertificate);
return offset;
}
static int
dissect_cmp_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_cmp_PKIStatus(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 104 "./asn1/cmp/cmp.cnf"
guint32 value;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&value);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " Status=%s", val_to_str(value, cmp_PKIStatus_vals, "unknown"));
return offset;
}
int
dissect_cmp_PKIFailureInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
PKIFailureInfo_bits, hf_index, ett_cmp_PKIFailureInfo,
NULL);
return offset;
}
int
dissect_cmp_PKIStatusInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PKIStatusInfo_sequence, hf_index, ett_cmp_PKIStatusInfo);
return offset;
}
int
dissect_cmp_CertOrEncCert(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
CertOrEncCert_choice, hf_index, ett_cmp_CertOrEncCert,
NULL);
return offset;
}
int
dissect_cmp_CertifiedKeyPair(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CertifiedKeyPair_sequence, hf_index, ett_cmp_CertifiedKeyPair);
return offset;
}
int
dissect_cmp_CertResponse(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CertResponse_sequence, hf_index, ett_cmp_CertResponse);
return offset;
}
static int
dissect_cmp_SEQUENCE_OF_CertResponse(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_CertResponse_sequence_of, hf_index, ett_cmp_SEQUENCE_OF_CertResponse);
return offset;
}
int
dissect_cmp_CertRepMessage(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CertRepMessage_sequence, hf_index, ett_cmp_CertRepMessage);
return offset;
}
static int
dissect_cmp_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
int
dissect_cmp_Challenge(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Challenge_sequence, hf_index, ett_cmp_Challenge);
return offset;
}
static int
dissect_cmp_POPODecKeyChallContent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
POPODecKeyChallContent_sequence_of, hf_index, ett_cmp_POPODecKeyChallContent);
return offset;
}
int
dissect_cmp_POPODecKeyRespContent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
POPODecKeyRespContent_sequence_of, hf_index, ett_cmp_POPODecKeyRespContent);
return offset;
}
static int
dissect_cmp_SEQUENCE_SIZE_1_MAX_OF_CertifiedKeyPair(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_MAX_OF_CertifiedKeyPair_sequence_of, hf_index, ett_cmp_SEQUENCE_SIZE_1_MAX_OF_CertifiedKeyPair);
return offset;
}
int
dissect_cmp_KeyRecRepContent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
KeyRecRepContent_sequence, hf_index, ett_cmp_KeyRecRepContent);
return offset;
}
int
dissect_cmp_RevDetails(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RevDetails_sequence, hf_index, ett_cmp_RevDetails);
return offset;
}
int
dissect_cmp_RevReqContent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
RevReqContent_sequence_of, hf_index, ett_cmp_RevReqContent);
return offset;
}
static int
dissect_cmp_SEQUENCE_SIZE_1_MAX_OF_PKIStatusInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_MAX_OF_PKIStatusInfo_sequence_of, hf_index, ett_cmp_SEQUENCE_SIZE_1_MAX_OF_PKIStatusInfo);
return offset;
}
static int
dissect_cmp_SEQUENCE_SIZE_1_MAX_OF_CertId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_MAX_OF_CertId_sequence_of, hf_index, ett_cmp_SEQUENCE_SIZE_1_MAX_OF_CertId);
return offset;
}
static int
dissect_cmp_SEQUENCE_SIZE_1_MAX_OF_CertificateList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_MAX_OF_CertificateList_sequence_of, hf_index, ett_cmp_SEQUENCE_SIZE_1_MAX_OF_CertificateList);
return offset;
}
int
dissect_cmp_RevRepContent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RevRepContent_sequence, hf_index, ett_cmp_RevRepContent);
return offset;
}
int
dissect_cmp_CAKeyUpdAnnContent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CAKeyUpdAnnContent_sequence, hf_index, ett_cmp_CAKeyUpdAnnContent);
return offset;
}
int
dissect_cmp_CertAnnContent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_cmp_CMPCertificate(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
int
dissect_cmp_RevAnnContent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RevAnnContent_sequence, hf_index, ett_cmp_RevAnnContent);
return offset;
}
int
dissect_cmp_CRLAnnContent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
CRLAnnContent_sequence_of, hf_index, ett_cmp_CRLAnnContent);
return offset;
}
int
dissect_cmp_PKIConfirmContent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
int
dissect_cmp_PKIMessages(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
PKIMessages_sequence_of, hf_index, ett_cmp_PKIMessages);
return offset;
}
int
dissect_cmp_NestedMessageContent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_cmp_PKIMessages(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
int
dissect_cmp_GenMsgContent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
GenMsgContent_sequence_of, hf_index, ett_cmp_GenMsgContent);
return offset;
}
static int
dissect_cmp_GenRepContent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
GenRepContent_sequence_of, hf_index, ett_cmp_GenRepContent);
return offset;
}
int
dissect_cmp_ErrorMsgContent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ErrorMsgContent_sequence, hf_index, ett_cmp_ErrorMsgContent);
return offset;
}
int
dissect_cmp_CertStatus(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CertStatus_sequence, hf_index, ett_cmp_CertStatus);
return offset;
}
int
dissect_cmp_CertConfirmContent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
CertConfirmContent_sequence_of, hf_index, ett_cmp_CertConfirmContent);
return offset;
}
static int
dissect_cmp_PollReqContent_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PollReqContent_item_sequence, hf_index, ett_cmp_PollReqContent_item);
return offset;
}
int
dissect_cmp_PollReqContent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
PollReqContent_sequence_of, hf_index, ett_cmp_PollReqContent);
return offset;
}
static int
dissect_cmp_PollRepContent_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PollRepContent_item_sequence, hf_index, ett_cmp_PollRepContent_item);
return offset;
}
int
dissect_cmp_PollRepContent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
PollRepContent_sequence_of, hf_index, ett_cmp_PollRepContent);
return offset;
}
int
dissect_cmp_PKIBody(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 94 "./asn1/cmp/cmp.cnf"
gint branch_taken;
offset = dissect_ber_choice(actx, tree, tvb, offset,
PKIBody_choice, hf_index, ett_cmp_PKIBody,
&branch_taken);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " Body=%s", val_to_str(branch_taken, cmp_PKIBody_vals, "unknown"));
return offset;
}
int
dissect_cmp_PKIProtection(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
int
dissect_cmp_PKIMessage(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PKIMessage_sequence, hf_index, ett_cmp_PKIMessage);
return offset;
}
int
dissect_cmp_ProtectedPart(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ProtectedPart_sequence, hf_index, ett_cmp_ProtectedPart);
return offset;
}
int
dissect_cmp_PBMParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PBMParameter_sequence, hf_index, ett_cmp_PBMParameter);
return offset;
}
int
dissect_cmp_DHBMParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DHBMParameter_sequence, hf_index, ett_cmp_DHBMParameter);
return offset;
}
int
dissect_cmp_OOBCert(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_cmp_CMPCertificate(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_cmp_BIT_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
int
dissect_cmp_OOBCertHash(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
OOBCertHash_sequence, hf_index, ett_cmp_OOBCertHash);
return offset;
}
static int
dissect_cmp_CAProtEncCertValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_cmp_CMPCertificate(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_cmp_SignKeyPairTypesValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SignKeyPairTypesValue_sequence_of, hf_index, ett_cmp_SignKeyPairTypesValue);
return offset;
}
static int
dissect_cmp_EncKeyPairTypesValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
EncKeyPairTypesValue_sequence_of, hf_index, ett_cmp_EncKeyPairTypesValue);
return offset;
}
static int
dissect_cmp_PreferredSymmAlgValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_pkix1explicit_AlgorithmIdentifier(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_cmp_CAKeyUpdateInfoValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_cmp_CAKeyUpdAnnContent(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_cmp_CurrentCRLValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_pkix1explicit_CertificateList(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_cmp_OBJECT_IDENTIFIER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_cmp_UnsupportedOIDsValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
UnsupportedOIDsValue_sequence_of, hf_index, ett_cmp_UnsupportedOIDsValue);
return offset;
}
static int
dissect_cmp_KeyPairParamReqValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_cmp_KeyPairParamRepValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_pkix1explicit_AlgorithmIdentifier(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_cmp_RevPassphraseValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_crmf_EncryptedValue(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_cmp_ImplicitConfirmValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_cmp_ConfirmWaitTimeValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_GeneralizedTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_cmp_OrigPKIMessageValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_cmp_PKIMessages(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_cmp_SuppLangTagsValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SuppLangTagsValue_sequence_of, hf_index, ett_cmp_SuppLangTagsValue);
return offset;
}
static int dissect_PBMParameter_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_cmp_PBMParameter(FALSE, tvb, offset, &asn1_ctx, tree, hf_cmp_PBMParameter_PDU);
return offset;
}
static int dissect_DHBMParameter_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_cmp_DHBMParameter(FALSE, tvb, offset, &asn1_ctx, tree, hf_cmp_DHBMParameter_PDU);
return offset;
}
static int dissect_CAProtEncCertValue_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_cmp_CAProtEncCertValue(FALSE, tvb, offset, &asn1_ctx, tree, hf_cmp_CAProtEncCertValue_PDU);
return offset;
}
static int dissect_SignKeyPairTypesValue_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_cmp_SignKeyPairTypesValue(FALSE, tvb, offset, &asn1_ctx, tree, hf_cmp_SignKeyPairTypesValue_PDU);
return offset;
}
static int dissect_EncKeyPairTypesValue_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_cmp_EncKeyPairTypesValue(FALSE, tvb, offset, &asn1_ctx, tree, hf_cmp_EncKeyPairTypesValue_PDU);
return offset;
}
static int dissect_PreferredSymmAlgValue_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_cmp_PreferredSymmAlgValue(FALSE, tvb, offset, &asn1_ctx, tree, hf_cmp_PreferredSymmAlgValue_PDU);
return offset;
}
static int dissect_CAKeyUpdateInfoValue_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_cmp_CAKeyUpdateInfoValue(FALSE, tvb, offset, &asn1_ctx, tree, hf_cmp_CAKeyUpdateInfoValue_PDU);
return offset;
}
static int dissect_CurrentCRLValue_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_cmp_CurrentCRLValue(FALSE, tvb, offset, &asn1_ctx, tree, hf_cmp_CurrentCRLValue_PDU);
return offset;
}
static int dissect_UnsupportedOIDsValue_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_cmp_UnsupportedOIDsValue(FALSE, tvb, offset, &asn1_ctx, tree, hf_cmp_UnsupportedOIDsValue_PDU);
return offset;
}
static int dissect_KeyPairParamReqValue_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_cmp_KeyPairParamReqValue(FALSE, tvb, offset, &asn1_ctx, tree, hf_cmp_KeyPairParamReqValue_PDU);
return offset;
}
static int dissect_KeyPairParamRepValue_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_cmp_KeyPairParamRepValue(FALSE, tvb, offset, &asn1_ctx, tree, hf_cmp_KeyPairParamRepValue_PDU);
return offset;
}
static int dissect_RevPassphraseValue_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_cmp_RevPassphraseValue(FALSE, tvb, offset, &asn1_ctx, tree, hf_cmp_RevPassphraseValue_PDU);
return offset;
}
static int dissect_ImplicitConfirmValue_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_cmp_ImplicitConfirmValue(FALSE, tvb, offset, &asn1_ctx, tree, hf_cmp_ImplicitConfirmValue_PDU);
return offset;
}
static int dissect_ConfirmWaitTimeValue_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_cmp_ConfirmWaitTimeValue(FALSE, tvb, offset, &asn1_ctx, tree, hf_cmp_ConfirmWaitTimeValue_PDU);
return offset;
}
static int dissect_OrigPKIMessageValue_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_cmp_OrigPKIMessageValue(FALSE, tvb, offset, &asn1_ctx, tree, hf_cmp_OrigPKIMessageValue_PDU);
return offset;
}
static int dissect_SuppLangTagsValue_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_cmp_SuppLangTagsValue(FALSE, tvb, offset, &asn1_ctx, tree, hf_cmp_SuppLangTagsValue_PDU);
return offset;
}
static int
dissect_cmp_pdu(tvbuff_t *tvb, proto_tree *tree, asn1_ctx_t *actx)
{
return dissect_cmp_PKIMessage(FALSE, tvb, 0, actx,tree, -1);
}
static int dissect_cmp_tcp_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
tvbuff_t *next_tvb;
guint32 pdu_len;
guint8 pdu_type;
nstime_t ts;
proto_item *item=NULL;
proto_item *ti=NULL;
proto_tree *tree=NULL;
proto_tree *tcptrans_tree=NULL;
asn1_ctx_t asn1_ctx;
int offset=0;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CMP");
col_set_str(pinfo->cinfo, COL_INFO, "PKIXCMP");
if(parent_tree){
item=proto_tree_add_item(parent_tree, proto_cmp, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_cmp);
}
pdu_len=tvb_get_ntohl(tvb, 0);
pdu_type=tvb_get_guint8(tvb, 4);
if (pdu_type < 10) {
ti = proto_tree_add_item(tree, proto_cmp, tvb, offset, 5, ENC_NA);
tcptrans_tree = proto_item_add_subtree(ti, ett_cmp);
proto_tree_add_item(tree, hf_cmp_tcptrans_len, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cmp_tcptrans_type, tvb, offset++, 1, ENC_BIG_ENDIAN);
} else {
tcptrans_tree = proto_tree_add_subtree(tree, tvb, offset, 7, ett_cmp, NULL, "TCP transport");
pdu_type=tvb_get_guint8(tvb, 6);
proto_tree_add_item(tcptrans_tree, hf_cmp_tcptrans_len, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tcptrans_tree, hf_cmp_tcptrans10_version, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tcptrans_tree, hf_cmp_tcptrans10_flags, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tcptrans_tree, hf_cmp_tcptrans_type, tvb, offset++, 1, ENC_BIG_ENDIAN);
}
col_add_str (pinfo->cinfo, COL_INFO, val_to_str (pdu_type, cmp_pdu_types, "0x%x"));
switch(pdu_type){
case CMP_TYPE_PKIMSG:
next_tvb = tvb_new_subset_length_caplen(tvb, offset, tvb_reported_length_remaining(tvb, offset), pdu_len);
dissect_cmp_pdu(next_tvb, tree, &asn1_ctx);
offset += tvb_reported_length_remaining(tvb, offset);
break;
case CMP_TYPE_POLLREP:
proto_tree_add_item(tcptrans_tree, hf_cmp_tcptrans_poll_ref, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
ts.secs = tvb_get_ntohl(tvb, 4);
ts.nsecs = 0;
proto_tree_add_time(tcptrans_tree, hf_cmp_tcptrans_ttcb, tvb, offset, 4, &ts);
offset += 4;
break;
case CMP_TYPE_POLLREQ:
proto_tree_add_item(tcptrans_tree, hf_cmp_tcptrans_poll_ref, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case CMP_TYPE_NEGPOLLREP:
break;
case CMP_TYPE_PARTIALMSGREP:
proto_tree_add_item(tcptrans_tree, hf_cmp_tcptrans_next_poll_ref, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
ts.secs = tvb_get_ntohl(tvb, 4);
ts.nsecs = 0;
proto_tree_add_time(tcptrans_tree, hf_cmp_tcptrans_ttcb, tvb, offset, 4, &ts);
offset += 4;
next_tvb = tvb_new_subset_length_caplen(tvb, offset, tvb_reported_length_remaining(tvb, offset), pdu_len);
dissect_cmp_pdu(next_tvb, tree, &asn1_ctx);
offset += tvb_reported_length_remaining(tvb, offset);
break;
case CMP_TYPE_FINALMSGREP:
next_tvb = tvb_new_subset_length_caplen(tvb, offset, tvb_reported_length_remaining(tvb, offset), pdu_len);
dissect_cmp_pdu(next_tvb, tree, &asn1_ctx);
offset += tvb_reported_length_remaining(tvb, offset);
break;
case CMP_TYPE_ERRORMSGREP:
break;
}
return offset;
}
static guint get_cmp_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb,
int offset, void *data _U_)
{
guint32 plen;
plen = tvb_get_ntohl(tvb, offset);
return plen+4;
}
static int
dissect_cmp_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data)
{
guint32 pdu_len;
guint8 pdu_type;
int offset=4;
if (!tvb_bytes_exist(tvb, 0, 5)) {
return 0;
}
pdu_len=tvb_get_ntohl(tvb, 0);
pdu_type=tvb_get_guint8(tvb, 4);
if(pdu_type == 10) {
pdu_type = tvb_get_guint8(tvb, 7);
offset = 7;
if((pdu_len<=2)||(pdu_len>10000)){
return 0;
}
} else {
if(pdu_type>6){
return 0;
}
if((pdu_len<=0)||(pdu_len>10000)){
return 0;
}
}
if((pdu_type==0)&&(pdu_len<3)){
return 0;
}
tcp_dissect_pdus(tvb, pinfo, parent_tree, cmp_desegment, offset, get_cmp_pdu_len,
dissect_cmp_tcp_pdu, data);
return tvb_captured_length(tvb);
}
static int
dissect_cmp_http(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CMP");
col_set_str(pinfo->cinfo, COL_INFO, "PKIXCMP");
if(parent_tree){
item=proto_tree_add_item(parent_tree, proto_cmp, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_cmp);
}
return dissect_cmp_pdu(tvb, tree, &asn1_ctx);
}
void proto_register_cmp(void) {
static hf_register_info hf[] = {
{ &hf_cmp_type_oid,
{ "InfoType", "cmp.type.oid",
FT_STRING, BASE_NONE, NULL, 0,
"Type of InfoTypeAndValue", HFILL }},
{ &hf_cmp_tcptrans_len,
{ "Length", "cmp.tcptrans.length",
FT_UINT32, BASE_DEC, NULL, 0,
"TCP transport Length of PDU in bytes", HFILL }},
{ &hf_cmp_tcptrans_type,
{ "Type", "cmp.tcptrans.type",
FT_UINT8, BASE_DEC, VALS(cmp_pdu_types), 0,
"TCP transport PDU Type", HFILL }},
{ &hf_cmp_tcptrans_poll_ref,
{ "Polling Reference", "cmp.tcptrans.poll_ref",
FT_UINT32, BASE_HEX, NULL, 0,
"TCP transport Polling Reference", HFILL }},
{ &hf_cmp_tcptrans_next_poll_ref,
{ "Next Polling Reference", "cmp.tcptrans.next_poll_ref",
FT_UINT32, BASE_HEX, NULL, 0,
"TCP transport Next Polling Reference", HFILL }},
{ &hf_cmp_tcptrans_ttcb,
{ "Time to check Back", "cmp.tcptrans.ttcb",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0,
"TCP transport Time to check Back", HFILL }},
{ &hf_cmp_tcptrans10_version,
{ "Version", "cmp.tcptrans10.version",
FT_UINT8, BASE_DEC, NULL, 0,
"TCP transport version", HFILL }},
{ &hf_cmp_tcptrans10_flags,
{ "Flags", "cmp.tcptrans10.flags",
FT_UINT8, BASE_DEC, NULL, 0,
"TCP transport flags", HFILL }},
#line 1 "./asn1/cmp/packet-cmp-hfarr.c"
{ &hf_cmp_PBMParameter_PDU,
{ "PBMParameter", "cmp.PBMParameter_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_DHBMParameter_PDU,
{ "DHBMParameter", "cmp.DHBMParameter_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_CAProtEncCertValue_PDU,
{ "CAProtEncCertValue", "cmp.CAProtEncCertValue",
FT_UINT32, BASE_DEC, VALS(cmp_CMPCertificate_vals), 0,
NULL, HFILL }},
{ &hf_cmp_SignKeyPairTypesValue_PDU,
{ "SignKeyPairTypesValue", "cmp.SignKeyPairTypesValue",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_EncKeyPairTypesValue_PDU,
{ "EncKeyPairTypesValue", "cmp.EncKeyPairTypesValue",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_PreferredSymmAlgValue_PDU,
{ "PreferredSymmAlgValue", "cmp.PreferredSymmAlgValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_CAKeyUpdateInfoValue_PDU,
{ "CAKeyUpdateInfoValue", "cmp.CAKeyUpdateInfoValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_CurrentCRLValue_PDU,
{ "CurrentCRLValue", "cmp.CurrentCRLValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_UnsupportedOIDsValue_PDU,
{ "UnsupportedOIDsValue", "cmp.UnsupportedOIDsValue",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_KeyPairParamReqValue_PDU,
{ "KeyPairParamReqValue", "cmp.KeyPairParamReqValue",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_KeyPairParamRepValue_PDU,
{ "KeyPairParamRepValue", "cmp.KeyPairParamRepValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_RevPassphraseValue_PDU,
{ "RevPassphraseValue", "cmp.RevPassphraseValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_ImplicitConfirmValue_PDU,
{ "ImplicitConfirmValue", "cmp.ImplicitConfirmValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_ConfirmWaitTimeValue_PDU,
{ "ConfirmWaitTimeValue", "cmp.ConfirmWaitTimeValue",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_OrigPKIMessageValue_PDU,
{ "OrigPKIMessageValue", "cmp.OrigPKIMessageValue",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_SuppLangTagsValue_PDU,
{ "SuppLangTagsValue", "cmp.SuppLangTagsValue",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_x509v3PKCert,
{ "x509v3PKCert", "cmp.x509v3PKCert_element",
FT_NONE, BASE_NONE, NULL, 0,
"Certificate", HFILL }},
{ &hf_cmp_header,
{ "header", "cmp.header_element",
FT_NONE, BASE_NONE, NULL, 0,
"PKIHeader", HFILL }},
{ &hf_cmp_body,
{ "body", "cmp.body",
FT_UINT32, BASE_DEC, VALS(cmp_PKIBody_vals), 0,
"PKIBody", HFILL }},
{ &hf_cmp_protection,
{ "protection", "cmp.protection",
FT_BYTES, BASE_NONE, NULL, 0,
"PKIProtection", HFILL }},
{ &hf_cmp_extraCerts,
{ "extraCerts", "cmp.extraCerts",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_CMPCertificate", HFILL }},
{ &hf_cmp_extraCerts_item,
{ "CMPCertificate", "cmp.CMPCertificate",
FT_UINT32, BASE_DEC, VALS(cmp_CMPCertificate_vals), 0,
NULL, HFILL }},
{ &hf_cmp_PKIMessages_item,
{ "PKIMessage", "cmp.PKIMessage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_pvno,
{ "pvno", "cmp.pvno",
FT_INT32, BASE_DEC, VALS(cmp_T_pvno_vals), 0,
NULL, HFILL }},
{ &hf_cmp_sender,
{ "sender", "cmp.sender",
FT_UINT32, BASE_DEC, NULL, 0,
"GeneralName", HFILL }},
{ &hf_cmp_recipient,
{ "recipient", "cmp.recipient",
FT_UINT32, BASE_DEC, NULL, 0,
"GeneralName", HFILL }},
{ &hf_cmp_messageTime,
{ "messageTime", "cmp.messageTime",
FT_STRING, BASE_NONE, NULL, 0,
"GeneralizedTime", HFILL }},
{ &hf_cmp_protectionAlg,
{ "protectionAlg", "cmp.protectionAlg_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_cmp_senderKID,
{ "senderKID", "cmp.senderKID",
FT_BYTES, BASE_NONE, NULL, 0,
"KeyIdentifier", HFILL }},
{ &hf_cmp_recipKID,
{ "recipKID", "cmp.recipKID",
FT_BYTES, BASE_NONE, NULL, 0,
"KeyIdentifier", HFILL }},
{ &hf_cmp_transactionID,
{ "transactionID", "cmp.transactionID",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_cmp_senderNonce,
{ "senderNonce", "cmp.senderNonce",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_cmp_recipNonce,
{ "recipNonce", "cmp.recipNonce",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_cmp_freeText,
{ "freeText", "cmp.freeText",
FT_UINT32, BASE_DEC, NULL, 0,
"PKIFreeText", HFILL }},
{ &hf_cmp_generalInfo,
{ "generalInfo", "cmp.generalInfo",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_InfoTypeAndValue", HFILL }},
{ &hf_cmp_generalInfo_item,
{ "InfoTypeAndValue", "cmp.InfoTypeAndValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_PKIFreeText_item,
{ "PKIFreeText item", "cmp.PKIFreeText_item",
FT_STRING, BASE_NONE, NULL, 0,
"UTF8String", HFILL }},
{ &hf_cmp_ir,
{ "ir", "cmp.ir",
FT_UINT32, BASE_DEC, NULL, 0,
"CertReqMessages", HFILL }},
{ &hf_cmp_ip,
{ "ip", "cmp.ip_element",
FT_NONE, BASE_NONE, NULL, 0,
"CertRepMessage", HFILL }},
{ &hf_cmp_cr,
{ "cr", "cmp.cr",
FT_UINT32, BASE_DEC, NULL, 0,
"CertReqMessages", HFILL }},
{ &hf_cmp_cp,
{ "cp", "cmp.cp_element",
FT_NONE, BASE_NONE, NULL, 0,
"CertRepMessage", HFILL }},
{ &hf_cmp_p10cr,
{ "p10cr", "cmp.p10cr_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_popdecc,
{ "popdecc", "cmp.popdecc",
FT_UINT32, BASE_DEC, NULL, 0,
"POPODecKeyChallContent", HFILL }},
{ &hf_cmp_popdecr,
{ "popdecr", "cmp.popdecr",
FT_UINT32, BASE_DEC, NULL, 0,
"POPODecKeyRespContent", HFILL }},
{ &hf_cmp_kur,
{ "kur", "cmp.kur",
FT_UINT32, BASE_DEC, NULL, 0,
"CertReqMessages", HFILL }},
{ &hf_cmp_kup,
{ "kup", "cmp.kup_element",
FT_NONE, BASE_NONE, NULL, 0,
"CertRepMessage", HFILL }},
{ &hf_cmp_krr,
{ "krr", "cmp.krr",
FT_UINT32, BASE_DEC, NULL, 0,
"CertReqMessages", HFILL }},
{ &hf_cmp_krp,
{ "krp", "cmp.krp_element",
FT_NONE, BASE_NONE, NULL, 0,
"KeyRecRepContent", HFILL }},
{ &hf_cmp_rr,
{ "rr", "cmp.rr",
FT_UINT32, BASE_DEC, NULL, 0,
"RevReqContent", HFILL }},
{ &hf_cmp_rp,
{ "rp", "cmp.rp_element",
FT_NONE, BASE_NONE, NULL, 0,
"RevRepContent", HFILL }},
{ &hf_cmp_ccr,
{ "ccr", "cmp.ccr",
FT_UINT32, BASE_DEC, NULL, 0,
"CertReqMessages", HFILL }},
{ &hf_cmp_ccp,
{ "ccp", "cmp.ccp_element",
FT_NONE, BASE_NONE, NULL, 0,
"CertRepMessage", HFILL }},
{ &hf_cmp_ckuann,
{ "ckuann", "cmp.ckuann_element",
FT_NONE, BASE_NONE, NULL, 0,
"CAKeyUpdAnnContent", HFILL }},
{ &hf_cmp_cann,
{ "cann", "cmp.cann",
FT_UINT32, BASE_DEC, VALS(cmp_CMPCertificate_vals), 0,
"CertAnnContent", HFILL }},
{ &hf_cmp_rann,
{ "rann", "cmp.rann_element",
FT_NONE, BASE_NONE, NULL, 0,
"RevAnnContent", HFILL }},
{ &hf_cmp_crlann,
{ "crlann", "cmp.crlann",
FT_UINT32, BASE_DEC, NULL, 0,
"CRLAnnContent", HFILL }},
{ &hf_cmp_pkiconf,
{ "pkiconf", "cmp.pkiconf_element",
FT_NONE, BASE_NONE, NULL, 0,
"PKIConfirmContent", HFILL }},
{ &hf_cmp_nested,
{ "nested", "cmp.nested",
FT_UINT32, BASE_DEC, NULL, 0,
"NestedMessageContent", HFILL }},
{ &hf_cmp_genm,
{ "genm", "cmp.genm",
FT_UINT32, BASE_DEC, NULL, 0,
"GenMsgContent", HFILL }},
{ &hf_cmp_genp,
{ "genp", "cmp.genp",
FT_UINT32, BASE_DEC, NULL, 0,
"GenRepContent", HFILL }},
{ &hf_cmp_error,
{ "error", "cmp.error_element",
FT_NONE, BASE_NONE, NULL, 0,
"ErrorMsgContent", HFILL }},
{ &hf_cmp_certConf,
{ "certConf", "cmp.certConf",
FT_UINT32, BASE_DEC, NULL, 0,
"CertConfirmContent", HFILL }},
{ &hf_cmp_pollReq,
{ "pollReq", "cmp.pollReq",
FT_UINT32, BASE_DEC, NULL, 0,
"PollReqContent", HFILL }},
{ &hf_cmp_pollRep,
{ "pollRep", "cmp.pollRep",
FT_UINT32, BASE_DEC, NULL, 0,
"PollRepContent", HFILL }},
{ &hf_cmp_salt,
{ "salt", "cmp.salt",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_cmp_owf,
{ "owf", "cmp.owf_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_cmp_iterationCount,
{ "iterationCount", "cmp.iterationCount",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_cmp_mac,
{ "mac", "cmp.mac_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_cmp_pkistatus,
{ "status", "cmp.status",
FT_INT32, BASE_DEC, VALS(cmp_PKIStatus_vals), 0,
"PKIStatus", HFILL }},
{ &hf_cmp_statusString,
{ "statusString", "cmp.statusString",
FT_UINT32, BASE_DEC, NULL, 0,
"PKIFreeText", HFILL }},
{ &hf_cmp_failInfo,
{ "failInfo", "cmp.failInfo",
FT_BYTES, BASE_NONE, NULL, 0,
"PKIFailureInfo", HFILL }},
{ &hf_cmp_hashAlg,
{ "hashAlg", "cmp.hashAlg_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_cmp_certId,
{ "certId", "cmp.certId_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_hashVal,
{ "hashVal", "cmp.hashVal",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_cmp_POPODecKeyChallContent_item,
{ "Challenge", "cmp.Challenge_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_witness,
{ "witness", "cmp.witness",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_cmp_challenge,
{ "challenge", "cmp.challenge",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_cmp_POPODecKeyRespContent_item,
{ "POPODecKeyRespContent item", "cmp.POPODecKeyRespContent_item",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_cmp_caPubs,
{ "caPubs", "cmp.caPubs",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_CMPCertificate", HFILL }},
{ &hf_cmp_caPubs_item,
{ "CMPCertificate", "cmp.CMPCertificate",
FT_UINT32, BASE_DEC, VALS(cmp_CMPCertificate_vals), 0,
NULL, HFILL }},
{ &hf_cmp_response,
{ "response", "cmp.response",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_CertResponse", HFILL }},
{ &hf_cmp_response_item,
{ "CertResponse", "cmp.CertResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_certReqId,
{ "certReqId", "cmp.certReqId",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_cmp_pkistatusinf,
{ "status", "cmp.status_element",
FT_NONE, BASE_NONE, NULL, 0,
"PKIStatusInfo", HFILL }},
{ &hf_cmp_certifiedKeyPair,
{ "certifiedKeyPair", "cmp.certifiedKeyPair_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_rspInfo,
{ "rspInfo", "cmp.rspInfo",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_cmp_certOrEncCert,
{ "certOrEncCert", "cmp.certOrEncCert",
FT_UINT32, BASE_DEC, VALS(cmp_CertOrEncCert_vals), 0,
NULL, HFILL }},
{ &hf_cmp_privateKey,
{ "privateKey", "cmp.privateKey_element",
FT_NONE, BASE_NONE, NULL, 0,
"EncryptedValue", HFILL }},
{ &hf_cmp_publicationInfo,
{ "publicationInfo", "cmp.publicationInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
"PKIPublicationInfo", HFILL }},
{ &hf_cmp_certificate,
{ "certificate", "cmp.certificate",
FT_UINT32, BASE_DEC, VALS(cmp_CMPCertificate_vals), 0,
"CMPCertificate", HFILL }},
{ &hf_cmp_encryptedCert,
{ "encryptedCert", "cmp.encryptedCert_element",
FT_NONE, BASE_NONE, NULL, 0,
"EncryptedValue", HFILL }},
{ &hf_cmp_newSigCert,
{ "newSigCert", "cmp.newSigCert",
FT_UINT32, BASE_DEC, VALS(cmp_CMPCertificate_vals), 0,
"CMPCertificate", HFILL }},
{ &hf_cmp_caCerts,
{ "caCerts", "cmp.caCerts",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_CMPCertificate", HFILL }},
{ &hf_cmp_caCerts_item,
{ "CMPCertificate", "cmp.CMPCertificate",
FT_UINT32, BASE_DEC, VALS(cmp_CMPCertificate_vals), 0,
NULL, HFILL }},
{ &hf_cmp_keyPairHist,
{ "keyPairHist", "cmp.keyPairHist",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_CertifiedKeyPair", HFILL }},
{ &hf_cmp_keyPairHist_item,
{ "CertifiedKeyPair", "cmp.CertifiedKeyPair_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_RevReqContent_item,
{ "RevDetails", "cmp.RevDetails_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_certDetails,
{ "certDetails", "cmp.certDetails_element",
FT_NONE, BASE_NONE, NULL, 0,
"CertTemplate", HFILL }},
{ &hf_cmp_crlEntryDetails,
{ "crlEntryDetails", "cmp.crlEntryDetails",
FT_UINT32, BASE_DEC, NULL, 0,
"Extensions", HFILL }},
{ &hf_cmp_rvrpcnt_status,
{ "status", "cmp.status",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_PKIStatusInfo", HFILL }},
{ &hf_cmp_rvrpcnt_status_item,
{ "PKIStatusInfo", "cmp.PKIStatusInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_revCerts,
{ "revCerts", "cmp.revCerts",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_CertId", HFILL }},
{ &hf_cmp_revCerts_item,
{ "CertId", "cmp.CertId_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_crls,
{ "crls", "cmp.crls",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_CertificateList", HFILL }},
{ &hf_cmp_crls_item,
{ "CertificateList", "cmp.CertificateList_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_oldWithNew,
{ "oldWithNew", "cmp.oldWithNew",
FT_UINT32, BASE_DEC, VALS(cmp_CMPCertificate_vals), 0,
"CMPCertificate", HFILL }},
{ &hf_cmp_newWithOld,
{ "newWithOld", "cmp.newWithOld",
FT_UINT32, BASE_DEC, VALS(cmp_CMPCertificate_vals), 0,
"CMPCertificate", HFILL }},
{ &hf_cmp_newWithNew,
{ "newWithNew", "cmp.newWithNew",
FT_UINT32, BASE_DEC, VALS(cmp_CMPCertificate_vals), 0,
"CMPCertificate", HFILL }},
{ &hf_cmp_willBeRevokedAt,
{ "willBeRevokedAt", "cmp.willBeRevokedAt",
FT_STRING, BASE_NONE, NULL, 0,
"GeneralizedTime", HFILL }},
{ &hf_cmp_badSinceDate,
{ "badSinceDate", "cmp.badSinceDate",
FT_STRING, BASE_NONE, NULL, 0,
"GeneralizedTime", HFILL }},
{ &hf_cmp_crlDetails,
{ "crlDetails", "cmp.crlDetails",
FT_UINT32, BASE_DEC, NULL, 0,
"Extensions", HFILL }},
{ &hf_cmp_CRLAnnContent_item,
{ "CertificateList", "cmp.CertificateList_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_CertConfirmContent_item,
{ "CertStatus", "cmp.CertStatus_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_certHash,
{ "certHash", "cmp.certHash",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_cmp_statusInfo,
{ "statusInfo", "cmp.statusInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
"PKIStatusInfo", HFILL }},
{ &hf_cmp_infoType,
{ "infoType", "cmp.infoType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_infoValue,
{ "infoValue", "cmp.infoValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_SignKeyPairTypesValue_item,
{ "AlgorithmIdentifier", "cmp.AlgorithmIdentifier_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_EncKeyPairTypesValue_item,
{ "AlgorithmIdentifier", "cmp.AlgorithmIdentifier_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_UnsupportedOIDsValue_item,
{ "UnsupportedOIDsValue item", "cmp.UnsupportedOIDsValue_item",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_cmp_SuppLangTagsValue_item,
{ "SuppLangTagsValue item", "cmp.SuppLangTagsValue_item",
FT_STRING, BASE_NONE, NULL, 0,
"UTF8String", HFILL }},
{ &hf_cmp_GenMsgContent_item,
{ "InfoTypeAndValue", "cmp.InfoTypeAndValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_GenRepContent_item,
{ "InfoTypeAndValue", "cmp.InfoTypeAndValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_pKIStatusInfo,
{ "pKIStatusInfo", "cmp.pKIStatusInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_errorCode,
{ "errorCode", "cmp.errorCode",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_cmp_errorDetails,
{ "errorDetails", "cmp.errorDetails",
FT_UINT32, BASE_DEC, NULL, 0,
"PKIFreeText", HFILL }},
{ &hf_cmp_PollReqContent_item,
{ "PollReqContent item", "cmp.PollReqContent_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_PollRepContent_item,
{ "PollRepContent item", "cmp.PollRepContent_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmp_checkAfter,
{ "checkAfter", "cmp.checkAfter",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_cmp_reason,
{ "reason", "cmp.reason",
FT_UINT32, BASE_DEC, NULL, 0,
"PKIFreeText", HFILL }},
{ &hf_cmp_PKIFailureInfo_badAlg,
{ "badAlg", "cmp.badAlg",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_cmp_PKIFailureInfo_badMessageCheck,
{ "badMessageCheck", "cmp.badMessageCheck",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_cmp_PKIFailureInfo_badRequest,
{ "badRequest", "cmp.badRequest",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_cmp_PKIFailureInfo_badTime,
{ "badTime", "cmp.badTime",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_cmp_PKIFailureInfo_badCertId,
{ "badCertId", "cmp.badCertId",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_cmp_PKIFailureInfo_badDataFormat,
{ "badDataFormat", "cmp.badDataFormat",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_cmp_PKIFailureInfo_wrongAuthority,
{ "wrongAuthority", "cmp.wrongAuthority",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_cmp_PKIFailureInfo_incorrectData,
{ "incorrectData", "cmp.incorrectData",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_cmp_PKIFailureInfo_missingTimeStamp,
{ "missingTimeStamp", "cmp.missingTimeStamp",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_cmp_PKIFailureInfo_badPOP,
{ "badPOP", "cmp.badPOP",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_cmp_PKIFailureInfo_certRevoked,
{ "certRevoked", "cmp.certRevoked",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_cmp_PKIFailureInfo_certConfirmed,
{ "certConfirmed", "cmp.certConfirmed",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_cmp_PKIFailureInfo_wrongIntegrity,
{ "wrongIntegrity", "cmp.wrongIntegrity",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_cmp_PKIFailureInfo_badRecipientNonce,
{ "badRecipientNonce", "cmp.badRecipientNonce",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_cmp_PKIFailureInfo_timeNotAvailable,
{ "timeNotAvailable", "cmp.timeNotAvailable",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_cmp_PKIFailureInfo_unacceptedPolicy,
{ "unacceptedPolicy", "cmp.unacceptedPolicy",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_cmp_PKIFailureInfo_unacceptedExtension,
{ "unacceptedExtension", "cmp.unacceptedExtension",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_cmp_PKIFailureInfo_addInfoNotAvailable,
{ "addInfoNotAvailable", "cmp.addInfoNotAvailable",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_cmp_PKIFailureInfo_badSenderNonce,
{ "badSenderNonce", "cmp.badSenderNonce",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_cmp_PKIFailureInfo_badCertTemplate,
{ "badCertTemplate", "cmp.badCertTemplate",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_cmp_PKIFailureInfo_signerNotTrusted,
{ "signerNotTrusted", "cmp.signerNotTrusted",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_cmp_PKIFailureInfo_transactionIdInUse,
{ "transactionIdInUse", "cmp.transactionIdInUse",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_cmp_PKIFailureInfo_unsupportedVersion,
{ "unsupportedVersion", "cmp.unsupportedVersion",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_cmp_PKIFailureInfo_notAuthorized,
{ "notAuthorized", "cmp.notAuthorized",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_cmp_PKIFailureInfo_systemUnavail,
{ "systemUnavail", "cmp.systemUnavail",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_cmp_PKIFailureInfo_systemFailure,
{ "systemFailure", "cmp.systemFailure",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_cmp_PKIFailureInfo_duplicateCertReq,
{ "duplicateCertReq", "cmp.duplicateCertReq",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
#line 324 "./asn1/cmp/packet-cmp-template.c"
};
static gint *ett[] = {
&ett_cmp,
#line 1 "./asn1/cmp/packet-cmp-ettarr.c"
&ett_cmp_CMPCertificate,
&ett_cmp_PKIMessage,
&ett_cmp_SEQUENCE_SIZE_1_MAX_OF_CMPCertificate,
&ett_cmp_PKIMessages,
&ett_cmp_PKIHeader,
&ett_cmp_SEQUENCE_SIZE_1_MAX_OF_InfoTypeAndValue,
&ett_cmp_PKIFreeText,
&ett_cmp_PKIBody,
&ett_cmp_ProtectedPart,
&ett_cmp_PBMParameter,
&ett_cmp_DHBMParameter,
&ett_cmp_PKIFailureInfo,
&ett_cmp_PKIStatusInfo,
&ett_cmp_OOBCertHash,
&ett_cmp_POPODecKeyChallContent,
&ett_cmp_Challenge,
&ett_cmp_POPODecKeyRespContent,
&ett_cmp_CertRepMessage,
&ett_cmp_SEQUENCE_OF_CertResponse,
&ett_cmp_CertResponse,
&ett_cmp_CertifiedKeyPair,
&ett_cmp_CertOrEncCert,
&ett_cmp_KeyRecRepContent,
&ett_cmp_SEQUENCE_SIZE_1_MAX_OF_CertifiedKeyPair,
&ett_cmp_RevReqContent,
&ett_cmp_RevDetails,
&ett_cmp_RevRepContent,
&ett_cmp_SEQUENCE_SIZE_1_MAX_OF_PKIStatusInfo,
&ett_cmp_SEQUENCE_SIZE_1_MAX_OF_CertId,
&ett_cmp_SEQUENCE_SIZE_1_MAX_OF_CertificateList,
&ett_cmp_CAKeyUpdAnnContent,
&ett_cmp_RevAnnContent,
&ett_cmp_CRLAnnContent,
&ett_cmp_CertConfirmContent,
&ett_cmp_CertStatus,
&ett_cmp_InfoTypeAndValue,
&ett_cmp_SignKeyPairTypesValue,
&ett_cmp_EncKeyPairTypesValue,
&ett_cmp_UnsupportedOIDsValue,
&ett_cmp_SuppLangTagsValue,
&ett_cmp_GenMsgContent,
&ett_cmp_GenRepContent,
&ett_cmp_ErrorMsgContent,
&ett_cmp_PollReqContent,
&ett_cmp_PollReqContent_item,
&ett_cmp_PollRepContent,
&ett_cmp_PollRepContent_item,
#line 330 "./asn1/cmp/packet-cmp-template.c"
};
module_t *cmp_module;
proto_cmp = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_cmp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
cmp_module = prefs_register_protocol(proto_cmp, proto_reg_handoff_cmp);
prefs_register_bool_preference(cmp_module, "desegment",
"Reassemble CMP-over-TCP messages spanning multiple TCP segments",
"Whether the CMP-over-TCP dissector should reassemble messages spanning multiple TCP segments. "
"To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&cmp_desegment);
prefs_register_uint_preference(cmp_module, "http_alternate_port",
"Alternate HTTP port",
"Decode this TCP port\'s traffic as CMP-over-HTTP. Set to \"0\" to disable. "
"Use this if the Content-Type is not set correctly.",
10,
&cmp_alternate_http_port);
prefs_register_uint_preference(cmp_module, "tcp_style_http_alternate_port",
"Alternate TCP-style-HTTP port",
"Decode this TCP port\'s traffic as TCP-transport-style CMP-over-HTTP. Set to \"0\" to disable. "
"Use this if the Content-Type is not set correctly.",
10,
&cmp_alternate_tcp_style_http_port);
}
void proto_reg_handoff_cmp(void) {
static gboolean inited = FALSE;
static dissector_handle_t cmp_http_handle;
static dissector_handle_t cmp_tcp_style_http_handle;
static dissector_handle_t cmp_tcp_handle;
static guint cmp_alternate_http_port_prev = 0;
static guint cmp_alternate_tcp_style_http_port_prev = 0;
if (!inited) {
cmp_http_handle = create_dissector_handle(dissect_cmp_http, proto_cmp);
dissector_add_string("media_type", "application/pkixcmp", cmp_http_handle);
dissector_add_string("media_type", "application/x-pkixcmp", cmp_http_handle);
cmp_tcp_style_http_handle = create_dissector_handle(dissect_cmp_tcp_pdu, proto_cmp);
dissector_add_string("media_type", "application/pkixcmp-poll", cmp_tcp_style_http_handle);
dissector_add_string("media_type", "application/x-pkixcmp-poll", cmp_tcp_style_http_handle);
cmp_tcp_handle = create_dissector_handle(dissect_cmp_tcp, proto_cmp);
dissector_add_uint_with_preference("tcp.port", TCP_PORT_CMP, cmp_tcp_handle);
oid_add_from_string("Cryptlib-presence-check","1.3.6.1.4.1.3029.3.1.1");
oid_add_from_string("Cryptlib-PKIBoot","1.3.6.1.4.1.3029.3.1.2");
oid_add_from_string("HMAC MD5","1.3.6.1.5.5.8.1.1");
oid_add_from_string("HMAC SHA-1","1.3.6.1.5.5.8.1.2");
oid_add_from_string("HMAC TIGER","1.3.6.1.5.5.8.1.3");
oid_add_from_string("HMAC RIPEMD-160","1.3.6.1.5.5.8.1.4");
#line 1 "./asn1/cmp/packet-cmp-dis-tab.c"
register_ber_oid_dissector("1.2.840.113533.7.66.13", dissect_PBMParameter_PDU, proto_cmp, "id-PasswordBasedMac");
register_ber_oid_dissector("1.2.640.113533.7.66.30", dissect_DHBMParameter_PDU, proto_cmp, "id-DHBasedMac");
register_ber_oid_dissector("1.3.6.1.5.5.7.4.1", dissect_CAProtEncCertValue_PDU, proto_cmp, "id-it-caProtEncCert");
register_ber_oid_dissector("1.3.6.1.5.5.7.4.2", dissect_SignKeyPairTypesValue_PDU, proto_cmp, "id-it-signKeyPairTypes");
register_ber_oid_dissector("1.3.6.1.5.5.7.4.3", dissect_EncKeyPairTypesValue_PDU, proto_cmp, "id-it-encKeyPairTypes");
register_ber_oid_dissector("1.3.6.1.5.5.7.4.4", dissect_PreferredSymmAlgValue_PDU, proto_cmp, "id-it-preferredSymmAlg");
register_ber_oid_dissector("1.3.6.1.5.5.7.4.5", dissect_CAKeyUpdateInfoValue_PDU, proto_cmp, "id-it-caKeyUpdateInfo");
register_ber_oid_dissector("1.3.6.1.5.5.7.4.6", dissect_CurrentCRLValue_PDU, proto_cmp, "id-it-currentCRL");
register_ber_oid_dissector("1.3.6.1.5.5.7.4.7", dissect_UnsupportedOIDsValue_PDU, proto_cmp, "id-it-unsupportedOIDs");
register_ber_oid_dissector("1.3.6.1.5.5.7.4.10", dissect_KeyPairParamReqValue_PDU, proto_cmp, "id-it-keyPairParamReq");
register_ber_oid_dissector("1.3.6.1.5.5.7.4.11", dissect_KeyPairParamRepValue_PDU, proto_cmp, "id-it-keyPairParamRep");
register_ber_oid_dissector("1.3.6.1.5.5.7.4.12", dissect_RevPassphraseValue_PDU, proto_cmp, "id-it-revPassphrase");
register_ber_oid_dissector("1.3.6.1.5.5.7.4.13", dissect_ImplicitConfirmValue_PDU, proto_cmp, "id-it-implicitConfirm");
register_ber_oid_dissector("1.3.6.1.5.5.7.4.14", dissect_ConfirmWaitTimeValue_PDU, proto_cmp, "id-it-confirmWaitTime");
register_ber_oid_dissector("1.3.6.1.5.5.7.4.15", dissect_OrigPKIMessageValue_PDU, proto_cmp, "id-it-origPKIMessage");
register_ber_oid_dissector("1.3.6.1.5.5.7.4.16", dissect_SuppLangTagsValue_PDU, proto_cmp, "id-it-suppLangTags");
#line 393 "./asn1/cmp/packet-cmp-template.c"
inited = TRUE;
}
if (cmp_alternate_http_port != cmp_alternate_http_port_prev) {
if (cmp_alternate_http_port_prev != 0) {
http_tcp_dissector_delete(cmp_alternate_http_port_prev);
}
if (cmp_alternate_http_port != 0)
http_tcp_dissector_add( cmp_alternate_http_port, cmp_http_handle);
cmp_alternate_http_port_prev = cmp_alternate_http_port;
}
if (cmp_alternate_tcp_style_http_port != cmp_alternate_tcp_style_http_port_prev) {
if (cmp_alternate_tcp_style_http_port_prev != 0) {
http_tcp_dissector_delete(cmp_alternate_tcp_style_http_port_prev);
}
if (cmp_alternate_tcp_style_http_port != 0)
http_tcp_dissector_add( cmp_alternate_tcp_style_http_port, cmp_tcp_style_http_handle);
cmp_alternate_tcp_style_http_port_prev = cmp_alternate_tcp_style_http_port;
}
}
