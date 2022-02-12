static int
dissect_tdmoe(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *tdmoe_tree;
tvbuff_t *next_client;
guint16 channels;
guint16 subaddress;
if (tvb_length(tvb) < 8)
return 0;
subaddress = tvb_get_ntohs(tvb, 0);
channels = tvb_get_ntohs(tvb, 6);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TDMoE");
col_add_fstr(pinfo->cinfo, COL_INFO, "Subaddress: %d Channels: %d %s",
subaddress,
channels,
(tvb_get_guint8(tvb, 3) & TDMOE_YELLOW_ALARM_BITMASK ? "[YELLOW ALARM]" : "")
);
if (tree) {
gint32 offset = 0;
static const gint *flags[] = { &hf_tdmoe_yellow_alarm, &hf_tdmoe_sig_bits_present, NULL };
ti = proto_tree_add_item(tree, proto_tdmoe, tvb, 0, -1, ENC_NA);
tdmoe_tree = proto_item_add_subtree(ti, ett_tdmoe);
proto_tree_add_item(tdmoe_tree, hf_tdmoe_subaddress, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tdmoe_tree, hf_tdmoe_samples, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_bitmask(tdmoe_tree, tvb, offset, hf_tdmoe_flags, ett_tdmoe_flags, flags, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tdmoe_tree, hf_tdmoe_packet_counter, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tdmoe_tree, hf_tdmoe_channels, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
if (tvb_get_guint8(tvb, 3) & TDMOE_SIGBITS_BITMASK) {
guint16 length = (channels >> 1) + ((channels & 0x01) ? 1 : 0);
proto_tree_add_item(tdmoe_tree, hf_tdmoe_sig_bits, tvb, offset, length, ENC_NA);
offset += length;
}
next_client = tvb_new_subset_remaining(tvb, offset);
return call_dissector(data_handle, next_client, pinfo, tdmoe_tree);
}
return tvb_reported_length(tvb);
}
void
proto_register_tdmoe(void)
{
static hf_register_info hf[] = {
{ &hf_tdmoe_subaddress,
{ "Subaddress", "tdmoe.subaddress", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_tdmoe_samples,
{ "Samples", "tdmoe.samples", FT_UINT8, BASE_DEC, NULL, 0x0,
"Samples per channel", HFILL }},
{ &hf_tdmoe_flags,
{ "Flags", "tdmoe.flags", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_tdmoe_yellow_alarm,
{ "Yellow Alarm", "tdmoe.yellowalarm", FT_BOOLEAN, 8, NULL, TDMOE_YELLOW_ALARM_BITMASK,
NULL, HFILL }},
{ &hf_tdmoe_sig_bits_present,
{ "Sig bits present", "tdmoe.sig_bits_present", FT_BOOLEAN, 8, NULL, TDMOE_SIGBITS_BITMASK,
NULL, HFILL }},
{ &hf_tdmoe_packet_counter,
{ "Counter", "tdmoe.counter", FT_UINT16, BASE_DEC, NULL, 0x0,
"Packet number", HFILL }},
{ &hf_tdmoe_channels,
{ "Channels", "tdmoe.channels", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_tdmoe_sig_bits,
{ "Sig bits", "tdmoe.sig_bits", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_tdmoe,
&ett_tdmoe_flags
};
proto_tdmoe = proto_register_protocol("Digium TDMoE Protocol", "TDMoE", "tdmoe");
proto_register_field_array(proto_tdmoe, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_tdmoe(void)
{
dissector_handle_t tdmoe_handle;
tdmoe_handle = new_create_dissector_handle(dissect_tdmoe, proto_tdmoe);
dissector_add_uint("ethertype", ETHERTYPE_TDMOE, tdmoe_handle);
data_handle = find_dissector("data");
}
