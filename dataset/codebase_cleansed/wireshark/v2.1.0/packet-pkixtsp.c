static int
dissect_pkixtsp_T_version(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pkixtsp_OCTET_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pkixtsp_MessageImprint(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MessageImprint_sequence, hf_index, ett_pkixtsp_MessageImprint);
return offset;
}
static int
dissect_pkixtsp_TSAPolicyId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_pkixtsp_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pkixtsp_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_pkixtsp_TimeStampReq(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TimeStampReq_sequence, hf_index, ett_pkixtsp_TimeStampReq);
return offset;
}
static int
dissect_pkixtsp_PKIStatus(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pkixtsp_PKIFailureInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
PKIFailureInfo_bits, hf_index, ett_pkixtsp_PKIFailureInfo,
NULL);
return offset;
}
static int
dissect_pkixtsp_PKIStatusInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PKIStatusInfo_sequence, hf_index, ett_pkixtsp_PKIStatusInfo);
return offset;
}
static int
dissect_pkixtsp_TimeStampToken(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_cms_ContentInfo(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_pkixtsp_TimeStampResp(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TimeStampResp_sequence, hf_index, ett_pkixtsp_TimeStampResp);
return offset;
}
static int
dissect_pkixtsp_Tst_version(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pkixtsp_GeneralizedTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_GeneralizedTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_pkixtsp_INTEGER_1_999(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pkixtsp_Accuracy(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Accuracy_sequence, hf_index, ett_pkixtsp_Accuracy);
return offset;
}
static int
dissect_pkixtsp_TSTInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TSTInfo_sequence, hf_index, ett_pkixtsp_TSTInfo);
return offset;
}
static int dissect_TSTInfo_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_pkixtsp_TSTInfo(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkixtsp_TSTInfo_PDU);
return offset;
}
static int
dissect_timestamp_reply(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PKIXTSP");
col_set_str(pinfo->cinfo, COL_INFO, "Reply");
if(parent_tree){
item=proto_tree_add_item(parent_tree, proto_pkixtsp, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_pkixtsp);
}
return dissect_pkixtsp_TimeStampResp(FALSE, tvb, 0, &asn1_ctx, tree, -1);
}
static int
dissect_timestamp_query(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PKIXTSP");
col_set_str(pinfo->cinfo, COL_INFO, "Query");
if(parent_tree){
item=proto_tree_add_item(parent_tree, proto_pkixtsp, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_pkixtsp);
}
return dissect_pkixtsp_TimeStampReq(FALSE, tvb, 0, &asn1_ctx, tree, -1);
}
void proto_register_pkixtsp(void) {
static hf_register_info hf[] = {
#line 1 "./asn1/pkixtsp/packet-pkixtsp-hfarr.c"
{ &hf_pkixtsp_TSTInfo_PDU,
{ "TSTInfo", "pkixtsp.TSTInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkixtsp_version,
{ "version", "pkixtsp.version",
FT_INT32, BASE_DEC, VALS(pkixtsp_T_version_vals), 0,
NULL, HFILL }},
{ &hf_pkixtsp_messageImprint,
{ "messageImprint", "pkixtsp.messageImprint_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkixtsp_reqPolicy,
{ "reqPolicy", "pkixtsp.reqPolicy",
FT_OID, BASE_NONE, NULL, 0,
"TSAPolicyId", HFILL }},
{ &hf_pkixtsp_nonce,
{ "nonce", "pkixtsp.nonce",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_pkixtsp_certReq,
{ "certReq", "pkixtsp.certReq",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_pkixtsp_extensions,
{ "extensions", "pkixtsp.extensions",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_pkixtsp_hashAlgorithm,
{ "hashAlgorithm", "pkixtsp.hashAlgorithm_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_pkixtsp_hashedMessage,
{ "hashedMessage", "pkixtsp.hashedMessage",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_pkixtsp_status,
{ "status", "pkixtsp.status_element",
FT_NONE, BASE_NONE, NULL, 0,
"PKIStatusInfo", HFILL }},
{ &hf_pkixtsp_timeStampToken,
{ "timeStampToken", "pkixtsp.timeStampToken_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkixtsp_pki_status,
{ "status", "pkixtsp.status",
FT_INT32, BASE_DEC, VALS(pkixtsp_PKIStatus_vals), 0,
"PKIStatus", HFILL }},
{ &hf_pkixtsp_failInfo,
{ "failInfo", "pkixtsp.failInfo",
FT_BYTES, BASE_NONE, NULL, 0,
"PKIFailureInfo", HFILL }},
{ &hf_pkixtsp_tst_version,
{ "version", "pkixtsp.version",
FT_INT32, BASE_DEC, VALS(pkixtsp_Tst_version_vals), 0,
"Tst_version", HFILL }},
{ &hf_pkixtsp_policy,
{ "policy", "pkixtsp.policy",
FT_OID, BASE_NONE, NULL, 0,
"TSAPolicyId", HFILL }},
{ &hf_pkixtsp_serialNumber,
{ "serialNumber", "pkixtsp.serialNumber",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_pkixtsp_genTime,
{ "genTime", "pkixtsp.genTime",
FT_STRING, BASE_NONE, NULL, 0,
"GeneralizedTime", HFILL }},
{ &hf_pkixtsp_accuracy,
{ "accuracy", "pkixtsp.accuracy_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkixtsp_ordering,
{ "ordering", "pkixtsp.ordering",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_pkixtsp_tsa,
{ "tsa", "pkixtsp.tsa",
FT_UINT32, BASE_DEC, NULL, 0,
"GeneralName", HFILL }},
{ &hf_pkixtsp_seconds,
{ "seconds", "pkixtsp.seconds",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_pkixtsp_millis,
{ "millis", "pkixtsp.millis",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_999", HFILL }},
{ &hf_pkixtsp_micros,
{ "micros", "pkixtsp.micros",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_999", HFILL }},
{ &hf_pkixtsp_PKIFailureInfo_badAlg,
{ "badAlg", "pkixtsp.badAlg",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_pkixtsp_PKIFailureInfo_badRequest,
{ "badRequest", "pkixtsp.badRequest",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_pkixtsp_PKIFailureInfo_badDataFormat,
{ "badDataFormat", "pkixtsp.badDataFormat",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_pkixtsp_PKIFailureInfo_timeNotAvailable,
{ "timeNotAvailable", "pkixtsp.timeNotAvailable",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_pkixtsp_PKIFailureInfo_unacceptedPolicy,
{ "unacceptedPolicy", "pkixtsp.unacceptedPolicy",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_pkixtsp_PKIFailureInfo_unacceptedExtension,
{ "unacceptedExtension", "pkixtsp.unacceptedExtension",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_pkixtsp_PKIFailureInfo_addInfoNotAvailable,
{ "addInfoNotAvailable", "pkixtsp.addInfoNotAvailable",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_pkixtsp_PKIFailureInfo_systemFailure,
{ "systemFailure", "pkixtsp.systemFailure",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
#line 103 "./asn1/pkixtsp/packet-pkixtsp-template.c"
};
static gint *ett[] = {
&ett_pkixtsp,
#line 1 "./asn1/pkixtsp/packet-pkixtsp-ettarr.c"
&ett_pkixtsp_TimeStampReq,
&ett_pkixtsp_MessageImprint,
&ett_pkixtsp_TimeStampResp,
&ett_pkixtsp_PKIStatusInfo,
&ett_pkixtsp_PKIFailureInfo,
&ett_pkixtsp_TSTInfo,
&ett_pkixtsp_Accuracy,
#line 109 "./asn1/pkixtsp/packet-pkixtsp-template.c"
};
proto_pkixtsp = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_pkixtsp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_pkixtsp(void) {
dissector_handle_t timestamp_reply_handle;
dissector_handle_t timestamp_query_handle;
timestamp_reply_handle = create_dissector_handle(dissect_timestamp_reply, proto_pkixtsp);
dissector_add_string("media_type", "application/timestamp-reply", timestamp_reply_handle);
timestamp_query_handle = create_dissector_handle(dissect_timestamp_query, proto_pkixtsp);
dissector_add_string("media_type", "application/timestamp-query", timestamp_query_handle);
#line 1 "./asn1/pkixtsp/packet-pkixtsp-dis-tab.c"
register_ber_oid_dissector("1.2.840.113549.1.9.16.1.4", dissect_TSTInfo_PDU, proto_pkixtsp, "id-ct-TSTInfo");
#line 133 "./asn1/pkixtsp/packet-pkixtsp-template.c"
}
