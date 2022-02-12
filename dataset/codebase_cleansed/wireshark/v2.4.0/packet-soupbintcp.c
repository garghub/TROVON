static void
dissect_soupbintcp_common(
tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree)
{
struct conv_data *conv_data;
struct pdu_data *pdu_data;
const char *pkt_name;
gint32 seq_num;
gboolean seq_num_valid;
proto_item *ti;
proto_tree *soupbintcp_tree = NULL;
conversation_t *conv = NULL;
guint16 expected_len;
guint8 pkt_type;
gint offset = 0;
guint this_seq = 0, next_seq = 0, key;
heur_dtbl_entry_t *hdtbl_entry;
proto_item *pi;
key = (guint)tvb_raw_offset(tvb);
expected_len = tvb_get_ntohs(tvb, 0);
pkt_type = tvb_get_guint8(tvb, 2);
pkt_name = val_to_str(pkt_type, pkt_type_val, "Unknown (%u)");
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SoupBinTCP");
col_add_str(pinfo->cinfo, COL_INFO, pkt_name);
if (pkt_type == 'A' && !PINFO_FD_VISITED(pinfo)) {
ws_strtou32(tvb_get_string_enc(wmem_packet_scope(), tvb, 13, 20, ENC_ASCII),
NULL, &next_seq);
conv = conversation_new(pinfo->num,
&pinfo->src,
&pinfo->dst,
pinfo->ptype,
pinfo->srcport,
pinfo->destport,
0);
conv_data = (struct conv_data *)wmem_alloc(wmem_file_scope(), sizeof(struct conv_data));
conv_data->next_seq = next_seq;
conversation_add_proto_data(conv, proto_soupbintcp, conv_data);
}
if (pkt_type == 'S') {
if (!PINFO_FD_VISITED(pinfo)) {
conv = find_conversation(pinfo->num,
&pinfo->src,
&pinfo->dst,
pinfo->ptype,
pinfo->srcport,
pinfo->destport,
0);
if (!conv) {
this_seq = 0;
} else {
conv_data = (struct conv_data *)conversation_get_proto_data(conv,
proto_soupbintcp);
if (conv_data) {
this_seq = conv_data->next_seq++;
} else {
this_seq = 0;
}
pdu_data = (struct pdu_data *)wmem_alloc(
wmem_file_scope(),
sizeof(struct pdu_data));
pdu_data->seq_num = this_seq;
p_add_proto_data(wmem_file_scope(), pinfo, proto_soupbintcp, key, pdu_data);
}
} else {
pdu_data = (struct pdu_data *)p_get_proto_data(wmem_file_scope(), pinfo, proto_soupbintcp, key);
if (pdu_data) {
this_seq = pdu_data->seq_num;
} else {
this_seq = 0;
}
}
col_append_fstr(pinfo->cinfo, COL_INFO, ", SeqNum = %u", this_seq);
}
if (tree) {
ti = proto_tree_add_item(tree,
proto_soupbintcp,
tvb, 0, -1, ENC_NA);
soupbintcp_tree = proto_item_add_subtree(ti, ett_soupbintcp);
proto_item_append_text(ti, ", %s", pkt_name);
proto_tree_add_item(soupbintcp_tree,
hf_soupbintcp_packet_length,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(soupbintcp_tree,
hf_soupbintcp_packet_type,
tvb, offset, 1, ENC_ASCII|ENC_NA);
offset += 1;
switch (pkt_type) {
case '+':
proto_tree_add_item(soupbintcp_tree,
hf_soupbintcp_text,
tvb, offset, expected_len - 1, ENC_ASCII|ENC_NA);
break;
case 'A':
proto_tree_add_item(soupbintcp_tree,
hf_soupbintcp_session,
tvb, offset, 10, ENC_ASCII|ENC_NA);
offset += 10;
seq_num_valid = ws_strtoi32(tvb_get_string_enc(wmem_packet_scope(),
tvb, offset, 20, ENC_ASCII), NULL, &seq_num);
pi = proto_tree_add_string_format_value(soupbintcp_tree,
hf_soupbintcp_next_seq_num,
tvb, offset, 20,
"X", "%d", seq_num);
if (!seq_num_valid)
expert_add_info(pinfo, pi, &ei_soupbintcp_next_seq_num_invalid);
break;
case 'J':
proto_tree_add_item(soupbintcp_tree,
hf_soupbintcp_reject_code,
tvb, offset, 1, ENC_ASCII|ENC_NA);
break;
case 'U':
break;
case 'S':
proto_item_append_text(ti, ", SeqNum=%u", this_seq);
proto_tree_add_string_format_value(soupbintcp_tree,
hf_soupbintcp_seq_num,
tvb, offset, 0,
"X",
"%u (Calculated)",
this_seq);
break;
case 'L':
proto_tree_add_item(soupbintcp_tree,
hf_soupbintcp_username,
tvb, offset, 6, ENC_ASCII|ENC_NA);
offset += 6;
proto_tree_add_item(soupbintcp_tree,
hf_soupbintcp_password,
tvb, offset, 10, ENC_ASCII|ENC_NA);
offset += 10;
proto_tree_add_item(soupbintcp_tree,
hf_soupbintcp_session,
tvb, offset, 10, ENC_ASCII|ENC_NA);
offset += 10;
seq_num_valid = ws_strtoi32(tvb_get_string_enc(wmem_packet_scope(),
tvb, offset, 20, ENC_ASCII), NULL, &seq_num);
pi = proto_tree_add_string_format_value(soupbintcp_tree,
hf_soupbintcp_req_seq_num,
tvb, offset, 20,
"X", "%d", seq_num);
if (!seq_num_valid)
expert_add_info(pinfo, pi, &ei_soupbintcp_req_seq_num_invalid);
break;
case 'H':
break;
case 'O':
break;
case 'R':
break;
case 'Z':
break;
default:
proto_tree_add_item(tree,
hf_soupbintcp_message,
tvb, offset, -1, ENC_NA);
break;
}
}
if (pkt_type == 'S' || pkt_type == 'U') {
tvbuff_t *sub_tvb;
sub_tvb = tvb_new_subset_remaining(tvb, 3);
#if 0
if (try_conversation_dissector(&pinfo->dst, &pinfo->src, pinfo->ptype,
pinfo->srcport, pinfo->destport,
sub_tvb, pinfo, tree, NULL)) {
return;
}
#endif
if (dissector_try_heuristic(heur_subdissector_list,
sub_tvb,
pinfo,
tree,
&hdtbl_entry,
NULL)) {
return;
}
if (tree) {
proto_tree_add_item(soupbintcp_tree,
hf_soupbintcp_message,
sub_tvb, 0, -1,
ENC_NA);
}
}
}
static guint
get_soupbintcp_pdu_len(
packet_info *pinfo _U_,
tvbuff_t *tvb,
int offset,
void *data _U_)
{
return (guint)tvb_get_ntohs(tvb, offset) + 2;
}
static int
dissect_soupbintcp_tcp_pdu(
tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
void *data _U_)
{
dissect_soupbintcp_common(tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
static int
dissect_soupbintcp_tcp(
tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
void *data)
{
tcp_dissect_pdus(tvb, pinfo, tree,
soupbintcp_desegment, 2,
get_soupbintcp_pdu_len,
dissect_soupbintcp_tcp_pdu, data);
return tvb_captured_length(tvb);
}
void
proto_register_soupbintcp(void)
{
expert_module_t* expert_soupbinttcp;
static hf_register_info hf[] = {
{ &hf_soupbintcp_packet_length,
{ "Packet Length", "soupbintcp.packet_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Packet length, in bytes, NOT including these two bytes.",
HFILL }},
{ &hf_soupbintcp_packet_type,
{ "Packet Type", "soupbintcp.packet_type",
FT_CHAR, BASE_HEX, VALS(pkt_type_val), 0x0,
"Message type code",
HFILL }},
{ &hf_soupbintcp_reject_code,
{ "Login Reject Code", "soupbintcp.reject_code",
FT_CHAR, BASE_HEX, VALS(reject_code_val), 0x0,
"Login reject reason code",
HFILL }},
{ &hf_soupbintcp_message,
{ "Message", "soupbintcp.message",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Content of SoupBinTCP frame",
HFILL }},
{ &hf_soupbintcp_text,
{ "Debug Text", "soupbintcp.text",
FT_STRING, BASE_NONE, NULL, 0x0,
"Free-form, human-readable text",
HFILL }},
{ &hf_soupbintcp_username,
{ "User Name", "soupbintcp.username",
FT_STRING, BASE_NONE, NULL, 0x0,
"User's login name",
HFILL }},
{ &hf_soupbintcp_password,
{ "Password", "soupbintcp.password",
FT_STRING, BASE_NONE, NULL, 0x0,
"User's login password",
HFILL }},
{ &hf_soupbintcp_session,
{ "Session", "soupbintcp.session",
FT_STRING, BASE_NONE, NULL, 0x0,
"Session identifier, or send all spaces to log into the currently "
"active session",
HFILL }},
{ &hf_soupbintcp_seq_num,
{ "Sequence number", "soupbintcp.seq_num",
FT_STRING, BASE_NONE, NULL, 0x0,
"Calculated sequence number for this message",
HFILL }},
{ &hf_soupbintcp_next_seq_num,
{ "Next sequence number", "soupbintcp.next_seq_num",
FT_STRING, BASE_NONE, NULL, 0x0,
"Sequence number of next Sequenced Data message to be delivered",
HFILL }},
{ &hf_soupbintcp_req_seq_num,
{ "Requested sequence number", "soupbintcp.req_seq_num",
FT_STRING, BASE_NONE, NULL, 0x0,
"Request to begin (re)transmission of Sequenced Data at this "
"sequence number, or, if zero, to begin transmission with the "
"next message generated",
HFILL }}
};
static gint *ett[] = {
&ett_soupbintcp
};
static ei_register_info ei[] = {
{ &ei_soupbintcp_req_seq_num_invalid, { "soupbintcp.req_seq_num.invalid", PI_MALFORMED, PI_ERROR,
"Sequence number of next Sequenced Data message to be delivered is an invalid string", EXPFILL }},
{ &ei_soupbintcp_next_seq_num_invalid, { "soupbintcp.next_seq_num.invalid", PI_MALFORMED, PI_ERROR,
"Request to begin (re)transmission is an invalid string", EXPFILL }}
};
module_t *soupbintcp_module;
proto_soupbintcp = proto_register_protocol("SoupBinTCP", "SoupBinTCP", "soupbintcp");
proto_register_field_array(proto_soupbintcp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
soupbintcp_module = prefs_register_protocol(proto_soupbintcp, NULL);
prefs_register_bool_preference(
soupbintcp_module,
"desegment",
"Reassemble SoupBinTCP messages spanning multiple TCP segments",
"Whether the SoupBinTCP dissector should reassemble messages "
"spanning multiple TCP segments.",
&soupbintcp_desegment);
heur_subdissector_list = register_heur_dissector_list("soupbintcp", proto_soupbintcp);
expert_soupbinttcp = expert_register_protocol(proto_soupbintcp);
expert_register_field_array(expert_soupbinttcp, ei, array_length(ei));
}
void
proto_reg_handoff_soupbintcp(void)
{
soupbintcp_handle = create_dissector_handle(dissect_soupbintcp_tcp, proto_soupbintcp);
dissector_add_uint_range_with_preference("tcp.port", "", soupbintcp_handle);
}
