static void
dissect_ipp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *ipp_tree;
proto_item *ti;
int offset = 0;
gboolean is_request = (pinfo->destport == pinfo->match_port);
guint16 status_code;
const gchar *status_fmt;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IPP");
if (is_request)
col_set_str(pinfo->cinfo, COL_INFO, "IPP request");
else
col_set_str(pinfo->cinfo, COL_INFO, "IPP response");
if (tree) {
ti = proto_tree_add_item(tree, proto_ipp, tvb, offset, -1, ENC_NA);
ipp_tree = proto_item_add_subtree(ti, ett_ipp);
proto_tree_add_text(ipp_tree, tvb, offset, 2, "Version: %u.%u",
tvb_get_guint8(tvb, offset),
tvb_get_guint8(tvb, offset + 1));
offset += 2;
if (is_request) {
proto_tree_add_text(ipp_tree, tvb, offset, 2, "Operation-id: %s",
val_to_str(tvb_get_ntohs(tvb, offset), operation_vals,
"Unknown (0x%04x)"));
} else {
status_code = tvb_get_ntohs(tvb, offset);
switch (status_code & STATUS_TYPE_MASK) {
case STATUS_SUCCESSFUL:
status_fmt = "Successful (0x%04x)";
break;
case STATUS_INFORMATIONAL:
status_fmt = "Informational (0x%04x)";
break;
case STATUS_REDIRECTION:
status_fmt = "Redirection (0x%04x)";
break;
case STATUS_CLIENT_ERROR:
status_fmt = "Client error (0x%04x)";
break;
case STATUS_SERVER_ERROR:
status_fmt = "Server error (0x%04x)";
break;
default:
status_fmt = "Unknown (0x%04x)";
break;
}
proto_tree_add_text(ipp_tree, tvb, offset, 2, "Status-code: %s",
val_to_str(status_code, status_vals, status_fmt));
}
offset += 2;
proto_tree_add_text(ipp_tree, tvb, offset, 4, "Request ID: %u",
tvb_get_ntohl(tvb, offset));
offset += 4;
offset = parse_attributes(tvb, offset, ipp_tree);
if (tvb_offset_exists(tvb, offset)) {
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, offset), pinfo,
ipp_tree);
}
}
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
while (tvb_offset_exists(tvb, offset)) {
tag = tvb_get_guint8(tvb, offset);
tag_desc = val_to_str(tag, tag_vals, "Reserved (0x%02x)");
if (TAG_TYPE(tag) == TAG_TYPE_DELIMITER) {
if (tas != NULL)
proto_item_set_len(tas, offset - start_offset);
as_tree = NULL;
attr_tree = tree;
start_offset = offset;
tas = proto_tree_add_text(tree, tvb, offset, 1,
"%s", tag_desc);
offset += 1;
if (tag == TAG_END_OF_ATTRIBUTES) {
break;
}
} else {
name_length = tvb_get_ntohs(tvb, offset + 1);
value_length = tvb_get_ntohs(tvb, offset + 1 + 2 + name_length);
if (as_tree == NULL) {
as_tree = proto_item_add_subtree(tas,
ett_ipp_as);
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
proto_item *ti;
guint8 bool_val;
switch (tag) {
case TAG_BOOLEAN:
if (value_length != 1) {
ti = proto_tree_add_text(tree, tvb, offset,
1 + 2 + name_length + 2 + value_length,
"%s: Invalid boolean (length is %u, should be 1)",
tvb_format_text(tvb, offset + 1 + 2, name_length),
value_length);
} else {
bool_val = tvb_get_guint8(tvb,
offset + 1 + 2 + name_length + 2);
ti = proto_tree_add_text(tree, tvb, offset,
1 + 2 + name_length + 2 + value_length,
"%s: %s",
tvb_format_text(tvb, offset + 1 + 2, name_length),
val_to_str(bool_val, bool_vals, "Unknown (0x%02x)"));
}
break;
case TAG_INTEGER:
case TAG_ENUM:
if (value_length != 4) {
ti = proto_tree_add_text(tree, tvb, offset,
1 + 2 + name_length + 2 + value_length,
"%s: Invalid integer (length is %u, should be 4)",
tvb_format_text(tvb, offset + 1 + 2, name_length),
value_length);
} else {
const char *name_val;
name_val=tvb_get_ptr(tvb, offset + 1 + 2, name_length);
if ((name_length > 5) && name_val && !tvb_memeql(tvb, offset + 1 + 2 + name_length - 5, "-time", 5)) {
ti = proto_tree_add_text(tree, tvb, offset,
1 + 2 + name_length + 2 + value_length,
"%s: %s",
format_text(name_val, name_length),
abs_time_secs_to_str(tvb_get_ntohl(tvb, offset + 1 + 2 + name_length + 2),
ABSOLUTE_TIME_LOCAL,
TRUE));
}
else if ((name_length > 5) && name_val && !tvb_memeql(tvb, offset + 1 + 2, "printer-state", 13)) {
ti = proto_tree_add_text(tree, tvb, offset,
1 + 2 + name_length + 2 + value_length,
"%s: %s",
format_text(name_val, name_length),
val_to_str_const(tvb_get_ntohl(tvb, offset + 1 + 2 + name_length + 2),
printer_state_vals,
"Unknown Printer State"));
}
else if ((name_length > 5) && name_val && !tvb_memeql(tvb, offset + 1 + 2, "job-state", 9)) {
ti = proto_tree_add_text(tree, tvb, offset,
1 + 2 + name_length + 2 + value_length,
"%s: %s",
format_text(name_val, name_length),
val_to_str_const(tvb_get_ntohl(tvb, offset + 1 + 2 + name_length + 2),
job_state_vals,
"Unknown Job State"));
}
else {
ti = proto_tree_add_text(tree, tvb, offset,
1 + 2 + name_length + 2 + value_length,
"%s: %u",
format_text(name_val, name_length),
tvb_get_ntohl(tvb, offset + 1 + 2 + name_length + 2));
}
}
break;
default:
ti = proto_tree_add_text(tree, tvb, offset,
1 + 2 + name_length + 2 + value_length,
"%s: Unknown integer type 0x%02x",
tvb_format_text(tvb, offset + 1 + 2, name_length),
tag);
break;
}
return proto_item_add_subtree(ti, ett_ipp_attr);
}
static void
add_integer_value(const gchar *tag_desc, proto_tree *tree, tvbuff_t *tvb,
int offset, int name_length, int value_length, guint8 tag)
{
guint8 bool_val;
char *name_val;
offset = add_value_head(tag_desc, tree, tvb, offset, name_length,
value_length, &name_val);
switch (tag) {
case TAG_BOOLEAN:
if (value_length == 1) {
bool_val = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, value_length,
"Value: %s",
val_to_str(bool_val, bool_vals, "Unknown (0x%02x)"));
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
guint32 printer_state_reason;
printer_state_reason = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, value_length,
"Value: %s (%u)",
val_to_str(printer_state_reason, printer_state_vals,
"Unknown Printer State (0x%02x)"), printer_state_reason);
}
else if ((name_length > 5) && name_val && !strcmp(name_val, "job-state")) {
guint32 job_state_reason;
job_state_reason = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, value_length,
"Value: %s (%u)",
val_to_str(job_state_reason, job_state_vals,
"Unknown Job State (0x%02x)"), job_state_reason);
}
else{
proto_tree_add_text(tree, tvb, offset, value_length,
"Value: %u", tvb_get_ntohl(tvb, offset));
}
}
break;
}
}
static proto_tree *
add_octetstring_tree(proto_tree *tree, tvbuff_t *tvb, int offset,
int name_length, int value_length)
{
proto_item *ti;
ti = proto_tree_add_text(tree, tvb, offset,
1 + 2 + name_length + 2 + value_length,
"%s: %s",
tvb_format_text(tvb, offset + 1 + 2, name_length),
tvb_bytes_to_str(tvb, offset + 1 + 2 + name_length + 2, value_length));
return proto_item_add_subtree(ti, ett_ipp_attr);
}
static void
add_octetstring_value(const gchar *tag_desc, proto_tree *tree, tvbuff_t *tvb,
int offset, int name_length, int value_length)
{
offset = add_value_head(tag_desc, tree, tvb, offset, name_length,
value_length, NULL);
proto_tree_add_text(tree, tvb, offset, value_length,
"Value: %s", tvb_bytes_to_str(tvb, offset, value_length));
}
static proto_tree *
add_charstring_tree(proto_tree *tree, tvbuff_t *tvb, int offset,
int name_length, int value_length)
{
proto_item *ti;
ti = proto_tree_add_text(tree, tvb, offset,
1 + 2 + name_length + 2 + value_length,
"%s: %s",
tvb_format_text(tvb, offset + 1 + 2, name_length),
tvb_format_text(tvb, offset + 1 + 2 + name_length + 2, value_length));
return proto_item_add_subtree(ti, ett_ipp_attr);
}
static void
add_charstring_value(const gchar *tag_desc, proto_tree *tree, tvbuff_t *tvb,
int offset, int name_length, int value_length)
{
offset = add_value_head(tag_desc, tree, tvb, offset, name_length,
value_length, NULL);
proto_tree_add_text(tree, tvb, offset, value_length,
"Value: %s", tvb_format_text(tvb, offset, value_length));
}
static int
add_value_head(const gchar *tag_desc, proto_tree *tree, tvbuff_t *tvb,
int offset, int name_length, int value_length, char **name_val)
{
proto_tree_add_text(tree, tvb, offset, 1, "Tag: %s", tag_desc);
offset += 1;
proto_tree_add_text(tree, tvb, offset, 2, "Name length: %u",
name_length);
offset += 2;
if (name_length != 0) {
guint8 *nv;
nv = tvb_get_ephemeral_string(tvb, offset, name_length);
proto_tree_add_text(tree, tvb, offset, name_length,
"Name: %s", format_text(nv, name_length));
if (name_val) {
*name_val=nv;
}
}
offset += name_length;
proto_tree_add_text(tree, tvb, offset, 2, "Value length: %u",
value_length);
offset += 2;
return offset;
}
void
proto_register_ipp(void)
{
static hf_register_info hf[] = {
{ &hf_ipp_timestamp,
{ "Time", "ipp.timestamp", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_ipp,
&ett_ipp_as,
&ett_ipp_attr,
};
proto_ipp = proto_register_protocol("Internet Printing Protocol",
"IPP", "ipp");
proto_register_field_array(proto_ipp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_ipp(void)
{
dissector_handle_t ipp_handle;
ipp_handle = create_dissector_handle(dissect_ipp, proto_ipp);
http_dissector_add(631, ipp_handle);
dissector_add_string("media_type", "application/ipp", ipp_handle);
data_handle = find_dissector("data");
}
