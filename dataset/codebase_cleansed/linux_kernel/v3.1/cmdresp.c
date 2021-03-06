void lbs_mac_event_disconnected(struct lbs_private *priv)
{
if (priv->connect_status != LBS_CONNECTED)
return;
lbs_deb_enter(LBS_DEB_ASSOC);
msleep_interruptible(1000);
if (priv->wdev->iftype == NL80211_IFTYPE_STATION)
lbs_send_disconnect_notification(priv);
netif_stop_queue(priv->dev);
netif_carrier_off(priv->dev);
kfree_skb(priv->currenttxskb);
priv->currenttxskb = NULL;
priv->tx_pending_len = 0;
priv->connect_status = LBS_DISCONNECTED;
if (priv->psstate != PS_STATE_FULL_POWER) {
lbs_deb_cmd("disconnected, so exit PS mode\n");
lbs_set_ps_mode(priv, PS_MODE_ACTION_EXIT_PS, false);
}
lbs_deb_leave(LBS_DEB_ASSOC);
}
int lbs_process_command_response(struct lbs_private *priv, u8 *data, u32 len)
{
uint16_t respcmd, curcmd;
struct cmd_header *resp;
int ret = 0;
unsigned long flags;
uint16_t result;
lbs_deb_enter(LBS_DEB_HOST);
mutex_lock(&priv->lock);
spin_lock_irqsave(&priv->driver_lock, flags);
if (!priv->cur_cmd) {
lbs_deb_host("CMD_RESP: cur_cmd is NULL\n");
ret = -1;
spin_unlock_irqrestore(&priv->driver_lock, flags);
goto done;
}
resp = (void *)data;
curcmd = le16_to_cpu(priv->cur_cmd->cmdbuf->command);
respcmd = le16_to_cpu(resp->command);
result = le16_to_cpu(resp->result);
lbs_deb_cmd("CMD_RESP: response 0x%04x, seq %d, size %d\n",
respcmd, le16_to_cpu(resp->seqnum), len);
lbs_deb_hex(LBS_DEB_CMD, "CMD_RESP", (void *) resp, len);
if (resp->seqnum != priv->cur_cmd->cmdbuf->seqnum) {
netdev_info(priv->dev,
"Received CMD_RESP with invalid sequence %d (expected %d)\n",
le16_to_cpu(resp->seqnum),
le16_to_cpu(priv->cur_cmd->cmdbuf->seqnum));
spin_unlock_irqrestore(&priv->driver_lock, flags);
ret = -1;
goto done;
}
if (respcmd != CMD_RET(curcmd) &&
respcmd != CMD_RET_802_11_ASSOCIATE && curcmd != CMD_802_11_ASSOCIATE) {
netdev_info(priv->dev, "Invalid CMD_RESP %x to command %x!\n",
respcmd, curcmd);
spin_unlock_irqrestore(&priv->driver_lock, flags);
ret = -1;
goto done;
}
if (resp->result == cpu_to_le16(0x0004)) {
netdev_info(priv->dev,
"Firmware returns DEFER to command %x. Will let it time out...\n",
le16_to_cpu(resp->command));
spin_unlock_irqrestore(&priv->driver_lock, flags);
ret = -1;
goto done;
}
del_timer(&priv->command_timer);
priv->cmd_timed_out = 0;
if (respcmd == CMD_RET(CMD_802_11_PS_MODE)) {
struct cmd_ds_802_11_ps_mode *psmode = (void *) &resp[1];
u16 action = le16_to_cpu(psmode->action);
lbs_deb_host(
"CMD_RESP: PS_MODE cmd reply result 0x%x, action 0x%x\n",
result, action);
if (result) {
lbs_deb_host("CMD_RESP: PS command failed with 0x%x\n",
result);
if (priv->wdev->iftype == NL80211_IFTYPE_MONITOR &&
action == PS_MODE_ACTION_ENTER_PS)
priv->psmode = LBS802_11POWERMODECAM;
} else if (action == PS_MODE_ACTION_ENTER_PS) {
priv->needtowakeup = 0;
priv->psstate = PS_STATE_AWAKE;
lbs_deb_host("CMD_RESP: ENTER_PS command response\n");
if (priv->connect_status != LBS_CONNECTED) {
lbs_deb_host(
"disconnected, invoking lbs_ps_wakeup\n");
spin_unlock_irqrestore(&priv->driver_lock, flags);
mutex_unlock(&priv->lock);
lbs_set_ps_mode(priv, PS_MODE_ACTION_EXIT_PS,
false);
mutex_lock(&priv->lock);
spin_lock_irqsave(&priv->driver_lock, flags);
}
} else if (action == PS_MODE_ACTION_EXIT_PS) {
priv->needtowakeup = 0;
priv->psstate = PS_STATE_FULL_POWER;
lbs_deb_host("CMD_RESP: EXIT_PS command response\n");
} else {
lbs_deb_host("CMD_RESP: PS action 0x%X\n", action);
}
__lbs_complete_command(priv, priv->cur_cmd, result);
spin_unlock_irqrestore(&priv->driver_lock, flags);
ret = 0;
goto done;
}
if ((result != 0 || !(respcmd & 0x8000))) {
lbs_deb_host("CMD_RESP: error 0x%04x in command reply 0x%04x\n",
result, respcmd);
switch (respcmd) {
case CMD_RET(CMD_GET_HW_SPEC):
case CMD_RET(CMD_802_11_RESET):
lbs_deb_host("CMD_RESP: reset failed\n");
break;
}
__lbs_complete_command(priv, priv->cur_cmd, result);
spin_unlock_irqrestore(&priv->driver_lock, flags);
ret = -1;
goto done;
}
spin_unlock_irqrestore(&priv->driver_lock, flags);
if (priv->cur_cmd && priv->cur_cmd->callback) {
ret = priv->cur_cmd->callback(priv, priv->cur_cmd->callback_arg,
resp);
}
spin_lock_irqsave(&priv->driver_lock, flags);
if (priv->cur_cmd) {
__lbs_complete_command(priv, priv->cur_cmd, result);
}
spin_unlock_irqrestore(&priv->driver_lock, flags);
done:
mutex_unlock(&priv->lock);
lbs_deb_leave_args(LBS_DEB_HOST, "ret %d", ret);
return ret;
}
int lbs_process_event(struct lbs_private *priv, u32 event)
{
int ret = 0;
struct cmd_header cmd;
lbs_deb_enter(LBS_DEB_CMD);
switch (event) {
case MACREG_INT_CODE_LINK_SENSED:
lbs_deb_cmd("EVENT: link sensed\n");
break;
case MACREG_INT_CODE_DEAUTHENTICATED:
lbs_deb_cmd("EVENT: deauthenticated\n");
lbs_mac_event_disconnected(priv);
break;
case MACREG_INT_CODE_DISASSOCIATED:
lbs_deb_cmd("EVENT: disassociated\n");
lbs_mac_event_disconnected(priv);
break;
case MACREG_INT_CODE_LINK_LOST_NO_SCAN:
lbs_deb_cmd("EVENT: link lost\n");
lbs_mac_event_disconnected(priv);
break;
case MACREG_INT_CODE_PS_SLEEP:
lbs_deb_cmd("EVENT: ps sleep\n");
if (priv->psstate == PS_STATE_FULL_POWER) {
lbs_deb_cmd(
"EVENT: in FULL POWER mode, ignoreing PS_SLEEP\n");
break;
}
priv->psstate = PS_STATE_PRE_SLEEP;
lbs_ps_confirm_sleep(priv);
break;
case MACREG_INT_CODE_HOST_AWAKE:
lbs_deb_cmd("EVENT: host awake\n");
if (priv->reset_deep_sleep_wakeup)
priv->reset_deep_sleep_wakeup(priv);
priv->is_deep_sleep = 0;
lbs_cmd_async(priv, CMD_802_11_WAKEUP_CONFIRM, &cmd,
sizeof(cmd));
priv->is_host_sleep_activated = 0;
wake_up_interruptible(&priv->host_sleep_q);
break;
case MACREG_INT_CODE_DEEP_SLEEP_AWAKE:
if (priv->reset_deep_sleep_wakeup)
priv->reset_deep_sleep_wakeup(priv);
lbs_deb_cmd("EVENT: ds awake\n");
priv->is_deep_sleep = 0;
priv->wakeup_dev_required = 0;
wake_up_interruptible(&priv->ds_awake_q);
break;
case MACREG_INT_CODE_PS_AWAKE:
lbs_deb_cmd("EVENT: ps awake\n");
if (priv->psstate == PS_STATE_FULL_POWER) {
lbs_deb_cmd(
"EVENT: In FULL POWER mode - ignore PS AWAKE\n");
break;
}
priv->psstate = PS_STATE_AWAKE;
if (priv->needtowakeup) {
lbs_deb_cmd("waking up ...\n");
lbs_set_ps_mode(priv, PS_MODE_ACTION_EXIT_PS, false);
}
break;
case MACREG_INT_CODE_MIC_ERR_UNICAST:
lbs_deb_cmd("EVENT: UNICAST MIC ERROR\n");
lbs_send_mic_failureevent(priv, event);
break;
case MACREG_INT_CODE_MIC_ERR_MULTICAST:
lbs_deb_cmd("EVENT: MULTICAST MIC ERROR\n");
lbs_send_mic_failureevent(priv, event);
break;
case MACREG_INT_CODE_MIB_CHANGED:
lbs_deb_cmd("EVENT: MIB CHANGED\n");
break;
case MACREG_INT_CODE_INIT_DONE:
lbs_deb_cmd("EVENT: INIT DONE\n");
break;
case MACREG_INT_CODE_ADHOC_BCN_LOST:
lbs_deb_cmd("EVENT: ADHOC beacon lost\n");
break;
case MACREG_INT_CODE_RSSI_LOW:
netdev_alert(priv->dev, "EVENT: rssi low\n");
break;
case MACREG_INT_CODE_SNR_LOW:
netdev_alert(priv->dev, "EVENT: snr low\n");
break;
case MACREG_INT_CODE_MAX_FAIL:
netdev_alert(priv->dev, "EVENT: max fail\n");
break;
case MACREG_INT_CODE_RSSI_HIGH:
netdev_alert(priv->dev, "EVENT: rssi high\n");
break;
case MACREG_INT_CODE_SNR_HIGH:
netdev_alert(priv->dev, "EVENT: snr high\n");
break;
case MACREG_INT_CODE_MESH_AUTO_STARTED:
netdev_info(priv->dev, "EVENT: MESH_AUTO_STARTED (ignoring)\n");
break;
default:
netdev_alert(priv->dev, "EVENT: unknown event id %d\n", event);
break;
}
lbs_deb_leave_args(LBS_DEB_CMD, "ret %d", ret);
return ret;
}
