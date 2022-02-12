static int add_transport_layer_frame(int offset, tvbuff_t *tvb, proto_tree* ecmp_tree, int addr_type)
{
proto_item *ecmp_address_item = NULL;
proto_tree *ecmp_address_tree = NULL;
guint8 byte_test;
ecmp_address_item = proto_tree_add_item(ecmp_tree, addr_type, tvb, offset, 1, ENC_BIG_ENDIAN);
byte_test = tvb_get_guint8(tvb, offset);
if ((byte_test != 0) && (byte_test != 1)) {
ecmp_address_tree = proto_item_add_subtree(ecmp_address_item, ett_ecmp_address);
switch (byte_test)
{
case 2:
offset++;
proto_tree_add_item(ecmp_address_tree, hf_ecmp_physical_address, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ecmp_address_tree, hf_ecmp_logical_address, tvb, offset, 1, ENC_NA);
break;
case 3:
proto_tree_add_item(ecmp_address_tree, hf_ecmp_diagnostic, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
case 4:
proto_tree_add_item(ecmp_address_tree, hf_ecmp_names_scheme, tvb, offset, 2, ENC_BIG_ENDIAN|ENC_ASCII);
offset += (tvb_get_ntohs(tvb, offset) + 2);
break;
}
}
offset++;
return offset;
}
static int add_option_codes(int offset, packet_info *pinfo, tvbuff_t *tvb, proto_tree* ecmp_tree)
{
proto_item* ecmp_option_number_item = NULL;
proto_item* ecmp_option_item;
proto_tree* ecmp_option_tree;
proto_tree* ecmp_option_data_tree = NULL;
guint8 option_code_display = 0;
guint16 count = 0;
int start_offset;
gboolean more_options = TRUE;
offset++;
start_offset = offset;
ecmp_option_tree = proto_tree_add_subtree(ecmp_tree, tvb, offset, 1, ett_ecmp_option, &ecmp_option_number_item, "Options" );
while(more_options)
{
option_code_display = tvb_get_guint8(tvb, offset);
ecmp_option_item = proto_tree_add_item(ecmp_option_tree, hf_ecmp_option, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
switch(option_code_display)
{
case 0:
proto_item_append_text(ecmp_option_number_item, ": %d", count);
proto_item_set_len(ecmp_option_number_item, offset-start_offset);
more_options = FALSE;
break;
case 1:
break;
case 2:
ecmp_option_data_tree = proto_item_add_subtree(ecmp_option_item, ett_ecmp_option_data);
proto_tree_add_item(ecmp_option_data_tree, hf_ecmp_process_time, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
break;
default:
proto_item_append_text(ecmp_option_number_item, "%d ", count);
expert_add_info(pinfo, ecmp_option_number_item, &ei_ecmp_option);
break;
}
count++;
}
return offset;
}
static void add_attributes(packet_info* pinfo, int offset, tvbuff_t *tvb, proto_tree* ecmp_tree, gboolean request)
{
proto_item* ecmp_attribute_number_item = NULL;
proto_item* ecmp_attribute_item = NULL, *color_item;
proto_tree* ecmp_attribute_tree = NULL;
proto_tree* ecmp_attribute_data_tree = NULL;
guint8 no_of_attributes = 0;
guint8 a = 0;
guint8 b = 0;
guint8 c = 0;
guint8 check = 0;
guint16 att_length = 0;
guint32 color;
gchar* pStr = NULL;
int start_offset = offset;
ecmp_attribute_number_item = proto_tree_add_item(ecmp_tree, hf_ecmp_no_of_attributes, tvb, offset, 1, ENC_BIG_ENDIAN);
ecmp_attribute_tree = proto_item_add_subtree(ecmp_attribute_number_item, ett_ecmp_attribute);
no_of_attributes = tvb_get_guint8(tvb, offset);
offset++;
for (a = 0; a < no_of_attributes; a++, offset++) {
ecmp_attribute_item = proto_tree_add_item(ecmp_attribute_tree, hf_ecmp_attribute, tvb, offset, 1, ENC_BIG_ENDIAN );
ecmp_attribute_data_tree = proto_item_add_subtree(ecmp_attribute_item, ett_ecmp_attribute_data);
if (!request) {
switch(tvb_get_guint8(tvb, offset))
{
case 8:
offset+= 1;
offset+= 2;
color = tvb_get_ntohl(tvb, offset);
color_item = proto_tree_add_uint_format_value(ecmp_attribute_data_tree, hf_ecmp_primary_colour, tvb, offset, 4, color, "(red) %d (green) %d (blue) %d", tvb_get_guint8(tvb, offset+1), tvb_get_guint8(tvb, offset+2), tvb_get_guint8(tvb, offset+3));
if ((color & 0xFF000000) != 0) {
expert_add_info(pinfo, color_item, &ei_ecmp_color);
}
offset+= 4;
color = tvb_get_ntohl(tvb, offset);
color_item = proto_tree_add_uint_format_value(ecmp_attribute_data_tree, hf_ecmp_secondary_colour, tvb, offset, 4, color, "(red) %d (green) %d (blue) %d", tvb_get_guint8(tvb, offset+1), tvb_get_guint8(tvb, offset+2), tvb_get_guint8(tvb, offset+3));
if ((color & 0xFF000000) != 0) {
expert_add_info(pinfo, color_item, &ei_ecmp_color);
}
offset+= 4;
break;
case 7:
offset++;
att_length = tvb_get_ntohs(tvb, offset);
pStr = (gchar *)wmem_alloc(wmem_packet_scope(), att_length+1);
b = 0;
offset+= 2;
if (pStr != NULL) {
for (c = 0; c < att_length; c++, offset++) {
check = tvb_get_guint8(tvb,offset);
if((check == 'V')||(check == '#')||(check == '@')) {
pStr[b] = ' ';
b++;
} else if(tvb_get_guint8(tvb,offset)== (';')) {
pStr[b] = 0;
proto_tree_add_string(ecmp_attribute_data_tree, hf_ecmp_version_summary, tvb, offset-b, b, pStr);
b = 0;
} else {
pStr[b] = (gchar)tvb_get_guint8(tvb,offset);
b++;
}
}
pStr[b] = 0;
proto_tree_add_string(ecmp_attribute_data_tree, hf_ecmp_version_summary, tvb, offset-b, b, pStr);
offset-= 1;
}
break;
default:
proto_tree_add_item(ecmp_attribute_data_tree, hf_ecmp_attribute_string, tvb, offset+1, 2, ENC_BIG_ENDIAN|ENC_ASCII);
offset += (tvb_get_ntohs(tvb, offset+1) + 2);
break;
}
}
}
proto_item_set_len(ecmp_attribute_number_item, offset-start_offset);
}
static int add_category_codes(int offset, tvbuff_t *tvb, proto_tree* ecmp_tree)
{
proto_item *ecmp_category_item = NULL;
proto_tree *ecmp_category_tree = NULL;
guint8 category_size = 0;
int start_offset = offset;
guint8 category_value = tvb_get_guint8(tvb, offset);
ecmp_category_item = proto_tree_add_item(ecmp_tree, hf_ecmp_category, tvb, offset, 1, ENC_BIG_ENDIAN);
ecmp_category_tree = proto_item_add_subtree(ecmp_category_item, ett_ecmp_category);
offset++;
category_size = tvb_get_guint8(tvb, offset);
offset++;
if(category_size==2 && category_value == 1) {
proto_tree_add_item(ecmp_category_tree, hf_ecmp_category_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=category_size;
} else if(category_size == 4 && category_value == 0) {
proto_tree_add_item(ecmp_category_tree, hf_ecmp_drive_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ecmp_category_tree, hf_ecmp_drive_derivative, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ecmp_category_tree, hf_ecmp_drive_factory_fit_category_id, tvb, offset+2, 2, ENC_BIG_ENDIAN);
offset+=category_size;
} else {
proto_tree_add_item(ecmp_category_tree, hf_ecmp_data, tvb, offset, category_size, ENC_NA);
offset += category_size;
}
proto_item_set_len(ecmp_category_item, offset-start_offset);
return offset;
}
static int get_response_size(int offset, tvbuff_t *tvb, proto_tree* ecmp_tree)
{
proto_item* ecmp_max_response_item = NULL;
proto_tree* ecmp_response_size_tree = NULL;
guint8 chunks = 0;
guint16 max_response_size = 0;
chunks = tvb_get_guint8(tvb, offset)>>4&0x0F;
max_response_size = tvb_get_ntohs(tvb, offset) & 0x0FFF;
ecmp_response_size_tree = proto_tree_add_subtree_format(ecmp_tree, tvb, offset, 2, ett_ecmp_response_size, &ecmp_max_response_item, "Response Size: %X, %X (%d)", chunks, max_response_size, max_response_size);
proto_tree_add_item(ecmp_response_size_tree, hf_ecmp_chunking, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_uint_format_value(ecmp_response_size_tree, hf_ecmp_max_response_size, tvb, offset, 2, max_response_size, "%d bytes", max_response_size);
offset+= 2;
return offset;
}
static int add_command_codes(packet_info* pinfo, int offset, tvbuff_t *tvb, proto_tree* ecmp_tree, guint8 transaction_id_value, guint8* command_value)
{
proto_tree *ecmp_command_tree;
const gchar* command_str;
guint8 command;
command = tvb_get_guint8(tvb, offset);
*command_value = command & 0x7F;
command_str = val_to_str(*command_value, command_vals, "Unknown Type (0x%02x)");
ecmp_command_tree = proto_tree_add_subtree_format(ecmp_tree, tvb, offset, 1, ett_ecmp_command, NULL, "Request Response Code: %s", command_str);
proto_tree_add_item(ecmp_command_tree, hf_ecmp_command, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ecmp_command_tree, hf_ecmp_type_rr, tvb, offset, 1, ENC_BIG_ENDIAN);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s, %s. Transaction ID: %d",
command_str, val_to_str(((command & 0x80) >> 7), type_rr, "Unknown Type (0x%02x)"), transaction_id_value);
return offset;
}
static int add_cyclic_frame_query(int offset, tvbuff_t *tvb, proto_tree* ecmp_tree )
{
proto_tree_add_item(ecmp_tree, hf_ecmp_cyclic_link_num, tvb, offset++, 1, ENC_BIG_ENDIAN);
return offset;
}
static int add_cyclic_frame(int offset, tvbuff_t *tvb, proto_tree* ecmp_tree )
{
guint8 scheme;
proto_item *ecmp_scheme_item = NULL;
proto_tree *ecmp_scheme_tree = NULL;
proto_tree_add_item(ecmp_tree, hf_ecmp_cyclic_link_num, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ecmp_tree, hf_ecmp_cyclic_align, tvb, offset++, 1, ENC_BIG_ENDIAN);
scheme = tvb_get_guint8(tvb, offset);
ecmp_scheme_item = proto_tree_add_item(ecmp_tree, hf_ecmp_cyclic_scheme, tvb, offset++, 1, ENC_BIG_ENDIAN);
if (scheme == 1) {
ecmp_scheme_tree = proto_item_add_subtree(ecmp_scheme_item, ett_ecmp_cyclic_scheme);
proto_tree_add_item( ecmp_scheme_tree, hf_ecmp_grandmaster, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(ecmp_scheme_tree, hf_ecmp_cyclic_frame_time, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
}
proto_tree_add_item(ecmp_tree, hf_ecmp_data, tvb, offset, -1, ENC_NA);
return tvb_reported_length(tvb);
}
static int display_raw_cyclic_data(guint8 display, int offset, guint16 buffer_size, tvbuff_t *tvb, proto_tree* ecmp_current_tree )
{
if (buffer_size == 0) {
proto_tree_add_bytes_format_value(ecmp_current_tree, hf_ecmp_cyclic_data, tvb, offset-1, 0, NULL, "No data");
} else {
gchar* pdata = NULL;
guint16 idx = 0;
guint8 value8 = 0;
guint16 value16 = 0;
guint32 value32 = 0;
guint16 num_elements_total = 0;
const guint16 num_byte_elements_per_line = 16;
const guint16 num_word_elements_per_line = 16;
const guint16 num_long_elements_per_line = 8;
guint16 num_elements_per_line = 8;
guint16 num_elements = 0;
guint16 format_string_size = 0;
guint16 a = 0;
int start_offset, line_offset;
if (display == cyclic_display_byte_format) {
format_string_size = (num_byte_elements_per_line * 3) + 1;
num_elements_per_line = num_byte_elements_per_line;
num_elements_total = buffer_size;
} else if (display == cyclic_display_word_format) {
format_string_size = (num_word_elements_per_line * 5) + 1;
num_elements_per_line = num_word_elements_per_line;
num_elements_total = buffer_size >> 1;
} else if (display == cyclic_display_long_format) {
format_string_size = (num_long_elements_per_line * 9) + 1;
num_elements_per_line = num_long_elements_per_line;
num_elements_total = buffer_size >> 2;
} else {
format_string_size = (num_byte_elements_per_line * 3) + 1;
num_elements_per_line = num_byte_elements_per_line;
num_elements_total = buffer_size;
}
pdata = (gchar *)wmem_alloc(wmem_packet_scope(), format_string_size);
idx = 0;
num_elements = 0;
line_offset = start_offset = offset;
for (a = 0; a < num_elements_total; a++ )
{
if (display == cyclic_display_byte_format) {
value8 = tvb_get_guint8(tvb, offset);
offset++;
} else if (display == cyclic_display_word_format) {
value16 = tvb_get_ntohs(tvb, offset);
offset += 2;
} else if (display == cyclic_display_long_format) {
value32 = tvb_get_ntohl(tvb, offset);
offset += 4;
}
num_elements++;
if (num_elements >= num_elements_per_line) {
if (display == cyclic_display_byte_format) {
g_snprintf(&pdata[idx], 32, "%02x",value8);
} else if (display == cyclic_display_word_format) {
g_snprintf(&pdata[idx], 32, "%04x",value16);
} else if (display == cyclic_display_long_format) {
g_snprintf(&pdata[idx], 32, "%08x",value32);
}
proto_tree_add_bytes_format(ecmp_current_tree, hf_ecmp_cyclic_data, tvb, offset, offset-line_offset, NULL, "%s", pdata);
idx = 0;
num_elements = 0;
line_offset = offset;
} else {
if (display == cyclic_display_byte_format) {
g_snprintf(&pdata[idx], 32, "%02x ",value8);
idx += 3;
} else if (display == cyclic_display_word_format) {
g_snprintf(&pdata[idx], 32, "%04x ",value16);
idx += 5;
} else if (display == cyclic_display_long_format) {
g_snprintf(&pdata[idx], 32, "%08x ",value32);
idx += 9;
}
}
}
if (num_elements > 0) {
pdata[idx] = 0x00;
proto_tree_add_bytes_format(ecmp_current_tree, hf_ecmp_cyclic_data, tvb, start_offset, offset-start_offset, NULL, "%s", pdata);
}
}
return offset;
}
static void add_info_response(int offset, tvbuff_t *tvb, proto_tree* ecmp_tree)
{
proto_item* ecmp_info_address_item = NULL;
proto_tree* ecmp_info_tree = NULL;
proto_tree* ecmp_info_address_tree = NULL, *address_tree;
guint16 length = 0;
guint8 no_of_address = 0;
guint8 i = 0;
length = tvb_reported_length(tvb);
ecmp_info_tree = proto_tree_add_subtree(ecmp_tree, tvb, offset, 6, ett_ecmp_info_type, NULL, "Response Information");
proto_tree_add_item(ecmp_info_tree, hf_ecmp_buffer_size, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+= 2;
proto_tree_add_item(ecmp_info_tree, hf_ecmp_max_response, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+= 2;
proto_tree_add_item(ecmp_info_tree, hf_ecmp_max_handle, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+= 2;
if (length > offset) {
ecmp_info_address_item = proto_tree_add_item(ecmp_tree, hf_ecmp_info_address, tvb, offset, 1, ENC_BIG_ENDIAN);
ecmp_info_address_tree = proto_item_add_subtree(ecmp_info_address_item, ett_ecmp_info_count);
no_of_address = tvb_get_guint8(tvb, offset);
if (no_of_address > 0) {
for (i = 0; i < no_of_address; i++) {
address_tree = proto_tree_add_subtree_format(ecmp_info_address_tree, tvb, offset, 1, ett_ecmp_address, NULL, "Address %d", i+1);
proto_tree_add_item(address_tree, hf_ecmp_physical_address, tvb, offset, 1, ENC_NA);
proto_tree_add_item(address_tree, hf_ecmp_logical_address, tvb, offset, 1, ENC_NA);
offset+= 1;
}
}
}
}
static int get_data_type(packet_info* pinfo, int offset, guint8 data_type, tvbuff_t *tvb, proto_tree* ecmp_current_tree)
{
switch(data_type)
{
case 0:
proto_tree_add_item(ecmp_current_tree, hf_ecmp_data_boolean, tvb, offset, 1, ENC_NA);
break;
case 1:
proto_tree_add_item(ecmp_current_tree, hf_ecmp_data_int8, tvb, offset, 1, ENC_NA);
break;
case 2:
proto_tree_add_item(ecmp_current_tree, hf_ecmp_data_uint8, tvb, offset, 1, ENC_NA);
break;
case 3:
proto_tree_add_item(ecmp_current_tree, hf_ecmp_data_int16, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+= 1;
break;
case 4:
proto_tree_add_item(ecmp_current_tree, hf_ecmp_data_uint16, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+= 1;
break;
case 5:
proto_tree_add_item(ecmp_current_tree, hf_ecmp_data_int32, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+= 3;
break;
case 6:
proto_tree_add_item(ecmp_current_tree, hf_ecmp_data_uint32, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+= 3;
break;
case 7:
proto_tree_add_item(ecmp_current_tree, hf_ecmp_data_int64, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+= 7;
break;
case 8:
proto_tree_add_item(ecmp_current_tree, hf_ecmp_data_uint64, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+= 7;
break;
case 9:
proto_tree_add_item(ecmp_current_tree, hf_ecmp_data, tvb, offset, 16, ENC_NA);
offset += 15;
break;
case 10:
proto_tree_add_item(ecmp_current_tree, hf_ecmp_data, tvb, offset, 16, ENC_NA);
offset += 15;
break;
case 20:
proto_tree_add_item(ecmp_current_tree, hf_ecmp_data_float, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+= 3;
break;
case 21:
proto_tree_add_item(ecmp_current_tree, hf_ecmp_data_double, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+= 7;
break;
case 30:
proto_tree_add_item(ecmp_current_tree, hf_ecmp_string_id, tvb, offset, 2, ENC_NA|ENC_ASCII);
offset++;
break;
case 32:
proto_tree_add_item(ecmp_current_tree, hf_ecmp_ecmp_string, tvb, offset+1, 2, ENC_BIG_ENDIAN|ENC_ASCII);
offset += (tvb_get_ntohs(tvb, offset+1) + 2);
break;
default:
if (data_type < 128) {
proto_tree_add_expert(ecmp_current_tree, pinfo, &ei_ecmp_data_type, tvb, 0, -1);
} else {
proto_tree_add_item(ecmp_current_tree, hf_ecmp_data, tvb, offset, (data_type- 127), ENC_NA);
offset += (data_type- 128);
}
break;
}
return offset;
}
static int get_address_scheme(packet_info* pinfo, int offset, guint8 scheme, tvbuff_t *tvb, proto_tree* ecmp_parameter_tree)
{
switch (scheme)
{
case 0:
proto_tree_add_item(ecmp_parameter_tree, hf_ecmp_address_scheme_menu, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+= 2;
proto_tree_add_item(ecmp_parameter_tree, hf_ecmp_address_scheme_parameter, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
break;
case 1:
proto_tree_add_item(ecmp_parameter_tree, hf_ecmp_address_scheme_slot, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(ecmp_parameter_tree, hf_ecmp_address_scheme_menu, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+= 2;
proto_tree_add_item(ecmp_parameter_tree, hf_ecmp_address_scheme_parameter, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
break;
case 3:
offset--;
proto_tree_add_item(ecmp_parameter_tree, hf_ecmp_variable_name, tvb, offset+1, 2, ENC_BIG_ENDIAN|ENC_ASCII);
offset += (tvb_get_ntohs(tvb, offset+1) + 2);
break;
case 4:
proto_tree_add_item(ecmp_parameter_tree, hf_ecmp_address_scheme_null_byte_size, tvb, offset, 1, ENC_NA);
offset++;
break;
default:
proto_tree_add_expert(ecmp_parameter_tree, pinfo, &ei_ecmp_parameter_addressing_scheme, tvb, offset, 1);
}
return offset;
}
static void get_parameter_definitions(packet_info* pinfo, int offset, guint8 command_value, tvbuff_t *tvb, proto_tree* ecmp_tree)
{
proto_item* ecmp_parameter_item = NULL;
proto_tree* ecmp_parameter_number_tree = NULL;
proto_tree* ecmp_parameter_tree = NULL;
guint8 count = 0;
guint8 a = 0;
guint8 data_type = 0;
gint8 dec = 0;
guint8 scheme = 0;
guint16 n = 0;
scheme = tvb_get_guint8(tvb, offset);
ecmp_parameter_item = proto_tree_add_item(ecmp_tree, hf_ecmp_parameter_address, tvb, offset, 1, ENC_BIG_ENDIAN);
ecmp_parameter_tree = proto_item_add_subtree(ecmp_parameter_item, ett_ecmp_param_address);
offset++;
if(command_value == ECMP_COMMAND_GETNEXTOBJECTS)
{
offset = get_address_scheme(pinfo, offset, scheme, tvb, ecmp_parameter_tree);
offset++;
proto_tree_add_item(ecmp_tree, hf_ecmp_number_of_subsequent_object_requests, tvb, offset, 1, ENC_NA);
}else
{
ecmp_parameter_item = proto_tree_add_item(ecmp_tree, hf_ecmp_number_of_parameter_definitions, tvb, offset, 1, ENC_BIG_ENDIAN);
ecmp_parameter_number_tree = proto_item_add_subtree(ecmp_parameter_item, ett_ecmp_param_address);
count = tvb_get_guint8(tvb,offset);
offset++;
switch(scheme)
{
case 0:
n = 4;
break;
case 1:
n = 5;
break;
case 3:
n = 1 + ((tvb_get_guint8(tvb, offset+1)<<8)|(tvb_get_guint8(tvb, offset+2)));
break;
default:
n = 0;
break;
}
if (command_value == ECMP_COMMAND_OBJECTINFO) {
n += 1;
}
for (a = 0; a < count; a++) {
ecmp_parameter_tree = proto_tree_add_subtree_format(ecmp_parameter_number_tree, tvb, offset, n, ett_ecmp_param_address, NULL, "Parameter Definition %d:", (a+1));
if (command_value == ECMP_COMMAND_OBJECTINFO) {
proto_tree_add_item(ecmp_parameter_tree, hf_ecmp_info_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
offset = get_address_scheme(pinfo, offset, scheme, tvb, ecmp_parameter_tree);
offset++;
} else {
offset = get_address_scheme(pinfo, offset, scheme, tvb, ecmp_parameter_tree);
offset++;
if (command_value == ECMP_COMMAND_WRITE) {
data_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(ecmp_parameter_tree, hf_ecmp_data_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
dec = (gint8)tvb_get_guint8(tvb, offset);
if (dec != -1) {
proto_tree_add_int(ecmp_parameter_tree, hf_ecmp_number_of_decimal_places, tvb, offset, 1, dec);
} else {
proto_tree_add_int_format_value(ecmp_parameter_tree, hf_ecmp_number_of_decimal_places, tvb, offset, 1, dec, "0 (Invalid type)");
}
offset++;
offset = get_data_type(pinfo, offset, data_type, tvb, ecmp_parameter_tree);
offset++;
}
}
}
}
}
static void get_object_info_response(packet_info* pinfo, int offset, tvbuff_t *tvb, proto_tree* ecmp_tree)
{
proto_item* ecmp_response_item = NULL;
proto_tree* ecmp_parameter_number_tree = NULL;
proto_tree* ecmp_parameter_response_tree = NULL;
guint8 count = 0;
guint8 a = 0;
guint8 n = 0;
guint8 info_type0 = 0;
guint16 length = 0;
guint8 data_type = 0;
length = tvb_reported_length(tvb);
ecmp_response_item = proto_tree_add_item(ecmp_tree, hf_ecmp_number_of_parameter_responses, tvb, offset, 1, ENC_BIG_ENDIAN);
ecmp_parameter_number_tree = proto_item_add_subtree(ecmp_response_item, ett_ecmp_param_address);
count = tvb_get_guint8(tvb, offset);
if (count == 0) {
offset++;
proto_tree_add_item(ecmp_parameter_number_tree, hf_ecmp_parameter_status, tvb, offset, 1, ENC_BIG_ENDIAN);
} else {
for (a = 0; a < count; a++) {
if (a==0) {
n = (length-offset)/count;
}
offset++;
proto_tree_add_subtree_format(ecmp_parameter_number_tree, tvb, offset, n, ett_ecmp_command, NULL, "Response %d:", (a+1));
proto_tree_add_item(ecmp_parameter_response_tree, hf_ecmp_parameter_status, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ecmp_parameter_response_tree, hf_ecmp_info_type, tvb, offset, 1, ENC_BIG_ENDIAN);
info_type0 = tvb_get_guint8(tvb, offset);
switch(info_type0)
{
case 0:
proto_tree_add_item(ecmp_parameter_response_tree, hf_ecmp_no_information_available, tvb, offset, 1, ENC_NA);
break;
case 1:
offset++;
proto_tree_add_item(ecmp_parameter_response_tree, hf_ecmp_min_param_menu, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
break;
case 2:
offset++;
proto_tree_add_item(ecmp_parameter_response_tree, hf_ecmp_max_param_menu, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
break;
case 3:
{
static const int * fields[] = {
&hf_ecmp_param_format_bit_default_unipolar,
&hf_ecmp_param_format_write_allowed,
&hf_ecmp_param_format_read_not_allowed,
&hf_ecmp_param_format_protected_from_destinations,
&hf_ecmp_param_format_parameter_not_visible,
&hf_ecmp_param_format_not_clonable,
&hf_ecmp_param_format_voltage_or_current_rating_dependant,
&hf_ecmp_param_format_parameter_has_no_default,
&hf_ecmp_param_format_number_of_decimal_places,
&hf_ecmp_param_format_variable_maximum_and_minimum,
&hf_ecmp_param_format_string_parameter,
&hf_ecmp_param_format_desitination_set_up_parameter,
&hf_ecmp_param_format_filtered_when_displayed,
&hf_ecmp_param_format_pseudo_read_only,
&hf_ecmp_param_format_display_format,
&hf_ecmp_param_format_floating_point_value,
&hf_ecmp_param_format_units,
NULL
};
offset++;
proto_tree_add_bitmask_list(ecmp_parameter_response_tree, tvb, offset, 4, fields, ENC_BIG_ENDIAN);
offset+= 3;
}
break;
case 4:
offset++;
data_type = tvb_get_guint8(tvb,offset);
ecmp_response_item = proto_tree_add_item(ecmp_parameter_response_tree, hf_ecmp_data_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
offset = get_data_type(pinfo, offset, data_type, tvb, ecmp_parameter_response_tree);
break;
case 5:
offset++;
data_type = tvb_get_guint8(tvb,offset);
ecmp_response_item = proto_tree_add_item(ecmp_parameter_response_tree, hf_ecmp_data_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
offset = get_data_type(pinfo, offset, data_type, tvb, ecmp_parameter_response_tree);
break;
case 6:
offset++;
proto_tree_add_item(ecmp_parameter_response_tree, hf_ecmp_string_id, tvb, offset, 2, ENC_NA|ENC_ASCII);
offset++;
break;
case 7:
offset++;
ecmp_response_item = proto_tree_add_item(ecmp_parameter_response_tree, hf_ecmp_data_type, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
default:
expert_add_info(pinfo, ecmp_response_item, &ei_ecmp_info_type);
break;
}
}
}
}
static int get_parameter_responses(packet_info* pinfo, int offset, guint8 command_value, tvbuff_t *tvb, proto_tree* ecmp_tree)
{
proto_item* ecmp_response_item = NULL;
proto_tree* ecmp_parameter_number_tree = NULL;
proto_tree* ecmp_parameter_response_tree = NULL;
guint8 count = 0;
guint8 a = 0;
guint8 data_type = 0;
guint8 unit_id = 0;
gint8 dec = 0;
guint16 n = 0;
guint8 st_error = 0;
guint16 length = 0;
guint8 scheme = 0;
int start_offset;
scheme = tvb_get_guint8(tvb, offset);
length = tvb_reported_length(tvb);
if (command_value == ECMP_COMMAND_GETNEXTOBJECTS) {
proto_tree_add_item(ecmp_tree, hf_ecmp_parameter_address, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
ecmp_response_item = proto_tree_add_item(ecmp_tree, hf_ecmp_number_of_parameter_responses, tvb, offset, 1, ENC_BIG_ENDIAN);
ecmp_parameter_number_tree = proto_item_add_subtree(ecmp_response_item, ett_ecmp_param_address);
count = tvb_get_guint8(tvb, offset);
if (count == 0) {
offset++;
if (command_value != ECMP_COMMAND_GETNEXTOBJECTS) {
proto_tree_add_item(ecmp_parameter_number_tree, hf_ecmp_parameter_status, tvb, offset, 1, ENC_BIG_ENDIAN);
}
} else {
for (a = 0; a < count; a++) {
if (command_value == ECMP_COMMAND_WRITE) {
if (a==0) {
n = (length-offset)/count;
}
offset++;
ecmp_parameter_response_tree = proto_tree_add_subtree_format(ecmp_parameter_number_tree, tvb, offset, n, ett_ecmp_command, NULL, "Response %d:", (a+1));
ecmp_response_item = proto_tree_add_item(ecmp_parameter_response_tree, hf_ecmp_parameter_status, tvb, offset, 1, ENC_BIG_ENDIAN);
} else if (command_value == ECMP_COMMAND_GETNEXTOBJECTS) {
if (a==0) {
n = (length-offset)/count;
}
offset++;
ecmp_parameter_response_tree = proto_tree_add_subtree_format(ecmp_parameter_number_tree, tvb, offset, n, ett_ecmp_command, NULL, "Response %d:", (a+1));
offset = get_address_scheme(pinfo, offset, scheme, tvb, ecmp_parameter_response_tree);
} else {
if ((gint8)tvb_get_guint8(tvb, offset+1) < 0) {
st_error = 1;
offset++;
ecmp_parameter_response_tree = proto_tree_add_subtree_format(ecmp_parameter_number_tree, tvb, offset, 1, ett_ecmp_command, NULL, "Response %d:", (a+1));
ecmp_response_item = proto_tree_add_item(ecmp_parameter_response_tree, hf_ecmp_parameter_status, tvb, offset, 1, ENC_BIG_ENDIAN);
if ((a+1) != count) {
while(1) {
if(tvb_get_guint8(tvb, offset+1)==0) {
offset++;
} else {
break;
}
}
}
} else {
offset++;
start_offset = offset;
ecmp_parameter_response_tree = proto_tree_add_subtree_format(ecmp_parameter_number_tree, tvb, offset, 0, ett_ecmp_command, &ecmp_response_item, "Response %d:", (a+1));
proto_tree_add_item(ecmp_parameter_response_tree, hf_ecmp_parameter_status, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ecmp_parameter_response_tree, hf_ecmp_data_type, tvb, offset, 1, ENC_BIG_ENDIAN);
data_type = tvb_get_guint8(tvb,offset);
offset++;
offset = get_data_type(pinfo, offset, data_type, tvb, ecmp_parameter_response_tree);
if ((command_value == ECMP_COMMAND_READWITHTYPE) && (st_error!= 1)) {
offset++;
dec = (gint8)tvb_get_guint8(tvb, offset);
if (dec != -1) {
proto_tree_add_int(ecmp_parameter_response_tree, hf_ecmp_number_of_decimal_places, tvb, offset, 1, dec);
} else {
proto_tree_add_int_format_value(ecmp_parameter_response_tree, hf_ecmp_number_of_decimal_places, tvb, offset, 1, dec, "0 (Invalid type)");
}
offset++;
unit_id = tvb_get_guint8(tvb, offset);
proto_tree_add_item(ecmp_parameter_response_tree, hf_ecmp_display_unit_id, tvb, offset, 1, ENC_NA);
if (unit_id == 255) {
offset++;
proto_tree_add_item(ecmp_parameter_response_tree, hf_ecmp_unit_id_string, tvb, offset, 2, ENC_BIG_ENDIAN|ENC_ASCII);
offset += (tvb_get_ntohs(tvb, offset) + 2);
}
}
proto_item_set_len(ecmp_response_item, offset-start_offset);
}
}
}
}
return offset;
}
static void file_open(int offset, gboolean request, tvbuff_t *tvb, proto_tree* ecmp_tree)
{
proto_tree* ecmp_scheme_data_tree = NULL;
guint8 additional_scheme = 0;
guint8 relative = 0;
if (request) {
static const int * fields[] = {
&hf_ecmp_open_in_non_blocking_mode,
&hf_ecmp_open_file_relative_to_specified_directory_handle,
&hf_ecmp_file_access_mode,
NULL
};
proto_tree_add_bitmask(ecmp_tree, tvb, offset, hf_ecmp_access_mode, ett_ecmp_access_mode, fields, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ecmp_tree, hf_ecmp_additional_scheme, tvb, offset, 1, ENC_BIG_ENDIAN);
additional_scheme= tvb_get_guint8(tvb, offset);
proto_tree_add_item(ecmp_tree, hf_ecmp_file_name, tvb, offset+1, 2, ENC_BIG_ENDIAN|ENC_ASCII);
offset += (tvb_get_ntohs(tvb, offset+1) + 2);
if (relative == 1) {
offset++;
proto_tree_add_item(ecmp_tree, hf_ecmp_file_handle, tvb, offset, 2, ENC_BIG_ENDIAN);
}
if (additional_scheme == 1) {
offset+= 2;
ecmp_scheme_data_tree = proto_tree_add_subtree(ecmp_tree, tvb, offset, -1, ett_ecmp_access_file, NULL, "Additional scheme data");
proto_tree_add_item(ecmp_scheme_data_tree, hf_ecmp_scheme_data_length, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(ecmp_scheme_data_tree, hf_ecmp_data, tvb, offset, -1, ENC_NA);
}
} else {
proto_tree_add_item(ecmp_tree, hf_ecmp_file_status, tvb, offset, 1, ENC_BIG_ENDIAN);
if ((gint8)tvb_get_guint8(tvb, offset) >= 0) {
offset++;
proto_tree_add_item(ecmp_tree, hf_ecmp_file_handle, tvb, offset, 2, ENC_BIG_ENDIAN);
}
}
}
static void file_read(int offset, gboolean request, tvbuff_t *tvb, proto_tree* ecmp_tree)
{
guint16 req_bytes = 0;
if (request) {
proto_tree_add_item(ecmp_tree, hf_ecmp_file_handle, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(ecmp_tree, hf_ecmp_number_of_requested_bytes, tvb, offset, 2, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(ecmp_tree, hf_ecmp_file_status, tvb, offset, 1, ENC_BIG_ENDIAN);
if ((gint8)tvb_get_guint8(tvb, offset)>= 0) {
offset++;
req_bytes = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(ecmp_tree, hf_ecmp_response_data, tvb, offset, req_bytes+2, ENC_NA);
}
}
}
static void file_write(int offset, gboolean request, tvbuff_t *tvb, proto_tree* ecmp_tree)
{
guint16 req_bytes;
if (request) {
proto_tree_add_item(ecmp_tree, hf_ecmp_file_handle, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
req_bytes = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(ecmp_tree, hf_ecmp_data, tvb, offset+2, req_bytes, ENC_NA);
} else {
proto_tree_add_item(ecmp_tree, hf_ecmp_file_status, tvb, offset, 1, ENC_BIG_ENDIAN);
}
}
static void file_close(int offset, gboolean request, tvbuff_t *tvb, proto_tree* ecmp_tree)
{
if (request) {
proto_tree_add_item(ecmp_tree, hf_ecmp_file_handle, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(ecmp_tree, hf_ecmp_number_of_bytes_transferred, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+= 4;
proto_tree_add_item(ecmp_tree, hf_ecmp_crc, tvb, offset, 4, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(ecmp_tree, hf_ecmp_file_status, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
}
static int get_file_attribute(packet_info* pinfo, int offset, guint8 attribute0, tvbuff_t *tvb, proto_tree* ecmp_current_tree)
{
nstime_t ts;
switch(attribute0)
{
case 0:
proto_tree_add_item(ecmp_current_tree, hf_ecmp_file_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+= 3;
break;
case 1:
proto_tree_add_item(ecmp_current_tree, hf_ecmp_file_integrity, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 2:
proto_tree_add_item(ecmp_current_tree, hf_ecmp_crc, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+= 3;
break;
case 3:
{
static const int * fields[] = {
&hf_ecmp_display_attr_read_only,
&hf_ecmp_display_attr_hidden,
&hf_ecmp_display_attr_system,
&hf_ecmp_display_attr_volume_label,
&hf_ecmp_display_attr_subdirectory,
&hf_ecmp_display_attr_archive,
NULL
};
proto_tree_add_bitmask_list(ecmp_current_tree, tvb, offset, 1, fields, ENC_BIG_ENDIAN);
}
break;
case 4:
ts.secs = tvb_get_ntohl(tvb, offset);
ts.nsecs = 0;
proto_tree_add_time(ecmp_current_tree, hf_ecmp_display_creation, tvb, offset, 4, &ts);
offset+= 3;
break;
case 5:
ts.secs = tvb_get_ntohl(tvb, offset);
ts.nsecs = 0;
proto_tree_add_time(ecmp_current_tree, hf_ecmp_display_modification, tvb, offset, 4, &ts);
offset+= 3;
break;
default:
proto_tree_add_expert(ecmp_current_tree, pinfo, &ei_ecmp_attribute_type, tvb, offset, 1);
break;
}
return offset;
}
static void file_info(packet_info* pinfo, int offset, gboolean request, tvbuff_t *tvb, proto_tree* ecmp_tree)
{
proto_item* ecmp_file_info_item = NULL;
proto_tree* ecmp_file_info_tree = NULL;
proto_tree* ecmp_file_info_att_tree = NULL;
guint8 no_of_att = 0;
guint8 attribute0 = 0;
guint8 a = 0;
int start_offset;
if (request) {
proto_tree_add_item(ecmp_tree, hf_ecmp_file_handle, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
no_of_att = tvb_get_guint8(tvb, offset);
ecmp_file_info_item = proto_tree_add_uint(ecmp_tree, hf_ecmp_no_of_attributes, tvb, offset, 1, no_of_att);
ecmp_file_info_tree = proto_item_add_subtree(ecmp_file_info_item, ett_ecmp_file_info);
offset++;
for (a = 0; a < no_of_att; a++) {
ecmp_file_info_item = proto_tree_add_item(ecmp_file_info_tree, hf_ecmp_file_attributes, tvb, offset, 1, ENC_BIG_ENDIAN);
ecmp_file_info_att_tree = proto_item_add_subtree(ecmp_file_info_item, ett_ecmp_file_info_att);
attribute0 = tvb_get_guint8(tvb, offset);
offset++;
offset = get_file_attribute(pinfo, offset, attribute0, tvb, ecmp_file_info_att_tree);
}
proto_item_set_len(ecmp_file_info_item, no_of_att);
} else {
proto_tree_add_item(ecmp_tree, hf_ecmp_file_status, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
no_of_att = tvb_get_guint8(tvb, offset);
ecmp_file_info_item = proto_tree_add_uint(ecmp_tree, hf_ecmp_no_of_attributes, tvb, offset, 1, no_of_att);
ecmp_file_info_tree = proto_item_add_subtree(ecmp_file_info_item, ett_ecmp_file_info);
start_offset = offset;
for (a = 0; a < no_of_att; a++) {
offset++;
ecmp_file_info_item = proto_tree_add_item(ecmp_file_info_tree, hf_ecmp_file_attributes, tvb, offset, 1, ENC_BIG_ENDIAN);
ecmp_file_info_att_tree = proto_item_add_subtree(ecmp_file_info_item, ett_ecmp_file_info_att);
attribute0 = tvb_get_guint8(tvb, offset);
offset++;
offset = get_file_attribute(pinfo, offset, attribute0, tvb, ecmp_file_info_att_tree);
}
proto_item_set_len(ecmp_file_info_item, offset-start_offset);
}
}
static void file_state_delete(guint16 offset, gboolean request, tvbuff_t *tvb, proto_tree* ecmp_tree)
{
if (request) {
proto_tree_add_item(ecmp_tree, hf_ecmp_file_handle, tvb, offset, 2, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(ecmp_tree, hf_ecmp_file_status, tvb, offset, 1, ENC_BIG_ENDIAN);
}
}
static void file_pos(int offset, gboolean request, tvbuff_t *tvb, proto_tree* ecmp_tree)
{
proto_tree* ecmp_file_position_tree = NULL;
if (request) {
proto_tree_add_item(ecmp_tree, hf_ecmp_file_handle, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
ecmp_file_position_tree = proto_tree_add_subtree(ecmp_tree, tvb, offset, 5, ett_ecmp_file_position, NULL, "Position");
proto_tree_add_item(ecmp_file_position_tree, hf_ecmp_file_ref_point, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ecmp_file_position_tree, hf_ecmp_ref_offset, tvb, offset, 4, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(ecmp_tree, hf_ecmp_file_status, tvb, offset, 1, ENC_BIG_ENDIAN);
if((gint8)tvb_get_guint8(tvb,offset) >= 0) {
offset++;
proto_tree_add_item(ecmp_file_position_tree, hf_ecmp_ref_offset, tvb, offset, 4, ENC_BIG_ENDIAN);
}
}
}
static void file_list(packet_info* pinfo, int offset, gboolean request, tvbuff_t *tvb, proto_tree* ecmp_tree)
{
proto_item* ecmp_file_list_item, *ecmp_file_list_item2, *item_type_item;
proto_tree* ecmp_file_list_no_tree = NULL;
proto_tree* ecmp_file_list_tree = NULL;
guint8 no_of_items = 0;
guint8 item_type = 0;
guint8 a = 0;
guint16 n = 0;
int start_offset, start_offset2;
if (request) {
proto_tree_add_item(ecmp_tree, hf_ecmp_file_handle, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+= 2;
proto_tree_add_item(ecmp_tree, hf_ecmp_number_of_files_to_list, tvb, offset, 1, ENC_NA);
} else {
proto_tree_add_item(ecmp_tree, hf_ecmp_file_status, tvb, offset, 1, ENC_BIG_ENDIAN);
if ((gint8)tvb_get_guint8(tvb,offset) >= 0) {
offset++;
no_of_items = tvb_get_guint8(tvb, offset);
proto_tree_add_item(ecmp_tree, hf_ecmp_number_of_files_to_list, tvb, offset, 1, ENC_NA);
offset++;
ecmp_file_list_item = proto_tree_add_item(ecmp_tree, hf_ecmp_file_hash, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
start_offset = offset+1;
ecmp_file_list_no_tree = proto_tree_add_subtree(ecmp_tree, tvb, offset+1, no_of_items, ett_ecmp_file_list_no, &ecmp_file_list_item, "Files");
for (a = 0; a < no_of_items; a++) {
start_offset2 = offset;
offset++;
item_type = tvb_get_guint8(tvb, offset);
n = tvb_get_ntohs(tvb, offset+1);
ecmp_file_list_tree = proto_tree_add_subtree_format(ecmp_file_list_no_tree, tvb, offset, n+2, ett_ecmp_file_list, &ecmp_file_list_item2, "File %d:", a+1);
item_type_item = proto_tree_add_item(ecmp_file_list_tree, hf_ecmp_item_type, tvb, offset, 1, ENC_NA);
switch(item_type)
{
case 0:
proto_tree_add_item(ecmp_file_list_tree, hf_ecmp_file_name, tvb, offset+1, 2, ENC_BIG_ENDIAN|ENC_ASCII);
break;
case 1:
proto_tree_add_item(ecmp_file_list_tree, hf_ecmp_directory, tvb, offset+1, 2, ENC_BIG_ENDIAN|ENC_ASCII);
break;
default:
expert_add_info(pinfo, item_type_item, &ei_ecmp_item_type);
break;
}
offset+= n;
proto_item_set_len(ecmp_file_list_item2, offset-start_offset2);
}
proto_item_set_len(ecmp_file_list_item, (offset+1)-start_offset);
}
}
}
static void file_exists(int offset, gboolean request, tvbuff_t *tvb, proto_tree* ecmp_tree)
{
if (request) {
proto_tree_add_item(ecmp_tree, hf_ecmp_file_name, tvb, offset, 2, ENC_BIG_ENDIAN|ENC_ASCII);
} else {
proto_tree_add_item(ecmp_tree, hf_ecmp_file_status, tvb, offset, 1, ENC_BIG_ENDIAN);
}
}
static int add_cyclic_setup_attributes(packet_info* pinfo, int offset, guint16 length, tvbuff_t *tvb, proto_tree* ecmp_tree)
{
proto_item *cyclic_setup_attributes_root = NULL;
proto_item *cyclic_setup_attributes = NULL;
proto_item *cyclic_setup_attrib_item_root = NULL;
proto_tree *cyclic_setup_attrib_item = NULL;
guint8 attrib;
cyclic_setup_attributes_root = proto_tree_add_item(ecmp_tree, hf_ecmp_cyclic_setup_attrib_count, tvb, offset++, 1, ENC_BIG_ENDIAN);
cyclic_setup_attributes = proto_item_add_subtree(cyclic_setup_attributes_root, ett_cyclic_setup_attribs);
while (offset < length) {
attrib = tvb_get_guint8(tvb, offset);
cyclic_setup_attrib_item_root = proto_tree_add_item(cyclic_setup_attributes, hf_ecmp_cyclic_setup_attrib, tvb, offset++, 1, ENC_BIG_ENDIAN);
cyclic_setup_attrib_item = proto_item_add_subtree(cyclic_setup_attrib_item_root, ett_cyclic_setup_attrib_item);
switch (attrib) {
case 3:
{
proto_tree_add_item(cyclic_setup_attrib_item, hf_ecmp_mec_offset, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
break;
case 4:
case 5:
{
proto_tree_add_item(cyclic_setup_attrib_item, hf_ecmp_sample_period, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
}
break;
case 7:
{
guint32 val;
val = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint_format_value(cyclic_setup_attrib_item, hf_ecmp_rx_timeout, tvb, offset, 4, val, "%dus", val);
offset += 4;
proto_tree_add_item(cyclic_setup_attrib_item, hf_ecmp_rx_action, tvb, offset++, 1, ENC_NA);
proto_tree_add_item(cyclic_setup_attrib_item, hf_ecmp_rx_event_destination, tvb, offset++, 1, ENC_NA);
proto_tree_add_item(cyclic_setup_attrib_item, hf_ecmp_rx_event, tvb, offset++, 1, ENC_NA);
}
break;
case 8:
{
proto_tree_add_item(cyclic_setup_attrib_item, hf_ecmp_rx_late_handler_action, tvb, offset++, 1, ENC_NA);
proto_tree_add_item(cyclic_setup_attrib_item, hf_ecmp_rx_late_handler_event_destination, tvb, offset++, 1, ENC_NA);
proto_tree_add_item(cyclic_setup_attrib_item, hf_ecmp_rx_late_handler_event, tvb, offset++, 1, ENC_NA);
}
break;
case 9:
{
proto_tree_add_item(cyclic_setup_attrib_item, hf_ecmp_transport_addr_scheme, tvb, offset++, 1, ENC_NA);
proto_tree_add_item(cyclic_setup_attrib_item, hf_ecmp_transport_addr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
break;
case 12:
{
guint8 addrScheme;
proto_tree_add_item(cyclic_setup_attrib_item, hf_ecmp_mapping_item_offset, tvb, offset++, 1, ENC_NA);
addrScheme = tvb_get_guint8(tvb, offset);
proto_tree_add_item(cyclic_setup_attrib_item, hf_ecmp_mapping_item_scheme, tvb, offset++, 1, ENC_NA);
offset = get_address_scheme(pinfo, offset, addrScheme, tvb, cyclic_setup_attrib_item);
offset++;
}
break;
case 0:
case 1:
case 2:
case 6:
case 10:
case 11:
case 13:
case 128:
case 129:
case 130:
case 131:
case 132:
case 133:
case 134:
{
proto_tree_add_item(cyclic_setup_attrib_item, hf_ecmp_setup_attribute, tvb, offset++, 1, ENC_NA);
}
break;
case 135:
{
proto_tree_add_item(cyclic_setup_attrib_item, hf_ecmp_mec_period, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
break;
default:
break;
}
}
return offset;
}
static void cyclic_setup(packet_info* pinfo, guint16 offset, gboolean request, tvbuff_t *tvb, proto_tree* ecmp_tree)
{
guint16 length = 0;
proto_item* cyclic_setup_attributes_root = NULL;
proto_item* cyclic_setup_attributes = NULL;
guint8 Mode;
length = tvb_reported_length(tvb);
if (request) {
proto_tree_add_item(ecmp_tree, hf_ecmp_cyclic_setup_linkno, tvb, offset++, 1, ENC_BIG_ENDIAN);
Mode = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(ecmp_tree, hf_ecmp_cyclic_setup_mode, tvb, offset++, 1, Mode);
switch (Mode) {
case 0:
case 10:
{
proto_tree_add_item(ecmp_tree, hf_ecmp_cyclic_setup_dir, tvb, offset++, 1, ENC_BIG_ENDIAN);
add_cyclic_setup_attributes(pinfo, offset, length, tvb, ecmp_tree);
}
break;
case 1:
case 2:
case 3:
case 4:
proto_tree_add_item(ecmp_tree, hf_ecmp_cyclic_setup_dir, tvb, offset++, 1, ENC_BIG_ENDIAN);
break;
case 5:
proto_tree_add_item(ecmp_tree, hf_ecmp_data, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_NA);
break;
case 11:
case 6:
{
if (Mode == 11) {
proto_tree_add_item(ecmp_tree, hf_ecmp_cyclic_setup_dir, tvb, offset++, 1, ENC_BIG_ENDIAN);
}
cyclic_setup_attributes_root = proto_tree_add_item(ecmp_tree, hf_ecmp_cyclic_setup_attrib_count, tvb, offset++, 1, ENC_BIG_ENDIAN);
cyclic_setup_attributes = proto_item_add_subtree(cyclic_setup_attributes_root, ett_cyclic_setup_attribs);
while (offset < length) {
proto_tree_add_item(cyclic_setup_attributes, hf_ecmp_cyclic_setup_attrib, tvb, offset++, 1, ENC_BIG_ENDIAN);
}
}
break;
case 12:
{
proto_tree_add_item(ecmp_tree, hf_ecmp_cyclic_setup_dir, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ecmp_tree, hf_ecmp_cyclic_setup_max_mappings, tvb, offset++, 1, ENC_NA);
proto_tree_add_item(ecmp_tree, hf_ecmp_cyclic_setup_start_offset, tvb, offset++, 1, ENC_NA);
}
break;
default:
proto_tree_add_item(ecmp_tree, hf_ecmp_data, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_NA);
break;
}
} else {
proto_tree_add_item(ecmp_tree, hf_ecmp_cyclic_setup_rsp_status, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ecmp_tree, hf_ecmp_cyclic_setup_rsp_err_idx, tvb, offset++, 1, ENC_BIG_ENDIAN);
Mode = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(ecmp_tree, hf_ecmp_cyclic_setup_mode, tvb, offset++, 1, Mode);
switch (Mode) {
case 0:
case 1:
case 2:
case 3:
break;
case 4:
proto_tree_add_item(ecmp_tree, hf_ecmp_cyclic_setup_link_exists, tvb, offset++, 1, ENC_BIG_ENDIAN);
break;
case 5:
{
guint8 txCount, rxCount, linkno;
txCount = tvb_get_guint8(tvb, offset);
cyclic_setup_attributes_root = proto_tree_add_item(ecmp_tree, hf_ecmp_cyclic_setup_tx_count, tvb, offset++, 1, ENC_NA);
cyclic_setup_attributes = proto_item_add_subtree(cyclic_setup_attributes_root, ett_cyclic_setup_attribs);
while (txCount > 0) {
linkno = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(cyclic_setup_attributes, hf_ecmp_cyclic_setup_linkno, tvb, offset++, 1, linkno);
txCount--;
}
rxCount = tvb_get_guint8(tvb, offset);
cyclic_setup_attributes_root = proto_tree_add_item(ecmp_tree, hf_ecmp_cyclic_setup_rx_count, tvb, offset++, 1, ENC_NA);
cyclic_setup_attributes = proto_item_add_subtree(cyclic_setup_attributes_root, ett_cyclic_setup_attribs);
while (rxCount > 0) {
linkno = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(cyclic_setup_attributes, hf_ecmp_cyclic_setup_linkno, tvb, offset++, 1, linkno);
rxCount--;
}
}
break;
case 10:
{
cyclic_setup_attributes_root = proto_tree_add_item(ecmp_tree, hf_ecmp_cyclic_setup_attrib_count, tvb, offset++, 1, ENC_BIG_ENDIAN);
cyclic_setup_attributes = proto_item_add_subtree(cyclic_setup_attributes_root, ett_cyclic_setup_attribs);
while (offset < length) {
proto_tree_add_item(cyclic_setup_attributes, hf_ecmp_cyclic_setup_attrib, tvb, offset++, 1, ENC_BIG_ENDIAN);
}
}
break;
case 11:
case 12:
case 6:
add_cyclic_setup_attributes(pinfo, offset, length, tvb, ecmp_tree);
break;
default:
proto_tree_add_item(ecmp_tree, hf_ecmp_data, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_NA);
break;
}
}
}
static void program_status(int offset, gboolean request, tvbuff_t *tvb, proto_tree* ecmp_tree)
{
proto_item* ecmp_program_status_message_tree = NULL;
if (request) {
ecmp_program_status_message_tree = proto_tree_add_subtree(ecmp_tree, tvb, offset, 1, ett_ecmp_program_status_message, NULL, "Program Status: (Query)");
proto_tree_add_item(ecmp_program_status_message_tree, hf_ecmp_program_status_target, tvb, offset, 1, ENC_NA);
} else {
ecmp_program_status_message_tree = proto_tree_add_subtree(ecmp_tree, tvb, offset, 2, ett_ecmp_program_status_message, NULL, "Program Status: (Response)");
proto_tree_add_item(ecmp_program_status_message_tree, hf_ecmp_program_status_status, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(ecmp_program_status_message_tree, hf_ecmp_program_status_additional_items, tvb, offset, 1, ENC_NA);
}
}
static void program_control(int offset, gboolean request, tvbuff_t *tvb, proto_tree* ecmp_tree)
{
proto_item* ecmp_program_control_message_tree = NULL;
if (request) {
ecmp_program_control_message_tree = proto_tree_add_subtree(ecmp_tree, tvb, offset, 3, ett_ecmp_program_control_message, NULL, "Program Control: (Query)");
proto_tree_add_item(ecmp_program_control_message_tree, hf_ecmp_program_control_target, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(ecmp_program_control_message_tree, hf_ecmp_program_control_command, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(ecmp_program_control_message_tree, hf_ecmp_program_control_sub_command, tvb, offset, 1, ENC_NA);
} else {
ecmp_program_control_message_tree = proto_tree_add_subtree(ecmp_tree, tvb, offset, 1, ett_ecmp_program_control_message, NULL, "Program Control: (Response)");
proto_tree_add_item(ecmp_program_control_message_tree, hf_ecmp_program_control_status, tvb, offset, 1, ENC_NA);
}
}
static void modbus_pdu(int offset, gboolean request, tvbuff_t *tvb, packet_info* pinfo, proto_tree* ecmp_tree)
{
tvbuff_t* next_tvb;
guint16 size = 0;
int packet_type;
if (request) {
size = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(ecmp_tree, hf_ecmp_modbus_pdu_size, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
packet_type = QUERY_PACKET;
next_tvb = tvb_new_subset_length(tvb, offset, size);
call_dissector_with_data(modbus_handle, next_tvb, pinfo, ecmp_tree, &packet_type);
} else {
size = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(ecmp_tree, hf_ecmp_modbus_pdu_size, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
packet_type = RESPONSE_PACKET;
next_tvb = tvb_new_subset_length(tvb, offset, size);
call_dissector_with_data(modbus_handle, next_tvb, pinfo, ecmp_tree, &packet_type);
}
}
static void interrogate(packet_info* pinfo, int offset, gboolean request, tvbuff_t *tvb, proto_tree* ecmp_tree)
{
const guint8 interrogate_type_command = 0;
proto_tree* ecmp_interrogate_message_tree = NULL, *ecmp_interrogate_tree;
proto_item* ecmp_interrogate_message_item = NULL;
guint8 item_type = 0;
guint8 command_req = 0;
guint8 supported = 0;
guint32 count = 0;
guint32 j;
if (request) {
ecmp_interrogate_tree = proto_tree_add_subtree(ecmp_tree, tvb, offset, 2, ett_ecmp_interrogate_message, NULL, "Interrogate: (Query)");
item_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(ecmp_interrogate_tree, hf_ecmp_interrogate_item_type, tvb, offset, 1, ENC_NA);
offset += 1;
count = tvb_get_guint8(tvb, offset);
proto_tree_add_item(ecmp_interrogate_tree, hf_ecmp_interrogate_count, tvb, offset, 1, ENC_NA);
offset += 1;
ecmp_interrogate_message_tree = proto_tree_add_subtree(ecmp_interrogate_tree, tvb, offset, count, ett_ecmp_interrogate_message, &ecmp_interrogate_message_item, "ECMP Commands to be Checked");
if (item_type == interrogate_type_command) {
for (j = 0; j < count; j++) {
proto_tree_add_item(ecmp_interrogate_message_tree, hf_ecmp_interrogate_command, tvb, offset, 1, ENC_NA);
offset += 1;
}
proto_item_set_len(ecmp_interrogate_message_item, count);
} else {
expert_add_info(pinfo, ecmp_interrogate_message_item, &ei_ecmp_options_not_implemented);
}
} else {
ecmp_interrogate_tree = proto_tree_add_subtree(ecmp_tree, tvb, offset, 2, ett_ecmp_interrogate_message, NULL, "Interrogate: (Response)");
item_type = tvb_get_guint8(tvb, offset);
offset += 1;
count = tvb_get_guint8(tvb, offset);
offset += 1;
if (item_type == interrogate_type_command) {
ecmp_interrogate_message_tree = proto_tree_add_subtree(ecmp_interrogate_tree, tvb, offset, 1, ett_ecmp_interrogate_message, &ecmp_interrogate_message_item, "ECMP Commands Supported");
for (j = 0; j < count; j++) {
command_req = tvb_get_guint8(tvb, offset);
offset += 1;
supported = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_uint_format(ecmp_interrogate_message_tree, hf_ecmp_interrogate_command, tvb, offset, 1, command_req, "%s: %s",
try_val_to_str(command_req, command_vals),
try_val_to_str(supported, Interrogate_support_state));
}
} else {
expert_add_info(pinfo, ecmp_interrogate_message_item, &ei_ecmp_options_not_implemented);
}
}
}
static void tunnel_frame(int offset, gboolean request, tvbuff_t *tvb, proto_tree* ecmp_tree)
{
proto_tree_add_item(ecmp_tree, hf_ecmp_tunnel_control, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ecmp_tree, hf_ecmp_tunnel_start_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ecmp_tree, hf_ecmp_tunnel_end_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
if (request) {
proto_tree_add_item(ecmp_tree, hf_ecmp_tunnel_check_output_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset+= 1;
proto_tree_add_item(ecmp_tree, hf_ecmp_tunnel_size, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+= 2;
proto_tree_add_item(ecmp_tree, hf_ecmp_data, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_NA);
}
static int dissect_ecmp_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ecmp_item = NULL;
proto_item *ecmp_transaction_id_item = NULL;
proto_item *ecmp_chunk_id_item = NULL;
proto_tree *ecmp_tree = NULL;
guint8 command_value = 0;
gboolean request;
guint8 transaction_id_value = 0;
int offset = 0;
gint framelen = 0;
framelen = tvb_reported_length(tvb);
if (framelen < ecmp_min_packet_size) {
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTO_TAG_ECMP);
col_clear(pinfo->cinfo,COL_INFO);
offset = 4;
ecmp_item = proto_tree_add_item(tree, proto_ecmp, tvb, 0, -1, ENC_NA);
ecmp_tree = proto_item_add_subtree(ecmp_item, ett_ecmp);
offset = add_transport_layer_frame(offset, tvb, ecmp_tree, hf_ecmp_destination_address);
offset = add_transport_layer_frame(offset, tvb, ecmp_tree, hf_ecmp_source_address);
ecmp_transaction_id_item = proto_tree_add_item(ecmp_tree, hf_ecmp_transaction_id, tvb, offset, 1, ENC_BIG_ENDIAN );
transaction_id_value = tvb_get_guint8(tvb, offset);
if(transaction_id_value == 0) {
proto_item_append_text(ecmp_transaction_id_item, "%s", " -> Not initiated by Request");
}
offset++;
request = ((tvb_get_guint8(tvb, offset+2) & 0x80) == 0);
if (request) {
offset = get_response_size(offset, tvb, ecmp_tree);
offset = add_command_codes(pinfo, offset, tvb, ecmp_tree, transaction_id_value, &command_value);
offset = add_option_codes(offset, pinfo, tvb, ecmp_tree);
switch(command_value)
{
case ECMP_COMMAND_IDENTIFY:
add_attributes(pinfo, offset, tvb, ecmp_tree, request);
break;
case ECMP_COMMAND_INFO:
proto_tree_add_item(ecmp_tree, hf_ecmp_info_command, tvb, 0, -1, ENC_NA);
break;
case ECMP_COMMAND_INTERROGATE:
interrogate(pinfo, offset, request, tvb, ecmp_tree);
break;
case ECMP_COMMAND_READ:
get_parameter_definitions(pinfo, offset, command_value, tvb, ecmp_tree);
break;
case ECMP_COMMAND_READWITHTYPE:
get_parameter_definitions(pinfo, offset, command_value, tvb, ecmp_tree);
break;
case ECMP_COMMAND_WRITE:
get_parameter_definitions(pinfo, offset, command_value, tvb, ecmp_tree);
break;
case ECMP_COMMAND_OBJECTINFO:
get_parameter_definitions(pinfo, offset, command_value, tvb, ecmp_tree);
break;
case ECMP_COMMAND_GETNEXTOBJECTS:
get_parameter_definitions(pinfo, offset, command_value, tvb, ecmp_tree);
break;
case ECMP_COMMAND_FILEOPEN:
file_open(offset, request, tvb, ecmp_tree);
break;
case ECMP_COMMAND_FILEREAD:
file_read(offset, request, tvb, ecmp_tree);
break;
case ECMP_COMMAND_FILEWRITE:
file_write(offset, request, tvb, ecmp_tree);
break;
case ECMP_COMMAND_FILECLOSE:
file_close(offset, request, tvb, ecmp_tree);
break;
case ECMP_COMMAND_FILEINFO:
file_info(pinfo, offset, request, tvb, ecmp_tree);
break;
case ECMP_COMMAND_FILEDELETE:
file_state_delete(offset, request, tvb, ecmp_tree);
break;
case ECMP_COMMAND_FILESTATE:
file_state_delete(offset, request, tvb, ecmp_tree);
break;
case ECMP_COMMAND_FILEPOS:
file_pos(offset, request, tvb, ecmp_tree);
break;
case ECMP_COMMAND_FILELIST:
file_list(pinfo, offset, request, tvb, ecmp_tree);
break;
case ECMP_COMMAND_FILEEXISTS:
file_exists(offset, request, tvb, ecmp_tree);
break;
case ECMP_COMMAND_CYCLICLINK:
cyclic_setup(pinfo, offset, request, tvb, ecmp_tree);
break;
case ECMP_COMMAND_PROGRAMCONTROL:
program_control(offset, request, tvb, ecmp_tree);
break;
case ECMP_COMMAND_PROGRAMSTATUS:
program_status(offset, request, tvb, ecmp_tree);
break;
case ECMP_COMMAND_CYCLICFRAME:
add_cyclic_frame_query(offset, tvb, ecmp_tree);
break;
case ECMP_COMMAND_TUNNELFRAME:
tunnel_frame(offset, command_value, tvb, ecmp_tree);
break;
case ECMP_COMMAND_MODBUSPDU:
modbus_pdu(offset, request, tvb, pinfo, ecmp_tree);
break;
default:
proto_tree_add_expert(ecmp_tree, pinfo, &ei_ecmp_unknown_command, tvb, 0, -1);
break;
}
} else {
guint8 chunk_id_value = 0;
gint8 status_value = 0;
status_value = (gint8)tvb_get_guint8(tvb, offset);
proto_tree_add_item(ecmp_tree, hf_ecmp_status, tvb, offset, 1, ENC_BIG_ENDIAN);
if (status_value >= 0) {
offset++;
chunk_id_value = tvb_get_guint8(tvb, offset);
ecmp_chunk_id_item = proto_tree_add_item(ecmp_tree, hf_ecmp_chunk_id, tvb, offset, 1, ENC_BIG_ENDIAN);
if(chunk_id_value == 0) {
proto_item_append_text(ecmp_chunk_id_item, "%s", " -> Response is NOT Chunked");
}
offset++;
offset = add_command_codes(pinfo, offset, tvb, ecmp_tree, transaction_id_value, &command_value);
if ((status_value == 0) || (status_value == 1)) {
offset = add_option_codes(offset, pinfo, tvb, ecmp_tree);
switch(command_value)
{
case ECMP_COMMAND_IDENTIFY:
offset = add_category_codes(offset, tvb, ecmp_tree);
add_attributes(pinfo, offset, tvb, ecmp_tree, request);
break;
case ECMP_COMMAND_INFO:
add_info_response(offset, tvb, ecmp_tree);
break;
case ECMP_COMMAND_INTERROGATE:
interrogate(pinfo, offset, request, tvb, ecmp_tree);
break;
case ECMP_COMMAND_READ:
get_parameter_responses(pinfo, offset, command_value, tvb, ecmp_tree);
break;
case ECMP_COMMAND_READWITHTYPE:
get_parameter_responses(pinfo, offset, command_value, tvb, ecmp_tree);
break;
case ECMP_COMMAND_WRITE:
get_parameter_responses(pinfo, offset, command_value, tvb, ecmp_tree);
break;
case ECMP_COMMAND_OBJECTINFO:
get_object_info_response(pinfo, offset, tvb, ecmp_tree);
break;
case ECMP_COMMAND_GETNEXTOBJECTS:
get_parameter_responses(pinfo, offset, command_value, tvb, ecmp_tree);
break;
case ECMP_COMMAND_FILEOPEN:
file_open(offset, request, tvb, ecmp_tree);
break;
case ECMP_COMMAND_FILEREAD:
file_read(offset, request, tvb, ecmp_tree);
break;
case ECMP_COMMAND_FILEWRITE:
file_write(offset, request, tvb, ecmp_tree);
break;
case ECMP_COMMAND_FILECLOSE:
file_close(offset, request, tvb, ecmp_tree);
break;
case ECMP_COMMAND_FILEINFO:
file_info(pinfo, offset, request, tvb, ecmp_tree);
break;
case ECMP_COMMAND_FILEDELETE:
file_state_delete(offset, request, tvb, ecmp_tree);
break;
case ECMP_COMMAND_FILESTATE:
file_state_delete(offset, request, tvb, ecmp_tree);
break;
case ECMP_COMMAND_FILEPOS:
file_pos(offset, request, tvb, ecmp_tree);
break;
case ECMP_COMMAND_FILELIST:
file_list(pinfo, offset, request, tvb, ecmp_tree);
break;
case ECMP_COMMAND_FILEEXISTS:
file_exists(offset, request, tvb, ecmp_tree);
break;
case ECMP_COMMAND_CYCLICLINK:
cyclic_setup(pinfo, offset, request, tvb, ecmp_tree);
break;
case ECMP_COMMAND_PROGRAMCONTROL:
program_control(offset, request, tvb, ecmp_tree);
break;
case ECMP_COMMAND_PROGRAMSTATUS:
program_status(offset, request, tvb, ecmp_tree);
break;
case ECMP_COMMAND_CYCLICFRAME:
add_cyclic_frame(offset, tvb, ecmp_tree);
break;
case ECMP_COMMAND_TUNNELFRAME:
tunnel_frame(offset, command_value, tvb, ecmp_tree);
break;
case ECMP_COMMAND_MODBUSPDU:
modbus_pdu(offset, request, tvb, pinfo, ecmp_tree);
break;
default:
proto_tree_add_expert(ecmp_tree, pinfo, &ei_ecmp_unknown_command, tvb, 0, -1);
break;
}
}
}
}
return framelen;
}
static int dissect_ecmp_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ecmp_item = NULL;
proto_tree *ecmp_tree = NULL;
proto_tree *ecmp_cyclic_data_32_bit_display_tree = NULL;
proto_tree *ecmp_cyclic_data_16_bit_display_tree = NULL;
proto_tree *ecmp_cyclic_data_8_bit_display_tree = NULL;
guint8 command_value = 0;
guint8 type_value = 0;
guint8 transaction_id_value = 0;
guint16 offset = 0;
gint framelen = 0;
guint8 scheme = 0;
framelen = tvb_reported_length(tvb);
if (framelen < ecmp_min_packet_size) {
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTO_TAG_ECMP);
col_clear(pinfo->cinfo,COL_INFO);
offset += 2;
transaction_id_value = tvb_get_guint8(tvb, offset);
offset += 3;
type_value = tvb_get_guint8(tvb, offset);
command_value = type_value & 0x7f;
offset += 2;
col_add_fstr(pinfo->cinfo, COL_INFO, "%s, %s. Transaction ID: %d",
val_to_str(command_value, command_vals, "Unknown Type:0x%02x"),
val_to_str((type_value & 0x80) >> 7, type_rr, "Unknown Type:0x%02x"), transaction_id_value);
ecmp_item = proto_tree_add_item(tree, proto_ecmp, tvb, 0, -1, ENC_NA);
ecmp_tree = proto_item_add_subtree(ecmp_item, ett_ecmp);
proto_tree_add_item(ecmp_tree, hf_ecmp_cyclic_link_req_resp, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ecmp_tree, hf_ecmp_cyclic_link_number_display, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (type_value & 0x80) {
proto_tree_add_item(ecmp_tree, hf_ecmp_udp_alignment, tvb, offset, 1, ENC_NA);
offset += 1;
scheme = tvb_get_guint8(tvb, offset);
proto_tree_add_item(ecmp_tree, hf_ecmp_udp_scheme, tvb, offset, 1, ENC_NA);
offset += 1;
if (scheme == 1) {
proto_tree_add_item(ecmp_tree, hf_ecmp_grandmaster, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(ecmp_tree, hf_ecmp_process_time, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
}
ecmp_cyclic_data_32_bit_display_tree = proto_tree_add_subtree(ecmp_tree, tvb, offset, 2, ett_ecmp_cyclic_data_32_bit_display, NULL,
"Cyclic Data (32-bit hex unsigned format): ");
display_raw_cyclic_data(cyclic_display_long_format, offset, framelen - offset, tvb, ecmp_cyclic_data_32_bit_display_tree);
ecmp_cyclic_data_16_bit_display_tree = proto_tree_add_subtree(ecmp_tree, tvb, offset, 2, ett_ecmp_cyclic_data_16_bit_display, NULL,
"Cyclic Data (16-bit hex unsigned format): ");
display_raw_cyclic_data(cyclic_display_word_format, offset, framelen - offset, tvb, ecmp_cyclic_data_16_bit_display_tree);
ecmp_cyclic_data_8_bit_display_tree = proto_tree_add_subtree(ecmp_tree, tvb, offset, 2, ett_ecmp_cyclic_data_8_bit_display, NULL,
"Cyclic Data (8-bit hex unsigned format): ");
display_raw_cyclic_data(cyclic_display_byte_format, offset, framelen - offset, tvb, ecmp_cyclic_data_8_bit_display_tree);
}
return tvb_reported_length(tvb);
}
void proto_register_ecmp (void)
{
static hf_register_info hf[] = {
{ &hf_ecmp_destination_address,
{ "Destination Address scheme", "ecmp.destination_address", FT_UINT8, BASE_DEC, VALS(address_scheme), 0, NULL, HFILL }},
{ &hf_ecmp_source_address,
{ "Source Address scheme", "ecmp.source_address", FT_UINT8, BASE_DEC, VALS(address_scheme), 0, NULL, HFILL }},
{ &hf_ecmp_diagnostic,
{ "Diagnostic group", "ecmp.diagnostic", FT_UINT8, BASE_DEC, VALS(diagnostic), 0, NULL, HFILL }},
{ &hf_ecmp_command,
{ "Command", "ecmp.command", FT_UINT8, BASE_DEC, VALS(command_vals), 0x7F, NULL, HFILL }},
{ &hf_ecmp_option,
{ "Option", "ecmp.option", FT_UINT8, BASE_DEC, VALS(option_code), 0x0, NULL, HFILL }},
{ &hf_ecmp_type_rr,
{ "Type", "ecmp.type", FT_UINT8, BASE_DEC, VALS(type_rr), 0x80, "ECMP Type (request/response)", HFILL }},
{ &hf_ecmp_chunking,
{ "Chunks allowed","ecmp.chunking", FT_UINT16, BASE_DEC, NULL,0xF000, "ECMP number of chunks allowed", HFILL}},
{ &hf_ecmp_max_response_size,
{ "Maximum Response Size","ecmp.response_size", FT_UINT16, BASE_DEC, NULL,0x0FFF, NULL, HFILL}},
{ &hf_ecmp_category,
{ "Device", "ecmp.category", FT_UINT8, BASE_DEC, VALS(category), 0x0, "ECMP Category (drive or option module)", HFILL }},
{ &hf_ecmp_attribute,
{ "Attribute", "ecmp.attribute", FT_UINT8, BASE_DEC, VALS(attribute), 0x0, NULL, HFILL }},
{ &hf_ecmp_no_of_attributes,
{ "Number of attributes", "ecmp.attribute_number", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_status,
{ "Status", "ecmp.status", FT_INT8, BASE_DEC, VALS(status), 0x0, NULL, HFILL }},
{ &hf_ecmp_chunk_id,
{ "Chunk ID", "ecmp.chunkID", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_transaction_id,
{ "Transaction ID", "ecmp.transactionID", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_drive_type,
{ "Product Type", "ecmp.drive_type", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_drive_derivative,
{ "Drive Derivative", "ecmp.drive_derivative", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_drive_factory_fit_category_id,
{ "Factory Fitted Option ID", "ecmp.drive_factory_fit_category_id", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_category_id,
{ "Option ID", "ecmp.category_id", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_cyclic_link_num,
{ "Cyclic Link Number", "ecmp.link_num", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_cyclic_align,
{ "Alignment", "ecmp.cyclic_align", FT_UINT8, BASE_DEC, VALS(cyclic_align), 0x0, "ECMP Cyclic Data Alignment", HFILL }},
{ &hf_ecmp_cyclic_scheme,
{ "Scheme", "ecmp.cyclic_scheme", FT_UINT8, BASE_DEC, VALS(cyclic_scheme), 0x0, "ECMP Cyclic Scheme", HFILL }},
{ &hf_ecmp_cyclic_link_number_display,
{ "Cyclic Link Number Display", "ecmp.link_num_display", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_buffer_size,
{"Buffer Size", "ecmp.buffer_size", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_ecmp_max_response,
{"Maximum Response Time", "ecmp.max_response", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_ecmp_max_handle,
{"Maximum Handle Period", "ecmp.max_handle", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_ecmp_info_address,
{"Number of Default Route Addresses", "ecmp.count", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_ecmp_parameter_address,
{"Parameter Addressing Scheme", "ecmp.parameter.address", FT_UINT8, BASE_DEC, VALS(parameter_address_scheme), 0x0, NULL, HFILL}},
{ &hf_ecmp_number_of_parameter_definitions,
{"Number of Parameter Definitions", "ecmp.parameter.definitions", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_ecmp_number_of_parameter_responses,
{"Number of Parameter Responses", "ecmp.parameter.response", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_ecmp_parameter_status,
{"Parameter Status", "ecmp.parameter.status", FT_INT8, BASE_DEC, VALS(parameter_access_status), 0x0, NULL, HFILL}},
{ &hf_ecmp_data_type,
{"Parameter Data Type", "ecmp.parameter.data_type", FT_UINT8, BASE_DEC, VALS(parameter_data_types), 0x0, NULL, HFILL}},
{ &hf_ecmp_info_type,
{"Info Type", "ecmp.info_type", FT_UINT8, BASE_DEC, VALS(info_type), 0x0, NULL, HFILL}},
{ &hf_ecmp_file_status,
{"File Status", "ecmp.file.status", FT_INT8, BASE_DEC, VALS(file_status), 0x0, NULL, HFILL}},
{ &hf_ecmp_file_handle,
{"File Handle", "ecmp.file.handle", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_ecmp_file_attributes,
{"Attribute", "ecmp.file.attribute", FT_UINT8, BASE_DEC, VALS(file_attributes), 0x0, "File attributes", HFILL}},
{ &hf_ecmp_file_ref_point,
{"Reference Point", "ecmp.file.reference", FT_UINT8, BASE_DEC, VALS(file_ref_point), 0x0, "File reference points", HFILL}},
{ &hf_ecmp_tunnel_control,
{"Control", "ecmp.tunnel_control", FT_UINT8, BASE_DEC, NULL, 0x0, "Tunnel frame control field", HFILL}},
{ &hf_ecmp_tunnel_start_flag,
{"Start", "ecmp.tunnel_control.start", FT_BOOLEAN, 8, NULL, TUNNEL_START_FLAG, "Tunnel frame control field start flag", HFILL}},
{ &hf_ecmp_tunnel_end_flag,
{"End", "ecmp.tunnel_control.end", FT_BOOLEAN, 8, NULL, TUNNEL_END_FLAG, "Tunnel frame control field end flag", HFILL}},
{ &hf_ecmp_tunnel_check_output_flag,
{"Check Output", "ecmp.tunnel_control.check", FT_BOOLEAN, 8, NULL, TUNNEL_CHECK_OUTPUT_FLAG, "Tunnel frame control field check output flag", HFILL}},
{ &hf_ecmp_tunnel_size,
{"Size", "ecmp.tunnel_size", FT_UINT16, BASE_DEC, NULL, 0x0, "Tunnel frame payload size", HFILL}},
{ &hf_ecmp_cyclic_setup_mode,
{"Mode", "ecmp.cyclic_setup.mode", FT_UINT8, BASE_DEC, VALS(cyclic_setup_mode), 0x0, "Cyclic setup mode", HFILL}},
{ &hf_ecmp_cyclic_setup_linkno,
{"Link No", "ecmp.cyclic_setup.linkno", FT_UINT8, BASE_DEC, NULL, 0x0, "Cyclic setup link no", HFILL}},
{ &hf_ecmp_cyclic_setup_dir,
{"Direction", "ecmp.cyclic_setup.direction", FT_UINT8, BASE_DEC, VALS(cyclic_setup_link_dir), 0x0, "Cyclic setup link direction", HFILL}},
{ &hf_ecmp_cyclic_setup_attrib_count,
{"Count", "ecmp.cyclic_setup.attrib_count", FT_UINT8, BASE_DEC, NULL, 0x0, "Cyclic setup attribute count", HFILL}},
{ &hf_ecmp_cyclic_setup_attrib,
{"Attribute", "ecmp.cyclic_setup.attrib", FT_UINT8, BASE_DEC, VALS(cyclic_attributes), 0x0, "Cyclic setup attribute", HFILL}},
{ &hf_ecmp_cyclic_setup_rsp_status,
{"Status", "ecmp.cyclic_setup.rsp_status", FT_INT8, BASE_DEC, NULL, 0x0, "Cyclic setup status", HFILL}},
{ &hf_ecmp_cyclic_setup_rsp_err_idx,
{"Error Index", "ecmp.cyclic_setup.rsp_err_idx", FT_UINT8, BASE_DEC, NULL, 0x0, "Cyclic setup error index", HFILL}},
{ &hf_ecmp_cyclic_setup_link_exists,
{"Existence State", "ecmp.cyclic_setup.exists.state", FT_UINT8, BASE_DEC, VALS(cyclic_setup_link_exists), 0x0, "Cyclic setup exists state", HFILL}},
{ &hf_ecmp_cyclic_link_req_resp,
{"Cyclic Link - Request-Response", "ecmp.cyclic_link.request.response", FT_UINT8, BASE_DEC, VALS(cyclic_link_req_resp), 0x0, "Cyclic link request - response", HFILL}},
{ &hf_ecmp_attribute_string,
{ "Attribute string", "ecmp.attribute_string", FT_UINT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_file_name,
{ "File name", "ecmp.file_name", FT_UINT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_directory,
{ "Directory", "ecmp.directory", FT_UINT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_names_scheme,
{ "Names Scheme", "ecmp.names_scheme", FT_UINT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_variable_name,
{ "Variable name", "ecmp.variable_name", FT_UINT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_unit_id_string,
{ "Unit ID String", "ecmp.unit_id_string", FT_UINT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_ecmp_string,
{ "ECMP string", "ecmp.ecmp_string", FT_UINT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_info_command,
{ "Info command data", "ecmp.info_command", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_process_time,
{ "ProcessAt time", "ecmp.processat_time", FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_cyclic_frame_time,
{ "Cyclic frame time", "ecmp.cyclic_frame_time", FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_grandmaster,
{ "Grandmaster", "ecmp.grandmaster", FT_EUI64, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_data,
{ "Data", "ecmp.data", FT_BYTES, SEP_SPACE, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_response_data,
{ "Response Data", "ecmp.response_data", FT_BYTES, SEP_SPACE, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_physical_address, { "Physical address", "ecmp.physical_address", FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }},
{ &hf_ecmp_logical_address, { "Logical address", "ecmp.logical_address", FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL }},
{ &hf_ecmp_primary_colour, { "Primary Colour", "ecmp.primary_colour", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_secondary_colour, { "Secondary Colour", "ecmp.secondary_colour", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_number_of_subsequent_object_requests, { "Number of subsequent object requests", "ecmp.number_of_subsequent_object_requests", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_number_of_decimal_places, { "Number of decimal places", "ecmp.number_of_decimal_places", FT_INT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_no_information_available, { "No Information available", "ecmp.no_information_available", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_param_format_bit_default_unipolar, { "BU- Bit default/Unipolar", "ecmp.param_format.bit_default_unipolar", FT_UINT32, BASE_DEC, NULL, 0x00000001, NULL, HFILL }},
{ &hf_ecmp_param_format_write_allowed, { "W- Write allowed", "ecmp.param_format.write_allowed", FT_UINT32, BASE_DEC, NULL, 0x00000002, NULL, HFILL }},
{ &hf_ecmp_param_format_read_not_allowed, { "NR- Read not allowed", "ecmp.param_format.read_not_allowed", FT_UINT32, BASE_DEC, NULL, 0x00000004, NULL, HFILL }},
{ &hf_ecmp_param_format_protected_from_destinations, { "PT- Protected from destinations", "ecmp.param_format.protected_from_destinations", FT_UINT32, BASE_DEC, NULL, 0x00000008, NULL, HFILL }},
{ &hf_ecmp_param_format_parameter_not_visible, { "NV- Parameter not visible", "ecmp.param_format.parameter_not_visible", FT_UINT32, BASE_DEC, NULL, 0x00000010, NULL, HFILL }},
{ &hf_ecmp_param_format_not_clonable, { "NC- Not clonable", "ecmp.param_format.not_clonable", FT_UINT32, BASE_DEC, NULL, 0x00000020, NULL, HFILL }},
{ &hf_ecmp_param_format_voltage_or_current_rating_dependant, { "RA- Voltage or current rating dependant", "ecmp.param_format.voltage_or_current_rating_dependant", FT_UINT32, BASE_DEC, NULL, 0x00000040, NULL, HFILL }},
{ &hf_ecmp_param_format_parameter_has_no_default, { "ND- Parameter has no default", "ecmp.param_format.parameter_has_no_default", FT_UINT32, BASE_DEC, NULL, 0x00000080, NULL, HFILL }},
{ &hf_ecmp_param_format_number_of_decimal_places, { "DP- Number of Decimal places", "ecmp.param_format.number_of_decimal_places", FT_UINT32, BASE_DEC, NULL, 0x00000F00, NULL, HFILL }},
{ &hf_ecmp_param_format_variable_maximum_and_minimum, { "VM- Variable maximum and minimum", "ecmp.param_format.variable_maximum_and_minimum", FT_UINT32, BASE_DEC, NULL, 0x00001000, NULL, HFILL }},
{ &hf_ecmp_param_format_string_parameter, { "TE- String parameter", "ecmp.param_format.string_parameter", FT_UINT32, BASE_DEC, NULL, 0x00002000, NULL, HFILL }},
{ &hf_ecmp_param_format_desitination_set_up_parameter, { "DE- Desitination set-up parameter", "ecmp.param_format.desitination_set_up_parameter", FT_UINT32, BASE_DEC, NULL, 0x00004000, NULL, HFILL }},
{ &hf_ecmp_param_format_filtered_when_displayed, { "FI- Filtered when displayed", "ecmp.param_format.filtered_when_displayed", FT_UINT32, BASE_DEC, NULL, 0x00008000, NULL, HFILL }},
{ &hf_ecmp_param_format_pseudo_read_only, { "PR- Pseudo read only", "ecmp.param_format.pseudo_read_only", FT_UINT32, BASE_DEC, NULL, 0x00010000, NULL, HFILL }},
{ &hf_ecmp_param_format_display_format, { "DF- Display Format", "ecmp.param_format.display_format", FT_UINT32, BASE_DEC, VALS(display_format), 0x001E0000, NULL, HFILL }},
{ &hf_ecmp_param_format_floating_point_value, { "FL- Floating point value", "ecmp.param_format.floating_point_value", FT_UINT32, BASE_DEC, NULL, 0x00200000, NULL, HFILL }},
{ &hf_ecmp_param_format_units, { "UNITS", "ecmp.param_format.units", FT_UINT32, BASE_DEC, VALS(format_units), 0x0FC00000, NULL, HFILL }},
{ &hf_ecmp_string_id, { "String ID", "ecmp.string_id", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_address_scheme_menu, { "Menu", "ecmp.address_scheme.menu", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_address_scheme_parameter, { "Parameter", "ecmp.address_scheme.parameter", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_address_scheme_slot, { "Slot", "ecmp.address_scheme.slot", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_address_scheme_null_byte_size, { "NULL byte size", "ecmp.address_scheme.null_byte_size", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_display_unit_id, { "Unit ID", "ecmp.display_unit_id", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_data_boolean, { "Data", "ecmp.data.boolean", FT_UINT8, BASE_DEC, NULL, 0x01, NULL, HFILL }},
{ &hf_ecmp_data_int8, { "Data", "ecmp.data.int8", FT_INT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_data_uint8, { "Data", "ecmp.data.uint8", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_data_int16, { "Data", "ecmp.data.int16", FT_INT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_data_uint16, { "Data", "ecmp.data.uint16", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_data_int32, { "Data", "ecmp.data.int32", FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_data_uint32, { "Data", "ecmp.data.uint32", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_data_int64, { "Data", "ecmp.data.int64", FT_INT64, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_data_uint64, { "Data", "ecmp.data.uint64", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_data_float, { "Data", "ecmp.data.float", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_data_double, { "Data", "ecmp.data.double", FT_DOUBLE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_access_mode, { "Access Mode", "ecmp.access_mode", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_open_in_non_blocking_mode, { "Open in non-blocking mode", "ecmp.open_in_non_blocking_mode", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_ecmp_open_file_relative_to_specified_directory_handle, { "Open file relative to specified directory handle", "ecmp.open_file_relative_to_specified_directory_handle", FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }},
{ &hf_ecmp_file_access_mode, { "File Access Mode", "ecmp.file_access_mode", FT_UINT8, BASE_DEC, VALS(file_status_mode), 0x0F, NULL, HFILL }},
{ &hf_ecmp_additional_scheme, { "Additional Scheme", "ecmp.additional_scheme", FT_UINT8, BASE_DEC, VALS(additional_scheme_vals), 0x0, NULL, HFILL }},
{ &hf_ecmp_scheme_data_length, { "Length", "ecmp.scheme_data_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_number_of_requested_bytes, { "Number of requested bytes", "ecmp.number_of_requested_bytes", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_number_of_bytes_transferred, { "Number of bytes transferred", "ecmp.number_of_bytes_transferred", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_crc, { "CRC", "ecmp.crc", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_ref_offset, { "Offset", "ecmp.ref_offset", FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_number_of_files_to_list, { "Number of files to list", "ecmp.number_of_files_to_list", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_file_hash, { "Hash", "ecmp.file_hash", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_item_type, { "Item type", "ecmp.item_type", FT_UINT8, BASE_DEC, VALS(item_type_vals), 0x0, NULL, HFILL }},
{ &hf_ecmp_file_integrity, { "File Integrity", "ecmp.file_integrity", FT_UINT8, BASE_DEC, VALS(file_integrity_vals), 0x01, NULL, HFILL }},
{ &hf_ecmp_display_attr_read_only, { "Read Only", "ecmp.display_attr.read_only", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_ecmp_display_attr_hidden, { "Hidden", "ecmp.display_attr.hidden", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_ecmp_display_attr_system, { "System", "ecmp.display_attr.system", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_ecmp_display_attr_volume_label, { "Volume Label", "ecmp.display_attr.volume_label", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_ecmp_display_attr_subdirectory, { "Subdirectory", "ecmp.display_attr.subdirectory", FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }},
{ &hf_ecmp_display_attr_archive, { "Archive", "ecmp.display_attr.archive", FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL }},
{ &hf_ecmp_display_creation, { "Display creation", "ecmp.display_creation", FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_display_modification, { "Display modification", "ecmp.display_modification", FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_interrogate_item_type, { "Item Type", "ecmp.interrogate_item_type", FT_UINT8, BASE_DEC, VALS(Interrogate_command_option_state), 0x0, NULL, HFILL }},
{ &hf_ecmp_interrogate_count, { "Count", "ecmp.interrogate_count", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_modbus_pdu_size, { "Size", "ecmp.modbus_pdu_size", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
#if 0
{ &hf_ecmp_destination_scheme, { "Destination Scheme", "ecmp.destination_scheme", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
#endif
{ &hf_ecmp_program_control_target, { "Target", "ecmp.program_control_target", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_program_control_command, { "Command", "ecmp.program_control_command", FT_UINT8, BASE_DEC, VALS(command_code_list), 0x0, NULL, HFILL }},
{ &hf_ecmp_program_control_sub_command, { "Sub-Command", "ecmp.program_control_sub_command", FT_UINT8, BASE_DEC, VALS(sub_command_code_list), 0x0, NULL, HFILL }},
{ &hf_ecmp_program_control_status, { "Status", "ecmp.program_control_status", FT_UINT8, BASE_DEC, VALS(status_list), 0x0, NULL, HFILL }},
{ &hf_ecmp_program_status_target, { "Target", "ecmp.program_status_target", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_program_status_status, { "Status", "ecmp.program_status_status", FT_UINT8, BASE_DEC, VALS(running_state_list), 0x0, NULL, HFILL }},
{ &hf_ecmp_program_status_additional_items, { "Additional Items", "ecmp.program_status_additional_items", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_cyclic_setup_max_mappings, { "Max Mappings", "ecmp.cyclic_setup.max_mappings", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_cyclic_setup_start_offset, { "Start Offset", "ecmp.cyclic_setup.start_offset", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_cyclic_setup_tx_count, { "Tx Count", "ecmp.cyclic_setup.tx_count", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_cyclic_setup_rx_count, { "Rx Count", "ecmp.cyclic_setup.rx_count", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_udp_alignment, { "Alignment", "ecmp.udp_alignment", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_udp_scheme, { "Scheme", "ecmp.udp_scheme", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_cyclic_data, { "Cyclic Data", "ecmp.cyclic_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_version_summary, { "Version summary", "ecmp.version_summary", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_min_param_menu, { "Min parameter in menu", "ecmp.min_param_menu", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_max_param_menu, { "Max parameter in menu", "ecmp.max_param_menu", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_file_length, { "File length", "ecmp.file_length", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_mec_offset, { "mec_offset", "ecmp.mec_offset", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_sample_period, { "Sample period", "ecmp.sample_period", FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_rx_timeout, { "RX Timeout", "ecmp.rx_timeout", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_rx_action, { "Action", "ecmp.rx_action", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_rx_event_destination, { "Event Destination", "ecmp.rx_event_destination", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_rx_event, { "Event", "ecmp.rx_event", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_rx_late_handler_action, { "Action", "ecmp.rx_late_handler_action", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_rx_late_handler_event_destination, { "Event Destination", "ecmp.rx_late_handler_event_destination", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_rx_late_handler_event, { "Event", "ecmp.rx_late_handler_event", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_transport_addr_scheme, { "Scheme", "ecmp.transport_addr_scheme", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_transport_addr, { "Transport address", "ecmp.transport_addr", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_mapping_item_offset, { "Offset", "ecmp.mapping_item_offset", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_mapping_item_scheme, { "Scheme", "ecmp.mapping_item_scheme", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_setup_attribute, { "Attribute", "ecmp.setup_attribute", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_mec_period, { "mec period", "ecmp.mec_period", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ecmp_interrogate_command, { "Command", "ecmp.interrogate_command", FT_UINT8, BASE_DEC, VALS(command_vals), 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_ecmp,
&ett_ecmp_address,
&ett_ecmp_response_size,
&ett_ecmp_command,
&ett_ecmp_category,
&ett_ecmp_option,
&ett_ecmp_option_data,
&ett_ecmp_attribute,
&ett_ecmp_attribute_data,
&ett_ecmp_cyclic_scheme,
&ett_ecmp_interrogate_message,
&ett_ecmp_info_type,
&ett_ecmp_info_count,
&ett_ecmp_param_address,
&ett_ecmp_access_mode,
&ett_ecmp_access_file,
&ett_ecmp_file_read,
&ett_ecmp_file_write,
&ett_ecmp_file_info,
&ett_ecmp_file_info_att,
&ett_ecmp_file_position,
&ett_ecmp_file_list_no,
&ett_ecmp_file_list,
&ett_ecmp_tunnel_3s_goodframe,
&ett_ecmp_tunnel_3s_size,
&ett_ecmp_tunnel_3s_service,
&ett_cyclic_setup_attribs,
&ett_cyclic_setup_transport_addr,
&ett_cyclic_setup_attrib_item,
&ett_ecmp_cyclic_data_32_bit_display,
&ett_ecmp_cyclic_data_16_bit_display,
&ett_ecmp_cyclic_data_8_bit_display,
&ett_ecmp_modbus_pdu_message,
&ett_ecmp_program_control_message,
&ett_ecmp_program_status_message
};
static ei_register_info ei[] = {
{ &ei_ecmp_unknown_command, { "ecmp.unknown_command", PI_PROTOCOL, PI_WARN, "Unknown Command", EXPFILL }},
{ &ei_ecmp_color, { "ecmp.color_invalid", PI_PROTOCOL, PI_WARN, "Invalid color data value", EXPFILL }},
{ &ei_ecmp_option, { "ecmp.ecmp_option.unknown", PI_PROTOCOL, PI_WARN, "ERROR - Unrecognised Option Code", EXPFILL }},
{ &ei_ecmp_data_type, { "ecmp.data_type.unknown", PI_PROTOCOL, PI_WARN, "Unknown Data Type", EXPFILL }},
{ &ei_ecmp_parameter_addressing_scheme, { "ecmp.incorrect_parameter_addressing_scheme", PI_PROTOCOL, PI_WARN, "Incorrect parameter addressing scheme", EXPFILL }},
{ &ei_ecmp_info_type, { "ecmp.info_type.unknown", PI_PROTOCOL, PI_WARN, "Unknown info type", EXPFILL }},
{ &ei_ecmp_attribute_type, { "ecmp.attribute_type.unknown", PI_PROTOCOL, PI_WARN, "Wrong attribute type", EXPFILL }},
{ &ei_ecmp_item_type, { "ecmp.item_type.unknown", PI_PROTOCOL, PI_WARN, "Unknown item type", EXPFILL }},
{ &ei_ecmp_options_not_implemented, { "ecmp.options_not_implemented", PI_UNDECODED, PI_WARN, "ECMP Options Not Implemented", EXPFILL }}
};
expert_module_t* expert_ecmp;
proto_ecmp = proto_register_protocol ("ECMP", PROTO_TAG_ECMP, "ecmp");
proto_register_field_array(proto_ecmp, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
expert_ecmp = expert_register_protocol(proto_ecmp);
expert_register_field_array(expert_ecmp, ei, array_length(ei));
}
void proto_reg_handoff_ecmp(void)
{
static gboolean initialized = FALSE;
static dissector_handle_t ecmp_tcp_handle, ecmp_udp_handle;
if (!initialized) {
ecmp_tcp_handle = create_dissector_handle(dissect_ecmp_tcp, proto_ecmp);
ecmp_udp_handle = create_dissector_handle(dissect_ecmp_udp, proto_ecmp);
dissector_add_uint("udp.port", global_ecmp_port, ecmp_udp_handle);
dissector_add_uint("tcp.port", global_ecmp_port, ecmp_tcp_handle);
initialized = TRUE;
}
modbus_handle = find_dissector_add_dependency("modbus", proto_ecmp);
proto_modbus = proto_get_id_by_filter_name( "modbus" );
}
