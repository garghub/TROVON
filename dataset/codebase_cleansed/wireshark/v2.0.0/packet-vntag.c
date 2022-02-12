static void
dissect_vntag(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint16 encap_proto;
proto_tree *vntag_tree = NULL;
ethertype_data_t ethertype_data;
static const int * fields[] = {
&hf_vntag_dir,
&hf_vntag_ptr,
&hf_vntag_vif_list_id,
&hf_vntag_dst,
&hf_vntag_looped,
&hf_vntag_r,
&hf_vntag_version,
&hf_vntag_src,
NULL
};
col_set_str(pinfo->cinfo, COL_PROTOCOL, "VNTAG");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
proto_item *ti = proto_tree_add_item(tree, proto_vntag, tvb, 0, 4, ENC_NA);
vntag_tree = proto_item_add_subtree(ti, ett_vntag);
proto_tree_add_bitmask_list(vntag_tree, tvb, 0, 4, fields, ENC_BIG_ENDIAN);
}
encap_proto = tvb_get_ntohs(tvb, 4);
#if 0
if (encap_proto <= IEEE_802_3_MAX_LEN) {
gboolean is_802_2;
is_802_2 = TRUE;
if (tvb_captured_length_remaining(tvb, 4) >= 2) {
if (tvb_get_ntohs(tvb, 4) == 0xffff)
is_802_2 = FALSE;
}
dissect_802_3(encap_proto, is_802_2, tvb, 4, pinfo, tree, vntag_tree, hf_vntag_len, hf_vntag_trailer, 0);
} else {
#endif
ethertype_data.etype = encap_proto;
ethertype_data.offset_after_ethertype = 6;
ethertype_data.fh_tree = vntag_tree;
ethertype_data.etype_id = hf_vntag_etype;
ethertype_data.trailer_id = hf_vntag_trailer;
ethertype_data.fcs_len = 0;
call_dissector_with_data(ethertype_handle, tvb, pinfo, tree, &ethertype_data);
#if 0
}
#endif
}
void
proto_register_vntag(void)
{
static hf_register_info hf[] = {
{ &hf_vntag_etype,
{ "Type", "vntag.etype", FT_UINT16, BASE_HEX, VALS(etype_vals), 0x0, NULL, HFILL }
},
{ &hf_vntag_dir,
{ "Direction", "vntag.dir", FT_UINT32, BASE_DEC, NULL, 0x80000000, NULL, HFILL }
},
{ &hf_vntag_ptr,
{ "Pointer", "vntag.ptr", FT_UINT32, BASE_DEC, NULL, 0x40000000, NULL, HFILL }
},
{ &hf_vntag_vif_list_id,
{ "Downlink Ports", "vntag.vif_list_id", FT_UINT32, BASE_DEC, NULL, 0x30000000, NULL, HFILL }
},
{ &hf_vntag_dst,
{ "Destination", "vntag.dst", FT_UINT32, BASE_DEC, NULL, 0x0FFF0000, NULL, HFILL }
},
{ &hf_vntag_looped,
{ "Looped", "vntag.looped", FT_UINT32, BASE_DEC, NULL, 0x00008000, NULL, HFILL }
},
{ &hf_vntag_r,
{ "Reserved", "vntag.r", FT_UINT32, BASE_DEC, NULL, 0x00004000, NULL, HFILL }
},
{ &hf_vntag_version,
{ "Version", "vntag.version", FT_UINT32, BASE_DEC, NULL, 0x00003000, NULL, HFILL }
},
{ &hf_vntag_src,
{ "Source", "vntag.src", FT_UINT32, BASE_DEC, NULL, 0x00000FFF, NULL, HFILL }
},
#if 0
{ &hf_vntag_len,
{ "Length", "vntag.len", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
#endif
{ &hf_vntag_trailer,
{ "Trailer", "vntag.trailer", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
}
};
static gint *ett[] = {
&ett_vntag
};
proto_vntag = proto_register_protocol("VN-Tag", "VNTAG", "vntag");
proto_register_field_array(proto_vntag, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_vntag(void)
{
dissector_handle_t vntag_handle;
vntag_handle = create_dissector_handle(dissect_vntag, proto_vntag);
dissector_add_uint("ethertype", ETHERTYPE_VNTAG, vntag_handle);
ethertype_handle = find_dissector("ethertype");
}
