static guint
get_ipdc_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
guint raw_len = (tvb_get_ntohs(tvb,offset+2) & 0x03FF);
return raw_len + 4;
}
static int
dissect_ipdc_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *ipdc_tree;
proto_tree *tag_tree, *line_tree;
tvbuff_t *q931_tvb;
const char *des;
const char *enum_val = "";
char tmp_tag_text[IPDC_STR_LEN + 1];
const value_string *val_ptr;
gint hf_ptr;
guint32 type;
guint len;
guint i;
guint status;
gshort tag;
guint32 tmp_tag;
gshort nr = tvb_get_guint8(tvb,0);
gshort ns = tvb_get_guint8(tvb,1);
guint payload_len = get_ipdc_pdu_len(pinfo,tvb,0,NULL);
gshort trans_id_size;
guint32 trans_id;
guint16 message_code;
guint16 offset;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IPDC");
if (payload_len < 4)
return 0;
col_append_fstr(pinfo->cinfo, COL_INFO, "r=%u s=%u ", nr, ns);
if (payload_len == 4) {
ti = proto_tree_add_item(tree, proto_ipdc, tvb, 0, -1, ENC_NA);
ipdc_tree = proto_item_add_subtree(ti, ett_ipdc);
proto_tree_add_item(ipdc_tree, hf_ipdc_nr, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ipdc_tree, hf_ipdc_ns, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(ipdc_tree, hf_ipdc_payload_len, tvb, 2, 2,
payload_len);
col_set_fence(pinfo->cinfo, COL_INFO);
return 4;
}
trans_id_size = TRANS_ID_SIZE_IPDC;
trans_id = tvb_get_ntohl(tvb,6);
message_code = tvb_get_ntohs(tvb,6+trans_id_size);
offset = 6 + trans_id_size + 2;
col_append_fstr(pinfo->cinfo, COL_INFO,
"TID=%x %s ",
trans_id,
val_to_str_const(message_code, message_code_vals,
TEXT_UNDEFINED));
ti = proto_tree_add_item(tree, proto_ipdc, tvb, 0, -1, ENC_NA);
ipdc_tree = proto_item_add_subtree(ti, ett_ipdc);
proto_tree_add_item(ipdc_tree, hf_ipdc_nr, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ipdc_tree, hf_ipdc_ns, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(ipdc_tree, hf_ipdc_payload_len, tvb,
2, 2, payload_len);
proto_tree_add_item(ipdc_tree, hf_ipdc_protocol_id, tvb,
4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ipdc_tree, hf_ipdc_trans_id_size, tvb,
5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ipdc_tree, hf_ipdc_trans_id, tvb,
6, trans_id_size, ENC_NA);
proto_tree_add_item(ipdc_tree, hf_ipdc_message_code, tvb,
6 + trans_id_size, 2, ENC_BIG_ENDIAN);
tag_tree = proto_tree_add_subtree(ipdc_tree, tvb, offset, payload_len - offset,
ett_ipdc_tag, NULL, "IPDC tags");
for (;;) {
tag = tvb_get_guint8(tvb, offset);
if (tag == 0x0) {
if (offset == payload_len - 1) {
proto_tree_add_item(tag_tree, hf_ipdc_end_of_tags, tvb, offset, 1, ENC_NA);
} else {
proto_tree_add_item(tag_tree, hf_ipdc_data_trailing_end_of_tags, tvb, offset, 1, ENC_NA);
}
break;
}
len = tvb_get_guint8(tvb,offset+1);
des = val_to_str_ext_const(tag, &tag_description_ext, TEXT_UNDEFINED);
for (i = 0; (ipdc_tag_types[i].tag != tag &&
ipdc_tag_types[i].type != IPDC_UNKNOWN); i++)
;
type = ipdc_tag_types[i].type;
tmp_tag = 0;
switch (type) {
case IPDC_ASCII:
DISSECTOR_ASSERT(len<=IPDC_STR_LEN);
tvb_memcpy(tvb, tmp_tag_text, offset+2, len);
tmp_tag_text[len] = 0;
proto_tree_add_string_format(tag_tree, hf_ipdc_ascii, tvb, offset,
len + 2, tmp_tag_text, "%s (0x%2.2x): %s", des, tag,
tmp_tag_text);
break;
case IPDC_UINT:
case IPDC_BYTE:
for (i = 0; i < len; i++)
tmp_tag += tvb_get_guint8(tvb,
offset + 2 + i) * (guint32)pow(256, len - (i + 1));
if (len == 1)
enum_val =
val_to_str_ext_const(IPDC_TAG(tag) + tmp_tag,
&tag_enum_type_ext, TEXT_UNDEFINED);
if (len == 1 && strcmp(enum_val, TEXT_UNDEFINED) != 0) {
proto_tree_add_uint_format(tag_tree, hf_ipdc_uint, tvb,
offset, len + 2, tmp_tag,
"%s (0x%2.2x): %s",
des, tag, enum_val);
} else {
proto_tree_add_uint_format(tag_tree, hf_ipdc_uint, tvb,
offset, len + 2, tmp_tag,
"%s (0x%2.2x): %u",
des, tag, tmp_tag);
}
break;
case IPDC_IPA:
switch (len) {
case 4:
proto_tree_add_ipv4_format(tag_tree, hf_ipdc_ipv4, tvb,
offset, len + 2, tvb_get_ntohl(tvb, offset + 2),
"%s (0x%2.2x): %s",
des, tag, tvb_ip_to_str(tvb, offset + 2));
break;
case 6:
proto_tree_add_ipv4_format(tag_tree, hf_ipdc_ipv4, tvb,
offset, len + 2, tvb_get_ntohl(tvb, offset + 2),
"%s (0x%2.2x): %s:%u",
des, tag, tvb_ip_to_str(tvb, offset + 2), tvb_get_ntohs(tvb, offset + 6));
break;
default:
proto_tree_add_expert_format(tag_tree, pinfo, &ei_ipdc_ipv4, tvb, offset, len + 2, "%s (0x%2.2x): Invalid IP address length %u",
des, tag, len);
}
break;
case IPDC_LINESTATUS:
case IPDC_CHANNELSTATUS:
line_tree = proto_tree_add_subtree_format(tag_tree, tvb, offset, len + 2, ett_ipdc_line_status, NULL, "%s (0x%2.2x)", des, tag);
val_ptr = (type == IPDC_LINESTATUS) ? line_status_vals : channel_status_vals;
hf_ptr = (type == IPDC_LINESTATUS) ? hf_ipdc_line_status : hf_ipdc_channel_status;
for (i = 0; i < len; i++) {
status = tvb_get_guint8(tvb,offset+2+i);
proto_tree_add_uint_format(line_tree, hf_ptr, tvb,
offset + 2 + i, 1, status,
"%s (0x%2.2x) %.2u: %u (%s)",
des, tag, i + 1, status,
val_to_str_const(status,
val_ptr,
TEXT_UNDEFINED));
}
break;
case IPDC_Q931:
q931_tvb =
tvb_new_subset_length(tvb, offset+2, len);
call_dissector(q931_handle,q931_tvb,pinfo,tree);
break;
case IPDC_ENCTYPE:
proto_tree_add_uint_format(tag_tree, hf_ipdc_enctype, tvb,
offset, len + 2, tvb_get_guint8(tvb,offset+2),
"%s (0x%2.2x): %s",
des, tag, val_to_str_const(
tvb_get_guint8(tvb,offset+2),
encoding_type_vals,
TEXT_UNDEFINED));
if (len == 2) {
proto_tree_add_uint_format(tag_tree, hf_ipdc_enctype, tvb,
offset, len + 2, tvb_get_guint8(tvb,offset+3),
"%s (0x%2.2x): %u",
des, tag, tvb_get_guint8(tvb,offset+3));
}
break;
default:
proto_tree_add_bytes_format(tag_tree, hf_ipdc_type_unknown, tvb, offset, len + 2, NULL, "0x%2.2x: %s", tag, des);
}
offset += len + 2;
}
col_set_fence(pinfo->cinfo, COL_INFO);
return tvb_captured_length(tvb);
}
static int
dissect_ipdc_tcp_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
return dissect_ipdc_common(tvb, pinfo, tree, data);
}
static int
dissect_ipdc_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, tree, ipdc_desegment, 4,
get_ipdc_pdu_len, dissect_ipdc_tcp_pdu, data);
return tvb_captured_length(tvb);
}
void
proto_register_ipdc(void)
{
static hf_register_info hf[] = {
{ &hf_ipdc_nr,
{ "N(r)", "ipdc.nr",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Receive sequence number", HFILL }
},
{ &hf_ipdc_ns,
{ "N(s)", "ipdc.ns",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Transmit sequence number", HFILL }
},
{ &hf_ipdc_payload_len,
{ "Payload length", "ipdc.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipdc_protocol_id,
{ "Protocol ID", "ipdc.protocol_id",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipdc_trans_id_size,
{ "Transaction ID size", "ipdc.trans_id_size",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipdc_trans_id,
{ "Transaction ID", "ipdc.trans_id",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipdc_message_code,
{ "Message code", "ipdc.message_code",
FT_UINT16, BASE_HEX, VALS(message_code_vals), 0x0,
NULL, HFILL }
},
{ &hf_ipdc_ascii,
{ "ASCII value", "ipdc.ascii",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipdc_uint,
{ "Byte/UINT value", "ipdc.uint",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipdc_ipv4,
{ "IPv4 value", "ipdc.ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipdc_line_status,
{ "Line Status value", "ipdc.line_status",
FT_UINT8, BASE_DEC, VALS(line_status_vals), 0x0,
NULL, HFILL }
},
{ &hf_ipdc_channel_status,
{ "Channel Status value", "ipdc.channel_status",
FT_UINT8, BASE_DEC, VALS(channel_status_vals), 0x0,
NULL, HFILL }
},
{ &hf_ipdc_enctype,
{ "Enctype value", "ipdc.enctype",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipdc_end_of_tags,
{ "end of tags", "ipdc.end_of_tags",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipdc_data_trailing_end_of_tags,
{ "data trailing end of tags", "ipdc.data_trailing_end_of_tags",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ipdc_type_unknown,
{ "Unknown type", "ipdc.type_unknown",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_ipdc,
&ett_ipdc_tag,
&ett_ipdc_line_status,
};
static ei_register_info ei[] = {
{ &ei_ipdc_ipv4, { "ipdc.ipv4.invalid_length", PI_PROTOCOL, PI_WARN, "Invalid IP address length", EXPFILL }},
};
module_t *ipdc_module;
expert_module_t* expert_ipdc;
proto_ipdc = proto_register_protocol("IP Device Control (SS7 over IP)",
"IPDC", "ipdc");
proto_register_field_array(proto_ipdc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_ipdc = expert_register_protocol(proto_ipdc);
expert_register_field_array(expert_ipdc, ei, array_length(ei));
ipdc_module = prefs_register_protocol(proto_ipdc, proto_reg_handoff_ipdc);
prefs_register_bool_preference(ipdc_module, "desegment_ipdc_messages",
"Reassemble IPDC messages spanning multiple TCP segments",
"Whether the IPDC dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&ipdc_desegment);
prefs_register_uint_preference(ipdc_module, "tcp.port",
"IPDC monitoring port",
"Set the IPDC monitoring port", 10,
&ipdc_port_pref);
}
void
proto_reg_handoff_ipdc(void)
{
static guint last_ipdc_port_pref = 0;
static dissector_handle_t ipdc_tcp_handle = NULL;
if (ipdc_tcp_handle) {
dissector_delete_uint("tcp.port", last_ipdc_port_pref,
ipdc_tcp_handle);
} else {
ipdc_tcp_handle =
new_create_dissector_handle(dissect_ipdc_tcp, proto_ipdc);
q931_handle = find_dissector("q931");
}
last_ipdc_port_pref = ipdc_port_pref;
dissector_add_uint("tcp.port", ipdc_port_pref, ipdc_tcp_handle);
}
