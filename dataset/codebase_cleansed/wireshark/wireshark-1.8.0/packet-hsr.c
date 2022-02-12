static void
dissect_hsr_frame(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *hsr_tree;
tvbuff_t *next_tvb;
guint16 etype;
guint16 lsdu_size, lsdu_size_correct;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HSR");
col_set_str(pinfo->cinfo, COL_INFO, "HSR-Data Frame");
ti = proto_tree_add_item(tree, proto_hsr, tvb, 0, HSR_TOTAL_LENGTH, ENC_NA);
hsr_tree = proto_item_add_subtree(ti, ett_hsr_frame);
proto_tree_add_item(hsr_tree, hf_hsr_path,
tvb, HSR_PATH_OFFSET, HSR_LSDU_PATH_LENGTH , ENC_BIG_ENDIAN);
proto_tree_add_item(hsr_tree, hf_hsr_netid,
tvb, HSR_PATH_OFFSET, HSR_LSDU_PATH_LENGTH , ENC_BIG_ENDIAN);
proto_tree_add_item(hsr_tree, hf_hsr_laneid,
tvb, HSR_PATH_OFFSET, HSR_LSDU_PATH_LENGTH , ENC_BIG_ENDIAN);
lsdu_size = tvb_get_ntohs(tvb, HSR_PATH_OFFSET) & 0x0fff;
lsdu_size_correct = tvb_reported_length_remaining(tvb, 0);
if (lsdu_size == lsdu_size_correct) {
proto_tree_add_uint_format(hsr_tree, hf_hsr_lsdu_size,
tvb, HSR_PATH_OFFSET, HSR_LSDU_PATH_LENGTH, lsdu_size,
"LSDU size: %d [correct]", lsdu_size);
} else {
proto_tree_add_uint_format(hsr_tree, hf_hsr_lsdu_size,
tvb, HSR_PATH_OFFSET, HSR_LSDU_PATH_LENGTH, lsdu_size,
"LSDU size: %d [WRONG, should be %d]", lsdu_size, lsdu_size_correct);
}
proto_tree_add_item(hsr_tree, hf_hsr_sequence_nr,
tvb, HSR_SEQUENZNR_OFFSET,HSR_SEQUENZNR_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(hsr_tree, hf_type,
tvb, HSR_TOTAL_LENGTH,2, ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset (tvb, HSR_TOTAL_LENGTH + 2, -1, -1);
etype = tvb_get_ntohs(tvb, HSR_TOTAL_LENGTH);
if (!dissector_try_uint(ethertype_subdissector_table, etype, next_tvb, pinfo, tree))
call_dissector(data_handle, next_tvb, pinfo, hsr_tree);
}
void proto_register_hsr(void)
{
static hf_register_info hf[] = {
{ &hf_hsr_path,
{ "Path", "hsr.path",
FT_UINT16, BASE_DEC, NULL, 0xf000,
NULL, HFILL }
},
{ &hf_hsr_netid,
{ "Network id", "hsr.netid",
FT_UINT16, BASE_DEC, NULL, 0xe000,
NULL, HFILL }
},
{ &hf_hsr_laneid,
{ "Lane id", "hsr.laneid",
FT_UINT16, BASE_DEC, VALS(hsr_laneid_vals), 0x1000,
NULL, HFILL }
},
{ &hf_hsr_lsdu_size,
{ "LSDU size", "hsr.lsdu_size",
FT_UINT16, BASE_DEC, NULL, 0x0fff,
NULL, HFILL }
},
{ &hf_hsr_sequence_nr,
{ "Sequence number", "hsr.hsr_sequence_nr",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_type,
{ "Type", "hsr.type",
FT_UINT16, BASE_HEX, VALS(etype_vals), 0x00,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_hsr_frame,
};
proto_hsr = proto_register_protocol("High-availability Seamless Redundancy (IEC62439 Part 3 Chapter 5)",
"HSR", "hsr");
proto_register_field_array(proto_hsr, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_hsr(void)
{
dissector_handle_t hsr_frame_handle;
hsr_frame_handle = create_dissector_handle(dissect_hsr_frame, proto_hsr);
dissector_add_uint("ethertype", ETHERTYPE_HSR, hsr_frame_handle);
ethertype_subdissector_table = find_dissector_table("ethertype");
data_handle = find_dissector("data");
}
