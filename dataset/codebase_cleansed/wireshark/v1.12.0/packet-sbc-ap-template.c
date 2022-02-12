static int dissect_ProtocolIEFieldValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(sbc_ap_ies_dissector_table, ProtocolIE_ID, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_ProtocolExtensionFieldExtensionValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(sbc_ap_extension_dissector_table, ProtocolExtensionID, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_InitiatingMessageValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(sbc_ap_proc_imsg_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_SuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(sbc_ap_proc_sout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_UnsuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(sbc_ap_proc_uout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static void
dissect_sbc_ap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *sbc_ap_item = NULL;
proto_tree *sbc_ap_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PNAME);
if (tree) {
sbc_ap_item = proto_tree_add_item(tree, proto_sbc_ap, tvb, 0, -1, ENC_NA);
sbc_ap_tree = proto_item_add_subtree(sbc_ap_item, ett_sbc_ap);
dissect_SBC_AP_PDU_PDU(tvb, pinfo, sbc_ap_tree, NULL);
}
}
void proto_register_sbc_ap(void) {
static hf_register_info hf[] = {
#include "packet-sbc-ap-hfarr.c"
};
static gint *ett[] = {
&ett_sbc_ap,
#include "packet-sbc-ap-ettarr.c"
};
proto_sbc_ap = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_sbc_ap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
sbc_ap_ies_dissector_table = register_dissector_table("sbc_ap.ies", "SBC-AP-PROTOCOL-IES", FT_UINT32, BASE_DEC);
sbc_ap_extension_dissector_table = register_dissector_table("sbc_ap.extension", "SBC-AP-PROTOCOL-EXTENSION", FT_UINT32, BASE_DEC);
sbc_ap_proc_imsg_dissector_table = register_dissector_table("sbc_ap.proc.imsg", "SBC-AP-ELEMENTARY-PROCEDURE InitiatingMessage", FT_UINT32, BASE_DEC);
sbc_ap_proc_sout_dissector_table = register_dissector_table("sbc_ap.proc.sout", "SBC-AP-ELEMENTARY-PROCEDURE SuccessfulOutcome", FT_UINT32, BASE_DEC);
sbc_ap_proc_uout_dissector_table = register_dissector_table("sbc_ap.proc.uout", "SBC-AP-ELEMENTARY-PROCEDURE UnsuccessfulOutcome", FT_UINT32, BASE_DEC);
}
void
proto_reg_handoff_sbc_ap(void)
{
static gboolean inited = FALSE;
static guint SctpPort;
if( !inited ) {
sbc_ap_handle = create_dissector_handle(dissect_sbc_ap, proto_sbc_ap);
dissector_add_uint("sctp.ppi", SBC_AP_PAYLOAD_PROTOCOL_ID, sbc_ap_handle);
inited = TRUE;
#include "packet-sbc-ap-dis-tab.c"
} else {
if (SctpPort != 0) {
dissector_delete_uint("sctp.port", SctpPort, sbc_ap_handle);
}
}
SctpPort = global_sbc_ap_port;
if (SctpPort != 0) {
dissector_add_uint("sctp.port", SctpPort, sbc_ap_handle);
}
}
