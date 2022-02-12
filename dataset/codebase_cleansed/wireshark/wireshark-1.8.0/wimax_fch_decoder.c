static void dissect_wimax_fch_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gint offset = 0;
proto_item *fch_item = NULL;
proto_tree *fch_tree = NULL;
if(!bs_address.len)
COPY_ADDRESS(&bs_address, &(pinfo->src));
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "FCH");
if (tree)
{
fch_item = proto_tree_add_protocol_format(tree, proto_wimax_fch_decoder, tvb, offset, 3, "DL Frame Prefix (24 bits)");
fch_tree = proto_item_add_subtree(fch_item, ett_wimax_fch_decoder);
proto_tree_add_item(fch_tree, hf_fch_used_subchannel_group0, tvb, offset, FCH_BURST_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(fch_tree, hf_fch_used_subchannel_group1, tvb, offset, FCH_BURST_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(fch_tree, hf_fch_used_subchannel_group2, tvb, offset, FCH_BURST_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(fch_tree, hf_fch_used_subchannel_group3, tvb, offset, FCH_BURST_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(fch_tree, hf_fch_used_subchannel_group4, tvb, offset, FCH_BURST_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(fch_tree, hf_fch_used_subchannel_group5, tvb, offset, FCH_BURST_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(fch_tree, hf_fch_reserved_1, tvb, offset, FCH_BURST_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(fch_tree, hf_fch_repetition_coding_indication, tvb, offset, FCH_BURST_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(fch_tree, hf_fch_coding_indication, tvb, offset, FCH_BURST_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(fch_tree, hf_fch_dlmap_length, tvb, offset, FCH_BURST_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(fch_tree, hf_fch_reserved_2, tvb, offset, FCH_BURST_LENGTH, ENC_BIG_ENDIAN);
}
}
void proto_register_wimax_fch(void)
{
static hf_register_info hf[] =
{
{
&hf_fch_used_subchannel_group0,
{
"Sub-Channel Group 0", "wmx.fch.subchannel_group0",
FT_UINT24, BASE_DEC, VALS(used_or_not_used), USED_SUB_CHANNEL_GROUP_0,
NULL, HFILL
}
},
{
&hf_fch_used_subchannel_group1,
{
"Sub-Channel Group 1", "wmx.fch.subchannel_group1",
FT_UINT24, BASE_DEC, VALS(used_or_not_used), USED_SUB_CHANNEL_GROUP_1,
NULL, HFILL
}
},
{
&hf_fch_used_subchannel_group2,
{
"Sub-Channel Group 2", "wmx.fch.subchannel_group2",
FT_UINT24, BASE_DEC, VALS(used_or_not_used), USED_SUB_CHANNEL_GROUP_2,
NULL, HFILL
}
},
{
&hf_fch_used_subchannel_group3,
{
"Sub-Channel Group 3", "wmx.fch.subchannel_group3",
FT_UINT24, BASE_DEC, VALS(used_or_not_used), USED_SUB_CHANNEL_GROUP_3,
NULL, HFILL
}
},
{
&hf_fch_used_subchannel_group4,
{
"Sub-Channel Group 4", "wmx.fch.subchannel_group4",
FT_UINT24, BASE_DEC, VALS(used_or_not_used), USED_SUB_CHANNEL_GROUP_4,
NULL, HFILL
}
},
{
&hf_fch_used_subchannel_group5,
{
"Sub-Channel Group 5", "wmx.fch.subchannel_group5",
FT_UINT24, BASE_DEC, VALS(used_or_not_used), USED_SUB_CHANNEL_GROUP_5,
NULL, HFILL
}
},
{
&hf_fch_reserved_1,
{
"Reserved", "wmx.fch.reserved1",
FT_UINT24, BASE_DEC, NULL, FCH_RESERVED_1,
NULL, HFILL
}
},
{
&hf_fch_repetition_coding_indication,
{
"Repetition Coding Indication", "wmx.fch.repetition_coding_indication",
FT_UINT24, BASE_DEC, VALS(repetition_coding_indications), REPETITION_CODING_INDICATION,
NULL, HFILL
}
},
{
&hf_fch_coding_indication,
{
"Coding Indication", "wmx.fch.coding_indication",
FT_UINT24, BASE_DEC, VALS(coding_indications), CODING_INDICATION,
NULL, HFILL
}
},
{
&hf_fch_dlmap_length,
{
"DL Map Length", "wmx.fch.dl_map_length",
FT_UINT24, BASE_DEC, NULL, DL_MAP_LENGTH,
NULL, HFILL
}
},
{
&hf_fch_reserved_2,
{
"Reserved", "wmx.fch.reserved2",
FT_UINT24, BASE_DEC, NULL, FCH_RESERVED_2,
NULL, HFILL
}
}
};
static gint *ett[] =
{
&ett_wimax_fch_decoder,
};
proto_wimax_fch_decoder = proto_wimax;
proto_register_field_array(proto_wimax_fch_decoder, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("wimax_fch_burst_handler", dissect_wimax_fch_decoder, -1);
}
