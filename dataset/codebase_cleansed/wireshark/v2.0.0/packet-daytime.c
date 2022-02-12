static void
dissect_daytime(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *daytime_tree;
proto_item *ti;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DAYTIME");
col_add_fstr(pinfo->cinfo, COL_INFO, "DAYTIME %s",
pinfo->srcport == pinfo->match_uint ? "Response":"Request");
if (tree) {
ti = proto_tree_add_item(tree, hfi_daytime, tvb, 0, -1, ENC_NA);
daytime_tree = proto_item_add_subtree(ti, ett_daytime);
proto_tree_add_boolean(daytime_tree, &hfi_response_request, tvb, 0, 0, pinfo->srcport==DAYTIME_PORT);
if (pinfo->srcport == DAYTIME_PORT) {
proto_tree_add_item(daytime_tree, &hfi_daytime_string, tvb, 0, -1, ENC_ASCII|ENC_NA);
}
}
}
void
proto_register_daytime(void)
{
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] = {
&hfi_daytime_string,
&hfi_response_request,
};
#endif
static gint *ett[] = {
&ett_daytime,
};
int proto_daytime;
proto_daytime = proto_register_protocol("Daytime Protocol", "DAYTIME", "daytime");
hfi_daytime = proto_registrar_get_nth(proto_daytime);
proto_register_fields(proto_daytime, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
daytime_handle = create_dissector_handle(dissect_daytime, proto_daytime);
}
void
proto_reg_handoff_daytime(void)
{
dissector_add_uint("udp.port", DAYTIME_PORT, daytime_handle);
dissector_add_uint("tcp.port", DAYTIME_PORT, daytime_handle);
}
