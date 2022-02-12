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
p7_module = prefs_register_protocol_subtree("OSI/X.400", proto_p7, NULL);
prefs_register_obsolete_preference(p7_module, "tcp.port");
prefs_register_static_text_preference(p7_module, "tcp_port_info",
"The TCP ports used by the P7 protocol should be added to the TPKT preference \"TPKT TCP ports\", or by selecting \"TPKT\" as the \"Transport\" protocol in the \"Decode As\" dialog.",
"P7 TCP Port preference moved information");
}
void proto_reg_handoff_p7(void) {
#include "packet-p7-dis-tab.c"
oid_add_from_string("id-ac-ms-access","2.6.0.1.11");
oid_add_from_string("id-ac-ms-reliable-access","2.6.0.1.12");
register_ros_protocol_info("2.6.0.2.9", &p7_ros_info, 0, "id-as-ms", FALSE);
register_ros_protocol_info("2.6.0.2.5", &p7_ros_info, 0, "id-as-mrse", FALSE);
register_ros_protocol_info("2.6.0.2.1", &p7_ros_info, 0, "id-as-msse", FALSE);
}
