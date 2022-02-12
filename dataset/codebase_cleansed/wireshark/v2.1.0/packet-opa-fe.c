static int dissect_opa_fe(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint offset = 0;
proto_item *FE_item;
proto_tree *FE_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Omni-Path");
col_clear(pinfo->cinfo, COL_INFO);
tree = proto_tree_get_root(tree);
FE_item = proto_tree_add_item(tree, proto_opa_fe, tvb, offset, 24, ENC_NA);
FE_tree = proto_item_add_subtree(FE_item, ett_fe);
proto_tree_add_item(FE_tree, hf_opa_fe_magicnumber, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(FE_tree, hf_opa_fe_length_oob, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(FE_tree, hf_opa_fe_headerversion, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(FE_tree, hf_opa_fe_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(FE_tree, hf_opa_fe_Reserved64, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
call_dissector(opa_mad_handle, tvb_new_subset_remaining(tvb, offset), pinfo, FE_tree);
return tvb_captured_length(tvb);
}
static void range_delete_fe_ssl_callback(guint32 port)
{
ssl_dissector_delete(port, opa_fe_handle);
}
static void range_add_fe_ssl_callback(guint32 port)
{
ssl_dissector_add(port, opa_fe_handle);
}
void proto_register_opa_fe(void)
{
module_t *opa_fe_module;
static hf_register_info hf[] = {
{ &hf_opa_fe_magicnumber, {
"Magic Number", "opa.fe.magicnumber",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_opa_fe_length_oob, {
"Length OOB", "opa.fe.lengthoob",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_opa_fe_headerversion, {
"Header Version", "opa.fe.headerversion",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_opa_fe_length, {
"Length", "opa.fe.length",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_opa_fe_Reserved64, {
"Reserved (64 bits)", "opa.fe.reserved64",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL }
}
};
static gint *ett[] = {
&ett_fe
};
proto_opa_fe = proto_register_protocol(
"Intel Omni-Path FE Header - Omni-Path Fabric Excutive Header",
"OPA FE", "opa.fe");
opa_fe_handle = register_dissector("opa.fe", dissect_opa_fe, proto_opa_fe);
proto_register_field_array(proto_opa_fe, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
opa_fe_module = prefs_register_protocol(proto_opa_fe, proto_reg_handoff_opa_fe);
range_convert_str(&global_fe_ssl_range, OPA_FE_SSL_RANGE, 65535);
fe_ssl_range = range_empty();
prefs_register_range_preference(opa_fe_module, "ssl.port", "SSL/TLS Ports",
"SSL/TLS Ports range",
&global_fe_ssl_range, 65535);
range_convert_str(&global_fe_tcp_range, OPA_FE_TCP_RANGE, 65535);
fe_tcp_range = range_empty();
prefs_register_range_preference(opa_fe_module, "tcp.port", "TCP Ports",
"TCP Ports range",
&global_fe_tcp_range, 65535);
}
void proto_reg_handoff_opa_fe(void)
{
opa_mad_handle = find_dissector("opa.mad");
range_foreach(fe_ssl_range, range_delete_fe_ssl_callback);
g_free(fe_ssl_range);
fe_ssl_range = range_copy(global_fe_ssl_range);
range_foreach(fe_ssl_range, range_add_fe_ssl_callback);
dissector_delete_uint_range("tcp.port", fe_tcp_range, opa_fe_handle);
g_free(fe_tcp_range);
fe_tcp_range = range_copy(global_fe_tcp_range);
dissector_add_uint_range("tcp.port", fe_tcp_range, opa_fe_handle);
}
