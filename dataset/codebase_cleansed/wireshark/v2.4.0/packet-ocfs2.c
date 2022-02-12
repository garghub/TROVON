static int dlm_cookie_handler(proto_tree *tree, tvbuff_t *tvb, guint offset, int hf_cookie)
{
proto_item *item;
guint64 cookie;
guint64 seq;
guint8 node_idx;
item = proto_tree_add_item(tree, hf_cookie, tvb, offset, 8, ENC_BIG_ENDIAN);
cookie = tvb_get_ntoh64(tvb, offset);
cookie >>= 56;
node_idx = (guint8)((cookie >> 56) & G_GINT64_CONSTANT(0xff));
seq = cookie & G_GINT64_CONSTANT(0x00ffffffffffffff);
proto_item_append_text(item, " (%u:%" G_GINT64_MODIFIER "u)", node_idx, seq);
return offset + 8;
}
static int dlm_lkm_flags_handler(proto_tree *tree, tvbuff_t *tvb, guint offset,
guint32 *dlm_lock_flags_ptr)
{
static const int *flags[] = {
&hf_dlm_lock_flag_unused1,
&hf_dlm_lock_flag_orphan,
&hf_dlm_lock_flag_parentable,
&hf_dlm_lock_flag_block,
&hf_dlm_lock_flag_local,
&hf_dlm_lock_flag_valblk,
&hf_dlm_lock_flag_noqueue,
&hf_dlm_lock_flag_convert,
&hf_dlm_lock_flag_nodlckwt,
&hf_dlm_lock_flag_unlock,
&hf_dlm_lock_flag_cancel,
&hf_dlm_lock_flag_deqall,
&hf_dlm_lock_flag_invvalblk,
&hf_dlm_lock_flag_syncsts,
&hf_dlm_lock_flag_timeout,
&hf_dlm_lock_flag_sngldlck,
&hf_dlm_lock_flag_findlocal,
&hf_dlm_lock_flag_proc_owned,
&hf_dlm_lock_flag_xid,
&hf_dlm_lock_flag_xid_conflict,
&hf_dlm_lock_flag_force,
&hf_dlm_lock_flag_revvalblk,
&hf_dlm_lock_flag_unused2,
&hf_dlm_lock_flag_migration,
&hf_dlm_lock_flag_put_lvb,
&hf_dlm_lock_flag_get_lvb,
&hf_dlm_lock_flag_recovery,
NULL
};
if(dlm_lock_flags_ptr != NULL){
*dlm_lock_flags_ptr = tvb_get_ntohl(tvb, offset);
}
proto_tree_add_bitmask_with_flags(tree, tvb, offset, hf_dlm_lock_flags,
ett_dtm_lock_flags, flags, ENC_BIG_ENDIAN, BMT_NO_INT | BMT_NO_FALSE | BMT_NO_TFS);
return offset + 4;
}
static int dlm_name_handler(proto_tree *tree, tvbuff_t *tvb, guint offset, int namelen)
{
guint8 lock_type;
guint64 blkno;
proto_item *ti;
ti = proto_tree_add_item(tree, hf_dlm_name, tvb, offset, namelen, ENC_ASCII|ENC_NA);
lock_type = tvb_get_guint8(tvb, offset);
if (lock_type == 'N') {
blkno = tvb_get_ntoh64(tvb, offset + OCFS2_DENTRY_LOCK_INO_START);
proto_item_append_text(ti, "%08x", (unsigned int)blkno);
}
return offset + namelen;
}
static void dissect_dlm_migrate_lockres(proto_tree *tree, tvbuff_t *tvb, int offset)
{
unsigned int i;
guint32 num_locks;
static const int * mres_flags[] = {
&hf_dlm_mres_flag_recovery,
&hf_dlm_mres_flag_migration,
&hf_dlm_mres_flag_all_done,
NULL
};
proto_tree_add_item(tree, hf_dlm_master, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_dlm_namelen, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item_ret_uint(tree, hf_dlm_mres_num_locks, tvb, offset, 1, ENC_BIG_ENDIAN, &num_locks);
offset += 1;
if (num_locks == 0)
return;
proto_tree_add_bitmask_with_flags(tree, tvb, offset, hf_dlm_mres_flags,
ett_mres_flags, mres_flags, ENC_BIG_ENDIAN, BMT_NO_INT | BMT_NO_FALSE | BMT_NO_TFS);
offset += 1;
proto_tree_add_item(tree, hf_dlm_mres_total_locks, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dlm_cookie_handler(tree, tvb, offset, hf_dlm_mres_mig_cookie);
proto_tree_add_item(tree, hf_dlm_name, tvb, offset, 32, ENC_ASCII|ENC_NA);
offset += 32;
proto_tree_add_item(tree, hf_dlm_lvb1, tvb, offset, 24, ENC_NA);
offset += 24;
proto_tree_add_item(tree, hf_dlm_lvb2, tvb, offset, 24, ENC_NA);
offset += 24;
proto_tree_add_item(tree, hf_dlm_lvb3, tvb, offset, 16, ENC_NA);
offset += 16;
for (i = 0; i < num_locks; i++) {
proto_tree *subtree;
subtree = proto_tree_add_subtree_format(tree, tvb, offset, 16,
ett_migrate_lockres_locks, NULL, "Locks%d: ", i + 1);
offset = dlm_cookie_handler(subtree, tvb, offset, hf_dlm_mres_mig_cookie);
proto_tree_add_item(subtree, hf_dlm_pad8, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(subtree, hf_dlm_mres_list, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(subtree, hf_dlm_mres_ml_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(subtree, hf_dlm_mres_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(subtree, hf_dlm_mres_convert_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(subtree, hf_dlm_mres_highest_blocked, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(subtree, hf_dlm_mres_node, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
}
static void
dlm_fmt_revision( gchar *result, guint32 revision )
{
g_snprintf( result, ITEM_LABEL_LENGTH, "%d.%02d", (guint8)(( revision & 0xFF00 ) >> 8), (guint8)(revision & 0xFF) );
}
static void dissect_dlm_query_join_request(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint8 cc, *node_bits_array;
guint8 *node_map;
gint len;
unsigned int i, j;
gboolean oldver = FALSE;
node_bits_array = (guint8 *)wmem_alloc0(wmem_packet_scope(), (DLM_QUERY_JOIN_REQUEST_LEN_NODEMAP*8)+1);
len = tvb_reported_length_remaining(tvb, offset);
if (len == DLM_QUERY_JOIN_REQUEST_OLD_LEN)
oldver = TRUE;
proto_tree_add_item(tree, hf_dlm_node_idx, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_dlm_pad16, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dlm_domain_name_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (!oldver)
{
proto_tree_add_item(tree, hf_dlm_proto_ver, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dlm_fs_proto_ver, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
proto_tree_add_item(tree, hf_dlm_domain_name, tvb, offset, 64, ENC_ASCII|ENC_NA);
offset += 64;
node_map = (guint8 *)tvb_memdup(wmem_packet_scope(), tvb, offset, DLM_QUERY_JOIN_REQUEST_LEN_NODEMAP);
for (i = 0; i < DLM_QUERY_JOIN_REQUEST_LEN_NODEMAP; i++) {
cc = node_map[i];
for (j = 0; j < 8; j++)
node_bits_array[i * 8 + j] =
(((cc >> j) & 1) ? '1' : '0');
}
node_bits_array[(DLM_QUERY_JOIN_REQUEST_LEN_NODEMAP*8)] = 0;
proto_tree_add_bytes_format_value(tree, hf_dlm_node_map, tvb, offset, DLM_QUERY_JOIN_REQUEST_LEN_NODEMAP, NULL, "%s", node_bits_array);
}
static void dissect_dlm_query_region(proto_tree *tree, tvbuff_t *tvb,
guint offset)
{
guint32 i, num_regions;
guchar *region;
proto_tree_add_item(tree, hf_dlm_qr_node, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item_ret_uint(tree, hf_dlm_qr_numregions, tvb, offset, 1, ENC_BIG_ENDIAN, &num_regions);
offset += 1;
proto_tree_add_item(tree, hf_dlm_qr_namelen, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_dlm_pad8, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_dlm_qr_domain, tvb, offset, 64, ENC_ASCII|ENC_NA);
offset += 64;
for (i = 0; i < num_regions; i++, offset += O2HB_MAX_REGION_NAME_LEN) {
region = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, O2HB_MAX_REGION_NAME_LEN, ENC_ASCII);
proto_tree_add_string_format(tree, hf_dlm_qr_region, tvb, offset, 1,
region, "Region%d: %s", i + 1, region);
}
}
static void dissect_dlm_query_nodeinfo(proto_tree *tree, tvbuff_t *tvb, guint offset)
{
guint32 i, num_nodes;
proto_tree_add_item(tree, hf_dlm_qn_nodenum, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item_ret_uint(tree, hf_dlm_qn_numnodes, tvb, offset, 1, ENC_BIG_ENDIAN, &num_nodes);
offset += 1;
proto_tree_add_item(tree, hf_dlm_qn_namelen, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_dlm_qn_domain, tvb, offset, 64, ENC_ASCII|ENC_NA);
offset += 64;
for (i = 0; i < num_nodes; i++) {
proto_tree *subtree;
subtree = proto_tree_add_subtree_format(tree, tvb, offset, 8,
ett_query_nodeinfo, NULL, "Node%d: ", i+1);
proto_tree_add_item(subtree, hf_dlm_qn_node, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(subtree, hf_dlm_pad8, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(subtree, hf_dlm_qn_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(subtree, hf_dlm_qn_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
}
static int dissect_master_msg(proto_tree *tree, tvbuff_t *tvb, int offset, int hf_flag)
{
guint32 namelen;
proto_tree_add_item(tree, hf_dlm_node_idx, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item_ret_uint(tree, hf_dlm_namelen, tvb, offset, 1, ENC_BIG_ENDIAN, &namelen);
offset += 1;
proto_tree_add_item(tree, hf_dlm_pad16, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (hf_flag == -1)
proto_tree_add_item(tree, hf_dlm_flags, tvb, offset, 4, ENC_BIG_ENDIAN);
else
proto_tree_add_item(tree, hf_flag, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return dlm_name_handler(tree, tvb, offset, namelen);
}
static int dissect_create_lock_msg(proto_tree *tree, tvbuff_t *tvb, int offset,
guint32 *dlm_lock_flags_ptr)
{
guint32 namelen;
offset = dlm_cookie_handler(tree, tvb, offset, hf_dlm_cookie);
offset = dlm_lkm_flags_handler(tree, tvb, offset, dlm_lock_flags_ptr);
proto_tree_add_item(tree, hf_dlm_pad8, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_dlm_node_idx, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_dlm_requested_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item_ret_uint(tree, hf_dlm_namelen, tvb, offset, 1, ENC_BIG_ENDIAN, &namelen);
offset += 1;
dlm_name_handler(tree, tvb, offset, namelen);
return offset + O2NM_MAX_NAME_LEN;
}
static int dissect_convert_lock_msg(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint32 dlm_lock_flags;
offset = dissect_create_lock_msg(tree, tvb, offset, &dlm_lock_flags);
if(dlm_lock_flags & DLM_LOCK_FLAGS_PUT_LVB){
proto_tree_add_item(tree, hf_dlm_lvb1, tvb, offset, 24, ENC_NA);
offset += 24;
proto_tree_add_item(tree, hf_dlm_lvb2, tvb, offset, 24, ENC_NA);
offset += 24;
proto_tree_add_item(tree, hf_dlm_lvb3, tvb, offset, 16, ENC_NA);
offset += 16;
}
return offset;
}
static int dissect_unlock_msg(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint32 namelen;
guint32 dlm_lock_flags;
offset = dlm_cookie_handler(tree, tvb, offset, hf_dlm_cookie);
offset = dlm_lkm_flags_handler(tree, tvb, offset, &dlm_lock_flags);
proto_tree_add_item(tree, hf_dlm_pad16, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dlm_node_idx, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item_ret_uint(tree, hf_dlm_namelen, tvb, offset, 1, ENC_BIG_ENDIAN, &namelen);
offset += 1;
dlm_name_handler(tree, tvb, offset, namelen);
offset += O2NM_MAX_NAME_LEN;
if(dlm_lock_flags & DLM_LOCK_FLAGS_PUT_LVB){
proto_tree_add_item(tree, hf_dlm_lvb1, tvb, offset, 24, ENC_NA);
offset += 24;
proto_tree_add_item(tree, hf_dlm_lvb2, tvb, offset, 24, ENC_NA);
offset += 24;
proto_tree_add_item(tree, hf_dlm_lvb3, tvb, offset, 16, ENC_NA);
offset += 16;
}
return offset;
}
static int dissect_proxy_ast_msg(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint32 namelen;
guint32 dlm_lock_flags;
offset = dlm_cookie_handler(tree, tvb, offset, hf_dlm_cookie);
offset = dlm_lkm_flags_handler(tree, tvb, offset, &dlm_lock_flags);
proto_tree_add_item(tree, hf_dlm_node_idx, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_dlm_ast_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_dlm_blocked_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item_ret_uint(tree, hf_dlm_namelen, tvb, offset, 1, ENC_BIG_ENDIAN, &namelen);
offset += 1;
dlm_name_handler(tree, tvb, offset, namelen);
offset += O2NM_MAX_NAME_LEN;
if(dlm_lock_flags & DLM_LOCK_FLAGS_GET_LVB){
proto_tree_add_item(tree, hf_dlm_lvb1, tvb, offset, 24, ENC_NA);
offset += 24;
proto_tree_add_item(tree, hf_dlm_lvb2, tvb, offset, 24, ENC_NA);
offset += 24;
proto_tree_add_item(tree, hf_dlm_lvb3, tvb, offset, 16, ENC_NA);
offset += 16;
}
return offset;
}
static int dissect_deref_lockres_msg(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint32 namelen;
proto_tree_add_item(tree, hf_dlm_pad32, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_dlm_pad16, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dlm_node_idx, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item_ret_uint(tree, hf_dlm_namelen, tvb, offset, 1, ENC_BIG_ENDIAN, &namelen);
offset += 1;
return dlm_name_handler(tree, tvb, offset, namelen);
}
static int dissect_migrate_request_msg(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint32 namelen;
proto_tree_add_item(tree, hf_dlm_master, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_dlm_new_master, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item_ret_uint(tree, hf_dlm_namelen, tvb, offset, 1, ENC_BIG_ENDIAN, &namelen);
offset += 1;
proto_tree_add_item(tree, hf_dlm_pad8, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_dlm_pad32, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return dlm_name_handler(tree, tvb, offset, namelen);
}
static int dissect_dlm_joined_msg(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_dlm_node_idx, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_dlm_pad16, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dlm_domain_name_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_dlm_domain_name, tvb, offset, 64, ENC_ASCII|ENC_NA);
offset += 64;
return offset;
}
static int dissect_master_requery_msg(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint32 namelen;
proto_tree_add_item(tree, hf_dlm_pad16, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dlm_node_idx, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item_ret_uint(tree, hf_dlm_namelen, tvb, offset, 1, ENC_BIG_ENDIAN, &namelen);
offset += 1;
proto_tree_add_item(tree, hf_dlm_pad32, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return dlm_name_handler(tree, tvb, offset, namelen);
}
static int dissect_lock_request_msg(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_dlm_node_idx, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_dlm_dead_node, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_dlm_pad16, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dlm_pad32, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int dissect_reco_data_done_msg(proto_tree *tree, tvbuff_t *tvb, int offset)
{
offset = dissect_lock_request_msg(tree, tvb, offset);
proto_tree_add_item(tree, hf_dlm_reco_lvb, tvb, offset, 64, ENC_NA);
offset += 64;
return offset;
}
static int dissect_finalize_reco_msg(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_dlm_node_idx, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_dlm_dead_node, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_dlm_fr_flags, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_dlm_pad8, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_dlm_pad32, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int dissect_ocfs2_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *subtree;
proto_item *ti;
guint32 len, msg_type;
guint32 magic;
tvbuff_t *next_tvb;
int offset = 0;
magic = tvb_get_ntohs(tvb, offset);
if (try_val_to_str(magic, o2net_magic) == NULL)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "OCFS2");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_ocfs2, tvb, offset, -1, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_ocfs2);
proto_tree_add_item(subtree, hf_msg_magic, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item_ret_uint(subtree, hf_msg_data_len, tvb, 2, 2, ENC_BIG_ENDIAN, &len);
offset += 2;
proto_tree_add_item_ret_uint(subtree, hf_msg_msg_type, tvb, 4, 2, ENC_BIG_ENDIAN, &msg_type);
offset += 2;
switch(magic){
case O2NET_MSG_KEEP_REQ_MAGIC:
col_append_sep_str(pinfo->cinfo, COL_INFO, " | ", "Keepalive Request");
break;
case O2NET_MSG_KEEP_RESP_MAGIC:
col_append_sep_str(pinfo->cinfo, COL_INFO, " | ", "Keepalive Response");
break;
default:
col_append_sep_str(pinfo->cinfo, COL_INFO, " | ",
val_to_str_ext(msg_type, &ext_dlm_magic, "Unknown Type (0x%02x)") );
break;
}
col_set_fence(pinfo->cinfo, COL_INFO);
proto_tree_add_item(subtree, hf_msg_pad, tvb, 4, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(subtree, hf_msg_sys_status, tvb, 8, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, hf_msg_status, tvb, 12, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, hf_msg_key, tvb, 16, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, hf_msg_msg_num, tvb, 20, 4, ENC_BIG_ENDIAN);
offset += 4;
if (magic == O2NET_MSG_MAGIC) {
switch (msg_type) {
case DLM_MASTER_REQUEST_MSG:
dissect_master_msg(subtree, tvb, offset, -1);
break;
case DLM_ASSERT_MASTER_MSG:
dissect_master_msg(subtree, tvb, offset, hf_dlm_am_flags);
break;
case DLM_CREATE_LOCK_MSG:
dissect_create_lock_msg(subtree, tvb, offset, NULL);
break;
case DLM_CONVERT_LOCK_MSG:
dissect_convert_lock_msg(subtree, tvb, offset);
break;
case DLM_PROXY_AST_MSG:
dissect_proxy_ast_msg(subtree, tvb, offset);
break;
case DLM_UNLOCK_LOCK_MSG:
dissect_unlock_msg(subtree, tvb, offset);
break;
case DLM_DEREF_LOCKRES_MSG:
dissect_deref_lockres_msg(subtree, tvb, offset);
break;
case DLM_MIGRATE_REQUEST_MSG:
dissect_migrate_request_msg(subtree, tvb, offset);
break;
case DLM_MIG_LOCKRES_MSG:
dissect_dlm_migrate_lockres(subtree, tvb, offset);
break;
case DLM_QUERY_JOIN_MSG:
dissect_dlm_query_join_request(subtree, tvb, offset);
break;
case DLM_ASSERT_JOINED_MSG:
case DLM_CANCEL_JOIN_MSG:
dissect_dlm_joined_msg(subtree, tvb, offset);
break;
case DLM_EXIT_DOMAIN_MSG:
proto_tree_add_item(tree, hf_dlm_node_idx, tvb, offset, 1, ENC_NA);
break;
case DLM_MASTER_REQUERY_MSG:
dissect_master_requery_msg(subtree, tvb, offset);
break;
case DLM_LOCK_REQUEST_MSG:
case DLM_BEGIN_RECO_MSG:
dissect_lock_request_msg(subtree, tvb, offset);
break;
case DLM_RECO_DATA_DONE_MSG:
dissect_reco_data_done_msg(subtree, tvb, offset);
break;
case DLM_FINALIZE_RECO_MSG:
dissect_finalize_reco_msg(subtree, tvb, offset);
break;
case DLM_QUERY_REGION_MSG:
dissect_dlm_query_region(subtree, tvb, offset);
break;
case DLM_QUERY_NODEINFO_MSG:
dissect_dlm_query_nodeinfo(subtree, tvb, offset);
break;
default:
proto_tree_add_item(tree, hf_dlm_payload, tvb, offset, len, ENC_NA);
break;
}
} else {
next_tvb = tvb_new_subset_length(tvb, offset, len);
call_data_dissector(next_tvb, pinfo, tree);
}
return tvb_reported_length(tvb);
}
static guint
get_ocfs2_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
guint16 plen;
plen = tvb_get_ntohs(tvb, offset + 2);
return plen + 24;
}
static int dissect_ocfs2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint32 magic;
int offset = 0;
if (!tvb_bytes_exist(tvb, offset, 2))
return 0;
magic = tvb_get_ntohs(tvb, offset);
if (try_val_to_str(magic, o2net_magic) == NULL)
return 0;
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, 4, get_ocfs2_pdu_len, dissect_ocfs2_pdu, data);
return tvb_captured_length(tvb);
}
void proto_register_ocfs2(void)
{
static hf_register_info hf[] = {
{ &hf_msg_magic,
{ "Magic", "ocfs2.msg.magic", FT_UINT16, BASE_HEX,
VALS(o2net_magic), 0x0,
"Magic number identifier of O2NET-over-TCPmessage",
HFILL
}
},
{ &hf_msg_data_len,
{ "Len", "ocfs2.msg.data_len", FT_UINT16, BASE_DEC,
NULL, 0x0, "Data length", HFILL
}
},
{ &hf_msg_msg_type,
{ "Type", "ocfs2.msg.msg_type", FT_UINT16, BASE_DEC|BASE_EXT_STRING,
&ext_dlm_magic, 0x0, "Message type", HFILL
}
},
{ &hf_msg_pad,
{ "Pad", "ocfs2.msg.pad", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_msg_sys_status,
{ "Sys Status", "ocfs2.msg.sys_status", FT_UINT32,
BASE_DEC, NULL, 0x0,
"System level status return code", HFILL
}
},
{ &hf_msg_status,
{ "Status", "ocfs2.msg.status", FT_UINT32, BASE_DEC,
NULL, 0x0, "Return code", HFILL
}
},
{ &hf_msg_key,
{ "Key", "ocfs2.msg.key", FT_UINT32, BASE_HEX, NULL,
0x0, NULL, HFILL
}
},
{ &hf_msg_msg_num,
{ "Num", "ocfs2.msg.msg_num", FT_UINT32, BASE_DEC, NULL,
0x0, "Message identification number", HFILL
}
},
{ &hf_dlm_node_idx,
{ "Node", "ocfs2.dlm.node_idx", FT_UINT8, BASE_DEC,
NULL, 0x0, "Node index", HFILL
}
},
{ &hf_dlm_lock_flags,
{ "Flags", "ocfs2.dlm.lock.flags", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_dlm_lock_flag_unused1,
{ "unused", "ocfs2.dlm.lock.flags.unused", FT_UINT32, BASE_HEX,
NULL, 0x0000000F, NULL, HFILL
}
},
{ &hf_dlm_lock_flag_orphan,
{ "orphan", "ocfs2.dlm.lock.flags.orphan", FT_BOOLEAN, 32,
NULL, 0x00000010, NULL, HFILL
}
},
{ &hf_dlm_lock_flag_parentable,
{ "parentable", "ocfs2.dlm.lock.flags.parentable", FT_BOOLEAN, 32,
NULL, 0x00000020, NULL, HFILL
}
},
{ &hf_dlm_lock_flag_block,
{ "block", "ocfs2.dlm.lock.flags.block", FT_BOOLEAN, 32,
NULL, 0x00000040, NULL, HFILL
}
},
{ &hf_dlm_lock_flag_local,
{ "local", "ocfs2.dlm.lock.flags.local", FT_BOOLEAN, 32,
NULL, 0x00000080, NULL, HFILL
}
},
{ &hf_dlm_lock_flag_valblk,
{ "valblk", "ocfs2.dlm.lock.flags.valblk", FT_BOOLEAN, 32,
NULL, 0x00000100, NULL, HFILL
}
},
{ &hf_dlm_lock_flag_noqueue,
{ "noqueue", "ocfs2.dlm.lock.flags.noqueue", FT_BOOLEAN, 32,
NULL, 0x00000200, NULL, HFILL
}
},
{ &hf_dlm_lock_flag_convert,
{ "convert", "ocfs2.dlm.lock.flags.convert", FT_BOOLEAN, 32,
NULL, 0x00000400, NULL, HFILL
}
},
{ &hf_dlm_lock_flag_nodlckwt,
{ "nodlckwt", "ocfs2.dlm.lock.flags.nodlckwt", FT_BOOLEAN, 32,
NULL, 0x00000800, NULL, HFILL
}
},
{ &hf_dlm_lock_flag_unlock,
{ "unlock", "ocfs2.dlm.lock.flags.unlock", FT_BOOLEAN, 32,
NULL, 0x00001000, NULL, HFILL
}
},
{ &hf_dlm_lock_flag_cancel,
{ "cancel", "ocfs2.dlm.lock.flags.cancel", FT_BOOLEAN, 32,
NULL, 0x00002000, NULL, HFILL
}
},
{ &hf_dlm_lock_flag_deqall,
{ "deqall", "ocfs2.dlm.lock.flags.deqall", FT_BOOLEAN, 32,
NULL, 0x00004000, NULL, HFILL
}
},
{ &hf_dlm_lock_flag_invvalblk,
{ "invvalblk", "ocfs2.dlm.lock.flags.invvalblk", FT_BOOLEAN, 32,
NULL, 0x00008000, NULL, HFILL
}
},
{ &hf_dlm_lock_flag_syncsts,
{ "syncsts", "ocfs2.dlm.lock.flags.syncsts", FT_BOOLEAN, 32,
NULL, 0x00010000, NULL, HFILL
}
},
{ &hf_dlm_lock_flag_timeout,
{ "timeout", "ocfs2.dlm.lock.flags.timeout", FT_BOOLEAN, 32,
NULL, 0x00020000, NULL, HFILL
}
},
{ &hf_dlm_lock_flag_sngldlck,
{ "sngldlck", "ocfs2.dlm.lock.flags.sngldlck", FT_BOOLEAN, 32,
NULL, 0x00040000, NULL, HFILL
}
},
{ &hf_dlm_lock_flag_findlocal,
{ "findlocal", "ocfs2.dlm.lock.flags.findlocal", FT_BOOLEAN, 32,
NULL, 0x00080000, NULL, HFILL
}
},
{ &hf_dlm_lock_flag_proc_owned,
{ "proc_owned", "ocfs2.dlm.lock.flags.proc_owned", FT_BOOLEAN, 32,
NULL, 0x00100000, NULL, HFILL
}
},
{ &hf_dlm_lock_flag_xid,
{ "xid", "ocfs2.dlm.lock.flags.xid", FT_BOOLEAN, 32,
NULL, 0x00200000, NULL, HFILL
}
},
{ &hf_dlm_lock_flag_xid_conflict,
{ "xid_conflict", "ocfs2.dlm.lock.flags.xid_conflict", FT_BOOLEAN, 32,
NULL, 0x00400000, NULL, HFILL
}
},
{ &hf_dlm_lock_flag_force,
{ "force", "ocfs2.dlm.lock.flags.force", FT_BOOLEAN, 32,
NULL, 0x00800000, NULL, HFILL
}
},
{ &hf_dlm_lock_flag_revvalblk,
{ "revvalblk", "ocfs2.dlm.lock.flags.revvalblk", FT_BOOLEAN, 32,
NULL, 0x01000000, NULL, HFILL
}
},
{ &hf_dlm_lock_flag_unused2,
{ "unused", "ocfs2.dlm.lock.flags.unused", FT_UINT32, BASE_HEX,
NULL, 0x0E000000, NULL, HFILL
}
},
{ &hf_dlm_lock_flag_migration,
{ "migration", "ocfs2.dlm.lock.flags.migration", FT_BOOLEAN, 32,
NULL, 0x10000000, NULL, HFILL
}
},
{ &hf_dlm_lock_flag_put_lvb,
{ "put_lvb", "ocfs2.dlm.lock.flags.put_lvb", FT_BOOLEAN, 32,
NULL, 0x20000000, NULL, HFILL
}
},
{ &hf_dlm_lock_flag_get_lvb,
{ "get_lvb", "ocfs2.dlm.lock.flags.get_lvb", FT_BOOLEAN, 32,
NULL, 0x40000000, NULL, HFILL
}
},
{ &hf_dlm_lock_flag_recovery,
{ "recovery", "ocfs2.dlm.lock.flags.recovery", FT_BOOLEAN, 32,
NULL, 0x80000000, NULL, HFILL
}
},
{ &hf_dlm_am_flags,
{ "Flags", "ocfs2.dlm.am_flags", FT_UINT32, BASE_HEX,
VALS(dlm_assert_master_flags), 0x0,
"Assert Master Flags", HFILL
}
},
{ &hf_dlm_fr_flags,
{ "Flags", "ocfs2.dlm.fr_flags", FT_UINT32, BASE_HEX,
VALS(dlm_finalize_reco_flags), 0x0,
"Finalize Recovery Flags", HFILL
}
},
{ &hf_dlm_namelen,
{ "Namelen", "ocfs2.dlm.namelen", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_dlm_name,
{ "Name", "ocfs2.dlm.name", FT_STRING, BASE_NONE, NULL,
0x0, NULL, HFILL
}
},
{ &hf_dlm_cookie,
{ "Cookie", "ocfs2.dlm.cookie", FT_UINT64, BASE_HEX,
NULL, 0x0,
"Unique ID for a single lock on a resource", HFILL
}
},
{ &hf_dlm_requested_type,
{ "Requested", "ocfs2.dlm.requested_type", FT_UINT8,
BASE_DEC, VALS(dlm_lock_modes), 0x0,
"Requested lock level", HFILL
}
},
{ &hf_dlm_blocked_type,
{ "Blocked", "ocfs2.dlm.blocked_type", FT_UINT8,
BASE_DEC, VALS(dlm_lock_modes), 0x0,
"Blocked lock type", HFILL
}
},
{ &hf_dlm_ast_type,
{ "AST Type", "ocfs2.dlm.ast_type", FT_UINT8, BASE_DEC,
VALS(dlm_proxy_ast_types), 0x0, NULL, HFILL
}
},
{ &hf_dlm_dead_node,
{ "Dead Node", "ocfs2.dlm.dead_node", FT_UINT8,
BASE_DEC, NULL, 0x0, "Dead node index", HFILL
}
},
{ &hf_dlm_lvb1,
{ "LVB1", "ocfs2.dlm.lvb", FT_BYTES, BASE_NONE, NULL,
0x0, "Lock value block", HFILL
}
},
{ &hf_dlm_lvb2,
{ "LVB2", "ocfs2.dlm.lvb", FT_BYTES, BASE_NONE, NULL,
0x0, "Lock value block", HFILL
}
},
{ &hf_dlm_lvb3,
{ "LVB3", "ocfs2.dlm.lvb", FT_BYTES, BASE_NONE, NULL,
0x0, "Lock value block", HFILL
}
},
{ &hf_dlm_domain_name_len,
{ "Domain Namelen", "ocfs2.dlm.domain_namelen",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL,
HFILL
}
},
{ &hf_dlm_proto_ver,
{ "DLM Protocol", "ocfs2.dlm.proto_ver",
FT_UINT16, BASE_CUSTOM, CF_FUNC(dlm_fmt_revision), 0x0, NULL,
HFILL
}
},
{ &hf_dlm_fs_proto_ver,
{ "FS Protocol", "ocfs2.dlm.fs_proto_ver",
FT_UINT16, BASE_CUSTOM, CF_FUNC(dlm_fmt_revision), 0x0, NULL,
HFILL
}
},
{ &hf_dlm_node_map,
{ "Node Map", "ocfs2.dlm.node_map", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{ &hf_dlm_domain_name,
{ "Domain Name", "ocfs2.dlm.domain_name", FT_STRING,
BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{ &hf_dlm_master,
{ "Master", "ocfs2.dlm.master", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_dlm_new_master,
{ "New Master", "ocfs2.dlm.new_master", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{ &hf_dlm_mres_num_locks,
{ "Num Locks", "ocfs2.dlm.num_locks", FT_UINT8,
BASE_DEC, NULL, 0x0, "Migres Num Locks", HFILL
}
},
{ &hf_dlm_mres_flags,
{ "Flags", "ocfs2.dlm.mres_flags", FT_UINT8, BASE_HEX,
NULL, 0x01, "Migres Flags", HFILL
}
},
{ &hf_dlm_mres_flag_recovery,
{ "recovery", "ocfs2.dlm.mres_flags.recovery", FT_BOOLEAN, 8,
NULL, 0x02, NULL, HFILL
}
},
{ &hf_dlm_mres_flag_migration,
{ "migration", "ocfs2.dlm.mres_flags.migration", FT_BOOLEAN, 8,
NULL, 0x04, NULL, HFILL
}
},
{ &hf_dlm_mres_flag_all_done,
{ "all_done", "ocfs2.dlm.mres_flags.all_done", FT_BOOLEAN, 8,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_dlm_mres_total_locks,
{ "Total Locks", "ocfs2.dlm.total_locks", FT_UINT32,
BASE_DEC, NULL, 0x0, "Migres Total Locks", HFILL
}
},
{ &hf_dlm_mres_mig_cookie,
{ "Cookie", "ocfs2.dlm.migratable_lock.mig_cookie",
FT_UINT64, BASE_DEC, NULL, 0x0, "Migres Cookie", HFILL
}
},
{ &hf_dlm_mres_list,
{ "List", "ocfs2.dlm.migratable_lock.list", FT_UINT8,
BASE_DEC, VALS(dlm_lockres_list), 0x0, NULL, HFILL
}
},
{ &hf_dlm_mres_ml_flags,
{ "List", "ocfs2.dlm.migratable_lock.flags", FT_UINT8,
BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{ &hf_dlm_mres_type,
{ "Type", "ocfs2.dlm.migratable_lock.type", FT_UINT8,
BASE_DEC, VALS(dlm_lock_modes), 0x0, NULL, HFILL
}
},
{ &hf_dlm_mres_convert_type,
{ "Convert type", "ocfs2.dlm.migratable_lock.convert_type", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{ &hf_dlm_mres_highest_blocked,
{ "Highest blocked", "ocfs2.dlm.migratable_lock.highest_blocked", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{ &hf_dlm_mres_node,
{ "Node", "ocfs2.dlm.migratable_lock.node", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{ &hf_dlm_qr_node,
{ "Node", "ocfs2.dlm.query_region.qr_node", FT_UINT8,
BASE_DEC, NULL, 0x0, "Query Region Node", HFILL
}
},
{ &hf_dlm_qr_numregions,
{ "Num Regions", "ocfs2.dlm.query_region.qr_numregions",
FT_UINT8, BASE_DEC, NULL, 0x0,
"The number of regions to compare with", HFILL
}
},
{ &hf_dlm_qr_namelen,
{ "Domain Namelen", "ocfs2.dlm.query_region.qr_namelen",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{ &hf_dlm_qr_domain,
{ "Domain Name", "ocfs2.dlm.query_region.qr_domain",
FT_STRING, BASE_NONE, NULL, 0x0, NULL,
HFILL
}
},
{ &hf_dlm_qr_region,
{ "Region", "ocfs2.dlm.query_region.region",
FT_STRING, BASE_NONE, NULL, 0x0, NULL,
HFILL
}
},
{ &hf_dlm_qn_nodenum,
{ "Node", "ocfs2.dlm_query_nodeinfo.qn_nodenum",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{ &hf_dlm_qn_numnodes,
{ "Num Nodes", "ocfs2.dlm_query_nodeinfo.qn_numnodes",
FT_UINT8, BASE_DEC, NULL, 0x0,
"The number of nodes to query", HFILL
}
},
{ &hf_dlm_qn_namelen,
{ "Domain Namelen",
"ocfs2.dlm_query_nodeinfo.qn_namelen", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{ &hf_dlm_qn_domain,
{ "Domain Name", "ocfs2.dlm_query_nodeinfo.qn_domain",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL,
HFILL
}
},
{ &hf_dlm_qn_node,
{ "Node", "ocfs2.dlm_query_nodeinfo.node",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL,
HFILL
}
},
{ &hf_dlm_qn_port,
{ "Port", "ocfs2.dlm_query_nodeinfo.port",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL,
HFILL
}
},
{ &hf_dlm_qn_ip,
{ "IP Address", "ocfs2.dlm_query_nodeinfo.ip",
FT_IPv4, BASE_NONE, NULL, 0x0, NULL,
HFILL
}
},
{ &hf_dlm_reco_lvb,
{ "Recovery LVB", "ocfs2.reco_lvb",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL,
HFILL
}
},
{ &hf_dlm_pad8,
{ "Pad", "ocfs2.dlm.pad",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL,
HFILL
}
},
{ &hf_dlm_pad16,
{ "Pad", "ocfs2.dlm.pad",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL,
HFILL
}
},
{ &hf_dlm_pad32,
{ "Pad", "ocfs2.dlm.pad",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL,
HFILL
}
},
{ &hf_dlm_flags,
{ "Flags", "ocfs2.dlm.flags",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL,
HFILL
}
},
{ &hf_dlm_payload,
{ "Payload", "ocfs2.dlm.payload",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL,
HFILL
}
},
};
static gint *ett[] = {
&ett_ocfs2,
&ett_dtm_lock_flags,
&ett_mres_flags,
&ett_migrate_lockres_locks,
&ett_query_nodeinfo,
};
proto_ocfs2 = proto_register_protocol("OCFS2 Networking", "OCFS2", "ocfs2");
proto_register_field_array(proto_ocfs2, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_ocfs2(void)
{
dissector_handle_t ocfs2_handle;
ocfs2_handle = create_dissector_handle(dissect_ocfs2, proto_ocfs2);
dissector_add_for_decode_as_with_preference("tcp.port", ocfs2_handle);
}
