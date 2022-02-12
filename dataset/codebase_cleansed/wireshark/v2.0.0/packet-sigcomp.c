static void
sigcomp_init_udvm(void) {
gchar *partial_state_str;
guint8 *sip_sdp_buff, *presence_buff;
state_buffer_table = g_hash_table_new_full(g_str_hash,
g_str_equal,
g_free,
g_free);
sip_sdp_buff = (guint8 *)g_malloc(SIP_SDP_STATE_LENGTH + 8);
partial_state_str = bytes_to_str(NULL, sip_sdp_state_identifier, 6);
memset(sip_sdp_buff, 0, 8);
sip_sdp_buff[0] = SIP_SDP_STATE_LENGTH >> 8;
sip_sdp_buff[1] = SIP_SDP_STATE_LENGTH & 0xff;
memcpy(sip_sdp_buff+8, sip_sdp_static_dictionaty_for_sigcomp, SIP_SDP_STATE_LENGTH);
g_hash_table_insert(state_buffer_table, g_strdup(partial_state_str), sip_sdp_buff);
wmem_free(NULL, partial_state_str);
presence_buff = (guint8 *)g_malloc(PRESENCE_STATE_LENGTH + 8);
partial_state_str = bytes_to_str(NULL, presence_state_identifier, 6);
memset(presence_buff, 0, 8);
presence_buff[0] = PRESENCE_STATE_LENGTH >> 8;
presence_buff[1] = PRESENCE_STATE_LENGTH & 0xff;
memcpy(presence_buff+8, presence_static_dictionary_for_sigcomp, PRESENCE_STATE_LENGTH);
g_hash_table_insert(state_buffer_table, g_strdup(partial_state_str), presence_buff);
wmem_free(NULL, partial_state_str);
}
static void
sigcomp_cleanup_udvm(void) {
g_hash_table_destroy(state_buffer_table);
}
static int udvm_state_access(tvbuff_t *tvb, proto_tree *tree,guint8 *buff,guint16 p_id_start, guint16 p_id_length, guint16 state_begin, guint16 *state_length,
guint16 *state_address, guint16 *state_instruction,
gint hf_id)
{
int result_code = 0;
guint32 n;
guint16 k;
guint16 buf_size_real;
guint16 byte_copy_right;
guint16 byte_copy_left;
char partial_state[STATE_BUFFER_SIZE];
guint8 *state_buff;
gchar *partial_state_str;
if (( p_id_length < STATE_MIN_ACCESS_LEN ) || ( p_id_length > STATE_BUFFER_SIZE )) {
result_code = 1;
return result_code;
}
n = 0;
while ( n < p_id_length && n < STATE_BUFFER_SIZE && p_id_start + n < UDVM_MEMORY_SIZE ) {
partial_state[n] = buff[p_id_start + n];
n++;
}
partial_state_str = bytes_to_str(wmem_packet_scope(), partial_state, p_id_length);
proto_tree_add_item(tree, hf_sigcomp_accessing_state, tvb, 0, -1, ENC_NA);
proto_tree_add_string(tree,hf_id, tvb, 0, 0, partial_state_str);
state_buff = (guint8 *)g_hash_table_lookup(state_buffer_table, partial_state_str);
if ( state_buff == NULL ) {
result_code = 2;
return result_code;
}
buf_size_real = (state_buff[0] << 8) | state_buff[1];
if (*state_length == 0) {
*state_length = buf_size_real;
}
if ( *state_address == 0 ) {
*state_address = state_buff[2] << 8;
*state_address = *state_address | state_buff[3];
}
if ( *state_instruction == 0 ) {
*state_instruction = state_buff[4] << 8;
*state_instruction = *state_instruction | state_buff[5];
}
if ((state_begin + *state_length) > buf_size_real) {
return 3;
}
if (*state_length == 0 && state_begin != 0) {
return 17;
}
n = state_begin + 8;
k = *state_address;
byte_copy_right = buff[66] << 8;
byte_copy_right = byte_copy_right | buff[67];
byte_copy_left = buff[64] << 8;
byte_copy_left = byte_copy_left | buff[65];
while ( (gint32) n < (state_begin + *state_length + 8) && n < UDVM_MEMORY_SIZE ) {
buff[k] = state_buff[n];
k = ( k + 1 ) & 0xffff;
if ( k == byte_copy_right ) {
k = byte_copy_left;
}
n++;
}
return 0;
}
static void udvm_state_create(guint8 *state_buff,guint8 *state_identifier,guint16 p_id_length) {
char partial_state[STATE_BUFFER_SIZE];
guint i;
gchar *partial_state_str;
gchar *dummy_buff;
i = 0;
while ( i < p_id_length && i < STATE_BUFFER_SIZE ) {
partial_state[i] = state_identifier[i];
i++;
}
partial_state_str = bytes_to_str(NULL, partial_state, p_id_length);
dummy_buff = (gchar *)g_hash_table_lookup(state_buffer_table, partial_state_str);
if ( dummy_buff == NULL ) {
g_hash_table_insert(state_buffer_table, g_strdup(partial_state_str), state_buff);
} else {
g_free(state_buff);
}
wmem_free(NULL, partial_state_str);
}
static void udvm_state_free(guint8 buff[] _U_,guint16 p_id_start _U_,guint16 p_id_length _U_) {
}
void udvm_state_free(guint8 buff[],guint16 p_id_start,guint16 p_id_length) {
char partial_state[STATE_BUFFER_SIZE];
guint i;
gchar *partial_state_str;
gchar *dummy_buff;
i = 0;
while ( i < p_id_length && i < STATE_BUFFER_SIZE && p_id_start + i < UDVM_MEMORY_SIZE ) {
partial_state[i] = buff[p_id_start + i];
i++;
}
partial_state_str = bytes_to_str(NULL, partial_state, p_id_length);
dummy_buff = g_hash_table_lookup(state_buffer_table, partial_state_str);
if ( dummy_buff != NULL ) {
g_hash_table_remove (state_buffer_table, partial_state_str);
g_free(dummy_buff);
}
wmem_free(NULL, partial_state_str);
}
static int
decode_udvm_literal_operand(guint8 *buff,guint operand_address, guint16 *value)
{
guint bytecode;
guint16 operand;
guint test_bits;
guint offset = operand_address;
guint8 temp_data;
bytecode = buff[operand_address];
test_bits = bytecode >> 7;
if (test_bits == 1) {
test_bits = bytecode >> 6;
if (test_bits == 2) {
temp_data = buff[operand_address] & 0x1f;
operand = temp_data << 8;
temp_data = buff[(operand_address + 1) & 0xffff];
operand = operand | temp_data;
*value = operand;
offset = offset + 2;
} else {
offset ++;
temp_data = buff[operand_address] & 0x1f;
operand = temp_data << 8;
temp_data = buff[(operand_address + 1) & 0xffff];
operand = operand | temp_data;
*value = operand;
offset = offset + 2;
}
} else {
operand = ( bytecode & 0x7f);
*value = operand;
offset ++;
}
return offset;
}
static int
dissect_udvm_reference_operand_memory(guint8 *buff,guint operand_address, guint16 *value,guint *result_dest)
{
guint bytecode;
guint16 operand;
guint offset = operand_address;
guint test_bits;
guint8 temp_data;
guint16 temp_data16;
bytecode = buff[operand_address];
test_bits = bytecode >> 7;
if (test_bits == 1) {
test_bits = bytecode >> 6;
if (test_bits == 2) {
temp_data = buff[operand_address] & 0x3f;
operand = temp_data << 8;
temp_data = buff[(operand_address + 1) & 0xffff];
operand = operand | temp_data;
operand = (operand * 2);
*result_dest = operand;
temp_data16 = buff[operand] << 8;
temp_data16 = temp_data16 | buff[(operand+1) & 0xffff];
*value = temp_data16;
offset = offset + 2;
} else {
operand_address++;
operand = buff[operand_address] << 8;
operand = operand | buff[(operand_address + 1) & 0xffff];
*result_dest = operand;
temp_data16 = buff[operand] << 8;
temp_data16 = temp_data16 | buff[(operand+1) & 0xffff];
*value = temp_data16;
offset = offset + 3;
}
} else {
operand = ( bytecode & 0x7f);
operand = (operand * 2);
*result_dest = operand;
temp_data16 = buff[operand] << 8;
temp_data16 = temp_data16 | buff[(operand+1) & 0xffff];
*value = temp_data16;
offset ++;
}
if (offset >= UDVM_MEMORY_SIZE || *result_dest >= UDVM_MEMORY_SIZE - 1 )
THROW(ReportedBoundsError);
return offset;
}
static int
decode_udvm_multitype_operand(guint8 *buff,guint operand_address, guint16 *value)
{
guint test_bits;
guint bytecode;
guint offset = operand_address;
guint16 operand;
guint32 result;
guint8 temp_data;
guint16 temp_data16;
guint16 memmory_addr = 0;
*value = 0;
bytecode = buff[operand_address];
test_bits = ( bytecode & 0xc0 ) >> 6;
switch (test_bits ) {
case 0:
operand = buff[operand_address];
*value = operand;
offset ++;
break;
case 1:
memmory_addr = ( bytecode & 0x3f) * 2;
temp_data16 = buff[memmory_addr] << 8;
temp_data16 = temp_data16 | buff[(memmory_addr+1) & 0xffff];
*value = temp_data16;
offset ++;
break;
case 2:
test_bits = ( bytecode & 0xe0 ) >> 5;
if ( test_bits == 5 ) {
temp_data = buff[operand_address] & 0x1f;
operand = temp_data << 8;
temp_data = buff[(operand_address + 1) & 0xffff];
operand = operand | temp_data;
*value = operand;
offset = offset + 2;
} else {
test_bits = ( bytecode & 0xf0 ) >> 4;
if ( test_bits == 9 ) {
temp_data = buff[operand_address] & 0x0f;
operand = temp_data << 8;
temp_data = buff[(operand_address + 1) & 0xffff];
operand = operand | temp_data;
operand = operand + 61440;
*value = operand;
offset = offset + 2;
} else {
test_bits = ( bytecode & 0x08 ) >> 3;
if ( test_bits == 1) {
result = 1 << ((buff[operand_address] & 0x07) + 8);
operand = result & 0xffff;
*value = operand;
offset ++;
} else {
test_bits = ( bytecode & 0x0e ) >> 1;
if ( test_bits == 3 ) {
result = 1 << ((buff[operand_address] & 0x01) + 6);
operand = result & 0xffff;
*value = operand;
offset ++;
} else {
offset ++;
temp_data16 = buff[(operand_address + 1) & 0xffff] << 8;
temp_data16 = temp_data16 | buff[(operand_address + 2) & 0xffff];
if ( (bytecode & 0x01) == 1 ) {
memmory_addr = temp_data16;
temp_data16 = buff[memmory_addr] << 8;
temp_data16 = temp_data16 | buff[(memmory_addr+1) & 0xffff];
}
*value = temp_data16;
offset = offset +2;
}
}
}
}
break;
case 3:
test_bits = ( bytecode & 0x20 ) >> 5;
if ( test_bits == 1 ) {
operand = ( buff[operand_address] & 0x1f) + 65504;
*value = operand;
offset ++;
} else {
memmory_addr = buff[operand_address] & 0x1f;
memmory_addr = memmory_addr << 8;
memmory_addr = memmory_addr | buff[(operand_address + 1) & 0xffff];
temp_data16 = buff[memmory_addr] << 8;
temp_data16 = temp_data16 | buff[(memmory_addr+1) & 0xffff];
*value = temp_data16;
offset = offset +2;
}
default :
break;
}
return offset;
}
static int
decode_udvm_address_operand(guint8 *buff,guint operand_address, guint16 *value,guint current_address)
{
guint32 result;
guint16 value1;
guint next_opreand_address;
next_opreand_address = decode_udvm_multitype_operand(buff, operand_address, &value1);
result = value1 & 0xffff;
result = result + current_address;
*value = result & 0xffff;
return next_opreand_address;
}
static int
decomp_dispatch_get_bits(
tvbuff_t *message_tvb,
proto_tree *udvm_tree,
guint8 bit_order,
guint8 *buff,
guint16 *old_input_bit_order,
guint16 *remaining_bits,
guint16 *input_bits,
guint *input_address,
guint16 length,
guint16 *result_code,
guint msg_end,
gboolean print_level_1)
{
guint16 input_bit_order;
guint16 bits_still_required = length;
guint16 value = 0;
guint8 octet;
gint extra_bytes_available = msg_end - *input_address;
gint p_bit;
gint prev_p_bit = *old_input_bit_order & 0x0001;
gint bits_to_use = 0;
input_bit_order = buff[68] << 8;
input_bit_order = input_bit_order | buff[69];
*result_code = 0;
p_bit = (input_bit_order & 0x0001) != 0;
if (prev_p_bit != p_bit)
{
*remaining_bits = 0;
*old_input_bit_order = input_bit_order;
}
if (*remaining_bits + extra_bytes_available * 8 < length)
{
*result_code = 11;
return 0xfbad;
}
while (bits_still_required > 0)
{
if (*remaining_bits == 0)
{
octet = tvb_get_guint8(message_tvb, *input_address);
if (print_level_1 ) {
proto_tree_add_uint_format(udvm_tree, hf_sigcomp_getting_value, message_tvb, *input_address, 1, octet,
" Getting value: %u (0x%x) From Addr: %u", octet, octet, *input_address);
}
*input_address = *input_address + 1;
if (p_bit != 0)
{
octet = reverse[octet];
}
*input_bits = octet;
*remaining_bits = 8;
}
bits_to_use = bits_still_required < *remaining_bits ? bits_still_required : *remaining_bits;
bits_still_required -= bits_to_use;
*input_bits <<= bits_to_use;
value = (value << bits_to_use)
| ((*input_bits >> 8) & 0xFF);
*remaining_bits -= bits_to_use;
*input_bits &= 0x00FF;
}
if (bit_order != 0)
{
guint16 lsb = reverse[(value >> 8) & 0xFF];
guint16 msb = reverse[value & 0xFF];
value = ((msb << 8) | lsb) >> (16 - length);
}
return value;
}
static tvbuff_t*
decompress_sigcomp_message(tvbuff_t *bytecode_tvb, tvbuff_t *message_tvb, packet_info *pinfo,
proto_tree *udvm_tree, gint udvm_mem_dest,
gint print_flags, gint hf_id,
gint header_len,
gint byte_code_state_len, gint byte_code_id_len,
gint udvm_start_ip)
{
tvbuff_t *decomp_tvb;
guint8 *buff = (guint8 *)wmem_alloc0(wmem_packet_scope(), UDVM_MEMORY_SIZE);
char string[2];
guint8 *out_buff;
guint32 i = 0;
guint16 n = 0;
guint16 m = 0;
guint16 x;
guint k = 0;
guint16 H;
guint16 oldH;
guint offset = 0;
guint start_offset;
guint result_dest;
guint code_length = 0;
guint8 current_instruction;
guint current_address;
guint operand_address;
guint input_address;
guint16 output_address = 0;
guint next_operand_address;
guint8 octet;
guint8 msb;
guint8 lsb;
guint16 byte_copy_right;
guint16 byte_copy_left;
guint16 input_bit_order;
guint16 stack_location;
guint16 stack_fill;
guint16 result;
guint msg_end = tvb_reported_length_remaining(message_tvb, 0);
guint16 result_code = 0;
guint16 old_input_bit_order = 0;
guint16 remaining_bits = 0;
guint16 input_bits = 0;
guint8 bit_order = 0;
gboolean outside_huffman_boundaries = TRUE;
gboolean print_in_loop = FALSE;
guint16 instruction_address;
guint8 no_of_state_create = 0;
guint16 state_length_buff[5];
guint16 state_address_buff[5];
guint16 state_instruction_buff[5];
guint16 state_minimum_access_length_buff[5];
guint32 used_udvm_cycles = 0;
guint cycles_per_bit;
guint maximum_UDVM_cycles;
guint8 *sha1buff;
unsigned char sha1_digest_buf[STATE_BUFFER_SIZE];
sha1_context ctx;
proto_item *addr_item = NULL;
guint16 length;
guint16 at_address;
guint16 destination;
guint16 addr;
guint16 value;
guint16 p_id_start;
guint16 p_id_length;
guint16 state_begin;
guint16 state_length;
guint16 state_address;
guint16 state_instruction;
guint16 operand_1;
guint16 operand_2;
guint16 value_1;
guint16 value_2;
guint16 at_address_1;
guint16 at_address_2;
guint16 at_address_3;
guint16 j;
guint16 bits_n;
guint16 lower_bound_n;
guint16 upper_bound_n;
guint16 uncompressed_n;
guint16 position;
guint16 ref_destination;
guint16 multy_offset;
guint16 output_start;
guint16 output_length;
guint16 minimum_access_length;
guint16 state_retention_priority;
guint16 requested_feedback_location;
guint16 returned_parameters_location;
guint16 start_value;
gboolean print_level_1 = FALSE;
gboolean print_level_2 = FALSE;
gboolean print_level_3 = FALSE;
gint show_instr_detail_level = 0;
switch ( print_flags ) {
case 0:
break;
case 1:
print_level_1 = TRUE;
show_instr_detail_level = 1;
break;
case 2:
print_level_1 = TRUE;
print_level_2 = TRUE;
show_instr_detail_level = 1;
break;
case 3:
print_level_1 = TRUE;
print_level_2 = TRUE;
print_level_3 = TRUE;
show_instr_detail_level = 2;
break;
default:
print_level_1 = TRUE;
show_instr_detail_level = 1;
break;
}
buff[0] = (UDVM_MEMORY_SIZE >> 8) & 0x00FF;
buff[1] = UDVM_MEMORY_SIZE & 0x00FF;
buff[2] = 0;
buff[3] = 16;
buff[4] = 0;
buff[5] = 1;
buff[6] = (byte_code_id_len >> 8) & 0x00FF;
buff[7] = byte_code_id_len & 0x00FF;
buff[8] = (byte_code_state_len >> 8) & 0x00FF;
buff[9] = byte_code_state_len & 0x00FF;
code_length = tvb_reported_length_remaining(bytecode_tvb, 0);
cycles_per_bit = buff[2] << 8;
cycles_per_bit = cycles_per_bit | buff[3];
maximum_UDVM_cycles = (( 8 * (header_len + msg_end) ) + 1000) * cycles_per_bit;
proto_tree_add_uint(udvm_tree, hf_sigcomp_message_length, bytecode_tvb, offset, 1, msg_end);
proto_tree_add_uint(udvm_tree, hf_sigcomp_byte_code_length, bytecode_tvb, offset, 1, code_length);
proto_tree_add_uint(udvm_tree, hf_sigcomp_max_udvm_cycles, bytecode_tvb, offset, 1, maximum_UDVM_cycles);
i = udvm_mem_dest;
if ( print_level_3 )
proto_tree_add_uint(udvm_tree, hf_sigcomp_load_bytecode_into_udvm_start, bytecode_tvb, offset, 1, i);
while ( code_length > offset && i < UDVM_MEMORY_SIZE ) {
buff[i] = tvb_get_guint8(bytecode_tvb, offset);
if ( print_level_3 )
proto_tree_add_uint_format(udvm_tree, hf_sigcomp_instruction_code, bytecode_tvb, offset, 1, buff[i],
" Addr: %u Instruction code(0x%02x) ", i, buff[i]);
i++;
offset++;
}
current_address = udvm_start_ip;
input_address = 0;
proto_tree_add_uint_format(udvm_tree, hf_sigcomp_udvm_execution_stated, bytecode_tvb, offset, 1, current_address,
"UDVM EXECUTION STARTED at Address: %u Message size %u", current_address, msg_end);
out_buff = (guint8 *)g_malloc(UDVM_MEMORY_SIZE);
offset = 0;
execute_next_instruction:
if ( used_udvm_cycles > maximum_UDVM_cycles ) {
result_code = 15;
goto decompression_failure;
}
used_udvm_cycles++;
current_instruction = buff[current_address & 0xffff];
if (show_instr_detail_level == 2 ) {
addr_item = proto_tree_add_uint_format(udvm_tree, hf_sigcomp_current_instruction, bytecode_tvb, offset, 1, current_instruction,
"Addr: %u ## %s(%d)", current_address,
val_to_str_ext_const(current_instruction, &udvm_instruction_code_vals_ext, "INVALID INSTRUCTION"),
current_instruction);
}
offset++;
switch ( current_instruction ) {
case SIGCOMP_INSTR_DECOMPRESSION_FAILURE:
if ( result_code == 0 )
result_code = 9;
proto_tree_add_uint_format(udvm_tree, hf_sigcomp_decompression_failure, NULL, 0, 0,
current_address, "Addr: %u ## DECOMPRESSION-FAILURE(0)",
current_address);
proto_tree_add_uint(udvm_tree, hf_sigcomp_wireshark_udvm_diagnostic, NULL, 0, 0, result_code);
if ( output_address > 0 ) {
decomp_tvb = tvb_new_child_real_data(message_tvb, out_buff,output_address,output_address);
tvb_set_free_cb( decomp_tvb, g_free );
add_new_data_source(pinfo, decomp_tvb, "Decompressed SigComp message(Incomplete)");
proto_tree_add_expert(udvm_tree, pinfo, &ei_sigcomp_sigcomp_message_decompression_failure, decomp_tvb, 0, -1);
return decomp_tvb;
}
g_free(out_buff);
return NULL;
break;
case SIGCOMP_INSTR_AND:
if (show_instr_detail_level == 2 ) {
proto_item_append_text(addr_item, " (operand_1, operand_2)");
}
start_offset = offset;
operand_address = current_address + 1;
next_operand_address = dissect_udvm_reference_operand_memory(buff, operand_address, &operand_1, &result_dest);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_operand_1, bytecode_tvb, offset, (next_operand_address-operand_address), operand_1,
"Addr: %u operand_1 %u", operand_address, operand_1);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &operand_2);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_operand_2, bytecode_tvb, offset, (next_operand_address-operand_address), operand_2,
"Addr: %u operand_2 %u", operand_address, operand_2);
}
offset += (next_operand_address-operand_address);
if (show_instr_detail_level == 1)
{
proto_tree_add_none_format(udvm_tree, hf_sigcomp_decompress_instruction, bytecode_tvb, start_offset, offset-start_offset,
"Addr: %u ## AND (operand_1=%u, operand_2=%u)",
current_address, operand_1, operand_2);
}
result = operand_1 & operand_2;
lsb = result & 0xff;
msb = result >> 8;
buff[result_dest] = msb;
buff[(result_dest+1) & 0xffff] = lsb;
if (print_level_1 ) {
proto_tree_add_none_format(udvm_tree, hf_sigcomp_loading_result, bytecode_tvb, 0, -1,
" Loading result %u at %u", result, result_dest);
}
current_address = next_operand_address;
goto execute_next_instruction;
break;
case SIGCOMP_INSTR_OR:
if (show_instr_detail_level == 2 ) {
proto_item_append_text(addr_item, " (operand_1, operand_2)");
}
start_offset = offset;
operand_address = current_address + 1;
next_operand_address = dissect_udvm_reference_operand_memory(buff, operand_address, &operand_1, &result_dest);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_operand_1, bytecode_tvb, offset, (next_operand_address-operand_address), operand_1,
"Addr: %u operand_1 %u", operand_address, operand_1);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &operand_2);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_operand_2, bytecode_tvb, offset, (next_operand_address-operand_address), operand_2,
"Addr: %u operand_2 %u", operand_address, operand_2);
}
offset += (next_operand_address-operand_address);
if (show_instr_detail_level == 1)
{
proto_tree_add_none_format(udvm_tree, hf_sigcomp_decompress_instruction, bytecode_tvb, start_offset, offset-start_offset,
"Addr: %u ## OR (operand_1=%u, operand_2=%u)",
current_address, operand_1, operand_2);
}
result = operand_1 | operand_2;
lsb = result & 0xff;
msb = result >> 8;
buff[result_dest] = msb;
buff[(result_dest+1) & 0xffff] = lsb;
if (print_level_1 ) {
proto_tree_add_none_format(udvm_tree, hf_sigcomp_loading_result, bytecode_tvb, 0, -1,
" Loading result %u at %u", result, result_dest);
}
current_address = next_operand_address;
goto execute_next_instruction;
break;
case SIGCOMP_INSTR_NOT:
if (show_instr_detail_level == 2 ) {
proto_item_append_text(addr_item, " ($operand_1)");
}
start_offset = offset;
operand_address = current_address + 1;
next_operand_address = dissect_udvm_reference_operand_memory(buff, operand_address, &operand_1, &result_dest);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_operand_1, bytecode_tvb, offset, (next_operand_address-operand_address), operand_1,
"Addr: %u operand_1 %u", operand_address, operand_1);
}
offset += (next_operand_address-operand_address);
if (show_instr_detail_level == 1)
{
proto_tree_add_none_format(udvm_tree, hf_sigcomp_decompress_instruction, bytecode_tvb, start_offset, offset-start_offset,
"Addr: %u ## NOT (operand_1=%u)",
current_address, operand_1);
}
result = operand_1 ^ 0xffff;
lsb = result & 0xff;
msb = result >> 8;
buff[result_dest] = msb;
buff[(result_dest+1) & 0xffff] = lsb;
if (print_level_1 ) {
proto_tree_add_none_format(udvm_tree, hf_sigcomp_loading_result, bytecode_tvb, 0, -1,
" Loading result %u at %u", result, result_dest);
}
current_address = next_operand_address;
goto execute_next_instruction;
break;
case SIGCOMP_INSTR_LSHIFT:
if (show_instr_detail_level == 2 ) {
proto_item_append_text(addr_item, " ($operand_1, operand_2)");
}
start_offset = offset;
operand_address = current_address + 1;
next_operand_address = dissect_udvm_reference_operand_memory(buff, operand_address, &operand_1, &result_dest);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_operand_1, bytecode_tvb, offset, (next_operand_address-operand_address), operand_1,
"Addr: %u operand_1 %u", operand_address, operand_1);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &operand_2);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_operand_2, bytecode_tvb, offset, (next_operand_address-operand_address), operand_2,
"Addr: %u operand_2 %u", operand_address, operand_2);
}
offset += (next_operand_address-operand_address);
if (show_instr_detail_level == 1)
{
proto_tree_add_none_format(udvm_tree, hf_sigcomp_decompress_instruction, bytecode_tvb, start_offset, offset-start_offset,
"Addr: %u ## LSHIFT (operand_1=%u, operand_2=%u)",
current_address, operand_1, operand_2);
}
result = operand_1 << operand_2;
lsb = result & 0xff;
msb = result >> 8;
buff[result_dest] = msb;
buff[(result_dest+1) & 0xffff] = lsb;
if (print_level_1 ) {
proto_tree_add_none_format(udvm_tree, hf_sigcomp_loading_result, bytecode_tvb, 0, -1,
" Loading result %u at %u", result, result_dest);
}
current_address = next_operand_address;
goto execute_next_instruction;
break;
case SIGCOMP_INSTR_RSHIFT:
if (show_instr_detail_level == 2 ) {
proto_item_append_text(addr_item, " (operand_1, operand_2)");
}
start_offset = offset;
operand_address = current_address + 1;
next_operand_address = dissect_udvm_reference_operand_memory(buff, operand_address, &operand_1, &result_dest);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_operand_1, bytecode_tvb, offset, (next_operand_address-operand_address), operand_1,
"Addr: %u operand_1 %u", operand_address, operand_1);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &operand_2);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_operand_2, bytecode_tvb, offset, (next_operand_address-operand_address), operand_2,
"Addr: %u operand_2 %u", operand_address, operand_2);
}
offset += (next_operand_address-operand_address);
if (show_instr_detail_level == 1)
{
proto_tree_add_none_format(udvm_tree, hf_sigcomp_decompress_instruction, bytecode_tvb, start_offset, offset-start_offset,
"Addr: %u ## RSHIFT (operand_1=%u, operand_2=%u)",
current_address, operand_1, operand_2);
}
result = operand_1 >> operand_2;
lsb = result & 0xff;
msb = result >> 8;
buff[result_dest] = msb;
buff[(result_dest+1) & 0xffff] = lsb;
if (print_level_1 ) {
proto_tree_add_none_format(udvm_tree, hf_sigcomp_loading_result, bytecode_tvb, 0, -1,
" Loading result %u at %u", result, result_dest);
}
current_address = next_operand_address;
goto execute_next_instruction;
break;
case SIGCOMP_INSTR_ADD:
if (show_instr_detail_level == 2 ) {
proto_item_append_text(addr_item, " (operand_1, operand_2)");
}
start_offset = offset;
operand_address = current_address + 1;
next_operand_address = dissect_udvm_reference_operand_memory(buff, operand_address, &operand_1, &result_dest);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_operand_1, bytecode_tvb, offset, (next_operand_address-operand_address), operand_1,
"Addr: %u operand_1 %u", operand_address, operand_1);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &operand_2);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_operand_2, bytecode_tvb, offset, (next_operand_address-operand_address), operand_2,
"Addr: %u operand_2 %u", operand_address, operand_2);
}
offset += (next_operand_address-operand_address);
if (show_instr_detail_level == 1)
{
proto_tree_add_none_format(udvm_tree, hf_sigcomp_decompress_instruction, bytecode_tvb, start_offset, offset-start_offset,
"Addr: %u ## ADD (operand_1=%u, operand_2=%u)",
current_address, operand_1, operand_2);
}
result = operand_1 + operand_2;
lsb = result & 0xff;
msb = result >> 8;
buff[result_dest] = msb;
buff[(result_dest+1) & 0xffff] = lsb;
if (print_level_1 ) {
proto_tree_add_none_format(udvm_tree, hf_sigcomp_loading_result, bytecode_tvb, 0, -1,
" Loading result %u at %u", result, result_dest);
}
current_address = next_operand_address;
goto execute_next_instruction;
case SIGCOMP_INSTR_SUBTRACT:
if (show_instr_detail_level == 2 ) {
proto_item_append_text(addr_item, " (operand_1, operand_2)");
}
start_offset = offset;
operand_address = current_address + 1;
next_operand_address = dissect_udvm_reference_operand_memory(buff, operand_address, &operand_1, &result_dest);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_operand_1, bytecode_tvb, offset, (next_operand_address-operand_address), operand_1,
"Addr: %u operand_1 %u", operand_address, operand_1);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &operand_2);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_operand_2, bytecode_tvb, offset, (next_operand_address-operand_address), operand_2,
"Addr: %u operand_2 %u", operand_address, operand_2);
}
offset += (next_operand_address-operand_address);
if (show_instr_detail_level == 1)
{
proto_tree_add_none_format(udvm_tree, hf_sigcomp_decompress_instruction, bytecode_tvb, start_offset, offset-start_offset,
"Addr: %u ## SUBTRACT (operand_1=%u, operand_2=%u)",
current_address, operand_1, operand_2);
}
result = operand_1 - operand_2;
lsb = result & 0xff;
msb = result >> 8;
buff[result_dest] = msb;
buff[(result_dest+1) & 0xffff] = lsb;
if (print_level_1 ) {
proto_tree_add_none_format(udvm_tree, hf_sigcomp_loading_result, bytecode_tvb, 0, -1,
" Loading result %u at %u", result, result_dest);
}
current_address = next_operand_address;
goto execute_next_instruction;
break;
case SIGCOMP_INSTR_MULTIPLY:
if (show_instr_detail_level == 2 ) {
proto_item_append_text(addr_item, " (operand_1, operand_2)");
}
start_offset = offset;
operand_address = current_address + 1;
next_operand_address = dissect_udvm_reference_operand_memory(buff, operand_address, &operand_1, &result_dest);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_operand_1, bytecode_tvb, offset, (next_operand_address-operand_address), operand_1,
"Addr: %u operand_1 %u", operand_address, operand_1);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &operand_2);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_operand_2, bytecode_tvb, offset, (next_operand_address-operand_address), operand_2,
"Addr: %u operand_2 %u", operand_address, operand_2);
}
offset += (next_operand_address-operand_address);
if (show_instr_detail_level == 1)
{
proto_tree_add_none_format(udvm_tree, hf_sigcomp_decompress_instruction, bytecode_tvb, start_offset, offset-start_offset,
"Addr: %u ## MULTIPLY (operand_1=%u, operand_2=%u)",
current_address, operand_1, operand_2);
}
if ( operand_2 == 0) {
result_code = 4;
goto decompression_failure;
}
result = operand_1 * operand_2;
lsb = result & 0xff;
msb = result >> 8;
buff[result_dest] = msb;
buff[(result_dest+1) & 0xffff] = lsb;
if (print_level_1 ) {
proto_tree_add_none_format(udvm_tree, hf_sigcomp_loading_result, bytecode_tvb, 0, -1,
" Loading result %u at %u", result, result_dest);
}
current_address = next_operand_address;
goto execute_next_instruction;
break;
case SIGCOMP_INSTR_DIVIDE:
if (show_instr_detail_level == 2 ) {
proto_item_append_text(addr_item, " (operand_1, operand_2)");
}
start_offset = offset;
operand_address = current_address + 1;
next_operand_address = dissect_udvm_reference_operand_memory(buff, operand_address, &operand_1, &result_dest);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_operand_1, bytecode_tvb, offset, (next_operand_address-operand_address), operand_1,
"Addr: %u operand_1 %u", operand_address, operand_1);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &operand_2);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_operand_2, bytecode_tvb, offset, (next_operand_address-operand_address), operand_2,
"Addr: %u operand_2 %u", operand_address, operand_2);
}
offset += (next_operand_address-operand_address);
if (show_instr_detail_level == 1)
{
proto_tree_add_none_format(udvm_tree, hf_sigcomp_decompress_instruction, bytecode_tvb, start_offset, offset-start_offset,
"Addr: %u ## DIVIDE (operand_1=%u, operand_2=%u)",
current_address, operand_1, operand_2);
}
if ( operand_2 == 0) {
result_code = 4;
goto decompression_failure;
}
result = operand_1 / operand_2;
lsb = result & 0xff;
msb = result >> 8;
buff[result_dest] = msb;
buff[(result_dest+1) & 0xffff] = lsb;
if (print_level_1 ) {
proto_tree_add_none_format(udvm_tree, hf_sigcomp_loading_result, bytecode_tvb, 0, -1,
" Loading result %u at %u", result, result_dest);
}
current_address = next_operand_address;
goto execute_next_instruction;
break;
case SIGCOMP_INSTR_REMAINDER:
if (show_instr_detail_level == 2 ) {
proto_item_append_text(addr_item, " (operand_1, operand_2)");
}
start_offset = offset;
operand_address = current_address + 1;
next_operand_address = dissect_udvm_reference_operand_memory(buff, operand_address, &operand_1, &result_dest);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_operand_1, bytecode_tvb, offset, (next_operand_address-operand_address), operand_1,
"Addr: %u operand_1 %u", operand_address, operand_1);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &operand_2);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_operand_2, bytecode_tvb, offset, (next_operand_address-operand_address), operand_2,
"Addr: %u operand_2 %u", operand_address, operand_2);
}
offset += (next_operand_address-operand_address);
if (show_instr_detail_level == 1)
{
proto_tree_add_none_format(udvm_tree, hf_sigcomp_decompress_instruction, bytecode_tvb, start_offset, offset-start_offset,
"Addr: %u ## REMAINDER (operand_1=%u, operand_2=%u)",
current_address, operand_1, operand_2);
}
if ( operand_2 == 0) {
result_code = 4;
goto decompression_failure;
}
result = operand_1 - operand_2 * (operand_1 / operand_2);
lsb = result & 0xff;
msb = result >> 8;
buff[result_dest] = msb;
buff[(result_dest+1) & 0xffff] = lsb;
if (print_level_1 ) {
proto_tree_add_none_format(udvm_tree, hf_sigcomp_loading_result, bytecode_tvb, 0, -1,
" Loading result %u at %u", result, result_dest);
}
current_address = next_operand_address;
goto execute_next_instruction;
break;
case SIGCOMP_INSTR_SORT_ASCENDING:
if (show_instr_detail_level == 2 ) {
proto_item_append_text(addr_item, " (start, n, k))");
}
proto_tree_add_expert(udvm_tree, pinfo, &ei_sigcomp_execution_of_this_instruction_is_not_implemented, bytecode_tvb, 0, -1);
break;
case SIGCOMP_INSTR_SORT_DESCENDING:
if (show_instr_detail_level == 2 ) {
proto_item_append_text(addr_item, " (start, n, k))");
}
proto_tree_add_expert(udvm_tree, pinfo, &ei_sigcomp_execution_of_this_instruction_is_not_implemented, bytecode_tvb, 0, -1);
break;
case SIGCOMP_INSTR_SHA_1:
if (show_instr_detail_level == 2 ) {
proto_item_append_text(addr_item, " (position, length, destination)");
}
operand_address = current_address + 1;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &position);
if (print_level_1 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_position, bytecode_tvb, offset, (next_operand_address-operand_address), position,
"Addr: %u position %u", operand_address, position);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &length);
if (print_level_1 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_length, bytecode_tvb, offset, (next_operand_address-operand_address), length,
"Addr: %u Length %u", operand_address, length);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = dissect_udvm_reference_operand_memory(buff, operand_address, &ref_destination, &result_dest);
if (print_level_1 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_ref_dest, bytecode_tvb, offset, (next_operand_address-operand_address), ref_destination,
"Addr: %u $destination %u", operand_address, ref_destination);
}
offset += (next_operand_address-operand_address);
used_udvm_cycles = used_udvm_cycles + length;
n = 0;
k = position;
byte_copy_right = buff[66] << 8;
byte_copy_right = byte_copy_right | buff[67];
byte_copy_left = buff[64] << 8;
byte_copy_left = byte_copy_left | buff[65];
if (print_level_2 ) {
proto_tree_add_bytes_format(udvm_tree, hf_sigcomp_byte_copy, message_tvb, 0, -1,
NULL, "byte_copy_right = %u", byte_copy_right);
}
sha1_starts( &ctx );
while (n<length) {
guint16 handle_now = length;
if ( k < byte_copy_right && byte_copy_right <= k + (length-n) ) {
handle_now = byte_copy_right - position;
}
if (k + handle_now >= UDVM_MEMORY_SIZE)
goto decompression_failure;
sha1_update( &ctx, &buff[k], handle_now );
k = ( k + handle_now ) & 0xffff;
n = ( n + handle_now ) & 0xffff;
if ( k >= byte_copy_right ) {
k = byte_copy_left;
}
}
sha1_finish( &ctx, sha1_digest_buf );
k = ref_destination;
for ( n=0; n< STATE_BUFFER_SIZE; n++ ) {
buff[k] = sha1_digest_buf[n];
k = ( k + 1 ) & 0xffff;
n++;
if ( k == byte_copy_right ) {
k = byte_copy_left;
}
}
if (print_level_2 ) {
proto_tree_add_bytes_with_length(udvm_tree, hf_sigcomp_calculated_sha_1, message_tvb, 0, -1,
sha1_digest_buf, STATE_BUFFER_SIZE);
}
current_address = next_operand_address;
goto execute_next_instruction;
break;
case SIGCOMP_INSTR_LOAD:
if (show_instr_detail_level == 2 ) {
proto_item_append_text(addr_item, " (%%address, %%value)");
}
start_offset = offset;
operand_address = current_address + 1;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &addr);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_address, bytecode_tvb, offset, (next_operand_address-operand_address), addr,
"Addr: %u Address %u", operand_address, addr);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &value);
if (show_instr_detail_level == 2)
{
proto_tree_add_uint_format(udvm_tree, hf_udvm_value, bytecode_tvb, offset, (next_operand_address-operand_address), value,
"Addr: %u Value %u", operand_address, value);
}
offset += (next_operand_address-operand_address);
lsb = value & 0xff;
msb = value >> 8;
buff[addr] = msb;
buff[(addr + 1) & 0xffff] = lsb;
if (print_level_1 ) {
proto_tree_add_none_format(udvm_tree, hf_sigcomp_decompress_instruction, bytecode_tvb, start_offset, offset-start_offset,
"Addr: %u ## LOAD (%%address=%u, %%value=%u)",
current_address, addr, value);
proto_tree_add_none_format(udvm_tree, hf_sigcomp_loading_result, bytecode_tvb, 0, -1,
" Loading bytes at %u Value %u 0x%x", addr, value, value);
}
current_address = next_operand_address;
goto execute_next_instruction;
break;
case SIGCOMP_INSTR_MULTILOAD:
if (show_instr_detail_level == 2 ) {
proto_item_append_text(addr_item, " (%%address, #n, value_0, ..., value_n-1)");
}
start_offset = offset;
operand_address = current_address + 1;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &addr);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_address, bytecode_tvb, offset, (next_operand_address-operand_address), addr,
"Addr: %u Address %u", operand_address, addr);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_literal_operand(buff,operand_address, &n);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_literal_num, bytecode_tvb, offset, (next_operand_address-operand_address), n,
"Addr: %u n %u", operand_address, n);
}
offset += (next_operand_address-operand_address);
if (show_instr_detail_level == 1)
{
proto_tree_add_none_format(udvm_tree, hf_sigcomp_decompress_instruction, bytecode_tvb, start_offset, offset-start_offset,
"Addr: %u ## MULTILOAD (%%address=%u, #n=%u, value_0, ..., value_%d)",
current_address, addr, n, n-1);
}
operand_address = next_operand_address;
used_udvm_cycles = used_udvm_cycles + n;
while ( n > 0) {
n = n - 1;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &value);
lsb = value & 0xff;
msb = value >> 8;
if (addr >= UDVM_MEMORY_SIZE - 1)
goto decompression_failure;
buff[addr] = msb;
buff[(addr + 1) & 0xffff] = lsb;
length = next_operand_address - operand_address;
if (print_level_1 ) {
proto_tree_add_none_format(udvm_tree, hf_sigcomp_loading_result, bytecode_tvb, 0, -1,
"Addr: %u Value %5u - Loading bytes at %5u Value %5u 0x%x", operand_address, value, addr, value, value);
}
addr = addr + 2;
operand_address = next_operand_address;
}
current_address = next_operand_address;
goto execute_next_instruction;
break;
case SIGCOMP_INSTR_PUSH:
if (show_instr_detail_level == 2) {
proto_item_append_text(addr_item, " (value)");
}
start_offset = offset;
operand_address = current_address + 1;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &value);
if (show_instr_detail_level == 2) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_value, bytecode_tvb, offset, (next_operand_address-operand_address), value,
"Addr: %u Value %u", operand_address, value);
}
offset += (next_operand_address-operand_address);
if (show_instr_detail_level == 1)
{
proto_tree_add_none_format(udvm_tree, hf_sigcomp_decompress_instruction, bytecode_tvb, start_offset, offset-start_offset,
"Addr: %u ## PUSH (value=%u)",
current_address, value);
}
current_address = next_operand_address;
stack_location = (buff[70] << 8) | buff[71];
stack_fill = (buff[stack_location] << 8)
| buff[(stack_location+1) & 0xFFFF];
addr = (stack_location + stack_fill * 2 + 2) & 0xFFFF;
if (addr >= UDVM_MEMORY_SIZE - 1)
goto decompression_failure;
buff[addr] = (value >> 8) & 0x00FF;
buff[(addr+1) & 0xFFFF] = value & 0x00FF;
if (stack_location >= UDVM_MEMORY_SIZE - 1)
goto decompression_failure;
stack_fill = (stack_fill + 1) & 0xFFFF;
buff[stack_location] = (stack_fill >> 8) & 0x00FF;
buff[(stack_location+1) & 0xFFFF] = stack_fill & 0x00FF;
goto execute_next_instruction;
break;
case SIGCOMP_INSTR_POP:
if (show_instr_detail_level == 2) {
proto_item_append_text(addr_item, " (value)");
}
start_offset = offset;
operand_address = current_address + 1;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &destination);
if (show_instr_detail_level == 2) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_address, bytecode_tvb, offset, (next_operand_address-operand_address), destination,
"Addr: %u Value %u", operand_address, destination);
}
offset += (next_operand_address-operand_address);
if (show_instr_detail_level == 1)
{
proto_tree_add_none_format(udvm_tree, hf_sigcomp_decompress_instruction, bytecode_tvb, start_offset, offset-start_offset,
"Addr: %u ## POP (address=%u)",
current_address, destination);
}
current_address = next_operand_address;
stack_location = (buff[70] << 8) | buff[71];
stack_fill = (buff[stack_location] << 8)
| buff[(stack_location+1) & 0xFFFF];
if (stack_fill == 0)
{
result_code = 16;
goto decompression_failure;
}
if (stack_location >= UDVM_MEMORY_SIZE - 1)
goto decompression_failure;
stack_fill = (stack_fill - 1) & 0xFFFF;
buff[stack_location] = (stack_fill >> 8) & 0x00FF;
buff[(stack_location+1) & 0xFFFF] = stack_fill & 0x00FF;
addr = (stack_location + stack_fill * 2 + 2) & 0xFFFF;
if (addr >= UDVM_MEMORY_SIZE - 1)
goto decompression_failure;
value = (buff[addr] << 8)
| buff[(addr+1) & 0xFFFF];
if (destination >= UDVM_MEMORY_SIZE - 1)
goto decompression_failure;
buff[destination] = (value >> 8) & 0x00FF;
buff[(destination+1) & 0xFFFF] = value & 0x00FF;
goto execute_next_instruction;
break;
case SIGCOMP_INSTR_COPY:
if (show_instr_detail_level == 2 ) {
proto_item_append_text(addr_item, " (position, length, destination)");
}
start_offset = offset;
operand_address = current_address + 1;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &position);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_position, bytecode_tvb, offset, (next_operand_address-operand_address), position,
"Addr: %u position %u", operand_address, position);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &length);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_length, bytecode_tvb, offset, (next_operand_address-operand_address), length,
"Addr: %u Length %u", operand_address, length);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &destination);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_ref_dest, bytecode_tvb, offset, (next_operand_address-operand_address), destination,
"Addr: %u Destination %u", operand_address, destination);
}
offset += (next_operand_address-operand_address);
if (show_instr_detail_level == 1)
{
proto_tree_add_none_format(udvm_tree, hf_sigcomp_decompress_instruction, bytecode_tvb, start_offset, offset-start_offset,
"Addr: %u ## COPY (position=%u, length=%u, destination=%u)",
current_address, position, length, destination);
}
current_address = next_operand_address;
n = 0;
k = destination;
byte_copy_right = buff[66] << 8;
byte_copy_right = byte_copy_right | buff[67];
byte_copy_left = buff[64] << 8;
byte_copy_left = byte_copy_left | buff[65];
if (print_level_2 ) {
proto_tree_add_bytes_format(udvm_tree, hf_sigcomp_byte_copy, message_tvb, input_address, 1,
NULL, " byte_copy_right = %u", byte_copy_right);
}
while ( n < length ) {
buff[k] = buff[position];
if (print_level_2 ) {
proto_tree_add_uint_format(udvm_tree, hf_sigcomp_copying_value, message_tvb, input_address, 1,
buff[position], " Copying value: %u (0x%x) to Addr: %u",
buff[position], buff[position], k);
}
position = ( position + 1 ) & 0xffff;
k = ( k + 1 ) & 0xffff;
n++;
if ( k == byte_copy_right ) {
k = byte_copy_left;
}
if ( position == byte_copy_right ) {
position = byte_copy_left;
}
}
used_udvm_cycles = used_udvm_cycles + length;
goto execute_next_instruction;
break;
case SIGCOMP_INSTR_COPY_LITERAL:
if (show_instr_detail_level == 2 ) {
proto_item_append_text(addr_item, " (position, length, $destination)");
}
start_offset = offset;
operand_address = current_address + 1;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &position);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_position, bytecode_tvb, offset, (next_operand_address-operand_address), position,
"Addr: %u position %u", operand_address, position);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &length);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_length, bytecode_tvb, offset, (next_operand_address-operand_address), length,
"Addr: %u Length %u", operand_address, length);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = dissect_udvm_reference_operand_memory(buff, operand_address, &ref_destination, &result_dest);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_ref_dest, bytecode_tvb, offset, (next_operand_address-operand_address), ref_destination,
"Addr: %u destination %u", operand_address, ref_destination);
}
offset += (next_operand_address-operand_address);
if (show_instr_detail_level == 1)
{
proto_tree_add_none_format(udvm_tree, hf_sigcomp_decompress_instruction, bytecode_tvb, start_offset, offset-start_offset,
"Addr: %u ## COPY-LITERAL (position=%u, length=%u, $destination=%u)",
current_address, position, length, ref_destination);
}
current_address = next_operand_address;
n = 0;
k = ref_destination;
byte_copy_right = buff[66] << 8;
byte_copy_right = byte_copy_right | buff[67];
byte_copy_left = buff[64] << 8;
byte_copy_left = byte_copy_left | buff[65];
if (print_level_2 ) {
proto_tree_add_bytes_format(udvm_tree, hf_sigcomp_byte_copy, message_tvb, input_address, 1,
NULL, " byte_copy_right = %u", byte_copy_right);
}
while ( n < length ) {
buff[k] = buff[position];
if (print_level_2 ) {
proto_tree_add_uint_format(udvm_tree, hf_sigcomp_copying_value, message_tvb, input_address, 1,
buff[position], " Copying value: %u (0x%x) to Addr: %u",
buff[position], buff[position], k);
}
position = ( position + 1 ) & 0xffff;
k = ( k + 1 ) & 0xffff;
n++;
if ( k == byte_copy_right ) {
k = byte_copy_left;
}
if ( position == byte_copy_right ) {
position = byte_copy_left;
}
}
buff[result_dest] = k >> 8;
buff[(result_dest + 1) & 0xffff] = k & 0x00ff;
used_udvm_cycles = used_udvm_cycles + length;
goto execute_next_instruction;
break;
case SIGCOMP_INSTR_COPY_OFFSET:
if (show_instr_detail_level == 2 ) {
proto_item_append_text(addr_item, " (offset, length, $destination)");
}
start_offset = offset;
operand_address = current_address + 1;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &multy_offset);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_offset, bytecode_tvb, offset, (next_operand_address-operand_address), multy_offset,
"Addr: %u offset %u", operand_address, multy_offset);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &length);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_length, bytecode_tvb, offset, (next_operand_address-operand_address), length,
"Addr: %u Length %u", operand_address, length);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = dissect_udvm_reference_operand_memory(buff, operand_address, &ref_destination, &result_dest);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_ref_dest, bytecode_tvb, offset, (next_operand_address-operand_address), ref_destination,
"Addr: %u $destination %u", operand_address, ref_destination);
}
offset += (next_operand_address-operand_address);
if (show_instr_detail_level == 1)
{
proto_tree_add_none_format(udvm_tree, hf_sigcomp_decompress_instruction, bytecode_tvb, start_offset, offset-start_offset,
"Addr: %u ## COPY-OFFSET (offset=%u, length=%u, $destination=%u)",
current_address, multy_offset, length, result_dest);
}
current_address = next_operand_address;
byte_copy_left = buff[64] << 8;
byte_copy_left = byte_copy_left | buff[65];
byte_copy_right = buff[66] << 8;
byte_copy_right = byte_copy_right | buff[67];
for (position = ref_destination, i = 0; i < multy_offset; i++)
{
if ( position == byte_copy_left )
{
position = (byte_copy_right - 1) & 0xffff;
}
else
{
position = (position - 1) & 0xffff;
}
}
if (print_level_2 ) {
proto_tree_add_bytes_format(udvm_tree, hf_sigcomp_byte_copy, message_tvb, input_address, 1,
NULL, " byte_copy_left = %u byte_copy_right = %u position= %u",
byte_copy_left, byte_copy_right, position);
}
n = 0;
k = ref_destination;
if (print_level_2 ) {
proto_tree_add_bytes_format(udvm_tree, hf_sigcomp_byte_copy, message_tvb, input_address, 1, NULL,
" byte_copy_left = %u byte_copy_right = %u", byte_copy_left, byte_copy_right);
}
while ( n < length ) {
buff[k] = buff[position];
if (print_level_2 ) {
proto_tree_add_uint_format(udvm_tree, hf_sigcomp_copying_value, message_tvb, input_address, 1,
buff[position], " Copying value: %5u (0x%x) from Addr: %u to Addr: %u",
buff[position], buff[position],(position), k);
}
n++;
k = ( k + 1 ) & 0xffff;
position = ( position + 1 ) & 0xffff;
if ( k == byte_copy_right ) {
k = byte_copy_left;
}
if ( position == byte_copy_right ) {
position = byte_copy_left;
}
}
buff[result_dest] = k >> 8;
buff[result_dest + 1] = k & 0x00ff;
used_udvm_cycles = used_udvm_cycles + length;
goto execute_next_instruction;
break;
case SIGCOMP_INSTR_MEMSET:
if (show_instr_detail_level == 2 ) {
proto_item_append_text(addr_item, " (address, length, start_value, offset)");
}
start_offset = offset;
operand_address = current_address + 1;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &addr);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_address, bytecode_tvb, offset, (next_operand_address-operand_address), addr,
"Addr: %u Address %u", operand_address, addr);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &length);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_length, bytecode_tvb, offset, (next_operand_address-operand_address), length,
"Addr: %u Length %u", operand_address, length);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &start_value);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_start_value, bytecode_tvb, offset, (next_operand_address-operand_address), start_value,
"Addr: %u start_value %u", operand_address, start_value);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &multy_offset);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_offset, bytecode_tvb, offset, (next_operand_address-operand_address), multy_offset,
"Addr: %u offset %u", operand_address, multy_offset);
}
offset += (next_operand_address-operand_address);
if (show_instr_detail_level == 1)
{
proto_tree_add_none_format(udvm_tree, hf_sigcomp_decompress_instruction, bytecode_tvb, start_offset, offset-start_offset,
"Addr: %u ## MEMSET (address=%u, length=%u, start_value=%u, offset=%u)",
current_address, addr, length, start_value, multy_offset);
}
current_address = next_operand_address;
n = 0;
k = addr;
byte_copy_right = buff[66] << 8;
byte_copy_right = byte_copy_right | buff[67];
byte_copy_left = buff[64] << 8;
byte_copy_left = byte_copy_left | buff[65];
if (print_level_2 ) {
proto_tree_add_bytes_format(udvm_tree, hf_sigcomp_byte_copy, message_tvb, input_address, 1, NULL,
" byte_copy_left = %u byte_copy_right = %u", byte_copy_left, byte_copy_right);
}
while ( n < length ) {
if ( k == byte_copy_right ) {
k = byte_copy_left;
}
buff[k] = (start_value + ( n * multy_offset)) & 0xff;
if (print_level_2 ) {
proto_tree_add_uint_format(udvm_tree, hf_sigcomp_storing_value, message_tvb, input_address, 1,
buff[k], " Storing value: %u (0x%x) at Addr: %u",
buff[k], buff[k], k);
}
k = ( k + 1 ) & 0xffff;
n++;
}
used_udvm_cycles = used_udvm_cycles + length;
goto execute_next_instruction;
break;
case SIGCOMP_INSTR_JUMP:
if (show_instr_detail_level == 2 ) {
proto_item_append_text(addr_item, " (@address)");
}
start_offset = offset;
operand_address = current_address + 1;
next_operand_address = decode_udvm_address_operand(buff,operand_address, &at_address, current_address);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_at_address, bytecode_tvb, offset, (next_operand_address-operand_address), at_address,
"Addr: %u @Address %u", operand_address, at_address);
}
offset += (next_operand_address-operand_address);
if (show_instr_detail_level == 1)
{
proto_tree_add_none_format(udvm_tree, hf_sigcomp_decompress_instruction, bytecode_tvb, start_offset, offset-start_offset,
"Addr: %u ## JUMP (@address=%u)",
current_address, at_address);
}
current_address = at_address;
goto execute_next_instruction;
break;
case SIGCOMP_INSTR_COMPARE:
if (show_instr_detail_level == 2 ) {
proto_item_append_text(addr_item, " (value_1, value_2, @address_1, @address_2, @address_3)");
}
start_offset = offset;
operand_address = current_address + 1;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &value_1);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_value, bytecode_tvb, offset, (next_operand_address-operand_address), value_1,
"Addr: %u Value %u", operand_address, value_1);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &value_2);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_value, bytecode_tvb, offset, (next_operand_address-operand_address), value_2,
"Addr: %u Value %u", operand_address, value_2);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &at_address_1);
at_address_1 = ( current_address + at_address_1) & 0xffff;
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_at_address, bytecode_tvb, offset, (next_operand_address-operand_address), at_address_1,
"Addr: %u @Address %u", operand_address, at_address_1);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &at_address_2);
at_address_2 = ( current_address + at_address_2) & 0xffff;
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_at_address, bytecode_tvb, offset, (next_operand_address-operand_address), at_address_2,
"Addr: %u @Address %u", operand_address, at_address_2);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &at_address_3);
at_address_3 = ( current_address + at_address_3) & 0xffff;
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_at_address, bytecode_tvb, offset, (next_operand_address-operand_address), at_address_3,
"Addr: %u @Address %u", operand_address, at_address_3);
}
offset += (next_operand_address-operand_address);
if (show_instr_detail_level == 1)
{
proto_tree_add_none_format(udvm_tree, hf_sigcomp_decompress_instruction, bytecode_tvb, start_offset, offset-start_offset,
"Addr: %u ## COMPARE (value_1=%u, value_2=%u, @address_1=%u, @address_2=%u, @address_3=%u)",
current_address, value_1, value_2, at_address_1, at_address_2, at_address_3);
}
if ( value_1 < value_2 )
current_address = at_address_1;
if ( value_1 == value_2 )
current_address = at_address_2;
if ( value_1 > value_2 )
current_address = at_address_3;
goto execute_next_instruction;
break;
case SIGCOMP_INSTR_CALL:
if (show_instr_detail_level == 2) {
proto_item_append_text(addr_item, " (@address) (PUSH addr )");
}
start_offset = offset;
operand_address = current_address + 1;
next_operand_address = decode_udvm_address_operand(buff,operand_address, &at_address, current_address);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_at_address, bytecode_tvb, offset, (next_operand_address-operand_address), at_address,
"Addr: %u @Address %u", operand_address, at_address);
}
offset += (next_operand_address-operand_address);
if (show_instr_detail_level == 1)
{
proto_tree_add_none_format(udvm_tree, hf_sigcomp_decompress_instruction, bytecode_tvb, start_offset, offset-start_offset,
"Addr: %u ## CALL (@address=%u)",
current_address, at_address);
}
current_address = next_operand_address;
stack_location = (buff[70] << 8) | buff[71];
stack_fill = (buff[stack_location] << 8)
| buff[(stack_location+1) & 0xFFFF];
addr = (stack_location + stack_fill * 2 + 2) & 0xFFFF;
if (addr >= UDVM_MEMORY_SIZE - 1)
goto decompression_failure;
buff[addr] = (current_address >> 8) & 0x00FF;
buff[(addr+1) & 0xFFFF] = current_address & 0x00FF;
stack_fill = (stack_fill + 1) & 0xFFFF;
if (stack_location >= UDVM_MEMORY_SIZE - 1)
goto decompression_failure;
buff[stack_location] = (stack_fill >> 8) & 0x00FF;
buff[(stack_location+1) & 0xFFFF] = stack_fill & 0x00FF;
current_address = at_address;
goto execute_next_instruction;
break;
case SIGCOMP_INSTR_RETURN:
stack_location = (buff[70] << 8) | buff[71];
stack_fill = (buff[stack_location] << 8)
| buff[(stack_location+1) & 0xFFFF];
if (stack_fill == 0)
{
result_code = 16;
goto decompression_failure;
}
stack_fill = (stack_fill - 1) & 0xFFFF;
if (stack_location >= UDVM_MEMORY_SIZE - 1)
goto decompression_failure;
buff[stack_location] = (stack_fill >> 8) & 0x00FF;
buff[(stack_location+1) & 0xFFFF] = stack_fill & 0x00FF;
addr = (stack_location + stack_fill * 2 + 2) & 0xFFFF;
at_address = (buff[addr] << 8)
| buff[(addr+1) & 0xFFFF];
current_address = at_address;
goto execute_next_instruction;
break;
case SIGCOMP_INSTR_SWITCH:
instruction_address = current_address;
if (show_instr_detail_level == 2) {
proto_item_append_text(addr_item, " (#n, j, @address_0, @address_1, ... , @address_n-1))");
}
operand_address = current_address + 1;
next_operand_address = decode_udvm_literal_operand(buff,operand_address, &n);
if (print_level_2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_literal_num, bytecode_tvb, offset, (next_operand_address-operand_address), n,
"Addr: %u n %u", operand_address, n);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &j);
if (print_level_2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_j, bytecode_tvb, offset, (next_operand_address-operand_address), j,
"Addr: %u j %u", operand_address, j);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
m = 0;
while ( m < n ) {
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &at_address_1);
at_address_1 = ( instruction_address + at_address_1) & 0xffff;
if (print_level_2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_at_address, bytecode_tvb, offset, (next_operand_address-operand_address), at_address_1,
"Addr: %u @Address %u", operand_address, at_address_1);
}
offset += (next_operand_address-operand_address);
if ( j == m ) {
current_address = at_address_1;
}
operand_address = next_operand_address;
m++;
}
if ( ( j == n ) || ( j > n )) {
result_code = 5;
goto decompression_failure;
}
if ( current_address > UDVM_MEMORY_SIZE ) {
result_code = 6;
goto decompression_failure;
}
used_udvm_cycles = used_udvm_cycles + n;
goto execute_next_instruction;
break;
case SIGCOMP_INSTR_CRC:
if (show_instr_detail_level == 2) {
proto_item_append_text(addr_item, " (value, position, length, @address)");
}
start_offset = offset;
operand_address = current_address + 1;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &value);
if (print_level_2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_value, bytecode_tvb, offset, (next_operand_address-operand_address), value,
"Addr: %u Value %u", operand_address, value);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &position);
if (print_level_2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_position, bytecode_tvb, offset, (next_operand_address-operand_address), position,
"Addr: %u position %u", operand_address, position);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &length);
if (print_level_2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_length, bytecode_tvb, offset, (next_operand_address-operand_address), length,
"Addr: %u Length %u", operand_address, length);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &at_address);
at_address = ( current_address + at_address) & 0xffff;
if (print_level_2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_at_address, bytecode_tvb, offset, (next_operand_address-operand_address), at_address,
"Addr: %u @Address %u", operand_address, at_address);
}
offset += (next_operand_address-operand_address);
used_udvm_cycles = used_udvm_cycles + length;
n = 0;
k = position;
byte_copy_right = buff[66] << 8;
byte_copy_right = byte_copy_right | buff[67];
byte_copy_left = buff[64] << 8;
byte_copy_left = byte_copy_left | buff[65];
result = 0;
if (print_level_2 ) {
proto_tree_add_bytes_format(udvm_tree, hf_sigcomp_byte_copy, message_tvb, 0, -1,
NULL, "byte_copy_right = %u", byte_copy_right);
}
while (n<length) {
guint16 handle_now = length - n;
if ( k < byte_copy_right && byte_copy_right <= k + (length-n) ) {
handle_now = byte_copy_right - k;
}
if (k + handle_now >= UDVM_MEMORY_SIZE)
goto decompression_failure;
result = crc16_ccitt_seed(&buff[k], handle_now, (guint16) (result ^ 0xffff));
k = ( k + handle_now ) & 0xffff;
n = ( n + handle_now ) & 0xffff;
if ( k >= byte_copy_right ) {
k = byte_copy_left;
}
}
result = result ^ 0xffff;
if (print_level_1 ) {
proto_tree_add_none_format(udvm_tree, hf_sigcomp_decompress_instruction, bytecode_tvb, start_offset, offset-start_offset,
"Calculated CRC %u", result);
}
if (result != value) {
current_address = at_address;
}
else {
current_address = next_operand_address;
}
goto execute_next_instruction;
break;
case SIGCOMP_INSTR_INPUT_BYTES:
if (show_instr_detail_level == 2 ) {
proto_item_append_text(addr_item, " length, destination, @address)");
}
start_offset = offset;
operand_address = current_address + 1;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &length);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_length, bytecode_tvb, offset, (next_operand_address-operand_address), length,
"Addr: %u Length %u", operand_address, length);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &destination);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_destination, bytecode_tvb, offset, (next_operand_address-operand_address), destination,
"Addr: %u Destination %u", operand_address, destination);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &at_address);
at_address = ( current_address + at_address) & 0xffff;
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_at_address, bytecode_tvb, offset, (next_operand_address-operand_address), at_address,
"Addr: %u @Address %u", operand_address, at_address);
}
offset += (next_operand_address-operand_address);
if (show_instr_detail_level == 1)
{
proto_tree_add_none_format(udvm_tree, hf_sigcomp_decompress_instruction, bytecode_tvb, start_offset, offset-start_offset,
"Addr: %u ## INPUT-BYTES length=%u, destination=%u, @address=%u)",
current_address, length, destination, at_address);
}
n = 0;
k = destination;
byte_copy_right = buff[66] << 8;
byte_copy_right = byte_copy_right | buff[67];
byte_copy_left = buff[64] << 8;
byte_copy_left = byte_copy_left | buff[65];
if (print_level_1 ) {
proto_tree_add_bytes_format(udvm_tree, hf_sigcomp_byte_copy, message_tvb, input_address, 1,
NULL, " byte_copy_right = %u", byte_copy_right);
}
remaining_bits = 0;
input_bits=0;
while ( n < length ) {
if (input_address > ( msg_end - 1)) {
current_address = at_address;
result_code = 14;
goto execute_next_instruction;
}
if ( k == byte_copy_right ) {
k = byte_copy_left;
}
octet = tvb_get_guint8(message_tvb, input_address);
buff[k] = octet;
if (print_level_1 ) {
proto_tree_add_uint_format(udvm_tree, hf_sigcomp_loading_value, message_tvb, input_address, 1,
octet, " Loading value: %u (0x%x) at Addr: %u", octet, octet, k);
}
input_address++;
k = ( k + 1 ) & 0xffff;
n++;
}
used_udvm_cycles = used_udvm_cycles + length;
current_address = next_operand_address;
goto execute_next_instruction;
break;
case SIGCOMP_INSTR_INPUT_BITS:
if (show_instr_detail_level == 2 ) {
proto_item_append_text(addr_item, " (length, destination, @address)");
}
start_offset = offset;
operand_address = current_address + 1;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &length);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_length, bytecode_tvb, offset, (next_operand_address-operand_address), length,
"Addr: %u length %u", operand_address, length);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &destination);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_destination, bytecode_tvb, offset, (next_operand_address-operand_address), destination,
"Addr: %u Destination %u", operand_address, destination);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_address_operand(buff,operand_address, &at_address, current_address);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_at_address, bytecode_tvb, offset, (next_operand_address-operand_address), at_address,
"Addr: %u @Address %u", operand_address, at_address);
}
offset += (next_operand_address-operand_address);
if (show_instr_detail_level == 1)
{
proto_tree_add_none_format(udvm_tree, hf_sigcomp_decompress_instruction, bytecode_tvb, start_offset, offset-start_offset,
"Addr: %u ## INPUT-BITS length=%u, destination=%u, @address=%u)",
current_address, length, destination, at_address);
}
current_address = next_operand_address;
input_bit_order = buff[68] << 8;
input_bit_order = input_bit_order | buff[69];
if ( length > 16 ) {
result_code = 7;
goto decompression_failure;
}
if ( input_bit_order > 7 ) {
result_code = 8;
goto decompression_failure;
}
bit_order = ( input_bit_order & 0x0004 ) >> 2;
value = decomp_dispatch_get_bits( message_tvb, udvm_tree, bit_order,
buff, &old_input_bit_order, &remaining_bits,
&input_bits, &input_address, length, &result_code, msg_end, print_level_1);
if ( result_code == 11 ) {
current_address = at_address;
goto execute_next_instruction;
}
msb = value >> 8;
lsb = value & 0x00ff;
if (destination >= UDVM_MEMORY_SIZE - 1)
goto decompression_failure;
buff[destination] = msb;
buff[(destination + 1) & 0xffff]=lsb;
if (print_level_1 ) {
proto_tree_add_none_format(udvm_tree, hf_sigcomp_loading_result, message_tvb, input_address, 1,
" Loading value: %u (0x%x) at Addr: %u, remaining_bits: %u", value, value, destination, remaining_bits);
}
goto execute_next_instruction;
break;
case SIGCOMP_INSTR_INPUT_HUFFMAN:
if (show_instr_detail_level == 2 ) {
proto_item_append_text(addr_item, " (destination, @address, #n, bits_1, lower_bound_1,upper_bound_1, uncompressed_1, ... , bits_n, lower_bound_n,upper_bound_n, uncompressed_n)");
}
start_offset = offset;
operand_address = current_address + 1;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &destination);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_destination, bytecode_tvb, offset, (next_operand_address-operand_address), destination,
"Addr: %u Destination %u", operand_address, destination);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_address_operand(buff,operand_address, &at_address, current_address);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_at_address, bytecode_tvb, offset, (next_operand_address-operand_address), at_address,
"Addr: %u @Address %u", operand_address, at_address);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_literal_operand(buff,operand_address, &n);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_literal_num, bytecode_tvb, offset, (next_operand_address-operand_address), n,
"Addr: %u n %u", operand_address, n);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
if (show_instr_detail_level == 1)
{
proto_tree_add_none_format(udvm_tree, hf_sigcomp_decompress_instruction, bytecode_tvb, start_offset, offset-start_offset,
"Addr: %u ## INPUT-HUFFMAN (destination=%u, @address=%u, #n=%u, bits_1, lower_1,upper_1, unc_1, ... , bits_%d, lower_%d,upper_%d, unc_%d)",
current_address, destination, at_address, n, n, n, n, n);
}
used_udvm_cycles = used_udvm_cycles + n;
input_bit_order = buff[68] << 8;
input_bit_order = input_bit_order | buff[69];
bit_order = ( input_bit_order & 0x0002 ) >> 1;
j = 1;
H = 0;
m = n;
outside_huffman_boundaries = TRUE;
print_in_loop = print_level_3;
while ( m > 0 ) {
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &bits_n);
if (print_in_loop ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_bits, bytecode_tvb, offset, (next_operand_address-operand_address), bits_n,
"Addr: %u bits_n %u", operand_address, bits_n);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &lower_bound_n);
if (print_in_loop ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_lower_bound, bytecode_tvb, offset, (next_operand_address-operand_address), lower_bound_n,
"Addr: %u lower_bound_n %u", operand_address, lower_bound_n);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &upper_bound_n);
if (print_in_loop ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_upper_bound, bytecode_tvb, offset, (next_operand_address-operand_address), upper_bound_n,
"Addr: %u upper_bound_n %u", operand_address, upper_bound_n);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &uncompressed_n);
if (print_in_loop ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_uncompressed, bytecode_tvb, offset, (next_operand_address-operand_address), uncompressed_n,
"Addr: %u uncompressed_n %u", operand_address, uncompressed_n);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
if ( outside_huffman_boundaries ) {
k = decomp_dispatch_get_bits( message_tvb, udvm_tree, bit_order,
buff, &old_input_bit_order, &remaining_bits,
&input_bits, &input_address, bits_n, &result_code, msg_end, print_level_1);
if ( result_code == 11 ) {
current_address = at_address;
goto execute_next_instruction;
}
oldH = H;
H = (H << bits_n) | k;
if (print_level_3 ) {
proto_tree_add_bytes_format(udvm_tree, hf_sigcomp_set_hu, bytecode_tvb, 0, -1, NULL,
" Set H(%u) := H(%u) * 2^bits_j(%u) + k(%u)",
H ,oldH, 1<<bits_n,k);
}
if ((H < lower_bound_n) || (H > upper_bound_n)) {
outside_huffman_boundaries = TRUE;
} else {
outside_huffman_boundaries = FALSE;
print_in_loop = FALSE;
if (print_level_2 ) {
proto_tree_add_bytes_format(udvm_tree, hf_sigcomp_set_hu, bytecode_tvb, 0, -1, NULL,
" H(%u) = H(%u) + uncompressed_n(%u) - lower_bound_n(%u)",
(H + uncompressed_n - lower_bound_n ),H, uncompressed_n, lower_bound_n);
}
H = H + uncompressed_n - lower_bound_n;
msb = H >> 8;
lsb = H & 0x00ff;
if (destination >= UDVM_MEMORY_SIZE - 1)
goto decompression_failure;
buff[destination] = msb;
buff[(destination + 1) & 0xffff]=lsb;
if (print_level_1 ) {
proto_tree_add_uint_format(udvm_tree, hf_sigcomp_loading_h, message_tvb, input_address, 1, H,
" Loading H: %u (0x%x) at Addr: %u,j = %u remaining_bits: %u",
H, H, destination,( n - m + 1 ), remaining_bits);
}
}
}
m = m - 1;
}
if ( outside_huffman_boundaries ) {
result_code = 10;
goto decompression_failure;
}
current_address = next_operand_address;
goto execute_next_instruction;
break;
case SIGCOMP_INSTR_STATE_ACCESS:
if (show_instr_detail_level == 2 ) {
proto_item_append_text(addr_item, " (partial_identifier_start, partial_identifier_length,state_begin, state_length, state_address, state_instruction)");
}
start_offset = offset;
operand_address = current_address + 1;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &p_id_start);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_partial_identifier_start, bytecode_tvb, offset, (next_operand_address-operand_address), p_id_start,
"Addr: %u partial_identifier_start %u", operand_address, p_id_start);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &p_id_length);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_partial_identifier_length, bytecode_tvb, offset, (next_operand_address-operand_address), p_id_length,
"Addr: %u partial_identifier_length %u", operand_address, p_id_length);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &state_begin);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_state_begin, bytecode_tvb, offset, (next_operand_address-operand_address), state_begin,
"Addr: %u state_begin %u", operand_address, state_begin);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &state_length);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_state_length, bytecode_tvb, offset, (next_operand_address-operand_address), state_length,
"Addr: %u state_length %u", operand_address, state_length);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &state_address);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_state_address, bytecode_tvb, offset, (next_operand_address-operand_address), state_address,
"Addr: %u state_address %u", operand_address, state_address);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &state_instruction);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_state_instr, bytecode_tvb, offset, (next_operand_address-operand_address), state_instruction,
"Addr: %u state_instruction %u", operand_address, state_instruction);
}
offset += (next_operand_address-operand_address);
if (show_instr_detail_level == 1)
{
proto_tree_add_none_format(udvm_tree, hf_sigcomp_decompress_instruction, bytecode_tvb, start_offset, offset-start_offset,
"Addr: %u ## STATE-ACCESS(31) (partial_identifier_start=%u, partial_identifier_length=%u,state_begin=%u, state_length=%u, state_address=%u, state_instruction=%u)",
current_address, p_id_start, p_id_length, state_begin, state_length, state_address, state_instruction);
}
current_address = next_operand_address;
byte_copy_right = buff[66] << 8;
byte_copy_right = byte_copy_right | buff[67];
byte_copy_left = buff[64] << 8;
byte_copy_left = byte_copy_left | buff[65];
if (print_level_2 ) {
proto_tree_add_bytes_format(udvm_tree, hf_sigcomp_byte_copy, message_tvb, input_address, 1, NULL,
" byte_copy_right = %u, byte_copy_left = %u", byte_copy_right,byte_copy_left);
}
result_code = udvm_state_access(message_tvb, udvm_tree, buff, p_id_start, p_id_length, state_begin, &state_length,
&state_address, &state_instruction, hf_id);
if ( result_code != 0 ) {
goto decompression_failure;
}
used_udvm_cycles = used_udvm_cycles + state_length;
goto execute_next_instruction;
break;
case SIGCOMP_INSTR_STATE_CREATE:
if (show_instr_detail_level == 2 ) {
proto_item_append_text(addr_item, " (state_length, state_address, state_instruction,minimum_access_length, state_retention_priority)");
}
start_offset = offset;
operand_address = current_address + 1;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &state_length);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_state_length, bytecode_tvb, offset, (next_operand_address-operand_address), state_length,
"Addr: %u state_length %u", operand_address, state_length);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &state_address);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_state_address, bytecode_tvb, offset, (next_operand_address-operand_address), state_address,
"Addr: %u state_address %u", operand_address, state_address);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &state_instruction);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_state_instr, bytecode_tvb, offset, (next_operand_address-operand_address), state_instruction,
"Addr: %u state_instruction %u", operand_address, state_instruction);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &minimum_access_length);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_min_acc_len, bytecode_tvb, offset, (next_operand_address-operand_address), minimum_access_length,
"Addr: %u minimum_access_length %u", operand_address, minimum_access_length);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &state_retention_priority);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_state_ret_pri, bytecode_tvb, offset, (next_operand_address-operand_address), state_retention_priority,
"Addr: %u state_retention_priority %u", operand_address, state_retention_priority);
}
offset += (next_operand_address-operand_address);
if (show_instr_detail_level == 1)
{
proto_tree_add_none_format(udvm_tree, hf_sigcomp_decompress_instruction, bytecode_tvb, start_offset, offset-start_offset,
"Addr: %u ## STATE-CREATE(32) (state_length=%u, state_address=%u, state_instruction=%u,minimum_access_length=%u, state_retention_priority=%u)",
current_address, state_length, state_address, state_instruction,minimum_access_length, state_retention_priority);
}
current_address = next_operand_address;
no_of_state_create++;
if ( no_of_state_create > 4 ) {
result_code = 12;
goto decompression_failure;
}
if (( minimum_access_length < 6 ) || ( minimum_access_length > STATE_BUFFER_SIZE )) {
result_code = 1;
goto decompression_failure;
}
if ( state_retention_priority == 65535 ) {
result_code = 13;
goto decompression_failure;
}
state_length_buff[no_of_state_create] = state_length;
state_address_buff[no_of_state_create] = state_address;
state_instruction_buff[no_of_state_create] = state_instruction;
state_minimum_access_length_buff[no_of_state_create] = minimum_access_length;
used_udvm_cycles = used_udvm_cycles + state_length;
byte_copy_right = buff[66] << 8;
byte_copy_right = byte_copy_right | buff[67];
byte_copy_left = buff[64] << 8;
byte_copy_left = byte_copy_left | buff[65];
n = 0;
k = state_address;
while ( n < state_length ) {
if ( k == byte_copy_right ) {
k = byte_copy_left;
}
string[0]= buff[k];
string[1]= '\0';
if (print_level_3 ) {
proto_tree_add_uint_format(udvm_tree, hf_sigcomp_state_value, bytecode_tvb, 0, 0, buff[k],
" Addr: %5u State value: %u (0x%x) ASCII(%s)",
k,buff[k],buff[k],format_text(string, 1));
}
k = ( k + 1 ) & 0xffff;
n++;
}
goto execute_next_instruction;
break;
case SIGCOMP_INSTR_STATE_FREE:
if (show_instr_detail_level == 2 ) {
proto_item_append_text(addr_item, " (partial_identifier_start, partial_identifier_length)");
}
start_offset = offset;
operand_address = current_address + 1;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &p_id_start);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_partial_identifier_start, bytecode_tvb, offset, (next_operand_address-operand_address), p_id_start,
"Addr: %u partial_identifier_start %u", operand_address, p_id_start);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &p_id_length);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_partial_identifier_length, bytecode_tvb, offset, (next_operand_address-operand_address), p_id_length,
"Addr: %u partial_identifier_length %u", operand_address, p_id_length);
}
offset += (next_operand_address-operand_address);
if (show_instr_detail_level == 1)
{
proto_tree_add_none_format(udvm_tree, hf_sigcomp_decompress_instruction, bytecode_tvb, start_offset, offset-start_offset,
"Addr: %u ## STATE-FREE (partial_identifier_start=%u, partial_identifier_length=%u)",
current_address, p_id_start, p_id_length);
}
current_address = next_operand_address;
udvm_state_free(buff,p_id_start,p_id_length);
goto execute_next_instruction;
break;
case SIGCOMP_INSTR_OUTPUT:
if (show_instr_detail_level == 2 ) {
proto_item_append_text(addr_item, " (output_start, output_length)");
}
start_offset = offset;
operand_address = current_address + 1;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &output_start);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_output_start, bytecode_tvb, offset, (next_operand_address-operand_address), output_start,
"Addr: %u output_start %u", operand_address, output_start);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &output_length);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_output_length, bytecode_tvb, offset, (next_operand_address-operand_address), output_length,
"Addr: %u output_length %u", operand_address, output_length);
}
offset += (next_operand_address-operand_address);
if (show_instr_detail_level == 1)
{
proto_tree_add_none_format(udvm_tree, hf_sigcomp_decompress_instruction, bytecode_tvb, start_offset, offset-start_offset,
"Addr: %u ## OUTPUT (output_start=%u, output_length=%u)",
current_address, output_start, output_length);
}
current_address = next_operand_address;
n = 0;
k = output_start;
byte_copy_right = buff[66] << 8;
byte_copy_right = byte_copy_right | buff[67];
byte_copy_left = buff[64] << 8;
byte_copy_left = byte_copy_left | buff[65];
if (print_level_3 ) {
proto_tree_add_bytes_format(udvm_tree, hf_sigcomp_byte_copy, bytecode_tvb, 0, -1,
NULL, " byte_copy_right = %u", byte_copy_right);
}
while ( n < output_length ) {
if ( k == byte_copy_right ) {
k = byte_copy_left;
}
out_buff[output_address] = buff[k];
string[0]= buff[k];
string[1]= '\0';
if (print_level_3 ) {
proto_tree_add_uint_format(udvm_tree, hf_sigcomp_output_value, bytecode_tvb, 0, -1, buff[k],
" Output value: %u (0x%x) ASCII(%s) from Addr: %u ,output to dispatcher position %u",
buff[k],buff[k],format_text(string,1), k,output_address);
}
k = ( k + 1 ) & 0xffff;
output_address ++;
n++;
}
used_udvm_cycles = used_udvm_cycles + output_length;
goto execute_next_instruction;
break;
case SIGCOMP_INSTR_END_MESSAGE:
if (show_instr_detail_level == 2 ) {
proto_item_append_text(addr_item, " (requested_feedback_location,state_instruction, minimum_access_length,state_retention_priority)");
}
start_offset = offset;
operand_address = current_address + 1;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &requested_feedback_location);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_req_feedback_loc, bytecode_tvb, offset, (next_operand_address-operand_address), requested_feedback_location,
"Addr: %u requested_feedback_location %u",
operand_address, requested_feedback_location);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &returned_parameters_location);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_ret_param_loc, bytecode_tvb, offset, (next_operand_address-operand_address), returned_parameters_location,
"Addr: %u returned_parameters_location %u", operand_address, returned_parameters_location);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &state_length);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_state_length, bytecode_tvb, offset, (next_operand_address-operand_address), state_length,
"Addr: %u state_length %u", operand_address, state_length);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &state_address);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_state_address, bytecode_tvb, offset, (next_operand_address-operand_address), state_address,
"Addr: %u state_address %u", operand_address, state_address);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &state_instruction);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_state_instr, bytecode_tvb, offset, (next_operand_address-operand_address), state_instruction,
"Addr: %u state_instruction %u", operand_address, state_instruction);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &minimum_access_length);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_min_acc_len, bytecode_tvb, offset, (next_operand_address-operand_address), minimum_access_length,
"Addr: %u minimum_access_length %u", operand_address, minimum_access_length);
}
offset += (next_operand_address-operand_address);
operand_address = next_operand_address;
next_operand_address = decode_udvm_multitype_operand(buff, operand_address, &state_retention_priority);
if (show_instr_detail_level == 2 ) {
proto_tree_add_uint_format(udvm_tree, hf_udvm_state_ret_pri, bytecode_tvb, offset, (next_operand_address-operand_address), state_retention_priority,
"Addr: %u state_retention_priority %u", operand_address, state_retention_priority);
}
offset += (next_operand_address-operand_address);
if (show_instr_detail_level == 1)
{
proto_tree_add_none_format(udvm_tree, hf_sigcomp_decompress_instruction, bytecode_tvb, start_offset, offset-start_offset,
"Addr: %u ## END-MESSAGE (requested_feedback_location=%u, returned_parameters_location=%u, state_length=%u, state_address=%u, state_instruction=%u, minimum_access_length=%u, state_retention_priority=%u)",
current_address, requested_feedback_location, returned_parameters_location, state_length, state_address, state_instruction, minimum_access_length,state_retention_priority);
}
no_of_state_create++;
if ( no_of_state_create > 4 ) {
result_code = 12;
goto decompression_failure;
}
state_length_buff[no_of_state_create] = state_length;
state_address_buff[no_of_state_create] = state_address;
state_instruction_buff[no_of_state_create] = state_instruction;
state_minimum_access_length_buff[no_of_state_create] = minimum_access_length;
proto_tree_add_uint(udvm_tree, hf_sigcomp_num_state_create, bytecode_tvb, 0, 0, no_of_state_create);
if ( no_of_state_create != 0 ) {
memset(sha1_digest_buf, 0, STATE_BUFFER_SIZE);
n = 1;
byte_copy_right = buff[66] << 8;
byte_copy_right = byte_copy_right | buff[67];
byte_copy_left = buff[64] << 8;
byte_copy_left = byte_copy_left | buff[65];
while ( n < no_of_state_create + 1 ) {
sha1buff = (guint8 *)g_malloc(state_length_buff[n]+8);
sha1buff[0] = state_length_buff[n] >> 8;
sha1buff[1] = state_length_buff[n] & 0xff;
sha1buff[2] = state_address_buff[n] >> 8;
sha1buff[3] = state_address_buff[n] & 0xff;
sha1buff[4] = state_instruction_buff[n] >> 8;
sha1buff[5] = state_instruction_buff[n] & 0xff;
sha1buff[6] = state_minimum_access_length_buff[n] >> 8;
sha1buff[7] = state_minimum_access_length_buff[n] & 0xff;
if (print_level_3 ) {
proto_tree_add_bytes_with_length(udvm_tree, hf_sigcomp_sha1buff, bytecode_tvb, 0, -1, sha1buff, 8);
}
k = state_address_buff[n];
for ( x=0; x < state_length_buff[n]; x++)
{
if ( k == byte_copy_right ) {
k = byte_copy_left;
}
sha1buff[8+x] = buff[k];
k = ( k + 1 ) & 0xffff;
}
sha1_starts( &ctx );
sha1_update( &ctx, (guint8 *) sha1buff, state_length_buff[n] + 8);
sha1_finish( &ctx, sha1_digest_buf );
if (print_level_3 ) {
proto_tree_add_bytes_with_length(udvm_tree, hf_sigcomp_sha1_digest, bytecode_tvb, 0, -1, sha1_digest_buf, STATE_BUFFER_SIZE);
}
#if 0
udvm_state_create(sha1buff, sha1_digest_buf, state_minimum_access_length_buff[n]);
#endif
udvm_state_create(sha1buff, sha1_digest_buf, STATE_MIN_ACCESS_LEN);
proto_tree_add_item(udvm_tree, hf_sigcomp_creating_state, bytecode_tvb, 0, -1, ENC_NA);
proto_tree_add_string(udvm_tree,hf_id, bytecode_tvb, 0, 0, bytes_to_str(wmem_packet_scope(), sha1_digest_buf, STATE_MIN_ACCESS_LEN));
n++;
}
}
decomp_tvb = tvb_new_child_real_data(message_tvb, out_buff,output_address,output_address);
tvb_set_free_cb( decomp_tvb, g_free );
add_new_data_source(pinfo, decomp_tvb, "Decompressed SigComp message");
proto_tree_add_item(udvm_tree, hf_sigcomp_sigcomp_message_decompressed, decomp_tvb, 0, -1, ENC_NA);
used_udvm_cycles += state_length;
proto_tree_add_uint(udvm_tree, hf_sigcomp_max_udvm_cycles, bytecode_tvb, 0, 0, maximum_UDVM_cycles);
proto_tree_add_uint(udvm_tree, hf_sigcomp_used_udvm_cycles, bytecode_tvb, 0, 0, used_udvm_cycles);
return decomp_tvb;
break;
default:
expert_add_info_format(pinfo, addr_item, &ei_sigcomp_invalid_instruction,
"Addr %u Invalid instruction: %u (0x%x)", current_address,current_instruction,current_instruction);
break;
}
g_free(out_buff);
return NULL;
decompression_failure:
proto_tree_add_expert_format(udvm_tree, pinfo, &ei_sigcomp_decompression_failure, bytecode_tvb, 0, -1,
"DECOMPRESSION FAILURE: %s", val_to_str(result_code, result_code_vals,"Unknown (%u)"));
g_free(out_buff);
THROW(ReportedBoundsError);
return NULL;
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
if (data == 0xffff) {
offset = offset + 2;
octet = tvb_get_guint8(tvb,offset);
} else {
octet = tvb_get_guint8(tvb,offset);
}
if ((octet & 0xf8) != 0xf8)
return offset;
length = tvb_reported_length_remaining(tvb, offset);
for (i=0; i<(length-1); ++i) {
data = tvb_get_ntohs(tvb, offset+i);
if (0xffff == data) break;
}
if (i >= (length-1)) {
if (pinfo->can_desegment || pinfo->saved_can_desegment) {
pinfo->desegment_offset = offset;
pinfo->desegment_len=DESEGMENT_ONE_MORE_SEGMENT;
return -1;
}
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SIGCOMP");
col_clear(pinfo->cinfo, COL_INFO);
length = tvb_captured_length_remaining(tvb,offset);
try_again:
ti = proto_tree_add_item(tree, proto_sigcomp, tvb, 0, -1, ENC_NA);
sigcomp_tree = proto_item_add_subtree(ti, ett_sigcomp);
i=0;
end_off_message = FALSE;
buff = (guint8 *)wmem_alloc(pinfo->pool, length-offset);
if (udvm_print_detail_level>2)
proto_tree_add_item(sigcomp_tree, hf_sigcomp_starting_to_remove_escape_digits, tvb, offset, -1, ENC_NA);
while ((offset < length) && (end_off_message == FALSE)) {
octet = tvb_get_guint8(tvb,offset);
if ( octet == 0xff ) {
if ( offset +1 >= length ) {
offset++;
continue;
}
if (udvm_print_detail_level>2)
proto_tree_add_none_format(sigcomp_tree, hf_sigcomp_escape_digit_found, tvb, offset, 2,
" Escape digit found (0xFF)");
octet = tvb_get_guint8(tvb, offset+1);
if ( octet == 0) {
buff[i] = 0xff;
offset = offset +2;
i++;
continue;
}
if ((octet > 0x7f) && (octet < 0xff )) {
if (udvm_print_detail_level>2)
proto_tree_add_none_format(sigcomp_tree, hf_sigcomp_illegal_escape_code, tvb, offset, 2,
" Illegal escape code");
offset += tvb_captured_length_remaining(tvb,offset);
return offset;
}
if ( octet == 0xff) {
if (udvm_print_detail_level>2)
proto_tree_add_none_format(sigcomp_tree, hf_sigcomp_end_of_sigcomp_message_indication_found, tvb, offset, 2,
" End of SigComp message indication found (0xFFFF)");
end_off_message = TRUE;
offset = offset+2;
continue;
}
buff[i] = 0xff;
if (udvm_print_detail_level>2)
proto_tree_add_uint_format(sigcomp_tree, hf_sigcomp_addr_value, tvb, offset, 1, buff[i],
" Addr: %u tvb value(0x%0x) ", i, buff[i]);
i++;
offset = offset+2;
if (udvm_print_detail_level>2)
proto_tree_add_bytes_format(sigcomp_tree, hf_sigcomp_copying_bytes_literally, tvb, offset, octet,
NULL, " Copying %u bytes literally",octet);
if ( offset+octet >= length)
octet = length - offset;
for ( n=0; n < octet; n++ ) {
buff[i] = tvb_get_guint8(tvb, offset);
if (udvm_print_detail_level>2)
proto_tree_add_uint_format(sigcomp_tree, hf_sigcomp_addr_value, tvb, offset, 1, buff[i],
" Addr: %u tvb value(0x%0x) ", i, buff[i]);
i++;
offset++;
}
continue;
}
buff[i] = octet;
if (udvm_print_detail_level>2)
proto_tree_add_uint_format(sigcomp_tree, hf_sigcomp_addr_value, tvb, offset, 1, buff[i],
" Addr: %u tvb value(0x%0x) ", i, buff[i]);
i++;
offset++;
}
unescaped_tvb = tvb_new_child_real_data(tvb, buff,i,i);
add_new_data_source(pinfo, unescaped_tvb, "Unescaped Data handed to the SigComp dissector");
proto_tree_add_item(sigcomp_tree, hf_sigcomp_data_for_sigcomp_dissector, unescaped_tvb, 0, -1, ENC_NA);
if (end_off_message == TRUE) {
dissect_sigcomp_common(unescaped_tvb, pinfo, sigcomp_tree);
} else {
proto_tree_add_expert(sigcomp_tree, pinfo, &ei_sigcomp_tcp_fragment, unescaped_tvb, 0, -1);
}
if ( offset < length) {
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
if ( partial_state_len != 0 ) {
partial_state_len = partial_state_len * 3 + 3;
col_set_str(pinfo->cinfo, COL_INFO, "Msg format 1");
if ( tbit == 1 ) {
len = 1;
octet = tvb_get_guint8(tvb, offset);
if ( (octet & 0x80) != 0 ) {
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
partial_state_str = bytes_to_str(wmem_packet_scope(), partial_state, partial_state_len);
proto_tree_add_string(sigcomp_tree,hf_sigcomp_partial_state,
tvb, offset, partial_state_len, partial_state_str);
offset = offset + partial_state_len;
msg_len = tvb_reported_length_remaining(tvb, offset);
if (msg_len>0) {
proto_item *ti;
ti = proto_tree_add_uint(sigcomp_tree, hf_sigcomp_remaining_message_bytes, tvb,
offset, 0, msg_len);
PROTO_ITEM_SET_GENERATED(ti);
}
if ( decompress ) {
msg_tvb = tvb_new_subset_length(tvb, offset, msg_len);
buff = (guint8 *)wmem_alloc0(pinfo->pool, UDVM_MEMORY_SIZE);
p_id_start = 0;
state_begin = 0;
state_length = 0;
state_address = 0;
state_instruction =0;
i = 0;
while ( i < partial_state_len ) {
buff[i] = partial_state[i];
i++;
}
#if 0
result_code = udvm_state_access(tvb, sigcomp_tree, buff, p_id_start, partial_state_len, state_begin, &state_length,
&state_address, &state_instruction, hf_sigcomp_partial_state);
#endif
result_code = udvm_state_access(tvb, sigcomp_tree, buff, p_id_start, STATE_MIN_ACCESS_LEN, state_begin, &state_length,
&state_address, &state_instruction, hf_sigcomp_partial_state);
if ( result_code != 0 ) {
proto_tree_add_expert_format(sigcomp_tree, pinfo, &ei_sigcomp_failed_to_access_state_wireshark_udvm_diagnostic, tvb, 0, -1,
"Failed to Access state Wireshark UDVM diagnostic: %s", val_to_str(result_code, result_code_vals,"Unknown (%u)"));
return tvb_captured_length(tvb);
}
udvm_tvb = tvb_new_child_real_data(tvb, buff,state_length+state_address,state_length+state_address);
add_new_data_source(pinfo, udvm_tvb, "State/ExecutionTrace");
udvm2_tvb = tvb_new_subset_length(udvm_tvb, state_address, state_length);
udvm_exe_item = proto_tree_add_item(sigcomp_tree, hf_udvm_execution_trace,
udvm2_tvb, 0, state_length,
ENC_NA);
sigcomp_udvm_exe_tree = proto_item_add_subtree( udvm_exe_item, ett_sigcomp_udvm_exe);
decomp_tvb = decompress_sigcomp_message(udvm2_tvb, msg_tvb, pinfo,
sigcomp_udvm_exe_tree, state_address,
udvm_print_detail_level, hf_sigcomp_partial_state,
offset, state_length, partial_state_len, state_instruction);
if ( decomp_tvb ) {
proto_item *ti;
guint32 compression_ratio =
(guint32)(((float)tvb_reported_length(decomp_tvb) / (float)tvb_reported_length(tvb)) * 100);
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
if ( (octet & 0x80) != 0 ) {
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
if ((len == 0) && (nack_version == 1)) {
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
val_to_str_ext_const(octet, &sigcomp_nack_reason_code_vals_ext, "Unknown"),
val_to_str_ext_const(opcode, &udvm_instruction_code_vals_ext, "Unknown"));
proto_tree_add_item(sigcomp_tree,hf_sigcomp_nack_pc, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset +2;
proto_tree_add_item(sigcomp_tree,hf_sigcomp_nack_sha1, tvb, offset, SHA1_DIGEST_LEN, ENC_NA);
offset = offset +SHA1_DIGEST_LEN;
col_append_fstr(pinfo->cinfo, COL_INFO, " NACK reason=%s, opcode=%s",
val_to_str_ext_const(octet, &sigcomp_nack_reason_code_vals_ext, "Unknown"),
val_to_str_ext_const(opcode, &udvm_instruction_code_vals_ext, "Unknown"));
switch ( octet) {
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
} else {
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
udvm_tvb = tvb_new_subset_length(tvb, offset, len);
if ( dissect_udvm_code )
dissect_udvm_bytecode(udvm_tvb, pinfo, sigcomp_udvm_tree, destination);
offset = offset + len;
msg_len = tvb_reported_length_remaining(tvb, offset);
if (msg_len>0) {
proto_item *ti = proto_tree_add_item(sigcomp_tree, hf_sigcomp_remaining_sigcomp_message, tvb, offset, -1, ENC_NA);
PROTO_ITEM_SET_GENERATED(ti);
}
if ( decompress ) {
msg_tvb = tvb_new_subset_length(tvb, offset, msg_len);
udvm_exe_item = proto_tree_add_item(sigcomp_tree, hf_udvm_execution_trace,
tvb, bytecode_offset, bytecode_len,
ENC_NA);
sigcomp_udvm_exe_tree = proto_item_add_subtree( udvm_exe_item, ett_sigcomp_udvm_exe);
decomp_tvb = decompress_sigcomp_message(udvm_tvb, msg_tvb, pinfo,
sigcomp_udvm_exe_tree, destination,
udvm_print_detail_level, hf_sigcomp_partial_state,
offset, 0, 0, destination);
if ( decomp_tvb ) {
proto_item *ti;
guint32 compression_ratio =
(guint32)(((float)tvb_reported_length(decomp_tvb) / (float)tvb_reported_length(tvb)) * 100);
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
return tvb_captured_length(tvb);
}
static void
dissect_udvm_bytecode(tvbuff_t *udvm_tvb, packet_info* pinfo, proto_tree *sigcomp_udvm_tree,guint start_address)
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
item = proto_tree_add_uint_format(sigcomp_udvm_tree, hf_sigcomp_udvm_instruction, udvm_tvb, offset, 1,
instruction_no, "######### UDVM instruction %u at UDVM-address %u (0x%x) #########",
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
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_2_addr,
udvm_tvb, start_offset, len, value);
} else {
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
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_2_addr,
udvm_tvb, start_offset, len, value);
} else {
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
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_2_addr,
udvm_tvb, start_offset, len, value);
} else {
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
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_2_addr,
udvm_tvb, start_offset, len, value);
} else {
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
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_2_addr,
udvm_tvb, start_offset, len, value);
} else {
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
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_2_addr,
udvm_tvb, start_offset, len, value);
} else {
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
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_2_addr,
udvm_tvb, start_offset, len, value);
} else {
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
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_2_addr,
udvm_tvb, start_offset, len, value);
} else {
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
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_operand_2_addr,
udvm_tvb, start_offset, len, value);
} else {
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
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_length,
udvm_tvb, start_offset, len, value);
} else {
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
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_value,
udvm_tvb, start_offset, len, value);
} else {
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
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_value,
udvm_tvb, start_offset, len, value);
} else {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_value,
udvm_tvb, start_offset, len, value);
}
}
break;
case SIGCOMP_INSTR_PUSH:
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_value,
udvm_tvb, start_offset, len, value);
} else {
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
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_length,
udvm_tvb, start_offset, len, value);
} else {
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
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_length,
udvm_tvb, start_offset, len, value);
} else {
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
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_offset,
udvm_tvb, start_offset, len, value);
} else {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_offset,
udvm_tvb, start_offset, len, value);
}
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_length,
udvm_tvb, start_offset, len, value);
} else {
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
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_length,
udvm_tvb, start_offset, len, value);
} else {
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
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_value,
udvm_tvb, start_offset, len, value);
} else {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_value,
udvm_tvb, start_offset, len, value);
}
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_value,
udvm_tvb, start_offset, len, value);
} else {
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
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_j,
udvm_tvb, start_offset, len, value);
} else {
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
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_value,
udvm_tvb, start_offset, len, value);
} else {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_value,
udvm_tvb, start_offset, len, value);
}
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_position,
udvm_tvb, start_offset, len, value);
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_length,
udvm_tvb, start_offset, len, value);
} else {
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
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_length,
udvm_tvb, start_offset, len, value);
} else {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_length,
udvm_tvb, start_offset, len, value);
}
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_destination,
udvm_tvb, start_offset, len, value);
} else {
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
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_length,
udvm_tvb, start_offset, len, value);
} else {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_length,
udvm_tvb, start_offset, len, value);
}
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, FALSE,&start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_destination,
udvm_tvb, start_offset, len, value);
} else {
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
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_addr_destination,
udvm_tvb, start_offset, len, value);
} else {
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
} else {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_state_length,
udvm_tvb, start_offset, len, value);
}
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value ,&is_memory_address);
len = offset - start_offset;
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_state_address_addr,
udvm_tvb, start_offset, len, value);
} else {
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
} else {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_state_length,
udvm_tvb, start_offset, len, value);
}
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_state_address_addr,
udvm_tvb, start_offset, len, value);
} else {
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
} else {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_output_start,
udvm_tvb, start_offset, len, value);
}
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_output_length_addr,
udvm_tvb, start_offset, len, value);
} else {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_output_length,
udvm_tvb, start_offset, len, value);
}
break;
case SIGCOMP_INSTR_END_MESSAGE:
if ((msg_length-1) < offset) {
proto_tree_add_expert(sigcomp_udvm_tree, pinfo, &ei_sigcomp_all_remaining_parameters_zero, udvm_tvb, 0, -1);
return;
}
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_req_feedback_loc,
udvm_tvb, start_offset, len, value);
if ((msg_length-1) < offset) {
proto_tree_add_expert(sigcomp_udvm_tree, pinfo, &ei_sigcomp_all_remaining_parameters_zero, udvm_tvb, offset-1, -1);
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
} else {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_state_length,
udvm_tvb, start_offset, len, value);
}
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
if ( is_memory_address ) {
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_state_address_addr,
udvm_tvb, start_offset, len, value);
} else {
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
if ( tvb_reported_length_remaining(udvm_tvb, offset) != 0 ) {
offset = dissect_udvm_multitype_operand(udvm_tvb, sigcomp_udvm_tree, offset, TRUE, &start_offset, &value, &is_memory_address);
len = offset - start_offset;
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_state_ret_pri,
udvm_tvb, start_offset, len, value);
} else {
item2 = proto_tree_add_uint_format_value(sigcomp_udvm_tree, hf_udvm_state_ret_pri, udvm_tvb, offset, 1, 0,
"0 (Not in the uploaded code as UDVM buffer initialized to Zero");
PROTO_ITEM_SET_GENERATED(item2);
}
if ( tvb_reported_length_remaining(udvm_tvb, offset) != 0 ) {
len = tvb_reported_length_remaining(udvm_tvb, offset);
UDVM_address = start_address + offset;
proto_tree_add_bytes_format(sigcomp_udvm_tree, hf_sigcomp_remaining_bytes, udvm_tvb, offset, len, NULL,
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
if (test_bits == 1) {
test_bits = bytecode >> 6;
if (test_bits == 2) {
display_bytecode = bytecode & 0xc0;
if ( display_udvm_bytecode )
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_literal_bytecode,
udvm_tvb, offset, 1, display_bytecode);
operand = tvb_get_ntohs(udvm_tvb, offset) & 0x3fff;
*value = operand;
*start_offset = offset;
offset = offset + 2;
} else {
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
} else {
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
if (test_bits == 1) {
test_bits = bytecode >> 6;
if (test_bits == 2) {
display_bytecode = bytecode & 0xc0;
if ( display_udvm_bytecode )
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_reference_bytecode,
udvm_tvb, offset, 1, display_bytecode);
operand = tvb_get_ntohs(udvm_tvb, offset) & 0x3fff;
*value = (operand * 2);
*start_offset = offset;
offset = offset + 2;
} else {
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
} else {
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
switch (test_bits ) {
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
if ( test_bits == 5 ) {
display_bytecode = bytecode & 0xe0;
if ( display_udvm_bytecode )
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_multitype_bytecode,
udvm_tvb, offset, 1, display_bytecode);
operand = tvb_get_ntohs(udvm_tvb, offset) & 0x1fff;
*value = operand;
*start_offset = offset;
offset = offset + 2;
} else {
test_bits = ( bytecode & 0xf0 ) >> 4;
if ( test_bits == 9 ) {
display_bytecode = bytecode & 0xf0;
if ( display_udvm_bytecode )
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_multitype_bytecode,
udvm_tvb, offset, 1, display_bytecode);
operand = (tvb_get_ntohs(udvm_tvb, offset) & 0x0fff) + 61440;
*start_offset = offset;
*value = operand;
offset = offset + 2;
} else {
test_bits = ( bytecode & 0x08 ) >> 3;
if ( test_bits == 1) {
display_bytecode = bytecode & 0xf8;
if ( display_udvm_bytecode )
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_multitype_bytecode,
udvm_tvb, offset, 1, display_bytecode);
result = (guint32)pow(2,( bytecode & 0x07) + 8);
operand = result & 0xffff;
*start_offset = offset;
*value = operand;
offset ++;
} else {
test_bits = ( bytecode & 0x0e ) >> 1;
if ( test_bits == 3 ) {
display_bytecode = bytecode & 0xfe;
if ( display_udvm_bytecode )
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_multitype_bytecode,
udvm_tvb, offset, 1, display_bytecode);
result = (guint32)pow(2,( bytecode & 0x01) + 6);
operand = result & 0xffff;
*start_offset = offset;
*value = operand;
offset ++;
} else {
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
if ( test_bits == 1 ) {
display_bytecode = bytecode & 0xe0;
if ( display_udvm_bytecode )
proto_tree_add_uint(sigcomp_udvm_tree, hf_udvm_multitype_bytecode,
udvm_tvb, offset, 1, display_bytecode);
operand = ( bytecode & 0x1f) + 65504;
*start_offset = offset;
*value = operand;
offset ++;
} else {
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
if (tree) {
ti = proto_tree_add_item(tree, proto_raw_sigcomp, tvb, 0, -1, ENC_NA);
raw_tree = proto_item_add_subtree(ti, ett_raw_text);
}
offset = 0;
while (tvb_offset_exists(tvb, offset)) {
tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
linelen = next_offset - offset;
proto_tree_add_format_text(raw_tree, tvb, offset, linelen);
offset = next_offset;
}
}
void
proto_register_sigcomp(void)
{
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
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &destination_address_encoding_vals_ext, 0xf,
NULL, HFILL }
},
{ &hf_sigcomp_udvm_bytecode,
{ "Uploaded UDVM bytecode","sigcomp.udvm.byte-code",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sigcomp_udvm_instr,
{ "UDVM instruction code","sigcomp.udvm.instr",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &udvm_instruction_code_vals_ext, 0x0,
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
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &sigcomp_nack_reason_code_vals_ext, 0x0,
"NACK Reason Code", HFILL }
},
{ &hf_sigcomp_nack_failed_op_code,
{ "OPCODE of failed instruction", "sigcomp.nack.failed_op_code",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &udvm_instruction_code_vals_ext, 0x0,
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
{ &hf_sigcomp_decompress_instruction,
{ "Instruction", "sigcomp.decompress_instruction",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sigcomp_loading_result,
{ "Loading result", "sigcomp.loading_result",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sigcomp_byte_copy,
{ "byte copy", "sigcomp.byte_copy",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sigcomp_accessing_state, { "### Accessing state ###", "sigcomp.accessing_state", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_getting_value, { "Getting value", "sigcomp.getting_value", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_load_bytecode_into_udvm_start, { "Load bytecode into UDVM starting at", "sigcomp.load_bytecode_into_udvm_start", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_instruction_code, { "Instruction code", "sigcomp.instruction_code", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_current_instruction, { "Addr", "sigcomp.current_instruction", FT_UINT8, BASE_DEC|BASE_EXT_STRING, &udvm_instruction_code_vals_ext, 0x0, NULL, HFILL }},
{ &hf_sigcomp_decompression_failure, { "DECOMPRESSION-FAILURE", "sigcomp.decompression_failure", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_wireshark_udvm_diagnostic, { "Wireshark UDVM diagnostic", "sigcomp.wireshark_udvm_diagnostic", FT_UINT32, BASE_DEC, VALS(result_code_vals), 0x0, NULL, HFILL }},
{ &hf_sigcomp_calculated_sha_1, { "Calculated SHA-1", "sigcomp.calculated_sha_1", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_copying_value, { "Copying value", "sigcomp.copying_value", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_storing_value, { "Storing value", "sigcomp.storing_value", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_loading_value, { "Loading value", "sigcomp.loading_value", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_set_hu, { "Set Hu", "sigcomp.set_hu", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_loading_h, { "Loading H", "sigcomp.loading_h", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_state_value, { "Addr", "sigcomp.state_value", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_output_value, { "Output value", "sigcomp.output_value", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_num_state_create, { "no_of_state_create", "sigcomp.num_state_create", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_sha1_digest, { "SHA1 digest", "sigcomp.sha1_digest", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_creating_state, { "### Creating state ###", "sigcomp.creating_state", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_sigcomp_message_decompressed, { "SigComp message Decompressed", "sigcomp.message_decompressed", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_starting_to_remove_escape_digits, { "Starting to remove escape digits", "sigcomp.starting_to_remove_escape_digits", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_escape_digit_found, { "Escape digit found", "sigcomp.escape_digit_found", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_illegal_escape_code, { "Illegal escape code", "sigcomp.illegal_escape_code", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_end_of_sigcomp_message_indication_found, { "End of SigComp message indication found", "sigcomp.end_of_sigcomp_message_indication_found", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_addr_value, { "Addr", "sigcomp.addr", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_copying_bytes_literally, { "Copying bytes literally", "sigcomp.copying_bytes_literally", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_data_for_sigcomp_dissector, { "Data handed to the Sigcomp dissector", "sigcomp.data_for_sigcomp_dissector", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_remaining_sigcomp_message, { "Remaining SigComp message", "sigcomp.remaining_sigcomp_message", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_sha1buff, { "sha1buff", "sigcomp.sha1buff", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_udvm_instruction, { "UDVM instruction", "sigcomp.udvm_instruction", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_remaining_bytes, { "Remaining bytes", "sigcomp.remaining_bytes", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_max_udvm_cycles, { "maximum_UDVM_cycles", "sigcomp.max_udvm_cycles", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_used_udvm_cycles, { "used_udvm_cycles", "sigcomp.used_udvm_cycles", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_udvm_execution_stated, { "UDVM EXECUTION STARTED", "sigcomp.udvm_execution_stated", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_message_length, { "Message Length", "sigcomp.message_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sigcomp_byte_code_length, { "Byte code length", "sigcomp.byte_code_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
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
{ &ei_sigcomp_invalid_instruction, { "sigcomp.invalid_instruction", PI_PROTOCOL, PI_WARN, "Invalid instruction", EXPFILL }},
{ &ei_sigcomp_sigcomp_message_decompression_failure, { "sigcomp.message_decompression_failure", PI_PROTOCOL, PI_WARN, "SigComp message Decompression failure", EXPFILL }},
{ &ei_sigcomp_execution_of_this_instruction_is_not_implemented, { "sigcomp.execution_of_this_instruction_is_not_implemented", PI_UNDECODED, PI_WARN, "Execution of this instruction is NOT implemented", EXPFILL }},
{ &ei_sigcomp_decompression_failure, { "sigcomp.decompression_failure", PI_PROTOCOL, PI_WARN, "DECOMPRESSION FAILURE", EXPFILL }},
{ &ei_sigcomp_tcp_fragment, { "sigcomp.tcp_fragment", PI_MALFORMED, PI_ERROR, "TCP Fragment", EXPFILL }},
{ &ei_sigcomp_failed_to_access_state_wireshark_udvm_diagnostic, { "sigcomp.failed_to_access_state_wireshark_udvm_diagnostic", PI_PROTOCOL, PI_WARN, "Failed to Access state Wireshark UDVM diagnostic", EXPFILL }},
{ &ei_sigcomp_all_remaining_parameters_zero, { "sigcomp.all_remaining_parameters", PI_PROTOCOL, PI_NOTE, "All remaining parameters = 0(Not in the uploaded code as UDVM buffer initialized to Zero", EXPFILL }},
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
register_init_routine(&sigcomp_init_udvm);
register_cleanup_routine(&sigcomp_cleanup_udvm);
}
void
proto_reg_handoff_sigcomp(void)
{
static dissector_handle_t sigcomp_handle;
static dissector_handle_t sigcomp_tcp_handle;
static gboolean Initialized = FALSE;
static guint udp_port1;
static guint udp_port2;
static guint tcp_port1;
static guint tcp_port2;
if (!Initialized) {
sigcomp_handle = find_dissector("sigcomp");
sigcomp_tcp_handle = new_create_dissector_handle(dissect_sigcomp_tcp,proto_sigcomp);
sip_handle = find_dissector("sip");
Initialized=TRUE;
} else {
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
