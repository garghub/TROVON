static int
add_sdnv64_to_tree(proto_tree *tree, tvbuff_t *tvb, packet_info* pinfo, int offset, int hf_sdnv, guint64 *value, proto_item** item_ret)
{
int sdnv_status;
int sdnv_length;
guint64 sdnv_value;
proto_item* ti;
sdnv_status = evaluate_sdnv64(tvb, offset, &sdnv_length, &sdnv_value);
ti = proto_tree_add_uint64(tree, hf_sdnv, tvb, offset, sdnv_length, sdnv_value);
*value = sdnv_value;
if (NULL != *item_ret) *item_ret = ti;
if (!sdnv_status) {
expert_add_info(pinfo, ti, &ei_ltp_sdnv_length);
}
return sdnv_length;
}
static int
dissect_data_segment(proto_tree *ltp_tree, tvbuff_t *tvb,packet_info *pinfo,int frame_offset,int ltp_type, guint64 session_num)
{
guint64 client_id;
guint64 data_offset;
guint64 data_length;
guint64 chkp_sno = 0;
guint64 rpt_sno = 0;
guint64 sda_client_id = 0;
unsigned segment_size = 0;
int sdnv_length;
int sdnv_status;
proto_tree *ltp_data_tree;
proto_item *ti;
fragment_head *frag_msg = NULL;
gboolean more_frags = TRUE;
tvbuff_t *new_tvb = NULL;
ltp_data_tree = proto_tree_add_subtree(ltp_tree, tvb, frame_offset, tvb_captured_length(tvb), ett_data_segm, NULL, "Data Segment");
sdnv_status = evaluate_sdnv64(tvb, frame_offset, &sdnv_length, &client_id);
ti = proto_tree_add_uint64_format_value(ltp_data_tree, hf_ltp_data_clid, tvb, frame_offset, sdnv_length, client_id,
"%" G_GINT64_MODIFIER "u (%s)", client_id,
val_to_str_const((const guint32) client_id, client_service_id_info, "Invalid"));
if (!sdnv_status) {
expert_add_info(pinfo, ti, &ei_ltp_sdnv_length);
return 0;
}
frame_offset += sdnv_length;
segment_size += sdnv_length;
if ((sdnv_length = add_sdnv64_to_tree(ltp_data_tree, tvb, pinfo, frame_offset, hf_ltp_data_offset, &data_offset, &ti)) > 0) {
frame_offset += sdnv_length;
segment_size += sdnv_length;
} else {
return 0;
}
if ((sdnv_length = add_sdnv64_to_tree(ltp_data_tree, tvb, pinfo, frame_offset, hf_ltp_data_length, &data_length, &ti)) > 0) {
frame_offset += sdnv_length;
segment_size += sdnv_length;
segment_size += (unsigned int) data_length;
} else {
return 0;
}
more_frags = FALSE;
if (ltp_type != 0 && ltp_type < 4)
{
if ((sdnv_length = add_sdnv64_to_tree(ltp_data_tree, tvb, pinfo, frame_offset, hf_ltp_data_chkp, &chkp_sno, &ti)) > 0) {
frame_offset += sdnv_length;
segment_size += sdnv_length;
if (chkp_sno > 4294967295U) {
expert_add_info(pinfo, ti, &ei_ltp_sno_larger_than_ccsds);
}
} else {
return 0;
}
if ((sdnv_length = add_sdnv64_to_tree(ltp_data_tree, tvb, pinfo, frame_offset, hf_ltp_data_rpt, &rpt_sno, &ti)) > 0) {
frame_offset += sdnv_length;
segment_size += sdnv_length;
if (rpt_sno > 4294967295U) {
expert_add_info(pinfo, ti, &ei_ltp_sno_larger_than_ccsds);
}
} else {
return 0;
}
} else if (ltp_type != 7) {
more_frags = TRUE;
}
if (segment_size >= tvb_captured_length(tvb)) {
proto_tree_add_string(ltp_data_tree, hf_ltp_partial_packet, tvb, 0, 0, "<increase capture size?>");
return tvb_captured_length(tvb);
}
frag_msg = fragment_add_check(&ltp_reassembly_table,
tvb, frame_offset, pinfo, (guint32)session_num, NULL,
(guint32)data_offset, (guint32)data_length, more_frags);
if(frag_msg)
{
if(!(frag_msg->flags & FD_PARTIAL_REASSEMBLY))
{
if(!more_frags && data_offset == 0)
{
new_tvb = tvb_new_subset_remaining(tvb, frame_offset);
}
else
{
new_tvb = process_reassembled_data(tvb, frame_offset, pinfo, "Reassembled LTP Segment",
frag_msg, &ltp_frag_items,NULL, ltp_data_tree);
}
}
}
if(new_tvb)
{
int data_count = 1;
int parse_length;
int parse_offset = 0;
parse_length = tvb_captured_length(new_tvb);
while(parse_offset < parse_length)
{
int bundle_size;
int sda_header_size;
proto_tree *ltp_data_data_tree;
tvbuff_t *datatvb;
ltp_data_data_tree = proto_tree_add_subtree_format(ltp_data_tree, tvb,frame_offset, 0,
ett_data_data_segm, NULL, "Data[%d]",data_count);
sda_header_size = 0;
if (client_id == 2) {
sdnv_status = evaluate_sdnv64(tvb, frame_offset+parse_offset, &sdnv_length, &sda_client_id);
ti = proto_tree_add_uint64_format_value(ltp_data_data_tree, hf_ltp_data_sda_clid, tvb, frame_offset+parse_offset, sdnv_length, sda_client_id,
"%" G_GINT64_MODIFIER "u (%s)", sda_client_id, val_to_str_const((const guint32) sda_client_id, client_service_id_info, "Invalid"));
if (!sdnv_status) {
expert_add_info(pinfo, ti, &ei_ltp_sdnv_length);
return 0;
}
sda_header_size = sdnv_length;
parse_offset += sdnv_length;
if (parse_offset == parse_length) {
col_set_str(pinfo->cinfo, COL_INFO, "CCSDS LTP SDA Protocol Error");
return 0;
}
}
datatvb = tvb_new_subset_length_caplen(new_tvb, parse_offset, (int)parse_length - parse_offset, tvb_captured_length(new_tvb));
bundle_size = call_dissector(bundle_handle, datatvb, pinfo, ltp_data_data_tree);
if(bundle_size == 0) {
col_set_str(pinfo->cinfo, COL_INFO, "Dissection Failed");
return 0;
}
proto_item_set_len(ltp_data_data_tree, bundle_size+sda_header_size);
parse_offset += bundle_size;
data_count++;
}
}
else
{
if(frag_msg && more_frags)
{
col_append_fstr(pinfo->cinfo, COL_INFO, "[Reassembled in %d] ",frag_msg->reassembled_in);
}
else
{
col_append_str(pinfo->cinfo, COL_INFO, "[Unfinished LTP Segment] ");
}
}
return segment_size;
}
static int
dissect_report_segment(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ltp_tree, int frame_offset) {
guint64 rpt_sno;
guint64 chkp_sno;
guint64 upper_bound;
guint64 lower_bound;
int rcpt_clm_cnt;
guint64 offset;
guint64 length;
int rpt_sno_size;
int chkp_sno_size;
int upper_bound_size;
int lower_bound_size;
int rcpt_clm_cnt_size;
int offset_size;
int length_size;
int segment_offset = 0;
int i;
proto_item *ltp_rpt_item;
proto_item *ltp_rpt_clm_item;
proto_tree *ltp_rpt_tree;
proto_tree *ltp_rpt_clm_tree;
ltp_rpt_tree = proto_tree_add_subtree(ltp_tree, tvb, frame_offset, -1, ett_rpt_segm, &ltp_rpt_item, "Report Segment");
rpt_sno = evaluate_sdnv_64(tvb, frame_offset, &rpt_sno_size);
proto_tree_add_uint64(ltp_rpt_tree, hf_ltp_rpt_sno, tvb, frame_offset + segment_offset, rpt_sno_size, rpt_sno);
segment_offset += rpt_sno_size;
chkp_sno = evaluate_sdnv_64(tvb, frame_offset + segment_offset, &chkp_sno_size);
proto_tree_add_uint64(ltp_rpt_tree, hf_ltp_rpt_chkp, tvb, frame_offset + segment_offset, chkp_sno_size, chkp_sno);
segment_offset += chkp_sno_size;
upper_bound = evaluate_sdnv(tvb, frame_offset + segment_offset, &upper_bound_size);
proto_tree_add_uint64(ltp_rpt_tree, hf_ltp_rpt_ub, tvb, frame_offset + segment_offset, upper_bound_size, upper_bound);
segment_offset += upper_bound_size;
lower_bound = evaluate_sdnv(tvb, frame_offset + segment_offset, &lower_bound_size);
proto_tree_add_uint64(ltp_rpt_tree, hf_ltp_rpt_lb, tvb, frame_offset + segment_offset, lower_bound_size, lower_bound);
segment_offset += lower_bound_size;
rcpt_clm_cnt = evaluate_sdnv(tvb, frame_offset + segment_offset, &rcpt_clm_cnt_size);
if (rcpt_clm_cnt < 0){
proto_item_set_end(ltp_rpt_item, tvb, frame_offset + segment_offset);
expert_add_info_format(pinfo, ltp_tree, &ei_ltp_neg_reception_claim_count,
"Negative reception claim count: %d", rcpt_clm_cnt);
return 0;
}
if (rcpt_clm_cnt > tvb_captured_length_remaining(tvb, frame_offset + segment_offset) / 2) {
proto_item_set_end(ltp_rpt_item, tvb, frame_offset + segment_offset);
expert_add_info_format(pinfo, ltp_tree, &ei_ltp_mal_reception_claim,
"Reception claim count impossibly large: %d > %d", rcpt_clm_cnt,
tvb_captured_length_remaining(tvb, frame_offset + segment_offset) / 2);
return 0;
}
proto_tree_add_uint(ltp_rpt_tree, hf_ltp_rpt_clm_cnt, tvb, frame_offset + segment_offset, rcpt_clm_cnt_size, rcpt_clm_cnt);
segment_offset += rcpt_clm_cnt_size;
ltp_rpt_clm_tree = proto_tree_add_subtree(ltp_rpt_tree, tvb, frame_offset + segment_offset, -1, ett_rpt_clm, &ltp_rpt_clm_item, "Reception claims");
for(i = 0; i<rcpt_clm_cnt; i++){
offset = evaluate_sdnv(tvb,frame_offset + segment_offset, &offset_size);
proto_tree_add_uint64_format(ltp_rpt_clm_tree, hf_ltp_rpt_clm_off, tvb, frame_offset + segment_offset, offset_size, offset,
"Offset[%d] : %"G_GINT64_MODIFIER"d", i, offset);
segment_offset += offset_size;
length = evaluate_sdnv(tvb,frame_offset + segment_offset, &length_size);
proto_tree_add_uint64_format(ltp_rpt_clm_tree, hf_ltp_rpt_clm_len, tvb, frame_offset + segment_offset, length_size, length,
"Length[%d] : %"G_GINT64_MODIFIER"d",i, length);
segment_offset += length_size;
}
proto_item_set_end(ltp_rpt_clm_item, tvb, frame_offset + segment_offset);
proto_item_set_end(ltp_rpt_item, tvb, frame_offset + segment_offset);
return segment_offset;
}
static int
dissect_report_ack_segment(proto_tree *ltp_tree, tvbuff_t *tvb,int frame_offset){
guint64 rpt_sno;
int rpt_sno_size;
int segment_offset = 0;
proto_tree *ltp_rpt_ack_tree;
rpt_sno = evaluate_sdnv_64(tvb,frame_offset, &rpt_sno_size);
segment_offset += rpt_sno_size;
if((unsigned)(frame_offset + segment_offset) > tvb_captured_length(tvb)){
return 0;
}
ltp_rpt_ack_tree = proto_tree_add_subtree(ltp_tree, tvb,frame_offset, segment_offset,
ett_rpt_ack_segm, NULL, "Report Ack Segment");
proto_tree_add_uint64(ltp_rpt_ack_tree, hf_ltp_rpt_ack_sno, tvb, frame_offset,rpt_sno_size, rpt_sno);
return segment_offset;
}
static int
dissect_cancel_segment(proto_tree * ltp_tree, tvbuff_t *tvb,int frame_offset){
guint8 reason_code;
proto_tree *ltp_cancel_tree;
reason_code = tvb_get_guint8(tvb,frame_offset);
ltp_cancel_tree = proto_tree_add_subtree(ltp_tree, tvb,frame_offset, 1, ett_session_mgmt, NULL, "Cancel Segment");
proto_tree_add_uint_format_value(ltp_cancel_tree, hf_ltp_cancel_code, tvb, frame_offset, 1, reason_code,
"%x (%s)", reason_code, val_to_str_const(reason_code,ltp_cancel_codes,"Reserved"));
return 1;
}
static int
dissect_header_extn(proto_tree *ltp_tree, tvbuff_t *tvb,int frame_offset,int hdr_extn_cnt){
guint8 extn_type[LTP_MAX_HDR_EXTN];
guint64 length[LTP_MAX_HDR_EXTN];
guint64 value[LTP_MAX_HDR_EXTN];
int length_size[LTP_MAX_HDR_EXTN];
int value_size[LTP_MAX_HDR_EXTN];
int i;
int extn_offset = 0;
proto_tree *ltp_hdr_extn_tree;
for(i = 0; i < hdr_extn_cnt; i++){
extn_type[i] = tvb_get_guint8(tvb,frame_offset);
extn_offset++;
if((unsigned)(frame_offset + extn_offset) >= tvb_captured_length(tvb)){
return 0;
}
length[i] = evaluate_sdnv_64(tvb,frame_offset,&length_size[i]);
extn_offset += length_size[i];
if((unsigned)(frame_offset + extn_offset) >= tvb_captured_length(tvb)){
return 0;
}
value[i] = evaluate_sdnv_64(tvb,frame_offset,&value_size[i]);
extn_offset += value_size[i];
if((unsigned)(frame_offset + extn_offset) >= tvb_captured_length(tvb)){
return 0;
}
}
ltp_hdr_extn_tree = proto_tree_add_subtree(ltp_tree, tvb,frame_offset, extn_offset, ett_hdr_extn, NULL, "Header Extension");
for(i = 0; i < hdr_extn_cnt; i++){
proto_tree_add_uint_format_value(ltp_hdr_extn_tree, hf_ltp_hdr_extn_tag, tvb, frame_offset, 1, extn_type[i], "%x (%s)", extn_type[i], val_to_str_const(extn_type[i],extn_tag_codes,"Unassigned/Reserved"));
proto_tree_add_uint64_format(ltp_hdr_extn_tree, hf_ltp_hdr_extn_len, tvb, frame_offset, length_size[i],length[i], "Length [%d]: %"G_GINT64_MODIFIER"d",i+1,length[i]);
frame_offset += length_size[i];
proto_tree_add_uint64_format(ltp_hdr_extn_tree, hf_ltp_hdr_extn_val, tvb, frame_offset, value_size[i],value[i], "Value [%d]: %"G_GINT64_MODIFIER"d",i+1,value[i]);
frame_offset += value_size[i];
}
return extn_offset;
}
static int
dissect_trailer_extn(proto_tree *ltp_tree, tvbuff_t *tvb,int frame_offset,int trl_extn_cnt){
guint8 extn_type[LTP_MAX_TRL_EXTN];
guint64 length[LTP_MAX_TRL_EXTN];
guint64 value[LTP_MAX_TRL_EXTN];
int length_size[LTP_MAX_TRL_EXTN];
int value_size[LTP_MAX_TRL_EXTN];
int i;
int extn_offset = 0;
proto_tree *ltp_trl_extn_tree;
DISSECTOR_ASSERT(trl_extn_cnt < LTP_MAX_TRL_EXTN);
for(i = 0; i < trl_extn_cnt; i++){
extn_type[i] = tvb_get_guint8(tvb,frame_offset);
extn_offset++;
if((unsigned)(frame_offset + extn_offset) >= tvb_captured_length(tvb)){
return 0;
}
length[i] = evaluate_sdnv_64(tvb,frame_offset,&length_size[i]);
extn_offset += length_size[i];
if((unsigned)(frame_offset + extn_offset) >= tvb_captured_length(tvb)){
return 0;
}
value[i] = evaluate_sdnv_64(tvb,frame_offset,&value_size[i]);
extn_offset += value_size[i];
if((unsigned)(frame_offset + extn_offset) >= tvb_captured_length(tvb)){
return 0;
}
}
ltp_trl_extn_tree = proto_tree_add_subtree(ltp_tree, tvb,frame_offset, extn_offset, ett_trl_extn, NULL, "Header Extension");
for(i = 0; i < trl_extn_cnt; i++){
proto_tree_add_uint_format_value(ltp_trl_extn_tree, hf_ltp_trl_extn_tag, tvb, frame_offset, 1, extn_type[i], "%x (%s)", extn_type[i], val_to_str_const(extn_type[i],extn_tag_codes,"Unassigned/Reserved"));
proto_tree_add_uint64_format(ltp_trl_extn_tree, hf_ltp_trl_extn_len, tvb, frame_offset, length_size[i], length[i], "Length [%d]: %"G_GINT64_MODIFIER"d",i+1,length[i]);
frame_offset += length_size[i];
proto_tree_add_uint64_format(ltp_trl_extn_tree, hf_ltp_trl_extn_val, tvb, frame_offset, value_size[i], value[i], "Value [%d]: %"G_GINT64_MODIFIER"d",i+0,value[i]);
frame_offset += value_size[i];
}
return extn_offset;
}
static int
dissect_ltp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti = NULL;
proto_tree *ltp_tree = NULL;
int frame_offset;
int header_offset;
int segment_offset = 0;
guint8 ltp_hdr;
gint ltp_type;
guint8 ltp_extn_cnt;
gint hdr_extn_cnt;
gint trl_extn_cnt;
guint64 engine_id;
guint64 session_num;
int engine_id_size;
int session_num_size;
proto_tree *ltp_header_tree = NULL;
proto_tree *ltp_session_tree = NULL;
if(tvb_captured_length(tvb) < LTP_MIN_DATA_BUFFER){
return 0;
}
frame_offset = 0;
header_offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LTP Segment");
ltp_hdr = tvb_get_guint8(tvb, frame_offset);
header_offset++;
engine_id = evaluate_sdnv_64(tvb,frame_offset + header_offset,&engine_id_size);
header_offset += engine_id_size;
if((unsigned)header_offset >= tvb_captured_length(tvb)){
col_set_str(pinfo->cinfo, COL_INFO, "Protocol Error");
return 0;
}
session_num = evaluate_sdnv_64(tvb,frame_offset + header_offset,&session_num_size);
header_offset += session_num_size;
if((unsigned)header_offset >= tvb_captured_length(tvb)){
col_set_str(pinfo->cinfo, COL_INFO, "Protocol Error");
return 0;
}
ti = proto_tree_add_item(tree, proto_ltp, tvb, 0, -1, ENC_NA);
ltp_tree = proto_item_add_subtree(ti, ett_ltp);
ltp_header_tree = proto_tree_add_subtree(ltp_tree, tvb, frame_offset, header_offset+1, ett_ltp_hdr, NULL, "LTP Header");
proto_tree_add_uint(ltp_header_tree,hf_ltp_version,tvb,frame_offset,1,hi_nibble(ltp_hdr));
ltp_type = lo_nibble(ltp_hdr);
proto_tree_add_uint_format_value(ltp_header_tree,hf_ltp_type,tvb,frame_offset,1,ltp_type,"%x (%s)",
ltp_type,val_to_str_const(ltp_type,ltp_type_codes,"Invalid"));
frame_offset++;
ltp_session_tree = proto_tree_add_subtree(ltp_header_tree, tvb, frame_offset, header_offset+1, ett_hdr_session, NULL, "Session ID");
proto_tree_add_uint64(ltp_session_tree,hf_ltp_session_orig,tvb,frame_offset,engine_id_size,engine_id);
frame_offset+=engine_id_size;
proto_tree_add_uint64(ltp_session_tree,hf_ltp_session_no, tvb, frame_offset,session_num_size,session_num);
frame_offset+=session_num_size;
ltp_extn_cnt = tvb_get_guint8(tvb,frame_offset);
hdr_extn_cnt = hi_nibble(ltp_extn_cnt);
trl_extn_cnt = lo_nibble(ltp_extn_cnt);
proto_tree_add_uint(ltp_header_tree,hf_ltp_hdr_extn_cnt,tvb,frame_offset,1,hdr_extn_cnt);
proto_tree_add_uint(ltp_header_tree,hf_ltp_trl_extn_cnt,tvb,frame_offset,1,trl_extn_cnt);
frame_offset++;
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const(ltp_type,ltp_type_col_info,"Protocol Error"));
if(hdr_extn_cnt > 0){
int hdr_extn_offset;
if((unsigned)frame_offset >= tvb_captured_length(tvb)){
col_set_str(pinfo->cinfo, COL_INFO, "Protocol Error");
return 0;
}
hdr_extn_offset = dissect_header_extn(ltp_tree, tvb, frame_offset,hdr_extn_cnt);
if(hdr_extn_offset == 0){
col_set_str(pinfo->cinfo, COL_INFO, "Protocol Error");
return 0;
}
frame_offset += hdr_extn_offset;
}
if((unsigned)frame_offset > tvb_captured_length(tvb)){
col_set_str(pinfo->cinfo, COL_INFO, "Protocol Error");
return 0;
}
else if((unsigned)frame_offset == tvb_captured_length(tvb)){
if(ltp_type != 13 && ltp_type != 15){
col_set_str(pinfo->cinfo, COL_INFO, "Protocol Error");
return 0;
}
}
if((ltp_type >= 0) && (ltp_type < 8)){
segment_offset = dissect_data_segment(ltp_tree,tvb,pinfo,frame_offset,ltp_type,session_num);
if(segment_offset == 0){
col_set_str(pinfo->cinfo, COL_INFO, "Protocol Error");
return 0;
}
}
else if(ltp_type == 8){
segment_offset = dissect_report_segment(tvb, pinfo, ltp_tree,frame_offset);
if(segment_offset == 0){
col_set_str(pinfo->cinfo, COL_INFO, "Protocol Error");
return 0;
}
}
else if(ltp_type == 9){
segment_offset = dissect_report_ack_segment(ltp_tree,tvb,frame_offset);
if(segment_offset == 0){
col_set_str(pinfo->cinfo, COL_INFO, "Protocol Error");
return 0;
}
}
else if(ltp_type == 12 || ltp_type == 14){
segment_offset = dissect_cancel_segment(ltp_tree,tvb,frame_offset);
if(segment_offset == 0){
col_set_str(pinfo->cinfo, COL_INFO, "Protocol Error");
return 0;
}
}
else if(ltp_type == 13 || ltp_type == 15){
proto_tree_add_string(ltp_tree, hf_ltp_cancel_ack, tvb, 0, 0, "(No Data)");
}
frame_offset += segment_offset;
if(trl_extn_cnt > 0){
if((unsigned)frame_offset >= tvb_captured_length(tvb)){
col_set_str(pinfo->cinfo, COL_INFO, "Protocol Error");
return 0;
}
if(0 == dissect_trailer_extn(ltp_tree, tvb, frame_offset,trl_extn_cnt)) {
col_set_str(pinfo->cinfo, COL_INFO, "Protocol Error");
return 0;
}
}
return tvb_captured_length(tvb);
}
void
proto_register_ltp(void)
{
static hf_register_info hf[] = {
{&hf_ltp_version,
{"LTP Version","ltp.version",
FT_UINT8,BASE_DEC,NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_type,
{"LTP Type","ltp.type",
FT_UINT8,BASE_HEX,NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_session_orig,
{"Session originator","ltp.session.orig",
FT_UINT64,BASE_DEC,NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_session_no,
{"Session number","ltp.session.number",
FT_UINT64,BASE_DEC,NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_hdr_extn_cnt,
{"Header Extension Count","ltp.hdr.extn.cnt",
FT_UINT8,BASE_DEC,NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_trl_extn_cnt,
{"Trailer Extension Count","ltp.trl.extn.cnt",
FT_UINT8,BASE_DEC,NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_data_clid,
{"Client service ID","ltp.data.client.id",
FT_UINT64,BASE_DEC,NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_data_offset,
{"Offset","ltp.data.offset",
FT_UINT64,BASE_DEC,NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_data_length,
{"Length","ltp.data.length",
FT_UINT64,BASE_DEC,NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_data_chkp,
{"Checkpoint serial number","ltp.data.chkp",
FT_UINT64,BASE_DEC,NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_data_rpt,
{"Report serial number","ltp.data.rpt",
FT_UINT64,BASE_DEC,NULL, 0x0, NULL, HFILL}
},
#if 0
{&hf_ltp_data_clidata,
{"Client service data","ltp.data.data",
FT_BYTES,BASE_NONE,NULL, 0x0, NULL, HFILL}
},
#endif
{&hf_ltp_rpt_sno,
{"Report serial number","ltp.rpt.sno",
FT_UINT64,BASE_DEC,NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_rpt_chkp,
{"Checkpoint serial number","ltp.rpt.chkp",
FT_UINT64,BASE_DEC,NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_rpt_ub,
{"Upper bound","ltp.rpt.ub",
FT_UINT64,BASE_DEC,NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_rpt_lb,
{"Lower bound","ltp.rpt.lb",
FT_UINT64,BASE_DEC,NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_rpt_clm_cnt,
{"Reception claim count","ltp.rpt.clm.cnt",
FT_UINT8,BASE_DEC,NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_rpt_clm_off,
{"Offset","ltp.rpt.clm.off",
FT_UINT64,BASE_DEC,NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_rpt_clm_len,
{"Length","ltp.rpt.clm.len",
FT_UINT64,BASE_DEC,NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_rpt_ack_sno,
{"Report serial number","ltp.rpt.ack.sno",
FT_UINT64,BASE_DEC,NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_cancel_code,
{"Cancel code","ltp.cancel.code",
FT_UINT8,BASE_HEX,NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_hdr_extn_tag,
{"Extension tag","ltp.hdr.extn.tag",
FT_UINT8,BASE_HEX,NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_hdr_extn_len,
{"Length","ltp.hdr.extn.len",
FT_UINT64,BASE_DEC,NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_hdr_extn_val,
{"Value","ltp.hdr.extn.val",
FT_UINT64,BASE_DEC,NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_trl_extn_tag,
{"Extension tag","ltp.trl.extn.tag",
FT_UINT8,BASE_HEX,NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_trl_extn_len,
{"Length","ltp.trl.extn.len",
FT_UINT64,BASE_DEC,NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_trl_extn_val,
{"Value","ltp.trl.extn.val",
FT_UINT64,BASE_DEC,NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_fragments,
{"LTP Fragments", "ltp.fragments",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_fragment,
{"LTP Fragment", "ltp.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_fragment_overlap,
{"LTP fragment overlap", "ltp.fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_fragment_overlap_conflicts,
{"LTP fragment overlapping with conflicting data",
"ltp.fragment.overlap.conflicts",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_fragment_multiple_tails,
{"LTP has multiple tails", "ltp.fragment.multiple_tails",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_fragment_too_long_fragment,
{"LTP fragment too long", "ltp.fragment.too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_fragment_error,
{"LTP defragmentation error", "ltp.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_fragment_count,
{"LTP fragment count", "ltp.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_reassembled_in,
{"LTP reassembled in", "ltp.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_reassembled_length,
{"LTP reassembled length", "ltp.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_data_sda_clid,
{"Client service ID", "ltp.data.sda.client.id",
FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_partial_packet,
{"<partial packet>", "ltp.partial_packet",
FT_STRINGZPAD, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_ltp_cancel_ack,
{"<Cancel Ack>", "ltp.cancel_ack",
FT_STRINGZPAD, BASE_NONE, NULL, 0x0, NULL, HFILL}
}
};
static gint *ett[] = {
&ett_ltp,
&ett_ltp_hdr,
&ett_hdr_session,
&ett_hdr_extn,
&ett_data_segm,
&ett_data_data_segm,
&ett_rpt_segm,
&ett_rpt_clm,
&ett_rpt_ack_segm,
&ett_session_mgmt,
&ett_trl_extn,
&ett_ltp_fragment,
&ett_ltp_fragments
};
static ei_register_info ei[] = {
{ &ei_ltp_neg_reception_claim_count, { "ltp.neg_reception_claim_count", PI_UNDECODED, PI_ERROR, "Negative reception claim count", EXPFILL }},
{ &ei_ltp_mal_reception_claim, { "ltp.mal_reception_claim", PI_MALFORMED, PI_ERROR, "Reception claim count impossibly large", EXPFILL }},
{ &ei_ltp_sdnv_length, { "ltp.sdnv_length_invalid", PI_PROTOCOL, PI_ERROR, "SDNV length error", EXPFILL }},
{ &ei_ltp_sno_larger_than_ccsds, { "ltp.serial_number_too_large", PI_PROTOCOL, PI_WARN, "Serial number larger than CCSDS specification", EXPFILL }}
};
expert_module_t* expert_ltp;
proto_ltp = proto_register_protocol("Licklider Transmission Protocol", "LTP", "ltp");
proto_register_field_array(proto_ltp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_ltp = expert_register_protocol(proto_ltp);
expert_register_field_array(expert_ltp, ei, array_length(ei));
reassembly_table_register(&ltp_reassembly_table,
&addresses_reassembly_table_functions);
}
void
proto_reg_handoff_ltp(void)
{
dissector_handle_t ltp_handle;
ltp_handle = create_dissector_handle(dissect_ltp, proto_ltp);
bundle_handle = find_dissector_add_dependency("bundle", proto_ltp);
dissector_add_uint_with_preference("udp.port", LTP_PORT, ltp_handle);
dissector_add_uint_with_preference("dccp.port", LTP_PORT, ltp_handle);
}
