static guint
get_ulp_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
return tvb_get_ntohs(tvb,offset);
}
static int
dissect_ulp_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, tree, ulp_desegment, ULP_HEADER_SIZE,
get_ulp_pdu_len, dissect_ULP_PDU_PDU, data);
return tvb_captured_length(tvb);
}
void proto_register_ulp(void) {
static hf_register_info hf[] = {
#include "packet-ulp-hfarr.c"
};
static gint *ett[] = {
&ett_ulp,
#include "packet-ulp-ettarr.c"
};
module_t *ulp_module;
proto_ulp = proto_register_protocol(PNAME, PSNAME, PFNAME);
new_register_dissector("ulp", dissect_ulp_tcp, proto_ulp);
proto_register_field_array(proto_ulp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
ulp_module = prefs_register_protocol(proto_ulp,proto_reg_handoff_ulp);
prefs_register_bool_preference(ulp_module, "desegment_ulp_messages",
"Reassemble ULP messages spanning multiple TCP segments",
"Whether the ULP dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&ulp_desegment);
prefs_register_uint_preference(ulp_module, "tcp.port",
"ULP TCP Port",
"Set the TCP port for ULP messages (IANA registered port is 7275)",
10,
&gbl_ulp_tcp_port);
prefs_register_uint_preference(ulp_module, "udp.port",
"ULP UDP Port",
"Set the UDP port for ULP messages (IANA registered port is 7275)",
10,
&gbl_ulp_udp_port);
}
void
proto_reg_handoff_ulp(void)
{
static gboolean initialized = FALSE;
static dissector_handle_t ulp_tcp_handle, ulp_udp_handle;
static guint local_ulp_tcp_port, local_ulp_udp_port;
if (!initialized) {
ulp_tcp_handle = find_dissector("ulp");
dissector_add_string("media_type","application/oma-supl-ulp", ulp_tcp_handle);
ulp_udp_handle = new_create_dissector_handle(dissect_ULP_PDU_PDU, proto_ulp);
rrlp_handle = find_dissector("rrlp");
lpp_handle = find_dissector("lpp");
initialized = TRUE;
} else {
dissector_delete_uint("tcp.port", local_ulp_tcp_port, ulp_tcp_handle);
dissector_delete_uint("udp.port", local_ulp_udp_port, ulp_udp_handle);
}
local_ulp_tcp_port = gbl_ulp_tcp_port;
dissector_add_uint("tcp.port", gbl_ulp_tcp_port, ulp_tcp_handle);
local_ulp_udp_port = gbl_ulp_udp_port;
dissector_add_uint("udp.port", gbl_ulp_udp_port, ulp_udp_handle);
}
