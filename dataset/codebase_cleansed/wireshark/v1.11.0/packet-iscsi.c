static void
iscsi_dissect_TargetAddress(packet_info *pinfo, proto_tree *tree _U_,char *val)
{
address *addr = NULL;
int port;
char *value = wmem_strdup(wmem_packet_scope(), val);
char *p = NULL, *pgt = NULL;
if (value[0] == '[') {
p = strchr(value, ']');
if (p != NULL) {
*p = 0;
p += 2;
pgt = strchr(p, ',');
if (pgt != NULL) {
*pgt++ = 0;
}
}
} else {
int i0,i1,i2,i3;
if (sscanf(value, "%d.%d.%d.%d", &i0,&i1,&i2,&i3) == 4) {
p = strchr(value, ':');
if (p != NULL) {
*p++ = 0;
pgt = strchr(p, ',');
if (pgt != NULL) {
*pgt++ = 0;
}
addr = wmem_new(wmem_packet_scope(), address);
addr->type = AT_IPv4;
addr->len = 4;
addr->data = wmem_alloc(wmem_packet_scope(), 4);
((char *)addr->data)[0] = i0;
((char *)addr->data)[1] = i1;
((char *)addr->data)[2] = i2;
((char *)addr->data)[3] = i3;
port = atoi(p);
}
}
}
if (addr && !pinfo->fd->flags.visited) {
conversation_t *conv;
conv = conversation_new(pinfo->fd->num, addr, addr, PT_TCP, port, port, NO_ADDR2|NO_PORT2);
if (conv == NULL) {
return;
}
conversation_set_dissector(conv, iscsi_handle);
}
}
static gint
addTextKeys(packet_info *pinfo, proto_tree *tt, tvbuff_t *tvb, gint offset, guint32 text_len) {
const gint limit = offset + text_len;
while(offset < limit) {
char *key = NULL, *value = NULL;
gint len = tvb_strnlen(tvb, offset, limit - offset);
if(len == -1) {
len = limit - offset;
} else {
len = len + 1;
}
key = tvb_get_string(wmem_packet_scope(), tvb, offset, len);
if (key == NULL) {
break;
}
value = strchr(key, '=');
if (value == NULL) {
break;
}
*value++ = 0;
if (!strcmp(key, "TargetAddress")) {
iscsi_dissect_TargetAddress(pinfo, tt, value);
}
proto_tree_add_item(tt, hf_iscsi_KeyValue, tvb, offset, len, ENC_ASCII|ENC_NA);
offset += len;
}
return offset;
}
static gint
handleHeaderDigest(iscsi_session_t *iscsi_session, proto_item *ti, tvbuff_t *tvb, guint offset, int headerLen) {
int available_bytes = tvb_length_remaining(tvb, offset);
switch(iscsi_session->header_digest){
case ISCSI_HEADER_DIGEST_CRC32:
if(available_bytes >= (headerLen + 4)) {
guint32 crc = ~crc32c_calculate(tvb_get_ptr(tvb, offset, headerLen), headerLen, CRC32C_PRELOAD);
guint32 sent = tvb_get_ntohl(tvb, offset + headerLen);
if(crc == sent) {
proto_tree_add_uint_format_value(ti, hf_iscsi_HeaderDigest32, tvb, offset + headerLen, 4, sent, "0x%08x (Good CRC32)", sent);
} else {
proto_tree_add_uint_format_value(ti, hf_iscsi_HeaderDigest32, tvb, offset + headerLen, 4, sent, "0x%08x (Bad CRC32, should be 0x%08x)", sent, crc);
}
}
return offset + headerLen + 4;
}
return offset + headerLen;
}
static gint
handleDataDigest(proto_item *ti, tvbuff_t *tvb, guint offset, int dataLen) {
int available_bytes = tvb_length_remaining(tvb, offset);
if(enableDataDigests) {
if(dataDigestIsCRC32) {
if(available_bytes >= (dataLen + 4)) {
guint32 crc = ~crc32c_calculate(tvb_get_ptr(tvb, offset, dataLen), dataLen, CRC32C_PRELOAD);
guint32 sent = tvb_get_ntohl(tvb, offset + dataLen);
if(crc == sent) {
proto_tree_add_uint_format_value(ti, hf_iscsi_DataDigest32, tvb, offset + dataLen, 4, sent, "0x%08x (Good CRC32)", sent);
}
else {
proto_tree_add_uint_format_value(ti, hf_iscsi_DataDigest32, tvb, offset + dataLen, 4, sent, "0x%08x (Bad CRC32, should be 0x%08x)", sent, crc);
}
}
return offset + dataLen + 4;
}
if((unsigned)available_bytes >= (dataLen + dataDigestSize)) {
proto_tree_add_item(ti, hf_iscsi_DataDigest, tvb, offset + dataLen, dataDigestSize, ENC_NA);
}
return offset + dataLen + dataDigestSize;
}
return offset + dataLen;
}
static int
handleDataSegment(proto_item *ti, tvbuff_t *tvb, guint offset, guint dataSegmentLen, guint endOffset, int hf_id) {
if(endOffset > offset) {
int dataOffset = offset;
int dataLen = MIN(dataSegmentLen, endOffset - offset);
if(dataLen > 0) {
proto_tree_add_item(ti, hf_id, tvb, offset, dataLen, ENC_NA);
offset += dataLen;
}
if(offset < endOffset && (offset & 3) != 0) {
int padding = 4 - (offset & 3);
proto_tree_add_item(ti, hf_iscsi_Padding, tvb, offset, padding, ENC_NA);
offset += padding;
}
if(dataSegmentLen > 0 && offset < endOffset)
offset = handleDataDigest(ti, tvb, dataOffset, offset - dataOffset);
}
return offset;
}
static int
handleDataSegmentAsTextKeys(packet_info *pinfo, proto_item *ti, tvbuff_t *tvb, guint offset, guint dataSegmentLen, guint endOffset, int digestsActive) {
if(endOffset > offset) {
int dataOffset = offset;
int textLen = MIN(dataSegmentLen, endOffset - offset);
if(textLen > 0) {
proto_item *tf = proto_tree_add_text(ti, tvb, offset, textLen, "Key/Value Pairs");
proto_tree *tt = proto_item_add_subtree(tf, ett_iscsi_KeyValues);
offset = addTextKeys(pinfo, tt, tvb, offset, textLen);
}
if(offset < endOffset && (offset & 3) != 0) {
int padding = 4 - (offset & 3);
proto_tree_add_item(ti, hf_iscsi_Padding, tvb, offset, padding, ENC_NA);
offset += padding;
}
if(digestsActive && dataSegmentLen > 0 && offset < endOffset)
offset = handleDataDigest(ti, tvb, dataOffset, offset - dataOffset);
}
return offset;
}
static void
dissect_iscsi_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, guint8 opcode, const char *opcode_str, guint32 data_segment_len, iscsi_session_t *iscsi_session, conversation_t *conversation) {
guint original_offset = offset;
proto_tree *ti = NULL;
guint8 scsi_status = 0;
gboolean S_bit=FALSE;
gboolean A_bit=FALSE;
guint cdb_offset = offset + 32;
guint end_offset = offset + tvb_length_remaining(tvb, offset);
iscsi_conv_data_t *cdata = NULL;
int paddedDataSegmentLength = data_segment_len;
guint16 lun=0xffff;
guint immediate_data_length=0;
guint immediate_data_offset=0;
itl_nexus_t *itl=NULL;
guint ahs_cdb_length=0;
guint ahs_cdb_offset=0;
guint32 data_offset=0;
if(paddedDataSegmentLength & 3)
paddedDataSegmentLength += 4 - (paddedDataSegmentLength & 3);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "iSCSI");
cdata=(iscsi_conv_data_t *)wmem_tree_lookup32(iscsi_session->itlq, tvb_get_ntohl(tvb, offset+16));
if(!cdata){
cdata = wmem_new(wmem_file_scope(), iscsi_conv_data_t);
cdata->itlq.lun=0xffff;
cdata->itlq.scsi_opcode=0xffff;
cdata->itlq.task_flags=0;
cdata->itlq.data_length=0;
cdata->itlq.bidir_data_length=0;
cdata->itlq.fc_time = pinfo->fd->abs_ts;
cdata->itlq.first_exchange_frame=0;
cdata->itlq.last_exchange_frame=0;
cdata->itlq.flags=0;
cdata->itlq.alloc_len=0;
cdata->itlq.extra_data=NULL;
cdata->data_in_frame=0;
cdata->data_out_frame=0;
wmem_tree_insert32(iscsi_session->itlq, tvb_get_ntohl(tvb, offset+16), cdata);
}
if (opcode == ISCSI_OPCODE_SCSI_RESPONSE ||
opcode == ISCSI_OPCODE_SCSI_DATA_IN) {
scsi_status = tvb_get_guint8 (tvb, offset+3);
}
if ((opcode == ISCSI_OPCODE_SCSI_RESPONSE) ||
(opcode == ISCSI_OPCODE_SCSI_DATA_IN) ||
(opcode == ISCSI_OPCODE_SCSI_DATA_OUT)) {
switch(opcode){
case ISCSI_OPCODE_SCSI_RESPONSE:
cdata->itlq.last_exchange_frame=pinfo->fd->num;
break;
case ISCSI_OPCODE_SCSI_DATA_IN:
if(tvb_get_guint8(tvb, offset+1)&ISCSI_SCSI_DATA_FLAG_S){
cdata->itlq.last_exchange_frame=pinfo->fd->num;
}
cdata->data_in_frame=pinfo->fd->num;
break;
case ISCSI_OPCODE_SCSI_DATA_OUT:
cdata->data_out_frame=pinfo->fd->num;
break;
}
} else if (opcode == ISCSI_OPCODE_SCSI_COMMAND) {
if(tvb_get_guint8(tvb, offset+8)&0x40){
lun=tvb_get_guint8(tvb,offset+8)&0x3f;
lun<<=8;
lun|=tvb_get_guint8(tvb,offset+9);
} else {
lun=tvb_get_guint8(tvb,offset+9);
}
cdata->itlq.lun=lun;
cdata->itlq.first_exchange_frame=pinfo->fd->num;
itl=(itl_nexus_t *)wmem_tree_lookup32(iscsi_session->itl, lun);
if(!itl){
itl=wmem_new(wmem_file_scope(), itl_nexus_t);
itl->cmdset=0xff;
itl->conversation=conversation;
wmem_tree_insert32(iscsi_session->itl, lun, itl);
}
}
if(!itl){
itl=(itl_nexus_t *)wmem_tree_lookup32(iscsi_session->itl, cdata->itlq.lun);
}
if (opcode != ISCSI_OPCODE_SCSI_COMMAND) {
col_append_str(pinfo->cinfo, COL_INFO, opcode_str);
if (opcode == ISCSI_OPCODE_SCSI_RESPONSE ||
(opcode == ISCSI_OPCODE_SCSI_DATA_IN &&
(tvb_get_guint8(tvb, offset + 1) & ISCSI_SCSI_DATA_FLAG_S))) {
col_append_fstr (pinfo->cinfo, COL_INFO, " (%s)",
val_to_str (scsi_status, scsi_status_val, "0x%x"));
}
else if (opcode == ISCSI_OPCODE_LOGIN_RESPONSE) {
guint16 login_status = tvb_get_ntohs(tvb, offset+36);
col_append_fstr (pinfo->cinfo, COL_INFO, " (%s)",
val_to_str (login_status, iscsi_login_status, "0x%x"));
}
else if (opcode == ISCSI_OPCODE_LOGOUT_COMMAND) {
guint8 logoutReason;
if(iscsi_protocol_version == ISCSI_PROTOCOL_DRAFT08) {
logoutReason = tvb_get_guint8(tvb, offset+11);
} else if(iscsi_protocol_version >= ISCSI_PROTOCOL_DRAFT13) {
logoutReason = tvb_get_guint8(tvb, offset+1) & 0x7f;
}
else {
logoutReason = tvb_get_guint8(tvb, offset+23);
}
col_append_fstr (pinfo->cinfo, COL_INFO, " (%s)",
val_to_str (logoutReason, iscsi_logout_reasons, "0x%x"));
}
else if (opcode == ISCSI_OPCODE_TASK_MANAGEMENT_FUNCTION) {
guint8 tmf = tvb_get_guint8(tvb, offset + 1) & 0x7f;
col_append_fstr (pinfo->cinfo, COL_INFO, " (%s)",
val_to_str (tmf, iscsi_task_management_functions, "0x%x"));
}
else if (opcode == ISCSI_OPCODE_TASK_MANAGEMENT_FUNCTION_RESPONSE) {
guint8 resp = tvb_get_guint8(tvb, offset + 2);
col_append_fstr (pinfo->cinfo, COL_INFO, " (%s)",
val_to_str (resp, iscsi_task_management_responses, "0x%x"));
}
else if (opcode == ISCSI_OPCODE_REJECT) {
guint8 reason = tvb_get_guint8(tvb, offset + 2);
col_append_fstr (pinfo->cinfo, COL_INFO, " (%s)",
val_to_str (reason, iscsi_reject_reasons, "0x%x"));
}
else if (opcode == ISCSI_OPCODE_ASYNC_MESSAGE) {
guint8 asyncEvent = tvb_get_guint8(tvb, offset + 36);
col_append_fstr (pinfo->cinfo, COL_INFO, " (%s)",
val_to_str (asyncEvent, iscsi_asyncevents, "0x%x"));
}
}
if (tree) {
proto_item *tp;
tp = proto_tree_add_protocol_format(tree, proto_iscsi, tvb,
offset, -1, "iSCSI (%s)",
opcode_str);
ti = proto_item_add_subtree(tp, ett_iscsi);
}
proto_tree_add_uint(ti, hf_iscsi_Opcode, tvb,
offset + 0, 1, opcode);
if((opcode & TARGET_OPCODE_BIT) == 0) {
gint b = tvb_get_guint8(tvb, offset + 0);
if(iscsi_protocol_version == ISCSI_PROTOCOL_DRAFT08) {
if(opcode != ISCSI_OPCODE_SCSI_DATA_OUT &&
opcode != ISCSI_OPCODE_LOGOUT_COMMAND &&
opcode != ISCSI_OPCODE_SNACK_REQUEST)
proto_tree_add_boolean(ti, hf_iscsi_X, tvb, offset + 0, 1, b);
}
if(opcode != ISCSI_OPCODE_SCSI_DATA_OUT &&
opcode != ISCSI_OPCODE_LOGIN_COMMAND &&
opcode != ISCSI_OPCODE_SNACK_REQUEST)
proto_tree_add_boolean(ti, hf_iscsi_I, tvb, offset + 0, 1, b);
}
if(opcode == ISCSI_OPCODE_NOP_OUT) {
if(iscsi_protocol_version > ISCSI_PROTOCOL_DRAFT09) {
proto_tree_add_item(ti, hf_iscsi_TotalAHSLength, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_uint(ti, hf_iscsi_DataSegmentLength, tvb, offset + 5, 3, tvb_get_ntoh24(tvb, offset + 5));
dissect_scsi_lun(ti, tvb, offset + 8);
proto_tree_add_item(ti, hf_iscsi_InitiatorTaskTag, tvb, offset + 16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_TargetTransferTag, tvb, offset + 20, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_CmdSN, tvb, offset + 24, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_ExpStatSN, tvb, offset + 28, 4, ENC_BIG_ENDIAN);
offset = handleHeaderDigest(iscsi_session, ti, tvb, offset, 48);
offset = handleDataSegment(ti, tvb, offset, data_segment_len, end_offset, hf_iscsi_ping_data);
} else if(opcode == ISCSI_OPCODE_NOP_IN) {
if(iscsi_protocol_version > ISCSI_PROTOCOL_DRAFT09) {
proto_tree_add_item(ti, hf_iscsi_TotalAHSLength, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_uint(ti, hf_iscsi_DataSegmentLength, tvb, offset + 5, 3, tvb_get_ntoh24(tvb, offset + 5));
dissect_scsi_lun(ti, tvb, offset + 8);
proto_tree_add_item(ti, hf_iscsi_InitiatorTaskTag, tvb, offset + 16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_TargetTransferTag, tvb, offset + 20, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_StatSN, tvb, offset + 24, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_ExpCmdSN, tvb, offset + 28, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_MaxCmdSN, tvb, offset + 32, 4, ENC_BIG_ENDIAN);
offset = handleHeaderDigest(iscsi_session, ti, tvb, offset, 48);
offset = handleDataSegment(ti, tvb, offset, data_segment_len, end_offset, hf_iscsi_ping_data);
} else if(opcode == ISCSI_OPCODE_SCSI_COMMAND) {
guint32 ahsLen = tvb_get_guint8(tvb, offset + 4) * 4;
{
gint b = tvb_get_guint8(tvb, offset + 1);
proto_item *tf = proto_tree_add_uint(ti, hf_iscsi_Flags, tvb, offset + 1, 1, b);
proto_tree *tt = proto_item_add_subtree(tf, ett_iscsi_Flags);
proto_tree_add_boolean(tt, hf_iscsi_SCSICommand_F, tvb, offset + 1, 1, b);
proto_tree_add_boolean(tt, hf_iscsi_SCSICommand_R, tvb, offset + 1, 1, b);
if(b&0x40){
cdata->itlq.task_flags|=SCSI_DATA_READ;
}
proto_tree_add_boolean(tt, hf_iscsi_SCSICommand_W, tvb, offset + 1, 1, b);
if(b&0x20){
cdata->itlq.task_flags|=SCSI_DATA_WRITE;
}
proto_tree_add_uint(tt, hf_iscsi_SCSICommand_Attr, tvb, offset + 1, 1, b);
}
if(iscsi_protocol_version < ISCSI_PROTOCOL_DRAFT12) {
proto_tree_add_item(ti, hf_iscsi_SCSICommand_CRN, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_item(ti, hf_iscsi_TotalAHSLength, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(ti, hf_iscsi_DataSegmentLength, tvb, offset + 5, 3, tvb_get_ntoh24(tvb, offset + 5));
dissect_scsi_lun(ti, tvb, offset + 8);
proto_tree_add_item(ti, hf_iscsi_InitiatorTaskTag, tvb, offset + 16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_ExpectedDataTransferLength, tvb, offset + 20, 4, ENC_BIG_ENDIAN);
cdata->itlq.data_length=tvb_get_ntohl(tvb, offset+20);
proto_tree_add_item(ti, hf_iscsi_CmdSN, tvb, offset + 24, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_ExpStatSN, tvb, offset + 28, 4, ENC_BIG_ENDIAN);
if(ahsLen > 0) {
guint ahs_offset=offset+48;
guint16 ahs_length=0;
guint8 ahs_type=0;
while(ahs_offset<(offset+48+ahsLen)){
ahs_length=tvb_get_ntohs(tvb, ahs_offset);
proto_tree_add_item(ti, hf_iscsi_AHS_length, tvb, ahs_offset, 2, ENC_BIG_ENDIAN);
ahs_offset+=2;
ahs_type=tvb_get_guint8(tvb, ahs_offset);
proto_tree_add_item(ti, hf_iscsi_AHS_type, tvb, ahs_offset, 1, ENC_BIG_ENDIAN);
ahs_offset++;
switch(ahs_type){
case 0x01:
ahs_cdb_offset=ahs_offset+1;
ahs_cdb_length=ahs_length-1;
proto_tree_add_item(ti, hf_iscsi_AHS_extended_cdb, tvb, ahs_cdb_offset, ahs_cdb_length, ENC_NA);
ahs_offset+=ahs_length;
break;
case 0x02:
ahs_offset++;
proto_tree_add_item(ti, hf_iscsi_AHS_read_data_length, tvb, ahs_offset, 4, ENC_BIG_ENDIAN);
cdata->itlq.bidir_data_length=tvb_get_ntohl(tvb, ahs_offset);
ahs_offset+=4;
break;
default:
proto_tree_add_item(ti, hf_iscsi_AHS_blob, tvb, ahs_offset, ahs_length, ENC_NA);
ahs_offset+=ahs_length;
}
if(ahs_offset & 3){
ahs_offset=(ahs_offset+3) & ~3;
}
}
}
offset = handleHeaderDigest(iscsi_session, ti, tvb, offset, 48 + ahsLen);
immediate_data_offset=offset;
offset = handleDataSegment(ti, tvb, offset, data_segment_len, end_offset, hf_iscsi_immediate_data);
immediate_data_length=offset-immediate_data_offset;
} else if(opcode == ISCSI_OPCODE_SCSI_RESPONSE) {
{
gint b = tvb_get_guint8(tvb, offset + 1);
proto_item *tf = proto_tree_add_uint(ti, hf_iscsi_Flags, tvb, offset + 1, 1, b);
proto_tree *tt = proto_item_add_subtree(tf, ett_iscsi_Flags);
proto_tree_add_boolean(tt, hf_iscsi_SCSIResponse_o, tvb, offset + 1, 1, b);
proto_tree_add_boolean(tt, hf_iscsi_SCSIResponse_u, tvb, offset + 1, 1, b);
proto_tree_add_boolean(tt, hf_iscsi_SCSIResponse_O, tvb, offset + 1, 1, b);
proto_tree_add_boolean(tt, hf_iscsi_SCSIResponse_U, tvb, offset + 1, 1, b);
}
proto_tree_add_item(ti, hf_iscsi_SCSIResponse_Response, tvb, offset + 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_SCSIResponse_Status, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
if(iscsi_protocol_version > ISCSI_PROTOCOL_DRAFT09) {
proto_tree_add_item(ti, hf_iscsi_TotalAHSLength, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_uint(ti, hf_iscsi_DataSegmentLength, tvb, offset + 5, 3, tvb_get_ntoh24(tvb, offset + 5));
proto_tree_add_item(ti, hf_iscsi_InitiatorTaskTag, tvb, offset + 16, 4, ENC_BIG_ENDIAN);
if(iscsi_protocol_version <= ISCSI_PROTOCOL_DRAFT09) {
proto_tree_add_item(ti, hf_iscsi_SCSIResponse_ResidualCount, tvb, offset + 20, 4, ENC_BIG_ENDIAN);
}
proto_tree_add_item(ti, hf_iscsi_StatSN, tvb, offset + 24, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_ExpCmdSN, tvb, offset + 28, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_MaxCmdSN, tvb, offset + 32, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_ExpDataSN, tvb, offset + 36, 4, ENC_BIG_ENDIAN);
if(iscsi_protocol_version <= ISCSI_PROTOCOL_DRAFT09) {
proto_tree_add_item(ti, hf_iscsi_SCSIResponse_BidiReadResidualCount, tvb, offset + 44, 4, ENC_BIG_ENDIAN);
}
else {
proto_tree_add_item(ti, hf_iscsi_SCSIResponse_BidiReadResidualCount, tvb, offset + 40, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_SCSIResponse_ResidualCount, tvb, offset + 44, 4, ENC_BIG_ENDIAN);
}
offset = handleHeaderDigest(iscsi_session, ti, tvb, offset, 48);
handleDataDigest(ti, tvb, offset, paddedDataSegmentLength);
} else if(opcode == ISCSI_OPCODE_TASK_MANAGEMENT_FUNCTION) {
proto_tree_add_item(ti, hf_iscsi_TaskManagementFunction_Function, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
if(iscsi_protocol_version > ISCSI_PROTOCOL_DRAFT09) {
proto_tree_add_item(ti, hf_iscsi_TotalAHSLength, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(ti, hf_iscsi_DataSegmentLength, tvb, offset + 5, 3, tvb_get_ntoh24(tvb, offset + 5));
}
dissect_scsi_lun(ti, tvb, offset + 8);
proto_tree_add_item(ti, hf_iscsi_InitiatorTaskTag, tvb, offset + 16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_TaskManagementFunction_ReferencedTaskTag, tvb, offset + 20, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_CmdSN, tvb, offset + 24, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_ExpStatSN, tvb, offset + 28, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_RefCmdSN, tvb, offset + 32, 4, ENC_BIG_ENDIAN);
offset = handleHeaderDigest(iscsi_session, ti, tvb, offset, 48);
} else if(opcode == ISCSI_OPCODE_TASK_MANAGEMENT_FUNCTION_RESPONSE) {
proto_tree_add_item(ti, hf_iscsi_TaskManagementFunction_Response, tvb, offset + 2, 1, ENC_BIG_ENDIAN);
if(iscsi_protocol_version <= ISCSI_PROTOCOL_DRAFT09) {
proto_tree_add_item(ti, hf_iscsi_TotalAHSLength, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(ti, hf_iscsi_DataSegmentLength, tvb, offset + 5, 3, tvb_get_ntoh24(tvb, offset + 5));
}
proto_tree_add_item(ti, hf_iscsi_InitiatorTaskTag, tvb, offset + 16, 4, ENC_BIG_ENDIAN);
if(iscsi_protocol_version < ISCSI_PROTOCOL_DRAFT12) {
proto_tree_add_item(ti, hf_iscsi_TaskManagementFunction_ReferencedTaskTag, tvb, offset + 20, 4, ENC_BIG_ENDIAN);
}
proto_tree_add_item(ti, hf_iscsi_StatSN, tvb, offset + 24, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_ExpCmdSN, tvb, offset + 28, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_MaxCmdSN, tvb, offset + 32, 4, ENC_BIG_ENDIAN);
offset = handleHeaderDigest(iscsi_session, ti, tvb, offset, 48);
} else if(opcode == ISCSI_OPCODE_LOGIN_COMMAND) {
int digestsActive = 0;
{
gint b = tvb_get_guint8(tvb, offset + 1);
if(iscsi_protocol_version == ISCSI_PROTOCOL_DRAFT08) {
if((b & CSG_MASK) >= ISCSI_CSG_OPERATIONAL_NEGOTIATION)
digestsActive = 1;
}
#if 0
proto_item *tf = proto_tree_add_uint(ti, hf_iscsi_Flags, tvb, offset + 1, 1, b);
proto_tree *tt = proto_item_add_subtree(tf, ett_iscsi_Flags);
#endif
proto_tree_add_boolean(ti, hf_iscsi_Login_T, tvb, offset + 1, 1, b);
if(iscsi_protocol_version >= ISCSI_PROTOCOL_DRAFT13) {
proto_tree_add_boolean(ti, hf_iscsi_Login_C, tvb, offset + 1, 1, b);
}
if(iscsi_protocol_version == ISCSI_PROTOCOL_DRAFT08) {
proto_tree_add_boolean(ti, hf_iscsi_Login_X, tvb, offset + 1, 1, b);
}
proto_tree_add_item(ti, hf_iscsi_Login_CSG, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
if(b&0x80){
proto_tree_add_item(ti, hf_iscsi_Login_NSG, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
}
}
proto_tree_add_item(ti, hf_iscsi_VersionMax, tvb, offset + 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_VersionMin, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
if(iscsi_protocol_version > ISCSI_PROTOCOL_DRAFT09) {
proto_tree_add_item(ti, hf_iscsi_TotalAHSLength, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_uint(ti, hf_iscsi_DataSegmentLength, tvb, offset + 5, 3, tvb_get_ntoh24(tvb, offset + 5));
if(iscsi_protocol_version == ISCSI_PROTOCOL_DRAFT08) {
proto_tree_add_item(ti, hf_iscsi_CID, tvb, offset + 8, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_ISID8, tvb, offset + 12, 2, ENC_BIG_ENDIAN);
}
else {
proto_item *tf = proto_tree_add_item(ti, hf_iscsi_ISID, tvb, offset + 8, 6, ENC_NA);
proto_tree *tt = proto_item_add_subtree(tf, ett_iscsi_ISID);
if(iscsi_protocol_version == ISCSI_PROTOCOL_DRAFT09) {
proto_tree_add_item(tt, hf_iscsi_ISID_Type, tvb, offset + 8, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tt, hf_iscsi_ISID_NamingAuthority, tvb, offset + 9, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tt, hf_iscsi_ISID_Qualifier, tvb, offset + 12, 2, ENC_BIG_ENDIAN);
}
else {
proto_tree_add_item(tt, hf_iscsi_ISID_t, tvb, offset + 8, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tt, hf_iscsi_ISID_a, tvb, offset + 8, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tt, hf_iscsi_ISID_b, tvb, offset + 9, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tt, hf_iscsi_ISID_c, tvb, offset + 11, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tt, hf_iscsi_ISID_d, tvb, offset + 12, 2, ENC_BIG_ENDIAN);
}
}
if(iscsi_protocol_version < ISCSI_PROTOCOL_DRAFT12) {
proto_tree_add_item(ti, hf_iscsi_TSID, tvb, offset + 14, 2, ENC_BIG_ENDIAN);
}
else {
proto_tree_add_item(ti, hf_iscsi_TSIH, tvb, offset + 14, 2, ENC_BIG_ENDIAN);
}
proto_tree_add_item(ti, hf_iscsi_InitiatorTaskTag, tvb, offset + 16, 4, ENC_BIG_ENDIAN);
if(iscsi_protocol_version > ISCSI_PROTOCOL_DRAFT08) {
proto_tree_add_item(ti, hf_iscsi_CID, tvb, offset + 20, 2, ENC_BIG_ENDIAN);
}
proto_tree_add_item(ti, hf_iscsi_CmdSN, tvb, offset + 24, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_ExpStatSN, tvb, offset + 28, 4, ENC_BIG_ENDIAN);
if(digestsActive){
offset = handleHeaderDigest(iscsi_session, ti, tvb, offset, 48);
} else {
offset += 48;
}
offset = handleDataSegmentAsTextKeys(pinfo, ti, tvb, offset, data_segment_len, end_offset, digestsActive);
} else if(opcode == ISCSI_OPCODE_LOGIN_RESPONSE) {
int digestsActive = 0;
{
gint b = tvb_get_guint8(tvb, offset + 1);
if(iscsi_protocol_version == ISCSI_PROTOCOL_DRAFT08) {
if((b & CSG_MASK) >= ISCSI_CSG_OPERATIONAL_NEGOTIATION)
digestsActive = 1;
}
#if 0
proto_item *tf = proto_tree_add_uint(ti, hf_iscsi_Flags, tvb, offset + 1, 1, b);
proto_tree *tt = proto_item_add_subtree(tf, ett_iscsi_Flags);
#endif
proto_tree_add_boolean(ti, hf_iscsi_Login_T, tvb, offset + 1, 1, b);
if(iscsi_protocol_version >= ISCSI_PROTOCOL_DRAFT13) {
proto_tree_add_boolean(ti, hf_iscsi_Login_C, tvb, offset + 1, 1, b);
}
proto_tree_add_item(ti, hf_iscsi_Login_CSG, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
if(b&0x80){
proto_tree_add_item(ti, hf_iscsi_Login_NSG, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
}
}
proto_tree_add_item(ti, hf_iscsi_VersionMax, tvb, offset + 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_VersionActive, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
if(iscsi_protocol_version > ISCSI_PROTOCOL_DRAFT09) {
proto_tree_add_item(ti, hf_iscsi_TotalAHSLength, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_uint(ti, hf_iscsi_DataSegmentLength, tvb, offset + 5, 3, tvb_get_ntoh24(tvb, offset + 5));
if(iscsi_protocol_version == ISCSI_PROTOCOL_DRAFT08) {
proto_tree_add_item(ti, hf_iscsi_ISID8, tvb, offset + 12, 2, ENC_BIG_ENDIAN);
}
else {
proto_item *tf = proto_tree_add_item(ti, hf_iscsi_ISID, tvb, offset + 8, 6, ENC_NA);
proto_tree *tt = proto_item_add_subtree(tf, ett_iscsi_ISID);
if(iscsi_protocol_version == ISCSI_PROTOCOL_DRAFT09) {
proto_tree_add_item(tt, hf_iscsi_ISID_Type, tvb, offset + 8, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tt, hf_iscsi_ISID_NamingAuthority, tvb, offset + 9, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tt, hf_iscsi_ISID_Qualifier, tvb, offset + 12, 2, ENC_BIG_ENDIAN);
}
else {
proto_tree_add_item(tt, hf_iscsi_ISID_t, tvb, offset + 8, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tt, hf_iscsi_ISID_a, tvb, offset + 8, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tt, hf_iscsi_ISID_b, tvb, offset + 9, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tt, hf_iscsi_ISID_c, tvb, offset + 11, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tt, hf_iscsi_ISID_d, tvb, offset + 12, 2, ENC_BIG_ENDIAN);
}
}
if(iscsi_protocol_version < ISCSI_PROTOCOL_DRAFT12) {
proto_tree_add_item(ti, hf_iscsi_TSID, tvb, offset + 14, 2, ENC_BIG_ENDIAN);
}
else {
proto_tree_add_item(ti, hf_iscsi_TSIH, tvb, offset + 14, 2, ENC_BIG_ENDIAN);
}
proto_tree_add_item(ti, hf_iscsi_InitiatorTaskTag, tvb, offset + 16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_StatSN, tvb, offset + 24, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_ExpCmdSN, tvb, offset + 28, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_MaxCmdSN, tvb, offset + 32, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_Login_Status, tvb, offset + 36, 2, ENC_BIG_ENDIAN);
if(digestsActive){
offset = handleHeaderDigest(iscsi_session, ti, tvb, offset, 48);
} else {
offset += 48;
}
offset = handleDataSegmentAsTextKeys(pinfo, ti, tvb, offset, data_segment_len, end_offset, digestsActive);
} else if(opcode == ISCSI_OPCODE_TEXT_COMMAND) {
{
gint b = tvb_get_guint8(tvb, offset + 1);
proto_item *tf = proto_tree_add_uint(ti, hf_iscsi_Flags, tvb, offset + 1, 1, b);
proto_tree *tt = proto_item_add_subtree(tf, ett_iscsi_Flags);
proto_tree_add_boolean(tt, hf_iscsi_Text_F, tvb, offset + 1, 1, b);
if(iscsi_protocol_version >= ISCSI_PROTOCOL_DRAFT13) {
proto_tree_add_boolean(tt, hf_iscsi_Text_C, tvb, offset + 1, 1, b);
}
}
if(iscsi_protocol_version > ISCSI_PROTOCOL_DRAFT09) {
proto_tree_add_item(ti, hf_iscsi_TotalAHSLength, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_uint(ti, hf_iscsi_DataSegmentLength, tvb, offset + 5, 3, tvb_get_ntoh24(tvb, offset + 5));
if(iscsi_protocol_version > ISCSI_PROTOCOL_DRAFT09) {
dissect_scsi_lun(ti, tvb, offset + 8);
}
proto_tree_add_item(ti, hf_iscsi_InitiatorTaskTag, tvb, offset + 16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_TargetTransferTag, tvb, offset + 20, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_CmdSN, tvb, offset + 24, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_ExpStatSN, tvb, offset + 28, 4, ENC_BIG_ENDIAN);
offset = handleHeaderDigest(iscsi_session, ti, tvb, offset, 48);
offset = handleDataSegmentAsTextKeys(pinfo, ti, tvb, offset, data_segment_len, end_offset, TRUE);
} else if(opcode == ISCSI_OPCODE_TEXT_RESPONSE) {
{
gint b = tvb_get_guint8(tvb, offset + 1);
proto_item *tf = proto_tree_add_uint(ti, hf_iscsi_Flags, tvb, offset + 1, 1, b);
proto_tree *tt = proto_item_add_subtree(tf, ett_iscsi_Flags);
proto_tree_add_boolean(tt, hf_iscsi_Text_F, tvb, offset + 1, 1, b);
if(iscsi_protocol_version >= ISCSI_PROTOCOL_DRAFT13) {
proto_tree_add_boolean(tt, hf_iscsi_Text_C, tvb, offset + 1, 1, b);
}
}
if(iscsi_protocol_version > ISCSI_PROTOCOL_DRAFT09) {
proto_tree_add_item(ti, hf_iscsi_TotalAHSLength, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_uint(ti, hf_iscsi_DataSegmentLength, tvb, offset + 5, 3, tvb_get_ntoh24(tvb, offset + 5));
if(iscsi_protocol_version > ISCSI_PROTOCOL_DRAFT09) {
dissect_scsi_lun(ti, tvb, offset + 8);
}
proto_tree_add_item(ti, hf_iscsi_InitiatorTaskTag, tvb, offset + 16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_TargetTransferTag, tvb, offset + 20, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_StatSN, tvb, offset + 24, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_ExpCmdSN, tvb, offset + 28, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_MaxCmdSN, tvb, offset + 32, 4, ENC_BIG_ENDIAN);
offset = handleHeaderDigest(iscsi_session, ti, tvb, offset, 48);
offset = handleDataSegmentAsTextKeys(pinfo, ti, tvb, offset, data_segment_len, end_offset, TRUE);
} else if(opcode == ISCSI_OPCODE_SCSI_DATA_OUT) {
{
gint b = tvb_get_guint8(tvb, offset + 1);
proto_item *tf = proto_tree_add_uint(ti, hf_iscsi_Flags, tvb, offset + 1, 1, b);
proto_tree *tt = proto_item_add_subtree(tf, ett_iscsi_Flags);
proto_tree_add_boolean(tt, hf_iscsi_SCSIData_F, tvb, offset + 1, 1, b);
}
if(iscsi_protocol_version > ISCSI_PROTOCOL_DRAFT09) {
proto_tree_add_item(ti, hf_iscsi_TotalAHSLength, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_uint(ti, hf_iscsi_DataSegmentLength, tvb, offset + 5, 3, tvb_get_ntoh24(tvb, offset + 5));
dissect_scsi_lun(ti, tvb, offset + 8);
proto_tree_add_item(ti, hf_iscsi_InitiatorTaskTag, tvb, offset + 16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_TargetTransferTag, tvb, offset + 20, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_ExpStatSN, tvb, offset + 28, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_DataSN, tvb, offset + 36, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_BufferOffset, tvb, offset + 40, 4, ENC_BIG_ENDIAN);
data_offset=tvb_get_ntohl(tvb, offset+40);
offset = handleHeaderDigest(iscsi_session, ti, tvb, offset, 48);
handleDataDigest(ti, tvb, offset, paddedDataSegmentLength);
} else if(opcode == ISCSI_OPCODE_SCSI_DATA_IN) {
{
gint b = tvb_get_guint8(tvb, offset + 1);
proto_item *tf = proto_tree_add_uint(ti, hf_iscsi_Flags, tvb, offset + 1, 1, b);
proto_tree *tt = proto_item_add_subtree(tf, ett_iscsi_Flags);
if(b&ISCSI_SCSI_DATA_FLAG_S){
S_bit=TRUE;
}
if(b&ISCSI_SCSI_DATA_FLAG_A){
A_bit=TRUE;
}
proto_tree_add_boolean(tt, hf_iscsi_SCSIData_F, tvb, offset + 1, 1, b);
if(iscsi_protocol_version > ISCSI_PROTOCOL_DRAFT08) {
proto_tree_add_boolean(tt, hf_iscsi_SCSIData_A, tvb, offset + 1, 1, b);
}
proto_tree_add_boolean(tt, hf_iscsi_SCSIData_O, tvb, offset + 1, 1, b);
proto_tree_add_boolean(tt, hf_iscsi_SCSIData_U, tvb, offset + 1, 1, b);
proto_tree_add_boolean(tt, hf_iscsi_SCSIData_S, tvb, offset + 1, 1, b);
}
if(S_bit){
proto_tree_add_item(ti, hf_iscsi_SCSIResponse_Status, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
}
if(iscsi_protocol_version > ISCSI_PROTOCOL_DRAFT09) {
proto_tree_add_item(ti, hf_iscsi_TotalAHSLength, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_uint(ti, hf_iscsi_DataSegmentLength, tvb, offset + 5, 3, tvb_get_ntoh24(tvb, offset + 5));
if(iscsi_protocol_version > ISCSI_PROTOCOL_DRAFT09) {
if (A_bit) {
dissect_scsi_lun(ti, tvb, offset + 8);
}
}
proto_tree_add_item(ti, hf_iscsi_InitiatorTaskTag, tvb, offset + 16, 4, ENC_BIG_ENDIAN);
if(iscsi_protocol_version <= ISCSI_PROTOCOL_DRAFT09) {
proto_tree_add_item(ti, hf_iscsi_SCSIData_ResidualCount, tvb, offset + 20, 4, ENC_BIG_ENDIAN);
}
else {
if (A_bit) {
proto_tree_add_item(ti, hf_iscsi_TargetTransferTag, tvb, offset + 20, 4, ENC_BIG_ENDIAN);
}
}
proto_tree_add_item(ti, hf_iscsi_StatSN, tvb, offset + 24, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_ExpCmdSN, tvb, offset + 28, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_MaxCmdSN, tvb, offset + 32, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_DataSN, tvb, offset + 36, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_BufferOffset, tvb, offset + 40, 4, ENC_BIG_ENDIAN);
data_offset=tvb_get_ntohl(tvb, offset+40);
if(iscsi_protocol_version > ISCSI_PROTOCOL_DRAFT09) {
proto_tree_add_item(ti, hf_iscsi_SCSIData_ResidualCount, tvb, offset + 44, 4, ENC_BIG_ENDIAN);
}
offset = handleHeaderDigest(iscsi_session, ti, tvb, offset, 48);
handleDataDigest(ti, tvb, offset, paddedDataSegmentLength);
} else if(opcode == ISCSI_OPCODE_LOGOUT_COMMAND) {
if(iscsi_protocol_version >= ISCSI_PROTOCOL_DRAFT13) {
proto_tree_add_item(ti, hf_iscsi_Logout_Reason, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
}
if(iscsi_protocol_version > ISCSI_PROTOCOL_DRAFT09) {
proto_tree_add_item(ti, hf_iscsi_TotalAHSLength, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(ti, hf_iscsi_DataSegmentLength, tvb, offset + 5, 3, tvb_get_ntoh24(tvb, offset + 5));
}
if(iscsi_protocol_version == ISCSI_PROTOCOL_DRAFT08) {
proto_tree_add_item(ti, hf_iscsi_CID, tvb, offset + 8, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_Logout_Reason, tvb, offset + 11, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_item(ti, hf_iscsi_InitiatorTaskTag, tvb, offset + 16, 4, ENC_BIG_ENDIAN);
if(iscsi_protocol_version > ISCSI_PROTOCOL_DRAFT08) {
proto_tree_add_item(ti, hf_iscsi_CID, tvb, offset + 20, 2, ENC_BIG_ENDIAN);
if(iscsi_protocol_version < ISCSI_PROTOCOL_DRAFT13) {
proto_tree_add_item(ti, hf_iscsi_Logout_Reason, tvb, offset + 23, 1, ENC_BIG_ENDIAN);
}
}
proto_tree_add_item(ti, hf_iscsi_CmdSN, tvb, offset + 24, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_ExpStatSN, tvb, offset + 28, 4, ENC_BIG_ENDIAN);
offset = handleHeaderDigest(iscsi_session, ti, tvb, offset, 48);
} else if(opcode == ISCSI_OPCODE_LOGOUT_RESPONSE) {
proto_tree_add_item(ti, hf_iscsi_Logout_Response, tvb, offset + 2, 1, ENC_BIG_ENDIAN);
if(iscsi_protocol_version > ISCSI_PROTOCOL_DRAFT09) {
proto_tree_add_item(ti, hf_iscsi_TotalAHSLength, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(ti, hf_iscsi_DataSegmentLength, tvb, offset + 5, 3, tvb_get_ntoh24(tvb, offset + 5));
}
proto_tree_add_item(ti, hf_iscsi_InitiatorTaskTag, tvb, offset + 16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_StatSN, tvb, offset + 24, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_ExpCmdSN, tvb, offset + 28, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_MaxCmdSN, tvb, offset + 32, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_Time2Wait, tvb, offset + 40, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_Time2Retain, tvb, offset + 42, 2, ENC_BIG_ENDIAN);
offset = handleHeaderDigest(iscsi_session, ti, tvb, offset, 48);
} else if(opcode == ISCSI_OPCODE_SNACK_REQUEST) {
{
#if 0
gint b = tvb_get_guint8(tvb, offset + 1);
proto_item *tf = proto_tree_add_uint(ti, hf_iscsi_Flags, tvb, offset + 1, 1, b);
proto_tree *tt = proto_item_add_subtree(tf, ett_iscsi_Flags);
#endif
proto_tree_add_item(ti, hf_iscsi_snack_type, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
}
if(iscsi_protocol_version > ISCSI_PROTOCOL_DRAFT09) {
proto_tree_add_item(ti, hf_iscsi_TotalAHSLength, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(ti, hf_iscsi_DataSegmentLength, tvb, offset + 5, 3, tvb_get_ntoh24(tvb, offset + 5));
dissect_scsi_lun(ti, tvb, offset + 8);
}
proto_tree_add_item(ti, hf_iscsi_InitiatorTaskTag, tvb, offset + 16, 4, ENC_BIG_ENDIAN);
if(iscsi_protocol_version <= ISCSI_PROTOCOL_DRAFT09) {
proto_tree_add_item(ti, hf_iscsi_BegRun, tvb, offset + 20, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_RunLength, tvb, offset + 24, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_ExpStatSN, tvb, offset + 28, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_ExpDataSN, tvb, offset + 36, 4, ENC_BIG_ENDIAN);
}
else {
proto_tree_add_item(ti, hf_iscsi_TargetTransferTag, tvb, offset + 20, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_ExpStatSN, tvb, offset + 28, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_BegRun, tvb, offset + 40, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_RunLength, tvb, offset + 44, 4, ENC_BIG_ENDIAN);
}
offset = handleHeaderDigest(iscsi_session, ti, tvb, offset, 48);
} else if(opcode == ISCSI_OPCODE_R2T) {
if(iscsi_protocol_version > ISCSI_PROTOCOL_DRAFT09) {
proto_tree_add_item(ti, hf_iscsi_TotalAHSLength, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(ti, hf_iscsi_DataSegmentLength, tvb, offset + 5, 3, tvb_get_ntoh24(tvb, offset + 5));
dissect_scsi_lun(ti, tvb, offset + 8);
}
proto_tree_add_item(ti, hf_iscsi_InitiatorTaskTag, tvb, offset + 16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_TargetTransferTag, tvb, offset + 20, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_StatSN, tvb, offset + 24, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_ExpCmdSN, tvb, offset + 28, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_MaxCmdSN, tvb, offset + 32, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_R2TSN, tvb, offset + 36, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_BufferOffset, tvb, offset + 40, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_DesiredDataLength, tvb, offset + 44, 4, ENC_BIG_ENDIAN);
offset = handleHeaderDigest(iscsi_session, ti, tvb, offset, 48);
} else if(opcode == ISCSI_OPCODE_ASYNC_MESSAGE) {
int dsl, snsl;
if(iscsi_protocol_version > ISCSI_PROTOCOL_DRAFT09) {
proto_tree_add_item(ti, hf_iscsi_TotalAHSLength, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
}
dsl=tvb_get_ntoh24(tvb, offset+5);
proto_tree_add_uint(ti, hf_iscsi_DataSegmentLength, tvb, offset + 5, 3, tvb_get_ntoh24(tvb, offset + 5));
dissect_scsi_lun(ti, tvb, offset + 8);
proto_tree_add_item(ti, hf_iscsi_StatSN, tvb, offset + 24, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_ExpCmdSN, tvb, offset + 28, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_MaxCmdSN, tvb, offset + 32, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_AsyncEvent, tvb, offset + 36, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_EventVendorCode, tvb, offset + 37, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_Parameter1, tvb, offset + 38, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_Parameter2, tvb, offset + 40, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_Parameter3, tvb, offset + 42, 2, ENC_BIG_ENDIAN);
offset = handleHeaderDigest(iscsi_session, ti, tvb, offset, 48);
if(dsl){
snsl=tvb_get_ntohs(tvb, offset);
offset+=2;
if(snsl){
tvbuff_t *data_tvb;
int tvb_len, tvb_rlen;
tvb_len=tvb_length_remaining(tvb, offset);
if(tvb_len>snsl)
tvb_len=snsl;
tvb_rlen=tvb_reported_length_remaining(tvb, offset);
if(tvb_rlen>snsl)
tvb_rlen=snsl;
data_tvb=tvb_new_subset(tvb, offset, tvb_len, tvb_rlen);
dissect_scsi_snsinfo (data_tvb, pinfo, tree, 0,
tvb_len,
&cdata->itlq, itl);
offset+=snsl;
}
if((end_offset-offset)>0){
proto_tree_add_item(ti, hf_iscsi_async_event_data, tvb, offset, end_offset-offset, ENC_NA);
}
}
offset=end_offset;
} else if(opcode == ISCSI_OPCODE_REJECT) {
proto_item *tf;
proto_tree *tt;
int next_opcode;
const char *next_opcode_str;
proto_tree_add_item(ti, hf_iscsi_Reject_Reason, tvb, offset + 2, 1, ENC_BIG_ENDIAN);
if(iscsi_protocol_version > ISCSI_PROTOCOL_DRAFT09) {
proto_tree_add_item(ti, hf_iscsi_TotalAHSLength, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_uint(ti, hf_iscsi_DataSegmentLength, tvb, offset + 5, 3, tvb_get_ntoh24(tvb, offset + 5));
proto_tree_add_item(ti, hf_iscsi_StatSN, tvb, offset + 24, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_ExpCmdSN, tvb, offset + 28, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_MaxCmdSN, tvb, offset + 32, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_iscsi_DataSN, tvb, offset + 36, 4, ENC_BIG_ENDIAN);
offset = handleHeaderDigest(iscsi_session, ti, tvb, offset, 48);
next_opcode = tvb_get_guint8(tvb, offset) & 0x3f;
next_opcode_str = try_val_to_str(next_opcode, iscsi_opcodes);
tf = proto_tree_add_text(ti, tvb, offset, -1, "Rejected Header");
tt = proto_item_add_subtree(tf, ett_iscsi_RejectHeader);
dissect_iscsi_pdu(tvb, pinfo, tt, offset, next_opcode, next_opcode_str, 0, iscsi_session, conversation);
} else if(opcode == ISCSI_OPCODE_VENDOR_SPECIFIC_I0 ||
opcode == ISCSI_OPCODE_VENDOR_SPECIFIC_I1 ||
opcode == ISCSI_OPCODE_VENDOR_SPECIFIC_I2 ||
opcode == ISCSI_OPCODE_VENDOR_SPECIFIC_T0 ||
opcode == ISCSI_OPCODE_VENDOR_SPECIFIC_T1 ||
opcode == ISCSI_OPCODE_VENDOR_SPECIFIC_T2) {
if(iscsi_protocol_version > ISCSI_PROTOCOL_DRAFT09) {
proto_tree_add_item(ti, hf_iscsi_TotalAHSLength, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_uint(ti, hf_iscsi_DataSegmentLength, tvb, offset + 5, 3, tvb_get_ntoh24(tvb, offset + 5));
offset = handleHeaderDigest(iscsi_session, ti, tvb, offset, 48);
offset = handleDataSegment(ti, tvb, offset, data_segment_len, end_offset, hf_iscsi_vendor_specific_data);
}
switch(opcode){
case ISCSI_OPCODE_SCSI_RESPONSE:
if (cdata->itlq.first_exchange_frame){
nstime_t delta_time;
proto_tree_add_uint(ti, hf_iscsi_request_frame, tvb, 0, 0, cdata->itlq.first_exchange_frame);
nstime_delta(&delta_time, &pinfo->fd->abs_ts, &cdata->itlq.fc_time);
proto_tree_add_time(ti, hf_iscsi_time, tvb, 0, 0, &delta_time);
}
if (cdata->data_in_frame)
proto_tree_add_uint(ti, hf_iscsi_data_in_frame, tvb, 0, 0, cdata->data_in_frame);
if (cdata->data_out_frame)
proto_tree_add_uint(ti, hf_iscsi_data_out_frame, tvb, 0, 0, cdata->data_out_frame);
break;
case ISCSI_OPCODE_SCSI_DATA_IN:
if(!S_bit){
if (cdata->itlq.first_exchange_frame)
proto_tree_add_uint(ti, hf_iscsi_request_frame, tvb, 0, 0, cdata->itlq.first_exchange_frame);
if (cdata->itlq.last_exchange_frame)
proto_tree_add_uint(ti, hf_iscsi_response_frame, tvb, 0, 0, cdata->itlq.last_exchange_frame);
} else {
if (cdata->itlq.first_exchange_frame){
nstime_t delta_time;
proto_tree_add_uint(ti, hf_iscsi_request_frame, tvb, 0, 0, cdata->itlq.first_exchange_frame);
nstime_delta(&delta_time, &pinfo->fd->abs_ts, &cdata->itlq.fc_time);
proto_tree_add_time(ti, hf_iscsi_time, tvb, 0, 0, &delta_time);
}
}
if (cdata->data_out_frame)
proto_tree_add_uint(ti, hf_iscsi_data_out_frame, tvb, 0, 0, cdata->data_out_frame);
break;
case ISCSI_OPCODE_SCSI_DATA_OUT:
if (cdata->itlq.first_exchange_frame)
proto_tree_add_uint(ti, hf_iscsi_request_frame, tvb, 0, 0, cdata->itlq.first_exchange_frame);
if (cdata->data_in_frame)
proto_tree_add_uint(ti, hf_iscsi_data_in_frame, tvb, 0, 0, cdata->data_in_frame);
if (cdata->itlq.last_exchange_frame)
proto_tree_add_uint(ti, hf_iscsi_response_frame, tvb, 0, 0, cdata->itlq.last_exchange_frame);
break;
case ISCSI_OPCODE_SCSI_COMMAND:
if (cdata->data_in_frame)
proto_tree_add_uint(ti, hf_iscsi_data_in_frame, tvb, 0, 0, cdata->data_in_frame);
if (cdata->data_out_frame)
proto_tree_add_uint(ti, hf_iscsi_data_out_frame, tvb, 0, 0, cdata->data_out_frame);
if (cdata->itlq.last_exchange_frame)
proto_tree_add_uint(ti, hf_iscsi_response_frame, tvb, 0, 0, cdata->itlq.last_exchange_frame);
break;
}
proto_item_set_len(ti, offset - original_offset);
if((opcode & ((iscsi_protocol_version == ISCSI_PROTOCOL_DRAFT08)?
~(X_BIT | I_BIT) :
~I_BIT)) == ISCSI_OPCODE_SCSI_COMMAND) {
tvbuff_t *cdb_tvb, *data_tvb;
int tvb_len, tvb_rlen;
tvb_len=tvb_length_remaining(tvb, cdb_offset);
tvb_rlen=tvb_reported_length_remaining(tvb, cdb_offset);
if(ahs_cdb_length && ahs_cdb_length<1024){
guint8 *cdb_buf;
cdb_buf=(guint8 *)wmem_alloc(pinfo->pool, 16+ahs_cdb_length);
tvb_memcpy(tvb, cdb_buf, cdb_offset, 16);
tvb_memcpy(tvb, cdb_buf+16, ahs_cdb_offset, ahs_cdb_length);
cdb_tvb = tvb_new_child_real_data(tvb, cdb_buf,
ahs_cdb_length+16,
ahs_cdb_length+16);
add_new_data_source(pinfo, cdb_tvb, "CDB+AHS");
} else {
if(tvb_len>16){
tvb_len=16;
}
if(tvb_rlen>16){
tvb_rlen=16;
}
cdb_tvb=tvb_new_subset(tvb, cdb_offset, tvb_len, tvb_rlen);
}
dissect_scsi_cdb(cdb_tvb, pinfo, tree, SCSI_DEV_UNKNOWN, &cdata->itlq, itl);
col_set_fence(pinfo->cinfo, COL_INFO);
if(immediate_data_length){
tvb_len=tvb_length_remaining(tvb, immediate_data_offset);
if(tvb_len>(int)immediate_data_length)
tvb_len=immediate_data_length;
tvb_rlen=tvb_reported_length_remaining(tvb, immediate_data_offset);
if(tvb_rlen>(int)immediate_data_length)
tvb_rlen=immediate_data_length;
data_tvb=tvb_new_subset(tvb, immediate_data_offset, tvb_len, tvb_rlen);
dissect_scsi_payload (data_tvb, pinfo, tree,
TRUE,
&cdata->itlq, itl,
0);
}
}
else if (opcode == ISCSI_OPCODE_SCSI_RESPONSE) {
if (scsi_status == 0x2) {
if((end_offset - offset) >= 2) {
int senseLen = tvb_get_ntohs(tvb, offset);
if(ti != NULL)
proto_tree_add_item(ti, hf_iscsi_SenseLength, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if(senseLen > 0){
tvbuff_t *data_tvb;
int tvb_len, tvb_rlen;
tvb_len=tvb_length_remaining(tvb, offset);
if(tvb_len>senseLen)
tvb_len=senseLen;
tvb_rlen=tvb_reported_length_remaining(tvb, offset);
if(tvb_rlen>senseLen)
tvb_rlen=senseLen;
data_tvb=tvb_new_subset(tvb, offset, tvb_len, tvb_rlen);
dissect_scsi_snsinfo (data_tvb, pinfo, tree, 0,
tvb_len,
&cdata->itlq, itl);
}
}
}
else {
dissect_scsi_rsp(tvb, pinfo, tree, &cdata->itlq, itl, scsi_status);
}
}
else if ((opcode == ISCSI_OPCODE_SCSI_DATA_IN) ||
(opcode == ISCSI_OPCODE_SCSI_DATA_OUT)) {
tvbuff_t *data_tvb;
int tvb_len, tvb_rlen;
tvb_len=tvb_length_remaining(tvb, offset);
if(tvb_len>(int)data_segment_len)
tvb_len=data_segment_len;
tvb_rlen=tvb_reported_length_remaining(tvb, offset);
if(tvb_rlen>(int)data_segment_len)
tvb_rlen=data_segment_len;
data_tvb=tvb_new_subset(tvb, offset, tvb_len, tvb_rlen);
dissect_scsi_payload (data_tvb, pinfo, tree,
(opcode==ISCSI_OPCODE_SCSI_DATA_OUT),
&cdata->itlq, itl,
data_offset);
}
if(S_bit){
dissect_scsi_rsp(tvb, pinfo, tree, &cdata->itlq, itl, scsi_status);
}
}
static gboolean
dissect_iscsi(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gboolean check_port) {
guint iSCSIPdusDissected = 0;
guint offset = 0;
guint32 available_bytes = tvb_length(tvb);
int digestsActive = 1;
conversation_t *conversation = NULL;
iscsi_session_t *iscsi_session=NULL;
guint8 opcode, tmpbyte;
if (available_bytes < 48) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return TRUE;
}
opcode = tvb_get_guint8(tvb, offset + 0);
opcode &= OPCODE_MASK;
switch(opcode){
case ISCSI_OPCODE_NOP_IN:
if(tvb_get_guint8(tvb, offset+0)&0xc0){
return FALSE;
}
if(tvb_get_guint8(tvb, offset+1)!=0x80){
return FALSE;
}
if(tvb_get_guint8(tvb, offset+2)||tvb_get_guint8(tvb, offset+3)){
return FALSE;
}
break;
case ISCSI_OPCODE_NOP_OUT:
if(tvb_get_guint8(tvb, offset+0)&0x80){
return FALSE;
}
if(tvb_get_guint8(tvb, offset+1)!=0x80){
return FALSE;
}
if(tvb_get_guint8(tvb, offset+2)||tvb_get_guint8(tvb, offset+3)){
return FALSE;
}
if(!tvb_get_letohl(tvb,offset+16) || !tvb_get_letohl(tvb,offset+20)){
return FALSE;
}
if(tvb_get_letohl(tvb,offset+32)
|| tvb_get_letohl(tvb,offset+36)
|| tvb_get_letohl(tvb,offset+40)
|| tvb_get_letohl(tvb,offset+44)){
return FALSE;
}
break;
case ISCSI_OPCODE_LOGIN_COMMAND:
if((tvb_get_guint8(tvb, offset+0)&0xc0)!=0x40){
return FALSE;
}
tmpbyte=tvb_get_guint8(tvb, offset+1);
switch(tmpbyte&0xf0){
case 0x80:
case 0x40:
case 0x00:
break;
default:
return FALSE;
}
if(((tmpbyte & 0x03) == 0x02)
|| ((tmpbyte & 0x0c) == 0x08)) {
return FALSE;
}
if(tmpbyte&0x80){
if(!(tmpbyte&0x03)){
return FALSE;
}
}
break;
case ISCSI_OPCODE_LOGIN_RESPONSE:
if(tvb_get_guint8(tvb, offset+0)&0xc0){
return FALSE;
}
tmpbyte=tvb_get_guint8(tvb, offset+1);
switch(tmpbyte&0xf0){
case 0x80:
case 0x40:
case 0x00:
break;
default:
return FALSE;
}
if(((tmpbyte & 0x03) == 0x02)
|| ((tmpbyte & 0x0c) == 0x08)) {
return FALSE;
}
if(tmpbyte&0x80){
if(!(tmpbyte&0x03)){
return FALSE;
}
}
if(tvb_get_letohl(tvb,offset+20)
|| tvb_get_letohl(tvb,offset+40)
|| tvb_get_letohl(tvb,offset+44)){
return FALSE;
}
if(tvb_get_letohs(tvb,offset+38)){
return FALSE;
}
break;
case ISCSI_OPCODE_TASK_MANAGEMENT_FUNCTION:
if(tvb_get_guint8(tvb, offset+0)&0x80){
return FALSE;
}
tmpbyte=tvb_get_guint8(tvb, offset+1);
if(!(tmpbyte&0x80)){
return FALSE;
}
if(!try_val_to_str(tmpbyte&0x7f, iscsi_task_management_functions)){
return FALSE;
}
if(tvb_get_letohs(tvb,offset+2)){
return FALSE;
}
if(tvb_get_letohl(tvb,offset+4)){
return FALSE;
}
break;
case ISCSI_OPCODE_TASK_MANAGEMENT_FUNCTION_RESPONSE:
if(tvb_get_guint8(tvb, offset+0)&0xc0){
return FALSE;
}
if(tvb_get_guint8(tvb, offset+1)!=0x80){
return FALSE;
}
tmpbyte=tvb_get_guint8(tvb,offset+2);
if(tmpbyte>6 && tmpbyte<255){
return FALSE;
}
if(tvb_get_guint8(tvb,offset+3)){
return FALSE;
}
if(tvb_get_letohl(tvb,offset+4)
|| tvb_get_letohl(tvb,offset+8)
|| tvb_get_letohl(tvb,offset+12)
|| tvb_get_letohl(tvb,offset+20)
|| tvb_get_letohl(tvb,offset+36)
|| tvb_get_letohl(tvb,offset+40)
|| tvb_get_letohl(tvb,offset+44)){
return FALSE;
}
break;
case ISCSI_OPCODE_LOGOUT_COMMAND:
if(tvb_get_guint8(tvb, offset+0)&0x80){
return FALSE;
}
tmpbyte=tvb_get_guint8(tvb, offset+1);
if(!(tmpbyte&0x80)){
return FALSE;
}
if(!try_val_to_str(tmpbyte&0x7f, iscsi_logout_reasons)){
return FALSE;
}
if(tvb_get_letohs(tvb,offset+2)){
return FALSE;
}
if(tvb_get_letohl(tvb,offset+4)
|| tvb_get_letohl(tvb,offset+8)
|| tvb_get_letohl(tvb,offset+12)
|| tvb_get_letohl(tvb,offset+32)
|| tvb_get_letohl(tvb,offset+36)
|| tvb_get_letohl(tvb,offset+40)
|| tvb_get_letohl(tvb,offset+44)){
return FALSE;
}
break;
case ISCSI_OPCODE_SNACK_REQUEST:
if(tvb_get_guint8(tvb, offset+0)&0xc0){
return FALSE;
}
tmpbyte=tvb_get_guint8(tvb, offset+1);
if((tmpbyte&0xf0)!=0x80){
return FALSE;
}
if(!try_val_to_str(tmpbyte&0x0f, iscsi_snack_types)){
return FALSE;
}
switch(tmpbyte&0x0f){
case 1:
case 2:
if(tvb_get_letohl(tvb,offset+16)!=0xffffffff){
return FALSE;
}
break;
case 3:
if(tvb_get_letohl(tvb,offset+20)==0xffffffff){
return FALSE;
}
if(tvb_get_letohl(tvb,offset+20)==0){
return FALSE;
}
break;
}
if(tvb_get_letohs(tvb,offset+2)){
return FALSE;
}
if(tvb_get_letohl(tvb,offset+24)
|| tvb_get_letohl(tvb,offset+32)
|| tvb_get_letohl(tvb,offset+36)){
return FALSE;
}
break;
case ISCSI_OPCODE_R2T:
if(tvb_get_guint8(tvb, offset+0)&0xc0){
return FALSE;
}
if(tvb_get_guint8(tvb, offset+1)!=0x80){
return FALSE;
}
if(tvb_get_letohs(tvb,offset+2)){
return FALSE;
}
if(tvb_get_letohl(tvb,offset+4)){
return FALSE;
}
if(!tvb_get_letohl(tvb,offset+44)){
return FALSE;
}
break;
case ISCSI_OPCODE_REJECT:
if(tvb_get_guint8(tvb, offset+0)&0xc0){
return FALSE;
}
if(tvb_get_guint8(tvb, offset+1)!=0x80){
return FALSE;
}
if(!try_val_to_str(tvb_get_guint8(tvb,offset+2), iscsi_reject_reasons)){
return FALSE;
}
if(tvb_get_guint8(tvb, offset+3)){
return FALSE;
}
if(tvb_get_letohl(tvb,offset+8)
|| tvb_get_letohl(tvb,offset+12)
|| tvb_get_letohl(tvb,offset+20)
|| tvb_get_letohl(tvb,offset+40)
|| tvb_get_letohl(tvb,offset+44)){
return FALSE;
}
if(tvb_get_letohl(tvb,offset+16)!=0xffffffff){
return FALSE;
}
break;
case ISCSI_OPCODE_TEXT_COMMAND:
if(tvb_get_guint8(tvb, offset+0)&0x80){
return FALSE;
}
switch(tvb_get_guint8(tvb,offset+1)){
case 0x80:
case 0x40:
break;
default:
return FALSE;
}
if(tvb_get_letohs(tvb,offset+2)){
return FALSE;
}
if(tvb_get_letohl(tvb,offset+32)
|| tvb_get_letohl(tvb,offset+36)
|| tvb_get_letohl(tvb,offset+40)
|| tvb_get_letohl(tvb,offset+44)){
return FALSE;
}
break;
case ISCSI_OPCODE_TEXT_RESPONSE:
if(tvb_get_guint8(tvb, offset+0)&0xc0){
return FALSE;
}
switch(tvb_get_guint8(tvb,offset+1)){
case 0x80:
case 0x40:
break;
default:
return FALSE;
}
if(tvb_get_letohs(tvb,offset+2)){
return FALSE;
}
if(tvb_get_letohl(tvb,offset+36)
|| tvb_get_letohl(tvb,offset+40)
|| tvb_get_letohl(tvb,offset+44)){
return FALSE;
}
break;
case ISCSI_OPCODE_SCSI_COMMAND:
if(tvb_get_guint8(tvb, offset+0)&0x80){
return FALSE;
}
if(tvb_get_guint8(tvb, offset+1)&0x18){
return FALSE;
}
if(tvb_get_letohs(tvb,offset+2)){
return FALSE;
}
if(tvb_get_ntoh48(tvb, offset+10)){
return FALSE;
}
if(tvb_get_guint8(tvb,offset+20)){
return FALSE;
}
break;
case ISCSI_OPCODE_SCSI_RESPONSE:
if(tvb_get_guint8(tvb, offset+0)&0xc0){
return FALSE;
}
tmpbyte=tvb_get_guint8(tvb,offset+1);
if(!(tmpbyte&0x80)){
return FALSE;
}
if(tmpbyte&0x61){
return FALSE;
}
if(!try_val_to_str(tvb_get_guint8(tvb,offset+3), scsi_status_val)){
return FALSE;
}
if(tvb_get_letohl(tvb,offset+8)
|| tvb_get_letohl(tvb,offset+12)){
return FALSE;
}
break;
case ISCSI_OPCODE_ASYNC_MESSAGE:
if(tvb_get_guint8(tvb, offset+0)&0xc0){
return FALSE;
}
if(tvb_get_guint8(tvb, offset+1)!=0x80){
return FALSE;
}
if(tvb_get_letohs(tvb,offset+2)){
return FALSE;
}
if(tvb_get_letohl(tvb,offset+20)
|| tvb_get_letohl(tvb,offset+44)){
return FALSE;
}
if(tvb_get_letohl(tvb,offset+16)!=0xffffffff){
return FALSE;
}
break;
case ISCSI_OPCODE_LOGOUT_RESPONSE:
if(tvb_get_guint8(tvb, offset+0)&0xc0){
return FALSE;
}
if(tvb_get_guint8(tvb, offset+1)!=0x80){
return FALSE;
}
if(!try_val_to_str(tvb_get_guint8(tvb,offset+2), iscsi_logout_response)){
return FALSE;
}
if(tvb_get_guint8(tvb,offset+3)){
return FALSE;
}
if(tvb_get_letohl(tvb,offset+4)
|| tvb_get_letohl(tvb,offset+8)
|| tvb_get_letohl(tvb,offset+12)
|| tvb_get_letohl(tvb,offset+20)
|| tvb_get_letohl(tvb,offset+36)
|| tvb_get_letohl(tvb,offset+44)){
return FALSE;
}
break;
case ISCSI_OPCODE_SCSI_DATA_OUT:
if(tvb_get_guint8(tvb, offset+0)&0xc0){
return FALSE;
}
if(tvb_get_guint8(tvb,offset+1)&0x7f){
return FALSE;
}
if(tvb_get_letohs(tvb,offset+2)){
return FALSE;
}
if(tvb_get_letohl(tvb,offset+24)
|| tvb_get_letohl(tvb,offset+32)
|| tvb_get_letohl(tvb,offset+44)){
return FALSE;
}
break;
case ISCSI_OPCODE_SCSI_DATA_IN:
if(tvb_get_guint8(tvb, offset+0)&0xc0){
return FALSE;
}
if(tvb_get_guint8(tvb,offset+1)&0x38){
return FALSE;
}
if(tvb_get_guint8(tvb,offset+2)){
return FALSE;
}
break;
case ISCSI_OPCODE_VENDOR_SPECIFIC_I0:
case ISCSI_OPCODE_VENDOR_SPECIFIC_I1:
case ISCSI_OPCODE_VENDOR_SPECIFIC_I2:
case ISCSI_OPCODE_VENDOR_SPECIFIC_T0:
case ISCSI_OPCODE_VENDOR_SPECIFIC_T1:
case ISCSI_OPCODE_VENDOR_SPECIFIC_T2:
break;
default:
return FALSE;
}
while(available_bytes >= 48 || (iscsi_desegment && available_bytes >= 8)) {
const char *opcode_str = NULL;
guint32 data_segment_len;
guint32 pduLen = 48;
guint8 secondPduByte = tvb_get_guint8(tvb, offset + 1);
int badPdu = FALSE;
guint8 ahsLen=0;
opcode = tvb_get_guint8(tvb, offset + 0);
opcode &= OPCODE_MASK;
opcode_str = try_val_to_str(opcode, iscsi_opcodes);
if(opcode == ISCSI_OPCODE_TASK_MANAGEMENT_FUNCTION ||
opcode == ISCSI_OPCODE_TASK_MANAGEMENT_FUNCTION_RESPONSE ||
opcode == ISCSI_OPCODE_R2T ||
opcode == ISCSI_OPCODE_LOGOUT_COMMAND ||
opcode == ISCSI_OPCODE_LOGOUT_RESPONSE ||
opcode == ISCSI_OPCODE_SNACK_REQUEST)
data_segment_len = 0;
else
data_segment_len = tvb_get_ntohl(tvb, offset + 4) & 0x00ffffff;
if(opcode_str == NULL) {
badPdu = TRUE;
}
if(!badPdu && check_port) {
badPdu = TRUE;
if ((opcode & TARGET_OPCODE_BIT) && value_is_in_range(global_iscsi_port_range, pinfo->srcport)) {
badPdu = FALSE;
}
if (!(opcode & TARGET_OPCODE_BIT) && value_is_in_range(global_iscsi_port_range, pinfo->destport)) {
badPdu = FALSE;
}
if ((opcode & TARGET_OPCODE_BIT) && pinfo->srcport == iscsi_system_port) {
badPdu = FALSE;
}
if (!(opcode & TARGET_OPCODE_BIT) && pinfo->destport == iscsi_system_port) {
badPdu = FALSE;
}
}
if(!badPdu && enable_bogosity_filter) {
if(data_segment_len > bogus_pdu_data_length_threshold) {
badPdu = TRUE;
}
else if(demand_good_f_bit &&
!(secondPduByte & 0x80) &&
(opcode == ISCSI_OPCODE_NOP_OUT ||
opcode == ISCSI_OPCODE_NOP_IN ||
opcode == ISCSI_OPCODE_LOGOUT_COMMAND ||
opcode == ISCSI_OPCODE_LOGOUT_RESPONSE ||
opcode == ISCSI_OPCODE_SCSI_RESPONSE ||
opcode == ISCSI_OPCODE_TASK_MANAGEMENT_FUNCTION_RESPONSE ||
opcode == ISCSI_OPCODE_R2T ||
opcode == ISCSI_OPCODE_ASYNC_MESSAGE ||
opcode == ISCSI_OPCODE_SNACK_REQUEST ||
opcode == ISCSI_OPCODE_REJECT)) {
badPdu = TRUE;
} else if(opcode==ISCSI_OPCODE_NOP_OUT) {
if(tvb_get_ntohl(tvb, offset+20)==0){
badPdu = TRUE;
}
}
}
if(badPdu) {
return iSCSIPdusDissected > 0;
}
if(opcode == ISCSI_OPCODE_LOGIN_COMMAND ||
opcode == ISCSI_OPCODE_LOGIN_RESPONSE) {
if(iscsi_protocol_version == ISCSI_PROTOCOL_DRAFT08) {
if((secondPduByte & CSG_MASK) < ISCSI_CSG_OPERATIONAL_NEGOTIATION) {
digestsActive = 0;
}
} else {
digestsActive = 0;
}
}
if(opcode == ISCSI_OPCODE_SCSI_COMMAND) {
ahsLen = tvb_get_guint8(tvb, offset + 4);
pduLen += ahsLen * 4;
}
pduLen += data_segment_len;
if((pduLen & 3) != 0)
pduLen += 4 - (pduLen & 3);
if(digestsActive && data_segment_len > 0 && enableDataDigests) {
if(dataDigestIsCRC32)
pduLen += 4;
else
pduLen += dataDigestSize;
}
conversation = find_or_create_conversation(pinfo);
iscsi_session=(iscsi_session_t *)conversation_get_proto_data(conversation, proto_iscsi);
if(!iscsi_session){
iscsi_session = wmem_new(wmem_file_scope(), iscsi_session_t);
iscsi_session->header_digest = ISCSI_HEADER_DIGEST_AUTO;
iscsi_session->itlq = wmem_tree_new(wmem_file_scope());
iscsi_session->itl = wmem_tree_new(wmem_file_scope());
conversation_add_proto_data(conversation, proto_iscsi, iscsi_session);
conversation_set_dissector(conversation, iscsi_handle);
}
if(digestsActive && (available_bytes>=(guint32) (48+4+ahsLen*4)) && (iscsi_session->header_digest==ISCSI_HEADER_DIGEST_AUTO) ){
guint32 crc;
crc= ~crc32c_calculate(tvb_get_ptr(tvb, offset, 48+ahsLen*4), 48+ahsLen*4, CRC32C_PRELOAD);
if(crc==tvb_get_ntohl(tvb,48+ahsLen*4)){
iscsi_session->header_digest=ISCSI_HEADER_DIGEST_CRC32;
} else {
iscsi_session->header_digest=ISCSI_HEADER_DIGEST_NONE;
}
}
if(digestsActive){
switch(iscsi_session->header_digest){
case ISCSI_HEADER_DIGEST_CRC32:
pduLen += 4;
break;
case ISCSI_HEADER_DIGEST_NONE:
break;
case ISCSI_HEADER_DIGEST_AUTO:
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
}
}
if(iscsi_desegment && pinfo->can_desegment) {
if(pduLen > available_bytes) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = pduLen - available_bytes;
return TRUE;
}
}
if(!pinfo->fd->flags.visited){
if(pduLen>(guint32)tvb_reported_length_remaining(tvb, offset)){
pinfo->want_pdu_tracking=2;
pinfo->bytes_until_next_pdu=pduLen-tvb_reported_length_remaining(tvb, offset);
}
}
if(iSCSIPdusDissected == 0)
col_set_str(pinfo->cinfo, COL_INFO, "");
else
col_append_str(pinfo->cinfo, COL_INFO, ", ");
dissect_iscsi_pdu(tvb, pinfo, tree, offset, opcode, opcode_str, data_segment_len, iscsi_session, conversation);
if(pduLen > available_bytes)
pduLen = available_bytes;
offset += pduLen;
available_bytes -= pduLen;
++iSCSIPdusDissected;
}
return iSCSIPdusDissected > 0;
}
static int
dissect_iscsi_handle(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_) {
return dissect_iscsi(tvb, pinfo, tree, FALSE);
}
static gboolean
dissect_iscsi_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_) {
guint32 available_bytes = tvb_length(tvb);
if (available_bytes < 48 ){
return FALSE;
}
return dissect_iscsi(tvb, pinfo, tree, TRUE);
}
void
proto_register_iscsi(void)
{
module_t *iscsi_module;
static hf_register_info hf[] = {
{ &hf_iscsi_request_frame,
{ "Request in", "iscsi.request_frame",
FT_FRAMENUM, BASE_NONE, NULL, 0,
"The request to this transaction is in this frame", HFILL }},
{ &hf_iscsi_time,
{ "Time from request", "iscsi.time",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0,
"Time between the Command and the Response", HFILL }},
{ &hf_iscsi_data_in_frame,
{ "Data In in", "iscsi.data_in_frame",
FT_FRAMENUM, BASE_NONE, NULL, 0,
"The Data In for this transaction is in this frame", HFILL }},
{ &hf_iscsi_data_out_frame,
{ "Data Out in", "iscsi.data_out_frame",
FT_FRAMENUM, BASE_NONE, NULL, 0,
"The Data Out for this transaction is in this frame", HFILL }},
{ &hf_iscsi_response_frame,
{ "Response in", "iscsi.response_frame",
FT_FRAMENUM, BASE_NONE, NULL, 0,
"The response to this transaction is in this frame", HFILL }},
{ &hf_iscsi_AHS_length,
{ "AHS Length", "iscsi.ahs.length",
FT_UINT16, BASE_DEC, NULL, 0,
"Length of Additional header segment", HFILL }
},
{ &hf_iscsi_AHS_read_data_length,
{ "Bidirectional Read Data Length", "iscsi.ahs.bidir.length",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_iscsi_AHS_type,
{ "AHS Type", "iscsi.ahs.type",
FT_UINT8, BASE_DEC, VALS(ahs_type_vals), 0,
"Type of Additional header segment", HFILL }
},
{ &hf_iscsi_AHS_extended_cdb,
{ "AHS Extended CDB", "iscsi.ahs.extended_cdb",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_iscsi_AHS_blob,
{ "Unknown AHS blob", "iscsi.ahs.unknown_blob",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_iscsi_Padding,
{ "Padding", "iscsi.padding",
FT_BYTES, BASE_NONE, NULL, 0,
"Padding to 4 byte boundary", HFILL }
},
{ &hf_iscsi_ping_data,
{ "PingData", "iscsi.pingdata",
FT_BYTES, BASE_NONE, NULL, 0,
"Ping Data", HFILL }
},
{ &hf_iscsi_immediate_data,
{ "ImmediateData", "iscsi.immediatedata",
FT_BYTES, BASE_NONE, NULL, 0,
"Immediate Data", HFILL }
},
{ &hf_iscsi_async_event_data,
{ "AsyncEventData", "iscsi.asynceventdata",
FT_BYTES, BASE_NONE, NULL, 0,
"Async Event Data", HFILL }
},
{ &hf_iscsi_vendor_specific_data,
{ "VendorSpecificData", "iscsi.vendorspecificdata",
FT_BYTES, BASE_NONE, NULL, 0,
"Vendor Specific Data", HFILL }
},
{ &hf_iscsi_HeaderDigest32,
{ "HeaderDigest", "iscsi.headerdigest32",
FT_UINT32, BASE_HEX, NULL, 0,
"Header Digest", HFILL }
},
{ &hf_iscsi_DataDigest,
{ "DataDigest", "iscsi.datadigest",
FT_BYTES, BASE_NONE, NULL, 0,
"Data Digest", HFILL }
},
{ &hf_iscsi_DataDigest32,
{ "DataDigest", "iscsi.datadigest32",
FT_UINT32, BASE_HEX, NULL, 0,
"Data Digest", HFILL }
},
{ &hf_iscsi_Opcode,
{ "Opcode", "iscsi.opcode",
FT_UINT8, BASE_HEX, VALS(iscsi_opcodes), 0,
NULL, HFILL }
},
{ &hf_iscsi_X,
{ "X", "iscsi.X",
FT_BOOLEAN, 8, TFS(&iscsi_meaning_X), 0x80,
"Command Retry", HFILL }
},
{ &hf_iscsi_I,
{ "I", "iscsi.I",
FT_BOOLEAN, 8, TFS(&iscsi_meaning_I), 0x40,
"Immediate delivery", HFILL }
},
{ &hf_iscsi_Flags,
{ "Flags", "iscsi.flags",
FT_UINT8, BASE_HEX, NULL, 0,
"Opcode specific flags", HFILL }
},
{ &hf_iscsi_SCSICommand_F,
{ "F", "iscsi.scsicommand.F",
FT_BOOLEAN, 8, TFS(&iscsi_meaning_F), 0x80,
"PDU completes command", HFILL }
},
{ &hf_iscsi_SCSICommand_R,
{ "R", "iscsi.scsicommand.R",
FT_BOOLEAN, 8, TFS(&iscsi_meaning_R), 0x40,
"Command reads from SCSI target", HFILL }
},
{ &hf_iscsi_SCSICommand_W,
{ "W", "iscsi.scsicommand.W",
FT_BOOLEAN, 8, TFS(&iscsi_meaning_W), 0x20,
"Command writes to SCSI target", HFILL }
},
{ &hf_iscsi_SCSICommand_Attr,
{ "Attr", "iscsi.scsicommand.attr",
FT_UINT8, BASE_HEX, VALS(iscsi_scsicommand_taskattrs), 0x07,
"SCSI task attributes", HFILL }
},
{ &hf_iscsi_SCSICommand_CRN,
{ "CRN", "iscsi.scsicommand.crn",
FT_UINT8, BASE_HEX, NULL, 0,
"SCSI command reference number", HFILL }
},
{ &hf_iscsi_DataSegmentLength,
{ "DataSegmentLength", "iscsi.datasegmentlength",
FT_UINT32, BASE_HEX, NULL, 0,
"Data segment length (bytes)", HFILL }
},
{ &hf_iscsi_TotalAHSLength,
{ "TotalAHSLength", "iscsi.totalahslength",
FT_UINT8, BASE_HEX, NULL, 0,
"Total additional header segment length (4 byte words)", HFILL }
},
{ &hf_iscsi_InitiatorTaskTag,
{ "InitiatorTaskTag", "iscsi.initiatortasktag",
FT_UINT32, BASE_HEX, NULL, 0,
"Initiator's task tag", HFILL }
},
{ &hf_iscsi_ExpectedDataTransferLength,
{ "ExpectedDataTransferLength", "iscsi.scsicommand.expecteddatatransferlength",
FT_UINT32, BASE_HEX, NULL, 0,
"Expected length of data transfer", HFILL }
},
{ &hf_iscsi_CmdSN,
{ "CmdSN", "iscsi.cmdsn",
FT_UINT32, BASE_HEX, NULL, 0,
"Sequence number for this command", HFILL }
},
{ &hf_iscsi_ExpStatSN,
{ "ExpStatSN", "iscsi.expstatsn",
FT_UINT32, BASE_HEX, NULL, 0,
"Next expected status sequence number", HFILL }
},
{ &hf_iscsi_SCSIResponse_ResidualCount,
{ "ResidualCount", "iscsi.scsiresponse.residualcount",
FT_UINT32, BASE_HEX, NULL, 0,
"Residual count", HFILL }
},
{ &hf_iscsi_StatSN,
{ "StatSN", "iscsi.statsn",
FT_UINT32, BASE_HEX, NULL, 0,
"Status sequence number", HFILL }
},
{ &hf_iscsi_ExpCmdSN,
{ "ExpCmdSN", "iscsi.expcmdsn",
FT_UINT32, BASE_HEX, NULL, 0,
"Next expected command sequence number", HFILL }
},
{ &hf_iscsi_MaxCmdSN,
{ "MaxCmdSN", "iscsi.maxcmdsn",
FT_UINT32, BASE_HEX, NULL, 0,
"Maximum acceptable command sequence number", HFILL }
},
{ &hf_iscsi_SCSIResponse_o,
{ "o", "iscsi.scsiresponse.o",
FT_BOOLEAN, 8, TFS(&iscsi_meaning_o), 0x10,
"Bi-directional read residual overflow", HFILL }
},
{ &hf_iscsi_SCSIResponse_u,
{ "u", "iscsi.scsiresponse.u",
FT_BOOLEAN, 8, TFS(&iscsi_meaning_u), 0x08,
"Bi-directional read residual underflow", HFILL }
},
{ &hf_iscsi_SCSIResponse_O,
{ "O", "iscsi.scsiresponse.O",
FT_BOOLEAN, 8, TFS(&iscsi_meaning_O), 0x04,
"Residual overflow", HFILL }
},
{ &hf_iscsi_SCSIResponse_U,
{ "U", "iscsi.scsiresponse.U",
FT_BOOLEAN, 8, TFS(&iscsi_meaning_U), 0x02,
"Residual underflow", HFILL }
},
{ &hf_iscsi_SCSIResponse_Status,
{ "Status", "iscsi.scsiresponse.status",
FT_UINT8, BASE_HEX, VALS(scsi_status_val), 0,
"SCSI command status value", HFILL }
},
{ &hf_iscsi_SCSIResponse_Response,
{ "Response", "iscsi.scsiresponse.response",
FT_UINT8, BASE_HEX, VALS(iscsi_scsi_responses), 0,
"SCSI command response value", HFILL }
},
{ &hf_iscsi_SCSIResponse_BidiReadResidualCount,
{ "BidiReadResidualCount", "iscsi.scsiresponse.bidireadresidualcount",
FT_UINT32, BASE_HEX, NULL, 0,
"Bi-directional read residual count", HFILL }
},
{ &hf_iscsi_SenseLength,
{ "SenseLength", "iscsi.scsiresponse.senselength",
FT_UINT16, BASE_HEX, NULL, 0,
"Sense data length", HFILL }
},
{ &hf_iscsi_SCSIData_F,
{ "F", "iscsi.scsidata.F",
FT_BOOLEAN, 8, TFS(&iscsi_meaning_F), ISCSI_SCSI_DATA_FLAG_F,
"Final PDU", HFILL }
},
{ &hf_iscsi_SCSIData_A,
{ "A", "iscsi.scsidata.A",
FT_BOOLEAN, 8, TFS(&iscsi_meaning_A), ISCSI_SCSI_DATA_FLAG_A,
"Acknowledge Requested", HFILL }
},
{ &hf_iscsi_SCSIData_S,
{ "S", "iscsi.scsidata.S",
FT_BOOLEAN, 8, TFS(&iscsi_meaning_S), ISCSI_SCSI_DATA_FLAG_S,
"PDU Contains SCSI command status", HFILL }
},
{ &hf_iscsi_SCSIData_U,
{ "U", "iscsi.scsidata.U",
FT_BOOLEAN, 8, TFS(&iscsi_meaning_U), ISCSI_SCSI_DATA_FLAG_U,
"Residual underflow", HFILL }
},
{ &hf_iscsi_SCSIData_O,
{ "O", "iscsi.scsidata.O",
FT_BOOLEAN, 8, TFS(&iscsi_meaning_O), ISCSI_SCSI_DATA_FLAG_O,
"Residual overflow", HFILL }
},
{ &hf_iscsi_TargetTransferTag,
{ "TargetTransferTag", "iscsi.targettransfertag",
FT_UINT32, BASE_HEX, NULL, 0,
"Target transfer tag", HFILL }
},
{ &hf_iscsi_BufferOffset,
{ "BufferOffset", "iscsi.bufferOffset",
FT_UINT32, BASE_HEX, NULL, 0,
"Buffer offset", HFILL }
},
{ &hf_iscsi_SCSIData_ResidualCount,
{ "ResidualCount", "iscsi.scsidata.readresidualcount",
FT_UINT32, BASE_HEX, NULL, 0,
"Residual count", HFILL }
},
{ &hf_iscsi_DataSN,
{ "DataSN", "iscsi.datasn",
FT_UINT32, BASE_HEX, NULL, 0,
"Data sequence number", HFILL }
},
{ &hf_iscsi_VersionMax,
{ "VersionMax", "iscsi.versionmax",
FT_UINT8, BASE_HEX, NULL, 0,
"Maximum supported protocol version", HFILL }
},
{ &hf_iscsi_VersionMin,
{ "VersionMin", "iscsi.versionmin",
FT_UINT8, BASE_HEX, NULL, 0,
"Minimum supported protocol version", HFILL }
},
{ &hf_iscsi_VersionActive,
{ "VersionActive", "iscsi.versionactive",
FT_UINT8, BASE_HEX, NULL, 0,
"Negotiated protocol version", HFILL }
},
{ &hf_iscsi_CID,
{ "CID", "iscsi.cid",
FT_UINT16, BASE_HEX, NULL, 0,
"Connection identifier", HFILL }
},
{ &hf_iscsi_ISID8,
{ "ISID", "iscsi.isid",
FT_UINT16, BASE_HEX, NULL, 0,
"Initiator part of session identifier", HFILL }
},
{ &hf_iscsi_ISID,
{ "ISID", "iscsi.isid",
FT_BYTES, BASE_NONE, NULL, 0,
"Initiator part of session identifier", HFILL }
},
{ &hf_iscsi_ISID_Type,
{ "ISID_Type", "iscsi.isid.type",
FT_UINT8, BASE_HEX, VALS(iscsi_isid_type), 0,
"Initiator part of session identifier - type", HFILL }
},
{ &hf_iscsi_ISID_NamingAuthority,
{ "ISID_NamingAuthority", "iscsi.isid.namingauthority",
FT_UINT24, BASE_HEX, NULL, 0,
"Initiator part of session identifier - naming authority", HFILL }
},
{ &hf_iscsi_ISID_Qualifier,
{ "ISID_Qualifier", "iscsi.isid.qualifier",
FT_UINT8, BASE_HEX, NULL, 0,
"Initiator part of session identifier - qualifier", HFILL }
},
{ &hf_iscsi_ISID_t,
{ "ISID_t", "iscsi.isid.t",
FT_UINT8, BASE_HEX, VALS(iscsi_isid_type), 0xc0,
"Initiator part of session identifier - t", HFILL }
},
{ &hf_iscsi_ISID_a,
{ "ISID_a", "iscsi.isid.a",
FT_UINT8, BASE_HEX, NULL, 0x3f,
"Initiator part of session identifier - a", HFILL }
},
{ &hf_iscsi_ISID_b,
{ "ISID_b", "iscsi.isid.b",
FT_UINT16, BASE_HEX, NULL, 0,
"Initiator part of session identifier - b", HFILL }
},
{ &hf_iscsi_ISID_c,
{ "ISID_c", "iscsi.isid.c",
FT_UINT8, BASE_HEX, NULL, 0,
"Initiator part of session identifier - c", HFILL }
},
{ &hf_iscsi_ISID_d,
{ "ISID_d", "iscsi.isid.d",
FT_UINT16, BASE_HEX, NULL, 0,
"Initiator part of session identifier - d", HFILL }
},
{ &hf_iscsi_TSID,
{ "TSID", "iscsi.tsid",
FT_UINT16, BASE_HEX, NULL, 0,
"Target part of session identifier", HFILL }
},
{ &hf_iscsi_TSIH,
{ "TSIH", "iscsi.tsih",
FT_UINT16, BASE_HEX, NULL, 0,
"Target session identifying handle", HFILL }
},
{ &hf_iscsi_Login_T,
{ "T", "iscsi.login.T",
FT_BOOLEAN, 8, TFS(&iscsi_meaning_T), 0x80,
"Transit to next login stage", HFILL }
},
{ &hf_iscsi_Login_C,
{ "C", "iscsi.login.C",
FT_BOOLEAN, 8, TFS(&iscsi_meaning_C), 0x40,
"Text incomplete", HFILL }
},
{ &hf_iscsi_Login_X,
{ "X", "iscsi.login.X",
FT_BOOLEAN, 8, TFS(&iscsi_meaning_login_X), 0x40,
"Restart Connection", HFILL }
},
{ &hf_iscsi_Login_CSG,
{ "CSG", "iscsi.login.csg",
FT_UINT8, BASE_HEX, VALS(iscsi_login_stage), CSG_MASK,
"Current stage", HFILL }
},
{ &hf_iscsi_Login_NSG,
{ "NSG", "iscsi.login.nsg",
FT_UINT8, BASE_HEX, VALS(iscsi_login_stage), NSG_MASK,
"Next stage", HFILL }
},
{ &hf_iscsi_Login_Status,
{ "Status", "iscsi.login.status",
FT_UINT16, BASE_HEX, VALS(iscsi_login_status), 0,
"Status class and detail", HFILL }
},
{ &hf_iscsi_KeyValue,
{ "KeyValue", "iscsi.keyvalue",
FT_STRING, BASE_NONE, NULL, 0,
"Key/value pair", HFILL }
},
{ &hf_iscsi_Text_F,
{ "F", "iscsi.text.F",
FT_BOOLEAN, 8, TFS(&iscsi_meaning_F), 0x80,
"Final PDU in text sequence", HFILL }
},
{ &hf_iscsi_Text_C,
{ "C", "iscsi.text.C",
FT_BOOLEAN, 8, TFS(&iscsi_meaning_C), 0x40,
"Text incomplete", HFILL }
},
{ &hf_iscsi_ExpDataSN,
{ "ExpDataSN", "iscsi.expdatasn",
FT_UINT32, BASE_HEX, NULL, 0,
"Next expected data sequence number", HFILL }
},
{ &hf_iscsi_R2TSN,
{ "R2TSN", "iscsi.r2tsn",
FT_UINT32, BASE_HEX, NULL, 0,
"R2T PDU Number", HFILL }
},
{ &hf_iscsi_TaskManagementFunction_Response,
{ "Response", "iscsi.taskmanfun.response",
FT_UINT8, BASE_HEX, VALS(iscsi_task_management_responses), 0,
NULL, HFILL }
},
{ &hf_iscsi_TaskManagementFunction_ReferencedTaskTag,
{ "ReferencedTaskTag", "iscsi.taskmanfun.referencedtasktag",
FT_UINT32, BASE_HEX, NULL, 0,
"Referenced task tag", HFILL }
},
{ &hf_iscsi_RefCmdSN,
{ "RefCmdSN", "iscsi.refcmdsn",
FT_UINT32, BASE_HEX, NULL, 0,
"Command sequence number for command to be aborted", HFILL }
},
{ &hf_iscsi_TaskManagementFunction_Function,
{ "Function", "iscsi.taskmanfun.function",
FT_UINT8, BASE_HEX, VALS(iscsi_task_management_functions), 0x7F,
"Requested task function", HFILL }
},
{ &hf_iscsi_Logout_Reason,
{ "Reason", "iscsi.logout.reason",
FT_UINT8, BASE_HEX, VALS(iscsi_logout_reasons), 0x7F,
"Reason for logout", HFILL }
},
{ &hf_iscsi_Logout_Response,
{ "Response", "iscsi.logout.response",
FT_UINT8, BASE_HEX, VALS(iscsi_logout_response), 0,
"Logout response", HFILL }
},
{ &hf_iscsi_Time2Wait,
{ "Time2Wait", "iscsi.time2wait",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_iscsi_Time2Retain,
{ "Time2Retain", "iscsi.time2retain",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_iscsi_DesiredDataLength,
{ "DesiredDataLength", "iscsi.desireddatalength",
FT_UINT32, BASE_HEX, NULL, 0,
"Desired data length (bytes)", HFILL }
},
{ &hf_iscsi_AsyncEvent,
{ "AsyncEvent", "iscsi.asyncevent",
FT_UINT8, BASE_HEX, VALS(iscsi_asyncevents), 0,
"Async event type", HFILL }
},
{ &hf_iscsi_EventVendorCode,
{ "EventVendorCode", "iscsi.eventvendorcode",
FT_UINT8, BASE_HEX, NULL, 0,
"Event vendor code", HFILL }
},
{ &hf_iscsi_Parameter1,
{ "Parameter1", "iscsi.parameter1",
FT_UINT16, BASE_HEX, NULL, 0,
"Parameter 1", HFILL }
},
{ &hf_iscsi_Parameter2,
{ "Parameter2", "iscsi.parameter2",
FT_UINT16, BASE_HEX, NULL, 0,
"Parameter 2", HFILL }
},
{ &hf_iscsi_Parameter3,
{ "Parameter3", "iscsi.parameter3",
FT_UINT16, BASE_HEX, NULL, 0,
"Parameter 3", HFILL }
},
{ &hf_iscsi_Reject_Reason,
{ "Reason", "iscsi.reject.reason",
FT_UINT8, BASE_HEX, VALS(iscsi_reject_reasons), 0,
"Reason for command rejection", HFILL }
},
{ &hf_iscsi_snack_type,
{ "S", "iscsi.snack.type",
FT_UINT8, BASE_DEC, VALS(iscsi_snack_types), 0x0f,
"Type of SNACK requested", HFILL }
},
{ &hf_iscsi_BegRun,
{ "BegRun", "iscsi.snack.begrun",
FT_UINT32, BASE_HEX, NULL, 0,
"First missed DataSN or StatSN", HFILL }
},
{ &hf_iscsi_RunLength,
{ "RunLength", "iscsi.snack.runlength",
FT_UINT32, BASE_HEX, NULL, 0,
"Number of additional missing status PDUs in this run", HFILL }
},
};
static gint *ett[] = {
&ett_iscsi,
&ett_iscsi_KeyValues,
&ett_iscsi_CDB,
&ett_iscsi_Flags,
&ett_iscsi_RejectHeader,
&ett_iscsi_lun,
&ett_iscsi_ISID,
};
proto_iscsi = proto_register_protocol("iSCSI", "iSCSI", "iscsi");
proto_register_field_array(proto_iscsi, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
iscsi_module = prefs_register_protocol(proto_iscsi, NULL);
prefs_register_enum_preference(iscsi_module,
"protocol_version",
"Protocol version",
"The iSCSI protocol version",
&iscsi_protocol_version,
iscsi_protocol_versions,
FALSE);
prefs_register_bool_preference(iscsi_module,
"desegment_iscsi_messages",
"Reassemble iSCSI messages\nspanning multiple TCP segments",
"Whether the iSCSI dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&iscsi_desegment);
prefs_register_bool_preference(iscsi_module,
"bogus_pdu_filter",
"Enable bogus pdu filter",
"When enabled, packets that appear bogus are ignored",
&enable_bogosity_filter);
prefs_register_bool_preference(iscsi_module,
"demand_good_f_bit",
"Ignore packets with bad F bit",
"Ignore packets that haven't set the F bit when they should have",
&demand_good_f_bit);
prefs_register_uint_preference(iscsi_module,
"bogus_pdu_max_data_len",
"Bogus pdu max data length threshold",
"Treat packets whose data segment length is greater than this value as bogus",
10,
&bogus_pdu_data_length_threshold);
range_convert_str(&global_iscsi_port_range, TCP_PORT_ISCSI_RANGE, MAX_TCP_PORT);
prefs_register_range_preference(iscsi_module,
"target_ports",
"Target Ports Range",
"Range of iSCSI target ports"
"(default " TCP_PORT_ISCSI_RANGE ")",
&global_iscsi_port_range, MAX_TCP_PORT);
prefs_register_uint_preference(iscsi_module,
"target_system_port",
"Target system port",
"System port number of iSCSI target",
10,
&iscsi_system_port);
prefs_register_bool_preference(iscsi_module,
"enable_data_digests",
"Enable data digests",
"When enabled, pdus are assumed to contain a data digest",
&enableDataDigests);
prefs_register_bool_preference(iscsi_module,
"data_digest_is_crc32c",
"Data digest is CRC32C",
"When enabled, data digests are assumed to be CRC32C",
&dataDigestIsCRC32);
prefs_register_uint_preference(iscsi_module,
"data_digest_size",
"Data digest size",
"The size of a data digest (bytes)",
10,
&dataDigestSize);
prefs_register_obsolete_preference(iscsi_module,
"version_03_compatible");
prefs_register_obsolete_preference(iscsi_module,
"bogus_pdu_max_digest_padding");
prefs_register_obsolete_preference(iscsi_module,
"header_digest_is_crc32c");
prefs_register_obsolete_preference(iscsi_module,
"header_digest_size");
prefs_register_obsolete_preference(iscsi_module,
"enable_header_digests");
}
void
proto_reg_handoff_iscsi(void)
{
heur_dissector_add("tcp", dissect_iscsi_heur, proto_iscsi);
iscsi_handle = new_create_dissector_handle(dissect_iscsi_handle, proto_iscsi);
dissector_add_handle("tcp.port", iscsi_handle);
}
