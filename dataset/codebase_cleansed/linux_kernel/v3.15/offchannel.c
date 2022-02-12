static void ieee80211_offchannel_ps_enable(struct ieee80211_sub_if_data *sdata)
{
struct ieee80211_local *local = sdata->local;
struct ieee80211_if_managed *ifmgd = &sdata->u.mgd;
local->offchannel_ps_enabled = false;
del_timer_sync(&local->dynamic_ps_timer);
del_timer_sync(&ifmgd->bcn_mon_timer);
del_timer_sync(&ifmgd->conn_mon_timer);
cancel_work_sync(&local->dynamic_ps_enable_work);
if (local->hw.conf.flags & IEEE80211_CONF_PS) {
local->offchannel_ps_enabled = true;
local->hw.conf.flags &= ~IEEE80211_CONF_PS;
ieee80211_hw_config(local, IEEE80211_CONF_CHANGE_PS);
}
if (!local->offchannel_ps_enabled ||
!(local->hw.flags & IEEE80211_HW_PS_NULLFUNC_STACK))
ieee80211_send_nullfunc(local, sdata, 1);
}
static void ieee80211_offchannel_ps_disable(struct ieee80211_sub_if_data *sdata)
{
struct ieee80211_local *local = sdata->local;
if (!local->ps_sdata)
ieee80211_send_nullfunc(local, sdata, 0);
else if (local->offchannel_ps_enabled) {
local->hw.conf.flags |= IEEE80211_CONF_PS;
ieee80211_hw_config(local, IEEE80211_CONF_CHANGE_PS);
} else if (local->hw.conf.dynamic_ps_timeout > 0) {
ieee80211_send_nullfunc(local, sdata, 0);
mod_timer(&local->dynamic_ps_timer, jiffies +
msecs_to_jiffies(local->hw.conf.dynamic_ps_timeout));
}
ieee80211_sta_reset_beacon_monitor(sdata);
ieee80211_sta_reset_conn_monitor(sdata);
}
void ieee80211_offchannel_stop_vifs(struct ieee80211_local *local)
{
struct ieee80211_sub_if_data *sdata;
if (WARN_ON(local->use_chanctx))
return;
ieee80211_stop_queues_by_reason(&local->hw, IEEE80211_MAX_QUEUE_MAP,
IEEE80211_QUEUE_STOP_REASON_OFFCHANNEL);
ieee80211_flush_queues(local, NULL);
mutex_lock(&local->iflist_mtx);
list_for_each_entry(sdata, &local->interfaces, list) {
if (!ieee80211_sdata_running(sdata))
continue;
if (sdata->vif.type == NL80211_IFTYPE_P2P_DEVICE)
continue;
if (sdata->vif.type != NL80211_IFTYPE_MONITOR)
set_bit(SDATA_STATE_OFFCHANNEL, &sdata->state);
if (sdata->vif.bss_conf.enable_beacon) {
set_bit(SDATA_STATE_OFFCHANNEL_BEACON_STOPPED,
&sdata->state);
sdata->vif.bss_conf.enable_beacon = false;
ieee80211_bss_info_change_notify(
sdata, BSS_CHANGED_BEACON_ENABLED);
}
if (sdata->vif.type == NL80211_IFTYPE_STATION &&
sdata->u.mgd.associated)
ieee80211_offchannel_ps_enable(sdata);
}
mutex_unlock(&local->iflist_mtx);
}
void ieee80211_offchannel_return(struct ieee80211_local *local)
{
struct ieee80211_sub_if_data *sdata;
if (WARN_ON(local->use_chanctx))
return;
mutex_lock(&local->iflist_mtx);
list_for_each_entry(sdata, &local->interfaces, list) {
if (sdata->vif.type == NL80211_IFTYPE_P2P_DEVICE)
continue;
if (sdata->vif.type != NL80211_IFTYPE_MONITOR)
clear_bit(SDATA_STATE_OFFCHANNEL, &sdata->state);
if (!ieee80211_sdata_running(sdata))
continue;
if (sdata->vif.type == NL80211_IFTYPE_STATION &&
sdata->u.mgd.associated)
ieee80211_offchannel_ps_disable(sdata);
if (test_and_clear_bit(SDATA_STATE_OFFCHANNEL_BEACON_STOPPED,
&sdata->state)) {
sdata->vif.bss_conf.enable_beacon = true;
ieee80211_bss_info_change_notify(
sdata, BSS_CHANGED_BEACON_ENABLED);
}
}
mutex_unlock(&local->iflist_mtx);
ieee80211_wake_queues_by_reason(&local->hw, IEEE80211_MAX_QUEUE_MAP,
IEEE80211_QUEUE_STOP_REASON_OFFCHANNEL);
}
void ieee80211_handle_roc_started(struct ieee80211_roc_work *roc)
{
if (roc->notified)
return;
if (roc->mgmt_tx_cookie) {
if (!WARN_ON(!roc->frame)) {
ieee80211_tx_skb_tid_band(roc->sdata, roc->frame, 7,
roc->chan->band);
roc->frame = NULL;
}
} else {
cfg80211_ready_on_channel(&roc->sdata->wdev, roc->cookie,
roc->chan, roc->req_duration,
GFP_KERNEL);
}
roc->notified = true;
}
static void ieee80211_hw_roc_start(struct work_struct *work)
{
struct ieee80211_local *local =
container_of(work, struct ieee80211_local, hw_roc_start);
struct ieee80211_roc_work *roc, *dep, *tmp;
mutex_lock(&local->mtx);
if (list_empty(&local->roc_list))
goto out_unlock;
roc = list_first_entry(&local->roc_list, struct ieee80211_roc_work,
list);
if (!roc->started)
goto out_unlock;
roc->hw_begun = true;
roc->hw_start_time = local->hw_roc_start_time;
ieee80211_handle_roc_started(roc);
list_for_each_entry_safe(dep, tmp, &roc->dependents, list) {
ieee80211_handle_roc_started(dep);
if (dep->duration > roc->duration) {
u32 dur = dep->duration;
dep->duration = dur - roc->duration;
roc->duration = dur;
list_move(&dep->list, &roc->list);
}
}
out_unlock:
mutex_unlock(&local->mtx);
}
void ieee80211_ready_on_channel(struct ieee80211_hw *hw)
{
struct ieee80211_local *local = hw_to_local(hw);
local->hw_roc_start_time = jiffies;
trace_api_ready_on_channel(local);
ieee80211_queue_work(hw, &local->hw_roc_start);
}
void ieee80211_start_next_roc(struct ieee80211_local *local)
{
struct ieee80211_roc_work *roc;
lockdep_assert_held(&local->mtx);
if (list_empty(&local->roc_list)) {
ieee80211_run_deferred_scan(local);
return;
}
roc = list_first_entry(&local->roc_list, struct ieee80211_roc_work,
list);
if (WARN_ON_ONCE(roc->started))
return;
if (local->ops->remain_on_channel) {
int ret, duration = roc->duration;
if (!duration)
duration = 10;
ret = drv_remain_on_channel(local, roc->sdata, roc->chan,
duration, roc->type);
roc->started = true;
if (ret) {
wiphy_warn(local->hw.wiphy,
"failed to start next HW ROC (%d)\n", ret);
ieee80211_remain_on_channel_expired(&local->hw);
}
} else {
ieee80211_queue_delayed_work(&local->hw, &roc->work,
round_jiffies_relative(HZ/2));
}
}
void ieee80211_roc_notify_destroy(struct ieee80211_roc_work *roc, bool free)
{
struct ieee80211_roc_work *dep, *tmp;
if (WARN_ON(roc->to_be_freed))
return;
if (roc->frame) {
cfg80211_mgmt_tx_status(&roc->sdata->wdev,
(unsigned long)roc->frame,
roc->frame->data, roc->frame->len,
false, GFP_KERNEL);
kfree_skb(roc->frame);
}
if (!roc->mgmt_tx_cookie)
cfg80211_remain_on_channel_expired(&roc->sdata->wdev,
roc->cookie, roc->chan,
GFP_KERNEL);
list_for_each_entry_safe(dep, tmp, &roc->dependents, list)
ieee80211_roc_notify_destroy(dep, true);
if (free)
kfree(roc);
else
roc->to_be_freed = true;
}
void ieee80211_sw_roc_work(struct work_struct *work)
{
struct ieee80211_roc_work *roc =
container_of(work, struct ieee80211_roc_work, work.work);
struct ieee80211_sub_if_data *sdata = roc->sdata;
struct ieee80211_local *local = sdata->local;
bool started, on_channel;
mutex_lock(&local->mtx);
if (roc->to_be_freed)
goto out_unlock;
if (roc->abort)
goto finish;
if (WARN_ON(list_empty(&local->roc_list)))
goto out_unlock;
if (WARN_ON(roc != list_first_entry(&local->roc_list,
struct ieee80211_roc_work,
list)))
goto out_unlock;
if (!roc->started) {
struct ieee80211_roc_work *dep;
WARN_ON(local->use_chanctx);
roc->on_channel = roc->chan == local->_oper_chandef.chan &&
local->_oper_chandef.width != NL80211_CHAN_WIDTH_5 &&
local->_oper_chandef.width != NL80211_CHAN_WIDTH_10;
ieee80211_recalc_idle(local);
if (!roc->on_channel) {
ieee80211_offchannel_stop_vifs(local);
local->tmp_channel = roc->chan;
ieee80211_hw_config(local, 0);
}
ieee80211_handle_roc_started(roc);
list_for_each_entry(dep, &roc->dependents, list)
ieee80211_handle_roc_started(dep);
if (!roc->duration)
goto finish;
roc->started = true;
ieee80211_queue_delayed_work(&local->hw, &roc->work,
msecs_to_jiffies(roc->duration));
} else {
finish:
list_del(&roc->list);
started = roc->started;
on_channel = roc->on_channel;
ieee80211_roc_notify_destroy(roc, !roc->abort);
if (started && !on_channel) {
ieee80211_flush_queues(local, NULL);
local->tmp_channel = NULL;
ieee80211_hw_config(local, 0);
ieee80211_offchannel_return(local);
}
ieee80211_recalc_idle(local);
if (started)
ieee80211_start_next_roc(local);
else if (list_empty(&local->roc_list))
ieee80211_run_deferred_scan(local);
}
out_unlock:
mutex_unlock(&local->mtx);
}
static void ieee80211_hw_roc_done(struct work_struct *work)
{
struct ieee80211_local *local =
container_of(work, struct ieee80211_local, hw_roc_done);
struct ieee80211_roc_work *roc;
mutex_lock(&local->mtx);
if (list_empty(&local->roc_list))
goto out_unlock;
roc = list_first_entry(&local->roc_list, struct ieee80211_roc_work,
list);
if (!roc->started)
goto out_unlock;
list_del(&roc->list);
ieee80211_roc_notify_destroy(roc, true);
ieee80211_start_next_roc(local);
out_unlock:
mutex_unlock(&local->mtx);
}
void ieee80211_remain_on_channel_expired(struct ieee80211_hw *hw)
{
struct ieee80211_local *local = hw_to_local(hw);
trace_api_remain_on_channel_expired(local);
ieee80211_queue_work(hw, &local->hw_roc_done);
}
void ieee80211_roc_setup(struct ieee80211_local *local)
{
INIT_WORK(&local->hw_roc_start, ieee80211_hw_roc_start);
INIT_WORK(&local->hw_roc_done, ieee80211_hw_roc_done);
INIT_LIST_HEAD(&local->roc_list);
}
void ieee80211_roc_purge(struct ieee80211_local *local,
struct ieee80211_sub_if_data *sdata)
{
struct ieee80211_roc_work *roc, *tmp;
LIST_HEAD(tmp_list);
mutex_lock(&local->mtx);
list_for_each_entry_safe(roc, tmp, &local->roc_list, list) {
if (sdata && roc->sdata != sdata)
continue;
if (roc->started && local->ops->remain_on_channel) {
drv_cancel_remain_on_channel(local);
}
list_move_tail(&roc->list, &tmp_list);
roc->abort = true;
}
mutex_unlock(&local->mtx);
list_for_each_entry_safe(roc, tmp, &tmp_list, list) {
if (local->ops->remain_on_channel) {
list_del(&roc->list);
ieee80211_roc_notify_destroy(roc, true);
} else {
ieee80211_queue_delayed_work(&local->hw, &roc->work, 0);
flush_delayed_work(&roc->work);
WARN_ON(!roc->to_be_freed);
kfree(roc);
}
}
WARN_ON_ONCE(!list_empty(&tmp_list));
}
