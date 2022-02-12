static void
dissect_nasdaq_soup_packet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, proto_tree *tree, int offset, int linelen)
{
guint8 nasdaq_soup_type;
tvbuff_t *new_tvb = NULL;
nasdaq_soup_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_nasdaq_soup_packet_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
switch (nasdaq_soup_type) {
case '+':
proto_tree_add_item(tree, hf_nasdaq_soup_text, tvb, offset, linelen -1, ENC_ASCII|ENC_NA);
offset += linelen -1;
break;
case 'A':
proto_tree_add_item(tree, hf_nasdaq_soup_session, tvb, offset, 10, ENC_ASCII|ENC_NA);
offset += 10;
proto_tree_add_item(tree, hf_nasdaq_soup_seq_number, tvb, offset, 10, ENC_ASCII|ENC_NA);
offset += 10;
break;
case 'J':
proto_tree_add_item(tree, hf_nasdaq_soup_reject_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
case 'U':
case 'S':
if (linelen > 1 && nasdaq_itch_handle) {
new_tvb = tvb_new_subset_length(tvb, offset,linelen -1);
} else {
proto_tree_add_item(tree, hf_nasdaq_soup_message, tvb, offset, linelen -1, ENC_ASCII|ENC_NA);
}
offset += linelen -1;
break;
case 'L':
proto_tree_add_item(tree, hf_nasdaq_soup_username, tvb, offset, 6, ENC_ASCII|ENC_NA);
offset += 6;
proto_tree_add_item(tree, hf_nasdaq_soup_password, tvb, offset, 10, ENC_ASCII|ENC_NA);
offset += 10;
proto_tree_add_item(tree, hf_nasdaq_soup_session, tvb, offset, 10, ENC_ASCII|ENC_NA);
offset += 10;
proto_tree_add_item(tree, hf_nasdaq_soup_seq_number, tvb, offset, 10, ENC_ASCII|ENC_NA);
offset += 10;
break;
case 'H':
case 'O':
case 'R':
break;
default:
proto_tree_add_item(tree, hf_nasdaq_soup_message, tvb, offset, linelen -1, ENC_ASCII|ENC_NA);
offset += linelen -1;
break;
}
proto_tree_add_item(tree, hf_nasdaq_soup_packet_eol, tvb, offset, 1, ENC_ASCII|ENC_NA);
if (new_tvb) {
call_dissector(nasdaq_itch_handle, new_tvb, pinfo, parent_tree);
}
return;
}
static void
dissect_nasdaq_soup(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *nasdaq_soup_tree = NULL;
guint8 nasdaq_soup_type;
int linelen;
gint next_offset;
int offset = 0;
gint counter = 0;
while (tvb_offset_exists(tvb, offset)) {
linelen = tvb_find_line_end(tvb, offset, -1, &next_offset, nasdaq_soup_desegment && pinfo->can_desegment);
if (linelen == -1) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return;
}
nasdaq_soup_type = tvb_get_guint8(tvb, offset);
if (counter == 0) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Nasdaq-SOUP");
col_clear(pinfo->cinfo, COL_INFO);
}
if (counter) {
col_append_str(pinfo->cinfo, COL_INFO, "; ");
col_set_fence(pinfo->cinfo, COL_INFO);
}
col_append_str(pinfo->cinfo, COL_INFO, val_to_str(nasdaq_soup_type, message_types_val, "Unknown packet type (0x%02x)"));
counter++;
ti = proto_tree_add_item(tree, proto_nasdaq_soup, tvb, offset, linelen +1, ENC_NA);
nasdaq_soup_tree = proto_item_add_subtree(ti, ett_nasdaq_soup);
dissect_nasdaq_soup_packet(tvb, pinfo, tree, nasdaq_soup_tree, offset, linelen);
offset = next_offset;
}
}
static void nasdaq_soup_prefs(void)
{
dissector_delete_uint_range("tcp.port", nasdaq_soup_tcp_range, nasdaq_soup_handle);
g_free(nasdaq_soup_tcp_range);
nasdaq_soup_tcp_range = range_copy(global_nasdaq_soup_tcp_range);
dissector_add_uint_range("tcp.port", nasdaq_soup_tcp_range, nasdaq_soup_handle);
}
void
proto_register_nasdaq_soup(void)
{
static hf_register_info hf[] = {
{ &hf_nasdaq_soup_packet_type,
{ "Packet Type", "nasdaq-soup.packet_type",
FT_UINT8, BASE_DEC, VALS(message_types_val), 0x0,
NULL, HFILL }},
{ &hf_nasdaq_soup_reject_code,
{ "Login Reject Code", "nasdaq-soup.reject_code",
FT_UINT8, BASE_DEC, VALS(reject_code_val), 0x0,
NULL, HFILL }},
{ &hf_nasdaq_soup_message,
{ "Message", "nasdaq-soup.message",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_nasdaq_soup_text,
{ "Debug Text", "nasdaq-soup.text",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_nasdaq_soup_username,
{ "User Name", "nasdaq-soup.username",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_nasdaq_soup_password,
{ "Password", "nasdaq-soup.password",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_nasdaq_soup_session,
{ "Session", "nasdaq-soup.session",
FT_STRING, BASE_NONE, NULL, 0x0,
"Session ID", HFILL }},
{ &hf_nasdaq_soup_seq_number,
{ "Sequence number", "nasdaq-soup.seq_number",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_nasdaq_soup_packet_eol,
{ "End Of Packet", "nasdaq-soup.packet_eol",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }}
};
static gint *ett[] = {
&ett_nasdaq_soup
};
module_t *nasdaq_soup_module;
proto_nasdaq_soup = proto_register_protocol("Nasdaq-SoupTCP version 2.0","NASDAQ-SOUP", "nasdaq_soup");
proto_register_field_array(proto_nasdaq_soup, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
nasdaq_soup_module = prefs_register_protocol(proto_nasdaq_soup, nasdaq_soup_prefs);
prefs_register_bool_preference(nasdaq_soup_module, "desegment",
"Reassemble Nasdaq-SoupTCP messages spanning multiple TCP segments",
"Whether the Nasdaq-SoupTCP dissector should reassemble messages spanning multiple TCP segments.",
&nasdaq_soup_desegment);
prefs_register_range_preference(nasdaq_soup_module, "tcp.port", "TCP Ports", "TCP Ports range", &global_nasdaq_soup_tcp_range, 65535);
nasdaq_soup_tcp_range = range_empty();
}
void
proto_reg_handoff_nasdaq_soup(void)
{
nasdaq_soup_handle = create_dissector_handle(dissect_nasdaq_soup, proto_nasdaq_soup);
nasdaq_itch_handle = find_dissector("nasdaq-itch");
dissector_add_for_decode_as("tcp.port", nasdaq_soup_handle);
}
