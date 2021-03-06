static u8
mwifiex_search_oui_in_ie(struct ie_body *iebody, u8 *oui)
{
u8 count;
count = iebody->ptk_cnt[0];
while (count) {
if (!memcmp(iebody->ptk_body, oui, sizeof(iebody->ptk_body)))
return MWIFIEX_OUI_PRESENT;
--count;
if (count)
iebody = (struct ie_body *) ((u8 *) iebody +
sizeof(iebody->ptk_body));
}
pr_debug("info: %s: OUI is not found in PTK\n", __func__);
return MWIFIEX_OUI_NOT_PRESENT;
}
static u8
mwifiex_is_rsn_oui_present(struct mwifiex_bssdescriptor *bss_desc, u32 cipher)
{
u8 *oui;
struct ie_body *iebody;
u8 ret = MWIFIEX_OUI_NOT_PRESENT;
if (((bss_desc->bcn_rsn_ie) && ((*(bss_desc->bcn_rsn_ie)).
ieee_hdr.element_id == WLAN_EID_RSN))) {
iebody = (struct ie_body *)
(((u8 *) bss_desc->bcn_rsn_ie->data) +
RSN_GTK_OUI_OFFSET);
oui = &mwifiex_rsn_oui[cipher][0];
ret = mwifiex_search_oui_in_ie(iebody, oui);
if (ret)
return ret;
}
return ret;
}
static u8
mwifiex_is_wpa_oui_present(struct mwifiex_bssdescriptor *bss_desc, u32 cipher)
{
u8 *oui;
struct ie_body *iebody;
u8 ret = MWIFIEX_OUI_NOT_PRESENT;
if (((bss_desc->bcn_wpa_ie) && ((*(bss_desc->bcn_wpa_ie)).
vend_hdr.element_id == WLAN_EID_WPA))) {
iebody = (struct ie_body *) bss_desc->bcn_wpa_ie->data;
oui = &mwifiex_wpa_oui[cipher][0];
ret = mwifiex_search_oui_in_ie(iebody, oui);
if (ret)
return ret;
}
return ret;
}
s32
mwifiex_ssid_cmp(struct mwifiex_802_11_ssid *ssid1,
struct mwifiex_802_11_ssid *ssid2)
{
if (!ssid1 || !ssid2 || (ssid1->ssid_len != ssid2->ssid_len))
return -1;
return memcmp(ssid1->ssid, ssid2->ssid, ssid1->ssid_len);
}
int mwifiex_find_best_bss(struct mwifiex_private *priv,
struct mwifiex_ssid_bssid *ssid_bssid)
{
struct mwifiex_ssid_bssid tmp_ssid_bssid;
u8 *mac;
if (!ssid_bssid)
return -1;
memcpy(&tmp_ssid_bssid, ssid_bssid,
sizeof(struct mwifiex_ssid_bssid));
if (!mwifiex_bss_ioctl_find_bss(priv, &tmp_ssid_bssid)) {
memcpy(ssid_bssid, &tmp_ssid_bssid,
sizeof(struct mwifiex_ssid_bssid));
mac = (u8 *) &ssid_bssid->bssid;
dev_dbg(priv->adapter->dev, "cmd: found network: ssid=%s,"
" %pM\n", ssid_bssid->ssid.ssid, mac);
return 0;
}
return -1;
}
int mwifiex_set_user_scan_ioctl(struct mwifiex_private *priv,
struct mwifiex_user_scan_cfg *scan_req)
{
int status;
priv->adapter->cmd_wait_q.condition = false;
status = mwifiex_scan_networks(priv, scan_req);
if (!status)
status = mwifiex_wait_queue_complete(priv->adapter);
return status;
}
static bool
mwifiex_is_network_compatible_for_wapi(struct mwifiex_private *priv,
struct mwifiex_bssdescriptor *bss_desc)
{
if (priv->sec_info.wapi_enabled &&
(bss_desc->bcn_wapi_ie &&
((*(bss_desc->bcn_wapi_ie)).ieee_hdr.element_id ==
WLAN_EID_BSS_AC_ACCESS_DELAY))) {
return true;
}
return false;
}
static bool
mwifiex_is_network_compatible_for_no_sec(struct mwifiex_private *priv,
struct mwifiex_bssdescriptor *bss_desc)
{
if (priv->sec_info.wep_status == MWIFIEX_802_11_WEP_DISABLED
&& !priv->sec_info.wpa_enabled && !priv->sec_info.wpa2_enabled
&& ((!bss_desc->bcn_wpa_ie) ||
((*(bss_desc->bcn_wpa_ie)).vend_hdr.element_id !=
WLAN_EID_WPA))
&& ((!bss_desc->bcn_rsn_ie) ||
((*(bss_desc->bcn_rsn_ie)).ieee_hdr.element_id !=
WLAN_EID_RSN))
&& !priv->sec_info.encryption_mode
&& !bss_desc->privacy) {
return true;
}
return false;
}
static bool
mwifiex_is_network_compatible_for_static_wep(struct mwifiex_private *priv,
struct mwifiex_bssdescriptor *bss_desc)
{
if (priv->sec_info.wep_status == MWIFIEX_802_11_WEP_ENABLED
&& !priv->sec_info.wpa_enabled && !priv->sec_info.wpa2_enabled
&& bss_desc->privacy) {
return true;
}
return false;
}
static bool
mwifiex_is_network_compatible_for_wpa(struct mwifiex_private *priv,
struct mwifiex_bssdescriptor *bss_desc,
int index)
{
if (priv->sec_info.wep_status == MWIFIEX_802_11_WEP_DISABLED
&& priv->sec_info.wpa_enabled && !priv->sec_info.wpa2_enabled
&& ((bss_desc->bcn_wpa_ie) && ((*(bss_desc->bcn_wpa_ie)).vend_hdr.
element_id == WLAN_EID_WPA))
) {
dev_dbg(priv->adapter->dev, "info: %s: WPA: index=%d"
" wpa_ie=%#x wpa2_ie=%#x WEP=%s WPA=%s WPA2=%s "
"EncMode=%#x privacy=%#x\n", __func__, index,
(bss_desc->bcn_wpa_ie) ?
(*(bss_desc->bcn_wpa_ie)).
vend_hdr.element_id : 0,
(bss_desc->bcn_rsn_ie) ?
(*(bss_desc->bcn_rsn_ie)).
ieee_hdr.element_id : 0,
(priv->sec_info.wep_status ==
MWIFIEX_802_11_WEP_ENABLED) ? "e" : "d",
(priv->sec_info.wpa_enabled) ? "e" : "d",
(priv->sec_info.wpa2_enabled) ? "e" : "d",
priv->sec_info.encryption_mode,
bss_desc->privacy);
return true;
}
return false;
}
static bool
mwifiex_is_network_compatible_for_wpa2(struct mwifiex_private *priv,
struct mwifiex_bssdescriptor *bss_desc,
int index)
{
if (priv->sec_info.wep_status == MWIFIEX_802_11_WEP_DISABLED
&& !priv->sec_info.wpa_enabled && priv->sec_info.wpa2_enabled
&& ((bss_desc->bcn_rsn_ie) && ((*(bss_desc->bcn_rsn_ie)).ieee_hdr.
element_id == WLAN_EID_RSN))
) {
dev_dbg(priv->adapter->dev, "info: %s: WPA2: index=%d"
" wpa_ie=%#x wpa2_ie=%#x WEP=%s WPA=%s WPA2=%s "
"EncMode=%#x privacy=%#x\n", __func__, index,
(bss_desc->bcn_wpa_ie) ?
(*(bss_desc->bcn_wpa_ie)).
vend_hdr.element_id : 0,
(bss_desc->bcn_rsn_ie) ?
(*(bss_desc->bcn_rsn_ie)).
ieee_hdr.element_id : 0,
(priv->sec_info.wep_status ==
MWIFIEX_802_11_WEP_ENABLED) ? "e" : "d",
(priv->sec_info.wpa_enabled) ? "e" : "d",
(priv->sec_info.wpa2_enabled) ? "e" : "d",
priv->sec_info.encryption_mode,
bss_desc->privacy);
return true;
}
return false;
}
static bool
mwifiex_is_network_compatible_for_adhoc_aes(struct mwifiex_private *priv,
struct mwifiex_bssdescriptor *bss_desc)
{
if (priv->sec_info.wep_status == MWIFIEX_802_11_WEP_DISABLED
&& !priv->sec_info.wpa_enabled && !priv->sec_info.wpa2_enabled
&& ((!bss_desc->bcn_wpa_ie) || ((*(bss_desc->bcn_wpa_ie)).vend_hdr.
element_id != WLAN_EID_WPA))
&& ((!bss_desc->bcn_rsn_ie) || ((*(bss_desc->bcn_rsn_ie)).ieee_hdr.
element_id != WLAN_EID_RSN))
&& !priv->sec_info.encryption_mode
&& bss_desc->privacy) {
return true;
}
return false;
}
static bool
mwifiex_is_network_compatible_for_dynamic_wep(struct mwifiex_private *priv,
struct mwifiex_bssdescriptor *bss_desc,
int index)
{
if (priv->sec_info.wep_status == MWIFIEX_802_11_WEP_DISABLED
&& !priv->sec_info.wpa_enabled && !priv->sec_info.wpa2_enabled
&& ((!bss_desc->bcn_wpa_ie) || ((*(bss_desc->bcn_wpa_ie)).vend_hdr.
element_id != WLAN_EID_WPA))
&& ((!bss_desc->bcn_rsn_ie) || ((*(bss_desc->bcn_rsn_ie)).ieee_hdr.
element_id != WLAN_EID_RSN))
&& priv->sec_info.encryption_mode
&& bss_desc->privacy) {
dev_dbg(priv->adapter->dev, "info: %s: dynamic "
"WEP: index=%d wpa_ie=%#x wpa2_ie=%#x "
"EncMode=%#x privacy=%#x\n",
__func__, index,
(bss_desc->bcn_wpa_ie) ?
(*(bss_desc->bcn_wpa_ie)).
vend_hdr.element_id : 0,
(bss_desc->bcn_rsn_ie) ?
(*(bss_desc->bcn_rsn_ie)).
ieee_hdr.element_id : 0,
priv->sec_info.encryption_mode,
bss_desc->privacy);
return true;
}
return false;
}
static s32
mwifiex_is_network_compatible(struct mwifiex_private *priv, u32 index, u32 mode)
{
struct mwifiex_adapter *adapter = priv->adapter;
struct mwifiex_bssdescriptor *bss_desc;
bss_desc = &adapter->scan_table[index];
bss_desc->disable_11n = false;
if (priv->media_connected && (priv->bss_mode == NL80211_IFTYPE_STATION)
&& (bss_desc->bss_mode == NL80211_IFTYPE_STATION))
return index;
if (priv->wps.session_enable) {
dev_dbg(adapter->dev,
"info: return success directly in WPS period\n");
return index;
}
if (mwifiex_is_network_compatible_for_wapi(priv, bss_desc)) {
dev_dbg(adapter->dev, "info: return success for WAPI AP\n");
return index;
}
if (bss_desc->bss_mode == mode) {
if (mwifiex_is_network_compatible_for_no_sec(priv, bss_desc)) {
return index;
} else if (mwifiex_is_network_compatible_for_static_wep(priv,
bss_desc)) {
dev_dbg(adapter->dev, "info: Disable 11n in WEP mode.\n");
bss_desc->disable_11n = true;
return index;
} else if (mwifiex_is_network_compatible_for_wpa(priv, bss_desc,
index)) {
if (((priv->adapter->config_bands & BAND_GN
|| priv->adapter->config_bands & BAND_AN)
&& bss_desc->bcn_ht_cap)
&& !mwifiex_is_wpa_oui_present(bss_desc,
CIPHER_SUITE_CCMP)) {
if (mwifiex_is_wpa_oui_present(bss_desc,
CIPHER_SUITE_TKIP)) {
dev_dbg(adapter->dev,
"info: Disable 11n if AES "
"is not supported by AP\n");
bss_desc->disable_11n = true;
} else {
return -1;
}
}
return index;
} else if (mwifiex_is_network_compatible_for_wpa2(priv,
bss_desc, index)) {
if (((priv->adapter->config_bands & BAND_GN
|| priv->adapter->config_bands & BAND_AN)
&& bss_desc->bcn_ht_cap)
&& !mwifiex_is_rsn_oui_present(bss_desc,
CIPHER_SUITE_CCMP)) {
if (mwifiex_is_rsn_oui_present(bss_desc,
CIPHER_SUITE_TKIP)) {
dev_dbg(adapter->dev,
"info: Disable 11n if AES "
"is not supported by AP\n");
bss_desc->disable_11n = true;
} else {
return -1;
}
}
return index;
} else if (mwifiex_is_network_compatible_for_adhoc_aes(priv,
bss_desc)) {
return index;
} else if (mwifiex_is_network_compatible_for_dynamic_wep(priv,
bss_desc, index)) {
return index;
}
dev_dbg(adapter->dev, "info: %s: failed: index=%d "
"wpa_ie=%#x wpa2_ie=%#x WEP=%s WPA=%s WPA2=%s EncMode"
"=%#x privacy=%#x\n",
__func__, index,
(bss_desc->bcn_wpa_ie) ?
(*(bss_desc->bcn_wpa_ie)).vend_hdr.
element_id : 0,
(bss_desc->bcn_rsn_ie) ?
(*(bss_desc->bcn_rsn_ie)).ieee_hdr.
element_id : 0,
(priv->sec_info.wep_status ==
MWIFIEX_802_11_WEP_ENABLED) ? "e" : "d",
(priv->sec_info.wpa_enabled) ? "e" : "d",
(priv->sec_info.wpa2_enabled) ? "e" : "d",
priv->sec_info.encryption_mode, bss_desc->privacy);
return -1;
}
return -1;
}
static s32
mwifiex_find_best_network_in_list(struct mwifiex_private *priv)
{
struct mwifiex_adapter *adapter = priv->adapter;
u32 mode = priv->bss_mode;
s32 best_net = -1;
s32 best_rssi = 0;
u32 i;
dev_dbg(adapter->dev, "info: num of BSSIDs = %d\n",
adapter->num_in_scan_table);
for (i = 0; i < adapter->num_in_scan_table; i++) {
switch (mode) {
case NL80211_IFTYPE_STATION:
case NL80211_IFTYPE_ADHOC:
if (mwifiex_is_network_compatible(priv, i, mode) >= 0) {
if (SCAN_RSSI(adapter->scan_table[i].rssi) >
best_rssi) {
best_rssi = SCAN_RSSI(adapter->
scan_table[i].rssi);
best_net = i;
}
}
break;
case NL80211_IFTYPE_UNSPECIFIED:
default:
if (SCAN_RSSI(adapter->scan_table[i].rssi) >
best_rssi) {
best_rssi = SCAN_RSSI(adapter->scan_table[i].
rssi);
best_net = i;
}
break;
}
}
return best_net;
}
static void
mwifiex_scan_create_channel_list(struct mwifiex_private *priv,
const struct mwifiex_user_scan_cfg
*user_scan_in,
struct mwifiex_chan_scan_param_set
*scan_chan_list,
u8 filtered_scan)
{
enum ieee80211_band band;
struct ieee80211_supported_band *sband;
struct ieee80211_channel *ch;
struct mwifiex_adapter *adapter = priv->adapter;
int chan_idx = 0, i;
u8 scan_type;
for (band = 0; (band < IEEE80211_NUM_BANDS) ; band++) {
if (!priv->wdev->wiphy->bands[band])
continue;
sband = priv->wdev->wiphy->bands[band];
for (i = 0; (i < sband->n_channels) ; i++, chan_idx++) {
ch = &sband->channels[i];
if (ch->flags & IEEE80211_CHAN_DISABLED)
continue;
scan_chan_list[chan_idx].radio_type = band;
scan_type = ch->flags & IEEE80211_CHAN_PASSIVE_SCAN;
if (user_scan_in &&
user_scan_in->chan_list[0].scan_time)
scan_chan_list[chan_idx].max_scan_time =
cpu_to_le16((u16) user_scan_in->
chan_list[0].scan_time);
else if (scan_type == MWIFIEX_SCAN_TYPE_PASSIVE)
scan_chan_list[chan_idx].max_scan_time =
cpu_to_le16(adapter->passive_scan_time);
else
scan_chan_list[chan_idx].max_scan_time =
cpu_to_le16(adapter->active_scan_time);
if (scan_type == MWIFIEX_SCAN_TYPE_PASSIVE)
scan_chan_list[chan_idx].chan_scan_mode_bitmap
|= MWIFIEX_PASSIVE_SCAN;
else
scan_chan_list[chan_idx].chan_scan_mode_bitmap
&= ~MWIFIEX_PASSIVE_SCAN;
scan_chan_list[chan_idx].chan_number =
(u32) ch->hw_value;
if (filtered_scan) {
scan_chan_list[chan_idx].max_scan_time =
cpu_to_le16(adapter->specific_scan_time);
scan_chan_list[chan_idx].chan_scan_mode_bitmap
|= MWIFIEX_DISABLE_CHAN_FILT;
}
}
}
}
static int
mwifiex_scan_channel_list(struct mwifiex_private *priv,
u32 max_chan_per_scan, u8 filtered_scan,
struct mwifiex_scan_cmd_config *scan_cfg_out,
struct mwifiex_ie_types_chan_list_param_set
*chan_tlv_out,
struct mwifiex_chan_scan_param_set *scan_chan_list)
{
int ret = 0;
struct mwifiex_chan_scan_param_set *tmp_chan_list;
struct mwifiex_chan_scan_param_set *start_chan;
u32 tlv_idx;
u32 total_scan_time;
u32 done_early;
if (!scan_cfg_out || !chan_tlv_out || !scan_chan_list) {
dev_dbg(priv->adapter->dev,
"info: Scan: Null detect: %p, %p, %p\n",
scan_cfg_out, chan_tlv_out, scan_chan_list);
return -1;
}
chan_tlv_out->header.type = cpu_to_le16(TLV_TYPE_CHANLIST);
tmp_chan_list = scan_chan_list;
while (tmp_chan_list->chan_number) {
tlv_idx = 0;
total_scan_time = 0;
chan_tlv_out->header.len = 0;
start_chan = tmp_chan_list;
done_early = false;
while (tlv_idx < max_chan_per_scan
&& tmp_chan_list->chan_number && !done_early) {
dev_dbg(priv->adapter->dev,
"info: Scan: Chan(%3d), Radio(%d),"
" Mode(%d, %d), Dur(%d)\n",
tmp_chan_list->chan_number,
tmp_chan_list->radio_type,
tmp_chan_list->chan_scan_mode_bitmap
& MWIFIEX_PASSIVE_SCAN,
(tmp_chan_list->chan_scan_mode_bitmap
& MWIFIEX_DISABLE_CHAN_FILT) >> 1,
le16_to_cpu(tmp_chan_list->max_scan_time));
memcpy(chan_tlv_out->chan_scan_param + tlv_idx,
tmp_chan_list,
sizeof(chan_tlv_out->chan_scan_param));
chan_tlv_out->header.len =
cpu_to_le16(le16_to_cpu(chan_tlv_out->header.len) +
(sizeof(chan_tlv_out->chan_scan_param)));
scan_cfg_out->tlv_buf_len = (u32) ((u8 *) chan_tlv_out -
scan_cfg_out->tlv_buf);
scan_cfg_out->tlv_buf_len +=
(sizeof(chan_tlv_out->header)
+ le16_to_cpu(chan_tlv_out->header.len));
tlv_idx++;
total_scan_time +=
le16_to_cpu(tmp_chan_list->max_scan_time);
done_early = false;
if (!filtered_scan && (tmp_chan_list->chan_number == 1
|| tmp_chan_list->chan_number == 6
|| tmp_chan_list->chan_number == 11))
done_early = true;
tmp_chan_list++;
if (!filtered_scan && (tmp_chan_list->chan_number == 1
|| tmp_chan_list->chan_number == 6
|| tmp_chan_list->chan_number == 11))
done_early = true;
}
if (total_scan_time > MWIFIEX_MAX_TOTAL_SCAN_TIME) {
dev_err(priv->adapter->dev, "total scan time %dms"
" is over limit (%dms), scan skipped\n",
total_scan_time, MWIFIEX_MAX_TOTAL_SCAN_TIME);
ret = -1;
break;
}
priv->adapter->scan_channels = start_chan;
ret = mwifiex_send_cmd_async(priv, HostCmd_CMD_802_11_SCAN,
HostCmd_ACT_GEN_SET, 0,
scan_cfg_out);
if (ret)
break;
}
if (ret)
return -1;
return 0;
}
static void
mwifiex_scan_setup_scan_config(struct mwifiex_private *priv,
const struct mwifiex_user_scan_cfg *user_scan_in,
struct mwifiex_scan_cmd_config *scan_cfg_out,
struct mwifiex_ie_types_chan_list_param_set
**chan_list_out,
struct mwifiex_chan_scan_param_set
*scan_chan_list,
u8 *max_chan_per_scan, u8 *filtered_scan,
u8 *scan_current_only)
{
struct mwifiex_adapter *adapter = priv->adapter;
struct mwifiex_ie_types_num_probes *num_probes_tlv;
struct mwifiex_ie_types_wildcard_ssid_params *wildcard_ssid_tlv;
struct mwifiex_ie_types_rates_param_set *rates_tlv;
const u8 zero_mac[ETH_ALEN] = { 0, 0, 0, 0, 0, 0 };
u8 *tlv_pos;
u32 num_probes;
u32 ssid_len;
u32 chan_idx;
u32 scan_type;
u16 scan_dur;
u8 channel;
u8 radio_type;
u32 ssid_idx;
u8 ssid_filter;
u8 rates[MWIFIEX_SUPPORTED_RATES];
u32 rates_size;
struct mwifiex_ie_types_htcap *ht_cap;
scan_cfg_out->tlv_buf_len = 0;
tlv_pos = scan_cfg_out->tlv_buf;
*filtered_scan = false;
*scan_current_only = false;
if (user_scan_in) {
ssid_filter = true;
scan_cfg_out->bss_mode =
(user_scan_in->bss_mode ? (u8) user_scan_in->
bss_mode : (u8) adapter->scan_mode);
num_probes =
(user_scan_in->num_probes ? user_scan_in->
num_probes : adapter->scan_probes);
memcpy(scan_cfg_out->specific_bssid,
user_scan_in->specific_bssid,
sizeof(scan_cfg_out->specific_bssid));
for (ssid_idx = 0;
((ssid_idx < ARRAY_SIZE(user_scan_in->ssid_list))
&& (*user_scan_in->ssid_list[ssid_idx].ssid
|| user_scan_in->ssid_list[ssid_idx].max_len));
ssid_idx++) {
ssid_len = strlen(user_scan_in->ssid_list[ssid_idx].
ssid) + 1;
wildcard_ssid_tlv =
(struct mwifiex_ie_types_wildcard_ssid_params *)
tlv_pos;
wildcard_ssid_tlv->header.type =
cpu_to_le16(TLV_TYPE_WILDCARDSSID);
wildcard_ssid_tlv->header.len = cpu_to_le16(
(u16) (ssid_len + sizeof(wildcard_ssid_tlv->
max_ssid_length)));
wildcard_ssid_tlv->max_ssid_length =
user_scan_in->ssid_list[ssid_idx].max_len;
memcpy(wildcard_ssid_tlv->ssid,
user_scan_in->ssid_list[ssid_idx].ssid,
ssid_len);
tlv_pos += (sizeof(wildcard_ssid_tlv->header)
+ le16_to_cpu(wildcard_ssid_tlv->header.len));
dev_dbg(adapter->dev, "info: scan: ssid_list[%d]: %s, %d\n",
ssid_idx, wildcard_ssid_tlv->ssid,
wildcard_ssid_tlv->max_ssid_length);
if (!ssid_len && wildcard_ssid_tlv->max_ssid_length)
ssid_filter = false;
}
if ((ssid_idx && ssid_filter)
|| memcmp(scan_cfg_out->specific_bssid, &zero_mac,
sizeof(zero_mac)))
*filtered_scan = true;
} else {
scan_cfg_out->bss_mode = (u8) adapter->scan_mode;
num_probes = adapter->scan_probes;
}
if (*filtered_scan)
*max_chan_per_scan = MWIFIEX_MAX_CHANNELS_PER_SPECIFIC_SCAN;
else
*max_chan_per_scan = MWIFIEX_CHANNELS_PER_SCAN_CMD;
if (num_probes) {
dev_dbg(adapter->dev, "info: scan: num_probes = %d\n",
num_probes);
num_probes_tlv = (struct mwifiex_ie_types_num_probes *) tlv_pos;
num_probes_tlv->header.type = cpu_to_le16(TLV_TYPE_NUMPROBES);
num_probes_tlv->header.len =
cpu_to_le16(sizeof(num_probes_tlv->num_probes));
num_probes_tlv->num_probes = cpu_to_le16((u16) num_probes);
tlv_pos += sizeof(num_probes_tlv->header) +
le16_to_cpu(num_probes_tlv->header.len);
}
memset(rates, 0, sizeof(rates));
rates_size = mwifiex_get_supported_rates(priv, rates);
rates_tlv = (struct mwifiex_ie_types_rates_param_set *) tlv_pos;
rates_tlv->header.type = cpu_to_le16(WLAN_EID_SUPP_RATES);
rates_tlv->header.len = cpu_to_le16((u16) rates_size);
memcpy(rates_tlv->rates, rates, rates_size);
tlv_pos += sizeof(rates_tlv->header) + rates_size;
dev_dbg(adapter->dev, "info: SCAN_CMD: Rates size = %d\n", rates_size);
if (ISSUPP_11NENABLED(priv->adapter->fw_cap_info)
&& (priv->adapter->config_bands & BAND_GN
|| priv->adapter->config_bands & BAND_AN)) {
ht_cap = (struct mwifiex_ie_types_htcap *) tlv_pos;
memset(ht_cap, 0, sizeof(struct mwifiex_ie_types_htcap));
ht_cap->header.type = cpu_to_le16(WLAN_EID_HT_CAPABILITY);
ht_cap->header.len =
cpu_to_le16(sizeof(struct ieee80211_ht_cap));
radio_type =
mwifiex_band_to_radio_type(priv->adapter->config_bands);
mwifiex_fill_cap_info(priv, radio_type, ht_cap);
tlv_pos += sizeof(struct mwifiex_ie_types_htcap);
}
mwifiex_cmd_append_vsie_tlv(priv, MWIFIEX_VSIE_MASK_SCAN, &tlv_pos);
*chan_list_out =
(struct mwifiex_ie_types_chan_list_param_set *) tlv_pos;
if (user_scan_in && user_scan_in->chan_list[0].chan_number) {
dev_dbg(adapter->dev, "info: Scan: Using supplied channel list\n");
for (chan_idx = 0;
chan_idx < MWIFIEX_USER_SCAN_CHAN_MAX
&& user_scan_in->chan_list[chan_idx].chan_number;
chan_idx++) {
channel = user_scan_in->chan_list[chan_idx].chan_number;
(scan_chan_list + chan_idx)->chan_number = channel;
radio_type =
user_scan_in->chan_list[chan_idx].radio_type;
(scan_chan_list + chan_idx)->radio_type = radio_type;
scan_type = user_scan_in->chan_list[chan_idx].scan_type;
if (scan_type == MWIFIEX_SCAN_TYPE_PASSIVE)
(scan_chan_list +
chan_idx)->chan_scan_mode_bitmap
|= MWIFIEX_PASSIVE_SCAN;
else
(scan_chan_list +
chan_idx)->chan_scan_mode_bitmap
&= ~MWIFIEX_PASSIVE_SCAN;
if (user_scan_in->chan_list[chan_idx].scan_time) {
scan_dur = (u16) user_scan_in->
chan_list[chan_idx].scan_time;
} else {
if (scan_type == MWIFIEX_SCAN_TYPE_PASSIVE)
scan_dur = adapter->passive_scan_time;
else if (*filtered_scan)
scan_dur = adapter->specific_scan_time;
else
scan_dur = adapter->active_scan_time;
}
(scan_chan_list + chan_idx)->min_scan_time =
cpu_to_le16(scan_dur);
(scan_chan_list + chan_idx)->max_scan_time =
cpu_to_le16(scan_dur);
}
if ((chan_idx == 1)
&& (user_scan_in->chan_list[0].chan_number
== priv->curr_bss_params.bss_descriptor.channel)) {
*scan_current_only = true;
dev_dbg(adapter->dev,
"info: Scan: Scanning current channel only\n");
}
} else {
dev_dbg(adapter->dev,
"info: Scan: Creating full region channel list\n");
mwifiex_scan_create_channel_list(priv, user_scan_in,
scan_chan_list,
*filtered_scan);
}
}
static void
mwifiex_ret_802_11_scan_get_tlv_ptrs(struct mwifiex_adapter *adapter,
struct mwifiex_ie_types_data *tlv,
u32 tlv_buf_size, u32 req_tlv_type,
struct mwifiex_ie_types_data **tlv_data)
{
struct mwifiex_ie_types_data *current_tlv;
u32 tlv_buf_left;
u32 tlv_type;
u32 tlv_len;
current_tlv = tlv;
tlv_buf_left = tlv_buf_size;
*tlv_data = NULL;
dev_dbg(adapter->dev, "info: SCAN_RESP: tlv_buf_size = %d\n",
tlv_buf_size);
while (tlv_buf_left >= sizeof(struct mwifiex_ie_types_header)) {
tlv_type = le16_to_cpu(current_tlv->header.type);
tlv_len = le16_to_cpu(current_tlv->header.len);
if (sizeof(tlv->header) + tlv_len > tlv_buf_left) {
dev_err(adapter->dev, "SCAN_RESP: TLV buffer corrupt\n");
break;
}
if (req_tlv_type == tlv_type) {
switch (tlv_type) {
case TLV_TYPE_TSFTIMESTAMP:
dev_dbg(adapter->dev, "info: SCAN_RESP: TSF "
"timestamp TLV, len = %d\n", tlv_len);
*tlv_data = (struct mwifiex_ie_types_data *)
current_tlv;
break;
case TLV_TYPE_CHANNELBANDLIST:
dev_dbg(adapter->dev, "info: SCAN_RESP: channel"
" band list TLV, len = %d\n", tlv_len);
*tlv_data = (struct mwifiex_ie_types_data *)
current_tlv;
break;
default:
dev_err(adapter->dev,
"SCAN_RESP: unhandled TLV = %d\n",
tlv_type);
return;
}
}
if (*tlv_data)
break;
tlv_buf_left -= (sizeof(tlv->header) + tlv_len);
current_tlv =
(struct mwifiex_ie_types_data *) (current_tlv->data +
tlv_len);
}
}
static int
mwifiex_interpret_bss_desc_with_ie(struct mwifiex_adapter *adapter,
struct mwifiex_bssdescriptor *bss_entry,
u8 **beacon_info, u32 *bytes_left)
{
int ret = 0;
u8 element_id;
struct ieee_types_fh_param_set *fh_param_set;
struct ieee_types_ds_param_set *ds_param_set;
struct ieee_types_cf_param_set *cf_param_set;
struct ieee_types_ibss_param_set *ibss_param_set;
__le16 beacon_interval;
__le16 capabilities;
u8 *current_ptr;
u8 *rate;
u8 element_len;
u16 total_ie_len;
u8 bytes_to_copy;
u8 rate_size;
u16 beacon_size;
u8 found_data_rate_ie;
u32 bytes_left_for_current_beacon;
struct ieee_types_vendor_specific *vendor_ie;
const u8 wpa_oui[4] = { 0x00, 0x50, 0xf2, 0x01 };
const u8 wmm_oui[4] = { 0x00, 0x50, 0xf2, 0x02 };
found_data_rate_ie = false;
rate_size = 0;
beacon_size = 0;
if (*bytes_left >= sizeof(beacon_size)) {
memcpy(&beacon_size, *beacon_info, sizeof(beacon_size));
*bytes_left -= sizeof(beacon_size);
*beacon_info += sizeof(beacon_size);
}
if (!beacon_size || beacon_size > *bytes_left) {
*beacon_info += *bytes_left;
*bytes_left = 0;
return -1;
}
current_ptr = *beacon_info;
*beacon_info += beacon_size;
*bytes_left -= beacon_size;
bytes_left_for_current_beacon = beacon_size;
memcpy(bss_entry->mac_address, current_ptr, ETH_ALEN);
dev_dbg(adapter->dev, "info: InterpretIE: AP MAC Addr: %pM\n",
bss_entry->mac_address);
current_ptr += ETH_ALEN;
bytes_left_for_current_beacon -= ETH_ALEN;
if (bytes_left_for_current_beacon < 12) {
dev_err(adapter->dev, "InterpretIE: not enough bytes left\n");
return -1;
}
bss_entry->rssi = (s32) (*current_ptr);
dev_dbg(adapter->dev, "info: InterpretIE: RSSI=%02X\n", *current_ptr);
current_ptr += 1;
bytes_left_for_current_beacon -= 1;
bss_entry->beacon_buf = current_ptr;
bss_entry->beacon_buf_size = bytes_left_for_current_beacon;
memcpy(bss_entry->time_stamp, current_ptr, 8);
current_ptr += 8;
bytes_left_for_current_beacon -= 8;
memcpy(&beacon_interval, current_ptr, 2);
bss_entry->beacon_period = le16_to_cpu(beacon_interval);
current_ptr += 2;
bytes_left_for_current_beacon -= 2;
memcpy(&capabilities, current_ptr, 2);
dev_dbg(adapter->dev, "info: InterpretIE: capabilities=0x%X\n",
capabilities);
bss_entry->cap_info_bitmap = le16_to_cpu(capabilities);
current_ptr += 2;
bytes_left_for_current_beacon -= 2;
dev_dbg(adapter->dev, "info: InterpretIE: IELength for this AP = %d\n",
bytes_left_for_current_beacon);
if (bss_entry->cap_info_bitmap & WLAN_CAPABILITY_PRIVACY) {
dev_dbg(adapter->dev, "info: InterpretIE: AP WEP enabled\n");
bss_entry->privacy = MWIFIEX_802_11_PRIV_FILTER_8021X_WEP;
} else {
bss_entry->privacy = MWIFIEX_802_11_PRIV_FILTER_ACCEPT_ALL;
}
if (bss_entry->cap_info_bitmap & WLAN_CAPABILITY_IBSS)
bss_entry->bss_mode = NL80211_IFTYPE_ADHOC;
else
bss_entry->bss_mode = NL80211_IFTYPE_STATION;
while (bytes_left_for_current_beacon >= 2) {
element_id = *current_ptr;
element_len = *(current_ptr + 1);
total_ie_len = element_len + sizeof(struct ieee_types_header);
if (bytes_left_for_current_beacon < total_ie_len) {
dev_err(adapter->dev, "err: InterpretIE: in processing"
" IE, bytes left < IE length\n");
bytes_left_for_current_beacon = 0;
ret = -1;
continue;
}
switch (element_id) {
case WLAN_EID_SSID:
bss_entry->ssid.ssid_len = element_len;
memcpy(bss_entry->ssid.ssid, (current_ptr + 2),
element_len);
dev_dbg(adapter->dev, "info: InterpretIE: ssid: %-32s\n",
bss_entry->ssid.ssid);
break;
case WLAN_EID_SUPP_RATES:
memcpy(bss_entry->data_rates, current_ptr + 2,
element_len);
memcpy(bss_entry->supported_rates, current_ptr + 2,
element_len);
rate_size = element_len;
found_data_rate_ie = true;
break;
case WLAN_EID_FH_PARAMS:
fh_param_set =
(struct ieee_types_fh_param_set *) current_ptr;
memcpy(&bss_entry->phy_param_set.fh_param_set,
fh_param_set,
sizeof(struct ieee_types_fh_param_set));
break;
case WLAN_EID_DS_PARAMS:
ds_param_set =
(struct ieee_types_ds_param_set *) current_ptr;
bss_entry->channel = ds_param_set->current_chan;
memcpy(&bss_entry->phy_param_set.ds_param_set,
ds_param_set,
sizeof(struct ieee_types_ds_param_set));
break;
case WLAN_EID_CF_PARAMS:
cf_param_set =
(struct ieee_types_cf_param_set *) current_ptr;
memcpy(&bss_entry->ss_param_set.cf_param_set,
cf_param_set,
sizeof(struct ieee_types_cf_param_set));
break;
case WLAN_EID_IBSS_PARAMS:
ibss_param_set =
(struct ieee_types_ibss_param_set *)
current_ptr;
memcpy(&bss_entry->ss_param_set.ibss_param_set,
ibss_param_set,
sizeof(struct ieee_types_ibss_param_set));
break;
case WLAN_EID_ERP_INFO:
bss_entry->erp_flags = *(current_ptr + 2);
break;
case WLAN_EID_EXT_SUPP_RATES:
if (found_data_rate_ie) {
if ((element_len + rate_size) >
MWIFIEX_SUPPORTED_RATES)
bytes_to_copy =
(MWIFIEX_SUPPORTED_RATES -
rate_size);
else
bytes_to_copy = element_len;
rate = (u8 *) bss_entry->data_rates;
rate += rate_size;
memcpy(rate, current_ptr + 2, bytes_to_copy);
rate = (u8 *) bss_entry->supported_rates;
rate += rate_size;
memcpy(rate, current_ptr + 2, bytes_to_copy);
}
break;
case WLAN_EID_VENDOR_SPECIFIC:
vendor_ie = (struct ieee_types_vendor_specific *)
current_ptr;
if (!memcmp
(vendor_ie->vend_hdr.oui, wpa_oui,
sizeof(wpa_oui))) {
bss_entry->bcn_wpa_ie =
(struct ieee_types_vendor_specific *)
current_ptr;
bss_entry->wpa_offset = (u16) (current_ptr -
bss_entry->beacon_buf);
} else if (!memcmp(vendor_ie->vend_hdr.oui, wmm_oui,
sizeof(wmm_oui))) {
if (total_ie_len ==
sizeof(struct ieee_types_wmm_parameter)
|| total_ie_len ==
sizeof(struct ieee_types_wmm_info))
memcpy((u8 *) &bss_entry->wmm_ie,
current_ptr, total_ie_len);
}
break;
case WLAN_EID_RSN:
bss_entry->bcn_rsn_ie =
(struct ieee_types_generic *) current_ptr;
bss_entry->rsn_offset = (u16) (current_ptr -
bss_entry->beacon_buf);
break;
case WLAN_EID_BSS_AC_ACCESS_DELAY:
bss_entry->bcn_wapi_ie =
(struct ieee_types_generic *) current_ptr;
bss_entry->wapi_offset = (u16) (current_ptr -
bss_entry->beacon_buf);
break;
case WLAN_EID_HT_CAPABILITY:
bss_entry->bcn_ht_cap = (struct ieee80211_ht_cap *)
(current_ptr +
sizeof(struct ieee_types_header));
bss_entry->ht_cap_offset = (u16) (current_ptr +
sizeof(struct ieee_types_header) -
bss_entry->beacon_buf);
break;
case WLAN_EID_HT_INFORMATION:
bss_entry->bcn_ht_info = (struct ieee80211_ht_info *)
(current_ptr +
sizeof(struct ieee_types_header));
bss_entry->ht_info_offset = (u16) (current_ptr +
sizeof(struct ieee_types_header) -
bss_entry->beacon_buf);
break;
case WLAN_EID_BSS_COEX_2040:
bss_entry->bcn_bss_co_2040 = (u8 *) (current_ptr +
sizeof(struct ieee_types_header));
bss_entry->bss_co_2040_offset = (u16) (current_ptr +
sizeof(struct ieee_types_header) -
bss_entry->beacon_buf);
break;
case WLAN_EID_EXT_CAPABILITY:
bss_entry->bcn_ext_cap = (u8 *) (current_ptr +
sizeof(struct ieee_types_header));
bss_entry->ext_cap_offset = (u16) (current_ptr +
sizeof(struct ieee_types_header) -
bss_entry->beacon_buf);
break;
case WLAN_EID_OVERLAP_BSS_SCAN_PARAM:
bss_entry->bcn_obss_scan =
(struct ieee_types_obss_scan_param *)
current_ptr;
bss_entry->overlap_bss_offset = (u16) (current_ptr -
bss_entry->beacon_buf);
break;
default:
break;
}
current_ptr += element_len + 2;
bytes_left_for_current_beacon -= (element_len + 2);
}
return ret;
}
static void
mwifiex_adjust_beacon_buffer_ptrs(struct mwifiex_private *priv, u8 advance,
u8 *bcn_store, u32 rem_bcn_size,
u32 num_of_ent)
{
struct mwifiex_adapter *adapter = priv->adapter;
u32 adj_idx;
for (adj_idx = 0; adj_idx < num_of_ent; adj_idx++) {
if (adapter->scan_table[adj_idx].beacon_buf > bcn_store) {
if (advance)
adapter->scan_table[adj_idx].beacon_buf +=
rem_bcn_size;
else
adapter->scan_table[adj_idx].beacon_buf -=
rem_bcn_size;
if (adapter->scan_table[adj_idx].bcn_wpa_ie)
adapter->scan_table[adj_idx].bcn_wpa_ie =
(struct ieee_types_vendor_specific *)
(adapter->scan_table[adj_idx].beacon_buf +
adapter->scan_table[adj_idx].wpa_offset);
if (adapter->scan_table[adj_idx].bcn_rsn_ie)
adapter->scan_table[adj_idx].bcn_rsn_ie =
(struct ieee_types_generic *)
(adapter->scan_table[adj_idx].beacon_buf +
adapter->scan_table[adj_idx].rsn_offset);
if (adapter->scan_table[adj_idx].bcn_wapi_ie)
adapter->scan_table[adj_idx].bcn_wapi_ie =
(struct ieee_types_generic *)
(adapter->scan_table[adj_idx].beacon_buf +
adapter->scan_table[adj_idx].wapi_offset);
if (adapter->scan_table[adj_idx].bcn_ht_cap)
adapter->scan_table[adj_idx].bcn_ht_cap =
(struct ieee80211_ht_cap *)
(adapter->scan_table[adj_idx].beacon_buf +
adapter->scan_table[adj_idx].ht_cap_offset);
if (adapter->scan_table[adj_idx].bcn_ht_info)
adapter->scan_table[adj_idx].bcn_ht_info =
(struct ieee80211_ht_info *)
(adapter->scan_table[adj_idx].beacon_buf +
adapter->scan_table[adj_idx].ht_info_offset);
if (adapter->scan_table[adj_idx].bcn_bss_co_2040)
adapter->scan_table[adj_idx].bcn_bss_co_2040 =
(u8 *)
(adapter->scan_table[adj_idx].beacon_buf +
adapter->scan_table[adj_idx].bss_co_2040_offset);
if (adapter->scan_table[adj_idx].bcn_ext_cap)
adapter->scan_table[adj_idx].bcn_ext_cap =
(u8 *)
(adapter->scan_table[adj_idx].beacon_buf +
adapter->scan_table[adj_idx].ext_cap_offset);
if (adapter->scan_table[adj_idx].bcn_obss_scan)
adapter->scan_table[adj_idx].bcn_obss_scan =
(struct ieee_types_obss_scan_param *)
(adapter->scan_table[adj_idx].beacon_buf +
adapter->scan_table[adj_idx].overlap_bss_offset);
}
}
}
static void
mwifiex_update_beacon_buffer_ptrs(struct mwifiex_bssdescriptor *beacon)
{
if (beacon->bcn_wpa_ie)
beacon->bcn_wpa_ie = (struct ieee_types_vendor_specific *)
(beacon->beacon_buf + beacon->wpa_offset);
if (beacon->bcn_rsn_ie)
beacon->bcn_rsn_ie = (struct ieee_types_generic *)
(beacon->beacon_buf + beacon->rsn_offset);
if (beacon->bcn_wapi_ie)
beacon->bcn_wapi_ie = (struct ieee_types_generic *)
(beacon->beacon_buf + beacon->wapi_offset);
if (beacon->bcn_ht_cap)
beacon->bcn_ht_cap = (struct ieee80211_ht_cap *)
(beacon->beacon_buf + beacon->ht_cap_offset);
if (beacon->bcn_ht_info)
beacon->bcn_ht_info = (struct ieee80211_ht_info *)
(beacon->beacon_buf + beacon->ht_info_offset);
if (beacon->bcn_bss_co_2040)
beacon->bcn_bss_co_2040 = (u8 *) (beacon->beacon_buf +
beacon->bss_co_2040_offset);
if (beacon->bcn_ext_cap)
beacon->bcn_ext_cap = (u8 *) (beacon->beacon_buf +
beacon->ext_cap_offset);
if (beacon->bcn_obss_scan)
beacon->bcn_obss_scan = (struct ieee_types_obss_scan_param *)
(beacon->beacon_buf + beacon->overlap_bss_offset);
}
static void
mwifiex_ret_802_11_scan_store_beacon(struct mwifiex_private *priv,
u32 beacon_idx, u32 num_of_ent,
struct mwifiex_bssdescriptor *new_beacon)
{
struct mwifiex_adapter *adapter = priv->adapter;
u8 *bcn_store;
u32 new_bcn_size;
u32 old_bcn_size;
u32 bcn_space;
if (adapter->scan_table[beacon_idx].beacon_buf) {
new_bcn_size = new_beacon->beacon_buf_size;
old_bcn_size = adapter->scan_table[beacon_idx].beacon_buf_size;
bcn_space = adapter->scan_table[beacon_idx].beacon_buf_size_max;
bcn_store = adapter->scan_table[beacon_idx].beacon_buf;
new_beacon->beacon_buf_size_max = bcn_space;
if (new_bcn_size == old_bcn_size) {
memcpy(bcn_store, new_beacon->beacon_buf,
new_beacon->beacon_buf_size);
} else if (new_bcn_size <= bcn_space) {
memcpy(bcn_store, new_beacon->beacon_buf, new_bcn_size);
if (old_bcn_size < bcn_space
&& new_bcn_size <= old_bcn_size) {
dev_dbg(adapter->dev, "info: AppControl:"
" smaller duplicate beacon "
"(%d), old = %d, new = %d, space = %d,"
"left = %d\n",
beacon_idx, old_bcn_size, new_bcn_size,
bcn_space,
(int)(sizeof(adapter->bcn_buf) -
(adapter->bcn_buf_end -
adapter->bcn_buf)));
memmove(bcn_store + old_bcn_size,
bcn_store + bcn_space,
adapter->bcn_buf_end - (bcn_store +
bcn_space));
adapter->bcn_buf_end -=
(bcn_space - old_bcn_size);
new_beacon->beacon_buf_size_max = old_bcn_size;
mwifiex_adjust_beacon_buffer_ptrs(priv, 0,
bcn_store, (bcn_space - old_bcn_size),
num_of_ent);
}
} else if (adapter->bcn_buf_end + (new_bcn_size - bcn_space)
< (adapter->bcn_buf + sizeof(adapter->bcn_buf))) {
dev_dbg(adapter->dev, "info: AppControl:"
" larger duplicate beacon (%d), "
"old = %d, new = %d, space = %d, left = %d\n",
beacon_idx, old_bcn_size, new_bcn_size,
bcn_space,
(int)(sizeof(adapter->bcn_buf) -
(adapter->bcn_buf_end -
adapter->bcn_buf)));
memmove(bcn_store + new_bcn_size,
bcn_store + bcn_space,
adapter->bcn_buf_end - (bcn_store + bcn_space));
memcpy(bcn_store, new_beacon->beacon_buf, new_bcn_size);
adapter->bcn_buf_end += (new_bcn_size - bcn_space);
new_beacon->beacon_buf_size_max = new_bcn_size;
mwifiex_adjust_beacon_buffer_ptrs(priv, 1, bcn_store,
(new_bcn_size - bcn_space),
num_of_ent);
} else {
dev_err(adapter->dev, "AppControl: larger duplicate "
" beacon (%d), old = %d new = %d, space = %d,"
" left = %d\n", beacon_idx, old_bcn_size,
new_bcn_size, bcn_space,
(int)(sizeof(adapter->bcn_buf) -
(adapter->bcn_buf_end - adapter->bcn_buf)));
new_beacon->beacon_buf_size = old_bcn_size;
if (new_beacon->bcn_wpa_ie)
new_beacon->wpa_offset =
adapter->scan_table[beacon_idx].
wpa_offset;
if (new_beacon->bcn_rsn_ie)
new_beacon->rsn_offset =
adapter->scan_table[beacon_idx].
rsn_offset;
if (new_beacon->bcn_wapi_ie)
new_beacon->wapi_offset =
adapter->scan_table[beacon_idx].
wapi_offset;
if (new_beacon->bcn_ht_cap)
new_beacon->ht_cap_offset =
adapter->scan_table[beacon_idx].
ht_cap_offset;
if (new_beacon->bcn_ht_info)
new_beacon->ht_info_offset =
adapter->scan_table[beacon_idx].
ht_info_offset;
if (new_beacon->bcn_bss_co_2040)
new_beacon->bss_co_2040_offset =
adapter->scan_table[beacon_idx].
bss_co_2040_offset;
if (new_beacon->bcn_ext_cap)
new_beacon->ext_cap_offset =
adapter->scan_table[beacon_idx].
ext_cap_offset;
if (new_beacon->bcn_obss_scan)
new_beacon->overlap_bss_offset =
adapter->scan_table[beacon_idx].
overlap_bss_offset;
}
new_beacon->beacon_buf = bcn_store;
mwifiex_update_beacon_buffer_ptrs(new_beacon);
} else {
if (adapter->bcn_buf_end + new_beacon->beacon_buf_size +
SCAN_BEACON_ENTRY_PAD < (adapter->bcn_buf +
sizeof(adapter->bcn_buf))) {
memcpy(adapter->bcn_buf_end, new_beacon->beacon_buf,
new_beacon->beacon_buf_size);
new_beacon->beacon_buf = adapter->bcn_buf_end;
new_beacon->beacon_buf_size_max =
(new_beacon->beacon_buf_size +
SCAN_BEACON_ENTRY_PAD);
mwifiex_update_beacon_buffer_ptrs(new_beacon);
adapter->bcn_buf_end += new_beacon->beacon_buf_size_max;
dev_dbg(adapter->dev, "info: AppControl: beacon[%02d]"
" sz=%03d, used = %04d, left = %04d\n",
beacon_idx,
new_beacon->beacon_buf_size,
(int)(adapter->bcn_buf_end - adapter->bcn_buf),
(int)(sizeof(adapter->bcn_buf) -
(adapter->bcn_buf_end -
adapter->bcn_buf)));
} else {
dev_dbg(adapter->dev, "info: AppControl: no space for"
" beacon (%d): %pM sz=%03d, left=%03d\n",
beacon_idx, new_beacon->mac_address,
new_beacon->beacon_buf_size,
(int)(sizeof(adapter->bcn_buf) -
(adapter->bcn_buf_end -
adapter->bcn_buf)));
new_beacon->beacon_buf = NULL;
new_beacon->beacon_buf_size = 0;
new_beacon->beacon_buf_size_max = 0;
new_beacon->bcn_wpa_ie = NULL;
new_beacon->wpa_offset = 0;
new_beacon->bcn_rsn_ie = NULL;
new_beacon->rsn_offset = 0;
new_beacon->bcn_wapi_ie = NULL;
new_beacon->wapi_offset = 0;
new_beacon->bcn_ht_cap = NULL;
new_beacon->ht_cap_offset = 0;
new_beacon->bcn_ht_info = NULL;
new_beacon->ht_info_offset = 0;
new_beacon->bcn_bss_co_2040 = NULL;
new_beacon->bss_co_2040_offset = 0;
new_beacon->bcn_ext_cap = NULL;
new_beacon->ext_cap_offset = 0;
new_beacon->bcn_obss_scan = NULL;
new_beacon->overlap_bss_offset = 0;
}
}
}
static void mwifiex_restore_curr_bcn(struct mwifiex_private *priv)
{
struct mwifiex_adapter *adapter = priv->adapter;
struct mwifiex_bssdescriptor *curr_bss =
&priv->curr_bss_params.bss_descriptor;
unsigned long flags;
if (priv->curr_bcn_buf &&
((adapter->bcn_buf_end + priv->curr_bcn_size) <
(adapter->bcn_buf + sizeof(adapter->bcn_buf)))) {
spin_lock_irqsave(&priv->curr_bcn_buf_lock, flags);
memcpy(adapter->bcn_buf_end, priv->curr_bcn_buf,
priv->curr_bcn_size);
curr_bss->beacon_buf = adapter->bcn_buf_end;
curr_bss->beacon_buf_size = priv->curr_bcn_size;
adapter->bcn_buf_end += priv->curr_bcn_size;
if (curr_bss->bcn_wpa_ie)
curr_bss->bcn_wpa_ie =
(struct ieee_types_vendor_specific *)
(curr_bss->beacon_buf +
curr_bss->wpa_offset);
if (curr_bss->bcn_rsn_ie)
curr_bss->bcn_rsn_ie = (struct ieee_types_generic *)
(curr_bss->beacon_buf +
curr_bss->rsn_offset);
if (curr_bss->bcn_ht_cap)
curr_bss->bcn_ht_cap = (struct ieee80211_ht_cap *)
(curr_bss->beacon_buf +
curr_bss->ht_cap_offset);
if (curr_bss->bcn_ht_info)
curr_bss->bcn_ht_info = (struct ieee80211_ht_info *)
(curr_bss->beacon_buf +
curr_bss->ht_info_offset);
if (curr_bss->bcn_bss_co_2040)
curr_bss->bcn_bss_co_2040 =
(u8 *) (curr_bss->beacon_buf +
curr_bss->bss_co_2040_offset);
if (curr_bss->bcn_ext_cap)
curr_bss->bcn_ext_cap = (u8 *) (curr_bss->beacon_buf +
curr_bss->ext_cap_offset);
if (curr_bss->bcn_obss_scan)
curr_bss->bcn_obss_scan =
(struct ieee_types_obss_scan_param *)
(curr_bss->beacon_buf +
curr_bss->overlap_bss_offset);
spin_unlock_irqrestore(&priv->curr_bcn_buf_lock, flags);
dev_dbg(adapter->dev, "info: current beacon restored %d\n",
priv->curr_bcn_size);
} else {
dev_warn(adapter->dev,
"curr_bcn_buf not saved or bcn_buf has no space\n");
}
}
static void
mwifiex_process_scan_results(struct mwifiex_private *priv)
{
struct mwifiex_adapter *adapter = priv->adapter;
s32 j;
u32 i;
unsigned long flags;
if (priv->media_connected) {
j = mwifiex_find_ssid_in_list(priv, &priv->curr_bss_params.
bss_descriptor.ssid,
priv->curr_bss_params.
bss_descriptor.mac_address,
priv->bss_mode);
if (j >= 0) {
spin_lock_irqsave(&priv->curr_bcn_buf_lock, flags);
priv->curr_bss_params.bss_descriptor.bcn_wpa_ie = NULL;
priv->curr_bss_params.bss_descriptor.wpa_offset = 0;
priv->curr_bss_params.bss_descriptor.bcn_rsn_ie = NULL;
priv->curr_bss_params.bss_descriptor.rsn_offset = 0;
priv->curr_bss_params.bss_descriptor.bcn_wapi_ie = NULL;
priv->curr_bss_params.bss_descriptor.wapi_offset = 0;
priv->curr_bss_params.bss_descriptor.bcn_ht_cap = NULL;
priv->curr_bss_params.bss_descriptor.ht_cap_offset =
0;
priv->curr_bss_params.bss_descriptor.bcn_ht_info = NULL;
priv->curr_bss_params.bss_descriptor.ht_info_offset =
0;
priv->curr_bss_params.bss_descriptor.bcn_bss_co_2040 =
NULL;
priv->curr_bss_params.bss_descriptor.
bss_co_2040_offset = 0;
priv->curr_bss_params.bss_descriptor.bcn_ext_cap = NULL;
priv->curr_bss_params.bss_descriptor.ext_cap_offset = 0;
priv->curr_bss_params.bss_descriptor.
bcn_obss_scan = NULL;
priv->curr_bss_params.bss_descriptor.
overlap_bss_offset = 0;
priv->curr_bss_params.bss_descriptor.beacon_buf = NULL;
priv->curr_bss_params.bss_descriptor.beacon_buf_size =
0;
priv->curr_bss_params.bss_descriptor.
beacon_buf_size_max = 0;
dev_dbg(adapter->dev, "info: Found current ssid/bssid"
" in list @ index #%d\n", j);
memcpy(&priv->curr_bss_params.bss_descriptor,
&adapter->scan_table[j],
sizeof(priv->curr_bss_params.bss_descriptor));
mwifiex_save_curr_bcn(priv);
spin_unlock_irqrestore(&priv->curr_bcn_buf_lock, flags);
} else {
mwifiex_restore_curr_bcn(priv);
}
}
for (i = 0; i < adapter->num_in_scan_table; i++)
dev_dbg(adapter->dev, "info: scan:(%02d) %pM "
"RSSI[%03d], SSID[%s]\n",
i, adapter->scan_table[i].mac_address,
(s32) adapter->scan_table[i].rssi,
adapter->scan_table[i].ssid.ssid);
}
static u8
mwifiex_radio_type_to_band(u8 radio_type)
{
switch (radio_type) {
case HostCmd_SCAN_RADIO_TYPE_A:
return BAND_A;
case HostCmd_SCAN_RADIO_TYPE_BG:
default:
return BAND_G;
}
}
static void
mwifiex_scan_delete_table_entry(struct mwifiex_private *priv, s32 table_idx)
{
struct mwifiex_adapter *adapter = priv->adapter;
u32 del_idx;
u32 beacon_buf_adj;
u8 *beacon_buf;
beacon_buf_adj = adapter->scan_table[table_idx].beacon_buf_size_max;
dev_dbg(adapter->dev, "info: Scan: Delete Entry %d, beacon buffer "
"removal = %d bytes\n", table_idx, beacon_buf_adj);
if (beacon_buf_adj) {
beacon_buf = adapter->scan_table[table_idx].beacon_buf;
adapter->bcn_buf_end -= beacon_buf_adj;
dev_dbg(adapter->dev, "info: scan: delete entry %d,"
" compact data: %p <- %p (sz = %d)\n",
table_idx, beacon_buf,
beacon_buf + beacon_buf_adj,
(int)(adapter->bcn_buf_end - beacon_buf));
memmove(beacon_buf, beacon_buf + beacon_buf_adj,
adapter->bcn_buf_end - beacon_buf);
}
dev_dbg(adapter->dev,
"info: Scan: Delete Entry %d, num_in_scan_table = %d\n",
table_idx, adapter->num_in_scan_table);
for (del_idx = table_idx; (del_idx + 1) < adapter->num_in_scan_table;
del_idx++) {
memcpy(adapter->scan_table + del_idx,
adapter->scan_table + del_idx + 1,
sizeof(struct mwifiex_bssdescriptor));
if (adapter->scan_table[del_idx].beacon_buf) {
adapter->scan_table[del_idx].beacon_buf -=
beacon_buf_adj;
if (adapter->scan_table[del_idx].bcn_wpa_ie)
adapter->scan_table[del_idx].bcn_wpa_ie =
(struct ieee_types_vendor_specific *)
(adapter->scan_table[del_idx].
beacon_buf +
adapter->scan_table[del_idx].
wpa_offset);
if (adapter->scan_table[del_idx].bcn_rsn_ie)
adapter->scan_table[del_idx].bcn_rsn_ie =
(struct ieee_types_generic *)
(adapter->scan_table[del_idx].
beacon_buf +
adapter->scan_table[del_idx].
rsn_offset);
if (adapter->scan_table[del_idx].bcn_wapi_ie)
adapter->scan_table[del_idx].bcn_wapi_ie =
(struct ieee_types_generic *)
(adapter->scan_table[del_idx].beacon_buf
+ adapter->scan_table[del_idx].
wapi_offset);
if (adapter->scan_table[del_idx].bcn_ht_cap)
adapter->scan_table[del_idx].bcn_ht_cap =
(struct ieee80211_ht_cap *)
(adapter->scan_table[del_idx].beacon_buf
+ adapter->scan_table[del_idx].
ht_cap_offset);
if (adapter->scan_table[del_idx].bcn_ht_info)
adapter->scan_table[del_idx].bcn_ht_info =
(struct ieee80211_ht_info *)
(adapter->scan_table[del_idx].beacon_buf
+ adapter->scan_table[del_idx].
ht_info_offset);
if (adapter->scan_table[del_idx].bcn_bss_co_2040)
adapter->scan_table[del_idx].bcn_bss_co_2040 =
(u8 *)
(adapter->scan_table[del_idx].beacon_buf
+ adapter->scan_table[del_idx].
bss_co_2040_offset);
if (adapter->scan_table[del_idx].bcn_ext_cap)
adapter->scan_table[del_idx].bcn_ext_cap =
(u8 *)
(adapter->scan_table[del_idx].beacon_buf
+ adapter->scan_table[del_idx].
ext_cap_offset);
if (adapter->scan_table[del_idx].bcn_obss_scan)
adapter->scan_table[del_idx].
bcn_obss_scan =
(struct ieee_types_obss_scan_param *)
(adapter->scan_table[del_idx].beacon_buf
+ adapter->scan_table[del_idx].
overlap_bss_offset);
}
}
memset(adapter->scan_table + adapter->num_in_scan_table - 1,
0x00, sizeof(struct mwifiex_bssdescriptor));
adapter->num_in_scan_table--;
}
static int
mwifiex_scan_delete_ssid_table_entry(struct mwifiex_private *priv,
struct mwifiex_802_11_ssid *del_ssid)
{
s32 table_idx = -1;
dev_dbg(priv->adapter->dev, "info: scan: delete ssid entry: %-32s\n",
del_ssid->ssid);
while ((table_idx = mwifiex_find_ssid_in_list(priv, del_ssid, NULL,
NL80211_IFTYPE_UNSPECIFIED)) >= 0) {
dev_dbg(priv->adapter->dev,
"info: Scan: Delete SSID Entry: Found Idx = %d\n",
table_idx);
mwifiex_scan_delete_table_entry(priv, table_idx);
}
return table_idx == -1 ? -1 : 0;
}
int mwifiex_scan_networks(struct mwifiex_private *priv,
const struct mwifiex_user_scan_cfg *user_scan_in)
{
int ret = 0;
struct mwifiex_adapter *adapter = priv->adapter;
struct cmd_ctrl_node *cmd_node;
union mwifiex_scan_cmd_config_tlv *scan_cfg_out;
struct mwifiex_ie_types_chan_list_param_set *chan_list_out;
u32 buf_size;
struct mwifiex_chan_scan_param_set *scan_chan_list;
u8 keep_previous_scan;
u8 filtered_scan;
u8 scan_current_chan_only;
u8 max_chan_per_scan;
unsigned long flags;
if (adapter->scan_processing) {
dev_dbg(adapter->dev, "cmd: Scan already in process...\n");
return ret;
}
spin_lock_irqsave(&adapter->mwifiex_cmd_lock, flags);
adapter->scan_processing = true;
spin_unlock_irqrestore(&adapter->mwifiex_cmd_lock, flags);
if (priv->scan_block) {
dev_dbg(adapter->dev,
"cmd: Scan is blocked during association...\n");
return ret;
}
scan_cfg_out = kzalloc(sizeof(union mwifiex_scan_cmd_config_tlv),
GFP_KERNEL);
if (!scan_cfg_out) {
dev_err(adapter->dev, "failed to alloc scan_cfg_out\n");
return -ENOMEM;
}
buf_size = sizeof(struct mwifiex_chan_scan_param_set) *
MWIFIEX_USER_SCAN_CHAN_MAX;
scan_chan_list = kzalloc(buf_size, GFP_KERNEL);
if (!scan_chan_list) {
dev_err(adapter->dev, "failed to alloc scan_chan_list\n");
kfree(scan_cfg_out);
return -ENOMEM;
}
keep_previous_scan = false;
mwifiex_scan_setup_scan_config(priv, user_scan_in,
&scan_cfg_out->config, &chan_list_out,
scan_chan_list, &max_chan_per_scan,
&filtered_scan, &scan_current_chan_only);
if (user_scan_in)
keep_previous_scan = user_scan_in->keep_previous_scan;
if (!keep_previous_scan) {
memset(adapter->scan_table, 0x00,
sizeof(struct mwifiex_bssdescriptor) * IW_MAX_AP);
adapter->num_in_scan_table = 0;
adapter->bcn_buf_end = adapter->bcn_buf;
}
ret = mwifiex_scan_channel_list(priv, max_chan_per_scan, filtered_scan,
&scan_cfg_out->config, chan_list_out,
scan_chan_list);
if (!ret) {
spin_lock_irqsave(&adapter->scan_pending_q_lock, flags);
if (!list_empty(&adapter->scan_pending_q)) {
cmd_node = list_first_entry(&adapter->scan_pending_q,
struct cmd_ctrl_node, list);
list_del(&cmd_node->list);
spin_unlock_irqrestore(&adapter->scan_pending_q_lock,
flags);
mwifiex_insert_cmd_to_pending_q(adapter, cmd_node,
true);
} else {
spin_unlock_irqrestore(&adapter->scan_pending_q_lock,
flags);
}
} else {
spin_lock_irqsave(&adapter->mwifiex_cmd_lock, flags);
adapter->scan_processing = true;
spin_unlock_irqrestore(&adapter->mwifiex_cmd_lock, flags);
}
kfree(scan_cfg_out);
kfree(scan_chan_list);
return ret;
}
int mwifiex_cmd_802_11_scan(struct host_cmd_ds_command *cmd,
struct mwifiex_scan_cmd_config *scan_cfg)
{
struct host_cmd_ds_802_11_scan *scan_cmd = &cmd->params.scan;
scan_cmd->bss_mode = scan_cfg->bss_mode;
memcpy(scan_cmd->bssid, scan_cfg->specific_bssid,
sizeof(scan_cmd->bssid));
memcpy(scan_cmd->tlv_buffer, scan_cfg->tlv_buf, scan_cfg->tlv_buf_len);
cmd->command = cpu_to_le16(HostCmd_CMD_802_11_SCAN);
cmd->size = cpu_to_le16((u16) (sizeof(scan_cmd->bss_mode)
+ sizeof(scan_cmd->bssid)
+ scan_cfg->tlv_buf_len + S_DS_GEN));
return 0;
}
int mwifiex_ret_802_11_scan(struct mwifiex_private *priv,
struct host_cmd_ds_command *resp)
{
int ret = 0;
struct mwifiex_adapter *adapter = priv->adapter;
struct cmd_ctrl_node *cmd_node;
struct host_cmd_ds_802_11_scan_rsp *scan_rsp;
struct mwifiex_bssdescriptor *bss_new_entry = NULL;
struct mwifiex_ie_types_data *tlv_data;
struct mwifiex_ie_types_tsf_timestamp *tsf_tlv;
u8 *bss_info;
u32 scan_resp_size;
u32 bytes_left;
u32 num_in_table;
u32 bss_idx;
u32 idx;
u32 tlv_buf_size;
long long tsf_val;
struct mwifiex_chan_freq_power *cfp;
struct mwifiex_ie_types_chan_band_list_param_set *chan_band_tlv;
struct chan_band_param_set *chan_band;
u8 band;
u8 is_bgscan_resp;
unsigned long flags;
is_bgscan_resp = (le16_to_cpu(resp->command)
== HostCmd_CMD_802_11_BG_SCAN_QUERY);
if (is_bgscan_resp)
scan_rsp = &resp->params.bg_scan_query_resp.scan_resp;
else
scan_rsp = &resp->params.scan_resp;
if (scan_rsp->number_of_sets > IW_MAX_AP) {
dev_err(adapter->dev, "SCAN_RESP: too many AP returned (%d)\n",
scan_rsp->number_of_sets);
ret = -1;
goto done;
}
bytes_left = le16_to_cpu(scan_rsp->bss_descript_size);
dev_dbg(adapter->dev, "info: SCAN_RESP: bss_descript_size %d\n",
bytes_left);
scan_resp_size = le16_to_cpu(resp->size);
dev_dbg(adapter->dev,
"info: SCAN_RESP: returned %d APs before parsing\n",
scan_rsp->number_of_sets);
num_in_table = adapter->num_in_scan_table;
bss_info = scan_rsp->bss_desc_and_tlv_buffer;
tlv_buf_size = scan_resp_size - (bytes_left
+ sizeof(scan_rsp->bss_descript_size)
+ sizeof(scan_rsp->number_of_sets)
+ S_DS_GEN);
tlv_data = (struct mwifiex_ie_types_data *) (scan_rsp->
bss_desc_and_tlv_buffer +
bytes_left);
mwifiex_ret_802_11_scan_get_tlv_ptrs(adapter, tlv_data, tlv_buf_size,
TLV_TYPE_TSFTIMESTAMP,
(struct mwifiex_ie_types_data **)
&tsf_tlv);
mwifiex_ret_802_11_scan_get_tlv_ptrs(adapter, tlv_data, tlv_buf_size,
TLV_TYPE_CHANNELBANDLIST,
(struct mwifiex_ie_types_data **)
&chan_band_tlv);
bss_new_entry = kzalloc(sizeof(struct mwifiex_bssdescriptor),
GFP_KERNEL);
if (!bss_new_entry) {
dev_err(adapter->dev, " failed to alloc bss_new_entry\n");
return -ENOMEM;
}
for (idx = 0; idx < scan_rsp->number_of_sets && bytes_left; idx++) {
memset(bss_new_entry, 0x00,
sizeof(struct mwifiex_bssdescriptor));
if (mwifiex_interpret_bss_desc_with_ie(adapter, bss_new_entry,
&bss_info,
&bytes_left)) {
dev_err(adapter->dev, "SCAN_RESP: "
"mwifiex_interpret_bss_desc_with_ie "
"returned ERROR\n");
continue;
}
dev_dbg(adapter->dev, "info: SCAN_RESP: BSSID = %pM\n",
bss_new_entry->mac_address);
for (bss_idx = 0; bss_idx < num_in_table; bss_idx++) {
if (memcmp(bss_new_entry->mac_address,
adapter->scan_table[bss_idx].mac_address,
sizeof(bss_new_entry->mac_address))) {
continue;
}
if ((bss_new_entry->ssid.ssid_len
== adapter->scan_table[bss_idx]. ssid.ssid_len)
&& (!memcmp(bss_new_entry->ssid.ssid,
adapter->scan_table[bss_idx].ssid.ssid,
bss_new_entry->ssid.ssid_len))) {
dev_dbg(adapter->dev, "info: SCAN_RESP:"
" duplicate of index: %d\n", bss_idx);
break;
}
}
if (bss_idx == num_in_table) {
if (bss_idx == IW_MAX_AP)
bss_idx--;
else
num_in_table++;
}
mwifiex_ret_802_11_scan_store_beacon(priv, bss_idx,
num_in_table, bss_new_entry);
if (tsf_tlv) {
memcpy(&tsf_val, &tsf_tlv->tsf_data[idx * TSF_DATA_SIZE]
, sizeof(tsf_val));
memcpy(&bss_new_entry->network_tsf, &tsf_val,
sizeof(bss_new_entry->network_tsf));
}
band = BAND_G;
if (chan_band_tlv) {
chan_band = &chan_band_tlv->chan_band_param[idx];
band = mwifiex_radio_type_to_band(chan_band->radio_type
& (BIT(0) | BIT(1)));
}
bss_new_entry->bss_band = band;
cfp = mwifiex_get_cfp_by_band_and_channel_from_cfg80211(priv,
(u8) bss_new_entry->bss_band,
(u16)bss_new_entry->channel);
if (cfp)
bss_new_entry->freq = cfp->freq;
else
bss_new_entry->freq = 0;
memcpy(&adapter->scan_table[bss_idx], bss_new_entry,
sizeof(adapter->scan_table[bss_idx]));
}
dev_dbg(adapter->dev,
"info: SCAN_RESP: Scanned %2d APs, %d valid, %d total\n",
scan_rsp->number_of_sets,
num_in_table - adapter->num_in_scan_table, num_in_table);
adapter->num_in_scan_table = num_in_table;
spin_lock_irqsave(&adapter->scan_pending_q_lock, flags);
if (list_empty(&adapter->scan_pending_q)) {
spin_unlock_irqrestore(&adapter->scan_pending_q_lock, flags);
spin_lock_irqsave(&adapter->mwifiex_cmd_lock, flags);
adapter->scan_processing = false;
spin_unlock_irqrestore(&adapter->mwifiex_cmd_lock, flags);
mwifiex_process_scan_results(priv);
if (adapter->curr_cmd->wait_q_enabled) {
adapter->cmd_wait_q.status = 0;
mwifiex_complete_cmd(adapter);
}
if (priv->report_scan_result)
priv->report_scan_result = false;
if (priv->scan_pending_on_block) {
priv->scan_pending_on_block = false;
up(&priv->async_sem);
}
} else {
cmd_node = list_first_entry(&adapter->scan_pending_q,
struct cmd_ctrl_node, list);
list_del(&cmd_node->list);
spin_unlock_irqrestore(&adapter->scan_pending_q_lock, flags);
mwifiex_insert_cmd_to_pending_q(adapter, cmd_node, true);
}
done:
kfree((u8 *) bss_new_entry);
return ret;
}
int mwifiex_cmd_802_11_bg_scan_query(struct host_cmd_ds_command *cmd)
{
struct host_cmd_ds_802_11_bg_scan_query *bg_query =
&cmd->params.bg_scan_query;
cmd->command = cpu_to_le16(HostCmd_CMD_802_11_BG_SCAN_QUERY);
cmd->size = cpu_to_le16(sizeof(struct host_cmd_ds_802_11_bg_scan_query)
+ S_DS_GEN);
bg_query->flush = 1;
return 0;
}
s32
mwifiex_find_ssid_in_list(struct mwifiex_private *priv,
struct mwifiex_802_11_ssid *ssid, u8 *bssid,
u32 mode)
{
struct mwifiex_adapter *adapter = priv->adapter;
s32 net = -1, j;
u8 best_rssi = 0;
u32 i;
dev_dbg(adapter->dev, "info: num of entries in table = %d\n",
adapter->num_in_scan_table);
for (i = 0;
i < adapter->num_in_scan_table && (!bssid || (bssid && net < 0));
i++) {
if (!mwifiex_ssid_cmp(&adapter->scan_table[i].ssid, ssid) &&
(!bssid
|| !memcmp(adapter->scan_table[i].mac_address, bssid,
ETH_ALEN))
&&
(mwifiex_get_cfp_by_band_and_channel_from_cfg80211
(priv, (u8) adapter->scan_table[i].bss_band,
(u16) adapter->scan_table[i].channel))) {
switch (mode) {
case NL80211_IFTYPE_STATION:
case NL80211_IFTYPE_ADHOC:
j = mwifiex_is_network_compatible(priv, i,
mode);
if (j >= 0) {
if (SCAN_RSSI
(adapter->scan_table[i].rssi) >
best_rssi) {
best_rssi = SCAN_RSSI(adapter->
scan_table
[i].rssi);
net = i;
}
} else {
if (net == -1)
net = j;
}
break;
case NL80211_IFTYPE_UNSPECIFIED:
default:
if (SCAN_RSSI(adapter->scan_table[i].rssi) >
best_rssi) {
best_rssi = SCAN_RSSI(adapter->
scan_table[i].rssi);
net = i;
}
break;
}
}
}
return net;
}
s32
mwifiex_find_bssid_in_list(struct mwifiex_private *priv, u8 *bssid,
u32 mode)
{
struct mwifiex_adapter *adapter = priv->adapter;
s32 net = -1;
u32 i;
if (!bssid)
return -1;
dev_dbg(adapter->dev, "info: FindBSSID: Num of BSSIDs = %d\n",
adapter->num_in_scan_table);
for (i = 0; net < 0 && i < adapter->num_in_scan_table; i++) {
if (!memcmp
(adapter->scan_table[i].mac_address, bssid, ETH_ALEN)
&& mwifiex_get_cfp_by_band_and_channel_from_cfg80211
(priv,
(u8) adapter->
scan_table[i].
bss_band,
(u16) adapter->
scan_table[i].
channel)) {
switch (mode) {
case NL80211_IFTYPE_STATION:
case NL80211_IFTYPE_ADHOC:
net = mwifiex_is_network_compatible(priv, i,
mode);
break;
default:
net = i;
break;
}
}
}
return net;
}
void
mwifiex_queue_scan_cmd(struct mwifiex_private *priv,
struct cmd_ctrl_node *cmd_node)
{
struct mwifiex_adapter *adapter = priv->adapter;
unsigned long flags;
cmd_node->wait_q_enabled = true;
spin_lock_irqsave(&adapter->scan_pending_q_lock, flags);
list_add_tail(&cmd_node->list, &adapter->scan_pending_q);
spin_unlock_irqrestore(&adapter->scan_pending_q_lock, flags);
}
int mwifiex_find_best_network(struct mwifiex_private *priv,
struct mwifiex_ssid_bssid *req_ssid_bssid)
{
struct mwifiex_adapter *adapter = priv->adapter;
struct mwifiex_bssdescriptor *req_bss;
s32 i;
memset(req_ssid_bssid, 0, sizeof(struct mwifiex_ssid_bssid));
i = mwifiex_find_best_network_in_list(priv);
if (i >= 0) {
req_bss = &adapter->scan_table[i];
memcpy(&req_ssid_bssid->ssid, &req_bss->ssid,
sizeof(struct mwifiex_802_11_ssid));
memcpy((u8 *) &req_ssid_bssid->bssid,
(u8 *) &req_bss->mac_address, ETH_ALEN);
if (priv->bss_mode == NL80211_IFTYPE_UNSPECIFIED)
priv->bss_mode = req_bss->bss_mode;
}
if (!req_ssid_bssid->ssid.ssid_len)
return -1;
dev_dbg(adapter->dev, "info: Best network found = [%s], "
"[%pM]\n", req_ssid_bssid->ssid.ssid,
req_ssid_bssid->bssid);
return 0;
}
static int mwifiex_scan_specific_ssid(struct mwifiex_private *priv,
struct mwifiex_802_11_ssid *req_ssid)
{
struct mwifiex_adapter *adapter = priv->adapter;
int ret = 0;
struct mwifiex_user_scan_cfg *scan_cfg;
if (!req_ssid)
return -1;
if (adapter->scan_processing) {
dev_dbg(adapter->dev, "cmd: Scan already in process...\n");
return ret;
}
if (priv->scan_block) {
dev_dbg(adapter->dev,
"cmd: Scan is blocked during association...\n");
return ret;
}
mwifiex_scan_delete_ssid_table_entry(priv, req_ssid);
scan_cfg = kzalloc(sizeof(struct mwifiex_user_scan_cfg), GFP_KERNEL);
if (!scan_cfg) {
dev_err(adapter->dev, "failed to alloc scan_cfg\n");
return -ENOMEM;
}
memcpy(scan_cfg->ssid_list[0].ssid, req_ssid->ssid,
req_ssid->ssid_len);
scan_cfg->keep_previous_scan = true;
ret = mwifiex_scan_networks(priv, scan_cfg);
kfree(scan_cfg);
return ret;
}
int mwifiex_request_scan(struct mwifiex_private *priv,
struct mwifiex_802_11_ssid *req_ssid)
{
int ret;
if (down_interruptible(&priv->async_sem)) {
dev_err(priv->adapter->dev, "%s: acquire semaphore\n",
__func__);
return -1;
}
priv->scan_pending_on_block = true;
priv->adapter->cmd_wait_q.condition = false;
if (req_ssid && req_ssid->ssid_len != 0)
ret = mwifiex_scan_specific_ssid(priv, req_ssid);
else
ret = mwifiex_scan_networks(priv, NULL);
if (!ret)
ret = mwifiex_wait_queue_complete(priv->adapter);
if (ret == -1) {
priv->scan_pending_on_block = false;
up(&priv->async_sem);
}
return ret;
}
int
mwifiex_cmd_append_vsie_tlv(struct mwifiex_private *priv,
u16 vsie_mask, u8 **buffer)
{
int id, ret_len = 0;
struct mwifiex_ie_types_vendor_param_set *vs_param_set;
if (!buffer)
return 0;
if (!(*buffer))
return 0;
for (id = 0; id < MWIFIEX_MAX_VSIE_NUM; id++) {
if (priv->vs_ie[id].mask & vsie_mask) {
vs_param_set =
(struct mwifiex_ie_types_vendor_param_set *)
*buffer;
vs_param_set->header.type =
cpu_to_le16(TLV_TYPE_PASSTHROUGH);
vs_param_set->header.len =
cpu_to_le16((((u16) priv->vs_ie[id].ie[1])
& 0x00FF) + 2);
memcpy(vs_param_set->ie, priv->vs_ie[id].ie,
le16_to_cpu(vs_param_set->header.len));
*buffer += le16_to_cpu(vs_param_set->header.len) +
sizeof(struct mwifiex_ie_types_header);
ret_len += le16_to_cpu(vs_param_set->header.len) +
sizeof(struct mwifiex_ie_types_header);
}
}
return ret_len;
}
void
mwifiex_save_curr_bcn(struct mwifiex_private *priv)
{
struct mwifiex_bssdescriptor *curr_bss =
&priv->curr_bss_params.bss_descriptor;
if (!curr_bss->beacon_buf_size)
return;
if (!priv->curr_bcn_buf ||
priv->curr_bcn_size != curr_bss->beacon_buf_size) {
priv->curr_bcn_size = curr_bss->beacon_buf_size;
kfree(priv->curr_bcn_buf);
priv->curr_bcn_buf = kzalloc(curr_bss->beacon_buf_size,
GFP_KERNEL);
if (!priv->curr_bcn_buf) {
dev_err(priv->adapter->dev,
"failed to alloc curr_bcn_buf\n");
return;
}
}
memcpy(priv->curr_bcn_buf, curr_bss->beacon_buf,
curr_bss->beacon_buf_size);
dev_dbg(priv->adapter->dev, "info: current beacon saved %d\n",
priv->curr_bcn_size);
}
void
mwifiex_free_curr_bcn(struct mwifiex_private *priv)
{
kfree(priv->curr_bcn_buf);
priv->curr_bcn_buf = NULL;
}
