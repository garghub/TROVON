int iwl_send_bt_prio_tbl(struct iwl_mvm *mvm)
{
if (!(mvm->fw->ucode_capa.flags & IWL_UCODE_TLV_FLAGS_NEWBT_COEX))
return 0;
return iwl_mvm_send_cmd_pdu(mvm, BT_COEX_PRIO_TABLE, CMD_SYNC,
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
return BT_COEX_LOOSE_LUT;
}
ret = BT_COEX_TX_DIS_LUT;
if (mvm->cfg->bt_shared_single_ant) {
rcu_read_unlock();
return ret;
}
phy_ctx_id = *((u16 *)chanctx_conf->drv_priv);
if (mvm->last_bt_ci_cmd.primary_ch_phy_id == phy_ctx_id)
ret = le32_to_cpu(mvm->last_bt_notif.primary_ch_lut);
else if (mvm->last_bt_ci_cmd.secondary_ch_phy_id == phy_ctx_id)
ret = le32_to_cpu(mvm->last_bt_notif.secondary_ch_lut);
rcu_read_unlock();
return ret;
}
int iwl_send_bt_init_conf(struct iwl_mvm *mvm)
{
struct iwl_bt_coex_cmd *bt_cmd;
struct iwl_host_cmd cmd = {
.id = BT_CONFIG,
.len = { sizeof(*bt_cmd), },
.dataflags = { IWL_HCMD_DFL_NOCOPY, },
.flags = CMD_SYNC,
};
int ret;
u32 flags;
if (!(mvm->fw->ucode_capa.flags & IWL_UCODE_TLV_FLAGS_NEWBT_COEX))
return 0;
bt_cmd = kzalloc(sizeof(*bt_cmd), GFP_KERNEL);
if (!bt_cmd)
return -ENOMEM;
cmd.data[0] = bt_cmd;
bt_cmd->max_kill = 5;
bt_cmd->bt4_antenna_isolation_thr = BT_ANTENNA_COUPLING_THRESHOLD,
bt_cmd->bt4_antenna_isolation = iwlwifi_mod_params.ant_coupling,
bt_cmd->bt4_tx_tx_delta_freq_thr = 15,
bt_cmd->bt4_tx_rx_max_freq0 = 15,
flags = iwlwifi_mod_params.bt_coex_active ?
BT_COEX_NW : BT_COEX_DISABLE;
flags |= BT_CH_PRIMARY_EN | BT_CH_SECONDARY_EN | BT_SYNC_2_BT_DISABLE;
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
BT_VALID_CORUN_LUT_20 |
BT_VALID_CORUN_LUT_40 |
BT_VALID_ANT_ISOLATION |
BT_VALID_ANT_ISOLATION_THRS |
BT_VALID_TXTX_DELTA_FREQ_THRS |
BT_VALID_TXRX_MAX_FREQ_0 |
BT_VALID_SYNC_TO_SCO);
if (mvm->cfg->bt_shared_single_ant)
memcpy(&bt_cmd->decision_lut, iwl_single_shared_ant,
sizeof(iwl_single_shared_ant));
else
memcpy(&bt_cmd->decision_lut, iwl_combined_lookup,
sizeof(iwl_combined_lookup));
memcpy(&bt_cmd->bt_prio_boost, iwl_bt_prio_boost,
sizeof(iwl_bt_prio_boost));
memcpy(&bt_cmd->bt4_multiprio_lut, iwl_bt_mprio_lut,
sizeof(iwl_bt_mprio_lut));
bt_cmd->kill_ack_msk =
cpu_to_le32(iwl_bt_ack_kill_msk[BT_KILL_MSK_DEFAULT]);
bt_cmd->kill_cts_msk =
cpu_to_le32(iwl_bt_cts_kill_msk[BT_KILL_MSK_DEFAULT]);
memset(&mvm->last_bt_notif, 0, sizeof(mvm->last_bt_notif));
memset(&mvm->last_bt_ci_cmd, 0, sizeof(mvm->last_bt_ci_cmd));
ret = iwl_mvm_send_cmd(mvm, &cmd);
kfree(bt_cmd);
return ret;
}
static int iwl_mvm_bt_udpate_ctrl_kill_msk(struct iwl_mvm *mvm,
bool reduced_tx_power)
{
enum iwl_bt_kill_msk bt_kill_msk;
struct iwl_bt_coex_cmd *bt_cmd;
struct iwl_bt_coex_profile_notif *notif = &mvm->last_bt_notif;
struct iwl_host_cmd cmd = {
.id = BT_CONFIG,
.data[0] = &bt_cmd,
.len = { sizeof(*bt_cmd), },
.dataflags = { IWL_HCMD_DFL_NOCOPY, },
.flags = CMD_SYNC,
};
int ret = 0;
lockdep_assert_held(&mvm->mutex);
if (reduced_tx_power) {
bt_kill_msk = BT_KILL_MSK_REDUCED_TXPOW;
} else {
if (BT_MBOX_MSG(notif, 3, SCO_STATE) ||
BT_MBOX_MSG(notif, 3, A2DP_STATE) ||
BT_MBOX_MSG(notif, 3, SNIFF_STATE))
bt_kill_msk = BT_KILL_MSK_SCO_HID_A2DP;
else
bt_kill_msk = BT_KILL_MSK_DEFAULT;
}
IWL_DEBUG_COEX(mvm,
"Update kill_msk: %d - SCO %sactive A2DP %sactive SNIFF %sactive\n",
bt_kill_msk,
BT_MBOX_MSG(notif, 3, SCO_STATE) ? "" : "in",
BT_MBOX_MSG(notif, 3, A2DP_STATE) ? "" : "in",
BT_MBOX_MSG(notif, 3, SNIFF_STATE) ? "" : "in");
if (bt_kill_msk == mvm->bt_kill_msk)
return 0;
mvm->bt_kill_msk = bt_kill_msk;
bt_cmd = kzalloc(sizeof(*bt_cmd), GFP_KERNEL);
if (!bt_cmd)
return -ENOMEM;
cmd.data[0] = bt_cmd;
bt_cmd->flags = cpu_to_le32(BT_COEX_NW);
bt_cmd->kill_ack_msk = cpu_to_le32(iwl_bt_ack_kill_msk[bt_kill_msk]);
bt_cmd->kill_cts_msk = cpu_to_le32(iwl_bt_cts_kill_msk[bt_kill_msk]);
bt_cmd->valid_bit_msk |= cpu_to_le32(BT_VALID_ENABLE |
BT_VALID_KILL_ACK |
BT_VALID_KILL_CTS);
IWL_DEBUG_COEX(mvm, "ACK Kill msk = 0x%08x, CTS Kill msk = 0x%08x\n",
iwl_bt_ack_kill_msk[bt_kill_msk],
iwl_bt_cts_kill_msk[bt_kill_msk]);
ret = iwl_mvm_send_cmd(mvm, &cmd);
kfree(bt_cmd);
return ret;
}
static int iwl_mvm_bt_coex_reduced_txp(struct iwl_mvm *mvm, u8 sta_id,
bool enable)
{
struct iwl_bt_coex_cmd *bt_cmd;
struct iwl_host_cmd cmd = {
.id = BT_CONFIG,
.len = { sizeof(*bt_cmd), },
.dataflags = { IWL_HCMD_DFL_DUP, },
.flags = CMD_ASYNC,
};
struct ieee80211_sta *sta;
struct iwl_mvm_sta *mvmsta;
int ret;
if (sta_id == IWL_MVM_STATION_COUNT)
return 0;
sta = rcu_dereference_protected(mvm->fw_id_to_mac_id[sta_id],
lockdep_is_held(&mvm->mutex));
if (IS_ERR_OR_NULL(sta))
return 0;
mvmsta = iwl_mvm_sta_from_mac80211(sta);
if (mvmsta->bt_reduced_txpower == enable)
return 0;
bt_cmd = kzalloc(sizeof(*bt_cmd), GFP_ATOMIC);
if (!bt_cmd)
return -ENOMEM;
cmd.data[0] = bt_cmd;
bt_cmd->flags = cpu_to_le32(BT_COEX_NW);
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
enable ? BT_ENABLE_REDUCED_TXPOWER_THRESHOLD : 0;
mvmvif->bf_data.bt_coex_min_thold =
enable ? BT_DISABLE_REDUCED_TXPOWER_THRESHOLD : 0;
}
static void iwl_mvm_bt_notif_iterator(void *_data, u8 *mac,
struct ieee80211_vif *vif)
{
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
struct iwl_bt_iterator_data *data = _data;
struct iwl_mvm *mvm = data->mvm;
struct ieee80211_chanctx_conf *chanctx_conf;
enum ieee80211_smps_mode smps_mode;
int ave_rssi;
lockdep_assert_held(&mvm->mutex);
if (vif->type != NL80211_IFTYPE_STATION &&
vif->type != NL80211_IFTYPE_AP)
return;
smps_mode = IEEE80211_SMPS_AUTOMATIC;
chanctx_conf = rcu_dereference(vif->chanctx_conf);
if ((!chanctx_conf ||
chanctx_conf->def.chan->band != IEEE80211_BAND_2GHZ)) {
if (vif->type == NL80211_IFTYPE_STATION && vif->bss_conf.assoc)
iwl_mvm_update_smps(mvm, vif, IWL_MVM_SMPS_REQ_BT_COEX,
smps_mode);
iwl_mvm_bt_coex_enable_rssi_event(mvm, vif, false, 0);
return;
}
if (vif->type == NL80211_IFTYPE_AP) {
if (!mvmvif->ap_ibss_active)
return;
data->reduced_tx_power = false;
if (chanctx_conf == data->primary)
return;
data->secondary = data->primary;
data->primary = chanctx_conf;
return;
}
data->num_bss_ifaces++;
if (!vif->bss_conf.assoc)
return;
if (!data->primary || data->primary == chanctx_conf)
data->primary = chanctx_conf;
else if (!data->secondary)
data->secondary = chanctx_conf;
if (le32_to_cpu(data->notif->bt_activity_grading) >= BT_HIGH_TRAFFIC)
smps_mode = IEEE80211_SMPS_STATIC;
else if (le32_to_cpu(data->notif->bt_activity_grading) >=
BT_LOW_TRAFFIC)
smps_mode = IEEE80211_SMPS_DYNAMIC;
IWL_DEBUG_COEX(data->mvm,
"mac %d: bt_status %d bt_activity_grading %d smps_req %d\n",
mvmvif->id, data->notif->bt_status,
data->notif->bt_activity_grading, smps_mode);
iwl_mvm_update_smps(mvm, vif, IWL_MVM_SMPS_REQ_BT_COEX, smps_mode);
if (iwl_get_coex_type(mvm, vif) == BT_COEX_LOOSE_LUT ||
mvm->cfg->bt_shared_single_ant) {
data->reduced_tx_power = false;
iwl_mvm_bt_coex_enable_rssi_event(mvm, vif, false, 0);
return;
}
if (!data->notif->bt_status) {
if (iwl_mvm_bt_coex_reduced_txp(mvm, mvmvif->ap_sta_id, false))
IWL_ERR(mvm, "Couldn't send BT_CONFIG cmd\n");
data->reduced_tx_power = false;
iwl_mvm_bt_coex_enable_rssi_event(mvm, vif, false, 0);
return;
}
ave_rssi = mvmvif->bf_data.ave_beacon_signal;
if (!ave_rssi)
ave_rssi = -100;
if (ave_rssi > BT_ENABLE_REDUCED_TXPOWER_THRESHOLD) {
if (iwl_mvm_bt_coex_reduced_txp(mvm, mvmvif->ap_sta_id, true))
IWL_ERR(mvm, "Couldn't send BT_CONFIG cmd\n");
} else if (ave_rssi < BT_DISABLE_REDUCED_TXPOWER_THRESHOLD) {
if (iwl_mvm_bt_coex_reduced_txp(mvm, mvmvif->ap_sta_id, false))
IWL_ERR(mvm, "Couldn't send BT_CONFIG cmd\n");
data->reduced_tx_power = false;
}
iwl_mvm_bt_coex_enable_rssi_event(mvm, vif, true, ave_rssi);
}
static void iwl_mvm_bt_coex_notif_handle(struct iwl_mvm *mvm)
{
struct iwl_bt_iterator_data data = {
.mvm = mvm,
.notif = &mvm->last_bt_notif,
.reduced_tx_power = true,
};
struct iwl_bt_coex_ci_cmd cmd = {};
u8 ci_bw_idx;
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
if (memcmp(&cmd, &mvm->last_bt_ci_cmd, sizeof(cmd))) {
if (iwl_mvm_send_cmd_pdu(mvm, BT_COEX_CI, CMD_SYNC,
sizeof(cmd), &cmd))
IWL_ERR(mvm, "Failed to send BT_CI cmd");
memcpy(&mvm->last_bt_ci_cmd, &cmd, sizeof(cmd));
}
data.reduced_tx_power = data.reduced_tx_power && data.num_bss_ifaces;
if (iwl_mvm_bt_udpate_ctrl_kill_msk(mvm, data.reduced_tx_power))
IWL_ERR(mvm, "Failed to update the ctrl_kill_msk\n");
}
int iwl_mvm_rx_bt_coex_notif(struct iwl_mvm *mvm,
struct iwl_rx_cmd_buffer *rxb,
struct iwl_device_cmd *dev_cmd)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
struct iwl_bt_coex_profile_notif *notif = (void *)pkt->data;
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
memcpy(&mvm->last_bt_notif, notif, sizeof(mvm->last_bt_notif));
iwl_mvm_bt_coex_notif_handle(mvm);
return 0;
}
static void iwl_mvm_bt_rssi_iterator(void *_data, u8 *mac,
struct ieee80211_vif *vif)
{
struct iwl_mvm_vif *mvmvif = (void *)vif->drv_priv;
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
data->num_bss_ifaces++;
if (!mvmsta->bt_reduced_txpower)
data->reduced_tx_power = false;
}
void iwl_mvm_bt_rssi_event(struct iwl_mvm *mvm, struct ieee80211_vif *vif,
enum ieee80211_rssi_event rssi_event)
{
struct iwl_mvm_vif *mvmvif = (void *)vif->drv_priv;
struct iwl_bt_iterator_data data = {
.mvm = mvm,
.reduced_tx_power = true,
};
int ret;
lockdep_assert_held(&mvm->mutex);
if (mvmvif->ap_sta_id == IWL_MVM_STATION_COUNT)
return;
if (!mvm->last_bt_notif.bt_status)
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
data.reduced_tx_power = data.reduced_tx_power && data.num_bss_ifaces;
if (iwl_mvm_bt_udpate_ctrl_kill_msk(mvm, data.reduced_tx_power))
IWL_ERR(mvm, "Failed to update the ctrl_kill_msk\n");
}
u16 iwl_mvm_bt_coex_agg_time_limit(struct iwl_mvm *mvm,
struct ieee80211_sta *sta)
{
struct iwl_mvm_sta *mvmsta = iwl_mvm_sta_from_mac80211(sta);
enum iwl_bt_coex_lut_type lut_type;
if (le32_to_cpu(mvm->last_bt_notif.bt_activity_grading) <
BT_HIGH_TRAFFIC)
return LINK_QUAL_AGG_TIME_LIMIT_DEF;
lut_type = iwl_get_coex_type(mvm, mvmsta->vif);
if (lut_type == BT_COEX_LOOSE_LUT)
return LINK_QUAL_AGG_TIME_LIMIT_DEF;
return LINK_QUAL_AGG_TIME_LIMIT_BT_ACT;
}
bool iwl_mvm_bt_coex_is_mimo_allowed(struct iwl_mvm *mvm,
struct ieee80211_sta *sta)
{
struct iwl_mvm_sta *mvmsta = iwl_mvm_sta_from_mac80211(sta);
if (le32_to_cpu(mvm->last_bt_notif.bt_activity_grading) <
BT_HIGH_TRAFFIC)
return true;
return iwl_get_coex_type(mvm, mvmsta->vif) == BT_COEX_TIGHT_LUT;
}
void iwl_mvm_bt_coex_vif_change(struct iwl_mvm *mvm)
{
if (!(mvm->fw->ucode_capa.flags & IWL_UCODE_TLV_FLAGS_NEWBT_COEX))
return;
iwl_mvm_bt_coex_notif_handle(mvm);
}
