static int
dissect_json(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
proto_tree *json_tree = NULL;
proto_item *ti = NULL;
json_parser_data_t parser_data;
tvbparse_t *tt;
const char *data_name;
int offset;
wmem_list_frame_t *proto = wmem_list_frame_prev(wmem_list_tail(pinfo->layers));
if (proto) {
const char *name = proto_get_protocol_filter_name(GPOINTER_TO_INT(wmem_list_frame_data(proto)));
if (!strcmp(name, "frame")) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "JSON");
col_set_str(pinfo->cinfo, COL_INFO, "JavaScript Object Notation");
}
}
data_name = pinfo->match_string;
if (! (data_name && data_name[0])) {
data_name = (char *)data;
if (! (data_name && data_name[0])) {
data_name = NULL;
}
}
if (tree) {
ti = proto_tree_add_item(tree, hfi_json, tvb, 0, -1, ENC_NA);
json_tree = proto_item_add_subtree(ti, ett_json);
if (data_name)
proto_item_append_text(ti, ": %s", data_name);
}
offset = 0;
parser_data.stack = wmem_stack_new(wmem_packet_scope());
wmem_stack_push(parser_data.stack, json_tree);
tt = tvbparse_init(tvb, offset, -1, &parser_data, want_ignore);
while ((tvbparse_get(tt, want)))
;
offset = tvbparse_curr_offset(tt);
proto_item_set_len(ti, offset);
if (tvb_reported_length_remaining(tvb, offset) > 0) {
tvbuff_t *next_tvb;
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector_with_data(text_lines_handle, next_tvb, pinfo, tree, data);
} else if (data_name) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " ", "(%s)", data_name);
}
return tvb_captured_length(tvb);
}
static int
dissect_json_file(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
return dissect_json(tvb, pinfo, tree, NULL);
}
static void before_object(void *tvbparse_data, const void *wanted_data _U_, tvbparse_elem_t *tok) {
json_parser_data_t *data = (json_parser_data_t *) tvbparse_data;
proto_tree *tree = (proto_tree *)wmem_stack_peek(data->stack);
proto_tree *subtree;
proto_item *ti;
ti = proto_tree_add_item(tree, &hfi_json_object, tok->tvb, tok->offset, tok->len, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_json_object);
wmem_stack_push(data->stack, subtree);
}
static void after_object(void *tvbparse_data, const void *wanted_data _U_, tvbparse_elem_t *elem _U_) {
json_parser_data_t *data = (json_parser_data_t *) tvbparse_data;
wmem_stack_pop(data->stack);
}
static void before_member(void *tvbparse_data, const void *wanted_data _U_, tvbparse_elem_t *tok) {
json_parser_data_t *data = (json_parser_data_t *) tvbparse_data;
proto_tree *tree = (proto_tree *)wmem_stack_peek(data->stack);
proto_tree *subtree;
proto_item *ti;
ti = proto_tree_add_item(tree, &hfi_json_member, tok->tvb, tok->offset, tok->len, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_json_member);
wmem_stack_push(data->stack, subtree);
}
static void after_member(void *tvbparse_data, const void *wanted_data _U_, tvbparse_elem_t *tok) {
json_parser_data_t *data = (json_parser_data_t *) tvbparse_data;
proto_tree *tree = (proto_tree *)wmem_stack_pop(data->stack);
if (tree) {
tvbparse_elem_t *key_tok = tok->sub;
if (key_tok && key_tok->id == JSON_TOKEN_STRING) {
char *key = tvb_get_string_enc(wmem_packet_scope(), key_tok->tvb, key_tok->offset, key_tok->len, ENC_ASCII);
proto_item_append_text(tree, " Key: %s", key);
}
}
}
static void before_array(void *tvbparse_data, const void *wanted_data _U_, tvbparse_elem_t *tok) {
json_parser_data_t *data = (json_parser_data_t *) tvbparse_data;
proto_tree *tree = (proto_tree *)wmem_stack_peek(data->stack);
proto_tree *subtree;
proto_item *ti;
ti = proto_tree_add_item(tree, &hfi_json_array, tok->tvb, tok->offset, tok->len, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_json_array);
wmem_stack_push(data->stack, subtree);
}
static void after_array(void *tvbparse_data, const void *wanted_data _U_, tvbparse_elem_t *elem _U_) {
json_parser_data_t *data = (json_parser_data_t *) tvbparse_data;
wmem_stack_pop(data->stack);
}
static int
json_tvb_memcpy_utf8(char *buf, tvbuff_t *tvb, int offset, int offset_max)
{
int len = ws_utf8_char_len((guint8) *buf);
if (len == -1 || ((guint) (offset + len)) >= (guint) offset_max) {
*buf = '?';
return 1;
}
tvb_memcpy(tvb, buf + 1, offset + 1, len - 1);
if (!g_utf8_validate(buf, len, NULL)) {
*buf = '?';
return 1;
}
return len;
}
static char *json_string_unescape(tvbparse_elem_t *tok)
{
char *str = (char *)wmem_alloc(wmem_packet_scope(), tok->len - 1);
int i, j;
j = 0;
for (i = 1; i < tok->len - 1; i++) {
guint8 ch = tvb_get_guint8(tok->tvb, tok->offset + i);
int bin;
if (ch == '\\') {
i++;
ch = tvb_get_guint8(tok->tvb, tok->offset + i);
switch (ch) {
case '\"':
case '\\':
case '/':
str[j++] = ch;
break;
case 'b':
str[j++] = '\b';
break;
case 'f':
str[j++] = '\f';
break;
case 'n':
str[j++] = '\n';
break;
case 'r':
str[j++] = '\r';
break;
case 't':
str[j++] = '\t';
break;
case 'u':
{
guint32 unicode_hex = 0;
gboolean valid = TRUE;
int k;
for (k = 0; k < 4; k++) {
i++;
unicode_hex <<= 4;
ch = tvb_get_guint8(tok->tvb, tok->offset + i);
bin = ws_xton(ch);
if (bin == -1) {
valid = FALSE;
break;
}
unicode_hex |= bin;
}
if ((IS_LEAD_SURROGATE(unicode_hex))) {
ch = tvb_get_guint8(tok->tvb, tok->offset + i + 1);
if (ch == '\\') {
i++;
ch = tvb_get_guint8(tok->tvb, tok->offset + i + 1);
if (ch == 'u') {
guint16 lead_surrogate = unicode_hex;
guint16 trail_surrogate = 0;
i++;
for (k = 0; k < 4; k++) {
i++;
trail_surrogate <<= 4;
ch = tvb_get_guint8(tok->tvb, tok->offset + i);
bin = ws_xton(ch);
if (bin == -1) {
valid = FALSE;
break;
}
trail_surrogate |= bin;
}
if ((IS_TRAIL_SURROGATE(trail_surrogate))) {
unicode_hex = SURROGATE_VALUE(lead_surrogate,trail_surrogate);
} else {
valid = FALSE;
}
} else {
valid = FALSE;
}
} else {
valid = FALSE;
}
} else if ((IS_TRAIL_SURROGATE(unicode_hex))) {
i++;
valid = FALSE;
}
if (valid && g_unichar_validate(unicode_hex) && g_unichar_isprint(unicode_hex)) {
int charlen = g_unichar_to_utf8(unicode_hex, &str[j]);
j += charlen;
} else
str[j++] = '?';
break;
}
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
} else {
int utf_len;
str[j] = ch;
utf_len = json_tvb_memcpy_utf8(&str[j], tok->tvb, i, tok->len);
j += utf_len;
i += (utf_len - 1);
}
}
str[j] = '\0';
return str;
}
static void after_value(void *tvbparse_data, const void *wanted_data _U_, tvbparse_elem_t *tok) {
json_parser_data_t *data = (json_parser_data_t *) tvbparse_data;
proto_tree *tree = (proto_tree *)wmem_stack_peek(data->stack);
json_token_type_t value_id = JSON_TOKEN_INVALID;
if (tok->sub)
value_id = (json_token_type_t)tok->sub->id;
switch (value_id) {
case JSON_TOKEN_STRING:
if (tok->len >= 2)
proto_tree_add_string(tree, &hfi_json_value_string, tok->tvb, tok->offset, tok->len, json_string_unescape(tok));
else
proto_tree_add_item(tree, &hfi_json_value_string, tok->tvb, tok->offset, tok->len, ENC_ASCII|ENC_NA);
break;
case JSON_TOKEN_NUMBER:
proto_tree_add_item(tree, &hfi_json_value_number, tok->tvb, tok->offset, tok->len, ENC_ASCII|ENC_NA);
break;
case JSON_TOKEN_FALSE:
proto_tree_add_item(tree, &hfi_json_value_false, tok->tvb, tok->offset, tok->len, ENC_NA);
break;
case JSON_TOKEN_NULL:
proto_tree_add_item(tree, &hfi_json_value_null, tok->tvb, tok->offset, tok->len, ENC_NA);
break;
case JSON_TOKEN_TRUE:
proto_tree_add_item(tree, &hfi_json_value_true, tok->tvb, tok->offset, tok->len, ENC_NA);
break;
case JSON_OBJECT:
case JSON_ARRAY:
break;
default:
proto_tree_add_format_text(tree, tok->tvb, tok->offset, tok->len);
break;
}
}
static void init_json_parser(void) {
static tvbparse_wanted_t _want_object;
static tvbparse_wanted_t _want_array;
tvbparse_wanted_t *want_object, *want_array;
tvbparse_wanted_t *want_member;
tvbparse_wanted_t *want_string;
tvbparse_wanted_t *want_number, *want_int;
tvbparse_wanted_t *want_value;
tvbparse_wanted_t *want_value_separator;
#define tvbparse_optional(id, private_data, before_cb, after_cb, wanted) \
tvbparse_some(id, 0, 1, private_data, before_cb, after_cb, wanted)
tvbparse_wanted_t *want_quot = tvbparse_char(-1,"\"",NULL,NULL,NULL);
want_string = tvbparse_set_seq(JSON_TOKEN_STRING, NULL, NULL, NULL,
want_quot,
tvbparse_some(-1, 0, G_MAXINT, NULL, NULL, NULL,
tvbparse_set_oneof(-1, NULL, NULL, NULL,
tvbparse_not_chars(-1, 0, 0, "\"" "\\", NULL, NULL, NULL),
tvbparse_set_seq(-1, NULL, NULL, NULL,
tvbparse_char(-1, "\\", NULL, NULL, NULL),
tvbparse_set_oneof(-1, NULL, NULL, NULL,
tvbparse_chars(-1, 0, 1, "\"" "\\" "/bfnrt", NULL, NULL, NULL),
tvbparse_set_seq(-1, NULL, NULL, NULL,
tvbparse_char(-1, "u", NULL, NULL, NULL),
tvbparse_chars(-1, 4, 4, "0123456789abcdefABCDEF", NULL, NULL, NULL),
NULL),
NULL),
NULL),
NULL)
),
want_quot,
NULL);
want_value_separator = tvbparse_char(-1, ",", NULL, NULL, NULL);
want_int = tvbparse_set_oneof(-1, NULL, NULL, NULL,
tvbparse_char(-1, "0", NULL, NULL, NULL),
tvbparse_set_seq(-1, NULL, NULL, NULL,
tvbparse_chars(-1, 1, 1, "123456789", NULL, NULL, NULL),
tvbparse_optional(-1, NULL, NULL, NULL,
tvbparse_chars(-1, 0, 0, "0123456789", NULL, NULL, NULL)),
NULL),
NULL);
want_number = tvbparse_set_seq(JSON_TOKEN_NUMBER, NULL, NULL, NULL,
tvbparse_optional(-1, NULL, NULL, NULL,
tvbparse_chars(-1, 0, 1, "-", NULL, NULL, NULL)),
want_int,
tvbparse_optional(-1, NULL, NULL, NULL,
tvbparse_set_seq(-1, NULL, NULL, NULL,
tvbparse_char(-1, ".", NULL, NULL, NULL),
tvbparse_chars(-1, 1, 0, "0123456789", NULL, NULL, NULL),
NULL)),
tvbparse_optional(-1, NULL, NULL, NULL,
tvbparse_set_seq(-1, NULL, NULL, NULL,
tvbparse_char(-1, "eE", NULL, NULL, NULL),
tvbparse_optional(-1, NULL, NULL, NULL,
tvbparse_chars(-1, 0, 1, "-+", NULL, NULL, NULL)),
tvbparse_chars(-1, 1, 0, "0123456789", NULL, NULL, NULL),
NULL)),
NULL);
want_value = tvbparse_set_oneof(-1, NULL, NULL, after_value,
tvbparse_string(JSON_TOKEN_FALSE, "false", NULL, NULL, NULL),
tvbparse_string(JSON_TOKEN_NULL, "null", NULL, NULL, NULL),
tvbparse_string(JSON_TOKEN_TRUE, "true", NULL, NULL, NULL),
&_want_object,
&_want_array,
want_number,
want_string,
NULL);
want_array = tvbparse_set_seq(JSON_ARRAY, NULL, before_array, after_array,
tvbparse_char(-1, "[", NULL, NULL, NULL),
tvbparse_optional(-1, NULL, NULL, NULL,
tvbparse_set_seq(-1, NULL, NULL, NULL,
want_value,
tvbparse_some(-1, 0, G_MAXINT, NULL, NULL, NULL,
tvbparse_set_seq(-1, NULL, NULL, NULL,
want_value_separator,
want_value,
NULL)),
NULL)
),
tvbparse_char(-1, "]", NULL, NULL, NULL),
NULL);
_want_array = *want_array;
want_member = tvbparse_set_seq(-1, NULL, before_member, after_member,
want_string,
tvbparse_char(-1, ":", NULL, NULL, NULL),
want_value,
NULL);
want_object = tvbparse_set_seq(JSON_OBJECT, NULL, before_object, after_object,
tvbparse_char(-1, "{", NULL, NULL, NULL),
tvbparse_optional(-1, NULL, NULL, NULL,
tvbparse_set_seq(-1, NULL, NULL, NULL,
want_member,
tvbparse_some(-1, 0, G_MAXINT, NULL, NULL, NULL,
tvbparse_set_seq(-1, NULL, NULL, NULL,
want_value_separator,
want_member,
NULL)),
NULL)
),
tvbparse_char(-1, "}", NULL, NULL, NULL),
NULL);
_want_object = *want_object;
want_ignore = tvbparse_chars(-1, 1, 0, " \t\r\n", NULL, NULL, NULL);
want = tvbparse_set_oneof(-1, NULL, NULL, NULL,
want_object,
want_array,
NULL);
}
static gboolean
dissect_json_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
guint len = tvb_captured_length(tvb);
const guint8* buf = tvb_get_string_enc(wmem_packet_scope(), tvb, 0, len, ENC_ASCII);
if (jsmn_is_json(buf, len) == FALSE)
return FALSE;
return (dissect_json(tvb, pinfo, tree, data) != 0);
}
void
proto_register_json(void)
{
static gint *ett[] = {
&ett_json,
&ett_json_array,
&ett_json_object,
&ett_json_member
};
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] = {
&hfi_json_array,
&hfi_json_object,
&hfi_json_member,
&hfi_json_value_string,
&hfi_json_value_number,
&hfi_json_value_false,
&hfi_json_value_null,
&hfi_json_value_true,
};
#endif
proto_json = proto_register_protocol("JavaScript Object Notation", "JSON", "json");
hfi_json = proto_registrar_get_nth(proto_json);
proto_register_fields(proto_json, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
json_handle = new_register_dissector("json", dissect_json, proto_json);
init_json_parser();
}
void
proto_reg_handoff_json(void)
{
dissector_handle_t json_file_handle = new_create_dissector_handle(dissect_json_file, proto_json);
heur_dissector_add("hpfeeds", dissect_json_heur, "JSON over HPFEEDS", "json_hpfeeds", proto_json, HEURISTIC_ENABLE);
heur_dissector_add("db-lsp", dissect_json_heur, "JSON over DB-LSP", "json_db_lsp", proto_json, HEURISTIC_ENABLE);
dissector_add_uint("wtap_encap", WTAP_ENCAP_JSON, json_file_handle);
dissector_add_string("media_type", "application/json", json_handle);
dissector_add_string("media_type", "application/json-rpc", json_handle);
dissector_add_string("media_type", "application/jsonrequest", json_handle);
text_lines_handle = find_dissector("data-text-lines");
}
