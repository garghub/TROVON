static int
dissect_pn_io_ps_SB(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, guint8 *drep _U_, int hfindex, const int **fields)
{
if (tree) {
guint8 u8StatusByte;
proto_item *sb_item;
u8StatusByte = tvb_get_guint8(tvb, offset);
sb_item = proto_tree_add_bitmask_with_flags(tree, tvb, offset, hfindex, ett_pn_io_ioxs, fields,
ENC_LITTLE_ENDIAN, BMT_NO_APPEND);
proto_item_append_text(sb_item, " (%s)", ((u8StatusByte == 0x20) || (u8StatusByte == 0x00)) ? "normal" : "unnormal");
}
return offset + 1;
}
static int
dissect_pn_io_ps_CB(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, guint8 *drep _U_, int hfindex, const int **fields)
{
if (tree) {
guint8 u8ControlByte;
proto_item *cb_item;
u8ControlByte = tvb_get_guint8(tvb, offset);
cb_item = proto_tree_add_bitmask_with_flags(tree, tvb, offset, hfindex, ett_pn_io_ioxs, fields,
ENC_LITTLE_ENDIAN, BMT_NO_APPEND);
proto_item_append_text(cb_item, " (%s)", ((u8ControlByte == 0x20) || (u8ControlByte == 0x00) ||
(u8ControlByte == 0xa0) || (u8ControlByte == 0x80)) ? "normal" : "unnormal");
}
return offset + 1;
}
static int
dissect_PNIO_IOCS(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree,
guint8 *drep _U_, int hfindex, guint16 slotNr, guint16 subSlotNr, const int **fields)
{
if (tree) {
guint8 u8IOxS;
proto_item *ioxs_item;
u8IOxS = tvb_get_guint8(tvb, offset);
ioxs_item = proto_tree_add_bitmask_with_flags(tree, tvb, offset, hfindex,
ett_pn_io_ioxs, fields, ENC_LITTLE_ENDIAN, BMT_NO_APPEND);
proto_item_append_text(ioxs_item,
" (%s%s), Slot: 0x%x, Subslot: 0x%x",
(u8IOxS & 0x01) ? "another IOxS follows " : "",
(u8IOxS & 0x80) ? "good" : "bad",
slotNr,
subSlotNr);
}
return offset + 1;
}
static int
dissect_PNIO_IOxS(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, guint8 *drep _U_, int hfindex, const int **fields)
{
if (tree) {
guint8 u8IOxS;
proto_item *ioxs_item;
u8IOxS = tvb_get_guint8(tvb, offset);
ioxs_item = proto_tree_add_bitmask_with_flags(tree, tvb, offset, hfindex,
ett_pn_io_ioxs, fields, ENC_LITTLE_ENDIAN, BMT_NO_APPEND);
proto_item_append_text(ioxs_item,
" (%s%s)",
(u8IOxS & 0x01) ? "another IOxS follows " : "",
(u8IOxS & 0x80) ? "good" : "bad");
}
return offset + 1;
}
static int
dissect_pn_io_ps_uint(tvbuff_t *tvb, gint offset, packet_info *pinfo _U_,
proto_tree *tree, guint8 *drep,
int hfindex, guint8 bytelength, guint64 *pdata)
{
guint64 data;
gboolean generalDissection;
generalDissection = FALSE;
switch (bytelength) {
case 1:
data = tvb_get_guint8(tvb, offset);
if (pdata)
*pdata = data;
break;
case 2:
data = tvb_get_letohs(tvb, offset);
if (pdata)
*pdata = data;
break;
case 3:
data = tvb_get_letoh24(tvb, offset);
if (pdata)
*pdata = data;
break;
case 4:
data = tvb_get_letohl(tvb, offset);
if (pdata)
*pdata = data;
break;
case 5:
data = tvb_get_letoh40(tvb, offset);
if (pdata)
*pdata = data;
break;
case 6:
data = tvb_get_letoh48(tvb, offset);
if (pdata)
*pdata = data;
break;
case 7:
data = tvb_get_letoh56(tvb, offset);
if (pdata)
*pdata = data;
break;
case 8:
data = tvb_get_letoh64(tvb, offset);
if (pdata)
*pdata = data;
break;
default:
dissect_pn_user_data(tvb, offset, pinfo, tree, bytelength, "Safety IO Data");
generalDissection = TRUE;
break;
}
if (tree && generalDissection == FALSE) {
proto_tree_add_item(tree, hfindex, tvb, offset, bytelength, DREP_ENC_INTEGER(drep));
}
return offset + bytelength;
}
int
dissect_PNIO_C_SDU_RTC1(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep _U_)
{
proto_tree *data_tree = NULL;
guint16 frameOffset;
guint32 objectCounter;
gboolean inputFlag;
gboolean outputFlag;
gboolean psInfoText;
proto_item *data_item;
proto_item *IODataObject_item;
proto_item *IODataObject_item_info;
proto_tree *IODataObject_tree;
proto_item *ModuleID_item;
proto_item *ModuleDiff_item;
wmem_strbuf_t *moduleName;
guint8 toggleBitSb;
guint8 toggleBitCb;
guint64 f_data;
guint8 statusbyte;
guint8 controlbyte;
guint16 number_io_data_objects_input_cr;
guint16 number_iocs_input_cr;
guint16 number_io_data_objects_output_cr;
guint16 number_iocs_output_cr;
conversation_t *conversation;
stationInfo *station_info = NULL;
iocsObject *iocs_object;
ioDataObject *io_data_object;
moduleDiffInfo *module_diff_info;
wmem_list_frame_t *frame;
wmem_list_frame_t *frame_diff;
frameOffset = 0;
f_data = 0;
inputFlag = FALSE;
outputFlag = FALSE;
psInfoText = FALSE;
number_io_data_objects_input_cr = 0;
number_iocs_input_cr = 0;
number_io_data_objects_output_cr = 0;
number_iocs_output_cr = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PNIO");
data_item = proto_tree_add_protocol_format(tree, proto_pn_io_rtc1, tvb, offset, tvb_captured_length(tvb),
"PROFINET IO Cyclic Service Data Unit: %u bytes", tvb_captured_length(tvb));
data_tree = proto_item_add_subtree(data_item, ett_pn_io_rtc);
if (!(dissect_CSF_SDU_heur(tvb, pinfo, data_tree, NULL) == FALSE))
return(tvb_captured_length(tvb));
conversation = find_conversation(pinfo->num, &pinfo->dl_src, &pinfo->dl_dst, PT_NONE, 0, 0, 0);
if (conversation != NULL) {
station_info = (stationInfo*)conversation_get_proto_data(conversation, proto_pn_dcp);
if (station_info != NULL) {
if (pnio_ps_selection == TRUE) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PNIO_PS");
}
if (addresses_equal(&(pinfo->src), &(conversation->key_ptr->addr1)) && addresses_equal(&(pinfo->dst), &(conversation->key_ptr->addr2))) {
inputFlag = TRUE;
outputFlag = FALSE;
number_io_data_objects_input_cr = station_info->ioDataObjectNr;
number_iocs_input_cr = station_info->iocsNr;
}
if (addresses_equal(&(pinfo->dst), &(conversation->key_ptr->addr1)) && addresses_equal(&(pinfo->src), &(conversation->key_ptr->addr2))) {
outputFlag = TRUE;
inputFlag = FALSE;
number_io_data_objects_output_cr = station_info->ioDataObjectNr;
number_iocs_output_cr = station_info->iocsNr;
}
}
}
if (inputFlag) {
if (pnio_ps_selection == TRUE) {
proto_tree_add_string_format_value(data_tree, hf_pn_io_frame_info_type, tvb,
offset, 0, "Response", "Response Frame (IO_Device -> IO_Controller)");
}
else {
proto_tree_add_string_format_value(data_tree, hf_pn_io_frame_info_type, tvb,
offset, 0, "Input", "Input Frame (IO_Device -> IO_Controller)");
}
if (station_info != NULL) {
if (station_info->typeofstation != NULL) {
proto_tree_add_string_format_value(data_tree, hf_pn_io_frame_info_vendor, tvb, 0,
0, station_info->typeofstation, "\"%s\"", station_info->typeofstation);
}
if (station_info->nameofstation != NULL) {
proto_tree_add_string_format_value(data_tree, hf_pn_io_frame_info_nameofstation, tvb, 0,
0, station_info->nameofstation, "\"%s\"", station_info->nameofstation);
}
if (station_info->gsdPathLength == TRUE) {
if (station_info->gsdFound == TRUE) {
if (station_info->gsdLocation != NULL) {
IODataObject_item_info = proto_tree_add_item(data_tree, hf_pn_io_frame_info_gsd_found, tvb, offset, 0, ENC_NA);
proto_item_append_text(IODataObject_item_info, ": \"%s\"", station_info->gsdLocation);
}
}
else {
if (station_info->gsdLocation != NULL) {
IODataObject_item_info = proto_tree_add_item(data_tree, hf_pn_io_frame_info_gsd_error, tvb, offset, 0, ENC_NA);
proto_item_append_text(IODataObject_item_info, " Please place relevant GSD-file under \"%s\"", station_info->gsdLocation);
}
}
}
else {
IODataObject_item_info = proto_tree_add_item(data_tree, hf_pn_io_frame_info_gsd_path, tvb, offset, 0, ENC_NA);
proto_item_append_text(IODataObject_item_info, " Please check your GSD-file networkpath. (No Path configured)");
}
}
objectCounter = number_io_data_objects_input_cr + number_iocs_input_cr;
if (objectCounter > (guint)tvb_reported_length_remaining(tvb, offset)) {
expert_add_info_format(pinfo, data_item, &ei_pn_io_too_many_data_objects, "Too many data objects: %d", objectCounter);
return(tvb_captured_length(tvb));
}
while (objectCounter--) {
if (station_info != NULL) {
for (frame = wmem_list_head(station_info->ioobject_data_in); frame != NULL; frame = wmem_list_frame_next(frame)) {
io_data_object = (ioDataObject*)wmem_list_frame_data(frame);
if (io_data_object->frameOffset == frameOffset) {
IODataObject_item = proto_tree_add_item(data_tree, hf_pn_io_io_data_object, tvb, offset, 0, ENC_NA);
IODataObject_tree = proto_item_add_subtree(IODataObject_item, ett_pn_io_io_data_object);
for (frame_diff = wmem_list_head(station_info->diff_module); frame_diff != NULL; frame_diff = wmem_list_frame_next(frame_diff)) {
module_diff_info = (moduleDiffInfo*)wmem_list_frame_data(frame_diff);
if (io_data_object->moduleIdentNr != module_diff_info->modulID) {
ModuleDiff_item = proto_tree_add_item(IODataObject_tree, hf_pn_io_io_data_object_info_module_diff, tvb, 0, 0, ENC_NA);
proto_item_append_text(ModuleDiff_item, ": Device using ModuleIdentNumber 0x%08x instead of 0x%08x", module_diff_info->modulID, io_data_object->moduleIdentNr);
break;
}
}
proto_tree_add_uint(IODataObject_tree, hf_pn_io_io_data_object_info_moduleidentnumber, tvb, 0, 0, io_data_object->moduleIdentNr);
proto_tree_add_uint(IODataObject_tree, hf_pn_io_io_data_object_info_submoduleidentnumber, tvb, 0, 0, io_data_object->subModuleIdentNr);
if (io_data_object->profisafeSupported == TRUE && pnio_ps_selection == TRUE) {
if (io_data_object->profisafeSupported == TRUE && psInfoText == FALSE) {
col_append_str(pinfo->cinfo, COL_INFO, ", PROFIsafe Device");
psInfoText = TRUE;
}
proto_tree_add_uint(IODataObject_tree, hf_pn_io_ps_f_dest_adr, tvb, 0, 0, io_data_object->f_dest_adr);
if ((io_data_object->length - F_MESSAGE_TRAILER_4BYTE) > 0) {
offset = dissect_pn_io_ps_uint(tvb, offset, pinfo, IODataObject_tree, drep, hf_pn_io_ps_f_data,
(io_data_object->length - F_MESSAGE_TRAILER_4BYTE), &f_data);
}
statusbyte = tvb_get_guint8(tvb, offset);
toggleBitSb = statusbyte & 0x20;
if (io_data_object->lastToggleBit != toggleBitSb) {
ModuleID_item = proto_tree_add_uint(IODataObject_tree, hf_pn_io_ps_sb_toggelBitChanged, tvb, offset, 0, toggleBitSb);
PROTO_ITEM_SET_HIDDEN(ModuleID_item);
ModuleID_item = proto_tree_add_uint(IODataObject_tree, hf_pn_io_ps_sb_toggelBitChange_slot_nr, tvb, offset, 0, io_data_object->slotNr);
PROTO_ITEM_SET_HIDDEN(ModuleID_item);
ModuleID_item = proto_tree_add_uint(IODataObject_tree, hf_pn_io_ps_sb_toggelBitChange_subslot_nr, tvb, offset, 0, io_data_object->subSlotNr);
PROTO_ITEM_SET_HIDDEN(ModuleID_item);
}
offset = dissect_pn_io_ps_SB(tvb, offset, pinfo, IODataObject_tree, drep, hf_pn_io_ps_sb, ps_sb_fields);
offset = dissect_pn_user_data(tvb, offset, pinfo, IODataObject_tree, io_data_object->f_crc_len, "CRC");
io_data_object->last_sb_cb = statusbyte;
io_data_object->lastToggleBit = toggleBitSb;
}
else {
offset = dissect_pn_user_data(tvb, offset, pinfo, IODataObject_tree, io_data_object->length, "IO Data");
}
if (io_data_object->discardIOXS == FALSE) {
offset = dissect_PNIO_IOxS(tvb, offset, pinfo, IODataObject_tree, drep, hf_pn_io_iops, ioxs_fields);
proto_item_set_len(IODataObject_item, io_data_object->length + 1);
}
else {
proto_item_set_len(IODataObject_item, io_data_object->length);
}
proto_item_append_text(IODataObject_item, ": Slot: 0x%x Subslot: 0x%x",
io_data_object->slotNr, io_data_object->subSlotNr);
if (io_data_object->amountInGSDML > 1) {
if (io_data_object->slotNr == 0) {
moduleName = wmem_strbuf_new(wmem_packet_scope(), "Headstation");
}
else {
moduleName = wmem_strbuf_new(wmem_packet_scope(), "Module");
}
if (io_data_object->profisafeSupported == TRUE) {
if (io_data_object->length >= 5) {
wmem_strbuf_append(moduleName, ", DI");
}
else {
wmem_strbuf_append(moduleName, ", DO");
}
}
else {
if (io_data_object->length > 0) {
wmem_strbuf_append(moduleName, ", DI");
}
else {
wmem_strbuf_append(moduleName, ", DO");
}
}
io_data_object->moduleNameStr = wmem_strdup(wmem_file_scope(), wmem_strbuf_get_str(moduleName));
}
proto_item_append_text(IODataObject_item, " ModuleName: \"%s\"", io_data_object->moduleNameStr);
if (io_data_object->profisafeSupported == TRUE && pnio_ps_selection == TRUE) {
(proto_item_append_text(IODataObject_item, " (PROFIsafe Module)"));
}
frameOffset = frameOffset + io_data_object->length;
if (io_data_object->discardIOXS == FALSE) {
frameOffset = frameOffset + 1;
}
}
}
}
if (station_info != NULL) {
for (frame = wmem_list_head(station_info->iocs_data_in); frame != NULL; frame = wmem_list_frame_next(frame)) {
iocs_object = (iocsObject*)wmem_list_frame_data(frame);
if (iocs_object->frameOffset == frameOffset) {
offset = dissect_PNIO_IOCS(tvb, offset, pinfo, data_tree, drep, hf_pn_io_iocs, iocs_object->slotNr,
iocs_object->subSlotNr, ioxs_fields);
frameOffset = frameOffset + 1;
break;
}
}
}
}
offset = dissect_pn_user_data(tvb, offset, pinfo, tree, tvb_captured_length_remaining(tvb, offset), "GAP and RTCPadding");
}
else if (outputFlag) {
if (pnio_ps_selection == TRUE) {
proto_tree_add_string_format_value(data_tree, hf_pn_io_frame_info_type, tvb,
offset, 0, "Request", "Request Frame (IO_Controller -> IO_Device)");
}
else {
proto_tree_add_string_format_value(data_tree, hf_pn_io_frame_info_type, tvb,
offset, 0, "Output", "Output Frame (IO_Controller -> IO_Device)");
}
if (station_info != NULL) {
if (station_info->typeofstation != NULL) {
proto_tree_add_string_format_value(data_tree, hf_pn_io_frame_info_vendor, tvb, 0,
0, station_info->typeofstation, "\"%s\"", station_info->typeofstation);
}
if (station_info->nameofstation != NULL) {
proto_tree_add_string_format_value(data_tree, hf_pn_io_frame_info_nameofstation, tvb, 0,
0, station_info->nameofstation, "\"%s\"", station_info->nameofstation);
}
if (station_info->gsdPathLength == TRUE) {
if (station_info->gsdFound == TRUE) {
if (station_info->gsdLocation != NULL) {
IODataObject_item_info = proto_tree_add_item(data_tree, hf_pn_io_frame_info_gsd_found, tvb, offset, 0, ENC_NA);
proto_item_append_text(IODataObject_item_info, ": \"%s\"", station_info->gsdLocation);
}
}
else {
if (station_info->gsdLocation != NULL) {
IODataObject_item_info = proto_tree_add_item(data_tree, hf_pn_io_frame_info_gsd_error, tvb, offset, 0, ENC_NA);
proto_item_append_text(IODataObject_item_info, " Please place relevant GSD-file under \"%s\"", station_info->gsdLocation);
}
}
}
else {
IODataObject_item_info = proto_tree_add_item(data_tree, hf_pn_io_frame_info_gsd_path, tvb, offset, 0, ENC_NA);
proto_item_append_text(IODataObject_item_info, " Please check your GSD-file networkpath. (No Path configured)");
}
}
objectCounter = number_io_data_objects_output_cr + number_iocs_output_cr;
if (objectCounter > (guint)tvb_reported_length_remaining(tvb, offset)) {
expert_add_info_format(pinfo, data_item, &ei_pn_io_too_many_data_objects, "Too many data objects: %d", objectCounter);
return(tvb_captured_length(tvb));
}
while (objectCounter--) {
if (station_info != NULL) {
for (frame = wmem_list_head(station_info->ioobject_data_out); frame != NULL; frame = wmem_list_frame_next(frame)) {
io_data_object = (ioDataObject*)wmem_list_frame_data(frame);
if (io_data_object != NULL && io_data_object->frameOffset == frameOffset) {
IODataObject_item = proto_tree_add_item(data_tree, hf_pn_io_io_data_object, tvb, offset, 0, ENC_NA);
IODataObject_tree = proto_item_add_subtree(IODataObject_item, ett_pn_io_io_data_object);
for (frame_diff = wmem_list_head(station_info->diff_module); frame_diff != NULL; frame_diff = wmem_list_frame_next(frame_diff)) {
module_diff_info = (moduleDiffInfo*)wmem_list_frame_data(frame_diff);
if (io_data_object->moduleIdentNr != module_diff_info->modulID) {
ModuleDiff_item = proto_tree_add_item(IODataObject_tree, hf_pn_io_io_data_object_info_module_diff, tvb, 0, 0, ENC_NA);
proto_item_append_text(ModuleDiff_item, ": Device using ModuleIdentNumber 0x%08x instead of 0x%08x", module_diff_info->modulID, io_data_object->moduleIdentNr);
break;
}
}
proto_tree_add_uint(IODataObject_tree, hf_pn_io_io_data_object_info_moduleidentnumber, tvb, 0, 0, io_data_object->moduleIdentNr);
proto_tree_add_uint(IODataObject_tree, hf_pn_io_io_data_object_info_submoduleidentnumber, tvb, 0, 0, io_data_object->subModuleIdentNr);
if (io_data_object->profisafeSupported == TRUE && pnio_ps_selection == TRUE) {
if (io_data_object->profisafeSupported == TRUE && psInfoText == FALSE) {
col_append_str(pinfo->cinfo, COL_INFO, ", PROFIsafe Device");
psInfoText = TRUE;
}
proto_tree_add_uint(IODataObject_tree, hf_pn_io_ps_f_dest_adr, tvb, 0, 0, io_data_object->f_dest_adr);
if ((io_data_object->length - F_MESSAGE_TRAILER_4BYTE) > 0) {
offset = dissect_pn_io_ps_uint(tvb, offset, pinfo, IODataObject_tree, drep, hf_pn_io_ps_f_data,
(io_data_object->length - F_MESSAGE_TRAILER_4BYTE), &f_data);
}
controlbyte = tvb_get_guint8(tvb, offset);
toggleBitCb = controlbyte & 0x20;
if (io_data_object->lastToggleBit != toggleBitCb) {
ModuleID_item = proto_tree_add_uint(IODataObject_tree, hf_pn_io_ps_cb_toggelBitChanged, tvb, offset, 0, toggleBitCb);
PROTO_ITEM_SET_HIDDEN(ModuleID_item);
ModuleID_item = proto_tree_add_uint(IODataObject_tree, hf_pn_io_ps_cb_toggelBitChange_slot_nr, tvb, offset, 0, io_data_object->slotNr);
PROTO_ITEM_SET_HIDDEN(ModuleID_item);
ModuleID_item = proto_tree_add_uint(IODataObject_tree, hf_pn_io_ps_cb_toggelBitChange_subslot_nr, tvb, offset, 0, io_data_object->subSlotNr);
PROTO_ITEM_SET_HIDDEN(ModuleID_item);
}
offset = dissect_pn_io_ps_CB(tvb, offset, pinfo, IODataObject_tree, drep, hf_pn_io_ps_cb, ps_cb_fields);
offset = dissect_pn_user_data(tvb, offset, pinfo, IODataObject_tree, io_data_object->f_crc_len, "CRC");
io_data_object->last_sb_cb = controlbyte;
io_data_object->lastToggleBit = toggleBitCb;
}
else {
offset = dissect_pn_user_data(tvb, offset, pinfo, IODataObject_tree, io_data_object->length, "IO Data");
}
if (io_data_object->discardIOXS == FALSE) {
offset = dissect_PNIO_IOxS(tvb, offset, pinfo, IODataObject_tree, drep, hf_pn_io_iops, ioxs_fields);
proto_item_set_len(IODataObject_item, io_data_object->length + 1);
}
else {
proto_item_set_len(IODataObject_item, io_data_object->length);
}
proto_item_append_text(IODataObject_item, ": Slot: 0x%x Subslot: 0x%x",
io_data_object->slotNr, io_data_object->subSlotNr);
if (io_data_object->amountInGSDML > 1) {
if (io_data_object->slotNr == 0) {
moduleName = wmem_strbuf_new(wmem_packet_scope(), "Headstation");
}
else {
moduleName = wmem_strbuf_new(wmem_packet_scope(), "Module");
}
if (io_data_object->profisafeSupported == TRUE) {
if (io_data_object->length >= 5) {
wmem_strbuf_append(moduleName, ", DO");
}
else {
wmem_strbuf_append(moduleName, ", DI");
}
}
else {
if (io_data_object->length > 0) {
wmem_strbuf_append(moduleName, ", DO");
}
else {
wmem_strbuf_append(moduleName, ", DI");
}
}
io_data_object->moduleNameStr = wmem_strdup(wmem_file_scope(), wmem_strbuf_get_str(moduleName));
}
proto_item_append_text(IODataObject_item, " ModuleName: \"%s\"", io_data_object->moduleNameStr);
if (io_data_object->profisafeSupported == TRUE && pnio_ps_selection == TRUE) {
proto_item_append_text(IODataObject_item, " (PROFIsafe Module)");
}
frameOffset = frameOffset + io_data_object->length;
if (io_data_object->discardIOXS == FALSE) {
frameOffset = frameOffset + 1;
}
}
}
}
if (station_info != NULL) {
for (frame = wmem_list_head(station_info->iocs_data_out); frame != NULL; frame = wmem_list_frame_next(frame)) {
iocs_object = (iocsObject*)wmem_list_frame_data(frame);
if (iocs_object->frameOffset == frameOffset) {
offset = dissect_PNIO_IOCS(tvb, offset, pinfo, data_tree, drep, hf_pn_io_iocs, iocs_object->slotNr,
iocs_object->subSlotNr, ioxs_fields);
frameOffset = frameOffset + 1;
break;
}
}
}
}
offset = dissect_pn_user_data(tvb, offset, pinfo, tree, tvb_captured_length_remaining(tvb, offset), "GAP and RTCPadding");
}
return offset;
}
void
init_pn_io_rtc1(int proto)
{
static hf_register_info hf[] = {
{ &hf_pn_io_io_data_object,
{ "IODataObject", "pn_io.io_data_object",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_io_data_object_info_module_diff,
{ "Difference", "pn_io.io_data_object.diff_module",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_io_data_object_info_moduleidentnumber,
{ "ModuleIdentNumber", "pn_io.io_data_object.module_nr",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_io_data_object_info_submoduleidentnumber,
{ "SubmoduleIdentNumber", "pn_io.io_data_object.submodule_nr",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_frame_info_type,
{ "PN Frame Type", "pn_io.frame_info.type",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_frame_info_vendor,
{ "DeviceVendorValue", "pn_io.frame_info.vendor",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_frame_info_nameofstation,
{ "NameOfStation", "pn_io.frame_info.nameofstation",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_frame_info_gsd_found,
{ "GSD-file found", "pn_io.frame_info.gsd_found",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_frame_info_gsd_error,
{ "GSD-file not found.", "pn_io.frame_info.gsd_error",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_frame_info_gsd_path,
{ "GSD-file networkpath failure!", "pn_io.frame_info.gsd_path",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_iocs,
{ "IOCS", "pn_io.ioxs",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_iops,
{ "IOPS", "pn_io.ioxs",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ioxs_extension,
{ "Extension", "pn_io.ioxs.extension",
FT_UINT8, BASE_HEX, VALS(pn_io_ioxs_extension), 0x01,
NULL, HFILL }
},
{ &hf_pn_io_ioxs_res14,
{ "Reserved", "pn_io.ioxs.res14",
FT_UINT8, BASE_HEX, NULL, 0x1E,
NULL, HFILL }
},
{ &hf_pn_io_ioxs_instance,
{ "Instance", "pn_io.ioxs.instance",
FT_UINT8, BASE_HEX, VALS(pn_io_ioxs_instance), 0x60,
NULL, HFILL }
},
{ &hf_pn_io_ioxs_datastate,
{ "DataState", "pn_io.ioxs.datastate",
FT_UINT8, BASE_HEX, VALS(pn_io_ioxs_datastate), 0x80,
NULL, HFILL }
},
{ &hf_pn_io_ps_sb,
{ "Status Byte", "pn_io.ps.sb",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ps_sb_toggelBitChanged,
{ "Status Byte", "pn_io.ps.sb.toggle_d_changed",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pn_io_ps_sb_toggelBitChange_slot_nr,
{ "Slot_Number", "pn_io.ps.sb.toggle_d_changed.slot",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ps_sb_toggelBitChange_subslot_nr,
{ "Sub_Slot_Number", "pn_io.ps.sb.toggle_d_changed.subslot",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ps_cb,
{ "Control Byte", "pn_io.ps.cb",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ps_cb_toggelBitChanged,
{ "Control Byte", "pn_io.ps.cb.toggle_h_changed",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pn_io_ps_cb_toggelBitChange_slot_nr,
{ "Slot_Number", "pn_io.ps.cb.toggle_h_changed.slot",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ps_cb_toggelBitChange_subslot_nr,
{ "Sub_Slot_Number", "pn_io.ps.cb.toggle_h_changed.subslot",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ps_sb_iparOK,
{ "iPar_OK - F-Device has new iParameter values assigned", "pn_io.ps.sb.iPar_OK",
FT_UINT8, BASE_HEX, NULL, 0x01,
NULL, HFILL }
},
{ &hf_pn_io_ps_sb_DeviceFault,
{ "Device_Fault - Failure exists in F-Device or F-Module", "pn_io.ps.sb.DeviceFault",
FT_UINT8, BASE_HEX, NULL, 0x02,
NULL, HFILL }
},
{ &hf_pn_io_ps_sb_CECRC,
{ "CE_CRC - CRC Communication fault", "pn_io.ps.sb.CE_CRC",
FT_UINT8, BASE_HEX, NULL, 0x04,
NULL, HFILL }
},
{ &hf_pn_io_ps_sb_WDtimeout,
{ "WD_timeout - WatchDog timeout Communication fault", "pn_io.ps.sb.WD_timeout",
FT_UINT8, BASE_HEX, NULL, 0x08,
NULL, HFILL }
},
{ &hf_pn_io_ps_sb_FVactivated,
{ "FV_activated - Fail-safe values (FV) activated", "pn_io.ps.sb.FV_activated",
FT_UINT8, BASE_HEX, NULL, 0x10,
NULL, HFILL }
},
{ &hf_pn_io_ps_sb_Toggle_d,
{ "Toggle_d - Device-based Toggle Bit", "pn_io.ps.sb.Toggle_d",
FT_UINT8, BASE_HEX, NULL, 0x20,
NULL, HFILL }
},
{ &hf_pn_io_ps_sb_ConsNr_reset,
{ "cons_nr_R - F-Device has reset its consecutive number counter", "pn_io.ps.sb.cons_nr_R",
FT_UINT8, BASE_HEX, NULL, 0x40,
NULL, HFILL }
},
{ &hf_pn_io_ps_sb_res,
{ "Bit7 - reserved for future releases", "pn_io.ps.sb.bit7",
FT_UINT8, BASE_HEX, NULL, 0x80,
NULL, HFILL }
},
{ &hf_pn_io_ps_cb_iparEN,
{ "iPar_EN - iParameter assignment deblocked", "pn_io.ps.cb.iparEN",
FT_UINT8, BASE_HEX, NULL, 0x01,
NULL, HFILL }
},
{ &hf_pn_io_ps_cb_OAReq,
{ "OA_Req - Operator acknowledge requested", "pn_io.ps.cb.OA_Req",
FT_UINT8, BASE_HEX, NULL, 0x02,
NULL, HFILL }
},
{ &hf_pn_io_ps_cb_resetConsNr,
{ "R_cons_nr - Set the Virtual Consecutive Number within the F-Device to be \"0\"", "pn_io.ps.cb.R_cons_nr",
FT_UINT8, BASE_HEX, NULL, 0x04,
NULL, HFILL }
},
{ &hf_pn_io_ps_cb_useTO2,
{ "Bit3 - Reserved or Use the secondary watchdog (Use_TO2)", "pn_io.ps.cb.bit3",
FT_UINT8, BASE_HEX, NULL, 0x08,
NULL, HFILL }
},
{ &hf_pn_io_ps_cb_activateFV,
{ "activate_FV - Fail-safe values (FV) to be activated", "pn_io.ps.cb.activate_FV",
FT_UINT8, BASE_HEX, NULL, 0x10,
NULL, HFILL }
},
{ &hf_pn_io_ps_cb_Toggle_h,
{ "Toggle_h - Host-based Toggle Bit", "pn_io.ps.cb.Toggle_h",
FT_UINT8, BASE_HEX, NULL, 0x20,
NULL, HFILL }
},
{ &hf_pn_io_ps_cb_Chf_ACK,
{ "Bit6 - Reserved or Operator acknowledge after cleared channel fault (ChF_Ack)", "pn_io.ps.cb.bit6",
FT_UINT8, BASE_HEX, NULL, 0x40,
NULL, HFILL }
},
{ &hf_pn_io_ps_cb_loopcheck,
{ "Bit7 - Reserved or Loop-back check (Loopcheck, shall be set to 1)", "pn_io.ps.cb.bit7",
FT_UINT8, BASE_HEX, NULL, 0x80,
NULL, HFILL }
},
{ &hf_pn_io_ps_f_dest_adr,
{ "F_Dest_Add", "pn_io.ps.f_dest_add",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pn_io_ps_f_data,
{ "SafetyIO Data", "pn_io.ps.f_data",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_pn_io_rtc,
&ett_pn_io_ioxs,
&ett_pn_io_io_data_object
};
static ei_register_info ei[] = {
{ &ei_pn_io_too_many_data_objects, { "pn_io.too_many_data_objects", PI_MALFORMED, PI_ERROR, "Too many data objects", EXPFILL }},
};
expert_module_t* expert_pn_io;
proto_pn_io_rtc1 = proto;
proto_register_field_array(proto, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_pn_io = expert_register_protocol(proto_pn_io_rtc1);
expert_register_field_array(expert_pn_io, ei, array_length(ei));
}
