static void
dissect_udld(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *udld_tree = NULL;
int offset = 0;
guint16 type;
guint16 length;
proto_item *tlvi;
proto_tree *tlv_tree;
int real_length;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "UDLD");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
proto_item *flags_ti;
proto_tree *flags_tree;
ti = proto_tree_add_item(tree, proto_udld, tvb, offset, -1, ENC_NA);
udld_tree = proto_item_add_subtree(ti, ett_udld);
proto_tree_add_item(udld_tree, hf_udld_version, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(udld_tree, hf_udld_opcode, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
flags_ti = proto_tree_add_item(udld_tree, hf_udld_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
flags_tree = proto_item_add_subtree(flags_ti, ett_udld_flags);
proto_tree_add_item(flags_tree, hf_udld_flags_rt, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_udld_flags_rsy, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(udld_tree, hf_udld_checksum, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
} else {
offset += 4;
}
while (tvb_reported_length_remaining(tvb, offset) != 0) {
type = tvb_get_ntohs(tvb, offset + TLV_TYPE);
length = tvb_get_ntohs(tvb, offset + TLV_LENGTH);
if (length < 4) {
if (tree) {
tlvi = proto_tree_add_text(udld_tree, tvb, offset, 4,
"TLV with invalid length %u (< 4)",
length);
tlv_tree = proto_item_add_subtree(tlvi, ett_udld_tlv);
proto_tree_add_uint(tlv_tree, hf_udld_tlvtype, tvb,
offset + TLV_TYPE, 2, type);
proto_tree_add_uint(tlv_tree, hf_udld_tlvlength, tvb,
offset + TLV_LENGTH, 2, length);
}
offset += 4;
break;
}
switch (type) {
case TYPE_DEVICE_ID:
col_append_fstr(pinfo->cinfo, COL_INFO,
"Device ID: %s ",
tvb_format_stringzpad(tvb, offset + 4,
length - 4));
if (tree) {
tlvi = proto_tree_add_text(udld_tree, tvb, offset,
length, "Device ID: %s",
tvb_format_stringzpad(tvb, offset + 4, length - 4));
tlv_tree = proto_item_add_subtree(tlvi, ett_udld_tlv);
proto_tree_add_uint(tlv_tree, hf_udld_tlvtype, tvb,
offset + TLV_TYPE, 2, type);
proto_tree_add_uint(tlv_tree, hf_udld_tlvlength, tvb,
offset + TLV_LENGTH, 2, length);
proto_tree_add_text(tlv_tree, tvb, offset + 4,
length - 4, "Device ID: %s",
tvb_format_stringzpad(tvb, offset + 4, length - 4));
}
offset += length;
break;
case TYPE_PORT_ID:
real_length = length;
if (tvb_get_guint8(tvb, offset + real_length) != 0x00) {
real_length = length + 3;
}
col_append_fstr(pinfo->cinfo, COL_INFO,
"Port ID: %s ",
tvb_format_stringzpad(tvb, offset + 4, length - 4));
if (tree) {
tlvi = proto_tree_add_text(udld_tree, tvb, offset,
real_length, "Port ID: %s",
tvb_format_text(tvb, offset + 4, real_length - 4));
tlv_tree = proto_item_add_subtree(tlvi, ett_udld_tlv);
proto_tree_add_uint(tlv_tree, hf_udld_tlvtype, tvb,
offset + TLV_TYPE, 2, type);
proto_tree_add_uint(tlv_tree, hf_udld_tlvlength, tvb,
offset + TLV_LENGTH, 2, length);
proto_tree_add_text(tlv_tree, tvb, offset + 4,
real_length - 4,
"Sent through Interface: %s",
tvb_format_text(tvb, offset + 4, real_length - 4));
}
offset += real_length;
break;
case TYPE_ECHO:
case TYPE_MESSAGE_INTERVAL:
case TYPE_TIMEOUT_INTERVAL:
case TYPE_DEVICE_NAME:
case TYPE_SEQUENCE_NUMBER:
default:
tlvi = proto_tree_add_text(udld_tree, tvb, offset,
length, "Type: %s, length: %u",
val_to_str(type, type_vals, "Unknown (0x%04x)"),
length);
tlv_tree = proto_item_add_subtree(tlvi, ett_udld_tlv);
proto_tree_add_uint(tlv_tree, hf_udld_tlvtype, tvb,
offset + TLV_TYPE, 2, type);
proto_tree_add_uint(tlv_tree, hf_udld_tlvlength, tvb,
offset + TLV_LENGTH, 2, length);
if (length > 4) {
proto_tree_add_text(tlv_tree, tvb, offset + 4,
length - 4, "Data");
} else {
return;
}
offset += length;
}
}
call_dissector(data_handle, tvb_new_subset_remaining(tvb, offset), pinfo, udld_tree);
}
void
proto_register_udld(void)
{
static hf_register_info hf[] = {
{ &hf_udld_version,
{ "Version", "udld.version", FT_UINT8, BASE_DEC, NULL, 0xE0,
NULL, HFILL }},
{ &hf_udld_opcode,
{ "Opcode", "udld.opcode", FT_UINT8, BASE_DEC, VALS(opcode_vals), 0x1F,
NULL, HFILL }},
{ &hf_udld_flags,
{ "Flags", "udld.flags", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_udld_flags_rt,
{ "Recommended timeout", "udld.flags.rt", FT_UINT8, BASE_HEX, NULL, 0x80,
NULL, HFILL }},
{ &hf_udld_flags_rsy,
{ "ReSynch", "udld.flags.rsy", FT_UINT8, BASE_HEX, NULL, 0x40,
NULL, HFILL }},
{ &hf_udld_checksum,
{ "Checksum", "udld.checksum", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_udld_tlvtype,
{ "Type", "udld.tlv.type", FT_UINT16, BASE_HEX, VALS(type_vals), 0x0,
NULL, HFILL }},
{ &hf_udld_tlvlength,
{ "Length", "udld.tlv.len", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }}
};
static gint *ett[] = {
&ett_udld,
&ett_udld_flags,
&ett_udld_tlv
};
proto_udld = proto_register_protocol("Unidirectional Link Detection",
"UDLD", "udld");
proto_register_field_array(proto_udld, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_udld(void)
{
dissector_handle_t udld_handle;
data_handle = find_dissector("data");
udld_handle = create_dissector_handle(dissect_udld, proto_udld);
dissector_add_uint("llc.cisco_pid", 0x0111, udld_handle);
dissector_add_uint("chdlc.protocol", 0x0111, udld_handle);
}
