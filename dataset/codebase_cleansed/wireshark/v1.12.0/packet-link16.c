static int dissect_link16(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
Link16State *state = (Link16State *)data;
proto_item *link16_item = NULL;
proto_tree *link16_tree = NULL;
guint16 cache;
guint8 wordformat, contlabel;
if (!state)
REPORT_DISSECTOR_BUG("Link 16 dissector state missing");
cache = tvb_get_letohs(tvb, 0);
wordformat = cache & 0x3;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Link 16");
if (tree) {
link16_item = proto_tree_add_item(tree, proto_link16, tvb, 0, -1, ENC_NA);
link16_tree = proto_item_add_subtree(link16_item, ett_link16);
proto_tree_add_bitmask_text(link16_tree, tvb, 0, 2, "Header", NULL, ett_link16, link16_fields[wordformat], ENC_LITTLE_ENDIAN, BMT_NO_APPEND);
}
switch (wordformat) {
case WORDFORMAT_INITIAL:
state->label = (cache >> 2) & 0x1F;
state->sublabel = (cache >> 7) & 0x7;
state->extension = 0;
col_append_fstr(pinfo->cinfo, COL_INFO, " J%d.%dI", state->label, state->sublabel);
proto_item_append_text(link16_item, " J%d.%dI", state->label, state->sublabel);
break;
case WORDFORMAT_EXTENSION:
col_append_fstr(pinfo->cinfo, COL_INFO, " J%d.%dE%d", state->label, state->sublabel, state->extension);
proto_item_append_text(link16_item, " J%d.%dE%d", state->label, state->sublabel, state->extension);
state->extension++;
break;
case WORDFORMAT_CONTINUATION:
contlabel = (cache >> 2) & 0x1F;
col_append_fstr(pinfo->cinfo, COL_INFO, " J%d.%dC%d", state->label, state->sublabel, contlabel);
proto_item_append_text(link16_item, " J%d.%dC%d", state->label, state->sublabel, contlabel);
}
proto_item_append_text(link16_item, " %s", val_to_str_const(MKPAIR(state->label, state->sublabel), Link16_Message_Strings, "Unknown"));
return tvb_captured_length(tvb);
}
void proto_register_link16(void)
{
static hf_register_info hf[] = {
{ &hf_link16_wordformat,
{ "Word Format", "link16.wordformat", FT_UINT16, BASE_DEC, VALS(WordFormat_Strings), 0x3,
NULL, HFILL }},
{ &hf_link16_label,
{ "Label", "link16.label", FT_UINT16, BASE_DEC, VALS(Link16_Label_Strings), 0x7C,
NULL, HFILL }},
{ &hf_link16_sublabel,
{ "Sublabel", "link16.sublabel", FT_UINT16, BASE_DEC, NULL, 0x380,
NULL, HFILL }},
{ &hf_link16_mli,
{ "Message Length Indicator", "link16.mli", FT_UINT16, BASE_DEC, NULL, 0x1C00,
NULL, HFILL }},
{ &hf_link16_contlabel,
{ "Continuation Word Label", "link16.contlabel", FT_UINT16, BASE_DEC, NULL, 0x7C,
NULL, HFILL }}
};
static gint *ett[] = {
&ett_link16,
};
proto_link16 = proto_register_protocol("Link 16", "LINK16", "link16");
proto_register_field_array(proto_link16, hf, array_length (hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector("link16", dissect_link16, proto_link16);
}
void proto_reg_handoff_link16(void)
{
}
