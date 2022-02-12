static void
dissect_stt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *stt_tree, *flg_tree;
proto_item *ti, *flg_item, *l4_offset_item;
tvbuff_t *next_tvb;
guint8 flags, l4_offset;
guint16 attributes;
guint64 context_id;
int offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "STT");
col_clear_fence(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_stt, tvb, offset, -1, ENC_NA);
stt_tree = proto_item_add_subtree(ti, ett_stt);
proto_tree_add_item(stt_tree, hf_stt_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
flg_item = proto_tree_add_item(stt_tree, hf_stt_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
flg_tree = proto_item_add_subtree(flg_item, ett_stt_flgs);
flags = tvb_get_guint8(tvb, offset);
proto_tree_add_item(flg_tree, hf_stt_flag_b7, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flg_tree, hf_stt_flag_b6, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flg_tree, hf_stt_flag_b5, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flg_tree, hf_stt_flag_b4, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flg_tree, hf_stt_flag_b3, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flg_tree, hf_stt_flag_b2, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flg_tree, hf_stt_flag_b1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flg_tree, hf_stt_flag_b0, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
l4_offset = tvb_get_guint8(tvb, offset);
l4_offset_item = proto_tree_add_item(stt_tree, hf_stt_l4_offset, tvb, offset, 1, ENC_BIG_ENDIAN);
if ( !(flags & FLAG_B3_MASK) && (l4_offset != 0) ) {
expert_add_info_format(pinfo, l4_offset_item, &ei_stt_l4_offset, "Incorrect offset, should be equals to zero");
}
if ( (flags & FLAG_B3_MASK) && (l4_offset == 0) ) {
expert_add_info_format(pinfo, l4_offset_item, &ei_stt_l4_offset, "Incorrect offset, should be greater than zero");
}
offset ++;
proto_tree_add_item(stt_tree, hf_stt_reserved_8, tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
proto_tree_add_item(stt_tree, hf_stt_mss, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
attributes = tvb_get_ntohs(tvb, offset);
if (attributes & STT_V_MASK) {
proto_item_append_text(ti, ", Priority: %u, VLAN ID: %u", (attributes >> 13), (attributes & STT_VLANID_MASK));
proto_tree_add_item(stt_tree, hf_stt_pcp, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(stt_tree, hf_stt_v, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(stt_tree, hf_stt_vlan_id, tvb, offset, 2, ENC_BIG_ENDIAN);
}
offset += 2;
context_id = tvb_get_ntoh64(tvb, offset);
proto_tree_add_item(stt_tree, hf_stt_context_id, tvb, offset, 8, ENC_BIG_ENDIAN);
proto_item_append_text(ti, ", Context ID: 0x%" G_GINT64_MODIFIER "x",context_id);
offset += 8;
proto_tree_add_item(stt_tree, hf_stt_padding, tvb, offset, 2, ENC_NA);
offset += 2;
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(eth_handle, next_tvb, pinfo, tree);
}
void
proto_register_stt(void)
{
expert_module_t* expert_stt;
static hf_register_info hf[] = {
{ &hf_stt_version,
{ "Version", "stt.version",
FT_UINT8, BASE_DEC, NULL, NO_MASK,
NULL, HFILL
},
},
{ &hf_stt_flags,
{ "Flags", "stt.flags",
FT_UINT8, BASE_HEX, NULL, NO_MASK,
NULL, HFILL,
},
},
{ &hf_stt_flag_b7,
{ "Unused flag", "stt.flags.b7",
FT_BOOLEAN, 8, NULL, FLAG_B7_MASK,
NULL, HFILL,
},
},
{ &hf_stt_flag_b6,
{ "Unused flag", "stt.flags.b6",
FT_BOOLEAN, 8, NULL, FLAG_B6_MASK,
NULL, HFILL,
},
},
{ &hf_stt_flag_b5,
{ "Unused flag", "stt.flags.b5",
FT_BOOLEAN, 8, NULL, FLAG_B5_MASK,
NULL, HFILL,
},
},
{ &hf_stt_flag_b4,
{ "Unused flag", "stt.flags.b4",
FT_BOOLEAN, 8, NULL, FLAG_B4_MASK,
NULL, HFILL,
},
},
{ &hf_stt_flag_b3,
{ "TCP payload", "stt.flags.b3",
FT_BOOLEAN, 8, NULL, FLAG_B3_MASK,
NULL, HFILL,
},
},
{ &hf_stt_flag_b2,
{ "IPv4 packet", "stt.flags.b2",
FT_BOOLEAN, 8, NULL, FLAG_B2_MASK,
NULL, HFILL,
},
},
{ &hf_stt_flag_b1,
{ "Checksum partial", "stt.flags.b1",
FT_BOOLEAN, 8, NULL, FLAG_B1_MASK,
NULL, HFILL,
},
},
{ &hf_stt_flag_b0,
{ "Checksum verified", "stt.flags.b0",
FT_BOOLEAN, 8, NULL, FLAG_B0_MASK,
NULL, HFILL,
},
},
{ &hf_stt_l4_offset,
{ "L4 Offset", "stt.l4offset",
FT_UINT8, BASE_DEC, NULL, NO_MASK,
NULL, HFILL,
},
},
{ &hf_stt_reserved_8,
{ "Reserved", "stt.reserved",
FT_UINT8, BASE_DEC, NULL, NO_MASK,
NULL, HFILL,
},
},
{ &hf_stt_mss,
{ "Max Segment Size", "stt.mss",
FT_UINT16, BASE_DEC, NULL, NO_MASK,
NULL, HFILL,
},
},
{ &hf_stt_pcp,
{ "PCP", "stt.pcp",
FT_UINT16, BASE_DEC, VALS(pri_vals), STT_PCP_MASK,
NULL, HFILL,
},
},
{ &hf_stt_v,
{ "V flag", "stt.v",
FT_UINT16, BASE_DEC, NULL, STT_V_MASK,
NULL, HFILL,
},
},
{ &hf_stt_vlan_id,
{ "VLAN ID", "stt.vlan_id",
FT_UINT16, BASE_DEC, NULL, STT_VLANID_MASK,
NULL, HFILL,
},
},
{ &hf_stt_context_id,
{ "Context ID", "stt.context_id",
FT_UINT64, BASE_HEX, NULL, NO_MASK,
NULL, HFILL,
},
},
{ &hf_stt_padding,
{ "Padding", "stt.padding",
FT_BYTES, BASE_NONE, NULL, NO_MASK,
NULL, HFILL,
},
},
};
static gint *ett[] = {
&ett_stt,
&ett_stt_flgs,
};
static ei_register_info ei[] = {
{ &ei_stt_l4_offset,
{ "stt.l4_offset_bad.expert", PI_PROTOCOL,
PI_WARN, "Bad L4 Offset", EXPFILL
}
},
};
proto_stt = proto_register_protocol("Stateless Transport Tunneling",
"STT", "stt");
expert_stt = expert_register_protocol(proto_stt);
expert_register_field_array(expert_stt, ei, array_length(ei));
proto_register_field_array(proto_stt, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_stt(void)
{
dissector_handle_t stt_handle;
eth_handle = find_dissector("eth");
stt_handle = create_dissector_handle(dissect_stt, proto_stt);
dissector_add_uint("tcp.port", TCP_PORT_STT, stt_handle);
}
