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
proto_tree_add_item(tftp_tree, hf_tftp_source_file,
tvb, offset, i1, ENC_ASCII|ENC_NA);
tftp_info->source_file = tvb_get_string_enc(wmem_file_scope(), tvb, offset, i1, ENC_ASCII);
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
proto_tree_add_item(tftp_tree, hf_tftp_destination_file,
tvb, offset, i1, ENC_ASCII|ENC_NA);
tftp_info->destination_file =
tvb_get_string_enc(wmem_file_scope(), tvb, offset, i1, ENC_ASCII);
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
data_tvb = tvb_new_subset(tvb, offset, -1, bytes);
call_dissector(data_handle, data_tvb, pinfo, tree);
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
opcode = tvb_get_ntohs(tvb, 0);
if ((opcode == TFTP_RRQ) ||
(opcode == TFTP_WRQ) ||
(opcode == TFTP_DATA) ||
(opcode == TFTP_ACK) ||
(opcode == TFTP_ERROR) ||
(opcode == TFTP_INFO) ||
(opcode == TFTP_OACK)) {
dissect_tftp_message(tftp_info, tvb, pinfo, tree);
return TRUE;
}
else {
return FALSE;
}
}
static void
dissect_tftp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
conversation_t *conversation = NULL;
tftp_conv_info_t *tftp_info;
if (value_is_in_range(global_tftp_port_range, pinfo->destport) ||
(pinfo->match_uint == pinfo->destport)) {
conversation = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst, PT_UDP,
pinfo->srcport, 0, NO_PORT_B);
if( (conversation == NULL) || (conversation->dissector_handle != tftp_handle) ){
conversation = conversation_new(pinfo->fd->num, &pinfo->src, &pinfo->dst, PT_UDP,
pinfo->srcport, 0, NO_PORT2);
conversation_set_dissector(conversation, tftp_handle);
}
} else {
conversation = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->srcport, pinfo->destport, 0);
if( (conversation == NULL) || (conversation->dissector_handle != tftp_handle) ){
conversation = conversation_new(pinfo->fd->num, &pinfo->src, &pinfo->dst, PT_UDP,
pinfo->destport, pinfo->srcport, 0);
conversation_set_dissector(conversation, tftp_handle);
} else if (conversation->options & NO_PORT_B) {
if (pinfo->destport == conversation->key_ptr->port1)
conversation_set_port2(conversation, pinfo->srcport);
else
return;
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
module_t *tftp_module;
expert_module_t* expert_tftp;
proto_tftp = proto_register_protocol("Trivial File Transfer Protocol",
"TFTP", "tftp");
proto_register_field_array(proto_tftp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_tftp = expert_register_protocol(proto_tftp);
expert_register_field_array(expert_tftp, ei, array_length(ei));
register_dissector("tftp", dissect_tftp, proto_tftp);
range_convert_str(&global_tftp_port_range, UDP_PORT_TFTP_RANGE, MAX_UDP_PORT);
tftp_module = prefs_register_protocol(proto_tftp, proto_reg_handoff_tftp);
prefs_register_range_preference(tftp_module, "udp_ports",
"TFTP port numbers",
"Port numbers used for TFTP traffic "
"(default " UDP_PORT_TFTP_RANGE ")",
&global_tftp_port_range, MAX_UDP_PORT);
tftp_eo_tap = register_tap("tftp_eo");
}
void
proto_reg_handoff_tftp(void)
{
static range_t *tftp_port_range;
static gboolean tftp_initialized = FALSE;
if (!tftp_initialized) {
tftp_handle = find_dissector("tftp");
data_handle = find_dissector("data");
heur_dissector_add("stun", dissect_embeddedtftp_heur, proto_tftp);
tftp_initialized = TRUE;
} else {
dissector_delete_uint_range("udp.port", tftp_port_range, tftp_handle);
g_free(tftp_port_range);
}
tftp_port_range = range_copy(global_tftp_port_range);
dissector_add_uint_range("udp.port", tftp_port_range, tftp_handle);
}
