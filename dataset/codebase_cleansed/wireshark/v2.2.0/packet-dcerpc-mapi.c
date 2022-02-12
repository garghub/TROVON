static int
cnf_dissect_hyper(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, dcerpc_info* di, guint8 *drep, guint32 param _U_, int hfindex)
{
offset = dissect_ndr_uint64(tvb, offset, pinfo, tree, di, drep, hfindex, NULL);
return offset;
}
static int mapi_dissect_element_request_handles_cnf(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
gint reported_len;
gint i;
gint handles_cnt = 0;
guint32 value;
proto_tree *tr = NULL;
reported_len = tvb_reported_length_remaining(tvb, offset);
handles_cnt = reported_len / 4;
tr = proto_tree_add_subtree_format(tree, tvb, offset, reported_len, ett_mapi_mapi_request, NULL, "MAPI Handles: %d", handles_cnt);
for (i = 0; i < handles_cnt; i++) {
value = tvb_get_letohl(tvb, offset);
proto_tree_add_uint_format(tr, hf_mapi_MAPI_handle, tvb, offset, 4, value, "[%.2d] MAPI handle: 0x%.8x", i, value);
offset += 4;
}
return offset;
}
static int
mapi_dissect_struct_EcDoRpc_MAPI_REQ(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
guint8 opnum;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_mapi_EcDoRpc_MAPI_REQ);
}
opnum = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_mapi_MAPI_OPNUM, tvb, offset, 1, ENC_NA);
offset += 1;
col_append_fstr(pinfo->cinfo, COL_INFO, " + %s", val_to_str(opnum, mapi_MAPI_OPNUM_vals, "Unknown MAPI operation"));
proto_tree_add_item(tree, hf_mapi_EcDoRpc_mapi_flags, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_mapi_EcDoRpc_handle_index, tvb, offset, 1, ENC_NA);
offset += 1;
switch(opnum) {
case op_MAPI_Release:
offset = mapi_dissect_element_EcDoRpc_MAPI_REQ_UNION_Release(tvb, offset, pinfo, tree, di, drep);
break;
case op_MAPI_OpenFolder:
offset = mapi_dissect_element_EcDoRpc_MAPI_REQ_UNION_OpenFolder(tvb, offset, pinfo, tree, di, drep);
break;
case op_MAPI_GetProps:
offset = mapi_dissect_element_EcDoRpc_MAPI_REQ_UNION_GetProps(tvb, offset, pinfo, tree, di, drep);
break;
case op_MAPI_OpenMsgStore:
offset = mapi_dissect_element_EcDoRpc_MAPI_REQ_UNION_OpenMsgStore(tvb, offset, pinfo, tree, di, drep);
break;
default:
offset += param - 3;
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
mapi_dissect_element_EcDoRpc_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = mapi_dissect_element_EcDoRpc_request_(tvb, offset, pinfo, tree, di, drep);
return offset;
}
static int
mapi_dissect_element_EcDoRpc_request_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
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
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_mapi_EcDoRpc_mapi_request, &size);
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
tr = proto_tree_add_subtree(tree, decrypted_tvb, 0, size, ett_mapi_mapi_request, NULL, "Decrypted MAPI PDU");
pdu_len = tvb_get_letohs(decrypted_tvb, 0);
proto_tree_add_uint(tr, hf_mapi_pdu_len, decrypted_tvb, 0, 2, pdu_len);
proto_tree_add_item(tr, hf_mapi_decrypted_data, decrypted_tvb, 2, pdu_len - 2, ENC_NA);
offset = mapi_dissect_element_EcDoRpc_request__(decrypted_tvb, 0, pinfo, tr, di, drep);
offset = mapi_dissect_element_request_handles_cnf(decrypted_tvb, offset, pinfo, tr, di, drep);
return start_offset + offset + 4;
}
static int mapi_dissect_element_EcDoRpc_request__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint16 length;
length = tvb_get_letohs(tvb, offset);
offset += 2;
while (offset < length) {
offset = mapi_dissect_struct_EcDoRpc_MAPI_REQ(tvb, offset, pinfo, tree, di, drep, hf_mapi_mapi_request_mapi_req, length - offset);
}
return offset;
}
static int
mapi_dissect_element_EcDoRpc_MAPI_REQ_UNION_OpenFolder(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int origin_offset;
origin_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_mapi_EcDoRpc_MAPI_REQ_UNION_mapi_OpenFolder, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mapi_OpenFolder_req);
}
proto_tree_add_item(tree, hf_mapi_EcDoRpc_handle_index, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_mapi_EcDoRpc_folder_id, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_mapi_EcDoRpc_unknown2, tvb, offset, 1, ENC_NA);
offset += 1;
proto_item_set_len(item, offset - origin_offset);
return offset;
}
static int
mapi_dissect_element_EcDoRpc_MAPI_REQ_UNION_GetProps(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int origin_offset;
guint16 i;
guint16 prop_count;
guint32 mapitag;
origin_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_mapi_EcDoRpc_MAPI_REQ_UNION_mapi_GetProps, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mapi_GetProps_req);
}
proto_tree_add_item(tree, hf_mapi_EcDoRpc_unknown3, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
prop_count = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_mapi_EcDoRpc_prop_count, tvb, offset, 2, prop_count);
offset += 2;
for (i = 0; i < prop_count; i++) {
mapitag = tvb_get_letohl(tvb, offset);
proto_tree_add_uint_format(tree, hf_mapi_EcDoRpc_mapi_tag, tvb, offset, 4, mapitag, "[%.2d] %s", i, val_to_str(mapitag, mapi_MAPITAGS_vals, "Unknown MAPITAGS"));
offset += 4;
}
proto_item_set_len(item, offset - origin_offset);
return offset;
}
static int
mapi_dissect_element_EcDoRpc_MAPI_REQ_UNION_OpenMsgStore(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int origin_offset;
guint16 str_len;
origin_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_mapi_EcDoRpc_MAPI_REQ_UNION_mapi_OpenMsgStore, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mapi_OpenMsgStore_req);
}
proto_tree_add_item(tree, hf_mapi_EcDoRpc_codepage, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mapi_EcDoRpc_padding, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mapi_EcDoRpc_row, tvb, offset, 1, ENC_NA);
offset += 1;
str_len = tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_mapi_EcDoRpc_str_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mapi_EcDoRpc_mailbox, tvb, offset, str_len, ENC_ASCII|ENC_NA);
offset += str_len;
proto_item_set_len(item, offset - origin_offset);
return offset;
}
static int
mapi_dissect_struct_EcDoRpc_MAPI_REPL(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
guint8 opnum;
guint32 retval;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mapi_EcDoRpc_MAPI_REPL);
}
opnum = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_mapi_MAPI_OPNUM, tvb, offset, 1, ENC_NA);
offset += 1;
col_append_fstr(pinfo->cinfo, COL_INFO, " + %s", val_to_str(opnum, mapi_MAPI_OPNUM_vals, "Unknown MAPI operation: 0x%02x"));
if (opnum != op_MAPI_Notify) {
proto_tree_add_item(tree, hf_mapi_EcDoRpc_handle_index, tvb, offset, 1, ENC_NA);
offset += 1;
retval = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_mapi_MAPISTATUS_status, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (retval == MAPI_E_SUCCESS) {
switch(opnum) {
case op_MAPI_Release:
offset = mapi_dissect_element_EcDoRpc_MAPI_REPL_UNION_Release(tvb, offset, pinfo, tree, di, drep);
break;
case op_MAPI_OpenFolder:
offset = mapi_dissect_element_EcDoRpc_MAPI_REPL_UNION_OpenFolder(tvb, offset, pinfo, tree, di, drep);
break;
case op_MAPI_GetProps:
offset = mapi_dissect_element_EcDoRpc_MAPI_REPL_UNION_GetProps(tvb, offset, pinfo, tree, di, drep);
break;
default:
offset += param - 6;
}
}
} else {
offset += param - 1;
}
proto_item_set_len(item, offset - old_offset);
return offset;
}
static int
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
int
mapi_dissect_enum_MAPITAGS(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
{
guint32 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
int
mapi_dissect_enum_MAPISTATUS(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
{
guint32 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
static int
mapi_dissect_element_DATA_BLOB_data(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, mapi_dissect_element_DATA_BLOB_data_, NDR_POINTER_UNIQUE, "Pointer to Data (uint8)",hf_mapi_DATA_BLOB_data);
return offset;
}
static int
mapi_dissect_element_DATA_BLOB_data_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_mapi_DATA_BLOB_data, 0);
return offset;
}
static int
mapi_dissect_element_DATA_BLOB_length(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_mapi_DATA_BLOB_length, 0);
return offset;
}
int
mapi_dissect_struct_DATA_BLOB(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mapi_DATA_BLOB);
}
offset = mapi_dissect_element_DATA_BLOB_data(tvb, offset, pinfo, tree, di, drep);
offset = mapi_dissect_element_DATA_BLOB_length(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
static int
mapi_dissect_element_input_locale_language(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mapi_input_locale_language, 0);
return offset;
}
static int
mapi_dissect_element_input_locale_method(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mapi_input_locale_method, 0);
return offset;
}
int
mapi_dissect_struct_input_locale(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mapi_input_locale);
}
offset = mapi_dissect_element_input_locale_language(tvb, offset, pinfo, tree, di, drep);
offset = mapi_dissect_element_input_locale_method(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
int
mapi_dissect_enum_MAPI_OBJTYPE(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint8 *param _U_)
{
guint8 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint8(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
int
mapi_dissect_enum_ACLRIGHTS(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
{
guint32 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
int
mapi_dissect_enum_MAPI_OPNUM(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint8 *param _U_)
{
guint8 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint8(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
static int
mapi_dissect_element_FILETIME_dwLowDateTime(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mapi_FILETIME_dwLowDateTime, 0);
return offset;
}
static int
mapi_dissect_element_FILETIME_dwHighDateTime(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mapi_FILETIME_dwHighDateTime, 0);
return offset;
}
int
mapi_dissect_struct_FILETIME(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mapi_FILETIME);
}
offset = mapi_dissect_element_FILETIME_dwLowDateTime(tvb, offset, pinfo, tree, di, drep);
offset = mapi_dissect_element_FILETIME_dwHighDateTime(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
static int
mapi_dissect_element_LPSTR_lppszA(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_null_term_string(tvb, offset, pinfo, tree, drep, hf_mapi_LPSTR_lppszA , 0);
return offset;
}
int
mapi_dissect_struct_LPSTR(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mapi_LPSTR);
}
offset = mapi_dissect_element_LPSTR_lppszA(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
int
mapi_dissect_enum_property_types(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
{
guint32 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
static int
mapi_dissect_element_SPropValue_CTR_i(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_mapi_SPropValue_CTR_i, 0);
return offset;
}
static int
mapi_dissect_element_SPropValue_CTR_l(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mapi_SPropValue_CTR_l, 0);
return offset;
}
static int
mapi_dissect_element_SPropValue_CTR_dbl(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_duint32(tvb, offset, pinfo, tree, di, drep, hf_mapi_SPropValue_CTR_dbl, NULL);
return offset;
}
static int
mapi_dissect_element_SPropValue_CTR_err(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mapi_SPropValue_CTR_err, 0);
return offset;
}
static int
mapi_dissect_element_SPropValue_CTR_b(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_mapi_SPropValue_CTR_b, 0);
return offset;
}
static int
mapi_dissect_element_SPropValue_CTR_d(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_duint32(tvb, offset, pinfo, tree, di, drep, hf_mapi_SPropValue_CTR_d, NULL);
return offset;
}
static int
mapi_dissect_element_SPropValue_CTR_lpszA(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_null_term_string(tvb, offset, pinfo, tree, drep, hf_mapi_SPropValue_CTR_lpszA , 0);
return offset;
}
static int
mapi_dissect_element_SPropValue_CTR_lpszW(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_null_term_wstring(tvb, offset, pinfo, tree, drep, hf_mapi_SPropValue_CTR_lpszW , 0);
return offset;
}
static int
mapi_dissect_element_SPropValue_CTR_ft(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = mapi_dissect_struct_FILETIME(tvb,offset,pinfo,tree,di,drep,hf_mapi_SPropValue_CTR_ft,0);
return offset;
}
static int
mapi_dissect_element_SPropValue_CTR_lpguid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uuid_t(tvb, offset, pinfo, tree, di, drep, hf_mapi_SPropValue_CTR_lpguid, NULL);
return offset;
}
static int
mapi_dissect_SPropValue_CTR(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
guint32 level;
old_offset = offset;
if (parent_tree) {
tree = proto_tree_add_subtree(parent_tree, tvb, offset, -1, ett_mapi_SPropValue_CTR, &item, "SPropValue_CTR");
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_index, &level);
ALIGN_TO_4_BYTES;
switch(level) {
case PT_I2:
offset = mapi_dissect_element_SPropValue_CTR_i(tvb, offset, pinfo, tree, di, drep);
break;
case PT_LONG:
offset = mapi_dissect_element_SPropValue_CTR_l(tvb, offset, pinfo, tree, di, drep);
break;
case PT_DOUBLE:
offset = mapi_dissect_element_SPropValue_CTR_dbl(tvb, offset, pinfo, tree, di, drep);
break;
case PT_ERROR:
offset = mapi_dissect_element_SPropValue_CTR_err(tvb, offset, pinfo, tree, di, drep);
break;
case PT_BOOLEAN:
offset = mapi_dissect_element_SPropValue_CTR_b(tvb, offset, pinfo, tree, di, drep);
break;
case PT_I8:
offset = mapi_dissect_element_SPropValue_CTR_d(tvb, offset, pinfo, tree, di, drep);
break;
case PT_STRING8:
offset = mapi_dissect_element_SPropValue_CTR_lpszA(tvb, offset, pinfo, tree, di, drep);
break;
case PT_UNICODE:
offset = mapi_dissect_element_SPropValue_CTR_lpszW(tvb, offset, pinfo, tree, di, drep);
break;
case PT_SYSTIME:
offset = mapi_dissect_element_SPropValue_CTR_ft(tvb, offset, pinfo, tree, di, drep);
break;
case PT_CLSID:
offset = mapi_dissect_element_SPropValue_CTR_lpguid(tvb, offset, pinfo, tree, di, drep);
break;
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
mapi_dissect_element_SPropValue_ulPropTag(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = mapi_dissect_enum_MAPITAGS(tvb, offset, pinfo, tree, di, drep, hf_mapi_SPropValue_ulPropTag, 0);
return offset;
}
static int
mapi_dissect_element_SPropValue_value(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = mapi_dissect_SPropValue_CTR(tvb, offset, pinfo, tree, di, drep, hf_mapi_property_types, 0);
return offset;
}
int
mapi_dissect_struct_SPropValue(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
gboolean oldalign = di->no_align;
int old_offset;
di->no_align = TRUE;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mapi_SPropValue);
}
offset = mapi_dissect_element_SPropValue_ulPropTag(tvb, offset, pinfo, tree, di, drep);
offset = mapi_dissect_element_SPropValue_value(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
di->no_align = oldalign;
return offset;
}
int
mapi_dissect_enum_ulRowFlags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint8 *param _U_)
{
guint8 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint8(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
static int
mapi_dissect_element_SRow_ulRowFlags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = mapi_dissect_enum_ulRowFlags(tvb, offset, pinfo, tree, di, drep, hf_mapi_SRow_ulRowFlags, 0);
return offset;
}
int
mapi_dissect_struct_SRow(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
gboolean oldalign = di->no_align;
int old_offset;
di->no_align = TRUE;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mapi_SRow);
}
offset = mapi_dissect_element_SRow_ulRowFlags(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
di->no_align = oldalign;
return offset;
}
int
mapi_dissect_struct_Release_req(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
gboolean oldalign = di->no_align;
int old_offset;
di->no_align = TRUE;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
}
proto_item_set_len(item, offset-old_offset);
di->no_align = oldalign;
return offset;
}
int
mapi_dissect_struct_Release_repl(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
gboolean oldalign = di->no_align;
int old_offset;
di->no_align = TRUE;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
}
proto_item_set_len(item, offset-old_offset);
di->no_align = oldalign;
return offset;
}
static int
mapi_dissect_element_OpenMessage_req_folder_handle_idx(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_mapi_OpenMessage_req_folder_handle_idx, 0);
return offset;
}
static int
mapi_dissect_element_OpenMessage_req_max_data(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_mapi_OpenMessage_req_max_data, 0);
return offset;
}
static int
mapi_dissect_element_OpenMessage_req_folder_id(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset=cnf_dissect_hyper(tvb, offset, pinfo, tree, di, drep, 0, hf_mapi_OpenMessage_req_folder_id);
return offset;
}
static int
mapi_dissect_element_OpenMessage_req_message_permissions(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_mapi_OpenMessage_req_message_permissions, 0);
return offset;
}
static int
mapi_dissect_element_OpenMessage_req_message_id(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset=cnf_dissect_hyper(tvb, offset, pinfo, tree, di, drep, 0, hf_mapi_OpenMessage_req_message_id);
return offset;
}
int
mapi_dissect_struct_OpenMessage_req(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
gboolean oldalign = di->no_align;
int old_offset;
di->no_align = TRUE;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mapi_OpenMessage_req);
}
offset = mapi_dissect_element_OpenMessage_req_folder_handle_idx(tvb, offset, pinfo, tree, di, drep);
offset = mapi_dissect_element_OpenMessage_req_max_data(tvb, offset, pinfo, tree, di, drep);
offset = mapi_dissect_element_OpenMessage_req_folder_id(tvb, offset, pinfo, tree, di, drep);
offset = mapi_dissect_element_OpenMessage_req_message_permissions(tvb, offset, pinfo, tree, di, drep);
offset = mapi_dissect_element_OpenMessage_req_message_id(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
di->no_align = oldalign;
return offset;
}
int
mapi_dissect_enum_CODEPAGEID(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
{
guint32 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
int
mapi_dissect_enum_ulRecipClass(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint8 *param _U_)
{
guint8 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint8(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
int
mapi_dissect_enum_addr_type(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint8 *param _U_)
{
guint8 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint8(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
static int
mapi_dissect_element_RecipExchange_organization_length(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_mapi_RecipExchange_organization_length, 0);
return offset;
}
static int
mapi_dissect_element_RecipExchange_addr_type(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = mapi_dissect_enum_addr_type(tvb, offset, pinfo, tree, di, drep, hf_mapi_RecipExchange_addr_type, 0);
return offset;
}
int
mapi_dissect_struct_RecipExchange(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
gboolean oldalign = di->no_align;
int old_offset;
di->no_align = TRUE;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mapi_RecipExchange);
}
offset = mapi_dissect_element_RecipExchange_organization_length(tvb, offset, pinfo, tree, di, drep);
offset = mapi_dissect_element_RecipExchange_addr_type(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
di->no_align = oldalign;
return offset;
}
int
mapi_dissect_struct_RecipSMTP(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
gboolean oldalign = di->no_align;
int old_offset;
di->no_align = TRUE;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
}
proto_item_set_len(item, offset-old_offset);
di->no_align = oldalign;
return offset;
}
int
mapi_dissect_enum_OM_recipient_type(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint16 *param _U_)
{
guint16 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
static int
mapi_dissect_element_recipient_type_EXCHANGE(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = mapi_dissect_struct_RecipExchange(tvb,offset,pinfo,tree,di,drep,hf_mapi_recipient_type_EXCHANGE,0);
return offset;
}
static int
mapi_dissect_element_recipient_type_SMTP(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = mapi_dissect_struct_RecipSMTP(tvb,offset,pinfo,tree,di,drep,hf_mapi_recipient_type_SMTP,0);
return offset;
}
static int
mapi_dissect_recipient_type(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
guint16 level;
old_offset = offset;
if (parent_tree) {
tree = proto_tree_add_subtree(parent_tree, tvb, offset, -1, ett_mapi_recipient_type, &item, "recipient_type");
}
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, di, drep, hf_index, &level);
switch(level) {
case 0x0:
offset = mapi_dissect_element_recipient_type_EXCHANGE(tvb, offset, pinfo, tree, di, drep);
break;
case 0xA:
offset = mapi_dissect_element_recipient_type_SMTP(tvb, offset, pinfo, tree, di, drep);
break;
default:
break;
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
int
mapi_dissect_enum_OM_recipient_displayname_7bit(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint16 *param _U_)
{
guint16 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
static int
mapi_dissect_element_recipient_displayname_7bit_lpszA(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_null_term_string(tvb, offset, pinfo, tree, drep, hf_mapi_recipient_displayname_7bit_lpszA , 0);
return offset;
}
static int
mapi_dissect_recipient_displayname_7bit(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
guint16 level;
old_offset = offset;
if (parent_tree) {
tree = proto_tree_add_subtree(parent_tree, tvb, offset, -1, ett_mapi_recipient_displayname_7bit, &item, "recipient_displayname_7bit");
}
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, di, drep, hf_index, &level);
ALIGN_TO_4_BYTES;
switch(level) {
case 0x400:
offset = mapi_dissect_element_recipient_displayname_7bit_lpszA(tvb, offset, pinfo, tree, di, drep);
break;
default:
break;
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
mapi_dissect_element_recipients_headers_bitmask(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_mapi_recipients_headers_bitmask, 0);
return offset;
}
static int
mapi_dissect_element_recipients_headers_type(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = mapi_dissect_recipient_type(tvb, offset, pinfo, tree, di, drep, hf_mapi_recipient_type, 0);
return offset;
}
static int
mapi_dissect_element_recipients_headers_username(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = mapi_dissect_recipient_displayname_7bit(tvb, offset, pinfo, tree, di, drep, hf_mapi_recipients_headers_username, 0);
return offset;
}
static int
mapi_dissect_element_recipients_headers_prop_count(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_mapi_recipients_headers_prop_count, 0);
return offset;
}
static int
mapi_dissect_element_recipients_headers_layout(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_mapi_recipients_headers_layout, 0);
return offset;
}
static int
mapi_dissect_element_recipients_headers_prop_values(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_datablob(tvb, offset, pinfo, tree, di, drep, hf_mapi_recipients_headers_prop_values, 1);
return offset;
}
int
mapi_dissect_struct_recipients_headers(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
gboolean oldalign = di->no_align;
int old_offset;
di->no_align = TRUE;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mapi_recipients_headers);
}
offset = mapi_dissect_element_recipients_headers_bitmask(tvb, offset, pinfo, tree, di, drep);
offset = mapi_dissect_element_recipients_headers_type(tvb, offset, pinfo, tree, di, drep);
offset = mapi_dissect_element_recipients_headers_username(tvb, offset, pinfo, tree, di, drep);
offset = mapi_dissect_element_recipients_headers_prop_count(tvb, offset, pinfo, tree, di, drep);
offset = mapi_dissect_element_recipients_headers_layout(tvb, offset, pinfo, tree, di, drep);
offset = mapi_dissect_element_recipients_headers_prop_values(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
di->no_align = oldalign;
return offset;
}
static int
mapi_dissect_element_OpenMessage_recipients_RecipClass(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = mapi_dissect_enum_ulRecipClass(tvb, offset, pinfo, tree, di, drep, hf_mapi_OpenMessage_recipients_RecipClass, 0);
return offset;
}
static int
mapi_dissect_element_OpenMessage_recipients_codepage(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = mapi_dissect_enum_CODEPAGEID(tvb, offset, pinfo, tree, di, drep, hf_mapi_OpenMessage_recipients_codepage, 0);
return offset;
}
static int
mapi_dissect_element_OpenMessage_recipients_recipients_headers(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint16 size;
int conformant = di->conformant_run;
tvbuff_t *subtvb;
if (!conformant) {
guint32 saved_flags = di->call_data->flags;
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, di, drep, hf_mapi_OpenMessage_recipients_recipients_headers_, &size);
di->call_data->flags &= ~DCERPC_IS_NDR64;
subtvb = tvb_new_subset(tvb, offset, (const gint)size, -1);
mapi_dissect_element_OpenMessage_recipients_recipients_headers_(subtvb, 0, pinfo, tree, di, drep);
offset += (int)size;
di->call_data->flags = saved_flags;
}
return offset;
}
static int
mapi_dissect_element_OpenMessage_recipients_recipients_headers_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = mapi_dissect_struct_recipients_headers(tvb,offset,pinfo,tree,di,drep,hf_mapi_OpenMessage_recipients_recipients_headers,0);
return offset;
}
int
mapi_dissect_struct_OpenMessage_recipients(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
gboolean oldalign = di->no_align;
int old_offset;
di->no_align = TRUE;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mapi_OpenMessage_recipients);
}
offset = mapi_dissect_element_OpenMessage_recipients_RecipClass(tvb, offset, pinfo, tree, di, drep);
offset = mapi_dissect_element_OpenMessage_recipients_codepage(tvb, offset, pinfo, tree, di, drep);
offset = mapi_dissect_element_OpenMessage_recipients_recipients_headers(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
di->no_align = oldalign;
return offset;
}
int
mapi_dissect_bitmap_ulEventType(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item;
static const int * mapi_ulEventType_fields[] = {
&hf_mapi_ulEventType_fnevCriticalError,
&hf_mapi_ulEventType_fnevNewMail,
&hf_mapi_ulEventType_fnevObjectCreated,
&hf_mapi_ulEventType_fnevObjectDeleted,
&hf_mapi_ulEventType_fnevObjectModified,
&hf_mapi_ulEventType_fnevObjectMoved,
&hf_mapi_ulEventType_fnevObjectCopied,
&hf_mapi_ulEventType_fnevSearchComplete,
&hf_mapi_ulEventType_fnevTableModified,
&hf_mapi_ulEventType_fnevStatusObjectModified,
&hf_mapi_ulEventType_fnevReservedForMapi,
&hf_mapi_ulEventType_fnevExtended,
NULL
};
guint16 flags;
ALIGN_TO_2_BYTES;
item = proto_tree_add_bitmask_with_flags(parent_tree, tvb, offset, hf_index,
ett_mapi_ulEventType, mapi_ulEventType_fields, DREP_ENC_INTEGER(drep), BMT_NO_FALSE);
offset = dissect_ndr_uint16(tvb, offset, pinfo, parent_tree, di, drep, -1, &flags);
if (!flags)
proto_item_append_text(item, ": (No values set)");
if (flags & (~0xc00003ff)) {
flags &= (~0xc00003ff);
proto_item_append_text(item, "Unknown bitmap value 0x%x", flags);
}
return offset;
}
static int
mapi_dissect_element_EcDoRpc_MAPI_REQ_UNION_Release(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = mapi_dissect_struct_Release_req(tvb,offset,pinfo,tree,di,drep,hf_mapi_EcDoRpc_MAPI_REQ_UNION_mapi_Release,0);
return offset;
}
static int
mapi_dissect_element_EcDoRpc_MAPI_REPL_UNION_Release(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = mapi_dissect_struct_Release_repl(tvb,offset,pinfo,tree,di,drep,hf_mapi_EcDoRpc_MAPI_REPL_UNION_mapi_Release,0);
return offset;
}
static int
mapi_dissect_element_EcDoConnect_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, mapi_dissect_element_EcDoConnect_handle_, NDR_POINTER_REF, "Pointer to Handle (policy_handle)",hf_mapi_handle);
return offset;
}
static int
mapi_dissect_element_EcDoConnect_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_mapi_handle, 0x0001);
return offset;
}
static int
mapi_dissect_element_EcDoConnect_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint8), hf_mapi_EcDoConnect_name, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
mapi_dissect_element_EcDoConnect_unknown1(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
int i;
for (i = 0; i < 3; i++)
offset = mapi_dissect_element_EcDoConnect_unknown1_(tvb, offset, pinfo, tree, di, drep);
return offset;
}
static int
mapi_dissect_element_EcDoConnect_unknown1_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mapi_EcDoConnect_unknown1, 0);
return offset;
}
static int
mapi_dissect_element_EcDoConnect_code_page(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mapi_EcDoConnect_code_page, 0);
return offset;
}
static int
mapi_dissect_element_EcDoConnect_input_locale(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = mapi_dissect_struct_input_locale(tvb,offset,pinfo,tree,di,drep,hf_mapi_EcDoConnect_input_locale,0);
return offset;
}
static int
mapi_dissect_element_EcDoConnect_unknown2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mapi_EcDoConnect_unknown2, 0);
return offset;
}
static int
mapi_dissect_element_EcDoConnect_unknown3(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_mapi_EcDoConnect_unknown3, 0);
return offset;
}
static int
mapi_dissect_element_EcDoConnect_unknown4(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
int i;
for (i = 0; i < 3; i++)
offset = mapi_dissect_element_EcDoConnect_unknown4_(tvb, offset, pinfo, tree, di, drep);
return offset;
}
static int
mapi_dissect_element_EcDoConnect_unknown4_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mapi_EcDoConnect_unknown4, 0);
return offset;
}
static int
mapi_dissect_element_EcDoConnect_session_nb(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, mapi_dissect_element_EcDoConnect_session_nb_, NDR_POINTER_REF, "Pointer to Session Nb (uint16)",hf_mapi_EcDoConnect_session_nb);
return offset;
}
static int
mapi_dissect_element_EcDoConnect_session_nb_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_mapi_EcDoConnect_session_nb, 0);
return offset;
}
static int
mapi_dissect_element_EcDoConnect_org_group(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, mapi_dissect_element_EcDoConnect_org_group_, NDR_POINTER_UNIQUE, "Pointer to Org Group (uint8)",hf_mapi_EcDoConnect_org_group);
return offset;
}
static int
mapi_dissect_element_EcDoConnect_org_group_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint8), hf_mapi_EcDoConnect_org_group, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
mapi_dissect_element_EcDoConnect_user(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, mapi_dissect_element_EcDoConnect_user_, NDR_POINTER_UNIQUE, "Pointer to User (uint8)",hf_mapi_EcDoConnect_user);
return offset;
}
static int
mapi_dissect_element_EcDoConnect_user_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint8), hf_mapi_EcDoConnect_user, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
mapi_dissect_element_EcDoConnect_store_version(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
int i;
for (i = 0; i < 3; i++)
offset = mapi_dissect_element_EcDoConnect_store_version_(tvb, offset, pinfo, tree, di, drep);
return offset;
}
static int
mapi_dissect_element_EcDoConnect_store_version_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_mapi_EcDoConnect_store_version, 0);
return offset;
}
static int
mapi_dissect_element_EcDoConnect_emsmdb_client_version(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
int i;
for (i = 0; i < 3; i++)
offset = mapi_dissect_element_EcDoConnect_emsmdb_client_version_(tvb, offset, pinfo, tree, di, drep);
return offset;
}
static int
mapi_dissect_element_EcDoConnect_emsmdb_client_version_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_mapi_EcDoConnect_emsmdb_client_version, 0);
return offset;
}
static int
mapi_dissect_element_EcDoConnect_alloc_space(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, mapi_dissect_element_EcDoConnect_alloc_space_, NDR_POINTER_REF, "Pointer to Alloc Space (uint32)",hf_mapi_EcDoConnect_alloc_space);
return offset;
}
static int
mapi_dissect_element_EcDoConnect_alloc_space_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mapi_EcDoConnect_alloc_space, 0);
return offset;
}
static int
mapi_dissect_EcDoConnect_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="EcDoConnect";
offset = mapi_dissect_element_EcDoConnect_handle(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mapi_dissect_element_EcDoConnect_unknown4(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mapi_dissect_element_EcDoConnect_session_nb(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mapi_dissect_element_EcDoConnect_org_group(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mapi_dissect_element_EcDoConnect_user(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mapi_dissect_element_EcDoConnect_store_version(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mapi_dissect_element_EcDoConnect_emsmdb_client_version(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mapi_dissect_element_EcDoConnect_alloc_space(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_mapi_MAPISTATUS_status, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Status: %s", val_to_str(status, mapi_MAPISTATUS_vals, "Unknown MAPISTATUS error 0x%08x"));
return offset;
}
static int
mapi_dissect_EcDoConnect_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="EcDoConnect";
offset = mapi_dissect_element_EcDoConnect_name(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mapi_dissect_element_EcDoConnect_unknown1(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mapi_dissect_element_EcDoConnect_code_page(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mapi_dissect_element_EcDoConnect_input_locale(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mapi_dissect_element_EcDoConnect_unknown2(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mapi_dissect_element_EcDoConnect_unknown3(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mapi_dissect_element_EcDoConnect_emsmdb_client_version(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mapi_dissect_element_EcDoConnect_alloc_space(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
mapi_dissect_element_EcDoDisconnect_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, mapi_dissect_element_EcDoDisconnect_handle_, NDR_POINTER_REF, "Pointer to Handle (policy_handle)",hf_mapi_handle);
return offset;
}
static int
mapi_dissect_element_EcDoDisconnect_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_mapi_handle, 0x0002);
return offset;
}
static int
mapi_dissect_EcDoDisconnect_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="EcDoDisconnect";
offset = mapi_dissect_element_EcDoDisconnect_handle(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_mapi_MAPISTATUS_status, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Status: %s", val_to_str(status, mapi_MAPISTATUS_vals, "Unknown MAPISTATUS error 0x%08x"));
return offset;
}
static int
mapi_dissect_EcDoDisconnect_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="EcDoDisconnect";
offset = mapi_dissect_element_EcDoDisconnect_handle(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
mapi_dissect_element_EcDoRpc_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, mapi_dissect_element_EcDoRpc_handle_, NDR_POINTER_REF, "Pointer to Handle (policy_handle)",hf_mapi_handle);
return offset;
}
static int
mapi_dissect_element_EcDoRpc_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_mapi_handle, 0);
return offset;
}
static int
mapi_dissect_element_EcDoRpc_size(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mapi_EcDoRpc_size, 0);
return offset;
}
static int
mapi_dissect_element_EcDoRpc_offset(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mapi_EcDoRpc_offset, 0);
return offset;
}
static int
mapi_dissect_element_EcDoRpc_length(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, mapi_dissect_element_EcDoRpc_length_, NDR_POINTER_REF, "Pointer to Length (uint16)",hf_mapi_EcDoRpc_length);
return offset;
}
static int
mapi_dissect_element_EcDoRpc_length_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_mapi_EcDoRpc_length, 0);
return offset;
}
static int
mapi_dissect_element_EcDoRpc_max_data(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_mapi_EcDoRpc_max_data, 0);
return offset;
}
static int
mapi_dissect_EcDoRpc_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="EcDoRpc";
offset = mapi_dissect_element_EcDoRpc_handle(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mapi_dissect_element_EcDoRpc_size(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mapi_dissect_element_EcDoRpc_offset(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mapi_dissect_element_EcDoRpc_response(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mapi_dissect_element_EcDoRpc_length(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_mapi_MAPISTATUS_status, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Status: %s", val_to_str(status, mapi_MAPISTATUS_vals, "Unknown MAPISTATUS error 0x%08x"));
return offset;
}
static int
mapi_dissect_EcDoRpc_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="EcDoRpc";
offset = mapi_dissect_element_EcDoRpc_handle(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mapi_dissect_element_EcDoRpc_size(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mapi_dissect_element_EcDoRpc_offset(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mapi_dissect_element_EcDoRpc_request(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mapi_dissect_element_EcDoRpc_length(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mapi_dissect_element_EcDoRpc_max_data(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
mapi_dissect_EcGetMoreRpc_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="EcGetMoreRpc";
return offset;
}
static int
mapi_dissect_EcGetMoreRpc_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="EcGetMoreRpc";
return offset;
}
static int
mapi_dissect_element_EcRRegisterPushNotification_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, mapi_dissect_element_EcRRegisterPushNotification_handle_, NDR_POINTER_REF, "Pointer to Handle (policy_handle)",hf_mapi_handle);
return offset;
}
static int
mapi_dissect_element_EcRRegisterPushNotification_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_mapi_handle, 0);
return offset;
}
static int
mapi_dissect_element_EcRRegisterPushNotification_ulEventMask(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = mapi_dissect_bitmap_ulEventType(tvb, offset, pinfo, tree, di, drep, hf_mapi_EcRRegisterPushNotification_ulEventMask, 0);
return offset;
}
static int
mapi_dissect_element_EcRRegisterPushNotification_notifkey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, mapi_dissect_element_EcRRegisterPushNotification_notifkey_);
return offset;
}
static int
mapi_dissect_element_EcRRegisterPushNotification_notifkey_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_mapi_EcRRegisterPushNotification_notifkey, 0);
return offset;
}
static int
mapi_dissect_element_EcRRegisterPushNotification_notif_len(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_mapi_EcRRegisterPushNotification_notif_len, 0);
return offset;
}
static int
mapi_dissect_element_EcRRegisterPushNotification_unknown2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mapi_EcRRegisterPushNotification_unknown2, 0);
return offset;
}
static int
mapi_dissect_element_EcRRegisterPushNotification_sockaddr(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, mapi_dissect_element_EcRRegisterPushNotification_sockaddr_);
return offset;
}
static int
mapi_dissect_element_EcRRegisterPushNotification_sockaddr_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_mapi_EcRRegisterPushNotification_sockaddr, 0);
return offset;
}
static int
mapi_dissect_element_EcRRegisterPushNotification_sockaddr_len(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_mapi_EcRRegisterPushNotification_sockaddr_len, 0);
return offset;
}
static int
mapi_dissect_element_EcRRegisterPushNotification_retval(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, mapi_dissect_element_EcRRegisterPushNotification_retval_, NDR_POINTER_REF, "Pointer to Retval (uint32)",hf_mapi_EcRRegisterPushNotification_retval);
return offset;
}
static int
mapi_dissect_element_EcRRegisterPushNotification_retval_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mapi_EcRRegisterPushNotification_retval, 0);
return offset;
}
static int
mapi_dissect_EcRRegisterPushNotification_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="EcRRegisterPushNotification";
offset = mapi_dissect_element_EcRRegisterPushNotification_handle(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mapi_dissect_element_EcRRegisterPushNotification_retval(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_mapi_MAPISTATUS_status, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Status: %s", val_to_str(status, mapi_MAPISTATUS_vals, "Unknown MAPISTATUS error 0x%08x"));
return offset;
}
static int
mapi_dissect_EcRRegisterPushNotification_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="EcRRegisterPushNotification";
offset = mapi_dissect_element_EcRRegisterPushNotification_handle(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mapi_dissect_element_EcRRegisterPushNotification_ulEventMask(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mapi_dissect_element_EcRRegisterPushNotification_notifkey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mapi_dissect_element_EcRRegisterPushNotification_notif_len(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mapi_dissect_element_EcRRegisterPushNotification_unknown2(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mapi_dissect_element_EcRRegisterPushNotification_sockaddr(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mapi_dissect_element_EcRRegisterPushNotification_sockaddr_len(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
mapi_dissect_element_EcRUnregisterPushNotification_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, mapi_dissect_element_EcRUnregisterPushNotification_handle_, NDR_POINTER_REF, "Pointer to Handle (policy_handle)",hf_mapi_handle);
return offset;
}
static int
mapi_dissect_element_EcRUnregisterPushNotification_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_mapi_handle, 0);
return offset;
}
static int
mapi_dissect_element_EcRUnregisterPushNotification_unknown(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
int i;
for (i = 0; i < 2; i++)
offset = mapi_dissect_element_EcRUnregisterPushNotification_unknown_(tvb, offset, pinfo, tree, di, drep);
return offset;
}
static int
mapi_dissect_element_EcRUnregisterPushNotification_unknown_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mapi_EcRUnregisterPushNotification_unknown, 0);
return offset;
}
static int
mapi_dissect_EcRUnregisterPushNotification_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="EcRUnregisterPushNotification";
offset = mapi_dissect_element_EcRUnregisterPushNotification_handle(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_mapi_MAPISTATUS_status, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Status: %s", val_to_str(status, mapi_MAPISTATUS_vals, "Unknown MAPISTATUS error 0x%08x"));
return offset;
}
static int
mapi_dissect_EcRUnregisterPushNotification_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="EcRUnregisterPushNotification";
offset = mapi_dissect_element_EcRUnregisterPushNotification_handle(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mapi_dissect_element_EcRUnregisterPushNotification_unknown(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
mapi_dissect_EcDummyRpc_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="EcDummyRpc";
return offset;
}
static int
mapi_dissect_EcDummyRpc_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="EcDummyRpc";
return offset;
}
static int
mapi_dissect_EcRGetDCName_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="EcRGetDCName";
return offset;
}
static int
mapi_dissect_EcRGetDCName_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="EcRGetDCName";
return offset;
}
static int
mapi_dissect_EcRNetGetDCName_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="EcRNetGetDCName";
return offset;
}
static int
mapi_dissect_EcRNetGetDCName_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="EcRNetGetDCName";
return offset;
}
static int
mapi_dissect_EcDoRpcExt_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="EcDoRpcExt";
return offset;
}
static int
mapi_dissect_EcDoRpcExt_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="EcDoRpcExt";
return offset;
}
void proto_register_dcerpc_mapi(void)
{
static hf_register_info hf[] = {
{ &hf_mapi_DATA_BLOB_data,
{ "Data", "mapi.DATA_BLOB.data", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_DATA_BLOB_length,
{ "Length", "mapi.DATA_BLOB.length", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcDoConnect_alloc_space,
{ "Alloc Space", "mapi.EcDoConnect.alloc_space", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcDoConnect_code_page,
{ "Code Page", "mapi.EcDoConnect.code_page", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcDoConnect_emsmdb_client_version,
{ "Emsmdb Client Version", "mapi.EcDoConnect.emsmdb_client_version", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcDoConnect_input_locale,
{ "Input Locale", "mapi.EcDoConnect.input_locale", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcDoConnect_name,
{ "Name", "mapi.EcDoConnect.name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcDoConnect_org_group,
{ "Org Group", "mapi.EcDoConnect.org_group", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcDoConnect_session_nb,
{ "Session Nb", "mapi.EcDoConnect.session_nb", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcDoConnect_store_version,
{ "Store Version", "mapi.EcDoConnect.store_version", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcDoConnect_unknown1,
{ "Unknown1", "mapi.EcDoConnect.unknown1", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcDoConnect_unknown2,
{ "Unknown2", "mapi.EcDoConnect.unknown2", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcDoConnect_unknown3,
{ "Unknown3", "mapi.EcDoConnect.unknown3", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcDoConnect_unknown4,
{ "Unknown4", "mapi.EcDoConnect.unknown4", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcDoConnect_user,
{ "User", "mapi.EcDoConnect.user", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcDoRpc_MAPI_REPL_UNION_mapi_GetProps,
{ "Mapi Getprops", "mapi.EcDoRpc_MAPI_REPL_UNION.mapi_GetProps", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcDoRpc_MAPI_REPL_UNION_mapi_OpenFolder,
{ "Mapi Openfolder", "mapi.EcDoRpc_MAPI_REPL_UNION.mapi_OpenFolder", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcDoRpc_MAPI_REPL_UNION_mapi_Release,
{ "Mapi Release", "mapi.EcDoRpc_MAPI_REPL_UNION.mapi_Release", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcDoRpc_MAPI_REQ_UNION_mapi_GetProps,
{ "Mapi Getprops", "mapi.EcDoRpc_MAPI_REQ_UNION.mapi_GetProps", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcDoRpc_MAPI_REQ_UNION_mapi_OpenFolder,
{ "Mapi Openfolder", "mapi.EcDoRpc_MAPI_REQ_UNION.mapi_OpenFolder", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcDoRpc_MAPI_REQ_UNION_mapi_OpenMsgStore,
{ "Mapi Openmsgstore", "mapi.EcDoRpc_MAPI_REQ_UNION.mapi_OpenMsgStore", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcDoRpc_MAPI_REQ_UNION_mapi_Release,
{ "Mapi Release", "mapi.EcDoRpc_MAPI_REQ_UNION.mapi_Release", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcDoRpc_codepage,
{ "Codepage", "mapi.EcDoRpc.codepage", FT_UINT32, BASE_HEX, NULL, 0, "NULL", HFILL }},
{ &hf_mapi_EcDoRpc_folder_id,
{ "Folder ID", "mapi.EcDoRpc.folder_id", FT_UINT64, BASE_HEX, NULL, 0, "NULL", HFILL }},
{ &hf_mapi_EcDoRpc_handle_index,
{ "Handle index", "mapi.EcDoRpc.handle_index", FT_UINT8, BASE_DEC, NULL, 0, "NULL", HFILL }},
{ &hf_mapi_EcDoRpc_layout,
{ "Layout", "mapi.EcDoRpc.layout", FT_UINT8, BASE_DEC, NULL, 0, "NULL", HFILL }},
{ &hf_mapi_EcDoRpc_length,
{ "Length", "mapi.EcDoRpc.length", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcDoRpc_mailbox,
{ "Mailbox", "mapi.EcDoRpc.mailbox", FT_STRING, BASE_NONE, NULL, 0, "NULL", HFILL }},
{ &hf_mapi_EcDoRpc_mapi_flags,
{ "mapi_flags", "mapi.EcDoRpc.mapi_flags", FT_UINT8, BASE_HEX, NULL, 0, "NULL", HFILL }},
{ &hf_mapi_EcDoRpc_mapi_request,
{ "Mapi Request", "mapi.EcDoRpc.mapi_request", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcDoRpc_mapi_request_,
{ "Subcontext length", "mapi.EcDoRpc.subcontext", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcDoRpc_mapi_response,
{ "Mapi Response", "mapi.EcDoRpc.mapi_response", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcDoRpc_mapi_response_,
{ "Subcontext length", "mapi.EcDoRpc.subcontext", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcDoRpc_mapi_tag,
{ "MAPI tag", "mapi.EcDoRpc.mapi_tag", FT_UINT32, BASE_HEX, NULL, 0, "NULL", HFILL }},
{ &hf_mapi_EcDoRpc_max_data,
{ "Max Data", "mapi.EcDoRpc.max_data", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcDoRpc_offset,
{ "Offset", "mapi.EcDoRpc.offset", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcDoRpc_padding,
{ "Padding", "mapi.EcDoRpc.padding", FT_UINT32, BASE_HEX, NULL, 0, "NULL", HFILL }},
{ &hf_mapi_EcDoRpc_prop_count,
{ "Prop count", "mapi.EcDoRpc.prop_count", FT_UINT16, BASE_HEX, NULL, 0, "NULL", HFILL }},
{ &hf_mapi_EcDoRpc_row,
{ "Row", "mapi.EcDoRpc.row", FT_UINT8, BASE_HEX, NULL, 0, "NULL", HFILL }},
{ &hf_mapi_EcDoRpc_size,
{ "Size", "mapi.EcDoRpc.size", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcDoRpc_str_length,
{ "Length", "mapi.EcDoRpc.str_length", FT_UINT16, BASE_HEX, NULL, 0, "NULL", HFILL }},
{ &hf_mapi_EcDoRpc_subcontext_size,
{ "Subcontext size", "mapi.EcDoRpc.subcontext_size", FT_UINT32, BASE_HEX, NULL, 0, "NULL", HFILL }},
{ &hf_mapi_EcDoRpc_unknown1,
{ "Unknown1", "mapi.EcDoRpc.unknown1", FT_UINT16, BASE_HEX, NULL, 0, "NULL", HFILL }},
{ &hf_mapi_EcDoRpc_unknown2,
{ "Unknown2", "mapi.EcDoRpc.unknown2", FT_UINT8, BASE_DEC, NULL, 0, "NULL", HFILL }},
{ &hf_mapi_EcDoRpc_unknown3,
{ "Unknown3", "mapi.EcDoRpc.unknown3", FT_UINT32, BASE_HEX, NULL, 0, "NULL", HFILL }},
{ &hf_mapi_EcRRegisterPushNotification_notif_len,
{ "Notif Len", "mapi.EcRRegisterPushNotification.notif_len", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcRRegisterPushNotification_notifkey,
{ "Notifkey", "mapi.EcRRegisterPushNotification.notifkey", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcRRegisterPushNotification_retval,
{ "Retval", "mapi.EcRRegisterPushNotification.retval", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcRRegisterPushNotification_sockaddr,
{ "Sockaddr", "mapi.EcRRegisterPushNotification.sockaddr", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcRRegisterPushNotification_sockaddr_len,
{ "Sockaddr Len", "mapi.EcRRegisterPushNotification.sockaddr_len", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcRRegisterPushNotification_ulEventMask,
{ "Uleventmask", "mapi.EcRRegisterPushNotification.ulEventMask", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcRRegisterPushNotification_unknown2,
{ "Unknown2", "mapi.EcRRegisterPushNotification.unknown2", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_EcRUnregisterPushNotification_unknown,
{ "Unknown", "mapi.EcRUnregisterPushNotification.unknown", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_FILETIME_dwHighDateTime,
{ "Dwhighdatetime", "mapi.FILETIME.dwHighDateTime", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_FILETIME_dwLowDateTime,
{ "Dwlowdatetime", "mapi.FILETIME.dwLowDateTime", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_LPSTR_lppszA,
{ "Lppsza", "mapi.LPSTR.lppszA", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mapi_MAPISTATUS_status,
{ "MAPISTATUS", "mapi.MAPISTATUS_status", FT_UINT32, BASE_HEX, VALS(mapi_MAPISTATUS_vals), 0, NULL, HFILL }},
{ &hf_mapi_MAPI_OPNUM,
{ "Opnum", "mapi.EcDoRpc_MAPI_REPL.opnum", FT_UINT8, BASE_HEX, VALS(mapi_MAPI_OPNUM_vals), 0, "NULL", HFILL }},
{ &hf_mapi_MAPI_handle,
{ "MAPI handle", "mapi.mapi_handle", FT_UINT32, BASE_HEX, NULL, 0, "NULL", HFILL }},
{ &hf_mapi_OpenMessage_recipients_RecipClass,
{ "Recipclass", "mapi.OpenMessage_recipients.RecipClass", FT_UINT8, BASE_DEC, VALS(mapi_ulRecipClass_vals), 0, NULL, HFILL }},
{ &hf_mapi_OpenMessage_recipients_codepage,
{ "Codepage", "mapi.OpenMessage_recipients.codepage", FT_UINT32, BASE_DEC, VALS(mapi_CODEPAGEID_vals), 0, NULL, HFILL }},
{ &hf_mapi_OpenMessage_recipients_recipients_headers,
{ "Recipients Headers", "mapi.OpenMessage_recipients.recipients_headers", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mapi_OpenMessage_recipients_recipients_headers_,
{ "Subcontext length", "mapi.OpenMessage_recipients.subcontext", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_mapi_OpenMessage_req_folder_handle_idx,
{ "Folder Handle Idx", "mapi.OpenMessage_req.folder_handle_idx", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_OpenMessage_req_folder_id,
{ "Folder Id", "mapi.OpenMessage_req.folder_id", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_OpenMessage_req_max_data,
{ "Max Data", "mapi.OpenMessage_req.max_data", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_OpenMessage_req_message_id,
{ "Message Id", "mapi.OpenMessage_req.message_id", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_OpenMessage_req_message_permissions,
{ "Message Permissions", "mapi.OpenMessage_req.message_permissions", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_RecipExchange_addr_type,
{ "Addr Type", "mapi.RecipExchange.addr_type", FT_UINT8, BASE_DEC, VALS(mapi_addr_type_vals), 0, NULL, HFILL }},
{ &hf_mapi_RecipExchange_organization_length,
{ "Organization Length", "mapi.RecipExchange.organization_length", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_SPropValue_CTR_b,
{ "B", "mapi.SPropValue_CTR.b", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_SPropValue_CTR_d,
{ "D", "mapi.SPropValue_CTR.d", FT_INT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_SPropValue_CTR_dbl,
{ "Dbl", "mapi.SPropValue_CTR.dbl", FT_INT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_SPropValue_CTR_err,
{ "Err", "mapi.SPropValue_CTR.err", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_SPropValue_CTR_ft,
{ "Ft", "mapi.SPropValue_CTR.ft", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mapi_SPropValue_CTR_i,
{ "I", "mapi.SPropValue_CTR.i", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_SPropValue_CTR_l,
{ "L", "mapi.SPropValue_CTR.l", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_SPropValue_CTR_lpguid,
{ "Lpguid", "mapi.SPropValue_CTR.lpguid", FT_GUID, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mapi_SPropValue_CTR_lpszA,
{ "Lpsza", "mapi.SPropValue_CTR.lpszA", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mapi_SPropValue_CTR_lpszW,
{ "Lpszw", "mapi.SPropValue_CTR.lpszW", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mapi_SPropValue_ulPropTag,
{ "Ulproptag", "mapi.SPropValue.ulPropTag", FT_UINT32, BASE_DEC, VALS(mapi_MAPITAGS_vals), 0, NULL, HFILL }},
{ &hf_mapi_SRow_ulRowFlags,
{ "Ulrowflags", "mapi.SRow.ulRowFlags", FT_UINT8, BASE_DEC, VALS(mapi_ulRowFlags_vals), 0, NULL, HFILL }},
{ &hf_mapi_decrypted_data,
{ "Decrypted data", "mapi.decrypted.data", FT_BYTES, BASE_NONE, NULL, 0, "NULL", HFILL }},
{ &hf_mapi_handle,
{ "Handle", "mapi.handle", FT_BYTES, BASE_NONE, NULL, 0, "NULL", HFILL }},
{ &hf_mapi_input_locale_language,
{ "Language", "mapi.input_locale.language", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_input_locale_method,
{ "Method", "mapi.input_locale.method", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_mapi_request_mapi_req,
{ "Mapi Req", "mapi.mapi_request.mapi_req", FT_NONE, BASE_NONE, NULL, 0, "HFILL", HFILL }},
{ &hf_mapi_mapi_response_mapi_repl,
{ "Mapi Repl", "mapi.mapi_response.mapi_repl", FT_NONE, BASE_NONE, NULL, 0, "NULL", HFILL }},
{ &hf_mapi_opnum,
{ "Operation", "mapi.opnum", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_pdu_len,
{ "Length", "mapi.pdu.len", FT_UINT16, BASE_HEX, NULL, 0x0, "Size of the command PDU", HFILL }},
{ &hf_mapi_property_types,
{ "Value", "mapi.SPropValue.value", FT_UINT32, BASE_HEX, VALS(mapi_property_types_vals), 0, "NULL", HFILL }},
{ &hf_mapi_recipient_displayname_7bit_lpszA,
{ "Lpsza", "mapi.recipient_displayname_7bit.lpszA", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mapi_recipient_type,
{ "Recipient Type", "mapi.recipients_headers.type", FT_UINT16, BASE_HEX, VALS(mapi_OM_recipient_type_vals), 0, "NULL", HFILL }},
{ &hf_mapi_recipient_type_EXCHANGE,
{ "Exchange", "mapi.recipient_type.EXCHANGE", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mapi_recipient_type_SMTP,
{ "Smtp", "mapi.recipient_type.SMTP", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mapi_recipients_headers_bitmask,
{ "Bitmask", "mapi.recipients_headers.bitmask", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_recipients_headers_layout,
{ "Layout", "mapi.recipients_headers.layout", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_recipients_headers_prop_count,
{ "Prop Count", "mapi.recipients_headers.prop_count", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mapi_recipients_headers_prop_values,
{ "Prop Values", "mapi.recipients_headers.prop_values", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mapi_recipients_headers_username,
{ "Username", "mapi.recipients_headers.username", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mapi_ulEventType_fnevCriticalError,
{ "Fnevcriticalerror", "mapi.ulEventType.fnevCriticalError", FT_BOOLEAN, 16, TFS(&ulEventType_fnevCriticalError_tfs), ( 0x00000001 ), NULL, HFILL }},
{ &hf_mapi_ulEventType_fnevExtended,
{ "Fnevextended", "mapi.ulEventType.fnevExtended", FT_BOOLEAN, 16, TFS(&ulEventType_fnevExtended_tfs), ( 0x80000000 ), NULL, HFILL }},
{ &hf_mapi_ulEventType_fnevNewMail,
{ "Fnevnewmail", "mapi.ulEventType.fnevNewMail", FT_BOOLEAN, 16, TFS(&ulEventType_fnevNewMail_tfs), ( 0x00000002 ), NULL, HFILL }},
{ &hf_mapi_ulEventType_fnevObjectCopied,
{ "Fnevobjectcopied", "mapi.ulEventType.fnevObjectCopied", FT_BOOLEAN, 16, TFS(&ulEventType_fnevObjectCopied_tfs), ( 0x00000040 ), NULL, HFILL }},
{ &hf_mapi_ulEventType_fnevObjectCreated,
{ "Fnevobjectcreated", "mapi.ulEventType.fnevObjectCreated", FT_BOOLEAN, 16, TFS(&ulEventType_fnevObjectCreated_tfs), ( 0x00000004 ), NULL, HFILL }},
{ &hf_mapi_ulEventType_fnevObjectDeleted,
{ "Fnevobjectdeleted", "mapi.ulEventType.fnevObjectDeleted", FT_BOOLEAN, 16, TFS(&ulEventType_fnevObjectDeleted_tfs), ( 0x00000008 ), NULL, HFILL }},
{ &hf_mapi_ulEventType_fnevObjectModified,
{ "Fnevobjectmodified", "mapi.ulEventType.fnevObjectModified", FT_BOOLEAN, 16, TFS(&ulEventType_fnevObjectModified_tfs), ( 0x00000010 ), NULL, HFILL }},
{ &hf_mapi_ulEventType_fnevObjectMoved,
{ "Fnevobjectmoved", "mapi.ulEventType.fnevObjectMoved", FT_BOOLEAN, 16, TFS(&ulEventType_fnevObjectMoved_tfs), ( 0x00000020 ), NULL, HFILL }},
{ &hf_mapi_ulEventType_fnevReservedForMapi,
{ "Fnevreservedformapi", "mapi.ulEventType.fnevReservedForMapi", FT_BOOLEAN, 16, TFS(&ulEventType_fnevReservedForMapi_tfs), ( 0x40000000 ), NULL, HFILL }},
{ &hf_mapi_ulEventType_fnevSearchComplete,
{ "Fnevsearchcomplete", "mapi.ulEventType.fnevSearchComplete", FT_BOOLEAN, 16, TFS(&ulEventType_fnevSearchComplete_tfs), ( 0x00000080 ), NULL, HFILL }},
{ &hf_mapi_ulEventType_fnevStatusObjectModified,
{ "Fnevstatusobjectmodified", "mapi.ulEventType.fnevStatusObjectModified", FT_BOOLEAN, 16, TFS(&ulEventType_fnevStatusObjectModified_tfs), ( 0x00000200 ), NULL, HFILL }},
{ &hf_mapi_ulEventType_fnevTableModified,
{ "Fnevtablemodified", "mapi.ulEventType.fnevTableModified", FT_BOOLEAN, 16, TFS(&ulEventType_fnevTableModified_tfs), ( 0x00000100 ), NULL, HFILL }},
};
static gint *ett[] = {
&ett_mapi_mapi_request,
&ett_mapi_EcDoRpc_MAPI_REQ,
&ett_mapi_OpenFolder_req,
&ett_mapi_GetProps_req,
&ett_mapi_OpenMsgStore_req,
&ett_mapi_mapi_response,
&ett_mapi_EcDoRpc_MAPI_REPL,
&ett_mapi_OpenFolder_repl,
&ett_mapi_GetProps_repl,
&ett_dcerpc_mapi,
&ett_mapi_DATA_BLOB,
&ett_mapi_input_locale,
&ett_mapi_FILETIME,
&ett_mapi_LPSTR,
&ett_mapi_SPropValue_CTR,
&ett_mapi_SPropValue,
&ett_mapi_SRow,
&ett_mapi_Release_req,
&ett_mapi_Release_repl,
&ett_mapi_OpenMessage_req,
&ett_mapi_RecipExchange,
&ett_mapi_RecipSMTP,
&ett_mapi_recipient_type,
&ett_mapi_recipient_displayname_7bit,
&ett_mapi_recipients_headers,
&ett_mapi_OpenMessage_recipients,
&ett_mapi_ulEventType,
&ett_mapi_EcDoRpc_MAPI_REQ_UNION,
&ett_mapi_EcDoRpc_MAPI_REPL_UNION,
};
proto_dcerpc_mapi = proto_register_protocol("Exchange 5.5 EMSMDB", "MAPI", "mapi");
proto_register_field_array(proto_dcerpc_mapi, hf, array_length (hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_dcerpc_mapi(void)
{
dcerpc_init_uuid(proto_dcerpc_mapi, ett_dcerpc_mapi,
&uuid_dcerpc_mapi, ver_dcerpc_mapi,
mapi_dissectors, hf_mapi_opnum);
}
