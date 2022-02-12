int
dnsserver_dissect_struct_DNS_RPC_NAME(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
guint8 len;
const char *dn;
int dn_len = 0;
guint16 bc;
if(di->conformant_run){
return offset;
}
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_dnsserver_DNS_RPC_NAME);
}
offset = dissect_ndr_uint8(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_NAME_NameLength, &len);
bc = tvb_captured_length_remaining(tvb, offset);
dn = get_unicode_or_ascii_string(tvb, &offset,
TRUE, &dn_len, TRUE, TRUE, &bc);
if (dn) {
proto_tree_add_string(tree, hf_dnsserver_DNS_RPC_NAME_name, tvb,
offset, dn_len,dn);
offset += dn_len;
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_NODE_RecordCount(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di, guint8 *drep _U_)
{
if(di->conformant_run){
return offset;
}
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_NODE_RecordCount, &node_record_count);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_NODE_records(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di, guint8 *drep _U_)
{
if(di->conformant_run){
return offset;
}
while(node_record_count--){
offset = dnsserver_dissect_element_DNS_RPC_NODE_records_(tvb, offset, pinfo, tree, di, drep);
}
return offset;
}
int
dnsserver_dissect_enum_DNS_RPC_CLIENT_VERSION(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
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
dnsserver_dissect_element_DNS_RPC_VERSION_OSMajorVersion(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_VERSION_OSMajorVersion, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_VERSION_OSMinorVersion(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_VERSION_OSMinorVersion, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_VERSION_ServicePackVersion(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_VERSION_ServicePackVersion, 0);
return offset;
}
int
dnsserver_dissect_struct_DNS_RPC_VERSION(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_2_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_dnsserver_DNS_RPC_VERSION);
}
offset = dnsserver_dissect_element_DNS_RPC_VERSION_OSMajorVersion(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_VERSION_OSMinorVersion(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_VERSION_ServicePackVersion(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_2_BYTES;
}
return offset;
}
int
dnsserver_dissect_enum_DNS_RPC_BOOT_METHOD(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint8 *param _U_)
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
dnsserver_dissect_bitmap_DNS_LOG_LEVELS(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item;
static const int * dnsserver_DNS_LOG_LEVELS_fields[] = {
&hf_dnsserver_DNS_LOG_LEVELS_DNS_LOG_LEVEL_QUERY,
&hf_dnsserver_DNS_LOG_LEVELS_DNS_LOG_LEVEL_NOTIFY,
&hf_dnsserver_DNS_LOG_LEVELS_DNS_LOG_LEVEL_UPDATE,
&hf_dnsserver_DNS_LOG_LEVELS_DNS_LOG_LEVEL_QUESTIONS,
&hf_dnsserver_DNS_LOG_LEVELS_DNS_LOG_LEVEL_ANSWERS,
&hf_dnsserver_DNS_LOG_LEVELS_DNS_LOG_LEVEL_SEND,
&hf_dnsserver_DNS_LOG_LEVELS_DNS_LOG_LEVEL_RECV,
&hf_dnsserver_DNS_LOG_LEVELS_DNS_LOG_LEVEL_UDP,
&hf_dnsserver_DNS_LOG_LEVELS_DNS_LOG_LEVEL_TCP,
&hf_dnsserver_DNS_LOG_LEVELS_DNS_LOG_LEVEL_FULL_PACKETS,
&hf_dnsserver_DNS_LOG_LEVELS_DNS_LOG_LEVEL_WRITE_THROUGH,
NULL
};
guint32 flags;
ALIGN_TO_4_BYTES;
item = proto_tree_add_bitmask_with_flags(parent_tree, tvb, offset, hf_index,
ett_dnsserver_DNS_LOG_LEVELS, dnsserver_DNS_LOG_LEVELS_fields, DREP_ENC_INTEGER(drep), BMT_NO_FALSE);
offset = dissect_ndr_uint32(tvb, offset, pinfo, parent_tree, di, drep, -1, &flags);
if (!flags)
proto_item_append_text(item, ": (No values set)");
if (flags & (~0x8100f331)) {
flags &= (~0x8100f331);
proto_item_append_text(item, "Unknown bitmap value 0x%x", flags);
}
return offset;
}
int
dnsserver_dissect_bitmap_DNS_RPC_PROTOCOLS(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item;
static const int * dnsserver_DNS_RPC_PROTOCOLS_fields[] = {
&hf_dnsserver_DNS_RPC_PROTOCOLS_DNS_RPC_USE_TCPIP,
&hf_dnsserver_DNS_RPC_PROTOCOLS_DNS_RPC_USE_NAMED_PIPE,
&hf_dnsserver_DNS_RPC_PROTOCOLS_DNS_RPC_USE_LPC,
NULL
};
guint32 flags;
ALIGN_TO_4_BYTES;
item = proto_tree_add_bitmask_with_flags(parent_tree, tvb, offset, hf_index,
ett_dnsserver_DNS_RPC_PROTOCOLS, dnsserver_DNS_RPC_PROTOCOLS_fields, DREP_ENC_INTEGER(drep), BMT_NO_FALSE);
offset = dissect_ndr_uint32(tvb, offset, pinfo, parent_tree, di, drep, -1, &flags);
if (!flags)
proto_item_append_text(item, ": (No values set)");
if (flags & (~0x00000007)) {
flags &= (~0x00000007);
proto_item_append_text(item, "Unknown bitmap value 0x%x", flags);
}
return offset;
}
int
dnsserver_dissect_enum_DNS_NAME_CHECK_FLAGS(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
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
dnsserver_dissect_enum_DNS_RECORD_TYPE(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint16 *param _U_)
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
dnsserver_dissect_bitmap_DNS_SELECT_FLAGS(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item;
static const int * dnsserver_DNS_SELECT_FLAGS_fields[] = {
&hf_dnsserver_DNS_SELECT_FLAGS_DNS_RPC_VIEW_AUTHORITY_DATA,
&hf_dnsserver_DNS_SELECT_FLAGS_DNS_RPC_VIEW_CACHE_DATA,
&hf_dnsserver_DNS_SELECT_FLAGS_DNS_RPC_VIEW_GLUE_DATA,
&hf_dnsserver_DNS_SELECT_FLAGS_DNS_RPC_VIEW_ROOT_HINT_DATA,
&hf_dnsserver_DNS_SELECT_FLAGS_DNS_RPC_VIEW_ADDITIONAL_DATA,
&hf_dnsserver_DNS_SELECT_FLAGS_DNS_RPC_VIEW_NO_CHILDREN,
&hf_dnsserver_DNS_SELECT_FLAGS_DNS_RPC_VIEW_ONLY_CHILDREN,
NULL
};
guint32 flags;
ALIGN_TO_4_BYTES;
item = proto_tree_add_bitmask_with_flags(parent_tree, tvb, offset, hf_index,
ett_dnsserver_DNS_SELECT_FLAGS, dnsserver_DNS_SELECT_FLAGS_fields, DREP_ENC_INTEGER(drep), BMT_NO_FALSE);
offset = dissect_ndr_uint32(tvb, offset, pinfo, parent_tree, di, drep, -1, &flags);
if (!flags)
proto_item_append_text(item, ": (No values set)");
if (flags & (~0x0003001f)) {
flags &= (~0x0003001f);
proto_item_append_text(item, "Unknown bitmap value 0x%x", flags);
}
return offset;
}
int
dnsserver_dissect_bitmap_DNS_RPC_NODE_FLAGS(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item;
static const int * dnsserver_DNS_RPC_NODE_FLAGS_fields[] = {
&hf_dnsserver_DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_CACHE_DATA,
&hf_dnsserver_DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_ZONE_ROOT,
&hf_dnsserver_DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_AUTH_ZONE_ROOT,
&hf_dnsserver_DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_ZONE_DELEGATION,
&hf_dnsserver_DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_RECOR_DEFAULT_TTL,
&hf_dnsserver_DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_RECORD_TTL_CHANGE,
&hf_dnsserver_DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_RECORD_CREATE_PTR,
&hf_dnsserver_DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_NODE_STICKY,
&hf_dnsserver_DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_NODE_COMPLETE,
&hf_dnsserver_DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_OPEN_ACL,
&hf_dnsserver_DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_AGING_ON,
&hf_dnsserver_DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_SUPPRESS_NOTIFY,
NULL
};
guint32 flags;
ALIGN_TO_4_BYTES;
item = proto_tree_add_bitmask_with_flags(parent_tree, tvb, offset, hf_index,
ett_dnsserver_DNS_RPC_NODE_FLAGS, dnsserver_DNS_RPC_NODE_FLAGS_fields, DREP_ENC_INTEGER(drep), BMT_NO_FALSE);
offset = dissect_ndr_uint32(tvb, offset, pinfo, parent_tree, di, drep, -1, &flags);
if (!flags)
proto_item_append_text(item, ": (No values set)");
if (flags & (~0xff870000)) {
flags &= (~0xff870000);
proto_item_append_text(item, "Unknown bitmap value 0x%x", flags);
}
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_RECORD_NODE_NAME_Name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dnsserver_dissect_struct_DNS_RPC_NAME(tvb,offset,pinfo,tree,di,drep,hf_dnsserver_DNS_RPC_RECORD_NODE_NAME_Name,0);
return offset;
}
int
dnsserver_dissect_struct_DNS_RPC_RECORD_NODE_NAME(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_dnsserver_DNS_RPC_RECORD_NODE_NAME);
}
offset = dnsserver_dissect_element_DNS_RPC_RECORD_NODE_NAME_Name(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_RECORD_UNION_NodeName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dnsserver_dissect_struct_DNS_RPC_RECORD_NODE_NAME(tvb,offset,pinfo,tree,di,drep,hf_dnsserver_DNS_RPC_RECORD_UNION_NodeName,0);
return offset;
}
static int
dnsserver_dissect_DNS_RPC_RECORD_UNION(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
guint32 level;
old_offset = offset;
if (parent_tree) {
tree = proto_tree_add_subtree(parent_tree, tvb, offset, -1, ett_dnsserver_DNS_RPC_RECORD_UNION, &item, "DNS_RPC_RECORD_UNION");
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_index, &level);
switch(level) {
case 2:
offset = dnsserver_dissect_element_DNS_RPC_RECORD_UNION_NodeName(tvb, offset, pinfo, tree, di, drep);
break;
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_RECORD_DataLength(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_RECORD_DataLength, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_RECORD_Type(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, guint16 *Type)
{
offset = dnsserver_dissect_enum_DNS_RECORD_TYPE(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_RECORD_Type, Type);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_RECORD_Flags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_RECORD_Flags, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_RECORD_Serial(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_RECORD_Serial, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_RECORD_TtlSeconds(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_RECORD_TtlSeconds, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_RECORD_TimeStamp(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_RECORD_TimeStamp, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_RECORD_reserved(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_RECORD_reserved, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_RECORD_record(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, guint16 *Type)
{
offset = dnsserver_dissect_DNS_RPC_RECORD_UNION(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_RECORD_record, *Type);
return offset;
}
int
dnsserver_dissect_struct_DNS_RPC_RECORD(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
guint16 Type = 0;
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_dnsserver_DNS_RPC_RECORD);
}
offset = dnsserver_dissect_element_DNS_RPC_RECORD_DataLength(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_RECORD_Type(tvb, offset, pinfo, tree, di, drep, &Type);
offset = dnsserver_dissect_element_DNS_RPC_RECORD_Flags(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_RECORD_Serial(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_RECORD_TtlSeconds(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_RECORD_TimeStamp(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_RECORD_reserved(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_RECORD_record(tvb, offset, pinfo, tree, di, drep, &Type);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_NODE_Length(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_NODE_Length, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_NODE_Flags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dnsserver_dissect_bitmap_DNS_RPC_NODE_FLAGS(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_NODE_Flags, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_NODE_Childcount(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_NODE_Childcount, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_NODE_NodeName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dnsserver_dissect_struct_DNS_RPC_NAME(tvb,offset,pinfo,tree,di,drep,hf_dnsserver_DNS_RPC_NODE_NodeName,0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_NODE_records_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dnsserver_dissect_struct_DNS_RPC_RECORD(tvb,offset,pinfo,tree,di,drep,hf_dnsserver_DNS_RPC_NODE_records,0);
return offset;
}
int
dnsserver_dissect_struct_DNS_RPC_NODE(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_dnsserver_DNS_RPC_NODE);
}
offset = dnsserver_dissect_element_DNS_RPC_NODE_Length(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_NODE_RecordCount(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_NODE_Flags(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_NODE_Childcount(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_NODE_NodeName(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_NODE_records(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
static int
dnsserver_dissect_element_IP4_ARRAY_AddrCount(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_IP4_ARRAY_AddrCount, 0);
return offset;
}
static int
dnsserver_dissect_element_IP4_ARRAY_AddrArray(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_IP4_ARRAY_AddrArray_);
return offset;
}
static int
dnsserver_dissect_element_IP4_ARRAY_AddrArray_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_IP4_ARRAY_AddrArray, 0);
return offset;
}
int
dnsserver_dissect_struct_IP4_ARRAY(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_dnsserver_IP4_ARRAY);
}
offset = dnsserver_dissect_element_IP4_ARRAY_AddrCount(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_IP4_ARRAY_AddrArray(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_RpcStructureVersion(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_RpcStructureVersion, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_reserved0(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_reserved0, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_Version(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dnsserver_dissect_struct_DNS_RPC_VERSION(tvb,offset,pinfo,tree,di,drep,hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_Version,0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_BootMethod(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dnsserver_dissect_enum_DNS_RPC_BOOT_METHOD(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_BootMethod, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_AdminConfigured(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_AdminConfigured, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_AllowUpdate(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_AllowUpdate, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_DsAvailable(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_DsAvailable, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_ServerName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_ServerName_, NDR_POINTER_UNIQUE, "Pointer to Servername (uint8)",hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_ServerName);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_ServerName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint8), hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_ServerName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_DsContainer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_DsContainer_, NDR_POINTER_UNIQUE, "Pointer to Dscontainer (uint16)",hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_DsContainer);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_DsContainer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_DsContainer, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_ServerAddrs(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_ServerAddrs_, NDR_POINTER_UNIQUE, "Pointer to Serveraddrs (IP4_ARRAY)",hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_ServerAddrs);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_ServerAddrs_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dnsserver_dissect_struct_IP4_ARRAY(tvb,offset,pinfo,tree,di,drep,hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_ServerAddrs,0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_ListenAddrs(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_ListenAddrs_, NDR_POINTER_UNIQUE, "Pointer to Listenaddrs (IP4_ARRAY)",hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_ListenAddrs);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_ListenAddrs_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dnsserver_dissect_struct_IP4_ARRAY(tvb,offset,pinfo,tree,di,drep,hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_ListenAddrs,0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_Forwarders(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_Forwarders_, NDR_POINTER_UNIQUE, "Pointer to Forwarders (IP4_ARRAY)",hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_Forwarders);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_Forwarders_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dnsserver_dissect_struct_IP4_ARRAY(tvb,offset,pinfo,tree,di,drep,hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_Forwarders,0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_LogFilter(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_LogFilter_, NDR_POINTER_UNIQUE, "Pointer to Logfilter (IP4_ARRAY)",hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_LogFilter);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_LogFilter_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dnsserver_dissect_struct_IP4_ARRAY(tvb,offset,pinfo,tree,di,drep,hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_LogFilter,0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_LogFilePath(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_LogFilePath_, NDR_POINTER_UNIQUE, "Pointer to Logfilepath (uint16)",hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_LogFilePath);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_LogFilePath_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_LogFilePath, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_DomainName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_DomainName_, NDR_POINTER_UNIQUE, "Pointer to Domainname (uint8)",hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_DomainName);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_DomainName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint8), hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_DomainName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_ForestName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_ForestName_, NDR_POINTER_UNIQUE, "Pointer to Forestname (uint8)",hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_ForestName);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_ForestName_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint8), hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_ForestName, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_DomainDirectoryPartition(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_DomainDirectoryPartition_, NDR_POINTER_UNIQUE, "Pointer to Domaindirectorypartition (uint8)",hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_DomainDirectoryPartition);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_DomainDirectoryPartition_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint8), hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_DomainDirectoryPartition, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_ForestDirectoryPartition(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_ForestDirectoryPartition_, NDR_POINTER_UNIQUE, "Pointer to Forestdirectorypartition (uint8)",hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_ForestDirectoryPartition);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_ForestDirectoryPartition_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint8), hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_ForestDirectoryPartition, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_extension0(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_extension0_, NDR_POINTER_UNIQUE, "Pointer to Extension0 (uint8)",hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_extension0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_extension0_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint8), hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_extension0, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_extension1(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_extension1_, NDR_POINTER_UNIQUE, "Pointer to Extension1 (uint8)",hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_extension1);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_extension1_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint8), hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_extension1, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_extension2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_extension2_, NDR_POINTER_UNIQUE, "Pointer to Extension2 (uint8)",hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_extension2);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_extension2_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint8), hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_extension2, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_extension3(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_extension3_, NDR_POINTER_UNIQUE, "Pointer to Extension3 (uint8)",hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_extension3);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_extension3_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint8), hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_extension3, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_extension4(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_extension4_, NDR_POINTER_UNIQUE, "Pointer to Extension4 (uint8)",hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_extension4);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_extension4_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint8), hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_extension4, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_extension5(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_extension5_, NDR_POINTER_UNIQUE, "Pointer to Extension5 (uint8)",hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_extension5);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_extension5_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint8), hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_extension5, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_LogLevel(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dnsserver_dissect_bitmap_DNS_LOG_LEVELS(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_LogLevel, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_DebugLevel(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_DebugLevel, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_ForwardTimeout(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_ForwardTimeout, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_RpcProtocol(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dnsserver_dissect_bitmap_DNS_RPC_PROTOCOLS(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_RpcProtocol, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_NameCheckFlag(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dnsserver_dissect_enum_DNS_NAME_CHECK_FLAGS(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_NameCheckFlag, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_AddressAnswerLimit(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_AddressAnswerLimit, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_RecursionRetry(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_RecursionRetry, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_RecursionTimeout(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_RecursionTimeout, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_MaxCacheTtl(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_MaxCacheTtl, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_DsPollingInterval(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_DsPollingInterval, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_LocalNetPriorityNetmask(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_LocalNetPriorityNetmask, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_ScavengingInterval(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_ScavengingInterval, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_DefaultRefreshInterval(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_DefaultRefreshInterval, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_DefaultNoRefreshInterval(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_DefaultNoRefreshInterval, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_LastScavengeTime(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_LastScavengeTime, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_EventLogLevel(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_EventLogLevel, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_LogFileMaxSize(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_LogFileMaxSize, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_DsForestVersion(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_DsForestVersion, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_DsDomainVersion(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_DsDomainVersion, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_DsDsaVersion(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_DsDsaVersion, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_reserve_array(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
int i;
for (i = 0; i < 4; i++)
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_reserve_array_(tvb, offset, pinfo, tree, di, drep);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_reserve_array_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_reserve_array, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_AutoReverseZones(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_AutoReverseZones, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_AutoCacheUpdate(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_AutoCacheUpdate, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_RecurseAfterForwarding(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_RecurseAfterForwarding, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_ForwardDelegations(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_ForwardDelegations, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_NoRecursion(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_NoRecursion, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_SecureResponses(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_SecureResponses, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_RoundRobin(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_RoundRobin, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_LocalNetPriority(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_LocalNetPriority, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_BindSecondaries(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_BindSecondaries, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_WriteAuthorityNs(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_WriteAuthorityNs, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_StrictFileParsing(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_StrictFileParsing, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_LooseWildcarding(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_LooseWildcarding, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_DefaultAgingState(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_DefaultAgingState, 0);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_reserve_array2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
int i;
for (i = 0; i < 15; i++)
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_reserve_array2_(tvb, offset, pinfo, tree, di, drep);
return offset;
}
static int
dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_reserve_array2_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_reserve_array2, 0);
return offset;
}
int
dnsserver_dissect_struct_DNS_RPC_SERVER_INFO_DOTNET(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_dnsserver_DNS_RPC_SERVER_INFO_DOTNET);
}
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_RpcStructureVersion(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_reserved0(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_Version(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_BootMethod(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_AdminConfigured(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_AllowUpdate(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_DsAvailable(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_ServerName(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_DsContainer(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_ServerAddrs(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_ListenAddrs(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_Forwarders(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_LogFilter(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_LogFilePath(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_DomainName(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_ForestName(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_DomainDirectoryPartition(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_ForestDirectoryPartition(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_extension0(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_extension1(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_extension2(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_extension3(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_extension4(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_extension5(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_LogLevel(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_DebugLevel(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_ForwardTimeout(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_RpcProtocol(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_NameCheckFlag(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_AddressAnswerLimit(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_RecursionRetry(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_RecursionTimeout(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_MaxCacheTtl(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_DsPollingInterval(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_LocalNetPriorityNetmask(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_ScavengingInterval(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_DefaultRefreshInterval(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_DefaultNoRefreshInterval(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_LastScavengeTime(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_EventLogLevel(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_LogFileMaxSize(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_DsForestVersion(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_DsDomainVersion(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_DsDsaVersion(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_reserve_array(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_AutoReverseZones(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_AutoCacheUpdate(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_RecurseAfterForwarding(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_ForwardDelegations(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_NoRecursion(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_SecureResponses(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_RoundRobin(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_LocalNetPriority(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_BindSecondaries(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_WriteAuthorityNs(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_StrictFileParsing(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_LooseWildcarding(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_DefaultAgingState(tvb, offset, pinfo, tree, di, drep);
offset = dnsserver_dissect_element_DNS_RPC_SERVER_INFO_DOTNET_reserve_array2(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
int
dnsserver_dissect_enum_DnssrvRpcTypeId(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
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
dnsserver_dissect_element_DNSSRV_RPC_UNION_null(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DNSSRV_RPC_UNION_null_, NDR_POINTER_UNIQUE, "Pointer to Null (uint8)",hf_dnsserver_DNSSRV_RPC_UNION_null);
return offset;
}
static int
dnsserver_dissect_element_DNSSRV_RPC_UNION_null_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNSSRV_RPC_UNION_null, 0);
return offset;
}
static int
dnsserver_dissect_element_DNSSRV_RPC_UNION_dword(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DNSSRV_RPC_UNION_dword, 0);
return offset;
}
static int
dnsserver_dissect_element_DNSSRV_RPC_UNION_ServerInfoDotnet(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DNSSRV_RPC_UNION_ServerInfoDotnet_, NDR_POINTER_UNIQUE, "Pointer to Serverinfodotnet (DNS_RPC_SERVER_INFO_DOTNET)",hf_dnsserver_DNSSRV_RPC_UNION_ServerInfoDotnet);
return offset;
}
static int
dnsserver_dissect_element_DNSSRV_RPC_UNION_ServerInfoDotnet_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dnsserver_dissect_struct_DNS_RPC_SERVER_INFO_DOTNET(tvb,offset,pinfo,tree,di,drep,hf_dnsserver_DNSSRV_RPC_UNION_ServerInfoDotnet,0);
return offset;
}
static int
dnsserver_dissect_DNSSRV_RPC_UNION(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
guint32 level;
old_offset = offset;
if (parent_tree) {
tree = proto_tree_add_subtree(parent_tree, tvb, offset, -1, ett_dnsserver_DNSSRV_RPC_UNION, &item, "DNSSRV_RPC_UNION");
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_index, &level);
ALIGN_TO_5_BYTES;
switch(level) {
case DNSSRV_TYPEID_NULL:
offset = dnsserver_dissect_element_DNSSRV_RPC_UNION_null(tvb, offset, pinfo, tree, di, drep);
break;
case DNSSRV_TYPEID_DWORD:
offset = dnsserver_dissect_element_DNSSRV_RPC_UNION_dword(tvb, offset, pinfo, tree, di, drep);
break;
case DNSSRV_TYPEID_SERVER_INFO_DOTNET:
offset = dnsserver_dissect_element_DNSSRV_RPC_UNION_ServerInfoDotnet(tvb, offset, pinfo, tree, di, drep);
break;
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
dnsserver_dissect_element_DNS_RECORD_BUFFER_rpc_node(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dnsserver_dissect_struct_DNS_RPC_NODE(tvb,offset,pinfo,tree,di,drep,hf_dnsserver_DNS_RECORD_BUFFER_rpc_node,0);
return offset;
}
int
dnsserver_dissect_struct_DNS_RECORD_BUFFER(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_dnsserver_DNS_RECORD_BUFFER);
}
offset = dnsserver_dissect_element_DNS_RECORD_BUFFER_rpc_node(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
static int
dnsserver_dissect_DnssrvOperation_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="DnssrvOperation";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_status, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
dnsserver_dissect_DnssrvOperation_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="DnssrvOperation";
return offset;
}
static int
dnsserver_dissect_DnssrvQuery_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="DnssrvQuery";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_status, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
dnsserver_dissect_DnssrvQuery_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="DnssrvQuery";
return offset;
}
static int
dnsserver_dissect_DnssrvComplexOperation_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="DnssrvComplexOperation";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_status, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
dnsserver_dissect_DnssrvComplexOperation_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="DnssrvComplexOperation";
return offset;
}
static int
dnsserver_dissect_DnssrvEnumRecords_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="DnssrvEnumRecords";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_status, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
dnsserver_dissect_DnssrvEnumRecords_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="DnssrvEnumRecords";
return offset;
}
static int
dnsserver_dissect_DnssrvUpdateRecord_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="DnssrvUpdateRecord";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_status, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
dnsserver_dissect_DnssrvUpdateRecord_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="DnssrvUpdateRecord";
return offset;
}
static int
dnsserver_dissect_DnssrvOperation2_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="DnssrvOperation2";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_status, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
dnsserver_dissect_DnssrvOperation2_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="DnssrvOperation2";
return offset;
}
static int
dnsserver_dissect_element_DnssrvQuery2_client_version(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dnsserver_dissect_enum_DNS_RPC_CLIENT_VERSION(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DnssrvQuery2_client_version, 0);
return offset;
}
static int
dnsserver_dissect_element_DnssrvQuery2_setting_flags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DnssrvQuery2_setting_flags, 0);
return offset;
}
static int
dnsserver_dissect_element_DnssrvQuery2_server_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DnssrvQuery2_server_name_, NDR_POINTER_UNIQUE, "Pointer to Server Name (uint16)",hf_dnsserver_DnssrvQuery2_server_name);
return offset;
}
static int
dnsserver_dissect_element_DnssrvQuery2_server_name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_dnsserver_DnssrvQuery2_server_name, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
dnsserver_dissect_element_DnssrvQuery2_zone(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DnssrvQuery2_zone_, NDR_POINTER_UNIQUE, "Pointer to Zone (uint8)",hf_dnsserver_DnssrvQuery2_zone);
return offset;
}
static int
dnsserver_dissect_element_DnssrvQuery2_zone_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint8), hf_dnsserver_DnssrvQuery2_zone, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
dnsserver_dissect_element_DnssrvQuery2_operation(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DnssrvQuery2_operation_, NDR_POINTER_UNIQUE, "Pointer to Operation (uint8)",hf_dnsserver_DnssrvQuery2_operation);
return offset;
}
static int
dnsserver_dissect_element_DnssrvQuery2_operation_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint8), hf_dnsserver_DnssrvQuery2_operation, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
dnsserver_dissect_element_DnssrvQuery2_type_id(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DnssrvQuery2_type_id_, NDR_POINTER_REF, "Pointer to Type Id (DnssrvRpcTypeId)",hf_dnsserver_DnssrvQuery2_type_id);
return offset;
}
static int
dnsserver_dissect_element_DnssrvQuery2_type_id_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dnsserver_dissect_enum_DnssrvRpcTypeId(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DnssrvQuery2_type_id, 0);
return offset;
}
static int
dnsserver_dissect_element_DnssrvQuery2_data(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DnssrvQuery2_data_, NDR_POINTER_REF, "Pointer to Data (DNSSRV_RPC_UNION)",hf_dnsserver_DnssrvQuery2_data);
return offset;
}
static int
dnsserver_dissect_element_DnssrvQuery2_data_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dnsserver_dissect_DNSSRV_RPC_UNION(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DnssrvQuery2_data, 0);
return offset;
}
static int
dnsserver_dissect_DnssrvQuery2_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="DnssrvQuery2";
offset = dnsserver_dissect_element_DnssrvQuery2_type_id(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dnsserver_dissect_element_DnssrvQuery2_data(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_status, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
dnsserver_dissect_DnssrvQuery2_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="DnssrvQuery2";
offset = dnsserver_dissect_element_DnssrvQuery2_client_version(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dnsserver_dissect_element_DnssrvQuery2_setting_flags(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dnsserver_dissect_element_DnssrvQuery2_server_name(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dnsserver_dissect_element_DnssrvQuery2_zone(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dnsserver_dissect_element_DnssrvQuery2_operation(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
dnsserver_dissect_DnssrvComplexOperation2_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="DnssrvComplexOperation2";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_status, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
dnsserver_dissect_DnssrvComplexOperation2_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="DnssrvComplexOperation2";
return offset;
}
static int
dnsserver_dissect_element_DnssrvEnumRecords2_client_version(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dnsserver_dissect_enum_DNS_RPC_CLIENT_VERSION(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DnssrvEnumRecords2_client_version, 0);
return offset;
}
static int
dnsserver_dissect_element_DnssrvEnumRecords2_setting_flags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DnssrvEnumRecords2_setting_flags, 0);
return offset;
}
static int
dnsserver_dissect_element_DnssrvEnumRecords2_server_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DnssrvEnumRecords2_server_name_, NDR_POINTER_UNIQUE, "Pointer to Server Name (uint16)",hf_dnsserver_DnssrvEnumRecords2_server_name);
return offset;
}
static int
dnsserver_dissect_element_DnssrvEnumRecords2_server_name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_dnsserver_DnssrvEnumRecords2_server_name, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
dnsserver_dissect_element_DnssrvEnumRecords2_zone(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DnssrvEnumRecords2_zone_, NDR_POINTER_UNIQUE, "Pointer to Zone (uint8)",hf_dnsserver_DnssrvEnumRecords2_zone);
return offset;
}
static int
dnsserver_dissect_element_DnssrvEnumRecords2_zone_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint8), hf_dnsserver_DnssrvEnumRecords2_zone, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
dnsserver_dissect_element_DnssrvEnumRecords2_node_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DnssrvEnumRecords2_node_name_, NDR_POINTER_UNIQUE, "Pointer to Node Name (uint8)",hf_dnsserver_DnssrvEnumRecords2_node_name);
return offset;
}
static int
dnsserver_dissect_element_DnssrvEnumRecords2_node_name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint8), hf_dnsserver_DnssrvEnumRecords2_node_name, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
dnsserver_dissect_element_DnssrvEnumRecords2_start_child(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DnssrvEnumRecords2_start_child_, NDR_POINTER_UNIQUE, "Pointer to Start Child (uint8)",hf_dnsserver_DnssrvEnumRecords2_start_child);
return offset;
}
static int
dnsserver_dissect_element_DnssrvEnumRecords2_start_child_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint8), hf_dnsserver_DnssrvEnumRecords2_start_child, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
dnsserver_dissect_element_DnssrvEnumRecords2_record_type(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dnsserver_dissect_enum_DNS_RECORD_TYPE(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DnssrvEnumRecords2_record_type, 0);
return offset;
}
static int
dnsserver_dissect_element_DnssrvEnumRecords2_select_flag(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dnsserver_dissect_bitmap_DNS_SELECT_FLAGS(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DnssrvEnumRecords2_select_flag, 0);
return offset;
}
static int
dnsserver_dissect_element_DnssrvEnumRecords2_filter_start(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DnssrvEnumRecords2_filter_start_, NDR_POINTER_UNIQUE, "Pointer to Filter Start (uint8)",hf_dnsserver_DnssrvEnumRecords2_filter_start);
return offset;
}
static int
dnsserver_dissect_element_DnssrvEnumRecords2_filter_start_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint8), hf_dnsserver_DnssrvEnumRecords2_filter_start, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
dnsserver_dissect_element_DnssrvEnumRecords2_filter_stop(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DnssrvEnumRecords2_filter_stop_, NDR_POINTER_UNIQUE, "Pointer to Filter Stop (uint8)",hf_dnsserver_DnssrvEnumRecords2_filter_stop);
return offset;
}
static int
dnsserver_dissect_element_DnssrvEnumRecords2_filter_stop_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint8), hf_dnsserver_DnssrvEnumRecords2_filter_stop, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
dnsserver_dissect_element_DnssrvEnumRecords2_buffer_length(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DnssrvEnumRecords2_buffer_length_, NDR_POINTER_REF, "Pointer to Buffer Length (uint32)",hf_dnsserver_DnssrvEnumRecords2_buffer_length);
return offset;
}
static int
dnsserver_dissect_element_DnssrvEnumRecords2_buffer_length_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DnssrvEnumRecords2_buffer_length, 0);
return offset;
}
static int
dnsserver_dissect_element_DnssrvEnumRecords2_record_buffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, dnsserver_dissect_element_DnssrvEnumRecords2_record_buffer_, NDR_POINTER_UNIQUE, "Pointer to Record Buffer (DNS_RPC_NODE)",hf_dnsserver_DnssrvEnumRecords2_record_buffer);
return offset;
}
static int
dnsserver_dissect_element_DnssrvEnumRecords2_record_buffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint3264 size;
int conformant = di->conformant_run;
tvbuff_t *subtvb;
if (!conformant) {
guint32 saved_flags = di->call_data->flags;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_DnssrvEnumRecords2_record_buffer_, &size);
di->call_data->flags &= ~DCERPC_IS_NDR64;
subtvb = tvb_new_subset(tvb, offset, (const gint)size, -1);
dnsserver_dissect_element_DnssrvEnumRecords2_record_buffer__(subtvb, 0, pinfo, tree, di, drep);
offset += (int)size;
di->call_data->flags = saved_flags;
}
return offset;
}
static int
dnsserver_dissect_element_DnssrvEnumRecords2_record_buffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dnsserver_dissect_struct_DNS_RPC_NODE(tvb,offset,pinfo,tree,di,drep,hf_dnsserver_DnssrvEnumRecords2_record_buffer,0);
return offset;
}
static int
dnsserver_dissect_DnssrvEnumRecords2_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="DnssrvEnumRecords2";
offset = dnsserver_dissect_element_DnssrvEnumRecords2_buffer_length(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dnsserver_dissect_element_DnssrvEnumRecords2_record_buffer(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_status, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
dnsserver_dissect_DnssrvEnumRecords2_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="DnssrvEnumRecords2";
offset = dnsserver_dissect_element_DnssrvEnumRecords2_client_version(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dnsserver_dissect_element_DnssrvEnumRecords2_setting_flags(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dnsserver_dissect_element_DnssrvEnumRecords2_server_name(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dnsserver_dissect_element_DnssrvEnumRecords2_zone(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dnsserver_dissect_element_DnssrvEnumRecords2_node_name(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dnsserver_dissect_element_DnssrvEnumRecords2_start_child(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dnsserver_dissect_element_DnssrvEnumRecords2_record_type(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dnsserver_dissect_element_DnssrvEnumRecords2_select_flag(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dnsserver_dissect_element_DnssrvEnumRecords2_filter_start(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dnsserver_dissect_element_DnssrvEnumRecords2_filter_stop(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
dnsserver_dissect_DnssrvUpdateRecord2_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="DnssrvUpdateRecord2";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, di, drep, hf_dnsserver_status, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
dnsserver_dissect_DnssrvUpdateRecord2_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="DnssrvUpdateRecord2";
return offset;
}
void proto_register_dcerpc_dnsserver(void)
{
static hf_register_info hf[] = {
{ &hf_dnsserver_DNSSRV_RPC_UNION_ServerInfoDotnet,
{ "Serverinfodotnet", "dnsserver.DNSSRV_RPC_UNION.ServerInfoDotnet", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNSSRV_RPC_UNION_dword,
{ "Dword", "dnsserver.DNSSRV_RPC_UNION.dword", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNSSRV_RPC_UNION_null,
{ "Null", "dnsserver.DNSSRV_RPC_UNION.null", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_LOG_LEVELS_DNS_LOG_LEVEL_ANSWERS,
{ "Dns Log Level Answers", "dnsserver.DNS_LOG_LEVELS.DNS_LOG_LEVEL_ANSWERS", FT_BOOLEAN, 32, TFS(&DNS_LOG_LEVELS_DNS_LOG_LEVEL_ANSWERS_tfs), ( 0x00000200 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_LOG_LEVELS_DNS_LOG_LEVEL_FULL_PACKETS,
{ "Dns Log Level Full Packets", "dnsserver.DNS_LOG_LEVELS.DNS_LOG_LEVEL_FULL_PACKETS", FT_BOOLEAN, 32, TFS(&DNS_LOG_LEVELS_DNS_LOG_LEVEL_FULL_PACKETS_tfs), ( 0x01000000 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_LOG_LEVELS_DNS_LOG_LEVEL_NOTIFY,
{ "Dns Log Level Notify", "dnsserver.DNS_LOG_LEVELS.DNS_LOG_LEVEL_NOTIFY", FT_BOOLEAN, 32, TFS(&DNS_LOG_LEVELS_DNS_LOG_LEVEL_NOTIFY_tfs), ( 0x00000010 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_LOG_LEVELS_DNS_LOG_LEVEL_QUERY,
{ "Dns Log Level Query", "dnsserver.DNS_LOG_LEVELS.DNS_LOG_LEVEL_QUERY", FT_BOOLEAN, 32, TFS(&DNS_LOG_LEVELS_DNS_LOG_LEVEL_QUERY_tfs), ( 0x00000001 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_LOG_LEVELS_DNS_LOG_LEVEL_QUESTIONS,
{ "Dns Log Level Questions", "dnsserver.DNS_LOG_LEVELS.DNS_LOG_LEVEL_QUESTIONS", FT_BOOLEAN, 32, TFS(&DNS_LOG_LEVELS_DNS_LOG_LEVEL_QUESTIONS_tfs), ( 0x00000100 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_LOG_LEVELS_DNS_LOG_LEVEL_RECV,
{ "Dns Log Level Recv", "dnsserver.DNS_LOG_LEVELS.DNS_LOG_LEVEL_RECV", FT_BOOLEAN, 32, TFS(&DNS_LOG_LEVELS_DNS_LOG_LEVEL_RECV_tfs), ( 0x00002000 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_LOG_LEVELS_DNS_LOG_LEVEL_SEND,
{ "Dns Log Level Send", "dnsserver.DNS_LOG_LEVELS.DNS_LOG_LEVEL_SEND", FT_BOOLEAN, 32, TFS(&DNS_LOG_LEVELS_DNS_LOG_LEVEL_SEND_tfs), ( 0x00001000 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_LOG_LEVELS_DNS_LOG_LEVEL_TCP,
{ "Dns Log Level Tcp", "dnsserver.DNS_LOG_LEVELS.DNS_LOG_LEVEL_TCP", FT_BOOLEAN, 32, TFS(&DNS_LOG_LEVELS_DNS_LOG_LEVEL_TCP_tfs), ( 0x00008000 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_LOG_LEVELS_DNS_LOG_LEVEL_UDP,
{ "Dns Log Level Udp", "dnsserver.DNS_LOG_LEVELS.DNS_LOG_LEVEL_UDP", FT_BOOLEAN, 32, TFS(&DNS_LOG_LEVELS_DNS_LOG_LEVEL_UDP_tfs), ( 0x00004000 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_LOG_LEVELS_DNS_LOG_LEVEL_UPDATE,
{ "Dns Log Level Update", "dnsserver.DNS_LOG_LEVELS.DNS_LOG_LEVEL_UPDATE", FT_BOOLEAN, 32, TFS(&DNS_LOG_LEVELS_DNS_LOG_LEVEL_UPDATE_tfs), ( 0x00000020 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_LOG_LEVELS_DNS_LOG_LEVEL_WRITE_THROUGH,
{ "Dns Log Level Write Through", "dnsserver.DNS_LOG_LEVELS.DNS_LOG_LEVEL_WRITE_THROUGH", FT_BOOLEAN, 32, TFS(&DNS_LOG_LEVELS_DNS_LOG_LEVEL_WRITE_THROUGH_tfs), ( 0x80000000 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_RECORD_BUFFER_rpc_node,
{ "Rpc Node", "dnsserver.DNS_RECORD_BUFFER.rpc_node", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_NAME_Name,
{ "Name", "dnsserver.DNS_RPC_NAME.Name", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_NAME_NameLength,
{ "Namelength", "dnsserver.DNS_RPC_NAME.NameLength", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_NAME_name,
{ "Name", "dnsserver.DNS_RPC_NAME.name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_NODE_Childcount,
{ "Childcount", "dnsserver.DNS_RPC_NODE.Childcount", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_AGING_ON,
{ "Dns Rpc Flag Aging On", "dnsserver.DNS_RPC_NODE_FLAGS.DNS_RPC_FLAG_AGING_ON", FT_BOOLEAN, 32, TFS(&DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_AGING_ON_tfs), ( 0x00020000 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_AUTH_ZONE_ROOT,
{ "Dns Rpc Flag Auth Zone Root", "dnsserver.DNS_RPC_NODE_FLAGS.DNS_RPC_FLAG_AUTH_ZONE_ROOT", FT_BOOLEAN, 32, TFS(&DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_AUTH_ZONE_ROOT_tfs), ( 0x20000000 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_CACHE_DATA,
{ "Dns Rpc Flag Cache Data", "dnsserver.DNS_RPC_NODE_FLAGS.DNS_RPC_FLAG_CACHE_DATA", FT_BOOLEAN, 32, TFS(&DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_CACHE_DATA_tfs), ( 0x80000000 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_NODE_COMPLETE,
{ "Dns Rpc Flag Node Complete", "dnsserver.DNS_RPC_NODE_FLAGS.DNS_RPC_FLAG_NODE_COMPLETE", FT_BOOLEAN, 32, TFS(&DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_NODE_COMPLETE_tfs), ( 0x00800000 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_NODE_STICKY,
{ "Dns Rpc Flag Node Sticky", "dnsserver.DNS_RPC_NODE_FLAGS.DNS_RPC_FLAG_NODE_STICKY", FT_BOOLEAN, 32, TFS(&DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_NODE_STICKY_tfs), ( 0x01000000 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_OPEN_ACL,
{ "Dns Rpc Flag Open Acl", "dnsserver.DNS_RPC_NODE_FLAGS.DNS_RPC_FLAG_OPEN_ACL", FT_BOOLEAN, 32, TFS(&DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_OPEN_ACL_tfs), ( 0x00040000 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_RECORD_CREATE_PTR,
{ "Dns Rpc Flag Record Create Ptr", "dnsserver.DNS_RPC_NODE_FLAGS.DNS_RPC_FLAG_RECORD_CREATE_PTR", FT_BOOLEAN, 32, TFS(&DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_RECORD_CREATE_PTR_tfs), ( 0x02000000 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_RECORD_TTL_CHANGE,
{ "Dns Rpc Flag Record Ttl Change", "dnsserver.DNS_RPC_NODE_FLAGS.DNS_RPC_FLAG_RECORD_TTL_CHANGE", FT_BOOLEAN, 32, TFS(&DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_RECORD_TTL_CHANGE_tfs), ( 0x04000000 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_RECOR_DEFAULT_TTL,
{ "Dns Rpc Flag Recor Default Ttl", "dnsserver.DNS_RPC_NODE_FLAGS.DNS_RPC_FLAG_RECOR_DEFAULT_TTL", FT_BOOLEAN, 32, TFS(&DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_RECOR_DEFAULT_TTL_tfs), ( 0x08000000 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_SUPPRESS_NOTIFY,
{ "Dns Rpc Flag Suppress Notify", "dnsserver.DNS_RPC_NODE_FLAGS.DNS_RPC_FLAG_SUPPRESS_NOTIFY", FT_BOOLEAN, 32, TFS(&DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_SUPPRESS_NOTIFY_tfs), ( 0x00010000 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_ZONE_DELEGATION,
{ "Dns Rpc Flag Zone Delegation", "dnsserver.DNS_RPC_NODE_FLAGS.DNS_RPC_FLAG_ZONE_DELEGATION", FT_BOOLEAN, 32, TFS(&DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_ZONE_DELEGATION_tfs), ( 0x10000000 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_ZONE_ROOT,
{ "Dns Rpc Flag Zone Root", "dnsserver.DNS_RPC_NODE_FLAGS.DNS_RPC_FLAG_ZONE_ROOT", FT_BOOLEAN, 32, TFS(&DNS_RPC_NODE_FLAGS_DNS_RPC_FLAG_ZONE_ROOT_tfs), ( 0x40000000 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_NODE_Flags,
{ "Flags", "dnsserver.DNS_RPC_NODE.Flags", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_NODE_Length,
{ "Length", "dnsserver.DNS_RPC_NODE.Length", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_NODE_NodeName,
{ "Nodename", "dnsserver.DNS_RPC_NODE.NodeName", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_NODE_RecordCount,
{ "Recordcount", "dnsserver.DNS_RPC_NODE.RecordCount", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_NODE_records,
{ "Records", "dnsserver.DNS_RPC_NODE.records", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_PROTOCOLS_DNS_RPC_USE_LPC,
{ "Dns Rpc Use Lpc", "dnsserver.DNS_RPC_PROTOCOLS.DNS_RPC_USE_LPC", FT_BOOLEAN, 32, TFS(&DNS_RPC_PROTOCOLS_DNS_RPC_USE_LPC_tfs), ( 0x00000004 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_PROTOCOLS_DNS_RPC_USE_NAMED_PIPE,
{ "Dns Rpc Use Named Pipe", "dnsserver.DNS_RPC_PROTOCOLS.DNS_RPC_USE_NAMED_PIPE", FT_BOOLEAN, 32, TFS(&DNS_RPC_PROTOCOLS_DNS_RPC_USE_NAMED_PIPE_tfs), ( 0x00000002 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_PROTOCOLS_DNS_RPC_USE_TCPIP,
{ "Dns Rpc Use Tcpip", "dnsserver.DNS_RPC_PROTOCOLS.DNS_RPC_USE_TCPIP", FT_BOOLEAN, 32, TFS(&DNS_RPC_PROTOCOLS_DNS_RPC_USE_TCPIP_tfs), ( 0x00000001 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_RECORD_DataLength,
{ "Datalength", "dnsserver.DNS_RPC_RECORD.DataLength", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_RECORD_Flags,
{ "Flags", "dnsserver.DNS_RPC_RECORD.Flags", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_RECORD_NODE_NAME_Name,
{ "Name", "dnsserver.DNS_RPC_RECORD_NODE_NAME.Name", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_RECORD_Serial,
{ "Serial", "dnsserver.DNS_RPC_RECORD.Serial", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_RECORD_TimeStamp,
{ "Timestamp", "dnsserver.DNS_RPC_RECORD.TimeStamp", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_RECORD_TtlSeconds,
{ "Ttlseconds", "dnsserver.DNS_RPC_RECORD.TtlSeconds", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_RECORD_Type,
{ "Type", "dnsserver.DNS_RPC_RECORD.Type", FT_UINT16, BASE_DEC, VALS(dnsserver_DNS_RECORD_TYPE_vals), 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_RECORD_UNION_NodeName,
{ "Nodename", "dnsserver.DNS_RPC_RECORD_UNION.NodeName", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_RECORD_record,
{ "Record", "dnsserver.DNS_RPC_RECORD.record", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_RECORD_reserved,
{ "Reserved", "dnsserver.DNS_RPC_RECORD.reserved", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_AddressAnswerLimit,
{ "Addressanswerlimit", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.AddressAnswerLimit", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_AdminConfigured,
{ "Adminconfigured", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.AdminConfigured", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_AllowUpdate,
{ "Allowupdate", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.AllowUpdate", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_AutoCacheUpdate,
{ "Autocacheupdate", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.AutoCacheUpdate", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_AutoReverseZones,
{ "Autoreversezones", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.AutoReverseZones", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_BindSecondaries,
{ "Bindsecondaries", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.BindSecondaries", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_BootMethod,
{ "Bootmethod", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.BootMethod", FT_UINT8, BASE_DEC, VALS(dnsserver_DNS_RPC_BOOT_METHOD_vals), 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_DebugLevel,
{ "Debuglevel", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.DebugLevel", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_DefaultAgingState,
{ "Defaultagingstate", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.DefaultAgingState", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_DefaultNoRefreshInterval,
{ "Defaultnorefreshinterval", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.DefaultNoRefreshInterval", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_DefaultRefreshInterval,
{ "Defaultrefreshinterval", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.DefaultRefreshInterval", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_DomainDirectoryPartition,
{ "Domaindirectorypartition", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.DomainDirectoryPartition", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_DomainName,
{ "Domainname", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.DomainName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_DsAvailable,
{ "Dsavailable", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.DsAvailable", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_DsContainer,
{ "Dscontainer", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.DsContainer", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_DsDomainVersion,
{ "Dsdomainversion", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.DsDomainVersion", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_DsDsaVersion,
{ "Dsdsaversion", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.DsDsaVersion", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_DsForestVersion,
{ "Dsforestversion", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.DsForestVersion", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_DsPollingInterval,
{ "Dspollinginterval", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.DsPollingInterval", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_EventLogLevel,
{ "Eventloglevel", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.EventLogLevel", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_ForestDirectoryPartition,
{ "Forestdirectorypartition", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.ForestDirectoryPartition", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_ForestName,
{ "Forestname", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.ForestName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_ForwardDelegations,
{ "Forwarddelegations", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.ForwardDelegations", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_ForwardTimeout,
{ "Forwardtimeout", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.ForwardTimeout", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_Forwarders,
{ "Forwarders", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.Forwarders", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_LastScavengeTime,
{ "Lastscavengetime", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.LastScavengeTime", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_ListenAddrs,
{ "Listenaddrs", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.ListenAddrs", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_LocalNetPriority,
{ "Localnetpriority", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.LocalNetPriority", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_LocalNetPriorityNetmask,
{ "Localnetprioritynetmask", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.LocalNetPriorityNetmask", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_LogFileMaxSize,
{ "Logfilemaxsize", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.LogFileMaxSize", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_LogFilePath,
{ "Logfilepath", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.LogFilePath", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_LogFilter,
{ "Logfilter", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.LogFilter", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_LogLevel,
{ "Loglevel", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.LogLevel", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_LooseWildcarding,
{ "Loosewildcarding", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.LooseWildcarding", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_MaxCacheTtl,
{ "Maxcachettl", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.MaxCacheTtl", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_NameCheckFlag,
{ "Namecheckflag", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.NameCheckFlag", FT_UINT32, BASE_DEC, VALS(dnsserver_DNS_NAME_CHECK_FLAGS_vals), 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_NoRecursion,
{ "Norecursion", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.NoRecursion", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_RecurseAfterForwarding,
{ "Recurseafterforwarding", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.RecurseAfterForwarding", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_RecursionRetry,
{ "Recursionretry", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.RecursionRetry", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_RecursionTimeout,
{ "Recursiontimeout", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.RecursionTimeout", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_RoundRobin,
{ "Roundrobin", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.RoundRobin", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_RpcProtocol,
{ "Rpcprotocol", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.RpcProtocol", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_RpcStructureVersion,
{ "Rpcstructureversion", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.RpcStructureVersion", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_ScavengingInterval,
{ "Scavenginginterval", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.ScavengingInterval", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_SecureResponses,
{ "Secureresponses", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.SecureResponses", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_ServerAddrs,
{ "Serveraddrs", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.ServerAddrs", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_ServerName,
{ "Servername", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.ServerName", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_StrictFileParsing,
{ "Strictfileparsing", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.StrictFileParsing", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_Version,
{ "Version", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.Version", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_WriteAuthorityNs,
{ "Writeauthorityns", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.WriteAuthorityNs", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_extension0,
{ "Extension0", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.extension0", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_extension1,
{ "Extension1", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.extension1", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_extension2,
{ "Extension2", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.extension2", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_extension3,
{ "Extension3", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.extension3", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_extension4,
{ "Extension4", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.extension4", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_extension5,
{ "Extension5", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.extension5", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_reserve_array,
{ "Reserve Array", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.reserve_array", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_reserve_array2,
{ "Reserve Array2", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.reserve_array2", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_SERVER_INFO_DOTNET_reserved0,
{ "Reserved0", "dnsserver.DNS_RPC_SERVER_INFO_DOTNET.reserved0", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_VERSION_OSMajorVersion,
{ "Osmajorversion", "dnsserver.DNS_RPC_VERSION.OSMajorVersion", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_VERSION_OSMinorVersion,
{ "Osminorversion", "dnsserver.DNS_RPC_VERSION.OSMinorVersion", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_RPC_VERSION_ServicePackVersion,
{ "Servicepackversion", "dnsserver.DNS_RPC_VERSION.ServicePackVersion", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DNS_SELECT_FLAGS_DNS_RPC_VIEW_ADDITIONAL_DATA,
{ "Dns Rpc View Additional Data", "dnsserver.DNS_SELECT_FLAGS.DNS_RPC_VIEW_ADDITIONAL_DATA", FT_BOOLEAN, 32, TFS(&DNS_SELECT_FLAGS_DNS_RPC_VIEW_ADDITIONAL_DATA_tfs), ( 0x00000010 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_SELECT_FLAGS_DNS_RPC_VIEW_AUTHORITY_DATA,
{ "Dns Rpc View Authority Data", "dnsserver.DNS_SELECT_FLAGS.DNS_RPC_VIEW_AUTHORITY_DATA", FT_BOOLEAN, 32, TFS(&DNS_SELECT_FLAGS_DNS_RPC_VIEW_AUTHORITY_DATA_tfs), ( 0x00000001 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_SELECT_FLAGS_DNS_RPC_VIEW_CACHE_DATA,
{ "Dns Rpc View Cache Data", "dnsserver.DNS_SELECT_FLAGS.DNS_RPC_VIEW_CACHE_DATA", FT_BOOLEAN, 32, TFS(&DNS_SELECT_FLAGS_DNS_RPC_VIEW_CACHE_DATA_tfs), ( 0x00000002 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_SELECT_FLAGS_DNS_RPC_VIEW_GLUE_DATA,
{ "Dns Rpc View Glue Data", "dnsserver.DNS_SELECT_FLAGS.DNS_RPC_VIEW_GLUE_DATA", FT_BOOLEAN, 32, TFS(&DNS_SELECT_FLAGS_DNS_RPC_VIEW_GLUE_DATA_tfs), ( 0x00000004 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_SELECT_FLAGS_DNS_RPC_VIEW_NO_CHILDREN,
{ "Dns Rpc View No Children", "dnsserver.DNS_SELECT_FLAGS.DNS_RPC_VIEW_NO_CHILDREN", FT_BOOLEAN, 32, TFS(&DNS_SELECT_FLAGS_DNS_RPC_VIEW_NO_CHILDREN_tfs), ( 0x00010000 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_SELECT_FLAGS_DNS_RPC_VIEW_ONLY_CHILDREN,
{ "Dns Rpc View Only Children", "dnsserver.DNS_SELECT_FLAGS.DNS_RPC_VIEW_ONLY_CHILDREN", FT_BOOLEAN, 32, TFS(&DNS_SELECT_FLAGS_DNS_RPC_VIEW_ONLY_CHILDREN_tfs), ( 0x00020000 ), NULL, HFILL }},
{ &hf_dnsserver_DNS_SELECT_FLAGS_DNS_RPC_VIEW_ROOT_HINT_DATA,
{ "Dns Rpc View Root Hint Data", "dnsserver.DNS_SELECT_FLAGS.DNS_RPC_VIEW_ROOT_HINT_DATA", FT_BOOLEAN, 32, TFS(&DNS_SELECT_FLAGS_DNS_RPC_VIEW_ROOT_HINT_DATA_tfs), ( 0x00000008 ), NULL, HFILL }},
{ &hf_dnsserver_DnssrvEnumRecords2_buffer_length,
{ "Buffer Length", "dnsserver.DnssrvEnumRecords2.buffer_length", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DnssrvEnumRecords2_client_version,
{ "Client Version", "dnsserver.DnssrvEnumRecords2.client_version", FT_UINT32, BASE_DEC, VALS(dnsserver_DNS_RPC_CLIENT_VERSION_vals), 0, NULL, HFILL }},
{ &hf_dnsserver_DnssrvEnumRecords2_filter_start,
{ "Filter Start", "dnsserver.DnssrvEnumRecords2.filter_start", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DnssrvEnumRecords2_filter_stop,
{ "Filter Stop", "dnsserver.DnssrvEnumRecords2.filter_stop", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DnssrvEnumRecords2_node_name,
{ "Node Name", "dnsserver.DnssrvEnumRecords2.node_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DnssrvEnumRecords2_record_buffer,
{ "Record Buffer", "dnsserver.DnssrvEnumRecords2.record_buffer", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DnssrvEnumRecords2_record_buffer_,
{ "Subcontext length", "dnsserver.DnssrvEnumRecords2.subcontext", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DnssrvEnumRecords2_record_type,
{ "Record Type", "dnsserver.DnssrvEnumRecords2.record_type", FT_UINT16, BASE_DEC, VALS(dnsserver_DNS_RECORD_TYPE_vals), 0, NULL, HFILL }},
{ &hf_dnsserver_DnssrvEnumRecords2_select_flag,
{ "Select Flag", "dnsserver.DnssrvEnumRecords2.select_flag", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DnssrvEnumRecords2_server_name,
{ "Server Name", "dnsserver.DnssrvEnumRecords2.server_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DnssrvEnumRecords2_setting_flags,
{ "Setting Flags", "dnsserver.DnssrvEnumRecords2.setting_flags", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DnssrvEnumRecords2_start_child,
{ "Start Child", "dnsserver.DnssrvEnumRecords2.start_child", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DnssrvEnumRecords2_zone,
{ "Zone", "dnsserver.DnssrvEnumRecords2.zone", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DnssrvQuery2_client_version,
{ "Client Version", "dnsserver.DnssrvQuery2.client_version", FT_UINT32, BASE_DEC, VALS(dnsserver_DNS_RPC_CLIENT_VERSION_vals), 0, NULL, HFILL }},
{ &hf_dnsserver_DnssrvQuery2_data,
{ "Data", "dnsserver.DnssrvQuery2.data", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DnssrvQuery2_operation,
{ "Operation", "dnsserver.DnssrvQuery2.operation", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DnssrvQuery2_server_name,
{ "Server Name", "dnsserver.DnssrvQuery2.server_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DnssrvQuery2_setting_flags,
{ "Setting Flags", "dnsserver.DnssrvQuery2.setting_flags", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_DnssrvQuery2_type_id,
{ "Type Id", "dnsserver.DnssrvQuery2.type_id", FT_UINT32, BASE_DEC, VALS(dnsserver_DnssrvRpcTypeId_vals), 0, NULL, HFILL }},
{ &hf_dnsserver_DnssrvQuery2_zone,
{ "Zone", "dnsserver.DnssrvQuery2.zone", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_IP4_ARRAY_AddrArray,
{ "Addrarray", "dnsserver.IP4_ARRAY.AddrArray", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_IP4_ARRAY_AddrCount,
{ "Addrcount", "dnsserver.IP4_ARRAY.AddrCount", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_opnum,
{ "Operation", "dnsserver.opnum", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dnsserver_status,
{ "NT Error", "dnsserver.status", FT_UINT32, BASE_HEX, VALS(NT_errors), 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_dcerpc_dnsserver,
&ett_dnsserver_DNS_RPC_VERSION,
&ett_dnsserver_DNS_LOG_LEVELS,
&ett_dnsserver_DNS_RPC_PROTOCOLS,
&ett_dnsserver_DNS_SELECT_FLAGS,
&ett_dnsserver_DNS_RPC_NODE_FLAGS,
&ett_dnsserver_DNS_RPC_NAME,
&ett_dnsserver_DNS_RPC_RECORD_NODE_NAME,
&ett_dnsserver_DNS_RPC_RECORD_UNION,
&ett_dnsserver_DNS_RPC_RECORD,
&ett_dnsserver_DNS_RPC_NODE,
&ett_dnsserver_IP4_ARRAY,
&ett_dnsserver_DNS_RPC_SERVER_INFO_DOTNET,
&ett_dnsserver_DNSSRV_RPC_UNION,
&ett_dnsserver_DNS_RECORD_BUFFER,
};
proto_dcerpc_dnsserver = proto_register_protocol("DNS Server", "DNSSERVER", "dnsserver");
proto_register_field_array(proto_dcerpc_dnsserver, hf, array_length (hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_dcerpc_dnsserver(void)
{
dcerpc_init_uuid(proto_dcerpc_dnsserver, ett_dcerpc_dnsserver,
&uuid_dcerpc_dnsserver, ver_dcerpc_dnsserver,
dnsserver_dissectors, hf_dnsserver_opnum);
}
