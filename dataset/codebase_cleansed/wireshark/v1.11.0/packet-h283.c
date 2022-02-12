static int
dissect_h283_INTEGER_0_255(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_h283_INTEGER_0_65535(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_h283_H221NonStandard(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h283_H221NonStandard, H221NonStandard_sequence);
return offset;
}
static int
dissect_h283_OBJECT_IDENTIFIER(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_object_identifier(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_h283_NonStandardIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h283_NonStandardIdentifier, NonStandardIdentifier_choice,
NULL);
return offset;
}
static int
dissect_h283_OCTET_STRING(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_h283_NonStandardParameter(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h283_NonStandardParameter, NonStandardParameter_sequence);
return offset;
}
static int
dissect_h283_MTAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h283_MTAddress, MTAddress_sequence);
return offset;
}
static int
dissect_h283_INTEGER_0_4294967295(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4294967295U, NULL, FALSE);
return offset;
}
static int
dissect_h283_NULL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_null(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_h283_BOOLEAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_boolean(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_h283_LCTRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 58 "../../asn1/h283/h283.cnf"
gint32 msg_type = -1;
const gchar *p = NULL;
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h283_LCTRequest, LCTRequest_choice,
&msg_type);
#line 61 "../../asn1/h283/h283.cnf"
p = try_val_to_str(msg_type, VALS(h283_LCTRequest_vals));
if (!info_is_set && p ) {
col_add_fstr(actx->pinfo->cinfo, COL_INFO, "LCTRequest/%s", p);
info_is_set = TRUE;
}
return offset;
}
static int
dissect_h283_T_deviceListResp(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 105 "../../asn1/h283/h283.cnf"
tvbuff_t *next_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &next_tvb);
if (next_tvb && tvb_length(next_tvb)) {
call_dissector((rdc_device_list_handle)?rdc_device_list_handle:data_handle, next_tvb, actx->pinfo, tree);
}
return offset;
}
static int
dissect_h283_LCTResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 71 "../../asn1/h283/h283.cnf"
gint32 msg_type = -1;
const gchar *p = NULL;
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h283_LCTResponse, LCTResponse_choice,
&msg_type);
#line 74 "../../asn1/h283/h283.cnf"
p = try_val_to_str(msg_type, VALS(h283_LCTResponse_vals));
if (!info_is_set && p ) {
col_add_fstr(actx->pinfo->cinfo, COL_INFO, "LCTResponse/%s", p);
info_is_set = TRUE;
}
return offset;
}
static int
dissect_h283_LCTIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 84 "../../asn1/h283/h283.cnf"
gint32 msg_type = -1;
const gchar *p = NULL;
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h283_LCTIndication, LCTIndication_choice,
&msg_type);
#line 87 "../../asn1/h283/h283.cnf"
p = try_val_to_str(msg_type, VALS(h283_LCTIndication_vals));
if (!info_is_set && p ) {
col_add_fstr(actx->pinfo->cinfo, COL_INFO, "LCTIndication/%s", p);
info_is_set = TRUE;
}
return offset;
}
static int
dissect_h283_SEQUENCE_OF_NonStandardParameter(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h283_SEQUENCE_OF_NonStandardParameter, SEQUENCE_OF_NonStandardParameter_sequence_of);
return offset;
}
static int
dissect_h283_NonStandardMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h283_NonStandardMessage, NonStandardMessage_sequence);
return offset;
}
static int
dissect_h283_LCTMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 45 "../../asn1/h283/h283.cnf"
gint32 msg_type = -1;
const gchar *p = NULL;
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h283_LCTMessage, LCTMessage_choice,
&msg_type);
#line 48 "../../asn1/h283/h283.cnf"
p = try_val_to_str(msg_type, VALS(h283_LCTMessage_vals));
if (!info_is_set && p ) {
col_add_fstr(actx->pinfo->cinfo, COL_INFO, "LCTMessage/%s", p);
info_is_set = TRUE;
}
return offset;
}
static int
dissect_h283_T_rdcPDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 95 "../../asn1/h283/h283.cnf"
tvbuff_t *next_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &next_tvb);
if (next_tvb && tvb_length(next_tvb)) {
call_dissector((rdc_pdu_handle)?rdc_pdu_handle:data_handle, next_tvb, actx->pinfo, proto_tree_get_root(tree));
}
info_is_set = TRUE;
return offset;
}
static int
dissect_h283_T_dataType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 32 "../../asn1/h283/h283.cnf"
gint32 data_type = -1;
const gchar *p = NULL;
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h283_T_dataType, T_dataType_choice,
&data_type);
#line 35 "../../asn1/h283/h283.cnf"
p = try_val_to_str(data_type, VALS(h283_T_dataType_vals));
if (!info_is_set && p ) {
col_add_fstr(actx->pinfo->cinfo, COL_INFO, "RDCData/%s", p);
info_is_set = TRUE;
}
return offset;
}
static int
dissect_h283_RDCData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h283_RDCData, RDCData_sequence);
return offset;
}
static int
dissect_h283_T_pduType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 19 "../../asn1/h283/h283.cnf"
gint32 pdu_type = -1;
const gchar *p = NULL;
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h283_T_pduType, T_pduType_choice,
&pdu_type);
#line 22 "../../asn1/h283/h283.cnf"
p = try_val_to_str(pdu_type, VALS(h283_T_pduType_vals));
if (!info_is_set && p ) {
col_set_str(actx->pinfo->cinfo, COL_INFO, p);
info_is_set = TRUE;
}
return offset;
}
static int
dissect_h283_LCTPDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h283_LCTPDU, LCTPDU_sequence);
return offset;
}
static int dissect_LCTPDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_h283_LCTPDU(tvb, offset, &asn1_ctx, tree, hf_h283_LCTPDU_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int
dissect_h283_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti = NULL;
proto_tree *h283_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PSNAME);
info_is_set = FALSE;
ti = proto_tree_add_item(tree, proto_h283, tvb, 0, -1, ENC_NA);
h283_tree = proto_item_add_subtree(ti, ett_h283);
return dissect_LCTPDU_PDU(tvb, pinfo, h283_tree, NULL);
}
void proto_register_h283(void) {
static hf_register_info hf[] = {
#line 1 "../../asn1/h283/packet-h283-hfarr.c"
{ &hf_h283_LCTPDU_PDU,
{ "LCTPDU", "h283.LCTPDU_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h283_t35CountryCode,
{ "t35CountryCode", "h283.t35CountryCode",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_h283_t35Extension,
{ "t35Extension", "h283.t35Extension",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_h283_manufacturerCode,
{ "manufacturerCode", "h283.manufacturerCode",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_h283_object,
{ "object", "h283.object",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_h283_h221NonStandard,
{ "h221NonStandard", "h283.h221NonStandard_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h283_nonStandardIdentifier,
{ "nonStandardIdentifier", "h283.nonStandardIdentifier",
FT_UINT32, BASE_DEC, VALS(h283_NonStandardIdentifier_vals), 0,
NULL, HFILL }},
{ &hf_h283_data,
{ "data", "h283.data",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_h283_srcAddr,
{ "srcAddr", "h283.srcAddr_element",
FT_NONE, BASE_NONE, NULL, 0,
"MTAddress", HFILL }},
{ &hf_h283_dstAddr,
{ "dstAddr", "h283.dstAddr_element",
FT_NONE, BASE_NONE, NULL, 0,
"MTAddress", HFILL }},
{ &hf_h283_timestamp,
{ "timestamp", "h283.timestamp",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_h283_seqNumber,
{ "seqNumber", "h283.seqNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_h283_pduType,
{ "pduType", "h283.pduType",
FT_UINT32, BASE_DEC, VALS(h283_T_pduType_vals), 0,
NULL, HFILL }},
{ &hf_h283_ack,
{ "ack", "h283.ack_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h283_rdcData,
{ "rdcData", "h283.rdcData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h283_nonStandardParameters,
{ "nonStandardParameters", "h283.nonStandardParameters",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_NonStandardParameter", HFILL }},
{ &hf_h283_nonStandardParameters_item,
{ "NonStandardParameter", "h283.NonStandardParameter_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h283_mAddress,
{ "mAddress", "h283.mAddress",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_h283_tAddress,
{ "tAddress", "h283.tAddress",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_h283_reliable,
{ "reliable", "h283.reliable",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h283_dataType,
{ "dataType", "h283.dataType",
FT_UINT32, BASE_DEC, VALS(h283_T_dataType_vals), 0,
NULL, HFILL }},
{ &hf_h283_lctMessage,
{ "lctMessage", "h283.lctMessage",
FT_UINT32, BASE_DEC, VALS(h283_LCTMessage_vals), 0,
NULL, HFILL }},
{ &hf_h283_rdcPDU,
{ "rdcPDU", "h283.rdcPDU",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h283_lctRequest,
{ "lctRequest", "h283.lctRequest",
FT_UINT32, BASE_DEC, VALS(h283_LCTRequest_vals), 0,
NULL, HFILL }},
{ &hf_h283_lctResponse,
{ "lctResponse", "h283.lctResponse",
FT_UINT32, BASE_DEC, VALS(h283_LCTResponse_vals), 0,
NULL, HFILL }},
{ &hf_h283_lctIndication,
{ "lctIndication", "h283.lctIndication",
FT_UINT32, BASE_DEC, VALS(h283_LCTIndication_vals), 0,
NULL, HFILL }},
{ &hf_h283_nonStandardMessage,
{ "nonStandardMessage", "h283.nonStandardMessage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h283_announceReq,
{ "announceReq", "h283.announceReq_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h283_deviceListReq,
{ "deviceListReq", "h283.deviceListReq_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h283_announceResp,
{ "announceResp", "h283.announceResp_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h283_deviceListResp,
{ "deviceListResp", "h283.deviceListResp",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h283_deviceChange,
{ "deviceChange", "h283.deviceChange_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
#line 78 "../../asn1/h283/packet-h283-template.c"
};
static gint *ett[] = {
&ett_h283,
#line 1 "../../asn1/h283/packet-h283-ettarr.c"
&ett_h283_H221NonStandard,
&ett_h283_NonStandardIdentifier,
&ett_h283_NonStandardParameter,
&ett_h283_LCTPDU,
&ett_h283_T_pduType,
&ett_h283_SEQUENCE_OF_NonStandardParameter,
&ett_h283_MTAddress,
&ett_h283_RDCData,
&ett_h283_T_dataType,
&ett_h283_LCTMessage,
&ett_h283_LCTRequest,
&ett_h283_LCTResponse,
&ett_h283_LCTIndication,
&ett_h283_NonStandardMessage,
#line 84 "../../asn1/h283/packet-h283-template.c"
};
proto_h283 = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_h283, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector(PFNAME, dissect_h283_udp, proto_h283);
}
void proto_reg_handoff_h283(void)
{
dissector_handle_t h283_udp_handle;
h283_udp_handle = find_dissector(PFNAME);
dissector_add_handle("udp.port", h283_udp_handle);
rdc_pdu_handle = find_dissector("rdc");
rdc_device_list_handle = find_dissector("rdc.device_list");
data_handle = find_dissector("data");
}
