static int
dissect_ipp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
proto_tree *ipp_tree;
proto_item *ti;
int offset = 0;
http_message_info_t *message_info = (http_message_info_t *)data;
gboolean is_request;
guint16 operation_status;
const gchar *status_type;
guint32 request_id;
conversation_t *conversation;
ipp_conv_info_t *ipp_info;
ipp_transaction_t *ipp_trans;
if (message_info != NULL) {
switch (message_info->type) {
case HTTP_REQUEST:
is_request = TRUE;
break;
case HTTP_RESPONSE:
is_request = FALSE;
break;
default:
is_request = (pinfo->destport == pinfo->match_uint);
break;
}
} else {
is_request = (pinfo->destport == pinfo->match_uint);
}
operation_status = tvb_get_ntohs(tvb, 2);
request_id = tvb_get_ntohl(tvb, 4);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IPP");
if (is_request)
col_add_fstr(pinfo->cinfo, COL_INFO, "IPP Request (%s)", val_to_str(operation_status, operation_vals, "0x%04x"));
else
col_add_fstr(pinfo->cinfo, COL_INFO, "IPP Response (%s)", val_to_str(operation_status, status_vals, "0x%04x"));
ti = proto_tree_add_item(tree, proto_ipp, tvb, offset, -1, ENC_NA);
ipp_tree = proto_item_add_subtree(ti, ett_ipp);
conversation = find_or_create_conversation(pinfo);
ipp_info = (ipp_conv_info_t *)conversation_get_proto_data(conversation, proto_ipp);
if (!ipp_info) {
ipp_info = wmem_new(wmem_file_scope(), ipp_conv_info_t);
ipp_info->pdus=wmem_map_new(wmem_file_scope(), g_direct_hash, g_direct_equal);
conversation_add_proto_data(conversation, proto_ipp, ipp_info);
}
if (!PINFO_FD_VISITED(pinfo)) {
if (is_request) {
ipp_trans=wmem_new(wmem_file_scope(), ipp_transaction_t);
ipp_trans->req_frame = pinfo->num;
ipp_trans->rep_frame = 0;
ipp_trans->req_time = pinfo->fd->abs_ts;
wmem_map_insert(ipp_info->pdus, GUINT_TO_POINTER(request_id), (void *)ipp_trans);
} else {
ipp_trans=(ipp_transaction_t *)wmem_map_lookup(ipp_info->pdus, GUINT_TO_POINTER(request_id));
if (ipp_trans) {
ipp_trans->rep_frame = pinfo->num;
}
}
} else {
ipp_trans=(ipp_transaction_t *)wmem_map_lookup(ipp_info->pdus, GUINT_TO_POINTER(request_id));
}
if (!ipp_trans) {
ipp_trans=wmem_new(wmem_packet_scope(), ipp_transaction_t);
ipp_trans->req_frame = 0;
ipp_trans->rep_frame = 0;
ipp_trans->req_time = pinfo->fd->abs_ts;
}
if (is_request) {
if (ipp_trans->rep_frame) {
proto_item *it;
it = proto_tree_add_uint(ipp_tree, hf_ipp_response_in,
tvb, 0, 0, ipp_trans->rep_frame);
PROTO_ITEM_SET_GENERATED(it);
}
} else {
if (ipp_trans->req_frame) {
proto_item *it;
nstime_t ns;
it = proto_tree_add_uint(ipp_tree, hf_ipp_response_to,
tvb, 0, 0, ipp_trans->req_frame);
PROTO_ITEM_SET_GENERATED(it);
nstime_delta(&ns, &pinfo->fd->abs_ts, &ipp_trans->req_time);
it = proto_tree_add_time(ipp_tree, hf_ipp_response_time, tvb, 0, 0, &ns);
PROTO_ITEM_SET_GENERATED(it);
}
}
proto_tree_add_item(ipp_tree, hf_ipp_version, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (is_request) {
proto_tree_add_item(ipp_tree, hf_ipp_operation_id, tvb, offset, 2, ENC_BIG_ENDIAN);
} else {
switch (operation_status & STATUS_TYPE_MASK) {
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
status_type = "Client Error";
break;
case STATUS_SERVER_ERROR:
status_type = "Server Error";
break;
default:
status_type = "Unknown";
break;
}
proto_tree_add_uint_format_value(ipp_tree, hf_ipp_status_code, tvb, offset, 2, operation_status, "%s (%s)", status_type, val_to_str(operation_status, status_vals, "0x%04x"));
}
offset += 2;
proto_tree_add_item(ipp_tree, hf_ipp_request_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = parse_attributes(tvb, offset, ipp_tree);
if (tvb_offset_exists(tvb, offset)) {
call_data_dissector(tvb_new_subset_remaining(tvb, offset), pinfo, ipp_tree);
}
return tvb_captured_length(tvb);
}
static int
parse_attributes(tvbuff_t *tvb, int offset, proto_tree *tree)
{
guint8 tag;
const gchar *tag_desc;
gchar *name = "";
int name_length, value_length;
proto_tree *as_tree = tree;
proto_item *tas = NULL;
int start_offset = offset;
proto_tree *attr_tree = tree;
proto_tree *subtree = NULL;
while (tvb_offset_exists(tvb, offset)) {
tag = tvb_get_guint8(tvb, offset);
tag_desc = val_to_str(tag, tag_vals, "unknown-%02x");
if (TAG_TYPE(tag) == TAG_TYPE_DELIMITER) {
name = "";
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
if (name_length != 0)
name = tvb_format_text(tvb, offset + 1 + 2, name_length);
value_length = tvb_get_ntohs(tvb, offset + 1 + 2 + name_length);
if (tag == TAG_MEMBERATTRNAME && value_length != 0)
name = tvb_format_text(tvb, offset + 1 + 2 + name_length + 2, value_length);
if (as_tree == NULL) {
as_tree = subtree;
attr_tree = as_tree;
}
switch (TAG_TYPE(tag)) {
case TAG_TYPE_OUTOFBAND :
if (name_length != 0) {
attr_tree = proto_tree_add_subtree_format(as_tree, tvb, offset, 1 + 2 + name_length + 2 + value_length, ett_ipp_attr, NULL, "%s (%s)", name, tag_desc);
}
proto_tree_add_item(attr_tree, hf_ipp_outofband_value, tvb, offset, 1, ENC_NA);
break;
case TAG_TYPE_INTEGER :
if (name_length != 0) {
attr_tree = add_integer_tree(as_tree, tvb, offset, name_length, name, value_length, tag);
}
add_integer_value(tag_desc, attr_tree, tvb, offset, name_length, name, value_length, tag);
break;
case TAG_TYPE_OCTETSTRING :
if (name_length != 0) {
attr_tree = add_octetstring_tree(as_tree, tvb, offset, name_length, name, value_length, tag);
}
if (tag == TAG_ENDCOLLECTION && attr_tree && attr_tree->parent)
attr_tree = attr_tree->parent;
else
attr_tree = add_octetstring_value(tag_desc, attr_tree, tvb, offset, name_length, name, value_length, tag);
break;
case TAG_TYPE_CHARSTRING :
if (name_length != 0) {
attr_tree = add_charstring_tree(as_tree, tvb, offset, tag, name_length, name, value_length);
}
add_charstring_value(tag_desc, attr_tree, tvb, offset, name_length, name, value_length, tag);
break;
default :
if (name_length != 0) {
attr_tree = proto_tree_add_subtree_format(as_tree, tvb, offset, 1 + 2 + name_length + 2 + value_length, ett_ipp_attr, NULL, "%s (%s)", name, tag_desc);
}
proto_tree_add_item(attr_tree, hf_ipp_unknown_value, tvb, offset + 1 + 2 + name_length + 2, value_length, ENC_NA);
break;
}
offset += 1 + 2 + name_length + 2 + value_length;
}
}
return offset;
}
static proto_tree *
add_integer_tree(proto_tree *tree, tvbuff_t *tvb, int offset,
int name_length, const gchar *name, int value_length, guint8 tag)
{
int count = 0;
const char *type = val_to_str_const(tag, tag_vals, "unknown-%02x");
gchar *value = NULL;
int valoffset = offset;
switch (tag) {
case TAG_BOOLEAN:
if (value_length == 1) {
value = wmem_strdup(wmem_packet_scope(), tvb_get_guint8(tvb, offset + 1 + 2 + name_length + 2) ? "true" : "false");
}
else {
value = wmem_strdup(wmem_packet_scope(), "???");
}
valoffset += 1 + 2 + name_length + 2 + value_length;
break;
case TAG_INTEGER :
do
{
char* temp;
count ++;
valoffset += 1 + 2 + name_length + 2;
if (!tvb_offset_exists(tvb, valoffset + value_length))
break;
if (value_length == 8) {
guint32 lower = tvb_get_ntohl(tvb, valoffset + 0);
guint32 upper = tvb_get_ntohl(tvb, valoffset + 4);
temp = wmem_strdup_printf(wmem_packet_scope(), "%d-%d", lower, upper);
}
else if (value_length == 4) {
temp = wmem_strdup_printf(wmem_packet_scope(), "%d", tvb_get_ntohl(tvb, valoffset + 0));
}
else {
temp = "???";
}
if (value)
value = wmem_strconcat(wmem_packet_scope(), value, ",", temp, NULL);
else
value = wmem_strdup(wmem_packet_scope(), temp);
valoffset += value_length;
if (!tvb_offset_exists(tvb, valoffset + 3))
break;
tag = tvb_get_guint8(tvb, valoffset);
name_length = tvb_get_ntohs(tvb, valoffset + 1);
if (!tvb_offset_exists(tvb, valoffset + 1 + 2 + name_length + 2))
break;
value_length = tvb_get_ntohs(tvb, valoffset + 1 + 2 + name_length);
}
while (name_length == 0 && (tag == TAG_INTEGER || tag == TAG_RANGEOFINTEGER));
break;
case TAG_ENUM :
do
{
const gchar* temp;
count ++;
valoffset += 1 + 2 + name_length + 2;
if (!tvb_offset_exists(tvb, valoffset + value_length))
break;
if (value_length != 4) {
temp = "???";
} else {
if (!strncmp(name, "printer-state", 13)) {
temp = val_to_str_const(tvb_get_ntohl(tvb, valoffset), printer_state_vals, "unknown-%d");
}
else if (!strncmp(name, "job-state", 9)) {
temp = val_to_str_const(tvb_get_ntohl(tvb, valoffset), job_state_vals, "unknown-%d");
}
else if (!strncmp(name, "document-state", 14)) {
temp = val_to_str_const(tvb_get_ntohl(tvb, valoffset), document_state_vals, "unknown-%d");
}
else if (!strncmp(name, "operations-supported", 20)) {
temp = val_to_str_const(tvb_get_ntohl(tvb, valoffset), operation_vals, "unknown-%04x");
}
else if (!strncmp(name, "finishings", 10)) {
temp = val_to_str_const(tvb_get_ntohl(tvb, valoffset), finishings_vals, "unknown-%d");
}
else if (!strncmp(name, "orientation-requested", 21) || !strncmp(name, "media-feed-orientation", 22)) {
temp = val_to_str_const(tvb_get_ntohl(tvb, valoffset), orientation_vals, "unknown-%d");
}
else if (!strncmp(name, "print-quality", 13)) {
temp = val_to_str_const(tvb_get_ntohl(tvb, valoffset), quality_vals, "unknown-%d");
}
else if (!strncmp(name, "transmission-status", 19)) {
temp = val_to_str_const(tvb_get_ntohl(tvb, valoffset), transmission_status_vals, "unknown-%d");
}
else {
temp = wmem_strdup_printf(wmem_packet_scope(), "%d", tvb_get_ntohl(tvb, offset + 1 + 2 + name_length + 2));
}
}
if (value)
value = wmem_strconcat(wmem_packet_scope(), value, ",", temp, NULL);
else
value = wmem_strdup(wmem_packet_scope(), temp);
valoffset += value_length;
if (!tvb_offset_exists(tvb, valoffset + 3))
break;
tag = tvb_get_guint8(tvb, valoffset);
name_length = tvb_get_ntohs(tvb, valoffset + 1);
if (!tvb_offset_exists(tvb, valoffset + 1 + 2 + name_length + 2))
break;
value_length = tvb_get_ntohs(tvb, valoffset + 1 + 2 + name_length);
}
while (name_length == 0 && tag == TAG_ENUM);
break;
default:
value = wmem_strdup(wmem_packet_scope(), "???");
break;
}
return proto_tree_add_subtree_format(tree, tvb, offset, valoffset - offset, ett_ipp_attr, NULL, "%s (%s%s): %s", name, count > 1 ? "1setOf " : "", type, value);
}
static void
add_integer_value(const gchar *tag_desc, proto_tree *tree, tvbuff_t *tvb,
int offset, int name_length, const gchar *name, int value_length, guint8 tag)
{
int valoffset = offset + 1 + 2 + name_length + 2;
if (name_length > 0)
proto_tree_add_item(tree, hf_ipp_name, tvb, offset + 1 + 2, name_length, ENC_ASCII|ENC_NA);
switch (tag) {
case TAG_BOOLEAN:
if (value_length == 1) {
proto_tree_add_item(tree, hf_ipp_boolean_value, tvb, valoffset, value_length, ENC_BIG_ENDIAN);
}
else {
proto_tree_add_boolean_format(tree, hf_ipp_boolean_value, tvb, valoffset, value_length, 0, "boolean value: ??? %d bytes ???", value_length);
}
break;
case TAG_INTEGER:
if (value_length == 4) {
proto_tree_add_item(tree, hf_ipp_integer_value, tvb, valoffset, value_length, ENC_BIG_ENDIAN);
}
else {
proto_tree_add_int_format(tree, hf_ipp_integer_value, tvb, valoffset, value_length, 0, "integer value: ??? %d bytes ???", value_length);
}
break;
case TAG_ENUM:
if (value_length == 4) {
if (!strncmp(name, "printer-state", 13)) {
proto_tree_add_item(tree, hf_ipp_enum_value_printer_state, tvb, valoffset, value_length, ENC_BIG_ENDIAN);
}
else if (!strncmp(name, "job-state", 9)) {
proto_tree_add_item(tree, hf_ipp_enum_value_job_state, tvb, valoffset, value_length, ENC_BIG_ENDIAN);
}
else if (!strncmp(name, "document-state", 14)) {
proto_tree_add_item(tree, hf_ipp_enum_value_document_state, tvb, valoffset, value_length, ENC_BIG_ENDIAN);
}
else if (!strncmp(name, "operations-supported", 20)) {
proto_tree_add_item(tree, hf_ipp_enum_value_operations_supported, tvb, valoffset, value_length, ENC_BIG_ENDIAN);
}
else if (!strncmp(name, "finishings", 10)) {
proto_tree_add_item(tree, hf_ipp_enum_value_finishings, tvb, valoffset, value_length, ENC_BIG_ENDIAN);
}
else if (!strncmp(name, "orientation-requested", 21) || !strncmp(name, "media-feed-orientation", 22)) {
proto_tree_add_item(tree, hf_ipp_enum_value_orientation, tvb, valoffset, value_length, ENC_BIG_ENDIAN);
}
else if (!strncmp(name, "print-quality", 13)) {
proto_tree_add_item(tree, hf_ipp_enum_value_print_quality, tvb, valoffset, value_length, ENC_BIG_ENDIAN);
}
else if (!strncmp(name, "transmission-status", 19)) {
proto_tree_add_item(tree, hf_ipp_enum_value_transmission_status, tvb, valoffset, value_length, ENC_BIG_ENDIAN);
}
else {
proto_tree_add_item(tree, hf_ipp_enum_value, tvb, valoffset, value_length, ENC_BIG_ENDIAN);
}
}
else {
proto_tree_add_int_format_value(tree, hf_ipp_enum_value, tvb, valoffset, value_length, 0, "??? %d bytes ???", value_length);
}
break;
default :
proto_tree_add_string_format(tree, hf_ipp_integer_value, tvb, valoffset, value_length, 0, "%s value: ??? %d bytes ???", tag_desc, value_length);
break;
}
}
static proto_tree *
add_octetstring_tree(proto_tree *tree, tvbuff_t *tvb, int offset, int name_length, const gchar *name, int value_length, guint8 tag)
{
int count = 0;
const char *type = val_to_str_const(tag, tag_vals, "unknown-%02x");
gchar *value = NULL;
int valoffset = offset;
switch (tag) {
case TAG_OCTETSTRING :
do {
count ++;
if (value)
value = wmem_strconcat(wmem_packet_scope(), value, ",'", tvb_format_text(tvb, valoffset + 1 + 2 + name_length + 2, value_length), "'", NULL);
else
value = wmem_strconcat(wmem_packet_scope(), "'", tvb_format_text(tvb, valoffset + 1 + 2 + name_length + 2, value_length), "'", NULL);
valoffset += 1 + 2 + name_length + 2 + value_length;
if (!tvb_offset_exists(tvb, valoffset + 3))
break;
tag = tvb_get_guint8(tvb, valoffset);
name_length = tvb_get_ntohs(tvb, valoffset + 1);
if (!tvb_offset_exists(tvb, valoffset + 1 + 2 + name_length + 2))
break;
value_length = tvb_get_ntohs(tvb, valoffset + 1 + 2 + name_length);
}
while (name_length == 0 && tag == TAG_OCTETSTRING);
break;
case TAG_DATETIME :
valoffset += 1 + 2 + name_length + 2;
if (value_length == 11) {
guint16 year = tvb_get_ntohs(tvb, valoffset + 0);
guint8 month = tvb_get_guint8(tvb, valoffset + 2);
guint8 day = tvb_get_guint8(tvb, valoffset + 3);
guint8 hours = tvb_get_guint8(tvb, valoffset + 4);
guint8 minutes = tvb_get_guint8(tvb, valoffset + 5);
guint8 seconds = tvb_get_guint8(tvb, valoffset + 6);
guint8 decisecs = tvb_get_guint8(tvb, valoffset + 7);
guint8 utcsign = tvb_get_guint8(tvb, valoffset + 8);
guint8 utchours = tvb_get_guint8(tvb, valoffset + 9);
guint8 utcminutes = tvb_get_guint8(tvb, valoffset + 10);
value = wmem_strdup_printf(wmem_packet_scope(), "%04d-%02d-%02dT%02d:%02d:%02d.%d%c%02d%02d", year, month, day, hours, minutes, seconds, decisecs, utcsign, utchours, utcminutes);
} else {
value = wmem_strdup(wmem_packet_scope(), "???");
}
valoffset += value_length;
break;
case TAG_RESOLUTION :
do {
char* temp;
count ++;
valoffset += 1 + 2 + name_length + 2;
if (value_length == 9 && tvb_offset_exists(tvb, valoffset + value_length)) {
int xres = tvb_get_ntohl(tvb, valoffset + 0);
int yres = tvb_get_ntohl(tvb, valoffset + 4);
guint8 units = tvb_get_guint8(tvb, valoffset + 8);
temp = wmem_strdup_printf(wmem_packet_scope(), "%dx%d%s", xres, yres, units == 3 ? "dpi" : units == 4 ? "dpcm" : "unknown");
}
else {
temp = "???";
}
if (value)
value = wmem_strconcat(wmem_packet_scope(), value, ",", temp, NULL);
else
value = wmem_strdup(wmem_packet_scope(), temp);
valoffset += value_length;
if (!tvb_offset_exists(tvb, valoffset + 3))
break;
tag = tvb_get_guint8(tvb, valoffset);
name_length = tvb_get_ntohs(tvb, valoffset + 1);
if (!tvb_offset_exists(tvb, valoffset + 1 + 2 + name_length + 2))
break;
value_length = tvb_get_ntohs(tvb, valoffset + 1 + 2 + name_length);
}
while (name_length == 0 && tag == TAG_RESOLUTION);
break;
case TAG_RANGEOFINTEGER :
do {
char* temp;
count ++;
valoffset += 1 + 2 + name_length + 2;
if (!tvb_offset_exists(tvb, valoffset + value_length))
break;
if (value_length == 8) {
guint32 lower = tvb_get_ntohl(tvb, valoffset + 0);
guint32 upper = tvb_get_ntohl(tvb, valoffset + 4);
temp = wmem_strdup_printf(wmem_packet_scope(), "%d-%d", lower, upper);
}
else if (value_length == 4) {
temp = wmem_strdup_printf(wmem_packet_scope(), "%d", tvb_get_ntohl(tvb, valoffset + 0));
}
else {
temp = "???";
}
if (value)
value = wmem_strconcat(wmem_packet_scope(), value, ",", temp, NULL);
else
value = wmem_strdup(wmem_packet_scope(), temp);
valoffset += value_length;
if (!tvb_offset_exists(tvb, valoffset + 3))
break;
tag = tvb_get_guint8(tvb, valoffset);
name_length = tvb_get_ntohs(tvb, valoffset + 1);
if (!tvb_offset_exists(tvb, valoffset + 1 + 2 + name_length + 2))
break;
value_length = tvb_get_ntohs(tvb, valoffset + 1 + 2 + name_length);
}
while (name_length == 0 && (tag == TAG_RANGEOFINTEGER || tag == TAG_INTEGER));
break;
case TAG_TEXTWITHLANGUAGE :
case TAG_NAMEWITHLANGUAGE :
do {
char *temp = NULL;
count ++;
if ((tag == TAG_NAMEWITHLANGUAGE || tag == TAG_TEXTWITHLANGUAGE) && value_length > 4) {
int language_length = tvb_get_ntohs(tvb, valoffset + 0);
int string_length;
if (tvb_offset_exists(tvb, valoffset + 2 + language_length)) {
string_length = tvb_get_ntohs(tvb, valoffset + 2 + language_length);
if (tvb_offset_exists(tvb, valoffset + 2 + language_length + 2 + string_length)) {
temp = wmem_strdup_printf(wmem_packet_scope(), "'%s'(%s)", tvb_format_text(tvb, valoffset + 1 + 2 + name_length + 2 + 2 + language_length + 2, string_length), tvb_format_text(tvb, valoffset + 1 + 2 + name_length + 2 + 2, language_length));
}
}
}
else {
temp = wmem_strdup_printf(wmem_packet_scope(), "'%s'", tvb_format_text(tvb, valoffset + 1 + 2 + name_length + 2, value_length));
}
if (value)
value = wmem_strconcat(wmem_packet_scope(), value, ",", temp, NULL);
else
value = wmem_strdup(wmem_packet_scope(), temp);
valoffset += 1 + 2 + name_length + 2 + value_length;
if (!tvb_offset_exists(tvb, valoffset + 3))
break;
tag = tvb_get_guint8(tvb, valoffset);
name_length = tvb_get_ntohs(tvb, valoffset + 1);
if (!tvb_offset_exists(tvb, valoffset + 1 + 2 + name_length + 2))
break;
value_length = tvb_get_ntohs(tvb, valoffset + 1 + 2 + name_length);
}
while (name_length == 0 && (TAG_TYPE(tag) == TAG_TYPE_CHARSTRING || tag == TAG_NAMEWITHLANGUAGE || tag == TAG_TEXTWITHLANGUAGE));
break;
case TAG_BEGCOLLECTION :
do {
char temp[1024];
count ++;
valoffset = ipp_fmt_collection(tvb, valoffset + 1 + 2 + name_length + 2 + value_length, temp, sizeof(temp));
if (value)
value = wmem_strconcat(wmem_packet_scope(), value, ",", temp, NULL);
else
value = wmem_strdup(wmem_packet_scope(), temp);
if (!tvb_offset_exists(tvb, valoffset + 3))
break;
tag = tvb_get_guint8(tvb, valoffset);
name_length = tvb_get_ntohs(tvb, valoffset + 1);
if (!tvb_offset_exists(tvb, valoffset + 1 + 2 + name_length + 2))
break;
value_length = tvb_get_ntohs(tvb, valoffset + 1 + 2 + name_length);
}
while (name_length == 0 && tag == TAG_BEGCOLLECTION);
break;
default :
value = wmem_strdup(wmem_packet_scope(), tvb_bytes_to_str(wmem_packet_scope(), tvb, offset + 1 + 2 + name_length + 2, value_length));
valoffset += 1 + 2 + name_length + 2 + value_length;
break;
}
return proto_tree_add_subtree_format(tree, tvb, offset, valoffset - offset, ett_ipp_attr, NULL, "%s (%s%s): %s", name, count > 1 ? "1setOf " : "", type, value);
}
static proto_tree *
add_octetstring_value(const gchar *tag_desc, proto_tree *tree, tvbuff_t *tvb,
int offset, int name_length, const gchar *name _U_, int value_length, guint8 tag)
{
proto_tree *subtree = tree;
char value[176];
int valoffset = offset + 1 + 2 + name_length + 2;
int endoffset;
if (name_length > 0)
proto_tree_add_item(tree, hf_ipp_name, tvb, offset + 1 + 2, name_length, ENC_ASCII|ENC_NA);
switch (tag) {
case TAG_OCTETSTRING :
proto_tree_add_item(tree, hf_ipp_octetstring_value, tvb, valoffset, value_length, ENC_ASCII|ENC_NA);
break;
case TAG_DATETIME :
if (value_length == 11) {
guint16 year = tvb_get_ntohs(tvb, valoffset + 0);
guint8 month = tvb_get_guint8(tvb, valoffset + 2);
guint8 day = tvb_get_guint8(tvb, valoffset + 3);
guint8 hours = tvb_get_guint8(tvb, valoffset + 4);
guint8 minutes = tvb_get_guint8(tvb, valoffset + 5);
guint8 seconds = tvb_get_guint8(tvb, valoffset + 6);
guint8 decisecs = tvb_get_guint8(tvb, valoffset + 7);
guint8 utcsign = tvb_get_guint8(tvb, valoffset + 8);
guint8 utchours = tvb_get_guint8(tvb, valoffset + 9);
guint8 utcminutes = tvb_get_guint8(tvb, valoffset + 10);
proto_tree_add_bytes_format(tree, hf_ipp_datetime_value, tvb, valoffset, value_length, NULL, "dateTime value: %04d-%02d-%02dT%02d:%02d:%02d.%d%c%02d%02d", year, month, day, hours, minutes, seconds, decisecs, utcsign, utchours, utcminutes);
}
else {
proto_tree_add_item(tree, hf_ipp_datetime_value, tvb, valoffset, value_length, ENC_NA);
}
break;
case TAG_RESOLUTION :
if (value_length == 9) {
int xres = tvb_get_ntohl(tvb, valoffset + 0);
int yres = tvb_get_ntohl(tvb, valoffset + 4);
guint8 units = tvb_get_guint8(tvb, valoffset + 8);
proto_tree_add_bytes_format(tree, hf_ipp_resolution_value, tvb, valoffset, value_length, NULL, "resolution value: %dx%d%s", xres, yres, units == 3 ? "dpi" : units == 4 ? "dpcm" : "unknown");
}
else {
proto_tree_add_item(tree, hf_ipp_resolution_value, tvb, valoffset, value_length, ENC_NA);
}
break;
case TAG_RANGEOFINTEGER :
if (value_length == 8) {
int lower = tvb_get_ntohl(tvb, valoffset + 0);
int upper = tvb_get_ntohl(tvb, valoffset + 4);
proto_tree_add_bytes_format(tree, hf_ipp_rangeofinteger_value, tvb, valoffset, value_length, NULL, "rangeOfInteger value: %d-%d", lower, upper);
}
else {
proto_tree_add_item(tree, hf_ipp_rangeofinteger_value, tvb, valoffset, value_length, ENC_NA);
}
break;
case TAG_TEXTWITHLANGUAGE :
case TAG_NAMEWITHLANGUAGE :
if (value_length > 4) {
int language_length = tvb_get_ntohs(tvb, valoffset + 0);
if (tvb_offset_exists(tvb, valoffset + 2 + language_length)) {
int string_length = tvb_get_ntohs(tvb, valoffset + 2 + language_length);
if (tvb_offset_exists(tvb, valoffset + 2 + language_length + 2 + string_length)) {
proto_tree_add_bytes_format(tree, tag == TAG_NAMEWITHLANGUAGE ? hf_ipp_namewithlanguage_value : hf_ipp_textwithlanguage_value, tvb, valoffset, value_length, NULL, "%s value: '%s'(%s)", tag_desc, tvb_format_text(tvb, valoffset + 1 + 2 + name_length + 2 + 2 + language_length + 2, string_length), tvb_format_text(tvb, valoffset + 1 + 2 + name_length + 2 + 2, language_length));
break;
}
}
}
if (tag == TAG_NAMEWITHLANGUAGE) {
proto_tree_add_item(tree, hf_ipp_namewithlanguage_value, tvb, valoffset, value_length, ENC_NA);
}
else {
proto_tree_add_item(tree, hf_ipp_textwithlanguage_value, tvb, valoffset, value_length, ENC_NA);
}
break;
case TAG_BEGCOLLECTION :
endoffset = ipp_fmt_collection(tvb, valoffset + value_length, value, sizeof(value));
subtree = proto_tree_add_subtree_format(tree, tvb, valoffset, endoffset - valoffset, ett_ipp_member, NULL, "collection %s", value);
break;
default :
proto_tree_add_string_format(tree, hf_ipp_octetstring_value, tvb, valoffset, value_length, NULL, "%s value: ??? %d bytes ???", tag_desc, value_length);
break;
}
return subtree;
}
static proto_tree *
add_charstring_tree(proto_tree *tree, tvbuff_t *tvb, int offset,
guint8 tag, int name_length, const gchar *name, int value_length)
{
int count = 0, valoffset = offset;
const char *type = val_to_str_const(tag, tag_vals, "unknown-%02x");
gchar *value = NULL;
do {
gchar *temp = NULL;
count ++;
if ((tag == TAG_NAMEWITHLANGUAGE || tag == TAG_TEXTWITHLANGUAGE) && value_length > 4) {
int language_length = tvb_get_ntohs(tvb, valoffset + 0);
int string_length;
if (tvb_offset_exists(tvb, valoffset + 2 + language_length)) {
string_length = tvb_get_ntohs(tvb, valoffset + 2 + language_length);
if (tvb_offset_exists(tvb, valoffset + 2 + language_length + 2 + string_length)) {
temp = wmem_strdup_printf(wmem_packet_scope(), "'%s'(%s)", tvb_format_text(tvb, valoffset + 1 + 2 + name_length + 2 + 2 + language_length + 2, string_length), tvb_format_text(tvb, valoffset + 1 + 2 + name_length + 2 + 2, language_length));
}
}
}
else {
temp = wmem_strdup_printf(wmem_packet_scope(), "'%s'", tvb_format_text(tvb, valoffset + 1 + 2 + name_length + 2, value_length));
}
if (value)
value = wmem_strconcat(wmem_packet_scope(), value, ",", temp, NULL);
else
value = wmem_strdup(wmem_packet_scope(), temp);
valoffset += 1 + 2 + name_length + 2 + value_length;
if (!tvb_offset_exists(tvb, valoffset + 3))
break;
tag = tvb_get_guint8(tvb, valoffset);
name_length = tvb_get_ntohs(tvb, valoffset + 1);
if (!tvb_offset_exists(tvb, valoffset + 1 + 2 + name_length + 2))
break;
value_length = tvb_get_ntohs(tvb, valoffset + 1 + 2 + name_length);
}
while (name_length == 0 && (TAG_TYPE(tag) == TAG_TYPE_CHARSTRING || tag == TAG_NAMEWITHLANGUAGE || tag == TAG_TEXTWITHLANGUAGE));
return proto_tree_add_subtree_format(tree, tvb, offset, valoffset - offset, ett_ipp_attr, NULL, "%s (%s%s): %s", name, count > 1 ? "1setOf " : "", type, value);
}
static void
add_charstring_value(const gchar *tag_desc, proto_tree *tree, tvbuff_t *tvb,
int offset, int name_length, const gchar *name _U_, int value_length, guint8 tag)
{
int valoffset = offset + 1 + 2 + name_length + 2;
if (name_length > 0)
proto_tree_add_item(tree, hf_ipp_name, tvb, offset + 1 + 2, name_length, ENC_ASCII|ENC_NA);
if (tag == TAG_MEMBERATTRNAME)
proto_tree_add_item(tree, hf_ipp_memberattrname, tvb, valoffset, value_length, ENC_ASCII|ENC_NA);
else
proto_tree_add_string_format(tree, hf_ipp_charstring_value, tvb, valoffset, value_length, NULL, "%s value: '%s'", tag_desc, tvb_format_text(tvb, valoffset, value_length));
}
static int
ipp_fmt_collection(tvbuff_t *tvb, int valoffset, char *buffer, int bufsize)
{
char *bufptr = buffer, *bufend = buffer + bufsize - 1;
guint8 tag;
int name_length, value_length;
int overflow = 0;
*bufptr++ = '{';
buffer ++;
do {
if (!tvb_offset_exists(tvb, valoffset + 3))
break;
tag = tvb_get_guint8(tvb, valoffset);
name_length = tvb_get_ntohs(tvb, valoffset + 1);
if (!tvb_offset_exists(tvb, valoffset + 1 + 2 + name_length + 2))
break;
value_length = tvb_get_ntohs(tvb, valoffset + 1 + 2 + name_length);
if (!tvb_offset_exists(tvb, valoffset + 1 + 2 + name_length + 2 + value_length))
break;
if (tag == TAG_MEMBERATTRNAME && !overflow) {
if (bufptr > buffer && bufptr < bufend)
*bufptr++ = ',';
if ((bufend - bufptr) < value_length) {
g_strlcpy(bufptr, "...", bufend - bufptr + 1);
overflow = 1;
}
else {
g_strlcpy(bufptr, tvb_format_text(tvb, valoffset + 1 + 2 + name_length + 2, value_length), bufend - bufptr + 1);
}
bufptr += strlen(bufptr);
}
valoffset += 1 + 2 + name_length + 2 + value_length;
if (tag == TAG_BEGCOLLECTION) {
char temp[176];
valoffset = ipp_fmt_collection(tvb, valoffset, temp, sizeof(temp));
if (!overflow) {
if ((bufend - bufptr) < (int)strlen(temp)) {
g_strlcpy(bufptr, "...", bufend - bufptr + 1);
overflow = 1;
}
else {
g_strlcpy(bufptr, temp, bufend - bufptr + 1);
}
bufptr += strlen(bufptr);
}
}
} while (tag != TAG_ENDCOLLECTION);
if (bufptr < bufend)
*bufptr++ = '}';
*bufptr = '\0';
return (valoffset);
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
{ &hf_ipp_version, { "version", "ipp.version", FT_UINT16, BASE_CUSTOM, CF_FUNC(ipp_fmt_version), 0x0, NULL, HFILL }},
{ &hf_ipp_operation_id, { "operation-id", "ipp.operation_id", FT_UINT16, BASE_HEX, VALS(operation_vals), 0x0, NULL, HFILL }},
{ &hf_ipp_status_code, { "status-code", "ipp.status_code", FT_UINT16, BASE_HEX, VALS(status_vals), 0x0, NULL, HFILL }},
{ &hf_ipp_request_id, { "request-id", "ipp.request_id", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ipp_name, { "name", "ipp.name", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ipp_memberattrname, { "memberAttrName", "ipp.memberattrname", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ipp_boolean_value, { "boolean value", "ipp.boolean_value", FT_UINT8, BASE_HEX, VALS(boolean_vals), 0x0, NULL, HFILL }},
{ &hf_ipp_integer_value, { "integer value", "ipp.integer_value", FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ipp_enum_value, { "enum value", "ipp.enum_value", FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ipp_enum_value_printer_state, { "printer-state", "ipp.enum_value", FT_INT32, BASE_DEC, VALS(printer_state_vals), 0x0, NULL, HFILL }},
{ &hf_ipp_enum_value_job_state, { "job-state", "ipp.enum_value", FT_INT32, BASE_DEC, VALS(job_state_vals), 0x0, NULL, HFILL }},
{ &hf_ipp_enum_value_document_state, { "document-state", "ipp.enum_value", FT_INT32, BASE_DEC, VALS(document_state_vals), 0x0, NULL, HFILL }},
{ &hf_ipp_enum_value_operations_supported, { "operations-supported", "ipp.enum_value", FT_INT32, BASE_DEC, VALS(operation_vals), 0x0, NULL, HFILL }},
{ &hf_ipp_enum_value_finishings, { "finishings", "ipp.enum_value", FT_INT32, BASE_DEC, VALS(finishings_vals), 0x0, NULL, HFILL }},
{ &hf_ipp_enum_value_orientation, { "orientation", "ipp.enum_value", FT_INT32, BASE_DEC, VALS(orientation_vals), 0x0, NULL, HFILL }},
{ &hf_ipp_enum_value_print_quality, { "print-quality", "ipp.enum_value", FT_INT32, BASE_DEC, VALS(quality_vals), 0x0, NULL, HFILL }},
{ &hf_ipp_enum_value_transmission_status, { "transmission-status", "ipp.enum_value", FT_INT32, BASE_DEC, VALS(transmission_status_vals), 0x0, NULL, HFILL }},
{ &hf_ipp_outofband_value, { "out-of-band value", "ipp.outofband_value", FT_UINT8, BASE_HEX, VALS(tag_vals), 0x0, NULL, HFILL }},
{ &hf_ipp_charstring_value, { "string value", "ipp.charstring_value", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ipp_octetstring_value, { "octetString value", "ipp.octetstring_value", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ipp_datetime_value, { "dateTime value", "ipp.datetime_value", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ipp_resolution_value, { "resolution value", "ipp.resolution_value", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ipp_rangeofinteger_value, { "rangeOfInteger value", "ipp.rangeofinteger_value", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ipp_textwithlanguage_value, { "textWithLanguage value", "ipp.textwithlanguage_value", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ipp_namewithlanguage_value, { "nameWithLanguage value", "ipp.namewithlanguage_value", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ipp_unknown_value, { "unknown value", "ipp.unknown_value", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ipp_response_in, { "Response In", "ipp.response_in", FT_FRAMENUM, BASE_NONE, FRAMENUM_TYPE(FT_FRAMENUM_RESPONSE), 0x0, "The response to this IPP request is in this frame", HFILL }},
{ &hf_ipp_response_to, { "Request In", "ipp.response_to", FT_FRAMENUM, BASE_NONE, FRAMENUM_TYPE(FT_FRAMENUM_REQUEST), 0x0, "This is a response to the IPP request in this frame", HFILL }},
{ &hf_ipp_response_time, { "Response Time", "ipp.response_time", FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0, "The time between the Request and the Response", HFILL }}
};
static gint *ett[] = {
&ett_ipp,
&ett_ipp_as,
&ett_ipp_attr,
&ett_ipp_member
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
