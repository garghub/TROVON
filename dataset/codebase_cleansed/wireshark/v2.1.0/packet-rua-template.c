static int dissect_ProtocolIEFieldValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(rua_ies_dissector_table, ProtocolIE_ID, tvb, pinfo, tree, FALSE, NULL)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_ProtocolExtensionFieldExtensionValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(rua_extension_dissector_table, ProtocolIE_ID, tvb, pinfo, tree, FALSE, NULL)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_InitiatingMessageValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(rua_proc_imsg_dissector_table, ProcedureCode, tvb, pinfo, tree, FALSE, NULL)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_SuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(rua_proc_sout_dissector_table, ProcedureCode, tvb, pinfo, tree, FALSE, NULL)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_UnsuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(rua_proc_uout_dissector_table, ProcedureCode, tvb, pinfo, tree, FALSE, NULL)) ? tvb_captured_length(tvb) : 0;
}
static int
dissect_rua(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
proto_item *rua_item = NULL;
proto_tree *rua_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RUA");
rua_item = proto_tree_add_item(tree, proto_rua, tvb, 0, -1, ENC_NA);
rua_tree = proto_item_add_subtree(rua_item, ett_rua);
return dissect_RUA_PDU_PDU(tvb, pinfo, rua_tree, data);
}
void proto_register_rua(void) {
module_t *rua_module;
static hf_register_info hf[] = {
#include "packet-rua-hfarr.c"
};
static gint *ett[] = {
&ett_rua,
#include "packet-rua-ettarr.c"
};
proto_rua = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_rua, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("rua", dissect_rua, proto_rua);
rua_ies_dissector_table = register_dissector_table("rua.ies", "RUA-PROTOCOL-IES", proto_rua, FT_UINT32, BASE_DEC, DISSECTOR_TABLE_ALLOW_DUPLICATE);
rua_extension_dissector_table = register_dissector_table("rua.extension", "RUA-PROTOCOL-EXTENSION", proto_rua, FT_UINT32, BASE_DEC, DISSECTOR_TABLE_ALLOW_DUPLICATE);
rua_proc_imsg_dissector_table = register_dissector_table("rua.proc.imsg", "RUA-ELEMENTARY-PROCEDURE InitiatingMessage", proto_rua, FT_UINT32, BASE_DEC, DISSECTOR_TABLE_ALLOW_DUPLICATE);
rua_proc_sout_dissector_table = register_dissector_table("rua.proc.sout", "RUA-ELEMENTARY-PROCEDURE SuccessfulOutcome", proto_rua, FT_UINT32, BASE_DEC, DISSECTOR_TABLE_ALLOW_DUPLICATE);
rua_proc_uout_dissector_table = register_dissector_table("rua.proc.uout", "RUA-ELEMENTARY-PROCEDURE UnsuccessfulOutcome", proto_rua, FT_UINT32, BASE_DEC, DISSECTOR_TABLE_ALLOW_DUPLICATE);
rua_module = prefs_register_protocol(proto_rua, proto_reg_handoff_rua);
prefs_register_uint_preference(rua_module, "port", "RUA SCTP Port", "Set the port for RUA messages (Default of 29169)", 10, &global_sctp_port);
}
void
proto_reg_handoff_rua(void)
{
static gboolean initialized = FALSE;
static dissector_handle_t rua_handle;
static guint sctp_port;
if (!initialized) {
rua_handle = find_dissector("rua");
ranap_handle = find_dissector_add_dependency("ranap", proto_rua);
dissector_add_uint("sctp.ppi", RUA_PAYLOAD_PROTOCOL_ID, rua_handle);
initialized = TRUE;
#include "packet-rua-dis-tab.c"
} else {
dissector_delete_uint("sctp.port", sctp_port, rua_handle);
}
sctp_port = global_sctp_port;
dissector_add_uint("sctp.port", sctp_port, rua_handle);
}
