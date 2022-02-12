static int
misc_dissect_element_winreg_Data_string(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_null_term_wstring(tvb, offset, pinfo, tree, drep, hf_misc_winreg_Data_string , 0);
return offset;
}
static int
misc_dissect_element_winreg_Data_value(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_misc_winreg_Data_value, 0);
return offset;
}
static int
misc_dissect_struct_string_array(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info *di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
return offset;
}
static int
misc_dissect_element_GUID_time_low(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_misc_GUID_time_low, 0);
return offset;
}
static int
misc_dissect_element_GUID_time_mid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_misc_GUID_time_mid, 0);
return offset;
}
static int
misc_dissect_element_GUID_time_hi_and_version(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_misc_GUID_time_hi_and_version, 0);
return offset;
}
static int
misc_dissect_element_GUID_clock_seq(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
int i;
for (i = 0; i < 2; i++)
offset = misc_dissect_element_GUID_clock_seq_(tvb, offset, pinfo, tree, di, drep);
return offset;
}
static int
misc_dissect_element_GUID_clock_seq_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_misc_GUID_clock_seq, 0);
return offset;
}
static int
misc_dissect_element_GUID_node(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
int i;
for (i = 0; i < 6; i++)
offset = misc_dissect_element_GUID_node_(tvb, offset, pinfo, tree, di, drep);
return offset;
}
static int
misc_dissect_element_GUID_node_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_misc_GUID_node, 0);
return offset;
}
int
misc_dissect_struct_GUID(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_misc_GUID);
}
offset = misc_dissect_element_GUID_time_low(tvb, offset, pinfo, tree, di, drep);
offset = misc_dissect_element_GUID_time_mid(tvb, offset, pinfo, tree, di, drep);
offset = misc_dissect_element_GUID_time_hi_and_version(tvb, offset, pinfo, tree, di, drep);
offset = misc_dissect_element_GUID_clock_seq(tvb, offset, pinfo, tree, di, drep);
offset = misc_dissect_element_GUID_node(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
static int
misc_dissect_element_ndr_syntax_id_uuid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uuid_t(tvb, offset, pinfo, tree, di, drep, hf_misc_ndr_syntax_id_uuid, NULL);
return offset;
}
static int
misc_dissect_element_ndr_syntax_id_if_version(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_misc_ndr_syntax_id_if_version, 0);
return offset;
}
int
misc_dissect_struct_ndr_syntax_id(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_misc_ndr_syntax_id);
}
offset = misc_dissect_element_ndr_syntax_id_uuid(tvb, offset, pinfo, tree, di, drep);
offset = misc_dissect_element_ndr_syntax_id_if_version(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
static int
misc_dissect_element_policy_handle_handle_type(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_misc_policy_handle_handle_type, 0);
return offset;
}
static int
misc_dissect_element_policy_handle_uuid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uuid_t(tvb, offset, pinfo, tree, di, drep, hf_misc_policy_handle_uuid, NULL);
return offset;
}
int
misc_dissect_struct_policy_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_misc_policy_handle);
}
offset = misc_dissect_element_policy_handle_handle_type(tvb, offset, pinfo, tree, di, drep);
offset = misc_dissect_element_policy_handle_uuid(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
int
misc_dissect_enum_netr_SchannelType(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint1632 *param _U_)
{
guint1632 parameter=0;
if(param){
parameter=(guint1632)*param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if(param){
*param=(guint32)parameter;
}
return offset;
}
static int
misc_dissect_element_KRB5_EDATA_NTSTATUS_ntstatus(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_misc_KRB5_EDATA_NTSTATUS_ntstatus, 0);
return offset;
}
static int
misc_dissect_element_KRB5_EDATA_NTSTATUS_unknown1(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_misc_KRB5_EDATA_NTSTATUS_unknown1, 0);
return offset;
}
static int
misc_dissect_element_KRB5_EDATA_NTSTATUS_unknown2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_misc_KRB5_EDATA_NTSTATUS_unknown2, 0);
return offset;
}
int
misc_dissect_struct_KRB5_EDATA_NTSTATUS(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_misc_KRB5_EDATA_NTSTATUS);
}
offset = misc_dissect_element_KRB5_EDATA_NTSTATUS_ntstatus(tvb, offset, pinfo, tree, di, drep);
offset = misc_dissect_element_KRB5_EDATA_NTSTATUS_unknown1(tvb, offset, pinfo, tree, di, drep);
offset = misc_dissect_element_KRB5_EDATA_NTSTATUS_unknown2(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
int
misc_dissect_enum_winreg_Type(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
{
guint32 parameter=0;
if(param){
parameter=(guint32)*param;
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if(param){
*param=(guint32)parameter;
}
return offset;
}
static int
misc_dissect_element_winreg_Data_binary(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_datablob(tvb, offset, pinfo, tree, di, drep, hf_misc_winreg_Data_binary, 1);
return offset;
}
static int
misc_dissect_element_winreg_Data_string_array(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = misc_dissect_struct_string_array(tvb,offset,pinfo,tree,di,drep,hf_misc_winreg_Data_string_array,0);
return offset;
}
static int
misc_dissect_element_winreg_Data_data(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_datablob(tvb, offset, pinfo, tree, di, drep, hf_misc_winreg_Data_data, 1);
return offset;
}
static int
misc_dissect_winreg_Data(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
guint32 level = param;
old_offset = offset;
if (parent_tree) {
tree = proto_tree_add_subtree(parent_tree, tvb, offset, -1, ett_misc_winreg_Data, &item, "winreg_Data");
}
switch(level) {
case REG_NONE:
break;
case REG_SZ:
offset = misc_dissect_element_winreg_Data_string(tvb, offset, pinfo, tree, di, drep);
break;
case REG_EXPAND_SZ:
offset = misc_dissect_element_winreg_Data_string(tvb, offset, pinfo, tree, di, drep);
break;
case REG_BINARY:
offset = misc_dissect_element_winreg_Data_binary(tvb, offset, pinfo, tree, di, drep);
break;
case REG_DWORD:
offset = misc_dissect_element_winreg_Data_value(tvb, offset, pinfo, tree, di, drep);
break;
case REG_DWORD_BIG_ENDIAN:
offset = misc_dissect_element_winreg_Data_value(tvb, offset, pinfo, tree, di, drep);
break;
case REG_MULTI_SZ:
offset = misc_dissect_element_winreg_Data_string_array(tvb, offset, pinfo, tree, di, drep);
break;
default:
offset = misc_dissect_element_winreg_Data_data(tvb, offset, pinfo, tree, di, drep);
break;
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
void proto_register_dcerpc_misc(void)
{
static hf_register_info hf[] = {
{ &hf_misc_GUID_time_mid,
{ "Time Mid", "misc.GUID.time_mid", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_misc_winreg_Data_value,
{ "Value", "misc.winreg_Data.value", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_misc_GUID_time_low,
{ "Time Low", "misc.GUID.time_low", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_misc_KRB5_EDATA_NTSTATUS_unknown2,
{ "Unknown2", "misc.KRB5_EDATA_NTSTATUS.unknown2", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_misc_GUID_time_hi_and_version,
{ "Time Hi And Version", "misc.GUID.time_hi_and_version", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_misc_KRB5_EDATA_NTSTATUS_ntstatus,
{ "Ntstatus", "misc.KRB5_EDATA_NTSTATUS.ntstatus", FT_UINT32, BASE_DEC, VALS(NT_errors), 0, NULL, HFILL }},
{ &hf_misc_GUID_node,
{ "Node", "misc.GUID.node", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_misc_winreg_Data_string,
{ "String", "misc.winreg_Data.string", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_misc_winreg_Data_data,
{ "Data", "misc.winreg_Data.data", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_misc_winreg_Data_binary,
{ "Binary", "misc.winreg_Data.binary", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_misc_policy_handle_uuid,
{ "Uuid", "misc.policy_handle.uuid", FT_GUID, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_misc_KRB5_EDATA_NTSTATUS_unknown1,
{ "Unknown1", "misc.KRB5_EDATA_NTSTATUS.unknown1", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_misc_policy_handle_handle_type,
{ "Handle Type", "misc.policy_handle.handle_type", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_misc_ndr_syntax_id_uuid,
{ "Uuid", "misc.ndr_syntax_id.uuid", FT_GUID, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_misc_opnum,
{ "Operation", "misc.opnum", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_misc_GUID_clock_seq,
{ "Clock Seq", "misc.GUID.clock_seq", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_misc_winreg_Data_string_array,
{ "String Array", "misc.winreg_Data.string_array", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_misc_ndr_syntax_id_if_version,
{ "If Version", "misc.ndr_syntax_id.if_version", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_dcerpc_misc,
&ett_misc_GUID,
&ett_misc_ndr_syntax_id,
&ett_misc_policy_handle,
&ett_misc_KRB5_EDATA_NTSTATUS,
&ett_misc_winreg_Data,
};
proto_dcerpc_misc = proto_register_protocol("MISC (pidl)", "MISC", "misc");
proto_register_field_array(proto_dcerpc_misc, hf, array_length (hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_dcerpc_misc(void)
{
dcerpc_init_uuid(proto_dcerpc_misc, ett_dcerpc_misc,
&uuid_dcerpc_misc, ver_dcerpc_misc,
misc_dissectors, hf_misc_opnum);
}
