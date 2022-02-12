void ieee80211_tx_status_irqsafe(struct ieee80211_hw *hw,
struct sk_buff *skb)
{
struct ieee80211_local *local = hw_to_local(hw);
struct ieee80211_tx_info *info = IEEE80211_SKB_CB(skb);
int tmp;
skb->pkt_type = IEEE80211_TX_STATUS_MSG;
skb_queue_tail(info->flags & IEEE80211_TX_CTL_REQ_TX_STATUS ?
&local->skb_queue : &local->skb_queue_unreliable, skb);
tmp = skb_queue_len(&local->skb_queue) +
skb_queue_len(&local->skb_queue_unreliable);
while (tmp > IEEE80211_IRQSAFE_QUEUE_LIMIT &&
(skb = skb_dequeue(&local->skb_queue_unreliable))) {
dev_kfree_skb_irq(skb);
tmp--;
I802_DEBUG_INC(local->tx_status_drop);
}
tasklet_schedule(&local->tasklet);
}
static void ieee80211_handle_filtered_frame(struct ieee80211_local *local,
struct sta_info *sta,
struct sk_buff *skb)
{
struct ieee80211_tx_info *info = IEEE80211_SKB_CB(skb);
memset(&info->control, 0, sizeof(info->control));
info->control.jiffies = jiffies;
info->control.vif = &sta->sdata->vif;
info->flags |= IEEE80211_TX_INTFL_NEED_TXPROCESSING |
IEEE80211_TX_INTFL_RETRANSMISSION;
info->flags &= ~IEEE80211_TX_TEMPORARY_FLAGS;
sta->tx_filtered_count++;
set_sta_flags(sta, WLAN_STA_CLEAR_PS_FILT);
if (test_sta_flags(sta, WLAN_STA_PS_STA) &&
skb_queue_len(&sta->tx_filtered) < STA_MAX_TX_BUFFER) {
skb_queue_tail(&sta->tx_filtered, skb);
return;
}
if (!test_sta_flags(sta, WLAN_STA_PS_STA) &&
!(info->flags & IEEE80211_TX_INTFL_RETRIED)) {
info->flags |= IEEE80211_TX_INTFL_RETRIED;
ieee80211_add_pending_skb(local, skb);
return;
}
#ifdef CONFIG_MAC80211_VERBOSE_DEBUG
if (net_ratelimit())
wiphy_debug(local->hw.wiphy,
"dropped TX filtered frame, queue_len=%d PS=%d @%lu\n",
skb_queue_len(&sta->tx_filtered),
!!test_sta_flags(sta, WLAN_STA_PS_STA), jiffies);
#endif
dev_kfree_skb(skb);
}
static void ieee80211_frame_acked(struct sta_info *sta, struct sk_buff *skb)
{
struct ieee80211_mgmt *mgmt = (void *) skb->data;
struct ieee80211_local *local = sta->local;
struct ieee80211_sub_if_data *sdata = sta->sdata;
if (ieee80211_is_action(mgmt->frame_control) &&
sdata->vif.type == NL80211_IFTYPE_STATION &&
mgmt->u.action.category == WLAN_CATEGORY_HT &&
mgmt->u.action.u.ht_smps.action == WLAN_HT_ACTION_SMPS) {
switch (mgmt->u.action.u.ht_smps.smps_control) {
case WLAN_HT_SMPS_CONTROL_DYNAMIC:
sta->sdata->u.mgd.ap_smps = IEEE80211_SMPS_DYNAMIC;
break;
case WLAN_HT_SMPS_CONTROL_STATIC:
sta->sdata->u.mgd.ap_smps = IEEE80211_SMPS_STATIC;
break;
case WLAN_HT_SMPS_CONTROL_DISABLED:
default:
sta->sdata->u.mgd.ap_smps = IEEE80211_SMPS_OFF;
break;
}
ieee80211_queue_work(&local->hw, &local->recalc_smps);
}
}
void ieee80211_tx_status(struct ieee80211_hw *hw, struct sk_buff *skb)
{
struct sk_buff *skb2;
struct ieee80211_hdr *hdr = (struct ieee80211_hdr *) skb->data;
struct ieee80211_local *local = hw_to_local(hw);
struct ieee80211_tx_info *info = IEEE80211_SKB_CB(skb);
u16 frag, type;
__le16 fc;
struct ieee80211_supported_band *sband;
struct ieee80211_tx_status_rtap_hdr *rthdr;
struct ieee80211_sub_if_data *sdata;
struct net_device *prev_dev = NULL;
struct sta_info *sta, *tmp;
int retry_count = -1, i;
int rates_idx = -1;
bool send_to_cooked;
bool acked;
for (i = 0; i < IEEE80211_TX_MAX_RATES; i++) {
if (info->status.rates[i].idx < 0) {
break;
} else if (i >= hw->max_report_rates) {
info->status.rates[i].idx = -1;
info->status.rates[i].count = 0;
break;
}
retry_count += info->status.rates[i].count;
}
rates_idx = i - 1;
if (retry_count < 0)
retry_count = 0;
rcu_read_lock();
sband = local->hw.wiphy->bands[info->band];
fc = hdr->frame_control;
for_each_sta_info(local, hdr->addr1, sta, tmp) {
if (memcmp(hdr->addr2, sta->sdata->vif.addr, ETH_ALEN))
continue;
acked = !!(info->flags & IEEE80211_TX_STAT_ACK);
if (!acked && test_sta_flags(sta, WLAN_STA_PS_STA)) {
ieee80211_handle_filtered_frame(local, sta, skb);
rcu_read_unlock();
return;
}
if ((local->hw.flags & IEEE80211_HW_HAS_RATE_CONTROL) &&
(rates_idx != -1))
sta->last_tx_rate = info->status.rates[rates_idx];
if ((info->flags & IEEE80211_TX_STAT_AMPDU_NO_BACK) &&
(ieee80211_is_data_qos(fc))) {
u16 tid, ssn;
u8 *qc;
qc = ieee80211_get_qos_ctl(hdr);
tid = qc[0] & 0xf;
ssn = ((le16_to_cpu(hdr->seq_ctrl) + 0x10)
& IEEE80211_SCTL_SEQ);
ieee80211_send_bar(sta->sdata, hdr->addr1,
tid, ssn);
}
if (info->flags & IEEE80211_TX_STAT_TX_FILTERED) {
ieee80211_handle_filtered_frame(local, sta, skb);
rcu_read_unlock();
return;
} else {
if (!acked)
sta->tx_retry_failed++;
sta->tx_retry_count += retry_count;
}
rate_control_tx_status(local, sband, sta, skb);
if (ieee80211_vif_is_mesh(&sta->sdata->vif))
ieee80211s_update_metric(local, sta, skb);
if (!(info->flags & IEEE80211_TX_CTL_INJECTED) && acked)
ieee80211_frame_acked(sta, skb);
if ((sta->sdata->vif.type == NL80211_IFTYPE_STATION) &&
(local->hw.flags & IEEE80211_HW_REPORTS_TX_ACK_STATUS))
ieee80211_sta_tx_notify(sta->sdata, (void *) skb->data, acked);
if (local->hw.flags & IEEE80211_HW_REPORTS_TX_ACK_STATUS) {
if (info->flags & IEEE80211_TX_STAT_ACK) {
if (sta->lost_packets)
sta->lost_packets = 0;
} else if (++sta->lost_packets >= STA_LOST_PKT_THRESHOLD) {
cfg80211_cqm_pktloss_notify(sta->sdata->dev,
sta->sta.addr,
sta->lost_packets,
GFP_ATOMIC);
sta->lost_packets = 0;
}
}
}
rcu_read_unlock();
ieee80211_led_tx(local, 0);
frag = le16_to_cpu(hdr->seq_ctrl) & IEEE80211_SCTL_FRAG;
type = le16_to_cpu(hdr->frame_control) & IEEE80211_FCTL_FTYPE;
if (info->flags & IEEE80211_TX_STAT_ACK) {
if (frag == 0) {
local->dot11TransmittedFrameCount++;
if (is_multicast_ether_addr(hdr->addr1))
local->dot11MulticastTransmittedFrameCount++;
if (retry_count > 0)
local->dot11RetryCount++;
if (retry_count > 1)
local->dot11MultipleRetryCount++;
}
if (!is_multicast_ether_addr(hdr->addr1) ||
type == IEEE80211_FTYPE_DATA ||
type == IEEE80211_FTYPE_MGMT)
local->dot11TransmittedFragmentCount++;
} else {
if (frag == 0)
local->dot11FailedCount++;
}
if (ieee80211_is_nullfunc(fc) && ieee80211_has_pm(fc) &&
(local->hw.flags & IEEE80211_HW_REPORTS_TX_ACK_STATUS) &&
!(info->flags & IEEE80211_TX_CTL_INJECTED) &&
local->ps_sdata && !(local->scanning)) {
if (info->flags & IEEE80211_TX_STAT_ACK) {
local->ps_sdata->u.mgd.flags |=
IEEE80211_STA_NULLFUNC_ACKED;
} else
mod_timer(&local->dynamic_ps_timer, jiffies +
msecs_to_jiffies(10));
}
if (info->flags & IEEE80211_TX_INTFL_NL80211_FRAME_TX) {
struct ieee80211_work *wk;
u64 cookie = (unsigned long)skb;
rcu_read_lock();
list_for_each_entry_rcu(wk, &local->work_list, list) {
if (wk->type != IEEE80211_WORK_OFFCHANNEL_TX)
continue;
if (wk->offchan_tx.frame != skb)
continue;
wk->offchan_tx.frame = NULL;
break;
}
rcu_read_unlock();
if (local->hw_roc_skb_for_status == skb) {
cookie = local->hw_roc_cookie ^ 2;
local->hw_roc_skb_for_status = NULL;
}
if (cookie == local->hw_offchan_tx_cookie)
local->hw_offchan_tx_cookie = 0;
cfg80211_mgmt_tx_status(
skb->dev, cookie, skb->data, skb->len,
!!(info->flags & IEEE80211_TX_STAT_ACK), GFP_ATOMIC);
}
skb_orphan(skb);
send_to_cooked = !!(info->flags & IEEE80211_TX_CTL_INJECTED) ||
(type != IEEE80211_FTYPE_DATA);
if (!local->monitors && (!send_to_cooked || !local->cooked_mntrs)) {
dev_kfree_skb(skb);
return;
}
if (skb_headroom(skb) < sizeof(*rthdr)) {
printk(KERN_ERR "ieee80211_tx_status: headroom too small\n");
dev_kfree_skb(skb);
return;
}
rthdr = (struct ieee80211_tx_status_rtap_hdr *)
skb_push(skb, sizeof(*rthdr));
memset(rthdr, 0, sizeof(*rthdr));
rthdr->hdr.it_len = cpu_to_le16(sizeof(*rthdr));
rthdr->hdr.it_present =
cpu_to_le32((1 << IEEE80211_RADIOTAP_TX_FLAGS) |
(1 << IEEE80211_RADIOTAP_DATA_RETRIES) |
(1 << IEEE80211_RADIOTAP_RATE));
if (!(info->flags & IEEE80211_TX_STAT_ACK) &&
!is_multicast_ether_addr(hdr->addr1))
rthdr->tx_flags |= cpu_to_le16(IEEE80211_RADIOTAP_F_TX_FAIL);
if ((info->status.rates[0].flags & IEEE80211_TX_RC_USE_RTS_CTS) ||
(info->status.rates[0].flags & IEEE80211_TX_RC_USE_CTS_PROTECT))
rthdr->tx_flags |= cpu_to_le16(IEEE80211_RADIOTAP_F_TX_CTS);
else if (info->status.rates[0].flags & IEEE80211_TX_RC_USE_RTS_CTS)
rthdr->tx_flags |= cpu_to_le16(IEEE80211_RADIOTAP_F_TX_RTS);
if (info->status.rates[0].idx >= 0 &&
!(info->status.rates[0].flags & IEEE80211_TX_RC_MCS))
rthdr->rate = sband->bitrates[
info->status.rates[0].idx].bitrate / 5;
rthdr->data_retries = retry_count;
skb_set_mac_header(skb, 0);
skb->ip_summed = CHECKSUM_UNNECESSARY;
skb->pkt_type = PACKET_OTHERHOST;
skb->protocol = htons(ETH_P_802_2);
memset(skb->cb, 0, sizeof(skb->cb));
rcu_read_lock();
list_for_each_entry_rcu(sdata, &local->interfaces, list) {
if (sdata->vif.type == NL80211_IFTYPE_MONITOR) {
if (!ieee80211_sdata_running(sdata))
continue;
if ((sdata->u.mntr_flags & MONITOR_FLAG_COOK_FRAMES) &&
!send_to_cooked)
continue;
if (prev_dev) {
skb2 = skb_clone(skb, GFP_ATOMIC);
if (skb2) {
skb2->dev = prev_dev;
netif_rx(skb2);
}
}
prev_dev = sdata->dev;
}
}
if (prev_dev) {
skb->dev = prev_dev;
netif_rx(skb);
skb = NULL;
}
rcu_read_unlock();
dev_kfree_skb(skb);
}
void ieee80211_report_low_ack(struct ieee80211_sta *pubsta, u32 num_packets)
{
struct sta_info *sta = container_of(pubsta, struct sta_info, sta);
cfg80211_cqm_pktloss_notify(sta->sdata->dev, sta->sta.addr,
num_packets, GFP_ATOMIC);
}
