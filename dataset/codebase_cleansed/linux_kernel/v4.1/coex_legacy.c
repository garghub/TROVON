static int iwl_send_bt_prio_tbl(struct iwl_mvm *mvm)
{
if (unlikely(mvm->bt_force_ant_mode != BT_FORCE_ANT_DIS))
return 0;
return iwl_mvm_send_cmd_pdu(mvm, BT_COEX_PRIO_TABLE, 0,
sizeof(struct iwl_bt_coex_prio_tbl_cmd),
&iwl_bt_prio_tbl);
}
static enum iwl_bt_coex_lut_type
iwl_get_coex_type(struct iwl_mvm *mvm, const struct ieee80211_vif *vif)
{
struct ieee80211_chanctx_conf *chanctx_conf;
enum iwl_bt_coex_lut_type ret;
u16 phy_ctx_id;
rcu_read_lock();
chanctx_conf = rcu_dereference(vif->chanctx_conf);
if (!chanctx_conf ||
chanctx_conf->def.chan->band != IEEE80211_BAND_2GHZ) {
rcu_read_unlock();
return BT_COEX_INVALID_LUT;
}
ret = BT_COEX_TX_DIS_LUT;
if (mvm->cfg->bt_shared_single_ant) {
rcu_read_unlock();
return ret;
}
phy_ctx_id = *((u16 *)chanctx_conf->drv_priv);
if (mvm->last_bt_ci_cmd_old.primary_ch_phy_id == phy_ctx_id)
ret = le32_to_cpu(mvm->last_bt_notif_old.primary_ch_lut);
else if (mvm->last_bt_ci_cmd_old.secondary_ch_phy_id == phy_ctx_id)
ret = le32_to_cpu(mvm->last_bt_notif_old.secondary_ch_lut);
rcu_read_unlock();
return ret;
}
int iwl_send_bt_init_conf_old(struct iwl_mvm *mvm)
{
struct iwl_bt_coex_cmd_old *bt_cmd;
struct iwl_host_cmd cmd = {
.id = BT_CONFIG,
.len = { sizeof(*bt_cmd), },
.dataflags = { IWL_HCMD_DFL_NOCOPY, },
};
int ret;
u32 flags;
ret = iwl_send_bt_prio_tbl(mvm);
if (ret)
return ret;
bt_cmd = kzalloc(sizeof(*bt_cmd), GFP_KERNEL);
if (!bt_cmd)
return -ENOMEM;
cmd.data[0] = bt_cmd;
lockdep_assert_held(&mvm->mutex);
if (unlikely(mvm->bt_force_ant_mode != BT_FORCE_ANT_DIS)) {
switch (mvm->bt_force_ant_mode) {
case BT_FORCE_ANT_AUTO:
flags = BT_COEX_AUTO_OLD;
break;
case BT_FORCE_ANT_BT:
flags = BT_COEX_BT_OLD;
break;
case BT_FORCE_ANT_WIFI:
flags = BT_COEX_WIFI_OLD;
break;
default:
WARN_ON(1);
flags = 0;
}
bt_cmd->flags = cpu_to_le32(flags);
bt_cmd->valid_bit_msk = cpu_to_le32(BT_VALID_ENABLE);
goto send_cmd;
}
bt_cmd->max_kill = 5;
bt_cmd->bt4_antenna_isolation_thr =
IWL_MVM_BT_COEX_ANTENNA_COUPLING_THRS;
bt_cmd->bt4_antenna_isolation = iwlwifi_mod_params.ant_coupling;
bt_cmd->bt4_tx_tx_delta_freq_thr = 15;
bt_cmd->bt4_tx_rx_max_freq0 = 15;
bt_cmd->override_primary_lut = BT_COEX_INVALID_LUT;
bt_cmd->override_secondary_lut = BT_COEX_INVALID_LUT;
flags = iwlwifi_mod_params.bt_coex_active ?
BT_COEX_NW_OLD : BT_COEX_DISABLE_OLD;
bt_cmd->flags = cpu_to_le32(flags);
bt_cmd->valid_bit_msk = cpu_to_le32(BT_VALID_ENABLE |
BT_VALID_BT_PRIO_BOOST |
BT_VALID_MAX_KILL |
BT_VALID_3W_TMRS |
BT_VALID_KILL_ACK |
BT_VALID_KILL_CTS |
BT_VALID_REDUCED_TX_POWER |
BT_VALID_LUT |
BT_VALID_WIFI_RX_SW_PRIO_BOOST |
BT_VALID_WIFI_TX_SW_PRIO_BOOST |
BT_VALID_ANT_ISOLATION |
BT_VALID_ANT_ISOLATION_THRS |
BT_VALID_TXTX_DELTA_FREQ_THRS |
BT_VALID_TXRX_MAX_FREQ_0 |
BT_VALID_SYNC_TO_SCO |
BT_VALID_TTC |
BT_VALID_RRC);
if (IWL_MVM_BT_COEX_SYNC2SCO)
bt_cmd->flags |= cpu_to_le32(BT_COEX_SYNC2SCO);
if (iwl_mvm_bt_is_plcr_supported(mvm)) {
bt_cmd->valid_bit_msk |= cpu_to_le32(BT_VALID_CORUN_LUT_20 |
BT_VALID_CORUN_LUT_40);
bt_cmd->flags |= cpu_to_le32(BT_COEX_CORUNNING);
}
if (IWL_MVM_BT_COEX_MPLUT) {
bt_cmd->flags |= cpu_to_le32(BT_COEX_MPLUT);
bt_cmd->valid_bit_msk |= cpu_to_le32(BT_VALID_MULTI_PRIO_LUT);
}
if (IWL_MVM_BT_COEX_TTC)
bt_cmd->flags |= cpu_to_le32(BT_COEX_TTC);
if (iwl_mvm_bt_is_rrc_supported(mvm))
bt_cmd->flags |= cpu_to_le32(BT_COEX_RRC);
if (mvm->cfg->bt_shared_single_ant)
memcpy(&bt_cmd->decision_lut, iwl_single_shared_ant,
sizeof(iwl_single_shared_ant));
else
memcpy(&bt_cmd->decision_lut, iwl_combined_lookup,
sizeof(iwl_combined_lookup));
memcpy(bt_cmd->bt4_corun_lut20, antenna_coupling_ranges[0].lut20,
sizeof(bt_cmd->bt4_corun_lut20));
memcpy(bt_cmd->bt4_corun_lut40, antenna_coupling_ranges[0].lut20,
sizeof(bt_cmd->bt4_corun_lut40));
memcpy(&bt_cmd->bt_prio_boost, iwl_bt_prio_boost,
sizeof(iwl_bt_prio_boost));
bt_cmd->bt4_multiprio_lut[0] = cpu_to_le32(IWL_MVM_BT_COEX_MPLUT_REG0);
bt_cmd->bt4_multiprio_lut[1] = cpu_to_le32(IWL_MVM_BT_COEX_MPLUT_REG1);
send_cmd:
memset(&mvm->last_bt_notif_old, 0, sizeof(mvm->last_bt_notif_old));
memset(&mvm->last_bt_ci_cmd_old, 0, sizeof(mvm->last_bt_ci_cmd_old));
ret = iwl_mvm_send_cmd(mvm, &cmd);
kfree(bt_cmd);
return ret;
}
static int iwl_mvm_bt_udpate_ctrl_kill_msk(struct iwl_mvm *mvm)
{
struct iwl_bt_coex_profile_notif_old *notif = &mvm->last_bt_notif_old;
u32 primary_lut = le32_to_cpu(notif->primary_ch_lut);
u32 ag = le32_to_cpu(notif->bt_activity_grading);
struct iwl_bt_coex_cmd_old *bt_cmd;
u8 ack_kill_msk, cts_kill_msk;
struct iwl_host_cmd cmd = {
.id = BT_CONFIG,
.data[0] = &bt_cmd,
.len = { sizeof(*bt_cmd), },
.dataflags = { IWL_HCMD_DFL_NOCOPY, },
};
int ret = 0;
lockdep_assert_held(&mvm->mutex);
ack_kill_msk = iwl_bt_ack_kill_msk[ag][primary_lut];
cts_kill_msk = iwl_bt_cts_kill_msk[ag][primary_lut];
if (mvm->bt_ack_kill_msk[0] == ack_kill_msk &&
mvm->bt_cts_kill_msk[0] == cts_kill_msk)
return 0;
mvm->bt_ack_kill_msk[0] = ack_kill_msk;
mvm->bt_cts_kill_msk[0] = cts_kill_msk;
bt_cmd = kzalloc(sizeof(*bt_cmd), GFP_KERNEL);
if (!bt_cmd)
return -ENOMEM;
cmd.data[0] = bt_cmd;
bt_cmd->flags = cpu_to_le32(BT_COEX_NW_OLD);
bt_cmd->kill_ack_msk = cpu_to_le32(iwl_bt_ctl_kill_msk[ack_kill_msk]);
bt_cmd->kill_cts_msk = cpu_to_le32(iwl_bt_ctl_kill_msk[cts_kill_msk]);
bt_cmd->valid_bit_msk |= cpu_to_le32(BT_VALID_ENABLE |
BT_VALID_KILL_ACK |
BT_VALID_KILL_CTS);
ret = iwl_mvm_send_cmd(mvm, &cmd);
kfree(bt_cmd);
return ret;
}
static int iwl_mvm_bt_coex_reduced_txp(struct iwl_mvm *mvm, u8 sta_id,
bool enable)
{
struct iwl_bt_coex_cmd_old *bt_cmd;
struct iwl_host_cmd cmd = {
.id = BT_CONFIG,
.len = { sizeof(*bt_cmd), },
.dataflags = { IWL_HCMD_DFL_DUP, },
.flags = CMD_ASYNC,
};
struct iwl_mvm_sta *mvmsta;
int ret;
mvmsta = iwl_mvm_sta_from_staid_protected(mvm, sta_id);
if (!mvmsta)
return 0;
if (mvmsta->bt_reduced_txpower == enable)
return 0;
bt_cmd = kzalloc(sizeof(*bt_cmd), GFP_ATOMIC);
if (!bt_cmd)
return -ENOMEM;
cmd.data[0] = bt_cmd;
bt_cmd->flags = cpu_to_le32(BT_COEX_NW_OLD);
bt_cmd->valid_bit_msk =
cpu_to_le32(BT_VALID_ENABLE | BT_VALID_REDUCED_TX_POWER);
bt_cmd->bt_reduced_tx_power = sta_id;
if (enable)
bt_cmd->bt_reduced_tx_power |= BT_REDUCED_TX_POWER_BIT;
IWL_DEBUG_COEX(mvm, "%sable reduced Tx Power for sta %d\n",
enable ? "en" : "dis", sta_id);
mvmsta->bt_reduced_txpower = enable;
ret = iwl_mvm_send_cmd(mvm, &cmd);
kfree(bt_cmd);
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
enum ieee80211_smps_mode smps_mode;
u32 bt_activity_grading;
int ave_rssi;
lockdep_assert_held(&mvm->mutex);
switch (vif->type) {
case NL80211_IFTYPE_STATION:
smps_mode = IEEE80211_SMPS_AUTOMATIC;
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
chanctx_conf->def.chan->band != IEEE80211_BAND_2GHZ)) {
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
smps_mode = vif->type == NL80211_IFTYPE_AP ?
IEEE80211_SMPS_OFF :
IEEE80211_SMPS_DYNAMIC;
if (!vif->bss_conf.assoc)
smps_mode = IEEE80211_SMPS_AUTOMATIC;
if (mvmvif->phy_ctxt &&
data->notif->rrc_enabled & BIT(mvmvif->phy_ctxt->id))
smps_mode = IEEE80211_SMPS_AUTOMATIC;
IWL_DEBUG_COEX(data->mvm,
"mac %d: bt_status %d bt_activity_grading %d smps_req %d\n",
mvmvif->id, data->notif->bt_status, bt_activity_grading,
smps_mode);
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
!data->notif->bt_status) {
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
.notif = &mvm->last_bt_notif_old,
};
struct iwl_bt_coex_ci_cmd_old cmd = {};
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
cmd.co_run_bw_primary = 0;
} else {
cmd.co_run_bw_primary = 1;
if (chan->def.center_freq1 >
chan->def.chan->center_freq)
ci_bw_idx = 2;
else
ci_bw_idx = 1;
}
cmd.bt_primary_ci =
iwl_ci_mask[chan->def.chan->hw_value][ci_bw_idx];
cmd.primary_ch_phy_id = *((u16 *)data.primary->drv_priv);
}
if (data.secondary) {
struct ieee80211_chanctx_conf *chan = data.secondary;
if (WARN_ON(!data.secondary->def.chan)) {
rcu_read_unlock();
return;
}
if (chan->def.width < NL80211_CHAN_WIDTH_40) {
ci_bw_idx = 0;
cmd.co_run_bw_secondary = 0;
} else {
cmd.co_run_bw_secondary = 1;
if (chan->def.center_freq1 >
chan->def.chan->center_freq)
ci_bw_idx = 2;
else
ci_bw_idx = 1;
}
cmd.bt_secondary_ci =
iwl_ci_mask[chan->def.chan->hw_value][ci_bw_idx];
cmd.secondary_ch_phy_id = *((u16 *)data.secondary->drv_priv);
}
rcu_read_unlock();
if (memcmp(&cmd, &mvm->last_bt_ci_cmd_old, sizeof(cmd))) {
if (iwl_mvm_send_cmd_pdu(mvm, BT_COEX_CI, 0,
sizeof(cmd), &cmd))
IWL_ERR(mvm, "Failed to send BT_CI cmd\n");
memcpy(&mvm->last_bt_ci_cmd_old, &cmd, sizeof(cmd));
}
if (iwl_mvm_bt_udpate_ctrl_kill_msk(mvm))
IWL_ERR(mvm, "Failed to update the ctrl_kill_msk\n");
}
int iwl_mvm_rx_bt_coex_notif_old(struct iwl_mvm *mvm,
struct iwl_rx_cmd_buffer *rxb,
struct iwl_device_cmd *dev_cmd)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
struct iwl_bt_coex_profile_notif_old *notif = (void *)pkt->data;
IWL_DEBUG_COEX(mvm, "BT Coex Notification received\n");
IWL_DEBUG_COEX(mvm, "\tBT status: %s\n",
notif->bt_status ? "ON" : "OFF");
IWL_DEBUG_COEX(mvm, "\tBT open conn %d\n", notif->bt_open_conn);
IWL_DEBUG_COEX(mvm, "\tBT ci compliance %d\n", notif->bt_ci_compliance);
IWL_DEBUG_COEX(mvm, "\tBT primary_ch_lut %d\n",
le32_to_cpu(notif->primary_ch_lut));
IWL_DEBUG_COEX(mvm, "\tBT secondary_ch_lut %d\n",
le32_to_cpu(notif->secondary_ch_lut));
IWL_DEBUG_COEX(mvm, "\tBT activity grading %d\n",
le32_to_cpu(notif->bt_activity_grading));
IWL_DEBUG_COEX(mvm, "\tBT agg traffic load %d\n",
notif->bt_agg_traffic_load);
memcpy(&mvm->last_bt_notif_old, notif, sizeof(mvm->last_bt_notif_old));
iwl_mvm_bt_coex_notif_handle(mvm);
return 0;
}
static void iwl_mvm_bt_rssi_iterator(void *_data, u8 *mac,
struct ieee80211_vif *vif)
{
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
struct iwl_bt_iterator_data *data = _data;
struct iwl_mvm *mvm = data->mvm;
struct ieee80211_sta *sta;
struct iwl_mvm_sta *mvmsta;
struct ieee80211_chanctx_conf *chanctx_conf;
rcu_read_lock();
chanctx_conf = rcu_dereference(vif->chanctx_conf);
if (!chanctx_conf ||
chanctx_conf->def.chan->band != IEEE80211_BAND_2GHZ) {
rcu_read_unlock();
return;
}
rcu_read_unlock();
if (vif->type != NL80211_IFTYPE_STATION ||
mvmvif->ap_sta_id == IWL_MVM_STATION_COUNT)
return;
sta = rcu_dereference_protected(mvm->fw_id_to_mac_id[mvmvif->ap_sta_id],
lockdep_is_held(&mvm->mutex));
if (IS_ERR_OR_NULL(sta))
return;
mvmsta = iwl_mvm_sta_from_mac80211(sta);
}
void iwl_mvm_bt_rssi_event_old(struct iwl_mvm *mvm, struct ieee80211_vif *vif,
enum ieee80211_rssi_event_data rssi_event)
{
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
struct iwl_bt_iterator_data data = {
.mvm = mvm,
};
int ret;
lockdep_assert_held(&mvm->mutex);
if (unlikely(mvm->bt_force_ant_mode != BT_FORCE_ANT_DIS))
return;
if (mvmvif->ap_sta_id == IWL_MVM_STATION_COUNT)
return;
if (!mvm->last_bt_notif_old.bt_status)
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
ieee80211_iterate_active_interfaces_atomic(
mvm->hw, IEEE80211_IFACE_ITER_NORMAL,
iwl_mvm_bt_rssi_iterator, &data);
if (iwl_mvm_bt_udpate_ctrl_kill_msk(mvm))
IWL_ERR(mvm, "Failed to update the ctrl_kill_msk\n");
}
u16 iwl_mvm_coex_agg_time_limit_old(struct iwl_mvm *mvm,
struct ieee80211_sta *sta)
{
struct iwl_mvm_sta *mvmsta = iwl_mvm_sta_from_mac80211(sta);
enum iwl_bt_coex_lut_type lut_type;
if (le32_to_cpu(mvm->last_bt_notif_old.bt_activity_grading) <
BT_HIGH_TRAFFIC)
return LINK_QUAL_AGG_TIME_LIMIT_DEF;
if (mvm->last_bt_notif_old.ttc_enabled)
return LINK_QUAL_AGG_TIME_LIMIT_DEF;
lut_type = iwl_get_coex_type(mvm, mvmsta->vif);
if (lut_type == BT_COEX_LOOSE_LUT || lut_type == BT_COEX_INVALID_LUT)
return LINK_QUAL_AGG_TIME_LIMIT_DEF;
return LINK_QUAL_AGG_TIME_LIMIT_BT_ACT;
}
bool iwl_mvm_bt_coex_is_mimo_allowed_old(struct iwl_mvm *mvm,
struct ieee80211_sta *sta)
{
struct iwl_mvm_sta *mvmsta = iwl_mvm_sta_from_mac80211(sta);
enum iwl_bt_coex_lut_type lut_type;
if (mvm->last_bt_notif_old.ttc_enabled)
return true;
if (le32_to_cpu(mvm->last_bt_notif_old.bt_activity_grading) <
BT_HIGH_TRAFFIC)
return true;
lut_type = iwl_get_coex_type(mvm, mvmsta->vif);
return lut_type != BT_COEX_LOOSE_LUT;
}
bool iwl_mvm_bt_coex_is_shared_ant_avail_old(struct iwl_mvm *mvm)
{
u32 ag = le32_to_cpu(mvm->last_bt_notif_old.bt_activity_grading);
return ag < BT_HIGH_TRAFFIC;
}
bool iwl_mvm_bt_coex_is_tpc_allowed_old(struct iwl_mvm *mvm,
enum ieee80211_band band)
{
u32 bt_activity =
le32_to_cpu(mvm->last_bt_notif_old.bt_activity_grading);
if (band != IEEE80211_BAND_2GHZ)
return false;
return bt_activity >= BT_LOW_TRAFFIC;
}
void iwl_mvm_bt_coex_vif_change_old(struct iwl_mvm *mvm)
{
iwl_mvm_bt_coex_notif_handle(mvm);
}
int iwl_mvm_rx_ant_coupling_notif_old(struct iwl_mvm *mvm,
struct iwl_rx_cmd_buffer *rxb,
struct iwl_device_cmd *dev_cmd)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
u32 ant_isolation = le32_to_cpup((void *)pkt->data);
u8 __maybe_unused lower_bound, upper_bound;
int ret;
u8 lut;
struct iwl_bt_coex_cmd_old *bt_cmd;
struct iwl_host_cmd cmd = {
.id = BT_CONFIG,
.len = { sizeof(*bt_cmd), },
.dataflags = { IWL_HCMD_DFL_NOCOPY, },
};
if (!iwl_mvm_bt_is_plcr_supported(mvm))
return 0;
lockdep_assert_held(&mvm->mutex);
if (unlikely(mvm->bt_force_ant_mode != BT_FORCE_ANT_DIS))
return 0;
if (ant_isolation == mvm->last_ant_isol)
return 0;
for (lut = 0; lut < ARRAY_SIZE(antenna_coupling_ranges) - 1; lut++)
if (ant_isolation < antenna_coupling_ranges[lut + 1].range)
break;
lower_bound = antenna_coupling_ranges[lut].range;
if (lut < ARRAY_SIZE(antenna_coupling_ranges) - 1)
upper_bound = antenna_coupling_ranges[lut + 1].range;
else
upper_bound = antenna_coupling_ranges[lut].range;
IWL_DEBUG_COEX(mvm, "Antenna isolation=%d in range [%d,%d[, lut=%d\n",
ant_isolation, lower_bound, upper_bound, lut);
mvm->last_ant_isol = ant_isolation;
if (mvm->last_corun_lut == lut)
return 0;
mvm->last_corun_lut = lut;
bt_cmd = kzalloc(sizeof(*bt_cmd), GFP_KERNEL);
if (!bt_cmd)
return 0;
cmd.data[0] = bt_cmd;
bt_cmd->flags = cpu_to_le32(BT_COEX_NW_OLD);
bt_cmd->valid_bit_msk |= cpu_to_le32(BT_VALID_ENABLE |
BT_VALID_CORUN_LUT_20 |
BT_VALID_CORUN_LUT_40);
memcpy(bt_cmd->bt4_corun_lut20, antenna_coupling_ranges[lut].lut20,
sizeof(bt_cmd->bt4_corun_lut20));
memcpy(bt_cmd->bt4_corun_lut40, antenna_coupling_ranges[lut].lut20,
sizeof(bt_cmd->bt4_corun_lut40));
ret = iwl_mvm_send_cmd(mvm, &cmd);
kfree(bt_cmd);
return ret;
}
