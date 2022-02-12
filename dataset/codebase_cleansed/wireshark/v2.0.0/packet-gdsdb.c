static int dword_align(int length)
{
return (length + (4-(length&3)));
}
static int add_uint_string(proto_tree *tree, int hf_string, tvbuff_t *tvb, int offset)
{
proto_item* ti;
int length;
ti = proto_tree_add_item(tree, hf_string, tvb,
offset, 4, ENC_ASCII|ENC_BIG_ENDIAN);
length = dword_align(tvb_get_ntohl(tvb, offset))+4;
proto_item_set_len(ti, length);
return offset + length;
}
static int add_byte_array(proto_tree *tree, int hf_len, int hf_byte, tvbuff_t *tvb, int offset)
{
proto_item* ti;
guint32 length;
proto_tree_add_item_ret_uint(tree, hf_len, tvb,
offset, 4, ENC_BIG_ENDIAN, &length);
offset += 4;
if (length > 0)
{
ti = proto_tree_add_item(tree, hf_byte, tvb,
offset, length, ENC_NA);
length = dword_align(length);
proto_item_set_len(ti, length);
}
return offset + length;
}
static int
gdsdb_dummy(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int offset _U_)
{
return tvb_reported_length(tvb);
}
static int
gdsdb_connect(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
int count, file_size, total_length = 16;
int i, length = tvb_reported_length_remaining(tvb, offset);
proto_item *ti;
proto_tree *pref_tree;
if (length < total_length)
return -1;
file_size = tvb_get_ntohl(tvb, offset+12);
total_length += 4+dword_align(file_size);
if (length < total_length+4)
return -1;
count = tvb_get_ntohl(tvb, offset+total_length-4);
total_length += (4+(count*20));
if (length < total_length)
return -1;
proto_tree_add_item(tree, hf_gdsdb_connect_operation, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_connect_version, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_connect_client, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = add_uint_string(tree, hf_gdsdb_connect_filename, tvb, offset);
proto_tree_add_item(tree, hf_gdsdb_connect_count, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s", tvb_format_text(tvb, offset+4, tvb_get_ntohl(tvb, offset)));
offset = add_uint_string(tree, hf_gdsdb_connect_userid, tvb, offset);
for(i=0;i<count;i++){
ti = proto_tree_add_item(tree, hf_gdsdb_connect_pref, tvb, offset, 20, ENC_NA);
pref_tree = proto_item_add_subtree(ti, ett_gdsdb_connect_pref);
proto_tree_add_item(pref_tree, hf_gdsdb_connect_pref_version,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pref_tree, hf_gdsdb_connect_pref_architecture,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pref_tree, hf_gdsdb_connect_pref_mintype,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pref_tree, hf_gdsdb_connect_pref_maxtype,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pref_tree, hf_gdsdb_connect_pref_weight,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
return offset;
}
static int
gdsdb_accept(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
if (tvb_reported_length_remaining(tvb, offset) < 12) {
return -1;
}
proto_tree_add_item(tree, hf_gdsdb_accept_version, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_accept_architecture, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_accept_proto_min_type, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
gdsdb_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
if (tvb_reported_length_remaining(tvb, offset) < 16) {
return -1;
}
proto_tree_add_item(tree, hf_gdsdb_request_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_request_object, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_request_partner, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
return offset;
}
static int
gdsdb_attach(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
int total_length = 12;
int size, length = tvb_reported_length_remaining(tvb, offset);
if (length < total_length) {
return -1;
}
size = tvb_get_ntohl(tvb, offset+4);
total_length += dword_align(size);
if (length < total_length)
return -1;
size = tvb_get_ntohl(tvb, offset+total_length-4);
total_length += dword_align(size);
if (length < total_length)
return -1;
proto_tree_add_item(tree, hf_gdsdb_attach_database_object_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s", tvb_format_text(tvb, offset+4, tvb_get_ntohl(tvb, offset)));
offset = add_uint_string(tree, hf_gdsdb_attach_database_path, tvb, offset);
offset = add_uint_string(tree, hf_gdsdb_attach_database_param_buf, tvb, offset);
return offset;
}
static int
gdsdb_compile(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
int total_length = 8;
int size, length = tvb_reported_length_remaining(tvb, offset);
if (length < total_length) {
return -1;
}
size = tvb_get_ntohl(tvb, offset+4);
total_length += dword_align(size);
if (length < total_length)
return -1;
proto_tree_add_item(tree, hf_gdsdb_compile_database, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = add_uint_string(tree, hf_gdsdb_compile_blr, tvb, offset);
return offset;
}
static int
gdsdb_receive(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
if (tvb_reported_length_remaining(tvb, offset) < 20) {
return -1;
}
proto_tree_add_item(tree, hf_gdsdb_receive_request, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_receive_incarnation, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_receive_transaction, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_receive_msgnr, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_receive_messages, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
while (tvb_reported_length_remaining(tvb, offset) >= 12) {
proto_tree_add_item(tree, hf_gdsdb_receive_direction,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_receive_offset,
tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
}
return offset;
}
static int
gdsdb_send(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
if (tvb_reported_length_remaining(tvb, offset) < 20) {
return -1;
}
proto_tree_add_item(tree, hf_gdsdb_send_request, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_send_incarnation, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_send_transaction, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_send_msgnr, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_send_messages, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
gdsdb_status_vector(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint32 arg;
while (tvb_reported_length_remaining(tvb, offset) >= 4)
{
proto_tree_add_item_ret_uint(tree, hf_gdsdb_status_vector_arg, tvb,
offset, 4, ENC_BIG_ENDIAN, &arg);
offset += 4;
if (arg == 0)
break;
switch(arg)
{
case arg_gds:
default:
proto_tree_add_item(tree, hf_gdsdb_status_vector_error_code, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case arg_number:
proto_tree_add_item(tree, hf_gdsdb_status_vector_number, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case arg_string:
case arg_interpreted:
offset = add_uint_string(tree, hf_gdsdb_status_vector_string, tvb, offset);
break;
case arg_sql_state:
offset = add_uint_string(tree, hf_gdsdb_status_vector_sql_state, tvb, offset);
break;
}
}
return offset;
}
static int
gdsdb_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
int total_length = 16;
int length = tvb_reported_length_remaining(tvb, offset);
guint32 size_length;
if (length < total_length) {
return -1;
}
total_length += dword_align(tvb_get_ntohl(tvb, offset+12));
if (length < total_length) {
return -1;
}
proto_tree_add_item(tree, hf_gdsdb_response_object, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_response_blobid, tvb,
offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item_ret_uint(tree, hf_gdsdb_response_datasize, tvb,
offset, 4, ENC_BIG_ENDIAN, &size_length);
offset += 4;
if (size_length > 0)
proto_tree_add_item(tree, hf_gdsdb_response_data, tvb, offset, size_length, ENC_NA);
offset += size_length;
return gdsdb_status_vector(tree, tvb, offset);
}
static int
gdsdb_transact(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
if (tvb_reported_length_remaining(tvb, offset) < 8) {
return -1;
}
proto_tree_add_item(tree, hf_gdsdb_transact_database, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_transact_transaction, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
gdsdb_transact_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
if (tvb_reported_length_remaining(tvb, offset) < 4) {
return -1;
}
proto_tree_add_item(tree, hf_gdsdb_transactresponse_messages,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
gdsdb_open_blob2(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
int total_length = 12;
int length = tvb_reported_length_remaining(tvb, offset);
if (length < total_length) {
return -1;
}
total_length += dword_align(tvb_get_ntohl(tvb, offset));
if (length < total_length) {
return -1;
}
offset = add_uint_string(tree, hf_gdsdb_openblob2_bpb, tvb, offset);
proto_tree_add_item(tree, hf_gdsdb_openblob_transaction, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_openblob_id, tvb, offset,
8, ENC_BIG_ENDIAN);
offset += 8;
return offset;
}
static int
gdsdb_open_blob(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
if (tvb_reported_length_remaining(tvb, offset) < 8) {
return -1;
}
proto_tree_add_item(tree, hf_gdsdb_openblob_transaction, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_openblob_id, tvb, offset,
8, ENC_BIG_ENDIAN);
offset += 8;
return offset;
}
static int
gdsdb_segment(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
if (tvb_reported_length_remaining(tvb, offset) < 12)
return -1;
if (tree) {
}
return tvb_reported_length(tvb);
}
static int
gdsdb_seek_blob(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
if (tvb_reported_length_remaining(tvb, offset) < 12)
return -1;
if (tree) {
}
return tvb_reported_length(tvb);
}
static int
gdsdb_reconnect(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
int total_length = 8;
int length = tvb_reported_length_remaining(tvb, offset);
if (length < total_length) {
return -1;
}
total_length += dword_align(tvb_get_ntohl(tvb, offset+4));
if (length < total_length) {
return -1;
}
proto_tree_add_item(tree, hf_gdsdb_reconnect_handle, tvb, offset,
4, ENC_BIG_ENDIAN);
offset += 4;
offset = add_byte_array(tree, hf_gdsdb_reconnect_database_size, hf_gdsdb_reconnect_database, tvb, offset);
return offset;
}
static int
gdsdb_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
guint opcode;
int total_length = 16;
int length = tvb_reported_length_remaining(tvb, offset);
if (length < total_length) {
return -1;
}
opcode = tvb_get_ntohl(tvb, offset-4);
total_length += dword_align(tvb_get_ntohl(tvb, offset+8));
if (length < total_length) {
return -1;
}
if(opcode == op_service_info) {
total_length += dword_align(tvb_get_ntohl(tvb, offset+total_length-8));
if (length < total_length) {
return -1;
}
}
proto_tree_add_item(tree, hf_gdsdb_info_object, tvb, offset,
4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_info_incarnation, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = add_uint_string(tree, hf_gdsdb_info_items, tvb, offset);
if(opcode == op_service_info) {
offset = add_uint_string(tree, hf_gdsdb_info_recv_items, tvb, offset);
}
proto_tree_add_item(tree, hf_gdsdb_info_buffer_length, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
gdsdb_service_start(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
if (tvb_reported_length_remaining(tvb, offset) < 16)
return -1;
if (tree) {
}
return tvb_reported_length(tvb);
}
static int
gdsdb_release(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
if (tvb_reported_length_remaining(tvb, offset) < 4)
return -1;
proto_tree_add_item(tree, hf_gdsdb_release_object, tvb, offset,
4, ENC_BIG_ENDIAN);
return tvb_reported_length(tvb);
}
static int
gdsdb_event(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
if (tvb_reported_length_remaining(tvb, offset) < 20)
return -1;
if (tree) {
}
return tvb_reported_length(tvb);
}
static int
gdsdb_cancel_events(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
if (tvb_reported_length_remaining(tvb, offset) < 8)
return -1;
if (tree) {
}
return tvb_reported_length(tvb);
}
static int
gdsdb_ddl(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
if (tvb_reported_length_remaining(tvb, offset) < 12)
return -1;
if (tree) {
}
return tvb_reported_length(tvb);
}
static int
gdsdb_slice(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
if (tvb_reported_length_remaining(tvb, offset) < 20)
return -1;
if (tree) {
}
return tvb_reported_length(tvb);
}
static int
gdsdb_slice_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
if (tvb_reported_length_remaining(tvb, offset) < 4)
return -1;
if (tree) {
}
return tvb_reported_length(tvb);
}
static int
gdsdb_execute(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
if (tvb_reported_length_remaining(tvb, offset) < 16)
return -1;
proto_tree_add_item(tree, hf_gdsdb_execute_statement, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_execute_transaction, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_execute_message_number, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_execute_messages, tvb,
offset, 4, ENC_BIG_ENDIAN);
return tvb_reported_length(tvb);
}
static int
gdsdb_exec_immediate2(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
if (tvb_reported_length_remaining(tvb, offset) < 40)
return -1;
if (tree) {
}
return tvb_reported_length(tvb);
}
static int
gdsdb_prepare(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
int total_length = 20;
int length = tvb_reported_length_remaining(tvb, offset);
if (length < total_length) {
return -1;
}
total_length += dword_align(tvb_get_ntohl(tvb, offset+12));
if (length < total_length) {
return -1;
}
proto_tree_add_item(tree, hf_gdsdb_prepare_transaction, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_prepare_statement, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_prepare_dialect, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s", tvb_format_text(tvb, offset+4, tvb_get_ntohl(tvb, offset)));
offset = add_uint_string(tree, hf_gdsdb_prepare_querystr, tvb, offset);
proto_tree_add_item(tree, hf_gdsdb_prepare_bufferlength, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
gdsdb_fetch(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
if (tvb_reported_length_remaining(tvb, offset) < 12) {
return -1;
}
if (tree) {
}
return tvb_reported_length(tvb);
}
static int
gdsdb_fetch_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
if (tvb_reported_length_remaining(tvb, offset) < 8) {
return -1;
}
if (tree) {
}
return tvb_reported_length(tvb);
}
static int
gdsdb_free_statement(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
if (tvb_reported_length_remaining(tvb, offset) < 8) {
return -1;
}
proto_tree_add_item(tree, hf_gdsdb_free_statement, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_free_option, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
gdsdb_insert(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
if (tvb_reported_length_remaining(tvb, offset) < 12) {
return -1;
}
if (tree) {
}
return tvb_reported_length(tvb);
}
static int
gdsdb_cursor(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
if (tvb_reported_length_remaining(tvb, offset) < 12) {
return -1;
}
if (tree) {
}
return tvb_reported_length(tvb);
}
static int
gdsdb_sql_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
if (tvb_reported_length_remaining(tvb, offset) < 4) {
return -1;
}
if (tree) {
}
return tvb_reported_length(tvb);
}
static int
dissect_gdsdb(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *gdsdb_tree;
guint opcode;
int offset = 0;
if (tvb_reported_length(tvb) < 4)
return 0;
opcode = tvb_get_ntohl(tvb, offset);
if(opcode >= op_max)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GDS DB");
col_clear(pinfo->cinfo, COL_INFO);
while (tvb_reported_length_remaining(tvb, offset) >= 4)
{
opcode = tvb_get_ntohl(tvb, offset);
if(opcode >= op_max)
return 0;
col_append_sep_str(pinfo->cinfo, COL_INFO, ", ",
val_to_str(opcode, gdsdb_opcode, "Unknown opcode %u"));
ti = proto_tree_add_item(tree, proto_gdsdb, tvb, offset, -1, ENC_NA);
gdsdb_tree = proto_item_add_subtree(ti, ett_gdsdb);
proto_tree_add_item(gdsdb_tree, hf_gdsdb_opcode, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset = gdsdb_handle_opcode[opcode](tvb, pinfo, gdsdb_tree, offset+4);
if (offset < 0)
{
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return -1;
}
}
return offset;
}
void
proto_register_gdsdb(void)
{
static hf_register_info hf[] = {
{ &hf_gdsdb_opcode,
{ "Opcode", "gdsdb.opcode",
FT_UINT32, BASE_DEC, VALS(gdsdb_opcode), 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_connect_operation,
{ "Operation", "gdsdb.connect.operation",
FT_UINT32, BASE_DEC, VALS(gdsdb_opcode), 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_connect_version,
{ "Version", "gdsdb.connect.version",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_connect_client,
{ "Client Architecture", "gdsdb.connect.client",
FT_UINT32, BASE_DEC, VALS(gdsdb_architectures), 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_connect_filename,
{ "Filename", "gdsdb.connect.filename",
FT_UINT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_connect_count,
{ "Version option count", "gdsdb.connect.count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_connect_userid,
{ "User ID", "gdsdb.connect.userid",
FT_UINT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_connect_pref,
{ "Preferred version", "gdsdb.connect.pref",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_connect_pref_version,
{ "Version", "gdsdb.connect.pref.version",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_connect_pref_architecture,
{ "Architecture", "gdsdb.connect.pref.arch",
FT_UINT32, BASE_DEC, VALS(gdsdb_architectures), 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_connect_pref_mintype,
{ "Minimum type", "gdsdb.connect.pref.mintype",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_connect_pref_maxtype,
{ "Maximum type", "gdsdb.connect.pref.maxtype",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_connect_pref_weight,
{ "Preference weight", "gdsdb.connect.pref.weight",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_accept_version,
{ "Version", "gdsdb.accept.version",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_accept_architecture,
{ "Architecture", "gdsdb.accept.arch",
FT_UINT32, BASE_DEC, VALS(gdsdb_architectures), 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_accept_proto_min_type,
{ "Protocol Minimum Type", "gdsdb.accept.proto_min_type",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_request_type,
{ "Type", "gdsdb.connect.type",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_request_object,
{ "Object", "gdsdb.connect.object",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_request_partner,
{ "Partner", "gdsdb.connect.partner",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_attach_database_object_id,
{ "Database ObjectID", "gdsdb.attach.database_object_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_attach_database_path,
{ "Database Path", "gdsdb.attach.database_path",
FT_UINT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_attach_database_param_buf,
{ "Database Parameter Buffers", "gdsdb.attach.database_param_buf",
FT_UINT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_compile_database,
{ "Database", "gdsdb.compile.filename",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_compile_blr,
{ "BLR", "gdsdb.compile.blr",
FT_UINT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_receive_request,
{ "Request", "gdsdb.receive.request",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_receive_incarnation,
{ "Incarnation", "gdsdb.receive.incarnation",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_receive_transaction,
{ "Transaction", "gdsdb.receive.transaction",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_receive_msgnr,
{ "Message number", "gdsdb.receive.msgnr",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_receive_messages,
{ "Message Count", "gdsdb.receive.msgcount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_receive_direction,
{ "Scroll direction", "gdsdb.receive.direction",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_receive_offset,
{ "Scroll offset", "gdsdb.receive.offset",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_send_request,
{ "Send request", "gdsdb.send.request",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_send_incarnation,
{ "Send request", "gdsdb.send.incarnation",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_send_transaction,
{ "Send request", "gdsdb.send.transaction",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_send_msgnr,
{ "Send request", "gdsdb.send.msgnr",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_send_messages,
{ "Send request", "gdsdb.send.messages",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_response_object,
{ "Response object", "gdsdb.response.object",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_response_blobid,
{ "Blob ID", "gdsdb.response.blobid",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_response_datasize,
{ "Data size", "gdsdb.response.datasize",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_response_data,
{ "Data", "gdsdb.response.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_status_vector_arg,
{ "Argument", "gdsdb.status_vector.arg",
FT_UINT32, BASE_DEC, VALS(gdsdb_arg_types), 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_status_vector_error_code,
{ "Error code", "gdsdb.status_vector.error_code",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_status_vector_number,
{ "Number", "gdsdb.status_vector.number",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_status_vector_string,
{ "String", "gdsdb.status_vector.string",
FT_UINT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_status_vector_sql_state,
{ "SQL State", "gdsdb.status_vector.sql_state",
FT_UINT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_transact_database,
{ "Database", "gdsdb.transact.database",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_transact_transaction,
{ "Database", "gdsdb.transact.transaction",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_gdsdb_transact_messages,
{ "Messages", "gdsdb.transact.messages",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_gdsdb_transactresponse_messages,
{ "Messages", "gdsdb.transactresponse.messages",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_openblob2_bpb,
{ "Blob parameter block", "gdsdb.openblob2.bpb",
FT_UINT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_openblob_transaction,
{ "Transaction", "gdsdb.openblob2.transaction",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_openblob_id,
{ "ID", "gdsdb.openblob.id",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_gdsdb_segment_blob,
{ "Blob", "gdsdb.segment.blob",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_segment_length,
{ "Length", "gdsdb.segment.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_segment_segment,
{ "Segment", "gdsdb.segment.segment",
FT_UINT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_seekblob_blob,
{ "Blob", "gdsdb.seekblob.blob",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_seekblob_mode,
{ "Mode", "gdsdb.seekblob.mode",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_gdsdb_reconnect_handle,
{ "Handle", "gdsdb.reconnect.handle",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_reconnect_database_size,
{ "Database size", "gdsdb.reconnect.database_size",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_reconnect_database,
{ "Database", "gdsdb.reconnect.database",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_info_object,
{ "Object", "gdsdb.info.object",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_info_incarnation,
{ "Incarnation", "gdsdb.info.incarnation",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_info_items,
{ "Items", "gdsdb.info.items",
FT_UINT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_info_recv_items,
{ "Items", "gdsdb.info.recv_items",
FT_UINT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_info_buffer_length,
{ "Buffer length", "gdsdb.info.bufferlength",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_release_object,
{ "Object", "gdsdb.release.object",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_gdsdb_prepare2_transaction,
{ "Transaction", "gdsdb.prepare2.transaction",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_event_database,
{ "Database", "gdsdb.event.database",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_event_items,
{ "Event description block", "gdsdb.event.items",
FT_UINT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_event_ast,
{ "ast routine", "gdsdb.event.ast",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_event_arg,
{ "Argument to ast routine", "gdsdb.event.arg",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_event_rid,
{ "ID", "gdsdb.event.id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_ddl_database,
{ "Database", "gdsdb.ddl.database",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_ddl_transaction,
{ "Transaction", "gdsdb.ddl.transaction",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_ddl_blr,
{ "BLR", "gdsdb.ddl.blr",
FT_UINT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_slice_transaction,
{ "Transaction", "gdsdb.slice.transaction",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_slice_id,
{ "ID", "gdsdb.slice.id",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_slice_sdl,
{ "Slice description language", "gdsdb.slice.sdl",
FT_UINT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_slice_parameters,
{ "Parameters", "gdsdb.slice.parameters",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_sliceresponse_length,
{ "Length", "gdsdb.sliceresponse.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_gdsdb_execute_statement,
{ "Statement", "gdsdb.execute.statement",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_execute_transaction,
{ "Transaction", "gdsdb.execute.transaction",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_execute_message_number,
{ "Message number", "gdsdb.execute.messagenumber",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_execute_messages,
{ "Number of messages", "gdsdb.execute.messages",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_gdsdb_execute_outblr,
{ "Output BLR", "gdsdb.execute.outblr",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_execute_outmsgnr,
{ "Output Message number", "gdsdb.execute.outmsgnr",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_prepare2_blr,
{ "BLR", "gdsdb.prepare.blr",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_prepare2_number,
{ "Message number", "gdsdb.prepare2.messagenumber",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_prepare2_messages,
{ "Number of messages", "gdsdb.prepare2.messages",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_prepare2_outblr,
{ "Output BLR", "gdsdb.prepare2.outblr",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_prepare2_outmsgnr,
{ "Output Message number", "gdsdb.prepare2.outmsgnr",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_gdsdb_prepare_transaction,
{ "Prepare, Transaction", "gdsdb.prepare.transaction",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_prepare_statement,
{ "Prepare, Statement", "gdsdb.prepare.statement",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_prepare_dialect,
{ "Prepare, Dialect", "gdsdb.prepare.dialect",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_prepare_querystr,
{ "Prepare, Query", "gdsdb.prepare.querystr",
FT_UINT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_prepare_bufferlength,
{ "Prepare, Bufferlength", "gdsdb.prepare.bufferlen",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_gdsdb_fetch_statement,
{ "Statement", "gdsdb.fetch.statement",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_fetch_message_number,
{ "Message number", "gdsdb.fetch.messagenr",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_fetch_messages,
{ "Number of messages", "gdsdb.fetch.messages",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_fetchresponse_status,
{ "Status", "gdsdb.fetchresponse.status",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_fetchresponse_messages,
{ "Number of messages", "gdsdb.fetchresponse.messages",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_gdsdb_free_statement,
{ "Statement", "gdsdb.fetchresponse.statement",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_free_option,
{ "Option", "gdsdb.fetchresponse.option",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_gdsdb_insert_statement,
{ "Statement", "gdsdb.insert.statement",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_insert_message_number,
{ "Message number", "gdsdb.insert.messagenr",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_insert_messages,
{ "Number of messages", "gdsdb.insert.messages",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_cursor_statement,
{ "Statement", "gdsdb.cursor.statement",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_cursor_type,
{ "Type", "gdsdb.cursor.type",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_sqlresponse_messages,
{ "SQL Response, Message Count", "gdsdb.sqlresponse.msgcount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
}
#endif
};
static gint *ett[] = {
&ett_gdsdb,
&ett_gdsdb_connect_pref
};
proto_gdsdb = proto_register_protocol(
"Firebird SQL Database Remote Protocol",
"FB/IB GDS DB", "gdsdb");
proto_register_field_array(proto_gdsdb, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_gdsdb(void)
{
dissector_handle_t gdsdb_handle;
gdsdb_handle = new_create_dissector_handle(dissect_gdsdb,
proto_gdsdb);
dissector_add_uint("tcp.port", TCP_PORT, gdsdb_handle);
}
