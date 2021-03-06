static guint
get_wow_pdu_len(packet_info *pinfo, tvbuff_t *tvb, int offset, void *data _U_)
{
gint8 size_field_offset = -1;
guint8 cmd;
guint16 pkt_len;
cmd = tvb_get_guint8(tvb, offset);
if(WOW_SERVER_TO_CLIENT && cmd == REALM_LIST)
size_field_offset = 1;
if(WOW_CLIENT_TO_SERVER && cmd == AUTH_LOGON_CHALLENGE)
size_field_offset = 2;
pkt_len = tvb_get_letohs(tvb, size_field_offset);
return pkt_len + size_field_offset + 2;
}
static int
dissect_wow_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *wow_tree, *wow_realms_tree;
gchar *string, *realm_name;
guint8 cmd, srp_i_len, srp_g_len, srp_n_len;
guint16 num_realms;
guint32 offset = 0;
gint len, ii;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "WOW");
col_clear(pinfo->cinfo, COL_INFO);
cmd = tvb_get_guint8(tvb, offset);
col_set_str(pinfo->cinfo, COL_INFO,
val_to_str_const(cmd, cmd_vs,
"Unrecognized packet type"));
if(tree) {
ti = proto_tree_add_item(tree, proto_wow, tvb, 0, -1, ENC_NA);
wow_tree = proto_item_add_subtree(ti, ett_wow);
proto_tree_add_item(wow_tree, hf_wow_command, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
offset += 1;
switch(cmd) {
case AUTH_LOGON_CHALLENGE :
if(WOW_CLIENT_TO_SERVER) {
proto_tree_add_item(wow_tree, hf_wow_error, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(wow_tree, hf_wow_pkt_size,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
string = g_strreverse(tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 4, ENC_ASCII));
proto_tree_add_string(wow_tree, hf_wow_gamename,
tvb, offset, 4, string);
offset += 4;
proto_tree_add_item(wow_tree, hf_wow_version1,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(wow_tree, hf_wow_version2,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(wow_tree, hf_wow_version3,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(wow_tree, hf_wow_build, tvb,
offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
string = g_strreverse(tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 4, ENC_ASCII));
proto_tree_add_string(wow_tree, hf_wow_platform,
tvb, offset, 4, string);
offset += 4;
string = g_strreverse(tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 4, ENC_ASCII));
proto_tree_add_string(wow_tree, hf_wow_os, tvb,
offset, 4, string);
offset += 4;
string = g_strreverse(tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 4, ENC_ASCII));
proto_tree_add_string(wow_tree, hf_wow_country,
tvb, offset, 4, string);
offset += 4;
proto_tree_add_item(wow_tree,
hf_wow_timezone_bias,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(wow_tree, hf_wow_ip, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(wow_tree,
hf_wow_srp_i_len,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
srp_i_len = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(wow_tree,
hf_wow_srp_i, tvb,
offset, srp_i_len,
ENC_ASCII|ENC_NA);
} else if(WOW_SERVER_TO_CLIENT) {
proto_tree_add_item(wow_tree, hf_wow_error, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
offset += 1;
proto_tree_add_item(wow_tree, hf_wow_srp_b, tvb,
offset, 32, ENC_NA);
offset += 32;
proto_tree_add_item(wow_tree, hf_wow_srp_g_len,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
srp_g_len = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(wow_tree, hf_wow_srp_g, tvb,
offset, srp_g_len, ENC_NA);
offset += srp_g_len;
proto_tree_add_item(wow_tree, hf_wow_srp_n_len,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
srp_n_len = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(wow_tree, hf_wow_srp_n, tvb,
offset, srp_n_len, ENC_NA);
offset += srp_n_len;
proto_tree_add_item(wow_tree, hf_wow_srp_s, tvb,
offset, 32, ENC_NA);
}
break;
case AUTH_LOGON_PROOF :
if(WOW_CLIENT_TO_SERVER) {
proto_tree_add_item(wow_tree, hf_wow_srp_a, tvb,
offset, 32, ENC_NA);
offset += 32;
proto_tree_add_item(wow_tree, hf_wow_srp_m1,
tvb, offset, 20, ENC_NA);
offset += 20;
proto_tree_add_item(wow_tree, hf_wow_crc_hash,
tvb, offset, 20, ENC_NA);
offset += 20;
proto_tree_add_item(wow_tree, hf_wow_num_keys,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
} else if(WOW_SERVER_TO_CLIENT) {
proto_tree_add_item(wow_tree, hf_wow_error, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(wow_tree, hf_wow_srp_m2,
tvb, offset, 20, ENC_NA);
}
break;
case REALM_LIST :
if(WOW_CLIENT_TO_SERVER) {
} else if(WOW_SERVER_TO_CLIENT) {
proto_tree_add_item(wow_tree, hf_wow_pkt_size,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
offset += 4;
proto_tree_add_item(wow_tree, hf_wow_num_realms,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
num_realms = tvb_get_letohs(tvb, offset);
offset += 2;
for(ii = 0; ii < num_realms; ii++) {
realm_name = tvb_get_stringz_enc(wmem_packet_scope(), tvb,
offset + 3,
&len, ENC_ASCII);
wow_realms_tree = proto_tree_add_subtree(wow_tree, tvb,
offset, 0,
ett_wow_realms, NULL,
realm_name);
proto_tree_add_item(wow_realms_tree, hf_wow_realm_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(wow_realms_tree, hf_wow_realm_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(wow_realms_tree, hf_wow_realm_color, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_string(wow_realms_tree, hf_wow_realm_name, tvb, offset, len, realm_name);
offset += len;
string = tvb_get_stringz_enc(wmem_packet_scope(), tvb, offset,
&len, ENC_ASCII);
proto_tree_add_string(wow_realms_tree, hf_wow_realm_socket, tvb, offset, len, string);
offset += len;
proto_tree_add_item(wow_realms_tree, hf_wow_realm_population_level, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(wow_realms_tree, hf_wow_realm_num_characters, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(wow_realms_tree, hf_wow_realm_timezone, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
offset += 1;
}
break;
}
}
}
return tvb_captured_length(tvb);
}
static gboolean
dissect_wow(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
gint8 size_field_offset = -1;
guint8 cmd;
cmd = tvb_get_guint8(tvb, 0);
if(WOW_SERVER_TO_CLIENT && cmd == REALM_LIST)
size_field_offset = 1;
if(WOW_CLIENT_TO_SERVER && cmd == AUTH_LOGON_CHALLENGE)
size_field_offset = 2;
if(size_field_offset > -1) {
tcp_dissect_pdus(tvb, pinfo, tree, wow_preference_desegment,
size_field_offset+2, get_wow_pdu_len,
dissect_wow_pdu, data);
} else {
dissect_wow_pdu(tvb, pinfo, tree, data);
}
return TRUE;
}
void
proto_register_wow(void)
{
module_t *wow_module;
static hf_register_info hf[] = {
{ &hf_wow_command,
{ "Command", "wow.cmd",
FT_UINT8, BASE_HEX, VALS(cmd_vs), 0,
"Type of packet", HFILL }
},
{ &hf_wow_error,
{ "Error", "wow.error",
FT_UINT8, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_wow_pkt_size,
{ "Packet size", "wow.pkt_size",
FT_UINT16, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_wow_gamename,
{ "Game name", "wow.gamename",
FT_STRING, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_wow_version1,
{ "Version 1", "wow.version1",
FT_UINT8, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_wow_version2,
{ "Version 2", "wow.version2",
FT_UINT8, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_wow_version3,
{ "Version 3", "wow.version3",
FT_UINT8, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_wow_build,
{ "Build", "wow.build",
FT_UINT16, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_wow_platform,
{ "Platform", "wow.platform",
FT_STRING, BASE_NONE, 0, 0,
"CPU architecture of client system", HFILL }
},
{ &hf_wow_os,
{ "Operating system", "wow.os",
FT_STRING, BASE_NONE, 0, 0,
"Operating system of client system", HFILL }
},
{ &hf_wow_country,
{ "Country", "wow.country",
FT_STRING, BASE_NONE, 0, 0,
"Language and country of client system", HFILL }
},
{ &hf_wow_timezone_bias,
{ "Timezone bias", "wow.timezone_bias",
FT_UINT32, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_wow_ip,
{ "IP address", "wow.ip",
FT_IPv4, BASE_NONE, 0, 0,
"Client's actual IP address", HFILL }
},
{ &hf_wow_srp_i_len,
{ "SRP I length", "wow.srp.i_len",
FT_UINT8, BASE_DEC, 0, 0,
"Secure Remote Password protocol 'I' value length", HFILL }
},
{ &hf_wow_srp_i,
{ "SRP I", "wow.srp.i",
FT_STRING, BASE_NONE, 0, 0,
"Secure Remote Password protocol 'I' value (username)", HFILL }
},
{ &hf_wow_srp_b,
{ "SRP B", "wow.srp.b",
FT_BYTES, BASE_NONE, 0, 0,
"Secure Remote Password protocol 'B' value (one of the public ephemeral values)", HFILL }
},
{ &hf_wow_srp_g_len,
{ "SRP g length", "wow.srp.g_len",
FT_UINT8, BASE_DEC, 0, 0,
"Secure Remote Password protocol 'g' value length",
HFILL }
},
{ &hf_wow_srp_g,
{ "SRP g", "wow.srp.g",
FT_BYTES, BASE_NONE, 0, 0,
"Secure Remote Password protocol 'g' value", HFILL }
},
{ &hf_wow_srp_n_len,
{ "SRP N length", "wow.srp.n_len",
FT_UINT8, BASE_DEC, 0, 0,
"Secure Remote Password protocol 'N' value length",
HFILL }
},
{ &hf_wow_srp_n,
{ "SRP N", "wow.srp.n",
FT_BYTES, BASE_NONE, 0, 0,
"Secure Remote Password protocol 'N' value (a large safe prime)", HFILL }
},
{ &hf_wow_srp_s,
{ "SRP s", "wow.srp.s",
FT_BYTES, BASE_NONE, 0, 0,
"Secure Remote Password protocol 's' (user's salt) value",
HFILL }
},
{ &hf_wow_srp_a,
{ "SRP A", "wow.srp.a",
FT_BYTES, BASE_NONE, 0, 0,
"Secure Remote Password protocol 'A' value (one of the public ephemeral values)", HFILL }
},
{ &hf_wow_srp_m1,
{ "SRP M1", "wow.srp.m1",
FT_BYTES, BASE_NONE, 0, 0,
"Secure Remote Password protocol 'M1' value", HFILL }
},
{ &hf_wow_crc_hash,
{ "CRC hash", "wow.crc_hash",
FT_BYTES, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_wow_num_keys,
{ "Number of keys", "wow.num_keys",
FT_UINT8, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_wow_srp_m2,
{ "SRP M2", "wow.srp.m2",
FT_BYTES, BASE_NONE, 0, 0,
"Secure Remote Password protocol 'M2' value", HFILL }
},
{ &hf_wow_num_realms,
{ "Number of realms", "wow.num_realms",
FT_UINT16, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_wow_realm_type,
{ "Type", "wow.realm_type",
FT_UINT8, BASE_DEC, VALS(realm_type_vs), 0,
"Also known as realm icon", HFILL }
},
{ &hf_wow_realm_status,
{ "Status", "wow.realm_status",
FT_UINT8, BASE_DEC, VALS(realm_status_vs), 0,
NULL, HFILL }
},
{ &hf_wow_realm_color,
{ "Color", "wow.realm_color",
FT_UINT8, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_wow_realm_name,
{ "Name", "wow.realm_name",
FT_STRINGZ, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_wow_realm_socket,
{ "Server socket", "wow.realm_socket",
FT_STRINGZ, BASE_NONE, 0, 0,
"IP address and port to connect to on the server to reach this realm", HFILL }
},
{ &hf_wow_realm_population_level,
{ "Population level", "wow.realm_population_level",
FT_FLOAT, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_wow_realm_num_characters,
{ "Number of characters", "wow.realm_num_characters",
FT_UINT8, BASE_DEC, 0, 0,
"Number of characters the user has in this realm", HFILL }
},
{ &hf_wow_realm_timezone,
{ "Timezone", "wow.realm_timezone",
FT_UINT8, BASE_DEC, 0, 0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_wow,
&ett_wow_realms
};
proto_wow = proto_register_protocol("World of Warcraft",
"WOW", "wow");
proto_register_field_array(proto_wow, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
wow_module = prefs_register_protocol(proto_wow, NULL);
prefs_register_bool_preference(wow_module, "desegment", "Reassemble wow messages spanning multiple TCP segments.", "Whether the wow dissector should reassemble messages spanning multiple TCP segments. To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.", &wow_preference_desegment);
}
void
proto_reg_handoff_wow(void)
{
dissector_handle_t wow_handle;
wow_handle = create_dissector_handle(dissect_wow, proto_wow);
dissector_add_uint_with_preference("tcp.port", WOW_PORT, wow_handle);
}
