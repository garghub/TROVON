static int
dissect_cwids(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
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
memset(&phdr, 0, sizeof(phdr));
phdr.fcs_len = 0;
phdr.decrypted = FALSE;
phdr.datapad = FALSE;
phdr.phy = PHDR_802_11_PHY_UNKNOWN;
proto_tree_add_item(cwids_tree, hf_cwids_version, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(cwids_tree, hf_cwids_timestamp, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(cwids_tree, hf_cwids_unknown1, tvb, offset, 1, ENC_NA);
offset += 1;
phdr.has_channel = TRUE;
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
return tvb_captured_length(tvb);
}
void
proto_register_cwids(void)
{
static hf_register_info hf[] = {
{ &hf_cwids_version,
{ "Capture Version", "cwids.version", FT_UINT16, BASE_DEC, NULL,
0x0, "Version or format of record", HFILL }},
{ &hf_cwids_timestamp,
{ "Timestamp [us]", "cwids.timestamp", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_cwids_unknown1,
{ "Unknown1", "cwids.unknown1", FT_BYTES, BASE_NONE, NULL,
0x0, "1st Unknown block", HFILL }},
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
expert_module_t* expert_cwids;
proto_cwids = proto_register_protocol("Cisco Wireless IDS Captures", "CWIDS", "cwids");
proto_register_field_array(proto_cwids, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_cwids = expert_register_protocol(proto_cwids);
expert_register_field_array(expert_cwids, ei, array_length(ei));
}
void
proto_reg_handoff_cwids(void)
{
dissector_handle_t cwids_handle;
cwids_handle = create_dissector_handle(dissect_cwids, proto_cwids);
dissector_add_for_decode_as_with_preference("udp.port", cwids_handle);
ieee80211_radio_handle = find_dissector_add_dependency("wlan_noqos_radio", proto_cwids);
}
