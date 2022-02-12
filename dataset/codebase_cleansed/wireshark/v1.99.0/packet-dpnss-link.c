static void
dissect_dpnss_link(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *item;
proto_tree *dpnss_link_tree;
guint8 octet;
tvbuff_t *protocol_data_tvb;
guint16 protocol_data_length;
gboolean uton;
uton = pinfo->pseudo_header->l1event.uton;
col_set_str(pinfo->cinfo, COL_DEF_SRC, uton?"TE":"NT");
col_set_str(pinfo->cinfo, COL_DEF_DST, uton?"NT":"TE");
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DPNSS");
item = proto_tree_add_item(tree, proto_dpnss_link, tvb, 0, -1, ENC_NA);
dpnss_link_tree = proto_item_add_subtree(item, ett_dpnss_link);
proto_tree_add_item(dpnss_link_tree, hf_dpnss_link_address_framegroup,
tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dpnss_link_tree, hf_dpnss_link_address_crbit,
tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dpnss_link_tree, hf_dpnss_link_address_extension,
tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dpnss_link_tree, hf_dpnss_link_address2_reserved,
tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dpnss_link_tree, hf_dpnss_link_address2_dlcId,
tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dpnss_link_tree, hf_dpnss_link_address2_dlcIdNr,
tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dpnss_link_tree, hf_dpnss_link_address2_extension,
tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dpnss_link_tree, hf_dpnss_link_control_frameType,
tvb, 2, 1, ENC_BIG_ENDIAN);
octet = tvb_get_guint8(tvb, 2);
switch (octet){
case FRAME_TYPE_UI_EVEN:
case FRAME_TYPE_UI_ODD:
protocol_data_length=tvb_length(tvb)-LINK_HEADER_SIZE;
protocol_data_tvb=tvb_new_subset_length(tvb, LINK_HEADER_SIZE,
protocol_data_length);
if (dpnss_handle && protocol_data_length>0) {
call_dissector(dpnss_handle, protocol_data_tvb, pinfo, tree);
}
break;
default:
break;
}
}
void
proto_register_dpnss_link(void)
{
static hf_register_info hf[] = {
{ &hf_dpnss_link_address_framegroup,
{ "Frame Group", "dpnss_link.framegroup",
FT_UINT8, BASE_DEC, VALS(dpnss_link_framegroup_vals), 0xfc,
NULL, HFILL }
},
{ &hf_dpnss_link_address_crbit,
{ "C/R Bit", "dpnss_link.crbit",
FT_UINT8, BASE_DEC, VALS(dpnss_link_crbit_vals), 0x02,
NULL, HFILL }
},
{ &hf_dpnss_link_address_extension,
{ "Extension", "dpnss_link.extension",
FT_UINT8, BASE_DEC, VALS(dpnss_link_extend_vals), 0x01,
NULL, HFILL }
},
{ &hf_dpnss_link_address2_reserved,
{ "Reserved", "dpnss_link.reserved",
FT_UINT8, BASE_DEC, VALS(dpnss_link_reserved_vals), 0x80,
NULL, HFILL }
},
{ &hf_dpnss_link_address2_dlcId,
{ "DLC ID", "dpnss_link.dlcId",
FT_UINT8, BASE_DEC, VALS(dpnss_link_dlcId_vals), 0x40,
NULL, HFILL }
},
{ &hf_dpnss_link_address2_dlcIdNr,
{ "DLC ID Number", "dpnss_link.dlcIdNr",
FT_UINT8, BASE_DEC, NULL, 0x3e,
NULL, HFILL }
},
{ &hf_dpnss_link_address2_extension,
{ "Extension", "dpnss_link.extension2",
FT_UINT8, BASE_DEC, VALS(dpnss_link_extend_vals), 0x01,
NULL, HFILL }
},
{ &hf_dpnss_link_control_frameType,
{ "Frame Type", "dpnss_link.frameType",
FT_UINT8, BASE_DEC, VALS(dpnss_link_frameType_vals), 0xff,
NULL, HFILL }
}
};
static gint *ett[] = { &ett_dpnss_link };
proto_dpnss_link = proto_register_protocol("Digital Private Signalling System No 1 Link Layer",
"DPNSS Link", "dpnss_link");
register_dissector("dpnss_link", dissect_dpnss_link, proto_dpnss_link);
proto_register_field_array(proto_dpnss_link, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_dpnss_link(void)
{
dissector_handle_t dpnss_link_handle;
dpnss_link_handle = find_dissector("dpnss_link");
dissector_add_uint("wtap_encap", WTAP_ENCAP_DPNSS, dpnss_link_handle);
dpnss_handle = find_dissector("dpnss");
}
