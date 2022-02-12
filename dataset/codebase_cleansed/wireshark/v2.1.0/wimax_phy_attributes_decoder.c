static int dissect_wimax_phy_attributes_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint offset = 0;
guint tvb_len;
proto_item *phy_item = NULL;
proto_tree *phy_tree = NULL;
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "PHY-attr");
if (tree)
{
tvb_len = tvb_reported_length(tvb);
phy_item = proto_tree_add_protocol_format(tree, proto_wimax_phy_attributes_decoder, tvb, offset, tvb_len, "PDU Burst Physical Attributes (%u bytes)", tvb_len);
phy_tree = proto_item_add_subtree(phy_item, ett_wimax_phy_attributes_decoder);
proto_tree_add_item(phy_tree, hf_phy_attributes_subchannelization_type, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(phy_tree, hf_phy_attributes_permbase, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(phy_tree, hf_phy_attributes_modulation_rate, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(phy_tree, hf_phy_attributes_encoding_type, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(phy_tree, hf_phy_attributes_num_repeat, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(phy_tree, hf_phy_attributes_symbol_offset, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(phy_tree, hf_phy_attributes_num_of_slots, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
while(offset < tvb_len)
{
proto_tree_add_item(phy_tree, hf_phy_attributes_subchannel, tvb, offset++, 1, ENC_BIG_ENDIAN);
}
}
return tvb_captured_length(tvb);
}
void proto_register_wimax_phy_attributes(void)
{
static hf_register_info hf[] =
{
{
&hf_phy_attributes_subchannelization_type,
{"Subchannelization Type", "wmx.phy_attributes.subchannelization_type", FT_UINT8, BASE_DEC, VALS(vals_subchannel_types), 0x0, NULL, HFILL}
},
{
&hf_phy_attributes_permbase,
{"Permbase", "wmx.phy_attributes.permbase", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{
&hf_phy_attributes_modulation_rate,
{"Modulation Rate", "wmx.phy_attributes.modulation_rate", FT_UINT8, BASE_DEC, VALS(vals_modulation_rates), 0x0, NULL, HFILL}
},
{
&hf_phy_attributes_encoding_type,
{"Encoding Type", "wmx.phy_attributes.encoding_type", FT_UINT8, BASE_DEC, VALS(vals_encoding_types), 0x0, NULL, HFILL}
},
{
&hf_phy_attributes_num_repeat,
{"numRepeat", "wmx.phy_attributes.num_repeat", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_phy_attributes_symbol_offset,
{"Symbol Offset", "wmx.phy_attributes.symbol_offset", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_phy_attributes_num_of_slots,
{"Number Of Slots", "wmx.phy_attributes.num_of_slots", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_phy_attributes_subchannel,
{"Subchannel", "wmx.phy_attributes.subchannel", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
}
};
static gint *ett[] =
{
&ett_wimax_phy_attributes_decoder
};
proto_wimax_phy_attributes_decoder = proto_wimax;
register_dissector("wimax_phy_attributes_burst_handler", dissect_wimax_phy_attributes_decoder, -1);
proto_register_field_array(proto_wimax_phy_attributes_decoder, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
