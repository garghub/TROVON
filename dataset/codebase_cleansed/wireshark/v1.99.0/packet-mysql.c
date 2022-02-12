static int
mysql_dissect_greeting(tvbuff_t *tvb, packet_info *pinfo, int offset,
proto_tree *tree, mysql_conn_data_t *conn_data)
{
gint protocol;
gint lenstr;
int ver_offset;
proto_item *tf;
proto_item *greeting_tree;
protocol= tvb_get_guint8(tvb, offset);
if (protocol == 0xff) {
return mysql_dissect_error_packet(tvb, pinfo, offset+1, tree);
}
conn_data->state= LOGIN;
tf = proto_tree_add_item(tree, hf_mysql_server_greeting, tvb, offset, -1, ENC_NA);
greeting_tree = proto_item_add_subtree(tf, ett_server_greeting);
col_append_fstr(pinfo->cinfo, COL_INFO, " proto=%d", protocol) ;
proto_tree_add_item(greeting_tree, hf_mysql_protocol, tvb, offset, 1, ENC_NA);
offset += 1;
lenstr = tvb_strsize(tvb,offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " version=%s", tvb_get_string_enc(wmem_packet_scope(), tvb, offset, lenstr, ENC_ASCII|ENC_NA));
proto_tree_add_item(greeting_tree, hf_mysql_version, tvb, offset, lenstr, ENC_ASCII|ENC_NA);
conn_data->major_version = 0;
for (ver_offset = 0; ver_offset < lenstr; ver_offset++) {
guint8 ver_char = tvb_get_guint8(tvb, offset + ver_offset);
if (ver_char == '.') break;
conn_data->major_version = conn_data->major_version * 10 + ver_char - '0';
}
offset += lenstr;
proto_tree_add_item(greeting_tree, hf_mysql_thread_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
lenstr = tvb_strsize(tvb,offset);
proto_tree_add_item(greeting_tree, hf_mysql_salt, tvb, offset, lenstr, ENC_ASCII|ENC_NA);
offset += lenstr;
if (!tvb_reported_length_remaining(tvb, offset)) return offset;
offset = mysql_dissect_caps_server(tvb, offset, greeting_tree, &conn_data->srv_caps);
if (!tvb_reported_length_remaining(tvb, offset)) return offset;
proto_tree_add_item(greeting_tree, hf_mysql_server_language, tvb, offset, 1, ENC_NA);
offset += 1;
offset = mysql_dissect_server_status(tvb, offset, greeting_tree, NULL);
proto_tree_add_item(greeting_tree, hf_mysql_unused, tvb, offset, 13, ENC_NA);
offset += 13;
if (tvb_reported_length_remaining(tvb, offset)) {
lenstr = tvb_strsize(tvb,offset);
proto_tree_add_item(greeting_tree, hf_mysql_salt2, tvb, offset, lenstr, ENC_ASCII|ENC_NA);
offset += lenstr;
}
if (tvb_reported_length_remaining(tvb, offset)) {
lenstr = tvb_strsize(tvb,offset);
proto_tree_add_item(greeting_tree, hf_mysql_auth_plugin, tvb, offset, lenstr, ENC_ASCII|ENC_NA);
offset += lenstr;
}
return offset;
}
static int
add_connattrs_entry_to_tree(tvbuff_t *tvb, packet_info *pinfo _U_, proto_item *tree, int offset) {
guint64 lenstr;
int orig_offset = offset, lenfle;
proto_item *ti;
proto_tree *connattrs_tree;
ti = proto_tree_add_item(tree, hf_mysql_connattrs_attr, tvb, offset, 1, ENC_NA);
connattrs_tree = proto_item_add_subtree(ti, ett_connattrs_attr);
lenfle = tvb_get_fle(tvb, offset, &lenstr, NULL);
proto_tree_add_uint64(connattrs_tree, hf_mysql_connattrs_name_length, tvb, offset, lenfle, lenstr);
offset += lenfle;
tvb_ensure_bytes_exist64(tvb, offset, lenstr);
proto_tree_add_item(connattrs_tree, hf_mysql_connattrs_name, tvb, offset, (gint)lenstr, ENC_ASCII|ENC_NA);
proto_item_append_text(ti, " - %s", tvb_get_string_enc(wmem_packet_scope(), tvb, offset, (int)lenstr, ENC_ASCII|ENC_NA));
offset += (int)lenstr;
lenfle = tvb_get_fle(tvb, offset, &lenstr, NULL);
proto_tree_add_uint64(connattrs_tree, hf_mysql_connattrs_value_length, tvb, offset, lenfle, lenstr);
offset += lenfle;
tvb_ensure_bytes_exist64(tvb, offset, lenstr);
proto_tree_add_item(connattrs_tree, hf_mysql_connattrs_value, tvb, offset, (gint)lenstr, ENC_ASCII|ENC_NA);
proto_item_append_text(ti, ": %s", tvb_get_string_enc(wmem_packet_scope(), tvb, offset, (int)lenstr, ENC_ASCII|ENC_NA));
offset += (int)lenstr;
proto_item_set_len(ti, offset - orig_offset);
return (offset - orig_offset);
}
static int
mysql_dissect_login(tvbuff_t *tvb, packet_info *pinfo, int offset,
proto_tree *tree, mysql_conn_data_t *conn_data)
{
gint lenstr;
proto_item *tf;
proto_item *login_tree;
conn_data->state = RESPONSE_OK;
tf = proto_tree_add_item(tree, hf_mysql_login_request, tvb, offset, -1, ENC_NA);
login_tree = proto_item_add_subtree(tf, ett_login_request);
offset = mysql_dissect_caps_client(tvb, offset, login_tree, &conn_data->clnt_caps);
if (!(conn_data->frame_start_ssl) && conn_data->clnt_caps & MYSQL_CAPS_SL)
{
col_set_str(pinfo->cinfo, COL_INFO, "Response: SSL Handshake");
conn_data->frame_start_ssl = pinfo->fd->num;
}
if (conn_data->clnt_caps & MYSQL_CAPS_CU)
{
offset = mysql_dissect_ext_caps_client(tvb, offset, login_tree, &conn_data->clnt_caps_ext);
proto_tree_add_item(login_tree, hf_mysql_max_packet, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(login_tree, hf_mysql_charset, tvb, offset, 1, ENC_NA);
offset += 1;
offset += 23;
} else {
proto_tree_add_item(login_tree, hf_mysql_max_packet, tvb, offset, 3, ENC_LITTLE_ENDIAN);
offset += 3;
}
lenstr = my_tvb_strsize(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " user=%s", tvb_get_string_enc(wmem_packet_scope(), tvb, offset, lenstr, ENC_ASCII|ENC_NA));
proto_tree_add_item(login_tree, hf_mysql_user, tvb, offset, lenstr, ENC_ASCII|ENC_NA);
offset += lenstr;
if (!tvb_reported_length_remaining(tvb, offset)) return offset;
if (conn_data->clnt_caps & MYSQL_CAPS_SC) {
lenstr = tvb_get_guint8(tvb, offset);
offset += 1;
} else {
lenstr = my_tvb_strsize(tvb, offset);
}
if (tree && lenstr > 1) {
proto_tree_add_item(login_tree, hf_mysql_passwd, tvb, offset, lenstr, ENC_NA);
}
offset += lenstr;
if (conn_data->clnt_caps & MYSQL_CAPS_CD)
{
lenstr= my_tvb_strsize(tvb,offset);
if(lenstr<0){
return offset;
}
col_append_fstr(pinfo->cinfo, COL_INFO, " db=%s", tvb_get_string_enc(wmem_packet_scope(), tvb, offset, lenstr, ENC_ASCII|ENC_NA));
proto_tree_add_item(login_tree, hf_mysql_schema, tvb, offset, lenstr, ENC_ASCII|ENC_NA);
offset += lenstr;
}
if (conn_data->clnt_caps_ext & MYSQL_CAPS_PA)
{
lenstr= my_tvb_strsize(tvb,offset);
proto_tree_add_item(login_tree, hf_mysql_client_auth_plugin, tvb, offset, lenstr, ENC_ASCII|ENC_NA);
offset += lenstr;
}
if (conn_data->clnt_caps_ext & MYSQL_CAPS_CA)
{
proto_tree *connattrs_tree;
int lenfle;
guint64 connattrs_length;
int length;
lenfle = tvb_get_fle(tvb, offset, &connattrs_length, NULL);
tf = proto_tree_add_item(login_tree, hf_mysql_connattrs, tvb, offset, (guint32)connattrs_length, ENC_NA);
connattrs_tree = proto_item_add_subtree(tf, ett_connattrs);
proto_tree_add_uint64(connattrs_tree, hf_mysql_connattrs_length, tvb, offset, lenfle, connattrs_length);
offset += lenfle;
while (connattrs_length > 0) {
length = add_connattrs_entry_to_tree(tvb, pinfo, connattrs_tree, offset);
offset += length;
connattrs_length -= length;
}
}
return offset;
}
static void
mysql_dissect_exec_string(tvbuff_t *tvb, int *param_offset, proto_item *field_tree)
{
guint32 param_len32;
guint8 param_len;
param_len = tvb_get_guint8(tvb, *param_offset);
switch (param_len) {
case 0xfc:
*param_offset += 1;
param_len32 = tvb_get_letohs(tvb, *param_offset);
proto_tree_add_item(field_tree, hf_mysql_exec_field_string,
tvb, *param_offset, 2, ENC_ASCII | ENC_LITTLE_ENDIAN);
*param_offset += param_len32 + 2;
break;
case 0xfd:
*param_offset += 1;
param_len32 = tvb_get_letoh24(tvb, *param_offset);
proto_tree_add_item(field_tree, hf_mysql_exec_field_string,
tvb, *param_offset, 3, ENC_ASCII | ENC_LITTLE_ENDIAN);
*param_offset += param_len32 + 3;
break;
default:
proto_tree_add_item(field_tree, hf_mysql_exec_field_string,
tvb, *param_offset, 1, ENC_ASCII | ENC_NA);
*param_offset += param_len + 1;
break;
}
}
static void
mysql_dissect_exec_time(tvbuff_t *tvb, int *param_offset, proto_item *field_tree)
{
guint8 param_len;
param_len = tvb_get_guint8(tvb, *param_offset);
proto_tree_add_item(field_tree, hf_mysql_exec_field_time_length,
tvb, *param_offset, 1, ENC_NA);
*param_offset += 1;
if (param_len >= 1) {
proto_tree_add_item(field_tree, hf_mysql_exec_field_time_sign,
tvb, *param_offset, 1, ENC_NA);
}
if (param_len >= 5) {
proto_tree_add_item(field_tree, hf_mysql_exec_field_time_days,
tvb, *param_offset + 1, 4, ENC_LITTLE_ENDIAN);
}
if (param_len >= 8) {
proto_tree_add_item(field_tree, hf_mysql_exec_field_hour,
tvb, *param_offset + 5, 1, ENC_NA);
proto_tree_add_item(field_tree, hf_mysql_exec_field_minute,
tvb, *param_offset + 6, 1, ENC_NA);
proto_tree_add_item(field_tree, hf_mysql_exec_field_second,
tvb, *param_offset + 7, 1, ENC_NA);
}
if (param_len >= 12) {
proto_tree_add_item(field_tree, hf_mysql_exec_field_second_b,
tvb, *param_offset + 8, 4, ENC_LITTLE_ENDIAN);
}
*param_offset += param_len;
}
static void
mysql_dissect_exec_datetime(tvbuff_t *tvb, int *param_offset, proto_item *field_tree)
{
guint8 param_len;
param_len = tvb_get_guint8(tvb, *param_offset);
proto_tree_add_item(field_tree, hf_mysql_exec_field_datetime_length,
tvb, *param_offset, 1, ENC_NA);
*param_offset += 1;
if (param_len >= 2) {
proto_tree_add_item(field_tree, hf_mysql_exec_field_year,
tvb, *param_offset, 2, ENC_LITTLE_ENDIAN);
}
if (param_len >= 4) {
proto_tree_add_item(field_tree, hf_mysql_exec_field_month,
tvb, *param_offset + 2, 1, ENC_NA);
proto_tree_add_item(field_tree, hf_mysql_exec_field_day,
tvb, *param_offset + 3, 1, ENC_NA);
}
if (param_len >= 7) {
proto_tree_add_item(field_tree, hf_mysql_exec_field_hour,
tvb, *param_offset + 4, 1, ENC_NA);
proto_tree_add_item(field_tree, hf_mysql_exec_field_minute,
tvb, *param_offset + 5, 1, ENC_NA);
proto_tree_add_item(field_tree, hf_mysql_exec_field_second,
tvb, *param_offset + 6, 1, ENC_NA);
}
if (param_len >= 11) {
proto_tree_add_item(field_tree, hf_mysql_exec_field_second_b,
tvb, *param_offset + 7, 4, ENC_LITTLE_ENDIAN);
}
*param_offset += param_len;
}
static void
mysql_dissect_exec_primitive(tvbuff_t *tvb, int *param_offset,
proto_item *field_tree, const int hfindex,
const int offset)
{
proto_tree_add_item(field_tree, hfindex, tvb,
*param_offset, offset, ENC_LITTLE_ENDIAN);
*param_offset += offset;
}
static void
mysql_dissect_exec_tiny(tvbuff_t *tvb, int *param_offset, proto_item *field_tree)
{
mysql_dissect_exec_primitive(tvb, param_offset, field_tree, hf_mysql_exec_field_tiny, 1);
}
static void
mysql_dissect_exec_short(tvbuff_t *tvb, int *param_offset, proto_item *field_tree)
{
mysql_dissect_exec_primitive(tvb, param_offset, field_tree, hf_mysql_exec_field_short, 2);
}
static void
mysql_dissect_exec_long(tvbuff_t *tvb, int *param_offset, proto_item *field_tree)
{
mysql_dissect_exec_primitive(tvb, param_offset, field_tree, hf_mysql_exec_field_long, 4);
}
static void
mysql_dissect_exec_float(tvbuff_t *tvb, int *param_offset, proto_item *field_tree)
{
mysql_dissect_exec_primitive(tvb, param_offset, field_tree, hf_mysql_exec_field_float, 4);
}
static void
mysql_dissect_exec_double(tvbuff_t *tvb, int *param_offset, proto_item *field_tree)
{
mysql_dissect_exec_primitive(tvb, param_offset, field_tree, hf_mysql_exec_field_double, 8);
}
static void
mysql_dissect_exec_longlong(tvbuff_t *tvb, int *param_offset, proto_item *field_tree)
{
mysql_dissect_exec_primitive(tvb, param_offset, field_tree, hf_mysql_exec_field_longlong, 8);
}
static void
mysql_dissect_exec_null(tvbuff_t *tvb _U_, int *param_offset _U_, proto_item *field_tree _U_)
{}
static char
mysql_dissect_exec_param(proto_item *req_tree, tvbuff_t *tvb, int *offset,
int *param_offset, guint8 param_flags,
packet_info *pinfo)
{
guint8 param_type, param_unsigned;
proto_item *tf;
proto_item *field_tree;
int dissector_index = 0;
tf = proto_tree_add_item(req_tree, hf_mysql_exec_param, tvb, *offset, 2, ENC_NA);
field_tree = proto_item_add_subtree(tf, ett_stat);
proto_tree_add_item(field_tree, hf_mysql_fld_type, tvb, *offset, 1, ENC_NA);
param_type = tvb_get_guint8(tvb, *offset);
*offset += 1;
proto_tree_add_item(field_tree, hf_mysql_exec_unsigned, tvb, *offset, 1, ENC_NA);
param_unsigned = tvb_get_guint8(tvb, *offset);
*offset += 1;
if ((param_flags & MYSQL_PARAM_FLAG_STREAMED) == MYSQL_PARAM_FLAG_STREAMED) {
expert_add_info(pinfo, field_tree, &ei_mysql_streamed_param);
return 1;
}
while (mysql_exec_dissectors[dissector_index].dissector != NULL) {
if (mysql_exec_dissectors[dissector_index].type == param_type &&
mysql_exec_dissectors[dissector_index].unsigned_flag == param_unsigned) {
mysql_exec_dissectors[dissector_index].dissector(tvb, param_offset, field_tree);
return 1;
}
dissector_index++;
}
return 0;
}
static int
mysql_dissect_request(tvbuff_t *tvb,packet_info *pinfo, int offset,
proto_tree *tree, mysql_conn_data_t *conn_data)
{
gint opcode;
gint lenstr;
proto_item *tf = NULL, *ti;
proto_item *req_tree;
guint32 stmt_id;
my_stmt_data_t *stmt_data;
int stmt_pos, param_offset;
tf = proto_tree_add_item(tree, hf_mysql_request, tvb, offset, 1, ENC_NA);
req_tree = proto_item_add_subtree(tf, ett_request);
opcode = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", val_to_str(opcode, mysql_command_vals, "Unknown (%u)"));
proto_tree_add_item(req_tree, hf_mysql_command, tvb, offset, 1, ENC_NA);
proto_item_append_text(tf, " %s", val_to_str(opcode, mysql_command_vals, "Unknown (%u)"));
offset += 1;
switch (opcode) {
case MYSQL_QUIT:
break;
case MYSQL_PROCESS_INFO:
conn_data->state = RESPONSE_TABULAR;
break;
case MYSQL_DEBUG:
case MYSQL_PING:
conn_data->state = RESPONSE_OK;
break;
case MYSQL_STATISTICS:
conn_data->state = RESPONSE_MESSAGE;
break;
case MYSQL_INIT_DB:
case MYSQL_CREATE_DB:
case MYSQL_DROP_DB:
lenstr = my_tvb_strsize(tvb, offset);
proto_tree_add_item(req_tree, hf_mysql_schema, tvb, offset, lenstr, ENC_ASCII|ENC_NA);
offset += lenstr;
conn_data->state = RESPONSE_OK;
break;
case MYSQL_QUERY:
lenstr = my_tvb_strsize(tvb, offset);
proto_tree_add_item(req_tree, hf_mysql_query, tvb, offset, lenstr, ENC_ASCII|ENC_NA);
if (mysql_showquery) {
col_append_fstr(pinfo->cinfo, COL_INFO, " { %s } ", tvb_get_string_enc(wmem_packet_scope(), tvb, offset, lenstr, ENC_ASCII|ENC_NA));
}
offset += lenstr;
conn_data->state = RESPONSE_TABULAR;
break;
case MYSQL_STMT_PREPARE:
lenstr = my_tvb_strsize(tvb, offset);
proto_tree_add_item(req_tree, hf_mysql_query, tvb, offset, lenstr, ENC_ASCII|ENC_NA);
offset += lenstr;
conn_data->state = RESPONSE_PREPARE;
break;
case MYSQL_STMT_CLOSE:
proto_tree_add_item(req_tree, hf_mysql_stmt_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
conn_data->state = REQUEST;
break;
case MYSQL_STMT_RESET:
proto_tree_add_item(req_tree, hf_mysql_stmt_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
conn_data->state = RESPONSE_OK;
break;
case MYSQL_FIELD_LIST:
lenstr = my_tvb_strsize(tvb, offset);
proto_tree_add_item(req_tree, hf_mysql_table_name, tvb, offset, lenstr, ENC_ASCII|ENC_NA);
offset += lenstr;
conn_data->state = RESPONSE_SHOW_FIELDS;
break;
case MYSQL_PROCESS_KILL:
proto_tree_add_item(req_tree, hf_mysql_thd_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
conn_data->state = RESPONSE_OK;
break;
case MYSQL_CHANGE_USER:
lenstr = tvb_strsize(tvb, offset);
proto_tree_add_item(req_tree, hf_mysql_user, tvb, offset, lenstr, ENC_ASCII|ENC_NA);
offset += lenstr;
if (conn_data->clnt_caps & MYSQL_CAPS_SC) {
lenstr = tvb_get_guint8(tvb, offset);
offset += 1;
} else {
lenstr = tvb_strsize(tvb, offset);
}
proto_tree_add_item(req_tree, hf_mysql_passwd, tvb, offset, lenstr, ENC_NA);
offset += lenstr;
lenstr = my_tvb_strsize(tvb, offset);
proto_tree_add_item(req_tree, hf_mysql_schema, tvb, offset, lenstr, ENC_ASCII|ENC_NA);
offset += lenstr;
if (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(req_tree, hf_mysql_charset, tvb, offset, 1, ENC_NA);
offset += 2;
}
if (conn_data->clnt_caps_ext & MYSQL_CAPS_PA)
{
lenstr= my_tvb_strsize(tvb,offset);
proto_tree_add_item(req_tree, hf_mysql_client_auth_plugin, tvb, offset, lenstr, ENC_ASCII|ENC_NA);
offset += lenstr;
}
if (conn_data->clnt_caps_ext & MYSQL_CAPS_CA)
{
proto_tree *connattrs_tree;
int lenfle;
guint64 connattrs_length;
int length;
lenfle = tvb_get_fle(tvb, offset, &connattrs_length, NULL);
tf = proto_tree_add_item(req_tree, hf_mysql_connattrs, tvb, offset, (guint32)connattrs_length, ENC_NA);
connattrs_tree = proto_item_add_subtree(tf, ett_connattrs);
proto_tree_add_uint64(connattrs_tree, hf_mysql_connattrs_length, tvb, offset, lenfle, connattrs_length);
offset += lenfle;
while (connattrs_length > 0) {
length = add_connattrs_entry_to_tree(tvb, pinfo, connattrs_tree, offset);
offset += length;
connattrs_length -= length;
}
}
conn_data->state= RESPONSE_OK;
break;
case MYSQL_REFRESH:
{
proto_item *tff;
proto_item *rfsh_tree;
tff = proto_tree_add_item(req_tree, hf_mysql_refresh, tvb, offset, 1, ENC_NA);
rfsh_tree = proto_item_add_subtree(tff, ett_refresh);
proto_tree_add_item(rfsh_tree, hf_mysql_rfsh_grants, tvb, offset, 1, ENC_NA);
proto_tree_add_item(rfsh_tree, hf_mysql_rfsh_log, tvb, offset, 1, ENC_NA);
proto_tree_add_item(rfsh_tree, hf_mysql_rfsh_tables, tvb, offset, 1, ENC_NA);
proto_tree_add_item(rfsh_tree, hf_mysql_rfsh_hosts, tvb, offset, 1, ENC_NA);
proto_tree_add_item(rfsh_tree, hf_mysql_rfsh_status, tvb, offset, 1, ENC_NA);
proto_tree_add_item(rfsh_tree, hf_mysql_rfsh_threads, tvb, offset, 1, ENC_NA);
proto_tree_add_item(rfsh_tree, hf_mysql_rfsh_slave, tvb, offset, 1, ENC_NA);
proto_tree_add_item(rfsh_tree, hf_mysql_rfsh_master, tvb, offset, 1, ENC_NA);
}
offset += 1;
conn_data->state= RESPONSE_OK;
break;
case MYSQL_SHUTDOWN:
proto_tree_add_item(req_tree, hf_mysql_shutdown, tvb, offset, 1, ENC_NA);
offset += 1;
conn_data->state = RESPONSE_OK;
break;
case MYSQL_SET_OPTION:
proto_tree_add_item(req_tree, hf_mysql_option, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
conn_data->state = RESPONSE_OK;
break;
case MYSQL_STMT_FETCH:
proto_tree_add_item(req_tree, hf_mysql_stmt_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(req_tree, hf_mysql_num_rows, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
conn_data->state = RESPONSE_TABULAR;
break;
case MYSQL_STMT_SEND_LONG_DATA:
proto_tree_add_item(req_tree, hf_mysql_stmt_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
stmt_id = tvb_get_letohl(tvb, offset);
offset += 4;
stmt_data = (my_stmt_data_t *)wmem_tree_lookup32(conn_data->stmts, stmt_id);
if (stmt_data != NULL) {
guint16 data_param = tvb_get_letohs(tvb, offset);
if (stmt_data->nparam > data_param) {
stmt_data->param_flags[data_param] |= MYSQL_PARAM_FLAG_STREAMED;
}
}
proto_tree_add_item(req_tree, hf_mysql_param, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
lenstr = tvb_reported_length_remaining(tvb, offset);
if (tree && lenstr > 0) {
proto_tree_add_item(req_tree, hf_mysql_payload, tvb, offset, lenstr, ENC_NA);
}
offset += lenstr;
conn_data->state = REQUEST;
break;
case MYSQL_STMT_EXECUTE:
proto_tree_add_item(req_tree, hf_mysql_stmt_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
stmt_id = tvb_get_letohl(tvb, offset);
offset += 4;
if (conn_data->major_version >= 5) {
proto_tree_add_item(req_tree, hf_mysql_exec_flags5, tvb, offset, 1, ENC_NA);
} else {
proto_tree_add_item(req_tree, hf_mysql_exec_flags4, tvb, offset, 1, ENC_NA);
}
offset += 1;
proto_tree_add_item(req_tree, hf_mysql_exec_iter, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
stmt_data = (my_stmt_data_t *)wmem_tree_lookup32(conn_data->stmts, stmt_id);
if (stmt_data != NULL) {
if (stmt_data->nparam != 0) {
guint8 stmt_bound;
offset += (stmt_data->nparam + 7) / 8;
proto_tree_add_item(req_tree, hf_mysql_new_parameter_bound_flag, tvb, offset, 1, ENC_NA);
stmt_bound = tvb_get_guint8(tvb, offset);
offset += 1;
if (stmt_bound == 1) {
param_offset = offset + stmt_data->nparam * 2;
for (stmt_pos = 0; stmt_pos < stmt_data->nparam; stmt_pos++) {
if (!mysql_dissect_exec_param(req_tree, tvb, &offset, &param_offset,
stmt_data->param_flags[stmt_pos], pinfo))
break;
}
offset = param_offset;
}
}
} else {
lenstr = tvb_reported_length_remaining(tvb, offset);
if (tree && lenstr > 0) {
ti = proto_tree_add_item(req_tree, hf_mysql_payload, tvb, offset, lenstr, ENC_NA);
expert_add_info(pinfo, ti, &ei_mysql_prepare_response_needed);
}
offset += lenstr;
}
#if 0
#else
lenstr = tvb_reported_length_remaining(tvb, offset);
if (tree && lenstr > 0) {
ti = proto_tree_add_item(req_tree, hf_mysql_payload, tvb, offset, lenstr, ENC_NA);
expert_add_info_format(pinfo, ti, &ei_mysql_dissector_incomplete, "FIXME: execute dissector incomplete");
}
offset += lenstr;
#endif
conn_data->state= RESPONSE_TABULAR;
break;
case MYSQL_BINLOG_DUMP:
proto_tree_add_item(req_tree, hf_mysql_binlog_position, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(req_tree, hf_mysql_binlog_flags, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(req_tree, hf_mysql_binlog_server_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
lenstr = tvb_reported_length_remaining(tvb, offset);
if (tree && lenstr > 0) {
proto_tree_add_item(req_tree, hf_mysql_binlog_file_name, tvb, offset, lenstr, ENC_ASCII|ENC_NA);
}
offset += lenstr;
conn_data->state = REQUEST;
break;
case MYSQL_TABLE_DUMP:
case MYSQL_CONNECT_OUT:
case MYSQL_REGISTER_SLAVE:
ti = proto_tree_add_item(req_tree, hf_mysql_payload, tvb, offset, -1, ENC_NA);
expert_add_info_format(pinfo, ti, &ei_mysql_dissector_incomplete, "FIXME: implement replication packets");
offset += tvb_reported_length_remaining(tvb, offset);
conn_data->state = REQUEST;
break;
default:
ti = proto_tree_add_item(req_tree, hf_mysql_payload, tvb, offset, -1, ENC_NA);
expert_add_info(pinfo, ti, &ei_mysql_command);
offset += tvb_reported_length_remaining(tvb, offset);
conn_data->state = UNDEFINED;
}
return offset;
}
static int
mysql_dissect_response(tvbuff_t *tvb, packet_info *pinfo, int offset,
proto_tree *tree, mysql_conn_data_t *conn_data)
{
gint response_code;
gint lenstr;
proto_item *ti;
guint16 server_status = 0;
response_code = tvb_get_guint8(tvb, offset);
if (response_code == 0xff ) {
offset = mysql_dissect_error_packet(tvb, pinfo, offset+1, tree);
conn_data->state= REQUEST;
}
else if (response_code == 0xfe && tvb_reported_length_remaining(tvb, offset) < 9) {
ti = proto_tree_add_item(tree, hf_mysql_eof, tvb, offset, 1, ENC_NA);
offset += 1;
if (tvb_reported_length_remaining(tvb, offset)) {
proto_tree_add_item(tree, hf_mysql_num_warn, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset = mysql_dissect_server_status(tvb, offset+2, tree, &server_status);
}
if (conn_data->state == FIELD_PACKET) {
conn_data->state= ROW_PACKET;
} else if (conn_data->state == ROW_PACKET) {
if (server_status & MYSQL_STAT_MU) {
conn_data->state= RESPONSE_TABULAR;
} else {
conn_data->state= REQUEST;
}
} else if (conn_data->state == PREPARED_PARAMETERS) {
if (conn_data->stmt_num_fields > 0) {
conn_data->state= PREPARED_FIELDS;
} else {
conn_data->state= REQUEST;
}
} else if (conn_data->state == PREPARED_FIELDS) {
conn_data->state= REQUEST;
} else {
conn_data->state= REQUEST;
expert_add_info(pinfo, ti, &ei_mysql_eof);
}
}
else if (response_code == 0) {
if (conn_data->state == RESPONSE_PREPARE) {
offset = mysql_dissect_response_prepare(tvb, offset, tree, conn_data);
} else if (tvb_reported_length_remaining(tvb, offset+1) > tvb_get_fle(tvb, offset+1, NULL, NULL)) {
offset = mysql_dissect_ok_packet(tvb, pinfo, offset+1, tree, conn_data);
} else {
offset = mysql_dissect_result_header(tvb, pinfo, offset, tree, conn_data);
}
}
else {
switch (conn_data->state) {
case RESPONSE_MESSAGE:
if ((lenstr = tvb_reported_length_remaining(tvb, offset))) {
proto_tree_add_item(tree, hf_mysql_message, tvb, offset, lenstr, ENC_ASCII|ENC_NA);
offset += lenstr;
}
conn_data->state = REQUEST;
break;
case RESPONSE_TABULAR:
offset = mysql_dissect_result_header(tvb, pinfo, offset, tree, conn_data);
break;
case FIELD_PACKET:
case RESPONSE_SHOW_FIELDS:
case RESPONSE_PREPARE:
case PREPARED_PARAMETERS:
offset = mysql_dissect_field_packet(tvb, offset, tree, conn_data);
break;
case ROW_PACKET:
offset = mysql_dissect_row_packet(tvb, offset, tree);
break;
case PREPARED_FIELDS:
offset = mysql_dissect_field_packet(tvb, offset, tree, conn_data);
break;
default:
ti = proto_tree_add_item(tree, hf_mysql_payload, tvb, offset, -1, ENC_NA);
expert_add_info(pinfo, ti, &ei_mysql_unknown_response);
offset += tvb_reported_length_remaining(tvb, offset);
conn_data->state = UNDEFINED;
}
}
return offset;
}
static int
mysql_dissect_error_packet(tvbuff_t *tvb, packet_info *pinfo,
int offset, proto_tree *tree)
{
col_append_fstr(pinfo->cinfo, COL_INFO, " Error %d", tvb_get_letohs(tvb, offset));
proto_tree_add_item(tree, hf_mysql_error_code, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (tvb_get_guint8(tvb, offset) == '#')
{
offset += 1;
proto_tree_add_item(tree, hf_mysql_sqlstate, tvb, offset, 5, ENC_ASCII|ENC_NA);
offset += 5;
}
proto_tree_add_item(tree, hf_mysql_error_string, tvb, offset, -1, ENC_ASCII|ENC_NA);
offset += tvb_reported_length_remaining(tvb, offset);
return offset;
}
static int
add_session_tracker_entry_to_tree(tvbuff_t *tvb, packet_info *pinfo, proto_item *tree, int offset) {
guint8 data_type;
guint64 length;
guint64 lenstr;
int orig_offset = offset, lenfle;
proto_item *item, *ti;
proto_tree *session_track_tree;
ti = proto_tree_add_item(tree, hf_mysql_session_track, tvb, offset, 1, ENC_NA);
session_track_tree = proto_item_add_subtree(ti, ett_session_track);
proto_tree_add_item(session_track_tree, hf_mysql_session_track_type, tvb, offset, 1, ENC_BIG_ENDIAN);
data_type = tvb_get_guint8(tvb, offset);
offset += 1;
lenfle = tvb_get_fle(tvb, offset, &length, NULL);
proto_tree_add_uint64(session_track_tree, hf_mysql_session_track_length, tvb, offset, lenfle, length);
offset += lenfle;
switch (data_type) {
case 0:
lenfle = tvb_get_fle(tvb, offset, &lenstr, NULL);
proto_tree_add_uint64(session_track_tree, hf_mysql_session_track_sysvar_length, tvb, offset, lenfle, lenstr);
offset += lenfle;
proto_tree_add_item(session_track_tree, hf_mysql_session_track_sysvar_name, tvb, offset, (gint)lenstr, ENC_ASCII|ENC_NA);
offset += (int)lenstr;
lenfle = tvb_get_fle(tvb, offset, &lenstr, NULL);
proto_tree_add_uint64(session_track_tree, hf_mysql_session_track_sysvar_length, tvb, offset, lenfle, lenstr);
offset += lenfle;
proto_tree_add_item(session_track_tree, hf_mysql_session_track_sysvar_value, tvb, offset, (gint)lenstr, ENC_ASCII|ENC_NA);
offset += (int)lenstr;
break;
case 1:
lenfle = tvb_get_fle(tvb, offset, &lenstr, NULL);
proto_tree_add_uint64(session_track_tree, hf_mysql_session_track_schema_length, tvb, offset, lenfle, lenstr);
offset += lenfle;
proto_tree_add_item(session_track_tree, hf_mysql_session_track_schema, tvb, offset, (gint)lenstr, ENC_ASCII|ENC_NA);
offset += (int)lenstr;
break;
case 2:
proto_tree_add_item(session_track_tree, hf_mysql_session_state_change, tvb, offset, 1, ENC_ASCII|ENC_NA);
offset++;
break;
default:
item = proto_tree_add_item(session_track_tree, hf_mysql_payload, tvb, offset, (gint)length, ENC_NA);
expert_add_info_format(pinfo, item, &ei_mysql_dissector_incomplete, "FIXME: unrecognized session tracker data");
offset += (int)length;
}
proto_item_set_len(ti, offset - orig_offset);
return (offset - orig_offset);
}
static int
mysql_dissect_ok_packet(tvbuff_t *tvb, packet_info *pinfo, int offset,
proto_tree *tree, mysql_conn_data_t *conn_data)
{
guint64 lenstr;
guint64 affected_rows;
guint64 insert_id;
int fle;
guint16 server_status = 0;
col_append_str(pinfo->cinfo, COL_INFO, " OK" );
fle = tvb_get_fle(tvb, offset, &affected_rows, NULL);
proto_tree_add_uint64(tree, hf_mysql_affected_rows, tvb, offset, fle, affected_rows);
offset += fle;
fle= tvb_get_fle(tvb, offset, &insert_id, NULL);
if (tree && insert_id) {
proto_tree_add_uint64(tree, hf_mysql_insert_id, tvb, offset, fle, insert_id);
}
offset += fle;
if (tvb_reported_length_remaining(tvb, offset) > 0) {
offset = mysql_dissect_server_status(tvb, offset, tree, &server_status);
if (conn_data->clnt_caps & conn_data->srv_caps & MYSQL_CAPS_CU) {
proto_tree_add_item(tree, hf_mysql_num_warn, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
}
if (conn_data->clnt_caps_ext & MYSQL_CAPS_ST) {
guint64 session_track_length;
proto_item *tf;
proto_item *session_track_tree = NULL;
int length;
offset += tvb_get_fle(tvb, offset, &lenstr, NULL);
if (lenstr) {
proto_tree_add_item(tree, hf_mysql_message, tvb, offset, (gint)lenstr, ENC_ASCII|ENC_NA);
offset += (int)lenstr;
}
if (server_status & MYSQL_STAT_SESSION_STATE_CHANGED) {
fle = tvb_get_fle(tvb, offset, &session_track_length, NULL);
tf = proto_tree_add_item(tree, hf_mysql_session_track_data, tvb, offset, -1, ENC_NA);
session_track_tree = proto_item_add_subtree(tf, ett_session_track_data);
proto_tree_add_uint64(tf, hf_mysql_session_track_data_length, tvb, offset, fle, session_track_length);
offset += fle;
while (session_track_length > 0) {
length = add_session_tracker_entry_to_tree(tvb, pinfo, session_track_tree, offset);
offset += length;
session_track_length -= length;
}
}
} else {
if (tvb_reported_length_remaining(tvb, offset) > 0) {
lenstr = tvb_reported_length_remaining(tvb, offset);
proto_tree_add_item(tree, hf_mysql_message, tvb, offset, (gint)lenstr, ENC_ASCII|ENC_NA);
offset += (int)lenstr;
}
}
conn_data->state = REQUEST;
return offset;
}
static int
mysql_dissect_server_status(tvbuff_t *tvb, int offset, proto_tree *tree, guint16 *server_status)
{
proto_item *tf;
proto_item *stat_tree;
if (server_status) {
*server_status = tvb_get_letohs(tvb, offset);
}
if (tree) {
tf= proto_tree_add_item(tree, hf_mysql_server_status, tvb, offset, 2, ENC_LITTLE_ENDIAN);
stat_tree= proto_item_add_subtree(tf, ett_stat);
proto_tree_add_item(stat_tree, hf_mysql_stat_it, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(stat_tree, hf_mysql_stat_ac, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(stat_tree, hf_mysql_stat_mr, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(stat_tree, hf_mysql_stat_mu, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(stat_tree, hf_mysql_stat_bi, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(stat_tree, hf_mysql_stat_ni, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(stat_tree, hf_mysql_stat_cr, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(stat_tree, hf_mysql_stat_lr, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(stat_tree, hf_mysql_stat_dr, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(stat_tree, hf_mysql_stat_bs, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(stat_tree, hf_mysql_stat_session_state_changed, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(stat_tree, hf_mysql_stat_query_was_slow, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(stat_tree, hf_mysql_stat_ps_out_params, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
offset += 2;
return offset;
}
static int
mysql_dissect_caps_server(tvbuff_t *tvb, int offset, proto_tree *tree, guint16 *caps)
{
proto_item *tf;
proto_item *cap_tree;
*caps= tvb_get_letohs(tvb, offset);
if (tree) {
tf = proto_tree_add_item(tree, hf_mysql_caps_server, tvb, offset, 2, ENC_LITTLE_ENDIAN);
cap_tree= proto_item_add_subtree(tf, ett_caps);
proto_tree_add_item(cap_tree, hf_mysql_cap_long_password, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_mysql_cap_found_rows, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_mysql_cap_long_flag, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_mysql_cap_connect_with_db, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_mysql_cap_no_schema, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_mysql_cap_compress, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_mysql_cap_odbc, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_mysql_cap_local_files, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_mysql_cap_ignore_space, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_mysql_cap_change_user, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_mysql_cap_interactive, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_mysql_cap_ssl, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_mysql_cap_ignore_sigpipe, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_mysql_cap_transactions, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_mysql_cap_reserved, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_mysql_cap_secure_connect, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
offset += 2;
return offset;
}
static int
mysql_dissect_caps_client(tvbuff_t *tvb, int offset, proto_tree *tree, guint16 *caps)
{
proto_item *tf;
proto_item *cap_tree;
*caps= tvb_get_letohs(tvb, offset);
if (tree) {
tf = proto_tree_add_item(tree, hf_mysql_caps_client, tvb, offset, 2, ENC_LITTLE_ENDIAN);
cap_tree= proto_item_add_subtree(tf, ett_caps);
proto_tree_add_item(cap_tree, hf_mysql_cap_long_password, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_mysql_cap_found_rows, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_mysql_cap_long_flag, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_mysql_cap_connect_with_db, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_mysql_cap_no_schema, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_mysql_cap_compress, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_mysql_cap_odbc, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_mysql_cap_local_files, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_mysql_cap_ignore_space, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_mysql_cap_change_user, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_mysql_cap_interactive, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_mysql_cap_ssl, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_mysql_cap_ignore_sigpipe, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_mysql_cap_transactions, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_mysql_cap_reserved, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cap_tree, hf_mysql_cap_secure_connect, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
offset += 2;
return offset;
}
static int
mysql_dissect_ext_caps_client(tvbuff_t *tvb, int offset, proto_tree *tree, guint16 *ext_caps)
{
proto_item *tf;
proto_item *extcap_tree;
*ext_caps= tvb_get_letohs(tvb, offset);
if (tree) {
tf = proto_tree_add_item(tree, hf_mysql_extcaps_client, tvb, offset, 2, ENC_LITTLE_ENDIAN);
extcap_tree = proto_item_add_subtree(tf, ett_extcaps);
proto_tree_add_item(extcap_tree, hf_mysql_cap_multi_statements, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(extcap_tree, hf_mysql_cap_multi_results, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(extcap_tree, hf_mysql_cap_ps_multi_results, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(extcap_tree, hf_mysql_cap_plugin_auth, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(extcap_tree, hf_mysql_cap_connect_attrs, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(extcap_tree, hf_mysql_cap_plugin_auth_lenenc_client_data, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(extcap_tree, hf_mysql_cap_client_can_handle_expired_passwords, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(extcap_tree, hf_mysql_cap_session_track, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(extcap_tree, hf_mysql_cap_unused, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
offset += 2;
return offset;
}
static int
mysql_dissect_result_header(tvbuff_t *tvb, packet_info *pinfo, int offset,
proto_tree *tree, mysql_conn_data_t *conn_data)
{
gint fle;
guint64 num_fields, extra;
col_append_str(pinfo->cinfo, COL_INFO, " TABULAR" );
fle = tvb_get_fle(tvb, offset, &num_fields, NULL);
proto_tree_add_uint64(tree, hf_mysql_num_fields, tvb, offset, fle, num_fields);
offset += fle;
if (tvb_reported_length_remaining(tvb, offset)) {
fle = tvb_get_fle(tvb, offset, &extra, NULL);
proto_tree_add_uint64(tree, hf_mysql_extra, tvb, offset, fle, extra);
offset += fle;
}
if (num_fields) {
conn_data->state = FIELD_PACKET;
} else {
conn_data->state = ROW_PACKET;
}
return offset;
}
static int
mysql_field_add_lestring(tvbuff_t *tvb, int offset, proto_tree *tree, int field)
{
guint64 lelen;
guint8 is_null;
offset += tvb_get_fle(tvb, offset, &lelen, &is_null);
if(is_null)
proto_tree_add_string(tree, field, tvb, offset, 4, "NULL");
else
{
proto_tree_add_item(tree, field, tvb, offset, (int)lelen, ENC_NA);
if (offset + (int)lelen < offset) {
offset = tvb_reported_length(tvb);
}
else {
offset += (int)lelen;
}
}
return offset;
}
static int
mysql_dissect_field_packet(tvbuff_t *tvb, int offset, proto_tree *tree, mysql_conn_data_t *conn_data _U_)
{
proto_item *tf;
proto_item *flags_tree;
offset = mysql_field_add_lestring(tvb, offset, tree, hf_mysql_fld_catalog);
offset = mysql_field_add_lestring(tvb, offset, tree, hf_mysql_fld_db);
offset = mysql_field_add_lestring(tvb, offset, tree, hf_mysql_fld_table);
offset = mysql_field_add_lestring(tvb, offset, tree, hf_mysql_fld_org_table);
offset = mysql_field_add_lestring(tvb, offset, tree, hf_mysql_fld_name);
offset = mysql_field_add_lestring(tvb, offset, tree, hf_mysql_fld_org_name);
offset +=1;
proto_tree_add_item(tree, hf_mysql_fld_charsetnr, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mysql_fld_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mysql_fld_type, tvb, offset, 1, ENC_NA);
offset += 1;
tf = proto_tree_add_item(tree, hf_mysql_fld_flags, tvb, offset, 2, ENC_LITTLE_ENDIAN);
flags_tree = proto_item_add_subtree(tf, ett_field_flags);
proto_tree_add_item(flags_tree, hf_mysql_fld_not_null, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(flags_tree, hf_mysql_fld_primary_key, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(flags_tree, hf_mysql_fld_unique_key, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(flags_tree, hf_mysql_fld_multiple_key, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(flags_tree, hf_mysql_fld_blob, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(flags_tree, hf_mysql_fld_unsigned, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(flags_tree, hf_mysql_fld_zero_fill, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(flags_tree, hf_mysql_fld_binary, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(flags_tree, hf_mysql_fld_enum, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(flags_tree, hf_mysql_fld_auto_increment, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(flags_tree, hf_mysql_fld_timestamp, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(flags_tree, hf_mysql_fld_set, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mysql_fld_decimals, tvb, offset, 1, ENC_NA);
offset += 1;
offset += 2;
if (tree && tvb_reported_length_remaining(tvb, offset) > 0) {
offset = mysql_field_add_lestring(tvb, offset, tree, hf_mysql_fld_default);
}
return offset;
}
static int
mysql_dissect_row_packet(tvbuff_t *tvb, int offset, proto_tree *tree)
{
while (tvb_reported_length_remaining(tvb, offset) > 0) {
offset = mysql_field_add_lestring(tvb, offset, tree, hf_mysql_row_text);
}
return offset;
}
static int
mysql_dissect_response_prepare(tvbuff_t *tvb, int offset, proto_tree *tree, mysql_conn_data_t *conn_data)
{
my_stmt_data_t *stmt_data;
guint32 stmt_id;
int flagsize;
offset += 1;
proto_tree_add_item(tree, hf_mysql_stmt_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
stmt_id = tvb_get_letohl(tvb, offset);
offset += 4;
proto_tree_add_item(tree, hf_mysql_num_fields, tvb, offset, 2, ENC_LITTLE_ENDIAN);
conn_data->stmt_num_fields = tvb_get_letohs(tvb, offset);
offset += 2;
proto_tree_add_item(tree, hf_mysql_num_params, tvb, offset, 2, ENC_LITTLE_ENDIAN);
conn_data->stmt_num_params = tvb_get_letohs(tvb, offset);
stmt_data = wmem_new(wmem_file_scope(), struct my_stmt_data);
stmt_data->nparam = conn_data->stmt_num_params;
flagsize = (int)(sizeof(guint8) * stmt_data->nparam);
stmt_data->param_flags = (guint8 *)wmem_alloc(wmem_file_scope(), flagsize);
memset(stmt_data->param_flags, 0, flagsize);
wmem_tree_insert32(conn_data->stmts, stmt_id, stmt_data);
offset += 2;
offset += 1;
proto_tree_add_item(tree, hf_mysql_num_warn, tvb, offset, 2, ENC_LITTLE_ENDIAN);
if (conn_data->stmt_num_params > 0)
conn_data->state = PREPARED_PARAMETERS;
else if (conn_data->stmt_num_fields > 0)
conn_data->state = PREPARED_FIELDS;
else
conn_data->state = REQUEST;
return offset + tvb_reported_length_remaining(tvb, offset);
}
static gint
my_tvb_strsize(tvbuff_t *tvb, int offset)
{
gint len = tvb_strnlen(tvb, offset, -1);
if (len == -1) {
len = tvb_reported_length_remaining(tvb, offset);
} else {
len++;
}
return len;
}
static int
tvb_get_fle(tvbuff_t *tvb, int offset, guint64 *res, guint8 *is_null)
{
guint8 prefix;
prefix = tvb_get_guint8(tvb, offset);
if (is_null)
*is_null = 0;
switch (prefix) {
case 251:
if (res)
*res = 0;
if (is_null)
*is_null = 1;
break;
case 252:
if (res)
*res = tvb_get_letohs(tvb, offset+1);
return 3;
case 253:
if (res)
*res = tvb_get_letohl(tvb, offset+1);
return 5;
case 254:
if (res)
*res = tvb_get_letoh64(tvb, offset+1);
return 9;
default:
if (res)
*res = prefix;
}
return 1;
}
static guint
get_mysql_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
guint plen= tvb_get_letoh24(tvb, offset);
return plen + 4;
}
static int
dissect_mysql_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *mysql_tree= NULL;
proto_item *ti;
conversation_t *conversation;
int offset = 0;
guint packet_number;
gboolean is_response, is_ssl = FALSE;
mysql_conn_data_t *conn_data;
#ifdef CTDEBUG
mysql_state_t conn_state_in, conn_state_out, frame_state;
guint64 generation;
proto_item *pi;
#endif
struct mysql_frame_data *mysql_frame_data_p;
conversation= find_or_create_conversation(pinfo);
conn_data= (mysql_conn_data_t *)conversation_get_proto_data(conversation, proto_mysql);
if (!conn_data) {
conn_data= wmem_new(wmem_file_scope(), mysql_conn_data_t);
conn_data->srv_caps= 0;
conn_data->clnt_caps= 0;
conn_data->clnt_caps_ext= 0;
conn_data->state= UNDEFINED;
conn_data->stmts= wmem_tree_new(wmem_file_scope());
#ifdef CTDEBUG
conn_data->generation= 0;
#endif
conn_data->major_version= 0;
conn_data->frame_start_ssl= 0;
conversation_add_proto_data(conversation, proto_mysql, conn_data);
}
mysql_frame_data_p = (struct mysql_frame_data *)p_get_proto_data(wmem_file_scope(), pinfo, proto_mysql, 0);
if (!mysql_frame_data_p) {
mysql_frame_data_p = wmem_new(wmem_file_scope(), struct mysql_frame_data);
mysql_frame_data_p->state = conn_data->state;
p_add_proto_data(wmem_file_scope(), pinfo, proto_mysql, 0, mysql_frame_data_p);
} else if (conn_data->state != FIELD_PACKET && conn_data->state != ROW_PACKET ) {
conn_data->state= mysql_frame_data_p->state;
}
if (tree) {
ti = proto_tree_add_item(tree, proto_mysql, tvb, offset, -1, ENC_NA);
mysql_tree = proto_item_add_subtree(ti, ett_mysql);
proto_tree_add_item(mysql_tree, hf_mysql_packet_length, tvb, offset, 3, ENC_LITTLE_ENDIAN);
}
offset+= 3;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MySQL");
if (pinfo->destport == pinfo->match_uint) {
is_response= FALSE;
} else {
is_response= TRUE;
}
packet_number = tvb_get_guint8(tvb, offset);
proto_tree_add_item(mysql_tree, hf_mysql_packet_number, tvb, offset, 1, ENC_NA);
offset += 1;
#ifdef CTDEBUG
conn_state_in= conn_data->state;
frame_state = mysql_frame_data_p->state;
generation= conn_data->generation;
if (tree) {
pi = proto_tree_add_debug(mysql_tree, tvb, offset, 0, "conversation: %p", conversation);
PROTO_ITEM_SET_GENERATED(pi);
pi = proto_tree_add_debug(mysql_tree, tvb, offset, 0, "generation: %" G_GINT64_MODIFIER "d", generation);
PROTO_ITEM_SET_GENERATED(pi);
pi = proto_tree_add_debug(mysql_tree, tvb, offset, 0, "conn state: %s (%u)",
val_to_str(conn_state_in, state_vals, "Unknown (%u)"),
conn_state_in);
PROTO_ITEM_SET_GENERATED(pi);
pi = proto_tree_add_debug(mysql_tree, tvb, offset, 0, "frame state: %s (%u)",
val_to_str(frame_state, state_vals, "Unknown (%u)"),
frame_state);
PROTO_ITEM_SET_GENERATED(pi);
}
#endif
proto_get_frame_protocols(pinfo->layers, NULL, NULL, NULL, NULL, &is_ssl);
if (is_response) {
if (packet_number == 0 ) {
col_set_str(pinfo->cinfo, COL_INFO, "Server Greeting");
offset = mysql_dissect_greeting(tvb, pinfo, offset, mysql_tree, conn_data);
} else {
col_set_str(pinfo->cinfo, COL_INFO, "Response");
offset = mysql_dissect_response(tvb, pinfo, offset, mysql_tree, conn_data);
}
} else {
if (packet_number == 1 || (packet_number == 2 && is_ssl)) {
col_set_str(pinfo->cinfo, COL_INFO, "Login Request");
offset = mysql_dissect_login(tvb, pinfo, offset, mysql_tree, conn_data);
} else {
col_set_str(pinfo->cinfo, COL_INFO, "Request");
offset = mysql_dissect_request(tvb, pinfo, offset, mysql_tree, conn_data);
}
}
#ifdef CTDEBUG
conn_state_out= conn_data->state;
++(conn_data->generation);
pi = proto_tree_add_debug(mysql_tree, tvb, offset, 0, "next proto state: %s (%u)",
val_to_str(conn_state_out, state_vals, "Unknown (%u)"),
conn_state_out);
PROTO_ITEM_SET_GENERATED(pi);
#endif
if (tree && tvb_reported_length_remaining(tvb, offset) > 0) {
ti = proto_tree_add_item(mysql_tree, hf_mysql_payload, tvb, offset, -1, ENC_NA);
expert_add_info(pinfo, ti, &ei_mysql_dissector_incomplete);
}
return tvb_reported_length(tvb);
}
static int
dissect_mysql(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
gboolean is_ssl = FALSE;
conversation_t *conversation;
mysql_conn_data_t *conn_data;
proto_get_frame_protocols(pinfo->layers, NULL, NULL, NULL, NULL, &is_ssl);
conversation = find_or_create_conversation(pinfo);
conn_data = (mysql_conn_data_t *)conversation_get_proto_data(conversation, proto_mysql);
if(conn_data){
if(conn_data->frame_start_ssl && conn_data->frame_start_ssl < pinfo->fd->num && !(is_ssl)) {
call_dissector(ssl_handle, tvb, pinfo, tree);
return tvb_reported_length(tvb);
}
}
tcp_dissect_pdus(tvb, pinfo, tree, mysql_desegment, 3,
get_mysql_pdu_len, dissect_mysql_pdu, data);
return tvb_reported_length(tvb);
}
void proto_register_mysql(void)
{
static hf_register_info hf[]=
{
{ &hf_mysql_packet_length,
{ "Packet Length", "mysql.packet_length",
FT_UINT24, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_packet_number,
{ "Packet Number", "mysql.packet_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_request,
{ "Request Command", "mysql.request",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_command,
{ "Command", "mysql.command",
FT_UINT8, BASE_DEC, VALS(mysql_command_vals), 0x0,
NULL, HFILL }},
{ &hf_mysql_error_code,
{ "Error Code", "mysql.error_code",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_error_string,
{ "Error message", "mysql.error.message",
FT_STRING, BASE_NONE, NULL, 0x0,
"Error string in case of MySQL error message", HFILL }},
{ &hf_mysql_sqlstate,
{ "SQL state", "mysql.sqlstate",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_message,
{ "Message", "mysql.message",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_server_greeting,
{ "Server Greeting", "mysql.server_greeting",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_protocol,
{ "Protocol", "mysql.protocol",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Protocol Version", HFILL }},
{ &hf_mysql_version,
{ "Version", "mysql.version",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"MySQL Version", HFILL }},
{ &hf_mysql_session_track,
{ "Session Track", "mysql.session_track",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_session_track_type,
{ "Session tracking type", "mysql.session_track.type",
FT_UINT8, BASE_DEC, VALS(mysql_session_track_type_vals), 0x0,
NULL, HFILL }},
{ &hf_mysql_session_track_length,
{ "Session tracking length", "mysql.session_track.length",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_session_track_data,
{ "Session tracking data", "mysql.session_track.data",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_session_track_data_length,
{ "Session tracking data length", "mysql.session_track.data.length",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_session_track_sysvar_length,
{ "System variable change Length", "mysql.session_track.sysvar.length",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_session_track_sysvar_name,
{ "System variable change Name", "mysql.session_track.sysvar.name",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_session_track_sysvar_value,
{ "System variable change Value", "mysql.session_track.sysvar.value",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_session_track_schema_length,
{ "Schema change length", "mysql.session_track.schema.length",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_session_track_schema,
{ "Schema change", "mysql.session_track.schema",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_session_state_change,
{ "State change", "mysql.session_track.state_change",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_caps_server,
{ "Server Capabilities", "mysql.caps.server",
FT_UINT16, BASE_HEX, NULL, 0x0,
"MySQL Capabilities", HFILL }},
{ &hf_mysql_caps_client,
{ "Client Capabilities", "mysql.caps.client",
FT_UINT16, BASE_HEX, NULL, 0x0,
"MySQL Capabilities", HFILL }},
{ &hf_mysql_cap_long_password,
{ "Long Password","mysql.caps.lp",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_CAPS_LP,
NULL, HFILL }},
{ &hf_mysql_cap_found_rows,
{ "Found Rows","mysql.caps.fr",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_CAPS_FR,
NULL, HFILL }},
{ &hf_mysql_cap_long_flag,
{ "Long Column Flags","mysql.caps.lf",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_CAPS_LF,
NULL, HFILL }},
{ &hf_mysql_cap_connect_with_db,
{ "Connect With Database","mysql.caps.cd",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_CAPS_CD,
NULL, HFILL }},
{ &hf_mysql_cap_no_schema,
{ "Don't Allow database.table.column","mysql.caps.ns",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_CAPS_NS,
NULL, HFILL }},
{ &hf_mysql_cap_compress,
{ "Can use compression protocol","mysql.caps.cp",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_CAPS_CP,
NULL, HFILL }},
{ &hf_mysql_cap_odbc,
{ "ODBC Client","mysql.caps.ob",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_CAPS_OB,
NULL, HFILL }},
{ &hf_mysql_cap_local_files,
{ "Can Use LOAD DATA LOCAL","mysql.caps.li",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_CAPS_LI,
NULL, HFILL }},
{ &hf_mysql_cap_ignore_space,
{ "Ignore Spaces before '('","mysql.caps.is",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_CAPS_IS,
NULL, HFILL }},
{ &hf_mysql_cap_change_user,
{ "Speaks 4.1 protocol (new flag)","mysql.caps.cu",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_CAPS_CU,
NULL, HFILL }},
{ &hf_mysql_cap_interactive,
{ "Interactive Client","mysql.caps.ia",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_CAPS_IA,
NULL, HFILL }},
{ &hf_mysql_cap_ssl,
{ "Switch to SSL after handshake","mysql.caps.sl",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_CAPS_SL,
NULL, HFILL }},
{ &hf_mysql_cap_ignore_sigpipe,
{ "Ignore sigpipes","mysql.caps.ii",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_CAPS_II,
NULL, HFILL }},
{ &hf_mysql_cap_transactions,
{ "Knows about transactions","mysql.caps.ta",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_CAPS_TA,
NULL, HFILL }},
{ &hf_mysql_cap_reserved,
{ "Speaks 4.1 protocol (old flag)","mysql.caps.rs",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_CAPS_RS,
NULL, HFILL }},
{ &hf_mysql_cap_secure_connect,
{ "Can do 4.1 authentication","mysql.caps.sc",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_CAPS_SC,
NULL, HFILL }},
{ &hf_mysql_extcaps_client,
{ "Extended Client Capabilities", "mysql.extcaps.client",
FT_UINT16, BASE_HEX, NULL, 0x0,
"MySQL Extended Capabilities", HFILL }},
{ &hf_mysql_cap_multi_statements,
{ "Multiple statements","mysql.caps.ms",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_CAPS_MS,
NULL, HFILL }},
{ &hf_mysql_cap_multi_results,
{ "Multiple results","mysql.caps.mr",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_CAPS_MR,
NULL, HFILL }},
{ &hf_mysql_cap_ps_multi_results,
{ "PS Multiple results","mysql.caps.pm",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_CAPS_PM,
NULL, HFILL }},
{ &hf_mysql_cap_plugin_auth,
{ "Plugin Auth","mysql.caps.pa",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_CAPS_PA,
NULL, HFILL }},
{ &hf_mysql_cap_connect_attrs,
{ "Connect attrs","mysql.caps.ca",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_CAPS_CA,
NULL, HFILL }},
{ &hf_mysql_cap_plugin_auth_lenenc_client_data,
{ "Plugin Auth LENENC Client Data","mysql.caps.pm",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_CAPS_AL,
NULL, HFILL }},
{ &hf_mysql_cap_client_can_handle_expired_passwords,
{ "Client can handle expired passwords","mysql.caps.ep",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_CAPS_EP,
NULL, HFILL }},
{ &hf_mysql_cap_session_track,
{ "Session variable tracking","mysql.caps.session_track",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_CAPS_ST,
NULL, HFILL }},
{ &hf_mysql_cap_unused,
{ "Unused","mysql.caps.unused",
FT_UINT16, BASE_HEX, NULL, MYSQL_CAPS_UNUSED,
NULL, HFILL }},
{ &hf_mysql_login_request,
{ "Login Request", "mysql.login_request",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_max_packet,
{ "MAX Packet", "mysql.max_packet",
FT_UINT24, BASE_DEC, NULL, 0x0,
"MySQL Max packet", HFILL }},
{ &hf_mysql_charset,
{ "Charset", "mysql.charset",
FT_UINT8, BASE_DEC, VALS(mysql_collation_vals), 0x0,
"MySQL Charset", HFILL }},
{ &hf_mysql_table_name,
{ "Table Name", "mysql.table_name",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_user,
{ "Username", "mysql.user",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Login Username", HFILL }},
{ &hf_mysql_schema,
{ "Schema", "mysql.schema",
FT_STRING, BASE_NONE, NULL, 0x0,
"Login Schema", HFILL }},
{ &hf_mysql_client_auth_plugin,
{ "Client Auth Plugin", "mysql.client_auth_plugin",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_connattrs,
{ "Connection Attributes", "mysql.connattrs",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_connattrs_length,
{ "Connection Attributes length", "mysql.connattrs.length",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_connattrs_attr,
{ "Connection Attribute", "mysql.connattrs.attr",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_connattrs_name_length,
{ "Connection Attribute Name Length", "mysql.connattrs.name.length",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_connattrs_name,
{ "Connection Attribute Name", "mysql.connattrs.name",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_connattrs_value_length,
{ "Connection Attribute Name Length", "mysql.connattrs.name.length",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_connattrs_value,
{ "Connection Attribute Value", "mysql.connattrs.value",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_salt,
{ "Salt", "mysql.salt",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_salt2,
{ "Salt", "mysql.salt2",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_auth_plugin,
{ "Authentication Plugin", "mysql.auth_plugin",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_thread_id,
{ "Thread ID", "mysql.thread_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
"MySQL Thread ID", HFILL }},
{ &hf_mysql_server_language,
{ "Server Language", "mysql.server_language",
FT_UINT8, BASE_DEC, VALS(mysql_collation_vals), 0x0,
"MySQL Charset", HFILL }},
{ &hf_mysql_server_status,
{ "Server Status", "mysql.server_status",
FT_UINT16, BASE_HEX, NULL, 0x0,
"MySQL Status", HFILL }},
{ &hf_mysql_stat_it,
{ "In transaction", "mysql.stat.it",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_STAT_IT,
NULL, HFILL }},
{ &hf_mysql_stat_ac,
{ "AUTO_COMMIT", "mysql.stat.ac",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_STAT_AC,
NULL, HFILL }},
{ &hf_mysql_stat_mr,
{ "More results", "mysql.stat.mr",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_STAT_MR,
NULL, HFILL }},
{ &hf_mysql_stat_mu,
{ "Multi query - more resultsets", "mysql.stat.mu",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_STAT_MU,
NULL, HFILL }},
{ &hf_mysql_stat_bi,
{ "Bad index used", "mysql.stat.bi",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_STAT_BI,
NULL, HFILL }},
{ &hf_mysql_stat_ni,
{ "No index used", "mysql.stat.ni",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_STAT_NI,
NULL, HFILL }},
{ &hf_mysql_stat_cr,
{ "Cursor exists", "mysql.stat.cr",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_STAT_CR,
NULL, HFILL }},
{ &hf_mysql_stat_lr,
{ "Last row sent", "mysql.stat.lr",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_STAT_LR,
NULL, HFILL }},
{ &hf_mysql_stat_dr,
{ "database dropped", "mysql.stat.dr",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_STAT_DR,
NULL, HFILL }},
{ &hf_mysql_stat_bs,
{ "No backslash escapes", "mysql.stat.bs",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_STAT_BS,
NULL, HFILL }},
{ &hf_mysql_stat_session_state_changed,
{ "Session state changed", "mysql.stat.session_state_changed",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_STAT_SESSION_STATE_CHANGED,
NULL, HFILL }},
{ &hf_mysql_stat_query_was_slow,
{ "Query was slow", "mysql.stat.query_was_slow",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_STAT_QUERY_WAS_SLOW,
NULL, HFILL }},
{ &hf_mysql_stat_ps_out_params,
{ "PS Out Params", "mysql.stat.ps_out_params",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_STAT_PS_OUT_PARAMS,
NULL, HFILL }},
{ &hf_mysql_refresh,
{ "Refresh Option", "mysql.refresh",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_rfsh_grants,
{ "reload permissions", "mysql.rfsh.grants",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), MYSQL_RFSH_GRANT,
NULL, HFILL }},
{ &hf_mysql_rfsh_log,
{ "flush logfiles", "mysql.rfsh.log",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), MYSQL_RFSH_LOG,
NULL, HFILL }},
{ &hf_mysql_rfsh_tables,
{ "flush tables", "mysql.rfsh.tables",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), MYSQL_RFSH_TABLES,
NULL, HFILL }},
{ &hf_mysql_rfsh_hosts,
{ "flush hosts", "mysql.rfsh.hosts",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), MYSQL_RFSH_HOSTS,
NULL, HFILL }},
{ &hf_mysql_rfsh_status,
{ "reset statistics", "mysql.rfsh.status",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), MYSQL_RFSH_STATUS,
NULL, HFILL }},
{ &hf_mysql_rfsh_threads,
{ "empty thread cache", "mysql.rfsh.threads",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), MYSQL_RFSH_THREADS,
NULL, HFILL }},
{ &hf_mysql_rfsh_slave,
{ "flush slave status", "mysql.rfsh.slave",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), MYSQL_RFSH_SLAVE,
NULL, HFILL }},
{ &hf_mysql_rfsh_master,
{ "flush master status", "mysql.rfsh.master",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), MYSQL_RFSH_MASTER,
NULL, HFILL }},
{ &hf_mysql_unused,
{ "Unused", "mysql.unused",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_passwd,
{ "Password", "mysql.passwd",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_payload,
{ "Payload", "mysql.payload",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Additional Payload", HFILL }},
{ &hf_mysql_affected_rows,
{ "Affected Rows", "mysql.affected_rows",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_insert_id,
{ "Last INSERT ID", "mysql.insert_id",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_num_warn,
{ "Warnings", "mysql.warnings",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_thd_id,
{ "Thread ID", "mysql.thd_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_stmt_id,
{ "Statement ID", "mysql.stmt_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_query,
{ "Statement", "mysql.query",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_shutdown,
{ "Shutdown Level", "mysql.shutdown",
FT_UINT8, BASE_DEC, VALS(mysql_shutdown_vals), 0x0,
NULL, HFILL }},
{ &hf_mysql_option,
{ "Option", "mysql.option",
FT_UINT16, BASE_DEC, VALS(mysql_option_vals), 0x0,
NULL, HFILL }},
{ &hf_mysql_param,
{ "Parameter", "mysql.param",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_num_params,
{ "Number of parameter", "mysql.num_params",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_num_rows,
{ "Rows to fetch", "mysql.num_rows",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_exec_flags4,
{ "Flags (unused)", "mysql.exec_flags",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_exec_flags5,
{ "Flags", "mysql.exec_flags",
FT_UINT8, BASE_DEC, VALS(mysql_exec_flags_vals), 0x0,
NULL, HFILL }},
{ &hf_mysql_new_parameter_bound_flag,
{ "New parameter bound flag", "mysql.new_parameter_bound_flag",
FT_UINT8, BASE_DEC, VALS(mysql_new_parameter_bound_flag_vals), 0x0,
NULL, HFILL }},
{ &hf_mysql_exec_iter,
{ "Iterations (unused)", "mysql.exec_iter",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_binlog_position,
{ "Binlog Position", "mysql.binlog.position",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Position to start at", HFILL }},
{ &hf_mysql_binlog_flags,
{ "Binlog Flags", "mysql.binlog.flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
"(currently not used; always 0)", HFILL }},
{ &hf_mysql_binlog_server_id,
{ "Binlog server id", "mysql.binlog.server_id",
FT_UINT16, BASE_HEX, NULL, 0x0,
"server_id of the slave", HFILL }},
{ &hf_mysql_binlog_file_name,
{ "Binlog file name", "mysql.binlog.file_name",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_eof,
{ "EOF marker", "mysql.eof",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_num_fields,
{ "Number of fields", "mysql.num_fields",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_extra,
{ "Extra data", "mysql.extra",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_fld_catalog,
{ "Catalog", "mysql.field.catalog",
FT_STRING, BASE_NONE, NULL, 0x0,
"Field: catalog", HFILL }},
{ &hf_mysql_fld_db,
{ "Database", "mysql.field.db",
FT_STRING, BASE_NONE, NULL, 0x0,
"Field: database", HFILL }},
{ &hf_mysql_fld_table,
{ "Table", "mysql.field.table",
FT_STRING, BASE_NONE, NULL, 0x0,
"Field: table", HFILL }},
{ &hf_mysql_fld_org_table,
{ "Original table", "mysql.field.org_table",
FT_STRING, BASE_NONE, NULL, 0x0,
"Field: original table", HFILL }},
{ &hf_mysql_fld_name,
{ "Name", "mysql.field.name",
FT_STRING, BASE_NONE, NULL, 0x0,
"Field: name", HFILL }},
{ &hf_mysql_fld_org_name,
{ "Original name", "mysql.field.org_name",
FT_STRING, BASE_NONE, NULL, 0x0,
"Field: original name", HFILL }},
{ &hf_mysql_fld_charsetnr,
{ "Charset number", "mysql.field.charsetnr",
FT_UINT16, BASE_DEC, VALS(mysql_collation_vals), 0x0,
"Field: charset number", HFILL }},
{ &hf_mysql_fld_length,
{ "Length", "mysql.field.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Field: length", HFILL }},
{ &hf_mysql_fld_type,
{ "Type", "mysql.field.type",
FT_UINT8, BASE_DEC, VALS(type_constants), 0x0,
"Field: type", HFILL }},
{ &hf_mysql_fld_flags,
{ "Flags", "mysql.field.flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
"Field: flags", HFILL }},
{ &hf_mysql_fld_not_null,
{ "Not null", "mysql.field.flags.not_null",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_FLD_NOT_NULL_FLAG,
"Field: flag not null", HFILL }},
{ &hf_mysql_fld_primary_key,
{ "Primary key", "mysql.field.flags.primary_key",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_FLD_PRI_KEY_FLAG,
"Field: flag primary key", HFILL }},
{ &hf_mysql_fld_unique_key,
{ "Unique key", "mysql.field.flags.unique_key",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_FLD_UNIQUE_KEY_FLAG,
"Field: flag unique key", HFILL }},
{ &hf_mysql_fld_multiple_key,
{ "Multiple key", "mysql.field.flags.multiple_key",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_FLD_MULTIPLE_KEY_FLAG,
"Field: flag multiple key", HFILL }},
{ &hf_mysql_fld_blob,
{ "Blob", "mysql.field.flags.blob",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_FLD_BLOB_FLAG,
"Field: flag blob", HFILL }},
{ &hf_mysql_fld_unsigned,
{ "Unsigned", "mysql.field.flags.unsigned",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_FLD_UNSIGNED_FLAG,
"Field: flag unsigned", HFILL }},
{ &hf_mysql_fld_zero_fill,
{ "Zero fill", "mysql.field.flags.zero_fill",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_FLD_ZEROFILL_FLAG,
"Field: flag zero fill", HFILL }},
{ &hf_mysql_fld_binary,
{ "Binary", "mysql.field.flags.binary",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_FLD_BINARY_FLAG,
"Field: flag binary", HFILL }},
{ &hf_mysql_fld_enum,
{ "Enum", "mysql.field.flags.enum",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_FLD_ENUM_FLAG,
"Field: flag enum", HFILL }},
{ &hf_mysql_fld_auto_increment,
{ "Auto increment", "mysql.field.flags.auto_increment",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_FLD_AUTO_INCREMENT_FLAG,
"Field: flag auto increment", HFILL }},
{ &hf_mysql_fld_timestamp,
{ "Timestamp", "mysql.field.flags.timestamp",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_FLD_TIMESTAMP_FLAG,
"Field: flag timestamp", HFILL }},
{ &hf_mysql_fld_set,
{ "Set", "mysql.field.flags.set",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), MYSQL_FLD_SET_FLAG,
"Field: flag set", HFILL }},
{ &hf_mysql_fld_decimals,
{ "Decimals", "mysql.field.decimals",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Field: decimals", HFILL }},
{ &hf_mysql_fld_default,
{ "Default", "mysql.field.default",
FT_STRING, BASE_NONE, NULL, 0x0,
"Field: default", HFILL }},
{ &hf_mysql_row_text,
{ "text", "mysql.row.text",
FT_STRING, BASE_NONE, NULL, 0x0,
"Field: row packet text", HFILL }},
{ &hf_mysql_exec_param,
{ "Parameter", "mysql.exec_param",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_exec_unsigned,
{ "Unsigned", "mysql.exec.unsigned",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_exec_field_longlong,
{ "Value", "mysql.exec.field.longlong",
FT_INT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_exec_field_string,
{ "Value", "mysql.exec.field.string",
FT_UINT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_exec_field_double,
{ "Value", "mysql.exec.field.double",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_exec_field_datetime_length,
{ "Length", "mysql.exec.field.datetime.length",
FT_INT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_exec_field_year,
{ "Year", "mysql.exec.field.year",
FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_exec_field_month,
{ "Month", "mysql.exec.field.month",
FT_INT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_exec_field_day,
{ "Day", "mysql.exec.field.day",
FT_INT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_exec_field_hour,
{ "Hour", "mysql.exec.field.hour",
FT_INT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_exec_field_minute,
{ "Minute", "mysql.exec.field.minute",
FT_INT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_exec_field_second,
{ "Second", "mysql.exec.field.second",
FT_INT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_exec_field_second_b,
{ "Billionth of a second", "mysql.exec.field.secondb",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_exec_field_long,
{ "Value", "mysql.exec.field.long",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_exec_field_tiny,
{ "Value", "mysql.exec.field.tiny",
FT_INT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_exec_field_short,
{ "Value", "mysql.exec.field.short",
FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_exec_field_float,
{ "Value", "mysql.exec.field.float",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_exec_field_time_length,
{ "Length", "mysql.exec.field.time.length",
FT_INT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mysql_exec_field_time_sign,
{ "Flags", "mysql.exec.field.time.sign",
FT_UINT8, BASE_DEC, VALS(mysql_exec_time_sign_vals), 0x0,
NULL, HFILL }},
{ &hf_mysql_exec_field_time_days,
{ "Days", "mysql.exec.field.time.days",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[]=
{
&ett_mysql,
&ett_server_greeting,
&ett_login_request,
&ett_caps,
&ett_extcaps,
&ett_stat,
&ett_request,
&ett_refresh,
&ett_field_flags,
&ett_exec_param,
&ett_session_track,
&ett_session_track_data,
&ett_connattrs,
&ett_connattrs_attr
};
static ei_register_info ei[] = {
{ &ei_mysql_dissector_incomplete, { "mysql.dissector_incomplete", PI_UNDECODED, PI_WARN, "FIXME - dissector is incomplete", EXPFILL }},
{ &ei_mysql_streamed_param, { "mysql.streamed_param", PI_SEQUENCE, PI_CHAT, "This parameter was streamed, its value can be found in Send BLOB packets", EXPFILL }},
{ &ei_mysql_prepare_response_needed, { "mysql.prepare_response_needed", PI_UNDECODED, PI_WARN, "PREPARE Response packet is needed to dissect the payload", EXPFILL }},
{ &ei_mysql_command, { "mysql.command.invalid", PI_PROTOCOL, PI_WARN, "Unknown/invalid command code", EXPFILL }},
{ &ei_mysql_eof, { "mysql.eof.wrong_state", PI_PROTOCOL, PI_WARN, "EOF Marker found while connection in wrong state.", EXPFILL }},
{ &ei_mysql_unknown_response, { "mysql.unknown_response", PI_UNDECODED, PI_WARN, "unknown/invalid response", EXPFILL }},
};
module_t *mysql_module;
expert_module_t* expert_mysql;
proto_mysql = proto_register_protocol("MySQL Protocol", "MySQL", "mysql");
proto_register_field_array(proto_mysql, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_mysql = expert_register_protocol(proto_mysql);
expert_register_field_array(expert_mysql, ei, array_length(ei));
mysql_module = prefs_register_protocol(proto_mysql, NULL);
prefs_register_bool_preference(mysql_module, "desegment_buffers",
"Reassemble MySQL buffers spanning multiple TCP segments",
"Whether the MySQL dissector should reassemble MySQL buffers spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&mysql_desegment);
prefs_register_bool_preference(mysql_module, "show_sql_query",
"Show SQL Query string in INFO column",
"Whether the MySQL dissector should display the SQL query string in the INFO column.",
&mysql_showquery);
new_register_dissector("mysql", dissect_mysql, proto_mysql);
}
void proto_reg_handoff_mysql(void)
{
dissector_handle_t mysql_handle;
ssl_handle = find_dissector("ssl");
mysql_handle = new_create_dissector_handle(dissect_mysql, proto_mysql);
dissector_add_uint("tcp.port", TCP_PORT_MySQL, mysql_handle);
}
