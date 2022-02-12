static void
dissect_fcoe(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gint crc_offset;
gint eof_offset;
gint frame_len = 0;
gint header_len = FCOE_HEADER_LEN;
guint version;
const char *ver;
guint16 len_sof;
gint bytes_remaining;
guint8 sof = 0;
guint8 eof = 0;
const char *eof_str;
const char *crc_msg;
const char *len_msg;
proto_item *ti;
proto_item *item;
proto_tree *fcoe_tree;
proto_tree *crc_tree;
tvbuff_t *next_tvb;
gboolean crc_exists;
guint32 crc_computed = 0;
guint32 crc = 0;
fc_data_t fc_data;
if (tvb_get_guint8(tvb, 1)) {
header_len = 2;
len_sof = tvb_get_ntohs(tvb, 0);
frame_len = ((len_sof & 0x3ff0) >> 2) - 4;
sof = len_sof & 0xf;
sof |= (sof < 8) ? 0x30 : 0x20;
version = len_sof >> 14;
ver = "pre-T11 ";
if (version != 0)
ver = wmem_strdup_printf(wmem_packet_scope(), ver, "pre-T11 ver %d ", version);
} else {
frame_len = tvb_reported_length_remaining(tvb, 0) -
FCOE_HEADER_LEN - FCOE_TRAILER_LEN;
sof = tvb_get_guint8(tvb, FCOE_HEADER_LEN - 1);
ver = "";
version = tvb_get_guint8(tvb, 0) >> 4;
if (version != 0)
ver = wmem_strdup_printf(wmem_packet_scope(), ver, "ver %d ", version);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "FCoE");
crc_offset = header_len + frame_len;
eof_offset = crc_offset + 4;
bytes_remaining = tvb_captured_length_remaining(tvb, header_len);
if (bytes_remaining > frame_len)
bytes_remaining = frame_len;
next_tvb = tvb_new_subset(tvb, header_len, bytes_remaining, frame_len);
eof_str = "none";
if (tvb_bytes_exist(tvb, eof_offset, 1)) {
eof = tvb_get_guint8(tvb, eof_offset);
eof_str = val_to_str(eof, fcoe_eof_vals, "0x%x");
}
crc_msg = "";
crc_exists = tvb_bytes_exist(tvb, crc_offset, 4);
if (crc_exists) {
crc = tvb_get_ntohl(tvb, crc_offset);
crc_computed = crc32_802_tvb(next_tvb, frame_len);
if (crc != crc_computed) {
crc_msg = " [bad FC CRC]";
}
}
len_msg = "";
if ((frame_len % 4) != 0 || frame_len < 24) {
len_msg = " [invalid length]";
}
ti = proto_tree_add_protocol_format(tree, proto_fcoe, tvb, 0,
header_len,
"FCoE %s(%s/%s) %d bytes%s%s", ver,
val_to_str(sof, fcoe_sof_vals,
"0x%x"),
eof_str, frame_len, crc_msg,
len_msg);
fcoe_tree = proto_item_add_subtree(ti, ett_fcoe);
proto_tree_add_uint(fcoe_tree, hf_fcoe_ver, tvb, 0, 1, version);
if (tvb_get_guint8(tvb, 1)) {
proto_tree_add_uint(fcoe_tree, hf_fcoe_len, tvb, 0, 2, frame_len);
}
proto_tree_add_uint(fcoe_tree, hf_fcoe_sof, tvb,
header_len - 1, 1, sof);
if (crc_exists) {
if (crc == crc_computed) {
item = proto_tree_add_uint_format_value(fcoe_tree, hf_fcoe_crc, tvb,
crc_offset, 4, crc,
"%8.8x [valid]", crc);
} else {
item = proto_tree_add_uint_format_value(fcoe_tree, hf_fcoe_crc, tvb,
crc_offset, 4, crc,
"%8.8x [error: should be %8.8x]",
crc, crc_computed);
expert_add_info_format(pinfo, item, &ei_fcoe_crc,
"Bad FC CRC %8.8x %8.x",
crc, crc_computed);
}
proto_tree_set_appendix(fcoe_tree, tvb, crc_offset,
tvb_captured_length_remaining (tvb, crc_offset));
} else {
item = proto_tree_add_uint_format_value(fcoe_tree, hf_fcoe_crc, tvb, crc_offset, 0,
0, "CRC: [missing]");
}
crc_tree = proto_item_add_subtree(item, ett_fcoe_crc);
ti = proto_tree_add_boolean(crc_tree, hf_fcoe_crc_bad, tvb,
crc_offset, 4,
crc_exists && crc != crc_computed);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_boolean(crc_tree, hf_fcoe_crc_good, tvb,
crc_offset, 4,
crc_exists && crc == crc_computed);
PROTO_ITEM_SET_GENERATED(ti);
if (tvb_bytes_exist(tvb, eof_offset, 1)) {
proto_tree_add_item(fcoe_tree, hf_fcoe_eof, tvb, eof_offset, 1, ENC_BIG_ENDIAN);
}
fc_data.sof_eof = 0;
if (sof == FCOE_SOFi3 || sof == FCOE_SOFi2 || sof == FCOE_SOFi4) {
fc_data.sof_eof = FC_DATA_SOF_FIRST_FRAME;
} else if (sof == FCOE_SOFf) {
fc_data.sof_eof = FC_DATA_SOF_SOFF;
}
if (eof != FCOE_EOFn) {
fc_data.sof_eof |= FC_DATA_EOF_LAST_FRAME;
} else if (eof != FCOE_EOFt) {
fc_data.sof_eof |= FC_DATA_EOF_INVALID;
}
fc_data.ethertype = 0;
if (fc_handle) {
call_dissector_with_data(fc_handle, next_tvb, pinfo, tree, &fc_data);
} else if (data_handle) {
call_dissector(data_handle, next_tvb, pinfo, tree);
}
}
void
proto_register_fcoe(void)
{
module_t *fcoe_module;
static hf_register_info hf[] = {
{ &hf_fcoe_sof,
{"SOF", "fcoe.sof", FT_UINT8, BASE_HEX, VALS(fcoe_sof_vals), 0,
NULL, HFILL}},
{ &hf_fcoe_eof,
{"EOF", "fcoe.eof", FT_UINT8, BASE_HEX, VALS(fcoe_eof_vals), 0,
NULL, HFILL}},
{ &hf_fcoe_ver,
{"Version", "fcoe.ver", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL}},
{ &hf_fcoe_len,
{"Frame length", "fcoe.len", FT_UINT32,
BASE_DEC, NULL, 0, NULL, HFILL}},
{ &hf_fcoe_crc,
{"CRC", "fcoe.crc", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL}},
{ &hf_fcoe_crc_good,
{"CRC good", "fcoe.crc_good", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True: CRC matches packet content; False: doesn't match or not checked.", HFILL }},
{ &hf_fcoe_crc_bad,
{"CRC bad", "fcoe.crc_bad", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True: CRC doesn't match packet content; False: matches or not checked.", HFILL }}
};
static gint *ett[] = {
&ett_fcoe,
&ett_fcoe_crc
};
static ei_register_info ei[] = {
{ &ei_fcoe_crc, { "fcoe.crc.bad", PI_CHECKSUM, PI_ERROR, "Bad checksum", EXPFILL }},
};
expert_module_t* expert_fcoe;
proto_fcoe = proto_register_protocol("Fibre Channel over Ethernet",
"FCoE", "fcoe");
proto_register_field_array(proto_fcoe, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_fcoe = expert_register_protocol(proto_fcoe);
expert_register_field_array(expert_fcoe, ei, array_length(ei));
fcoe_module = prefs_register_protocol(proto_fcoe, NULL);
prefs_register_obsolete_preference(fcoe_module, "ethertype");
}
void
proto_reg_handoff_fcoe(void)
{
dissector_handle_t fcoe_handle;
fcoe_handle = create_dissector_handle(dissect_fcoe, proto_fcoe);
dissector_add_uint("ethertype", ETHERTYPE_FCOE, fcoe_handle);
data_handle = find_dissector("data");
fc_handle = find_dissector("fc");
}
