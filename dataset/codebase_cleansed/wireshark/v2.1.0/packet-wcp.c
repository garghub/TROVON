static void
dissect_wcp_con_req(tvbuff_t *tvb, int offset, proto_tree *tree) {
guint32 alg_cnt;
proto_tree_add_item(tree, hf_wcp_tid, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_wcp_rev, tvb, offset + 2, 1, ENC_NA);
proto_tree_add_item(tree, hf_wcp_init, tvb, offset + 3, 1, ENC_NA);
proto_tree_add_item(tree, hf_wcp_seq_size, tvb, offset + 4, 1, ENC_NA);
proto_tree_add_item_ret_uint(tree, hf_wcp_alg_cnt, tvb, offset + 5, 1, ENC_NA, &alg_cnt);
proto_tree_add_item(tree, hf_wcp_alg_a, tvb, offset + 6, 1, ENC_NA);
if ( alg_cnt > 1)
proto_tree_add_item(tree, hf_wcp_alg_b, tvb, offset + 7, 1, ENC_NA);
if ( alg_cnt > 2)
proto_tree_add_item(tree, hf_wcp_alg_c, tvb, offset + 8, 1, ENC_NA);
if ( alg_cnt > 3)
proto_tree_add_item(tree, hf_wcp_alg_d, tvb, offset + 9, 1, ENC_NA);
}
static void
dissect_wcp_con_ack( tvbuff_t *tvb, int offset, proto_tree *tree){
proto_tree_add_item(tree, hf_wcp_tid, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_wcp_rev, tvb, offset + 2, 1, ENC_NA);
proto_tree_add_item(tree, hf_wcp_seq_size, tvb, offset + 3, 1, ENC_NA);
proto_tree_add_item(tree, hf_wcp_alg, tvb, offset + 4, 1, ENC_NA);
}
static void
dissect_wcp_init( tvbuff_t *tvb, int offset, proto_tree *tree){
proto_tree_add_item(tree, hf_wcp_tid, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_wcp_rev, tvb, offset + 2, 1, ENC_NA);
proto_tree_add_item(tree, hf_wcp_hist_size, tvb, offset + 3, 1, ENC_NA);
proto_tree_add_item(tree, hf_wcp_ppc, tvb, offset + 4, 1, ENC_NA);
proto_tree_add_item(tree, hf_wcp_pib, tvb, offset + 5, 1, ENC_NA);
}
static void
dissect_wcp_reset( tvbuff_t *tvb, int offset, proto_tree *tree){
proto_tree_add_item(tree, hf_wcp_tid, tvb, offset, 2, ENC_BIG_ENDIAN);
}
static void wcp_save_data( tvbuff_t *tvb, packet_info *pinfo, circuit_type ctype, guint32 circuit_id){
wcp_window_t *buf_ptr = 0;
size_t len;
len = tvb_reported_length( tvb)-3;
buf_ptr = get_wcp_window_ptr(pinfo, ctype, circuit_id);
if (( buf_ptr->buf_cur + len) <= (buf_ptr->buffer + MAX_WIN_BUF_LEN)){
tvb_memcpy( tvb, buf_ptr->buf_cur, 2, len);
buf_ptr->buf_cur = buf_ptr->buf_cur + len;
} else {
guint8 *buf_end = buf_ptr->buffer + MAX_WIN_BUF_LEN;
tvb_memcpy( tvb, buf_ptr->buf_cur, 2, buf_end - buf_ptr->buf_cur);
tvb_memcpy( tvb, buf_ptr->buffer, (gint) (buf_end - buf_ptr->buf_cur-2),
len - (buf_end - buf_ptr->buf_cur));
buf_ptr->buf_cur = buf_ptr->buf_cur + len - MAX_WIN_BUF_LEN;
}
}
static int dissect_wcp( tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_) {
proto_tree *wcp_tree;
proto_item *ti;
int wcp_header_len;
guint16 temp, cmd, ext_cmd, seq;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "WCP");
col_clear(pinfo->cinfo, COL_INFO);
temp = tvb_get_ntohs(tvb, 0);
cmd = (temp & 0xf000) >> 12;
ext_cmd = (temp & 0x0f00) >> 8;
if ( cmd == 0xf)
wcp_header_len= 1;
else
wcp_header_len= 2;
seq = temp & 0x0fff;
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const(cmd, cmd_string, "Unknown"));
if ( cmd == 0xf)
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s",
val_to_str_const(ext_cmd, ext_cmd_string, "Unknown"));
ti = proto_tree_add_item(tree, proto_wcp, tvb, 0, wcp_header_len, ENC_NA);
wcp_tree = proto_item_add_subtree(ti, ett_wcp);
proto_tree_add_item(wcp_tree, hf_wcp_cmd, tvb, 0, 1, ENC_NA);
if ( cmd == 0xf){
proto_tree_add_uint(wcp_tree, hf_wcp_ext_cmd, tvb, 1, 1,
tvb_get_guint8( tvb, 0));
switch (ext_cmd){
case CONNECT_REQ:
dissect_wcp_con_req( tvb, 1, wcp_tree);
break;
case CONNECT_ACK:
dissect_wcp_con_ack( tvb, 1, wcp_tree);
break;
case INIT_REQ:
case INIT_ACK:
dissect_wcp_init( tvb, 1, wcp_tree);
break;
case RESET_REQ:
case RESET_ACK:
dissect_wcp_reset( tvb, 1, wcp_tree);
break;
default:
break;
}
}else {
proto_tree_add_uint(wcp_tree, hf_wcp_seq, tvb, 0, 2, seq);
}
if ( cmd != 1 && cmd != 0 && !(cmd == 0xf && ext_cmd == 0))
return 2;
if ( cmd == 1) {
if ( !pinfo->fd->flags.visited){
wcp_save_data( tvb, pinfo, pinfo->ctype, pinfo->circuit_id);
}
next_tvb = tvb_new_subset_remaining(tvb, wcp_header_len);
}
else {
next_tvb = wcp_uncompress( tvb, wcp_header_len, pinfo, wcp_tree, pinfo->ctype, pinfo->circuit_id);
if ( !next_tvb){
return tvb_captured_length(tvb);
}
}
proto_tree_add_item(wcp_tree, hf_wcp_chksum, tvb,
tvb_reported_length( tvb)-1, 1, ENC_NA);
call_dissector(fr_uncompressed_handle, next_tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
static guint8 *
decompressed_entry(guint8 *dst, guint16 data_offset,
guint16 data_cnt, int *len, wcp_window_t *buf_ptr)
{
const guint8 *src;
guint8 *buf_start, *buf_end;
buf_start = buf_ptr->buffer;
buf_end = buf_ptr->buffer + MAX_WIN_BUF_LEN;
src = (dst - 1 - data_offset);
if ( src < buf_start)
src += MAX_WIN_BUF_LEN;
while( data_cnt--){
*dst = *src;
if ( buf_ptr->initialized < MAX_WIN_BUF_LEN)
buf_ptr->initialized++;
if ( ++(*len) >MAX_WCP_BUF_LEN){
return NULL;
}
if ( dst++ == buf_end)
dst = buf_start;
if ( src++ == buf_end)
src = buf_start;
}
return dst;
}
static
wcp_window_t *get_wcp_window_ptr(packet_info *pinfo, circuit_type ctype, guint32 circuit_id){
circuit_t *circuit;
wcp_circuit_data_t *wcp_circuit_data;
circuit = find_circuit( ctype, circuit_id,
pinfo->num);
if ( !circuit){
circuit = circuit_new( ctype, circuit_id,
pinfo->num);
}
wcp_circuit_data = (wcp_circuit_data_t *)circuit_get_proto_data(circuit, proto_wcp);
if ( !wcp_circuit_data){
wcp_circuit_data = wmem_new(wmem_file_scope(), wcp_circuit_data_t);
wcp_circuit_data->recv.buf_cur = wcp_circuit_data->recv.buffer;
wcp_circuit_data->recv.initialized = 0;
wcp_circuit_data->send.buf_cur = wcp_circuit_data->send.buffer;
wcp_circuit_data->send.initialized = 0;
circuit_add_proto_data(circuit, proto_wcp, wcp_circuit_data);
}
if (pinfo->pseudo_header->x25.flags & FROM_DCE)
return &wcp_circuit_data->recv;
else
return &wcp_circuit_data->send;
}
static tvbuff_t *wcp_uncompress( tvbuff_t *src_tvb, int offset, packet_info *pinfo, proto_tree *tree, circuit_type ctype, guint32 circuit_id) {
proto_tree *cd_tree, *sub_tree;
proto_item *cd_item, *ti;
int len, i;
int cnt = tvb_reported_length( src_tvb)-1;
guint8 *dst, *src, *buf_start, *buf_end, comp_flag_bits = 0;
guint16 data_offset, data_cnt;
guint8 src_buf[ MAX_WCP_BUF_LEN];
tvbuff_t *tvb;
wcp_window_t *buf_ptr = 0;
wcp_pdata_t *pdata_ptr;
buf_ptr = get_wcp_window_ptr(pinfo, ctype, circuit_id);
buf_start = buf_ptr->buffer;
buf_end = buf_start + MAX_WIN_BUF_LEN;
cd_item = proto_tree_add_item(tree, hf_wcp_compressed_data,
src_tvb, offset, cnt - offset, ENC_NA);
cd_tree = proto_item_add_subtree(cd_item, ett_wcp_comp_data);
if (cnt - offset > MAX_WCP_BUF_LEN) {
expert_add_info_format(pinfo, cd_item, &ei_wcp_compressed_data_exceeds,
"Compressed data exceeds maximum buffer length (%d > %d)",
cnt - offset, MAX_WCP_BUF_LEN);
return NULL;
}
src = (guint8 *)tvb_memcpy(src_tvb, src_buf, offset, cnt - offset);
dst = buf_ptr->buf_cur;
len = 0;
i = -1;
while( offset < cnt){
if ( --i >= 0){
if ( comp_flag_bits & 0x80){
if (!(offset + 1 < cnt)) {
return NULL;
}
data_offset = pntoh16(src) & WCP_OFFSET_MASK;
if ((*src & 0xf0) == 0x10){
if (!(offset + 2 < cnt)) {
return NULL;
}
data_cnt = *(src + 2) + 1;
if ( tree) {
ti = proto_tree_add_item( cd_tree, hf_wcp_long_run, src_tvb,
offset, 3, ENC_NA);
sub_tree = proto_item_add_subtree(ti, ett_wcp_field);
proto_tree_add_uint(sub_tree, hf_wcp_offset, src_tvb,
offset, 2, data_offset);
proto_tree_add_item( sub_tree, hf_wcp_long_len, src_tvb,
offset+2, 1, ENC_BIG_ENDIAN);
}
src += 3;
offset += 3;
}else{
data_cnt = (*src >> 4) + 1;
if ( tree) {
ti = proto_tree_add_item( cd_tree, hf_wcp_short_run, src_tvb,
offset, 2, ENC_NA);
sub_tree = proto_item_add_subtree(ti, ett_wcp_field);
proto_tree_add_uint( sub_tree, hf_wcp_short_len, src_tvb,
offset, 1, *src);
proto_tree_add_uint(sub_tree, hf_wcp_offset, src_tvb,
offset, 2, data_offset);
}
src += 2;
offset += 2;
}
if (data_offset + 1 > buf_ptr->initialized) {
expert_add_info_format(pinfo, cd_item, &ei_wcp_invalid_window_offset,
"Data offset exceeds valid window size (%d > %d)",
data_offset+1, buf_ptr->initialized);
return NULL;
}
if (data_offset + 1 < data_cnt) {
expert_add_info_format(pinfo, cd_item, &ei_wcp_invalid_window_offset,
"Data count exceeds offset (%d > %d)",
data_cnt, data_offset+1);
return NULL;
}
if ( !pinfo->fd->flags.visited){
dst = decompressed_entry(dst,
data_offset, data_cnt, &len,
buf_ptr);
if (dst == NULL){
expert_add_info_format(pinfo, cd_item, &ei_wcp_uncompressed_data_exceeds,
"Uncompressed data exceeds maximum buffer length (%d > %d)",
len, MAX_WCP_BUF_LEN);
return NULL;
}
}
}else {
if ( ++len >MAX_WCP_BUF_LEN){
expert_add_info_format(pinfo, cd_item, &ei_wcp_uncompressed_data_exceeds,
"Uncompressed data exceeds maximum buffer length (%d > %d)",
len, MAX_WCP_BUF_LEN);
return NULL;
}
if ( !pinfo->fd->flags.visited){
*dst = *src;
if ( dst++ == buf_end)
dst = buf_start;
if (buf_ptr->initialized < MAX_WIN_BUF_LEN)
buf_ptr->initialized++;
}
++src;
++offset;
}
comp_flag_bits <<= 1;
}else {
comp_flag_bits = *src++;
proto_tree_add_uint(cd_tree, hf_wcp_comp_bits, src_tvb, offset, 1,
comp_flag_bits);
offset++;
i = 8;
}
}
if ( pinfo->fd->flags.visited){
pdata_ptr = (wcp_pdata_t *)p_get_proto_data(wmem_file_scope(), pinfo, proto_wcp, 0);
if ( !pdata_ptr) {
REPORT_DISSECTOR_BUG("Can't find uncompressed data");
return NULL;
}
len = pdata_ptr->len;
} else {
pdata_ptr = wmem_new(wmem_file_scope(), wcp_pdata_t);
memcpy( &pdata_ptr->buffer, buf_ptr->buf_cur, len);
pdata_ptr->len = len;
p_add_proto_data(wmem_file_scope(), pinfo, proto_wcp, 0, (void*)pdata_ptr);
buf_ptr->buf_cur = dst;
}
tvb = tvb_new_child_real_data(src_tvb, pdata_ptr->buffer, pdata_ptr->len, pdata_ptr->len);
add_new_data_source( pinfo, tvb, "Uncompressed WCP");
return tvb;
}
void
proto_register_wcp(void)
{
static hf_register_info hf[] = {
{ &hf_wcp_cmd,
{ "Command", "wcp.cmd", FT_UINT8, BASE_HEX, VALS(cmd_string), WCP_CMD,
"Compression Command", HFILL }},
{ &hf_wcp_ext_cmd,
{ "Extended Command", "wcp.ext_cmd", FT_UINT8, BASE_HEX, VALS(ext_cmd_string), WCP_EXT_CMD,
"Extended Compression Command", HFILL }},
{ &hf_wcp_seq,
{ "SEQ", "wcp.seq", FT_UINT16, BASE_HEX, NULL, WCP_SEQ,
"Sequence Number", HFILL }},
{ &hf_wcp_chksum,
{ "Checksum", "wcp.checksum", FT_UINT8, BASE_DEC, NULL, 0,
"Packet Checksum", HFILL }},
{ &hf_wcp_tid,
{ "TID", "wcp.tid", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_wcp_rev,
{ "Revision", "wcp.rev", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_wcp_init,
{ "Initiator", "wcp.init", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_wcp_seq_size,
{ "Seq Size", "wcp.seq_size", FT_UINT8, BASE_DEC, NULL, 0,
"Sequence Size", HFILL }},
{ &hf_wcp_alg_cnt,
{ "Alg Count", "wcp.alg_cnt", FT_UINT8, BASE_DEC, NULL, 0,
"Algorithm Count", HFILL }},
{ &hf_wcp_alg_a,
{ "Alg 1", "wcp.alg1", FT_UINT8, BASE_DEC, NULL, 0,
"Algorithm #1", HFILL }},
{ &hf_wcp_alg_b,
{ "Alg 2", "wcp.alg2", FT_UINT8, BASE_DEC, NULL, 0,
"Algorithm #2", HFILL }},
{ &hf_wcp_alg_c,
{ "Alg 3", "wcp.alg3", FT_UINT8, BASE_DEC, NULL, 0,
"Algorithm #3", HFILL }},
{ &hf_wcp_alg_d,
{ "Alg 4", "wcp.alg4", FT_UINT8, BASE_DEC, NULL, 0,
"Algorithm #4", HFILL }},
{ &hf_wcp_alg,
{ "Alg", "wcp.alg", FT_UINT8, BASE_DEC, NULL, 0,
"Algorithm", HFILL }},
#if 0
{ &hf_wcp_rexmit,
{ "Rexmit", "wcp.rexmit", FT_UINT8, BASE_DEC, NULL, 0,
"Retransmit", HFILL }},
#endif
{ &hf_wcp_hist_size,
{ "History", "wcp.hist", FT_UINT8, BASE_DEC, NULL, 0,
"History Size", HFILL }},
{ &hf_wcp_ppc,
{ "PerPackComp", "wcp.ppc", FT_UINT8, BASE_DEC, NULL, 0,
"Per Packet Compression", HFILL }},
{ &hf_wcp_pib,
{ "PIB", "wcp.pib", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_wcp_compressed_data,
{ "Compressed Data", "wcp.compressed_data", FT_NONE, BASE_NONE, NULL, 0,
"Raw compressed data", HFILL }},
{ &hf_wcp_comp_bits,
{ "Compress Flag", "wcp.flag", FT_UINT8, BASE_HEX, NULL, 0,
"Compressed byte flag", HFILL }},
#if 0
{ &hf_wcp_comp_marker,
{ "Compress Marker", "wcp.mark", FT_UINT8, BASE_DEC, NULL, 0,
"Compressed marker", HFILL }},
#endif
{ &hf_wcp_offset,
{ "Source offset", "wcp.off", FT_UINT16, BASE_HEX, NULL, WCP_OFFSET_MASK,
"Data source offset", HFILL }},
{ &hf_wcp_short_len,
{ "Compress Length", "wcp.short_len", FT_UINT8, BASE_HEX, NULL, 0xf0,
"Compressed length", HFILL }},
{ &hf_wcp_long_len,
{ "Compress Length", "wcp.long_len", FT_UINT8, BASE_HEX, NULL, 0,
"Compressed length", HFILL }},
{ &hf_wcp_long_run,
{ "Long Compression", "wcp.long_comp", FT_BYTES, BASE_NONE, NULL, 0,
"Long Compression type", HFILL }},
{ &hf_wcp_short_run,
{ "Short Compression", "wcp.short_comp", FT_BYTES, BASE_NONE, NULL, 0,
"Short Compression type", HFILL }},
};
static gint *ett[] = {
&ett_wcp,
&ett_wcp_comp_data,
&ett_wcp_field,
};
static ei_register_info ei[] = {
{ &ei_wcp_compressed_data_exceeds, { "wcp.compressed_data.exceeds", PI_MALFORMED, PI_ERROR, "Compressed data exceeds maximum buffer length", EXPFILL }},
{ &ei_wcp_uncompressed_data_exceeds, { "wcp.uncompressed_data.exceeds", PI_MALFORMED, PI_ERROR, "Uncompressed data exceeds maximum buffer length", EXPFILL }},
{ &ei_wcp_invalid_window_offset, { "wcp.off.invalid", PI_MALFORMED, PI_ERROR, "Offset points outside of visible window", EXPFILL }},
#if 0
{ &ei_wcp_invalid_match_length, { "wcp.len.invalid", PI_MALFORMED, PI_ERROR, "Length greater than offset", EXPFILL }},
#endif
};
expert_module_t* expert_wcp;
proto_wcp = proto_register_protocol ("Wellfleet Compression", "WCP", "wcp");
proto_register_field_array (proto_wcp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_wcp = expert_register_protocol(proto_wcp);
expert_register_field_array(expert_wcp, ei, array_length(ei));
}
void
proto_reg_handoff_wcp(void) {
dissector_handle_t wcp_handle;
fr_uncompressed_handle = find_dissector_add_dependency("fr_uncompressed", proto_wcp);
wcp_handle = create_dissector_handle(dissect_wcp, proto_wcp);
dissector_add_uint("fr.nlpid", NLPID_COMPRESSED, wcp_handle);
dissector_add_uint("ethertype", ETHERTYPE_WCP, wcp_handle);
}
