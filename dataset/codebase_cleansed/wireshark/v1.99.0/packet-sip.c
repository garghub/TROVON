static gint sip_equal(gconstpointer v, gconstpointer v2)
{
const sip_hash_key* val1 = (const sip_hash_key*)v;
const sip_hash_key* val2 = (const sip_hash_key*)v2;
if (strcmp(val1->call_id, val2->call_id) != 0)
{
return 0;
}
return (ADDRESSES_EQUAL(&(val1->source_address), &(val2->source_address))) &&
(val1->source_port == val2->source_port) &&
(ADDRESSES_EQUAL(&(val1->dest_address), &(val2->dest_address))) &&
(val1->dest_port == val2->dest_port);
}
static void
sip_init_protocol(void)
{
guint i;
gchar *value_copy;
if (sip_hash)
g_hash_table_destroy(sip_hash);
sip_hash = g_hash_table_new(g_str_hash , sip_equal);
if(!sip_headers_hash){
sip_headers_hash = g_hash_table_new(g_str_hash , g_str_equal);
for (i = 1; i < array_length(sip_headers); i++){
value_copy = g_strdup (sip_headers[i].name);
ascii_strdown_inplace(value_copy);
g_hash_table_insert(sip_headers_hash, (gpointer)value_copy, GINT_TO_POINTER(i));
}
}
}
static void
export_sip_pdu(packet_info *pinfo, tvbuff_t *tvb)
{
exp_pdu_data_t *exp_pdu_data;
guint8 tags_bit_field;
tags_bit_field = EXP_PDU_TAG_IP_SRC_BIT + EXP_PDU_TAG_IP_DST_BIT + EXP_PDU_TAG_SRC_PORT_BIT+
EXP_PDU_TAG_DST_PORT_BIT + EXP_PDU_TAG_ORIG_FNO_BIT;
exp_pdu_data = load_export_pdu_tags(pinfo, "sip", -1, &tags_bit_field, 1);
exp_pdu_data->tvb_captured_length = tvb_captured_length(tvb);
exp_pdu_data->tvb_reported_length = tvb_reported_length(tvb);
exp_pdu_data->pdu_tvb = tvb;
tap_queue_packet(exported_pdu_tap, pinfo, exp_pdu_data);
}
static void
sip_uri_offset_init(uri_offset_info *uri_offsets){
uri_offsets->display_name_start = -1;
uri_offsets->display_name_end = -1;
uri_offsets->uri_start = -1;
uri_offsets->uri_end = -1;
uri_offsets->uri_parameters_start = -1;
uri_offsets->uri_parameters_end = -1;
uri_offsets->name_addr_start = -1;
uri_offsets->name_addr_end = -1;
uri_offsets->uri_user_start = -1;
uri_offsets->uri_user_end = -1;
uri_offsets->uri_host_start = -1;
uri_offsets->uri_host_end = -1;
uri_offsets->uri_host_port_start = -1;
uri_offsets->uri_host_port_end = -1;
}
static gint
dissect_sip_uri(tvbuff_t *tvb, packet_info *pinfo _U_, gint start_offset,
gint line_end_offset, uri_offset_info *uri_offsets)
{
guchar c = '\0';
gint current_offset;
gint queried_offset;
gint parameter_end_offset;
gboolean in_ipv6 = FALSE;
current_offset = tvb_skip_wsp(tvb, start_offset, line_end_offset - start_offset);
if(current_offset >= line_end_offset) {
return -1;
}
uri_offsets->uri_start = current_offset;
if (tvb_strneql(tvb, current_offset, "sip", 3) != 0)
return -1;
if(uri_offsets->uri_end == -1)
{
int end_offset;
end_offset = tvb_pbrk_guint8(tvb, current_offset, line_end_offset - current_offset, ",;", NULL);
if (end_offset != -1)
{
uri_offsets->uri_end = end_offset - 1;
}
else
{
uri_offsets->uri_end = line_end_offset - 3;
}
uri_offsets->name_addr_end = uri_offsets->uri_end;
}
queried_offset = tvb_find_guint8(tvb, uri_offsets->uri_start, uri_offsets->uri_end - uri_offsets->uri_start, '@');
if(queried_offset == -1)
{
uri_offsets->uri_host_start = tvb_find_guint8(tvb, uri_offsets->uri_start, uri_offsets->uri_end - uri_offsets->uri_start, ':')+1;
}
else
{
uri_offsets->uri_user_start = tvb_find_guint8(tvb, uri_offsets->uri_start, uri_offsets->uri_end - uri_offsets->uri_start, ':')+1;
uri_offsets->uri_user_end = tvb_find_guint8(tvb, uri_offsets->uri_user_start, uri_offsets->uri_end - uri_offsets->uri_start, '@')-1;
uri_offsets->uri_host_start = uri_offsets->uri_user_end + 2;
}
parameter_end_offset = uri_offsets->uri_host_start;
in_ipv6 = (tvb_get_guint8(tvb, parameter_end_offset) == '[');
while (parameter_end_offset < line_end_offset)
{
parameter_end_offset++;
parameter_end_offset = tvb_pbrk_guint8(tvb, parameter_end_offset, line_end_offset - parameter_end_offset, ">,;? \r:[]", &c);
if (parameter_end_offset == -1)
{
parameter_end_offset = line_end_offset;
break;
}
switch (c) {
case '>':
case ',':
goto uri_host_end_found;
case ';':
uri_offsets->uri_parameters_start = parameter_end_offset + 1;
goto uri_host_end_found;
case '?':
case ' ':
case '\r':
goto uri_host_end_found;
case ':':
if (!in_ipv6)
goto uri_host_end_found;
break;
case '[':
in_ipv6 = TRUE;
break;
case ']':
in_ipv6 = FALSE;
break;
default :
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
}
uri_host_end_found:
uri_offsets->uri_host_end = parameter_end_offset - 1;
if (c == ':')
{
uri_offsets->uri_host_port_start = parameter_end_offset + 1;
parameter_end_offset = uri_offsets->uri_host_port_start;
while (parameter_end_offset < line_end_offset)
{
parameter_end_offset++;
parameter_end_offset = tvb_pbrk_guint8(tvb, parameter_end_offset, line_end_offset - parameter_end_offset, ">,;? \r", &c);
if (parameter_end_offset == -1)
{
parameter_end_offset = line_end_offset;
break;
}
switch (c) {
case '>':
case ',':
goto uri_host_port_end_found;
case ';':
uri_offsets->uri_parameters_start = parameter_end_offset + 1;
goto uri_host_port_end_found;
case '?':
case ' ':
case '\r':
goto uri_host_port_end_found;
default :
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
}
uri_host_port_end_found:
uri_offsets->uri_host_port_end = parameter_end_offset -1;
}
return uri_offsets->name_addr_end;
}
static proto_item *
sip_proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, gint value_offset, gint value_len)
{
const char *str;
unsigned long val;
if (!proto_field_is_referenced(tree, hfindex))
return tree;
str = tvb_get_string_enc(wmem_packet_scope(), tvb, value_offset, value_len, ENC_UTF_8|ENC_NA);
val = strtoul(str, NULL, 10);
return proto_tree_add_uint(tree, hfindex, tvb, start, length, (guint32) val);
}
static proto_item *
sip_proto_tree_add_string(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, gint value_offset, gint value_len)
{
const char *str;
if (!proto_field_is_referenced(tree, hfindex))
return tree;
str = tvb_get_string_enc(wmem_packet_scope(), tvb, value_offset, value_len, ENC_UTF_8|ENC_NA);
return proto_tree_add_string(tree, hfindex, tvb, start, length, str);
}
static void
sip_proto_set_format_text(const proto_tree *tree, proto_item *item, tvbuff_t *tvb, int offset, int length)
{
if (tree != item && item && PTREE_DATA(item)->visible)
proto_item_set_text(item, "%s", tvb_format_text(tvb, offset, length));
}
static gint
dissect_sip_history_info(tvbuff_t *tvb, proto_tree* tree, packet_info *pinfo _U_, gint current_offset,
gint line_end_offset)
{
int comma_offset;
gboolean first_time = TRUE;
while (line_end_offset > current_offset){
comma_offset = tvb_find_guint8(tvb, current_offset, line_end_offset - current_offset, ',');
if(comma_offset == -1){
if(first_time == TRUE){
return line_end_offset;
}
comma_offset = line_end_offset;
}
first_time = FALSE;
proto_tree_add_format_text(tree, tvb, current_offset, comma_offset-current_offset);
current_offset = comma_offset+1;
}
return line_end_offset;
}
static gint
dissect_sip_p_charging_func_addresses(tvbuff_t *tvb, proto_tree* tree, packet_info *pinfo _U_, gint current_offset,
gint line_end_offset)
{
gint semi_offset, start_quote_offset, end_quote_offset;
gboolean first_time = TRUE;
while (line_end_offset > current_offset){
start_quote_offset = tvb_find_guint8(tvb, current_offset, line_end_offset - current_offset, '"');
if(start_quote_offset>0){
end_quote_offset = tvb_find_guint8(tvb, start_quote_offset+1, line_end_offset - (start_quote_offset+1), '"');
if (end_quote_offset>0)
semi_offset = tvb_find_guint8(tvb, end_quote_offset+1, line_end_offset - (end_quote_offset+1), ';');
else {
semi_offset = tvb_find_guint8(tvb, start_quote_offset+1, line_end_offset - (start_quote_offset+1), ';');
}
}else{
semi_offset = tvb_find_guint8(tvb, current_offset, line_end_offset - current_offset, ';');
}
if(semi_offset == -1){
if(first_time == TRUE){
return line_end_offset;
}
semi_offset = line_end_offset;
}
first_time = FALSE;
proto_tree_add_format_text(tree, tvb, current_offset, semi_offset-current_offset);
current_offset = semi_offset+1;
}
return current_offset;
}
static gint
dissect_sip_name_addr_or_addr_spec(tvbuff_t *tvb, packet_info *pinfo _U_, gint start_offset,
gint line_end_offset, uri_offset_info *uri_offsets)
{
gchar c;
gint i;
gint current_offset;
gint queried_offset;
gint colon_offset;
gboolean uri_without_angle_quotes = FALSE;
current_offset = tvb_skip_wsp(tvb, start_offset, line_end_offset - start_offset);
if(current_offset >= line_end_offset) {
return -1;
}
uri_offsets->name_addr_start = current_offset;
c=tvb_get_guint8(tvb, current_offset);
switch(c)
{
case '"':
uri_offsets->display_name_start = current_offset;
do
{
queried_offset = tvb_find_guint8(tvb, current_offset + 1, line_end_offset - (current_offset + 1), '"');
if(queried_offset == -1)
{
return -1;
}
current_offset = queried_offset;
for(i=1;tvb_get_guint8(tvb, queried_offset - i) == '\\';i++);
i--;
if(i % 2 == 0)
{
break;
}
} while (current_offset < line_end_offset);
if(current_offset >= line_end_offset)
{
return -1;
}
uri_offsets->display_name_end = current_offset;
queried_offset = tvb_find_guint8(tvb, current_offset, line_end_offset - current_offset, '<');
if(queried_offset == -1)
{
return -1;
}
current_offset = queried_offset + 1;
break;
case '<':
current_offset++;
break;
default:
queried_offset = tvb_find_guint8(tvb, current_offset, line_end_offset - current_offset, '<');
colon_offset = tvb_find_guint8(tvb, current_offset, line_end_offset - current_offset, ':');
if(queried_offset != -1 && colon_offset != -1)
{
if(queried_offset < colon_offset)
{
uri_offsets->display_name_start = current_offset;
uri_offsets->display_name_end = queried_offset - 1;
current_offset = queried_offset + 1;
}
else
{
uri_without_angle_quotes = TRUE;
}
}
else
{
if(queried_offset != -1)
{
uri_offsets->display_name_start = current_offset;
uri_offsets->display_name_end = queried_offset - 1;
current_offset = queried_offset + 1;
break;
}
if(colon_offset != -1)
{
uri_without_angle_quotes = TRUE;
break;
}
return -1;
}
break;
}
uri_offsets->uri_start = current_offset;
if(uri_without_angle_quotes==FALSE){
queried_offset = tvb_find_guint8(tvb, current_offset, line_end_offset - current_offset, '>');
if(queried_offset == -1)
{
return -1;
}
uri_offsets->name_addr_end = queried_offset;
uri_offsets->uri_end = queried_offset - 1;
}
return dissect_sip_uri(tvb, pinfo, current_offset, line_end_offset, uri_offsets);
}
static proto_tree *
display_sip_uri (tvbuff_t *tvb, proto_tree *sip_element_tree, packet_info *pinfo, uri_offset_info* uri_offsets, hf_sip_uri_t* uri)
{
proto_item *ti;
proto_tree *uri_item_tree = NULL;
tvbuff_t *next_tvb;
if(uri_offsets->display_name_end != uri_offsets->display_name_start) {
proto_tree_add_item(sip_element_tree, hf_sip_display, tvb, uri_offsets->display_name_start,
uri_offsets->display_name_end - uri_offsets->display_name_start + 1, ENC_UTF_8|ENC_NA);
}
ti = proto_tree_add_item(sip_element_tree, *(uri->hf_sip_addr),
tvb, uri_offsets->uri_start, uri_offsets->uri_end - uri_offsets->uri_start + 1, ENC_UTF_8|ENC_NA);
uri_item_tree = proto_item_add_subtree(ti, *(uri->ett_uri));
if(uri_offsets->uri_user_end > uri_offsets->uri_user_start) {
proto_tree_add_item(uri_item_tree, *(uri->hf_sip_user), tvb, uri_offsets->uri_user_start,
uri_offsets->uri_user_end - uri_offsets->uri_user_start + 1, ENC_UTF_8|ENC_NA);
if(sip_uri_userinfo_handle){
next_tvb = tvb_new_subset(tvb, uri_offsets->uri_user_start, uri_offsets->uri_user_end - uri_offsets->uri_user_start + 1,
uri_offsets->uri_user_end - uri_offsets->uri_user_start + 1);
call_dissector(sip_uri_userinfo_handle, next_tvb, pinfo, uri_item_tree);
}
}
proto_tree_add_item(uri_item_tree, *(uri->hf_sip_host), tvb, uri_offsets->uri_host_start,
uri_offsets->uri_host_end - uri_offsets->uri_host_start + 1, ENC_UTF_8|ENC_NA);
if(uri_offsets->uri_host_port_end > uri_offsets->uri_host_port_start) {
proto_tree_add_item(uri_item_tree, *(uri->hf_sip_port), tvb, uri_offsets->uri_host_port_start,
uri_offsets->uri_host_port_end - uri_offsets->uri_host_port_start + 1, ENC_UTF_8|ENC_NA);
}
if (uri_offsets->uri_parameters_start != -1) {
gint current_offset = uri_offsets->uri_parameters_start;
gint uri_params_start_offset = current_offset;
gint queried_offset;
gint uri_param_end_offset = -1;
gchar c;
while (current_offset < uri_offsets->name_addr_end) {
queried_offset = tvb_pbrk_guint8(tvb, current_offset, uri_offsets->name_addr_end - current_offset, ",;", &c);
if (queried_offset == -1) {
c = tvb_get_guint8(tvb, uri_offsets->name_addr_end);
if (c == '>') {
uri_param_end_offset = uri_offsets->name_addr_end - 1;
} else {
uri_param_end_offset = uri_offsets->name_addr_end;
}
current_offset = uri_offsets->name_addr_end;
} else if (c==',') {
uri_param_end_offset = queried_offset;
current_offset = queried_offset+1;
} else if (c==';') {
uri_param_end_offset = queried_offset-1;
current_offset = tvb_skip_wsp(tvb, queried_offset+1, uri_offsets->name_addr_end - queried_offset + 1);
}
proto_tree_add_item(uri_item_tree, *(uri->hf_sip_param), tvb, uri_params_start_offset ,
uri_param_end_offset - uri_params_start_offset +1, ENC_UTF_8|ENC_NA);
uri_params_start_offset = current_offset;
}
}
return uri_item_tree;
}
static gint
dissect_sip_contact_item(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint start_offset, gint line_end_offset,
guchar* contacts_expires_0, guchar* contacts_expires_unknown)
{
gchar c;
gint current_offset;
gint queried_offset;
gint contact_params_start_offset = -1;
uri_offset_info uri_offsets;
gboolean end_of_hdr = FALSE;
gboolean has_expires_param = FALSE;
start_offset = tvb_skip_wsp(tvb, start_offset, line_end_offset - start_offset);
if(start_offset >= line_end_offset) {
return -1;
}
sip_uri_offset_init(&uri_offsets);
current_offset = dissect_sip_name_addr_or_addr_spec(tvb, pinfo, start_offset, line_end_offset, &uri_offsets);
if(current_offset == -1)
{
return -1;
}
display_sip_uri(tvb, tree, pinfo, &uri_offsets, &sip_contact_uri);
queried_offset = tvb_find_guint8(tvb, uri_offsets.uri_end, line_end_offset - uri_offsets.uri_end, ',');
contact_params_start_offset = tvb_find_guint8(tvb, uri_offsets.uri_end, line_end_offset - uri_offsets.uri_end, ';');
if(contact_params_start_offset == -1) {
(*contacts_expires_unknown)++;
return line_end_offset;
}
if (queried_offset != -1 && queried_offset < contact_params_start_offset) {
(*contacts_expires_unknown)++;
return queried_offset;
}
contact_params_start_offset++;
current_offset = contact_params_start_offset;
queried_offset = current_offset;
while(current_offset< line_end_offset){
c = '\0';
queried_offset++;
queried_offset = (queried_offset < line_end_offset) ? tvb_pbrk_guint8(tvb, queried_offset, line_end_offset - queried_offset, "\r\n,;\"", &c) : -1;
if (queried_offset != -1)
{
switch (c) {
case '\r':
case '\n':
end_of_hdr = TRUE;
case ',':
case ';':
case '"':
break;
default :
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
}
if (queried_offset == -1) {
current_offset = line_end_offset;
}else if(c=='"'){
queried_offset = tvb_find_guint8(tvb, queried_offset+1, line_end_offset - queried_offset, '"');
if(queried_offset==-1){
current_offset = line_end_offset;
} else {
current_offset = tvb_pbrk_guint8(tvb, queried_offset+1, line_end_offset - queried_offset, ",;", &c);
if(current_offset==-1){
current_offset = line_end_offset;
}
}
}else{
current_offset = queried_offset;
}
proto_tree_add_item(tree, hf_sip_contact_param, tvb, contact_params_start_offset ,
current_offset - contact_params_start_offset, ENC_UTF_8|ENC_NA);
if (tvb_strncaseeql(tvb, contact_params_start_offset, "expires=", 8) == 0) {
if (atoi(tvb_get_string_enc(wmem_packet_scope(), tvb, contact_params_start_offset+8,
current_offset - (contact_params_start_offset+8), ENC_UTF_8|ENC_NA)) == 0) {
(*contacts_expires_0)++;
if (stat_info && stat_info->response_code > 199 && stat_info->response_code < 300) {
proto_tree_add_expert_format(tree, pinfo, &ei_sip_odd_register_response,
tvb, contact_params_start_offset, current_offset - contact_params_start_offset,
"SIP REGISTER %d response contains Contact with expires=0",
stat_info->response_code);
}
} else {
has_expires_param = TRUE;
}
}
contact_params_start_offset = current_offset+1;
queried_offset = contact_params_start_offset;
if (end_of_hdr) {
current_offset = line_end_offset;
}
if (c == ',') {
break;
}
}
if (!has_expires_param) {
(*contacts_expires_unknown)++;
}
return current_offset;
}
static gint
dissect_sip_authorization_item(tvbuff_t *tvb, proto_tree *tree, gint start_offset, gint line_end_offset)
{
gint current_offset, par_name_end_offset, queried_offset;
gint equals_offset = 0;
gchar *name;
header_parameter_t *auth_parameter;
guint i = 0;
gchar c = '\0';
start_offset = tvb_skip_wsp(tvb, start_offset, line_end_offset - start_offset);
if (start_offset >= line_end_offset)
{
return -1;
}
current_offset = start_offset;
equals_offset = tvb_find_guint8(tvb, current_offset + 1, line_end_offset - (current_offset + 1), '=');
if(equals_offset == -1){
return -1;
}
par_name_end_offset = equals_offset - 1;
par_name_end_offset = tvb_skip_wsp_return(tvb,par_name_end_offset);
name = tvb_get_string_enc(wmem_packet_scope(), tvb, start_offset, par_name_end_offset-start_offset, ENC_UTF_8|ENC_NA);
queried_offset = tvb_pbrk_guint8(tvb, par_name_end_offset, line_end_offset - par_name_end_offset, "'\"", &c);
if (queried_offset == -1) {
current_offset = line_end_offset;
}else if(c=='"'){
queried_offset = tvb_find_guint8(tvb, queried_offset+1, line_end_offset - queried_offset, '"');
if(queried_offset==-1){
queried_offset = line_end_offset;
}
current_offset = tvb_find_guint8(tvb, queried_offset+1, line_end_offset - queried_offset, ',');
if(current_offset==-1){
current_offset = line_end_offset;
}
}else{
current_offset = queried_offset;
}
for (auth_parameter = &auth_parameters_hf_array[i];
i < array_length(auth_parameters_hf_array);
i++, auth_parameter++)
{
if (g_ascii_strcasecmp(name, auth_parameter->param_name) == 0)
{
proto_tree_add_item(tree, *(auth_parameter->hf_item), tvb,
equals_offset+1, current_offset-equals_offset-1,
ENC_UTF_8|ENC_NA);
break;
}
}
if (i == array_length(auth_parameters_hf_array))
{
proto_tree_add_format_text(tree, tvb, start_offset, current_offset-start_offset);
}
return current_offset;
}
static void
dissect_sip_reason_header(tvbuff_t *tvb, proto_tree *tree, gint start_offset, gint line_end_offset){
gint current_offset, semi_colon_offset, length;
gchar *param_name = NULL;
guint cause_value;
start_offset = tvb_skip_wsp(tvb, start_offset, line_end_offset - start_offset);
if (start_offset >= line_end_offset)
{
return;
}
current_offset = start_offset;
semi_colon_offset = tvb_find_guint8(tvb, current_offset, line_end_offset-current_offset, ';');
if(semi_colon_offset == -1)
return;
length = semi_colon_offset - current_offset;
if (tree) {
proto_tree_add_text(tree, tvb, start_offset, length,
"Reason Protocols: %s", tvb_format_text(tvb, start_offset, length));
}
param_name = tvb_get_string_enc(wmem_packet_scope(), tvb, start_offset, length, ENC_UTF_8|ENC_NA);
if (g_ascii_strcasecmp(param_name, "Q.850") == 0){
current_offset = tvb_find_guint8(tvb, semi_colon_offset, line_end_offset-semi_colon_offset, '=')+1;
length = line_end_offset - current_offset;
cause_value = (guint)strtoul(tvb_get_string_enc(wmem_packet_scope(), tvb, current_offset, length, ENC_UTF_8|ENC_NA), NULL, 10);
proto_tree_add_text(tree, tvb, current_offset, length,
"Cause: %u(0x%x)[%s]", cause_value,cause_value,
val_to_str_ext(cause_value, &q850_cause_code_vals_ext, "Unknown (%d)" ));
}
}
static void
dissect_sip_sec_mechanism(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, gint start_offset, gint line_end_offset){
gint current_offset, semi_colon_offset, length, par_name_end_offset, equals_offset;
guint32 spi_c;
guint32 spi_s;
guint16 port;
start_offset = tvb_skip_wsp(tvb, start_offset, line_end_offset - start_offset);
if (start_offset >= line_end_offset)
{
return;
}
current_offset = start_offset;
semi_colon_offset = tvb_find_guint8(tvb, current_offset, line_end_offset-current_offset, ';');
if(semi_colon_offset == -1){
semi_colon_offset = line_end_offset;
}
length = semi_colon_offset-current_offset;
proto_tree_add_item(tree, hf_sip_sec_mechanism, tvb,
start_offset, length,
ENC_UTF_8|ENC_NA);
current_offset = current_offset + length + 1;
while(current_offset < line_end_offset){
gchar *param_name = NULL, *value = NULL;
current_offset = tvb_skip_wsp(tvb, current_offset, line_end_offset - current_offset);
semi_colon_offset = tvb_find_guint8(tvb, current_offset, line_end_offset-current_offset, ';');
if(semi_colon_offset == -1){
semi_colon_offset = line_end_offset;
}
length = semi_colon_offset - current_offset;
equals_offset = tvb_find_guint8(tvb, current_offset + 1, length, '=');
if(equals_offset != -1){
par_name_end_offset = equals_offset;
param_name = tvb_get_string_enc(wmem_packet_scope(), tvb, current_offset, par_name_end_offset-current_offset, ENC_UTF_8|ENC_NA);
value = tvb_get_string_enc(wmem_packet_scope(), tvb, equals_offset+1, semi_colon_offset-equals_offset+1, ENC_UTF_8|ENC_NA);
}
if (g_ascii_strcasecmp(param_name, "alg") == 0){
proto_tree_add_item(tree, hf_sip_sec_mechanism_alg, tvb,
equals_offset+1, semi_colon_offset-equals_offset-1,
ENC_UTF_8|ENC_NA);
}else if (g_ascii_strcasecmp(param_name, "ealg") == 0){
proto_tree_add_item(tree, hf_sip_sec_mechanism_ealg, tvb,
equals_offset+1, semi_colon_offset-equals_offset-1,
ENC_UTF_8|ENC_NA);
}else if (g_ascii_strcasecmp(param_name, "prot") == 0){
proto_tree_add_item(tree, hf_sip_sec_mechanism_prot, tvb,
equals_offset+1, semi_colon_offset-equals_offset-1,
ENC_UTF_8|ENC_NA);
}else if (g_ascii_strcasecmp(param_name, "spi-c") == 0){
if (!value) {
proto_tree_add_expert(tree, pinfo, &ei_sip_sipsec_malformed,
tvb, current_offset, -1);
} else {
spi_c = (guint32)strtoul(value, NULL, 10);
proto_tree_add_uint(tree, hf_sip_sec_mechanism_spi_c, tvb,
equals_offset+1, semi_colon_offset-equals_offset-1, spi_c);
}
}else if (g_ascii_strcasecmp(param_name, "spi-s") == 0){
if (!value) {
proto_tree_add_expert(tree, pinfo, &ei_sip_sipsec_malformed,
tvb, current_offset, -1);
} else {
spi_s = (guint32)strtoul(value, NULL, 10);
proto_tree_add_uint(tree, hf_sip_sec_mechanism_spi_s, tvb,
equals_offset+1, semi_colon_offset-equals_offset-1, spi_s);
}
}else if (g_ascii_strcasecmp(param_name, "port1") == 0){
if (!value) {
proto_tree_add_expert(tree, pinfo, &ei_sip_sipsec_malformed,
tvb, current_offset, -1);
} else {
port = (guint16)strtoul(value, NULL, 10);
proto_tree_add_uint(tree, hf_sip_sec_mechanism_port1, tvb,
equals_offset+1, semi_colon_offset-equals_offset-1, port);
}
}else if (g_ascii_strcasecmp(param_name, "port-c") == 0){
if (!value) {
proto_tree_add_expert(tree, pinfo, &ei_sip_sipsec_malformed,
tvb, current_offset, -1);
} else {
port = (guint32)strtoul(value, NULL, 10);
proto_tree_add_uint(tree, hf_sip_sec_mechanism_port_c, tvb,
equals_offset+1, semi_colon_offset-equals_offset-1, port);
}
}else if (g_ascii_strcasecmp(param_name, "port2") == 0){
if (!value) {
proto_tree_add_expert(tree, pinfo, &ei_sip_sipsec_malformed,
tvb, current_offset, -1);
} else {
port = (guint32)strtoul(value, NULL, 10);
proto_tree_add_uint(tree, hf_sip_sec_mechanism_port2, tvb,
equals_offset+1, semi_colon_offset-equals_offset-1, port);
}
}else if (g_ascii_strcasecmp(param_name, "port-s") == 0){
if (!value) {
proto_tree_add_expert(tree, pinfo, &ei_sip_sipsec_malformed,
tvb, current_offset, -1);
} else {
port = (guint32)strtoul(value, NULL, 10);
proto_tree_add_uint(tree, hf_sip_sec_mechanism_port_s, tvb,
equals_offset+1, semi_colon_offset-equals_offset-1, port);
}
}
else{
proto_tree_add_format_text(tree, tvb, current_offset, length);
}
current_offset = semi_colon_offset+1;
}
}
static void dissect_sip_route_header(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, hf_sip_uri_t *sip_route_uri_p, gint start_offset, gint line_end_offset)
{
gint current_offset;
uri_offset_info uri_offsets;
current_offset = start_offset;
current_offset = tvb_skip_wsp(tvb, current_offset, line_end_offset - current_offset);
if (current_offset >= line_end_offset) {
return;
}
while (current_offset < line_end_offset) {
current_offset = tvb_find_guint8(tvb, current_offset, (line_end_offset - 1) - current_offset, ',');
if (current_offset != -1) {
sip_uri_offset_init(&uri_offsets);
current_offset = dissect_sip_name_addr_or_addr_spec(tvb, pinfo, start_offset, current_offset, &uri_offsets);
if(current_offset == -1)
return;
display_sip_uri(tvb, tree, pinfo, &uri_offsets, sip_route_uri_p);
current_offset++;
start_offset = current_offset + 1;
} else {
sip_uri_offset_init(&uri_offsets);
current_offset = dissect_sip_name_addr_or_addr_spec(tvb, pinfo, start_offset, line_end_offset, &uri_offsets);
if(current_offset == -1)
return;
display_sip_uri(tvb, tree, pinfo, &uri_offsets, sip_route_uri_p);
return;
}
current_offset++;
}
return;
}
static void dissect_sip_via_header(tvbuff_t *tvb, proto_tree *tree, gint start_offset, gint line_end_offset)
{
gint current_offset;
gint address_start_offset;
gint semicolon_offset;
gboolean colon_seen;
gboolean ipv6_reference;
gboolean ipv6_address;
guchar c;
gchar *param_name = NULL;
current_offset = start_offset;
while (1)
{
semicolon_offset = 0;
ipv6_reference = FALSE;
ipv6_address = FALSE;
colon_seen = FALSE;
current_offset = tvb_skip_wsp(tvb, current_offset, line_end_offset - current_offset);
if (current_offset >= line_end_offset)
{
return;
}
current_offset = tvb_find_guint8(tvb, current_offset, line_end_offset - current_offset, '/');
if (current_offset != -1)
{
current_offset++;
current_offset = tvb_find_guint8(tvb, current_offset, line_end_offset - current_offset, '/');
}
if (current_offset != -1)
{
current_offset++;
current_offset = tvb_skip_wsp(tvb, current_offset, line_end_offset - current_offset);
} else
current_offset = line_end_offset;
while (current_offset < line_end_offset)
{
int transport_start_offset = current_offset;
current_offset = tvb_pbrk_guint8(tvb, current_offset, line_end_offset - current_offset, "\t /", &c);
if (current_offset != -1){
proto_tree_add_item(tree, hf_sip_via_transport, tvb, transport_start_offset,
current_offset - transport_start_offset, ENC_UTF_8|ENC_NA);
if(c=='/'){
current_offset++;
continue;
}
current_offset = tvb_skip_wsp(tvb, current_offset, line_end_offset - current_offset);
c = tvb_get_guint8(tvb, current_offset);
if(c=='/'){
current_offset++;
continue;
}
break;
}else{
current_offset = line_end_offset;
}
}
current_offset = tvb_skip_wsp(tvb, current_offset, line_end_offset - current_offset);
address_start_offset = current_offset;
while (current_offset < line_end_offset)
{
current_offset = tvb_pbrk_guint8(tvb, current_offset, line_end_offset - current_offset, "[] \t:;", &c);
if (current_offset == -1)
{
current_offset = line_end_offset;
break;
}
if (c == '[') {
ipv6_reference = TRUE;
ipv6_address = TRUE;
}
else if (c == ']')
{
ipv6_reference = FALSE;
}
if (colon_seen || (c == ' ') || (c == '\t') || ((c == ':') && (ipv6_reference == FALSE)) || (c == ';'))
{
break;
}
current_offset++;
}
if (ipv6_address == TRUE) {
proto_tree_add_item(tree, hf_sip_via_sent_by_address, tvb, address_start_offset + 1,
current_offset - address_start_offset - 2, ENC_UTF_8|ENC_NA);
} else {
proto_tree_add_item(tree, hf_sip_via_sent_by_address, tvb, address_start_offset,
current_offset - address_start_offset, ENC_UTF_8|ENC_NA);
}
current_offset = tvb_skip_wsp(tvb, current_offset, line_end_offset - current_offset);
c = tvb_get_guint8(tvb, current_offset);
if (c == ':')
{
gint port_offset;
current_offset++;
current_offset = tvb_skip_wsp(tvb, current_offset, line_end_offset - current_offset);
port_offset = current_offset;
while (current_offset < line_end_offset)
{
c = tvb_get_guint8(tvb, current_offset);
if (!isdigit(c))
{
if (current_offset > port_offset)
{
int port = atoi(tvb_get_string_enc(wmem_packet_scope(), tvb, port_offset,
current_offset - port_offset, ENC_UTF_8|ENC_NA));
proto_tree_add_uint(tree, hf_sip_via_sent_by_port, tvb, port_offset,
current_offset - port_offset, port);
}
else
{
return;
}
break;
}
current_offset++;
}
}
current_offset = tvb_skip_wsp(tvb, current_offset, line_end_offset - current_offset);
while (current_offset < line_end_offset)
{
gboolean equals_found = FALSE;
gboolean found_end_of_parameters = FALSE;
gint parameter_name_end = 0;
header_parameter_t *via_parameter;
guint i = 0;
while (current_offset < line_end_offset)
{
c = tvb_get_guint8(tvb, current_offset);
if (c == ';')
{
semicolon_offset = current_offset;
current_offset++;
break;
}
else
if ((c != ' ') && (c != '\t'))
{
found_end_of_parameters = TRUE;
break;
}
current_offset++;
}
if (found_end_of_parameters)
{
break;
}
if (current_offset == line_end_offset)
{
return;
}
while (current_offset < line_end_offset)
{
c = tvb_get_guint8(tvb, current_offset);
if (!isalpha(c) && (c != '-'))
{
break;
}
current_offset++;
}
if (c == '=')
{
equals_found = TRUE;
}
parameter_name_end = current_offset;
current_offset = tvb_pbrk_guint8(tvb, current_offset, line_end_offset - current_offset, "\t;, ", NULL);
if (current_offset == -1)
current_offset = line_end_offset;
param_name = tvb_get_string_enc(wmem_packet_scope(), tvb, semicolon_offset+1,
parameter_name_end - semicolon_offset - 1, ENC_UTF_8|ENC_NA);
for (via_parameter = &via_parameters_hf_array[i];
i < array_length(via_parameters_hf_array);
i++, via_parameter++)
{
if (g_ascii_strcasecmp(param_name, via_parameter->param_name) == 0)
{
if (equals_found)
{
proto_tree_add_item(tree, *(via_parameter->hf_item), tvb,
parameter_name_end+1, current_offset-parameter_name_end-1,
ENC_UTF_8|ENC_NA);
}
else
{
proto_tree_add_item(tree, *(via_parameter->hf_item), tvb,
semicolon_offset+1, current_offset-semicolon_offset-1,
ENC_UTF_8|ENC_NA);
}
break;
}
}
if (i == array_length(via_parameters_hf_array))
{
proto_tree_add_format_text(tree, tvb, semicolon_offset+1, current_offset-semicolon_offset-1);
}
current_offset = tvb_skip_wsp(tvb, current_offset, line_end_offset - current_offset);
if (current_offset < line_end_offset)
{
c = tvb_get_guint8(tvb, current_offset);
if (c == ',')
{
current_offset++;
break;
}
}
}
}
}
static int
dissect_sip(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
guint8 octet;
int len;
int remaining_length;
octet = tvb_get_guint8(tvb,0);
if ((octet & 0xf8) == 0xf8){
call_dissector(sigcomp_handle, tvb, pinfo, tree);
return tvb_reported_length(tvb);
}
remaining_length = tvb_reported_length(tvb);
len = dissect_sip_common(tvb, 0, remaining_length, pinfo, tree, FALSE, FALSE);
if (len < 0)
return 0;
else
return len;
}
static void
dissect_sip_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 octet;
int offset = 0;
int len;
int remaining_length;
octet = tvb_get_guint8(tvb,0);
if ((octet & 0xf8) == 0xf8){
call_dissector(sigcomp_handle, tvb, pinfo, tree);
return;
}
remaining_length = tvb_reported_length(tvb);
while (remaining_length > 0) {
len = dissect_sip_common(tvb, offset, remaining_length, pinfo, tree, TRUE, TRUE);
if (len <= 0)
break;
offset += len;
remaining_length = remaining_length - len;
}
}
static gboolean
dissect_sip_tcp_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
int offset = 0;
int len;
gboolean first = TRUE;
int remaining_length;
remaining_length = tvb_reported_length(tvb);
while (remaining_length > 0) {
len = dissect_sip_common(tvb, offset, remaining_length, pinfo, tree, !first, TRUE);
if (len == -2) {
if (first) {
return FALSE;
}
break;
}
if (len == -1)
break;
offset += len;
remaining_length = remaining_length - len;
first = FALSE;
}
return TRUE;
}
static gboolean
dissect_sip_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
int remaining_length = tvb_reported_length(tvb);
return dissect_sip_common(tvb, 0, remaining_length, pinfo, tree, FALSE, FALSE) > 0;
}
static int
dissect_sip_common(tvbuff_t *tvb, int offset, int remaining_length, packet_info *pinfo, proto_tree *tree,
gboolean dissect_other_as_continuation, gboolean use_reassembly)
{
int orig_offset;
gint next_offset, linelen;
int content_length, datalen, reported_datalen;
line_type_t line_type;
tvbuff_t *next_tvb;
gboolean is_known_request;
gboolean found_match = FALSE;
const char *descr;
guint token_1_len = 0;
guint current_method_idx = SIP_METHOD_INVALID;
proto_item *ts = NULL, *ti_a = NULL, *th = NULL;
proto_tree *sip_tree = NULL, *reqresp_tree = NULL, *hdr_tree = NULL,
*message_body_tree = NULL, *cseq_tree = NULL,
*via_tree = NULL, *reason_tree = NULL, *rack_tree = NULL,
*route_tree = NULL, *security_client_tree = NULL;
guchar contacts = 0, contact_is_star = 0, expires_is_0 = 0, contacts_expires_0 = 0, contacts_expires_unknown = 0;
guint32 cseq_number = 0;
guchar cseq_number_set = 0;
char cseq_method[MAX_CSEQ_METHOD_SIZE] = "";
char call_id[MAX_CALL_ID_SIZE] = "";
gchar *media_type_str_lower_case = NULL;
char *content_type_parameter_str = NULL;
char *content_encoding_parameter_str = NULL;
guint resend_for_packet = 0;
guint request_for_response = 0;
guint32 response_time = 0;
int strlen_to_copy;
heur_dtbl_entry_t *hdtbl_entry;
if (!dissect_other_as_continuation &&
((remaining_length < 1) || !g_ascii_isprint(tvb_get_guint8(tvb, offset))))
{
return -2;
}
orig_offset = offset;
linelen = tvb_find_line_end(tvb, offset, remaining_length, &next_offset, FALSE);
if(linelen==0){
return -2;
}
if (tvb_strnlen(tvb, offset, linelen) > -1)
{
return -2;
}
line_type = sip_parse_line(tvb, offset, linelen, &token_1_len);
if (line_type == OTHER_LINE) {
if (!dissect_other_as_continuation) {
return -2;
}
} else if ((use_reassembly)&&( pinfo->ptype == PT_TCP)) {
if (!req_resp_hdrs_do_reassembly(tvb, offset, pinfo,
sip_desegment_headers, sip_desegment_body)) {
return -1;
}
}
stat_info = wmem_new0(wmem_packet_scope(), sip_info_value_t);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SIP");
DPRINT2(("------------------------------ dissect_sip_common ------------------------------"));
switch (line_type) {
case REQUEST_LINE:
is_known_request = sip_is_known_request(tvb, offset, token_1_len, &current_method_idx);
descr = is_known_request ? "Request" : "Unknown request";
col_add_lstr(pinfo->cinfo, COL_INFO,
descr, ": ",
tvb_format_text(tvb, offset, linelen - SIP2_HDR_LEN - 1),
COL_ADD_LSTR_TERMINATOR);
DPRINT(("got %s: %s", descr,
tvb_format_text(tvb, offset, linelen - SIP2_HDR_LEN - 1)));
break;
case STATUS_LINE:
descr = "Status";
col_add_lstr(pinfo->cinfo, COL_INFO,
"Status: ",
tvb_format_text(tvb, offset + SIP2_HDR_LEN + 1, linelen - SIP2_HDR_LEN - 1),
COL_ADD_LSTR_TERMINATOR);
stat_info->reason_phrase = tvb_get_string_enc(wmem_packet_scope(), tvb, offset + SIP2_HDR_LEN + 5,
linelen - (SIP2_HDR_LEN + 5),ENC_UTF_8|ENC_NA);
DPRINT(("got Response: %s",
tvb_format_text(tvb, offset + SIP2_HDR_LEN + 1, linelen - SIP2_HDR_LEN - 1)));
break;
case OTHER_LINE:
default:
descr = "Continuation";
col_set_str(pinfo->cinfo, COL_INFO, "Continuation");
DPRINT(("got continuation"));
break;
}
if (tree) {
ts = proto_tree_add_item(tree, proto_sip, tvb, offset, -1, ENC_NA);
sip_tree = proto_item_add_subtree(ts, ett_sip);
}
switch (line_type) {
case REQUEST_LINE:
if (sip_tree) {
ti_a = proto_tree_add_item(sip_tree, hf_Request_Line, tvb,
offset, linelen, ENC_UTF_8|ENC_NA);
reqresp_tree = proto_item_add_subtree(ti_a, ett_sip_reqresp);
}
dfilter_sip_request_line(tvb, reqresp_tree, pinfo, offset, token_1_len, linelen);
break;
case STATUS_LINE:
if (sip_tree) {
ti_a = proto_tree_add_item(sip_tree, hf_sip_Status_Line, tvb,
offset, linelen, ENC_UTF_8|ENC_NA);
reqresp_tree = proto_item_add_subtree(ti_a, ett_sip_reqresp);
}
dfilter_sip_status_line(tvb, reqresp_tree, pinfo, linelen, offset);
break;
case OTHER_LINE:
if (sip_tree) {
reqresp_tree = proto_tree_add_subtree_format(sip_tree, tvb, offset, next_offset,
ett_sip_reqresp, NULL, "%s line: %s", descr,
tvb_format_text(tvb, offset, linelen));
proto_tree_add_text(reqresp_tree, tvb, offset, -1, "Continuation data");
}
return remaining_length;
}
remaining_length = remaining_length - (next_offset - offset);
offset = next_offset;
if (sip_tree) {
th = proto_tree_add_item(sip_tree, hf_sip_msg_hdr, tvb, offset,
remaining_length, ENC_UTF_8|ENC_NA);
proto_item_set_text(th, "Message Header");
hdr_tree = proto_item_add_subtree(th, ett_sip_hdr);
}
next_offset = offset;
content_length = -1;
while (remaining_length > 0) {
gint line_end_offset;
gint colon_offset;
gint semi_colon_offset;
gint parameter_offset;
gint parameter_end_offset;
gint parameter_len;
gint content_type_len, content_type_parameter_str_len;
gint header_len;
gchar *header_name;
dissector_handle_t ext_hdr_handle;
gint hf_index;
gint value_offset;
gint sub_value_offset;
gint comma_offset;
guchar c;
gint value_len;
gboolean is_no_header_termination = FALSE;
proto_tree *tc_uri_item_tree = NULL;
uri_offset_info uri_offsets;
linelen = tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
if (linelen == 0) {
offset = next_offset;
break;
}
line_end_offset = offset + linelen;
if(tvb_reported_length_remaining(tvb, next_offset) <= 0){
is_no_header_termination = TRUE;
}else{
while ((c = tvb_get_guint8(tvb, next_offset)) == ' ' || c == '\t')
{
linelen += (next_offset - line_end_offset);
linelen += tvb_find_line_end(tvb, next_offset, -1, &next_offset, FALSE);
line_end_offset = offset + linelen;
}
}
colon_offset = tvb_find_guint8(tvb, offset, linelen, ':');
if (colon_offset == -1) {
if(hdr_tree) {
proto_tree_add_text(hdr_tree, tvb, offset,
next_offset - offset, "%s",
tvb_format_text(tvb, offset, linelen));
}
} else {
header_len = colon_offset - offset;
header_name = (gchar*)tvb_get_string_enc(wmem_packet_scope(), tvb, offset, header_len, ENC_UTF_8|ENC_NA);
ascii_strdown_inplace(header_name);
hf_index = sip_is_known_sip_header(header_name, header_len);
value_offset = tvb_skip_wsp(tvb, colon_offset + 1, line_end_offset - (colon_offset + 1));
value_len = (gint) (line_end_offset - value_offset);
if (hf_index == -1) {
proto_item *ti_c = proto_tree_add_text(hdr_tree, tvb,
offset, next_offset - offset, "%s",
tvb_format_text(tvb, offset, linelen));
ext_hdr_handle = dissector_get_string_handle(ext_hdr_subdissector_table, header_name);
if (ext_hdr_handle != NULL) {
tvbuff_t *next_tvb2;
next_tvb2 = tvb_new_subset_length(tvb, value_offset, value_len);
dissector_try_string(ext_hdr_subdissector_table, header_name, next_tvb2, pinfo, proto_item_add_subtree(ti_c, ett_sip_ext_hdr), NULL);
} else {
expert_add_info_format(pinfo, ti_c, &ei_sip_unrecognized_header,
"Unrecognised SIP header (%s)",
header_name);
}
} else {
proto_item *sip_element_item;
proto_tree *sip_element_tree;
switch ( hf_index ) {
case POS_TO :
{
proto_item *item;
sip_element_item = sip_proto_tree_add_string(hdr_tree,
hf_header_array[hf_index], tvb,
offset, next_offset - offset,
value_offset, value_len);
sip_proto_set_format_text(hdr_tree, sip_element_item, tvb, offset, linelen);
sip_element_tree = proto_item_add_subtree( sip_element_item,
ett_sip_element);
sip_uri_offset_init(&uri_offsets);
if((dissect_sip_name_addr_or_addr_spec(tvb, pinfo, value_offset, line_end_offset+2, &uri_offsets)) != -1){
display_sip_uri(tvb, sip_element_tree, pinfo, &uri_offsets, &sip_to_uri);
if((uri_offsets.name_addr_start != -1) && (uri_offsets.name_addr_end != -1)){
stat_info->tap_to_addr=tvb_get_string_enc(wmem_packet_scope(), tvb, uri_offsets.name_addr_start,
uri_offsets.name_addr_end - uri_offsets.name_addr_start, ENC_UTF_8|ENC_NA);
}
offset = uri_offsets.name_addr_end +1;
}
parameter_offset = offset;
while (parameter_offset < line_end_offset
&& (tvb_strneql(tvb, parameter_offset, "tag=", 4) != 0))
parameter_offset++;
if ( parameter_offset < line_end_offset ){
parameter_offset = parameter_offset + 4;
parameter_end_offset = tvb_find_guint8(tvb, parameter_offset,
(line_end_offset - parameter_offset), ';');
if ( parameter_end_offset == -1)
parameter_end_offset = line_end_offset;
parameter_len = parameter_end_offset - parameter_offset;
proto_tree_add_item(sip_element_tree, hf_sip_to_tag, tvb, parameter_offset,
parameter_len, ENC_UTF_8|ENC_NA);
item = proto_tree_add_item(sip_element_tree, hf_sip_tag, tvb, parameter_offset,
parameter_len, ENC_UTF_8|ENC_NA);
PROTO_ITEM_SET_HIDDEN(item);
switch (current_method_idx) {
case SIP_METHOD_INVITE:
case SIP_METHOD_SUBSCRIBE:
case SIP_METHOD_REFER:
col_append_str(pinfo->cinfo, COL_INFO, ", in-dialog");
break;
}
}
}
break;
case POS_FROM :
if(hdr_tree) {
proto_item *item;
sip_element_item = sip_proto_tree_add_string(hdr_tree,
hf_header_array[hf_index], tvb,
offset, next_offset - offset,
value_offset, value_len);
sip_proto_set_format_text(hdr_tree, sip_element_item, tvb, offset, linelen);
sip_element_tree = proto_item_add_subtree( sip_element_item, ett_sip_element);
sip_uri_offset_init(&uri_offsets);
if((dissect_sip_name_addr_or_addr_spec(tvb, pinfo, value_offset, line_end_offset+2, &uri_offsets)) != -1){
display_sip_uri(tvb, sip_element_tree, pinfo, &uri_offsets, &sip_from_uri);
if((uri_offsets.name_addr_start != -1) && (uri_offsets.name_addr_end != -1)){
stat_info->tap_from_addr=tvb_get_string_enc(wmem_packet_scope(), tvb, uri_offsets.name_addr_start,
uri_offsets.name_addr_end - uri_offsets.name_addr_start, ENC_UTF_8|ENC_NA);
}
offset = uri_offsets.name_addr_end +1;
}
parameter_offset = offset;
while (parameter_offset < line_end_offset
&& (tvb_strneql(tvb, parameter_offset, "tag=", 4) != 0))
parameter_offset++;
if ( parameter_offset < line_end_offset ){
parameter_offset = parameter_offset + 4;
parameter_end_offset = tvb_find_guint8(tvb, parameter_offset,
(line_end_offset - parameter_offset), ';');
if ( parameter_end_offset == -1)
parameter_end_offset = line_end_offset;
parameter_len = parameter_end_offset - parameter_offset;
proto_tree_add_item(sip_element_tree, hf_sip_from_tag, tvb, parameter_offset,
parameter_len, ENC_UTF_8|ENC_NA);
item = proto_tree_add_item(sip_element_tree, hf_sip_tag, tvb, parameter_offset,
parameter_len, ENC_UTF_8|ENC_NA);
PROTO_ITEM_SET_HIDDEN(item);
}
}
break;
case POS_P_ASSERTED_IDENTITY :
if(hdr_tree)
{
sip_element_item = sip_proto_tree_add_string(hdr_tree,
hf_header_array[hf_index], tvb,
offset, next_offset - offset,
value_offset, value_len);
sip_proto_set_format_text(hdr_tree, sip_element_item, tvb, offset, linelen);
sip_element_tree = proto_item_add_subtree( sip_element_item,
ett_sip_element);
sip_uri_offset_init(&uri_offsets);
if((dissect_sip_name_addr_or_addr_spec(tvb, pinfo, value_offset, line_end_offset+2, &uri_offsets)) != -1)
display_sip_uri(tvb, sip_element_tree, pinfo, &uri_offsets, &sip_pai_uri);
}
break;
case POS_HISTORY_INFO:
if(hdr_tree)
{
sip_element_item = sip_proto_tree_add_string(hdr_tree,
hf_header_array[hf_index], tvb,
offset, next_offset - offset,
value_offset, value_len);
sip_proto_set_format_text(hdr_tree, sip_element_item, tvb, offset, linelen);
sip_element_tree = proto_item_add_subtree( sip_element_item,
ett_sip_hist);
dissect_sip_history_info(tvb, sip_element_tree, pinfo, value_offset, line_end_offset);
}
break;
case POS_P_CHARGING_FUNC_ADDRESSES:
if(hdr_tree)
{
sip_element_item = sip_proto_tree_add_string(hdr_tree,
hf_header_array[hf_index], tvb,
offset, next_offset - offset,
value_offset, value_len);
sip_proto_set_format_text(hdr_tree, sip_element_item, tvb, offset, linelen);
sip_element_tree = proto_item_add_subtree( sip_element_item,
ett_sip_element);
dissect_sip_p_charging_func_addresses(tvb, sip_element_tree, pinfo, value_offset, line_end_offset);
}
break;
case POS_P_PREFERRED_IDENTITY :
if(hdr_tree)
{
sip_element_item = sip_proto_tree_add_string(hdr_tree,
hf_header_array[hf_index], tvb,
offset, next_offset - offset,
value_offset, value_len);
sip_proto_set_format_text(hdr_tree, sip_element_item, tvb, offset, linelen);
sip_element_tree = proto_item_add_subtree( sip_element_item,
ett_sip_element);
sip_uri_offset_init(&uri_offsets);
if((dissect_sip_name_addr_or_addr_spec(tvb, pinfo, value_offset, line_end_offset+2, &uri_offsets)) != -1)
display_sip_uri(tvb, sip_element_tree, pinfo, &uri_offsets, &sip_ppi_uri);
}
break;
case POS_PERMISSION_MISSING :
if(hdr_tree)
{
sip_element_item = sip_proto_tree_add_string(hdr_tree,
hf_header_array[hf_index], tvb,
offset, next_offset - offset,
value_offset, value_len);
sip_proto_set_format_text(hdr_tree, sip_element_item, tvb, offset, linelen);
sip_element_tree = proto_item_add_subtree( sip_element_item,
ett_sip_element);
sip_uri_offset_init(&uri_offsets);
if((dissect_sip_name_addr_or_addr_spec(tvb, pinfo, value_offset, line_end_offset+2, &uri_offsets)) != -1)
display_sip_uri(tvb, sip_element_tree, pinfo, &uri_offsets, &sip_pmiss_uri);
}
break;
case POS_TRIGGER_CONSENT :
if(hdr_tree)
{
sip_element_item = sip_proto_tree_add_string(hdr_tree,
hf_header_array[hf_index], tvb,
offset, next_offset - offset,
value_offset, value_len);
sip_proto_set_format_text(hdr_tree, sip_element_item, tvb, offset, linelen);
sip_element_tree = proto_item_add_subtree( sip_element_item,
ett_sip_element);
sip_uri_offset_init(&uri_offsets);
if((dissect_sip_uri(tvb, pinfo, value_offset, line_end_offset+2, &uri_offsets)) != -1) {
tc_uri_item_tree = display_sip_uri(tvb, sip_element_tree, pinfo, &uri_offsets, &sip_tc_uri);
if (line_end_offset > uri_offsets.uri_end) {
gint hparam_offset = uri_offsets.uri_end + 1;
if (tvb_find_guint8(tvb, hparam_offset, 1,';')) {
while ((hparam_offset != -1 && hparam_offset < line_end_offset) ) {
hparam_offset = hparam_offset + 1;
if (tvb_strncaseeql(tvb, hparam_offset, "target-uri=\"", 12) == 0) {
gint turi_start_offset = hparam_offset + 12;
gint turi_end_offset = tvb_find_guint8(tvb, turi_start_offset, -1,'\"');
if (turi_end_offset != -1)
proto_tree_add_item(tc_uri_item_tree, hf_sip_tc_turi, tvb, turi_start_offset,(turi_end_offset - turi_start_offset),ENC_UTF_8|ENC_NA);
else
break;
}
hparam_offset = tvb_find_guint8(tvb, hparam_offset, -1,';');
}
}
}
}
}
break;
case POS_CSEQ :
{
char *value = tvb_get_string_enc(wmem_packet_scope(), tvb, value_offset, value_len, ENC_UTF_8|ENC_NA);
cseq_number = (guint32)strtoul(value, NULL, 10);
cseq_number_set = 1;
stat_info->tap_cseq_number=cseq_number;
if (hdr_tree) {
sip_element_item = proto_tree_add_string(hdr_tree,
hf_header_array[hf_index], tvb,
offset, next_offset - offset,
value);
sip_proto_set_format_text(hdr_tree, sip_element_item, tvb, offset, linelen);
cseq_tree = proto_item_add_subtree(sip_element_item, ett_sip_cseq);
}
for (sub_value_offset=0; sub_value_offset < value_len; sub_value_offset++)
{
if (!isdigit((guchar)value[sub_value_offset]))
{
proto_tree_add_uint(cseq_tree, hf_sip_cseq_seq_no,
tvb, value_offset, sub_value_offset,
cseq_number);
break;
}
}
for (; sub_value_offset < value_len; sub_value_offset++)
{
if (isalpha((guchar)value[sub_value_offset]))
{
break;
}
}
if (sub_value_offset == value_len)
{
THROW(ReportedBoundsError);
return offset - orig_offset;
}
strlen_to_copy = (int)value_len-sub_value_offset;
if (strlen_to_copy > MAX_CSEQ_METHOD_SIZE) {
if (hdr_tree) {
proto_tree_add_string_format(hdr_tree,
hf_header_array[hf_index], tvb,
offset, next_offset - offset,
value+sub_value_offset, "%s String too big: %d bytes",
sip_headers[POS_CSEQ].name,
strlen_to_copy);
}
THROW(ReportedBoundsError);
return offset - orig_offset;
}
else {
g_strlcpy(cseq_method, value+sub_value_offset, MAX_CSEQ_METHOD_SIZE);
if (cseq_tree)
{
proto_tree_add_item(cseq_tree, hf_sip_cseq_method, tvb,
value_offset + sub_value_offset, strlen_to_copy, ENC_UTF_8|ENC_NA);
}
}
}
break;
case POS_RACK :
{
char *value = tvb_get_string_enc(wmem_packet_scope(), tvb, value_offset, value_len, ENC_UTF_8|ENC_NA);
int cseq_no_offset;
if (hdr_tree) {
sip_element_item = proto_tree_add_string(hdr_tree,
hf_header_array[hf_index], tvb,
offset, next_offset - offset,
value);
sip_proto_set_format_text(hdr_tree, sip_element_item, tvb, offset, linelen);
rack_tree = proto_item_add_subtree(sip_element_item, ett_sip_rack);
}
for (sub_value_offset=0; sub_value_offset < value_len; sub_value_offset++)
{
if (!isdigit((guchar)value[sub_value_offset]))
{
proto_tree_add_uint(rack_tree, hf_sip_rack_rseq_no,
tvb, value_offset, sub_value_offset,
(guint32)strtoul(value, NULL, 10));
break;
}
}
for ( ; sub_value_offset < value_len; sub_value_offset++)
{
if (value[sub_value_offset] != ' ' &&
value[sub_value_offset] != '\t')
{
break;
}
}
cseq_no_offset = sub_value_offset;
for ( ; sub_value_offset < value_len; sub_value_offset++)
{
if (!isdigit((guchar)value[sub_value_offset]))
{
proto_tree_add_uint(rack_tree, hf_sip_rack_cseq_no,
tvb, value_offset+cseq_no_offset,
sub_value_offset-cseq_no_offset,
(guint32)strtoul(value+cseq_no_offset, NULL, 10));
break;
}
}
for ( ; sub_value_offset < value_len; sub_value_offset++)
{
if (isalpha((guchar)value[sub_value_offset]))
{
break;
}
}
if (sub_value_offset == linelen)
{
THROW(ReportedBoundsError);
return offset - orig_offset;
}
if (cseq_tree)
{
proto_tree_add_item(rack_tree, hf_sip_rack_cseq_method, tvb,
value_offset + sub_value_offset,
(int)value_len-sub_value_offset, ENC_UTF_8|ENC_NA);
}
break;
}
case POS_CALL_ID :
{
char *value = tvb_get_string_enc(wmem_packet_scope(), tvb, value_offset, value_len, ENC_UTF_8|ENC_NA);
g_strlcpy(call_id, value, MAX_CALL_ID_SIZE);
stat_info->tap_call_id = wmem_strdup(wmem_packet_scope(), call_id);
sip_element_item = proto_tree_add_string(hdr_tree,
hf_header_array[hf_index], tvb,
offset, next_offset - offset,
value);
sip_proto_set_format_text(hdr_tree, sip_element_item, tvb, offset, linelen);
}
break;
case POS_EXPIRES :
if (tvb_strneql(tvb, value_offset, "0", value_len) == 0)
{
expires_is_0 = 1;
}
sip_proto_tree_add_uint(hdr_tree,
hf_header_array[hf_index], tvb,
offset, next_offset - offset,
value_offset, value_len);
break;
case POS_CONTENT_TYPE :
sip_element_item = sip_proto_tree_add_string(hdr_tree,
hf_header_array[hf_index], tvb,
offset, next_offset - offset,
value_offset, value_len);
sip_proto_set_format_text(hdr_tree, sip_element_item, tvb, offset, linelen);
content_type_len = value_len;
semi_colon_offset = tvb_find_guint8(tvb, value_offset, value_len, ';');
if ( semi_colon_offset != -1) {
gint content_type_end;
parameter_offset = tvb_skip_wsp(tvb, semi_colon_offset +1, value_offset + value_len - (semi_colon_offset +1));
content_type_end = tvb_skip_wsp_return(tvb, semi_colon_offset-1);
content_type_len = content_type_end - value_offset;
content_type_parameter_str_len = value_offset + value_len - parameter_offset;
content_type_parameter_str = tvb_get_string_enc(wmem_packet_scope(), tvb, parameter_offset,
content_type_parameter_str_len, ENC_UTF_8|ENC_NA);
}
media_type_str_lower_case = ascii_strdown_inplace(
(gchar *)tvb_get_string_enc(wmem_packet_scope(), tvb, value_offset, content_type_len, ENC_UTF_8|ENC_NA));
break;
case POS_CONTENT_LENGTH :
{
char *value = tvb_get_string_enc(wmem_packet_scope(), tvb, value_offset, value_len, ENC_UTF_8|ENC_NA);
content_length = atoi(value);
sip_element_item = proto_tree_add_uint(hdr_tree,
hf_header_array[hf_index], tvb,
offset, next_offset - offset,
content_length);
sip_proto_set_format_text(hdr_tree, sip_element_item, tvb, offset, linelen);
break;
}
case POS_MAX_BREADTH :
case POS_MAX_FORWARDS :
case POS_RSEQ :
sip_proto_tree_add_uint(hdr_tree,
hf_header_array[hf_index], tvb,
offset, next_offset - offset,
value_offset, value_len);
break;
case POS_CONTACT :
sip_element_item = sip_proto_tree_add_string(hdr_tree,
hf_header_array[hf_index], tvb,
offset, next_offset - offset,
value_offset, value_len);
sip_proto_set_format_text(hdr_tree, sip_element_item, tvb, offset, linelen);
sip_element_tree = proto_item_add_subtree( sip_element_item,
ett_sip_element);
c = tvb_get_guint8(tvb, value_offset);
if (c =='*'){
contact_is_star = 1;
break;
}
{
comma_offset = value_offset;
while((comma_offset = dissect_sip_contact_item(tvb, pinfo, sip_element_tree, comma_offset,
next_offset, &contacts_expires_0, &contacts_expires_unknown)) != -1)
{
contacts++;
if(comma_offset == next_offset)
{
break;
}
if(tvb_get_guint8(tvb, comma_offset) != ',')
{
break;
}
comma_offset++;
}
}
break;
case POS_AUTHORIZATION:
case POS_WWW_AUTHENTICATE:
case POS_PROXY_AUTHENTICATE:
case POS_PROXY_AUTHORIZATION:
case POS_AUTHENTICATION_INFO:
if (hdr_tree) {
proto_item *ti_c;
sip_element_item = sip_proto_tree_add_string(hdr_tree,
hf_header_array[hf_index], tvb,
offset, next_offset - offset,
value_offset, value_len);
sip_proto_set_format_text(hdr_tree, sip_element_item, tvb, offset, linelen);
sip_element_tree = proto_item_add_subtree( sip_element_item,
ett_sip_element);
ti_c = proto_tree_add_item(hdr_tree, hf_sip_auth, tvb,
offset, next_offset-offset,
ENC_UTF_8|ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti_c);
if (hf_index != POS_AUTHENTICATION_INFO)
{
comma_offset = tvb_pbrk_guint8(tvb, value_offset, line_end_offset - value_offset, " \t\r\n", NULL);
proto_tree_add_item(sip_element_tree, hf_sip_auth_scheme,
tvb, value_offset, comma_offset - value_offset,
ENC_UTF_8|ENC_NA);
}else{
comma_offset = value_offset;
}
while ((comma_offset = dissect_sip_authorization_item(tvb, sip_element_tree, comma_offset, line_end_offset)) != -1)
{
if(comma_offset == line_end_offset)
{
break;
}
if(tvb_get_guint8(tvb, comma_offset) != ',')
{
break;
}
comma_offset++;
}
}
break;
case POS_ROUTE:
if (hdr_tree) {
sip_element_item = sip_proto_tree_add_string(hdr_tree,
hf_header_array[hf_index], tvb,
offset, next_offset - offset,
value_offset, value_len);
sip_proto_set_format_text(hdr_tree, sip_element_item, tvb, offset, linelen);
route_tree = proto_item_add_subtree(sip_element_item, ett_sip_route);
dissect_sip_route_header(tvb, route_tree, pinfo, &sip_route_uri, value_offset, line_end_offset);
}
break;
case POS_RECORD_ROUTE:
if (hdr_tree) {
sip_element_item = sip_proto_tree_add_string(hdr_tree,
hf_header_array[hf_index], tvb,
offset, next_offset - offset,
value_offset, value_len);
sip_proto_set_format_text(hdr_tree, sip_element_item, tvb, offset, linelen);
route_tree = proto_item_add_subtree(sip_element_item, ett_sip_route);
dissect_sip_route_header(tvb, route_tree, pinfo, &sip_record_route_uri, value_offset, line_end_offset);
}
break;
case POS_SERVICE_ROUTE:
if (hdr_tree) {
sip_element_item = sip_proto_tree_add_string(hdr_tree,
hf_header_array[hf_index], tvb,
offset, next_offset - offset,
value_offset, value_len);
sip_proto_set_format_text(hdr_tree, sip_element_item, tvb, offset, linelen);
route_tree = proto_item_add_subtree(sip_element_item, ett_sip_route);
dissect_sip_route_header(tvb, route_tree, pinfo, &sip_service_route_uri, value_offset, line_end_offset);
}
break;
case POS_VIA:
if (hdr_tree) {
sip_element_item = sip_proto_tree_add_string(hdr_tree,
hf_header_array[hf_index], tvb,
offset, next_offset - offset,
value_offset, value_len);
sip_proto_set_format_text(hdr_tree, sip_element_item, tvb, offset, linelen);
via_tree = proto_item_add_subtree(sip_element_item, ett_sip_via);
dissect_sip_via_header(tvb, via_tree, value_offset, line_end_offset);
}
break;
case POS_REASON:
if(hdr_tree) {
sip_element_item = sip_proto_tree_add_string(hdr_tree,
hf_header_array[hf_index], tvb,
offset, next_offset - offset,
value_offset, value_len);
sip_proto_set_format_text(hdr_tree, sip_element_item, tvb, offset, linelen);
reason_tree = proto_item_add_subtree(sip_element_item, ett_sip_reason);
dissect_sip_reason_header(tvb, reason_tree, value_offset, line_end_offset);
}
break;
case POS_CONTENT_ENCODING:
sip_element_item = sip_proto_tree_add_string(hdr_tree,
hf_header_array[hf_index], tvb,
offset, next_offset - offset,
value_offset, value_len);
sip_proto_set_format_text(hdr_tree, sip_element_item, tvb, offset, linelen);
content_encoding_parameter_str = ascii_strdown_inplace(tvb_get_string_enc(wmem_packet_scope(), tvb, value_offset,
(line_end_offset-value_offset), ENC_UTF_8|ENC_NA));
break;
case POS_SECURITY_CLIENT:
sip_element_item = sip_proto_tree_add_string(hdr_tree,
hf_header_array[hf_index], tvb,
offset, next_offset - offset,
value_offset, value_len);
sip_proto_set_format_text(hdr_tree, sip_element_item, tvb, offset, linelen);
comma_offset = tvb_find_guint8(tvb, value_offset, line_end_offset - value_offset, ',');
while(comma_offset<line_end_offset){
comma_offset = tvb_find_guint8(tvb, value_offset, line_end_offset - value_offset, ',');
if(comma_offset == -1){
comma_offset = line_end_offset;
}
security_client_tree = proto_item_add_subtree(sip_element_item, ett_sip_security_client);
dissect_sip_sec_mechanism(tvb, pinfo, security_client_tree, value_offset, comma_offset);
comma_offset = value_offset = comma_offset+1;
}
break;
case POS_SECURITY_SERVER:
sip_element_item = sip_proto_tree_add_string(hdr_tree,
hf_header_array[hf_index], tvb,
offset, next_offset - offset,
value_offset, value_len);
sip_proto_set_format_text(hdr_tree, sip_element_item, tvb, offset, linelen);
comma_offset = tvb_find_guint8(tvb, value_offset, line_end_offset - value_offset, ',');
while(comma_offset<line_end_offset){
comma_offset = tvb_find_guint8(tvb, value_offset, line_end_offset - value_offset, ',');
if(comma_offset == -1){
comma_offset = line_end_offset;
}
security_client_tree = proto_item_add_subtree(sip_element_item, ett_sip_security_server);
dissect_sip_sec_mechanism(tvb, pinfo, security_client_tree, value_offset, comma_offset);
comma_offset = value_offset = comma_offset+1;
}
break;
case POS_SECURITY_VERIFY:
sip_element_item = sip_proto_tree_add_string(hdr_tree,
hf_header_array[hf_index], tvb,
offset, next_offset - offset,
value_offset, value_len);
sip_proto_set_format_text(hdr_tree, sip_element_item, tvb, offset, linelen);
comma_offset = tvb_find_guint8(tvb, value_offset, line_end_offset - value_offset, ',');
while(comma_offset<line_end_offset){
comma_offset = tvb_find_guint8(tvb, value_offset, line_end_offset - value_offset, ',');
if(comma_offset == -1){
comma_offset = line_end_offset;
}
security_client_tree = proto_item_add_subtree(sip_element_item, ett_sip_security_verify);
dissect_sip_sec_mechanism(tvb, pinfo, security_client_tree, value_offset, comma_offset);
comma_offset = value_offset = comma_offset+1;
}
break;
default :
sip_element_item = sip_proto_tree_add_string(hdr_tree,
hf_header_array[hf_index], tvb,
offset, next_offset - offset,
value_offset, value_len);
sip_proto_set_format_text(hdr_tree, sip_element_item, tvb, offset, linelen);
break;
}
}
}
if (is_no_header_termination == TRUE){
proto_tree_add_expert(hdr_tree, pinfo, &ei_sip_header_not_terminated,
tvb, line_end_offset, -1);
}
remaining_length = remaining_length - (next_offset - offset);
offset = next_offset;
}
datalen = tvb_captured_length_remaining(tvb, offset);
reported_datalen = tvb_reported_length_remaining(tvb, offset);
if (content_length != -1) {
if (datalen > content_length)
datalen = content_length;
if (reported_datalen > content_length)
reported_datalen = content_length;
}
if (expires_is_0) {
contacts_expires_0 += contacts_expires_unknown;
}
if (current_method_idx == SIP_METHOD_REGISTER)
{
if (contact_is_star && expires_is_0)
{
col_append_str(pinfo->cinfo, COL_INFO, " (remove all bindings)");
}
else
if (contacts_expires_0 > 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, " (remove %d binding%s)",
contacts_expires_0, contacts_expires_0 == 1 ? "":"s");
if (contacts > contacts_expires_0) {
col_append_fstr(pinfo->cinfo, COL_INFO, " (add %d binding%s)",
contacts - contacts_expires_0,
(contacts - contacts_expires_0 == 1) ? "":"s");
}
}
else
if (!contacts)
{
col_append_str(pinfo->cinfo, COL_INFO, " (fetch bindings)");
}
else
{
col_append_fstr(pinfo->cinfo, COL_INFO, " (%d binding%s)",
contacts, contacts == 1 ? "":"s");
}
}
if (line_type == STATUS_LINE && (strcmp(cseq_method, "REGISTER") == 0) &&
stat_info && stat_info->response_code > 199 && stat_info->response_code < 300)
{
if (contacts_expires_0 > 0) {
col_append_fstr(pinfo->cinfo, COL_INFO, " (removed %d binding%s)",
contacts_expires_0, contacts_expires_0 == 1 ? "":"s");
if (contacts > contacts_expires_0) {
col_append_fstr(pinfo->cinfo, COL_INFO, " (%d binding%s kept)",
contacts - contacts_expires_0,
(contacts - contacts_expires_0 == 1) ? "":"s");
}
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, " (%d binding%s)",
contacts, contacts == 1 ? "":"s");
}
}
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_set_fence(pinfo->cinfo, COL_INFO);
if ((line_type == REQUEST_LINE)&&(strcmp(cseq_method, "ACK") == 0))
{
request_for_response = sip_find_invite(pinfo, cseq_method, call_id,
cseq_number_set, cseq_number,
&response_time);
stat_info->setup_time = response_time;
}
resend_for_packet = sip_is_packet_resend(pinfo, cseq_method, call_id,
cseq_number_set, cseq_number,
line_type);
stat_info->resend = (resend_for_packet > 0);
if (line_type == STATUS_LINE)
{
request_for_response = sip_find_request(pinfo, cseq_method, call_id,
cseq_number_set, cseq_number,
&response_time);
}
if (datalen > 0) {
proto_item_set_end(th, tvb, offset);
if(content_encoding_parameter_str != NULL &&
(!strncmp(content_encoding_parameter_str, "gzip", 4) ||
!strncmp(content_encoding_parameter_str,"deflate",7))){
next_tvb = tvb_uncompress(tvb, offset, datalen);
if (next_tvb) {
add_new_data_source(pinfo, next_tvb, "gunziped data");
if(sip_tree) {
ti_a = proto_tree_add_item(sip_tree, hf_sip_msg_body, next_tvb, 0, -1,
ENC_NA);
message_body_tree = proto_item_add_subtree(ti_a, ett_sip_message_body);
}
} else {
next_tvb = tvb_new_subset(tvb, offset, datalen, reported_datalen);
if(sip_tree) {
ti_a = proto_tree_add_item(sip_tree, hf_sip_msg_body, next_tvb, 0, -1,
ENC_NA);
message_body_tree = proto_item_add_subtree(ti_a, ett_sip_message_body);
}
}
}else{
next_tvb = tvb_new_subset(tvb, offset, datalen, reported_datalen);
if(sip_tree) {
ti_a = proto_tree_add_item(sip_tree, hf_sip_msg_body, next_tvb, 0, -1,
ENC_NA);
message_body_tree = proto_item_add_subtree(ti_a, ett_sip_message_body);
}
}
if ( media_type_str_lower_case != NULL ) {
void *save_private_data = pinfo->private_data;
pinfo->private_data = content_type_parameter_str;
if (!strcmp(media_type_str_lower_case, "application/sdp")) {
if (resend_for_packet == 0) {
if (line_type == REQUEST_LINE) {
DPRINT(("calling setup_sdp_transport() SDP_EXCHANGE_OFFER frame=%d",
pinfo->fd->num));
DINDENT();
setup_sdp_transport(next_tvb, pinfo, SDP_EXCHANGE_OFFER, pinfo->fd->num, sip_delay_sdp_changes);
DENDENT();
} else if (line_type == STATUS_LINE) {
if (stat_info->response_code >= 400) {
DPRINT(("calling setup_sdp_transport() SDP_EXCHANGE_ANSWER_REJECT "
"request_frame=%d, this=%d",
request_for_response, pinfo->fd->num));
DINDENT();
setup_sdp_transport(next_tvb, pinfo, SDP_EXCHANGE_ANSWER_REJECT, request_for_response, sip_delay_sdp_changes);
DENDENT();
}
else if ((stat_info->response_code >= 200) && (stat_info->response_code <= 299)) {
DPRINT(("calling setup_sdp_transport() SDP_EXCHANGE_ANSWER_ACCEPT "
"request_frame=%d, this=%d",
request_for_response, pinfo->fd->num));
DINDENT();
setup_sdp_transport(next_tvb, pinfo, SDP_EXCHANGE_ANSWER_ACCEPT, request_for_response, sip_delay_sdp_changes);
DENDENT();
}
}
} else {
DPRINT(("calling setup_sdp_transport() resend_for_packet "
"request_frame=%d, this=%d",
request_for_response, pinfo->fd->num));
DINDENT();
setup_sdp_transport_resend(pinfo->fd->num, resend_for_packet);
DENDENT();
}
}
DPRINT(("calling dissector_try_string()"));
DINDENT();
found_match = dissector_try_string(media_type_dissector_table,
media_type_str_lower_case,
next_tvb, pinfo,
message_body_tree, NULL);
DENDENT();
DPRINT(("done calling dissector_try_string() with found_match=%s",
found_match?"TRUE":"FALSE"));
if (!found_match &&
!strncmp(media_type_str_lower_case, "multipart/", sizeof("multipart/")-1)) {
DPRINT(("calling dissector_try_string() for multipart"));
DINDENT();
found_match = dissector_try_string(media_type_dissector_table,
"multipart/",
next_tvb, pinfo,
message_body_tree, NULL);
DENDENT();
DPRINT(("done calling dissector_try_string() with found_match=%s",
found_match?"TRUE":"FALSE"));
}
pinfo->private_data = save_private_data;
}
if ( found_match != TRUE )
{
DPRINT(("calling dissector_try_heuristic() with found_match=%s",
found_match?"TRUE":"FALSE"));
DINDENT();
if (!(dissector_try_heuristic(heur_subdissector_list,
next_tvb, pinfo, message_body_tree, &hdtbl_entry, NULL))) {
int tmp_offset = 0;
while (tvb_offset_exists(next_tvb, tmp_offset)) {
tvb_find_line_end(next_tvb, tmp_offset, -1, &next_offset, FALSE);
linelen = next_offset - tmp_offset;
proto_tree_add_format_text(message_body_tree, next_tvb,
tmp_offset, linelen);
tmp_offset = next_offset;
}
}
DENDENT();
}
offset += datalen;
}
if (reqresp_tree)
{
proto_item *item;
item = proto_tree_add_boolean(reqresp_tree, hf_sip_resend, tvb, orig_offset, 0,
resend_for_packet > 0);
PROTO_ITEM_SET_GENERATED(item);
if (resend_for_packet > 0)
{
item = proto_tree_add_uint(reqresp_tree, hf_sip_original_frame,
tvb, orig_offset, 0, resend_for_packet);
PROTO_ITEM_SET_GENERATED(item);
}
if (request_for_response > 0)
{
item = proto_tree_add_uint(reqresp_tree, hf_sip_matching_request_frame,
tvb, orig_offset, 0, request_for_response);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_uint(reqresp_tree, hf_sip_response_time,
tvb, orig_offset, 0, response_time);
PROTO_ITEM_SET_GENERATED(item);
if ((line_type == STATUS_LINE)&&(strcmp(cseq_method, "BYE") == 0)){
item = proto_tree_add_uint(reqresp_tree, hf_sip_release_time,
tvb, orig_offset, 0, response_time);
PROTO_ITEM_SET_GENERATED(item);
}
}
}
if (ts != NULL)
proto_item_set_len(ts, offset - orig_offset);
if (global_sip_raw_text)
tvb_raw_text_add(tvb, orig_offset, offset - orig_offset, tree);
if (!pinfo->flags.in_error_pkt)
{
tap_queue_packet(sip_tap, pinfo, stat_info);
if(have_tap_listener(exported_pdu_tap)){
export_sip_pdu(pinfo,tvb);
}
}
if (stat_info->request_method) {
proto_item_append_text(ts, " (%s)", stat_info->request_method);
}
else {
proto_item_append_text(ts, " (%u)", stat_info->response_code);
}
return offset - orig_offset;
}
static void
dfilter_sip_request_line(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, gint offset, guint meth_len, gint linelen)
{
char *value;
guint parameter_len = meth_len;
uri_offset_info uri_offsets;
value = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, parameter_len, ENC_UTF_8|ENC_NA);
stat_info->request_method = value;
if (tree) {
proto_tree_add_string(tree, hf_sip_Method, tvb, offset, parameter_len, value);
offset=offset + parameter_len+1;
sip_uri_offset_init(&uri_offsets);
uri_offsets.uri_end = tvb_find_guint8(tvb, offset, linelen, ' ')-1;
dissect_sip_uri(tvb, pinfo, offset, offset + linelen, &uri_offsets);
display_sip_uri(tvb, tree, pinfo, &uri_offsets, &sip_req_uri);
}
}
static void
dfilter_sip_status_line(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, gint line_end, gint offset)
{
gint response_code = 0;
int diag_len;
tvbuff_t *next_tvb;
response_code = atoi((char*)tvb_get_string_enc(wmem_packet_scope(), tvb, offset + SIP2_HDR_LEN + 1, 3, ENC_UTF_8|ENC_NA));
if (tree) {
proto_tree_add_uint(tree, hf_sip_Status_Code, tvb, offset + SIP2_HDR_LEN + 1,
3, response_code);
}
stat_info->response_code = response_code;
offset = SIP2_HDR_LEN + 1 + 3 + 1;
diag_len = line_end - offset;
if((diag_len) <= 0)
return;
if(sip_diag_handle){
next_tvb = tvb_new_subset_length(tvb, offset, diag_len);
call_dissector(sip_diag_handle, next_tvb, pinfo, tree);
}
}
static line_type_t
sip_parse_line(tvbuff_t *tvb, int offset, gint linelen, guint *token_1_lenp)
{
gint space_offset;
gint token_1_start;
guint token_1_len;
gint token_2_start;
guint token_2_len;
gint token_3_start;
guint token_3_len;
gint colon_pos;
token_1_start = offset;
space_offset = tvb_find_guint8(tvb, token_1_start, -1, ' ');
if ((space_offset == -1) || (space_offset == token_1_start)) {
return OTHER_LINE;
}
token_1_len = space_offset - token_1_start;
token_2_start = space_offset + 1;
space_offset = tvb_find_guint8(tvb, token_2_start, -1, ' ');
if (space_offset == -1) {
return OTHER_LINE;
}
token_2_len = space_offset - token_2_start;
token_3_start = space_offset + 1;
token_3_len = token_1_start + linelen - token_3_start;
*token_1_lenp = token_1_len;
if ( (strict_sip_version && (
token_1_len == SIP2_HDR_LEN
&& tvb_strneql(tvb, token_1_start, SIP2_HDR, SIP2_HDR_LEN) == 0)
) || (! strict_sip_version && (
tvb_strncaseeql(tvb, token_1_start, "SIP/", 4) == 0)
)) {
if (token_2_len != 3) {
return OTHER_LINE;
}
if (!isdigit(tvb_get_guint8(tvb, token_2_start)) ||
!isdigit(tvb_get_guint8(tvb, token_2_start + 1)) ||
!isdigit(tvb_get_guint8(tvb, token_2_start + 2))) {
return OTHER_LINE;
}
return STATUS_LINE;
} else {
if (token_2_len < 3) {
return OTHER_LINE;
}
colon_pos = tvb_find_guint8(tvb, token_2_start + 1, -1, ':');
if (colon_pos == -1) {
return OTHER_LINE;
}
if (colon_pos >= token_3_start) {
return OTHER_LINE;
}
if ( (strict_sip_version && (
token_3_len != SIP2_HDR_LEN
|| tvb_strneql(tvb, token_3_start, SIP2_HDR, SIP2_HDR_LEN) == -1)
) || (! strict_sip_version && (
tvb_strncaseeql(tvb, token_3_start, "SIP/", 4) == -1)
)) {
return OTHER_LINE;
}
return REQUEST_LINE;
}
}
static gboolean sip_is_known_request(tvbuff_t *tvb, int meth_offset,
guint meth_len, guint *meth_idx)
{
guint i;
gchar *meth_name;
meth_name = tvb_get_string_enc(wmem_packet_scope(), tvb, meth_offset, meth_len, ENC_UTF_8|ENC_NA);
for (i = 1; i < array_length(sip_methods); i++) {
if (meth_len == strlen(sip_methods[i]) &&
strncmp(meth_name, sip_methods[i], meth_len) == 0)
{
*meth_idx = i;
return TRUE;
}
}
return FALSE;
}
static gint sip_is_known_sip_header(gchar *header_name, guint header_len)
{
guint pos;
if(header_len>1){
pos = GPOINTER_TO_UINT(g_hash_table_lookup(sip_headers_hash, header_name));
if (pos!=0)
return pos;
}
for (pos = 1; pos < array_length(sip_headers); pos++) {
if (sip_headers[pos].compact_name != NULL &&
header_len == strlen(sip_headers[pos].compact_name) &&
g_ascii_strncasecmp(header_name, sip_headers[pos].compact_name, header_len) == 0)
return pos;
}
return -1;
}
static void
tvb_raw_text_add(tvbuff_t *tvb, int offset, int length, proto_tree *tree)
{
proto_tree *raw_tree = NULL;
proto_item *ti = NULL;
int next_offset, linelen, end_offset;
char *str;
if (tree) {
ti = proto_tree_add_item(tree, proto_raw_sip, tvb, offset, length, ENC_NA);
raw_tree = proto_item_add_subtree(ti, ett_raw_text);
}
end_offset = offset + length;
while (offset < end_offset) {
tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
linelen = next_offset - offset;
if (raw_tree) {
if (global_sip_raw_text_without_crlf)
str = tvb_format_text_wsp(tvb, offset, linelen);
else
str = tvb_format_text(tvb, offset, linelen);
proto_tree_add_string_format(raw_tree, hf_sip_raw_line, tvb, offset, linelen,
str,
"%s",
str);
}
offset = next_offset;
}
}
guint sip_is_packet_resend(packet_info *pinfo,
gchar *cseq_method,
gchar *call_id,
guchar cseq_number_set,
guint32 cseq_number, line_type_t line_type)
{
guint32 cseq_to_compare = 0;
sip_hash_key key;
sip_hash_key *p_key = 0;
sip_hash_value *p_val = 0;
sip_frame_result_value *sip_frame_result = NULL;
guint result = 0;
if (pinfo->ptype != PT_UDP)
{
return 0;
}
if (pinfo->flags.in_error_pkt)
{
return 0;
}
if (!cseq_number_set)
{
return 0;
}
if (pinfo->fd->flags.visited)
{
sip_frame_result = (sip_frame_result_value*)p_get_proto_data(wmem_file_scope(), pinfo, proto_sip, pinfo->curr_layer_num);
if (sip_frame_result != NULL)
{
return sip_frame_result->original_frame_num;
}
else
{
return 0;
}
}
g_strlcpy(key.call_id, call_id, MAX_CALL_ID_SIZE);
SET_ADDRESS(&key.dest_address, pinfo->net_dst.type, pinfo->net_dst.len,
pinfo->net_dst.data);
SET_ADDRESS(&key.source_address, pinfo->net_src.type,
pinfo->net_src.len, pinfo->net_src.data);
key.dest_port = pinfo->destport;
if (sip_retrans_the_same_sport) {
key.source_port = pinfo->srcport;
} else {
key.source_port = MAGIC_SOURCE_PORT;
}
p_val = (sip_hash_value*)g_hash_table_lookup(sip_hash, &key);
if (p_val)
{
cseq_to_compare = p_val->cseq;
if (cseq_number != p_val->cseq)
{
p_val->cseq = cseq_number;
g_strlcpy(p_val->method, cseq_method, MAX_CSEQ_METHOD_SIZE);
p_val->transaction_state = nothing_seen;
p_val->frame_number = 0;
if (line_type == REQUEST_LINE)
{
p_val->request_time = pinfo->fd->abs_ts;
}
}
}
else
{
p_key = wmem_new(wmem_file_scope(), sip_hash_key);
p_val = wmem_new0(wmem_file_scope(), sip_hash_value);
g_snprintf(p_key->call_id, MAX_CALL_ID_SIZE, "%s", call_id);
SE_COPY_ADDRESS(&(p_key->dest_address), &pinfo->net_dst);
SE_COPY_ADDRESS(&(p_key->source_address), &pinfo->net_src);
p_key->dest_port = pinfo->destport;
if (sip_retrans_the_same_sport) {
p_key->source_port = pinfo->srcport;
} else {
p_key->source_port = MAGIC_SOURCE_PORT;
}
p_val->cseq = cseq_number;
g_strlcpy(p_val->method, cseq_method, MAX_CSEQ_METHOD_SIZE);
p_val->transaction_state = nothing_seen;
if (line_type == REQUEST_LINE)
{
p_val->request_time = pinfo->fd->abs_ts;
}
g_hash_table_insert(sip_hash, p_key, p_val);
cseq_to_compare = 0;
}
if ((line_type == REQUEST_LINE) && (cseq_number == cseq_to_compare) &&
(p_val->transaction_state == request_seen) &&
(strcmp(cseq_method, p_val->method) == 0) &&
(strcmp(cseq_method, "ACK") != 0) &&
(strcmp(cseq_method, "CANCEL") != 0))
{
result = p_val->frame_number;
}
if ((line_type == STATUS_LINE) && (cseq_number == cseq_to_compare) &&
(p_val->transaction_state == final_response_seen) &&
(strcmp(cseq_method, p_val->method) == 0) &&
(stat_info->response_code >= 200) &&
(stat_info->response_code == p_val->response_code))
{
result = p_val->frame_number;
}
p_val->cseq = cseq_number;
switch (line_type)
{
case REQUEST_LINE:
p_val->transaction_state = request_seen;
if (!result)
{
p_val->frame_number = pinfo->fd->num;
}
break;
case STATUS_LINE:
if (stat_info->response_code >= 200)
{
p_val->response_code = stat_info->response_code;
p_val->transaction_state = final_response_seen;
if (!result)
{
p_val->frame_number = pinfo->fd->num;
}
}
else
{
p_val->transaction_state = provisional_response_seen;
}
break;
default:
break;
}
sip_frame_result = (sip_frame_result_value *)p_get_proto_data(wmem_file_scope(), pinfo, proto_sip, pinfo->curr_layer_num);
if (sip_frame_result == NULL)
{
sip_frame_result = wmem_new0(wmem_file_scope(), sip_frame_result_value);
p_add_proto_data(wmem_file_scope(), pinfo, proto_sip, pinfo->curr_layer_num, sip_frame_result);
}
sip_frame_result->original_frame_num = result;
return result;
}
guint sip_find_request(packet_info *pinfo,
gchar *cseq_method,
gchar *call_id,
guchar cseq_number_set,
guint32 cseq_number,
guint32 *response_time)
{
guint32 cseq_to_compare = 0;
sip_hash_key key;
sip_hash_value *p_val = 0;
sip_frame_result_value *sip_frame_result = NULL;
guint result = 0;
gint seconds_between_packets;
gint nseconds_between_packets;
if (pinfo->ptype != PT_UDP)
{
return 0;
}
if (pinfo->flags.in_error_pkt)
{
return 0;
}
if (!cseq_number_set)
{
return 0;
}
if (pinfo->fd->flags.visited)
{
sip_frame_result = (sip_frame_result_value*)p_get_proto_data(wmem_file_scope(), pinfo, proto_sip, pinfo->curr_layer_num);
if (sip_frame_result != NULL)
{
*response_time = sip_frame_result->response_time;
return sip_frame_result->response_request_frame_num;
}
else
{
return 0;
}
}
g_strlcpy(key.call_id, call_id, MAX_CALL_ID_SIZE);
SET_ADDRESS(&key.dest_address, pinfo->net_src.type, pinfo->net_src.len,
pinfo->net_src.data);
SET_ADDRESS(&key.source_address, pinfo->net_dst.type, pinfo->net_dst.len,
pinfo->net_dst.data);
key.dest_port = pinfo->srcport;
key.source_port = pinfo->destport;
p_val = (sip_hash_value*)g_hash_table_lookup(sip_hash, &key);
if (p_val)
{
cseq_to_compare = p_val->cseq;
}
else
{
return 0;
}
if ((cseq_number == cseq_to_compare) &&
(p_val->transaction_state == request_seen) &&
(strcmp(cseq_method, p_val->method) == 0))
{
result = p_val->frame_number;
}
sip_frame_result = (sip_frame_result_value *)p_get_proto_data(wmem_file_scope(), pinfo, proto_sip, pinfo->curr_layer_num);
if (sip_frame_result == NULL)
{
sip_frame_result = wmem_new0(wmem_file_scope(), sip_frame_result_value);
p_add_proto_data(wmem_file_scope(), pinfo, proto_sip, pinfo->curr_layer_num, sip_frame_result);
}
sip_frame_result->response_request_frame_num = result;
seconds_between_packets = (gint)
(pinfo->fd->abs_ts.secs - p_val->request_time.secs);
nseconds_between_packets =
pinfo->fd->abs_ts.nsecs - p_val->request_time.nsecs;
sip_frame_result->response_time = (seconds_between_packets*1000) +
(nseconds_between_packets / 1000000);
*response_time = sip_frame_result->response_time;
return result;
}
guint sip_find_invite(packet_info *pinfo,
gchar *cseq_method _U_,
gchar *call_id,
guchar cseq_number_set,
guint32 cseq_number _U_,
guint32 *response_time)
{
#if 0
guint32 cseq_to_compare = 0;
#endif
sip_hash_key key;
sip_hash_value *p_val = 0;
sip_frame_result_value *sip_frame_result = NULL;
guint result = 0;
gint seconds_between_packets;
gint nseconds_between_packets;
if (pinfo->ptype != PT_UDP)
{
return 0;
}
if (pinfo->flags.in_error_pkt)
{
return 0;
}
if (!cseq_number_set)
{
return 0;
}
if (pinfo->fd->flags.visited)
{
sip_frame_result = (sip_frame_result_value*)p_get_proto_data(wmem_file_scope(), pinfo, proto_sip, pinfo->curr_layer_num);
if (sip_frame_result != NULL)
{
*response_time = sip_frame_result->response_time;
return sip_frame_result->response_request_frame_num;
}
else
{
return 0;
}
}
g_strlcpy(key.call_id, call_id, MAX_CALL_ID_SIZE);
SET_ADDRESS(&key.dest_address, pinfo->net_dst.type, pinfo->net_dst.len,
pinfo->net_dst.data);
SET_ADDRESS(&key.source_address, pinfo->net_src.type, pinfo->net_src.len,
pinfo->net_src.data);
key.dest_port = pinfo->destport;
key.source_port = pinfo->srcport;
p_val = (sip_hash_value*)g_hash_table_lookup(sip_hash, &key);
if (p_val)
{
#if 0
cseq_to_compare = p_val->cseq;
#endif
}
else
{
return 0;
}
#if 0
if ((cseq_number == cseq_to_compare) &&
(p_val->transaction_state == request_seen) &&
(strcmp(cseq_method, p_val->method) == 0))
{
result = p_val->frame_number;
}
#endif
result = p_val->frame_number;
sip_frame_result = (sip_frame_result_value *)p_get_proto_data(wmem_file_scope(), pinfo, proto_sip, pinfo->curr_layer_num);
if (sip_frame_result == NULL)
{
sip_frame_result = wmem_new0(wmem_file_scope(), sip_frame_result_value);
p_add_proto_data(wmem_file_scope(), pinfo, proto_sip, pinfo->curr_layer_num, sip_frame_result);
}
sip_frame_result->response_request_frame_num = result;
seconds_between_packets = (gint)
(pinfo->fd->abs_ts.secs - p_val->request_time.secs);
nseconds_between_packets =
pinfo->fd->abs_ts.nsecs - p_val->request_time.nsecs;
sip_frame_result->response_time = (seconds_between_packets*1000) +
(nseconds_between_packets / 1000000);
*response_time = sip_frame_result->response_time;
return result;
}
void proto_register_sip(void)
{
static hf_register_info hf[] = {
{ &hf_sip_msg_hdr,
{ "Message Header", "sip.msg_hdr",
FT_STRING, BASE_NONE, NULL, 0,
"Message Header in SIP message", HFILL }
},
{ &hf_sip_Method,
{ "Method", "sip.Method",
FT_STRING, BASE_NONE,NULL,0x0,
"SIP Method", HFILL }
},
{ &hf_Request_Line,
{ "Request-Line", "sip.Request-Line",
FT_STRING, BASE_NONE,NULL,0x0,
"SIP Request-Line", HFILL }
},
{ &hf_sip_ruri,
{ "Request-URI", "sip.r-uri",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: SIP R-URI", HFILL }
},
{ &hf_sip_ruri_user,
{ "Request-URI User Part", "sip.r-uri.user",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: SIP R-URI User", HFILL }
},
{ &hf_sip_ruri_host,
{ "Request-URI Host Part", "sip.r-uri.host",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: SIP R-URI Host", HFILL }
},
{ &hf_sip_ruri_port,
{ "Request-URI Host Port", "sip.r-uri.port",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: SIP R-URI Port", HFILL }
},
{ &hf_sip_ruri_param,
{ "Request URI parameter", "sip.r-uri.param",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_sip_Status_Code,
{ "Status-Code", "sip.Status-Code",
FT_UINT32, BASE_DEC,NULL,0x0,
"SIP Status Code", HFILL }
},
{ &hf_sip_Status_Line,
{ "Status-Line", "sip.Status-Line",
FT_STRING, BASE_NONE,NULL,0x0,
"SIP Status-Line", HFILL }
},
{ &hf_sip_display,
{ "SIP Display info", "sip.display.info",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Display info", HFILL }
},
{ &hf_sip_to_addr,
{ "SIP to address", "sip.to.addr",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: To Address", HFILL }
},
{ &hf_sip_to_user,
{ "SIP to address User Part", "sip.to.user",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: To Address User", HFILL }
},
{ &hf_sip_to_host,
{ "SIP to address Host Part", "sip.to.host",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: To Address Host", HFILL }
},
{ &hf_sip_to_port,
{ "SIP to address Host Port", "sip.to.port",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: To Address Port", HFILL }
},
{ &hf_sip_to_param,
{ "SIP To URI parameter", "sip.to.param",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_sip_to_tag,
{ "SIP to tag", "sip.to.tag",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: to tag", HFILL }
},
{ &hf_sip_from_addr,
{ "SIP from address", "sip.from.addr",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: From Address", HFILL }
},
{ &hf_sip_from_user,
{ "SIP from address User Part", "sip.from.user",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: From Address User", HFILL }
},
{ &hf_sip_from_host,
{ "SIP from address Host Part", "sip.from.host",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: From Address Host", HFILL }
},
{ &hf_sip_from_port,
{ "SIP from address Host Port", "sip.from.port",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: From Address Port", HFILL }
},
{ &hf_sip_from_param,
{ "SIP From URI parameter", "sip.from.param",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_sip_from_tag,
{ "SIP from tag", "sip.from.tag",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: from tag", HFILL }
},
{ &hf_sip_curi,
{ "Contact URI", "sip.contact.uri",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: SIP C-URI", HFILL }
},
{ &hf_sip_curi_user,
{ "Contact URI User Part", "sip.contact.user",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: SIP C-URI User", HFILL }
},
{ &hf_sip_curi_host,
{ "Contact URI Host Part", "sip.contact.host",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: SIP C-URI Host", HFILL }
},
{ &hf_sip_curi_port,
{ "Contact URI Host Port", "sip.contact.port",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: SIP C-URI Port", HFILL }
},
{ &hf_sip_curi_param,
{ "Contact URI parameter", "sip.contact.param",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_sip_route,
{ "Route URI", "sip.Route.uri",
FT_STRING, BASE_NONE,NULL,0x0,NULL,HFILL }
},
{ &hf_sip_route_user,
{ "Route Userinfo", "sip.Route.user",
FT_STRING, BASE_NONE,NULL,0x0,NULL,HFILL }
},
{ &hf_sip_route_host,
{ "Route Host Part", "sip.Route.host",
FT_STRING, BASE_NONE,NULL,0x0,NULL,HFILL }
},
{ &hf_sip_route_port,
{ "Route Host Port", "sip.Route.port",
FT_STRING, BASE_NONE,NULL,0x0,NULL,HFILL }
},
{ &hf_sip_route_param,
{ "Route URI parameter", "sip.Route.param",
FT_STRING, BASE_NONE,NULL,0x0,NULL,HFILL }
},
{ &hf_sip_record_route,
{ "Record-Route URI", "sip.Record-Route.uri",
FT_STRING, BASE_NONE,NULL,0x0,NULL,HFILL }
},
{ &hf_sip_record_route_user,
{ "Record-Route Userinfo", "sip.Record-Route.user",
FT_STRING, BASE_NONE,NULL,0x0,NULL,HFILL }
},
{ &hf_sip_record_route_host,
{ "Record-Route Host Part", "sip.Record-Route.host",
FT_STRING, BASE_NONE,NULL,0x0,NULL,HFILL }
},
{ &hf_sip_record_route_port,
{ "Record-Route Host Port", "sip.Record-Route.port",
FT_STRING, BASE_NONE,NULL,0x0,NULL,HFILL }
},
{ &hf_sip_record_route_param,
{ "Record-Route URI parameter", "sip.Record-Route.param",
FT_STRING, BASE_NONE,NULL,0x0,NULL,HFILL }
},
{ &hf_sip_service_route,
{ "Service-Route URI", "sip.Service-Route.uri",
FT_STRING, BASE_NONE,NULL,0x0,NULL,HFILL }
},
{ &hf_sip_service_route_user,
{ "Service-Route Userinfo", "sip.Service-Route.user",
FT_STRING, BASE_NONE,NULL,0x0,NULL,HFILL }
},
{ &hf_sip_service_route_host,
{ "Service-Route Host Part", "sip.Service-Route.host",
FT_STRING, BASE_NONE,NULL,0x0,NULL,HFILL }
},
{ &hf_sip_service_route_port,
{ "Service-Route Host Port", "sip.Service-Route.port",
FT_STRING, BASE_NONE,NULL,0x0,NULL,HFILL }
},
{ &hf_sip_service_route_param,
{ "Service-Route URI parameter", "sip.Service-Route.param",
FT_STRING, BASE_NONE,NULL,0x0,NULL,HFILL }
},
{ &hf_sip_contact_param,
{ "Contact parameter", "sip.contact.parameter",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: one contact parameter", HFILL }
},
{ &hf_sip_tag,
{ "SIP tag", "sip.tag",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: tag", HFILL }
},
{ &hf_sip_pai_addr,
{ "SIP PAI Address", "sip.pai.addr",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3325: P-Asserted-Identity Address", HFILL }
},
{ &hf_sip_pai_user,
{ "SIP PAI User Part", "sip.pai.user",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3325: P-Asserted-Identity User", HFILL }
},
{ &hf_sip_pai_host,
{ "SIP PAI Host Part", "sip.pai.host",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3325: P-Asserted-Identity Host", HFILL }
},
{ &hf_sip_pai_port,
{ "SIP PAI Host Port", "sip.pai.port",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3325: P-Asserted-Identity Port", HFILL }
},
{ &hf_sip_pai_param,
{ "SIP PAI URI parameter", "sip.pai.param",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_sip_pmiss_addr,
{ "SIP PMISS Address", "sip.pmiss.addr",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3325: Permission Missing Address", HFILL }
},
{ &hf_sip_pmiss_user,
{ "SIP PMISS User Part", "sip.pmiss.user",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3325: Permission Missing User", HFILL }
},
{ &hf_sip_pmiss_host,
{ "SIP PMISS Host Part", "sip.pmiss.host",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3325: Permission Missing Host", HFILL }
},
{ &hf_sip_pmiss_port,
{ "SIP PMISS Host Port", "sip.pmiss.port",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3325: Permission Missing Port", HFILL }
},
{ &hf_sip_pmiss_param,
{ "SIP PMISS URI parameter", "sip.pmiss.param",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_sip_ppi_addr,
{ "SIP PPI Address", "sip.ppi.addr",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3325: P-Preferred-Identity Address", HFILL }
},
{ &hf_sip_ppi_user,
{ "SIP PPI User Part", "sip.ppi.user",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3325: P-Preferred-Identity User", HFILL }
},
{ &hf_sip_ppi_host,
{ "SIP PPI Host Part", "sip.ppi.host",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3325: P-Preferred-Identity Host", HFILL }
},
{ &hf_sip_ppi_port,
{ "SIP PPI Host Port", "sip.ppi.port",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3325: P-Preferred-Identity Port", HFILL }
},
{ &hf_sip_ppi_param,
{ "SIP PPI URI parameter", "sip.ppi.param",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_sip_tc_addr,
{ "SIP TC Address", "sip.tc.addr",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3325: Trigger Consent Address", HFILL }
},
{ &hf_sip_tc_user,
{ "SIP TC User Part", "sip.tc.user",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3325: Trigger Consent User", HFILL }
},
{ &hf_sip_tc_host,
{ "SIP TC Host Part", "sip.tc.host",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3325: Trigger Consent Host", HFILL }
},
{ &hf_sip_tc_port,
{ "SIP TC Host Port", "sip.tc.port",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3325: Trigger Consent Port", HFILL }
},
{ &hf_sip_tc_param,
{ "SIP TC URI parameter", "sip.tc.param",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_sip_tc_turi,
{ "SIP TC Target URI", "sip.tc.target-uri",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3325: Trigger Consent Target URI", HFILL }
},
{ &hf_header_array[POS_ACCEPT],
{ "Accept", "sip.Accept",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Accept Header", HFILL }
},
{ &hf_header_array[POS_ACCEPT_CONTACT],
{ "Accept-Contact", "sip.Accept-Contact",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3841: Accept-Contact Header", HFILL }
},
{ &hf_header_array[POS_ACCEPT_ENCODING],
{ "Accept-Encoding", "sip.Accept-Encoding",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3841: Accept-Encoding Header", HFILL }
},
{ &hf_header_array[POS_ACCEPT_LANGUAGE],
{ "Accept-Language", "sip.Accept-Language",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Accept-Language Header", HFILL }
},
{ &hf_header_array[POS_ACCEPT_RESOURCE_PRIORITY],
{ "Accept-Resource-Priority", "sip.Accept-Resource-Priority",
FT_STRING, BASE_NONE,NULL,0x0,
"Draft: Accept-Resource-Priority Header", HFILL }
},
{ &hf_header_array[POS_ALERT_INFO],
{ "Alert-Info", "sip.Alert-Info",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Alert-Info Header", HFILL }
},
{ &hf_header_array[POS_ALLOW],
{ "Allow", "sip.Allow",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Allow Header", HFILL }
},
{ &hf_header_array[POS_ALLOW_EVENTS],
{ "Allow-Events", "sip.Allow-Events",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3265: Allow-Events Header", HFILL }
},
{ &hf_header_array[POS_ANSWER_MODE],
{ "Answer-Mode", "sip.Answer-Mode",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 5373: Answer-Mode Header", HFILL }
},
{ &hf_header_array[POS_AUTHENTICATION_INFO],
{ "Authentication-Info", "sip.Authentication-Info",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Authentication-Info Header", HFILL }
},
{ &hf_header_array[POS_AUTHORIZATION],
{ "Authorization", "sip.Authorization",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Authorization Header", HFILL }
},
{ &hf_header_array[POS_CALL_ID],
{ "Call-ID", "sip.Call-ID",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Call-ID Header", HFILL }
},
{ &hf_header_array[POS_CALL_INFO],
{ "Call-Info", "sip.Call-Info",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Call-Info Header", HFILL }
},
{ &hf_header_array[POS_CONTACT],
{ "Contact", "sip.Contact",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Contact Header", HFILL }
},
{ &hf_header_array[POS_CONTENT_DISPOSITION],
{ "Content-Disposition", "sip.Content-Disposition",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Content-Disposition Header", HFILL }
},
{ &hf_header_array[POS_CONTENT_ENCODING],
{ "Content-Encoding", "sip.Content-Encoding",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Content-Encoding Header", HFILL }
},
{ &hf_header_array[POS_CONTENT_LANGUAGE],
{ "Content-Language", "sip.Content-Language",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Content-Language Header", HFILL }
},
{ &hf_header_array[POS_CONTENT_LENGTH],
{ "Content-Length", "sip.Content-Length",
FT_UINT32, BASE_DEC,NULL,0x0,
"RFC 3261: Content-Length Header", HFILL }
},
{ &hf_header_array[POS_CONTENT_TYPE],
{ "Content-Type", "sip.Content-Type",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Content-Type Header", HFILL }
},
{ &hf_header_array[POS_CSEQ],
{ "CSeq", "sip.CSeq",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: CSeq Header", HFILL }
},
{ &hf_header_array[POS_DATE],
{ "Date", "sip.Date",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Date Header", HFILL }
},
{ &hf_header_array[POS_ERROR_INFO],
{ "Error-Info", "sip.Error-Info",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Error-Info Header", HFILL }
},
{ &hf_header_array[POS_EVENT],
{ "Event", "sip.Event",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3265: Event Header", HFILL }
},
{ &hf_header_array[POS_EXPIRES],
{ "Expires", "sip.Expires",
FT_UINT32, BASE_DEC,NULL,0x0,
"RFC 3261: Expires Header", HFILL }
},
{ &hf_header_array[POS_FEATURE_CAPS],
{ "Feature-Caps", "sip.feature_caps",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 6809: Feature-Caps", HFILL }
},
{ &hf_header_array[POS_FLOW_TIMER],
{ "Flow-Timer", "sip.Flow-Timer",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 5626: Flow-Timer", HFILL }
},
{ &hf_header_array[POS_FROM],
{ "From", "sip.From",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: From Header", HFILL }
},
{ &hf_header_array[POS_GEOLOCATION],
{ "Geolocation", "sip.Geolocation",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_header_array[POS_GEOLOCATION_ERROR],
{ "Geolocation-Error", "sip.Geolocation",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_header_array[POS_GEOLOCATION_ROUTING],
{ "Geolocation-Routing", "sip.Geolocation_Routing",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_header_array[POS_HISTORY_INFO],
{ "History-Info", "sip.History-Info",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 4244: Request History Information", HFILL }
},
{ &hf_header_array[POS_IDENTITY],
{ "Identity", "sip.Identity",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 4474: Request Identity", HFILL }
},
{ &hf_header_array[POS_IDENTITY_INFO],
{ "Identity-info", "sip.Identity-info",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 4474: Request Identity-info", HFILL }
},
{ &hf_header_array[POS_INFO_PKG],
{ "Info-Package", "sip.Info-Package",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_header_array[POS_IN_REPLY_TO],
{ "In-Reply-To", "sip.In-Reply-To",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: In-Reply-To Header", HFILL }
},
{ &hf_header_array[POS_JOIN],
{ "Join", "sip.Join",
FT_STRING, BASE_NONE,NULL,0x0,
"Draft: Join Header", HFILL }
},
{ &hf_header_array[POS_MAX_BREADTH],
{ "Max-Breadth", "sip.Max-Breadth",
FT_UINT32, BASE_DEC,NULL,0x0,
"RFC 5393: Max-Breadth Header", HFILL }
},
{ &hf_header_array[POS_MAX_FORWARDS],
{ "Max-Forwards", "sip.Max-Forwards",
FT_UINT32, BASE_DEC,NULL,0x0,
"RFC 3261: Max-Forwards Header", HFILL }
},
{ &hf_header_array[POS_MIME_VERSION],
{ "MIME-Version", "sip.MIME-Version",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: MIME-Version Header", HFILL }
},
{ &hf_header_array[POS_MIN_EXPIRES],
{ "Min-Expires", "sip.Min-Expires",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Min-Expires Header", HFILL }
},
{ &hf_header_array[POS_MIN_SE],
{ "Min-SE", "sip.Min-SE",
FT_STRING, BASE_NONE,NULL,0x0,
"Draft: Min-SE Header", HFILL }
},
{ &hf_header_array[POS_ORGANIZATION],
{ "Organization", "sip.Organization",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Organization Header", HFILL }
},
{ &hf_header_array[POS_P_ACCESS_NETWORK_INFO],
{ "P-Access-Network-Info", "sip.P-Access-Network-Info",
FT_STRING, BASE_NONE,NULL,0x0,
"P-Access-Network-Info Header", HFILL }
},
{ &hf_header_array[POS_P_ANSWER_STATE],
{ "P-Answer-State", "sip.P-Answer-State",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 4964: P-Answer-State Header", HFILL }
},
{ &hf_header_array[POS_P_ASSERTED_IDENTITY],
{ "P-Asserted-Identity", "sip.P-Asserted-Identity",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3325: P-Asserted-Identity Header", HFILL }
},
{ &hf_header_array[POS_P_ASSERTED_SERV],
{ "P-Asserted-Service", "sip.P-Asserted-Service",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_header_array[POS_P_ASSOCIATED_URI],
{ "P-Associated-URI", "sip.P-Associated-URI",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3455: P-Associated-URI Header", HFILL }
},
{ &hf_header_array[POS_P_CALLED_PARTY_ID],
{ "P-Called-Party-ID", "sip.P-Called-Party-ID",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3455: P-Called-Party-ID Header", HFILL }
},
{ &hf_header_array[POS_P_CHARGING_FUNC_ADDRESSES],
{ "P-Charging-Function-Addresses","sip.P-Charging-Function-Addresses",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_header_array[POS_P_CHARGING_VECTOR],
{ "P-Charging-Vector", "sip.P-Charging-Vector",
FT_STRING, BASE_NONE,NULL,0x0,
"P-Charging-Vector Header", HFILL }
},
{ &hf_header_array[POS_P_DCS_TRACE_PARTY_ID],
{ "P-DCS-Trace-Party-ID", "sip.P-DCS-Trace-Party-ID",
FT_STRING, BASE_NONE,NULL,0x0,
"P-DCS-Trace-Party-ID Header", HFILL }
},
{ &hf_header_array[POS_P_DCS_OSPS],
{ "P-DCS-OSPS", "sip.P-DCS-OSPS",
FT_STRING, BASE_NONE,NULL,0x0,
"P-DCS-OSPS Header", HFILL }
},
{ &hf_header_array[POS_P_DCS_BILLING_INFO],
{ "P-DCS-Billing-Info", "sip.P-DCS-Billing-Info",
FT_STRING, BASE_NONE,NULL,0x0,
"P-DCS-Billing-Info Header", HFILL }
},
{ &hf_header_array[POS_P_DCS_LAES],
{ "P-DCS-LAES", "sip.P-DCS-LAES",
FT_STRING, BASE_NONE,NULL,0x0,
"P-DCS-LAES Header", HFILL }
},
{ &hf_header_array[POS_P_DCS_REDIRECT],
{ "P-DCS-Redirect", "sip.P-DCS-Redirect",
FT_STRING, BASE_NONE,NULL,0x0,
"P-DCS-Redirect Header", HFILL }
},
{ &hf_header_array[POS_P_EARLY_MEDIA],
{ "P-Early-Media", "sip.P-Early-Media",
FT_STRING, BASE_NONE,NULL,0x0,
"P-Early-Media Header", HFILL }
},
{ &hf_header_array[POS_P_MEDIA_AUTHORIZATION],
{ "P-Media-Authorization", "sip.P-Media-Authorization",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3313: P-Media-Authorization Header", HFILL }
},
{ &hf_header_array[POS_P_PREFERRED_IDENTITY],
{ "P-Preferred-Identity", "sip.P-Preferred-Identity",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3325: P-Preferred-Identity Header", HFILL }
},
{ &hf_header_array[POS_P_PREFERRED_SERV],
{ "P-Preferred-Service", "sip.P-Preferred-Service",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_header_array[POS_P_PROFILE_KEY],
{ "P-Profile-Key", "sip.P-Profile-Key",
FT_STRING, BASE_NONE,NULL,0x0,
"P-Profile-Key Header", HFILL }
},
{ &hf_header_array[POS_P_REFUSED_URI_LST],
{ "P-Refused-URI-List", "sip.P-Refused-URI-List",
FT_STRING, BASE_NONE,NULL,0x0,
"P-Refused-URI-List Header", HFILL }
},
{ &hf_header_array[POS_P_SERVED_USER],
{ "P-Served-User", "sip.P-Served-User",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_header_array[POS_P_USER_DATABASE],
{ "P-User-Database", "sip.P-User-Database",
FT_STRING, BASE_NONE,NULL,0x0,
"P-User-Database Header", HFILL }
},
{ &hf_header_array[POS_P_VISITED_NETWORK_ID],
{ "P-Visited-Network-ID", "sip.P-Visited-Network-ID",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3455: P-Visited-Network-ID Header", HFILL }
},
{ &hf_header_array[POS_PATH],
{ "Path", "sip.Path",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3327: Path Header", HFILL }
},
{ &hf_header_array[POS_PERMISSION_MISSING],
{ "Permission-Missing", "sip.Permission-Missing",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 5360: Permission Missing Header", HFILL }
},
{ &hf_header_array[POS_POLICY_CONTACT],
{ "Policy-Contact", "sip.Policy_Contact",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_header_array[POS_POLICY_ID],
{ "Policy-ID", "sip.Policy_ID",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_header_array[POS_PRIORITY],
{ "Priority", "sip.Priority",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Priority Header", HFILL }
},
{ &hf_header_array[POS_PRIV_ANSWER_MODE],
{ "Priv-Answer-mode", "sip.Priv-Answer-mode",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_header_array[POS_PRIVACY],
{ "Privacy", "sip.Privacy",
FT_STRING, BASE_NONE,NULL,0x0,
"Privacy Header", HFILL }
},
{ &hf_header_array[POS_PROXY_AUTHENTICATE],
{ "Proxy-Authenticate", "sip.Proxy-Authenticate",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Proxy-Authenticate Header", HFILL }
},
{ &hf_header_array[POS_PROXY_AUTHORIZATION],
{ "Proxy-Authorization", "sip.Proxy-Authorization",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Proxy-Authorization Header", HFILL }
},
{ &hf_header_array[POS_PROXY_REQUIRE],
{ "Proxy-Require", "sip.Proxy-Require",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Proxy-Require Header", HFILL }
},
{ &hf_header_array[POS_RACK],
{ "RAck", "sip.RAck",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3262: RAck Header", HFILL }
},
{ &hf_header_array[POS_REASON],
{ "Reason", "sip.Reason",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3326 Reason Header", HFILL }
},
{ &hf_header_array[POS_REASON_PHRASE],
{ "Reason-Phrase", "sip.Reason-Phrase",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_header_array[POS_RECORD_ROUTE],
{ "Record-Route", "sip.Record-Route",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Record-Route Header", HFILL }
},
{ &hf_header_array[POS_RECV_INFO],
{ "Recv-Info", "sip.Recv-Info",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_header_array[POS_REFER_SUB],
{ "Refer-Sub", "sip.Refer-Sub",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 4488: Refer-Sub Header", HFILL }
},
{ &hf_header_array[POS_REFER_TO],
{ "Refer-To", "sip.Refer-To",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3515: Refer-To Header", HFILL }
},
{ &hf_header_array[POS_REFERED_BY],
{ "Refered By", "sip.Refered-by",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3892: Refered-by Header", HFILL }
},
{ &hf_header_array[POS_REJECT_CONTACT],
{ "Reject-Contact", "sip.Reject-Contact",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3841: Reject-Contact Header", HFILL }
},
{ &hf_header_array[POS_REPLACES],
{ "Replaces", "sip.Replaces",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3891: Replaces Header", HFILL }
},
{ &hf_header_array[POS_REPLY_TO],
{ "Reply-To", "sip.Reply-To",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Reply-To Header", HFILL }
},
{ &hf_header_array[POS_REQUEST_DISPOSITION],
{ "Request-Disposition", "sip.Request-Disposition",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3841: Request-Disposition Header", HFILL }
},
{ &hf_header_array[POS_REQUIRE],
{ "Require", "sip.Require",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Require Header", HFILL }
},
{ &hf_header_array[POS_RESOURCE_PRIORITY],
{ "Resource-Priority", "sip.Resource-Priority",
FT_STRING, BASE_NONE,NULL,0x0,
"Draft: Resource-Priority Header", HFILL }
},
{ &hf_header_array[POS_RETRY_AFTER],
{ "Retry-After", "sip.Retry-After",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Retry-After Header", HFILL }
},
{ &hf_header_array[POS_ROUTE],
{ "Route", "sip.Route",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Route Header", HFILL }
},
{ &hf_header_array[POS_RSEQ],
{ "RSeq", "sip.RSeq",
FT_UINT32, BASE_DEC,NULL,0x0,
"RFC 3262: RSeq Header", HFILL }
},
{ &hf_header_array[ POS_SECURITY_CLIENT],
{ "Security-Client", "sip.Security-Client",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3329 Security-Client Header", HFILL }
},
{ &hf_header_array[ POS_SECURITY_SERVER],
{ "Security-Server", "sip.Security-Server",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3329 Security-Server Header", HFILL }
},
{ &hf_header_array[ POS_SECURITY_VERIFY],
{ "Security-Verify", "sip.Security-Verify",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3329 Security-Verify Header", HFILL }
},
{ &hf_header_array[POS_SERVER],
{ "Server", "sip.Server",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Server Header", HFILL }
},
{ &hf_header_array[POS_SERVICE_ROUTE],
{ "Service-Route", "sip.Service-Route",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3608: Service-Route Header", HFILL }
},
{ &hf_header_array[POS_SESSION_EXPIRES],
{ "Session-Expires", "sip.Session-Expires",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 4028: Session-Expires Header", HFILL }
},
{ &hf_header_array[POS_SIP_ETAG],
{ "ETag", "sip.ETag",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3903: SIP-ETag Header", HFILL }
},
{ &hf_header_array[POS_SIP_IF_MATCH],
{ "If_Match", "sip.If_Match",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3903: SIP-If-Match Header", HFILL }
},
{ &hf_header_array[POS_SUBJECT],
{ "Subject", "sip.Subject",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Subject Header", HFILL }
},
{ &hf_header_array[POS_SUBSCRIPTION_STATE],
{ "Subscription-State", "sip.Subscription-State",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3265: Subscription-State Header", HFILL }
},
{ &hf_header_array[POS_SUPPORTED],
{ "Supported", "sip.Supported",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Supported Header", HFILL }
},
{ &hf_header_array[POS_SUPPRESS_IF_MATCH],
{ "Suppress-If-Match", "sip.Suppress_If_Match",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_header_array[POS_TARGET_DIALOG],
{ "Target-Dialog", "sip.Target-Dialog",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 4538: Target-Dialog Header", HFILL }
},
{ &hf_header_array[POS_TIMESTAMP],
{ "Timestamp", "sip.Timestamp",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Timestamp Header", HFILL }
},
{ &hf_header_array[POS_TO],
{ "To", "sip.To",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: To Header", HFILL }
},
{ &hf_header_array[POS_TRIGGER_CONSENT],
{ "Trigger-Consent", "sip.Trigger-Consent",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 5380: Trigger Consent", HFILL }
},
{ &hf_header_array[POS_UNSUPPORTED],
{ "Unsupported", "sip.Unsupported",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Unsupported Header", HFILL }
},
{ &hf_header_array[POS_USER_AGENT],
{ "User-Agent", "sip.User-Agent",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: User-Agent Header", HFILL }
},
{ &hf_header_array[POS_VIA],
{ "Via", "sip.Via",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Via Header", HFILL }
},
{ &hf_header_array[POS_WARNING],
{ "Warning", "sip.Warning",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: Warning Header", HFILL }
},
{ &hf_header_array[POS_WWW_AUTHENTICATE],
{ "WWW-Authenticate", "sip.WWW-Authenticate",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 3261: WWW-Authenticate Header", HFILL }
},
{ &hf_header_array[POS_DIVERSION],
{ "Diversion", "sip.Diversion",
FT_STRING, BASE_NONE,NULL,0x0,
"RFC 5806: Diversion Header", HFILL }
},
{ &hf_header_array[POS_USER_TO_USER],
{ "User-to-User", "sip.uui",
FT_STRING, BASE_NONE,NULL,0x0,
"draft-johnston-sipping-cc-uui-09: User-to-User header", HFILL }
},
{ &hf_sip_resend,
{ "Resent Packet", "sip.resend",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sip_original_frame,
{ "Suspected resend of frame", "sip.resend-original",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Original transmission of frame", HFILL}
},
{ &hf_sip_matching_request_frame,
{ "Request Frame", "sip.response-request",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_sip_response_time,
{ "Response Time (ms)", "sip.response-time",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Response time since original request (in milliseconds)", HFILL}
},
{ &hf_sip_release_time,
{ "Release Time (ms)", "sip.release-time",
FT_UINT32, BASE_DEC, NULL, 0x0,
"release time since original BYE (in milliseconds)", HFILL}
},
{ &hf_sip_auth,
{ "Authentication", "sip.auth",
FT_STRING, BASE_NONE, NULL, 0x0,
"SIP Authentication", HFILL}
},
{ &hf_sip_auth_scheme,
{ "Authentication Scheme", "sip.auth.scheme",
FT_STRING, BASE_NONE, NULL, 0x0,
"SIP Authentication Scheme", HFILL}
},
{ &hf_sip_auth_digest_response,
{ "Digest Authentication Response", "sip.auth.digest.response",
FT_STRING, BASE_NONE, NULL, 0x0,
"SIP Digest Authentication Response Value", HFILL}
},
{ &hf_sip_auth_nc,
{ "Nonce Count", "sip.auth.nc",
FT_STRING, BASE_NONE, NULL, 0x0,
"SIP Authentication Nonce count", HFILL}
},
{ &hf_sip_auth_username,
{ "Username", "sip.auth.username",
FT_STRING, BASE_NONE, NULL, 0x0,
"SIP Authentication Username", HFILL}
},
{ &hf_sip_auth_realm,
{ "Realm", "sip.auth.realm",
FT_STRING, BASE_NONE, NULL, 0x0,
"SIP Authentication Realm", HFILL}
},
{ &hf_sip_auth_nonce,
{ "Nonce Value", "sip.auth.nonce",
FT_STRING, BASE_NONE, NULL, 0x0,
"SIP Authentication Nonce", HFILL}
},
{ &hf_sip_auth_algorithm,
{ "Algorithm", "sip.auth.algorithm",
FT_STRING, BASE_NONE, NULL, 0x0,
"SIP Authentication Algorithm", HFILL}
},
{ &hf_sip_auth_opaque,
{ "Opaque Value", "sip.auth.opaque",
FT_STRING, BASE_NONE, NULL, 0x0,
"SIP Authentication Opaque value", HFILL}
},
{ &hf_sip_auth_qop,
{ "QOP", "sip.auth.qop",
FT_STRING, BASE_NONE, NULL, 0x0,
"SIP Authentication QOP", HFILL}
},
{ &hf_sip_auth_cnonce,
{ "CNonce Value", "sip.auth.cnonce",
FT_STRING, BASE_NONE, NULL, 0x0,
"SIP Authentication Client Nonce", HFILL}
},
{ &hf_sip_auth_uri,
{ "Authentication URI", "sip.auth.uri",
FT_STRING, BASE_NONE, NULL, 0x0,
"SIP Authentication URI", HFILL}
},
{ &hf_sip_auth_domain,
{ "Authentication Domain", "sip.auth.domain",
FT_STRING, BASE_NONE, NULL, 0x0,
"SIP Authentication Domain", HFILL}
},
{ &hf_sip_auth_stale,
{ "Stale Flag", "sip.auth.stale",
FT_STRING, BASE_NONE, NULL, 0x0,
"SIP Authentication Stale Flag", HFILL}
},
{ &hf_sip_auth_auts,
{ "Authentication Token", "sip.auth.auts",
FT_STRING, BASE_NONE, NULL, 0x0,
"SIP Authentication Token", HFILL}
},
{ &hf_sip_auth_rspauth,
{ "Response auth", "sip.auth.rspauth",
FT_STRING, BASE_NONE, NULL, 0x0,
"SIP Authentication Response auth", HFILL}
},
{ &hf_sip_auth_nextnonce,
{ "Next Nonce", "sip.auth.nextnonce",
FT_STRING, BASE_NONE, NULL, 0x0,
"SIP Authentication Next Nonce", HFILL}
},
{ &hf_sip_auth_ik,
{ "Integrity Key", "sip.auth.ik",
FT_STRING, BASE_NONE, NULL, 0x0,
"SIP Authentication Integrity Key", HFILL}
},
{ &hf_sip_auth_ck,
{ "Cyphering Key", "sip.auth.ck",
FT_STRING, BASE_NONE, NULL, 0x0,
"SIP Authentication Cyphering Key", HFILL}
},
{ &hf_sip_cseq_seq_no,
{ "Sequence Number", "sip.CSeq.seq",
FT_UINT32, BASE_DEC, NULL, 0x0,
"CSeq header sequence number", HFILL}
},
{ &hf_sip_cseq_method,
{ "Method", "sip.CSeq.method",
FT_STRING, BASE_NONE, NULL, 0x0,
"CSeq header method", HFILL}
},
{ &hf_sip_via_transport,
{ "Transport", "sip.Via.transport",
FT_STRING, BASE_NONE, NULL, 0x0,
"Via header Transport", HFILL}
},
{ &hf_sip_via_sent_by_address,
{ "Sent-by Address", "sip.Via.sent-by.address",
FT_STRING, BASE_NONE, NULL, 0x0,
"Via header Sent-by Address", HFILL}
},
{ &hf_sip_via_sent_by_port,
{ "Sent-by port", "sip.Via.sent-by.port",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Via header Sent-by Port", HFILL}
},
{ &hf_sip_via_branch,
{ "Branch", "sip.Via.branch",
FT_STRING, BASE_NONE, NULL, 0x0,
"SIP Via Branch", HFILL},
},
{ &hf_sip_via_maddr,
{ "Maddr", "sip.Via.maddr",
FT_STRING, BASE_NONE, NULL, 0x0,
"SIP Via Maddr", HFILL},
},
{ &hf_sip_via_rport,
{ "RPort", "sip.Via.rport",
FT_STRING, BASE_NONE, NULL, 0x0,
"SIP Via RPort", HFILL},
},
{ &hf_sip_via_received,
{ "Received", "sip.Via.received",
FT_STRING, BASE_NONE, NULL, 0x0,
"SIP Via Received", HFILL},
},
{ &hf_sip_via_ttl,
{ "TTL", "sip.Via.ttl",
FT_STRING, BASE_NONE, NULL, 0x0,
"SIP Via TTL", HFILL}
},
{ &hf_sip_via_comp,
{ "Comp", "sip.Via.comp",
FT_STRING, BASE_NONE, NULL, 0x0,
"SIP Via comp", HFILL}
},
{ &hf_sip_via_sigcomp_id,
{ "Sigcomp identifier", "sip.Via.sigcomp-id",
FT_STRING, BASE_NONE, NULL, 0x0,
"SIP Via sigcomp identifier", HFILL}
},
{ &hf_sip_rack_rseq_no,
{ "RSeq Sequence Number", "sip.RAck.RSeq.seq",
FT_UINT32, BASE_DEC, NULL, 0x0,
"RAck RSeq header sequence number (from prov response)", HFILL}
},
{ &hf_sip_rack_cseq_no,
{ "CSeq Sequence Number", "sip.RAck.CSeq.seq",
FT_UINT32, BASE_DEC, NULL, 0x0,
"RAck CSeq header sequence number (from prov response)", HFILL}
},
{ &hf_sip_rack_cseq_method,
{ "CSeq Method", "sip.RAck.CSeq.method",
FT_STRING, BASE_NONE, NULL, 0x0,
"RAck CSeq header method (from prov response)", HFILL}
},
{ &hf_sip_msg_body,
{ "Message Body", "sip.msg_body",
FT_NONE, BASE_NONE, NULL, 0x0,
"Message Body in SIP message", HFILL }
},
{ &hf_sip_sec_mechanism,
{ "[Security-mechanism]", "sip.sec_mechanism",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_sip_sec_mechanism_alg,
{ "alg", "sip.sec_mechanism.alg",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_sip_sec_mechanism_ealg,
{ "ealg", "sip.sec_mechanism.ealg",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_sip_sec_mechanism_prot,
{ "prot", "sip.sec_mechanism.prot",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_sip_sec_mechanism_spi_c,
{ "spi-c", "sip.sec_mechanism.spi_c",
FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_sip_sec_mechanism_spi_s,
{ "spi-s", "sip.sec_mechanism.spi_s",
FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_sip_sec_mechanism_port1,
{ "port1", "sip.sec_mechanism.port1",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_sip_sec_mechanism_port_c,
{ "port-c", "sip.sec_mechanism.port_c",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_sip_sec_mechanism_port2,
{ "port2", "sip.sec_mechanism.port2",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_sip_sec_mechanism_port_s,
{ "port-s", "sip.sec_mechanism.port_s",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
}
};
static hf_register_info raw_hf[] = {
{ &hf_sip_raw_line,
{ "Raw SIP Line", "raw_sip.line",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
}};
static gint *ett[] = {
&ett_sip,
&ett_sip_reqresp,
&ett_sip_hdr,
&ett_sip_ext_hdr,
&ett_sip_element,
&ett_sip_hist,
&ett_sip_uri,
&ett_sip_contact_item,
&ett_sip_message_body,
&ett_sip_cseq,
&ett_sip_via,
&ett_sip_reason,
&ett_sip_security_client,
&ett_sip_security_server,
&ett_sip_security_verify,
&ett_sip_rack,
&ett_sip_record_route,
&ett_sip_service_route,
&ett_sip_route,
&ett_sip_ruri,
&ett_sip_pai_uri,
&ett_sip_pmiss_uri,
&ett_sip_ppi_uri,
&ett_sip_tc_uri,
&ett_sip_to_uri,
&ett_sip_from_uri,
&ett_sip_curi
};
static gint *ett_raw[] = {
&ett_raw_text,
};
static ei_register_info ei[] = {
{ &ei_sip_unrecognized_header, { "sip.unrecognized_header", PI_UNDECODED, PI_NOTE, "Unrecognised SIP header", EXPFILL }},
{ &ei_sip_header_not_terminated, { "sip.header_not_terminated", PI_MALFORMED, PI_WARN, "Header not terminated by empty line (CRLF)", EXPFILL }},
{ &ei_sip_odd_register_response, { "sip.response.unusual", PI_RESPONSE_CODE, PI_WARN, "SIP Response is unusual", EXPFILL }},
{ &ei_sip_sipsec_malformed, { "sip.sec_mechanism.malformed", PI_MALFORMED, PI_WARN, "SIP Security-mechanism header malformed", EXPFILL }},
};
module_t *sip_module;
expert_module_t* expert_sip;
proto_sip = proto_register_protocol("Session Initiation Protocol",
"SIP", "sip");
proto_raw_sip = proto_register_protocol("Session Initiation Protocol (SIP as raw text)",
"Raw_SIP", "raw_sip");
new_register_dissector("sip", dissect_sip, proto_sip);
register_dissector("sip.tcp", dissect_sip_tcp, proto_sip);
proto_register_field_array(proto_sip, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_sip = expert_register_protocol(proto_sip);
expert_register_field_array(expert_sip, ei, array_length(ei));
proto_register_subtree_array(ett_raw, array_length(ett_raw));
proto_register_field_array(proto_raw_sip, raw_hf, array_length(raw_hf));
sip_module = prefs_register_protocol(proto_sip, proto_reg_handoff_sip);
range_convert_str(&global_sip_tcp_port_range, DEFAULT_SIP_PORT_RANGE, MAX_UDP_PORT);
prefs_register_range_preference(sip_module, "tcp.ports", "SIP TCP ports",
"TCP ports to be decoded as SIP (default: "
DEFAULT_SIP_PORT_RANGE ")",
&global_sip_tcp_port_range, MAX_UDP_PORT);
prefs_register_uint_preference(sip_module, "tls.port",
"SIP TLS Port",
"SIP Server TLS Port",
10, &sip_tls_port);
prefs_register_bool_preference(sip_module, "display_raw_text",
"Display raw text for SIP message",
"Specifies that the raw text of the "
"SIP message should be displayed "
"in addition to the dissection tree",
&global_sip_raw_text);
prefs_register_bool_preference(sip_module, "display_raw_text_without_crlf",
"Don't show '\\r\\n' in raw SIP messages",
"If the raw text of the SIP message "
"is displayed, the trailing carriage "
"return and line feed are not shown",
&global_sip_raw_text_without_crlf);
prefs_register_bool_preference(sip_module, "strict_sip_version",
"Enforce strict SIP version check (" SIP2_HDR ")",
"If enabled, only " SIP2_HDR " traffic will be dissected as SIP. "
"Disable it to allow SIP traffic with a different version "
"to be dissected as SIP.",
&strict_sip_version);
prefs_register_bool_preference(sip_module, "desegment_headers",
"Reassemble SIP headers spanning multiple TCP segments",
"Whether the SIP dissector should reassemble headers "
"of a request spanning multiple TCP segments. "
"To use this option, you must also enable "
"\"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&sip_desegment_headers);
prefs_register_bool_preference(sip_module, "desegment_body",
"Reassemble SIP bodies spanning multiple TCP segments",
"Whether the SIP dissector should use the "
"\"Content-length:\" value, if present, to reassemble "
"the body of a request spanning multiple TCP segments, "
"and reassemble chunked data spanning multiple TCP segments. "
"To use this option, you must also enable "
"\"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&sip_desegment_body);
prefs_register_bool_preference(sip_module, "retrans_the_same_sport",
"Retransmissions always use the same source port",
"Whether retransmissions are detected coming from the same source port only.",
&sip_retrans_the_same_sport);
prefs_register_bool_preference(sip_module, "delay_sdp_changes",
"Delay SDP changes for tracking media",
"Whether SIP should delay tracking the media (e.g., RTP/RTCP) until an SDP offer "
"is answered. If enabled, mid-dialog changes to SDP and media state only take "
"effect if and when an SDP offer is successfully answered; however enabling this "
"prevents tracking media in early-media call scenarios",
&sip_delay_sdp_changes);
prefs_register_obsolete_preference(sip_module, "tcp.port");
register_init_routine(&sip_init_protocol);
register_heur_dissector_list("sip", &heur_subdissector_list);
sip_tap = register_tap("sip");
ext_hdr_subdissector_table = register_dissector_table("sip.hdr", "SIP Extension header", FT_STRING, BASE_NONE);
}
void
proto_reg_handoff_sip(void)
{
static range_t *sip_tcp_port_range;
static guint saved_sip_tls_port;
static gboolean sip_prefs_initialized = FALSE;
if (!sip_prefs_initialized) {
dissector_handle_t sip_handle;
sip_handle = find_dissector("sip");
sip_tcp_handle = find_dissector("sip.tcp");
sigcomp_handle = find_dissector("sigcomp");
sip_diag_handle = find_dissector("sip.diagnostic");
sip_uri_userinfo_handle = find_dissector("sip.uri_userinfo");
media_type_dissector_table = find_dissector_table("media_type");
dissector_add_uint("udp.port", UDP_PORT_SIP, sip_handle);
dissector_add_string("media_type", "message/sip", sip_handle);
heur_dissector_add("udp", dissect_sip_heur, proto_sip);
heur_dissector_add("tcp", dissect_sip_tcp_heur, proto_sip);
heur_dissector_add("sctp", dissect_sip_heur, proto_sip);
heur_dissector_add("stun", dissect_sip_heur, proto_sip);
sip_prefs_initialized = TRUE;
} else {
dissector_delete_uint_range("tcp.port", sip_tcp_port_range, sip_tcp_handle);
g_free(sip_tcp_port_range);
ssl_dissector_delete(saved_sip_tls_port, "sip.tcp", TRUE);
}
sip_tcp_port_range = range_copy(global_sip_tcp_port_range);
dissector_add_uint_range("tcp.port", sip_tcp_port_range, sip_tcp_handle);
saved_sip_tls_port = sip_tls_port;
ssl_dissector_add(saved_sip_tls_port, "sip.tcp", TRUE);
exported_pdu_tap = find_tap_id(EXPORT_PDU_TAP_NAME_LAYER_7);
}
