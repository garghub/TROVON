static int
dissect_hsr_prp_supervision(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *hsr_prp_supervision_tree;
guint8 tlv_type;
guint8 tlv_length;
guint16 sup_version;
int offset;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HSR/PRP");
col_set_str(pinfo->cinfo, COL_INFO, "HSR or PRP Supervision");
ti = proto_tree_add_item(tree, proto_hsr_prp_supervision, tvb, 0, -1, ENC_NA);
hsr_prp_supervision_tree = proto_item_add_subtree(ti, ett_hsr_prp_supervision);
offset = 0;
proto_tree_add_item(hsr_prp_supervision_tree, hf_hsr_prp_supervision_path,
tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(hsr_prp_supervision_tree, hf_hsr_prp_supervision_version,
tvb, offset, 2, ENC_BIG_ENDIAN);
sup_version = tvb_get_ntohs(tvb, 0) & 0x0fff;
offset += 2;
if (sup_version > 0) {
proto_tree_add_item(hsr_prp_supervision_tree, hf_hsr_prp_supervision_seqno,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
while (tvb_reported_length_remaining(tvb, offset) > 0) {
tlv_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(hsr_prp_supervision_tree, hf_hsr_prp_supervision_tlv_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
tlv_length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(hsr_prp_supervision_tree, hf_hsr_prp_supervision_tlv_length,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if ((tlv_type == 20 || tlv_type == 21 || tlv_type == 23) && (tlv_length == 6 || tlv_length == 12)) {
if (tlv_type == 23) {
col_set_str(pinfo->cinfo, COL_INFO, "HSR Supervision");
} else {
col_set_str(pinfo->cinfo, COL_INFO, "PRP Supervision");
}
if (tlv_length == 12) {
proto_tree_add_item(hsr_prp_supervision_tree, hf_hsr_prp_supervision_source_mac_address_A,
tvb, offset, 6, ENC_NA);
proto_tree_add_item(hsr_prp_supervision_tree, hf_hsr_prp_supervision_source_mac_address_B,
tvb, offset+6, 6, ENC_NA);
} else {
proto_tree_add_item(hsr_prp_supervision_tree, hf_hsr_prp_supervision_source_mac_address,
tvb, offset, 6, ENC_NA);
}
} else if (tlv_type == 30 && tlv_length == 6) {
proto_tree_add_item(hsr_prp_supervision_tree, hf_hsr_prp_supervision_red_box_mac_address,
tvb, offset, 6, ENC_NA);
if (sup_version == 0) {
offset += tlv_length;
break;
}
} else if (tlv_type == 31 && tlv_length == 6) {
proto_tree_add_item(hsr_prp_supervision_tree, hf_hsr_prp_supervision_vdan_mac_address,
tvb, offset, 6, ENC_NA);
if (sup_version == 0) {
offset += tlv_length;
break;
}
} else if (tlv_type == 0) {
offset += tlv_length;
break;
} else {
}
offset += tlv_length;
}
proto_item_set_len(ti, offset);
tvb_set_reported_length(tvb, offset);
return tvb_captured_length(tvb);
}
void proto_register_hsr_prp_supervision(void)
{
static hf_register_info hf[] = {
{ &hf_hsr_prp_supervision_path,
{ "Path", "hsr_prp_supervision.path",
FT_UINT16, BASE_DEC, NULL, 0xf000,
NULL, HFILL }
},
{ &hf_hsr_prp_supervision_version,
{ "Version", "hsr_prp_supervision.version",
FT_UINT16, BASE_DEC, NULL, 0x0fff,
NULL, HFILL }
},
{ &hf_hsr_prp_supervision_seqno,
{ "Sequence number", "hsr_prp_supervision.supervision_seqno",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_hsr_prp_supervision_tlv_type,
{ "TLV type", "hsr_prp_supervision.tlv.type",
FT_UINT8, BASE_DEC, VALS(type_vals), 0x00,
NULL, HFILL }
},
{ &hf_hsr_prp_supervision_tlv_length,
{ "TLV length", "hsr_prp_supervision.tlv.length",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_hsr_prp_supervision_source_mac_address_A,
{ "Source MAC Address A", "hsr_prp_supervision.source_mac_address_A",
FT_ETHER, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_hsr_prp_supervision_source_mac_address_B,
{ "Source MAC Address B", "hsr_prp_supervision.source_mac_address_B",
FT_ETHER, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_hsr_prp_supervision_source_mac_address,
{ "Source MAC Address", "hsr_prp_supervision.source_mac_address",
FT_ETHER, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_hsr_prp_supervision_red_box_mac_address,
{ "RedBox MAC Address", "hsr_prp_supervision.red_box_mac_address",
FT_ETHER, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_hsr_prp_supervision_vdan_mac_address,
{ "VDAN MAC Address", "hsr_prp_supervision.vdan_mac_address",
FT_ETHER, BASE_NONE, NULL, 0x00,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_hsr_prp_supervision
};
proto_hsr_prp_supervision = proto_register_protocol("HSR/PRP Supervision (IEC62439 Part 3)",
"HSR_PRP_SUPERVISION", "hsr_prp_supervision");
proto_register_field_array(proto_hsr_prp_supervision, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_hsr_prp_supervision(void)
{
dissector_handle_t hsr_prp_supervision_handle;
hsr_prp_supervision_handle = create_dissector_handle(dissect_hsr_prp_supervision, proto_hsr_prp_supervision);
dissector_add_uint("ethertype", ETHERTYPE_PRP, hsr_prp_supervision_handle);
}
