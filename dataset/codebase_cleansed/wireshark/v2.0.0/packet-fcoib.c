static gboolean
manual_addr_match(packet_info *pinfo) {
if (gPREF_MAN_EN) {
if ( (ADDRESSES_EQUAL(&pinfo->src, &manual_addr[0]) &&
ADDRESSES_EQUAL(&pinfo->dst, &manual_addr[1]) &&
(pinfo->srcport == 0xffffffff || pinfo->srcport == gPREF_QP[0]) &&
(pinfo->destport == 0xffffffff || pinfo->destport == gPREF_QP[1])) ||
(ADDRESSES_EQUAL(&pinfo->src, &manual_addr[1]) &&
ADDRESSES_EQUAL(&pinfo->dst, &manual_addr[0]) &&
(pinfo->srcport == 0xffffffff || pinfo->srcport == gPREF_QP[1]) &&
(pinfo->destport == 0xffffffff || pinfo->destport == gPREF_QP[0])) )
return TRUE;
}
return FALSE;
}
static gboolean
dissect_fcoib(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint crc_offset;
gint eof_offset;
gint sof_offset;
gint frame_len;
guint version;
const char *ver;
gint bytes_remaining;
guint8 sof = 0;
guint8 eof = 0;
guint8 sig = 0;
const char *eof_str;
const char *sof_str;
const char *crc_msg;
const char *len_msg;
proto_item *ti;
proto_item *item;
proto_tree *fcoib_tree;
proto_tree *crc_tree;
tvbuff_t *next_tvb;
gboolean crc_exists;
guint32 crc_computed = 0;
guint32 crc = 0;
gboolean packet_match_manual;
fc_data_t fc_data;
tree = proto_tree_get_root(tree);
frame_len = tvb_reported_length_remaining(tvb, 0) -
FCOIB_HEADER_LEN - FCOIB_TRAILER_LEN;
crc_offset = FCOIB_HEADER_LEN + frame_len;
eof_offset = crc_offset + 4;
sof_offset = FCOIB_HEADER_LEN - 1;
if (frame_len <= 0)
return FALSE;
packet_match_manual = manual_addr_match(pinfo);
if (!packet_match_manual && !gPREF_HEUR_EN)
return FALSE;
if (tvb_bytes_exist(tvb, 0, 1))
sig = tvb_get_guint8(tvb, 0) >> 6;
if (tvb_bytes_exist(tvb, eof_offset, 1))
eof = tvb_get_guint8(tvb, eof_offset);
if (tvb_bytes_exist(tvb, sof_offset, 1))
sof = tvb_get_guint8(tvb, sof_offset);
if (!packet_match_manual) {
if (sig != 1)
return FALSE;
if (!tvb_bytes_exist(tvb, eof_offset + 1, 3) || tvb_get_ntoh24(tvb, eof_offset + 1) != 0)
return FALSE;
if (!try_val_to_str(sof, fcoib_sof_vals))
return FALSE;
if (!try_val_to_str(eof, fcoib_eof_vals))
return FALSE;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "FCoIB");
bytes_remaining = tvb_captured_length_remaining(tvb, FCOIB_HEADER_LEN);
if (bytes_remaining > frame_len)
bytes_remaining = frame_len;
next_tvb = tvb_new_subset(tvb, FCOIB_HEADER_LEN, bytes_remaining, frame_len);
ver = "";
version = tvb_get_guint8(tvb, 0 + FCOIB_VER_OFFSET) >> 4;
if (version != 0)
ver = wmem_strdup_printf(wmem_packet_scope(), ver, "ver %d ", version);
eof_str = "none";
if (tvb_bytes_exist(tvb, eof_offset, 1)) {
eof_str = val_to_str(eof, fcoib_eof_vals, "0x%x");
}
sof_str = "none";
if (tvb_bytes_exist(tvb, sof_offset, 1)) {
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
if (crc == crc_computed) {
item = proto_tree_add_uint_format_value(fcoib_tree, hf_fcoib_crc, tvb,
crc_offset, 4, crc,
"%8.8x [valid]", crc);
} else {
item = proto_tree_add_uint_format_value(fcoib_tree, hf_fcoib_crc, tvb,
crc_offset, 4, crc,
"%8.8x [error: should be %8.8x]",
crc, crc_computed);
expert_add_info_format(pinfo, item, &ei_fcoib_crc,
"Bad FC CRC %8.8x %8.x",
crc, crc_computed);
}
proto_tree_set_appendix(fcoib_tree, tvb, crc_offset,
tvb_captured_length_remaining (tvb, crc_offset));
} else {
item = proto_tree_add_uint_format_value(fcoib_tree, hf_fcoib_crc, tvb, crc_offset, 0,
0, "CRC: [missing]");
}
crc_tree = proto_item_add_subtree(item, ett_fcoib_crc);
ti = proto_tree_add_boolean(crc_tree, hf_fcoib_crc_bad, tvb,
crc_offset, 4,
crc_exists && crc != crc_computed);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_boolean(crc_tree, hf_fcoib_crc_good, tvb,
crc_offset, 4,
crc_exists && crc == crc_computed);
PROTO_ITEM_SET_GENERATED(ti);
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
} else if (eof != FCOIB_EOFt) {
fc_data.sof_eof |= FC_DATA_EOF_INVALID;
}
fc_data.ethertype = 0;
if (fc_handle) {
call_dissector_with_data(fc_handle, next_tvb, pinfo, tree, &fc_data);
} else if (data_handle) {
call_dissector(data_handle, next_tvb, pinfo, tree);
}
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
{ &hf_fcoib_crc_good,
{"CRC good", "fcoib.crc_good", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True: CRC matches packet content; False: doesn't match or not checked.", HFILL }},
{ &hf_fcoib_crc_bad,
{"CRC bad", "fcoib.crc_bad", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True: CRC doesn't match packet content; False: matches or not checked.", HFILL }}
};
static gint *ett[] = {
&ett_fcoib,
&ett_fcoib_crc
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
prefs_register_bool_preference(fcoib_module, "heur_en", "Enable heuristic identification of FCoIB packets",
"When this option is enabled Wireshark will attempt to identify FCoIB packets automatically "
"based on some common features (may generate false positives)",
&gPREF_HEUR_EN);
prefs_register_bool_preference(fcoib_module, "manual_en", "Enable manual settings",
"Enables dissecting packets between the manually configured source/destination as FCoIB traffic",
&gPREF_MAN_EN);
prefs_register_static_text_preference(fcoib_module, "addr_a", "Address A",
"Side A of the manually-configured connection");
prefs_register_enum_preference(fcoib_module, "addr_a_type", "Address Type",
"Type of address specified", &gPREF_TYPE[0], pref_address_types, FALSE);
prefs_register_string_preference(fcoib_module, "addr_a_id", "ID",
"LID/GID of address A", &gPREF_ID[0]);
prefs_register_uint_preference(fcoib_module, "addr_a_qp", "QP Number",
"QP Number for address A", 10, &gPREF_QP[0]);
prefs_register_static_text_preference(fcoib_module, "addr_b", "Address B",
"Side B of the manually-configured connection");
prefs_register_enum_preference(fcoib_module, "addr_b_type", "Address Type",
"Type of address specified", &gPREF_TYPE[1], pref_address_types, FALSE);
prefs_register_string_preference(fcoib_module, "addr_b_id", "ID",
"LID/GID of address B", &gPREF_ID[1]);
prefs_register_uint_preference(fcoib_module, "addr_b_qp", "QP Number",
"QP Number for address B", 10, &gPREF_QP[1]);
}
void
proto_reg_handoff_fcoib(void)
{
static gboolean initialized = FALSE;
if (!initialized) {
heur_dissector_add("infiniband.payload", dissect_fcoib, "Fibre Channel over Infiniband", "fc_infiniband", proto_fcoib, HEURISTIC_ENABLE);
data_handle = find_dissector("data");
fc_handle = find_dissector("fc");
initialized = TRUE;
}
if (gPREF_MAN_EN) {
gboolean error_occured = FALSE;
char *not_parsed;
int i;
for (i = 0; i < 2; i++) {
if (gPREF_ID[i][0] == '\0') {
error_occured = TRUE;
} else if (gPREF_TYPE[i] == 0) {
errno = 0;
*((guint16*)manual_addr_data[i]) = (guint16)strtoul(gPREF_ID[i], &not_parsed, 0);
if (errno || *not_parsed != '\0') {
error_occured = TRUE;
} else {
SET_ADDRESS(&manual_addr[i], AT_IB, sizeof(guint16), manual_addr_data[i]);
}
} else {
if (!str_to_ip6( gPREF_ID[i], manual_addr_data[i])) {
error_occured = TRUE;
} else {
SET_ADDRESS(&manual_addr[i], AT_IB, GID_SIZE, manual_addr_data[i]);
}
}
if (error_occured) {
gPREF_MAN_EN = FALSE;
break;
}
}
}
}
