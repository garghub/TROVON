static void t38_defragment_init(void)
{
reassembly_table_init(&data_reassembly_table,
&addresses_reassembly_table_functions);
}
void t38_add_address(packet_info *pinfo,
address *addr, int port,
int other_port,
const gchar *setup_method, guint32 setup_frame_number)
{
address null_addr;
conversation_t* p_conversation;
t38_conv* p_conversation_data = NULL;
if (pinfo->fd->flags.visited)
{
return;
}
SET_ADDRESS(&null_addr, AT_NONE, 0, NULL);
p_conversation = find_conversation( setup_frame_number, addr, &null_addr, PT_UDP, port, other_port,
NO_ADDR_B | (!other_port ? NO_PORT_B : 0));
if ( !p_conversation || p_conversation->setup_frame != setup_frame_number) {
p_conversation = conversation_new( setup_frame_number, addr, &null_addr, PT_UDP,
(guint32)port, (guint32)other_port,
NO_ADDR2 | (!other_port ? NO_PORT2 : 0));
}
conversation_set_dissector(p_conversation, t38_udp_handle);
p_conversation_data = (t38_conv*)conversation_get_proto_data(p_conversation, proto_t38);
if ( ! p_conversation_data ) {
p_conversation_data = se_new(t38_conv);
conversation_add_proto_data(p_conversation, proto_t38, p_conversation_data);
}
g_strlcpy(p_conversation_data->setup_method, setup_method, MAX_T38_SETUP_METHOD_SIZE);
p_conversation_data->setup_frame_number = setup_frame_number;
p_conversation_data->src_t38_info.reass_ID = 0;
p_conversation_data->src_t38_info.reass_start_seqnum = -1;
p_conversation_data->src_t38_info.reass_data_type = 0;
p_conversation_data->src_t38_info.last_seqnum = -1;
p_conversation_data->src_t38_info.packet_lost = 0;
p_conversation_data->src_t38_info.burst_lost = 0;
p_conversation_data->src_t38_info.time_first_t4_data = 0;
p_conversation_data->dst_t38_info.reass_ID = 0;
p_conversation_data->dst_t38_info.reass_start_seqnum = -1;
p_conversation_data->dst_t38_info.reass_data_type = 0;
p_conversation_data->dst_t38_info.last_seqnum = -1;
p_conversation_data->dst_t38_info.packet_lost = 0;
p_conversation_data->dst_t38_info.burst_lost = 0;
p_conversation_data->dst_t38_info.time_first_t4_data = 0;
}
fragment_data *
force_reassemble_seq(reassembly_table *table, packet_info *pinfo, guint32 id)
{
fragment_data *fd_head;
fragment_data *fd_i;
fragment_data *last_fd;
guint32 dfpos, size, packet_lost, burst_lost, seq_num;
fd_head = fragment_get(table, pinfo, id, NULL);
if (pinfo->fd->flags.visited) {
if (fd_head != NULL && fd_head->flags & FD_DEFRAGMENTED) {
return fd_head;
} else {
return NULL;
}
}
if (fd_head==NULL){
return NULL;
}
packet_lost = 0;
burst_lost = 0;
seq_num = 0;
for(fd_i=fd_head->next;fd_i;fd_i=fd_i->next) {
if (seq_num != fd_i->offset) {
packet_lost += fd_i->offset - seq_num;
if ( (fd_i->offset - seq_num) > burst_lost ) {
burst_lost = fd_i->offset - seq_num;
}
}
seq_num = fd_i->offset + 1;
}
size=0;
last_fd=NULL;
for(fd_i=fd_head->next;fd_i;fd_i=fd_i->next) {
if(!last_fd || last_fd->offset!=fd_i->offset){
size+=fd_i->len;
}
last_fd=fd_i;
}
fd_head->data = (char *)g_malloc(size);
fd_head->len = size;
dfpos = 0;
last_fd=NULL;
for (fd_i=fd_head->next;fd_i && fd_i->len + dfpos <= size;fd_i=fd_i->next) {
if (fd_i->len) {
if(!last_fd || last_fd->offset!=fd_i->offset){
memcpy(fd_head->data+dfpos,fd_i->data,fd_i->len);
dfpos += fd_i->len;
} else {
fd_i->flags |= FD_OVERLAP;
fd_head->flags |= FD_OVERLAP;
if( (last_fd->len!=fd_i->datalen)
|| memcmp(last_fd->data, fd_i->data, last_fd->len) ){
fd_i->flags |= FD_OVERLAPCONFLICT;
fd_head->flags |= FD_OVERLAPCONFLICT;
}
}
}
last_fd=fd_i;
}
for (fd_i=fd_head->next;fd_i;fd_i=fd_i->next) {
if(fd_i->data){
g_free(fd_i->data);
fd_i->data=NULL;
}
}
fd_head->flags |= FD_DEFRAGMENTED;
fd_head->reassembled_in=pinfo->fd->num;
col_append_fstr(pinfo->cinfo, COL_INFO, " (t4-data Reassembled: %d pack lost, %d pack burst lost)", packet_lost, burst_lost);
p_t38_packet_conv_info->packet_lost = packet_lost;
p_t38_packet_conv_info->burst_lost = burst_lost;
return fd_head;
}
static int
dissect_t38_T30_indicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
16, &T30ind_value, TRUE, 7, NULL);
#line 31 "../../asn1/t38/t38.cnf"
if (primary_part){
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " t30ind: %s",
val_to_str(T30ind_value,t38_T30_indicator_vals,"<unknown>"));
}
if (primary_part)
t38_info->t30ind_value = T30ind_value;
return offset;
}
static int
dissect_t38_T30_data(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
9, &Data_value, TRUE, 6, NULL);
#line 43 "../../asn1/t38/t38.cnf"
if (primary_part){
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " data:%s:",
val_to_str(Data_value,t38_T30_data_vals,"<unknown>"));
}
if (primary_part)
t38_info->data_value = Data_value;
return offset;
}
static int
dissect_t38_Type_of_msg(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_t38_Type_of_msg, Type_of_msg_choice,
&Type_of_msg_value);
#line 24 "../../asn1/t38/t38.cnf"
if (primary_part)
t38_info->type_msg = Type_of_msg_value;
return offset;
}
static int
dissect_t38_T_field_type(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, &Data_Field_field_type_value, (use_pre_corrigendum_asn1_specification)?FALSE:TRUE, (use_pre_corrigendum_asn1_specification)?0:4, NULL);
#line 63 "../../asn1/t38/t38.cnf"
if (primary_part){
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " %s",
val_to_str(Data_Field_field_type_value,t38_T_field_type_vals,"<unknown>"));
}
if (primary_part && (Data_Field_item_num<2)) {
if (Data_Field_field_type_value == 2 || Data_Field_field_type_value == 4 || Data_Field_field_type_value == 7) {
fragment_data *frag_msg = NULL;
tvbuff_t* new_tvb = NULL;
gboolean save_fragmented = actx->pinfo->fragmented;
actx->pinfo->fragmented = TRUE;
if (p_t38_packet_conv_info->reass_start_seqnum != -1) {
frag_msg = fragment_add_seq(&data_reassembly_table,
tvb, offset, actx->pinfo,
p_t38_packet_conv_info->reass_ID,
NULL,
seq_number + Data_Field_item_num - (guint32)p_t38_packet_conv_info->reass_start_seqnum + (guint32)p_t38_packet_conv_info->additional_hdlc_data_field_counter,
0,
FALSE,
0);
if ( Data_Field_field_type_value == 7 ) {
if (!frag_msg) {
force_reassemble_seq(&data_reassembly_table,
actx->pinfo,
p_t38_packet_conv_info->reass_ID
);
} else {
col_append_str(actx->pinfo->cinfo, COL_INFO, " (t4-data Reassembled: No packet lost)");
g_snprintf(t38_info->desc_comment, MAX_T38_DESC, "No packet lost");
}
if (p_t38_packet_conv_info->packet_lost) {
g_snprintf(t38_info->desc_comment, MAX_T38_DESC, " Pack lost: %d, Pack burst lost: %d", p_t38_packet_conv_info->packet_lost, p_t38_packet_conv_info->burst_lost);
} else {
g_snprintf(t38_info->desc_comment, MAX_T38_DESC, "No packet lost");
}
process_reassembled_data(tvb, offset, actx->pinfo,
"Reassembled T38", frag_msg, &data_frag_items, NULL, tree);
actx->pinfo->fragmented = save_fragmented;
t38_info->time_first_t4_data = p_t38_packet_conv_info->time_first_t4_data;
t38_info->frame_num_first_t4_data = p_t38_packet_conv_info->reass_ID;
} else {
new_tvb = process_reassembled_data(tvb, offset, actx->pinfo,
"Reassembled T38", frag_msg, &data_frag_items, NULL, tree);
actx->pinfo->fragmented = save_fragmented;
actx->pinfo->private_data = t38_info;
if (new_tvb) call_dissector((t30_hdlc_handle) ? t30_hdlc_handle : data_handle, new_tvb, actx->pinfo, tree);
}
} else {
if(tree){
proto_tree_add_text(tree, tvb, offset, tvb_reported_length_remaining(tvb, offset),
"[RECEIVED END OF FRAGMENT W/OUT ANY FRAGMENT DATA]");
}
col_append_str(actx->pinfo->cinfo, COL_INFO, " [Malformed?]");
actx->pinfo->fragmented = save_fragmented;
}
}
if ( p_t38_conv && ( ((Data_Field_field_type_value >0) && (Data_Field_field_type_value <6)) || (Data_Field_field_type_value == 7) ) ){
p_t38_conv_info->reass_ID = 0;
p_t38_conv_info->reass_start_seqnum = -1;
p_t38_conv_info->additional_hdlc_data_field_counter = 0;
p_t38_conv_info->seqnum_prev_data_field = -1;
}
t38_info->Data_Field_field_type_value = Data_Field_field_type_value;
}
return offset;
}
static int
dissect_t38_T_field_data(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 156 "../../asn1/t38/t38.cnf"
tvbuff_t *value_tvb = NULL;
guint32 value_len;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 65535, FALSE, &value_tvb);
value_len = tvb_length(value_tvb);
#line 163 "../../asn1/t38/t38.cnf"
if (primary_part){
if(value_len < 8){
col_append_fstr(actx->pinfo->cinfo, COL_INFO, "[%s]",
tvb_bytes_to_str(value_tvb,0,value_len));
}
else {
col_append_fstr(actx->pinfo->cinfo, COL_INFO, "[%s...]",
tvb_bytes_to_str(value_tvb,0,7));
}
}
if (primary_part && (Data_Field_item_num<2)) {
fragment_data *frag_msg = NULL;
if (Data_Field_field_type_value == 0 || Data_Field_field_type_value == 6) {
gboolean save_fragmented = actx->pinfo->fragmented;
actx->pinfo->fragmented = TRUE;
if (p_t38_packet_conv && p_t38_conv && (p_t38_packet_conv_info->reass_ID == 0)) {
p_t38_conv_info->reass_ID = actx->pinfo->fd->num;
p_t38_conv_info->reass_start_seqnum = seq_number;
p_t38_conv_info->time_first_t4_data = nstime_to_sec(&actx->pinfo->fd->rel_ts);
p_t38_conv_info->additional_hdlc_data_field_counter = 0;
p_t38_packet_conv_info->reass_ID = p_t38_conv_info->reass_ID;
p_t38_packet_conv_info->reass_start_seqnum = p_t38_conv_info->reass_start_seqnum;
p_t38_packet_conv_info->seqnum_prev_data_field = p_t38_conv_info->seqnum_prev_data_field;
p_t38_packet_conv_info->additional_hdlc_data_field_counter = p_t38_conv_info->additional_hdlc_data_field_counter;
p_t38_packet_conv_info->time_first_t4_data = p_t38_conv_info->time_first_t4_data;
}
if (seq_number == (guint32)p_t38_packet_conv_info->seqnum_prev_data_field){
p_t38_packet_conv_info->additional_hdlc_data_field_counter ++;
if(p_t38_conv){
p_t38_conv_info->additional_hdlc_data_field_counter = p_t38_packet_conv_info->additional_hdlc_data_field_counter;
}
}
frag_msg = fragment_add_seq(&data_reassembly_table,
value_tvb, 0,
actx->pinfo,
p_t38_packet_conv_info->reass_ID,
NULL,
seq_number - (guint32)p_t38_packet_conv_info->reass_start_seqnum + (guint32)p_t38_packet_conv_info->additional_hdlc_data_field_counter,
value_len,
TRUE,
0);
p_t38_packet_conv_info->seqnum_prev_data_field = (gint32)seq_number;
process_reassembled_data(tvb, offset, actx->pinfo,
"Reassembled T38", frag_msg, &data_frag_items, NULL, tree);
if (!frag_msg) {
if (Data_Field_field_type_value == 0) {
col_append_fstr(actx->pinfo->cinfo, COL_INFO," (HDLC fragment %u)",
seq_number + (guint32)p_t38_packet_conv_info->additional_hdlc_data_field_counter
- (guint32)p_t38_packet_conv_info->reass_start_seqnum);
} else {
col_append_fstr(actx->pinfo->cinfo, COL_INFO," (t4-data fragment %u)", seq_number - (guint32)p_t38_packet_conv_info->reass_start_seqnum);
}
}
actx->pinfo->fragmented = save_fragmented;
}
}
return offset;
}
static int
dissect_t38_Data_Field_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t38_Data_Field_item, Data_Field_item_sequence);
#line 55 "../../asn1/t38/t38.cnf"
if (primary_part) Data_Field_item_num++;
return offset;
}
static int
dissect_t38_Data_Field(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_t38_Data_Field, Data_Field_sequence_of);
return offset;
}
static int
dissect_t38_IFPPacket(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t38_IFPPacket, IFPPacket_sequence);
return offset;
}
static int
dissect_t38_T_seq_number(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, &seq_number, FALSE);
#line 243 "../../asn1/t38/t38.cnf"
if (primary_part)
t38_info->seq_num = seq_number;
col_append_fstr(actx->pinfo->cinfo, COL_INFO, "Seq=%05u ",seq_number);
return offset;
}
static int
dissect_t38_T_primary_ifp_packet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 251 "../../asn1/t38/t38.cnf"
primary_part = TRUE;
offset = dissect_per_open_type(tvb, offset, actx, tree, hf_index, dissect_t38_IFPPacket);
#line 253 "../../asn1/t38/t38.cnf"
if (p_t38_packet_conv && (!actx->pinfo->flags.in_error_pkt) && ((gint32) seq_number != p_t38_packet_conv_info->last_seqnum))
tap_queue_packet(t38_tap, actx->pinfo, t38_info);
if (p_t38_conv) p_t38_conv_info->last_seqnum = (gint32) seq_number;
return offset;
}
static int
dissect_t38_OpenType_IFPPacket(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type(tvb, offset, actx, tree, hf_index, dissect_t38_IFPPacket);
return offset;
}
static int
dissect_t38_T_secondary_ifp_packets(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_t38_T_secondary_ifp_packets, T_secondary_ifp_packets_sequence_of);
return offset;
}
static int
dissect_t38_INTEGER(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_integer(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_t38_OCTET_STRING(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_t38_T_fec_data(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_t38_T_fec_data, T_fec_data_sequence_of);
return offset;
}
static int
dissect_t38_T_fec_info(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t38_T_fec_info, T_fec_info_sequence);
return offset;
}
static int
dissect_t38_T_error_recovery(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 261 "../../asn1/t38/t38.cnf"
primary_part = FALSE;
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_t38_T_error_recovery, T_error_recovery_choice,
NULL);
#line 263 "../../asn1/t38/t38.cnf"
primary_part = TRUE;
return offset;
}
static int
dissect_t38_UDPTLPacket(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 237 "../../asn1/t38/t38.cnf"
Data_Field_field_type_value = 1;
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_t38_UDPTLPacket, UDPTLPacket_sequence);
return offset;
}
static int dissect_IFPPacket_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_t38_IFPPacket(tvb, offset, &asn1_ctx, tree, hf_t38_IFPPacket_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UDPTLPacket_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_t38_UDPTLPacket(tvb, offset, &asn1_ctx, tree, hf_t38_UDPTLPacket_PDU);
offset += 7; offset >>= 3;
return offset;
}
static void
init_t38_info_conv(packet_info *pinfo)
{
t38_info_current++;
if (t38_info_current==MAX_T38_MESSAGES_IN_PACKET) {
t38_info_current=0;
}
t38_info = &t38_info_arr[t38_info_current];
t38_info->seq_num = 0;
t38_info->type_msg = 0;
t38_info->data_value = 0;
t38_info->t30ind_value =0;
t38_info->setup_frame_number = 0;
t38_info->Data_Field_field_type_value = 0;
t38_info->desc[0] = '\0';
t38_info->desc_comment[0] = '\0';
t38_info->time_first_t4_data = 0;
t38_info->frame_num_first_t4_data = 0;
p_t38_packet_conv = NULL;
p_t38_conv = NULL;
p_t38_packet_conv = (t38_conv *)p_get_proto_data(pinfo->fd, proto_t38, 0);
p_conv = find_conversation(pinfo->fd->num, &pinfo->net_dst, &pinfo->net_src,
pinfo->ptype,
pinfo->destport, pinfo->srcport, NO_ADDR_B | NO_PORT_B);
if (!p_conv) {
p_conv = conversation_new(pinfo->fd->num, &pinfo->net_src, &pinfo->net_dst,
pinfo->ptype, pinfo->srcport, pinfo->destport, NO_ADDR_B | NO_PORT_B);
conversation_set_dissector(p_conv, t38_udp_handle);
}
if (!p_t38_packet_conv) {
p_t38_conv = (t38_conv *)conversation_get_proto_data(p_conv, proto_t38);
if (!p_t38_conv) {
p_t38_conv = se_new(t38_conv);
p_t38_conv->setup_method[0] = '\0';
p_t38_conv->setup_frame_number = 0;
p_t38_conv->src_t38_info.reass_ID = 0;
p_t38_conv->src_t38_info.reass_start_seqnum = -1;
p_t38_conv->src_t38_info.reass_data_type = 0;
p_t38_conv->src_t38_info.last_seqnum = -1;
p_t38_conv->src_t38_info.packet_lost = 0;
p_t38_conv->src_t38_info.burst_lost = 0;
p_t38_conv->src_t38_info.time_first_t4_data = 0;
p_t38_conv->src_t38_info.additional_hdlc_data_field_counter = 0;
p_t38_conv->src_t38_info.seqnum_prev_data_field = -1;
p_t38_conv->dst_t38_info.reass_ID = 0;
p_t38_conv->dst_t38_info.reass_start_seqnum = -1;
p_t38_conv->dst_t38_info.reass_data_type = 0;
p_t38_conv->dst_t38_info.last_seqnum = -1;
p_t38_conv->dst_t38_info.packet_lost = 0;
p_t38_conv->dst_t38_info.burst_lost = 0;
p_t38_conv->dst_t38_info.time_first_t4_data = 0;
p_t38_conv->dst_t38_info.additional_hdlc_data_field_counter = 0;
p_t38_conv->dst_t38_info.seqnum_prev_data_field = -1;
conversation_add_proto_data(p_conv, proto_t38, p_t38_conv);
}
p_t38_packet_conv = se_new(t38_conv);
g_strlcpy(p_t38_packet_conv->setup_method, p_t38_conv->setup_method, MAX_T38_SETUP_METHOD_SIZE);
p_t38_packet_conv->setup_frame_number = p_t38_conv->setup_frame_number;
memcpy(&(p_t38_packet_conv->src_t38_info), &(p_t38_conv->src_t38_info), sizeof(t38_conv_info));
memcpy(&(p_t38_packet_conv->dst_t38_info), &(p_t38_conv->dst_t38_info), sizeof(t38_conv_info));
p_add_proto_data(pinfo->fd, proto_t38, 0, p_t38_packet_conv);
}
if (ADDRESSES_EQUAL(&p_conv->key_ptr->addr1, &pinfo->net_src)) {
p_t38_conv_info = &(p_t38_conv->src_t38_info);
p_t38_packet_conv_info = &(p_t38_packet_conv->src_t38_info);
} else {
p_t38_conv_info = &(p_t38_conv->dst_t38_info);
p_t38_packet_conv_info = &(p_t38_packet_conv->dst_t38_info);
}
t38_info->setup_frame_number = p_t38_packet_conv->setup_frame_number;
}
static void
dissect_t38_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 octet1;
proto_item *it;
proto_tree *tr;
guint32 offset=0;
if (dissect_possible_rtpv2_packets_as_rtp){
octet1 = tvb_get_guint8(tvb, offset);
if (RTP_VERSION(octet1) == 2){
call_dissector(rtp_handle,tvb,pinfo,tree);
return;
}
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "T.38");
col_clear(pinfo->cinfo, COL_INFO);
primary_part = TRUE;
Data_Field_item_num = 0;
it=proto_tree_add_protocol_format(tree, proto_t38, tvb, 0, -1, "ITU-T Recommendation T.38");
tr=proto_item_add_subtree(it, ett_t38);
init_t38_info_conv(pinfo);
if (global_t38_show_setup_info) {
show_setup_info(tvb, tr, p_t38_packet_conv);
}
col_append_str(pinfo->cinfo, COL_INFO, "UDP: UDPTLPacket ");
offset = dissect_UDPTLPacket_PDU(tvb, pinfo, tr, NULL);
if (tvb_length_remaining(tvb,offset)>0){
if (tr){
proto_tree_add_text(tr, tvb, offset, tvb_reported_length_remaining(tvb, offset),
"[MALFORMED PACKET or wrong preference settings]");
}
col_append_str(pinfo->cinfo, COL_INFO, " [Malformed?]");
}
}
static void
dissect_t38_tcp_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *it;
proto_tree *tr;
guint32 offset=0;
tvbuff_t *next_tvb;
guint16 ifp_packet_number=1;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "T.38");
col_clear(pinfo->cinfo, COL_INFO);
primary_part = TRUE;
Data_Field_item_num = 0;
it=proto_tree_add_protocol_format(tree, proto_t38, tvb, 0, -1, "ITU-T Recommendation T.38");
tr=proto_item_add_subtree(it, ett_t38);
init_t38_info_conv(pinfo);
if (global_t38_show_setup_info) {
show_setup_info(tvb, tr, p_t38_packet_conv);
}
col_append_str(pinfo->cinfo, COL_INFO, "TCP: IFPPacket");
while(tvb_length_remaining(tvb,offset)>0)
{
next_tvb = tvb_new_subset_remaining(tvb, offset);
offset += dissect_IFPPacket_PDU(next_tvb, pinfo, tr, NULL);
ifp_packet_number++;
if(tvb_length_remaining(tvb,offset)>0){
if(t38_tpkt_usage == T38_TPKT_ALWAYS){
if(tr){
proto_tree_add_text(tr, tvb, offset, tvb_reported_length_remaining(tvb, offset),
"[MALFORMED PACKET or wrong preference settings]");
}
col_append_str(pinfo->cinfo, COL_INFO, " [Malformed?]");
break;
}else {
col_append_fstr(pinfo->cinfo, COL_INFO, " IFPPacket#%u",ifp_packet_number);
}
}
}
}
static void
dissect_t38_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
primary_part = TRUE;
if(t38_tpkt_usage == T38_TPKT_ALWAYS){
dissect_tpkt_encap(tvb,pinfo,tree,t38_tpkt_reassembly,t38_tcp_pdu_handle);
}
else if((t38_tpkt_usage == T38_TPKT_NEVER) || (is_tpkt(tvb,1) == -1)){
dissect_t38_tcp_pdu(tvb, pinfo, tree);
}
else {
dissect_tpkt_encap(tvb,pinfo,tree,t38_tpkt_reassembly,t38_tcp_pdu_handle);
}
}
static void
dissect_t38(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if(pinfo->ipproto == IP_PROTO_TCP)
{
dissect_t38_tcp(tvb, pinfo, tree);
}
else if(pinfo->ipproto == IP_PROTO_UDP)
{
dissect_t38_udp(tvb, pinfo, tree);
}
}
void
show_setup_info(tvbuff_t *tvb, proto_tree *tree, t38_conv *p_t38_conversation)
{
proto_tree *t38_setup_tree;
proto_item *ti;
if (!p_t38_conversation || p_t38_conversation->setup_frame_number == 0) {
return;
}
ti = proto_tree_add_string_format(tree, hf_t38_setup, tvb, 0, 0,
"",
"Stream setup by %s (frame %u)",
p_t38_conversation->setup_method,
p_t38_conversation->setup_frame_number);
PROTO_ITEM_SET_GENERATED(ti);
t38_setup_tree = proto_item_add_subtree(ti, ett_t38_setup);
if (t38_setup_tree)
{
proto_item* item = proto_tree_add_uint(t38_setup_tree, hf_t38_setup_frame,
tvb, 0, 0, p_t38_conversation->setup_frame_number);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_string(t38_setup_tree, hf_t38_setup_method,
tvb, 0, 0, p_t38_conversation->setup_method);
PROTO_ITEM_SET_GENERATED(item);
}
}
void
proto_register_t38(void)
{
static hf_register_info hf[] =
{
#line 1 "../../asn1/t38/packet-t38-hfarr.c"
{ &hf_t38_IFPPacket_PDU,
{ "IFPPacket", "t38.IFPPacket",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t38_UDPTLPacket_PDU,
{ "UDPTLPacket", "t38.UDPTLPacket",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t38_type_of_msg,
{ "type-of-msg", "t38.type_of_msg",
FT_UINT32, BASE_DEC, VALS(t38_Type_of_msg_vals), 0,
NULL, HFILL }},
{ &hf_t38_data_field,
{ "data-field", "t38.data_field",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_t38_t30_indicator,
{ "t30-indicator", "t38.t30_indicator",
FT_UINT32, BASE_DEC, VALS(t38_T30_indicator_vals), 0,
NULL, HFILL }},
{ &hf_t38_t30_data,
{ "t30-data", "t38.t30_data",
FT_UINT32, BASE_DEC, VALS(t38_T30_data_vals), 0,
NULL, HFILL }},
{ &hf_t38_Data_Field_item,
{ "Data-Field item", "t38.Data_Field_item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t38_field_type,
{ "field-type", "t38.field_type",
FT_UINT32, BASE_DEC, VALS(t38_T_field_type_vals), 0,
NULL, HFILL }},
{ &hf_t38_field_data,
{ "field-data", "t38.field_data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t38_seq_number,
{ "seq-number", "t38.seq_number",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_t38_primary_ifp_packet,
{ "primary-ifp-packet", "t38.primary_ifp_packet",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t38_error_recovery,
{ "error-recovery", "t38.error_recovery",
FT_UINT32, BASE_DEC, VALS(t38_T_error_recovery_vals), 0,
NULL, HFILL }},
{ &hf_t38_secondary_ifp_packets,
{ "secondary-ifp-packets", "t38.secondary_ifp_packets",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_t38_secondary_ifp_packets_item,
{ "secondary-ifp-packets item", "t38.secondary_ifp_packets_item",
FT_NONE, BASE_NONE, NULL, 0,
"OpenType_IFPPacket", HFILL }},
{ &hf_t38_fec_info,
{ "fec-info", "t38.fec_info",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t38_fec_npackets,
{ "fec-npackets", "t38.fec_npackets",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_t38_fec_data,
{ "fec-data", "t38.fec_data",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_t38_fec_data_item,
{ "fec-data item", "t38.fec_data_item",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
#line 670 "../../asn1/t38/packet-t38-template.c"
{ &hf_t38_setup,
{ "Stream setup", "t38.setup", FT_STRING, BASE_NONE,
NULL, 0x0, "Stream setup, method and frame number", HFILL }},
{ &hf_t38_setup_frame,
{ "Stream frame", "t38.setup-frame", FT_FRAMENUM, BASE_NONE,
NULL, 0x0, "Frame that set up this stream", HFILL }},
{ &hf_t38_setup_method,
{ "Stream Method", "t38.setup-method", FT_STRING, BASE_NONE,
NULL, 0x0, "Method used to set up this stream", HFILL }},
{&hf_t38_fragments,
{"Message fragments", "t38.fragments",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_t38_fragment,
{"Message fragment", "t38.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_t38_fragment_overlap,
{"Message fragment overlap", "t38.fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{&hf_t38_fragment_overlap_conflicts,
{"Message fragment overlapping with conflicting data",
"t38.fragment.overlap.conflicts",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{&hf_t38_fragment_multiple_tails,
{"Message has multiple tail fragments",
"t38.fragment.multiple_tails",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{&hf_t38_fragment_too_long_fragment,
{"Message fragment too long", "t38.fragment.too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{&hf_t38_fragment_error,
{"Message defragmentation error", "t38.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_t38_fragment_count,
{"Message fragment count", "t38.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL } },
{&hf_t38_reassembled_in,
{"Reassembled in", "t38.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_t38_reassembled_length,
{"Reassembled T38 length", "t38.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL } },
};
static gint *ett[] =
{
&ett_t38,
#line 1 "../../asn1/t38/packet-t38-ettarr.c"
&ett_t38_IFPPacket,
&ett_t38_Type_of_msg,
&ett_t38_Data_Field,
&ett_t38_Data_Field_item,
&ett_t38_UDPTLPacket,
&ett_t38_T_error_recovery,
&ett_t38_T_secondary_ifp_packets,
&ett_t38_T_fec_info,
&ett_t38_T_fec_data,
#line 717 "../../asn1/t38/packet-t38-template.c"
&ett_t38_setup,
&ett_data_fragment,
&ett_data_fragments
};
module_t *t38_module;
proto_t38 = proto_register_protocol("T.38", "T.38", "t38");
proto_register_field_array(proto_t38, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("t38", dissect_t38, proto_t38);
register_init_routine(t38_defragment_init);
t38_tap = register_tap("t38");
t38_module = prefs_register_protocol(proto_t38, proto_reg_handoff_t38);
prefs_register_bool_preference(t38_module, "use_pre_corrigendum_asn1_specification",
"Use the Pre-Corrigendum ASN.1 specification",
"Whether the T.38 dissector should decode using the Pre-Corrigendum T.38 "
"ASN.1 specification (1998).",
&use_pre_corrigendum_asn1_specification);
prefs_register_bool_preference(t38_module, "dissect_possible_rtpv2_packets_as_rtp",
"Dissect possible RTP version 2 packets with RTP dissector",
"Whether a UDP packet that looks like RTP version 2 packet will "
"be dissected as RTP packet or T.38 packet. If enabled there is a risk that T.38 UDPTL "
"packets with sequence number higher than 32767 may be dissected as RTP.",
&dissect_possible_rtpv2_packets_as_rtp);
prefs_register_uint_preference(t38_module, "tcp.port",
"T.38 TCP Port",
"Set the TCP port for T.38 messages",
10, &global_t38_tcp_port);
prefs_register_uint_preference(t38_module, "udp.port",
"T.38 UDP Port",
"Set the UDP port for T.38 messages",
10, &global_t38_udp_port);
prefs_register_bool_preference(t38_module, "reassembly",
"Reassemble T.38 PDUs over TPKT over TCP",
"Whether the dissector should reassemble T.38 PDUs spanning multiple TCP segments "
"when TPKT is used over TCP. "
"To use this option, you must also enable \"Allow subdissectors to reassemble "
"TCP streams\" in the TCP protocol settings.",
&t38_tpkt_reassembly);
prefs_register_enum_preference(t38_module, "tpkt_usage",
"TPKT used over TCP",
"Whether T.38 is used with TPKT for TCP",
(gint *)&t38_tpkt_usage,t38_tpkt_options,FALSE);
prefs_register_bool_preference(t38_module, "show_setup_info",
"Show stream setup information",
"Where available, show which protocol and frame caused "
"this T.38 stream to be created",
&global_t38_show_setup_info);
}
void
proto_reg_handoff_t38(void)
{
static gboolean t38_prefs_initialized = FALSE;
static guint tcp_port;
static guint udp_port;
if (!t38_prefs_initialized) {
t38_udp_handle=create_dissector_handle(dissect_t38_udp, proto_t38);
t38_tcp_handle=create_dissector_handle(dissect_t38_tcp, proto_t38);
t38_tcp_pdu_handle=create_dissector_handle(dissect_t38_tcp_pdu, proto_t38);
rtp_handle = find_dissector("rtp");
t30_hdlc_handle = find_dissector("t30.hdlc");
data_handle = find_dissector("data");
t38_prefs_initialized = TRUE;
}
else {
dissector_delete_uint("tcp.port", tcp_port, t38_tcp_handle);
dissector_delete_uint("udp.port", udp_port, t38_udp_handle);
}
tcp_port = global_t38_tcp_port;
udp_port = global_t38_udp_port;
dissector_add_uint("tcp.port", tcp_port, t38_tcp_handle);
dissector_add_uint("udp.port", udp_port, t38_udp_handle);
}
