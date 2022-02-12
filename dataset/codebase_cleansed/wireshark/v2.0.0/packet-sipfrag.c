static void dissect_sipfrag(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *sipfrag_tree;
proto_item *ti;
gint offset = 0;
gint next_offset;
int linelen;
char *string;
gint lines = 0;
col_append_str(pinfo->cinfo, COL_PROTOCOL, "/sipfrag");
col_append_str(pinfo->cinfo, COL_INFO, ", with Sipfrag");
ti = proto_tree_add_item(tree, proto_sipfrag, tvb, offset, -1, ENC_NA);
sipfrag_tree = proto_item_add_subtree(ti, ett_sipfrag);
while (tvb_offset_exists(tvb, offset))
{
linelen = tvb_find_line_end_unquoted(tvb, offset, -1, &next_offset);
string = (char*)tvb_get_string_enc(wmem_packet_scope(), tvb, offset, linelen, ENC_ASCII);
proto_tree_add_string_format(sipfrag_tree, hf_sipfrag_line,
tvb, offset,
linelen, string,
"%s", string);
lines++;
if (lines == 1) {
col_append_fstr(pinfo->cinfo, COL_INFO, "(%s", string);
}
offset = next_offset;
}
col_append_str(pinfo->cinfo, COL_INFO, (lines > 1) ? "...)" : ")");
}
void proto_register_sipfrag(void)
{
static hf_register_info hf[] =
{
{ &hf_sipfrag_line,
{ "Line",
"sipfrag.line",FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
};
static gint *ett[] =
{
&ett_sipfrag
};
proto_sipfrag = proto_register_protocol("Sipfrag", "SIPFRAG", "sipfrag");
proto_register_field_array(proto_sipfrag, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("sipfrag", dissect_sipfrag, proto_sipfrag);
}
void proto_reg_handoff_sipfrag(void)
{
dissector_handle_t sipfrag_handle = find_dissector("sipfrag");
dissector_add_string("media_type", "message/sipfrag", sipfrag_handle);
}
