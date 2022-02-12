static void dissect_wimax_hack_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gint offset = 0;
guint length, num_of_hacks, i;
proto_item *hack_item = NULL;
proto_tree *hack_tree = NULL;
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "HARQ ACK Burst:");
if (tree)
{
length = tvb_reported_length(tvb);
hack_item = proto_tree_add_protocol_format(tree, proto_wimax_hack_decoder, tvb, offset, length, "HARQ ACK Burst (%u bytes)", length);
hack_tree = proto_item_add_subtree(hack_item, ett_wimax_hack_decoder);
num_of_hacks = tvb_get_guint8(tvb, offset);
proto_tree_add_item(hack_tree, hf_hack_num_of_hacks, tvb, offset++, 1, ENC_BIG_ENDIAN);
for(i = 0; i < num_of_hacks; i++)
{
proto_tree_add_item(hack_tree, hf_hack_subchannel, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(hack_tree, hf_hack_symboloffset, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(hack_tree, hf_hack_half_slot_flag, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(hack_tree, hf_hack_value, tvb, offset++, 1, ENC_BIG_ENDIAN);
}
}
}
void proto_register_wimax_hack(void)
{
static hf_register_info hf[] =
{
{
&hf_hack_burst,
{"HARQ ACK Burst", "wmx.hack.burst", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_hack_num_of_hacks,
{"Number Of HARQ ACKs/NACKs", "wmx.hack.num_of_hacks", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_hack_subchannel,
{"Physical Subchannel", "wmx.hack.subchannel", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_hack_symboloffset,
{"Symbol Offset", "wmx.hack.symbol_offset", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_hack_half_slot_flag,
{"Half-Slot Flag", "wmx.hack.half_slot_flag", FT_UINT8, BASE_DEC, VALS(vals_flags), 0x0, NULL, HFILL}
},
{
&hf_hack_value,
{"ACK Value", "wmx.hack.hack_value", FT_UINT8, BASE_DEC, VALS(vals_values), 0x0, NULL, HFILL}
}
};
static gint *ett[] =
{
&ett_wimax_hack_decoder,
};
proto_wimax_hack_decoder = proto_wimax;
register_dissector("wimax_hack_burst_handler", dissect_wimax_hack_decoder, -1);
proto_register_field_array(proto_wimax_hack_decoder, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
