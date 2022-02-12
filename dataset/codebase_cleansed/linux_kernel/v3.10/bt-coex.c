static inline bool is_loose_coex(void)
{
return iwlwifi_mod_params.ant_coupling >
IWL_BT_ANTENNA_COUPLING_THRESHOLD;
}
int iwl_send_bt_prio_tbl(struct iwl_mvm *mvm)
{
return iwl_mvm_send_cmd_pdu(mvm, BT_COEX_PRIO_TABLE, CMD_SYNC,
sizeof(struct iwl_bt_coex_prio_tbl_cmd),
&iwl_bt_prio_tbl);
}
static int iwl_send_bt_env(struct iwl_mvm *mvm, u8 action, u8 type)
{
struct iwl_bt_coex_prot_env_cmd env_cmd;
int ret;
env_cmd.action = action;
env_cmd.type = type;
ret = iwl_mvm_send_cmd_pdu(mvm, BT_COEX_PROT_ENV, CMD_SYNC,
sizeof(env_cmd), &env_cmd);
if (ret)
IWL_ERR(mvm, "failed to send BT env command\n");
return ret;
}
int iwl_send_bt_init_conf(struct iwl_mvm *mvm)
{
struct iwl_bt_coex_cmd cmd = {
.max_kill = 5,
.bt3_time_t7_value = 1,
.bt3_prio_sample_time = 2,
.bt3_timer_t2_value = 0xc,
};
int ret;
cmd.flags = iwlwifi_mod_params.bt_coex_active ?
BT_COEX_NW : BT_COEX_DISABLE;
cmd.flags |= BT_CH_PRIMARY_EN | BT_SYNC_2_BT_DISABLE;
cmd.valid_bit_msk = cpu_to_le16(BT_VALID_ENABLE |
BT_VALID_BT_PRIO_BOOST |
BT_VALID_MAX_KILL |
BT_VALID_3W_TMRS |
BT_VALID_KILL_ACK |
BT_VALID_KILL_CTS |
BT_VALID_REDUCED_TX_POWER |
BT_VALID_LUT);
if (is_loose_coex())
memcpy(&cmd.decision_lut, iwl_loose_lookup,
sizeof(iwl_tight_lookup));
else
memcpy(&cmd.decision_lut, iwl_tight_lookup,
sizeof(iwl_tight_lookup));
cmd.bt_prio_boost = cpu_to_le32(IWL_BT_DEFAULT_BOOST);
cmd.kill_ack_msk =
cpu_to_le32(iwl_bt_ack_kill_msk[BT_KILL_MSK_DEFAULT]);
cmd.kill_cts_msk =
cpu_to_le32(iwl_bt_cts_kill_msk[BT_KILL_MSK_DEFAULT]);
memset(&mvm->last_bt_notif, 0, sizeof(mvm->last_bt_notif));
ret = iwl_send_bt_env(mvm, BT_COEX_ENV_OPEN,
BT_COEX_PRIO_TBL_EVT_INIT_CALIB2);
if (ret)
return ret;
ret = iwl_send_bt_env(mvm, BT_COEX_ENV_CLOSE,
BT_COEX_PRIO_TBL_EVT_INIT_CALIB2);
if (ret)
return ret;
return iwl_mvm_send_cmd_pdu(mvm, BT_CONFIG, CMD_SYNC,
sizeof(cmd), &cmd);
}
static int iwl_mvm_bt_udpate_ctrl_kill_msk(struct iwl_mvm *mvm,
bool reduced_tx_power)
{
enum iwl_bt_kill_msk bt_kill_msk;
struct iwl_bt_coex_cmd cmd = {};
struct iwl_bt_coex_profile_notif *notif = &mvm->last_bt_notif;
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
cmd.kill_ack_msk = cpu_to_le32(iwl_bt_ack_kill_msk[bt_kill_msk]);
cmd.kill_cts_msk = cpu_to_le32(iwl_bt_cts_kill_msk[bt_kill_msk]);
cmd.valid_bit_msk = cpu_to_le16(BT_VALID_KILL_ACK | BT_VALID_KILL_CTS);
IWL_DEBUG_COEX(mvm, "bt_kill_msk = %d\n", bt_kill_msk);
return iwl_mvm_send_cmd_pdu(mvm, BT_CONFIG, CMD_SYNC,
sizeof(cmd), &cmd);
}
static int iwl_mvm_bt_coex_reduced_txp(struct iwl_mvm *mvm, u8 sta_id,
bool enable)
{
struct iwl_bt_coex_cmd cmd = {
.valid_bit_msk = cpu_to_le16(BT_VALID_REDUCED_TX_POWER),
.bt_reduced_tx_power = sta_id,
};
struct ieee80211_sta *sta;
struct iwl_mvm_sta *mvmsta;
if (sta_id == IWL_MVM_STATION_COUNT)
return 0;
sta = rcu_dereference_protected(mvm->fw_id_to_mac_id[sta_id],
lockdep_is_held(&mvm->mutex));
mvmsta = (void *)sta->drv_priv;
if (mvmsta->bt_reduced_txpower == enable)
return 0;
if (enable)
cmd.bt_reduced_tx_power |= BT_REDUCED_TX_POWER_BIT;
IWL_DEBUG_COEX(mvm, "%sable reduced Tx Power for sta %d\n",
enable ? "en" : "dis", sta_id);
mvmsta->bt_reduced_txpower = enable;
return iwl_mvm_send_cmd_pdu(mvm, BT_CONFIG, CMD_ASYNC,
sizeof(cmd), &cmd);
}
static void iwl_mvm_bt_notif_iterator(void *_data, u8 *mac,
struct ieee80211_vif *vif)
{
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
struct iwl_bt_iterator_data *data = _data;
struct iwl_mvm *mvm = data->mvm;
struct ieee80211_chanctx_conf *chanctx_conf;
enum ieee80211_smps_mode smps_mode;
enum ieee80211_band band;
int ave_rssi;
if (vif->type != NL80211_IFTYPE_STATION)
return;
rcu_read_lock();
chanctx_conf = rcu_dereference(vif->chanctx_conf);
if (chanctx_conf && chanctx_conf->def.chan)
band = chanctx_conf->def.chan->band;
else
band = -1;
rcu_read_unlock();
smps_mode = IEEE80211_SMPS_AUTOMATIC;
if (band != IEEE80211_BAND_2GHZ) {
ieee80211_request_smps(vif, smps_mode);
return;
}
if (data->notif->bt_status)
smps_mode = IEEE80211_SMPS_DYNAMIC;
if (data->notif->bt_traffic_load >= IWL_BT_LOAD_FORCE_SISO_THRESHOLD)
smps_mode = IEEE80211_SMPS_STATIC;
IWL_DEBUG_COEX(data->mvm,
"mac %d: bt_status %d traffic_load %d smps_req %d\n",
mvmvif->id, data->notif->bt_status,
data->notif->bt_traffic_load, smps_mode);
ieee80211_request_smps(vif, smps_mode);
if (is_loose_coex())
return;
data->num_bss_ifaces++;
if (!BT_MBOX_MSG(data->notif, 3, OPEN_CON_2)) {
if (iwl_mvm_bt_coex_reduced_txp(mvm, mvmvif->ap_sta_id, false))
IWL_ERR(mvm, "Couldn't send BT_CONFIG cmd\n");
data->reduced_tx_power = false;
ieee80211_disable_rssi_reports(vif);
return;
}
ave_rssi = ieee80211_ave_rssi(vif);
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
ieee80211_enable_rssi_reports(vif, BT_DISABLE_REDUCED_TXPOWER_THRESHOLD,
BT_ENABLE_REDUCED_TXPOWER_THRESHOLD);
}
static void iwl_mvm_bt_coex_notif_handle(struct iwl_mvm *mvm)
{
struct iwl_bt_iterator_data data = {
.mvm = mvm,
.notif = &mvm->last_bt_notif,
.reduced_tx_power = true,
};
ieee80211_iterate_active_interfaces_atomic(
mvm->hw, IEEE80211_IFACE_ITER_NORMAL,
iwl_mvm_bt_notif_iterator, &data);
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
IWL_DEBUG_COEX(mvm, "\tBT %salive\n", notif->bt_status ? "" : "not ");
IWL_DEBUG_COEX(mvm, "\tBT open conn %d\n", notif->bt_open_conn);
IWL_DEBUG_COEX(mvm, "\tBT traffic load %d\n", notif->bt_traffic_load);
IWL_DEBUG_COEX(mvm, "\tBT agg traffic load %d\n",
notif->bt_agg_traffic_load);
IWL_DEBUG_COEX(mvm, "\tBT ci compliance %d\n", notif->bt_ci_compliance);
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
if (vif->type != NL80211_IFTYPE_STATION ||
mvmvif->ap_sta_id == IWL_MVM_STATION_COUNT)
return;
sta = rcu_dereference_protected(mvm->fw_id_to_mac_id[mvmvif->ap_sta_id],
lockdep_is_held(&mvm->mutex));
mvmsta = (void *)sta->drv_priv;
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
mutex_lock(&mvm->mutex);
if (WARN_ON_ONCE(mvmvif->ap_sta_id == IWL_MVM_STATION_COUNT))
goto out_unlock;
if (!BT_MBOX_MSG(&mvm->last_bt_notif, 3, OPEN_CON_2))
goto out_unlock;
IWL_DEBUG_COEX(mvm, "RSSI for %pM is now %s\n", vif->bss_conf.bssid,
rssi_event == RSSI_EVENT_HIGH ? "HIGH" : "LOW");
if (rssi_event == RSSI_EVENT_LOW || is_loose_coex())
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
out_unlock:
mutex_unlock(&mvm->mutex);
}
void iwl_mvm_bt_coex_vif_assoc(struct iwl_mvm *mvm, struct ieee80211_vif *vif)
{
struct ieee80211_chanctx_conf *chanctx_conf;
enum ieee80211_band band;
rcu_read_lock();
chanctx_conf = rcu_dereference(vif->chanctx_conf);
if (chanctx_conf && chanctx_conf->def.chan)
band = chanctx_conf->def.chan->band;
else
band = -1;
rcu_read_unlock();
if (band == IEEE80211_BAND_2GHZ)
return;
memset(&mvm->last_bt_notif, 0, sizeof(mvm->last_bt_notif));
iwl_mvm_bt_coex_notif_handle(mvm);
}
