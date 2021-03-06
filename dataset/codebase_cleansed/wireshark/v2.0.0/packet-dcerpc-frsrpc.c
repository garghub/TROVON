static int
frsrpc_dissect_element_CommPktChangeOrderCommand_file_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di, guint8 *drep _U_)
{
int conformant = di->conformant_run;
if (!conformant) {
guint32 soffset = dissect_null_term_wstring(tvb, offset, pinfo, tree, drep, hf_frsrpc_CommPktChangeOrderCommand_file_name, 0);
DISSECTOR_ASSERT(soffset - offset < 261);
offset += 261;
}
return offset;
}
int
frsrpc_dissect_struct_CommPktChunk(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
guint1632 type = 0;
int i = 0;
const char *s = NULL;
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_frsrpc_frsrpc_CommPktChunk);
}
offset = frsrpc_dissect_element_CommPktChunk_type(tvb, offset, pinfo, tree, di, drep, &type);
offset = frsrpc_dissect_element_CommPktChunk_data(tvb, offset, pinfo, tree, di, drep, &type);
for (i=0; frsrpc_frsrpc_CommPktChunkType_vals[i].strptr; i++) {
if (frsrpc_frsrpc_CommPktChunkType_vals[i].value == type) {
s = frsrpc_frsrpc_CommPktChunkType_vals[i].strptr;
}
}
if (s != NULL) {
proto_item_append_text(item, ", type = %s", s);
}
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_3_BYTES;
}
return offset;
}
int
frsrpc_dissect_enum_CommPktCommand(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
{
guint32 parameter=0;
int i = 0;
const char *s = NULL;
if(param){
parameter=(guint32)*param;
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
for (i=0; frsrpc_frsrpc_CommPktCommand_vals[i].strptr != NULL; i++) {
if (frsrpc_frsrpc_CommPktCommand_vals[i].value == parameter) {
s = frsrpc_frsrpc_CommPktCommand_vals[i].strptr;
}
}
if (s!= NULL)
col_append_fstr(pinfo->cinfo, COL_INFO, ",command = %s",
s);
if(param){
*param=(guint32)parameter;
}
return offset;
}
static int
frsrpc_dissect_struct_frsrpc_CommPktChunkCtr(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, dcerpc_info* di, guint8 *drep _U_, int hf_index, guint32 param _U_)
{
guint32 nb_chunk = 0;
guint32 remaining = tvb_reported_length_remaining(tvb, offset);
int align_status = di->no_align;
if (remaining > 0) {
proto_item *item = proto_tree_add_item(tree, hf_index, tvb, offset, -1, TRUE);
proto_tree *subtree = proto_item_add_subtree(item, ett_ChunkCtr);
di->no_align = 1;
for(nb_chunk = 0; remaining > 0; nb_chunk++) {
offset = frsrpc_dissect_struct_CommPktChunk(tvb, offset, pinfo, subtree, di, drep, hf_CommPktChunk, param);
remaining = tvb_reported_length_remaining(tvb, offset);
}
di->no_align = align_status;
}
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkGuidName_guid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint3264 size;
int conformant = di->conformant_run;
tvbuff_t *subtvb;
if (!conformant) {
guint32 saved_flags = di->call_data->flags;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChunkGuidName_guid_, &size);
di->call_data->flags &= ~DCERPC_IS_NDR64;
subtvb = tvb_new_subset(tvb, offset, (const gint)size, -1);
frsrpc_dissect_element_CommPktChunkGuidName_guid_(subtvb, 0, pinfo, tree, di, drep);
offset += (int)size;
di->call_data->flags = saved_flags;
}
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkGuidName_guid_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uuid_t(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChunkGuidName_guid, NULL);
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkGuidName_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint3264 size;
int conformant = di->conformant_run;
tvbuff_t *subtvb;
if (!conformant) {
guint32 saved_flags = di->call_data->flags;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChunkGuidName_name_, &size);
di->call_data->flags &= ~DCERPC_IS_NDR64;
subtvb = tvb_new_subset(tvb, offset, (const gint)size, -1);
frsrpc_dissect_element_CommPktChunkGuidName_name_(subtvb, 0, pinfo, tree, di, drep);
offset += (int)size;
di->call_data->flags = saved_flags;
}
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkGuidName_name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_null_term_wstring(tvb, offset, pinfo, tree, drep, hf_frsrpc_frsrpc_CommPktChunkGuidName_name , 0);
return offset;
}
int
frsrpc_dissect_struct_CommPktChunkGuidName(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_frsrpc_frsrpc_CommPktChunkGuidName);
}
offset = frsrpc_dissect_element_CommPktChunkGuidName_guid(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChunkGuidName_name(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
frsrpc_dissect_element_CommPktGSVN_vsn(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uint64(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktGSVN_vsn, NULL);
return offset;
}
static int
frsrpc_dissect_element_CommPktGSVN_guid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uuid_t(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktGSVN_guid, NULL);
return offset;
}
int
frsrpc_dissect_struct_CommPktGSVN(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_8_BYTES;
ALIGN_TO_8_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_frsrpc_frsrpc_CommPktGSVN);
}
offset = frsrpc_dissect_element_CommPktGSVN_vsn(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktGSVN_guid(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_8_BYTES;
}
return offset;
}
int
frsrpc_dissect_bitmap_CommPktCoCmdFlags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint32 flags;
ALIGN_TO_4_BYTES;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, 4, DREP_ENC_INTEGER(drep));
tree = proto_item_add_subtree(item,ett_frsrpc_frsrpc_CommPktCoCmdFlags);
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, -1, &flags);
proto_item_append_text(item, ": ");
if (!flags)
proto_item_append_text(item, "(No values set)");
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_ABORT_CO, tvb, offset-4, 4, flags);
if (flags&( 0x00000001 )){
proto_item_append_text(item, "FRSRPC_CO_FLAG_ABORT_CO");
if (flags & (~( 0x00000001 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000001 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_VV_ACTIVATED, tvb, offset-4, 4, flags);
if (flags&( 0x00000002 )){
proto_item_append_text(item, "FRSRPC_CO_FLAG_VV_ACTIVATED");
if (flags & (~( 0x00000002 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000002 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_CONTENT_CMD, tvb, offset-4, 4, flags);
if (flags&( 0x00000004 )){
proto_item_append_text(item, "FRSRPC_CO_FLAG_CONTENT_CMD");
if (flags & (~( 0x00000004 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000004 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_LOCATION_CMD, tvb, offset-4, 4, flags);
if (flags&( 0x00000008 )){
proto_item_append_text(item, "FRSRPC_CO_FLAG_LOCATION_CMD");
if (flags & (~( 0x00000008 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000008 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_ONLIST, tvb, offset-4, 4, flags);
if (flags&( 0x00000010 )){
proto_item_append_text(item, "FRSRPC_CO_FLAG_ONLIST");
if (flags & (~( 0x00000010 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000010 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_LOCALCO, tvb, offset-4, 4, flags);
if (flags&( 0x00000020 )){
proto_item_append_text(item, "FRSRPC_CO_FLAG_LOCALCO");
if (flags & (~( 0x00000020 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000020 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_RETRY, tvb, offset-4, 4, flags);
if (flags&( 0x00000040 )){
proto_item_append_text(item, "FRSRPC_CO_FLAG_RETRY");
if (flags & (~( 0x00000040 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000040 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_OUT_OF_ORDER, tvb, offset-4, 4, flags);
if (flags&( 0x00000200 )){
proto_item_append_text(item, "FRSRPC_CO_FLAG_OUT_OF_ORDER");
if (flags & (~( 0x00000200 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000200 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_NEW_FILE, tvb, offset-4, 4, flags);
if (flags&( 0x00000400 )){
proto_item_append_text(item, "FRSRPC_CO_FLAG_NEW_FILE");
if (flags & (~( 0x00000400 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000400 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_CONTROL, tvb, offset-4, 4, flags);
if (flags&( 0x00001000 )){
proto_item_append_text(item, "FRSRPC_CO_FLAG_CONTROL");
if (flags & (~( 0x00001000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00001000 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_DIRECTED_CO, tvb, offset-4, 4, flags);
if (flags&( 0x00002000 )){
proto_item_append_text(item, "FRSRPC_CO_FLAG_DIRECTED_CO");
if (flags & (~( 0x00002000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00002000 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_VVJOIN_TO_ORIG, tvb, offset-4, 4, flags);
if (flags&( 0x00040000 )){
proto_item_append_text(item, "FRSRPC_CO_FLAG_VVJOIN_TO_ORIG");
if (flags & (~( 0x00040000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00040000 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_SKIP_ORIG_REC_C, tvb, offset-4, 4, flags);
if (flags&( 0x00100000 )){
proto_item_append_text(item, "FRSRPC_CO_FLAG_SKIP_ORIG_REC_C");
if (flags & (~( 0x00100000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00100000 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_MOVEIN_GEN, tvb, offset-4, 4, flags);
if (flags&( 0x00200000 )){
proto_item_append_text(item, "FRSRPC_CO_FLAG_MOVEIN_GEN");
if (flags & (~( 0x00200000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00200000 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_MORPH_GEN_HEAD, tvb, offset-4, 4, flags);
if (flags&( 0x00400000 )){
proto_item_append_text(item, "FRSRPC_CO_FLAG_MORPH_GEN_HEAD");
if (flags & (~( 0x00400000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00400000 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_JUST_OID_RESET, tvb, offset-4, 4, flags);
if (flags&( 0x00800000 )){
proto_item_append_text(item, "FRSRPC_CO_FLAG_JUST_OID_RESET");
if (flags & (~( 0x00800000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00800000 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_COMPRESSED_STAGE, tvb, offset-4, 4, flags);
if (flags&( 0x01000000 )){
proto_item_append_text(item, "FRSRPC_CO_FLAG_COMPRESSED_STAGE");
if (flags & (~( 0x01000000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x01000000 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_SKIP_VV_UPDATE, tvb, offset-4, 4, flags);
if (flags&( 0x02000000 )){
proto_item_append_text(item, "FRSRPC_CO_FLAG_SKIP_VV_UPDATE");
if (flags & (~( 0x02000000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x02000000 ));
if (flags) {
proto_item_append_text(item, "Unknown bitmap value 0x%x", flags);
}
return offset;
}
int
frsrpc_dissect_bitmap_CommPktCoCmdIFlags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint32 flags;
ALIGN_TO_4_BYTES;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, 4, DREP_ENC_INTEGER(drep));
tree = proto_item_add_subtree(item,ett_frsrpc_frsrpc_CommPktCoCmdIFlags);
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, -1, &flags);
proto_item_append_text(item, ": ");
if (!flags)
proto_item_append_text(item, "(No values set)");
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdIFlags_FRSRPC_CO_IFLAG_VVRETIRE_EXEC, tvb, offset-4, 4, flags);
if (flags&( 0x00000001 )){
proto_item_append_text(item, "FRSRPC_CO_IFLAG_VVRETIRE_EXEC");
if (flags & (~( 0x00000001 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000001 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdIFlags_FRSRPC_CO_IFLAG_CO_ABORT, tvb, offset-4, 4, flags);
if (flags&( 0x00000002 )){
proto_item_append_text(item, "FRSRPC_CO_IFLAG_CO_ABORT");
if (flags & (~( 0x00000002 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000002 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdIFlags_FRSRPC_CO_IFLAG_DIR_ENUM_PENDING, tvb, offset-4, 4, flags);
if (flags&( 0x00000004 )){
proto_item_append_text(item, "FRSRPC_CO_IFLAG_DIR_ENUM_PENDING");
if (flags & (~( 0x00000004 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000004 ));
if (flags) {
proto_item_append_text(item, "Unknown bitmap value 0x%x", flags);
}
return offset;
}
int
frsrpc_dissect_enum_CommPktCoCmdStatus(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
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
frsrpc_dissect_bitmap_CommPktCoCmdContentCmd(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint32 flags;
ALIGN_TO_4_BYTES;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, 4, DREP_ENC_INTEGER(drep));
tree = proto_item_add_subtree(item,ett_frsrpc_frsrpc_CommPktCoCmdContentCmd);
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, -1, &flags);
proto_item_append_text(item, ": ");
if (!flags)
proto_item_append_text(item, "(No values set)");
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_DATA_OVERWRITE, tvb, offset-4, 4, flags);
if (flags&( 0x00000001 )){
proto_item_append_text(item, "FRSRPC_CONTENT_REASON_DATA_OVERWRITE");
if (flags & (~( 0x00000001 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000001 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_DATA_EXTEND, tvb, offset-4, 4, flags);
if (flags&( 0x00000002 )){
proto_item_append_text(item, "FRSRPC_CONTENT_REASON_DATA_EXTEND");
if (flags & (~( 0x00000002 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000002 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_DATA_TRUNCATION, tvb, offset-4, 4, flags);
if (flags&( 0x00000004 )){
proto_item_append_text(item, "FRSRPC_CONTENT_REASON_DATA_TRUNCATION");
if (flags & (~( 0x00000004 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000004 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_NAMED_DATA_OVERWRITE, tvb, offset-4, 4, flags);
if (flags&( 0x00000010 )){
proto_item_append_text(item, "FRSRPC_CONTENT_REASON_NAMED_DATA_OVERWRITE");
if (flags & (~( 0x00000010 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000010 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_NAMED_DATA_EXTEND, tvb, offset-4, 4, flags);
if (flags&( 0x00000020 )){
proto_item_append_text(item, "FRSRPC_CONTENT_REASON_NAMED_DATA_EXTEND");
if (flags & (~( 0x00000020 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000020 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_NAMED_DATA_TRUNCATION, tvb, offset-4, 4, flags);
if (flags&( 0x00000040 )){
proto_item_append_text(item, "FRSRPC_CONTENT_REASON_NAMED_DATA_TRUNCATION");
if (flags & (~( 0x00000040 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000040 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_FILE_CREATE, tvb, offset-4, 4, flags);
if (flags&( 0x00000100 )){
proto_item_append_text(item, "FRSRPC_CONTENT_REASON_FILE_CREATE");
if (flags & (~( 0x00000100 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000100 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_FILE_DELETE, tvb, offset-4, 4, flags);
if (flags&( 0x00000200 )){
proto_item_append_text(item, "FRSRPC_CONTENT_REASON_FILE_DELETE");
if (flags & (~( 0x00000200 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000200 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_EA_CHANGE, tvb, offset-4, 4, flags);
if (flags&( 0x00000400 )){
proto_item_append_text(item, "FRSRPC_CONTENT_REASON_EA_CHANGE");
if (flags & (~( 0x00000400 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000400 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_SECURITY_CHANGE, tvb, offset-4, 4, flags);
if (flags&( 0x00000800 )){
proto_item_append_text(item, "FRSRPC_CONTENT_REASON_SECURITY_CHANGE");
if (flags & (~( 0x00000800 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000800 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_OLD_NAME, tvb, offset-4, 4, flags);
if (flags&( 0x00001000 )){
proto_item_append_text(item, "FRSRPC_CONTENT_REASON_OLD_NAME");
if (flags & (~( 0x00001000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00001000 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_NEW_NAME, tvb, offset-4, 4, flags);
if (flags&( 0x00002000 )){
proto_item_append_text(item, "FRSRPC_CONTENT_REASON_NEW_NAME");
if (flags & (~( 0x00002000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00002000 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_BASIC_INFO_CHANGE, tvb, offset-4, 4, flags);
if (flags&( 0x00004000 )){
proto_item_append_text(item, "FRSRPC_CONTENT_REASON_BASIC_INFO_CHANGE");
if (flags & (~( 0x00004000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00004000 ));
proto_tree_add_boolean(tree, hf_frsrpc_frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_COMPRESSION_CHANGE, tvb, offset-4, 4, flags);
if (flags&( 0x00020000 )){
proto_item_append_text(item, "FRSRPC_CONTENT_REASON_COMPRESSION_CHANGE");
if (flags & (~( 0x00020000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00020000 ));
if (flags) {
proto_item_append_text(item, "Unknown bitmap value 0x%x", flags);
}
return offset;
}
int
frsrpc_dissect_enum_CommPktCoCmdLocationCmd(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
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
frsrpc_dissect_element_CommPktChangeOrderCommand_sequence_number(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_sequence_number, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_flags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = frsrpc_dissect_bitmap_CommPktCoCmdFlags(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_flags, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_iflags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = frsrpc_dissect_bitmap_CommPktCoCmdIFlags(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_iflags, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = frsrpc_dissect_enum_CommPktCoCmdStatus(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_status, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_content_cmd(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = frsrpc_dissect_bitmap_CommPktCoCmdContentCmd(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_content_cmd, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_location_cmd(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = frsrpc_dissect_enum_CommPktCoCmdLocationCmd(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_location_cmd, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_file_attributes(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_file_attributes, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_file_version_number(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_file_version_number, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_partern_ack_sequence_number(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_partern_ack_sequence_number, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_not_used(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_not_used, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_file_size(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uint64(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_file_size, NULL);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_file_offset(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uint64(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_file_offset, NULL);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_frs_vsn(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uint64(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_frs_vsn, NULL);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_file_usn(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uint64(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_file_usn, NULL);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_jrnl_usn(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uint64(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_jrnl_usn, NULL);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_jrnl_first_usn(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uint64(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_jrnl_first_usn, NULL);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_original_replica_num(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_original_replica_num, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_new_replica_num(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_new_replica_num, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_change_order_guid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uuid_t(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_change_order_guid, NULL);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_originator_guid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uuid_t(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_originator_guid, NULL);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_file_guid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uuid_t(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_file_guid, NULL);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_old_parent_guid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uuid_t(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_old_parent_guid, NULL);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_new_parent_guid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uuid_t(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_new_parent_guid, NULL);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_connection_guid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uuid_t(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_connection_guid, NULL);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_ack_version(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uint64(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_ack_version, NULL);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_spare2ul1(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uint64(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_spare2ul1, NULL);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_spare1guid_p1(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uint64(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_spare1guid_p1, NULL);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_spare1guid_p2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uint64(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_spare1guid_p2, NULL);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_spare2guid_p1(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uint64(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_spare2guid_p1, NULL);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_spare3guid_p2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uint64(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_spare3guid_p2, NULL);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_spare1wcs(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_spare1wcs, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_spare2wcs(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_spare2wcs, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_extension(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_extension, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_spare2bin(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_spare2bin, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_event_time(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_event_time);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_file_name_length(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_file_name_length, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_padding1(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_padding1, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_padding2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_padding2, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_padding3(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_padding3, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderCommand_padding4(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderCommand_padding4, 0);
return offset;
}
int
frsrpc_dissect_struct_CommPktChangeOrderCommand(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_8_BYTES;
ALIGN_TO_8_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_frsrpc_frsrpc_CommPktChangeOrderCommand);
}
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_sequence_number(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_flags(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_iflags(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_status(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_content_cmd(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_location_cmd(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_file_attributes(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_file_version_number(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_partern_ack_sequence_number(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_not_used(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_file_size(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_file_offset(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_frs_vsn(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_file_usn(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_jrnl_usn(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_jrnl_first_usn(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_original_replica_num(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_new_replica_num(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_change_order_guid(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_originator_guid(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_file_guid(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_old_parent_guid(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_new_parent_guid(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_connection_guid(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_ack_version(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_spare2ul1(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_spare1guid_p1(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_spare1guid_p2(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_spare2guid_p1(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_spare3guid_p2(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_spare1wcs(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_spare2wcs(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_extension(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_spare2bin(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_event_time(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_file_name_length(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_file_name(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_padding1(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_padding2(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_padding3(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderCommand_padding4(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_8_BYTES;
}
return offset;
}
int
frsrpc_dissect_enum_CommPktDataExtensionType(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
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
frsrpc_dissect_element_CommPktDataExtensionChecksum_prefix_size(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktDataExtensionChecksum_prefix_size, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktDataExtensionChecksum_prefix_type(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = frsrpc_dissect_enum_CommPktDataExtensionType(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktDataExtensionChecksum_prefix_type, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktDataExtensionChecksum_data(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
int i;
for (i = 0; i < 16; i++)
offset = frsrpc_dissect_element_CommPktDataExtensionChecksum_data_(tvb, offset, pinfo, tree, di, drep);
return offset;
}
static int
frsrpc_dissect_element_CommPktDataExtensionChecksum_data_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktDataExtensionChecksum_data, 0);
return offset;
}
int
frsrpc_dissect_struct_CommPktDataExtensionChecksum(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_frsrpc_frsrpc_CommPktDataExtensionChecksum);
}
offset = frsrpc_dissect_element_CommPktDataExtensionChecksum_prefix_size(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktDataExtensionChecksum_prefix_type(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktDataExtensionChecksum_data(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
static int
frsrpc_dissect_element_CommPktDataExtensionRetryTimeout_prefix_size(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktDataExtensionRetryTimeout_prefix_size, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktDataExtensionRetryTimeout_prefix_type(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = frsrpc_dissect_enum_CommPktDataExtensionType(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktDataExtensionRetryTimeout_prefix_type, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktDataExtensionRetryTimeout_count(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktDataExtensionRetryTimeout_count, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktDataExtensionRetryTimeout_not_used(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktDataExtensionRetryTimeout_not_used, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktDataExtensionRetryTimeout_first_try_time(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktDataExtensionRetryTimeout_first_try_time);
return offset;
}
int
frsrpc_dissect_struct_CommPktDataExtensionRetryTimeout(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_frsrpc_frsrpc_CommPktDataExtensionRetryTimeout);
}
offset = frsrpc_dissect_element_CommPktDataExtensionRetryTimeout_prefix_size(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktDataExtensionRetryTimeout_prefix_type(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktDataExtensionRetryTimeout_count(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktDataExtensionRetryTimeout_not_used(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktDataExtensionRetryTimeout_first_try_time(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
int
frsrpc_dissect_enum_CommPktCoRecordExtensionMajor(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint1632 *param _U_)
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
frsrpc_dissect_element_CommPktCoRecordExtensionWin2k_field_size(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktCoRecordExtensionWin2k_field_size, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktCoRecordExtensionWin2k_major(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = frsrpc_dissect_enum_CommPktCoRecordExtensionMajor(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktCoRecordExtensionWin2k_major, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktCoRecordExtensionWin2k_offset_count(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktCoRecordExtensionWin2k_offset_count, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktCoRecordExtensionWin2k_offset(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktCoRecordExtensionWin2k_offset, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktCoRecordExtensionWin2k_offset_last(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktCoRecordExtensionWin2k_offset_last, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktCoRecordExtensionWin2k_data_checksum(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = frsrpc_dissect_struct_CommPktDataExtensionChecksum(tvb,offset,pinfo,tree,di,drep,hf_frsrpc_frsrpc_CommPktCoRecordExtensionWin2k_data_checksum,0);
return offset;
}
int
frsrpc_dissect_struct_CommPktCoRecordExtensionWin2k(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_frsrpc_frsrpc_CommPktCoRecordExtensionWin2k);
}
offset = frsrpc_dissect_element_CommPktCoRecordExtensionWin2k_field_size(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktCoRecordExtensionWin2k_major(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktCoRecordExtensionWin2k_offset_count(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktCoRecordExtensionWin2k_offset(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktCoRecordExtensionWin2k_offset_last(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktCoRecordExtensionWin2k_data_checksum(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderRecordExtension_field_size(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderRecordExtension_field_size, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderRecordExtension_major(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = frsrpc_dissect_enum_CommPktCoRecordExtensionMajor(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderRecordExtension_major, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderRecordExtension_offset_count(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderRecordExtension_offset_count, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderRecordExtension_offset0(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderRecordExtension_offset0, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderRecordExtension_offset1(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderRecordExtension_offset1, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderRecordExtension_offset_last(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderRecordExtension_offset_last, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderRecordExtension_not_used(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChangeOrderRecordExtension_not_used, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderRecordExtension_data_checksum(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = frsrpc_dissect_struct_CommPktDataExtensionChecksum(tvb,offset,pinfo,tree,di,drep,hf_frsrpc_frsrpc_CommPktChangeOrderRecordExtension_data_checksum,0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChangeOrderRecordExtension_data_retry_timeout(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = frsrpc_dissect_struct_CommPktDataExtensionRetryTimeout(tvb,offset,pinfo,tree,di,drep,hf_frsrpc_frsrpc_CommPktChangeOrderRecordExtension_data_retry_timeout,0);
return offset;
}
int
frsrpc_dissect_struct_CommPktChangeOrderRecordExtension(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_frsrpc_frsrpc_CommPktChangeOrderRecordExtension);
}
offset = frsrpc_dissect_element_CommPktChangeOrderRecordExtension_field_size(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderRecordExtension_major(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderRecordExtension_offset_count(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderRecordExtension_offset0(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderRecordExtension_offset1(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderRecordExtension_offset_last(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderRecordExtension_not_used(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderRecordExtension_data_checksum(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_CommPktChangeOrderRecordExtension_data_retry_timeout(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
int
frsrpc_dissect_enum_CommPktChunkType(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint1632 *param _U_)
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
frsrpc_dissect_element_CommPktChunkData_blob(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_datablob(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChunkData_blob, 1);
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkData_bop(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChunkData_bop, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkData_command(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = frsrpc_dissect_enum_CommPktCommand(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChunkData_command, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkData_to(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = frsrpc_dissect_struct_CommPktChunkGuidName(tvb,offset,pinfo,tree,di,drep,hf_frsrpc_frsrpc_CommPktChunkData_to,0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkData_from(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = frsrpc_dissect_struct_CommPktChunkGuidName(tvb,offset,pinfo,tree,di,drep,hf_frsrpc_frsrpc_CommPktChunkData_from,0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkData_replica(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = frsrpc_dissect_struct_CommPktChunkGuidName(tvb,offset,pinfo,tree,di,drep,hf_frsrpc_frsrpc_CommPktChunkData_replica,0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkData_connection(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = frsrpc_dissect_struct_CommPktChunkGuidName(tvb,offset,pinfo,tree,di,drep,hf_frsrpc_frsrpc_CommPktChunkData_connection,0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkData_join_guid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint3264 size;
int conformant = di->conformant_run;
tvbuff_t *subtvb;
if (!conformant) {
guint32 saved_flags = di->call_data->flags;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChunkData_join_guid_, &size);
di->call_data->flags &= ~DCERPC_IS_NDR64;
subtvb = tvb_new_subset(tvb, offset, (const gint)size, -1);
frsrpc_dissect_element_CommPktChunkData_join_guid_(subtvb, 0, pinfo, tree, di, drep);
offset += (int)size;
di->call_data->flags = saved_flags;
}
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkData_join_guid_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uuid_t(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChunkData_join_guid, NULL);
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkData_last_join_time(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChunkData_last_join_time);
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkData_vvector(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint3264 size;
int conformant = di->conformant_run;
tvbuff_t *subtvb;
if (!conformant) {
guint32 saved_flags = di->call_data->flags;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChunkData_vvector_, &size);
di->call_data->flags &= ~DCERPC_IS_NDR64;
subtvb = tvb_new_subset(tvb, offset, (const gint)size, -1);
frsrpc_dissect_element_CommPktChunkData_vvector_(subtvb, 0, pinfo, tree, di, drep);
offset += (int)size;
di->call_data->flags = saved_flags;
}
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkData_vvector_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = frsrpc_dissect_struct_CommPktGSVN(tvb,offset,pinfo,tree,di,drep,hf_frsrpc_frsrpc_CommPktChunkData_vvector,0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkData_join_time(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint3264 size;
int conformant = di->conformant_run;
tvbuff_t *subtvb;
if (!conformant) {
guint32 saved_flags = di->call_data->flags;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChunkData_join_time_, &size);
di->call_data->flags &= ~DCERPC_IS_NDR64;
subtvb = tvb_new_subset(tvb, offset, (const gint)size, -1);
frsrpc_dissect_element_CommPktChunkData_join_time_(subtvb, 0, pinfo, tree, di, drep);
offset += (int)size;
di->call_data->flags = saved_flags;
}
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkData_join_time_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChunkData_join_time);
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkData_replica_version_guid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint3264 size;
int conformant = di->conformant_run;
tvbuff_t *subtvb;
if (!conformant) {
guint32 saved_flags = di->call_data->flags;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChunkData_replica_version_guid_, &size);
di->call_data->flags &= ~DCERPC_IS_NDR64;
subtvb = tvb_new_subset(tvb, offset, (const gint)size, -1);
frsrpc_dissect_element_CommPktChunkData_replica_version_guid_(subtvb, 0, pinfo, tree, di, drep);
offset += (int)size;
di->call_data->flags = saved_flags;
}
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkData_replica_version_guid_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uuid_t(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChunkData_replica_version_guid, NULL);
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkData_compression_guid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uuid_t(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChunkData_compression_guid, NULL);
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkData_block(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_datablob(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChunkData_block, 1);
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkData_block_size(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uint64(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChunkData_block_size, NULL);
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkData_file_size(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uint64(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChunkData_file_size, NULL);
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkData_file_offset(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uint64(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChunkData_file_offset, NULL);
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkData_gvsn(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint3264 size;
int conformant = di->conformant_run;
tvbuff_t *subtvb;
if (!conformant) {
guint32 saved_flags = di->call_data->flags;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChunkData_gvsn_, &size);
di->call_data->flags &= ~DCERPC_IS_NDR64;
subtvb = tvb_new_subset(tvb, offset, (const gint)size, -1);
frsrpc_dissect_element_CommPktChunkData_gvsn_(subtvb, 0, pinfo, tree, di, drep);
offset += (int)size;
di->call_data->flags = saved_flags;
}
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkData_gvsn_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = frsrpc_dissect_struct_CommPktGSVN(tvb,offset,pinfo,tree,di,drep,hf_frsrpc_frsrpc_CommPktChunkData_gvsn,0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkData_co_guid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint3264 size;
int conformant = di->conformant_run;
tvbuff_t *subtvb;
if (!conformant) {
guint32 saved_flags = di->call_data->flags;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChunkData_co_guid_, &size);
di->call_data->flags &= ~DCERPC_IS_NDR64;
subtvb = tvb_new_subset(tvb, offset, (const gint)size, -1);
frsrpc_dissect_element_CommPktChunkData_co_guid_(subtvb, 0, pinfo, tree, di, drep);
offset += (int)size;
di->call_data->flags = saved_flags;
}
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkData_co_guid_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uuid_t(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChunkData_co_guid, NULL);
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkData_co_sequnence_number(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChunkData_co_sequnence_number, 0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkData_remote_co(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint3264 size;
int conformant = di->conformant_run;
tvbuff_t *subtvb;
if (!conformant) {
guint32 saved_flags = di->call_data->flags;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChunkData_remote_co_, &size);
di->call_data->flags &= ~DCERPC_IS_NDR64;
subtvb = tvb_new_subset(tvb, offset, (const gint)size, -1);
frsrpc_dissect_element_CommPktChunkData_remote_co_(subtvb, 0, pinfo, tree, di, drep);
offset += (int)size;
di->call_data->flags = saved_flags;
}
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkData_remote_co_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = frsrpc_dissect_struct_CommPktChangeOrderCommand(tvb,offset,pinfo,tree,di,drep,hf_frsrpc_frsrpc_CommPktChunkData_remote_co,0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkData_co_ext_win2k(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint3264 size;
int conformant = di->conformant_run;
tvbuff_t *subtvb;
if (!conformant) {
guint32 saved_flags = di->call_data->flags;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChunkData_co_ext_win2k_, &size);
di->call_data->flags &= ~DCERPC_IS_NDR64;
subtvb = tvb_new_subset(tvb, offset, (const gint)size, -1);
frsrpc_dissect_element_CommPktChunkData_co_ext_win2k_(subtvb, 0, pinfo, tree, di, drep);
offset += (int)size;
di->call_data->flags = saved_flags;
}
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkData_co_ext_win2k_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = frsrpc_dissect_struct_CommPktCoRecordExtensionWin2k(tvb,offset,pinfo,tree,di,drep,hf_frsrpc_frsrpc_CommPktChunkData_co_ext_win2k,0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkData_co_extension2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = frsrpc_dissect_struct_CommPktChangeOrderRecordExtension(tvb,offset,pinfo,tree,di,drep,hf_frsrpc_frsrpc_CommPktChunkData_co_extension2,0);
return offset;
}
static int
frsrpc_dissect_element_CommPktChunkData_bopend(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChunkData_bopend, 0);
return offset;
}
static int
frsrpc_dissect_CommPktChunkData(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
guint32 level = param;
old_offset = offset;
if (parent_tree) {
tree = proto_tree_add_subtree(parent_tree, tvb, offset, -1, ett_frsrpc_frsrpc_CommPktChunkData, &item, "frsrpc_CommPktChunkData");
}
switch(level) {
default:
offset = frsrpc_dissect_element_CommPktChunkData_blob(tvb, offset, pinfo, tree, di, drep);
break;
case FRSRPC_COMM_PKT_CHUNK_BOP:
offset = frsrpc_dissect_element_CommPktChunkData_bop(tvb, offset, pinfo, tree, di, drep);
break;
case FRSRPC_COMM_PKT_CHUNK_COMMAND:
offset = frsrpc_dissect_element_CommPktChunkData_command(tvb, offset, pinfo, tree, di, drep);
break;
case FRSRPC_COMM_PKT_CHUNK_TO:
offset = frsrpc_dissect_element_CommPktChunkData_to(tvb, offset, pinfo, tree, di, drep);
break;
case FRSRPC_COMM_PKT_CHUNK_FROM:
offset = frsrpc_dissect_element_CommPktChunkData_from(tvb, offset, pinfo, tree, di, drep);
break;
case FRSRPC_COMM_PKT_CHUNK_REPLICA:
offset = frsrpc_dissect_element_CommPktChunkData_replica(tvb, offset, pinfo, tree, di, drep);
break;
case FRSRPC_COMM_PKT_CHUNK_CONNECTION:
offset = frsrpc_dissect_element_CommPktChunkData_connection(tvb, offset, pinfo, tree, di, drep);
break;
case FRSRPC_COMM_PKT_CHUNK_JOIN_GUID:
offset = frsrpc_dissect_element_CommPktChunkData_join_guid(tvb, offset, pinfo, tree, di, drep);
break;
case FRSRPC_COMM_PKT_CHUNK_LAST_JOIN_TIME:
offset = frsrpc_dissect_element_CommPktChunkData_last_join_time(tvb, offset, pinfo, tree, di, drep);
break;
case FRSRPC_COMM_PKT_CHUNK_VVECTOR:
offset = frsrpc_dissect_element_CommPktChunkData_vvector(tvb, offset, pinfo, tree, di, drep);
break;
case FRSRPC_COMM_PKT_CHUNK_JOIN_TIME:
offset = frsrpc_dissect_element_CommPktChunkData_join_time(tvb, offset, pinfo, tree, di, drep);
break;
case FRSRPC_COMM_PKT_CHUNK_REPLICA_VERSION_GUID:
offset = frsrpc_dissect_element_CommPktChunkData_replica_version_guid(tvb, offset, pinfo, tree, di, drep);
break;
case FRSRPC_COMM_PKT_CHUNK_COMPRESSION_GUID:
offset = frsrpc_dissect_element_CommPktChunkData_compression_guid(tvb, offset, pinfo, tree, di, drep);
break;
case FRSRPC_COMM_PKT_CHUNK_BLOCK:
offset = frsrpc_dissect_element_CommPktChunkData_block(tvb, offset, pinfo, tree, di, drep);
break;
case FRSRPC_COMM_PKT_CHUNK_BLOCK_SIZE:
offset = frsrpc_dissect_element_CommPktChunkData_block_size(tvb, offset, pinfo, tree, di, drep);
break;
case FRSRPC_COMM_PKT_CHUNK_FILE_SIZE:
offset = frsrpc_dissect_element_CommPktChunkData_file_size(tvb, offset, pinfo, tree, di, drep);
break;
case FRSRPC_COMM_PKT_CHUNK_FILE_OFFSET:
offset = frsrpc_dissect_element_CommPktChunkData_file_offset(tvb, offset, pinfo, tree, di, drep);
break;
case FRSRPC_COMM_PKT_CHUNK_GVSN:
offset = frsrpc_dissect_element_CommPktChunkData_gvsn(tvb, offset, pinfo, tree, di, drep);
break;
case FRSRPC_COMM_PKT_CHUNK_CO_GUID:
offset = frsrpc_dissect_element_CommPktChunkData_co_guid(tvb, offset, pinfo, tree, di, drep);
break;
case FRSRPC_COMM_PKT_CHUNK_CO_SEQUENCE_NUMBER:
offset = frsrpc_dissect_element_CommPktChunkData_co_sequnence_number(tvb, offset, pinfo, tree, di, drep);
break;
case FRSRPC_COMM_PKT_CHUNK_REMOTE_CO:
offset = frsrpc_dissect_element_CommPktChunkData_remote_co(tvb, offset, pinfo, tree, di, drep);
break;
case FRSRPC_COMM_PKT_CHUNK_CO_EXT_WIN2K:
offset = frsrpc_dissect_element_CommPktChunkData_co_ext_win2k(tvb, offset, pinfo, tree, di, drep);
break;
case FRSRPC_COMM_PKT_CHUNK_CO_EXTENTION_2:
offset = frsrpc_dissect_element_CommPktChunkData_co_extension2(tvb, offset, pinfo, tree, di, drep);
break;
case FRSRPC_COMM_PKT_CHUNK_EOP:
offset = frsrpc_dissect_element_CommPktChunkData_bopend(tvb, offset, pinfo, tree, di, drep);
break;
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
frsrpc_dissect_element_CommPktChunk_type(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, guint1632 *type)
{
offset = frsrpc_dissect_enum_CommPktChunkType(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChunk_type, type);
return offset;
}
static int
frsrpc_dissect_element_CommPktChunk_data(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, guint1632 *type)
{
guint3264 size;
int conformant = di->conformant_run;
tvbuff_t *subtvb;
if (!conformant) {
guint32 saved_flags = di->call_data->flags;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChunk_data_, &size);
di->call_data->flags &= ~DCERPC_IS_NDR64;
subtvb = tvb_new_subset(tvb, offset, (const gint)size, -1);
frsrpc_dissect_element_CommPktChunk_data_(subtvb, 0, pinfo, tree, di, drep, type);
offset += (int)size;
di->call_data->flags = saved_flags;
}
return offset;
}
static int
frsrpc_dissect_element_CommPktChunk_data_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, guint1632 *type)
{
offset = frsrpc_dissect_CommPktChunkData(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_CommPktChunk_data, *type);
return offset;
}
int
frsrpc_dissect_enum_CommPktMajor(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
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
frsrpc_dissect_enum_CommPktMinor(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
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
frsrpc_dissect_element_FrsSendCommPktReq_major(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = frsrpc_dissect_enum_CommPktMajor(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_FrsSendCommPktReq_major, 0);
return offset;
}
static int
frsrpc_dissect_element_FrsSendCommPktReq_minor(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = frsrpc_dissect_enum_CommPktMinor(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_FrsSendCommPktReq_minor, 0);
return offset;
}
static int
frsrpc_dissect_element_FrsSendCommPktReq_cs_id(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_FrsSendCommPktReq_cs_id, 0);
return offset;
}
static int
frsrpc_dissect_element_FrsSendCommPktReq_memory_len(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_FrsSendCommPktReq_memory_len, 0);
return offset;
}
static int
frsrpc_dissect_element_FrsSendCommPktReq_pkt_len(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_FrsSendCommPktReq_pkt_len, 0);
return offset;
}
static int
frsrpc_dissect_element_FrsSendCommPktReq_upk_len(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_FrsSendCommPktReq_upk_len, 0);
return offset;
}
static int
frsrpc_dissect_element_FrsSendCommPktReq_ctr(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, frsrpc_dissect_element_FrsSendCommPktReq_ctr_, NDR_POINTER_UNIQUE, "Pointer to Ctr (frsrpc_CommPktChunkCtr)",hf_frsrpc_frsrpc_FrsSendCommPktReq_ctr);
return offset;
}
static int
frsrpc_dissect_element_FrsSendCommPktReq_ctr_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint3264 size;
int conformant = di->conformant_run;
tvbuff_t *subtvb;
if (!conformant) {
guint32 saved_flags = di->call_data->flags;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_FrsSendCommPktReq_ctr_, &size);
di->call_data->flags &= ~DCERPC_IS_NDR64;
subtvb = tvb_new_subset(tvb, offset, (const gint)size, -1);
frsrpc_dissect_element_FrsSendCommPktReq_ctr__(subtvb, 0, pinfo, tree, di, drep);
offset += (int)size;
di->call_data->flags = saved_flags;
}
return offset;
}
static int
frsrpc_dissect_element_FrsSendCommPktReq_ctr__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = frsrpc_dissect_struct_frsrpc_CommPktChunkCtr(tvb,offset,pinfo,tree,di,drep,hf_frsrpc_frsrpc_FrsSendCommPktReq_ctr,0);
return offset;
}
static int
frsrpc_dissect_element_FrsSendCommPktReq_data_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_FrsSendCommPktReq_data_name, NULL);
return offset;
}
static int
frsrpc_dissect_element_FrsSendCommPktReq_data_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_FrsSendCommPktReq_data_handle, NULL);
return offset;
}
int
frsrpc_dissect_struct_FrsSendCommPktReq(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_5_BYTES;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_frsrpc_frsrpc_FrsSendCommPktReq);
}
offset = frsrpc_dissect_element_FrsSendCommPktReq_major(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_FrsSendCommPktReq_minor(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_FrsSendCommPktReq_cs_id(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_FrsSendCommPktReq_memory_len(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_FrsSendCommPktReq_pkt_len(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_FrsSendCommPktReq_upk_len(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_FrsSendCommPktReq_ctr(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_FrsSendCommPktReq_data_name(tvb, offset, pinfo, tree, di, drep);
offset = frsrpc_dissect_element_FrsSendCommPktReq_data_handle(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
int
frsrpc_dissect_enum_PartnerAuthLevel(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
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
frsrpc_dissect_element_FrsSendCommPkt_req(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = frsrpc_dissect_struct_FrsSendCommPktReq(tvb,offset,pinfo,tree,di,drep,hf_frsrpc_frsrpc_FrsSendCommPkt_req,0);
return offset;
}
static int
frsrpc_dissect_FrsSendCommPkt_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="FrsSendCommPkt";
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
frsrpc_dissect_FrsSendCommPkt_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="FrsSendCommPkt";
offset = frsrpc_dissect_element_FrsSendCommPkt_req(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
frsrpc_dissect_element_FrsVerifyPromotionParent_parent_account(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, frsrpc_dissect_element_FrsVerifyPromotionParent_parent_account_, NDR_POINTER_UNIQUE, "Pointer to Parent Account (uint16)",hf_frsrpc_frsrpc_FrsVerifyPromotionParent_parent_account);
return offset;
}
static int
frsrpc_dissect_element_FrsVerifyPromotionParent_parent_account_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_frsrpc_frsrpc_FrsVerifyPromotionParent_parent_account, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
frsrpc_dissect_element_FrsVerifyPromotionParent_parent_password(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, frsrpc_dissect_element_FrsVerifyPromotionParent_parent_password_, NDR_POINTER_UNIQUE, "Pointer to Parent Password (uint16)",hf_frsrpc_frsrpc_FrsVerifyPromotionParent_parent_password);
return offset;
}
static int
frsrpc_dissect_element_FrsVerifyPromotionParent_parent_password_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_frsrpc_frsrpc_FrsVerifyPromotionParent_parent_password, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
frsrpc_dissect_element_FrsVerifyPromotionParent_replica_set_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, frsrpc_dissect_element_FrsVerifyPromotionParent_replica_set_name_, NDR_POINTER_UNIQUE, "Pointer to Replica Set Name (uint16)",hf_frsrpc_frsrpc_FrsVerifyPromotionParent_replica_set_name);
return offset;
}
static int
frsrpc_dissect_element_FrsVerifyPromotionParent_replica_set_name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_frsrpc_frsrpc_FrsVerifyPromotionParent_replica_set_name, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
frsrpc_dissect_element_FrsVerifyPromotionParent_replica_set_type(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, frsrpc_dissect_element_FrsVerifyPromotionParent_replica_set_type_, NDR_POINTER_UNIQUE, "Pointer to Replica Set Type (uint16)",hf_frsrpc_frsrpc_FrsVerifyPromotionParent_replica_set_type);
return offset;
}
static int
frsrpc_dissect_element_FrsVerifyPromotionParent_replica_set_type_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_frsrpc_frsrpc_FrsVerifyPromotionParent_replica_set_type, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
frsrpc_dissect_element_FrsVerifyPromotionParent_partner_auth_level(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = frsrpc_dissect_enum_PartnerAuthLevel(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_FrsVerifyPromotionParent_partner_auth_level, 0);
return offset;
}
static int
frsrpc_dissect_element_FrsVerifyPromotionParent___ndr_guid_size(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_FrsVerifyPromotionParent___ndr_guid_size, 0);
return offset;
}
static int
frsrpc_dissect_FrsVerifyPromotionParent_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="FrsVerifyPromotionParent";
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
frsrpc_dissect_FrsVerifyPromotionParent_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="FrsVerifyPromotionParent";
offset = frsrpc_dissect_element_FrsVerifyPromotionParent_parent_account(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = frsrpc_dissect_element_FrsVerifyPromotionParent_parent_password(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = frsrpc_dissect_element_FrsVerifyPromotionParent_replica_set_name(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = frsrpc_dissect_element_FrsVerifyPromotionParent_replica_set_type(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = frsrpc_dissect_element_FrsVerifyPromotionParent_partner_auth_level(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = frsrpc_dissect_element_FrsVerifyPromotionParent___ndr_guid_size(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
frsrpc_dissect_element_FrsStartPromotionParent_parent_account(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, frsrpc_dissect_element_FrsStartPromotionParent_parent_account_, NDR_POINTER_UNIQUE, "Pointer to Parent Account (uint16)",hf_frsrpc_frsrpc_FrsStartPromotionParent_parent_account);
return offset;
}
static int
frsrpc_dissect_element_FrsStartPromotionParent_parent_account_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_frsrpc_frsrpc_FrsStartPromotionParent_parent_account, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
frsrpc_dissect_element_FrsStartPromotionParent_parent_password(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, frsrpc_dissect_element_FrsStartPromotionParent_parent_password_, NDR_POINTER_UNIQUE, "Pointer to Parent Password (uint16)",hf_frsrpc_frsrpc_FrsStartPromotionParent_parent_password);
return offset;
}
static int
frsrpc_dissect_element_FrsStartPromotionParent_parent_password_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_frsrpc_frsrpc_FrsStartPromotionParent_parent_password, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
frsrpc_dissect_element_FrsStartPromotionParent_replica_set_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, frsrpc_dissect_element_FrsStartPromotionParent_replica_set_name_, NDR_POINTER_UNIQUE, "Pointer to Replica Set Name (uint16)",hf_frsrpc_frsrpc_FrsStartPromotionParent_replica_set_name);
return offset;
}
static int
frsrpc_dissect_element_FrsStartPromotionParent_replica_set_name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_frsrpc_frsrpc_FrsStartPromotionParent_replica_set_name, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
frsrpc_dissect_element_FrsStartPromotionParent_replica_set_type(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, frsrpc_dissect_element_FrsStartPromotionParent_replica_set_type_, NDR_POINTER_UNIQUE, "Pointer to Replica Set Type (uint16)",hf_frsrpc_frsrpc_FrsStartPromotionParent_replica_set_type);
return offset;
}
static int
frsrpc_dissect_element_FrsStartPromotionParent_replica_set_type_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_frsrpc_frsrpc_FrsStartPromotionParent_replica_set_type, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
frsrpc_dissect_element_FrsStartPromotionParent_connection_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, frsrpc_dissect_element_FrsStartPromotionParent_connection_name_, NDR_POINTER_UNIQUE, "Pointer to Connection Name (uint16)",hf_frsrpc_frsrpc_FrsStartPromotionParent_connection_name);
return offset;
}
static int
frsrpc_dissect_element_FrsStartPromotionParent_connection_name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_frsrpc_frsrpc_FrsStartPromotionParent_connection_name, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
frsrpc_dissect_element_FrsStartPromotionParent_partner_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, frsrpc_dissect_element_FrsStartPromotionParent_partner_name_, NDR_POINTER_UNIQUE, "Pointer to Partner Name (uint16)",hf_frsrpc_frsrpc_FrsStartPromotionParent_partner_name);
return offset;
}
static int
frsrpc_dissect_element_FrsStartPromotionParent_partner_name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_frsrpc_frsrpc_FrsStartPromotionParent_partner_name, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
frsrpc_dissect_element_FrsStartPromotionParent_partner_princ_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, frsrpc_dissect_element_FrsStartPromotionParent_partner_princ_name_, NDR_POINTER_UNIQUE, "Pointer to Partner Princ Name (uint16)",hf_frsrpc_frsrpc_FrsStartPromotionParent_partner_princ_name);
return offset;
}
static int
frsrpc_dissect_element_FrsStartPromotionParent_partner_princ_name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_frsrpc_frsrpc_FrsStartPromotionParent_partner_princ_name, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
frsrpc_dissect_element_FrsStartPromotionParent_partner_auth_level(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = frsrpc_dissect_enum_PartnerAuthLevel(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_FrsStartPromotionParent_partner_auth_level, 0);
return offset;
}
static int
frsrpc_dissect_element_FrsStartPromotionParent___ndr_guid_size(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_FrsStartPromotionParent___ndr_guid_size, 0);
return offset;
}
static int
frsrpc_dissect_element_FrsStartPromotionParent_connection_guid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, frsrpc_dissect_element_FrsStartPromotionParent_connection_guid_, NDR_POINTER_UNIQUE, "Pointer to Connection Guid (GUID)",hf_frsrpc_frsrpc_FrsStartPromotionParent_connection_guid);
return offset;
}
static int
frsrpc_dissect_element_FrsStartPromotionParent_connection_guid_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint3264 size;
int conformant = di->conformant_run;
tvbuff_t *subtvb;
if (!conformant) {
guint32 saved_flags = di->call_data->flags;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_FrsStartPromotionParent_connection_guid_, &size);
di->call_data->flags &= ~DCERPC_IS_NDR64;
subtvb = tvb_new_subset(tvb, offset, (const gint)size, -1);
frsrpc_dissect_element_FrsStartPromotionParent_connection_guid__(subtvb, 0, pinfo, tree, di, drep);
offset += (int)size;
di->call_data->flags = saved_flags;
}
return offset;
}
static int
frsrpc_dissect_element_FrsStartPromotionParent_connection_guid__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uuid_t(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_FrsStartPromotionParent_connection_guid, NULL);
return offset;
}
static int
frsrpc_dissect_element_FrsStartPromotionParent_partner_guid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, frsrpc_dissect_element_FrsStartPromotionParent_partner_guid_, NDR_POINTER_UNIQUE, "Pointer to Partner Guid (GUID)",hf_frsrpc_frsrpc_FrsStartPromotionParent_partner_guid);
return offset;
}
static int
frsrpc_dissect_element_FrsStartPromotionParent_partner_guid_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint3264 size;
int conformant = di->conformant_run;
tvbuff_t *subtvb;
if (!conformant) {
guint32 saved_flags = di->call_data->flags;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_FrsStartPromotionParent_partner_guid_, &size);
di->call_data->flags &= ~DCERPC_IS_NDR64;
subtvb = tvb_new_subset(tvb, offset, (const gint)size, -1);
frsrpc_dissect_element_FrsStartPromotionParent_partner_guid__(subtvb, 0, pinfo, tree, di, drep);
offset += (int)size;
di->call_data->flags = saved_flags;
}
return offset;
}
static int
frsrpc_dissect_element_FrsStartPromotionParent_partner_guid__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uuid_t(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_FrsStartPromotionParent_partner_guid, NULL);
return offset;
}
static int
frsrpc_dissect_element_FrsStartPromotionParent_parent_guid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, frsrpc_dissect_element_FrsStartPromotionParent_parent_guid_, NDR_POINTER_UNIQUE, "Pointer to Parent Guid (GUID)",hf_frsrpc_frsrpc_FrsStartPromotionParent_parent_guid);
return offset;
}
static int
frsrpc_dissect_element_FrsStartPromotionParent_parent_guid_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint3264 size;
int conformant = di->conformant_run;
tvbuff_t *subtvb;
if (!conformant) {
guint32 saved_flags = di->call_data->flags;
offset = dissect_ndr_uint3264(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_FrsStartPromotionParent_parent_guid_, &size);
di->call_data->flags &= ~DCERPC_IS_NDR64;
subtvb = tvb_new_subset(tvb, offset, (const gint)size, -1);
frsrpc_dissect_element_FrsStartPromotionParent_parent_guid__(subtvb, 0, pinfo, tree, di, drep);
offset += (int)size;
di->call_data->flags = saved_flags;
}
return offset;
}
static int
frsrpc_dissect_element_FrsStartPromotionParent_parent_guid__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uuid_t(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_frsrpc_FrsStartPromotionParent_parent_guid, NULL);
return offset;
}
static int
frsrpc_dissect_FrsStartPromotionParent_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="FrsStartPromotionParent";
offset = frsrpc_dissect_element_FrsStartPromotionParent_parent_guid(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
frsrpc_dissect_FrsStartPromotionParent_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="FrsStartPromotionParent";
offset = frsrpc_dissect_element_FrsStartPromotionParent_parent_account(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = frsrpc_dissect_element_FrsStartPromotionParent_parent_password(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = frsrpc_dissect_element_FrsStartPromotionParent_replica_set_name(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = frsrpc_dissect_element_FrsStartPromotionParent_replica_set_type(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = frsrpc_dissect_element_FrsStartPromotionParent_connection_name(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = frsrpc_dissect_element_FrsStartPromotionParent_partner_name(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = frsrpc_dissect_element_FrsStartPromotionParent_partner_princ_name(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = frsrpc_dissect_element_FrsStartPromotionParent_partner_auth_level(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = frsrpc_dissect_element_FrsStartPromotionParent___ndr_guid_size(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = frsrpc_dissect_element_FrsStartPromotionParent_connection_guid(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = frsrpc_dissect_element_FrsStartPromotionParent_partner_guid(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = frsrpc_dissect_element_FrsStartPromotionParent_parent_guid(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
frsrpc_dissect_FrsNOP_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="FrsNOP";
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_frsrpc_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
frsrpc_dissect_FrsNOP_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="FrsNOP";
return offset;
}
static int
frsrpc_dissect_FRSRPC_BACKUP_COMPLETE_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="FRSRPC_BACKUP_COMPLETE";
return offset;
}
static int
frsrpc_dissect_FRSRPC_BACKUP_COMPLETE_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="FRSRPC_BACKUP_COMPLETE";
return offset;
}
static int
frsrpc_dissect_FRSRPC_BACKUP_COMPLETE_5_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="FRSRPC_BACKUP_COMPLETE_5";
return offset;
}
static int
frsrpc_dissect_FRSRPC_BACKUP_COMPLETE_5_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="FRSRPC_BACKUP_COMPLETE_5";
return offset;
}
static int
frsrpc_dissect_FRSRPC_BACKUP_COMPLETE_6_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="FRSRPC_BACKUP_COMPLETE_6";
return offset;
}
static int
frsrpc_dissect_FRSRPC_BACKUP_COMPLETE_6_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="FRSRPC_BACKUP_COMPLETE_6";
return offset;
}
static int
frsrpc_dissect_FRSRPC_BACKUP_COMPLETE_7_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="FRSRPC_BACKUP_COMPLETE_7";
return offset;
}
static int
frsrpc_dissect_FRSRPC_BACKUP_COMPLETE_7_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="FRSRPC_BACKUP_COMPLETE_7";
return offset;
}
static int
frsrpc_dissect_FRSRPC_BACKUP_COMPLETE_8_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="FRSRPC_BACKUP_COMPLETE_8";
return offset;
}
static int
frsrpc_dissect_FRSRPC_BACKUP_COMPLETE_8_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="FRSRPC_BACKUP_COMPLETE_8";
return offset;
}
static int
frsrpc_dissect_FRSRPC_BACKUP_COMPLETE_9_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="FRSRPC_BACKUP_COMPLETE_9";
return offset;
}
static int
frsrpc_dissect_FRSRPC_BACKUP_COMPLETE_9_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="FRSRPC_BACKUP_COMPLETE_9";
return offset;
}
static int
frsrpc_dissect_FRSRPC_VERIFY_PROMOTION_PARENT_EX_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="FRSRPC_VERIFY_PROMOTION_PARENT_EX";
return offset;
}
static int
frsrpc_dissect_FRSRPC_VERIFY_PROMOTION_PARENT_EX_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="FRSRPC_VERIFY_PROMOTION_PARENT_EX";
return offset;
}
void proto_register_dcerpc_frsrpc(void)
{
static hf_register_info hf[] = {
{ &hf_CommPktChunk,
{ "Chunk", "frsrpc.chunk.ctr.chunk", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_CommPktChangeOrderCommand_file_name,
{ "File Name", "frsrpc.CommPktChangeOrderCommand.file_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_ack_version,
{ "Ack Version", "frsrpc.frsrpc_CommPktChangeOrderCommand.ack_version", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_change_order_guid,
{ "Change Order Guid", "frsrpc.frsrpc_CommPktChangeOrderCommand.change_order_guid", FT_GUID, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_connection_guid,
{ "Connection Guid", "frsrpc.frsrpc_CommPktChangeOrderCommand.connection_guid", FT_GUID, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_content_cmd,
{ "Content Cmd", "frsrpc.frsrpc_CommPktChangeOrderCommand.content_cmd", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_event_time,
{ "Event Time", "frsrpc.frsrpc_CommPktChangeOrderCommand.event_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_extension,
{ "Extension", "frsrpc.frsrpc_CommPktChangeOrderCommand.extension", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_file_attributes,
{ "File Attributes", "frsrpc.frsrpc_CommPktChangeOrderCommand.file_attributes", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_file_guid,
{ "File Guid", "frsrpc.frsrpc_CommPktChangeOrderCommand.file_guid", FT_GUID, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_file_name,
{ "File Name", "frsrpc.frsrpc_CommPktChangeOrderCommand.file_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_file_name_length,
{ "File Name Length", "frsrpc.frsrpc_CommPktChangeOrderCommand.file_name_length", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_file_offset,
{ "File Offset", "frsrpc.frsrpc_CommPktChangeOrderCommand.file_offset", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_file_size,
{ "File Size", "frsrpc.frsrpc_CommPktChangeOrderCommand.file_size", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_file_usn,
{ "File Usn", "frsrpc.frsrpc_CommPktChangeOrderCommand.file_usn", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_file_version_number,
{ "File Version Number", "frsrpc.frsrpc_CommPktChangeOrderCommand.file_version_number", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_flags,
{ "Flags", "frsrpc.frsrpc_CommPktChangeOrderCommand.flags", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_frs_vsn,
{ "Frs Vsn", "frsrpc.frsrpc_CommPktChangeOrderCommand.frs_vsn", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_iflags,
{ "Iflags", "frsrpc.frsrpc_CommPktChangeOrderCommand.iflags", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_jrnl_first_usn,
{ "Jrnl First Usn", "frsrpc.frsrpc_CommPktChangeOrderCommand.jrnl_first_usn", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_jrnl_usn,
{ "Jrnl Usn", "frsrpc.frsrpc_CommPktChangeOrderCommand.jrnl_usn", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_location_cmd,
{ "Location Cmd", "frsrpc.frsrpc_CommPktChangeOrderCommand.location_cmd", FT_UINT32, BASE_DEC, VALS(frsrpc_frsrpc_CommPktCoCmdLocationCmd_vals), 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_new_parent_guid,
{ "New Parent Guid", "frsrpc.frsrpc_CommPktChangeOrderCommand.new_parent_guid", FT_GUID, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_new_replica_num,
{ "New Replica Num", "frsrpc.frsrpc_CommPktChangeOrderCommand.new_replica_num", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_not_used,
{ "Not Used", "frsrpc.frsrpc_CommPktChangeOrderCommand.not_used", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_old_parent_guid,
{ "Old Parent Guid", "frsrpc.frsrpc_CommPktChangeOrderCommand.old_parent_guid", FT_GUID, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_original_replica_num,
{ "Original Replica Num", "frsrpc.frsrpc_CommPktChangeOrderCommand.original_replica_num", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_originator_guid,
{ "Originator Guid", "frsrpc.frsrpc_CommPktChangeOrderCommand.originator_guid", FT_GUID, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_padding1,
{ "Padding1", "frsrpc.frsrpc_CommPktChangeOrderCommand.padding1", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_padding2,
{ "Padding2", "frsrpc.frsrpc_CommPktChangeOrderCommand.padding2", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_padding3,
{ "Padding3", "frsrpc.frsrpc_CommPktChangeOrderCommand.padding3", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_padding4,
{ "Padding4", "frsrpc.frsrpc_CommPktChangeOrderCommand.padding4", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_partern_ack_sequence_number,
{ "Partern Ack Sequence Number", "frsrpc.frsrpc_CommPktChangeOrderCommand.partern_ack_sequence_number", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_sequence_number,
{ "Sequence Number", "frsrpc.frsrpc_CommPktChangeOrderCommand.sequence_number", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_spare1guid_p1,
{ "Spare1guid P1", "frsrpc.frsrpc_CommPktChangeOrderCommand.spare1guid_p1", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_spare1guid_p2,
{ "Spare1guid P2", "frsrpc.frsrpc_CommPktChangeOrderCommand.spare1guid_p2", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_spare1wcs,
{ "Spare1wcs", "frsrpc.frsrpc_CommPktChangeOrderCommand.spare1wcs", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_spare2bin,
{ "Spare2bin", "frsrpc.frsrpc_CommPktChangeOrderCommand.spare2bin", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_spare2guid_p1,
{ "Spare2guid P1", "frsrpc.frsrpc_CommPktChangeOrderCommand.spare2guid_p1", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_spare2ul1,
{ "Spare2ul1", "frsrpc.frsrpc_CommPktChangeOrderCommand.spare2ul1", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_spare2wcs,
{ "Spare2wcs", "frsrpc.frsrpc_CommPktChangeOrderCommand.spare2wcs", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_spare3guid_p2,
{ "Spare3guid P2", "frsrpc.frsrpc_CommPktChangeOrderCommand.spare3guid_p2", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderCommand_status,
{ "Status", "frsrpc.frsrpc_CommPktChangeOrderCommand.status", FT_UINT32, BASE_DEC, VALS(frsrpc_frsrpc_CommPktCoCmdStatus_vals), 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderRecordExtension_data_checksum,
{ "Data Checksum", "frsrpc.frsrpc_CommPktChangeOrderRecordExtension.data_checksum", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderRecordExtension_data_retry_timeout,
{ "Data Retry Timeout", "frsrpc.frsrpc_CommPktChangeOrderRecordExtension.data_retry_timeout", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderRecordExtension_field_size,
{ "Field Size", "frsrpc.frsrpc_CommPktChangeOrderRecordExtension.field_size", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderRecordExtension_major,
{ "Major", "frsrpc.frsrpc_CommPktChangeOrderRecordExtension.major", FT_UINT1632, BASE_DEC, VALS(frsrpc_frsrpc_CommPktCoRecordExtensionMajor_vals), 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderRecordExtension_not_used,
{ "Not Used", "frsrpc.frsrpc_CommPktChangeOrderRecordExtension.not_used", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderRecordExtension_offset0,
{ "Offset0", "frsrpc.frsrpc_CommPktChangeOrderRecordExtension.offset0", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderRecordExtension_offset1,
{ "Offset1", "frsrpc.frsrpc_CommPktChangeOrderRecordExtension.offset1", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderRecordExtension_offset_count,
{ "Offset Count", "frsrpc.frsrpc_CommPktChangeOrderRecordExtension.offset_count", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChangeOrderRecordExtension_offset_last,
{ "Offset Last", "frsrpc.frsrpc_CommPktChangeOrderRecordExtension.offset_last", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_blob,
{ "Blob", "frsrpc.frsrpc_CommPktChunkData.blob", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_block,
{ "Block", "frsrpc.frsrpc_CommPktChunkData.block", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_block_size,
{ "Block Size", "frsrpc.frsrpc_CommPktChunkData.block_size", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_bop,
{ "Bop", "frsrpc.frsrpc_CommPktChunkData.bop", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_bopend,
{ "Bopend", "frsrpc.frsrpc_CommPktChunkData.bopend", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_co_ext_win2k,
{ "Co Ext Win2k", "frsrpc.frsrpc_CommPktChunkData.co_ext_win2k", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_co_ext_win2k_,
{ "Subcontext length", "frsrpc.frsrpc_CommPktChunkData.subcontext", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_co_extension2,
{ "Co Extension2", "frsrpc.frsrpc_CommPktChunkData.co_extension2", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_co_guid,
{ "Co Guid", "frsrpc.frsrpc_CommPktChunkData.co_guid", FT_GUID, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_co_guid_,
{ "Subcontext length", "frsrpc.frsrpc_CommPktChunkData.subcontext", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_co_sequnence_number,
{ "Co Sequnence Number", "frsrpc.frsrpc_CommPktChunkData.co_sequnence_number", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_command,
{ "Command", "frsrpc.frsrpc_CommPktChunkData.command", FT_UINT32, BASE_DEC, VALS(frsrpc_frsrpc_CommPktCommand_vals), 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_compression_guid,
{ "Compression Guid", "frsrpc.frsrpc_CommPktChunkData.compression_guid", FT_GUID, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_connection,
{ "Connection", "frsrpc.frsrpc_CommPktChunkData.connection", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_file_offset,
{ "File Offset", "frsrpc.frsrpc_CommPktChunkData.file_offset", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_file_size,
{ "File Size", "frsrpc.frsrpc_CommPktChunkData.file_size", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_from,
{ "From", "frsrpc.frsrpc_CommPktChunkData.from", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_gvsn,
{ "Gvsn", "frsrpc.frsrpc_CommPktChunkData.gvsn", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_gvsn_,
{ "Subcontext length", "frsrpc.frsrpc_CommPktChunkData.subcontext", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_join_guid,
{ "Join Guid", "frsrpc.frsrpc_CommPktChunkData.join_guid", FT_GUID, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_join_guid_,
{ "Subcontext length", "frsrpc.frsrpc_CommPktChunkData.subcontext", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_join_time,
{ "Join Time", "frsrpc.frsrpc_CommPktChunkData.join_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_join_time_,
{ "Subcontext length", "frsrpc.frsrpc_CommPktChunkData.subcontext", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_last_join_time,
{ "Last Join Time", "frsrpc.frsrpc_CommPktChunkData.last_join_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_remote_co,
{ "Remote Co", "frsrpc.frsrpc_CommPktChunkData.remote_co", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_remote_co_,
{ "Subcontext length", "frsrpc.frsrpc_CommPktChunkData.subcontext", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_replica,
{ "Replica", "frsrpc.frsrpc_CommPktChunkData.replica", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_replica_version_guid,
{ "Replica Version Guid", "frsrpc.frsrpc_CommPktChunkData.replica_version_guid", FT_GUID, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_replica_version_guid_,
{ "Subcontext length", "frsrpc.frsrpc_CommPktChunkData.subcontext", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_to,
{ "To", "frsrpc.frsrpc_CommPktChunkData.to", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_vvector,
{ "Vvector", "frsrpc.frsrpc_CommPktChunkData.vvector", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkData_vvector_,
{ "Subcontext length", "frsrpc.frsrpc_CommPktChunkData.subcontext", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkGuidName_guid,
{ "Guid", "frsrpc.frsrpc_CommPktChunkGuidName.guid", FT_GUID, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkGuidName_guid_,
{ "Subcontext length", "frsrpc.frsrpc_CommPktChunkGuidName.subcontext", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkGuidName_name,
{ "Name", "frsrpc.frsrpc_CommPktChunkGuidName.name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunkGuidName_name_,
{ "Subcontext length", "frsrpc.frsrpc_CommPktChunkGuidName.subcontext", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunk_data,
{ "Data", "frsrpc.frsrpc_CommPktChunk.data", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunk_data_,
{ "Subcontext length", "frsrpc.frsrpc_CommPktChunk.subcontext", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktChunk_type,
{ "Type", "frsrpc.frsrpc_CommPktChunk.type", FT_UINT1632, BASE_DEC, VALS(frsrpc_frsrpc_CommPktChunkType_vals), 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_BASIC_INFO_CHANGE,
{ "Frsrpc Content Reason Basic Info Change", "frsrpc.frsrpc_CommPktCoCmdContentCmd.FRSRPC_CONTENT_REASON_BASIC_INFO_CHANGE", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_BASIC_INFO_CHANGE_tfs), ( 0x00004000 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_COMPRESSION_CHANGE,
{ "Frsrpc Content Reason Compression Change", "frsrpc.frsrpc_CommPktCoCmdContentCmd.FRSRPC_CONTENT_REASON_COMPRESSION_CHANGE", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_COMPRESSION_CHANGE_tfs), ( 0x00020000 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_DATA_EXTEND,
{ "Frsrpc Content Reason Data Extend", "frsrpc.frsrpc_CommPktCoCmdContentCmd.FRSRPC_CONTENT_REASON_DATA_EXTEND", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_DATA_EXTEND_tfs), ( 0x00000002 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_DATA_OVERWRITE,
{ "Frsrpc Content Reason Data Overwrite", "frsrpc.frsrpc_CommPktCoCmdContentCmd.FRSRPC_CONTENT_REASON_DATA_OVERWRITE", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_DATA_OVERWRITE_tfs), ( 0x00000001 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_DATA_TRUNCATION,
{ "Frsrpc Content Reason Data Truncation", "frsrpc.frsrpc_CommPktCoCmdContentCmd.FRSRPC_CONTENT_REASON_DATA_TRUNCATION", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_DATA_TRUNCATION_tfs), ( 0x00000004 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_EA_CHANGE,
{ "Frsrpc Content Reason Ea Change", "frsrpc.frsrpc_CommPktCoCmdContentCmd.FRSRPC_CONTENT_REASON_EA_CHANGE", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_EA_CHANGE_tfs), ( 0x00000400 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_FILE_CREATE,
{ "Frsrpc Content Reason File Create", "frsrpc.frsrpc_CommPktCoCmdContentCmd.FRSRPC_CONTENT_REASON_FILE_CREATE", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_FILE_CREATE_tfs), ( 0x00000100 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_FILE_DELETE,
{ "Frsrpc Content Reason File Delete", "frsrpc.frsrpc_CommPktCoCmdContentCmd.FRSRPC_CONTENT_REASON_FILE_DELETE", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_FILE_DELETE_tfs), ( 0x00000200 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_NAMED_DATA_EXTEND,
{ "Frsrpc Content Reason Named Data Extend", "frsrpc.frsrpc_CommPktCoCmdContentCmd.FRSRPC_CONTENT_REASON_NAMED_DATA_EXTEND", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_NAMED_DATA_EXTEND_tfs), ( 0x00000020 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_NAMED_DATA_OVERWRITE,
{ "Frsrpc Content Reason Named Data Overwrite", "frsrpc.frsrpc_CommPktCoCmdContentCmd.FRSRPC_CONTENT_REASON_NAMED_DATA_OVERWRITE", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_NAMED_DATA_OVERWRITE_tfs), ( 0x00000010 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_NAMED_DATA_TRUNCATION,
{ "Frsrpc Content Reason Named Data Truncation", "frsrpc.frsrpc_CommPktCoCmdContentCmd.FRSRPC_CONTENT_REASON_NAMED_DATA_TRUNCATION", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_NAMED_DATA_TRUNCATION_tfs), ( 0x00000040 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_NEW_NAME,
{ "Frsrpc Content Reason New Name", "frsrpc.frsrpc_CommPktCoCmdContentCmd.FRSRPC_CONTENT_REASON_NEW_NAME", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_NEW_NAME_tfs), ( 0x00002000 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_OLD_NAME,
{ "Frsrpc Content Reason Old Name", "frsrpc.frsrpc_CommPktCoCmdContentCmd.FRSRPC_CONTENT_REASON_OLD_NAME", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_OLD_NAME_tfs), ( 0x00001000 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_SECURITY_CHANGE,
{ "Frsrpc Content Reason Security Change", "frsrpc.frsrpc_CommPktCoCmdContentCmd.FRSRPC_CONTENT_REASON_SECURITY_CHANGE", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdContentCmd_FRSRPC_CONTENT_REASON_SECURITY_CHANGE_tfs), ( 0x00000800 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_ABORT_CO,
{ "Frsrpc Co Flag Abort Co", "frsrpc.frsrpc_CommPktCoCmdFlags.FRSRPC_CO_FLAG_ABORT_CO", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_ABORT_CO_tfs), ( 0x00000001 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_COMPRESSED_STAGE,
{ "Frsrpc Co Flag Compressed Stage", "frsrpc.frsrpc_CommPktCoCmdFlags.FRSRPC_CO_FLAG_COMPRESSED_STAGE", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_COMPRESSED_STAGE_tfs), ( 0x01000000 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_CONTENT_CMD,
{ "Frsrpc Co Flag Content Cmd", "frsrpc.frsrpc_CommPktCoCmdFlags.FRSRPC_CO_FLAG_CONTENT_CMD", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_CONTENT_CMD_tfs), ( 0x00000004 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_CONTROL,
{ "Frsrpc Co Flag Control", "frsrpc.frsrpc_CommPktCoCmdFlags.FRSRPC_CO_FLAG_CONTROL", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_CONTROL_tfs), ( 0x00001000 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_DIRECTED_CO,
{ "Frsrpc Co Flag Directed Co", "frsrpc.frsrpc_CommPktCoCmdFlags.FRSRPC_CO_FLAG_DIRECTED_CO", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_DIRECTED_CO_tfs), ( 0x00002000 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_JUST_OID_RESET,
{ "Frsrpc Co Flag Just Oid Reset", "frsrpc.frsrpc_CommPktCoCmdFlags.FRSRPC_CO_FLAG_JUST_OID_RESET", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_JUST_OID_RESET_tfs), ( 0x00800000 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_LOCALCO,
{ "Frsrpc Co Flag Localco", "frsrpc.frsrpc_CommPktCoCmdFlags.FRSRPC_CO_FLAG_LOCALCO", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_LOCALCO_tfs), ( 0x00000020 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_LOCATION_CMD,
{ "Frsrpc Co Flag Location Cmd", "frsrpc.frsrpc_CommPktCoCmdFlags.FRSRPC_CO_FLAG_LOCATION_CMD", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_LOCATION_CMD_tfs), ( 0x00000008 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_MORPH_GEN_HEAD,
{ "Frsrpc Co Flag Morph Gen Head", "frsrpc.frsrpc_CommPktCoCmdFlags.FRSRPC_CO_FLAG_MORPH_GEN_HEAD", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_MORPH_GEN_HEAD_tfs), ( 0x00400000 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_MOVEIN_GEN,
{ "Frsrpc Co Flag Movein Gen", "frsrpc.frsrpc_CommPktCoCmdFlags.FRSRPC_CO_FLAG_MOVEIN_GEN", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_MOVEIN_GEN_tfs), ( 0x00200000 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_NEW_FILE,
{ "Frsrpc Co Flag New File", "frsrpc.frsrpc_CommPktCoCmdFlags.FRSRPC_CO_FLAG_NEW_FILE", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_NEW_FILE_tfs), ( 0x00000400 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_ONLIST,
{ "Frsrpc Co Flag Onlist", "frsrpc.frsrpc_CommPktCoCmdFlags.FRSRPC_CO_FLAG_ONLIST", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_ONLIST_tfs), ( 0x00000010 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_OUT_OF_ORDER,
{ "Frsrpc Co Flag Out Of Order", "frsrpc.frsrpc_CommPktCoCmdFlags.FRSRPC_CO_FLAG_OUT_OF_ORDER", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_OUT_OF_ORDER_tfs), ( 0x00000200 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_RETRY,
{ "Frsrpc Co Flag Retry", "frsrpc.frsrpc_CommPktCoCmdFlags.FRSRPC_CO_FLAG_RETRY", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_RETRY_tfs), ( 0x00000040 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_SKIP_ORIG_REC_C,
{ "Frsrpc Co Flag Skip Orig Rec C", "frsrpc.frsrpc_CommPktCoCmdFlags.FRSRPC_CO_FLAG_SKIP_ORIG_REC_C", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_SKIP_ORIG_REC_C_tfs), ( 0x00100000 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_SKIP_VV_UPDATE,
{ "Frsrpc Co Flag Skip Vv Update", "frsrpc.frsrpc_CommPktCoCmdFlags.FRSRPC_CO_FLAG_SKIP_VV_UPDATE", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_SKIP_VV_UPDATE_tfs), ( 0x02000000 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_VVJOIN_TO_ORIG,
{ "Frsrpc Co Flag Vvjoin To Orig", "frsrpc.frsrpc_CommPktCoCmdFlags.FRSRPC_CO_FLAG_VVJOIN_TO_ORIG", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_VVJOIN_TO_ORIG_tfs), ( 0x00040000 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_VV_ACTIVATED,
{ "Frsrpc Co Flag Vv Activated", "frsrpc.frsrpc_CommPktCoCmdFlags.FRSRPC_CO_FLAG_VV_ACTIVATED", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdFlags_FRSRPC_CO_FLAG_VV_ACTIVATED_tfs), ( 0x00000002 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdIFlags_FRSRPC_CO_IFLAG_CO_ABORT,
{ "Frsrpc Co Iflag Co Abort", "frsrpc.frsrpc_CommPktCoCmdIFlags.FRSRPC_CO_IFLAG_CO_ABORT", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdIFlags_FRSRPC_CO_IFLAG_CO_ABORT_tfs), ( 0x00000002 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdIFlags_FRSRPC_CO_IFLAG_DIR_ENUM_PENDING,
{ "Frsrpc Co Iflag Dir Enum Pending", "frsrpc.frsrpc_CommPktCoCmdIFlags.FRSRPC_CO_IFLAG_DIR_ENUM_PENDING", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdIFlags_FRSRPC_CO_IFLAG_DIR_ENUM_PENDING_tfs), ( 0x00000004 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoCmdIFlags_FRSRPC_CO_IFLAG_VVRETIRE_EXEC,
{ "Frsrpc Co Iflag Vvretire Exec", "frsrpc.frsrpc_CommPktCoCmdIFlags.FRSRPC_CO_IFLAG_VVRETIRE_EXEC", FT_BOOLEAN, 32, TFS(&frsrpc_CommPktCoCmdIFlags_FRSRPC_CO_IFLAG_VVRETIRE_EXEC_tfs), ( 0x00000001 ), NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoRecordExtensionWin2k_data_checksum,
{ "Data Checksum", "frsrpc.frsrpc_CommPktCoRecordExtensionWin2k.data_checksum", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoRecordExtensionWin2k_field_size,
{ "Field Size", "frsrpc.frsrpc_CommPktCoRecordExtensionWin2k.field_size", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoRecordExtensionWin2k_major,
{ "Major", "frsrpc.frsrpc_CommPktCoRecordExtensionWin2k.major", FT_UINT1632, BASE_DEC, VALS(frsrpc_frsrpc_CommPktCoRecordExtensionMajor_vals), 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoRecordExtensionWin2k_offset,
{ "Offset", "frsrpc.frsrpc_CommPktCoRecordExtensionWin2k.offset", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoRecordExtensionWin2k_offset_count,
{ "Offset Count", "frsrpc.frsrpc_CommPktCoRecordExtensionWin2k.offset_count", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktCoRecordExtensionWin2k_offset_last,
{ "Offset Last", "frsrpc.frsrpc_CommPktCoRecordExtensionWin2k.offset_last", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktDataExtensionChecksum_data,
{ "Data", "frsrpc.frsrpc_CommPktDataExtensionChecksum.data", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktDataExtensionChecksum_prefix_size,
{ "Prefix Size", "frsrpc.frsrpc_CommPktDataExtensionChecksum.prefix_size", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktDataExtensionChecksum_prefix_type,
{ "Prefix Type", "frsrpc.frsrpc_CommPktDataExtensionChecksum.prefix_type", FT_UINT32, BASE_DEC, VALS(frsrpc_frsrpc_CommPktDataExtensionType_vals), 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktDataExtensionRetryTimeout_count,
{ "Count", "frsrpc.frsrpc_CommPktDataExtensionRetryTimeout.count", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktDataExtensionRetryTimeout_first_try_time,
{ "First Try Time", "frsrpc.frsrpc_CommPktDataExtensionRetryTimeout.first_try_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktDataExtensionRetryTimeout_not_used,
{ "Not Used", "frsrpc.frsrpc_CommPktDataExtensionRetryTimeout.not_used", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktDataExtensionRetryTimeout_prefix_size,
{ "Prefix Size", "frsrpc.frsrpc_CommPktDataExtensionRetryTimeout.prefix_size", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktDataExtensionRetryTimeout_prefix_type,
{ "Prefix Type", "frsrpc.frsrpc_CommPktDataExtensionRetryTimeout.prefix_type", FT_UINT32, BASE_DEC, VALS(frsrpc_frsrpc_CommPktDataExtensionType_vals), 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktGSVN_guid,
{ "Guid", "frsrpc.frsrpc_CommPktGSVN.guid", FT_GUID, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_CommPktGSVN_vsn,
{ "Vsn", "frsrpc.frsrpc_CommPktGSVN.vsn", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsSendCommPktReq_cs_id,
{ "Cs Id", "frsrpc.frsrpc_FrsSendCommPktReq.cs_id", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsSendCommPktReq_ctr,
{ "Ctr", "frsrpc.frsrpc_FrsSendCommPktReq.ctr", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsSendCommPktReq_ctr_,
{ "Subcontext length", "frsrpc.frsrpc_FrsSendCommPktReq.subcontext", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsSendCommPktReq_data_handle,
{ "Data Handle", "frsrpc.frsrpc_FrsSendCommPktReq.data_handle", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsSendCommPktReq_data_name,
{ "Data Name", "frsrpc.frsrpc_FrsSendCommPktReq.data_name", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsSendCommPktReq_major,
{ "Major", "frsrpc.frsrpc_FrsSendCommPktReq.major", FT_UINT32, BASE_DEC, VALS(frsrpc_frsrpc_CommPktMajor_vals), 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsSendCommPktReq_memory_len,
{ "Memory Len", "frsrpc.frsrpc_FrsSendCommPktReq.memory_len", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsSendCommPktReq_minor,
{ "Minor", "frsrpc.frsrpc_FrsSendCommPktReq.minor", FT_UINT32, BASE_DEC, VALS(frsrpc_frsrpc_CommPktMinor_vals), 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsSendCommPktReq_pkt_len,
{ "Pkt Len", "frsrpc.frsrpc_FrsSendCommPktReq.pkt_len", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsSendCommPktReq_upk_len,
{ "Upk Len", "frsrpc.frsrpc_FrsSendCommPktReq.upk_len", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsSendCommPkt_req,
{ "Req", "frsrpc.frsrpc_FrsSendCommPkt.req", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsStartPromotionParent___ndr_guid_size,
{ "Ndr Guid Size", "frsrpc.frsrpc_FrsStartPromotionParent.__ndr_guid_size", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsStartPromotionParent_connection_guid,
{ "Connection Guid", "frsrpc.frsrpc_FrsStartPromotionParent.connection_guid", FT_GUID, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsStartPromotionParent_connection_guid_,
{ "Subcontext length", "frsrpc.frsrpc_FrsStartPromotionParent.subcontext", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsStartPromotionParent_connection_name,
{ "Connection Name", "frsrpc.frsrpc_FrsStartPromotionParent.connection_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsStartPromotionParent_parent_account,
{ "Parent Account", "frsrpc.frsrpc_FrsStartPromotionParent.parent_account", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsStartPromotionParent_parent_guid,
{ "Parent Guid", "frsrpc.frsrpc_FrsStartPromotionParent.parent_guid", FT_GUID, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsStartPromotionParent_parent_guid_,
{ "Subcontext length", "frsrpc.frsrpc_FrsStartPromotionParent.subcontext", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsStartPromotionParent_parent_password,
{ "Parent Password", "frsrpc.frsrpc_FrsStartPromotionParent.parent_password", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsStartPromotionParent_partner_auth_level,
{ "Partner Auth Level", "frsrpc.frsrpc_FrsStartPromotionParent.partner_auth_level", FT_UINT32, BASE_DEC, VALS(frsrpc_frsrpc_PartnerAuthLevel_vals), 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsStartPromotionParent_partner_guid,
{ "Partner Guid", "frsrpc.frsrpc_FrsStartPromotionParent.partner_guid", FT_GUID, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsStartPromotionParent_partner_guid_,
{ "Subcontext length", "frsrpc.frsrpc_FrsStartPromotionParent.subcontext", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsStartPromotionParent_partner_name,
{ "Partner Name", "frsrpc.frsrpc_FrsStartPromotionParent.partner_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsStartPromotionParent_partner_princ_name,
{ "Partner Princ Name", "frsrpc.frsrpc_FrsStartPromotionParent.partner_princ_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsStartPromotionParent_replica_set_name,
{ "Replica Set Name", "frsrpc.frsrpc_FrsStartPromotionParent.replica_set_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsStartPromotionParent_replica_set_type,
{ "Replica Set Type", "frsrpc.frsrpc_FrsStartPromotionParent.replica_set_type", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsVerifyPromotionParent___ndr_guid_size,
{ "Ndr Guid Size", "frsrpc.frsrpc_FrsVerifyPromotionParent.__ndr_guid_size", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsVerifyPromotionParent_parent_account,
{ "Parent Account", "frsrpc.frsrpc_FrsVerifyPromotionParent.parent_account", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsVerifyPromotionParent_parent_password,
{ "Parent Password", "frsrpc.frsrpc_FrsVerifyPromotionParent.parent_password", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsVerifyPromotionParent_partner_auth_level,
{ "Partner Auth Level", "frsrpc.frsrpc_FrsVerifyPromotionParent.partner_auth_level", FT_UINT32, BASE_DEC, VALS(frsrpc_frsrpc_PartnerAuthLevel_vals), 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsVerifyPromotionParent_replica_set_name,
{ "Replica Set Name", "frsrpc.frsrpc_FrsVerifyPromotionParent.replica_set_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_frsrpc_FrsVerifyPromotionParent_replica_set_type,
{ "Replica Set Type", "frsrpc.frsrpc_FrsVerifyPromotionParent.replica_set_type", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_opnum,
{ "Operation", "frsrpc.opnum", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_frsrpc_werror,
{ "Windows Error", "frsrpc.werror", FT_UINT32, BASE_HEX, VALS(WERR_errors), 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_ChunkCtr,
&ett_dcerpc_frsrpc,
&ett_frsrpc_frsrpc_CommPktChunkGuidName,
&ett_frsrpc_frsrpc_CommPktGSVN,
&ett_frsrpc_frsrpc_CommPktCoCmdFlags,
&ett_frsrpc_frsrpc_CommPktCoCmdIFlags,
&ett_frsrpc_frsrpc_CommPktCoCmdContentCmd,
&ett_frsrpc_frsrpc_CommPktChangeOrderCommand,
&ett_frsrpc_frsrpc_CommPktDataExtensionChecksum,
&ett_frsrpc_frsrpc_CommPktDataExtensionRetryTimeout,
&ett_frsrpc_frsrpc_CommPktCoRecordExtensionWin2k,
&ett_frsrpc_frsrpc_CommPktChangeOrderRecordExtension,
&ett_frsrpc_frsrpc_CommPktChunkData,
&ett_frsrpc_frsrpc_CommPktChunk,
&ett_frsrpc_frsrpc_FrsSendCommPktReq,
};
proto_dcerpc_frsrpc = proto_register_protocol("File Replication Service", "FRSRPC", "frsrpc");
proto_register_field_array(proto_dcerpc_frsrpc, hf, array_length (hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_dcerpc_frsrpc(void)
{
dcerpc_init_uuid(proto_dcerpc_frsrpc, ett_dcerpc_frsrpc,
&uuid_dcerpc_frsrpc, ver_dcerpc_frsrpc,
frsrpc_dissectors, hf_frsrpc_opnum);
}
