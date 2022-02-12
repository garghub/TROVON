static guint
dissect_moldudp_msgblk(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, guint32 sequence)
{
proto_item *ti;
proto_tree *blk_tree;
guint16 msglen, real_msglen, whole_len;
guint remaining;
if (tvb_reported_length(tvb) - offset < MOLDUDP_MSGLEN_LEN)
return 0;
msglen = tvb_get_letohs(tvb, offset);
remaining = tvb_reported_length(tvb) - offset - MOLDUDP_MSGLEN_LEN;
if (msglen == 0)
col_set_str(pinfo->cinfo, COL_INFO, "MoldUDP Messages (End Of Session)");
if (tvb_reported_length(tvb) < (offset + MOLDUDP_MSGLEN_LEN))
real_msglen = 0;
else if (msglen <= remaining)
real_msglen = msglen;
else
real_msglen = remaining;
whole_len = real_msglen + MOLDUDP_MSGLEN_LEN;
ti = proto_tree_add_item(tree, hf_moldudp_msgblk,
tvb, offset, whole_len, ENC_NA);
blk_tree = proto_item_add_subtree(ti, ett_moldudp_msgblk);
ti = proto_tree_add_uint(blk_tree, hf_moldudp_msgseq,
tvb, offset, 0, sequence);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_item(blk_tree, hf_moldudp_msglen,
tvb, offset, MOLDUDP_MSGLEN_LEN, ENC_LITTLE_ENDIAN);
if (msglen != real_msglen)
expert_add_info_format(pinfo, ti, &ei_moldudp_msglen_invalid,
"Invalid Message Length (claimed %u, found %u)",
msglen, real_msglen);
offset += MOLDUDP_MSGLEN_LEN;
proto_tree_add_item(blk_tree, hf_moldudp_msgdata,
tvb, offset, real_msglen, ENC_NA);
return whole_len;
}
static int
dissect_moldudp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *moldudp_tree;
guint offset = 0;
guint16 count, real_count = 0;
guint32 sequence;
if (tvb_reported_length(tvb) < (MOLDUDP_SESSION_LEN +
MOLDUDP_SEQUENCE_LEN +
MOLDUDP_COUNT_LEN))
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MoldUDP");
col_clear(pinfo->cinfo, COL_INFO);
count = tvb_get_letohs(tvb, MOLDUDP_SESSION_LEN + MOLDUDP_SEQUENCE_LEN);
if (count == MOLDUDP_HEARTBEAT)
col_set_str(pinfo->cinfo, COL_INFO, "MoldUDP Heartbeat");
else
col_set_str(pinfo->cinfo, COL_INFO, "MoldUDP Messages");
ti = proto_tree_add_item(tree, proto_moldudp,
tvb, offset, -1, ENC_NA);
moldudp_tree = proto_item_add_subtree(ti, ett_moldudp);
proto_tree_add_item(moldudp_tree, hf_moldudp_session,
tvb, offset, MOLDUDP_SESSION_LEN, ENC_ASCII|ENC_NA);
offset += MOLDUDP_SESSION_LEN;
sequence = tvb_get_letohl(tvb, offset);
proto_tree_add_item(moldudp_tree, hf_moldudp_sequence,
tvb, offset, MOLDUDP_SEQUENCE_LEN, ENC_LITTLE_ENDIAN);
offset += MOLDUDP_SEQUENCE_LEN;
ti = proto_tree_add_item(moldudp_tree, hf_moldudp_count,
tvb, offset, MOLDUDP_COUNT_LEN, ENC_LITTLE_ENDIAN);
offset += MOLDUDP_COUNT_LEN;
while (tvb_reported_length(tvb) >= offset + MOLDUDP_MSGLEN_LEN)
{
offset += dissect_moldudp_msgblk(tvb, pinfo, moldudp_tree,
offset, sequence++);
real_count++;
}
if (real_count != count)
{
expert_add_info_format(pinfo, ti, &ei_moldudp_count_invalid,
"Invalid Message Count (claimed %u, found %u)",
count, real_count);
}
return tvb_length(tvb);
}
void
proto_register_moldudp(void)
{
module_t *moldudp_module;
static hf_register_info hf[] = {
{ &hf_moldudp_session,
{ "Session", "moldudp.session", FT_STRING, BASE_NONE, NULL, 0,
"The session to which this packet belongs.", HFILL }},
{ &hf_moldudp_sequence,
{ "Sequence", "moldudp.sequence", FT_UINT32, BASE_DEC, NULL, 0,
"The sequence number of the first message in this packet.", HFILL }},
{ &hf_moldudp_count,
{ "Count", "moldudp.count", FT_UINT16, BASE_DEC, NULL, 0,
"The number of messages contained in this packet.", HFILL }},
{ &hf_moldudp_msgblk,
{ "Message Block", "moldudp.msgblock", FT_NONE, BASE_NONE, NULL, 0,
"A message.", HFILL }},
{ &hf_moldudp_msglen,
{ "Length", "moldudp.msglen", FT_UINT16, BASE_DEC, NULL, 0,
"The length of this message.", HFILL }},
{ &hf_moldudp_msgseq,
{ "Sequence", "moldudp.msgseq", FT_UINT32, BASE_DEC, NULL, 0,
"The sequence number of this message.", HFILL }},
{ &hf_moldudp_msgdata,
{ "Payload", "moldudp.msgdata", FT_BYTES, BASE_NONE, NULL, 0,
"The payload data of this message.", HFILL }}
};
static gint *ett[] = {
&ett_moldudp,
&ett_moldudp_msgblk
};
static ei_register_info ei[] = {
{ &ei_moldudp_msglen_invalid, { "moldudp.msglen.invalid", PI_MALFORMED, PI_ERROR, "Invalid Message Length", EXPFILL }},
{ &ei_moldudp_count_invalid, { "moldudp.count.invalid", PI_MALFORMED, PI_ERROR, "Invalid Count", EXPFILL }},
};
expert_module_t* expert_moldudp;
proto_moldudp = proto_register_protocol("MoldUDP",
"MoldUDP", "moldudp");
proto_register_field_array(proto_moldudp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_moldudp = expert_register_protocol(proto_moldudp);
expert_register_field_array(expert_moldudp, ei, array_length(ei));
moldudp_module = prefs_register_protocol(proto_moldudp,
proto_reg_handoff_moldudp);
prefs_register_uint_preference(moldudp_module, "udp.port", "MoldUDP UDP Port",
"MoldUDP UDP port to capture on.",
10, &pf_moldudp_port);
}
void
proto_reg_handoff_moldudp(void)
{
static gboolean initialized = FALSE;
static dissector_handle_t moldudp_handle;
static int currentPort;
if (!initialized) {
moldudp_handle = new_create_dissector_handle(dissect_moldudp,
proto_moldudp);
initialized = TRUE;
} else {
dissector_delete_uint("udp.port", currentPort, moldudp_handle);
}
currentPort = pf_moldudp_port;
dissector_add_uint("udp.port", currentPort, moldudp_handle);
}
