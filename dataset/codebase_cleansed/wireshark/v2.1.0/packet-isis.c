static int
dissect_isis(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti, *version_item;
proto_tree *isis_tree = NULL;
int offset = 0;
guint8 isis_version;
guint8 isis_type;
tvbuff_t *next_tvb;
isis_data_t subdissector_data;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ISIS");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_isis, tvb, 0, -1, ENC_NA);
isis_tree = proto_item_add_subtree(ti, ett_isis);
proto_tree_add_item(isis_tree, hf_isis_irpd, tvb, offset, 1, ENC_BIG_ENDIAN );
offset += 1;
subdissector_data.header_length = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(isis_tree, hf_isis_header_length, tvb,
offset, 1, subdissector_data.header_length );
offset += 1;
isis_version = tvb_get_guint8(tvb, offset);
version_item = proto_tree_add_uint(isis_tree, hf_isis_version, tvb,
offset, 1, isis_version );
if (isis_version != ISIS_REQUIRED_VERSION){
col_add_fstr(pinfo->cinfo, COL_INFO,
"Unknown ISIS version (%u vs %u)",
isis_version, ISIS_REQUIRED_VERSION );
expert_add_info(pinfo, version_item, &ei_isis_version);
}
offset += 1;
subdissector_data.system_id_len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(isis_tree, hf_isis_system_id_length, tvb,
offset, 1, subdissector_data.system_id_len );
offset += 1;
isis_type = tvb_get_guint8(tvb, offset) & ISIS_TYPE_MASK;
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str ( isis_type, isis_vals, "Unknown (0x%x)" ) );
proto_tree_add_item(isis_tree, hf_isis_type, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item(isis_tree, hf_isis_type_reserved, tvb, offset, 1, ENC_BIG_ENDIAN );
offset += 1;
proto_tree_add_item(isis_tree, hf_isis_version2, tvb, offset, 1, ENC_BIG_ENDIAN );
offset += 1;
proto_tree_add_item(isis_tree, hf_isis_reserved, tvb, offset, 1, ENC_BIG_ENDIAN );
offset += 1;
proto_tree_add_item(isis_tree, hf_isis_max_area_adr, tvb, offset, 1, ENC_BIG_ENDIAN );
offset += 1;
if (subdissector_data.system_id_len == 0)
subdissector_data.system_id_len = 6;
else if (subdissector_data.system_id_len == 255) {
subdissector_data.system_id_len = 0;
}
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (!dissector_try_uint_new(isis_dissector_table, isis_type, next_tvb,
pinfo, tree, TRUE, &subdissector_data))
{
proto_tree_add_expert(tree, pinfo, &ei_isis_type, tvb, offset, -1);
}
return tvb_captured_length(tvb);
}
void
proto_register_isis(void)
{
static hf_register_info hf[] = {
{ &hf_isis_irpd,
{ "Intra Domain Routing Protocol Discriminator", "isis.irpd",
FT_UINT8, BASE_HEX, VALS(nlpid_vals), 0x0, NULL, HFILL }},
{ &hf_isis_header_length,
{ "PDU Header Length", "isis.len", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isis_version,
{ "Version", "isis.version", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isis_system_id_length,
{ "System ID Length", "isis.sysid_len",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isis_type,
{ "PDU Type", "isis.type", FT_UINT8, BASE_DEC,
VALS(isis_vals), ISIS_TYPE_MASK, NULL, HFILL }},
{ &hf_isis_type_reserved,
{ "Reserved", "isis.reserved", FT_UINT8, BASE_HEX,
NULL, ISIS_TYPE_RESERVED_MASK, NULL, HFILL }},
{ &hf_isis_version2,
{ "Version2 (==1)", "isis.version2", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_isis_reserved,
{ "Reserved (==0)", "isis.reserved", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_isis_max_area_adr,
{ "Max.AREAs: (0==3)", "isis.max_area_adr", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_isis,
};
static ei_register_info ei[] = {
{ &ei_isis_version, { "isis.version.unknown", PI_PROTOCOL, PI_WARN, "Unknown ISIS version", EXPFILL }},
{ &ei_isis_type, { "isis.type.unknown", PI_PROTOCOL, PI_WARN, "Unknown ISIS packet type", EXPFILL }},
};
expert_module_t* expert_isis;
proto_isis = proto_register_protocol(PROTO_STRING_ISIS, "ISIS", "isis");
proto_register_field_array(proto_isis, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_isis = expert_register_protocol(proto_isis);
expert_register_field_array(expert_isis, ei, array_length(ei));
isis_handle = register_dissector("isis", dissect_isis, proto_isis);
isis_dissector_table = register_dissector_table("isis.type",
"ISIS Type", proto_isis, FT_UINT8, BASE_DEC, DISSECTOR_TABLE_ALLOW_DUPLICATE);
}
void
proto_reg_handoff_isis(void)
{
dissector_add_uint("osinl.incl", NLPID_ISO10589_ISIS, isis_handle);
dissector_add_uint("ethertype", ETHERTYPE_L2ISIS, isis_handle);
}
