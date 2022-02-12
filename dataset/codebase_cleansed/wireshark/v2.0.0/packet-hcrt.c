static void dissect_hcrt_body(tvbuff_t* tvb, proto_tree* tree , int* offset,
int type, int addr_mode, int adl, int body_len)
{
proto_item* ti_body;
proto_tree* hcrt_body_tree;
gint i;
ti_body = proto_tree_add_item(tree, hf_hcrt_body, tvb, *offset, body_len, ENC_NA);
hcrt_body_tree = proto_item_add_subtree(ti_body, ett_hcrt_body);
switch (type) {
case HCRT_NOP:
proto_tree_add_item(hcrt_body_tree, hf_hcrt_command_nop, tvb, *offset,
body_len, ENC_NA);
break;
case HCRT_WRITE:
if (addr_mode == ADDR_MODE_32) {
proto_tree_add_item(hcrt_body_tree, hf_hcrt_addr_32, tvb, *offset,
4, ENC_LITTLE_ENDIAN);
for (i = 1; i <= adl; i++) {
proto_tree_add_item(hcrt_body_tree, hf_hcrt_data_32, tvb,
*offset + i * 4, 4, ENC_LITTLE_ENDIAN);
}
} else {
proto_tree_add_item(hcrt_body_tree, hf_hcrt_addr_64, tvb, *offset,
8, ENC_LITTLE_ENDIAN);
for (i = 1; i <= adl; i++)
proto_tree_add_item(hcrt_body_tree, hf_hcrt_data_64, tvb,
*offset + i * 8, 8, ENC_LITTLE_ENDIAN);
}
break;
case HCRT_READ:
if (addr_mode == ADDR_MODE_32) {
proto_tree_add_item(hcrt_body_tree, hf_hcrt_addr_32, tvb, *offset, 4,
ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(hcrt_body_tree, hf_hcrt_addr_64, tvb, *offset, 8,
ENC_LITTLE_ENDIAN);
}
break;
case HCRT_RESPONSE:
if (body_len > 0) {
proto_tree_add_item(hcrt_body_tree, hf_hcrt_command_nop, tvb, *offset,
body_len, ENC_NA);
}
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
(*offset) += body_len;
}
static gboolean dissect_hcrt_header(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree,
int* offset, guint8 b0_first, guint8 b0_current)
{
proto_item* ti_hdr;
proto_tree* hcrt_hdr_tree;
gboolean last;
guint8 type;
ti_hdr = proto_tree_add_item(tree, hf_hcrt_header, tvb, *offset, 4, ENC_NA);
hcrt_hdr_tree = proto_item_add_subtree(ti_hdr, ett_hcrt_hdr);
if (b0_first != b0_current) {
expert_add_info_format(pinfo, hcrt_hdr_tree, &ei_hcrt_error,
"Invalid Byte 0 in Header. Must be equal in all HCrt messages. "
"Expected: %.2X, got: %.2X", b0_first, b0_current);
}
type = (b0_current & 0x30) >> 4;
proto_tree_add_item(hcrt_hdr_tree, hf_hcrt_message_tag, tvb,
*offset, 1, ENC_NA);
proto_tree_add_item(hcrt_hdr_tree, hf_hcrt_message_type, tvb,
*offset, 1, ENC_NA);
proto_tree_add_item(hcrt_hdr_tree, hf_hcrt_am, tvb,
*offset, 1, ENC_NA);
proto_tree_add_item(hcrt_hdr_tree, hf_hcrt_do, tvb,
*offset, 1, ENC_NA);
(*offset)++;
if (type != HCRT_RESPONSE) {
proto_tree_add_item(hcrt_hdr_tree, hf_hcrt_1st_dword_enable, tvb,
*offset, 1, ENC_NA);
} else {
proto_tree_add_item(hcrt_hdr_tree, hf_hcrt_resp_code, tvb,
*offset, 1, ENC_NA);
}
if (type != HCRT_RESPONSE) {
proto_tree_add_item(hcrt_hdr_tree, hf_hcrt_last_dword_enable, tvb,
*offset, 1, ENC_NA);
}
(*offset)++;
proto_tree_add_item(hcrt_hdr_tree, hf_hcrt_adl, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(hcrt_hdr_tree, hf_hcrt_last, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
last = (tvb_get_letohs(tvb, *offset) & 0x8000) != 0;
(*offset) += 2;
return last;
}
static gboolean dissect_hcrt_message(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree,
int* offset, guint8 b0_first, int i)
{
gboolean last;
guint adl;
guint addr_mode;
guint body_len;
proto_tree* hcrt_msg_tree;
guint8 b0_current;
int type;
b0_current = tvb_get_guint8(tvb, *offset);
adl = tvb_get_letohs(tvb, *offset + 2) & 0x0FFF;
addr_mode = (1 + ((b0_current & 0x40) >> 6));
type = (b0_current & 0x30) >> 4;
switch (type) {
case HCRT_NOP:
body_len = 4 * addr_mode * adl;
break;
case HCRT_WRITE:
body_len = 4 * addr_mode * (adl + 1);
break;
case HCRT_READ:
body_len = 4 * addr_mode;
break;
case HCRT_RESPONSE:
body_len = 4 * addr_mode * adl;
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
hcrt_msg_tree = proto_tree_add_subtree_format(tree, tvb, *offset,
HCRT_HDR_LEN + body_len, ett_hcrt_msg, NULL, "Message %d", i);
last = dissect_hcrt_header(tvb, pinfo, hcrt_msg_tree, offset, b0_first, b0_current);
dissect_hcrt_body(tvb, hcrt_msg_tree, offset, type, addr_mode, adl, body_len);
return last;
}
static void dissect_hcrt(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree)
{
guint8 type;
proto_item* ti;
proto_tree* hcrt_tree;
guint offset;
int i = 1;
guint8 b0_first;
guint8 tag;
guint adl;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HCrt");
col_clear(pinfo->cinfo, COL_INFO);
b0_first = tvb_get_guint8(tvb, 0);
tag = b0_first & 0x0F;
type = (b0_first & 0x30) >> 4;
adl = tvb_get_letohs(tvb, 2) & 0x0FFF;
col_add_fstr(pinfo->cinfo, COL_INFO, "Type: %s, Tag: 0x%X, ADL: %u",
val_to_str(type, hcrt_message_types, "Unknown (0x%02x)"), tag, adl);
if (adl == 1) {
if (type == HCRT_READ || type == HCRT_WRITE) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Address: 0x%.8X", tvb_get_letohl(tvb, 4));
}
if (type == HCRT_WRITE) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Data: 0x%.8X", tvb_get_letohl(tvb, 8));
}
}
offset = 0;
ti = proto_tree_add_item(tree, proto_hcrt, tvb, 0, -1, ENC_NA);
hcrt_tree = proto_item_add_subtree(ti, ett_hcrt);
while (!dissect_hcrt_message(tvb, pinfo, hcrt_tree, &offset, b0_first, i)) {
i++;
}
}
void proto_register_hcrt(void)
{
expert_module_t* expert_hcrt;
module_t* hcrt_module;
static hf_register_info hf[] = {
{ &hf_hcrt_header,
{ "Header", "hcrt.hdr",
FT_NONE, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_hcrt_message_tag,
{ "Tag", "hcrt.tag",
FT_UINT8, BASE_HEX,
NULL, 0x0F,
NULL, HFILL }
},
{ &hf_hcrt_message_type,
{ "Type", "hcrt.type",
FT_UINT8, BASE_DEC,
VALS(hcrt_message_types), 0x30,
NULL, HFILL }
},
{ &hf_hcrt_am,
{ "Addressing Mode", "hcrt.am",
FT_UINT8, BASE_DEC,
VALS(hcrt_ams), 0x40,
NULL, HFILL }
},
{ &hf_hcrt_do,
{ "Discovery Operation", "hcrt.do",
FT_BOOLEAN, 8,
TFS(&hcrt_dos), 0x80,
NULL, HFILL }
},
{ &hf_hcrt_1st_dword_enable,
{ "1st DWORD enable", "hcrt.first_dword_enable",
FT_UINT8, BASE_HEX,
VALS(dword_enable_vals), 0xF0,
NULL, HFILL }
},
{ &hf_hcrt_last_dword_enable,
{ "Last DWORD enable", "hcrt.last_dword_enable",
FT_UINT8, BASE_HEX,
VALS(dword_enable_vals), 0x0F,
NULL, HFILL }
},
{ &hf_hcrt_resp_code,
{ "Response code", "hcrt.response_code",
FT_UINT8, BASE_HEX,
VALS(response_codes), 0xF0,
NULL, HFILL }
},
{ &hf_hcrt_adl,
{ "ADL", "hcrt.adl",
FT_UINT16, BASE_DEC,
NULL, 0x0FFF,
NULL, HFILL }
},
{ &hf_hcrt_last,
{ "Last message", "hcrt.last",
FT_BOOLEAN, 16,
NULL, 0x8000,
NULL, HFILL }
},
{ &hf_hcrt_body,
{ "Body", "hcrt.body",
FT_NONE, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_hcrt_addr_32,
{ "Address", "hcrt.address32",
FT_UINT32, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hcrt_addr_64,
{ "Address", "hcrt.address64",
FT_UINT64, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hcrt_data_32,
{ "Data", "hcrt.data32",
FT_UINT32, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hcrt_data_64,
{ "Data", "hcrt.data32",
FT_UINT64, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hcrt_command_nop,
{ "Command", "hcrt.command_nop",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
}
};
static ei_register_info ei[] = {
{ &ei_hcrt_error, { "hcrt.error", PI_MALFORMED, PI_ERROR, "Unusual error code", EXPFILL }}
};
static gint* ett[] = {
&ett_hcrt,
&ett_hcrt_msg,
&ett_hcrt_hdr,
&ett_hcrt_body,
};
proto_hcrt = proto_register_protocol (
"Hotline Command-Response Transaction protocol",
"HCrt",
"hcrt"
);
proto_register_field_array(proto_hcrt, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_hcrt = expert_register_protocol(proto_hcrt);
expert_register_field_array(expert_hcrt, ei, array_length(ei));
range_convert_str(&hcrt_port_range_default, HCRT_UDP_PORTS_DEFAULT, MAX_UDP_PORT);
hcrt_module = prefs_register_protocol(proto_hcrt, proto_reg_handoff_hcrt);
prefs_register_range_preference(hcrt_module,
"dissector_udp_port",
"UDP port",
"The UDP port used in L3 communications (default " HCRT_UDP_PORTS_DEFAULT ")",
&hcrt_port_range_default, MAX_UDP_PORT);
prefs_register_uint_preference(hcrt_module,
"dissector_ethertype",
"Ethernet type",
"The ethernet type used for L2 communications",
10, &ethertype_pref);
}
void proto_reg_handoff_hcrt(void)
{
static dissector_handle_t hcrt_handle;
static gboolean hcrt_prefs_initialized = FALSE;
static range_t* hcrt_port_range;
static gint hcrt_ethertype;
if (!hcrt_prefs_initialized) {
hcrt_handle = create_dissector_handle(dissect_hcrt, proto_hcrt);
dissector_add_for_decode_as("tcp.port", hcrt_handle);
hcrt_prefs_initialized = TRUE;
} else {
dissector_delete_uint("ethertype", hcrt_ethertype, hcrt_handle);
dissector_delete_uint_range("udp.port", hcrt_port_range, hcrt_handle);
g_free(hcrt_port_range);
}
hcrt_port_range = range_copy(hcrt_port_range_default);
hcrt_ethertype = ethertype_pref;
dissector_add_uint("ethertype", hcrt_ethertype, hcrt_handle);
dissector_add_uint_range("udp.port", hcrt_port_range, hcrt_handle);
}
