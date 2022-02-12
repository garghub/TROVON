int
mapi_dissect_element_EcDoRpc_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = mapi_dissect_element_EcDoRpc_response_(tvb, offset, pinfo, tree, di, drep);
return offset;
}
static int
mapi_dissect_element_EcDoRpc_response_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 size;
int start_offset = offset;
guint8 *decrypted_data;
tvbuff_t *decrypted_tvb;
const guint8 *ptr;
gint reported_len;
guint16 pdu_len;
guint32 i;
proto_tree *tr = NULL;
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_mapi_EcDoRpc_mapi_response, &size);
proto_tree_add_uint(tree, hf_mapi_EcDoRpc_subcontext_size, tvb, start_offset, offset - start_offset + size, size);
reported_len = tvb_reported_length_remaining(tvb, offset);
if ((guint32) reported_len > size) {
reported_len = size;
}
if (size > (guint32) reported_len) {
size = reported_len;
}
ptr = tvb_get_ptr(tvb, offset, size);
decrypted_data = (guint8 *)g_malloc(size);
for (i = 0; i < size; i++) {
decrypted_data[i] = ptr[i] ^ 0xA5;
}
decrypted_tvb = tvb_new_child_real_data(tvb, decrypted_data, size, reported_len);
tvb_set_free_cb(decrypted_tvb, g_free);
add_new_data_source(pinfo, decrypted_tvb, "Decrypted MAPI");
tr = proto_tree_add_subtree(tree, decrypted_tvb, 0, size, ett_mapi_mapi_response, NULL, "Decrypted MAPI PDU");
pdu_len = tvb_get_letohs(decrypted_tvb, 0);
proto_tree_add_uint(tr, hf_mapi_pdu_len, decrypted_tvb, 0, 2, pdu_len);
proto_tree_add_item(tr, hf_mapi_decrypted_data, decrypted_tvb, 2, pdu_len - 2, ENC_NA);
offset = mapi_dissect_element_EcDoRpc_response__(decrypted_tvb, 0, pinfo, tr, di, drep);
offset = mapi_dissect_element_request_handles_cnf(decrypted_tvb, offset, pinfo, tr, di, drep);
return start_offset + offset + 4;
}
static int
mapi_dissect_element_EcDoRpc_response__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint16 length;
tvbuff_t *subtvb;
length = tvb_get_letohs(tvb, offset);
subtvb = tvb_new_subset(tvb, offset, length, length);
offset += 2;
while (offset < length) {
offset = mapi_dissect_struct_EcDoRpc_MAPI_REPL(subtvb, offset, pinfo, tree, di, drep, hf_mapi_mapi_response_mapi_repl, length - offset);
}
return offset;
}
static int
mapi_dissect_element_EcDoRpc_MAPI_REPL_UNION_OpenFolder(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
int origin_offset;
origin_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_mapi_EcDoRpc_MAPI_REPL_UNION_mapi_OpenFolder, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mapi_OpenFolder_repl);
}
old_offset = offset;
proto_tree_add_item(tree, hf_mapi_EcDoRpc_unknown1, tvb, old_offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_item_set_len(item, offset - origin_offset);
return offset;
}
static int
mapi_dissect_element_EcDoRpc_MAPI_REPL_UNION_GetProps(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int origin_offset;
guint16 length;
origin_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_mapi_EcDoRpc_MAPI_REPL_UNION_mapi_GetProps, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mapi_GetProps_repl);
}
proto_tree_add_item(tree, hf_mapi_EcDoRpc_layout, tvb, offset, 1, ENC_NA);
offset += 1;
length = tvb_reported_length_remaining(tvb, offset);
proto_tree_add_uint(tree, hf_mapi_EcDoRpc_prop_count, tvb, offset, 0, length);
offset += length;
proto_item_set_len(item, offset - origin_offset);
return offset;
}
