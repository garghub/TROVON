static int
dissect_mdshdr(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti_main;
proto_item *hidden_item;
proto_tree *mdshdr_tree_main, *mdshdr_tree_hdr, *mdshdr_tree_trlr;
int offset = 0;
guint pktlen;
tvbuff_t *next_tvb;
guint8 sof, eof;
int trailer_start = 0;
fc_data_t fc_data;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MDS Header");
col_clear(pinfo->cinfo, COL_INFO);
sof = tvb_get_guint8(tvb, offset+MDSHDR_SOF_OFFSET) & 0x0F;
pktlen = tvb_get_ntohs(tvb, offset+MDSHDR_PKTLEN_OFFSET) & 0x1FFF;
if ((tvb_captured_length(tvb) >= (MDSHDR_HEADER_SIZE + pktlen))
&& (pktlen >= MDSHDR_TRAILER_SIZE)) {
trailer_start = MDSHDR_HEADER_SIZE + pktlen - MDSHDR_TRAILER_SIZE;
eof = tvb_get_guint8(tvb, trailer_start);
tvb_set_reported_length(tvb, MDSHDR_HEADER_SIZE+pktlen);
}
else {
eof = MDSHDR_EOF_UNKNOWN;
}
fc_data.sof_eof = 0;
if ((sof == MDSHDR_SOFi3) || (sof == MDSHDR_SOFi2) || (sof == MDSHDR_SOFi1)
|| (sof == MDSHDR_SOFi4)) {
fc_data.sof_eof = FC_DATA_SOF_FIRST_FRAME;
}
else if (sof == MDSHDR_SOFf) {
fc_data.sof_eof = FC_DATA_SOF_SOFF;
}
if (eof != MDSHDR_EOFn) {
fc_data.sof_eof |= FC_DATA_EOF_LAST_FRAME;
}
else if (eof != MDSHDR_EOFt) {
fc_data.sof_eof |= FC_DATA_EOF_INVALID;
}
if (tree) {
ti_main = proto_tree_add_protocol_format(tree, proto_mdshdr, tvb, 0,
MDSHDR_HEADER_SIZE+pktlen,
"MDS Header(%s/%s)",
val_to_str(sof, sof_vals, "Unknown(%u)"),
val_to_str(eof, eof_vals, "Unknown(%u)"));
mdshdr_tree_main = proto_item_add_subtree(ti_main, ett_mdshdr);
mdshdr_tree_hdr = proto_tree_add_subtree(mdshdr_tree_main, tvb, MDSHDR_VER_OFFSET,
MDSHDR_HEADER_SIZE, ett_mdshdr_hdr, NULL, "MDS Header");
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
hidden_item = proto_tree_add_item(mdshdr_tree_hdr, hf_mdshdr_span,
tvb, MDSHDR_VSAN_OFFSET,
MDSHDR_SIZE_INT16, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
if (tvb_reported_length(tvb) >= MDSHDR_HEADER_SIZE + pktlen
&& 0 != trailer_start) {
mdshdr_tree_trlr = proto_tree_add_subtree(mdshdr_tree_main, tvb, trailer_start,
MDSHDR_TRAILER_SIZE,
ett_mdshdr_trlr, NULL, "MDS Trailer");
proto_tree_add_item(mdshdr_tree_trlr, hf_mdshdr_eof, tvb,
trailer_start, MDSHDR_SIZE_BYTE, ENC_BIG_ENDIAN);
proto_tree_add_item(mdshdr_tree_trlr, hf_mdshdr_fccrc, tvb,
trailer_start+2, MDSHDR_SIZE_INT32, ENC_BIG_ENDIAN);
}
else {
proto_tree_add_item(mdshdr_tree_main, hf_mdshdr_no_trailer, tvb, 0, 0, ENC_NA);
}
}
if (tvb_reported_length(tvb) >= MDSHDR_HEADER_SIZE + pktlen
&& 0 != pktlen ) {
next_tvb = tvb_new_subset_length(tvb, MDSHDR_HEADER_SIZE, pktlen);
}
else {
next_tvb = tvb_new_subset_remaining(tvb, MDSHDR_HEADER_SIZE);
}
if (fc_dissector_handle) {
fc_data.ethertype = ETHERTYPE_FCFT;
call_dissector_with_data(fc_dissector_handle, next_tvb, pinfo, tree, &fc_data);
}
else {
call_data_dissector(next_tvb, pinfo, tree);
}
return tvb_captured_length(tvb);
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
{ &hf_mdshdr_no_trailer,
{"MDS Trailer: Not Found", "mdshdr.no_trailer", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_mdshdr_span,
{"SPAN Frame", "mdshdr.span", FT_UINT16, BASE_DEC, NULL, 0xF000, NULL, HFILL}},
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
fc_dissector_handle = find_dissector_add_dependency("fc", proto_mdshdr);
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
