static int __init iwl_mvm_init(void)
{
int ret;
ret = iwl_mvm_rate_control_register();
if (ret) {
pr_err("Unable to register rate control algorithm: %d\n", ret);
return ret;
}
ret = iwl_opmode_register("iwlmvm", &iwl_mvm_ops);
if (ret) {
pr_err("Unable to register MVM op_mode: %d\n", ret);
iwl_mvm_rate_control_unregister();
}
return ret;
}
static void __exit iwl_mvm_exit(void)
{
iwl_opmode_deregister("iwlmvm");
iwl_mvm_rate_control_unregister();
}
static void iwl_mvm_nic_config(struct iwl_op_mode *op_mode)
{
struct iwl_mvm *mvm = IWL_OP_MODE_GET_MVM(op_mode);
u8 radio_cfg_type, radio_cfg_step, radio_cfg_dash;
u32 reg_val = 0;
radio_cfg_type = (mvm->fw->phy_config & FW_PHY_CFG_RADIO_TYPE) >>
FW_PHY_CFG_RADIO_TYPE_POS;
radio_cfg_step = (mvm->fw->phy_config & FW_PHY_CFG_RADIO_STEP) >>
FW_PHY_CFG_RADIO_STEP_POS;
radio_cfg_dash = (mvm->fw->phy_config & FW_PHY_CFG_RADIO_DASH) >>
FW_PHY_CFG_RADIO_DASH_POS;
reg_val |= CSR_HW_REV_STEP(mvm->trans->hw_rev) <<
CSR_HW_IF_CONFIG_REG_POS_MAC_STEP;
reg_val |= CSR_HW_REV_DASH(mvm->trans->hw_rev) <<
CSR_HW_IF_CONFIG_REG_POS_MAC_DASH;
reg_val |= radio_cfg_type << CSR_HW_IF_CONFIG_REG_POS_PHY_TYPE;
reg_val |= radio_cfg_step << CSR_HW_IF_CONFIG_REG_POS_PHY_STEP;
reg_val |= radio_cfg_dash << CSR_HW_IF_CONFIG_REG_POS_PHY_DASH;
WARN_ON((radio_cfg_type << CSR_HW_IF_CONFIG_REG_POS_PHY_TYPE) &
~CSR_HW_IF_CONFIG_REG_MSK_PHY_TYPE);
reg_val |= CSR_HW_IF_CONFIG_REG_BIT_RADIO_SI;
iwl_trans_set_bits_mask(mvm->trans, CSR_HW_IF_CONFIG_REG,
CSR_HW_IF_CONFIG_REG_MSK_MAC_DASH |
CSR_HW_IF_CONFIG_REG_MSK_MAC_STEP |
CSR_HW_IF_CONFIG_REG_MSK_PHY_TYPE |
CSR_HW_IF_CONFIG_REG_MSK_PHY_STEP |
CSR_HW_IF_CONFIG_REG_MSK_PHY_DASH |
CSR_HW_IF_CONFIG_REG_BIT_RADIO_SI |
CSR_HW_IF_CONFIG_REG_BIT_MAC_SI,
reg_val);
IWL_DEBUG_INFO(mvm, "Radio type=0x%x-0x%x-0x%x\n", radio_cfg_type,
radio_cfg_step, radio_cfg_dash);
iwl_set_bits_mask_prph(mvm->trans, APMG_PS_CTRL_REG,
APMG_PS_CTRL_EARLY_PWR_OFF_RESET_DIS,
~APMG_PS_CTRL_EARLY_PWR_OFF_RESET_DIS);
}
static struct iwl_op_mode *
iwl_op_mode_mvm_start(struct iwl_trans *trans, const struct iwl_cfg *cfg,
const struct iwl_fw *fw, struct dentry *dbgfs_dir)
{
struct ieee80211_hw *hw;
struct iwl_op_mode *op_mode;
struct iwl_mvm *mvm;
struct iwl_trans_config trans_cfg = {};
static const u8 no_reclaim_cmds[] = {
TX_CMD,
};
int err, scan_size;
hw = ieee80211_alloc_hw(sizeof(struct iwl_op_mode) +
sizeof(struct iwl_mvm),
&iwl_mvm_hw_ops);
if (!hw)
return NULL;
op_mode = hw->priv;
op_mode->ops = &iwl_mvm_ops;
mvm = IWL_OP_MODE_GET_MVM(op_mode);
mvm->dev = trans->dev;
mvm->trans = trans;
mvm->cfg = cfg;
mvm->fw = fw;
mvm->hw = hw;
mvm->restart_fw = iwlwifi_mod_params.restart_fw ? -1 : 0;
mvm->aux_queue = 15;
mvm->first_agg_queue = 16;
mvm->last_agg_queue = mvm->cfg->base_params->num_of_queues - 1;
if (mvm->cfg->base_params->num_of_queues == 16) {
mvm->aux_queue = 11;
mvm->first_agg_queue = 12;
}
mvm->sf_state = SF_UNINIT;
mutex_init(&mvm->mutex);
spin_lock_init(&mvm->async_handlers_lock);
INIT_LIST_HEAD(&mvm->time_event_list);
INIT_LIST_HEAD(&mvm->async_handlers_list);
spin_lock_init(&mvm->time_event_lock);
INIT_WORK(&mvm->async_handlers_wk, iwl_mvm_async_handlers_wk);
INIT_WORK(&mvm->roc_done_wk, iwl_mvm_roc_done_wk);
INIT_WORK(&mvm->sta_drained_wk, iwl_mvm_sta_drained_wk);
SET_IEEE80211_DEV(mvm->hw, mvm->trans->dev);
trans_cfg.op_mode = op_mode;
trans_cfg.no_reclaim_cmds = no_reclaim_cmds;
trans_cfg.n_no_reclaim_cmds = ARRAY_SIZE(no_reclaim_cmds);
trans_cfg.rx_buf_size_8k = iwlwifi_mod_params.amsdu_size_8K;
if (mvm->fw->ucode_capa.flags & IWL_UCODE_TLV_FLAGS_DW_BC_TABLE)
trans_cfg.bc_table_dword = true;
if (!iwlwifi_mod_params.wd_disable)
trans_cfg.queue_watchdog_timeout = cfg->base_params->wd_timeout;
else
trans_cfg.queue_watchdog_timeout = IWL_WATCHDOG_DISABLED;
trans_cfg.command_names = iwl_mvm_cmd_strings;
trans_cfg.cmd_queue = IWL_MVM_CMD_QUEUE;
trans_cfg.cmd_fifo = IWL_MVM_CMD_FIFO;
snprintf(mvm->hw->wiphy->fw_version,
sizeof(mvm->hw->wiphy->fw_version),
"%s", fw->fw_version);
iwl_trans_configure(mvm->trans, &trans_cfg);
trans->rx_mpdu_cmd = REPLY_RX_MPDU_CMD;
trans->rx_mpdu_cmd_hdr_size = sizeof(struct iwl_rx_mpdu_res_start);
iwl_notification_wait_init(&mvm->notif_wait);
mvm->phy_db = iwl_phy_db_init(trans);
if (!mvm->phy_db) {
IWL_ERR(mvm, "Cannot init phy_db\n");
goto out_free;
}
IWL_INFO(mvm, "Detected %s, REV=0x%X\n",
mvm->cfg->name, mvm->trans->hw_rev);
iwl_mvm_tt_initialize(mvm);
if (iwlwifi_mod_params.nvm_file) {
err = iwl_nvm_init(mvm);
if (err)
goto out_free;
} else {
err = iwl_trans_start_hw(mvm->trans);
if (err)
goto out_free;
mutex_lock(&mvm->mutex);
err = iwl_run_init_mvm_ucode(mvm, true);
iwl_trans_stop_device(trans);
mutex_unlock(&mvm->mutex);
if (err < 0 && !iwlmvm_mod_params.init_dbg) {
IWL_ERR(mvm, "Failed to run INIT ucode: %d\n", err);
goto out_free;
}
}
scan_size = sizeof(struct iwl_scan_cmd) +
mvm->fw->ucode_capa.max_probe_length +
(MAX_NUM_SCAN_CHANNELS * sizeof(struct iwl_scan_channel));
mvm->scan_cmd = kmalloc(scan_size, GFP_KERNEL);
if (!mvm->scan_cmd)
goto out_free;
err = iwl_mvm_mac_setup_register(mvm);
if (err)
goto out_free;
err = iwl_mvm_dbgfs_register(mvm, dbgfs_dir);
if (err)
goto out_unregister;
if (mvm->fw->ucode_capa.flags & IWL_UCODE_TLV_FLAGS_PM_CMD_SUPPORT)
mvm->pm_ops = &pm_mac_ops;
else
mvm->pm_ops = &pm_legacy_ops;
memset(&mvm->rx_stats, 0, sizeof(struct mvm_statistics_rx));
return op_mode;
out_unregister:
ieee80211_unregister_hw(mvm->hw);
iwl_mvm_leds_exit(mvm);
out_free:
iwl_phy_db_free(mvm->phy_db);
kfree(mvm->scan_cmd);
if (!iwlwifi_mod_params.nvm_file)
iwl_trans_op_mode_leave(trans);
ieee80211_free_hw(mvm->hw);
return NULL;
}
static void iwl_op_mode_mvm_stop(struct iwl_op_mode *op_mode)
{
struct iwl_mvm *mvm = IWL_OP_MODE_GET_MVM(op_mode);
int i;
iwl_mvm_leds_exit(mvm);
iwl_mvm_tt_exit(mvm);
ieee80211_unregister_hw(mvm->hw);
kfree(mvm->scan_cmd);
kfree(mvm->mcast_filter_cmd);
mvm->mcast_filter_cmd = NULL;
#if defined(CONFIG_PM_SLEEP) && defined(CONFIG_IWLWIFI_DEBUGFS)
kfree(mvm->d3_resume_sram);
#endif
iwl_trans_op_mode_leave(mvm->trans);
iwl_phy_db_free(mvm->phy_db);
mvm->phy_db = NULL;
iwl_free_nvm_data(mvm->nvm_data);
for (i = 0; i < NVM_NUM_OF_SECTIONS; i++)
kfree(mvm->nvm_sections[i].data);
ieee80211_free_hw(mvm->hw);
}
void iwl_mvm_async_handlers_purge(struct iwl_mvm *mvm)
{
struct iwl_async_handler_entry *entry, *tmp;
spin_lock_bh(&mvm->async_handlers_lock);
list_for_each_entry_safe(entry, tmp, &mvm->async_handlers_list, list) {
iwl_free_rxb(&entry->rxb);
list_del(&entry->list);
kfree(entry);
}
spin_unlock_bh(&mvm->async_handlers_lock);
}
static void iwl_mvm_async_handlers_wk(struct work_struct *wk)
{
struct iwl_mvm *mvm =
container_of(wk, struct iwl_mvm, async_handlers_wk);
struct iwl_async_handler_entry *entry, *tmp;
struct list_head local_list;
INIT_LIST_HEAD(&local_list);
mutex_lock(&mvm->mutex);
spin_lock_bh(&mvm->async_handlers_lock);
list_splice_init(&mvm->async_handlers_list, &local_list);
spin_unlock_bh(&mvm->async_handlers_lock);
list_for_each_entry_safe(entry, tmp, &local_list, list) {
if (entry->fn(mvm, &entry->rxb, NULL))
IWL_WARN(mvm,
"returned value from ASYNC handlers are ignored\n");
iwl_free_rxb(&entry->rxb);
list_del(&entry->list);
kfree(entry);
}
mutex_unlock(&mvm->mutex);
}
static int iwl_mvm_rx_dispatch(struct iwl_op_mode *op_mode,
struct iwl_rx_cmd_buffer *rxb,
struct iwl_device_cmd *cmd)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
struct iwl_mvm *mvm = IWL_OP_MODE_GET_MVM(op_mode);
u8 i;
iwl_notification_wait_notify(&mvm->notif_wait, pkt);
for (i = 0; i < ARRAY_SIZE(iwl_mvm_rx_handlers); i++) {
const struct iwl_rx_handlers *rx_h = &iwl_mvm_rx_handlers[i];
struct iwl_async_handler_entry *entry;
if (rx_h->cmd_id != pkt->hdr.cmd)
continue;
if (!rx_h->async)
return rx_h->fn(mvm, rxb, cmd);
entry = kzalloc(sizeof(*entry), GFP_ATOMIC);
if (!entry)
return 0;
entry->rxb._page = rxb_steal_page(rxb);
entry->rxb._offset = rxb->_offset;
entry->rxb._rx_page_order = rxb->_rx_page_order;
entry->fn = rx_h->fn;
spin_lock(&mvm->async_handlers_lock);
list_add_tail(&entry->list, &mvm->async_handlers_list);
spin_unlock(&mvm->async_handlers_lock);
schedule_work(&mvm->async_handlers_wk);
break;
}
return 0;
}
static void iwl_mvm_stop_sw_queue(struct iwl_op_mode *op_mode, int queue)
{
struct iwl_mvm *mvm = IWL_OP_MODE_GET_MVM(op_mode);
int mq = mvm->queue_to_mac80211[queue];
if (WARN_ON_ONCE(mq == IWL_INVALID_MAC80211_QUEUE))
return;
if (atomic_inc_return(&mvm->queue_stop_count[mq]) > 1) {
IWL_DEBUG_TX_QUEUES(mvm,
"queue %d (mac80211 %d) already stopped\n",
queue, mq);
return;
}
set_bit(mq, &mvm->transport_queue_stop);
ieee80211_stop_queue(mvm->hw, mq);
}
static void iwl_mvm_wake_sw_queue(struct iwl_op_mode *op_mode, int queue)
{
struct iwl_mvm *mvm = IWL_OP_MODE_GET_MVM(op_mode);
int mq = mvm->queue_to_mac80211[queue];
if (WARN_ON_ONCE(mq == IWL_INVALID_MAC80211_QUEUE))
return;
if (atomic_dec_return(&mvm->queue_stop_count[mq]) > 0) {
IWL_DEBUG_TX_QUEUES(mvm,
"queue %d (mac80211 %d) already awake\n",
queue, mq);
return;
}
clear_bit(mq, &mvm->transport_queue_stop);
ieee80211_wake_queue(mvm->hw, mq);
}
void iwl_mvm_set_hw_ctkill_state(struct iwl_mvm *mvm, bool state)
{
if (state)
set_bit(IWL_MVM_STATUS_HW_CTKILL, &mvm->status);
else
clear_bit(IWL_MVM_STATUS_HW_CTKILL, &mvm->status);
wiphy_rfkill_set_hw_state(mvm->hw->wiphy, iwl_mvm_is_radio_killed(mvm));
}
static void iwl_mvm_set_hw_rfkill_state(struct iwl_op_mode *op_mode, bool state)
{
struct iwl_mvm *mvm = IWL_OP_MODE_GET_MVM(op_mode);
if (state)
set_bit(IWL_MVM_STATUS_HW_RFKILL, &mvm->status);
else
clear_bit(IWL_MVM_STATUS_HW_RFKILL, &mvm->status);
if (state && mvm->cur_ucode != IWL_UCODE_INIT)
iwl_trans_stop_device(mvm->trans);
wiphy_rfkill_set_hw_state(mvm->hw->wiphy, iwl_mvm_is_radio_killed(mvm));
}
static void iwl_mvm_free_skb(struct iwl_op_mode *op_mode, struct sk_buff *skb)
{
struct iwl_mvm *mvm = IWL_OP_MODE_GET_MVM(op_mode);
struct ieee80211_tx_info *info;
info = IEEE80211_SKB_CB(skb);
iwl_trans_free_tx_cmd(mvm->trans, info->driver_data[1]);
ieee80211_free_txskb(mvm->hw, skb);
}
static void iwl_mvm_reprobe_wk(struct work_struct *wk)
{
struct iwl_mvm_reprobe *reprobe;
reprobe = container_of(wk, struct iwl_mvm_reprobe, work);
if (device_reprobe(reprobe->dev))
dev_err(reprobe->dev, "reprobe failed!\n");
kfree(reprobe);
module_put(THIS_MODULE);
}
static void iwl_mvm_nic_restart(struct iwl_mvm *mvm)
{
iwl_abort_notification_waits(&mvm->notif_wait);
if (test_and_set_bit(IWL_MVM_STATUS_IN_HW_RESTART, &mvm->status)) {
struct iwl_mvm_reprobe *reprobe;
IWL_ERR(mvm,
"Firmware error during reconfiguration - reprobe!\n");
if (!try_module_get(THIS_MODULE)) {
IWL_ERR(mvm, "Module is being unloaded - abort\n");
return;
}
reprobe = kzalloc(sizeof(*reprobe), GFP_ATOMIC);
if (!reprobe) {
module_put(THIS_MODULE);
return;
}
reprobe->dev = mvm->trans->dev;
INIT_WORK(&reprobe->work, iwl_mvm_reprobe_wk);
schedule_work(&reprobe->work);
} else if (mvm->cur_ucode == IWL_UCODE_REGULAR && mvm->restart_fw) {
switch (mvm->scan_status) {
case IWL_MVM_SCAN_NONE:
break;
case IWL_MVM_SCAN_OS:
ieee80211_scan_completed(mvm->hw, true);
break;
case IWL_MVM_SCAN_SCHED:
ieee80211_sched_scan_stopped(mvm->hw);
break;
}
if (mvm->restart_fw > 0)
mvm->restart_fw--;
ieee80211_restart_hw(mvm->hw);
}
}
static void iwl_mvm_nic_error(struct iwl_op_mode *op_mode)
{
struct iwl_mvm *mvm = IWL_OP_MODE_GET_MVM(op_mode);
iwl_mvm_dump_nic_error_log(mvm);
if (!mvm->restart_fw)
iwl_mvm_dump_sram(mvm);
iwl_mvm_nic_restart(mvm);
}
static void iwl_mvm_cmd_queue_full(struct iwl_op_mode *op_mode)
{
struct iwl_mvm *mvm = IWL_OP_MODE_GET_MVM(op_mode);
WARN_ON(1);
iwl_mvm_nic_restart(mvm);
}
