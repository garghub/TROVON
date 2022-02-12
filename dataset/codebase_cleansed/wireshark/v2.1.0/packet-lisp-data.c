static int
dissect_lisp_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint offset = 0;
guint8 flags;
guint8 ip_ver;
tvbuff_t *next_tvb;
proto_item *ti;
proto_item *tif;
proto_tree *lisp_data_tree;
proto_tree *lisp_data_flags_tree;
if (pinfo->destport == LISP_CONTROL_PORT)
return call_dissector(lisp_handle, tvb, pinfo, tree);
if (tvb_reported_length(tvb) < LISP_DATA_HEADER_LEN)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LISP");
col_set_str(pinfo->cinfo, COL_INFO, "LISP Encapsulation Header");
ti = proto_tree_add_item(tree, proto_lisp_data, tvb, 0,
LISP_DATA_HEADER_LEN, ENC_NA);
lisp_data_tree = proto_item_add_subtree(ti, ett_lisp_data);
tif = proto_tree_add_item(lisp_data_tree,
hf_lisp_data_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
lisp_data_flags_tree = proto_item_add_subtree(tif, ett_lisp_data_flags);
proto_tree_add_item(lisp_data_flags_tree,
hf_lisp_data_flags_nonce, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lisp_data_flags_tree,
hf_lisp_data_flags_lsb, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lisp_data_flags_tree,
hf_lisp_data_flags_enr, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lisp_data_flags_tree,
hf_lisp_data_flags_mv, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lisp_data_flags_tree,
hf_lisp_data_flags_iid, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lisp_data_flags_tree,
hf_lisp_data_flags_res, tvb, offset, 1, ENC_BIG_ENDIAN);
flags = tvb_get_guint8(tvb, offset);
offset += 1;
if (flags&LISP_DATA_FLAG_E && !(flags&LISP_DATA_FLAG_N)) {
expert_add_info(pinfo, tif, &ei_lisp_data_flags_en_invalid);
}
if (flags&LISP_DATA_FLAG_N) {
if (flags&LISP_DATA_FLAG_V) {
expert_add_info(pinfo, tif, &ei_lisp_data_flags_nv_invalid);
}
proto_tree_add_item(lisp_data_tree,
hf_lisp_data_nonce, tvb, offset, 3, ENC_BIG_ENDIAN);
} else {
if (flags&LISP_DATA_FLAG_V) {
proto_item *tiv;
proto_tree *lisp_data_mapver_tree;
tiv = proto_tree_add_item(lisp_data_tree,
hf_lisp_data_mapver, tvb, offset, 3, ENC_BIG_ENDIAN);
lisp_data_mapver_tree = proto_item_add_subtree(tiv, ett_lisp_data_mapver);
proto_tree_add_item(lisp_data_mapver_tree,
hf_lisp_data_srcmapver, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(lisp_data_mapver_tree,
hf_lisp_data_dstmapver, tvb, offset, 3, ENC_BIG_ENDIAN);
}
}
offset += 3;
if (flags&LISP_DATA_FLAG_I) {
proto_tree_add_item(lisp_data_tree,
hf_lisp_data_iid, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
if (flags&LISP_DATA_FLAG_L) {
proto_tree_add_item(lisp_data_tree,
hf_lisp_data_lsb8, tvb, offset, 1, ENC_BIG_ENDIAN);
}
} else {
if (flags&LISP_DATA_FLAG_L) {
proto_tree_add_item(lisp_data_tree,
hf_lisp_data_lsb, tvb, offset, 4, ENC_BIG_ENDIAN);
}
}
next_tvb = tvb_new_subset_remaining(tvb, LISP_DATA_HEADER_LEN);
ip_ver = tvb_get_bits8(next_tvb, 0, 4);
switch (ip_ver) {
case 4:
call_dissector(ipv4_handle, next_tvb, pinfo, tree);
return tvb_reported_length(tvb);
case 6:
call_dissector(ipv6_handle, next_tvb, pinfo, tree);
return tvb_reported_length(tvb);
}
return LISP_DATA_HEADER_LEN;
}
void
proto_register_lisp_data(void)
{
static hf_register_info hf[] = {
{ &hf_lisp_data_flags,
{ "Flags", "lisp-data.flags",
FT_UINT8, BASE_HEX, NULL, 0x0, "LISP Data Header Flags", HFILL }},
{ &hf_lisp_data_flags_nonce,
{ "N bit (Nonce present)", "lisp-data.flags.nonce",
FT_BOOLEAN, LISP_DATA_FLAGS_WIDTH, TFS(&tfs_set_notset),
LISP_DATA_FLAG_N, NULL, HFILL }},
{ &hf_lisp_data_flags_lsb,
{ "L bit (Locator-Status-Bits field enabled)", "lisp-data.flags.lsb",
FT_BOOLEAN, LISP_DATA_FLAGS_WIDTH, TFS(&tfs_set_notset),
LISP_DATA_FLAG_L, NULL, HFILL }},
{ &hf_lisp_data_flags_enr,
{ "E bit (Echo-Nonce-Request)", "lisp-data.flags.enr",
FT_BOOLEAN, LISP_DATA_FLAGS_WIDTH, TFS(&tfs_set_notset),
LISP_DATA_FLAG_E, NULL, HFILL }},
{ &hf_lisp_data_flags_mv,
{ "V bit (Map-Version present)", "lisp-data.flags.mv",
FT_BOOLEAN, LISP_DATA_FLAGS_WIDTH, TFS(&tfs_set_notset),
LISP_DATA_FLAG_V, NULL, HFILL }},
{ &hf_lisp_data_flags_iid,
{ "I bit (Instance ID present)", "lisp-data.flags.iid",
FT_BOOLEAN, LISP_DATA_FLAGS_WIDTH, TFS(&tfs_set_notset),
LISP_DATA_FLAG_I, NULL, HFILL }},
{ &hf_lisp_data_flags_res,
{ "Reserved", "lisp-data.flags.res",
FT_UINT8, BASE_HEX, NULL,
LISP_DATA_FLAG_RES, "Must be zero", HFILL }},
{ &hf_lisp_data_nonce,
{ "Nonce", "lisp-data.nonce",
FT_UINT24, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_lisp_data_mapver,
{ "Map-Version", "lisp-data.mapver",
FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_lisp_data_srcmapver,
{ "Source Map-Version", "lisp-data.srcmapver",
FT_UINT24, BASE_DEC, NULL, 0xFFF000, NULL, HFILL }},
{ &hf_lisp_data_dstmapver,
{ "Destination Map-Version", "lisp-data.dstmapver",
FT_UINT24, BASE_DEC, NULL, 0x000FFF, NULL, HFILL }},
{ &hf_lisp_data_iid,
{ "Instance ID", "lisp-data.iid",
FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lisp_data_lsb,
{ "Locator-Status-Bits", "lisp-data.lsb",
FT_UINT32, BASE_HEX, NULL, 0xFFFFFFFF, NULL, HFILL }},
{ &hf_lisp_data_lsb8,
{ "Locator-Status-Bits", "lisp-data.lsb8",
FT_UINT8, BASE_HEX, NULL, 0xFF, NULL, HFILL }}
};
static gint *ett[] = {
&ett_lisp_data,
&ett_lisp_data_flags,
&ett_lisp_data_mapver
};
static ei_register_info ei[] = {
{ &ei_lisp_data_flags_en_invalid, { "lisp-data.flags.en_invalid", PI_PROTOCOL, PI_WARN, "Invalid flag combination: if E is set, N MUST be set", EXPFILL }},
{ &ei_lisp_data_flags_nv_invalid, { "lisp-data.flags.nv_invalid", PI_PROTOCOL, PI_WARN, "Invalid flag combination: N and V can't be set both", EXPFILL }},
};
expert_module_t* expert_lisp_data;
proto_lisp_data = proto_register_protocol("Locator/ID Separation Protocol (Data)",
"LISP Data", "lisp-data");
proto_register_field_array(proto_lisp_data, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_lisp_data = expert_register_protocol(proto_lisp_data);
expert_register_field_array(expert_lisp_data, ei, array_length(ei));
}
void
proto_reg_handoff_lisp_data(void)
{
dissector_handle_t lisp_data_handle;
lisp_data_handle = create_dissector_handle(dissect_lisp_data,
proto_lisp_data);
dissector_add_uint("udp.port", LISP_DATA_PORT, lisp_data_handle);
ipv4_handle = find_dissector_add_dependency("ip", proto_lisp_data);
ipv6_handle = find_dissector_add_dependency("ipv6", proto_lisp_data);
lisp_handle = find_dissector_add_dependency("lisp", proto_lisp_data);
}
