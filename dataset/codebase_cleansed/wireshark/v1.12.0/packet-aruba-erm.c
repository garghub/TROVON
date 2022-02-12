static int
dissect_aruba_erm_pcap(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *aruba_erm_tree, gint offset)
{
nstime_t ts;
ts.secs = tvb_get_ntohl(tvb, 0);
ts.nsecs = tvb_get_ntohl(tvb,4)*1000;
proto_tree_add_time(aruba_erm_tree, hf_aruba_erm_time, tvb, offset, 8,&ts);
offset +=8;
proto_tree_add_item(aruba_erm_tree, hf_aruba_erm_incl_len, tvb, 8, 4, ENC_BIG_ENDIAN);
offset +=4;
proto_tree_add_item(aruba_erm_tree, hf_aruba_erm_orig_len, tvb, 12, 4, ENC_BIG_ENDIAN);
offset +=4;
return offset;
}
static int
dissect_aruba_erm_pcap_radio(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *aruba_erm_tree, gint offset)
{
proto_item *ti_data_rate;
guint16 data_rate;
data_rate = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(aruba_erm_tree, hf_aruba_erm_data_rate, tvb, offset, 2, ENC_BIG_ENDIAN);
ti_data_rate = proto_tree_add_float_format(aruba_erm_tree, hf_aruba_erm_data_rate_gen,
tvb, 16, 2,
(float)data_rate / 2,
"Data Rate: %.1f Mb/s",
(float)data_rate / 2);
PROTO_ITEM_SET_GENERATED(ti_data_rate);
offset += 2;
proto_tree_add_item(aruba_erm_tree, hf_aruba_erm_channel, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(aruba_erm_tree, hf_aruba_erm_signal_strength, tvb, offset, 1, ENC_NA);
offset += 1;
return offset;
}
static void
dissect_aruba_erm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *aruba_erm_tree;
tvbuff_t *eth_tvb;
int offset = 0 ;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTO_SHORT_NAME);
col_set_str(pinfo->cinfo, COL_INFO, PROTO_SHORT_NAME);
ti = proto_tree_add_item(tree, proto_aruba_erm, tvb, 0, 0, ENC_NA);
proto_item_append_text(ti, ": %s", val_to_str(aruba_erm_type, aruba_erm_type_vals, "Unknown"));
aruba_erm_tree = proto_item_add_subtree(ti, ett_aruba_erm);
switch(aruba_erm_type){
case TYPE_PCAP:
offset = dissect_aruba_erm_pcap(tvb, pinfo, aruba_erm_tree, offset);
proto_item_set_len(ti, offset);
eth_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(ieee80211_handle, eth_tvb, pinfo, tree);
break;
case TYPE_PEEK:
call_dissector(peek_handle, tvb, pinfo, tree);
break;
case TYPE_AIRMAGNET:
proto_tree_add_expert(tree, pinfo, &ei_aruba_erm_airmagnet, tvb, offset, -1);
call_dissector(data_handle, tvb, pinfo, tree);
break;
case TYPE_PCAPPLUSRADIO:
offset = dissect_aruba_erm_pcap(tvb, pinfo, aruba_erm_tree, offset);
offset = dissect_aruba_erm_pcap_radio(tvb, pinfo, aruba_erm_tree, offset);
proto_item_set_len(ti, offset);
eth_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(ieee80211_handle, eth_tvb, pinfo, tree);
break;
case TYPE_PPI:
call_dissector(ppi_handle, tvb, pinfo, tree);
break;
default:
break;
}
}
void
proto_register_aruba_erm(void)
{
static hf_register_info hf[] = {
{ &hf_aruba_erm_time,
{ "Packet Capture Timestamp", "aruba_erm.time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL,
0x00, NULL, HFILL }},
{ &hf_aruba_erm_incl_len,
{ "Packet Captured Length", "aruba_erm.incl_len", FT_UINT32, BASE_DEC, NULL,
0x00, NULL, HFILL }},
{ &hf_aruba_erm_orig_len,
{ "Packet Length", "aruba_erm.orig_len", FT_UINT32, BASE_DEC, NULL,
0x00, NULL, HFILL }},
{ &hf_aruba_erm_data_rate,
{ "Data Rate", "aruba_erm.data_rate", FT_UINT16, BASE_DEC, NULL,
0x00, "Data rate (1/2 Mb/s)", HFILL }},
{ &hf_aruba_erm_data_rate_gen,
{ "Data Rate", "aruba_erm.data_rate_gen", FT_FLOAT, BASE_NONE, NULL,
0x00, "Data rate (1/2 Mb/s)", HFILL }},
{ &hf_aruba_erm_channel,
{ "Channel", "aruba_erm.channel", FT_UINT8, BASE_DEC, NULL,
0x00, "802.11 channel number that this frame was sent/received on", HFILL }},
{ &hf_aruba_erm_signal_strength,
{ "Signal Strength [percent]", "aruba_erm.signal_strength", FT_UINT8, BASE_DEC, NULL,
0x00, "Signal strength (Percentage)", HFILL }},
};
static gint *ett[] = {
&ett_aruba_erm,
};
static ei_register_info ei[] = {
{ &ei_aruba_erm_airmagnet, { "aruba_erm.airmagnet", PI_UNDECODED, PI_ERROR, "Airmagnet (type 2) is no yet supported (Please use other type)", EXPFILL }}
};
static const enum_val_t aruba_erm_types[] = {
{ "pcap_type_0", "pcap (type 0)", TYPE_PCAP},
{ "peek_type_1", "peek (type1)", TYPE_PEEK},
{ "airmagnet_type_2", "airmagnet (type 2)", TYPE_AIRMAGNET},
{ "pcapplusradio_type_3", "pcap+radio header (type 3)", TYPE_PCAPPLUSRADIO},
{ "ppi_type_4", "ppi (type 4)", TYPE_PPI},
{ NULL, NULL, -1}
};
module_t *aruba_erm_module;
expert_module_t* expert_aruba_erm;
proto_aruba_erm = proto_register_protocol(PROTO_LONG_NAME, PROTO_SHORT_NAME, "aruba_erm");
range_convert_str (&global_aruba_erm_port_range, "0", MAX_UDP_PORT);
aruba_erm_module = prefs_register_protocol(proto_aruba_erm, proto_reg_handoff_aruba_erm);
prefs_register_range_preference(aruba_erm_module, "udp.ports", "ARUBA_ERM UDP Port numbers",
"Set the UDP port numbers (typically the range 5555 to 5560) used for ARUBA"
" encapsulated remote mirroring frames;\n"
"0 (default) means that the ARUBA_ERM dissector is not active\n",
&global_aruba_erm_port_range, MAX_UDP_PORT);
prefs_register_enum_preference(aruba_erm_module, "type.captured",
"Type of formats for captured packets",
"Type of formats for captured packets",
&aruba_erm_type, aruba_erm_types, FALSE);
proto_register_field_array(proto_aruba_erm, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_aruba_erm = expert_register_protocol(proto_aruba_erm);
expert_register_field_array(expert_aruba_erm, ei, array_length(ei));
}
void
proto_reg_handoff_aruba_erm(void)
{
static range_t *aruba_erm_port_range;
static range_t *aruba_erm_radio_port_range;
static gboolean initialized = FALSE;
if (!initialized) {
ieee80211_handle = find_dissector("wlan_withoutfcs");
ppi_handle = find_dissector("ppi");
peek_handle = find_dissector("peekremote");
data_handle = find_dissector("data");
aruba_erm_handle = create_dissector_handle(dissect_aruba_erm, proto_aruba_erm);
initialized = TRUE;
} else {
dissector_delete_uint_range("udp.port", aruba_erm_port_range, aruba_erm_handle);
g_free(aruba_erm_port_range);
g_free(aruba_erm_radio_port_range);
}
aruba_erm_port_range = range_copy(global_aruba_erm_port_range);
dissector_add_uint_range("udp.port", aruba_erm_port_range, aruba_erm_handle);
}
