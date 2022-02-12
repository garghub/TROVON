static gboolean
utp_is_v1(tvbuff_t *tvb) {
guint8 v1_ver_type;
guint8 v1_ext;
guint len;
v1_ver_type = tvb_get_guint8(tvb, 0);
v1_ext = tvb_get_guint8(tvb, 1);
if (((v1_ver_type & 0x0f) != 1) ||
((v1_ver_type>>4) >= ST_NUM_STATES) ||
(v1_ext >= EXT_NUM_EXT)) {
return FALSE;
}
len = tvb_reported_length(tvb);
if (len < V1_FIXED_HDR_SIZE) {
return TRUE;
}
len -= V1_FIXED_HDR_SIZE;
if ((len == 0) ||
(len == 6) ||
(len == 10) ||
(len == 14) ||
((len > 14) && (len%2 == 0))) {
return TRUE;
}
return FALSE;
}
static int
dissect_utp_header_v0(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, guint8 *extension_type)
{
proto_tree_add_item(tree, hf_bt_utp_connection_id_v0, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_bt_utp_timestamp_sec, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_bt_utp_timestamp_us, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_bt_utp_timestamp_diff_us, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_bt_utp_wnd_size_v0, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bt_utp_next_extension_type, tvb, offset, 1, ENC_BIG_ENDIAN);
*extension_type = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(tree, hf_bt_utp_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " Type: %s", val_to_str(tvb_get_guint8(tvb, offset), bt_utp_type_vals, "Unknown %d"));
offset += 1;
proto_tree_add_item(tree, hf_bt_utp_seq_nr, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bt_utp_ack_nr, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_utp_header_v1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, guint8 *extension_type)
{
proto_tree_add_item(tree, hf_bt_utp_ver, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bt_utp_type, tvb, offset, 1, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " Type: %s", val_to_str((tvb_get_guint8(tvb, offset) >> 4), bt_utp_type_vals, "Unknown %d"));
offset += 1;
proto_tree_add_item(tree, hf_bt_utp_next_extension_type, tvb, offset, 1, ENC_BIG_ENDIAN);
*extension_type = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(tree, hf_bt_utp_connection_id_v1, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bt_utp_timestamp_us, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_bt_utp_timestamp_diff_us, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_bt_utp_wnd_size_v1, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_bt_utp_seq_nr, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bt_utp_ack_nr, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_utp_extension(tvbuff_t *tvb, packet_info _U_*pinfo, proto_tree *tree, int offset, guint8 *extension_type)
{
proto_item *ti;
proto_tree *ext_tree;
guint8 extension_length;
while(offset < (int)tvb_reported_length(tvb))
{
switch(*extension_type){
case EXT_SELECTION_ACKS:
{
ti = proto_tree_add_item(tree, hf_bt_utp_extension, tvb, offset, -1, ENC_NA);
ext_tree = proto_item_add_subtree(ti, ett_bt_utp_extension);
proto_tree_add_item(ext_tree, hf_bt_utp_next_extension_type, tvb, offset, 1, ENC_BIG_ENDIAN);
*extension_type = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(ext_tree, hf_bt_utp_extension_len, tvb, offset, 1, ENC_BIG_ENDIAN);
extension_length = tvb_get_guint8(tvb, offset);
proto_item_append_text(ti, " Selection Acks, Len=%d", extension_length);
offset += 1;
proto_tree_add_item(ext_tree, hf_bt_utp_extension_bitmask, tvb, offset, extension_length, ENC_NA);
offset += extension_length;
proto_item_set_len(ti, 1 + 1 + extension_length);
break;
}
case EXT_EXTENSION_BITS:
{
ti = proto_tree_add_item(tree, hf_bt_utp_extension, tvb, offset, -1, ENC_NA);
ext_tree = proto_item_add_subtree(ti, ett_bt_utp_extension);
proto_tree_add_item(ext_tree, hf_bt_utp_next_extension_type, tvb, offset, 1, ENC_BIG_ENDIAN);
*extension_type = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(ext_tree, hf_bt_utp_extension_len, tvb, offset, 1, ENC_BIG_ENDIAN);
extension_length = tvb_get_guint8(tvb, offset);
proto_item_append_text(ti, " Extension Bits, Len=%d", extension_length);
offset += 1;
proto_tree_add_item(ext_tree, hf_bt_utp_extension_bitmask, tvb, offset, extension_length, ENC_NA);
offset += extension_length;
proto_item_set_len(ti, 1 + 1 + extension_length);
break;
}
default:
ti = proto_tree_add_item(tree, hf_bt_utp_extension, tvb, offset, -1, ENC_NA);
ext_tree = proto_item_add_subtree(ti, ett_bt_utp_extension);
proto_tree_add_item(ext_tree, hf_bt_utp_next_extension_type, tvb, offset, 1, ENC_BIG_ENDIAN);
*extension_type = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(ext_tree, hf_bt_utp_extension_len, tvb, offset, 1, ENC_BIG_ENDIAN);
extension_length = tvb_get_guint8(tvb, offset);
proto_item_append_text(ti, " Unknown, Len=%d", extension_length);
offset += 1;
proto_tree_add_item(ext_tree, hf_bt_utp_extension_unknown, tvb, offset, extension_length, ENC_NA);
offset += extension_length;
proto_item_set_len(ti, 1 + 1 + extension_length);
break;
}
}
return offset;
}
static int
dissect_bt_utp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
conversation_t *conversation;
if( tvb_get_guint8(tvb,0)=='d' )
{
proto_tree *sub_tree = NULL;
int decoded_length = 0;
guint8 extension_type;
conversation = find_or_create_conversation(pinfo);
conversation_set_dissector(conversation, bt_utp_handle);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "BT-uTP");
col_set_str( pinfo->cinfo, COL_INFO, "uTorrent Transport Protocol" );
if(tree)
{
proto_item *ti;
ti = proto_tree_add_item(tree, proto_bt_utp, tvb, 0, -1, ENC_NA);
sub_tree = proto_item_add_subtree(ti, ett_bt_utp);
}
if (!utp_is_v1(tvb)) {
decoded_length = dissect_utp_header_v0(tvb, pinfo, sub_tree, decoded_length, &extension_type);
} else {
decoded_length = dissect_utp_header_v1(tvb, pinfo, sub_tree, decoded_length, &extension_type);
}
decoded_length = dissect_utp_extension(tvb, pinfo, sub_tree, decoded_length, &extension_type);
return decoded_length;
}
return 0;
}
void
proto_register_bt_utp(void)
{
static hf_register_info hf[] = {
{ &hf_bt_utp_ver,
{ "Version", "bt-utp.ver",
FT_UINT8, BASE_DEC, NULL, 0x0F,
NULL, HFILL }
},
{ &hf_bt_utp_flags,
{ "Flags", "bt-utp.flags",
FT_UINT8, BASE_DEC, VALS(bt_utp_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_bt_utp_type,
{ "Type", "bt-utp.type",
FT_UINT8, BASE_DEC, VALS(bt_utp_type_vals), 0xF0,
NULL, HFILL }
},
{ &hf_bt_utp_extension,
{ "Extension", "bt-utp.extension",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bt_utp_next_extension_type,
{ "Next Extension Type", "bt-utp.next_extension_type",
FT_UINT8, BASE_DEC, VALS(bt_utp_extension_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_bt_utp_extension_len,
{ "Extension Length", "bt-utp.extension_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bt_utp_extension_bitmask,
{ "Extension Bitmask", "bt-utp.extension_bitmask",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bt_utp_extension_unknown,
{ "Extension Unknown", "bt-utp.extension_unknown",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bt_utp_connection_id_v0,
{ "Connection ID", "bt-utp.connection_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bt_utp_connection_id_v1,
{ "Connection ID", "bt-utp.connection_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bt_utp_timestamp_sec,
{ "Timestamp seconds", "bt-utp.timestamp_sec",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bt_utp_timestamp_us,
{ "Timestamp Microseconds", "bt-utp.timestamp_us",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bt_utp_timestamp_diff_us,
{ "Timestamp Difference Microseconds", "bt-utp.timestamp_diff_us",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bt_utp_wnd_size_v0,
{ "Windows Size", "bt-utp.wnd_size",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bt_utp_wnd_size_v1,
{ "Windows Size", "bt-utp.wnd_size",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bt_utp_seq_nr,
{ "Sequence NR", "bt-utp.seq_nr",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bt_utp_ack_nr,
{ "ACK NR", "bt-utp.ack_nr",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = { &ett_bt_utp, &ett_bt_utp_extension };
proto_bt_utp = proto_register_protocol (
"uTorrent Transport Protocol",
"BT-uTP",
"bt-utp"
);
proto_register_field_array(proto_bt_utp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_bt_utp(void)
{
heur_dissector_add("udp", dissect_bt_utp, proto_bt_utp);
bt_utp_handle = new_create_dissector_handle(dissect_bt_utp, proto_bt_utp);
dissector_add_handle("udp.port", bt_utp_handle);
}
