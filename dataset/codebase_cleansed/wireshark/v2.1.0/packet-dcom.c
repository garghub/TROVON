void dcom_interface_dump(void) {
dcom_machine_t *machine;
dcom_object_t *object;
dcom_interface_t *interf;
GList *machines;
GList *objects;
GList *interfaces;
for(machines = dcom_machines; machines != NULL; machines = g_list_next(machines)) {
machine = (dcom_machine_t *)machines->data;
for(objects = machine->objects; objects != NULL; objects = g_list_next(objects)) {
object = (dcom_object_t *)objects->data;
for(interfaces = object->interfaces; interfaces != NULL; interfaces = g_list_next(interfaces)) {
interf = (dcom_interface_t *)interfaces->data;
}
}
}
}
dcom_interface_t *dcom_interface_find(packet_info *pinfo _U_, const address *addr _U_, e_guid_t *ipid)
{
dcom_interface_t *interf;
GList *interfaces;
if(memcmp(ipid, &uuid_null, sizeof(uuid_null)) == 0)
{
return NULL;
}
for(interfaces = dcom_interfaces; interfaces != NULL; interfaces = g_list_next(interfaces)) {
interf = (dcom_interface_t *)interfaces->data;
if(memcmp(&interf->ipid, ipid, sizeof(e_guid_t)) == 0) {
return interf;
}
}
return NULL;
}
dcom_interface_t *dcom_interface_new(packet_info *pinfo, const address *addr, e_guid_t *iid, guint64 oxid, guint64 oid, e_guid_t *ipid)
{
GList *dcom_iter;
dcom_machine_t *machine;
dcom_object_t *object;
dcom_interface_t *interf;
if( memcmp(iid, &uuid_null, sizeof(uuid_null)) == 0 ||
memcmp(ipid, &uuid_null, sizeof(uuid_null)) == 0)
{
return NULL;
}
if(oxid == 0 || oid == 0) {
interf = wmem_new(wmem_file_scope(), dcom_interface_t);
interf->parent = NULL;
interf->private_data = NULL;
interf->first_packet = pinfo->num;
interf->iid = *iid;
interf->ipid = *ipid;
dcom_interfaces = g_list_append(dcom_interfaces, interf);
return interf;
}
dcom_iter = dcom_machines;
while(dcom_iter != NULL) {
machine = (dcom_machine_t *)dcom_iter->data;
if(cmp_address(&machine->ip, addr) == 0) {
break;
}
dcom_iter = g_list_next(dcom_iter);
}
if(dcom_iter == NULL) {
machine = g_new(dcom_machine_t,1);
copy_address(&machine->ip, addr);
machine->objects = NULL;
machine->first_packet = pinfo->num;
dcom_machines = g_list_append(dcom_machines, machine);
}
dcom_iter = machine->objects;
while(dcom_iter != NULL) {
object = (dcom_object_t *)dcom_iter->data;
if(object->oid == oid) {
break;
}
dcom_iter = g_list_next(dcom_iter);
}
if(dcom_iter == NULL) {
object = g_new(dcom_object_t,1);
object->parent = machine;
object->interfaces = NULL;
object->private_data = NULL;
object->first_packet = pinfo->num;
object->oid = oid;
object->oxid = oxid;
machine->objects = g_list_append(machine->objects, object);
}
dcom_iter = object->interfaces;
while(dcom_iter != NULL) {
interf = (dcom_interface_t *)dcom_iter->data;
if(memcmp(&interf->ipid, ipid, sizeof(e_guid_t)) == 0) {
break;
}
dcom_iter = g_list_next(dcom_iter);
}
if(dcom_iter == NULL) {
interf = g_new(dcom_interface_t,1);
interf->parent = object;
interf->private_data = NULL;
interf->first_packet = pinfo->num;
interf->iid = *iid;
interf->ipid = *ipid;
object->interfaces = g_list_append(object->interfaces, interf);
dcom_interfaces = g_list_append(dcom_interfaces, interf);
}
return interf;
}
static int
dissect_dcom_extent(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep)
{
guint32 u32ArraySize;
guint32 u32ArraySize2;
guint32 u32Pointer;
guint32 u32VariableOffset;
guint32 u32Idx;
guint32 u32SubStart;
proto_item *sub_item;
proto_tree *sub_tree;
guint32 u32ArrayCount;
guint32 u32ArrayRes;
guint32 u32ExtentSize;
e_guid_t uuidExtend;
const char *uuid_name;
offset = dissect_dcom_dcerpc_pointer(tvb, offset, pinfo, tree, di, drep, &u32Pointer);
if (u32Pointer == 0) {
return offset;
}
offset = dissect_dcom_DWORD(tvb, offset, pinfo, tree, di, drep,
hf_dcom_extent_array_count, &u32ArrayCount);
offset = dissect_dcom_DWORD(tvb, offset, pinfo, tree, di, drep,
hf_dcom_extent_array_res, &u32ArrayRes);
offset = dissect_dcom_dcerpc_pointer(tvb, offset, pinfo, tree, di, drep, &u32Pointer);
if (u32Pointer == 0) {
return offset;
}
offset = dissect_dcom_dcerpc_array_size(tvb, offset, pinfo, tree, di, drep,
&u32ArraySize);
u32VariableOffset = offset + u32ArraySize*4;
u32Idx = 1;
while (u32ArraySize--) {
sub_item = proto_tree_add_item(tree, hf_dcom_extent, tvb, offset, 0, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_dcom_extent);
u32SubStart = offset;
offset = dissect_dcom_dcerpc_pointer(tvb, offset, pinfo, sub_tree, di, drep, &u32Pointer);
if(u32Pointer != 0) {
u32VariableOffset = dissect_dcom_DWORD(tvb, u32VariableOffset, pinfo, sub_tree, di, drep,
hf_dcom_extent_size, &u32ExtentSize);
dissect_dcom_UUID(tvb, u32VariableOffset, pinfo, NULL, di, drep,
hf_dcom_extent_id, &uuidExtend);
if((uuid_name = guids_get_uuid_name(&uuidExtend)) != NULL) {
proto_tree_add_guid_format_value(sub_tree, hf_dcom_extent_id, tvb,
offset, sizeof(e_guid_t), (e_guid_t *) &uuidExtend,
"%s (%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x)",
uuid_name,
uuidExtend.data1, uuidExtend.data2, uuidExtend.data3,
uuidExtend.data4[0], uuidExtend.data4[1],
uuidExtend.data4[2], uuidExtend.data4[3],
uuidExtend.data4[4], uuidExtend.data4[5],
uuidExtend.data4[6], uuidExtend.data4[7]);
u32VariableOffset += 16;
} else {
u32VariableOffset = dissect_dcom_UUID(tvb, u32VariableOffset, pinfo, sub_tree, di, drep,
hf_dcom_extent_id, &uuidExtend);
}
u32VariableOffset = dissect_dcom_dcerpc_array_size(tvb, u32VariableOffset, pinfo, sub_tree, di, drep,
&u32ArraySize2);
u32VariableOffset = dissect_dcom_nospec_data(tvb, u32VariableOffset, pinfo, sub_tree, drep, u32ArraySize2);
if(uuid_name != NULL) {
proto_item_append_text(sub_item, "[%u]: %s, Bytes=%u",
u32Idx, uuid_name, u32ArraySize2);
} else {
proto_item_append_text(sub_item, "[%u]: Bytes=%u",
u32Idx, u32ArraySize2);
}
proto_item_set_len(sub_item, offset - u32SubStart);
} else {
proto_item_append_text(sub_item, "[%u]: NULL", u32Idx);
proto_item_set_len(sub_item, offset - u32SubStart);
}
u32Idx++;
}
return u32VariableOffset;
}
int
dissect_dcom_this(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep)
{
guint16 u16VersionMajor;
guint16 u16VersionMinor;
guint32 u32Flags;
guint32 u32Res;
e_guid_t uuidCausality;
proto_item *sub_item;
proto_tree *sub_tree;
guint32 u32SubStart;
proto_item *pi;
sub_item = proto_tree_add_protocol_format(tree, proto_dcom, tvb, offset, 0,
"DCOM, ORPCThis");
sub_tree = proto_item_add_subtree(sub_item, ett_dcom_this);
offset = dissect_dcom_COMVERSION(tvb, offset, pinfo, sub_tree, di, drep,
&u16VersionMajor, &u16VersionMinor);
u32SubStart = offset - 4;
offset = dissect_dcom_DWORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_this_flags, &u32Flags);
offset = dissect_dcom_DWORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_this_res, &u32Res);
offset = dissect_dcom_UUID(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_this_cid, &uuidCausality);
offset = dissect_dcom_extent(tvb, offset, pinfo, sub_tree, di, drep);
proto_item_append_text(sub_item, ", V%u.%u, Causality ID: %s",
u16VersionMajor, u16VersionMinor, guids_resolve_guid_to_str(&uuidCausality));
proto_item_set_len(sub_item, offset - u32SubStart);
if(memcmp(&di->call_data->object_uuid, &uuid_null, sizeof(uuid_null)) != 0) {
pi = proto_tree_add_guid_format(tree, hf_dcom_ipid, tvb, offset, 0,
(e_guid_t *) &di->call_data->object_uuid,
"Object UUID/IPID: %s", guids_resolve_guid_to_str(&di->call_data->object_uuid));
PROTO_ITEM_SET_GENERATED(pi);
}
return offset;
}
int
dissect_dcom_that(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep) {
guint32 u32Flags;
proto_item *sub_item;
proto_tree *sub_tree;
guint32 u32SubStart;
proto_item *pi;
sub_item = proto_tree_add_protocol_format(tree, proto_dcom, tvb, offset, 0,
"DCOM, ORPCThat");
sub_tree = proto_item_add_subtree(sub_item, ett_dcom_that);
offset = dissect_dcom_DWORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_that_flags, &u32Flags);
u32SubStart = offset - 4;
offset = dissect_dcom_extent(tvb, offset, pinfo, sub_tree, di, drep);
proto_item_set_len(sub_item, offset - u32SubStart);
if(memcmp(&di->call_data->object_uuid, &uuid_null, sizeof(uuid_null)) != 0) {
pi = proto_tree_add_guid_format(tree, hf_dcom_ipid, tvb, offset, 0,
(e_guid_t *) &di->call_data->object_uuid,
"Object UUID/IPID: %s", guids_resolve_guid_to_str(&di->call_data->object_uuid));
PROTO_ITEM_SET_GENERATED(pi);
}
return offset;
}
int
dissect_dcom_simple_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep)
{
offset = dissect_dcom_this(tvb, offset, pinfo, tree, di, drep);
return offset;
}
int
dissect_dcom_simple_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep)
{
guint32 u32HResult;
offset = dissect_dcom_that(tvb, offset, pinfo, tree, di, drep);
offset = dissect_dcom_HRESULT(tvb, offset, pinfo, tree, di, drep,
&u32HResult);
col_append_fstr(pinfo->cinfo, COL_INFO, " -> %s",
val_to_str(u32HResult, dcom_hresult_vals, "Unknown (0x%08x)") );
return offset;
}
int
dissect_dcom_dcerpc_array_size(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep, guint32 *pu32ArraySize)
{
if (!dcom_prefs_display_unmarshalling_details) {
tree = NULL;
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_dcom_array_size, pu32ArraySize);
return offset;
}
int
dissect_dcom_dcerpc_pointer(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep, guint32 *pu32Pointer)
{
if (!dcom_prefs_display_unmarshalling_details) {
tree = NULL;
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_dcom_pointer_val, pu32Pointer);
return offset;
}
extern int
dissect_dcom_tobedone_data(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep _U_, int length)
{
proto_item *item;
item = proto_tree_add_item(tree, hf_dcom_tobedone, tvb, offset, length, ENC_NA);
PROTO_ITEM_SET_GENERATED(item);
expert_add_info(pinfo, item, &ei_dcom_dissetion_incomplete);
offset += length;
return offset;
}
extern int
dissect_dcom_nospec_data(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep _U_, int length)
{
proto_item *item;
item = proto_tree_add_item(tree, hf_dcom_nospec, tvb, offset, length, ENC_NA);
PROTO_ITEM_SET_GENERATED(item);
expert_add_info(pinfo, item, &ei_dcom_no_spec);
offset += length;
return offset;
}
int
dissect_dcom_indexed_WORD(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
int hfindex, guint16 * pu16WORD, int field_index)
{
guint16 u16WORD;
dissect_dcom_WORD(tvb, offset, pinfo, NULL , di, drep,
hfindex, &u16WORD);
if (tree) {
proto_tree_add_uint_format(tree, hfindex, tvb, offset, 2, u16WORD,
"%s[%u]: 0x%04x",
proto_registrar_get_name(hfindex),
field_index, u16WORD);
}
offset += 2;
if (pu16WORD)
*pu16WORD = u16WORD;
return offset;
}
int
dissect_dcom_indexed_DWORD(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
int hfindex, guint32 * pu32DWORD, int field_index)
{
guint32 u32DWORD;
dissect_dcom_DWORD(tvb, offset, pinfo, NULL , di, drep,
hfindex, &u32DWORD);
if (tree) {
proto_tree_add_uint_format(tree, hfindex, tvb, offset, 4, u32DWORD,
"%s[%u]: 0x%08x",
proto_registrar_get_name(hfindex),
field_index, u32DWORD);
}
offset += 4;
if (pu32DWORD)
*pu32DWORD = u32DWORD;
return offset;
}
int
dissect_dcom_HRESULT_item(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
guint32 * pu32HResult, int field_index, proto_item **item)
{
guint32 u32HResult;
offset = dissect_dcom_DWORD(tvb, offset, pinfo, NULL , di, drep,
field_index, &u32HResult);
if (tree) {
*item = proto_tree_add_item (tree, field_index, tvb, offset-4, 4, DREP_ENC_INTEGER(drep));
}
if (pu32HResult)
*pu32HResult = u32HResult;
return offset;
}
int
dissect_dcom_HRESULT(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
guint32 * pu32HResult)
{
guint32 u32HResult;
proto_item *item = NULL;
offset = dissect_dcom_DWORD(tvb, offset, pinfo, NULL , di, drep,
hf_dcom_hresult, &u32HResult);
if (tree) {
item = proto_tree_add_item (tree, hf_dcom_hresult, tvb, offset-4, 4, DREP_ENC_INTEGER(drep));
}
if(u32HResult & 0x80000000) {
expert_add_info_format(pinfo, item, &ei_dcom_hresult_expert, "Hresult: %s",
val_to_str(u32HResult, dcom_hresult_vals, "Unknown (0x%x)"));
}
if (pu32HResult)
*pu32HResult = u32HResult;
return offset;
}
int
dissect_dcom_indexed_HRESULT(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
guint32 * pu32HResult, int field_index)
{
guint32 u32HResult;
proto_item *item = NULL;
offset = dissect_dcom_DWORD(tvb, offset, pinfo, NULL , di, drep,
hf_dcom_hresult, &u32HResult);
if (tree) {
item = proto_tree_add_uint_format(tree, hf_dcom_hresult, tvb, offset-4, 4, u32HResult,
"HResult[%u]: %s (0x%08x)", field_index,
val_to_str_const(u32HResult, dcom_hresult_vals, "Unknown"),
u32HResult);
}
if(u32HResult & 0x80000000) {
expert_add_info_format(pinfo, item, &ei_dcom_hresult_expert, "Hresult: %s",
val_to_str(u32HResult, dcom_hresult_vals, "Unknown (0x%x)"));
}
if (pu32HResult)
*pu32HResult = u32HResult;
return offset;
}
int
dissect_dcom_COMVERSION(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
guint16 * pu16VersionMajor, guint16 * pu16VersionMinor)
{
offset = dissect_dcom_WORD(tvb, offset, pinfo, tree, di, drep,
hf_dcom_version_major, pu16VersionMajor);
offset = dissect_dcom_WORD(tvb, offset, pinfo, tree, di, drep,
hf_dcom_version_minor, pu16VersionMinor);
return offset;
}
int
dissect_dcom_SAFEARRAY(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep, int hfindex _U_, sa_callback_t sacb)
{
guint32 u32Dims;
guint16 u16Dims;
guint16 u16Features;
guint32 u32ElementSize;
guint32 u32VarType;
guint32 u32Elements;
guint32 u32Pointer;
guint32 u32BoundElements;
guint32 u32LowBound;
gchar cData[100];
guint32 u32ArraySize;
guint32 u32VariableOffset;
guint32 u32Data;
guint16 u16Data;
guint8 u8Data;
guint16 u16Locks;
guint16 u16VarType;
proto_item *sub_item;
proto_tree *sub_tree;
guint32 u32SubStart;
guint32 u32TmpOffset;
static const int * features[] = {
&hf_dcom_sa_features_variant,
&hf_dcom_sa_features_dispatch,
&hf_dcom_sa_features_unknown,
&hf_dcom_sa_features_bstr,
&hf_dcom_sa_features_have_vartype,
&hf_dcom_sa_features_have_iid,
&hf_dcom_sa_features_record,
&hf_dcom_sa_features_fixedsize,
&hf_dcom_sa_features_embedded,
&hf_dcom_sa_features_static,
&hf_dcom_sa_features_auto,
NULL
};
sub_item = proto_tree_add_item(tree, hf_dcom_safearray, tvb, offset, 0, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_dcom_safearray);
u32SubStart = offset;
offset = dissect_dcom_dcerpc_pointer(tvb, offset, pinfo, sub_tree, di, drep, &u32Pointer);
offset = dissect_dcom_dcerpc_pointer(tvb, offset, pinfo, sub_tree, di, drep, &u32Pointer);
offset = dissect_dcom_DWORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_sa_dims32, &u32Dims);
offset = dissect_dcom_WORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_sa_dims16, &u16Dims);
u32TmpOffset = dissect_dcom_WORD(tvb, offset, pinfo, NULL, di, drep, -1, &u16Features);
proto_tree_add_bitmask_value_with_flags(sub_tree, tvb, offset, hf_dcom_sa_features,
ett_dcom_sa_features, features, u16Features, BMT_NO_APPEND);
offset = u32TmpOffset;
offset = dissect_dcom_DWORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_sa_element_size, &u32ElementSize);
offset = dissect_dcom_WORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_sa_locks, &u16Locks);
offset = dissect_dcom_WORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_sa_vartype16, &u16VarType);
offset = dissect_dcom_DWORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_sa_vartype32, &u32VarType);
offset = dissect_dcom_DWORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_sa_elements, &u32Elements);
offset = dissect_dcom_dcerpc_pointer(tvb, offset, pinfo, sub_tree, di, drep, &u32Pointer);
u32BoundElements = 0;
while(u32Dims--) {
offset = dissect_dcom_DWORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_sa_bound_elements, &u32BoundElements);
offset = dissect_dcom_DWORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_sa_low_bound, &u32LowBound);
}
offset = dissect_dcom_dcerpc_array_size(tvb, offset, pinfo, sub_tree, di, drep, &u32ArraySize);
tvb_ensure_bytes_exist(tvb, offset, u32ArraySize * u32ElementSize);
u32VariableOffset = offset + u32ArraySize * u32ElementSize;
if(sacb) {
sacb(tvb, offset, pinfo, tree, di, drep, u32VarType, u32ArraySize);
}
while(u32ArraySize--) {
switch(u32VarType) {
case(WIRESHARK_VT_ERROR):
offset = dissect_dcom_HRESULT(tvb, offset, pinfo, sub_tree, di, drep,
&u32Data);
break;
case(WIRESHARK_VT_I1):
offset = dissect_dcom_BYTE(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_vt_i1, &u8Data);
break;
case(WIRESHARK_VT_I2):
offset = dissect_dcom_WORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_vt_i2, &u16Data);
break;
case(WIRESHARK_VT_I4):
offset = dissect_dcom_DWORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_vt_i4, &u32Data);
break;
case(WIRESHARK_VT_I8):
offset = dissect_dcom_I8(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_vt_i8, NULL);
u32VariableOffset = offset;
break;
case(WIRESHARK_VT_BSTR):
offset = dissect_dcom_dcerpc_pointer(tvb, offset, pinfo, sub_tree, di, drep, &u32Pointer);
if (u32Pointer) {
u32VariableOffset = dissect_dcom_BSTR(tvb, u32VariableOffset, pinfo, sub_tree, di, drep,
hf_dcom_vt_bstr, cData, sizeof(cData) );
}
break;
default:
u32VariableOffset = dissect_dcom_tobedone_data(tvb, u32VariableOffset, pinfo, sub_tree, drep,
10000);
}
}
proto_item_append_text(sub_item, ": Elements: %u/%u VarType: %s",
u32Elements, u32BoundElements,
val_to_str(u32VarType, dcom_variant_type_vals, "Unknown (0x%08x)") );
proto_item_set_len(sub_item, u32VariableOffset - u32SubStart);
return u32VariableOffset;
}
int
dissect_dcom_VARTYPE(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
guint16 *pu16VarType)
{
offset = dissect_dcom_WORD(tvb, offset, pinfo, tree, di, drep,
hf_dcom_variant_type, pu16VarType);
return offset;
}
int
dissect_dcom_VARIANT(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep, int hfindex)
{
guint32 u32Size;
guint32 u32RPCRes;
guint16 u16Res;
guint32 u32SubStart;
proto_item *sub_item;
proto_tree *sub_tree;
guint16 u16VarType;
guint32 u32VarType;
guint8 u8Data;
guint16 u16Data;
guint32 u32Data;
guint64 u64Data;
gint64 cyData;
gchar cData[500];
guint32 u32Pointer;
gfloat f32Data;
gdouble f64Data;
if (offset % 8) {
offset += 8 - (offset % 8);
}
sub_item = proto_tree_add_item(tree, hfindex, tvb, offset, 0, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(sub_item, ett_dcom_variant);
u32SubStart = offset;
offset = dissect_dcom_DWORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_variant_size, &u32Size);
offset = dissect_dcom_DWORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_variant_rpc_res, &u32RPCRes);
offset = dissect_dcom_VARTYPE(tvb, offset, pinfo, sub_tree, di, drep,
&u16VarType);
offset = dissect_dcom_WORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_variant_wres, &u16Res);
offset = dissect_dcom_WORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_variant_wres, &u16Res);
offset = dissect_dcom_WORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_variant_wres, &u16Res);
offset = dissect_dcom_DWORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_variant_type32, &u32VarType);
if (u32VarType & WIRESHARK_VT_BYREF) {
u32VarType &=~WIRESHARK_VT_BYREF;
offset = dissect_dcom_dcerpc_pointer(tvb, offset, pinfo, sub_tree, di, drep, &u32Pointer);
}
switch (u32VarType) {
case(WIRESHARK_VT_EMPTY):
break;
case(WIRESHARK_VT_BOOL):
offset = dissect_dcom_VARIANT_BOOL(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_vt_bool, &u16Data);
break;
case(WIRESHARK_VT_I1):
offset = dissect_dcom_BYTE(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_vt_i1, &u8Data);
break;
case(WIRESHARK_VT_UI1):
offset = dissect_dcom_BYTE(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_vt_ui1, &u8Data);
break;
case(WIRESHARK_VT_I2):
offset = dissect_dcom_WORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_vt_i2, &u16Data);
break;
case(WIRESHARK_VT_UI2):
offset = dissect_dcom_WORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_vt_ui2, &u16Data);
break;
case(WIRESHARK_VT_I4):
offset = dissect_dcom_DWORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_vt_i4, &u32Data);
break;
case(WIRESHARK_VT_I8):
offset = dissect_dcom_I8(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_vt_i8, &u64Data);
break;
case(WIRESHARK_VT_CY):
offset = dissect_dcom_I8(tvb, offset, pinfo, NULL, di, drep,
0, &cyData);
proto_tree_add_int64_format(sub_tree, hf_dcom_vt_cy, tvb, offset - 8,
8, cyData, "%s: %" G_GINT64_FORMAT ".%.04" G_GINT64_FORMAT,
proto_registrar_get_name(hf_dcom_vt_cy),
cyData / 10000, ABS(cyData % 10000));
break;
case(WIRESHARK_VT_UI4):
offset = dissect_dcom_DWORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_vt_ui4, &u32Data);
break;
case(WIRESHARK_VT_UI8):
offset = dissect_dcom_I8(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_vt_ui8, &u64Data);
break;
case(WIRESHARK_VT_R4):
offset = dissect_dcom_FLOAT(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_vt_r4, &f32Data);
break;
case(WIRESHARK_VT_R8):
offset = dissect_dcom_DOUBLE(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_vt_r8, &f64Data);
break;
case(WIRESHARK_VT_DATE):
offset = dissect_dcom_DATE(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_vt_date, &f64Data);
break;
case(WIRESHARK_VT_BSTR):
offset = dissect_dcom_dcerpc_pointer(tvb, offset, pinfo, sub_tree, di, drep, &u32Pointer);
if (u32Pointer) {
offset = dissect_dcom_BSTR(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_vt_bstr, cData, sizeof(cData) );
}
break;
case(WIRESHARK_VT_DISPATCH):
offset = dissect_dcom_dcerpc_pointer(tvb, offset, pinfo, sub_tree, di, drep, &u32Pointer);
if (u32Pointer) {
offset = dissect_dcom_MInterfacePointer(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_vt_dispatch, NULL);
}
break;
case(WIRESHARK_VT_ARRAY):
offset = dissect_dcom_SAFEARRAY(tvb, offset, pinfo, sub_tree, di, drep,
0, NULL);
break;
case(WIRESHARK_VT_ERROR):
offset = dissect_dcom_HRESULT(tvb, offset, pinfo, sub_tree, di, drep,
0);
break;
case(WIRESHARK_VT_VARIANT):
offset = dissect_dcom_dcerpc_pointer(tvb, offset, pinfo, sub_tree, di, drep, &u32Pointer);
if (u32Pointer) {
offset = dissect_dcom_VARIANT(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_vt_byref );
}
break;
case(WIRESHARK_VT_UNKNOWN):
offset = dissect_dcom_dcerpc_pointer(tvb, offset, pinfo, sub_tree, di, drep, &u32Pointer);
break;
default:
offset = dissect_dcom_tobedone_data(tvb, offset, pinfo, sub_tree, drep,
10000);
}
proto_item_append_text(sub_item, ": %s",
val_to_str(u16VarType, dcom_variant_type_vals, "Unknown (0x%08x)") );
proto_item_set_len(sub_item, offset - u32SubStart);
return offset;
}
int
dissect_dcom_UUID(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep,
int hfindex, e_guid_t *pdata)
{
const gchar *uuid_name;
header_field_info *hfi;
e_guid_t uuid;
offset = dissect_ndr_uuid_t(tvb, offset, pinfo, NULL, di, drep,
hfindex, &uuid);
hfi = proto_registrar_get_nth(hfindex);
uuid_name = guids_get_uuid_name(&uuid);
if(uuid_name) {
proto_tree_add_guid_format(tree, hfindex, tvb, offset-16, 16, (e_guid_t *) &uuid,
"%s: %s (%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x)",
hfi->name, uuid_name,
uuid.data1, uuid.data2, uuid.data3,
uuid.data4[0], uuid.data4[1],
uuid.data4[2], uuid.data4[3],
uuid.data4[4], uuid.data4[5],
uuid.data4[6], uuid.data4[7]);
} else {
proto_tree_add_guid_format(tree, hfindex, tvb, offset-16, 16, (e_guid_t *) &uuid,
"%s: %08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
hfi->name,
uuid.data1, uuid.data2, uuid.data3,
uuid.data4[0], uuid.data4[1],
uuid.data4[2], uuid.data4[3],
uuid.data4[4], uuid.data4[5],
uuid.data4[6], uuid.data4[7]);
}
if(pdata != NULL) {
*pdata = uuid;
}
return offset;
}
int
dissect_dcom_append_UUID(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep,
int hfindex, int field_index, e_guid_t *uuid)
{
const gchar *uuid_name;
proto_item *pi;
header_field_info *hfi;
offset = dissect_ndr_uuid_t(tvb, offset, pinfo, NULL, di, drep,
hfindex, uuid);
uuid_name = guids_get_uuid_name(uuid);
hfi = proto_registrar_get_nth(hfindex);
pi = proto_tree_add_guid_format(tree, hfindex, tvb, offset-16, 16, (e_guid_t *) uuid, "%s", hfi->name);
if (field_index != -1) {
proto_item_append_text(pi, "[%u]: ", field_index);
} else {
proto_item_append_text(pi, ": ");
}
if(uuid_name) {
proto_item_append_text(pi, "%s (", uuid_name);
}
proto_item_append_text(pi, "%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
uuid->data1, uuid->data2, uuid->data3,
uuid->data4[0], uuid->data4[1],
uuid->data4[2], uuid->data4[3],
uuid->data4[4], uuid->data4[5],
uuid->data4[6], uuid->data4[7]);
if(uuid_name) {
proto_item_append_text(pi, ")");
}
if (field_index != -1) {
col_append_fstr(pinfo->cinfo, COL_INFO, " %s[%u]=%s",
hfi->name, field_index, (uuid_name) ? uuid_name : "???");
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, " %s=%s",
hfi->name, (uuid_name) ? uuid_name : "???");
}
return offset;
}
static int
dcom_tvb_get_nwstringz0(tvbuff_t *tvb, gint offset, guint32 inLength, gchar *pszStr, guint32 outLength, gboolean *isPrintable)
{
guint32 u32Idx;
guint32 u32IdxA;
guint32 u32IdxW;
guint32 inLengthWithoutNullDelimiter = 0;
guint8 u8Tmp1;
guint8 u8Tmp2;
*isPrintable = TRUE;
inLengthWithoutNullDelimiter = inLength == 0 ? 0 : inLength -1;
DISSECTOR_ASSERT(outLength >= 1);
for(u32Idx = 0; u32Idx < inLengthWithoutNullDelimiter; u32Idx+=2) {
u8Tmp1 = tvb_get_guint8(tvb, offset+u32Idx);
u8Tmp2 = tvb_get_guint8(tvb, offset+u32Idx+1);
if (u8Tmp1 == 0 && u8Tmp2 == 0) {
u32Idx+=2;
break;
}
if(!(g_ascii_isprint(u8Tmp1) || u8Tmp1 == 10 || u8Tmp1 == 13)|| u8Tmp2 != 0) {
*isPrintable = FALSE;
}
}
if(*isPrintable == TRUE) {
for(u32IdxA = 0, u32IdxW = 0;
u32IdxW < u32Idx && u32IdxA < outLength-2;
u32IdxW+=2, u32IdxA++) {
pszStr[u32IdxA] = tvb_get_guint8(tvb, offset+u32IdxW);
}
} else {
for(u32IdxA = 0, u32IdxW = 0;
u32IdxW < u32Idx && u32IdxA < outLength-2;
u32IdxW++, u32IdxA+=2) {
g_snprintf(&pszStr[u32IdxA], 3, "%02X", tvb_get_guint8(tvb, offset+u32IdxW));
}
}
DISSECTOR_ASSERT(u32IdxA < outLength);
pszStr[u32IdxA] = 0;
return offset + u32Idx;
}
int
dissect_dcom_indexed_LPWSTR(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep, int hfindex,
gchar *pszStr, guint32 u32MaxStr, int field_index)
{
guint32 u32MaxCount;
guint32 u32Offset;
guint32 u32ArraySize;
guint32 u32StrStart;
proto_item *sub_item;
proto_tree *sub_tree;
guint32 u32SubStart;
gboolean isPrintable;
if (offset % 4) {
offset += 4 - (offset % 4);
}
sub_item = proto_tree_add_string(tree, hfindex, tvb, offset, 0, "");
sub_tree = proto_item_add_subtree(sub_item, ett_dcom_lpwstr);
u32SubStart = offset;
offset = dissect_dcom_DWORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_max_count, &u32MaxCount);
offset = dissect_dcom_DWORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_offset, &u32Offset);
offset = dissect_dcom_dcerpc_array_size(tvb, offset, pinfo, sub_tree, di, drep,
&u32ArraySize);
u32StrStart = offset;
offset = dcom_tvb_get_nwstringz0(tvb, offset, u32ArraySize*2, pszStr, u32MaxStr, &isPrintable);
proto_tree_add_string(sub_tree, hfindex, tvb, u32StrStart, offset - u32StrStart, pszStr);
if (field_index != -1) {
proto_item_set_text(sub_item, "%s[%u]: %s%s%s",
proto_registrar_get_name(hfindex),
field_index,
isPrintable ? "\"" : "", pszStr, isPrintable ? "\"" : "");
} else {
proto_item_append_text(sub_item, "%s%s%s",
isPrintable ? "\"" : "", pszStr, isPrintable ? "\"" : "");
}
proto_item_set_len(sub_item, offset - u32SubStart);
return offset;
}
int
dissect_dcom_LPWSTR(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep, int hfindex,
gchar *pszStr, guint32 u32MaxStr)
{
return dissect_dcom_indexed_LPWSTR(tvb, offset, pinfo, tree, di, drep,
hfindex, pszStr, u32MaxStr, -1);
}
int
dissect_dcom_BSTR(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep, int hfindex,
gchar *pszStr, guint32 u32MaxStr)
{
guint32 u32MaxCount;
guint32 u32ArraySize;
gint strStart, subStart, realOffset;
proto_item *sub_item;
proto_tree *sub_tree;
guint32 u32ByteLength;
gboolean isPrintable;
if (offset % 4) {
offset += 4 - (offset % 4);
}
sub_item = proto_tree_add_string(tree, hfindex, tvb, offset, 0, "");
sub_tree = proto_item_add_subtree(sub_item, ett_dcom_lpwstr);
subStart = offset;
offset = dissect_dcom_DWORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_max_count, &u32MaxCount);
offset = dissect_dcom_DWORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_byte_length, &u32ByteLength);
offset = dissect_dcom_dcerpc_array_size(tvb, offset, pinfo, sub_tree, di, drep,
&u32ArraySize);
if ((guint32)offset + u32ArraySize*2 > G_MAXINT)
return offset;
realOffset = offset + u32ArraySize*2;
strStart = offset;
offset = dcom_tvb_get_nwstringz0(tvb, offset, u32ArraySize*2, pszStr, u32MaxStr, &isPrintable);
proto_tree_add_string(sub_tree, hfindex, tvb, strStart, offset - strStart, pszStr);
proto_item_append_text(sub_item, "%s%s%s",
isPrintable ? "\"" : "", pszStr, isPrintable ? "\"" : "");
if (realOffset <= subStart) {
return offset;
}
proto_item_set_len(sub_item, realOffset - subStart);
return realOffset;
}
int
dissect_dcom_DUALSTRINGARRAY(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep, int hfindex, gchar *ip)
{
guint16 u16NumEntries;
guint16 u16SecurityOffset;
gchar szStr[1000];
guint32 u32MaxStr = sizeof(szStr);
guint32 u32Start;
guint16 u16TowerId;
guint16 u16SecurityAuthnSvc;
guint16 u16SecurityAuthzSvc;
proto_item *sub_item;
proto_tree *sub_tree;
guint32 u32SubStart;
guint32 u32StringBindings = 0;
guint32 u32SecurityBindings = 0;
proto_item *subsub_item;
proto_tree *subsub_tree;
guint32 u32SubSubStart;
gboolean isPrintable;
guint32 first_ip = 0;
guint32 curr_ip = 0;
struct in_addr ipaddr;
proto_item *pi;
sub_item = proto_tree_add_item(tree, hfindex, tvb, offset, 0, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(sub_item, ett_dcom_dualstringarray);
offset = dissect_dcom_WORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_dualstringarray_num_entries, &u16NumEntries);
u32SubStart = offset - 2;
offset = dissect_dcom_WORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_dualstringarray_security_offset, &u16SecurityOffset);
while ( tvb_get_ntohs(tvb, offset) ) {
u32StringBindings++;
subsub_item = proto_tree_add_item(sub_tree, hf_dcom_dualstringarray_string, tvb, offset, 0, ENC_NA);
subsub_tree = proto_item_add_subtree(subsub_item, ett_dcom_dualstringarray_binding);
u32SubSubStart = offset;
offset = dissect_dcom_WORD(tvb, offset, pinfo, subsub_tree, di, drep,
hf_dcom_dualstringarray_string_tower_id, &u16TowerId);
u32Start = offset;
offset = dcom_tvb_get_nwstringz0(tvb, offset, u32MaxStr, szStr, u32MaxStr, &isPrintable);
pi = proto_tree_add_string(subsub_tree, hf_dcom_dualstringarray_string_network_addr,
tvb, u32Start, offset - u32Start, szStr);
if (inet_aton(szStr, &ipaddr)) {
if(get_host_ipaddr(szStr, &curr_ip)) {
if(first_ip == 0) {
if(ip != NULL) {
memcpy(ip, &curr_ip, sizeof(curr_ip));
}
first_ip = curr_ip;
} else {
if(first_ip != curr_ip) {
address first_ip_addr, curr_ip_addr;
set_address(&first_ip_addr, AT_IPv4, 4, &first_ip);
set_address(&curr_ip_addr, AT_IPv4, 4, &curr_ip);
expert_add_info_format(pinfo, pi, &ei_dcom_dualstringarray_mult_ip,
"DUALSTRINGARRAY: multiple IP's %s %s",
address_to_str(wmem_packet_scope(), &first_ip_addr), address_to_str(wmem_packet_scope(), &curr_ip_addr));
}
}
}
}
proto_item_append_text(subsub_item, "[%u]: TowerId=%s, NetworkAddr=\"%s\"",
u32StringBindings,
val_to_str(u16TowerId, dcom_protseq_vals, "Unknown (0x%04x"),
szStr);
proto_item_set_len(subsub_item, offset - u32SubSubStart);
}
offset += 2;
while ( tvb_get_ntohs(tvb, offset) ) {
u32SecurityBindings++;
subsub_item = proto_tree_add_item(sub_tree, hf_dcom_dualstringarray_security, tvb, offset, 0, ENC_NA);
subsub_tree = proto_item_add_subtree(subsub_item, ett_dcom_dualstringarray_binding);
u32SubSubStart = offset;
offset = dissect_dcom_WORD(tvb, offset, pinfo, subsub_tree, di, drep,
hf_dcom_dualstringarray_security_authn_svc,
&u16SecurityAuthnSvc);
offset = dissect_dcom_WORD(tvb, offset, pinfo, subsub_tree, di, drep,
hf_dcom_dualstringarray_security_authz_svc,
&u16SecurityAuthzSvc);
u32Start = offset;
offset = dcom_tvb_get_nwstringz0(tvb, offset, u32MaxStr, szStr, u32MaxStr, &isPrintable);
proto_tree_add_string(subsub_tree, hf_dcom_dualstringarray_security_princ_name,
tvb, u32Start, offset - u32Start, szStr);
proto_item_append_text(subsub_item, "[%u]: AuthnSvc=0x%04x, AuthzSvc=0x%04x, PrincName=\"%s\"",
u32SecurityBindings, u16SecurityAuthnSvc, u16SecurityAuthzSvc, szStr);
proto_item_set_len(subsub_item, offset - u32SubSubStart);
}
offset += 2;
proto_item_append_text(sub_item, ": STRINGBINDINGs=%u, SECURITYBINDINGs=%u",
u32StringBindings, u32SecurityBindings);
proto_item_set_len(sub_item, offset - u32SubStart);
return offset;
}
int
dissect_dcom_STDOBJREF(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep, int hfindex _U_,
guint64 *oxid, guint64 *oid, e_guid_t *ipid)
{
guint32 u32Flags;
guint32 u32PublicRefs;
proto_item *sub_item;
proto_tree *sub_tree;
guint32 u32SubStart;
sub_item = proto_tree_add_item(tree, hf_dcom_stdobjref, tvb, offset, 0, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_dcom_stdobjref);
offset = dissect_dcom_DWORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_stdobjref_flags, &u32Flags);
u32SubStart = offset - 4;
offset = dissect_dcom_DWORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_stdobjref_public_refs, &u32PublicRefs);
offset = dissect_dcom_ID(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_oxid, oxid);
offset = dissect_dcom_ID(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_oid, oid);
offset = dissect_dcom_UUID(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_ipid, ipid);
proto_item_append_text(sub_item, ": PublicRefs=%u IPID=%s",
u32PublicRefs, guids_resolve_guid_to_str(ipid));
proto_item_set_len(sub_item, offset - u32SubStart);
return offset;
}
int
dcom_register_rountine(dcom_dissect_fn_t routine, e_guid_t* uuid)
{
dcom_marshaler_t *marshaler;
if (dcom_get_rountine_by_uuid(uuid))
return -1;
marshaler = wmem_new(wmem_file_scope(), dcom_marshaler_t);
if (!marshaler) {
return -1;
}
marshaler->parent = NULL;
marshaler->private_data = NULL;
marshaler->uuid = *uuid;
marshaler->routine = routine;
dcom_marshalers = g_list_append(dcom_marshalers, marshaler);
return 0;
}
dcom_dissect_fn_t
dcom_get_rountine_by_uuid(const e_guid_t* uuid)
{
dcom_marshaler_t *marsh;
GList *marshalers;
if(memcmp(uuid, &uuid_null, sizeof(uuid_null)) == 0) {
return NULL;
}
for(marshalers = dcom_marshalers; marshalers!= NULL;
marshalers = g_list_next(marshalers)) {
marsh = (dcom_marshaler_t *)marshalers->data;
if(memcmp(&marsh->uuid, uuid, sizeof(e_guid_t)) == 0) {
return marsh->routine;
}
}
return NULL;
}
static int
dissect_dcom_CUSTOBJREF(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep, int hfindex,
e_guid_t *clsid, e_guid_t *iid)
{
guint32 u32CBExtension;
guint32 u32Size;
guint32 u32SubStart;
proto_item *sub_item;
proto_tree *sub_tree;
dcom_dissect_fn_t routine = NULL;
hfindex = hf_dcom_custobjref;
sub_item = proto_tree_add_item(tree, hfindex, tvb, offset, 0, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_dcom_custobjref);
u32SubStart = offset;
offset = dissect_dcom_UUID(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_clsid, clsid);
offset = dissect_dcom_DWORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_objref_cbextension, &u32CBExtension);
offset = dissect_dcom_DWORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_objref_size, &u32Size);
routine = dcom_get_rountine_by_uuid(iid);
if (routine){
offset = routine(tvb, offset, pinfo, sub_tree, di, drep, 0);
}
proto_item_set_len(sub_item, offset - u32SubStart);
return offset;
}
int
dissect_dcom_OBJREF(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep, int hfindex, dcom_interface_t **interf)
{
guint32 u32Signature;
guint32 u32Flags;
e_guid_t iid;
e_guid_t clsid;
proto_item *sub_item;
proto_tree *sub_tree;
guint32 u32SubStart;
guint64 oxid = 0;
guint64 oid = 0;
e_guid_t ipid;
dcom_interface_t *dcom_if = NULL;
gchar ip[4];
memset(&ipid, 0, sizeof(ipid));
memset(ip, 0, sizeof(ip));
sub_item = proto_tree_add_item(tree, hf_dcom_objref, tvb, offset, 0, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_dcom_objref);
offset = dissect_dcom_DWORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_objref_signature, &u32Signature);
u32SubStart = offset - 4;
offset = dissect_dcom_DWORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_objref_flags, &u32Flags);
offset = dissect_dcom_UUID(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_iid, &iid);
switch(u32Flags) {
case(0x1):
offset = dissect_dcom_STDOBJREF(tvb, offset, pinfo, sub_tree, di, drep, hfindex,
&oxid, &oid, &ipid);
offset = dissect_dcom_DUALSTRINGARRAY(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_objref_resolver_address, ip);
break;
case(0x2):
offset = dissect_dcom_STDOBJREF(tvb, offset, pinfo, sub_tree, di, drep, hfindex,
&oxid, &oid, &iid);
offset = dissect_dcom_UUID(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_clsid, &clsid);
offset = dissect_dcom_DUALSTRINGARRAY(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_objref_resolver_address, ip);
break;
case(0x4):
offset = dissect_dcom_CUSTOBJREF(tvb, offset, pinfo, sub_tree, di, drep, hfindex,
&clsid, &iid);
break;
}
if(u32Flags == 0x1 || u32Flags == 0x2) {
if(pinfo->net_src.type == AT_IPv4) {
address addr;
set_address(&addr, AT_IPv4, 4, ip);
dcom_if = dcom_interface_new(pinfo,
&addr,
&iid, oxid, oid, &ipid);
}
}
if(interf != NULL) {
*interf = dcom_if;
}
proto_item_set_len(sub_item, offset - u32SubStart);
return offset;
}
int
dissect_dcom_MInterfacePointer(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep, int hfindex, dcom_interface_t **interf)
{
guint32 u32CntData;
guint32 u32ArraySize;
proto_item *sub_item;
proto_tree *sub_tree;
guint32 u32SubStart;
if (!hfindex) {
hfindex = hf_dcom_interface_pointer;
}
sub_item = proto_tree_add_item(tree, hfindex, tvb, offset, 0, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(sub_item, ett_dcom_interface_pointer);
offset = dissect_dcom_dcerpc_array_size(tvb, offset, pinfo, sub_tree, di, drep, &u32ArraySize);
u32SubStart = offset - 4;
offset = dissect_dcom_DWORD(tvb, offset, pinfo, sub_tree, di, drep,
hf_dcom_ip_cnt_data, &u32CntData);
offset = dissect_dcom_OBJREF(tvb, offset, pinfo, sub_tree, di, drep, hfindex, interf);
proto_item_set_len(sub_item, offset - u32SubStart);
return offset;
}
int
dissect_dcom_PMInterfacePointer(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep, int hfindex, dcom_interface_t **interf)
{
guint32 u32Pointer;
offset = dissect_dcom_dcerpc_pointer(tvb, offset, pinfo, tree, di, drep, &u32Pointer);
if (u32Pointer) {
offset = dissect_dcom_MInterfacePointer(tvb, offset, pinfo, tree, di, drep, hfindex, interf);
} else {
if(interf != NULL) {
*interf = NULL;
}
}
return offset;
}
static void dcom_cleanup(void) {
if (dcom_machines != NULL) {
GList *machines;
for(machines = dcom_machines; machines != NULL; machines = g_list_next(machines)) {
dcom_machine_t *machine = (dcom_machine_t *)machines->data;
if (machine->objects != NULL) {
GList *objects;
for(objects = machine->objects; objects != NULL; objects = g_list_next(objects)) {
dcom_object_t *object = (dcom_object_t *)objects->data;
if (object->interfaces != NULL) {
GList *interface;
for(interface = object->interfaces; interface != NULL; interface = g_list_next(interface)) {
g_free(interface->data);
interface->data = NULL;
}
g_list_free(object->interfaces);
object->interfaces = NULL;
}
g_free(objects->data);
objects->data = NULL;
}
g_list_free(machine->objects);
free_address(&machine->ip);
machine->objects = NULL;
}
g_free(machines->data);
machines->data = NULL;
}
g_list_free(dcom_machines);
dcom_machines = NULL;
}
if (dcom_interfaces != NULL) {
g_list_free(dcom_interfaces);
dcom_interfaces = NULL;
}
}
void
proto_register_dcom (void)
{
static hf_register_info hf_dcom_this_array[] = {
#if 0
{ &hf_dcom_this_version_major,
{ "VersionMajor", "dcom.this.version_major", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
#endif
#if 0
{ &hf_dcom_this_version_minor,
{ "VersionMinor", "dcom.this.version_minor", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
#endif
{ &hf_dcom_this_flags,
{ "Flags", "dcom.this.flags", FT_UINT32, BASE_HEX, VALS(dcom_thisthat_flag_vals), 0x0, NULL, HFILL }},
{ &hf_dcom_this_res,
{ "Reserved", "dcom.this.res", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_this_cid,
{ "Causality ID", "dcom.this.uuid", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL }}
};
static hf_register_info hf_dcom_that_array[] = {
{ &hf_dcom_that_flags,
{ "Flags", "dcom.that.flags", FT_UINT32, BASE_HEX, VALS(dcom_thisthat_flag_vals), 0x0, NULL, HFILL }}
};
static hf_register_info hf_dcom_extent_array[] = {
{ &hf_dcom_extent,
{ "Extension", "dcom.extent", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_extent_array_count,
{ "Extension Count", "dcom.extent.array_count", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_extent_array_res,
{ "Reserved", "dcom.extent.array_res", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_extent_size,
{ "Extension Size", "dcom.extent.size", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_extent_id,
{ "Extension Id", "dcom.extent.id", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL }}
};
static hf_register_info hf_dcom_array[] = {
{ &hf_dcom_version_major,
{ "VersionMajor", "dcom.version_major", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_version_minor,
{ "VersionMinor", "dcom.version_minor", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_hresult,
{ "HResult", "dcom.hresult", FT_UINT32, BASE_HEX, VALS(dcom_hresult_vals), 0x0, NULL, HFILL }},
{ &hf_dcom_max_count,
{ "MaxCount", "dcom.max_count", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_offset,
{ "Offset", "dcom.offset", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_byte_length,
{ "ByteLength", "dcom.byte_length", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
#if 0
{ &hf_dcom_actual_count,
{ "ActualCount", "dcom.actual_count", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
#endif
{ &hf_dcom_tobedone,
{ "To Be Done", "dcom.tobedone", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_nospec,
{ "No Specification Available", "dcom.nospec", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
#if 0
{ &hf_dcom_variant,
{ "Variant", "dcom.variant", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
#endif
{ &hf_dcom_variant_type,
{ "VarType", "dcom.variant_type", FT_UINT16, BASE_HEX, VALS(dcom_variant_type_vals), 0x0, NULL, HFILL }},
{ &hf_dcom_variant_type32,
{ "VarType32", "dcom.variant_type32", FT_UINT32, BASE_HEX, VALS(dcom_variant_type_vals), 0x0, NULL, HFILL }},
{ &hf_dcom_variant_size,
{ "Size", "dcom.variant_size", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_variant_rpc_res,
{ "RPC-Reserved", "dcom.variant_rpc_res", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_variant_wres,
{ "Reserved", "dcom.variant_wres", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_array_size,
{ "(ArraySize)", "dcom.array_size", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_pointer_val,
{ "(PointerVal)", "dcom.pointer_val", FT_UINT32, BASE_HEX, VALS(dcom_dcerpc_pointer_vals), 0x0, NULL, HFILL }}
};
static hf_register_info hf_dcom_interface_pointer_array[] = {
{ &hf_dcom_interface_pointer,
{ "InterfacePointer", "dcom.ifp", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_ip_cnt_data,
{ "CntData", "dcom.ip_cnt_data", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }}
};
static hf_register_info hf_dcom_objref_array[] = {
{ &hf_dcom_objref,
{ "OBJREF", "dcom.objref", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_objref_signature,
{ "Signature", "dcom.objref.signature", FT_UINT32, BASE_HEX, VALS(dcom_objref_signature_vals), 0x0, NULL, HFILL }},
{ &hf_dcom_objref_flags,
{ "Flags", "dcom.objref.flags", FT_UINT32, BASE_HEX, VALS(dcom_objref_flag_vals), 0x0, NULL, HFILL }},
{ &hf_dcom_iid,
{ "IID", "dcom.iid", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_clsid,
{ "CLSID", "dcom.clsid", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_objref_resolver_address,
{ "ResolverAddress", "dcom.objref.resolver_address", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_objref_cbextension,
{ "CBExtension", "dcom.objref.cbextension", FT_UINT32, BASE_DEC, NULL, 0x0, "Size of extension data", HFILL }},
{ &hf_dcom_objref_size,
{ "Size", "dcom.objref.size", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }}
};
static hf_register_info hf_dcom_stdobjref_array[] = {
{ &hf_dcom_stdobjref,
{ "STDOBJREF", "dcom.stdobjref", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_stdobjref_flags,
{ "Flags", "dcom.stdobjref.flags", FT_UINT32, BASE_HEX, VALS(dcom_stdobjref_flag_vals), 0x0, NULL, HFILL }},
{ &hf_dcom_stdobjref_public_refs,
{ "PublicRefs", "dcom.stdobjref.public_refs", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_oxid,
{ "OXID", "dcom.oxid", FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_oid,
{ "OID", "dcom.oid", FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_ipid,
{ "IPID", "dcom.ipid", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL }}
};
static hf_register_info hf_dcom_custobjref_array[] = {
{ &hf_dcom_custobjref,
{ "CUSTOMOBJREF", "dcom.custobjref", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
static hf_register_info hf_dcom_dualstringarray_array[] = {
{ &hf_dcom_dualstringarray_num_entries,
{ "NumEntries", "dcom.dualstringarray.num_entries", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_dualstringarray_security_offset,
{ "SecurityOffset", "dcom.dualstringarray.security_offset", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_dualstringarray_string,
{ "StringBinding", "dcom.dualstringarray.string", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_dualstringarray_string_tower_id,
{ "TowerId", "dcom.dualstringarray.tower_id", FT_UINT16, BASE_HEX, VALS(dcom_protseq_vals), 0x0, NULL, HFILL }},
{ &hf_dcom_dualstringarray_string_network_addr,
{ "NetworkAddr", "dcom.dualstringarray.network_addr", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_dualstringarray_security,
{ "SecurityBinding", "dcom.dualstringarray.security", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_dualstringarray_security_authn_svc,
{ "AuthnSvc", "dcom.dualstringarray.security_authn_svc", FT_UINT16, BASE_HEX, VALS(dcom_dualstringarray_authn), 0x0, NULL, HFILL }},
{ &hf_dcom_dualstringarray_security_authz_svc,
{ "AuthzSvc", "dcom.dualstringarray.security_authz_svc", FT_UINT16, BASE_HEX, VALS(dcom_dualstringarray_authz), 0x0, NULL, HFILL }},
{ &hf_dcom_dualstringarray_security_princ_name,
{ "PrincName", "dcom.dualstringarray.security_princ_name", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }}
};
static hf_register_info hf_dcom_vt_array[] = {
{ &hf_dcom_vt_bool,
{ "VT_BOOL", "dcom.vt.bool", FT_UINT16, BASE_HEX, VALS(dcom_vt_bool_vals), 0x0, NULL, HFILL }},
{ &hf_dcom_vt_i1,
{ "VT_I1", "dcom.vt.i1", FT_INT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_vt_i2,
{ "VT_I2", "dcom.vt.i2", FT_INT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_vt_i4,
{ "VT_I4", "dcom.vt.i4", FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_vt_i8,
{ "VT_I8", "dcom.vt.i8", FT_INT64, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_vt_cy,
{ "VT_CY", "dcom.vt.cy", FT_INT64, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_vt_ui1,
{ "VT_UI1", "dcom.vt.ui1", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_vt_ui2,
{ "VT_UI2", "dcom.vt.ui2", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_vt_ui4,
{ "VT_UI4", "dcom.vt.ui4", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_vt_ui8,
{ "VT_UI8", "dcom.vt.ui8", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_vt_r4,
{ "VT_R4", "dcom.vt.r4", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_vt_r8,
{ "VT_R8", "dcom.vt.r8", FT_DOUBLE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_vt_date,
{ "VT_DATE", "dcom.vt.date", FT_DOUBLE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_vt_bstr,
{ "VT_BSTR", "dcom.vt.bstr", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_vt_byref,
{ "BYREF", "dcom.vt.byref", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_vt_dispatch,
{ "VT_DISPATCH", "dcom.vt.dispatch", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }}
};
static hf_register_info hf_dcom_sa_array[] = {
{ &hf_dcom_safearray,
{ "SAFEARRAY", "dcom.sa", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_sa_dims32,
{ "Dims32", "dcom.sa.dims32", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_sa_dims16,
{ "Dims16", "dcom.sa.dims16", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_sa_features,
{ "Features", "dcom.sa.features", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_sa_element_size,
{ "ElementSize", "dcom.sa.element_size", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_sa_locks,
{ "Locks", "dcom.sa.locks", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_sa_vartype32,
{ "VarType32", "dcom.sa.vartype", FT_UINT32, BASE_DEC, VALS(dcom_variant_type_vals), 0x0, NULL, HFILL }},
{ &hf_dcom_sa_vartype16,
{ "VarType16", "dcom.sa.vartype", FT_UINT16, BASE_DEC, VALS(dcom_variant_type_vals), 0x0, NULL, HFILL }},
{ &hf_dcom_sa_elements,
{ "Elements", "dcom.sa.elements", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_sa_bound_elements,
{ "BoundElements", "dcom.sa.bound_elements", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_sa_low_bound,
{ "LowBound", "dcom.sa.low_bound", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dcom_sa_features_auto,
{ "AUTO", "dcom.sa.features_auto", FT_BOOLEAN, 16, TFS (&tfs_set_notset), WIRESHARK_FADF_AUTO, NULL, HFILL }},
{ &hf_dcom_sa_features_static,
{ "STATIC", "dcom.sa.features_static", FT_BOOLEAN, 16, TFS (&tfs_set_notset), WIRESHARK_FADF_STATIC, NULL, HFILL }},
{ &hf_dcom_sa_features_embedded,
{ "EMBEDDED", "dcom.sa.features_embedded", FT_BOOLEAN, 16, TFS (&tfs_set_notset), WIRESHARK_FADF_EMBEDDED, NULL, HFILL }},
{ &hf_dcom_sa_features_fixedsize,
{ "FIXEDSIZE", "dcom.sa.features_fixedsize", FT_BOOLEAN, 16, TFS (&tfs_set_notset), WIRESHARK_FADF_FIXEDSIZE, NULL, HFILL }},
{ &hf_dcom_sa_features_record,
{ "RECORD", "dcom.sa.features_record", FT_BOOLEAN, 16, TFS (&tfs_set_notset), WIRESHARK_FADF_RECORD, NULL, HFILL }},
{ &hf_dcom_sa_features_have_iid,
{ "HAVEIID", "dcom.sa.features_have_iid", FT_BOOLEAN, 16, TFS (&tfs_set_notset), WIRESHARK_FADF_HAVEIID, NULL, HFILL }},
{ &hf_dcom_sa_features_have_vartype,
{ "HAVEVARTYPE", "dcom.sa.features_have_vartype", FT_BOOLEAN, 16, TFS (&tfs_set_notset), WIRESHARK_FADF_HAVEVARTYPE, NULL, HFILL }},
{ &hf_dcom_sa_features_bstr,
{ "BSTR", "dcom.sa.features_bstr", FT_BOOLEAN, 16, TFS (&tfs_set_notset), WIRESHARK_FADF_BSTR, NULL, HFILL }},
{ &hf_dcom_sa_features_unknown,
{ "UNKNOWN", "dcom.sa.features_unknown", FT_BOOLEAN, 16, TFS (&tfs_set_notset), WIRESHARK_FADF_UNKNOWN, NULL, HFILL }},
{ &hf_dcom_sa_features_dispatch,
{ "DISPATCH", "dcom.sa.features_dispatch", FT_BOOLEAN, 16, TFS (&tfs_set_notset), WIRESHARK_FADF_DISPATCH, NULL, HFILL }},
{ &hf_dcom_sa_features_variant,
{ "VARIANT", "dcom.sa.features_variant", FT_BOOLEAN, 16, TFS (&tfs_set_notset), WIRESHARK_FADF_VARIANT, NULL, HFILL }}
};
static gint *ett_dcom[] = {
&ett_dcom_this,
&ett_dcom_that,
&ett_dcom_extent,
&ett_dcom_lpwstr,
&ett_dcom_interface_pointer,
&ett_dcom_objref,
&ett_dcom_stdobjref,
&ett_dcom_custobjref,
&ett_dcom_dualstringarray,
&ett_dcom_dualstringarray_binding,
&ett_dcom_variant,
&ett_dcom_safearray,
&ett_dcom_sa_features,
};
static ei_register_info ei[] = {
{ &ei_dcom_dissetion_incomplete, { "dcom.dissetion_incomplete", PI_UNDECODED, PI_WARN, "Dissection incomplete", EXPFILL }},
{ &ei_dcom_no_spec, { "dcom.no_spec", PI_UNDECODED, PI_NOTE, "No specification available, dissection not possible", EXPFILL }},
{ &ei_dcom_hresult_expert, { "dcom.hresult.expert", PI_RESPONSE_CODE, PI_NOTE, "Hresult", EXPFILL }},
{ &ei_dcom_dualstringarray_mult_ip, { "dcom.dualstringarray.mult_ip", PI_UNDECODED, PI_NOTE, "DUALSTRINGARRAY Multiple IP", EXPFILL }},
};
module_t *dcom_module;
expert_module_t* expert_dcom;
proto_dcom = proto_register_protocol ("DCOM", "DCOM", "dcom");
proto_register_field_array(proto_dcom, hf_dcom_this_array, array_length(hf_dcom_this_array));
proto_register_field_array(proto_dcom, hf_dcom_that_array, array_length(hf_dcom_that_array));
proto_register_field_array(proto_dcom, hf_dcom_extent_array, array_length(hf_dcom_extent_array));
proto_register_field_array(proto_dcom, hf_dcom_array, array_length(hf_dcom_array));
proto_register_field_array(proto_dcom, hf_dcom_objref_array, array_length(hf_dcom_objref_array));
proto_register_field_array(proto_dcom, hf_dcom_stdobjref_array, array_length(hf_dcom_stdobjref_array));
proto_register_field_array(proto_dcom, hf_dcom_custobjref_array, array_length(hf_dcom_custobjref_array));
proto_register_field_array(proto_dcom, hf_dcom_dualstringarray_array, array_length(hf_dcom_dualstringarray_array));
proto_register_field_array(proto_dcom, hf_dcom_interface_pointer_array, array_length(hf_dcom_interface_pointer_array));
proto_register_field_array(proto_dcom, hf_dcom_vt_array, array_length(hf_dcom_vt_array));
proto_register_field_array(proto_dcom, hf_dcom_sa_array, array_length(hf_dcom_sa_array));
proto_register_subtree_array (ett_dcom, array_length (ett_dcom));
expert_dcom = expert_register_protocol(proto_dcom);
expert_register_field_array(expert_dcom, ei, array_length(ei));
dcom_module = prefs_register_protocol(proto_dcom, NULL);
prefs_register_bool_preference(dcom_module, "display_unmarshalling_details",
"Display DCOM unmarshalling details",
"Display some DCOM unmarshalled fields "
"usually hidden",
&dcom_prefs_display_unmarshalling_details);
register_cleanup_routine(dcom_cleanup);
}
void
proto_reg_handoff_dcom (void)
{
guids_add_uuid(&uuid_debug_ext, "Debug Information Body Extension");
guids_add_uuid(&uuid_ext_error_ext, "Extended Error Info Body Extension");
guids_add_uuid(&ipid_rem_unknown, "IRemUnknown");
guids_add_uuid(&iid_unknown, "IUnknown");
guids_add_uuid(&uuid_null, "NULL");
guids_add_uuid(&iid_class_factory, "IClassFactory");
}
