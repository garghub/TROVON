void
capture_wlancap(const guchar *pd, int offset, int len, packet_counts *ld)
{
guint32 length;
if (!BYTES_ARE_IN_FRAME(offset, len, sizeof(guint32)*2)) {
ld->other++;
return;
}
length = pntoh32(pd+sizeof(guint32));
if (!BYTES_ARE_IN_FRAME(offset, len, length)) {
ld->other++;
return;
}
offset += length;
capture_ieee80211(pd, offset, len, ld);
}
static void
dissect_wlancap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *wlan_tree = NULL;
proto_item *ti;
tvbuff_t *next_tvb;
int offset;
guint32 version;
guint32 length;
guint32 channel;
guint frequency;
gint calc_channel;
guint32 datarate;
guint32 ssi_type;
gint32 dbm;
guint32 antnoise;
struct ieee_802_11_phdr phdr;
phdr.fcs_len = -1;
phdr.decrypted = FALSE;
phdr.datapad = FALSE;
phdr.phy = PHDR_802_11_PHY_UNKNOWN;
phdr.presence_flags = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "WLAN");
col_clear(pinfo->cinfo, COL_INFO);
offset = 0;
version = tvb_get_ntohl(tvb, offset) - WLANCAP_MAGIC_COOKIE_BASE;
length = tvb_get_ntohl(tvb, offset+4);
col_add_fstr(pinfo->cinfo, COL_INFO, "AVS WLAN Capture v%x, Length %d",version, length);
if (version > 2) {
goto skip;
}
if (tree) {
ti = proto_tree_add_item(tree, proto_wlancap, tvb, 0, length, ENC_NA);
wlan_tree = proto_item_add_subtree(ti, ett_wlancap);
proto_tree_add_item(wlan_tree, hf_wlancap_magic, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(wlan_tree, hf_wlancap_version, tvb, offset, 4, ENC_BIG_ENDIAN);
}
offset+=4;
if (tree)
proto_tree_add_item(wlan_tree, hf_wlancap_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
phdr.presence_flags |= PHDR_802_11_HAS_TSF_TIMESTAMP;
phdr.tsf_timestamp = tvb_get_ntoh64(tvb, offset);
if (tree)
proto_tree_add_item(wlan_tree, hf_wlancap_mactime, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
if (tree)
proto_tree_add_item(wlan_tree, hf_wlancap_hosttime, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
switch (tvb_get_ntohl(tvb, offset)) {
case 1:
phdr.phy = PHDR_802_11_PHY_11_FHSS;
phdr.phy_info.info_11_fhss.presence_flags = 0;
break;
case 2:
phdr.phy = PHDR_802_11_PHY_11_DSSS;
break;
case 3:
phdr.phy = PHDR_802_11_PHY_11_IR;
break;
case 4:
phdr.phy = PHDR_802_11_PHY_11B;
phdr.phy_info.info_11b.presence_flags = 0;
break;
case 5:
phdr.phy = PHDR_802_11_PHY_11B;
phdr.phy_info.info_11b.presence_flags = 0;
break;
case 6:
phdr.phy = PHDR_802_11_PHY_11G;
phdr.phy_info.info_11g.presence_flags = 0;
break;
case 7:
phdr.phy = PHDR_802_11_PHY_11A;
phdr.phy_info.info_11a.presence_flags = 0;
break;
case 8:
phdr.phy = PHDR_802_11_PHY_11A;
phdr.phy_info.info_11a.presence_flags = 0;
break;
case 9:
phdr.phy = PHDR_802_11_PHY_11G;
phdr.phy_info.info_11g.presence_flags = 0;
break;
}
if (tree)
proto_tree_add_item(wlan_tree, hf_wlancap_phytype, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
if (phdr.phy == PHDR_802_11_PHY_11_FHSS) {
phdr.phy_info.info_11_fhss.presence_flags =
PHDR_802_11_FHSS_HAS_HOP_SET |
PHDR_802_11_FHSS_HAS_HOP_PATTERN |
PHDR_802_11_FHSS_HAS_HOP_INDEX;
phdr.phy_info.info_11_fhss.hop_set = tvb_get_guint8(tvb, offset);
if (tree)
proto_tree_add_item(wlan_tree, hf_wlancap_hop_set, tvb, offset, 1, ENC_NA);
phdr.phy_info.info_11_fhss.hop_pattern = tvb_get_guint8(tvb, offset + 1);
if (tree)
proto_tree_add_item(wlan_tree, hf_wlancap_hop_pattern, tvb, offset + 1, 1, ENC_NA);
phdr.phy_info.info_11_fhss.hop_index = tvb_get_guint8(tvb, offset + 2);
if (tree)
proto_tree_add_item(wlan_tree, hf_wlancap_hop_index, tvb, offset + 2, 1, ENC_NA);
} else {
channel = tvb_get_ntohl(tvb, offset);
if (channel < 256) {
col_add_fstr(pinfo->cinfo, COL_FREQ_CHAN, "%u", channel);
phdr.presence_flags |= PHDR_802_11_HAS_CHANNEL;
phdr.channel = channel;
if (tree)
proto_tree_add_uint(wlan_tree, hf_wlancap_channel, tvb, offset, 4, channel);
frequency = ieee80211_chan_to_mhz(channel, (phdr.phy != PHDR_802_11_PHY_11A));
if (frequency != 0) {
phdr.presence_flags |= PHDR_802_11_HAS_FREQUENCY;
phdr.frequency = frequency;
}
} else if (channel < 10000) {
col_add_fstr(pinfo->cinfo, COL_FREQ_CHAN, "%u MHz", channel);
phdr.presence_flags |= PHDR_802_11_HAS_FREQUENCY;
phdr.frequency = channel;
if (tree)
proto_tree_add_uint_format(wlan_tree, hf_wlancap_channel_frequency, tvb, offset,
4, channel, "Frequency: %u MHz", channel);
calc_channel = ieee80211_mhz_to_chan(channel);
if (calc_channel != -1) {
phdr.presence_flags |= PHDR_802_11_HAS_CHANNEL;
phdr.channel = calc_channel;
}
} else {
col_add_fstr(pinfo->cinfo, COL_FREQ_CHAN, "%u KHz", channel);
if (tree)
proto_tree_add_uint_format(wlan_tree, hf_wlancap_channel_frequency, tvb, offset,
4, channel, "Frequency: %u KHz", channel);
}
}
offset+=4;
datarate = tvb_get_ntohl(tvb, offset);
if (datarate < 100000) {
datarate *= 100000;
}
col_add_fstr(pinfo->cinfo, COL_TX_RATE, "%u.%u",
datarate / 1000000,
((datarate % 1000000) > 500000) ? 5 : 0);
if (datarate != 0) {
if ((datarate % 500000) == 0) {
phdr.presence_flags |= PHDR_802_11_HAS_DATA_RATE;
phdr.data_rate = datarate / 500000;
}
}
if (tree) {
proto_tree_add_uint64_format_value(wlan_tree, hf_wlancap_data_rate, tvb, offset, 4,
datarate,
"%u.%u Mb/s",
datarate/1000000,
((datarate % 1000000) > 500000) ? 5 : 0);
}
offset+=4;
if (tree)
proto_tree_add_item(wlan_tree, hf_wlancap_antenna, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
if (tree)
proto_tree_add_item(wlan_tree, hf_wlancap_priority, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
ssi_type = tvb_get_ntohl(tvb, offset);
if (tree)
proto_tree_add_uint(wlan_tree, hf_wlancap_ssi_type, tvb, offset, 4, ssi_type);
offset+=4;
switch (ssi_type) {
case SSI_NONE:
default:
break;
case SSI_NORM_RSSI:
col_add_fstr(pinfo->cinfo, COL_RSSI, "%u (norm)", tvb_get_ntohl(tvb, offset));
if (tree)
proto_tree_add_item(wlan_tree, hf_wlancap_normrssi_antsignal, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case SSI_DBM:
dbm = tvb_get_ntohl(tvb, offset);
phdr.presence_flags |= PHDR_802_11_HAS_SIGNAL_DBM;
phdr.signal_dbm = dbm;
col_add_fstr(pinfo->cinfo, COL_RSSI, "%d dBm", dbm);
if (tree)
proto_tree_add_item(wlan_tree, hf_wlancap_dbm_antsignal, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case SSI_RAW_RSSI:
col_add_fstr(pinfo->cinfo, COL_RSSI, "%u (raw)", tvb_get_ntohl(tvb, offset));
if (tree)
proto_tree_add_item(wlan_tree, hf_wlancap_rawrssi_antsignal, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
}
offset+=4;
antnoise = tvb_get_ntohl(tvb, offset);
if (antnoise != 0xffffffff) {
switch (ssi_type) {
case SSI_NONE:
default:
break;
case SSI_NORM_RSSI:
if (tree)
proto_tree_add_uint(wlan_tree, hf_wlancap_normrssi_antnoise, tvb, offset, 4, antnoise);
break;
case SSI_DBM:
if (antnoise != 0) {
phdr.presence_flags |= PHDR_802_11_HAS_NOISE_DBM;
phdr.noise_dbm = antnoise;
}
if (tree)
proto_tree_add_int(wlan_tree, hf_wlancap_dbm_antnoise, tvb, offset, 4, antnoise);
break;
case SSI_RAW_RSSI:
if (tree)
proto_tree_add_uint(wlan_tree, hf_wlancap_rawrssi_antnoise, tvb, offset, 4, antnoise);
break;
}
}
offset+=4;
switch (tvb_get_ntohl(tvb, offset)) {
case 0:
break;
case 1:
switch (phdr.phy) {
case PHDR_802_11_PHY_11B:
phdr.phy_info.info_11b.presence_flags |= PHDR_802_11B_HAS_SHORT_PREAMBLE;
phdr.phy_info.info_11b.short_preamble = TRUE;
break;
case PHDR_802_11_PHY_11G:
phdr.phy_info.info_11g.presence_flags |= PHDR_802_11G_HAS_SHORT_PREAMBLE;
phdr.phy_info.info_11g.short_preamble = TRUE;
break;
}
break;
case 2:
switch (phdr.phy) {
case PHDR_802_11_PHY_11B:
phdr.phy_info.info_11b.presence_flags |= PHDR_802_11B_HAS_SHORT_PREAMBLE;
phdr.phy_info.info_11b.short_preamble = FALSE;
break;
case PHDR_802_11_PHY_11G:
phdr.phy_info.info_11g.presence_flags |= PHDR_802_11G_HAS_SHORT_PREAMBLE;
phdr.phy_info.info_11g.short_preamble = FALSE;
break;
}
break;
default:
break;
}
if (tree)
proto_tree_add_item(wlan_tree, hf_wlancap_preamble, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
if (tree)
proto_tree_add_item(wlan_tree, hf_wlancap_encoding, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
if (version > 1) {
if (tree)
proto_tree_add_item(wlan_tree, hf_wlancap_sequence, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
if (tree)
proto_tree_add_item(wlan_tree, hf_wlancap_drops, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
if (tree)
proto_tree_add_item(wlan_tree, hf_wlancap_receiver_addr, tvb, offset, 6, ENC_NA);
offset+=6;
if (tree)
proto_tree_add_item(wlan_tree, hf_wlancap_padding, tvb, offset, 2, ENC_NA);
}
skip:
offset = length;
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector_with_data(ieee80211_radio_handle, next_tvb, pinfo, tree, (void *)&phdr);
}
void proto_register_ieee80211_wlancap(void)
{
proto_wlancap = proto_register_protocol("AVS WLAN Capture header",
"AVS WLANCAP", "wlancap");
proto_register_field_array(proto_wlancap, hf_wlancap,
array_length(hf_wlancap));
register_dissector("wlancap", dissect_wlancap, proto_wlancap);
wlancap_handle = create_dissector_handle(dissect_wlancap, proto_wlancap);
dissector_add_uint("wtap_encap", WTAP_ENCAP_IEEE_802_11_AVS,
wlancap_handle);
proto_register_subtree_array(tree_array, array_length(tree_array));
}
void proto_reg_handoff_ieee80211_wlancap(void)
{
ieee80211_radio_handle = find_dissector("wlan_radio");
}
