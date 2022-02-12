static int dissect_ProtocolIEFieldValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
return (dissector_try_uint(m3ap_ies_dissector_table, ProtocolIE_ID, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_ProtocolExtensionFieldExtensionValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
return (dissector_try_uint(m3ap_extension_dissector_table, ProtocolIE_ID, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_InitiatingMessageValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
return (dissector_try_uint(m3ap_proc_imsg_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_SuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
return (dissector_try_uint(m3ap_proc_sout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_UnsuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
return (dissector_try_uint(m3ap_proc_uout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static void
dissect_m3ap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *m3ap_item = NULL;
proto_tree *m3ap_tree = NULL;
if (check_col(pinfo->cinfo, COL_PROTOCOL))
col_set_str(pinfo->cinfo, COL_PROTOCOL, PNAME);
if (tree) {
m3ap_item = proto_tree_add_item(tree, proto_m3ap, tvb, 0, -1, ENC_NA);
m3ap_tree = proto_item_add_subtree(m3ap_item, ett_m3ap);
dissect_M3AP_PDU_PDU(tvb, pinfo, m3ap_tree);
}
}
void proto_register_m3ap(void) {
static hf_register_info hf[] = {
{ &hf_m3ap_Absolute_Time_ofMBMS_Data_value,
{ "Absolute-Time-ofMBMS-Data-value", "m3ap.Absolute_Time_ofMBMS_Data_value",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_m3ap_IPAddress,
{ "IPAddress", "m3ap.IPAddress",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
#include "packet-m3ap-hfarr.c"
};
static gint *ett[] = {
&ett_m3ap,
#include "packet-m3ap-ettarr.c"
};
proto_m3ap = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_m3ap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
m3ap_ies_dissector_table = register_dissector_table("m3ap.ies", "M3AP-PROTOCOL-IES", FT_UINT32, BASE_DEC);
m3ap_extension_dissector_table = register_dissector_table("m3ap.extension", "M3AP-PROTOCOL-EXTENSION", FT_UINT32, BASE_DEC);
m3ap_proc_imsg_dissector_table = register_dissector_table("m3ap.proc.imsg", "M3AP-ELEMENTARY-PROCEDURE InitiatingMessage", FT_UINT32, BASE_DEC);
m3ap_proc_sout_dissector_table = register_dissector_table("m3ap.proc.sout", "M3AP-ELEMENTARY-PROCEDURE SuccessfulOutcome", FT_UINT32, BASE_DEC);
m3ap_proc_uout_dissector_table = register_dissector_table("m3ap.proc.uout", "M3AP-ELEMENTARY-PROCEDURE UnsuccessfulOutcome", FT_UINT32, BASE_DEC);
}
void
proto_reg_handoff_m3ap(void)
{
static gboolean inited = FALSE;
static guint SctpPort;
if( !inited ) {
m3ap_handle = create_dissector_handle(dissect_m3ap, proto_m3ap);
dissector_add_uint("sctp.ppi", PROTO_3GPP_M3AP_PROTOCOL_ID, m3ap_handle);
inited = TRUE;
#include "packet-m3ap-dis-tab.c"
dissector_add_uint("m3ap.extension", 17, new_create_dissector_handle(dissect_AllocationAndRetentionPriority_PDU, proto_m3ap));
}
else {
if (SctpPort != 0) {
dissector_delete_uint("sctp.port", SctpPort, m3ap_handle);
}
}
SctpPort = global_m3ap_port;
if (SctpPort != 0) {
dissector_add_uint("sctp.port", SctpPort, m3ap_handle);
}
}
