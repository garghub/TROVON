static int dissect_ProtocolIEFieldValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(lcsap_ies_dissector_table, ProtocolIE_ID, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_ProtocolExtensionFieldExtensionValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(lcsap_extension_dissector_table, ProtocolExtensionID, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_InitiatingMessageValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(lcsap_proc_imsg_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_SuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(lcsap_proc_sout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_UnsuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(lcsap_proc_uout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int
dissect_lcsap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *lcsap_item = NULL;
proto_tree *lcsap_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LCSAP");
lcsap_item = proto_tree_add_item(tree, proto_lcsap, tvb, 0, -1, ENC_NA);
lcsap_tree = proto_item_add_subtree(lcsap_item, ett_lcsap);
dissect_LCS_AP_PDU_PDU(tvb, pinfo, lcsap_tree, NULL);
return tvb_captured_length(tvb);
}
void
proto_reg_handoff_lcsap(void)
{
static gboolean Initialized=FALSE;
static guint SctpPort;
if (!Initialized) {
lpp_handle = find_dissector_add_dependency("lpp", proto_lcsap);
lppa_handle = find_dissector_add_dependency("lppa", proto_lcsap);
dissector_add_for_decode_as("sctp.port", lcsap_handle);
dissector_add_uint("sctp.ppi", LCS_AP_PAYLOAD_PROTOCOL_ID, lcsap_handle);
Initialized=TRUE;
#include "packet-lcsap-dis-tab.c"
} else {
if (SctpPort != 0) {
dissector_delete_uint("sctp.port", SctpPort, lcsap_handle);
}
}
SctpPort=gbl_lcsapSctpPort;
if (SctpPort != 0) {
dissector_add_uint("sctp.port", SctpPort, lcsap_handle);
}
}
void proto_register_lcsap(void) {
static hf_register_info hf[] = {
{ &hf_lcsap_pos_method,
{ "Positioning Method", "lcsap.pos_method",
FT_UINT8, BASE_DEC, VALS(lcsap_pos_method_vals), 0xf8,
NULL, HFILL }
},
{ &hf_lcsap_pos_usage,
{ "Positioning usage", "lcsap.pos_usage",
FT_UINT8, BASE_DEC, VALS(lcsap_pos_usage_vals), 0x07,
NULL, HFILL }
},
{ &hf_lcsap_gnss_pos_method,
{ "GNSS Positioning Method", "lcsap.gnss_pos_method",
FT_UINT8, BASE_DEC, VALS(lcsap_gnss_pos_method_vals), 0xc0,
NULL, HFILL }
},
{ &hf_lcsap_gnss_id,
{ "GNSS ID", "lcsap.gnss_id",
FT_UINT8, BASE_DEC, VALS(lcsap_gnss_id_vals), 0x38,
NULL, HFILL }
},
{ &hf_lcsap_gnss_pos_usage,
{ "GNSS Positioning usage", "lcsap.gnss_pos_usage",
FT_UINT8, BASE_DEC, VALS(lcsap_gnss_pos_usage_vals), 0x07,
NULL, HFILL }
},
#include "packet-lcsap-hfarr.c"
};
static gint *ett[] = {
&ett_lcsap,
&ett_lcsap_plmnd_id,
&ett_lcsap_imsi,
&ett_lcsap_civic_address,
#include "packet-lcsap-ettarr.c"
};
module_t *lcsap_module;
expert_module_t *expert_lcsap;
static ei_register_info ei[] = {
{ &ei_lcsap_civic_data_not_xml,
{ "lcsap.civic_data_not_xml", PI_PROTOCOL, PI_ERROR, "Shold contain a UTF-8 encoded PIDF - LO XML document as defined in IETF RFC 4119", EXPFILL } },
};
proto_lcsap = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_lcsap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
lcsap_handle = register_dissector("lcsap", dissect_lcsap, proto_lcsap);
lcsap_ies_dissector_table = register_dissector_table("lcsap.ies", "LCS-AP-PROTOCOL-IES", proto_lcsap, FT_UINT32, BASE_DEC);
expert_lcsap = expert_register_protocol(proto_lcsap);
expert_register_field_array(expert_lcsap, ei, array_length(ei));
lcsap_extension_dissector_table = register_dissector_table("lcsap.extension", "LCS-AP-PROTOCOL-EXTENSION", proto_lcsap, FT_UINT32, BASE_DEC);
lcsap_proc_imsg_dissector_table = register_dissector_table("lcsap.proc.imsg", "LCS-AP-ELEMENTARY-PROCEDURE InitiatingMessage", proto_lcsap, FT_UINT32, BASE_DEC);
lcsap_proc_sout_dissector_table = register_dissector_table("lcsap.proc.sout", "LCS-AP-ELEMENTARY-PROCEDURE SuccessfulOutcome", proto_lcsap, FT_UINT32, BASE_DEC);
lcsap_proc_uout_dissector_table = register_dissector_table("lcsap.proc.uout", "LCS-AP-ELEMENTARY-PROCEDURE UnsuccessfulOutcome", proto_lcsap, FT_UINT32, BASE_DEC);
lcsap_module = prefs_register_protocol(proto_lcsap, proto_reg_handoff_lcsap);
prefs_register_uint_preference(lcsap_module, "sctp.port",
"LCSAP SCTP Port",
"Set the SCTP port for LCSAP messages",
10,
&gbl_lcsapSctpPort);
xml_handle = find_dissector_add_dependency("xml", proto_lcsap);
}
