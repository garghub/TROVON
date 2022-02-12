static void iwl_static_sleep_cmd(struct iwl_priv *priv,
struct iwl_powertable_cmd *cmd,
enum iwl_power_level lvl, int period)
{
const struct iwl_power_vec_entry *table;
int max_sleep[IWL_POWER_VEC_SIZE] = { 0 };
int i;
u8 skip;
u32 slp_itrvl;
if (priv->lib->adv_pm) {
table = apm_range_2;
if (period <= IWL_DTIM_RANGE_1_MAX)
table = apm_range_1;
if (period <= IWL_DTIM_RANGE_0_MAX)
table = apm_range_0;
} else {
table = range_2;
if (period <= IWL_DTIM_RANGE_1_MAX)
table = range_1;
if (period <= IWL_DTIM_RANGE_0_MAX)
table = range_0;
}
if (WARN_ON(lvl < 0 || lvl >= IWL_POWER_NUM))
memset(cmd, 0, sizeof(*cmd));
else
*cmd = table[lvl].cmd;
if (period == 0) {
skip = 0;
period = 1;
for (i = 0; i < IWL_POWER_VEC_SIZE; i++)
max_sleep[i] = 1;
} else {
skip = table[lvl].no_dtim;
for (i = 0; i < IWL_POWER_VEC_SIZE; i++)
max_sleep[i] = le32_to_cpu(cmd->sleep_interval[i]);
max_sleep[IWL_POWER_VEC_SIZE - 1] = skip + 1;
}
slp_itrvl = le32_to_cpu(cmd->sleep_interval[IWL_POWER_VEC_SIZE - 1]);
if (slp_itrvl == 0xFF)
cmd->sleep_interval[IWL_POWER_VEC_SIZE - 1] =
cpu_to_le32(period * (skip + 1));
slp_itrvl = le32_to_cpu(cmd->sleep_interval[IWL_POWER_VEC_SIZE - 1]);
if (slp_itrvl > period)
cmd->sleep_interval[IWL_POWER_VEC_SIZE - 1] =
cpu_to_le32((slp_itrvl / period) * period);
if (skip)
cmd->flags |= IWL_POWER_SLEEP_OVER_DTIM_MSK;
else
cmd->flags &= ~IWL_POWER_SLEEP_OVER_DTIM_MSK;
if (priv->cfg->base_params->shadow_reg_enable)
cmd->flags |= IWL_POWER_SHADOW_REG_ENA;
else
cmd->flags &= ~IWL_POWER_SHADOW_REG_ENA;
if (iwl_advanced_bt_coexist(priv)) {
if (!priv->lib->bt_params->bt_sco_disable)
cmd->flags |= IWL_POWER_BT_SCO_ENA;
else
cmd->flags &= ~IWL_POWER_BT_SCO_ENA;
}
slp_itrvl = le32_to_cpu(cmd->sleep_interval[IWL_POWER_VEC_SIZE - 1]);
if (slp_itrvl > IWL_CONN_MAX_LISTEN_INTERVAL)
cmd->sleep_interval[IWL_POWER_VEC_SIZE - 1] =
cpu_to_le32(IWL_CONN_MAX_LISTEN_INTERVAL);
for (i = IWL_POWER_VEC_SIZE - 1; i >= 0 ; i--) {
if (le32_to_cpu(cmd->sleep_interval[i]) >
(max_sleep[i] * period))
cmd->sleep_interval[i] =
cpu_to_le32(max_sleep[i] * period);
if (i != (IWL_POWER_VEC_SIZE - 1)) {
if (le32_to_cpu(cmd->sleep_interval[i]) >
le32_to_cpu(cmd->sleep_interval[i+1]))
cmd->sleep_interval[i] =
cmd->sleep_interval[i+1];
}
}
if (priv->power_data.bus_pm)
cmd->flags |= IWL_POWER_PCI_PM_MSK;
else
cmd->flags &= ~IWL_POWER_PCI_PM_MSK;
IWL_DEBUG_POWER(priv, "numSkipDtim = %u, dtimPeriod = %d\n",
skip, period);
IWL_DEBUG_POWER(priv, "Sleep command for index %d\n", lvl + 1);
}
static void iwl_power_sleep_cam_cmd(struct iwl_priv *priv,
struct iwl_powertable_cmd *cmd)
{
memset(cmd, 0, sizeof(*cmd));
if (priv->power_data.bus_pm)
cmd->flags |= IWL_POWER_PCI_PM_MSK;
IWL_DEBUG_POWER(priv, "Sleep command for CAM\n");
}
static int iwl_set_power(struct iwl_priv *priv, struct iwl_powertable_cmd *cmd)
{
IWL_DEBUG_POWER(priv, "Sending power/sleep command\n");
IWL_DEBUG_POWER(priv, "Flags value = 0x%08X\n", cmd->flags);
IWL_DEBUG_POWER(priv, "Tx timeout = %u\n", le32_to_cpu(cmd->tx_data_timeout));
IWL_DEBUG_POWER(priv, "Rx timeout = %u\n", le32_to_cpu(cmd->rx_data_timeout));
IWL_DEBUG_POWER(priv, "Sleep interval vector = { %d , %d , %d , %d , %d }\n",
le32_to_cpu(cmd->sleep_interval[0]),
le32_to_cpu(cmd->sleep_interval[1]),
le32_to_cpu(cmd->sleep_interval[2]),
le32_to_cpu(cmd->sleep_interval[3]),
le32_to_cpu(cmd->sleep_interval[4]));
return iwl_dvm_send_cmd_pdu(priv, POWER_TABLE_CMD, 0,
sizeof(struct iwl_powertable_cmd), cmd);
}
static void iwl_power_build_cmd(struct iwl_priv *priv,
struct iwl_powertable_cmd *cmd)
{
bool enabled = priv->hw->conf.flags & IEEE80211_CONF_PS;
int dtimper;
if (force_cam) {
iwl_power_sleep_cam_cmd(priv, cmd);
return;
}
dtimper = priv->hw->conf.ps_dtim_period ?: 1;
if (priv->wowlan)
iwl_static_sleep_cmd(priv, cmd, IWL_POWER_INDEX_5, dtimper);
else if (!priv->lib->no_idle_support &&
priv->hw->conf.flags & IEEE80211_CONF_IDLE)
iwl_static_sleep_cmd(priv, cmd, IWL_POWER_INDEX_5, 20);
else if (iwl_tt_is_low_power_state(priv)) {
iwl_static_sleep_cmd(priv, cmd,
iwl_tt_current_power_mode(priv), dtimper);
} else if (!enabled)
iwl_power_sleep_cam_cmd(priv, cmd);
else if (priv->power_data.debug_sleep_level_override >= 0)
iwl_static_sleep_cmd(priv, cmd,
priv->power_data.debug_sleep_level_override,
dtimper);
else {
if (iwlwifi_mod_params.power_level > IWL_POWER_INDEX_1 &&
iwlwifi_mod_params.power_level <= IWL_POWER_NUM)
iwl_static_sleep_cmd(priv, cmd,
iwlwifi_mod_params.power_level - 1, dtimper);
else
iwl_static_sleep_cmd(priv, cmd,
IWL_POWER_INDEX_1, dtimper);
}
}
int iwl_power_set_mode(struct iwl_priv *priv, struct iwl_powertable_cmd *cmd,
bool force)
{
int ret;
bool update_chains;
lockdep_assert_held(&priv->mutex);
update_chains = priv->chain_noise_data.state == IWL_CHAIN_NOISE_DONE ||
priv->chain_noise_data.state == IWL_CHAIN_NOISE_ALIVE;
if (!memcmp(&priv->power_data.sleep_cmd, cmd, sizeof(*cmd)) && !force)
return 0;
if (!iwl_is_ready_rf(priv))
return -EIO;
memcpy(&priv->power_data.sleep_cmd_next, cmd, sizeof(*cmd));
if (test_bit(STATUS_SCANNING, &priv->status) && !force) {
IWL_DEBUG_INFO(priv, "Defer power set mode while scanning\n");
return 0;
}
if (cmd->flags & IWL_POWER_DRIVER_ALLOW_SLEEP_MSK)
iwl_dvm_set_pmi(priv, true);
ret = iwl_set_power(priv, cmd);
if (!ret) {
if (!(cmd->flags & IWL_POWER_DRIVER_ALLOW_SLEEP_MSK))
iwl_dvm_set_pmi(priv, false);
if (update_chains)
iwl_update_chain_flags(priv);
else
IWL_DEBUG_POWER(priv,
"Cannot update the power, chain noise "
"calibration running: %d\n",
priv->chain_noise_data.state);
memcpy(&priv->power_data.sleep_cmd, cmd, sizeof(*cmd));
} else
IWL_ERR(priv, "set power fail, ret = %d\n", ret);
return ret;
}
int iwl_power_update_mode(struct iwl_priv *priv, bool force)
{
struct iwl_powertable_cmd cmd;
iwl_power_build_cmd(priv, &cmd);
return iwl_power_set_mode(priv, &cmd, force);
}
void iwl_power_initialize(struct iwl_priv *priv)
{
priv->power_data.bus_pm = priv->trans->pm_support;
priv->power_data.debug_sleep_level_override = -1;
memset(&priv->power_data.sleep_cmd, 0,
sizeof(priv->power_data.sleep_cmd));
}
