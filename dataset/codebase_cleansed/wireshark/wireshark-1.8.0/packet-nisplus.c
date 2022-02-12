static int
dissect_nisplus_time(tvbuff_t *tvb, int offset, proto_tree *tree, int hfindex)
{
nstime_t ts;
ts.nsecs = 0;
ts.secs = tvb_get_ntohl(tvb, offset);
offset += 4;
proto_tree_add_time(tree, hfindex, tvb, offset, 4, &ts);
return offset;
}
static int
dissect_group(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
offset = dissect_rpc_string(tvb, tree,
hf_nisplus_group_name, offset, NULL);
return offset;
}
static int
dissect_group_obj(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree)
{
proto_item* lock_item = NULL;
proto_tree* lock_tree = NULL;
int old_offset = offset;
lock_item = proto_tree_add_item(tree, hf_nisplus_group,
tvb, offset, -1, ENC_NA);
lock_tree = proto_item_add_subtree(lock_item, ett_nisplus_group);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_nisplus_group_flags, offset);
offset = dissect_rpc_array(tvb, pinfo, lock_tree, offset,
dissect_group, hf_nisplus_grps);
proto_item_set_len(lock_item, offset-old_offset);
return offset;
}
static int
dissect_access_rights(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_item* mask_item = NULL;
proto_tree* mask_tree = NULL;
guint32 mask;
mask_item = proto_tree_add_item(tree, hf_nisplus_access_mask,
tvb, offset, 4, ENC_NA);
mask_tree = proto_item_add_subtree(mask_item, ett_nisplus_access_mask);
mask = tvb_get_ntohl(tvb, offset);
proto_tree_add_boolean(mask_tree, hf_nisplus_mask_world_read, tvb, offset, 4, mask);
proto_tree_add_boolean(mask_tree, hf_nisplus_mask_world_modify, tvb, offset, 4, mask);
proto_tree_add_boolean(mask_tree, hf_nisplus_mask_world_create, tvb, offset, 4, mask);
proto_tree_add_boolean(mask_tree, hf_nisplus_mask_world_destroy, tvb, offset, 4, mask);
proto_tree_add_boolean(mask_tree, hf_nisplus_mask_group_read, tvb, offset, 4, mask);
proto_tree_add_boolean(mask_tree, hf_nisplus_mask_group_modify, tvb, offset, 4, mask);
proto_tree_add_boolean(mask_tree, hf_nisplus_mask_group_create, tvb, offset, 4, mask);
proto_tree_add_boolean(mask_tree, hf_nisplus_mask_group_destroy, tvb, offset, 4, mask);
proto_tree_add_boolean(mask_tree, hf_nisplus_mask_owner_read, tvb, offset, 4, mask);
proto_tree_add_boolean(mask_tree, hf_nisplus_mask_owner_modify, tvb, offset, 4, mask);
proto_tree_add_boolean(mask_tree, hf_nisplus_mask_owner_create, tvb, offset, 4, mask);
proto_tree_add_boolean(mask_tree, hf_nisplus_mask_owner_destroy, tvb, offset, 4, mask);
proto_tree_add_boolean(mask_tree, hf_nisplus_mask_nobody_read, tvb, offset, 4, mask);
proto_tree_add_boolean(mask_tree, hf_nisplus_mask_nobody_modify, tvb, offset, 4, mask);
proto_tree_add_boolean(mask_tree, hf_nisplus_mask_nobody_create, tvb, offset, 4, mask);
proto_tree_add_boolean(mask_tree, hf_nisplus_mask_nobody_destroy, tvb, offset, 4, mask);
offset += 4;
return offset;
}
static int
dissect_table(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item* lock_item = NULL;
proto_tree* lock_tree = NULL;
proto_item* mask_item = NULL;
proto_tree* mask_tree = NULL;
guint32 mask;
int old_offset = offset;
lock_item = proto_tree_add_item(tree, hf_nisplus_table_col,
tvb, offset, -1, ENC_NA);
lock_tree = proto_item_add_subtree(lock_item, ett_nisplus_table_col);
offset = dissect_rpc_string(tvb, lock_tree,
hf_nisplus_table_col_name, offset, NULL);
mask_item = proto_tree_add_item(lock_tree, hf_nisplus_table_col_mask,
tvb, offset, 4,
ENC_NA);
mask_tree = proto_item_add_subtree(mask_item, ett_nisplus_table_col_mask);
mask = tvb_get_ntohl(tvb, offset);
proto_tree_add_boolean(mask_tree, hf_nisplus_table_col_mask_binary,
tvb, offset, 4, mask);
proto_tree_add_boolean(mask_tree, hf_nisplus_table_col_mask_encrypted,
tvb, offset, 4, mask);
proto_tree_add_boolean(mask_tree, hf_nisplus_table_col_mask_xdr,
tvb, offset, 4, mask);
proto_tree_add_boolean(mask_tree, hf_nisplus_table_col_mask_searchable,
tvb, offset, 4, mask);
proto_tree_add_boolean(mask_tree, hf_nisplus_table_col_mask_casesensitive,
tvb, offset, 4, mask);
proto_tree_add_boolean(mask_tree, hf_nisplus_table_col_mask_modified,
tvb, offset, 4, mask);
proto_tree_add_boolean(mask_tree, hf_nisplus_table_col_mask_asn,
tvb, offset, 4, mask);
offset += 4;
offset = dissect_access_rights(tvb, offset, lock_tree);
proto_item_set_len(lock_item, offset-old_offset);
return offset;
}
static int
dissect_table_obj(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree)
{
proto_item* lock_item = NULL;
proto_tree* lock_tree = NULL;
int old_offset = offset;
lock_item = proto_tree_add_item(tree, hf_nisplus_table,
tvb, offset, -1, ENC_NA);
lock_tree = proto_item_add_subtree(lock_item, ett_nisplus_table);
offset = dissect_rpc_string(tvb, lock_tree,
hf_nisplus_table_type, offset, NULL);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_nisplus_table_maxcol, offset);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_nisplus_table_sep, offset);
offset = dissect_rpc_array(tvb, pinfo, lock_tree, offset,
dissect_table, hf_nisplus_table_cols);
offset = dissect_rpc_string(tvb, lock_tree,
hf_nisplus_table_path, offset, NULL);
proto_item_set_len(lock_item, offset-old_offset);
return offset;
}
static int
dissect_entry(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item* lock_item = NULL;
proto_tree* lock_tree = NULL;
proto_item* mask_item = NULL;
proto_tree* mask_tree = NULL;
guint32 mask;
int old_offset = offset;
lock_item = proto_tree_add_item(tree, hf_nisplus_entry_col,
tvb, offset, -1, ENC_NA);
lock_tree = proto_item_add_subtree(lock_item, ett_nisplus_entry_col);
mask_item = proto_tree_add_item(lock_tree, hf_nisplus_entry_mask,
tvb, offset, 4,
ENC_NA);
mask_tree = proto_item_add_subtree(mask_item, ett_nisplus_entry_mask);
mask = tvb_get_ntohl(tvb, offset);
proto_tree_add_boolean(mask_tree, hf_nisplus_entry_mask_binary, tvb, offset, 4, mask);
proto_tree_add_boolean(mask_tree, hf_nisplus_entry_mask_crypt, tvb, offset, 4, mask);
proto_tree_add_boolean(mask_tree, hf_nisplus_entry_mask_xdr, tvb, offset, 4, mask);
proto_tree_add_boolean(mask_tree, hf_nisplus_entry_mask_modified, tvb, offset, 4, mask);
proto_tree_add_boolean(mask_tree, hf_nisplus_entry_mask_asn, tvb, offset, 4, mask);
offset += 4;
offset = dissect_rpc_string(tvb, lock_tree,
hf_nisplus_entry_val, offset, NULL);
proto_item_set_len(lock_item, offset-old_offset);
return offset;
}
static int
dissect_entry_obj(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree)
{
proto_item* lock_item = NULL;
proto_tree* lock_tree = NULL;
int old_offset = offset;
lock_item = proto_tree_add_item(tree, hf_nisplus_entry,
tvb, offset, -1, ENC_NA);
lock_tree = proto_item_add_subtree(lock_item, ett_nisplus_entry);
offset = dissect_rpc_string(tvb, lock_tree,
hf_nisplus_entry_type, offset, NULL);
offset = dissect_rpc_array(tvb, pinfo, lock_tree, offset,
dissect_entry, hf_nisplus_entry_cols);
proto_item_set_len(lock_item, offset-old_offset);
return offset;
}
static int
dissect_attr(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item* lock_item = NULL;
proto_tree* lock_tree = NULL;
int old_offset = offset;
lock_item = proto_tree_add_item(tree, hf_nisplus_attr,
tvb, offset, -1, ENC_NA);
lock_tree = proto_item_add_subtree(lock_item, ett_nisplus_attr);
offset = dissect_rpc_string(tvb, lock_tree,
hf_nisplus_attr_name, offset, NULL);
offset = dissect_rpc_data(tvb, lock_tree,
hf_nisplus_attr_val, offset);
proto_item_set_len(lock_item, offset-old_offset);
return offset;
}
static int
dissect_link_obj(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree)
{
proto_item* lock_item = NULL;
proto_tree* lock_tree = NULL;
int old_offset = offset;
lock_item = proto_tree_add_item(tree, hf_nisplus_link,
tvb, offset, -1, ENC_NA);
lock_tree = proto_item_add_subtree(lock_item, ett_nisplus_link);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_nisplus_object_type, offset);
offset = dissect_rpc_array(tvb, pinfo, lock_tree, offset,
dissect_attr, hf_nisplus_attrs_array);
offset = dissect_rpc_string(tvb, lock_tree,
hf_nisplus_object_name, offset, NULL);
proto_item_set_len(lock_item, offset-old_offset);
return offset;
}
static int
dissect_endpoint(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item* lock_item = NULL;
proto_tree* lock_tree = NULL;
int old_offset = offset;
lock_item = proto_tree_add_item(tree, hf_nisplus_endpoint,
tvb, offset, -1, ENC_NA);
lock_tree = proto_item_add_subtree(lock_item, ett_nisplus_endpoint);
offset = dissect_rpc_string(tvb, lock_tree,
hf_nisplus_endpoint_uaddr, offset, NULL);
offset = dissect_rpc_string(tvb, lock_tree,
hf_nisplus_endpoint_family, offset, NULL);
offset = dissect_rpc_string(tvb, lock_tree,
hf_nisplus_endpoint_proto, offset, NULL);
proto_item_set_len(lock_item, offset-old_offset);
return offset;
}
static int
dissect_directory_server(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree)
{
proto_item* lock_item = NULL;
proto_tree* lock_tree = NULL;
int old_offset = offset;
lock_item = proto_tree_add_item(tree, hf_nisplus_server,
tvb, offset, -1, ENC_NA);
lock_tree = proto_item_add_subtree(lock_item, ett_nisplus_server);
offset = dissect_rpc_string(tvb, lock_tree,
hf_nisplus_server_name, offset, NULL);
offset = dissect_rpc_array(tvb, pinfo, lock_tree, offset,
dissect_endpoint, hf_nisplus_endpoints);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_nisplus_key_type, offset);
offset = dissect_rpc_data(tvb, lock_tree,
hf_nisplus_key_data, offset);
proto_item_set_len(lock_item, offset-old_offset);
return offset;
}
static int
dissect_directory_mask(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item* lock_item = NULL;
proto_tree* lock_tree = NULL;
int old_offset = offset;
lock_item = proto_tree_add_item(tree, hf_nisplus_directory_mask,
tvb, offset, -1, ENC_NA);
lock_tree = proto_item_add_subtree(lock_item, ett_nisplus_directory_mask);
offset = dissect_access_rights(tvb, offset, lock_tree);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_nisplus_object_type, offset);
proto_item_set_len(lock_item, offset-old_offset);
return offset;
}
static int
dissect_directory_obj(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree)
{
proto_item* lock_item = NULL;
proto_tree* lock_tree = NULL;
int old_offset = offset;
lock_item = proto_tree_add_item(tree, hf_nisplus_directory,
tvb, offset, -1, ENC_NA);
lock_tree = proto_item_add_subtree(lock_item, ett_nisplus_directory);
offset = dissect_rpc_string(tvb, lock_tree,
hf_nisplus_directory_name, offset, NULL);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_nisplus_directory_type, offset);
offset = dissect_rpc_array(tvb, pinfo, lock_tree, offset,
dissect_directory_server, hf_nisplus_servers);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_nisplus_directory_ttl, offset);
offset = dissect_rpc_array(tvb, pinfo, lock_tree, offset,
dissect_directory_mask, hf_nisplus_directory_mask_list);
proto_item_set_len(lock_item, offset-old_offset);
return offset;
}
static int
dissect_nisplus_oid(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_item* lock_item = NULL;
proto_tree* lock_tree = NULL;
int old_offset = offset;
lock_item = proto_tree_add_item(tree, hf_nisplus_oid, tvb,
offset, -1, ENC_NA);
lock_tree = proto_item_add_subtree(lock_item, ett_nisplus_oid);
offset = dissect_nisplus_time(tvb, offset, lock_tree,
hf_nisplus_object_ctime);
offset = dissect_nisplus_time(tvb, offset, lock_tree,
hf_nisplus_object_mtime);
proto_item_set_len(lock_item, offset-old_offset);
return offset;
}
static int
dissect_nisplus_object(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree)
{
proto_item* lock_item = NULL;
proto_tree* lock_tree = NULL;
gint32 type;
int old_offset = offset;
lock_item = proto_tree_add_item(tree, hf_nisplus_object, tvb,
offset, -1, ENC_NA);
lock_tree = proto_item_add_subtree(lock_item, ett_nisplus_object);
offset = dissect_nisplus_oid(tvb, offset, lock_tree);
offset = dissect_rpc_string(tvb, lock_tree,
hf_nisplus_object_name, offset, NULL);
offset = dissect_rpc_string(tvb, lock_tree,
hf_nisplus_object_owner, offset, NULL);
offset = dissect_rpc_string(tvb, lock_tree,
hf_nisplus_object_group, offset, NULL);
offset = dissect_rpc_string(tvb, lock_tree,
hf_nisplus_object_domain, offset, NULL);
offset = dissect_access_rights(tvb, offset, lock_tree);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_nisplus_object_ttl, offset);
type = tvb_get_ntohl(tvb, offset);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_nisplus_object_type, offset);
switch (type) {
case NIS_DIRECTORY_OBJ:
offset = dissect_directory_obj(tvb, offset, pinfo, lock_tree);
break;
case NIS_GROUP_OBJ:
offset = dissect_group_obj(tvb, offset, pinfo, lock_tree);
break;
case NIS_TABLE_OBJ:
offset = dissect_table_obj(tvb, offset, pinfo, lock_tree);
break;
case NIS_ENTRY_OBJ:
offset = dissect_entry_obj(tvb, offset, pinfo, lock_tree);
break;
case NIS_LINK_OBJ:
offset = dissect_link_obj(tvb, offset, pinfo, lock_tree);
break;
case NIS_PRIVATE_OBJ:
offset = dissect_rpc_data(tvb, lock_tree,
hf_nisplus_object_private, offset);
break;
case NIS_NO_OBJ:
break;
case NIS_BOGUS_OBJ:
break;
default:
break;
};
proto_item_set_len(lock_item, offset-old_offset);
return offset;
}
static int
dissect_ns_request(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree)
{
offset = dissect_rpc_string(tvb, tree,
hf_nisplus_object_name, offset, NULL);
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_nisplus_object, hf_nisplus_object);
return offset;
}
static int
dissect_ib_request(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree)
{
offset = dissect_rpc_string(tvb, tree,
hf_nisplus_object_name, offset, NULL);
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_attr, hf_nisplus_attrs_array);
offset = dissect_rpc_uint32(tvb, tree,
hf_nisplus_ib_flags, offset);
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_nisplus_object, hf_nisplus_object);
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_directory_server, hf_nisplus_cbservers);
offset = dissect_rpc_uint32(tvb, tree,
hf_nisplus_ib_bufsize, offset);
offset = dissect_rpc_data(tvb, tree,
hf_nisplus_cookie, offset);
return offset;
}
static int
dissect_fd_args(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
offset = dissect_rpc_string(tvb, tree,
hf_nisplus_fd_dirname, offset, NULL);
offset = dissect_rpc_string(tvb, tree,
hf_nisplus_fd_requester, offset, NULL);
return offset;
}
static int
dissect_nisplus_tag(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item* lock_item = NULL;
proto_tree* lock_tree = NULL;
int old_offset = offset;
lock_item = proto_tree_add_item(tree, hf_nisplus_tag, tvb,
offset, -1, ENC_NA);
lock_tree = proto_item_add_subtree(lock_item, ett_nisplus_tag);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_nisplus_tag_type, offset);
offset = dissect_rpc_string(tvb, lock_tree,
hf_nisplus_tag_val, offset, NULL);
proto_item_set_len(lock_item, offset-old_offset);
return offset;
}
static int
dissect_nisplus_taglist(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree)
{
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_nisplus_tag, hf_nisplus_taglist);
return offset;
}
static int
dissect_dump_args(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree)
{
offset = dissect_rpc_string(tvb, tree,
hf_nisplus_dump_dir, offset, NULL);
offset = dissect_nisplus_time(tvb, offset, tree,
hf_nisplus_dump_time);
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_directory_server, hf_nisplus_cbservers);
return offset;
}
static int
dissect_netobj(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
offset = dissect_rpc_data(tvb, tree,
hf_nisplus_dummy, offset);
return offset;
}
static int
dissect_nisname(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
offset = dissect_rpc_string(tvb, tree,
hf_nisplus_object_name, offset, NULL);
return offset;
}
static int
dissect_ping_args(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
offset = dissect_rpc_string(tvb, tree,
hf_nisplus_ping_dir, offset, NULL);
offset = dissect_nisplus_time(tvb, offset, tree,
hf_nisplus_ping_time);
return offset;
}
static int
dissect_nisplus_result(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree)
{
offset = dissect_rpc_uint32(tvb, tree,
hf_nisplus_error, offset);
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_nisplus_object, hf_nisplus_object);
offset = dissect_rpc_data(tvb, tree,
hf_nisplus_cookie, offset);
offset = dissect_rpc_uint32(tvb, tree,
hf_nisplus_zticks, offset);
offset = dissect_rpc_uint32(tvb, tree,
hf_nisplus_dticks, offset);
offset = dissect_rpc_uint32(tvb, tree,
hf_nisplus_aticks, offset);
offset = dissect_rpc_uint32(tvb, tree,
hf_nisplus_cticks, offset);
return offset;
}
static int
dissect_fd_result(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
offset = dissect_rpc_uint32(tvb, tree,
hf_nisplus_error, offset);
offset = dissect_rpc_string(tvb, tree,
hf_nisplus_fd_dirname, offset, NULL);
offset = dissect_rpc_data(tvb, tree,
hf_nisplus_dir_data, offset);
offset = dissect_rpc_data(tvb, tree,
hf_nisplus_signature, offset);
return offset;
}
static int
dissect_log_entry(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree)
{
proto_item* lock_item = NULL;
proto_tree* lock_tree = NULL;
int old_offset = offset;
lock_item = proto_tree_add_item(tree, hf_nisplus_log_entry,
tvb, offset, -1, ENC_NA);
lock_tree = proto_item_add_subtree(lock_item, ett_nisplus_log_entry);
offset = dissect_nisplus_time(tvb, offset, lock_tree,
hf_nisplus_log_time);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_nisplus_log_type, offset);
offset = dissect_rpc_string(tvb, lock_tree,
hf_nisplus_log_principal, offset, NULL);
offset = dissect_rpc_string(tvb, lock_tree,
hf_nisplus_directory_name, offset, NULL);
offset = dissect_rpc_array(tvb, pinfo, lock_tree, offset,
dissect_attr, hf_nisplus_attrs_array);
offset = dissect_nisplus_object(tvb, offset, pinfo, lock_tree);
proto_item_set_len(lock_item, offset-old_offset);
return offset;
}
static int
dissect_log_result(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree)
{
offset = dissect_rpc_uint32(tvb, tree,
hf_nisplus_error, offset);
offset = dissect_rpc_data(tvb, tree,
hf_nisplus_cookie, offset);
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_log_entry, hf_nisplus_log_entries);
return offset;
}
static int
dissect_callback_result(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
offset = dissect_rpc_bool(tvb, tree, hf_nisplus_callback_status,
offset);
return offset;
}
static int
dissect_change_time(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
offset = dissect_nisplus_time(tvb, offset, tree,
hf_nisplus_log_time);
return offset;
}
static int
dissect_cp_result(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
offset = dissect_rpc_uint32(tvb, tree,
hf_nisplus_cp_status, offset);
offset = dissect_rpc_uint32(tvb, tree,
hf_nisplus_cp_zticks, offset);
offset = dissect_rpc_uint32(tvb, tree,
hf_nisplus_cp_dticks, offset);
return offset;
}
static int
dissect_nisplus_error(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
offset = dissect_rpc_uint32(tvb, tree,
hf_nisplus_error, offset);
return offset;
}
void
proto_register_nis(void)
{
static const true_false_string tfs_col_binary = {
"column is binary",
"column is NOT binary"
};
static const true_false_string tfs_col_encrypted = {
"column is encrypted",
"column is NOT encrypted"
};
static const true_false_string tfs_col_xdr = {
"column is xdr encoded",
"column is NOT xdr encoded"
};
static const true_false_string tfs_col_searchable = {
"column is searchable",
"column is NOT searchable"
};
static const true_false_string tfs_col_casesensitive = {
"column is case sensitive",
"column is NOT case sensitive"
};
static const true_false_string tfs_col_modified = {
"column is modified",
"column is NOT modified"
};
static const true_false_string tfs_col_asn = {
"column is asn.1 encoded",
"column is NOT asn.1 encoded"
};
static const true_false_string tfs_entry_binary = {
"entry is binary",
"entry is NOT binary"
};
static const true_false_string tfs_entry_crypt = {
"entry is encrypted",
"entry is NOT encrypted"
};
static const true_false_string tfs_entry_xdr = {
"entry is xdr encoded",
"entry is NOT xdr encoded"
};
static const true_false_string tfs_entry_modified = {
"entry is modified",
"entry is NOT modified"
};
static const true_false_string tfs_entry_asn = {
"entry is asn.1 encoded",
"entry is NOT asn.1 encoded"
};
static const true_false_string tfs_world_read = {
"world can read",
"world can NOT read"
};
static const true_false_string tfs_world_modify = {
"world can modify",
"world can NOT modify"
};
static const true_false_string tfs_world_create = {
"world can create",
"world can NOT create"
};
static const true_false_string tfs_world_destroy = {
"world can destroy",
"world can NOT destroy"
};
static const true_false_string tfs_group_read = {
"group can read",
"group can NOT read"
};
static const true_false_string tfs_group_modify = {
"group can modify",
"group can NOT modify"
};
static const true_false_string tfs_group_create = {
"group can create",
"group can NOT create"
};
static const true_false_string tfs_group_destroy = {
"group can destroy",
"group can NOT destroy"
};
static const true_false_string tfs_owner_read = {
"owner can read",
"owner can NOT read"
};
static const true_false_string tfs_owner_modify = {
"owner can modify",
"owner can NOT modify"
};
static const true_false_string tfs_owner_create = {
"owner can create",
"owner can NOT create"
};
static const true_false_string tfs_owner_destroy = {
"owner can destroy",
"owner can NOT destroy"
};
static const true_false_string tfs_nobody_read = {
"nobody can read",
"nobody can NOT read"
};
static const true_false_string tfs_nobody_modify = {
"nobody can modify",
"nobody can NOT modify"
};
static const true_false_string tfs_nobody_create = {
"nobody can create",
"nobody can NOT create"
};
static const true_false_string tfs_nobody_destroy = {
"nobody can destroy",
"nobody can NOT destroy"
};
static const true_false_string tfs_callback_status = {
"unknown",
"unknown"
};
static hf_register_info hf[] = {
{ &hf_nisplus_procedure_v3, {
"V3 Procedure", "nisplus.procedure_v3", FT_UINT32, BASE_DEC,
VALS(nisplus3_proc_vals), 0, NULL, HFILL }},
{ &hf_nisplus_object, {
"NIS Object", "nisplus.object", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_nisplus_oid, {
"Object Identity Verifier", "nisplus.object.oid", FT_NONE, BASE_NONE,
NULL, 0, "NIS Object Identity Verifier", HFILL }},
{ &hf_nisplus_object_name, {
"name", "nisplus.object.name", FT_STRING, BASE_NONE,
NULL, 0, "NIS Name For This Object", HFILL }},
{ &hf_nisplus_object_owner, {
"owner", "nisplus.object.owner", FT_STRING, BASE_NONE,
NULL, 0, "NIS Name Of Object Owner", HFILL }},
{ &hf_nisplus_object_group, {
"group", "nisplus.object.group", FT_STRING, BASE_NONE,
NULL, 0, "NIS Name Of Access Group", HFILL }},
{ &hf_nisplus_object_domain, {
"domain", "nisplus.object.domain", FT_STRING, BASE_NONE,
NULL, 0, "NIS Administrator For This Object", HFILL }},
{ &hf_nisplus_object_ttl, {
"ttl", "nisplus.object.ttl", FT_UINT32, BASE_DEC,
NULL, 0, "NIS Time To Live For This Object", HFILL }},
{ &hf_nisplus_object_private, {
"private", "nisplus.object.private", FT_BYTES, BASE_NONE,
NULL, 0, "NIS Private Object", HFILL }},
{ &hf_nisplus_directory, {
"directory", "nisplus.directory", FT_NONE, BASE_NONE,
NULL, 0, "NIS Directory Object", HFILL }},
{ &hf_nisplus_directory_name, {
"directory name", "nisplus.directory.name", FT_STRING, BASE_NONE,
NULL, 0, "Name Of Directory Being Served", HFILL }},
{ &hf_nisplus_directory_type, {
"type", "nisplus.directory.type", FT_UINT32, BASE_DEC,
VALS(ns_type), 0, "NIS Type Of Name Service", HFILL }},
{ &hf_nisplus_directory_ttl, {
"ttl", "nisplus.directory.ttl", FT_UINT32, BASE_DEC,
NULL, 0, "Time To Live", HFILL }},
{ &hf_nisplus_directory_mask, {
"mask", "nisplus.directory.mask", FT_NONE, BASE_NONE,
NULL, 0, "NIS Directory Create/Destroy Rights", HFILL }},
{ &hf_nisplus_directory_mask_list, {
"mask list", "nisplus.directory.mask_list", FT_NONE, BASE_NONE,
NULL, 0, "List Of Directory Create/Destroy Rights", HFILL }},
{ &hf_nisplus_mask_world_read, {
"WORLD READ", "nisplus.directory.mask.world_read",
FT_BOOLEAN, 32, TFS(&tfs_world_read),
NIS_MASK_WORLD_READ, "World Read Flag", HFILL }},
{ &hf_nisplus_mask_world_modify, {
"WORLD MODIFY", "nisplus.directory.mask.world_modify",
FT_BOOLEAN, 32, TFS(&tfs_world_modify),
NIS_MASK_WORLD_MODIFY, "World Modify Flag", HFILL }},
{ &hf_nisplus_mask_world_create, {
"WORLD CREATE", "nisplus.directory.mask.world_create",
FT_BOOLEAN, 32, TFS(&tfs_world_create),
NIS_MASK_WORLD_CREATE, "World Create Flag", HFILL }},
{ &hf_nisplus_mask_world_destroy, {
"WORLD DESTROY", "nisplus.directory.mask.world_destroy",
FT_BOOLEAN, 32, TFS(&tfs_world_destroy),
NIS_MASK_WORLD_DESTROY, "World Destroy Flag", HFILL }},
{ &hf_nisplus_mask_group_read, {
"GROUP READ", "nisplus.directory.mask.group_read",
FT_BOOLEAN, 32, TFS(&tfs_group_read),
NIS_MASK_GROUP_READ, "Group Read Flag", HFILL }},
{ &hf_nisplus_mask_group_modify, {
"GROUP MODIFY", "nisplus.directory.mask.group_modify",
FT_BOOLEAN, 32, TFS(&tfs_group_modify),
NIS_MASK_GROUP_MODIFY, "Group Modify Flag", HFILL }},
{ &hf_nisplus_mask_group_create, {
"GROUP CREATE", "nisplus.directory.mask.group_create",
FT_BOOLEAN, 32, TFS(&tfs_group_create),
NIS_MASK_GROUP_CREATE, "Group Create Flag", HFILL }},
{ &hf_nisplus_mask_group_destroy, {
"GROUP DESTROY", "nisplus.directory.mask.group_destroy",
FT_BOOLEAN, 32, TFS(&tfs_group_destroy),
NIS_MASK_GROUP_DESTROY, "Group Destroy Flag", HFILL }},
{ &hf_nisplus_mask_owner_read, {
"OWNER READ", "nisplus.directory.mask.owner_read",
FT_BOOLEAN, 32, TFS(&tfs_owner_read),
NIS_MASK_OWNER_READ, "Owner Read Flag", HFILL }},
{ &hf_nisplus_mask_owner_modify, {
"OWNER MODIFY", "nisplus.directory.mask.owner_modify",
FT_BOOLEAN, 32, TFS(&tfs_owner_modify),
NIS_MASK_OWNER_MODIFY, "Owner Modify Flag", HFILL }},
{ &hf_nisplus_mask_owner_create, {
"OWNER CREATE", "nisplus.directory.mask.owner_create",
FT_BOOLEAN, 32, TFS(&tfs_owner_create),
NIS_MASK_OWNER_CREATE, "Owner Create Flag", HFILL }},
{ &hf_nisplus_mask_owner_destroy, {
"OWNER DESTROY", "nisplus.directory.mask.owner_destroy",
FT_BOOLEAN, 32, TFS(&tfs_owner_destroy),
NIS_MASK_OWNER_DESTROY, "Owner Destroy Flag", HFILL }},
{ &hf_nisplus_mask_nobody_read, {
"NOBODY READ", "nisplus.directory.mask.nobody_read",
FT_BOOLEAN, 32, TFS(&tfs_nobody_read),
NIS_MASK_NOBODY_READ, "Nobody Read Flag", HFILL }},
{ &hf_nisplus_mask_nobody_modify, {
"NOBODY MODIFY", "nisplus.directory.mask.nobody_modify",
FT_BOOLEAN, 32, TFS(&tfs_nobody_modify),
NIS_MASK_NOBODY_MODIFY, "Nobody Modify Flag", HFILL }},
{ &hf_nisplus_mask_nobody_create, {
"NOBODY CREATE", "nisplus.directory.mask.nobody_create",
FT_BOOLEAN, 32, TFS(&tfs_nobody_create),
NIS_MASK_NOBODY_CREATE, "Nobody Create Flag", HFILL }},
{ &hf_nisplus_mask_nobody_destroy, {
"NOBODY DESTROY", "nisplus.directory.mask.nobody_destroy",
FT_BOOLEAN, 32, TFS(&tfs_nobody_destroy),
NIS_MASK_NOBODY_DESTROY, "Nobody Destroy Flag", HFILL }},
{ &hf_nisplus_access_mask, {
"access mask", "nisplus.access.mask", FT_NONE, BASE_NONE,
NULL, 0, "NIS Access Mask", HFILL }},
{ &hf_nisplus_object_type, {
"type", "nisplus.object.type", FT_UINT32, BASE_DEC,
VALS(obj_type), 0, "NIS Type Of Object", HFILL }},
{ &hf_nisplus_servers, {
"nis servers", "nisplus.servers", FT_NONE, BASE_NONE,
NULL, 0, "NIS Servers For This Directory", HFILL }},
{ &hf_nisplus_cbservers, {
"nis servers", "nisplus.servers", FT_NONE, BASE_NONE,
NULL, 0, "Optional Callback Server", HFILL }},
{ &hf_nisplus_server, {
"server", "nisplus.server", FT_NONE, BASE_NONE,
NULL, 0, "NIS Server For This Directory", HFILL }},
{ &hf_nisplus_server_name, {
"name", "nisplus.server.name", FT_STRING, BASE_NONE,
NULL, 0, "Name Of NIS Server", HFILL }},
{ &hf_nisplus_key_type, {
"type", "nisplus.key.type", FT_UINT32, BASE_DEC,
VALS(key_type), 0, "Type Of Key", HFILL }},
{ &hf_nisplus_key_data, {
"key data", "nisplus.key.data", FT_BYTES, BASE_NONE,
NULL, 0, "Encryption Key", HFILL }},
{ &hf_nisplus_endpoints, {
"nis endpoints", "nisplus.endpoints", FT_NONE, BASE_NONE,
NULL, 0, "Endpoints For This NIS Server", HFILL }},
{ &hf_nisplus_endpoint, {
"endpoint", "nisplus.endpoint", FT_NONE, BASE_NONE,
NULL, 0, "Endpoint For This NIS Server", HFILL }},
{ &hf_nisplus_endpoint_uaddr, {
"addr", "nisplus.endpoint.uaddr", FT_STRING, BASE_NONE,
NULL, 0, "Address", HFILL }},
{ &hf_nisplus_endpoint_family, {
"family", "nisplus.endpoint.family", FT_STRING, BASE_NONE,
NULL, 0, "Transport Family", HFILL }},
{ &hf_nisplus_endpoint_proto, {
"proto", "nisplus.endpoint.proto", FT_STRING, BASE_NONE,
NULL, 0, "Protocol", HFILL }},
{ &hf_nisplus_link, {
"link", "nisplus.link", FT_NONE, BASE_NONE,
NULL, 0, "NIS Link Object", HFILL }},
{ &hf_nisplus_attrs_array, {
"Attributes", "nisplus.attributes", FT_NONE, BASE_NONE,
NULL, 0, "List Of Attributes", HFILL }},
{ &hf_nisplus_attr, {
"Attribute", "nisplus.attr", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_nisplus_attr_name, {
"name", "nisplus.attr.name", FT_STRING, BASE_NONE,
NULL, 0, "Attribute Name", HFILL }},
{ &hf_nisplus_attr_val, {
"val", "nisplus.attr.val", FT_BYTES, BASE_NONE,
NULL, 0, "Attribute Value", HFILL }},
{ &hf_nisplus_entry, {
"entry", "nisplus.entry", FT_NONE, BASE_NONE,
NULL, 0, "Entry Object", HFILL }},
{ &hf_nisplus_entry_type, {
"type", "nisplus.entry.type", FT_STRING, BASE_NONE,
NULL, 0, "Entry Type", HFILL }},
{ &hf_nisplus_entry_cols, {
"columns", "nisplus.entry.cols", FT_NONE, BASE_NONE,
NULL, 0, "Entry Columns", HFILL }},
{ &hf_nisplus_entry_col, {
"column", "nisplus.entry.col", FT_NONE, BASE_NONE,
NULL, 0, "Entry Column", HFILL }},
{ &hf_nisplus_entry_flags, {
"flags", "nisplus.entry.flags", FT_UINT32, BASE_HEX,
NULL, 0, "Entry Col Flags", HFILL }},
{ &hf_nisplus_entry_val, {
"val", "nisplus.entry.val", FT_STRING, BASE_NONE,
NULL, 0, "Entry Value", HFILL }},
{ &hf_nisplus_entry_mask, {
"mask", "nisplus.entry.mask", FT_NONE, BASE_NONE,
NULL, 0, "Entry Col Mask", HFILL }},
{ &hf_nisplus_entry_mask_binary, {
"BINARY", "nisplus.entry.mask.binary",
FT_BOOLEAN, 32, TFS(&tfs_entry_binary),
NIS_MASK_ENTRY_BINARY, "Is This Entry BINARY Flag", HFILL }},
{ &hf_nisplus_entry_mask_crypt, {
"ENCRYPTED", "nisplus.entry.mask.encrypted",
FT_BOOLEAN, 32, TFS(&tfs_entry_crypt),
NIS_MASK_ENTRY_CRYPT, "Is This Entry ENCRYPTED Flag", HFILL }},
{ &hf_nisplus_entry_mask_xdr, {
"XDR", "nisplus.entry.mask.xdr",
FT_BOOLEAN, 32, TFS(&tfs_entry_xdr),
NIS_MASK_ENTRY_XDR, "Is This Entry XDR Encoded Flag", HFILL }},
{ &hf_nisplus_entry_mask_modified, {
"MODIFIED", "nisplus.entry.mask.modified",
FT_BOOLEAN, 32, TFS(&tfs_entry_modified),
NIS_MASK_ENTRY_MODIFIED, "Is This Entry MODIFIED Flag", HFILL }},
{ &hf_nisplus_entry_mask_asn, {
"ASN.1", "nisplus.entry.mask.asn",
FT_BOOLEAN, 32, TFS(&tfs_entry_asn),
NIS_MASK_ENTRY_ASN, "Is This Entry ASN.1 Encoded Flag", HFILL }},
{ &hf_nisplus_table, {
"table", "nisplus.table", FT_NONE, BASE_NONE,
NULL, 0, "Table Object", HFILL }},
{ &hf_nisplus_table_type, {
"type", "nisplus.table.type", FT_STRING, BASE_NONE,
NULL, 0, "Table Type", HFILL }},
{ &hf_nisplus_table_maxcol, {
"max columns", "nisplus.table.maxcol", FT_UINT16, BASE_DEC,
NULL, 0, "Maximum Number Of Columns For Table", HFILL }},
{ &hf_nisplus_table_sep, {
"separator", "nisplus.table.separator", FT_UINT8, BASE_HEX,
NULL, 0, "Separator Character", HFILL }},
{ &hf_nisplus_table_cols, {
"columns", "nisplus.table.cols", FT_NONE, BASE_NONE,
NULL, 0, "Table Columns", HFILL }},
{ &hf_nisplus_table_col, {
"column", "nisplus.table.col", FT_NONE, BASE_NONE,
NULL, 0, "Table Column", HFILL }},
{ &hf_nisplus_table_path, {
"path", "nisplus.table.path", FT_STRING, BASE_NONE,
NULL, 0, "Table Path", HFILL }},
{ &hf_nisplus_table_col_name, {
"column name", "nisplus.table.col.name", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_nisplus_table_col_mask, {
"flags", "nisplus.table.col.flags", FT_NONE, BASE_NONE,
NULL, 0, "Flags For This Column", HFILL }},
{ &hf_nisplus_table_col_mask_binary, {
"binary", "nisplus.table.flags.binary",
FT_BOOLEAN, 32, TFS(&tfs_col_binary),
NIS_MASK_TABLE_BINARY, "Is This Column BINARY", HFILL }},
{ &hf_nisplus_table_col_mask_encrypted, {
"encrypted", "nisplus.table.flags.encrypted",
FT_BOOLEAN, 32, TFS(&tfs_col_encrypted),
NIS_MASK_TABLE_CRYPT, "Is This Column ENCRYPTED", HFILL }},
{ &hf_nisplus_table_col_mask_xdr, {
"xdr", "nisplus.table.flags.xdr",
FT_BOOLEAN, 32, TFS(&tfs_col_xdr),
NIS_MASK_TABLE_XDR, "Is This Column XDR Encoded", HFILL }},
{ &hf_nisplus_table_col_mask_searchable, {
"searchable", "nisplus.table.flags.searchable",
FT_BOOLEAN, 32, TFS(&tfs_col_searchable),
NIS_MASK_TABLE_SRCH, "Is This Column SEARCHABLE", HFILL }},
{ &hf_nisplus_table_col_mask_casesensitive, {
"casesensitive", "nisplus.table.flags.casesensitive",
FT_BOOLEAN, 32, TFS(&tfs_col_casesensitive),
NIS_MASK_TABLE_CASE, "Is This Column CASESENSITIVE", HFILL }},
{ &hf_nisplus_table_col_mask_modified, {
"modified", "nisplus.table.flags.modified",
FT_BOOLEAN, 32, TFS(&tfs_col_modified),
NIS_MASK_TABLE_MODIFIED, "Is This Column MODIFIED", HFILL }},
{ &hf_nisplus_table_col_mask_asn, {
"asn", "nisplus.table.flags.asn",
FT_BOOLEAN, 32, TFS(&tfs_col_asn),
NIS_MASK_TABLE_ASN, "Is This Column ASN.1 Encoded", HFILL }},
{ &hf_nisplus_group, {
"Group", "nisplus.group", FT_NONE, BASE_NONE,
NULL, 0, "Group Object", HFILL }},
{ &hf_nisplus_grps, {
"Groups", "nisplus.grps", FT_NONE, BASE_NONE,
NULL, 0, "List Of Groups", HFILL }},
{ &hf_nisplus_group_flags, {
"flags", "nisplus.group.flags", FT_UINT32, BASE_HEX,
NULL, 0, "Group Object Flags", HFILL }},
{ &hf_nisplus_group_name, {
"group name", "nisplus.group.name", FT_STRING, BASE_NONE,
NULL, 0, "Name Of Group Member", HFILL }},
{ &hf_nisplus_object_ctime, {
"ctime", "nisplus.ctime", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Time Of Creation", HFILL }},
{ &hf_nisplus_object_mtime, {
"mtime", "nisplus.mtime", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Time Last Modified", HFILL }},
{ &hf_nisplus_ib_flags, {
"flags", "nisplus.ib.flags", FT_UINT32, BASE_HEX,
NULL, 0, "Information Base Flags", HFILL }},
{ &hf_nisplus_ib_bufsize, {
"bufsize", "nisplus.ib.bufsize", FT_UINT32, BASE_HEX,
NULL, 0, "Optional First/NextBufSize", HFILL }},
{ &hf_nisplus_cookie, {
"cookie", "nisplus.cookie", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_nisplus_fd_dirname, {
"dirname", "nisplus.fd.dirname", FT_STRING, BASE_NONE,
NULL, 0, "Directory Name", HFILL }},
{ &hf_nisplus_fd_requester, {
"requester", "nisplus.fd.requester", FT_STRING, BASE_NONE,
NULL, 0, "Host Principal Name For Signature", HFILL }},
{ &hf_nisplus_taglist, {
"taglist", "nisplus.taglist", FT_NONE, BASE_NONE,
NULL, 0, "List Of Tags", HFILL }},
{ &hf_nisplus_tag, {
"tag", "nisplus.tag", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_nisplus_tag_type, {
"type", "nisplus.tag.type", FT_UINT32, BASE_DEC,
NULL, 0, "Type Of Statistics Tag", HFILL }},
{ &hf_nisplus_tag_val, {
"value", "nisplus.tag.value", FT_STRING, BASE_NONE,
NULL, 0, "Value Of Statistics Tag", HFILL }},
{ &hf_nisplus_dump_dir, {
"directory", "nisplus.dump.dir", FT_STRING, BASE_NONE,
NULL, 0, "Directory To Dump", HFILL }},
{ &hf_nisplus_dump_time, {
"time", "nisplus.dump.time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "From This Timestamp", HFILL }},
{ &hf_nisplus_dummy, {
"dummy", "nisplus.dummy", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_nisplus_ping_time, {
"time", "nisplus.ping.time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Timestamp Of The Transaction", HFILL }},
{ &hf_nisplus_ping_dir, {
"directory", "nisplus.ping.dir", FT_STRING, BASE_NONE,
NULL, 0, "Directory That Had The Change", HFILL }},
{ &hf_nisplus_error, {
"status", "nisplus.status", FT_UINT32, BASE_DEC,
VALS(nis_error), 0, "NIS Status Code", HFILL }},
{ &hf_nisplus_dir_data, {
"data", "nisplus.fd.dir.data", FT_BYTES, BASE_NONE,
NULL, 0, "Directory Data In XDR Format", HFILL }},
{ &hf_nisplus_signature, {
"signature", "nisplus.fd.sig", FT_BYTES, BASE_NONE,
NULL, 0, "Signature Of The Source", HFILL }},
{ &hf_nisplus_log_entries, {
"log entries", "nisplus.log.entries", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_nisplus_log_entry, {
"log entry", "nisplus.log.entry", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_nisplus_log_time, {
"time", "nisplus.log.time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Time Of Log Entry", HFILL }},
{ &hf_nisplus_log_type, {
"type", "nisplus.log.entry.type", FT_UINT32, BASE_DEC,
VALS(entry_type), 0, "Type Of Entry In Transaction Log", HFILL }},
{ &hf_nisplus_log_principal, {
"principal", "nisplus.log.principal", FT_STRING, BASE_NONE,
NULL, 0, "Principal Making The Change", HFILL }},
{ &hf_nisplus_callback_status, {
"status", "nisplus.callback.status",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_callback_status),
0x0, "Status Of Callback Thread", HFILL }},
{ &hf_nisplus_cp_status, {
"status", "nisplus.checkpoint.status", FT_UINT32, BASE_DEC,
NULL, 0, "Checkpoint Status", HFILL }},
{ &hf_nisplus_cp_zticks, {
"zticks", "nisplus.checkpoint.zticks", FT_UINT32, BASE_DEC,
NULL, 0, "Service Ticks", HFILL }},
{ &hf_nisplus_cp_dticks, {
"dticks", "nisplus.checkpoint.dticks", FT_UINT32, BASE_DEC,
NULL, 0, "Database Ticks", HFILL }},
{ &hf_nisplus_zticks, {
"zticks", "nisplus.zticks", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_nisplus_dticks, {
"dticks", "nisplus.dticks", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_nisplus_aticks, {
"aticks", "nisplus.aticks", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_nisplus_cticks, {
"cticks", "nisplus.cticks", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_nisplus,
&ett_nisplus_object,
&ett_nisplus_oid,
&ett_nisplus_directory,
&ett_nisplus_directory_mask,
&ett_nisplus_access_mask,
&ett_nisplus_server,
&ett_nisplus_endpoint,
&ett_nisplus_link,
&ett_nisplus_attr,
&ett_nisplus_entry,
&ett_nisplus_entry_col,
&ett_nisplus_entry_mask,
&ett_nisplus_table,
&ett_nisplus_table_col,
&ett_nisplus_table_col_mask,
&ett_nisplus_group,
&ett_nisplus_grps,
&ett_nisplus_tag,
&ett_nisplus_log_entry,
};
proto_nisplus = proto_register_protocol("NIS+",
"NIS+", "nisplus");
proto_register_field_array(proto_nisplus, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_nis(void)
{
rpc_init_prog(proto_nisplus, NIS_PROGRAM, ett_nisplus);
rpc_init_proc_table(NIS_PROGRAM, 3, nisplus3_proc, hf_nisplus_procedure_v3);
}
static int
dissect_cb_entry(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item* lock_item = NULL;
int old_offset = offset;
lock_item = proto_tree_add_item(tree, hf_nispluscb_entry,
tvb, offset, -1, ENC_NA);
proto_item_set_len(lock_item, offset-old_offset);
return offset;
}
static int
dissect_cback_data(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree)
{
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_cb_entry, hf_nispluscb_entries);
return offset;
}
void
proto_register_niscb(void)
{
static hf_register_info hf[] = {
{ &hf_nispluscb_procedure_v1, {
"V1 Procedure", "nispluscb.procedure_v1", FT_UINT32, BASE_DEC,
VALS(nispluscb1_proc_vals), 0, NULL, HFILL }},
{ &hf_nispluscb_entries, {
"entries", "nispluscb.entries", FT_NONE, BASE_NONE,
NULL, 0, "NIS Callback Entries", HFILL }},
{ &hf_nispluscb_entry, {
"entry", "nispluscb.entry", FT_NONE, BASE_NONE,
NULL, 0, "NIS Callback Entry", HFILL }},
};
static gint *ett[] = {
&ett_nispluscb,
&ett_nispluscb_entry,
};
proto_nispluscb = proto_register_protocol("NIS+ Callback",
"NIS+ CB", "nispluscb");
proto_register_field_array(proto_nispluscb, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_niscb(void)
{
rpc_init_prog(proto_nispluscb, CB_PROGRAM, ett_nispluscb);
rpc_init_proc_table(CB_PROGRAM, 1, cb1_proc, hf_nispluscb_procedure_v1);
}
