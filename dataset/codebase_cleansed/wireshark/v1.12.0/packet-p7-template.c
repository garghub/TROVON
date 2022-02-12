void proto_register_p7(void) {
static hf_register_info hf[] =
{
#include "packet-p7-hfarr.c"
};
static gint *ett[] = {
&ett_p7,
#include "packet-p7-ettarr.c"
};
module_t *p7_module;
proto_p7 = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_p7, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
p7_module = prefs_register_protocol_subtree("OSI/X.400", proto_p7, prefs_register_p7);
prefs_register_uint_preference(p7_module, "tcp.port", "P7 TCP Port",
"Set the port for P7 operations (if other"
" than the default of 102)",
10, &global_p7_tcp_port);
}
void proto_reg_handoff_p7(void) {
#include "packet-p7-dis-tab.c"
oid_add_from_string("id-ac-ms-access","2.6.0.1.11");
oid_add_from_string("id-ac-ms-reliable-access","2.6.0.1.12");
register_ros_protocol_info("2.6.0.2.9", &p7_ros_info, 0, "id-as-ms", FALSE);
register_ros_protocol_info("2.6.0.2.5", &p7_ros_info, 0, "id-as-mrse", FALSE);
register_ros_protocol_info("2.6.0.2.1", &p7_ros_info, 0, "id-as-msse", FALSE);
tpkt_handle = find_dissector("tpkt");
}
static void
prefs_register_p7(void)
{
static guint tcp_port = 0;
if((tcp_port > 0) && (tcp_port != 102) && tpkt_handle)
dissector_delete_uint("tcp.port", tcp_port, tpkt_handle);
tcp_port = global_p7_tcp_port;
if((tcp_port > 0) && (tcp_port != 102) && tpkt_handle)
dissector_add_uint("tcp.port", global_p7_tcp_port, tpkt_handle);
}
