static int
dissect_h501_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti = NULL;
proto_tree *h501_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PSNAME);
ti = proto_tree_add_item(tree, proto_h501, tvb, 0, -1, ENC_NA);
h501_tree = proto_item_add_subtree(ti, ett_h501);
return dissect_Message_PDU(tvb, pinfo, h501_tree, NULL);
}
static int
dissect_h501_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
dissect_tpkt_encap(tvb, pinfo, tree, FALSE, h501_pdu_handle);
return tvb_length(tvb);
}
static int
dissect_h501_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
dissect_tpkt_encap(tvb, pinfo, tree, h501_desegment_tcp, h501_pdu_handle);
return tvb_length(tvb);
}
void proto_register_h501(void) {
module_t *h501_module;
static hf_register_info hf[] = {
#include "packet-h501-hfarr.c"
};
static gint *ett[] = {
&ett_h501,
#include "packet-h501-ettarr.c"
};
proto_h501 = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_h501, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector(PFNAME, dissect_h501_pdu, proto_h501);
h501_module = prefs_register_protocol(proto_h501, proto_reg_handoff_h501);
prefs_register_uint_preference(h501_module, "udp.port",
"UDP port",
"Port to be decoded as h501",
10, &h501_udp_port);
prefs_register_uint_preference(h501_module, "tcp.port",
"TCP port",
"Port to be decoded as h501",
10, &h501_tcp_port);
prefs_register_bool_preference(h501_module, "desegment",
"Desegment H.501 over TCP",
"Desegment H.501 messages that span more TCP segments",
&h501_desegment_tcp);
}
void proto_reg_handoff_h501(void)
{
static gboolean h501_prefs_initialized = FALSE;
static dissector_handle_t h501_udp_handle;
static dissector_handle_t h501_tcp_handle;
static guint saved_h501_udp_port;
static guint saved_h501_tcp_port;
if (!h501_prefs_initialized) {
h501_pdu_handle = find_dissector(PFNAME);
h501_udp_handle = new_create_dissector_handle(dissect_h501_udp, proto_h501);
h501_tcp_handle = new_create_dissector_handle(dissect_h501_tcp, proto_h501);
h501_prefs_initialized = TRUE;
} else {
dissector_delete_uint("udp.port", saved_h501_udp_port, h501_udp_handle);
dissector_delete_uint("tcp.port", saved_h501_tcp_port, h501_tcp_handle);
}
saved_h501_udp_port = h501_udp_port;
dissector_add_uint("udp.port", saved_h501_udp_port, h501_udp_handle);
saved_h501_tcp_port = h501_tcp_port;
dissector_add_uint("tcp.port", saved_h501_tcp_port, h501_tcp_handle);
}
