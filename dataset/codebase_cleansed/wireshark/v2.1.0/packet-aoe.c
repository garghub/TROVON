static guint
ata_cmd_hash_matched(gconstpointer k)
{
return GPOINTER_TO_UINT(k);
}
static gint
ata_cmd_equal_matched(gconstpointer k1, gconstpointer k2)
{
return k1==k2;
}
static guint
ata_cmd_hash_unmatched(gconstpointer k)
{
const ata_info_t *key = (const ata_info_t *)k;
return key->tag;
}
static gint
ata_cmd_equal_unmatched(gconstpointer k1, gconstpointer k2)
{
const ata_info_t *key1 = (const ata_info_t *)k1;
const ata_info_t *key2 = (const ata_info_t *)k2;
return (key1->tag==key2->tag)&&(key1->conversation==key2->conversation);
}
static void
dissect_ata_pdu(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, gboolean response, guint32 tag)
{
proto_item *tmp_item;
guint8 aflags;
guint64 lba;
ata_info_t *ata_info=NULL;
conversation_t *conversation;
conversation = find_or_create_conversation(pinfo);
if( !(pinfo->fd->flags.visited) ){
if(!response){
ata_info_t *tmp_ata_info;
ata_info=wmem_new(wmem_file_scope(), ata_info_t);
ata_info->tag=tag;
ata_info->conversation=conversation;
ata_info->request_frame=pinfo->num;
ata_info->response_frame=0;
ata_info->cmd=tvb_get_guint8(tvb, offset+3);
ata_info->req_time=pinfo->abs_ts;
tmp_ata_info=(ata_info_t *)g_hash_table_lookup(ata_cmd_unmatched, ata_info);
if(tmp_ata_info){
g_hash_table_remove(ata_cmd_unmatched, tmp_ata_info);
}
g_hash_table_insert(ata_cmd_unmatched, ata_info, ata_info);
} else {
ata_info_t tmp_ata_info;
tmp_ata_info.tag=tag;
tmp_ata_info.conversation=conversation;
ata_info=(ata_info_t *)g_hash_table_lookup(ata_cmd_unmatched, &tmp_ata_info);
if(ata_info){
ata_info->response_frame=pinfo->num;
g_hash_table_remove(ata_cmd_unmatched, ata_info);
g_hash_table_insert(ata_cmd_matched, GUINT_TO_POINTER(ata_info->request_frame), ata_info);
g_hash_table_insert(ata_cmd_matched, GUINT_TO_POINTER(ata_info->response_frame), ata_info);
}
}
} else {
ata_info=(ata_info_t *)g_hash_table_lookup(ata_cmd_matched, GUINT_TO_POINTER(pinfo->num));
}
if(ata_info){
if(response){
if(ata_info->request_frame){
nstime_t delta_ts;
tmp_item=proto_tree_add_uint(tree, hf_aoe_response_to, tvb, 0, 0, ata_info->request_frame);
PROTO_ITEM_SET_GENERATED(tmp_item);
nstime_delta(&delta_ts, &pinfo->abs_ts, &ata_info->req_time);
tmp_item=proto_tree_add_time(tree, hf_aoe_time, tvb, offset, 0, &delta_ts);
PROTO_ITEM_SET_GENERATED(tmp_item);
}
} else {
if(ata_info->response_frame){
tmp_item=proto_tree_add_uint(tree, hf_aoe_response_in, tvb, 0, 0, ata_info->response_frame);
PROTO_ITEM_SET_GENERATED(tmp_item);
}
}
}
aflags=tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_aoe_aflags_e, tvb, offset, 1, ENC_BIG_ENDIAN);
if(aflags&AOE_AFLAGS_E){
proto_tree_add_item(tree, hf_aoe_aflags_d, tvb, offset, 1, ENC_BIG_ENDIAN);
}
if(aflags&AOE_AFLAGS_W){
proto_tree_add_item(tree, hf_aoe_aflags_a, tvb, offset, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_item(tree, hf_aoe_aflags_w, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_aoe_err_feature, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_aoe_sector_count, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if(!response){
proto_tree_add_item(tree, hf_aoe_acmd, tvb, offset, 1, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " ATA:%s", val_to_str(tvb_get_guint8(tvb, offset), ata_cmd_vals, " Unknown ATA<0x%02x>"));
} else {
proto_tree_add_item(tree, hf_aoe_astatus, tvb, offset, 1, ENC_BIG_ENDIAN);
if(ata_info != NULL && ata_info->request_frame){
tmp_item=proto_tree_add_uint(tree, hf_aoe_acmd, tvb, 0, 0, ata_info->cmd);
PROTO_ITEM_SET_GENERATED(tmp_item);
col_append_fstr(pinfo->cinfo, COL_INFO, " ATA:%s", val_to_str(ata_info->cmd, ata_cmd_vals, " Unknown ATA<0x%02x>"));
}
}
offset++;
lba=tvb_get_letohs(tvb, offset+4);
lba=(lba<<32)|tvb_get_letohl(tvb, offset);
offset+=8;
proto_tree_add_uint64(tree, hf_aoe_lba, tvb, offset-8, 6, lba);
}
static void
dissect_aoe_v1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 flags, cmd;
guint32 tag;
proto_item *flags_item;
proto_tree *flags_tree;
flags=tvb_get_guint8(tvb, 0)&0x0f;
flags_tree=proto_tree_add_subtree(tree, tvb, 0, 1, ett_aoe_flags, &flags_item, "Flags:");
proto_tree_add_item(flags_tree, hf_aoe_flags_response, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aoe_flags_error, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_item_append_text(flags_item,(flags&AOE_FLAGS_RESPONSE)?" Response":" Request");
if(flags&AOE_FLAGS_ERROR){
proto_item_append_text(flags_item, " Error");
}
if(flags&AOE_FLAGS_ERROR){
proto_tree_add_item(tree, hf_aoe_error, tvb, 1, 1, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, "Error:%s ", val_to_str(tvb_get_guint8(tvb, 1), error_vals, "Unknown error<%d>"));
}
proto_tree_add_item(tree, hf_aoe_major, tvb, 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_aoe_minor, tvb, 4, 1, ENC_BIG_ENDIAN);
cmd=tvb_get_guint8(tvb, 5);
proto_tree_add_item(tree, hf_aoe_cmd, tvb, 5, 1, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s %s", val_to_str(cmd, cmd_vals, "Unknown command<%d>"), (flags&AOE_FLAGS_RESPONSE)?"Response":"Request");
tag=tvb_get_letohl(tvb, 6);
proto_tree_add_item(tree, hf_aoe_tag, tvb, 6, 4, ENC_BIG_ENDIAN);
switch(cmd){
case AOE_CMD_ISSUE_ATA_COMMAND:
dissect_ata_pdu(pinfo, tree, tvb, 10, flags&AOE_FLAGS_RESPONSE, tag);
break;
case AOE_CMD_QUERY_CONFIG_INFO:
break;
}
}
static int
dissect_aoe(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data _U_)
{
proto_item *item;
proto_tree *tree;
guint8 version;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "AoE");
col_clear(pinfo->cinfo, COL_INFO);
item = proto_tree_add_item(parent_tree, proto_aoe, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_aoe);
version=tvb_get_guint8(tvb, 0)>>4;
proto_tree_add_uint(tree, hf_aoe_version, tvb, 0, 1, version);
switch(version){
case 1:
dissect_aoe_v1(tvb, pinfo, tree);
break;
}
return tvb_captured_length(tvb);
}
static void
ata_init(void)
{
ata_cmd_unmatched=g_hash_table_new(ata_cmd_hash_unmatched, ata_cmd_equal_unmatched);
ata_cmd_matched=g_hash_table_new(ata_cmd_hash_matched, ata_cmd_equal_matched);
}
static void
ata_cleanup(void)
{
g_hash_table_destroy(ata_cmd_unmatched);
g_hash_table_destroy(ata_cmd_matched);
}
void
proto_register_aoe(void)
{
static hf_register_info hf[] = {
{ &hf_aoe_cmd,
{ "Command", "aoe.cmd", FT_UINT8, BASE_DEC, VALS(cmd_vals), 0x0,
"AOE Command", HFILL}},
{ &hf_aoe_version,
{ "Version", "aoe.version", FT_UINT8, BASE_DEC, NULL, 0x0,
"Version of the AOE protocol", HFILL}},
{ &hf_aoe_error,
{ "Error", "aoe.error", FT_UINT8, BASE_DEC, VALS(error_vals), 0x0,
"Error code", HFILL}},
{ &hf_aoe_err_feature,
{ "Err/Feature", "aoe.err_feature", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_aoe_sector_count,
{ "Sector Count", "aoe.sector_count", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_aoe_flags_response,
{ "Response flag", "aoe.response", FT_BOOLEAN, 8, TFS(&tfs_response_request), AOE_FLAGS_RESPONSE, "Whether this is a response PDU or not", HFILL}},
{ &hf_aoe_flags_error,
{ "Error flag", "aoe.flags_error", FT_BOOLEAN, 8, TFS(&tfs_error), AOE_FLAGS_ERROR, "Whether this is an error PDU or not", HFILL}},
{ &hf_aoe_major,
{ "Major", "aoe.major", FT_UINT16, BASE_HEX, NULL, 0x0,
"Major address", HFILL}},
{ &hf_aoe_minor,
{ "Minor", "aoe.minor", FT_UINT8, BASE_HEX, NULL, 0x0,
"Minor address", HFILL}},
{ &hf_aoe_acmd,
{ "ATA Cmd", "aoe.ata.cmd", FT_UINT8, BASE_HEX, VALS(ata_cmd_vals), 0x0,
"ATA command opcode", HFILL}},
{ &hf_aoe_astatus,
{ "ATA Status", "aoe.ata.status", FT_UINT8, BASE_HEX, NULL, 0x0,
"ATA status bits", HFILL}},
{ &hf_aoe_tag,
{ "Tag", "aoe.tag", FT_UINT32, BASE_HEX, NULL, 0x0,
"Command Tag", HFILL}},
{ &hf_aoe_aflags_e,
{ "E", "aoe.aflags.e", FT_BOOLEAN, 8, TFS(&tfs_aflags_e), AOE_AFLAGS_E, "Whether this is a normal or LBA48 command", HFILL}},
{ &hf_aoe_aflags_d,
{ "D", "aoe.aflags.d", FT_BOOLEAN, 8, TFS(&tfs_aflags_d), AOE_AFLAGS_D, NULL, HFILL}},
{ &hf_aoe_aflags_a,
{ "A", "aoe.aflags.a", FT_BOOLEAN, 8, TFS(&tfs_aflags_a), AOE_AFLAGS_A, "Whether this is an asynchronous write or not", HFILL}},
{ &hf_aoe_aflags_w,
{ "W", "aoe.aflags.w", FT_BOOLEAN, 8, TFS(&tfs_aflags_w), AOE_AFLAGS_W, "Is this a command writing data to the device or not", HFILL}},
{ &hf_aoe_lba,
{ "Lba", "aoe.lba", FT_UINT64, BASE_HEX, NULL, 0x00, "Lba address", HFILL}},
{ &hf_aoe_response_in,
{ "Response In", "aoe.response_in", FT_FRAMENUM, BASE_NONE, NULL, 0x0, "The response to this packet is in this frame", HFILL }},
{ &hf_aoe_response_to,
{ "Response To", "aoe.response_to", FT_FRAMENUM, BASE_NONE, NULL, 0x0, "This is a response to the ATA command in this frame", HFILL }},
{ &hf_aoe_time,
{ "Time from request", "aoe.time", FT_RELATIVE_TIME, BASE_NONE, NULL, 0, "Time between Request and Reply for ATA calls", HFILL }},
};
static gint *ett[] = {
&ett_aoe,
&ett_aoe_flags,
};
proto_aoe = proto_register_protocol("ATAoverEthernet", "AOE", "aoe");
proto_register_field_array(proto_aoe, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
aoe_handle = register_dissector("aoe", dissect_aoe, proto_aoe);
register_init_routine(ata_init);
register_cleanup_routine(ata_cleanup);
}
void
proto_reg_handoff_aoe(void)
{
dissector_add_uint("ethertype", ETHERTYPE_AOE, aoe_handle);
}
