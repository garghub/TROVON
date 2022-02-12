static int
gdsdb_dummy(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_)
{
return 0;
}
static int
gdsdb_connect(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset;
int length;
int count;
int i;
proto_item *ti;
proto_tree *pref_tree;
if (tvb_length(tvb) < 16) {
return 0;
}
if (check_col(pinfo->cinfo, COL_INFO)){
col_append_str(pinfo->cinfo, COL_INFO, ": ");
col_append_str(pinfo->cinfo, COL_INFO,
tvb_format_text(tvb, 20,
tvb_get_ntohl(tvb, 16)));
}
if (tree) {
offset = 4;
proto_tree_add_item(tree, hf_gdsdb_connect_operation, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_connect_version, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_connect_client, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_connect_filename, tvb,
offset, 4, ENC_ASCII|ENC_NA);
length = tvb_get_ntohl(tvb, offset);
offset += length + 6;
proto_tree_add_item(tree, hf_gdsdb_connect_count, tvb,
offset, 4, ENC_BIG_ENDIAN);
count = tvb_get_ntohl(tvb, offset);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_connect_userid, tvb,
offset, 4, ENC_ASCII|ENC_NA);
length = tvb_get_ntohl(tvb, offset);
offset += length + 5;
for(i=0;i<count;i++){
ti = proto_tree_add_item(tree, hf_gdsdb_connect_pref,
tvb, offset, 20, ENC_NA);
pref_tree = proto_item_add_subtree(ti,
ett_gdsdb_connect_pref);
proto_tree_add_item(pref_tree,
hf_gdsdb_connect_pref_version,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pref_tree,
hf_gdsdb_connect_pref_architecture,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pref_tree,
hf_gdsdb_connect_pref_mintype,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pref_tree,
hf_gdsdb_connect_pref_maxtype,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pref_tree,
hf_gdsdb_connect_pref_weight,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
}
return tvb_length(tvb);
}
static int
gdsdb_accept(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset;
if (tvb_length(tvb) < 16) {
return 0;
}
if (tree) {
offset = 4;
proto_tree_add_item(tree, hf_gdsdb_accept_version, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_accept_architecture, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
return tvb_length(tvb);
}
static int
gdsdb_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset;
if (tvb_length(tvb) < 20) {
return 0;
}
if (tree) {
offset = 4;
proto_tree_add_item(tree, hf_gdsdb_request_type, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_request_object, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_request_partner, tvb,
offset, 8, ENC_BIG_ENDIAN);
}
return tvb_length(tvb);
}
static int
gdsdb_attach(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset;
int length;
if (tvb_length(tvb) < 20) {
return 0;
}
if (check_col(pinfo->cinfo, COL_INFO)){
col_append_str(pinfo->cinfo, COL_INFO, ": ");
col_append_str(pinfo->cinfo, COL_INFO,
tvb_format_text(tvb, 12,
tvb_get_ntohl(tvb, 8)));
}
if (tree) {
offset = 4;
proto_tree_add_item(tree, hf_gdsdb_attach_database, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_attach_filename, tvb,
offset, 4, ENC_ASCII|ENC_NA);
length = tvb_get_ntohl(tvb, offset);
offset += length + 6;
proto_tree_add_uint_format_value(tree,
hf_gdsdb_attach_dpb, tvb, offset, 4 + length,
length, "%i data bytes", length);
}
return tvb_length(tvb);
}
static int
gdsdb_compile(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset;
if (tvb_length(tvb) < 20) {
return 0;
}
if (tree) {
offset = 4;
proto_tree_add_item(tree, hf_gdsdb_compile_database, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_compile_blr, tvb,
offset, 4, ENC_ASCII|ENC_NA);
}
return tvb_length(tvb);
}
static int
gdsdb_receive(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset;
if (tvb_length(tvb) < 20) {
return 0;
}
if (tree) {
offset = 4;
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
while(tvb_bytes_exist(tvb, offset, 12)) {
proto_tree_add_item(tree, hf_gdsdb_receive_direction,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_receive_offset,
tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
}
}
return tvb_length(tvb);
}
static int
gdsdb_send(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset;
if (tvb_length(tvb) < 20) {
return 0;
}
if (tree) {
offset = 4;
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
}
return tvb_length(tvb);
}
static int
gdsdb_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset;
int length;
if (tvb_length(tvb) < 32) {
return 0;
}
if (tree) {
offset = 4;
proto_tree_add_item(tree, hf_gdsdb_response_object, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_response_blobid, tvb,
offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_gdsdb_response_data, tvb,
offset, 4, ENC_ASCII|ENC_NA);
length = tvb_get_ntohl(tvb, offset);
offset += length + 4;
proto_tree_add_item(tree, hf_gdsdb_response_status, tvb,
offset, tvb_length(tvb) - offset, ENC_NA);
}
return tvb_length(tvb);
}
static int
gdsdb_transact(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset;
if (tvb_length(tvb) < 20) {
return 0;
}
if (tree) {
offset = 4;
proto_tree_add_item(tree, hf_gdsdb_transact_database, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_transact_transaction, tvb,
offset, 4, ENC_BIG_ENDIAN);
}
return tvb_length(tvb);
}
static int
gdsdb_transact_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset;
if (tvb_length(tvb) < 8) {
return 0;
}
if (tree) {
offset = 4;
proto_tree_add_item(tree, hf_gdsdb_transactresponse_messages,
tvb, offset, 4, ENC_BIG_ENDIAN);
}
return tvb_length(tvb);
}
static int
gdsdb_open_blob2(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset;
int length;
if (!tvb_bytes_exist(tvb, 0, 20)) {
return 0;
}
if (tree) {
offset = 4;
proto_tree_add_item(tree, hf_gdsdb_openblob2_bpb, tvb, offset,
4, ENC_ASCII|ENC_NA);
length = tvb_get_ntohl(tvb, offset);
offset += length + 6;
proto_tree_add_item(tree, hf_gdsdb_openblob_transaction, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_openblob_id, tvb, offset,
8, ENC_BIG_ENDIAN);
}
return tvb_length(tvb);
}
static int
gdsdb_open_blob(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset;
if (tvb_length(tvb) < 16) {
return 0;
}
if (tree) {
offset = 4;
proto_tree_add_item(tree, hf_gdsdb_openblob_transaction, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_openblob_id, tvb, offset,
8, ENC_BIG_ENDIAN);
}
return tvb_length(tvb);
}
static int
gdsdb_segment(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
if (tvb_length(tvb) < 16) {
return 0;
}
if (tree) {
}
return tvb_length(tvb);
}
static int
gdsdb_seek_blob(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
if (tvb_length(tvb) < 16) {
return 0;
}
if (tree) {
}
return tvb_length(tvb);
}
static int
gdsdb_reconnect(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
if (tvb_length(tvb) < 12) {
return 0;
}
if (tree) {
}
return tvb_length(tvb);
}
static int
gdsdb_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset;
int length;
guint opcode;
if (tvb_length(tvb) < 20) {
return 0;
}
opcode = tvb_get_ntohl(tvb, 0);
if (tree) {
offset = 4;
proto_tree_add_item(tree, hf_gdsdb_info_object, tvb, offset,
4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_info_incarnation, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if(opcode == op_service_info) {
proto_tree_add_item(tree, hf_gdsdb_info_items, tvb,
offset, 4, ENC_ASCII|ENC_NA);
length = tvb_get_ntohl(tvb, offset);
offset += length + 6;
}
proto_tree_add_item(tree, hf_gdsdb_info_buffer_length, tvb,
offset, 4, ENC_BIG_ENDIAN);
}
return tvb_length(tvb);
}
static int
gdsdb_service_start(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
if (tvb_length(tvb) < 16) {
return 0;
}
if (tree) {
}
return tvb_length(tvb);
}
static int
gdsdb_release(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
if (tvb_length(tvb) < 8) {
return 0;
}
if (tree) {
}
return tvb_length(tvb);
}
static int
gdsdb_event(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
if (tvb_length(tvb) < 24) {
return 0;
}
if (tree) {
}
return tvb_length(tvb);
}
static int
gdsdb_cancel_events(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
if (tvb_length(tvb) < 12) {
return 0;
}
if (tree) {
}
return tvb_length(tvb);
}
static int
gdsdb_ddl(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
if (tvb_length(tvb) < 16) {
return 0;
}
if (tree) {
}
return tvb_length(tvb);
}
static int
gdsdb_slice(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
if (tvb_length(tvb) < 24) {
return 0;
}
if (tree) {
}
return tvb_length(tvb);
}
static int
gdsdb_slice_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
if (tvb_length(tvb) < 8) {
return 0;
}
if (tree) {
}
return tvb_length(tvb);
}
static int
gdsdb_execute(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
if (tvb_length(tvb) < 12) {
return 0;
}
if (tree) {
}
return tvb_length(tvb);
}
static int
gdsdb_exec_immediate2(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
if (tvb_length(tvb) < 44) {
return 0;
}
if (tree) {
}
return tvb_length(tvb);
}
static int
gdsdb_prepare(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset;
int length;
if (tvb_length(tvb) < 32) {
return 0;
}
if (check_col(pinfo->cinfo, COL_INFO)){
col_append_str(pinfo->cinfo, COL_INFO, ": ");
col_append_str(pinfo->cinfo, COL_INFO,
tvb_format_text(tvb, 20,
tvb_get_ntohl(tvb, 16)));
}
if(tree) {
offset = 4;
proto_tree_add_item(tree, hf_gdsdb_prepare_transaction, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_prepare_statement, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_prepare_dialect, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gdsdb_prepare_querystr, tvb,
offset, 4, ENC_ASCII|ENC_NA);
length = tvb_get_ntohl(tvb, offset);
offset += length + 6;
proto_tree_add_uint_format_value(tree,
hf_gdsdb_prepare_items, tvb, offset, 4 + length,
length, "%i data bytes", length);
offset += tvb_get_ntohl(tvb, offset) + 6;
proto_tree_add_item(tree, hf_gdsdb_prepare_bufferlength, tvb,
offset, 2, ENC_BIG_ENDIAN);
}
return tvb_length(tvb);
}
static int
gdsdb_fetch(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
if (tvb_length(tvb) < 16) {
return 0;
}
if (tree) {
}
return tvb_length(tvb);
}
static int
gdsdb_fetch_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
if (tvb_length(tvb) < 12) {
return 0;
}
if (tree) {
}
return tvb_length(tvb);
}
static int
gdsdb_free_statement(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
if (tvb_length(tvb) < 12) {
return 0;
}
if (tree) {
}
return tvb_length(tvb);
}
static int
gdsdb_insert(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
if (tvb_length(tvb) < 16) {
return 0;
}
if (tree) {
}
return tvb_length(tvb);
}
static int
gdsdb_cursor(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
if (tvb_length(tvb) < 16) {
return 0;
}
if (tree) {
}
return tvb_length(tvb);
}
static int
gdsdb_sql_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
if (tvb_length(tvb) < 8) {
return 0;
}
if (tree) {
}
return tvb_length(tvb);
}
static int
dissect_gdsdb(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *gdsdb_tree;
guint opcode;
packet_info nopi;
gdsdb_tree = NULL;
nopi.cinfo = NULL;
if (tvb_length(tvb) < 4)
return 0;
opcode = tvb_get_ntohl(tvb, 0);
if(opcode >= op_max)
return 0;
if(!gdsdb_handle_opcode[opcode](tvb, &nopi, NULL))
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GDS DB");
if (check_col(pinfo->cinfo, COL_INFO))
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(opcode, gdsdb_opcode, "Unknown opcode %u"));
if (tree) {
ti = proto_tree_add_item(tree, proto_gdsdb, tvb, 0, -1,
ENC_NA);
gdsdb_tree = proto_item_add_subtree(ti, ett_gdsdb);
proto_tree_add_item(gdsdb_tree, hf_gdsdb_opcode, tvb,
0, 4, ENC_BIG_ENDIAN);
}
return gdsdb_handle_opcode[opcode](tvb, pinfo, gdsdb_tree);
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
FT_UINT32, BASE_DEC, NULL, 0x0,
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
{ &hf_gdsdb_attach_database,
{ "Database", "gdsdb.attach.database",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_attach_filename,
{ "Filename", "gdsdb.attach.filename",
FT_UINT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_attach_dpb,
{ "Database parameter block", "gdsdb.attach.dpblength",
FT_UINT32, BASE_DEC, NULL, 0x0,
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
{ &hf_gdsdb_response_data,
{ "Data", "gdsdb.response.data",
FT_UINT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_response_status,
{ "Status vector", "gdsdb.response.status",
FT_NONE, BASE_NONE, NULL, 0x0,
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
{ &hf_gdsdb_transact_messages,
{ "Messages", "gdsdb.transact.messages",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
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
{ &hf_gdsdb_reconnect_database,
{ "Database", "gdsdb.reconnect.database",
FT_UINT32, BASE_DEC, NULL, 0x0,
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
{ &hf_gdsdb_prepare_items,
{ "Prepare, Information items", "gdsdb.prepare.items",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gdsdb_prepare_bufferlength,
{ "Prepare, Bufferlength", "gdsdb.prepare.bufferlen",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
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
};
static gint *ett[] = {
&ett_gdsdb,
&ett_gdsdb_opcode,
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
