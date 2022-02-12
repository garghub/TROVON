static int
dissect_ipp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *ipp_tree;
proto_item *ti;
int offset = 0;
gboolean is_request = (pinfo->destport == pinfo->match_uint);
guint16 status_code;
const gchar *status_type;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IPP");
if (is_request)
col_set_str(pinfo->cinfo, COL_INFO, "IPP request");
else
col_set_str(pinfo->cinfo, COL_INFO, "IPP response");
ti = proto_tree_add_item(tree, proto_ipp, tvb, offset, -1, ENC_NA);
ipp_tree = proto_item_add_subtree(ti, ett_ipp);
proto_tree_add_item(ipp_tree, hf_ipp_version, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (is_request) {
proto_tree_add_item(ipp_tree, hf_ipp_operation_id, tvb, offset, 2, ENC_BIG_ENDIAN);
} else {
status_code = tvb_get_ntohs(tvb, offset);
switch (status_code & STATUS_TYPE_MASK) {
case STATUS_SUCCESSFUL:
status_type = "Successful";
break;
case STATUS_INFORMATIONAL:
status_type = "Informational";
break;
case STATUS_REDIRECTION:
status_type = "Redirection";
break;
case STATUS_CLIENT_ERROR:
status_type = "Client error";
break;
case STATUS_SERVER_ERROR:
status_type = "Server error";
break;
default:
status_type = "Unknown";
break;
}
proto_tree_add_uint_format_value(ipp_tree, hf_ipp_status_code, tvb, offset, 2, status_code,
"%s (%s)", status_type, val_to_str(status_code, status_vals, "0x804x"));
}
offset += 2;
proto_tree_add_item(ipp_tree, hf_ipp_request_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = parse_attributes(tvb, offset, ipp_tree);
if (tvb_offset_exists(tvb, offset)) {
call_data_dissector(tvb_new_subset_remaining(tvb, offset), pinfo,
ipp_tree);
}
return tvb_captured_length(tvb);
}
static int
parse_attributes(tvbuff_t *tvb, int offset, proto_tree *tree)
{
guint8 tag;
const gchar *tag_desc;
int name_length, value_length;
proto_tree *as_tree = tree;
proto_item *tas = NULL;
int start_offset = offset;
proto_tree *attr_tree = tree;
proto_tree *subtree = NULL;
while (tvb_offset_exists(tvb, offset)) {
tag = tvb_get_guint8(tvb, offset);
tag_desc = val_to_str(tag, tag_vals, "Reserved (0x%02x)");
if (TAG_TYPE(tag) == TAG_TYPE_DELIMITER) {
if (tas != NULL)
proto_item_set_len(tas, offset - start_offset);
as_tree = NULL;
attr_tree = tree;
start_offset = offset;
subtree = proto_tree_add_subtree(tree, tvb, offset, 1, ett_ipp_as, &tas, tag_desc);
offset += 1;
if (tag == TAG_END_OF_ATTRIBUTES) {
break;
}
} else {
name_length = tvb_get_ntohs(tvb, offset + 1);
value_length = tvb_get_ntohs(tvb, offset + 1 + 2 + name_length);
if (as_tree == NULL) {
as_tree = subtree;
attr_tree = as_tree;
}
switch (TAG_TYPE(tag)) {
case TAG_TYPE_INTEGER:
if (name_length != 0) {
attr_tree = add_integer_tree(as_tree,
tvb, offset, name_length,
value_length, tag);
}
add_integer_value(tag_desc, attr_tree, tvb,
offset, name_length, value_length, tag);
break;
case TAG_TYPE_OCTETSTRING:
if (name_length != 0) {
attr_tree = add_octetstring_tree(as_tree,
tvb, offset, name_length,
value_length);
}
add_octetstring_value(tag_desc, attr_tree, tvb,
offset, name_length, value_length);
break;
case TAG_TYPE_CHARSTRING:
if (name_length != 0) {
attr_tree = add_charstring_tree(as_tree,
tvb, offset, name_length,
value_length);
}
add_charstring_value(tag_desc, attr_tree, tvb,
offset, name_length, value_length);
break;
}
offset += 1 + 2 + name_length + 2 + value_length;
}
}
return offset;
}
static proto_tree *
add_integer_tree(proto_tree *tree, tvbuff_t *tvb, int offset,
int name_length, int value_length, guint8 tag)
{
proto_tree *subtree;
guint8 bool_val;
switch (tag) {
case TAG_BOOLEAN:
if (value_length != 1) {
subtree = proto_tree_add_subtree_format(tree, tvb, offset,
1 + 2 + name_length + 2 + value_length,
ett_ipp_attr, NULL, "%s: Invalid boolean (length is %u, should be 1)",
tvb_format_text(tvb, offset + 1 + 2, name_length),
value_length);
} else {
bool_val = tvb_get_guint8(tvb,
offset + 1 + 2 + name_length + 2);
subtree = proto_tree_add_subtree_format(tree, tvb, offset,
1 + 2 + name_length + 2 + value_length,
ett_ipp_attr, NULL, "%s: %s",
tvb_format_text(tvb, offset + 1 + 2, name_length),
val_to_str(bool_val, bool_vals, "Unknown (0x%02x)"));
}
break;
case TAG_INTEGER:
case TAG_ENUM:
if (value_length != 4) {
subtree = proto_tree_add_subtree_format(tree, tvb, offset,
1 + 2 + name_length + 2 + value_length,
ett_ipp_attr, NULL, "%s: Invalid integer (length is %u, should be 4)",
tvb_format_text(tvb, offset + 1 + 2, name_length),
value_length);
} else {
const char *name_val;
name_val=tvb_get_ptr(tvb, offset + 1 + 2, name_length);
if ((name_length > 5) && name_val && !tvb_memeql(tvb, offset + 1 + 2 + name_length - 5, "-time", 5)) {
subtree = proto_tree_add_subtree_format(tree, tvb, offset,
1 + 2 + name_length + 2 + value_length,
ett_ipp_attr, NULL, "%s: %s",
format_text(name_val, name_length),
abs_time_secs_to_str(wmem_packet_scope(), tvb_get_ntohl(tvb, offset + 1 + 2 + name_length + 2),
ABSOLUTE_TIME_LOCAL,
TRUE));
}
else if ((name_length > 5) && name_val && !tvb_memeql(tvb, offset + 1 + 2, "printer-state", 13)) {
subtree = proto_tree_add_subtree_format(tree, tvb, offset,
1 + 2 + name_length + 2 + value_length,
ett_ipp_attr, NULL, "%s: %s",
format_text(name_val, name_length),
val_to_str_const(tvb_get_ntohl(tvb, offset + 1 + 2 + name_length + 2),
printer_state_vals,
"Unknown Printer State"));
}
else if ((name_length > 5) && name_val && !tvb_memeql(tvb, offset + 1 + 2, "job-state", 9)) {
subtree = proto_tree_add_subtree_format(tree, tvb, offset,
1 + 2 + name_length + 2 + value_length,
ett_ipp_attr, NULL, "%s: %s",
format_text(name_val, name_length),
val_to_str_const(tvb_get_ntohl(tvb, offset + 1 + 2 + name_length + 2),
job_state_vals,
"Unknown Job State"));
}
else {
subtree = proto_tree_add_subtree_format(tree, tvb, offset,
1 + 2 + name_length + 2 + value_length,
ett_ipp_attr, NULL, "%s: %u",
format_text(name_val, name_length),
tvb_get_ntohl(tvb, offset + 1 + 2 + name_length + 2));
}
}
break;
default:
subtree = proto_tree_add_subtree_format(tree, tvb, offset,
1 + 2 + name_length + 2 + value_length,
ett_ipp_attr, NULL, "%s: Unknown integer type 0x%02x",
tvb_format_text(tvb, offset + 1 + 2, name_length),
tag);
break;
}
return subtree;
}
static void
add_integer_value(const gchar *tag_desc, proto_tree *tree, tvbuff_t *tvb,
int offset, int name_length, int value_length, guint8 tag)
{
char *name_val = NULL;
offset = add_value_head(tag_desc, tree, tvb, offset, name_length,
value_length, &name_val);
switch (tag) {
case TAG_BOOLEAN:
if (value_length == 1) {
proto_tree_add_item(tree, hf_ipp_bool_value, tvb, offset, value_length, ENC_BIG_ENDIAN);
}
break;
case TAG_INTEGER:
case TAG_ENUM:
if (value_length == 4) {
if ((name_length > 5) && name_val && !strcmp(name_val+name_length-5, "-time")) {
nstime_t ns;
ns.secs=tvb_get_ntohl(tvb, offset);
ns.nsecs=0;
proto_tree_add_time(tree, hf_ipp_timestamp, tvb, offset, 4, &ns);
}
else if ((name_length > 5) && name_val && !strcmp(name_val, "printer-state")) {
proto_tree_add_item(tree, hf_ipp_printer_state, tvb, offset, value_length, ENC_BIG_ENDIAN);
}
else if ((name_length > 5) && name_val && !strcmp(name_val, "job-state")) {
proto_tree_add_item(tree, hf_ipp_job_state, tvb, offset, value_length, ENC_BIG_ENDIAN);
}
else{
proto_tree_add_item(tree, hf_ipp_uint32_value, tvb, offset, value_length, ENC_BIG_ENDIAN);
}
}
break;
}
}
static proto_tree *
add_octetstring_tree(proto_tree *tree, tvbuff_t *tvb, int offset,
int name_length, int value_length)
{
return proto_tree_add_subtree_format(tree, tvb, offset,
1 + 2 + name_length + 2 + value_length,
ett_ipp_attr, NULL, "%s: %s",
tvb_format_text(tvb, offset + 1 + 2, name_length),
tvb_bytes_to_str(wmem_packet_scope(), tvb, offset + 1 + 2 + name_length + 2, value_length));
}
static void
add_octetstring_value(const gchar *tag_desc, proto_tree *tree, tvbuff_t *tvb,
int offset, int name_length, int value_length)
{
offset = add_value_head(tag_desc, tree, tvb, offset, name_length,
value_length, NULL);
proto_tree_add_item(tree, hf_ipp_bytes_value, tvb, offset, value_length, ENC_NA);
}
static proto_tree *
add_charstring_tree(proto_tree *tree, tvbuff_t *tvb, int offset,
int name_length, int value_length)
{
return proto_tree_add_subtree_format(tree, tvb, offset,
1 + 2 + name_length + 2 + value_length,
ett_ipp_attr, NULL, "%s: %s",
tvb_format_text(tvb, offset + 1 + 2, name_length),
tvb_format_text(tvb, offset + 1 + 2 + name_length + 2, value_length));
}
static void
add_charstring_value(const gchar *tag_desc, proto_tree *tree, tvbuff_t *tvb,
int offset, int name_length, int value_length)
{
offset = add_value_head(tag_desc, tree, tvb, offset, name_length,
value_length, NULL);
proto_tree_add_item(tree, hf_ipp_charstring_value, tvb, offset, value_length, ENC_NA|ENC_ASCII);
}
static int
add_value_head(const gchar *tag_desc, proto_tree *tree, tvbuff_t *tvb,
int offset, int name_length, int value_length, char **name_val)
{
proto_tree_add_string(tree, hf_ipp_tag, tvb, offset, 1, tag_desc);
offset += 1;
proto_tree_add_uint(tree, hf_ipp_name_length, tvb, offset, 2, name_length);
offset += 2;
if (name_length != 0) {
guint8 *nv;
nv = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, name_length, ENC_ASCII);
proto_tree_add_string(tree, hf_ipp_name, tvb, offset, name_length, format_text(nv, name_length));
if (name_val) {
*name_val=nv;
}
}
offset += name_length;
proto_tree_add_uint(tree, hf_ipp_value_length, tvb, offset, 2, value_length);
offset += 2;
return offset;
}
static void
ipp_fmt_version( gchar *result, guint32 revision )
{
g_snprintf( result, ITEM_LABEL_LENGTH, "%u.%u", (guint8)(( revision & 0xFF00 ) >> 8), (guint8)(revision & 0xFF) );
}
void
proto_register_ipp(void)
{
static hf_register_info hf[] = {
{ &hf_ipp_timestamp,
{ "Time", "ipp.timestamp", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, NULL, HFILL }},
{ &hf_ipp_version, { "Version", "ipp.version", FT_UINT16, BASE_CUSTOM, CF_FUNC(ipp_fmt_version), 0x0, NULL, HFILL }},
{ &hf_ipp_operation_id, { "Operation-id", "ipp.operation_id", FT_UINT16, BASE_HEX, VALS(operation_vals), 0x0, NULL, HFILL }},
{ &hf_ipp_status_code, { "Status-code", "ipp.status_code", FT_UINT16, BASE_HEX, VALS(status_vals), 0x0, NULL, HFILL }},
{ &hf_ipp_request_id, { "Request ID", "ipp.request_id", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ipp_bool_value, { "Value", "ipp.bool_value", FT_UINT8, BASE_HEX, VALS(bool_vals), 0x0, NULL, HFILL }},
{ &hf_ipp_printer_state, { "Printer State", "ipp.printer_state", FT_UINT32, BASE_DEC, VALS(printer_state_vals), 0x0, NULL, HFILL }},
{ &hf_ipp_job_state, { "Job State", "ipp.job_state", FT_UINT32, BASE_DEC, VALS(job_state_vals), 0x0, NULL, HFILL }},
{ &hf_ipp_uint32_value, { "Value", "ipp.uint_value", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ipp_bytes_value, { "Value", "ipp.bytes_value", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ipp_charstring_value, { "Value", "ipp.charstring_value", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ipp_tag, { "Tag", "ipp.tag", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ipp_name_length, { "Name length", "ipp.name_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ipp_name, { "Name", "ipp.name", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ipp_value_length, { "Value length", "ipp.value_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_ipp,
&ett_ipp_as,
&ett_ipp_attr,
};
proto_ipp = proto_register_protocol("Internet Printing Protocol", "IPP", "ipp");
proto_register_field_array(proto_ipp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_ipp(void)
{
dissector_handle_t ipp_handle;
ipp_handle = create_dissector_handle(dissect_ipp, proto_ipp);
http_tcp_dissector_add(631, ipp_handle);
dissector_add_string("media_type", "application/ipp", ipp_handle);
}
