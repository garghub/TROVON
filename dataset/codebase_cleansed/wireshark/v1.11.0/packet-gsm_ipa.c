static gint
dissect_ipa_attr(tvbuff_t *tvb, int base_offs, proto_tree *tree)
{
guint8 len, attr_type;
int offset = base_offs;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
attr_type = tvb_get_guint8(tvb, offset);
switch (attr_type) {
case 0x00:
len = tvb_get_guint8(tvb, offset+1);
proto_tree_add_item(tree, hf_ipaccess_attr_tag,
tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ipaccess_attr_string,
tvb, offset+3, len-1, ENC_ASCII|ENC_NA);
break;
case 0x01:
len = 0;
proto_tree_add_item(tree, hf_ipaccess_attr_tag,
tvb, offset+1, 1, ENC_BIG_ENDIAN);
break;
default:
len = 0;
proto_tree_add_text(tree, tvb, offset+1, 1,
"unknown attribute type 0x%02x",
attr_type);
break;
};
offset += len + 2;
};
return offset;
}
static gint
dissect_ipaccess(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *ipaccess_tree;
guint8 msg_type;
msg_type = tvb_get_guint8(tvb, 0);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(msg_type, ipaccess_msgtype_vals,
"unknown 0x%02x"));
if (tree) {
ti = proto_tree_add_item(tree, proto_ipaccess, tvb, 0, -1, ENC_NA);
ipaccess_tree = proto_item_add_subtree(ti, ett_ipaccess);
proto_tree_add_item(ipaccess_tree, hf_ipaccess_msgtype,
tvb, 0, 1, ENC_BIG_ENDIAN);
switch (msg_type) {
case 4:
case 5:
dissect_ipa_attr(tvb, 1, ipaccess_tree);
break;
}
}
return 1;
}
static gint
dissect_osmo(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ipatree, proto_tree *tree)
{
tvbuff_t *next_tvb;
guint8 osmo_proto;
osmo_proto = tvb_get_guint8(tvb, 0);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(osmo_proto, ipa_osmo_proto_vals,
"unknown 0x%02x"));
if (ipatree) {
proto_tree_add_item(ipatree, hf_ipa_osmo_proto,
tvb, 0, 1, ENC_BIG_ENDIAN);
}
next_tvb = tvb_new_subset_remaining(tvb, 1);
if (dissector_try_uint(osmo_dissector_table, osmo_proto, next_tvb, pinfo, tree))
return 1;
if (osmo_proto == IPAC_PROTO_EXT_MGCP) {
call_dissector(sub_handles[SUB_MGCP], next_tvb, pinfo, tree);
return 1;
} else if (osmo_proto == IPAC_PROTO_EXT_CTRL) {
if (tree) {
proto_tree_add_item(tree, hf_ipa_osmo_ctrl_data, next_tvb, 0, -1, ENC_ASCII|ENC_NA);
}
return 1;
}
call_dissector(sub_handles[SUB_DATA], next_tvb, pinfo, tree);
return 1;
}
static void
dissect_ipa(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gint remaining;
gint header_length = 3;
int offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IPA");
col_clear(pinfo->cinfo, COL_INFO);
while ((remaining = tvb_reported_length_remaining(tvb, offset)) > 0) {
proto_item *ti;
proto_tree *ipa_tree = NULL;
guint16 len, msg_type;
tvbuff_t *next_tvb;
len = tvb_get_ntohs(tvb, offset);
msg_type = tvb_get_guint8(tvb, offset+2);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(msg_type, ipa_protocol_vals,
"unknown 0x%02x"));
if ((pinfo->ipproto == IP_PROTO_UDP) && (len + 4 == remaining)) {
header_length++;
}
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_ipa,
tvb, offset, len+header_length,
"IPA protocol ip.access, type: %s",
val_to_str(msg_type, ipa_protocol_vals,
"unknown 0x%02x"));
ipa_tree = proto_item_add_subtree(ti, ett_ipa);
proto_tree_add_item(ipa_tree, hf_ipa_data_len,
tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ipa_tree, hf_ipa_protocol,
tvb, offset+2, 1, ENC_BIG_ENDIAN);
}
next_tvb = tvb_new_subset(tvb, offset+header_length, len, len);
switch (msg_type) {
case ABISIP_OML:
if (sub_handles[SUB_OML])
call_dissector(sub_handles[SUB_OML], next_tvb,
pinfo, tree);
break;
case ABISIP_IPACCESS:
dissect_ipaccess(next_tvb, pinfo, tree);
break;
case AIP_SCCP:
call_dissector(sub_handles[SUB_SCCP], next_tvb, pinfo, tree);
break;
case IPA_MGCP:
call_dissector(sub_handles[SUB_MGCP], next_tvb, pinfo, tree);
break;
case OSMO_EXT:
dissect_osmo(next_tvb, pinfo, ipa_tree, tree);
break;
case HSL_DEBUG:
if (tree) {
proto_tree_add_item(ipa_tree, hf_ipa_hsl_debug,
next_tvb, 0, len, ENC_ASCII|ENC_NA);
if (global_ipa_in_root == TRUE)
proto_tree_add_item(tree, hf_ipa_hsl_debug,
next_tvb, 0, len, ENC_ASCII|ENC_NA);
}
if (global_ipa_in_info == TRUE)
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ",
tvb_get_stringz(wmem_packet_scope(), next_tvb, 0, NULL));
break;
default:
if (msg_type < ABISIP_RSL_MAX) {
call_dissector(sub_handles[SUB_RSL], next_tvb, pinfo, tree);
}
break;
}
offset += len + header_length;
}
}
void proto_register_ipa(void)
{
module_t *ipa_module;
static hf_register_info hf[] = {
{&hf_ipa_data_len,
{"DataLen", "gsm_ipa.data_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The length of the data (in bytes)", HFILL}
},
{&hf_ipa_protocol,
{"Protocol", "gsm_ipa.protocol",
FT_UINT8, BASE_HEX, VALS(ipa_protocol_vals), 0x0,
"The IPA Sub-Protocol", HFILL}
},
{&hf_ipa_hsl_debug,
{"Debug Message", "gsm_ipa.hsl_debug",
FT_STRING, BASE_NONE, NULL, 0,
"Hay Systems Limited debug message", HFILL}
},
{&hf_ipa_osmo_proto,
{"Osmo ext protocol", "gsm_ipa.osmo.protocol",
FT_UINT8, BASE_HEX, VALS(ipa_osmo_proto_vals), 0x0,
"The osmo extension protocol", HFILL}
},
{&hf_ipa_osmo_ctrl_data,
{"CTRL data", "gsm_ipa.ctrl.data",
FT_STRING, BASE_NONE, NULL, 0x0,
"Control interface data", HFILL}
},
};
static hf_register_info hf_ipa[] = {
{&hf_ipaccess_msgtype,
{"MessageType", "ipaccess.msg_type",
FT_UINT8, BASE_HEX, VALS(ipaccess_msgtype_vals), 0x0,
"Type of ip.access messsage", HFILL}
},
{&hf_ipaccess_attr_tag,
{"Tag", "ipaccess.attr_tag",
FT_UINT8, BASE_HEX, VALS(ipaccess_idtag_vals), 0x0,
"Attribute Tag", HFILL}
},
{&hf_ipaccess_attr_string,
{"String", "ipaccess.attr_string",
FT_STRING, BASE_NONE, NULL, 0x0,
"String attribute", HFILL}
},
};
static gint *ett[] = {
&ett_ipa,
&ett_ipaccess,
};
proto_ipa =
proto_register_protocol("GSM over IP protocol as used by ip.access",
"GSM over IP", "gsm_ipa");
proto_ipaccess =
proto_register_protocol("GSM over IP ip.access CCM sub-protocol",
"IPA", "ipaccess");
proto_register_field_array(proto_ipa, hf, array_length(hf));
proto_register_field_array(proto_ipaccess, hf_ipa, array_length(hf_ipa));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("gsm_ipa", dissect_ipa, proto_ipa);
osmo_dissector_table = register_dissector_table("ipa.osmo.protocol",
"GSM over IP ip.access Protocol",
FT_UINT8, BASE_DEC);
range_convert_str(&global_ipa_tcp_ports, IPA_TCP_PORTS, MAX_TCP_PORT);
range_convert_str(&global_ipa_udp_ports, IPA_UDP_PORTS_DEFAULT, MAX_UDP_PORT);
ipa_module = prefs_register_protocol(proto_ipa,
proto_reg_handoff_gsm_ipa);
prefs_register_range_preference(ipa_module, "tcp_ports",
"GSM IPA TCP Port(s)",
"Set the port(s) for ip.access IPA"
" (default: " IPA_TCP_PORTS ")",
&global_ipa_tcp_ports, MAX_TCP_PORT);
prefs_register_range_preference(ipa_module, "udp_ports",
"GSM IPA UDP Port(s)",
"Set the port(s) for ip.access IPA"
" (usually: " IPA_UDP_PORTS ")",
&global_ipa_udp_ports, MAX_UDP_PORT);
prefs_register_bool_preference(ipa_module, "hsl_debug_in_root_tree",
"HSL Debug messages in root protocol tree",
NULL, &global_ipa_in_root);
prefs_register_bool_preference(ipa_module, "hsl_debug_in_info",
"HSL Debug messages in INFO column",
NULL, &global_ipa_in_info);
}
void proto_reg_handoff_gsm_ipa(void)
{
static gboolean ipa_initialized = FALSE;
static range_t *ipa_tcp_ports, *ipa_udp_ports;
if (!ipa_initialized) {
sub_handles[SUB_RSL] = find_dissector("gsm_abis_rsl");
sub_handles[SUB_OML] = find_dissector("gsm_abis_oml");
sub_handles[SUB_SCCP] = find_dissector("sccp");
sub_handles[SUB_MGCP] = find_dissector("mgcp");
sub_handles[SUB_DATA] = find_dissector("data");
ipa_handle = create_dissector_handle(dissect_ipa, proto_ipa);
ipa_initialized = TRUE;
} else {
dissector_delete_uint_range("tcp.port", ipa_tcp_ports, ipa_handle);
g_free(ipa_tcp_ports);
dissector_delete_uint_range("udp.port", ipa_udp_ports, ipa_handle);
g_free(ipa_udp_ports);
}
ipa_tcp_ports = range_copy(global_ipa_tcp_ports);
ipa_udp_ports = range_copy(global_ipa_udp_ports);
dissector_add_uint_range("udp.port", ipa_udp_ports, ipa_handle);
dissector_add_uint_range("tcp.port", ipa_tcp_ports, ipa_handle);
}
