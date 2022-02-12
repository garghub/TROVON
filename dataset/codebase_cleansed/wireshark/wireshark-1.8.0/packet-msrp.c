void
msrp_add_address( packet_info *pinfo,
address *addr, int port,
const gchar *setup_method, guint32 setup_frame_number)
{
address null_addr;
conversation_t* p_conv;
struct _msrp_conversation_info *p_conv_data = NULL;
if (pinfo->fd->flags.visited)
{
return;
}
SET_ADDRESS(&null_addr, AT_NONE, 0, NULL);
p_conv = find_conversation( pinfo->fd->num, addr, &null_addr, PT_TCP, port, 0,
NO_ADDR_B | NO_PORT_B);
if (!p_conv) {
p_conv = conversation_new( pinfo->fd->num, addr, &null_addr, PT_TCP,
(guint32)port, 0,
NO_ADDR2 | NO_PORT2);
}
conversation_set_dissector(p_conv, msrp_handle);
p_conv_data = conversation_get_proto_data(p_conv, proto_msrp);
if (!p_conv_data) {
p_conv_data = se_alloc0(sizeof(struct _msrp_conversation_info));
conversation_add_proto_data(p_conv, proto_msrp, p_conv_data);
}
p_conv_data->setup_method_set = TRUE;
g_strlcpy(p_conv_data->setup_method, setup_method, MAX_MSRP_SETUP_METHOD_SIZE);
p_conv_data->setup_frame_number = setup_frame_number;
}
static void
show_setup_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
conversation_t *p_conv = NULL;
struct _msrp_conversation_info *p_conv_data = NULL;
p_conv_data = p_get_proto_data(pinfo->fd, proto_msrp);
if (!p_conv_data)
{
p_conv = find_conversation(pinfo->fd->num, &pinfo->net_dst, &pinfo->net_src,
PT_TCP,
pinfo->destport, pinfo->srcport, 0);
if (p_conv)
{
struct _msrp_conversation_info *p_conv_packet_data;
p_conv_data = conversation_get_proto_data(p_conv, proto_msrp);
if (p_conv_data)
{
p_conv_packet_data = se_memdup(p_conv_data,
sizeof(struct _msrp_conversation_info));
p_add_proto_data(pinfo->fd, proto_msrp, p_conv_packet_data);
}
}
}
if (p_conv_data && p_conv_data->setup_method_set)
{
proto_tree *msrp_setup_tree;
proto_item *ti = proto_tree_add_string_format(tree, hf_msrp_setup, tvb, 0, 0,
"",
"Stream setup by %s (frame %u)",
p_conv_data->setup_method,
p_conv_data->setup_frame_number);
PROTO_ITEM_SET_GENERATED(ti);
msrp_setup_tree = proto_item_add_subtree(ti, ett_msrp_setup);
if (msrp_setup_tree)
{
proto_item* item = proto_tree_add_uint(msrp_setup_tree, hf_msrp_setup_frame,
tvb, 0, 0, p_conv_data->setup_frame_number);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_string(msrp_setup_tree, hf_msrp_setup_method,
tvb, 0, 0, p_conv_data->setup_method);
PROTO_ITEM_SET_GENERATED(item);
}
}
}
static gint msrp_is_known_msrp_header(tvbuff_t *tvb, int offset, guint header_len)
{
guint i;
for (i = 1; i < array_length(msrp_headers); i++) {
if (header_len == strlen(msrp_headers[i].name) &&
tvb_strncaseeql(tvb, offset, msrp_headers[i].name, header_len) == 0)
{
return i;
}
}
return -1;
}
static void
tvb_raw_text_add(tvbuff_t *tvb, proto_tree *tree)
{
int offset, next_offset, linelen;
offset = 0;
while (tvb_offset_exists(tvb, offset)) {
tvb_find_line_end(tvb, offset, -1, &next_offset, ENC_BIG_ENDIAN);
linelen = next_offset - offset;
if(tree) {
proto_tree_add_text(tree, tvb, offset, linelen,
"%s", tvb_format_text(tvb, offset, linelen));
}
offset = next_offset;
}
}
static gboolean
check_msrp_header(tvbuff_t *tvb)
{
gint linelen;
gint space_offset;
gint next_offset = 0;
guint token_1_len;
gint token_2_start;
if(tvb_length(tvb) < 4 || tvb_get_ntohl(tvb, 0) != 0x4d535250 ){
return FALSE;
}
linelen = tvb_find_line_end(tvb, 0, -1, &next_offset, ENC_BIG_ENDIAN);
space_offset = tvb_find_guint8(tvb, 0, linelen, ' ');
if (space_offset <= 0) {
return FALSE;
}
token_1_len = space_offset;
token_2_start = space_offset + 1;
space_offset = tvb_find_guint8(tvb, token_2_start, linelen, ' ');
if (space_offset == -1) {
return FALSE;
}
if (token_1_len == MSRP_HDR_LEN) {
return TRUE;
}
return FALSE;
}
static int
find_end_line(tvbuff_t *tvb, gint start)
{
gint offset = start, next_offset, linelen;
while (tvb_length_remaining(tvb, offset) > 0) {
linelen = tvb_find_line_end(tvb, offset, -1, &next_offset, ENC_BIG_ENDIAN);
if (linelen == -1) {
return -1;
}
if (tvb_strneql(tvb, next_offset, (const gchar *)"-------", 7) == 0)
return next_offset;
offset = next_offset;
}
return -1;
}
static gboolean
dissect_msrp_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
conversation_t* conversation;
if ( check_msrp_header(tvb)){
if (pinfo->fd->flags.visited){
conversation = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst, pinfo->ptype,
pinfo->srcport, pinfo->destport, 0);
if (conversation == NULL){
conversation = conversation_new(pinfo->fd->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->srcport, pinfo->destport, 0);
conversation_set_dissector(conversation, msrp_handle);
}
}
dissect_msrp(tvb, pinfo, tree);
return TRUE;
}
return FALSE;
}
static int
dissect_msrp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gint offset = 0;
gint next_offset = 0;
proto_item *ti, *th, *msrp_headers_item;
proto_tree *msrp_tree, *reqresp_tree, *raw_tree, *msrp_hdr_tree, *msrp_end_tree;
proto_tree *msrp_data_tree;
gint linelen;
gint space_offset;
gint token_2_start;
guint token_2_len;
gint token_3_start;
guint token_3_len;
gint token_4_start = 0;
guint token_4_len = 0;
gboolean is_msrp_response;
gint end_line_offset;
gint end_line_len;
gint line_end_offset;
gint message_end_offset;
gint colon_offset;
gint header_len;
gint hf_index;
gint value_offset;
guchar c;
gint value_len;
char *value;
gboolean have_body = FALSE;
gboolean found_match = FALSE;
gint content_type_len, content_type_parameter_str_len;
gchar *media_type_str_lower_case = NULL;
char *content_type_parameter_str = NULL;
tvbuff_t *next_tvb;
gint parameter_offset;
gint semi_colon_offset;
if ( !check_msrp_header(tvb)){
return 0;
}
offset = 0;
linelen = tvb_find_line_end(tvb, 0, -1, &next_offset, ENC_BIG_ENDIAN);
token_2_start = tvb_find_guint8(tvb, 0, linelen, ' ') + 1;
space_offset = tvb_find_guint8(tvb, token_2_start, linelen-token_2_start, ' ');
token_2_len = space_offset - token_2_start;
token_3_start = space_offset + 1;
space_offset = tvb_find_guint8(tvb, token_3_start,linelen-token_3_start, ' ');
if ( space_offset == -1){
token_3_len = linelen - token_3_start;
}else{
token_3_len = space_offset - token_3_start;
token_4_start = space_offset + 1;
token_4_len = linelen - token_4_start;
}
is_msrp_response = FALSE;
if (token_3_len == 3) {
if (isdigit(tvb_get_guint8(tvb, token_3_start)) &&
isdigit(tvb_get_guint8(tvb, token_3_start + 1)) &&
isdigit(tvb_get_guint8(tvb, token_3_start + 2))) {
is_msrp_response = TRUE;
}
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MSRP");
if (is_msrp_response){
col_add_fstr(pinfo->cinfo, COL_INFO, "Response: %s ",
tvb_format_text(tvb, token_3_start, token_3_len));
if (token_4_len )
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ",
tvb_format_text(tvb, token_4_start, token_4_len));
col_append_fstr(pinfo->cinfo, COL_INFO, "Transaction ID: %s",
tvb_format_text(tvb, token_2_start, token_2_len));
}else{
proto_tree_add_text(tree, tvb, token_3_start, token_3_len,
"Col %s L=%u", tvb_format_text(tvb, token_3_start, token_3_len),token_3_len);
col_add_fstr(pinfo->cinfo, COL_INFO, "Request: %s ",
tvb_format_text(tvb, token_3_start, token_3_len));
col_append_fstr(pinfo->cinfo, COL_INFO, "Transaction ID: %s",
tvb_format_text(tvb, token_2_start, token_2_len));
}
offset = next_offset;
end_line_offset = find_end_line(tvb,offset);
end_line_len = tvb_find_line_end(tvb, end_line_offset, -1, &next_offset, ENC_BIG_ENDIAN);
message_end_offset = end_line_offset + end_line_len + 2;
if (tree) {
ti = proto_tree_add_item(tree, proto_msrp, tvb, 0, message_end_offset, ENC_NA);
msrp_tree = proto_item_add_subtree(ti, ett_msrp);
if (is_msrp_response){
th = proto_tree_add_item(msrp_tree,hf_msrp_response_line,tvb,0,linelen,ENC_ASCII|ENC_NA);
reqresp_tree = proto_item_add_subtree(th, ett_msrp_reqresp);
proto_tree_add_item(reqresp_tree,hf_msrp_transactionID,tvb,token_2_start,token_2_len,ENC_ASCII|ENC_NA);
proto_tree_add_uint(reqresp_tree,hf_msrp_status_code,tvb,token_3_start,token_3_len,
atoi(tvb_get_ephemeral_string(tvb, token_3_start, token_3_len)));
}else{
th = proto_tree_add_item(msrp_tree,hf_msrp_request_line,tvb,0,linelen,ENC_ASCII|ENC_NA);
reqresp_tree = proto_item_add_subtree(th, ett_msrp_reqresp);
proto_tree_add_item(reqresp_tree,hf_msrp_transactionID,tvb,token_2_start,token_2_len,ENC_ASCII|ENC_NA);
proto_tree_add_item(reqresp_tree,hf_msrp_method,tvb,token_3_start,token_3_len,ENC_ASCII|ENC_NA);
}
if (global_msrp_show_setup_info)
{
show_setup_info(tvb, pinfo, msrp_tree);
}
msrp_headers_item = proto_tree_add_item(msrp_tree, hf_msrp_msg_hdr, tvb, offset,(end_line_offset - offset), ENC_NA);
msrp_hdr_tree = proto_item_add_subtree(msrp_headers_item, ett_msrp_hdr);
while (tvb_reported_length_remaining(tvb, offset) > 0 && offset < end_line_offset ) {
linelen = tvb_find_line_end(tvb, offset, -1, &next_offset, ENC_BIG_ENDIAN);
if (linelen == 0) {
have_body = TRUE;
break;
}
line_end_offset = offset + linelen;
colon_offset = tvb_find_guint8(tvb, offset, linelen, ':');
if (colon_offset == -1) {
proto_tree_add_text(msrp_hdr_tree, tvb, offset,
next_offset - offset, "%s",
tvb_format_text(tvb, offset, linelen));
} else {
header_len = colon_offset - offset;
hf_index = msrp_is_known_msrp_header(tvb, offset, header_len);
if (hf_index == -1) {
proto_tree_add_text(msrp_hdr_tree, tvb,
offset, next_offset - offset, "%s",
tvb_format_text(tvb, offset, linelen));
} else {
value_offset = colon_offset + 1;
while (value_offset < line_end_offset &&
((c = tvb_get_guint8(tvb, value_offset)) == ' ' ||
c == '\t'))
value_offset++;
value_len = line_end_offset - value_offset;
value = tvb_get_ephemeral_string(tvb, value_offset,
value_len);
proto_tree_add_string_format(msrp_hdr_tree,
hf_header_array[hf_index], tvb,
offset, next_offset - offset,
value, "%s",
tvb_format_text(tvb, offset, linelen));
switch ( hf_index ) {
case MSRP_CONTENT_TYPE :
content_type_len = value_len;
semi_colon_offset = tvb_find_guint8(tvb, value_offset,linelen, ';');
if ( semi_colon_offset != -1) {
parameter_offset = semi_colon_offset +1;
while (parameter_offset < line_end_offset
&& ((c = tvb_get_guint8(tvb, parameter_offset)) == ' '
|| c == '\t'))
parameter_offset++;
content_type_len = semi_colon_offset - value_offset;
content_type_parameter_str_len = line_end_offset - parameter_offset;
content_type_parameter_str = tvb_get_ephemeral_string(tvb,
parameter_offset, content_type_parameter_str_len);
}
media_type_str_lower_case = ascii_strdown_inplace(
(gchar *)tvb_get_ephemeral_string(tvb, value_offset, content_type_len));
break;
default:
break;
}
}
}
offset = next_offset;
}
if ( have_body ){
proto_item_set_end(msrp_headers_item, tvb, next_offset);
next_tvb = tvb_new_subset_remaining(tvb, next_offset);
ti = proto_tree_add_item(msrp_tree, hf_msrp_data, tvb,
next_offset, -1, ENC_ASCII|ENC_NA);
msrp_data_tree = proto_item_add_subtree(ti, ett_msrp_data);
if ( media_type_str_lower_case != NULL ) {
void *save_private_data = pinfo->private_data;
pinfo->private_data = content_type_parameter_str;
found_match = dissector_try_string(media_type_dissector_table,
media_type_str_lower_case,
next_tvb, pinfo,
msrp_data_tree);
pinfo->private_data = save_private_data;
}
if ( found_match != TRUE )
{
offset = 0;
while (tvb_offset_exists(next_tvb, offset)) {
tvb_find_line_end(next_tvb, offset, -1, &next_offset, ENC_BIG_ENDIAN);
linelen = next_offset - offset;
proto_tree_add_text(msrp_data_tree, next_tvb, offset, linelen,
"%s", tvb_format_text(next_tvb, offset, linelen));
offset = next_offset;
}
}
}
ti = proto_tree_add_item(msrp_tree,hf_msrp_end_line,tvb,end_line_offset,end_line_len,ENC_ASCII|ENC_NA);
msrp_end_tree = proto_item_add_subtree(ti, ett_msrp_end_line);
proto_tree_add_item(msrp_end_tree,hf_msrp_transactionID,tvb,end_line_offset + 7,token_2_len,ENC_ASCII|ENC_NA);
proto_tree_add_item(msrp_end_tree,hf_msrp_cnt_flg,tvb,end_line_offset+end_line_len-1,1,ENC_ASCII|ENC_NA);
if (global_msrp_raw_text){
ti = proto_tree_add_text(tree, tvb, 0, -1,"Message Session Relay Protocol(as raw text)");
raw_tree = proto_item_add_subtree(ti, ett_msrp);
tvb_raw_text_add(tvb,raw_tree);
}
}
return message_end_offset;
}
void
proto_register_msrp(void)
{
static gint *ett[] = {
&ett_msrp,
&ett_raw_text,
&ett_msrp_reqresp,
&ett_msrp_hdr,
&ett_msrp_data,
&ett_msrp_end_line,
&ett_msrp_setup
};
static hf_register_info hf[] = {
{ &hf_msrp_request_line,
{ "Request Line", "msrp.request.line",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_msrp_response_line,
{ "Response Line", "msrp.response.line",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_msrp_transactionID,
{ "Transaction Id", "msrp.transaction.id",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_msrp_method,
{ "Method", "msrp.method",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_msrp_status_code,
{ "Status code", "msrp.status.code",
FT_UINT16, BASE_DEC,NULL,0x0,
NULL, HFILL }
},
{ &hf_msrp_msg_hdr,
{ "Message Header", "msrp.msg.hdr",
FT_NONE, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_msrp_end_line,
{ "End Line", "msrp.end.line",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_msrp_cnt_flg,
{ "Continuation-flag", "msrp.cnt.flg",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_header_array[MSRP_FROM_PATH],
{ "From Path", "msrp.from.path",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_header_array[MSRP_TO_PATH],
{ "To Path", "msrp.to.path",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_header_array[MSRP_MESSAGE_ID],
{ "Message ID", "msrp.messageid",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_header_array[MSRP_SUCCESS_REPORT],
{ "Success Report", "msrp.success.report",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_header_array[MSRP_FAILURE_REPORT],
{ "Failure Report", "msrp.failure.report",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_header_array[MSRP_BYTE_RANGE],
{ "Byte Range", "msrp.byte.range",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_header_array[MSRP_STATUS],
{ "Status", "msrp.status",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_header_array[MSRP_CONTENT_TYPE],
{ "Content-Type", "msrp.content.type",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_header_array[MSRP_CONTENT_ID],
{ "Content-ID", "msrp.content.id",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_header_array[MSRP_CONTENT_DISCRIPTION],
{ "Content-Description", "msrp.content.description",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_header_array[MSRP_CONTENT_DISPOSITION],
{ "Content-Disposition", "msrp.content.disposition",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_header_array[MSRP_USE_PATH],
{ "Use-Path", "msrp.use.path",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_header_array[MSRP_WWW_AUTHENTICATE],
{ "WWW-Authenticate", "msrp.www.authenticate",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_header_array[MSRP_AUTHORIZATION],
{ "Authorization", "msrp.authorization",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_header_array[MSRP_AUTHENTICATION_INFO],
{ "Authentication-Info", "msrp.authentication.info",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_msrp_data,
{ "Data", "msrp.data",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_msrp_setup,
{ "Stream setup", "msrp.setup",
FT_STRING, BASE_NONE, NULL, 0x0,
"Stream setup, method and frame number", HFILL}
},
{ &hf_msrp_setup_frame,
{ "Setup frame", "msrp.setup-frame",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Frame that set up this stream", HFILL}
},
{ &hf_msrp_setup_method,
{ "Setup Method", "msrp.setup-method",
FT_STRING, BASE_NONE, NULL, 0x0,
"Method used to set up this stream", HFILL}
},
};
module_t *msrp_module;
proto_msrp = proto_register_protocol("Message Session Relay Protocol","MSRP", "msrp");
proto_register_field_array(proto_msrp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
msrp_module = prefs_register_protocol(proto_msrp, NULL);
prefs_register_bool_preference(msrp_module, "display_raw_text",
"Display raw text for MSRP message",
"Specifies that the raw text of the "
"MSRP message should be displayed "
"in addition to the dissection tree",
&global_msrp_raw_text);
prefs_register_bool_preference(msrp_module, "show_setup_info",
"Show stream setup information",
"Where available, show which protocol and frame caused "
"this MSRP stream to be created",
&global_msrp_show_setup_info);
new_register_dissector("msrp", dissect_msrp, proto_msrp);
}
void
proto_reg_handoff_msrp(void)
{
msrp_handle = find_dissector("msrp");
dissector_add_handle("tcp.port", msrp_handle);
heur_dissector_add("tcp", dissect_msrp_heur, proto_msrp);
media_type_dissector_table = find_dissector_table("media_type");
}
