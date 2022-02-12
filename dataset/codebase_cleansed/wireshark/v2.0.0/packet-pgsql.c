static void dissect_pgsql_fe_msg(guchar type, guint length, tvbuff_t *tvb,
gint n, proto_tree *tree,
pgsql_conn_data_t *conv_data)
{
guchar c;
gint i, siz;
char *s;
proto_tree *shrub;
switch (type) {
case 'p':
siz = tvb_strsize(tvb, n);
proto_tree_add_item(tree, hf_passwd, tvb, n, siz, ENC_ASCII|ENC_NA);
break;
case 'Q':
siz = tvb_strsize(tvb, n);
proto_tree_add_item(tree, hf_query, tvb, n, siz, ENC_ASCII|ENC_NA);
break;
case 'P':
siz = tvb_strsize(tvb, n);
proto_tree_add_item(tree, hf_statement, tvb, n, siz, ENC_ASCII|ENC_NA);
n += siz;
siz = tvb_strsize(tvb, n);
proto_tree_add_item(tree, hf_query, tvb, n, siz, ENC_ASCII|ENC_NA);
n += siz;
i = tvb_get_ntohs(tvb, n);
shrub = proto_tree_add_subtree_format(tree, tvb, n, 2, ett_values, NULL, "Parameters: %d", i);
n += 2;
while (i-- > 0) {
proto_tree_add_item(shrub, hf_typeoid, tvb, n, 4, ENC_BIG_ENDIAN);
n += 4;
}
break;
case 'B':
siz = tvb_strsize(tvb, n);
proto_tree_add_item(tree, hf_portal, tvb, n, siz, ENC_ASCII|ENC_NA);
n += siz;
siz = tvb_strsize(tvb, n);
proto_tree_add_item(tree, hf_statement, tvb, n, siz, ENC_ASCII|ENC_NA);
n += siz;
i = tvb_get_ntohs(tvb, n);
shrub = proto_tree_add_subtree_format(tree, tvb, n, 2, ett_values, NULL, "Parameter formats: %d", i);
n += 2;
while (i-- > 0) {
proto_tree_add_item(shrub, hf_format, tvb, n, 2, ENC_BIG_ENDIAN);
n += 2;
}
i = tvb_get_ntohs(tvb, n);
shrub = proto_tree_add_subtree_format(tree, tvb, n, 2, ett_values, NULL, "Parameter values: %d", i);
n += 2;
while (i-- > 0) {
siz = tvb_get_ntohl(tvb, n);
proto_tree_add_int(shrub, hf_val_length, tvb, n, 4, siz);
n += 4;
if (siz > 0) {
proto_tree_add_item(shrub, hf_val_data, tvb, n, siz, ENC_NA);
n += siz;
}
}
i = tvb_get_ntohs(tvb, n);
shrub = proto_tree_add_subtree_format(tree, tvb, n, 2, ett_values, NULL, "Result formats: %d", i);
n += 2;
while (i-- > 0) {
proto_tree_add_item(shrub, hf_format, tvb, n, 2, ENC_BIG_ENDIAN);
n += 2;
}
break;
case 'E':
siz = tvb_strsize(tvb, n);
proto_tree_add_item(tree, hf_portal, tvb, n, siz, ENC_ASCII|ENC_NA);
n += siz;
i = tvb_get_ntohl(tvb, n);
if (i == 0)
proto_tree_add_uint_format_value(tree, hf_return, tvb, n, 4, i, "all rows");
else
proto_tree_add_uint_format_value(tree, hf_return, tvb, n, 4, i, "%d rows", i);
break;
case 'D':
case 'C':
c = tvb_get_guint8(tvb, n);
if (c == 'P')
i = hf_portal;
else
i = hf_statement;
n += 1;
s = tvb_get_stringz_enc(wmem_packet_scope(), tvb, n, &siz, ENC_ASCII);
proto_tree_add_string(tree, i, tvb, n, siz, s);
break;
case '\0':
i = tvb_get_ntohl(tvb, n);
n += 4;
length -= n;
switch (i) {
case 196608:
while ((signed)length > 0) {
siz = tvb_strsize(tvb, n);
length -= siz;
if ((signed)length <= 0) {
break;
}
proto_tree_add_item(tree, hf_parameter_name, tvb, n, siz, ENC_ASCII|ENC_NA);
i = tvb_strsize(tvb, n+siz);
proto_tree_add_item(tree, hf_parameter_value, tvb, n + siz, i, ENC_ASCII|ENC_NA);
length -= i;
n += siz+i;
if (length == 1 && tvb_get_guint8(tvb, n) == 0)
break;
}
break;
case 80877103:
conv_data->ssl_requested = TRUE;
break;
case 80877102:
proto_tree_add_item(tree, hf_pid, tvb, n, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_key, tvb, n+4, 4, ENC_BIG_ENDIAN);
break;
}
break;
case 'd':
proto_tree_add_item(tree, hf_copydata, tvb, n, length-n+1, ENC_NA);
break;
case 'f':
siz = tvb_strsize(tvb, n);
proto_tree_add_item(tree, hf_error, tvb, n, siz, ENC_ASCII|ENC_NA);
break;
case 'F':
proto_tree_add_item(tree, hf_oid, tvb, n, 4, ENC_BIG_ENDIAN);
n += 4;
i = tvb_get_ntohs(tvb, n);
shrub = proto_tree_add_subtree_format(tree, tvb, n, 2, ett_values, NULL, "Parameter formats: %d", i);
n += 2;
while (i-- > 0) {
proto_tree_add_item(shrub, hf_format, tvb, n, 2, ENC_BIG_ENDIAN);
n += 2;
}
i = tvb_get_ntohs(tvb, n);
shrub = proto_tree_add_subtree_format(tree, tvb, n, 2, ett_values, NULL, "Parameter values: %d", i);
n += 2;
while (i-- > 0) {
siz = tvb_get_ntohl(tvb, n);
proto_tree_add_item(shrub, hf_val_length, tvb, n, 4, ENC_BIG_ENDIAN);
n += 4;
if (siz > 0) {
proto_tree_add_item(shrub, hf_val_data, tvb, n, siz, ENC_NA);
n += siz;
}
}
proto_tree_add_item(tree, hf_format, tvb, n, 2, ENC_BIG_ENDIAN);
break;
}
}
static void dissect_pgsql_be_msg(guchar type, guint length, tvbuff_t *tvb,
gint n, proto_tree *tree)
{
guchar c;
gint i, siz;
char *s, *t;
proto_item *ti;
proto_tree *shrub;
switch (type) {
case 'R':
proto_tree_add_item(tree, hf_authtype, tvb, n, 4, ENC_BIG_ENDIAN);
i = tvb_get_ntohl(tvb, n);
if (i == 4 || i == 5) {
n += 4;
siz = (i == 4 ? 2 : 4);
proto_tree_add_item(tree, hf_salt, tvb, n, siz, ENC_NA);
}
break;
case 'K':
proto_tree_add_item(tree, hf_pid, tvb, n, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_key, tvb, n+4, 4, ENC_BIG_ENDIAN);
break;
case 'S':
s = tvb_get_stringz_enc(wmem_packet_scope(), tvb, n, &siz, ENC_ASCII);
proto_tree_add_string(tree, hf_parameter_name, tvb, n, siz, s);
n += siz;
t = tvb_get_stringz_enc(wmem_packet_scope(), tvb, n, &i, ENC_ASCII);
proto_tree_add_string(tree, hf_parameter_value, tvb, n, i, t);
break;
case 't':
i = tvb_get_ntohs(tvb, n);
shrub = proto_tree_add_subtree_format(tree, tvb, n, 2, ett_values, NULL, "Parameters: %d", i);
n += 2;
while (i-- > 0) {
proto_tree_add_item(shrub, hf_typeoid, tvb, n, 4, ENC_BIG_ENDIAN);
n += 4;
}
break;
case 'T':
i = tvb_get_ntohs(tvb, n);
ti = proto_tree_add_item(tree, hf_field_count, tvb, n, 2, ENC_BIG_ENDIAN);
shrub = proto_item_add_subtree(ti, ett_values);
n += 2;
while (i-- > 0) {
proto_tree *twig;
siz = tvb_strsize(tvb, n);
ti = proto_tree_add_item(shrub, hf_val_name, tvb, n, siz, ENC_ASCII|ENC_NA);
twig = proto_item_add_subtree(ti, ett_values);
n += siz;
proto_tree_add_item(twig, hf_tableoid, tvb, n, 4, ENC_BIG_ENDIAN);
n += 4;
proto_tree_add_item(twig, hf_val_idx, tvb, n, 2, ENC_BIG_ENDIAN);
n += 2;
proto_tree_add_item(twig, hf_typeoid, tvb, n, 4, ENC_BIG_ENDIAN);
n += 4;
proto_tree_add_item(twig, hf_val_length, tvb, n, 2, ENC_BIG_ENDIAN);
n += 2;
proto_tree_add_item(twig, hf_val_mod, tvb, n, 4, ENC_BIG_ENDIAN);
n += 4;
proto_tree_add_item(twig, hf_format, tvb, n, 2, ENC_BIG_ENDIAN);
n += 2;
}
break;
case 'D':
i = tvb_get_ntohs(tvb, n);
ti = proto_tree_add_item(tree, hf_field_count, tvb, n, 2, ENC_BIG_ENDIAN);
shrub = proto_item_add_subtree(ti, ett_values);
n += 2;
while (i-- > 0) {
siz = tvb_get_ntohl(tvb, n);
proto_tree_add_int(shrub, hf_val_length, tvb, n, 4, siz);
n += 4;
if (siz > 0) {
proto_tree_add_item(shrub, hf_val_data, tvb, n, siz, ENC_NA);
n += siz;
}
}
break;
case 'C':
siz = tvb_strsize(tvb, n);
proto_tree_add_item(tree, hf_tag, tvb, n, siz, ENC_ASCII|ENC_NA);
break;
case 'Z':
proto_tree_add_item(tree, hf_status, tvb, n, 1, ENC_BIG_ENDIAN);
break;
case 'E':
case 'N':
length -= 4;
while ((signed)length > 0) {
c = tvb_get_guint8(tvb, n);
if (c == '\0')
break;
s = tvb_get_stringz_enc(wmem_packet_scope(), tvb, n+1, &siz, ENC_ASCII);
i = hf_text;
switch (c) {
case 'S': i = hf_severity; break;
case 'C': i = hf_code; break;
case 'M': i = hf_message; break;
case 'D': i = hf_detail; break;
case 'H': i = hf_hint; break;
case 'P': i = hf_position; break;
case 'p': i = hf_internal_position; break;
case 'q': i = hf_internal_query; break;
case 'W': i = hf_where; break;
case 's': i = hf_schema_name; break;
case 't': i = hf_table_name; break;
case 'c': i = hf_column_name; break;
case 'd': i = hf_type_name; break;
case 'n': i = hf_constraint_name; break;
case 'F': i = hf_file; break;
case 'L': i = hf_line; break;
case 'R': i = hf_routine; break;
}
proto_tree_add_string(tree, i, tvb, n, siz+1, s);
length -= siz+1;
n += siz+1;
}
break;
case 'A':
proto_tree_add_item(tree, hf_pid, tvb, n, 4, ENC_BIG_ENDIAN);
n += 4;
siz = tvb_strsize(tvb, n);
proto_tree_add_item(tree, hf_condition, tvb, n, siz, ENC_ASCII|ENC_NA);
n += siz;
siz = tvb_strsize(tvb, n);
if (siz > 1)
proto_tree_add_item(tree, hf_text, tvb, n, siz, ENC_ASCII|ENC_NA);
break;
case 'G':
case 'H':
proto_tree_add_item(tree, hf_format, tvb, n, 1, ENC_BIG_ENDIAN);
n += 1;
i = tvb_get_ntohs(tvb, n);
shrub = proto_tree_add_subtree_format(tree, tvb, n, 2, ett_values, NULL, "Columns: %d", i);
n += 2;
while (i-- > 2) {
proto_tree_add_item(shrub, hf_format, tvb, n, 2, ENC_BIG_ENDIAN);
n += 2;
}
break;
case 'd':
proto_tree_add_item(tree, hf_copydata, tvb, n, length-n+1, ENC_NA);
break;
case 'V':
siz = tvb_get_ntohl(tvb, n);
proto_tree_add_int(tree, hf_val_length, tvb, n, 4, siz);
if (siz > 0)
proto_tree_add_item(tree, hf_val_data, tvb, n+4, siz, ENC_NA);
break;
}
}
static guint
pgsql_length(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
gint n = 0;
guchar type;
guint length;
type = tvb_get_guint8(tvb, offset);
if (type != '\0')
n = 1;
length = tvb_get_ntohl(tvb, offset+n);
return length+n;
}
static int
dissect_pgsql_msg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti, *hidden_item;
proto_tree *ptree;
conversation_t *conversation;
pgsql_conn_data_t *conn_data;
gint n;
guchar type;
const char *typestr;
guint length;
gboolean fe = (pinfo->match_uint == pinfo->destport);
conversation = find_or_create_conversation(pinfo);
conn_data = (pgsql_conn_data_t *)conversation_get_proto_data(conversation, proto_pgsql);
if (!conn_data) {
conn_data = wmem_new(wmem_file_scope(), pgsql_conn_data_t);
conn_data->ssl_requested = FALSE;
conversation_add_proto_data(conversation, proto_pgsql, conn_data);
}
n = 0;
type = tvb_get_guint8(tvb, 0);
if (type != '\0')
n += 1;
length = tvb_get_ntohl(tvb, n);
if (fe) {
if (type == '\0') {
guint tag = tvb_get_ntohl(tvb, 4);
if (length == 16 && tag == 80877102)
typestr = "Cancel request";
else if (length == 8 && tag == 80877103)
typestr = "SSL request";
else if (tag == 196608)
typestr = "Startup message";
else
typestr = "Unknown";
} else
typestr = val_to_str_const(type, fe_messages, "Unknown");
}
else {
typestr = val_to_str_const(type, be_messages, "Unknown");
}
col_append_fstr(pinfo->cinfo, COL_INFO, "%s%c",
( first_message ? "" : "/" ), type);
first_message = FALSE;
{
ti = proto_tree_add_item(tree, proto_pgsql, tvb, 0, -1, ENC_NA);
ptree = proto_item_add_subtree(ti, ett_pgsql);
n = 1;
if (type == '\0')
n = 0;
proto_tree_add_string(ptree, hf_type, tvb, 0, n, typestr);
proto_tree_add_item(ptree, hf_length, tvb, n, 4, ENC_BIG_ENDIAN);
hidden_item = proto_tree_add_boolean(ptree, hf_frontend, tvb, 0, 0, fe);
PROTO_ITEM_SET_HIDDEN(hidden_item);
n += 4;
if (fe)
dissect_pgsql_fe_msg(type, length, tvb, n, ptree, conn_data);
else
dissect_pgsql_be_msg(type, length, tvb, n, ptree);
}
return tvb_captured_length(tvb);
}
static int
dissect_pgsql(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
conversation_t *conversation;
pgsql_conn_data_t *conn_data;
first_message = TRUE;
conversation = find_or_create_conversation(pinfo);
conn_data = (pgsql_conn_data_t *)conversation_get_proto_data(conversation, proto_pgsql);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PGSQL");
col_set_str(pinfo->cinfo, COL_INFO,
(pinfo->match_uint == pinfo->destport) ?
">" : "<");
if (conn_data && conn_data->ssl_requested) {
switch (tvb_get_guint8(tvb, 0)) {
case 'S':
ssl_starttls_ack(ssl_handle, pinfo, pgsql_handle);
break;
case 'N':
default:
break;
}
conn_data->ssl_requested = FALSE;
return tvb_captured_length(tvb);
}
tcp_dissect_pdus(tvb, pinfo, tree, pgsql_desegment, 5,
pgsql_length, dissect_pgsql_msg, data);
return tvb_captured_length(tvb);
}
void
proto_register_pgsql(void)
{
static hf_register_info hf[] = {
{ &hf_frontend,
{ "Frontend", "pgsql.frontend", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True for messages from the frontend, false otherwise.",
HFILL }
},
{ &hf_type,
{ "Type", "pgsql.type", FT_STRING, BASE_NONE, NULL, 0,
"A one-byte message type identifier.", HFILL }
},
{ &hf_length,
{ "Length", "pgsql.length", FT_UINT32, BASE_DEC, NULL, 0,
"The length of the message (not including the type).",
HFILL }
},
{ &hf_parameter_name,
{ "Parameter name", "pgsql.parameter_name", FT_STRINGZ,
BASE_NONE, NULL, 0, "The name of a database parameter.",
HFILL }
},
{ &hf_parameter_value,
{ "Parameter value", "pgsql.parameter_value", FT_STRINGZ,
BASE_NONE, NULL, 0, "The value of a database parameter.",
HFILL }
},
{ &hf_query,
{ "Query", "pgsql.query", FT_STRINGZ, BASE_NONE, NULL, 0,
"A query string.", HFILL }
},
{ &hf_passwd,
{ "Password", "pgsql.password", FT_STRINGZ, BASE_NONE, NULL, 0,
"A password.", HFILL }
},
{ &hf_authtype,
{ "Authentication type", "pgsql.authtype", FT_INT32, BASE_DEC,
VALS(auth_types), 0,
"The type of authentication requested by the backend.", HFILL }
},
{ &hf_salt,
{ "Salt value", "pgsql.salt", FT_BYTES, BASE_NONE, NULL, 0,
"The salt to use while encrypting a password.", HFILL }
},
{ &hf_statement,
{ "Statement", "pgsql.statement", FT_STRINGZ, BASE_NONE, NULL, 0,
"The name of a prepared statement.", HFILL }
},
{ &hf_portal,
{ "Portal", "pgsql.portal", FT_STRINGZ, BASE_NONE, NULL, 0,
"The name of a portal.", HFILL }
},
{ &hf_return,
{ "Returns", "pgsql.returns", FT_UINT32, BASE_DEC,
NULL, 0,
NULL, HFILL }
},
{ &hf_tag,
{ "Tag", "pgsql.tag", FT_STRINGZ, BASE_NONE, NULL, 0,
"A completion tag.", HFILL }
},
{ &hf_status,
{ "Status", "pgsql.status", FT_UINT8, BASE_DEC, VALS(status_vals),
0, "The transaction status of the backend.", HFILL }
},
{ &hf_copydata,
{ "Copy data", "pgsql.copydata", FT_BYTES, BASE_NONE, NULL, 0,
"Data sent following a Copy-in or Copy-out response.", HFILL }
},
{ &hf_error,
{ "Error", "pgsql.error", FT_STRINGZ, BASE_NONE, NULL, 0,
"An error message.", HFILL }
},
{ &hf_pid,
{ "PID", "pgsql.pid", FT_UINT32, BASE_DEC, NULL, 0,
"The process ID of a backend.", HFILL }
},
{ &hf_key,
{ "Key", "pgsql.key", FT_UINT32, BASE_DEC, NULL, 0,
"The secret key used by a particular backend.", HFILL }
},
{ &hf_condition,
{ "Condition", "pgsql.condition", FT_STRINGZ, BASE_NONE, NULL, 0,
"The name of a NOTIFY condition.", HFILL }
},
{ &hf_text,
{ "Text", "pgsql.text", FT_STRINGZ, BASE_NONE, NULL, 0,
"Text from the backend.", HFILL }
},
{ &hf_tableoid,
{ "Table OID", "pgsql.oid.table", FT_UINT32, BASE_DEC, NULL, 0,
"The object identifier of a table.", HFILL }
},
{ &hf_typeoid,
{ "Type OID", "pgsql.oid.type", FT_UINT32, BASE_DEC, NULL, 0,
"The object identifier of a type.", HFILL }
},
{ &hf_oid,
{ "OID", "pgsql.oid", FT_UINT32, BASE_DEC, NULL, 0,
"An object identifier.", HFILL }
},
{ &hf_format,
{ "Format", "pgsql.format", FT_UINT16, BASE_DEC, VALS(format_vals),
0, "A format specifier.", HFILL }
},
{ &hf_field_count,
{ "Field count", "pgsql.field.count", FT_UINT16, BASE_DEC, NULL, 0,
"The number of fields within a row.", HFILL }
},
{ &hf_val_name,
{ "Column name", "pgsql.col.name", FT_STRINGZ, BASE_NONE, NULL, 0,
"The name of a column.", HFILL }
},
{ &hf_val_idx,
{ "Column index", "pgsql.col.index", FT_UINT32, BASE_DEC, NULL, 0,
"The position of a column within a row.", HFILL }
},
{ &hf_val_length,
{ "Column length", "pgsql.val.length", FT_INT32, BASE_DEC, NULL, 0,
"The length of a parameter value, in bytes. -1 means NULL.",
HFILL }
},
{ &hf_val_data,
{ "Data", "pgsql.val.data", FT_BYTES, BASE_NONE, NULL, 0,
"Parameter data.", HFILL }
},
{ &hf_val_mod,
{ "Type modifier", "pgsql.col.typemod", FT_INT32, BASE_DEC, NULL, 0,
"The type modifier for a column.", HFILL }
},
{ &hf_severity,
{ "Severity", "pgsql.severity", FT_STRINGZ, BASE_NONE, NULL, 0,
"Message severity.", HFILL }
},
{ &hf_code,
{ "Code", "pgsql.code", FT_STRINGZ, BASE_NONE, NULL, 0,
"SQLState code.", HFILL }
},
{ &hf_message,
{ "Message", "pgsql.message", FT_STRINGZ, BASE_NONE, NULL, 0,
"Error message.", HFILL }
},
{ &hf_detail,
{ "Detail", "pgsql.detail", FT_STRINGZ, BASE_NONE, NULL, 0,
"Detailed error message.", HFILL }
},
{ &hf_hint,
{ "Hint", "pgsql.hint", FT_STRINGZ, BASE_NONE, NULL, 0,
"A suggestion to resolve an error.", HFILL }
},
{ &hf_position,
{ "Position", "pgsql.position", FT_STRINGZ, BASE_NONE, NULL, 0,
"The index of the error within the query string.", HFILL }
},
{ &hf_internal_position,
{ "Position (Internal)", "pgsql.internal_position", FT_STRINGZ, BASE_NONE, NULL, 0,
"The index of the error within the internally-generated query string.", HFILL }
},
{ &hf_internal_query,
{ "Query (Internal)", "pgsql.internal_query", FT_STRINGZ, BASE_NONE, NULL, 0,
"The internally-generated query string", HFILL }
},
{ &hf_where,
{ "Context", "pgsql.where", FT_STRINGZ, BASE_NONE, NULL, 0,
"The context in which an error occurred.", HFILL }
},
{ &hf_schema_name,
{ "Schema", "pgsql.schema_name", FT_STRINGZ, BASE_NONE, NULL, 0,
"The schema with which an error is associated.", HFILL }
},
{ &hf_table_name,
{ "Table", "pgsql.table_name", FT_STRINGZ, BASE_NONE, NULL, 0,
"The table with which an error is associated.", HFILL }
},
{ &hf_column_name,
{ "Column", "pgsql.column_name", FT_STRINGZ, BASE_NONE, NULL, 0,
"The column with which an error is associated.", HFILL }
},
{ &hf_type_name,
{ "Type", "pgsql.type_name", FT_STRINGZ, BASE_NONE, NULL, 0,
"The date type with which an error is associated.", HFILL }
},
{ &hf_constraint_name,
{ "Constraint", "pgsql.constraint_name", FT_STRINGZ, BASE_NONE, NULL, 0,
"The constraint with which an error is associated.", HFILL }
},
{ &hf_file,
{ "File", "pgsql.file", FT_STRINGZ, BASE_NONE, NULL, 0,
"The source-code file where an error was reported.", HFILL }
},
{ &hf_line,
{ "Line", "pgsql.line", FT_STRINGZ, BASE_NONE, NULL, 0,
"The line number on which an error was reported.", HFILL }
},
{ &hf_routine,
{ "Routine", "pgsql.routine", FT_STRINGZ, BASE_NONE, NULL, 0,
"The routine that reported an error.", HFILL }
}
};
static gint *ett[] = {
&ett_pgsql,
&ett_values
};
module_t *mod_pgsql;
proto_pgsql = proto_register_protocol("PostgreSQL", "PGSQL", "pgsql");
proto_register_field_array(proto_pgsql, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
mod_pgsql = prefs_register_protocol(proto_pgsql, proto_reg_handoff_pgsql);
prefs_register_uint_preference(
mod_pgsql, "tcp.port", "PGSQL TCP port", "Set the port for PGSQL "
"messages (if different from the default of 5432)", 10, &pgsql_port
);
}
void
proto_reg_handoff_pgsql(void)
{
static gboolean initialized = FALSE;
static guint saved_pgsql_port;
if (!initialized) {
pgsql_handle = new_create_dissector_handle(dissect_pgsql, proto_pgsql);
initialized = TRUE;
} else {
dissector_delete_uint("tcp.port", saved_pgsql_port, pgsql_handle);
}
dissector_add_uint("tcp.port", pgsql_port, pgsql_handle);
saved_pgsql_port = pgsql_port;
ssl_handle = find_dissector("ssl");
}
