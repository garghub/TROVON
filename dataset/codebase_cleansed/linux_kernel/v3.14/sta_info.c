static int sta_info_hash_del(struct ieee80211_local *local,
struct sta_info *sta)
{
struct sta_info *s;
s = rcu_dereference_protected(local->sta_hash[STA_HASH(sta->sta.addr)],
lockdep_is_held(&local->sta_mtx));
if (!s)
return -ENOENT;
if (s == sta) {
rcu_assign_pointer(local->sta_hash[STA_HASH(sta->sta.addr)],
s->hnext);
return 0;
}
while (rcu_access_pointer(s->hnext) &&
rcu_access_pointer(s->hnext) != sta)
s = rcu_dereference_protected(s->hnext,
lockdep_is_held(&local->sta_mtx));
if (rcu_access_pointer(s->hnext)) {
rcu_assign_pointer(s->hnext, sta->hnext);
return 0;
}
return -ENOENT;
}
static void __cleanup_single_sta(struct sta_info *sta)
{
int ac, i;
struct tid_ampdu_tx *tid_tx;
struct ieee80211_sub_if_data *sdata = sta->sdata;
struct ieee80211_local *local = sdata->local;
struct ps_data *ps;
if (test_sta_flag(sta, WLAN_STA_PS_STA) ||
test_sta_flag(sta, WLAN_STA_PS_DRIVER)) {
if (sta->sdata->vif.type == NL80211_IFTYPE_AP ||
sta->sdata->vif.type == NL80211_IFTYPE_AP_VLAN)
ps = &sdata->bss->ps;
else if (ieee80211_vif_is_mesh(&sdata->vif))
ps = &sdata->u.mesh.ps;
else
return;
clear_sta_flag(sta, WLAN_STA_PS_STA);
clear_sta_flag(sta, WLAN_STA_PS_DRIVER);
atomic_dec(&ps->num_sta_ps);
sta_info_recalc_tim(sta);
}
for (ac = 0; ac < IEEE80211_NUM_ACS; ac++) {
local->total_ps_buffered -= skb_queue_len(&sta->ps_tx_buf[ac]);
ieee80211_purge_tx_queue(&local->hw, &sta->ps_tx_buf[ac]);
ieee80211_purge_tx_queue(&local->hw, &sta->tx_filtered[ac]);
}
if (ieee80211_vif_is_mesh(&sdata->vif))
mesh_sta_cleanup(sta);
cancel_work_sync(&sta->drv_unblock_wk);
for (i = 0; i < IEEE80211_NUM_TIDS; i++) {
kfree(sta->ampdu_mlme.tid_start_tx[i]);
tid_tx = rcu_dereference_raw(sta->ampdu_mlme.tid_tx[i]);
if (!tid_tx)
continue;
ieee80211_purge_tx_queue(&local->hw, &tid_tx->pending);
kfree(tid_tx);
}
}
static void cleanup_single_sta(struct sta_info *sta)
{
struct ieee80211_sub_if_data *sdata = sta->sdata;
struct ieee80211_local *local = sdata->local;
__cleanup_single_sta(sta);
sta_info_free(local, sta);
}
struct sta_info *sta_info_get(struct ieee80211_sub_if_data *sdata,
const u8 *addr)
{
struct ieee80211_local *local = sdata->local;
struct sta_info *sta;
sta = rcu_dereference_check(local->sta_hash[STA_HASH(addr)],
lockdep_is_held(&local->sta_mtx));
while (sta) {
if (sta->sdata == sdata &&
ether_addr_equal(sta->sta.addr, addr))
break;
sta = rcu_dereference_check(sta->hnext,
lockdep_is_held(&local->sta_mtx));
}
return sta;
}
struct sta_info *sta_info_get_bss(struct ieee80211_sub_if_data *sdata,
const u8 *addr)
{
struct ieee80211_local *local = sdata->local;
struct sta_info *sta;
sta = rcu_dereference_check(local->sta_hash[STA_HASH(addr)],
lockdep_is_held(&local->sta_mtx));
while (sta) {
if ((sta->sdata == sdata ||
(sta->sdata->bss && sta->sdata->bss == sdata->bss)) &&
ether_addr_equal(sta->sta.addr, addr))
break;
sta = rcu_dereference_check(sta->hnext,
lockdep_is_held(&local->sta_mtx));
}
return sta;
}
struct sta_info *sta_info_get_by_idx(struct ieee80211_sub_if_data *sdata,
int idx)
{
struct ieee80211_local *local = sdata->local;
struct sta_info *sta;
int i = 0;
list_for_each_entry_rcu(sta, &local->sta_list, list) {
if (sdata != sta->sdata)
continue;
if (i < idx) {
++i;
continue;
}
return sta;
}
return NULL;
}
void sta_info_free(struct ieee80211_local *local, struct sta_info *sta)
{
int i;
if (sta->rate_ctrl)
rate_control_free_sta(sta);
if (sta->tx_lat) {
for (i = 0; i < IEEE80211_NUM_TIDS; i++)
kfree(sta->tx_lat[i].bins);
kfree(sta->tx_lat);
}
sta_dbg(sta->sdata, "Destroyed STA %pM\n", sta->sta.addr);
kfree(sta);
}
static void sta_info_hash_add(struct ieee80211_local *local,
struct sta_info *sta)
{
lockdep_assert_held(&local->sta_mtx);
sta->hnext = local->sta_hash[STA_HASH(sta->sta.addr)];
rcu_assign_pointer(local->sta_hash[STA_HASH(sta->sta.addr)], sta);
}
static void sta_unblock(struct work_struct *wk)
{
struct sta_info *sta;
sta = container_of(wk, struct sta_info, drv_unblock_wk);
if (sta->dead)
return;
if (!test_sta_flag(sta, WLAN_STA_PS_STA)) {
local_bh_disable();
ieee80211_sta_ps_deliver_wakeup(sta);
local_bh_enable();
} else if (test_and_clear_sta_flag(sta, WLAN_STA_PSPOLL)) {
clear_sta_flag(sta, WLAN_STA_PS_DRIVER);
local_bh_disable();
ieee80211_sta_ps_deliver_poll_response(sta);
local_bh_enable();
} else if (test_and_clear_sta_flag(sta, WLAN_STA_UAPSD)) {
clear_sta_flag(sta, WLAN_STA_PS_DRIVER);
local_bh_disable();
ieee80211_sta_ps_deliver_uapsd(sta);
local_bh_enable();
} else
clear_sta_flag(sta, WLAN_STA_PS_DRIVER);
}
static int sta_prepare_rate_control(struct ieee80211_local *local,
struct sta_info *sta, gfp_t gfp)
{
if (local->hw.flags & IEEE80211_HW_HAS_RATE_CONTROL)
return 0;
sta->rate_ctrl = local->rate_ctrl;
sta->rate_ctrl_priv = rate_control_alloc_sta(sta->rate_ctrl,
&sta->sta, gfp);
if (!sta->rate_ctrl_priv)
return -ENOMEM;
return 0;
}
struct sta_info *sta_info_alloc(struct ieee80211_sub_if_data *sdata,
const u8 *addr, gfp_t gfp)
{
struct ieee80211_local *local = sdata->local;
struct sta_info *sta;
struct timespec uptime;
struct ieee80211_tx_latency_bin_ranges *tx_latency;
int i;
sta = kzalloc(sizeof(*sta) + local->hw.sta_data_size, gfp);
if (!sta)
return NULL;
rcu_read_lock();
tx_latency = rcu_dereference(local->tx_latency);
if (tx_latency) {
sta->tx_lat = kzalloc(IEEE80211_NUM_TIDS *
sizeof(struct ieee80211_tx_latency_stat),
GFP_ATOMIC);
if (!sta->tx_lat) {
rcu_read_unlock();
goto free;
}
if (tx_latency->n_ranges) {
for (i = 0; i < IEEE80211_NUM_TIDS; i++) {
sta->tx_lat[i].bin_count =
tx_latency->n_ranges + 1;
sta->tx_lat[i].bins =
kcalloc(sta->tx_lat[i].bin_count,
sizeof(u32), GFP_ATOMIC);
if (!sta->tx_lat[i].bins) {
rcu_read_unlock();
goto free;
}
}
}
}
rcu_read_unlock();
spin_lock_init(&sta->lock);
spin_lock_init(&sta->ps_lock);
INIT_WORK(&sta->drv_unblock_wk, sta_unblock);
INIT_WORK(&sta->ampdu_mlme.work, ieee80211_ba_session_work);
mutex_init(&sta->ampdu_mlme.mtx);
#ifdef CONFIG_MAC80211_MESH
if (ieee80211_vif_is_mesh(&sdata->vif) &&
!sdata->u.mesh.user_mpm)
init_timer(&sta->plink_timer);
sta->nonpeer_pm = NL80211_MESH_POWER_ACTIVE;
#endif
memcpy(sta->sta.addr, addr, ETH_ALEN);
sta->local = local;
sta->sdata = sdata;
sta->last_rx = jiffies;
sta->sta_state = IEEE80211_STA_NONE;
do_posix_clock_monotonic_gettime(&uptime);
sta->last_connected = uptime.tv_sec;
ewma_init(&sta->avg_signal, 1024, 8);
for (i = 0; i < ARRAY_SIZE(sta->chain_signal_avg); i++)
ewma_init(&sta->chain_signal_avg[i], 1024, 8);
if (sta_prepare_rate_control(local, sta, gfp))
goto free;
for (i = 0; i < IEEE80211_NUM_TIDS; i++) {
sta->timer_to_tid[i] = i;
}
for (i = 0; i < IEEE80211_NUM_ACS; i++) {
skb_queue_head_init(&sta->ps_tx_buf[i]);
skb_queue_head_init(&sta->tx_filtered[i]);
}
for (i = 0; i < IEEE80211_NUM_TIDS; i++)
sta->last_seq_ctrl[i] = cpu_to_le16(USHRT_MAX);
sta->sta.smps_mode = IEEE80211_SMPS_OFF;
if (sdata->vif.type == NL80211_IFTYPE_AP ||
sdata->vif.type == NL80211_IFTYPE_AP_VLAN) {
struct ieee80211_supported_band *sband =
local->hw.wiphy->bands[ieee80211_get_sdata_band(sdata)];
u8 smps = (sband->ht_cap.cap & IEEE80211_HT_CAP_SM_PS) >>
IEEE80211_HT_CAP_SM_PS_SHIFT;
switch (smps) {
case WLAN_HT_SMPS_CONTROL_DISABLED:
sta->known_smps_mode = IEEE80211_SMPS_OFF;
break;
case WLAN_HT_SMPS_CONTROL_STATIC:
sta->known_smps_mode = IEEE80211_SMPS_STATIC;
break;
case WLAN_HT_SMPS_CONTROL_DYNAMIC:
sta->known_smps_mode = IEEE80211_SMPS_DYNAMIC;
break;
default:
WARN_ON(1);
}
}
sta_dbg(sdata, "Allocated STA %pM\n", sta->sta.addr);
return sta;
free:
if (sta->tx_lat) {
for (i = 0; i < IEEE80211_NUM_TIDS; i++)
kfree(sta->tx_lat[i].bins);
kfree(sta->tx_lat);
}
kfree(sta);
return NULL;
}
static int sta_info_insert_check(struct sta_info *sta)
{
struct ieee80211_sub_if_data *sdata = sta->sdata;
if (unlikely(!ieee80211_sdata_running(sdata)))
return -ENETDOWN;
if (WARN_ON(ether_addr_equal(sta->sta.addr, sdata->vif.addr) ||
is_multicast_ether_addr(sta->sta.addr)))
return -EINVAL;
return 0;
}
static int sta_info_insert_drv_state(struct ieee80211_local *local,
struct ieee80211_sub_if_data *sdata,
struct sta_info *sta)
{
enum ieee80211_sta_state state;
int err = 0;
for (state = IEEE80211_STA_NOTEXIST; state < sta->sta_state; state++) {
err = drv_sta_state(local, sdata, sta, state, state + 1);
if (err)
break;
}
if (!err) {
if (!local->ops->sta_add)
sta->uploaded = true;
return 0;
}
if (sdata->vif.type == NL80211_IFTYPE_ADHOC) {
sdata_info(sdata,
"failed to move IBSS STA %pM to state %d (%d) - keeping it anyway\n",
sta->sta.addr, state + 1, err);
err = 0;
}
for (; state > IEEE80211_STA_NOTEXIST; state--)
WARN_ON(drv_sta_state(local, sdata, sta, state, state - 1));
return err;
}
static int sta_info_insert_finish(struct sta_info *sta) __acquires(RCU)
{
struct ieee80211_local *local = sta->local;
struct ieee80211_sub_if_data *sdata = sta->sdata;
struct station_info sinfo;
int err = 0;
lockdep_assert_held(&local->sta_mtx);
if (sta_info_get_bss(sdata, sta->sta.addr)) {
err = -EEXIST;
goto out_err;
}
local->num_sta++;
local->sta_generation++;
smp_mb();
set_sta_flag(sta, WLAN_STA_BLOCK_BA);
sta_info_hash_add(local, sta);
list_add_rcu(&sta->list, &local->sta_list);
err = sta_info_insert_drv_state(local, sdata, sta);
if (err)
goto out_remove;
set_sta_flag(sta, WLAN_STA_INSERTED);
clear_sta_flag(sta, WLAN_STA_BLOCK_BA);
ieee80211_recalc_min_chandef(sdata);
ieee80211_sta_debugfs_add(sta);
rate_control_add_sta_debugfs(sta);
memset(&sinfo, 0, sizeof(sinfo));
sinfo.filled = 0;
sinfo.generation = local->sta_generation;
cfg80211_new_sta(sdata->dev, sta->sta.addr, &sinfo, GFP_KERNEL);
sta_dbg(sdata, "Inserted STA %pM\n", sta->sta.addr);
rcu_read_lock();
mutex_unlock(&local->sta_mtx);
if (ieee80211_vif_is_mesh(&sdata->vif))
mesh_accept_plinks_update(sdata);
return 0;
out_remove:
sta_info_hash_del(local, sta);
list_del_rcu(&sta->list);
local->num_sta--;
synchronize_net();
__cleanup_single_sta(sta);
out_err:
mutex_unlock(&local->sta_mtx);
rcu_read_lock();
return err;
}
int sta_info_insert_rcu(struct sta_info *sta) __acquires(RCU)
{
struct ieee80211_local *local = sta->local;
int err = 0;
might_sleep();
err = sta_info_insert_check(sta);
if (err) {
rcu_read_lock();
goto out_free;
}
mutex_lock(&local->sta_mtx);
err = sta_info_insert_finish(sta);
if (err)
goto out_free;
return 0;
out_free:
BUG_ON(!err);
sta_info_free(local, sta);
return err;
}
int sta_info_insert(struct sta_info *sta)
{
int err = sta_info_insert_rcu(sta);
rcu_read_unlock();
return err;
}
static inline void __bss_tim_set(u8 *tim, u16 id)
{
tim[id / 8] |= (1 << (id % 8));
}
static inline void __bss_tim_clear(u8 *tim, u16 id)
{
tim[id / 8] &= ~(1 << (id % 8));
}
static inline bool __bss_tim_get(u8 *tim, u16 id)
{
return tim[id / 8] & (1 << (id % 8));
}
static unsigned long ieee80211_tids_for_ac(int ac)
{
switch (ac) {
case IEEE80211_AC_VO:
return BIT(6) | BIT(7);
case IEEE80211_AC_VI:
return BIT(4) | BIT(5);
case IEEE80211_AC_BE:
return BIT(0) | BIT(3);
case IEEE80211_AC_BK:
return BIT(1) | BIT(2);
default:
WARN_ON(1);
return 0;
}
}
void sta_info_recalc_tim(struct sta_info *sta)
{
struct ieee80211_local *local = sta->local;
struct ps_data *ps;
bool indicate_tim = false;
u8 ignore_for_tim = sta->sta.uapsd_queues;
int ac;
u16 id;
if (sta->sdata->vif.type == NL80211_IFTYPE_AP ||
sta->sdata->vif.type == NL80211_IFTYPE_AP_VLAN) {
if (WARN_ON_ONCE(!sta->sdata->bss))
return;
ps = &sta->sdata->bss->ps;
id = sta->sta.aid;
#ifdef CONFIG_MAC80211_MESH
} else if (ieee80211_vif_is_mesh(&sta->sdata->vif)) {
ps = &sta->sdata->u.mesh.ps;
id = sta->plid % (IEEE80211_MAX_AID + 1);
#endif
} else {
return;
}
if (local->hw.flags & IEEE80211_HW_AP_LINK_PS)
return;
if (sta->dead)
goto done;
if (ignore_for_tim == BIT(IEEE80211_NUM_ACS) - 1)
ignore_for_tim = 0;
for (ac = 0; ac < IEEE80211_NUM_ACS; ac++) {
unsigned long tids;
if (ignore_for_tim & BIT(ac))
continue;
indicate_tim |= !skb_queue_empty(&sta->tx_filtered[ac]) ||
!skb_queue_empty(&sta->ps_tx_buf[ac]);
if (indicate_tim)
break;
tids = ieee80211_tids_for_ac(ac);
indicate_tim |=
sta->driver_buffered_tids & tids;
}
done:
spin_lock_bh(&local->tim_lock);
if (indicate_tim == __bss_tim_get(ps->tim, id))
goto out_unlock;
if (indicate_tim)
__bss_tim_set(ps->tim, id);
else
__bss_tim_clear(ps->tim, id);
if (local->ops->set_tim) {
local->tim_in_locked_section = true;
drv_set_tim(local, &sta->sta, indicate_tim);
local->tim_in_locked_section = false;
}
out_unlock:
spin_unlock_bh(&local->tim_lock);
}
static bool sta_info_buffer_expired(struct sta_info *sta, struct sk_buff *skb)
{
struct ieee80211_tx_info *info;
int timeout;
if (!skb)
return false;
info = IEEE80211_SKB_CB(skb);
timeout = (sta->listen_interval *
sta->sdata->vif.bss_conf.beacon_int *
32 / 15625) * HZ;
if (timeout < STA_TX_BUFFER_EXPIRE)
timeout = STA_TX_BUFFER_EXPIRE;
return time_after(jiffies, info->control.jiffies + timeout);
}
static bool sta_info_cleanup_expire_buffered_ac(struct ieee80211_local *local,
struct sta_info *sta, int ac)
{
unsigned long flags;
struct sk_buff *skb;
for (;;) {
spin_lock_irqsave(&sta->tx_filtered[ac].lock, flags);
skb = skb_peek(&sta->tx_filtered[ac]);
if (sta_info_buffer_expired(sta, skb))
skb = __skb_dequeue(&sta->tx_filtered[ac]);
else
skb = NULL;
spin_unlock_irqrestore(&sta->tx_filtered[ac].lock, flags);
if (!skb)
break;
ieee80211_free_txskb(&local->hw, skb);
}
for (;;) {
spin_lock_irqsave(&sta->ps_tx_buf[ac].lock, flags);
skb = skb_peek(&sta->ps_tx_buf[ac]);
if (sta_info_buffer_expired(sta, skb))
skb = __skb_dequeue(&sta->ps_tx_buf[ac]);
else
skb = NULL;
spin_unlock_irqrestore(&sta->ps_tx_buf[ac].lock, flags);
if (!skb)
break;
local->total_ps_buffered--;
ps_dbg(sta->sdata, "Buffered frame expired (STA %pM)\n",
sta->sta.addr);
ieee80211_free_txskb(&local->hw, skb);
}
sta_info_recalc_tim(sta);
return !(skb_queue_empty(&sta->ps_tx_buf[ac]) &&
skb_queue_empty(&sta->tx_filtered[ac]));
}
static bool sta_info_cleanup_expire_buffered(struct ieee80211_local *local,
struct sta_info *sta)
{
bool have_buffered = false;
int ac;
if (!sta->sdata->bss &&
!ieee80211_vif_is_mesh(&sta->sdata->vif))
return false;
for (ac = 0; ac < IEEE80211_NUM_ACS; ac++)
have_buffered |=
sta_info_cleanup_expire_buffered_ac(local, sta, ac);
return have_buffered;
}
static int __must_check __sta_info_destroy_part1(struct sta_info *sta)
{
struct ieee80211_local *local;
struct ieee80211_sub_if_data *sdata;
int ret;
might_sleep();
if (!sta)
return -ENOENT;
local = sta->local;
sdata = sta->sdata;
lockdep_assert_held(&local->sta_mtx);
set_sta_flag(sta, WLAN_STA_BLOCK_BA);
ieee80211_sta_tear_down_BA_sessions(sta, AGG_STOP_DESTROY_STA);
ret = sta_info_hash_del(local, sta);
if (WARN_ON(ret))
return ret;
list_del_rcu(&sta->list);
drv_sta_pre_rcu_remove(local, sta->sdata, sta);
if (sdata->vif.type == NL80211_IFTYPE_AP_VLAN &&
rcu_access_pointer(sdata->u.vlan.sta) == sta)
RCU_INIT_POINTER(sdata->u.vlan.sta, NULL);
return 0;
}
static void __sta_info_destroy_part2(struct sta_info *sta)
{
struct ieee80211_local *local = sta->local;
struct ieee80211_sub_if_data *sdata = sta->sdata;
int ret;
might_sleep();
lockdep_assert_held(&local->sta_mtx);
ieee80211_free_sta_keys(local, sta);
sta->dead = true;
local->num_sta--;
local->sta_generation++;
while (sta->sta_state > IEEE80211_STA_NONE) {
ret = sta_info_move_state(sta, sta->sta_state - 1);
if (ret) {
WARN_ON_ONCE(1);
break;
}
}
if (sta->uploaded) {
ret = drv_sta_state(local, sdata, sta, IEEE80211_STA_NONE,
IEEE80211_STA_NOTEXIST);
WARN_ON_ONCE(ret != 0);
}
sta_dbg(sdata, "Removed STA %pM\n", sta->sta.addr);
cfg80211_del_sta(sdata->dev, sta->sta.addr, GFP_KERNEL);
rate_control_remove_sta_debugfs(sta);
ieee80211_sta_debugfs_remove(sta);
ieee80211_recalc_min_chandef(sdata);
cleanup_single_sta(sta);
}
int __must_check __sta_info_destroy(struct sta_info *sta)
{
int err = __sta_info_destroy_part1(sta);
if (err)
return err;
synchronize_net();
__sta_info_destroy_part2(sta);
return 0;
}
int sta_info_destroy_addr(struct ieee80211_sub_if_data *sdata, const u8 *addr)
{
struct sta_info *sta;
int ret;
mutex_lock(&sdata->local->sta_mtx);
sta = sta_info_get(sdata, addr);
ret = __sta_info_destroy(sta);
mutex_unlock(&sdata->local->sta_mtx);
return ret;
}
int sta_info_destroy_addr_bss(struct ieee80211_sub_if_data *sdata,
const u8 *addr)
{
struct sta_info *sta;
int ret;
mutex_lock(&sdata->local->sta_mtx);
sta = sta_info_get_bss(sdata, addr);
ret = __sta_info_destroy(sta);
mutex_unlock(&sdata->local->sta_mtx);
return ret;
}
static void sta_info_cleanup(unsigned long data)
{
struct ieee80211_local *local = (struct ieee80211_local *) data;
struct sta_info *sta;
bool timer_needed = false;
rcu_read_lock();
list_for_each_entry_rcu(sta, &local->sta_list, list)
if (sta_info_cleanup_expire_buffered(local, sta))
timer_needed = true;
rcu_read_unlock();
if (local->quiescing)
return;
if (!timer_needed)
return;
mod_timer(&local->sta_cleanup,
round_jiffies(jiffies + STA_INFO_CLEANUP_INTERVAL));
}
void sta_info_init(struct ieee80211_local *local)
{
spin_lock_init(&local->tim_lock);
mutex_init(&local->sta_mtx);
INIT_LIST_HEAD(&local->sta_list);
setup_timer(&local->sta_cleanup, sta_info_cleanup,
(unsigned long)local);
}
void sta_info_stop(struct ieee80211_local *local)
{
del_timer_sync(&local->sta_cleanup);
}
int __sta_info_flush(struct ieee80211_sub_if_data *sdata, bool vlans)
{
struct ieee80211_local *local = sdata->local;
struct sta_info *sta, *tmp;
LIST_HEAD(free_list);
int ret = 0;
might_sleep();
WARN_ON(vlans && sdata->vif.type != NL80211_IFTYPE_AP);
WARN_ON(vlans && !sdata->bss);
mutex_lock(&local->sta_mtx);
list_for_each_entry_safe(sta, tmp, &local->sta_list, list) {
if (sdata == sta->sdata ||
(vlans && sdata->bss == sta->sdata->bss)) {
if (!WARN_ON(__sta_info_destroy_part1(sta)))
list_add(&sta->free_list, &free_list);
ret++;
}
}
if (!list_empty(&free_list)) {
synchronize_net();
list_for_each_entry_safe(sta, tmp, &free_list, free_list)
__sta_info_destroy_part2(sta);
}
mutex_unlock(&local->sta_mtx);
return ret;
}
void ieee80211_sta_expire(struct ieee80211_sub_if_data *sdata,
unsigned long exp_time)
{
struct ieee80211_local *local = sdata->local;
struct sta_info *sta, *tmp;
mutex_lock(&local->sta_mtx);
list_for_each_entry_safe(sta, tmp, &local->sta_list, list) {
if (sdata != sta->sdata)
continue;
if (time_after(jiffies, sta->last_rx + exp_time)) {
sta_dbg(sta->sdata, "expiring inactive STA %pM\n",
sta->sta.addr);
if (ieee80211_vif_is_mesh(&sdata->vif) &&
test_sta_flag(sta, WLAN_STA_PS_STA))
atomic_dec(&sdata->u.mesh.ps.num_sta_ps);
WARN_ON(__sta_info_destroy(sta));
}
}
mutex_unlock(&local->sta_mtx);
}
struct ieee80211_sta *ieee80211_find_sta_by_ifaddr(struct ieee80211_hw *hw,
const u8 *addr,
const u8 *localaddr)
{
struct sta_info *sta, *nxt;
for_each_sta_info(hw_to_local(hw), addr, sta, nxt) {
if (localaddr &&
!ether_addr_equal(sta->sdata->vif.addr, localaddr))
continue;
if (!sta->uploaded)
return NULL;
return &sta->sta;
}
return NULL;
}
struct ieee80211_sta *ieee80211_find_sta(struct ieee80211_vif *vif,
const u8 *addr)
{
struct sta_info *sta;
if (!vif)
return NULL;
sta = sta_info_get_bss(vif_to_sdata(vif), addr);
if (!sta)
return NULL;
if (!sta->uploaded)
return NULL;
return &sta->sta;
}
void ieee80211_sta_ps_deliver_wakeup(struct sta_info *sta)
{
struct ieee80211_sub_if_data *sdata = sta->sdata;
struct ieee80211_local *local = sdata->local;
struct sk_buff_head pending;
int filtered = 0, buffered = 0, ac;
unsigned long flags;
struct ps_data *ps;
if (sdata->vif.type == NL80211_IFTYPE_AP ||
sdata->vif.type == NL80211_IFTYPE_AP_VLAN)
ps = &sdata->bss->ps;
else if (ieee80211_vif_is_mesh(&sdata->vif))
ps = &sdata->u.mesh.ps;
else
return;
clear_sta_flag(sta, WLAN_STA_SP);
BUILD_BUG_ON(BITS_TO_LONGS(IEEE80211_NUM_TIDS) > 1);
sta->driver_buffered_tids = 0;
if (!(local->hw.flags & IEEE80211_HW_AP_LINK_PS))
drv_sta_notify(local, sdata, STA_NOTIFY_AWAKE, &sta->sta);
skb_queue_head_init(&pending);
spin_lock(&sta->ps_lock);
for (ac = 0; ac < IEEE80211_NUM_ACS; ac++) {
int count = skb_queue_len(&pending), tmp;
spin_lock_irqsave(&sta->tx_filtered[ac].lock, flags);
skb_queue_splice_tail_init(&sta->tx_filtered[ac], &pending);
spin_unlock_irqrestore(&sta->tx_filtered[ac].lock, flags);
tmp = skb_queue_len(&pending);
filtered += tmp - count;
count = tmp;
spin_lock_irqsave(&sta->ps_tx_buf[ac].lock, flags);
skb_queue_splice_tail_init(&sta->ps_tx_buf[ac], &pending);
spin_unlock_irqrestore(&sta->ps_tx_buf[ac].lock, flags);
tmp = skb_queue_len(&pending);
buffered += tmp - count;
}
ieee80211_add_pending_skbs(local, &pending);
clear_sta_flag(sta, WLAN_STA_PS_DRIVER);
clear_sta_flag(sta, WLAN_STA_PS_STA);
spin_unlock(&sta->ps_lock);
atomic_dec(&ps->num_sta_ps);
if (!ieee80211_smps_is_restrictive(sta->known_smps_mode,
sdata->smps_mode) &&
sta->known_smps_mode != sdata->bss->req_smps &&
sta_info_tx_streams(sta) != 1) {
ht_dbg(sdata,
"%pM just woke up and MIMO capable - update SMPS\n",
sta->sta.addr);
ieee80211_send_smps_action(sdata, sdata->bss->req_smps,
sta->sta.addr,
sdata->vif.bss_conf.bssid);
}
local->total_ps_buffered -= buffered;
sta_info_recalc_tim(sta);
ps_dbg(sdata,
"STA %pM aid %d sending %d filtered/%d PS frames since STA not sleeping anymore\n",
sta->sta.addr, sta->sta.aid, filtered, buffered);
}
static void ieee80211_send_null_response(struct ieee80211_sub_if_data *sdata,
struct sta_info *sta, int tid,
enum ieee80211_frame_release_type reason,
bool call_driver)
{
struct ieee80211_local *local = sdata->local;
struct ieee80211_qos_hdr *nullfunc;
struct sk_buff *skb;
int size = sizeof(*nullfunc);
__le16 fc;
bool qos = test_sta_flag(sta, WLAN_STA_WME);
struct ieee80211_tx_info *info;
struct ieee80211_chanctx_conf *chanctx_conf;
if (qos) {
fc = cpu_to_le16(IEEE80211_FTYPE_DATA |
IEEE80211_STYPE_QOS_NULLFUNC |
IEEE80211_FCTL_FROMDS);
} else {
size -= 2;
fc = cpu_to_le16(IEEE80211_FTYPE_DATA |
IEEE80211_STYPE_NULLFUNC |
IEEE80211_FCTL_FROMDS);
}
skb = dev_alloc_skb(local->hw.extra_tx_headroom + size);
if (!skb)
return;
skb_reserve(skb, local->hw.extra_tx_headroom);
nullfunc = (void *) skb_put(skb, size);
nullfunc->frame_control = fc;
nullfunc->duration_id = 0;
memcpy(nullfunc->addr1, sta->sta.addr, ETH_ALEN);
memcpy(nullfunc->addr2, sdata->vif.addr, ETH_ALEN);
memcpy(nullfunc->addr3, sdata->vif.addr, ETH_ALEN);
nullfunc->seq_ctrl = 0;
skb->priority = tid;
skb_set_queue_mapping(skb, ieee802_1d_to_ac[tid]);
if (qos) {
nullfunc->qos_ctrl = cpu_to_le16(tid);
if (reason == IEEE80211_FRAME_RELEASE_UAPSD)
nullfunc->qos_ctrl |=
cpu_to_le16(IEEE80211_QOS_CTL_EOSP);
}
info = IEEE80211_SKB_CB(skb);
info->flags |= IEEE80211_TX_CTL_NO_PS_BUFFER |
IEEE80211_TX_CTL_PS_RESPONSE |
IEEE80211_TX_STATUS_EOSP |
IEEE80211_TX_CTL_REQ_TX_STATUS;
if (call_driver)
drv_allow_buffered_frames(local, sta, BIT(tid), 1,
reason, false);
skb->dev = sdata->dev;
rcu_read_lock();
chanctx_conf = rcu_dereference(sdata->vif.chanctx_conf);
if (WARN_ON(!chanctx_conf)) {
rcu_read_unlock();
kfree_skb(skb);
return;
}
ieee80211_xmit(sdata, skb, chanctx_conf->def.chan->band);
rcu_read_unlock();
}
static int find_highest_prio_tid(unsigned long tids)
{
if (tids & 0xF8)
return fls(tids) - 1;
if (tids & BIT(0))
return 0;
return fls(tids) - 1;
}
static void
ieee80211_sta_ps_deliver_response(struct sta_info *sta,
int n_frames, u8 ignored_acs,
enum ieee80211_frame_release_type reason)
{
struct ieee80211_sub_if_data *sdata = sta->sdata;
struct ieee80211_local *local = sdata->local;
bool more_data = false;
int ac;
unsigned long driver_release_tids = 0;
struct sk_buff_head frames;
set_sta_flag(sta, WLAN_STA_SP);
__skb_queue_head_init(&frames);
for (ac = 0; ac < IEEE80211_NUM_ACS; ac++) {
unsigned long tids;
if (ignored_acs & BIT(ac))
continue;
tids = ieee80211_tids_for_ac(ac);
if (skb_queue_empty(&frames))
driver_release_tids |= sta->driver_buffered_tids & tids;
if (driver_release_tids) {
if (reason == IEEE80211_FRAME_RELEASE_PSPOLL &&
hweight16(driver_release_tids) > 1) {
more_data = true;
driver_release_tids =
BIT(find_highest_prio_tid(
driver_release_tids));
break;
}
} else {
struct sk_buff *skb;
while (n_frames > 0) {
skb = skb_dequeue(&sta->tx_filtered[ac]);
if (!skb) {
skb = skb_dequeue(
&sta->ps_tx_buf[ac]);
if (skb)
local->total_ps_buffered--;
}
if (!skb)
break;
n_frames--;
__skb_queue_tail(&frames, skb);
}
}
if (!skb_queue_empty(&sta->tx_filtered[ac]) ||
!skb_queue_empty(&sta->ps_tx_buf[ac])) {
more_data = true;
break;
}
}
if (skb_queue_empty(&frames) && !driver_release_tids) {
int tid;
tid = 7 - ((ffs(~ignored_acs) - 1) << 1);
ieee80211_send_null_response(sdata, sta, tid, reason, true);
} else if (!driver_release_tids) {
struct sk_buff_head pending;
struct sk_buff *skb;
int num = 0;
u16 tids = 0;
bool need_null = false;
skb_queue_head_init(&pending);
while ((skb = __skb_dequeue(&frames))) {
struct ieee80211_tx_info *info = IEEE80211_SKB_CB(skb);
struct ieee80211_hdr *hdr = (void *) skb->data;
u8 *qoshdr = NULL;
num++;
info->flags |= IEEE80211_TX_CTL_NO_PS_BUFFER |
IEEE80211_TX_CTL_PS_RESPONSE;
if (more_data || !skb_queue_empty(&frames))
hdr->frame_control |=
cpu_to_le16(IEEE80211_FCTL_MOREDATA);
else
hdr->frame_control &=
cpu_to_le16(~IEEE80211_FCTL_MOREDATA);
if (ieee80211_is_data_qos(hdr->frame_control) ||
ieee80211_is_qos_nullfunc(hdr->frame_control))
qoshdr = ieee80211_get_qos_ctl(hdr);
tids |= BIT(skb->priority);
__skb_queue_tail(&pending, skb);
if (!skb_queue_empty(&frames))
continue;
if (reason != IEEE80211_FRAME_RELEASE_UAPSD) {
info->flags |= IEEE80211_TX_STATUS_EOSP |
IEEE80211_TX_CTL_REQ_TX_STATUS;
break;
}
if (qoshdr) {
*qoshdr |= IEEE80211_QOS_CTL_EOSP;
info->flags |= IEEE80211_TX_STATUS_EOSP |
IEEE80211_TX_CTL_REQ_TX_STATUS;
} else {
hdr->frame_control |=
cpu_to_le16(IEEE80211_FCTL_MOREDATA);
need_null = true;
num++;
}
break;
}
drv_allow_buffered_frames(local, sta, tids, num,
reason, more_data);
ieee80211_add_pending_skbs(local, &pending);
if (need_null)
ieee80211_send_null_response(
sdata, sta, find_highest_prio_tid(tids),
reason, false);
sta_info_recalc_tim(sta);
} else {
drv_release_buffered_frames(local, sta, driver_release_tids,
n_frames, reason, more_data);
}
}
void ieee80211_sta_ps_deliver_poll_response(struct sta_info *sta)
{
u8 ignore_for_response = sta->sta.uapsd_queues;
if (ignore_for_response == BIT(IEEE80211_NUM_ACS) - 1)
ignore_for_response = 0;
ieee80211_sta_ps_deliver_response(sta, 1, ignore_for_response,
IEEE80211_FRAME_RELEASE_PSPOLL);
}
void ieee80211_sta_ps_deliver_uapsd(struct sta_info *sta)
{
int n_frames = sta->sta.max_sp;
u8 delivery_enabled = sta->sta.uapsd_queues;
if (!delivery_enabled)
return;
switch (sta->sta.max_sp) {
case 1:
n_frames = 2;
break;
case 2:
n_frames = 4;
break;
case 3:
n_frames = 6;
break;
case 0:
n_frames = 8;
break;
}
ieee80211_sta_ps_deliver_response(sta, n_frames, ~delivery_enabled,
IEEE80211_FRAME_RELEASE_UAPSD);
}
void ieee80211_sta_block_awake(struct ieee80211_hw *hw,
struct ieee80211_sta *pubsta, bool block)
{
struct sta_info *sta = container_of(pubsta, struct sta_info, sta);
trace_api_sta_block_awake(sta->local, pubsta, block);
if (block)
set_sta_flag(sta, WLAN_STA_PS_DRIVER);
else if (test_sta_flag(sta, WLAN_STA_PS_DRIVER))
ieee80211_queue_work(hw, &sta->drv_unblock_wk);
}
void ieee80211_sta_eosp(struct ieee80211_sta *pubsta)
{
struct sta_info *sta = container_of(pubsta, struct sta_info, sta);
struct ieee80211_local *local = sta->local;
trace_api_eosp(local, pubsta);
clear_sta_flag(sta, WLAN_STA_SP);
}
void ieee80211_sta_set_buffered(struct ieee80211_sta *pubsta,
u8 tid, bool buffered)
{
struct sta_info *sta = container_of(pubsta, struct sta_info, sta);
if (WARN_ON(tid >= IEEE80211_NUM_TIDS))
return;
trace_api_sta_set_buffered(sta->local, pubsta, tid, buffered);
if (buffered)
set_bit(tid, &sta->driver_buffered_tids);
else
clear_bit(tid, &sta->driver_buffered_tids);
sta_info_recalc_tim(sta);
}
int sta_info_move_state(struct sta_info *sta,
enum ieee80211_sta_state new_state)
{
might_sleep();
if (sta->sta_state == new_state)
return 0;
switch (new_state) {
case IEEE80211_STA_NONE:
if (sta->sta_state != IEEE80211_STA_AUTH)
return -EINVAL;
break;
case IEEE80211_STA_AUTH:
if (sta->sta_state != IEEE80211_STA_NONE &&
sta->sta_state != IEEE80211_STA_ASSOC)
return -EINVAL;
break;
case IEEE80211_STA_ASSOC:
if (sta->sta_state != IEEE80211_STA_AUTH &&
sta->sta_state != IEEE80211_STA_AUTHORIZED)
return -EINVAL;
break;
case IEEE80211_STA_AUTHORIZED:
if (sta->sta_state != IEEE80211_STA_ASSOC)
return -EINVAL;
break;
default:
WARN(1, "invalid state %d", new_state);
return -EINVAL;
}
sta_dbg(sta->sdata, "moving STA %pM to state %d\n",
sta->sta.addr, new_state);
if (test_sta_flag(sta, WLAN_STA_INSERTED)) {
int err = drv_sta_state(sta->local, sta->sdata, sta,
sta->sta_state, new_state);
if (err)
return err;
}
switch (new_state) {
case IEEE80211_STA_NONE:
if (sta->sta_state == IEEE80211_STA_AUTH)
clear_bit(WLAN_STA_AUTH, &sta->_flags);
break;
case IEEE80211_STA_AUTH:
if (sta->sta_state == IEEE80211_STA_NONE)
set_bit(WLAN_STA_AUTH, &sta->_flags);
else if (sta->sta_state == IEEE80211_STA_ASSOC)
clear_bit(WLAN_STA_ASSOC, &sta->_flags);
break;
case IEEE80211_STA_ASSOC:
if (sta->sta_state == IEEE80211_STA_AUTH) {
set_bit(WLAN_STA_ASSOC, &sta->_flags);
} else if (sta->sta_state == IEEE80211_STA_AUTHORIZED) {
if (sta->sdata->vif.type == NL80211_IFTYPE_AP ||
(sta->sdata->vif.type == NL80211_IFTYPE_AP_VLAN &&
!sta->sdata->u.vlan.sta))
atomic_dec(&sta->sdata->bss->num_mcast_sta);
clear_bit(WLAN_STA_AUTHORIZED, &sta->_flags);
}
break;
case IEEE80211_STA_AUTHORIZED:
if (sta->sta_state == IEEE80211_STA_ASSOC) {
if (sta->sdata->vif.type == NL80211_IFTYPE_AP ||
(sta->sdata->vif.type == NL80211_IFTYPE_AP_VLAN &&
!sta->sdata->u.vlan.sta))
atomic_inc(&sta->sdata->bss->num_mcast_sta);
set_bit(WLAN_STA_AUTHORIZED, &sta->_flags);
}
break;
default:
break;
}
sta->sta_state = new_state;
return 0;
}
u8 sta_info_tx_streams(struct sta_info *sta)
{
struct ieee80211_sta_ht_cap *ht_cap = &sta->sta.ht_cap;
u8 rx_streams;
if (!sta->sta.ht_cap.ht_supported)
return 1;
if (sta->sta.vht_cap.vht_supported) {
int i;
u16 tx_mcs_map =
le16_to_cpu(sta->sta.vht_cap.vht_mcs.tx_mcs_map);
for (i = 7; i >= 0; i--)
if ((tx_mcs_map & (0x3 << (i * 2))) !=
IEEE80211_VHT_MCS_NOT_SUPPORTED)
return i + 1;
}
if (ht_cap->mcs.rx_mask[3])
rx_streams = 4;
else if (ht_cap->mcs.rx_mask[2])
rx_streams = 3;
else if (ht_cap->mcs.rx_mask[1])
rx_streams = 2;
else
rx_streams = 1;
if (!(ht_cap->mcs.tx_params & IEEE80211_HT_MCS_TX_RX_DIFF))
return rx_streams;
return ((ht_cap->mcs.tx_params & IEEE80211_HT_MCS_TX_MAX_STREAMS_MASK)
>> IEEE80211_HT_MCS_TX_MAX_STREAMS_SHIFT) + 1;
}
