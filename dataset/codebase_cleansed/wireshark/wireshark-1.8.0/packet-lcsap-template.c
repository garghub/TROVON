static int dissect_ProtocolIEFieldValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
return (dissector_try_uint(lcsap_ies_dissector_table, ProtocolIE_ID, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_ProtocolExtensionFieldExtensionValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
return (dissector_try_uint(lcsap_extension_dissector_table, ProtocolExtensionID, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_InitiatingMessageValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
return (dissector_try_uint(lcsap_proc_imsg_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_SuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
return (dissector_try_uint(lcsap_proc_sout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_UnsuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
return (dissector_try_uint(lcsap_proc_uout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static void
dissect_lcsap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *lcsap_item = NULL;
proto_tree *lcsap_tree = NULL;
if (check_col(pinfo->cinfo, COL_PROTOCOL))
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LCSAP");
lcsap_item = proto_tree_add_item(tree, proto_lcsap, tvb, 0, -1, ENC_NA);
lcsap_tree = proto_item_add_subtree(lcsap_item, ett_lcsap);
dissect_LCS_AP_PDU_PDU(tvb, pinfo, lcsap_tree);
}
void
proto_reg_handoff_lcsap(void)
{
static gboolean Initialized=FALSE;
static dissector_handle_t lcsap_handle;
static guint SctpPort;
if (!Initialized) {
lcsap_handle = find_dissector("lcsap");
lpp_handle = find_dissector("lpp");
lppa_handle = find_dissector("lppa");
dissector_add_handle("sctp.port", lcsap_handle);
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
#include "packet-lcsap-hfarr.c"
};
static gint *ett[] = {
&ett_lcsap,
#include "packet-lcsap-ettarr.c"
};
module_t *lcsap_module;
proto_lcsap = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_lcsap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("lcsap", dissect_lcsap, proto_lcsap);
lcsap_ies_dissector_table = register_dissector_table("lcsap.ies", "LCS-AP-PROTOCOL-IES", FT_UINT32, BASE_DEC);
lcsap_extension_dissector_table = register_dissector_table("lcsap.extension", "LCS-AP-PROTOCOL-EXTENSION", FT_UINT32, BASE_DEC);
lcsap_proc_imsg_dissector_table = register_dissector_table("lcsap.proc.imsg", "LCS-AP-ELEMENTARY-PROCEDURE InitiatingMessage", FT_UINT32, BASE_DEC);
lcsap_proc_sout_dissector_table = register_dissector_table("lcsap.proc.sout", "LCS-AP-ELEMENTARY-PROCEDURE SuccessfulOutcome", FT_UINT32, BASE_DEC);
lcsap_proc_uout_dissector_table = register_dissector_table("lcsap.proc.uout", "LCS-AP-ELEMENTARY-PROCEDURE UnsuccessfulOutcome", FT_UINT32, BASE_DEC);
lcsap_module = prefs_register_protocol(proto_lcsap, proto_reg_handoff_lcsap);
prefs_register_uint_preference(lcsap_module, "sctp.port",
"LCSAP SCTP Port",
"Set the SCTP port for LCSAP messages",
10,
&gbl_lcsapSctpPort);
}
