static guint
get_ulp_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
return tvb_get_ntohs(tvb,offset);
}
static void
dissect_ulp_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tcp_dissect_pdus(tvb, pinfo, tree, ulp_desegment, ULP_HEADER_SIZE,
get_ulp_pdu_len, dissect_ULP_PDU_PDU);
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
register_dissector("ulp", dissect_ulp_tcp, proto_ulp);
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
"Set the TCP port for Ulp messages(IANA registerd port is 7275)",
10,
&gbl_ulp_port);
}
void
proto_reg_handoff_ulp(void)
{
static gboolean initialized = FALSE;
static dissector_handle_t ulp_handle;
static guint local_ulp_port;
if (!initialized) {
ulp_handle = find_dissector("ulp");
dissector_add_string("media_type","application/oma-supl-ulp", ulp_handle);
rrlp_handle = find_dissector("rrlp");
lpp_handle = find_dissector("lpp");
initialized = TRUE;
} else {
dissector_delete_uint("tcp.port", local_ulp_port, ulp_handle);
}
local_ulp_port = gbl_ulp_port;
dissector_add_uint("tcp.port", gbl_ulp_port, ulp_handle);
}
