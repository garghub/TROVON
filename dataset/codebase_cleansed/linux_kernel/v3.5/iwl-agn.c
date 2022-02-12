void iwl_update_chain_flags(struct iwl_priv *priv)
{
struct iwl_rxon_context *ctx;
for_each_context(priv, ctx) {
iwlagn_set_rxon_chain(priv, ctx);
if (ctx->active.rx_chain != ctx->staging.rx_chain)
iwlagn_commit_rxon(priv, ctx);
}
}
static void iwl_set_beacon_tim(struct iwl_priv *priv,
struct iwl_tx_beacon_cmd *tx_beacon_cmd,
u8 *beacon, u32 frame_size)
{
u16 tim_idx;
struct ieee80211_mgmt *mgmt = (struct ieee80211_mgmt *)beacon;
tim_idx = mgmt->u.beacon.variable - beacon;
while ((tim_idx < (frame_size - 2)) &&
(beacon[tim_idx] != WLAN_EID_TIM))
tim_idx += beacon[tim_idx+1] + 2;
if ((tim_idx < (frame_size - 1)) && (beacon[tim_idx] == WLAN_EID_TIM)) {
tx_beacon_cmd->tim_idx = cpu_to_le16(tim_idx);
tx_beacon_cmd->tim_size = beacon[tim_idx+1];
} else
IWL_WARN(priv, "Unable to find TIM Element in beacon\n");
}
int iwlagn_send_beacon_cmd(struct iwl_priv *priv)
{
struct iwl_tx_beacon_cmd *tx_beacon_cmd;
struct iwl_host_cmd cmd = {
.id = REPLY_TX_BEACON,
.flags = CMD_SYNC,
};
struct ieee80211_tx_info *info;
u32 frame_size;
u32 rate_flags;
u32 rate;
lockdep_assert_held(&priv->mutex);
if (!priv->beacon_ctx) {
IWL_ERR(priv, "trying to build beacon w/o beacon context!\n");
return 0;
}
if (WARN_ON(!priv->beacon_skb))
return -EINVAL;
if (!priv->beacon_cmd)
priv->beacon_cmd = kzalloc(sizeof(*tx_beacon_cmd), GFP_KERNEL);
tx_beacon_cmd = priv->beacon_cmd;
if (!tx_beacon_cmd)
return -ENOMEM;
frame_size = priv->beacon_skb->len;
tx_beacon_cmd->tx.len = cpu_to_le16((u16)frame_size);
tx_beacon_cmd->tx.sta_id = priv->beacon_ctx->bcast_sta_id;
tx_beacon_cmd->tx.stop_time.life_time = TX_CMD_LIFE_TIME_INFINITE;
tx_beacon_cmd->tx.tx_flags = TX_CMD_FLG_SEQ_CTL_MSK |
TX_CMD_FLG_TSF_MSK | TX_CMD_FLG_STA_RATE_MSK;
iwl_set_beacon_tim(priv, tx_beacon_cmd, priv->beacon_skb->data,
frame_size);
info = IEEE80211_SKB_CB(priv->beacon_skb);
if (info->control.rates[0].idx < 0 ||
info->control.rates[0].flags & IEEE80211_TX_RC_MCS)
rate = 0;
else
rate = info->control.rates[0].idx;
priv->mgmt_tx_ant = iwl_toggle_tx_ant(priv, priv->mgmt_tx_ant,
priv->hw_params.valid_tx_ant);
rate_flags = iwl_ant_idx_to_flags(priv->mgmt_tx_ant);
if (info->band == IEEE80211_BAND_5GHZ)
rate += IWL_FIRST_OFDM_RATE;
else if (rate >= IWL_FIRST_CCK_RATE && rate <= IWL_LAST_CCK_RATE)
rate_flags |= RATE_MCS_CCK_MSK;
tx_beacon_cmd->tx.rate_n_flags =
iwl_hw_set_rate_n_flags(rate, rate_flags);
cmd.len[0] = sizeof(*tx_beacon_cmd);
cmd.data[0] = tx_beacon_cmd;
cmd.dataflags[0] = IWL_HCMD_DFL_NOCOPY;
cmd.len[1] = frame_size;
cmd.data[1] = priv->beacon_skb->data;
cmd.dataflags[1] = IWL_HCMD_DFL_NOCOPY;
return iwl_dvm_send_cmd(priv, &cmd);
}
static void iwl_bg_beacon_update(struct work_struct *work)
{
struct iwl_priv *priv =
container_of(work, struct iwl_priv, beacon_update);
struct sk_buff *beacon;
mutex_lock(&priv->mutex);
if (!priv->beacon_ctx) {
IWL_ERR(priv, "updating beacon w/o beacon context!\n");
goto out;
}
if (priv->beacon_ctx->vif->type != NL80211_IFTYPE_AP) {
goto out;
}
beacon = ieee80211_beacon_get(priv->hw, priv->beacon_ctx->vif);
if (!beacon) {
IWL_ERR(priv, "update beacon failed -- keeping old\n");
goto out;
}
dev_kfree_skb(priv->beacon_skb);
priv->beacon_skb = beacon;
iwlagn_send_beacon_cmd(priv);
out:
mutex_unlock(&priv->mutex);
}
static void iwl_bg_bt_runtime_config(struct work_struct *work)
{
struct iwl_priv *priv =
container_of(work, struct iwl_priv, bt_runtime_config);
if (test_bit(STATUS_EXIT_PENDING, &priv->status))
return;
if (!iwl_is_ready_rf(priv))
return;
iwlagn_send_advance_bt_config(priv);
}
static void iwl_bg_bt_full_concurrency(struct work_struct *work)
{
struct iwl_priv *priv =
container_of(work, struct iwl_priv, bt_full_concurrency);
struct iwl_rxon_context *ctx;
mutex_lock(&priv->mutex);
if (test_bit(STATUS_EXIT_PENDING, &priv->status))
goto out;
if (!iwl_is_ready_rf(priv))
goto out;
IWL_DEBUG_INFO(priv, "BT coex in %s mode\n",
priv->bt_full_concurrent ?
"full concurrency" : "3-wire");
for_each_context(priv, ctx) {
iwlagn_set_rxon_chain(priv, ctx);
iwlagn_commit_rxon(priv, ctx);
}
iwlagn_send_advance_bt_config(priv);
out:
mutex_unlock(&priv->mutex);
}
int iwl_send_statistics_request(struct iwl_priv *priv, u8 flags, bool clear)
{
struct iwl_statistics_cmd statistics_cmd = {
.configuration_flags =
clear ? IWL_STATS_CONF_CLEAR_STATS : 0,
};
if (flags & CMD_ASYNC)
return iwl_dvm_send_cmd_pdu(priv, REPLY_STATISTICS_CMD,
CMD_ASYNC,
sizeof(struct iwl_statistics_cmd),
&statistics_cmd);
else
return iwl_dvm_send_cmd_pdu(priv, REPLY_STATISTICS_CMD,
CMD_SYNC,
sizeof(struct iwl_statistics_cmd),
&statistics_cmd);
}
static void iwl_bg_statistics_periodic(unsigned long data)
{
struct iwl_priv *priv = (struct iwl_priv *)data;
if (test_bit(STATUS_EXIT_PENDING, &priv->status))
return;
if (!iwl_is_ready_rf(priv))
return;
iwl_send_statistics_request(priv, CMD_ASYNC, false);
}
static void iwl_print_cont_event_trace(struct iwl_priv *priv, u32 base,
u32 start_idx, u32 num_events,
u32 capacity, u32 mode)
{
u32 i;
u32 ptr;
u32 ev, time, data;
unsigned long reg_flags;
if (mode == 0)
ptr = base + (4 * sizeof(u32)) + (start_idx * 2 * sizeof(u32));
else
ptr = base + (4 * sizeof(u32)) + (start_idx * 3 * sizeof(u32));
spin_lock_irqsave(&priv->trans->reg_lock, reg_flags);
if (unlikely(!iwl_grab_nic_access(priv->trans))) {
spin_unlock_irqrestore(&priv->trans->reg_lock, reg_flags);
return;
}
iwl_write32(priv->trans, HBUS_TARG_MEM_RADDR, ptr);
if (WARN_ON(num_events > capacity - start_idx))
num_events = capacity - start_idx;
for (i = 0; i < num_events; i++) {
ev = iwl_read32(priv->trans, HBUS_TARG_MEM_RDAT);
time = iwl_read32(priv->trans, HBUS_TARG_MEM_RDAT);
if (mode == 0) {
trace_iwlwifi_dev_ucode_cont_event(
priv->trans->dev, 0, time, ev);
} else {
data = iwl_read32(priv->trans, HBUS_TARG_MEM_RDAT);
trace_iwlwifi_dev_ucode_cont_event(
priv->trans->dev, time, data, ev);
}
}
iwl_release_nic_access(priv->trans);
spin_unlock_irqrestore(&priv->trans->reg_lock, reg_flags);
}
static void iwl_continuous_event_trace(struct iwl_priv *priv)
{
u32 capacity;
struct {
u32 capacity;
u32 mode;
u32 wrap_counter;
u32 write_counter;
} __packed read;
u32 base;
u32 mode;
u32 num_wraps;
u32 next_entry;
base = priv->device_pointers.log_event_table;
if (iwlagn_hw_valid_rtc_data_addr(base)) {
iwl_read_targ_mem_words(priv->trans, base, &read, sizeof(read));
capacity = read.capacity;
mode = read.mode;
num_wraps = read.wrap_counter;
next_entry = read.write_counter;
} else
return;
if (unlikely(next_entry == capacity))
next_entry = 0;
if (unlikely(next_entry < priv->event_log.next_entry &&
num_wraps == priv->event_log.num_wraps))
num_wraps++;
if (num_wraps == priv->event_log.num_wraps) {
iwl_print_cont_event_trace(
priv, base, priv->event_log.next_entry,
next_entry - priv->event_log.next_entry,
capacity, mode);
priv->event_log.non_wraps_count++;
} else {
if (num_wraps - priv->event_log.num_wraps > 1)
priv->event_log.wraps_more_count++;
else
priv->event_log.wraps_once_count++;
trace_iwlwifi_dev_ucode_wrap_event(priv->trans->dev,
num_wraps - priv->event_log.num_wraps,
next_entry, priv->event_log.next_entry);
if (next_entry < priv->event_log.next_entry) {
iwl_print_cont_event_trace(
priv, base, priv->event_log.next_entry,
capacity - priv->event_log.next_entry,
capacity, mode);
iwl_print_cont_event_trace(
priv, base, 0, next_entry, capacity, mode);
} else {
iwl_print_cont_event_trace(
priv, base, next_entry,
capacity - next_entry,
capacity, mode);
iwl_print_cont_event_trace(
priv, base, 0, next_entry, capacity, mode);
}
}
priv->event_log.num_wraps = num_wraps;
priv->event_log.next_entry = next_entry;
}
static void iwl_bg_ucode_trace(unsigned long data)
{
struct iwl_priv *priv = (struct iwl_priv *)data;
if (test_bit(STATUS_EXIT_PENDING, &priv->status))
return;
if (priv->event_log.ucode_trace) {
iwl_continuous_event_trace(priv);
mod_timer(&priv->ucode_trace,
jiffies + msecs_to_jiffies(UCODE_TRACE_PERIOD));
}
}
static void iwl_bg_tx_flush(struct work_struct *work)
{
struct iwl_priv *priv =
container_of(work, struct iwl_priv, tx_flush);
if (test_bit(STATUS_EXIT_PENDING, &priv->status))
return;
if (!iwl_is_ready_rf(priv))
return;
IWL_DEBUG_INFO(priv, "device request: flush all tx frames\n");
iwlagn_dev_txfifo_flush(priv, IWL_DROP_ALL);
}
void iwl_init_context(struct iwl_priv *priv, u32 ucode_flags)
{
int i;
priv->valid_contexts = BIT(IWL_RXON_CTX_BSS);
if (ucode_flags & IWL_UCODE_TLV_FLAGS_PAN)
priv->valid_contexts |= BIT(IWL_RXON_CTX_PAN);
for (i = 0; i < NUM_IWL_RXON_CTX; i++)
priv->contexts[i].ctxid = i;
priv->contexts[IWL_RXON_CTX_BSS].always_active = true;
priv->contexts[IWL_RXON_CTX_BSS].is_active = true;
priv->contexts[IWL_RXON_CTX_BSS].rxon_cmd = REPLY_RXON;
priv->contexts[IWL_RXON_CTX_BSS].rxon_timing_cmd = REPLY_RXON_TIMING;
priv->contexts[IWL_RXON_CTX_BSS].rxon_assoc_cmd = REPLY_RXON_ASSOC;
priv->contexts[IWL_RXON_CTX_BSS].qos_cmd = REPLY_QOS_PARAM;
priv->contexts[IWL_RXON_CTX_BSS].ap_sta_id = IWL_AP_ID;
priv->contexts[IWL_RXON_CTX_BSS].wep_key_cmd = REPLY_WEPKEY;
priv->contexts[IWL_RXON_CTX_BSS].bcast_sta_id = IWLAGN_BROADCAST_ID;
priv->contexts[IWL_RXON_CTX_BSS].exclusive_interface_modes =
BIT(NL80211_IFTYPE_ADHOC) | BIT(NL80211_IFTYPE_MONITOR);
priv->contexts[IWL_RXON_CTX_BSS].interface_modes =
BIT(NL80211_IFTYPE_STATION);
priv->contexts[IWL_RXON_CTX_BSS].ap_devtype = RXON_DEV_TYPE_AP;
priv->contexts[IWL_RXON_CTX_BSS].ibss_devtype = RXON_DEV_TYPE_IBSS;
priv->contexts[IWL_RXON_CTX_BSS].station_devtype = RXON_DEV_TYPE_ESS;
priv->contexts[IWL_RXON_CTX_BSS].unused_devtype = RXON_DEV_TYPE_ESS;
memcpy(priv->contexts[IWL_RXON_CTX_BSS].ac_to_queue,
iwlagn_bss_ac_to_queue, sizeof(iwlagn_bss_ac_to_queue));
memcpy(priv->contexts[IWL_RXON_CTX_BSS].ac_to_fifo,
iwlagn_bss_ac_to_fifo, sizeof(iwlagn_bss_ac_to_fifo));
priv->contexts[IWL_RXON_CTX_PAN].rxon_cmd = REPLY_WIPAN_RXON;
priv->contexts[IWL_RXON_CTX_PAN].rxon_timing_cmd =
REPLY_WIPAN_RXON_TIMING;
priv->contexts[IWL_RXON_CTX_PAN].rxon_assoc_cmd =
REPLY_WIPAN_RXON_ASSOC;
priv->contexts[IWL_RXON_CTX_PAN].qos_cmd = REPLY_WIPAN_QOS_PARAM;
priv->contexts[IWL_RXON_CTX_PAN].ap_sta_id = IWL_AP_ID_PAN;
priv->contexts[IWL_RXON_CTX_PAN].wep_key_cmd = REPLY_WIPAN_WEPKEY;
priv->contexts[IWL_RXON_CTX_PAN].bcast_sta_id = IWLAGN_PAN_BCAST_ID;
priv->contexts[IWL_RXON_CTX_PAN].station_flags = STA_FLG_PAN_STATION;
priv->contexts[IWL_RXON_CTX_PAN].interface_modes =
BIT(NL80211_IFTYPE_STATION) | BIT(NL80211_IFTYPE_AP);
if (ucode_flags & IWL_UCODE_TLV_FLAGS_P2P)
priv->contexts[IWL_RXON_CTX_PAN].interface_modes |=
BIT(NL80211_IFTYPE_P2P_CLIENT) |
BIT(NL80211_IFTYPE_P2P_GO);
priv->contexts[IWL_RXON_CTX_PAN].ap_devtype = RXON_DEV_TYPE_CP;
priv->contexts[IWL_RXON_CTX_PAN].station_devtype = RXON_DEV_TYPE_2STA;
priv->contexts[IWL_RXON_CTX_PAN].unused_devtype = RXON_DEV_TYPE_P2P;
memcpy(priv->contexts[IWL_RXON_CTX_PAN].ac_to_queue,
iwlagn_pan_ac_to_queue, sizeof(iwlagn_pan_ac_to_queue));
memcpy(priv->contexts[IWL_RXON_CTX_PAN].ac_to_fifo,
iwlagn_pan_ac_to_fifo, sizeof(iwlagn_pan_ac_to_fifo));
priv->contexts[IWL_RXON_CTX_PAN].mcast_queue = IWL_IPAN_MCAST_QUEUE;
BUILD_BUG_ON(NUM_IWL_RXON_CTX != 2);
}
void iwl_rf_kill_ct_config(struct iwl_priv *priv)
{
struct iwl_ct_kill_config cmd;
struct iwl_ct_kill_throttling_config adv_cmd;
int ret = 0;
iwl_write32(priv->trans, CSR_UCODE_DRV_GP1_CLR,
CSR_UCODE_DRV_GP1_REG_BIT_CT_KILL_EXIT);
priv->thermal_throttle.ct_kill_toggle = false;
if (priv->cfg->base_params->support_ct_kill_exit) {
adv_cmd.critical_temperature_enter =
cpu_to_le32(priv->hw_params.ct_kill_threshold);
adv_cmd.critical_temperature_exit =
cpu_to_le32(priv->hw_params.ct_kill_exit_threshold);
ret = iwl_dvm_send_cmd_pdu(priv,
REPLY_CT_KILL_CONFIG_CMD,
CMD_SYNC, sizeof(adv_cmd), &adv_cmd);
if (ret)
IWL_ERR(priv, "REPLY_CT_KILL_CONFIG_CMD failed\n");
else
IWL_DEBUG_INFO(priv, "REPLY_CT_KILL_CONFIG_CMD "
"succeeded, critical temperature enter is %d,"
"exit is %d\n",
priv->hw_params.ct_kill_threshold,
priv->hw_params.ct_kill_exit_threshold);
} else {
cmd.critical_temperature_R =
cpu_to_le32(priv->hw_params.ct_kill_threshold);
ret = iwl_dvm_send_cmd_pdu(priv,
REPLY_CT_KILL_CONFIG_CMD,
CMD_SYNC, sizeof(cmd), &cmd);
if (ret)
IWL_ERR(priv, "REPLY_CT_KILL_CONFIG_CMD failed\n");
else
IWL_DEBUG_INFO(priv, "REPLY_CT_KILL_CONFIG_CMD "
"succeeded, "
"critical temperature is %d\n",
priv->hw_params.ct_kill_threshold);
}
}
static int iwlagn_send_calib_cfg_rt(struct iwl_priv *priv, u32 cfg)
{
struct iwl_calib_cfg_cmd calib_cfg_cmd;
struct iwl_host_cmd cmd = {
.id = CALIBRATION_CFG_CMD,
.len = { sizeof(struct iwl_calib_cfg_cmd), },
.data = { &calib_cfg_cmd, },
};
memset(&calib_cfg_cmd, 0, sizeof(calib_cfg_cmd));
calib_cfg_cmd.ucd_calib_cfg.once.is_enable = IWL_CALIB_RT_CFG_ALL;
calib_cfg_cmd.ucd_calib_cfg.once.start = cpu_to_le32(cfg);
return iwl_dvm_send_cmd(priv, &cmd);
}
static int iwlagn_send_tx_ant_config(struct iwl_priv *priv, u8 valid_tx_ant)
{
struct iwl_tx_ant_config_cmd tx_ant_cmd = {
.valid = cpu_to_le32(valid_tx_ant),
};
if (IWL_UCODE_API(priv->fw->ucode_ver) > 1) {
IWL_DEBUG_HC(priv, "select valid tx ant: %u\n", valid_tx_ant);
return iwl_dvm_send_cmd_pdu(priv,
TX_ANT_CONFIGURATION_CMD,
CMD_SYNC,
sizeof(struct iwl_tx_ant_config_cmd),
&tx_ant_cmd);
} else {
IWL_DEBUG_HC(priv, "TX_ANT_CONFIGURATION_CMD not supported\n");
return -EOPNOTSUPP;
}
}
void iwl_send_bt_config(struct iwl_priv *priv)
{
struct iwl_bt_cmd bt_cmd = {
.lead_time = BT_LEAD_TIME_DEF,
.max_kill = BT_MAX_KILL_DEF,
.kill_ack_mask = 0,
.kill_cts_mask = 0,
};
if (!iwlwifi_mod_params.bt_coex_active)
bt_cmd.flags = BT_COEX_DISABLE;
else
bt_cmd.flags = BT_COEX_ENABLE;
priv->bt_enable_flag = bt_cmd.flags;
IWL_DEBUG_INFO(priv, "BT coex %s\n",
(bt_cmd.flags == BT_COEX_DISABLE) ? "disable" : "active");
if (iwl_dvm_send_cmd_pdu(priv, REPLY_BT_CONFIG,
CMD_SYNC, sizeof(struct iwl_bt_cmd), &bt_cmd))
IWL_ERR(priv, "failed to send BT Coex Config\n");
}
int iwl_alive_start(struct iwl_priv *priv)
{
int ret = 0;
struct iwl_rxon_context *ctx = &priv->contexts[IWL_RXON_CTX_BSS];
IWL_DEBUG_INFO(priv, "Runtime Alive received.\n");
set_bit(STATUS_ALIVE, &priv->status);
if (iwl_is_rfkill(priv))
return -ERFKILL;
if (priv->event_log.ucode_trace) {
mod_timer(&priv->ucode_trace, jiffies);
}
if (priv->cfg->bt_params &&
priv->cfg->bt_params->advanced_bt_coexist) {
if (priv->cfg->bt_params->bt_sco_disable)
priv->bt_enable_pspoll = false;
else
priv->bt_enable_pspoll = true;
priv->bt_valid = IWLAGN_BT_ALL_VALID_MSK;
priv->kill_ack_mask = IWLAGN_BT_KILL_ACK_MASK_DEFAULT;
priv->kill_cts_mask = IWLAGN_BT_KILL_CTS_MASK_DEFAULT;
iwlagn_send_advance_bt_config(priv);
priv->bt_valid = IWLAGN_BT_VALID_ENABLE_FLAGS;
priv->cur_rssi_ctx = NULL;
iwl_send_prio_tbl(priv);
ret = iwl_send_bt_env(priv, IWL_BT_COEX_ENV_OPEN,
BT_COEX_PRIO_TBL_EVT_INIT_CALIB2);
if (ret)
return ret;
ret = iwl_send_bt_env(priv, IWL_BT_COEX_ENV_CLOSE,
BT_COEX_PRIO_TBL_EVT_INIT_CALIB2);
if (ret)
return ret;
} else {
iwl_send_bt_config(priv);
}
iwlagn_send_calib_cfg_rt(priv, IWL_CALIB_CFG_DC_IDX);
ieee80211_wake_queues(priv->hw);
iwlagn_send_tx_ant_config(priv, priv->hw_params.valid_tx_ant);
if (iwl_is_associated_ctx(ctx) && !priv->wowlan) {
struct iwl_rxon_cmd *active_rxon =
(struct iwl_rxon_cmd *)&ctx->active;
ctx->staging.filter_flags |= RXON_FILTER_ASSOC_MSK;
active_rxon->filter_flags &= ~RXON_FILTER_ASSOC_MSK;
} else {
struct iwl_rxon_context *tmp;
for_each_context(priv, tmp)
iwl_connection_init_rx_config(priv, tmp);
iwlagn_set_rxon_chain(priv, ctx);
}
if (!priv->wowlan) {
iwl_reset_run_time_calib(priv);
}
set_bit(STATUS_READY, &priv->status);
ret = iwlagn_commit_rxon(priv, ctx);
if (ret)
return ret;
iwl_rf_kill_ct_config(priv);
IWL_DEBUG_INFO(priv, "ALIVE processing complete.\n");
return iwl_power_update_mode(priv, true);
}
static void iwl_clear_driver_stations(struct iwl_priv *priv)
{
struct iwl_rxon_context *ctx;
spin_lock_bh(&priv->sta_lock);
memset(priv->stations, 0, sizeof(priv->stations));
priv->num_stations = 0;
priv->ucode_key_table = 0;
for_each_context(priv, ctx) {
memset(ctx->wep_keys, 0, sizeof(ctx->wep_keys));
ctx->key_mapping_keys = 0;
}
spin_unlock_bh(&priv->sta_lock);
}
void iwl_down(struct iwl_priv *priv)
{
int exit_pending;
IWL_DEBUG_INFO(priv, DRV_NAME " is going down\n");
lockdep_assert_held(&priv->mutex);
iwl_scan_cancel_timeout(priv, 200);
ieee80211_remain_on_channel_expired(priv->hw);
exit_pending =
test_and_set_bit(STATUS_EXIT_PENDING, &priv->status);
iwl_clear_ucode_stations(priv, NULL);
iwl_dealloc_bcast_stations(priv);
iwl_clear_driver_stations(priv);
priv->bt_status = 0;
priv->cur_rssi_ctx = NULL;
priv->bt_is_sco = 0;
if (priv->cfg->bt_params)
priv->bt_traffic_load =
priv->cfg->bt_params->bt_init_traffic_load;
else
priv->bt_traffic_load = 0;
priv->bt_full_concurrent = false;
priv->bt_ci_compliance = 0;
if (!exit_pending)
clear_bit(STATUS_EXIT_PENDING, &priv->status);
if (priv->mac80211_registered)
ieee80211_stop_queues(priv->hw);
priv->ucode_loaded = false;
iwl_trans_stop_device(priv->trans);
priv->status &= test_bit(STATUS_RF_KILL_HW, &priv->status) <<
STATUS_RF_KILL_HW |
test_bit(STATUS_GEO_CONFIGURED, &priv->status) <<
STATUS_GEO_CONFIGURED |
test_bit(STATUS_FW_ERROR, &priv->status) <<
STATUS_FW_ERROR |
test_bit(STATUS_EXIT_PENDING, &priv->status) <<
STATUS_EXIT_PENDING;
dev_kfree_skb(priv->beacon_skb);
priv->beacon_skb = NULL;
}
static void iwl_bg_run_time_calib_work(struct work_struct *work)
{
struct iwl_priv *priv = container_of(work, struct iwl_priv,
run_time_calib_work);
mutex_lock(&priv->mutex);
if (test_bit(STATUS_EXIT_PENDING, &priv->status) ||
test_bit(STATUS_SCANNING, &priv->status)) {
mutex_unlock(&priv->mutex);
return;
}
if (priv->start_calib) {
iwl_chain_noise_calibration(priv);
iwl_sensitivity_calibration(priv);
}
mutex_unlock(&priv->mutex);
}
void iwlagn_prepare_restart(struct iwl_priv *priv)
{
bool bt_full_concurrent;
u8 bt_ci_compliance;
u8 bt_load;
u8 bt_status;
bool bt_is_sco;
int i;
lockdep_assert_held(&priv->mutex);
priv->is_open = 0;
bt_full_concurrent = priv->bt_full_concurrent;
bt_ci_compliance = priv->bt_ci_compliance;
bt_load = priv->bt_traffic_load;
bt_status = priv->bt_status;
bt_is_sco = priv->bt_is_sco;
iwl_down(priv);
priv->bt_full_concurrent = bt_full_concurrent;
priv->bt_ci_compliance = bt_ci_compliance;
priv->bt_traffic_load = bt_load;
priv->bt_status = bt_status;
priv->bt_is_sco = bt_is_sco;
for (i = IWLAGN_FIRST_AMPDU_QUEUE; i < IWL_MAX_HW_QUEUES; i++)
priv->queue_to_mac80211[i] = IWL_INVALID_MAC80211_QUEUE;
for (i = 0; i < IWL_MAX_HW_QUEUES; i++)
atomic_set(&priv->queue_stop_count[i], 0);
memset(priv->agg_q_alloc, 0, sizeof(priv->agg_q_alloc));
}
static void iwl_bg_restart(struct work_struct *data)
{
struct iwl_priv *priv = container_of(data, struct iwl_priv, restart);
if (test_bit(STATUS_EXIT_PENDING, &priv->status))
return;
if (test_and_clear_bit(STATUS_FW_ERROR, &priv->status)) {
mutex_lock(&priv->mutex);
iwlagn_prepare_restart(priv);
mutex_unlock(&priv->mutex);
iwl_cancel_deferred_work(priv);
ieee80211_restart_hw(priv->hw);
} else {
WARN_ON(1);
}
}
void iwlagn_disable_roc(struct iwl_priv *priv)
{
struct iwl_rxon_context *ctx = &priv->contexts[IWL_RXON_CTX_PAN];
lockdep_assert_held(&priv->mutex);
if (!priv->hw_roc_setup)
return;
ctx->staging.dev_type = RXON_DEV_TYPE_P2P;
ctx->staging.filter_flags &= ~RXON_FILTER_ASSOC_MSK;
priv->hw_roc_channel = NULL;
memset(ctx->staging.node_addr, 0, ETH_ALEN);
iwlagn_commit_rxon(priv, ctx);
ctx->is_active = false;
priv->hw_roc_setup = false;
}
static void iwlagn_disable_roc_work(struct work_struct *work)
{
struct iwl_priv *priv = container_of(work, struct iwl_priv,
hw_roc_disable_work.work);
mutex_lock(&priv->mutex);
iwlagn_disable_roc(priv);
mutex_unlock(&priv->mutex);
}
void iwl_setup_deferred_work(struct iwl_priv *priv)
{
priv->workqueue = create_singlethread_workqueue(DRV_NAME);
INIT_WORK(&priv->restart, iwl_bg_restart);
INIT_WORK(&priv->beacon_update, iwl_bg_beacon_update);
INIT_WORK(&priv->run_time_calib_work, iwl_bg_run_time_calib_work);
INIT_WORK(&priv->tx_flush, iwl_bg_tx_flush);
INIT_WORK(&priv->bt_full_concurrency, iwl_bg_bt_full_concurrency);
INIT_WORK(&priv->bt_runtime_config, iwl_bg_bt_runtime_config);
INIT_DELAYED_WORK(&priv->hw_roc_disable_work,
iwlagn_disable_roc_work);
iwl_setup_scan_deferred_work(priv);
if (priv->cfg->bt_params)
iwlagn_bt_setup_deferred_work(priv);
init_timer(&priv->statistics_periodic);
priv->statistics_periodic.data = (unsigned long)priv;
priv->statistics_periodic.function = iwl_bg_statistics_periodic;
init_timer(&priv->ucode_trace);
priv->ucode_trace.data = (unsigned long)priv;
priv->ucode_trace.function = iwl_bg_ucode_trace;
}
void iwl_cancel_deferred_work(struct iwl_priv *priv)
{
if (priv->cfg->bt_params)
iwlagn_bt_cancel_deferred_work(priv);
cancel_work_sync(&priv->run_time_calib_work);
cancel_work_sync(&priv->beacon_update);
iwl_cancel_scan_deferred_work(priv);
cancel_work_sync(&priv->bt_full_concurrency);
cancel_work_sync(&priv->bt_runtime_config);
cancel_delayed_work_sync(&priv->hw_roc_disable_work);
del_timer_sync(&priv->statistics_periodic);
del_timer_sync(&priv->ucode_trace);
}
static void iwl_init_hw_rates(struct ieee80211_rate *rates)
{
int i;
for (i = 0; i < IWL_RATE_COUNT_LEGACY; i++) {
rates[i].bitrate = iwl_rates[i].ieee * 5;
rates[i].hw_value = i;
rates[i].hw_value_short = i;
rates[i].flags = 0;
if ((i >= IWL_FIRST_CCK_RATE) && (i <= IWL_LAST_CCK_RATE)) {
rates[i].flags |=
(iwl_rates[i].plcp == IWL_RATE_1M_PLCP) ?
0 : IEEE80211_RATE_SHORT_PREAMBLE;
}
}
}
static void iwl_init_ht_hw_capab(const struct iwl_priv *priv,
struct ieee80211_sta_ht_cap *ht_info,
enum ieee80211_band band)
{
u16 max_bit_rate = 0;
u8 rx_chains_num = priv->hw_params.rx_chains_num;
u8 tx_chains_num = priv->hw_params.tx_chains_num;
ht_info->cap = 0;
memset(&ht_info->mcs, 0, sizeof(ht_info->mcs));
ht_info->ht_supported = true;
if (priv->cfg->ht_params &&
priv->cfg->ht_params->ht_greenfield_support)
ht_info->cap |= IEEE80211_HT_CAP_GRN_FLD;
ht_info->cap |= IEEE80211_HT_CAP_SGI_20;
max_bit_rate = MAX_BIT_RATE_20_MHZ;
if (priv->hw_params.ht40_channel & BIT(band)) {
ht_info->cap |= IEEE80211_HT_CAP_SUP_WIDTH_20_40;
ht_info->cap |= IEEE80211_HT_CAP_SGI_40;
ht_info->mcs.rx_mask[4] = 0x01;
max_bit_rate = MAX_BIT_RATE_40_MHZ;
}
if (iwlwifi_mod_params.amsdu_size_8K)
ht_info->cap |= IEEE80211_HT_CAP_MAX_AMSDU;
ht_info->ampdu_factor = CFG_HT_RX_AMPDU_FACTOR_DEF;
ht_info->ampdu_density = CFG_HT_MPDU_DENSITY_DEF;
ht_info->mcs.rx_mask[0] = 0xFF;
if (rx_chains_num >= 2)
ht_info->mcs.rx_mask[1] = 0xFF;
if (rx_chains_num >= 3)
ht_info->mcs.rx_mask[2] = 0xFF;
max_bit_rate *= rx_chains_num;
WARN_ON(max_bit_rate & ~IEEE80211_HT_MCS_RX_HIGHEST_MASK);
ht_info->mcs.rx_highest = cpu_to_le16(max_bit_rate);
ht_info->mcs.tx_params = IEEE80211_HT_MCS_TX_DEFINED;
if (tx_chains_num != rx_chains_num) {
ht_info->mcs.tx_params |= IEEE80211_HT_MCS_TX_RX_DIFF;
ht_info->mcs.tx_params |= ((tx_chains_num - 1) <<
IEEE80211_HT_MCS_TX_MAX_STREAMS_SHIFT);
}
}
static int iwl_init_geos(struct iwl_priv *priv)
{
struct iwl_channel_info *ch;
struct ieee80211_supported_band *sband;
struct ieee80211_channel *channels;
struct ieee80211_channel *geo_ch;
struct ieee80211_rate *rates;
int i = 0;
s8 max_tx_power = IWLAGN_TX_POWER_TARGET_POWER_MIN;
if (priv->bands[IEEE80211_BAND_2GHZ].n_bitrates ||
priv->bands[IEEE80211_BAND_5GHZ].n_bitrates) {
IWL_DEBUG_INFO(priv, "Geography modes already initialized.\n");
set_bit(STATUS_GEO_CONFIGURED, &priv->status);
return 0;
}
channels = kcalloc(priv->channel_count,
sizeof(struct ieee80211_channel), GFP_KERNEL);
if (!channels)
return -ENOMEM;
rates = kcalloc(IWL_RATE_COUNT_LEGACY, sizeof(struct ieee80211_rate),
GFP_KERNEL);
if (!rates) {
kfree(channels);
return -ENOMEM;
}
sband = &priv->bands[IEEE80211_BAND_5GHZ];
sband->channels = &channels[ARRAY_SIZE(iwl_eeprom_band_1)];
sband->bitrates = &rates[IWL_FIRST_OFDM_RATE];
sband->n_bitrates = IWL_RATE_COUNT_LEGACY - IWL_FIRST_OFDM_RATE;
if (priv->hw_params.sku & EEPROM_SKU_CAP_11N_ENABLE)
iwl_init_ht_hw_capab(priv, &sband->ht_cap,
IEEE80211_BAND_5GHZ);
sband = &priv->bands[IEEE80211_BAND_2GHZ];
sband->channels = channels;
sband->bitrates = rates;
sband->n_bitrates = IWL_RATE_COUNT_LEGACY;
if (priv->hw_params.sku & EEPROM_SKU_CAP_11N_ENABLE)
iwl_init_ht_hw_capab(priv, &sband->ht_cap,
IEEE80211_BAND_2GHZ);
priv->ieee_channels = channels;
priv->ieee_rates = rates;
for (i = 0; i < priv->channel_count; i++) {
ch = &priv->channel_info[i];
if (!is_channel_valid(ch))
continue;
sband = &priv->bands[ch->band];
geo_ch = &sband->channels[sband->n_channels++];
geo_ch->center_freq =
ieee80211_channel_to_frequency(ch->channel, ch->band);
geo_ch->max_power = ch->max_power_avg;
geo_ch->max_antenna_gain = 0xff;
geo_ch->hw_value = ch->channel;
if (is_channel_valid(ch)) {
if (!(ch->flags & EEPROM_CHANNEL_IBSS))
geo_ch->flags |= IEEE80211_CHAN_NO_IBSS;
if (!(ch->flags & EEPROM_CHANNEL_ACTIVE))
geo_ch->flags |= IEEE80211_CHAN_PASSIVE_SCAN;
if (ch->flags & EEPROM_CHANNEL_RADAR)
geo_ch->flags |= IEEE80211_CHAN_RADAR;
geo_ch->flags |= ch->ht40_extension_channel;
if (ch->max_power_avg > max_tx_power)
max_tx_power = ch->max_power_avg;
} else {
geo_ch->flags |= IEEE80211_CHAN_DISABLED;
}
IWL_DEBUG_INFO(priv, "Channel %d Freq=%d[%sGHz] %s flag=0x%X\n",
ch->channel, geo_ch->center_freq,
is_channel_a_band(ch) ? "5.2" : "2.4",
geo_ch->flags & IEEE80211_CHAN_DISABLED ?
"restricted" : "valid",
geo_ch->flags);
}
priv->tx_power_device_lmt = max_tx_power;
priv->tx_power_user_lmt = max_tx_power;
priv->tx_power_next = max_tx_power;
if ((priv->bands[IEEE80211_BAND_5GHZ].n_channels == 0) &&
priv->hw_params.sku & EEPROM_SKU_CAP_BAND_52GHZ) {
IWL_INFO(priv, "Incorrectly detected BG card as ABG. "
"Please send your %s to maintainer.\n",
priv->trans->hw_id_str);
priv->hw_params.sku &= ~EEPROM_SKU_CAP_BAND_52GHZ;
}
if (iwlwifi_mod_params.disable_5ghz)
priv->bands[IEEE80211_BAND_5GHZ].n_channels = 0;
IWL_INFO(priv, "Tunable channels: %d 802.11bg, %d 802.11a channels\n",
priv->bands[IEEE80211_BAND_2GHZ].n_channels,
priv->bands[IEEE80211_BAND_5GHZ].n_channels);
set_bit(STATUS_GEO_CONFIGURED, &priv->status);
return 0;
}
static void iwl_free_geos(struct iwl_priv *priv)
{
kfree(priv->ieee_channels);
kfree(priv->ieee_rates);
clear_bit(STATUS_GEO_CONFIGURED, &priv->status);
}
int iwl_init_drv(struct iwl_priv *priv)
{
int ret;
spin_lock_init(&priv->sta_lock);
mutex_init(&priv->mutex);
INIT_LIST_HEAD(&priv->calib_results);
priv->ieee_channels = NULL;
priv->ieee_rates = NULL;
priv->band = IEEE80211_BAND_2GHZ;
priv->plcp_delta_threshold =
priv->cfg->base_params->plcp_delta_threshold;
priv->iw_mode = NL80211_IFTYPE_STATION;
priv->current_ht_config.smps = IEEE80211_SMPS_STATIC;
priv->missed_beacon_threshold = IWL_MISSED_BEACON_THRESHOLD_DEF;
priv->agg_tids_count = 0;
priv->ucode_owner = IWL_OWNERSHIP_DRIVER;
priv->rx_statistics_jiffies = jiffies;
iwlagn_set_rxon_chain(priv, &priv->contexts[IWL_RXON_CTX_BSS]);
iwl_init_scan_params(priv);
if (priv->cfg->bt_params &&
priv->cfg->bt_params->advanced_bt_coexist) {
priv->kill_ack_mask = IWLAGN_BT_KILL_ACK_MASK_DEFAULT;
priv->kill_cts_mask = IWLAGN_BT_KILL_CTS_MASK_DEFAULT;
priv->bt_valid = IWLAGN_BT_ALL_VALID_MSK;
priv->bt_on_thresh = BT_ON_THRESHOLD_DEF;
priv->bt_duration = BT_DURATION_LIMIT_DEF;
priv->dynamic_frag_thresh = BT_FRAG_THRESHOLD_DEF;
}
ret = iwl_init_channel_map(priv);
if (ret) {
IWL_ERR(priv, "initializing regulatory failed: %d\n", ret);
goto err;
}
ret = iwl_init_geos(priv);
if (ret) {
IWL_ERR(priv, "initializing geos failed: %d\n", ret);
goto err_free_channel_map;
}
iwl_init_hw_rates(priv->ieee_rates);
return 0;
err_free_channel_map:
iwl_free_channel_map(priv);
err:
return ret;
}
void iwl_uninit_drv(struct iwl_priv *priv)
{
iwl_free_geos(priv);
iwl_free_channel_map(priv);
kfree(priv->scan_cmd);
kfree(priv->beacon_cmd);
kfree(rcu_dereference_raw(priv->noa_data));
iwl_calib_free_results(priv);
#ifdef CONFIG_IWLWIFI_DEBUGFS
kfree(priv->wowlan_sram);
#endif
}
void iwl_set_hw_params(struct iwl_priv *priv)
{
if (priv->cfg->ht_params)
priv->hw_params.use_rts_for_aggregation =
priv->cfg->ht_params->use_rts_for_aggregation;
if (iwlwifi_mod_params.disable_11n & IWL_DISABLE_HT_ALL)
priv->hw_params.sku &= ~EEPROM_SKU_CAP_11N_ENABLE;
priv->lib->set_hw_params(priv);
}
void iwl_option_config(struct iwl_priv *priv)
{
#ifdef CONFIG_IWLWIFI_DEBUG
IWL_INFO(priv, "CONFIG_IWLWIFI_DEBUG enabled\n");
#else
IWL_INFO(priv, "CONFIG_IWLWIFI_DEBUG disabled\n");
#endif
#ifdef CONFIG_IWLWIFI_DEBUGFS
IWL_INFO(priv, "CONFIG_IWLWIFI_DEBUGFS enabled\n");
#else
IWL_INFO(priv, "CONFIG_IWLWIFI_DEBUGFS disabled\n");
#endif
#ifdef CONFIG_IWLWIFI_DEVICE_TRACING
IWL_INFO(priv, "CONFIG_IWLWIFI_DEVICE_TRACING enabled\n");
#else
IWL_INFO(priv, "CONFIG_IWLWIFI_DEVICE_TRACING disabled\n");
#endif
#ifdef CONFIG_IWLWIFI_DEVICE_TESTMODE
IWL_INFO(priv, "CONFIG_IWLWIFI_DEVICE_TESTMODE enabled\n");
#else
IWL_INFO(priv, "CONFIG_IWLWIFI_DEVICE_TESTMODE disabled\n");
#endif
#ifdef CONFIG_IWLWIFI_P2P
IWL_INFO(priv, "CONFIG_IWLWIFI_P2P enabled\n");
#else
IWL_INFO(priv, "CONFIG_IWLWIFI_P2P disabled\n");
#endif
}
static struct iwl_op_mode *iwl_op_mode_dvm_start(struct iwl_trans *trans,
const struct iwl_cfg *cfg,
const struct iwl_fw *fw)
{
struct iwl_priv *priv;
struct ieee80211_hw *hw;
struct iwl_op_mode *op_mode;
u16 num_mac;
u32 ucode_flags;
struct iwl_trans_config trans_cfg;
static const u8 no_reclaim_cmds[] = {
REPLY_RX_PHY_CMD,
REPLY_RX,
REPLY_RX_MPDU_CMD,
REPLY_COMPRESSED_BA,
STATISTICS_NOTIFICATION,
REPLY_TX,
};
int i;
hw = iwl_alloc_all();
if (!hw) {
pr_err("%s: Cannot allocate network device\n", cfg->name);
goto out;
}
op_mode = hw->priv;
op_mode->ops = &iwl_dvm_ops;
priv = IWL_OP_MODE_GET_DVM(op_mode);
priv->trans = trans;
priv->dev = trans->dev;
priv->cfg = cfg;
priv->fw = fw;
switch (priv->cfg->device_family) {
case IWL_DEVICE_FAMILY_1000:
case IWL_DEVICE_FAMILY_100:
priv->lib = &iwl1000_lib;
break;
case IWL_DEVICE_FAMILY_2000:
case IWL_DEVICE_FAMILY_105:
priv->lib = &iwl2000_lib;
break;
case IWL_DEVICE_FAMILY_2030:
case IWL_DEVICE_FAMILY_135:
priv->lib = &iwl2030_lib;
break;
case IWL_DEVICE_FAMILY_5000:
priv->lib = &iwl5000_lib;
break;
case IWL_DEVICE_FAMILY_5150:
priv->lib = &iwl5150_lib;
break;
case IWL_DEVICE_FAMILY_6000:
case IWL_DEVICE_FAMILY_6005:
case IWL_DEVICE_FAMILY_6000i:
case IWL_DEVICE_FAMILY_6050:
case IWL_DEVICE_FAMILY_6150:
priv->lib = &iwl6000_lib;
break;
case IWL_DEVICE_FAMILY_6030:
priv->lib = &iwl6030_lib;
break;
default:
break;
}
if (WARN_ON(!priv->lib))
goto out_free_hw;
trans_cfg.op_mode = op_mode;
trans_cfg.no_reclaim_cmds = no_reclaim_cmds;
trans_cfg.n_no_reclaim_cmds = ARRAY_SIZE(no_reclaim_cmds);
trans_cfg.rx_buf_size_8k = iwlwifi_mod_params.amsdu_size_8K;
if (!iwlwifi_mod_params.wd_disable)
trans_cfg.queue_watchdog_timeout =
priv->cfg->base_params->wd_timeout;
else
trans_cfg.queue_watchdog_timeout = IWL_WATCHHDOG_DISABLED;
trans_cfg.command_names = iwl_dvm_cmd_strings;
ucode_flags = fw->ucode_capa.flags;
#ifndef CONFIG_IWLWIFI_P2P
ucode_flags &= ~IWL_UCODE_TLV_FLAGS_P2P;
#endif
if (ucode_flags & IWL_UCODE_TLV_FLAGS_PAN) {
priv->sta_key_max_num = STA_KEY_MAX_NUM_PAN;
trans_cfg.cmd_queue = IWL_IPAN_CMD_QUEUE_NUM;
trans_cfg.queue_to_fifo = iwlagn_ipan_queue_to_tx_fifo;
trans_cfg.n_queue_to_fifo =
ARRAY_SIZE(iwlagn_ipan_queue_to_tx_fifo);
} else {
priv->sta_key_max_num = STA_KEY_MAX_NUM;
trans_cfg.cmd_queue = IWL_DEFAULT_CMD_QUEUE_NUM;
trans_cfg.queue_to_fifo = iwlagn_default_queue_to_tx_fifo;
trans_cfg.n_queue_to_fifo =
ARRAY_SIZE(iwlagn_default_queue_to_tx_fifo);
}
iwl_trans_configure(priv->trans, &trans_cfg);
SET_IEEE80211_DEV(priv->hw, priv->trans->dev);
iwl_option_config(priv);
IWL_DEBUG_INFO(priv, "*** LOAD DRIVER ***\n");
priv->bt_ant_couple_ok =
(iwlwifi_mod_params.ant_coupling >
IWL_BT_ANTENNA_COUPLING_THRESHOLD) ?
true : false;
priv->bt_ch_announce = iwlwifi_mod_params.bt_ch_announce;
IWL_DEBUG_INFO(priv, "BT channel inhibition is %s\n",
(priv->bt_ch_announce) ? "On" : "Off");
spin_lock_init(&priv->statistics.lock);
IWL_INFO(priv, "Detected %s, REV=0x%X\n",
priv->cfg->name, priv->trans->hw_rev);
if (iwl_trans_start_hw(priv->trans))
goto out_free_hw;
if (iwl_eeprom_init(priv, priv->trans->hw_rev)) {
IWL_ERR(priv, "Unable to init EEPROM\n");
goto out_free_hw;
}
iwl_trans_stop_hw(priv->trans, false);
if (iwl_eeprom_check_version(priv))
goto out_free_eeprom;
if (iwl_eeprom_init_hw_params(priv))
goto out_free_eeprom;
iwl_eeprom_get_mac(priv, priv->addresses[0].addr);
IWL_DEBUG_INFO(priv, "MAC address: %pM\n", priv->addresses[0].addr);
priv->hw->wiphy->addresses = priv->addresses;
priv->hw->wiphy->n_addresses = 1;
num_mac = iwl_eeprom_query16(priv, EEPROM_NUM_MAC_ADDRESS);
if (num_mac > 1) {
memcpy(priv->addresses[1].addr, priv->addresses[0].addr,
ETH_ALEN);
priv->addresses[1].addr[5]++;
priv->hw->wiphy->n_addresses++;
}
iwl_set_hw_params(priv);
if (!(priv->hw_params.sku & EEPROM_SKU_CAP_IPAN_ENABLE)) {
IWL_DEBUG_INFO(priv, "Your EEPROM disabled PAN");
ucode_flags &= ~IWL_UCODE_TLV_FLAGS_PAN;
ucode_flags &= ~IWL_UCODE_TLV_FLAGS_P2P;
priv->sta_key_max_num = STA_KEY_MAX_NUM;
trans_cfg.cmd_queue = IWL_DEFAULT_CMD_QUEUE_NUM;
trans_cfg.queue_to_fifo = iwlagn_default_queue_to_tx_fifo;
trans_cfg.n_queue_to_fifo =
ARRAY_SIZE(iwlagn_default_queue_to_tx_fifo);
iwl_trans_configure(priv->trans, &trans_cfg);
}
for (i = 0; i < IWL_MAX_HW_QUEUES; i++) {
priv->queue_to_mac80211[i] = IWL_INVALID_MAC80211_QUEUE;
if (i < IWLAGN_FIRST_AMPDU_QUEUE &&
i != IWL_DEFAULT_CMD_QUEUE_NUM &&
i != IWL_IPAN_CMD_QUEUE_NUM)
priv->queue_to_mac80211[i] = i;
atomic_set(&priv->queue_stop_count[i], 0);
}
WARN_ON(trans_cfg.queue_to_fifo[trans_cfg.cmd_queue] !=
IWLAGN_CMD_FIFO_NUM);
if (iwl_init_drv(priv))
goto out_free_eeprom;
iwl_setup_deferred_work(priv);
iwl_setup_rx_handlers(priv);
iwl_testmode_init(priv);
iwl_power_initialize(priv);
iwl_tt_initialize(priv);
snprintf(priv->hw->wiphy->fw_version,
sizeof(priv->hw->wiphy->fw_version),
"%s", fw->fw_version);
priv->new_scan_threshold_behaviour =
!!(ucode_flags & IWL_UCODE_TLV_FLAGS_NEWSCAN);
priv->phy_calib_chain_noise_reset_cmd =
fw->ucode_capa.standard_phy_calibration_size;
priv->phy_calib_chain_noise_gain_cmd =
fw->ucode_capa.standard_phy_calibration_size + 1;
iwl_init_context(priv, ucode_flags);
if (iwlagn_mac_setup_register(priv, &fw->ucode_capa))
goto out_destroy_workqueue;
if (iwl_dbgfs_register(priv, DRV_NAME))
IWL_ERR(priv,
"failed to create debugfs files. Ignoring error\n");
return op_mode;
out_destroy_workqueue:
destroy_workqueue(priv->workqueue);
priv->workqueue = NULL;
iwl_uninit_drv(priv);
out_free_eeprom:
iwl_eeprom_free(priv);
out_free_hw:
ieee80211_free_hw(priv->hw);
out:
op_mode = NULL;
return op_mode;
}
void iwl_op_mode_dvm_stop(struct iwl_op_mode *op_mode)
{
struct iwl_priv *priv = IWL_OP_MODE_GET_DVM(op_mode);
IWL_DEBUG_INFO(priv, "*** UNLOAD DRIVER ***\n");
iwl_dbgfs_unregister(priv);
iwl_testmode_cleanup(priv);
iwlagn_mac_unregister(priv);
iwl_tt_exit(priv);
priv->ucode_loaded = false;
iwl_trans_stop_device(priv->trans);
iwl_eeprom_free(priv);
flush_workqueue(priv->workqueue);
destroy_workqueue(priv->workqueue);
priv->workqueue = NULL;
iwl_uninit_drv(priv);
dev_kfree_skb(priv->beacon_skb);
iwl_trans_stop_hw(priv->trans, true);
ieee80211_free_hw(priv->hw);
}
static const char *desc_lookup(u32 num)
{
int i;
int max = ARRAY_SIZE(desc_lookup_text);
if (num < max)
return desc_lookup_text[num];
max = ARRAY_SIZE(advanced_lookup) - 1;
for (i = 0; i < max; i++) {
if (advanced_lookup[i].num == num)
break;
}
return advanced_lookup[i].name;
}
static void iwl_dump_nic_error_log(struct iwl_priv *priv)
{
struct iwl_trans *trans = priv->trans;
u32 base;
struct iwl_error_event_table table;
base = priv->device_pointers.error_event_table;
if (priv->cur_ucode == IWL_UCODE_INIT) {
if (!base)
base = priv->fw->init_errlog_ptr;
} else {
if (!base)
base = priv->fw->inst_errlog_ptr;
}
if (!iwlagn_hw_valid_rtc_data_addr(base)) {
IWL_ERR(priv,
"Not valid error log pointer 0x%08X for %s uCode\n",
base,
(priv->cur_ucode == IWL_UCODE_INIT)
? "Init" : "RT");
return;
}
iwl_read_targ_mem_words(trans, base, &table, sizeof(table));
if (ERROR_START_OFFSET <= table.valid * ERROR_ELEM_SIZE) {
IWL_ERR(trans, "Start IWL Error Log Dump:\n");
IWL_ERR(trans, "Status: 0x%08lX, count: %d\n",
priv->status, table.valid);
}
trace_iwlwifi_dev_ucode_error(trans->dev, table.error_id, table.tsf_low,
table.data1, table.data2, table.line,
table.blink1, table.blink2, table.ilink1,
table.ilink2, table.bcon_time, table.gp1,
table.gp2, table.gp3, table.ucode_ver,
table.hw_ver, table.brd_ver);
IWL_ERR(priv, "0x%08X | %-28s\n", table.error_id,
desc_lookup(table.error_id));
IWL_ERR(priv, "0x%08X | uPc\n", table.pc);
IWL_ERR(priv, "0x%08X | branchlink1\n", table.blink1);
IWL_ERR(priv, "0x%08X | branchlink2\n", table.blink2);
IWL_ERR(priv, "0x%08X | interruptlink1\n", table.ilink1);
IWL_ERR(priv, "0x%08X | interruptlink2\n", table.ilink2);
IWL_ERR(priv, "0x%08X | data1\n", table.data1);
IWL_ERR(priv, "0x%08X | data2\n", table.data2);
IWL_ERR(priv, "0x%08X | line\n", table.line);
IWL_ERR(priv, "0x%08X | beacon time\n", table.bcon_time);
IWL_ERR(priv, "0x%08X | tsf low\n", table.tsf_low);
IWL_ERR(priv, "0x%08X | tsf hi\n", table.tsf_hi);
IWL_ERR(priv, "0x%08X | time gp1\n", table.gp1);
IWL_ERR(priv, "0x%08X | time gp2\n", table.gp2);
IWL_ERR(priv, "0x%08X | time gp3\n", table.gp3);
IWL_ERR(priv, "0x%08X | uCode version\n", table.ucode_ver);
IWL_ERR(priv, "0x%08X | hw version\n", table.hw_ver);
IWL_ERR(priv, "0x%08X | board version\n", table.brd_ver);
IWL_ERR(priv, "0x%08X | hcmd\n", table.hcmd);
IWL_ERR(priv, "0x%08X | isr0\n", table.isr0);
IWL_ERR(priv, "0x%08X | isr1\n", table.isr1);
IWL_ERR(priv, "0x%08X | isr2\n", table.isr2);
IWL_ERR(priv, "0x%08X | isr3\n", table.isr3);
IWL_ERR(priv, "0x%08X | isr4\n", table.isr4);
IWL_ERR(priv, "0x%08X | isr_pref\n", table.isr_pref);
IWL_ERR(priv, "0x%08X | wait_event\n", table.wait_event);
IWL_ERR(priv, "0x%08X | l2p_control\n", table.l2p_control);
IWL_ERR(priv, "0x%08X | l2p_duration\n", table.l2p_duration);
IWL_ERR(priv, "0x%08X | l2p_mhvalid\n", table.l2p_mhvalid);
IWL_ERR(priv, "0x%08X | l2p_addr_match\n", table.l2p_addr_match);
IWL_ERR(priv, "0x%08X | lmpm_pmg_sel\n", table.lmpm_pmg_sel);
IWL_ERR(priv, "0x%08X | timestamp\n", table.u_timestamp);
IWL_ERR(priv, "0x%08X | flow_handler\n", table.flow_handler);
}
static int iwl_print_event_log(struct iwl_priv *priv, u32 start_idx,
u32 num_events, u32 mode,
int pos, char **buf, size_t bufsz)
{
u32 i;
u32 base;
u32 event_size;
u32 ptr;
u32 ev, time, data;
unsigned long reg_flags;
struct iwl_trans *trans = priv->trans;
if (num_events == 0)
return pos;
base = priv->device_pointers.log_event_table;
if (priv->cur_ucode == IWL_UCODE_INIT) {
if (!base)
base = priv->fw->init_evtlog_ptr;
} else {
if (!base)
base = priv->fw->inst_evtlog_ptr;
}
if (mode == 0)
event_size = 2 * sizeof(u32);
else
event_size = 3 * sizeof(u32);
ptr = base + EVENT_START_OFFSET + (start_idx * event_size);
spin_lock_irqsave(&trans->reg_lock, reg_flags);
if (unlikely(!iwl_grab_nic_access(trans)))
goto out_unlock;
iwl_write32(trans, HBUS_TARG_MEM_RADDR, ptr);
for (i = 0; i < num_events; i++) {
ev = iwl_read32(trans, HBUS_TARG_MEM_RDAT);
time = iwl_read32(trans, HBUS_TARG_MEM_RDAT);
if (mode == 0) {
if (bufsz) {
pos += scnprintf(*buf + pos, bufsz - pos,
"EVT_LOG:0x%08x:%04u\n",
time, ev);
} else {
trace_iwlwifi_dev_ucode_event(trans->dev, 0,
time, ev);
IWL_ERR(priv, "EVT_LOG:0x%08x:%04u\n",
time, ev);
}
} else {
data = iwl_read32(trans, HBUS_TARG_MEM_RDAT);
if (bufsz) {
pos += scnprintf(*buf + pos, bufsz - pos,
"EVT_LOGT:%010u:0x%08x:%04u\n",
time, data, ev);
} else {
IWL_ERR(priv, "EVT_LOGT:%010u:0x%08x:%04u\n",
time, data, ev);
trace_iwlwifi_dev_ucode_event(trans->dev, time,
data, ev);
}
}
}
iwl_release_nic_access(trans);
out_unlock:
spin_unlock_irqrestore(&trans->reg_lock, reg_flags);
return pos;
}
static int iwl_print_last_event_logs(struct iwl_priv *priv, u32 capacity,
u32 num_wraps, u32 next_entry,
u32 size, u32 mode,
int pos, char **buf, size_t bufsz)
{
if (num_wraps) {
if (next_entry < size) {
pos = iwl_print_event_log(priv,
capacity - (size - next_entry),
size - next_entry, mode,
pos, buf, bufsz);
pos = iwl_print_event_log(priv, 0,
next_entry, mode,
pos, buf, bufsz);
} else
pos = iwl_print_event_log(priv, next_entry - size,
size, mode, pos, buf, bufsz);
} else {
if (next_entry < size) {
pos = iwl_print_event_log(priv, 0, next_entry,
mode, pos, buf, bufsz);
} else {
pos = iwl_print_event_log(priv, next_entry - size,
size, mode, pos, buf, bufsz);
}
}
return pos;
}
int iwl_dump_nic_event_log(struct iwl_priv *priv, bool full_log,
char **buf, bool display)
{
u32 base;
u32 capacity;
u32 mode;
u32 num_wraps;
u32 next_entry;
u32 size;
u32 logsize;
int pos = 0;
size_t bufsz = 0;
struct iwl_trans *trans = priv->trans;
base = priv->device_pointers.log_event_table;
if (priv->cur_ucode == IWL_UCODE_INIT) {
logsize = priv->fw->init_evtlog_size;
if (!base)
base = priv->fw->init_evtlog_ptr;
} else {
logsize = priv->fw->inst_evtlog_size;
if (!base)
base = priv->fw->inst_evtlog_ptr;
}
if (!iwlagn_hw_valid_rtc_data_addr(base)) {
IWL_ERR(priv,
"Invalid event log pointer 0x%08X for %s uCode\n",
base,
(priv->cur_ucode == IWL_UCODE_INIT)
? "Init" : "RT");
return -EINVAL;
}
capacity = iwl_read_targ_mem(trans, base);
mode = iwl_read_targ_mem(trans, base + (1 * sizeof(u32)));
num_wraps = iwl_read_targ_mem(trans, base + (2 * sizeof(u32)));
next_entry = iwl_read_targ_mem(trans, base + (3 * sizeof(u32)));
if (capacity > logsize) {
IWL_ERR(priv, "Log capacity %d is bogus, limit to %d "
"entries\n", capacity, logsize);
capacity = logsize;
}
if (next_entry > logsize) {
IWL_ERR(priv, "Log write index %d is bogus, limit to %d\n",
next_entry, logsize);
next_entry = logsize;
}
size = num_wraps ? capacity : next_entry;
if (size == 0) {
IWL_ERR(trans, "Start IWL Event Log Dump: nothing in log\n");
return pos;
}
#ifdef CONFIG_IWLWIFI_DEBUG
if (!(iwl_have_debug_level(IWL_DL_FW_ERRORS)) && !full_log)
size = (size > DEFAULT_DUMP_EVENT_LOG_ENTRIES)
? DEFAULT_DUMP_EVENT_LOG_ENTRIES : size;
#else
size = (size > DEFAULT_DUMP_EVENT_LOG_ENTRIES)
? DEFAULT_DUMP_EVENT_LOG_ENTRIES : size;
#endif
IWL_ERR(priv, "Start IWL Event Log Dump: display last %u entries\n",
size);
#ifdef CONFIG_IWLWIFI_DEBUG
if (display) {
if (full_log)
bufsz = capacity * 48;
else
bufsz = size * 48;
*buf = kmalloc(bufsz, GFP_KERNEL);
if (!*buf)
return -ENOMEM;
}
if (iwl_have_debug_level(IWL_DL_FW_ERRORS) || full_log) {
if (num_wraps)
pos = iwl_print_event_log(priv, next_entry,
capacity - next_entry, mode,
pos, buf, bufsz);
pos = iwl_print_event_log(priv, 0,
next_entry, mode, pos, buf, bufsz);
} else
pos = iwl_print_last_event_logs(priv, capacity, num_wraps,
next_entry, size, mode,
pos, buf, bufsz);
#else
pos = iwl_print_last_event_logs(priv, capacity, num_wraps,
next_entry, size, mode,
pos, buf, bufsz);
#endif
return pos;
}
static void iwlagn_fw_error(struct iwl_priv *priv, bool ondemand)
{
unsigned int reload_msec;
unsigned long reload_jiffies;
#ifdef CONFIG_IWLWIFI_DEBUG
if (iwl_have_debug_level(IWL_DL_FW_ERRORS))
iwl_print_rx_config_cmd(priv, IWL_RXON_CTX_BSS);
#endif
priv->ucode_loaded = false;
set_bit(STATUS_FW_ERROR, &priv->status);
iwl_abort_notification_waits(&priv->notif_wait);
clear_bit(STATUS_READY, &priv->status);
wake_up(&priv->trans->wait_command_queue);
if (!ondemand) {
reload_jiffies = jiffies;
reload_msec = jiffies_to_msecs((long) reload_jiffies -
(long) priv->reload_jiffies);
priv->reload_jiffies = reload_jiffies;
if (reload_msec <= IWL_MIN_RELOAD_DURATION) {
priv->reload_count++;
if (priv->reload_count >= IWL_MAX_CONTINUE_RELOAD_CNT) {
IWL_ERR(priv, "BUG_ON, Stop restarting\n");
return;
}
} else
priv->reload_count = 0;
}
if (!test_bit(STATUS_EXIT_PENDING, &priv->status)) {
if (iwlwifi_mod_params.restart_fw) {
IWL_DEBUG_FW_ERRORS(priv,
"Restarting adapter due to uCode error.\n");
queue_work(priv->workqueue, &priv->restart);
} else
IWL_DEBUG_FW_ERRORS(priv,
"Detected FW error, but not restarting\n");
}
}
void iwl_nic_error(struct iwl_op_mode *op_mode)
{
struct iwl_priv *priv = IWL_OP_MODE_GET_DVM(op_mode);
IWL_ERR(priv, "Loaded firmware version: %s\n",
priv->fw->fw_version);
iwl_dump_nic_error_log(priv);
iwl_dump_nic_event_log(priv, false, NULL, false);
iwlagn_fw_error(priv, false);
}
void iwl_cmd_queue_full(struct iwl_op_mode *op_mode)
{
struct iwl_priv *priv = IWL_OP_MODE_GET_DVM(op_mode);
if (!iwl_check_for_ct_kill(priv)) {
IWL_ERR(priv, "Restarting adapter queue is full\n");
iwlagn_fw_error(priv, false);
}
}
void iwl_nic_config(struct iwl_op_mode *op_mode)
{
struct iwl_priv *priv = IWL_OP_MODE_GET_DVM(op_mode);
priv->lib->nic_config(priv);
}
static void iwl_wimax_active(struct iwl_op_mode *op_mode)
{
struct iwl_priv *priv = IWL_OP_MODE_GET_DVM(op_mode);
clear_bit(STATUS_READY, &priv->status);
IWL_ERR(priv, "RF is used by WiMAX\n");
}
void iwl_stop_sw_queue(struct iwl_op_mode *op_mode, int queue)
{
struct iwl_priv *priv = IWL_OP_MODE_GET_DVM(op_mode);
int mq = priv->queue_to_mac80211[queue];
if (WARN_ON_ONCE(mq == IWL_INVALID_MAC80211_QUEUE))
return;
if (atomic_inc_return(&priv->queue_stop_count[mq]) > 1) {
IWL_DEBUG_TX_QUEUES(priv,
"queue %d (mac80211 %d) already stopped\n",
queue, mq);
return;
}
set_bit(mq, &priv->transport_queue_stop);
ieee80211_stop_queue(priv->hw, mq);
}
void iwl_wake_sw_queue(struct iwl_op_mode *op_mode, int queue)
{
struct iwl_priv *priv = IWL_OP_MODE_GET_DVM(op_mode);
int mq = priv->queue_to_mac80211[queue];
if (WARN_ON_ONCE(mq == IWL_INVALID_MAC80211_QUEUE))
return;
if (atomic_dec_return(&priv->queue_stop_count[mq]) > 0) {
IWL_DEBUG_TX_QUEUES(priv,
"queue %d (mac80211 %d) already awake\n",
queue, mq);
return;
}
clear_bit(mq, &priv->transport_queue_stop);
if (!priv->passive_no_rx)
ieee80211_wake_queue(priv->hw, mq);
}
void iwlagn_lift_passive_no_rx(struct iwl_priv *priv)
{
int mq;
if (!priv->passive_no_rx)
return;
for (mq = 0; mq < IWLAGN_FIRST_AMPDU_QUEUE; mq++) {
if (!test_bit(mq, &priv->transport_queue_stop)) {
IWL_DEBUG_TX_QUEUES(priv, "Wake queue %d", mq);
ieee80211_wake_queue(priv->hw, mq);
} else {
IWL_DEBUG_TX_QUEUES(priv, "Don't wake queue %d", mq);
}
}
priv->passive_no_rx = false;
}
void iwl_free_skb(struct iwl_op_mode *op_mode, struct sk_buff *skb)
{
struct ieee80211_tx_info *info;
info = IEEE80211_SKB_CB(skb);
kmem_cache_free(iwl_tx_cmd_pool, (info->driver_data[1]));
dev_kfree_skb_any(skb);
}
void iwl_set_hw_rfkill_state(struct iwl_op_mode *op_mode, bool state)
{
struct iwl_priv *priv = IWL_OP_MODE_GET_DVM(op_mode);
if (state)
set_bit(STATUS_RF_KILL_HW, &priv->status);
else
clear_bit(STATUS_RF_KILL_HW, &priv->status);
wiphy_rfkill_set_hw_state(priv->hw->wiphy, state);
}
static int __init iwl_init(void)
{
int ret;
pr_info(DRV_DESCRIPTION ", " DRV_VERSION "\n");
pr_info(DRV_COPYRIGHT "\n");
iwl_tx_cmd_pool = kmem_cache_create("iwl_dev_cmd",
sizeof(struct iwl_device_cmd),
sizeof(void *), 0, NULL);
if (!iwl_tx_cmd_pool)
return -ENOMEM;
ret = iwlagn_rate_control_register();
if (ret) {
pr_err("Unable to register rate control algorithm: %d\n", ret);
goto error_rc_register;
}
ret = iwl_pci_register_driver();
if (ret)
goto error_pci_register;
return ret;
error_pci_register:
iwlagn_rate_control_unregister();
error_rc_register:
kmem_cache_destroy(iwl_tx_cmd_pool);
return ret;
}
static void __exit iwl_exit(void)
{
iwl_pci_unregister_driver();
iwlagn_rate_control_unregister();
kmem_cache_destroy(iwl_tx_cmd_pool);
}
