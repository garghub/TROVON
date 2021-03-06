static void
dissect_irc_tag_data(proto_tree *tree, proto_item *item, tvbuff_t *tvb, int offset, int datalen, packet_info *pinfo, guint8* command)
{
guchar found_start_needle = 0,
found_end_needle = 0;
gint tag_start_offset, tag_end_offset;
tag_start_offset = tvb_pbrk_guint8(tvb, offset, datalen, TAG_DELIMITER, &found_start_needle);
if (tag_start_offset == -1)
{
return;
}
tag_end_offset = tvb_pbrk_guint8(tvb, offset, datalen-offset, TAG_DELIMITER, &found_end_needle);
if (tag_end_offset == -1)
{
expert_add_info(pinfo, item, &ei_irc_missing_end_delimiter);
return;
}
if ((strcmp(command, "NOTICE") != 0) &&
(strcmp(command, "PRIVMSG") != 0))
{
expert_add_info(pinfo, item, &ei_irc_tag_data_invalid);
}
proto_tree_add_item(tree, hf_irc_ctcp, tvb, offset+1, datalen-2, ENC_ASCII|ENC_NA);
}
static void
dissect_irc_request(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset, int linelen)
{
proto_tree *request_tree, *command_tree = NULL;
proto_item *request_item, *command_item;
int start_offset = offset;
int end_offset = start_offset+linelen;
gint eop_offset = -1,
eoc_offset = -1,
eocp_offset,
tag_start_offset, tag_end_offset;
guint8* str_command;
guchar found_needle = 0,
found_tag_needle = 0;
gboolean first_command_param = TRUE;
request_item = proto_tree_add_item(tree, hf_irc_request, tvb, offset, linelen, ENC_ASCII|ENC_NA);
if (linelen <= 0)
return;
request_tree = proto_item_add_subtree(request_item, ett_irc_request );
if (tvb_get_guint8(tvb, offset) == ':')
{
eop_offset = tvb_pbrk_guint8(tvb, offset+1, linelen-1, " ", &found_needle);
if (eop_offset == -1)
{
expert_add_info(pinfo, request_item, &ei_irc_prefix_missing_ending_space);
return;
}
proto_tree_add_item(request_tree, hf_irc_request_prefix, tvb, offset+1, eop_offset-offset-1, ENC_ASCII|ENC_NA);
found_needle = 0;
offset = eop_offset+1;
}
while(offset < end_offset && tvb_get_guint8(tvb, offset) == ' ')
{
offset++;
}
if (offset == end_offset)
{
expert_add_info(pinfo, request_item, &ei_irc_request_command);
return;
}
eoc_offset = tvb_pbrk_guint8(tvb, offset, end_offset-offset, " ", &found_needle);
if (eoc_offset == -1)
{
proto_tree_add_item(request_tree, hf_irc_request_command, tvb, offset, end_offset-offset, ENC_ASCII|ENC_NA);
col_append_fstr( pinfo->cinfo, COL_INFO, " (%s)", tvb_get_string(wmem_packet_scope(), tvb, offset, end_offset-offset));
if ((end_offset-offset == 3) &&
(isdigit(tvb_get_guint8(tvb, offset))) &&
(isdigit(tvb_get_guint8(tvb, offset+1))) &&
(isdigit(tvb_get_guint8(tvb, offset+2))))
{
expert_add_info(pinfo, request_item, &ei_irc_numeric_request_command);
}
return;
}
proto_tree_add_item(request_tree, hf_irc_request_command, tvb, offset, eoc_offset-offset, ENC_ASCII|ENC_NA);
str_command = tvb_get_string(wmem_packet_scope(), tvb, offset, eoc_offset-offset);
col_append_fstr( pinfo->cinfo, COL_INFO, " (%s)", str_command);
if ((eoc_offset-offset == 3) &&
(isdigit(tvb_get_guint8(tvb, offset))) &&
(isdigit(tvb_get_guint8(tvb, offset+1))) &&
(isdigit(tvb_get_guint8(tvb, offset+2))))
{
expert_add_info(pinfo, request_item, &ei_irc_numeric_request_command);
}
found_needle = 0;
offset = eoc_offset+1;
while(offset < end_offset && tvb_get_guint8(tvb, offset) == ' ')
{
offset++;
}
if (offset == end_offset)
{
return;
}
if (tvb_get_guint8(tvb, offset) == ':')
{
proto_tree_add_item(request_tree, hf_irc_request_trailer, tvb, offset+1, end_offset-offset-1, ENC_ASCII|ENC_NA);
dissect_irc_tag_data(request_tree, request_item, tvb, offset+1, end_offset-offset-1, pinfo, str_command);
return;
}
while(offset < end_offset)
{
eocp_offset = tvb_pbrk_guint8(tvb, offset, end_offset-offset, " ", &found_needle);
tag_start_offset = tvb_pbrk_guint8(tvb, offset, end_offset-offset, TAG_DELIMITER, &found_tag_needle);
if (first_command_param)
{
command_item = proto_tree_add_text(request_tree, tvb, offset, end_offset-offset, "Command parameters");
command_tree = proto_item_add_subtree(command_item, ett_irc_request_command );
first_command_param = FALSE;
}
if (((eocp_offset == -1) && (tag_start_offset == -1)) ||
((eocp_offset != -1) && (tag_start_offset == -1)) ||
(eocp_offset < tag_start_offset))
{
found_needle = 0;
if (eocp_offset == -1)
{
proto_tree_add_item(command_tree, hf_irc_request_command_param, tvb, offset, end_offset-offset, ENC_ASCII|ENC_NA);
return;
}
proto_tree_add_item(command_tree, hf_irc_request_command_param, tvb, offset, eocp_offset-offset, ENC_ASCII|ENC_NA);
offset = eocp_offset+1;
while(offset < end_offset && tvb_get_guint8(tvb, offset) == ' ')
{
offset++;
}
if (offset == end_offset)
{
break;
}
if (tvb_get_guint8(tvb, offset) == ':')
{
proto_tree_add_item(request_tree, hf_irc_request_trailer, tvb, offset+1, end_offset-offset-1, ENC_ASCII|ENC_NA);
dissect_irc_tag_data(request_tree, request_item, tvb, offset+1, end_offset-offset-1, pinfo, str_command);
return;
}
}
else if (((eocp_offset == -1) && (tag_start_offset != -1)) ||
(eocp_offset > tag_start_offset))
{
found_tag_needle = 0;
tag_end_offset = tvb_pbrk_guint8(tvb, tag_start_offset+1, end_offset-tag_start_offset-1, TAG_DELIMITER, &found_tag_needle);
if (tag_end_offset == -1)
{
expert_add_info(pinfo, request_item, &ei_irc_missing_end_delimiter);
return;
}
dissect_irc_tag_data(request_tree, request_item, tvb, tag_start_offset, tag_end_offset-tag_start_offset, pinfo, str_command);
offset = tag_end_offset+1;
}
}
}
static void
dissect_irc_response(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset, int linelen)
{
proto_tree *response_tree, *command_tree = NULL;
proto_item *response_item, *command_item, *hidden_item;
int start_offset = offset;
int end_offset = start_offset+linelen;
gint eop_offset = -1,
eoc_offset = -1,
eocp_offset,
tag_start_offset, tag_end_offset;
guint8* str_command;
guint16 num_command;
guchar found_needle = 0,
found_tag_needle = 0;
gboolean first_command_param = TRUE;
response_item = proto_tree_add_item(tree, hf_irc_response, tvb, offset, linelen, ENC_ASCII|ENC_NA);
if (linelen <= 0)
return;
response_tree = proto_item_add_subtree(response_item, ett_irc_response );
if (tvb_get_guint8(tvb, offset) == ':')
{
eop_offset = tvb_pbrk_guint8(tvb, offset+1, linelen-1, " ", &found_needle);
if (eop_offset == -1)
{
expert_add_info(pinfo, response_item, &ei_irc_prefix_missing_ending_space);
return;
}
proto_tree_add_item(response_tree, hf_irc_response_prefix, tvb, offset+1, eop_offset-offset-1, ENC_ASCII|ENC_NA);
found_needle = 0;
offset = eop_offset+1;
}
while(offset < end_offset && tvb_get_guint8(tvb, offset) == ' ')
{
offset++;
}
if (offset == end_offset)
{
expert_add_info(pinfo, response_item, &ei_irc_response_command);
return;
}
eoc_offset = tvb_pbrk_guint8(tvb, offset, end_offset-offset, " ", &found_needle);
if (eoc_offset == -1)
{
proto_tree_add_item(response_tree, hf_irc_response_command, tvb, offset, end_offset-offset, ENC_ASCII|ENC_NA);
col_append_fstr( pinfo->cinfo, COL_INFO, " (%s)", tvb_get_string(wmem_packet_scope(), tvb, offset, end_offset-offset));
if ((end_offset-offset == 3) &&
(isdigit(tvb_get_guint8(tvb, offset))) &&
(isdigit(tvb_get_guint8(tvb, offset+1))) &&
(isdigit(tvb_get_guint8(tvb, offset+2))))
{
num_command = ((tvb_get_guint8(tvb, offset)-0x30)*100) + ((tvb_get_guint8(tvb, offset+1)-0x30)*10) + (tvb_get_guint8(tvb, offset+2)-0x30);
hidden_item = proto_tree_add_uint(response_tree, hf_irc_response_num_command, tvb, offset, end_offset-offset, num_command);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
return;
}
proto_tree_add_item(response_tree, hf_irc_response_command, tvb, offset, eoc_offset-offset, ENC_ASCII|ENC_NA);
str_command = tvb_get_string(wmem_packet_scope(), tvb, offset, eoc_offset-offset);
col_append_fstr( pinfo->cinfo, COL_INFO, " (%s)", str_command);
if ((eoc_offset-offset == 3) &&
(isdigit(tvb_get_guint8(tvb, offset))) &&
(isdigit(tvb_get_guint8(tvb, offset+1))) &&
(isdigit(tvb_get_guint8(tvb, offset+2))))
{
num_command = ((tvb_get_guint8(tvb, offset)-0x30)*100) + ((tvb_get_guint8(tvb, offset+1)-0x30)*10) + (tvb_get_guint8(tvb, offset+2)-0x30);
hidden_item = proto_tree_add_uint(response_tree, hf_irc_response_num_command, tvb, offset, eoc_offset-offset, num_command);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
found_needle = 0;
offset = eoc_offset+1;
while(offset < end_offset && tvb_get_guint8(tvb, offset) == ' ')
{
offset++;
}
if (offset == end_offset)
{
return;
}
if (tvb_get_guint8(tvb, offset) == ':')
{
proto_tree_add_item(response_tree, hf_irc_response_trailer, tvb, offset+1, end_offset-offset-1, ENC_ASCII|ENC_NA);
dissect_irc_tag_data(response_tree, response_item, tvb, offset+1, end_offset-offset-1, pinfo, str_command);
return;
}
while(offset < end_offset)
{
eocp_offset = tvb_pbrk_guint8(tvb, offset, end_offset-offset, " ", &found_needle);
tag_start_offset = tvb_pbrk_guint8(tvb, offset, end_offset-offset, TAG_DELIMITER, &found_tag_needle);
if (first_command_param)
{
command_item = proto_tree_add_text(response_tree, tvb, offset, end_offset-offset, "Command parameters");
command_tree = proto_item_add_subtree(command_item, ett_irc_response_command );
first_command_param = FALSE;
}
if ((tag_start_offset == -1) || (eocp_offset < tag_start_offset))
{
found_needle = 0;
if (eocp_offset == -1)
{
proto_tree_add_item(command_tree, hf_irc_response_command_param, tvb, offset, end_offset-offset, ENC_ASCII|ENC_NA);
return;
}
proto_tree_add_item(command_tree, hf_irc_response_command_param, tvb, offset, eocp_offset-offset, ENC_ASCII|ENC_NA);
offset = eocp_offset+1;
while(offset < end_offset && tvb_get_guint8(tvb, offset) == ' ')
{
offset++;
}
if (offset == end_offset)
{
break;
}
if (tvb_get_guint8(tvb, offset) == ':')
{
proto_tree_add_item(response_tree, hf_irc_response_trailer, tvb, offset+1, end_offset-offset-1, ENC_ASCII|ENC_NA);
dissect_irc_tag_data(response_tree, response_item, tvb, offset+1, end_offset-offset-1, pinfo, str_command);
return;
}
}
else if ((eocp_offset == -1) || (eocp_offset > tag_start_offset))
{
found_tag_needle = 0;
tag_end_offset = tvb_pbrk_guint8(tvb, tag_start_offset+1, end_offset-tag_start_offset-1, TAG_DELIMITER, &found_tag_needle);
if (tag_end_offset == -1)
{
expert_add_info(pinfo, response_item, &ei_irc_missing_end_delimiter);
return;
}
dissect_irc_tag_data(response_tree, response_item, tvb, tag_start_offset, tag_end_offset-tag_start_offset, pinfo, str_command);
offset = tag_end_offset+1;
}
}
}
static void
dissect_irc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *irc_tree, *ti;
gint offset = 0;
gint next_offset;
int linelen;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IRC");
col_set_str(pinfo->cinfo, COL_INFO,
(pinfo->match_uint == pinfo->destport) ? "Request" : "Response");
ti = proto_tree_add_item(tree, proto_irc, tvb, 0, -1, ENC_NA);
irc_tree = proto_item_add_subtree(ti, ett_irc);
while (tvb_reported_length_remaining(tvb, offset) > 0)
{
linelen = tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
if (next_offset == offset) {
break;
}
if (linelen != 0)
{
if (pinfo->match_uint == pinfo->destport)
{
dissect_irc_request(irc_tree, tvb, pinfo, offset, linelen);
}
else
{
dissect_irc_response(irc_tree, tvb, pinfo, offset, linelen);
}
}
offset = next_offset;
}
}
void
proto_register_irc(void)
{
static hf_register_info hf[] = {
{ &hf_irc_response, { "Response", "irc.response", FT_STRING, BASE_NONE,
NULL, 0x0, "Line of response message", HFILL }},
{ &hf_irc_request, { "Request", "irc.request", FT_STRING, BASE_NONE,
NULL, 0x0, "Line of request message", HFILL }},
{ &hf_irc_request_prefix, { "Prefix", "irc.request.prefix", FT_STRING, BASE_NONE,
NULL, 0x0, "Request prefix", HFILL }},
{ &hf_irc_request_command, { "Command", "irc.request.command", FT_STRING, BASE_NONE,
NULL, 0x0, "Request command", HFILL }},
{ &hf_irc_request_command_param, { "Parameter", "irc.request.command_parameter", FT_STRING, BASE_NONE,
NULL, 0x0, "Request command parameter", HFILL }},
{ &hf_irc_request_trailer, { "Trailer", "irc.request.trailer", FT_STRING, BASE_NONE,
NULL, 0x0, "Request trailer", HFILL }},
{ &hf_irc_response_prefix, { "Prefix", "irc.response.prefix", FT_STRING, BASE_NONE,
NULL, 0x0, "Response prefix", HFILL }},
{ &hf_irc_response_command, { "Command", "irc.response.command", FT_STRING, BASE_NONE,
NULL, 0x0, "Response command", HFILL }},
{ &hf_irc_response_num_command, { "Command", "irc.response.command", FT_UINT16, BASE_DEC,
NULL, 0x0, "Response (numeric) command", HFILL }},
{ &hf_irc_response_command_param, { "Parameter", "irc.response.command_parameter", FT_STRING, BASE_NONE,
NULL, 0x0, "Response command parameter", HFILL }},
{ &hf_irc_response_trailer, { "Trailer", "irc.response.trailer", FT_STRING, BASE_NONE,
NULL, 0x0, "Response trailer", HFILL }},
{ &hf_irc_ctcp, { "CTCP Data", "irc.ctcp", FT_STRING, BASE_NONE,
NULL, 0x0, "Placeholder to dissect CTCP data", HFILL }}
};
static gint *ett[] = {
&ett_irc,
&ett_irc_request,
&ett_irc_request_command,
&ett_irc_response,
&ett_irc_response_command
};
static ei_register_info ei[] = {
{ &ei_irc_missing_end_delimiter, { "irc.missing_end_delimiter", PI_MALFORMED, PI_ERROR, "Missing ending tag delimiter (0x01)", EXPFILL }},
{ &ei_irc_tag_data_invalid, { "irc.tag_data_invalid", PI_PROTOCOL, PI_WARN, "Tag data outside of NOTICE or PRIVMSG command", EXPFILL }},
{ &ei_irc_prefix_missing_ending_space, { "irc.prefix_missing_ending_space", PI_MALFORMED, PI_ERROR, "Prefix missing ending <space>", EXPFILL }},
{ &ei_irc_request_command, { "irc.request.command.missing", PI_MALFORMED, PI_ERROR, "Request has no command", EXPFILL }},
{ &ei_irc_numeric_request_command, { "irc.request.command.numeric", PI_PROTOCOL, PI_WARN, "Numeric command not allowed in request", EXPFILL }},
{ &ei_irc_response_command, { "irc.response.command.missing", PI_MALFORMED, PI_ERROR, "Response has no command", EXPFILL }},
};
expert_module_t* expert_irc;
proto_irc = proto_register_protocol("Internet Relay Chat", "IRC", "irc");
proto_register_field_array(proto_irc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_irc = expert_register_protocol(proto_irc);
expert_register_field_array(expert_irc, ei, array_length(ei));
}
void
proto_reg_handoff_irc(void)
{
dissector_handle_t irc_handle;
irc_handle = create_dissector_handle(dissect_irc, proto_irc);
dissector_add_uint("tcp.port", TCP_PORT_IRC, irc_handle);
dissector_add_uint("tcp.port", TCP_PORT_DIRCPROXY, irc_handle);
}
