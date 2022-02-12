static int fix_marker(tvbuff_t *tvb, int offset)
{
return tvb_strneql(tvb, offset, MARKER_TAG, MARKER_LEN);
}
static void dissect_fix_init(void) {
}
static int
tag_search(int key)
{
int lower = 0, upper = array_length(fix_fields) -1;
while (lower <= upper) {
int middle = (lower + upper) / 2;
int res = fix_fields[middle].tag;
if (res < key) {
lower = middle + 1;
} else if (res == key) {
return middle;
} else {
upper = middle - 1;
}
}
return -1;
}
static int fix_next_header(tvbuff_t *tvb, int offset)
{
guint min_len = tvb_length_remaining(tvb, offset);
const guint8 *data = tvb_get_string(wmem_packet_scope(), tvb, offset, min_len);
const guint8 *start = data;
while ((start = strstr(start, "\0018"))) {
min_len = (guint) (start +1 -data);
if (tvb_length_remaining(tvb, min_len + offset) < MARKER_LEN)
break;
if (!fix_marker(tvb, min_len +offset) )
break;
start++;
}
return min_len;
}
static fix_parameter *fix_param(tvbuff_t *tvb, int offset)
{
static fix_parameter ret;
int equals;
ret.ctrla_offset = tvb_find_guint8(tvb, offset, -1, 0x01);
if (ret.ctrla_offset == -1) {
return NULL;
}
ret.field_len = ret.ctrla_offset - offset + 1;
equals = tvb_find_guint8(tvb, offset, ret.field_len, '=');
if (equals == -1) {
return NULL;
}
ret.value_offset = equals + 1;
ret.tag_len = ret.value_offset - offset - 1;
ret.value_len = ret.ctrla_offset - ret.value_offset;
return &ret;
}
static int fix_header_len(tvbuff_t *tvb, int offset)
{
int base_offset, ctrla_offset;
char *value;
int size;
fix_parameter *tag;
base_offset = offset;
if (fix_marker(tvb, offset) != 0) {
return fix_next_header(tvb, offset);
}
ctrla_offset = tvb_find_guint8(tvb, offset, -1, 0x01);
if (ctrla_offset == -1) {
return fix_next_header(tvb, offset +MARKER_LEN) +MARKER_LEN;
}
offset = ctrla_offset + 1;
if (!(tag = fix_param(tvb, offset)) || tvb_strneql(tvb, offset, "9=", 2)) {
return fix_next_header(tvb, offset);
}
value = tvb_get_string(wmem_packet_scope(), tvb, tag->value_offset, tag->value_len);
size = atoi(value) +tag->ctrla_offset - base_offset +1;
if (tvb_length_remaining(tvb, base_offset) > size +4) {
offset = base_offset +size;
if (tvb_strneql(tvb, offset, "10=", 3) != 0) {
return fix_next_header(tvb, base_offset +MARKER_LEN) +MARKER_LEN;
}
ctrla_offset = tvb_find_guint8(tvb, offset, -1, 0x01);
if (ctrla_offset == -1) {
return size+7;
}
return size +ctrla_offset -offset +1;
}
else {
}
return size +7;
}
static void
dissect_fix_packet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *fix_tree;
int pdu_len;
int offset = 0;
int field_offset, ctrla_offset;
int tag_value;
char *value;
char *tag_str;
fix_parameter *tag;
const char *msg_type;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "FIX");
col_clear(pinfo->cinfo, COL_INFO);
if (fix_marker(tvb, 0) != 0) {
col_set_str(pinfo->cinfo, COL_INFO, "[FIX continuation]");
ti = proto_tree_add_item(tree, proto_fix, tvb, 0, -1, ENC_NA);
fix_tree = proto_item_add_subtree(ti, ett_fix);
proto_tree_add_item(fix_tree, hf_fix_data, tvb, 0, -1, ENC_NA);
return;
}
pdu_len = tvb_reported_length(tvb);
ti = proto_tree_add_item(tree, proto_fix, tvb, 0, -1, ENC_NA);
fix_tree = proto_item_add_subtree(ti, ett_fix);
ctrla_offset = tvb_find_guint8(tvb, offset, -1, 0x01);
if (ctrla_offset == -1) {
return;
}
offset = ctrla_offset + 1;
ctrla_offset = tvb_find_guint8(tvb, offset, -1, 0x01);
if (ctrla_offset == -1) {
return;
}
offset = ctrla_offset + 1;
if (!(tag = fix_param(tvb, offset)) || tag->value_len < 1) {
return;
}
value = tvb_get_string(wmem_packet_scope(), tvb, tag->value_offset, tag->value_len);
msg_type = str_to_str(value, messages_val, "FIX Message (%s)");
col_add_str(pinfo->cinfo, COL_INFO, msg_type);
field_offset = 0;
while(field_offset < pdu_len && (tag = fix_param(tvb, field_offset)) ) {
int i, found;
if (tag->tag_len < 1) {
field_offset = tag->ctrla_offset + 1;
continue;
}
tag_str = tvb_get_string(wmem_packet_scope(), tvb, field_offset, tag->tag_len);
tag_value = atoi(tag_str);
if (tag->value_len < 1) {
proto_tree *field_tree;
ti = proto_tree_add_text(fix_tree, tvb, field_offset, tag->field_len, "%i: <missing value>", tag_value);
field_tree = proto_item_add_subtree(ti, ett_badfield);
proto_tree_add_uint(field_tree, hf_fix_field_tag, tvb, field_offset, tag->tag_len, tag_value);
field_offset = tag->ctrla_offset + 1;
continue;
}
found = 0;
if ((i = tag_search(tag_value)) >= 0) {
found = 1;
}
value = tvb_get_string(wmem_packet_scope(), tvb, tag->value_offset, tag->value_len);
if (found) {
if (fix_fields[i].table) {
if (tree) {
switch (fix_fields[i].type) {
case 1:
proto_tree_add_string_format_value(fix_tree, fix_fields[i].hf_id, tvb, field_offset, tag->field_len, value,
"%s (%s)", value, str_to_str(value, (string_string *)fix_fields[i].table, "unknown %s"));
break;
case 2:
proto_tree_add_string_format_value(fix_tree, fix_fields[i].hf_id, tvb, field_offset, tag->field_len, value,
"%s (%s)", value, val_to_str(*value, (value_string *)fix_fields[i].table, "unknown %d"));
break;
default:
proto_tree_add_string_format_value(fix_tree, fix_fields[i].hf_id, tvb, field_offset, tag->field_len, value,
"%s (%s)", value, val_to_str(atoi(value), (value_string *)fix_fields[i].table, "unknown %d"));
break;
}
}
}
else {
proto_item *item;
switch(tag_value) {
case 10:
{
proto_tree *checksum_tree;
guint8 sum = 0;
const guint8 *data = tvb_get_ptr(tvb, 0, field_offset);
gboolean sum_ok;
int j;
for (j = 0; j < field_offset; j++, data++) {
sum += *data;
}
sum_ok = (atoi(value) == sum);
if (sum_ok) {
item = proto_tree_add_string_format_value(fix_tree, fix_fields[i].hf_id, tvb, field_offset, tag->field_len,
value, "%s [correct]", value);
}
else {
item = proto_tree_add_string_format_value(fix_tree, fix_fields[i].hf_id, tvb, field_offset, tag->field_len,
value, "%s [incorrect should be %d]", value, sum);
}
checksum_tree = proto_item_add_subtree(item, ett_checksum);
item = proto_tree_add_boolean(checksum_tree, hf_fix_checksum_good, tvb, field_offset, tag->field_len, sum_ok);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_boolean(checksum_tree, hf_fix_checksum_bad, tvb, field_offset, tag->field_len, !sum_ok);
PROTO_ITEM_SET_GENERATED(item);
if (!sum_ok)
expert_add_info(pinfo, item, &ei_fix_checksum_bad);
}
break;
default:
proto_tree_add_string(fix_tree, fix_fields[i].hf_id, tvb, field_offset, tag->field_len, value);
break;
}
}
}
else if (tree) {
proto_tree *field_tree;
ti = proto_tree_add_text(fix_tree, tvb, field_offset, tag->field_len, "%i: %s", tag_value, value);
field_tree = proto_item_add_subtree(ti, ett_unknow);
proto_tree_add_uint(field_tree, hf_fix_field_tag, tvb, field_offset, tag->tag_len, tag_value);
proto_tree_add_item(field_tree, hf_fix_field_value, tvb, tag->value_offset, tag->value_len, ENC_ASCII|ENC_NA);
}
field_offset = tag->ctrla_offset + 1;
tag_str = NULL;
}
return;
}
static guint
get_fix_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
int fix_len;
fix_len = fix_header_len(tvb, offset);
return fix_len;
}
static void
dissect_fix_pdus(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tcp_dissect_pdus(tvb, pinfo, tree, fix_desegment, FIX_MIN_LEN,
get_fix_pdu_len, dissect_fix_packet);
}
static void
dissect_fix(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_fix_pdus(tvb, pinfo, tree);
}
static gboolean
dissect_fix_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
conversation_t *conv;
if (fix_marker(tvb, 0) != 0) {
return FALSE;
}
conv = find_or_create_conversation(pinfo);
conversation_set_dissector(conv, fix_handle);
dissect_fix_pdus(tvb, pinfo, tree);
return TRUE;
}
static void fix_prefs(void)
{
dissector_delete_uint_range("tcp.port", fix_tcp_range, fix_handle);
g_free(fix_tcp_range);
fix_tcp_range = range_copy(global_fix_tcp_range);
dissector_add_uint_range("tcp.port", fix_tcp_range, fix_handle);
}
void
proto_register_fix(void)
{
static hf_register_info hf[] = {
{ &hf_fix_data,
{ "Continuation Data", "fix.data", FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_fix_field_tag,
{ "Field Tag", "fix.field.tag", FT_UINT16, BASE_DEC, NULL, 0x0,
"Field length.", HFILL }},
{ &hf_fix_field_value,
{ "Field Value", "fix.field.value", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_fix_checksum_good,
{ "Good Checksum", "fix.checksum_good", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True: checksum matches packet content; False: doesn't match content or not checked", HFILL }},
{ &hf_fix_checksum_bad,
{ "Bad Checksum", "fix.checksum_bad", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True: checksum doesn't match packet content; False: matches content or not checked", HFILL }},
};
static gint *ett[] = {
&ett_fix,
&ett_unknow,
&ett_badfield,
&ett_checksum,
};
static ei_register_info ei[] = {
{ &ei_fix_checksum_bad, { "fix.checksum_bad.expert", PI_CHECKSUM, PI_ERROR, "Bad checksum", EXPFILL }},
};
module_t *fix_module;
expert_module_t* expert_fix;
register_init_routine(&dissect_fix_init);
proto_fix = proto_register_protocol("Financial Information eXchange Protocol",
"FIX", "fix");
fix_handle = register_dissector("fix", dissect_fix, proto_fix);
proto_register_field_array(proto_fix, hf, array_length(hf));
proto_register_field_array(proto_fix, hf_FIX, array_length(hf_FIX));
proto_register_subtree_array(ett, array_length(ett));
expert_fix = expert_register_protocol(proto_fix);
expert_register_field_array(expert_fix, ei, array_length(ei));
fix_module = prefs_register_protocol(proto_fix, fix_prefs);
prefs_register_bool_preference(fix_module, "desegment",
"Reassemble FIX messages spanning multiple TCP segments",
"Whether the FIX dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable"
" \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&fix_desegment);
prefs_register_range_preference(fix_module, "tcp.port", "TCP Ports", "TCP Ports range", &global_fix_tcp_range, 65535);
fix_tcp_range = range_empty();
}
void
proto_reg_handoff_fix(void)
{
heur_dissector_add("tcp", dissect_fix_heur, proto_fix);
dissector_add_handle("tcp.port", fix_handle);
}
