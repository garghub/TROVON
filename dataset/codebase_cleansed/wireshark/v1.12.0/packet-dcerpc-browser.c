static int
dissect_browser_long_pointer(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_uint32 (tvb, offset, pinfo, tree, di, drep,
di->hf_index, NULL);
return offset;
}
static int
dissect_browser_TYPE_4_data(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
guint32 len;
int old_offset = offset;
if(di->conformant_run){
offset =dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, NULL);
return offset;
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, &len);
proto_tree_add_item(tree, hf_browser_unknown_bytes, tvb, offset, len,
ENC_NA);
offset += len;
if (offset < old_offset)
THROW(ReportedBoundsError);
return len;
}
static int
dissect_browser_TYPE_4(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_browser_TYPE_4_data, NDR_POINTER_UNIQUE,
"unknown TYPE_4", -1);
return offset;
}
static int
dissect_browser_TYPE_3_data(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
guint32 len;
int old_offset = offset;
if(di->conformant_run){
offset =dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, NULL);
return offset;
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, &len);
proto_tree_add_item(tree, hf_browser_unknown_bytes, tvb, offset, len,
ENC_NA);
offset += len;
if (offset < old_offset)
THROW(ReportedBoundsError);
return len;
}
static int
dissect_browser_TYPE_3(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_browser_TYPE_3_data, NDR_POINTER_UNIQUE,
"unknown TYPE_3", -1);
return offset;
}
static int
dissect_browser_TYPE_2(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
guint32 level;
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, &level);
ALIGN_TO_4_BYTES;
switch(level){
case 100:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_browser_TYPE_3, NDR_POINTER_UNIQUE,
"unknown TYPE_3", -1);
break;
case 101:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_browser_TYPE_4, NDR_POINTER_UNIQUE,
"unknown TYPE_4", -1);
break;
}
return offset;
}
static int
dissect_browser_TYPE_1(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_browser_TYPE_2(tvb, offset, pinfo, tree, di, drep);
return offset;
}
static int
dissect_browser_browserr_server_enum_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, di, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_browser_unknown_string, 0);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, di, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_browser_unknown_string, 0);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, di, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_browser_unknown_string, 0);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_browser_TYPE_1, NDR_POINTER_REF,
"unknown TYPE_1", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, di, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_browser_unknown_string, 0);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_browser_long_pointer, NDR_POINTER_UNIQUE,
"unknown long", hf_browser_unknown_long);
return offset;
}
static int
dissect_browser_browserr_server_enum_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_browser_TYPE_1, NDR_POINTER_REF,
"unknown TYPE_1", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_browser_long_pointer, NDR_POINTER_UNIQUE,
"unknown long", hf_browser_unknown_long);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_rc, NULL);
return offset;
}
static int
dissect_browser_browserr_debug_call_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, di, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_browser_unknown_string, 0);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
return offset;
}
static int
dissect_browser_browserr_debug_call_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di _U_, guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_rc, NULL);
return offset;
}
static int
dissect_browser_browserr_query_other_domains_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, di, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_browser_unknown_string, 0);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_browser_TYPE_1, NDR_POINTER_REF,
"unknown TYPE_1", -1);
return offset;
}
static int
dissect_browser_browserr_query_other_domains_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di _U_, guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_rc, NULL);
return offset;
}
static int
dissect_browser_browserr_reset_netlogon_state_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, di, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_browser_unknown_string, 0);
return offset;
}
static int
dissect_browser_browserr_reset_netlogon_state_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di _U_, guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_rc, NULL);
return offset;
}
static int
dissect_browser_browserr_debug_trace_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, di, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_browser_unknown_string, 0);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, di, drep,
NDR_POINTER_REF, "unknown string",
hf_browser_unknown_string, 0);
return offset;
}
static int
dissect_browser_browserr_debug_trace_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di _U_, guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_rc, NULL);
return offset;
}
static int
dissect_browser_TYPE_5(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_duint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_hyper, NULL);
offset = dissect_ndr_duint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_hyper, NULL);
offset = dissect_ndr_duint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_hyper, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_duint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_hyper, NULL);
return offset;
}
static int
dissect_browser_browserr_query_statistics_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, di, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_browser_unknown_string, 0);
return offset;
}
static int
dissect_browser_browserr_query_statistics_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_browser_TYPE_5, NDR_POINTER_UNIQUE,
"unknown TYPE_5", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_rc, NULL);
return offset;
}
static int
dissect_browser_browserr_reset_statistics_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, di, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_browser_unknown_string, 0);
return offset;
}
static int
dissect_browser_browserr_reset_statistics_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di _U_, guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_rc, NULL);
return offset;
}
static int
dissect_browser_netr_browser_statistics_clear_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, di, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_browser_unknown_string, 0);
return offset;
}
static int
dissect_browser_netr_browser_statistics_clear_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di _U_, guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_rc, NULL);
return offset;
}
static int
dissect_browser_TYPE_11(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di _U_, guint8 *drep)
{
offset = dissect_ndr_duint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_hyper, NULL);
offset = dissect_ndr_duint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_hyper, NULL);
offset = dissect_ndr_duint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_hyper, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_duint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_hyper, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
return offset;
}
static int
dissect_browser_TYPE_11_array(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep,
dissect_browser_TYPE_11);
return offset;
}
static int
dissect_browser_TYPE_10(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_browser_TYPE_11_array, NDR_POINTER_UNIQUE,
"unknown TYPE_11_ARRAY", -1);
return offset;
}
static int
dissect_browser_TYPE_9_data(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
guint32 len;
int old_offset = offset;
if(di->conformant_run){
offset =dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, NULL);
return offset;
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, &len);
proto_tree_add_item(tree, hf_browser_unknown_bytes, tvb, offset, len,
ENC_NA);
offset += len;
if (offset < old_offset)
THROW(ReportedBoundsError);
return len;
}
static int
dissect_browser_TYPE_9(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_browser_TYPE_9_data, NDR_POINTER_UNIQUE,
"unknown TYPE_9", -1);
return offset;
}
static int
dissect_browser_TYPE_8(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
guint32 level;
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, &level);
ALIGN_TO_4_BYTES;
switch(level){
case 100:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_browser_TYPE_9, NDR_POINTER_UNIQUE,
"unknown TYPE_9", -1);
break;
case 101:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_browser_TYPE_10, NDR_POINTER_UNIQUE,
"unknown TYPE_10", -1);
break;
}
return offset;
}
static int
dissect_browser_TYPE_7(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_browser_TYPE_8(tvb, offset, pinfo, tree, di, drep);
return offset;
}
static int
dissect_browser_netr_browser_statistics_get_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, di, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_browser_unknown_string, 0);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_browser_TYPE_7, NDR_POINTER_REF,
"unknown TYPE_7", -1);
return offset;
}
static int
dissect_browser_netr_browser_statistics_get_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_browser_TYPE_7, NDR_POINTER_REF,
"unknown TYPE_7", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_rc, NULL);
return offset;
}
static int
dissect_browser_browserr_set_netlogon_state_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, di, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_browser_unknown_string, 0);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, di, drep,
NDR_POINTER_REF, "unknown string",
hf_browser_unknown_string, 0);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, di, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_browser_unknown_string, 0);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
return offset;
}
static int
dissect_browser_browserr_set_netlogon_state_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di _U_, guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_rc, NULL);
return offset;
}
static int
dissect_browser_TYPE_12_data(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
guint32 len;
int old_offset = offset;
if(di->conformant_run){
offset =dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, NULL);
return offset;
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, &len);
proto_tree_add_item(tree, hf_browser_unknown_bytes, tvb, offset, len,
ENC_NA);
offset += len;
if (offset < old_offset)
THROW(ReportedBoundsError);
return offset;
}
static int
dissect_browser_TYPE_12(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_browser_TYPE_12_data, NDR_POINTER_UNIQUE,
"unknown TYPE_12", -1);
return offset;
}
static int
dissect_browser_browserr_query_emulated_domains_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, di, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_browser_unknown_string, 0);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_browser_TYPE_12, NDR_POINTER_REF,
"unknown TYPE_12", -1);
return offset;
}
static int
dissect_browser_browserr_query_emulated_domains_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_browser_TYPE_12, NDR_POINTER_REF,
"unknown TYPE_12", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_rc, NULL);
return offset;
}
static int
dissect_browser_browserr_server_enum_ex_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, di, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_browser_unknown_string, 0);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, di, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_browser_unknown_string, 0);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, di, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_browser_unknown_string, 0);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_browser_TYPE_1, NDR_POINTER_REF,
"unknown TYPE_1", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, di, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_browser_unknown_string, 0);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, di, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_browser_unknown_string, 0);
return offset;
}
static int
dissect_browser_browserr_server_enum_ex_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_browser_TYPE_1, NDR_POINTER_REF,
"unknown TYPE_1", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_unknown_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_browser_rc, NULL);
return offset;
}
void
proto_register_dcerpc_browser(void)
{
static hf_register_info hf[] = {
{ &hf_browser_opnum, {
"Operation", "rpc_browser.opnum", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_browser_rc, {
"Return code", "rpc_browser.rc", FT_UINT32, BASE_HEX | BASE_EXT_STRING,
&NT_errors_ext, 0x0, "Browser return code", HFILL }},
{ &hf_browser_unknown_long, {
"Unknown long", "rpc_browser.unknown.long", FT_UINT32, BASE_HEX,
NULL, 0x0, "Unknown long. If you know what this is, contact wireshark developers.", HFILL }},
{ &hf_browser_unknown_hyper, {
"Unknown hyper", "rpc_browser.unknown.hyper", FT_UINT64, BASE_HEX,
NULL, 0x0, "Unknown hyper. If you know what this is, contact wireshark developers.", HFILL }},
{ &hf_browser_unknown_bytes, {
"Unknown bytes", "rpc_browser.unknown.bytes", FT_BYTES, BASE_NONE,
NULL, 0x0, "Unknown bytes. If you know what this is, contact wireshark developers.", HFILL }},
{ &hf_browser_unknown_string, {
"Unknown string", "rpc_browser.unknown.string", FT_STRING, BASE_NONE,
NULL, 0x0, "Unknown string. If you know what this is, contact wireshark developers.", HFILL }}
};
static gint *ett[] = {
&ett_dcerpc_browser
};
proto_dcerpc_browser = proto_register_protocol(
"RPC Browser", "RPC_BROWSER", "rpc_browser");
proto_register_field_array(proto_dcerpc_browser, hf,
array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_dcerpc_browser(void)
{
dcerpc_init_uuid(proto_dcerpc_browser, ett_dcerpc_browser,
&uuid_dcerpc_browser, ver_dcerpc_browser,
dcerpc_browser_dissectors, hf_browser_opnum);
}
