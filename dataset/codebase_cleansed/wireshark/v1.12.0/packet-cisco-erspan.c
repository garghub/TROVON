static void
erspan_fmt_timestamp(gchar *result, guint32 timeval)
{
g_snprintf(result, ITEM_LABEL_LENGTH, "%.4f", (((gfloat)timeval)/10000));
}
static void
dissect_erspan(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_item *ti_ver;
proto_tree *erspan_tree = NULL;
tvbuff_t *eth_tvb;
guint32 offset = 0;
guint16 version;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTO_SHORT_NAME);
col_set_str(pinfo->cinfo, COL_INFO, PROTO_SHORT_NAME ":");
if (tree) {
ti = proto_tree_add_item(tree, proto_erspan, tvb, offset, -1,
ENC_NA);
erspan_tree = proto_item_add_subtree(ti, ett_erspan);
}
if(pref_fake_erspan) {
eth_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(ethnofcs_handle, eth_tvb, pinfo, tree);
return;
}
version = tvb_get_ntohs(tvb, offset) >> 12;
if (tree) {
ti_ver = proto_tree_add_item(erspan_tree, hf_erspan_version, tvb, offset, 2,
ENC_BIG_ENDIAN);
if ((version != 1) && (version != 2 )) {
expert_add_info(pinfo, ti_ver, &ei_erspan_version_unknown);
return;
}
proto_tree_add_item(erspan_tree, hf_erspan_vlan, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(erspan_tree, hf_erspan_priority, tvb, offset, 2,
ENC_BIG_ENDIAN);
proto_tree_add_item(erspan_tree, hf_erspan_unknown2, tvb, offset, 2,
ENC_BIG_ENDIAN);
if (version == 1)
proto_tree_add_item(erspan_tree, hf_erspan_direction, tvb,
offset, 2, ENC_BIG_ENDIAN);
else
proto_tree_add_item(erspan_tree, hf_erspan_unknown3, tvb,
offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(erspan_tree, hf_erspan_truncated, tvb, offset, 2,
ENC_BIG_ENDIAN);
proto_tree_add_item(erspan_tree, hf_erspan_spanid, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
if (version == 2) {
proto_tree_add_item(erspan_tree, hf_erspan_timestamp, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(erspan_tree, hf_erspan_unknown4, tvb,
offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(erspan_tree, hf_erspan_direction2, tvb,
offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(erspan_tree, hf_erspan_unknown5, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(erspan_tree, hf_erspan_unknown6, tvb,
offset, 4, ENC_NA);
offset += 4;
}
proto_tree_add_item(erspan_tree, hf_erspan_unknown7, tvb, offset, 4,
ENC_NA);
offset += 4;
}
else {
offset += 8;
if (version == 2)
offset += 12;
}
eth_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(ethnofcs_handle, eth_tvb, pinfo, tree);
}
void
proto_register_erspan(void)
{
module_t *erspan_module;
expert_module_t* expert_erspan;
static hf_register_info hf[] = {
{ &hf_erspan_version,
{ "Version", "erspan.version", FT_UINT16, BASE_DEC, VALS(erspan_version_vals),
0xf000, NULL, HFILL }},
{ &hf_erspan_vlan,
{ "Vlan", "erspan.vlan", FT_UINT16, BASE_DEC, NULL,
0x0fff, NULL, HFILL }},
{ &hf_erspan_priority,
{ "Priority", "erspan.priority", FT_UINT16, BASE_DEC, NULL,
0xe000, NULL, HFILL }},
{ &hf_erspan_unknown2,
{ "Unknown2", "erspan.unknown2", FT_UINT16, BASE_DEC, NULL,
0x1000, NULL, HFILL }},
{ &hf_erspan_direction,
{ "Direction", "erspan.direction", FT_UINT16, BASE_DEC, VALS(erspan_direction_vals),
0x0800, NULL, HFILL }},
{ &hf_erspan_unknown3,
{ "Unknown3", "erspan.unknown3", FT_UINT16, BASE_DEC, NULL,
0x0800, NULL, HFILL }},
{ &hf_erspan_truncated,
{ "Truncated", "erspan.truncated", FT_UINT16, BASE_DEC, VALS(erspan_truncated_vals),
0x0400, "ERSPAN packet exceeded the MTU size", HFILL }},
{ &hf_erspan_spanid,
{ "SpanID", "erspan.spanid", FT_UINT16, BASE_DEC, NULL,
0x03ff, NULL, HFILL }},
{ &hf_erspan_timestamp,
{ "Timestamp", "erspan.timestamp", FT_UINT32, BASE_CUSTOM, erspan_fmt_timestamp,
0, NULL, HFILL }},
{ &hf_erspan_unknown4,
{ "Unknown4", "erspan.unknown4", FT_BYTES, BASE_NONE, NULL,
0, NULL, HFILL }},
{ &hf_erspan_direction2,
{ "Direction2", "erspan.direction2", FT_UINT16, BASE_DEC, VALS(erspan_direction_vals),
0x0008, NULL, HFILL }},
{ &hf_erspan_unknown5,
{ "Unknown5", "erspan.unknown5", FT_UINT16, BASE_HEX, NULL,
0xfff7, NULL, HFILL }},
{ &hf_erspan_unknown6,
{ "Unknown6", "erspan.unknown6", FT_BYTES, BASE_NONE, NULL,
0, NULL, HFILL }},
{ &hf_erspan_unknown7,
{ "Unknown7", "erspan.unknown7", FT_BYTES, BASE_NONE, NULL,
0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_erspan,
};
static ei_register_info ei[] = {
{ &ei_erspan_version_unknown, { "erspan.version.unknown", PI_UNDECODED, PI_WARN, "Unknown version, please report or test to use fake ERSPAN preference", EXPFILL }},
};
proto_erspan = proto_register_protocol(PROTO_LONG_NAME, PROTO_SHORT_NAME, "erspan");
proto_register_field_array(proto_erspan, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_erspan = expert_register_protocol(proto_erspan);
expert_register_field_array(expert_erspan, ei, array_length(ei));
erspan_module = prefs_register_protocol(proto_erspan, NULL);
prefs_register_bool_preference(erspan_module, "fake_erspan",
"FORCE to decode fake ERSPAN frame",
"When set, dissector will FORCE to decode directly Ethernet Frame"
"Some vendor use fake ERSPAN frame (with not ERSPAN Header)",
&pref_fake_erspan);
}
void
proto_reg_handoff_erspan(void)
{
dissector_handle_t erspan_handle;
ethnofcs_handle = find_dissector("eth_withoutfcs");
erspan_handle = create_dissector_handle(dissect_erspan, proto_erspan);
dissector_add_uint("gre.proto", GRE_ERSPAN_88BE, erspan_handle);
dissector_add_uint("gre.proto", GRE_ERSPAN_22EB, erspan_handle);
}
