static void iwl_power_build_cmd(struct iwl_mvm *mvm, struct ieee80211_vif *vif,
struct iwl_powertable_cmd *cmd)
{
struct ieee80211_hw *hw = mvm->hw;
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
struct ieee80211_chanctx_conf *chanctx_conf;
struct ieee80211_channel *chan;
int dtimper, dtimper_msec;
int keep_alive;
bool radar_detect = false;
cmd->id_and_color = cpu_to_le32(FW_CMD_ID_AND_COLOR(mvmvif->id,
mvmvif->color));
cmd->action = cpu_to_le32(FW_CTXT_ACTION_MODIFY);
if ((!vif->bss_conf.ps) ||
(iwlmvm_mod_params.power_scheme == IWL_POWER_SCHEME_CAM))
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
(iwlmvm_mod_params.power_scheme == IWL_POWER_SCHEME_LP)) {
cmd->flags |= cpu_to_le16(POWER_FLAGS_SLEEP_OVER_DTIM_MSK);
cmd->num_skip_dtim = 2;
}
dtimper_msec = dtimper * vif->bss_conf.beacon_int;
keep_alive = max_t(int, 3 * dtimper_msec,
MSEC_PER_SEC * POWER_KEEP_ALIVE_PERIOD_SEC);
keep_alive = DIV_ROUND_UP(keep_alive, MSEC_PER_SEC);
cmd->keep_alive_seconds = cpu_to_le16(keep_alive);
if (iwlmvm_mod_params.power_scheme == IWL_POWER_SCHEME_LP) {
cmd->rx_data_timeout = cpu_to_le32(10);
cmd->tx_data_timeout = cpu_to_le32(10);
} else {
cmd->rx_data_timeout = cpu_to_le32(50);
cmd->tx_data_timeout = cpu_to_le32(50);
}
}
int iwl_mvm_power_update_mode(struct iwl_mvm *mvm, struct ieee80211_vif *vif)
{
struct iwl_powertable_cmd cmd = {};
if (!iwlwifi_mod_params.power_save) {
IWL_DEBUG_POWER(mvm, "Power management is not allowed\n");
return 0;
}
if (vif->type != NL80211_IFTYPE_STATION || vif->p2p)
return 0;
iwl_power_build_cmd(mvm, vif, &cmd);
IWL_DEBUG_POWER(mvm,
"Sending power table command on mac id 0x%X for power level %d, flags = 0x%X\n",
cmd.id_and_color, iwlmvm_mod_params.power_scheme,
le16_to_cpu(cmd.flags));
if (cmd.flags & cpu_to_le16(POWER_FLAGS_POWER_MANAGEMENT_ENA_MSK)) {
IWL_DEBUG_POWER(mvm, "Keep alive = %u sec\n",
le16_to_cpu(cmd.keep_alive_seconds));
IWL_DEBUG_POWER(mvm, "Rx timeout = %u usec\n",
le32_to_cpu(cmd.rx_data_timeout));
IWL_DEBUG_POWER(mvm, "Tx timeout = %u usec\n",
le32_to_cpu(cmd.tx_data_timeout));
IWL_DEBUG_POWER(mvm, "Rx timeout (uAPSD) = %u usec\n",
le32_to_cpu(cmd.rx_data_timeout_uapsd));
IWL_DEBUG_POWER(mvm, "Tx timeout = %u usec\n",
le32_to_cpu(cmd.tx_data_timeout_uapsd));
IWL_DEBUG_POWER(mvm, "LP RX RSSI threshold = %u\n",
cmd.lprx_rssi_threshold);
IWL_DEBUG_POWER(mvm, "DTIMs to skip = %u\n", cmd.num_skip_dtim);
}
return iwl_mvm_send_cmd_pdu(mvm, POWER_TABLE_CMD, CMD_SYNC,
sizeof(cmd), &cmd);
}
int iwl_mvm_power_disable(struct iwl_mvm *mvm, struct ieee80211_vif *vif)
{
struct iwl_powertable_cmd cmd = {};
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
if (!iwlwifi_mod_params.power_save) {
IWL_DEBUG_POWER(mvm, "Power management is not allowed\n");
return 0;
}
if (vif->type != NL80211_IFTYPE_STATION || vif->p2p)
return 0;
cmd.id_and_color = cpu_to_le32(FW_CMD_ID_AND_COLOR(mvmvif->id,
mvmvif->color));
cmd.action = cpu_to_le32(FW_CTXT_ACTION_MODIFY);
IWL_DEBUG_POWER(mvm,
"Sending power table command on mac id 0x%X for power level %d, flags = 0x%X\n",
cmd.id_and_color, iwlmvm_mod_params.power_scheme,
le16_to_cpu(cmd.flags));
return iwl_mvm_send_cmd_pdu(mvm, POWER_TABLE_CMD, CMD_ASYNC,
sizeof(cmd), &cmd);
}
void iwl_power_get_params(struct iwl_mvm *mvm, struct ieee80211_vif *vif,
struct iwl_powertable_cmd *cmd)
{
iwl_power_build_cmd(mvm, vif, cmd);
}
