static int
dissect_genl_ctrl_ops_attrs(tvbuff_t *tvb, void *data, proto_tree *tree, int nla_type, int offset, int len)
{
enum ws_genl_ctrl_op_attr type = (enum ws_genl_ctrl_op_attr) nla_type;
genl_ctrl_info_t *info = (genl_ctrl_info_t *) data;
proto_tree *ptree = proto_tree_get_parent_tree(tree);
guint32 value;
switch (type) {
case WS_CTRL_ATTR_OP_UNSPEC:
break;
case WS_CTRL_ATTR_OP_ID:
if (len == 4) {
proto_tree_add_item_ret_uint(tree, hfi_genl_ctrl_op_id.id, tvb, offset, 4, info->encoding, &value);
proto_item_append_text(tree, ": %u", value);
proto_item_append_text(ptree, ", id=%u", value);
offset += 4;
}
break;
case WS_CTRL_ATTR_OP_FLAGS:
if (len == 4) {
guint64 op_flags;
proto_tree_add_bitmask_with_flags_ret_uint64(tree, tvb, offset, hfi_genl_ctrl_op_flags.id, ett_genl_ctrl_op_flags, genl_ctrl_op_flags_fields, info->encoding, BMT_NO_FALSE, &op_flags);
proto_item_append_text(tree, ": 0x%08x", (guint32)op_flags);
proto_item_append_text(ptree, ", flags=0x%08x", (guint32)op_flags);
offset += 4;
}
break;
}
return offset;
}
static int
dissect_genl_ctrl_groups_attrs(tvbuff_t *tvb, void *data, proto_tree *tree, int nla_type, int offset, int len)
{
enum ws_genl_ctrl_group_attr type = (enum ws_genl_ctrl_group_attr) nla_type;
genl_ctrl_info_t *info = (genl_ctrl_info_t *) data;
proto_tree *ptree = proto_tree_get_parent_tree(tree);
guint32 value;
const guint8 *strval;
switch (type) {
case WS_CTRL_ATTR_MCAST_GRP_UNSPEC:
break;
case WS_CTRL_ATTR_MCAST_GRP_NAME:
proto_tree_add_item_ret_string(tree, hfi_genl_ctrl_group_name.id, tvb, offset, len, ENC_ASCII, wmem_packet_scope(), &strval);
proto_item_append_text(tree, ": %s", strval);
proto_item_append_text(ptree, ", name=%s", strval);
offset += len;
break;
case WS_CTRL_ATTR_MCAST_GRP_ID:
if (len == 4) {
proto_tree_add_item_ret_uint(tree, hfi_genl_ctrl_group_id.id, tvb, offset, 4, info->encoding, &value);
proto_item_append_text(tree, ": %u", value);
proto_item_append_text(ptree, ", id=%u", value);
offset += 4;
}
break;
}
return offset;
}
static int
dissect_genl_ctrl_attrs(tvbuff_t *tvb, void *data, proto_tree *tree, int nla_type, int offset, int len)
{
enum ws_genl_ctrl_attr type = (enum ws_genl_ctrl_attr) nla_type;
genl_ctrl_info_t *info = (genl_ctrl_info_t *) data;
guint32 value;
switch (type) {
case WS_CTRL_CMD_UNSPEC:
break;
case WS_CTRL_ATTR_FAMILY_ID:
if (len == 2) {
proto_tree_add_item_ret_uint(tree, hfi_genl_ctrl_family_id.id, tvb, offset, 2, info->encoding, &value);
proto_item_append_text(tree, ": %#x", value);
info->family_id = value;
offset += 2;
}
break;
case WS_CTRL_ATTR_FAMILY_NAME:
proto_tree_add_item_ret_string(tree, hfi_genl_ctrl_family_name.id, tvb, offset, len, ENC_ASCII, wmem_packet_scope(), &info->family_name);
proto_item_append_text(tree, ": %s", info->family_name);
offset += len;
break;
case WS_CTRL_ATTR_VERSION:
if (len == 4) {
proto_tree_add_item_ret_uint(tree, hfi_genl_ctrl_version.id, tvb, offset, 4, info->encoding, &value);
proto_item_append_text(tree, ": %u", value);
offset += 4;
}
break;
case WS_CTRL_ATTR_HDRSIZE:
if (len == 4) {
proto_tree_add_item_ret_uint(tree, hfi_genl_ctrl_hdrsize.id, tvb, offset, 4, info->encoding, &value);
proto_item_append_text(tree, ": %u", value);
offset += 4;
}
break;
case WS_CTRL_ATTR_MAXATTR:
if (len == 4) {
proto_tree_add_item_ret_uint(tree, hfi_genl_ctrl_maxattr.id, tvb, offset, 4, info->encoding, &value);
proto_item_append_text(tree, ": %u", value);
offset += 4;
}
break;
case WS_CTRL_ATTR_OPS:
offset = dissect_netlink_attributes_array(tvb, &hfi_genl_ctrl_ops_attr, ett_genl_ctrl_ops, ett_genl_ctrl_ops_attr, info, info->data, tree, offset, len, dissect_genl_ctrl_ops_attrs);
break;
case WS_CTRL_ATTR_MCAST_GROUPS:
offset = dissect_netlink_attributes_array(tvb, &hfi_genl_ctrl_groups_attr, ett_genl_ctrl_groups, ett_genl_ctrl_groups_attr, info, info->data, tree, offset, len, dissect_genl_ctrl_groups_attrs);
break;
}
return offset;
}
static int
dissect_genl_ctrl(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, void *data)
{
genl_info_t *genl_info = (genl_info_t *) data;
genl_ctrl_info_t info;
int offset;
if (!genl_info) {
return 0;
}
info.data = genl_info->data;
info.encoding = genl_info->encoding;
info.family_id = 0;
info.family_name = NULL;
offset = dissect_genl_header(tvb, genl_info, &hfi_genl_ctrl_cmd);
dissect_netlink_attributes(tvb, &hfi_genl_ctrl_attr, ett_genl_ctrl_attr, &info, info.data, genl_info->genl_tree, offset, -1, dissect_genl_ctrl_attrs);
if (info.family_id && info.family_id != WS_GENL_ID_CTRL && info.family_name) {
wmem_map_insert(genl_family_map, GUINT_TO_POINTER(info.family_id), wmem_strdup(wmem_file_scope(), info.family_name));
}
return tvb_captured_length(tvb);
}
int dissect_genl_header(tvbuff_t *tvb, genl_info_t *genl_info, header_field_info *hfi_cmd)
{
int offset = 0;
if (!hfi_cmd) {
hfi_cmd = &hfi_genl_cmd;
}
proto_tree_add_item(genl_info->genl_tree, hfi_cmd, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(genl_info->genl_tree, &hfi_genl_version, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(genl_info->genl_tree, &hfi_genl_reserved, tvb, offset, 2, genl_info->encoding);
offset += 2;
return offset;
}
static int
dissect_netlink_generic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *_data)
{
struct packet_netlink_data *data = (struct packet_netlink_data *)_data;
genl_info_t info;
proto_tree *nlmsg_tree;
proto_item *pi, *pi_type;
const char *family_name;
tvbuff_t *next_tvb;
int offset = 0;
DISSECTOR_ASSERT(data && data->magic == PACKET_NETLINK_MAGIC);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Netlink generic");
col_clear(pinfo->cinfo, COL_INFO);
pi = proto_tree_add_item(tree, proto_registrar_get_nth(proto_netlink_generic), tvb, 0, -1, ENC_NA);
nlmsg_tree = proto_item_add_subtree(pi, ett_netlink_generic);
offset = dissect_netlink_header(tvb, nlmsg_tree, offset, data->encoding, &hfi_genl_family_id, &pi_type);
family_name = (const char *)wmem_map_lookup(genl_family_map, GUINT_TO_POINTER(data->type));
proto_item_append_text(pi_type, " (%s)", family_name ? family_name : "Unknown");
info.data = data;
info.encoding = data->encoding;
info.genl_tree = nlmsg_tree;
info.cmd = tvb_get_guint8(tvb, offset);
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (tvb_reported_length_remaining(tvb, offset + 4)) {
if (family_name) {
int ret;
ret = dissector_try_string(genl_dissector_table, family_name, next_tvb, pinfo, tree, &info);
if (ret) {
return ret;
}
}
}
offset = dissect_genl_header(next_tvb, &info, NULL);
if (tvb_reported_length_remaining(tvb, offset)) {
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_data_dissector(next_tvb, pinfo, tree);
}
return offset;
}
static void
genl_init(void)
{
wmem_map_insert(genl_family_map, GUINT_TO_POINTER(WS_GENL_ID_CTRL), GENL_CTRL_NAME);
}
void
proto_register_netlink_generic(void)
{
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] = {
&hfi_genl_family_id,
&hfi_genl_cmd,
&hfi_genl_version,
&hfi_genl_reserved,
&hfi_genl_ctrl_attr,
&hfi_genl_ctrl_cmd,
&hfi_genl_ctrl_family_id,
&hfi_genl_ctrl_family_name,
&hfi_genl_ctrl_version,
&hfi_genl_ctrl_hdrsize,
&hfi_genl_ctrl_maxattr,
&hfi_genl_ctrl_ops_attr,
&hfi_genl_ctrl_groups_attr,
&hfi_genl_ctrl_op_id,
&hfi_genl_ctrl_op_flags,
&hfi_genl_ctrl_op_flags_admin_perm,
&hfi_genl_ctrl_op_flags_cmd_cap_do,
&hfi_genl_ctrl_op_flags_cmd_cap_dump,
&hfi_genl_ctrl_op_flags_cmd_cap_haspol,
&hfi_genl_ctrl_op_flags_uns_admin_perm,
&hfi_genl_ctrl_group_name,
&hfi_genl_ctrl_group_id,
};
#endif
static gint *ett[] = {
&ett_netlink_generic,
&ett_genl_ctrl_attr,
&ett_genl_ctrl_ops,
&ett_genl_ctrl_ops_attr,
&ett_genl_ctrl_op_flags,
&ett_genl_ctrl_groups,
&ett_genl_ctrl_groups_attr,
&ett_genl_nested_attr,
};
proto_netlink_generic = proto_register_protocol("Linux Generic Netlink protocol", "genl", "genl");
hfi_netlink_generic = proto_registrar_get_nth(proto_netlink_generic);
proto_register_fields(proto_netlink_generic, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
netlink_generic = create_dissector_handle(dissect_netlink_generic, proto_netlink_generic);
netlink_generic_ctrl = create_dissector_handle(dissect_genl_ctrl, proto_netlink_generic);
genl_dissector_table = register_dissector_table(
"genl.family",
"Linux Generic Netlink family name",
proto_netlink_generic, FT_STRING,
BASE_NONE
);
genl_family_map = wmem_map_new_autoreset(wmem_epan_scope(), wmem_file_scope(), g_direct_hash, g_direct_equal);
register_init_routine(genl_init);
}
void
proto_reg_handoff_netlink_generic(void)
{
dissector_add_string("genl.family", GENL_CTRL_NAME, netlink_generic_ctrl);
dissector_add_uint("netlink.protocol", WS_NETLINK_GENERIC, netlink_generic);
}
