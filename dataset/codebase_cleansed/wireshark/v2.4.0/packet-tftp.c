static gboolean
tftp_eo_packet(void *tapdata, packet_info *pinfo, epan_dissect_t *edt _U_, const void *data)
{
export_object_list_t *object_list = (export_object_list_t *)tapdata;
const tftp_eo_t *eo_info = (const tftp_eo_t *)data;
export_object_entry_t *entry;
GSList *block_iterator;
guint payload_data_offset = 0;
eo_info_dynamic_t *dynamic_info;
entry = g_new(export_object_entry_t, 1);
entry->pkt_num = pinfo->num;
entry->filename = g_path_get_basename(eo_info->filename);
entry->payload_len = eo_info->payload_len;
entry->payload_data = (guint8 *)g_try_malloc((gsize)entry->payload_len);
for (block_iterator = eo_info->block_list; block_iterator; block_iterator = block_iterator->next) {
file_block_t *block = (file_block_t*)block_iterator->data;
memcpy(entry->payload_data + payload_data_offset,
block->data,
block->length);
payload_data_offset += block->length;
}
entry->hostname = NULL;
entry->content_type = NULL;
dynamic_info = g_new(eo_info_dynamic_t, 1);
dynamic_info->filename = eo_info->filename;
dynamic_info->block_list = eo_info->block_list;
s_dynamic_info_list = g_slist_append(s_dynamic_info_list, (eo_info_dynamic_t*)dynamic_info);
object_list->add_entry(object_list->gui_data, entry);
return TRUE;
}
static void cleanup_tftp_eo(eo_info_dynamic_t *dynamic_info)
{
GSList *block_iterator;
g_free(dynamic_info->filename);
for (block_iterator = dynamic_info->block_list; block_iterator; block_iterator = block_iterator->next) {
file_block_t *block = (file_block_t*)(block_iterator->data);
wmem_free(NULL, block->data);
g_free(block);
}
}
static void tftp_eo_cleanup(void)
{
GSList *dynamic_iterator;
for (dynamic_iterator = s_dynamic_info_list; dynamic_iterator; dynamic_iterator = dynamic_iterator->next) {
eo_info_dynamic_t *dynamic_info = (eo_info_dynamic_t*)dynamic_iterator->data;
cleanup_tftp_eo(dynamic_info);
}
s_dynamic_info_list = NULL;
}
static void
tftp_dissect_options(tvbuff_t *tvb, packet_info *pinfo, int offset,
proto_tree *tree, guint16 opcode, tftp_conv_info_t *tftp_info)
{
int option_len, value_len;
int value_offset;
const char *optionname;
const char *optionvalue;
proto_tree *opt_tree;
while (tvb_offset_exists(tvb, offset)) {
option_len = tvb_strsize(tvb, offset);
value_offset = offset + option_len;
value_len = tvb_strsize(tvb, value_offset);
optionname = tvb_format_text(tvb, offset, option_len-1);
optionvalue = tvb_format_text(tvb, value_offset, value_len-1);
opt_tree = proto_tree_add_subtree_format(tree, tvb, offset, option_len+value_len,
ett_tftp_option, NULL, "Option: %s = %s", optionname, optionvalue);
proto_tree_add_item(opt_tree, hf_tftp_option_name, tvb, offset,
option_len, ENC_ASCII|ENC_NA);
proto_tree_add_item(opt_tree, hf_tftp_option_value, tvb, value_offset,
value_len, ENC_ASCII|ENC_NA);
offset += option_len + value_len;
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s=%s",
optionname, optionvalue);
if (!g_ascii_strcasecmp((const char *)optionname, "blksize") &&
opcode == TFTP_OACK) {
gint blocksize = (gint)strtol((const char *)optionvalue, NULL, 10);
if (blocksize < 8 || blocksize > 65464) {
expert_add_info(pinfo, NULL, &ei_tftp_blocksize_range);
} else {
tftp_info->blocksize = blocksize;
}
}
}
}
static void cleanup_tftp_blocks(tftp_conv_info_t *conv)
{
GSList *block_iterator;
for (block_iterator = conv->block_list; block_iterator; block_iterator = block_iterator->next) {
file_block_t *block = (file_block_t*)block_iterator->data;
wmem_free(NULL, block->data);
g_free(block);
}
conv->block_list = NULL;
conv->file_length = 0;
}
static void dissect_tftp_message(tftp_conv_info_t *tftp_info,
tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree)
{
proto_tree *tftp_tree;
proto_item *ti;
gint offset = 0;
guint16 opcode;
guint16 bytes;
guint16 blocknum;
guint i1;
guint16 error;
tvbuff_t *data_tvb = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TFTP");
ti = proto_tree_add_item(tree, proto_tftp, tvb, offset, -1, ENC_NA);
tftp_tree = proto_item_add_subtree(ti, ett_tftp);
opcode = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tftp_tree, hf_tftp_opcode, tvb, offset, 2, opcode);
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(opcode, tftp_opcode_vals, "Unknown (0x%04x)"));
offset += 2;
if (opcode!=TFTP_RRQ && opcode!=TFTP_WRQ) {
if (tftp_info->source_file) {
ti = proto_tree_add_string(tftp_tree, hf_tftp_source_file, tvb,
0, 0, tftp_info->source_file);
PROTO_ITEM_SET_GENERATED(ti);
}
if (tftp_info->destination_file) {
ti = proto_tree_add_string(tftp_tree, hf_tftp_destination_file, tvb,
0, 0, tftp_info->destination_file);
PROTO_ITEM_SET_GENERATED(ti);
}
}
switch (opcode) {
case TFTP_RRQ:
i1 = tvb_strsize(tvb, offset);
proto_tree_add_item_ret_string(tftp_tree, hf_tftp_source_file,
tvb, offset, i1, ENC_ASCII|ENC_NA, wmem_file_scope(), &tftp_info->source_file);
tftp_info->destination_file = NULL;
col_append_fstr(pinfo->cinfo, COL_INFO, ", File: %s",
tvb_format_stringzpad(tvb, offset, i1));
offset += i1;
i1 = tvb_strsize(tvb, offset);
proto_tree_add_item(tftp_tree, hf_tftp_transfer_type,
tvb, offset, i1, ENC_ASCII|ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Transfer type: %s",
tvb_format_stringzpad(tvb, offset, i1));
offset += i1;
tftp_dissect_options(tvb, pinfo, offset, tftp_tree,
opcode, tftp_info);
break;
case TFTP_WRQ:
i1 = tvb_strsize(tvb, offset);
proto_tree_add_item_ret_string(tftp_tree, hf_tftp_destination_file,
tvb, offset, i1, ENC_ASCII|ENC_NA, wmem_file_scope(), &tftp_info->destination_file);
tftp_info->source_file = NULL;
col_append_fstr(pinfo->cinfo, COL_INFO, ", File: %s",
tvb_format_stringzpad(tvb, offset, i1));
offset += i1;
i1 = tvb_strsize(tvb, offset);
proto_tree_add_item(tftp_tree, hf_tftp_transfer_type,
tvb, offset, i1, ENC_ASCII|ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Transfer type: %s",
tvb_format_stringzpad(tvb, offset, i1));
offset += i1;
tftp_dissect_options(tvb, pinfo, offset, tftp_tree,
opcode, tftp_info);
break;
case TFTP_INFO:
tftp_dissect_options(tvb, pinfo, offset, tftp_tree,
opcode, tftp_info);
break;
case TFTP_DATA:
blocknum = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tftp_tree, hf_tftp_blocknum, tvb, offset, 2,
blocknum);
if (!pinfo->fd->flags.visited) {
if (blocknum > tftp_info->next_block_num) {
tftp_info->next_block_num = blocknum + 1;
tftp_info->blocks_missing = TRUE;
}
else if (blocknum == tftp_info->next_block_num) {
tftp_info->next_block_num++;
}
}
offset += 2;
bytes = tvb_reported_length_remaining(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Block: %i%s",
blocknum,
(bytes < tftp_info->blocksize)?" (last)":"" );
if (bytes > 0) {
data_tvb = tvb_new_subset_length_caplen(tvb, offset, -1, bytes);
call_data_dissector(data_tvb, pinfo, tree);
}
if (have_tap_listener(tftp_eo_tap) && !tftp_info->blocks_missing) {
file_block_t *block;
if (blocknum == 1) {
cleanup_tftp_blocks(tftp_info);
tftp_info->next_tap_block_num = 1;
}
if (blocknum != tftp_info->next_tap_block_num) {
return;
}
if (bytes > 0) {
block = (file_block_t*)g_malloc(sizeof(file_block_t));
block->length = bytes;
block->data = tvb_memdup(NULL, data_tvb, 0, bytes);
tftp_info->block_list = g_slist_append(tftp_info->block_list, block);
tftp_info->file_length += bytes;
tftp_info->next_tap_block_num++;
}
if (bytes < tftp_info->blocksize) {
tftp_eo_t *eo_info;
if ((tftp_info->source_file == NULL) && (tftp_info->destination_file == NULL)) {
cleanup_tftp_blocks(tftp_info);
return;
}
eo_info = wmem_new(wmem_packet_scope(), tftp_eo_t);
if (tftp_info->source_file) {
eo_info->filename = g_strdup(tftp_info->source_file);
}
else if (tftp_info->destination_file) {
eo_info->filename = g_strdup(tftp_info->destination_file);
}
eo_info->payload_len = tftp_info->file_length;
eo_info->pkt_num = blocknum;
eo_info->block_list = tftp_info->block_list;
tap_queue_packet(tftp_eo_tap, pinfo, eo_info);
tftp_info->block_list = NULL;
tftp_info->next_tap_block_num = 1;
}
}
break;
case TFTP_ACK:
blocknum = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tftp_tree, hf_tftp_blocknum, tvb, offset, 2,
blocknum);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Block: %i",
blocknum);
break;
case TFTP_ERROR:
error = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tftp_tree, hf_tftp_error_code, tvb, offset, 2,
error);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Code: %s",
val_to_str(error, tftp_error_code_vals, "Unknown (%u)"));
offset += 2;
i1 = tvb_strsize(tvb, offset);
proto_tree_add_item(tftp_tree, hf_tftp_error_string, tvb, offset,
i1, ENC_ASCII|ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Message: %s",
tvb_format_stringzpad(tvb, offset, i1));
expert_add_info(pinfo, NULL, &ei_tftp_blocksize_range);
break;
case TFTP_OACK:
tftp_dissect_options(tvb, pinfo, offset, tftp_tree,
opcode, tftp_info);
break;
default:
proto_tree_add_item(tftp_tree, hf_tftp_data, tvb, offset, -1, ENC_NA);
break;
}
}
static gboolean
dissect_embeddedtftp_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
conversation_t *conversation = NULL;
guint16 opcode;
tftp_conv_info_t *tftp_info;
if (tvb_captured_length(tvb) < MIN_HDR_LEN)
return FALSE;
opcode = tvb_get_ntohs(tvb, 0);
switch (opcode) {
case TFTP_RRQ:
case TFTP_WRQ:
{
gint char_offset = 1;
while (tvb_captured_length_remaining(tvb, char_offset)) {
gchar c = (gchar)tvb_get_guint8(tvb, char_offset++);
if (c == '\0') {
break;
}
else if (!g_ascii_isprint(c)) {
return FALSE;
}
}
}
case TFTP_DATA:
case TFTP_ACK:
case TFTP_OACK:
case TFTP_INFO:
break;
case TFTP_ERROR:
switch (tvb_get_ntohs(tvb, 2)) {
case TFTP_ERR_NOT_DEF:
case TFTP_ERR_NOT_FOUND:
case TFTP_ERR_NOT_ALLOWED:
case TFTP_ERR_DISK_FULL:
case TFTP_ERR_BAD_OP:
case TFTP_ERR_BAD_ID:
case TFTP_ERR_EXISTS:
case TFTP_ERR_NO_USER:
case TFTP_ERR_OPT_FAIL:
break;
default:
return FALSE;
}
break;
default:
return FALSE;
}
conversation = find_or_create_conversation(pinfo);
tftp_info = (tftp_conv_info_t *)conversation_get_proto_data(conversation, proto_tftp);
if (!tftp_info) {
tftp_info = wmem_new(wmem_file_scope(), tftp_conv_info_t);
tftp_info->blocksize = 512;
tftp_info->source_file = NULL;
tftp_info->destination_file = NULL;
tftp_info->next_block_num = 1;
tftp_info->blocks_missing = FALSE;
tftp_info->next_tap_block_num = 1;
tftp_info->block_list = NULL;
tftp_info->file_length = 0;
conversation_add_proto_data(conversation, proto_tftp, tftp_info);
}
dissect_tftp_message(tftp_info, tvb, pinfo, tree);
return TRUE;
}
static int
dissect_tftp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
conversation_t *conversation = NULL;
tftp_conv_info_t *tftp_info;
if (value_is_in_range(global_tftp_port_range, pinfo->destport) ||
(pinfo->match_uint == pinfo->destport)) {
conversation = find_conversation(pinfo->num, &pinfo->src, &pinfo->dst, PT_UDP,
pinfo->srcport, 0, NO_PORT_B);
if( (conversation == NULL) || (conversation_get_dissector(conversation, pinfo->num) != tftp_handle) ){
conversation = conversation_new(pinfo->num, &pinfo->src, &pinfo->dst, PT_UDP,
pinfo->srcport, 0, NO_PORT2);
conversation_set_dissector(conversation, tftp_handle);
}
} else {
conversation = find_conversation(pinfo->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->srcport, pinfo->destport, 0);
if( (conversation == NULL) || (conversation_get_dissector(conversation, pinfo->num) != tftp_handle) ){
conversation = conversation_new(pinfo->num, &pinfo->src, &pinfo->dst, PT_UDP,
pinfo->destport, pinfo->srcport, 0);
conversation_set_dissector(conversation, tftp_handle);
} else if (conversation->options & NO_PORT_B) {
if (pinfo->destport == conversation->key_ptr->port1)
conversation_set_port2(conversation, pinfo->srcport);
else
return 0;
}
}
tftp_info = (tftp_conv_info_t *)conversation_get_proto_data(conversation, proto_tftp);
if (!tftp_info) {
tftp_info = wmem_new(wmem_file_scope(), tftp_conv_info_t);
tftp_info->blocksize = 512;
tftp_info->source_file = NULL;
tftp_info->destination_file = NULL;
tftp_info->next_block_num = 1;
tftp_info->blocks_missing = FALSE;
tftp_info->next_tap_block_num = 1;
tftp_info->block_list = NULL;
tftp_info->file_length = 0;
conversation_add_proto_data(conversation, proto_tftp, tftp_info);
}
dissect_tftp_message(tftp_info, tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
static void
apply_tftp_prefs(void) {
global_tftp_port_range = prefs_get_range_value("tftp", "udp.port");
}
void
proto_register_tftp(void)
{
static hf_register_info hf[] = {
{ &hf_tftp_opcode,
{ "Opcode", "tftp.opcode",
FT_UINT16, BASE_DEC, VALS(tftp_opcode_vals), 0x0,
"TFTP message type", HFILL }},
{ &hf_tftp_source_file,
{ "Source File", "tftp.source_file",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"TFTP source file name", HFILL }},
{ &hf_tftp_destination_file,
{ "DESTINATION File", "tftp.destination_file",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"TFTP source file name", HFILL }},
{ &hf_tftp_transfer_type,
{ "Type", "tftp.type",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"TFTP transfer type", HFILL }},
{ &hf_tftp_blocknum,
{ "Block", "tftp.block",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Block number", HFILL }},
{ &hf_tftp_error_code,
{ "Error code", "tftp.error.code",
FT_UINT16, BASE_DEC, VALS(tftp_error_code_vals), 0x0,
"Error code in case of TFTP error message", HFILL }},
{ &hf_tftp_error_string,
{ "Error message", "tftp.error.message",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Error string in case of TFTP error message", HFILL }},
{ &hf_tftp_option_name,
{ "Option name", "tftp.option.name",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_tftp_option_value,
{ "Option value", "tftp.option.value",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_tftp_data,
{ "Data", "tftp.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_tftp,
&ett_tftp_option,
};
static ei_register_info ei[] = {
{ &ei_tftp_blocksize_range, { "tftp.blocksize_range", PI_RESPONSE_CODE, PI_WARN, "TFTP blocksize out of range", EXPFILL }},
};
expert_module_t* expert_tftp;
proto_tftp = proto_register_protocol("Trivial File Transfer Protocol", "TFTP", "tftp");
proto_register_field_array(proto_tftp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_tftp = expert_register_protocol(proto_tftp);
expert_register_field_array(expert_tftp, ei, array_length(ei));
tftp_handle = register_dissector("tftp", dissect_tftp, proto_tftp);
prefs_register_protocol(proto_tftp, apply_tftp_prefs);
tftp_eo_tap = register_export_object(proto_tftp, tftp_eo_packet, tftp_eo_cleanup);
}
void
proto_reg_handoff_tftp(void)
{
heur_dissector_add("stun", dissect_embeddedtftp_heur, "TFTP over TURN", "tftp_stun", proto_tftp, HEURISTIC_ENABLE);
dissector_add_uint_range_with_preference("udp.port", UDP_PORT_TFTP_RANGE, tftp_handle);
}
