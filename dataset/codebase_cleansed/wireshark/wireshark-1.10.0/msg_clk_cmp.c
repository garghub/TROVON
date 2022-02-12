void dissect_mac_mgmt_msg_clk_cmp_decoder(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
guint offset = 0;
guint i;
guint clock_count;
guint tvb_len, payload_type;
proto_item *clk_cmp_item = NULL;
proto_tree *clk_cmp_tree = NULL;
payload_type = tvb_get_guint8(tvb, 0);
if(payload_type != MAC_MGMT_MSG_CLK_CMP)
{
return;
}
if (tree)
{
tvb_len = tvb_reported_length(tvb);
clk_cmp_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_clk_cmp_decoder, tvb, offset, tvb_len, "Clock Comparison (CLK-CMP) (%u bytes)", tvb_len);
clk_cmp_tree = proto_item_add_subtree(clk_cmp_item, ett_mac_mgmt_msg_clk_cmp_decoder);
proto_tree_add_item(clk_cmp_tree, hf_clk_cmp_message_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
clock_count = tvb_get_guint8(tvb, offset);
proto_tree_add_item(clk_cmp_tree, hf_clk_cmp_clock_count, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
for (i = 0; i < clock_count; i++ )
{
proto_tree_add_item(clk_cmp_tree, hf_clk_cmp_clock_id, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(clk_cmp_tree, hf_clk_cmp_seq_number, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(clk_cmp_tree, hf_clk_cmp_comparison_value, tvb, offset++, 1, ENC_BIG_ENDIAN);
}
}
}
void proto_register_mac_mgmt_msg_clk_cmp(void)
{
static hf_register_info hf_clk_cmp[] =
{
{
&hf_clk_cmp_message_type,
{
"MAC Management Message Type", "wmx.macmgtmsgtype.clk_cmp",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_clk_cmp_clock_count,
{
"Clock Count", "wmx.clk_cmp.clock_count",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_clk_cmp_clock_id,
{
"Clock ID", "wmx.clk_cmp.clock_id",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_clk_cmp_comparison_value,
{
"Comparison Value", "wmx.clk_cmp.comparison_value",
FT_INT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
#if 0
{
&hf_clk_cmp_invalid_tlv,
{
"Invalid TLV", "wmx.clk_cmp.invalid_tlv",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
}
},
#endif
{
&hf_clk_cmp_seq_number,
{
"Sequence Number", "wmx.clk_cmp.seq_number",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
}
};
static gint *ett[] =
{
&ett_mac_mgmt_msg_clk_cmp_decoder,
};
proto_mac_mgmt_msg_clk_cmp_decoder = proto_register_protocol (
"WiMax CLK-CMP Message",
"WiMax CLK-CMP (clk)",
"wmx.clk"
);
proto_register_field_array(proto_mac_mgmt_msg_clk_cmp_decoder, hf_clk_cmp, array_length(hf_clk_cmp));
proto_register_subtree_array(ett, array_length(ett));
}
