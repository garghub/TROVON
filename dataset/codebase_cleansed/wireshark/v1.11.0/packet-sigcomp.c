static void
sigcomp_init_protocol(void)
{
sigcomp_init_udvm();
}
static int
dissect_sigcomp_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *_data _U_)
{
proto_item *ti;
proto_tree *sigcomp_tree;
tvbuff_t *unescaped_tvb;
guint8 *buff;
int offset = 0;
int length;
guint8 octet;
guint16 data;
int i;
int n;
gboolean end_off_message;
top_tree = tree;
data = tvb_get_ntohs(tvb, offset);
if(data == 0xffff){
offset = offset + 2;
octet = tvb_get_guint8(tvb,offset);
}else{
octet = tvb_get_guint8(tvb,offset);
}
if ((octet & 0xf8) != 0xf8)
return offset;
length = tvb_ensure_length_remaining(tvb, offset);
for(i=0; i<(length-1); ++i){
data = tvb_get_ntohs(tvb, offset+i);
if (0xffff == data) break;
}
if (i >= (length-1)){
if (pinfo->can_desegment || pinfo->saved_can_desegment){
pinfo->desegment_offset = offset;
pinfo->desegment_len=DESEGMENT_ONE_MORE_SEGMENT;
return -1;
}
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SIGCOMP");
col_clear(pinfo->cinfo, COL_INFO);
length = tvb_length_remaining(tvb,offset);
try_again:
ti = proto_tree_add_item(tree, proto_sigcomp, tvb, 0, -1, ENC_NA);
sigcomp_tree = proto_item_add_subtree(ti, ett_sigcomp);
i=0;
end_off_message = FALSE;
buff = (guint8 *)wmem_alloc(pinfo->pool, length-offset);
if (udvm_print_detail_level>2)
proto_tree_add_text(sigcomp_tree, tvb, offset, -1,"Starting to remove escape digits");
while ((offset < length) && (end_off_message == FALSE)){
octet = tvb_get_guint8(tvb,offset);
if ( octet == 0xff ){
if ( offset +1 >= length ){
offset++;
continue;
}
if (udvm_print_detail_level>2)
proto_tree_add_text(sigcomp_tree, tvb, offset, 2,
" Escape digit found (0xFF)");
octet = tvb_get_guint8(tvb, offset+1);
if ( octet == 0){
buff[i] = 0xff;
offset = offset +2;
i++;
continue;
}
if ((octet > 0x7f) && (octet < 0xff )){
if (udvm_print_detail_level>2)
proto_tree_add_text(sigcomp_tree, tvb, offset, 2,
" Illegal escape code");
offset = offset + tvb_length_remaining(tvb,offset);
return offset;
}
if ( octet == 0xff){
if (udvm_print_detail_level>2)
proto_tree_add_text(sigcomp_tree, tvb, offset, 2,
" End of SigComp message indication found (0xFFFF)");
end_off_message = TRUE;
offset = offset+2;
continue;
}
buff[i] = 0xff;
if (udvm_print_detail_level>2)
proto_tree_add_text(sigcomp_tree, tvb, offset, 1,
" Addr: %u tvb value(0x%0x) ", i, buff[i]);
i++;
offset = offset+2;
if (udvm_print_detail_level>2)
proto_tree_add_text(sigcomp_tree, tvb, offset, octet,
" Copying %u bytes literally",octet);
if( offset+octet >= length)
octet = length - offset;
for ( n=0; n < octet; n++ ){
buff[i] = tvb_get_guint8(tvb, offset);
if (udvm_print_detail_level>2)
proto_tree_add_text(sigcomp_tree, tvb, offset, 1,
" Addr: %u tvb value(0x%0x) ", i, buff[i]);
i++;
offset++;
}
continue;
}
buff[i] = octet;
if (udvm_print_detail_level>2)
proto_tree_add_text(sigcomp_tree, tvb, offset, 1,
" Addr: %u tvb value(0x%0x) ", i, buff[i]);
i++;
offset++;
}
unescaped_tvb = tvb_new_child_real_data(tvb, buff,i,i);
add_new_data_source(pinfo, unescaped_tvb, "Unescaped Data handed to the SigComp dissector");
proto_tree_add_text(sigcomp_tree, unescaped_tvb, 0, -1,"Data handed to the Sigcomp dissector");
if (end_off_message == TRUE){
dissect_sigcomp_common(unescaped_tvb, pinfo, sigcomp_tree);
}else{
proto_tree_add_text(sigcomp_tree, unescaped_tvb, 0, -1,"TCP Fragment, no end mark found");
}
if ( offset < length){
goto try_again;
}
return offset;
}
static int
dissect_sigcomp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *sigcomp_tree;
gint offset = 0;
gint8 octet;
if ( pinfo->ptype == PT_TCP )
return dissect_sigcomp_tcp(tvb, pinfo, tree, NULL);
octet = tvb_get_guint8(tvb, offset);
if ((octet & 0xf8) != 0xf8)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SIGCOMP");
col_clear(pinfo->cinfo, COL_INFO);
top_tree = tree;
ti = proto_tree_add_item(tree, proto_sigcomp, tvb, 0, -1, ENC_NA);
sigcomp_tree = proto_item_add_subtree(ti, ett_sigcomp);
return dissect_sigcomp_common(tvb, pinfo, sigcomp_tree);
}
static int
dissect_sigcomp_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *sigcomp_tree)
{
tvbuff_t *udvm_tvb, *msg_tvb, *udvm2_tvb;
tvbuff_t *decomp_tvb = NULL;
proto_item *udvm_bytecode_item, *udvm_exe_item;
proto_tree *sigcomp_udvm_tree, *sigcomp_udvm_exe_tree;
gint offset = 0;
gint bytecode_offset;
guint16 partial_state_len;
guint octet;
guint8 returned_feedback_field[128];
guint8 partial_state[12];
guint tbit;
guint16 len = 0;
guint16 bytecode_len = 0;
guint destination;
gint msg_len = 0;
guint8 *buff;
guint16 p_id_start;
guint8 i;
guint16 state_begin;
guint16 state_length;
guint16 state_address;
guint16 state_instruction;
guint16 result_code;
gchar *partial_state_str;
guint8 nack_version;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_item(sigcomp_tree,hf_sigcomp_t_bit, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sigcomp_tree,hf_sigcomp_len, tvb, offset, 1, ENC_BIG_ENDIAN);
tbit = ( octet & 0x04)>>2;
partial_state_len = octet & 0x03;
offset ++;
if ( partial_state_len != 0 ){
partial_state_len = partial_state_len * 3 + 3;
col_set_str(pinfo->cinfo, COL_INFO, "Msg format 1");
if ( tbit == 1 ) {
len = 1;
octet = tvb_get_guint8(tvb, offset);
if ( (octet & 0x80) != 0 ){
len = octet & 0x7f;
proto_tree_add_item(sigcomp_tree,hf_sigcomp_returned_feedback_item_len,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
tvb_memcpy(tvb,returned_feedback_field,offset, len);
} else {
returned_feedback_field[0] = tvb_get_guint8(tvb, offset) & 0x7f;
}
proto_tree_add_bytes(sigcomp_tree,hf_sigcomp_returned_feedback_item,
tvb, offset, len, returned_feedback_field);
offset = offset + len;
}
tvb_memcpy(tvb, partial_state, offset, partial_state_len);
partial_state_str = bytes_to_str(partial_state, partial_state_len);
proto_tree_add_string(sigcomp_tree,hf_sigcomp_partial_state,
tvb, offset, partial_state_len, partial_state_str);
offset = offset + partial_state_len;
msg_len = tvb_reported_length_remaining(tvb, offset);
if(msg_len>0){
proto_item *ti;
ti = proto_tree_add_uint(sigcomp_tree, hf_sigcomp_remaining_message_bytes, tvb,
offset, 0, msg_len);
PROTO_ITEM_SET_GENERATED(ti);
}
if ( decompress ) {
msg_tvb = tvb_new_subset(tvb, offset, msg_len, msg_len);
buff = (guint8 *)wmem_alloc0(pinfo->pool, UDVM_MEMORY_SIZE);
p_id_start = 0;
state_begin = 0;
state_length = 0;
state_address = 0;
state_instruction =0;
i = 0;
while ( i < partial_state_len ){
buff[i] = partial_state[i];
i++;
}
#if 0
result_code = udvm_state_access(tvb, sigcomp_tree, buff, p_id_start, partial_state_len, state_begin, &state_length,
&state_address, &state_instruction, hf_sigcomp_partial_state);
#endif
result_code = udvm_state_access(tvb, sigcomp_tree, buff, p_id_start, STATE_MIN_ACCESS_LEN, state_begin, &state_length,
&state_address, &state_instruction, hf_sigcomp_partial_state);
if ( result_code != 0 ){
proto_item *ti;
ti = proto_tree_add_text(sigcomp_tree, tvb, 0, -1,"Failed to Access state Wireshark UDVM diagnostic: %s.",
val_to_str(result_code, result_code_vals,"Unknown (%u)"));
PROTO_ITEM_SET_GENERATED(ti);
return tvb_length(tvb);
}
udvm_tvb = tvb_new_child_real_data(tvb, buff,state_length+state_address,state_length+state_address);
add_new_data_source(pinfo, udvm_tvb, "State/ExecutionTrace");
udvm2_tvb = tvb_new_subset(udvm_tvb, state_address, state_length, state_length);
udvm_exe_item = proto_tree_add_item(sigcomp_tree, hf_udvm_execution_trace,
udvm2_tvb, 0, state_length,
ENC_NA);
sigcomp_udvm_exe_tree = proto_item_add_subtree( udvm_exe_item, ett_sigcomp_udvm_exe);
decomp_tvb = decompress_sigcomp_message(udvm2_tvb, msg_tvb, pinfo,
sigcomp_udvm_exe_tree, state_address,
udvm_print_detail_level, hf_sigcomp_partial_state,
offset, state_length, partial_state_len, state_instruction);
if ( decomp_tvb ){
proto_item *ti;
guint32 compression_ratio =
(guint32)(((float)tvb_length(decomp_tvb) / (float)tvb_length(tvb)) * 100);
proto_tree_add_text(sigcomp_tree, decomp_tvb, 0, -1,"SigComp message Decompressed WOHO!!");
ti = proto_tree_add_uint(sigcomp_tree, hf_sigcomp_compression_ratio, decomp_tvb,
0, 0, compression_ratio);
PROTO_ITEM_SET_GENERATED(ti);
if ( display_raw_txt )
tvb_raw_text_add(decomp_tvb, top_tree);
col_append_str(pinfo->cinfo, COL_PROTOCOL, "/");
col_set_fence(pinfo->cinfo,COL_PROTOCOL);
call_dissector(sip_handle, decomp_tvb, pinfo, top_tree);
}
}
}
else{
col_set_str(pinfo->cinfo, COL_INFO, "Msg format 2");
if ( tbit == 1 ) {
len = 1;
octet = tvb_get_guint8(tvb, offset);
if ( (octet & 0x80) != 0 ){
len = octet & 0x7f;
proto_tree_add_item(sigcomp_tree,hf_sigcomp_returned_feedback_item_len,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
}
tvb_memcpy(tvb,returned_feedback_field,offset, len);
proto_tree_add_bytes(sigcomp_tree,hf_sigcomp_returned_feedback_item,
tvb, offset, len, returned_feedback_field);
offset = offset + len;
}
len = tvb_get_ntohs(tvb, offset) >> 4;
nack_version = tvb_get_guint8(tvb, offset+1) & 0x0f;
if ((len == 0) && (nack_version == 1)){
proto_item *reason_ti;
guint8 opcode;
offset++;
proto_tree_add_item(sigcomp_tree,hf_sigcomp_nack_ver, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
octet = tvb_get_guint8(tvb, offset);
reason_ti = proto_tree_add_item(sigcomp_tree,hf_sigcomp_nack_reason_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
opcode = tvb_get_guint8(tvb, offset);
proto_tree_add_item(sigcomp_tree,hf_sigcomp_nack_failed_op_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
expert_add_info_format(pinfo, reason_ti, &ei_sigcomp_nack_failed_op_code,
"SigComp NACK (reason=%s, opcode=%s)",
val_to_str_const(octet, sigcomp_nack_reason_code_vals, "Unknown"),
val_to_str_const(opcode, udvm_instruction_code_vals, "Unknown"));
proto_tree_add_item(sigcomp_tree,hf_sigcomp_nack_pc, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset +2;
proto_tree_add_item(sigcomp_tree,hf_sigcomp_nack_sha1, tvb, offset, 20, ENC_NA);
offset = offset +20;
col_append_fstr(pinfo->cinfo, COL_INFO, " NACK reason=%s, opcode=%s",
val_to_str_const(octet, sigcomp_nack_reason_code_vals, "Unknown"),
val_to_str_const(opcode, udvm_instruction_code_vals, "Unknown"));
switch ( octet){
case SIGCOMP_NACK_STATE_NOT_FOUND:
case SIGCOMP_NACK_ID_NOT_UNIQUE:
case SIGCOMP_NACK_STATE_TOO_SHORT:
proto_tree_add_item(sigcomp_tree,hf_sigcomp_nack_state_id, tvb, offset, -1, ENC_NA);
break;
case SIGCOMP_NACK_CYCLES_EXHAUSTED:
proto_tree_add_item(sigcomp_tree,hf_sigcomp_nack_cycles_per_bit, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SIGCOMP_NACK_BYTECODES_TOO_LARGE:
proto_tree_add_item(sigcomp_tree,hf_sigcomp_nack_memory_size, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
default:
break;
}
}else{
octet = tvb_get_guint8(tvb, (offset + 1));
destination = (octet & 0x0f);
if ( destination != 0 )
destination = 64 + ( destination * 64 );
proto_tree_add_item(sigcomp_tree,hf_sigcomp_code_len, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sigcomp_tree,hf_sigcomp_destination, tvb, (offset+ 1), 1, ENC_BIG_ENDIAN);
offset = offset +2;
bytecode_len = len;
bytecode_offset = offset;
udvm_bytecode_item = proto_tree_add_item(sigcomp_tree, hf_sigcomp_udvm_bytecode, tvb,
bytecode_offset, bytecode_len, ENC_NA);
proto_item_append_text(udvm_bytecode_item,
" %u (0x%x) bytes", bytecode_len, bytecode_len);
sigcomp_udvm_tree = proto_item_add_subtree( udvm_bytecode_item, ett_sigcomp_udvm);
udvm_tvb = tvb_new_subset(tvb, offset, len, len);
if ( dissect_udvm_code )
dissect_udvm_bytecode(udvm_tvb, sigcomp_udvm_tree, destination);
offset = offset + len;
msg_len = tvb_reported_length_remaining(tvb, offset);
if (msg_len>0) {
proto_item *ti = proto_tree_add_text(sigcomp_tree, tvb, offset, -1,
"Remaining SigComp message %u bytes",
tvb_reported_length_remaining(tvb, offset));
PROTO_ITEM_SET_GENERATED(ti);
}
if ( decompress ){
msg_tvb = tvb_new_subset(tvb, offset, msg_len, msg_len);
udvm_exe_item = proto_tree_add_item(sigcomp_tree, hf_udvm_execution_trace,
tvb, bytecode_offset, bytecode_len,
ENC_NA);
sigcomp_udvm_exe_tree = proto_item_add_subtree( udvm_exe_item, ett_sigcomp_udvm_exe);
decomp_tvb = decompress_sigcomp_message(udvm_tvb, msg_tvb, pinfo,
sigcomp_udvm_exe_tree, destination,
udvm_print_detail_level, hf_sigcomp_partial_state,
offset, 0, 0, destination);
if ( decomp_tvb ){
proto_item *ti;
guint32 compression_ratio =
(guint32)(((float)tvb_length(decomp_tvb) / (float)tvb_length(tvb)) * 100);
proto_tree_add_text(sigcomp_tree, decomp_tvb, 0, -1,"SigComp message Decompressed WOHO!!");
ti = proto_tree_add_uint(sigcomp_tree, hf_sigcomp_compression_ratio, decomp_tvb,
0, 0, compression_ratio);
PROTO_ITEM_SET_GENERATED(ti);
if ( display_raw_txt )
tvb_raw_text_add(decomp_tvb, top_tree);
col_append_str(pinfo->cinfo, COL_PROTOCOL, "/");
col_set_fence(pinfo->cinfo,COL_PROTOCOL);
call_dissector(sip_handle, decomp_tvb, pinfo, top_tree);
}
}
}
}
return tvb_length(tvb);
}
static void
dissect_udvm_bytecode(tvbuff_t *udvm_tvb, proto_tree *sigcomp_udvm_tree,guint start_address)
{
guint instruction;
gint offset = 0;
gint start_offset = 0;
gint len;
gint n;
guint instruction_no = 0;
guint16 value = 0;
proto_item *item, *item2;
guint UDVM_address = start_address;
gboolean is_memory_address;
guint16 msg_length = tvb_reported_length_remaining(udvm_tvb, offset);
while (msg_length > offset) {
instruction = tvb_get_guint8(udvm_tvb, offset);
instruction_no ++;
UDVM_address = start_address + offset;
;
item = proto_tree_add_text(sigcomp_udvm_tree, udvm_tvb, offset, 1,
"######### UDVM instruction %u at UDVM-address %u (0x%x) #########",
instruction_no,UDVM_address,UDVM_address);
PROTO_ITEM_SET_GENERATED(item);
proto_tree_add_item(sigcomp_udvm_tree, hf_sigcomp_udvm_instr, udvm_tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
switch ( instruction ) {
case SIGCOMP_INSTR_AND:
offset = dissect_udvm_reference_operand(udvm_tvb, sigcomp_udvm_tree, offset, &start_offset, &value);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_1,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ){
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_2_addr,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_2,
udvm_tvb, start_offset, len, value);
}
break;
case SIGCOMP_INSTR_OR:
offset = dissect_udvm_reference_operand(udvm_tvb, sigcomp_udvm_tree, offset, &start_offset, &value);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_1,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ){
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_2_addr,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_2,
udvm_tvb, start_offset, len, value);
}
break;
case SIGCOMP_INSTR_NOT:
offset = dissect_udvm_reference_operand(udvm_tvb, sigcomp_udvm_tree, offset, &start_offset, &value);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_1,
udvm_tvb, start_offset, len, value);
break;
case SIGCOMP_INSTR_LSHIFT:
offset = dissect_udvm_reference_operand(udvm_tvb, sigcomp_udvm_tree, offset, &start_offset, &value);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_1,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ){
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_2_addr,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_2,
udvm_tvb, start_offset, len, value);
}
break;
case SIGCOMP_INSTR_RSHIFT:
offset = dissect_udvm_reference_operand(udvm_tvb, sigcomp_udvm_tree, offset, &start_offset, &value);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_1,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ){
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_2_addr,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_2,
udvm_tvb, start_offset, len, value);
}
break;
case SIGCOMP_INSTR_ADD:
offset = dissect_udvm_reference_operand(udvm_tvb, sigcomp_udvm_tree, offset, &start_offset, &value);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_1,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ){
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_2_addr,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_2,
udvm_tvb, start_offset, len, value);
}
break;
case SIGCOMP_INSTR_SUBTRACT:
offset = dissect_udvm_reference_operand(udvm_tvb, sigcomp_udvm_tree, offset, &start_offset, &value);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_1,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ){
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_2_addr,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_2,
udvm_tvb, start_offset, len, value);
}
break;
case SIGCOMP_INSTR_MULTIPLY:
offset = dissect_udvm_reference_operand(udvm_tvb, sigcomp_udvm_tree, offset, &start_offset, &value);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_1,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ){
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_2_addr,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_2,
udvm_tvb, start_offset, len, value);
}
break;
case SIGCOMP_INSTR_DIVIDE:
offset = dissect_udvm_reference_operand(udvm_tvb, sigcomp_udvm_tree, offset, &start_offset, &value);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_1,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ){
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_2_addr,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_2,
udvm_tvb, start_offset, len, value);
}
break;
case SIGCOMP_INSTR_REMAINDER:
offset = dissect_udvm_reference_operand(udvm_tvb, sigcomp_udvm_tree, offset, &start_offset, &value);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_1,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ){
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_2_addr,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_2,
udvm_tvb, start_offset, len, value);
}
break;
case SIGCOMP_INSTR_SORT_ASCENDING:
offset = offset + tvb_reported_length_remaining(udvm_tvb, offset);
break;
case SIGCOMP_INSTR_SORT_DESCENDING:
offset = offset + tvb_reported_length_remaining(udvm_tvb, offset);
break;
case SIGCOMP_INSTR_SHA_1:
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_position,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ){
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_length,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_length,
udvm_tvb, start_offset, len, value);
}
offset = dissect_udvm_reference_operand(udvm_tvb, sigcomp_udvm_tree, offset, &start_offset, &value);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_ref_dest,
udvm_tvb, start_offset, len, value);
break;
case SIGCOMP_INSTR_LOAD:
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_address,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ){
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_value,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_value,
udvm_tvb, start_offset, len, value);
}
break;
case SIGCOMP_INSTR_MULTILOAD:
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_address,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_literal_operand(udvm_tvb, sigcomp_udvm_tree, offset, &start_offset, &value);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_literal_num,
udvm_tvb, start_offset, len, value);
n = value;
while ( n > 0) {
n = n -1;
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ){
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_value,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_value,
udvm_tvb, start_offset, len, value);
}
}
break;
case SIGCOMP_INSTR_PUSH:
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ){
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_value,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_value,
udvm_tvb, start_offset, len, value);
}
break;
case SIGCOMP_INSTR_POP:
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_address,
udvm_tvb, start_offset, len, value);
break;
case SIGCOMP_INSTR_COPY:
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_position,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ){
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_length,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_length,
udvm_tvb, start_offset, len, value);
}
offset = dissect_udvm_reference_operand(udvm_tvb, sigcomp_udvm_tree, offset, &start_offset, &value);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_ref_dest,
udvm_tvb, start_offset, len, value);
break;
case SIGCOMP_INSTR_COPY_LITERAL:
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_position,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ){
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_length,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_length,
udvm_tvb, start_offset, len, value);
}
offset = dissect_udvm_reference_operand(udvm_tvb, sigcomp_udvm_tree, offset, &start_offset, &value);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_ref_dest,
udvm_tvb, start_offset, len, value);
break;
case SIGCOMP_INSTR_COPY_OFFSET:
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ){
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_offset,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_offset,
udvm_tvb, start_offset, len, value);
}
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ){
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_length,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_length,
udvm_tvb, start_offset, len, value);
}
offset = dissect_udvm_reference_operand(udvm_tvb, sigcomp_udvm_tree, offset, &start_offset, &value);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_ref_dest,
udvm_tvb, start_offset, len, value);
break;
case SIGCOMP_INSTR_MEMSET:
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_address,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ){
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_length,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_length,
udvm_tvb, start_offset, len, value);
}
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_start_value,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_offset,
udvm_tvb, start_offset, len, value);
break;
case SIGCOMP_INSTR_JUMP:
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
value = ( value + UDVM_address ) & 0xffff;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_at_address,
udvm_tvb, start_offset, len, value);
break;
case SIGCOMP_INSTR_COMPARE:
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ){
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_value,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_value,
udvm_tvb, start_offset, len, value);
}
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ){
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_value,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_value,
udvm_tvb, start_offset, len, value);
}
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
value = ( value + UDVM_address ) & 0xffff;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_at_address,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
value = ( value + UDVM_address ) & 0xffff;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_at_address,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
value = ( value + UDVM_address ) & 0xffff;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_at_address,
udvm_tvb, start_offset, len, value);
break;
case SIGCOMP_INSTR_CALL:
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
value = ( value + UDVM_address ) & 0xffff;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_at_address,
udvm_tvb, start_offset, len, value);
break;
case SIGCOMP_INSTR_RETURN:
break;
case SIGCOMP_INSTR_SWITCH:
offset = dissect_udvm_literal_operand(udvm_tvb, sigcomp_udvm_tree, offset, &start_offset, &value);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_literal_num,
udvm_tvb, start_offset, len, value);
n = value;
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ){
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_j,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_j,
udvm_tvb, start_offset, len, value);
}
while ( n > 0) {
n = n -1;
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
value = ( value + UDVM_address ) & 0xffff;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_at_address,
udvm_tvb, start_offset, len, value);
}
break;
case SIGCOMP_INSTR_CRC:
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ){
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_value,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_value,
udvm_tvb, start_offset, len, value);
}
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_position,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ){
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_length,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_length,
udvm_tvb, start_offset, len, value);
}
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
value = ( value + UDVM_address ) & 0xffff;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_at_address,
udvm_tvb, start_offset, len, value);
break;
case SIGCOMP_INSTR_INPUT_BYTES:
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ){
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_length,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_length,
udvm_tvb, start_offset, len, value);
}
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ){
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_destination,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_destination,
udvm_tvb, start_offset, len, value);
}
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
value = ( value + UDVM_address ) & 0xffff;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_at_address,
udvm_tvb, start_offset, len, value);
break;
case SIGCOMP_INSTR_INPUT_BITS:
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ){
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_length,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_length,
udvm_tvb, start_offset, len, value);
}
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ){
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_destination,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_destination,
udvm_tvb, start_offset, len, value);
}
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
value = ( value + UDVM_address ) & 0xffff;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_at_address,
udvm_tvb, start_offset, len, value);
break;
case SIGCOMP_INSTR_INPUT_HUFFMAN:
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ){
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_destination,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_destination,
udvm_tvb, start_offset, len, value);
}
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
value = ( value + UDVM_address ) & 0xffff;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_at_address,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_literal_operand(udvm_tvb, sigcomp_udvm_tree, offset, &start_offset, &value);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_literal_num,
udvm_tvb, start_offset, len, value);
n = value;
while ( n > 0) {
n = n -1;
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_bits,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_lower_bound,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_upper_bound,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_uncompressed,
udvm_tvb, start_offset, len, value);
}
break;
case SIGCOMP_INSTR_STATE_ACCESS:
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value ,&is_memory_address);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_partial_identifier_start,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value ,&is_memory_address);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_partial_identifier_length,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_state_begin,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_state_length_addr,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_state_length,
udvm_tvb, start_offset, len, value);
}
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value ,&is_memory_address);
len = offset - start_offset;
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_state_address_addr,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_state_address,
udvm_tvb, start_offset, len, value);
}
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_state_instr,
udvm_tvb, start_offset, len, value);
break;
case SIGCOMP_INSTR_STATE_CREATE:
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_state_length_addr,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_state_length,
udvm_tvb, start_offset, len, value);
}
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_state_address_addr,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_state_address,
udvm_tvb, start_offset, len, value);
}
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_state_instr,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_min_acc_len,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_state_ret_pri,
udvm_tvb, start_offset, len, value);
break;
case SIGCOMP_INSTR_STATE_FREE:
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_partial_identifier_start,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_partial_identifier_length,
udvm_tvb, start_offset, len, value);
break;
case SIGCOMP_INSTR_OUTPUT:
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_output_start,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_output_start,
udvm_tvb, start_offset, len, value);
}
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_output_length_addr,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_output_length,
udvm_tvb, start_offset, len, value);
}
break;
case SIGCOMP_INSTR_END_MESSAGE:
if ((msg_length-1) < offset){
item2 = proto_tree_add_text(sigcomp_udvm_tree, udvm_tvb, 0, -1,
"All remaining parameters = 0(Not in the uploaded code as UDVM buffer initialized to Zero");
PROTO_ITEM_SET_GENERATED(item2);
return;
}
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_req_feedback_loc,
udvm_tvb, start_offset, len, value);
if ((msg_length-1) < offset){
item2 = proto_tree_add_text(sigcomp_udvm_tree, udvm_tvb, offset-1, -1,
"All remaining parameters = 0(Not in the uploaded code as UDVM buffer initialized to Zero");
PROTO_ITEM_SET_GENERATED(item2);
return;
}
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_ret_param_loc,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_state_length_addr,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_state_length,
udvm_tvb, start_offset, len, value);
}
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_state_address_addr,
udvm_tvb, start_offset, len, value);
}else{
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_state_address,
udvm_tvb, start_offset, len, value);
}
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_state_instr,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_min_acc_len,
udvm_tvb, start_offset, len, value);
if ( tvb_reported_length_remaining(udvm_tvb, offset) != 0 ){
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_state_ret_pri,
udvm_tvb, start_offset, len, value);
}else{
item2 = proto_tree_add_text(sigcomp_udvm_tree, udvm_tvb, offset, 1,
"state_retention_priority = 0(Not in the uploaded code as UDVM buffer initialized to Zero");
PROTO_ITEM_SET_GENERATED(item2);
}
if ( tvb_reported_length_remaining(udvm_tvb, offset) != 0 ){
len = tvb_reported_length_remaining(udvm_tvb, offset);
UDVM_address = start_address + offset;
proto_tree_add_text(sigcomp_udvm_tree, udvm_tvb, offset, len,
"Remaining %u bytes starting at UDVM addr %u (0x%x)- State information ?",len, UDVM_address, UDVM_address);
}
offset = offset + tvb_reported_length_remaining(udvm_tvb, offset);
break;
default:
offset = offset + tvb_reported_length_remaining(udvm_tvb, offset);
break;
}
}
return;
}
static int
dissect_udvm_literal_operand(tvbuff_t *udvm_tvb, proto_tree *sigcomp_udvm_tree,
gint offset, gint *start_offset, guint16 *value)
{
guint bytecode;
guint16 operand;
guint test_bits;
guint display_bytecode;
bytecode = tvb_get_guint8(udvm_tvb, offset);
test_bits = bytecode >> 7;
if (test_bits == 1){
test_bits = bytecode >> 6;
if (test_bits == 2){
display_bytecode = bytecode & 0xc0;
if ( display_udvm_bytecode )
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_literal_bytecode,
udvm_tvb, offset, 1, display_bytecode);
operand = tvb_get_ntohs(udvm_tvb, offset) & 0x3fff;
*value = operand;
*start_offset = offset;
offset = offset + 2;
}else{
display_bytecode = bytecode & 0xc0;
if ( display_udvm_bytecode )
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_literal_bytecode,
udvm_tvb, offset, 1, display_bytecode);
offset ++;
operand = tvb_get_ntohs(udvm_tvb, offset);
*value = operand;
*start_offset = offset;
offset = offset + 2;
}
}else{
display_bytecode = bytecode & 0xc0;
if ( display_udvm_bytecode )
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_literal_bytecode,
udvm_tvb, offset, 1, display_bytecode);
operand = ( bytecode & 0x7f);
*value = operand;
*start_offset = offset;
offset ++;
}
return offset;
}
static int
dissect_udvm_reference_operand(tvbuff_t *udvm_tvb, proto_tree *sigcomp_udvm_tree,
gint offset, gint *start_offset, guint16 *value)
{
guint bytecode;
guint16 operand;
guint test_bits;
guint display_bytecode;
bytecode = tvb_get_guint8(udvm_tvb, offset);
test_bits = bytecode >> 7;
if (test_bits == 1){
test_bits = bytecode >> 6;
if (test_bits == 2){
display_bytecode = bytecode & 0xc0;
if ( display_udvm_bytecode )
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_reference_bytecode,
udvm_tvb, offset, 1, display_bytecode);
operand = tvb_get_ntohs(udvm_tvb, offset) & 0x3fff;
*value = (operand * 2);
*start_offset = offset;
offset = offset + 2;
}else{
display_bytecode = bytecode & 0xc0;
if ( display_udvm_bytecode )
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_reference_bytecode,
udvm_tvb, offset, 1, display_bytecode);
offset ++;
operand = tvb_get_ntohs(udvm_tvb, offset);
*value = operand;
*start_offset = offset;
offset = offset + 2;
}
}else{
display_bytecode = bytecode & 0xc0;
if ( display_udvm_bytecode )
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_reference_bytecode,
udvm_tvb, offset, 1, display_bytecode);
operand = ( bytecode & 0x7f);
*value = (operand * 2);
*start_offset = offset;
offset ++;
}
return offset;
}
static int
dissect_udvm_multitype_operand(tvbuff_t *udvm_tvb, proto_tree *sigcomp_udvm_tree,
gint offset, gboolean is_addr _U_, gint *start_offset, guint16 *value, gboolean *is_memory_address )
{
guint bytecode;
guint display_bytecode;
guint16 operand;
guint32 result;
guint test_bits;
*is_memory_address = FALSE;
bytecode = tvb_get_guint8(udvm_tvb, offset);
test_bits = ( bytecode & 0xc0 ) >> 6;
switch (test_bits ){
case 0:
display_bytecode = bytecode & 0xc0;
if ( display_udvm_bytecode )
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_multitype_bytecode,
udvm_tvb, offset, 1, display_bytecode);
operand = ( bytecode & 0x3f);
*value = operand;
*start_offset = offset;
offset ++;
break;
case 1:
display_bytecode = bytecode & 0xc0;
if ( display_udvm_bytecode )
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_multitype_bytecode,
udvm_tvb, offset, 1, display_bytecode);
operand = ( bytecode & 0x3f) * 2;
*is_memory_address = TRUE;
*value = operand;
*start_offset = offset;
offset ++;
break;
case 2:
test_bits = ( bytecode & 0xe0 ) >> 5;
if ( test_bits == 5 ){
display_bytecode = bytecode & 0xe0;
if ( display_udvm_bytecode )
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_multitype_bytecode,
udvm_tvb, offset, 1, display_bytecode);
operand = tvb_get_ntohs(udvm_tvb, offset) & 0x1fff;
*value = operand;
*start_offset = offset;
offset = offset + 2;
}else{
test_bits = ( bytecode & 0xf0 ) >> 4;
if ( test_bits == 9 ){
display_bytecode = bytecode & 0xf0;
if ( display_udvm_bytecode )
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_multitype_bytecode,
udvm_tvb, offset, 1, display_bytecode);
operand = (tvb_get_ntohs(udvm_tvb, offset) & 0x0fff) + 61440;
*start_offset = offset;
*value = operand;
offset = offset + 2;
}else{
test_bits = ( bytecode & 0x08 ) >> 3;
if ( test_bits == 1){
display_bytecode = bytecode & 0xf8;
if ( display_udvm_bytecode )
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_multitype_bytecode,
udvm_tvb, offset, 1, display_bytecode);
result = (guint32)pow(2,( bytecode & 0x07) + 8);
operand = result & 0xffff;
*start_offset = offset;
*value = operand;
offset ++;
}else{
test_bits = ( bytecode & 0x0e ) >> 1;
if ( test_bits == 3 ){
display_bytecode = bytecode & 0xfe;
if ( display_udvm_bytecode )
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_multitype_bytecode,
udvm_tvb, offset, 1, display_bytecode);
result = (guint32)pow(2,( bytecode & 0x01) + 6);
operand = result & 0xffff;
*start_offset = offset;
*value = operand;
offset ++;
}else{
display_bytecode = bytecode;
if ( display_udvm_bytecode )
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_multitype_bytecode,
udvm_tvb, offset, 1, display_bytecode);
if ( (bytecode & 0x01) == 1 )
*is_memory_address = TRUE;
offset ++;
operand = tvb_get_ntohs(udvm_tvb, offset);
*value = operand;
*start_offset = offset;
offset = offset +2;
}
}
}
}
break;
case 3:
test_bits = ( bytecode & 0x20 ) >> 5;
if ( test_bits == 1 ){
display_bytecode = bytecode & 0xe0;
if ( display_udvm_bytecode )
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_multitype_bytecode,
udvm_tvb, offset, 1, display_bytecode);
operand = ( bytecode & 0x1f) + 65504;
*start_offset = offset;
*value = operand;
offset ++;
}else{
display_bytecode = bytecode & 0xe0;
if ( display_udvm_bytecode )
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_multitype_bytecode,
udvm_tvb, offset, 1, display_bytecode);
operand = (tvb_get_ntohs(udvm_tvb, offset) & 0x1fff);
*is_memory_address = TRUE;
*start_offset = offset;
*value = operand;
offset = offset +2;
}
default :
break;
}
return offset;
}
static void
tvb_raw_text_add(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree *raw_tree = NULL;
proto_item *ti = NULL;
int offset, next_offset, linelen;
if(tree) {
ti = proto_tree_add_item(tree, proto_raw_sigcomp, tvb, 0, -1, ENC_NA);
raw_tree = proto_item_add_subtree(ti, ett_raw_text);
}
offset = 0;
while (tvb_offset_exists(tvb, offset)) {
tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
linelen = next_offset - offset;
if(raw_tree) {
proto_tree_add_text(raw_tree, tvb, offset, linelen,
"%s", tvb_format_text(tvb, offset, linelen));
}
offset = next_offset;
}
}
void
proto_register_sigcomp(void)
{
void proto_reg_handoff_sigcomp(void);
static hf_register_info hf[] = {
{ &hf_sigcomp_t_bit,
{ "T bit", "sigcomp.t.bit",
FT_UINT8, BASE_DEC, NULL, 0x04,
"Sigcomp T bit", HFILL }
},
{ &hf_sigcomp_len,
{ "Partial state id length","sigcomp.length",
FT_UINT8, BASE_HEX, VALS(length_encoding_vals), 0x03,
"Sigcomp length", HFILL }
},
{ &hf_sigcomp_returned_feedback_item,
{ "Returned_feedback item", "sigcomp.returned.feedback.item",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Returned feedback item", HFILL }
},
{ &hf_sigcomp_partial_state,
{ "Partial state identifier", "sigcomp.partial.state.identifier",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sigcomp_remaining_message_bytes,
{ "Remaining SigComp message bytes", "sigcomp.remaining-bytes",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of bytes remaining in message", HFILL }
},
{ &hf_sigcomp_compression_ratio,
{ "Compression ratio (%)", "sigcomp.compression-ratio",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Compression ratio (decompressed / compressed) %", HFILL }
},
{ &hf_sigcomp_returned_feedback_item_len,
{ "Returned feedback item length", "sigcomp.returned.feedback.item.len",
FT_UINT8, BASE_DEC, NULL, 0x7f,
NULL, HFILL }
},
{ &hf_sigcomp_code_len,
{ "Code length","sigcomp.code.len",
FT_UINT16, BASE_HEX, NULL, 0xfff0,
NULL, HFILL }
},
{ &hf_sigcomp_destination,
{ "Destination","sigcomp.destination",
FT_UINT8, BASE_HEX, VALS(destination_address_encoding_vals), 0xf,
NULL, HFILL }
},
{ &hf_sigcomp_udvm_bytecode,
{ "Uploaded UDVM bytecode","sigcomp.udvm.byte-code",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sigcomp_udvm_instr,
{ "UDVM instruction code","sigcomp.udvm.instr",
FT_UINT8, BASE_DEC, VALS(udvm_instruction_code_vals), 0x0,
NULL, HFILL }
},
{ &hf_udvm_execution_trace,
{ "UDVM execution trace","sigcomp.udvm.execution-trace",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_udvm_multitype_bytecode,
{ "UDVM bytecode", "sigcomp.udvm.multyt.bytecode",
FT_UINT8, BASE_HEX, VALS(display_bytecode_vals), 0x0,
NULL, HFILL }
},
{ &hf_udvm_reference_bytecode,
{ "UDVM bytecode", "sigcomp.udvm.ref.bytecode",
FT_UINT8, BASE_HEX, VALS(display_ref_bytecode_vals), 0x0,
NULL, HFILL }
},
{ &hf_udvm_literal_bytecode,
{ "UDVM bytecode", "sigcomp.udvm.lit.bytecode",
FT_UINT8, BASE_HEX, VALS(display_lit_bytecode_vals), 0x0,
NULL, HFILL }
},
#if 0
{ &hf_udvm_operand,
{ "UDVM operand", "sigcomp.udvm.operand",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_udvm_length,
{ "%Length", "sigcomp.udvm.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length", HFILL }
},
{ &hf_udvm_addr_length,
{ "%Length[memory address]", "sigcomp.udvm.addr.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length", HFILL }
},
{ &hf_udvm_destination,
{ "%Destination", "sigcomp.udvm.destination",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Destination", HFILL }
},
{ &hf_udvm_addr_destination,
{ "%Destination[memory address]", "sigcomp.udvm.addr.destination",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Destination", HFILL }
},
{ &hf_udvm_at_address,
{ "@Address(mem_add_of_inst + D) mod 2^16)", "sigcomp.udvm.at.address",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Address", HFILL }
},
{ &hf_udvm_address,
{ "%Address", "sigcomp.udvm.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Address", HFILL }
},
{ &hf_udvm_literal_num,
{ "#n", "sigcomp.udvm.literal-num",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Literal number", HFILL }
},
{ &hf_udvm_value,
{ "%Value", "sigcomp.udvm.value",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Value", HFILL }
},
{ &hf_udvm_addr_value,
{ "%Value[memory address]", "sigcomp.udvm.value",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Value", HFILL }
},
{ &hf_partial_identifier_start,
{ "%Partial identifier start", "sigcomp.udvm.partial.identifier.start",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Partial identifier start", HFILL }
},
{ &hf_partial_identifier_length,
{ "%Partial identifier length", "sigcomp.udvm.partial.identifier.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Partial identifier length", HFILL }
},
{ &hf_state_begin,
{ "%State begin", "sigcomp.udvm.state.begin",
FT_UINT16, BASE_DEC, NULL, 0x0,
"State begin", HFILL }
},
{ &hf_udvm_state_length,
{ "%State length", "sigcomp.udvm.state.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"State length", HFILL }
},
{ &hf_udvm_state_length_addr,
{ "%State length[memory address]", "sigcomp.udvm.state.length.addr",
FT_UINT16, BASE_DEC, NULL, 0x0,
"State length", HFILL }
},
{ &hf_udvm_state_address,
{ "%State address", "sigcomp.udvm.start.address",
FT_UINT16, BASE_DEC, NULL, 0x0,
"State address", HFILL }
},
{ &hf_udvm_state_address_addr,
{ "%State address[memory address]", "sigcomp.udvm.start.address.addr",
FT_UINT16, BASE_DEC, NULL, 0x0,
"State address", HFILL }
},
{ &hf_udvm_state_instr,
{ "%State instruction", "sigcomp.udvm.start.instr",
FT_UINT16, BASE_DEC, NULL, 0x0,
"State instruction", HFILL }
},
{ &hf_udvm_operand_1,
{ "$Operand 1[memory address]", "sigcomp.udvm.operand.1",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Reference $ Operand 1", HFILL }
},
{ &hf_udvm_operand_2,
{ "%Operand 2", "sigcomp.udvm.operand.2",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Operand 2", HFILL }
},
{ &hf_udvm_operand_2_addr,
{ "%Operand 2[memory address]", "sigcomp.udvm.operand.2.addr",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Operand 2", HFILL }
},
{ &hf_udvm_j,
{ "%j", "sigcomp.udvm.j",
FT_UINT16, BASE_DEC, NULL, 0x0,
"j", HFILL }
},
{ &hf_udvm_addr_j,
{ "%j[memory address]", "sigcomp.udvm.addr.j",
FT_UINT16, BASE_DEC, NULL, 0x0,
"j", HFILL }
},
{ &hf_udvm_output_start,
{ "%Output_start", "sigcomp.output.start",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Output start", HFILL }
},
{ &hf_udvm_addr_output_start,
{ "%Output_start[memory address]", "sigcomp.addr.output.start",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Output start", HFILL }
},
{ &hf_udvm_output_length,
{ "%Output_length", "sigcomp.output.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Output length", HFILL }
},
{ &hf_udvm_output_length_addr,
{ "%Output_length[memory address]", "sigcomp.output.length.addr",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Output length", HFILL }
},
{ &hf_udvm_req_feedback_loc,
{ "%Requested feedback location", "sigcomp.req.feedback.loc",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Requested feedback location", HFILL }
},
{ &hf_udvm_min_acc_len,
{ "%Minimum access length", "sigcomp.min.acc.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Minimum access length", HFILL }
},
{ &hf_udvm_state_ret_pri,
{ "%State retention priority", "sigcomp.udvm.state.ret.pri",
FT_UINT16, BASE_DEC, NULL, 0x0,
"State retention priority", HFILL }
},
{ &hf_udvm_ret_param_loc,
{ "%Returned parameters location", "sigcomp.ret.param.loc",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Returned parameters location", HFILL }
},
{ &hf_udvm_position,
{ "%Position", "sigcomp.udvm.position",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Position", HFILL }
},
{ &hf_udvm_ref_dest,
{ "$Destination[memory address]", "sigcomp.udvm.ref.destination",
FT_UINT16, BASE_DEC, NULL, 0x0,
"(reference)Destination", HFILL }
},
{ &hf_udvm_bits,
{ "%Bits", "sigcomp.udvm.bits",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Bits", HFILL }
},
{ &hf_udvm_lower_bound,
{ "%Lower bound", "sigcomp.udvm.lower.bound",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Lower_bound", HFILL }
},
{ &hf_udvm_upper_bound,
{ "%Upper bound", "sigcomp.udvm.upper.bound",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Upper bound", HFILL }
},
{ &hf_udvm_uncompressed,
{ "%Uncompressed", "sigcomp.udvm.uncompressed",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Uncompressed", HFILL }
},
{ &hf_udvm_start_value,
{ "%Start value", "sigcomp.udvm.start.value",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Start value", HFILL }
},
{ &hf_udvm_offset,
{ "%Offset", "sigcomp.udvm.offset",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Offset", HFILL }
},
{ &hf_udvm_addr_offset,
{ "%Offset[memory address]", "sigcomp.udvm.addr.offset",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Offset", HFILL }
},
{ &hf_sigcomp_nack_ver,
{ "NACK Version", "sigcomp.nack.ver",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_sigcomp_nack_reason_code,
{ "Reason Code", "sigcomp.nack.reason",
FT_UINT8, BASE_DEC, VALS(sigcomp_nack_reason_code_vals), 0x0,
"NACK Reason Code", HFILL }
},
{ &hf_sigcomp_nack_failed_op_code,
{ "OPCODE of failed instruction", "sigcomp.nack.failed_op_code",
FT_UINT8, BASE_DEC, VALS(udvm_instruction_code_vals), 0x0,
"NACK OPCODE of failed instruction", HFILL }
},
{ &hf_sigcomp_nack_pc,
{ "PC of failed instruction", "sigcomp.nack.pc",
FT_UINT16, BASE_DEC, NULL, 0x0,
"NACK PC of failed instruction", HFILL }
},
{ &hf_sigcomp_nack_sha1,
{ "SHA-1 Hash of failed message", "sigcomp.nack.sha1",
FT_BYTES, BASE_NONE, NULL, 0x0,
"NACK SHA-1 Hash of failed message", HFILL }
},
{ &hf_sigcomp_nack_state_id,
{ "State ID (6 - 20 bytes)", "sigcomp.nack.state_id",
FT_BYTES, BASE_NONE, NULL, 0x0,
"NACK State ID (6 - 20 bytes)", HFILL }
},
{ &hf_sigcomp_nack_cycles_per_bit,
{ "Cycles Per Bit", "sigcomp.nack.cycles_per_bit",
FT_UINT8, BASE_DEC, NULL, 0x0,
"NACK Cycles Per Bit", HFILL }
},
{ &hf_sigcomp_nack_memory_size,
{ "Memory size", "sigcomp.memory_size",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_sigcomp,
&ett_sigcomp_udvm,
&ett_sigcomp_udvm_exe,
};
static gint *ett_raw[] = {
&ett_raw_text,
};
static ei_register_info ei[] = {
{ &ei_sigcomp_nack_failed_op_code, { "sigcomp.nack.failed_op_code.expert", PI_SEQUENCE, PI_WARN, "SigComp NACK", EXPFILL }},
};
module_t *sigcomp_module;
expert_module_t* expert_sigcomp;
static const enum_val_t udvm_detail_vals[] = {
{"no-printout", "No-Printout", 0},
{"low-detail", "Low-detail", 1},
{"medium-detail", "Medium-detail", 2},
{"high-detail", "High-detail", 3},
{NULL, NULL, -1}
};
proto_sigcomp = proto_register_protocol("Signaling Compression",
"SIGCOMP", "sigcomp");
proto_raw_sigcomp = proto_register_protocol("Decompressed SigComp message as raw text",
"Raw_SigComp", "raw_sigcomp");
new_register_dissector("sigcomp", dissect_sigcomp, proto_sigcomp);
proto_register_field_array(proto_sigcomp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
proto_register_subtree_array(ett_raw, array_length(ett_raw));
expert_sigcomp = expert_register_protocol(proto_sigcomp);
expert_register_field_array(expert_sigcomp, ei, array_length(ei));
sigcomp_module = prefs_register_protocol(proto_sigcomp,
proto_reg_handoff_sigcomp);
prefs_register_uint_preference(sigcomp_module, "udp.port",
"Sigcomp UDP Port 1",
"Set UDP port 1 for SigComp messages",
10,
&SigCompUDPPort1);
prefs_register_uint_preference(sigcomp_module, "udp.port2",
"Sigcomp UDP Port 2",
"Set UDP port 2 for SigComp messages",
10,
&SigCompUDPPort2);
prefs_register_uint_preference(sigcomp_module, "tcp.port",
"Sigcomp TCP Port 1",
"Set TCP port 1 for SigComp messages",
10,
&SigCompTCPPort1);
prefs_register_uint_preference(sigcomp_module, "tcp.port2",
"Sigcomp TCP Port 2",
"Set TCP port 2 for SigComp messages",
10,
&SigCompTCPPort2);
prefs_register_bool_preference(sigcomp_module, "display.udvm.code",
"Dissect the UDVM code",
"Preference whether to Dissect the UDVM code or not",
&dissect_udvm_code);
prefs_register_bool_preference(sigcomp_module, "display.bytecode",
"Display the bytecode of operands",
"preference whether to display the bytecode in "
"UDVM operands or not",
&display_udvm_bytecode);
prefs_register_bool_preference(sigcomp_module, "decomp.msg",
"Decompress message",
"preference whether to decompress message or not",
&decompress);
prefs_register_bool_preference(sigcomp_module, "display.decomp.msg.as.txt",
"Displays the decompressed message as text",
"preference whether to display the decompressed message "
"as raw text or not",
&display_raw_txt);
prefs_register_enum_preference(sigcomp_module, "show.udvm.execution",
"Level of detail of UDVM execution:",
"'No-Printout' = UDVM executes silently, then increasing detail "
"about execution of UDVM instructions; "
"Warning! CPU intense at high detail",
&udvm_print_detail_level, udvm_detail_vals, FALSE);
register_init_routine(&sigcomp_init_protocol);
}
void
proto_reg_handoff_sigcomp(void)
{
static dissector_handle_t sigcomp_handle;
static dissector_handle_t sigcomp_tcp_handle;
static gboolean Initialized=FALSE;
static guint udp_port1;
static guint udp_port2;
static guint tcp_port1;
static guint tcp_port2;
if (!Initialized) {
sigcomp_handle = find_dissector("sigcomp");
sigcomp_tcp_handle = new_create_dissector_handle(dissect_sigcomp_tcp,proto_sigcomp);
sip_handle = find_dissector("sip");
Initialized=TRUE;
}else{
dissector_delete_uint("udp.port", udp_port1, sigcomp_handle);
dissector_delete_uint("udp.port", udp_port2, sigcomp_handle);
dissector_delete_uint("tcp.port", tcp_port1, sigcomp_tcp_handle);
dissector_delete_uint("tcp.port", tcp_port2, sigcomp_tcp_handle);
}
udp_port1 = SigCompUDPPort1;
udp_port2 = SigCompUDPPort2;
tcp_port1 = SigCompTCPPort1;
tcp_port2 = SigCompTCPPort2;
dissector_add_uint("udp.port", SigCompUDPPort1, sigcomp_handle);
dissector_add_uint("udp.port", SigCompUDPPort2, sigcomp_handle);
dissector_add_uint("tcp.port", SigCompTCPPort1, sigcomp_tcp_handle);
dissector_add_uint("tcp.port", SigCompTCPPort2, sigcomp_tcp_handle);
}
