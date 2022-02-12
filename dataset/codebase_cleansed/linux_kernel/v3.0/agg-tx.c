static void ieee80211_send_addba_request(struct ieee80211_sub_if_data *sdata,
const u8 *da, u16 tid,
u8 dialog_token, u16 start_seq_num,
u16 agg_size, u16 timeout)
{
struct ieee80211_local *local = sdata->local;
struct sk_buff *skb;
struct ieee80211_mgmt *mgmt;
u16 capab;
skb = dev_alloc_skb(sizeof(*mgmt) + local->hw.extra_tx_headroom);
if (!skb) {
printk(KERN_ERR "%s: failed to allocate buffer "
"for addba request frame\n", sdata->name);
return;
}
skb_reserve(skb, local->hw.extra_tx_headroom);
mgmt = (struct ieee80211_mgmt *) skb_put(skb, 24);
memset(mgmt, 0, 24);
memcpy(mgmt->da, da, ETH_ALEN);
memcpy(mgmt->sa, sdata->vif.addr, ETH_ALEN);
if (sdata->vif.type == NL80211_IFTYPE_AP ||
sdata->vif.type == NL80211_IFTYPE_AP_VLAN)
memcpy(mgmt->bssid, sdata->vif.addr, ETH_ALEN);
else if (sdata->vif.type == NL80211_IFTYPE_STATION)
memcpy(mgmt->bssid, sdata->u.mgd.bssid, ETH_ALEN);
mgmt->frame_control = cpu_to_le16(IEEE80211_FTYPE_MGMT |
IEEE80211_STYPE_ACTION);
skb_put(skb, 1 + sizeof(mgmt->u.action.u.addba_req));
mgmt->u.action.category = WLAN_CATEGORY_BACK;
mgmt->u.action.u.addba_req.action_code = WLAN_ACTION_ADDBA_REQ;
mgmt->u.action.u.addba_req.dialog_token = dialog_token;
capab = (u16)(1 << 1);
capab |= (u16)(tid << 2);
capab |= (u16)(agg_size << 6);
mgmt->u.action.u.addba_req.capab = cpu_to_le16(capab);
mgmt->u.action.u.addba_req.timeout = cpu_to_le16(timeout);
mgmt->u.action.u.addba_req.start_seq_num =
cpu_to_le16(start_seq_num << 4);
ieee80211_tx_skb(sdata, skb);
}
void ieee80211_send_bar(struct ieee80211_sub_if_data *sdata, u8 *ra, u16 tid, u16 ssn)
{
struct ieee80211_local *local = sdata->local;
struct sk_buff *skb;
struct ieee80211_bar *bar;
u16 bar_control = 0;
skb = dev_alloc_skb(sizeof(*bar) + local->hw.extra_tx_headroom);
if (!skb) {
printk(KERN_ERR "%s: failed to allocate buffer for "
"bar frame\n", sdata->name);
return;
}
skb_reserve(skb, local->hw.extra_tx_headroom);
bar = (struct ieee80211_bar *)skb_put(skb, sizeof(*bar));
memset(bar, 0, sizeof(*bar));
bar->frame_control = cpu_to_le16(IEEE80211_FTYPE_CTL |
IEEE80211_STYPE_BACK_REQ);
memcpy(bar->ra, ra, ETH_ALEN);
memcpy(bar->ta, sdata->vif.addr, ETH_ALEN);
bar_control |= (u16)IEEE80211_BAR_CTRL_ACK_POLICY_NORMAL;
bar_control |= (u16)IEEE80211_BAR_CTRL_CBMTID_COMPRESSED_BA;
bar_control |= (u16)(tid << 12);
bar->control = cpu_to_le16(bar_control);
bar->start_seq_num = cpu_to_le16(ssn);
IEEE80211_SKB_CB(skb)->flags |= IEEE80211_TX_INTFL_DONT_ENCRYPT;
ieee80211_tx_skb(sdata, skb);
}
void ieee80211_assign_tid_tx(struct sta_info *sta, int tid,
struct tid_ampdu_tx *tid_tx)
{
lockdep_assert_held(&sta->ampdu_mlme.mtx);
lockdep_assert_held(&sta->lock);
rcu_assign_pointer(sta->ampdu_mlme.tid_tx[tid], tid_tx);
}
int ___ieee80211_stop_tx_ba_session(struct sta_info *sta, u16 tid,
enum ieee80211_back_parties initiator,
bool tx)
{
struct ieee80211_local *local = sta->local;
struct tid_ampdu_tx *tid_tx;
int ret;
lockdep_assert_held(&sta->ampdu_mlme.mtx);
spin_lock_bh(&sta->lock);
tid_tx = rcu_dereference_protected_tid_tx(sta, tid);
if (!tid_tx) {
spin_unlock_bh(&sta->lock);
return -ENOENT;
}
if (test_bit(HT_AGG_STATE_WANT_START, &tid_tx->state)) {
ieee80211_assign_tid_tx(sta, tid, NULL);
spin_unlock_bh(&sta->lock);
kfree_rcu(tid_tx, rcu_head);
return 0;
}
spin_unlock_bh(&sta->lock);
#ifdef CONFIG_MAC80211_HT_DEBUG
printk(KERN_DEBUG "Tx BA session stop requested for %pM tid %u\n",
sta->sta.addr, tid);
#endif
set_bit(HT_AGG_STATE_STOPPING, &tid_tx->state);
del_timer_sync(&tid_tx->addba_resp_timer);
clear_bit(HT_AGG_STATE_OPERATIONAL, &tid_tx->state);
tid_tx->stop_initiator = initiator;
tid_tx->tx_stop = tx;
ret = drv_ampdu_action(local, sta->sdata,
IEEE80211_AMPDU_TX_STOP,
&sta->sta, tid, NULL, 0);
if (WARN_ON(ret)) {
}
return ret;
}
static void sta_addba_resp_timer_expired(unsigned long data)
{
u16 tid = *(u8 *)data;
struct sta_info *sta = container_of((void *)data,
struct sta_info, timer_to_tid[tid]);
struct tid_ampdu_tx *tid_tx;
rcu_read_lock();
tid_tx = rcu_dereference(sta->ampdu_mlme.tid_tx[tid]);
if (!tid_tx ||
test_bit(HT_AGG_STATE_RESPONSE_RECEIVED, &tid_tx->state)) {
rcu_read_unlock();
#ifdef CONFIG_MAC80211_HT_DEBUG
printk(KERN_DEBUG "timer expired on tid %d but we are not "
"(or no longer) expecting addBA response there\n",
tid);
#endif
return;
}
#ifdef CONFIG_MAC80211_HT_DEBUG
printk(KERN_DEBUG "addBA response timer expired on tid %d\n", tid);
#endif
ieee80211_stop_tx_ba_session(&sta->sta, tid);
rcu_read_unlock();
}
static inline int ieee80211_ac_from_tid(int tid)
{
return ieee802_1d_to_ac[tid & 7];
}
static void __acquires(agg_queue)
ieee80211_stop_queue_agg(struct ieee80211_local *local, int tid)
{
int queue = ieee80211_ac_from_tid(tid);
if (atomic_inc_return(&local->agg_queue_stop[queue]) == 1)
ieee80211_stop_queue_by_reason(
&local->hw, queue,
IEEE80211_QUEUE_STOP_REASON_AGGREGATION);
__acquire(agg_queue);
}
static void __releases(agg_queue)
ieee80211_wake_queue_agg(struct ieee80211_local *local, int tid)
{
int queue = ieee80211_ac_from_tid(tid);
if (atomic_dec_return(&local->agg_queue_stop[queue]) == 0)
ieee80211_wake_queue_by_reason(
&local->hw, queue,
IEEE80211_QUEUE_STOP_REASON_AGGREGATION);
__release(agg_queue);
}
void ieee80211_tx_ba_session_handle_start(struct sta_info *sta, int tid)
{
struct tid_ampdu_tx *tid_tx;
struct ieee80211_local *local = sta->local;
struct ieee80211_sub_if_data *sdata = sta->sdata;
u16 start_seq_num;
int ret;
tid_tx = rcu_dereference_protected_tid_tx(sta, tid);
ieee80211_stop_queue_agg(local, tid);
clear_bit(HT_AGG_STATE_WANT_START, &tid_tx->state);
synchronize_net();
start_seq_num = sta->tid_seq[tid] >> 4;
ret = drv_ampdu_action(local, sdata, IEEE80211_AMPDU_TX_START,
&sta->sta, tid, &start_seq_num, 0);
if (ret) {
#ifdef CONFIG_MAC80211_HT_DEBUG
printk(KERN_DEBUG "BA request denied - HW unavailable for"
" tid %d\n", tid);
#endif
spin_lock_bh(&sta->lock);
ieee80211_assign_tid_tx(sta, tid, NULL);
spin_unlock_bh(&sta->lock);
ieee80211_wake_queue_agg(local, tid);
kfree_rcu(tid_tx, rcu_head);
return;
}
ieee80211_wake_queue_agg(local, tid);
mod_timer(&tid_tx->addba_resp_timer, jiffies + ADDBA_RESP_INTERVAL);
#ifdef CONFIG_MAC80211_HT_DEBUG
printk(KERN_DEBUG "activated addBA response timer on tid %d\n", tid);
#endif
spin_lock_bh(&sta->lock);
sta->ampdu_mlme.addba_req_num[tid]++;
spin_unlock_bh(&sta->lock);
ieee80211_send_addba_request(sdata, sta->sta.addr, tid,
tid_tx->dialog_token, start_seq_num,
local->hw.max_tx_aggregation_subframes,
tid_tx->timeout);
}
int ieee80211_start_tx_ba_session(struct ieee80211_sta *pubsta, u16 tid,
u16 timeout)
{
struct sta_info *sta = container_of(pubsta, struct sta_info, sta);
struct ieee80211_sub_if_data *sdata = sta->sdata;
struct ieee80211_local *local = sdata->local;
struct tid_ampdu_tx *tid_tx;
int ret = 0;
trace_api_start_tx_ba_session(pubsta, tid);
if (WARN_ON(!local->ops->ampdu_action))
return -EINVAL;
if ((tid >= STA_TID_NUM) ||
!(local->hw.flags & IEEE80211_HW_AMPDU_AGGREGATION))
return -EINVAL;
#ifdef CONFIG_MAC80211_HT_DEBUG
printk(KERN_DEBUG "Open BA session requested for %pM tid %u\n",
pubsta->addr, tid);
#endif
if (sdata->vif.type != NL80211_IFTYPE_STATION &&
sdata->vif.type != NL80211_IFTYPE_AP_VLAN &&
sdata->vif.type != NL80211_IFTYPE_AP)
return -EINVAL;
if (test_sta_flags(sta, WLAN_STA_BLOCK_BA)) {
#ifdef CONFIG_MAC80211_HT_DEBUG
printk(KERN_DEBUG "BA sessions blocked. "
"Denying BA session request\n");
#endif
return -EINVAL;
}
spin_lock_bh(&sta->lock);
if (sta->ampdu_mlme.addba_req_num[tid] > HT_AGG_MAX_RETRIES) {
ret = -EBUSY;
goto err_unlock_sta;
}
tid_tx = rcu_dereference_protected_tid_tx(sta, tid);
if (tid_tx || sta->ampdu_mlme.tid_start_tx[tid]) {
#ifdef CONFIG_MAC80211_HT_DEBUG
printk(KERN_DEBUG "BA request denied - session is not "
"idle on tid %u\n", tid);
#endif
ret = -EAGAIN;
goto err_unlock_sta;
}
tid_tx = kzalloc(sizeof(struct tid_ampdu_tx), GFP_ATOMIC);
if (!tid_tx) {
#ifdef CONFIG_MAC80211_HT_DEBUG
if (net_ratelimit())
printk(KERN_ERR "allocate tx mlme to tid %d failed\n",
tid);
#endif
ret = -ENOMEM;
goto err_unlock_sta;
}
skb_queue_head_init(&tid_tx->pending);
__set_bit(HT_AGG_STATE_WANT_START, &tid_tx->state);
tid_tx->timeout = timeout;
tid_tx->addba_resp_timer.function = sta_addba_resp_timer_expired;
tid_tx->addba_resp_timer.data = (unsigned long)&sta->timer_to_tid[tid];
init_timer(&tid_tx->addba_resp_timer);
sta->ampdu_mlme.dialog_token_allocator++;
tid_tx->dialog_token = sta->ampdu_mlme.dialog_token_allocator;
sta->ampdu_mlme.tid_start_tx[tid] = tid_tx;
ieee80211_queue_work(&local->hw, &sta->ampdu_mlme.work);
err_unlock_sta:
spin_unlock_bh(&sta->lock);
return ret;
}
static void __acquires(agg_queue)
ieee80211_agg_splice_packets(struct ieee80211_local *local,
struct tid_ampdu_tx *tid_tx, u16 tid)
{
int queue = ieee80211_ac_from_tid(tid);
unsigned long flags;
ieee80211_stop_queue_agg(local, tid);
if (WARN(!tid_tx, "TID %d gone but expected when splicing aggregates"
" from the pending queue\n", tid))
return;
if (!skb_queue_empty(&tid_tx->pending)) {
spin_lock_irqsave(&local->queue_stop_reason_lock, flags);
skb_queue_splice_tail_init(&tid_tx->pending,
&local->pending[queue]);
spin_unlock_irqrestore(&local->queue_stop_reason_lock, flags);
}
}
static void __releases(agg_queue)
ieee80211_agg_splice_finish(struct ieee80211_local *local, u16 tid)
{
ieee80211_wake_queue_agg(local, tid);
}
static void ieee80211_agg_tx_operational(struct ieee80211_local *local,
struct sta_info *sta, u16 tid)
{
struct tid_ampdu_tx *tid_tx;
lockdep_assert_held(&sta->ampdu_mlme.mtx);
tid_tx = rcu_dereference_protected_tid_tx(sta, tid);
#ifdef CONFIG_MAC80211_HT_DEBUG
printk(KERN_DEBUG "Aggregation is on for tid %d\n", tid);
#endif
drv_ampdu_action(local, sta->sdata,
IEEE80211_AMPDU_TX_OPERATIONAL,
&sta->sta, tid, NULL, tid_tx->buf_size);
spin_lock_bh(&sta->lock);
ieee80211_agg_splice_packets(local, tid_tx, tid);
set_bit(HT_AGG_STATE_OPERATIONAL, &tid_tx->state);
ieee80211_agg_splice_finish(local, tid);
spin_unlock_bh(&sta->lock);
}
void ieee80211_start_tx_ba_cb(struct ieee80211_vif *vif, u8 *ra, u16 tid)
{
struct ieee80211_sub_if_data *sdata = vif_to_sdata(vif);
struct ieee80211_local *local = sdata->local;
struct sta_info *sta;
struct tid_ampdu_tx *tid_tx;
trace_api_start_tx_ba_cb(sdata, ra, tid);
if (tid >= STA_TID_NUM) {
#ifdef CONFIG_MAC80211_HT_DEBUG
printk(KERN_DEBUG "Bad TID value: tid = %d (>= %d)\n",
tid, STA_TID_NUM);
#endif
return;
}
mutex_lock(&local->sta_mtx);
sta = sta_info_get(sdata, ra);
if (!sta) {
mutex_unlock(&local->sta_mtx);
#ifdef CONFIG_MAC80211_HT_DEBUG
printk(KERN_DEBUG "Could not find station: %pM\n", ra);
#endif
return;
}
mutex_lock(&sta->ampdu_mlme.mtx);
tid_tx = rcu_dereference_protected_tid_tx(sta, tid);
if (WARN_ON(!tid_tx)) {
#ifdef CONFIG_MAC80211_HT_DEBUG
printk(KERN_DEBUG "addBA was not requested!\n");
#endif
goto unlock;
}
if (WARN_ON(test_and_set_bit(HT_AGG_STATE_DRV_READY, &tid_tx->state)))
goto unlock;
if (test_bit(HT_AGG_STATE_RESPONSE_RECEIVED, &tid_tx->state))
ieee80211_agg_tx_operational(local, sta, tid);
unlock:
mutex_unlock(&sta->ampdu_mlme.mtx);
mutex_unlock(&local->sta_mtx);
}
void ieee80211_start_tx_ba_cb_irqsafe(struct ieee80211_vif *vif,
const u8 *ra, u16 tid)
{
struct ieee80211_sub_if_data *sdata = vif_to_sdata(vif);
struct ieee80211_local *local = sdata->local;
struct ieee80211_ra_tid *ra_tid;
struct sk_buff *skb = dev_alloc_skb(0);
if (unlikely(!skb)) {
#ifdef CONFIG_MAC80211_HT_DEBUG
if (net_ratelimit())
printk(KERN_WARNING "%s: Not enough memory, "
"dropping start BA session", sdata->name);
#endif
return;
}
ra_tid = (struct ieee80211_ra_tid *) &skb->cb;
memcpy(&ra_tid->ra, ra, ETH_ALEN);
ra_tid->tid = tid;
skb->pkt_type = IEEE80211_SDATA_QUEUE_AGG_START;
skb_queue_tail(&sdata->skb_queue, skb);
ieee80211_queue_work(&local->hw, &sdata->work);
}
int __ieee80211_stop_tx_ba_session(struct sta_info *sta, u16 tid,
enum ieee80211_back_parties initiator,
bool tx)
{
int ret;
mutex_lock(&sta->ampdu_mlme.mtx);
ret = ___ieee80211_stop_tx_ba_session(sta, tid, initiator, tx);
mutex_unlock(&sta->ampdu_mlme.mtx);
return ret;
}
int ieee80211_stop_tx_ba_session(struct ieee80211_sta *pubsta, u16 tid)
{
struct sta_info *sta = container_of(pubsta, struct sta_info, sta);
struct ieee80211_sub_if_data *sdata = sta->sdata;
struct ieee80211_local *local = sdata->local;
struct tid_ampdu_tx *tid_tx;
int ret = 0;
trace_api_stop_tx_ba_session(pubsta, tid);
if (!local->ops->ampdu_action)
return -EINVAL;
if (tid >= STA_TID_NUM)
return -EINVAL;
spin_lock_bh(&sta->lock);
tid_tx = rcu_dereference_protected_tid_tx(sta, tid);
if (!tid_tx) {
ret = -ENOENT;
goto unlock;
}
if (test_bit(HT_AGG_STATE_STOPPING, &tid_tx->state)) {
ret = 0;
goto unlock;
}
set_bit(HT_AGG_STATE_WANT_STOP, &tid_tx->state);
ieee80211_queue_work(&local->hw, &sta->ampdu_mlme.work);
unlock:
spin_unlock_bh(&sta->lock);
return ret;
}
void ieee80211_stop_tx_ba_cb(struct ieee80211_vif *vif, u8 *ra, u8 tid)
{
struct ieee80211_sub_if_data *sdata = vif_to_sdata(vif);
struct ieee80211_local *local = sdata->local;
struct sta_info *sta;
struct tid_ampdu_tx *tid_tx;
trace_api_stop_tx_ba_cb(sdata, ra, tid);
if (tid >= STA_TID_NUM) {
#ifdef CONFIG_MAC80211_HT_DEBUG
printk(KERN_DEBUG "Bad TID value: tid = %d (>= %d)\n",
tid, STA_TID_NUM);
#endif
return;
}
#ifdef CONFIG_MAC80211_HT_DEBUG
printk(KERN_DEBUG "Stopping Tx BA session for %pM tid %d\n",
ra, tid);
#endif
mutex_lock(&local->sta_mtx);
sta = sta_info_get(sdata, ra);
if (!sta) {
#ifdef CONFIG_MAC80211_HT_DEBUG
printk(KERN_DEBUG "Could not find station: %pM\n", ra);
#endif
goto unlock;
}
mutex_lock(&sta->ampdu_mlme.mtx);
spin_lock_bh(&sta->lock);
tid_tx = rcu_dereference_protected_tid_tx(sta, tid);
if (!tid_tx || !test_bit(HT_AGG_STATE_STOPPING, &tid_tx->state)) {
#ifdef CONFIG_MAC80211_HT_DEBUG
printk(KERN_DEBUG "unexpected callback to A-MPDU stop\n");
#endif
goto unlock_sta;
}
if (tid_tx->stop_initiator == WLAN_BACK_INITIATOR && tid_tx->tx_stop)
ieee80211_send_delba(sta->sdata, ra, tid,
WLAN_BACK_INITIATOR, WLAN_REASON_QSTA_NOT_USE);
ieee80211_agg_splice_packets(local, tid_tx, tid);
ieee80211_assign_tid_tx(sta, tid, NULL);
ieee80211_agg_splice_finish(local, tid);
kfree_rcu(tid_tx, rcu_head);
unlock_sta:
spin_unlock_bh(&sta->lock);
mutex_unlock(&sta->ampdu_mlme.mtx);
unlock:
mutex_unlock(&local->sta_mtx);
}
void ieee80211_stop_tx_ba_cb_irqsafe(struct ieee80211_vif *vif,
const u8 *ra, u16 tid)
{
struct ieee80211_sub_if_data *sdata = vif_to_sdata(vif);
struct ieee80211_local *local = sdata->local;
struct ieee80211_ra_tid *ra_tid;
struct sk_buff *skb = dev_alloc_skb(0);
if (unlikely(!skb)) {
#ifdef CONFIG_MAC80211_HT_DEBUG
if (net_ratelimit())
printk(KERN_WARNING "%s: Not enough memory, "
"dropping stop BA session", sdata->name);
#endif
return;
}
ra_tid = (struct ieee80211_ra_tid *) &skb->cb;
memcpy(&ra_tid->ra, ra, ETH_ALEN);
ra_tid->tid = tid;
skb->pkt_type = IEEE80211_SDATA_QUEUE_AGG_STOP;
skb_queue_tail(&sdata->skb_queue, skb);
ieee80211_queue_work(&local->hw, &sdata->work);
}
void ieee80211_process_addba_resp(struct ieee80211_local *local,
struct sta_info *sta,
struct ieee80211_mgmt *mgmt,
size_t len)
{
struct tid_ampdu_tx *tid_tx;
u16 capab, tid;
u8 buf_size;
capab = le16_to_cpu(mgmt->u.action.u.addba_resp.capab);
tid = (capab & IEEE80211_ADDBA_PARAM_TID_MASK) >> 2;
buf_size = (capab & IEEE80211_ADDBA_PARAM_BUF_SIZE_MASK) >> 6;
mutex_lock(&sta->ampdu_mlme.mtx);
tid_tx = rcu_dereference_protected_tid_tx(sta, tid);
if (!tid_tx)
goto out;
if (mgmt->u.action.u.addba_resp.dialog_token != tid_tx->dialog_token) {
#ifdef CONFIG_MAC80211_HT_DEBUG
printk(KERN_DEBUG "wrong addBA response token, tid %d\n", tid);
#endif
goto out;
}
del_timer(&tid_tx->addba_resp_timer);
#ifdef CONFIG_MAC80211_HT_DEBUG
printk(KERN_DEBUG "switched off addBA timer for tid %d\n", tid);
#endif
if (le16_to_cpu(mgmt->u.action.u.addba_resp.status)
== WLAN_STATUS_SUCCESS) {
if (!buf_size)
goto out;
if (test_and_set_bit(HT_AGG_STATE_RESPONSE_RECEIVED,
&tid_tx->state)) {
goto out;
}
tid_tx->buf_size = buf_size;
if (test_bit(HT_AGG_STATE_DRV_READY, &tid_tx->state))
ieee80211_agg_tx_operational(local, sta, tid);
sta->ampdu_mlme.addba_req_num[tid] = 0;
} else {
___ieee80211_stop_tx_ba_session(sta, tid, WLAN_BACK_INITIATOR,
true);
}
out:
mutex_unlock(&sta->ampdu_mlme.mtx);
}
