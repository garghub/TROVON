void
capture_wlancap(const guchar *pd, int offset, int len, packet_counts *ld)
{
guint32 length;
if (!BYTES_ARE_IN_FRAME(offset, len, sizeof(guint32)*2)) {
ld->other++;
return;
}
length = pntohl(pd+sizeof(guint32));
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
guint32 datarate;
guint32 ssi_type;
guint32 antnoise;
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
wlan_tree = proto_item_add_subtree(ti, ett_radio);
proto_tree_add_item(wlan_tree, hf_wlan_magic, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(wlan_tree, hf_wlan_version, tvb, offset, 4, ENC_BIG_ENDIAN);
}
offset+=4;
if (tree)
proto_tree_add_item(wlan_tree, hf_wlan_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
if (tree)
proto_tree_add_item(wlan_tree, hf_mactime, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
if (tree)
proto_tree_add_item(wlan_tree, hf_hosttime, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
if (tree)
proto_tree_add_item(wlan_tree, hf_wlan_phytype, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
channel = tvb_get_ntohl(tvb, offset);
if (channel < 256) {
col_add_fstr(pinfo->cinfo, COL_FREQ_CHAN, "%u", channel);
if (tree)
proto_tree_add_uint(wlan_tree, hf_channel, tvb, offset, 4, channel);
} else if (channel < 10000) {
col_add_fstr(pinfo->cinfo, COL_FREQ_CHAN, "%u MHz", channel);
if (tree)
proto_tree_add_uint_format(wlan_tree, hf_channel_frequency, tvb, offset,
4, channel, "Frequency: %u MHz", channel);
} else {
col_add_fstr(pinfo->cinfo, COL_FREQ_CHAN, "%u KHz", channel);
if (tree)
proto_tree_add_uint_format(wlan_tree, hf_channel_frequency, tvb, offset,
4, channel, "Frequency: %u KHz", channel);
}
offset+=4;
datarate = tvb_get_ntohl(tvb, offset);
if (datarate < 100000) {
datarate *= 100000;
}
col_add_fstr(pinfo->cinfo, COL_TX_RATE, "%u.%u",
datarate / 1000000,
((datarate % 1000000) > 500000) ? 5 : 0);
if (tree) {
proto_tree_add_uint64_format(wlan_tree, hf_data_rate, tvb, offset, 4,
datarate,
"Data Rate: %u.%u Mb/s",
datarate/1000000,
((datarate % 1000000) > 500000) ? 5 : 0);
}
offset+=4;
if (tree)
proto_tree_add_item(wlan_tree, hf_wlan_antenna, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
if (tree)
proto_tree_add_item(wlan_tree, hf_wlan_priority, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
ssi_type = tvb_get_ntohl(tvb, offset);
if (tree)
proto_tree_add_uint(wlan_tree, hf_wlan_ssi_type, tvb, offset, 4, ssi_type);
offset+=4;
switch (ssi_type) {
case SSI_NONE:
default:
break;
case SSI_NORM_RSSI:
col_add_fstr(pinfo->cinfo, COL_RSSI, "%u (norm)", tvb_get_ntohl(tvb, offset));
if (tree)
proto_tree_add_item(wlan_tree, hf_normrssi_antsignal, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case SSI_DBM:
col_add_fstr(pinfo->cinfo, COL_RSSI, "%d dBm", tvb_get_ntohl(tvb, offset));
if (tree)
proto_tree_add_item(wlan_tree, hf_dbm_antsignal, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case SSI_RAW_RSSI:
col_add_fstr(pinfo->cinfo, COL_RSSI, "%u (raw)", tvb_get_ntohl(tvb, offset));
if (tree)
proto_tree_add_item(wlan_tree, hf_rawrssi_antsignal, tvb, offset, 4, ENC_BIG_ENDIAN);
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
proto_tree_add_uint(wlan_tree, hf_normrssi_antnoise, tvb, offset, 4, antnoise);
break;
case SSI_DBM:
if (tree)
proto_tree_add_int(wlan_tree, hf_dbm_antnoise, tvb, offset, 4, antnoise);
break;
case SSI_RAW_RSSI:
if (tree)
proto_tree_add_uint(wlan_tree, hf_rawrssi_antnoise, tvb, offset, 4, antnoise);
break;
}
}
offset+=4;
if (tree)
proto_tree_add_item(wlan_tree, hf_wlan_preamble, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
if (tree)
proto_tree_add_item(wlan_tree, hf_wlan_encoding, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
if (version > 1) {
if (tree)
proto_tree_add_item(wlan_tree, hf_wlan_sequence, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
if (tree)
proto_tree_add_item(wlan_tree, hf_wlan_drops, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
if (tree)
proto_tree_add_item(wlan_tree, hf_wlan_receiver_addr, tvb, offset, 6, ENC_NA);
offset+=6;
if (tree)
proto_tree_add_item(wlan_tree, hf_wlan_padding, tvb, offset, 2, ENC_NA);
offset+=2;
}
skip:
offset = length;
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(ieee80211_handle, next_tvb, pinfo, tree);
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
ieee80211_handle = find_dissector("wlan");
}
