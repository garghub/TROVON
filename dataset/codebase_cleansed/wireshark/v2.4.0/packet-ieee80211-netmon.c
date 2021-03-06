static int
dissect_netmon_802_11(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
struct ieee_802_11_phdr *phdr = (struct ieee_802_11_phdr *)data;
proto_tree *wlan_tree = NULL, *opmode_tree;
proto_item *ti;
tvbuff_t *next_tvb;
int offset;
guint8 version;
guint16 length;
guint32 phy_type;
guint32 flags;
guint32 channel;
gint calc_channel;
gint32 rssi;
guint8 rate;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "WLAN");
col_clear(pinfo->cinfo, COL_INFO);
offset = 0;
version = tvb_get_guint8(tvb, offset);
length = tvb_get_letohs(tvb, offset+1);
col_add_fstr(pinfo->cinfo, COL_INFO, "NetMon WLAN Capture v%u, Length %u",
version, length);
if (version != 2) {
goto skip;
}
if (length < MIN_HEADER_LEN) {
goto skip;
}
ti = proto_tree_add_item(tree, proto_netmon_802_11, tvb, 0, length,
ENC_NA);
wlan_tree = proto_item_add_subtree(ti, ett_netmon_802_11);
proto_tree_add_item(wlan_tree, hf_netmon_802_11_version, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(wlan_tree, hf_netmon_802_11_length, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
offset += 2;
ti = proto_tree_add_item(wlan_tree, hf_netmon_802_11_op_mode, tvb, offset,
4, ENC_LITTLE_ENDIAN);
opmode_tree = proto_item_add_subtree(ti, ett_netmon_802_11_op_mode);
proto_tree_add_item(opmode_tree, hf_netmon_802_11_op_mode_sta, tvb, offset,
4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(opmode_tree, hf_netmon_802_11_op_mode_ap, tvb, offset,
4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(opmode_tree, hf_netmon_802_11_op_mode_sta_ext, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(opmode_tree, hf_netmon_802_11_op_mode_mon, tvb, offset,
4, ENC_LITTLE_ENDIAN);
offset += 4;
flags = tvb_get_letohl(tvb, offset);
offset += 4;
if (flags != 0xffffffff) {
phy_type = tvb_get_letohl(tvb, offset);
memset(&phdr->phy_info, 0, sizeof(phdr->phy_info));
switch (phy_type) {
case PHY_TYPE_UNKNOWN:
phdr->phy = PHDR_802_11_PHY_UNKNOWN;
break;
case PHY_TYPE_FHSS:
phdr->phy = PHDR_802_11_PHY_11_FHSS;
break;
case PHY_TYPE_IR_BASEBAND:
phdr->phy = PHDR_802_11_PHY_11_IR;
break;
case PHY_TYPE_DSSS:
phdr->phy = PHDR_802_11_PHY_11_DSSS;
break;
case PHY_TYPE_HR_DSSS:
phdr->phy = PHDR_802_11_PHY_11B;
break;
case PHY_TYPE_OFDM:
phdr->phy = PHDR_802_11_PHY_11A;
break;
case PHY_TYPE_ERP:
phdr->phy = PHDR_802_11_PHY_11G;
break;
case PHY_TYPE_HT:
phdr->phy = PHDR_802_11_PHY_11N;
break;
case PHY_TYPE_VHT:
phdr->phy = PHDR_802_11_PHY_11AC;
break;
default:
phdr->phy = PHDR_802_11_PHY_UNKNOWN;
break;
}
proto_tree_add_item(wlan_tree, hf_netmon_802_11_phy_type, tvb, offset, 4,
ENC_LITTLE_ENDIAN);
offset += 4;
channel = tvb_get_letohl(tvb, offset);
if (channel < 1000) {
if (channel == 0) {
proto_tree_add_uint_format_value(wlan_tree, hf_netmon_802_11_channel,
tvb, offset, 4, channel,
"Unknown");
} else {
guint frequency;
phdr->has_channel = TRUE;
phdr->channel = channel;
proto_tree_add_uint(wlan_tree, hf_netmon_802_11_channel,
tvb, offset, 4, channel);
switch (phdr->phy) {
case PHDR_802_11_PHY_11B:
case PHDR_802_11_PHY_11G:
frequency = ieee80211_chan_to_mhz(channel, TRUE);
break;
case PHDR_802_11_PHY_11A:
frequency = ieee80211_chan_to_mhz(channel, FALSE);
break;
default:
frequency = 0;
break;
}
if (frequency != 0) {
phdr->has_frequency = TRUE;
phdr->frequency = frequency;
}
}
} else {
phdr->has_frequency = TRUE;
phdr->frequency = channel;
proto_tree_add_uint(wlan_tree, hf_netmon_802_11_frequency,
tvb, offset, 4, channel);
calc_channel = ieee80211_mhz_to_chan(channel);
if (calc_channel != -1) {
phdr->has_channel = TRUE;
phdr->channel = calc_channel;
}
}
offset += 4;
rssi = tvb_get_letohl(tvb, offset);
if (rssi == 0) {
proto_tree_add_int_format_value(wlan_tree, hf_netmon_802_11_rssi,
tvb, offset, 4, rssi,
"Unknown");
} else {
phdr->has_signal_dbm = TRUE;
phdr->signal_dbm = rssi;
proto_tree_add_int_format_value(wlan_tree, hf_netmon_802_11_rssi,
tvb, offset, 4, rssi,
"%d dBm", rssi);
}
offset += 4;
rate = tvb_get_guint8(tvb, offset);
if (rate == 0) {
proto_tree_add_uint_format_value(wlan_tree, hf_netmon_802_11_datarate,
tvb, offset, 1, rate,
"Unknown");
} else {
phdr->has_data_rate = TRUE;
phdr->data_rate = rate;
proto_tree_add_uint_format_value(wlan_tree, hf_netmon_802_11_datarate,
tvb, offset, 1, rate,
"%f Mb/s", rate*.5);
}
offset += 1;
} else
offset += 13;
phdr->has_tsf_timestamp = TRUE;
phdr->tsf_timestamp = tvb_get_letoh64(tvb, offset);
proto_tree_add_item(wlan_tree, hf_netmon_802_11_timestamp, tvb, offset, 8,
ENC_LITTLE_ENDIAN);
skip:
offset = length;
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector_with_data(ieee80211_radio_handle, next_tvb, pinfo, tree, phdr);
return offset;
}
void
proto_register_netmon_802_11(void)
{
static const value_string phy_type[] = {
{ PHY_TYPE_UNKNOWN, "Unknown" },
{ PHY_TYPE_FHSS, "802.11 FHSS" },
{ PHY_TYPE_DSSS, "802.11 DSSS" },
{ PHY_TYPE_IR_BASEBAND, "802.11 IR" },
{ PHY_TYPE_OFDM, "802.11a" },
{ PHY_TYPE_HR_DSSS, "802.11b" },
{ PHY_TYPE_ERP, "802.11g" },
{ PHY_TYPE_HT, "802.11n" },
{ PHY_TYPE_VHT, "802.11ac" },
{ 0, NULL },
};
static hf_register_info hf[] = {
{ &hf_netmon_802_11_version, { "Header revision", "netmon_802_11.version", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_netmon_802_11_length, { "Header length", "netmon_802_11.length", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_netmon_802_11_op_mode, { "Operation mode", "netmon_802_11.op_mode", FT_UINT32,
BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_netmon_802_11_op_mode_sta, { "Station mode", "netmon_802_11.op_mode.sta", FT_UINT32,
BASE_HEX, NULL, OP_MODE_STA, NULL, HFILL } },
{ &hf_netmon_802_11_op_mode_ap, { "AP mode", "netmon_802_11.op_mode.ap", FT_UINT32,
BASE_HEX, NULL, OP_MODE_AP, NULL, HFILL } },
{ &hf_netmon_802_11_op_mode_sta_ext, { "Extensible station mode", "netmon_802_11.op_mode.sta_ext", FT_UINT32,
BASE_HEX, NULL, OP_MODE_STA_EXT, NULL, HFILL } },
{ &hf_netmon_802_11_op_mode_mon, { "Monitor mode", "netmon_802_11.op_mode.on", FT_UINT32,
BASE_HEX, NULL, OP_MODE_MON, NULL, HFILL } },
#if 0
{ &hf_netmon_802_11_flags, { "Flags", "netmon_802_11.flags", FT_UINT32,
BASE_HEX, NULL, 0x0, NULL, HFILL } },
#endif
{ &hf_netmon_802_11_phy_type, { "PHY type", "netmon_802_11.phy_type", FT_UINT32,
BASE_DEC, VALS(phy_type), 0x0, NULL, HFILL } },
{ &hf_netmon_802_11_channel, { "Channel", "netmon_802_11.channel", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_netmon_802_11_frequency, { "Center frequency", "netmon_802_11.frequency", FT_UINT32,
BASE_DEC|BASE_UNIT_STRING, &units_mhz, 0x0, NULL, HFILL } },
{ &hf_netmon_802_11_rssi, { "RSSI", "netmon_802_11.rssi", FT_INT32,
BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_netmon_802_11_datarate, { "Data rate", "netmon_802_11.datarate", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_netmon_802_11_timestamp, { "Timestamp", "netmon_802_11.timestamp", FT_UINT64,
BASE_DEC, NULL, 0x0, NULL, HFILL } },
};
static gint *ett[] = {
&ett_netmon_802_11,
&ett_netmon_802_11_op_mode
};
proto_netmon_802_11 = proto_register_protocol("NetMon 802.11 capture header",
"NetMon 802.11",
"netmon_802_11");
proto_register_field_array(proto_netmon_802_11, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_netmon_802_11(void)
{
dissector_handle_t netmon_802_11_handle;
ieee80211_radio_handle = find_dissector_add_dependency("wlan_radio", proto_netmon_802_11);
netmon_802_11_handle = create_dissector_handle(dissect_netmon_802_11,
proto_netmon_802_11);
dissector_add_uint("wtap_encap", WTAP_ENCAP_IEEE_802_11_NETMON, netmon_802_11_handle);
}
