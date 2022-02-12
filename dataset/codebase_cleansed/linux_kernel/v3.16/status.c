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
ieee80211_free_txskb(hw, skb);
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
struct ieee80211_hdr *hdr = (void *)skb->data;
int ac;
memset(&info->control, 0, sizeof(info->control));
info->control.jiffies = jiffies;
info->control.vif = &sta->sdata->vif;
info->flags |= IEEE80211_TX_INTFL_NEED_TXPROCESSING |
IEEE80211_TX_INTFL_RETRANSMISSION;
info->flags &= ~IEEE80211_TX_TEMPORARY_FLAGS;
sta->tx_filtered_count++;
if (hdr->frame_control & cpu_to_le16(IEEE80211_FCTL_MOREDATA))
hdr->frame_control &= ~cpu_to_le16(IEEE80211_FCTL_MOREDATA);
if (ieee80211_is_data_qos(hdr->frame_control)) {
u8 *p = ieee80211_get_qos_ctl(hdr);
int tid = *p & IEEE80211_QOS_CTL_TID_MASK;
if (*p & IEEE80211_QOS_CTL_EOSP)
*p &= ~IEEE80211_QOS_CTL_EOSP;
ac = ieee802_1d_to_ac[tid & 7];
} else {
ac = IEEE80211_AC_BE;
}
set_sta_flag(sta, WLAN_STA_CLEAR_PS_FILT);
if (test_sta_flag(sta, WLAN_STA_PS_STA) &&
skb_queue_len(&sta->tx_filtered[ac]) < STA_MAX_TX_BUFFER) {
skb_queue_tail(&sta->tx_filtered[ac], skb);
sta_info_recalc_tim(sta);
if (!timer_pending(&local->sta_cleanup))
mod_timer(&local->sta_cleanup,
round_jiffies(jiffies +
STA_INFO_CLEANUP_INTERVAL));
return;
}
if (!test_sta_flag(sta, WLAN_STA_PS_STA) &&
!(info->flags & IEEE80211_TX_INTFL_RETRIED)) {
info->flags |= IEEE80211_TX_INTFL_RETRIED;
ieee80211_add_pending_skb(local, skb);
return;
}
ps_dbg_ratelimited(sta->sdata,
"dropped TX filtered frame, queue_len=%d PS=%d @%lu\n",
skb_queue_len(&sta->tx_filtered[ac]),
!!test_sta_flag(sta, WLAN_STA_PS_STA), jiffies);
ieee80211_free_txskb(&local->hw, skb);
}
static void ieee80211_check_pending_bar(struct sta_info *sta, u8 *addr, u8 tid)
{
struct tid_ampdu_tx *tid_tx;
tid_tx = rcu_dereference(sta->ampdu_mlme.tid_tx[tid]);
if (!tid_tx || !tid_tx->bar_pending)
return;
tid_tx->bar_pending = false;
ieee80211_send_bar(&sta->sdata->vif, addr, tid, tid_tx->failed_bar_ssn);
}
static void ieee80211_frame_acked(struct sta_info *sta, struct sk_buff *skb)
{
struct ieee80211_mgmt *mgmt = (void *) skb->data;
struct ieee80211_local *local = sta->local;
struct ieee80211_sub_if_data *sdata = sta->sdata;
if (local->hw.flags & IEEE80211_HW_REPORTS_TX_ACK_STATUS)
sta->last_rx = jiffies;
if (ieee80211_is_data_qos(mgmt->frame_control)) {
struct ieee80211_hdr *hdr = (void *) skb->data;
u8 *qc = ieee80211_get_qos_ctl(hdr);
u16 tid = qc[0] & 0xf;
ieee80211_check_pending_bar(sta, hdr->addr1, tid);
}
if (ieee80211_is_action(mgmt->frame_control) &&
mgmt->u.action.category == WLAN_CATEGORY_HT &&
mgmt->u.action.u.ht_smps.action == WLAN_HT_ACTION_SMPS &&
ieee80211_sdata_running(sdata)) {
enum ieee80211_smps_mode smps_mode;
switch (mgmt->u.action.u.ht_smps.smps_control) {
case WLAN_HT_SMPS_CONTROL_DYNAMIC:
smps_mode = IEEE80211_SMPS_DYNAMIC;
break;
case WLAN_HT_SMPS_CONTROL_STATIC:
smps_mode = IEEE80211_SMPS_STATIC;
break;
case WLAN_HT_SMPS_CONTROL_DISABLED:
default:
smps_mode = IEEE80211_SMPS_OFF;
break;
}
if (sdata->vif.type == NL80211_IFTYPE_STATION) {
sdata->smps_mode = smps_mode;
ieee80211_queue_work(&local->hw, &sdata->recalc_smps);
} else if (sdata->vif.type == NL80211_IFTYPE_AP ||
sdata->vif.type == NL80211_IFTYPE_AP_VLAN) {
sta->known_smps_mode = smps_mode;
}
}
}
static void ieee80211_set_bar_pending(struct sta_info *sta, u8 tid, u16 ssn)
{
struct tid_ampdu_tx *tid_tx;
tid_tx = rcu_dereference(sta->ampdu_mlme.tid_tx[tid]);
if (!tid_tx)
return;
tid_tx->failed_bar_ssn = ssn;
tid_tx->bar_pending = true;
}
static int ieee80211_tx_radiotap_len(struct ieee80211_tx_info *info)
{
int len = sizeof(struct ieee80211_radiotap_header);
if (info->status.rates[0].idx >= 0 &&
!(info->status.rates[0].flags & (IEEE80211_TX_RC_MCS |
IEEE80211_TX_RC_VHT_MCS)))
len += 2;
len += 2;
len += 1;
if (info->status.rates[0].idx >= 0) {
if (info->status.rates[0].flags & IEEE80211_TX_RC_MCS)
len += 3;
else if (info->status.rates[0].flags & IEEE80211_TX_RC_VHT_MCS)
len = ALIGN(len, 2) + 12;
}
return len;
}
static void
ieee80211_add_tx_radiotap_header(struct ieee80211_local *local,
struct ieee80211_supported_band *sband,
struct sk_buff *skb, int retry_count,
int rtap_len, int shift)
{
struct ieee80211_tx_info *info = IEEE80211_SKB_CB(skb);
struct ieee80211_hdr *hdr = (struct ieee80211_hdr *) skb->data;
struct ieee80211_radiotap_header *rthdr;
unsigned char *pos;
u16 txflags;
rthdr = (struct ieee80211_radiotap_header *) skb_push(skb, rtap_len);
memset(rthdr, 0, rtap_len);
rthdr->it_len = cpu_to_le16(rtap_len);
rthdr->it_present =
cpu_to_le32((1 << IEEE80211_RADIOTAP_TX_FLAGS) |
(1 << IEEE80211_RADIOTAP_DATA_RETRIES));
pos = (unsigned char *)(rthdr + 1);
if (info->status.rates[0].idx >= 0 &&
!(info->status.rates[0].flags & (IEEE80211_TX_RC_MCS |
IEEE80211_TX_RC_VHT_MCS))) {
u16 rate;
rthdr->it_present |= cpu_to_le32(1 << IEEE80211_RADIOTAP_RATE);
rate = sband->bitrates[info->status.rates[0].idx].bitrate;
*pos = DIV_ROUND_UP(rate, 5 * (1 << shift));
pos += 2;
}
txflags = 0;
if (!(info->flags & IEEE80211_TX_STAT_ACK) &&
!is_multicast_ether_addr(hdr->addr1))
txflags |= IEEE80211_RADIOTAP_F_TX_FAIL;
if (info->status.rates[0].flags & IEEE80211_TX_RC_USE_CTS_PROTECT)
txflags |= IEEE80211_RADIOTAP_F_TX_CTS;
if (info->status.rates[0].flags & IEEE80211_TX_RC_USE_RTS_CTS)
txflags |= IEEE80211_RADIOTAP_F_TX_RTS;
put_unaligned_le16(txflags, pos);
pos += 2;
*pos = retry_count;
pos++;
if (info->status.rates[0].idx < 0)
return;
if (info->status.rates[0].flags & IEEE80211_TX_RC_MCS) {
rthdr->it_present |= cpu_to_le32(1 << IEEE80211_RADIOTAP_MCS);
pos[0] = IEEE80211_RADIOTAP_MCS_HAVE_MCS |
IEEE80211_RADIOTAP_MCS_HAVE_GI |
IEEE80211_RADIOTAP_MCS_HAVE_BW;
if (info->status.rates[0].flags & IEEE80211_TX_RC_SHORT_GI)
pos[1] |= IEEE80211_RADIOTAP_MCS_SGI;
if (info->status.rates[0].flags & IEEE80211_TX_RC_40_MHZ_WIDTH)
pos[1] |= IEEE80211_RADIOTAP_MCS_BW_40;
if (info->status.rates[0].flags & IEEE80211_TX_RC_GREEN_FIELD)
pos[1] |= IEEE80211_RADIOTAP_MCS_FMT_GF;
pos[2] = info->status.rates[0].idx;
pos += 3;
} else if (info->status.rates[0].flags & IEEE80211_TX_RC_VHT_MCS) {
u16 known = local->hw.radiotap_vht_details &
(IEEE80211_RADIOTAP_VHT_KNOWN_GI |
IEEE80211_RADIOTAP_VHT_KNOWN_BANDWIDTH);
rthdr->it_present |= cpu_to_le32(1 << IEEE80211_RADIOTAP_VHT);
pos = (u8 *)rthdr + ALIGN(pos - (u8 *)rthdr, 2);
put_unaligned_le16(known, pos);
pos += 2;
if (info->status.rates[0].flags & IEEE80211_TX_RC_SHORT_GI)
*pos |= IEEE80211_RADIOTAP_VHT_FLAG_SGI;
pos++;
if (info->status.rates[0].flags & IEEE80211_TX_RC_40_MHZ_WIDTH)
*pos = 1;
else if (info->status.rates[0].flags & IEEE80211_TX_RC_80_MHZ_WIDTH)
*pos = 4;
else if (info->status.rates[0].flags & IEEE80211_TX_RC_160_MHZ_WIDTH)
*pos = 11;
else
*pos = 0;
pos++;
*pos = (ieee80211_rate_get_vht_mcs(&info->status.rates[0]) << 4) |
ieee80211_rate_get_vht_nss(&info->status.rates[0]);
pos += 4;
pos++;
pos++;
pos += 2;
}
}
static void ieee80211_report_used_skb(struct ieee80211_local *local,
struct sk_buff *skb, bool dropped)
{
struct ieee80211_tx_info *info = IEEE80211_SKB_CB(skb);
struct ieee80211_hdr *hdr = (void *)skb->data;
bool acked = info->flags & IEEE80211_TX_STAT_ACK;
if (dropped)
acked = false;
if (info->flags & (IEEE80211_TX_INTFL_NL80211_FRAME_TX |
IEEE80211_TX_INTFL_MLME_CONN_TX)) {
struct ieee80211_sub_if_data *sdata = NULL;
struct ieee80211_sub_if_data *iter_sdata;
u64 cookie = (unsigned long)skb;
rcu_read_lock();
if (skb->dev) {
list_for_each_entry_rcu(iter_sdata, &local->interfaces,
list) {
if (!iter_sdata->dev)
continue;
if (skb->dev == iter_sdata->dev) {
sdata = iter_sdata;
break;
}
}
} else {
sdata = rcu_dereference(local->p2p_sdata);
}
if (!sdata) {
skb->dev = NULL;
} else if (info->flags & IEEE80211_TX_INTFL_MLME_CONN_TX) {
ieee80211_mgd_conn_tx_status(sdata, hdr->frame_control,
acked);
} else if (ieee80211_is_nullfunc(hdr->frame_control) ||
ieee80211_is_qos_nullfunc(hdr->frame_control)) {
cfg80211_probe_status(sdata->dev, hdr->addr1,
cookie, acked, GFP_ATOMIC);
} else {
cfg80211_mgmt_tx_status(&sdata->wdev, cookie, skb->data,
skb->len, acked, GFP_ATOMIC);
}
rcu_read_unlock();
}
if (unlikely(info->ack_frame_id)) {
struct sk_buff *ack_skb;
unsigned long flags;
spin_lock_irqsave(&local->ack_status_lock, flags);
ack_skb = idr_find(&local->ack_status_frames,
info->ack_frame_id);
if (ack_skb)
idr_remove(&local->ack_status_frames,
info->ack_frame_id);
spin_unlock_irqrestore(&local->ack_status_lock, flags);
if (ack_skb) {
if (!dropped) {
skb_complete_wifi_ack(ack_skb, acked);
} else {
dev_kfree_skb_any(ack_skb);
}
}
}
}
static void ieee80211_tx_latency_end_msrmnt(struct ieee80211_local *local,
struct sk_buff *skb,
struct sta_info *sta,
struct ieee80211_hdr *hdr)
{
ktime_t skb_dprt;
struct timespec dprt_time;
u32 msrmnt;
u16 tid;
u8 *qc;
int i, bin_range_count;
u32 *bin_ranges;
__le16 fc;
struct ieee80211_tx_latency_stat *tx_lat;
struct ieee80211_tx_latency_bin_ranges *tx_latency;
ktime_t skb_arv = skb->tstamp;
tx_latency = rcu_dereference(local->tx_latency);
if (!tx_latency || !ktime_to_ns(skb_arv))
return;
fc = hdr->frame_control;
if (!ieee80211_is_data(fc))
return;
if (ieee80211_is_data_qos(hdr->frame_control)) {
qc = ieee80211_get_qos_ctl(hdr);
tid = qc[0] & IEEE80211_QOS_CTL_TID_MASK;
} else {
tid = 0;
}
tx_lat = &sta->tx_lat[tid];
ktime_get_ts(&dprt_time);
skb_dprt = ktime_set(dprt_time.tv_sec, dprt_time.tv_nsec);
msrmnt = ktime_to_ms(ktime_sub(skb_dprt, skb_arv));
if (tx_lat->max < msrmnt)
tx_lat->max = msrmnt;
tx_lat->counter++;
tx_lat->sum += msrmnt;
if (!tx_lat->bins)
return;
bin_range_count = tx_latency->n_ranges;
bin_ranges = tx_latency->ranges;
for (i = 0; i < bin_range_count; i++) {
if (msrmnt <= bin_ranges[i]) {
tx_lat->bins[i]++;
break;
}
}
if (i == bin_range_count)
tx_lat->bins[i]++;
}
static void ieee80211_lost_packet(struct sta_info *sta, struct sk_buff *skb)
{
struct ieee80211_tx_info *info = IEEE80211_SKB_CB(skb);
if ((info->flags & IEEE80211_TX_CTL_AMPDU) &&
!(info->flags & IEEE80211_TX_STAT_AMPDU))
return;
if (++sta->lost_packets < STA_LOST_PKT_THRESHOLD)
return;
cfg80211_cqm_pktloss_notify(sta->sdata->dev, sta->sta.addr,
sta->lost_packets, GFP_ATOMIC);
sta->lost_packets = 0;
}
void ieee80211_tx_status(struct ieee80211_hw *hw, struct sk_buff *skb)
{
struct sk_buff *skb2;
struct ieee80211_hdr *hdr = (struct ieee80211_hdr *) skb->data;
struct ieee80211_local *local = hw_to_local(hw);
struct ieee80211_tx_info *info = IEEE80211_SKB_CB(skb);
__le16 fc;
struct ieee80211_supported_band *sband;
struct ieee80211_sub_if_data *sdata;
struct net_device *prev_dev = NULL;
struct sta_info *sta, *tmp;
int retry_count = -1, i;
int rates_idx = -1;
bool send_to_cooked;
bool acked;
struct ieee80211_bar *bar;
int rtap_len;
int shift = 0;
for (i = 0; i < IEEE80211_TX_MAX_RATES; i++) {
if ((info->flags & IEEE80211_TX_CTL_AMPDU) &&
!(info->flags & IEEE80211_TX_STAT_AMPDU)) {
info->status.rates[i].idx = -1;
info->status.rates[i].count = 0;
break;
} else if (info->status.rates[i].idx < 0) {
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
if (!ether_addr_equal(hdr->addr2, sta->sdata->vif.addr))
continue;
shift = ieee80211_vif_get_shift(&sta->sdata->vif);
if (info->flags & IEEE80211_TX_STATUS_EOSP)
clear_sta_flag(sta, WLAN_STA_SP);
acked = !!(info->flags & IEEE80211_TX_STAT_ACK);
if (!acked && test_sta_flag(sta, WLAN_STA_PS_STA)) {
ieee80211_handle_filtered_frame(local, sta, skb);
rcu_read_unlock();
return;
}
if (ieee80211_vif_is_mesh(&sta->sdata->vif) &&
ieee80211_is_data_qos(fc))
ieee80211_mpsp_trigger_process(
ieee80211_get_qos_ctl(hdr),
sta, true, acked);
if ((local->hw.flags & IEEE80211_HW_HAS_RATE_CONTROL) &&
(ieee80211_is_data(hdr->frame_control)) &&
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
ieee80211_send_bar(&sta->sdata->vif, hdr->addr1,
tid, ssn);
}
if (!acked && ieee80211_is_back_req(fc)) {
u16 tid, control;
bar = (struct ieee80211_bar *) skb->data;
control = le16_to_cpu(bar->control);
if (!(control & IEEE80211_BAR_CTRL_MULTI_TID)) {
u16 ssn = le16_to_cpu(bar->start_seq_num);
tid = (control &
IEEE80211_BAR_CTRL_TID_INFO_MASK) >>
IEEE80211_BAR_CTRL_TID_INFO_SHIFT;
ieee80211_set_bar_pending(sta, tid, ssn);
}
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
} else {
ieee80211_lost_packet(sta, skb);
}
}
if (acked)
sta->last_ack_signal = info->status.ack_signal;
ieee80211_tx_latency_end_msrmnt(local, skb, sta, hdr);
}
rcu_read_unlock();
ieee80211_led_tx(local);
if (info->flags & IEEE80211_TX_STAT_ACK) {
if (ieee80211_is_first_frag(hdr->seq_ctrl)) {
local->dot11TransmittedFrameCount++;
if (is_multicast_ether_addr(hdr->addr1))
local->dot11MulticastTransmittedFrameCount++;
if (retry_count > 0)
local->dot11RetryCount++;
if (retry_count > 1)
local->dot11MultipleRetryCount++;
}
if (!is_multicast_ether_addr(hdr->addr1) ||
ieee80211_is_data(fc) ||
ieee80211_is_mgmt(fc))
local->dot11TransmittedFragmentCount++;
} else {
if (ieee80211_is_first_frag(hdr->seq_ctrl))
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
ieee80211_report_used_skb(local, skb, false);
skb_orphan(skb);
send_to_cooked = !!(info->flags & IEEE80211_TX_CTL_INJECTED) ||
!(ieee80211_is_data(fc));
if (!local->monitors && (!send_to_cooked || !local->cooked_mntrs)) {
dev_kfree_skb(skb);
return;
}
rtap_len = ieee80211_tx_radiotap_len(info);
if (WARN_ON_ONCE(skb_headroom(skb) < rtap_len)) {
pr_err("ieee80211_tx_status: headroom too small\n");
dev_kfree_skb(skb);
return;
}
ieee80211_add_tx_radiotap_header(local, sband, skb, retry_count,
rtap_len, shift);
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
void ieee80211_free_txskb(struct ieee80211_hw *hw, struct sk_buff *skb)
{
struct ieee80211_local *local = hw_to_local(hw);
ieee80211_report_used_skb(local, skb, true);
dev_kfree_skb_any(skb);
}
void ieee80211_purge_tx_queue(struct ieee80211_hw *hw,
struct sk_buff_head *skbs)
{
struct sk_buff *skb;
while ((skb = __skb_dequeue(skbs)))
ieee80211_free_txskb(hw, skb);
}
