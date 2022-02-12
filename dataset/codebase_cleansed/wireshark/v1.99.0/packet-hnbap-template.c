static int dissect_ProtocolIEFieldValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(hnbap_ies_dissector_table, ProtocolIE_ID, tvb, pinfo, tree, FALSE, NULL)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_ProtocolExtensionFieldExtensionValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(hnbap_extension_dissector_table, ProtocolIE_ID, tvb, pinfo, tree, FALSE, NULL)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_InitiatingMessageValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(hnbap_proc_imsg_dissector_table, ProcedureCode, tvb, pinfo, tree, FALSE, NULL)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_SuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(hnbap_proc_sout_dissector_table, ProcedureCode, tvb, pinfo, tree, FALSE, NULL)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_UnsuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(hnbap_proc_uout_dissector_table, ProcedureCode, tvb, pinfo, tree, FALSE, NULL)) ? tvb_captured_length(tvb) : 0;
}
static void
dissect_hnbap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *hnbap_item = NULL;
proto_tree *hnbap_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HNBAP");
hnbap_item = proto_tree_add_item(tree, proto_hnbap, tvb, 0, -1, ENC_NA);
hnbap_tree = proto_item_add_subtree(hnbap_item, ett_hnbap);
dissect_HNBAP_PDU_PDU(tvb, pinfo, hnbap_tree);
}
void proto_register_hnbap(void) {
module_t *hnbap_module;
static hf_register_info hf[] = {
#include "packet-hnbap-hfarr.c"
};
static gint *ett[] = {
&ett_hnbap,
#include "packet-hnbap-ettarr.c"
};
proto_hnbap = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_hnbap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("hnbap", dissect_hnbap, proto_hnbap);
hnbap_ies_dissector_table = register_dissector_table("hnbap.ies", "HNBAP-PROTOCOL-IES", FT_UINT32, BASE_DEC);
hnbap_extension_dissector_table = register_dissector_table("hnbap.extension", "HNBAP-PROTOCOL-EXTENSION", FT_UINT32, BASE_DEC);
hnbap_proc_imsg_dissector_table = register_dissector_table("hnbap.proc.imsg", "HNBAP-ELEMENTARY-PROCEDURE InitiatingMessage", FT_UINT32, BASE_DEC);
hnbap_proc_sout_dissector_table = register_dissector_table("hnbap.proc.sout", "HNBAP-ELEMENTARY-PROCEDURE SuccessfulOutcome", FT_UINT32, BASE_DEC);
hnbap_proc_uout_dissector_table = register_dissector_table("hnbap.proc.uout", "HNBAP-ELEMENTARY-PROCEDURE UnsuccessfulOutcome", FT_UINT32, BASE_DEC);
hnbap_module = prefs_register_protocol(proto_hnbap, proto_reg_handoff_hnbap);
prefs_register_uint_preference(hnbap_module, "port", "HNBAP SCTP Port", "Set the port for HNBAP messages (Default of 29169)", 10, &global_sctp_port);
}
void
proto_reg_handoff_hnbap(void)
{
static gboolean initialized = FALSE;
static dissector_handle_t hnbap_handle;
static guint sctp_port;
if (!initialized) {
hnbap_handle = find_dissector("hnbap");
dissector_add_uint("sctp.ppi", HNBAP_PAYLOAD_PROTOCOL_ID, hnbap_handle);
initialized = TRUE;
#include "packet-hnbap-dis-tab.c"
} else {
dissector_delete_uint("sctp.port", sctp_port, hnbap_handle);
}
sctp_port = global_sctp_port;
dissector_add_uint("sctp.port", sctp_port, hnbap_handle);
}
