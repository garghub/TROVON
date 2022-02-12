static int
dissect_fcoib(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint crc_offset;
gint eof_offset;
gint sof_offset;
gint frame_len;
guint version;
const char *ver;
guint8 sof = 0;
guint8 eof = 0;
guint8 sig = 0;
const char *eof_str;
const char *sof_str;
const char *crc_msg;
const char *len_msg;
proto_item *ti;
proto_tree *fcoib_tree;
tvbuff_t *next_tvb;
gboolean crc_exists;
guint32 crc_computed = 0;
guint32 crc = 0;
fc_data_t fc_data;
frame_len = tvb_reported_length_remaining(tvb, 0) -
FCOIB_HEADER_LEN - FCOIB_TRAILER_LEN;
crc_offset = FCOIB_HEADER_LEN + frame_len;
eof_offset = crc_offset + 4;
sof_offset = FCOIB_HEADER_LEN - 1;
if (frame_len <= 0)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "FCoIB");
next_tvb = tvb_new_subset_length(tvb, FCOIB_HEADER_LEN, frame_len);
ver = "";
version = tvb_get_guint8(tvb, 0 + FCOIB_VER_OFFSET) >> 4;
if (version != 0)
ver = wmem_strdup_printf(wmem_packet_scope(), ver, "ver %d ", version);
if (tvb_bytes_exist(tvb, 0, 1))
sig = tvb_get_guint8(tvb, 0) >> 6;
eof_str = "none";
if (tvb_bytes_exist(tvb, eof_offset, 1)) {
eof = tvb_get_guint8(tvb, eof_offset);
eof_str = val_to_str(eof, fcoib_eof_vals, "0x%x");
}
sof_str = "none";
if (tvb_bytes_exist(tvb, sof_offset, 1)) {
sof = tvb_get_guint8(tvb, sof_offset);
sof_str = val_to_str(sof, fcoib_sof_vals, "0x%x");
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
ti = proto_tree_add_protocol_format(tree, proto_fcoib, tvb, 0,
FCOIB_HEADER_LEN,
"FCoIB %s(%s/%s) %d bytes%s%s", ver,
sof_str, eof_str,
frame_len, crc_msg,
len_msg);
fcoib_tree = proto_item_add_subtree(ti, ett_fcoib);
proto_tree_add_uint(fcoib_tree, hf_fcoib_sig, tvb, 0, 1, sig);
proto_tree_add_uint(fcoib_tree, hf_fcoib_ver, tvb, FCOIB_VER_OFFSET, 1, version);
proto_tree_add_uint(fcoib_tree, hf_fcoib_sof, tvb, sof_offset, 1, sof);
if (crc_exists) {
proto_tree_add_checksum(fcoib_tree, tvb, crc_offset, hf_fcoib_crc, hf_fcoib_crc_status, &ei_fcoib_crc, pinfo, crc_computed, ENC_BIG_ENDIAN, PROTO_CHECKSUM_VERIFY);
proto_tree_set_appendix(fcoib_tree, tvb, crc_offset,
tvb_captured_length_remaining (tvb, crc_offset));
} else {
proto_tree_add_checksum(fcoib_tree, tvb, crc_offset, hf_fcoib_crc, hf_fcoib_crc_status, &ei_fcoib_crc, pinfo, 0, ENC_BIG_ENDIAN, PROTO_CHECKSUM_NOT_PRESENT);
}
if (tvb_bytes_exist(tvb, eof_offset, 1)) {
proto_tree_add_item(fcoib_tree, hf_fcoib_eof, tvb, eof_offset, 1, ENC_BIG_ENDIAN);
}
fc_data.sof_eof = 0;
if (sof == FCOIB_SOFi3 || sof == FCOIB_SOFi2 || sof == FCOIB_SOFi4) {
fc_data.sof_eof = FC_DATA_SOF_FIRST_FRAME;
} else if (sof == FCOIB_SOFf) {
fc_data.sof_eof = FC_DATA_SOF_SOFF;
}
if (eof != FCOIB_EOFn) {
fc_data.sof_eof |= FC_DATA_EOF_LAST_FRAME;
if (eof != FCOIB_EOFt) {
fc_data.sof_eof |= FC_DATA_EOF_INVALID;
}
}
fc_data.ethertype = 0;
if (fc_handle) {
call_dissector_with_data(fc_handle, next_tvb, pinfo, tree, &fc_data);
} else {
call_data_dissector(next_tvb, pinfo, tree);
}
return tvb_captured_length(tvb);
}
static gboolean
dissect_fcoib_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint crc_offset;
gint eof_offset;
gint sof_offset;
gint frame_len;
guint8 sof = 0;
guint8 eof = 0;
guint8 sig = 0;
frame_len = tvb_reported_length_remaining(tvb, 0) -
FCOIB_HEADER_LEN - FCOIB_TRAILER_LEN;
crc_offset = FCOIB_HEADER_LEN + frame_len;
eof_offset = crc_offset + 4;
sof_offset = FCOIB_HEADER_LEN - 1;
if (frame_len <= 0)
return FALSE;
if (tvb_bytes_exist(tvb, 0, 1))
sig = tvb_get_guint8(tvb, 0) >> 6;
if (tvb_bytes_exist(tvb, eof_offset, 1))
eof = tvb_get_guint8(tvb, eof_offset);
if (tvb_bytes_exist(tvb, sof_offset, 1))
sof = tvb_get_guint8(tvb, sof_offset);
if (sig != 1)
return FALSE;
if (!tvb_bytes_exist(tvb, eof_offset + 1, 3) || tvb_get_ntoh24(tvb, eof_offset + 1) != 0)
return FALSE;
if (!try_val_to_str(sof, fcoib_sof_vals))
return FALSE;
if (!try_val_to_str(eof, fcoib_eof_vals))
return FALSE;
dissect_fcoib(tvb, pinfo, tree, data);
return TRUE;
}
void
proto_register_fcoib(void)
{
module_t *fcoib_module;
static hf_register_info hf[] = {
{ &hf_fcoib_sof,
{"SOF", "fcoib.sof", FT_UINT8, BASE_HEX, VALS(fcoib_sof_vals), 0,
NULL, HFILL}},
{ &hf_fcoib_eof,
{"EOF", "fcoib.eof", FT_UINT8, BASE_HEX, VALS(fcoib_eof_vals), 0,
NULL, HFILL}},
{ &hf_fcoib_sig,
{"Signature", "fcoib.sig", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL}},
{ &hf_fcoib_ver,
{"Version", "fcoib.ver", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL}},
{ &hf_fcoib_crc,
{"CRC", "fcoib.crc", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL}},
{ &hf_fcoib_crc_status,
{"CRC Status", "fcoib.crc.status", FT_UINT8, BASE_NONE, VALS(proto_checksum_vals), 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_fcoib,
};
static ei_register_info ei[] = {
{ &ei_fcoib_crc, { "fcoib.crc.bad", PI_CHECKSUM, PI_ERROR, "Bad checksum", EXPFILL }},
};
expert_module_t* expert_fcoib;
proto_fcoib = proto_register_protocol("Fibre Channel over Infiniband",
"FCoIB", "fcoib");
proto_register_field_array(proto_fcoib, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_fcoib = expert_register_protocol(proto_fcoib);
expert_register_field_array(expert_fcoib, ei, array_length(ei));
fcoib_module = prefs_register_protocol(proto_fcoib, proto_reg_handoff_fcoib);
prefs_register_static_text_preference(fcoib_module, "use_decode_as",
"Heuristic matching preferences removed. Use Infiniband protocol preferences or Decode As.",
"Simple heuristics can still be enable (may generate false positives) through Infiniband protocol preferences."
"To force FCoIB dissection use Decode As");
prefs_register_obsolete_preference(fcoib_module, "heur_en");
prefs_register_obsolete_preference(fcoib_module, "manual_en");
prefs_register_obsolete_preference(fcoib_module, "addr_a");
prefs_register_obsolete_preference(fcoib_module, "addr_a_type");
prefs_register_obsolete_preference(fcoib_module, "addr_a_id");
prefs_register_obsolete_preference(fcoib_module, "addr_a_qp");
prefs_register_obsolete_preference(fcoib_module, "addr_b");
prefs_register_obsolete_preference(fcoib_module, "addr_b_type");
prefs_register_obsolete_preference(fcoib_module, "addr_b_id");
prefs_register_obsolete_preference(fcoib_module, "addr_b_qp");
}
void
proto_reg_handoff_fcoib(void)
{
heur_dissector_add("infiniband.payload", dissect_fcoib_heur, "Fibre Channel over Infiniband", "fc_infiniband", proto_fcoib, HEURISTIC_ENABLE);
dissector_add_for_decode_as("infiniband", create_dissector_handle( dissect_fcoib, proto_fcoib ) );
fc_handle = find_dissector_add_dependency("fc", proto_fcoib);
}
