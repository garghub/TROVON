static void
dissect_calcappprotocol_message(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *calcappprotocol_tree)
{
guint8 type;
type = tvb_get_guint8(message_tvb, MESSAGE_TYPE_OFFSET);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str_const(type, message_type_values, "Unknown CalcAppProtocol type"));
proto_tree_add_item(calcappprotocol_tree, hf_message_type, message_tvb, MESSAGE_TYPE_OFFSET, MESSAGE_TYPE_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(calcappprotocol_tree, hf_message_flags, message_tvb, MESSAGE_FLAGS_OFFSET, MESSAGE_FLAGS_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(calcappprotocol_tree, hf_message_length, message_tvb, MESSAGE_LENGTH_OFFSET, MESSAGE_LENGTH_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(calcappprotocol_tree, hf_message_jobid, message_tvb, MESSAGE_JOBID_OFFSET, MESSAGE_JOBID_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(calcappprotocol_tree, hf_message_jobsize, message_tvb, MESSAGE_JOBSIZE_OFFSET, MESSAGE_JOBSIZE_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(calcappprotocol_tree, hf_message_completed, message_tvb, MESSAGE_COMPLETED_OFFSET, MESSAGE_COMPLETED_LENGTH, ENC_BIG_ENDIAN);
}
static int
dissect_calcappprotocol(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *calcappprotocol_item;
proto_tree *calcappprotocol_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CalcAppProtocol");
if (tree) {
calcappprotocol_item = proto_tree_add_item(tree, proto_calcappprotocol, message_tvb, 0, -1, ENC_NA);
calcappprotocol_tree = proto_item_add_subtree(calcappprotocol_item, ett_calcappprotocol);
} else {
calcappprotocol_tree = NULL;
};
dissect_calcappprotocol_message(message_tvb, pinfo, calcappprotocol_tree);
return(TRUE);
}
void
proto_register_calcappprotocol(void)
{
static hf_register_info hf[] = {
{ &hf_message_type, { "Type", "calcappprotocol.message_type", FT_UINT8, BASE_DEC, VALS(message_type_values), 0x0, NULL, HFILL } },
{ &hf_message_flags, { "Flags", "calcappprotocol.message_flags", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_message_length, { "Length", "calcappprotocol.message_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_message_jobid, { "JobID", "calcappprotocol.message_jobid", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_message_jobsize, { "JobSize", "calcappprotocol.message_jobsize", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_message_completed, { "Completed", "calcappprotocol.message_completed", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL } },
};
static gint *ett[] = {
&ett_calcappprotocol
};
proto_calcappprotocol = proto_register_protocol("Calculation Application Protocol", "CalcAppProtocol", "calcappprotocol");
proto_register_field_array(proto_calcappprotocol, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_calcappprotocol(void)
{
dissector_handle_t calcappprotocol_handle;
calcappprotocol_handle = new_create_dissector_handle(dissect_calcappprotocol, proto_calcappprotocol);
dissector_add_uint("sctp.ppi", CALCAPPPROTOCOL_PAYLOAD_PROTOCOL_ID_LEGACY, calcappprotocol_handle);
dissector_add_uint("sctp.ppi", CALCAPP_PAYLOAD_PROTOCOL_ID, calcappprotocol_handle);
}
