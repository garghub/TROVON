const char *get_cmd_string(u8 cmd)
{
switch (cmd) {
IWL_CMD(REPLY_ALIVE);
IWL_CMD(REPLY_ERROR);
IWL_CMD(REPLY_RXON);
IWL_CMD(REPLY_RXON_ASSOC);
IWL_CMD(REPLY_QOS_PARAM);
IWL_CMD(REPLY_RXON_TIMING);
IWL_CMD(REPLY_ADD_STA);
IWL_CMD(REPLY_REMOVE_STA);
IWL_CMD(REPLY_REMOVE_ALL_STA);
IWL_CMD(REPLY_TXFIFO_FLUSH);
IWL_CMD(REPLY_WEPKEY);
IWL_CMD(REPLY_TX);
IWL_CMD(REPLY_LEDS_CMD);
IWL_CMD(REPLY_TX_LINK_QUALITY_CMD);
IWL_CMD(COEX_PRIORITY_TABLE_CMD);
IWL_CMD(COEX_MEDIUM_NOTIFICATION);
IWL_CMD(COEX_EVENT_CMD);
IWL_CMD(REPLY_QUIET_CMD);
IWL_CMD(REPLY_CHANNEL_SWITCH);
IWL_CMD(CHANNEL_SWITCH_NOTIFICATION);
IWL_CMD(REPLY_SPECTRUM_MEASUREMENT_CMD);
IWL_CMD(SPECTRUM_MEASURE_NOTIFICATION);
IWL_CMD(POWER_TABLE_CMD);
IWL_CMD(PM_SLEEP_NOTIFICATION);
IWL_CMD(PM_DEBUG_STATISTIC_NOTIFIC);
IWL_CMD(REPLY_SCAN_CMD);
IWL_CMD(REPLY_SCAN_ABORT_CMD);
IWL_CMD(SCAN_START_NOTIFICATION);
IWL_CMD(SCAN_RESULTS_NOTIFICATION);
IWL_CMD(SCAN_COMPLETE_NOTIFICATION);
IWL_CMD(BEACON_NOTIFICATION);
IWL_CMD(REPLY_TX_BEACON);
IWL_CMD(WHO_IS_AWAKE_NOTIFICATION);
IWL_CMD(QUIET_NOTIFICATION);
IWL_CMD(REPLY_TX_PWR_TABLE_CMD);
IWL_CMD(MEASURE_ABORT_NOTIFICATION);
IWL_CMD(REPLY_BT_CONFIG);
IWL_CMD(REPLY_STATISTICS_CMD);
IWL_CMD(STATISTICS_NOTIFICATION);
IWL_CMD(REPLY_CARD_STATE_CMD);
IWL_CMD(CARD_STATE_NOTIFICATION);
IWL_CMD(MISSED_BEACONS_NOTIFICATION);
IWL_CMD(REPLY_CT_KILL_CONFIG_CMD);
IWL_CMD(SENSITIVITY_CMD);
IWL_CMD(REPLY_PHY_CALIBRATION_CMD);
IWL_CMD(REPLY_RX_PHY_CMD);
IWL_CMD(REPLY_RX_MPDU_CMD);
IWL_CMD(REPLY_RX);
IWL_CMD(REPLY_COMPRESSED_BA);
IWL_CMD(CALIBRATION_CFG_CMD);
IWL_CMD(CALIBRATION_RES_NOTIFICATION);
IWL_CMD(CALIBRATION_COMPLETE_NOTIFICATION);
IWL_CMD(REPLY_TX_POWER_DBM_CMD);
IWL_CMD(TEMPERATURE_NOTIFICATION);
IWL_CMD(TX_ANT_CONFIGURATION_CMD);
IWL_CMD(REPLY_BT_COEX_PROFILE_NOTIF);
IWL_CMD(REPLY_BT_COEX_PRIO_TABLE);
IWL_CMD(REPLY_BT_COEX_PROT_ENV);
IWL_CMD(REPLY_WIPAN_PARAMS);
IWL_CMD(REPLY_WIPAN_RXON);
IWL_CMD(REPLY_WIPAN_RXON_TIMING);
IWL_CMD(REPLY_WIPAN_RXON_ASSOC);
IWL_CMD(REPLY_WIPAN_QOS_PARAM);
IWL_CMD(REPLY_WIPAN_WEPKEY);
IWL_CMD(REPLY_WIPAN_P2P_CHANNEL_SWITCH);
IWL_CMD(REPLY_WIPAN_NOA_NOTIFICATION);
IWL_CMD(REPLY_WIPAN_DEACTIVATION_COMPLETE);
default:
return "UNKNOWN";
}
}
static void iwl_generic_cmd_callback(struct iwl_priv *priv,
struct iwl_device_cmd *cmd,
struct iwl_rx_packet *pkt)
{
if (pkt->hdr.flags & IWL_CMD_FAILED_MSK) {
IWL_ERR(priv, "Bad return from %s (0x%08X)\n",
get_cmd_string(cmd->hdr.cmd), pkt->hdr.flags);
return;
}
#ifdef CONFIG_IWLWIFI_DEBUG
switch (cmd->hdr.cmd) {
case REPLY_TX_LINK_QUALITY_CMD:
case SENSITIVITY_CMD:
IWL_DEBUG_HC_DUMP(priv, "back from %s (0x%08X)\n",
get_cmd_string(cmd->hdr.cmd), pkt->hdr.flags);
break;
default:
IWL_DEBUG_HC(priv, "back from %s (0x%08X)\n",
get_cmd_string(cmd->hdr.cmd), pkt->hdr.flags);
}
#endif
}
static int iwl_send_cmd_async(struct iwl_priv *priv, struct iwl_host_cmd *cmd)
{
int ret;
if (WARN_ON(!(cmd->flags & CMD_ASYNC)))
return -EINVAL;
if (WARN_ON(cmd->flags & CMD_WANT_SKB))
return -EINVAL;
if (!cmd->callback)
cmd->callback = iwl_generic_cmd_callback;
if (test_bit(STATUS_EXIT_PENDING, &priv->status))
return -EBUSY;
ret = iwl_enqueue_hcmd(priv, cmd);
if (ret < 0) {
IWL_ERR(priv, "Error sending %s: enqueue_hcmd failed: %d\n",
get_cmd_string(cmd->id), ret);
return ret;
}
return 0;
}
int iwl_send_cmd_sync(struct iwl_priv *priv, struct iwl_host_cmd *cmd)
{
int cmd_idx;
int ret;
if (WARN_ON(cmd->flags & CMD_ASYNC))
return -EINVAL;
if (WARN_ON(cmd->callback))
return -EINVAL;
IWL_DEBUG_INFO(priv, "Attempting to send sync command %s\n",
get_cmd_string(cmd->id));
set_bit(STATUS_HCMD_ACTIVE, &priv->status);
IWL_DEBUG_INFO(priv, "Setting HCMD_ACTIVE for command %s\n",
get_cmd_string(cmd->id));
cmd_idx = iwl_enqueue_hcmd(priv, cmd);
if (cmd_idx < 0) {
ret = cmd_idx;
clear_bit(STATUS_HCMD_ACTIVE, &priv->status);
IWL_ERR(priv, "Error sending %s: enqueue_hcmd failed: %d\n",
get_cmd_string(cmd->id), ret);
return ret;
}
ret = wait_event_interruptible_timeout(priv->wait_command_queue,
!test_bit(STATUS_HCMD_ACTIVE, &priv->status),
HOST_COMPLETE_TIMEOUT);
if (!ret) {
if (test_bit(STATUS_HCMD_ACTIVE, &priv->status)) {
IWL_ERR(priv,
"Error sending %s: time out after %dms.\n",
get_cmd_string(cmd->id),
jiffies_to_msecs(HOST_COMPLETE_TIMEOUT));
clear_bit(STATUS_HCMD_ACTIVE, &priv->status);
IWL_DEBUG_INFO(priv, "Clearing HCMD_ACTIVE for command %s\n",
get_cmd_string(cmd->id));
ret = -ETIMEDOUT;
goto cancel;
}
}
if (test_bit(STATUS_RF_KILL_HW, &priv->status)) {
IWL_ERR(priv, "Command %s aborted: RF KILL Switch\n",
get_cmd_string(cmd->id));
ret = -ECANCELED;
goto fail;
}
if (test_bit(STATUS_FW_ERROR, &priv->status)) {
IWL_ERR(priv, "Command %s failed: FW Error\n",
get_cmd_string(cmd->id));
ret = -EIO;
goto fail;
}
if ((cmd->flags & CMD_WANT_SKB) && !cmd->reply_page) {
IWL_ERR(priv, "Error: Response NULL in '%s'\n",
get_cmd_string(cmd->id));
ret = -EIO;
goto cancel;
}
return 0;
cancel:
if (cmd->flags & CMD_WANT_SKB) {
priv->txq[priv->cmd_queue].meta[cmd_idx].flags &=
~CMD_WANT_SKB;
}
fail:
if (cmd->reply_page) {
iwl_free_pages(priv, cmd->reply_page);
cmd->reply_page = 0;
}
return ret;
}
int iwl_send_cmd(struct iwl_priv *priv, struct iwl_host_cmd *cmd)
{
if (cmd->flags & CMD_ASYNC)
return iwl_send_cmd_async(priv, cmd);
return iwl_send_cmd_sync(priv, cmd);
}
int iwl_send_cmd_pdu(struct iwl_priv *priv, u8 id, u16 len, const void *data)
{
struct iwl_host_cmd cmd = {
.id = id,
.len = { len, },
.data = { data, },
};
return iwl_send_cmd_sync(priv, &cmd);
}
int iwl_send_cmd_pdu_async(struct iwl_priv *priv,
u8 id, u16 len, const void *data,
void (*callback)(struct iwl_priv *priv,
struct iwl_device_cmd *cmd,
struct iwl_rx_packet *pkt))
{
struct iwl_host_cmd cmd = {
.id = id,
.len = { len, },
.data = { data, },
};
cmd.flags |= CMD_ASYNC;
cmd.callback = callback;
return iwl_send_cmd_async(priv, &cmd);
}
