static void
dissect_teimanagement(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *tei_tree = NULL;
proto_item *tei_ti;
guint8 message;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TEI");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
tei_ti = proto_tree_add_item(tree, proto_tei, tvb, 0, 5, ENC_NA);
tei_tree = proto_item_add_subtree(tei_ti, lm_subtree);
proto_tree_add_item(tei_tree, lm_entity_id, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tei_tree, lm_reference, tvb, 1, 2, ENC_BIG_ENDIAN);
}
message = tvb_get_guint8(tvb, 3);
if (check_col(pinfo->cinfo, COL_INFO))
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(message, tei_msg_vals, "Unknown message type (0x%04x)"));
if (tree) {
proto_tree_add_uint(tei_tree, lm_message, tvb, 3, 1, message);
proto_tree_add_item(tei_tree, lm_action, tvb, 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tei_tree, lm_extend, tvb, 4, 1, ENC_BIG_ENDIAN);
}
}
void
proto_register_teimanagement(void)
{
static gint *subtree[]={
&lm_subtree
};
static hf_register_info hf[] = {
{ &lm_entity_id,
{ "Entity", "tei.entity", FT_UINT8, BASE_HEX, NULL, 0x0,
"Layer Management Entity Identifier", HFILL }},
{ &lm_reference,
{ "Reference", "tei.reference", FT_UINT16, BASE_DEC, NULL, 0x0,
"Reference Number", HFILL }},
{ &lm_message,
{ "Msg", "tei.msg", FT_UINT8, BASE_DEC, VALS(tei_msg_vals), 0x0,
"Message Type", HFILL }},
{ &lm_action,
{ "Action", "tei.action", FT_UINT8, BASE_DEC, NULL, 0xfe,
"Action Indicator", HFILL }},
{ &lm_extend,
{ "Extend", "tei.extend", FT_UINT8, BASE_DEC, NULL, 0x01,
"Extension Indicator", HFILL }}
};
proto_tei = proto_register_protocol("TEI Management Procedure, Channel D (LAPD)",
"TEI_MANAGEMENT", "tei_management");
proto_register_field_array (proto_tei, hf, array_length(hf));
proto_register_subtree_array(subtree, array_length(subtree));
}
void
proto_reg_handoff_teimanagement(void)
{
dissector_handle_t teimanagement_handle;
teimanagement_handle = create_dissector_handle(dissect_teimanagement,
proto_tei);
dissector_add_uint("lapd.sapi", LAPD_SAPI_L2, teimanagement_handle);
}
