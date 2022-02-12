static int dissect_ProtocolIEFieldValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
s1ap_ctx_t s1ap_ctx;
s1ap_ctx.message_type = message_type;
s1ap_ctx.ProcedureCode = ProcedureCode;
s1ap_ctx.ProtocolIE_ID = ProtocolIE_ID;
s1ap_ctx.ProtocolExtensionID = ProtocolExtensionID;
return (dissector_try_uint_new(s1ap_ies_dissector_table, ProtocolIE_ID, tvb, pinfo, tree, TRUE, &s1ap_ctx)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_ProtocolExtensionFieldExtensionValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
s1ap_ctx_t s1ap_ctx;
s1ap_ctx.message_type = message_type;
s1ap_ctx.ProcedureCode = ProcedureCode;
s1ap_ctx.ProtocolIE_ID = ProtocolIE_ID;
s1ap_ctx.ProtocolExtensionID = ProtocolExtensionID;
return (dissector_try_uint_new(s1ap_extension_dissector_table, ProtocolExtensionID, tvb, pinfo, tree, TRUE, &s1ap_ctx)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_InitiatingMessageValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
return (dissector_try_uint_new(s1ap_proc_imsg_dissector_table, ProcedureCode, tvb, pinfo, tree, TRUE, data)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_SuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
return (dissector_try_uint_new(s1ap_proc_sout_dissector_table, ProcedureCode, tvb, pinfo, tree, TRUE, data)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_UnsuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
return (dissector_try_uint_new(s1ap_proc_uout_dissector_table, ProcedureCode, tvb, pinfo, tree, TRUE, data)) ? tvb_captured_length(tvb) : 0;
}
static int
dissect_s1ap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *s1ap_item = NULL;
proto_tree *s1ap_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "S1AP");
s1ap_item = proto_tree_add_item(tree, proto_s1ap, tvb, 0, -1, ENC_NA);
s1ap_tree = proto_item_add_subtree(s1ap_item, ett_s1ap);
dissect_S1AP_PDU_PDU(tvb, pinfo, s1ap_tree, NULL);
return tvb_captured_length(tvb);
}
void
proto_reg_handoff_s1ap(void)
{
static gboolean Initialized=FALSE;
static guint SctpPort;
gcsna_handle = find_dissector_add_dependency("gcsna", proto_s1ap);
if (!Initialized) {
nas_eps_handle = find_dissector_add_dependency("nas-eps", proto_s1ap);
lppa_handle = find_dissector_add_dependency("lppa", proto_s1ap);
bssgp_handle = find_dissector_add_dependency("bssgp", proto_s1ap);
dissector_add_for_decode_as("sctp.port", s1ap_handle);
dissector_add_uint("sctp.ppi", S1AP_PAYLOAD_PROTOCOL_ID, s1ap_handle);
Initialized=TRUE;
#include "packet-s1ap-dis-tab.c"
} else {
if (SctpPort != 0) {
dissector_delete_uint("sctp.port", SctpPort, s1ap_handle);
}
}
SctpPort=gbl_s1apSctpPort;
if (SctpPort != 0) {
dissector_add_uint("sctp.port", SctpPort, s1ap_handle);
}
}
void proto_register_s1ap(void) {
static hf_register_info hf[] = {
{ &hf_s1ap_transportLayerAddressIPv4,
{ "transportLayerAddress(IPv4)", "s1ap.transportLayerAddressIPv4",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_s1ap_transportLayerAddressIPv6,
{ "transportLayerAddress(IPv6)", "s1ap.transportLayerAddressIPv6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }},
#include "packet-s1ap-hfarr.c"
};
static gint *ett[] = {
&ett_s1ap,
&ett_s1ap_TransportLayerAddress,
&ett_s1ap_ToTargetTransparentContainer,
&ett_s1ap_ToSourceTransparentContainer,
&ett_s1ap_RRCContainer,
&ett_s1ap_UERadioCapability,
&ett_s1ap_RIMInformation,
&ett_s1ap_Cdma2000PDU,
&ett_s1ap_Cdma2000SectorID,
#include "packet-s1ap-ettarr.c"
};
module_t *s1ap_module;
proto_s1ap = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_s1ap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
s1ap_handle = register_dissector("s1ap", dissect_s1ap, proto_s1ap);
s1ap_ies_dissector_table = register_dissector_table("s1ap.ies", "S1AP-PROTOCOL-IES", proto_s1ap, FT_UINT32, BASE_DEC);
s1ap_ies_p1_dissector_table = register_dissector_table("s1ap.ies.pair.first", "S1AP-PROTOCOL-IES-PAIR FirstValue", proto_s1ap, FT_UINT32, BASE_DEC);
s1ap_ies_p2_dissector_table = register_dissector_table("s1ap.ies.pair.second", "S1AP-PROTOCOL-IES-PAIR SecondValue", proto_s1ap, FT_UINT32, BASE_DEC);
s1ap_extension_dissector_table = register_dissector_table("s1ap.extension", "S1AP-PROTOCOL-EXTENSION", proto_s1ap, FT_UINT32, BASE_DEC);
s1ap_proc_imsg_dissector_table = register_dissector_table("s1ap.proc.imsg", "S1AP-ELEMENTARY-PROCEDURE InitiatingMessage", proto_s1ap, FT_UINT32, BASE_DEC);
s1ap_proc_sout_dissector_table = register_dissector_table("s1ap.proc.sout", "S1AP-ELEMENTARY-PROCEDURE SuccessfulOutcome", proto_s1ap, FT_UINT32, BASE_DEC);
s1ap_proc_uout_dissector_table = register_dissector_table("s1ap.proc.uout", "S1AP-ELEMENTARY-PROCEDURE UnsuccessfulOutcome", proto_s1ap, FT_UINT32, BASE_DEC);
s1ap_module = prefs_register_protocol(proto_s1ap, proto_reg_handoff_s1ap);
prefs_register_uint_preference(s1ap_module, "sctp.port",
"S1AP SCTP Port",
"Set the SCTP port for S1AP messages",
10,
&gbl_s1apSctpPort);
prefs_register_bool_preference(s1ap_module, "dissect_container", "Dissect TransparentContainer", "Dissect TransparentContainers that are opaque to S1AP", &g_s1ap_dissect_container);
}
