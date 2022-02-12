static int
dissect_ProtocolIEFieldValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(m2ap_ies_dissector_table, ProtocolIE_ID, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int
dissect_ProtocolExtensionFieldExtensionValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(m2ap_extension_dissector_table, ProtocolIE_ID, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int
dissect_InitiatingMessageValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(m2ap_proc_imsg_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int
dissect_SuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(m2ap_proc_sout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int
dissect_UnsuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(m2ap_proc_uout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int
dissect_m2ap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *m2ap_item = NULL;
proto_tree *m2ap_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PSNAME);
col_clear_fence(pinfo->cinfo, COL_INFO);
col_clear(pinfo->cinfo, COL_INFO);
m2ap_item = proto_tree_add_item(tree, proto_m2ap, tvb, 0, -1, ENC_NA);
m2ap_tree = proto_item_add_subtree(m2ap_item, ett_m2ap);
dissect_M2AP_PDU_PDU(tvb, pinfo, m2ap_tree, NULL);
return tvb_captured_length(tvb);
}
void
proto_register_m2ap(void) {
static hf_register_info hf[] = {
{ &hf_m2ap_IPAddress_v4,
{ "IPAddress", "m2ap.IPAddress_v4",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_m2ap_IPAddress_v6,
{ "IPAddress", "m2ap.IPAddress_v6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
#include "packet-m2ap-hfarr.c"
};
static gint *ett[] = {
&ett_m2ap,
&ett_m2ap_PLMN_Identity,
&ett_m2ap_IPAddress,
#include "packet-m2ap-ettarr.c"
};
expert_module_t* expert_m2ap;
static ei_register_info ei[] = {
{ &ei_m2ap_invalid_ip_address_len, { "m2ap.invalid_ip_address_len", PI_MALFORMED, PI_ERROR, "Invalid IP address length", EXPFILL }}
};
proto_m2ap = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_m2ap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_m2ap = expert_register_protocol(proto_m2ap);
expert_register_field_array(expert_m2ap, ei, array_length(ei));
m2ap_handle = register_dissector(PFNAME, dissect_m2ap, proto_m2ap);
m2ap_ies_dissector_table = register_dissector_table("m2ap.ies", "M2AP-PROTOCOL-IES", proto_m2ap, FT_UINT32, BASE_DEC);
m2ap_extension_dissector_table = register_dissector_table("m2ap.extension", "M2AP-PROTOCOL-EXTENSION", proto_m2ap, FT_UINT32, BASE_DEC);
m2ap_proc_imsg_dissector_table = register_dissector_table("m2ap.proc.imsg", "M2AP-ELEMENTARY-PROCEDURE InitiatingMessage", proto_m2ap, FT_UINT32, BASE_DEC);
m2ap_proc_sout_dissector_table = register_dissector_table("m2ap.proc.sout", "M2AP-ELEMENTARY-PROCEDURE SuccessfulOutcome", proto_m2ap, FT_UINT32, BASE_DEC);
m2ap_proc_uout_dissector_table = register_dissector_table("m2ap.proc.uout", "M2AP-ELEMENTARY-PROCEDURE UnsuccessfulOutcome", proto_m2ap, FT_UINT32, BASE_DEC);
}
void
proto_reg_handoff_m2ap(void)
{
dissector_add_uint("sctp.ppi", PROTO_3GPP_M2AP_PROTOCOL_ID, m2ap_handle);
dissector_add_uint("sctp.port", M2AP_PORT, m2ap_handle);
#include "packet-m2ap-dis-tab.c"
}
