static guint
get_openflow_pdu_length(packet_info *pinfo _U_, tvbuff_t *tvb,
int offset, void *data _U_)
{
return tvb_get_ntohs(tvb, offset + 2);
}
static int
dissect_openflow_tcp_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint offset = 0;
guint8 version;
proto_item* ti;
version = tvb_get_guint8(tvb, 0);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "OpenFlow");
col_clear(pinfo->cinfo,COL_INFO);
switch(version){
case OFP_VERSION_1_0:
call_dissector(openflow_v1_handle, tvb, pinfo, tree);
break;
case OFP_VERSION_1_3:
call_dissector(openflow_v4_handle, tvb, pinfo, tree);
break;
case OFP_VERSION_1_4:
call_dissector(openflow_v5_handle, tvb, pinfo, tree);
break;
default:
ti = proto_tree_add_item(tree, hf_openflow_version, tvb, offset, 1, ENC_BIG_ENDIAN);
expert_add_info(pinfo, ti, &ei_openflow_version);
break;
}
return tvb_reported_length(tvb);
}
static int
dissect_openflow(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
tcp_dissect_pdus(tvb, pinfo, tree, openflow_desegment, OFP_HEADER_LEN,
get_openflow_pdu_length, dissect_openflow_tcp_pdu, data);
return tvb_captured_length(tvb);
}
static gboolean
dissect_openflow_heur(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, void *data)
{
conversation_t *conversation = NULL;
if ((pinfo->destport != OFP_LEGACY_PORT) &&
(pinfo->destport != OFP_LEGACY2_PORT) &&
(pinfo->destport != OFP_IANA_PORT) &&
(pinfo->destport != (guint32)g_openflow_port)) {
return FALSE;
}
conversation = find_or_create_conversation(pinfo);
conversation_set_dissector(conversation, openflow_handle);
dissect_openflow(tvb, pinfo, tree, data);
return TRUE;
}
void
proto_register_openflow(void)
{
static hf_register_info hf[] = {
{ &hf_openflow_version,
{ "Version", "openflow.version",
FT_UINT8, BASE_HEX, VALS(openflow_version_values), 0x7f,
NULL, HFILL }
}
};
static ei_register_info ei[] = {
{ &ei_openflow_version, { "openflow.version.unknown", PI_UNDECODED, PI_WARN, "Unsupported version not dissected", EXPFILL }},
};
module_t *openflow_module;
expert_module_t* expert_openflow;
proto_openflow = proto_register_protocol("OpenFlow",
"OpenFlow", "openflow");
new_register_dissector("openflow", dissect_openflow, proto_openflow);
proto_register_field_array(proto_openflow, hf, array_length(hf));
expert_openflow = expert_register_protocol(proto_openflow);
expert_register_field_array(expert_openflow, ei, array_length(ei));
openflow_module = prefs_register_protocol(proto_openflow, proto_reg_handoff_openflow);
prefs_register_uint_preference(openflow_module, "tcp.port", "OpenFlow TCP port",
"OpenFlow TCP port (6653 is the IANA assigned port)",
10, &g_openflow_port);
prefs_register_obsolete_preference(openflow_module, "heuristic");
prefs_register_bool_preference(openflow_module, "desegment",
"Reassemble OpenFlow messages spanning multiple TCP segments",
"Whether the OpenFlow dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&openflow_desegment);
}
void
proto_reg_handoff_openflow(void)
{
static gboolean initialized = FALSE;
static int currentPort;
if (!initialized) {
openflow_handle = new_create_dissector_handle(dissect_openflow, proto_openflow);
heur_dissector_add("tcp", dissect_openflow_heur, "OpenFlow over TCP", "openflow_tcp", proto_openflow, HEURISTIC_ENABLE);
initialized = TRUE;
} else {
dissector_delete_uint("tcp.port", currentPort, openflow_handle);
}
currentPort = g_openflow_port;
dissector_add_uint("tcp.port", currentPort, openflow_handle);
openflow_v1_handle = find_dissector("openflow_v1");
openflow_v4_handle = find_dissector("openflow_v4");
openflow_v5_handle = find_dissector("openflow_v5");
}
