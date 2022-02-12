static void
dissect_radio (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
proto_item *ti = NULL;
proto_tree *radio_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Radio");
col_clear(pinfo->cinfo, COL_INFO);
col_add_fstr(pinfo->cinfo, COL_TX_RATE, "%u.%u",
pinfo->pseudo_header->ieee_802_11.data_rate / 2,
pinfo->pseudo_header->ieee_802_11.data_rate & 1 ? 5 : 0);
col_add_fstr(pinfo->cinfo, COL_RSSI, "%u%%",
pinfo->pseudo_header->ieee_802_11.signal_level);
if (tree) {
ti = proto_tree_add_item(tree, proto_radio, tvb, 0, 0, ENC_NA);
radio_tree = proto_item_add_subtree (ti, ett_radio);
proto_tree_add_uint64_format(radio_tree, hf_data_rate, tvb, 0, 0,
(guint64)pinfo->pseudo_header->ieee_802_11.data_rate * 500000,
"Data Rate: %u.%u Mb/s",
pinfo->pseudo_header->ieee_802_11.data_rate / 2,
pinfo->pseudo_header->ieee_802_11.data_rate & 1 ? 5 : 0);
proto_tree_add_uint(radio_tree, hf_channel, tvb, 0, 0,
pinfo->pseudo_header->ieee_802_11.channel);
proto_tree_add_uint_format(radio_tree, hf_signal_strength, tvb, 0, 0,
pinfo->pseudo_header->ieee_802_11.signal_level,
"Signal Strength: %u%%",
pinfo->pseudo_header->ieee_802_11.signal_level);
}
pinfo->current_proto = "IEEE 802.11";
call_dissector(ieee80211_handle, tvb, pinfo, tree);
}
void proto_register_ieee80211_radio(void)
{
proto_radio = proto_register_protocol("802.11 radio information", "Radio",
"radio");
proto_register_field_array(proto_radio, hf_radio, array_length(hf_radio));
proto_register_subtree_array(tree_array, array_length(tree_array));
}
void proto_reg_handoff_ieee80211_radio(void)
{
dissector_handle_t radio_handle;
radio_handle = create_dissector_handle(dissect_radio, proto_radio);
dissector_add_uint("wtap_encap", WTAP_ENCAP_IEEE_802_11_WITH_RADIO,
radio_handle);
ieee80211_handle = find_dissector("wlan");
}
