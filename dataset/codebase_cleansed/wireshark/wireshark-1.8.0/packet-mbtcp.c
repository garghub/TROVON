static int
classify_packet(packet_info *pinfo)
{
if (( pinfo->srcport == PORT_MBTCP ) && ( pinfo->destport != PORT_MBTCP ))
return RESPONSE_PACKET;
if (( pinfo->srcport != PORT_MBTCP ) && ( pinfo->destport == PORT_MBTCP ))
return QUERY_PACKET;
return CANNOT_CLASSIFY;
}
static void
dissect_mbtcp_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *mi;
proto_tree *mbtcp_tree;
int offset, packet_type;
tvbuff_t *next_tvb;
const char *func_string = "";
const char *pkt_type_str = "";
const char *err_str = "";
guint16 transaction_id, protocol_id, len;
guint8 unit_id, function_code, exception_code, subfunction_code;
void *p_save_proto_data;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Modbus/TCP");
col_clear(pinfo->cinfo, COL_INFO);
transaction_id = tvb_get_ntohs(tvb, 0);
protocol_id = tvb_get_ntohs(tvb, 2);
len = tvb_get_ntohs(tvb, 4);
unit_id = tvb_get_guint8(tvb, 6);
function_code = tvb_get_guint8(tvb, 7) & 0x7F;
offset = 0;
if (tvb_get_guint8(tvb, 7) & 0x80) {
exception_code = tvb_get_guint8(tvb, offset + 8);
}
else {
exception_code = 0;
}
if ((function_code == ENCAP_INTERFACE_TRANSP) && (exception_code == 0)) {
func_string = val_to_str(tvb_get_guint8(tvb, offset + 8), encap_interface_code_vals, "Encapsulated Interface Transport");
subfunction_code = 1;
}
else if ((function_code == DIAGNOSTICS) && (exception_code == 0)) {
func_string = val_to_str(tvb_get_ntohs(tvb, offset + 8), diagnostic_code_vals, "Diagnostics");
subfunction_code = 1;
}
else {
func_string = val_to_str(function_code, function_code_vals, "Unknown function (%d)");
subfunction_code = 0;
}
packet_type = classify_packet(pinfo);
if (check_col(pinfo->cinfo, COL_INFO))
{
switch ( packet_type ) {
case QUERY_PACKET :
pkt_type_str="query";
break;
case RESPONSE_PACKET :
pkt_type_str="response";
break;
case CANNOT_CLASSIFY :
err_str="Unable to classify as query or response.";
pkt_type_str="unknown";
break;
default :
break;
}
if ( exception_code != 0 )
err_str="Exception returned ";
if (subfunction_code == 0) {
if (strlen(err_str) > 0) {
col_add_fstr(pinfo->cinfo, COL_INFO,
"%8s: trans: %5u; unit: %3u, func: %3u: %s. %s",
pkt_type_str, transaction_id, unit_id,
function_code, func_string, err_str);
}
else {
col_add_fstr(pinfo->cinfo, COL_INFO,
"%8s: trans: %5u; unit: %3u, func: %3u: %s",
pkt_type_str, transaction_id, unit_id,
function_code, func_string);
}
}
else {
if (strlen(err_str) > 0) {
col_add_fstr(pinfo->cinfo, COL_INFO,
"%8s: trans: %5u; unit: %3u, func: %3u/%3u: %s. %s",
pkt_type_str, transaction_id, unit_id,
function_code, subfunction_code, func_string, err_str);
}
else {
col_add_fstr(pinfo->cinfo, COL_INFO,
"%8s: trans: %5u; unit: %3u, func: %3u/%3u: %s",
pkt_type_str, transaction_id, unit_id,
function_code, subfunction_code, func_string);
}
}
}
if (tree)
{
mi = proto_tree_add_protocol_format(tree, proto_mbtcp, tvb, offset,
len+6, "Modbus/TCP");
mbtcp_tree = proto_item_add_subtree(mi, ett_mbtcp);
proto_tree_add_uint(mbtcp_tree, hf_mbtcp_transid, tvb, offset, 2, transaction_id);
proto_tree_add_uint(mbtcp_tree, hf_mbtcp_protid, tvb, offset + 2, 2, protocol_id);
proto_tree_add_uint(mbtcp_tree, hf_mbtcp_len, tvb, offset + 4, 2, len);
proto_tree_add_uint(mbtcp_tree, hf_mbtcp_unitid, tvb, offset + 6, 1, unit_id);
next_tvb = tvb_new_subset( tvb, offset+7, len-1, len-1);
p_save_proto_data = p_get_proto_data( pinfo->fd, proto_mbtcp );
p_remove_proto_data(pinfo->fd, proto_mbtcp);
p_add_proto_data(pinfo->fd, proto_mbtcp, GINT_TO_POINTER(packet_type));
if( tvb_length_remaining(tvb, offset) > 0 )
call_dissector(modbus_handle, next_tvb, pinfo, tree);
p_remove_proto_data(pinfo->fd, proto_mbtcp);
p_add_proto_data(pinfo->fd, proto_mbtcp, p_save_proto_data);
}
}
static guint
get_mbtcp_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
guint16 plen;
plen = tvb_get_ntohs(tvb, offset + 4);
return plen + 6;
}
static int
dissect_mbtcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (!tvb_bytes_exist(tvb, 0, 8))
return 0;
if(tvb_get_ntohs(tvb, 2) != 0 ){
return 0;
}
if(tvb_get_ntohs(tvb, 4) < 2 ){
return 0;
}
tcp_dissect_pdus(tvb, pinfo, tree, mbtcp_desegment, 6,
get_mbtcp_pdu_len, dissect_mbtcp_pdu);
return tvb_length(tvb);
}
static int
dissect_mbudp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (!tvb_bytes_exist(tvb, 0, 8))
return 0;
if(tvb_get_ntohs(tvb, 2) != 0 ){
return 0;
}
if(tvb_get_ntohs(tvb, 4) < 2 ){
return 0;
}
dissect_mbtcp_pdu(tvb, pinfo, tree);
return tvb_length(tvb);
}
static void
dissect_mbtcp_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 function_code, gint payload_start, gint payload_len)
{
gint reported_len;
tvbuff_t *next_tvb;
reported_len = tvb_reported_length_remaining(tvb, payload_start);
if ( payload_start < 0 || ( payload_len + payload_start ) == 0 )
return;
if ( payload_len != reported_len ) {
proto_tree_add_bytes_format(tree, hf_modbus_data, tvb, payload_start, payload_len, NULL, "Data");
return;
}
next_tvb = tvb_new_subset(tvb, payload_start, payload_len, reported_len);
switch ( function_code ) {
default:
if ( ! dissector_try_string(mbtcp_dissector_table, "data", next_tvb, pinfo, tree) )
proto_tree_add_bytes_format(tree, hf_modbus_data, tvb, payload_start, payload_len, NULL, "Data");
break;
}
}
static int
dissect_modbus(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *modbus_tree, *group_tree, *event_tree,
*event_item_tree, *device_objects_tree,
*device_objects_item_tree;
proto_item *mi, *mf, *me, *mei, *doe, *doie;
int offset, group_offset, packet_type, temp_data;
const char *func_string = "";
gint payload_start, payload_len, event_index,
i, byte_cnt, len, num_objects, object_index,
object_len;
guint32 group_byte_cnt, group_word_cnt;
guint8 function_code, exception_code, mei_code, event_code, object_type;
guint16 diagnostic_code;
guint8 *object_str;
if (tree == NULL)
return tvb_length(tvb);
len = tvb_length_remaining(tvb, 0);
function_code = tvb_get_guint8(tvb, 0) & 0x7F;
if (tvb_get_guint8(tvb, 0) & 0x80 ) {
exception_code = tvb_get_guint8(tvb, 1);
}
else {
exception_code = 0;
}
packet_type = GPOINTER_TO_INT(p_get_proto_data( pinfo->fd, proto_mbtcp ));
offset = 0;
mf = proto_tree_add_text(tree, tvb, offset, len, "Modbus");
modbus_tree = proto_item_add_subtree(mf, ett_modbus_hdr);
mi = proto_tree_add_uint(modbus_tree, hf_mbtcp_functioncode, tvb, offset, 1,
function_code);
func_string = val_to_str(function_code, function_code_vals, "Unknown function");
payload_start = offset + 1;
payload_len = len - 1;
if (exception_code != 0) {
proto_item_set_text(mi, "function %u: %s. Exception: %s",
function_code,
func_string,
val_to_str(exception_code,
exception_code_vals,
"Unknown exception code (%u)"));
proto_tree_add_uint(modbus_tree, hf_modbus_exceptioncode, tvb, payload_start, 1,
exception_code);
}
else {
proto_item_set_text(mi, "function %u: %s", function_code,
func_string);
switch (function_code) {
case READ_COILS:
case READ_INPUT_DISCRETES:
if (packet_type == QUERY_PACKET) {
proto_tree_add_item(modbus_tree, hf_modbus_reference, tvb, payload_start, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(modbus_tree, hf_modbus_bitcnt, tvb, payload_start + 2, 2, ENC_BIG_ENDIAN);
}
else if (packet_type == RESPONSE_PACKET) {
byte_cnt = (guint32)tvb_get_guint8(tvb, payload_start);
proto_tree_add_uint(modbus_tree, hf_modbus_bytecnt, tvb, payload_start, 1, byte_cnt);
dissect_mbtcp_data(tvb, pinfo, modbus_tree, function_code, payload_start + 1, byte_cnt);
}
break;
case READ_MULT_REGS:
case READ_INPUT_REGS:
if (packet_type == QUERY_PACKET) {
proto_tree_add_item(modbus_tree, hf_modbus_reference, tvb, payload_start, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(modbus_tree, hf_modbus_wordcnt, tvb, payload_start + 2, 2, ENC_BIG_ENDIAN);
}
else if (packet_type == RESPONSE_PACKET) {
byte_cnt = (guint32)tvb_get_guint8(tvb, payload_start);
proto_tree_add_uint(modbus_tree, hf_modbus_bytecnt, tvb, payload_start, 1, byte_cnt);
dissect_mbtcp_data(tvb, pinfo, modbus_tree, function_code, payload_start + 1, byte_cnt);
}
break;
case WRITE_COIL:
if (packet_type == QUERY_PACKET) {
proto_tree_add_item(modbus_tree, hf_modbus_reference, tvb, payload_start, 2, ENC_BIG_ENDIAN);
dissect_mbtcp_data(tvb, pinfo, modbus_tree, function_code, payload_start + 2, 1);
proto_tree_add_text(modbus_tree, tvb, payload_start + 3, 1, "Padding");
}
else if (packet_type == RESPONSE_PACKET) {
proto_tree_add_item(modbus_tree, hf_modbus_reference, tvb, payload_start, 2, ENC_BIG_ENDIAN);
dissect_mbtcp_data(tvb, pinfo, modbus_tree, function_code, payload_start + 2, 1);
proto_tree_add_text(modbus_tree, tvb, payload_start + 3, 1, "Padding");
}
break;
case WRITE_SINGLE_REG:
if (packet_type == QUERY_PACKET) {
proto_tree_add_item(modbus_tree, hf_modbus_reference, tvb, payload_start, 2, ENC_BIG_ENDIAN);
dissect_mbtcp_data(tvb, pinfo, modbus_tree, function_code, payload_start + 2, 2);
}
else if (packet_type == RESPONSE_PACKET) {
proto_tree_add_item(modbus_tree, hf_modbus_reference, tvb, payload_start, 2, ENC_BIG_ENDIAN);
dissect_mbtcp_data(tvb, pinfo, modbus_tree, function_code, payload_start + 2, 2);
}
break;
case READ_EXCEPT_STAT:
if (packet_type == RESPONSE_PACKET)
dissect_mbtcp_data(tvb, pinfo, modbus_tree, function_code, payload_start, 1);
break;
case DIAGNOSTICS:
if ((packet_type == QUERY_PACKET) || (packet_type == RESPONSE_PACKET)) {
diagnostic_code = tvb_get_ntohs(tvb, payload_start);
proto_tree_add_uint(modbus_tree, hf_modbus_diag_sf, tvb, payload_start, 2, diagnostic_code);
switch(diagnostic_code)
{
case RETURN_QUERY_DATA:
if (packet_type == QUERY_PACKET) {
if (payload_len > 2)
proto_tree_add_text(modbus_tree, tvb, payload_start+2, payload_len-2, "Request Data");
}
else if (packet_type == RESPONSE_PACKET) {
if (payload_len > 2)
proto_tree_add_text(modbus_tree, tvb, payload_start+2, payload_len-2, "Echo Data");
}
break;
case RESTART_COMMUNICATION_OPTION:
temp_data = tvb_get_ntohs(tvb, payload_start+2);
if (temp_data == 0) {
proto_tree_add_text(modbus_tree, tvb, payload_start+2, 2, "Leave Log");
}
else if (temp_data == 0xFF) {
proto_tree_add_text(modbus_tree, tvb, payload_start+2, 2, "Clear Log");
}
else {
proto_tree_add_text(modbus_tree, tvb, payload_start+2, 2, "Unknown");
}
break;
case RETURN_DIAGNOSTIC_REGISTER:
if (packet_type == QUERY_PACKET) {
if (payload_len > 2)
dissect_mbtcp_data(tvb, pinfo, modbus_tree, function_code, payload_start+2, payload_len-2);
}
else if (packet_type == RESPONSE_PACKET) {
temp_data = tvb_get_ntohs(tvb, payload_start+2);
proto_tree_add_text( modbus_tree, tvb, payload_start+2, 2, "Diagnostic Register Contents 0x%04x", temp_data );
}
break;
case CHANGE_ASCII_INPUT_DELIMITER:
temp_data = tvb_get_guint8(tvb, payload_start+2);
proto_tree_add_text( modbus_tree, tvb, payload_start+2, 1, "CHAR 0x%02x", temp_data );
break;
case RETURN_BUS_MESSAGE_COUNT:
if (packet_type == QUERY_PACKET) {
if (payload_len > 2)
dissect_mbtcp_data(tvb, pinfo, modbus_tree, function_code, payload_start+2, payload_len-2);
}
else if (packet_type == RESPONSE_PACKET) {
temp_data = tvb_get_ntohs(tvb, payload_start+2);
proto_tree_add_text( modbus_tree, tvb, payload_start+2, 2, "Total Message Count %d", temp_data );
}
break;
case RETURN_BUS_COMM_ERROR_COUNT:
if (packet_type == QUERY_PACKET) {
if (payload_len > 2)
dissect_mbtcp_data(tvb, pinfo, modbus_tree, function_code, payload_start+2, payload_len-2);
}
else if (packet_type == RESPONSE_PACKET) {
temp_data = tvb_get_ntohs(tvb, payload_start+2);
proto_tree_add_text( modbus_tree, tvb, payload_start+2, 2, "CRC Error Count %d", temp_data );
}
break;
case RETURN_BUS_EXCEPTION_ERROR_COUNT:
if (packet_type == QUERY_PACKET) {
if (payload_len > 2)
dissect_mbtcp_data(tvb, pinfo, modbus_tree, function_code, payload_start+2, payload_len-2);
}
else if (packet_type == RESPONSE_PACKET) {
temp_data = tvb_get_ntohs(tvb, payload_start+2);
proto_tree_add_text( modbus_tree, tvb, payload_start+2, 2, "Exception Error Count %d", temp_data );
}
break;
case RETURN_SLAVE_MESSAGE_COUNT:
if (packet_type == QUERY_PACKET) {
if (payload_len > 2)
dissect_mbtcp_data(tvb, pinfo, modbus_tree, function_code, payload_start+2, payload_len-2);
}
else if (packet_type == RESPONSE_PACKET) {
temp_data = tvb_get_ntohs(tvb, payload_start+2);
proto_tree_add_text( modbus_tree, tvb, payload_start+2, 2, "Slave Message Count %d", temp_data );
}
break;
case RETURN_SLAVE_NO_RESPONSE_COUNT:
if (packet_type == QUERY_PACKET) {
if (payload_len > 2)
dissect_mbtcp_data(tvb, pinfo, modbus_tree, function_code, payload_start+2, payload_len-2);
}
else if (packet_type == RESPONSE_PACKET) {
temp_data = tvb_get_ntohs(tvb, payload_start+2);
proto_tree_add_text( modbus_tree, tvb, payload_start+2, 2, "Slave No Response Count %d", temp_data );
}
break;
case RETURN_SLAVE_NAK_COUNT:
if (packet_type == QUERY_PACKET) {
if (payload_len > 2)
dissect_mbtcp_data(tvb, pinfo, modbus_tree, function_code, payload_start+2, payload_len-2);
}
else if (packet_type == RESPONSE_PACKET) {
temp_data = tvb_get_ntohs(tvb, payload_start+2);
proto_tree_add_text( modbus_tree, tvb, payload_start+2, 2, "Slave NAK Count %d", temp_data );
}
break;
case RETURN_SLAVE_BUSY_COUNT:
if (packet_type == QUERY_PACKET) {
if (payload_len > 2)
dissect_mbtcp_data(tvb, pinfo, modbus_tree, function_code, payload_start+2, payload_len-2);
}
else if (packet_type == RESPONSE_PACKET) {
temp_data = tvb_get_ntohs(tvb, payload_start+2);
proto_tree_add_text( modbus_tree, tvb, payload_start+2, 2, "Slave Device Busy Count %d", temp_data );
}
break;
case RETURN_BUS_CHAR_OVERRUN_COUNT:
if (packet_type == QUERY_PACKET) {
if (payload_len > 2)
dissect_mbtcp_data(tvb, pinfo, modbus_tree, function_code, payload_start+2, payload_len-2);
}
else if (packet_type == RESPONSE_PACKET) {
temp_data = tvb_get_ntohs(tvb, payload_start+2);
proto_tree_add_text( modbus_tree, tvb, payload_start+2, 2, "Slave Character Overrun Count %d", temp_data );
}
break;
case CLEAR_OVERRUN_COUNTER_AND_FLAG:
case FORCE_LISTEN_ONLY_MODE:
case CLEAR_COUNTERS_AND_DIAG_REG:
default:
if (payload_len > 2)
dissect_mbtcp_data(tvb, pinfo, modbus_tree, function_code, payload_start+2, payload_len-2);
break;
}
}
break;
case GET_COMM_EVENT_CTRS:
if (packet_type == RESPONSE_PACKET) {
proto_tree_add_item(modbus_tree, hf_modbus_status, tvb, payload_start, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(modbus_tree, hf_modbus_event_count, tvb, payload_start+2, 2, ENC_BIG_ENDIAN);
}
break;
case GET_COMM_EVENT_LOG:
if (packet_type == RESPONSE_PACKET) {
byte_cnt = (guint32)tvb_get_guint8(tvb, payload_start);
proto_tree_add_uint(modbus_tree, hf_modbus_bytecnt, tvb, payload_start, 1, byte_cnt);
proto_tree_add_item(modbus_tree, hf_modbus_status, tvb, payload_start+1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(modbus_tree, hf_modbus_event_count, tvb, payload_start+3, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(modbus_tree, hf_modbus_message_count, tvb, payload_start+5, 2, ENC_BIG_ENDIAN);
if (byte_cnt-6 > 0) {
byte_cnt -= 6;
event_index = 0;
me = proto_tree_add_text(modbus_tree, tvb, payload_start+7, byte_cnt, "Events");
event_tree = proto_item_add_subtree(me, ett_events);
while (byte_cnt > 0) {
event_code = tvb_get_guint8(tvb, payload_start+7+event_index);
if (event_code == 0) {
proto_tree_add_text(event_tree, tvb, payload_start+7+event_index, 1, "Initiated Communication Restart");
}
else if (event_code == 4) {
proto_tree_add_text(event_tree, tvb, payload_start+7+event_index, 1, "Entered Listen Only Mode");
}
else if (event_code & REMOTE_DEVICE_RECV_EVENT_MASK) {
mei = proto_tree_add_text(event_tree, tvb, payload_start+7+event_index, 1, "Receive Event: 0x%02X", event_code);
event_item_tree = proto_item_add_subtree(mei, ett_events_recv);
proto_tree_add_item(event_item_tree, hf_modbus_event_recv_comm_err,
tvb, payload_start+7+event_index, 1, ENC_LITTLE_ENDIAN );
proto_tree_add_item(event_item_tree, hf_modbus_event_recv_char_over,
tvb, payload_start+7+event_index, 1, ENC_LITTLE_ENDIAN );
proto_tree_add_item(event_item_tree, hf_modbus_event_recv_lo_mode,
tvb, payload_start+7+event_index, 1, ENC_LITTLE_ENDIAN );
proto_tree_add_item(event_item_tree, hf_modbus_event_recv_broadcast,
tvb, payload_start+7+event_index, 1, ENC_LITTLE_ENDIAN );
}
else if ((event_code & REMOTE_DEVICE_SEND_EVENT_MASK) == REMOTE_DEVICE_SEND_EVENT_VALUE) {
mei = proto_tree_add_text(event_tree, tvb, payload_start+7+event_index, 1, "Send Event: 0x%02X", event_code);
event_item_tree = proto_item_add_subtree(mei, ett_events_send);
proto_tree_add_item(event_item_tree, hf_modbus_event_send_read_ex,
tvb, payload_start+7+event_index, 1, ENC_LITTLE_ENDIAN );
proto_tree_add_item(event_item_tree, hf_modbus_event_send_slave_abort_ex,
tvb, payload_start+7+event_index, 1, ENC_LITTLE_ENDIAN );
proto_tree_add_item(event_item_tree, hf_modbus_event_send_slave_busy_ex,
tvb, payload_start+7+event_index, 1, ENC_LITTLE_ENDIAN );
proto_tree_add_item(event_item_tree, hf_modbus_event_send_slave_nak_ex,
tvb, payload_start+7+event_index, 1, ENC_LITTLE_ENDIAN );
proto_tree_add_item(event_item_tree, hf_modbus_event_send_write_timeout,
tvb, payload_start+7+event_index, 1, ENC_LITTLE_ENDIAN );
proto_tree_add_item(event_item_tree, hf_modbus_event_send_lo_mode,
tvb, payload_start+7+event_index, 1, ENC_LITTLE_ENDIAN );
}
else {
proto_tree_add_text(event_tree, tvb, payload_start+7+event_index, 1, "Unknown Event");
}
byte_cnt--;
event_index++;
}
}
}
break;
case WRITE_MULT_COILS:
if (packet_type == QUERY_PACKET) {
proto_tree_add_item(modbus_tree, hf_modbus_reference, tvb, payload_start, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(modbus_tree, hf_modbus_bitcnt, tvb, payload_start + 2, 2, ENC_BIG_ENDIAN);
byte_cnt = (guint32)tvb_get_guint8(tvb, payload_start + 4);
proto_tree_add_uint(modbus_tree, hf_modbus_bytecnt, tvb, payload_start + 4, 1,
byte_cnt);
dissect_mbtcp_data(tvb, pinfo, modbus_tree, function_code, payload_start + 5, byte_cnt);
}
else if (packet_type == RESPONSE_PACKET) {
proto_tree_add_item(modbus_tree, hf_modbus_reference, tvb, payload_start, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(modbus_tree, hf_modbus_bitcnt, tvb, payload_start + 2, 2, ENC_BIG_ENDIAN);
}
break;
case WRITE_MULT_REGS:
if (packet_type == QUERY_PACKET) {
proto_tree_add_item(modbus_tree, hf_modbus_reference, tvb, payload_start, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(modbus_tree, hf_modbus_wordcnt, tvb, payload_start + 2, 2, ENC_BIG_ENDIAN);
byte_cnt = (guint32)tvb_get_guint8(tvb, payload_start + 4);
proto_tree_add_uint(modbus_tree, hf_modbus_bytecnt, tvb, payload_start + 4, 1,
byte_cnt);
dissect_mbtcp_data(tvb, pinfo, modbus_tree, function_code, payload_start + 5, byte_cnt);
}
else if (packet_type == RESPONSE_PACKET) {
proto_tree_add_item(modbus_tree, hf_modbus_reference, tvb, payload_start, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(modbus_tree, hf_modbus_wordcnt, tvb, payload_start + 2, 2, ENC_BIG_ENDIAN);
}
break;
case READ_FILE_RECORD:
if (packet_type == QUERY_PACKET) {
byte_cnt = (guint32)tvb_get_guint8(tvb, payload_start);
proto_tree_add_uint(modbus_tree, hf_modbus_bytecnt, tvb, payload_start, 1,
byte_cnt);
group_offset = payload_start + 1;
for (i = 0; i < byte_cnt / 7; i++) {
mi = proto_tree_add_text( modbus_tree, tvb, group_offset, 7,
"Group %u", i);
group_tree = proto_item_add_subtree(mi, ett_group_hdr);
proto_tree_add_item(group_tree, hf_modbus_reftype, tvb, group_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(group_tree, hf_modbus_lreference, tvb, group_offset + 1, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(group_tree, hf_modbus_wordcnt, tvb, group_offset + 5, 2, ENC_BIG_ENDIAN);
group_offset += 7;
}
}
else if (packet_type == RESPONSE_PACKET) {
byte_cnt = (guint32)tvb_get_guint8(tvb, payload_start);
proto_tree_add_uint(modbus_tree, hf_modbus_bytecnt, tvb, payload_start, 1,
byte_cnt);
group_offset = payload_start + 1;
i = 0;
while (byte_cnt > 0) {
group_byte_cnt = (guint32)tvb_get_guint8(tvb, group_offset);
mi = proto_tree_add_text( modbus_tree, tvb, group_offset, group_byte_cnt + 1,
"Group %u", i);
group_tree = proto_item_add_subtree(mi, ett_group_hdr);
proto_tree_add_uint(group_tree, hf_modbus_bytecnt, tvb, group_offset, 1,
group_byte_cnt);
proto_tree_add_item(group_tree, hf_modbus_reftype, tvb, group_offset + 1, 1, ENC_BIG_ENDIAN);
dissect_mbtcp_data(tvb, pinfo, group_tree, function_code, group_offset + 2, group_byte_cnt - 1);
group_offset += (group_byte_cnt + 1);
byte_cnt -= (group_byte_cnt + 1);
i++;
}
}
break;
case WRITE_FILE_RECORD:
if ((packet_type == QUERY_PACKET) || (packet_type == RESPONSE_PACKET)) {
byte_cnt = (guint32)tvb_get_guint8(tvb, payload_start);
proto_tree_add_uint(modbus_tree, hf_modbus_bytecnt, tvb, payload_start, 1,
byte_cnt);
group_offset = payload_start + 1;
i = 0;
while (byte_cnt > 0) {
group_word_cnt = tvb_get_ntohs(tvb, group_offset + 5);
group_byte_cnt = (2 * group_word_cnt) + 7;
mi = proto_tree_add_text( modbus_tree, tvb, group_offset,
group_byte_cnt, "Group %u", i);
group_tree = proto_item_add_subtree(mi, ett_group_hdr);
proto_tree_add_item(group_tree, hf_modbus_reftype, tvb, group_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(group_tree, hf_modbus_lreference, tvb, group_offset + 1, 4, ENC_BIG_ENDIAN);
proto_tree_add_uint(group_tree, hf_modbus_wordcnt, tvb, group_offset + 5, 2,
group_word_cnt);
dissect_mbtcp_data(tvb, pinfo, group_tree, function_code, group_offset + 7, group_byte_cnt - 7);
group_offset += group_byte_cnt;
byte_cnt -= group_byte_cnt;
i++;
}
}
break;
case MASK_WRITE_REG:
if ((packet_type == QUERY_PACKET) || (packet_type == RESPONSE_PACKET)) {
proto_tree_add_item(modbus_tree, hf_modbus_reference, tvb, payload_start, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(modbus_tree, hf_modbus_andmask, tvb, payload_start + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(modbus_tree, hf_modbus_ormask, tvb, payload_start + 4, 2, ENC_BIG_ENDIAN);
}
break;
case READ_WRITE_REG:
if (packet_type == QUERY_PACKET) {
proto_tree_add_item(modbus_tree, hf_modbus_readref, tvb, payload_start, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(modbus_tree, hf_modbus_readwordcnt, tvb, payload_start + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(modbus_tree, hf_modbus_writeref, tvb, payload_start + 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(modbus_tree, hf_modbus_writewordcnt, tvb, payload_start + 6, 2, ENC_BIG_ENDIAN);
byte_cnt = (guint32)tvb_get_guint8(tvb, payload_start + 8);
proto_tree_add_uint(modbus_tree, hf_modbus_bytecnt, tvb, payload_start + 8, 1,
byte_cnt);
dissect_mbtcp_data(tvb, pinfo, modbus_tree, function_code, payload_start + 9, byte_cnt);
}
else if (packet_type == RESPONSE_PACKET) {
byte_cnt = (guint32)tvb_get_guint8(tvb, payload_start);
proto_tree_add_uint(modbus_tree, hf_modbus_bytecnt, tvb, payload_start, 1,
byte_cnt);
dissect_mbtcp_data(tvb, pinfo, modbus_tree, function_code, payload_start + 1, byte_cnt);
}
break;
case READ_FIFO_QUEUE:
if (packet_type == QUERY_PACKET)
proto_tree_add_item(modbus_tree, hf_modbus_reference, tvb, payload_start, 2, ENC_BIG_ENDIAN);
else if (packet_type == RESPONSE_PACKET) {
byte_cnt = (guint32)tvb_get_ntohs(tvb, payload_start);
proto_tree_add_uint(modbus_tree, hf_modbus_lbytecnt, tvb, payload_start, 2,
byte_cnt);
proto_tree_add_item(modbus_tree, hf_modbus_wordcnt, tvb, payload_start + 2, 2, ENC_BIG_ENDIAN);
dissect_mbtcp_data(tvb, pinfo, modbus_tree, function_code, payload_start + 4, byte_cnt - 2);
}
break;
case ENCAP_INTERFACE_TRANSP:
if (packet_type == QUERY_PACKET) {
proto_tree_add_item(modbus_tree, hf_modbus_mei, tvb, payload_start, 1, ENC_BIG_ENDIAN);
mei_code = tvb_get_guint8(tvb, payload_start);
switch (mei_code)
{
case READ_DEVICE_ID:
proto_tree_add_item(modbus_tree, hf_modbus_read_device_id, tvb, payload_start+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(modbus_tree, hf_modbus_object_id, tvb, payload_start+2, 1, ENC_BIG_ENDIAN);
break;
case CANOPEN_REQ_RESP:
default:
if (payload_len > 1)
dissect_mbtcp_data(tvb, pinfo, modbus_tree, function_code, payload_start, payload_len-1);
break;
}
}
else if (packet_type == RESPONSE_PACKET) {
proto_tree_add_item(modbus_tree, hf_modbus_mei, tvb, payload_start, 1, ENC_BIG_ENDIAN);
mei_code = tvb_get_guint8(tvb, payload_start);
switch (mei_code)
{
case READ_DEVICE_ID:
proto_tree_add_item(modbus_tree, hf_modbus_read_device_id, tvb, payload_start+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(modbus_tree, hf_modbus_conformity_level, tvb, payload_start+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(modbus_tree, hf_modbus_more_follows, tvb, payload_start+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(modbus_tree, hf_modbus_next_object_id, tvb, payload_start+4, 1, ENC_BIG_ENDIAN);
num_objects = tvb_get_guint8(tvb, payload_start+5);
proto_tree_add_uint(modbus_tree, hf_modbus_num_objects, tvb, payload_start+5, 1, num_objects);
doe = proto_tree_add_text(modbus_tree, tvb, payload_start+6, payload_len-6, "Objects");
object_index = 0;
for (i = 1; i <= num_objects; i++)
{
device_objects_tree = proto_item_add_subtree(doe, ett_device_id_objects);
object_type = tvb_get_guint8(tvb, payload_start+6+object_index);
object_len = tvb_get_guint8(tvb, payload_start+6+object_index+1);
doie = proto_tree_add_text(device_objects_tree, tvb, payload_start+6+object_index, 2+object_len, "Object #%d", i);
device_objects_item_tree = proto_item_add_subtree(doie, ett_device_id_object_items);
proto_tree_add_item(device_objects_item_tree, hf_modbus_object_id, tvb, payload_start+6+object_index, 1, ENC_BIG_ENDIAN);
object_index++;
proto_tree_add_uint(device_objects_item_tree, hf_modbus_list_object_len, tvb, payload_start+6+object_index, 1, object_len);
object_index++;
if (object_type < 7)
{
object_str = tvb_get_string(tvb, payload_start+6+object_index, object_len);
proto_tree_add_string(device_objects_item_tree, hf_modbus_object_str_value, tvb, payload_start+6+object_index, object_len, object_str);
g_free(object_str);
}
else
{
if (object_len > 0)
proto_tree_add_text(device_objects_item_tree, tvb, payload_start+6+object_index, object_len, "Object Value");
}
object_index += object_len;
}
break;
case CANOPEN_REQ_RESP:
default:
if (payload_len > 1)
dissect_mbtcp_data(tvb, pinfo, modbus_tree, function_code, payload_start, payload_len-1);
break;
}
}
break;
case REPORT_SLAVE_ID:
default:
if (payload_len > 0)
dissect_mbtcp_data(tvb, pinfo, modbus_tree, function_code, payload_start, payload_len);
break;
}
}
return tvb_length(tvb);
}
void
proto_register_modbus(void)
{
static hf_register_info hf[] = {
{ &hf_mbtcp_transid,
{ "transaction identifier", "mbtcp.trans_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mbtcp_protid,
{ "protocol identifier", "mbtcp.prot_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mbtcp_len,
{ "length", "mbtcp.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mbtcp_unitid,
{ "unit identifier", "mbtcp.modbus.unit_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mbtcp_functioncode,
{ "function code", "mbtcp.modbus.func_code",
FT_UINT8, BASE_DEC, VALS(function_code_vals), 0x0,
NULL, HFILL }
},
{ &hf_modbus_reference,
{ "reference number", "mbtcp.modbus.reference_num",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_modbus_lreference,
{ "reference number (32 bit)", "mbtcp.modbus.reference_num_32",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_modbus_reftype,
{ "reference type", "mbtcp.modbus.reference_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_modbus_readref,
{ "read reference number", "mbtcp.modbus.read_reference_num",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_modbus_writeref,
{ "write reference number", "mbtcp.modbus.write_reference_num",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_modbus_wordcnt,
{ "word count", "mbtcp.modbus.word_cnt",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_modbus_readwordcnt,
{ "read word count", "mbtcp.modbus.read_word_cnt",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_modbus_writewordcnt,
{ "write word count", "mbtcp.modbus.write_word_cnt",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_modbus_bitcnt,
{ "bit count", "mbtcp.modbus.bit_cnt",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_modbus_bytecnt,
{ "byte count", "mbtcp.modbus.byte_cnt",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_modbus_lbytecnt,
{ "byte count (16-bit)", "mbtcp.modbus.byte_cnt_16",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_modbus_exceptioncode,
{ "exception code", "mbtcp.modbus.exception_code",
FT_UINT8, BASE_DEC, VALS(exception_code_vals), 0x0,
NULL, HFILL }
},
{ &hf_modbus_diag_sf,
{ "diagnostic code", "mbtcp.modbus.diagnostic_code",
FT_UINT16, BASE_DEC, VALS(diagnostic_code_vals), 0x0,
NULL, HFILL }
},
{ &hf_modbus_status,
{ "status", "mbtcp.modbus.ev_status",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_modbus_event_count,
{ "event count", "mbtcp.modbus.ev_count",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_modbus_message_count,
{ "message count", "mbtcp.modbus.ev_msg_count",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_modbus_event_recv_comm_err,
{ "Communication Error", "mbtcp.modbus.ev_recv_comm_err",
FT_UINT8, BASE_DEC, NULL, 0x02,
NULL, HFILL }
},
{ &hf_modbus_event_recv_char_over,
{ "Character Overrun", "mbtcp.modbus.ev_recv_char_over",
FT_UINT8, BASE_DEC, NULL, 0x10,
NULL, HFILL }
},
{ &hf_modbus_event_recv_lo_mode,
{ "Currently in Listen Only Mode", "mbtcp.modbus.ev_recv_lo_mode",
FT_UINT8, BASE_DEC, NULL, 0x20,
NULL, HFILL }
},
{ &hf_modbus_event_recv_broadcast,
{ "Broadcast Received", "mbtcp.modbus.ev_recv_broadcast",
FT_UINT8, BASE_DEC, NULL, 0x40,
NULL, HFILL }
},
{ &hf_modbus_event_send_read_ex,
{ "Read Exception Sent", "mbtcp.modbus.ev_send_read_ex",
FT_UINT8, BASE_DEC, NULL, 0x01,
NULL, HFILL }
},
{ &hf_modbus_event_send_slave_abort_ex,
{ "Slave Abort Exception Sent", "mbtcp.modbus.ev_send_slave_abort_ex",
FT_UINT8, BASE_DEC, NULL, 0x02,
NULL, HFILL }
},
{ &hf_modbus_event_send_slave_busy_ex,
{ "Slave Busy Exception Sent", "mbtcp.modbus.ev_send_slave_busy_ex",
FT_UINT8, BASE_DEC, NULL, 0x04,
NULL, HFILL }
},
{ &hf_modbus_event_send_slave_nak_ex,
{ "Slave Program NAK Exception Sent", "mbtcp.modbus.ev_send_slave_nak_ex",
FT_UINT8, BASE_DEC, NULL, 0x08,
NULL, HFILL }
},
{ &hf_modbus_event_send_write_timeout,
{ "Write Timeout Error Occurred", "mbtcp.modbus.ev_send_write_timeout",
FT_UINT8, BASE_DEC, NULL, 0x10,
NULL, HFILL }
},
{ &hf_modbus_event_send_lo_mode,
{ "Currently in Listen Only Mode", "mbtcp.modbus.ev_send_lo_mode",
FT_UINT8, BASE_DEC, NULL, 0x20,
NULL, HFILL }
},
{ &hf_modbus_andmask,
{ "AND mask", "mbtcp.modbus.and_mask",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_modbus_ormask,
{ "OR mask", "mbtcp.modbus.or_mask",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_modbus_data,
{ "Data", "mbtcp.modbus.data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_modbus_mei,
{ "MEI type", "mbtcp.modbus.mei",
FT_UINT8, BASE_DEC, VALS(encap_interface_code_vals), 0x0,
NULL, HFILL }
},
{ &hf_modbus_read_device_id,
{ "Read Device ID", "mbtcp.modbus.read_device_id",
FT_UINT8, BASE_DEC, VALS(read_device_id_vals), 0x0,
NULL, HFILL }
},
{ &hf_modbus_object_id,
{ "Object ID", "mbtcp.modbus.object_id",
FT_UINT8, BASE_DEC, VALS(object_id_vals), 0x0,
NULL, HFILL }
},
{ &hf_modbus_num_objects,
{ "Number of Objects", "mbtcp.modbus.num_objects",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_modbus_list_object_len,
{ "Object length", "mbtcp.modbus.objects_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_modbus_conformity_level,
{ "Conformity Level", "mbtcp.modbus.conformity_level",
FT_UINT8, BASE_HEX, VALS(conformity_level_vals), 0x0,
NULL, HFILL }
},
{ &hf_modbus_more_follows,
{ "More Follows", "mbtcp.modbus.more_follows",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_modbus_next_object_id,
{ "Next Object ID", "mbtcp.modbus.next_object_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_modbus_object_str_value,
{ "Object String Value", "mbtcp.modbus.object_str_value",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_mbtcp,
&ett_modbus_hdr,
&ett_group_hdr,
&ett_events,
&ett_events_recv,
&ett_events_send,
&ett_device_id_objects,
&ett_device_id_object_items
};
proto_mbtcp = proto_register_protocol("Modbus/TCP", "Modbus/TCP", "mbtcp");
proto_modbus = proto_register_protocol("Modbus", "Modbus", "modbus");
new_register_dissector("mbtcp", dissect_mbtcp, proto_mbtcp);
new_register_dissector("modbus", dissect_modbus, proto_modbus);
mbtcp_dissector_table = register_dissector_table("mbtcp.modbus.data", "Modbus/TCP Data", FT_STRING, BASE_NONE);
modbus_dissector_table = register_dissector_table("mbtcp.prot_id", "protocol identifier", FT_UINT16, BASE_DEC);
proto_register_field_array(proto_mbtcp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_mbtcp(void)
{
dissector_handle_t mbtcp_handle, mbudp_handle;
mbtcp_handle = new_create_dissector_handle(dissect_mbtcp, proto_mbtcp);
dissector_add_uint("tcp.port", PORT_MBTCP, mbtcp_handle);
mbudp_handle = new_create_dissector_handle(dissect_mbudp, proto_mbtcp);
dissector_add_uint("udp.port", PORT_MBTCP, mbudp_handle);
modbus_handle = new_create_dissector_handle(dissect_modbus, proto_modbus);
dissector_add_uint("mbtcp.prot_id", MODBUS_PROTOCOL_ID, modbus_handle);
}
