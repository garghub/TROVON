int
atsvc_dissect_bitmap_DaysOfMonth(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint32 flags;
ALIGN_TO_4_BYTES;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, 4, TRUE);
tree = proto_item_add_subtree(item,ett_atsvc_atsvc_DaysOfMonth);
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, NULL, drep, -1, &flags);
proto_item_append_text(item, ": ");
if (!flags)
proto_item_append_text(item, "(No values set)");
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfMonth_First, tvb, offset-4, 4, flags);
if (flags&( 0x00000001 )){
proto_item_append_text(item, "First");
if (flags & (~( 0x00000001 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000001 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfMonth_Second, tvb, offset-4, 4, flags);
if (flags&( 0x00000002 )){
proto_item_append_text(item, "Second");
if (flags & (~( 0x00000002 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000002 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfMonth_Third, tvb, offset-4, 4, flags);
if (flags&( 0x00000004 )){
proto_item_append_text(item, "Third");
if (flags & (~( 0x00000004 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000004 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfMonth_Fourth, tvb, offset-4, 4, flags);
if (flags&( 0x00000008 )){
proto_item_append_text(item, "Fourth");
if (flags & (~( 0x00000008 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000008 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfMonth_Fifth, tvb, offset-4, 4, flags);
if (flags&( 0x00000010 )){
proto_item_append_text(item, "Fifth");
if (flags & (~( 0x00000010 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000010 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfMonth_Sixth, tvb, offset-4, 4, flags);
if (flags&( 0x00000020 )){
proto_item_append_text(item, "Sixth");
if (flags & (~( 0x00000020 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000020 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfMonth_Seventh, tvb, offset-4, 4, flags);
if (flags&( 0x00000040 )){
proto_item_append_text(item, "Seventh");
if (flags & (~( 0x00000040 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000040 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfMonth_Eight, tvb, offset-4, 4, flags);
if (flags&( 0x00000080 )){
proto_item_append_text(item, "Eight");
if (flags & (~( 0x00000080 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000080 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfMonth_Ninth, tvb, offset-4, 4, flags);
if (flags&( 0x00000100 )){
proto_item_append_text(item, "Ninth");
if (flags & (~( 0x00000100 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000100 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfMonth_Tenth, tvb, offset-4, 4, flags);
if (flags&( 0x00000200 )){
proto_item_append_text(item, "Tenth");
if (flags & (~( 0x00000200 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000200 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfMonth_Eleventh, tvb, offset-4, 4, flags);
if (flags&( 0x00000400 )){
proto_item_append_text(item, "Eleventh");
if (flags & (~( 0x00000400 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000400 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfMonth_Twelfth, tvb, offset-4, 4, flags);
if (flags&( 0x00000800 )){
proto_item_append_text(item, "Twelfth");
if (flags & (~( 0x00000800 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000800 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfMonth_Thitteenth, tvb, offset-4, 4, flags);
if (flags&( 0x00001000 )){
proto_item_append_text(item, "Thitteenth");
if (flags & (~( 0x00001000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00001000 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfMonth_Fourteenth, tvb, offset-4, 4, flags);
if (flags&( 0x00002000 )){
proto_item_append_text(item, "Fourteenth");
if (flags & (~( 0x00002000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00002000 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfMonth_Fifteenth, tvb, offset-4, 4, flags);
if (flags&( 0x00004000 )){
proto_item_append_text(item, "Fifteenth");
if (flags & (~( 0x00004000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00004000 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfMonth_Sixteenth, tvb, offset-4, 4, flags);
if (flags&( 0x00008000 )){
proto_item_append_text(item, "Sixteenth");
if (flags & (~( 0x00008000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00008000 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfMonth_Seventeenth, tvb, offset-4, 4, flags);
if (flags&( 0x00010000 )){
proto_item_append_text(item, "Seventeenth");
if (flags & (~( 0x00010000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00010000 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfMonth_Eighteenth, tvb, offset-4, 4, flags);
if (flags&( 0x00020000 )){
proto_item_append_text(item, "Eighteenth");
if (flags & (~( 0x00020000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00020000 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfMonth_Ninteenth, tvb, offset-4, 4, flags);
if (flags&( 0x00040000 )){
proto_item_append_text(item, "Ninteenth");
if (flags & (~( 0x00040000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00040000 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfMonth_Twentyth, tvb, offset-4, 4, flags);
if (flags&( 0x00080000 )){
proto_item_append_text(item, "Twentyth");
if (flags & (~( 0x00080000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00080000 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfMonth_Twentyfirst, tvb, offset-4, 4, flags);
if (flags&( 0x00100000 )){
proto_item_append_text(item, "Twentyfirst");
if (flags & (~( 0x00100000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00100000 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfMonth_Twentysecond, tvb, offset-4, 4, flags);
if (flags&( 0x00200000 )){
proto_item_append_text(item, "Twentysecond");
if (flags & (~( 0x00200000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00200000 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfMonth_Twentythird, tvb, offset-4, 4, flags);
if (flags&( 0x00400000 )){
proto_item_append_text(item, "Twentythird");
if (flags & (~( 0x00400000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00400000 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfMonth_Twentyfourth, tvb, offset-4, 4, flags);
if (flags&( 0x00800000 )){
proto_item_append_text(item, "Twentyfourth");
if (flags & (~( 0x00800000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00800000 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfMonth_Twentyfifth, tvb, offset-4, 4, flags);
if (flags&( 0x01000000 )){
proto_item_append_text(item, "Twentyfifth");
if (flags & (~( 0x01000000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x01000000 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfMonth_Twentysixth, tvb, offset-4, 4, flags);
if (flags&( 0x02000000 )){
proto_item_append_text(item, "Twentysixth");
if (flags & (~( 0x02000000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x02000000 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfMonth_Twentyseventh, tvb, offset-4, 4, flags);
if (flags&( 0x04000000 )){
proto_item_append_text(item, "Twentyseventh");
if (flags & (~( 0x04000000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x04000000 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfMonth_Twentyeighth, tvb, offset-4, 4, flags);
if (flags&( 0x08000000 )){
proto_item_append_text(item, "Twentyeighth");
if (flags & (~( 0x08000000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x08000000 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfMonth_Twentyninth, tvb, offset-4, 4, flags);
if (flags&( 0x10000000 )){
proto_item_append_text(item, "Twentyninth");
if (flags & (~( 0x10000000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x10000000 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfMonth_Thirtieth, tvb, offset-4, 4, flags);
if (flags&( 0x20000000 )){
proto_item_append_text(item, "Thirtieth");
if (flags & (~( 0x20000000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x20000000 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfMonth_Thirtyfirst, tvb, offset-4, 4, flags);
if (flags&( 0x40000000 )){
proto_item_append_text(item, "Thirtyfirst");
if (flags & (~( 0x40000000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x40000000 ));
if (flags) {
proto_item_append_text(item, "Unknown bitmap value 0x%x", flags);
}
return offset;
}
int
atsvc_dissect_bitmap_Flags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint8 flags;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, 1, TRUE);
tree = proto_item_add_subtree(item,ett_atsvc_atsvc_Flags);
}
offset = dissect_ndr_uint8(tvb, offset, pinfo, NULL, drep, -1, &flags);
proto_item_append_text(item, ": ");
if (!flags)
proto_item_append_text(item, "(No values set)");
proto_tree_add_boolean(tree, hf_atsvc_atsvc_Flags_JOB_RUN_PERIODICALLY, tvb, offset-1, 1, flags);
if (flags&( 0x01 )){
proto_item_append_text(item, "JOB_RUN_PERIODICALLY");
if (flags & (~( 0x01 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x01 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_Flags_JOB_EXEC_ERROR, tvb, offset-1, 1, flags);
if (flags&( 0x02 )){
proto_item_append_text(item, "JOB_EXEC_ERROR");
if (flags & (~( 0x02 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x02 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_Flags_JOB_RUNS_TODAY, tvb, offset-1, 1, flags);
if (flags&( 0x04 )){
proto_item_append_text(item, "JOB_RUNS_TODAY");
if (flags & (~( 0x04 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x04 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_Flags_JOB_ADD_CURRENT_DATE, tvb, offset-1, 1, flags);
if (flags&( 0x08 )){
proto_item_append_text(item, "JOB_ADD_CURRENT_DATE");
if (flags & (~( 0x08 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x08 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_Flags_JOB_NONINTERACTIVE, tvb, offset-1, 1, flags);
if (flags&( 0x10 )){
proto_item_append_text(item, "JOB_NONINTERACTIVE");
if (flags & (~( 0x10 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x10 ));
if (flags) {
proto_item_append_text(item, "Unknown bitmap value 0x%x", flags);
}
return offset;
}
int
atsvc_dissect_bitmap_DaysOfWeek(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint8 flags;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, 1, TRUE);
tree = proto_item_add_subtree(item,ett_atsvc_atsvc_DaysOfWeek);
}
offset = dissect_ndr_uint8(tvb, offset, pinfo, NULL, drep, -1, &flags);
proto_item_append_text(item, ": ");
if (!flags)
proto_item_append_text(item, "(No values set)");
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfWeek_DAYSOFWEEK_MONDAY, tvb, offset-1, 1, flags);
if (flags&( 0x01 )){
proto_item_append_text(item, "DAYSOFWEEK_MONDAY");
if (flags & (~( 0x01 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x01 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfWeek_DAYSOFWEEK_TUESDAY, tvb, offset-1, 1, flags);
if (flags&( 0x02 )){
proto_item_append_text(item, "DAYSOFWEEK_TUESDAY");
if (flags & (~( 0x02 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x02 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfWeek_DAYSOFWEEK_WEDNESDAY, tvb, offset-1, 1, flags);
if (flags&( 0x04 )){
proto_item_append_text(item, "DAYSOFWEEK_WEDNESDAY");
if (flags & (~( 0x04 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x04 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfWeek_DAYSOFWEEK_THURSDAY, tvb, offset-1, 1, flags);
if (flags&( 0x08 )){
proto_item_append_text(item, "DAYSOFWEEK_THURSDAY");
if (flags & (~( 0x08 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x08 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfWeek_DAYSOFWEEK_FRIDAY, tvb, offset-1, 1, flags);
if (flags&( 0x10 )){
proto_item_append_text(item, "DAYSOFWEEK_FRIDAY");
if (flags & (~( 0x10 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x10 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfWeek_DAYSOFWEEK_SATURDAY, tvb, offset-1, 1, flags);
if (flags&( 0x20 )){
proto_item_append_text(item, "DAYSOFWEEK_SATURDAY");
if (flags & (~( 0x20 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x20 ));
proto_tree_add_boolean(tree, hf_atsvc_atsvc_DaysOfWeek_DAYSOFWEEK_SUNDAY, tvb, offset-1, 1, flags);
if (flags&( 0x40 )){
proto_item_append_text(item, "DAYSOFWEEK_SUNDAY");
if (flags & (~( 0x40 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x40 ));
if (flags) {
proto_item_append_text(item, "Unknown bitmap value 0x%x", flags);
}
return offset;
}
static int
atsvc_dissect_element_JobInfo_job_time(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_atsvc_atsvc_JobInfo_job_time, 0);
return offset;
}
static int
atsvc_dissect_element_JobInfo_days_of_month(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = atsvc_dissect_bitmap_DaysOfMonth(tvb, offset, pinfo, tree, drep, hf_atsvc_atsvc_JobInfo_days_of_month, 0);
return offset;
}
static int
atsvc_dissect_element_JobInfo_days_of_week(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = atsvc_dissect_bitmap_DaysOfWeek(tvb, offset, pinfo, tree, drep, hf_atsvc_atsvc_JobInfo_days_of_week, 0);
return offset;
}
static int
atsvc_dissect_element_JobInfo_flags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = atsvc_dissect_bitmap_Flags(tvb, offset, pinfo, tree, drep, hf_atsvc_atsvc_JobInfo_flags, 0);
return offset;
}
static int
atsvc_dissect_element_JobInfo_command(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, atsvc_dissect_element_JobInfo_command_, NDR_POINTER_UNIQUE, "Pointer to Command (uint16)",hf_atsvc_atsvc_JobInfo_command);
return offset;
}
static int
atsvc_dissect_element_JobInfo_command_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, drep, sizeof(guint16), hf_atsvc_atsvc_JobInfo_command, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
int
atsvc_dissect_struct_JobInfo(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_atsvc_atsvc_JobInfo);
}
offset = atsvc_dissect_element_JobInfo_job_time(tvb, offset, pinfo, tree, drep);
offset = atsvc_dissect_element_JobInfo_days_of_month(tvb, offset, pinfo, tree, drep);
offset = atsvc_dissect_element_JobInfo_days_of_week(tvb, offset, pinfo, tree, drep);
offset = atsvc_dissect_element_JobInfo_flags(tvb, offset, pinfo, tree, drep);
offset = atsvc_dissect_element_JobInfo_command(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
atsvc_dissect_element_JobEnumInfo_job_id(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_atsvc_job_id, 0);
return offset;
}
static int
atsvc_dissect_element_JobEnumInfo_job_time(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_atsvc_atsvc_JobEnumInfo_job_time, 0);
return offset;
}
static int
atsvc_dissect_element_JobEnumInfo_days_of_month(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = atsvc_dissect_bitmap_DaysOfMonth(tvb, offset, pinfo, tree, drep, hf_atsvc_atsvc_JobEnumInfo_days_of_month, 0);
return offset;
}
static int
atsvc_dissect_element_JobEnumInfo_days_of_week(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = atsvc_dissect_bitmap_DaysOfWeek(tvb, offset, pinfo, tree, drep, hf_atsvc_atsvc_JobEnumInfo_days_of_week, 0);
return offset;
}
static int
atsvc_dissect_element_JobEnumInfo_flags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = atsvc_dissect_bitmap_Flags(tvb, offset, pinfo, tree, drep, hf_atsvc_atsvc_JobEnumInfo_flags, 0);
return offset;
}
static int
atsvc_dissect_element_JobEnumInfo_command(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, atsvc_dissect_element_JobEnumInfo_command_, NDR_POINTER_UNIQUE, "Pointer to Command (uint16)",hf_atsvc_atsvc_JobEnumInfo_command);
return offset;
}
static int
atsvc_dissect_element_JobEnumInfo_command_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, drep, sizeof(guint16), hf_atsvc_atsvc_JobEnumInfo_command, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
int
atsvc_dissect_struct_JobEnumInfo(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_atsvc_atsvc_JobEnumInfo);
}
offset = atsvc_dissect_element_JobEnumInfo_job_id(tvb, offset, pinfo, tree, drep);
offset = atsvc_dissect_element_JobEnumInfo_job_time(tvb, offset, pinfo, tree, drep);
offset = atsvc_dissect_element_JobEnumInfo_days_of_month(tvb, offset, pinfo, tree, drep);
offset = atsvc_dissect_element_JobEnumInfo_days_of_week(tvb, offset, pinfo, tree, drep);
offset = atsvc_dissect_element_JobEnumInfo_flags(tvb, offset, pinfo, tree, drep);
offset = atsvc_dissect_element_JobEnumInfo_command(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
atsvc_dissect_element_enum_ctr_entries_read(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_atsvc_atsvc_enum_ctr_entries_read, 0);
return offset;
}
static int
atsvc_dissect_element_enum_ctr_first_entry(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, atsvc_dissect_element_enum_ctr_first_entry_, NDR_POINTER_UNIQUE, "Pointer to First Entry (atsvc_JobEnumInfo)",hf_atsvc_atsvc_enum_ctr_first_entry);
return offset;
}
static int
atsvc_dissect_element_enum_ctr_first_entry_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep, atsvc_dissect_element_enum_ctr_first_entry__);
return offset;
}
static int
atsvc_dissect_element_enum_ctr_first_entry__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = atsvc_dissect_struct_JobEnumInfo(tvb,offset,pinfo,tree,drep,hf_atsvc_atsvc_enum_ctr_first_entry,0);
return offset;
}
int
atsvc_dissect_struct_enum_ctr(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_atsvc_atsvc_enum_ctr);
}
offset = atsvc_dissect_element_enum_ctr_entries_read(tvb, offset, pinfo, tree, drep);
offset = atsvc_dissect_element_enum_ctr_first_entry(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
atsvc_dissect_element_JobAdd_servername(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, atsvc_dissect_element_JobAdd_servername_, NDR_POINTER_UNIQUE, "Pointer to Servername (uint16)",hf_atsvc_servername);
return offset;
}
static int
atsvc_dissect_element_JobAdd_servername_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, drep, sizeof(guint16), hf_atsvc_servername, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
atsvc_dissect_element_JobAdd_job_info(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, atsvc_dissect_element_JobAdd_job_info_, NDR_POINTER_REF, "Pointer to Job Info (atsvc_JobInfo)",hf_atsvc_job_info);
return offset;
}
static int
atsvc_dissect_element_JobAdd_job_info_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = atsvc_dissect_struct_JobInfo(tvb,offset,pinfo,tree,drep,hf_atsvc_job_info,0);
return offset;
}
static int
atsvc_dissect_element_JobAdd_job_id(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, atsvc_dissect_element_JobAdd_job_id_, NDR_POINTER_REF, "Pointer to Job Id (uint32)",hf_atsvc_job_id);
return offset;
}
static int
atsvc_dissect_element_JobAdd_job_id_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_atsvc_job_id, 0);
return offset;
}
static int
atsvc_dissect_JobAdd_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="JobAdd";
offset = atsvc_dissect_element_JobAdd_job_id(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_atsvc_status, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
atsvc_dissect_JobAdd_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="JobAdd";
offset = atsvc_dissect_element_JobAdd_servername(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = atsvc_dissect_element_JobAdd_job_info(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
atsvc_dissect_element_JobDel_servername(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, atsvc_dissect_element_JobDel_servername_, NDR_POINTER_UNIQUE, "Pointer to Servername (uint16)",hf_atsvc_servername);
return offset;
}
static int
atsvc_dissect_element_JobDel_servername_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, drep, sizeof(guint16), hf_atsvc_servername, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
atsvc_dissect_element_JobDel_min_job_id(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_atsvc_atsvc_JobDel_min_job_id, 0);
return offset;
}
static int
atsvc_dissect_element_JobDel_max_job_id(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_atsvc_atsvc_JobDel_max_job_id, 0);
return offset;
}
static int
atsvc_dissect_JobDel_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="JobDel";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_atsvc_status, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
atsvc_dissect_JobDel_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="JobDel";
offset = atsvc_dissect_element_JobDel_servername(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = atsvc_dissect_element_JobDel_min_job_id(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = atsvc_dissect_element_JobDel_max_job_id(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
atsvc_dissect_element_JobEnum_servername(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, atsvc_dissect_element_JobEnum_servername_, NDR_POINTER_UNIQUE, "Pointer to Servername (uint16)",hf_atsvc_servername);
return offset;
}
static int
atsvc_dissect_element_JobEnum_servername_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, drep, sizeof(guint16), hf_atsvc_servername, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
atsvc_dissect_element_JobEnum_ctr(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, atsvc_dissect_element_JobEnum_ctr_, NDR_POINTER_REF, "Pointer to Ctr (atsvc_enum_ctr)",hf_atsvc_atsvc_JobEnum_ctr);
return offset;
}
static int
atsvc_dissect_element_JobEnum_ctr_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = atsvc_dissect_struct_enum_ctr(tvb,offset,pinfo,tree,drep,hf_atsvc_atsvc_JobEnum_ctr,0);
return offset;
}
static int
atsvc_dissect_element_JobEnum_preferred_max_len(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_atsvc_atsvc_JobEnum_preferred_max_len, 0);
return offset;
}
static int
atsvc_dissect_element_JobEnum_total_entries(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, atsvc_dissect_element_JobEnum_total_entries_, NDR_POINTER_REF, "Pointer to Total Entries (uint32)",hf_atsvc_atsvc_JobEnum_total_entries);
return offset;
}
static int
atsvc_dissect_element_JobEnum_total_entries_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_atsvc_atsvc_JobEnum_total_entries, 0);
return offset;
}
static int
atsvc_dissect_element_JobEnum_resume_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, atsvc_dissect_element_JobEnum_resume_handle_, NDR_POINTER_UNIQUE, "Pointer to Resume Handle (uint32)",hf_atsvc_atsvc_JobEnum_resume_handle);
return offset;
}
static int
atsvc_dissect_element_JobEnum_resume_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_atsvc_atsvc_JobEnum_resume_handle, 0);
return offset;
}
static int
atsvc_dissect_JobEnum_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="JobEnum";
offset = atsvc_dissect_element_JobEnum_ctr(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = atsvc_dissect_element_JobEnum_total_entries(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = atsvc_dissect_element_JobEnum_resume_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_atsvc_status, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
atsvc_dissect_JobEnum_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="JobEnum";
offset = atsvc_dissect_element_JobEnum_servername(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = atsvc_dissect_element_JobEnum_ctr(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = atsvc_dissect_element_JobEnum_preferred_max_len(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = atsvc_dissect_element_JobEnum_resume_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
atsvc_dissect_element_JobGetInfo_servername(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, atsvc_dissect_element_JobGetInfo_servername_, NDR_POINTER_UNIQUE, "Pointer to Servername (uint16)",hf_atsvc_servername);
return offset;
}
static int
atsvc_dissect_element_JobGetInfo_servername_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, drep, sizeof(guint16), hf_atsvc_servername, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
atsvc_dissect_element_JobGetInfo_job_id(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_atsvc_job_id, 0);
return offset;
}
static int
atsvc_dissect_element_JobGetInfo_job_info(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, atsvc_dissect_element_JobGetInfo_job_info_, NDR_POINTER_REF, "Pointer to Job Info (atsvc_JobInfo)",hf_atsvc_job_info);
return offset;
}
static int
atsvc_dissect_element_JobGetInfo_job_info_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, atsvc_dissect_element_JobGetInfo_job_info__, NDR_POINTER_REF, "Pointer to Job Info (atsvc_JobInfo)",hf_atsvc_job_info);
return offset;
}
static int
atsvc_dissect_element_JobGetInfo_job_info__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = atsvc_dissect_struct_JobInfo(tvb,offset,pinfo,tree,drep,hf_atsvc_job_info,0);
return offset;
}
static int
atsvc_dissect_JobGetInfo_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="JobGetInfo";
offset = atsvc_dissect_element_JobGetInfo_job_info(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_atsvc_status, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
atsvc_dissect_JobGetInfo_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="JobGetInfo";
offset = atsvc_dissect_element_JobGetInfo_servername(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = atsvc_dissect_element_JobGetInfo_job_id(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
void proto_register_dcerpc_atsvc(void)
{
static hf_register_info hf[] = {
{ &hf_atsvc_atsvc_Flags_JOB_NONINTERACTIVE,
{ "Job Noninteractive", "atsvc.Flags.JOB_NONINTERACTIVE", FT_BOOLEAN, 8, TFS(&atsvc_Flags_JOB_NONINTERACTIVE_tfs), ( 0x10 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Fourteenth,
{ "Fourteenth", "atsvc.DaysOfMonth.Fourteenth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Fourteenth_tfs), ( 0x00002000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_Flags_JOB_RUN_PERIODICALLY,
{ "Job Run Periodically", "atsvc.Flags.JOB_RUN_PERIODICALLY", FT_BOOLEAN, 8, TFS(&atsvc_Flags_JOB_RUN_PERIODICALLY_tfs), ( 0x01 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_enum_ctr_entries_read,
{ "Entries Read", "atsvc.enum_ctr.entries_read", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Twentyeighth,
{ "Twentyeighth", "atsvc.DaysOfMonth.Twentyeighth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Twentyeighth_tfs), ( 0x08000000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfWeek_DAYSOFWEEK_MONDAY,
{ "Daysofweek Monday", "atsvc.DaysOfWeek.DAYSOFWEEK_MONDAY", FT_BOOLEAN, 8, TFS(&atsvc_DaysOfWeek_DAYSOFWEEK_MONDAY_tfs), ( 0x01 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfWeek_DAYSOFWEEK_SUNDAY,
{ "Daysofweek Sunday", "atsvc.DaysOfWeek.DAYSOFWEEK_SUNDAY", FT_BOOLEAN, 8, TFS(&atsvc_DaysOfWeek_DAYSOFWEEK_SUNDAY_tfs), ( 0x40 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Second,
{ "Second", "atsvc.DaysOfMonth.Second", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Second_tfs), ( 0x00000002 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Twentyth,
{ "Twentyth", "atsvc.DaysOfMonth.Twentyth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Twentyth_tfs), ( 0x00080000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Ninth,
{ "Ninth", "atsvc.DaysOfMonth.Ninth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Ninth_tfs), ( 0x00000100 ), NULL, HFILL }},
{ &hf_atsvc_servername,
{ "Server", "atsvc.server", FT_STRING, BASE_NONE, NULL, 0, "Name of the server", HFILL }},
{ &hf_atsvc_atsvc_DaysOfWeek_DAYSOFWEEK_WEDNESDAY,
{ "Daysofweek Wednesday", "atsvc.DaysOfWeek.DAYSOFWEEK_WEDNESDAY", FT_BOOLEAN, 8, TFS(&atsvc_DaysOfWeek_DAYSOFWEEK_WEDNESDAY_tfs), ( 0x04 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Twentyninth,
{ "Twentyninth", "atsvc.DaysOfMonth.Twentyninth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Twentyninth_tfs), ( 0x10000000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfWeek_DAYSOFWEEK_TUESDAY,
{ "Daysofweek Tuesday", "atsvc.DaysOfWeek.DAYSOFWEEK_TUESDAY", FT_BOOLEAN, 8, TFS(&atsvc_DaysOfWeek_DAYSOFWEEK_TUESDAY_tfs), ( 0x02 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Tenth,
{ "Tenth", "atsvc.DaysOfMonth.Tenth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Tenth_tfs), ( 0x00000200 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_JobEnum_resume_handle,
{ "Resume Handle", "atsvc.JobEnum.resume_handle", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Twentyseventh,
{ "Twentyseventh", "atsvc.DaysOfMonth.Twentyseventh", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Twentyseventh_tfs), ( 0x04000000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Fifteenth,
{ "Fifteenth", "atsvc.DaysOfMonth.Fifteenth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Fifteenth_tfs), ( 0x00004000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_JobInfo_command,
{ "Command", "atsvc.JobInfo.command", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Ninteenth,
{ "Ninteenth", "atsvc.DaysOfMonth.Ninteenth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Ninteenth_tfs), ( 0x00040000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Seventh,
{ "Seventh", "atsvc.DaysOfMonth.Seventh", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Seventh_tfs), ( 0x00000040 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Twentyfourth,
{ "Twentyfourth", "atsvc.DaysOfMonth.Twentyfourth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Twentyfourth_tfs), ( 0x00800000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Seventeenth,
{ "Seventeenth", "atsvc.DaysOfMonth.Seventeenth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Seventeenth_tfs), ( 0x00010000 ), NULL, HFILL }},
{ &hf_atsvc_opnum,
{ "Operation", "atsvc.opnum", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Twelfth,
{ "Twelfth", "atsvc.DaysOfMonth.Twelfth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Twelfth_tfs), ( 0x00000800 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Eighteenth,
{ "Eighteenth", "atsvc.DaysOfMonth.Eighteenth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Eighteenth_tfs), ( 0x00020000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_Flags_JOB_RUNS_TODAY,
{ "Job Runs Today", "atsvc.Flags.JOB_RUNS_TODAY", FT_BOOLEAN, 8, TFS(&atsvc_Flags_JOB_RUNS_TODAY_tfs), ( 0x04 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_JobEnum_total_entries,
{ "Total Entries", "atsvc.JobEnum.total_entries", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_enum_ctr_first_entry,
{ "First Entry", "atsvc.enum_ctr.first_entry", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_JobEnumInfo_job_time,
{ "Job Time", "atsvc.JobEnumInfo.job_time", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Thirtyfirst,
{ "Thirtyfirst", "atsvc.DaysOfMonth.Thirtyfirst", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Thirtyfirst_tfs), ( 0x40000000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Third,
{ "Third", "atsvc.DaysOfMonth.Third", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Third_tfs), ( 0x00000004 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_JobEnum_preferred_max_len,
{ "Preferred Max Len", "atsvc.JobEnum.preferred_max_len", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_JobEnumInfo_days_of_month,
{ "Days Of Month", "atsvc.JobEnumInfo.days_of_month", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfWeek_DAYSOFWEEK_THURSDAY,
{ "Daysofweek Thursday", "atsvc.DaysOfWeek.DAYSOFWEEK_THURSDAY", FT_BOOLEAN, 8, TFS(&atsvc_DaysOfWeek_DAYSOFWEEK_THURSDAY_tfs), ( 0x08 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfWeek_DAYSOFWEEK_FRIDAY,
{ "Daysofweek Friday", "atsvc.DaysOfWeek.DAYSOFWEEK_FRIDAY", FT_BOOLEAN, 8, TFS(&atsvc_DaysOfWeek_DAYSOFWEEK_FRIDAY_tfs), ( 0x10 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Twentythird,
{ "Twentythird", "atsvc.DaysOfMonth.Twentythird", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Twentythird_tfs), ( 0x00400000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_JobInfo_job_time,
{ "Job Time", "atsvc.JobInfo.job_time", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_status,
{ "NT Error", "atsvc.status", FT_UINT32, BASE_HEX, VALS(NT_errors), 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_JobInfo_flags,
{ "Flags", "atsvc.JobInfo.flags", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfWeek_DAYSOFWEEK_SATURDAY,
{ "Daysofweek Saturday", "atsvc.DaysOfWeek.DAYSOFWEEK_SATURDAY", FT_BOOLEAN, 8, TFS(&atsvc_DaysOfWeek_DAYSOFWEEK_SATURDAY_tfs), ( 0x20 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Sixth,
{ "Sixth", "atsvc.DaysOfMonth.Sixth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Sixth_tfs), ( 0x00000020 ), NULL, HFILL }},
{ &hf_atsvc_job_id,
{ "Job Id", "atsvc.job_id", FT_UINT32, BASE_DEC, NULL, 0, "Identifier of the scheduled job", HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Twentysixth,
{ "Twentysixth", "atsvc.DaysOfMonth.Twentysixth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Twentysixth_tfs), ( 0x02000000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Fifth,
{ "Fifth", "atsvc.DaysOfMonth.Fifth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Fifth_tfs), ( 0x00000010 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Fourth,
{ "Fourth", "atsvc.DaysOfMonth.Fourth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Fourth_tfs), ( 0x00000008 ), NULL, HFILL }},
{ &hf_atsvc_job_info,
{ "JobInfo", "atcvs.job_info", FT_NONE, BASE_NONE, NULL, 0, "JobInfo structure", HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Eleventh,
{ "Eleventh", "atsvc.DaysOfMonth.Eleventh", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Eleventh_tfs), ( 0x00000400 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Sixteenth,
{ "Sixteenth", "atsvc.DaysOfMonth.Sixteenth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Sixteenth_tfs), ( 0x00008000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_Flags_JOB_ADD_CURRENT_DATE,
{ "Job Add Current Date", "atsvc.Flags.JOB_ADD_CURRENT_DATE", FT_BOOLEAN, 8, TFS(&atsvc_Flags_JOB_ADD_CURRENT_DATE_tfs), ( 0x08 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_JobEnum_ctr,
{ "Ctr", "atsvc.JobEnum.ctr", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Twentyfifth,
{ "Twentyfifth", "atsvc.DaysOfMonth.Twentyfifth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Twentyfifth_tfs), ( 0x01000000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_JobInfo_days_of_month,
{ "Days Of Month", "atsvc.JobInfo.days_of_month", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Twentysecond,
{ "Twentysecond", "atsvc.DaysOfMonth.Twentysecond", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Twentysecond_tfs), ( 0x00200000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_First,
{ "First", "atsvc.DaysOfMonth.First", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_First_tfs), ( 0x00000001 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_JobEnumInfo_command,
{ "Command", "atsvc.JobEnumInfo.command", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Thirtieth,
{ "Thirtieth", "atsvc.DaysOfMonth.Thirtieth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Thirtieth_tfs), ( 0x20000000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Eight,
{ "Eight", "atsvc.DaysOfMonth.Eight", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Eight_tfs), ( 0x00000080 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Twentyfirst,
{ "Twentyfirst", "atsvc.DaysOfMonth.Twentyfirst", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Twentyfirst_tfs), ( 0x00100000 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_Flags_JOB_EXEC_ERROR,
{ "Job Exec Error", "atsvc.Flags.JOB_EXEC_ERROR", FT_BOOLEAN, 8, TFS(&atsvc_Flags_JOB_EXEC_ERROR_tfs), ( 0x02 ), NULL, HFILL }},
{ &hf_atsvc_atsvc_JobInfo_days_of_week,
{ "Days Of Week", "atsvc.JobInfo.days_of_week", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_JobDel_min_job_id,
{ "Min Job Id", "atsvc.JobDel.min_job_id", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_JobEnumInfo_days_of_week,
{ "Days Of Week", "atsvc.JobEnumInfo.days_of_week", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_JobEnumInfo_flags,
{ "Flags", "atsvc.JobEnumInfo.flags", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_JobDel_max_job_id,
{ "Max Job Id", "atsvc.JobDel.max_job_id", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_atsvc_atsvc_DaysOfMonth_Thitteenth,
{ "Thitteenth", "atsvc.DaysOfMonth.Thitteenth", FT_BOOLEAN, 32, TFS(&atsvc_DaysOfMonth_Thitteenth_tfs), ( 0x00001000 ), NULL, HFILL }},
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
