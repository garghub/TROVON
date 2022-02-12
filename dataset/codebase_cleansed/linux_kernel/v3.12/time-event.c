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
iwl_mvm_flush_tx_path(mvm, BIT(IWL_MVM_OFFCHANNEL_QUEUE), false);
}
static void iwl_mvm_roc_finished(struct iwl_mvm *mvm)
{
clear_bit(IWL_MVM_STATUS_ROC_RUNNING, &mvm->status);
schedule_work(&mvm->roc_done_wk);
}
static bool iwl_mvm_te_check_disconnect(struct iwl_mvm *mvm,
struct ieee80211_vif *vif,
const char *errmsg)
{
if (vif->type != NL80211_IFTYPE_STATION)
return false;
if (vif->bss_conf.assoc && vif->bss_conf.dtim_period)
return false;
if (errmsg)
IWL_ERR(mvm, "%s\n", errmsg);
ieee80211_connection_loss(vif);
return true;
}
static void iwl_mvm_te_handle_notif(struct iwl_mvm *mvm,
struct iwl_mvm_time_event_data *te_data,
struct iwl_time_event_notif *notif)
{
lockdep_assert_held(&mvm->time_event_lock);
IWL_DEBUG_TE(mvm, "Handle time event notif - UID = 0x%x action %d\n",
le32_to_cpu(notif->unique_id),
le32_to_cpu(notif->action));
if (WARN_ONCE(!le32_to_cpu(notif->status),
"Failed to schedule time event\n")) {
if (iwl_mvm_te_check_disconnect(mvm, te_data->vif, NULL)) {
iwl_mvm_te_clear_data(mvm, te_data);
return;
}
}
if (le32_to_cpu(notif->action) & TE_V2_NOTIF_HOST_EVENT_END) {
IWL_DEBUG_TE(mvm,
"TE ended - current time %lu, estimated end %lu\n",
jiffies, te_data->end_jiffies);
if (te_data->vif->type == NL80211_IFTYPE_P2P_DEVICE) {
ieee80211_remain_on_channel_expired(mvm->hw);
iwl_mvm_roc_finished(mvm);
}
iwl_mvm_te_check_disconnect(mvm, te_data->vif,
"No association and the time event is over already...");
iwl_mvm_te_clear_data(mvm, te_data);
} else if (le32_to_cpu(notif->action) & TE_V2_NOTIF_HOST_EVENT_START) {
te_data->running = true;
te_data->end_jiffies = TU_TO_EXP_TIME(te_data->duration);
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
static inline u16 te_v2_get_notify(__le16 policy)
{
return le16_to_cpu(policy) & TE_V2_NOTIF_MSK;
}
static inline u16 te_v2_get_dep_policy(__le16 policy)
{
return (le16_to_cpu(policy) & TE_V2_DEP_POLICY_MSK) >>
TE_V2_PLACEMENT_POS;
}
static inline u16 te_v2_get_absence(__le16 policy)
{
return (le16_to_cpu(policy) & TE_V2_ABSENCE) >> TE_V2_ABSENCE_POS;
}
static void iwl_mvm_te_v2_to_v1(const struct iwl_time_event_cmd_v2 *cmd_v2,
struct iwl_time_event_cmd_v1 *cmd_v1)
{
cmd_v1->id_and_color = cmd_v2->id_and_color;
cmd_v1->action = cmd_v2->action;
cmd_v1->id = cmd_v2->id;
cmd_v1->apply_time = cmd_v2->apply_time;
cmd_v1->max_delay = cmd_v2->max_delay;
cmd_v1->depends_on = cmd_v2->depends_on;
cmd_v1->interval = cmd_v2->interval;
cmd_v1->duration = cmd_v2->duration;
if (cmd_v2->repeat == TE_V2_REPEAT_ENDLESS)
cmd_v1->repeat = cpu_to_le32(TE_V1_REPEAT_ENDLESS);
else
cmd_v1->repeat = cpu_to_le32(cmd_v2->repeat);
cmd_v1->max_frags = cpu_to_le32(cmd_v2->max_frags);
cmd_v1->interval_reciprocal = 0;
cmd_v1->dep_policy = cpu_to_le32(te_v2_get_dep_policy(cmd_v2->policy));
cmd_v1->is_present = cpu_to_le32(!te_v2_get_absence(cmd_v2->policy));
cmd_v1->notify = cpu_to_le32(te_v2_get_notify(cmd_v2->policy));
}
static int iwl_mvm_send_time_event_cmd(struct iwl_mvm *mvm,
const struct iwl_time_event_cmd_v2 *cmd)
{
struct iwl_time_event_cmd_v1 cmd_v1;
if (mvm->fw->ucode_capa.flags & IWL_UCODE_TLV_FLAGS_TIME_EVENT_API_V2)
return iwl_mvm_send_cmd_pdu(mvm, TIME_EVENT_CMD, CMD_SYNC,
sizeof(*cmd), cmd);
iwl_mvm_te_v2_to_v1(cmd, &cmd_v1);
return iwl_mvm_send_cmd_pdu(mvm, TIME_EVENT_CMD, CMD_SYNC,
sizeof(cmd_v1), &cmd_v1);
}
static int iwl_mvm_time_event_send_add(struct iwl_mvm *mvm,
struct ieee80211_vif *vif,
struct iwl_mvm_time_event_data *te_data,
struct iwl_time_event_cmd_v2 *te_cmd)
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
ret = iwl_mvm_send_time_event_cmd(mvm, te_cmd);
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
struct iwl_time_event_cmd_v2 time_cmd = {};
lockdep_assert_held(&mvm->mutex);
if (te_data->running &&
time_after(te_data->end_jiffies, TU_TO_EXP_TIME(min_duration))) {
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
time_cmd.max_frags = TE_V2_FRAG_NONE;
time_cmd.max_delay = cpu_to_le32(500);
time_cmd.interval = cpu_to_le32(1);
time_cmd.duration = cpu_to_le32(duration);
time_cmd.repeat = 1;
time_cmd.policy = cpu_to_le16(TE_V2_NOTIF_HOST_EVENT_START |
TE_V2_NOTIF_HOST_EVENT_END);
iwl_mvm_time_event_send_add(mvm, vif, te_data, &time_cmd);
}
void iwl_mvm_remove_time_event(struct iwl_mvm *mvm,
struct iwl_mvm_vif *mvmvif,
struct iwl_mvm_time_event_data *te_data)
{
struct iwl_time_event_cmd_v2 time_cmd = {};
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
ret = iwl_mvm_send_time_event_cmd(mvm, &time_cmd);
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
int duration, enum ieee80211_roc_type type)
{
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
struct iwl_mvm_time_event_data *te_data = &mvmvif->time_event_data;
struct iwl_time_event_cmd_v2 time_cmd = {};
lockdep_assert_held(&mvm->mutex);
if (te_data->running) {
IWL_WARN(mvm, "P2P_DEVICE remain on channel already running\n");
return -EBUSY;
}
flush_work(&mvm->roc_done_wk);
time_cmd.action = cpu_to_le32(FW_CTXT_ACTION_ADD);
time_cmd.id_and_color =
cpu_to_le32(FW_CMD_ID_AND_COLOR(mvmvif->id, mvmvif->color));
switch (type) {
case IEEE80211_ROC_TYPE_NORMAL:
time_cmd.id = cpu_to_le32(IWL_MVM_ROC_TE_TYPE_NORMAL);
break;
case IEEE80211_ROC_TYPE_MGMT_TX:
time_cmd.id = cpu_to_le32(IWL_MVM_ROC_TE_TYPE_MGMT_TX);
break;
default:
WARN_ONCE(1, "Got an invalid ROC type\n");
return -EINVAL;
}
time_cmd.apply_time = cpu_to_le32(0);
time_cmd.interval = cpu_to_le32(1);
time_cmd.max_frags = min(MSEC_TO_TU(duration)/50, TE_V2_FRAG_ENDLESS);
time_cmd.max_delay = cpu_to_le32(MSEC_TO_TU(duration/2));
time_cmd.duration = cpu_to_le32(MSEC_TO_TU(duration));
time_cmd.repeat = 1;
time_cmd.policy = cpu_to_le16(TE_V2_NOTIF_HOST_EVENT_START |
TE_V2_NOTIF_HOST_EVENT_END);
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
