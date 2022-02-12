static void
dissect_nsh_md_type_1(tvbuff_t *tvb, proto_tree *nsh_tree, int offset)
{
proto_tree_add_item(nsh_tree, hf_nsh_context_header, tvb, offset, 4, ENC_NA);
proto_tree_add_item(nsh_tree, hf_nsh_context_header, tvb, offset + 4, 4, ENC_NA);
proto_tree_add_item(nsh_tree, hf_nsh_context_header, tvb, offset + 8, 4, ENC_NA);
proto_tree_add_item(nsh_tree, hf_nsh_context_header, tvb, offset + 12, 4, ENC_NA);
}
static void
dissect_nsh_md_type_2(tvbuff_t *tvb, proto_tree *nsh_tree, int offset, int nsh_bytes_len)
{
int type2_metadata_len = 0;
while (offset < nsh_bytes_len) {
proto_tree_add_item(nsh_tree, hf_nsh_metadata_class, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(nsh_tree, hf_nsh_metadata_type, tvb, offset + 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(nsh_tree, hf_nsh_metadata_reservedbits, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(nsh_tree, hf_nsh_metadata_length, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
type2_metadata_len = 4 * tvb_get_bits8(tvb, ((offset + 3) * 8) + 3, 5);
if (type2_metadata_len >= 4)
proto_tree_add_item(nsh_tree, hf_nsh_metadata, tvb, offset + 4, type2_metadata_len, ENC_NA);
offset = offset + 4 + type2_metadata_len;
}
}
static int
dissect_nsh(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
int offset = 0;
int md_type = -1;
guint32 nsh_bytes_len;
int nsh_next_proto = -1;
proto_item *length_pi;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NSH");
col_set_str(pinfo->cinfo, COL_INFO, "Network Service Header");
proto_item *ti;
proto_tree *nsh_tree;
ti = proto_tree_add_item(tree, proto_nsh, tvb, offset, 2, ENC_NA);
nsh_tree = proto_item_add_subtree(ti, ett_nsh);
proto_tree_add_item(nsh_tree, hf_nsh_version, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(nsh_tree, hf_nsh_oam, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(nsh_tree, hf_nsh_critical_metadata, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(nsh_tree, hf_nsh_reservedbits, tvb, offset, 2, ENC_BIG_ENDIAN);
length_pi = proto_tree_add_item_ret_uint(nsh_tree, hf_nsh_length, tvb, offset, 2, ENC_BIG_ENDIAN, &nsh_bytes_len);
nsh_bytes_len *= 4;
proto_item_set_len(ti, nsh_bytes_len);
md_type = tvb_get_guint8(tvb, offset + 2);
proto_tree_add_item(nsh_tree, hf_nsh_md_type, tvb, offset + 2, 1, ENC_BIG_ENDIAN);
nsh_next_proto = tvb_get_guint8(tvb, offset + 3);
proto_tree_add_item(nsh_tree, hf_nsh_next_proto, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
offset = offset + 4;
proto_tree_add_item(nsh_tree, hf_nsh_service_pathID, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(nsh_tree, hf_nsh_service_index, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
offset = offset + 4;
switch (md_type) {
case MD_TYPE_1:
if (nsh_bytes_len != 4 * 6) {
expert_add_info_format(pinfo, length_pi, &ei_nsh_length_invalid,
"Length MUST be of value 0x6 for MD Type equal to 0x1");
nsh_bytes_len = 4 * 6;
}
dissect_nsh_md_type_1(tvb, nsh_tree, offset);
break;
case MD_TYPE_2:
if (nsh_bytes_len < 4 * 2) {
expert_add_info_format(pinfo, length_pi, &ei_nsh_length_invalid,
"Length MUST be of value 0x2 or greater for MD Type equal to 0x2");
nsh_bytes_len = 4 * 2;
}
if (nsh_bytes_len > 8)
dissect_nsh_md_type_2(tvb, nsh_tree, offset, nsh_bytes_len);
break;
default:
if (nsh_bytes_len < 4) {
expert_add_info_format(pinfo, length_pi, &ei_nsh_length_invalid,
"Length must be at least 0x1 for NSH Base Header");
nsh_bytes_len = 4;
}
break;
}
if (tvb_captured_length_remaining(tvb, nsh_bytes_len) > 0) {
next_tvb = tvb_new_subset_remaining(tvb, nsh_bytes_len);
if (!dissector_try_uint(subdissector_table, nsh_next_proto, next_tvb, pinfo, tree)) {
call_data_dissector(next_tvb, pinfo, tree);
}
}
return tvb_captured_length(tvb);
}
void
proto_register_nsh(void)
{
expert_module_t *expert_nsh;
static hf_register_info nsh_info[] = {
{ &hf_nsh_version,
{ "Version", "nsh.version",
FT_UINT16, BASE_DEC_HEX, NULL, 0xC000,
NULL, HFILL }
},
{ &hf_nsh_oam,
{ "O Bit", "nsh.Obit",
FT_UINT16, BASE_DEC, NULL, 0x2000,
"OAM Bit", HFILL }
},
{ &hf_nsh_critical_metadata,
{ "C Bit", "nsh.CBit",
FT_UINT16, BASE_DEC, NULL, 0x1000,
"Critical Metadata Bit", HFILL }
},
{ &hf_nsh_reservedbits,
{ "Reserved Bits", "nsh.reservedbits",
FT_UINT16, BASE_HEX, NULL, 0x0FC0,
"Reserved bits within NSH Base Header", HFILL }
},
{ &hf_nsh_length,
{ "Length", "nsh.length",
FT_UINT16, BASE_DEC_HEX, NULL, 0x003F,
"Total length, in 4-byte words, of NSH including Base, Service Path headers and optional variable TLVs", HFILL }
},
{ &hf_nsh_md_type,
{ "MD Type", "nsh.mdtype",
FT_UINT8, BASE_DEC_HEX, NULL, 0x00,
"Metadata Type defines the format of the metadata being carried", HFILL }
},
{ &hf_nsh_next_proto,
{ "Next Protocol", "nsh.nextproto",
FT_UINT8, BASE_DEC_HEX, VALS(nsh_next_protocols), 0x00,
"Protocol type of the original packet", HFILL }
},
{ &hf_nsh_service_pathID,
{ "SPI", "nsh.spi",
FT_UINT24, BASE_DEC_HEX, NULL, 0x00,
"Service Path Identifier", HFILL }
},
{ &hf_nsh_service_index,
{ "SI", "nsh.si",
FT_UINT8, BASE_DEC_HEX, NULL, 0x00,
"Service Index", HFILL }
},
{ &hf_nsh_context_header,
{ "Context Header", "nsh.contextheader",
FT_BYTES, BASE_NONE, NULL, 0x00,
"Manadatory Context Header", HFILL }
},
{ &hf_nsh_metadata_class,
{ "TLV Class", "nsh.metadataclass",
FT_UINT16, BASE_DEC_HEX, NULL, 0x00,
"TLV class describes the scope of the metadata type field", HFILL }
},
{ &hf_nsh_metadata_type,
{ "Type", "nsh.metadatatype",
FT_UINT8, BASE_DEC_HEX, NULL, 0x00,
"Type of metadata", HFILL }
},
{ &hf_nsh_metadata_reservedbits,
{ "Reserved Bits", "nsh.metadatareservedbits",
FT_UINT8, BASE_HEX, NULL, 0xE0,
"Reserved Bits within Variable Length Metadata header", HFILL }
},
{ &hf_nsh_metadata_length,
{ "Length", "nsh.metadatalen",
FT_UINT8, BASE_HEX, NULL, 0x1F,
"Length of the variable metadata in 4-byte words", HFILL }
},
{ &hf_nsh_metadata,
{ "Variable Metadata", "nsh.metadata",
FT_BYTES, BASE_NONE, NULL, 0x00,
"Variable length metadata", HFILL }
},
};
static gint *ett[] = {
&ett_nsh,
};
static ei_register_info ei[] = {
{ &ei_nsh_length_invalid, { "nsh.length.invalid", PI_PROTOCOL, PI_WARN, "Invalid total length", EXPFILL }},
};
proto_nsh = proto_register_protocol("Network Service Header", "NSH", "nsh");
proto_register_field_array(proto_nsh, nsh_info, array_length(nsh_info));
proto_register_subtree_array(ett, array_length(ett));
expert_nsh = expert_register_protocol(proto_nsh);
expert_register_field_array(expert_nsh, ei, array_length(ei));
subdissector_table = register_dissector_table("nsh.next_proto", "NSH Next Protocol", proto_nsh, FT_UINT32, BASE_DEC);
}
void
proto_reg_handoff_nsh(void)
{
static dissector_handle_t nsh_handle;
nsh_handle = create_dissector_handle(dissect_nsh, proto_nsh);
dissector_add_uint("ethertype", ETHERTYPE_NSH, nsh_handle);
dissector_add_uint("gre.proto", ETHERTYPE_NSH, nsh_handle);
dissector_add_uint("vxlan.next_proto", VXLAN_NSH, nsh_handle);
dissector_add_uint("nsh.next_proto", NSH_NSH, nsh_handle);
}
