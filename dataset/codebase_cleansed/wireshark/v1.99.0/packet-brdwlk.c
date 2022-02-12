static void
dissect_brdwlk_err(proto_tree *parent_tree, tvbuff_t *tvb, int offset)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint8 flags;
flags = tvb_get_guint8(tvb, offset);
if (parent_tree) {
item=proto_tree_add_uint(parent_tree, hf_brdwlk_error,
tvb, offset, 1, flags);
tree=proto_item_add_subtree(item, ett_brdwlk_error);
}
proto_tree_add_boolean(tree, hf_brdwlk_error_plp, tvb, offset, 1, flags);
if (flags & 0x01) {
proto_item_append_text(item, " Packet Length Present");
}
flags &= (~( 0x01 ));
proto_tree_add_boolean(tree, hf_brdwlk_error_ef, tvb, offset, 1, flags);
if (flags & 0x02) {
proto_item_append_text(item, " Empty Frame");
}
flags &= (~( 0x02 ));
proto_tree_add_boolean(tree, hf_brdwlk_error_nd, tvb, offset, 1, flags);
if (flags & 0x04) {
proto_item_append_text(item, " No Data");
}
flags &= (~( 0x04 ));
proto_tree_add_boolean(tree, hf_brdwlk_error_tr, tvb, offset, 1, flags);
if (flags & 0x08) {
proto_item_append_text(item, " Truncated");
}
flags &= (~( 0x08 ));
proto_tree_add_boolean(tree, hf_brdwlk_error_badcrc, tvb, offset, 1, flags);
if (flags & 0x10) {
proto_item_append_text(item, " Bad FC CRC");
}
flags &= (~( 0x10 ));
proto_tree_add_boolean(tree, hf_brdwlk_error_ff, tvb, offset, 1, flags);
if (flags & 0x20) {
proto_item_append_text(item, " Fifo Full");
}
flags &= (~( 0x20 ));
proto_tree_add_boolean(tree, hf_brdwlk_error_jumbo, tvb, offset, 1, flags);
if (flags & 0x40) {
proto_item_append_text(item, " Jumbo FC Frame");
}
flags &= (~( 0x40 ));
proto_tree_add_boolean(tree, hf_brdwlk_error_ctrl, tvb, offset, 1, flags);
if (flags & 0x80) {
proto_item_append_text(item, " Ctrl Char Inside Frame");
}
}
static void
dissect_brdwlk(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti, *hidden_item;
proto_tree *brdwlk_tree = NULL;
tvbuff_t *next_tvb;
guint8 error, eof, sof;
int hdrlen = 2,
offset = 0;
gint len, reported_len, plen;
guint16 pkt_cnt;
gboolean dropped_packets;
fc_data_t fc_data;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Boardwalk");
col_clear(pinfo->cinfo, COL_INFO);
sof = (tvb_get_guint8(tvb, offset) & 0xF0) >> 4;
fc_data.sof_eof = 0;
if ((sof == FCM_DELIM_SOFI3) || (sof == FCM_DELIM_SOFI2) || (sof == FCM_DELIM_SOFI1)
|| (sof == FCM_DELIM_SOFI4)) {
fc_data.sof_eof = FC_DATA_SOF_FIRST_FRAME;
}
else if (sof == FCM_DELIM_SOFF) {
fc_data.sof_eof = FC_DATA_SOF_SOFF;
}
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_brdwlk, tvb, 0,
hdrlen, "Boardwalk");
brdwlk_tree = proto_item_add_subtree(ti, ett_brdwlk);
proto_tree_add_item(brdwlk_tree, hf_brdwlk_sof, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(brdwlk_tree, hf_brdwlk_vsan, tvb, offset, 2, ENC_BIG_ENDIAN);
}
len = tvb_length_remaining(tvb, hdrlen);
reported_len = tvb_reported_length_remaining(tvb, hdrlen);
if (reported_len < 4) {
;
}
else if (len < reported_len) {
reported_len -= 4;
if (len > reported_len)
len = reported_len;
}
else {
len -= 4;
reported_len -= 4;
offset = tvb_reported_length(tvb) - 4;
pkt_cnt = tvb_get_ntohs(tvb, offset);
if (tree) {
proto_tree_add_uint(brdwlk_tree, hf_brdwlk_pktcnt, tvb, offset,
2, pkt_cnt);
}
dropped_packets = FALSE;
if (pinfo->fd->flags.visited) {
if (p_get_proto_data(wmem_file_scope(), pinfo, proto_brdwlk, 0) != NULL)
dropped_packets = TRUE;
} else {
if (pkt_cnt != packet_count + 1) {
if (!first_pkt &&
(pkt_cnt != 0 || (packet_count != BRDWLK_MAX_PACKET_CNT))) {
dropped_packets = TRUE;
p_add_proto_data(wmem_file_scope(), pinfo, proto_brdwlk, 0, &packet_count);
}
}
}
if (tree) {
hidden_item = proto_tree_add_boolean(brdwlk_tree, hf_brdwlk_drop,
tvb, offset, 0, dropped_packets);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
packet_count = pkt_cnt;
error=tvb_get_guint8(tvb, offset+2);
dissect_brdwlk_err(brdwlk_tree, tvb, offset+2);
eof = tvb_get_guint8(tvb, offset+3);
if (eof != FCM_DELIM_EOFN) {
fc_data.sof_eof |= FC_DATA_EOF_LAST_FRAME;
}
else if (eof != FCM_DELIM_EOFT) {
fc_data.sof_eof |= FC_DATA_EOF_INVALID;
}
if (tree) {
proto_tree_add_item(brdwlk_tree, hf_brdwlk_eof, tvb, offset+3,
1, ENC_BIG_ENDIAN);
}
if ((error & BRDWLK_HAS_PLEN) && tree) {
plen = tvb_get_ntohl(tvb, offset-4);
plen *= 4;
proto_tree_add_uint(brdwlk_tree, hf_brdwlk_plen, tvb, offset-4,
4, plen);
#if 0
if (error & BRDWLK_TRUNCATED_BIT) {
tvb_set_reported_length(tvb, plen);
}
#endif
}
}
fc_data.ethertype = ETHERTYPE_BRDWALK;
next_tvb = tvb_new_subset(tvb, 2, len, reported_len);
call_dissector_with_data(fc_dissector_handle, next_tvb, pinfo, tree, &fc_data);
}
static void
brdwlk_init(void)
{
packet_count = 0;
first_pkt = TRUE;
}
void
proto_register_brdwlk(void)
{
static hf_register_info hf[] = {
{ &hf_brdwlk_sof,
{"SOF", "brdwlk.sof", FT_UINT8, BASE_HEX, VALS(brdwlk_sof_vals),
0xF0, NULL, HFILL}},
{ &hf_brdwlk_eof,
{"EOF", "brdwlk.eof", FT_UINT8, BASE_HEX, VALS(brdwlk_eof_vals),
0x0F, NULL, HFILL}},
{ &hf_brdwlk_error,
{"Error", "brdwlk.error", FT_UINT8, BASE_HEX, NULL, 0x0, NULL,
HFILL}},
{ &hf_brdwlk_pktcnt,
{"Packet Count", "brdwlk.pktcnt", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_brdwlk_drop,
{"Packet Dropped", "brdwlk.drop", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_brdwlk_vsan,
{"VSAN", "brdwlk.vsan", FT_UINT16, BASE_DEC, NULL, 0xFFF, NULL,
HFILL}},
{ &hf_brdwlk_plen,
{"Original Packet Length", "brdwlk.plen", FT_UINT32, BASE_DEC, NULL, 0x0, NULL,
HFILL}},
{ &hf_brdwlk_error_plp,
{"Packet Length Present", "brdwlk.error.plp", FT_BOOLEAN, 8, TFS(&tfs_error_plp), 0x01, NULL,
HFILL}},
{ &hf_brdwlk_error_ef,
{"Empty Frame", "brdwlk.error.ef", FT_BOOLEAN, 8, TFS(&tfs_error_ef), 0x02, NULL,
HFILL}},
{ &hf_brdwlk_error_nd,
{"No Data", "brdwlk.error.nd", FT_BOOLEAN, 8, TFS(&tfs_error_nd), 0x04, NULL,
HFILL}},
{ &hf_brdwlk_error_tr,
{"Truncated", "brdwlk.error.tr", FT_BOOLEAN, 8, TFS(&tfs_error_tr), 0x08, NULL,
HFILL}},
{ &hf_brdwlk_error_badcrc,
{"CRC", "brdwlk.error.crc", FT_BOOLEAN, 8, TFS(&tfs_error_crc), 0x10, NULL,
HFILL}},
{ &hf_brdwlk_error_ff,
{"Fifo Full", "brdwlk.error.ff", FT_BOOLEAN, 8, TFS(&tfs_error_ff), 0x20, NULL,
HFILL}},
{ &hf_brdwlk_error_jumbo,
{"Jumbo FC Frame", "brdwlk.error.jumbo", FT_BOOLEAN, 8, TFS(&tfs_error_jumbo), 0x40, NULL,
HFILL}},
{ &hf_brdwlk_error_ctrl,
{"Ctrl Char Inside Frame", "brdwlk.error.ctrl", FT_BOOLEAN, 8, TFS(&tfs_error_ctrl), 0x80, NULL,
HFILL}},
};
static gint *ett[] = {
&ett_brdwlk,
&ett_brdwlk_error,
};
proto_brdwlk = proto_register_protocol("Boardwalk",
"Boardwalk", "brdwlk");
proto_register_field_array(proto_brdwlk, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_init_routine(&brdwlk_init);
}
void
proto_reg_handoff_brdwlk(void)
{
dissector_handle_t brdwlk_handle;
brdwlk_handle = create_dissector_handle(dissect_brdwlk, proto_brdwlk);
dissector_add_uint("ethertype", ETHERTYPE_BRDWALK, brdwlk_handle);
dissector_add_uint("ethertype", 0xABCD, brdwlk_handle);
fc_dissector_handle = find_dissector("fc");
}
