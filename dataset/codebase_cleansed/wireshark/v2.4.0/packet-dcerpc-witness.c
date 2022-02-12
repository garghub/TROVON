static int
witness_dissect_notifyResponse_message_(tvbuff_t *tvb, int offset, int length _U_, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep _U_)
{
guint32 *type = (guint32 *)di->private_data;
guint8 le_drep[4] = { DREP_LITTLE_ENDIAN, };
return witness_dissect_notifyResponse_message(tvb, offset, pinfo, tree, di, le_drep,
hf_witness_witness_notifyResponse_messages_, *type);
}
static int
witness_dissect_element_notifyResponse_messages(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info *di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray_block(tvb, offset, pinfo, tree, di, drep,
witness_dissect_notifyResponse_message_);
return offset;
}
int
witness_dissect_struct_notifyResponse(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
guint32 *type = NULL;
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_witness_witness_notifyResponse);
}
type = wmem_new0(wmem_packet_scope(), guint32);
offset = witness_dissect_element_notifyResponse_type(tvb, offset, pinfo, tree, di, drep, type);
offset = witness_dissect_element_notifyResponse_length(tvb, offset, pinfo, tree, di, drep);
offset = witness_dissect_element_notifyResponse_num(tvb, offset, pinfo, tree, di, drep);
di->private_data = type;
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep,
witness_dissect_element_notifyResponse_messages,
NDR_POINTER_UNIQUE, "Pointer to Message Buffer (uint8)",
hf_witness_witness_notifyResponse_messages);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
static int
witness_dissect_element_IPaddrInfoList_addr(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = witness_dissect_struct_IPaddrInfo(tvb,offset,pinfo,tree,di,drep,hf_witness_witness_IPaddrInfoList_addr,0);
return offset;
}
int
witness_dissect_struct_IPaddrInfoList(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
gboolean oldalign = di->no_align;
int old_offset;
guint32 i, num;
di->no_align = TRUE;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_witness_witness_IPaddrInfoList);
}
offset = witness_dissect_element_IPaddrInfoList_length(tvb, offset, pinfo, tree, di, drep);
offset = witness_dissect_element_IPaddrInfoList_reserved(tvb, offset, pinfo, tree, di, drep);
num = tvb_get_letohl(tvb, offset);
offset = witness_dissect_element_IPaddrInfoList_num(tvb, offset, pinfo, tree, di, drep);
for (i = 0; i < num; i++) {
offset = witness_dissect_element_IPaddrInfoList_addr(tvb, offset, pinfo, tree, di, drep);
}
proto_item_set_len(item, offset-old_offset);
di->no_align = oldalign;
return offset;
}
static int
witness_dissect_element_interfaceInfo_group_name(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *parent_tree, dcerpc_info *di _U_, guint8 *drep _U_)
{
const gchar *str;
int len = 260;
guint16 bc = tvb_captured_length_remaining(tvb, offset);
str = get_unicode_or_ascii_string(tvb, &offset, TRUE, &len, TRUE, TRUE, &bc);
if (str) {
proto_item *pi;
pi = proto_tree_add_string(parent_tree, hf_witness_witness_interfaceInfo_group_name, tvb, offset, 2*260, str);
proto_item_append_text(pi, " [%d]", len);
proto_item_append_text(parent_tree, ": %s", str);
} else {
}
return offset + 2*260;
}
static int
PIDL_dissect_ipv4address(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep _U_, int hfindex, guint32 param)
{
if (di->conformant_run) {
return offset;
}
if (!di->no_align && (offset % 4)) {
offset += 4 - (offset % 4);
}
proto_tree_add_item(tree, hfindex, tvb, offset, 4, ENC_BIG_ENDIAN);
if (param & PIDL_SET_COL_INFO) {
const char *ip = tvb_ip_to_str(tvb, offset);
header_field_info *hf_info = proto_registrar_get_nth(hfindex);
proto_item_append_text(proto_tree_get_parent(tree), " %s:%s", hf_info->name, ip);
col_append_fstr(pinfo->cinfo, COL_INFO," %s:%s", hf_info->name, ip);
}
return offset + 4;
}
static int
PIDL_dissect_ipv6address(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep _U_, int hfindex, guint32 param)
{
if (di->conformant_run) {
return offset;
}
if (!di->no_align && (offset % 2)) {
offset += 2 - (offset % 2);
}
proto_tree_add_item(tree, hfindex, tvb, offset, 16, ENC_BIG_ENDIAN);
if (param & PIDL_SET_COL_INFO) {
const char *ip = tvb_ip6_to_str(tvb, offset);
header_field_info *hf_info = proto_registrar_get_nth(hfindex);
proto_item_append_text(proto_tree_get_parent(tree), " %s:%s", hf_info->name, ip);
col_append_fstr(pinfo->cinfo, COL_INFO," %s:%s", hf_info->name, ip);
}
return offset + 16;
}
int
witness_dissect_enum_version(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
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
witness_dissect_enum_interfaceInfo_state(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint16 *param _U_)
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
int
witness_dissect_bitmap_interfaceInfo_flags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item;
static const int * witness_witness_interfaceInfo_flags_fields[] = {
&hf_witness_witness_interfaceInfo_flags_WITNESS_INFO_IPv4_VALID,
&hf_witness_witness_interfaceInfo_flags_WITNESS_INFO_IPv6_VALID,
&hf_witness_witness_interfaceInfo_flags_WITNESS_INFO_WITNESS_IF,
NULL
};
guint32 flags;
ALIGN_TO_4_BYTES;
item = proto_tree_add_bitmask_with_flags(parent_tree, tvb, offset, hf_index,
ett_witness_witness_interfaceInfo_flags, witness_witness_interfaceInfo_flags_fields, DREP_ENC_INTEGER(drep), BMT_NO_FALSE);
offset = dissect_ndr_uint32(tvb, offset, pinfo, parent_tree, di, drep, -1, &flags);
if (!flags)
proto_item_append_text(item, ": (No values set)");
if (flags & (~0x00000007)) {
flags &= (~0x00000007);
proto_item_append_text(item, "Unknown bitmap value 0x%x", flags);
}
return offset;
}
static int
witness_dissect_element_interfaceInfo_version(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = witness_dissect_enum_version(tvb, offset, pinfo, tree, di, drep, hf_witness_witness_interfaceInfo_version, 0);
return offset;
}
static int
witness_dissect_element_interfaceInfo_state(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = witness_dissect_enum_interfaceInfo_state(tvb, offset, pinfo, tree, di, drep, hf_witness_witness_interfaceInfo_state, 0);
return offset;
}
static int
witness_dissect_element_interfaceInfo_ipv4(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset=PIDL_dissect_ipv4address(tvb, offset, pinfo, tree, di, drep, hf_witness_witness_interfaceInfo_ipv4, PIDL_SET_COL_INFO);
return offset;
}
static int
witness_dissect_element_interfaceInfo_ipv6(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset=PIDL_dissect_ipv6address(tvb, offset, pinfo, tree, di, drep, hf_witness_witness_interfaceInfo_ipv6, PIDL_SET_COL_INFO);
return offset;
}
static int
witness_dissect_element_interfaceInfo_flags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = witness_dissect_bitmap_interfaceInfo_flags(tvb, offset, pinfo, tree, di, drep, hf_witness_witness_interfaceInfo_flags, 0);
return offset;
}
int
witness_dissect_struct_interfaceInfo(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_witness_witness_interfaceInfo);
}
offset = witness_dissect_element_interfaceInfo_group_name(tvb, offset, pinfo, tree, di, drep);
offset = witness_dissect_element_interfaceInfo_version(tvb, offset, pinfo, tree, di, drep);
offset = witness_dissect_element_interfaceInfo_state(tvb, offset, pinfo, tree, di, drep);
offset = witness_dissect_element_interfaceInfo_ipv4(tvb, offset, pinfo, tree, di, drep);
offset = witness_dissect_element_interfaceInfo_ipv6(tvb, offset, pinfo, tree, di, drep);
offset = witness_dissect_element_interfaceInfo_flags(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
static int
witness_dissect_element_interfaceList_num_interfaces(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_witness_witness_interfaceList_num_interfaces, 0);
return offset;
}
static int
witness_dissect_element_interfaceList_interfaces(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, witness_dissect_element_interfaceList_interfaces_, NDR_POINTER_UNIQUE, "Pointer to Interfaces (witness_interfaceInfo)",hf_witness_witness_interfaceList_interfaces);
return offset;
}
static int
witness_dissect_element_interfaceList_interfaces_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, witness_dissect_element_interfaceList_interfaces__);
return offset;
}
static int
witness_dissect_element_interfaceList_interfaces__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = witness_dissect_struct_interfaceInfo(tvb,offset,pinfo,tree,di,drep,hf_witness_witness_interfaceList_interfaces,0);
return offset;
}
int
witness_dissect_struct_interfaceList(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_witness_witness_interfaceList);
}
offset = witness_dissect_element_interfaceList_num_interfaces(tvb, offset, pinfo, tree, di, drep);
offset = witness_dissect_element_interfaceList_interfaces(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
int
witness_dissect_enum_notifyResponse_type(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
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
witness_dissect_enum_ResourceChange_type(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
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
witness_dissect_element_ResourceChange_length(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_witness_witness_ResourceChange_length, 0);
return offset;
}
static int
witness_dissect_element_ResourceChange_type(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = witness_dissect_enum_ResourceChange_type(tvb, offset, pinfo, tree, di, drep, hf_witness_witness_ResourceChange_type, 0);
return offset;
}
static int
witness_dissect_element_ResourceChange_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_null_term_wstring(tvb, offset, pinfo, tree, drep, hf_witness_witness_ResourceChange_name , 0);
return offset;
}
int
witness_dissect_struct_ResourceChange(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
gboolean oldalign = di->no_align;
int old_offset;
di->no_align = TRUE;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_witness_witness_ResourceChange);
}
offset = witness_dissect_element_ResourceChange_length(tvb, offset, pinfo, tree, di, drep);
offset = witness_dissect_element_ResourceChange_type(tvb, offset, pinfo, tree, di, drep);
offset = witness_dissect_element_ResourceChange_name(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
di->no_align = oldalign;
return offset;
}
int
witness_dissect_bitmap_IPaddrInfo_flags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item;
static const int * witness_witness_IPaddrInfo_flags_fields[] = {
&hf_witness_witness_IPaddrInfo_flags_WITNESS_IPADDR_V4,
&hf_witness_witness_IPaddrInfo_flags_WITNESS_IPADDR_V6,
&hf_witness_witness_IPaddrInfo_flags_WITNESS_IPADDR_ONLINE,
&hf_witness_witness_IPaddrInfo_flags_WITNESS_IPADDR_OFFLINE,
NULL
};
guint32 flags;
ALIGN_TO_4_BYTES;
item = proto_tree_add_bitmask_with_flags(parent_tree, tvb, offset, hf_index,
ett_witness_witness_IPaddrInfo_flags, witness_witness_IPaddrInfo_flags_fields, DREP_ENC_INTEGER(drep), BMT_NO_FALSE);
offset = dissect_ndr_uint32(tvb, offset, pinfo, parent_tree, di, drep, -1, &flags);
if (!flags)
proto_item_append_text(item, ": (No values set)");
if (flags & (~0x0000001b)) {
flags &= (~0x0000001b);
proto_item_append_text(item, "Unknown bitmap value 0x%x", flags);
}
return offset;
}
static int
witness_dissect_element_IPaddrInfo_flags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = witness_dissect_bitmap_IPaddrInfo_flags(tvb, offset, pinfo, tree, di, drep, hf_witness_witness_IPaddrInfo_flags, 0);
return offset;
}
static int
witness_dissect_element_IPaddrInfo_ipv4(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset=PIDL_dissect_ipv4address(tvb, offset, pinfo, tree, di, drep, hf_witness_witness_IPaddrInfo_ipv4, PIDL_SET_COL_INFO);
return offset;
}
static int
witness_dissect_element_IPaddrInfo_ipv6(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset=PIDL_dissect_ipv6address(tvb, offset, pinfo, tree, di, drep, hf_witness_witness_IPaddrInfo_ipv6, PIDL_SET_COL_INFO);
return offset;
}
int
witness_dissect_struct_IPaddrInfo(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
gboolean oldalign = di->no_align;
int old_offset;
di->no_align = TRUE;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_witness_witness_IPaddrInfo);
}
offset = witness_dissect_element_IPaddrInfo_flags(tvb, offset, pinfo, tree, di, drep);
offset = witness_dissect_element_IPaddrInfo_ipv4(tvb, offset, pinfo, tree, di, drep);
offset = witness_dissect_element_IPaddrInfo_ipv6(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
di->no_align = oldalign;
return offset;
}
static int
witness_dissect_element_IPaddrInfoList_length(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_witness_witness_IPaddrInfoList_length, 0);
return offset;
}
static int
witness_dissect_element_IPaddrInfoList_reserved(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_witness_witness_IPaddrInfoList_reserved, 0);
return offset;
}
static int
witness_dissect_element_IPaddrInfoList_num(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_witness_witness_IPaddrInfoList_num, 0);
return offset;
}
static int
witness_dissect_element_notifyResponse_message_resource_change(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = witness_dissect_struct_ResourceChange(tvb,offset,pinfo,tree,di,drep,hf_witness_witness_notifyResponse_message_resource_change,0);
return offset;
}
static int
witness_dissect_element_notifyResponse_message_client_move(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = witness_dissect_struct_IPaddrInfoList(tvb,offset,pinfo,tree,di,drep,hf_witness_witness_notifyResponse_message_client_move,0);
return offset;
}
static int
witness_dissect_element_notifyResponse_message_share_move(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = witness_dissect_struct_IPaddrInfoList(tvb,offset,pinfo,tree,di,drep,hf_witness_witness_notifyResponse_message_share_move,0);
return offset;
}
static int
witness_dissect_element_notifyResponse_message_ip_change(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = witness_dissect_struct_IPaddrInfoList(tvb,offset,pinfo,tree,di,drep,hf_witness_witness_notifyResponse_message_ip_change,0);
return offset;
}
static int
witness_dissect_element_notifyResponse_message_data(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_datablob(tvb, offset, pinfo, tree, di, drep, hf_witness_witness_notifyResponse_message_data, 1);
return offset;
}
static int
witness_dissect_notifyResponse_message(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
guint32 level = param;
old_offset = offset;
if (parent_tree) {
tree = proto_tree_add_subtree(parent_tree, tvb, offset, -1, ett_witness_witness_notifyResponse_message, &item, "witness_notifyResponse_message");
}
switch(level) {
case WITNESS_NOTIFY_RESOURCE_CHANGE:
offset = witness_dissect_element_notifyResponse_message_resource_change(tvb, offset, pinfo, tree, di, drep);
break;
case WITNESS_NOTIFY_CLIENT_MOVE:
offset = witness_dissect_element_notifyResponse_message_client_move(tvb, offset, pinfo, tree, di, drep);
break;
case WITNESS_NOTIFY_SHARE_MOVE:
offset = witness_dissect_element_notifyResponse_message_share_move(tvb, offset, pinfo, tree, di, drep);
break;
case WITNESS_NOTIFY_IP_CHANGE:
offset = witness_dissect_element_notifyResponse_message_ip_change(tvb, offset, pinfo, tree, di, drep);
break;
default:
offset = witness_dissect_element_notifyResponse_message_data(tvb, offset, pinfo, tree, di, drep);
break;
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
witness_dissect_element_notifyResponse_type(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, guint32 *type)
{
offset = witness_dissect_enum_notifyResponse_type(tvb, offset, pinfo, tree, di, drep, hf_witness_witness_notifyResponse_type, type);
return offset;
}
static int
witness_dissect_element_notifyResponse_length(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_witness_witness_notifyResponse_length, 0);
return offset;
}
static int
witness_dissect_element_notifyResponse_num(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_witness_witness_notifyResponse_num, 0);
return offset;
}
int
witness_dissect_bitmap_RegisterEx_flags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item;
static const int * witness_witness_RegisterEx_flags_fields[] = {
&hf_witness_witness_RegisterEx_flags_WITNESS_REGISTER_IP_NOTIFICATION,
NULL
};
guint32 flags;
ALIGN_TO_4_BYTES;
item = proto_tree_add_bitmask_with_flags(parent_tree, tvb, offset, hf_index,
ett_witness_witness_RegisterEx_flags, witness_witness_RegisterEx_flags_fields, DREP_ENC_INTEGER(drep), BMT_NO_FALSE);
offset = dissect_ndr_uint32(tvb, offset, pinfo, parent_tree, di, drep, -1, &flags);
if (!flags)
proto_item_append_text(item, ": (No values set)");
if (flags & (~0x00000001)) {
flags &= (~0x00000001);
proto_item_append_text(item, "Unknown bitmap value 0x%x", flags);
}
return offset;
}
static int
witness_dissect_element_GetInterfaceList_interface_list(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, witness_dissect_element_GetInterfaceList_interface_list_, NDR_POINTER_REF, "Pointer to Interface List (witness_interfaceList)",hf_witness_witness_GetInterfaceList_interface_list);
return offset;
}
static int
witness_dissect_element_GetInterfaceList_interface_list_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, witness_dissect_element_GetInterfaceList_interface_list__, NDR_POINTER_UNIQUE, "Pointer to Interface List (witness_interfaceList)",hf_witness_witness_GetInterfaceList_interface_list);
return offset;
}
static int
witness_dissect_element_GetInterfaceList_interface_list__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = witness_dissect_struct_interfaceList(tvb,offset,pinfo,tree,di,drep,hf_witness_witness_GetInterfaceList_interface_list,0);
return offset;
}
static int
witness_dissect_GetInterfaceList_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="GetInterfaceList";
offset = witness_dissect_element_GetInterfaceList_interface_list(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_witness_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
witness_dissect_GetInterfaceList_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="GetInterfaceList";
return offset;
}
static int
witness_dissect_element_Register_context_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, witness_dissect_element_Register_context_handle_, NDR_POINTER_REF, "Pointer to Context Handle (policy_handle)",hf_witness_witness_Register_context_handle);
return offset;
}
static int
witness_dissect_element_Register_context_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_witness_witness_Register_context_handle, 0);
return offset;
}
static int
witness_dissect_element_Register_version(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = witness_dissect_enum_version(tvb, offset, pinfo, tree, di, drep, hf_witness_witness_Register_version, 0);
return offset;
}
static int
witness_dissect_element_Register_net_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, witness_dissect_element_Register_net_name_, NDR_POINTER_UNIQUE, "Pointer to Net Name (uint16)",hf_witness_witness_Register_net_name);
return offset;
}
static int
witness_dissect_element_Register_net_name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_witness_witness_Register_net_name, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
witness_dissect_element_Register_ip_address(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, witness_dissect_element_Register_ip_address_, NDR_POINTER_UNIQUE, "Pointer to Ip Address (uint16)",hf_witness_witness_Register_ip_address);
return offset;
}
static int
witness_dissect_element_Register_ip_address_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_witness_witness_Register_ip_address, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
witness_dissect_element_Register_client_computer_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, witness_dissect_element_Register_client_computer_name_, NDR_POINTER_UNIQUE, "Pointer to Client Computer Name (uint16)",hf_witness_witness_Register_client_computer_name);
return offset;
}
static int
witness_dissect_element_Register_client_computer_name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_witness_witness_Register_client_computer_name, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
witness_dissect_Register_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="Register";
offset = witness_dissect_element_Register_context_handle(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_witness_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
witness_dissect_Register_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="Register";
offset = witness_dissect_element_Register_version(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = witness_dissect_element_Register_net_name(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = witness_dissect_element_Register_ip_address(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = witness_dissect_element_Register_client_computer_name(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
witness_dissect_element_UnRegister_context_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_witness_witness_UnRegister_context_handle, 0);
return offset;
}
static int
witness_dissect_UnRegister_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="UnRegister";
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_witness_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
witness_dissect_UnRegister_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="UnRegister";
offset = witness_dissect_element_UnRegister_context_handle(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
witness_dissect_element_AsyncNotify_context_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_witness_witness_AsyncNotify_context_handle, 0);
return offset;
}
static int
witness_dissect_element_AsyncNotify_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, witness_dissect_element_AsyncNotify_response_, NDR_POINTER_REF, "Pointer to Response (witness_notifyResponse)",hf_witness_witness_AsyncNotify_response);
return offset;
}
static int
witness_dissect_element_AsyncNotify_response_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, witness_dissect_element_AsyncNotify_response__, NDR_POINTER_UNIQUE, "Pointer to Response (witness_notifyResponse)",hf_witness_witness_AsyncNotify_response);
return offset;
}
static int
witness_dissect_element_AsyncNotify_response__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = witness_dissect_struct_notifyResponse(tvb,offset,pinfo,tree,di,drep,hf_witness_witness_AsyncNotify_response,0);
return offset;
}
static int
witness_dissect_AsyncNotify_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="AsyncNotify";
offset = witness_dissect_element_AsyncNotify_response(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_witness_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
witness_dissect_AsyncNotify_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="AsyncNotify";
offset = witness_dissect_element_AsyncNotify_context_handle(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
witness_dissect_element_RegisterEx_context_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, witness_dissect_element_RegisterEx_context_handle_, NDR_POINTER_REF, "Pointer to Context Handle (policy_handle)",hf_witness_witness_RegisterEx_context_handle);
return offset;
}
static int
witness_dissect_element_RegisterEx_context_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_witness_witness_RegisterEx_context_handle, 0);
return offset;
}
static int
witness_dissect_element_RegisterEx_version(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = witness_dissect_enum_version(tvb, offset, pinfo, tree, di, drep, hf_witness_witness_RegisterEx_version, 0);
return offset;
}
static int
witness_dissect_element_RegisterEx_net_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, witness_dissect_element_RegisterEx_net_name_, NDR_POINTER_UNIQUE, "Pointer to Net Name (uint16)",hf_witness_witness_RegisterEx_net_name);
return offset;
}
static int
witness_dissect_element_RegisterEx_net_name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_witness_witness_RegisterEx_net_name, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
witness_dissect_element_RegisterEx_share_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, witness_dissect_element_RegisterEx_share_name_, NDR_POINTER_UNIQUE, "Pointer to Share Name (uint16)",hf_witness_witness_RegisterEx_share_name);
return offset;
}
static int
witness_dissect_element_RegisterEx_share_name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_witness_witness_RegisterEx_share_name, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
witness_dissect_element_RegisterEx_ip_address(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, witness_dissect_element_RegisterEx_ip_address_, NDR_POINTER_UNIQUE, "Pointer to Ip Address (uint16)",hf_witness_witness_RegisterEx_ip_address);
return offset;
}
static int
witness_dissect_element_RegisterEx_ip_address_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_witness_witness_RegisterEx_ip_address, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
witness_dissect_element_RegisterEx_client_computer_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, witness_dissect_element_RegisterEx_client_computer_name_, NDR_POINTER_UNIQUE, "Pointer to Client Computer Name (uint16)",hf_witness_witness_RegisterEx_client_computer_name);
return offset;
}
static int
witness_dissect_element_RegisterEx_client_computer_name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_witness_witness_RegisterEx_client_computer_name, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
witness_dissect_element_RegisterEx_flags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = witness_dissect_bitmap_RegisterEx_flags(tvb, offset, pinfo, tree, di, drep, hf_witness_witness_RegisterEx_flags, 0);
return offset;
}
static int
witness_dissect_element_RegisterEx_timeout(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_witness_witness_RegisterEx_timeout, 0);
return offset;
}
static int
witness_dissect_RegisterEx_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="RegisterEx";
offset = witness_dissect_element_RegisterEx_context_handle(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_witness_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
witness_dissect_RegisterEx_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="RegisterEx";
offset = witness_dissect_element_RegisterEx_version(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = witness_dissect_element_RegisterEx_net_name(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = witness_dissect_element_RegisterEx_share_name(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = witness_dissect_element_RegisterEx_ip_address(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = witness_dissect_element_RegisterEx_client_computer_name(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = witness_dissect_element_RegisterEx_flags(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = witness_dissect_element_RegisterEx_timeout(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
void proto_register_dcerpc_witness(void)
{
static hf_register_info hf[] = {
{ &hf_witness_opnum,
{ "Operation", "witness.opnum", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_witness_werror,
{ "Windows Error", "witness.werror", FT_UINT32, BASE_HEX, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_witness_witness_AsyncNotify_context_handle,
{ "Context Handle", "witness.witness_AsyncNotify.context_handle", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_AsyncNotify_response,
{ "Response", "witness.witness_AsyncNotify.response", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_GetInterfaceList_interface_list,
{ "Interface List", "witness.witness_GetInterfaceList.interface_list", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_IPaddrInfoList_addr,
{ "Addr", "witness.witness_IPaddrInfoList.addr", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_IPaddrInfoList_length,
{ "Length", "witness.witness_IPaddrInfoList.length", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_IPaddrInfoList_num,
{ "Num", "witness.witness_IPaddrInfoList.num", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_IPaddrInfoList_reserved,
{ "Reserved", "witness.witness_IPaddrInfoList.reserved", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_IPaddrInfo_flags,
{ "Flags", "witness.witness_IPaddrInfo.flags", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_IPaddrInfo_flags_WITNESS_IPADDR_OFFLINE,
{ "WITNESS IPADDR OFFLINE", "witness.witness_IPaddrInfo_flags.WITNESS_IPADDR_OFFLINE", FT_BOOLEAN, 32, TFS(&witness_IPaddrInfo_flags_WITNESS_IPADDR_OFFLINE_tfs), ( 0x10 ), NULL, HFILL }},
{ &hf_witness_witness_IPaddrInfo_flags_WITNESS_IPADDR_ONLINE,
{ "WITNESS IPADDR ONLINE", "witness.witness_IPaddrInfo_flags.WITNESS_IPADDR_ONLINE", FT_BOOLEAN, 32, TFS(&witness_IPaddrInfo_flags_WITNESS_IPADDR_ONLINE_tfs), ( 0x08 ), NULL, HFILL }},
{ &hf_witness_witness_IPaddrInfo_flags_WITNESS_IPADDR_V4,
{ "WITNESS IPADDR V4", "witness.witness_IPaddrInfo_flags.WITNESS_IPADDR_V4", FT_BOOLEAN, 32, TFS(&witness_IPaddrInfo_flags_WITNESS_IPADDR_V4_tfs), ( 0x01 ), NULL, HFILL }},
{ &hf_witness_witness_IPaddrInfo_flags_WITNESS_IPADDR_V6,
{ "WITNESS IPADDR V6", "witness.witness_IPaddrInfo_flags.WITNESS_IPADDR_V6", FT_BOOLEAN, 32, TFS(&witness_IPaddrInfo_flags_WITNESS_IPADDR_V6_tfs), ( 0x02 ), NULL, HFILL }},
{ &hf_witness_witness_IPaddrInfo_ipv4,
{ "Ipv4", "witness.witness_IPaddrInfo.ipv4", FT_IPv4, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_IPaddrInfo_ipv6,
{ "Ipv6", "witness.witness_IPaddrInfo.ipv6", FT_IPv6, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_RegisterEx_client_computer_name,
{ "Client Computer Name", "witness.witness_RegisterEx.client_computer_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_RegisterEx_context_handle,
{ "Context Handle", "witness.witness_RegisterEx.context_handle", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_RegisterEx_flags,
{ "Flags", "witness.witness_RegisterEx.flags", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_RegisterEx_flags_WITNESS_REGISTER_IP_NOTIFICATION,
{ "WITNESS REGISTER IP NOTIFICATION", "witness.witness_RegisterEx_flags.WITNESS_REGISTER_IP_NOTIFICATION", FT_BOOLEAN, 32, TFS(&witness_RegisterEx_flags_WITNESS_REGISTER_IP_NOTIFICATION_tfs), ( 0x01 ), NULL, HFILL }},
{ &hf_witness_witness_RegisterEx_ip_address,
{ "Ip Address", "witness.witness_RegisterEx.ip_address", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_RegisterEx_net_name,
{ "Net Name", "witness.witness_RegisterEx.net_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_RegisterEx_share_name,
{ "Share Name", "witness.witness_RegisterEx.share_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_RegisterEx_timeout,
{ "Timeout", "witness.witness_RegisterEx.timeout", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_RegisterEx_version,
{ "Version", "witness.witness_RegisterEx.version", FT_UINT32, BASE_DEC, VALS(witness_witness_version_vals), 0, NULL, HFILL }},
{ &hf_witness_witness_Register_client_computer_name,
{ "Client Computer Name", "witness.witness_Register.client_computer_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_Register_context_handle,
{ "Context Handle", "witness.witness_Register.context_handle", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_Register_ip_address,
{ "Ip Address", "witness.witness_Register.ip_address", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_Register_net_name,
{ "Net Name", "witness.witness_Register.net_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_Register_version,
{ "Version", "witness.witness_Register.version", FT_UINT32, BASE_DEC, VALS(witness_witness_version_vals), 0, NULL, HFILL }},
{ &hf_witness_witness_ResourceChange_length,
{ "Length", "witness.witness_ResourceChange.length", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_ResourceChange_name,
{ "Name", "witness.witness_ResourceChange.name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_ResourceChange_type,
{ "Type", "witness.witness_ResourceChange.type", FT_UINT32, BASE_DEC, VALS(witness_witness_ResourceChange_type_vals), 0, NULL, HFILL }},
{ &hf_witness_witness_UnRegister_context_handle,
{ "Context Handle", "witness.witness_UnRegister.context_handle", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_interfaceInfo_flags,
{ "Flags", "witness.witness_interfaceInfo.flags", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_interfaceInfo_flags_WITNESS_INFO_IPv4_VALID,
{ "WITNESS INFO IPv4 VALID", "witness.witness_interfaceInfo_flags.WITNESS_INFO_IPv4_VALID", FT_BOOLEAN, 32, TFS(&witness_interfaceInfo_flags_WITNESS_INFO_IPv4_VALID_tfs), ( 0x01 ), NULL, HFILL }},
{ &hf_witness_witness_interfaceInfo_flags_WITNESS_INFO_IPv6_VALID,
{ "WITNESS INFO IPv6 VALID", "witness.witness_interfaceInfo_flags.WITNESS_INFO_IPv6_VALID", FT_BOOLEAN, 32, TFS(&witness_interfaceInfo_flags_WITNESS_INFO_IPv6_VALID_tfs), ( 0x02 ), NULL, HFILL }},
{ &hf_witness_witness_interfaceInfo_flags_WITNESS_INFO_WITNESS_IF,
{ "WITNESS INFO WITNESS IF", "witness.witness_interfaceInfo_flags.WITNESS_INFO_WITNESS_IF", FT_BOOLEAN, 32, TFS(&witness_interfaceInfo_flags_WITNESS_INFO_WITNESS_IF_tfs), ( 0x04 ), NULL, HFILL }},
{ &hf_witness_witness_interfaceInfo_group_name,
{ "Group Name", "witness.witness_interfaceInfo.group_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_interfaceInfo_ipv4,
{ "Ipv4", "witness.witness_interfaceInfo.ipv4", FT_IPv4, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_interfaceInfo_ipv6,
{ "Ipv6", "witness.witness_interfaceInfo.ipv6", FT_IPv6, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_interfaceInfo_state,
{ "State", "witness.witness_interfaceInfo.state", FT_UINT16, BASE_DEC, VALS(witness_witness_interfaceInfo_state_vals), 0, NULL, HFILL }},
{ &hf_witness_witness_interfaceInfo_version,
{ "Version", "witness.witness_interfaceInfo.version", FT_UINT32, BASE_DEC, VALS(witness_witness_version_vals), 0, NULL, HFILL }},
{ &hf_witness_witness_interfaceList_interfaces,
{ "Interfaces", "witness.witness_interfaceList.interfaces", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_interfaceList_num_interfaces,
{ "Num Interfaces", "witness.witness_interfaceList.num_interfaces", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_notifyResponse_length,
{ "Length", "witness.witness_notifyResponse.length", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_notifyResponse_message_client_move,
{ "Client Move", "witness.witness_notifyResponse_message.client_move", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_notifyResponse_message_data,
{ "Data", "witness.witness_notifyResponse_message.data", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_notifyResponse_message_ip_change,
{ "Ip Change", "witness.witness_notifyResponse_message.ip_change", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_notifyResponse_message_resource_change,
{ "Resource Change", "witness.witness_notifyResponse_message.resource_change", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_notifyResponse_message_share_move,
{ "Share Move", "witness.witness_notifyResponse_message.share_move", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_notifyResponse_messages,
{ "Messages", "witness.witness_notifyResponse.messages", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_notifyResponse_messages_,
{ "Messages", "witness.witness_notifyResponse.messages_", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_notifyResponse_num,
{ "Num", "witness.witness_notifyResponse.num", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_witness_witness_notifyResponse_type,
{ "Type", "witness.witness_notifyResponse.type", FT_UINT32, BASE_DEC, VALS(witness_witness_notifyResponse_type_vals), 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_dcerpc_witness,
&ett_witness_witness_interfaceInfo_flags,
&ett_witness_witness_interfaceInfo,
&ett_witness_witness_interfaceList,
&ett_witness_witness_ResourceChange,
&ett_witness_witness_IPaddrInfo_flags,
&ett_witness_witness_IPaddrInfo,
&ett_witness_witness_IPaddrInfoList,
&ett_witness_witness_notifyResponse_message,
&ett_witness_witness_notifyResponse,
&ett_witness_witness_RegisterEx_flags,
};
proto_dcerpc_witness = proto_register_protocol("SMB Witness Service", "WITNESS", "witness");
proto_register_field_array(proto_dcerpc_witness, hf, array_length (hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_dcerpc_witness(void)
{
dcerpc_init_uuid(proto_dcerpc_witness, ett_dcerpc_witness,
&uuid_dcerpc_witness, ver_dcerpc_witness,
witness_dissectors, hf_witness_opnum);
}
