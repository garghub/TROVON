static void
dissect_daytime(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *daytime_tree;
proto_item *ti;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DAYTIME");
col_add_fstr(pinfo->cinfo, COL_INFO, "DAYTIME %s",
pinfo->srcport == pinfo->match_uint ? "Response":"Request");
if (tree) {
ti = proto_tree_add_item(tree, proto_daytime, tvb, 0, -1, ENC_NA);
daytime_tree = proto_item_add_subtree(ti, ett_daytime);
proto_tree_add_text(daytime_tree, tvb, 0, 0,
pinfo->srcport==DAYTIME_PORT ? "Type: Response":"Type: Request");
if (pinfo->srcport == DAYTIME_PORT) {
proto_tree_add_item(daytime_tree, hf_daytime_string, tvb, 0, -1, ENC_ASCII|ENC_NA);
}
}
}
void
proto_register_daytime(void)
{
static hf_register_info hf[] = {
{ &hf_daytime_string,
{ "Daytime", "daytime.string",
FT_STRING, BASE_NONE, NULL, 0x0,
"String containing time and date", HFILL }}
};
static gint *ett[] = {
&ett_daytime,
};
proto_daytime = proto_register_protocol("Daytime Protocol", "DAYTIME", "daytime");
proto_register_field_array(proto_daytime, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_daytime(void)
{
dissector_handle_t daytime_handle;
daytime_handle = create_dissector_handle(dissect_daytime, proto_daytime);
dissector_add_uint("udp.port", DAYTIME_PORT, daytime_handle);
dissector_add_uint("tcp.port", DAYTIME_PORT, daytime_handle);
}
