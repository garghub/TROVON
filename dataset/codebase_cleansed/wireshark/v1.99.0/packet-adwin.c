static void
adwin_request_response_handling(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *adwin_tree, guint32 seq_num, adwin_direction_t direction)
{
conversation_t *conversation;
adwin_conv_info_t *adwin_info;
adwin_transaction_t *adwin_trans;
conversation = find_or_create_conversation(pinfo);
adwin_info = (adwin_conv_info_t *)conversation_get_proto_data(conversation, proto_adwin);
if (!adwin_info) {
adwin_info = wmem_new(wmem_file_scope(), adwin_conv_info_t);
adwin_info->pdus = wmem_map_new(wmem_file_scope(), g_direct_hash, g_direct_equal);
conversation_add_proto_data(conversation, proto_adwin, adwin_info);
}
if (!pinfo->fd->flags.visited) {
if (direction == ADWIN_REQUEST) {
adwin_trans = wmem_new(wmem_file_scope(), adwin_transaction_t);
adwin_trans->req_frame = pinfo->fd->num;
adwin_trans->rep_frame = 0;
adwin_trans->req_time = pinfo->fd->abs_ts;
wmem_map_insert(adwin_info->pdus, GUINT_TO_POINTER(seq_num), (void *)adwin_trans);
} else {
adwin_trans = (adwin_transaction_t *)wmem_map_lookup(adwin_info->pdus, GUINT_TO_POINTER(seq_num));
if (adwin_trans) {
adwin_trans->rep_frame = pinfo->fd->num;
}
}
} else {
adwin_trans = (adwin_transaction_t *)wmem_map_lookup(adwin_info->pdus, GUINT_TO_POINTER(seq_num));
}
if (!adwin_trans) {
adwin_trans = wmem_new(wmem_packet_scope(), adwin_transaction_t);
adwin_trans->req_frame = 0;
adwin_trans->rep_frame = 0;
adwin_trans->req_time = pinfo->fd->abs_ts;
}
if (direction == ADWIN_REQUEST) {
if (adwin_trans->rep_frame) {
proto_item *it;
it = proto_tree_add_uint(adwin_tree, hf_adwin_response_in,
tvb, 0, 0, adwin_trans->rep_frame);
PROTO_ITEM_SET_GENERATED(it);
}
} else {
if (adwin_trans->req_frame) {
proto_item *it;
nstime_t ns;
it = proto_tree_add_uint(adwin_tree, hf_adwin_response_to,
tvb, 0, 0, adwin_trans->req_frame);
PROTO_ITEM_SET_GENERATED(it);
nstime_delta(&ns, &pinfo->fd->abs_ts, &adwin_trans->req_time);
it = proto_tree_add_time(adwin_tree, hf_adwin_response_time, tvb, 0, 0, &ns);
PROTO_ITEM_SET_GENERATED(it);
}
}
}
static void
dissect_UDPH1_generic(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *adwin_tree, proto_tree *adwin_debug_tree, gchar** info_string, const gchar* packet_name)
{
guint32 i3plus1code = 0, instructionID, seq_num;
instructionID = tvb_get_letohl(tvb, 0);
*info_string = wmem_strdup_printf(wmem_packet_scope(), "%s: %s", packet_name,
val_to_str_ext(instructionID, &instruction_mapping_ext, "unknown instruction: %d"));
if (instructionID == I_3PLUS1) {
gchar *tmp = *info_string;
i3plus1code = tvb_get_letohl(tvb, 20);
*info_string = wmem_strdup_printf(wmem_packet_scope(), "%s: %s", tmp, val_to_str_ext(i3plus1code, &instruction_3plus1_mapping_ext, "unknown 3+1 code: %d"));
}
seq_num = tvb_get_letohl(tvb, 4);
adwin_request_response_handling(tvb, pinfo, adwin_tree, seq_num, ADWIN_REQUEST);
if (! adwin_tree)
return;
SET_PACKET_TYPE(adwin_tree, APT_UDPH1_old);
proto_tree_add_item(adwin_tree, hf_adwin_instruction, tvb, 0, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_packet_index, tvb, 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_password, tvb, 8, 10, ENC_ASCII|ENC_NA);
proto_tree_add_item(adwin_debug_tree, hf_adwin_unused, tvb, 18, 2, ENC_NA);
switch(instructionID) {
case I_3PLUS1:
proto_tree_add_item(adwin_tree, hf_adwin_i3plus1, tvb, 20, 4, ENC_LITTLE_ENDIAN);
switch (i3plus1code) {
case I_3P1_SET_PAR:
proto_tree_add_item(adwin_tree, hf_adwin_parameter, tvb, 24, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_val1, tvb, 28, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_val1f, tvb, 28, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_debug_tree, hf_adwin_unused, tvb, 32, 4, ENC_NA);
break;
case I_3P1_GET_PAR:
proto_tree_add_item(adwin_tree, hf_adwin_parameter, tvb, 24, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_debug_tree, hf_adwin_unused, tvb, 28, 8, ENC_NA);
break;
case I_3P1_GET_MEMORY_INFO:
case I_3P1_GET_DETAILED_MEM_INFO:
proto_tree_add_item(adwin_tree, hf_adwin_mem_type, tvb, 24, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_debug_tree, hf_adwin_unused, tvb, 28, 8, ENC_NA);
break;
case I_3P1_START:
case I_3P1_STOP:
case I_3P1_CLEAR_PROCESS:
proto_tree_add_item(adwin_tree, hf_adwin_process_no, tvb, 24, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_debug_tree, hf_adwin_unused, tvb, 28, 8, ENC_NA);
break;
case I_3P1_GET_DATA_LENGTH:
proto_tree_add_item(adwin_tree, hf_adwin_data_no32, tvb, 24, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_debug_tree, hf_adwin_unused, tvb, 28, 8, ENC_NA);
break;
case I_3P1_CLEAR_FIFO:
case I_3P1_GET_FIFO_EMPTY:
case I_3P1_GET_FIFO_COUNT:
proto_tree_add_item(adwin_tree, hf_adwin_fifo_no32, tvb, 24, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_debug_tree, hf_adwin_unused, tvb, 28, 8, ENC_NA);
break;
default: ;
}
break;
case I_BOOT:
proto_tree_add_item(adwin_tree, hf_adwin_memsize, tvb, 20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_blocksize, tvb, 24, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_debug_tree, hf_adwin_unused, tvb, 26, 2, ENC_NA);
proto_tree_add_item(adwin_tree, hf_adwin_processor, tvb, 28, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_binfilesize, tvb, 32, 4, ENC_LITTLE_ENDIAN);
break;
case I_LOAD_BIN_FILE:
proto_tree_add_item(adwin_debug_tree, hf_adwin_unused, tvb, 20, 6, ENC_NA);
proto_tree_add_item(adwin_tree, hf_adwin_blocksize, tvb, 26, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_processor, tvb, 28, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_binfilesize, tvb, 32, 4, ENC_LITTLE_ENDIAN);
break;
case I_GET_WORKLOAD:
proto_tree_add_item(adwin_tree, hf_adwin_instruction, tvb, 20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_debug_tree, hf_adwin_unused, tvb, 24, 12, ENC_NA);
break;
case I_GET_DATA_TYPE:
proto_tree_add_item(adwin_debug_tree, hf_adwin_unused, tvb, 20, 4, ENC_NA);
proto_tree_add_item(adwin_tree, hf_adwin_data_no32, tvb, 24, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_start_index, tvb, 28, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_debug_tree, hf_adwin_unused, tvb, 32, 4, ENC_NA);
break;
case I_GET_DATA:
case I_SET_DATA:
proto_tree_add_item(adwin_tree, hf_adwin_data_type, tvb, 20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_data_no16, tvb, 24, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_blocksize, tvb, 26, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_start_index, tvb, 28, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_count, tvb, 32, 4, ENC_LITTLE_ENDIAN);
break;
case I_GET_DATA_SHIFTED_HANDSHAKE:
proto_tree_add_item(adwin_tree, hf_adwin_data_no16, tvb, 20, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_blocksize, tvb, 22, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_start_index, tvb, 24, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_count, tvb, 28, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adwin_debug_tree, hf_adwin_unused, tvb, 32, 4, ENC_NA);
break;
case I_GET_DATA_SMALL:
proto_tree_add_item(adwin_debug_tree, hf_adwin_unused, tvb, 20, 4, ENC_NA);
proto_tree_add_item(adwin_tree, hf_adwin_data_no16, tvb, 24, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_debug_tree, hf_adwin_unused, tvb, 26, 2, ENC_NA);
proto_tree_add_item(adwin_tree, hf_adwin_start_index, tvb, 28, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_count, tvb, 32, 4, ENC_LITTLE_ENDIAN);
break;
case I_GET_PAR_ALL:
proto_tree_add_item(adwin_tree, hf_adwin_start_index, tvb, 20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_count, tvb, 24, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_debug_tree, hf_adwin_unused, tvb, 28, 8, ENC_NA);
break;
case I_SET_DATA_LAST_STATUS:
proto_tree_add_item(adwin_tree, hf_adwin_data_packet_index, tvb, 20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_debug_tree, hf_adwin_unused, tvb, 24, 12, ENC_NA);
break;
case I_GET_ARM_VERSION:
proto_tree_add_item(adwin_tree, hf_adwin_armVersion, tvb, 20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_debug_tree, hf_adwin_unused, tvb, 24, 12, ENC_NA);
break;
case I_GET_FIFO:
case I_SET_FIFO:
proto_tree_add_item(adwin_tree, hf_adwin_data_type, tvb, 20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_fifo_no16, tvb, 24, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_debug_tree, hf_adwin_unused, tvb, 26, 6, ENC_NA);
proto_tree_add_item(adwin_tree, hf_adwin_count, tvb, 32, 4, ENC_LITTLE_ENDIAN);
break;
case I_GET_FIFO_RETRY:
case I_SET_FIFO_RETRY:
proto_tree_add_item(adwin_tree, hf_adwin_data_type, tvb, 20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_fifo_no16, tvb, 24, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_debug_tree, hf_adwin_unused, tvb, 26, 2, ENC_NA);
proto_tree_add_item(adwin_tree, hf_adwin_retry_packet_index, tvb, 28, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_count, tvb, 32, 4, ENC_LITTLE_ENDIAN);
break;
case I_TEST_VERSION:
proto_tree_add_item(adwin_debug_tree, hf_adwin_unused, tvb, 20, 16, ENC_NA);
break;
case I_GET_MEMORY:
proto_tree_add_item(adwin_tree, hf_adwin_address, tvb, 20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_count, tvb, 24, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_debug_tree, hf_adwin_unused, tvb, 28, 8, ENC_NA);
break;
default: ;
}
proto_tree_add_item(adwin_debug_tree, hf_adwin_link_addr, tvb, 36, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_timeout, tvb, 40, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_debug_tree, hf_adwin_osys, tvb, 44, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_debug_tree, hf_adwin_unused, tvb, 48, 4, ENC_NA);
}
static void
dissect_UDPH1_old(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *adwin_tree, proto_tree *adwin_debug_tree, gchar** info_string)
{
dissect_UDPH1_generic(tvb, pinfo, adwin_tree, adwin_debug_tree, info_string, "UDPH1 (old)");
}
static void
dissect_UDPH1_new(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *adwin_tree, proto_tree *adwin_debug_tree,
gchar** info_string)
{
gchar* dll_version_s;
gint32 dll_i;
dissect_UDPH1_generic(tvb, pinfo, adwin_tree, adwin_debug_tree, info_string, "UDPH1 (new)");
if (! adwin_tree)
return;
SET_PACKET_TYPE(adwin_tree, APT_UDPH1_new);
dll_i = tvb_get_letohl(tvb, 52);
dll_version_s = wmem_strdup_printf(wmem_packet_scope(), "%d.%d.%d",
dll_i / 1000000,
(dll_i - dll_i / 1000000 * 1000000) / 1000,
dll_i % 1000);
proto_tree_add_string(adwin_debug_tree, hf_adwin_dll_version,
tvb, 52, 4, dll_version_s);
}
static void
dissect_UDPR1(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *adwin_tree, proto_tree *adwin_debug_tree,
gchar** info_string)
{
const gchar *status_string;
guint32 seq_num, status;
status = tvb_get_letohl(tvb, 0);
status_string = try_val_to_str_ext(status, &error_code_mapping_ext);
if (status_string) {
*info_string = wmem_strdup_printf(wmem_packet_scope(), "UDPR1 Status: %s", status_string);
} else {
*info_string = wmem_strdup_printf(wmem_packet_scope(), "UDPR1 Undefined error code %d", status);
}
seq_num = tvb_get_letohl(tvb, 4);
adwin_request_response_handling(tvb, pinfo, adwin_tree, seq_num, ADWIN_RESPONSE);
if (! adwin_tree)
return;
SET_PACKET_TYPE(adwin_tree, APT_UDPR1);
proto_tree_add_item(adwin_tree, hf_adwin_status, tvb, 0, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_packet_index, tvb, 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_val1, tvb, 8, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_val1f, tvb, 8, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_val2, tvb, 12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_val3, tvb, 16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_val4, tvb, 20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_debug_tree, hf_adwin_unused, tvb, 24, 8, ENC_NA);
}
static void
dissect_UDPR2(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *adwin_tree, proto_tree *adwin_debug_tree,
gchar** info_string)
{
const gchar *status_string;
guint32 i, status, seq_num;
status = tvb_get_letohl(tvb, 0);
status_string = try_val_to_str_ext(status, &error_code_mapping_ext);
if (status_string) {
*info_string = wmem_strdup_printf(wmem_packet_scope(), "UDPR2 Status: %s", status_string);
} else {
*info_string = wmem_strdup_printf(wmem_packet_scope(), "UDPR2 Undefined error code %d", status);
}
seq_num = tvb_get_letohl(tvb, 4);
adwin_request_response_handling(tvb, pinfo, adwin_tree, seq_num, ADWIN_RESPONSE);
if (! adwin_tree)
return;
SET_PACKET_TYPE(adwin_tree, APT_UDPR2);
proto_tree_add_item(adwin_tree, hf_adwin_status, tvb, 0, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_packet_index, tvb, 4, 4, ENC_LITTLE_ENDIAN);
if (! global_adwin_dissect_data) {
call_dissector(data_handle, tvb_new_subset_length(tvb, 8, 250*4), pinfo, adwin_debug_tree);
return;
}
for (i = 0; i < 250; i++) {
proto_item *item;
guint32 offset = 8 + i * (int)sizeof(guint32);
gint32 value = tvb_get_letohl(tvb, offset);
void * fvalue = &value;
proto_tree_add_none_format(adwin_debug_tree, hf_adwin_data, tvb, offset, 4,
"Data[%3d]: %10d - %10f - 0x%08x",
i, value, *(float*)fvalue, value);
item = proto_tree_add_item(adwin_debug_tree, hf_adwin_data_int, tvb, offset, 4, ENC_LITTLE_ENDIAN);
PROTO_ITEM_SET_HIDDEN(item);
item = proto_tree_add_item(adwin_debug_tree, hf_adwin_data_float, tvb, offset, 4, ENC_LITTLE_ENDIAN);
PROTO_ITEM_SET_HIDDEN(item);
item = proto_tree_add_item(adwin_debug_tree, hf_adwin_data_hex, tvb, offset, 4, ENC_LITTLE_ENDIAN);
PROTO_ITEM_SET_HIDDEN(item);
}
}
static void
dissect_UDPR3(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *adwin_tree, proto_tree *adwin_debug_tree)
{
guint32 i, seq_num;
seq_num = tvb_get_letohl(tvb, 0);
adwin_request_response_handling(tvb, pinfo, adwin_tree, seq_num, ADWIN_RESPONSE);
if (! adwin_tree)
return;
SET_PACKET_TYPE(adwin_tree, APT_UDPR3);
proto_tree_add_item(adwin_tree, hf_adwin_packet_index, tvb, 0, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_packet_no, tvb, 4, 4, ENC_LITTLE_ENDIAN);
if (! global_adwin_dissect_data) {
call_dissector(data_handle, tvb_new_subset_length(tvb, 8, 350*4), pinfo, adwin_debug_tree);
return;
}
for (i = 0; i < 350; i++) {
proto_item *item;
guint32 offset = 8 + i * (int)sizeof(guint32);
gint32 value = tvb_get_letohl(tvb, offset);
void * fvalue = &value;
proto_tree_add_none_format(adwin_debug_tree, hf_adwin_data, tvb, offset, 4,
"Data[%3d]: %10d - %10f - 0x%08x",
i, value, *(float*)fvalue, value);
item = proto_tree_add_item(adwin_debug_tree, hf_adwin_data_int, tvb, offset, 4, ENC_LITTLE_ENDIAN);
PROTO_ITEM_SET_HIDDEN(item);
item = proto_tree_add_item(adwin_debug_tree, hf_adwin_data_float, tvb, offset, 4, ENC_LITTLE_ENDIAN);
PROTO_ITEM_SET_HIDDEN(item);
item = proto_tree_add_item(adwin_debug_tree, hf_adwin_data_hex, tvb, offset, 4, ENC_LITTLE_ENDIAN);
PROTO_ITEM_SET_HIDDEN(item);
}
}
static void
dissect_UDPR4(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *adwin_tree, proto_tree *adwin_debug_tree, gchar** info_string)
{
const gchar *status_string;
guint32 data_type, i, status, seq_num;
status = tvb_get_letohl(tvb, 0);
status_string = try_val_to_str_ext(status, &error_code_mapping_ext);
if (status_string) {
*info_string = wmem_strdup_printf(wmem_packet_scope(), "UDPR4 Status: %s", status_string);
} else {
*info_string = wmem_strdup_printf(wmem_packet_scope(), "UDPR4 Undefined error code %d", status);
}
seq_num = tvb_get_letohl(tvb, 4);
adwin_request_response_handling(tvb, pinfo, adwin_tree, seq_num, ADWIN_RESPONSE);
if (! adwin_tree)
return;
SET_PACKET_TYPE(adwin_tree, APT_UDPR4);
proto_tree_add_item(adwin_tree, hf_adwin_status, tvb, 0, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_packet_index, tvb, 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_packet_no, tvb, 1408, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_data_type, tvb, 1412, 4, ENC_LITTLE_ENDIAN);
data_type = tvb_get_letohl(tvb, 1412);
if (! global_adwin_dissect_data) {
call_dissector(data_handle, tvb_new_subset_length(tvb, 8, 350*4), pinfo, adwin_debug_tree);
return;
}
for (i = 0; i < 350; i++) {
proto_item *item;
guint32 offset = 8 + i * (int)sizeof(guint32);
gint32 value = tvb_get_letohl(tvb, offset);
void * fvalue = &value;
switch (data_type) {
case 2:
case 3:
case 4:
proto_tree_add_none_format(adwin_debug_tree, hf_adwin_data, tvb, offset, 4,
"Data[%3d]: %10d - 0x%08x",
i, value, value);
item = proto_tree_add_item(adwin_debug_tree, hf_adwin_data_int, tvb, offset, 4, ENC_LITTLE_ENDIAN);
PROTO_ITEM_SET_HIDDEN(item);
item = proto_tree_add_item(adwin_debug_tree, hf_adwin_data_hex, tvb, offset, 4, ENC_LITTLE_ENDIAN);
PROTO_ITEM_SET_HIDDEN(item);
break;
case 5:
proto_tree_add_none_format(adwin_debug_tree, hf_adwin_data, tvb, offset, 4,
"Data[%3d]: %10f - 0x%08x",
i, *(float*)fvalue, value);
item = proto_tree_add_item(adwin_debug_tree, hf_adwin_data_float, tvb, offset, 4, ENC_LITTLE_ENDIAN);
PROTO_ITEM_SET_HIDDEN(item);
item = proto_tree_add_item(adwin_debug_tree, hf_adwin_data_hex, tvb, offset, 4, ENC_LITTLE_ENDIAN);
PROTO_ITEM_SET_HIDDEN(item);
break;
default:
proto_tree_add_none_format(adwin_debug_tree, hf_adwin_data, tvb, offset, 4,
"Data[%3d]: 0x%08x",
i, value);
item = proto_tree_add_item(adwin_debug_tree, hf_adwin_data_hex, tvb, offset, 4, ENC_LITTLE_ENDIAN);
PROTO_ITEM_SET_HIDDEN(item);
}
}
}
static void
dissect_GDSHP(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *adwin_tree, proto_tree *adwin_debug_tree)
{
guint32 i, seq_num;
seq_num = tvb_get_ntohl(tvb, 0);
adwin_request_response_handling(tvb, pinfo, adwin_tree, seq_num, ADWIN_RESPONSE);
if (! adwin_tree)
return;
SET_PACKET_TYPE(adwin_tree, APT_GDSHP);
proto_tree_add_item(adwin_tree, hf_adwin_packet_index, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_packet_no, tvb, 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_unused, tvb, 8, 4, ENC_NA);
if (! global_adwin_dissect_data) {
call_dissector(data_handle, tvb_new_subset_length(tvb, 12, 336*4), pinfo, adwin_debug_tree);
return;
}
for (i = 0; i < 336; i++) {
proto_item *item;
guint32 offset = 12 + i * (int)sizeof(guint32);
gint32 value = tvb_get_letohl(tvb, offset);
void * fvalue = &value;
proto_tree_add_none_format(adwin_debug_tree, hf_adwin_data, tvb, offset, 4,
"Data[%3d]: %10d - %10f - 0x%08x",
i, value, *(float*)fvalue, value);
item = proto_tree_add_item(adwin_debug_tree, hf_adwin_data_int, tvb, offset, 4, ENC_LITTLE_ENDIAN);
PROTO_ITEM_SET_HIDDEN(item);
item = proto_tree_add_item(adwin_debug_tree, hf_adwin_data_float, tvb, offset, 4, ENC_LITTLE_ENDIAN);
PROTO_ITEM_SET_HIDDEN(item);
item = proto_tree_add_item(adwin_debug_tree, hf_adwin_data_hex, tvb, offset, 4, ENC_LITTLE_ENDIAN);
PROTO_ITEM_SET_HIDDEN(item);
}
}
static void
dissect_GDSHR(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *adwin_tree, proto_tree *adwin_debug_tree)
{
guint32 is_range, packet_start, packet_end, seq_num;
proto_item *ti;
seq_num = tvb_get_ntohl(tvb, 0);
adwin_request_response_handling(tvb, pinfo, adwin_tree, seq_num, ADWIN_RESPONSE);
if (! adwin_tree)
return;
SET_PACKET_TYPE(adwin_tree, APT_GDSHR);
proto_tree_add_item(adwin_tree, hf_adwin_packet_index, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_request_no, tvb, 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_complete_packets, tvb, 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adwin_debug_tree, hf_adwin_is_range, tvb, 12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adwin_debug_tree, hf_adwin_packet_start, tvb, 16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adwin_debug_tree, hf_adwin_packet_end, tvb, 20, 4, ENC_BIG_ENDIAN);
is_range = tvb_get_ntohl(tvb, 12);
packet_start = tvb_get_ntohl(tvb, 16);
switch(is_range) {
case 0:
ti = proto_tree_add_uint_format_value(adwin_tree, hf_adwin_gdsh_status, tvb, 12, 4,
is_range, "get single packet no %d", packet_start);
break;
case 1:
packet_end = tvb_get_ntohl(tvb, 20);
ti = proto_tree_add_uint_format_value(adwin_tree, hf_adwin_gdsh_status, tvb, 12, 4,
is_range, "get packets %d - %d",
packet_start, packet_end);
break;
case 2:
ti = proto_tree_add_uint_format_value(adwin_tree, hf_adwin_gdsh_status, tvb, 12, 4,
is_range, "finished");
break;
default:
ti = proto_tree_add_uint_format_value(adwin_tree, hf_adwin_gdsh_status, tvb, 12, 4,
is_range, "unknown code %d", is_range);
}
proto_item_set_len(ti, 12);
proto_tree_add_item(adwin_debug_tree, hf_adwin_unused, tvb, 24, 40, ENC_NA);
}
static int
dissect_adwin(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti, *ti2;
proto_tree *adwin_tree, *adwin_debug_tree;
gchar *info_string;
guint32 length;
length = tvb_reported_length(tvb);
if(! (length == UDPH1_OLD_LENGTH
|| length == UDPH1_NEW_LENGTH
|| length == UDPR1_LENGTH
|| length == UDPH2_LENGTH
|| length == UDPR2_LENGTH
|| length == UDPR3_LENGTH
|| length == UDPR4_LENGTH
|| length == GetDataSHPacket_LENGTH
|| length == GetDataSHRequest_LENGTH))
return(0);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ADwin");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
ti = proto_tree_add_item(tree, proto_adwin, tvb, 0, -1, ENC_NA);
adwin_tree = proto_item_add_subtree(ti, ett_adwin);
ti2 = proto_tree_add_item(adwin_tree, proto_adwin, tvb, 0, -1, ENC_NA);
adwin_debug_tree = proto_item_add_subtree(ti2, ett_adwin_debug);
proto_item_set_text(ti2, "ADwin Debug information");
} else {
adwin_tree = NULL;
adwin_debug_tree = NULL;
}
switch (length) {
case UDPH1_OLD_LENGTH:
dissect_UDPH1_old(tvb, pinfo, adwin_tree, adwin_debug_tree, &info_string);
break;
case UDPH1_NEW_LENGTH:
dissect_UDPH1_new(tvb, pinfo, adwin_tree, adwin_debug_tree, &info_string);
break;
case UDPR1_LENGTH:
dissect_UDPR1(tvb, pinfo, adwin_tree, adwin_debug_tree, &info_string);
break;
case UDPH2_LENGTH:
info_string = wmem_strdup(wmem_packet_scope(), "UDPH2 - UNUSED");
break;
case UDPR2_LENGTH:
dissect_UDPR2(tvb, pinfo, adwin_tree, adwin_debug_tree, &info_string);
break;
case UDPR3_LENGTH:
dissect_UDPR3(tvb, pinfo, adwin_tree, adwin_debug_tree);
info_string = wmem_strdup(wmem_packet_scope(), "UDPR3");
break;
case UDPR4_LENGTH:
dissect_UDPR4(tvb, pinfo, adwin_tree, adwin_debug_tree, &info_string);
break;
case GetDataSHPacket_LENGTH:
dissect_GDSHP(tvb, pinfo, adwin_tree, adwin_debug_tree);
info_string = wmem_strdup(wmem_packet_scope(), "GDSHP");
break;
case GetDataSHRequest_LENGTH:
dissect_GDSHR(tvb, pinfo, adwin_tree, adwin_debug_tree);
info_string = wmem_strdup(wmem_packet_scope(), "GDSHR");
break;
default:
info_string = wmem_strdup_printf(wmem_packet_scope(), "Unknown ADwin packet, length: %d", length);
break;
}
col_add_str(pinfo->cinfo, COL_INFO, info_string);
return (tvb_reported_length(tvb));
}
void
proto_reg_handoff_adwin(void)
{
static int adwin_prefs_initialized = FALSE;
static dissector_handle_t adwin_handle;
static unsigned int udp_port;
if (! adwin_prefs_initialized) {
adwin_handle = new_create_dissector_handle(dissect_adwin, proto_adwin);
data_handle = find_dissector("data");
adwin_prefs_initialized = TRUE;
} else {
dissector_delete_uint("udp.port", udp_port, adwin_handle);
}
udp_port = global_adwin_udp_port;
dissector_add_uint("udp.port", global_adwin_udp_port, adwin_handle);
}
void
proto_register_adwin(void)
{
static hf_register_info hf[] = {
{ &hf_adwin_address,
{ "memory address", "adwin.address",
FT_UINT32, BASE_HEX, NULL, 0x0,
"Memory address to read on DSP", HFILL }
},
{ &hf_adwin_armVersion,
{ "Get ARM Version", "adwin.armVersion",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_binfilesize,
{ "File size", "adwin.binfilesize",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Size of binary file", HFILL }
},
{ &hf_adwin_blocksize,
{ "Blocksize", "adwin.blocksize",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Maximum number of unacknowledged packets", HFILL }
},
{ &hf_adwin_complete_packets,
{ "Complete packets", "adwin.complete_packets",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Highest sequential package number", HFILL }
},
{ &hf_adwin_count,
{ "Count", "adwin.count",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of longs", HFILL }
},
{ &hf_adwin_data,
{ "Data", "adwin.data",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_data_int,
{ "Data element int", "adwin.data_int",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_data_float,
{ "Data element float", "adwin.data_float",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_data_hex,
{ "Data element hex", "adwin.data_hex",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_data_no16,
{ "Data No. (16bit)", "adwin.data",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_data_no32,
{ "Data No. (32bit)", "adwin.data",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_data_type,
{ "Data type", "adwin.data_type",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &data_type_mapping_ext, 0x0,
NULL, HFILL }
},
{ &hf_adwin_data_packet_index,
{ "Data packet index", "adwin.data_packet_index",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_dll_version,
{ "DLL Version", "adwin.dll_version",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_fifo_no16,
{ "FiFo No. (16bit)", "adwin.fifo_no",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_fifo_no32,
{ "FiFo No. (32bit)", "adwin.fifo_no",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_instruction,
{ "Instruction", "adwin.instruction",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &instruction_mapping_ext, 0x0,
NULL, HFILL }
},
{ &hf_adwin_is_range,
{ "packets are a range", "adwin.is_range",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_i3plus1,
{ "3+1 Instruction", "adwin.i3plus1",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &instruction_3plus1_mapping_ext, 0x0,
NULL, HFILL }
},
{ &hf_adwin_link_addr,
{ "Link address", "adwin.link_addr",
FT_UINT32, BASE_HEX, NULL, 0x0,
"Link address (TCP/IP Server only)", HFILL }
},
{ &hf_adwin_mem_type,
{ "Memory type", "adwin.mem_type",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_memsize,
{ "Memory size", "adwin.memsize",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_osys,
{ "Operating system", "adwin.osys",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &osys_mapping_ext, 0x0,
"Operating system / environment", HFILL }
},
{ &hf_adwin_packet_end,
{ "End packet", "adwin.packet_end",
FT_UINT32, BASE_DEC, NULL, 0x0,
"GDSH: End Packet", HFILL }
},
{ &hf_adwin_gdsh_status,
{ "GDSH status", "adwin.gdsh_status",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_packet_index,
{ "Packet index", "adwin.packet_index",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_packet_no,
{ "Packet No.", "adwin.packet_no",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_packet_start,
{ "Starting packet", "adwin.packet_start",
FT_UINT32, BASE_DEC, NULL, 0x0,
"GDSH: Starting Packet", HFILL }
},
{ &hf_adwin_packet_type,
{ "Packet type", "adwin.packet_type",
FT_INT32, BASE_DEC|BASE_EXT_STRING, &packet_type_mapping_ext, 0x0,
NULL, HFILL }
},
{ &hf_adwin_parameter,
{ "Parameter", "adwin.parameter",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &parameter_mapping_ext, 0x0,
NULL, HFILL }
},
{ &hf_adwin_password,
{ "Password", "adwin.password",
FT_STRING, BASE_NONE, NULL, 0x0,
"Password for ADwin system", HFILL }
},
{ &hf_adwin_process_no,
{ "Process No.", "adwin.process_no",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_processor,
{ "Processor", "adwin.processor",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_response_in,
{ "Response In", "adwin.response_in",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"The response to this ADwin request is in this frame", HFILL }
},
{ &hf_adwin_response_to,
{ "Request In", "adwin.response_to",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This is a response to the ADwin request in this frame", HFILL }
},
{ &hf_adwin_response_time,
{ "Response time", "adwin.response_time",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"The time between the Request and the Reply", HFILL }
},
{ &hf_adwin_retry_packet_index,
{ "Retry packet index", "adwin.retry_packet_index",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_request_no,
{ "Request Number", "adwin.request_no",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Request number index", HFILL }
},
{ &hf_adwin_start_index,
{ "Start index", "adwin.start_index",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_status,
{ "Status", "adwin.status",
FT_INT32, BASE_DEC|BASE_EXT_STRING, &error_code_mapping_ext, 0x0,
NULL, HFILL }
},
{ &hf_adwin_timeout,
{ "Timeout", "adwin.timeout",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Timeout in ms", HFILL }
},
{ &hf_adwin_unused,
{ "Unused", "adwin.unused",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_val1,
{ "Value 1 (as int)", "adwin.val1",
FT_INT32, BASE_DEC, NULL, 0x0,
"Generic return value 1 interpreted as integer (correct interpretation depends on request).", HFILL }
},
{ &hf_adwin_val1f,
{ "Value 1 (as float)", "adwin.val1f",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Generic return value 1 interpreted as float (correct interpretation depends on request).", HFILL }
},
{ &hf_adwin_val2,
{ "Value 2", "adwin.val2",
FT_INT32, BASE_DEC, NULL, 0x0,
"Generic return value 2 (interpretation depends on request).", HFILL }
},
{ &hf_adwin_val3,
{ "Value 3", "adwin.val3",
FT_INT32, BASE_DEC, NULL, 0x0,
"Generic return value 3 (interpretation depends on request).", HFILL }
},
{ &hf_adwin_val4,
{ "Value 4", "adwin.val4",
FT_INT32, BASE_DEC, NULL, 0x0,
"Generic return value 4 (interpretation depends on request).", HFILL }
},
};
static gint *ett[] = {
&ett_adwin,
&ett_adwin_debug,
};
module_t *adwin_module;
proto_adwin = proto_register_protocol("ADwin communication protocol",
"ADwin", "adwin");
proto_register_field_array(proto_adwin, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
adwin_module = prefs_register_protocol(proto_adwin, proto_reg_handoff_adwin);
prefs_register_uint_preference(adwin_module, "udp.port", "ADwin UDP Port",
"Set the UDP port for ADwin packets (if other"
" than the default of 6543)",
10, &global_adwin_udp_port);
prefs_register_bool_preference(adwin_module, "dissect_data",
"Dissect Data sections",
"Specify if the Data sections of packets "
"should be dissected or not",
&global_adwin_dissect_data);
}
