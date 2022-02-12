static void
dissect_peekremote(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tvbuff_t *next_tvb;
proto_tree *peekremote_tree = NULL;
proto_item *ti = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "AIROPEEK");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
ti = proto_tree_add_item(tree, proto_peekremote, tvb, 0, -1, ENC_NA);
peekremote_tree = proto_item_add_subtree(ti, ett_peekremote);
proto_tree_add_item(peekremote_tree, hf_peekremote_unknown1, tvb, 0, 2, ENC_NA);
proto_tree_add_item(peekremote_tree, hf_peekremote_unknown2, tvb, 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(peekremote_tree, hf_peekremote_unknown3, tvb, 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(peekremote_tree, hf_peekremote_unknown4, tvb, 6, 5, ENC_NA);
proto_tree_add_item(peekremote_tree, hf_peekremote_timestamp, tvb, 11, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(peekremote_tree, hf_peekremote_unknown5, tvb, 15, 2, ENC_NA);
proto_tree_add_item(peekremote_tree, hf_peekremote_channel, tvb, 17, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(peekremote_tree, hf_peekremote_unknown6, tvb, 18, 2, ENC_NA);
}
next_tvb = tvb_new_subset_remaining(tvb, 20);
pinfo->pseudo_header->ieee_802_11.fcs_len = 4;
call_dissector(ieee80211_handle, next_tvb, pinfo, tree);
}
void
proto_register_peekremote(void)
{
static hf_register_info hf[] = {
{ &hf_peekremote_unknown1,
{ "Unknown1", "peekremote.unknown1", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_peekremote_unknown2,
{ "caplength1", "peekremote.unknown2", FT_UINT16, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_peekremote_unknown3,
{ "caplength2", "peekremote.unknown3", FT_UINT16, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_peekremote_unknown4,
{ "Unknown4", "peekremote.unknown4", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_peekremote_unknown5,
{ "Unknown5", "peekremote.unknown5", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_peekremote_unknown6,
{ "Unknown6", "peekremote.unknown6", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_peekremote_timestamp,
{ "Timestamp?", "peekremote.timestamp", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_peekremote_channel,
{ "Channel", "peekremote.channel", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_peekremote,
};
proto_peekremote = proto_register_protocol(
"AiroPeek/OmniPeek encapsulated IEEE 802.11", "PEEKREMOTE", "peekremote");
proto_register_field_array(proto_peekremote, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_peekremote(void)
{
dissector_handle_t peekremote_handle;
ieee80211_handle = find_dissector("wlan_datapad");
peekremote_handle = create_dissector_handle(dissect_peekremote, proto_peekremote);
dissector_add_uint("udp.port", 5000, peekremote_handle);
}
