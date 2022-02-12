void iwl_mvm_te_clear_data(struct iwl_mvm *mvm,
struct iwl_mvm_time_event_data *te_data)
{
lockdep_assert_held(&mvm->time_event_lock);
if (te_data->id == TE_MAX)
return;
list_del(&te_data->list);
te_data->running = false;
te_data->uid = 0;
te_data->id = TE_MAX;
te_data->vif = NULL;
}
void iwl_mvm_roc_done_wk(struct work_struct *wk)
{
struct iwl_mvm *mvm = container_of(wk, struct iwl_mvm, roc_done_wk);
synchronize_net();
iwl_mvm_flush_tx_path(mvm, BIT(IWL_OFFCHANNEL_QUEUE), false);
}
static void iwl_mvm_roc_finished(struct iwl_mvm *mvm)
{
clear_bit(IWL_MVM_STATUS_ROC_RUNNING, &mvm->status);
schedule_work(&mvm->roc_done_wk);
}
static void iwl_mvm_te_handle_notif(struct iwl_mvm *mvm,
struct iwl_mvm_time_event_data *te_data,
struct iwl_time_event_notif *notif)
{
lockdep_assert_held(&mvm->time_event_lock);
IWL_DEBUG_TE(mvm, "Handle time event notif - UID = 0x%x action %d\n",
le32_to_cpu(notif->unique_id),
le32_to_cpu(notif->action));
WARN_ONCE(!le32_to_cpu(notif->status),
"Failed to schedule time event\n");
if (le32_to_cpu(notif->action) == TE_NOTIF_HOST_END) {
IWL_DEBUG_TE(mvm,
"TE ended - current time %lu, estimated end %lu\n",
jiffies, te_data->end_jiffies);
if (te_data->vif->type == NL80211_IFTYPE_P2P_DEVICE) {
ieee80211_remain_on_channel_expired(mvm->hw);
iwl_mvm_roc_finished(mvm);
}
if (te_data->vif->type == NL80211_IFTYPE_STATION &&
(!te_data->vif->bss_conf.assoc ||
!te_data->vif->bss_conf.dtim_period)) {
IWL_ERR(mvm,
"No assocation and the time event is over already...\n");
ieee80211_connection_loss(te_data->vif);
}
iwl_mvm_te_clear_data(mvm, te_data);
} else if (le32_to_cpu(notif->action) == TE_NOTIF_HOST_START) {
te_data->running = true;
te_data->end_jiffies = jiffies +
TU_TO_JIFFIES(te_data->duration);
if (te_data->vif->type == NL80211_IFTYPE_P2P_DEVICE) {
set_bit(IWL_MVM_STATUS_ROC_RUNNING, &mvm->status);
ieee80211_ready_on_channel(mvm->hw);
}
} else {
IWL_WARN(mvm, "Got TE with unknown action\n");
}
}
int iwl_mvm_rx_time_event_notif(struct iwl_mvm *mvm,
struct iwl_rx_cmd_buffer *rxb,
struct iwl_device_cmd *cmd)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
struct iwl_time_event_notif *notif = (void *)pkt->data;
struct iwl_mvm_time_event_data *te_data, *tmp;
IWL_DEBUG_TE(mvm, "Time event notification - UID = 0x%x action %d\n",
le32_to_cpu(notif->unique_id),
le32_to_cpu(notif->action));
spin_lock_bh(&mvm->time_event_lock);
list_for_each_entry_safe(te_data, tmp, &mvm->time_event_list, list) {
if (le32_to_cpu(notif->unique_id) == te_data->uid)
iwl_mvm_te_handle_notif(mvm, te_data, notif);
}
spin_unlock_bh(&mvm->time_event_lock);
return 0;
}
static bool iwl_mvm_time_event_response(struct iwl_notif_wait_data *notif_wait,
struct iwl_rx_packet *pkt, void *data)
{
struct iwl_mvm *mvm =
container_of(notif_wait, struct iwl_mvm, notif_wait);
struct iwl_mvm_time_event_data *te_data = data;
struct iwl_time_event_resp *resp;
int resp_len = le32_to_cpu(pkt->len_n_flags) & FH_RSCSR_FRAME_SIZE_MSK;
if (WARN_ON(pkt->hdr.cmd != TIME_EVENT_CMD))
return true;
if (WARN_ON_ONCE(resp_len != sizeof(pkt->hdr) + sizeof(*resp))) {
IWL_ERR(mvm, "Invalid TIME_EVENT_CMD response\n");
return true;
}
resp = (void *)pkt->data;
if (WARN_ON_ONCE(le32_to_cpu(resp->id) != te_data->id))
return false;
te_data->uid = le32_to_cpu(resp->unique_id);
IWL_DEBUG_TE(mvm, "TIME_EVENT_CMD response - UID = 0x%x\n",
te_data->uid);
return true;
}
static int iwl_mvm_time_event_send_add(struct iwl_mvm *mvm,
struct ieee80211_vif *vif,
struct iwl_mvm_time_event_data *te_data,
struct iwl_time_event_cmd *te_cmd)
{
static const u8 time_event_response[] = { TIME_EVENT_CMD };
struct iwl_notification_wait wait_time_event;
int ret;
lockdep_assert_held(&mvm->mutex);
IWL_DEBUG_TE(mvm, "Add new TE, duration %d TU\n",
le32_to_cpu(te_cmd->duration));
spin_lock_bh(&mvm->time_event_lock);
if (WARN_ON(te_data->id != TE_MAX)) {
spin_unlock_bh(&mvm->time_event_lock);
return -EIO;
}
te_data->vif = vif;
te_data->duration = le32_to_cpu(te_cmd->duration);
te_data->id = le32_to_cpu(te_cmd->id);
list_add_tail(&te_data->list, &mvm->time_event_list);
spin_unlock_bh(&mvm->time_event_lock);
iwl_init_notification_wait(&mvm->notif_wait, &wait_time_event,
time_event_response,
ARRAY_SIZE(time_event_response),
iwl_mvm_time_event_response, te_data);
ret = iwl_mvm_send_cmd_pdu(mvm, TIME_EVENT_CMD, CMD_SYNC,
sizeof(*te_cmd), te_cmd);
if (ret) {
IWL_ERR(mvm, "Couldn't send TIME_EVENT_CMD: %d\n", ret);
iwl_remove_notification(&mvm->notif_wait, &wait_time_event);
goto out_clear_te;
}
ret = iwl_wait_notification(&mvm->notif_wait, &wait_time_event, 1);
WARN_ON_ONCE(ret);
if (ret) {
out_clear_te:
spin_lock_bh(&mvm->time_event_lock);
iwl_mvm_te_clear_data(mvm, te_data);
spin_unlock_bh(&mvm->time_event_lock);
}
return ret;
}
void iwl_mvm_protect_session(struct iwl_mvm *mvm,
struct ieee80211_vif *vif,
u32 duration, u32 min_duration)
{
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
struct iwl_mvm_time_event_data *te_data = &mvmvif->time_event_data;
struct iwl_time_event_cmd time_cmd = {};
lockdep_assert_held(&mvm->mutex);
if (te_data->running &&
time_after(te_data->end_jiffies,
jiffies + TU_TO_JIFFIES(min_duration))) {
IWL_DEBUG_TE(mvm, "We have enough time in the current TE: %u\n",
jiffies_to_msecs(te_data->end_jiffies - jiffies));
return;
}
if (te_data->running) {
IWL_DEBUG_TE(mvm, "extend 0x%x: only %u ms left\n",
te_data->uid,
jiffies_to_msecs(te_data->end_jiffies - jiffies));
iwl_mvm_stop_session_protection(mvm, vif);
}
time_cmd.action = cpu_to_le32(FW_CTXT_ACTION_ADD);
time_cmd.id_and_color =
cpu_to_le32(FW_CMD_ID_AND_COLOR(mvmvif->id, mvmvif->color));
time_cmd.id = cpu_to_le32(TE_BSS_STA_AGGRESSIVE_ASSOC);
time_cmd.apply_time =
cpu_to_le32(iwl_read_prph(mvm->trans, DEVICE_SYSTEM_TIME_REG));
time_cmd.dep_policy = TE_INDEPENDENT;
time_cmd.is_present = cpu_to_le32(1);
time_cmd.max_frags = cpu_to_le32(TE_FRAG_NONE);
time_cmd.max_delay = cpu_to_le32(500);
time_cmd.interval = cpu_to_le32(1);
time_cmd.interval_reciprocal = cpu_to_le32(iwl_mvm_reciprocal(1));
time_cmd.duration = cpu_to_le32(duration);
time_cmd.repeat = cpu_to_le32(1);
time_cmd.notify = cpu_to_le32(TE_NOTIF_HOST_START | TE_NOTIF_HOST_END);
iwl_mvm_time_event_send_add(mvm, vif, te_data, &time_cmd);
}
void iwl_mvm_remove_time_event(struct iwl_mvm *mvm,
struct iwl_mvm_vif *mvmvif,
struct iwl_mvm_time_event_data *te_data)
{
struct iwl_time_event_cmd time_cmd = {};
u32 id, uid;
int ret;
spin_lock_bh(&mvm->time_event_lock);
uid = te_data->uid;
id = te_data->id;
iwl_mvm_te_clear_data(mvm, te_data);
spin_unlock_bh(&mvm->time_event_lock);
if (id == TE_MAX) {
IWL_DEBUG_TE(mvm, "TE 0x%x has already ended\n", uid);
return;
}
time_cmd.id = cpu_to_le32(uid);
time_cmd.action = cpu_to_le32(FW_CTXT_ACTION_REMOVE);
time_cmd.id_and_color =
cpu_to_le32(FW_CMD_ID_AND_COLOR(mvmvif->id, mvmvif->color));
IWL_DEBUG_TE(mvm, "Removing TE 0x%x\n", le32_to_cpu(time_cmd.id));
ret = iwl_mvm_send_cmd_pdu(mvm, TIME_EVENT_CMD, CMD_SYNC,
sizeof(time_cmd), &time_cmd);
if (WARN_ON(ret))
return;
}
void iwl_mvm_stop_session_protection(struct iwl_mvm *mvm,
struct ieee80211_vif *vif)
{
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
struct iwl_mvm_time_event_data *te_data = &mvmvif->time_event_data;
lockdep_assert_held(&mvm->mutex);
iwl_mvm_remove_time_event(mvm, mvmvif, te_data);
}
int iwl_mvm_start_p2p_roc(struct iwl_mvm *mvm, struct ieee80211_vif *vif,
int duration)
{
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
struct iwl_mvm_time_event_data *te_data = &mvmvif->time_event_data;
struct iwl_time_event_cmd time_cmd = {};
lockdep_assert_held(&mvm->mutex);
if (te_data->running) {
IWL_WARN(mvm, "P2P_DEVICE remain on channel already running\n");
return -EBUSY;
}
flush_work(&mvm->roc_done_wk);
time_cmd.action = cpu_to_le32(FW_CTXT_ACTION_ADD);
time_cmd.id_and_color =
cpu_to_le32(FW_CMD_ID_AND_COLOR(mvmvif->id, mvmvif->color));
time_cmd.id = cpu_to_le32(IWL_MVM_ROC_TE_TYPE);
time_cmd.apply_time = cpu_to_le32(0);
time_cmd.dep_policy = cpu_to_le32(TE_INDEPENDENT);
time_cmd.is_present = cpu_to_le32(1);
time_cmd.interval = cpu_to_le32(1);
time_cmd.max_frags = cpu_to_le32(MSEC_TO_TU(duration)/20);
time_cmd.max_delay = cpu_to_le32(MSEC_TO_TU(duration/2));
time_cmd.duration = cpu_to_le32(MSEC_TO_TU(duration));
time_cmd.repeat = cpu_to_le32(1);
time_cmd.notify = cpu_to_le32(TE_NOTIF_HOST_START | TE_NOTIF_HOST_END);
return iwl_mvm_time_event_send_add(mvm, vif, te_data, &time_cmd);
}
void iwl_mvm_stop_p2p_roc(struct iwl_mvm *mvm)
{
struct iwl_mvm_vif *mvmvif;
struct iwl_mvm_time_event_data *te_data;
lockdep_assert_held(&mvm->mutex);
mvmvif = NULL;
spin_lock_bh(&mvm->time_event_lock);
list_for_each_entry(te_data, &mvm->time_event_list, list) {
if (te_data->vif->type == NL80211_IFTYPE_P2P_DEVICE) {
mvmvif = iwl_mvm_vif_from_mac80211(te_data->vif);
break;
}
}
spin_unlock_bh(&mvm->time_event_lock);
if (!mvmvif) {
IWL_WARN(mvm, "P2P_DEVICE no remain on channel event\n");
return;
}
iwl_mvm_remove_time_event(mvm, mvmvif, te_data);
iwl_mvm_roc_finished(mvm);
}
