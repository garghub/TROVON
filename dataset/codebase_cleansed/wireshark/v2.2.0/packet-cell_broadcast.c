static void gsm_cbs_message_reassembly_init(void)
{
reassembly_table_init(&gsm_cbs_reassembly_table,
&addresses_reassembly_table_functions);
}
static void gsm_cbs_message_reassembly_cleanup(void)
{
reassembly_table_destroy(&gsm_cbs_reassembly_table);
}
guint dissect_cbs_serial_number(tvbuff_t *tvb, proto_tree *tree, guint offset)
{
guint16 serial_number = tvb_get_ntohs(tvb, offset) ;
proto_item *item;
proto_tree *subtree;
item = proto_tree_add_item(tree, hf_gsm_cbs_serial_number, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(item, ", Message Code: %d, Update Number: %d", (serial_number & 0x3FF) >> 4, serial_number & 0x0F);
subtree = proto_item_add_subtree(item, ett_cbs_serial_no);
proto_tree_add_item(subtree, hf_gsm_cbs_geographic_scope, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_cbs_message_code, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_cbs_update_number, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
guint dissect_cbs_message_identifier(tvbuff_t *tvb, proto_tree *tree, guint offset)
{
guint16 msg_id;
const char *msg_id_string = NULL;
msg_id = tvb_get_ntohs(tvb, offset);
msg_id_string = try_val_to_str(msg_id, message_id_values);
if (msg_id_string == NULL)
{
if (msg_id < 1000)
{
msg_id_string = "Message ID to be allocated by GSMA";
}
else if (msg_id < 4096)
{
msg_id_string = "Message ID intended for standardization in future versions of 3GPP TS 23.041";
}
else if (msg_id < 4224)
{
msg_id_string = "Message ID reserved for Cell Broadcast Data Download (unsecured) to the SIM ";
}
else if (msg_id < 4352)
{
msg_id_string = "Message ID reserved for Cell Broadcast Data Download (secured) to the SIM ";
}
else if (msg_id < 4360)
{
msg_id_string = "ETWS CBS Message Identifier for future extension";
}
else if (msg_id < 4400)
{
msg_id_string = "CMAS CBS Message Identifier for future extension";
}
else if (msg_id < 6400)
{
msg_id_string = "CBS Message Identifier for future PWS use";
}
else if (msg_id < 40960)
{
msg_id_string = "Intended for standardization in future versions of 3GPP TS 23.041";
}
else if (msg_id < 43500)
{
msg_id_string = "Message ID in PLMN operator specific range";
}
else if (msg_id < 43530)
{
msg_id_string = "Traffic Information Traffic Master UK";
}
else if (msg_id < 43585)
{
msg_id_string = "Traffic information Mannesmann Telecommerce";
}
else if (msg_id < 45056)
{
msg_id_string = "Message ID in PLMN operator specific range";
}
else
{
msg_id_string = "Message ID intended as PLMN operator specific range in future versions of 3GPP TS 23.041";
}
}
proto_tree_add_uint_format_value(tree, hf_gsm_cbs_message_identifier, tvb, offset, 2, msg_id, "%s (%d)", msg_id_string, msg_id);
offset += 2;
return offset;
}
tvbuff_t * dissect_cbs_data(guint8 sms_encoding, tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint offset )
{
tvbuff_t * tvb_out = NULL;
int length = tvb_reported_length(tvb) - offset;
gchar *text;
switch(sms_encoding){
case SMS_ENCODING_7BIT:
case SMS_ENCODING_7BIT_LANG:
text = tvb_get_ts_23_038_7bits_string(pinfo->pool, tvb, offset<<3, (length*8)/7);
tvb_out = tvb_new_child_real_data(tvb, text, (guint)strlen(text), (guint)strlen(text));
add_new_data_source(pinfo, tvb_out, "unpacked 7 bit data");
break;
case SMS_ENCODING_8BIT:
text = tvb_get_string_enc(pinfo->pool, tvb, offset, length, ENC_ASCII|ENC_NA);
tvb_out = tvb_new_child_real_data(tvb, text, (guint)strlen(text), (guint)strlen(text));
add_new_data_source(pinfo, tvb_out, "8 bit data");
break;
case SMS_ENCODING_UCS2:
case SMS_ENCODING_UCS2_LANG:
text = tvb_get_string_enc(pinfo->pool, tvb, offset, length, ENC_UCS_2|ENC_BIG_ENDIAN);
tvb_out = tvb_new_child_real_data(tvb, text, (guint)strlen(text), (guint)strlen(text));
add_new_data_source(pinfo, tvb_out, "UCS-2 data");
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_gsm_cbs_unhandled_encoding, tvb, offset, length,
"Unhandled encoding %d of CBS String", sms_encoding);
break;
}
return tvb_out;
}
static int
dissect_gsm_cell_broadcast(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint8 sms_encoding, total_pages, current_page;
guint32 offset = 0;
guint len, text_len;
guint32 msg_key;
proto_item *cbs_page_item = NULL;
proto_tree *cbs_page_tree = NULL;
guint16 serial_number, message_id;
tvbuff_t *cbs_page_tvb = NULL;
tvbuff_t *cbs_msg_tvb = NULL;
fragment_head * frag_data = NULL;
len = tvb_reported_length(tvb);
col_append_str(pinfo->cinfo, COL_PROTOCOL, " Cell Broadcast");
col_append_str(pinfo->cinfo, COL_INFO, " (CBS Page)");
cbs_page_item = proto_tree_add_protocol_format(proto_tree_get_root(tree), proto_cell_broadcast, tvb, 0, len, "GSM Cell Broadcast");
cbs_page_tree = proto_item_add_subtree(cbs_page_item, ett_gsm_cbs_page);
serial_number = tvb_get_ntohs(tvb, offset);
offset = dissect_cbs_serial_number(tvb, cbs_page_tree, offset);
message_id = tvb_get_ntohs(tvb, offset);
offset = dissect_cbs_message_identifier(tvb, cbs_page_tree, offset);
sms_encoding = dissect_cbs_data_coding_scheme(tvb, pinfo, cbs_page_tree, offset++);
total_pages = tvb_get_guint8(tvb, offset);
current_page = (total_pages & 0xF0) >> 4;
total_pages &= 0x0F;
proto_tree_add_item(cbs_page_tree, hf_gsm_cbs_current_page, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(cbs_page_tree, hf_gsm_cbs_total_pages, tvb, offset++, 1, ENC_BIG_ENDIAN);
cbs_page_tvb = dissect_cbs_data(sms_encoding, tvb, cbs_page_tree, pinfo, offset );
if (cbs_page_tvb != NULL)
{
text_len = tvb_reported_length(cbs_page_tvb);
while (text_len && (tvb_get_guint8(cbs_page_tvb, text_len-1) == '\r')) {
text_len--;
}
if (tree != NULL)
{
proto_tree *cbs_page_subtree = proto_tree_add_subtree(cbs_page_tree, tvb, offset, -1,
ett_gsm_cbs_page_content, NULL, "Cell Broadcast Page Contents");
len = tvb_reported_length(cbs_page_tvb);
proto_tree_add_item(cbs_page_subtree, hf_gsm_cbs_page_content, cbs_page_tvb, 0, text_len, ENC_ASCII|ENC_NA);
len -= text_len;
if (len)
{
proto_tree_add_item(cbs_page_subtree, hf_gsm_cbs_page_content_padding, cbs_page_tvb, text_len, len, ENC_ASCII|ENC_NA);
}
}
if (text_len)
{
cbs_page_tvb = tvb_new_subset_length(cbs_page_tvb, 0, text_len);
if (total_pages == 1)
{
cbs_msg_tvb = cbs_page_tvb;
}
else
{
msg_key = (serial_number << 16) + message_id;
frag_data = fragment_add_seq_check(&gsm_cbs_reassembly_table,
cbs_page_tvb, 0, pinfo, msg_key, NULL,
(current_page -1), text_len,
(current_page!=total_pages));
cbs_msg_tvb = process_reassembled_data(cbs_page_tvb, 0, pinfo, "Reassembled Cell Broadcast message",
frag_data, &gsm_page_items, NULL, cbs_page_tree);
}
}
}
if (cbs_msg_tvb != NULL)
{
proto_item *cbs_msg_item = NULL;
proto_tree *cbs_msg_tree = NULL;
len = tvb_reported_length(cbs_msg_tvb);
col_append_str(pinfo->cinfo, COL_INFO, " (CBS Message)");
cbs_msg_item = proto_tree_add_protocol_format(proto_tree_get_root(tree), proto_cell_broadcast, cbs_msg_tvb, 0, len, "GSM Cell Broadcast Message");
cbs_msg_tree = proto_item_add_subtree(cbs_msg_item, ett_cbs_msg);
proto_tree_add_item(cbs_msg_tree, hf_gsm_cbs_message_content, cbs_msg_tvb, 0, len, ENC_ASCII|ENC_NA);
}
return tvb_captured_length(tvb);
}
int dissect_umts_cell_broadcast_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint8 sms_encoding;
guint32 offset = 0;
guint32 len;
proto_item *cbs_item;
proto_tree *cbs_tree, *cbs_subtree;
guint msg_len;
guint8 *msg;
tvbuff_t * cbs_msg_tvb = NULL;
len = tvb_reported_length(tvb);
col_append_str(pinfo->cinfo, COL_PROTOCOL, " Cell Broadcast");
col_append_str(pinfo->cinfo, COL_INFO, " (CBS Message)");
cbs_item = proto_tree_add_protocol_format(proto_tree_get_root(tree), proto_cell_broadcast, tvb, 0, len, "Cell Broadcast");
cbs_tree = proto_item_add_subtree(cbs_item, ett_cbs_msg);
sms_encoding = dissect_cbs_data_coding_scheme(tvb, pinfo, cbs_tree, 0);
offset++;
cbs_msg_tvb = dissect_cbs_data(sms_encoding, tvb, cbs_tree, pinfo, offset );
msg_len = tvb_reported_length(cbs_msg_tvb);
cbs_subtree = proto_tree_add_subtree_format(cbs_tree, tvb, offset, -1,
ett_cbs_msg, NULL, "Cell Broadcast Message Contents (length: %d)", msg_len);
msg = tvb_get_string_enc(wmem_packet_scope(), cbs_msg_tvb, 0, msg_len, ENC_ASCII);
proto_tree_add_string_format(cbs_subtree, hf_gsm_cbs_message_content, cbs_msg_tvb, 0, -1, msg, "%s", msg);
return tvb_captured_length(tvb);
}
void
proto_register_cbs(void)
{
static hf_register_info hf_cbs[] =
{
{ &hf_gsm_cbs_serial_number,
{ "GSM CBS Serial Number", "gsm_cbs.serial_number",
FT_UINT16, BASE_HEX_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_cbs_message_code,
{ "GSM CBS Message Code", "gsm_cbs.message_code",
FT_UINT16, BASE_DEC_HEX, NULL, 0x3FF0,
NULL, HFILL }
},
{ &hf_gsm_cbs_geographic_scope,
{ "GSM CBS Geographic Scope", "gsm_cbs.geographic_scope",
FT_UINT16, BASE_DEC, VALS(geographic_scope_values), 0xC000,
NULL, HFILL }
},
{ &hf_gsm_cbs_update_number,
{ "GSM CBS Update Number", "gsm_cbs.update_number",
FT_UINT16, BASE_DEC, NULL, 0x000F,
NULL, HFILL }
},
{ &hf_gsm_cbs_message_identifier,
{ "GSM CBS Message Identifier", "gsm_cbs.message-identifier",
FT_UINT16, BASE_DEC_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_cbs_total_pages,
{ "GSM CBS Total Pages", "gsm_cbs.total_pages",
FT_UINT8, BASE_DEC, NULL, 0x0F,
NULL, HFILL }
},
{ &hf_gsm_cbs_current_page,
{ "GSM CBS Current Page", "gsm_cbs.current_page",
FT_UINT8, BASE_DEC, NULL, 0xF0,
NULL, HFILL }
},
{ &hf_gsm_cbs_page_overlap,
{ "page overlap",
"gsm_cbs.page.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"GSM CBS page overlaps with other fragments", HFILL
}
},
{ &hf_gsm_cbs_page_overlap_conflict,
{ "Conflicting data in page overlap",
"gsm_cbs.page.overlap.conflict",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Overlapping pages contained conflicting data", HFILL
}
},
{ &hf_gsm_cbs_page_multiple_tails,
{ "Multiple final pages found",
"gsm_cbs.page.multipletails",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Several copies of the final page were found when reassembling the message", HFILL
}
},
{ &hf_gsm_cbs_page_too_long_fragment,
{ "Page too long",
"gsm_cbs.page.toolongfragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Page contained data past end of packet", HFILL
}
},
{ &hf_gsm_cbs_page_error,
{ "Reassembly error",
"gsm_cbs.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Reassembly error due to illegal fragments", HFILL
}
},
{ &hf_gsm_cbs_page_count,
{ "Fragment count",
"gsm_cbs.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Count of Page Fragment", HFILL
}
},
{ &hf_gsm_cbs_message_reassembled_in,
{ "Reassembled in",
"gsm_cbs.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"CBS pages are reassembled in the given packet", HFILL
}
},
{ &hf_gsm_cbs_message_reassembled_length,
{ "Reassembled message length",
"gsm_cbs.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The total length of the reassembled message", HFILL
}
},
{ &hf_gsm_cbs_page_num,
{ "CBS Page Number",
"gsm_cbs.page_number",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gsm_cbs_pages,
{ "CBS Pages",
"gsm_cbs.pages",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gsm_cbs_page_content,
{ "CBS Page Content",
"gsm_cbs.page_content",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gsm_cbs_page_content_padding,
{ "CBS Page Content Padding",
"gsm_cbs.page_content_padding",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gsm_cbs_message_content,
{ "CBS Message Content",
"gsm_cbs.message_content",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
}
};
static gint *ett[] = {
&ett_cbs_msg,
&ett_cbs_serial_no,
&ett_cbs_coding,
&ett_gsm_cbs_page,
&ett_gsm_cbs_page_content,
&ett_gsm_cbs_pages,
};
static ei_register_info ei[] = {
{ &ei_gsm_cbs_unhandled_encoding, { "gsm_cbs.unhandled_encoding", PI_PROTOCOL, PI_WARN, "Unhandled encoding", EXPFILL }},
};
expert_module_t* expert_cell_broadcast;
proto_cell_broadcast = proto_register_protocol("GSM Cell Broadcast Service", "GSM Cell Broadcast Service", "gsm_cbs");
proto_register_field_array(proto_cell_broadcast, hf_cbs, array_length(hf_cbs));
register_init_routine(gsm_cbs_message_reassembly_init);
register_cleanup_routine(gsm_cbs_message_reassembly_cleanup);
register_dissector("gsm_cbs", dissect_gsm_cell_broadcast, proto_cell_broadcast);
register_dissector("umts_cell_broadcast", dissect_umts_cell_broadcast_message, proto_cell_broadcast);
proto_register_subtree_array(ett, array_length(ett));
expert_cell_broadcast = expert_register_protocol(proto_cell_broadcast);
expert_register_field_array(expert_cell_broadcast, ei, array_length(ei));
}
