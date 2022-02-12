static int dissect_ProtocolIEFieldValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
return (dissector_try_uint_new(nbap_ies_dissector_table, ProtocolIE_ID, tvb, pinfo, tree, FALSE)) ? tvb_length(tvb) : 0;
}
static int dissect_ProtocolExtensionFieldExtensionValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
return (dissector_try_uint_new(nbap_extension_dissector_table, ProtocolIE_ID, tvb, pinfo, tree, FALSE)) ? tvb_length(tvb) : 0;
}
static int dissect_InitiatingMessageValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (!ProcedureID) return 0;
return (dissector_try_string(nbap_proc_imsg_dissector_table, ProcedureID, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_SuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (!ProcedureID) return 0;
return (dissector_try_string(nbap_proc_sout_dissector_table, ProcedureID, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static int dissect_UnsuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (!ProcedureID) return 0;
return (dissector_try_string(nbap_proc_uout_dissector_table, ProcedureID, tvb, pinfo, tree)) ? tvb_length(tvb) : 0;
}
static void
dissect_nbap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *nbap_item = NULL;
proto_tree *nbap_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NBAP");
nbap_item = proto_tree_add_item(tree, proto_nbap, tvb, 0, -1, ENC_NA);
nbap_tree = proto_item_add_subtree(nbap_item, ett_nbap);
dissect_NBAP_PDU_PDU(tvb, pinfo, nbap_tree);
}
void proto_register_nbap(void) {
static hf_register_info hf[] = {
{ &hf_nbap_transportLayerAddress_ipv4,
{ "transportLayerAddress IPv4", "nbap.transportLayerAddress_ipv4",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_nbap_transportLayerAddress_ipv6,
{ "transportLayerAddress IPv6", "nbap.transportLayerAddress_ipv6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_nbap_transportLayerAddress_nsap,
{ "transportLayerAddress NSAP", "nbap.transportLayerAddress_NSAP",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
#include "packet-nbap-hfarr.c"
};
static gint *ett[] = {
&ett_nbap,
&ett_nbap_TransportLayerAddress,
&ett_nbap_TransportLayerAddress_nsap,
&ett_nbap_ib_sg_data,
#include "packet-nbap-ettarr.c"
};
proto_nbap = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_nbap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("nbap", dissect_nbap, proto_nbap);
nbap_ies_dissector_table = register_dissector_table("nbap.ies", "NBAP-PROTOCOL-IES", FT_UINT32, BASE_DEC);
nbap_extension_dissector_table = register_dissector_table("nbap.extension", "NBAP-PROTOCOL-EXTENSION", FT_UINT32, BASE_DEC);
nbap_proc_imsg_dissector_table = register_dissector_table("nbap.proc.imsg", "NBAP-ELEMENTARY-PROCEDURE InitiatingMessage", FT_STRING, BASE_NONE);
nbap_proc_sout_dissector_table = register_dissector_table("nbap.proc.sout", "NBAP-ELEMENTARY-PROCEDURE SuccessfulOutcome", FT_STRING, BASE_NONE);
nbap_proc_uout_dissector_table = register_dissector_table("nbap.proc.uout", "NBAP-ELEMENTARY-PROCEDURE UnsuccessfulOutcome", FT_STRING, BASE_NONE);
}
void
proto_reg_handoff_nbap(void)
{
dissector_handle_t nbap_handle;
nbap_handle = find_dissector("nbap");
fp_handle = find_dissector("fp");
dissector_add_uint("sctp.ppi", NBAP_PAYLOAD_PROTOCOL_ID, nbap_handle);
dissector_add_handle("sctp.port", nbap_handle);
#include "packet-nbap-dis-tab.c"
}
