static int
dissect_crmf_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_crmf_OptionalValidity(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
OptionalValidity_sequence, hf_index, ett_crmf_OptionalValidity);
return offset;
}
int
dissect_crmf_CertTemplate(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CertTemplate_sequence, hf_index, ett_crmf_CertTemplate);
return offset;
}
static int
dissect_crmf_T_type(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_crmf_type_oid, &actx->external.direct_reference);
return offset;
}
static int
dissect_crmf_T_value(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 72 "../../asn1/crmf/crmf.cnf"
offset=call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
int
dissect_crmf_AttributeTypeAndValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AttributeTypeAndValue_sequence, hf_index, ett_crmf_AttributeTypeAndValue);
return offset;
}
int
dissect_crmf_Controls(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Controls_sequence_of, hf_index, ett_crmf_Controls);
return offset;
}
int
dissect_crmf_CertRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CertRequest_sequence, hf_index, ett_crmf_CertRequest);
return offset;
}
static int
dissect_crmf_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_crmf_BIT_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
int
dissect_crmf_PKMACValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PKMACValue_sequence, hf_index, ett_crmf_PKMACValue);
return offset;
}
static int
dissect_crmf_T_authInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_authInfo_choice, hf_index, ett_crmf_T_authInfo,
NULL);
return offset;
}
int
dissect_crmf_POPOSigningKeyInput(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
POPOSigningKeyInput_sequence, hf_index, ett_crmf_POPOSigningKeyInput);
return offset;
}
int
dissect_crmf_POPOSigningKey(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
POPOSigningKey_sequence, hf_index, ett_crmf_POPOSigningKey);
return offset;
}
int
dissect_crmf_SubsequentMessage(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_crmf_POPOPrivKey(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
POPOPrivKey_choice, hf_index, ett_crmf_POPOPrivKey,
NULL);
return offset;
}
int
dissect_crmf_ProofOfPossession(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ProofOfPossession_choice, hf_index, ett_crmf_ProofOfPossession,
NULL);
return offset;
}
static int
dissect_crmf_SEQUENCE_SIZE_1_MAX_OF_AttributeTypeAndValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_MAX_OF_AttributeTypeAndValue_sequence_of, hf_index, ett_crmf_SEQUENCE_SIZE_1_MAX_OF_AttributeTypeAndValue);
return offset;
}
int
dissect_crmf_CertReqMsg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CertReqMsg_sequence, hf_index, ett_crmf_CertReqMsg);
return offset;
}
int
dissect_crmf_CertReqMessages(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
CertReqMessages_sequence_of, hf_index, ett_crmf_CertReqMessages);
return offset;
}
static int
dissect_crmf_OCTET_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_crmf_PBMParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PBMParameter_sequence, hf_index, ett_crmf_PBMParameter);
return offset;
}
int
dissect_crmf_RegToken(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_UTF8String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_crmf_Authenticator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_UTF8String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_crmf_T_action(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_crmf_T_pubMethod(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_crmf_SinglePubInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SinglePubInfo_sequence, hf_index, ett_crmf_SinglePubInfo);
return offset;
}
static int
dissect_crmf_SEQUENCE_SIZE_1_MAX_OF_SinglePubInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_MAX_OF_SinglePubInfo_sequence_of, hf_index, ett_crmf_SEQUENCE_SIZE_1_MAX_OF_SinglePubInfo);
return offset;
}
int
dissect_crmf_PKIPublicationInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PKIPublicationInfo_sequence, hf_index, ett_crmf_PKIPublicationInfo);
return offset;
}
int
dissect_crmf_EncryptedValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EncryptedValue_sequence, hf_index, ett_crmf_EncryptedValue);
return offset;
}
int
dissect_crmf_EncryptedKey(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
EncryptedKey_choice, hf_index, ett_crmf_EncryptedKey,
NULL);
return offset;
}
int
dissect_crmf_KeyGenParameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_crmf_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
int
dissect_crmf_PKIArchiveOptions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
PKIArchiveOptions_choice, hf_index, ett_crmf_PKIArchiveOptions,
NULL);
return offset;
}
int
dissect_crmf_CertId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CertId_sequence, hf_index, ett_crmf_CertId);
return offset;
}
int
dissect_crmf_OldCertId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_crmf_CertId(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
int
dissect_crmf_ProtocolEncrKey(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_pkix1explicit_SubjectPublicKeyInfo(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
int
dissect_crmf_UTF8Pairs(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_UTF8String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_crmf_CertReq(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_crmf_CertRequest(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
int
dissect_crmf_Attributes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
Attributes_set_of, hf_index, ett_crmf_Attributes);
return offset;
}
int
dissect_crmf_PrivateKeyInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PrivateKeyInfo_sequence, hf_index, ett_crmf_PrivateKeyInfo);
return offset;
}
static int
dissect_crmf_UTF8String(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_UTF8String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_crmf_T_identifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_identifier_choice, hf_index, ett_crmf_T_identifier,
NULL);
return offset;
}
int
dissect_crmf_EncKeyWithID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EncKeyWithID_sequence, hf_index, ett_crmf_EncKeyWithID);
return offset;
}
static void dissect_CertRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_crmf_CertRequest(FALSE, tvb, 0, &asn1_ctx, tree, hf_crmf_CertRequest_PDU);
}
static void dissect_PBMParameter_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_crmf_PBMParameter(FALSE, tvb, 0, &asn1_ctx, tree, hf_crmf_PBMParameter_PDU);
}
static void dissect_RegToken_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_crmf_RegToken(FALSE, tvb, 0, &asn1_ctx, tree, hf_crmf_RegToken_PDU);
}
static void dissect_Authenticator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_crmf_Authenticator(FALSE, tvb, 0, &asn1_ctx, tree, hf_crmf_Authenticator_PDU);
}
static void dissect_PKIPublicationInfo_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_crmf_PKIPublicationInfo(FALSE, tvb, 0, &asn1_ctx, tree, hf_crmf_PKIPublicationInfo_PDU);
}
static void dissect_PKIArchiveOptions_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_crmf_PKIArchiveOptions(FALSE, tvb, 0, &asn1_ctx, tree, hf_crmf_PKIArchiveOptions_PDU);
}
static void dissect_OldCertId_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_crmf_OldCertId(FALSE, tvb, 0, &asn1_ctx, tree, hf_crmf_OldCertId_PDU);
}
static void dissect_ProtocolEncrKey_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_crmf_ProtocolEncrKey(FALSE, tvb, 0, &asn1_ctx, tree, hf_crmf_ProtocolEncrKey_PDU);
}
static void dissect_UTF8Pairs_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_crmf_UTF8Pairs(FALSE, tvb, 0, &asn1_ctx, tree, hf_crmf_UTF8Pairs_PDU);
}
static void dissect_EncKeyWithID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_crmf_EncKeyWithID(FALSE, tvb, 0, &asn1_ctx, tree, hf_crmf_EncKeyWithID_PDU);
}
void proto_register_crmf(void) {
static hf_register_info hf[] = {
{ &hf_crmf_type_oid,
{ "Type", "crmf.type.oid",
FT_STRING, BASE_NONE, NULL, 0,
"Type of AttributeTypeAndValue", HFILL }},
#line 1 "../../asn1/crmf/packet-crmf-hfarr.c"
{ &hf_crmf_CertRequest_PDU,
{ "CertRequest", "crmf.CertRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_crmf_PBMParameter_PDU,
{ "PBMParameter", "crmf.PBMParameter_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_crmf_RegToken_PDU,
{ "RegToken", "crmf.RegToken",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_crmf_Authenticator_PDU,
{ "Authenticator", "crmf.Authenticator",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_crmf_PKIPublicationInfo_PDU,
{ "PKIPublicationInfo", "crmf.PKIPublicationInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_crmf_PKIArchiveOptions_PDU,
{ "PKIArchiveOptions", "crmf.PKIArchiveOptions",
FT_UINT32, BASE_DEC, VALS(crmf_PKIArchiveOptions_vals), 0,
NULL, HFILL }},
{ &hf_crmf_OldCertId_PDU,
{ "OldCertId", "crmf.OldCertId_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_crmf_ProtocolEncrKey_PDU,
{ "ProtocolEncrKey", "crmf.ProtocolEncrKey_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_crmf_UTF8Pairs_PDU,
{ "UTF8Pairs", "crmf.UTF8Pairs",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_crmf_EncKeyWithID_PDU,
{ "EncKeyWithID", "crmf.EncKeyWithID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_crmf_CertReqMessages_item,
{ "CertReqMsg", "crmf.CertReqMsg_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_crmf_certReq,
{ "certReq", "crmf.certReq_element",
FT_NONE, BASE_NONE, NULL, 0,
"CertRequest", HFILL }},
{ &hf_crmf_popo,
{ "popo", "crmf.popo",
FT_UINT32, BASE_DEC, VALS(crmf_ProofOfPossession_vals), 0,
"ProofOfPossession", HFILL }},
{ &hf_crmf_regInfo,
{ "regInfo", "crmf.regInfo",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_AttributeTypeAndValue", HFILL }},
{ &hf_crmf_regInfo_item,
{ "AttributeTypeAndValue", "crmf.AttributeTypeAndValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_crmf_certReqId,
{ "certReqId", "crmf.certReqId",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_crmf_certTemplate,
{ "certTemplate", "crmf.certTemplate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_crmf_controls,
{ "controls", "crmf.controls",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_crmf_version,
{ "version", "crmf.version",
FT_INT32, BASE_DEC, VALS(pkix1explicit_Version_vals), 0,
NULL, HFILL }},
{ &hf_crmf_serialNumber,
{ "serialNumber", "crmf.serialNumber",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_crmf_signingAlg,
{ "signingAlg", "crmf.signingAlg_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_crmf_template_issuer,
{ "issuer", "crmf.issuer",
FT_UINT32, BASE_DEC, NULL, 0,
"Name", HFILL }},
{ &hf_crmf_validity,
{ "validity", "crmf.validity_element",
FT_NONE, BASE_NONE, NULL, 0,
"OptionalValidity", HFILL }},
{ &hf_crmf_subject,
{ "subject", "crmf.subject",
FT_UINT32, BASE_DEC, NULL, 0,
"Name", HFILL }},
{ &hf_crmf_publicKey,
{ "publicKey", "crmf.publicKey_element",
FT_NONE, BASE_NONE, NULL, 0,
"SubjectPublicKeyInfo", HFILL }},
{ &hf_crmf_issuerUID,
{ "issuerUID", "crmf.issuerUID",
FT_BYTES, BASE_NONE, NULL, 0,
"UniqueIdentifier", HFILL }},
{ &hf_crmf_subjectUID,
{ "subjectUID", "crmf.subjectUID",
FT_BYTES, BASE_NONE, NULL, 0,
"UniqueIdentifier", HFILL }},
{ &hf_crmf_extensions,
{ "extensions", "crmf.extensions",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_crmf_notBefore,
{ "notBefore", "crmf.notBefore",
FT_UINT32, BASE_DEC, VALS(pkix1explicit_Time_vals), 0,
"Time", HFILL }},
{ &hf_crmf_notAfter,
{ "notAfter", "crmf.notAfter",
FT_UINT32, BASE_DEC, VALS(pkix1explicit_Time_vals), 0,
"Time", HFILL }},
{ &hf_crmf_Controls_item,
{ "AttributeTypeAndValue", "crmf.AttributeTypeAndValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_crmf_type,
{ "type", "crmf.type",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_crmf_value,
{ "value", "crmf.value_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_crmf_raVerified,
{ "raVerified", "crmf.raVerified_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_crmf_signature,
{ "signature", "crmf.signature_element",
FT_NONE, BASE_NONE, NULL, 0,
"POPOSigningKey", HFILL }},
{ &hf_crmf_keyEncipherment,
{ "keyEncipherment", "crmf.keyEncipherment",
FT_UINT32, BASE_DEC, VALS(crmf_POPOPrivKey_vals), 0,
"POPOPrivKey", HFILL }},
{ &hf_crmf_keyAgreement,
{ "keyAgreement", "crmf.keyAgreement",
FT_UINT32, BASE_DEC, VALS(crmf_POPOPrivKey_vals), 0,
"POPOPrivKey", HFILL }},
{ &hf_crmf_poposkInput,
{ "poposkInput", "crmf.poposkInput_element",
FT_NONE, BASE_NONE, NULL, 0,
"POPOSigningKeyInput", HFILL }},
{ &hf_crmf_algorithmIdentifier,
{ "algorithmIdentifier", "crmf.algorithmIdentifier_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_crmf_sk_signature,
{ "signature", "crmf.signature",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_crmf_authInfo,
{ "authInfo", "crmf.authInfo",
FT_UINT32, BASE_DEC, VALS(crmf_T_authInfo_vals), 0,
NULL, HFILL }},
{ &hf_crmf_sender,
{ "sender", "crmf.sender",
FT_UINT32, BASE_DEC, NULL, 0,
"GeneralName", HFILL }},
{ &hf_crmf_publicKeyMAC,
{ "publicKeyMAC", "crmf.publicKeyMAC_element",
FT_NONE, BASE_NONE, NULL, 0,
"PKMACValue", HFILL }},
{ &hf_crmf_algId,
{ "algId", "crmf.algId_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_crmf_pkmac_value,
{ "value", "crmf.value",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_crmf_salt,
{ "salt", "crmf.salt",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_crmf_owf,
{ "owf", "crmf.owf_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_crmf_iterationCount,
{ "iterationCount", "crmf.iterationCount",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_crmf_mac,
{ "mac", "crmf.mac_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_crmf_thisMessage,
{ "thisMessage", "crmf.thisMessage",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_crmf_subsequentMessage,
{ "subsequentMessage", "crmf.subsequentMessage",
FT_INT32, BASE_DEC, VALS(crmf_SubsequentMessage_vals), 0,
NULL, HFILL }},
{ &hf_crmf_dhMAC,
{ "dhMAC", "crmf.dhMAC",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_crmf_agreeMAC,
{ "agreeMAC", "crmf.agreeMAC_element",
FT_NONE, BASE_NONE, NULL, 0,
"PKMACValue", HFILL }},
{ &hf_crmf_encryptedKey,
{ "encryptedKey", "crmf.encryptedKey_element",
FT_NONE, BASE_NONE, NULL, 0,
"EnvelopedData", HFILL }},
{ &hf_crmf_action,
{ "action", "crmf.action",
FT_INT32, BASE_DEC, VALS(crmf_T_action_vals), 0,
NULL, HFILL }},
{ &hf_crmf_pubInfos,
{ "pubInfos", "crmf.pubInfos",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_SinglePubInfo", HFILL }},
{ &hf_crmf_pubInfos_item,
{ "SinglePubInfo", "crmf.SinglePubInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_crmf_pubMethod,
{ "pubMethod", "crmf.pubMethod",
FT_INT32, BASE_DEC, VALS(crmf_T_pubMethod_vals), 0,
NULL, HFILL }},
{ &hf_crmf_pubLocation,
{ "pubLocation", "crmf.pubLocation",
FT_UINT32, BASE_DEC, NULL, 0,
"GeneralName", HFILL }},
{ &hf_crmf_encryptedPrivKey,
{ "encryptedPrivKey", "crmf.encryptedPrivKey",
FT_UINT32, BASE_DEC, VALS(crmf_EncryptedKey_vals), 0,
"EncryptedKey", HFILL }},
{ &hf_crmf_keyGenParameters,
{ "keyGenParameters", "crmf.keyGenParameters",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_crmf_archiveRemGenPrivKey,
{ "archiveRemGenPrivKey", "crmf.archiveRemGenPrivKey",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_crmf_encryptedValue,
{ "encryptedValue", "crmf.encryptedValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_crmf_envelopedData,
{ "envelopedData", "crmf.envelopedData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_crmf_intendedAlg,
{ "intendedAlg", "crmf.intendedAlg_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_crmf_symmAlg,
{ "symmAlg", "crmf.symmAlg_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_crmf_encSymmKey,
{ "encSymmKey", "crmf.encSymmKey",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_crmf_keyAlg,
{ "keyAlg", "crmf.keyAlg_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_crmf_valueHint,
{ "valueHint", "crmf.valueHint",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_crmf_encValue,
{ "encValue", "crmf.encValue",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_crmf_issuer,
{ "issuer", "crmf.issuer",
FT_UINT32, BASE_DEC, NULL, 0,
"GeneralName", HFILL }},
{ &hf_crmf_enckeywid_privkey,
{ "privateKey", "crmf.privateKey_element",
FT_NONE, BASE_NONE, NULL, 0,
"PrivateKeyInfo", HFILL }},
{ &hf_crmf_identifier,
{ "identifier", "crmf.identifier",
FT_UINT32, BASE_DEC, VALS(crmf_T_identifier_vals), 0,
NULL, HFILL }},
{ &hf_crmf_string,
{ "string", "crmf.string",
FT_STRING, BASE_NONE, NULL, 0,
"UTF8String", HFILL }},
{ &hf_crmf_generalName,
{ "generalName", "crmf.generalName",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_crmf_privkey_version,
{ "version", "crmf.version",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_crmf_privateKeyAlgorithm,
{ "privateKeyAlgorithm", "crmf.privateKeyAlgorithm_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_crmf_privateKey,
{ "privateKey", "crmf.privateKey",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_crmf_attributes,
{ "attributes", "crmf.attributes",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_crmf_Attributes_item,
{ "Attribute", "crmf.Attribute_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
#line 64 "../../asn1/crmf/packet-crmf-template.c"
};
static gint *ett[] = {
#line 1 "../../asn1/crmf/packet-crmf-ettarr.c"
&ett_crmf_CertReqMessages,
&ett_crmf_CertReqMsg,
&ett_crmf_SEQUENCE_SIZE_1_MAX_OF_AttributeTypeAndValue,
&ett_crmf_CertRequest,
&ett_crmf_CertTemplate,
&ett_crmf_OptionalValidity,
&ett_crmf_Controls,
&ett_crmf_AttributeTypeAndValue,
&ett_crmf_ProofOfPossession,
&ett_crmf_POPOSigningKey,
&ett_crmf_POPOSigningKeyInput,
&ett_crmf_T_authInfo,
&ett_crmf_PKMACValue,
&ett_crmf_PBMParameter,
&ett_crmf_POPOPrivKey,
&ett_crmf_PKIPublicationInfo,
&ett_crmf_SEQUENCE_SIZE_1_MAX_OF_SinglePubInfo,
&ett_crmf_SinglePubInfo,
&ett_crmf_PKIArchiveOptions,
&ett_crmf_EncryptedKey,
&ett_crmf_EncryptedValue,
&ett_crmf_CertId,
&ett_crmf_EncKeyWithID,
&ett_crmf_T_identifier,
&ett_crmf_PrivateKeyInfo,
&ett_crmf_Attributes,
#line 69 "../../asn1/crmf/packet-crmf-template.c"
};
proto_crmf = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_crmf, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_crmf(void) {
oid_add_from_string("id-pkip","1.3.6.1.5.5.7.5");
oid_add_from_string("id-regCtrl","1.3.6.1.5.5.7.5.1");
oid_add_from_string("id-regInfo","1.3.6.1.5.5.7.5.2");
#line 1 "../../asn1/crmf/packet-crmf-dis-tab.c"
register_ber_oid_dissector("1.2.840.113549.1.9.16.1.21", dissect_EncKeyWithID_PDU, proto_crmf, "id-ct-encKeyWithID");
register_ber_oid_dissector("1.2.840.113533.7.66.13", dissect_PBMParameter_PDU, proto_crmf, "PasswordBasedMac");
register_ber_oid_dissector("1.3.6.1.5.5.7.5.1.1", dissect_RegToken_PDU, proto_crmf, "id-regCtrl-regToken");
register_ber_oid_dissector("1.3.6.1.5.5.7.5.1.2", dissect_Authenticator_PDU, proto_crmf, "id-regCtrl-authenticator");
register_ber_oid_dissector("1.3.6.1.5.5.7.5.1.3", dissect_PKIPublicationInfo_PDU, proto_crmf, "id-regCtrl-pkiPublicationInfo");
register_ber_oid_dissector("1.3.6.1.5.5.7.5.1.4", dissect_PKIArchiveOptions_PDU, proto_crmf, "id-regCtrl-pkiArchiveOptions");
register_ber_oid_dissector("1.3.6.1.5.5.7.5.1.5", dissect_OldCertId_PDU, proto_crmf, "id-regCtrl-oldCertID");
register_ber_oid_dissector("1.3.6.1.5.5.7.5.1.6", dissect_ProtocolEncrKey_PDU, proto_crmf, "id-regCtrl-protocolEncrKey");
register_ber_oid_dissector("1.3.6.1.5.5.7.5.2.1", dissect_UTF8Pairs_PDU, proto_crmf, "id-regInfo-utf8Pairs");
register_ber_oid_dissector("1.3.6.1.5.5.7.5.2.2", dissect_CertRequest_PDU, proto_crmf, "id-regInfo-certReq");
#line 87 "../../asn1/crmf/packet-crmf-template.c"
}
