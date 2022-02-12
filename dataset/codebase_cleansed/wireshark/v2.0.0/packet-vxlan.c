static void
dissect_vxlan(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *vxlan_tree;
proto_item *ti;
tvbuff_t *next_tvb;
int offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "VxLAN");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_vxlan, tvb, offset, -1, ENC_NA);
vxlan_tree = proto_item_add_subtree(ti, ett_vxlan);
proto_tree_add_bitmask(vxlan_tree, tvb, offset, hf_vxlan_flags,
ett_vxlan_flgs, flags_fields, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(vxlan_tree, hf_vxlan_gbp, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(vxlan_tree, hf_vxlan_vni, tvb, offset, 3, ENC_BIG_ENDIAN);
offset+=3;
proto_tree_add_item(vxlan_tree, hf_vxlan_reserved_8, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(eth_handle, next_tvb, pinfo, tree);
}
void
proto_register_vxlan(void)
{
static hf_register_info hf[] = {
{ &hf_vxlan_flags,
{ "Flags", "vxlan.flags",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL
},
},
{ &hf_vxlan_flags_reserved,
{ "Reserved(R)", "vxlan.flags_reserved",
FT_BOOLEAN, 16, NULL, 0x77b7,
NULL, HFILL,
},
},
{ &hf_vxlan_flag_g,
{ "GBP Extension", "vxlan.flag_g",
FT_BOOLEAN, 16, TFS(&tfs_defined_not_defined), 0x8000,
NULL, HFILL,
},
},
{ &hf_vxlan_flag_i,
{ "VXLAN Network ID (VNI)", "vxlan.flag_i",
FT_BOOLEAN, 16, NULL, 0x0800,
NULL, HFILL,
},
},
{ &hf_vxlan_flag_d,
{ "Don't Learn", "vxlan.flag_d",
FT_BOOLEAN, 16, NULL, 0x0040,
NULL, HFILL,
},
},
{ &hf_vxlan_flag_a,
{ "Policy Applied", "vxlan.flag_a",
FT_BOOLEAN, 16, NULL, 0x0008,
NULL, HFILL,
},
},
{ &hf_vxlan_gbp,
{ "Group Policy ID", "vxlan.gbp",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL
},
},
{ &hf_vxlan_vni,
{ "VXLAN Network Identifier (VNI)", "vxlan.vni",
FT_UINT24, BASE_DEC, NULL, 0x00,
NULL, HFILL
},
},
{ &hf_vxlan_reserved_8,
{ "Reserved", "vxlan.reserved8",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL
},
},
};
static gint *ett[] = {
&ett_vxlan,
&ett_vxlan_flgs,
};
proto_vxlan = proto_register_protocol("Virtual eXtensible Local Area Network",
"VXLAN", "vxlan");
proto_register_field_array(proto_vxlan, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_vxlan(void)
{
dissector_handle_t vxlan_handle;
eth_handle = find_dissector("eth");
vxlan_handle = create_dissector_handle(dissect_vxlan, proto_vxlan);
dissector_add_uint("udp.port", UDP_PORT_VXLAN, vxlan_handle);
dissector_add_for_decode_as("udp.port", vxlan_handle);
}
