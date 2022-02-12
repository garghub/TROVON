static guint
dissect_ssprotocol_message(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *ssprotocol_tree)
{
proto_item* flags_item;
proto_tree* flags_tree;
guint8 type;
guint16 data_length;
guint16 info_length;
guint total_length;
type = tvb_get_guint8(message_tvb, MESSAGE_TYPE_OFFSET);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str(type, message_type_values, "Unknown SSP type: %u"));
}
proto_tree_add_item(ssprotocol_tree, hf_message_type, message_tvb, MESSAGE_TYPE_OFFSET, MESSAGE_TYPE_LENGTH, ENC_BIG_ENDIAN);
flags_item = proto_tree_add_item(ssprotocol_tree, hf_message_flags, message_tvb, MESSAGE_FLAGS_OFFSET, MESSAGE_FLAGS_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(ssprotocol_tree, hf_message_length, message_tvb, MESSAGE_LENGTH_OFFSET, MESSAGE_LENGTH_LENGTH, ENC_BIG_ENDIAN);
total_length = MESSAGE_LENGTH_OFFSET + MESSAGE_LENGTH_LENGTH;
switch (type) {
case SS_KEEPALIVE_ACK_TYPE:
case SS_STATUS_TYPE:
info_length = tvb_get_ntohs(message_tvb, MESSAGE_LENGTH_OFFSET) - MESSAGE_STATUS_OFFSET;
if (info_length == MESSAGE_STATUS_LENGTH) {
proto_tree_add_item(ssprotocol_tree, hf_message_status, message_tvb, MESSAGE_STATUS_OFFSET, MESSAGE_STATUS_LENGTH, ENC_BIG_ENDIAN);
total_length += MESSAGE_STATUS_LENGTH;
}
break;
case SS_UPLOAD_TYPE:
case SS_DOWNLOAD_TYPE:
data_length = tvb_get_ntohs(message_tvb, MESSAGE_LENGTH_OFFSET) - MESSAGE_DATA_OFFSET;
if (data_length > 0) {
proto_tree_add_item(ssprotocol_tree, hf_message_data, message_tvb, MESSAGE_DATA_OFFSET, data_length, ENC_NA);
total_length += data_length;
}
break;
case SS_READY_TYPE:
info_length = tvb_get_ntohs(message_tvb, MESSAGE_LENGTH_OFFSET) - MESSAGE_RDY_INFO_OFFSET;
if (info_length > 0) {
proto_tree_add_item(ssprotocol_tree, hf_message_info, message_tvb, MESSAGE_RDY_INFO_OFFSET, info_length, ENC_ASCII|ENC_NA);
total_length += info_length;
}
break;
case SS_NOTREADY_TYPE:
info_length = tvb_get_ntohs(message_tvb, MESSAGE_LENGTH_OFFSET) - MESSAGE_NOTRDY_INFO_OFFSET;
if (info_length > 0) {
proto_tree_add_item(ssprotocol_tree, hf_message_reason, message_tvb, MESSAGE_NOTRDY_REASON_OFFSET, MESSAGE_NOTRDY_REASON_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(ssprotocol_tree, hf_message_info, message_tvb, MESSAGE_NOTRDY_INFO_OFFSET, info_length, ENC_ASCII|ENC_NA);
total_length += info_length;
}
break;
case SS_ENVIRONMENT_TYPE:
flags_tree = proto_item_add_subtree(flags_item, ett_environment_flags);
proto_tree_add_item(flags_tree, hf_environment_u_bit, message_tvb, MESSAGE_FLAGS_OFFSET, MESSAGE_FLAGS_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(ssprotocol_tree, hf_message_hash, message_tvb, MESSAGE_ENVIRON_HASH_OFFSET, MESSAGE_ENVIRON_HASH_LENGTH, ENC_NA);
break;
default:
break;
}
return total_length;
}
static int
dissect_ssprotocol(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ssprotocol_item;
proto_tree *ssprotocol_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SSP");
if (tree) {
ssprotocol_item = proto_tree_add_item(tree, proto_ssprotocol, message_tvb, 0, -1, ENC_NA);
ssprotocol_tree = proto_item_add_subtree(ssprotocol_item, ett_ssprotocol);
} else {
ssprotocol_tree = NULL;
};
return dissect_ssprotocol_message(message_tvb, pinfo, ssprotocol_tree);
}
void
proto_register_ssprotocol(void)
{
static hf_register_info hf[] = {
{ &hf_message_type, { "Type", "ssp.message_type", FT_UINT8, BASE_DEC, VALS(message_type_values), 0x0, NULL, HFILL } },
{ &hf_message_flags, { "Flags", "ssp.message_flags", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_message_length, { "Length", "ssp.message_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_message_status, { "Status", "ssp.message_status", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_message_reason, { "Reason", "ssp.message_reason", FT_UINT32, BASE_DEC, VALS(notrdy_reason_values), 0x0, NULL, HFILL } },
{ &hf_message_info, { "Info", "ssp.message_info", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_message_data, { "Data", "ssp.message_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_message_hash, { "Hash", "ssp.message_hash", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_environment_u_bit, { "U-Bit", "ssp.environment_u_bit", FT_BOOLEAN, 8,TFS(&environment_u_bit), SSP_ENVIRONMENT_U_BIT, NULL, HFILL } }
};
static gint *ett[] = {
&ett_ssprotocol,
&ett_environment_flags
};
proto_ssprotocol = proto_register_protocol("Scripting Service Protocol", "SSP", "ssp");
proto_register_field_array(proto_ssprotocol, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_ssprotocol(void)
{
dissector_handle_t ssprotocol_handle;
ssprotocol_handle = new_create_dissector_handle(dissect_ssprotocol, proto_ssprotocol);
dissector_add_uint("sctp.ppi", SSPROTOCOL_PAYLOAD_PROTOCOL_ID_LEGACY, ssprotocol_handle);
dissector_add_uint("sctp.ppi", SSP_PAYLOAD_PROTOCOL_ID, ssprotocol_handle);
}
