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
!ieee80211_hw_check(&local->hw, PS_NULLFUNC_STACK))
ieee80211_send_nullfunc(local, sdata, true);
}
static void ieee80211_offchannel_ps_disable(struct ieee80211_sub_if_data *sdata)
{
struct ieee80211_local *local = sdata->local;
if (!local->ps_sdata)
ieee80211_send_nullfunc(local, sdata, false);
else if (local->offchannel_ps_enabled) {
local->hw.conf.flags |= IEEE80211_CONF_PS;
ieee80211_hw_config(local, IEEE80211_CONF_CHANGE_PS);
} else if (local->hw.conf.dynamic_ps_timeout > 0) {
ieee80211_send_nullfunc(local, sdata, false);
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
IEEE80211_QUEUE_STOP_REASON_OFFCHANNEL,
false);
ieee80211_flush_queues(local, NULL, false);
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
IEEE80211_QUEUE_STOP_REASON_OFFCHANNEL,
false);
}
static void ieee80211_roc_notify_destroy(struct ieee80211_roc_work *roc)
{
if (roc->frame) {
cfg80211_mgmt_tx_status(&roc->sdata->wdev, roc->mgmt_tx_cookie,
roc->frame->data, roc->frame->len,
false, GFP_KERNEL);
ieee80211_free_txskb(&roc->sdata->local->hw, roc->frame);
}
if (!roc->mgmt_tx_cookie)
cfg80211_remain_on_channel_expired(&roc->sdata->wdev,
roc->cookie, roc->chan,
GFP_KERNEL);
list_del(&roc->list);
kfree(roc);
}
static unsigned long ieee80211_end_finished_rocs(struct ieee80211_local *local,
unsigned long now)
{
struct ieee80211_roc_work *roc, *tmp;
long remaining_dur_min = LONG_MAX;
lockdep_assert_held(&local->mtx);
list_for_each_entry_safe(roc, tmp, &local->roc_list, list) {
long remaining;
if (!roc->started)
break;
remaining = roc->start_time +
msecs_to_jiffies(roc->duration) -
now;
if (roc->abort || roc->hw_begun || remaining <= 0)
ieee80211_roc_notify_destroy(roc);
else
remaining_dur_min = min(remaining_dur_min, remaining);
}
return remaining_dur_min;
}
static bool ieee80211_recalc_sw_work(struct ieee80211_local *local,
unsigned long now)
{
long dur = ieee80211_end_finished_rocs(local, now);
if (dur == LONG_MAX)
return false;
mod_delayed_work(local->workqueue, &local->roc_work, dur);
return true;
}
static void ieee80211_handle_roc_started(struct ieee80211_roc_work *roc,
unsigned long start_time)
{
if (WARN_ON(roc->notified))
return;
roc->start_time = start_time;
roc->started = true;
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
struct ieee80211_roc_work *roc;
mutex_lock(&local->mtx);
list_for_each_entry(roc, &local->roc_list, list) {
if (!roc->started)
break;
roc->hw_begun = true;
ieee80211_handle_roc_started(roc, local->hw_roc_start_time);
}
mutex_unlock(&local->mtx);
}
void ieee80211_ready_on_channel(struct ieee80211_hw *hw)
{
struct ieee80211_local *local = hw_to_local(hw);
local->hw_roc_start_time = jiffies;
trace_api_ready_on_channel(local);
ieee80211_queue_work(hw, &local->hw_roc_start);
}
static void _ieee80211_start_next_roc(struct ieee80211_local *local)
{
struct ieee80211_roc_work *roc, *tmp;
enum ieee80211_roc_type type;
u32 min_dur, max_dur;
lockdep_assert_held(&local->mtx);
if (WARN_ON(list_empty(&local->roc_list)))
return;
roc = list_first_entry(&local->roc_list, struct ieee80211_roc_work,
list);
if (WARN_ON(roc->started))
return;
min_dur = roc->duration;
max_dur = roc->duration;
type = roc->type;
list_for_each_entry(tmp, &local->roc_list, list) {
if (tmp == roc)
continue;
if (tmp->sdata != roc->sdata || tmp->chan != roc->chan)
break;
max_dur = max(tmp->duration, max_dur);
min_dur = min(tmp->duration, min_dur);
type = max(tmp->type, type);
}
if (local->ops->remain_on_channel) {
int ret = drv_remain_on_channel(local, roc->sdata, roc->chan,
max_dur, type);
if (ret) {
wiphy_warn(local->hw.wiphy,
"failed to start next HW ROC (%d)\n", ret);
list_for_each_entry(tmp, &local->roc_list, list) {
if (tmp->sdata != roc->sdata ||
tmp->chan != roc->chan)
break;
tmp->started = true;
tmp->abort = true;
}
ieee80211_queue_work(&local->hw, &local->hw_roc_done);
return;
}
list_for_each_entry(tmp, &local->roc_list, list) {
if (tmp->sdata != roc->sdata || tmp->chan != roc->chan)
break;
tmp->started = true;
}
} else {
roc->on_channel = roc->chan == local->_oper_chandef.chan &&
local->_oper_chandef.width != NL80211_CHAN_WIDTH_5 &&
local->_oper_chandef.width != NL80211_CHAN_WIDTH_10;
ieee80211_recalc_idle(local);
if (!roc->on_channel) {
ieee80211_offchannel_stop_vifs(local);
local->tmp_channel = roc->chan;
ieee80211_hw_config(local, 0);
}
ieee80211_queue_delayed_work(&local->hw, &local->roc_work,
msecs_to_jiffies(min_dur));
list_for_each_entry(tmp, &local->roc_list, list) {
if (tmp->sdata != roc->sdata || tmp->chan != roc->chan)
break;
tmp->on_channel = roc->on_channel;
ieee80211_handle_roc_started(tmp, jiffies);
}
}
}
void ieee80211_start_next_roc(struct ieee80211_local *local)
{
struct ieee80211_roc_work *roc;
lockdep_assert_held(&local->mtx);
if (list_empty(&local->roc_list)) {
ieee80211_run_deferred_scan(local);
return;
}
if (local->in_reconfig)
return;
roc = list_first_entry(&local->roc_list, struct ieee80211_roc_work,
list);
if (WARN_ON_ONCE(roc->started))
return;
if (local->ops->remain_on_channel) {
_ieee80211_start_next_roc(local);
} else {
ieee80211_queue_delayed_work(&local->hw, &local->roc_work,
round_jiffies_relative(HZ/2));
}
}
static void __ieee80211_roc_work(struct ieee80211_local *local)
{
struct ieee80211_roc_work *roc;
bool on_channel;
lockdep_assert_held(&local->mtx);
if (WARN_ON(local->ops->remain_on_channel))
return;
roc = list_first_entry_or_null(&local->roc_list,
struct ieee80211_roc_work, list);
if (!roc)
return;
if (!roc->started) {
WARN_ON(local->use_chanctx);
_ieee80211_start_next_roc(local);
} else {
on_channel = roc->on_channel;
if (ieee80211_recalc_sw_work(local, jiffies))
return;
if (!on_channel) {
ieee80211_flush_queues(local, NULL, false);
local->tmp_channel = NULL;
ieee80211_hw_config(local, 0);
ieee80211_offchannel_return(local);
}
ieee80211_recalc_idle(local);
ieee80211_start_next_roc(local);
}
}
static void ieee80211_roc_work(struct work_struct *work)
{
struct ieee80211_local *local =
container_of(work, struct ieee80211_local, roc_work.work);
mutex_lock(&local->mtx);
__ieee80211_roc_work(local);
mutex_unlock(&local->mtx);
}
static void ieee80211_hw_roc_done(struct work_struct *work)
{
struct ieee80211_local *local =
container_of(work, struct ieee80211_local, hw_roc_done);
mutex_lock(&local->mtx);
ieee80211_end_finished_rocs(local, jiffies);
ieee80211_start_next_roc(local);
mutex_unlock(&local->mtx);
}
void ieee80211_remain_on_channel_expired(struct ieee80211_hw *hw)
{
struct ieee80211_local *local = hw_to_local(hw);
trace_api_remain_on_channel_expired(local);
ieee80211_queue_work(hw, &local->hw_roc_done);
}
static bool
ieee80211_coalesce_hw_started_roc(struct ieee80211_local *local,
struct ieee80211_roc_work *new_roc,
struct ieee80211_roc_work *cur_roc)
{
unsigned long now = jiffies;
unsigned long remaining;
if (WARN_ON(!cur_roc->started))
return false;
if (!cur_roc->hw_begun && new_roc->duration > cur_roc->duration)
return false;
remaining = cur_roc->start_time +
msecs_to_jiffies(cur_roc->duration) -
now;
if (new_roc->duration > jiffies_to_msecs(remaining))
return false;
list_add(&new_roc->list, &cur_roc->list);
if (cur_roc->hw_begun) {
new_roc->hw_begun = true;
ieee80211_handle_roc_started(new_roc, now);
}
return true;
}
static int ieee80211_start_roc_work(struct ieee80211_local *local,
struct ieee80211_sub_if_data *sdata,
struct ieee80211_channel *channel,
unsigned int duration, u64 *cookie,
struct sk_buff *txskb,
enum ieee80211_roc_type type)
{
struct ieee80211_roc_work *roc, *tmp;
bool queued = false, combine_started = true;
int ret;
lockdep_assert_held(&local->mtx);
if (local->use_chanctx && !local->ops->remain_on_channel)
return -EOPNOTSUPP;
roc = kzalloc(sizeof(*roc), GFP_KERNEL);
if (!roc)
return -ENOMEM;
if (!duration)
duration = 10;
roc->chan = channel;
roc->duration = duration;
roc->req_duration = duration;
roc->frame = txskb;
roc->type = type;
roc->sdata = sdata;
if (!txskb) {
roc->cookie = ieee80211_mgmt_tx_cookie(local);
*cookie = roc->cookie;
} else {
roc->mgmt_tx_cookie = *cookie;
}
if (list_empty(&local->roc_list) &&
!local->scanning && !ieee80211_is_radar_required(local)) {
if (!local->ops->remain_on_channel) {
list_add_tail(&roc->list, &local->roc_list);
ieee80211_queue_delayed_work(&local->hw,
&local->roc_work, 0);
} else {
ret = drv_remain_on_channel(local, sdata, channel,
duration, type);
if (ret) {
kfree(roc);
return ret;
}
roc->started = true;
list_add_tail(&roc->list, &local->roc_list);
}
return 0;
}
list_for_each_entry(tmp, &local->roc_list, list) {
if (tmp->chan != channel || tmp->sdata != sdata)
continue;
if (!tmp->started) {
list_add(&roc->list, &tmp->list);
queued = true;
break;
}
if (!combine_started)
continue;
if (!local->ops->remain_on_channel) {
unsigned long now = jiffies;
u32 elapsed = jiffies_to_msecs(now - tmp->start_time);
struct wiphy *wiphy = local->hw.wiphy;
u32 max_roc = wiphy->max_remain_on_channel_duration;
if (elapsed + roc->duration > max_roc) {
combine_started = false;
continue;
}
list_add(&roc->list, &tmp->list);
queued = true;
roc->on_channel = tmp->on_channel;
ieee80211_handle_roc_started(roc, now);
ieee80211_recalc_sw_work(local, now);
break;
}
queued = ieee80211_coalesce_hw_started_roc(local, roc, tmp);
if (queued)
break;
combine_started = false;
}
if (!queued)
list_add_tail(&roc->list, &local->roc_list);
return 0;
}
int ieee80211_remain_on_channel(struct wiphy *wiphy, struct wireless_dev *wdev,
struct ieee80211_channel *chan,
unsigned int duration, u64 *cookie)
{
struct ieee80211_sub_if_data *sdata = IEEE80211_WDEV_TO_SUB_IF(wdev);
struct ieee80211_local *local = sdata->local;
int ret;
mutex_lock(&local->mtx);
ret = ieee80211_start_roc_work(local, sdata, chan,
duration, cookie, NULL,
IEEE80211_ROC_TYPE_NORMAL);
mutex_unlock(&local->mtx);
return ret;
}
static int ieee80211_cancel_roc(struct ieee80211_local *local,
u64 cookie, bool mgmt_tx)
{
struct ieee80211_roc_work *roc, *tmp, *found = NULL;
int ret;
if (!cookie)
return -ENOENT;
mutex_lock(&local->mtx);
list_for_each_entry_safe(roc, tmp, &local->roc_list, list) {
if (!mgmt_tx && roc->cookie != cookie)
continue;
else if (mgmt_tx && roc->mgmt_tx_cookie != cookie)
continue;
found = roc;
break;
}
if (!found) {
mutex_unlock(&local->mtx);
return -ENOENT;
}
if (!found->started) {
ieee80211_roc_notify_destroy(found);
goto out_unlock;
}
if (local->ops->remain_on_channel) {
ret = drv_cancel_remain_on_channel(local);
if (WARN_ON_ONCE(ret)) {
mutex_unlock(&local->mtx);
return ret;
}
list_for_each_entry_safe(roc, tmp, &local->roc_list, list) {
if (!roc->started)
break;
if (roc == found)
found = NULL;
ieee80211_roc_notify_destroy(roc);
}
WARN_ON(found);
ieee80211_start_next_roc(local);
} else {
found->abort = true;
mod_delayed_work(local->workqueue, &local->roc_work, 0);
}
out_unlock:
mutex_unlock(&local->mtx);
return 0;
}
int ieee80211_cancel_remain_on_channel(struct wiphy *wiphy,
struct wireless_dev *wdev, u64 cookie)
{
struct ieee80211_sub_if_data *sdata = IEEE80211_WDEV_TO_SUB_IF(wdev);
struct ieee80211_local *local = sdata->local;
return ieee80211_cancel_roc(local, cookie, false);
}
int ieee80211_mgmt_tx(struct wiphy *wiphy, struct wireless_dev *wdev,
struct cfg80211_mgmt_tx_params *params, u64 *cookie)
{
struct ieee80211_sub_if_data *sdata = IEEE80211_WDEV_TO_SUB_IF(wdev);
struct ieee80211_local *local = sdata->local;
struct sk_buff *skb;
struct sta_info *sta;
const struct ieee80211_mgmt *mgmt = (void *)params->buf;
bool need_offchan = false;
u32 flags;
int ret;
u8 *data;
if (params->dont_wait_for_ack)
flags = IEEE80211_TX_CTL_NO_ACK;
else
flags = IEEE80211_TX_INTFL_NL80211_FRAME_TX |
IEEE80211_TX_CTL_REQ_TX_STATUS;
if (params->no_cck)
flags |= IEEE80211_TX_CTL_NO_CCK_RATE;
switch (sdata->vif.type) {
case NL80211_IFTYPE_ADHOC:
if (!sdata->vif.bss_conf.ibss_joined)
need_offchan = true;
#ifdef CONFIG_MAC80211_MESH
case NL80211_IFTYPE_MESH_POINT:
if (ieee80211_vif_is_mesh(&sdata->vif) &&
!sdata->u.mesh.mesh_id_len)
need_offchan = true;
#endif
case NL80211_IFTYPE_AP:
case NL80211_IFTYPE_AP_VLAN:
case NL80211_IFTYPE_P2P_GO:
if (sdata->vif.type != NL80211_IFTYPE_ADHOC &&
!ieee80211_vif_is_mesh(&sdata->vif) &&
!rcu_access_pointer(sdata->bss->beacon))
need_offchan = true;
if (!ieee80211_is_action(mgmt->frame_control) ||
mgmt->u.action.category == WLAN_CATEGORY_PUBLIC ||
mgmt->u.action.category == WLAN_CATEGORY_SELF_PROTECTED ||
mgmt->u.action.category == WLAN_CATEGORY_SPECTRUM_MGMT)
break;
rcu_read_lock();
sta = sta_info_get(sdata, mgmt->da);
rcu_read_unlock();
if (!sta)
return -ENOLINK;
break;
case NL80211_IFTYPE_STATION:
case NL80211_IFTYPE_P2P_CLIENT:
sdata_lock(sdata);
if (!sdata->u.mgd.associated ||
(params->offchan && params->wait &&
local->ops->remain_on_channel &&
memcmp(sdata->u.mgd.associated->bssid,
mgmt->bssid, ETH_ALEN)))
need_offchan = true;
sdata_unlock(sdata);
break;
case NL80211_IFTYPE_P2P_DEVICE:
need_offchan = true;
break;
default:
return -EOPNOTSUPP;
}
if (need_offchan && !params->chan)
return -EINVAL;
mutex_lock(&local->mtx);
if (!need_offchan) {
struct ieee80211_chanctx_conf *chanctx_conf;
rcu_read_lock();
chanctx_conf = rcu_dereference(sdata->vif.chanctx_conf);
if (chanctx_conf) {
need_offchan = params->chan &&
(params->chan !=
chanctx_conf->def.chan);
} else if (!params->chan) {
ret = -EINVAL;
rcu_read_unlock();
goto out_unlock;
} else {
need_offchan = true;
}
rcu_read_unlock();
}
if (need_offchan && !params->offchan) {
ret = -EBUSY;
goto out_unlock;
}
skb = dev_alloc_skb(local->hw.extra_tx_headroom + params->len);
if (!skb) {
ret = -ENOMEM;
goto out_unlock;
}
skb_reserve(skb, local->hw.extra_tx_headroom);
data = skb_put(skb, params->len);
memcpy(data, params->buf, params->len);
if (sdata->vif.csa_active &&
(sdata->vif.type == NL80211_IFTYPE_AP ||
sdata->vif.type == NL80211_IFTYPE_MESH_POINT ||
sdata->vif.type == NL80211_IFTYPE_ADHOC) &&
params->n_csa_offsets) {
int i;
struct beacon_data *beacon = NULL;
rcu_read_lock();
if (sdata->vif.type == NL80211_IFTYPE_AP)
beacon = rcu_dereference(sdata->u.ap.beacon);
else if (sdata->vif.type == NL80211_IFTYPE_ADHOC)
beacon = rcu_dereference(sdata->u.ibss.presp);
else if (ieee80211_vif_is_mesh(&sdata->vif))
beacon = rcu_dereference(sdata->u.mesh.beacon);
if (beacon)
for (i = 0; i < params->n_csa_offsets; i++)
data[params->csa_offsets[i]] =
beacon->csa_current_counter;
rcu_read_unlock();
}
IEEE80211_SKB_CB(skb)->flags = flags;
skb->dev = sdata->dev;
if (!params->dont_wait_for_ack) {
ret = ieee80211_attach_ack_skb(local, skb, cookie, GFP_KERNEL);
if (ret) {
kfree_skb(skb);
goto out_unlock;
}
} else {
*cookie = 0xffffffff;
}
if (!need_offchan) {
ieee80211_tx_skb(sdata, skb);
ret = 0;
goto out_unlock;
}
IEEE80211_SKB_CB(skb)->flags |= IEEE80211_TX_CTL_TX_OFFCHAN |
IEEE80211_TX_INTFL_OFFCHAN_TX_OK;
if (ieee80211_hw_check(&local->hw, QUEUE_CONTROL))
IEEE80211_SKB_CB(skb)->hw_queue =
local->hw.offchannel_tx_hw_queue;
ret = ieee80211_start_roc_work(local, sdata, params->chan,
params->wait, cookie, skb,
IEEE80211_ROC_TYPE_MGMT_TX);
if (ret)
ieee80211_free_txskb(&local->hw, skb);
out_unlock:
mutex_unlock(&local->mtx);
return ret;
}
int ieee80211_mgmt_tx_cancel_wait(struct wiphy *wiphy,
struct wireless_dev *wdev, u64 cookie)
{
struct ieee80211_local *local = wiphy_priv(wiphy);
return ieee80211_cancel_roc(local, cookie, true);
}
void ieee80211_roc_setup(struct ieee80211_local *local)
{
INIT_WORK(&local->hw_roc_start, ieee80211_hw_roc_start);
INIT_WORK(&local->hw_roc_done, ieee80211_hw_roc_done);
INIT_DELAYED_WORK(&local->roc_work, ieee80211_roc_work);
INIT_LIST_HEAD(&local->roc_list);
}
void ieee80211_roc_purge(struct ieee80211_local *local,
struct ieee80211_sub_if_data *sdata)
{
struct ieee80211_roc_work *roc, *tmp;
bool work_to_do = false;
mutex_lock(&local->mtx);
list_for_each_entry_safe(roc, tmp, &local->roc_list, list) {
if (sdata && roc->sdata != sdata)
continue;
if (roc->started) {
if (local->ops->remain_on_channel) {
drv_cancel_remain_on_channel(local);
ieee80211_roc_notify_destroy(roc);
} else {
roc->abort = true;
work_to_do = true;
}
} else {
ieee80211_roc_notify_destroy(roc);
}
}
if (work_to_do)
__ieee80211_roc_work(local);
mutex_unlock(&local->mtx);
}
