static int
dissect_t125_DataPriority(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_t125_INTEGER_0_MAX(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_t125_DomainParameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DomainParameters_sequence, hf_index, ett_t125_DomainParameters);
return offset;
}
static int
dissect_t125_OCTET_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_t125_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_t125_T_userData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 98 "../../asn1/t125/t125.cnf"
tvbuff_t *next_tvb = NULL;
heur_dtbl_entry_t *hdtbl_entry;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&next_tvb);
if(next_tvb)
dissector_try_heuristic(t125_heur_subdissector_list, next_tvb,
actx->pinfo, top_tree, &hdtbl_entry, NULL);
return offset;
}
static int
dissect_t125_Connect_Initial_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Connect_Initial_U_sequence, hf_index, ett_t125_Connect_Initial_U);
return offset;
}
static int
dissect_t125_Connect_Initial(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 101, TRUE, dissect_t125_Connect_Initial_U);
return offset;
}
static int
dissect_t125_Result(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_t125_T_userData_01(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 108 "../../asn1/t125/t125.cnf"
tvbuff_t *next_tvb = NULL;
heur_dtbl_entry_t *hdtbl_entry;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&next_tvb);
if(next_tvb)
dissector_try_heuristic(t125_heur_subdissector_list, next_tvb,
actx->pinfo, top_tree, &hdtbl_entry, NULL);
return offset;
}
static int
dissect_t125_Connect_Response_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Connect_Response_U_sequence, hf_index, ett_t125_Connect_Response_U);
return offset;
}
static int
dissect_t125_Connect_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 102, TRUE, dissect_t125_Connect_Response_U);
return offset;
}
static int
dissect_t125_Connect_Additional_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Connect_Additional_U_sequence, hf_index, ett_t125_Connect_Additional_U);
return offset;
}
static int
dissect_t125_Connect_Additional(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 103, TRUE, dissect_t125_Connect_Additional_U);
return offset;
}
static int
dissect_t125_Connect_Result_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Connect_Result_U_sequence, hf_index, ett_t125_Connect_Result_U);
return offset;
}
static int
dissect_t125_Connect_Result(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 104, TRUE, dissect_t125_Connect_Result_U);
return offset;
}
static int
dissect_t125_ConnectMCSPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ConnectMCSPDU_choice, hf_index, ett_t125_ConnectMCSPDU,
NULL);
return offset;
}
static int dissect_ConnectMCSPDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_t125_ConnectMCSPDU(FALSE, tvb, offset, &asn1_ctx, tree, hf_t125_ConnectMCSPDU_PDU);
return offset;
}
static int
dissect_t125(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
gint8 ber_class;
gboolean pc;
gint32 tag;
top_tree = parent_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "T.125");
col_clear(pinfo->cinfo, COL_INFO);
item = proto_tree_add_item(parent_tree, proto_t125, tvb, 0, tvb_captured_length(tvb), ENC_NA);
tree = proto_item_add_subtree(item, ett_t125);
get_ber_identifier(tvb, 0, &ber_class, &pc, &tag);
if ( (ber_class==BER_CLASS_APP) && (tag>=101) && (tag<=104) ){
dissect_ConnectMCSPDU_PDU(tvb, pinfo, tree, NULL);
} else {
t124_set_top_tree(top_tree);
dissect_DomainMCSPDU_PDU(tvb, pinfo, tree);
}
return tvb_captured_length(tvb);
}
static gboolean
dissect_t125_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
gint8 ber_class;
gboolean pc;
gint32 tag;
volatile gboolean failed;
failed = FALSE;
TRY {
get_ber_identifier(tvb, 0, &ber_class, &pc, &tag);
} CATCH_BOUNDS_ERRORS {
failed = TRUE;
} ENDTRY;
if (!failed && ((ber_class==BER_CLASS_APP) && ((tag>=101) && (tag<=104)))) {
dissect_t125(tvb, pinfo, parent_tree, NULL);
return TRUE;
}
return FALSE;
}
void proto_register_t125(void) {
static hf_register_info hf[] = {
#line 1 "../../asn1/t125/packet-t125-hfarr.c"
{ &hf_t125_ConnectMCSPDU_PDU,
{ "ConnectMCSPDU", "t125.ConnectMCSPDU",
FT_UINT32, BASE_DEC, VALS(t125_ConnectMCSPDU_vals), 0,
NULL, HFILL }},
{ &hf_t125_maxChannelIds,
{ "maxChannelIds", "t125.maxChannelIds",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_MAX", HFILL }},
{ &hf_t125_maxUserIds,
{ "maxUserIds", "t125.maxUserIds",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_MAX", HFILL }},
{ &hf_t125_maxTokenIds,
{ "maxTokenIds", "t125.maxTokenIds",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_MAX", HFILL }},
{ &hf_t125_numPriorities,
{ "numPriorities", "t125.numPriorities",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_MAX", HFILL }},
{ &hf_t125_minThroughput,
{ "minThroughput", "t125.minThroughput",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_MAX", HFILL }},
{ &hf_t125_maxHeight,
{ "maxHeight", "t125.maxHeight",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_MAX", HFILL }},
{ &hf_t125_maxMCSPDUsize,
{ "maxMCSPDUsize", "t125.maxMCSPDUsize",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_MAX", HFILL }},
{ &hf_t125_protocolVersion,
{ "protocolVersion", "t125.protocolVersion",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_MAX", HFILL }},
{ &hf_t125_callingDomainSelector,
{ "callingDomainSelector", "t125.callingDomainSelector",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_t125_calledDomainSelector,
{ "calledDomainSelector", "t125.calledDomainSelector",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_t125_upwardFlag,
{ "upwardFlag", "t125.upwardFlag",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_t125_targetParameters,
{ "targetParameters", "t125.targetParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"DomainParameters", HFILL }},
{ &hf_t125_minimumParameters,
{ "minimumParameters", "t125.minimumParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"DomainParameters", HFILL }},
{ &hf_t125_maximumParameters,
{ "maximumParameters", "t125.maximumParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"DomainParameters", HFILL }},
{ &hf_t125_userData,
{ "userData", "t125.userData",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t125_result,
{ "result", "t125.result",
FT_UINT32, BASE_DEC, VALS(t125_Result_vals), 0,
NULL, HFILL }},
{ &hf_t125_calledConnectId,
{ "calledConnectId", "t125.calledConnectId",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_MAX", HFILL }},
{ &hf_t125_domainParameters,
{ "domainParameters", "t125.domainParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t125_userData_01,
{ "userData", "t125.userData",
FT_BYTES, BASE_NONE, NULL, 0,
"T_userData_01", HFILL }},
{ &hf_t125_dataPriority,
{ "dataPriority", "t125.dataPriority",
FT_UINT32, BASE_DEC, VALS(t125_DataPriority_vals), 0,
NULL, HFILL }},
{ &hf_t125_connect_initial,
{ "connect-initial", "t125.connect_initial_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t125_connect_response,
{ "connect-response", "t125.connect_response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t125_connect_additional,
{ "connect-additional", "t125.connect_additional_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t125_connect_result,
{ "connect-result", "t125.connect_result_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
#line 127 "../../asn1/t125/packet-t125-template.c"
};
static gint *ett[] = {
&ett_t125,
#line 1 "../../asn1/t125/packet-t125-ettarr.c"
&ett_t125_DomainParameters,
&ett_t125_Connect_Initial_U,
&ett_t125_Connect_Response_U,
&ett_t125_Connect_Additional_U,
&ett_t125_Connect_Result_U,
&ett_t125_ConnectMCSPDU,
#line 133 "../../asn1/t125/packet-t125-template.c"
};
proto_t125 = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_t125, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_heur_dissector_list("t125", &t125_heur_subdissector_list);
new_register_dissector("t125", dissect_t125, proto_t125);
}
void proto_reg_handoff_t125(void) {
heur_dissector_add("cotp", dissect_t125_heur, proto_t125);
heur_dissector_add("cotp_is", dissect_t125_heur, proto_t125);
}
