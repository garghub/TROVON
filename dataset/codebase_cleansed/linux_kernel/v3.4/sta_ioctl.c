int mwifiex_copy_mcast_addr(struct mwifiex_multicast_list *mlist,
struct net_device *dev)
{
int i = 0;
struct netdev_hw_addr *ha;
netdev_for_each_mc_addr(ha, dev)
memcpy(&mlist->mac_list[i++], ha->addr, ETH_ALEN);
return i;
}
int mwifiex_wait_queue_complete(struct mwifiex_adapter *adapter)
{
bool cancel_flag = false;
int status;
struct cmd_ctrl_node *cmd_queued;
if (!adapter->cmd_queued)
return 0;
cmd_queued = adapter->cmd_queued;
adapter->cmd_queued = NULL;
dev_dbg(adapter->dev, "cmd pending\n");
atomic_inc(&adapter->cmd_pending);
queue_work(adapter->workqueue, &adapter->main_work);
wait_event_interruptible(adapter->cmd_wait_q.wait,
*(cmd_queued->condition));
if (!*(cmd_queued->condition))
cancel_flag = true;
if (cancel_flag) {
mwifiex_cancel_pending_ioctl(adapter);
dev_dbg(adapter->dev, "cmd cancel\n");
}
status = adapter->cmd_wait_q.status;
adapter->cmd_wait_q.status = 0;
return status;
}
int mwifiex_request_set_multicast_list(struct mwifiex_private *priv,
struct mwifiex_multicast_list *mcast_list)
{
int ret = 0;
u16 old_pkt_filter;
old_pkt_filter = priv->curr_pkt_filter;
if (mcast_list->mode == MWIFIEX_PROMISC_MODE) {
dev_dbg(priv->adapter->dev, "info: Enable Promiscuous mode\n");
priv->curr_pkt_filter |= HostCmd_ACT_MAC_PROMISCUOUS_ENABLE;
priv->curr_pkt_filter &=
~HostCmd_ACT_MAC_ALL_MULTICAST_ENABLE;
} else {
priv->curr_pkt_filter &= ~HostCmd_ACT_MAC_PROMISCUOUS_ENABLE;
if (mcast_list->mode == MWIFIEX_MULTICAST_MODE) {
dev_dbg(priv->adapter->dev,
"info: Enabling All Multicast!\n");
priv->curr_pkt_filter |=
HostCmd_ACT_MAC_ALL_MULTICAST_ENABLE;
} else {
priv->curr_pkt_filter &=
~HostCmd_ACT_MAC_ALL_MULTICAST_ENABLE;
if (mcast_list->num_multicast_addr) {
dev_dbg(priv->adapter->dev,
"info: Set multicast list=%d\n",
mcast_list->num_multicast_addr);
if (old_pkt_filter == priv->curr_pkt_filter) {
ret = mwifiex_send_cmd_async(priv,
HostCmd_CMD_MAC_MULTICAST_ADR,
HostCmd_ACT_GEN_SET, 0,
mcast_list);
} else {
ret = mwifiex_send_cmd_async(priv,
HostCmd_CMD_MAC_MULTICAST_ADR,
HostCmd_ACT_GEN_SET, 0,
mcast_list);
}
}
}
}
dev_dbg(priv->adapter->dev,
"info: old_pkt_filter=%#x, curr_pkt_filter=%#x\n",
old_pkt_filter, priv->curr_pkt_filter);
if (old_pkt_filter != priv->curr_pkt_filter) {
ret = mwifiex_send_cmd_async(priv, HostCmd_CMD_MAC_CONTROL,
HostCmd_ACT_GEN_SET,
0, &priv->curr_pkt_filter);
}
return ret;
}
int mwifiex_fill_new_bss_desc(struct mwifiex_private *priv,
u8 *bssid, s32 rssi, u8 *ie_buf,
size_t ie_len, u16 beacon_period,
u16 cap_info_bitmap, u8 band,
struct mwifiex_bssdescriptor *bss_desc)
{
int ret;
memcpy(bss_desc->mac_address, bssid, ETH_ALEN);
bss_desc->rssi = rssi;
bss_desc->beacon_buf = ie_buf;
bss_desc->beacon_buf_size = ie_len;
bss_desc->beacon_period = beacon_period;
bss_desc->cap_info_bitmap = cap_info_bitmap;
bss_desc->bss_band = band;
if (bss_desc->cap_info_bitmap & WLAN_CAPABILITY_PRIVACY) {
dev_dbg(priv->adapter->dev, "info: InterpretIE: AP WEP enabled\n");
bss_desc->privacy = MWIFIEX_802_11_PRIV_FILTER_8021X_WEP;
} else {
bss_desc->privacy = MWIFIEX_802_11_PRIV_FILTER_ACCEPT_ALL;
}
if (bss_desc->cap_info_bitmap & WLAN_CAPABILITY_IBSS)
bss_desc->bss_mode = NL80211_IFTYPE_ADHOC;
else
bss_desc->bss_mode = NL80211_IFTYPE_STATION;
ret = mwifiex_update_bss_desc_with_ie(priv->adapter, bss_desc,
ie_buf, ie_len);
return ret;
}
int mwifiex_bss_start(struct mwifiex_private *priv, struct cfg80211_bss *bss,
struct cfg80211_ssid *req_ssid)
{
int ret;
struct mwifiex_adapter *adapter = priv->adapter;
struct mwifiex_bssdescriptor *bss_desc = NULL;
u8 *beacon_ie = NULL;
priv->scan_block = false;
if (bss) {
bss_desc = kzalloc(sizeof(struct mwifiex_bssdescriptor),
GFP_KERNEL);
if (!bss_desc) {
dev_err(priv->adapter->dev, " failed to alloc bss_desc\n");
return -ENOMEM;
}
beacon_ie = kmemdup(bss->information_elements,
bss->len_beacon_ies, GFP_KERNEL);
if (!beacon_ie) {
kfree(bss_desc);
dev_err(priv->adapter->dev, " failed to alloc beacon_ie\n");
return -ENOMEM;
}
ret = mwifiex_fill_new_bss_desc(priv, bss->bssid, bss->signal,
beacon_ie, bss->len_beacon_ies,
bss->beacon_interval,
bss->capability,
*(u8 *)bss->priv, bss_desc);
if (ret)
goto done;
}
if (priv->bss_mode == NL80211_IFTYPE_STATION) {
ret = mwifiex_deauthenticate(priv, NULL);
if (ret)
goto done;
ret = mwifiex_check_network_compatibility(priv, bss_desc);
if (ret)
goto done;
dev_dbg(adapter->dev, "info: SSID found in scan list ... "
"associating...\n");
if (!netif_queue_stopped(priv->netdev))
mwifiex_stop_net_dev_queue(priv->netdev, adapter);
if (netif_carrier_ok(priv->netdev))
netif_carrier_off(priv->netdev);
priv->assoc_rsp_size = 0;
ret = mwifiex_associate(priv, bss_desc);
if (ret == WLAN_STATUS_NOT_SUPPORTED_AUTH_ALG &&
priv->sec_info.is_authtype_auto &&
priv->sec_info.wep_enabled) {
priv->sec_info.authentication_mode =
NL80211_AUTHTYPE_SHARED_KEY;
ret = mwifiex_associate(priv, bss_desc);
}
if (bss)
cfg80211_put_bss(bss);
} else {
if (bss_desc && bss_desc->ssid.ssid_len &&
(!mwifiex_ssid_cmp(&priv->curr_bss_params.bss_descriptor.
ssid, &bss_desc->ssid))) {
kfree(bss_desc);
kfree(beacon_ie);
return 0;
}
dev_dbg(adapter->dev, "info: Sending Adhoc Stop\n");
ret = mwifiex_deauthenticate(priv, NULL);
if (ret)
goto done;
priv->adhoc_is_link_sensed = false;
ret = mwifiex_check_network_compatibility(priv, bss_desc);
if (!netif_queue_stopped(priv->netdev))
mwifiex_stop_net_dev_queue(priv->netdev, adapter);
if (netif_carrier_ok(priv->netdev))
netif_carrier_off(priv->netdev);
if (!ret) {
dev_dbg(adapter->dev, "info: network found in scan"
" list. Joining...\n");
ret = mwifiex_adhoc_join(priv, bss_desc);
if (bss)
cfg80211_put_bss(bss);
} else {
dev_dbg(adapter->dev, "info: Network not found in "
"the list, creating adhoc with ssid = %s\n",
req_ssid->ssid);
ret = mwifiex_adhoc_start(priv, req_ssid);
}
}
done:
kfree(bss_desc);
kfree(beacon_ie);
return ret;
}
static int mwifiex_set_hs_params(struct mwifiex_private *priv, u16 action,
int cmd_type, struct mwifiex_ds_hs_cfg *hs_cfg)
{
struct mwifiex_adapter *adapter = priv->adapter;
int status = 0;
u32 prev_cond = 0;
if (!hs_cfg)
return -ENOMEM;
switch (action) {
case HostCmd_ACT_GEN_SET:
if (adapter->pps_uapsd_mode) {
dev_dbg(adapter->dev, "info: Host Sleep IOCTL"
" is blocked in UAPSD/PPS mode\n");
status = -1;
break;
}
if (hs_cfg->is_invoke_hostcmd) {
if (hs_cfg->conditions == HOST_SLEEP_CFG_CANCEL) {
if (!adapter->is_hs_configured)
break;
prev_cond = le32_to_cpu(adapter->hs_cfg
.conditions);
adapter->hs_cfg.conditions =
cpu_to_le32(hs_cfg->conditions);
} else if (hs_cfg->conditions) {
adapter->hs_cfg.conditions =
cpu_to_le32(hs_cfg->conditions);
adapter->hs_cfg.gpio = (u8)hs_cfg->gpio;
if (hs_cfg->gap)
adapter->hs_cfg.gap = (u8)hs_cfg->gap;
} else if (adapter->hs_cfg.conditions
== cpu_to_le32(HOST_SLEEP_CFG_CANCEL)) {
status = -1;
break;
}
if (cmd_type == MWIFIEX_SYNC_CMD)
status = mwifiex_send_cmd_sync(priv,
HostCmd_CMD_802_11_HS_CFG_ENH,
HostCmd_ACT_GEN_SET, 0,
&adapter->hs_cfg);
else
status = mwifiex_send_cmd_async(priv,
HostCmd_CMD_802_11_HS_CFG_ENH,
HostCmd_ACT_GEN_SET, 0,
&adapter->hs_cfg);
if (hs_cfg->conditions == HOST_SLEEP_CFG_CANCEL)
adapter->hs_cfg.conditions =
cpu_to_le32(prev_cond);
} else {
adapter->hs_cfg.conditions =
cpu_to_le32(hs_cfg->conditions);
adapter->hs_cfg.gpio = (u8)hs_cfg->gpio;
adapter->hs_cfg.gap = (u8)hs_cfg->gap;
}
break;
case HostCmd_ACT_GEN_GET:
hs_cfg->conditions = le32_to_cpu(adapter->hs_cfg.conditions);
hs_cfg->gpio = adapter->hs_cfg.gpio;
hs_cfg->gap = adapter->hs_cfg.gap;
break;
default:
status = -1;
break;
}
return status;
}
int mwifiex_cancel_hs(struct mwifiex_private *priv, int cmd_type)
{
struct mwifiex_ds_hs_cfg hscfg;
hscfg.conditions = HOST_SLEEP_CFG_CANCEL;
hscfg.is_invoke_hostcmd = true;
return mwifiex_set_hs_params(priv, HostCmd_ACT_GEN_SET,
cmd_type, &hscfg);
}
int mwifiex_enable_hs(struct mwifiex_adapter *adapter)
{
struct mwifiex_ds_hs_cfg hscfg;
if (adapter->hs_activated) {
dev_dbg(adapter->dev, "cmd: HS Already actived\n");
return true;
}
adapter->hs_activate_wait_q_woken = false;
memset(&hscfg, 0, sizeof(struct mwifiex_ds_hs_cfg));
hscfg.is_invoke_hostcmd = true;
if (mwifiex_set_hs_params(mwifiex_get_priv(adapter,
MWIFIEX_BSS_ROLE_STA),
HostCmd_ACT_GEN_SET, MWIFIEX_SYNC_CMD,
&hscfg)) {
dev_err(adapter->dev, "IOCTL request HS enable failed\n");
return false;
}
wait_event_interruptible(adapter->hs_activate_wait_q,
adapter->hs_activate_wait_q_woken);
return true;
}
int mwifiex_get_bss_info(struct mwifiex_private *priv,
struct mwifiex_bss_info *info)
{
struct mwifiex_adapter *adapter = priv->adapter;
struct mwifiex_bssdescriptor *bss_desc;
if (!info)
return -1;
bss_desc = &priv->curr_bss_params.bss_descriptor;
info->bss_mode = priv->bss_mode;
memcpy(&info->ssid, &bss_desc->ssid, sizeof(struct cfg80211_ssid));
memcpy(&info->bssid, &bss_desc->mac_address, ETH_ALEN);
info->bss_chan = bss_desc->channel;
info->region_code = adapter->region_code;
info->media_connected = priv->media_connected;
info->max_power_level = priv->max_tx_power_level;
info->min_power_level = priv->min_tx_power_level;
info->adhoc_state = priv->adhoc_state;
info->bcn_nf_last = priv->bcn_nf_last;
if (priv->sec_info.wep_enabled)
info->wep_status = true;
else
info->wep_status = false;
info->is_hs_configured = adapter->is_hs_configured;
info->is_deep_sleep = adapter->is_deep_sleep;
return 0;
}
int mwifiex_disable_auto_ds(struct mwifiex_private *priv)
{
struct mwifiex_ds_auto_ds auto_ds;
auto_ds.auto_ds = DEEP_SLEEP_OFF;
return mwifiex_send_cmd_sync(priv, HostCmd_CMD_802_11_PS_MODE_ENH,
DIS_AUTO_PS, BITMAP_AUTO_DS, &auto_ds);
}
int mwifiex_bss_set_channel(struct mwifiex_private *priv,
struct mwifiex_chan_freq_power *chan)
{
struct mwifiex_adapter *adapter = priv->adapter;
struct mwifiex_chan_freq_power *cfp = NULL;
if (!chan)
return -1;
if (!chan->channel && !chan->freq)
return -1;
if (adapter->adhoc_start_band & BAND_AN)
adapter->adhoc_start_band = BAND_G | BAND_B | BAND_GN;
else if (adapter->adhoc_start_band & BAND_A)
adapter->adhoc_start_band = BAND_G | BAND_B;
if (chan->channel) {
if (chan->channel <= MAX_CHANNEL_BAND_BG)
cfp = mwifiex_get_cfp(priv, 0, (u16) chan->channel, 0);
if (!cfp) {
cfp = mwifiex_get_cfp(priv, BAND_A,
(u16) chan->channel, 0);
if (cfp) {
if (adapter->adhoc_11n_enabled)
adapter->adhoc_start_band = BAND_A
| BAND_AN;
else
adapter->adhoc_start_band = BAND_A;
}
}
} else {
if (chan->freq <= MAX_FREQUENCY_BAND_BG)
cfp = mwifiex_get_cfp(priv, 0, 0, chan->freq);
if (!cfp) {
cfp = mwifiex_get_cfp(priv, BAND_A, 0, chan->freq);
if (cfp) {
if (adapter->adhoc_11n_enabled)
adapter->adhoc_start_band = BAND_A
| BAND_AN;
else
adapter->adhoc_start_band = BAND_A;
}
}
}
if (!cfp || !cfp->channel) {
dev_err(adapter->dev, "invalid channel/freq\n");
return -1;
}
priv->adhoc_channel = (u8) cfp->channel;
chan->channel = cfp->channel;
chan->freq = cfp->freq;
return 0;
}
static int mwifiex_bss_ioctl_ibss_channel(struct mwifiex_private *priv,
u16 action, u16 *channel)
{
if (action == HostCmd_ACT_GEN_GET) {
if (!priv->media_connected) {
*channel = priv->adhoc_channel;
return 0;
}
} else {
priv->adhoc_channel = (u8) *channel;
}
return mwifiex_send_cmd_sync(priv, HostCmd_CMD_802_11_RF_CHANNEL,
action, 0, channel);
}
int
mwifiex_drv_change_adhoc_chan(struct mwifiex_private *priv, u16 channel)
{
int ret;
struct mwifiex_bss_info bss_info;
struct mwifiex_ssid_bssid ssid_bssid;
u16 curr_chan = 0;
struct cfg80211_bss *bss = NULL;
struct ieee80211_channel *chan;
enum ieee80211_band band;
memset(&bss_info, 0, sizeof(bss_info));
if (mwifiex_get_bss_info(priv, &bss_info))
return -1;
ret = mwifiex_bss_ioctl_ibss_channel(priv, HostCmd_ACT_GEN_GET,
&curr_chan);
if (curr_chan == channel) {
ret = 0;
goto done;
}
dev_dbg(priv->adapter->dev, "cmd: updating channel from %d to %d\n",
curr_chan, channel);
if (!bss_info.media_connected) {
ret = 0;
goto done;
}
memset(&ssid_bssid, 0, ETH_ALEN);
ret = mwifiex_deauthenticate(priv, ssid_bssid.bssid);
ret = mwifiex_bss_ioctl_ibss_channel(priv, HostCmd_ACT_GEN_SET,
&channel);
if (mwifiex_request_scan(priv, &bss_info.ssid)) {
ret = -1;
goto done;
}
band = mwifiex_band_to_radio_type(priv->curr_bss_params.band);
chan = __ieee80211_get_channel(priv->wdev->wiphy,
ieee80211_channel_to_frequency(channel,
band));
bss = cfg80211_get_bss(priv->wdev->wiphy, chan, bss_info.bssid,
bss_info.ssid.ssid, bss_info.ssid.ssid_len,
WLAN_CAPABILITY_ESS, WLAN_CAPABILITY_ESS);
if (!bss)
wiphy_warn(priv->wdev->wiphy, "assoc: bss %pM not in scan results\n",
bss_info.bssid);
ret = mwifiex_bss_start(priv, bss, &bss_info.ssid);
done:
return ret;
}
static int mwifiex_rate_ioctl_get_rate_value(struct mwifiex_private *priv,
struct mwifiex_rate_cfg *rate_cfg)
{
rate_cfg->is_rate_auto = priv->is_data_rate_auto;
return mwifiex_send_cmd_sync(priv, HostCmd_CMD_802_11_TX_RATE_QUERY,
HostCmd_ACT_GEN_GET, 0, NULL);
}
static int mwifiex_rate_ioctl_set_rate_value(struct mwifiex_private *priv,
struct mwifiex_rate_cfg *rate_cfg)
{
u8 rates[MWIFIEX_SUPPORTED_RATES];
u8 *rate;
int rate_index, ret;
u16 bitmap_rates[MAX_BITMAP_RATES_SIZE];
u32 i;
struct mwifiex_adapter *adapter = priv->adapter;
if (rate_cfg->is_rate_auto) {
memset(bitmap_rates, 0, sizeof(bitmap_rates));
bitmap_rates[0] = 0x000F;
bitmap_rates[1] = 0x00FF;
for (i = 0; i < ARRAY_SIZE(priv->bitmap_rates) - 3; i++)
bitmap_rates[i + 2] = 0xFFFF;
bitmap_rates[9] = 0x3FFF;
} else {
memset(rates, 0, sizeof(rates));
mwifiex_get_active_data_rates(priv, rates);
rate = rates;
for (i = 0; (rate[i] && i < MWIFIEX_SUPPORTED_RATES); i++) {
dev_dbg(adapter->dev, "info: rate=%#x wanted=%#x\n",
rate[i], rate_cfg->rate);
if ((rate[i] & 0x7f) == (rate_cfg->rate & 0x7f))
break;
}
if ((i == MWIFIEX_SUPPORTED_RATES) || !rate[i]) {
dev_err(adapter->dev, "fixed data rate %#x is out "
"of range\n", rate_cfg->rate);
return -1;
}
memset(bitmap_rates, 0, sizeof(bitmap_rates));
rate_index = mwifiex_data_rate_to_index(rate_cfg->rate);
if (rate_index >= MWIFIEX_RATE_INDEX_HRDSSS0 &&
rate_index <= MWIFIEX_RATE_INDEX_HRDSSS3) {
bitmap_rates[0] = 1 << rate_index;
} else {
rate_index -= 1;
if (rate_index >= MWIFIEX_RATE_INDEX_OFDM0 &&
rate_index <= MWIFIEX_RATE_INDEX_OFDM7)
bitmap_rates[1] = 1 << (rate_index -
MWIFIEX_RATE_INDEX_OFDM0);
}
}
ret = mwifiex_send_cmd_sync(priv, HostCmd_CMD_TX_RATE_CFG,
HostCmd_ACT_GEN_SET, 0, bitmap_rates);
return ret;
}
static int mwifiex_rate_ioctl_cfg(struct mwifiex_private *priv,
struct mwifiex_rate_cfg *rate_cfg)
{
int status;
if (!rate_cfg)
return -1;
if (rate_cfg->action == HostCmd_ACT_GEN_GET)
status = mwifiex_rate_ioctl_get_rate_value(priv, rate_cfg);
else
status = mwifiex_rate_ioctl_set_rate_value(priv, rate_cfg);
return status;
}
int mwifiex_drv_get_data_rate(struct mwifiex_private *priv,
struct mwifiex_rate_cfg *rate)
{
int ret;
memset(rate, 0, sizeof(struct mwifiex_rate_cfg));
rate->action = HostCmd_ACT_GEN_GET;
ret = mwifiex_rate_ioctl_cfg(priv, rate);
if (!ret) {
if (rate->is_rate_auto)
rate->rate = mwifiex_index_to_data_rate(priv,
priv->tx_rate,
priv->tx_htinfo
);
else
rate->rate = priv->data_rate;
} else {
ret = -1;
}
return ret;
}
int mwifiex_set_tx_power(struct mwifiex_private *priv,
struct mwifiex_power_cfg *power_cfg)
{
int ret;
struct host_cmd_ds_txpwr_cfg *txp_cfg;
struct mwifiex_types_power_group *pg_tlv;
struct mwifiex_power_group *pg;
u8 *buf;
u16 dbm = 0;
if (!power_cfg->is_power_auto) {
dbm = (u16) power_cfg->power_level;
if ((dbm < priv->min_tx_power_level) ||
(dbm > priv->max_tx_power_level)) {
dev_err(priv->adapter->dev, "txpower value %d dBm"
" is out of range (%d dBm-%d dBm)\n",
dbm, priv->min_tx_power_level,
priv->max_tx_power_level);
return -1;
}
}
buf = kzalloc(MWIFIEX_SIZE_OF_CMD_BUFFER, GFP_KERNEL);
if (!buf) {
dev_err(priv->adapter->dev, "%s: failed to alloc cmd buffer\n",
__func__);
return -ENOMEM;
}
txp_cfg = (struct host_cmd_ds_txpwr_cfg *) buf;
txp_cfg->action = cpu_to_le16(HostCmd_ACT_GEN_SET);
if (!power_cfg->is_power_auto) {
txp_cfg->mode = cpu_to_le32(1);
pg_tlv = (struct mwifiex_types_power_group *)
(buf + sizeof(struct host_cmd_ds_txpwr_cfg));
pg_tlv->type = TLV_TYPE_POWER_GROUP;
pg_tlv->length = 4 * sizeof(struct mwifiex_power_group);
pg = (struct mwifiex_power_group *)
(buf + sizeof(struct host_cmd_ds_txpwr_cfg)
+ sizeof(struct mwifiex_types_power_group));
pg->first_rate_code = 0x00;
pg->last_rate_code = 0x03;
pg->modulation_class = MOD_CLASS_HR_DSSS;
pg->power_step = 0;
pg->power_min = (s8) dbm;
pg->power_max = (s8) dbm;
pg++;
pg->first_rate_code = 0x00;
pg->last_rate_code = 0x07;
pg->modulation_class = MOD_CLASS_OFDM;
pg->power_step = 0;
pg->power_min = (s8) dbm;
pg->power_max = (s8) dbm;
pg++;
pg->first_rate_code = 0x00;
pg->last_rate_code = 0x20;
pg->modulation_class = MOD_CLASS_HT;
pg->power_step = 0;
pg->power_min = (s8) dbm;
pg->power_max = (s8) dbm;
pg->ht_bandwidth = HT_BW_20;
pg++;
pg->first_rate_code = 0x00;
pg->last_rate_code = 0x20;
pg->modulation_class = MOD_CLASS_HT;
pg->power_step = 0;
pg->power_min = (s8) dbm;
pg->power_max = (s8) dbm;
pg->ht_bandwidth = HT_BW_40;
}
ret = mwifiex_send_cmd_sync(priv, HostCmd_CMD_TXPWR_CFG,
HostCmd_ACT_GEN_SET, 0, buf);
kfree(buf);
return ret;
}
int mwifiex_drv_set_power(struct mwifiex_private *priv, u32 *ps_mode)
{
int ret;
struct mwifiex_adapter *adapter = priv->adapter;
u16 sub_cmd;
if (*ps_mode)
adapter->ps_mode = MWIFIEX_802_11_POWER_MODE_PSP;
else
adapter->ps_mode = MWIFIEX_802_11_POWER_MODE_CAM;
sub_cmd = (*ps_mode) ? EN_AUTO_PS : DIS_AUTO_PS;
ret = mwifiex_send_cmd_sync(priv, HostCmd_CMD_802_11_PS_MODE_ENH,
sub_cmd, BITMAP_STA_PS, NULL);
if ((!ret) && (sub_cmd == DIS_AUTO_PS))
ret = mwifiex_send_cmd_async(priv,
HostCmd_CMD_802_11_PS_MODE_ENH,
GET_PS, 0, NULL);
return ret;
}
static int mwifiex_set_wpa_ie_helper(struct mwifiex_private *priv,
u8 *ie_data_ptr, u16 ie_len)
{
if (ie_len) {
if (ie_len > sizeof(priv->wpa_ie)) {
dev_err(priv->adapter->dev,
"failed to copy WPA IE, too big\n");
return -1;
}
memcpy(priv->wpa_ie, ie_data_ptr, ie_len);
priv->wpa_ie_len = (u8) ie_len;
dev_dbg(priv->adapter->dev, "cmd: Set Wpa_ie_len=%d IE=%#x\n",
priv->wpa_ie_len, priv->wpa_ie[0]);
if (priv->wpa_ie[0] == WLAN_EID_WPA) {
priv->sec_info.wpa_enabled = true;
} else if (priv->wpa_ie[0] == WLAN_EID_RSN) {
priv->sec_info.wpa2_enabled = true;
} else {
priv->sec_info.wpa_enabled = false;
priv->sec_info.wpa2_enabled = false;
}
} else {
memset(priv->wpa_ie, 0, sizeof(priv->wpa_ie));
priv->wpa_ie_len = 0;
dev_dbg(priv->adapter->dev, "info: reset wpa_ie_len=%d IE=%#x\n",
priv->wpa_ie_len, priv->wpa_ie[0]);
priv->sec_info.wpa_enabled = false;
priv->sec_info.wpa2_enabled = false;
}
return 0;
}
static int mwifiex_set_wapi_ie(struct mwifiex_private *priv,
u8 *ie_data_ptr, u16 ie_len)
{
if (ie_len) {
if (ie_len > sizeof(priv->wapi_ie)) {
dev_dbg(priv->adapter->dev,
"info: failed to copy WAPI IE, too big\n");
return -1;
}
memcpy(priv->wapi_ie, ie_data_ptr, ie_len);
priv->wapi_ie_len = ie_len;
dev_dbg(priv->adapter->dev, "cmd: Set wapi_ie_len=%d IE=%#x\n",
priv->wapi_ie_len, priv->wapi_ie[0]);
if (priv->wapi_ie[0] == WLAN_EID_BSS_AC_ACCESS_DELAY)
priv->sec_info.wapi_enabled = true;
} else {
memset(priv->wapi_ie, 0, sizeof(priv->wapi_ie));
priv->wapi_ie_len = ie_len;
dev_dbg(priv->adapter->dev,
"info: Reset wapi_ie_len=%d IE=%#x\n",
priv->wapi_ie_len, priv->wapi_ie[0]);
priv->sec_info.wapi_enabled = false;
}
return 0;
}
static int mwifiex_sec_ioctl_set_wapi_key(struct mwifiex_private *priv,
struct mwifiex_ds_encrypt_key *encrypt_key)
{
return mwifiex_send_cmd_sync(priv, HostCmd_CMD_802_11_KEY_MATERIAL,
HostCmd_ACT_GEN_SET, KEY_INFO_ENABLED,
encrypt_key);
}
static int mwifiex_sec_ioctl_set_wep_key(struct mwifiex_private *priv,
struct mwifiex_ds_encrypt_key *encrypt_key)
{
int ret;
struct mwifiex_wep_key *wep_key;
int index;
if (priv->wep_key_curr_index >= NUM_WEP_KEYS)
priv->wep_key_curr_index = 0;
wep_key = &priv->wep_key[priv->wep_key_curr_index];
index = encrypt_key->key_index;
if (encrypt_key->key_disable) {
priv->sec_info.wep_enabled = 0;
} else if (!encrypt_key->key_len) {
wep_key = &priv->wep_key[index];
if (!wep_key->key_length) {
dev_err(priv->adapter->dev,
"key not set, so cannot enable it\n");
return -1;
}
priv->wep_key_curr_index = (u16) index;
priv->sec_info.wep_enabled = 1;
} else {
wep_key = &priv->wep_key[index];
memset(wep_key, 0, sizeof(struct mwifiex_wep_key));
memcpy(wep_key->key_material,
encrypt_key->key_material,
encrypt_key->key_len);
wep_key->key_index = index;
wep_key->key_length = encrypt_key->key_len;
priv->sec_info.wep_enabled = 1;
}
if (wep_key->key_length) {
ret = mwifiex_send_cmd_async(priv,
HostCmd_CMD_802_11_KEY_MATERIAL,
HostCmd_ACT_GEN_SET, 0, NULL);
if (ret)
return ret;
}
if (priv->sec_info.wep_enabled)
priv->curr_pkt_filter |= HostCmd_ACT_MAC_WEP_ENABLE;
else
priv->curr_pkt_filter &= ~HostCmd_ACT_MAC_WEP_ENABLE;
ret = mwifiex_send_cmd_sync(priv, HostCmd_CMD_MAC_CONTROL,
HostCmd_ACT_GEN_SET, 0,
&priv->curr_pkt_filter);
return ret;
}
static int mwifiex_sec_ioctl_set_wpa_key(struct mwifiex_private *priv,
struct mwifiex_ds_encrypt_key *encrypt_key)
{
int ret;
u8 remove_key = false;
struct host_cmd_ds_802_11_key_material *ibss_key;
if (encrypt_key->key_len > WLAN_MAX_KEY_LEN) {
dev_err(priv->adapter->dev, "key length too long\n");
return -1;
}
if (priv->bss_mode == NL80211_IFTYPE_ADHOC) {
encrypt_key->key_index = MWIFIEX_KEY_INDEX_UNICAST;
ret = mwifiex_send_cmd_async(priv,
HostCmd_CMD_802_11_KEY_MATERIAL,
HostCmd_ACT_GEN_SET,
KEY_INFO_ENABLED, encrypt_key);
if (ret)
return ret;
ibss_key = &priv->aes_key;
memset(ibss_key, 0,
sizeof(struct host_cmd_ds_802_11_key_material));
memcpy(ibss_key->key_param_set.key, encrypt_key->key_material,
encrypt_key->key_len);
memcpy(&ibss_key->key_param_set.key_len, &encrypt_key->key_len,
sizeof(ibss_key->key_param_set.key_len));
ibss_key->key_param_set.key_type_id
= cpu_to_le16(KEY_TYPE_ID_TKIP);
ibss_key->key_param_set.key_info = cpu_to_le16(KEY_ENABLED);
encrypt_key->key_index = ~MWIFIEX_KEY_INDEX_UNICAST;
}
if (!encrypt_key->key_index)
encrypt_key->key_index = MWIFIEX_KEY_INDEX_UNICAST;
if (remove_key)
ret = mwifiex_send_cmd_sync(priv,
HostCmd_CMD_802_11_KEY_MATERIAL,
HostCmd_ACT_GEN_SET,
!KEY_INFO_ENABLED, encrypt_key);
else
ret = mwifiex_send_cmd_sync(priv,
HostCmd_CMD_802_11_KEY_MATERIAL,
HostCmd_ACT_GEN_SET,
KEY_INFO_ENABLED, encrypt_key);
return ret;
}
static int
mwifiex_sec_ioctl_encrypt_key(struct mwifiex_private *priv,
struct mwifiex_ds_encrypt_key *encrypt_key)
{
int status;
if (encrypt_key->is_wapi_key)
status = mwifiex_sec_ioctl_set_wapi_key(priv, encrypt_key);
else if (encrypt_key->key_len > WLAN_KEY_LEN_WEP104)
status = mwifiex_sec_ioctl_set_wpa_key(priv, encrypt_key);
else
status = mwifiex_sec_ioctl_set_wep_key(priv, encrypt_key);
return status;
}
int
mwifiex_drv_get_driver_version(struct mwifiex_adapter *adapter, char *version,
int max_len)
{
union {
u32 l;
u8 c[4];
} ver;
char fw_ver[32];
ver.l = adapter->fw_release_number;
sprintf(fw_ver, "%u.%u.%u.p%u", ver.c[2], ver.c[1], ver.c[0], ver.c[3]);
snprintf(version, max_len, driver_version, fw_ver);
dev_dbg(adapter->dev, "info: MWIFIEX VERSION: %s\n", version);
return 0;
}
int mwifiex_get_signal_info(struct mwifiex_private *priv,
struct mwifiex_ds_get_signal *signal)
{
int status;
signal->selector = ALL_RSSI_INFO_MASK;
if (!priv->media_connected) {
dev_dbg(priv->adapter->dev,
"info: Can not get signal in disconnected state\n");
return -1;
}
status = mwifiex_send_cmd_sync(priv, HostCmd_CMD_RSSI_INFO,
HostCmd_ACT_GEN_GET, 0, signal);
if (!status) {
if (signal->selector & BCN_RSSI_AVG_MASK)
priv->qual_level = signal->bcn_rssi_avg;
if (signal->selector & BCN_NF_AVG_MASK)
priv->qual_noise = signal->bcn_nf_avg;
}
return status;
}
int mwifiex_set_encode(struct mwifiex_private *priv, const u8 *key,
int key_len, u8 key_index, int disable)
{
struct mwifiex_ds_encrypt_key encrypt_key;
memset(&encrypt_key, 0, sizeof(struct mwifiex_ds_encrypt_key));
encrypt_key.key_len = key_len;
if (!disable) {
encrypt_key.key_index = key_index;
if (key_len)
memcpy(encrypt_key.key_material, key, key_len);
} else {
encrypt_key.key_disable = true;
}
return mwifiex_sec_ioctl_encrypt_key(priv, &encrypt_key);
}
int
mwifiex_get_ver_ext(struct mwifiex_private *priv)
{
struct mwifiex_ver_ext ver_ext;
memset(&ver_ext, 0, sizeof(struct host_cmd_ds_version_ext));
if (mwifiex_send_cmd_sync(priv, HostCmd_CMD_VERSION_EXT,
HostCmd_ACT_GEN_GET, 0, &ver_ext))
return -1;
return 0;
}
int
mwifiex_get_stats_info(struct mwifiex_private *priv,
struct mwifiex_ds_get_stats *log)
{
return mwifiex_send_cmd_sync(priv, HostCmd_CMD_802_11_GET_LOG,
HostCmd_ACT_GEN_GET, 0, log);
}
static int mwifiex_reg_mem_ioctl_reg_rw(struct mwifiex_private *priv,
struct mwifiex_ds_reg_rw *reg_rw,
u16 action)
{
u16 cmd_no;
switch (le32_to_cpu(reg_rw->type)) {
case MWIFIEX_REG_MAC:
cmd_no = HostCmd_CMD_MAC_REG_ACCESS;
break;
case MWIFIEX_REG_BBP:
cmd_no = HostCmd_CMD_BBP_REG_ACCESS;
break;
case MWIFIEX_REG_RF:
cmd_no = HostCmd_CMD_RF_REG_ACCESS;
break;
case MWIFIEX_REG_PMIC:
cmd_no = HostCmd_CMD_PMIC_REG_ACCESS;
break;
case MWIFIEX_REG_CAU:
cmd_no = HostCmd_CMD_CAU_REG_ACCESS;
break;
default:
return -1;
}
return mwifiex_send_cmd_sync(priv, cmd_no, action, 0, reg_rw);
}
int
mwifiex_reg_write(struct mwifiex_private *priv, u32 reg_type,
u32 reg_offset, u32 reg_value)
{
struct mwifiex_ds_reg_rw reg_rw;
reg_rw.type = cpu_to_le32(reg_type);
reg_rw.offset = cpu_to_le32(reg_offset);
reg_rw.value = cpu_to_le32(reg_value);
return mwifiex_reg_mem_ioctl_reg_rw(priv, &reg_rw, HostCmd_ACT_GEN_SET);
}
int
mwifiex_reg_read(struct mwifiex_private *priv, u32 reg_type,
u32 reg_offset, u32 *value)
{
int ret;
struct mwifiex_ds_reg_rw reg_rw;
reg_rw.type = cpu_to_le32(reg_type);
reg_rw.offset = cpu_to_le32(reg_offset);
ret = mwifiex_reg_mem_ioctl_reg_rw(priv, &reg_rw, HostCmd_ACT_GEN_GET);
if (ret)
goto done;
*value = le32_to_cpu(reg_rw.value);
done:
return ret;
}
int
mwifiex_eeprom_read(struct mwifiex_private *priv, u16 offset, u16 bytes,
u8 *value)
{
int ret;
struct mwifiex_ds_read_eeprom rd_eeprom;
rd_eeprom.offset = cpu_to_le16((u16) offset);
rd_eeprom.byte_count = cpu_to_le16((u16) bytes);
ret = mwifiex_send_cmd_sync(priv, HostCmd_CMD_802_11_EEPROM_ACCESS,
HostCmd_ACT_GEN_GET, 0, &rd_eeprom);
if (!ret)
memcpy(value, rd_eeprom.value, MAX_EEPROM_DATA);
return ret;
}
static int
mwifiex_set_gen_ie_helper(struct mwifiex_private *priv, u8 *ie_data_ptr,
u16 ie_len)
{
int ret = 0;
struct ieee_types_vendor_header *pvendor_ie;
const u8 wpa_oui[] = { 0x00, 0x50, 0xf2, 0x01 };
const u8 wps_oui[] = { 0x00, 0x50, 0xf2, 0x04 };
if (!ie_len) {
priv->gen_ie_buf_len = 0;
priv->wps.session_enable = false;
return 0;
} else if (!ie_data_ptr) {
return -1;
}
pvendor_ie = (struct ieee_types_vendor_header *) ie_data_ptr;
if (((pvendor_ie->element_id == WLAN_EID_WPA) &&
(!memcmp(pvendor_ie->oui, wpa_oui, sizeof(wpa_oui)))) ||
(pvendor_ie->element_id == WLAN_EID_RSN)) {
ret = mwifiex_set_wpa_ie_helper(priv, ie_data_ptr, ie_len);
priv->wps.session_enable = false;
return ret;
} else if (pvendor_ie->element_id == WLAN_EID_BSS_AC_ACCESS_DELAY) {
ret = mwifiex_set_wapi_ie(priv, ie_data_ptr, ie_len);
return ret;
}
if (ie_len < (sizeof(priv->gen_ie_buf) - priv->gen_ie_buf_len)) {
pvendor_ie = (struct ieee_types_vendor_header *) ie_data_ptr;
if ((pvendor_ie->element_id == WLAN_EID_VENDOR_SPECIFIC) &&
(!memcmp(pvendor_ie->oui, wps_oui, sizeof(wps_oui)))) {
priv->wps.session_enable = true;
dev_dbg(priv->adapter->dev,
"info: WPS Session Enabled.\n");
}
memcpy(priv->gen_ie_buf + priv->gen_ie_buf_len, ie_data_ptr,
ie_len);
priv->gen_ie_buf_len += ie_len;
} else {
ret = -1;
}
return ret;
}
static int mwifiex_misc_ioctl_gen_ie(struct mwifiex_private *priv,
struct mwifiex_ds_misc_gen_ie *gen_ie,
u16 action)
{
struct mwifiex_adapter *adapter = priv->adapter;
switch (gen_ie->type) {
case MWIFIEX_IE_TYPE_GEN_IE:
if (action == HostCmd_ACT_GEN_GET) {
gen_ie->len = priv->wpa_ie_len;
memcpy(gen_ie->ie_data, priv->wpa_ie, gen_ie->len);
} else {
mwifiex_set_gen_ie_helper(priv, gen_ie->ie_data,
(u16) gen_ie->len);
}
break;
case MWIFIEX_IE_TYPE_ARP_FILTER:
memset(adapter->arp_filter, 0, sizeof(adapter->arp_filter));
if (gen_ie->len > ARP_FILTER_MAX_BUF_SIZE) {
adapter->arp_filter_size = 0;
dev_err(adapter->dev, "invalid ARP filter size\n");
return -1;
} else {
memcpy(adapter->arp_filter, gen_ie->ie_data,
gen_ie->len);
adapter->arp_filter_size = gen_ie->len;
}
break;
default:
dev_err(adapter->dev, "invalid IE type\n");
return -1;
}
return 0;
}
int
mwifiex_set_gen_ie(struct mwifiex_private *priv, u8 *ie, int ie_len)
{
struct mwifiex_ds_misc_gen_ie gen_ie;
if (ie_len > IEEE_MAX_IE_SIZE)
return -EFAULT;
gen_ie.type = MWIFIEX_IE_TYPE_GEN_IE;
gen_ie.len = ie_len;
memcpy(gen_ie.ie_data, ie, ie_len);
if (mwifiex_misc_ioctl_gen_ie(priv, &gen_ie, HostCmd_ACT_GEN_SET))
return -EFAULT;
return 0;
}
