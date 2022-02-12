static gint round_to_2byte(gint current_offset,
gint starting_offset)
{
gint length = current_offset - starting_offset;
return starting_offset + ROUND_TO_2BYTE(length);
}
static gint round_to_4byte(gint current_offset,
gint starting_offset)
{
gint length = current_offset - starting_offset;
return starting_offset + ROUND_TO_4BYTE(length);
}
static gint round_to_8byte(gint current_offset,
gint starting_offset)
{
gint length = current_offset - starting_offset;
return starting_offset + ROUND_TO_8BYTE(length);
}
static guint32
get_uint32(tvbuff_t *tvb,
gint32 offset,
gint encoding)
{
return (ENC_BIG_ENDIAN == encoding) ?
tvb_get_ntohl(tvb, offset) :
tvb_get_letohl(tvb, offset);
}
static gint
handle_message_connect(tvbuff_t *tvb,
packet_info *pinfo,
gint offset,
proto_tree *message_tree)
{
guint8 the_one_byte;
the_one_byte = tvb_get_guint8(tvb, offset);
if(0 == the_one_byte) {
col_set_str(pinfo->cinfo, COL_INFO, "CONNECT-initial byte");
proto_tree_add_item(message_tree, hf_alljoyn_connect_byte_value, tvb, offset, 1, ENC_NA);
offset += 1;
}
return offset;
}
static const sasl_cmd *
find_sasl_command(tvbuff_t *tvb,
gint offset)
{
gint command_index;
for(command_index = 0; command_index < sasl_commands_count; command_index++) {
const sasl_cmd *cmd;
cmd = &sasl_commands[command_index];
if(0 == tvb_strneql(tvb, offset, cmd->text, cmd->length)) {
return cmd;
}
}
return NULL;
}
static gboolean set_pinfo_desegment(packet_info *pinfo, gint next_offset, gint addition_bytes_needed)
{
if(pinfo->can_desegment) {
pinfo->desegment_offset = next_offset;
pinfo->desegment_len = addition_bytes_needed;
return TRUE;
}
return FALSE;
}
static gint
handle_message_sasl(tvbuff_t *tvb,
packet_info *pinfo,
gint offset,
proto_tree *message_tree)
{
gint return_value = offset;
const sasl_cmd *command;
command = find_sasl_command(tvb, offset);
if(command) {
gint newline_offset = tvb_find_guint8(tvb, offset + command->length, -1, '\n') + 1;
if(0 == newline_offset) {
if((guint)tvb_captured_length_remaining(tvb, offset) < MAX_SASL_PACKET_LENGTH &&
set_pinfo_desegment(pinfo, offset, DESEGMENT_ONE_MORE_SEGMENT)) {
return_value = offset + command->length;
} else {
return_value = 0;
}
return return_value;
}
if(newline_offset > 0) {
gint length = command->length;
col_add_fstr(pinfo->cinfo, COL_INFO, "SASL-%s", command->text);
proto_tree_add_item(message_tree, hf_alljoyn_sasl_command, tvb, offset, length, ENC_ASCII|ENC_NA);
offset += length;
length = newline_offset - offset;
proto_tree_add_item(message_tree, hf_alljoyn_sasl_parameter, tvb, offset, length, ENC_ASCII|ENC_NA);
return_value = newline_offset;
}
}
return return_value;
}
static guint32
get_message_header_endianness(tvbuff_t *tvb,
gint offset)
{
guint8 endianness;
guint encoding;
endianness = tvb_get_guint8(tvb, offset + ENDIANNESS_OFFSET);
switch(endianness)
{
case 'l':
encoding = ENC_LITTLE_ENDIAN;
break;
case 'B':
encoding = ENC_BIG_ENDIAN;
break;
default:
encoding = ENC_ALLJOYN_BAD_ENCODING;
break;
}
return encoding;
}
static void
handle_message_header_expected_byte(tvbuff_t *tvb,
gint offset,
proto_tree *field_tree,
guint8 expected_value)
{
proto_item *item;
guint8 byte_value;
item = proto_tree_add_item(field_tree, hf_alljoyn_uint8, tvb, offset, 1, ENC_NA);
byte_value = tvb_get_guint8(tvb, offset);
if(expected_value == byte_value) {
proto_item_set_text(item, "0x%02x byte", expected_value);
} else {
proto_item_set_text(item, "Expected '0x%02x byte' but found '0x%02x'", expected_value, byte_value);
}
}
static gint
pad_according_to_type(gint offset, gint field_starting_offset, gint max_offset, guint8 type)
{
switch(type)
{
case ARG_BYTE:
break;
case ARG_DOUBLE:
case ARG_UINT64:
case ARG_INT64:
case ARG_STRUCT:
case ARG_DICT_ENTRY:
offset = round_to_8byte(offset, field_starting_offset);
break;
case ARG_SIGNATURE:
break;
case ARG_HANDLE:
break;
case ARG_INT32:
case ARG_UINT32:
case ARG_BOOLEAN:
offset = round_to_4byte(offset, field_starting_offset);
break;
case ARG_INT16:
case ARG_UINT16:
offset = round_to_2byte(offset, field_starting_offset);
break;
case ARG_STRING:
break;
case ARG_VARIANT:
break;
case ARG_OBJ_PATH:
break;
default:
break;
}
if(offset > max_offset) {
offset = max_offset;
}
return offset;
}
static void
append_struct_signature(proto_item *item,
const guint8 *signature,
gint signature_max_length,
const guint8 type_stop)
{
int depth = 0;
guint8 type_start;
gint signature_length = 0;
proto_item_append_text(item, "%c", ' ');
type_start = *signature;
do {
if(type_start == *signature) {
depth++;
}
if(type_stop == *signature) {
depth--;
}
proto_item_append_text(item, "%c", *signature++);
} while(depth > 0 && ++signature_length < signature_max_length);
if(signature_length >= signature_max_length) {
proto_item_append_text(item, "... Invalid signature!");
}
}
static void
advance_to_end_of_signature(const guint8 **signature,
guint8 *signature_length)
{
gboolean done = FALSE;
gint8 current_type;
gint8 end_type = ARG_INVALID;
while(*(++(*signature)) && --(*signature_length) > 0 && !done) {
current_type = **signature;
if(end_type != ARG_INVALID) {
if(end_type == current_type) {
done = TRUE;
}
continue;
}
switch(current_type)
{
case ARG_ARRAY:
advance_to_end_of_signature(signature, signature_length);
break;
case ARG_STRUCT:
end_type = ')';
advance_to_end_of_signature(signature, signature_length);
break;
case ARG_DICT_ENTRY:
end_type = '}';
advance_to_end_of_signature(signature, signature_length);
break;
case ARG_BYTE:
case ARG_DOUBLE:
case ARG_UINT64:
case ARG_INT64:
case ARG_SIGNATURE:
case ARG_HANDLE:
case ARG_INT32:
case ARG_UINT32:
case ARG_BOOLEAN:
case ARG_INT16:
case ARG_UINT16:
case ARG_STRING:
case ARG_VARIANT:
case ARG_OBJ_PATH:
done = TRUE;
break;
default:
done = TRUE;
break;
}
}
}
static void add_padding_item(gint padding_start, gint padding_end, tvbuff_t *tvb, proto_tree *tree)
{
if(padding_end > padding_start && padding_end < (gint)tvb_reported_length(tvb)) {
gint padding_length = padding_end - padding_start;
if (padding_length <= MAX_ROUND_TO_BYTES) {
proto_tree_add_item(tree, hf_padding, tvb, padding_start, padding_length, ENC_NA);
}
}
}
static gint
parse_arg(tvbuff_t *tvb,
packet_info *pinfo,
proto_item *header_item,
guint encoding,
gint offset,
proto_tree *field_tree,
gboolean is_reply_to,
guint8 type_id,
guint8 field_code,
const guint8 **signature,
guint8 *signature_length,
gint field_starting_offset)
{
gint length;
gint padding_start;
gint saved_offset = offset;
const gchar *header_type_name = NULL;
switch(type_id)
{
case ARG_INVALID:
header_type_name = "invalid";
offset = round_to_8byte(offset + 1, field_starting_offset);
break;
case ARG_ARRAY:
{
static gchar bad_array_format[] = "BAD DATA: Array length (in bytes) is %d. Remaining packet length is %d.";
proto_item *item;
proto_tree *tree;
const guint8 *sig_saved;
gint starting_offset;
gint number_of_items = 0;
guint8 remaining_sig_length = *signature_length;
gint packet_length = (gint)tvb_reported_length(tvb);
header_type_name = "array";
if(*signature == NULL || *signature_length < 1) {
col_add_fstr(pinfo->cinfo, COL_INFO, "BAD DATA: A %s argument needs a signature.", header_type_name);
return tvb_reported_length(tvb);
}
sig_saved = (*signature) + 1;
padding_start = offset;
offset = round_to_4byte(offset, field_starting_offset);
add_padding_item(padding_start, offset, tvb, field_tree);
length = (gint)get_uint32(tvb, offset, encoding);
padding_start = offset + 4;
starting_offset = pad_according_to_type(padding_start, field_starting_offset, packet_length, *sig_saved);
if(length < 0 || length > MAX_ARRAY_LEN || starting_offset + length > packet_length) {
col_add_fstr(pinfo->cinfo, COL_INFO, bad_array_format, length, tvb_reported_length_remaining(tvb, starting_offset));
return tvb_reported_length(tvb);
}
item = proto_tree_add_item(field_tree, hf_alljoyn_mess_body_array, tvb, offset, (starting_offset-offset) + length, encoding);
tree = proto_item_add_subtree(item, ett_alljoyn_mess_body_parameters);
offset = starting_offset;
add_padding_item(padding_start, offset, tvb, tree);
if(0 == length) {
advance_to_end_of_signature(signature, &remaining_sig_length);
} else {
while((offset - starting_offset) < length) {
const guint8 *sig_pointer;
number_of_items++;
sig_pointer = sig_saved;
remaining_sig_length = *signature_length - 1;
offset = parse_arg(tvb,
pinfo,
header_item,
encoding,
offset,
tree,
is_reply_to,
*sig_pointer,
field_code,
&sig_pointer,
&remaining_sig_length,
field_starting_offset);
*signature = sig_pointer;
}
}
*signature_length = remaining_sig_length;
if(item) {
proto_item_append_text(item, " of %d '%c' elements", number_of_items, *sig_saved);
}
}
break;
case ARG_BOOLEAN:
header_type_name = "boolean";
padding_start = offset;
offset = round_to_4byte(offset, field_starting_offset);
add_padding_item(padding_start, offset, tvb, field_tree);
proto_tree_add_item(field_tree, hf_alljoyn_boolean, tvb, offset, 4, encoding);
offset += 4;
break;
case ARG_DOUBLE:
header_type_name = "IEEE 754 double";
padding_start = offset;
offset = round_to_8byte(offset, field_starting_offset);
add_padding_item(padding_start, offset, tvb, field_tree);
proto_tree_add_item(field_tree, hf_alljoyn_double, tvb, offset, 8, encoding);
offset += 8;
break;
case ARG_SIGNATURE:
header_type_name = "signature";
*signature_length = tvb_get_guint8(tvb, offset);
if(*signature_length + 2 > tvb_reported_length_remaining(tvb, offset)) {
gint bytes_left = tvb_reported_length_remaining(tvb, offset);
col_add_fstr(pinfo->cinfo, COL_INFO, "BAD DATA: Signature length is %d. Only %d bytes left in packet.",
(gint)(*signature_length), bytes_left);
return tvb_reported_length(tvb);
}
length = *signature_length + 1;
proto_tree_add_item(field_tree, hf_alljoyn_mess_body_signature_length, tvb, offset, 1, encoding);
offset += 1;
proto_tree_add_item_ret_string(field_tree, hf_alljoyn_mess_body_signature, tvb, offset, length, ENC_ASCII|ENC_NA, wmem_packet_scope(), signature);
if(HDR_SIGNATURE == field_code) {
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)", *signature);
}
offset += length;
break;
case ARG_HANDLE:
header_type_name = "socket handle";
padding_start = offset;
offset = round_to_4byte(offset, field_starting_offset);
add_padding_item(padding_start, offset, tvb, field_tree);
proto_tree_add_item(field_tree, hf_alljoyn_handle, tvb, offset, 4, encoding);
offset += 4;
break;
case ARG_INT32:
header_type_name = "int32";
padding_start = offset;
offset = round_to_4byte(offset, field_starting_offset);
add_padding_item(padding_start, offset, tvb, field_tree);
proto_tree_add_item(field_tree, hf_alljoyn_int32, tvb, offset, 4, encoding);
offset += 4;
break;
case ARG_INT16:
header_type_name = "int16";
padding_start = offset;
offset = round_to_2byte(offset, field_starting_offset);
add_padding_item(padding_start, offset, tvb, field_tree);
proto_tree_add_item(field_tree, hf_alljoyn_int16, tvb, offset, 2, encoding);
offset += 2;
break;
case ARG_OBJ_PATH:
header_type_name = "object path";
length = get_uint32(tvb, offset, encoding) + 1;
if(length < 0 || length > MAX_ARRAY_LEN || length + 4 > tvb_reported_length_remaining(tvb, offset)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "BAD DATA: Object path length is %d. Only %d bytes left in packet.",
length, tvb_reported_length_remaining(tvb, offset + 4));
return tvb_reported_length(tvb);
}
proto_tree_add_item(field_tree, hf_alljoyn_uint32, tvb, offset, 4, encoding);
offset += 4;
proto_tree_add_item(field_tree, hf_alljoyn_string_data, tvb, offset, length, ENC_ASCII|ENC_NA);
offset += length;
break;
case ARG_UINT16:
header_type_name = "uint16";
padding_start = offset;
offset = round_to_2byte(offset, field_starting_offset);
add_padding_item(padding_start, offset, tvb, field_tree);
proto_tree_add_item(field_tree, hf_alljoyn_uint16, tvb, offset, 2, encoding);
offset += 2;
break;
case ARG_STRING:
{
const guint8 *member_name;
header_type_name = "string";
padding_start = offset;
offset = round_to_4byte(offset, field_starting_offset);
add_padding_item(padding_start, offset, tvb, field_tree);
proto_tree_add_item(field_tree, hf_alljoyn_string_size_32bit, tvb, offset, 4, encoding);
length = (gint)get_uint32(tvb, offset, encoding);
if(length < 0 || length > tvb_reported_length_remaining(tvb, offset)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "BAD DATA: String length is %d. Remaining packet length is %d.",
length, (gint)tvb_reported_length_remaining(tvb, offset));
return tvb_reported_length(tvb);
}
length += 1;
offset += 4;
proto_tree_add_item_ret_string(field_tree, hf_alljoyn_string_data, tvb, offset, length, ENC_UTF_8|ENC_NA, wmem_packet_scope(), &member_name);
if(HDR_MEMBER == field_code) {
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", member_name);
}
offset += length;
}
break;
case ARG_UINT64:
header_type_name = "uint64";
padding_start = offset;
offset = round_to_8byte(offset, field_starting_offset);
add_padding_item(padding_start, offset, tvb, field_tree);
proto_tree_add_item(field_tree, hf_alljoyn_uint64, tvb, offset, 8, encoding);
offset += 8;
break;
case ARG_UINT32:
header_type_name = "uint32";
padding_start = offset;
offset = round_to_4byte(offset, field_starting_offset);
add_padding_item(padding_start, offset, tvb, field_tree);
if(is_reply_to) {
static const gchar format[] = " Replies to: %09u";
guint32 replies_to;
replies_to = get_uint32(tvb, offset, encoding);
col_append_fstr(pinfo->cinfo, COL_INFO, format, replies_to);
if(header_item) {
proto_item *item;
item = proto_tree_add_item(field_tree, hf_alljoyn_uint32, tvb, offset, 4, encoding);
proto_item_set_text(item, format + 1, replies_to);
}
} else {
proto_tree_add_item(field_tree, hf_alljoyn_uint32, tvb, offset, 4, encoding);
}
offset += 4;
break;
case ARG_VARIANT:
{
proto_item *item;
proto_tree *tree;
const guint8 *sig_saved;
const guint8 *sig_pointer;
guint8 variant_sig_length;
header_type_name = "variant";
variant_sig_length = tvb_get_guint8(tvb, offset);
length = variant_sig_length;
if(length > tvb_reported_length_remaining(tvb, offset)) {
gint bytes_left = tvb_reported_length_remaining(tvb, offset);
col_add_fstr(pinfo->cinfo, COL_INFO, "BAD DATA: Variant signature length is %d. Only %d bytes left in packet.",
length, bytes_left);
offset = tvb_reported_length(tvb);
}
length += 1;
item = proto_tree_add_item(field_tree, hf_alljoyn_mess_body_variant, tvb, offset, 4, encoding);
tree = proto_item_add_subtree(item, ett_alljoyn_mess_body_parameters);
proto_tree_add_item(tree, hf_alljoyn_mess_body_signature_length, tvb, offset, 1, encoding);
offset += 1;
tree = proto_item_add_subtree(item, ett_alljoyn_mess_body_parameters);
proto_tree_add_item_ret_string(tree, hf_alljoyn_mess_body_signature, tvb, offset, length, ENC_ASCII|ENC_NA, wmem_packet_scope(), &sig_saved);
offset += length;
sig_pointer = sig_saved;
while(((sig_pointer - sig_saved) < (length - 1)) && (tvb_reported_length_remaining(tvb, offset) > 0)) {
proto_item_append_text(item, "%c", *sig_pointer);
offset = parse_arg(tvb, pinfo, header_item, encoding, offset, tree, is_reply_to,
*sig_pointer, field_code, &sig_pointer, &variant_sig_length, field_starting_offset);
}
proto_item_append_text(item, "'");
proto_item_set_end(item, tvb, offset);
}
break;
case ARG_INT64:
header_type_name = "int64";
padding_start = offset;
offset = round_to_8byte(offset, field_starting_offset);
add_padding_item(padding_start, offset, tvb, field_tree);
proto_tree_add_item(field_tree, hf_alljoyn_int64, tvb, offset, 8, encoding);
offset += 8;
break;
case ARG_BYTE:
header_type_name = "byte";
proto_tree_add_item(field_tree, hf_alljoyn_uint8, tvb, offset, 1, encoding);
offset += 1;
break;
case ARG_DICT_ENTRY:
case ARG_STRUCT:
{
proto_item *item;
proto_tree *tree;
int hf;
guint8 type_stop;
if(type_id == ARG_STRUCT) {
header_type_name = "structure";
hf = hf_alljoyn_mess_body_structure;
type_stop = ')';
} else {
header_type_name = "dictionary";
hf = hf_alljoyn_mess_body_dictionary_entry;
type_stop = '}';
}
if(*signature == NULL || *signature_length < 1) {
col_add_fstr(pinfo->cinfo, COL_INFO, "BAD DATA: A %s argument needs a signature.", header_type_name);
return tvb_reported_length(tvb);
}
item = proto_tree_add_item(field_tree, hf, tvb, offset, 4, encoding);
append_struct_signature(item, *signature, *signature_length, type_stop);
tree = proto_item_add_subtree(item, ett_alljoyn_mess_body_parameters);
padding_start = offset;
offset = pad_according_to_type(offset, field_starting_offset, tvb_reported_length(tvb), type_id);
add_padding_item(padding_start, offset, tvb, tree);
(*signature)++;
(*signature_length)--;
while(*signature && **signature && **signature != type_stop
&& tvb_reported_length_remaining(tvb, offset) > 0) {
offset = parse_arg(tvb,
pinfo,
header_item,
encoding,
offset,
tree,
is_reply_to,
**signature,
field_code,
signature,
signature_length,
field_starting_offset);
}
proto_item_set_end(item, tvb, offset);
}
break;
default:
header_type_name = "unexpected";
offset = tvb_reported_length(tvb);
break;
}
if(*signature && ARG_ARRAY != type_id && HDR_INVALID == field_code) {
(*signature)++;
(*signature_length)--;
}
if(NULL != header_item && NULL != header_type_name) {
proto_item_append_text(header_item, "%s", header_type_name);
}
if(offset > (gint)tvb_reported_length(tvb)) {
offset = (gint)tvb_reported_length(tvb);
} else if (offset == saved_offset) {
proto_tree_add_expert(field_tree, pinfo, &ei_alljoyn_empty_arg, tvb, offset, 0);
offset = (gint)tvb_reported_length(tvb);
}
return offset;
}
static void
alljoyn_typeid( gchar *result, guint32 type )
{
g_snprintf( result, ITEM_LABEL_LENGTH, "'%c' => ", type);
}
static gint
handle_message_field(tvbuff_t *tvb,
packet_info *pinfo,
proto_item *header_tree,
guint encoding,
gint offset,
const guint8 **signature,
guint8 *signature_length)
{
proto_tree *field_tree;
proto_item *item, *field_item;
guint8 field_code;
guint8 type_id;
gboolean is_reply_to = FALSE;
gint starting_offset = offset;
gint padding_start;
field_code = tvb_get_guint8(tvb, offset);
if(HDR_REPLY_SERIAL == field_code) {
is_reply_to = TRUE;
}
field_item = proto_tree_add_item(header_tree, hf_alljoyn_mess_header_field, tvb, offset, 1, ENC_NA);
field_tree = proto_item_add_subtree(field_item, ett_alljoyn_mess_header_field);
proto_tree_add_item(field_tree, hf_alljoyn_mess_body_header_fieldcode, tvb, offset, 1, ENC_NA);
offset += 1;
handle_message_header_expected_byte(tvb, offset, field_tree, 0x01);
offset += 1;
item = proto_tree_add_item(field_tree, hf_alljoyn_mess_body_header_typeid, tvb, offset, 1, ENC_NA);
type_id = tvb_get_guint8(tvb, offset);
offset += 1;
handle_message_header_expected_byte(tvb, offset, field_tree, 0x00);
offset += 1;
offset = parse_arg(tvb,
pinfo,
item,
encoding,
offset,
field_tree,
is_reply_to,
type_id,
field_code,
signature,
signature_length,
starting_offset);
padding_start = offset;
offset = round_to_8byte(offset, starting_offset);
add_padding_item(padding_start, offset, tvb, field_tree);
if(offset < 0 || offset > (gint)tvb_reported_length(tvb)) {
offset = (gint)tvb_reported_length(tvb);
}
proto_item_set_end(field_tree, tvb, offset);
return offset;
}
static const guint8 *
handle_message_header_fields(tvbuff_t *tvb,
packet_info *pinfo,
proto_item *header_tree,
guint encoding,
gint offset,
guint32 header_length,
guint8 *signature_length)
{
gint end_of_header;
proto_item *item;
proto_tree *tree;
const guint8 *signature = NULL;
item = proto_tree_add_item(header_tree, hf_alljoyn_mess_header_fields, tvb, offset, header_length, ENC_NA);
tree = proto_item_add_subtree(item, ett_alljoyn_mess_header);
end_of_header = offset + header_length;
while(offset < end_of_header) {
offset = handle_message_field(tvb, pinfo, tree, encoding, offset, &signature, signature_length);
}
return signature;
}
static gint
handle_message_body_parameters(tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *header_tree,
guint encoding,
gint offset,
gint32 body_length,
const guint8 *signature,
guint8 signature_length)
{
gint packet_length, end_of_body;
proto_tree *tree;
proto_item *item;
const gint starting_offset = offset;
packet_length = tvb_reported_length(tvb);
item = proto_tree_add_item(header_tree, hf_alljoyn_mess_body_parameters, tvb, offset, body_length, ENC_NA);
tree = proto_item_add_subtree(item, ett_alljoyn_mess_body_parameters);
end_of_body = offset + body_length;
if(end_of_body > packet_length) {
end_of_body = packet_length;
}
while(offset < end_of_body && signature && *signature) {
offset = parse_arg(tvb,
pinfo,
NULL,
encoding,
offset,
tree,
FALSE,
*signature,
HDR_INVALID,
&signature,
&signature_length,
starting_offset);
}
return offset;
}
static gint
handle_message_header_body(tvbuff_t *tvb,
packet_info *pinfo,
gint offset,
proto_item *message_tree,
gboolean is_ardp)
{
gint remaining_packet_length;
const guint8 *signature;
guint8 signature_length = 0;
proto_tree *header_tree, *flag_tree;
proto_item *header_item, *flag_item;
guint encoding;
gint packet_length_needed;
gint header_length = 0, body_length = 0;
remaining_packet_length = tvb_reported_length_remaining(tvb, offset);
encoding = get_message_header_endianness(tvb, offset);
if(ENC_ALLJOYN_BAD_ENCODING == encoding) {
col_add_fstr(pinfo->cinfo, COL_INFO, "BAD DATA: Endian encoding '0x%0x'. Expected 'l' or 'B'",
tvb_get_guint8(tvb, offset + ENDIANNESS_OFFSET));
return offset + remaining_packet_length;
}
if(remaining_packet_length < MESSAGE_HEADER_LENGTH) {
if(!set_pinfo_desegment(pinfo, offset, MESSAGE_HEADER_LENGTH - remaining_packet_length)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "BAD DATA: Remaining packet length is %d. Expected >= %d && <= %d",
remaining_packet_length, MESSAGE_HEADER_LENGTH, MAX_PACKET_LEN);
}
return offset + remaining_packet_length;
}
header_length = get_uint32(tvb, offset + HEADER_LENGTH_OFFSET, encoding);
body_length = get_uint32(tvb, offset + BODY_LENGTH_OFFSET, encoding);
packet_length_needed = ROUND_TO_8BYTE(header_length) + body_length + MESSAGE_HEADER_LENGTH;
if(packet_length_needed > remaining_packet_length) {
if(!set_pinfo_desegment(pinfo, offset, packet_length_needed - remaining_packet_length)) {
if(!is_ardp) {
col_add_fstr(pinfo->cinfo, COL_INFO, "BAD DATA: Remaining packet length is %d. Expected %d",
remaining_packet_length, packet_length_needed);
return offset + remaining_packet_length;
}
if (remaining_packet_length < header_length) {
col_add_fstr(pinfo->cinfo, COL_INFO, "Fragmented ARDP message: Remaining packet length is %d. Expected %d",
remaining_packet_length, packet_length_needed);
return offset + remaining_packet_length;
}
}
else {
return offset + remaining_packet_length;
}
}
header_item = proto_tree_add_item(message_tree, hf_alljoyn_mess_header, tvb, offset, MESSAGE_HEADER_LENGTH, ENC_NA);
header_tree = proto_item_add_subtree(header_item, ett_alljoyn_header);
proto_tree_add_item(header_tree, hf_alljoyn_mess_header_endian, tvb, offset + ENDIANNESS_OFFSET, 1, ENC_NA);
proto_tree_add_item(header_tree, hf_alljoyn_mess_header_type, tvb, offset + TYPE_OFFSET, 1, ENC_NA);
flag_item = proto_tree_add_item(header_tree, hf_alljoyn_mess_header_flags, tvb, offset + FLAGS_OFFSET, 1, ENC_NA);
flag_tree = proto_item_add_subtree(flag_item, ett_alljoyn_header_flags);
proto_tree_add_item(flag_tree, hf_alljoyn_mess_header_flags_encrypted, tvb, offset + FLAGS_OFFSET, 1, ENC_NA);
proto_tree_add_item(flag_tree, hf_alljoyn_mess_header_flags_compressed, tvb, offset + FLAGS_OFFSET, 1, ENC_NA);
proto_tree_add_item(flag_tree, hf_alljoyn_mess_header_flags_global_broadcast, tvb, offset + FLAGS_OFFSET, 1, ENC_NA);
proto_tree_add_item(flag_tree, hf_alljoyn_mess_header_flags_sessionless, tvb, offset + FLAGS_OFFSET, 1, ENC_NA);
proto_tree_add_item(flag_tree, hf_alljoyn_mess_header_flags_allow_remote_msg, tvb, offset + FLAGS_OFFSET, 1, ENC_NA);
proto_tree_add_item(flag_tree, hf_alljoyn_mess_header_flags_no_auto_start, tvb, offset + FLAGS_OFFSET, 1, ENC_NA);
proto_tree_add_item(flag_tree, hf_alljoyn_mess_header_flags_no_reply, tvb, offset + FLAGS_OFFSET, 1, ENC_NA);
proto_tree_add_item(header_tree, hf_alljoyn_mess_header_majorversion, tvb, offset + MAJORVERSION_OFFSET, 1, ENC_NA);
proto_tree_add_item(header_tree, hf_alljoyn_mess_header_body_length, tvb, offset + BODY_LENGTH_OFFSET, 4, encoding);
proto_tree_add_item(header_tree, hf_alljoyn_mess_header_serial, tvb, offset + SERIAL_OFFSET, 4, encoding);
col_add_fstr(pinfo->cinfo, COL_INFO, "Message %010u: '%s'", get_uint32(tvb, offset + SERIAL_OFFSET, encoding),
val_to_str_const(tvb_get_guint8(tvb, offset + TYPE_OFFSET), message_header_encoding_vals, "Unexpected message type"));
proto_tree_add_item(header_tree, hf_alljoyn_mess_header_header_length, tvb, offset + HEADER_LENGTH_OFFSET, 4, encoding);
offset += MESSAGE_HEADER_LENGTH;
packet_length_needed -= MESSAGE_HEADER_LENGTH;
signature = handle_message_header_fields(tvb, pinfo, message_tree, encoding,
offset, header_length, &signature_length);
offset += ROUND_TO_8BYTE(header_length);
packet_length_needed -= ROUND_TO_8BYTE(header_length);
remaining_packet_length = tvb_reported_length_remaining(tvb, offset);
if (packet_length_needed > remaining_packet_length) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "Fragmented ARDP message or bad data: Remaining packet length is %d. Expected %d",
remaining_packet_length, packet_length_needed);
return offset + remaining_packet_length;
}
if(body_length > 0 && signature != NULL && signature_length > 0) {
offset = handle_message_body_parameters(tvb,
pinfo,
message_tree,
encoding,
offset,
body_length,
signature,
signature_length);
}
return offset;
}
static gboolean
protocol_is_alljoyn_message(tvbuff_t *tvb, gint offset, gboolean is_ardp)
{
gint length = tvb_captured_length(tvb);
if(length < offset + 1)
return FALSE;
if(!is_ardp) {
if(tvb_get_guint8(tvb, offset) == 0)
return TRUE;
if(find_sasl_command(tvb, offset) != NULL)
return TRUE;
}
if(get_message_header_endianness(tvb, offset) == ENC_ALLJOYN_BAD_ENCODING)
return FALSE;
if((length < offset + 2) || (try_val_to_str(tvb_get_guint8(tvb, offset + 1), message_header_encoding_vals) == NULL))
return FALSE;
return TRUE;
}
static gint
dissect_AllJoyn_message(tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
gint offset)
{
proto_item *message_item;
proto_tree *message_tree;
gint last_offset = -1;
gint packet_length;
gboolean is_ardp = FALSE;
if(offset != 0) {
is_ardp = TRUE;
}
pinfo->desegment_len = 0;
packet_length = tvb_reported_length(tvb);
col_clear(pinfo->cinfo, COL_INFO);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ALLJOYN");
message_item = proto_tree_add_item(tree, proto_AllJoyn_mess, tvb, offset, -1, ENC_NA);
message_tree = proto_item_add_subtree(message_item, ett_alljoyn_mess);
while(offset < packet_length && offset > last_offset) {
last_offset = offset;
if(!is_ardp) {
offset = handle_message_connect(tvb, pinfo, offset, message_tree);
if(offset >= packet_length) {
break;
}
offset = handle_message_sasl(tvb, pinfo, offset, message_tree);
if(offset >= packet_length) {
break;
}
}
offset = handle_message_header_body(tvb, pinfo, offset, message_tree, is_ardp);
}
return offset;
}
static void
ns_parse_questions(tvbuff_t *tvb, gint* offset, proto_tree* alljoyn_tree, guint8 questions, guint message_version)
{
while(questions--) {
proto_item *alljoyn_questions_ti;
proto_tree *alljoyn_questions_tree;
gint count;
alljoyn_questions_ti = proto_tree_add_item(alljoyn_tree, hf_alljoyn_ns_whohas, tvb, *offset, 2, ENC_NA);
alljoyn_questions_tree = proto_item_add_subtree(alljoyn_questions_ti, ett_alljoyn_whohas);
if(0 == message_version) {
proto_tree_add_item(alljoyn_questions_tree, hf_alljoyn_ns_whohas_t_flag, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(alljoyn_questions_tree, hf_alljoyn_ns_whohas_u_flag, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(alljoyn_questions_tree, hf_alljoyn_ns_whohas_s_flag, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(alljoyn_questions_tree, hf_alljoyn_ns_whohas_f_flag, tvb, *offset, 1, ENC_NA);
}
(*offset) += 1;
proto_tree_add_item(alljoyn_questions_tree, hf_alljoyn_ns_whohas_count, tvb, *offset, 1, ENC_NA);
count = tvb_get_guint8(tvb, *offset);
(*offset) += 1;
while(count--) {
proto_item *alljoyn_bus_name_ti;
proto_tree *alljoyn_bus_name_tree;
gint bus_name_size = 0;
bus_name_size = tvb_get_guint8(tvb, *offset);
alljoyn_bus_name_ti = proto_tree_add_item(alljoyn_questions_tree, hf_alljoyn_string, tvb,
*offset, 1 + bus_name_size, ENC_NA);
alljoyn_bus_name_tree = proto_item_add_subtree(alljoyn_bus_name_ti, ett_alljoyn_ns_string);
proto_tree_add_item(alljoyn_bus_name_tree, hf_alljoyn_string_size_8bit, tvb, *offset, 1, ENC_NA);
(*offset) += 1;
proto_tree_add_item(alljoyn_bus_name_tree, hf_alljoyn_string_data, tvb, *offset, bus_name_size, ENC_ASCII|ENC_NA);
(*offset) += bus_name_size;
}
}
}
static void
ns_parse_answers_v0(tvbuff_t *tvb, gint* offset, proto_tree* alljoyn_tree, guint8 answers)
{
while(answers--) {
proto_item *alljoyn_answers_ti;
proto_tree *alljoyn_answers_tree;
gint flags;
gint count;
alljoyn_answers_ti = proto_tree_add_item(alljoyn_tree, hf_alljoyn_answer, tvb, *offset, 2, ENC_NA);
alljoyn_answers_tree = proto_item_add_subtree(alljoyn_answers_ti, ett_alljoyn_ns_answers);
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_g_flag, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_c_flag, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_t_flag, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_u_flag, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_s_flag, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_f_flag, tvb, *offset, 1, ENC_NA);
flags = tvb_get_guint8(tvb, *offset);
(*offset) += 1;
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_count, tvb, *offset, 1, ENC_NA);
count = tvb_get_guint8(tvb, *offset);
(*offset) += 1;
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_port, tvb, *offset, 2, ENC_BIG_ENDIAN);
(*offset) += 2;
if(flags & ISAT_S) {
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_ipv6, tvb, *offset, 16, ENC_NA);
(*offset) += 16;
}
if(flags & ISAT_F) {
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_ipv4, tvb, *offset, 4, ENC_BIG_ENDIAN);
(*offset) += 4;
}
if(flags & ISAT_G) {
proto_item *alljoyn_string_ti;
proto_tree *alljoyn_string_tree;
gint guid_size = 0;
guid_size = tvb_get_guint8(tvb, *offset);
alljoyn_string_ti = proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_isat_guid_string, tvb,
*offset, 1 + guid_size, ENC_NA);
alljoyn_string_tree = proto_item_add_subtree(alljoyn_string_ti, ett_alljoyn_ns_guid_string);
proto_tree_add_item(alljoyn_string_tree, hf_alljoyn_string_size_8bit, tvb, *offset, 1, ENC_NA);
(*offset) += 1;
proto_tree_add_item(alljoyn_string_tree, hf_alljoyn_string_data, tvb, *offset, guid_size, ENC_ASCII|ENC_NA);
(*offset) += guid_size;
}
while(count--) {
proto_item *alljoyn_entry_ti;
proto_tree *alljoyn_entry_tree;
proto_item *alljoyn_bus_name_ti;
proto_tree *alljoyn_bus_name_tree;
gint bus_name_size = tvb_get_guint8(tvb, *offset);
alljoyn_entry_ti = proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_isat_entry, tvb,
*offset, 1 + bus_name_size, ENC_NA);
alljoyn_entry_tree = proto_item_add_subtree(alljoyn_entry_ti, ett_alljoyn_ns_isat_entry);
alljoyn_bus_name_ti = proto_tree_add_item(alljoyn_entry_tree, hf_alljoyn_string, tvb, *offset,
1 + bus_name_size, ENC_NA);
alljoyn_bus_name_tree = proto_item_add_subtree(alljoyn_bus_name_ti, ett_alljoyn_string);
proto_tree_add_item(alljoyn_bus_name_tree, hf_alljoyn_string_size_8bit, tvb, *offset, 1, ENC_NA);
(*offset) += 1;
proto_tree_add_item(alljoyn_bus_name_tree, hf_alljoyn_string_data, tvb, *offset, bus_name_size, ENC_ASCII|ENC_NA);
(*offset) += bus_name_size;
}
}
}
static void
ns_parse_answers_v1(tvbuff_t *tvb, gint* offset, proto_tree* alljoyn_tree, guint8 answers)
{
while(answers--) {
proto_item *alljoyn_answers_ti;
proto_tree *alljoyn_answers_tree;
gint flags;
gint count;
alljoyn_answers_ti = proto_tree_add_item(alljoyn_tree, hf_alljoyn_answer, tvb, *offset, 2, ENC_NA);
alljoyn_answers_tree = proto_item_add_subtree(alljoyn_answers_ti, ett_alljoyn_ns_answers);
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_g_flag, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_c_flag, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_r4_flag, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_u4_flag, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_r6_flag, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_u6_flag, tvb, *offset, 1, ENC_NA);
flags = tvb_get_guint8(tvb, *offset);
(*offset) += 1;
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_count, tvb, *offset, 1, ENC_NA);
count = tvb_get_guint8(tvb, *offset);
(*offset) += 1;
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_transport_mask, tvb, *offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_transport_mask_wfd, tvb, *offset, 2, ENC_NA);
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_transport_mask_ice, tvb, *offset, 2, ENC_NA);
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_transport_mask_lan, tvb, *offset, 2, ENC_NA);
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_transport_mask_wwan, tvb, *offset, 2, ENC_NA);
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_transport_mask_tcp, tvb, *offset, 2, ENC_NA);
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_transport_mask_bluetooth, tvb, *offset, 2, ENC_NA);
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_transport_mask_local, tvb, *offset, 2, ENC_NA);
(*offset) += 2;
if(flags & ISAT_R4) {
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_ipv4, tvb, *offset, 4, ENC_BIG_ENDIAN);
(*offset) += 4;
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_port, tvb, *offset, 2, ENC_BIG_ENDIAN);
(*offset) += 2;
}
if(flags & ISAT_U4) {
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_ipv4, tvb, *offset, 4, ENC_BIG_ENDIAN);
(*offset) += 4;
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_port, tvb, *offset, 2, ENC_BIG_ENDIAN);
(*offset) += 2;
}
if(flags & ISAT_R6) {
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_ipv6, tvb, *offset, 16, ENC_NA);
(*offset) += 16;
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_port, tvb, *offset, 2, ENC_BIG_ENDIAN);
(*offset) += 2;
}
if(flags & ISAT_U6) {
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_ipv6, tvb, *offset, 16, ENC_NA);
(*offset) += 16;
proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_ns_isat_port, tvb, *offset, 2, ENC_BIG_ENDIAN);
(*offset) += 2;
}
if(flags & ISAT_G) {
proto_item *alljoyn_string_ti;
proto_tree *alljoyn_string_tree;
gint guid_size;
guid_size = tvb_get_guint8(tvb, *offset);
alljoyn_string_ti = proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_isat_guid_string, tvb,
*offset, 1 + guid_size, ENC_NA);
alljoyn_string_tree = proto_item_add_subtree(alljoyn_string_ti, ett_alljoyn_ns_guid_string);
proto_tree_add_item(alljoyn_string_tree, hf_alljoyn_string_size_8bit, tvb, *offset, 1, ENC_NA);
(*offset) += 1;
proto_tree_add_item(alljoyn_string_tree, hf_alljoyn_string_data, tvb, *offset, guid_size, ENC_ASCII|ENC_NA);
(*offset) += guid_size;
}
while(count--) {
proto_item *alljoyn_entry_ti;
proto_tree *alljoyn_entry_tree;
proto_tree *alljoyn_bus_name_ti;
proto_tree *alljoyn_bus_name_tree;
gint bus_name_size = tvb_get_guint8(tvb, *offset);
alljoyn_entry_ti = proto_tree_add_item(alljoyn_answers_tree, hf_alljoyn_isat_entry, tvb,
*offset, 1 + bus_name_size, ENC_NA);
alljoyn_entry_tree = proto_item_add_subtree(alljoyn_entry_ti, ett_alljoyn_isat_entry);
alljoyn_bus_name_ti = proto_tree_add_item(alljoyn_entry_tree, hf_alljoyn_string, tvb, *offset,
1 + bus_name_size, ENC_NA);
alljoyn_bus_name_tree = proto_item_add_subtree(alljoyn_bus_name_ti, ett_alljoyn_string);
proto_tree_add_item(alljoyn_bus_name_tree, hf_alljoyn_string_size_8bit, tvb, *offset, 1, ENC_NA);
(*offset) += 1;
proto_tree_add_item(alljoyn_bus_name_tree, hf_alljoyn_string_data, tvb, *offset, bus_name_size, ENC_ASCII|ENC_NA);
(*offset) += bus_name_size;
}
}
}
static int
dissect_AllJoyn_name_server(tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
void *data _U_)
{
proto_item *alljoyn_item, *header_item;
proto_tree *alljoyn_tree, *header_tree;
guint8 questions, answers;
guint8 version;
int offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ALLJOYN-NS");
col_clear(pinfo->cinfo, COL_INFO);
alljoyn_item = proto_tree_add_item(tree, proto_AllJoyn_ns, tvb, 0, -1, ENC_NA);
alljoyn_tree = proto_item_add_subtree(alljoyn_item, ett_alljoyn_ns);
header_item = proto_tree_add_item(alljoyn_tree, hf_alljoyn_ns_header, tvb, offset, 4, ENC_NA);
header_tree = proto_item_add_subtree(header_item, ett_alljoyn_ns_header);
proto_tree_add_item(header_tree, hf_alljoyn_ns_sender_version, tvb, offset, 1, ENC_NA);
proto_tree_add_item(header_tree, hf_alljoyn_ns_message_version, tvb, offset, 1, ENC_NA);
version = tvb_get_guint8(tvb, offset) & 0xF;
offset += 1;
col_add_fstr(pinfo->cinfo, COL_INFO, "VERSION %u", version);
if(version > 1)
col_append_str(pinfo->cinfo, COL_INFO, " (UNSUPPORTED)");
proto_tree_add_item(header_tree, hf_alljoyn_ns_questions, tvb, offset, 1, ENC_NA);
questions = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(header_tree, hf_alljoyn_ns_answers, tvb, offset, 1, ENC_NA);
answers = tvb_get_guint8(tvb, offset);
offset += 1;
if(answers > 0)
col_append_str(pinfo->cinfo, COL_INFO, " ISAT");
if(questions > 0)
col_append_str(pinfo->cinfo, COL_INFO, " WHOHAS");
proto_tree_add_item(header_tree, hf_alljoyn_ns_timer, tvb, offset, 1, ENC_NA);
offset += 1;
if(tree) {
ns_parse_questions(tvb, &offset, alljoyn_tree, questions, version);
switch(version) {
case 0:
ns_parse_answers_v0(tvb, &offset, alljoyn_tree, answers);
break;
case 1:
ns_parse_answers_v1(tvb, &offset, alljoyn_tree, answers);
break;
default:
break;
}
}
return tvb_reported_length(tvb);
}
static void
ardp_parse_header(tvbuff_t *tvb,
packet_info *pinfo,
alljoyn_ardp_tree_data *tree_data)
{
guint8 flags, header_length;
gint eaklen, packet_length;
guint16 data_length;
packet_length = tvb_reported_length(tvb);
flags = tvb_get_guint8(tvb, 0);
tree_data->syn = (flags & ARDP_SYN) != 0;
tree_data->ack = (flags & ARDP_ACK) != 0;
tree_data->eak = (flags & ARDP_EAK) != 0;
tree_data->rst = (flags & ARDP_RST) != 0;
tree_data->nul = (flags & ARDP_NUL) != 0;
header_length = 2 * tvb_get_guint8(tvb, ARDP_HEADER_LEN_OFFSET);
if(packet_length < ARDP_DATA_LENGTH_OFFSET + 2) {
set_pinfo_desegment(pinfo, 0, ARDP_DATA_LENGTH_OFFSET + 2 - packet_length);
tree_data->offset = ARDP_HEADER_LEN_OFFSET + 1;
return;
}
data_length = tvb_get_ntohs(tvb, ARDP_DATA_LENGTH_OFFSET);
if(packet_length < header_length + data_length) {
set_pinfo_desegment(pinfo, 0, header_length + data_length - packet_length);
tree_data->offset = ARDP_DATA_LENGTH_OFFSET + 2;
return;
}
proto_tree_add_item(tree_data->alljoyn_tree, hf_ardp_syn_flag, tvb, tree_data->offset, 1, ENC_NA);
proto_tree_add_item(tree_data->alljoyn_tree, hf_ardp_ack_flag, tvb, tree_data->offset, 1, ENC_NA);
proto_tree_add_item(tree_data->alljoyn_tree, hf_ardp_eak_flag, tvb, tree_data->offset, 1, ENC_NA);
proto_tree_add_item(tree_data->alljoyn_tree, hf_ardp_rst_flag, tvb, tree_data->offset, 1, ENC_NA);
proto_tree_add_item(tree_data->alljoyn_tree, hf_ardp_nul_flag, tvb, tree_data->offset, 1, ENC_NA);
proto_tree_add_item(tree_data->alljoyn_tree, hf_ardp_unused_flag, tvb, tree_data->offset, 1, ENC_NA);
proto_tree_add_item(tree_data->alljoyn_tree, hf_ardp_version_field, tvb, tree_data->offset, 1, ENC_NA);
tree_data->offset += 1;
proto_tree_add_item(tree_data->alljoyn_tree, hf_ardp_hlen, tvb, tree_data->offset, 1, ENC_NA);
tree_data->offset += 1;
proto_tree_add_item(tree_data->alljoyn_tree, hf_ardp_src, tvb, tree_data->offset, 2, ENC_BIG_ENDIAN);
tree_data->offset += 2;
proto_tree_add_item(tree_data->alljoyn_tree, hf_ardp_dst, tvb, tree_data->offset, 2, ENC_BIG_ENDIAN);
tree_data->offset += 2;
proto_tree_add_item(tree_data->alljoyn_tree, hf_ardp_dlen, tvb, tree_data->offset, 2, ENC_BIG_ENDIAN);
tree_data->offset += 2;
proto_tree_add_item(tree_data->alljoyn_tree, hf_ardp_seq, tvb, tree_data->offset, 4, ENC_BIG_ENDIAN);
tree_data->sequence = tvb_get_ntohl(tvb, tree_data->offset);
tree_data->offset += 4;
proto_tree_add_item(tree_data->alljoyn_tree, hf_ardp_ack, tvb, tree_data->offset, 4, ENC_BIG_ENDIAN);
tree_data->acknowledge = tvb_get_ntohl(tvb, tree_data->offset);
tree_data->offset += 4;
if(tree_data->syn) {
proto_tree_add_item(tree_data->alljoyn_tree, hf_ardp_segmax, tvb, tree_data->offset, 2, ENC_BIG_ENDIAN);
tree_data->offset += 2;
proto_tree_add_item(tree_data->alljoyn_tree, hf_ardp_segbmax, tvb, tree_data->offset, 2, ENC_BIG_ENDIAN);
tree_data->offset += 2;
proto_tree_add_item(tree_data->alljoyn_tree, hf_ardp_dackt, tvb, tree_data->offset, 4, ENC_BIG_ENDIAN);
tree_data->offset += 4;
proto_tree_add_item(tree_data->alljoyn_tree, hf_ardp_options, tvb, tree_data->offset, 2, ENC_BIG_ENDIAN);
tree_data->offset += 2;
} else {
proto_tree_add_item(tree_data->alljoyn_tree, hf_ardp_ttl, tvb, tree_data->offset, 4, ENC_BIG_ENDIAN);
tree_data->offset += 4;
proto_tree_add_item(tree_data->alljoyn_tree, hf_ardp_lcs, tvb, tree_data->offset, 4, ENC_BIG_ENDIAN);
tree_data->offset += 4;
proto_tree_add_item(tree_data->alljoyn_tree, hf_ardp_nsa, tvb, tree_data->offset, 4, ENC_BIG_ENDIAN);
tree_data->offset += 4;
proto_tree_add_item(tree_data->alljoyn_tree, hf_ardp_fss, tvb, tree_data->offset, 4, ENC_BIG_ENDIAN);
tree_data->start_sequence = tvb_get_ntohl(tvb, tree_data->offset);
tree_data->offset += 4;
proto_tree_add_item(tree_data->alljoyn_tree, hf_ardp_fcnt, tvb, tree_data->offset, 2, ENC_BIG_ENDIAN);
tree_data->fragment_count = tvb_get_ntohs(tvb, tree_data->offset);
tree_data->offset += 2;
eaklen = header_length - ARDP_FIXED_HDR_LEN;
if(eaklen > 0) {
if(tree_data->eak) {
proto_tree_add_item(tree_data->alljoyn_tree, hf_ardp_bmp, tvb, tree_data->offset, eaklen, ENC_NA);
}
tree_data->offset += eaklen;
}
}
}
static gboolean
protocol_is_ardp(tvbuff_t *tvb)
{
guint8 flags, header_length;
gint length = tvb_captured_length(tvb);
if(length < ARDP_HEADER_LEN_OFFSET + 1) {
return FALSE;
}
header_length = 2 * tvb_get_guint8(tvb, ARDP_HEADER_LEN_OFFSET);
flags = tvb_get_guint8(tvb, 0);
if((flags & ARDP_SYN) && header_length != ARDP_SYN_FIXED_HDR_LEN) {
return FALSE;
}
if(!(flags & ARDP_SYN) && header_length < ARDP_FIXED_HDR_LEN) {
return FALSE;
}
return TRUE;
}
static int
dissect_AllJoyn_ardp(tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
void *data _U_)
{
alljoyn_ardp_tree_data tree_data = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
gint packet_length = tvb_reported_length(tvb);
proto_item *alljoyn_item = NULL;
gboolean fragmentedPacket = FALSE;
if(protocol_is_alljoyn_message(tvb, 0, FALSE)) {
return dissect_AllJoyn_message(tvb, pinfo, tree, 0);
}
if(!protocol_is_ardp(tvb)) {
return 0;
}
pinfo->desegment_len = 0;
alljoyn_item = proto_tree_add_item(tree, proto_AllJoyn_ardp, tvb, 0, -1, ENC_NA);
tree_data.alljoyn_tree = proto_item_add_subtree(alljoyn_item, ett_alljoyn_ardp);
ardp_parse_header(tvb, pinfo, &tree_data);
if(pinfo->desegment_len != 0) {
return tree_data.offset;
}
if(tree_data.offset != 0) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ALLJOYN-ARDP");
}
if(tree_data.offset < packet_length) {
gint return_value = 0;
if(protocol_is_alljoyn_message(tvb, tree_data.offset, TRUE)) {
return_value = dissect_AllJoyn_message(tvb, pinfo, tree, tree_data.offset);
}
else {
fragmentedPacket = !tree_data.syn && (tree_data.sequence > tree_data.start_sequence);
}
if(return_value > tree_data.offset) {
return return_value;
}
}
col_clear(pinfo->cinfo, COL_INFO);
col_append_str(pinfo->cinfo, COL_INFO, "flags:");
if(tree_data.syn) {
col_append_str(pinfo->cinfo, COL_INFO, " SYN");
}
if(tree_data.ack) {
col_append_str(pinfo->cinfo, COL_INFO, " ACK");
}
if(tree_data.eak) {
col_append_str(pinfo->cinfo, COL_INFO, " EAK");
}
if(tree_data.rst) {
col_append_str(pinfo->cinfo, COL_INFO, " RST");
}
if(tree_data.nul) {
col_append_str(pinfo->cinfo, COL_INFO, " NUL");
}
col_append_fstr(pinfo->cinfo, COL_INFO, " SEQ: %10u", tree_data.sequence);
col_append_fstr(pinfo->cinfo, COL_INFO, " ACK: %10u", tree_data.acknowledge);
if(fragmentedPacket) {
guint fragment = (tree_data.sequence - tree_data.start_sequence) + 1;
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "Fragment %d of %d for a previous ALLJOYN message", fragment, tree_data.fragment_count);
}
return tree_data.offset;
}
void
proto_register_AllJoyn(void)
{
expert_module_t* expert_alljoyn;
static hf_register_info hf[] = {
{&hf_alljoyn_ns_header,
{"Header", "alljoyn.header",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_alljoyn_ns_sender_version,
{"Sender Version", "alljoyn.header.sendversion",
FT_UINT8, BASE_DEC, NULL, 0xF0,
NULL, HFILL}
},
{&hf_alljoyn_ns_message_version,
{"Message Version", "alljoyn.header.messageversion",
FT_UINT8, BASE_DEC, NULL, 0x0F,
NULL, HFILL}
},
{&hf_alljoyn_ns_questions,
{"Questions", "alljoyn.header.questions",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_alljoyn_ns_answers,
{"Answers", "alljoyn.header.answers",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_alljoyn_ns_timer,
{"Timer", "alljoyn.header.timer",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_alljoyn_ns_whohas,
{"Who-Has Message", "alljoyn.whohas",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_alljoyn_ns_whohas_t_flag,
{"TCP", "alljoyn.whohas.T",
FT_BOOLEAN, 8, NULL, WHOHAS_T,
NULL, HFILL}
},
{&hf_alljoyn_ns_whohas_u_flag,
{"UDP", "alljoyn.whohas.U",
FT_BOOLEAN, 8, NULL, WHOHAS_U,
NULL, HFILL}
},
{&hf_alljoyn_ns_whohas_s_flag,
{"IPv6", "alljoyn.whohas.S",
FT_BOOLEAN, 8, NULL, WHOHAS_S,
NULL, HFILL}
},
{&hf_alljoyn_ns_whohas_f_flag,
{"IPv4", "alljoyn.whohas.F",
FT_BOOLEAN, 8, NULL, WHOHAS_F,
NULL, HFILL}
},
{&hf_alljoyn_ns_whohas_count,
{"Count", "alljoyn.whohas.count",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_alljoyn_answer,
{"Is-At Message", "alljoyn.isat",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_alljoyn_isat_entry,
{"Advertisement Entry", "alljoyn.isat_entry",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_alljoyn_isat_guid_string,
{"GUID String", "alljoyn.isat_guid_string",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_alljoyn_ns_isat_g_flag,
{"GUID", "alljoyn.isat.G",
FT_BOOLEAN, 8, NULL, ISAT_G,
NULL, HFILL}
},
{&hf_alljoyn_ns_isat_c_flag,
{"Complete", "alljoyn.isat.C",
FT_BOOLEAN, 8, NULL, ISAT_C,
NULL, HFILL}
},
{&hf_alljoyn_ns_isat_count,
{"Count", "alljoyn.isat.count",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_alljoyn_ns_isat_ipv6,
{"IPv6 Address", "alljoyn.isat.ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_alljoyn_ns_isat_ipv4,
{"IPv4 Address", "alljoyn.isat.ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_alljoyn_ns_isat_t_flag,
{"TCP", "alljoyn.isat.T",
FT_BOOLEAN, 8, NULL, ISAT_T,
NULL, HFILL}
},
{&hf_alljoyn_ns_isat_u_flag,
{"UDP", "alljoyn.isat.U",
FT_BOOLEAN, 8, NULL, ISAT_U,
NULL, HFILL}
},
{&hf_alljoyn_ns_isat_s_flag,
{"IPv6", "alljoyn.isat.S",
FT_BOOLEAN, 8, NULL, ISAT_S,
NULL, HFILL}
},
{&hf_alljoyn_ns_isat_f_flag,
{"IPv4", "alljoyn.isat.F",
FT_BOOLEAN, 8, NULL, ISAT_F,
NULL, HFILL}
},
{&hf_alljoyn_ns_isat_port,
{"Port", "alljoyn.isat.port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_alljoyn_ns_isat_u6_flag,
{"IPv6 UDP", "alljoyn.isat.U6",
FT_BOOLEAN, 8, NULL, ISAT_U6,
NULL, HFILL}
},
{&hf_alljoyn_ns_isat_r6_flag,
{"IPv6 TCP", "alljoyn.isat.R6",
FT_BOOLEAN, 8, NULL, ISAT_R6,
NULL, HFILL}
},
{&hf_alljoyn_ns_isat_u4_flag,
{"IPv4 UDP", "alljoyn.isat.U4",
FT_BOOLEAN, 8, NULL, ISAT_U4,
NULL, HFILL}
},
{&hf_alljoyn_ns_isat_r4_flag,
{"IPv4 TCP", "alljoyn.isat.R4",
FT_BOOLEAN, 8, NULL, ISAT_R4,
NULL, HFILL}
},
{&hf_alljoyn_ns_isat_transport_mask,
{"Transport Mask", "alljoyn.isat.TransportMask",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{&hf_alljoyn_ns_isat_transport_mask_local,
{"Local Transport", "alljoyn.isat.TransportMask.Local",
FT_BOOLEAN, 16, NULL, TRANSPORT_LOCAL,
NULL, HFILL}
},
{&hf_alljoyn_ns_isat_transport_mask_bluetooth,
{"Bluetooth Transport", "alljoyn.isat.TransportMask.Bluetooth",
FT_BOOLEAN, 16, NULL, TRANSPORT_BLUETOOTH,
NULL, HFILL}
},
{&hf_alljoyn_ns_isat_transport_mask_tcp,
{"TCP Transport", "alljoyn.isat.TransportMask.TCP",
FT_BOOLEAN, 16, NULL, TRANSPORT_TCP,
NULL, HFILL}
},
{&hf_alljoyn_ns_isat_transport_mask_wwan,
{"Wirelesss WAN Transport", "alljoyn.isat.TransportMask.WWAN",
FT_BOOLEAN, 16, NULL, TRANSPORT_WWAN,
NULL, HFILL}
},
{&hf_alljoyn_ns_isat_transport_mask_lan,
{"Wired LAN Transport", "alljoyn.isat.TransportMask.LAN",
FT_BOOLEAN, 16, NULL, TRANSPORT_LAN,
NULL, HFILL}
},
{&hf_alljoyn_ns_isat_transport_mask_ice,
{"ICE protocol Transport", "alljoyn.isat.TransportMask.ICE",
FT_BOOLEAN, 16, NULL, TRANSPORT_ICE,
NULL, HFILL}
},
{&hf_alljoyn_ns_isat_transport_mask_wfd,
{"Wi-Fi Direct Transport", "alljoyn.isat.TransportMask.WFD",
FT_BOOLEAN, 16, NULL, TRANSPORT_WFD,
NULL, HFILL}
},
{&hf_alljoyn_connect_byte_value,
{"Connect Initial Byte", "alljoyn.InitialByte",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{&hf_alljoyn_sasl_command,
{"SASL command", "alljoyn.SASL.command",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_alljoyn_sasl_parameter,
{"SASL parameter", "alljoyn.SASL.parameter",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_alljoyn_mess_header,
{"Message Header", "alljoyn.mess_header",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_alljoyn_mess_header_endian,
{"Endianness", "alljoyn.mess_header.endianess",
FT_UINT8, BASE_DEC, VALS(endian_encoding_vals), 0x0,
NULL, HFILL}
},
{&hf_alljoyn_mess_header_type,
{"Message type", "alljoyn.mess_header.type",
FT_UINT8, BASE_DEC, VALS(message_header_encoding_vals), 0x0,
NULL, HFILL}
},
{&hf_alljoyn_mess_header_flags,
{"Flags", "alljoyn.mess_header.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{&hf_alljoyn_mess_header_flags_no_reply,
{"No reply expected", "alljoyn.mess_header.flags.noreply",
FT_BOOLEAN, 8, NULL, MESSAGE_HEADER_FLAG_NO_REPLY_EXPECTED,
NULL, HFILL}
},
{&hf_alljoyn_mess_header_flags_no_auto_start,
{"No auto start", "alljoyn.mess_header.flags.noautostart",
FT_BOOLEAN, 8, NULL, MESSAGE_HEADER_FLAG_NO_AUTO_START,
NULL, HFILL}
},
{&hf_alljoyn_mess_header_flags_allow_remote_msg,
{"Allow remote messages", "alljoyn.mess_header.flags.allowremotemessages",
FT_BOOLEAN, 8, NULL, MESSAGE_HEADER_FLAG_ALLOW_REMOTE_MSG,
NULL, HFILL}
},
{&hf_alljoyn_mess_header_flags_sessionless,
{"Sessionless", "alljoyn.mess_header.flags.sessionless",
FT_BOOLEAN, 8, NULL, MESSAGE_HEADER_FLAG_SESSIONLESS,
NULL, HFILL}
},
{&hf_alljoyn_mess_header_flags_global_broadcast,
{"Allow global broadcast", "alljoyn.mess_header.flags.globalbroadcast",
FT_BOOLEAN, 8, NULL, MESSAGE_HEADER_FLAG_GLOBAL_BROADCAST,
NULL, HFILL}
},
{&hf_alljoyn_mess_header_flags_compressed,
{"Compressed", "alljoyn.mess_header.flags.compressed",
FT_BOOLEAN, 8, NULL, MESSAGE_HEADER_FLAG_COMPRESSED,
NULL, HFILL}
},
{&hf_alljoyn_mess_header_flags_encrypted,
{"Encrypted", "alljoyn.mess_header.flags.encrypted",
FT_BOOLEAN, 8, NULL, MESSAGE_HEADER_FLAG_ENCRYPTED,
NULL, HFILL}
},
{&hf_alljoyn_mess_header_majorversion,
{"Major version", "alljoyn.mess_header.majorversion",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{&hf_alljoyn_mess_header_body_length,
{"Body length", "alljoyn.mess_header.bodylength",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{&hf_alljoyn_mess_header_serial,
{"Serial number", "alljoyn.mess_header.serial",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{&hf_alljoyn_mess_header_header_length,
{"Header length", "alljoyn.mess_header.headerlength",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{&hf_alljoyn_mess_header_fields,
{"Header fields", "alljoyn.mess_header.fields",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{&hf_alljoyn_mess_header_field,
{"Header field", "alljoyn.mess_header.field",
FT_UINT8, BASE_HEX, VALS(mess_header_field_encoding_vals), 0,
NULL, HFILL}
},
{&hf_alljoyn_mess_body_header_fieldcode,
{"Field code", "alljoyn.message.fieldcode",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL}
},
{&hf_alljoyn_mess_body_header_typeid,
{"Type ID", "alljoyn.message.typeid",
FT_UINT8, BASE_CUSTOM, CF_FUNC(alljoyn_typeid), 0,
NULL, HFILL}
},
{&hf_alljoyn_mess_body_parameters,
{"Parameters", "alljoyn.parameters",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{&hf_alljoyn_mess_body_array,
{"Array", "alljoyn.array",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{&hf_alljoyn_mess_body_structure,
{"struct", "alljoyn.structure",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{&hf_alljoyn_mess_body_dictionary_entry,
{"dictionary entry", "alljoyn.dictionary_entry",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{&hf_alljoyn_mess_body_variant,
{"Variant '", "alljoyn.variant",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{&hf_alljoyn_mess_body_signature_length,
{"Signature length", "alljoyn.parameter.signature_length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{&hf_alljoyn_mess_body_signature,
{"Signature", "alljoyn.parameter.signature",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_alljoyn_boolean,
{"Boolean", "alljoyn.boolean",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{&hf_alljoyn_uint8,
{"Unsigned byte", "alljoyn.uint8",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{&hf_alljoyn_int16,
{"Signed int16", "alljoyn.int16",
FT_INT16, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{&hf_alljoyn_uint16,
{"Unsigned int16", "alljoyn.uint16",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{&hf_alljoyn_handle,
{"Handle", "alljoyn.handle",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL}
},
{&hf_alljoyn_int32,
{"Signed int32", "alljoyn.int32",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{&hf_alljoyn_uint32,
{"Unsigned int32", "alljoyn.uint32",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{&hf_alljoyn_int64,
{"Signed int64", "alljoyn.int64",
FT_INT64, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{&hf_alljoyn_uint64,
{"Unsigned int64", "alljoyn.uint64",
FT_UINT64, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{&hf_alljoyn_double,
{"Double", "alljoyn.double",
FT_DOUBLE, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{&hf_padding,
{"Padding", "alljoyn.padding",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{&hf_alljoyn_string,
{"Bus Name", "alljoyn.string",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_alljoyn_string_size_8bit,
{"String Size 8-bit", "alljoyn.string.size8bit",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_alljoyn_string_size_32bit,
{"String Size 32-bit", "alljoyn.string.size32bit",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_alljoyn_string_data,
{"String Data", "alljoyn.string.data",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_ardp_syn_flag,
{"SYN", "ardp.hdr.SYN",
FT_BOOLEAN, 8, NULL, ARDP_SYN,
NULL, HFILL}
},
{&hf_ardp_ack_flag,
{"ACK", "ardp.hdr.ACK",
FT_BOOLEAN, 8, NULL, ARDP_ACK,
NULL, HFILL}},
{&hf_ardp_eak_flag,
{"EAK", "ardp.hdr.EAK",
FT_BOOLEAN, 8, NULL, ARDP_EAK,
NULL, HFILL}},
{&hf_ardp_rst_flag,
{"RST", "ardp.hdr.RST",
FT_BOOLEAN, 8, NULL, ARDP_RST,
NULL, HFILL}},
{&hf_ardp_nul_flag,
{"NUL", "ardp.hdr.NUL",
FT_BOOLEAN, 8, NULL, ARDP_NUL,
NULL, HFILL}},
{&hf_ardp_unused_flag,
{"UNUSED", "ardp.hdr.UNUSED",
FT_BOOLEAN, 8, NULL, ARDP_UNUSED,
NULL, HFILL}},
{&hf_ardp_version_field,
{"VER", "ardp.hdr.ver",
FT_UINT8, BASE_HEX, NULL, ARDP_VER,
NULL, HFILL}},
{&hf_ardp_hlen,
{"Header Length", "ardp.hdr.hlen",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_ardp_src,
{"Source Port", "ardp.hdr.src",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_ardp_dst,
{"Destination Port", "ardp.hdr.dst",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_ardp_dlen,
{"Data Length", "ardp.hdr.dlen",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_ardp_seq,
{"Sequence", "ardp.hdr.seq",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_ardp_ack,
{"Acknowledge", "ardp.hdr.ack",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_ardp_ttl,
{"Time to Live", "ardp.hdr.ttl",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_ardp_lcs,
{"Last Consumed Sequence", "ardp.hdr.lcs",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_ardp_nsa,
{"Next Sequence to ACK", "ardp.hdr.nsa",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_ardp_fss,
{"Fragment Starting Sequence", "ardp.hdr.fss",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_ardp_fcnt,
{"Fragment Count", "ardp.hdr.fcnt",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{&hf_ardp_bmp,
{"EACK Bitmap", "ardp.hdr.bmp",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{&hf_ardp_segmax,
{"Segment Max", "ardp.hdr.segmentmax",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_ardp_segbmax,
{"Segment Buffer Max", "ardp.hdr.segmentbmax",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_ardp_dackt,
{"Receiver's delayed ACK timeout", "ardp.hdr.dackt",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_ardp_options,
{"Options", "ardp.hdr.options",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
};
static gint *ett[] = {
&ett_alljoyn_ns,
&ett_alljoyn_ns_header,
&ett_alljoyn_ns_answers,
&ett_alljoyn_ns_guid_string,
&ett_alljoyn_ns_isat_entry,
&ett_alljoyn_ns_string,
&ett_alljoyn_whohas,
&ett_alljoyn_string,
&ett_alljoyn_isat_entry,
&ett_alljoyn_mess,
&ett_alljoyn_header,
&ett_alljoyn_header_flags,
&ett_alljoyn_mess_header_field,
&ett_alljoyn_mess_header,
&ett_alljoyn_mess_body_parameters,
&ett_alljoyn_ardp
};
static ei_register_info ei[] = {
{ &ei_alljoyn_empty_arg,
{ "alljoyn.empty_arg", PI_MALFORMED, PI_ERROR,
"Argument is empty", EXPFILL }}
};
proto_AllJoyn_ns = proto_register_protocol("AllJoyn Name Service Protocol", "AllJoyn NS", "ajns");
proto_AllJoyn_mess = proto_register_protocol("AllJoyn Message Protocol", "AllJoyn", "aj");
proto_register_field_array(proto_AllJoyn_ns, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_alljoyn = expert_register_protocol(proto_AllJoyn_mess);
expert_register_field_array(expert_alljoyn, ei, array_length(ei));
proto_AllJoyn_ardp = proto_register_protocol("AllJoyn Reliable Datagram Protocol", "AllJoyn ARDP", "ardp");
}
void
proto_reg_handoff_AllJoyn(void)
{
static gboolean initialized = FALSE;
static dissector_handle_t alljoyn_handle_ns;
static dissector_handle_t alljoyn_handle_ardp;
if(!initialized) {
alljoyn_handle_ns = create_dissector_handle(dissect_AllJoyn_name_server, proto_AllJoyn_ns);
alljoyn_handle_ardp = create_dissector_handle(dissect_AllJoyn_ardp, proto_AllJoyn_ardp);
} else {
dissector_delete_uint("udp.port", name_server_port, alljoyn_handle_ns);
dissector_delete_uint("tcp.port", name_server_port, alljoyn_handle_ns);
dissector_delete_uint("udp.port", message_port, alljoyn_handle_ardp);
dissector_delete_uint("tcp.port", message_port, alljoyn_handle_ardp);
}
dissector_add_uint("udp.port", name_server_port, alljoyn_handle_ns);
dissector_add_uint("tcp.port", name_server_port, alljoyn_handle_ns);
dissector_add_uint("udp.port", message_port, alljoyn_handle_ardp);
dissector_add_uint("tcp.port", message_port, alljoyn_handle_ardp);
}
