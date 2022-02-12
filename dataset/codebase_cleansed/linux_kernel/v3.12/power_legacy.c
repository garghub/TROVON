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
if (cmd->flags & cpu_to_le16(POWER_FLAGS_SKIP_OVER_DTIM_MSK))
IWL_DEBUG_POWER(mvm, "DTIM periods to skip = %u\n",
le32_to_cpu(cmd->skip_dtim_periods));
if (cmd->flags & cpu_to_le16(POWER_FLAGS_LPRX_ENA_MSK))
IWL_DEBUG_POWER(mvm, "LP RX RSSI threshold = %u\n",
le32_to_cpu(cmd->lprx_rssi_threshold));
}
}
static void iwl_mvm_power_build_cmd(struct iwl_mvm *mvm,
struct ieee80211_vif *vif,
struct iwl_powertable_cmd *cmd)
{
struct ieee80211_hw *hw = mvm->hw;
struct ieee80211_chanctx_conf *chanctx_conf;
struct ieee80211_channel *chan;
int dtimper, dtimper_msec;
int keep_alive;
bool radar_detect = false;
struct iwl_mvm_vif *mvmvif __maybe_unused =
iwl_mvm_vif_from_mac80211(vif);
cmd->keep_alive_seconds = POWER_KEEP_ALIVE_PERIOD_SEC;
if (iwlmvm_mod_params.power_scheme == IWL_POWER_SCHEME_CAM)
return;
cmd->flags |= cpu_to_le16(POWER_FLAGS_POWER_SAVE_ENA_MSK);
if (!vif->bss_conf.assoc)
cmd->flags |= cpu_to_le16(POWER_FLAGS_POWER_MANAGEMENT_ENA_MSK);
#ifdef CONFIG_IWLWIFI_DEBUGFS
if (mvmvif->dbgfs_pm.mask & MVM_DEBUGFS_PM_DISABLE_POWER_OFF &&
mvmvif->dbgfs_pm.disable_power_off)
cmd->flags &= cpu_to_le16(~POWER_FLAGS_POWER_SAVE_ENA_MSK);
#endif
if (!vif->bss_conf.ps)
return;
cmd->flags |= cpu_to_le16(POWER_FLAGS_POWER_MANAGEMENT_ENA_MSK);
if (vif->bss_conf.beacon_rate &&
(vif->bss_conf.beacon_rate->bitrate == 10 ||
vif->bss_conf.beacon_rate->bitrate == 60)) {
cmd->flags |= cpu_to_le16(POWER_FLAGS_LPRX_ENA_MSK);
cmd->lprx_rssi_threshold =
cpu_to_le32(POWER_LPRX_RSSI_THRESHOLD);
}
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
(iwlmvm_mod_params.power_scheme == IWL_POWER_SCHEME_LP ||
mvm->cur_ucode == IWL_UCODE_WOWLAN)) {
cmd->flags |= cpu_to_le16(POWER_FLAGS_SKIP_OVER_DTIM_MSK);
cmd->skip_dtim_periods = cpu_to_le32(3);
}
dtimper_msec = dtimper * vif->bss_conf.beacon_int;
keep_alive = max_t(int, 3 * dtimper_msec,
MSEC_PER_SEC * cmd->keep_alive_seconds);
keep_alive = DIV_ROUND_UP(keep_alive, MSEC_PER_SEC);
cmd->keep_alive_seconds = keep_alive;
if (mvm->cur_ucode != IWL_UCODE_WOWLAN) {
cmd->rx_data_timeout = cpu_to_le32(100 * USEC_PER_MSEC);
cmd->tx_data_timeout = cpu_to_le32(100 * USEC_PER_MSEC);
} else {
cmd->rx_data_timeout = cpu_to_le32(10 * USEC_PER_MSEC);
cmd->tx_data_timeout = cpu_to_le32(10 * USEC_PER_MSEC);
}
#ifdef CONFIG_IWLWIFI_DEBUGFS
if (mvmvif->dbgfs_pm.mask & MVM_DEBUGFS_PM_KEEP_ALIVE)
cmd->keep_alive_seconds = mvmvif->dbgfs_pm.keep_alive_seconds;
if (mvmvif->dbgfs_pm.mask & MVM_DEBUGFS_PM_SKIP_OVER_DTIM) {
if (mvmvif->dbgfs_pm.skip_over_dtim)
cmd->flags |=
cpu_to_le16(POWER_FLAGS_SKIP_OVER_DTIM_MSK);
else
cmd->flags &=
cpu_to_le16(~POWER_FLAGS_SKIP_OVER_DTIM_MSK);
}
if (mvmvif->dbgfs_pm.mask & MVM_DEBUGFS_PM_RX_DATA_TIMEOUT)
cmd->rx_data_timeout =
cpu_to_le32(mvmvif->dbgfs_pm.rx_data_timeout);
if (mvmvif->dbgfs_pm.mask & MVM_DEBUGFS_PM_TX_DATA_TIMEOUT)
cmd->tx_data_timeout =
cpu_to_le32(mvmvif->dbgfs_pm.tx_data_timeout);
if (mvmvif->dbgfs_pm.mask & MVM_DEBUGFS_PM_SKIP_DTIM_PERIODS)
cmd->skip_dtim_periods =
cpu_to_le32(mvmvif->dbgfs_pm.skip_dtim_periods);
if (mvmvif->dbgfs_pm.mask & MVM_DEBUGFS_PM_LPRX_ENA) {
if (mvmvif->dbgfs_pm.lprx_ena)
cmd->flags |= cpu_to_le16(POWER_FLAGS_LPRX_ENA_MSK);
else
cmd->flags &= cpu_to_le16(~POWER_FLAGS_LPRX_ENA_MSK);
}
if (mvmvif->dbgfs_pm.mask & MVM_DEBUGFS_PM_LPRX_RSSI_THRESHOLD)
cmd->lprx_rssi_threshold =
cpu_to_le32(mvmvif->dbgfs_pm.lprx_rssi_threshold);
#endif
}
static int iwl_mvm_power_legacy_update_mode(struct iwl_mvm *mvm,
struct ieee80211_vif *vif)
{
int ret;
bool ba_enable;
struct iwl_powertable_cmd cmd = {};
if (vif->type != NL80211_IFTYPE_STATION || vif->p2p)
return 0;
IWL_DEBUG_POWER(mvm, "Currently %d interfaces active\n",
mvm->vif_count);
if (mvm->vif_count > 1)
return 0;
iwl_mvm_power_build_cmd(mvm, vif, &cmd);
iwl_mvm_power_log(mvm, &cmd);
ret = iwl_mvm_send_cmd_pdu(mvm, POWER_TABLE_CMD, CMD_SYNC,
sizeof(cmd), &cmd);
if (ret)
return ret;
ba_enable = !!(cmd.flags &
cpu_to_le16(POWER_FLAGS_POWER_MANAGEMENT_ENA_MSK));
return iwl_mvm_update_beacon_abort(mvm, vif, ba_enable);
}
static int iwl_mvm_power_legacy_disable(struct iwl_mvm *mvm,
struct ieee80211_vif *vif)
{
struct iwl_powertable_cmd cmd = {};
struct iwl_mvm_vif *mvmvif __maybe_unused =
iwl_mvm_vif_from_mac80211(vif);
if (vif->type != NL80211_IFTYPE_STATION || vif->p2p)
return 0;
if (iwlmvm_mod_params.power_scheme != IWL_POWER_SCHEME_CAM)
cmd.flags |= cpu_to_le16(POWER_FLAGS_POWER_SAVE_ENA_MSK);
#ifdef CONFIG_IWLWIFI_DEBUGFS
if (mvmvif->dbgfs_pm.mask & MVM_DEBUGFS_PM_DISABLE_POWER_OFF &&
mvmvif->dbgfs_pm.disable_power_off)
cmd.flags &= cpu_to_le16(~POWER_FLAGS_POWER_SAVE_ENA_MSK);
#endif
iwl_mvm_power_log(mvm, &cmd);
return iwl_mvm_send_cmd_pdu(mvm, POWER_TABLE_CMD, CMD_ASYNC,
sizeof(cmd), &cmd);
}
static int iwl_mvm_power_legacy_dbgfs_read(struct iwl_mvm *mvm,
struct ieee80211_vif *vif, char *buf,
int bufsz)
{
struct iwl_powertable_cmd cmd = {};
int pos = 0;
iwl_mvm_power_build_cmd(mvm, vif, &cmd);
pos += scnprintf(buf+pos, bufsz-pos, "disable_power_off = %d\n",
(cmd.flags &
cpu_to_le16(POWER_FLAGS_POWER_SAVE_ENA_MSK)) ?
0 : 1);
pos += scnprintf(buf+pos, bufsz-pos, "skip_dtim_periods = %d\n",
le32_to_cpu(cmd.skip_dtim_periods));
pos += scnprintf(buf+pos, bufsz-pos, "power_scheme = %d\n",
iwlmvm_mod_params.power_scheme);
pos += scnprintf(buf+pos, bufsz-pos, "flags = 0x%x\n",
le16_to_cpu(cmd.flags));
pos += scnprintf(buf+pos, bufsz-pos, "keep_alive = %d\n",
cmd.keep_alive_seconds);
if (cmd.flags & cpu_to_le16(POWER_FLAGS_POWER_MANAGEMENT_ENA_MSK)) {
pos += scnprintf(buf+pos, bufsz-pos, "skip_over_dtim = %d\n",
(cmd.flags &
cpu_to_le16(POWER_FLAGS_SKIP_OVER_DTIM_MSK)) ?
1 : 0);
pos += scnprintf(buf+pos, bufsz-pos, "rx_data_timeout = %d\n",
le32_to_cpu(cmd.rx_data_timeout));
pos += scnprintf(buf+pos, bufsz-pos, "tx_data_timeout = %d\n",
le32_to_cpu(cmd.tx_data_timeout));
if (cmd.flags & cpu_to_le16(POWER_FLAGS_LPRX_ENA_MSK))
pos += scnprintf(buf+pos, bufsz-pos,
"lprx_rssi_threshold = %d\n",
le32_to_cpu(cmd.lprx_rssi_threshold));
}
return pos;
}
