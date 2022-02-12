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
u32 phy_config = iwl_mvm_get_phy_config(mvm);
radio_cfg_type = (phy_config & FW_PHY_CFG_RADIO_TYPE) >>
FW_PHY_CFG_RADIO_TYPE_POS;
radio_cfg_step = (phy_config & FW_PHY_CFG_RADIO_STEP) >>
FW_PHY_CFG_RADIO_STEP_POS;
radio_cfg_dash = (phy_config & FW_PHY_CFG_RADIO_DASH) >>
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
if (mvm->trans->cfg->device_family < IWL_DEVICE_FAMILY_8000)
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
if (!mvm->trans->cfg->apmg_not_supported)
iwl_set_bits_mask_prph(mvm->trans, APMG_PS_CTRL_REG,
APMG_PS_CTRL_EARLY_PWR_OFF_RESET_DIS,
~APMG_PS_CTRL_EARLY_PWR_OFF_RESET_DIS);
}
static u32 calc_min_backoff(struct iwl_trans *trans, const struct iwl_cfg *cfg)
{
const struct iwl_pwr_tx_backoff *pwr_tx_backoff = cfg->pwr_tx_backoffs;
if (!pwr_tx_backoff)
return 0;
while (pwr_tx_backoff->pwr) {
if (trans->dflt_pwr_limit >= pwr_tx_backoff->pwr)
return pwr_tx_backoff->backoff;
pwr_tx_backoff++;
}
return 0;
}
static void iwl_mvm_tx_unblock_dwork(struct work_struct *work)
{
struct iwl_mvm *mvm =
container_of(work, struct iwl_mvm, cs_tx_unblock_dwork.work);
struct ieee80211_vif *tx_blocked_vif;
struct iwl_mvm_vif *mvmvif;
mutex_lock(&mvm->mutex);
tx_blocked_vif =
rcu_dereference_protected(mvm->csa_tx_blocked_vif,
lockdep_is_held(&mvm->mutex));
if (!tx_blocked_vif)
goto unlock;
mvmvif = iwl_mvm_vif_from_mac80211(tx_blocked_vif);
iwl_mvm_modify_all_sta_disable_tx(mvm, mvmvif, false);
RCU_INIT_POINTER(mvm->csa_tx_blocked_vif, NULL);
unlock:
mutex_unlock(&mvm->mutex);
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
u32 min_backoff;
BUILD_BUG_ON(ARRAY_SIZE(mvm->fw_id_to_mac_id) != IWL_MVM_STATION_COUNT);
hw = ieee80211_alloc_hw(sizeof(struct iwl_op_mode) +
sizeof(struct iwl_mvm),
&iwl_mvm_hw_ops);
if (!hw)
return NULL;
if (cfg->max_rx_agg_size)
hw->max_rx_aggregation_subframes = cfg->max_rx_agg_size;
if (cfg->max_tx_agg_size)
hw->max_tx_aggregation_subframes = cfg->max_tx_agg_size;
op_mode = hw->priv;
mvm = IWL_OP_MODE_GET_MVM(op_mode);
mvm->dev = trans->dev;
mvm->trans = trans;
mvm->cfg = cfg;
mvm->fw = fw;
mvm->hw = hw;
mvm->init_status = 0;
if (iwl_mvm_has_new_rx_api(mvm)) {
op_mode->ops = &iwl_mvm_ops_mq;
trans->rx_mpdu_cmd_hdr_size = sizeof(struct iwl_rx_mpdu_desc);
} else {
op_mode->ops = &iwl_mvm_ops;
trans->rx_mpdu_cmd_hdr_size =
sizeof(struct iwl_rx_mpdu_res_start);
if (WARN_ON(trans->num_rx_queues > 1))
goto out_free;
}
mvm->fw_restart = iwlwifi_mod_params.fw_restart ? -1 : 0;
if (!iwl_mvm_is_dqa_supported(mvm)) {
mvm->last_agg_queue = mvm->cfg->base_params->num_of_queues - 1;
if (mvm->cfg->base_params->num_of_queues == 16) {
mvm->aux_queue = 11;
mvm->first_agg_queue = 12;
BUILD_BUG_ON(BITS_PER_BYTE *
sizeof(mvm->hw_queue_to_mac80211[0]) < 12);
} else {
mvm->aux_queue = 15;
mvm->first_agg_queue = 16;
BUILD_BUG_ON(BITS_PER_BYTE *
sizeof(mvm->hw_queue_to_mac80211[0]) < 16);
}
} else {
mvm->aux_queue = IWL_MVM_DQA_AUX_QUEUE;
mvm->probe_queue = IWL_MVM_DQA_AP_PROBE_RESP_QUEUE;
mvm->p2p_dev_queue = IWL_MVM_DQA_P2P_DEVICE_QUEUE;
mvm->first_agg_queue = IWL_MVM_DQA_MIN_DATA_QUEUE;
mvm->last_agg_queue = IWL_MVM_DQA_MAX_DATA_QUEUE;
}
mvm->sf_state = SF_UNINIT;
if (iwl_mvm_has_new_tx_api(mvm))
mvm->cur_ucode = IWL_UCODE_REGULAR;
else
mvm->cur_ucode = IWL_UCODE_INIT;
mvm->drop_bcn_ap_mode = true;
mutex_init(&mvm->mutex);
mutex_init(&mvm->d0i3_suspend_mutex);
spin_lock_init(&mvm->async_handlers_lock);
INIT_LIST_HEAD(&mvm->time_event_list);
INIT_LIST_HEAD(&mvm->aux_roc_te_list);
INIT_LIST_HEAD(&mvm->async_handlers_list);
spin_lock_init(&mvm->time_event_lock);
spin_lock_init(&mvm->queue_info_lock);
INIT_WORK(&mvm->async_handlers_wk, iwl_mvm_async_handlers_wk);
INIT_WORK(&mvm->roc_done_wk, iwl_mvm_roc_done_wk);
INIT_WORK(&mvm->sta_drained_wk, iwl_mvm_sta_drained_wk);
INIT_WORK(&mvm->d0i3_exit_work, iwl_mvm_d0i3_exit_work);
INIT_DELAYED_WORK(&mvm->fw_dump_wk, iwl_mvm_fw_error_dump_wk);
INIT_DELAYED_WORK(&mvm->tdls_cs.dwork, iwl_mvm_tdls_ch_switch_work);
INIT_DELAYED_WORK(&mvm->scan_timeout_dwork, iwl_mvm_scan_timeout_wk);
INIT_WORK(&mvm->add_stream_wk, iwl_mvm_add_new_dqa_stream_wk);
spin_lock_init(&mvm->d0i3_tx_lock);
spin_lock_init(&mvm->refs_lock);
skb_queue_head_init(&mvm->d0i3_tx);
init_waitqueue_head(&mvm->d0i3_exit_waitq);
init_waitqueue_head(&mvm->rx_sync_waitq);
atomic_set(&mvm->queue_sync_counter, 0);
SET_IEEE80211_DEV(mvm->hw, mvm->trans->dev);
INIT_DELAYED_WORK(&mvm->cs_tx_unblock_dwork, iwl_mvm_tx_unblock_dwork);
trans_cfg.op_mode = op_mode;
trans_cfg.no_reclaim_cmds = no_reclaim_cmds;
trans_cfg.n_no_reclaim_cmds = ARRAY_SIZE(no_reclaim_cmds);
switch (iwlwifi_mod_params.amsdu_size) {
case IWL_AMSDU_DEF:
case IWL_AMSDU_4K:
trans_cfg.rx_buf_size = IWL_AMSDU_4K;
break;
case IWL_AMSDU_8K:
trans_cfg.rx_buf_size = IWL_AMSDU_8K;
break;
case IWL_AMSDU_12K:
trans_cfg.rx_buf_size = IWL_AMSDU_12K;
break;
default:
pr_err("%s: Unsupported amsdu_size: %d\n", KBUILD_MODNAME,
iwlwifi_mod_params.amsdu_size);
trans_cfg.rx_buf_size = IWL_AMSDU_4K;
}
if (mvm->cfg->mq_rx_supported)
trans_cfg.rx_buf_size = IWL_AMSDU_4K;
trans->wide_cmd_header = true;
trans_cfg.bc_table_dword = true;
trans_cfg.command_groups = iwl_mvm_groups;
trans_cfg.command_groups_size = ARRAY_SIZE(iwl_mvm_groups);
if (iwl_mvm_is_dqa_supported(mvm))
trans_cfg.cmd_queue = IWL_MVM_DQA_CMD_QUEUE;
else
trans_cfg.cmd_queue = IWL_MVM_CMD_QUEUE;
trans_cfg.cmd_fifo = IWL_MVM_TX_FIFO_CMD;
trans_cfg.scd_set_active = true;
trans_cfg.cb_data_offs = offsetof(struct ieee80211_tx_info,
driver_data[2]);
trans_cfg.sdio_adma_addr = fw->sdio_adma_addr;
trans_cfg.sw_csum_tx = IWL_MVM_SW_TX_CSUM_OFFLOAD;
trans_cfg.cmd_q_wdg_timeout =
iwl_mvm_get_wd_timeout(mvm, NULL, false, true);
snprintf(mvm->hw->wiphy->fw_version,
sizeof(mvm->hw->wiphy->fw_version),
"%s", fw->fw_version);
iwl_trans_configure(mvm->trans, &trans_cfg);
trans->rx_mpdu_cmd = REPLY_RX_MPDU_CMD;
trans->dbg_dest_tlv = mvm->fw->dbg_dest_tlv;
trans->dbg_dest_reg_num = mvm->fw->dbg_dest_reg_num;
memcpy(trans->dbg_conf_tlv, mvm->fw->dbg_conf_tlv,
sizeof(trans->dbg_conf_tlv));
trans->dbg_trigger_tlv = mvm->fw->dbg_trigger_tlv;
iwl_notification_wait_init(&mvm->notif_wait);
mvm->phy_db = iwl_phy_db_init(trans);
if (!mvm->phy_db) {
IWL_ERR(mvm, "Cannot init phy_db\n");
goto out_free;
}
IWL_INFO(mvm, "Detected %s, REV=0x%X\n",
mvm->cfg->name, mvm->trans->hw_rev);
if (iwlwifi_mod_params.nvm_file)
mvm->nvm_file_name = iwlwifi_mod_params.nvm_file;
else
IWL_DEBUG_EEPROM(mvm->trans->dev,
"working without external nvm file\n");
err = iwl_trans_start_hw(mvm->trans);
if (err)
goto out_free;
mutex_lock(&mvm->mutex);
iwl_mvm_ref(mvm, IWL_MVM_REF_INIT_UCODE);
err = iwl_run_init_mvm_ucode(mvm, true);
if (!iwlmvm_mod_params.init_dbg)
iwl_mvm_stop_device(mvm);
iwl_mvm_unref(mvm, IWL_MVM_REF_INIT_UCODE);
mutex_unlock(&mvm->mutex);
if (err < 0) {
IWL_ERR(mvm, "Failed to run INIT ucode: %d\n", err);
goto out_free;
}
scan_size = iwl_mvm_scan_size(mvm);
mvm->scan_cmd = kmalloc(scan_size, GFP_KERNEL);
if (!mvm->scan_cmd)
goto out_free;
mvm->last_ebs_successful = true;
err = iwl_mvm_mac_setup_register(mvm);
if (err)
goto out_free;
mvm->hw_registered = true;
min_backoff = calc_min_backoff(trans, cfg);
iwl_mvm_thermal_initialize(mvm, min_backoff);
err = iwl_mvm_dbgfs_register(mvm, dbgfs_dir);
if (err)
goto out_unregister;
if (!iwl_mvm_has_new_rx_stats_api(mvm))
memset(&mvm->rx_stats_v3, 0,
sizeof(struct mvm_statistics_rx_v3));
else
memset(&mvm->rx_stats, 0, sizeof(struct mvm_statistics_rx));
if (iwl_mvm_is_d0i3_supported(mvm))
iwl_trans_unref(mvm->trans);
iwl_mvm_tof_init(mvm);
return op_mode;
out_unregister:
if (iwlmvm_mod_params.init_dbg)
return op_mode;
ieee80211_unregister_hw(mvm->hw);
mvm->hw_registered = false;
iwl_mvm_leds_exit(mvm);
iwl_mvm_thermal_exit(mvm);
out_free:
flush_delayed_work(&mvm->fw_dump_wk);
if (iwlmvm_mod_params.init_dbg)
return op_mode;
iwl_phy_db_free(mvm->phy_db);
kfree(mvm->scan_cmd);
iwl_trans_op_mode_leave(trans);
ieee80211_free_hw(mvm->hw);
return NULL;
}
static void iwl_op_mode_mvm_stop(struct iwl_op_mode *op_mode)
{
struct iwl_mvm *mvm = IWL_OP_MODE_GET_MVM(op_mode);
int i;
if (iwl_mvm_is_d0i3_supported(mvm))
iwl_trans_ref(mvm->trans);
iwl_mvm_leds_exit(mvm);
iwl_mvm_thermal_exit(mvm);
if (mvm->init_status & IWL_MVM_INIT_STATUS_REG_HW_INIT_COMPLETE) {
ieee80211_unregister_hw(mvm->hw);
mvm->init_status &= ~IWL_MVM_INIT_STATUS_REG_HW_INIT_COMPLETE;
}
kfree(mvm->scan_cmd);
kfree(mvm->mcast_filter_cmd);
mvm->mcast_filter_cmd = NULL;
#if defined(CONFIG_PM_SLEEP) && defined(CONFIG_IWLWIFI_DEBUGFS)
kfree(mvm->d3_resume_sram);
#endif
iwl_trans_op_mode_leave(mvm->trans);
iwl_phy_db_free(mvm->phy_db);
mvm->phy_db = NULL;
kfree(mvm->nvm_data);
for (i = 0; i < NVM_MAX_NUM_SECTIONS; i++)
kfree(mvm->nvm_sections[i].data);
iwl_mvm_tof_clean(mvm);
mutex_destroy(&mvm->mutex);
mutex_destroy(&mvm->d0i3_suspend_mutex);
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
LIST_HEAD(local_list);
spin_lock_bh(&mvm->async_handlers_lock);
list_splice_init(&mvm->async_handlers_list, &local_list);
spin_unlock_bh(&mvm->async_handlers_lock);
list_for_each_entry_safe(entry, tmp, &local_list, list) {
if (entry->context == RX_HANDLER_ASYNC_LOCKED)
mutex_lock(&mvm->mutex);
entry->fn(mvm, &entry->rxb);
iwl_free_rxb(&entry->rxb);
list_del(&entry->list);
if (entry->context == RX_HANDLER_ASYNC_LOCKED)
mutex_unlock(&mvm->mutex);
kfree(entry);
}
}
static inline void iwl_mvm_rx_check_trigger(struct iwl_mvm *mvm,
struct iwl_rx_packet *pkt)
{
struct iwl_fw_dbg_trigger_tlv *trig;
struct iwl_fw_dbg_trigger_cmd *cmds_trig;
int i;
if (!iwl_fw_dbg_trigger_enabled(mvm->fw, FW_DBG_TRIGGER_FW_NOTIF))
return;
trig = iwl_fw_dbg_get_trigger(mvm->fw, FW_DBG_TRIGGER_FW_NOTIF);
cmds_trig = (void *)trig->data;
if (!iwl_fw_dbg_trigger_check_stop(mvm, NULL, trig))
return;
for (i = 0; i < ARRAY_SIZE(cmds_trig->cmds); i++) {
if (!cmds_trig->cmds[i].cmd_id)
break;
if (cmds_trig->cmds[i].cmd_id != pkt->hdr.cmd ||
cmds_trig->cmds[i].group_id != pkt->hdr.group_id)
continue;
iwl_mvm_fw_dbg_collect_trig(mvm, trig,
"CMD 0x%02x.%02x received",
pkt->hdr.group_id, pkt->hdr.cmd);
break;
}
}
static void iwl_mvm_rx_common(struct iwl_mvm *mvm,
struct iwl_rx_cmd_buffer *rxb,
struct iwl_rx_packet *pkt)
{
int i;
iwl_mvm_rx_check_trigger(mvm, pkt);
iwl_notification_wait_notify(&mvm->notif_wait, pkt);
for (i = 0; i < ARRAY_SIZE(iwl_mvm_rx_handlers); i++) {
const struct iwl_rx_handlers *rx_h = &iwl_mvm_rx_handlers[i];
struct iwl_async_handler_entry *entry;
if (rx_h->cmd_id != WIDE_ID(pkt->hdr.group_id, pkt->hdr.cmd))
continue;
if (rx_h->context == RX_HANDLER_SYNC) {
rx_h->fn(mvm, rxb);
return;
}
entry = kzalloc(sizeof(*entry), GFP_ATOMIC);
if (!entry)
return;
entry->rxb._page = rxb_steal_page(rxb);
entry->rxb._offset = rxb->_offset;
entry->rxb._rx_page_order = rxb->_rx_page_order;
entry->fn = rx_h->fn;
entry->context = rx_h->context;
spin_lock(&mvm->async_handlers_lock);
list_add_tail(&entry->list, &mvm->async_handlers_list);
spin_unlock(&mvm->async_handlers_lock);
schedule_work(&mvm->async_handlers_wk);
break;
}
}
static void iwl_mvm_rx(struct iwl_op_mode *op_mode,
struct napi_struct *napi,
struct iwl_rx_cmd_buffer *rxb)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
struct iwl_mvm *mvm = IWL_OP_MODE_GET_MVM(op_mode);
u16 cmd = WIDE_ID(pkt->hdr.group_id, pkt->hdr.cmd);
if (likely(cmd == WIDE_ID(LEGACY_GROUP, REPLY_RX_MPDU_CMD)))
iwl_mvm_rx_rx_mpdu(mvm, napi, rxb);
else if (cmd == WIDE_ID(LEGACY_GROUP, REPLY_RX_PHY_CMD))
iwl_mvm_rx_rx_phy_cmd(mvm, rxb);
else
iwl_mvm_rx_common(mvm, rxb, pkt);
}
static void iwl_mvm_rx_mq(struct iwl_op_mode *op_mode,
struct napi_struct *napi,
struct iwl_rx_cmd_buffer *rxb)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
struct iwl_mvm *mvm = IWL_OP_MODE_GET_MVM(op_mode);
u16 cmd = WIDE_ID(pkt->hdr.group_id, pkt->hdr.cmd);
if (likely(cmd == WIDE_ID(LEGACY_GROUP, REPLY_RX_MPDU_CMD)))
iwl_mvm_rx_mpdu_mq(mvm, napi, rxb, 0);
else if (unlikely(cmd == WIDE_ID(DATA_PATH_GROUP,
RX_QUEUES_NOTIFICATION)))
iwl_mvm_rx_queue_notif(mvm, rxb, 0);
else if (cmd == WIDE_ID(LEGACY_GROUP, FRAME_RELEASE))
iwl_mvm_rx_frame_release(mvm, napi, rxb, 0);
else
iwl_mvm_rx_common(mvm, rxb, pkt);
}
void iwl_mvm_stop_mac_queues(struct iwl_mvm *mvm, unsigned long mq)
{
int q;
if (WARN_ON_ONCE(!mq))
return;
for_each_set_bit(q, &mq, IEEE80211_MAX_QUEUES) {
if (atomic_inc_return(&mvm->mac80211_queue_stop_count[q]) > 1) {
IWL_DEBUG_TX_QUEUES(mvm,
"mac80211 %d already stopped\n", q);
continue;
}
ieee80211_stop_queue(mvm->hw, q);
}
}
static void iwl_mvm_async_cb(struct iwl_op_mode *op_mode,
const struct iwl_device_cmd *cmd)
{
struct iwl_mvm *mvm = IWL_OP_MODE_GET_MVM(op_mode);
iwl_trans_block_txq_ptrs(mvm->trans, false);
}
static void iwl_mvm_stop_sw_queue(struct iwl_op_mode *op_mode, int hw_queue)
{
struct iwl_mvm *mvm = IWL_OP_MODE_GET_MVM(op_mode);
unsigned long mq;
spin_lock_bh(&mvm->queue_info_lock);
mq = mvm->hw_queue_to_mac80211[hw_queue];
spin_unlock_bh(&mvm->queue_info_lock);
iwl_mvm_stop_mac_queues(mvm, mq);
}
void iwl_mvm_start_mac_queues(struct iwl_mvm *mvm, unsigned long mq)
{
int q;
if (WARN_ON_ONCE(!mq))
return;
for_each_set_bit(q, &mq, IEEE80211_MAX_QUEUES) {
if (atomic_dec_return(&mvm->mac80211_queue_stop_count[q]) > 0) {
IWL_DEBUG_TX_QUEUES(mvm,
"mac80211 %d still stopped\n", q);
continue;
}
ieee80211_wake_queue(mvm->hw, q);
}
}
static void iwl_mvm_wake_sw_queue(struct iwl_op_mode *op_mode, int hw_queue)
{
struct iwl_mvm *mvm = IWL_OP_MODE_GET_MVM(op_mode);
unsigned long mq;
spin_lock_bh(&mvm->queue_info_lock);
mq = mvm->hw_queue_to_mac80211[hw_queue];
spin_unlock_bh(&mvm->queue_info_lock);
iwl_mvm_start_mac_queues(mvm, mq);
}
static void iwl_mvm_set_rfkill_state(struct iwl_mvm *mvm)
{
bool state = iwl_mvm_is_radio_killed(mvm);
if (state)
wake_up(&mvm->rx_sync_waitq);
wiphy_rfkill_set_hw_state(mvm->hw->wiphy, state);
}
void iwl_mvm_set_hw_ctkill_state(struct iwl_mvm *mvm, bool state)
{
if (state)
set_bit(IWL_MVM_STATUS_HW_CTKILL, &mvm->status);
else
clear_bit(IWL_MVM_STATUS_HW_CTKILL, &mvm->status);
iwl_mvm_set_rfkill_state(mvm);
}
static bool iwl_mvm_set_hw_rfkill_state(struct iwl_op_mode *op_mode, bool state)
{
struct iwl_mvm *mvm = IWL_OP_MODE_GET_MVM(op_mode);
bool calibrating = ACCESS_ONCE(mvm->calibrating);
if (state)
set_bit(IWL_MVM_STATUS_HW_RFKILL, &mvm->status);
else
clear_bit(IWL_MVM_STATUS_HW_RFKILL, &mvm->status);
iwl_mvm_set_rfkill_state(mvm);
if (calibrating)
iwl_abort_notification_waits(&mvm->notif_wait);
return state && (mvm->cur_ucode != IWL_UCODE_INIT || calibrating);
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
static void iwl_mvm_fw_error_dump_wk(struct work_struct *work)
{
struct iwl_mvm *mvm =
container_of(work, struct iwl_mvm, fw_dump_wk.work);
if (iwl_mvm_ref_sync(mvm, IWL_MVM_REF_FW_DBG_COLLECT))
return;
mutex_lock(&mvm->mutex);
if (mvm->cfg->device_family == IWL_DEVICE_FAMILY_7000) {
iwl_set_bits_prph(mvm->trans, MON_BUFF_SAMPLE_CTL, 0x100);
iwl_mvm_fw_error_dump(mvm);
if (!test_bit(STATUS_FW_ERROR, &mvm->trans->status) &&
mvm->fw->dbg_dest_tlv) {
iwl_clear_bits_prph(mvm->trans,
MON_BUFF_SAMPLE_CTL, 0x100);
iwl_clear_bits_prph(mvm->trans,
MON_BUFF_SAMPLE_CTL, 0x1);
iwl_set_bits_prph(mvm->trans, MON_BUFF_SAMPLE_CTL, 0x1);
}
} else {
u32 in_sample = iwl_read_prph(mvm->trans, DBGC_IN_SAMPLE);
u32 out_ctrl = iwl_read_prph(mvm->trans, DBGC_OUT_CTRL);
iwl_write_prph(mvm->trans, DBGC_IN_SAMPLE, 0);
udelay(100);
iwl_write_prph(mvm->trans, DBGC_OUT_CTRL, 0);
udelay(500);
iwl_mvm_fw_error_dump(mvm);
if (!test_bit(STATUS_FW_ERROR, &mvm->trans->status) &&
mvm->fw->dbg_dest_tlv) {
iwl_write_prph(mvm->trans, DBGC_IN_SAMPLE, in_sample);
iwl_write_prph(mvm->trans, DBGC_OUT_CTRL, out_ctrl);
}
}
mutex_unlock(&mvm->mutex);
iwl_mvm_unref(mvm, IWL_MVM_REF_FW_DBG_COLLECT);
}
void iwl_mvm_nic_restart(struct iwl_mvm *mvm, bool fw_error)
{
iwl_abort_notification_waits(&mvm->notif_wait);
iwl_mvm_report_scan_aborted(mvm);
if (!mvm->fw_restart && fw_error) {
iwl_mvm_fw_dbg_collect_desc(mvm, &iwl_mvm_dump_desc_assert,
NULL);
} else if (test_bit(IWL_MVM_STATUS_IN_HW_RESTART, &mvm->status)) {
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
} else if (mvm->cur_ucode == IWL_UCODE_REGULAR &&
mvm->hw_registered) {
iwl_mvm_ref(mvm, IWL_MVM_REF_UCODE_DOWN);
if (fw_error && mvm->fw_restart > 0)
mvm->fw_restart--;
set_bit(IWL_MVM_STATUS_HW_RESTART_REQUESTED, &mvm->status);
ieee80211_restart_hw(mvm->hw);
}
}
static void iwl_mvm_nic_error(struct iwl_op_mode *op_mode)
{
struct iwl_mvm *mvm = IWL_OP_MODE_GET_MVM(op_mode);
iwl_mvm_dump_nic_error_log(mvm);
iwl_mvm_nic_restart(mvm, true);
}
static void iwl_mvm_cmd_queue_full(struct iwl_op_mode *op_mode)
{
struct iwl_mvm *mvm = IWL_OP_MODE_GET_MVM(op_mode);
WARN_ON(1);
iwl_mvm_nic_restart(mvm, true);
}
static bool iwl_mvm_disallow_offloading(struct iwl_mvm *mvm,
struct ieee80211_vif *vif,
struct iwl_d0i3_iter_data *iter_data)
{
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
struct iwl_mvm_sta *mvmsta;
u32 available_tids = 0;
u8 tid;
if (WARN_ON(vif->type != NL80211_IFTYPE_STATION ||
mvmvif->ap_sta_id == IWL_MVM_INVALID_STA))
return false;
mvmsta = iwl_mvm_sta_from_staid_rcu(mvm, mvmvif->ap_sta_id);
if (!mvmsta)
return false;
spin_lock_bh(&mvmsta->lock);
for (tid = 0; tid < IWL_MAX_TID_COUNT; tid++) {
struct iwl_mvm_tid_data *tid_data = &mvmsta->tid_data[tid];
if (iwl_mvm_tid_queued(mvm, tid_data))
continue;
if (tid_data->state != IWL_AGG_OFF)
continue;
available_tids |= BIT(tid);
}
spin_unlock_bh(&mvmsta->lock);
if (!available_tids)
return true;
iter_data->offloading_tid = ffs(available_tids) - 1;
return false;
}
static void iwl_mvm_enter_d0i3_iterator(void *_data, u8 *mac,
struct ieee80211_vif *vif)
{
struct iwl_d0i3_iter_data *data = _data;
struct iwl_mvm *mvm = data->mvm;
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
u32 flags = CMD_ASYNC | CMD_HIGH_PRIO | CMD_SEND_IN_IDLE;
IWL_DEBUG_RPM(mvm, "entering D0i3 - vif %pM\n", vif->addr);
if (vif->type != NL80211_IFTYPE_STATION ||
!vif->bss_conf.assoc)
return;
if (iwl_mvm_disallow_offloading(mvm, vif, data))
data->disable_offloading = true;
iwl_mvm_update_d0i3_power_mode(mvm, vif, true, flags);
iwl_mvm_send_proto_offload(mvm, vif, data->disable_offloading,
false, flags);
data->ap_sta_id = mvmvif->ap_sta_id;
data->vif_count++;
data->connected_vif = vif;
}
static void iwl_mvm_set_wowlan_data(struct iwl_mvm *mvm,
struct iwl_wowlan_config_cmd *cmd,
struct iwl_d0i3_iter_data *iter_data)
{
struct ieee80211_sta *ap_sta;
struct iwl_mvm_sta *mvm_ap_sta;
if (iter_data->ap_sta_id == IWL_MVM_INVALID_STA)
return;
rcu_read_lock();
ap_sta = rcu_dereference(mvm->fw_id_to_mac_id[iter_data->ap_sta_id]);
if (IS_ERR_OR_NULL(ap_sta))
goto out;
mvm_ap_sta = iwl_mvm_sta_from_mac80211(ap_sta);
cmd->is_11n_connection = ap_sta->ht_cap.ht_supported;
cmd->offloading_tid = iter_data->offloading_tid;
cmd->flags = ENABLE_L3_FILTERING | ENABLE_NBNS_FILTERING |
ENABLE_DHCP_FILTERING | ENABLE_STORE_BEACON;
iwl_mvm_set_wowlan_qos_seq(mvm_ap_sta, cmd);
out:
rcu_read_unlock();
}
int iwl_mvm_enter_d0i3(struct iwl_op_mode *op_mode)
{
struct iwl_mvm *mvm = IWL_OP_MODE_GET_MVM(op_mode);
u32 flags = CMD_ASYNC | CMD_HIGH_PRIO | CMD_SEND_IN_IDLE;
int ret;
struct iwl_d0i3_iter_data d0i3_iter_data = {
.mvm = mvm,
};
struct iwl_wowlan_config_cmd wowlan_config_cmd = {
.wakeup_filter = cpu_to_le32(IWL_WOWLAN_WAKEUP_RX_FRAME |
IWL_WOWLAN_WAKEUP_BEACON_MISS |
IWL_WOWLAN_WAKEUP_LINK_CHANGE),
};
struct iwl_d3_manager_config d3_cfg_cmd = {
.min_sleep_time = cpu_to_le32(1000),
.wakeup_flags = cpu_to_le32(IWL_WAKEUP_D3_CONFIG_FW_ERROR),
};
IWL_DEBUG_RPM(mvm, "MVM entering D0i3\n");
if (WARN_ON_ONCE(mvm->cur_ucode != IWL_UCODE_REGULAR))
return -EINVAL;
set_bit(IWL_MVM_STATUS_IN_D0I3, &mvm->status);
if (iwl_mvm_ref_taken(mvm)) {
IWL_DEBUG_RPM(mvm->trans, "abort d0i3 due to taken ref\n");
clear_bit(IWL_MVM_STATUS_IN_D0I3, &mvm->status);
wake_up(&mvm->d0i3_exit_waitq);
return 1;
}
ieee80211_iterate_active_interfaces_atomic(mvm->hw,
IEEE80211_IFACE_ITER_NORMAL,
iwl_mvm_enter_d0i3_iterator,
&d0i3_iter_data);
if (d0i3_iter_data.vif_count == 1) {
mvm->d0i3_ap_sta_id = d0i3_iter_data.ap_sta_id;
mvm->d0i3_offloading = !d0i3_iter_data.disable_offloading;
} else {
WARN_ON_ONCE(d0i3_iter_data.vif_count > 1);
mvm->d0i3_ap_sta_id = IWL_MVM_INVALID_STA;
mvm->d0i3_offloading = false;
}
synchronize_net();
if (iwl_mvm_has_new_tx_api(mvm)) {
WARN_ONCE(1, "d0i3: Need to implement flush TX queue\n");
} else {
ret = iwl_mvm_flush_tx_path(mvm, iwl_mvm_flushable_queues(mvm),
flags);
if (ret)
return ret;
}
if (mvm->d0i3_ap_sta_id != IWL_MVM_INVALID_STA) {
if (!fw_has_capa(&mvm->fw->ucode_capa,
IWL_UCODE_TLV_CAPA_BEACON_STORING))
wowlan_config_cmd.wakeup_filter |=
cpu_to_le32(IWL_WOWLAN_WAKEUP_BCN_FILTERING);
iwl_mvm_wowlan_config_key_params(mvm,
d0i3_iter_data.connected_vif,
true, flags);
iwl_mvm_set_wowlan_data(mvm, &wowlan_config_cmd,
&d0i3_iter_data);
ret = iwl_mvm_send_cmd_pdu(mvm, WOWLAN_CONFIGURATION, flags,
sizeof(wowlan_config_cmd),
&wowlan_config_cmd);
if (ret)
return ret;
}
return iwl_mvm_send_cmd_pdu(mvm, D3_CONFIG_CMD,
flags | CMD_MAKE_TRANS_IDLE,
sizeof(d3_cfg_cmd), &d3_cfg_cmd);
}
static void iwl_mvm_exit_d0i3_iterator(void *_data, u8 *mac,
struct ieee80211_vif *vif)
{
struct iwl_mvm *mvm = _data;
u32 flags = CMD_ASYNC | CMD_HIGH_PRIO;
IWL_DEBUG_RPM(mvm, "exiting D0i3 - vif %pM\n", vif->addr);
if (vif->type != NL80211_IFTYPE_STATION ||
!vif->bss_conf.assoc)
return;
iwl_mvm_update_d0i3_power_mode(mvm, vif, false, flags);
}
static void iwl_mvm_d0i3_exit_work_iter(void *_data, u8 *mac,
struct ieee80211_vif *vif)
{
struct iwl_mvm_d0i3_exit_work_iter_data *data = _data;
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
u32 reasons = data->wakeup_reasons;
if (vif->type != NL80211_IFTYPE_STATION || !vif->bss_conf.assoc ||
data->mvm->d0i3_ap_sta_id != mvmvif->ap_sta_id)
return;
if (reasons & IWL_WOWLAN_WAKEUP_BY_DISCONNECTION_ON_DEAUTH)
iwl_mvm_connection_loss(data->mvm, vif, "D0i3");
else if (reasons & IWL_WOWLAN_WAKEUP_BY_DISCONNECTION_ON_MISSED_BEACON)
ieee80211_beacon_loss(vif);
else
iwl_mvm_d0i3_update_keys(data->mvm, vif, data->status);
}
void iwl_mvm_d0i3_enable_tx(struct iwl_mvm *mvm, __le16 *qos_seq)
{
struct ieee80211_sta *sta = NULL;
struct iwl_mvm_sta *mvm_ap_sta;
int i;
bool wake_queues = false;
lockdep_assert_held(&mvm->mutex);
spin_lock_bh(&mvm->d0i3_tx_lock);
if (mvm->d0i3_ap_sta_id == IWL_MVM_INVALID_STA)
goto out;
IWL_DEBUG_RPM(mvm, "re-enqueue packets\n");
sta = rcu_dereference_protected(
mvm->fw_id_to_mac_id[mvm->d0i3_ap_sta_id],
lockdep_is_held(&mvm->mutex));
if (IS_ERR_OR_NULL(sta)) {
sta = NULL;
goto out;
}
if (mvm->d0i3_offloading && qos_seq) {
mvm_ap_sta = iwl_mvm_sta_from_mac80211(sta);
for (i = 0; i < IWL_MAX_TID_COUNT; i++) {
u16 seq = le16_to_cpu(qos_seq[i]);
seq += 0x10;
mvm_ap_sta->tid_data[i].seq_number = seq;
}
}
out:
while (!skb_queue_empty(&mvm->d0i3_tx)) {
struct sk_buff *skb = __skb_dequeue(&mvm->d0i3_tx);
if (!sta || iwl_mvm_tx_skb(mvm, skb, sta))
ieee80211_free_txskb(mvm->hw, skb);
wake_queues = true;
}
clear_bit(IWL_MVM_STATUS_IN_D0I3, &mvm->status);
wake_up(&mvm->d0i3_exit_waitq);
mvm->d0i3_ap_sta_id = IWL_MVM_INVALID_STA;
if (wake_queues)
ieee80211_wake_queues(mvm->hw);
spin_unlock_bh(&mvm->d0i3_tx_lock);
}
static void iwl_mvm_d0i3_exit_work(struct work_struct *wk)
{
struct iwl_mvm *mvm = container_of(wk, struct iwl_mvm, d0i3_exit_work);
struct iwl_host_cmd get_status_cmd = {
.id = WOWLAN_GET_STATUSES,
.flags = CMD_HIGH_PRIO | CMD_WANT_SKB,
};
struct iwl_mvm_d0i3_exit_work_iter_data iter_data = {
.mvm = mvm,
};
struct iwl_wowlan_status *status;
int ret;
u32 wakeup_reasons = 0;
__le16 *qos_seq = NULL;
mutex_lock(&mvm->mutex);
ret = iwl_mvm_send_cmd(mvm, &get_status_cmd);
if (ret)
goto out;
status = (void *)get_status_cmd.resp_pkt->data;
wakeup_reasons = le32_to_cpu(status->wakeup_reasons);
qos_seq = status->qos_seq_ctr;
IWL_DEBUG_RPM(mvm, "wakeup reasons: 0x%x\n", wakeup_reasons);
iter_data.wakeup_reasons = wakeup_reasons;
iter_data.status = status;
ieee80211_iterate_active_interfaces(mvm->hw,
IEEE80211_IFACE_ITER_NORMAL,
iwl_mvm_d0i3_exit_work_iter,
&iter_data);
out:
iwl_mvm_d0i3_enable_tx(mvm, qos_seq);
IWL_DEBUG_INFO(mvm, "d0i3 exit completed (wakeup reasons: 0x%x)\n",
wakeup_reasons);
if (get_status_cmd.resp_pkt)
iwl_free_resp(&get_status_cmd);
iwl_mvm_update_changed_regdom(mvm);
iwl_mvm_unref(mvm, IWL_MVM_REF_EXIT_WORK);
mutex_unlock(&mvm->mutex);
}
int _iwl_mvm_exit_d0i3(struct iwl_mvm *mvm)
{
u32 flags = CMD_ASYNC | CMD_HIGH_PRIO | CMD_SEND_IN_IDLE |
CMD_WAKE_UP_TRANS;
int ret;
IWL_DEBUG_RPM(mvm, "MVM exiting D0i3\n");
if (WARN_ON_ONCE(mvm->cur_ucode != IWL_UCODE_REGULAR))
return -EINVAL;
mutex_lock(&mvm->d0i3_suspend_mutex);
if (test_bit(D0I3_DEFER_WAKEUP, &mvm->d0i3_suspend_flags)) {
IWL_DEBUG_RPM(mvm, "Deferring d0i3 exit until resume\n");
__set_bit(D0I3_PENDING_WAKEUP, &mvm->d0i3_suspend_flags);
mutex_unlock(&mvm->d0i3_suspend_mutex);
return 0;
}
mutex_unlock(&mvm->d0i3_suspend_mutex);
ret = iwl_mvm_send_cmd_pdu(mvm, D0I3_END_CMD, flags, 0, NULL);
if (ret)
goto out;
ieee80211_iterate_active_interfaces_atomic(mvm->hw,
IEEE80211_IFACE_ITER_NORMAL,
iwl_mvm_exit_d0i3_iterator,
mvm);
out:
schedule_work(&mvm->d0i3_exit_work);
return ret;
}
int iwl_mvm_exit_d0i3(struct iwl_op_mode *op_mode)
{
struct iwl_mvm *mvm = IWL_OP_MODE_GET_MVM(op_mode);
iwl_mvm_ref(mvm, IWL_MVM_REF_EXIT_WORK);
return _iwl_mvm_exit_d0i3(mvm);
}
static void iwl_mvm_rx_mq_rss(struct iwl_op_mode *op_mode,
struct napi_struct *napi,
struct iwl_rx_cmd_buffer *rxb,
unsigned int queue)
{
struct iwl_mvm *mvm = IWL_OP_MODE_GET_MVM(op_mode);
struct iwl_rx_packet *pkt = rxb_addr(rxb);
u16 cmd = WIDE_ID(pkt->hdr.group_id, pkt->hdr.cmd);
if (unlikely(cmd == WIDE_ID(LEGACY_GROUP, FRAME_RELEASE)))
iwl_mvm_rx_frame_release(mvm, napi, rxb, queue);
else if (unlikely(cmd == WIDE_ID(DATA_PATH_GROUP,
RX_QUEUES_NOTIFICATION)))
iwl_mvm_rx_queue_notif(mvm, rxb, queue);
else if (likely(cmd == WIDE_ID(LEGACY_GROUP, REPLY_RX_MPDU_CMD)))
iwl_mvm_rx_mpdu_mq(mvm, napi, rxb, queue);
}
