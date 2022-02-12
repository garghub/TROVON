static void
dissect_cwids(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tvbuff_t *wlan_tvb;
proto_tree *ti, *cwids_tree;
volatile int offset = 0;
guint16 capturelen;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CWIDS");
col_set_str(pinfo->cinfo, COL_INFO, "Cwids: ");
cwids_tree = NULL;
while(tvb_reported_length_remaining(tvb, offset) > 0) {
struct ieee_802_11_phdr phdr;
ti = proto_tree_add_item(tree, proto_cwids, tvb, offset, 28, ENC_NA);
cwids_tree = proto_item_add_subtree(ti, ett_cwids);
phdr.fcs_len = 0;
phdr.decrypted = FALSE;
phdr.datapad = FALSE;
phdr.phy = PHDR_802_11_PHY_UNKNOWN;
phdr.presence_flags = PHDR_802_11_HAS_CHANNEL;
proto_tree_add_item(cwids_tree, hf_cwids_version, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(cwids_tree, hf_cwids_unknown1, tvb, offset, 7, ENC_NA);
offset += 7;
phdr.channel = tvb_get_guint8(tvb, offset);
proto_tree_add_item(cwids_tree, hf_cwids_channel, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cwids_tree, hf_cwids_unknown2, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(cwids_tree, hf_cwids_reallength, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
capturelen = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(cwids_tree, hf_cwids_capturelen, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(cwids_tree, hf_cwids_unknown3, tvb, offset, 8, ENC_NA);
offset += 8;
wlan_tvb = tvb_new_subset_length(tvb, offset, capturelen);
TRY {
call_dissector_with_data(ieee80211_radio_handle, wlan_tvb, pinfo, tree, &phdr);
} CATCH_BOUNDS_ERRORS {
show_exception(wlan_tvb, pinfo, tree, EXCEPT_CODE, GET_MESSAGE);
expert_add_info(pinfo, ti, &ie_ieee80211_subpacket);
} ENDTRY;
offset += capturelen;
}
}
void
proto_register_cwids(void)
{
static hf_register_info hf[] = {
{ &hf_cwids_version,
{ "Capture Version", "cwids.version", FT_UINT16, BASE_DEC, NULL,
0x0, "Version or format of record", HFILL }},
{ &hf_cwids_unknown1,
{ "Unknown1", "cwids.unknown1", FT_BYTES, BASE_NONE, NULL,
0x0, "1st Unknown block - timestamp?", HFILL }},
{ &hf_cwids_channel,
{ "Channel", "cwids.channel", FT_UINT8, BASE_DEC, NULL,
0x0, "Channel for this capture", HFILL }},
{ &hf_cwids_unknown2,
{ "Unknown2", "cwids.unknown2", FT_BYTES, BASE_NONE, NULL,
0x0, "2nd Unknown block", HFILL }},
{ &hf_cwids_reallength,
{ "Original length", "cwids.reallen", FT_UINT16, BASE_DEC, NULL,
0x0, "Original num bytes in frame", HFILL }},
{ &hf_cwids_capturelen,
{ "Capture length", "cwids.caplen", FT_UINT16, BASE_DEC, NULL,
0x0, "Captured bytes in record", HFILL }},
{ &hf_cwids_unknown3,
{ "Unknown3", "cwids.unknown3", FT_BYTES, BASE_NONE, NULL,
0x0, "3rd Unknown block", HFILL }},
};
static gint *ett[] = {
&ett_cwids,
};
static ei_register_info ei[] = {
{ &ie_ieee80211_subpacket, { "cwids.ieee80211_malformed", PI_MALFORMED, PI_ERROR, "Malformed or short IEEE80211 subpacket", EXPFILL }},
};
module_t *cwids_module;
expert_module_t* expert_cwids;
proto_cwids = proto_register_protocol("Cisco Wireless IDS Captures", "CWIDS", "cwids");
proto_register_field_array(proto_cwids, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_cwids = expert_register_protocol(proto_cwids);
expert_register_field_array(expert_cwids, ei, array_length(ei));
cwids_module = prefs_register_protocol(proto_cwids, proto_reg_handoff_cwids);
prefs_register_uint_preference(cwids_module, "udp.port",
"CWIDS port",
"Set the destination UDP port Cisco wireless IDS messages",
10, &global_udp_port);
}
void
proto_reg_handoff_cwids(void)
{
static dissector_handle_t cwids_handle;
static guint saved_udp_port;
static gboolean initialized = FALSE;
if (!initialized) {
cwids_handle = create_dissector_handle(dissect_cwids, proto_cwids);
dissector_add_for_decode_as("udp.port", cwids_handle);
ieee80211_radio_handle = find_dissector("wlan_radio");
initialized = TRUE;
} else {
if (saved_udp_port != 0) {
dissector_delete_uint("udp.port", saved_udp_port, cwids_handle);
}
}
if (global_udp_port != 0) {
dissector_add_uint("udp.port", global_udp_port, cwids_handle);
}
saved_udp_port = global_udp_port;
}
