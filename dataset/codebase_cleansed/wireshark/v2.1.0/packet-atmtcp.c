static int
dissect_atmtcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *atmtcp_tree;
guint offset = 0;
gint32 length;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ATMTCP");
col_add_str(pinfo->cinfo, COL_INFO, "ATMTCP");
if (tree) {
ti = proto_tree_add_item(tree, proto_atmtcp, tvb, 0, -1, ENC_NA);
atmtcp_tree = proto_item_add_subtree(ti, ett_atmtcp);
proto_tree_add_item(atmtcp_tree, hf_atmtcp_vpi, tvb, offset, 2, ENC_BIG_ENDIAN);
}
offset += 2;
if (tree) {
proto_tree_add_item(atmtcp_tree, hf_atmtcp_vci, tvb, offset, 2, ENC_BIG_ENDIAN);
}
offset += 2;
if (tree) {
proto_tree_add_item(atmtcp_tree, hf_atmtcp_length, tvb, offset, 4, ENC_BIG_ENDIAN);
}
length = tvb_get_ntohl(tvb, offset);
if(length == ATMTCP_HDR_MAGIC)
{
col_append_str(pinfo->cinfo, COL_INFO, " Command");
}
else
{
col_append_str(pinfo->cinfo, COL_INFO, " Data");
}
offset += 4;
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_data_dissector(next_tvb, pinfo, tree);
return tvb_reported_length(tvb);
}
void
proto_register_atmtcp(void)
{
module_t *atmtcp_module;
static hf_register_info hf[] = {
{ &hf_atmtcp_vpi,
{ "VPI", "atmtcp.vpi", FT_UINT16, BASE_DEC, NULL, 0x0,
"Virtual Path Identifier", HFILL }
},
{ &hf_atmtcp_vci,
{ "VCI", "atmtcp.vci", FT_UINT16, BASE_DEC, NULL, 0x0,
"Virtual Channel Identifier", HFILL }
},
{ &hf_atmtcp_length,
{ "Length", "atmtcp.length", FT_UINT32, BASE_DEC, NULL, 0x0,
"length of data", HFILL }
}
};
static gint *ett[] = {
&ett_atmtcp
};
proto_atmtcp = proto_register_protocol("ATM over TCP", "ATMTCP", "atmtcp");
proto_register_field_array(proto_atmtcp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
atmtcp_module = prefs_register_protocol(proto_atmtcp, proto_reg_handoff_atmtcp);
prefs_register_uint_preference(atmtcp_module, "tcp.port", "ATMTCP TCP Port",
"ATMTCP TCP port if other than the default",
10, &global_atmtcp_tcp_port);
}
void
proto_reg_handoff_atmtcp(void)
{
static gboolean initialized = FALSE;
static dissector_handle_t atmtcp_handle;
static int current_port;
if (!initialized) {
atmtcp_handle = create_dissector_handle(dissect_atmtcp, proto_atmtcp);
initialized = TRUE;
} else {
dissector_delete_uint("tcp.port", current_port, atmtcp_handle);
}
current_port = global_atmtcp_tcp_port;
dissector_add_uint("tcp.port", current_port, atmtcp_handle);
}
