static void
dissect_airopeek(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *airopeek_tree = NULL;
proto_item *ti;
guint8 data_rate;
guint8 signal_level;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "AiroPeek");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
ti = proto_tree_add_item(tree, proto_airopeek, tvb, 0, 4, ENC_NA);
airopeek_tree = proto_item_add_subtree(ti, ett_airopeek);
}
data_rate = tvb_get_guint8(tvb, 0);
col_add_fstr(pinfo->cinfo, COL_TX_RATE, "%u.%u",
data_rate / 2,
data_rate & 1 ? 5 : 0);
if (tree) {
proto_tree_add_uint64_format(airopeek_tree, hf_data_rate, tvb, 0, 1,
(guint64)data_rate * 500000,
"Data Rate: %u.%u Mb/s",
data_rate / 2,
data_rate & 1 ? 5 : 0);
}
if (tree)
proto_tree_add_item(airopeek_tree, hf_channel, tvb, 1, 1, ENC_NA);
signal_level = tvb_get_guint8(tvb, 2);
col_add_fstr(pinfo->cinfo, COL_RSSI, "%u", signal_level);
if (tree) {
proto_tree_add_uint_format(airopeek_tree, hf_signal_strength, tvb, 2, 1,
signal_level,
"Signal Strength: %u%%",
signal_level);
}
pinfo->current_proto = "IEEE 802.11";
next_tvb = tvb_new_subset_remaining(tvb, 4);
call_dissector(ieee80211_handle, next_tvb, pinfo, tree);
}
void proto_register_ieee80211_airopeek(void)
{
static hf_register_info hf[] = {
{&hf_data_rate,
{"Data Rate", "airopeek.data_rate", FT_UINT64, BASE_DEC, NULL, 0,
"Data rate (b/s)", HFILL }},
{&hf_channel,
{"Channel", "airopeek.channel", FT_UINT8, BASE_DEC, NULL, 0,
"802.11 channel number that this frame was sent/received on", HFILL }},
{&hf_signal_strength,
{"Signal Strength", "airopeek.signal_strength", FT_UINT8, BASE_DEC, NULL, 0,
"Signal strength (Percentage)", HFILL }}
};
static gint *tree_array[] = {
&ett_airopeek
};
proto_airopeek = proto_register_protocol("AiroPeek 802.11 radio information",
"AiroPeek",
"airopeek");
proto_register_field_array(proto_airopeek, hf, array_length(hf));
proto_register_subtree_array(tree_array, array_length(tree_array));
}
void proto_reg_handoff_ieee80211_airopeek(void)
{
dissector_handle_t airopeek_handle;
airopeek_handle = create_dissector_handle(dissect_airopeek, proto_airopeek);
dissector_add_uint("wtap_encap", WTAP_ENCAP_IEEE_802_11_AIROPEEK,
airopeek_handle);
ieee80211_handle = find_dissector("wlan");
}
