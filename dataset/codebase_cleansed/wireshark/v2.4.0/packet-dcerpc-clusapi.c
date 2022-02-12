static int
clusapi_dissect_element_RPC_SECURITY_DESCRIPTOR_lpSecurityDescriptor(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_RPC_SECURITY_DESCRIPTOR_lpSecurityDescriptor_, NDR_POINTER_UNIQUE, "Pointer to LpSecurityDescriptor (uint8)",hf_clusapi_RPC_SECURITY_DESCRIPTOR_lpSecurityDescriptor);
return offset;
}
static int
clusapi_dissect_element_RPC_SECURITY_DESCRIPTOR_lpSecurityDescriptor_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucvarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_RPC_SECURITY_DESCRIPTOR_lpSecurityDescriptor__);
return offset;
}
static int
clusapi_dissect_element_RPC_SECURITY_DESCRIPTOR_lpSecurityDescriptor__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_RPC_SECURITY_DESCRIPTOR_lpSecurityDescriptor, 0);
return offset;
}
static int
clusapi_dissect_element_RPC_SECURITY_DESCRIPTOR_cbInSecurityDescriptor(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_RPC_SECURITY_DESCRIPTOR_cbInSecurityDescriptor, 0);
return offset;
}
static int
clusapi_dissect_element_RPC_SECURITY_DESCRIPTOR_cbOutSecurityDescriptor(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_RPC_SECURITY_DESCRIPTOR_cbOutSecurityDescriptor, 0);
return offset;
}
int
clusapi_dissect_struct_RPC_SECURITY_DESCRIPTOR(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_clusapi_RPC_SECURITY_DESCRIPTOR);
}
offset = clusapi_dissect_element_RPC_SECURITY_DESCRIPTOR_lpSecurityDescriptor(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_RPC_SECURITY_DESCRIPTOR_cbInSecurityDescriptor(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_RPC_SECURITY_DESCRIPTOR_cbOutSecurityDescriptor(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
clusapi_dissect_element_RPC_SECURITY_ATTRIBUTES_nLength(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_RPC_SECURITY_ATTRIBUTES_nLength, 0);
return offset;
}
static int
clusapi_dissect_element_RPC_SECURITY_ATTRIBUTES_RpcSecurityDescriptor(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_struct_RPC_SECURITY_DESCRIPTOR(tvb,offset,pinfo,tree,di,drep,hf_clusapi_RPC_SECURITY_ATTRIBUTES_RpcSecurityDescriptor,0);
return offset;
}
static int
clusapi_dissect_element_RPC_SECURITY_ATTRIBUTES_bInheritHandle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_RPC_SECURITY_ATTRIBUTES_bInheritHandle, 0);
return offset;
}
int
clusapi_dissect_struct_RPC_SECURITY_ATTRIBUTES(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_clusapi_RPC_SECURITY_ATTRIBUTES);
}
offset = clusapi_dissect_element_RPC_SECURITY_ATTRIBUTES_nLength(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_RPC_SECURITY_ATTRIBUTES_RpcSecurityDescriptor(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_RPC_SECURITY_ATTRIBUTES_bInheritHandle(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
clusapi_dissect_element_CLUSTER_OPERATIONAL_VERSION_INFO_dwSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_CLUSTER_OPERATIONAL_VERSION_INFO_dwSize, 0);
return offset;
}
static int
clusapi_dissect_element_CLUSTER_OPERATIONAL_VERSION_INFO_dwClusterHighestVersion(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_CLUSTER_OPERATIONAL_VERSION_INFO_dwClusterHighestVersion, 0);
return offset;
}
static int
clusapi_dissect_element_CLUSTER_OPERATIONAL_VERSION_INFO_dwClusterLowestVersion(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_CLUSTER_OPERATIONAL_VERSION_INFO_dwClusterLowestVersion, 0);
return offset;
}
static int
clusapi_dissect_element_CLUSTER_OPERATIONAL_VERSION_INFO_dwFlags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_CLUSTER_OPERATIONAL_VERSION_INFO_dwFlags, 0);
return offset;
}
static int
clusapi_dissect_element_CLUSTER_OPERATIONAL_VERSION_INFO_dwReserved(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_CLUSTER_OPERATIONAL_VERSION_INFO_dwReserved, 0);
return offset;
}
int
clusapi_dissect_struct_CLUSTER_OPERATIONAL_VERSION_INFO(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_clusapi_CLUSTER_OPERATIONAL_VERSION_INFO);
}
offset = clusapi_dissect_element_CLUSTER_OPERATIONAL_VERSION_INFO_dwSize(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_CLUSTER_OPERATIONAL_VERSION_INFO_dwClusterHighestVersion(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_CLUSTER_OPERATIONAL_VERSION_INFO_dwClusterLowestVersion(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_CLUSTER_OPERATIONAL_VERSION_INFO_dwFlags(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_CLUSTER_OPERATIONAL_VERSION_INFO_dwReserved(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
static int
clusapi_dissect_element_IDL_CLUSTER_SET_PASSWORD_STATUS_NodeId(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_IDL_CLUSTER_SET_PASSWORD_STATUS_NodeId, 0);
return offset;
}
static int
clusapi_dissect_element_IDL_CLUSTER_SET_PASSWORD_STATUS_SetAttempted(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_IDL_CLUSTER_SET_PASSWORD_STATUS_SetAttempted, 0);
return offset;
}
static int
clusapi_dissect_element_IDL_CLUSTER_SET_PASSWORD_STATUS_ReturnStatus(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_IDL_CLUSTER_SET_PASSWORD_STATUS_ReturnStatus, 0);
return offset;
}
int
clusapi_dissect_struct_IDL_CLUSTER_SET_PASSWORD_STATUS(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_clusapi_IDL_CLUSTER_SET_PASSWORD_STATUS);
}
offset = clusapi_dissect_element_IDL_CLUSTER_SET_PASSWORD_STATUS_NodeId(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_IDL_CLUSTER_SET_PASSWORD_STATUS_SetAttempted(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_IDL_CLUSTER_SET_PASSWORD_STATUS_ReturnStatus(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
int
clusapi_dissect_enum_IDL_CLUSTER_SET_PASSWORD_FLAGS(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint1632 *param _U_)
{
guint1632 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
static int
clusapi_dissect_element_CLUSTER_CREATE_GROUP_INFO_RPC_dwVersion(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_CLUSTER_CREATE_GROUP_INFO_RPC_dwVersion, 0);
return offset;
}
static int
clusapi_dissect_element_CLUSTER_CREATE_GROUP_INFO_RPC_dwGroupType(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_CLUSTER_CREATE_GROUP_INFO_RPC_dwGroupType, 0);
return offset;
}
int
clusapi_dissect_struct_CLUSTER_CREATE_GROUP_INFO_RPC(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_clusapi_CLUSTER_CREATE_GROUP_INFO_RPC);
}
offset = clusapi_dissect_element_CLUSTER_CREATE_GROUP_INFO_RPC_dwVersion(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_CLUSTER_CREATE_GROUP_INFO_RPC_dwGroupType(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
int
clusapi_dissect_bitmap_ClusterEnumType(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item;
static const int * clusapi_ClusterEnumType_fields[] = {
&hf_clusapi_ClusterEnumType_CLUSTER_ENUM_NODE,
&hf_clusapi_ClusterEnumType_CLUSTER_ENUM_RESTYPE,
&hf_clusapi_ClusterEnumType_CLUSTER_ENUM_RESOURCE,
&hf_clusapi_ClusterEnumType_CLUSTER_ENUM_GROUP,
&hf_clusapi_ClusterEnumType_CLUSTER_ENUM_NETWORK,
&hf_clusapi_ClusterEnumType_CLUSTER_ENUM_NETINTERFACE,
&hf_clusapi_ClusterEnumType_CLUSTER_ENUM_INTERNAL_NETWORK,
&hf_clusapi_ClusterEnumType_CLUSTER_ENUM_SHARED_VOLUME_RESOURCE,
NULL
};
guint32 flags;
ALIGN_TO_4_BYTES;
item = proto_tree_add_bitmask_with_flags(parent_tree, tvb, offset, hf_index,
ett_clusapi_ClusterEnumType, clusapi_ClusterEnumType_fields, DREP_ENC_INTEGER(drep), BMT_NO_FALSE);
offset = dissect_ndr_uint32(tvb, offset, pinfo, parent_tree, di, drep, -1, &flags);
if (!flags)
proto_item_append_text(item, ": (No values set)");
if (flags & (~0xc000003f)) {
flags &= (~0xc000003f);
proto_item_append_text(item, "Unknown bitmap value 0x%x", flags);
}
return offset;
}
static int
clusapi_dissect_element_ENUM_ENTRY_Type(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_bitmap_ClusterEnumType(tvb, offset, pinfo, tree, di, drep, hf_clusapi_ENUM_ENTRY_Type, 0);
return offset;
}
static int
clusapi_dissect_element_ENUM_ENTRY_Name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ENUM_ENTRY_Name_, NDR_POINTER_UNIQUE, "Pointer to Name (uint16)",hf_clusapi_ENUM_ENTRY_Name);
return offset;
}
static int
clusapi_dissect_element_ENUM_ENTRY_Name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_ENUM_ENTRY_Name, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
int
clusapi_dissect_struct_ENUM_ENTRY(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_clusapi_ENUM_ENTRY);
}
offset = clusapi_dissect_element_ENUM_ENTRY_Type(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_ENUM_ENTRY_Name(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
clusapi_dissect_element_ENUM_LIST_EntryCount(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_ENUM_LIST_EntryCount, 0);
return offset;
}
static int
clusapi_dissect_element_ENUM_LIST_Entry(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ENUM_LIST_Entry_);
return offset;
}
static int
clusapi_dissect_element_ENUM_LIST_Entry_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_struct_ENUM_ENTRY(tvb,offset,pinfo,tree,di,drep,hf_clusapi_ENUM_LIST_Entry,0);
return offset;
}
int
clusapi_dissect_struct_ENUM_LIST(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_clusapi_ENUM_LIST);
}
offset = clusapi_dissect_element_ENUM_LIST_EntryCount(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_ENUM_LIST_Entry(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
clusapi_dissect_element_GROUP_ENUM_ENTRY_Name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GROUP_ENUM_ENTRY_Name_, NDR_POINTER_UNIQUE, "Pointer to Name (uint16)",hf_clusapi_GROUP_ENUM_ENTRY_Name);
return offset;
}
static int
clusapi_dissect_element_GROUP_ENUM_ENTRY_Name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_GROUP_ENUM_ENTRY_Name, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_GROUP_ENUM_ENTRY_Id(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GROUP_ENUM_ENTRY_Id_, NDR_POINTER_UNIQUE, "Pointer to Id (uint16)",hf_clusapi_GROUP_ENUM_ENTRY_Id);
return offset;
}
static int
clusapi_dissect_element_GROUP_ENUM_ENTRY_Id_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_GROUP_ENUM_ENTRY_Id, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_GROUP_ENUM_ENTRY_dwState(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_GROUP_ENUM_ENTRY_dwState, 0);
return offset;
}
static int
clusapi_dissect_element_GROUP_ENUM_ENTRY_Owner(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GROUP_ENUM_ENTRY_Owner_, NDR_POINTER_UNIQUE, "Pointer to Owner (uint16)",hf_clusapi_GROUP_ENUM_ENTRY_Owner);
return offset;
}
static int
clusapi_dissect_element_GROUP_ENUM_ENTRY_Owner_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_GROUP_ENUM_ENTRY_Owner, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_GROUP_ENUM_ENTRY_dwFlags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_GROUP_ENUM_ENTRY_dwFlags, 0);
return offset;
}
static int
clusapi_dissect_element_GROUP_ENUM_ENTRY_cbProperties(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_GROUP_ENUM_ENTRY_cbProperties, 0);
return offset;
}
static int
clusapi_dissect_element_GROUP_ENUM_ENTRY_Properties(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GROUP_ENUM_ENTRY_Properties_, NDR_POINTER_UNIQUE, "Pointer to Properties (uint8)",hf_clusapi_GROUP_ENUM_ENTRY_Properties);
return offset;
}
static int
clusapi_dissect_element_GROUP_ENUM_ENTRY_Properties_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GROUP_ENUM_ENTRY_Properties__);
return offset;
}
static int
clusapi_dissect_element_GROUP_ENUM_ENTRY_Properties__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_GROUP_ENUM_ENTRY_Properties, 0);
return offset;
}
static int
clusapi_dissect_element_GROUP_ENUM_ENTRY_cbRoProperties(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_GROUP_ENUM_ENTRY_cbRoProperties, 0);
return offset;
}
static int
clusapi_dissect_element_GROUP_ENUM_ENTRY_RoProperties(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GROUP_ENUM_ENTRY_RoProperties_, NDR_POINTER_UNIQUE, "Pointer to RoProperties (uint8)",hf_clusapi_GROUP_ENUM_ENTRY_RoProperties);
return offset;
}
static int
clusapi_dissect_element_GROUP_ENUM_ENTRY_RoProperties_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GROUP_ENUM_ENTRY_RoProperties__);
return offset;
}
static int
clusapi_dissect_element_GROUP_ENUM_ENTRY_RoProperties__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_GROUP_ENUM_ENTRY_RoProperties, 0);
return offset;
}
int
clusapi_dissect_struct_GROUP_ENUM_ENTRY(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_clusapi_GROUP_ENUM_ENTRY);
}
offset = clusapi_dissect_element_GROUP_ENUM_ENTRY_Name(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_GROUP_ENUM_ENTRY_Id(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_GROUP_ENUM_ENTRY_dwState(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_GROUP_ENUM_ENTRY_Owner(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_GROUP_ENUM_ENTRY_dwFlags(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_GROUP_ENUM_ENTRY_cbProperties(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_GROUP_ENUM_ENTRY_Properties(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_GROUP_ENUM_ENTRY_cbRoProperties(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_GROUP_ENUM_ENTRY_RoProperties(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
clusapi_dissect_element_RESOURCE_ENUM_ENTRY_Name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_RESOURCE_ENUM_ENTRY_Name_, NDR_POINTER_UNIQUE, "Pointer to Name (uint16)",hf_clusapi_RESOURCE_ENUM_ENTRY_Name);
return offset;
}
static int
clusapi_dissect_element_RESOURCE_ENUM_ENTRY_Name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_RESOURCE_ENUM_ENTRY_Name, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_RESOURCE_ENUM_ENTRY_Id(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_RESOURCE_ENUM_ENTRY_Id_, NDR_POINTER_UNIQUE, "Pointer to Id (uint16)",hf_clusapi_RESOURCE_ENUM_ENTRY_Id);
return offset;
}
static int
clusapi_dissect_element_RESOURCE_ENUM_ENTRY_Id_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_RESOURCE_ENUM_ENTRY_Id, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_RESOURCE_ENUM_ENTRY_OwnerName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_RESOURCE_ENUM_ENTRY_OwnerName_, NDR_POINTER_UNIQUE, "Pointer to OwnerName (uint16)",hf_clusapi_RESOURCE_ENUM_ENTRY_OwnerName);
return offset;
}
static int
clusapi_dissect_element_RESOURCE_ENUM_ENTRY_OwnerName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_RESOURCE_ENUM_ENTRY_OwnerName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_RESOURCE_ENUM_ENTRY_OwnerId(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_RESOURCE_ENUM_ENTRY_OwnerId_, NDR_POINTER_UNIQUE, "Pointer to OwnerId (uint16)",hf_clusapi_RESOURCE_ENUM_ENTRY_OwnerId);
return offset;
}
static int
clusapi_dissect_element_RESOURCE_ENUM_ENTRY_OwnerId_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_RESOURCE_ENUM_ENTRY_OwnerId, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_RESOURCE_ENUM_ENTRY_cbProperties(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_RESOURCE_ENUM_ENTRY_cbProperties, 0);
return offset;
}
static int
clusapi_dissect_element_RESOURCE_ENUM_ENTRY_Properties(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_RESOURCE_ENUM_ENTRY_Properties_, NDR_POINTER_UNIQUE, "Pointer to Properties (uint8)",hf_clusapi_RESOURCE_ENUM_ENTRY_Properties);
return offset;
}
static int
clusapi_dissect_element_RESOURCE_ENUM_ENTRY_Properties_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_RESOURCE_ENUM_ENTRY_Properties__);
return offset;
}
static int
clusapi_dissect_element_RESOURCE_ENUM_ENTRY_Properties__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_RESOURCE_ENUM_ENTRY_Properties, 0);
return offset;
}
static int
clusapi_dissect_element_RESOURCE_ENUM_ENTRY_cbRoProperties(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_RESOURCE_ENUM_ENTRY_cbRoProperties, 0);
return offset;
}
static int
clusapi_dissect_element_RESOURCE_ENUM_ENTRY_RoProperties(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_RESOURCE_ENUM_ENTRY_RoProperties_, NDR_POINTER_UNIQUE, "Pointer to RoProperties (uint8)",hf_clusapi_RESOURCE_ENUM_ENTRY_RoProperties);
return offset;
}
static int
clusapi_dissect_element_RESOURCE_ENUM_ENTRY_RoProperties_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_RESOURCE_ENUM_ENTRY_RoProperties__);
return offset;
}
static int
clusapi_dissect_element_RESOURCE_ENUM_ENTRY_RoProperties__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_RESOURCE_ENUM_ENTRY_RoProperties, 0);
return offset;
}
int
clusapi_dissect_struct_RESOURCE_ENUM_ENTRY(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_clusapi_RESOURCE_ENUM_ENTRY);
}
offset = clusapi_dissect_element_RESOURCE_ENUM_ENTRY_Name(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_RESOURCE_ENUM_ENTRY_Id(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_RESOURCE_ENUM_ENTRY_OwnerName(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_RESOURCE_ENUM_ENTRY_OwnerId(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_RESOURCE_ENUM_ENTRY_cbProperties(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_RESOURCE_ENUM_ENTRY_Properties(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_RESOURCE_ENUM_ENTRY_cbRoProperties(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_RESOURCE_ENUM_ENTRY_RoProperties(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
clusapi_dissect_element_GROUP_ENUM_LIST_EntryCount(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_GROUP_ENUM_LIST_EntryCount, 0);
return offset;
}
static int
clusapi_dissect_element_GROUP_ENUM_LIST_Entry(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GROUP_ENUM_LIST_Entry_);
return offset;
}
static int
clusapi_dissect_element_GROUP_ENUM_LIST_Entry_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_struct_GROUP_ENUM_ENTRY(tvb,offset,pinfo,tree,di,drep,hf_clusapi_GROUP_ENUM_LIST_Entry,0);
return offset;
}
int
clusapi_dissect_struct_GROUP_ENUM_LIST(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_clusapi_GROUP_ENUM_LIST);
}
offset = clusapi_dissect_element_GROUP_ENUM_LIST_EntryCount(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_GROUP_ENUM_LIST_Entry(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
clusapi_dissect_element_RESOURCE_ENUM_LIST_EntryCount(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_RESOURCE_ENUM_LIST_EntryCount, 0);
return offset;
}
static int
clusapi_dissect_element_RESOURCE_ENUM_LIST_Entry(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_RESOURCE_ENUM_LIST_Entry_);
return offset;
}
static int
clusapi_dissect_element_RESOURCE_ENUM_LIST_Entry_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_struct_RESOURCE_ENUM_ENTRY(tvb,offset,pinfo,tree,di,drep,hf_clusapi_RESOURCE_ENUM_LIST_Entry,0);
return offset;
}
int
clusapi_dissect_struct_RESOURCE_ENUM_LIST(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_clusapi_RESOURCE_ENUM_LIST);
}
offset = clusapi_dissect_element_RESOURCE_ENUM_LIST_EntryCount(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_RESOURCE_ENUM_LIST_Entry(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
int
clusapi_dissect_enum_CreateResourceFlags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
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
clusapi_dissect_enum_ClusterResourceState(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
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
clusapi_dissect_enum_ClusterGroupState(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
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
clusapi_dissect_bitmap_ClusterGroupEnumType(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item;
static const int * clusapi_ClusterGroupEnumType_fields[] = {
&hf_clusapi_ClusterGroupEnumType_CLUSTER_GROUP_ENUM_CONTAINS,
&hf_clusapi_ClusterGroupEnumType_CLUSTER_GROUP_ENUM_NODES,
NULL
};
guint32 flags;
ALIGN_TO_4_BYTES;
item = proto_tree_add_bitmask_with_flags(parent_tree, tvb, offset, hf_index,
ett_clusapi_ClusterGroupEnumType, clusapi_ClusterGroupEnumType_fields, DREP_ENC_INTEGER(drep), BMT_NO_FALSE);
offset = dissect_ndr_uint32(tvb, offset, pinfo, parent_tree, di, drep, -1, &flags);
if (!flags)
proto_item_append_text(item, ": (No values set)");
if (flags & (~0x00000003)) {
flags &= (~0x00000003);
proto_item_append_text(item, "Unknown bitmap value 0x%x", flags);
}
return offset;
}
int
clusapi_dissect_enum_ClusterNodeState(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
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
clusapi_dissect_enum_ResourceClass(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
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
clusapi_dissect_element_CLUS_RESOURCE_CLASS_INFO_Class(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_enum_ResourceClass(tvb, offset, pinfo, tree, di, drep, hf_clusapi_CLUS_RESOURCE_CLASS_INFO_Class, 0);
return offset;
}
static int
clusapi_dissect_element_CLUS_RESOURCE_CLASS_INFO_SubClass(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_CLUS_RESOURCE_CLASS_INFO_SubClass, 0);
return offset;
}
int
clusapi_dissect_struct_CLUS_RESOURCE_CLASS_INFO(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_clusapi_CLUS_RESOURCE_CLASS_INFO);
}
offset = clusapi_dissect_element_CLUS_RESOURCE_CLASS_INFO_Class(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_CLUS_RESOURCE_CLASS_INFO_SubClass(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
int
clusapi_dissect_enum_ResourceControlCode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
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
clusapi_dissect_enum_ResourceTypeControlCode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
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
clusapi_dissect_enum_GroupControlCode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
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
clusapi_dissect_enum_NodeControlCode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
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
clusapi_dissect_enum_ClusterNetworkState(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
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
clusapi_dissect_enum_ClusterNetInterfaceState(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
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
clusapi_dissect_bitmap_ClusterResTypeEnumType(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item;
static const int * clusapi_ClusterResTypeEnumType_fields[] = {
&hf_clusapi_ClusterResTypeEnumType_CLUSTER_RESOURCE_TYPE_ENUM_NODES,
&hf_clusapi_ClusterResTypeEnumType_CLUSTER_RESOURCE_TYPE_ENUM_RESOURCES,
NULL
};
guint32 flags;
ALIGN_TO_4_BYTES;
item = proto_tree_add_bitmask_with_flags(parent_tree, tvb, offset, hf_index,
ett_clusapi_ClusterResTypeEnumType, clusapi_ClusterResTypeEnumType_fields, DREP_ENC_INTEGER(drep), BMT_NO_FALSE);
offset = dissect_ndr_uint32(tvb, offset, pinfo, parent_tree, di, drep, -1, &flags);
if (!flags)
proto_item_append_text(item, ": (No values set)");
if (flags & (~0x00000003)) {
flags &= (~0x00000003);
proto_item_append_text(item, "Unknown bitmap value 0x%x", flags);
}
return offset;
}
int
clusapi_dissect_enum_ClusterControlCode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
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
clusapi_dissect_enum_CLUSTER_PROPERTY_SYNTAX(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
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
clusapi_dissect_bitmap_DesiredAccessMask(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item;
static const int * clusapi_clusapi_DesiredAccessMask_fields[] = {
&hf_clusapi_clusapi_DesiredAccessMask_CLUSAPI_READ_ACCESS,
&hf_clusapi_clusapi_DesiredAccessMask_CLUSAPI_CHANGE_ACCESS,
&hf_clusapi_clusapi_DesiredAccessMask_CLUSAPI_GENERIC_READ,
&hf_clusapi_clusapi_DesiredAccessMask_CLUSAPI_GENERIC_WRITE,
&hf_clusapi_clusapi_DesiredAccessMask_CLUSAPI_GENERIC_EXECUTE,
&hf_clusapi_clusapi_DesiredAccessMask_CLUSAPI_GENERIC_ALL,
&hf_clusapi_clusapi_DesiredAccessMask_CLUSAPI_MAXIMUM_ALLOWED,
NULL
};
guint32 flags;
ALIGN_TO_4_BYTES;
item = proto_tree_add_bitmask_with_flags(parent_tree, tvb, offset, hf_index,
ett_clusapi_clusapi_DesiredAccessMask, clusapi_clusapi_DesiredAccessMask_fields, DREP_ENC_INTEGER(drep), BMT_NO_FALSE);
offset = dissect_ndr_uint32(tvb, offset, pinfo, parent_tree, di, drep, -1, &flags);
if (!flags)
proto_item_append_text(item, ": (No values set)");
if (flags & (~0xf2000003)) {
flags &= (~0xf2000003);
proto_item_append_text(item, "Unknown bitmap value 0x%x", flags);
}
return offset;
}
static int
clusapi_dissect_element_NOTIFY_FILTER_AND_TYPE_RPC_dwObjectType(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_NOTIFY_FILTER_AND_TYPE_RPC_dwObjectType, 0);
return offset;
}
static int
clusapi_dissect_element_NOTIFY_FILTER_AND_TYPE_RPC_FilterFlags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uint64(tvb, offset, pinfo, tree, di, drep, hf_clusapi_NOTIFY_FILTER_AND_TYPE_RPC_FilterFlags, NULL);
return offset;
}
int
clusapi_dissect_struct_NOTIFY_FILTER_AND_TYPE_RPC(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_8_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_clusapi_NOTIFY_FILTER_AND_TYPE_RPC);
}
offset = clusapi_dissect_element_NOTIFY_FILTER_AND_TYPE_RPC_dwObjectType(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_NOTIFY_FILTER_AND_TYPE_RPC_FilterFlags(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_8_BYTES;
}
return offset;
}
static int
clusapi_dissect_element_NOTIFICATION_DATA_RPC_FilterAndType(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_struct_NOTIFY_FILTER_AND_TYPE_RPC(tvb,offset,pinfo,tree,di,drep,hf_clusapi_NOTIFICATION_DATA_RPC_FilterAndType,0);
return offset;
}
static int
clusapi_dissect_element_NOTIFICATION_DATA_RPC_buffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NOTIFICATION_DATA_RPC_buffer_, NDR_POINTER_UNIQUE, "Pointer to Buffer (uint8)",hf_clusapi_NOTIFICATION_DATA_RPC_buffer);
return offset;
}
static int
clusapi_dissect_element_NOTIFICATION_DATA_RPC_buffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NOTIFICATION_DATA_RPC_buffer__);
return offset;
}
static int
clusapi_dissect_element_NOTIFICATION_DATA_RPC_buffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_NOTIFICATION_DATA_RPC_buffer, 0);
return offset;
}
static int
clusapi_dissect_element_NOTIFICATION_DATA_RPC_dwBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_NOTIFICATION_DATA_RPC_dwBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_NOTIFICATION_DATA_RPC_ObjectId(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NOTIFICATION_DATA_RPC_ObjectId_, NDR_POINTER_UNIQUE, "Pointer to ObjectId (uint16)",hf_clusapi_NOTIFICATION_DATA_RPC_ObjectId);
return offset;
}
static int
clusapi_dissect_element_NOTIFICATION_DATA_RPC_ObjectId_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_NOTIFICATION_DATA_RPC_ObjectId, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_NOTIFICATION_DATA_RPC_ParentId(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NOTIFICATION_DATA_RPC_ParentId_, NDR_POINTER_UNIQUE, "Pointer to ParentId (uint16)",hf_clusapi_NOTIFICATION_DATA_RPC_ParentId);
return offset;
}
static int
clusapi_dissect_element_NOTIFICATION_DATA_RPC_ParentId_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_NOTIFICATION_DATA_RPC_ParentId, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_NOTIFICATION_DATA_RPC_Name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NOTIFICATION_DATA_RPC_Name_, NDR_POINTER_UNIQUE, "Pointer to Name (uint16)",hf_clusapi_NOTIFICATION_DATA_RPC_Name);
return offset;
}
static int
clusapi_dissect_element_NOTIFICATION_DATA_RPC_Name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_NOTIFICATION_DATA_RPC_Name, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_NOTIFICATION_DATA_RPC_Type(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NOTIFICATION_DATA_RPC_Type_, NDR_POINTER_UNIQUE, "Pointer to Type (uint16)",hf_clusapi_NOTIFICATION_DATA_RPC_Type);
return offset;
}
static int
clusapi_dissect_element_NOTIFICATION_DATA_RPC_Type_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_NOTIFICATION_DATA_RPC_Type, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
int
clusapi_dissect_struct_NOTIFICATION_DATA_RPC(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_8_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_clusapi_NOTIFICATION_DATA_RPC);
}
offset = clusapi_dissect_element_NOTIFICATION_DATA_RPC_FilterAndType(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_NOTIFICATION_DATA_RPC_buffer(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_NOTIFICATION_DATA_RPC_dwBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_NOTIFICATION_DATA_RPC_ObjectId(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_NOTIFICATION_DATA_RPC_ParentId(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_NOTIFICATION_DATA_RPC_Name(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_NOTIFICATION_DATA_RPC_Type(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_8_BYTES;
}
return offset;
}
static int
clusapi_dissect_element_NOTIFICATION_RPC_dwNotifyKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NOTIFICATION_RPC_dwNotifyKey_, NDR_POINTER_UNIQUE, "Pointer to DwNotifyKey (uint32)",hf_clusapi_NOTIFICATION_RPC_dwNotifyKey);
return offset;
}
static int
clusapi_dissect_element_NOTIFICATION_RPC_dwNotifyKey_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_NOTIFICATION_RPC_dwNotifyKey, 0);
return offset;
}
static int
clusapi_dissect_element_NOTIFICATION_RPC_NotificationData(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_struct_NOTIFICATION_DATA_RPC(tvb,offset,pinfo,tree,di,drep,hf_clusapi_NOTIFICATION_RPC_NotificationData,0);
return offset;
}
int
clusapi_dissect_struct_NOTIFICATION_RPC(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_8_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_clusapi_NOTIFICATION_RPC);
}
offset = clusapi_dissect_element_NOTIFICATION_RPC_dwNotifyKey(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_NOTIFICATION_RPC_NotificationData(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_8_BYTES;
}
return offset;
}
static int
clusapi_dissect_element_CLUSTER_DISKID_DiskIdType(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_CLUSTER_DISKID_DiskIdType, 0);
return offset;
}
static int
clusapi_dissect_element_CLUSTER_DISKID_DiskIdBlob(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
int i;
for (i = 0; i < 16; i++)
offset = clusapi_dissect_element_CLUSTER_DISKID_DiskIdBlob_(tvb, offset, pinfo, tree, di, drep);
return offset;
}
static int
clusapi_dissect_element_CLUSTER_DISKID_DiskIdBlob_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_CLUSTER_DISKID_DiskIdBlob, 0);
return offset;
}
int
clusapi_dissect_struct_CLUSTER_DISKID(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_clusapi_CLUSTER_DISKID);
}
offset = clusapi_dissect_element_CLUSTER_DISKID_DiskIdType(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_CLUSTER_DISKID_DiskIdBlob(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
static int
clusapi_dissect_element_CLUSTER_MRR_NODE_RESPONSE_pszNodeName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CLUSTER_MRR_NODE_RESPONSE_pszNodeName_, NDR_POINTER_UNIQUE, "Pointer to PszNodeName (uint16)",hf_clusapi_CLUSTER_MRR_NODE_RESPONSE_pszNodeName);
return offset;
}
static int
clusapi_dissect_element_CLUSTER_MRR_NODE_RESPONSE_pszNodeName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_CLUSTER_MRR_NODE_RESPONSE_pszNodeName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_CLUSTER_MRR_NODE_RESPONSE_ResultCode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_CLUSTER_MRR_NODE_RESPONSE_ResultCode, 0);
return offset;
}
static int
clusapi_dissect_element_CLUSTER_MRR_NODE_RESPONSE_ResultSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_CLUSTER_MRR_NODE_RESPONSE_ResultSize, 0);
return offset;
}
static int
clusapi_dissect_element_CLUSTER_MRR_NODE_RESPONSE_pResultData(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CLUSTER_MRR_NODE_RESPONSE_pResultData_, NDR_POINTER_UNIQUE, "Pointer to PResultData (uint8)",hf_clusapi_CLUSTER_MRR_NODE_RESPONSE_pResultData);
return offset;
}
static int
clusapi_dissect_element_CLUSTER_MRR_NODE_RESPONSE_pResultData_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CLUSTER_MRR_NODE_RESPONSE_pResultData__);
return offset;
}
static int
clusapi_dissect_element_CLUSTER_MRR_NODE_RESPONSE_pResultData__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_CLUSTER_MRR_NODE_RESPONSE_pResultData, 0);
return offset;
}
int
clusapi_dissect_struct_CLUSTER_MRR_NODE_RESPONSE(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_clusapi_CLUSTER_MRR_NODE_RESPONSE);
}
offset = clusapi_dissect_element_CLUSTER_MRR_NODE_RESPONSE_pszNodeName(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_CLUSTER_MRR_NODE_RESPONSE_ResultCode(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_CLUSTER_MRR_NODE_RESPONSE_ResultSize(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_CLUSTER_MRR_NODE_RESPONSE_pResultData(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
clusapi_dissect_element_CLUSTER_MRR_RESPONSE_NodeCount(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_CLUSTER_MRR_RESPONSE_NodeCount, 0);
return offset;
}
static int
clusapi_dissect_element_CLUSTER_MRR_RESPONSE_pNodes(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CLUSTER_MRR_RESPONSE_pNodes_, NDR_POINTER_UNIQUE, "Pointer to PNodes (CLUSTER_MRR_NODE_RESPONSE)",hf_clusapi_CLUSTER_MRR_RESPONSE_pNodes);
return offset;
}
static int
clusapi_dissect_element_CLUSTER_MRR_RESPONSE_pNodes_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CLUSTER_MRR_RESPONSE_pNodes__);
return offset;
}
static int
clusapi_dissect_element_CLUSTER_MRR_RESPONSE_pNodes__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_struct_CLUSTER_MRR_NODE_RESPONSE(tvb,offset,pinfo,tree,di,drep,hf_clusapi_CLUSTER_MRR_RESPONSE_pNodes,0);
return offset;
}
int
clusapi_dissect_struct_CLUSTER_MRR_RESPONSE(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_clusapi_CLUSTER_MRR_RESPONSE);
}
offset = clusapi_dissect_element_CLUSTER_MRR_RESPONSE_NodeCount(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_CLUSTER_MRR_RESPONSE_pNodes(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
clusapi_dissect_element_NOTIFICATION_DATA_ASYNC_RPC_dwNotifyKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_NOTIFICATION_DATA_ASYNC_RPC_dwNotifyKey, 0);
return offset;
}
static int
clusapi_dissect_element_NOTIFICATION_DATA_ASYNC_RPC_dwFilter(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_NOTIFICATION_DATA_ASYNC_RPC_dwFilter, 0);
return offset;
}
static int
clusapi_dissect_element_NOTIFICATION_DATA_ASYNC_RPC_Name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NOTIFICATION_DATA_ASYNC_RPC_Name_, NDR_POINTER_UNIQUE, "Pointer to Name (uint16)",hf_clusapi_NOTIFICATION_DATA_ASYNC_RPC_Name);
return offset;
}
static int
clusapi_dissect_element_NOTIFICATION_DATA_ASYNC_RPC_Name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_NOTIFICATION_DATA_ASYNC_RPC_Name, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
int
clusapi_dissect_struct_NOTIFICATION_DATA_ASYNC_RPC(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_clusapi_NOTIFICATION_DATA_ASYNC_RPC);
}
offset = clusapi_dissect_element_NOTIFICATION_DATA_ASYNC_RPC_dwNotifyKey(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_NOTIFICATION_DATA_ASYNC_RPC_dwFilter(tvb, offset, pinfo, tree, di, drep);
offset = clusapi_dissect_element_NOTIFICATION_DATA_ASYNC_RPC_Name(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
int
clusapi_dissect_enum_CLUSDSK_DISKID_ENUM(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint1632 *param _U_)
{
guint1632 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
int
clusapi_dissect_enum_CLUSTER_PROPERTY_TYPE(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint1632 *param _U_)
{
guint1632 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
int
clusapi_dissect_enum_CLUSTER_PROPERTY_FORMAT(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint1632 *param _U_)
{
guint1632 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
int
clusapi_dissect_enum_CLUS_CHARACTERISTICS(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint1632 *param _U_)
{
guint1632 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
int
clusapi_dissect_enum_CLUS_FLAGS(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint1632 *param _U_)
{
guint1632 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
int
clusapi_dissect_enum_MAINTENANCE_MODE_TYPE(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint1632 *param _U_)
{
guint1632 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
int
clusapi_dissect_enum_CLUSTER_CHANGE(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint1632 *param _U_)
{
guint1632 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
int
clusapi_dissect_enum_CLUSTER_REG_BATCH_COMMAND(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint1632 *param _U_)
{
guint1632 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
int
clusapi_dissect_enum_CLUSTER_QUORUM_VALUE(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint1632 *param _U_)
{
guint1632 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
int
clusapi_dissect_enum_CLUSTER_OBJECT_TYPE(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint1632 *param _U_)
{
guint1632 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
int
clusapi_dissect_enum_CLUSTER_CHANGE_CLUSTER_V2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint1632 *param _U_)
{
guint1632 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
int
clusapi_dissect_enum_CLUSTER_CHANGE_GROUP_V2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint1632 *param _U_)
{
guint1632 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
int
clusapi_dissect_enum_CLUSTER_CHANGE_RESOURCE_V2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint1632 *param _U_)
{
guint1632 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
int
clusapi_dissect_enum_CHANGE_RESOURCE_TYPE_V2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint1632 *param _U_)
{
guint1632 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
int
clusapi_dissect_enum_CLUSTER_CHANGE_NETINTERFACE_V2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint1632 *param _U_)
{
guint1632 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
int
clusapi_dissect_enum_CLUSTER_CHANGE_NETWORK_V2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint1632 *param _U_)
{
guint1632 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
int
clusapi_dissect_enum_CLUSTER_CHANGE_NODE_V2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint1632 *param _U_)
{
guint1632 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
int
clusapi_dissect_enum_CLUSTER_CHANGE_REGISTRY_V2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint1632 *param _U_)
{
guint1632 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
int
clusapi_dissect_enum_CLUSTER_CHANGE_QUORUM_V2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint1632 *param _U_)
{
guint1632 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
int
clusapi_dissect_enum_CLUSTER_CHANGE_SHARED_VOLUME_V2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint1632 *param _U_)
{
guint1632 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
static int
clusapi_dissect_element_OpenCluster_Status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenCluster_Status_, NDR_POINTER_REF, "Pointer to Status (WERROR)",hf_clusapi_clusapi_OpenCluster_Status);
return offset;
}
static int
clusapi_dissect_element_OpenCluster_Status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenCluster_Status, 0);
return offset;
}
static int
clusapi_dissect_element_OpenCluster_Cluster(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenCluster_Cluster_, NDR_POINTER_REF, "Pointer to Cluster (policy_handle)",hf_clusapi_clusapi_OpenCluster_Cluster);
return offset;
}
static int
clusapi_dissect_element_OpenCluster_Cluster_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenCluster_Cluster, 0);
return offset;
}
static int
clusapi_dissect_OpenCluster_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OpenCluster";
offset = clusapi_dissect_element_OpenCluster_Status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenCluster_Cluster(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_OpenCluster_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OpenCluster";
return offset;
}
static int
clusapi_dissect_element_CloseCluster_Cluster(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CloseCluster_Cluster_, NDR_POINTER_REF, "Pointer to Cluster (policy_handle)",hf_clusapi_clusapi_CloseCluster_Cluster);
return offset;
}
static int
clusapi_dissect_element_CloseCluster_Cluster_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CloseCluster_Cluster, 0);
return offset;
}
static int
clusapi_dissect_CloseCluster_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="CloseCluster";
offset = clusapi_dissect_element_CloseCluster_Cluster(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_CloseCluster_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CloseCluster";
offset = clusapi_dissect_element_CloseCluster_Cluster(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_SetClusterName_NewClusterName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_SetClusterName_NewClusterName_, NDR_POINTER_REF, "Pointer to NewClusterName (uint16)",hf_clusapi_clusapi_SetClusterName_NewClusterName);
return offset;
}
static int
clusapi_dissect_element_SetClusterName_NewClusterName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_SetClusterName_NewClusterName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_SetClusterName_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_SetClusterName_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_SetClusterName_rpc_status);
return offset;
}
static int
clusapi_dissect_element_SetClusterName_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_SetClusterName_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_SetClusterName_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="SetClusterName";
offset = clusapi_dissect_element_SetClusterName_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_SetClusterName_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="SetClusterName";
offset = clusapi_dissect_element_SetClusterName_NewClusterName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_GetClusterName_ClusterName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetClusterName_ClusterName_, NDR_POINTER_REF, "Pointer to ClusterName (uint16)",hf_clusapi_clusapi_GetClusterName_ClusterName);
return offset;
}
static int
clusapi_dissect_element_GetClusterName_ClusterName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetClusterName_ClusterName__, NDR_POINTER_UNIQUE, "Pointer to ClusterName (uint16)",hf_clusapi_clusapi_GetClusterName_ClusterName);
return offset;
}
static int
clusapi_dissect_element_GetClusterName_ClusterName__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_GetClusterName_ClusterName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_GetClusterName_NodeName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetClusterName_NodeName_, NDR_POINTER_REF, "Pointer to NodeName (uint16)",hf_clusapi_clusapi_GetClusterName_NodeName);
return offset;
}
static int
clusapi_dissect_element_GetClusterName_NodeName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetClusterName_NodeName__, NDR_POINTER_UNIQUE, "Pointer to NodeName (uint16)",hf_clusapi_clusapi_GetClusterName_NodeName);
return offset;
}
static int
clusapi_dissect_element_GetClusterName_NodeName__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_GetClusterName_NodeName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_GetClusterName_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="GetClusterName";
offset = clusapi_dissect_element_GetClusterName_ClusterName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetClusterName_NodeName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_GetClusterName_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="GetClusterName";
return offset;
}
static int
clusapi_dissect_element_GetClusterVersion_lpwMajorVersion(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetClusterVersion_lpwMajorVersion_, NDR_POINTER_REF, "Pointer to LpwMajorVersion (uint16)",hf_clusapi_clusapi_GetClusterVersion_lpwMajorVersion);
return offset;
}
static int
clusapi_dissect_element_GetClusterVersion_lpwMajorVersion_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetClusterVersion_lpwMajorVersion, 0);
return offset;
}
static int
clusapi_dissect_element_GetClusterVersion_lpwMinorVersion(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetClusterVersion_lpwMinorVersion_, NDR_POINTER_REF, "Pointer to LpwMinorVersion (uint16)",hf_clusapi_clusapi_GetClusterVersion_lpwMinorVersion);
return offset;
}
static int
clusapi_dissect_element_GetClusterVersion_lpwMinorVersion_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetClusterVersion_lpwMinorVersion, 0);
return offset;
}
static int
clusapi_dissect_element_GetClusterVersion_lpwBuildNumber(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetClusterVersion_lpwBuildNumber_, NDR_POINTER_REF, "Pointer to LpwBuildNumber (uint16)",hf_clusapi_clusapi_GetClusterVersion_lpwBuildNumber);
return offset;
}
static int
clusapi_dissect_element_GetClusterVersion_lpwBuildNumber_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetClusterVersion_lpwBuildNumber, 0);
return offset;
}
static int
clusapi_dissect_element_GetClusterVersion_lpszVendorId(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetClusterVersion_lpszVendorId_, NDR_POINTER_REF, "Pointer to LpszVendorId (uint16)",hf_clusapi_clusapi_GetClusterVersion_lpszVendorId);
return offset;
}
static int
clusapi_dissect_element_GetClusterVersion_lpszVendorId_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetClusterVersion_lpszVendorId__, NDR_POINTER_UNIQUE, "Pointer to LpszVendorId (uint16)",hf_clusapi_clusapi_GetClusterVersion_lpszVendorId);
return offset;
}
static int
clusapi_dissect_element_GetClusterVersion_lpszVendorId__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_GetClusterVersion_lpszVendorId, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_GetClusterVersion_lpszCSDVersion(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetClusterVersion_lpszCSDVersion_, NDR_POINTER_REF, "Pointer to LpszCSDVersion (uint16)",hf_clusapi_clusapi_GetClusterVersion_lpszCSDVersion);
return offset;
}
static int
clusapi_dissect_element_GetClusterVersion_lpszCSDVersion_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetClusterVersion_lpszCSDVersion__, NDR_POINTER_UNIQUE, "Pointer to LpszCSDVersion (uint16)",hf_clusapi_clusapi_GetClusterVersion_lpszCSDVersion);
return offset;
}
static int
clusapi_dissect_element_GetClusterVersion_lpszCSDVersion__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_GetClusterVersion_lpszCSDVersion, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_GetClusterVersion_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="GetClusterVersion";
offset = clusapi_dissect_element_GetClusterVersion_lpwMajorVersion(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetClusterVersion_lpwMinorVersion(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetClusterVersion_lpwBuildNumber(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetClusterVersion_lpszVendorId(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetClusterVersion_lpszCSDVersion(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_GetClusterVersion_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="GetClusterVersion";
return offset;
}
static int
clusapi_dissect_element_GetQuorumResource_lpszResourceName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetQuorumResource_lpszResourceName_, NDR_POINTER_REF, "Pointer to LpszResourceName (uint16)",hf_clusapi_clusapi_GetQuorumResource_lpszResourceName);
return offset;
}
static int
clusapi_dissect_element_GetQuorumResource_lpszResourceName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetQuorumResource_lpszResourceName__, NDR_POINTER_UNIQUE, "Pointer to LpszResourceName (uint16)",hf_clusapi_clusapi_GetQuorumResource_lpszResourceName);
return offset;
}
static int
clusapi_dissect_element_GetQuorumResource_lpszResourceName__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_GetQuorumResource_lpszResourceName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_GetQuorumResource_lpszDeviceName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetQuorumResource_lpszDeviceName_, NDR_POINTER_REF, "Pointer to LpszDeviceName (uint16)",hf_clusapi_clusapi_GetQuorumResource_lpszDeviceName);
return offset;
}
static int
clusapi_dissect_element_GetQuorumResource_lpszDeviceName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetQuorumResource_lpszDeviceName__, NDR_POINTER_UNIQUE, "Pointer to LpszDeviceName (uint16)",hf_clusapi_clusapi_GetQuorumResource_lpszDeviceName);
return offset;
}
static int
clusapi_dissect_element_GetQuorumResource_lpszDeviceName__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_GetQuorumResource_lpszDeviceName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_GetQuorumResource_pdwMaxQuorumLogSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetQuorumResource_pdwMaxQuorumLogSize_, NDR_POINTER_REF, "Pointer to PdwMaxQuorumLogSize (uint32)",hf_clusapi_clusapi_GetQuorumResource_pdwMaxQuorumLogSize);
return offset;
}
static int
clusapi_dissect_element_GetQuorumResource_pdwMaxQuorumLogSize_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetQuorumResource_pdwMaxQuorumLogSize, 0);
return offset;
}
static int
clusapi_dissect_element_GetQuorumResource_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetQuorumResource_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_GetQuorumResource_rpc_status);
return offset;
}
static int
clusapi_dissect_element_GetQuorumResource_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetQuorumResource_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_GetQuorumResource_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="GetQuorumResource";
offset = clusapi_dissect_element_GetQuorumResource_lpszResourceName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetQuorumResource_lpszDeviceName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetQuorumResource_pdwMaxQuorumLogSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetQuorumResource_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_GetQuorumResource_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="GetQuorumResource";
return offset;
}
static int
clusapi_dissect_element_SetQuorumResource_hResource(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_SetQuorumResource_hResource, 0);
return offset;
}
static int
clusapi_dissect_element_SetQuorumResource_lpszDeviceName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_SetQuorumResource_lpszDeviceName_, NDR_POINTER_REF, "Pointer to LpszDeviceName (uint16)",hf_clusapi_clusapi_SetQuorumResource_lpszDeviceName);
return offset;
}
static int
clusapi_dissect_element_SetQuorumResource_lpszDeviceName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_SetQuorumResource_lpszDeviceName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_SetQuorumResource_dwMaxQuorumLogSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_SetQuorumResource_dwMaxQuorumLogSize, 0);
return offset;
}
static int
clusapi_dissect_element_SetQuorumResource_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_SetQuorumResource_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_SetQuorumResource_rpc_status);
return offset;
}
static int
clusapi_dissect_element_SetQuorumResource_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_SetQuorumResource_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_SetQuorumResource_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="SetQuorumResource";
offset = clusapi_dissect_element_SetQuorumResource_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_SetQuorumResource_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="SetQuorumResource";
offset = clusapi_dissect_element_SetQuorumResource_hResource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_SetQuorumResource_lpszDeviceName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_SetQuorumResource_dwMaxQuorumLogSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_CreateEnum_dwType(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_bitmap_ClusterEnumType(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateEnum_dwType, 0);
return offset;
}
static int
clusapi_dissect_element_CreateEnum_ReturnEnum(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateEnum_ReturnEnum_, NDR_POINTER_REF, "Pointer to ReturnEnum (ENUM_LIST)",hf_clusapi_clusapi_CreateEnum_ReturnEnum);
return offset;
}
static int
clusapi_dissect_element_CreateEnum_ReturnEnum_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateEnum_ReturnEnum__, NDR_POINTER_UNIQUE, "Pointer to ReturnEnum (ENUM_LIST)",hf_clusapi_clusapi_CreateEnum_ReturnEnum);
return offset;
}
static int
clusapi_dissect_element_CreateEnum_ReturnEnum__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_struct_ENUM_LIST(tvb,offset,pinfo,tree,di,drep,hf_clusapi_clusapi_CreateEnum_ReturnEnum,0);
return offset;
}
static int
clusapi_dissect_element_CreateEnum_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateEnum_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_CreateEnum_rpc_status);
return offset;
}
static int
clusapi_dissect_element_CreateEnum_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateEnum_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_CreateEnum_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="CreateEnum";
offset = clusapi_dissect_element_CreateEnum_ReturnEnum(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateEnum_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_CreateEnum_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CreateEnum";
offset = clusapi_dissect_element_CreateEnum_dwType(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_OpenResource_lpszResourceName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenResource_lpszResourceName_, NDR_POINTER_REF, "Pointer to LpszResourceName (uint16)",hf_clusapi_clusapi_OpenResource_lpszResourceName);
return offset;
}
static int
clusapi_dissect_element_OpenResource_lpszResourceName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_OpenResource_lpszResourceName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_OpenResource_Status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenResource_Status_, NDR_POINTER_REF, "Pointer to Status (WERROR)",hf_clusapi_clusapi_OpenResource_Status);
return offset;
}
static int
clusapi_dissect_element_OpenResource_Status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenResource_Status, 0);
return offset;
}
static int
clusapi_dissect_element_OpenResource_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenResource_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_OpenResource_rpc_status);
return offset;
}
static int
clusapi_dissect_element_OpenResource_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenResource_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_element_OpenResource_hResource(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenResource_hResource_, NDR_POINTER_REF, "Pointer to HResource (policy_handle)",hf_clusapi_clusapi_OpenResource_hResource);
return offset;
}
static int
clusapi_dissect_element_OpenResource_hResource_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenResource_hResource, 0);
return offset;
}
static int
clusapi_dissect_OpenResource_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OpenResource";
offset = clusapi_dissect_element_OpenResource_Status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenResource_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenResource_hResource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_OpenResource_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OpenResource";
offset = clusapi_dissect_element_OpenResource_lpszResourceName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_CreateResource_hGroup(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateResource_hGroup, 0);
return offset;
}
static int
clusapi_dissect_element_CreateResource_lpszResourceName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateResource_lpszResourceName_, NDR_POINTER_REF, "Pointer to LpszResourceName (uint16)",hf_clusapi_clusapi_CreateResource_lpszResourceName);
return offset;
}
static int
clusapi_dissect_element_CreateResource_lpszResourceName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_CreateResource_lpszResourceName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_CreateResource_lpszResourceType(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateResource_lpszResourceType_, NDR_POINTER_REF, "Pointer to LpszResourceType (uint16)",hf_clusapi_clusapi_CreateResource_lpszResourceType);
return offset;
}
static int
clusapi_dissect_element_CreateResource_lpszResourceType_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_CreateResource_lpszResourceType, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_CreateResource_dwFlags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_enum_CreateResourceFlags(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateResource_dwFlags, 0);
return offset;
}
static int
clusapi_dissect_element_CreateResource_Status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateResource_Status_, NDR_POINTER_REF, "Pointer to Status (WERROR)",hf_clusapi_clusapi_CreateResource_Status);
return offset;
}
static int
clusapi_dissect_element_CreateResource_Status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateResource_Status, 0);
return offset;
}
static int
clusapi_dissect_element_CreateResource_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateResource_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_CreateResource_rpc_status);
return offset;
}
static int
clusapi_dissect_element_CreateResource_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateResource_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_element_CreateResource_hResource(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateResource_hResource_, NDR_POINTER_REF, "Pointer to HResource (policy_handle)",hf_clusapi_clusapi_CreateResource_hResource);
return offset;
}
static int
clusapi_dissect_element_CreateResource_hResource_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateResource_hResource, 0);
return offset;
}
static int
clusapi_dissect_CreateResource_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CreateResource";
offset = clusapi_dissect_element_CreateResource_Status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateResource_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateResource_hResource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_CreateResource_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CreateResource";
offset = clusapi_dissect_element_CreateResource_hGroup(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateResource_lpszResourceName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateResource_lpszResourceType(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateResource_dwFlags(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_DeleteResource_hResource(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_DeleteResource_hResource, 0);
return offset;
}
static int
clusapi_dissect_element_DeleteResource_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_DeleteResource_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_DeleteResource_rpc_status);
return offset;
}
static int
clusapi_dissect_element_DeleteResource_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_DeleteResource_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_DeleteResource_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="DeleteResource";
offset = clusapi_dissect_element_DeleteResource_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_DeleteResource_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="DeleteResource";
offset = clusapi_dissect_element_DeleteResource_hResource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_CloseResource_Resource(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CloseResource_Resource_, NDR_POINTER_REF, "Pointer to Resource (policy_handle)",hf_clusapi_clusapi_CloseResource_Resource);
return offset;
}
static int
clusapi_dissect_element_CloseResource_Resource_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CloseResource_Resource, 0);
return offset;
}
static int
clusapi_dissect_CloseResource_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="CloseResource";
offset = clusapi_dissect_element_CloseResource_Resource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_CloseResource_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CloseResource";
offset = clusapi_dissect_element_CloseResource_Resource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_GetResourceState_hResource(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetResourceState_hResource, 0);
return offset;
}
static int
clusapi_dissect_element_GetResourceState_State(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetResourceState_State_, NDR_POINTER_REF, "Pointer to State (clusapi_ClusterResourceState)",hf_clusapi_clusapi_GetResourceState_State);
return offset;
}
static int
clusapi_dissect_element_GetResourceState_State_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_enum_ClusterResourceState(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetResourceState_State, 0);
return offset;
}
static int
clusapi_dissect_element_GetResourceState_NodeName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetResourceState_NodeName_, NDR_POINTER_REF, "Pointer to NodeName (uint16)",hf_clusapi_clusapi_GetResourceState_NodeName);
return offset;
}
static int
clusapi_dissect_element_GetResourceState_NodeName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetResourceState_NodeName__, NDR_POINTER_UNIQUE, "Pointer to NodeName (uint16)",hf_clusapi_clusapi_GetResourceState_NodeName);
return offset;
}
static int
clusapi_dissect_element_GetResourceState_NodeName__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_GetResourceState_NodeName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_GetResourceState_GroupName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetResourceState_GroupName_, NDR_POINTER_REF, "Pointer to GroupName (uint16)",hf_clusapi_clusapi_GetResourceState_GroupName);
return offset;
}
static int
clusapi_dissect_element_GetResourceState_GroupName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetResourceState_GroupName__, NDR_POINTER_UNIQUE, "Pointer to GroupName (uint16)",hf_clusapi_clusapi_GetResourceState_GroupName);
return offset;
}
static int
clusapi_dissect_element_GetResourceState_GroupName__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_GetResourceState_GroupName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_GetResourceState_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetResourceState_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_GetResourceState_rpc_status);
return offset;
}
static int
clusapi_dissect_element_GetResourceState_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetResourceState_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_GetResourceState_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="GetResourceState";
offset = clusapi_dissect_element_GetResourceState_State(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetResourceState_NodeName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetResourceState_GroupName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetResourceState_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_GetResourceState_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="GetResourceState";
offset = clusapi_dissect_element_GetResourceState_hResource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_SetResourceName_hResource(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_SetResourceName_hResource, 0);
return offset;
}
static int
clusapi_dissect_element_SetResourceName_lpszResourceName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_SetResourceName_lpszResourceName_, NDR_POINTER_REF, "Pointer to LpszResourceName (uint16)",hf_clusapi_clusapi_SetResourceName_lpszResourceName);
return offset;
}
static int
clusapi_dissect_element_SetResourceName_lpszResourceName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_SetResourceName_lpszResourceName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_SetResourceName_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_SetResourceName_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_SetResourceName_rpc_status);
return offset;
}
static int
clusapi_dissect_element_SetResourceName_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_SetResourceName_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_SetResourceName_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="SetResourceName";
offset = clusapi_dissect_element_SetResourceName_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_SetResourceName_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="SetResourceName";
offset = clusapi_dissect_element_SetResourceName_hResource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_SetResourceName_lpszResourceName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_GetResourceId_hResource(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetResourceId_hResource, 0);
return offset;
}
static int
clusapi_dissect_element_GetResourceId_pGuid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetResourceId_pGuid_, NDR_POINTER_REF, "Pointer to PGuid (uint16)",hf_clusapi_clusapi_GetResourceId_pGuid);
return offset;
}
static int
clusapi_dissect_element_GetResourceId_pGuid_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetResourceId_pGuid__, NDR_POINTER_UNIQUE, "Pointer to PGuid (uint16)",hf_clusapi_clusapi_GetResourceId_pGuid);
return offset;
}
static int
clusapi_dissect_element_GetResourceId_pGuid__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_GetResourceId_pGuid, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_GetResourceId_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetResourceId_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_GetResourceId_rpc_status);
return offset;
}
static int
clusapi_dissect_element_GetResourceId_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetResourceId_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_GetResourceId_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="GetResourceId";
offset = clusapi_dissect_element_GetResourceId_pGuid(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetResourceId_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_GetResourceId_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="GetResourceId";
offset = clusapi_dissect_element_GetResourceId_hResource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_GetResourceType_hResource(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetResourceType_hResource, 0);
return offset;
}
static int
clusapi_dissect_element_GetResourceType_lpszResourceType(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetResourceType_lpszResourceType_, NDR_POINTER_REF, "Pointer to LpszResourceType (uint16)",hf_clusapi_clusapi_GetResourceType_lpszResourceType);
return offset;
}
static int
clusapi_dissect_element_GetResourceType_lpszResourceType_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetResourceType_lpszResourceType__, NDR_POINTER_UNIQUE, "Pointer to LpszResourceType (uint16)",hf_clusapi_clusapi_GetResourceType_lpszResourceType);
return offset;
}
static int
clusapi_dissect_element_GetResourceType_lpszResourceType__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_GetResourceType_lpszResourceType, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_GetResourceType_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetResourceType_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_GetResourceType_rpc_status);
return offset;
}
static int
clusapi_dissect_element_GetResourceType_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetResourceType_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_GetResourceType_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="GetResourceType";
offset = clusapi_dissect_element_GetResourceType_lpszResourceType(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetResourceType_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_GetResourceType_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="GetResourceType";
offset = clusapi_dissect_element_GetResourceType_hResource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_FailResource_hResource(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_FailResource_hResource, 0);
return offset;
}
static int
clusapi_dissect_element_FailResource_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_FailResource_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_FailResource_rpc_status);
return offset;
}
static int
clusapi_dissect_element_FailResource_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_FailResource_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_FailResource_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="FailResource";
offset = clusapi_dissect_element_FailResource_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_FailResource_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="FailResource";
offset = clusapi_dissect_element_FailResource_hResource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_OnlineResource_hResource(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OnlineResource_hResource, 0);
return offset;
}
static int
clusapi_dissect_element_OnlineResource_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OnlineResource_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_OnlineResource_rpc_status);
return offset;
}
static int
clusapi_dissect_element_OnlineResource_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OnlineResource_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_OnlineResource_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="OnlineResource";
offset = clusapi_dissect_element_OnlineResource_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_OnlineResource_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OnlineResource";
offset = clusapi_dissect_element_OnlineResource_hResource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_OfflineResource_hResource(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OfflineResource_hResource, 0);
return offset;
}
static int
clusapi_dissect_element_OfflineResource_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OfflineResource_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_OfflineResource_rpc_status);
return offset;
}
static int
clusapi_dissect_element_OfflineResource_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OfflineResource_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_OfflineResource_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="OfflineResource";
offset = clusapi_dissect_element_OfflineResource_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_OfflineResource_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OfflineResource";
offset = clusapi_dissect_element_OfflineResource_hResource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_AddResourceDependency_hResource(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddResourceDependency_hResource, 0);
return offset;
}
static int
clusapi_dissect_element_AddResourceDependency_hDependsOn(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddResourceDependency_hDependsOn, 0);
return offset;
}
static int
clusapi_dissect_element_AddResourceDependency_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_AddResourceDependency_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_AddResourceDependency_rpc_status);
return offset;
}
static int
clusapi_dissect_element_AddResourceDependency_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddResourceDependency_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_AddResourceDependency_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="AddResourceDependency";
offset = clusapi_dissect_element_AddResourceDependency_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_AddResourceDependency_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="AddResourceDependency";
offset = clusapi_dissect_element_AddResourceDependency_hResource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddResourceDependency_hDependsOn(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_RemoveResourceDependency_hResource(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_RemoveResourceDependency_hResource, 0);
return offset;
}
static int
clusapi_dissect_element_RemoveResourceDependency_hDependsOn(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_RemoveResourceDependency_hDependsOn, 0);
return offset;
}
static int
clusapi_dissect_element_RemoveResourceDependency_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_RemoveResourceDependency_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_RemoveResourceDependency_rpc_status);
return offset;
}
static int
clusapi_dissect_element_RemoveResourceDependency_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_RemoveResourceDependency_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_RemoveResourceDependency_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="RemoveResourceDependency";
offset = clusapi_dissect_element_RemoveResourceDependency_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_RemoveResourceDependency_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="RemoveResourceDependency";
offset = clusapi_dissect_element_RemoveResourceDependency_hResource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_RemoveResourceDependency_hDependsOn(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_CanResourceBeDependent_hResource(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CanResourceBeDependent_hResource, 0);
return offset;
}
static int
clusapi_dissect_element_CanResourceBeDependent_hResourceDependent(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CanResourceBeDependent_hResourceDependent, 0);
return offset;
}
static int
clusapi_dissect_element_CanResourceBeDependent_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CanResourceBeDependent_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_CanResourceBeDependent_rpc_status);
return offset;
}
static int
clusapi_dissect_element_CanResourceBeDependent_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CanResourceBeDependent_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_CanResourceBeDependent_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="CanResourceBeDependent";
offset = clusapi_dissect_element_CanResourceBeDependent_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_CanResourceBeDependent_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CanResourceBeDependent";
offset = clusapi_dissect_element_CanResourceBeDependent_hResource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CanResourceBeDependent_hResourceDependent(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_CreateResEnum_hResource(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateResEnum_hResource, 0);
return offset;
}
static int
clusapi_dissect_element_CreateResEnum_dwType(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateResEnum_dwType, 0);
return offset;
}
static int
clusapi_dissect_element_CreateResEnum_ReturnEnum(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateResEnum_ReturnEnum_, NDR_POINTER_REF, "Pointer to ReturnEnum (ENUM_LIST)",hf_clusapi_clusapi_CreateResEnum_ReturnEnum);
return offset;
}
static int
clusapi_dissect_element_CreateResEnum_ReturnEnum_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateResEnum_ReturnEnum__, NDR_POINTER_UNIQUE, "Pointer to ReturnEnum (ENUM_LIST)",hf_clusapi_clusapi_CreateResEnum_ReturnEnum);
return offset;
}
static int
clusapi_dissect_element_CreateResEnum_ReturnEnum__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_struct_ENUM_LIST(tvb,offset,pinfo,tree,di,drep,hf_clusapi_clusapi_CreateResEnum_ReturnEnum,0);
return offset;
}
static int
clusapi_dissect_element_CreateResEnum_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateResEnum_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_CreateResEnum_rpc_status);
return offset;
}
static int
clusapi_dissect_element_CreateResEnum_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateResEnum_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_CreateResEnum_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="CreateResEnum";
offset = clusapi_dissect_element_CreateResEnum_ReturnEnum(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateResEnum_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_CreateResEnum_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CreateResEnum";
offset = clusapi_dissect_element_CreateResEnum_hResource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateResEnum_dwType(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_AddResourceNode_hResource(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddResourceNode_hResource, 0);
return offset;
}
static int
clusapi_dissect_element_AddResourceNode_hNode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddResourceNode_hNode, 0);
return offset;
}
static int
clusapi_dissect_element_AddResourceNode_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_AddResourceNode_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_AddResourceNode_rpc_status);
return offset;
}
static int
clusapi_dissect_element_AddResourceNode_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddResourceNode_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_AddResourceNode_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="AddResourceNode";
offset = clusapi_dissect_element_AddResourceNode_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_AddResourceNode_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="AddResourceNode";
offset = clusapi_dissect_element_AddResourceNode_hResource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddResourceNode_hNode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_RemoveResourceNode_hResource(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_RemoveResourceNode_hResource, 0);
return offset;
}
static int
clusapi_dissect_element_RemoveResourceNode_hNode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_RemoveResourceNode_hNode, 0);
return offset;
}
static int
clusapi_dissect_element_RemoveResourceNode_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_RemoveResourceNode_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_RemoveResourceNode_rpc_status);
return offset;
}
static int
clusapi_dissect_element_RemoveResourceNode_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_RemoveResourceNode_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_RemoveResourceNode_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="RemoveResourceNode";
offset = clusapi_dissect_element_RemoveResourceNode_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_RemoveResourceNode_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="RemoveResourceNode";
offset = clusapi_dissect_element_RemoveResourceNode_hResource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_RemoveResourceNode_hNode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_ChangeResourceGroup_hResource(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ChangeResourceGroup_hResource, 0);
return offset;
}
static int
clusapi_dissect_element_ChangeResourceGroup_hGroup(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ChangeResourceGroup_hGroup, 0);
return offset;
}
static int
clusapi_dissect_element_ChangeResourceGroup_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ChangeResourceGroup_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_ChangeResourceGroup_rpc_status);
return offset;
}
static int
clusapi_dissect_element_ChangeResourceGroup_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ChangeResourceGroup_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_ChangeResourceGroup_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="ChangeResourceGroup";
offset = clusapi_dissect_element_ChangeResourceGroup_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_ChangeResourceGroup_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="ChangeResourceGroup";
offset = clusapi_dissect_element_ChangeResourceGroup_hResource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ChangeResourceGroup_hGroup(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_CreateResourceType_lpszTypeName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateResourceType_lpszTypeName_, NDR_POINTER_REF, "Pointer to LpszTypeName (uint16)",hf_clusapi_clusapi_CreateResourceType_lpszTypeName);
return offset;
}
static int
clusapi_dissect_element_CreateResourceType_lpszTypeName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_CreateResourceType_lpszTypeName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_CreateResourceType_lpszDisplayName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateResourceType_lpszDisplayName_, NDR_POINTER_REF, "Pointer to LpszDisplayName (uint16)",hf_clusapi_clusapi_CreateResourceType_lpszDisplayName);
return offset;
}
static int
clusapi_dissect_element_CreateResourceType_lpszDisplayName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_CreateResourceType_lpszDisplayName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_CreateResourceType_lpszDllName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateResourceType_lpszDllName_, NDR_POINTER_REF, "Pointer to LpszDllName (uint16)",hf_clusapi_clusapi_CreateResourceType_lpszDllName);
return offset;
}
static int
clusapi_dissect_element_CreateResourceType_lpszDllName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_CreateResourceType_lpszDllName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_CreateResourceType_dwLooksAlive(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateResourceType_dwLooksAlive, 0);
return offset;
}
static int
clusapi_dissect_element_CreateResourceType_dwIsAlive(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateResourceType_dwIsAlive, 0);
return offset;
}
static int
clusapi_dissect_element_CreateResourceType_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateResourceType_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_CreateResourceType_rpc_status);
return offset;
}
static int
clusapi_dissect_element_CreateResourceType_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateResourceType_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_CreateResourceType_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="CreateResourceType";
offset = clusapi_dissect_element_CreateResourceType_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_CreateResourceType_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CreateResourceType";
offset = clusapi_dissect_element_CreateResourceType_lpszTypeName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateResourceType_lpszDisplayName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateResourceType_lpszDllName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateResourceType_dwLooksAlive(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateResourceType_dwIsAlive(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_DeleteResourceType_lpszTypeName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_DeleteResourceType_lpszTypeName_, NDR_POINTER_REF, "Pointer to LpszTypeName (uint16)",hf_clusapi_clusapi_DeleteResourceType_lpszTypeName);
return offset;
}
static int
clusapi_dissect_element_DeleteResourceType_lpszTypeName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_DeleteResourceType_lpszTypeName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_DeleteResourceType_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_DeleteResourceType_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_DeleteResourceType_rpc_status);
return offset;
}
static int
clusapi_dissect_element_DeleteResourceType_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_DeleteResourceType_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_DeleteResourceType_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="DeleteResourceType";
offset = clusapi_dissect_element_DeleteResourceType_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_DeleteResourceType_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="DeleteResourceType";
offset = clusapi_dissect_element_DeleteResourceType_lpszTypeName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_GetRootKey_samDesired(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = winreg_dissect_bitmap_AccessMask(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetRootKey_samDesired, 0);
return offset;
}
static int
clusapi_dissect_element_GetRootKey_Status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetRootKey_Status_, NDR_POINTER_REF, "Pointer to Status (WERROR)",hf_clusapi_clusapi_GetRootKey_Status);
return offset;
}
static int
clusapi_dissect_element_GetRootKey_Status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetRootKey_Status, 0);
return offset;
}
static int
clusapi_dissect_element_GetRootKey_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetRootKey_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_GetRootKey_rpc_status);
return offset;
}
static int
clusapi_dissect_element_GetRootKey_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetRootKey_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_element_GetRootKey_phKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetRootKey_phKey_, NDR_POINTER_REF, "Pointer to PhKey (policy_handle)",hf_clusapi_clusapi_GetRootKey_phKey);
return offset;
}
static int
clusapi_dissect_element_GetRootKey_phKey_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetRootKey_phKey, 0);
return offset;
}
static int
clusapi_dissect_GetRootKey_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="GetRootKey";
offset = clusapi_dissect_element_GetRootKey_Status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetRootKey_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetRootKey_phKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_GetRootKey_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="GetRootKey";
offset = clusapi_dissect_element_GetRootKey_samDesired(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_CreateKey_hKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateKey_hKey, 0);
return offset;
}
static int
clusapi_dissect_element_CreateKey_lpSubKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateKey_lpSubKey_, NDR_POINTER_REF, "Pointer to LpSubKey (uint16)",hf_clusapi_clusapi_CreateKey_lpSubKey);
return offset;
}
static int
clusapi_dissect_element_CreateKey_lpSubKey_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_CreateKey_lpSubKey, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_CreateKey_dwOptions(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateKey_dwOptions, 0);
return offset;
}
static int
clusapi_dissect_element_CreateKey_samDesired(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = winreg_dissect_bitmap_AccessMask(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateKey_samDesired, 0);
return offset;
}
static int
clusapi_dissect_element_CreateKey_lpSecurityAttributes(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateKey_lpSecurityAttributes_, NDR_POINTER_UNIQUE, "Pointer to LpSecurityAttributes (RPC_SECURITY_ATTRIBUTES)",hf_clusapi_clusapi_CreateKey_lpSecurityAttributes);
return offset;
}
static int
clusapi_dissect_element_CreateKey_lpSecurityAttributes_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_struct_RPC_SECURITY_ATTRIBUTES(tvb,offset,pinfo,tree,di,drep,hf_clusapi_clusapi_CreateKey_lpSecurityAttributes,0);
return offset;
}
static int
clusapi_dissect_element_CreateKey_lpdwDisposition(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateKey_lpdwDisposition_, NDR_POINTER_REF, "Pointer to LpdwDisposition (uint32)",hf_clusapi_clusapi_CreateKey_lpdwDisposition);
return offset;
}
static int
clusapi_dissect_element_CreateKey_lpdwDisposition_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateKey_lpdwDisposition, 0);
return offset;
}
static int
clusapi_dissect_element_CreateKey_Status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateKey_Status_, NDR_POINTER_REF, "Pointer to Status (WERROR)",hf_clusapi_clusapi_CreateKey_Status);
return offset;
}
static int
clusapi_dissect_element_CreateKey_Status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateKey_Status, 0);
return offset;
}
static int
clusapi_dissect_element_CreateKey_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateKey_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_CreateKey_rpc_status);
return offset;
}
static int
clusapi_dissect_element_CreateKey_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateKey_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_element_CreateKey_phKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateKey_phKey_, NDR_POINTER_REF, "Pointer to PhKey (policy_handle)",hf_clusapi_clusapi_CreateKey_phKey);
return offset;
}
static int
clusapi_dissect_element_CreateKey_phKey_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateKey_phKey, 0);
return offset;
}
static int
clusapi_dissect_CreateKey_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CreateKey";
offset = clusapi_dissect_element_CreateKey_lpdwDisposition(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateKey_Status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateKey_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateKey_phKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_CreateKey_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CreateKey";
offset = clusapi_dissect_element_CreateKey_hKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateKey_lpSubKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateKey_dwOptions(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateKey_samDesired(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateKey_lpSecurityAttributes(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_OpenKey_hKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenKey_hKey, 0);
return offset;
}
static int
clusapi_dissect_element_OpenKey_lpSubKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenKey_lpSubKey_, NDR_POINTER_REF, "Pointer to LpSubKey (uint16)",hf_clusapi_clusapi_OpenKey_lpSubKey);
return offset;
}
static int
clusapi_dissect_element_OpenKey_lpSubKey_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_OpenKey_lpSubKey, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_OpenKey_samDesired(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = winreg_dissect_bitmap_AccessMask(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenKey_samDesired, 0);
return offset;
}
static int
clusapi_dissect_element_OpenKey_Status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenKey_Status_, NDR_POINTER_REF, "Pointer to Status (WERROR)",hf_clusapi_clusapi_OpenKey_Status);
return offset;
}
static int
clusapi_dissect_element_OpenKey_Status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenKey_Status, 0);
return offset;
}
static int
clusapi_dissect_element_OpenKey_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenKey_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_OpenKey_rpc_status);
return offset;
}
static int
clusapi_dissect_element_OpenKey_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenKey_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_element_OpenKey_phKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenKey_phKey_, NDR_POINTER_REF, "Pointer to PhKey (policy_handle)",hf_clusapi_clusapi_OpenKey_phKey);
return offset;
}
static int
clusapi_dissect_element_OpenKey_phKey_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenKey_phKey, 0);
return offset;
}
static int
clusapi_dissect_OpenKey_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OpenKey";
offset = clusapi_dissect_element_OpenKey_Status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenKey_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenKey_phKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_OpenKey_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OpenKey";
offset = clusapi_dissect_element_OpenKey_hKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenKey_lpSubKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenKey_samDesired(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_EnumKey_hKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_EnumKey_hKey, 0);
return offset;
}
static int
clusapi_dissect_element_EnumKey_dwIndex(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_EnumKey_dwIndex, 0);
return offset;
}
static int
clusapi_dissect_element_EnumKey_KeyName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_EnumKey_KeyName_, NDR_POINTER_REF, "Pointer to KeyName (uint16)",hf_clusapi_clusapi_EnumKey_KeyName);
return offset;
}
static int
clusapi_dissect_element_EnumKey_KeyName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_EnumKey_KeyName__, NDR_POINTER_UNIQUE, "Pointer to KeyName (uint16)",hf_clusapi_clusapi_EnumKey_KeyName);
return offset;
}
static int
clusapi_dissect_element_EnumKey_KeyName__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_EnumKey_KeyName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_EnumKey_lpftLastWriteTime(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_EnumKey_lpftLastWriteTime_, NDR_POINTER_REF, "Pointer to LpftLastWriteTime (NTTIME)",hf_clusapi_clusapi_EnumKey_lpftLastWriteTime);
return offset;
}
static int
clusapi_dissect_element_EnumKey_lpftLastWriteTime_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_EnumKey_lpftLastWriteTime);
return offset;
}
static int
clusapi_dissect_element_EnumKey_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_EnumKey_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_EnumKey_rpc_status);
return offset;
}
static int
clusapi_dissect_element_EnumKey_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_EnumKey_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_EnumKey_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="EnumKey";
offset = clusapi_dissect_element_EnumKey_KeyName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_EnumKey_lpftLastWriteTime(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_EnumKey_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_EnumKey_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="EnumKey";
offset = clusapi_dissect_element_EnumKey_hKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_EnumKey_dwIndex(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_SetValue_hKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_SetValue_hKey, 0);
return offset;
}
static int
clusapi_dissect_element_SetValue_lpValueName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_SetValue_lpValueName_, NDR_POINTER_REF, "Pointer to LpValueName (uint16)",hf_clusapi_clusapi_SetValue_lpValueName);
return offset;
}
static int
clusapi_dissect_element_SetValue_lpValueName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_SetValue_lpValueName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_SetValue_dwType(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = misc_dissect_enum_winreg_Type(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_SetValue_dwType, 0);
return offset;
}
static int
clusapi_dissect_element_SetValue_lpData(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_SetValue_lpData_, NDR_POINTER_REF, "Pointer to LpData (uint8)",hf_clusapi_clusapi_SetValue_lpData);
return offset;
}
static int
clusapi_dissect_element_SetValue_lpData_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_SetValue_lpData__);
return offset;
}
static int
clusapi_dissect_element_SetValue_lpData__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_SetValue_lpData, 0);
return offset;
}
static int
clusapi_dissect_element_SetValue_cbData(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_SetValue_cbData, 0);
return offset;
}
static int
clusapi_dissect_element_SetValue_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_SetValue_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_SetValue_rpc_status);
return offset;
}
static int
clusapi_dissect_element_SetValue_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_SetValue_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_SetValue_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="SetValue";
offset = clusapi_dissect_element_SetValue_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_SetValue_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="SetValue";
offset = clusapi_dissect_element_SetValue_hKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_SetValue_lpValueName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_SetValue_dwType(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_SetValue_lpData(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_SetValue_cbData(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_DeleteValue_hKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_DeleteValue_hKey, 0);
return offset;
}
static int
clusapi_dissect_element_DeleteValue_lpValueName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_DeleteValue_lpValueName_, NDR_POINTER_REF, "Pointer to LpValueName (uint16)",hf_clusapi_clusapi_DeleteValue_lpValueName);
return offset;
}
static int
clusapi_dissect_element_DeleteValue_lpValueName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_DeleteValue_lpValueName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_DeleteValue_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_DeleteValue_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_DeleteValue_rpc_status);
return offset;
}
static int
clusapi_dissect_element_DeleteValue_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_DeleteValue_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_DeleteValue_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="DeleteValue";
offset = clusapi_dissect_element_DeleteValue_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_DeleteValue_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="DeleteValue";
offset = clusapi_dissect_element_DeleteValue_hKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_DeleteValue_lpValueName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_QueryValue_hKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_QueryValue_hKey, 0);
return offset;
}
static int
clusapi_dissect_element_QueryValue_lpValueName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_QueryValue_lpValueName_, NDR_POINTER_REF, "Pointer to LpValueName (uint16)",hf_clusapi_clusapi_QueryValue_lpValueName);
return offset;
}
static int
clusapi_dissect_element_QueryValue_lpValueName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_QueryValue_lpValueName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_QueryValue_lpValueType(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_QueryValue_lpValueType_, NDR_POINTER_REF, "Pointer to LpValueType (winreg_Type)",hf_clusapi_clusapi_QueryValue_lpValueType);
return offset;
}
static int
clusapi_dissect_element_QueryValue_lpValueType_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = misc_dissect_enum_winreg_Type(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_QueryValue_lpValueType, 0);
return offset;
}
static int
clusapi_dissect_element_QueryValue_lpData(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_QueryValue_lpData_, NDR_POINTER_REF, "Pointer to LpData (uint8)",hf_clusapi_clusapi_QueryValue_lpData);
return offset;
}
static int
clusapi_dissect_element_QueryValue_lpData_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_QueryValue_lpData__);
return offset;
}
static int
clusapi_dissect_element_QueryValue_lpData__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_QueryValue_lpData, 0);
return offset;
}
static int
clusapi_dissect_element_QueryValue_cbData(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_QueryValue_cbData, 0);
return offset;
}
static int
clusapi_dissect_element_QueryValue_lpcbRequired(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_QueryValue_lpcbRequired_, NDR_POINTER_REF, "Pointer to LpcbRequired (uint32)",hf_clusapi_clusapi_QueryValue_lpcbRequired);
return offset;
}
static int
clusapi_dissect_element_QueryValue_lpcbRequired_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_QueryValue_lpcbRequired, 0);
return offset;
}
static int
clusapi_dissect_element_QueryValue_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_QueryValue_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_QueryValue_rpc_status);
return offset;
}
static int
clusapi_dissect_element_QueryValue_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_QueryValue_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_QueryValue_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="QueryValue";
offset = clusapi_dissect_element_QueryValue_lpValueType(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_QueryValue_lpData(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_QueryValue_lpcbRequired(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_QueryValue_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_QueryValue_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="QueryValue";
offset = clusapi_dissect_element_QueryValue_hKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_QueryValue_lpValueName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_QueryValue_cbData(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_DeleteKey_hKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_DeleteKey_hKey, 0);
return offset;
}
static int
clusapi_dissect_element_DeleteKey_lpSubKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_DeleteKey_lpSubKey_, NDR_POINTER_REF, "Pointer to LpSubKey (uint16)",hf_clusapi_clusapi_DeleteKey_lpSubKey);
return offset;
}
static int
clusapi_dissect_element_DeleteKey_lpSubKey_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_DeleteKey_lpSubKey, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_DeleteKey_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_DeleteKey_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_DeleteKey_rpc_status);
return offset;
}
static int
clusapi_dissect_element_DeleteKey_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_DeleteKey_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_DeleteKey_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="DeleteKey";
offset = clusapi_dissect_element_DeleteKey_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_DeleteKey_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="DeleteKey";
offset = clusapi_dissect_element_DeleteKey_hKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_DeleteKey_lpSubKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_EnumValue_hKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_EnumValue_hKey, 0);
return offset;
}
static int
clusapi_dissect_element_EnumValue_dwIndex(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_EnumValue_dwIndex, 0);
return offset;
}
static int
clusapi_dissect_element_EnumValue_lpValueName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_EnumValue_lpValueName_, NDR_POINTER_REF, "Pointer to LpValueName (uint16)",hf_clusapi_clusapi_EnumValue_lpValueName);
return offset;
}
static int
clusapi_dissect_element_EnumValue_lpValueName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_EnumValue_lpValueName__, NDR_POINTER_UNIQUE, "Pointer to LpValueName (uint16)",hf_clusapi_clusapi_EnumValue_lpValueName);
return offset;
}
static int
clusapi_dissect_element_EnumValue_lpValueName__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_EnumValue_lpValueName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_EnumValue_lpType(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_EnumValue_lpType_, NDR_POINTER_REF, "Pointer to LpType (winreg_Type)",hf_clusapi_clusapi_EnumValue_lpType);
return offset;
}
static int
clusapi_dissect_element_EnumValue_lpType_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = misc_dissect_enum_winreg_Type(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_EnumValue_lpType, 0);
return offset;
}
static int
clusapi_dissect_element_EnumValue_lpData(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_EnumValue_lpData_, NDR_POINTER_REF, "Pointer to LpData (uint8)",hf_clusapi_clusapi_EnumValue_lpData);
return offset;
}
static int
clusapi_dissect_element_EnumValue_lpData_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_EnumValue_lpData__);
return offset;
}
static int
clusapi_dissect_element_EnumValue_lpData__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_EnumValue_lpData, 0);
return offset;
}
static int
clusapi_dissect_element_EnumValue_lpcbData(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_EnumValue_lpcbData_, NDR_POINTER_REF, "Pointer to LpcbData (uint32)",hf_clusapi_clusapi_EnumValue_lpcbData);
return offset;
}
static int
clusapi_dissect_element_EnumValue_lpcbData_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_EnumValue_lpcbData, 0);
return offset;
}
static int
clusapi_dissect_element_EnumValue_TotalSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_EnumValue_TotalSize_, NDR_POINTER_REF, "Pointer to TotalSize (uint32)",hf_clusapi_clusapi_EnumValue_TotalSize);
return offset;
}
static int
clusapi_dissect_element_EnumValue_TotalSize_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_EnumValue_TotalSize, 0);
return offset;
}
static int
clusapi_dissect_element_EnumValue_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_EnumValue_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_EnumValue_rpc_status);
return offset;
}
static int
clusapi_dissect_element_EnumValue_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_EnumValue_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_EnumValue_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="EnumValue";
offset = clusapi_dissect_element_EnumValue_lpValueName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_EnumValue_lpType(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_EnumValue_lpData(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_EnumValue_lpcbData(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_EnumValue_TotalSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_EnumValue_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_EnumValue_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="EnumValue";
offset = clusapi_dissect_element_EnumValue_hKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_EnumValue_dwIndex(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_EnumValue_lpcbData(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_CloseKey_pKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CloseKey_pKey_, NDR_POINTER_REF, "Pointer to PKey (policy_handle)",hf_clusapi_clusapi_CloseKey_pKey);
return offset;
}
static int
clusapi_dissect_element_CloseKey_pKey_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CloseKey_pKey, 0);
return offset;
}
static int
clusapi_dissect_CloseKey_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="CloseKey";
offset = clusapi_dissect_element_CloseKey_pKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_CloseKey_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CloseKey";
offset = clusapi_dissect_element_CloseKey_pKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_QueryInfoKey_hKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_QueryInfoKey_hKey, 0);
return offset;
}
static int
clusapi_dissect_element_QueryInfoKey_lpcSubKeys(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_QueryInfoKey_lpcSubKeys_, NDR_POINTER_REF, "Pointer to LpcSubKeys (uint32)",hf_clusapi_clusapi_QueryInfoKey_lpcSubKeys);
return offset;
}
static int
clusapi_dissect_element_QueryInfoKey_lpcSubKeys_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_QueryInfoKey_lpcSubKeys, 0);
return offset;
}
static int
clusapi_dissect_element_QueryInfoKey_lpcbMaxSubKeyLen(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_QueryInfoKey_lpcbMaxSubKeyLen_, NDR_POINTER_REF, "Pointer to LpcbMaxSubKeyLen (uint32)",hf_clusapi_clusapi_QueryInfoKey_lpcbMaxSubKeyLen);
return offset;
}
static int
clusapi_dissect_element_QueryInfoKey_lpcbMaxSubKeyLen_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_QueryInfoKey_lpcbMaxSubKeyLen, 0);
return offset;
}
static int
clusapi_dissect_element_QueryInfoKey_lpcValues(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_QueryInfoKey_lpcValues_, NDR_POINTER_REF, "Pointer to LpcValues (uint32)",hf_clusapi_clusapi_QueryInfoKey_lpcValues);
return offset;
}
static int
clusapi_dissect_element_QueryInfoKey_lpcValues_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_QueryInfoKey_lpcValues, 0);
return offset;
}
static int
clusapi_dissect_element_QueryInfoKey_lpcbMaxValueNameLen(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_QueryInfoKey_lpcbMaxValueNameLen_, NDR_POINTER_REF, "Pointer to LpcbMaxValueNameLen (uint32)",hf_clusapi_clusapi_QueryInfoKey_lpcbMaxValueNameLen);
return offset;
}
static int
clusapi_dissect_element_QueryInfoKey_lpcbMaxValueNameLen_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_QueryInfoKey_lpcbMaxValueNameLen, 0);
return offset;
}
static int
clusapi_dissect_element_QueryInfoKey_lpcbMaxValueLen(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_QueryInfoKey_lpcbMaxValueLen_, NDR_POINTER_REF, "Pointer to LpcbMaxValueLen (uint32)",hf_clusapi_clusapi_QueryInfoKey_lpcbMaxValueLen);
return offset;
}
static int
clusapi_dissect_element_QueryInfoKey_lpcbMaxValueLen_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_QueryInfoKey_lpcbMaxValueLen, 0);
return offset;
}
static int
clusapi_dissect_element_QueryInfoKey_lpcbSecurityDescriptor(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_QueryInfoKey_lpcbSecurityDescriptor_, NDR_POINTER_REF, "Pointer to LpcbSecurityDescriptor (uint32)",hf_clusapi_clusapi_QueryInfoKey_lpcbSecurityDescriptor);
return offset;
}
static int
clusapi_dissect_element_QueryInfoKey_lpcbSecurityDescriptor_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_QueryInfoKey_lpcbSecurityDescriptor, 0);
return offset;
}
static int
clusapi_dissect_element_QueryInfoKey_lpftLastWriteTime(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_QueryInfoKey_lpftLastWriteTime_, NDR_POINTER_REF, "Pointer to LpftLastWriteTime (NTTIME)",hf_clusapi_clusapi_QueryInfoKey_lpftLastWriteTime);
return offset;
}
static int
clusapi_dissect_element_QueryInfoKey_lpftLastWriteTime_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_QueryInfoKey_lpftLastWriteTime);
return offset;
}
static int
clusapi_dissect_element_QueryInfoKey_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_QueryInfoKey_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_QueryInfoKey_rpc_status);
return offset;
}
static int
clusapi_dissect_element_QueryInfoKey_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_QueryInfoKey_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_QueryInfoKey_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="QueryInfoKey";
offset = clusapi_dissect_element_QueryInfoKey_lpcSubKeys(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_QueryInfoKey_lpcbMaxSubKeyLen(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_QueryInfoKey_lpcValues(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_QueryInfoKey_lpcbMaxValueNameLen(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_QueryInfoKey_lpcbMaxValueLen(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_QueryInfoKey_lpcbSecurityDescriptor(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_QueryInfoKey_lpftLastWriteTime(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_QueryInfoKey_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_QueryInfoKey_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="QueryInfoKey";
offset = clusapi_dissect_element_QueryInfoKey_hKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_SetKeySecurity_hKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_SetKeySecurity_hKey, 0);
return offset;
}
static int
clusapi_dissect_element_SetKeySecurity_SecurityInformation(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_SetKeySecurity_SecurityInformation, 0);
return offset;
}
static int
clusapi_dissect_element_SetKeySecurity_pRpcSecurityDescriptor(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_SetKeySecurity_pRpcSecurityDescriptor_, NDR_POINTER_REF, "Pointer to PRpcSecurityDescriptor (RPC_SECURITY_DESCRIPTOR)",hf_clusapi_clusapi_SetKeySecurity_pRpcSecurityDescriptor);
return offset;
}
static int
clusapi_dissect_element_SetKeySecurity_pRpcSecurityDescriptor_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_struct_RPC_SECURITY_DESCRIPTOR(tvb,offset,pinfo,tree,di,drep,hf_clusapi_clusapi_SetKeySecurity_pRpcSecurityDescriptor,0);
return offset;
}
static int
clusapi_dissect_element_SetKeySecurity_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_SetKeySecurity_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_SetKeySecurity_rpc_status);
return offset;
}
static int
clusapi_dissect_element_SetKeySecurity_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_SetKeySecurity_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_SetKeySecurity_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="SetKeySecurity";
offset = clusapi_dissect_element_SetKeySecurity_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_SetKeySecurity_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="SetKeySecurity";
offset = clusapi_dissect_element_SetKeySecurity_hKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_SetKeySecurity_SecurityInformation(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_SetKeySecurity_pRpcSecurityDescriptor(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_GetKeySecurity_hKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetKeySecurity_hKey, 0);
return offset;
}
static int
clusapi_dissect_element_GetKeySecurity_SecurityInformation(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetKeySecurity_SecurityInformation, 0);
return offset;
}
static int
clusapi_dissect_element_GetKeySecurity_pRpcSecurityDescriptor(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetKeySecurity_pRpcSecurityDescriptor_, NDR_POINTER_REF, "Pointer to PRpcSecurityDescriptor (RPC_SECURITY_DESCRIPTOR)",hf_clusapi_clusapi_GetKeySecurity_pRpcSecurityDescriptor);
return offset;
}
static int
clusapi_dissect_element_GetKeySecurity_pRpcSecurityDescriptor_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_struct_RPC_SECURITY_DESCRIPTOR(tvb,offset,pinfo,tree,di,drep,hf_clusapi_clusapi_GetKeySecurity_pRpcSecurityDescriptor,0);
return offset;
}
static int
clusapi_dissect_element_GetKeySecurity_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetKeySecurity_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_GetKeySecurity_rpc_status);
return offset;
}
static int
clusapi_dissect_element_GetKeySecurity_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetKeySecurity_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_GetKeySecurity_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="GetKeySecurity";
offset = clusapi_dissect_element_GetKeySecurity_pRpcSecurityDescriptor(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetKeySecurity_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_GetKeySecurity_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="GetKeySecurity";
offset = clusapi_dissect_element_GetKeySecurity_hKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetKeySecurity_SecurityInformation(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetKeySecurity_pRpcSecurityDescriptor(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_OpenGroup_lpszGroupName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenGroup_lpszGroupName_, NDR_POINTER_REF, "Pointer to LpszGroupName (uint16)",hf_clusapi_clusapi_OpenGroup_lpszGroupName);
return offset;
}
static int
clusapi_dissect_element_OpenGroup_lpszGroupName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_OpenGroup_lpszGroupName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_OpenGroup_Status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenGroup_Status_, NDR_POINTER_REF, "Pointer to Status (WERROR)",hf_clusapi_clusapi_OpenGroup_Status);
return offset;
}
static int
clusapi_dissect_element_OpenGroup_Status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenGroup_Status, 0);
return offset;
}
static int
clusapi_dissect_element_OpenGroup_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenGroup_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_OpenGroup_rpc_status);
return offset;
}
static int
clusapi_dissect_element_OpenGroup_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenGroup_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_element_OpenGroup_hGroup(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenGroup_hGroup_, NDR_POINTER_REF, "Pointer to HGroup (policy_handle)",hf_clusapi_clusapi_OpenGroup_hGroup);
return offset;
}
static int
clusapi_dissect_element_OpenGroup_hGroup_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenGroup_hGroup, 0);
return offset;
}
static int
clusapi_dissect_OpenGroup_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OpenGroup";
offset = clusapi_dissect_element_OpenGroup_Status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenGroup_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenGroup_hGroup(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_OpenGroup_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OpenGroup";
offset = clusapi_dissect_element_OpenGroup_lpszGroupName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_CreateGroup_lpszGroupName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateGroup_lpszGroupName_, NDR_POINTER_REF, "Pointer to LpszGroupName (uint16)",hf_clusapi_clusapi_CreateGroup_lpszGroupName);
return offset;
}
static int
clusapi_dissect_element_CreateGroup_lpszGroupName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_CreateGroup_lpszGroupName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_CreateGroup_Status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateGroup_Status_, NDR_POINTER_REF, "Pointer to Status (WERROR)",hf_clusapi_clusapi_CreateGroup_Status);
return offset;
}
static int
clusapi_dissect_element_CreateGroup_Status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateGroup_Status, 0);
return offset;
}
static int
clusapi_dissect_element_CreateGroup_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateGroup_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_CreateGroup_rpc_status);
return offset;
}
static int
clusapi_dissect_element_CreateGroup_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateGroup_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_element_CreateGroup_hGroup(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateGroup_hGroup_, NDR_POINTER_REF, "Pointer to HGroup (policy_handle)",hf_clusapi_clusapi_CreateGroup_hGroup);
return offset;
}
static int
clusapi_dissect_element_CreateGroup_hGroup_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateGroup_hGroup, 0);
return offset;
}
static int
clusapi_dissect_CreateGroup_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CreateGroup";
offset = clusapi_dissect_element_CreateGroup_Status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateGroup_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateGroup_hGroup(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_CreateGroup_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CreateGroup";
offset = clusapi_dissect_element_CreateGroup_lpszGroupName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_DeleteGroup_Group(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_DeleteGroup_Group, 0);
return offset;
}
static int
clusapi_dissect_element_DeleteGroup_force(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_DeleteGroup_force, 0);
return offset;
}
static int
clusapi_dissect_element_DeleteGroup_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_DeleteGroup_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_DeleteGroup_rpc_status);
return offset;
}
static int
clusapi_dissect_element_DeleteGroup_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_DeleteGroup_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_DeleteGroup_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="DeleteGroup";
offset = clusapi_dissect_element_DeleteGroup_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_DeleteGroup_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="DeleteGroup";
offset = clusapi_dissect_element_DeleteGroup_Group(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_DeleteGroup_force(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_CloseGroup_Group(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CloseGroup_Group_, NDR_POINTER_REF, "Pointer to Group (policy_handle)",hf_clusapi_clusapi_CloseGroup_Group);
return offset;
}
static int
clusapi_dissect_element_CloseGroup_Group_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CloseGroup_Group, 0);
return offset;
}
static int
clusapi_dissect_CloseGroup_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="CloseGroup";
offset = clusapi_dissect_element_CloseGroup_Group(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_CloseGroup_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CloseGroup";
offset = clusapi_dissect_element_CloseGroup_Group(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_GetGroupState_hGroup(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetGroupState_hGroup, 0);
return offset;
}
static int
clusapi_dissect_element_GetGroupState_State(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetGroupState_State_, NDR_POINTER_REF, "Pointer to State (clusapi_ClusterGroupState)",hf_clusapi_clusapi_GetGroupState_State);
return offset;
}
static int
clusapi_dissect_element_GetGroupState_State_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_enum_ClusterGroupState(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetGroupState_State, 0);
return offset;
}
static int
clusapi_dissect_element_GetGroupState_NodeName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetGroupState_NodeName_, NDR_POINTER_REF, "Pointer to NodeName (uint16)",hf_clusapi_clusapi_GetGroupState_NodeName);
return offset;
}
static int
clusapi_dissect_element_GetGroupState_NodeName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetGroupState_NodeName__, NDR_POINTER_UNIQUE, "Pointer to NodeName (uint16)",hf_clusapi_clusapi_GetGroupState_NodeName);
return offset;
}
static int
clusapi_dissect_element_GetGroupState_NodeName__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_GetGroupState_NodeName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_GetGroupState_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetGroupState_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_GetGroupState_rpc_status);
return offset;
}
static int
clusapi_dissect_element_GetGroupState_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetGroupState_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_GetGroupState_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="GetGroupState";
offset = clusapi_dissect_element_GetGroupState_State(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetGroupState_NodeName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetGroupState_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_GetGroupState_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="GetGroupState";
offset = clusapi_dissect_element_GetGroupState_hGroup(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_SetGroupName_hGroup(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_SetGroupName_hGroup, 0);
return offset;
}
static int
clusapi_dissect_element_SetGroupName_lpszGroupName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_SetGroupName_lpszGroupName_, NDR_POINTER_REF, "Pointer to LpszGroupName (uint16)",hf_clusapi_clusapi_SetGroupName_lpszGroupName);
return offset;
}
static int
clusapi_dissect_element_SetGroupName_lpszGroupName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_SetGroupName_lpszGroupName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_SetGroupName_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_SetGroupName_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_SetGroupName_rpc_status);
return offset;
}
static int
clusapi_dissect_element_SetGroupName_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_SetGroupName_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_SetGroupName_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="SetGroupName";
offset = clusapi_dissect_element_SetGroupName_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_SetGroupName_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="SetGroupName";
offset = clusapi_dissect_element_SetGroupName_hGroup(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_SetGroupName_lpszGroupName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_GetGroupId_hGroup(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetGroupId_hGroup, 0);
return offset;
}
static int
clusapi_dissect_element_GetGroupId_pGuid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetGroupId_pGuid_, NDR_POINTER_REF, "Pointer to PGuid (uint16)",hf_clusapi_clusapi_GetGroupId_pGuid);
return offset;
}
static int
clusapi_dissect_element_GetGroupId_pGuid_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetGroupId_pGuid__, NDR_POINTER_UNIQUE, "Pointer to PGuid (uint16)",hf_clusapi_clusapi_GetGroupId_pGuid);
return offset;
}
static int
clusapi_dissect_element_GetGroupId_pGuid__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_GetGroupId_pGuid, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_GetGroupId_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetGroupId_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_GetGroupId_rpc_status);
return offset;
}
static int
clusapi_dissect_element_GetGroupId_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetGroupId_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_GetGroupId_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="GetGroupId";
offset = clusapi_dissect_element_GetGroupId_pGuid(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetGroupId_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_GetGroupId_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="GetGroupId";
offset = clusapi_dissect_element_GetGroupId_hGroup(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_GetNodeId_hNode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetNodeId_hNode, 0);
return offset;
}
static int
clusapi_dissect_element_GetNodeId_pGuid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNodeId_pGuid_, NDR_POINTER_REF, "Pointer to PGuid (uint16)",hf_clusapi_clusapi_GetNodeId_pGuid);
return offset;
}
static int
clusapi_dissect_element_GetNodeId_pGuid_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNodeId_pGuid__, NDR_POINTER_UNIQUE, "Pointer to PGuid (uint16)",hf_clusapi_clusapi_GetNodeId_pGuid);
return offset;
}
static int
clusapi_dissect_element_GetNodeId_pGuid__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_GetNodeId_pGuid, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_GetNodeId_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNodeId_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_GetNodeId_rpc_status);
return offset;
}
static int
clusapi_dissect_element_GetNodeId_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetNodeId_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_GetNodeId_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="GetNodeId";
offset = clusapi_dissect_element_GetNodeId_pGuid(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetNodeId_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_GetNodeId_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="GetNodeId";
offset = clusapi_dissect_element_GetNodeId_hNode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_OnlineGroup_hGroup(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OnlineGroup_hGroup, 0);
return offset;
}
static int
clusapi_dissect_element_OnlineGroup_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OnlineGroup_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_OnlineGroup_rpc_status);
return offset;
}
static int
clusapi_dissect_element_OnlineGroup_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OnlineGroup_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_OnlineGroup_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="OnlineGroup";
offset = clusapi_dissect_element_OnlineGroup_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_OnlineGroup_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OnlineGroup";
offset = clusapi_dissect_element_OnlineGroup_hGroup(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_OfflineGroup_hGroup(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OfflineGroup_hGroup, 0);
return offset;
}
static int
clusapi_dissect_element_OfflineGroup_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OfflineGroup_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_OfflineGroup_rpc_status);
return offset;
}
static int
clusapi_dissect_element_OfflineGroup_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OfflineGroup_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_OfflineGroup_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="OfflineGroup";
offset = clusapi_dissect_element_OfflineGroup_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_OfflineGroup_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OfflineGroup";
offset = clusapi_dissect_element_OfflineGroup_hGroup(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_MoveGroup_hGroup(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_MoveGroup_hGroup, 0);
return offset;
}
static int
clusapi_dissect_element_MoveGroup_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_MoveGroup_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_MoveGroup_rpc_status);
return offset;
}
static int
clusapi_dissect_element_MoveGroup_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_MoveGroup_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_MoveGroup_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="MoveGroup";
offset = clusapi_dissect_element_MoveGroup_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_MoveGroup_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="MoveGroup";
offset = clusapi_dissect_element_MoveGroup_hGroup(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_MoveGroupToNode_hGroup(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_MoveGroupToNode_hGroup, 0);
return offset;
}
static int
clusapi_dissect_element_MoveGroupToNode_hNode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_MoveGroupToNode_hNode, 0);
return offset;
}
static int
clusapi_dissect_element_MoveGroupToNode_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_MoveGroupToNode_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_MoveGroupToNode_rpc_status);
return offset;
}
static int
clusapi_dissect_element_MoveGroupToNode_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_MoveGroupToNode_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_MoveGroupToNode_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="MoveGroupToNode";
offset = clusapi_dissect_element_MoveGroupToNode_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_MoveGroupToNode_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="MoveGroupToNode";
offset = clusapi_dissect_element_MoveGroupToNode_hGroup(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_MoveGroupToNode_hNode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_CreateGroupResourceEnum_hGroup(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateGroupResourceEnum_hGroup, 0);
return offset;
}
static int
clusapi_dissect_element_CreateGroupResourceEnum_dwType(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_bitmap_ClusterGroupEnumType(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateGroupResourceEnum_dwType, 0);
return offset;
}
static int
clusapi_dissect_element_CreateGroupResourceEnum_ReturnEnum(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateGroupResourceEnum_ReturnEnum_, NDR_POINTER_REF, "Pointer to ReturnEnum (ENUM_LIST)",hf_clusapi_clusapi_CreateGroupResourceEnum_ReturnEnum);
return offset;
}
static int
clusapi_dissect_element_CreateGroupResourceEnum_ReturnEnum_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateGroupResourceEnum_ReturnEnum__, NDR_POINTER_UNIQUE, "Pointer to ReturnEnum (ENUM_LIST)",hf_clusapi_clusapi_CreateGroupResourceEnum_ReturnEnum);
return offset;
}
static int
clusapi_dissect_element_CreateGroupResourceEnum_ReturnEnum__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_struct_ENUM_LIST(tvb,offset,pinfo,tree,di,drep,hf_clusapi_clusapi_CreateGroupResourceEnum_ReturnEnum,0);
return offset;
}
static int
clusapi_dissect_element_CreateGroupResourceEnum_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateGroupResourceEnum_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_CreateGroupResourceEnum_rpc_status);
return offset;
}
static int
clusapi_dissect_element_CreateGroupResourceEnum_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateGroupResourceEnum_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_CreateGroupResourceEnum_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="CreateGroupResourceEnum";
offset = clusapi_dissect_element_CreateGroupResourceEnum_ReturnEnum(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateGroupResourceEnum_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_CreateGroupResourceEnum_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CreateGroupResourceEnum";
offset = clusapi_dissect_element_CreateGroupResourceEnum_hGroup(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateGroupResourceEnum_dwType(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_SetGroupNodeList_hGroup(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_SetGroupNodeList_hGroup, 0);
return offset;
}
static int
clusapi_dissect_element_SetGroupNodeList_multiSzNodeList(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_SetGroupNodeList_multiSzNodeList_, NDR_POINTER_UNIQUE, "Pointer to MultiSzNodeList (uint16)",hf_clusapi_clusapi_SetGroupNodeList_multiSzNodeList);
return offset;
}
static int
clusapi_dissect_element_SetGroupNodeList_multiSzNodeList_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_SetGroupNodeList_multiSzNodeList__);
return offset;
}
static int
clusapi_dissect_element_SetGroupNodeList_multiSzNodeList__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_SetGroupNodeList_multiSzNodeList, 0);
return offset;
}
static int
clusapi_dissect_element_SetGroupNodeList_cchListSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_SetGroupNodeList_cchListSize, 0);
return offset;
}
static int
clusapi_dissect_element_SetGroupNodeList_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_SetGroupNodeList_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_SetGroupNodeList_rpc_status);
return offset;
}
static int
clusapi_dissect_element_SetGroupNodeList_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_SetGroupNodeList_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_SetGroupNodeList_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="SetGroupNodeList";
offset = clusapi_dissect_element_SetGroupNodeList_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_SetGroupNodeList_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="SetGroupNodeList";
offset = clusapi_dissect_element_SetGroupNodeList_hGroup(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_SetGroupNodeList_multiSzNodeList(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_SetGroupNodeList_cchListSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_CreateNotify_Status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateNotify_Status_, NDR_POINTER_REF, "Pointer to Status (WERROR)",hf_clusapi_clusapi_CreateNotify_Status);
return offset;
}
static int
clusapi_dissect_element_CreateNotify_Status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateNotify_Status, 0);
return offset;
}
static int
clusapi_dissect_element_CreateNotify_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateNotify_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_CreateNotify_rpc_status);
return offset;
}
static int
clusapi_dissect_element_CreateNotify_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateNotify_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_element_CreateNotify_hNotify(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateNotify_hNotify_, NDR_POINTER_REF, "Pointer to HNotify (policy_handle)",hf_clusapi_clusapi_CreateNotify_hNotify);
return offset;
}
static int
clusapi_dissect_element_CreateNotify_hNotify_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateNotify_hNotify, 0);
return offset;
}
static int
clusapi_dissect_CreateNotify_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CreateNotify";
offset = clusapi_dissect_element_CreateNotify_Status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateNotify_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateNotify_hNotify(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_CreateNotify_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CreateNotify";
return offset;
}
static int
clusapi_dissect_element_CloseNotify_Notify(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CloseNotify_Notify_, NDR_POINTER_REF, "Pointer to Notify (policy_handle)",hf_clusapi_clusapi_CloseNotify_Notify);
return offset;
}
static int
clusapi_dissect_element_CloseNotify_Notify_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CloseNotify_Notify, 0);
return offset;
}
static int
clusapi_dissect_CloseNotify_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="CloseNotify";
offset = clusapi_dissect_element_CloseNotify_Notify(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_CloseNotify_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CloseNotify";
offset = clusapi_dissect_element_CloseNotify_Notify(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_AddNotifyCluster_hNotify(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyCluster_hNotify, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyCluster_hCluster(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyCluster_hCluster, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyCluster_dwFilter(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyCluster_dwFilter, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyCluster_dwNotifyKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyCluster_dwNotifyKey, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyCluster_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_AddNotifyCluster_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_AddNotifyCluster_rpc_status);
return offset;
}
static int
clusapi_dissect_element_AddNotifyCluster_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyCluster_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_AddNotifyCluster_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="AddNotifyCluster";
offset = clusapi_dissect_element_AddNotifyCluster_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_AddNotifyCluster_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="AddNotifyCluster";
offset = clusapi_dissect_element_AddNotifyCluster_hNotify(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyCluster_hCluster(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyCluster_dwFilter(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyCluster_dwNotifyKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_AddNotifyNode_hNotify(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyNode_hNotify, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyNode_hNode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyNode_hNode, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyNode_dwFilter(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyNode_dwFilter, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyNode_dwNotifyKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyNode_dwNotifyKey, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyNode_dwStateSequence(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_AddNotifyNode_dwStateSequence_, NDR_POINTER_REF, "Pointer to DwStateSequence (uint32)",hf_clusapi_clusapi_AddNotifyNode_dwStateSequence);
return offset;
}
static int
clusapi_dissect_element_AddNotifyNode_dwStateSequence_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyNode_dwStateSequence, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyNode_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_AddNotifyNode_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_AddNotifyNode_rpc_status);
return offset;
}
static int
clusapi_dissect_element_AddNotifyNode_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyNode_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_AddNotifyNode_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="AddNotifyNode";
offset = clusapi_dissect_element_AddNotifyNode_dwStateSequence(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyNode_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_AddNotifyNode_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="AddNotifyNode";
offset = clusapi_dissect_element_AddNotifyNode_hNotify(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyNode_hNode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyNode_dwFilter(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyNode_dwNotifyKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_AddNotifyGroup_hNotify(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyGroup_hNotify, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyGroup_hGroup(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyGroup_hGroup, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyGroup_dwFilter(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyGroup_dwFilter, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyGroup_dwNotifyKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyGroup_dwNotifyKey, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyGroup_dwStateSequence(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_AddNotifyGroup_dwStateSequence_, NDR_POINTER_REF, "Pointer to DwStateSequence (uint32)",hf_clusapi_clusapi_AddNotifyGroup_dwStateSequence);
return offset;
}
static int
clusapi_dissect_element_AddNotifyGroup_dwStateSequence_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyGroup_dwStateSequence, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyGroup_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_AddNotifyGroup_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_AddNotifyGroup_rpc_status);
return offset;
}
static int
clusapi_dissect_element_AddNotifyGroup_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyGroup_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_AddNotifyGroup_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="AddNotifyGroup";
offset = clusapi_dissect_element_AddNotifyGroup_dwStateSequence(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyGroup_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_AddNotifyGroup_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="AddNotifyGroup";
offset = clusapi_dissect_element_AddNotifyGroup_hNotify(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyGroup_hGroup(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyGroup_dwFilter(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyGroup_dwNotifyKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_AddNotifyResource_hNotify(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyResource_hNotify, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyResource_hResource(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyResource_hResource, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyResource_dwFilter(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyResource_dwFilter, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyResource_dwNotifyKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyResource_dwNotifyKey, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyResource_dwStateSequence(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_AddNotifyResource_dwStateSequence_, NDR_POINTER_REF, "Pointer to DwStateSequence (uint32)",hf_clusapi_clusapi_AddNotifyResource_dwStateSequence);
return offset;
}
static int
clusapi_dissect_element_AddNotifyResource_dwStateSequence_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyResource_dwStateSequence, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyResource_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_AddNotifyResource_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_AddNotifyResource_rpc_status);
return offset;
}
static int
clusapi_dissect_element_AddNotifyResource_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyResource_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_AddNotifyResource_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="AddNotifyResource";
offset = clusapi_dissect_element_AddNotifyResource_dwStateSequence(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyResource_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_AddNotifyResource_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="AddNotifyResource";
offset = clusapi_dissect_element_AddNotifyResource_hNotify(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyResource_hResource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyResource_dwFilter(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyResource_dwNotifyKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_AddNotifyKey_hNotify(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyKey_hNotify, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyKey_hKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyKey_hKey, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyKey_dwNotifyKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyKey_dwNotifyKey, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyKey_Filter(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyKey_Filter, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyKey_WatchSubTree(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyKey_WatchSubTree, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyKey_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_AddNotifyKey_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_AddNotifyKey_rpc_status);
return offset;
}
static int
clusapi_dissect_element_AddNotifyKey_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyKey_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_AddNotifyKey_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="AddNotifyKey";
offset = clusapi_dissect_element_AddNotifyKey_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_AddNotifyKey_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="AddNotifyKey";
offset = clusapi_dissect_element_AddNotifyKey_hNotify(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyKey_hKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyKey_dwNotifyKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyKey_Filter(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyKey_WatchSubTree(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyNode_hNotify(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ReAddNotifyNode_hNotify, 0);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyNode_hNode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ReAddNotifyNode_hNode, 0);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyNode_dwFilter(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ReAddNotifyNode_dwFilter, 0);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyNode_dwNotifyKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ReAddNotifyNode_dwNotifyKey, 0);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyNode_StateSequence(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ReAddNotifyNode_StateSequence, 0);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyNode_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ReAddNotifyNode_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_ReAddNotifyNode_rpc_status);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyNode_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ReAddNotifyNode_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_ReAddNotifyNode_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="ReAddNotifyNode";
offset = clusapi_dissect_element_ReAddNotifyNode_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_ReAddNotifyNode_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="ReAddNotifyNode";
offset = clusapi_dissect_element_ReAddNotifyNode_hNotify(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ReAddNotifyNode_hNode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ReAddNotifyNode_dwFilter(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ReAddNotifyNode_dwNotifyKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ReAddNotifyNode_StateSequence(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyGroup_hNotify(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ReAddNotifyGroup_hNotify, 0);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyGroup_hGroup(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ReAddNotifyGroup_hGroup, 0);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyGroup_dwFilter(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ReAddNotifyGroup_dwFilter, 0);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyGroup_dwNotifyKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ReAddNotifyGroup_dwNotifyKey, 0);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyGroup_StateSequence(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ReAddNotifyGroup_StateSequence, 0);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyGroup_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ReAddNotifyGroup_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_ReAddNotifyGroup_rpc_status);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyGroup_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ReAddNotifyGroup_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_ReAddNotifyGroup_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="ReAddNotifyGroup";
offset = clusapi_dissect_element_ReAddNotifyGroup_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_ReAddNotifyGroup_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="ReAddNotifyGroup";
offset = clusapi_dissect_element_ReAddNotifyGroup_hNotify(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ReAddNotifyGroup_hGroup(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ReAddNotifyGroup_dwFilter(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ReAddNotifyGroup_dwNotifyKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ReAddNotifyGroup_StateSequence(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyResource_hNotify(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ReAddNotifyResource_hNotify, 0);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyResource_hResource(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ReAddNotifyResource_hResource, 0);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyResource_dwFilter(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ReAddNotifyResource_dwFilter, 0);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyResource_dwNotifyKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ReAddNotifyResource_dwNotifyKey, 0);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyResource_StateSequence(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ReAddNotifyResource_StateSequence, 0);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyResource_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ReAddNotifyResource_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_ReAddNotifyResource_rpc_status);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyResource_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ReAddNotifyResource_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_ReAddNotifyResource_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="ReAddNotifyResource";
offset = clusapi_dissect_element_ReAddNotifyResource_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_ReAddNotifyResource_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="ReAddNotifyResource";
offset = clusapi_dissect_element_ReAddNotifyResource_hNotify(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ReAddNotifyResource_hResource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ReAddNotifyResource_dwFilter(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ReAddNotifyResource_dwNotifyKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ReAddNotifyResource_StateSequence(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_GetNotify_hNotify(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetNotify_hNotify, 0);
return offset;
}
static int
clusapi_dissect_element_GetNotify_dwNotifyKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNotify_dwNotifyKey_, NDR_POINTER_REF, "Pointer to DwNotifyKey (uint32)",hf_clusapi_clusapi_GetNotify_dwNotifyKey);
return offset;
}
static int
clusapi_dissect_element_GetNotify_dwNotifyKey_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetNotify_dwNotifyKey, 0);
return offset;
}
static int
clusapi_dissect_element_GetNotify_dwFilter(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNotify_dwFilter_, NDR_POINTER_REF, "Pointer to DwFilter (uint32)",hf_clusapi_clusapi_GetNotify_dwFilter);
return offset;
}
static int
clusapi_dissect_element_GetNotify_dwFilter_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetNotify_dwFilter, 0);
return offset;
}
static int
clusapi_dissect_element_GetNotify_dwStateSequence(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNotify_dwStateSequence_, NDR_POINTER_REF, "Pointer to DwStateSequence (uint32)",hf_clusapi_clusapi_GetNotify_dwStateSequence);
return offset;
}
static int
clusapi_dissect_element_GetNotify_dwStateSequence_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetNotify_dwStateSequence, 0);
return offset;
}
static int
clusapi_dissect_element_GetNotify_Name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNotify_Name_, NDR_POINTER_REF, "Pointer to Name (uint16)",hf_clusapi_clusapi_GetNotify_Name);
return offset;
}
static int
clusapi_dissect_element_GetNotify_Name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNotify_Name__, NDR_POINTER_UNIQUE, "Pointer to Name (uint16)",hf_clusapi_clusapi_GetNotify_Name);
return offset;
}
static int
clusapi_dissect_element_GetNotify_Name__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_GetNotify_Name, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_GetNotify_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNotify_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_GetNotify_rpc_status);
return offset;
}
static int
clusapi_dissect_element_GetNotify_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetNotify_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_GetNotify_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="GetNotify";
offset = clusapi_dissect_element_GetNotify_dwNotifyKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetNotify_dwFilter(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetNotify_dwStateSequence(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetNotify_Name(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetNotify_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_GetNotify_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="GetNotify";
offset = clusapi_dissect_element_GetNotify_hNotify(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_OpenNode_lpszNodeName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenNode_lpszNodeName_, NDR_POINTER_REF, "Pointer to LpszNodeName (uint16)",hf_clusapi_clusapi_OpenNode_lpszNodeName);
return offset;
}
static int
clusapi_dissect_element_OpenNode_lpszNodeName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_OpenNode_lpszNodeName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_OpenNode_Status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenNode_Status_, NDR_POINTER_REF, "Pointer to Status (WERROR)",hf_clusapi_clusapi_OpenNode_Status);
return offset;
}
static int
clusapi_dissect_element_OpenNode_Status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenNode_Status, 0);
return offset;
}
static int
clusapi_dissect_element_OpenNode_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenNode_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_OpenNode_rpc_status);
return offset;
}
static int
clusapi_dissect_element_OpenNode_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenNode_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_element_OpenNode_hNode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenNode_hNode_, NDR_POINTER_REF, "Pointer to HNode (policy_handle)",hf_clusapi_clusapi_OpenNode_hNode);
return offset;
}
static int
clusapi_dissect_element_OpenNode_hNode_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenNode_hNode, 0);
return offset;
}
static int
clusapi_dissect_OpenNode_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OpenNode";
offset = clusapi_dissect_element_OpenNode_Status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenNode_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenNode_hNode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_OpenNode_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OpenNode";
offset = clusapi_dissect_element_OpenNode_lpszNodeName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_CloseNode_Node(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CloseNode_Node_, NDR_POINTER_REF, "Pointer to Node (policy_handle)",hf_clusapi_clusapi_CloseNode_Node);
return offset;
}
static int
clusapi_dissect_element_CloseNode_Node_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CloseNode_Node, 0);
return offset;
}
static int
clusapi_dissect_CloseNode_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="CloseNode";
offset = clusapi_dissect_element_CloseNode_Node(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_CloseNode_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CloseNode";
offset = clusapi_dissect_element_CloseNode_Node(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_GetNodeState_hNode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetNodeState_hNode, 0);
return offset;
}
static int
clusapi_dissect_element_GetNodeState_State(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNodeState_State_, NDR_POINTER_REF, "Pointer to State (clusapi_ClusterNodeState)",hf_clusapi_clusapi_GetNodeState_State);
return offset;
}
static int
clusapi_dissect_element_GetNodeState_State_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_enum_ClusterNodeState(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetNodeState_State, 0);
return offset;
}
static int
clusapi_dissect_element_GetNodeState_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNodeState_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_GetNodeState_rpc_status);
return offset;
}
static int
clusapi_dissect_element_GetNodeState_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetNodeState_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_GetNodeState_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="GetNodeState";
offset = clusapi_dissect_element_GetNodeState_State(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetNodeState_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_GetNodeState_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="GetNodeState";
offset = clusapi_dissect_element_GetNodeState_hNode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_PauseNode_hNode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_PauseNode_hNode, 0);
return offset;
}
static int
clusapi_dissect_element_PauseNode_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_PauseNode_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_PauseNode_rpc_status);
return offset;
}
static int
clusapi_dissect_element_PauseNode_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_PauseNode_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_PauseNode_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="PauseNode";
offset = clusapi_dissect_element_PauseNode_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_PauseNode_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="PauseNode";
offset = clusapi_dissect_element_PauseNode_hNode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_ResumeNode_hNode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ResumeNode_hNode, 0);
return offset;
}
static int
clusapi_dissect_element_ResumeNode_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ResumeNode_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_ResumeNode_rpc_status);
return offset;
}
static int
clusapi_dissect_element_ResumeNode_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ResumeNode_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_ResumeNode_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="ResumeNode";
offset = clusapi_dissect_element_ResumeNode_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_ResumeNode_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="ResumeNode";
offset = clusapi_dissect_element_ResumeNode_hNode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_EvictNode_hNode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_EvictNode_hNode, 0);
return offset;
}
static int
clusapi_dissect_element_EvictNode_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_EvictNode_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_EvictNode_rpc_status);
return offset;
}
static int
clusapi_dissect_element_EvictNode_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_EvictNode_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_EvictNode_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="EvictNode";
offset = clusapi_dissect_element_EvictNode_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_EvictNode_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="EvictNode";
offset = clusapi_dissect_element_EvictNode_hNode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_NodeResourceControl_hResource(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeResourceControl_hResource, 0);
return offset;
}
static int
clusapi_dissect_element_NodeResourceControl_hNode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeResourceControl_hNode, 0);
return offset;
}
static int
clusapi_dissect_element_NodeResourceControl_dwControlCode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeResourceControl_dwControlCode, 0);
return offset;
}
static int
clusapi_dissect_element_NodeResourceControl_lpInBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeResourceControl_lpInBuffer_, NDR_POINTER_UNIQUE, "Pointer to LpInBuffer (uint8)",hf_clusapi_clusapi_NodeResourceControl_lpInBuffer);
return offset;
}
static int
clusapi_dissect_element_NodeResourceControl_lpInBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeResourceControl_lpInBuffer__);
return offset;
}
static int
clusapi_dissect_element_NodeResourceControl_lpInBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeResourceControl_lpInBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_NodeResourceControl_nInBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeResourceControl_nInBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_NodeResourceControl_lpOutBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeResourceControl_lpOutBuffer_, NDR_POINTER_REF, "Pointer to LpOutBuffer (uint8)",hf_clusapi_clusapi_NodeResourceControl_lpOutBuffer);
return offset;
}
static int
clusapi_dissect_element_NodeResourceControl_lpOutBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucvarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeResourceControl_lpOutBuffer__);
return offset;
}
static int
clusapi_dissect_element_NodeResourceControl_lpOutBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeResourceControl_lpOutBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_NodeResourceControl_nOutBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeResourceControl_nOutBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_NodeResourceControl_lpBytesReturned(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeResourceControl_lpBytesReturned_, NDR_POINTER_REF, "Pointer to LpBytesReturned (uint32)",hf_clusapi_clusapi_NodeResourceControl_lpBytesReturned);
return offset;
}
static int
clusapi_dissect_element_NodeResourceControl_lpBytesReturned_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeResourceControl_lpBytesReturned, 0);
return offset;
}
static int
clusapi_dissect_element_NodeResourceControl_lpcbRequired(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeResourceControl_lpcbRequired_, NDR_POINTER_REF, "Pointer to LpcbRequired (uint32)",hf_clusapi_clusapi_NodeResourceControl_lpcbRequired);
return offset;
}
static int
clusapi_dissect_element_NodeResourceControl_lpcbRequired_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeResourceControl_lpcbRequired, 0);
return offset;
}
static int
clusapi_dissect_element_NodeResourceControl_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeResourceControl_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_NodeResourceControl_rpc_status);
return offset;
}
static int
clusapi_dissect_element_NodeResourceControl_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeResourceControl_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_NodeResourceControl_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="NodeResourceControl";
offset = clusapi_dissect_element_NodeResourceControl_lpOutBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeResourceControl_lpBytesReturned(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeResourceControl_lpcbRequired(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeResourceControl_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_NodeResourceControl_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="NodeResourceControl";
offset = clusapi_dissect_element_NodeResourceControl_hResource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeResourceControl_hNode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeResourceControl_dwControlCode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeResourceControl_lpInBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeResourceControl_nInBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeResourceControl_nOutBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_ResourceControl_hResource(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ResourceControl_hResource, 0);
return offset;
}
static int
clusapi_dissect_element_ResourceControl_dwControlCode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_enum_ResourceControlCode(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ResourceControl_dwControlCode, 0);
return offset;
}
static int
clusapi_dissect_element_ResourceControl_lpInBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ResourceControl_lpInBuffer_, NDR_POINTER_UNIQUE, "Pointer to LpInBuffer (uint8)",hf_clusapi_clusapi_ResourceControl_lpInBuffer);
return offset;
}
static int
clusapi_dissect_element_ResourceControl_lpInBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ResourceControl_lpInBuffer__);
return offset;
}
static int
clusapi_dissect_element_ResourceControl_lpInBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ResourceControl_lpInBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_ResourceControl_nInBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ResourceControl_nInBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_ResourceControl_lpOutBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ResourceControl_lpOutBuffer_, NDR_POINTER_REF, "Pointer to LpOutBuffer (uint8)",hf_clusapi_clusapi_ResourceControl_lpOutBuffer);
return offset;
}
static int
clusapi_dissect_element_ResourceControl_lpOutBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucvarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ResourceControl_lpOutBuffer__);
return offset;
}
static int
clusapi_dissect_element_ResourceControl_lpOutBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ResourceControl_lpOutBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_ResourceControl_nOutBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ResourceControl_nOutBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_ResourceControl_lpBytesReturned(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ResourceControl_lpBytesReturned_, NDR_POINTER_REF, "Pointer to LpBytesReturned (uint32)",hf_clusapi_clusapi_ResourceControl_lpBytesReturned);
return offset;
}
static int
clusapi_dissect_element_ResourceControl_lpBytesReturned_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ResourceControl_lpBytesReturned, 0);
return offset;
}
static int
clusapi_dissect_element_ResourceControl_lpcbRequired(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ResourceControl_lpcbRequired_, NDR_POINTER_REF, "Pointer to LpcbRequired (uint32)",hf_clusapi_clusapi_ResourceControl_lpcbRequired);
return offset;
}
static int
clusapi_dissect_element_ResourceControl_lpcbRequired_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ResourceControl_lpcbRequired, 0);
return offset;
}
static int
clusapi_dissect_element_ResourceControl_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ResourceControl_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_ResourceControl_rpc_status);
return offset;
}
static int
clusapi_dissect_element_ResourceControl_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ResourceControl_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_ResourceControl_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="ResourceControl";
offset = clusapi_dissect_element_ResourceControl_lpOutBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ResourceControl_lpBytesReturned(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ResourceControl_lpcbRequired(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ResourceControl_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_ResourceControl_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="ResourceControl";
offset = clusapi_dissect_element_ResourceControl_hResource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ResourceControl_dwControlCode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ResourceControl_lpInBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ResourceControl_nInBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ResourceControl_nOutBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_NodeResourceTypeControl_hCluster(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeResourceTypeControl_hCluster, 0);
return offset;
}
static int
clusapi_dissect_element_NodeResourceTypeControl_lpszResourceTypeName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeResourceTypeControl_lpszResourceTypeName_, NDR_POINTER_REF, "Pointer to LpszResourceTypeName (uint16)",hf_clusapi_clusapi_NodeResourceTypeControl_lpszResourceTypeName);
return offset;
}
static int
clusapi_dissect_element_NodeResourceTypeControl_lpszResourceTypeName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_NodeResourceTypeControl_lpszResourceTypeName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_NodeResourceTypeControl_hNode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeResourceTypeControl_hNode, 0);
return offset;
}
static int
clusapi_dissect_element_NodeResourceTypeControl_dwControlCode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeResourceTypeControl_dwControlCode, 0);
return offset;
}
static int
clusapi_dissect_element_NodeResourceTypeControl_lpInBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeResourceTypeControl_lpInBuffer_, NDR_POINTER_UNIQUE, "Pointer to LpInBuffer (uint8)",hf_clusapi_clusapi_NodeResourceTypeControl_lpInBuffer);
return offset;
}
static int
clusapi_dissect_element_NodeResourceTypeControl_lpInBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeResourceTypeControl_lpInBuffer__);
return offset;
}
static int
clusapi_dissect_element_NodeResourceTypeControl_lpInBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeResourceTypeControl_lpInBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_NodeResourceTypeControl_nInBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeResourceTypeControl_nInBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_NodeResourceTypeControl_lpOutBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeResourceTypeControl_lpOutBuffer_, NDR_POINTER_REF, "Pointer to LpOutBuffer (uint8)",hf_clusapi_clusapi_NodeResourceTypeControl_lpOutBuffer);
return offset;
}
static int
clusapi_dissect_element_NodeResourceTypeControl_lpOutBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucvarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeResourceTypeControl_lpOutBuffer__);
return offset;
}
static int
clusapi_dissect_element_NodeResourceTypeControl_lpOutBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeResourceTypeControl_lpOutBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_NodeResourceTypeControl_nOutBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeResourceTypeControl_nOutBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_NodeResourceTypeControl_lpBytesReturned(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeResourceTypeControl_lpBytesReturned_, NDR_POINTER_REF, "Pointer to LpBytesReturned (uint32)",hf_clusapi_clusapi_NodeResourceTypeControl_lpBytesReturned);
return offset;
}
static int
clusapi_dissect_element_NodeResourceTypeControl_lpBytesReturned_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeResourceTypeControl_lpBytesReturned, 0);
return offset;
}
static int
clusapi_dissect_element_NodeResourceTypeControl_lpcbRequired(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeResourceTypeControl_lpcbRequired_, NDR_POINTER_REF, "Pointer to LpcbRequired (uint32)",hf_clusapi_clusapi_NodeResourceTypeControl_lpcbRequired);
return offset;
}
static int
clusapi_dissect_element_NodeResourceTypeControl_lpcbRequired_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeResourceTypeControl_lpcbRequired, 0);
return offset;
}
static int
clusapi_dissect_element_NodeResourceTypeControl_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeResourceTypeControl_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_NodeResourceTypeControl_rpc_status);
return offset;
}
static int
clusapi_dissect_element_NodeResourceTypeControl_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeResourceTypeControl_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_NodeResourceTypeControl_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="NodeResourceTypeControl";
offset = clusapi_dissect_element_NodeResourceTypeControl_lpOutBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeResourceTypeControl_lpBytesReturned(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeResourceTypeControl_lpcbRequired(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeResourceTypeControl_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_NodeResourceTypeControl_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="NodeResourceTypeControl";
offset = clusapi_dissect_element_NodeResourceTypeControl_hCluster(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeResourceTypeControl_lpszResourceTypeName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeResourceTypeControl_hNode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeResourceTypeControl_dwControlCode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeResourceTypeControl_lpInBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeResourceTypeControl_nInBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeResourceTypeControl_nOutBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_ResourceTypeControl_hCluster(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ResourceTypeControl_hCluster, 0);
return offset;
}
static int
clusapi_dissect_element_ResourceTypeControl_lpszResourceTypeName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ResourceTypeControl_lpszResourceTypeName_, NDR_POINTER_REF, "Pointer to LpszResourceTypeName (uint16)",hf_clusapi_clusapi_ResourceTypeControl_lpszResourceTypeName);
return offset;
}
static int
clusapi_dissect_element_ResourceTypeControl_lpszResourceTypeName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_ResourceTypeControl_lpszResourceTypeName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_ResourceTypeControl_dwControlCode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_enum_ResourceTypeControlCode(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ResourceTypeControl_dwControlCode, 0);
return offset;
}
static int
clusapi_dissect_element_ResourceTypeControl_lpInBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ResourceTypeControl_lpInBuffer_, NDR_POINTER_UNIQUE, "Pointer to LpInBuffer (uint8)",hf_clusapi_clusapi_ResourceTypeControl_lpInBuffer);
return offset;
}
static int
clusapi_dissect_element_ResourceTypeControl_lpInBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ResourceTypeControl_lpInBuffer__);
return offset;
}
static int
clusapi_dissect_element_ResourceTypeControl_lpInBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ResourceTypeControl_lpInBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_ResourceTypeControl_nInBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ResourceTypeControl_nInBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_ResourceTypeControl_lpOutBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ResourceTypeControl_lpOutBuffer_, NDR_POINTER_REF, "Pointer to LpOutBuffer (uint8)",hf_clusapi_clusapi_ResourceTypeControl_lpOutBuffer);
return offset;
}
static int
clusapi_dissect_element_ResourceTypeControl_lpOutBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucvarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ResourceTypeControl_lpOutBuffer__);
return offset;
}
static int
clusapi_dissect_element_ResourceTypeControl_lpOutBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ResourceTypeControl_lpOutBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_ResourceTypeControl_nOutBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ResourceTypeControl_nOutBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_ResourceTypeControl_lpBytesReturned(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ResourceTypeControl_lpBytesReturned_, NDR_POINTER_REF, "Pointer to LpBytesReturned (uint32)",hf_clusapi_clusapi_ResourceTypeControl_lpBytesReturned);
return offset;
}
static int
clusapi_dissect_element_ResourceTypeControl_lpBytesReturned_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ResourceTypeControl_lpBytesReturned, 0);
return offset;
}
static int
clusapi_dissect_element_ResourceTypeControl_lpcbRequired(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ResourceTypeControl_lpcbRequired_, NDR_POINTER_REF, "Pointer to LpcbRequired (uint32)",hf_clusapi_clusapi_ResourceTypeControl_lpcbRequired);
return offset;
}
static int
clusapi_dissect_element_ResourceTypeControl_lpcbRequired_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ResourceTypeControl_lpcbRequired, 0);
return offset;
}
static int
clusapi_dissect_element_ResourceTypeControl_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ResourceTypeControl_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_ResourceTypeControl_rpc_status);
return offset;
}
static int
clusapi_dissect_element_ResourceTypeControl_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ResourceTypeControl_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_ResourceTypeControl_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="ResourceTypeControl";
offset = clusapi_dissect_element_ResourceTypeControl_lpOutBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ResourceTypeControl_lpBytesReturned(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ResourceTypeControl_lpcbRequired(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ResourceTypeControl_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_ResourceTypeControl_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="ResourceTypeControl";
offset = clusapi_dissect_element_ResourceTypeControl_hCluster(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ResourceTypeControl_lpszResourceTypeName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ResourceTypeControl_dwControlCode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ResourceTypeControl_lpInBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ResourceTypeControl_nInBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ResourceTypeControl_nOutBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_NodeGroupControl_hGroup(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeGroupControl_hGroup, 0);
return offset;
}
static int
clusapi_dissect_element_NodeGroupControl_hNode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeGroupControl_hNode, 0);
return offset;
}
static int
clusapi_dissect_element_NodeGroupControl_dwControlCode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeGroupControl_dwControlCode, 0);
return offset;
}
static int
clusapi_dissect_element_NodeGroupControl_lpInBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeGroupControl_lpInBuffer_, NDR_POINTER_UNIQUE, "Pointer to LpInBuffer (uint8)",hf_clusapi_clusapi_NodeGroupControl_lpInBuffer);
return offset;
}
static int
clusapi_dissect_element_NodeGroupControl_lpInBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeGroupControl_lpInBuffer__);
return offset;
}
static int
clusapi_dissect_element_NodeGroupControl_lpInBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeGroupControl_lpInBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_NodeGroupControl_nInBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeGroupControl_nInBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_NodeGroupControl_lpOutBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeGroupControl_lpOutBuffer_, NDR_POINTER_REF, "Pointer to LpOutBuffer (uint8)",hf_clusapi_clusapi_NodeGroupControl_lpOutBuffer);
return offset;
}
static int
clusapi_dissect_element_NodeGroupControl_lpOutBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucvarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeGroupControl_lpOutBuffer__);
return offset;
}
static int
clusapi_dissect_element_NodeGroupControl_lpOutBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeGroupControl_lpOutBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_NodeGroupControl_nOutBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeGroupControl_nOutBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_NodeGroupControl_lpBytesReturned(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeGroupControl_lpBytesReturned_, NDR_POINTER_REF, "Pointer to LpBytesReturned (uint32)",hf_clusapi_clusapi_NodeGroupControl_lpBytesReturned);
return offset;
}
static int
clusapi_dissect_element_NodeGroupControl_lpBytesReturned_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeGroupControl_lpBytesReturned, 0);
return offset;
}
static int
clusapi_dissect_element_NodeGroupControl_lpcbRequired(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeGroupControl_lpcbRequired_, NDR_POINTER_REF, "Pointer to LpcbRequired (uint32)",hf_clusapi_clusapi_NodeGroupControl_lpcbRequired);
return offset;
}
static int
clusapi_dissect_element_NodeGroupControl_lpcbRequired_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeGroupControl_lpcbRequired, 0);
return offset;
}
static int
clusapi_dissect_element_NodeGroupControl_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeGroupControl_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_NodeGroupControl_rpc_status);
return offset;
}
static int
clusapi_dissect_element_NodeGroupControl_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeGroupControl_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_NodeGroupControl_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="NodeGroupControl";
offset = clusapi_dissect_element_NodeGroupControl_lpOutBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeGroupControl_lpBytesReturned(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeGroupControl_lpcbRequired(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeGroupControl_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_NodeGroupControl_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="NodeGroupControl";
offset = clusapi_dissect_element_NodeGroupControl_hGroup(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeGroupControl_hNode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeGroupControl_dwControlCode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeGroupControl_lpInBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeGroupControl_nInBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeGroupControl_nOutBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_GroupControl_hGroup(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GroupControl_hGroup, 0);
return offset;
}
static int
clusapi_dissect_element_GroupControl_dwControlCode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_enum_GroupControlCode(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GroupControl_dwControlCode, 0);
return offset;
}
static int
clusapi_dissect_element_GroupControl_lpInBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GroupControl_lpInBuffer_, NDR_POINTER_UNIQUE, "Pointer to LpInBuffer (uint8)",hf_clusapi_clusapi_GroupControl_lpInBuffer);
return offset;
}
static int
clusapi_dissect_element_GroupControl_lpInBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GroupControl_lpInBuffer__);
return offset;
}
static int
clusapi_dissect_element_GroupControl_lpInBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GroupControl_lpInBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_GroupControl_nInBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GroupControl_nInBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_GroupControl_lpOutBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GroupControl_lpOutBuffer_, NDR_POINTER_REF, "Pointer to LpOutBuffer (uint8)",hf_clusapi_clusapi_GroupControl_lpOutBuffer);
return offset;
}
static int
clusapi_dissect_element_GroupControl_lpOutBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucvarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GroupControl_lpOutBuffer__);
return offset;
}
static int
clusapi_dissect_element_GroupControl_lpOutBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GroupControl_lpOutBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_GroupControl_nOutBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GroupControl_nOutBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_GroupControl_lpBytesReturned(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GroupControl_lpBytesReturned_, NDR_POINTER_REF, "Pointer to LpBytesReturned (uint32)",hf_clusapi_clusapi_GroupControl_lpBytesReturned);
return offset;
}
static int
clusapi_dissect_element_GroupControl_lpBytesReturned_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GroupControl_lpBytesReturned, 0);
return offset;
}
static int
clusapi_dissect_element_GroupControl_lpcbRequired(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GroupControl_lpcbRequired_, NDR_POINTER_REF, "Pointer to LpcbRequired (uint32)",hf_clusapi_clusapi_GroupControl_lpcbRequired);
return offset;
}
static int
clusapi_dissect_element_GroupControl_lpcbRequired_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GroupControl_lpcbRequired, 0);
return offset;
}
static int
clusapi_dissect_element_GroupControl_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GroupControl_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_GroupControl_rpc_status);
return offset;
}
static int
clusapi_dissect_element_GroupControl_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GroupControl_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_GroupControl_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="GroupControl";
offset = clusapi_dissect_element_GroupControl_lpOutBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GroupControl_lpBytesReturned(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GroupControl_lpcbRequired(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GroupControl_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_GroupControl_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="GroupControl";
offset = clusapi_dissect_element_GroupControl_hGroup(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GroupControl_dwControlCode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GroupControl_lpInBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GroupControl_nInBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GroupControl_nOutBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_NodeNodeControl_hNode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeNodeControl_hNode, 0);
return offset;
}
static int
clusapi_dissect_element_NodeNodeControl_hHostNode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeNodeControl_hHostNode, 0);
return offset;
}
static int
clusapi_dissect_element_NodeNodeControl_dwControlCode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeNodeControl_dwControlCode, 0);
return offset;
}
static int
clusapi_dissect_element_NodeNodeControl_lpInBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeNodeControl_lpInBuffer_, NDR_POINTER_UNIQUE, "Pointer to LpInBuffer (uint8)",hf_clusapi_clusapi_NodeNodeControl_lpInBuffer);
return offset;
}
static int
clusapi_dissect_element_NodeNodeControl_lpInBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeNodeControl_lpInBuffer__);
return offset;
}
static int
clusapi_dissect_element_NodeNodeControl_lpInBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeNodeControl_lpInBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_NodeNodeControl_nInBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeNodeControl_nInBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_NodeNodeControl_lpOutBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeNodeControl_lpOutBuffer_, NDR_POINTER_REF, "Pointer to LpOutBuffer (uint8)",hf_clusapi_clusapi_NodeNodeControl_lpOutBuffer);
return offset;
}
static int
clusapi_dissect_element_NodeNodeControl_lpOutBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucvarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeNodeControl_lpOutBuffer__);
return offset;
}
static int
clusapi_dissect_element_NodeNodeControl_lpOutBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeNodeControl_lpOutBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_NodeNodeControl_nOutBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeNodeControl_nOutBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_NodeNodeControl_lpBytesReturned(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeNodeControl_lpBytesReturned_, NDR_POINTER_REF, "Pointer to LpBytesReturned (uint32)",hf_clusapi_clusapi_NodeNodeControl_lpBytesReturned);
return offset;
}
static int
clusapi_dissect_element_NodeNodeControl_lpBytesReturned_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeNodeControl_lpBytesReturned, 0);
return offset;
}
static int
clusapi_dissect_element_NodeNodeControl_lpcbRequired(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeNodeControl_lpcbRequired_, NDR_POINTER_REF, "Pointer to LpcbRequired (uint32)",hf_clusapi_clusapi_NodeNodeControl_lpcbRequired);
return offset;
}
static int
clusapi_dissect_element_NodeNodeControl_lpcbRequired_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeNodeControl_lpcbRequired, 0);
return offset;
}
static int
clusapi_dissect_element_NodeNodeControl_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeNodeControl_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_NodeNodeControl_rpc_status);
return offset;
}
static int
clusapi_dissect_element_NodeNodeControl_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeNodeControl_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_NodeNodeControl_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="NodeNodeControl";
offset = clusapi_dissect_element_NodeNodeControl_lpOutBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeNodeControl_lpBytesReturned(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeNodeControl_lpcbRequired(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeNodeControl_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_NodeNodeControl_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="NodeNodeControl";
offset = clusapi_dissect_element_NodeNodeControl_hNode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeNodeControl_hHostNode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeNodeControl_dwControlCode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeNodeControl_lpInBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeNodeControl_nInBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeNodeControl_nOutBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_NodeControl_hNode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeControl_hNode, 0);
return offset;
}
static int
clusapi_dissect_element_NodeControl_dwControlCode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_enum_NodeControlCode(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeControl_dwControlCode, 0);
return offset;
}
static int
clusapi_dissect_element_NodeControl_lpInBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeControl_lpInBuffer_, NDR_POINTER_UNIQUE, "Pointer to LpInBuffer (uint8)",hf_clusapi_clusapi_NodeControl_lpInBuffer);
return offset;
}
static int
clusapi_dissect_element_NodeControl_lpInBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeControl_lpInBuffer__);
return offset;
}
static int
clusapi_dissect_element_NodeControl_lpInBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeControl_lpInBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_NodeControl_nInBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeControl_nInBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_NodeControl_lpOutBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeControl_lpOutBuffer_, NDR_POINTER_REF, "Pointer to LpOutBuffer (uint8)",hf_clusapi_clusapi_NodeControl_lpOutBuffer);
return offset;
}
static int
clusapi_dissect_element_NodeControl_lpOutBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucvarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeControl_lpOutBuffer__);
return offset;
}
static int
clusapi_dissect_element_NodeControl_lpOutBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeControl_lpOutBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_NodeControl_nOutBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeControl_nOutBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_NodeControl_lpBytesReturned(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeControl_lpBytesReturned_, NDR_POINTER_REF, "Pointer to LpBytesReturned (uint32)",hf_clusapi_clusapi_NodeControl_lpBytesReturned);
return offset;
}
static int
clusapi_dissect_element_NodeControl_lpBytesReturned_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeControl_lpBytesReturned, 0);
return offset;
}
static int
clusapi_dissect_element_NodeControl_lpcbRequired(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeControl_lpcbRequired_, NDR_POINTER_REF, "Pointer to LpcbRequired (uint32)",hf_clusapi_clusapi_NodeControl_lpcbRequired);
return offset;
}
static int
clusapi_dissect_element_NodeControl_lpcbRequired_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeControl_lpcbRequired, 0);
return offset;
}
static int
clusapi_dissect_element_NodeControl_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeControl_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_NodeControl_rpc_status);
return offset;
}
static int
clusapi_dissect_element_NodeControl_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeControl_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_NodeControl_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="NodeControl";
offset = clusapi_dissect_element_NodeControl_lpOutBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeControl_lpBytesReturned(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeControl_lpcbRequired(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeControl_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_NodeControl_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="NodeControl";
offset = clusapi_dissect_element_NodeControl_hNode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeControl_dwControlCode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeControl_lpInBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeControl_nInBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeControl_nOutBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_Opnum80NotUsedOnWire_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="Opnum80NotUsedOnWire";
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_Opnum80NotUsedOnWire_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="Opnum80NotUsedOnWire";
return offset;
}
static int
clusapi_dissect_element_OpenNetwork_lpszNetworkName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenNetwork_lpszNetworkName_, NDR_POINTER_REF, "Pointer to LpszNetworkName (uint16)",hf_clusapi_clusapi_OpenNetwork_lpszNetworkName);
return offset;
}
static int
clusapi_dissect_element_OpenNetwork_lpszNetworkName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_OpenNetwork_lpszNetworkName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_OpenNetwork_Status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenNetwork_Status_, NDR_POINTER_REF, "Pointer to Status (WERROR)",hf_clusapi_clusapi_OpenNetwork_Status);
return offset;
}
static int
clusapi_dissect_element_OpenNetwork_Status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenNetwork_Status, 0);
return offset;
}
static int
clusapi_dissect_element_OpenNetwork_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenNetwork_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_OpenNetwork_rpc_status);
return offset;
}
static int
clusapi_dissect_element_OpenNetwork_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenNetwork_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_element_OpenNetwork_hNetwork(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenNetwork_hNetwork_, NDR_POINTER_REF, "Pointer to HNetwork (policy_handle)",hf_clusapi_clusapi_OpenNetwork_hNetwork);
return offset;
}
static int
clusapi_dissect_element_OpenNetwork_hNetwork_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenNetwork_hNetwork, 0);
return offset;
}
static int
clusapi_dissect_OpenNetwork_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OpenNetwork";
offset = clusapi_dissect_element_OpenNetwork_Status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenNetwork_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenNetwork_hNetwork(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_OpenNetwork_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OpenNetwork";
offset = clusapi_dissect_element_OpenNetwork_lpszNetworkName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_CloseNetwork_Network(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CloseNetwork_Network_, NDR_POINTER_REF, "Pointer to Network (policy_handle)",hf_clusapi_clusapi_CloseNetwork_Network);
return offset;
}
static int
clusapi_dissect_element_CloseNetwork_Network_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CloseNetwork_Network, 0);
return offset;
}
static int
clusapi_dissect_CloseNetwork_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="CloseNetwork";
offset = clusapi_dissect_element_CloseNetwork_Network(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_CloseNetwork_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CloseNetwork";
offset = clusapi_dissect_element_CloseNetwork_Network(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_GetNetworkState_hNetwork(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetNetworkState_hNetwork, 0);
return offset;
}
static int
clusapi_dissect_element_GetNetworkState_State(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNetworkState_State_, NDR_POINTER_REF, "Pointer to State (clusapi_ClusterNetworkState)",hf_clusapi_clusapi_GetNetworkState_State);
return offset;
}
static int
clusapi_dissect_element_GetNetworkState_State_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_enum_ClusterNetworkState(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetNetworkState_State, 0);
return offset;
}
static int
clusapi_dissect_element_GetNetworkState_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNetworkState_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_GetNetworkState_rpc_status);
return offset;
}
static int
clusapi_dissect_element_GetNetworkState_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetNetworkState_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_GetNetworkState_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="GetNetworkState";
offset = clusapi_dissect_element_GetNetworkState_State(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetNetworkState_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_GetNetworkState_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="GetNetworkState";
offset = clusapi_dissect_element_GetNetworkState_hNetwork(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_SetNetworkName_hNetwork(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_SetNetworkName_hNetwork, 0);
return offset;
}
static int
clusapi_dissect_element_SetNetworkName_lpszNetworkName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_SetNetworkName_lpszNetworkName_, NDR_POINTER_REF, "Pointer to LpszNetworkName (uint16)",hf_clusapi_clusapi_SetNetworkName_lpszNetworkName);
return offset;
}
static int
clusapi_dissect_element_SetNetworkName_lpszNetworkName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_SetNetworkName_lpszNetworkName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_SetNetworkName_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_SetNetworkName_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_SetNetworkName_rpc_status);
return offset;
}
static int
clusapi_dissect_element_SetNetworkName_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_SetNetworkName_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_SetNetworkName_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="SetNetworkName";
offset = clusapi_dissect_element_SetNetworkName_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_SetNetworkName_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="SetNetworkName";
offset = clusapi_dissect_element_SetNetworkName_hNetwork(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_SetNetworkName_lpszNetworkName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_CreateNetworkEnum_hNetwork(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateNetworkEnum_hNetwork, 0);
return offset;
}
static int
clusapi_dissect_element_CreateNetworkEnum_dwType(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateNetworkEnum_dwType, 0);
return offset;
}
static int
clusapi_dissect_element_CreateNetworkEnum_ReturnEnum(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateNetworkEnum_ReturnEnum_, NDR_POINTER_REF, "Pointer to ReturnEnum (ENUM_LIST)",hf_clusapi_clusapi_CreateNetworkEnum_ReturnEnum);
return offset;
}
static int
clusapi_dissect_element_CreateNetworkEnum_ReturnEnum_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateNetworkEnum_ReturnEnum__, NDR_POINTER_UNIQUE, "Pointer to ReturnEnum (ENUM_LIST)",hf_clusapi_clusapi_CreateNetworkEnum_ReturnEnum);
return offset;
}
static int
clusapi_dissect_element_CreateNetworkEnum_ReturnEnum__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_struct_ENUM_LIST(tvb,offset,pinfo,tree,di,drep,hf_clusapi_clusapi_CreateNetworkEnum_ReturnEnum,0);
return offset;
}
static int
clusapi_dissect_element_CreateNetworkEnum_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateNetworkEnum_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_CreateNetworkEnum_rpc_status);
return offset;
}
static int
clusapi_dissect_element_CreateNetworkEnum_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateNetworkEnum_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_CreateNetworkEnum_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="CreateNetworkEnum";
offset = clusapi_dissect_element_CreateNetworkEnum_ReturnEnum(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateNetworkEnum_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_CreateNetworkEnum_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CreateNetworkEnum";
offset = clusapi_dissect_element_CreateNetworkEnum_hNetwork(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateNetworkEnum_dwType(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_GetNetworkId_hNetwork(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetNetworkId_hNetwork, 0);
return offset;
}
static int
clusapi_dissect_element_GetNetworkId_pGuid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNetworkId_pGuid_, NDR_POINTER_REF, "Pointer to PGuid (uint16)",hf_clusapi_clusapi_GetNetworkId_pGuid);
return offset;
}
static int
clusapi_dissect_element_GetNetworkId_pGuid_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNetworkId_pGuid__, NDR_POINTER_UNIQUE, "Pointer to PGuid (uint16)",hf_clusapi_clusapi_GetNetworkId_pGuid);
return offset;
}
static int
clusapi_dissect_element_GetNetworkId_pGuid__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_GetNetworkId_pGuid, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_GetNetworkId_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNetworkId_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_GetNetworkId_rpc_status);
return offset;
}
static int
clusapi_dissect_element_GetNetworkId_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetNetworkId_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_GetNetworkId_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="GetNetworkId";
offset = clusapi_dissect_element_GetNetworkId_pGuid(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetNetworkId_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_GetNetworkId_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="GetNetworkId";
offset = clusapi_dissect_element_GetNetworkId_hNetwork(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_SetNetworkPriorityOrder_NetworkCount(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_SetNetworkPriorityOrder_NetworkCount, 0);
return offset;
}
static int
clusapi_dissect_element_SetNetworkPriorityOrder_NetworkIdList(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_SetNetworkPriorityOrder_NetworkIdList, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_SetNetworkPriorityOrder_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_SetNetworkPriorityOrder_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_SetNetworkPriorityOrder_rpc_status);
return offset;
}
static int
clusapi_dissect_element_SetNetworkPriorityOrder_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_SetNetworkPriorityOrder_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_SetNetworkPriorityOrder_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="SetNetworkPriorityOrder";
offset = clusapi_dissect_element_SetNetworkPriorityOrder_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_SetNetworkPriorityOrder_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="SetNetworkPriorityOrder";
offset = clusapi_dissect_element_SetNetworkPriorityOrder_NetworkCount(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_SetNetworkPriorityOrder_NetworkIdList(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_NodeNetworkControl_hNetwork(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeNetworkControl_hNetwork, 0);
return offset;
}
static int
clusapi_dissect_element_NodeNetworkControl_hNode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeNetworkControl_hNode, 0);
return offset;
}
static int
clusapi_dissect_element_NodeNetworkControl_dwControlCode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeNetworkControl_dwControlCode, 0);
return offset;
}
static int
clusapi_dissect_element_NodeNetworkControl_lpInBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeNetworkControl_lpInBuffer_, NDR_POINTER_UNIQUE, "Pointer to LpInBuffer (uint8)",hf_clusapi_clusapi_NodeNetworkControl_lpInBuffer);
return offset;
}
static int
clusapi_dissect_element_NodeNetworkControl_lpInBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeNetworkControl_lpInBuffer__);
return offset;
}
static int
clusapi_dissect_element_NodeNetworkControl_lpInBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeNetworkControl_lpInBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_NodeNetworkControl_nInBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeNetworkControl_nInBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_NodeNetworkControl_lpOutBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeNetworkControl_lpOutBuffer_, NDR_POINTER_REF, "Pointer to LpOutBuffer (uint8)",hf_clusapi_clusapi_NodeNetworkControl_lpOutBuffer);
return offset;
}
static int
clusapi_dissect_element_NodeNetworkControl_lpOutBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucvarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeNetworkControl_lpOutBuffer__);
return offset;
}
static int
clusapi_dissect_element_NodeNetworkControl_lpOutBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeNetworkControl_lpOutBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_NodeNetworkControl_nOutBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeNetworkControl_nOutBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_NodeNetworkControl_lpBytesReturned(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeNetworkControl_lpBytesReturned_, NDR_POINTER_REF, "Pointer to LpBytesReturned (uint32)",hf_clusapi_clusapi_NodeNetworkControl_lpBytesReturned);
return offset;
}
static int
clusapi_dissect_element_NodeNetworkControl_lpBytesReturned_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeNetworkControl_lpBytesReturned, 0);
return offset;
}
static int
clusapi_dissect_element_NodeNetworkControl_lpcbRequired(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeNetworkControl_lpcbRequired_, NDR_POINTER_REF, "Pointer to LpcbRequired (uint32)",hf_clusapi_clusapi_NodeNetworkControl_lpcbRequired);
return offset;
}
static int
clusapi_dissect_element_NodeNetworkControl_lpcbRequired_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeNetworkControl_lpcbRequired, 0);
return offset;
}
static int
clusapi_dissect_element_NodeNetworkControl_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeNetworkControl_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_NodeNetworkControl_rpc_status);
return offset;
}
static int
clusapi_dissect_element_NodeNetworkControl_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeNetworkControl_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_NodeNetworkControl_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="NodeNetworkControl";
offset = clusapi_dissect_element_NodeNetworkControl_lpOutBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeNetworkControl_lpBytesReturned(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeNetworkControl_lpcbRequired(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeNetworkControl_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_NodeNetworkControl_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="NodeNetworkControl";
offset = clusapi_dissect_element_NodeNetworkControl_hNetwork(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeNetworkControl_hNode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeNetworkControl_dwControlCode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeNetworkControl_lpInBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeNetworkControl_nInBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeNetworkControl_nOutBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_NetworkControl_hNetwork(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NetworkControl_hNetwork, 0);
return offset;
}
static int
clusapi_dissect_element_NetworkControl_dwControlCode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NetworkControl_dwControlCode, 0);
return offset;
}
static int
clusapi_dissect_element_NetworkControl_lpInBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NetworkControl_lpInBuffer_, NDR_POINTER_UNIQUE, "Pointer to LpInBuffer (uint8)",hf_clusapi_clusapi_NetworkControl_lpInBuffer);
return offset;
}
static int
clusapi_dissect_element_NetworkControl_lpInBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NetworkControl_lpInBuffer__);
return offset;
}
static int
clusapi_dissect_element_NetworkControl_lpInBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NetworkControl_lpInBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_NetworkControl_nInBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NetworkControl_nInBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_NetworkControl_lpOutBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NetworkControl_lpOutBuffer_, NDR_POINTER_REF, "Pointer to LpOutBuffer (uint8)",hf_clusapi_clusapi_NetworkControl_lpOutBuffer);
return offset;
}
static int
clusapi_dissect_element_NetworkControl_lpOutBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucvarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NetworkControl_lpOutBuffer__);
return offset;
}
static int
clusapi_dissect_element_NetworkControl_lpOutBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NetworkControl_lpOutBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_NetworkControl_nOutBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NetworkControl_nOutBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_NetworkControl_lpBytesReturned(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NetworkControl_lpBytesReturned_, NDR_POINTER_REF, "Pointer to LpBytesReturned (uint32)",hf_clusapi_clusapi_NetworkControl_lpBytesReturned);
return offset;
}
static int
clusapi_dissect_element_NetworkControl_lpBytesReturned_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NetworkControl_lpBytesReturned, 0);
return offset;
}
static int
clusapi_dissect_element_NetworkControl_lpcbRequired(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NetworkControl_lpcbRequired_, NDR_POINTER_REF, "Pointer to LpcbRequired (uint32)",hf_clusapi_clusapi_NetworkControl_lpcbRequired);
return offset;
}
static int
clusapi_dissect_element_NetworkControl_lpcbRequired_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NetworkControl_lpcbRequired, 0);
return offset;
}
static int
clusapi_dissect_element_NetworkControl_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NetworkControl_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_NetworkControl_rpc_status);
return offset;
}
static int
clusapi_dissect_element_NetworkControl_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NetworkControl_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_NetworkControl_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="NetworkControl";
offset = clusapi_dissect_element_NetworkControl_lpOutBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NetworkControl_lpBytesReturned(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NetworkControl_lpcbRequired(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NetworkControl_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_NetworkControl_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="NetworkControl";
offset = clusapi_dissect_element_NetworkControl_hNetwork(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NetworkControl_dwControlCode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NetworkControl_lpInBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NetworkControl_nInBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NetworkControl_nOutBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_AddNotifyNetwork_hNotify(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyNetwork_hNotify, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyNetwork_hNetwork(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyNetwork_hNetwork, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyNetwork_dwFilter(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyNetwork_dwFilter, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyNetwork_dwNotifyKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyNetwork_dwNotifyKey, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyNetwork_dwStateSequence(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_AddNotifyNetwork_dwStateSequence_, NDR_POINTER_REF, "Pointer to DwStateSequence (uint32)",hf_clusapi_clusapi_AddNotifyNetwork_dwStateSequence);
return offset;
}
static int
clusapi_dissect_element_AddNotifyNetwork_dwStateSequence_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyNetwork_dwStateSequence, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyNetwork_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_AddNotifyNetwork_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_AddNotifyNetwork_rpc_status);
return offset;
}
static int
clusapi_dissect_element_AddNotifyNetwork_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyNetwork_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_AddNotifyNetwork_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="AddNotifyNetwork";
offset = clusapi_dissect_element_AddNotifyNetwork_dwStateSequence(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyNetwork_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_AddNotifyNetwork_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="AddNotifyNetwork";
offset = clusapi_dissect_element_AddNotifyNetwork_hNotify(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyNetwork_hNetwork(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyNetwork_dwFilter(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyNetwork_dwNotifyKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyNetwork_hNotify(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ReAddNotifyNetwork_hNotify, 0);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyNetwork_hNetwork(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ReAddNotifyNetwork_hNetwork, 0);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyNetwork_dwFilter(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ReAddNotifyNetwork_dwFilter, 0);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyNetwork_dwNotifyKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ReAddNotifyNetwork_dwNotifyKey, 0);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyNetwork_StateSequence(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ReAddNotifyNetwork_StateSequence, 0);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyNetwork_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ReAddNotifyNetwork_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_ReAddNotifyNetwork_rpc_status);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyNetwork_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ReAddNotifyNetwork_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_ReAddNotifyNetwork_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="ReAddNotifyNetwork";
offset = clusapi_dissect_element_ReAddNotifyNetwork_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_ReAddNotifyNetwork_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="ReAddNotifyNetwork";
offset = clusapi_dissect_element_ReAddNotifyNetwork_hNotify(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ReAddNotifyNetwork_hNetwork(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ReAddNotifyNetwork_dwFilter(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ReAddNotifyNetwork_dwNotifyKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ReAddNotifyNetwork_StateSequence(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_OpenNetInterface_lpszNetInterfaceName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenNetInterface_lpszNetInterfaceName_, NDR_POINTER_REF, "Pointer to LpszNetInterfaceName (uint16)",hf_clusapi_clusapi_OpenNetInterface_lpszNetInterfaceName);
return offset;
}
static int
clusapi_dissect_element_OpenNetInterface_lpszNetInterfaceName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_OpenNetInterface_lpszNetInterfaceName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_OpenNetInterface_Status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenNetInterface_Status_, NDR_POINTER_REF, "Pointer to Status (WERROR)",hf_clusapi_clusapi_OpenNetInterface_Status);
return offset;
}
static int
clusapi_dissect_element_OpenNetInterface_Status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenNetInterface_Status, 0);
return offset;
}
static int
clusapi_dissect_element_OpenNetInterface_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenNetInterface_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_OpenNetInterface_rpc_status);
return offset;
}
static int
clusapi_dissect_element_OpenNetInterface_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenNetInterface_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_element_OpenNetInterface_hNetInterface(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenNetInterface_hNetInterface_, NDR_POINTER_REF, "Pointer to HNetInterface (policy_handle)",hf_clusapi_clusapi_OpenNetInterface_hNetInterface);
return offset;
}
static int
clusapi_dissect_element_OpenNetInterface_hNetInterface_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenNetInterface_hNetInterface, 0);
return offset;
}
static int
clusapi_dissect_OpenNetInterface_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OpenNetInterface";
offset = clusapi_dissect_element_OpenNetInterface_Status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenNetInterface_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenNetInterface_hNetInterface(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_OpenNetInterface_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OpenNetInterface";
offset = clusapi_dissect_element_OpenNetInterface_lpszNetInterfaceName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_CloseNetInterface_NetInterface(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CloseNetInterface_NetInterface_, NDR_POINTER_REF, "Pointer to NetInterface (policy_handle)",hf_clusapi_clusapi_CloseNetInterface_NetInterface);
return offset;
}
static int
clusapi_dissect_element_CloseNetInterface_NetInterface_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CloseNetInterface_NetInterface, 0);
return offset;
}
static int
clusapi_dissect_CloseNetInterface_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="CloseNetInterface";
offset = clusapi_dissect_element_CloseNetInterface_NetInterface(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_CloseNetInterface_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CloseNetInterface";
offset = clusapi_dissect_element_CloseNetInterface_NetInterface(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_GetNetInterfaceState_hNetInterface(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetNetInterfaceState_hNetInterface, 0);
return offset;
}
static int
clusapi_dissect_element_GetNetInterfaceState_State(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNetInterfaceState_State_, NDR_POINTER_REF, "Pointer to State (clusapi_ClusterNetInterfaceState)",hf_clusapi_clusapi_GetNetInterfaceState_State);
return offset;
}
static int
clusapi_dissect_element_GetNetInterfaceState_State_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_enum_ClusterNetInterfaceState(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetNetInterfaceState_State, 0);
return offset;
}
static int
clusapi_dissect_element_GetNetInterfaceState_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNetInterfaceState_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_GetNetInterfaceState_rpc_status);
return offset;
}
static int
clusapi_dissect_element_GetNetInterfaceState_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetNetInterfaceState_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_GetNetInterfaceState_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="GetNetInterfaceState";
offset = clusapi_dissect_element_GetNetInterfaceState_State(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetNetInterfaceState_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_GetNetInterfaceState_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="GetNetInterfaceState";
offset = clusapi_dissect_element_GetNetInterfaceState_hNetInterface(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_GetNetInterface_lpszNodeName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNetInterface_lpszNodeName_, NDR_POINTER_REF, "Pointer to LpszNodeName (uint16)",hf_clusapi_clusapi_GetNetInterface_lpszNodeName);
return offset;
}
static int
clusapi_dissect_element_GetNetInterface_lpszNodeName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_GetNetInterface_lpszNodeName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_GetNetInterface_lpszNetworkName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNetInterface_lpszNetworkName_, NDR_POINTER_REF, "Pointer to LpszNetworkName (uint16)",hf_clusapi_clusapi_GetNetInterface_lpszNetworkName);
return offset;
}
static int
clusapi_dissect_element_GetNetInterface_lpszNetworkName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_GetNetInterface_lpszNetworkName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_GetNetInterface_lppszInterfaceName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNetInterface_lppszInterfaceName_, NDR_POINTER_REF, "Pointer to LppszInterfaceName (uint16)",hf_clusapi_clusapi_GetNetInterface_lppszInterfaceName);
return offset;
}
static int
clusapi_dissect_element_GetNetInterface_lppszInterfaceName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNetInterface_lppszInterfaceName__, NDR_POINTER_UNIQUE, "Pointer to LppszInterfaceName (uint16)",hf_clusapi_clusapi_GetNetInterface_lppszInterfaceName);
return offset;
}
static int
clusapi_dissect_element_GetNetInterface_lppszInterfaceName__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_GetNetInterface_lppszInterfaceName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_GetNetInterface_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNetInterface_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_GetNetInterface_rpc_status);
return offset;
}
static int
clusapi_dissect_element_GetNetInterface_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetNetInterface_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_GetNetInterface_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="GetNetInterface";
offset = clusapi_dissect_element_GetNetInterface_lppszInterfaceName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetNetInterface_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_GetNetInterface_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="GetNetInterface";
offset = clusapi_dissect_element_GetNetInterface_lpszNodeName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetNetInterface_lpszNetworkName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_GetNetInterfaceId_hNetInterface(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetNetInterfaceId_hNetInterface, 0);
return offset;
}
static int
clusapi_dissect_element_GetNetInterfaceId_pGuid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNetInterfaceId_pGuid_, NDR_POINTER_REF, "Pointer to PGuid (uint16)",hf_clusapi_clusapi_GetNetInterfaceId_pGuid);
return offset;
}
static int
clusapi_dissect_element_GetNetInterfaceId_pGuid_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNetInterfaceId_pGuid__, NDR_POINTER_UNIQUE, "Pointer to PGuid (uint16)",hf_clusapi_clusapi_GetNetInterfaceId_pGuid);
return offset;
}
static int
clusapi_dissect_element_GetNetInterfaceId_pGuid__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_GetNetInterfaceId_pGuid, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_GetNetInterfaceId_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNetInterfaceId_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_GetNetInterfaceId_rpc_status);
return offset;
}
static int
clusapi_dissect_element_GetNetInterfaceId_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetNetInterfaceId_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_GetNetInterfaceId_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="GetNetInterfaceId";
offset = clusapi_dissect_element_GetNetInterfaceId_pGuid(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetNetInterfaceId_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_GetNetInterfaceId_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="GetNetInterfaceId";
offset = clusapi_dissect_element_GetNetInterfaceId_hNetInterface(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_NodeNetInterfaceControl_hNetInterface(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeNetInterfaceControl_hNetInterface, 0);
return offset;
}
static int
clusapi_dissect_element_NodeNetInterfaceControl_hNode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeNetInterfaceControl_hNode, 0);
return offset;
}
static int
clusapi_dissect_element_NodeNetInterfaceControl_dwControlCode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeNetInterfaceControl_dwControlCode, 0);
return offset;
}
static int
clusapi_dissect_element_NodeNetInterfaceControl_lpInBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeNetInterfaceControl_lpInBuffer_, NDR_POINTER_UNIQUE, "Pointer to LpInBuffer (uint8)",hf_clusapi_clusapi_NodeNetInterfaceControl_lpInBuffer);
return offset;
}
static int
clusapi_dissect_element_NodeNetInterfaceControl_lpInBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeNetInterfaceControl_lpInBuffer__);
return offset;
}
static int
clusapi_dissect_element_NodeNetInterfaceControl_lpInBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeNetInterfaceControl_lpInBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_NodeNetInterfaceControl_nInBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeNetInterfaceControl_nInBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_NodeNetInterfaceControl_lpOutBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeNetInterfaceControl_lpOutBuffer_, NDR_POINTER_REF, "Pointer to LpOutBuffer (uint8)",hf_clusapi_clusapi_NodeNetInterfaceControl_lpOutBuffer);
return offset;
}
static int
clusapi_dissect_element_NodeNetInterfaceControl_lpOutBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucvarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeNetInterfaceControl_lpOutBuffer__);
return offset;
}
static int
clusapi_dissect_element_NodeNetInterfaceControl_lpOutBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeNetInterfaceControl_lpOutBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_NodeNetInterfaceControl_nOutBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeNetInterfaceControl_nOutBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_NodeNetInterfaceControl_lpBytesReturned(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeNetInterfaceControl_lpBytesReturned_, NDR_POINTER_REF, "Pointer to LpBytesReturned (uint32)",hf_clusapi_clusapi_NodeNetInterfaceControl_lpBytesReturned);
return offset;
}
static int
clusapi_dissect_element_NodeNetInterfaceControl_lpBytesReturned_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeNetInterfaceControl_lpBytesReturned, 0);
return offset;
}
static int
clusapi_dissect_element_NodeNetInterfaceControl_lpcbRequired(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeNetInterfaceControl_lpcbRequired_, NDR_POINTER_REF, "Pointer to LpcbRequired (uint32)",hf_clusapi_clusapi_NodeNetInterfaceControl_lpcbRequired);
return offset;
}
static int
clusapi_dissect_element_NodeNetInterfaceControl_lpcbRequired_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeNetInterfaceControl_lpcbRequired, 0);
return offset;
}
static int
clusapi_dissect_element_NodeNetInterfaceControl_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeNetInterfaceControl_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_NodeNetInterfaceControl_rpc_status);
return offset;
}
static int
clusapi_dissect_element_NodeNetInterfaceControl_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeNetInterfaceControl_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_NodeNetInterfaceControl_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="NodeNetInterfaceControl";
offset = clusapi_dissect_element_NodeNetInterfaceControl_lpOutBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeNetInterfaceControl_lpBytesReturned(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeNetInterfaceControl_lpcbRequired(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeNetInterfaceControl_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_NodeNetInterfaceControl_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="NodeNetInterfaceControl";
offset = clusapi_dissect_element_NodeNetInterfaceControl_hNetInterface(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeNetInterfaceControl_hNode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeNetInterfaceControl_dwControlCode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeNetInterfaceControl_lpInBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeNetInterfaceControl_nInBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeNetInterfaceControl_nOutBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_NetInterfaceControl_hNetInterface(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NetInterfaceControl_hNetInterface, 0);
return offset;
}
static int
clusapi_dissect_element_NetInterfaceControl_dwControlCode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NetInterfaceControl_dwControlCode, 0);
return offset;
}
static int
clusapi_dissect_element_NetInterfaceControl_lpInBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NetInterfaceControl_lpInBuffer_, NDR_POINTER_UNIQUE, "Pointer to LpInBuffer (uint8)",hf_clusapi_clusapi_NetInterfaceControl_lpInBuffer);
return offset;
}
static int
clusapi_dissect_element_NetInterfaceControl_lpInBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NetInterfaceControl_lpInBuffer__);
return offset;
}
static int
clusapi_dissect_element_NetInterfaceControl_lpInBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NetInterfaceControl_lpInBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_NetInterfaceControl_nInBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NetInterfaceControl_nInBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_NetInterfaceControl_lpOutBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NetInterfaceControl_lpOutBuffer_, NDR_POINTER_REF, "Pointer to LpOutBuffer (uint8)",hf_clusapi_clusapi_NetInterfaceControl_lpOutBuffer);
return offset;
}
static int
clusapi_dissect_element_NetInterfaceControl_lpOutBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucvarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NetInterfaceControl_lpOutBuffer__);
return offset;
}
static int
clusapi_dissect_element_NetInterfaceControl_lpOutBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NetInterfaceControl_lpOutBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_NetInterfaceControl_nOutBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NetInterfaceControl_nOutBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_NetInterfaceControl_lpBytesReturned(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NetInterfaceControl_lpBytesReturned_, NDR_POINTER_REF, "Pointer to LpBytesReturned (uint32)",hf_clusapi_clusapi_NetInterfaceControl_lpBytesReturned);
return offset;
}
static int
clusapi_dissect_element_NetInterfaceControl_lpBytesReturned_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NetInterfaceControl_lpBytesReturned, 0);
return offset;
}
static int
clusapi_dissect_element_NetInterfaceControl_lpcbRequired(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NetInterfaceControl_lpcbRequired_, NDR_POINTER_REF, "Pointer to LpcbRequired (uint32)",hf_clusapi_clusapi_NetInterfaceControl_lpcbRequired);
return offset;
}
static int
clusapi_dissect_element_NetInterfaceControl_lpcbRequired_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NetInterfaceControl_lpcbRequired, 0);
return offset;
}
static int
clusapi_dissect_element_NetInterfaceControl_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NetInterfaceControl_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_NetInterfaceControl_rpc_status);
return offset;
}
static int
clusapi_dissect_element_NetInterfaceControl_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NetInterfaceControl_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_NetInterfaceControl_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="NetInterfaceControl";
offset = clusapi_dissect_element_NetInterfaceControl_lpOutBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NetInterfaceControl_lpBytesReturned(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NetInterfaceControl_lpcbRequired(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NetInterfaceControl_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_NetInterfaceControl_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="NetInterfaceControl";
offset = clusapi_dissect_element_NetInterfaceControl_hNetInterface(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NetInterfaceControl_dwControlCode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NetInterfaceControl_lpInBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NetInterfaceControl_nInBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NetInterfaceControl_nOutBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_AddNotifyNetInterface_hNotify(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyNetInterface_hNotify, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyNetInterface_hNetInterface(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyNetInterface_hNetInterface, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyNetInterface_dwFilter(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyNetInterface_dwFilter, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyNetInterface_dwNotifyKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyNetInterface_dwNotifyKey, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyNetInterface_dwStateSequence(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_AddNotifyNetInterface_dwStateSequence_, NDR_POINTER_REF, "Pointer to DwStateSequence (uint32)",hf_clusapi_clusapi_AddNotifyNetInterface_dwStateSequence);
return offset;
}
static int
clusapi_dissect_element_AddNotifyNetInterface_dwStateSequence_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyNetInterface_dwStateSequence, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyNetInterface_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_AddNotifyNetInterface_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_AddNotifyNetInterface_rpc_status);
return offset;
}
static int
clusapi_dissect_element_AddNotifyNetInterface_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyNetInterface_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_AddNotifyNetInterface_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="AddNotifyNetInterface";
offset = clusapi_dissect_element_AddNotifyNetInterface_dwStateSequence(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyNetInterface_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_AddNotifyNetInterface_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="AddNotifyNetInterface";
offset = clusapi_dissect_element_AddNotifyNetInterface_hNotify(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyNetInterface_hNetInterface(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyNetInterface_dwFilter(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyNetInterface_dwNotifyKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyNetInterface_hNotify(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ReAddNotifyNetInterface_hNotify, 0);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyNetInterface_hNetInterface(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ReAddNotifyNetInterface_hNetInterface, 0);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyNetInterface_dwFilter(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ReAddNotifyNetInterface_dwFilter, 0);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyNetInterface_dwNotifyKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ReAddNotifyNetInterface_dwNotifyKey, 0);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyNetInterface_StateSequence(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ReAddNotifyNetInterface_StateSequence, 0);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyNetInterface_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ReAddNotifyNetInterface_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_ReAddNotifyNetInterface_rpc_status);
return offset;
}
static int
clusapi_dissect_element_ReAddNotifyNetInterface_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ReAddNotifyNetInterface_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_ReAddNotifyNetInterface_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="ReAddNotifyNetInterface";
offset = clusapi_dissect_element_ReAddNotifyNetInterface_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_ReAddNotifyNetInterface_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="ReAddNotifyNetInterface";
offset = clusapi_dissect_element_ReAddNotifyNetInterface_hNotify(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ReAddNotifyNetInterface_hNetInterface(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ReAddNotifyNetInterface_dwFilter(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ReAddNotifyNetInterface_dwNotifyKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ReAddNotifyNetInterface_StateSequence(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_CreateNodeEnum_hNode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateNodeEnum_hNode, 0);
return offset;
}
static int
clusapi_dissect_element_CreateNodeEnum_dwType(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateNodeEnum_dwType, 0);
return offset;
}
static int
clusapi_dissect_element_CreateNodeEnum_ReturnEnum(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateNodeEnum_ReturnEnum_, NDR_POINTER_REF, "Pointer to ReturnEnum (ENUM_LIST)",hf_clusapi_clusapi_CreateNodeEnum_ReturnEnum);
return offset;
}
static int
clusapi_dissect_element_CreateNodeEnum_ReturnEnum_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateNodeEnum_ReturnEnum__, NDR_POINTER_UNIQUE, "Pointer to ReturnEnum (ENUM_LIST)",hf_clusapi_clusapi_CreateNodeEnum_ReturnEnum);
return offset;
}
static int
clusapi_dissect_element_CreateNodeEnum_ReturnEnum__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_struct_ENUM_LIST(tvb,offset,pinfo,tree,di,drep,hf_clusapi_clusapi_CreateNodeEnum_ReturnEnum,0);
return offset;
}
static int
clusapi_dissect_element_CreateNodeEnum_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateNodeEnum_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_CreateNodeEnum_rpc_status);
return offset;
}
static int
clusapi_dissect_element_CreateNodeEnum_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateNodeEnum_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_CreateNodeEnum_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="CreateNodeEnum";
offset = clusapi_dissect_element_CreateNodeEnum_ReturnEnum(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateNodeEnum_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_CreateNodeEnum_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CreateNodeEnum";
offset = clusapi_dissect_element_CreateNodeEnum_hNode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateNodeEnum_dwType(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_GetClusterVersion2_lpwMajorVersion(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetClusterVersion2_lpwMajorVersion_, NDR_POINTER_REF, "Pointer to LpwMajorVersion (uint16)",hf_clusapi_clusapi_GetClusterVersion2_lpwMajorVersion);
return offset;
}
static int
clusapi_dissect_element_GetClusterVersion2_lpwMajorVersion_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetClusterVersion2_lpwMajorVersion, 0);
return offset;
}
static int
clusapi_dissect_element_GetClusterVersion2_lpwMinorVersion(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetClusterVersion2_lpwMinorVersion_, NDR_POINTER_REF, "Pointer to LpwMinorVersion (uint16)",hf_clusapi_clusapi_GetClusterVersion2_lpwMinorVersion);
return offset;
}
static int
clusapi_dissect_element_GetClusterVersion2_lpwMinorVersion_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetClusterVersion2_lpwMinorVersion, 0);
return offset;
}
static int
clusapi_dissect_element_GetClusterVersion2_lpwBuildNumber(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetClusterVersion2_lpwBuildNumber_, NDR_POINTER_REF, "Pointer to LpwBuildNumber (uint16)",hf_clusapi_clusapi_GetClusterVersion2_lpwBuildNumber);
return offset;
}
static int
clusapi_dissect_element_GetClusterVersion2_lpwBuildNumber_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetClusterVersion2_lpwBuildNumber, 0);
return offset;
}
static int
clusapi_dissect_element_GetClusterVersion2_lpszVendorId(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetClusterVersion2_lpszVendorId_, NDR_POINTER_REF, "Pointer to LpszVendorId (uint16)",hf_clusapi_clusapi_GetClusterVersion2_lpszVendorId);
return offset;
}
static int
clusapi_dissect_element_GetClusterVersion2_lpszVendorId_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetClusterVersion2_lpszVendorId__, NDR_POINTER_UNIQUE, "Pointer to LpszVendorId (uint16)",hf_clusapi_clusapi_GetClusterVersion2_lpszVendorId);
return offset;
}
static int
clusapi_dissect_element_GetClusterVersion2_lpszVendorId__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_GetClusterVersion2_lpszVendorId, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_GetClusterVersion2_lpszCSDVersion(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetClusterVersion2_lpszCSDVersion_, NDR_POINTER_REF, "Pointer to LpszCSDVersion (uint16)",hf_clusapi_clusapi_GetClusterVersion2_lpszCSDVersion);
return offset;
}
static int
clusapi_dissect_element_GetClusterVersion2_lpszCSDVersion_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetClusterVersion2_lpszCSDVersion__, NDR_POINTER_UNIQUE, "Pointer to LpszCSDVersion (uint16)",hf_clusapi_clusapi_GetClusterVersion2_lpszCSDVersion);
return offset;
}
static int
clusapi_dissect_element_GetClusterVersion2_lpszCSDVersion__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_GetClusterVersion2_lpszCSDVersion, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_GetClusterVersion2_ppClusterOpVerInfo(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetClusterVersion2_ppClusterOpVerInfo_, NDR_POINTER_REF, "Pointer to PpClusterOpVerInfo (CLUSTER_OPERATIONAL_VERSION_INFO)",hf_clusapi_clusapi_GetClusterVersion2_ppClusterOpVerInfo);
return offset;
}
static int
clusapi_dissect_element_GetClusterVersion2_ppClusterOpVerInfo_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetClusterVersion2_ppClusterOpVerInfo__, NDR_POINTER_UNIQUE, "Pointer to PpClusterOpVerInfo (CLUSTER_OPERATIONAL_VERSION_INFO)",hf_clusapi_clusapi_GetClusterVersion2_ppClusterOpVerInfo);
return offset;
}
static int
clusapi_dissect_element_GetClusterVersion2_ppClusterOpVerInfo__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_struct_CLUSTER_OPERATIONAL_VERSION_INFO(tvb,offset,pinfo,tree,di,drep,hf_clusapi_clusapi_GetClusterVersion2_ppClusterOpVerInfo,0);
return offset;
}
static int
clusapi_dissect_element_GetClusterVersion2_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetClusterVersion2_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_GetClusterVersion2_rpc_status);
return offset;
}
static int
clusapi_dissect_element_GetClusterVersion2_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetClusterVersion2_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_GetClusterVersion2_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="GetClusterVersion2";
offset = clusapi_dissect_element_GetClusterVersion2_lpwMajorVersion(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetClusterVersion2_lpwMinorVersion(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetClusterVersion2_lpwBuildNumber(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetClusterVersion2_lpszVendorId(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetClusterVersion2_lpszCSDVersion(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetClusterVersion2_ppClusterOpVerInfo(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetClusterVersion2_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_GetClusterVersion2_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="GetClusterVersion2";
return offset;
}
static int
clusapi_dissect_element_CreateResTypeEnum_lpszTypeName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateResTypeEnum_lpszTypeName_, NDR_POINTER_REF, "Pointer to LpszTypeName (uint16)",hf_clusapi_clusapi_CreateResTypeEnum_lpszTypeName);
return offset;
}
static int
clusapi_dissect_element_CreateResTypeEnum_lpszTypeName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_CreateResTypeEnum_lpszTypeName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_CreateResTypeEnum_dwType(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_bitmap_ClusterResTypeEnumType(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateResTypeEnum_dwType, 0);
return offset;
}
static int
clusapi_dissect_element_CreateResTypeEnum_ReturnEnum(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateResTypeEnum_ReturnEnum_, NDR_POINTER_REF, "Pointer to ReturnEnum (ENUM_LIST)",hf_clusapi_clusapi_CreateResTypeEnum_ReturnEnum);
return offset;
}
static int
clusapi_dissect_element_CreateResTypeEnum_ReturnEnum_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateResTypeEnum_ReturnEnum__, NDR_POINTER_UNIQUE, "Pointer to ReturnEnum (ENUM_LIST)",hf_clusapi_clusapi_CreateResTypeEnum_ReturnEnum);
return offset;
}
static int
clusapi_dissect_element_CreateResTypeEnum_ReturnEnum__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_struct_ENUM_LIST(tvb,offset,pinfo,tree,di,drep,hf_clusapi_clusapi_CreateResTypeEnum_ReturnEnum,0);
return offset;
}
static int
clusapi_dissect_element_CreateResTypeEnum_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateResTypeEnum_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_CreateResTypeEnum_rpc_status);
return offset;
}
static int
clusapi_dissect_element_CreateResTypeEnum_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateResTypeEnum_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_CreateResTypeEnum_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="CreateResTypeEnum";
offset = clusapi_dissect_element_CreateResTypeEnum_ReturnEnum(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateResTypeEnum_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_CreateResTypeEnum_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CreateResTypeEnum";
offset = clusapi_dissect_element_CreateResTypeEnum_lpszTypeName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateResTypeEnum_dwType(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_BackupClusterDatabase_lpszPathName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_BackupClusterDatabase_lpszPathName_, NDR_POINTER_REF, "Pointer to LpszPathName (uint16)",hf_clusapi_clusapi_BackupClusterDatabase_lpszPathName);
return offset;
}
static int
clusapi_dissect_element_BackupClusterDatabase_lpszPathName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_BackupClusterDatabase_lpszPathName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_BackupClusterDatabase_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_BackupClusterDatabase_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_BackupClusterDatabase_rpc_status);
return offset;
}
static int
clusapi_dissect_element_BackupClusterDatabase_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_BackupClusterDatabase_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_BackupClusterDatabase_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="BackupClusterDatabase";
offset = clusapi_dissect_element_BackupClusterDatabase_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_BackupClusterDatabase_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="BackupClusterDatabase";
offset = clusapi_dissect_element_BackupClusterDatabase_lpszPathName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_NodeClusterControl_hCluster(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeClusterControl_hCluster, 0);
return offset;
}
static int
clusapi_dissect_element_NodeClusterControl_hHostNode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeClusterControl_hHostNode, 0);
return offset;
}
static int
clusapi_dissect_element_NodeClusterControl_dwControlCode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeClusterControl_dwControlCode, 0);
return offset;
}
static int
clusapi_dissect_element_NodeClusterControl_lpInBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeClusterControl_lpInBuffer_, NDR_POINTER_UNIQUE, "Pointer to LpInBuffer (uint8)",hf_clusapi_clusapi_NodeClusterControl_lpInBuffer);
return offset;
}
static int
clusapi_dissect_element_NodeClusterControl_lpInBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeClusterControl_lpInBuffer__);
return offset;
}
static int
clusapi_dissect_element_NodeClusterControl_lpInBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeClusterControl_lpInBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_NodeClusterControl_nInBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeClusterControl_nInBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_NodeClusterControl_lpOutBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeClusterControl_lpOutBuffer_, NDR_POINTER_REF, "Pointer to LpOutBuffer (uint8)",hf_clusapi_clusapi_NodeClusterControl_lpOutBuffer);
return offset;
}
static int
clusapi_dissect_element_NodeClusterControl_lpOutBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucvarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeClusterControl_lpOutBuffer__);
return offset;
}
static int
clusapi_dissect_element_NodeClusterControl_lpOutBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeClusterControl_lpOutBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_NodeClusterControl_nOutBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeClusterControl_nOutBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_NodeClusterControl_lpBytesReturned(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeClusterControl_lpBytesReturned_, NDR_POINTER_REF, "Pointer to LpBytesReturned (uint32)",hf_clusapi_clusapi_NodeClusterControl_lpBytesReturned);
return offset;
}
static int
clusapi_dissect_element_NodeClusterControl_lpBytesReturned_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeClusterControl_lpBytesReturned, 0);
return offset;
}
static int
clusapi_dissect_element_NodeClusterControl_lpcbRequired(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeClusterControl_lpcbRequired_, NDR_POINTER_REF, "Pointer to LpcbRequired (uint32)",hf_clusapi_clusapi_NodeClusterControl_lpcbRequired);
return offset;
}
static int
clusapi_dissect_element_NodeClusterControl_lpcbRequired_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeClusterControl_lpcbRequired, 0);
return offset;
}
static int
clusapi_dissect_element_NodeClusterControl_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_NodeClusterControl_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_NodeClusterControl_rpc_status);
return offset;
}
static int
clusapi_dissect_element_NodeClusterControl_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_NodeClusterControl_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_NodeClusterControl_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="NodeClusterControl";
offset = clusapi_dissect_element_NodeClusterControl_lpOutBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeClusterControl_lpBytesReturned(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeClusterControl_lpcbRequired(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeClusterControl_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_NodeClusterControl_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="NodeClusterControl";
offset = clusapi_dissect_element_NodeClusterControl_hCluster(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeClusterControl_hHostNode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeClusterControl_dwControlCode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeClusterControl_lpInBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeClusterControl_nInBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_NodeClusterControl_nOutBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_ClusterControl_hCluster(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ClusterControl_hCluster, 0);
return offset;
}
static int
clusapi_dissect_element_ClusterControl_dwControlCode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_enum_ClusterControlCode(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ClusterControl_dwControlCode, 0);
return offset;
}
static int
clusapi_dissect_element_ClusterControl_lpInBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ClusterControl_lpInBuffer_, NDR_POINTER_UNIQUE, "Pointer to LpInBuffer (uint8)",hf_clusapi_clusapi_ClusterControl_lpInBuffer);
return offset;
}
static int
clusapi_dissect_element_ClusterControl_lpInBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ClusterControl_lpInBuffer__);
return offset;
}
static int
clusapi_dissect_element_ClusterControl_lpInBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ClusterControl_lpInBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_ClusterControl_nInBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ClusterControl_nInBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_ClusterControl_lpOutBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ClusterControl_lpOutBuffer_, NDR_POINTER_REF, "Pointer to LpOutBuffer (uint8)",hf_clusapi_clusapi_ClusterControl_lpOutBuffer);
return offset;
}
static int
clusapi_dissect_element_ClusterControl_lpOutBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucvarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ClusterControl_lpOutBuffer__);
return offset;
}
static int
clusapi_dissect_element_ClusterControl_lpOutBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ClusterControl_lpOutBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_ClusterControl_nOutBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ClusterControl_nOutBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_ClusterControl_lpBytesReturned(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ClusterControl_lpBytesReturned_, NDR_POINTER_REF, "Pointer to LpBytesReturned (uint32)",hf_clusapi_clusapi_ClusterControl_lpBytesReturned);
return offset;
}
static int
clusapi_dissect_element_ClusterControl_lpBytesReturned_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ClusterControl_lpBytesReturned, 0);
return offset;
}
static int
clusapi_dissect_element_ClusterControl_lpcbRequired(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ClusterControl_lpcbRequired_, NDR_POINTER_REF, "Pointer to LpcbRequired (uint32)",hf_clusapi_clusapi_ClusterControl_lpcbRequired);
return offset;
}
static int
clusapi_dissect_element_ClusterControl_lpcbRequired_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ClusterControl_lpcbRequired, 0);
return offset;
}
static int
clusapi_dissect_element_ClusterControl_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ClusterControl_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_ClusterControl_rpc_status);
return offset;
}
static int
clusapi_dissect_element_ClusterControl_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ClusterControl_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_ClusterControl_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="ClusterControl";
offset = clusapi_dissect_element_ClusterControl_lpOutBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ClusterControl_lpBytesReturned(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ClusterControl_lpcbRequired(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ClusterControl_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_ClusterControl_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="ClusterControl";
offset = clusapi_dissect_element_ClusterControl_hCluster(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ClusterControl_dwControlCode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ClusterControl_lpInBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ClusterControl_nInBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ClusterControl_nOutBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_UnblockGetNotifyCall_hNotify(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_UnblockGetNotifyCall_hNotify, 0);
return offset;
}
static int
clusapi_dissect_UnblockGetNotifyCall_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="UnblockGetNotifyCall";
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_UnblockGetNotifyCall_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="UnblockGetNotifyCall";
offset = clusapi_dissect_element_UnblockGetNotifyCall_hNotify(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_SetServiceAccountPassword_lpszNewPassword(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_SetServiceAccountPassword_lpszNewPassword_, NDR_POINTER_REF, "Pointer to LpszNewPassword (uint16)",hf_clusapi_clusapi_SetServiceAccountPassword_lpszNewPassword);
return offset;
}
static int
clusapi_dissect_element_SetServiceAccountPassword_lpszNewPassword_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_SetServiceAccountPassword_lpszNewPassword, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_SetServiceAccountPassword_dwFlags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_enum_IDL_CLUSTER_SET_PASSWORD_FLAGS(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_SetServiceAccountPassword_dwFlags, 0);
return offset;
}
static int
clusapi_dissect_element_SetServiceAccountPassword_ReturnStatusBufferPtr(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucvarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_SetServiceAccountPassword_ReturnStatusBufferPtr_);
return offset;
}
static int
clusapi_dissect_element_SetServiceAccountPassword_ReturnStatusBufferPtr_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_struct_IDL_CLUSTER_SET_PASSWORD_STATUS(tvb,offset,pinfo,tree,di,drep,hf_clusapi_clusapi_SetServiceAccountPassword_ReturnStatusBufferPtr,0);
return offset;
}
static int
clusapi_dissect_element_SetServiceAccountPassword_ReturnStatusBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_SetServiceAccountPassword_ReturnStatusBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_SetServiceAccountPassword_SizeReturned(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_SetServiceAccountPassword_SizeReturned_, NDR_POINTER_REF, "Pointer to SizeReturned (uint32)",hf_clusapi_clusapi_SetServiceAccountPassword_SizeReturned);
return offset;
}
static int
clusapi_dissect_element_SetServiceAccountPassword_SizeReturned_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_SetServiceAccountPassword_SizeReturned, 0);
return offset;
}
static int
clusapi_dissect_element_SetServiceAccountPassword_ExpectedBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_SetServiceAccountPassword_ExpectedBufferSize_, NDR_POINTER_REF, "Pointer to ExpectedBufferSize (uint32)",hf_clusapi_clusapi_SetServiceAccountPassword_ExpectedBufferSize);
return offset;
}
static int
clusapi_dissect_element_SetServiceAccountPassword_ExpectedBufferSize_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_SetServiceAccountPassword_ExpectedBufferSize, 0);
return offset;
}
static int
clusapi_dissect_SetServiceAccountPassword_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="SetServiceAccountPassword";
offset = clusapi_dissect_element_SetServiceAccountPassword_ReturnStatusBufferPtr(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_SetServiceAccountPassword_SizeReturned(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_SetServiceAccountPassword_ExpectedBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_SetServiceAccountPassword_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="SetServiceAccountPassword";
offset = clusapi_dissect_element_SetServiceAccountPassword_lpszNewPassword(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_SetServiceAccountPassword_dwFlags(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_SetServiceAccountPassword_ReturnStatusBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_SetResourceDependencyExpression_hResource(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_SetResourceDependencyExpression_hResource, 0);
return offset;
}
static int
clusapi_dissect_element_SetResourceDependencyExpression_lpszDependencyExpression(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_SetResourceDependencyExpression_lpszDependencyExpression_, NDR_POINTER_UNIQUE, "Pointer to LpszDependencyExpression (uint16)",hf_clusapi_clusapi_SetResourceDependencyExpression_lpszDependencyExpression);
return offset;
}
static int
clusapi_dissect_element_SetResourceDependencyExpression_lpszDependencyExpression_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_SetResourceDependencyExpression_lpszDependencyExpression, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_SetResourceDependencyExpression_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_SetResourceDependencyExpression_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_SetResourceDependencyExpression_rpc_status);
return offset;
}
static int
clusapi_dissect_element_SetResourceDependencyExpression_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_SetResourceDependencyExpression_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_SetResourceDependencyExpression_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="SetResourceDependencyExpression";
offset = clusapi_dissect_element_SetResourceDependencyExpression_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_SetResourceDependencyExpression_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="SetResourceDependencyExpression";
offset = clusapi_dissect_element_SetResourceDependencyExpression_hResource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_SetResourceDependencyExpression_lpszDependencyExpression(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_GetResourceDependencyExpression_hResource(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetResourceDependencyExpression_hResource, 0);
return offset;
}
static int
clusapi_dissect_element_GetResourceDependencyExpression_lpszDependencyExpression(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetResourceDependencyExpression_lpszDependencyExpression_, NDR_POINTER_REF, "Pointer to LpszDependencyExpression (uint16)",hf_clusapi_clusapi_GetResourceDependencyExpression_lpszDependencyExpression);
return offset;
}
static int
clusapi_dissect_element_GetResourceDependencyExpression_lpszDependencyExpression_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetResourceDependencyExpression_lpszDependencyExpression__, NDR_POINTER_UNIQUE, "Pointer to LpszDependencyExpression (uint16)",hf_clusapi_clusapi_GetResourceDependencyExpression_lpszDependencyExpression);
return offset;
}
static int
clusapi_dissect_element_GetResourceDependencyExpression_lpszDependencyExpression__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_GetResourceDependencyExpression_lpszDependencyExpression, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_GetResourceDependencyExpression_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetResourceDependencyExpression_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_GetResourceDependencyExpression_rpc_status);
return offset;
}
static int
clusapi_dissect_element_GetResourceDependencyExpression_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetResourceDependencyExpression_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_GetResourceDependencyExpression_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="GetResourceDependencyExpression";
offset = clusapi_dissect_element_GetResourceDependencyExpression_lpszDependencyExpression(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetResourceDependencyExpression_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_GetResourceDependencyExpression_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="GetResourceDependencyExpression";
offset = clusapi_dissect_element_GetResourceDependencyExpression_hResource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_Opnum111NotUsedOnWire_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="Opnum111NotUsedOnWire";
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_Opnum111NotUsedOnWire_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="Opnum111NotUsedOnWire";
return offset;
}
static int
clusapi_dissect_element_GetResourceNetworkName_hResource(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetResourceNetworkName_hResource, 0);
return offset;
}
static int
clusapi_dissect_element_GetResourceNetworkName_lpszName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetResourceNetworkName_lpszName_, NDR_POINTER_REF, "Pointer to LpszName (uint16)",hf_clusapi_clusapi_GetResourceNetworkName_lpszName);
return offset;
}
static int
clusapi_dissect_element_GetResourceNetworkName_lpszName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetResourceNetworkName_lpszName__, NDR_POINTER_UNIQUE, "Pointer to LpszName (uint16)",hf_clusapi_clusapi_GetResourceNetworkName_lpszName);
return offset;
}
static int
clusapi_dissect_element_GetResourceNetworkName_lpszName__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_GetResourceNetworkName_lpszName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_GetResourceNetworkName_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetResourceNetworkName_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_GetResourceNetworkName_rpc_status);
return offset;
}
static int
clusapi_dissect_element_GetResourceNetworkName_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetResourceNetworkName_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_GetResourceNetworkName_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="GetResourceNetworkName";
offset = clusapi_dissect_element_GetResourceNetworkName_lpszName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetResourceNetworkName_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_GetResourceNetworkName_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="GetResourceNetworkName";
offset = clusapi_dissect_element_GetResourceNetworkName_hResource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_ExecuteBatch_hKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ExecuteBatch_hKey, 0);
return offset;
}
static int
clusapi_dissect_element_ExecuteBatch_cbData(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ExecuteBatch_cbData, 0);
return offset;
}
static int
clusapi_dissect_element_ExecuteBatch_lpData(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ExecuteBatch_lpData_, NDR_POINTER_REF, "Pointer to LpData (uint8)",hf_clusapi_clusapi_ExecuteBatch_lpData);
return offset;
}
static int
clusapi_dissect_element_ExecuteBatch_lpData_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ExecuteBatch_lpData__);
return offset;
}
static int
clusapi_dissect_element_ExecuteBatch_lpData__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ExecuteBatch_lpData, 0);
return offset;
}
static int
clusapi_dissect_element_ExecuteBatch_pdwFailedCommand(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ExecuteBatch_pdwFailedCommand_, NDR_POINTER_REF, "Pointer to PdwFailedCommand (int32)",hf_clusapi_clusapi_ExecuteBatch_pdwFailedCommand);
return offset;
}
static int
clusapi_dissect_element_ExecuteBatch_pdwFailedCommand_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ExecuteBatch_pdwFailedCommand, 0);
return offset;
}
static int
clusapi_dissect_element_ExecuteBatch_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ExecuteBatch_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_ExecuteBatch_rpc_status);
return offset;
}
static int
clusapi_dissect_element_ExecuteBatch_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ExecuteBatch_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_ExecuteBatch_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="ExecuteBatch";
offset = clusapi_dissect_element_ExecuteBatch_pdwFailedCommand(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ExecuteBatch_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_ExecuteBatch_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="ExecuteBatch";
offset = clusapi_dissect_element_ExecuteBatch_hKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ExecuteBatch_cbData(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ExecuteBatch_lpData(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_CreateBatchPort_hKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateBatchPort_hKey, 0);
return offset;
}
static int
clusapi_dissect_element_CreateBatchPort_phBatchPort(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateBatchPort_phBatchPort_, NDR_POINTER_REF, "Pointer to PhBatchPort (policy_handle)",hf_clusapi_clusapi_CreateBatchPort_phBatchPort);
return offset;
}
static int
clusapi_dissect_element_CreateBatchPort_phBatchPort_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateBatchPort_phBatchPort, 0);
return offset;
}
static int
clusapi_dissect_element_CreateBatchPort_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateBatchPort_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_CreateBatchPort_rpc_status);
return offset;
}
static int
clusapi_dissect_element_CreateBatchPort_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateBatchPort_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_CreateBatchPort_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="CreateBatchPort";
offset = clusapi_dissect_element_CreateBatchPort_phBatchPort(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateBatchPort_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_CreateBatchPort_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CreateBatchPort";
offset = clusapi_dissect_element_CreateBatchPort_hKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_GetBatchNotification_hBatchNotify(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetBatchNotification_hBatchNotify, 0);
return offset;
}
static int
clusapi_dissect_element_GetBatchNotification_cbData(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetBatchNotification_cbData_, NDR_POINTER_REF, "Pointer to CbData (uint32)",hf_clusapi_clusapi_GetBatchNotification_cbData);
return offset;
}
static int
clusapi_dissect_element_GetBatchNotification_cbData_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetBatchNotification_cbData, 0);
return offset;
}
static int
clusapi_dissect_element_GetBatchNotification_lpData(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetBatchNotification_lpData_, NDR_POINTER_REF, "Pointer to LpData (uint8)",hf_clusapi_clusapi_GetBatchNotification_lpData);
return offset;
}
static int
clusapi_dissect_element_GetBatchNotification_lpData_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetBatchNotification_lpData__, NDR_POINTER_UNIQUE, "Pointer to LpData (uint8)",hf_clusapi_clusapi_GetBatchNotification_lpData);
return offset;
}
static int
clusapi_dissect_element_GetBatchNotification_lpData__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetBatchNotification_lpData___);
return offset;
}
static int
clusapi_dissect_element_GetBatchNotification_lpData___(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetBatchNotification_lpData, 0);
return offset;
}
static int
clusapi_dissect_GetBatchNotification_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="GetBatchNotification";
offset = clusapi_dissect_element_GetBatchNotification_cbData(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetBatchNotification_lpData(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_GetBatchNotification_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="GetBatchNotification";
offset = clusapi_dissect_element_GetBatchNotification_hBatchNotify(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_CloseBatchPort_phBatchPort(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CloseBatchPort_phBatchPort_, NDR_POINTER_REF, "Pointer to PhBatchPort (policy_handle)",hf_clusapi_clusapi_CloseBatchPort_phBatchPort);
return offset;
}
static int
clusapi_dissect_element_CloseBatchPort_phBatchPort_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CloseBatchPort_phBatchPort, 0);
return offset;
}
static int
clusapi_dissect_CloseBatchPort_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="CloseBatchPort";
offset = clusapi_dissect_element_CloseBatchPort_phBatchPort(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_CloseBatchPort_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CloseBatchPort";
offset = clusapi_dissect_element_CloseBatchPort_phBatchPort(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_OpenClusterEx_dwDesiredAccess(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_bitmap_DesiredAccessMask(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenClusterEx_dwDesiredAccess, 0);
return offset;
}
static int
clusapi_dissect_element_OpenClusterEx_lpdwGrantedAccess(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenClusterEx_lpdwGrantedAccess_, NDR_POINTER_REF, "Pointer to LpdwGrantedAccess (uint32)",hf_clusapi_clusapi_OpenClusterEx_lpdwGrantedAccess);
return offset;
}
static int
clusapi_dissect_element_OpenClusterEx_lpdwGrantedAccess_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenClusterEx_lpdwGrantedAccess, 0);
return offset;
}
static int
clusapi_dissect_element_OpenClusterEx_Status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenClusterEx_Status_, NDR_POINTER_REF, "Pointer to Status (WERROR)",hf_clusapi_clusapi_OpenClusterEx_Status);
return offset;
}
static int
clusapi_dissect_element_OpenClusterEx_Status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenClusterEx_Status, 0);
return offset;
}
static int
clusapi_dissect_element_OpenClusterEx_hCluster(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenClusterEx_hCluster_, NDR_POINTER_REF, "Pointer to HCluster (policy_handle)",hf_clusapi_clusapi_OpenClusterEx_hCluster);
return offset;
}
static int
clusapi_dissect_element_OpenClusterEx_hCluster_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenClusterEx_hCluster, 0);
return offset;
}
static int
clusapi_dissect_OpenClusterEx_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OpenClusterEx";
offset = clusapi_dissect_element_OpenClusterEx_lpdwGrantedAccess(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenClusterEx_Status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenClusterEx_hCluster(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_OpenClusterEx_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OpenClusterEx";
offset = clusapi_dissect_element_OpenClusterEx_dwDesiredAccess(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_OpenNodeEx_lpszNodeName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenNodeEx_lpszNodeName_, NDR_POINTER_REF, "Pointer to LpszNodeName (uint16)",hf_clusapi_clusapi_OpenNodeEx_lpszNodeName);
return offset;
}
static int
clusapi_dissect_element_OpenNodeEx_lpszNodeName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_OpenNodeEx_lpszNodeName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_OpenNodeEx_dwDesiredAccess(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_bitmap_DesiredAccessMask(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenNodeEx_dwDesiredAccess, 0);
return offset;
}
static int
clusapi_dissect_element_OpenNodeEx_lpdwGrantedAccess(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenNodeEx_lpdwGrantedAccess_, NDR_POINTER_REF, "Pointer to LpdwGrantedAccess (uint32)",hf_clusapi_clusapi_OpenNodeEx_lpdwGrantedAccess);
return offset;
}
static int
clusapi_dissect_element_OpenNodeEx_lpdwGrantedAccess_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenNodeEx_lpdwGrantedAccess, 0);
return offset;
}
static int
clusapi_dissect_element_OpenNodeEx_Status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenNodeEx_Status_, NDR_POINTER_REF, "Pointer to Status (WERROR)",hf_clusapi_clusapi_OpenNodeEx_Status);
return offset;
}
static int
clusapi_dissect_element_OpenNodeEx_Status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenNodeEx_Status, 0);
return offset;
}
static int
clusapi_dissect_element_OpenNodeEx_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenNodeEx_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_OpenNodeEx_rpc_status);
return offset;
}
static int
clusapi_dissect_element_OpenNodeEx_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenNodeEx_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_element_OpenNodeEx_hNode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenNodeEx_hNode_, NDR_POINTER_REF, "Pointer to HNode (policy_handle)",hf_clusapi_clusapi_OpenNodeEx_hNode);
return offset;
}
static int
clusapi_dissect_element_OpenNodeEx_hNode_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenNodeEx_hNode, 0);
return offset;
}
static int
clusapi_dissect_OpenNodeEx_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OpenNodeEx";
offset = clusapi_dissect_element_OpenNodeEx_lpdwGrantedAccess(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenNodeEx_Status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenNodeEx_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenNodeEx_hNode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_OpenNodeEx_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OpenNodeEx";
offset = clusapi_dissect_element_OpenNodeEx_lpszNodeName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenNodeEx_dwDesiredAccess(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_OpenGroupEx_lpszGroupName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenGroupEx_lpszGroupName_, NDR_POINTER_REF, "Pointer to LpszGroupName (uint16)",hf_clusapi_clusapi_OpenGroupEx_lpszGroupName);
return offset;
}
static int
clusapi_dissect_element_OpenGroupEx_lpszGroupName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_OpenGroupEx_lpszGroupName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_OpenGroupEx_dwDesiredAccess(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_bitmap_DesiredAccessMask(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenGroupEx_dwDesiredAccess, 0);
return offset;
}
static int
clusapi_dissect_element_OpenGroupEx_lpdwGrantedAccess(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenGroupEx_lpdwGrantedAccess_, NDR_POINTER_REF, "Pointer to LpdwGrantedAccess (uint32)",hf_clusapi_clusapi_OpenGroupEx_lpdwGrantedAccess);
return offset;
}
static int
clusapi_dissect_element_OpenGroupEx_lpdwGrantedAccess_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenGroupEx_lpdwGrantedAccess, 0);
return offset;
}
static int
clusapi_dissect_element_OpenGroupEx_Status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenGroupEx_Status_, NDR_POINTER_REF, "Pointer to Status (WERROR)",hf_clusapi_clusapi_OpenGroupEx_Status);
return offset;
}
static int
clusapi_dissect_element_OpenGroupEx_Status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenGroupEx_Status, 0);
return offset;
}
static int
clusapi_dissect_element_OpenGroupEx_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenGroupEx_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_OpenGroupEx_rpc_status);
return offset;
}
static int
clusapi_dissect_element_OpenGroupEx_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenGroupEx_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_element_OpenGroupEx_hGroup(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenGroupEx_hGroup_, NDR_POINTER_REF, "Pointer to HGroup (policy_handle)",hf_clusapi_clusapi_OpenGroupEx_hGroup);
return offset;
}
static int
clusapi_dissect_element_OpenGroupEx_hGroup_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenGroupEx_hGroup, 0);
return offset;
}
static int
clusapi_dissect_OpenGroupEx_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OpenGroupEx";
offset = clusapi_dissect_element_OpenGroupEx_lpdwGrantedAccess(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenGroupEx_Status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenGroupEx_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenGroupEx_hGroup(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_OpenGroupEx_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OpenGroupEx";
offset = clusapi_dissect_element_OpenGroupEx_lpszGroupName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenGroupEx_dwDesiredAccess(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_OpenResourceEx_lpszResourceName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenResourceEx_lpszResourceName_, NDR_POINTER_REF, "Pointer to LpszResourceName (uint16)",hf_clusapi_clusapi_OpenResourceEx_lpszResourceName);
return offset;
}
static int
clusapi_dissect_element_OpenResourceEx_lpszResourceName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_OpenResourceEx_lpszResourceName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_OpenResourceEx_dwDesiredAccess(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_bitmap_DesiredAccessMask(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenResourceEx_dwDesiredAccess, 0);
return offset;
}
static int
clusapi_dissect_element_OpenResourceEx_lpdwGrantedAccess(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenResourceEx_lpdwGrantedAccess_, NDR_POINTER_REF, "Pointer to LpdwGrantedAccess (uint32)",hf_clusapi_clusapi_OpenResourceEx_lpdwGrantedAccess);
return offset;
}
static int
clusapi_dissect_element_OpenResourceEx_lpdwGrantedAccess_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenResourceEx_lpdwGrantedAccess, 0);
return offset;
}
static int
clusapi_dissect_element_OpenResourceEx_Status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenResourceEx_Status_, NDR_POINTER_REF, "Pointer to Status (WERROR)",hf_clusapi_clusapi_OpenResourceEx_Status);
return offset;
}
static int
clusapi_dissect_element_OpenResourceEx_Status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenResourceEx_Status, 0);
return offset;
}
static int
clusapi_dissect_element_OpenResourceEx_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenResourceEx_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_OpenResourceEx_rpc_status);
return offset;
}
static int
clusapi_dissect_element_OpenResourceEx_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenResourceEx_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_element_OpenResourceEx_hResource(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenResourceEx_hResource_, NDR_POINTER_REF, "Pointer to HResource (policy_handle)",hf_clusapi_clusapi_OpenResourceEx_hResource);
return offset;
}
static int
clusapi_dissect_element_OpenResourceEx_hResource_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenResourceEx_hResource, 0);
return offset;
}
static int
clusapi_dissect_OpenResourceEx_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OpenResourceEx";
offset = clusapi_dissect_element_OpenResourceEx_lpdwGrantedAccess(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenResourceEx_Status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenResourceEx_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenResourceEx_hResource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_OpenResourceEx_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OpenResourceEx";
offset = clusapi_dissect_element_OpenResourceEx_lpszResourceName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenResourceEx_dwDesiredAccess(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_OpenNetworkEx_lpszNetworkName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenNetworkEx_lpszNetworkName_, NDR_POINTER_REF, "Pointer to LpszNetworkName (uint16)",hf_clusapi_clusapi_OpenNetworkEx_lpszNetworkName);
return offset;
}
static int
clusapi_dissect_element_OpenNetworkEx_lpszNetworkName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_OpenNetworkEx_lpszNetworkName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_OpenNetworkEx_dwDesiredAccess(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_bitmap_DesiredAccessMask(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenNetworkEx_dwDesiredAccess, 0);
return offset;
}
static int
clusapi_dissect_element_OpenNetworkEx_lpdwGrantedAccess(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenNetworkEx_lpdwGrantedAccess_, NDR_POINTER_REF, "Pointer to LpdwGrantedAccess (uint32)",hf_clusapi_clusapi_OpenNetworkEx_lpdwGrantedAccess);
return offset;
}
static int
clusapi_dissect_element_OpenNetworkEx_lpdwGrantedAccess_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenNetworkEx_lpdwGrantedAccess, 0);
return offset;
}
static int
clusapi_dissect_element_OpenNetworkEx_Status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenNetworkEx_Status_, NDR_POINTER_REF, "Pointer to Status (WERROR)",hf_clusapi_clusapi_OpenNetworkEx_Status);
return offset;
}
static int
clusapi_dissect_element_OpenNetworkEx_Status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenNetworkEx_Status, 0);
return offset;
}
static int
clusapi_dissect_element_OpenNetworkEx_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenNetworkEx_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_OpenNetworkEx_rpc_status);
return offset;
}
static int
clusapi_dissect_element_OpenNetworkEx_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenNetworkEx_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_element_OpenNetworkEx_hNetwork(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenNetworkEx_hNetwork_, NDR_POINTER_REF, "Pointer to HNetwork (policy_handle)",hf_clusapi_clusapi_OpenNetworkEx_hNetwork);
return offset;
}
static int
clusapi_dissect_element_OpenNetworkEx_hNetwork_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenNetworkEx_hNetwork, 0);
return offset;
}
static int
clusapi_dissect_OpenNetworkEx_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OpenNetworkEx";
offset = clusapi_dissect_element_OpenNetworkEx_lpdwGrantedAccess(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenNetworkEx_Status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenNetworkEx_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenNetworkEx_hNetwork(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_OpenNetworkEx_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OpenNetworkEx";
offset = clusapi_dissect_element_OpenNetworkEx_lpszNetworkName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenNetworkEx_dwDesiredAccess(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_OpenNetInterfaceEx_lpszNetInterfaceName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenNetInterfaceEx_lpszNetInterfaceName_, NDR_POINTER_REF, "Pointer to LpszNetInterfaceName (uint16)",hf_clusapi_clusapi_OpenNetInterfaceEx_lpszNetInterfaceName);
return offset;
}
static int
clusapi_dissect_element_OpenNetInterfaceEx_lpszNetInterfaceName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_OpenNetInterfaceEx_lpszNetInterfaceName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_OpenNetInterfaceEx_dwDesiredAccess(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_bitmap_DesiredAccessMask(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenNetInterfaceEx_dwDesiredAccess, 0);
return offset;
}
static int
clusapi_dissect_element_OpenNetInterfaceEx_lpdwGrantedAccess(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenNetInterfaceEx_lpdwGrantedAccess_, NDR_POINTER_REF, "Pointer to LpdwGrantedAccess (uint32)",hf_clusapi_clusapi_OpenNetInterfaceEx_lpdwGrantedAccess);
return offset;
}
static int
clusapi_dissect_element_OpenNetInterfaceEx_lpdwGrantedAccess_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenNetInterfaceEx_lpdwGrantedAccess, 0);
return offset;
}
static int
clusapi_dissect_element_OpenNetInterfaceEx_Status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenNetInterfaceEx_Status_, NDR_POINTER_REF, "Pointer to Status (WERROR)",hf_clusapi_clusapi_OpenNetInterfaceEx_Status);
return offset;
}
static int
clusapi_dissect_element_OpenNetInterfaceEx_Status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenNetInterfaceEx_Status, 0);
return offset;
}
static int
clusapi_dissect_element_OpenNetInterfaceEx_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenNetInterfaceEx_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_OpenNetInterfaceEx_rpc_status);
return offset;
}
static int
clusapi_dissect_element_OpenNetInterfaceEx_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenNetInterfaceEx_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_element_OpenNetInterfaceEx_hNetInterface(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OpenNetInterfaceEx_hNetInterface_, NDR_POINTER_REF, "Pointer to HNetInterface (policy_handle)",hf_clusapi_clusapi_OpenNetInterfaceEx_hNetInterface);
return offset;
}
static int
clusapi_dissect_element_OpenNetInterfaceEx_hNetInterface_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OpenNetInterfaceEx_hNetInterface, 0);
return offset;
}
static int
clusapi_dissect_OpenNetInterfaceEx_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OpenNetInterfaceEx";
offset = clusapi_dissect_element_OpenNetInterfaceEx_lpdwGrantedAccess(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenNetInterfaceEx_Status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenNetInterfaceEx_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenNetInterfaceEx_hNetInterface(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_OpenNetInterfaceEx_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OpenNetInterfaceEx";
offset = clusapi_dissect_element_OpenNetInterfaceEx_lpszNetInterfaceName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OpenNetInterfaceEx_dwDesiredAccess(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_ChangeCsvState_hResource(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ChangeCsvState_hResource, 0);
return offset;
}
static int
clusapi_dissect_element_ChangeCsvState_dwState(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ChangeCsvState_dwState, 0);
return offset;
}
static int
clusapi_dissect_element_ChangeCsvState_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ChangeCsvState_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_ChangeCsvState_rpc_status);
return offset;
}
static int
clusapi_dissect_element_ChangeCsvState_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ChangeCsvState_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_ChangeCsvState_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="ChangeCsvState";
offset = clusapi_dissect_element_ChangeCsvState_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_ChangeCsvState_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="ChangeCsvState";
offset = clusapi_dissect_element_ChangeCsvState_hResource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ChangeCsvState_dwState(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_CreateNodeEnumEx_hNode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateNodeEnumEx_hNode, 0);
return offset;
}
static int
clusapi_dissect_element_CreateNodeEnumEx_dwType(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateNodeEnumEx_dwType, 0);
return offset;
}
static int
clusapi_dissect_element_CreateNodeEnumEx_dwOptions(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateNodeEnumEx_dwOptions, 0);
return offset;
}
static int
clusapi_dissect_element_CreateNodeEnumEx_ReturnIdEnum(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateNodeEnumEx_ReturnIdEnum_, NDR_POINTER_REF, "Pointer to ReturnIdEnum (ENUM_LIST)",hf_clusapi_clusapi_CreateNodeEnumEx_ReturnIdEnum);
return offset;
}
static int
clusapi_dissect_element_CreateNodeEnumEx_ReturnIdEnum_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateNodeEnumEx_ReturnIdEnum__, NDR_POINTER_UNIQUE, "Pointer to ReturnIdEnum (ENUM_LIST)",hf_clusapi_clusapi_CreateNodeEnumEx_ReturnIdEnum);
return offset;
}
static int
clusapi_dissect_element_CreateNodeEnumEx_ReturnIdEnum__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_struct_ENUM_LIST(tvb,offset,pinfo,tree,di,drep,hf_clusapi_clusapi_CreateNodeEnumEx_ReturnIdEnum,0);
return offset;
}
static int
clusapi_dissect_element_CreateNodeEnumEx_ReturnNameEnum(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateNodeEnumEx_ReturnNameEnum_, NDR_POINTER_REF, "Pointer to ReturnNameEnum (ENUM_LIST)",hf_clusapi_clusapi_CreateNodeEnumEx_ReturnNameEnum);
return offset;
}
static int
clusapi_dissect_element_CreateNodeEnumEx_ReturnNameEnum_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateNodeEnumEx_ReturnNameEnum__, NDR_POINTER_UNIQUE, "Pointer to ReturnNameEnum (ENUM_LIST)",hf_clusapi_clusapi_CreateNodeEnumEx_ReturnNameEnum);
return offset;
}
static int
clusapi_dissect_element_CreateNodeEnumEx_ReturnNameEnum__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_struct_ENUM_LIST(tvb,offset,pinfo,tree,di,drep,hf_clusapi_clusapi_CreateNodeEnumEx_ReturnNameEnum,0);
return offset;
}
static int
clusapi_dissect_element_CreateNodeEnumEx_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateNodeEnumEx_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_CreateNodeEnumEx_rpc_status);
return offset;
}
static int
clusapi_dissect_element_CreateNodeEnumEx_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateNodeEnumEx_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_CreateNodeEnumEx_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="CreateNodeEnumEx";
offset = clusapi_dissect_element_CreateNodeEnumEx_ReturnIdEnum(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateNodeEnumEx_ReturnNameEnum(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateNodeEnumEx_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_CreateNodeEnumEx_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CreateNodeEnumEx";
offset = clusapi_dissect_element_CreateNodeEnumEx_hNode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateNodeEnumEx_dwType(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateNodeEnumEx_dwOptions(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_CreateEnumEx_hCluster(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateEnumEx_hCluster, 0);
return offset;
}
static int
clusapi_dissect_element_CreateEnumEx_dwType(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_bitmap_ClusterEnumType(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateEnumEx_dwType, 0);
return offset;
}
static int
clusapi_dissect_element_CreateEnumEx_dwOptions(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateEnumEx_dwOptions, 0);
return offset;
}
static int
clusapi_dissect_element_CreateEnumEx_ReturnIdEnum(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateEnumEx_ReturnIdEnum_, NDR_POINTER_REF, "Pointer to ReturnIdEnum (ENUM_LIST)",hf_clusapi_clusapi_CreateEnumEx_ReturnIdEnum);
return offset;
}
static int
clusapi_dissect_element_CreateEnumEx_ReturnIdEnum_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateEnumEx_ReturnIdEnum__, NDR_POINTER_UNIQUE, "Pointer to ReturnIdEnum (ENUM_LIST)",hf_clusapi_clusapi_CreateEnumEx_ReturnIdEnum);
return offset;
}
static int
clusapi_dissect_element_CreateEnumEx_ReturnIdEnum__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_struct_ENUM_LIST(tvb,offset,pinfo,tree,di,drep,hf_clusapi_clusapi_CreateEnumEx_ReturnIdEnum,0);
return offset;
}
static int
clusapi_dissect_element_CreateEnumEx_ReturnNameEnum(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateEnumEx_ReturnNameEnum_, NDR_POINTER_REF, "Pointer to ReturnNameEnum (ENUM_LIST)",hf_clusapi_clusapi_CreateEnumEx_ReturnNameEnum);
return offset;
}
static int
clusapi_dissect_element_CreateEnumEx_ReturnNameEnum_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateEnumEx_ReturnNameEnum__, NDR_POINTER_UNIQUE, "Pointer to ReturnNameEnum (ENUM_LIST)",hf_clusapi_clusapi_CreateEnumEx_ReturnNameEnum);
return offset;
}
static int
clusapi_dissect_element_CreateEnumEx_ReturnNameEnum__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_struct_ENUM_LIST(tvb,offset,pinfo,tree,di,drep,hf_clusapi_clusapi_CreateEnumEx_ReturnNameEnum,0);
return offset;
}
static int
clusapi_dissect_element_CreateEnumEx_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateEnumEx_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_CreateEnumEx_rpc_status);
return offset;
}
static int
clusapi_dissect_element_CreateEnumEx_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateEnumEx_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_CreateEnumEx_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="CreateEnumEx";
offset = clusapi_dissect_element_CreateEnumEx_ReturnIdEnum(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateEnumEx_ReturnNameEnum(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateEnumEx_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_CreateEnumEx_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CreateEnumEx";
offset = clusapi_dissect_element_CreateEnumEx_hCluster(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateEnumEx_dwType(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateEnumEx_dwOptions(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_PauseNodeEx_hNode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_PauseNodeEx_hNode, 0);
return offset;
}
static int
clusapi_dissect_element_PauseNodeEx_bDrainNode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_PauseNodeEx_bDrainNode, 0);
return offset;
}
static int
clusapi_dissect_element_PauseNodeEx_dwPauseFlags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_PauseNodeEx_dwPauseFlags, 0);
return offset;
}
static int
clusapi_dissect_element_PauseNodeEx_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_PauseNodeEx_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_PauseNodeEx_rpc_status);
return offset;
}
static int
clusapi_dissect_element_PauseNodeEx_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_PauseNodeEx_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_PauseNodeEx_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="PauseNodeEx";
offset = clusapi_dissect_element_PauseNodeEx_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_PauseNodeEx_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="PauseNodeEx";
offset = clusapi_dissect_element_PauseNodeEx_hNode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_PauseNodeEx_bDrainNode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_PauseNodeEx_dwPauseFlags(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_PauseNodeWithDrainTarget_hNode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_PauseNodeWithDrainTarget_hNode, 0);
return offset;
}
static int
clusapi_dissect_element_PauseNodeWithDrainTarget_dwPauseFlags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_PauseNodeWithDrainTarget_dwPauseFlags, 0);
return offset;
}
static int
clusapi_dissect_element_PauseNodeWithDrainTarget_hNodeDrainTarget(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_PauseNodeWithDrainTarget_hNodeDrainTarget, 0);
return offset;
}
static int
clusapi_dissect_element_PauseNodeWithDrainTarget_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_PauseNodeWithDrainTarget_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_PauseNodeWithDrainTarget_rpc_status);
return offset;
}
static int
clusapi_dissect_element_PauseNodeWithDrainTarget_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_PauseNodeWithDrainTarget_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_PauseNodeWithDrainTarget_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="PauseNodeWithDrainTarget";
offset = clusapi_dissect_element_PauseNodeWithDrainTarget_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_PauseNodeWithDrainTarget_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="PauseNodeWithDrainTarget";
offset = clusapi_dissect_element_PauseNodeWithDrainTarget_hNode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_PauseNodeWithDrainTarget_dwPauseFlags(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_PauseNodeWithDrainTarget_hNodeDrainTarget(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_ResumeNodeEx_hNode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ResumeNodeEx_hNode, 0);
return offset;
}
static int
clusapi_dissect_element_ResumeNodeEx_dwResumeFailbackType(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ResumeNodeEx_dwResumeFailbackType, 0);
return offset;
}
static int
clusapi_dissect_element_ResumeNodeEx_dwResumeFlagsReserved(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ResumeNodeEx_dwResumeFlagsReserved, 0);
return offset;
}
static int
clusapi_dissect_element_ResumeNodeEx_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ResumeNodeEx_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_ResumeNodeEx_rpc_status);
return offset;
}
static int
clusapi_dissect_element_ResumeNodeEx_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ResumeNodeEx_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_ResumeNodeEx_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="ResumeNodeEx";
offset = clusapi_dissect_element_ResumeNodeEx_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_ResumeNodeEx_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="ResumeNodeEx";
offset = clusapi_dissect_element_ResumeNodeEx_hNode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ResumeNodeEx_dwResumeFailbackType(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ResumeNodeEx_dwResumeFlagsReserved(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_CreateGroupEx_lpszGroupName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateGroupEx_lpszGroupName_, NDR_POINTER_REF, "Pointer to LpszGroupName (uint16)",hf_clusapi_clusapi_CreateGroupEx_lpszGroupName);
return offset;
}
static int
clusapi_dissect_element_CreateGroupEx_lpszGroupName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_CreateGroupEx_lpszGroupName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_CreateGroupEx_pGroupInfo(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateGroupEx_pGroupInfo_, NDR_POINTER_UNIQUE, "Pointer to PGroupInfo (CLUSTER_CREATE_GROUP_INFO_RPC)",hf_clusapi_clusapi_CreateGroupEx_pGroupInfo);
return offset;
}
static int
clusapi_dissect_element_CreateGroupEx_pGroupInfo_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_struct_CLUSTER_CREATE_GROUP_INFO_RPC(tvb,offset,pinfo,tree,di,drep,hf_clusapi_clusapi_CreateGroupEx_pGroupInfo,0);
return offset;
}
static int
clusapi_dissect_element_CreateGroupEx_Status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateGroupEx_Status_, NDR_POINTER_REF, "Pointer to Status (WERROR)",hf_clusapi_clusapi_CreateGroupEx_Status);
return offset;
}
static int
clusapi_dissect_element_CreateGroupEx_Status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateGroupEx_Status, 0);
return offset;
}
static int
clusapi_dissect_element_CreateGroupEx_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateGroupEx_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_CreateGroupEx_rpc_status);
return offset;
}
static int
clusapi_dissect_element_CreateGroupEx_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateGroupEx_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_element_CreateGroupEx_hGroup(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateGroupEx_hGroup_, NDR_POINTER_REF, "Pointer to HGroup (policy_handle)",hf_clusapi_clusapi_CreateGroupEx_hGroup);
return offset;
}
static int
clusapi_dissect_element_CreateGroupEx_hGroup_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateGroupEx_hGroup, 0);
return offset;
}
static int
clusapi_dissect_CreateGroupEx_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CreateGroupEx";
offset = clusapi_dissect_element_CreateGroupEx_Status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateGroupEx_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateGroupEx_hGroup(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_CreateGroupEx_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CreateGroupEx";
offset = clusapi_dissect_element_CreateGroupEx_lpszGroupName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateGroupEx_pGroupInfo(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_OnlineGroupEx_hGroup(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OnlineGroupEx_hGroup, 0);
return offset;
}
static int
clusapi_dissect_element_OnlineGroupEx_dwOnlineFlags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OnlineGroupEx_dwOnlineFlags, 0);
return offset;
}
static int
clusapi_dissect_element_OnlineGroupEx_lpInBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OnlineGroupEx_lpInBuffer_, NDR_POINTER_REF, "Pointer to LpInBuffer (uint8)",hf_clusapi_clusapi_OnlineGroupEx_lpInBuffer);
return offset;
}
static int
clusapi_dissect_element_OnlineGroupEx_lpInBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OnlineGroupEx_lpInBuffer__);
return offset;
}
static int
clusapi_dissect_element_OnlineGroupEx_lpInBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OnlineGroupEx_lpInBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_OnlineGroupEx_cbInBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OnlineGroupEx_cbInBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_OnlineGroupEx_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OnlineGroupEx_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_OnlineGroupEx_rpc_status);
return offset;
}
static int
clusapi_dissect_element_OnlineGroupEx_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OnlineGroupEx_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_OnlineGroupEx_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="OnlineGroupEx";
offset = clusapi_dissect_element_OnlineGroupEx_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_OnlineGroupEx_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OnlineGroupEx";
offset = clusapi_dissect_element_OnlineGroupEx_hGroup(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OnlineGroupEx_dwOnlineFlags(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OnlineGroupEx_lpInBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OnlineGroupEx_cbInBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_OfflineGroupEx_hGroup(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OfflineGroupEx_hGroup, 0);
return offset;
}
static int
clusapi_dissect_element_OfflineGroupEx_dwOfflineFlags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OfflineGroupEx_dwOfflineFlags, 0);
return offset;
}
static int
clusapi_dissect_element_OfflineGroupEx_lpInBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OfflineGroupEx_lpInBuffer_, NDR_POINTER_REF, "Pointer to LpInBuffer (uint8)",hf_clusapi_clusapi_OfflineGroupEx_lpInBuffer);
return offset;
}
static int
clusapi_dissect_element_OfflineGroupEx_lpInBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OfflineGroupEx_lpInBuffer__);
return offset;
}
static int
clusapi_dissect_element_OfflineGroupEx_lpInBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OfflineGroupEx_lpInBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_OfflineGroupEx_cbInBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OfflineGroupEx_cbInBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_OfflineGroupEx_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OfflineGroupEx_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_OfflineGroupEx_rpc_status);
return offset;
}
static int
clusapi_dissect_element_OfflineGroupEx_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OfflineGroupEx_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_OfflineGroupEx_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="OfflineGroupEx";
offset = clusapi_dissect_element_OfflineGroupEx_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_OfflineGroupEx_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OfflineGroupEx";
offset = clusapi_dissect_element_OfflineGroupEx_hGroup(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OfflineGroupEx_dwOfflineFlags(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OfflineGroupEx_lpInBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OfflineGroupEx_cbInBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_MoveGroupEx_hGroup(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_MoveGroupEx_hGroup, 0);
return offset;
}
static int
clusapi_dissect_element_MoveGroupEx_dwMoveFlags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_MoveGroupEx_dwMoveFlags, 0);
return offset;
}
static int
clusapi_dissect_element_MoveGroupEx_lpInBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_MoveGroupEx_lpInBuffer_, NDR_POINTER_REF, "Pointer to LpInBuffer (uint8)",hf_clusapi_clusapi_MoveGroupEx_lpInBuffer);
return offset;
}
static int
clusapi_dissect_element_MoveGroupEx_lpInBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_MoveGroupEx_lpInBuffer__);
return offset;
}
static int
clusapi_dissect_element_MoveGroupEx_lpInBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_MoveGroupEx_lpInBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_MoveGroupEx_cbInBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_MoveGroupEx_cbInBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_MoveGroupEx_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_MoveGroupEx_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_MoveGroupEx_rpc_status);
return offset;
}
static int
clusapi_dissect_element_MoveGroupEx_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_MoveGroupEx_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_MoveGroupEx_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="MoveGroupEx";
offset = clusapi_dissect_element_MoveGroupEx_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_MoveGroupEx_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="MoveGroupEx";
offset = clusapi_dissect_element_MoveGroupEx_hGroup(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_MoveGroupEx_dwMoveFlags(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_MoveGroupEx_lpInBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_MoveGroupEx_cbInBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_MoveGroupToNodeEx_hGroup(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_MoveGroupToNodeEx_hGroup, 0);
return offset;
}
static int
clusapi_dissect_element_MoveGroupToNodeEx_hNode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_MoveGroupToNodeEx_hNode, 0);
return offset;
}
static int
clusapi_dissect_element_MoveGroupToNodeEx_dwMoveFlags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_MoveGroupToNodeEx_dwMoveFlags, 0);
return offset;
}
static int
clusapi_dissect_element_MoveGroupToNodeEx_lpInBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_MoveGroupToNodeEx_lpInBuffer_, NDR_POINTER_REF, "Pointer to LpInBuffer (uint8)",hf_clusapi_clusapi_MoveGroupToNodeEx_lpInBuffer);
return offset;
}
static int
clusapi_dissect_element_MoveGroupToNodeEx_lpInBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_MoveGroupToNodeEx_lpInBuffer__);
return offset;
}
static int
clusapi_dissect_element_MoveGroupToNodeEx_lpInBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_MoveGroupToNodeEx_lpInBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_MoveGroupToNodeEx_cbInBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_MoveGroupToNodeEx_cbInBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_MoveGroupToNodeEx_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_MoveGroupToNodeEx_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_MoveGroupToNodeEx_rpc_status);
return offset;
}
static int
clusapi_dissect_element_MoveGroupToNodeEx_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_MoveGroupToNodeEx_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_MoveGroupToNodeEx_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="MoveGroupToNodeEx";
offset = clusapi_dissect_element_MoveGroupToNodeEx_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_MoveGroupToNodeEx_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="MoveGroupToNodeEx";
offset = clusapi_dissect_element_MoveGroupToNodeEx_hGroup(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_MoveGroupToNodeEx_hNode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_MoveGroupToNodeEx_dwMoveFlags(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_MoveGroupToNodeEx_lpInBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_MoveGroupToNodeEx_cbInBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_CancelClusterGroupOperation_hGroup(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CancelClusterGroupOperation_hGroup, 0);
return offset;
}
static int
clusapi_dissect_element_CancelClusterGroupOperation_dwCancelFlags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CancelClusterGroupOperation_dwCancelFlags, 0);
return offset;
}
static int
clusapi_dissect_element_CancelClusterGroupOperation_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CancelClusterGroupOperation_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_CancelClusterGroupOperation_rpc_status);
return offset;
}
static int
clusapi_dissect_element_CancelClusterGroupOperation_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CancelClusterGroupOperation_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_CancelClusterGroupOperation_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="CancelClusterGroupOperation";
offset = clusapi_dissect_element_CancelClusterGroupOperation_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_CancelClusterGroupOperation_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CancelClusterGroupOperation";
offset = clusapi_dissect_element_CancelClusterGroupOperation_hGroup(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CancelClusterGroupOperation_dwCancelFlags(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_OnlineResourceEx_hResource(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OnlineResourceEx_hResource, 0);
return offset;
}
static int
clusapi_dissect_element_OnlineResourceEx_dwOnlineFlags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OnlineResourceEx_dwOnlineFlags, 0);
return offset;
}
static int
clusapi_dissect_element_OnlineResourceEx_lpInBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OnlineResourceEx_lpInBuffer_, NDR_POINTER_REF, "Pointer to LpInBuffer (uint8)",hf_clusapi_clusapi_OnlineResourceEx_lpInBuffer);
return offset;
}
static int
clusapi_dissect_element_OnlineResourceEx_lpInBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OnlineResourceEx_lpInBuffer__);
return offset;
}
static int
clusapi_dissect_element_OnlineResourceEx_lpInBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OnlineResourceEx_lpInBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_OnlineResourceEx_cbInBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OnlineResourceEx_cbInBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_OnlineResourceEx_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OnlineResourceEx_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_OnlineResourceEx_rpc_status);
return offset;
}
static int
clusapi_dissect_element_OnlineResourceEx_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OnlineResourceEx_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_OnlineResourceEx_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="OnlineResourceEx";
offset = clusapi_dissect_element_OnlineResourceEx_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_OnlineResourceEx_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OnlineResourceEx";
offset = clusapi_dissect_element_OnlineResourceEx_hResource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OnlineResourceEx_dwOnlineFlags(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OnlineResourceEx_lpInBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OnlineResourceEx_cbInBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_OfflineResourceEx_hResource(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OfflineResourceEx_hResource, 0);
return offset;
}
static int
clusapi_dissect_element_OfflineResourceEx_dwOfflineFlags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OfflineResourceEx_dwOfflineFlags, 0);
return offset;
}
static int
clusapi_dissect_element_OfflineResourceEx_lpInBuffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OfflineResourceEx_lpInBuffer_, NDR_POINTER_REF, "Pointer to LpInBuffer (uint8)",hf_clusapi_clusapi_OfflineResourceEx_lpInBuffer);
return offset;
}
static int
clusapi_dissect_element_OfflineResourceEx_lpInBuffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OfflineResourceEx_lpInBuffer__);
return offset;
}
static int
clusapi_dissect_element_OfflineResourceEx_lpInBuffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OfflineResourceEx_lpInBuffer, 0);
return offset;
}
static int
clusapi_dissect_element_OfflineResourceEx_cbInBufferSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OfflineResourceEx_cbInBufferSize, 0);
return offset;
}
static int
clusapi_dissect_element_OfflineResourceEx_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_OfflineResourceEx_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_OfflineResourceEx_rpc_status);
return offset;
}
static int
clusapi_dissect_element_OfflineResourceEx_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_OfflineResourceEx_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_OfflineResourceEx_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="OfflineResourceEx";
offset = clusapi_dissect_element_OfflineResourceEx_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_OfflineResourceEx_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="OfflineResourceEx";
offset = clusapi_dissect_element_OfflineResourceEx_hResource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OfflineResourceEx_dwOfflineFlags(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OfflineResourceEx_lpInBuffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_OfflineResourceEx_cbInBufferSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_CreateNotifyV2_rpc_error(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateNotifyV2_rpc_error_, NDR_POINTER_REF, "Pointer to Rpc Error (WERROR)",hf_clusapi_clusapi_CreateNotifyV2_rpc_error);
return offset;
}
static int
clusapi_dissect_element_CreateNotifyV2_rpc_error_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateNotifyV2_rpc_error, 0);
return offset;
}
static int
clusapi_dissect_element_CreateNotifyV2_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateNotifyV2_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_CreateNotifyV2_rpc_status);
return offset;
}
static int
clusapi_dissect_element_CreateNotifyV2_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateNotifyV2_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_element_CreateNotifyV2_hNotify(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateNotifyV2_hNotify_, NDR_POINTER_REF, "Pointer to HNotify (policy_handle)",hf_clusapi_clusapi_CreateNotifyV2_hNotify);
return offset;
}
static int
clusapi_dissect_element_CreateNotifyV2_hNotify_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateNotifyV2_hNotify, 0);
return offset;
}
static int
clusapi_dissect_CreateNotifyV2_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CreateNotifyV2";
offset = clusapi_dissect_element_CreateNotifyV2_rpc_error(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateNotifyV2_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateNotifyV2_hNotify(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_CreateNotifyV2_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CreateNotifyV2";
return offset;
}
static int
clusapi_dissect_element_AddNotifyV2_hNotify(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyV2_hNotify, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyV2_hObject(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyV2_hObject, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyV2_filter(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_struct_NOTIFY_FILTER_AND_TYPE_RPC(tvb,offset,pinfo,tree,di,drep,hf_clusapi_clusapi_AddNotifyV2_filter,0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyV2_dwNotifyKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyV2_dwNotifyKey, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyV2_dwVersion(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyV2_dwVersion, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyV2_isTargetedAtObject(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyV2_isTargetedAtObject, 0);
return offset;
}
static int
clusapi_dissect_element_AddNotifyV2_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_AddNotifyV2_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_AddNotifyV2_rpc_status);
return offset;
}
static int
clusapi_dissect_element_AddNotifyV2_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_AddNotifyV2_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_AddNotifyV2_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="AddNotifyV2";
offset = clusapi_dissect_element_AddNotifyV2_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_AddNotifyV2_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="AddNotifyV2";
offset = clusapi_dissect_element_AddNotifyV2_hNotify(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyV2_hObject(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyV2_filter(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyV2_dwNotifyKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyV2_dwVersion(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_AddNotifyV2_isTargetedAtObject(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_GetNotifyV2_hNotify(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetNotifyV2_hNotify, 0);
return offset;
}
static int
clusapi_dissect_element_GetNotifyV2_Notifications(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNotifyV2_Notifications_, NDR_POINTER_REF, "Pointer to Notifications (NOTIFICATION_RPC)",hf_clusapi_clusapi_GetNotifyV2_Notifications);
return offset;
}
static int
clusapi_dissect_element_GetNotifyV2_Notifications_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNotifyV2_Notifications__, NDR_POINTER_UNIQUE, "Pointer to Notifications (NOTIFICATION_RPC)",hf_clusapi_clusapi_GetNotifyV2_Notifications);
return offset;
}
static int
clusapi_dissect_element_GetNotifyV2_Notifications__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNotifyV2_Notifications___);
return offset;
}
static int
clusapi_dissect_element_GetNotifyV2_Notifications___(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_struct_NOTIFICATION_RPC(tvb,offset,pinfo,tree,di,drep,hf_clusapi_clusapi_GetNotifyV2_Notifications,0);
return offset;
}
static int
clusapi_dissect_element_GetNotifyV2_dwNumNotifications(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNotifyV2_dwNumNotifications_, NDR_POINTER_REF, "Pointer to DwNumNotifications (uint32)",hf_clusapi_clusapi_GetNotifyV2_dwNumNotifications);
return offset;
}
static int
clusapi_dissect_element_GetNotifyV2_dwNumNotifications_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetNotifyV2_dwNumNotifications, 0);
return offset;
}
static int
clusapi_dissect_GetNotifyV2_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="GetNotifyV2";
offset = clusapi_dissect_element_GetNotifyV2_Notifications(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetNotifyV2_dwNumNotifications(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_GetNotifyV2_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="GetNotifyV2";
offset = clusapi_dissect_element_GetNotifyV2_hNotify(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_QueryAllValues_hKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_QueryAllValues_hKey, 0);
return offset;
}
static int
clusapi_dissect_element_QueryAllValues_pcbData(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_QueryAllValues_pcbData_, NDR_POINTER_REF, "Pointer to PcbData (uint32)",hf_clusapi_clusapi_QueryAllValues_pcbData);
return offset;
}
static int
clusapi_dissect_element_QueryAllValues_pcbData_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_QueryAllValues_pcbData, 0);
return offset;
}
static int
clusapi_dissect_element_QueryAllValues_ppData(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_QueryAllValues_ppData_, NDR_POINTER_REF, "Pointer to PpData (uint8)",hf_clusapi_clusapi_QueryAllValues_ppData);
return offset;
}
static int
clusapi_dissect_element_QueryAllValues_ppData_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_QueryAllValues_ppData__);
return offset;
}
static int
clusapi_dissect_element_QueryAllValues_ppData__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_QueryAllValues_ppData___, NDR_POINTER_UNIQUE, "Pointer to PpData (uint8)",hf_clusapi_clusapi_QueryAllValues_ppData);
return offset;
}
static int
clusapi_dissect_element_QueryAllValues_ppData___(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_QueryAllValues_ppData____);
return offset;
}
static int
clusapi_dissect_element_QueryAllValues_ppData____(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_QueryAllValues_ppData, 0);
return offset;
}
static int
clusapi_dissect_element_QueryAllValues_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_QueryAllValues_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_QueryAllValues_rpc_status);
return offset;
}
static int
clusapi_dissect_element_QueryAllValues_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_QueryAllValues_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_QueryAllValues_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="QueryAllValues";
offset = clusapi_dissect_element_QueryAllValues_pcbData(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_QueryAllValues_ppData(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_QueryAllValues_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_QueryAllValues_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="QueryAllValues";
offset = clusapi_dissect_element_QueryAllValues_hKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_StmFindDisk_hCluster(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_StmFindDisk_hCluster, 0);
return offset;
}
static int
clusapi_dissect_element_StmFindDisk_dwFlags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_StmFindDisk_dwFlags, 0);
return offset;
}
static int
clusapi_dissect_element_StmFindDisk_pDiskId(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_StmFindDisk_pDiskId_, NDR_POINTER_UNIQUE, "Pointer to PDiskId (CLUSTER_DISKID)",hf_clusapi_clusapi_StmFindDisk_pDiskId);
return offset;
}
static int
clusapi_dissect_element_StmFindDisk_pDiskId_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_struct_CLUSTER_DISKID(tvb,offset,pinfo,tree,di,drep,hf_clusapi_clusapi_StmFindDisk_pDiskId,0);
return offset;
}
static int
clusapi_dissect_element_StmFindDisk_pUniqueId(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_StmFindDisk_pUniqueId_, NDR_POINTER_UNIQUE, "Pointer to PUniqueId (uint8)",hf_clusapi_clusapi_StmFindDisk_pUniqueId);
return offset;
}
static int
clusapi_dissect_element_StmFindDisk_pUniqueId_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_StmFindDisk_pUniqueId__);
return offset;
}
static int
clusapi_dissect_element_StmFindDisk_pUniqueId__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_StmFindDisk_pUniqueId, 0);
return offset;
}
static int
clusapi_dissect_element_StmFindDisk_uniqueIdSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_StmFindDisk_uniqueIdSize, 0);
return offset;
}
static int
clusapi_dissect_element_StmFindDisk_ppszDeviceName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_StmFindDisk_ppszDeviceName_, NDR_POINTER_REF, "Pointer to PpszDeviceName (uint16)",hf_clusapi_clusapi_StmFindDisk_ppszDeviceName);
return offset;
}
static int
clusapi_dissect_element_StmFindDisk_ppszDeviceName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_StmFindDisk_ppszDeviceName__, NDR_POINTER_UNIQUE, "Pointer to PpszDeviceName (uint16)",hf_clusapi_clusapi_StmFindDisk_ppszDeviceName);
return offset;
}
static int
clusapi_dissect_element_StmFindDisk_ppszDeviceName__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_clusapi_clusapi_StmFindDisk_ppszDeviceName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
clusapi_dissect_element_StmFindDisk_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_StmFindDisk_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_StmFindDisk_rpc_status);
return offset;
}
static int
clusapi_dissect_element_StmFindDisk_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_StmFindDisk_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_StmFindDisk_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="StmFindDisk";
offset = clusapi_dissect_element_StmFindDisk_pDiskId(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_StmFindDisk_ppszDeviceName(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_StmFindDisk_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_StmFindDisk_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="StmFindDisk";
offset = clusapi_dissect_element_StmFindDisk_hCluster(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_StmFindDisk_dwFlags(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_StmFindDisk_pDiskId(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_StmFindDisk_pUniqueId(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_StmFindDisk_uniqueIdSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_ClusterMrr_hCluster(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ClusterMrr_hCluster, 0);
return offset;
}
static int
clusapi_dissect_element_ClusterMrr_fExcludeSelf(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ClusterMrr_fExcludeSelf, 0);
return offset;
}
static int
clusapi_dissect_element_ClusterMrr_nodeSet(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uint64(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ClusterMrr_nodeSet, NULL);
return offset;
}
static int
clusapi_dissect_element_ClusterMrr_dwTimeout(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ClusterMrr_dwTimeout, 0);
return offset;
}
static int
clusapi_dissect_element_ClusterMrr_dwComponent(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ClusterMrr_dwComponent, 0);
return offset;
}
static int
clusapi_dissect_element_ClusterMrr_dwControlCode(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ClusterMrr_dwControlCode, 0);
return offset;
}
static int
clusapi_dissect_element_ClusterMrr_inSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ClusterMrr_inSize, 0);
return offset;
}
static int
clusapi_dissect_element_ClusterMrr_pInData(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ClusterMrr_pInData_, NDR_POINTER_UNIQUE, "Pointer to PInData (uint8)",hf_clusapi_clusapi_ClusterMrr_pInData);
return offset;
}
static int
clusapi_dissect_element_ClusterMrr_pInData_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ClusterMrr_pInData__);
return offset;
}
static int
clusapi_dissect_element_ClusterMrr_pInData__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ClusterMrr_pInData, 0);
return offset;
}
static int
clusapi_dissect_element_ClusterMrr_ppInfo(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ClusterMrr_ppInfo_, NDR_POINTER_REF, "Pointer to PpInfo (CLUSTER_MRR_RESPONSE)",hf_clusapi_clusapi_ClusterMrr_ppInfo);
return offset;
}
static int
clusapi_dissect_element_ClusterMrr_ppInfo_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ClusterMrr_ppInfo__);
return offset;
}
static int
clusapi_dissect_element_ClusterMrr_ppInfo__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ClusterMrr_ppInfo___, NDR_POINTER_UNIQUE, "Pointer to PpInfo (CLUSTER_MRR_RESPONSE)",hf_clusapi_clusapi_ClusterMrr_ppInfo);
return offset;
}
static int
clusapi_dissect_element_ClusterMrr_ppInfo___(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ClusterMrr_ppInfo____);
return offset;
}
static int
clusapi_dissect_element_ClusterMrr_ppInfo____(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_struct_CLUSTER_MRR_RESPONSE(tvb,offset,pinfo,tree,di,drep,hf_clusapi_clusapi_ClusterMrr_ppInfo,0);
return offset;
}
static int
clusapi_dissect_element_ClusterMrr_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ClusterMrr_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_ClusterMrr_rpc_status);
return offset;
}
static int
clusapi_dissect_element_ClusterMrr_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ClusterMrr_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_ClusterMrr_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="ClusterMrr";
offset = clusapi_dissect_element_ClusterMrr_ppInfo(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ClusterMrr_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_ClusterMrr_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="ClusterMrr";
offset = clusapi_dissect_element_ClusterMrr_hCluster(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ClusterMrr_fExcludeSelf(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ClusterMrr_nodeSet(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ClusterMrr_dwTimeout(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ClusterMrr_dwComponent(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ClusterMrr_dwControlCode(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ClusterMrr_inSize(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ClusterMrr_pInData(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_CreateGroupEnum_hCluster(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateGroupEnum_hCluster, 0);
return offset;
}
static int
clusapi_dissect_element_CreateGroupEnum_pProperties(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateGroupEnum_pProperties_, NDR_POINTER_UNIQUE, "Pointer to PProperties (uint8)",hf_clusapi_clusapi_CreateGroupEnum_pProperties);
return offset;
}
static int
clusapi_dissect_element_CreateGroupEnum_pProperties_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateGroupEnum_pProperties__);
return offset;
}
static int
clusapi_dissect_element_CreateGroupEnum_pProperties__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateGroupEnum_pProperties, 0);
return offset;
}
static int
clusapi_dissect_element_CreateGroupEnum_cbProperties(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateGroupEnum_cbProperties, 0);
return offset;
}
static int
clusapi_dissect_element_CreateGroupEnum_pRoProperties(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateGroupEnum_pRoProperties_, NDR_POINTER_UNIQUE, "Pointer to PRoProperties (uint8)",hf_clusapi_clusapi_CreateGroupEnum_pRoProperties);
return offset;
}
static int
clusapi_dissect_element_CreateGroupEnum_pRoProperties_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateGroupEnum_pRoProperties__);
return offset;
}
static int
clusapi_dissect_element_CreateGroupEnum_pRoProperties__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateGroupEnum_pRoProperties, 0);
return offset;
}
static int
clusapi_dissect_element_CreateGroupEnum_cbRoProperties(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateGroupEnum_cbRoProperties, 0);
return offset;
}
static int
clusapi_dissect_element_CreateGroupEnum_ppResultList(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateGroupEnum_ppResultList_, NDR_POINTER_REF, "Pointer to PpResultList (GROUP_ENUM_LIST)",hf_clusapi_clusapi_CreateGroupEnum_ppResultList);
return offset;
}
static int
clusapi_dissect_element_CreateGroupEnum_ppResultList_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateGroupEnum_ppResultList__, NDR_POINTER_UNIQUE, "Pointer to PpResultList (GROUP_ENUM_LIST)",hf_clusapi_clusapi_CreateGroupEnum_ppResultList);
return offset;
}
static int
clusapi_dissect_element_CreateGroupEnum_ppResultList__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_struct_GROUP_ENUM_LIST(tvb,offset,pinfo,tree,di,drep,hf_clusapi_clusapi_CreateGroupEnum_ppResultList,0);
return offset;
}
static int
clusapi_dissect_element_CreateGroupEnum_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateGroupEnum_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_CreateGroupEnum_rpc_status);
return offset;
}
static int
clusapi_dissect_element_CreateGroupEnum_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateGroupEnum_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_CreateGroupEnum_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="CreateGroupEnum";
offset = clusapi_dissect_element_CreateGroupEnum_ppResultList(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateGroupEnum_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_CreateGroupEnum_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CreateGroupEnum";
offset = clusapi_dissect_element_CreateGroupEnum_hCluster(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateGroupEnum_pProperties(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateGroupEnum_cbProperties(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateGroupEnum_pRoProperties(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateGroupEnum_cbRoProperties(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_CreateResourceEnum_hCluster(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateResourceEnum_hCluster, 0);
return offset;
}
static int
clusapi_dissect_element_CreateResourceEnum_pProperties(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateResourceEnum_pProperties_, NDR_POINTER_UNIQUE, "Pointer to PProperties (uint8)",hf_clusapi_clusapi_CreateResourceEnum_pProperties);
return offset;
}
static int
clusapi_dissect_element_CreateResourceEnum_pProperties_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateResourceEnum_pProperties__);
return offset;
}
static int
clusapi_dissect_element_CreateResourceEnum_pProperties__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateResourceEnum_pProperties, 0);
return offset;
}
static int
clusapi_dissect_element_CreateResourceEnum_cbProperties(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateResourceEnum_cbProperties, 0);
return offset;
}
static int
clusapi_dissect_element_CreateResourceEnum_pRoProperties(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateResourceEnum_pRoProperties_, NDR_POINTER_UNIQUE, "Pointer to PRoProperties (uint8)",hf_clusapi_clusapi_CreateResourceEnum_pRoProperties);
return offset;
}
static int
clusapi_dissect_element_CreateResourceEnum_pRoProperties_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateResourceEnum_pRoProperties__);
return offset;
}
static int
clusapi_dissect_element_CreateResourceEnum_pRoProperties__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateResourceEnum_pRoProperties, 0);
return offset;
}
static int
clusapi_dissect_element_CreateResourceEnum_cbRoProperties(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateResourceEnum_cbRoProperties, 0);
return offset;
}
static int
clusapi_dissect_element_CreateResourceEnum_ppResultList(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateResourceEnum_ppResultList_, NDR_POINTER_REF, "Pointer to PpResultList (RESOURCE_ENUM_LIST)",hf_clusapi_clusapi_CreateResourceEnum_ppResultList);
return offset;
}
static int
clusapi_dissect_element_CreateResourceEnum_ppResultList_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateResourceEnum_ppResultList__, NDR_POINTER_UNIQUE, "Pointer to PpResultList (RESOURCE_ENUM_LIST)",hf_clusapi_clusapi_CreateResourceEnum_ppResultList);
return offset;
}
static int
clusapi_dissect_element_CreateResourceEnum_ppResultList__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_struct_RESOURCE_ENUM_LIST(tvb,offset,pinfo,tree,di,drep,hf_clusapi_clusapi_CreateResourceEnum_ppResultList,0);
return offset;
}
static int
clusapi_dissect_element_CreateResourceEnum_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_CreateResourceEnum_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_CreateResourceEnum_rpc_status);
return offset;
}
static int
clusapi_dissect_element_CreateResourceEnum_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_CreateResourceEnum_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_CreateResourceEnum_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="CreateResourceEnum";
offset = clusapi_dissect_element_CreateResourceEnum_ppResultList(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateResourceEnum_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_CreateResourceEnum_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="CreateResourceEnum";
offset = clusapi_dissect_element_CreateResourceEnum_hCluster(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateResourceEnum_pProperties(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateResourceEnum_cbProperties(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateResourceEnum_pRoProperties(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_CreateResourceEnum_cbRoProperties(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_ExecuteReadBatch_hKey(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ExecuteReadBatch_hKey, 0);
return offset;
}
static int
clusapi_dissect_element_ExecuteReadBatch_cbInData(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ExecuteReadBatch_cbInData, 0);
return offset;
}
static int
clusapi_dissect_element_ExecuteReadBatch_lpInData(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ExecuteReadBatch_lpInData_, NDR_POINTER_REF, "Pointer to LpInData (uint8)",hf_clusapi_clusapi_ExecuteReadBatch_lpInData);
return offset;
}
static int
clusapi_dissect_element_ExecuteReadBatch_lpInData_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ExecuteReadBatch_lpInData__);
return offset;
}
static int
clusapi_dissect_element_ExecuteReadBatch_lpInData__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ExecuteReadBatch_lpInData, 0);
return offset;
}
static int
clusapi_dissect_element_ExecuteReadBatch_cbOutData(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ExecuteReadBatch_cbOutData_, NDR_POINTER_REF, "Pointer to CbOutData (uint32)",hf_clusapi_clusapi_ExecuteReadBatch_cbOutData);
return offset;
}
static int
clusapi_dissect_element_ExecuteReadBatch_cbOutData_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ExecuteReadBatch_cbOutData, 0);
return offset;
}
static int
clusapi_dissect_element_ExecuteReadBatch_lpOutData(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ExecuteReadBatch_lpOutData_, NDR_POINTER_REF, "Pointer to LpOutData (uint8)",hf_clusapi_clusapi_ExecuteReadBatch_lpOutData);
return offset;
}
static int
clusapi_dissect_element_ExecuteReadBatch_lpOutData_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ExecuteReadBatch_lpOutData__, NDR_POINTER_UNIQUE, "Pointer to LpOutData (uint8)",hf_clusapi_clusapi_ExecuteReadBatch_lpOutData);
return offset;
}
static int
clusapi_dissect_element_ExecuteReadBatch_lpOutData__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ExecuteReadBatch_lpOutData___);
return offset;
}
static int
clusapi_dissect_element_ExecuteReadBatch_lpOutData___(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ExecuteReadBatch_lpOutData, 0);
return offset;
}
static int
clusapi_dissect_element_ExecuteReadBatch_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_ExecuteReadBatch_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_ExecuteReadBatch_rpc_status);
return offset;
}
static int
clusapi_dissect_element_ExecuteReadBatch_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_ExecuteReadBatch_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_ExecuteReadBatch_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="ExecuteReadBatch";
offset = clusapi_dissect_element_ExecuteReadBatch_cbOutData(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ExecuteReadBatch_lpOutData(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ExecuteReadBatch_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_ExecuteReadBatch_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="ExecuteReadBatch";
offset = clusapi_dissect_element_ExecuteReadBatch_hKey(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ExecuteReadBatch_cbInData(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_ExecuteReadBatch_lpInData(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_RestartResource_hResource(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_RestartResource_hResource, 0);
return offset;
}
static int
clusapi_dissect_element_RestartResource_dwFlags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_RestartResource_dwFlags, 0);
return offset;
}
static int
clusapi_dissect_element_RestartResource_rpc_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_RestartResource_rpc_status_, NDR_POINTER_REF, "Pointer to Rpc Status (WERROR)",hf_clusapi_clusapi_RestartResource_rpc_status);
return offset;
}
static int
clusapi_dissect_element_RestartResource_rpc_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_RestartResource_rpc_status, 0);
return offset;
}
static int
clusapi_dissect_RestartResource_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="RestartResource";
offset = clusapi_dissect_element_RestartResource_rpc_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_RestartResource_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="RestartResource";
offset = clusapi_dissect_element_RestartResource_hResource(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_RestartResource_dwFlags(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
clusapi_dissect_element_GetNotifyAsync_hNotify(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetNotifyAsync_hNotify, 0);
return offset;
}
static int
clusapi_dissect_element_GetNotifyAsync_Notifications(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNotifyAsync_Notifications_, NDR_POINTER_REF, "Pointer to Notifications (NOTIFICATION_DATA_ASYNC_RPC)",hf_clusapi_clusapi_GetNotifyAsync_Notifications);
return offset;
}
static int
clusapi_dissect_element_GetNotifyAsync_Notifications_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNotifyAsync_Notifications__, NDR_POINTER_UNIQUE, "Pointer to Notifications (NOTIFICATION_DATA_ASYNC_RPC)",hf_clusapi_clusapi_GetNotifyAsync_Notifications);
return offset;
}
static int
clusapi_dissect_element_GetNotifyAsync_Notifications__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNotifyAsync_Notifications___);
return offset;
}
static int
clusapi_dissect_element_GetNotifyAsync_Notifications___(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = clusapi_dissect_struct_NOTIFICATION_DATA_ASYNC_RPC(tvb,offset,pinfo,tree,di,drep,hf_clusapi_clusapi_GetNotifyAsync_Notifications,0);
return offset;
}
static int
clusapi_dissect_element_GetNotifyAsync_dwNumNotifications(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, clusapi_dissect_element_GetNotifyAsync_dwNumNotifications_, NDR_POINTER_REF, "Pointer to DwNumNotifications (uint32)",hf_clusapi_clusapi_GetNotifyAsync_dwNumNotifications);
return offset;
}
static int
clusapi_dissect_element_GetNotifyAsync_dwNumNotifications_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_clusapi_GetNotifyAsync_dwNumNotifications, 0);
return offset;
}
static int
clusapi_dissect_GetNotifyAsync_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="GetNotifyAsync";
offset = clusapi_dissect_element_GetNotifyAsync_Notifications(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = clusapi_dissect_element_GetNotifyAsync_dwNumNotifications(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_clusapi_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
clusapi_dissect_GetNotifyAsync_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="GetNotifyAsync";
offset = clusapi_dissect_element_GetNotifyAsync_hNotify(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
void proto_register_dcerpc_clusapi(void)
{
static hf_register_info hf[] = {
{ &hf_clusapi_CLUSTER_CREATE_GROUP_INFO_RPC_dwGroupType,
{ "DwGroupType", "clusapi.CLUSTER_CREATE_GROUP_INFO_RPC.dwGroupType", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_CLUSTER_CREATE_GROUP_INFO_RPC_dwVersion,
{ "DwVersion", "clusapi.CLUSTER_CREATE_GROUP_INFO_RPC.dwVersion", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_CLUSTER_DISKID_DiskIdBlob,
{ "DiskIdBlob", "clusapi.CLUSTER_DISKID.DiskIdBlob", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_CLUSTER_DISKID_DiskIdType,
{ "DiskIdType", "clusapi.CLUSTER_DISKID.DiskIdType", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_CLUSTER_MRR_NODE_RESPONSE_ResultCode,
{ "ResultCode", "clusapi.CLUSTER_MRR_NODE_RESPONSE.ResultCode", FT_UINT32, BASE_DEC, VALS(HRES_errors), 0, NULL, HFILL }},
{ &hf_clusapi_CLUSTER_MRR_NODE_RESPONSE_ResultSize,
{ "ResultSize", "clusapi.CLUSTER_MRR_NODE_RESPONSE.ResultSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_CLUSTER_MRR_NODE_RESPONSE_pResultData,
{ "PResultData", "clusapi.CLUSTER_MRR_NODE_RESPONSE.pResultData", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_CLUSTER_MRR_NODE_RESPONSE_pszNodeName,
{ "PszNodeName", "clusapi.CLUSTER_MRR_NODE_RESPONSE.pszNodeName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_CLUSTER_MRR_RESPONSE_NodeCount,
{ "NodeCount", "clusapi.CLUSTER_MRR_RESPONSE.NodeCount", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_CLUSTER_MRR_RESPONSE_pNodes,
{ "PNodes", "clusapi.CLUSTER_MRR_RESPONSE.pNodes", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_CLUSTER_OPERATIONAL_VERSION_INFO_dwClusterHighestVersion,
{ "DwClusterHighestVersion", "clusapi.CLUSTER_OPERATIONAL_VERSION_INFO.dwClusterHighestVersion", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_CLUSTER_OPERATIONAL_VERSION_INFO_dwClusterLowestVersion,
{ "DwClusterLowestVersion", "clusapi.CLUSTER_OPERATIONAL_VERSION_INFO.dwClusterLowestVersion", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_CLUSTER_OPERATIONAL_VERSION_INFO_dwFlags,
{ "DwFlags", "clusapi.CLUSTER_OPERATIONAL_VERSION_INFO.dwFlags", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_CLUSTER_OPERATIONAL_VERSION_INFO_dwReserved,
{ "DwReserved", "clusapi.CLUSTER_OPERATIONAL_VERSION_INFO.dwReserved", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_CLUSTER_OPERATIONAL_VERSION_INFO_dwSize,
{ "DwSize", "clusapi.CLUSTER_OPERATIONAL_VERSION_INFO.dwSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_CLUS_RESOURCE_CLASS_INFO_Class,
{ "Class", "clusapi.CLUS_RESOURCE_CLASS_INFO.Class", FT_UINT32, BASE_DEC, VALS(clusapi_clusapi_ResourceClass_vals), 0, NULL, HFILL }},
{ &hf_clusapi_CLUS_RESOURCE_CLASS_INFO_SubClass,
{ "SubClass", "clusapi.CLUS_RESOURCE_CLASS_INFO.SubClass", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_ClusterEnumType_CLUSTER_ENUM_GROUP,
{ "CLUSTER ENUM GROUP", "clusapi.ClusterEnumType.CLUSTER_ENUM_GROUP", FT_BOOLEAN, 32, TFS(&ClusterEnumType_CLUSTER_ENUM_GROUP_tfs), ( 0x00000008 ), NULL, HFILL }},
{ &hf_clusapi_ClusterEnumType_CLUSTER_ENUM_INTERNAL_NETWORK,
{ "CLUSTER ENUM INTERNAL NETWORK", "clusapi.ClusterEnumType.CLUSTER_ENUM_INTERNAL_NETWORK", FT_BOOLEAN, 32, TFS(&ClusterEnumType_CLUSTER_ENUM_INTERNAL_NETWORK_tfs), ( 0x80000000 ), NULL, HFILL }},
{ &hf_clusapi_ClusterEnumType_CLUSTER_ENUM_NETINTERFACE,
{ "CLUSTER ENUM NETINTERFACE", "clusapi.ClusterEnumType.CLUSTER_ENUM_NETINTERFACE", FT_BOOLEAN, 32, TFS(&ClusterEnumType_CLUSTER_ENUM_NETINTERFACE_tfs), ( 0x00000020 ), NULL, HFILL }},
{ &hf_clusapi_ClusterEnumType_CLUSTER_ENUM_NETWORK,
{ "CLUSTER ENUM NETWORK", "clusapi.ClusterEnumType.CLUSTER_ENUM_NETWORK", FT_BOOLEAN, 32, TFS(&ClusterEnumType_CLUSTER_ENUM_NETWORK_tfs), ( 0x00000010 ), NULL, HFILL }},
{ &hf_clusapi_ClusterEnumType_CLUSTER_ENUM_NODE,
{ "CLUSTER ENUM NODE", "clusapi.ClusterEnumType.CLUSTER_ENUM_NODE", FT_BOOLEAN, 32, TFS(&ClusterEnumType_CLUSTER_ENUM_NODE_tfs), ( 0x00000001 ), NULL, HFILL }},
{ &hf_clusapi_ClusterEnumType_CLUSTER_ENUM_RESOURCE,
{ "CLUSTER ENUM RESOURCE", "clusapi.ClusterEnumType.CLUSTER_ENUM_RESOURCE", FT_BOOLEAN, 32, TFS(&ClusterEnumType_CLUSTER_ENUM_RESOURCE_tfs), ( 0x00000004 ), NULL, HFILL }},
{ &hf_clusapi_ClusterEnumType_CLUSTER_ENUM_RESTYPE,
{ "CLUSTER ENUM RESTYPE", "clusapi.ClusterEnumType.CLUSTER_ENUM_RESTYPE", FT_BOOLEAN, 32, TFS(&ClusterEnumType_CLUSTER_ENUM_RESTYPE_tfs), ( 0x00000002 ), NULL, HFILL }},
{ &hf_clusapi_ClusterEnumType_CLUSTER_ENUM_SHARED_VOLUME_RESOURCE,
{ "CLUSTER ENUM SHARED VOLUME RESOURCE", "clusapi.ClusterEnumType.CLUSTER_ENUM_SHARED_VOLUME_RESOURCE", FT_BOOLEAN, 32, TFS(&ClusterEnumType_CLUSTER_ENUM_SHARED_VOLUME_RESOURCE_tfs), ( 0x40000000 ), NULL, HFILL }},
{ &hf_clusapi_ClusterGroupEnumType_CLUSTER_GROUP_ENUM_CONTAINS,
{ "CLUSTER GROUP ENUM CONTAINS", "clusapi.ClusterGroupEnumType.CLUSTER_GROUP_ENUM_CONTAINS", FT_BOOLEAN, 32, TFS(&ClusterGroupEnumType_CLUSTER_GROUP_ENUM_CONTAINS_tfs), ( 0x00000001 ), NULL, HFILL }},
{ &hf_clusapi_ClusterGroupEnumType_CLUSTER_GROUP_ENUM_NODES,
{ "CLUSTER GROUP ENUM NODES", "clusapi.ClusterGroupEnumType.CLUSTER_GROUP_ENUM_NODES", FT_BOOLEAN, 32, TFS(&ClusterGroupEnumType_CLUSTER_GROUP_ENUM_NODES_tfs), ( 0x00000002 ), NULL, HFILL }},
{ &hf_clusapi_ClusterResTypeEnumType_CLUSTER_RESOURCE_TYPE_ENUM_NODES,
{ "CLUSTER RESOURCE TYPE ENUM NODES", "clusapi.ClusterResTypeEnumType.CLUSTER_RESOURCE_TYPE_ENUM_NODES", FT_BOOLEAN, 32, TFS(&ClusterResTypeEnumType_CLUSTER_RESOURCE_TYPE_ENUM_NODES_tfs), ( 0x00000001 ), NULL, HFILL }},
{ &hf_clusapi_ClusterResTypeEnumType_CLUSTER_RESOURCE_TYPE_ENUM_RESOURCES,
{ "CLUSTER RESOURCE TYPE ENUM RESOURCES", "clusapi.ClusterResTypeEnumType.CLUSTER_RESOURCE_TYPE_ENUM_RESOURCES", FT_BOOLEAN, 32, TFS(&ClusterResTypeEnumType_CLUSTER_RESOURCE_TYPE_ENUM_RESOURCES_tfs), ( 0x00000002 ), NULL, HFILL }},
{ &hf_clusapi_ENUM_ENTRY_Name,
{ "Name", "clusapi.ENUM_ENTRY.Name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_ENUM_ENTRY_Type,
{ "Type", "clusapi.ENUM_ENTRY.Type", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_ENUM_LIST_Entry,
{ "Entry", "clusapi.ENUM_LIST.Entry", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_ENUM_LIST_EntryCount,
{ "EntryCount", "clusapi.ENUM_LIST.EntryCount", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_GROUP_ENUM_ENTRY_Id,
{ "Id", "clusapi.GROUP_ENUM_ENTRY.Id", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_GROUP_ENUM_ENTRY_Name,
{ "Name", "clusapi.GROUP_ENUM_ENTRY.Name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_GROUP_ENUM_ENTRY_Owner,
{ "Owner", "clusapi.GROUP_ENUM_ENTRY.Owner", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_GROUP_ENUM_ENTRY_Properties,
{ "Properties", "clusapi.GROUP_ENUM_ENTRY.Properties", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_GROUP_ENUM_ENTRY_RoProperties,
{ "RoProperties", "clusapi.GROUP_ENUM_ENTRY.RoProperties", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_GROUP_ENUM_ENTRY_cbProperties,
{ "CbProperties", "clusapi.GROUP_ENUM_ENTRY.cbProperties", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_GROUP_ENUM_ENTRY_cbRoProperties,
{ "CbRoProperties", "clusapi.GROUP_ENUM_ENTRY.cbRoProperties", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_GROUP_ENUM_ENTRY_dwFlags,
{ "DwFlags", "clusapi.GROUP_ENUM_ENTRY.dwFlags", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_GROUP_ENUM_ENTRY_dwState,
{ "DwState", "clusapi.GROUP_ENUM_ENTRY.dwState", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_GROUP_ENUM_LIST_Entry,
{ "Entry", "clusapi.GROUP_ENUM_LIST.Entry", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_GROUP_ENUM_LIST_EntryCount,
{ "EntryCount", "clusapi.GROUP_ENUM_LIST.EntryCount", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_IDL_CLUSTER_SET_PASSWORD_STATUS_NodeId,
{ "NodeId", "clusapi.IDL_CLUSTER_SET_PASSWORD_STATUS.NodeId", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_IDL_CLUSTER_SET_PASSWORD_STATUS_ReturnStatus,
{ "ReturnStatus", "clusapi.IDL_CLUSTER_SET_PASSWORD_STATUS.ReturnStatus", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_IDL_CLUSTER_SET_PASSWORD_STATUS_SetAttempted,
{ "SetAttempted", "clusapi.IDL_CLUSTER_SET_PASSWORD_STATUS.SetAttempted", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_NOTIFICATION_DATA_ASYNC_RPC_Name,
{ "Name", "clusapi.NOTIFICATION_DATA_ASYNC_RPC.Name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_NOTIFICATION_DATA_ASYNC_RPC_dwFilter,
{ "DwFilter", "clusapi.NOTIFICATION_DATA_ASYNC_RPC.dwFilter", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_NOTIFICATION_DATA_ASYNC_RPC_dwNotifyKey,
{ "DwNotifyKey", "clusapi.NOTIFICATION_DATA_ASYNC_RPC.dwNotifyKey", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_NOTIFICATION_DATA_RPC_FilterAndType,
{ "FilterAndType", "clusapi.NOTIFICATION_DATA_RPC.FilterAndType", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_NOTIFICATION_DATA_RPC_Name,
{ "Name", "clusapi.NOTIFICATION_DATA_RPC.Name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_NOTIFICATION_DATA_RPC_ObjectId,
{ "ObjectId", "clusapi.NOTIFICATION_DATA_RPC.ObjectId", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_NOTIFICATION_DATA_RPC_ParentId,
{ "ParentId", "clusapi.NOTIFICATION_DATA_RPC.ParentId", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_NOTIFICATION_DATA_RPC_Type,
{ "Type", "clusapi.NOTIFICATION_DATA_RPC.Type", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_NOTIFICATION_DATA_RPC_buffer,
{ "Buffer", "clusapi.NOTIFICATION_DATA_RPC.buffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_NOTIFICATION_DATA_RPC_dwBufferSize,
{ "DwBufferSize", "clusapi.NOTIFICATION_DATA_RPC.dwBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_NOTIFICATION_RPC_NotificationData,
{ "NotificationData", "clusapi.NOTIFICATION_RPC.NotificationData", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_NOTIFICATION_RPC_dwNotifyKey,
{ "DwNotifyKey", "clusapi.NOTIFICATION_RPC.dwNotifyKey", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_NOTIFY_FILTER_AND_TYPE_RPC_FilterFlags,
{ "FilterFlags", "clusapi.NOTIFY_FILTER_AND_TYPE_RPC.FilterFlags", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_NOTIFY_FILTER_AND_TYPE_RPC_dwObjectType,
{ "DwObjectType", "clusapi.NOTIFY_FILTER_AND_TYPE_RPC.dwObjectType", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_RESOURCE_ENUM_ENTRY_Id,
{ "Id", "clusapi.RESOURCE_ENUM_ENTRY.Id", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_RESOURCE_ENUM_ENTRY_Name,
{ "Name", "clusapi.RESOURCE_ENUM_ENTRY.Name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_RESOURCE_ENUM_ENTRY_OwnerId,
{ "OwnerId", "clusapi.RESOURCE_ENUM_ENTRY.OwnerId", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_RESOURCE_ENUM_ENTRY_OwnerName,
{ "OwnerName", "clusapi.RESOURCE_ENUM_ENTRY.OwnerName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_RESOURCE_ENUM_ENTRY_Properties,
{ "Properties", "clusapi.RESOURCE_ENUM_ENTRY.Properties", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_RESOURCE_ENUM_ENTRY_RoProperties,
{ "RoProperties", "clusapi.RESOURCE_ENUM_ENTRY.RoProperties", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_RESOURCE_ENUM_ENTRY_cbProperties,
{ "CbProperties", "clusapi.RESOURCE_ENUM_ENTRY.cbProperties", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_RESOURCE_ENUM_ENTRY_cbRoProperties,
{ "CbRoProperties", "clusapi.RESOURCE_ENUM_ENTRY.cbRoProperties", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_RESOURCE_ENUM_LIST_Entry,
{ "Entry", "clusapi.RESOURCE_ENUM_LIST.Entry", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_RESOURCE_ENUM_LIST_EntryCount,
{ "EntryCount", "clusapi.RESOURCE_ENUM_LIST.EntryCount", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_RPC_SECURITY_ATTRIBUTES_RpcSecurityDescriptor,
{ "RpcSecurityDescriptor", "clusapi.RPC_SECURITY_ATTRIBUTES.RpcSecurityDescriptor", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_RPC_SECURITY_ATTRIBUTES_bInheritHandle,
{ "BInheritHandle", "clusapi.RPC_SECURITY_ATTRIBUTES.bInheritHandle", FT_INT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_RPC_SECURITY_ATTRIBUTES_nLength,
{ "NLength", "clusapi.RPC_SECURITY_ATTRIBUTES.nLength", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_RPC_SECURITY_DESCRIPTOR_cbInSecurityDescriptor,
{ "CbInSecurityDescriptor", "clusapi.RPC_SECURITY_DESCRIPTOR.cbInSecurityDescriptor", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_RPC_SECURITY_DESCRIPTOR_cbOutSecurityDescriptor,
{ "CbOutSecurityDescriptor", "clusapi.RPC_SECURITY_DESCRIPTOR.cbOutSecurityDescriptor", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_RPC_SECURITY_DESCRIPTOR_lpSecurityDescriptor,
{ "LpSecurityDescriptor", "clusapi.RPC_SECURITY_DESCRIPTOR.lpSecurityDescriptor", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyCluster_dwFilter,
{ "DwFilter", "clusapi.clusapi_AddNotifyCluster.dwFilter", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyCluster_dwNotifyKey,
{ "DwNotifyKey", "clusapi.clusapi_AddNotifyCluster.dwNotifyKey", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyCluster_hCluster,
{ "HCluster", "clusapi.clusapi_AddNotifyCluster.hCluster", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyCluster_hNotify,
{ "HNotify", "clusapi.clusapi_AddNotifyCluster.hNotify", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyCluster_rpc_status,
{ "Rpc Status", "clusapi.clusapi_AddNotifyCluster.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyGroup_dwFilter,
{ "DwFilter", "clusapi.clusapi_AddNotifyGroup.dwFilter", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyGroup_dwNotifyKey,
{ "DwNotifyKey", "clusapi.clusapi_AddNotifyGroup.dwNotifyKey", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyGroup_dwStateSequence,
{ "DwStateSequence", "clusapi.clusapi_AddNotifyGroup.dwStateSequence", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyGroup_hGroup,
{ "HGroup", "clusapi.clusapi_AddNotifyGroup.hGroup", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyGroup_hNotify,
{ "HNotify", "clusapi.clusapi_AddNotifyGroup.hNotify", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyGroup_rpc_status,
{ "Rpc Status", "clusapi.clusapi_AddNotifyGroup.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyKey_Filter,
{ "Filter", "clusapi.clusapi_AddNotifyKey.Filter", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyKey_WatchSubTree,
{ "WatchSubTree", "clusapi.clusapi_AddNotifyKey.WatchSubTree", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyKey_dwNotifyKey,
{ "DwNotifyKey", "clusapi.clusapi_AddNotifyKey.dwNotifyKey", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyKey_hKey,
{ "HKey", "clusapi.clusapi_AddNotifyKey.hKey", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyKey_hNotify,
{ "HNotify", "clusapi.clusapi_AddNotifyKey.hNotify", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyKey_rpc_status,
{ "Rpc Status", "clusapi.clusapi_AddNotifyKey.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyNetInterface_dwFilter,
{ "DwFilter", "clusapi.clusapi_AddNotifyNetInterface.dwFilter", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyNetInterface_dwNotifyKey,
{ "DwNotifyKey", "clusapi.clusapi_AddNotifyNetInterface.dwNotifyKey", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyNetInterface_dwStateSequence,
{ "DwStateSequence", "clusapi.clusapi_AddNotifyNetInterface.dwStateSequence", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyNetInterface_hNetInterface,
{ "HNetInterface", "clusapi.clusapi_AddNotifyNetInterface.hNetInterface", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyNetInterface_hNotify,
{ "HNotify", "clusapi.clusapi_AddNotifyNetInterface.hNotify", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyNetInterface_rpc_status,
{ "Rpc Status", "clusapi.clusapi_AddNotifyNetInterface.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyNetwork_dwFilter,
{ "DwFilter", "clusapi.clusapi_AddNotifyNetwork.dwFilter", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyNetwork_dwNotifyKey,
{ "DwNotifyKey", "clusapi.clusapi_AddNotifyNetwork.dwNotifyKey", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyNetwork_dwStateSequence,
{ "DwStateSequence", "clusapi.clusapi_AddNotifyNetwork.dwStateSequence", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyNetwork_hNetwork,
{ "HNetwork", "clusapi.clusapi_AddNotifyNetwork.hNetwork", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyNetwork_hNotify,
{ "HNotify", "clusapi.clusapi_AddNotifyNetwork.hNotify", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyNetwork_rpc_status,
{ "Rpc Status", "clusapi.clusapi_AddNotifyNetwork.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyNode_dwFilter,
{ "DwFilter", "clusapi.clusapi_AddNotifyNode.dwFilter", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyNode_dwNotifyKey,
{ "DwNotifyKey", "clusapi.clusapi_AddNotifyNode.dwNotifyKey", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyNode_dwStateSequence,
{ "DwStateSequence", "clusapi.clusapi_AddNotifyNode.dwStateSequence", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyNode_hNode,
{ "HNode", "clusapi.clusapi_AddNotifyNode.hNode", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyNode_hNotify,
{ "HNotify", "clusapi.clusapi_AddNotifyNode.hNotify", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyNode_rpc_status,
{ "Rpc Status", "clusapi.clusapi_AddNotifyNode.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyResource_dwFilter,
{ "DwFilter", "clusapi.clusapi_AddNotifyResource.dwFilter", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyResource_dwNotifyKey,
{ "DwNotifyKey", "clusapi.clusapi_AddNotifyResource.dwNotifyKey", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyResource_dwStateSequence,
{ "DwStateSequence", "clusapi.clusapi_AddNotifyResource.dwStateSequence", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyResource_hNotify,
{ "HNotify", "clusapi.clusapi_AddNotifyResource.hNotify", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyResource_hResource,
{ "HResource", "clusapi.clusapi_AddNotifyResource.hResource", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyResource_rpc_status,
{ "Rpc Status", "clusapi.clusapi_AddNotifyResource.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyV2_dwNotifyKey,
{ "DwNotifyKey", "clusapi.clusapi_AddNotifyV2.dwNotifyKey", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyV2_dwVersion,
{ "DwVersion", "clusapi.clusapi_AddNotifyV2.dwVersion", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyV2_filter,
{ "Filter", "clusapi.clusapi_AddNotifyV2.filter", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyV2_hNotify,
{ "HNotify", "clusapi.clusapi_AddNotifyV2.hNotify", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyV2_hObject,
{ "HObject", "clusapi.clusapi_AddNotifyV2.hObject", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyV2_isTargetedAtObject,
{ "IsTargetedAtObject", "clusapi.clusapi_AddNotifyV2.isTargetedAtObject", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddNotifyV2_rpc_status,
{ "Rpc Status", "clusapi.clusapi_AddNotifyV2.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddResourceDependency_hDependsOn,
{ "HDependsOn", "clusapi.clusapi_AddResourceDependency.hDependsOn", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddResourceDependency_hResource,
{ "HResource", "clusapi.clusapi_AddResourceDependency.hResource", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddResourceDependency_rpc_status,
{ "Rpc Status", "clusapi.clusapi_AddResourceDependency.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddResourceNode_hNode,
{ "HNode", "clusapi.clusapi_AddResourceNode.hNode", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddResourceNode_hResource,
{ "HResource", "clusapi.clusapi_AddResourceNode.hResource", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_AddResourceNode_rpc_status,
{ "Rpc Status", "clusapi.clusapi_AddResourceNode.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_BackupClusterDatabase_lpszPathName,
{ "LpszPathName", "clusapi.clusapi_BackupClusterDatabase.lpszPathName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_BackupClusterDatabase_rpc_status,
{ "Rpc Status", "clusapi.clusapi_BackupClusterDatabase.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CanResourceBeDependent_hResource,
{ "HResource", "clusapi.clusapi_CanResourceBeDependent.hResource", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CanResourceBeDependent_hResourceDependent,
{ "HResourceDependent", "clusapi.clusapi_CanResourceBeDependent.hResourceDependent", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CanResourceBeDependent_rpc_status,
{ "Rpc Status", "clusapi.clusapi_CanResourceBeDependent.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CancelClusterGroupOperation_dwCancelFlags,
{ "DwCancelFlags", "clusapi.clusapi_CancelClusterGroupOperation.dwCancelFlags", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CancelClusterGroupOperation_hGroup,
{ "HGroup", "clusapi.clusapi_CancelClusterGroupOperation.hGroup", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CancelClusterGroupOperation_rpc_status,
{ "Rpc Status", "clusapi.clusapi_CancelClusterGroupOperation.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ChangeCsvState_dwState,
{ "DwState", "clusapi.clusapi_ChangeCsvState.dwState", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ChangeCsvState_hResource,
{ "HResource", "clusapi.clusapi_ChangeCsvState.hResource", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ChangeCsvState_rpc_status,
{ "Rpc Status", "clusapi.clusapi_ChangeCsvState.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ChangeResourceGroup_hGroup,
{ "HGroup", "clusapi.clusapi_ChangeResourceGroup.hGroup", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ChangeResourceGroup_hResource,
{ "HResource", "clusapi.clusapi_ChangeResourceGroup.hResource", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ChangeResourceGroup_rpc_status,
{ "Rpc Status", "clusapi.clusapi_ChangeResourceGroup.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CloseBatchPort_phBatchPort,
{ "PhBatchPort", "clusapi.clusapi_CloseBatchPort.phBatchPort", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CloseCluster_Cluster,
{ "Cluster", "clusapi.clusapi_CloseCluster.Cluster", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CloseGroup_Group,
{ "Group", "clusapi.clusapi_CloseGroup.Group", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CloseKey_pKey,
{ "PKey", "clusapi.clusapi_CloseKey.pKey", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CloseNetInterface_NetInterface,
{ "NetInterface", "clusapi.clusapi_CloseNetInterface.NetInterface", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CloseNetwork_Network,
{ "Network", "clusapi.clusapi_CloseNetwork.Network", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CloseNode_Node,
{ "Node", "clusapi.clusapi_CloseNode.Node", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CloseNotify_Notify,
{ "Notify", "clusapi.clusapi_CloseNotify.Notify", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CloseResource_Resource,
{ "Resource", "clusapi.clusapi_CloseResource.Resource", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ClusterControl_dwControlCode,
{ "DwControlCode", "clusapi.clusapi_ClusterControl.dwControlCode", FT_UINT32, BASE_DEC, VALS(clusapi_clusapi_ClusterControlCode_vals), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ClusterControl_hCluster,
{ "HCluster", "clusapi.clusapi_ClusterControl.hCluster", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ClusterControl_lpBytesReturned,
{ "LpBytesReturned", "clusapi.clusapi_ClusterControl.lpBytesReturned", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ClusterControl_lpInBuffer,
{ "LpInBuffer", "clusapi.clusapi_ClusterControl.lpInBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ClusterControl_lpOutBuffer,
{ "LpOutBuffer", "clusapi.clusapi_ClusterControl.lpOutBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ClusterControl_lpcbRequired,
{ "LpcbRequired", "clusapi.clusapi_ClusterControl.lpcbRequired", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ClusterControl_nInBufferSize,
{ "NInBufferSize", "clusapi.clusapi_ClusterControl.nInBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ClusterControl_nOutBufferSize,
{ "NOutBufferSize", "clusapi.clusapi_ClusterControl.nOutBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ClusterControl_rpc_status,
{ "Rpc Status", "clusapi.clusapi_ClusterControl.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ClusterMrr_dwComponent,
{ "DwComponent", "clusapi.clusapi_ClusterMrr.dwComponent", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ClusterMrr_dwControlCode,
{ "DwControlCode", "clusapi.clusapi_ClusterMrr.dwControlCode", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ClusterMrr_dwTimeout,
{ "DwTimeout", "clusapi.clusapi_ClusterMrr.dwTimeout", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ClusterMrr_fExcludeSelf,
{ "FExcludeSelf", "clusapi.clusapi_ClusterMrr.fExcludeSelf", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ClusterMrr_hCluster,
{ "HCluster", "clusapi.clusapi_ClusterMrr.hCluster", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ClusterMrr_inSize,
{ "InSize", "clusapi.clusapi_ClusterMrr.inSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ClusterMrr_nodeSet,
{ "NodeSet", "clusapi.clusapi_ClusterMrr.nodeSet", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ClusterMrr_pInData,
{ "PInData", "clusapi.clusapi_ClusterMrr.pInData", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ClusterMrr_ppInfo,
{ "PpInfo", "clusapi.clusapi_ClusterMrr.ppInfo", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ClusterMrr_rpc_status,
{ "Rpc Status", "clusapi.clusapi_ClusterMrr.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateBatchPort_hKey,
{ "HKey", "clusapi.clusapi_CreateBatchPort.hKey", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateBatchPort_phBatchPort,
{ "PhBatchPort", "clusapi.clusapi_CreateBatchPort.phBatchPort", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateBatchPort_rpc_status,
{ "Rpc Status", "clusapi.clusapi_CreateBatchPort.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateEnumEx_ReturnIdEnum,
{ "ReturnIdEnum", "clusapi.clusapi_CreateEnumEx.ReturnIdEnum", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateEnumEx_ReturnNameEnum,
{ "ReturnNameEnum", "clusapi.clusapi_CreateEnumEx.ReturnNameEnum", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateEnumEx_dwOptions,
{ "DwOptions", "clusapi.clusapi_CreateEnumEx.dwOptions", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateEnumEx_dwType,
{ "DwType", "clusapi.clusapi_CreateEnumEx.dwType", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateEnumEx_hCluster,
{ "HCluster", "clusapi.clusapi_CreateEnumEx.hCluster", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateEnumEx_rpc_status,
{ "Rpc Status", "clusapi.clusapi_CreateEnumEx.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateEnum_ReturnEnum,
{ "ReturnEnum", "clusapi.clusapi_CreateEnum.ReturnEnum", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateEnum_dwType,
{ "DwType", "clusapi.clusapi_CreateEnum.dwType", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateEnum_rpc_status,
{ "Rpc Status", "clusapi.clusapi_CreateEnum.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateGroupEnum_cbProperties,
{ "CbProperties", "clusapi.clusapi_CreateGroupEnum.cbProperties", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateGroupEnum_cbRoProperties,
{ "CbRoProperties", "clusapi.clusapi_CreateGroupEnum.cbRoProperties", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateGroupEnum_hCluster,
{ "HCluster", "clusapi.clusapi_CreateGroupEnum.hCluster", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateGroupEnum_pProperties,
{ "PProperties", "clusapi.clusapi_CreateGroupEnum.pProperties", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateGroupEnum_pRoProperties,
{ "PRoProperties", "clusapi.clusapi_CreateGroupEnum.pRoProperties", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateGroupEnum_ppResultList,
{ "PpResultList", "clusapi.clusapi_CreateGroupEnum.ppResultList", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateGroupEnum_rpc_status,
{ "Rpc Status", "clusapi.clusapi_CreateGroupEnum.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateGroupEx_Status,
{ "Status", "clusapi.clusapi_CreateGroupEx.Status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateGroupEx_hGroup,
{ "HGroup", "clusapi.clusapi_CreateGroupEx.hGroup", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateGroupEx_lpszGroupName,
{ "LpszGroupName", "clusapi.clusapi_CreateGroupEx.lpszGroupName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateGroupEx_pGroupInfo,
{ "PGroupInfo", "clusapi.clusapi_CreateGroupEx.pGroupInfo", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateGroupEx_rpc_status,
{ "Rpc Status", "clusapi.clusapi_CreateGroupEx.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateGroupResourceEnum_ReturnEnum,
{ "ReturnEnum", "clusapi.clusapi_CreateGroupResourceEnum.ReturnEnum", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateGroupResourceEnum_dwType,
{ "DwType", "clusapi.clusapi_CreateGroupResourceEnum.dwType", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateGroupResourceEnum_hGroup,
{ "HGroup", "clusapi.clusapi_CreateGroupResourceEnum.hGroup", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateGroupResourceEnum_rpc_status,
{ "Rpc Status", "clusapi.clusapi_CreateGroupResourceEnum.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateGroup_Status,
{ "Status", "clusapi.clusapi_CreateGroup.Status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateGroup_hGroup,
{ "HGroup", "clusapi.clusapi_CreateGroup.hGroup", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateGroup_lpszGroupName,
{ "LpszGroupName", "clusapi.clusapi_CreateGroup.lpszGroupName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateGroup_rpc_status,
{ "Rpc Status", "clusapi.clusapi_CreateGroup.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateKey_Status,
{ "Status", "clusapi.clusapi_CreateKey.Status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateKey_dwOptions,
{ "DwOptions", "clusapi.clusapi_CreateKey.dwOptions", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateKey_hKey,
{ "HKey", "clusapi.clusapi_CreateKey.hKey", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateKey_lpSecurityAttributes,
{ "LpSecurityAttributes", "clusapi.clusapi_CreateKey.lpSecurityAttributes", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateKey_lpSubKey,
{ "LpSubKey", "clusapi.clusapi_CreateKey.lpSubKey", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateKey_lpdwDisposition,
{ "LpdwDisposition", "clusapi.clusapi_CreateKey.lpdwDisposition", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateKey_phKey,
{ "PhKey", "clusapi.clusapi_CreateKey.phKey", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateKey_rpc_status,
{ "Rpc Status", "clusapi.clusapi_CreateKey.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateKey_samDesired,
{ "SamDesired", "clusapi.clusapi_CreateKey.samDesired", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateNetworkEnum_ReturnEnum,
{ "ReturnEnum", "clusapi.clusapi_CreateNetworkEnum.ReturnEnum", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateNetworkEnum_dwType,
{ "DwType", "clusapi.clusapi_CreateNetworkEnum.dwType", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateNetworkEnum_hNetwork,
{ "HNetwork", "clusapi.clusapi_CreateNetworkEnum.hNetwork", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateNetworkEnum_rpc_status,
{ "Rpc Status", "clusapi.clusapi_CreateNetworkEnum.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateNodeEnumEx_ReturnIdEnum,
{ "ReturnIdEnum", "clusapi.clusapi_CreateNodeEnumEx.ReturnIdEnum", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateNodeEnumEx_ReturnNameEnum,
{ "ReturnNameEnum", "clusapi.clusapi_CreateNodeEnumEx.ReturnNameEnum", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateNodeEnumEx_dwOptions,
{ "DwOptions", "clusapi.clusapi_CreateNodeEnumEx.dwOptions", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateNodeEnumEx_dwType,
{ "DwType", "clusapi.clusapi_CreateNodeEnumEx.dwType", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateNodeEnumEx_hNode,
{ "HNode", "clusapi.clusapi_CreateNodeEnumEx.hNode", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateNodeEnumEx_rpc_status,
{ "Rpc Status", "clusapi.clusapi_CreateNodeEnumEx.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateNodeEnum_ReturnEnum,
{ "ReturnEnum", "clusapi.clusapi_CreateNodeEnum.ReturnEnum", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateNodeEnum_dwType,
{ "DwType", "clusapi.clusapi_CreateNodeEnum.dwType", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateNodeEnum_hNode,
{ "HNode", "clusapi.clusapi_CreateNodeEnum.hNode", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateNodeEnum_rpc_status,
{ "Rpc Status", "clusapi.clusapi_CreateNodeEnum.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateNotifyV2_hNotify,
{ "HNotify", "clusapi.clusapi_CreateNotifyV2.hNotify", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateNotifyV2_rpc_error,
{ "Rpc Error", "clusapi.clusapi_CreateNotifyV2.rpc_error", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateNotifyV2_rpc_status,
{ "Rpc Status", "clusapi.clusapi_CreateNotifyV2.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateNotify_Status,
{ "Status", "clusapi.clusapi_CreateNotify.Status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateNotify_hNotify,
{ "HNotify", "clusapi.clusapi_CreateNotify.hNotify", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateNotify_rpc_status,
{ "Rpc Status", "clusapi.clusapi_CreateNotify.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateResEnum_ReturnEnum,
{ "ReturnEnum", "clusapi.clusapi_CreateResEnum.ReturnEnum", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateResEnum_dwType,
{ "DwType", "clusapi.clusapi_CreateResEnum.dwType", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateResEnum_hResource,
{ "HResource", "clusapi.clusapi_CreateResEnum.hResource", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateResEnum_rpc_status,
{ "Rpc Status", "clusapi.clusapi_CreateResEnum.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateResTypeEnum_ReturnEnum,
{ "ReturnEnum", "clusapi.clusapi_CreateResTypeEnum.ReturnEnum", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateResTypeEnum_dwType,
{ "DwType", "clusapi.clusapi_CreateResTypeEnum.dwType", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateResTypeEnum_lpszTypeName,
{ "LpszTypeName", "clusapi.clusapi_CreateResTypeEnum.lpszTypeName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateResTypeEnum_rpc_status,
{ "Rpc Status", "clusapi.clusapi_CreateResTypeEnum.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateResourceEnum_cbProperties,
{ "CbProperties", "clusapi.clusapi_CreateResourceEnum.cbProperties", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateResourceEnum_cbRoProperties,
{ "CbRoProperties", "clusapi.clusapi_CreateResourceEnum.cbRoProperties", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateResourceEnum_hCluster,
{ "HCluster", "clusapi.clusapi_CreateResourceEnum.hCluster", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateResourceEnum_pProperties,
{ "PProperties", "clusapi.clusapi_CreateResourceEnum.pProperties", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateResourceEnum_pRoProperties,
{ "PRoProperties", "clusapi.clusapi_CreateResourceEnum.pRoProperties", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateResourceEnum_ppResultList,
{ "PpResultList", "clusapi.clusapi_CreateResourceEnum.ppResultList", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateResourceEnum_rpc_status,
{ "Rpc Status", "clusapi.clusapi_CreateResourceEnum.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateResourceType_dwIsAlive,
{ "DwIsAlive", "clusapi.clusapi_CreateResourceType.dwIsAlive", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateResourceType_dwLooksAlive,
{ "DwLooksAlive", "clusapi.clusapi_CreateResourceType.dwLooksAlive", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateResourceType_lpszDisplayName,
{ "LpszDisplayName", "clusapi.clusapi_CreateResourceType.lpszDisplayName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateResourceType_lpszDllName,
{ "LpszDllName", "clusapi.clusapi_CreateResourceType.lpszDllName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateResourceType_lpszTypeName,
{ "LpszTypeName", "clusapi.clusapi_CreateResourceType.lpszTypeName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateResourceType_rpc_status,
{ "Rpc Status", "clusapi.clusapi_CreateResourceType.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateResource_Status,
{ "Status", "clusapi.clusapi_CreateResource.Status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateResource_dwFlags,
{ "DwFlags", "clusapi.clusapi_CreateResource.dwFlags", FT_UINT32, BASE_DEC, VALS(clusapi_clusapi_CreateResourceFlags_vals), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateResource_hGroup,
{ "HGroup", "clusapi.clusapi_CreateResource.hGroup", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateResource_hResource,
{ "HResource", "clusapi.clusapi_CreateResource.hResource", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateResource_lpszResourceName,
{ "LpszResourceName", "clusapi.clusapi_CreateResource.lpszResourceName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateResource_lpszResourceType,
{ "LpszResourceType", "clusapi.clusapi_CreateResource.lpszResourceType", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_CreateResource_rpc_status,
{ "Rpc Status", "clusapi.clusapi_CreateResource.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_DeleteGroup_Group,
{ "Group", "clusapi.clusapi_DeleteGroup.Group", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_DeleteGroup_force,
{ "Force", "clusapi.clusapi_DeleteGroup.force", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_DeleteGroup_rpc_status,
{ "Rpc Status", "clusapi.clusapi_DeleteGroup.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_DeleteKey_hKey,
{ "HKey", "clusapi.clusapi_DeleteKey.hKey", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_DeleteKey_lpSubKey,
{ "LpSubKey", "clusapi.clusapi_DeleteKey.lpSubKey", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_DeleteKey_rpc_status,
{ "Rpc Status", "clusapi.clusapi_DeleteKey.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_DeleteResourceType_lpszTypeName,
{ "LpszTypeName", "clusapi.clusapi_DeleteResourceType.lpszTypeName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_DeleteResourceType_rpc_status,
{ "Rpc Status", "clusapi.clusapi_DeleteResourceType.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_DeleteResource_hResource,
{ "HResource", "clusapi.clusapi_DeleteResource.hResource", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_DeleteResource_rpc_status,
{ "Rpc Status", "clusapi.clusapi_DeleteResource.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_DeleteValue_hKey,
{ "HKey", "clusapi.clusapi_DeleteValue.hKey", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_DeleteValue_lpValueName,
{ "LpValueName", "clusapi.clusapi_DeleteValue.lpValueName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_DeleteValue_rpc_status,
{ "Rpc Status", "clusapi.clusapi_DeleteValue.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_DesiredAccessMask_CLUSAPI_CHANGE_ACCESS,
{ "CLUSAPI CHANGE ACCESS", "clusapi.clusapi_DesiredAccessMask.CLUSAPI_CHANGE_ACCESS", FT_BOOLEAN, 32, TFS(&clusapi_DesiredAccessMask_CLUSAPI_CHANGE_ACCESS_tfs), ( 0x00000002 ), NULL, HFILL }},
{ &hf_clusapi_clusapi_DesiredAccessMask_CLUSAPI_GENERIC_ALL,
{ "CLUSAPI GENERIC ALL", "clusapi.clusapi_DesiredAccessMask.CLUSAPI_GENERIC_ALL", FT_BOOLEAN, 32, TFS(&clusapi_DesiredAccessMask_CLUSAPI_GENERIC_ALL_tfs), ( 0x10000000 ), NULL, HFILL }},
{ &hf_clusapi_clusapi_DesiredAccessMask_CLUSAPI_GENERIC_EXECUTE,
{ "CLUSAPI GENERIC EXECUTE", "clusapi.clusapi_DesiredAccessMask.CLUSAPI_GENERIC_EXECUTE", FT_BOOLEAN, 32, TFS(&clusapi_DesiredAccessMask_CLUSAPI_GENERIC_EXECUTE_tfs), ( 0x20000000 ), NULL, HFILL }},
{ &hf_clusapi_clusapi_DesiredAccessMask_CLUSAPI_GENERIC_READ,
{ "CLUSAPI GENERIC READ", "clusapi.clusapi_DesiredAccessMask.CLUSAPI_GENERIC_READ", FT_BOOLEAN, 32, TFS(&clusapi_DesiredAccessMask_CLUSAPI_GENERIC_READ_tfs), ( 0x80000000 ), NULL, HFILL }},
{ &hf_clusapi_clusapi_DesiredAccessMask_CLUSAPI_GENERIC_WRITE,
{ "CLUSAPI GENERIC WRITE", "clusapi.clusapi_DesiredAccessMask.CLUSAPI_GENERIC_WRITE", FT_BOOLEAN, 32, TFS(&clusapi_DesiredAccessMask_CLUSAPI_GENERIC_WRITE_tfs), ( 0x40000000 ), NULL, HFILL }},
{ &hf_clusapi_clusapi_DesiredAccessMask_CLUSAPI_MAXIMUM_ALLOWED,
{ "CLUSAPI MAXIMUM ALLOWED", "clusapi.clusapi_DesiredAccessMask.CLUSAPI_MAXIMUM_ALLOWED", FT_BOOLEAN, 32, TFS(&clusapi_DesiredAccessMask_CLUSAPI_MAXIMUM_ALLOWED_tfs), ( 0x02000000 ), NULL, HFILL }},
{ &hf_clusapi_clusapi_DesiredAccessMask_CLUSAPI_READ_ACCESS,
{ "CLUSAPI READ ACCESS", "clusapi.clusapi_DesiredAccessMask.CLUSAPI_READ_ACCESS", FT_BOOLEAN, 32, TFS(&clusapi_DesiredAccessMask_CLUSAPI_READ_ACCESS_tfs), ( 0x00000001 ), NULL, HFILL }},
{ &hf_clusapi_clusapi_EnumKey_KeyName,
{ "KeyName", "clusapi.clusapi_EnumKey.KeyName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_EnumKey_dwIndex,
{ "DwIndex", "clusapi.clusapi_EnumKey.dwIndex", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_EnumKey_hKey,
{ "HKey", "clusapi.clusapi_EnumKey.hKey", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_EnumKey_lpftLastWriteTime,
{ "LpftLastWriteTime", "clusapi.clusapi_EnumKey.lpftLastWriteTime", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_EnumKey_rpc_status,
{ "Rpc Status", "clusapi.clusapi_EnumKey.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_EnumValue_TotalSize,
{ "TotalSize", "clusapi.clusapi_EnumValue.TotalSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_EnumValue_dwIndex,
{ "DwIndex", "clusapi.clusapi_EnumValue.dwIndex", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_EnumValue_hKey,
{ "HKey", "clusapi.clusapi_EnumValue.hKey", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_EnumValue_lpData,
{ "LpData", "clusapi.clusapi_EnumValue.lpData", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_EnumValue_lpType,
{ "LpType", "clusapi.clusapi_EnumValue.lpType", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_EnumValue_lpValueName,
{ "LpValueName", "clusapi.clusapi_EnumValue.lpValueName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_EnumValue_lpcbData,
{ "LpcbData", "clusapi.clusapi_EnumValue.lpcbData", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_EnumValue_rpc_status,
{ "Rpc Status", "clusapi.clusapi_EnumValue.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_EvictNode_hNode,
{ "HNode", "clusapi.clusapi_EvictNode.hNode", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_EvictNode_rpc_status,
{ "Rpc Status", "clusapi.clusapi_EvictNode.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ExecuteBatch_cbData,
{ "CbData", "clusapi.clusapi_ExecuteBatch.cbData", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ExecuteBatch_hKey,
{ "HKey", "clusapi.clusapi_ExecuteBatch.hKey", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ExecuteBatch_lpData,
{ "LpData", "clusapi.clusapi_ExecuteBatch.lpData", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ExecuteBatch_pdwFailedCommand,
{ "PdwFailedCommand", "clusapi.clusapi_ExecuteBatch.pdwFailedCommand", FT_INT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ExecuteBatch_rpc_status,
{ "Rpc Status", "clusapi.clusapi_ExecuteBatch.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ExecuteReadBatch_cbInData,
{ "CbInData", "clusapi.clusapi_ExecuteReadBatch.cbInData", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ExecuteReadBatch_cbOutData,
{ "CbOutData", "clusapi.clusapi_ExecuteReadBatch.cbOutData", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ExecuteReadBatch_hKey,
{ "HKey", "clusapi.clusapi_ExecuteReadBatch.hKey", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ExecuteReadBatch_lpInData,
{ "LpInData", "clusapi.clusapi_ExecuteReadBatch.lpInData", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ExecuteReadBatch_lpOutData,
{ "LpOutData", "clusapi.clusapi_ExecuteReadBatch.lpOutData", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ExecuteReadBatch_rpc_status,
{ "Rpc Status", "clusapi.clusapi_ExecuteReadBatch.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_FailResource_hResource,
{ "HResource", "clusapi.clusapi_FailResource.hResource", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_FailResource_rpc_status,
{ "Rpc Status", "clusapi.clusapi_FailResource.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetBatchNotification_cbData,
{ "CbData", "clusapi.clusapi_GetBatchNotification.cbData", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetBatchNotification_hBatchNotify,
{ "HBatchNotify", "clusapi.clusapi_GetBatchNotification.hBatchNotify", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetBatchNotification_lpData,
{ "LpData", "clusapi.clusapi_GetBatchNotification.lpData", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetClusterName_ClusterName,
{ "ClusterName", "clusapi.clusapi_GetClusterName.ClusterName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetClusterName_NodeName,
{ "NodeName", "clusapi.clusapi_GetClusterName.NodeName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetClusterVersion2_lpszCSDVersion,
{ "LpszCSDVersion", "clusapi.clusapi_GetClusterVersion2.lpszCSDVersion", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetClusterVersion2_lpszVendorId,
{ "LpszVendorId", "clusapi.clusapi_GetClusterVersion2.lpszVendorId", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetClusterVersion2_lpwBuildNumber,
{ "LpwBuildNumber", "clusapi.clusapi_GetClusterVersion2.lpwBuildNumber", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetClusterVersion2_lpwMajorVersion,
{ "LpwMajorVersion", "clusapi.clusapi_GetClusterVersion2.lpwMajorVersion", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetClusterVersion2_lpwMinorVersion,
{ "LpwMinorVersion", "clusapi.clusapi_GetClusterVersion2.lpwMinorVersion", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetClusterVersion2_ppClusterOpVerInfo,
{ "PpClusterOpVerInfo", "clusapi.clusapi_GetClusterVersion2.ppClusterOpVerInfo", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetClusterVersion2_rpc_status,
{ "Rpc Status", "clusapi.clusapi_GetClusterVersion2.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetClusterVersion_lpszCSDVersion,
{ "LpszCSDVersion", "clusapi.clusapi_GetClusterVersion.lpszCSDVersion", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetClusterVersion_lpszVendorId,
{ "LpszVendorId", "clusapi.clusapi_GetClusterVersion.lpszVendorId", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetClusterVersion_lpwBuildNumber,
{ "LpwBuildNumber", "clusapi.clusapi_GetClusterVersion.lpwBuildNumber", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetClusterVersion_lpwMajorVersion,
{ "LpwMajorVersion", "clusapi.clusapi_GetClusterVersion.lpwMajorVersion", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetClusterVersion_lpwMinorVersion,
{ "LpwMinorVersion", "clusapi.clusapi_GetClusterVersion.lpwMinorVersion", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetGroupId_hGroup,
{ "HGroup", "clusapi.clusapi_GetGroupId.hGroup", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetGroupId_pGuid,
{ "PGuid", "clusapi.clusapi_GetGroupId.pGuid", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetGroupId_rpc_status,
{ "Rpc Status", "clusapi.clusapi_GetGroupId.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetGroupState_NodeName,
{ "NodeName", "clusapi.clusapi_GetGroupState.NodeName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetGroupState_State,
{ "State", "clusapi.clusapi_GetGroupState.State", FT_UINT32, BASE_DEC, VALS(clusapi_clusapi_ClusterGroupState_vals), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetGroupState_hGroup,
{ "HGroup", "clusapi.clusapi_GetGroupState.hGroup", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetGroupState_rpc_status,
{ "Rpc Status", "clusapi.clusapi_GetGroupState.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetKeySecurity_SecurityInformation,
{ "SecurityInformation", "clusapi.clusapi_GetKeySecurity.SecurityInformation", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetKeySecurity_hKey,
{ "HKey", "clusapi.clusapi_GetKeySecurity.hKey", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetKeySecurity_pRpcSecurityDescriptor,
{ "PRpcSecurityDescriptor", "clusapi.clusapi_GetKeySecurity.pRpcSecurityDescriptor", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetKeySecurity_rpc_status,
{ "Rpc Status", "clusapi.clusapi_GetKeySecurity.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNetInterfaceId_hNetInterface,
{ "HNetInterface", "clusapi.clusapi_GetNetInterfaceId.hNetInterface", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNetInterfaceId_pGuid,
{ "PGuid", "clusapi.clusapi_GetNetInterfaceId.pGuid", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNetInterfaceId_rpc_status,
{ "Rpc Status", "clusapi.clusapi_GetNetInterfaceId.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNetInterfaceState_State,
{ "State", "clusapi.clusapi_GetNetInterfaceState.State", FT_UINT32, BASE_DEC, VALS(clusapi_clusapi_ClusterNetInterfaceState_vals), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNetInterfaceState_hNetInterface,
{ "HNetInterface", "clusapi.clusapi_GetNetInterfaceState.hNetInterface", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNetInterfaceState_rpc_status,
{ "Rpc Status", "clusapi.clusapi_GetNetInterfaceState.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNetInterface_lppszInterfaceName,
{ "LppszInterfaceName", "clusapi.clusapi_GetNetInterface.lppszInterfaceName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNetInterface_lpszNetworkName,
{ "LpszNetworkName", "clusapi.clusapi_GetNetInterface.lpszNetworkName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNetInterface_lpszNodeName,
{ "LpszNodeName", "clusapi.clusapi_GetNetInterface.lpszNodeName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNetInterface_rpc_status,
{ "Rpc Status", "clusapi.clusapi_GetNetInterface.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNetworkId_hNetwork,
{ "HNetwork", "clusapi.clusapi_GetNetworkId.hNetwork", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNetworkId_pGuid,
{ "PGuid", "clusapi.clusapi_GetNetworkId.pGuid", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNetworkId_rpc_status,
{ "Rpc Status", "clusapi.clusapi_GetNetworkId.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNetworkState_State,
{ "State", "clusapi.clusapi_GetNetworkState.State", FT_UINT32, BASE_DEC, VALS(clusapi_clusapi_ClusterNetworkState_vals), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNetworkState_hNetwork,
{ "HNetwork", "clusapi.clusapi_GetNetworkState.hNetwork", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNetworkState_rpc_status,
{ "Rpc Status", "clusapi.clusapi_GetNetworkState.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNodeId_hNode,
{ "HNode", "clusapi.clusapi_GetNodeId.hNode", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNodeId_pGuid,
{ "PGuid", "clusapi.clusapi_GetNodeId.pGuid", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNodeId_rpc_status,
{ "Rpc Status", "clusapi.clusapi_GetNodeId.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNodeState_State,
{ "State", "clusapi.clusapi_GetNodeState.State", FT_UINT32, BASE_DEC, VALS(clusapi_clusapi_ClusterNodeState_vals), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNodeState_hNode,
{ "HNode", "clusapi.clusapi_GetNodeState.hNode", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNodeState_rpc_status,
{ "Rpc Status", "clusapi.clusapi_GetNodeState.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNotifyAsync_Notifications,
{ "Notifications", "clusapi.clusapi_GetNotifyAsync.Notifications", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNotifyAsync_dwNumNotifications,
{ "DwNumNotifications", "clusapi.clusapi_GetNotifyAsync.dwNumNotifications", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNotifyAsync_hNotify,
{ "HNotify", "clusapi.clusapi_GetNotifyAsync.hNotify", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNotifyV2_Notifications,
{ "Notifications", "clusapi.clusapi_GetNotifyV2.Notifications", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNotifyV2_dwNumNotifications,
{ "DwNumNotifications", "clusapi.clusapi_GetNotifyV2.dwNumNotifications", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNotifyV2_hNotify,
{ "HNotify", "clusapi.clusapi_GetNotifyV2.hNotify", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNotify_Name,
{ "Name", "clusapi.clusapi_GetNotify.Name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNotify_dwFilter,
{ "DwFilter", "clusapi.clusapi_GetNotify.dwFilter", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNotify_dwNotifyKey,
{ "DwNotifyKey", "clusapi.clusapi_GetNotify.dwNotifyKey", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNotify_dwStateSequence,
{ "DwStateSequence", "clusapi.clusapi_GetNotify.dwStateSequence", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNotify_hNotify,
{ "HNotify", "clusapi.clusapi_GetNotify.hNotify", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetNotify_rpc_status,
{ "Rpc Status", "clusapi.clusapi_GetNotify.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetQuorumResource_lpszDeviceName,
{ "LpszDeviceName", "clusapi.clusapi_GetQuorumResource.lpszDeviceName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetQuorumResource_lpszResourceName,
{ "LpszResourceName", "clusapi.clusapi_GetQuorumResource.lpszResourceName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetQuorumResource_pdwMaxQuorumLogSize,
{ "PdwMaxQuorumLogSize", "clusapi.clusapi_GetQuorumResource.pdwMaxQuorumLogSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetQuorumResource_rpc_status,
{ "Rpc Status", "clusapi.clusapi_GetQuorumResource.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetResourceDependencyExpression_hResource,
{ "HResource", "clusapi.clusapi_GetResourceDependencyExpression.hResource", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetResourceDependencyExpression_lpszDependencyExpression,
{ "LpszDependencyExpression", "clusapi.clusapi_GetResourceDependencyExpression.lpszDependencyExpression", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetResourceDependencyExpression_rpc_status,
{ "Rpc Status", "clusapi.clusapi_GetResourceDependencyExpression.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetResourceId_hResource,
{ "HResource", "clusapi.clusapi_GetResourceId.hResource", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetResourceId_pGuid,
{ "PGuid", "clusapi.clusapi_GetResourceId.pGuid", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetResourceId_rpc_status,
{ "Rpc Status", "clusapi.clusapi_GetResourceId.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetResourceNetworkName_hResource,
{ "HResource", "clusapi.clusapi_GetResourceNetworkName.hResource", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetResourceNetworkName_lpszName,
{ "LpszName", "clusapi.clusapi_GetResourceNetworkName.lpszName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetResourceNetworkName_rpc_status,
{ "Rpc Status", "clusapi.clusapi_GetResourceNetworkName.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetResourceState_GroupName,
{ "GroupName", "clusapi.clusapi_GetResourceState.GroupName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetResourceState_NodeName,
{ "NodeName", "clusapi.clusapi_GetResourceState.NodeName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetResourceState_State,
{ "State", "clusapi.clusapi_GetResourceState.State", FT_UINT32, BASE_DEC, VALS(clusapi_clusapi_ClusterResourceState_vals), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetResourceState_hResource,
{ "HResource", "clusapi.clusapi_GetResourceState.hResource", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetResourceState_rpc_status,
{ "Rpc Status", "clusapi.clusapi_GetResourceState.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetResourceType_hResource,
{ "HResource", "clusapi.clusapi_GetResourceType.hResource", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetResourceType_lpszResourceType,
{ "LpszResourceType", "clusapi.clusapi_GetResourceType.lpszResourceType", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetResourceType_rpc_status,
{ "Rpc Status", "clusapi.clusapi_GetResourceType.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetRootKey_Status,
{ "Status", "clusapi.clusapi_GetRootKey.Status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetRootKey_phKey,
{ "PhKey", "clusapi.clusapi_GetRootKey.phKey", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetRootKey_rpc_status,
{ "Rpc Status", "clusapi.clusapi_GetRootKey.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GetRootKey_samDesired,
{ "SamDesired", "clusapi.clusapi_GetRootKey.samDesired", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GroupControl_dwControlCode,
{ "DwControlCode", "clusapi.clusapi_GroupControl.dwControlCode", FT_UINT32, BASE_DEC, VALS(clusapi_clusapi_GroupControlCode_vals), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GroupControl_hGroup,
{ "HGroup", "clusapi.clusapi_GroupControl.hGroup", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GroupControl_lpBytesReturned,
{ "LpBytesReturned", "clusapi.clusapi_GroupControl.lpBytesReturned", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GroupControl_lpInBuffer,
{ "LpInBuffer", "clusapi.clusapi_GroupControl.lpInBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GroupControl_lpOutBuffer,
{ "LpOutBuffer", "clusapi.clusapi_GroupControl.lpOutBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GroupControl_lpcbRequired,
{ "LpcbRequired", "clusapi.clusapi_GroupControl.lpcbRequired", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GroupControl_nInBufferSize,
{ "NInBufferSize", "clusapi.clusapi_GroupControl.nInBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GroupControl_nOutBufferSize,
{ "NOutBufferSize", "clusapi.clusapi_GroupControl.nOutBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_GroupControl_rpc_status,
{ "Rpc Status", "clusapi.clusapi_GroupControl.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_MoveGroupEx_cbInBufferSize,
{ "CbInBufferSize", "clusapi.clusapi_MoveGroupEx.cbInBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_MoveGroupEx_dwMoveFlags,
{ "DwMoveFlags", "clusapi.clusapi_MoveGroupEx.dwMoveFlags", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_MoveGroupEx_hGroup,
{ "HGroup", "clusapi.clusapi_MoveGroupEx.hGroup", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_MoveGroupEx_lpInBuffer,
{ "LpInBuffer", "clusapi.clusapi_MoveGroupEx.lpInBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_MoveGroupEx_rpc_status,
{ "Rpc Status", "clusapi.clusapi_MoveGroupEx.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_MoveGroupToNodeEx_cbInBufferSize,
{ "CbInBufferSize", "clusapi.clusapi_MoveGroupToNodeEx.cbInBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_MoveGroupToNodeEx_dwMoveFlags,
{ "DwMoveFlags", "clusapi.clusapi_MoveGroupToNodeEx.dwMoveFlags", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_MoveGroupToNodeEx_hGroup,
{ "HGroup", "clusapi.clusapi_MoveGroupToNodeEx.hGroup", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_MoveGroupToNodeEx_hNode,
{ "HNode", "clusapi.clusapi_MoveGroupToNodeEx.hNode", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_MoveGroupToNodeEx_lpInBuffer,
{ "LpInBuffer", "clusapi.clusapi_MoveGroupToNodeEx.lpInBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_MoveGroupToNodeEx_rpc_status,
{ "Rpc Status", "clusapi.clusapi_MoveGroupToNodeEx.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_MoveGroupToNode_hGroup,
{ "HGroup", "clusapi.clusapi_MoveGroupToNode.hGroup", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_MoveGroupToNode_hNode,
{ "HNode", "clusapi.clusapi_MoveGroupToNode.hNode", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_MoveGroupToNode_rpc_status,
{ "Rpc Status", "clusapi.clusapi_MoveGroupToNode.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_MoveGroup_hGroup,
{ "HGroup", "clusapi.clusapi_MoveGroup.hGroup", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_MoveGroup_rpc_status,
{ "Rpc Status", "clusapi.clusapi_MoveGroup.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NetInterfaceControl_dwControlCode,
{ "DwControlCode", "clusapi.clusapi_NetInterfaceControl.dwControlCode", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NetInterfaceControl_hNetInterface,
{ "HNetInterface", "clusapi.clusapi_NetInterfaceControl.hNetInterface", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NetInterfaceControl_lpBytesReturned,
{ "LpBytesReturned", "clusapi.clusapi_NetInterfaceControl.lpBytesReturned", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NetInterfaceControl_lpInBuffer,
{ "LpInBuffer", "clusapi.clusapi_NetInterfaceControl.lpInBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NetInterfaceControl_lpOutBuffer,
{ "LpOutBuffer", "clusapi.clusapi_NetInterfaceControl.lpOutBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NetInterfaceControl_lpcbRequired,
{ "LpcbRequired", "clusapi.clusapi_NetInterfaceControl.lpcbRequired", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NetInterfaceControl_nInBufferSize,
{ "NInBufferSize", "clusapi.clusapi_NetInterfaceControl.nInBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NetInterfaceControl_nOutBufferSize,
{ "NOutBufferSize", "clusapi.clusapi_NetInterfaceControl.nOutBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NetInterfaceControl_rpc_status,
{ "Rpc Status", "clusapi.clusapi_NetInterfaceControl.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NetworkControl_dwControlCode,
{ "DwControlCode", "clusapi.clusapi_NetworkControl.dwControlCode", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NetworkControl_hNetwork,
{ "HNetwork", "clusapi.clusapi_NetworkControl.hNetwork", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NetworkControl_lpBytesReturned,
{ "LpBytesReturned", "clusapi.clusapi_NetworkControl.lpBytesReturned", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NetworkControl_lpInBuffer,
{ "LpInBuffer", "clusapi.clusapi_NetworkControl.lpInBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NetworkControl_lpOutBuffer,
{ "LpOutBuffer", "clusapi.clusapi_NetworkControl.lpOutBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NetworkControl_lpcbRequired,
{ "LpcbRequired", "clusapi.clusapi_NetworkControl.lpcbRequired", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NetworkControl_nInBufferSize,
{ "NInBufferSize", "clusapi.clusapi_NetworkControl.nInBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NetworkControl_nOutBufferSize,
{ "NOutBufferSize", "clusapi.clusapi_NetworkControl.nOutBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NetworkControl_rpc_status,
{ "Rpc Status", "clusapi.clusapi_NetworkControl.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeClusterControl_dwControlCode,
{ "DwControlCode", "clusapi.clusapi_NodeClusterControl.dwControlCode", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeClusterControl_hCluster,
{ "HCluster", "clusapi.clusapi_NodeClusterControl.hCluster", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeClusterControl_hHostNode,
{ "HHostNode", "clusapi.clusapi_NodeClusterControl.hHostNode", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeClusterControl_lpBytesReturned,
{ "LpBytesReturned", "clusapi.clusapi_NodeClusterControl.lpBytesReturned", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeClusterControl_lpInBuffer,
{ "LpInBuffer", "clusapi.clusapi_NodeClusterControl.lpInBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeClusterControl_lpOutBuffer,
{ "LpOutBuffer", "clusapi.clusapi_NodeClusterControl.lpOutBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeClusterControl_lpcbRequired,
{ "LpcbRequired", "clusapi.clusapi_NodeClusterControl.lpcbRequired", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeClusterControl_nInBufferSize,
{ "NInBufferSize", "clusapi.clusapi_NodeClusterControl.nInBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeClusterControl_nOutBufferSize,
{ "NOutBufferSize", "clusapi.clusapi_NodeClusterControl.nOutBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeClusterControl_rpc_status,
{ "Rpc Status", "clusapi.clusapi_NodeClusterControl.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeControl_dwControlCode,
{ "DwControlCode", "clusapi.clusapi_NodeControl.dwControlCode", FT_UINT32, BASE_DEC, VALS(clusapi_clusapi_NodeControlCode_vals), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeControl_hNode,
{ "HNode", "clusapi.clusapi_NodeControl.hNode", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeControl_lpBytesReturned,
{ "LpBytesReturned", "clusapi.clusapi_NodeControl.lpBytesReturned", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeControl_lpInBuffer,
{ "LpInBuffer", "clusapi.clusapi_NodeControl.lpInBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeControl_lpOutBuffer,
{ "LpOutBuffer", "clusapi.clusapi_NodeControl.lpOutBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeControl_lpcbRequired,
{ "LpcbRequired", "clusapi.clusapi_NodeControl.lpcbRequired", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeControl_nInBufferSize,
{ "NInBufferSize", "clusapi.clusapi_NodeControl.nInBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeControl_nOutBufferSize,
{ "NOutBufferSize", "clusapi.clusapi_NodeControl.nOutBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeControl_rpc_status,
{ "Rpc Status", "clusapi.clusapi_NodeControl.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeGroupControl_dwControlCode,
{ "DwControlCode", "clusapi.clusapi_NodeGroupControl.dwControlCode", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeGroupControl_hGroup,
{ "HGroup", "clusapi.clusapi_NodeGroupControl.hGroup", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeGroupControl_hNode,
{ "HNode", "clusapi.clusapi_NodeGroupControl.hNode", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeGroupControl_lpBytesReturned,
{ "LpBytesReturned", "clusapi.clusapi_NodeGroupControl.lpBytesReturned", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeGroupControl_lpInBuffer,
{ "LpInBuffer", "clusapi.clusapi_NodeGroupControl.lpInBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeGroupControl_lpOutBuffer,
{ "LpOutBuffer", "clusapi.clusapi_NodeGroupControl.lpOutBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeGroupControl_lpcbRequired,
{ "LpcbRequired", "clusapi.clusapi_NodeGroupControl.lpcbRequired", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeGroupControl_nInBufferSize,
{ "NInBufferSize", "clusapi.clusapi_NodeGroupControl.nInBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeGroupControl_nOutBufferSize,
{ "NOutBufferSize", "clusapi.clusapi_NodeGroupControl.nOutBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeGroupControl_rpc_status,
{ "Rpc Status", "clusapi.clusapi_NodeGroupControl.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeNetInterfaceControl_dwControlCode,
{ "DwControlCode", "clusapi.clusapi_NodeNetInterfaceControl.dwControlCode", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeNetInterfaceControl_hNetInterface,
{ "HNetInterface", "clusapi.clusapi_NodeNetInterfaceControl.hNetInterface", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeNetInterfaceControl_hNode,
{ "HNode", "clusapi.clusapi_NodeNetInterfaceControl.hNode", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeNetInterfaceControl_lpBytesReturned,
{ "LpBytesReturned", "clusapi.clusapi_NodeNetInterfaceControl.lpBytesReturned", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeNetInterfaceControl_lpInBuffer,
{ "LpInBuffer", "clusapi.clusapi_NodeNetInterfaceControl.lpInBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeNetInterfaceControl_lpOutBuffer,
{ "LpOutBuffer", "clusapi.clusapi_NodeNetInterfaceControl.lpOutBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeNetInterfaceControl_lpcbRequired,
{ "LpcbRequired", "clusapi.clusapi_NodeNetInterfaceControl.lpcbRequired", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeNetInterfaceControl_nInBufferSize,
{ "NInBufferSize", "clusapi.clusapi_NodeNetInterfaceControl.nInBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeNetInterfaceControl_nOutBufferSize,
{ "NOutBufferSize", "clusapi.clusapi_NodeNetInterfaceControl.nOutBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeNetInterfaceControl_rpc_status,
{ "Rpc Status", "clusapi.clusapi_NodeNetInterfaceControl.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeNetworkControl_dwControlCode,
{ "DwControlCode", "clusapi.clusapi_NodeNetworkControl.dwControlCode", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeNetworkControl_hNetwork,
{ "HNetwork", "clusapi.clusapi_NodeNetworkControl.hNetwork", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeNetworkControl_hNode,
{ "HNode", "clusapi.clusapi_NodeNetworkControl.hNode", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeNetworkControl_lpBytesReturned,
{ "LpBytesReturned", "clusapi.clusapi_NodeNetworkControl.lpBytesReturned", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeNetworkControl_lpInBuffer,
{ "LpInBuffer", "clusapi.clusapi_NodeNetworkControl.lpInBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeNetworkControl_lpOutBuffer,
{ "LpOutBuffer", "clusapi.clusapi_NodeNetworkControl.lpOutBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeNetworkControl_lpcbRequired,
{ "LpcbRequired", "clusapi.clusapi_NodeNetworkControl.lpcbRequired", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeNetworkControl_nInBufferSize,
{ "NInBufferSize", "clusapi.clusapi_NodeNetworkControl.nInBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeNetworkControl_nOutBufferSize,
{ "NOutBufferSize", "clusapi.clusapi_NodeNetworkControl.nOutBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeNetworkControl_rpc_status,
{ "Rpc Status", "clusapi.clusapi_NodeNetworkControl.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeNodeControl_dwControlCode,
{ "DwControlCode", "clusapi.clusapi_NodeNodeControl.dwControlCode", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeNodeControl_hHostNode,
{ "HHostNode", "clusapi.clusapi_NodeNodeControl.hHostNode", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeNodeControl_hNode,
{ "HNode", "clusapi.clusapi_NodeNodeControl.hNode", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeNodeControl_lpBytesReturned,
{ "LpBytesReturned", "clusapi.clusapi_NodeNodeControl.lpBytesReturned", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeNodeControl_lpInBuffer,
{ "LpInBuffer", "clusapi.clusapi_NodeNodeControl.lpInBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeNodeControl_lpOutBuffer,
{ "LpOutBuffer", "clusapi.clusapi_NodeNodeControl.lpOutBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeNodeControl_lpcbRequired,
{ "LpcbRequired", "clusapi.clusapi_NodeNodeControl.lpcbRequired", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeNodeControl_nInBufferSize,
{ "NInBufferSize", "clusapi.clusapi_NodeNodeControl.nInBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeNodeControl_nOutBufferSize,
{ "NOutBufferSize", "clusapi.clusapi_NodeNodeControl.nOutBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeNodeControl_rpc_status,
{ "Rpc Status", "clusapi.clusapi_NodeNodeControl.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeResourceControl_dwControlCode,
{ "DwControlCode", "clusapi.clusapi_NodeResourceControl.dwControlCode", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeResourceControl_hNode,
{ "HNode", "clusapi.clusapi_NodeResourceControl.hNode", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeResourceControl_hResource,
{ "HResource", "clusapi.clusapi_NodeResourceControl.hResource", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeResourceControl_lpBytesReturned,
{ "LpBytesReturned", "clusapi.clusapi_NodeResourceControl.lpBytesReturned", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeResourceControl_lpInBuffer,
{ "LpInBuffer", "clusapi.clusapi_NodeResourceControl.lpInBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeResourceControl_lpOutBuffer,
{ "LpOutBuffer", "clusapi.clusapi_NodeResourceControl.lpOutBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeResourceControl_lpcbRequired,
{ "LpcbRequired", "clusapi.clusapi_NodeResourceControl.lpcbRequired", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeResourceControl_nInBufferSize,
{ "NInBufferSize", "clusapi.clusapi_NodeResourceControl.nInBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeResourceControl_nOutBufferSize,
{ "NOutBufferSize", "clusapi.clusapi_NodeResourceControl.nOutBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeResourceControl_rpc_status,
{ "Rpc Status", "clusapi.clusapi_NodeResourceControl.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeResourceTypeControl_dwControlCode,
{ "DwControlCode", "clusapi.clusapi_NodeResourceTypeControl.dwControlCode", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeResourceTypeControl_hCluster,
{ "HCluster", "clusapi.clusapi_NodeResourceTypeControl.hCluster", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeResourceTypeControl_hNode,
{ "HNode", "clusapi.clusapi_NodeResourceTypeControl.hNode", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeResourceTypeControl_lpBytesReturned,
{ "LpBytesReturned", "clusapi.clusapi_NodeResourceTypeControl.lpBytesReturned", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeResourceTypeControl_lpInBuffer,
{ "LpInBuffer", "clusapi.clusapi_NodeResourceTypeControl.lpInBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeResourceTypeControl_lpOutBuffer,
{ "LpOutBuffer", "clusapi.clusapi_NodeResourceTypeControl.lpOutBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeResourceTypeControl_lpcbRequired,
{ "LpcbRequired", "clusapi.clusapi_NodeResourceTypeControl.lpcbRequired", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeResourceTypeControl_lpszResourceTypeName,
{ "LpszResourceTypeName", "clusapi.clusapi_NodeResourceTypeControl.lpszResourceTypeName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeResourceTypeControl_nInBufferSize,
{ "NInBufferSize", "clusapi.clusapi_NodeResourceTypeControl.nInBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeResourceTypeControl_nOutBufferSize,
{ "NOutBufferSize", "clusapi.clusapi_NodeResourceTypeControl.nOutBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_NodeResourceTypeControl_rpc_status,
{ "Rpc Status", "clusapi.clusapi_NodeResourceTypeControl.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OfflineGroupEx_cbInBufferSize,
{ "CbInBufferSize", "clusapi.clusapi_OfflineGroupEx.cbInBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OfflineGroupEx_dwOfflineFlags,
{ "DwOfflineFlags", "clusapi.clusapi_OfflineGroupEx.dwOfflineFlags", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OfflineGroupEx_hGroup,
{ "HGroup", "clusapi.clusapi_OfflineGroupEx.hGroup", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OfflineGroupEx_lpInBuffer,
{ "LpInBuffer", "clusapi.clusapi_OfflineGroupEx.lpInBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OfflineGroupEx_rpc_status,
{ "Rpc Status", "clusapi.clusapi_OfflineGroupEx.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OfflineGroup_hGroup,
{ "HGroup", "clusapi.clusapi_OfflineGroup.hGroup", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OfflineGroup_rpc_status,
{ "Rpc Status", "clusapi.clusapi_OfflineGroup.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OfflineResourceEx_cbInBufferSize,
{ "CbInBufferSize", "clusapi.clusapi_OfflineResourceEx.cbInBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OfflineResourceEx_dwOfflineFlags,
{ "DwOfflineFlags", "clusapi.clusapi_OfflineResourceEx.dwOfflineFlags", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OfflineResourceEx_hResource,
{ "HResource", "clusapi.clusapi_OfflineResourceEx.hResource", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OfflineResourceEx_lpInBuffer,
{ "LpInBuffer", "clusapi.clusapi_OfflineResourceEx.lpInBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OfflineResourceEx_rpc_status,
{ "Rpc Status", "clusapi.clusapi_OfflineResourceEx.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OfflineResource_hResource,
{ "HResource", "clusapi.clusapi_OfflineResource.hResource", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OfflineResource_rpc_status,
{ "Rpc Status", "clusapi.clusapi_OfflineResource.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OnlineGroupEx_cbInBufferSize,
{ "CbInBufferSize", "clusapi.clusapi_OnlineGroupEx.cbInBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OnlineGroupEx_dwOnlineFlags,
{ "DwOnlineFlags", "clusapi.clusapi_OnlineGroupEx.dwOnlineFlags", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OnlineGroupEx_hGroup,
{ "HGroup", "clusapi.clusapi_OnlineGroupEx.hGroup", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OnlineGroupEx_lpInBuffer,
{ "LpInBuffer", "clusapi.clusapi_OnlineGroupEx.lpInBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OnlineGroupEx_rpc_status,
{ "Rpc Status", "clusapi.clusapi_OnlineGroupEx.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OnlineGroup_hGroup,
{ "HGroup", "clusapi.clusapi_OnlineGroup.hGroup", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OnlineGroup_rpc_status,
{ "Rpc Status", "clusapi.clusapi_OnlineGroup.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OnlineResourceEx_cbInBufferSize,
{ "CbInBufferSize", "clusapi.clusapi_OnlineResourceEx.cbInBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OnlineResourceEx_dwOnlineFlags,
{ "DwOnlineFlags", "clusapi.clusapi_OnlineResourceEx.dwOnlineFlags", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OnlineResourceEx_hResource,
{ "HResource", "clusapi.clusapi_OnlineResourceEx.hResource", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OnlineResourceEx_lpInBuffer,
{ "LpInBuffer", "clusapi.clusapi_OnlineResourceEx.lpInBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OnlineResourceEx_rpc_status,
{ "Rpc Status", "clusapi.clusapi_OnlineResourceEx.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OnlineResource_hResource,
{ "HResource", "clusapi.clusapi_OnlineResource.hResource", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OnlineResource_rpc_status,
{ "Rpc Status", "clusapi.clusapi_OnlineResource.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenClusterEx_Status,
{ "Status", "clusapi.clusapi_OpenClusterEx.Status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenClusterEx_dwDesiredAccess,
{ "DwDesiredAccess", "clusapi.clusapi_OpenClusterEx.dwDesiredAccess", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenClusterEx_hCluster,
{ "HCluster", "clusapi.clusapi_OpenClusterEx.hCluster", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenClusterEx_lpdwGrantedAccess,
{ "LpdwGrantedAccess", "clusapi.clusapi_OpenClusterEx.lpdwGrantedAccess", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenCluster_Cluster,
{ "Cluster", "clusapi.clusapi_OpenCluster.Cluster", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenCluster_Status,
{ "Status", "clusapi.clusapi_OpenCluster.Status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenGroupEx_Status,
{ "Status", "clusapi.clusapi_OpenGroupEx.Status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenGroupEx_dwDesiredAccess,
{ "DwDesiredAccess", "clusapi.clusapi_OpenGroupEx.dwDesiredAccess", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenGroupEx_hGroup,
{ "HGroup", "clusapi.clusapi_OpenGroupEx.hGroup", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenGroupEx_lpdwGrantedAccess,
{ "LpdwGrantedAccess", "clusapi.clusapi_OpenGroupEx.lpdwGrantedAccess", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenGroupEx_lpszGroupName,
{ "LpszGroupName", "clusapi.clusapi_OpenGroupEx.lpszGroupName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenGroupEx_rpc_status,
{ "Rpc Status", "clusapi.clusapi_OpenGroupEx.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenGroup_Status,
{ "Status", "clusapi.clusapi_OpenGroup.Status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenGroup_hGroup,
{ "HGroup", "clusapi.clusapi_OpenGroup.hGroup", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenGroup_lpszGroupName,
{ "LpszGroupName", "clusapi.clusapi_OpenGroup.lpszGroupName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenGroup_rpc_status,
{ "Rpc Status", "clusapi.clusapi_OpenGroup.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenKey_Status,
{ "Status", "clusapi.clusapi_OpenKey.Status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenKey_hKey,
{ "HKey", "clusapi.clusapi_OpenKey.hKey", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenKey_lpSubKey,
{ "LpSubKey", "clusapi.clusapi_OpenKey.lpSubKey", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenKey_phKey,
{ "PhKey", "clusapi.clusapi_OpenKey.phKey", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenKey_rpc_status,
{ "Rpc Status", "clusapi.clusapi_OpenKey.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenKey_samDesired,
{ "SamDesired", "clusapi.clusapi_OpenKey.samDesired", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenNetInterfaceEx_Status,
{ "Status", "clusapi.clusapi_OpenNetInterfaceEx.Status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenNetInterfaceEx_dwDesiredAccess,
{ "DwDesiredAccess", "clusapi.clusapi_OpenNetInterfaceEx.dwDesiredAccess", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenNetInterfaceEx_hNetInterface,
{ "HNetInterface", "clusapi.clusapi_OpenNetInterfaceEx.hNetInterface", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenNetInterfaceEx_lpdwGrantedAccess,
{ "LpdwGrantedAccess", "clusapi.clusapi_OpenNetInterfaceEx.lpdwGrantedAccess", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenNetInterfaceEx_lpszNetInterfaceName,
{ "LpszNetInterfaceName", "clusapi.clusapi_OpenNetInterfaceEx.lpszNetInterfaceName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenNetInterfaceEx_rpc_status,
{ "Rpc Status", "clusapi.clusapi_OpenNetInterfaceEx.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenNetInterface_Status,
{ "Status", "clusapi.clusapi_OpenNetInterface.Status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenNetInterface_hNetInterface,
{ "HNetInterface", "clusapi.clusapi_OpenNetInterface.hNetInterface", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenNetInterface_lpszNetInterfaceName,
{ "LpszNetInterfaceName", "clusapi.clusapi_OpenNetInterface.lpszNetInterfaceName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenNetInterface_rpc_status,
{ "Rpc Status", "clusapi.clusapi_OpenNetInterface.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenNetworkEx_Status,
{ "Status", "clusapi.clusapi_OpenNetworkEx.Status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenNetworkEx_dwDesiredAccess,
{ "DwDesiredAccess", "clusapi.clusapi_OpenNetworkEx.dwDesiredAccess", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenNetworkEx_hNetwork,
{ "HNetwork", "clusapi.clusapi_OpenNetworkEx.hNetwork", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenNetworkEx_lpdwGrantedAccess,
{ "LpdwGrantedAccess", "clusapi.clusapi_OpenNetworkEx.lpdwGrantedAccess", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenNetworkEx_lpszNetworkName,
{ "LpszNetworkName", "clusapi.clusapi_OpenNetworkEx.lpszNetworkName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenNetworkEx_rpc_status,
{ "Rpc Status", "clusapi.clusapi_OpenNetworkEx.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenNetwork_Status,
{ "Status", "clusapi.clusapi_OpenNetwork.Status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenNetwork_hNetwork,
{ "HNetwork", "clusapi.clusapi_OpenNetwork.hNetwork", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenNetwork_lpszNetworkName,
{ "LpszNetworkName", "clusapi.clusapi_OpenNetwork.lpszNetworkName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenNetwork_rpc_status,
{ "Rpc Status", "clusapi.clusapi_OpenNetwork.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenNodeEx_Status,
{ "Status", "clusapi.clusapi_OpenNodeEx.Status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenNodeEx_dwDesiredAccess,
{ "DwDesiredAccess", "clusapi.clusapi_OpenNodeEx.dwDesiredAccess", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenNodeEx_hNode,
{ "HNode", "clusapi.clusapi_OpenNodeEx.hNode", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenNodeEx_lpdwGrantedAccess,
{ "LpdwGrantedAccess", "clusapi.clusapi_OpenNodeEx.lpdwGrantedAccess", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenNodeEx_lpszNodeName,
{ "LpszNodeName", "clusapi.clusapi_OpenNodeEx.lpszNodeName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenNodeEx_rpc_status,
{ "Rpc Status", "clusapi.clusapi_OpenNodeEx.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenNode_Status,
{ "Status", "clusapi.clusapi_OpenNode.Status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenNode_hNode,
{ "HNode", "clusapi.clusapi_OpenNode.hNode", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenNode_lpszNodeName,
{ "LpszNodeName", "clusapi.clusapi_OpenNode.lpszNodeName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenNode_rpc_status,
{ "Rpc Status", "clusapi.clusapi_OpenNode.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenResourceEx_Status,
{ "Status", "clusapi.clusapi_OpenResourceEx.Status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenResourceEx_dwDesiredAccess,
{ "DwDesiredAccess", "clusapi.clusapi_OpenResourceEx.dwDesiredAccess", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenResourceEx_hResource,
{ "HResource", "clusapi.clusapi_OpenResourceEx.hResource", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenResourceEx_lpdwGrantedAccess,
{ "LpdwGrantedAccess", "clusapi.clusapi_OpenResourceEx.lpdwGrantedAccess", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenResourceEx_lpszResourceName,
{ "LpszResourceName", "clusapi.clusapi_OpenResourceEx.lpszResourceName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenResourceEx_rpc_status,
{ "Rpc Status", "clusapi.clusapi_OpenResourceEx.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenResource_Status,
{ "Status", "clusapi.clusapi_OpenResource.Status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenResource_hResource,
{ "HResource", "clusapi.clusapi_OpenResource.hResource", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenResource_lpszResourceName,
{ "LpszResourceName", "clusapi.clusapi_OpenResource.lpszResourceName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_OpenResource_rpc_status,
{ "Rpc Status", "clusapi.clusapi_OpenResource.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_PauseNodeEx_bDrainNode,
{ "BDrainNode", "clusapi.clusapi_PauseNodeEx.bDrainNode", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_PauseNodeEx_dwPauseFlags,
{ "DwPauseFlags", "clusapi.clusapi_PauseNodeEx.dwPauseFlags", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_PauseNodeEx_hNode,
{ "HNode", "clusapi.clusapi_PauseNodeEx.hNode", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_PauseNodeEx_rpc_status,
{ "Rpc Status", "clusapi.clusapi_PauseNodeEx.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_PauseNodeWithDrainTarget_dwPauseFlags,
{ "DwPauseFlags", "clusapi.clusapi_PauseNodeWithDrainTarget.dwPauseFlags", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_PauseNodeWithDrainTarget_hNode,
{ "HNode", "clusapi.clusapi_PauseNodeWithDrainTarget.hNode", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_PauseNodeWithDrainTarget_hNodeDrainTarget,
{ "HNodeDrainTarget", "clusapi.clusapi_PauseNodeWithDrainTarget.hNodeDrainTarget", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_PauseNodeWithDrainTarget_rpc_status,
{ "Rpc Status", "clusapi.clusapi_PauseNodeWithDrainTarget.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_PauseNode_hNode,
{ "HNode", "clusapi.clusapi_PauseNode.hNode", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_PauseNode_rpc_status,
{ "Rpc Status", "clusapi.clusapi_PauseNode.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_QueryAllValues_hKey,
{ "HKey", "clusapi.clusapi_QueryAllValues.hKey", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_QueryAllValues_pcbData,
{ "PcbData", "clusapi.clusapi_QueryAllValues.pcbData", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_QueryAllValues_ppData,
{ "PpData", "clusapi.clusapi_QueryAllValues.ppData", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_QueryAllValues_rpc_status,
{ "Rpc Status", "clusapi.clusapi_QueryAllValues.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_QueryInfoKey_hKey,
{ "HKey", "clusapi.clusapi_QueryInfoKey.hKey", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_QueryInfoKey_lpcSubKeys,
{ "LpcSubKeys", "clusapi.clusapi_QueryInfoKey.lpcSubKeys", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_QueryInfoKey_lpcValues,
{ "LpcValues", "clusapi.clusapi_QueryInfoKey.lpcValues", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_QueryInfoKey_lpcbMaxSubKeyLen,
{ "LpcbMaxSubKeyLen", "clusapi.clusapi_QueryInfoKey.lpcbMaxSubKeyLen", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_QueryInfoKey_lpcbMaxValueLen,
{ "LpcbMaxValueLen", "clusapi.clusapi_QueryInfoKey.lpcbMaxValueLen", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_QueryInfoKey_lpcbMaxValueNameLen,
{ "LpcbMaxValueNameLen", "clusapi.clusapi_QueryInfoKey.lpcbMaxValueNameLen", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_QueryInfoKey_lpcbSecurityDescriptor,
{ "LpcbSecurityDescriptor", "clusapi.clusapi_QueryInfoKey.lpcbSecurityDescriptor", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_QueryInfoKey_lpftLastWriteTime,
{ "LpftLastWriteTime", "clusapi.clusapi_QueryInfoKey.lpftLastWriteTime", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_QueryInfoKey_rpc_status,
{ "Rpc Status", "clusapi.clusapi_QueryInfoKey.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_QueryValue_cbData,
{ "CbData", "clusapi.clusapi_QueryValue.cbData", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_QueryValue_hKey,
{ "HKey", "clusapi.clusapi_QueryValue.hKey", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_QueryValue_lpData,
{ "LpData", "clusapi.clusapi_QueryValue.lpData", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_QueryValue_lpValueName,
{ "LpValueName", "clusapi.clusapi_QueryValue.lpValueName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_QueryValue_lpValueType,
{ "LpValueType", "clusapi.clusapi_QueryValue.lpValueType", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_QueryValue_lpcbRequired,
{ "LpcbRequired", "clusapi.clusapi_QueryValue.lpcbRequired", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_QueryValue_rpc_status,
{ "Rpc Status", "clusapi.clusapi_QueryValue.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ReAddNotifyGroup_StateSequence,
{ "StateSequence", "clusapi.clusapi_ReAddNotifyGroup.StateSequence", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ReAddNotifyGroup_dwFilter,
{ "DwFilter", "clusapi.clusapi_ReAddNotifyGroup.dwFilter", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ReAddNotifyGroup_dwNotifyKey,
{ "DwNotifyKey", "clusapi.clusapi_ReAddNotifyGroup.dwNotifyKey", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ReAddNotifyGroup_hGroup,
{ "HGroup", "clusapi.clusapi_ReAddNotifyGroup.hGroup", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ReAddNotifyGroup_hNotify,
{ "HNotify", "clusapi.clusapi_ReAddNotifyGroup.hNotify", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ReAddNotifyGroup_rpc_status,
{ "Rpc Status", "clusapi.clusapi_ReAddNotifyGroup.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ReAddNotifyNetInterface_StateSequence,
{ "StateSequence", "clusapi.clusapi_ReAddNotifyNetInterface.StateSequence", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ReAddNotifyNetInterface_dwFilter,
{ "DwFilter", "clusapi.clusapi_ReAddNotifyNetInterface.dwFilter", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ReAddNotifyNetInterface_dwNotifyKey,
{ "DwNotifyKey", "clusapi.clusapi_ReAddNotifyNetInterface.dwNotifyKey", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ReAddNotifyNetInterface_hNetInterface,
{ "HNetInterface", "clusapi.clusapi_ReAddNotifyNetInterface.hNetInterface", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ReAddNotifyNetInterface_hNotify,
{ "HNotify", "clusapi.clusapi_ReAddNotifyNetInterface.hNotify", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ReAddNotifyNetInterface_rpc_status,
{ "Rpc Status", "clusapi.clusapi_ReAddNotifyNetInterface.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ReAddNotifyNetwork_StateSequence,
{ "StateSequence", "clusapi.clusapi_ReAddNotifyNetwork.StateSequence", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ReAddNotifyNetwork_dwFilter,
{ "DwFilter", "clusapi.clusapi_ReAddNotifyNetwork.dwFilter", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ReAddNotifyNetwork_dwNotifyKey,
{ "DwNotifyKey", "clusapi.clusapi_ReAddNotifyNetwork.dwNotifyKey", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ReAddNotifyNetwork_hNetwork,
{ "HNetwork", "clusapi.clusapi_ReAddNotifyNetwork.hNetwork", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ReAddNotifyNetwork_hNotify,
{ "HNotify", "clusapi.clusapi_ReAddNotifyNetwork.hNotify", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ReAddNotifyNetwork_rpc_status,
{ "Rpc Status", "clusapi.clusapi_ReAddNotifyNetwork.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ReAddNotifyNode_StateSequence,
{ "StateSequence", "clusapi.clusapi_ReAddNotifyNode.StateSequence", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ReAddNotifyNode_dwFilter,
{ "DwFilter", "clusapi.clusapi_ReAddNotifyNode.dwFilter", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ReAddNotifyNode_dwNotifyKey,
{ "DwNotifyKey", "clusapi.clusapi_ReAddNotifyNode.dwNotifyKey", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ReAddNotifyNode_hNode,
{ "HNode", "clusapi.clusapi_ReAddNotifyNode.hNode", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ReAddNotifyNode_hNotify,
{ "HNotify", "clusapi.clusapi_ReAddNotifyNode.hNotify", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ReAddNotifyNode_rpc_status,
{ "Rpc Status", "clusapi.clusapi_ReAddNotifyNode.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ReAddNotifyResource_StateSequence,
{ "StateSequence", "clusapi.clusapi_ReAddNotifyResource.StateSequence", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ReAddNotifyResource_dwFilter,
{ "DwFilter", "clusapi.clusapi_ReAddNotifyResource.dwFilter", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ReAddNotifyResource_dwNotifyKey,
{ "DwNotifyKey", "clusapi.clusapi_ReAddNotifyResource.dwNotifyKey", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ReAddNotifyResource_hNotify,
{ "HNotify", "clusapi.clusapi_ReAddNotifyResource.hNotify", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ReAddNotifyResource_hResource,
{ "HResource", "clusapi.clusapi_ReAddNotifyResource.hResource", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ReAddNotifyResource_rpc_status,
{ "Rpc Status", "clusapi.clusapi_ReAddNotifyResource.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_RemoveResourceDependency_hDependsOn,
{ "HDependsOn", "clusapi.clusapi_RemoveResourceDependency.hDependsOn", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_RemoveResourceDependency_hResource,
{ "HResource", "clusapi.clusapi_RemoveResourceDependency.hResource", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_RemoveResourceDependency_rpc_status,
{ "Rpc Status", "clusapi.clusapi_RemoveResourceDependency.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_RemoveResourceNode_hNode,
{ "HNode", "clusapi.clusapi_RemoveResourceNode.hNode", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_RemoveResourceNode_hResource,
{ "HResource", "clusapi.clusapi_RemoveResourceNode.hResource", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_RemoveResourceNode_rpc_status,
{ "Rpc Status", "clusapi.clusapi_RemoveResourceNode.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ResourceControl_dwControlCode,
{ "DwControlCode", "clusapi.clusapi_ResourceControl.dwControlCode", FT_UINT32, BASE_DEC, VALS(clusapi_clusapi_ResourceControlCode_vals), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ResourceControl_hResource,
{ "HResource", "clusapi.clusapi_ResourceControl.hResource", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ResourceControl_lpBytesReturned,
{ "LpBytesReturned", "clusapi.clusapi_ResourceControl.lpBytesReturned", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ResourceControl_lpInBuffer,
{ "LpInBuffer", "clusapi.clusapi_ResourceControl.lpInBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ResourceControl_lpOutBuffer,
{ "LpOutBuffer", "clusapi.clusapi_ResourceControl.lpOutBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ResourceControl_lpcbRequired,
{ "LpcbRequired", "clusapi.clusapi_ResourceControl.lpcbRequired", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ResourceControl_nInBufferSize,
{ "NInBufferSize", "clusapi.clusapi_ResourceControl.nInBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ResourceControl_nOutBufferSize,
{ "NOutBufferSize", "clusapi.clusapi_ResourceControl.nOutBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ResourceControl_rpc_status,
{ "Rpc Status", "clusapi.clusapi_ResourceControl.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ResourceTypeControl_dwControlCode,
{ "DwControlCode", "clusapi.clusapi_ResourceTypeControl.dwControlCode", FT_UINT32, BASE_DEC, VALS(clusapi_clusapi_ResourceTypeControlCode_vals), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ResourceTypeControl_hCluster,
{ "HCluster", "clusapi.clusapi_ResourceTypeControl.hCluster", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ResourceTypeControl_lpBytesReturned,
{ "LpBytesReturned", "clusapi.clusapi_ResourceTypeControl.lpBytesReturned", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ResourceTypeControl_lpInBuffer,
{ "LpInBuffer", "clusapi.clusapi_ResourceTypeControl.lpInBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ResourceTypeControl_lpOutBuffer,
{ "LpOutBuffer", "clusapi.clusapi_ResourceTypeControl.lpOutBuffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ResourceTypeControl_lpcbRequired,
{ "LpcbRequired", "clusapi.clusapi_ResourceTypeControl.lpcbRequired", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ResourceTypeControl_lpszResourceTypeName,
{ "LpszResourceTypeName", "clusapi.clusapi_ResourceTypeControl.lpszResourceTypeName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ResourceTypeControl_nInBufferSize,
{ "NInBufferSize", "clusapi.clusapi_ResourceTypeControl.nInBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ResourceTypeControl_nOutBufferSize,
{ "NOutBufferSize", "clusapi.clusapi_ResourceTypeControl.nOutBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ResourceTypeControl_rpc_status,
{ "Rpc Status", "clusapi.clusapi_ResourceTypeControl.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_RestartResource_dwFlags,
{ "DwFlags", "clusapi.clusapi_RestartResource.dwFlags", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_RestartResource_hResource,
{ "HResource", "clusapi.clusapi_RestartResource.hResource", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_RestartResource_rpc_status,
{ "Rpc Status", "clusapi.clusapi_RestartResource.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ResumeNodeEx_dwResumeFailbackType,
{ "DwResumeFailbackType", "clusapi.clusapi_ResumeNodeEx.dwResumeFailbackType", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ResumeNodeEx_dwResumeFlagsReserved,
{ "DwResumeFlagsReserved", "clusapi.clusapi_ResumeNodeEx.dwResumeFlagsReserved", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ResumeNodeEx_hNode,
{ "HNode", "clusapi.clusapi_ResumeNodeEx.hNode", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ResumeNodeEx_rpc_status,
{ "Rpc Status", "clusapi.clusapi_ResumeNodeEx.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ResumeNode_hNode,
{ "HNode", "clusapi.clusapi_ResumeNode.hNode", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_ResumeNode_rpc_status,
{ "Rpc Status", "clusapi.clusapi_ResumeNode.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetClusterName_NewClusterName,
{ "NewClusterName", "clusapi.clusapi_SetClusterName.NewClusterName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetClusterName_rpc_status,
{ "Rpc Status", "clusapi.clusapi_SetClusterName.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetGroupName_hGroup,
{ "HGroup", "clusapi.clusapi_SetGroupName.hGroup", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetGroupName_lpszGroupName,
{ "LpszGroupName", "clusapi.clusapi_SetGroupName.lpszGroupName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetGroupName_rpc_status,
{ "Rpc Status", "clusapi.clusapi_SetGroupName.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetGroupNodeList_cchListSize,
{ "CchListSize", "clusapi.clusapi_SetGroupNodeList.cchListSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetGroupNodeList_hGroup,
{ "HGroup", "clusapi.clusapi_SetGroupNodeList.hGroup", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetGroupNodeList_multiSzNodeList,
{ "MultiSzNodeList", "clusapi.clusapi_SetGroupNodeList.multiSzNodeList", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetGroupNodeList_rpc_status,
{ "Rpc Status", "clusapi.clusapi_SetGroupNodeList.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetKeySecurity_SecurityInformation,
{ "SecurityInformation", "clusapi.clusapi_SetKeySecurity.SecurityInformation", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetKeySecurity_hKey,
{ "HKey", "clusapi.clusapi_SetKeySecurity.hKey", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetKeySecurity_pRpcSecurityDescriptor,
{ "PRpcSecurityDescriptor", "clusapi.clusapi_SetKeySecurity.pRpcSecurityDescriptor", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetKeySecurity_rpc_status,
{ "Rpc Status", "clusapi.clusapi_SetKeySecurity.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetNetworkName_hNetwork,
{ "HNetwork", "clusapi.clusapi_SetNetworkName.hNetwork", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetNetworkName_lpszNetworkName,
{ "LpszNetworkName", "clusapi.clusapi_SetNetworkName.lpszNetworkName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetNetworkName_rpc_status,
{ "Rpc Status", "clusapi.clusapi_SetNetworkName.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetNetworkPriorityOrder_NetworkCount,
{ "NetworkCount", "clusapi.clusapi_SetNetworkPriorityOrder.NetworkCount", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetNetworkPriorityOrder_NetworkIdList,
{ "NetworkIdList", "clusapi.clusapi_SetNetworkPriorityOrder.NetworkIdList", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetNetworkPriorityOrder_rpc_status,
{ "Rpc Status", "clusapi.clusapi_SetNetworkPriorityOrder.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetQuorumResource_dwMaxQuorumLogSize,
{ "DwMaxQuorumLogSize", "clusapi.clusapi_SetQuorumResource.dwMaxQuorumLogSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetQuorumResource_hResource,
{ "HResource", "clusapi.clusapi_SetQuorumResource.hResource", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetQuorumResource_lpszDeviceName,
{ "LpszDeviceName", "clusapi.clusapi_SetQuorumResource.lpszDeviceName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetQuorumResource_rpc_status,
{ "Rpc Status", "clusapi.clusapi_SetQuorumResource.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetResourceDependencyExpression_hResource,
{ "HResource", "clusapi.clusapi_SetResourceDependencyExpression.hResource", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetResourceDependencyExpression_lpszDependencyExpression,
{ "LpszDependencyExpression", "clusapi.clusapi_SetResourceDependencyExpression.lpszDependencyExpression", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetResourceDependencyExpression_rpc_status,
{ "Rpc Status", "clusapi.clusapi_SetResourceDependencyExpression.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetResourceName_hResource,
{ "HResource", "clusapi.clusapi_SetResourceName.hResource", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetResourceName_lpszResourceName,
{ "LpszResourceName", "clusapi.clusapi_SetResourceName.lpszResourceName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetResourceName_rpc_status,
{ "Rpc Status", "clusapi.clusapi_SetResourceName.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetServiceAccountPassword_ExpectedBufferSize,
{ "ExpectedBufferSize", "clusapi.clusapi_SetServiceAccountPassword.ExpectedBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetServiceAccountPassword_ReturnStatusBufferPtr,
{ "ReturnStatusBufferPtr", "clusapi.clusapi_SetServiceAccountPassword.ReturnStatusBufferPtr", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetServiceAccountPassword_ReturnStatusBufferSize,
{ "ReturnStatusBufferSize", "clusapi.clusapi_SetServiceAccountPassword.ReturnStatusBufferSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetServiceAccountPassword_SizeReturned,
{ "SizeReturned", "clusapi.clusapi_SetServiceAccountPassword.SizeReturned", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetServiceAccountPassword_dwFlags,
{ "DwFlags", "clusapi.clusapi_SetServiceAccountPassword.dwFlags", FT_UINT1632, BASE_DEC, VALS(clusapi_IDL_CLUSTER_SET_PASSWORD_FLAGS_vals), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetServiceAccountPassword_lpszNewPassword,
{ "LpszNewPassword", "clusapi.clusapi_SetServiceAccountPassword.lpszNewPassword", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetValue_cbData,
{ "CbData", "clusapi.clusapi_SetValue.cbData", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetValue_dwType,
{ "DwType", "clusapi.clusapi_SetValue.dwType", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetValue_hKey,
{ "HKey", "clusapi.clusapi_SetValue.hKey", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetValue_lpData,
{ "LpData", "clusapi.clusapi_SetValue.lpData", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetValue_lpValueName,
{ "LpValueName", "clusapi.clusapi_SetValue.lpValueName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_SetValue_rpc_status,
{ "Rpc Status", "clusapi.clusapi_SetValue.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_StmFindDisk_dwFlags,
{ "DwFlags", "clusapi.clusapi_StmFindDisk.dwFlags", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_StmFindDisk_hCluster,
{ "HCluster", "clusapi.clusapi_StmFindDisk.hCluster", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_StmFindDisk_pDiskId,
{ "PDiskId", "clusapi.clusapi_StmFindDisk.pDiskId", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_StmFindDisk_pUniqueId,
{ "PUniqueId", "clusapi.clusapi_StmFindDisk.pUniqueId", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_StmFindDisk_ppszDeviceName,
{ "PpszDeviceName", "clusapi.clusapi_StmFindDisk.ppszDeviceName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_StmFindDisk_rpc_status,
{ "Rpc Status", "clusapi.clusapi_StmFindDisk.rpc_status", FT_UINT32, BASE_DEC, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_StmFindDisk_uniqueIdSize,
{ "UniqueIdSize", "clusapi.clusapi_StmFindDisk.uniqueIdSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_clusapi_UnblockGetNotifyCall_hNotify,
{ "HNotify", "clusapi.clusapi_UnblockGetNotifyCall.hNotify", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_opnum,
{ "Operation", "clusapi.opnum", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_clusapi_werror,
{ "Windows Error", "clusapi.werror", FT_UINT32, BASE_HEX, VALS(WERR_errors), 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_dcerpc_clusapi,
&ett_clusapi_RPC_SECURITY_DESCRIPTOR,
&ett_clusapi_RPC_SECURITY_ATTRIBUTES,
&ett_clusapi_CLUSTER_OPERATIONAL_VERSION_INFO,
&ett_clusapi_IDL_CLUSTER_SET_PASSWORD_STATUS,
&ett_clusapi_CLUSTER_CREATE_GROUP_INFO_RPC,
&ett_clusapi_ClusterEnumType,
&ett_clusapi_ENUM_ENTRY,
&ett_clusapi_ENUM_LIST,
&ett_clusapi_GROUP_ENUM_ENTRY,
&ett_clusapi_RESOURCE_ENUM_ENTRY,
&ett_clusapi_GROUP_ENUM_LIST,
&ett_clusapi_RESOURCE_ENUM_LIST,
&ett_clusapi_ClusterGroupEnumType,
&ett_clusapi_CLUS_RESOURCE_CLASS_INFO,
&ett_clusapi_ClusterResTypeEnumType,
&ett_clusapi_clusapi_DesiredAccessMask,
&ett_clusapi_NOTIFY_FILTER_AND_TYPE_RPC,
&ett_clusapi_NOTIFICATION_DATA_RPC,
&ett_clusapi_NOTIFICATION_RPC,
&ett_clusapi_CLUSTER_DISKID,
&ett_clusapi_CLUSTER_MRR_NODE_RESPONSE,
&ett_clusapi_CLUSTER_MRR_RESPONSE,
&ett_clusapi_NOTIFICATION_DATA_ASYNC_RPC,
};
proto_dcerpc_clusapi = proto_register_protocol("Failover Cluster Management API (clusapi)", "CLUSAPI", "clusapi");
proto_register_field_array(proto_dcerpc_clusapi, hf, array_length (hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_dcerpc_clusapi(void)
{
dcerpc_init_uuid(proto_dcerpc_clusapi, ett_dcerpc_clusapi,
&uuid_dcerpc_clusapi, ver_dcerpc_clusapi,
clusapi_dissectors, hf_clusapi_opnum);
}
