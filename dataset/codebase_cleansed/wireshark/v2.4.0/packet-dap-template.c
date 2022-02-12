void proto_register_dap(void) {
static hf_register_info hf[] =
{
#include "packet-dap-hfarr.c"
};
static gint *ett[] = {
&ett_dap,
#include "packet-dap-ettarr.c"
};
static ei_register_info ei[] = {
{ &ei_dap_anonymous, { "dap.anonymous", PI_PROTOCOL, PI_NOTE, "Anonymous", EXPFILL }},
};
module_t *dap_module;
expert_module_t* expert_dap;
proto_dap = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_dap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_dap = expert_register_protocol(proto_dap);
expert_register_field_array(expert_dap, ei, array_length(ei));
dap_module = prefs_register_protocol_subtree("OSI/X.500", proto_dap, NULL);
prefs_register_obsolete_preference(dap_module, "tcp.port");
prefs_register_static_text_preference(dap_module, "tcp_port_info",
"The TCP ports used by the DAP protocol should be added to the TPKT preference \"TPKT TCP ports\", or the IDMP preference \"IDMP TCP Port\", or by selecting \"TPKT\" as the \"Transport\" protocol in the \"Decode As\" dialog.",
"DAP TCP Port preference moved information");
}
void proto_reg_handoff_dap(void) {
oid_add_from_string("id-ac-directory-access","2.5.3.1");
register_ros_protocol_info("2.5.9.1", &dap_ros_info, 0, "id-as-directory-access", FALSE);
register_idmp_protocol_info("2.5.33.0", &dap_ros_info, 0, "dap-ip");
x509if_register_fmt(hf_dap_equality, "=");
x509if_register_fmt(hf_dap_greaterOrEqual, ">=");
x509if_register_fmt(hf_dap_lessOrEqual, "<=");
x509if_register_fmt(hf_dap_approximateMatch, "=~");
x509if_register_fmt(hf_dap_present, "= *");
}
