static void dissect_wimax_cdma_code_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gint offset = 0;
proto_item *cdma_item;
proto_tree *cdma_tree;
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "CDMA Code Attribute");
if (tree)
{
cdma_item = proto_tree_add_item(tree, proto_wimax_cdma_code_decoder, tvb, offset, -1, ENC_NA);
cdma_tree = proto_item_add_subtree(cdma_item, ett_wimax_cdma_code_decoder);
proto_tree_add_item(cdma_tree, hf_wimax_ranging_code, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(cdma_tree, hf_wimax_ranging_symbol_offset, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(cdma_tree, hf_wimax_ranging_subchannel_offset, tvb, offset+2, 1, ENC_BIG_ENDIAN);
}
}
void proto_register_wimax_cdma(void)
{
static hf_register_info hf[] =
{
{
&hf_wimax_ranging_code,
{
"Ranging Code", "wmx.cdma.ranging_code",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_wimax_ranging_symbol_offset,
{
"Ranging Symbol Offset", "wmx.cdma.ranging_symbol_offset",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_wimax_ranging_subchannel_offset,
{
"Ranging Sub-Channel Offset", "wmx.cdma.ranging_subchannel_offset",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL
}
}
};
static gint *ett[] =
{
&ett_wimax_cdma_code_decoder,
};
proto_wimax_cdma_code_decoder = proto_register_protocol (
"WiMax CDMA Code Attribute",
"CDMA Code Attribute",
"wmx.cdma"
);
proto_register_field_array(proto_wimax_cdma_code_decoder, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("wimax_cdma_code_burst_handler", dissect_wimax_cdma_code_decoder, -1);
}
