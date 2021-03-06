static enum iwl_bt_coex_lut_type
iwl_get_coex_type(struct iwl_mvm *mvm, const struct ieee80211_vif *vif)
{
struct ieee80211_chanctx_conf *chanctx_conf;
enum iwl_bt_coex_lut_type ret;
u16 phy_ctx_id;
u32 primary_ch_phy_id, secondary_ch_phy_id;
rcu_read_lock();
chanctx_conf = rcu_dereference(vif->chanctx_conf);
if (!chanctx_conf ||
chanctx_conf->def.chan->band != NL80211_BAND_2GHZ) {
rcu_read_unlock();
return BT_COEX_INVALID_LUT;
}
ret = BT_COEX_TX_DIS_LUT;
if (mvm->cfg->bt_shared_single_ant) {
rcu_read_unlock();
return ret;
}
phy_ctx_id = *((u16 *)chanctx_conf->drv_priv);
primary_ch_phy_id = le32_to_cpu(mvm->last_bt_ci_cmd.primary_ch_phy_id);
secondary_ch_phy_id =
le32_to_cpu(mvm->last_bt_ci_cmd.secondary_ch_phy_id);
if (primary_ch_phy_id == phy_ctx_id)
ret = le32_to_cpu(mvm->last_bt_notif.primary_ch_lut);
else if (secondary_ch_phy_id == phy_ctx_id)
ret = le32_to_cpu(mvm->last_bt_notif.secondary_ch_lut);
rcu_read_unlock();
return ret;
}
int iwl_mvm_send_bt_init_conf(struct iwl_mvm *mvm)
{
struct iwl_bt_coex_cmd bt_cmd = {};
u32 mode;
lockdep_assert_held(&mvm->mutex);
if (unlikely(mvm->bt_force_ant_mode != BT_FORCE_ANT_DIS)) {
switch (mvm->bt_force_ant_mode) {
case BT_FORCE_ANT_BT:
mode = BT_COEX_BT;
break;
case BT_FORCE_ANT_WIFI:
mode = BT_COEX_WIFI;
break;
default:
WARN_ON(1);
mode = 0;
}
bt_cmd.mode = cpu_to_le32(mode);
goto send_cmd;
}
mode = iwlwifi_mod_params.bt_coex_active ? BT_COEX_NW : BT_COEX_DISABLE;
bt_cmd.mode = cpu_to_le32(mode);
if (IWL_MVM_BT_COEX_SYNC2SCO)
bt_cmd.enabled_modules |=
cpu_to_le32(BT_COEX_SYNC2SCO_ENABLED);
if (iwl_mvm_is_mplut_supported(mvm))
bt_cmd.enabled_modules |= cpu_to_le32(BT_COEX_MPLUT_ENABLED);
bt_cmd.enabled_modules |= cpu_to_le32(BT_COEX_HIGH_BAND_RET);
send_cmd:
memset(&mvm->last_bt_notif, 0, sizeof(mvm->last_bt_notif));
memset(&mvm->last_bt_ci_cmd, 0, sizeof(mvm->last_bt_ci_cmd));
return iwl_mvm_send_cmd_pdu(mvm, BT_CONFIG, 0, sizeof(bt_cmd), &bt_cmd);
}
static int iwl_mvm_bt_coex_reduced_txp(struct iwl_mvm *mvm, u8 sta_id,
bool enable)
{
struct iwl_bt_coex_reduced_txp_update_cmd cmd = {};
struct iwl_mvm_sta *mvmsta;
u32 value;
int ret;
mvmsta = iwl_mvm_sta_from_staid_protected(mvm, sta_id);
if (!mvmsta)
return 0;
if (mvmsta->bt_reduced_txpower == enable)
return 0;
value = mvmsta->sta_id;
if (enable)
value |= BT_REDUCED_TX_POWER_BIT;
IWL_DEBUG_COEX(mvm, "%sable reduced Tx Power for sta %d\n",
enable ? "en" : "dis", sta_id);
cmd.reduced_txp = cpu_to_le32(value);
mvmsta->bt_reduced_txpower = enable;
ret = iwl_mvm_send_cmd_pdu(mvm, BT_COEX_UPDATE_REDUCED_TXP, CMD_ASYNC,
sizeof(cmd), &cmd);
return ret;
}
static inline
void iwl_mvm_bt_coex_enable_rssi_event(struct iwl_mvm *mvm,
struct ieee80211_vif *vif,
bool enable, int rssi)
{
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
mvmvif->bf_data.last_bt_coex_event = rssi;
mvmvif->bf_data.bt_coex_max_thold =
enable ? -IWL_MVM_BT_COEX_EN_RED_TXP_THRESH : 0;
mvmvif->bf_data.bt_coex_min_thold =
enable ? -IWL_MVM_BT_COEX_DIS_RED_TXP_THRESH : 0;
}
static void iwl_mvm_bt_notif_iterator(void *_data, u8 *mac,
struct ieee80211_vif *vif)
{
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
struct iwl_bt_iterator_data *data = _data;
struct iwl_mvm *mvm = data->mvm;
struct ieee80211_chanctx_conf *chanctx_conf;
enum ieee80211_smps_mode smps_mode = IEEE80211_SMPS_AUTOMATIC;
u32 bt_activity_grading;
int ave_rssi;
lockdep_assert_held(&mvm->mutex);
switch (vif->type) {
case NL80211_IFTYPE_STATION:
break;
case NL80211_IFTYPE_AP:
if (!mvmvif->ap_ibss_active)
return;
break;
default:
return;
}
chanctx_conf = rcu_dereference(vif->chanctx_conf);
if ((!chanctx_conf ||
chanctx_conf->def.chan->band != NL80211_BAND_2GHZ)) {
if (vif->type == NL80211_IFTYPE_STATION) {
iwl_mvm_update_smps(mvm, vif, IWL_MVM_SMPS_REQ_BT_COEX,
smps_mode);
iwl_mvm_bt_coex_reduced_txp(mvm, mvmvif->ap_sta_id,
false);
iwl_mvm_bt_coex_enable_rssi_event(mvm, vif, false, 0);
}
return;
}
bt_activity_grading = le32_to_cpu(data->notif->bt_activity_grading);
if (bt_activity_grading >= BT_HIGH_TRAFFIC)
smps_mode = IEEE80211_SMPS_STATIC;
else if (bt_activity_grading >= BT_LOW_TRAFFIC)
smps_mode = IEEE80211_SMPS_DYNAMIC;
if (!vif->bss_conf.assoc)
smps_mode = IEEE80211_SMPS_AUTOMATIC;
if (mvmvif->phy_ctxt &&
(mvm->last_bt_notif.rrc_status & BIT(mvmvif->phy_ctxt->id)))
smps_mode = IEEE80211_SMPS_AUTOMATIC;
IWL_DEBUG_COEX(data->mvm,
"mac %d: bt_activity_grading %d smps_req %d\n",
mvmvif->id, bt_activity_grading, smps_mode);
if (vif->type == NL80211_IFTYPE_STATION)
iwl_mvm_update_smps(mvm, vif, IWL_MVM_SMPS_REQ_BT_COEX,
smps_mode);
if (iwl_mvm_vif_low_latency(mvmvif)) {
data->primary_ll = true;
data->secondary = data->primary;
data->primary = chanctx_conf;
}
if (vif->type == NL80211_IFTYPE_AP) {
if (!mvmvif->ap_ibss_active)
return;
if (chanctx_conf == data->primary)
return;
if (!data->primary_ll) {
data->secondary = data->primary;
data->primary = chanctx_conf;
} else {
data->secondary = chanctx_conf;
}
return;
}
if (!data->primary || data->primary == chanctx_conf)
data->primary = chanctx_conf;
else if (!data->secondary)
data->secondary = chanctx_conf;
if (iwl_get_coex_type(mvm, vif) == BT_COEX_LOOSE_LUT ||
mvm->cfg->bt_shared_single_ant || !vif->bss_conf.assoc ||
le32_to_cpu(mvm->last_bt_notif.bt_activity_grading) == BT_OFF) {
iwl_mvm_bt_coex_reduced_txp(mvm, mvmvif->ap_sta_id, false);
iwl_mvm_bt_coex_enable_rssi_event(mvm, vif, false, 0);
return;
}
ave_rssi = mvmvif->bf_data.ave_beacon_signal;
if (!ave_rssi)
ave_rssi = -100;
if (ave_rssi > -IWL_MVM_BT_COEX_EN_RED_TXP_THRESH) {
if (iwl_mvm_bt_coex_reduced_txp(mvm, mvmvif->ap_sta_id, true))
IWL_ERR(mvm, "Couldn't send BT_CONFIG cmd\n");
} else if (ave_rssi < -IWL_MVM_BT_COEX_DIS_RED_TXP_THRESH) {
if (iwl_mvm_bt_coex_reduced_txp(mvm, mvmvif->ap_sta_id, false))
IWL_ERR(mvm, "Couldn't send BT_CONFIG cmd\n");
}
iwl_mvm_bt_coex_enable_rssi_event(mvm, vif, true, ave_rssi);
}
static void iwl_mvm_bt_coex_notif_handle(struct iwl_mvm *mvm)
{
struct iwl_bt_iterator_data data = {
.mvm = mvm,
.notif = &mvm->last_bt_notif,
};
struct iwl_bt_coex_ci_cmd cmd = {};
u8 ci_bw_idx;
if (unlikely(mvm->bt_force_ant_mode != BT_FORCE_ANT_DIS))
return;
rcu_read_lock();
ieee80211_iterate_active_interfaces_atomic(
mvm->hw, IEEE80211_IFACE_ITER_NORMAL,
iwl_mvm_bt_notif_iterator, &data);
if (data.primary) {
struct ieee80211_chanctx_conf *chan = data.primary;
if (WARN_ON(!chan->def.chan)) {
rcu_read_unlock();
return;
}
if (chan->def.width < NL80211_CHAN_WIDTH_40) {
ci_bw_idx = 0;
} else {
if (chan->def.center_freq1 >
chan->def.chan->center_freq)
ci_bw_idx = 2;
else
ci_bw_idx = 1;
}
cmd.bt_primary_ci =
iwl_ci_mask[chan->def.chan->hw_value][ci_bw_idx];
cmd.primary_ch_phy_id =
cpu_to_le32(*((u16 *)data.primary->drv_priv));
}
if (data.secondary) {
struct ieee80211_chanctx_conf *chan = data.secondary;
if (WARN_ON(!data.secondary->def.chan)) {
rcu_read_unlock();
return;
}
if (chan->def.width < NL80211_CHAN_WIDTH_40) {
ci_bw_idx = 0;
} else {
if (chan->def.center_freq1 >
chan->def.chan->center_freq)
ci_bw_idx = 2;
else
ci_bw_idx = 1;
}
cmd.bt_secondary_ci =
iwl_ci_mask[chan->def.chan->hw_value][ci_bw_idx];
cmd.secondary_ch_phy_id =
cpu_to_le32(*((u16 *)data.secondary->drv_priv));
}
rcu_read_unlock();
if (memcmp(&cmd, &mvm->last_bt_ci_cmd, sizeof(cmd))) {
if (iwl_mvm_send_cmd_pdu(mvm, BT_COEX_CI, 0,
sizeof(cmd), &cmd))
IWL_ERR(mvm, "Failed to send BT_CI cmd\n");
memcpy(&mvm->last_bt_ci_cmd, &cmd, sizeof(cmd));
}
}
void iwl_mvm_rx_bt_coex_notif(struct iwl_mvm *mvm,
struct iwl_rx_cmd_buffer *rxb)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
struct iwl_bt_coex_profile_notif *notif = (void *)pkt->data;
if (!iwl_mvm_has_new_ats_coex_api(mvm)) {
struct iwl_bt_coex_profile_notif_v4 *v4 = (void *)pkt->data;
mvm->last_bt_notif.mbox_msg[0] = v4->mbox_msg[0];
mvm->last_bt_notif.mbox_msg[1] = v4->mbox_msg[1];
mvm->last_bt_notif.mbox_msg[2] = v4->mbox_msg[2];
mvm->last_bt_notif.mbox_msg[3] = v4->mbox_msg[3];
mvm->last_bt_notif.msg_idx = v4->msg_idx;
mvm->last_bt_notif.bt_ci_compliance = v4->bt_ci_compliance;
mvm->last_bt_notif.primary_ch_lut = v4->primary_ch_lut;
mvm->last_bt_notif.secondary_ch_lut = v4->secondary_ch_lut;
mvm->last_bt_notif.bt_activity_grading =
v4->bt_activity_grading;
mvm->last_bt_notif.ttc_status = v4->ttc_status;
mvm->last_bt_notif.rrc_status = v4->rrc_status;
} else {
memcpy(&mvm->last_bt_notif, notif, sizeof(mvm->last_bt_notif));
}
IWL_DEBUG_COEX(mvm, "BT Coex Notification received\n");
IWL_DEBUG_COEX(mvm, "\tBT ci compliance %d\n",
mvm->last_bt_notif.bt_ci_compliance);
IWL_DEBUG_COEX(mvm, "\tBT primary_ch_lut %d\n",
le32_to_cpu(mvm->last_bt_notif.primary_ch_lut));
IWL_DEBUG_COEX(mvm, "\tBT secondary_ch_lut %d\n",
le32_to_cpu(mvm->last_bt_notif.secondary_ch_lut));
IWL_DEBUG_COEX(mvm, "\tBT activity grading %d\n",
le32_to_cpu(mvm->last_bt_notif.bt_activity_grading));
iwl_mvm_bt_coex_notif_handle(mvm);
}
void iwl_mvm_bt_rssi_event(struct iwl_mvm *mvm, struct ieee80211_vif *vif,
enum ieee80211_rssi_event_data rssi_event)
{
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
int ret;
lockdep_assert_held(&mvm->mutex);
if (unlikely(mvm->bt_force_ant_mode != BT_FORCE_ANT_DIS))
return;
if (mvmvif->ap_sta_id == IWL_MVM_INVALID_STA)
return;
if (le32_to_cpu(mvm->last_bt_notif.bt_activity_grading) == BT_OFF)
return;
IWL_DEBUG_COEX(mvm, "RSSI for %pM is now %s\n", vif->bss_conf.bssid,
rssi_event == RSSI_EVENT_HIGH ? "HIGH" : "LOW");
if (rssi_event == RSSI_EVENT_LOW || mvm->cfg->bt_shared_single_ant ||
iwl_get_coex_type(mvm, vif) == BT_COEX_LOOSE_LUT)
ret = iwl_mvm_bt_coex_reduced_txp(mvm, mvmvif->ap_sta_id,
false);
else
ret = iwl_mvm_bt_coex_reduced_txp(mvm, mvmvif->ap_sta_id, true);
if (ret)
IWL_ERR(mvm, "couldn't send BT_CONFIG HCMD upon RSSI event\n");
}
u16 iwl_mvm_coex_agg_time_limit(struct iwl_mvm *mvm,
struct ieee80211_sta *sta)
{
struct iwl_mvm_sta *mvmsta = iwl_mvm_sta_from_mac80211(sta);
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(mvmsta->vif);
struct iwl_mvm_phy_ctxt *phy_ctxt = mvmvif->phy_ctxt;
enum iwl_bt_coex_lut_type lut_type;
if (mvm->last_bt_notif.ttc_status & BIT(phy_ctxt->id))
return LINK_QUAL_AGG_TIME_LIMIT_DEF;
if (le32_to_cpu(mvm->last_bt_notif.bt_activity_grading) <
BT_HIGH_TRAFFIC)
return LINK_QUAL_AGG_TIME_LIMIT_DEF;
lut_type = iwl_get_coex_type(mvm, mvmsta->vif);
if (lut_type == BT_COEX_LOOSE_LUT || lut_type == BT_COEX_INVALID_LUT)
return LINK_QUAL_AGG_TIME_LIMIT_DEF;
return LINK_QUAL_AGG_TIME_LIMIT_BT_ACT;
}
bool iwl_mvm_bt_coex_is_mimo_allowed(struct iwl_mvm *mvm,
struct ieee80211_sta *sta)
{
struct iwl_mvm_sta *mvmsta = iwl_mvm_sta_from_mac80211(sta);
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(mvmsta->vif);
struct iwl_mvm_phy_ctxt *phy_ctxt = mvmvif->phy_ctxt;
enum iwl_bt_coex_lut_type lut_type;
if (mvm->last_bt_notif.ttc_status & BIT(phy_ctxt->id))
return true;
if (le32_to_cpu(mvm->last_bt_notif.bt_activity_grading) <
BT_HIGH_TRAFFIC)
return true;
lut_type = iwl_get_coex_type(mvm, mvmsta->vif);
return lut_type != BT_COEX_LOOSE_LUT;
}
bool iwl_mvm_bt_coex_is_ant_avail(struct iwl_mvm *mvm, u8 ant)
{
if (mvm->cfg->bt_shared_single_ant)
return true;
if (ant & mvm->cfg->non_shared_ant)
return true;
return le32_to_cpu(mvm->last_bt_notif.bt_activity_grading) <
BT_HIGH_TRAFFIC;
}
bool iwl_mvm_bt_coex_is_shared_ant_avail(struct iwl_mvm *mvm)
{
if (mvm->cfg->bt_shared_single_ant)
return true;
return le32_to_cpu(mvm->last_bt_notif.bt_activity_grading) < BT_HIGH_TRAFFIC;
}
bool iwl_mvm_bt_coex_is_tpc_allowed(struct iwl_mvm *mvm,
enum nl80211_band band)
{
u32 bt_activity = le32_to_cpu(mvm->last_bt_notif.bt_activity_grading);
if (band != NL80211_BAND_2GHZ)
return false;
return bt_activity >= BT_LOW_TRAFFIC;
}
u8 iwl_mvm_bt_coex_tx_prio(struct iwl_mvm *mvm, struct ieee80211_hdr *hdr,
struct ieee80211_tx_info *info, u8 ac)
{
__le16 fc = hdr->frame_control;
bool mplut_enabled = iwl_mvm_is_mplut_supported(mvm);
if (info->band != NL80211_BAND_2GHZ)
return 0;
if (unlikely(mvm->bt_tx_prio))
return mvm->bt_tx_prio - 1;
if (likely(ieee80211_is_data(fc))) {
if (likely(ieee80211_is_data_qos(fc))) {
switch (ac) {
case IEEE80211_AC_BE:
return mplut_enabled ? 1 : 0;
case IEEE80211_AC_VI:
return mplut_enabled ? 2 : 3;
case IEEE80211_AC_VO:
return 3;
default:
return 0;
}
} else if (is_multicast_ether_addr(hdr->addr1)) {
return 3;
} else
return 0;
} else if (ieee80211_is_mgmt(fc)) {
return ieee80211_is_disassoc(fc) ? 0 : 3;
} else if (ieee80211_is_ctl(fc)) {
return 3;
}
return 0;
}
void iwl_mvm_bt_coex_vif_change(struct iwl_mvm *mvm)
{
iwl_mvm_bt_coex_notif_handle(mvm);
}
