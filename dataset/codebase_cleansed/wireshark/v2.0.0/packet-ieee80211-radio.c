static int
dissect_wlan_radio (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void *data)
{
struct ieee_802_11_phdr *phdr = (struct ieee_802_11_phdr *)data;
proto_item *ti = NULL;
proto_tree *radio_tree = NULL;
float data_rate = 0.0f;
gboolean have_data_rate = FALSE;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Radio");
col_clear(pinfo->cinfo, COL_INFO);
if (phdr->presence_flags & PHDR_802_11_HAS_DATA_RATE) {
data_rate = phdr->data_rate * 0.5f;
have_data_rate = TRUE;
}
if (phdr->presence_flags & PHDR_802_11_HAS_SIGNAL_DBM) {
col_add_fstr(pinfo->cinfo, COL_RSSI, "%u dBm", phdr->signal_dbm);
} else if (phdr->presence_flags & PHDR_802_11_HAS_SIGNAL_PERCENT) {
col_add_fstr(pinfo->cinfo, COL_RSSI, "%u%%", phdr->signal_percent);
}
if (tree) {
ti = proto_tree_add_item(tree, proto_wlan_radio, tvb, 0, 0, ENC_NA);
radio_tree = proto_item_add_subtree (ti, ett_wlan_radio);
if (phdr->phy != PHDR_802_11_PHY_UNKNOWN) {
proto_tree_add_uint(radio_tree, hf_wlan_radio_phy, tvb, 0, 0,
phdr->phy);
switch (phdr->phy) {
case PHDR_802_11_PHY_11_FHSS:
if (phdr->phy_info.info_11_fhss.presence_flags & PHDR_802_11_FHSS_HAS_HOP_SET) {
proto_tree_add_uint(radio_tree, hf_wlan_radio_11_fhss_hop_set, tvb, 0, 0,
phdr->phy_info.info_11_fhss.hop_set);
}
if (phdr->phy_info.info_11_fhss.presence_flags & PHDR_802_11_FHSS_HAS_HOP_PATTERN) {
proto_tree_add_uint(radio_tree, hf_wlan_radio_11_fhss_hop_pattern, tvb, 0, 0,
phdr->phy_info.info_11_fhss.hop_pattern);
}
if (phdr->phy_info.info_11_fhss.presence_flags & PHDR_802_11_FHSS_HAS_HOP_INDEX) {
proto_tree_add_uint(radio_tree, hf_wlan_radio_11_fhss_hop_index, tvb, 0, 0,
phdr->phy_info.info_11_fhss.hop_index);
}
break;
case PHDR_802_11_PHY_11B:
if (phdr->phy_info.info_11b.presence_flags & PHDR_802_11B_HAS_SHORT_PREAMBLE) {
proto_tree_add_boolean(radio_tree, hf_wlan_radio_short_preamble, tvb, 0, 0,
phdr->phy_info.info_11b.short_preamble);
}
break;
case PHDR_802_11_PHY_11A:
if (phdr->phy_info.info_11a.presence_flags & PHDR_802_11A_HAS_CHANNEL_TYPE) {
proto_tree_add_uint(radio_tree, hf_wlan_radio_11a_channel_type, tvb, 0, 0,
phdr->phy_info.info_11a.channel_type);
}
if (phdr->phy_info.info_11a.presence_flags & PHDR_802_11A_HAS_TURBO_TYPE) {
proto_tree_add_uint(radio_tree, hf_wlan_radio_11a_turbo_type, tvb, 0, 0,
phdr->phy_info.info_11a.turbo_type);
}
break;
case PHDR_802_11_PHY_11G:
if (phdr->phy_info.info_11g.presence_flags & PHDR_802_11G_HAS_SHORT_PREAMBLE) {
proto_tree_add_boolean(radio_tree, hf_wlan_radio_short_preamble, tvb, 0, 0,
phdr->phy_info.info_11g.short_preamble);
}
if (phdr->phy_info.info_11g.presence_flags & PHDR_802_11G_HAS_MODE) {
proto_tree_add_uint(radio_tree, hf_wlan_radio_11g_mode, tvb, 0, 0,
phdr->phy_info.info_11g.mode);
}
break;
case PHDR_802_11_PHY_11N:
{
guint bandwidth_40;
if (phdr->phy_info.info_11n.presence_flags & PHDR_802_11N_HAS_MCS_INDEX) {
proto_tree_add_uint(radio_tree, hf_wlan_radio_11n_mcs_index, tvb, 0, 0,
phdr->phy_info.info_11n.mcs_index);
}
if (phdr->phy_info.info_11n.presence_flags & PHDR_802_11N_HAS_BANDWIDTH) {
proto_tree_add_uint(radio_tree, hf_wlan_radio_11n_bandwidth, tvb, 0, 0,
phdr->phy_info.info_11n.bandwidth);
}
if (phdr->phy_info.info_11n.presence_flags & PHDR_802_11N_HAS_SHORT_GI) {
proto_tree_add_boolean(radio_tree, hf_wlan_radio_11n_short_gi, tvb, 0, 0,
phdr->phy_info.info_11n.short_gi);
}
if (phdr->phy_info.info_11n.presence_flags & PHDR_802_11N_HAS_GREENFIELD) {
proto_tree_add_boolean(radio_tree, hf_wlan_radio_11n_greenfield, tvb, 0, 0,
phdr->phy_info.info_11n.greenfield);
}
if (phdr->phy_info.info_11n.presence_flags & PHDR_802_11N_HAS_FEC) {
proto_tree_add_uint(radio_tree, hf_wlan_radio_11n_fec, tvb, 0, 0,
phdr->phy_info.info_11n.fec);
}
if (phdr->phy_info.info_11n.presence_flags & PHDR_802_11N_HAS_STBC_STREAMS) {
proto_tree_add_uint(radio_tree, hf_wlan_radio_11n_stbc_streams, tvb, 0, 0,
phdr->phy_info.info_11n.stbc_streams);
}
if (phdr->phy_info.info_11n.presence_flags & PHDR_802_11N_HAS_NESS) {
proto_tree_add_uint(radio_tree, hf_wlan_radio_11n_ness, tvb, 0, 0,
phdr->phy_info.info_11n.ness);
}
#define PHDR_802_11N_ALL_FIELDS_FOR_DATARATE \
(PHDR_802_11N_HAS_MCS_INDEX | \
PHDR_802_11N_HAS_BANDWIDTH | \
PHDR_802_11N_HAS_SHORT_GI)
if ((phdr->phy_info.info_11n.presence_flags & PHDR_802_11N_ALL_FIELDS_FOR_DATARATE) == PHDR_802_11N_ALL_FIELDS_FOR_DATARATE) {
bandwidth_40 =
(phdr->phy_info.info_11n.bandwidth == PHDR_802_11_BANDWIDTH_40_MHZ) ?
1 : 0;
if (phdr->phy_info.info_11n.mcs_index < MAX_MCS_INDEX) {
data_rate = ieee80211_float_htrates[phdr->phy_info.info_11n.mcs_index][bandwidth_40][phdr->phy_info.info_11n.short_gi];
have_data_rate = TRUE;
}
}
}
break;
case PHDR_802_11_PHY_11AC:
{
gboolean can_calculate_rate;
guint bandwidth = 0;
guint i;
if (phdr->phy_info.info_11ac.presence_flags & PHDR_802_11AC_HAS_STBC) {
proto_tree_add_boolean(radio_tree, hf_wlan_radio_11ac_stbc, tvb, 0, 0,
phdr->phy_info.info_11ac.stbc);
}
if (phdr->phy_info.info_11ac.presence_flags & PHDR_802_11AC_HAS_TXOP_PS_NOT_ALLOWED) {
proto_tree_add_boolean(radio_tree, hf_wlan_radio_11ac_txop_ps_not_allowed, tvb, 0, 0,
phdr->phy_info.info_11ac.txop_ps_not_allowed);
}
if (phdr->phy_info.info_11ac.presence_flags & PHDR_802_11AC_HAS_SHORT_GI) {
can_calculate_rate = TRUE;
proto_tree_add_boolean(radio_tree, hf_wlan_radio_11ac_short_gi, tvb, 0, 0,
phdr->phy_info.info_11ac.short_gi);
} else {
can_calculate_rate = FALSE;
}
if (phdr->phy_info.info_11ac.presence_flags & PHDR_802_11AC_HAS_SHORT_GI_NSYM_DISAMBIG) {
proto_tree_add_boolean(radio_tree, hf_wlan_radio_11ac_short_gi_nsym_disambig, tvb, 0, 0,
phdr->phy_info.info_11ac.short_gi_nsym_disambig);
}
if (phdr->phy_info.info_11ac.presence_flags & PHDR_802_11AC_HAS_LDPC_EXTRA_OFDM_SYMBOL) {
proto_tree_add_boolean(radio_tree, hf_wlan_radio_11ac_ldpc_extra_ofdm_symbol, tvb, 0, 0,
phdr->phy_info.info_11ac.ldpc_extra_ofdm_symbol);
}
if (phdr->phy_info.info_11ac.presence_flags & PHDR_802_11AC_HAS_BEAMFORMED) {
proto_tree_add_boolean(radio_tree, hf_wlan_radio_11ac_beamformed, tvb, 0, 0,
phdr->phy_info.info_11ac.beamformed);
}
if (phdr->phy_info.info_11ac.presence_flags & PHDR_802_11AC_HAS_BANDWIDTH) {
if (phdr->phy_info.info_11ac.bandwidth < G_N_ELEMENTS(ieee80211_vht_bw2rate_index))
bandwidth = ieee80211_vht_bw2rate_index[phdr->phy_info.info_11ac.bandwidth];
else
can_calculate_rate = FALSE;
proto_tree_add_uint(radio_tree, hf_wlan_radio_11ac_bandwidth, tvb, 0, 0,
phdr->phy_info.info_11ac.bandwidth);
} else {
can_calculate_rate = FALSE;
}
for (i = 0; i < 4; i++) {
if (phdr->phy_info.info_11ac.nss[i] != 0) {
proto_item *it;
proto_tree *user_tree;
it = proto_tree_add_item(radio_tree, hf_wlan_radio_11ac_user, tvb, 0, 0, ENC_NA);
proto_item_append_text(it, " %d: MCS %u", i, phdr->phy_info.info_11ac.mcs[i]);
user_tree = proto_item_add_subtree(it, ett_wlan_radio_11ac_user);
it = proto_tree_add_uint(user_tree, hf_wlan_radio_11ac_mcs, tvb, 0, 0,
phdr->phy_info.info_11ac.mcs[i]);
if (phdr->phy_info.info_11ac.mcs[i] > MAX_MCS_VHT_INDEX) {
proto_item_append_text(it, " (invalid)");
} else {
proto_item_append_text(it, " (%s %s)",
ieee80211_vhtinfo[phdr->phy_info.info_11ac.mcs[i]].modulation,
ieee80211_vhtinfo[phdr->phy_info.info_11ac.mcs[i]].coding_rate);
}
proto_tree_add_uint(user_tree, hf_wlan_radio_11ac_nss, tvb, 0, 0,
phdr->phy_info.info_11ac.nss[i]);
if (phdr->phy_info.info_11ac.presence_flags & PHDR_802_11AC_HAS_STBC) {
guint nsts;
if (phdr->phy_info.info_11ac.stbc)
nsts = 2 * phdr->phy_info.info_11ac.nss[i];
else
nsts = phdr->phy_info.info_11ac.nss[i];
proto_tree_add_uint(user_tree, hf_wlan_radio_11ac_nsts, tvb, 0, 0,
nsts);
}
if (phdr->phy_info.info_11ac.presence_flags & PHDR_802_11AC_HAS_FEC) {
proto_tree_add_uint(user_tree, hf_wlan_radio_11ac_fec, tvb, 0, 0,
(phdr->phy_info.info_11ac.fec >> i) & 0x01);
}
if (can_calculate_rate && phdr->phy_info.info_11ac.mcs[i] <= MAX_MCS_VHT_INDEX) {
data_rate = ieee80211_vhtinfo[phdr->phy_info.info_11ac.mcs[i]].rates[bandwidth][phdr->phy_info.info_11ac.short_gi] * phdr->phy_info.info_11ac.nss[i];
if (data_rate != 0.0f) {
proto_tree_add_float_format_value(user_tree, hf_wlan_radio_data_rate, tvb, 0, 0,
data_rate,
"%.1f Mb/s",
data_rate);
}
}
}
}
if (phdr->phy_info.info_11ac.presence_flags & PHDR_802_11AC_HAS_GROUP_ID) {
proto_tree_add_uint(radio_tree, hf_wlan_radio_11ac_gid, tvb, 0, 0,
phdr->phy_info.info_11ac.group_id);
}
if (phdr->phy_info.info_11ac.presence_flags & PHDR_802_11AC_HAS_PARTIAL_AID) {
proto_tree_add_uint(radio_tree, hf_wlan_radio_11ac_p_aid, tvb, 0, 0,
phdr->phy_info.info_11ac.partial_aid);
}
}
break;
}
}
if (have_data_rate) {
col_add_fstr(pinfo->cinfo, COL_TX_RATE, "%.1f", data_rate);
proto_tree_add_float_format_value(radio_tree, hf_wlan_radio_data_rate, tvb, 0, 0,
data_rate,
"%.1f Mb/s",
data_rate);
}
if (phdr->presence_flags & PHDR_802_11_HAS_CHANNEL) {
col_add_fstr(pinfo->cinfo, COL_FREQ_CHAN, "%u", phdr->channel);
proto_tree_add_uint(radio_tree, hf_wlan_radio_channel, tvb, 0, 0,
phdr->channel);
}
if (phdr->presence_flags & PHDR_802_11_HAS_FREQUENCY) {
col_add_fstr(pinfo->cinfo, COL_FREQ_CHAN, "%u MHz", phdr->frequency);
proto_tree_add_uint_format_value(radio_tree, hf_wlan_radio_frequency, tvb, 0, 0,
phdr->frequency,
"%u MHz",
phdr->frequency);
}
if (phdr->presence_flags & PHDR_802_11_HAS_SIGNAL_PERCENT) {
col_add_fstr(pinfo->cinfo, COL_RSSI, "%u%%", phdr->signal_percent);
proto_tree_add_uint_format_value(radio_tree, hf_wlan_radio_signal_percent, tvb, 0, 0,
phdr->signal_percent,
"%u%%",
phdr->signal_percent);
}
if (phdr->presence_flags & PHDR_802_11_HAS_SIGNAL_DBM) {
col_add_fstr(pinfo->cinfo, COL_RSSI, "%d dBm", phdr->signal_dbm);
proto_tree_add_int_format_value(radio_tree, hf_wlan_radio_signal_dbm, tvb, 0, 0,
phdr->signal_dbm,
"%d dBm",
phdr->signal_dbm);
}
if (phdr->presence_flags & PHDR_802_11_HAS_NOISE_PERCENT) {
proto_tree_add_uint_format_value(radio_tree, hf_wlan_radio_noise_percent, tvb, 0, 0,
phdr->noise_percent,
"%u%%",
phdr->noise_percent);
}
if (phdr->presence_flags & PHDR_802_11_HAS_NOISE_DBM) {
proto_tree_add_int_format_value(radio_tree, hf_wlan_radio_noise_dbm, tvb, 0, 0,
phdr->noise_dbm,
"%d dBm",
phdr->noise_dbm);
}
if (phdr->presence_flags & PHDR_802_11_HAS_TSF_TIMESTAMP) {
proto_tree_add_uint64(radio_tree, hf_wlan_radio_timestamp, tvb, 0, 0,
phdr->tsf_timestamp);
}
}
pinfo->current_proto = "IEEE 802.11";
return call_dissector_with_data(ieee80211_handle, tvb, pinfo, tree, data);
}
void proto_register_ieee80211_radio(void)
{
proto_wlan_radio = proto_register_protocol("802.11 radio information", "802.11 Radio",
"wlan_radio");
proto_register_field_array(proto_wlan_radio, hf_wlan_radio, array_length(hf_wlan_radio));
proto_register_subtree_array(tree_array, array_length(tree_array));
wlan_radio_handle = new_register_dissector("wlan_radio", dissect_wlan_radio, proto_wlan_radio);
}
void proto_reg_handoff_ieee80211_radio(void)
{
dissector_add_uint("wtap_encap", WTAP_ENCAP_IEEE_802_11_WITH_RADIO,
wlan_radio_handle);
ieee80211_handle = find_dissector("wlan");
}
