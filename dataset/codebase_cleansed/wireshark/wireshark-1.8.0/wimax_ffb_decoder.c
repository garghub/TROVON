static void dissect_wimax_ffb_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gint offset = 0;
guint length, num_of_ffbs, i;
proto_item *ffb_item = NULL;
proto_tree *ffb_tree = NULL;
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Fast Feedback Burst:");
if (tree)
{
length = tvb_reported_length(tvb);
ffb_item = proto_tree_add_protocol_format(tree, proto_wimax_ffb_decoder, tvb, offset, length, "Fast Feedback Burst (%u bytes)", length);
ffb_tree = proto_item_add_subtree(ffb_item, ett_wimax_ffb_decoder);
num_of_ffbs = tvb_get_guint8(tvb, offset);
proto_tree_add_item(ffb_tree, hf_ffb_num_of_ffbs, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ffb_tree, hf_ffb_type, tvb, offset++, 1, ENC_BIG_ENDIAN);
for(i = 0; i < num_of_ffbs; i++)
{
proto_tree_add_item(ffb_tree, hf_ffb_subchannel, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ffb_tree, hf_ffb_symboloffset, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ffb_tree, hf_ffb_value, tvb, offset++, 1, ENC_BIG_ENDIAN);
}
}
}
void proto_register_wimax_ffb(void)
{
static hf_register_info hf[] =
{
{
&hf_ffb_burst,
{"Fast Feedback Burst", "wmx.ffb.burst", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_ffb_num_of_ffbs,
{"Number Of Fast Feedback", "wmx.ffb.num_of_ffbs", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_ffb_type,
{"Fast Feedback Type", "wmx.ffb.ffb_type", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{
&hf_ffb_subchannel,
{"Physical Subchannel", "wmx.ffb.subchannel", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_ffb_symboloffset,
{"Symbol Offset", "wmx.ffb.symbol_offset", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_ffb_value,
{"Fast Feedback Value", "wmx.ffb.ffb_value", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
}
};
static gint *ett[] =
{
&ett_wimax_ffb_decoder,
};
proto_wimax_ffb_decoder = proto_wimax;
proto_register_field_array(proto_wimax_ffb_decoder, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("wimax_ffb_burst_handler", dissect_wimax_ffb_decoder, -1);
}
