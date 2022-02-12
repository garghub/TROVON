static void
dissect_pingpongprotocol_ping_message(tvbuff_t *message_tvb, proto_tree *message_tree)
{
guint16 ping_data_length;
proto_tree_add_item(message_tree, hf_ping_messageno, message_tvb, PING_MESSAGENO_OFFSET, PING_MESSAGENO_LENGTH, ENC_BIG_ENDIAN);
ping_data_length = tvb_get_ntohs(message_tvb, MESSAGE_LENGTH_OFFSET) - PING_DATA_OFFSET;
if (ping_data_length > 0)
proto_tree_add_item(message_tree, hf_ping_data, message_tvb, PING_DATA_OFFSET, ping_data_length, ENC_NA);
}
static void
dissect_pingpongprotocol_pong_message(tvbuff_t *message_tvb, proto_tree *message_tree)
{
guint16 pong_data_length;
proto_tree_add_item(message_tree, hf_pong_messageno, message_tvb, PONG_MESSAGENO_OFFSET, PONG_MESSAGENO_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(message_tree, hf_pong_replyno, message_tvb, PONG_REPLYNO_OFFSET, PONG_REPLYNO_LENGTH, ENC_BIG_ENDIAN);
pong_data_length = tvb_get_ntohs(message_tvb, MESSAGE_LENGTH_OFFSET) - PONG_DATA_OFFSET;
if (pong_data_length > 0) {
proto_tree_add_item(message_tree, hf_pong_data, message_tvb, PONG_DATA_OFFSET, pong_data_length, ENC_NA);
}
}
static void
dissect_pingpongprotocol_message(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *pingpongprotocol_tree)
{
guint8 type;
type = tvb_get_guint8(message_tvb, MESSAGE_TYPE_OFFSET);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str(type, message_type_values, "Unknown PingPongProtocol type"));
}
proto_tree_add_item(pingpongprotocol_tree, hf_message_type, message_tvb, MESSAGE_TYPE_OFFSET, MESSAGE_TYPE_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(pingpongprotocol_tree, hf_message_flags, message_tvb, MESSAGE_FLAGS_OFFSET, MESSAGE_FLAGS_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(pingpongprotocol_tree, hf_message_length, message_tvb, MESSAGE_LENGTH_OFFSET, MESSAGE_LENGTH_LENGTH, ENC_BIG_ENDIAN);
switch (type) {
case PINGPONG_PING_MESSAGE_TYPE:
dissect_pingpongprotocol_ping_message(message_tvb, pingpongprotocol_tree);
break;
case PINGPONG_PONG_MESSAGE_TYPE:
dissect_pingpongprotocol_pong_message(message_tvb, pingpongprotocol_tree);
break;
}
}
static int
dissect_pingpongprotocol(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *pingpongprotocol_item;
proto_tree *pingpongprotocol_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PingPongProtocol");
if (tree) {
pingpongprotocol_item = proto_tree_add_item(tree, proto_pingpongprotocol, message_tvb, 0, -1, ENC_NA);
pingpongprotocol_tree = proto_item_add_subtree(pingpongprotocol_item, ett_pingpongprotocol);
} else {
pingpongprotocol_tree = NULL;
};
dissect_pingpongprotocol_message(message_tvb, pinfo, pingpongprotocol_tree);
return(TRUE);
}
void
proto_register_pingpongprotocol(void)
{
static hf_register_info hf[] = {
{ &hf_message_type, { "Type", "pingpongprotocol.message_type", FT_UINT8, BASE_DEC, VALS(message_type_values), 0x0, NULL, HFILL } },
{ &hf_message_flags, { "Flags", "pingpongprotocol.message_flags", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_message_length, { "Length", "pingpongprotocol.message_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_ping_messageno, { "MessageNo", "pingpongprotocol.ping_messageno", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_ping_data, { "Ping_Data", "pingpongprotocol.ping_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_pong_messageno, { "MessageNo", "pingpongprotocol.pong_messageno", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_pong_replyno, { "ReplyNo", "pingpongprotocol.pong_replyno", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_pong_data, { "Pong_Data", "pingpongprotocol.pong_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
};
static gint *ett[] = {
&ett_pingpongprotocol
};
proto_pingpongprotocol = proto_register_protocol("Ping Pong Protocol", "PingPongProtocol", "pingpongprotocol");
proto_register_field_array(proto_pingpongprotocol, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_pingpongprotocol(void)
{
dissector_handle_t pingpongprotocol_handle;
pingpongprotocol_handle = new_create_dissector_handle(dissect_pingpongprotocol, proto_pingpongprotocol);
dissector_add_uint("sctp.ppi", PINGPONGPROTOCOL_PAYLOAD_PROTOCOL_ID_LEGACY, pingpongprotocol_handle);
dissector_add_uint("sctp.ppi", PPP_PAYLOAD_PROTOCOL_ID, pingpongprotocol_handle);
}
