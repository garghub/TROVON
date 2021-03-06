static void ieee80211_free_tid_rx(struct rcu_head *h)
{
struct tid_ampdu_rx *tid_rx =
container_of(h, struct tid_ampdu_rx, rcu_head);
int i;
for (i = 0; i < tid_rx->buf_size; i++)
__skb_queue_purge(&tid_rx->reorder_buf[i]);
kfree(tid_rx->reorder_buf);
kfree(tid_rx->reorder_time);
kfree(tid_rx);
}
void ___ieee80211_stop_rx_ba_session(struct sta_info *sta, u16 tid,
u16 initiator, u16 reason, bool tx)
{
struct ieee80211_local *local = sta->local;
struct tid_ampdu_rx *tid_rx;
struct ieee80211_ampdu_params params = {
.sta = &sta->sta,
.action = IEEE80211_AMPDU_RX_STOP,
.tid = tid,
.amsdu = false,
.timeout = 0,
.ssn = 0,
};
lockdep_assert_held(&sta->ampdu_mlme.mtx);
tid_rx = rcu_dereference_protected(sta->ampdu_mlme.tid_rx[tid],
lockdep_is_held(&sta->ampdu_mlme.mtx));
if (!test_bit(tid, sta->ampdu_mlme.agg_session_valid))
return;
RCU_INIT_POINTER(sta->ampdu_mlme.tid_rx[tid], NULL);
__clear_bit(tid, sta->ampdu_mlme.agg_session_valid);
ht_dbg(sta->sdata,
"Rx BA session stop requested for %pM tid %u %s reason: %d\n",
sta->sta.addr, tid,
initiator == WLAN_BACK_RECIPIENT ? "recipient" : "initiator",
(int)reason);
if (drv_ampdu_action(local, sta->sdata, &params))
sdata_info(sta->sdata,
"HW problem - can not stop rx aggregation for %pM tid %d\n",
sta->sta.addr, tid);
if (initiator == WLAN_BACK_RECIPIENT && tx)
ieee80211_send_delba(sta->sdata, sta->sta.addr,
tid, WLAN_BACK_RECIPIENT, reason);
if (!tid_rx)
return;
del_timer_sync(&tid_rx->session_timer);
spin_lock_bh(&tid_rx->reorder_lock);
tid_rx->removed = true;
spin_unlock_bh(&tid_rx->reorder_lock);
del_timer_sync(&tid_rx->reorder_timer);
call_rcu(&tid_rx->rcu_head, ieee80211_free_tid_rx);
}
void __ieee80211_stop_rx_ba_session(struct sta_info *sta, u16 tid,
u16 initiator, u16 reason, bool tx)
{
mutex_lock(&sta->ampdu_mlme.mtx);
___ieee80211_stop_rx_ba_session(sta, tid, initiator, reason, tx);
mutex_unlock(&sta->ampdu_mlme.mtx);
}
void ieee80211_stop_rx_ba_session(struct ieee80211_vif *vif, u16 ba_rx_bitmap,
const u8 *addr)
{
struct ieee80211_sub_if_data *sdata = vif_to_sdata(vif);
struct sta_info *sta;
int i;
rcu_read_lock();
sta = sta_info_get_bss(sdata, addr);
if (!sta) {
rcu_read_unlock();
return;
}
for (i = 0; i < IEEE80211_NUM_TIDS; i++)
if (ba_rx_bitmap & BIT(i))
set_bit(i, sta->ampdu_mlme.tid_rx_stop_requested);
ieee80211_queue_work(&sta->local->hw, &sta->ampdu_mlme.work);
rcu_read_unlock();
}
static void sta_rx_agg_session_timer_expired(unsigned long data)
{
u8 *ptid = (u8 *)data;
u8 *timer_to_id = ptid - *ptid;
struct sta_info *sta = container_of(timer_to_id, struct sta_info,
timer_to_tid[0]);
struct tid_ampdu_rx *tid_rx;
unsigned long timeout;
rcu_read_lock();
tid_rx = rcu_dereference(sta->ampdu_mlme.tid_rx[*ptid]);
if (!tid_rx) {
rcu_read_unlock();
return;
}
timeout = tid_rx->last_rx + TU_TO_JIFFIES(tid_rx->timeout);
if (time_is_after_jiffies(timeout)) {
mod_timer(&tid_rx->session_timer, timeout);
rcu_read_unlock();
return;
}
rcu_read_unlock();
ht_dbg(sta->sdata, "RX session timer expired on %pM tid %d\n",
sta->sta.addr, (u16)*ptid);
set_bit(*ptid, sta->ampdu_mlme.tid_rx_timer_expired);
ieee80211_queue_work(&sta->local->hw, &sta->ampdu_mlme.work);
}
static void sta_rx_agg_reorder_timer_expired(unsigned long data)
{
u8 *ptid = (u8 *)data;
u8 *timer_to_id = ptid - *ptid;
struct sta_info *sta = container_of(timer_to_id, struct sta_info,
timer_to_tid[0]);
rcu_read_lock();
ieee80211_release_reorder_timeout(sta, *ptid);
rcu_read_unlock();
}
static void ieee80211_send_addba_resp(struct ieee80211_sub_if_data *sdata, u8 *da, u16 tid,
u8 dialog_token, u16 status, u16 policy,
u16 buf_size, u16 timeout)
{
struct ieee80211_local *local = sdata->local;
struct sk_buff *skb;
struct ieee80211_mgmt *mgmt;
bool amsdu = ieee80211_hw_check(&local->hw, SUPPORTS_AMSDU_IN_AMPDU);
u16 capab;
skb = dev_alloc_skb(sizeof(*mgmt) + local->hw.extra_tx_headroom);
if (!skb)
return;
skb_reserve(skb, local->hw.extra_tx_headroom);
mgmt = skb_put_zero(skb, 24);
memcpy(mgmt->da, da, ETH_ALEN);
memcpy(mgmt->sa, sdata->vif.addr, ETH_ALEN);
if (sdata->vif.type == NL80211_IFTYPE_AP ||
sdata->vif.type == NL80211_IFTYPE_AP_VLAN ||
sdata->vif.type == NL80211_IFTYPE_MESH_POINT)
memcpy(mgmt->bssid, sdata->vif.addr, ETH_ALEN);
else if (sdata->vif.type == NL80211_IFTYPE_STATION)
memcpy(mgmt->bssid, sdata->u.mgd.bssid, ETH_ALEN);
else if (sdata->vif.type == NL80211_IFTYPE_ADHOC)
memcpy(mgmt->bssid, sdata->u.ibss.bssid, ETH_ALEN);
mgmt->frame_control = cpu_to_le16(IEEE80211_FTYPE_MGMT |
IEEE80211_STYPE_ACTION);
skb_put(skb, 1 + sizeof(mgmt->u.action.u.addba_resp));
mgmt->u.action.category = WLAN_CATEGORY_BACK;
mgmt->u.action.u.addba_resp.action_code = WLAN_ACTION_ADDBA_RESP;
mgmt->u.action.u.addba_resp.dialog_token = dialog_token;
capab = (u16)(amsdu << 0);
capab |= (u16)(policy << 1);
capab |= (u16)(tid << 2);
capab |= (u16)(buf_size << 6);
mgmt->u.action.u.addba_resp.capab = cpu_to_le16(capab);
mgmt->u.action.u.addba_resp.timeout = cpu_to_le16(timeout);
mgmt->u.action.u.addba_resp.status = cpu_to_le16(status);
ieee80211_tx_skb(sdata, skb);
}
void __ieee80211_start_rx_ba_session(struct sta_info *sta,
u8 dialog_token, u16 timeout,
u16 start_seq_num, u16 ba_policy, u16 tid,
u16 buf_size, bool tx, bool auto_seq)
{
struct ieee80211_local *local = sta->sdata->local;
struct tid_ampdu_rx *tid_agg_rx;
struct ieee80211_ampdu_params params = {
.sta = &sta->sta,
.action = IEEE80211_AMPDU_RX_START,
.tid = tid,
.amsdu = false,
.timeout = timeout,
.ssn = start_seq_num,
};
int i, ret = -EOPNOTSUPP;
u16 status = WLAN_STATUS_REQUEST_DECLINED;
if (tid >= IEEE80211_FIRST_TSPEC_TSID) {
ht_dbg(sta->sdata,
"STA %pM requests BA session on unsupported tid %d\n",
sta->sta.addr, tid);
goto end_no_lock;
}
if (!sta->sta.ht_cap.ht_supported) {
ht_dbg(sta->sdata,
"STA %pM erroneously requests BA session on tid %d w/o QoS\n",
sta->sta.addr, tid);
goto end_no_lock;
}
if (test_sta_flag(sta, WLAN_STA_BLOCK_BA)) {
ht_dbg(sta->sdata,
"Suspend in progress - Denying ADDBA request (%pM tid %d)\n",
sta->sta.addr, tid);
goto end_no_lock;
}
if (((ba_policy != 1) &&
(!(sta->sta.ht_cap.cap & IEEE80211_HT_CAP_DELAY_BA))) ||
(buf_size > IEEE80211_MAX_AMPDU_BUF)) {
status = WLAN_STATUS_INVALID_QOS_PARAM;
ht_dbg_ratelimited(sta->sdata,
"AddBA Req with bad params from %pM on tid %u. policy %d, buffer size %d\n",
sta->sta.addr, tid, ba_policy, buf_size);
goto end_no_lock;
}
if (buf_size == 0)
buf_size = IEEE80211_MAX_AMPDU_BUF;
if (buf_size > sta->sta.max_rx_aggregation_subframes)
buf_size = sta->sta.max_rx_aggregation_subframes;
params.buf_size = buf_size;
ht_dbg(sta->sdata, "AddBA Req buf_size=%d for %pM\n",
buf_size, sta->sta.addr);
mutex_lock(&sta->ampdu_mlme.mtx);
if (test_bit(tid, sta->ampdu_mlme.agg_session_valid)) {
if (sta->ampdu_mlme.tid_rx_token[tid] == dialog_token) {
ht_dbg_ratelimited(sta->sdata,
"updated AddBA Req from %pM on tid %u\n",
sta->sta.addr, tid);
status = WLAN_STATUS_REQUEST_DECLINED;
ieee80211_send_addba_resp(sta->sdata, sta->sta.addr,
tid, dialog_token, status,
1, buf_size, timeout);
goto end;
}
ht_dbg_ratelimited(sta->sdata,
"unexpected AddBA Req from %pM on tid %u\n",
sta->sta.addr, tid);
___ieee80211_stop_rx_ba_session(sta, tid, WLAN_BACK_RECIPIENT,
WLAN_STATUS_UNSPECIFIED_QOS,
false);
}
if (ieee80211_hw_check(&local->hw, SUPPORTS_REORDERING_BUFFER)) {
ret = drv_ampdu_action(local, sta->sdata, &params);
ht_dbg(sta->sdata,
"Rx A-MPDU request on %pM tid %d result %d\n",
sta->sta.addr, tid, ret);
if (!ret)
status = WLAN_STATUS_SUCCESS;
goto end;
}
tid_agg_rx = kzalloc(sizeof(*tid_agg_rx), GFP_KERNEL);
if (!tid_agg_rx)
goto end;
spin_lock_init(&tid_agg_rx->reorder_lock);
setup_deferrable_timer(&tid_agg_rx->session_timer,
sta_rx_agg_session_timer_expired,
(unsigned long)&sta->timer_to_tid[tid]);
setup_timer(&tid_agg_rx->reorder_timer,
sta_rx_agg_reorder_timer_expired,
(unsigned long)&sta->timer_to_tid[tid]);
tid_agg_rx->reorder_buf =
kcalloc(buf_size, sizeof(struct sk_buff_head), GFP_KERNEL);
tid_agg_rx->reorder_time =
kcalloc(buf_size, sizeof(unsigned long), GFP_KERNEL);
if (!tid_agg_rx->reorder_buf || !tid_agg_rx->reorder_time) {
kfree(tid_agg_rx->reorder_buf);
kfree(tid_agg_rx->reorder_time);
kfree(tid_agg_rx);
goto end;
}
for (i = 0; i < buf_size; i++)
__skb_queue_head_init(&tid_agg_rx->reorder_buf[i]);
ret = drv_ampdu_action(local, sta->sdata, &params);
ht_dbg(sta->sdata, "Rx A-MPDU request on %pM tid %d result %d\n",
sta->sta.addr, tid, ret);
if (ret) {
kfree(tid_agg_rx->reorder_buf);
kfree(tid_agg_rx->reorder_time);
kfree(tid_agg_rx);
goto end;
}
tid_agg_rx->ssn = start_seq_num;
tid_agg_rx->head_seq_num = start_seq_num;
tid_agg_rx->buf_size = buf_size;
tid_agg_rx->timeout = timeout;
tid_agg_rx->stored_mpdu_num = 0;
tid_agg_rx->auto_seq = auto_seq;
tid_agg_rx->started = false;
tid_agg_rx->reorder_buf_filtered = 0;
status = WLAN_STATUS_SUCCESS;
rcu_assign_pointer(sta->ampdu_mlme.tid_rx[tid], tid_agg_rx);
if (timeout) {
mod_timer(&tid_agg_rx->session_timer, TU_TO_EXP_TIME(timeout));
tid_agg_rx->last_rx = jiffies;
}
end:
if (status == WLAN_STATUS_SUCCESS) {
__set_bit(tid, sta->ampdu_mlme.agg_session_valid);
__clear_bit(tid, sta->ampdu_mlme.unexpected_agg);
sta->ampdu_mlme.tid_rx_token[tid] = dialog_token;
}
mutex_unlock(&sta->ampdu_mlme.mtx);
end_no_lock:
if (tx)
ieee80211_send_addba_resp(sta->sdata, sta->sta.addr, tid,
dialog_token, status, 1, buf_size,
timeout);
}
void ieee80211_process_addba_request(struct ieee80211_local *local,
struct sta_info *sta,
struct ieee80211_mgmt *mgmt,
size_t len)
{
u16 capab, tid, timeout, ba_policy, buf_size, start_seq_num;
u8 dialog_token;
dialog_token = mgmt->u.action.u.addba_req.dialog_token;
timeout = le16_to_cpu(mgmt->u.action.u.addba_req.timeout);
start_seq_num =
le16_to_cpu(mgmt->u.action.u.addba_req.start_seq_num) >> 4;
capab = le16_to_cpu(mgmt->u.action.u.addba_req.capab);
ba_policy = (capab & IEEE80211_ADDBA_PARAM_POLICY_MASK) >> 1;
tid = (capab & IEEE80211_ADDBA_PARAM_TID_MASK) >> 2;
buf_size = (capab & IEEE80211_ADDBA_PARAM_BUF_SIZE_MASK) >> 6;
__ieee80211_start_rx_ba_session(sta, dialog_token, timeout,
start_seq_num, ba_policy, tid,
buf_size, true, false);
}
void ieee80211_manage_rx_ba_offl(struct ieee80211_vif *vif,
const u8 *addr, unsigned int bit)
{
struct ieee80211_sub_if_data *sdata = vif_to_sdata(vif);
struct ieee80211_local *local = sdata->local;
struct sta_info *sta;
rcu_read_lock();
sta = sta_info_get_bss(sdata, addr);
if (!sta)
goto unlock;
set_bit(bit, sta->ampdu_mlme.tid_rx_manage_offl);
ieee80211_queue_work(&local->hw, &sta->ampdu_mlme.work);
unlock:
rcu_read_unlock();
}
void ieee80211_rx_ba_timer_expired(struct ieee80211_vif *vif,
const u8 *addr, unsigned int tid)
{
struct ieee80211_sub_if_data *sdata = vif_to_sdata(vif);
struct ieee80211_local *local = sdata->local;
struct sta_info *sta;
rcu_read_lock();
sta = sta_info_get_bss(sdata, addr);
if (!sta)
goto unlock;
set_bit(tid, sta->ampdu_mlme.tid_rx_timer_expired);
ieee80211_queue_work(&local->hw, &sta->ampdu_mlme.work);
unlock:
rcu_read_unlock();
}
