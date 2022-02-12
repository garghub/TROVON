static guint
get_ilp_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
return tvb_get_ntohs(tvb,offset);
}
static int
dissect_ilp_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, tree, ilp_desegment, ILP_HEADER_SIZE,
get_ilp_pdu_len, dissect_ILP_PDU_PDU, data);
return tvb_captured_length(tvb);
}
void proto_register_ilp(void) {
static hf_register_info hf[] = {
#include "packet-ilp-hfarr.c"
{ &hf_ilp_mobile_directory_number,
{ "Mobile Directory Number", "ilp.mobile_directory_number",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_ilp,
&ett_ilp_setid,
#include "packet-ilp-ettarr.c"
};
module_t *ilp_module;
proto_ilp = proto_register_protocol(PNAME, PSNAME, PFNAME);
ilp_handle = register_dissector("ilp", dissect_ilp_tcp, proto_ilp);
proto_register_field_array(proto_ilp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
ilp_module = prefs_register_protocol(proto_ilp, NULL);
prefs_register_bool_preference(ilp_module, "desegment_ilp_messages",
"Reassemble ILP messages spanning multiple TCP segments",
"Whether the ILP dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&ilp_desegment);
}
void
proto_reg_handoff_ilp(void)
{
dissector_add_string("media_type","application/oma-supl-ilp", ilp_handle);
rrlp_handle = find_dissector_add_dependency("rrlp", proto_ilp);
lpp_handle = find_dissector_add_dependency("lpp", proto_ilp);
dissector_add_uint_with_preference("tcp.port", ILP_TCP_PORT, ilp_handle);
}
