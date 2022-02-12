static guint
get_next_fcip_header_offset (tvbuff_t *tvb, packet_info *pinfo, gint offset)
{
gint bytes_remaining = tvb_length_remaining (tvb, offset);
gint frame_len;
guint16 flen, flen1;
fcip_eof_t eof, eofc;
NXT_BYTE: while (bytes_remaining) {
if (bytes_remaining < FCIP_ENCAP_HEADER_LEN) {
if(fcip_desegment && pinfo->can_desegment) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return -2;
}
}
if (tvb_memeql(tvb, offset, fcip_header_8_bytes, 8) != 0) {
offset++;
bytes_remaining--;
goto NXT_BYTE;
}
flen = (tvb_get_ntohs (tvb, offset+12)) & 0x03FF;
frame_len = (tvb_get_ntohs (tvb, offset+12) & 0x03FF)*4;
if ((flen < 15) || (flen > 545)) {
offset++;
bytes_remaining--;
goto NXT_BYTE;
}
flen1 = (tvb_get_ntohs (tvb, offset+14)) & 0x03FF;
if ((flen & 0x03FF) != ((~flen1)&0x03FF)) {
offset++;
bytes_remaining--;
goto NXT_BYTE;
}
if (tvb_bytes_exist (tvb, offset+(frame_len-1)*4, 4)) {
eof = (fcip_eof_t)tvb_get_guint8 (tvb, offset+(frame_len-1)*4);
eofc = (fcip_eof_t)tvb_get_guint8 (tvb, offset+(frame_len-1)*4+2);
if ((eof != FCIP_EOFn) && (eof != FCIP_EOFt) && (eof != FCIP_EOFrt)
&& (eof != FCIP_EOFdt) && (eof != FCIP_EOFni) &&
(eof != FCIP_EOFdti) && (eof != FCIP_EOFrti) &&
(eof != FCIP_EOFa)) {
offset++;
bytes_remaining--;
goto NXT_BYTE;
}
if ((eof != ~eofc) ||
(eof != tvb_get_guint8 (tvb, offset+(frame_len-1)*4+1)) ||
(eofc != tvb_get_guint8 (tvb, offset+(frame_len-1)*4+3))) {
offset++;
bytes_remaining--;
goto NXT_BYTE;
}
}
if ((tvb_get_guint8 (tvb, offset+9) != 0) ||
(tvb_get_guint8 (tvb, offset+11) != 0xFF)) {
offset++;
bytes_remaining--;
goto NXT_BYTE;
}
if (bytes_remaining >= (frame_len)) {
if (tvb_bytes_exist (tvb, offset+frame_len, 8)) {
if (tvb_memeql (tvb, offset+frame_len, fcip_header_8_bytes,
8) == 0) {
return (offset);
}
else {
offset++;
bytes_remaining--;
goto NXT_BYTE;
}
}
else {
return (offset);
}
}
else {
if(fcip_desegment && pinfo->can_desegment) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = frame_len - bytes_remaining;
return -2;
}
else {
return (offset);
}
}
}
return (-1);
}
static void
dissect_fcencap_header (tvbuff_t *tvb, proto_tree *tree, gint offset)
{
guint8 protocol = tvb_get_guint8 (tvb, offset);
if (tree) {
proto_tree_add_uint (tree, hf_fcip_protocol, tvb, offset, 1, protocol);
proto_tree_add_item (tree, hf_fcip_version, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_fcip_protocol_c, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_fcip_version_c, tvb, offset+3, 1, ENC_BIG_ENDIAN);
if (protocol == FCENCAP_PROTO_FCIP) {
proto_tree_add_item (tree, hf_fcip_encap_word1, tvb, offset+4,
4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_fcip_pflags_changed, tvb, offset+8,
1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_fcip_pflags_special, tvb, offset+8,
1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_fcip_pflags_c, tvb, offset+10, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_item (tree, hf_fcip_flags, tvb, offset+12, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_fcip_framelen, tvb, offset+12, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_fcip_flags_c, tvb, offset+14, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_fcip_framelen_c, tvb, offset+14, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_fcip_tsec, tvb, offset+16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_fcip_tusec, tvb, offset+20, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_fcip_encap_crc, tvb, offset+24, 4, ENC_BIG_ENDIAN);
}
}
static void
dissect_fcip_sf (tvbuff_t *tvb, proto_tree *tree, gint offset)
{
if (tree) {
proto_tree_add_string (tree, hf_fcip_src_wwn, tvb, offset, 8,
tvb_fcwwn_to_str (tvb, offset));
proto_tree_add_item (tree, hf_fcip_src_entity_id, tvb, offset+8, 8,
ENC_NA);
proto_tree_add_item (tree, hf_fcip_conn_nonce, tvb, offset+16, 8,
ENC_NA);
proto_tree_add_item (tree, hf_fcip_conn_flags, tvb, offset+24, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_fcip_conn_code, tvb, offset+26, 2, ENC_BIG_ENDIAN);
proto_tree_add_string (tree, hf_fcip_dst_wwn, tvb, offset+30, 8,
tvb_fcwwn_to_str (tvb, offset+30));
proto_tree_add_item (tree, hf_fcip_katov, tvb, offset+38, 4, ENC_BIG_ENDIAN);
}
}
static gboolean
dissect_fcip (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gboolean check_port)
{
gint offset = 0,
start = 0,
frame_len = 0;
gint bytes_remaining = tvb_length (tvb);
guint8 pflags, sof = 0, eof = 0;
proto_item *ti;
proto_tree *fcip_tree = NULL;
tvbuff_t *next_tvb;
fc_data_t fc_data;
if (bytes_remaining < FCIP_ENCAP_HEADER_LEN) {
return FALSE;
}
if (check_port &&
((pinfo->srcport != fcip_port) && (pinfo->destport != fcip_port))) {
return FALSE;
}
while (bytes_remaining > FCIP_ENCAP_HEADER_LEN) {
if ((offset = get_next_fcip_header_offset (tvb, pinfo, offset)) == -1) {
return FALSE;
}
else if (offset == -2) {
return (TRUE);
}
start = offset;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "FCIP");
frame_len = (tvb_get_ntohs (tvb, offset+12) & 0x03FF)*4;
if (bytes_remaining < frame_len) {
if(fcip_desegment && pinfo->can_desegment) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = frame_len - bytes_remaining;
return (TRUE);
}
}
pflags = tvb_get_guint8 (tvb, start+8);
if (tree) {
if (FCIP_IS_SF (pflags)) {
ti = proto_tree_add_protocol_format (tree, proto_fcip, tvb, 0,
FCIP_ENCAP_HEADER_LEN,
"FCIP");
}
else if (tvb_bytes_exist (tvb, offset, offset+frame_len-4)) {
sof = tvb_get_guint8 (tvb, offset+FCIP_ENCAP_HEADER_LEN);
eof = tvb_get_guint8 (tvb, offset+frame_len - 4);
ti = proto_tree_add_protocol_format (tree, proto_fcip, tvb, 0,
FCIP_ENCAP_HEADER_LEN,
"FCIP (%s/%s)",
val_to_str (sof, fcip_sof_vals,
"0x%x"),
val_to_str (eof, fcip_eof_vals,
"0x%x"));
}
else {
sof = tvb_get_guint8 (tvb, offset+FCIP_ENCAP_HEADER_LEN);
ti = proto_tree_add_protocol_format (tree, proto_fcip, tvb, 0,
FCIP_ENCAP_HEADER_LEN,
"FCIP (%s/%s)",
val_to_str (sof, fcip_sof_vals,
"0x%x"),
"NA");
}
fcip_tree = proto_item_add_subtree (ti, ett_fcip);
dissect_fcencap_header (tvb, fcip_tree, offset);
offset += FCIP_ENCAP_HEADER_LEN;
if (!FCIP_IS_SF (pflags)) {
proto_tree_add_item (fcip_tree, hf_fcip_sof, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (fcip_tree, hf_fcip_sof_c, tvb, offset+2, 1, ENC_BIG_ENDIAN);
offset += (frame_len-FCIP_ENCAP_HEADER_LEN-4);
if (tvb_bytes_exist (tvb, offset, 4)) {
proto_tree_add_item (fcip_tree, hf_fcip_eof, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (fcip_tree, hf_fcip_eof_c, tvb, offset+2, 1, ENC_BIG_ENDIAN);
}
}
}
if (!FCIP_IS_SF(pflags)) {
fc_data.sof_eof = 0;
if (sof) {
if ((sof == FCIP_SOFi3) || (sof == FCIP_SOFi2) || (sof == FCIP_SOFi4)) {
fc_data.sof_eof = FC_DATA_SOF_FIRST_FRAME;
}
else if (sof == FCIP_SOFf) {
fc_data.sof_eof = FC_DATA_SOF_SOFF;
}
if (eof != FCIP_EOFn) {
fc_data.sof_eof |= FC_DATA_EOF_LAST_FRAME;
}
else if (eof != FCIP_EOFt) {
fc_data.sof_eof |= FC_DATA_EOF_INVALID;
}
}
next_tvb = tvb_new_subset_remaining (tvb, FCIP_ENCAP_HEADER_LEN+4);
if (fc_handle) {
fc_data.ethertype = 0;
call_dissector_with_data(fc_handle, next_tvb, pinfo, tree, &fc_data);
}
else if (data_handle) {
call_dissector (data_handle, next_tvb, pinfo, tree);
}
}
else {
col_set_str(pinfo->cinfo, COL_INFO, "Special Frame");
if (FCIP_IS_CH (pflags)) {
col_append_str(pinfo->cinfo, COL_INFO, "(Changed)");
}
dissect_fcip_sf (tvb, fcip_tree, offset+4);
}
bytes_remaining -= frame_len;
}
return (TRUE);
}
static void
dissect_fcip_handle(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_fcip (tvb, pinfo, tree, FALSE);
}
static gboolean
dissect_fcip_heur (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissect_fcip (tvb, pinfo, tree, TRUE));
}
void
proto_register_fcip (void)
{
static hf_register_info hf[] = {
{ &hf_fcip_protocol,
{ "Protocol", "fcip.proto", FT_UINT8, BASE_DEC,
VALS(fcencap_proto_vals), 0, NULL, HFILL }},
{ &hf_fcip_protocol_c,
{"Protocol (1's Complement)", "fcip.protoc", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_fcip_version,
{"Version", "fcip.version", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_fcip_version_c,
{"Version (1's Complement)", "fcip.versionc", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_fcip_encap_word1,
{"FCIP Encapsulation Word1", "fcip.encap_word1", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_fcip_flags,
{"Flags", "fcip.flags", FT_UINT8, BASE_HEX,
NULL, 0xFC, NULL, HFILL}},
{ &hf_fcip_flags_c,
{"Flags (1's Complement)", "fcip.flagsc", FT_UINT8, BASE_HEX,
NULL, 0xFC, NULL, HFILL}},
{ &hf_fcip_framelen,
{"Frame Length (in Words)", "fcip.framelen", FT_UINT16, BASE_DEC,
NULL, 0x03FF, NULL, HFILL}},
{ &hf_fcip_framelen_c,
{"Frame Length (1's Complement)", "fcip.framelenc", FT_UINT16, BASE_DEC,
NULL, 0x03FF, NULL, HFILL}},
{ &hf_fcip_tsec,
{"Time (secs)", "fcip.tsec", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_fcip_tusec,
{"Time (fraction)", "fcip.tusec", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_fcip_encap_crc,
{"CRC", "fcip.encap_crc", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_fcip_sof,
{"SOF", "fcip.sof", FT_UINT8, BASE_HEX,
VALS (fcip_sof_vals), 0, NULL, HFILL}},
{ &hf_fcip_sof_c,
{"SOF (1's Complement)", "fcip.sofc", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_fcip_eof,
{"EOF", "fcip.eof", FT_UINT8, BASE_HEX,
VALS (fcip_eof_vals), 0, NULL, HFILL}},
{ &hf_fcip_eof_c,
{"EOF (1's Complement)", "fcip.eofc", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_fcip_pflags_changed,
{"Changed Flag", "fcip.pflags.ch", FT_BOOLEAN, 8,
NULL, 0x80, NULL, HFILL}},
{ &hf_fcip_pflags_special,
{"Special Frame Flag", "fcip.pflags.sf", FT_BOOLEAN, 8,
NULL, 0x1, NULL, HFILL}},
{ &hf_fcip_pflags_c,
{"Pflags (1's Complement)", "fcip.pflagsc", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_fcip_src_wwn,
{"Source Fabric WWN", "fcip.srcwwn", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_fcip_dst_wwn,
{"Destination Fabric WWN", "fcip.dstwwn", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_fcip_src_entity_id,
{"FC/FCIP Entity Id", "fcip.srcid", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_fcip_conn_flags,
{"Connection Usage Flags", "fcip.connflags", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_fcip_conn_code,
{"Connection Usage Code", "fcip.conncode", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_fcip_katov,
{"K_A_TOV", "fcip.katov", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_fcip_conn_nonce,
{"Connection Nonce", "fcip.nonce", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
};
static gint *ett[] = {
&ett_fcip,
};
module_t *fcip_module;
proto_fcip = proto_register_protocol("FCIP", "Fibre Channel over IP", "fcip");
proto_register_field_array(proto_fcip, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
fcip_module = prefs_register_protocol(proto_fcip, NULL);
prefs_register_bool_preference(fcip_module,
"desegment",
"Reassemble FCIP messages spanning multiple TCP segments",
"Whether the FCIP dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable"
" \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&fcip_desegment);
prefs_register_uint_preference(fcip_module,
"target_port",
"Target port",
"Port number used for FCIP",
10,
&fcip_port);
}
void
proto_reg_handoff_fcip (void)
{
dissector_handle_t fcip_handle;
heur_dissector_add("tcp", dissect_fcip_heur, proto_fcip);
fcip_handle = create_dissector_handle(dissect_fcip_handle, proto_fcip);
dissector_add_for_decode_as("tcp.port", fcip_handle);
data_handle = find_dissector("data");
fc_handle = find_dissector("fc");
}
