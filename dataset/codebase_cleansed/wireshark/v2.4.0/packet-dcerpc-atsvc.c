int
atsvc_dissect_bitmap_DaysOfMonth(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item;
static const int * atsvc_atsvc_DaysOfMonth_fields[] = {
&hf_atsvc_atsvc_DaysOfMonth_First,
&hf_atsvc_atsvc_DaysOfMonth_Second,
&hf_atsvc_atsvc_DaysOfMonth_Third,
&hf_atsvc_atsvc_DaysOfMonth_Fourth,
&hf_atsvc_atsvc_DaysOfMonth_Fifth,
&hf_atsvc_atsvc_DaysOfMonth_Sixth,
&hf_atsvc_atsvc_DaysOfMonth_Seventh,
&hf_atsvc_atsvc_DaysOfMonth_Eight,
&hf_atsvc_atsvc_DaysOfMonth_Ninth,
&hf_atsvc_atsvc_DaysOfMonth_Tenth,
&hf_atsvc_atsvc_DaysOfMonth_Eleventh,
&hf_atsvc_atsvc_DaysOfMonth_Twelfth,
&hf_atsvc_atsvc_DaysOfMonth_Thitteenth,
&hf_atsvc_atsvc_DaysOfMonth_Fourteenth,
&hf_atsvc_atsvc_DaysOfMonth_Fifteenth,
&hf_atsvc_atsvc_DaysOfMonth_Sixteenth,
&hf_atsvc_atsvc_DaysOfMonth_Seventeenth,
&hf_atsvc_atsvc_DaysOfMonth_Eighteenth,
&hf_atsvc_atsvc_DaysOfMonth_Ninteenth,
&hf_atsvc_atsvc_DaysOfMonth_Twentyth,
&hf_atsvc_atsvc_DaysOfMonth_Twentyfirst,
&hf_atsvc_atsvc_DaysOfMonth_Twentysecond,
&hf_atsvc_atsvc_DaysOfMonth_Twentythird,
&hf_atsvc_atsvc_DaysOfMonth_Twentyfourth,
&hf_atsvc_atsvc_DaysOfMonth_Twentyfifth,
&hf_atsvc_atsvc_DaysOfMonth_Twentysixth,
&hf_atsvc_atsvc_DaysOfMonth_Twentyseventh,
&hf_atsvc_atsvc_DaysOfMonth_Twentyeighth,
&hf_atsvc_atsvc_DaysOfMonth_Twentyninth,
&hf_atsvc_atsvc_DaysOfMonth_Thirtieth,
&hf_atsvc_atsvc_DaysOfMonth_Thirtyfirst,
NULL
};
guint32 flags;
ALIGN_TO_4_BYTES;
item = proto_tree_add_bitmask_with_flags(parent_tree, tvb, offset, hf_index,
ett_atsvc_atsvc_DaysOfMonth, atsvc_atsvc_DaysOfMonth_fields, DREP_ENC_INTEGER(drep), BMT_NO_FALSE);
offset = dissect_ndr_uint32(tvb, offset, pinfo, parent_tree, di, drep, -1, &flags);
if (!flags)
proto_item_append_text(item, ": (No values set)");
if (flags & (~0x7fffffff)) {
flags &= (~0x7fffffff);
proto_item_append_text(item, "Unknown bitmap value 0x%x", flags);
}
return offset;
}
int
atsvc_dissect_bitmap_Flags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item;
static const int * atsvc_atsvc_Flags_fields[] = {
&hf_atsvc_atsvc_Flags_JOB_RUN_PERIODICALLY,
&hf_atsvc_atsvc_Flags_JOB_EXEC_ERROR,
&hf_atsvc_atsvc_Flags_JOB_RUNS_TODAY,
&hf_atsvc_atsvc_Flags_JOB_ADD_CURRENT_DATE,
&hf_atsvc_atsvc_Flags_JOB_NONINTERACTIVE,
NULL
};
guint8 flags;
item = proto_tree_add_bitmask_with_flags(parent_tree, tvb, offset, hf_index,
ett_atsvc_atsvc_Flags, atsvc_atsvc_Flags_fields, DREP_ENC_INTEGER(drep), BMT_NO_FALSE);
offset = dissect_ndr_uint8(tvb, offset, pinfo, parent_tree, di, drep, -1, &flags);
if (!flags)
proto_item_append_text(item, ": (No values set)");
if (flags & (~0x0000001f)) {
flags &= (~0x0000001f);
proto_item_append_text(item, "Unknown bitmap value 0x%x", flags);
}
return offset;
}
int
atsvc_dissect_bitmap_DaysOfWeek(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item;
static const int * atsvc_atsvc_DaysOfWeek_fields[] = {
&hf_atsvc_atsvc_DaysOfWeek_DAYSOFWEEK_MONDAY,
&hf_atsvc_atsvc_DaysOfWeek_DAYSOFWEEK_TUESDAY,
&hf_atsvc_atsvc_DaysOfWeek_DAYSOFWEEK_WEDNESDAY,
&hf_atsvc_atsvc_DaysOfWeek_DAYSOFWEEK_THURSDAY,
&hf_atsvc_atsvc_DaysOfWeek_DAYSOFWEEK_FRIDAY,
&hf_atsvc_atsvc_DaysOfWeek_DAYSOFWEEK_SATURDAY,
&hf_atsvc_atsvc_DaysOfWeek_DAYSOFWEEK_SUNDAY,
NULL
};
guint8 flags;
item = proto_tree_add_bitmask_with_flags(parent_tree, tvb, offset, hf_index,
ett_atsvc_atsvc_DaysOfWeek, atsvc_atsvc_DaysOfWeek_fields, DREP_ENC_INTEGER(drep), BMT_NO_FALSE);
offset = dissect_ndr_uint8(tvb, offset, pinfo, parent_tree, di, drep, -1, &flags);
if (!flags)
proto_item_append_text(item, ": (No values set)");
if (flags & (~0x0000007f)) {
flags &= (~0x0000007f);
proto_item_append_text(item, "Unknown bitmap value 0x%x", flags);
}
return offset;
}
static int
atsvc_dissect_element_JobInfo_job_time(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_atsvc_atsvc_JobInfo_job_time, 0);
return offset;
}
static int
atsvc_dissect_element_JobInfo_days_of_month(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = atsvc_dissect_bitmap_DaysOfMonth(tvb, offset, pinfo, tree, di, drep, hf_atsvc_atsvc_JobInfo_days_of_month, 0);
return offset;
}
static int
atsvc_dissect_element_JobInfo_days_of_week(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = atsvc_dissect_bitmap_DaysOfWeek(tvb, offset, pinfo, tree, di, drep, hf_atsvc_atsvc_JobInfo_days_of_week, 0);
return offset;
}
static int
atsvc_dissect_element_JobInfo_flags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = atsvc_dissect_bitmap_Flags(tvb, offset, pinfo, tree, di, drep, hf_atsvc_atsvc_JobInfo_flags, 0);
return offset;
}
static int
atsvc_dissect_element_JobInfo_command(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, atsvc_dissect_element_JobInfo_command_, NDR_POINTER_UNIQUE, "Pointer to Command (uint16)",hf_atsvc_atsvc_JobInfo_command);
return offset;
}
static int
atsvc_dissect_element_JobInfo_command_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_atsvc_atsvc_JobInfo_command, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
int
atsvc_dissect_struct_JobInfo(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_atsvc_atsvc_JobInfo);
}
offset = atsvc_dissect_element_JobInfo_job_time(tvb, offset, pinfo, tree, di, drep);
offset = atsvc_dissect_element_JobInfo_days_of_month(tvb, offset, pinfo, tree, di, drep);
offset = atsvc_dissect_element_JobInfo_days_of_week(tvb, offset, pinfo, tree, di, drep);
offset = atsvc_dissect_element_JobInfo_flags(tvb, offset, pinfo, tree, di, drep);
offset = atsvc_dissect_element_JobInfo_command(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
atsvc_dissect_element_JobEnumInfo_job_id(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_atsvc_job_id, 0);
return offset;
}
static int
atsvc_dissect_element_JobEnumInfo_job_time(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_atsvc_atsvc_JobEnumInfo_job_time, 0);
return offset;
}
static int
atsvc_dissect_element_JobEnumInfo_days_of_month(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = atsvc_dissect_bitmap_DaysOfMonth(tvb, offset, pinfo, tree, di, drep, hf_atsvc_atsvc_JobEnumInfo_days_of_month, 0);
return offset;
}
static int
atsvc_dissect_element_JobEnumInfo_days_of_week(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = atsvc_dissect_bitmap_DaysOfWeek(tvb, offset, pinfo, tree, di, drep, hf_atsvc_atsvc_JobEnumInfo_days_of_week, 0);
return offset;
}
static int
atsvc_dissect_element_JobEnumInfo_flags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = atsvc_dissect_bitmap_Flags(tvb, offset, pinfo, tree, di, drep, hf_atsvc_atsvc_JobEnumInfo_flags, 0);
return offset;
}
static int
atsvc_dissect_element_JobEnumInfo_command(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, atsvc_dissect_element_JobEnumInfo_command_, NDR_POINTER_UNIQUE, "Pointer to Command (uint16)",hf_atsvc_atsvc_JobEnumInfo_command);
return offset;
}
static int
atsvc_dissect_element_JobEnumInfo_command_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_atsvc_atsvc_JobEnumInfo_command, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
int
atsvc_dissect_struct_JobEnumInfo(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_atsvc_atsvc_JobEnumInfo);
}
offset = atsvc_dissect_element_JobEnumInfo_job_id(tvb, offset, pinfo, tree, di, drep);
offset = atsvc_dissect_element_JobEnumInfo_job_time(tvb, offset, pinfo, tree, di, drep);
offset = atsvc_dissect_element_JobEnumInfo_days_of_month(tvb, offset, pinfo, tree, di, drep);
offset = atsvc_dissect_element_JobEnumInfo_days_of_week(tvb, offset, pinfo, tree, di, drep);
offset = atsvc_dissect_element_JobEnumInfo_flags(tvb, offset, pinfo, tree, di, drep);
offset = atsvc_dissect_element_JobEnumInfo_command(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
atsvc_dissect_element_enum_ctr_entries_read(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_atsvc_atsvc_enum_ctr_entries_read, 0);
return offset;
}
static int
atsvc_dissect_element_enum_ctr_first_entry(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, atsvc_dissect_element_enum_ctr_first_entry_, NDR_POINTER_UNIQUE, "Pointer to First Entry (atsvc_JobEnumInfo)",hf_atsvc_atsvc_enum_ctr_first_entry);
return offset;
}
static int
atsvc_dissect_element_enum_ctr_first_entry_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep, atsvc_dissect_element_enum_ctr_first_entry__);
return offset;
}
static int
atsvc_dissect_element_enum_ctr_first_entry__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = atsvc_dissect_struct_JobEnumInfo(tvb,offset,pinfo,tree,di,drep,hf_atsvc_atsvc_enum_ctr_first_entry,0);
return offset;
}
int
atsvc_dissect_struct_enum_ctr(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_atsvc_atsvc_enum_ctr);
}
offset = atsvc_dissect_element_enum_ctr_entries_read(tvb, offset, pinfo, tree, di, drep);
offset = atsvc_dissect_element_enum_ctr_first_entry(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
atsvc_dissect_element_JobAdd_servername(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, atsvc_dissect_element_JobAdd_servername_, NDR_POINTER_UNIQUE, "Pointer to Servername (uint16)",hf_atsvc_servername);
return offset;
}
static int
atsvc_dissect_element_JobAdd_servername_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_atsvc_servername, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
atsvc_dissect_element_JobAdd_job_info(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, atsvc_dissect_element_JobAdd_job_info_, NDR_POINTER_REF, "Pointer to Job Info (atsvc_JobInfo)",hf_atsvc_job_info);
return offset;
}
static int
atsvc_dissect_element_JobAdd_job_info_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = atsvc_dissect_struct_JobInfo(tvb,offset,pinfo,tree,di,drep,hf_atsvc_job_info,0);
return offset;
}
static int
atsvc_dissect_element_JobAdd_job_id(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, atsvc_dissect_element_JobAdd_job_id_, NDR_POINTER_REF, "Pointer to Job Id (uint32)",hf_atsvc_job_id);
return offset;
}
static int
atsvc_dissect_element_JobAdd_job_id_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_atsvc_job_id, 0);
return offset;
}
static int
atsvc_dissect_JobAdd_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="JobAdd";
offset = atsvc_dissect_element_JobAdd_job_id(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, di, drep, hf_atsvc_status, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
atsvc_dissect_JobAdd_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="JobAdd";
offset = atsvc_dissect_element_JobAdd_servername(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = atsvc_dissect_element_JobAdd_job_info(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
atsvc_dissect_element_JobDel_servername(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, atsvc_dissect_element_JobDel_servername_, NDR_POINTER_UNIQUE, "Pointer to Servername (uint16)",hf_atsvc_servername);
return offset;
}
static int
atsvc_dissect_element_JobDel_servername_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_atsvc_servername, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
atsvc_dissect_element_JobDel_min_job_id(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_atsvc_atsvc_JobDel_min_job_id, 0);
return offset;
}
static int
atsvc_dissect_element_JobDel_max_job_id(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_atsvc_atsvc_JobDel_max_job_id, 0);
return offset;
}
static int
atsvc_dissect_JobDel_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="JobDel";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, di, drep, hf_atsvc_status, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
atsvc_dissect_JobDel_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="JobDel";
offset = atsvc_dissect_element_JobDel_servername(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = atsvc_dissect_element_JobDel_min_job_id(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = atsvc_dissect_element_JobDel_max_job_id(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
atsvc_dissect_element_JobEnum_servername(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, atsvc_dissect_element_JobEnum_servername_, NDR_POINTER_UNIQUE, "Pointer to Servername (uint16)",hf_atsvc_servername);
return offset;
}
static int
atsvc_dissect_element_JobEnum_servername_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_atsvc_servername, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
atsvc_dissect_element_JobEnum_ctr(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, atsvc_dissect_element_JobEnum_ctr_, NDR_POINTER_REF, "Pointer to Ctr (atsvc_enum_ctr)",hf_atsvc_atsvc_JobEnum_ctr);
return offset;
}
static int
atsvc_dissect_element_JobEnum_ctr_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = atsvc_dissect_struct_enum_ctr(tvb,offset,pinfo,tree,di,drep,hf_atsvc_atsvc_JobEnum_ctr,0);
return offset;
}
static int
atsvc_dissect_element_JobEnum_preferred_max_len(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_atsvc_atsvc_JobEnum_preferred_max_len, 0);
return offset;
}
static int
atsvc_dissect_element_JobEnum_total_entries(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, atsvc_dissect_element_JobEnum_total_entries_, NDR_POINTER_REF, "Pointer to Total Entries (uint32)",hf_atsvc_atsvc_JobEnum_total_entries);
return offset;
}
static int
atsvc_dissect_element_JobEnum_total_entries_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_atsvc_atsvc_JobEnum_total_entries, 0);
return offset;
}
static int
atsvc_dissect_element_JobEnum_resume_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, atsvc_dissect_element_JobEnum_resume_handle_, NDR_POINTER_UNIQUE, "Pointer to Resume Handle (uint32)",hf_atsvc_atsvc_JobEnum_resume_handle);
return offset;
}
static int
atsvc_dissect_element_JobEnum_resume_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_atsvc_atsvc_JobEnum_resume_handle, 0);
return offset;
}
static int
atsvc_dissect_JobEnum_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="JobEnum";
offset = atsvc_dissect_element_JobEnum_ctr(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = atsvc_dissect_element_JobEnum_total_entries(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = atsvc_dissect_element_JobEnum_resume_handle(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, di, drep, hf_atsvc_status, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
atsvc_dissect_JobEnum_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="JobEnum";
offset = atsvc_dissect_element_JobEnum_servername(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = atsvc_dissect_element_JobEnum_ctr(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = atsvc_dissect_element_JobEnum_preferred_max_len(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = atsvc_dissect_element_JobEnum_resume_handle(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
atsvc_dissect_element_JobGetInfo_servername(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, atsvc_dissect_element_JobGetInfo_servername_, NDR_POINTER_UNIQUE, "Pointer to Servername (uint16)",hf_atsvc_servername);
return offset;
}
static int
atsvc_dissect_element_JobGetInfo_servername_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_atsvc_servername, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
atsvc_dissect_element_JobGetInfo_job_id(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_atsvc_job_id, 0);
return offset;
}
static int
atsvc_dissect_element_JobGetInfo_job_info(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, atsvc_dissect_element_JobGetInfo_job_info_, NDR_POINTER_REF, "Pointer to Job Info (atsvc_JobInfo)",hf_atsvc_job_info);
return offset;
}
static int
atsvc_dissect_element_JobGetInfo_job_info_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, atsvc_dissect_element_JobGetInfo_job_info__, NDR_POINTER_UNIQUE, "Pointer to Job Info (atsvc_JobInfo)",hf_atsvc_job_info);
return offset;
}
static int
atsvc_dissect_element_JobGetInfo_job_info__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = atsvc_dissect_struct_JobInfo(tvb,offset,pinfo,tree,di,drep,hf_atsvc_job_info,0);
return offset;
}
static int
atsvc_dissect_JobGetInfo_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="JobGetInfo";
offset = atsvc_dissect_element_JobGetInfo_job_info(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, di, drep, hf_atsvc_status, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
atsvc_dissect_JobGetInfo_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="JobGetInfo";
offset = atsvc_dissect_element_JobGetInfo_servername(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = atsvc_dissect_element_JobGetInfo_job_id(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
void proto_register_dcerpc_atsvc(void)
{
static hf_register_info hf[] = {
{ &hf_atsvc_atsvc_DaysOfMonth_Eight,
{ "Eight", "atsvc.atsvc_DaysOfMonth.Eight", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Eight_tfs), ( 0x00000080 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Eighteenth,
{ "Eighteenth", "atsvc.atsvc_DaysOfMonth.Eighteenth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Eighteenth_tfs), ( 0x00020000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Eleventh,
{ "Eleventh", "atsvc.atsvc_DaysOfMonth.Eleventh", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Eleventh_tfs), ( 0x00000400 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Fifteenth,
{ "Fifteenth", "atsvc.atsvc_DaysOfMonth.Fifteenth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Fifteenth_tfs), ( 0x00004000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Fifth,
{ "Fifth", "atsvc.atsvc_DaysOfMonth.Fifth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Fifth_tfs), ( 0x00000010 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_First,
{ "First", "atsvc.atsvc_DaysOfMonth.First", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_First_tfs), ( 0x00000001 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Fourteenth,
{ "Fourteenth", "atsvc.atsvc_DaysOfMonth.Fourteenth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Fourteenth_tfs), ( 0x00002000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Fourth,
{ "Fourth", "atsvc.atsvc_DaysOfMonth.Fourth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Fourth_tfs), ( 0x00000008 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Ninteenth,
{ "Ninteenth", "atsvc.atsvc_DaysOfMonth.Ninteenth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Ninteenth_tfs), ( 0x00040000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Ninth,
{ "Ninth", "atsvc.atsvc_DaysOfMonth.Ninth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Ninth_tfs), ( 0x00000100 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Second,
{ "Second", "atsvc.atsvc_DaysOfMonth.Second", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Second_tfs), ( 0x00000002 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Seventeenth,
{ "Seventeenth", "atsvc.atsvc_DaysOfMonth.Seventeenth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Seventeenth_tfs), ( 0x00010000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Seventh,
{ "Seventh", "atsvc.atsvc_DaysOfMonth.Seventh", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Seventh_tfs), ( 0x00000040 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Sixteenth,
{ "Sixteenth", "atsvc.atsvc_DaysOfMonth.Sixteenth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Sixteenth_tfs), ( 0x00008000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Sixth,
{ "Sixth", "atsvc.atsvc_DaysOfMonth.Sixth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Sixth_tfs), ( 0x00000020 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Tenth,
{ "Tenth", "atsvc.atsvc_DaysOfMonth.Tenth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Tenth_tfs), ( 0x00000200 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Third,
{ "Third", "atsvc.atsvc_DaysOfMonth.Third", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Third_tfs), ( 0x00000004 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Thirtieth,
{ "Thirtieth", "atsvc.atsvc_DaysOfMonth.Thirtieth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Thirtieth_tfs), ( 0x20000000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Thirtyfirst,
{ "Thirtyfirst", "atsvc.atsvc_DaysOfMonth.Thirtyfirst", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Thirtyfirst_tfs), ( 0x40000000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Thitteenth,
{ "Thitteenth", "atsvc.atsvc_DaysOfMonth.Thitteenth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Thitteenth_tfs), ( 0x00001000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Twelfth,
{ "Twelfth", "atsvc.atsvc_DaysOfMonth.Twelfth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Twelfth_tfs), ( 0x00000800 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Twentyeighth,
{ "Twentyeighth", "atsvc.atsvc_DaysOfMonth.Twentyeighth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Twentyeighth_tfs), ( 0x08000000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Twentyfifth,
{ "Twentyfifth", "atsvc.atsvc_DaysOfMonth.Twentyfifth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Twentyfifth_tfs), ( 0x01000000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Twentyfirst,
{ "Twentyfirst", "atsvc.atsvc_DaysOfMonth.Twentyfirst", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Twentyfirst_tfs), ( 0x00100000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Twentyfourth,
{ "Twentyfourth", "atsvc.atsvc_DaysOfMonth.Twentyfourth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Twentyfourth_tfs), ( 0x00800000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Twentyninth,
{ "Twentyninth", "atsvc.atsvc_DaysOfMonth.Twentyninth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Twentyninth_tfs), ( 0x10000000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Twentysecond,
{ "Twentysecond", "atsvc.atsvc_DaysOfMonth.Twentysecond", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Twentysecond_tfs), ( 0x00200000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Twentyseventh,
{ "Twentyseventh", "atsvc.atsvc_DaysOfMonth.Twentyseventh", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Twentyseventh_tfs), ( 0x04000000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Twentysixth,
{ "Twentysixth", "atsvc.atsvc_DaysOfMonth.Twentysixth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Twentysixth_tfs), ( 0x02000000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Twentyth,
{ "Twentyth", "atsvc.atsvc_DaysOfMonth.Twentyth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Twentyth_tfs), ( 0x00080000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Twentythird,
{ "Twentythird", "atsvc.atsvc_DaysOfMonth.Twentythird", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Twentythird_tfs), ( 0x00400000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfWeek_DAYSOFWEEK_FRIDAY,
{ "DAYSOFWEEK FRIDAY", "atsvc.atsvc_DaysOfWeek.DAYSOFWEEK_FRIDAY", FT_BOOLEAN, 8, TFS(&atsvc_DaysOfWeek_DAYSOFWEEK_FRIDAY_tfs), ( 0x10 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfWeek_DAYSOFWEEK_MONDAY,
{ "DAYSOFWEEK MONDAY", "atsvc.atsvc_DaysOfWeek.DAYSOFWEEK_MONDAY", FT_BOOLEAN, 8, TFS(&atsvc_DaysOfWeek_DAYSOFWEEK_MONDAY_tfs), ( 0x01 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfWeek_DAYSOFWEEK_SATURDAY,
{ "DAYSOFWEEK SATURDAY", "atsvc.atsvc_DaysOfWeek.DAYSOFWEEK_SATURDAY", FT_BOOLEAN, 8, TFS(&atsvc_DaysOfWeek_DAYSOFWEEK_SATURDAY_tfs), ( 0x20 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfWeek_DAYSOFWEEK_SUNDAY,
{ "DAYSOFWEEK SUNDAY", "atsvc.atsvc_DaysOfWeek.DAYSOFWEEK_SUNDAY", FT_BOOLEAN, 8, TFS(&atsvc_DaysOfWeek_DAYSOFWEEK_SUNDAY_tfs), ( 0x40 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfWeek_DAYSOFWEEK_THURSDAY,
{ "DAYSOFWEEK THURSDAY", "atsvc.atsvc_DaysOfWeek.DAYSOFWEEK_THURSDAY", FT_BOOLEAN, 8, TFS(&atsvc_DaysOfWeek_DAYSOFWEEK_THURSDAY_tfs), ( 0x08 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfWeek_DAYSOFWEEK_TUESDAY,
{ "DAYSOFWEEK TUESDAY", "atsvc.atsvc_DaysOfWeek.DAYSOFWEEK_TUESDAY", FT_BOOLEAN, 8, TFS(&atsvc_DaysOfWeek_DAYSOFWEEK_TUESDAY_tfs), ( 0x02 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfWeek_DAYSOFWEEK_WEDNESDAY,
{ "DAYSOFWEEK WEDNESDAY", "atsvc.atsvc_DaysOfWeek.DAYSOFWEEK_WEDNESDAY", FT_BOOLEAN, 8, TFS(&atsvc_DaysOfWeek_DAYSOFWEEK_WEDNESDAY_tfs), ( 0x04 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_Flags_JOB_ADD_CURRENT_DATE,
{ "JOB ADD CURRENT DATE", "atsvc.atsvc_Flags.JOB_ADD_CURRENT_DATE", FT_BOOLEAN, 8, TFS(&atsvc_Flags_JOB_ADD_CURRENT_DATE_tfs), ( 0x08 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_Flags_JOB_EXEC_ERROR,
{ "JOB EXEC ERROR", "atsvc.atsvc_Flags.JOB_EXEC_ERROR", FT_BOOLEAN, 8, TFS(&atsvc_Flags_JOB_EXEC_ERROR_tfs), ( 0x02 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_Flags_JOB_NONINTERACTIVE,
{ "JOB NONINTERACTIVE", "atsvc.atsvc_Flags.JOB_NONINTERACTIVE", FT_BOOLEAN, 8, TFS(&atsvc_Flags_JOB_NONINTERACTIVE_tfs), ( 0x10 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_Flags_JOB_RUNS_TODAY,
{ "JOB RUNS TODAY", "atsvc.atsvc_Flags.JOB_RUNS_TODAY", FT_BOOLEAN, 8, TFS(&atsvc_Flags_JOB_RUNS_TODAY_tfs), ( 0x04 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_Flags_JOB_RUN_PERIODICALLY,
{ "JOB RUN PERIODICALLY", "atsvc.atsvc_Flags.JOB_RUN_PERIODICALLY", FT_BOOLEAN, 8, TFS(&atsvc_Flags_JOB_RUN_PERIODICALLY_tfs), ( 0x01 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_JobDel_max_job_id,
{ "Max Job Id", "atsvc.atsvc_JobDel.max_job_id", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_JobDel_min_job_id,
{ "Min Job Id", "atsvc.atsvc_JobDel.min_job_id", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_JobEnumInfo_command,
{ "Command", "atsvc.atsvc_JobEnumInfo.command", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_JobEnumInfo_days_of_month,
{ "Days Of Month", "atsvc.atsvc_JobEnumInfo.days_of_month", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_JobEnumInfo_days_of_week,
{ "Days Of Week", "atsvc.atsvc_JobEnumInfo.days_of_week", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_JobEnumInfo_flags,
{ "Flags", "atsvc.atsvc_JobEnumInfo.flags", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_JobEnumInfo_job_time,
{ "Job Time", "atsvc.atsvc_JobEnumInfo.job_time", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_JobEnum_ctr,
{ "Ctr", "atsvc.atsvc_JobEnum.ctr", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_JobEnum_preferred_max_len,
{ "Preferred Max Len", "atsvc.atsvc_JobEnum.preferred_max_len", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_JobEnum_resume_handle,
{ "Resume Handle", "atsvc.atsvc_JobEnum.resume_handle", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_JobEnum_total_entries,
{ "Total Entries", "atsvc.atsvc_JobEnum.total_entries", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_JobInfo_command,
{ "Command", "atsvc.atsvc_JobInfo.command", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_JobInfo_days_of_month,
{ "Days Of Month", "atsvc.atsvc_JobInfo.days_of_month", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_JobInfo_days_of_week,
{ "Days Of Week", "atsvc.atsvc_JobInfo.days_of_week", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_JobInfo_flags,
{ "Flags", "atsvc.atsvc_JobInfo.flags", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_JobInfo_job_time,
{ "Job Time", "atsvc.atsvc_JobInfo.job_time", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_enum_ctr_entries_read,
{ "Entries Read", "atsvc.atsvc_enum_ctr.entries_read", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_enum_ctr_first_entry,
{ "First Entry", "atsvc.atsvc_enum_ctr.first_entry", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_job_id,
{ "Job Id", "atsvc.job_id", FT_UINT32, BASE_DEC, NULL, 0, "Identifier of the scheduled job", HFILL }},
{ &hf_atsvc_job_info,
{ "JobInfo", "atcvs.job_info", FT_NONE, BASE_NONE, NULL, 0, "JobInfo structure", HFILL }},
{ &hf_atsvc_opnum,
{ "Operation", "atsvc.opnum", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_servername,
{ "Server", "atsvc.server", FT_STRING, BASE_NONE, NULL, 0, "Name of the server", HFILL }},
{ &hf_atsvc_status,
{ "NT Error", "atsvc.status", FT_UINT32, BASE_HEX, VALS(NT_errors), 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_dcerpc_atsvc,
&ett_atsvc_atsvc_DaysOfMonth,
&ett_atsvc_atsvc_Flags,
&ett_atsvc_atsvc_DaysOfWeek,
&ett_atsvc_atsvc_JobInfo,
&ett_atsvc_atsvc_JobEnumInfo,
&ett_atsvc_atsvc_enum_ctr,
};
proto_dcerpc_atsvc = proto_register_protocol("Microsoft AT-Scheduler Service", "ATSVC", "atsvc");
proto_register_field_array(proto_dcerpc_atsvc, hf, array_length (hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_dcerpc_atsvc(void)
{
dcerpc_init_uuid(proto_dcerpc_atsvc, ett_dcerpc_atsvc,
&uuid_dcerpc_atsvc, ver_dcerpc_atsvc,
atsvc_dissectors, hf_atsvc_opnum);
}
