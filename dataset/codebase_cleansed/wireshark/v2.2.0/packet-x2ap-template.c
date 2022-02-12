static int dissect_ProtocolIEFieldValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(x2ap_ies_dissector_table, ProtocolIE_ID, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_ProtocolExtensionFieldExtensionValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(x2ap_extension_dissector_table, ProtocolIE_ID, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_InitiatingMessageValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(x2ap_proc_imsg_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_SuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(x2ap_proc_sout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_UnsuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(x2ap_proc_uout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int
dissect_x2ap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
proto_item *x2ap_item = NULL;
proto_tree *x2ap_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "X2AP");
x2ap_item = proto_tree_add_item(tree, proto_x2ap, tvb, 0, -1, ENC_NA);
x2ap_tree = proto_item_add_subtree(x2ap_item, ett_x2ap);
return dissect_X2AP_PDU_PDU(tvb, pinfo, x2ap_tree, data);
}
void proto_register_x2ap(void) {
static hf_register_info hf[] = {
{ &hf_x2ap_transportLayerAddressIPv4,
{ "transportLayerAddress(IPv4)", "x2ap.transportLayerAddressIPv4",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x2ap_transportLayerAddressIPv6,
{ "transportLayerAddress(IPv6)", "x2ap.transportLayerAddressIPv6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }},
#include "packet-x2ap-hfarr.c"
};
static gint *ett[] = {
&ett_x2ap,
&ett_x2ap_TransportLayerAddress,
#include "packet-x2ap-ettarr.c"
};
module_t *x2ap_module;
proto_x2ap = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_x2ap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
x2ap_handle = register_dissector("x2ap", dissect_x2ap, proto_x2ap);
x2ap_ies_dissector_table = register_dissector_table("x2ap.ies", "X2AP-PROTOCOL-IES", proto_x2ap, FT_UINT32, BASE_DEC);
x2ap_extension_dissector_table = register_dissector_table("x2ap.extension", "X2AP-PROTOCOL-EXTENSION", proto_x2ap, FT_UINT32, BASE_DEC);
x2ap_proc_imsg_dissector_table = register_dissector_table("x2ap.proc.imsg", "X2AP-ELEMENTARY-PROCEDURE InitiatingMessage", proto_x2ap, FT_UINT32, BASE_DEC);
x2ap_proc_sout_dissector_table = register_dissector_table("x2ap.proc.sout", "X2AP-ELEMENTARY-PROCEDURE SuccessfulOutcome", proto_x2ap, FT_UINT32, BASE_DEC);
x2ap_proc_uout_dissector_table = register_dissector_table("x2ap.proc.uout", "X2AP-ELEMENTARY-PROCEDURE UnsuccessfulOutcome", proto_x2ap, FT_UINT32, BASE_DEC);
x2ap_module = prefs_register_protocol(proto_x2ap, proto_reg_handoff_x2ap);
prefs_register_uint_preference(x2ap_module, "sctp.port",
"X2AP SCTP Port",
"Set the SCTP port for X2AP messages",
10,
&gbl_x2apSctpPort);
}
void
proto_reg_handoff_x2ap(void)
{
static gboolean Initialized=FALSE;
static guint SctpPort;
if (!Initialized) {
dissector_add_for_decode_as("sctp.port", x2ap_handle);
dissector_add_uint("sctp.ppi", X2AP_PAYLOAD_PROTOCOL_ID, x2ap_handle);
Initialized=TRUE;
#include "packet-x2ap-dis-tab.c"
} else {
if (SctpPort != 0) {
dissector_delete_uint("sctp.port", SctpPort, x2ap_handle);
}
}
SctpPort=gbl_x2apSctpPort;
if (SctpPort != 0) {
dissector_add_uint("sctp.port", SctpPort, x2ap_handle);
}
}
