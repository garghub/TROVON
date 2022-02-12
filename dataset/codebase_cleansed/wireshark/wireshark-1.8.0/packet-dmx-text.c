static void
dissect_dmx_text(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DMX Text");
col_clear(pinfo->cinfo, COL_INFO);
if (tree != NULL) {
unsigned offset = 0;
unsigned size;
proto_tree *ti = proto_tree_add_item(tree, proto_dmx_text, tvb,
offset, -1, FALSE);
proto_tree *dmx_text_tree = proto_item_add_subtree(ti, ett_dmx_text);
proto_tree_add_item(dmx_text_tree, hf_dmx_text_page_nr, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(dmx_text_tree, hf_dmx_text_line_len, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
size = tvb_reported_length_remaining(tvb, offset);
proto_tree_add_item(dmx_text_tree, hf_dmx_text_string, tvb,
offset, size, ENC_BIG_ENDIAN);
offset += size;
}
}
void
proto_register_dmx_text(void)
{
static hf_register_info hf[] = {
{ &hf_dmx_text_page_nr,
{ "Page Number",
"dmx_text.page_nr",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dmx_text_line_len,
{ "Line Length",
"dmx_text.line_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dmx_text_string,
{ "Text String",
"dmx_text.string",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_dmx_text
};
proto_dmx_text = proto_register_protocol("DMX Text Frame", "DMX Text Frame", "dmx-text");
proto_register_field_array(proto_dmx_text, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("dmx-text", dissect_dmx_text, proto_dmx_text);
}
void
proto_reg_handoff_dmx_text(void)
{
}
