static int
dissect_etag(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint16 encap_proto;
proto_tree *etag_tree = NULL;
ethertype_data_t ethertype_data;
guint64 tci;
static const int * fields1[] = {
&hf_etag_pcp,
&hf_etag_dei,
&hf_etag_iecid_base,
NULL
};
static const int * fields2[] = {
&hf_etag_res,
&hf_etag_grp,
&hf_etag_ecid_base,
NULL
};
tci = tvb_get_ntoh48( tvb, 0);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ETAG");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
guint32 e_cid, ing_e_cid;
proto_item *ti = proto_tree_add_item(tree, proto_etag, tvb, 0, IEEE8021BR_LEN - 2, ENC_NA);
e_cid = (guint32)((((tci >> 16) & 0xFFF) | (tci << 12)) & 0xFFFFF);
ing_e_cid = (guint32)((((tci >> 32) & 0xFFF) | ((tci << 4) & 0xFF000)) & 0xFFFFF);
if (etag_summary_in_tree) {
proto_item_append_text(ti, ", TCI: 0x%" G_GINT64_MODIFIER "x Ingress_E-CID: %u E-CID: %u", tci, ing_e_cid, e_cid);
}
etag_tree = proto_item_add_subtree(ti, ett_etag);
proto_tree_add_bitmask_list(etag_tree, tvb, 0, 2, fields1, ENC_BIG_ENDIAN);
proto_tree_add_bitmask_list(etag_tree, tvb, 2, 2, fields2, ENC_BIG_ENDIAN);
proto_tree_add_item(etag_tree, hf_etag_iecid_ext, tvb, 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(etag_tree, hf_etag_ecid_ext, tvb, 5, 1, ENC_BIG_ENDIAN);
}
encap_proto = tvb_get_ntohs(tvb, IEEE8021BR_LEN - 2);
ethertype_data.etype = encap_proto;
ethertype_data.offset_after_ethertype = IEEE8021BR_LEN;
ethertype_data.fh_tree = etag_tree;
ethertype_data.etype_id = hf_etag_etype;
ethertype_data.trailer_id = hf_etag_trailer;
ethertype_data.fcs_len = 0;
call_dissector_with_data(ethertype_handle, tvb, pinfo, tree, &ethertype_data);
return tvb_captured_length(tvb);
}
void
proto_register_etag(void)
{
static hf_register_info hf[] = {
{ &hf_etag_pcp,
{ "E-PCP", "etag.pcp", FT_UINT16, BASE_DEC, VALS(pri_vals), 0xE000,
"Descriptions are recommendations from IEEE standard 802.1D-2004", HFILL }
},
{ &hf_etag_dei,
{ "E-DEI", "etag.dei", FT_UINT16, BASE_DEC, NULL, 0x1000, NULL, HFILL }
},
{ &hf_etag_iecid_base,
{ "Ingress_E-CID_base", "etag.iecid_base", FT_UINT16, BASE_HEX, NULL, 0x0FFF, NULL, HFILL }
},
{ &hf_etag_res,
{ "Reserved", "etag.resv", FT_UINT16, BASE_DEC, NULL, 0xC000, NULL, HFILL }
},
{ &hf_etag_grp,
{ "GRP", "etag.group", FT_UINT16, BASE_DEC, VALS(grp_vals), 0x3000, NULL, HFILL }
},
{ &hf_etag_ecid_base,
{ "E-CID_base", "etag.ecid_base", FT_UINT16, BASE_HEX, NULL, 0xFFF, NULL, HFILL }
},
{ &hf_etag_iecid_ext,
{ "Ingress_E-CID_ext", "etag.iecid_ext", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_etag_ecid_ext,
{ "E-CID_ext", "etag.ecid_ext", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_etag_etype,
{ "Type", "etag.etype", FT_UINT16, BASE_HEX, VALS(etype_vals), 0x0, NULL, HFILL }
},
{ &hf_etag_trailer,
{ "Trailer", "etag.trailer", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_etag
};
module_t *etag_module;
proto_etag = proto_register_protocol("802.1BR E-Tag", "ETAG", "etag");
proto_register_field_array(proto_etag, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
etag_module = prefs_register_protocol(proto_etag, proto_reg_handoff_etag);
prefs_register_bool_preference(etag_module, "summary_in_tree",
"Show E-Tag summary in protocol tree",
"Whether the E-Tag summary line should be shown in the protocol tree",
&etag_summary_in_tree);
}
void
proto_reg_handoff_etag(void)
{
dissector_handle_t etag_handle;
etag_handle = create_dissector_handle(dissect_etag, proto_etag);
dissector_add_uint("ethertype", ETHERTYPE_IEEE_802_1BR, etag_handle);
ethertype_handle = find_dissector_add_dependency("ethertype", proto_etag);
}
