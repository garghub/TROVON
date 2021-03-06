static void
dissect_wcp_con_req(tvbuff_t *tvb, int offset, proto_tree *tree) {
guint alg_cnt = tvb_get_guint8(tvb, 5);
proto_tree_add_uint(tree, hf_wcp_tid, tvb, offset, 2, tvb_get_ntohs(tvb, offset));
proto_tree_add_uint(tree, hf_wcp_rev, tvb, offset + 2, 1, tvb_get_guint8(tvb, offset + 2));
proto_tree_add_uint(tree, hf_wcp_init, tvb, offset + 3, 1, tvb_get_guint8(tvb, offset + 3));
proto_tree_add_uint(tree, hf_wcp_seq_size, tvb, offset + 4, 1, tvb_get_guint8(tvb, offset + 4));
proto_tree_add_uint(tree, hf_wcp_alg_cnt, tvb, offset + 5, 1, alg_cnt);
proto_tree_add_uint(tree, hf_wcp_alg_a, tvb, offset + 6, 1, tvb_get_guint8(tvb, offset + 6));
if ( alg_cnt > 1)
proto_tree_add_uint(tree, hf_wcp_alg_b, tvb, offset + 7, 1, tvb_get_guint8(tvb, offset + 7));
if ( alg_cnt > 2)
proto_tree_add_uint(tree, hf_wcp_alg_c, tvb, offset + 8, 1, tvb_get_guint8(tvb, offset + 8));
if ( alg_cnt > 3)
proto_tree_add_uint(tree, hf_wcp_alg_d, tvb, offset + 9, 1, tvb_get_guint8(tvb, offset + 9));
}
static void
dissect_wcp_con_ack( tvbuff_t *tvb, int offset, proto_tree *tree){
proto_tree_add_uint(tree, hf_wcp_tid, tvb, offset, 2, tvb_get_ntohs(tvb, offset));
proto_tree_add_uint(tree, hf_wcp_rev, tvb, offset + 2, 1, tvb_get_guint8(tvb, offset + 2));
proto_tree_add_uint(tree, hf_wcp_seq_size, tvb, offset + 3, 1, tvb_get_guint8(tvb, offset + 3));
proto_tree_add_uint(tree, hf_wcp_alg, tvb, offset + 4, 1, tvb_get_guint8(tvb, offset + 4));
}
static void
dissect_wcp_init( tvbuff_t *tvb, int offset, proto_tree *tree){
proto_tree_add_uint(tree, hf_wcp_tid, tvb, offset, 2, tvb_get_ntohs(tvb, offset));
proto_tree_add_uint(tree, hf_wcp_rev, tvb, offset + 2, 1, tvb_get_guint8(tvb, offset + 2));
proto_tree_add_uint(tree, hf_wcp_hist_size, tvb, offset + 3, 1, tvb_get_guint8(tvb, offset + 3));
proto_tree_add_uint(tree, hf_wcp_ppc, tvb, offset + 4, 1, tvb_get_guint8(tvb, offset + 4));
proto_tree_add_uint(tree, hf_wcp_pib, tvb, offset + 5, 1, tvb_get_guint8(tvb, offset + 5));
}
static void
dissect_wcp_reset( tvbuff_t *tvb, int offset, proto_tree *tree){
proto_tree_add_uint(tree, hf_wcp_tid, tvb, offset, 2, tvb_get_ntohs(tvb, offset));
}
static void wcp_save_data( tvbuff_t *tvb, packet_info *pinfo){
wcp_window_t *buf_ptr = 0;
size_t len;
len = tvb_reported_length( tvb)-3;
buf_ptr = get_wcp_window_ptr( pinfo);
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
static void dissect_wcp( tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
proto_tree *wcp_tree;
proto_item *ti;
int wcp_header_len;
guint16 temp, cmd, ext_cmd, seq;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "WCP");
col_clear(pinfo->cinfo, COL_INFO);
temp =tvb_get_ntohs(tvb, 0);
cmd = (temp & 0xf000) >> 12;
ext_cmd = (temp & 0x0f00) >> 8;
if ( cmd == 0xf)
wcp_header_len= 1;
else
wcp_header_len= 2;
seq = temp & 0x0fff;
if (check_col(pinfo->cinfo, COL_INFO)){
col_add_str(pinfo->cinfo, COL_INFO, val_to_str(cmd, cmd_string, "Unknown"));
if ( cmd == 0xf)
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s",
val_to_str(ext_cmd, ext_cmd_string, "Unknown"));
}
if (tree) {
ti = proto_tree_add_item(tree, proto_wcp, tvb, 0, wcp_header_len, ENC_NA);
wcp_tree = proto_item_add_subtree(ti, ett_wcp);
proto_tree_add_uint(wcp_tree, hf_wcp_cmd, tvb, 0, 1, tvb_get_guint8( tvb, 0));
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
}
else {
wcp_tree = NULL;
}
if ( cmd != 1 && cmd != 0 && !(cmd == 0xf && ext_cmd == 0))
return;
if ( cmd == 1) {
if ( !pinfo->fd->flags.visited){
wcp_save_data( tvb, pinfo);
}
next_tvb = tvb_new_subset_remaining(tvb, wcp_header_len);
}
else {
next_tvb = wcp_uncompress( tvb, wcp_header_len, pinfo, wcp_tree);
if ( !next_tvb){
proto_tree_add_protocol_format(tree, proto_malformed, tvb, 0, 0,
"[Malformed Frame: Bad WCP compressed data]" );
return;
}
}
if ( tree)
proto_tree_add_uint(wcp_tree, hf_wcp_chksum, tvb,
tvb_reported_length( tvb)-1, 1,
tvb_get_guint8( tvb, tvb_reported_length(tvb)-1));
call_dissector(fr_uncompressed_handle, next_tvb, pinfo, tree);
return;
}
static guint8 *decompressed_entry( guint8 *src, guint8 *dst, int *len, guint8 * buf_start, guint8 *buf_end){
guint16 data_offset, data_cnt;
guint8 tmp = *src;
data_offset = (*(src++) & 0xf) << 8;
data_offset += *(src++);
if (( tmp & 0xf0) == 0x10){
data_cnt = *src;
data_cnt++;
}else {
data_cnt = tmp >> 4;
data_cnt++;
}
src = (dst - 1 - data_offset);
if ( src < buf_start)
src += MAX_WIN_BUF_LEN;
while( data_cnt--){
*dst = *src;
if ( ++(*len) >MAX_WCP_BUF_LEN){
printf("decomp failed, len = %d\n", *len);
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
wcp_window_t *get_wcp_window_ptr( packet_info *pinfo){
circuit_t *circuit;
wcp_circuit_data_t *wcp_circuit_data;
circuit = find_circuit( pinfo->ctype, pinfo->circuit_id,
pinfo->fd->num);
if ( !circuit){
circuit = circuit_new( pinfo->ctype, pinfo->circuit_id,
pinfo->fd->num);
}
wcp_circuit_data = circuit_get_proto_data(circuit, proto_wcp);
if ( !wcp_circuit_data){
wcp_circuit_data = se_alloc(sizeof(wcp_circuit_data_t));
wcp_circuit_data->recv.buf_cur = wcp_circuit_data->recv.buffer;
wcp_circuit_data->send.buf_cur = wcp_circuit_data->send.buffer;
circuit_add_proto_data(circuit, proto_wcp, wcp_circuit_data);
}
if (pinfo->pseudo_header->x25.flags & FROM_DCE)
return &wcp_circuit_data->recv;
else
return &wcp_circuit_data->send;
}
static tvbuff_t *wcp_uncompress( tvbuff_t *src_tvb, int offset, packet_info *pinfo, proto_tree *tree) {
proto_tree *sub_tree;
proto_item *ti;
int len=0, i = -1;
int cnt = tvb_reported_length( src_tvb)-1;
guint8 *dst, *src, *buf_start, *buf_end, comp_flag_bits = 0;
guint8 src_buf[ MAX_WCP_BUF_LEN];
tvbuff_t *volatile tvb = 0;
wcp_window_t *buf_ptr = 0;
wcp_pdata_t *volatile pdata_ptr;
volatile gboolean bounds_error = FALSE;
buf_ptr = get_wcp_window_ptr( pinfo);
buf_start = buf_ptr->buffer;
buf_end = buf_start + MAX_WIN_BUF_LEN;
if (cnt - offset > MAX_WCP_BUF_LEN) {
if (tree)
proto_tree_add_text( tree, src_tvb, offset, -1,
"Compressed data exceeds maximum buffer length (%d > %d)",
cnt - offset, MAX_WCP_BUF_LEN);
return NULL;
}
src = tvb_memcpy(src_tvb, src_buf, offset, cnt - offset);
dst = buf_ptr->buf_cur;
while( offset++ < cnt){
if ( --i >= 0){
if ( comp_flag_bits & 0x80){
if ( !pinfo->fd->flags.visited){
dst = decompressed_entry( src, dst, &len, buf_start, buf_end);
}
if ((*src & 0xf0) == 0x10){
if ( tree) {
ti = proto_tree_add_item( tree, hf_wcp_long_run, src_tvb,
offset-1, 3, ENC_NA);
sub_tree = proto_item_add_subtree(ti, ett_wcp_field);
proto_tree_add_uint(sub_tree, hf_wcp_offset, src_tvb,
offset-1, 2, pntohs(src));
proto_tree_add_item( sub_tree, hf_wcp_long_len, src_tvb,
offset+1, 1, ENC_BIG_ENDIAN);
}
src += 3;
offset += 2;
}else{
if ( tree) {
ti = proto_tree_add_item( tree, hf_wcp_short_run, src_tvb,
offset - 1, 2, ENC_NA);
sub_tree = proto_item_add_subtree(ti, ett_wcp_field);
proto_tree_add_uint( sub_tree, hf_wcp_short_len, src_tvb,
offset-1, 1, *src);
proto_tree_add_uint(sub_tree, hf_wcp_offset, src_tvb,
offset-1, 2, pntohs(src));
}
src += 2;
offset += 1;
}
}else {
if ( !pinfo->fd->flags.visited){
*dst = *src;
if ( dst++ == buf_end)
dst = buf_start;
}
++src;
++len;
}
if ( len >MAX_WCP_BUF_LEN){
return NULL;
}
comp_flag_bits <<= 1;
}else {
comp_flag_bits = *src++;
if (tree)
proto_tree_add_uint( tree, hf_wcp_comp_bits, src_tvb, offset-1, 1,
comp_flag_bits);
i = 8;
}
}
if ( pinfo->fd->flags.visited){
pdata_ptr = p_get_proto_data( pinfo->fd, proto_wcp);
if ( !pdata_ptr)
return NULL;
len = pdata_ptr->len;
} else {
pdata_ptr = se_alloc(sizeof(wcp_pdata_t));
memcpy( &pdata_ptr->buffer, buf_ptr->buf_cur, len);
pdata_ptr->len = len;
p_add_proto_data( pinfo->fd, proto_wcp, (void*)pdata_ptr);
buf_ptr->buf_cur = dst;
}
TRY {
tvb = tvb_new_child_real_data(src_tvb, pdata_ptr->buffer, pdata_ptr->len, pdata_ptr->len);
}
CATCH(BoundsError) {
DISSECTOR_ASSERT_NOT_REACHED();
}
CATCH(ReportedBoundsError) {
bounds_error = TRUE;
}
ENDTRY;
if (bounds_error) return NULL;
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
{ &hf_wcp_rexmit,
{ "Rexmit", "wcp.rexmit", FT_UINT8, BASE_DEC, NULL, 0,
"Retransmit", HFILL }},
{ &hf_wcp_hist_size,
{ "History", "wcp.hist", FT_UINT8, BASE_DEC, NULL, 0,
"History Size", HFILL }},
{ &hf_wcp_ppc,
{ "PerPackComp", "wcp.ppc", FT_UINT8, BASE_DEC, NULL, 0,
"Per Packet Compression", HFILL }},
{ &hf_wcp_pib,
{ "PIB", "wcp.pib", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_wcp_comp_bits,
{ "Compress Flag", "wcp.flag", FT_UINT8, BASE_HEX, NULL, 0,
"Compressed byte flag", HFILL }},
{ &hf_wcp_comp_marker,
{ "Compress Marker", "wcp.mark", FT_UINT8, BASE_DEC, NULL, 0,
"Compressed marker", HFILL }},
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
&ett_wcp_field,
};
proto_wcp = proto_register_protocol ("Wellfleet Compression", "WCP", "wcp");
proto_register_field_array (proto_wcp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_wcp(void) {
dissector_handle_t wcp_handle;
fr_uncompressed_handle = find_dissector("fr_uncompressed");
wcp_handle = create_dissector_handle(dissect_wcp, proto_wcp);
dissector_add_uint("fr.ietf", NLPID_COMPRESSED, wcp_handle);
dissector_add_uint("ethertype", ETHERTYPE_WCP, wcp_handle);
}
