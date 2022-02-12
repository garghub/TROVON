static int
dissect_maap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint8 maap_msg_type;
proto_item *maap_item = NULL;
proto_tree *maap_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MAAP");
col_clear(pinfo->cinfo, COL_INFO);
maap_msg_type = tvb_get_guint8(tvb, MAAP_MSG_TYPE_OFFSET);
maap_msg_type &= 0x0f;
col_add_fstr(pinfo->cinfo, COL_INFO, "%s:",
val_to_str(maap_msg_type, maap_msg_type_vals,
"Unknown Type(0x%02x)"));
switch (maap_msg_type)
{
case MAAP_MSG_TYPE_PROBE:
case MAAP_MSG_TYPE_ANNOUNCE:
col_append_fstr(pinfo->cinfo, COL_INFO, " req_start=%s, cnt=%d",
tvb_ether_to_str(tvb, MAAP_REQ_START_ADDR_OFFSET),
tvb_get_ntohs(tvb, MAAP_REQ_COUNT_OFFSET));
break;
case MAAP_MSG_TYPE_DEFEND:
col_append_fstr(pinfo->cinfo, COL_INFO, " conflict_start=%s, cnt=%d",
tvb_ether_to_str(tvb, MAAP_CONFLICT_START_ADDR_OFFSET),
tvb_get_ntohs(tvb, MAAP_CONFLICT_COUNT_OFFSET));
break;
default:
break;
}
if (tree) {
maap_item = proto_tree_add_item(tree, proto_maap, tvb, MAAP_START_OFFSET, -1, ENC_NA);
maap_tree = proto_item_add_subtree(maap_item, ett_maap);
proto_tree_add_item(maap_tree, hf_maap_message_type, tvb, MAAP_MSG_TYPE_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(maap_tree, hf_maap_version, tvb, MAAP_VERSION_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(maap_tree, hf_maap_data_length, tvb, MAAP_VERSION_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(maap_tree, hf_maap_stream_id, tvb, MAAP_STREAM_ID_OFFSET, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(maap_tree, hf_maap_req_start_addr, tvb, MAAP_REQ_START_ADDR_OFFSET, 6, ENC_NA);
proto_tree_add_item(maap_tree, hf_maap_req_count, tvb, MAAP_REQ_COUNT_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(maap_tree, hf_maap_conflict_start_addr, tvb, MAAP_CONFLICT_START_ADDR_OFFSET, 6, ENC_NA);
proto_tree_add_item(maap_tree, hf_maap_conflict_count, tvb, MAAP_CONFLICT_COUNT_OFFSET, 2, ENC_BIG_ENDIAN);
}
return tvb_captured_length(tvb);
}
void
proto_register_maap(void)
{
static hf_register_info hf[] = {
{ &hf_maap_message_type,
{ "Message Type", "maap.message_type",
FT_UINT8, BASE_HEX,
VALS(maap_msg_type_vals), MAAP_MSG_TYPE_MASK,
NULL, HFILL }},
{ &hf_maap_version,
{ "MAAP Version", "maap.version",
FT_UINT8, BASE_HEX,
NULL, MAAP_VERSION_MASK,
NULL, HFILL }},
{ &hf_maap_data_length,
{ "Data Length", "maap.data_length",
FT_UINT16, BASE_HEX,
NULL, MAAP_DATA_LEN_MASK,
NULL, HFILL }},
{ &hf_maap_stream_id,
{ "Stream ID", "maap.stream_id",
FT_UINT64, BASE_HEX,
NULL, 0x00,
NULL, HFILL }},
{ &hf_maap_req_start_addr,
{ "Requested Start Address", "maap.req_start_addr",
FT_ETHER, BASE_NONE,
NULL, 0x00,
NULL, HFILL }},
{ &hf_maap_req_count,
{ "Request Count", "maap.req_count",
FT_UINT16, BASE_HEX,
NULL, 0x00,
NULL, HFILL }},
{ &hf_maap_conflict_start_addr,
{ "Conflict Start Address", "maap.conflict_start_addr",
FT_ETHER, BASE_NONE,
NULL, 0x00,
NULL, HFILL }},
{ &hf_maap_conflict_count,
{ "Conflict Count", "maap.conflict_count",
FT_UINT16, BASE_HEX,
NULL, 0x00,
NULL, HFILL }}
};
static gint *ett[] = { &ett_maap };
proto_maap = proto_register_protocol (
"IEEE 1722 MAAP Protocol",
"MAAP",
"maap"
);
proto_register_field_array(proto_maap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_maap(void)
{
dissector_handle_t maap_handle;
maap_handle = create_dissector_handle(dissect_maap, proto_maap);
dissector_add_uint("ieee1722.subtype", 0x7E, maap_handle);
}
