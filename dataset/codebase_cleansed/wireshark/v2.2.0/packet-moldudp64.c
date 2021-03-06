static void moldudp64_prompt(packet_info *pinfo _U_, gchar* result)
{
g_snprintf(result, MAX_DECODE_AS_PROMPT_LEN, "Payload as");
}
static gpointer moldudp64_value(packet_info *pinfo _U_)
{
return 0;
}
static guint
dissect_moldudp64_msgblk(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, guint64 sequence)
{
proto_item *ti;
proto_tree *blk_tree;
guint16 msglen, real_msglen, whole_len;
gint remaining;
tvbuff_t* next_tvb;
if (tvb_captured_length_remaining(tvb, offset) < MOLDUDP64_MSGLEN_LEN)
return 0;
msglen = tvb_get_ntohs(tvb, offset);
remaining = tvb_reported_length(tvb) - offset - MOLDUDP64_MSGLEN_LEN;
if (remaining < 0)
real_msglen = 0;
else if (msglen <= remaining)
real_msglen = msglen;
else
real_msglen = remaining;
whole_len = real_msglen + MOLDUDP64_MSGLEN_LEN;
ti = proto_tree_add_item(tree, hf_moldudp64_msgblk,
tvb, offset, whole_len, ENC_NA);
blk_tree = proto_item_add_subtree(ti, ett_moldudp64_msgblk);
ti = proto_tree_add_uint64(blk_tree, hf_moldudp64_msgseq,
tvb, offset, 0, sequence);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_item(blk_tree, hf_moldudp64_msglen,
tvb, offset, MOLDUDP64_MSGLEN_LEN, ENC_BIG_ENDIAN);
if (msglen != real_msglen)
expert_add_info_format(pinfo, ti, &ei_moldudp64_msglen_invalid,
"Invalid Message Length (claimed %u, found %u)",
msglen, real_msglen);
offset += MOLDUDP64_MSGLEN_LEN;
next_tvb = tvb_new_subset_length(tvb, offset, real_msglen);
if (!dissector_try_uint_new(moldudp64_payload_table, 0, next_tvb, pinfo, tree, FALSE, NULL))
{
proto_tree_add_item(blk_tree, hf_moldudp64_msgdata, tvb, offset, real_msglen, ENC_NA);
}
return whole_len;
}
static int
dissect_moldudp64(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *moldudp64_tree;
guint offset = 0;
guint16 count, real_count = 0;
guint64 sequence;
if (tvb_reported_length(tvb) < (MOLDUDP64_SESSION_LEN +
MOLDUDP64_SEQUENCE_LEN +
MOLDUDP64_COUNT_LEN))
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MoldUDP64");
col_clear(pinfo->cinfo, COL_INFO);
sequence = tvb_get_ntoh64(tvb, MOLDUDP64_SESSION_LEN);
count = tvb_get_ntohs(tvb, MOLDUDP64_SESSION_LEN + MOLDUDP64_SEQUENCE_LEN);
if (count == MOLDUDP64_HEARTBEAT)
col_set_str(pinfo->cinfo, COL_INFO, "MoldUDP64 Heartbeat");
else if (count == MOLDUDP64_ENDOFSESS)
col_set_str(pinfo->cinfo, COL_INFO, "MoldUDP64 End Of Session");
else if (count > 0 && tvb_reported_length(tvb) == (MOLDUDP64_SESSION_LEN +
MOLDUDP64_SEQUENCE_LEN +
MOLDUDP64_COUNT_LEN))
col_set_str(pinfo->cinfo, COL_INFO, "MoldUDP64 Request");
else
col_set_str(pinfo->cinfo, COL_INFO, "MoldUDP64 Messages");
ti = proto_tree_add_item(tree, proto_moldudp64,
tvb, offset, -1, ENC_NA);
moldudp64_tree = proto_item_add_subtree(ti, ett_moldudp64);
proto_tree_add_item(moldudp64_tree, hf_moldudp64_session,
tvb, offset, MOLDUDP64_SESSION_LEN, ENC_ASCII|ENC_NA);
offset += MOLDUDP64_SESSION_LEN;
proto_tree_add_item(moldudp64_tree, hf_moldudp64_sequence,
tvb, offset, MOLDUDP64_SEQUENCE_LEN, ENC_BIG_ENDIAN);
offset += MOLDUDP64_SEQUENCE_LEN;
ti = proto_tree_add_item(moldudp64_tree, hf_moldudp64_count,
tvb, offset, MOLDUDP64_COUNT_LEN, ENC_BIG_ENDIAN);
offset += MOLDUDP64_COUNT_LEN;
while (tvb_reported_length(tvb) >= offset + MOLDUDP64_MSGLEN_LEN)
{
offset += dissect_moldudp64_msgblk(tvb, pinfo, moldudp64_tree,
offset, sequence++);
real_count++;
}
if (count == MOLDUDP64_ENDOFSESS && real_count != 0)
{
expert_add_info(pinfo, ti, &ei_moldudp64_end_of_session_extra);
}
else if (count > 0 && real_count == 0)
{
expert_add_info(pinfo, ti, &ei_moldudp64_request);
}
else if (real_count != count)
{
expert_add_info_format(pinfo, ti, &ei_moldudp64_count_invalid,
"Invalid Message Count (claimed %u, found %u)",
count, real_count);
}
return tvb_captured_length(tvb);
}
void
proto_register_moldudp64(void)
{
module_t *moldudp64_module;
static hf_register_info hf[] = {
{ &hf_moldudp64_session,
{ "Session", "moldudp64.session", FT_STRING, BASE_NONE, NULL, 0,
"The session to which this packet belongs.", HFILL }},
{ &hf_moldudp64_sequence,
{ "Sequence", "moldudp64.sequence", FT_UINT64, BASE_DEC, NULL, 0,
"The sequence number of the first message in this packet.", HFILL }},
{ &hf_moldudp64_count,
{ "Count", "moldudp64.count", FT_UINT16, BASE_DEC, NULL, 0,
"The number of messages contained in this packet.", HFILL }},
{ &hf_moldudp64_msgblk,
{ "Message Block", "moldudp64.msgblock", FT_NONE, BASE_NONE, NULL, 0,
"A message.", HFILL }},
{ &hf_moldudp64_msglen,
{ "Length", "moldudp64.msglen", FT_UINT16, BASE_DEC, NULL, 0,
"The length of this message.", HFILL }},
{ &hf_moldudp64_msgseq,
{ "Sequence", "moldudp64.msgseq", FT_UINT64, BASE_DEC, NULL, 0,
"The sequence number of this message.", HFILL }},
{ &hf_moldudp64_msgdata,
{ "Payload", "moldudp64.msgdata", FT_BYTES, BASE_NONE, NULL, 0,
"The payload data of this message.", HFILL }}
};
static gint *ett[] = {
&ett_moldudp64,
&ett_moldudp64_msgblk
};
static ei_register_info ei[] = {
{ &ei_moldudp64_msglen_invalid, { "moldudp64.msglen.invalid", PI_MALFORMED, PI_ERROR, "Invalid Message Length", EXPFILL }},
{ &ei_moldudp64_end_of_session_extra, { "moldudp64.end_of_session_extra", PI_MALFORMED, PI_ERROR, "End Of Session packet with extra data.", EXPFILL }},
{ &ei_moldudp64_count_invalid, { "moldudp64.count.invalid", PI_MALFORMED, PI_ERROR, "Invalid Message Count", EXPFILL }},
{ &ei_moldudp64_request, { "moldudp64.request", PI_COMMENTS_GROUP, PI_COMMENT, "Number of Requested Messages", EXPFILL }},
};
expert_module_t* expert_moldudp64;
static build_valid_func moldudp64_da_build_value[1] = {moldudp64_value};
static decode_as_value_t moldudp64_da_values = {moldudp64_prompt, 1, moldudp64_da_build_value};
static decode_as_t moldudp64_da = {"moldudp64", "MoldUDP64 Payload", "moldudp64.payload", 1, 0, &moldudp64_da_values, NULL, NULL,
decode_as_default_populate_list, decode_as_default_reset, decode_as_default_change, NULL};
proto_moldudp64 = proto_register_protocol("MoldUDP64",
"MoldUDP64", "moldudp64");
moldudp64_payload_table = register_dissector_table("moldudp64.payload", "MoldUDP64 Payload", proto_moldudp64, FT_UINT32, BASE_DEC);
proto_register_field_array(proto_moldudp64, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_moldudp64 = expert_register_protocol(proto_moldudp64);
expert_register_field_array(expert_moldudp64, ei, array_length(ei));
moldudp64_module = prefs_register_protocol(proto_moldudp64,
proto_reg_handoff_moldudp64);
prefs_register_uint_preference(moldudp64_module, "udp.port", "MoldUDP64 UDP Port",
"MoldUDP64 UDP port to dissect on.",
10, &pf_moldudp64_port);
register_decode_as(&moldudp64_da);
}
void
proto_reg_handoff_moldudp64(void)
{
static gboolean initialized = FALSE;
static dissector_handle_t moldudp64_handle;
static int currentPort;
if (!initialized) {
moldudp64_handle = create_dissector_handle(dissect_moldudp64,
proto_moldudp64);
initialized = TRUE;
} else {
dissector_delete_uint("udp.port", currentPort, moldudp64_handle);
}
currentPort = pf_moldudp64_port;
dissector_add_uint("udp.port", currentPort, moldudp64_handle);
}
