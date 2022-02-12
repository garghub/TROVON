static int dissect_ProtocolIEFieldValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(pcap_ies_dissector_table, ProtocolIE_ID, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_ProtocolExtensionFieldExtensionValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(pcap_extension_dissector_table, ProtocolExtensionID, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_InitiatingMessageValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(pcap_proc_imsg_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_SuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(pcap_proc_sout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_UnsuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(pcap_proc_uout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_OutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(pcap_proc_out_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static void
dissect_pcap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *pcap_item = NULL;
proto_tree *pcap_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PCAP");
pcap_item = proto_tree_add_item(tree, proto_pcap, tvb, 0, -1, ENC_NA);
pcap_tree = proto_item_add_subtree(pcap_item, ett_pcap);
dissect_PCAP_PDU_PDU(tvb, pinfo, pcap_tree, NULL);
}
static void range_delete_callback(guint32 ssn)
{
if ( ssn ) {
dissector_delete_uint("sccp.ssn", ssn, pcap_handle);
}
}
static void range_add_callback(guint32 ssn)
{
if (ssn) {
dissector_add_uint("sccp.ssn", ssn, pcap_handle);
}
}
void
proto_reg_handoff_pcap(void)
{
static gboolean prefs_initialized = FALSE;
static range_t *ssn_range;
if (! prefs_initialized) {
pcap_handle = find_dissector("pcap");
sccp_ssn_table = find_dissector_table("sccp.ssn");
prefs_initialized = TRUE;
#include "packet-pcap-dis-tab.c"
} else {
range_foreach(ssn_range, range_delete_callback);
g_free(ssn_range);
}
ssn_range = range_copy(global_ssn_range);
range_foreach(ssn_range, range_add_callback);
}
void proto_register_pcap(void) {
static hf_register_info hf[] = {
#include "packet-pcap-hfarr.c"
};
static gint *ett[] = {
&ett_pcap,
#include "packet-pcap-ettarr.c"
};
module_t *pcap_module;
proto_pcap = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_pcap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
pcap_module = prefs_register_protocol(proto_pcap, proto_reg_handoff_pcap);
register_dissector("pcap", dissect_pcap, proto_pcap);
pcap_ies_dissector_table = register_dissector_table("pcap.ies", "PCAP-PROTOCOL-IES", FT_UINT32, BASE_DEC);
pcap_ies_p1_dissector_table = register_dissector_table("pcap.ies.pair.first", "PCAP-PROTOCOL-IES-PAIR FirstValue", FT_UINT32, BASE_DEC);
pcap_ies_p2_dissector_table = register_dissector_table("pcap.ies.pair.second", "PCAP-PROTOCOL-IES-PAIR SecondValue", FT_UINT32, BASE_DEC);
pcap_extension_dissector_table = register_dissector_table("pcap.extension", "PCAP-PROTOCOL-EXTENSION", FT_UINT32, BASE_DEC);
pcap_proc_imsg_dissector_table = register_dissector_table("pcap.proc.imsg", "PCAP-ELEMENTARY-PROCEDURE InitiatingMessage", FT_UINT32, BASE_DEC);
pcap_proc_sout_dissector_table = register_dissector_table("pcap.proc.sout", "PCAP-ELEMENTARY-PROCEDURE SuccessfulOutcome", FT_UINT32, BASE_DEC);
pcap_proc_uout_dissector_table = register_dissector_table("pcap.proc.uout", "PCAP-ELEMENTARY-PROCEDURE UnsuccessfulOutcome", FT_UINT32, BASE_DEC);
pcap_proc_out_dissector_table = register_dissector_table("pcap.proc.out", "PCAP-ELEMENTARY-PROCEDURE Outcome", FT_UINT32, BASE_DEC);
range_convert_str(&global_ssn_range, "", MAX_SSN);
prefs_register_range_preference(pcap_module, "ssn", "SCCP SSNs",
"SCCP (and SUA) SSNs to decode as PCAP",
&global_ssn_range, MAX_SSN);
}
