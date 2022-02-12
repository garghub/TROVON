static void
decode_string_attribute(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item, int* hfValue, int offset, int length)
{
guint8* pbuffer;
if (length < 4) {
expert_add_info(pinfo, item, &ei_opsi_short_attribute);
return;
}
pbuffer=tvb_get_string_enc(wmem_packet_scope(), tvb, offset+4, length-4, ENC_ASCII);
proto_tree_add_string(tree, *hfValue, tvb, offset+4, length-4, pbuffer);
}
static void
decode_ipv4_attribute(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item, int* hfValue, int offset, int length)
{
guint32 ip_address;
if (length < 8) {
expert_add_info(pinfo, item, &ei_opsi_short_attribute);
return;
}
ip_address = tvb_get_ipv4(tvb, offset+4);
proto_tree_add_ipv4(tree, *hfValue, tvb, offset+4, 4, ip_address);
}
static void
decode_longint_attribute(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item, int* hfValue, int offset, int length)
{
if (length < 8) {
expert_add_info(pinfo, item, &ei_opsi_short_attribute);
return;
}
proto_tree_add_uint(tree, *hfValue, tvb, offset+4, 4, tvb_get_ntohl(tvb, offset+4));
}
static void
decode_value_string_attribute(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item, int* hfValue, int offset, int length)
{
if (length < 8) {
expert_add_info(pinfo, item, &ei_opsi_short_attribute);
return;
}
proto_tree_add_item(tree, *hfValue, tvb, offset+4, 4, ENC_BIG_ENDIAN);
}
static void
decode_time_attribute(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item, int* hfValue, int offset, int length)
{
nstime_t ns;
if (length < 8) {
expert_add_info(pinfo, item, &ei_opsi_short_attribute);
return;
}
ns.secs = tvb_get_ntohl(tvb, offset+4);
ns.nsecs = 0;
proto_tree_add_time(tree, *hfValue, tvb, offset+4, 4, &ns);
}
static guint
get_opsi_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
return tvb_get_ntohs(tvb, offset + 4);
}
static int
get_opsi_attribute_index(int min, int max, int attribute_type)
{
int middle, at;
middle = (min+max)/2;
at = opsi_attributes[middle].attribute_type;
if (at == attribute_type) return middle;
if (attribute_type > at) {
return (middle == max) ? -1 : get_opsi_attribute_index(middle+1, max, attribute_type);
}
return (middle == min) ? -1 : get_opsi_attribute_index(min, middle-1, attribute_type);
}
static void
dissect_attributes(tvbuff_t *tvb, packet_info *pinfo, proto_tree *opsi_tree, int offset, int length)
{
int i;
int attribute_type;
int attribute_length;
proto_item *ti;
proto_tree *ntree = NULL;
while (length >= 4) {
attribute_type = tvb_get_ntohs(tvb, offset);
attribute_length = tvb_get_ntohs(tvb, offset+2);
if (attribute_length > length) break;
i = get_opsi_attribute_index(0, OPSI_ATTRIBUTES_COUNT-1, attribute_type);
if (i == -1) {
proto_tree_add_expert_format(opsi_tree, pinfo, &ei_opsi_unknown_attribute, tvb, offset, attribute_length,
"Unknown attribute (%d)", attribute_type);
}
else {
ntree = proto_tree_add_subtree_format(opsi_tree, tvb, offset, attribute_length, *opsi_attributes[i].tree_id, &ti,
"%s (%d)", opsi_attributes[i].tree_text, attribute_type);
proto_tree_add_item(ntree, hf_opsi_attribute_length, tvb, offset+2, 2, ENC_BIG_ENDIAN);
opsi_attributes[i].dissect(tvb, pinfo, ntree, ti, opsi_attributes[i].hf_type_attribute, offset, attribute_length);
}
if (attribute_length < 4) {
break;
}
offset += attribute_length;
length -= attribute_length;
}
if (length) {
proto_tree_add_expert(opsi_tree, pinfo, &ei_opsi_short_frame, tvb, offset, -1);
}
}
static int
dissect_opsi_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *opsi_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "OPSI");
col_clear(pinfo->cinfo, COL_INFO);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ", ", "%s",
val_to_str(tvb_get_guint8(tvb, CODE_OFFSET), opsi_opcode,
"<Unknown opcode %d>"));
col_set_fence(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_opsi, tvb, 0, -1, ENC_NA);
opsi_tree = proto_item_add_subtree(ti, ett_opsi);
if (opsi_tree) {
proto_tree_add_item(opsi_tree, hf_opsi_major_version, tvb, MAJOR_VERSION_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(opsi_tree, hf_opsi_minor_version, tvb, MINOR_VERSION_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(opsi_tree, hf_opsi_opcode, tvb, CODE_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(opsi_tree, hf_opsi_hook_id, tvb, HOOK_ID_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(opsi_tree, hf_opsi_length, tvb, PACKET_LENGTH_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(opsi_tree, hf_opsi_session_id, tvb, SESSION_OFFSET, 2, ENC_BIG_ENDIAN);
}
dissect_attributes(tvb, pinfo, opsi_tree, HEADER_LENGTH, MIN(((int)tvb_reported_length(tvb)-HEADER_LENGTH), (tvb_get_ntohs(tvb, PACKET_LENGTH_OFFSET)-HEADER_LENGTH)));
return tvb_reported_length(tvb);
}
static int
dissect_opsi(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, tree, opsi_desegment, HEADER_LENGTH, get_opsi_pdu_len,
dissect_opsi_pdu, data);
return tvb_reported_length(tvb);
}
void
proto_register_opsi(void)
{
static hf_register_info hf[] = {
{ &hf_opsi_major_version,
{ "Major version", "opsi.major",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_opsi_minor_version,
{ "Minor version", "opsi.minor",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_opsi_opcode,
{ "Operation code", "opsi.opcode",
FT_UINT8, BASE_DEC, VALS(opsi_opcode), 0x0,
NULL, HFILL }
},
{ &hf_opsi_hook_id,
{ "Hook ID", "opsi.hook",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_opsi_length,
{ "Message length", "opsi.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_opsi_session_id,
{ "Session ID", "opsi.session_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_user_name_att,
{ "User name", "opsi.attr.user_name",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_password_att,
{ "User password", "opsi.attr.password",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_chap_password_att,
{ "CHAP password attribute", "opsi.attr.chap_password",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_nas_ip_add_att,
{ "NAS IP address", "opsi.attr.nas_ip_addr",
FT_IPv4, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_nas_port_att,
{ "NAS port", "opsi.attr.nas_port",
FT_UINT32, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_service_type_att,
{ "Service type", "opsi.attr.service_type",
FT_UINT32, BASE_DEC, VALS(opsi_service_type_code), 0x0,
NULL, HFILL }
},
{ &hf_framed_protocol_att,
{ "Framed protocol", "opsi.attr.framed_protocol",
FT_UINT32, BASE_DEC, VALS(opsi_framed_protocol_code), 0x0,
NULL, HFILL }
},
{ &hf_framed_address_att,
{ "Framed address", "opsi.attr.framed_address",
FT_IPv4, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_framed_netmask_att,
{ "Framed netmask", "opsi.attr.framed_netmask",
FT_IPv4, BASE_NETMASK, NULL, 0x00,
NULL, HFILL }
},
{ &hf_framed_routing_att,
{ "Framed routing", "opsi.attr.framed_routing",
FT_UINT32, BASE_DEC, VALS(opsi_framed_routing_code), 0x0,
NULL, HFILL }
},
{ &hf_framed_filter_att,
{ "Framed filter", "opsi.attr.framed_filter",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_framed_mtu_att,
{ "Framed MTU", "opsi.attr.framed_mtu",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_framed_compression_att,
{ "Framed compression", "opsi.attr.framed_compression",
FT_UINT32, BASE_DEC, VALS(opsi_framed_compression_code), 0x0,
NULL, HFILL }
},
{ &hf_called_station_att,
{ "Called station ID", "opsi.attr.called_station_id",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_calling_station_att,
{ "Calling station ID", "opsi.attr.calling_station_id",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_nas_identifier_att,
{ "NAS ID", "opsi.attr.nas_id",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_accounting_att,
{ "Accounting", "opsi.attr.accounting",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_acct_session_id_att,
{ "Accounting session ID", "opsi.attr.acct.session_id",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_chap_challenge_att,
{ "CHAP challenge", "opsi.attr.chap_challenge",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_nas_port_type_att,
{ "NAS port type", "opsi.attr.nas_port_type",
FT_UINT32, BASE_DEC, VALS(opsi_nas_port_type_code), 0x0,
NULL, HFILL }
},
{ &hf_designation_num_att,
{ "Designation number", "opsi.attr.designation_number",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_nas_port_id_att,
{ "NAS port ID", "opsi.attr.nas_port_id",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_smc_aaa_id_att,
{ "SMC AAA ID", "opsi.attr.smc_aaa_id",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_smc_vpn_id_att,
{ "SMC VPN ID", "opsi.attr.smc_vpn_id",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_smc_vpn_name_att,
{ "SMC VPN name", "opsi.attr.smc_vpn_name",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_smc_ran_id_att,
{ "SMC RAN ID", "opsi.attr.smc_ran_id",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_smc_ran_ip_att,
{ "SMC RAN IP address", "opsi.attr.smc_ran_ip",
FT_IPv4, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_smc_ran_name_att,
{ "SMC RAN name", "opsi.attr.smc_ran_name",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_smc_pop_id_att,
{ "SMC POP id", "opsi.attr.smc_pop_id",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_smc_pop_name_att,
{ "SMC POP name", "opsi.attr.smc_pop_name",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_smc_id_att,
{ "SMC ID", "opsi.attr.smc_id",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_smc_receive_time_att,
{ "SMC receive time", "opsi.attr.smc_receive_time",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x00,
NULL, HFILL }
},
{ &hf_smc_stat_time_att,
{ "SMC stat time", "opsi.attr.smc_stat_time",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_opsi_flags_att,
{ "OPSI flags", "opsi.attr.flags",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_opsi_application_name_att,
{ "OPSI application name", "opsi.attr.application_name",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_opsi_attribute_length,
{ "Length", "opsi.attr_length",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_opsi,
&ett_opsi_user_name,
&ett_opsi_user_password,
&ett_opsi_chap_password,
&ett_opsi_nas_ip_address,
&ett_opsi_nas_port,
&ett_opsi_service_type,
&ett_opsi_framed_protocol,
&ett_opsi_framed_address,
&ett_opsi_framed_netmask,
&ett_opsi_framed_routing,
&ett_opsi_framed_filter,
&ett_opsi_framed_mtu,
&ett_opsi_framed_compression,
&ett_opsi_called_station_id,
&ett_opsi_calling_station_id,
&ett_opsi_nas_identifier,
&ett_opsi_accounting,
&ett_opsi_acct_session_id,
&ett_opsi_chap_challenge,
&ett_opsi_nas_port_type,
&ett_opsi_designation_number,
&ett_opsi_nas_port_id,
&ett_opsi_smc_aaa_id,
&ett_opsi_smc_vpn_id,
&ett_opsi_smc_vpn_name,
&ett_opsi_smc_ran_id,
&ett_opsi_smc_ran_ip,
&ett_opsi_smc_ran_name,
&ett_opsi_smc_pop_id,
&ett_opsi_smc_pop_name,
&ett_opsi_smc_id,
&ett_opsi_smc_receive_time,
&ett_opsi_smc_stat_time,
&ett_opsi_flags,
&ett_opsi_application_name,
};
static ei_register_info ei[] = {
{ &ei_opsi_unknown_attribute, { "opsi.attr_unknown", PI_PROTOCOL, PI_WARN, "Unknown attribute", EXPFILL }},
{ &ei_opsi_short_attribute, { "opsi.attr_too_short", PI_MALFORMED, PI_WARN, "Too short attribute!", EXPFILL }},
{ &ei_opsi_short_frame, { "opsi.short_frame", PI_MALFORMED, PI_WARN, "Short frame", EXPFILL }},
};
module_t *opsi_module;
expert_module_t* expert_opsi;
proto_opsi = proto_register_protocol("Open Policy Service Interface",
"OPSI", "opsi");
proto_register_field_array(proto_opsi, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_opsi = expert_register_protocol(proto_opsi);
expert_register_field_array(expert_opsi, ei, array_length(ei));
opsi_module = prefs_register_protocol(proto_opsi, NULL);
prefs_register_bool_preference(opsi_module, "desegment_opsi_messages",
"Reassemble OPSI messages spanning multiple TCP segments",
"Whether the OPSI dissector should desegment all messages spanning multiple TCP segments",
&opsi_desegment);
}
void
proto_reg_handoff_opsi(void)
{
dissector_handle_t opsi_handle;
opsi_handle = new_create_dissector_handle(dissect_opsi, proto_opsi);
dissector_add_uint("tcp.port", TCP_PORT_OPSI, opsi_handle);
}
