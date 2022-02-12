static void
dissect_chargen(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree* chargen_tree;
proto_item* ti = NULL;
guint8* data;
guint32 len;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Chargen");
col_set_str(pinfo->cinfo, COL_INFO, "Chargen");
ti = proto_tree_add_item(tree, proto_chargen, tvb, 0, -1, ENC_NA);
chargen_tree = proto_item_add_subtree(ti, ett_chargen);
len = tvb_reported_length(tvb);
data = tvb_get_string_enc(wmem_packet_scope(), tvb, 0, len, ENC_ASCII);
proto_tree_add_string_format(chargen_tree, hf_chargen_data, tvb, 0,
len, "Data", "Data (%u): %s", len, data);
}
void
proto_register_chargen(void)
{
static hf_register_info hf[] = {
{ &hf_chargen_data, {
"Data", "chargen.data", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_chargen,
};
proto_chargen = proto_register_protocol("Character Generator Protocol", "chargen",
"chargen");
proto_register_field_array(proto_chargen, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_chargen(void)
{
dissector_handle_t chargen_handle;
chargen_handle = create_dissector_handle(dissect_chargen, proto_chargen);
dissector_add_uint("udp.port", CHARGEN_PORT_UDP, chargen_handle);
dissector_add_uint("tcp.port", CHARGEN_PORT_TCP, chargen_handle);
}
