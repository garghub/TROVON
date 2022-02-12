static void
dissect_airopeek(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *airopeek_tree = NULL;
proto_item *ti;
guint8 data_rate;
guint8 signal_level;
tvbuff_t *next_tvb;
struct ieee_802_11_phdr phdr;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "AiroPeek");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
ti = proto_tree_add_item(tree, proto_airopeek, tvb, 0, 4, ENC_NA);
airopeek_tree = proto_item_add_subtree(ti, ett_airopeek);
}
phdr.fcs_len = 0;
phdr.decrypted = FALSE;
phdr.datapad = FALSE;
phdr.phy = PHDR_802_11_PHY_UNKNOWN;
phdr.presence_flags =
PHDR_802_11_HAS_CHANNEL|
PHDR_802_11_HAS_DATA_RATE|
PHDR_802_11_HAS_SIGNAL_PERCENT;
data_rate = tvb_get_guint8(tvb, 0);
phdr.data_rate = data_rate;
col_add_fstr(pinfo->cinfo, COL_TX_RATE, "%u.%u",
data_rate / 2,
data_rate & 1 ? 5 : 0);
if (tree) {
proto_tree_add_uint64_format_value(airopeek_tree, hf_data_rate, tvb, 0, 1,
(guint64)data_rate * 500000,
"%u.%u Mb/s",
data_rate / 2,
data_rate & 1 ? 5 : 0);
}
phdr.channel = tvb_get_guint8(tvb, 1);
if (tree)
proto_tree_add_item(airopeek_tree, hf_channel, tvb, 1, 1, ENC_BIG_ENDIAN);
signal_level = tvb_get_guint8(tvb, 2);
phdr.signal_percent = signal_level;
col_add_fstr(pinfo->cinfo, COL_RSSI, "%u%%", signal_level);
proto_tree_add_uint_format_value(airopeek_tree, hf_signal_strength, tvb, 2, 1,
signal_level,
"%u%%",
signal_level);
pinfo->current_proto = "IEEE 802.11";
next_tvb = tvb_new_subset_remaining(tvb, 4);
call_dissector_with_data(ieee80211_radio_handle, next_tvb, pinfo, tree, &phdr);
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
ieee80211_radio_handle = find_dissector("wlan_radio");
}
