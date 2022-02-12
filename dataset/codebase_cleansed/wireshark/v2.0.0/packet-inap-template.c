static int
dissect_inap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "INAP");
if(parent_tree){
item = proto_tree_add_item(parent_tree, proto_inap, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_inap);
}
inap_pdu_type = tvb_get_guint8(tvb, offset)&0x0f;
inap_pdu_size = tvb_get_guint8(tvb, offset+1)+2;
opcode = 0;
dissect_inap_ROS(TRUE, tvb, offset, &asn1_ctx, tree, -1);
return inap_pdu_size;
}
static void range_delete_callback(guint32 ssn)
{
if (ssn) {
delete_itu_tcap_subdissector(ssn, inap_handle);
}
}
static void range_add_callback(guint32 ssn)
{
if (ssn) {
add_itu_tcap_subdissector(ssn, inap_handle);
}
}
void proto_reg_handoff_inap(void) {
static gboolean inap_prefs_initialized = FALSE;
static range_t *ssn_range;
if (!inap_prefs_initialized) {
inap_prefs_initialized = TRUE;
inap_handle = find_dissector("inap");
data_handle = find_dissector("data");
oid_add_from_string("Core-INAP-CS1-Codes","0.4.0.1.1.0.3.0");
oid_add_from_string("iso(1) identified-organization(3) icd-ecma(12) member-company(2) 1107 oen(3) inap(3) extensions(2)","1.3.12.2.1107.3.3.2");
oid_add_from_string("alcatel(1006)","1.3.12.2.1006.64");
oid_add_from_string("Siemens (1107)","1.3.12.2.1107");
oid_add_from_string("iso(1) member-body(2) gb(826) national(0) ericsson(1249) inDomain(51) inNetwork(1) inNetworkcapabilitySet1plus(1) ","1.2.826.0.1249.51.1.1");
}
else {
range_foreach(ssn_range, range_delete_callback);
g_free(ssn_range);
}
ssn_range = range_copy(global_ssn_range);
range_foreach(ssn_range, range_add_callback);
}
void proto_register_inap(void) {
module_t *inap_module;
static hf_register_info hf[] = {
{ &hf_inap_cause_indicator,
{ "Cause indicator", "inap.cause_indicator",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &q850_cause_code_vals_ext, 0x7f,
NULL, HFILL } },
#include "packet-inap-hfarr.c"
};
static gint *ett[] = {
&ett_inap,
&ett_inapisup_parameter,
&ett_inap_HighLayerCompatibility,
&ett_inap_extention_data,
&ett_inap_cause,
#include "packet-inap-ettarr.c"
};
static ei_register_info ei[] = {
{ &ei_inap_unknown_invokeData, { "inap.unknown.invokeData", PI_MALFORMED, PI_WARN, "Unknown invokeData", EXPFILL }},
{ &ei_inap_unknown_returnResultData, { "inap.unknown.returnResultData", PI_MALFORMED, PI_WARN, "Unknown returnResultData", EXPFILL }},
{ &ei_inap_unknown_returnErrorData, { "inap.unknown.returnErrorData", PI_MALFORMED, PI_WARN, "Unknown returnResultData", EXPFILL }},
};
expert_module_t* expert_inap;
proto_inap = proto_register_protocol(PNAME, PSNAME, PFNAME);
new_register_dissector("inap", dissect_inap, proto_inap);
proto_register_field_array(proto_inap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_inap = expert_register_protocol(proto_inap);
expert_register_field_array(expert_inap, ei, array_length(ei));
new_register_ber_oid_dissector("0.4.0.1.1.1.0.0", dissect_inap, proto_inap, "cs1-ssp-to-scp");
range_convert_str(&global_ssn_range, "106,241", MAX_SSN);
inap_module = prefs_register_protocol(proto_inap, proto_reg_handoff_inap);
prefs_register_obsolete_preference(inap_module, "tcap.itu_ssn");
prefs_register_obsolete_preference(inap_module, "tcap.itu_ssn1");
prefs_register_range_preference(inap_module, "ssn", "TCAP SSNs",
"TCAP Subsystem numbers used for INAP",
&global_ssn_range, MAX_SSN);
}
