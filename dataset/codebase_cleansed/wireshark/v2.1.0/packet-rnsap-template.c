static int dissect_ProtocolIEFieldValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(rnsap_ies_dissector_table, ProtocolIE_ID, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_ProtocolExtensionFieldExtensionValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(rnsap_extension_dissector_table, ProtocolIE_ID, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_PrivateIEFieldValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (call_ber_oid_callback(obj_id, tvb, 0, pinfo, tree, NULL)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_InitiatingMessageValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
if (!ProcedureID) return 0;
return (dissector_try_string(rnsap_proc_imsg_dissector_table, ProcedureID, tvb, pinfo, tree, NULL)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_SuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
if (!ProcedureID) return 0;
return (dissector_try_string(rnsap_proc_sout_dissector_table, ProcedureID, tvb, pinfo, tree, NULL)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_UnsuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
if (!ProcedureID) return 0;
return (dissector_try_string(rnsap_proc_uout_dissector_table, ProcedureID, tvb, pinfo, tree, NULL)) ? tvb_captured_length(tvb) : 0;
}
static int
dissect_rnsap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
proto_item *rnsap_item = NULL;
proto_tree *rnsap_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RNSAP");
rnsap_item = proto_tree_add_item(tree, proto_rnsap, tvb, 0, -1, ENC_NA);
rnsap_tree = proto_item_add_subtree(rnsap_item, ett_rnsap);
return dissect_RNSAP_PDU_PDU(tvb, pinfo, rnsap_tree, data);
}
void proto_register_rnsap(void) {
static hf_register_info hf[] = {
#include "packet-rnsap-hfarr.c"
};
static gint *ett[] = {
&ett_rnsap,
#include "packet-rnsap-ettarr.c"
};
proto_rnsap = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_rnsap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("rnsap", dissect_rnsap, proto_rnsap);
rnsap_ies_dissector_table = register_dissector_table("rnsap.ies", "RNSAP-PROTOCOL-IES", proto_rnsap, FT_UINT32, BASE_DEC, DISSECTOR_TABLE_ALLOW_DUPLICATE);
rnsap_extension_dissector_table = register_dissector_table("rnsap.extension", "RNSAP-PROTOCOL-EXTENSION", proto_rnsap, FT_UINT32, BASE_DEC, DISSECTOR_TABLE_ALLOW_DUPLICATE);
rnsap_proc_imsg_dissector_table = register_dissector_table("rnsap.proc.imsg", "RNSAP-ELEMENTARY-PROCEDURE InitiatingMessage", proto_rnsap, FT_STRING, BASE_NONE, DISSECTOR_TABLE_ALLOW_DUPLICATE);
rnsap_proc_sout_dissector_table = register_dissector_table("rnsap.proc.sout", "RNSAP-ELEMENTARY-PROCEDURE SuccessfulOutcome", proto_rnsap, FT_STRING, BASE_NONE, DISSECTOR_TABLE_ALLOW_DUPLICATE);
rnsap_proc_uout_dissector_table = register_dissector_table("rnsap.proc.uout", "RNSAP-ELEMENTARY-PROCEDURE UnsuccessfulOutcome", proto_rnsap, FT_STRING, BASE_NONE, DISSECTOR_TABLE_ALLOW_DUPLICATE);
}
void
proto_reg_handoff_rnsap(void)
{
dissector_handle_t rnsap_handle;
rnsap_handle = find_dissector("rnsap");
rrc_dl_dcch_handle = find_dissector_add_dependency("rrc.dl.dcch", proto_rnsap);
dissector_add_uint("sccp.ssn", SCCP_SSN_RNSAP, rnsap_handle);
#include "packet-rnsap-dis-tab.c"
}
