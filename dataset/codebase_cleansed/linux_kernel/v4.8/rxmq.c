static inline int iwl_mvm_check_pn(struct iwl_mvm *mvm, struct sk_buff *skb,
int queue, struct ieee80211_sta *sta)
{
struct iwl_mvm_sta *mvmsta;
struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)skb->data;
struct ieee80211_rx_status *stats = IEEE80211_SKB_RXCB(skb);
struct iwl_mvm_key_pn *ptk_pn;
u8 tid, keyidx;
u8 pn[IEEE80211_CCMP_PN_LEN];
u8 *extiv;
if (!ieee80211_is_data(hdr->frame_control) ||
is_multicast_ether_addr(hdr->addr1))
return 0;
if (!(stats->flag & RX_FLAG_DECRYPTED))
return 0;
if (queue == 0)
return 0;
if (IS_ERR_OR_NULL(sta)) {
IWL_ERR(mvm,
"expected hw-decrypted unicast frame for station\n");
return -1;
}
mvmsta = iwl_mvm_sta_from_mac80211(sta);
extiv = (u8 *)hdr + ieee80211_hdrlen(hdr->frame_control);
keyidx = extiv[3] >> 6;
ptk_pn = rcu_dereference(mvmsta->ptk_pn[keyidx]);
if (!ptk_pn)
return -1;
if (ieee80211_is_data_qos(hdr->frame_control))
tid = *ieee80211_get_qos_ctl(hdr) & IEEE80211_QOS_CTL_TID_MASK;
else
tid = 0;
if (tid >= IWL_MAX_TID_COUNT)
return -1;
pn[0] = extiv[7];
pn[1] = extiv[6];
pn[2] = extiv[5];
pn[3] = extiv[4];
pn[4] = extiv[1];
pn[5] = extiv[0];
if (memcmp(pn, ptk_pn->q[queue].pn[tid],
IEEE80211_CCMP_PN_LEN) <= 0)
return -1;
memcpy(ptk_pn->q[queue].pn[tid], pn, IEEE80211_CCMP_PN_LEN);
stats->flag |= RX_FLAG_PN_VALIDATED;
return 0;
}
static void iwl_mvm_create_skb(struct sk_buff *skb, struct ieee80211_hdr *hdr,
u16 len, u8 crypt_len,
struct iwl_rx_cmd_buffer *rxb)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
struct iwl_rx_mpdu_desc *desc = (void *)pkt->data;
unsigned int headlen, fraglen, pad_len = 0;
unsigned int hdrlen = ieee80211_hdrlen(hdr->frame_control);
if (desc->mac_flags2 & IWL_RX_MPDU_MFLG2_PAD)
pad_len = 2;
len -= pad_len;
headlen = (len <= skb_tailroom(skb)) ? len :
hdrlen + crypt_len + 8;
hdrlen += crypt_len;
memcpy(skb_put(skb, hdrlen), hdr, hdrlen);
memcpy(skb_put(skb, headlen - hdrlen), (u8 *)hdr + hdrlen + pad_len,
headlen - hdrlen);
fraglen = len - headlen;
if (fraglen) {
int offset = (void *)hdr + headlen + pad_len -
rxb_addr(rxb) + rxb_offset(rxb);
skb_add_rx_frag(skb, 0, rxb_steal_page(rxb), offset,
fraglen, rxb->truesize);
}
}
static void iwl_mvm_pass_packet_to_mac80211(struct iwl_mvm *mvm,
struct napi_struct *napi,
struct sk_buff *skb, int queue,
struct ieee80211_sta *sta)
{
if (iwl_mvm_check_pn(mvm, skb, queue, sta))
kfree_skb(skb);
else
ieee80211_rx_napi(mvm->hw, sta, skb, napi);
}
static void iwl_mvm_get_signal_strength(struct iwl_mvm *mvm,
struct iwl_rx_mpdu_desc *desc,
struct ieee80211_rx_status *rx_status)
{
int energy_a, energy_b, max_energy;
energy_a = desc->energy_a;
energy_a = energy_a ? -energy_a : S8_MIN;
energy_b = desc->energy_b;
energy_b = energy_b ? -energy_b : S8_MIN;
max_energy = max(energy_a, energy_b);
IWL_DEBUG_STATS(mvm, "energy In A %d B %d, and max %d\n",
energy_a, energy_b, max_energy);
rx_status->signal = max_energy;
rx_status->chains = 0;
rx_status->chain_signal[0] = energy_a;
rx_status->chain_signal[1] = energy_b;
rx_status->chain_signal[2] = S8_MIN;
}
static int iwl_mvm_rx_crypto(struct iwl_mvm *mvm, struct ieee80211_hdr *hdr,
struct ieee80211_rx_status *stats,
struct iwl_rx_mpdu_desc *desc, int queue,
u8 *crypt_len)
{
u16 status = le16_to_cpu(desc->status);
if (!ieee80211_has_protected(hdr->frame_control) ||
(status & IWL_RX_MPDU_STATUS_SEC_MASK) ==
IWL_RX_MPDU_STATUS_SEC_NONE)
return 0;
switch (status & IWL_RX_MPDU_STATUS_SEC_MASK) {
case IWL_RX_MPDU_STATUS_SEC_CCM:
case IWL_RX_MPDU_STATUS_SEC_GCM:
BUILD_BUG_ON(IEEE80211_CCMP_PN_LEN != IEEE80211_GCMP_PN_LEN);
if (!(status & IWL_RX_MPDU_STATUS_MIC_OK))
return -1;
stats->flag |= RX_FLAG_DECRYPTED;
*crypt_len = IEEE80211_CCMP_HDR_LEN;
return 0;
case IWL_RX_MPDU_STATUS_SEC_TKIP:
if (!(status & IWL_RX_MPDU_RES_STATUS_TTAK_OK))
return 0;
*crypt_len = IEEE80211_TKIP_IV_LEN;
case IWL_RX_MPDU_STATUS_SEC_WEP:
if (!(status & IWL_RX_MPDU_STATUS_ICV_OK))
return -1;
stats->flag |= RX_FLAG_DECRYPTED;
if ((status & IWL_RX_MPDU_STATUS_SEC_MASK) ==
IWL_RX_MPDU_STATUS_SEC_WEP)
*crypt_len = IEEE80211_WEP_IV_LEN;
return 0;
case IWL_RX_MPDU_STATUS_SEC_EXT_ENC:
if (!(status & IWL_RX_MPDU_STATUS_MIC_OK))
return -1;
stats->flag |= RX_FLAG_DECRYPTED;
return 0;
default:
IWL_ERR(mvm, "Unhandled alg: 0x%x\n", status);
}
return 0;
}
static void iwl_mvm_rx_csum(struct ieee80211_sta *sta,
struct sk_buff *skb,
struct iwl_rx_mpdu_desc *desc)
{
struct iwl_mvm_sta *mvmsta = iwl_mvm_sta_from_mac80211(sta);
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(mvmsta->vif);
u16 flags = le16_to_cpu(desc->l3l4_flags);
u8 l3_prot = (u8)((flags & IWL_RX_L3L4_L3_PROTO_MASK) >>
IWL_RX_L3_PROTO_POS);
if (mvmvif->features & NETIF_F_RXCSUM &&
flags & IWL_RX_L3L4_TCP_UDP_CSUM_OK &&
(flags & IWL_RX_L3L4_IP_HDR_CSUM_OK ||
l3_prot == IWL_RX_L3_TYPE_IPV6 ||
l3_prot == IWL_RX_L3_TYPE_IPV6_FRAG))
skb->ip_summed = CHECKSUM_UNNECESSARY;
}
static bool iwl_mvm_is_nonagg_dup(struct ieee80211_sta *sta, int queue,
struct ieee80211_rx_status *rx_status,
struct ieee80211_hdr *hdr,
struct iwl_rx_mpdu_desc *desc)
{
struct iwl_mvm_sta *mvm_sta;
struct iwl_mvm_rxq_dup_data *dup_data;
u8 baid, tid, sub_frame_idx;
if (WARN_ON(IS_ERR_OR_NULL(sta)))
return false;
baid = (le32_to_cpu(desc->reorder_data) &
IWL_RX_MPDU_REORDER_BAID_MASK) >>
IWL_RX_MPDU_REORDER_BAID_SHIFT;
if (baid != IWL_RX_REORDER_DATA_INVALID_BAID)
return false;
mvm_sta = iwl_mvm_sta_from_mac80211(sta);
dup_data = &mvm_sta->dup_data[queue];
if (ieee80211_is_ctl(hdr->frame_control) ||
ieee80211_is_qos_nullfunc(hdr->frame_control) ||
is_multicast_ether_addr(hdr->addr1)) {
rx_status->flag |= RX_FLAG_DUP_VALIDATED;
return false;
}
if (ieee80211_is_data_qos(hdr->frame_control))
tid = *ieee80211_get_qos_ctl(hdr) &
IEEE80211_QOS_CTL_TID_MASK;
else
tid = IWL_MAX_TID_COUNT;
sub_frame_idx = desc->amsdu_info & IWL_RX_MPDU_AMSDU_SUBFRAME_IDX_MASK;
if (unlikely(ieee80211_has_retry(hdr->frame_control) &&
dup_data->last_seq[tid] == hdr->seq_ctrl &&
dup_data->last_sub_frame[tid] >= sub_frame_idx))
return true;
dup_data->last_seq[tid] = hdr->seq_ctrl;
dup_data->last_sub_frame[tid] = sub_frame_idx;
rx_status->flag |= RX_FLAG_DUP_VALIDATED;
return false;
}
int iwl_mvm_notify_rx_queue(struct iwl_mvm *mvm, u32 rxq_mask,
const u8 *data, u32 count)
{
struct iwl_rxq_sync_cmd *cmd;
u32 data_size = sizeof(*cmd) + count;
int ret;
if (WARN_ON(count & 3 || count > IWL_MULTI_QUEUE_SYNC_MSG_MAX_SIZE))
return -EINVAL;
cmd = kzalloc(data_size, GFP_KERNEL);
if (!cmd)
return -ENOMEM;
cmd->rxq_mask = cpu_to_le32(rxq_mask);
cmd->count = cpu_to_le32(count);
cmd->flags = 0;
memcpy(cmd->payload, data, count);
ret = iwl_mvm_send_cmd_pdu(mvm,
WIDE_ID(DATA_PATH_GROUP,
TRIGGER_RX_QUEUES_NOTIF_CMD),
0, data_size, cmd);
kfree(cmd);
return ret;
}
static bool iwl_mvm_is_sn_less(u16 sn1, u16 sn2, u16 buffer_size)
{
return ieee80211_sn_less(sn1, sn2) &&
!ieee80211_sn_less(sn1, sn2 - buffer_size);
}
static void iwl_mvm_release_frames(struct iwl_mvm *mvm,
struct ieee80211_sta *sta,
struct napi_struct *napi,
struct iwl_mvm_reorder_buffer *reorder_buf,
u16 nssn)
{
u16 ssn = reorder_buf->head_sn;
lockdep_assert_held(&reorder_buf->lock);
if (iwl_mvm_is_sn_less(nssn, ssn, reorder_buf->buf_size))
return;
while (iwl_mvm_is_sn_less(ssn, nssn, reorder_buf->buf_size)) {
int index = ssn % reorder_buf->buf_size;
struct sk_buff_head *skb_list = &reorder_buf->entries[index];
struct sk_buff *skb;
ssn = ieee80211_sn_inc(ssn);
if (skb_queue_empty(skb_list) || !skb_peek_tail(skb_list))
continue;
while ((skb = __skb_dequeue(skb_list))) {
iwl_mvm_pass_packet_to_mac80211(mvm, napi, skb,
reorder_buf->queue,
sta);
reorder_buf->num_stored--;
}
}
reorder_buf->head_sn = nssn;
if (reorder_buf->num_stored && !reorder_buf->removed) {
u16 index = reorder_buf->head_sn % reorder_buf->buf_size;
while (!skb_peek_tail(&reorder_buf->entries[index]))
index = (index + 1) % reorder_buf->buf_size;
mod_timer(&reorder_buf->reorder_timer,
reorder_buf->reorder_time[index] + 1 +
RX_REORDER_BUF_TIMEOUT_MQ);
} else {
del_timer(&reorder_buf->reorder_timer);
}
}
void iwl_mvm_reorder_timer_expired(unsigned long data)
{
struct iwl_mvm_reorder_buffer *buf = (void *)data;
int i;
u16 sn = 0, index = 0;
bool expired = false;
spin_lock_bh(&buf->lock);
if (!buf->num_stored || buf->removed) {
spin_unlock_bh(&buf->lock);
return;
}
for (i = 0; i < buf->buf_size ; i++) {
index = (buf->head_sn + i) % buf->buf_size;
if (!skb_peek_tail(&buf->entries[index]))
continue;
if (!time_after(jiffies, buf->reorder_time[index] +
RX_REORDER_BUF_TIMEOUT_MQ))
break;
expired = true;
sn = ieee80211_sn_add(buf->head_sn, i + 1);
}
if (expired) {
struct ieee80211_sta *sta;
rcu_read_lock();
sta = rcu_dereference(buf->mvm->fw_id_to_mac_id[buf->sta_id]);
IWL_DEBUG_HT(buf->mvm,
"Releasing expired frames for sta %u, sn %d\n",
buf->sta_id, sn);
iwl_mvm_release_frames(buf->mvm, sta, NULL, buf, sn);
rcu_read_unlock();
} else if (buf->num_stored) {
mod_timer(&buf->reorder_timer,
buf->reorder_time[index] +
1 + RX_REORDER_BUF_TIMEOUT_MQ);
}
spin_unlock_bh(&buf->lock);
}
static void iwl_mvm_del_ba(struct iwl_mvm *mvm, int queue,
struct iwl_mvm_delba_data *data)
{
struct iwl_mvm_baid_data *ba_data;
struct ieee80211_sta *sta;
struct iwl_mvm_reorder_buffer *reorder_buf;
u8 baid = data->baid;
if (WARN_ON_ONCE(baid >= IWL_RX_REORDER_DATA_INVALID_BAID))
return;
rcu_read_lock();
ba_data = rcu_dereference(mvm->baid_map[baid]);
if (WARN_ON_ONCE(!ba_data))
goto out;
sta = rcu_dereference(mvm->fw_id_to_mac_id[ba_data->sta_id]);
if (WARN_ON_ONCE(IS_ERR_OR_NULL(sta)))
goto out;
reorder_buf = &ba_data->reorder_buf[queue];
spin_lock_bh(&reorder_buf->lock);
iwl_mvm_release_frames(mvm, sta, NULL, reorder_buf,
ieee80211_sn_add(reorder_buf->head_sn,
reorder_buf->buf_size));
spin_unlock_bh(&reorder_buf->lock);
del_timer_sync(&reorder_buf->reorder_timer);
out:
rcu_read_unlock();
}
void iwl_mvm_rx_queue_notif(struct iwl_mvm *mvm, struct iwl_rx_cmd_buffer *rxb,
int queue)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
struct iwl_rxq_sync_notification *notif;
struct iwl_mvm_internal_rxq_notif *internal_notif;
notif = (void *)pkt->data;
internal_notif = (void *)notif->payload;
if (internal_notif->sync) {
if (mvm->queue_sync_cookie != internal_notif->cookie) {
WARN_ONCE(1,
"Received expired RX queue sync message\n");
return;
}
atomic_dec(&mvm->queue_sync_counter);
}
switch (internal_notif->type) {
case IWL_MVM_RXQ_EMPTY:
break;
case IWL_MVM_RXQ_NOTIF_DEL_BA:
iwl_mvm_del_ba(mvm, queue, (void *)internal_notif->data);
break;
default:
WARN_ONCE(1, "Invalid identifier %d", internal_notif->type);
}
}
static bool iwl_mvm_reorder(struct iwl_mvm *mvm,
struct napi_struct *napi,
int queue,
struct ieee80211_sta *sta,
struct sk_buff *skb,
struct iwl_rx_mpdu_desc *desc)
{
struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)skb->data;
struct iwl_mvm_sta *mvm_sta;
struct iwl_mvm_baid_data *baid_data;
struct iwl_mvm_reorder_buffer *buffer;
struct sk_buff *tail;
u32 reorder = le32_to_cpu(desc->reorder_data);
bool amsdu = desc->mac_flags2 & IWL_RX_MPDU_MFLG2_AMSDU;
bool last_subframe =
desc->amsdu_info & IWL_RX_MPDU_AMSDU_LAST_SUBFRAME;
u8 tid = *ieee80211_get_qos_ctl(hdr) & IEEE80211_QOS_CTL_TID_MASK;
u8 sub_frame_idx = desc->amsdu_info &
IWL_RX_MPDU_AMSDU_SUBFRAME_IDX_MASK;
int index;
u16 nssn, sn;
u8 baid;
baid = (reorder & IWL_RX_MPDU_REORDER_BAID_MASK) >>
IWL_RX_MPDU_REORDER_BAID_SHIFT;
if (baid == IWL_RX_REORDER_DATA_INVALID_BAID)
return false;
if (WARN_ON(IS_ERR_OR_NULL(sta)))
return false;
mvm_sta = iwl_mvm_sta_from_mac80211(sta);
if (!ieee80211_is_data_qos(hdr->frame_control) ||
is_multicast_ether_addr(hdr->addr1))
return false;
if (unlikely(!ieee80211_is_data_present(hdr->frame_control)))
return false;
baid_data = rcu_dereference(mvm->baid_map[baid]);
if (WARN(!baid_data,
"Received baid %d, but no data exists for this BAID\n", baid))
return false;
if (WARN(tid != baid_data->tid || mvm_sta->sta_id != baid_data->sta_id,
"baid 0x%x is mapped to sta:%d tid:%d, but was received for sta:%d tid:%d\n",
baid, baid_data->sta_id, baid_data->tid, mvm_sta->sta_id,
tid))
return false;
nssn = reorder & IWL_RX_MPDU_REORDER_NSSN_MASK;
sn = (reorder & IWL_RX_MPDU_REORDER_SN_MASK) >>
IWL_RX_MPDU_REORDER_SN_SHIFT;
buffer = &baid_data->reorder_buf[queue];
spin_lock_bh(&buffer->lock);
if (!iwl_mvm_is_sn_less(nssn, buffer->head_sn + buffer->buf_size,
buffer->buf_size)) {
u16 min_sn = ieee80211_sn_less(sn, nssn) ? sn : nssn;
iwl_mvm_release_frames(mvm, sta, napi, buffer, min_sn);
}
if (ieee80211_sn_less(sn, buffer->head_sn))
goto drop;
if (!buffer->num_stored && ieee80211_sn_less(sn, nssn)) {
if (iwl_mvm_is_sn_less(buffer->head_sn, nssn,
buffer->buf_size) &&
(!amsdu || last_subframe))
buffer->head_sn = nssn;
spin_unlock_bh(&buffer->lock);
return false;
}
index = sn % buffer->buf_size;
tail = skb_peek_tail(&buffer->entries[index]);
if (tail && !amsdu)
goto drop;
else if (tail && (sn != buffer->last_amsdu ||
buffer->last_sub_index >= sub_frame_idx))
goto drop;
__skb_queue_tail(&buffer->entries[index], skb);
buffer->num_stored++;
buffer->reorder_time[index] = jiffies;
if (amsdu) {
buffer->last_amsdu = sn;
buffer->last_sub_index = sub_frame_idx;
}
if (!amsdu || last_subframe)
iwl_mvm_release_frames(mvm, sta, napi, buffer, nssn);
spin_unlock_bh(&buffer->lock);
return true;
drop:
kfree_skb(skb);
spin_unlock_bh(&buffer->lock);
return true;
}
static void iwl_mvm_agg_rx_received(struct iwl_mvm *mvm, u8 baid)
{
unsigned long now = jiffies;
unsigned long timeout;
struct iwl_mvm_baid_data *data;
rcu_read_lock();
data = rcu_dereference(mvm->baid_map[baid]);
if (WARN_ON(!data))
goto out;
if (!data->timeout)
goto out;
timeout = data->timeout;
if (time_before(data->last_rx + TU_TO_JIFFIES(timeout), now))
data->last_rx = now;
out:
rcu_read_unlock();
}
void iwl_mvm_rx_mpdu_mq(struct iwl_mvm *mvm, struct napi_struct *napi,
struct iwl_rx_cmd_buffer *rxb, int queue)
{
struct ieee80211_rx_status *rx_status;
struct iwl_rx_packet *pkt = rxb_addr(rxb);
struct iwl_rx_mpdu_desc *desc = (void *)pkt->data;
struct ieee80211_hdr *hdr = (void *)(pkt->data + sizeof(*desc));
u32 len = le16_to_cpu(desc->mpdu_len);
u32 rate_n_flags = le32_to_cpu(desc->rate_n_flags);
u16 phy_info = le16_to_cpu(desc->phy_info);
struct ieee80211_sta *sta = NULL;
struct sk_buff *skb;
u8 crypt_len = 0;
skb = alloc_skb(128, GFP_ATOMIC);
if (!skb) {
IWL_ERR(mvm, "alloc_skb failed\n");
return;
}
rx_status = IEEE80211_SKB_RXCB(skb);
if (iwl_mvm_rx_crypto(mvm, hdr, rx_status, desc, queue, &crypt_len)) {
kfree_skb(skb);
return;
}
if (!(desc->status & cpu_to_le16(IWL_RX_MPDU_STATUS_CRC_OK)) ||
!(desc->status & cpu_to_le16(IWL_RX_MPDU_STATUS_OVERRUN_OK))) {
IWL_DEBUG_RX(mvm, "Bad CRC or FIFO: 0x%08X.\n",
le16_to_cpu(desc->status));
rx_status->flag |= RX_FLAG_FAILED_FCS_CRC;
}
if (phy_info & IWL_RX_MPDU_PHY_SHORT_PREAMBLE)
rx_status->flag |= RX_FLAG_SHORTPRE;
if (likely(!(phy_info & IWL_RX_MPDU_PHY_TSF_OVERLOAD))) {
rx_status->mactime = le64_to_cpu(desc->tsf_on_air_rise);
rx_status->flag |= RX_FLAG_MACTIME_PLCP_START;
}
rx_status->device_timestamp = le32_to_cpu(desc->gp2_on_air_rise);
rx_status->band = desc->channel > 14 ? NL80211_BAND_5GHZ :
NL80211_BAND_2GHZ;
rx_status->freq = ieee80211_channel_to_frequency(desc->channel,
rx_status->band);
iwl_mvm_get_signal_strength(mvm, desc, rx_status);
if (!queue && (phy_info & IWL_RX_MPDU_PHY_AMPDU)) {
bool toggle_bit = phy_info & IWL_RX_MPDU_PHY_AMPDU_TOGGLE;
rx_status->flag |= RX_FLAG_AMPDU_DETAILS;
rx_status->ampdu_reference = mvm->ampdu_ref;
if (toggle_bit != mvm->ampdu_toggle) {
mvm->ampdu_ref++;
mvm->ampdu_toggle = toggle_bit;
}
}
rcu_read_lock();
if (le16_to_cpu(desc->status) & IWL_RX_MPDU_STATUS_SRC_STA_FOUND) {
u8 id = desc->sta_id_flags & IWL_RX_MPDU_SIF_STA_ID_MASK;
if (!WARN_ON_ONCE(id >= IWL_MVM_STATION_COUNT)) {
sta = rcu_dereference(mvm->fw_id_to_mac_id[id]);
if (IS_ERR(sta))
sta = NULL;
}
} else if (!is_multicast_ether_addr(hdr->addr2)) {
sta = ieee80211_find_sta_by_ifaddr(mvm->hw, hdr->addr2, NULL);
}
if (sta) {
struct iwl_mvm_sta *mvmsta = iwl_mvm_sta_from_mac80211(sta);
struct ieee80211_vif *tx_blocked_vif =
rcu_dereference(mvm->csa_tx_blocked_vif);
u8 baid = (u8)((le32_to_cpu(desc->reorder_data) &
IWL_RX_MPDU_REORDER_BAID_MASK) >>
IWL_RX_MPDU_REORDER_BAID_SHIFT);
if (unlikely(tx_blocked_vif) &&
tx_blocked_vif == mvmsta->vif) {
struct iwl_mvm_vif *mvmvif =
iwl_mvm_vif_from_mac80211(tx_blocked_vif);
if (mvmvif->csa_target_freq == rx_status->freq)
iwl_mvm_sta_modify_disable_tx_ap(mvm, sta,
false);
}
rs_update_last_rssi(mvm, &mvmsta->lq_sta, rx_status);
if (iwl_fw_dbg_trigger_enabled(mvm->fw, FW_DBG_TRIGGER_RSSI) &&
ieee80211_is_beacon(hdr->frame_control)) {
struct iwl_fw_dbg_trigger_tlv *trig;
struct iwl_fw_dbg_trigger_low_rssi *rssi_trig;
bool trig_check;
s32 rssi;
trig = iwl_fw_dbg_get_trigger(mvm->fw,
FW_DBG_TRIGGER_RSSI);
rssi_trig = (void *)trig->data;
rssi = le32_to_cpu(rssi_trig->rssi);
trig_check =
iwl_fw_dbg_trigger_check_stop(mvm, mvmsta->vif,
trig);
if (trig_check && rx_status->signal < rssi)
iwl_mvm_fw_dbg_collect_trig(mvm, trig, NULL);
}
if (ieee80211_is_data(hdr->frame_control))
iwl_mvm_rx_csum(sta, skb, desc);
if (iwl_mvm_is_nonagg_dup(sta, queue, rx_status, hdr, desc)) {
kfree_skb(skb);
rcu_read_unlock();
return;
}
if ((desc->mac_flags2 & IWL_RX_MPDU_MFLG2_AMSDU) &&
!WARN_ON(!ieee80211_is_data_qos(hdr->frame_control))) {
u8 *qc = ieee80211_get_qos_ctl(hdr);
*qc &= ~IEEE80211_QOS_CTL_A_MSDU_PRESENT;
}
if (baid != IWL_RX_REORDER_DATA_INVALID_BAID)
iwl_mvm_agg_rx_received(mvm, baid);
}
switch (rate_n_flags & RATE_MCS_CHAN_WIDTH_MSK) {
case RATE_MCS_CHAN_WIDTH_20:
break;
case RATE_MCS_CHAN_WIDTH_40:
rx_status->flag |= RX_FLAG_40MHZ;
break;
case RATE_MCS_CHAN_WIDTH_80:
rx_status->vht_flag |= RX_VHT_FLAG_80MHZ;
break;
case RATE_MCS_CHAN_WIDTH_160:
rx_status->vht_flag |= RX_VHT_FLAG_160MHZ;
break;
}
if (rate_n_flags & RATE_MCS_SGI_MSK)
rx_status->flag |= RX_FLAG_SHORT_GI;
if (rate_n_flags & RATE_HT_MCS_GF_MSK)
rx_status->flag |= RX_FLAG_HT_GF;
if (rate_n_flags & RATE_MCS_LDPC_MSK)
rx_status->flag |= RX_FLAG_LDPC;
if (rate_n_flags & RATE_MCS_HT_MSK) {
u8 stbc = (rate_n_flags & RATE_MCS_HT_STBC_MSK) >>
RATE_MCS_STBC_POS;
rx_status->flag |= RX_FLAG_HT;
rx_status->rate_idx = rate_n_flags & RATE_HT_MCS_INDEX_MSK;
rx_status->flag |= stbc << RX_FLAG_STBC_SHIFT;
} else if (rate_n_flags & RATE_MCS_VHT_MSK) {
u8 stbc = (rate_n_flags & RATE_MCS_VHT_STBC_MSK) >>
RATE_MCS_STBC_POS;
rx_status->vht_nss =
((rate_n_flags & RATE_VHT_MCS_NSS_MSK) >>
RATE_VHT_MCS_NSS_POS) + 1;
rx_status->rate_idx = rate_n_flags & RATE_VHT_MCS_RATE_CODE_MSK;
rx_status->flag |= RX_FLAG_VHT;
rx_status->flag |= stbc << RX_FLAG_STBC_SHIFT;
if (rate_n_flags & RATE_MCS_BF_MSK)
rx_status->vht_flag |= RX_VHT_FLAG_BF;
} else {
rx_status->rate_idx =
iwl_mvm_legacy_rate_to_mac80211_idx(rate_n_flags,
rx_status->band);
}
if (!queue) {
if (unlikely((ieee80211_is_beacon(hdr->frame_control) ||
ieee80211_is_probe_resp(hdr->frame_control)) &&
mvm->sched_scan_pass_all ==
SCHED_SCAN_PASS_ALL_ENABLED))
mvm->sched_scan_pass_all = SCHED_SCAN_PASS_ALL_FOUND;
if (unlikely(ieee80211_is_beacon(hdr->frame_control) ||
ieee80211_is_probe_resp(hdr->frame_control)))
rx_status->boottime_ns = ktime_get_boot_ns();
}
iwl_mvm_create_skb(skb, hdr, len, crypt_len, rxb);
if (!iwl_mvm_reorder(mvm, napi, queue, sta, skb, desc))
iwl_mvm_pass_packet_to_mac80211(mvm, napi, skb, queue, sta);
rcu_read_unlock();
}
void iwl_mvm_rx_frame_release(struct iwl_mvm *mvm, struct napi_struct *napi,
struct iwl_rx_cmd_buffer *rxb, int queue)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
struct iwl_frame_release *release = (void *)pkt->data;
struct ieee80211_sta *sta;
struct iwl_mvm_reorder_buffer *reorder_buf;
struct iwl_mvm_baid_data *ba_data;
int baid = release->baid;
IWL_DEBUG_HT(mvm, "Frame release notification for BAID %u, NSSN %d\n",
release->baid, le16_to_cpu(release->nssn));
if (WARN_ON_ONCE(baid == IWL_RX_REORDER_DATA_INVALID_BAID))
return;
rcu_read_lock();
ba_data = rcu_dereference(mvm->baid_map[baid]);
if (WARN_ON_ONCE(!ba_data))
goto out;
sta = rcu_dereference(mvm->fw_id_to_mac_id[ba_data->sta_id]);
if (WARN_ON_ONCE(IS_ERR_OR_NULL(sta)))
goto out;
reorder_buf = &ba_data->reorder_buf[queue];
spin_lock_bh(&reorder_buf->lock);
iwl_mvm_release_frames(mvm, sta, napi, reorder_buf,
le16_to_cpu(release->nssn));
spin_unlock_bh(&reorder_buf->lock);
out:
rcu_read_unlock();
}
