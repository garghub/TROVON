static void iwl_mvm_power_log(struct iwl_mvm *mvm,
struct iwl_powertable_cmd *cmd)
{
IWL_DEBUG_POWER(mvm,
"Sending power table command for power level %d, flags = 0x%X\n",
iwlmvm_mod_params.power_scheme,
le16_to_cpu(cmd->flags));
IWL_DEBUG_POWER(mvm, "Keep alive = %u sec\n", cmd->keep_alive_seconds);
if (cmd->flags & cpu_to_le16(POWER_FLAGS_POWER_MANAGEMENT_ENA_MSK)) {
IWL_DEBUG_POWER(mvm, "Rx timeout = %u usec\n",
le32_to_cpu(cmd->rx_data_timeout));
IWL_DEBUG_POWER(mvm, "Tx timeout = %u usec\n",
le32_to_cpu(cmd->tx_data_timeout));
IWL_DEBUG_POWER(mvm, "LP RX RSSI threshold = %u\n",
cmd->lprx_rssi_threshold);
}
}
void iwl_mvm_power_build_cmd(struct iwl_mvm *mvm, struct ieee80211_vif *vif,
struct iwl_powertable_cmd *cmd)
{
struct ieee80211_hw *hw = mvm->hw;
struct ieee80211_chanctx_conf *chanctx_conf;
struct ieee80211_channel *chan;
int dtimper, dtimper_msec;
int keep_alive;
bool radar_detect = false;
cmd->keep_alive_seconds = POWER_KEEP_ALIVE_PERIOD_SEC;
if (iwlmvm_mod_params.power_scheme == IWL_POWER_SCHEME_CAM)
return;
cmd->flags |= cpu_to_le16(POWER_FLAGS_POWER_SAVE_ENA_MSK);
if (!vif->bss_conf.ps)
return;
cmd->flags |= cpu_to_le16(POWER_FLAGS_POWER_MANAGEMENT_ENA_MSK);
dtimper = hw->conf.ps_dtim_period ?: 1;
rcu_read_lock();
chanctx_conf = rcu_dereference(vif->chanctx_conf);
WARN_ON(!chanctx_conf);
if (chanctx_conf) {
chan = chanctx_conf->def.chan;
radar_detect = chan->flags & IEEE80211_CHAN_RADAR;
}
rcu_read_unlock();
if (!radar_detect && (dtimper <= 10) &&
(iwlmvm_mod_params.power_scheme == IWL_POWER_SCHEME_LP))
cmd->flags |= cpu_to_le16(POWER_FLAGS_SKIP_OVER_DTIM_MSK);
dtimper_msec = dtimper * vif->bss_conf.beacon_int;
keep_alive = max_t(int, 3 * dtimper_msec,
MSEC_PER_SEC * cmd->keep_alive_seconds);
keep_alive = DIV_ROUND_UP(keep_alive, MSEC_PER_SEC);
cmd->keep_alive_seconds = keep_alive;
cmd->rx_data_timeout = cpu_to_le32(100 * USEC_PER_MSEC);
cmd->tx_data_timeout = cpu_to_le32(100 * USEC_PER_MSEC);
}
int iwl_mvm_power_update_mode(struct iwl_mvm *mvm, struct ieee80211_vif *vif)
{
struct iwl_powertable_cmd cmd = {};
if (vif->type != NL80211_IFTYPE_STATION || vif->p2p)
return 0;
iwl_mvm_power_build_cmd(mvm, vif, &cmd);
iwl_mvm_power_log(mvm, &cmd);
return iwl_mvm_send_cmd_pdu(mvm, POWER_TABLE_CMD, CMD_SYNC,
sizeof(cmd), &cmd);
}
int iwl_mvm_power_disable(struct iwl_mvm *mvm, struct ieee80211_vif *vif)
{
struct iwl_powertable_cmd cmd = {};
if (vif->type != NL80211_IFTYPE_STATION || vif->p2p)
return 0;
if (iwlmvm_mod_params.power_scheme != IWL_POWER_SCHEME_CAM)
cmd.flags |= cpu_to_le16(POWER_FLAGS_POWER_SAVE_ENA_MSK);
iwl_mvm_power_log(mvm, &cmd);
return iwl_mvm_send_cmd_pdu(mvm, POWER_TABLE_CMD, CMD_ASYNC,
sizeof(cmd), &cmd);
}
