static void
dissect_mdshdr(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti_main, *ti_hdr, *ti_trlr;
proto_item *hidden_item;
proto_tree *mdshdr_tree_main, *mdshdr_tree_hdr, *mdshdr_tree_trlr;
int offset = 0;
guint pktlen;
tvbuff_t *next_tvb;
guint8 sof, eof;
guint16 vsan;
guint8 span_id;
int trailer_start = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MDS Header");
col_clear(pinfo->cinfo, COL_INFO);
sof = tvb_get_guint8(tvb, offset+MDSHDR_SOF_OFFSET) & 0x0F;
pktlen = tvb_get_ntohs(tvb, offset+MDSHDR_PKTLEN_OFFSET) & 0x1FFF;
vsan = tvb_get_ntohs(tvb, offset+MDSHDR_VSAN_OFFSET) & 0x0FFF;
span_id = (tvb_get_ntohs(tvb, offset+MDSHDR_VSAN_OFFSET) & 0xF000) >> 12;
if ((tvb_length(tvb) >= (MDSHDR_HEADER_SIZE + pktlen))
&& (pktlen >= MDSHDR_TRAILER_SIZE)) {
trailer_start = MDSHDR_HEADER_SIZE + pktlen - MDSHDR_TRAILER_SIZE;
eof = tvb_get_guint8(tvb, trailer_start);
tvb_set_reported_length(tvb, MDSHDR_HEADER_SIZE+pktlen);
}
else {
eof = MDSHDR_EOF_UNKNOWN;
}
pinfo->src_idx = (tvb_get_ntohs(tvb, MDSHDR_SIDX_OFFSET) & 0x3FF);
pinfo->dst_idx = (tvb_get_ntohs(tvb, MDSHDR_DIDX_OFFSET) & 0xFFC) >> 2;
pinfo->vsan = vsan;
pinfo->sof_eof = 0;
if ((sof == MDSHDR_SOFi3) || (sof == MDSHDR_SOFi2) || (sof == MDSHDR_SOFi1)
|| (sof == MDSHDR_SOFi4)) {
pinfo->sof_eof = PINFO_SOF_FIRST_FRAME;
}
else if (sof == MDSHDR_SOFf) {
pinfo->sof_eof = PINFO_SOF_SOFF;
}
if (eof != MDSHDR_EOFn) {
pinfo->sof_eof |= PINFO_EOF_LAST_FRAME;
}
else if (eof != MDSHDR_EOFt) {
pinfo->sof_eof |= PINFO_EOF_INVALID;
}
if (tree) {
ti_main = proto_tree_add_protocol_format(tree, proto_mdshdr, tvb, 0,
MDSHDR_HEADER_SIZE+pktlen,
"MDS Header(%s/%s)",
val_to_str(sof, sof_vals, "Unknown(%u)"),
val_to_str(eof, eof_vals, "Unknown(%u)"));
mdshdr_tree_main = proto_item_add_subtree(ti_main, ett_mdshdr);
ti_hdr = proto_tree_add_text(mdshdr_tree_main, tvb, MDSHDR_VER_OFFSET,
MDSHDR_HEADER_SIZE, "MDS Header");
mdshdr_tree_hdr = proto_item_add_subtree(ti_hdr, ett_mdshdr_hdr);
hidden_item = proto_tree_add_item(mdshdr_tree_hdr, hf_mdshdr_sof, tvb, MDSHDR_SOF_OFFSET,
MDSHDR_SIZE_BYTE, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_item(mdshdr_tree_hdr, hf_mdshdr_pkt_len, tvb, MDSHDR_PKTLEN_OFFSET,
MDSHDR_SIZE_INT16, ENC_BIG_ENDIAN);
proto_tree_add_item(mdshdr_tree_hdr, hf_mdshdr_dstidx, tvb, MDSHDR_DIDX_OFFSET,
MDSHDR_SIZE_INT16, ENC_BIG_ENDIAN);
proto_tree_add_item(mdshdr_tree_hdr, hf_mdshdr_srcidx, tvb, MDSHDR_SIDX_OFFSET,
MDSHDR_SIZE_INT16, ENC_BIG_ENDIAN);
proto_tree_add_item(mdshdr_tree_hdr, hf_mdshdr_vsan, tvb, MDSHDR_VSAN_OFFSET,
MDSHDR_SIZE_INT16, ENC_BIG_ENDIAN);
hidden_item = proto_tree_add_uint(mdshdr_tree_hdr, hf_mdshdr_span,
tvb, MDSHDR_VSAN_OFFSET,
MDSHDR_SIZE_BYTE, span_id);
PROTO_ITEM_SET_HIDDEN(hidden_item);
if (tvb_length(tvb) >= MDSHDR_HEADER_SIZE + pktlen
&& 0 != trailer_start) {
ti_trlr = proto_tree_add_text(mdshdr_tree_main, tvb, trailer_start,
MDSHDR_TRAILER_SIZE,
"MDS Trailer");
mdshdr_tree_trlr = proto_item_add_subtree(ti_trlr, ett_mdshdr_trlr);
proto_tree_add_item(mdshdr_tree_trlr, hf_mdshdr_eof, tvb,
trailer_start, MDSHDR_SIZE_BYTE, ENC_BIG_ENDIAN);
proto_tree_add_item(mdshdr_tree_trlr, hf_mdshdr_fccrc, tvb,
trailer_start+2, MDSHDR_SIZE_INT32, ENC_BIG_ENDIAN);
}
else {
proto_tree_add_text(mdshdr_tree_main, tvb, 0, 0, "MDS Trailer: Not Found");
}
}
if (tvb_length(tvb) >= MDSHDR_HEADER_SIZE + pktlen
&& 0 != pktlen ) {
next_tvb = tvb_new_subset(tvb, MDSHDR_HEADER_SIZE, pktlen, pktlen);
}
else {
next_tvb = tvb_new_subset_remaining(tvb, MDSHDR_HEADER_SIZE);
}
if (fc_dissector_handle) {
call_dissector(fc_dissector_handle, next_tvb, pinfo, tree);
}
else {
call_dissector(data_handle, next_tvb, pinfo, tree);
}
}
void
proto_register_mdshdr(void)
{
static hf_register_info hf[] = {
{ &hf_mdshdr_sof,
{"SOF", "mdshdr.sof", FT_UINT8, BASE_DEC, VALS(sof_vals), 0x0, NULL, HFILL}},
{ &hf_mdshdr_pkt_len,
{"Packet Len", "mdshdr.plen", FT_UINT16, BASE_DEC, NULL, 0x1FFF, NULL, HFILL}},
{ &hf_mdshdr_dstidx,
{"Dst Index", "mdshdr.dstidx", FT_UINT16, BASE_HEX, NULL, 0xFFC, NULL, HFILL}},
{ &hf_mdshdr_srcidx,
{"Src Index", "mdshdr.srcidx", FT_UINT16, BASE_HEX, NULL, 0x3FF, NULL, HFILL}},
{ &hf_mdshdr_vsan,
{"VSAN", "mdshdr.vsan", FT_UINT16, BASE_DEC, NULL, 0x0FFF, NULL, HFILL}},
{ &hf_mdshdr_eof,
{"EOF", "mdshdr.eof", FT_UINT8, BASE_DEC, VALS(eof_vals), 0x0, NULL, HFILL}},
{ &hf_mdshdr_span,
{"SPAN Frame", "mdshdr.span", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_mdshdr_fccrc,
{"CRC", "mdshdr.crc", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}},
};
static gint *ett[] = {
&ett_mdshdr,
&ett_mdshdr_hdr,
&ett_mdshdr_trlr
};
module_t *mdshdr_module;
proto_mdshdr = proto_register_protocol("MDS Header", "MDS Header", "mdshdr");
proto_register_field_array(proto_mdshdr, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
mdshdr_module = prefs_register_protocol(proto_mdshdr, proto_reg_handoff_mdshdr);
prefs_register_bool_preference(mdshdr_module, "decode_if_etype_zero",
"Decode as MDS Header if Ethertype == 0",
"A frame is considered for decoding as MDSHDR if either "
"ethertype is 0xFCFC or zero. Turn this flag off if you "
"don't want ethertype zero to be decoded as MDSHDR. "
"This might be useful to avoid problems with test frames.",
&decode_if_zero_etype);
}
void
proto_reg_handoff_mdshdr(void)
{
static dissector_handle_t mdshdr_handle;
static gboolean registered_for_zero_etype = FALSE;
static gboolean mdshdr_prefs_initialized = FALSE;
if (!mdshdr_prefs_initialized) {
mdshdr_handle = create_dissector_handle(dissect_mdshdr, proto_mdshdr);
dissector_add_uint("ethertype", ETHERTYPE_FCFT, mdshdr_handle);
data_handle = find_dissector("data");
fc_dissector_handle = find_dissector("fc");
mdshdr_prefs_initialized = TRUE;
}
if (decode_if_zero_etype) {
if (!registered_for_zero_etype) {
dissector_add_uint("ethertype", ETHERTYPE_UNK, mdshdr_handle);
registered_for_zero_etype = TRUE;
}
} else {
if (registered_for_zero_etype) {
dissector_delete_uint("ethertype", ETHERTYPE_UNK, mdshdr_handle);
registered_for_zero_etype = FALSE;
}
}
}
