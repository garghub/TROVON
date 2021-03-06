struct sk_buff *rt2x00queue_alloc_rxskb(struct queue_entry *entry, gfp_t gfp)
{
struct rt2x00_dev *rt2x00dev = entry->queue->rt2x00dev;
struct sk_buff *skb;
struct skb_frame_desc *skbdesc;
unsigned int frame_size;
unsigned int head_size = 0;
unsigned int tail_size = 0;
frame_size = entry->queue->data_size + entry->queue->desc_size;
head_size = 4;
if (test_bit(CAPABILITY_HW_CRYPTO, &rt2x00dev->cap_flags)) {
head_size += 8;
tail_size += 8;
}
skb = __dev_alloc_skb(frame_size + head_size + tail_size, gfp);
if (!skb)
return NULL;
skb_reserve(skb, head_size);
skb_put(skb, frame_size);
skbdesc = get_skb_frame_desc(skb);
memset(skbdesc, 0, sizeof(*skbdesc));
skbdesc->entry = entry;
if (test_bit(REQUIRE_DMA, &rt2x00dev->cap_flags)) {
skbdesc->skb_dma = dma_map_single(rt2x00dev->dev,
skb->data,
skb->len,
DMA_FROM_DEVICE);
skbdesc->flags |= SKBDESC_DMA_MAPPED_RX;
}
return skb;
}
void rt2x00queue_map_txskb(struct queue_entry *entry)
{
struct device *dev = entry->queue->rt2x00dev->dev;
struct skb_frame_desc *skbdesc = get_skb_frame_desc(entry->skb);
skbdesc->skb_dma =
dma_map_single(dev, entry->skb->data, entry->skb->len, DMA_TO_DEVICE);
skbdesc->flags |= SKBDESC_DMA_MAPPED_TX;
}
void rt2x00queue_unmap_skb(struct queue_entry *entry)
{
struct device *dev = entry->queue->rt2x00dev->dev;
struct skb_frame_desc *skbdesc = get_skb_frame_desc(entry->skb);
if (skbdesc->flags & SKBDESC_DMA_MAPPED_RX) {
dma_unmap_single(dev, skbdesc->skb_dma, entry->skb->len,
DMA_FROM_DEVICE);
skbdesc->flags &= ~SKBDESC_DMA_MAPPED_RX;
} else if (skbdesc->flags & SKBDESC_DMA_MAPPED_TX) {
dma_unmap_single(dev, skbdesc->skb_dma, entry->skb->len,
DMA_TO_DEVICE);
skbdesc->flags &= ~SKBDESC_DMA_MAPPED_TX;
}
}
void rt2x00queue_free_skb(struct queue_entry *entry)
{
if (!entry->skb)
return;
rt2x00queue_unmap_skb(entry);
dev_kfree_skb_any(entry->skb);
entry->skb = NULL;
}
void rt2x00queue_align_frame(struct sk_buff *skb)
{
unsigned int frame_length = skb->len;
unsigned int align = ALIGN_SIZE(skb, 0);
if (!align)
return;
skb_push(skb, align);
memmove(skb->data, skb->data + align, frame_length);
skb_trim(skb, frame_length);
}
void rt2x00queue_insert_l2pad(struct sk_buff *skb, unsigned int header_length)
{
unsigned int payload_length = skb->len - header_length;
unsigned int header_align = ALIGN_SIZE(skb, 0);
unsigned int payload_align = ALIGN_SIZE(skb, header_length);
unsigned int l2pad = payload_length ? L2PAD_SIZE(header_length) : 0;
if (payload_align > header_align)
header_align += 4;
if (!header_align)
return;
skb_push(skb, header_align);
memmove(skb->data, skb->data + header_align, header_length);
if (payload_length && payload_align)
memmove(skb->data + header_length + l2pad,
skb->data + header_length + l2pad + payload_align,
payload_length);
skb_trim(skb, header_length + l2pad + payload_length);
}
void rt2x00queue_remove_l2pad(struct sk_buff *skb, unsigned int header_length)
{
unsigned int l2pad = (skb->len > header_length) ?
L2PAD_SIZE(header_length) : 0;
if (!l2pad)
return;
memmove(skb->data + l2pad, skb->data, header_length);
skb_pull(skb, l2pad);
}
static void rt2x00queue_create_tx_descriptor_seq(struct rt2x00_dev *rt2x00dev,
struct sk_buff *skb,
struct txentry_desc *txdesc)
{
struct ieee80211_tx_info *tx_info = IEEE80211_SKB_CB(skb);
struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)skb->data;
struct rt2x00_intf *intf = vif_to_intf(tx_info->control.vif);
u16 seqno;
if (!(tx_info->flags & IEEE80211_TX_CTL_ASSIGN_SEQ))
return;
__set_bit(ENTRY_TXD_GENERATE_SEQ, &txdesc->flags);
if (!test_bit(REQUIRE_SW_SEQNO, &rt2x00dev->cap_flags)) {
if (test_bit(CONFIG_QOS_DISABLED, &rt2x00dev->flags))
__clear_bit(ENTRY_TXD_GENERATE_SEQ, &txdesc->flags);
else
return;
}
if (test_bit(ENTRY_TXD_FIRST_FRAGMENT, &txdesc->flags))
seqno = atomic_add_return(0x10, &intf->seqno);
else
seqno = atomic_read(&intf->seqno);
hdr->seq_ctrl &= cpu_to_le16(IEEE80211_SCTL_FRAG);
hdr->seq_ctrl |= cpu_to_le16(seqno);
}
static void rt2x00queue_create_tx_descriptor_plcp(struct rt2x00_dev *rt2x00dev,
struct sk_buff *skb,
struct txentry_desc *txdesc,
const struct rt2x00_rate *hwrate)
{
struct ieee80211_tx_info *tx_info = IEEE80211_SKB_CB(skb);
struct ieee80211_tx_rate *txrate = &tx_info->control.rates[0];
unsigned int data_length;
unsigned int duration;
unsigned int residual;
if (test_bit(ENTRY_TXD_FIRST_FRAGMENT, &txdesc->flags))
txdesc->u.plcp.ifs = IFS_BACKOFF;
else
txdesc->u.plcp.ifs = IFS_SIFS;
data_length = skb->len + 4;
data_length += rt2x00crypto_tx_overhead(rt2x00dev, skb);
txdesc->u.plcp.signal = hwrate->plcp;
txdesc->u.plcp.service = 0x04;
if (hwrate->flags & DEV_RATE_OFDM) {
txdesc->u.plcp.length_high = (data_length >> 6) & 0x3f;
txdesc->u.plcp.length_low = data_length & 0x3f;
} else {
residual = GET_DURATION_RES(data_length, hwrate->bitrate);
duration = GET_DURATION(data_length, hwrate->bitrate);
if (residual != 0) {
duration++;
if (hwrate->bitrate == 110 && residual <= 30)
txdesc->u.plcp.service |= 0x80;
}
txdesc->u.plcp.length_high = (duration >> 8) & 0xff;
txdesc->u.plcp.length_low = duration & 0xff;
if (txrate->flags & IEEE80211_TX_RC_USE_SHORT_PREAMBLE)
txdesc->u.plcp.signal |= 0x08;
}
}
static void rt2x00queue_create_tx_descriptor_ht(struct rt2x00_dev *rt2x00dev,
struct sk_buff *skb,
struct txentry_desc *txdesc,
const struct rt2x00_rate *hwrate)
{
struct ieee80211_tx_info *tx_info = IEEE80211_SKB_CB(skb);
struct ieee80211_tx_rate *txrate = &tx_info->control.rates[0];
struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)skb->data;
struct rt2x00_sta *sta_priv = NULL;
if (tx_info->control.sta) {
txdesc->u.ht.mpdu_density =
tx_info->control.sta->ht_cap.ampdu_density;
sta_priv = sta_to_rt2x00_sta(tx_info->control.sta);
txdesc->u.ht.wcid = sta_priv->wcid;
}
if (txrate->flags & IEEE80211_TX_RC_MCS) {
txdesc->u.ht.mcs = txrate->idx;
if (tx_info->control.sta && txdesc->u.ht.mcs > 7 &&
((tx_info->control.sta->ht_cap.cap &
IEEE80211_HT_CAP_SM_PS) >>
IEEE80211_HT_CAP_SM_PS_SHIFT) ==
WLAN_HT_CAP_SM_PS_DYNAMIC)
__set_bit(ENTRY_TXD_HT_MIMO_PS, &txdesc->flags);
} else {
txdesc->u.ht.mcs = rt2x00_get_rate_mcs(hwrate->mcs);
if (txrate->flags & IEEE80211_TX_RC_USE_SHORT_PREAMBLE)
txdesc->u.ht.mcs |= 0x08;
}
if (test_bit(CONFIG_HT_DISABLED, &rt2x00dev->flags)) {
if (!(tx_info->flags & IEEE80211_TX_CTL_FIRST_FRAGMENT))
txdesc->u.ht.txop = TXOP_SIFS;
else
txdesc->u.ht.txop = TXOP_BACKOFF;
return;
}
txdesc->u.ht.ba_size = 7;
if (tx_info->flags & IEEE80211_TX_CTL_STBC)
txdesc->u.ht.stbc = 1;
if (tx_info->flags & IEEE80211_TX_CTL_AMPDU &&
!(tx_info->flags & IEEE80211_TX_CTL_RATE_CTRL_PROBE))
__set_bit(ENTRY_TXD_HT_AMPDU, &txdesc->flags);
if (txrate->flags & IEEE80211_TX_RC_40_MHZ_WIDTH ||
txrate->flags & IEEE80211_TX_RC_DUP_DATA)
__set_bit(ENTRY_TXD_HT_BW_40, &txdesc->flags);
if (txrate->flags & IEEE80211_TX_RC_SHORT_GI)
__set_bit(ENTRY_TXD_HT_SHORT_GI, &txdesc->flags);
if (ieee80211_is_mgmt(hdr->frame_control) &&
!ieee80211_is_beacon(hdr->frame_control))
txdesc->u.ht.txop = TXOP_BACKOFF;
else if (!(tx_info->flags & IEEE80211_TX_CTL_FIRST_FRAGMENT))
txdesc->u.ht.txop = TXOP_SIFS;
else
txdesc->u.ht.txop = TXOP_HTTXOP;
}
static void rt2x00queue_create_tx_descriptor(struct rt2x00_dev *rt2x00dev,
struct sk_buff *skb,
struct txentry_desc *txdesc)
{
struct ieee80211_tx_info *tx_info = IEEE80211_SKB_CB(skb);
struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)skb->data;
struct ieee80211_tx_rate *txrate = &tx_info->control.rates[0];
struct ieee80211_rate *rate;
const struct rt2x00_rate *hwrate = NULL;
memset(txdesc, 0, sizeof(*txdesc));
txdesc->length = skb->len;
txdesc->header_length = ieee80211_get_hdrlen_from_skb(skb);
if (!(tx_info->flags & IEEE80211_TX_CTL_NO_ACK))
__set_bit(ENTRY_TXD_ACK, &txdesc->flags);
if (ieee80211_is_rts(hdr->frame_control) ||
ieee80211_is_cts(hdr->frame_control)) {
__set_bit(ENTRY_TXD_BURST, &txdesc->flags);
if (ieee80211_is_rts(hdr->frame_control))
__set_bit(ENTRY_TXD_RTS_FRAME, &txdesc->flags);
else
__set_bit(ENTRY_TXD_CTS_FRAME, &txdesc->flags);
if (tx_info->control.rts_cts_rate_idx >= 0)
rate =
ieee80211_get_rts_cts_rate(rt2x00dev->hw, tx_info);
}
txdesc->retry_limit = tx_info->control.rates[0].count - 1;
if (txdesc->retry_limit >= rt2x00dev->long_retry)
__set_bit(ENTRY_TXD_RETRY_MODE, &txdesc->flags);
if (ieee80211_has_morefrags(hdr->frame_control)) {
__set_bit(ENTRY_TXD_BURST, &txdesc->flags);
__set_bit(ENTRY_TXD_MORE_FRAG, &txdesc->flags);
}
if (tx_info->flags & IEEE80211_TX_CTL_MORE_FRAMES)
__set_bit(ENTRY_TXD_BURST, &txdesc->flags);
if (ieee80211_is_beacon(hdr->frame_control) ||
ieee80211_is_probe_resp(hdr->frame_control))
__set_bit(ENTRY_TXD_REQ_TIMESTAMP, &txdesc->flags);
if ((tx_info->flags & IEEE80211_TX_CTL_FIRST_FRAGMENT) &&
!test_bit(ENTRY_TXD_RTS_FRAME, &txdesc->flags))
__set_bit(ENTRY_TXD_FIRST_FRAGMENT, &txdesc->flags);
if (txrate->flags & IEEE80211_TX_RC_GREEN_FIELD)
txdesc->rate_mode = RATE_MODE_HT_GREENFIELD;
else if (txrate->flags & IEEE80211_TX_RC_MCS)
txdesc->rate_mode = RATE_MODE_HT_MIX;
else {
rate = ieee80211_get_tx_rate(rt2x00dev->hw, tx_info);
hwrate = rt2x00_get_rate(rate->hw_value);
if (hwrate->flags & DEV_RATE_OFDM)
txdesc->rate_mode = RATE_MODE_OFDM;
else
txdesc->rate_mode = RATE_MODE_CCK;
}
rt2x00crypto_create_tx_descriptor(rt2x00dev, skb, txdesc);
rt2x00queue_create_tx_descriptor_seq(rt2x00dev, skb, txdesc);
if (test_bit(REQUIRE_HT_TX_DESC, &rt2x00dev->cap_flags))
rt2x00queue_create_tx_descriptor_ht(rt2x00dev, skb, txdesc,
hwrate);
else
rt2x00queue_create_tx_descriptor_plcp(rt2x00dev, skb, txdesc,
hwrate);
}
static int rt2x00queue_write_tx_data(struct queue_entry *entry,
struct txentry_desc *txdesc)
{
struct rt2x00_dev *rt2x00dev = entry->queue->rt2x00dev;
if (unlikely(rt2x00dev->ops->lib->get_entry_state &&
rt2x00dev->ops->lib->get_entry_state(entry))) {
ERROR(rt2x00dev,
"Corrupt queue %d, accessing entry which is not ours.\n"
"Please file bug report to %s.\n",
entry->queue->qid, DRV_PROJECT);
return -EINVAL;
}
skb_push(entry->skb, rt2x00dev->ops->extra_tx_headroom);
memset(entry->skb->data, 0, rt2x00dev->ops->extra_tx_headroom);
if (rt2x00dev->ops->lib->write_tx_data)
rt2x00dev->ops->lib->write_tx_data(entry, txdesc);
if (test_bit(REQUIRE_DMA, &rt2x00dev->cap_flags))
rt2x00queue_map_txskb(entry);
return 0;
}
static void rt2x00queue_write_tx_descriptor(struct queue_entry *entry,
struct txentry_desc *txdesc)
{
struct data_queue *queue = entry->queue;
queue->rt2x00dev->ops->lib->write_tx_desc(entry, txdesc);
rt2x00debug_dump_frame(queue->rt2x00dev, DUMP_FRAME_TX, entry->skb);
}
static void rt2x00queue_kick_tx_queue(struct data_queue *queue,
struct txentry_desc *txdesc)
{
if (rt2x00queue_threshold(queue) ||
!test_bit(ENTRY_TXD_BURST, &txdesc->flags))
queue->rt2x00dev->ops->lib->kick_queue(queue);
}
int rt2x00queue_write_tx_frame(struct data_queue *queue, struct sk_buff *skb,
bool local)
{
struct ieee80211_tx_info *tx_info;
struct queue_entry *entry;
struct txentry_desc txdesc;
struct skb_frame_desc *skbdesc;
u8 rate_idx, rate_flags;
int ret = 0;
rt2x00queue_create_tx_descriptor(queue->rt2x00dev, skb, &txdesc);
tx_info = IEEE80211_SKB_CB(skb);
rate_idx = tx_info->control.rates[0].idx;
rate_flags = tx_info->control.rates[0].flags;
skbdesc = get_skb_frame_desc(skb);
memset(skbdesc, 0, sizeof(*skbdesc));
skbdesc->tx_rate_idx = rate_idx;
skbdesc->tx_rate_flags = rate_flags;
if (local)
skbdesc->flags |= SKBDESC_NOT_MAC80211;
if (test_bit(ENTRY_TXD_ENCRYPT, &txdesc.flags) &&
!test_bit(ENTRY_TXD_ENCRYPT_IV, &txdesc.flags)) {
if (test_bit(REQUIRE_COPY_IV, &queue->rt2x00dev->cap_flags))
rt2x00crypto_tx_copy_iv(skb, &txdesc);
else
rt2x00crypto_tx_remove_iv(skb, &txdesc);
}
if (test_bit(REQUIRE_L2PAD, &queue->rt2x00dev->cap_flags))
rt2x00queue_insert_l2pad(skb, txdesc.header_length);
else if (test_bit(REQUIRE_DMA, &queue->rt2x00dev->cap_flags))
rt2x00queue_align_frame(skb);
spin_lock(&queue->tx_lock);
if (unlikely(rt2x00queue_full(queue))) {
ERROR(queue->rt2x00dev,
"Dropping frame due to full tx queue %d.\n", queue->qid);
ret = -ENOBUFS;
goto out;
}
entry = rt2x00queue_get_entry(queue, Q_INDEX);
if (unlikely(test_and_set_bit(ENTRY_OWNER_DEVICE_DATA,
&entry->flags))) {
ERROR(queue->rt2x00dev,
"Arrived at non-free entry in the non-full queue %d.\n"
"Please file bug report to %s.\n",
queue->qid, DRV_PROJECT);
ret = -EINVAL;
goto out;
}
skbdesc->entry = entry;
entry->skb = skb;
if (unlikely(rt2x00queue_write_tx_data(entry, &txdesc))) {
clear_bit(ENTRY_OWNER_DEVICE_DATA, &entry->flags);
entry->skb = NULL;
ret = -EIO;
goto out;
}
set_bit(ENTRY_DATA_PENDING, &entry->flags);
rt2x00queue_index_inc(entry, Q_INDEX);
rt2x00queue_write_tx_descriptor(entry, &txdesc);
rt2x00queue_kick_tx_queue(queue, &txdesc);
out:
spin_unlock(&queue->tx_lock);
return ret;
}
int rt2x00queue_clear_beacon(struct rt2x00_dev *rt2x00dev,
struct ieee80211_vif *vif)
{
struct rt2x00_intf *intf = vif_to_intf(vif);
if (unlikely(!intf->beacon))
return -ENOBUFS;
mutex_lock(&intf->beacon_skb_mutex);
rt2x00queue_free_skb(intf->beacon);
if (rt2x00dev->ops->lib->clear_beacon)
rt2x00dev->ops->lib->clear_beacon(intf->beacon);
mutex_unlock(&intf->beacon_skb_mutex);
return 0;
}
int rt2x00queue_update_beacon_locked(struct rt2x00_dev *rt2x00dev,
struct ieee80211_vif *vif)
{
struct rt2x00_intf *intf = vif_to_intf(vif);
struct skb_frame_desc *skbdesc;
struct txentry_desc txdesc;
if (unlikely(!intf->beacon))
return -ENOBUFS;
rt2x00queue_free_skb(intf->beacon);
intf->beacon->skb = ieee80211_beacon_get(rt2x00dev->hw, vif);
if (!intf->beacon->skb)
return -ENOMEM;
rt2x00queue_create_tx_descriptor(rt2x00dev, intf->beacon->skb, &txdesc);
skbdesc = get_skb_frame_desc(intf->beacon->skb);
memset(skbdesc, 0, sizeof(*skbdesc));
skbdesc->entry = intf->beacon;
rt2x00dev->ops->lib->write_beacon(intf->beacon, &txdesc);
return 0;
}
int rt2x00queue_update_beacon(struct rt2x00_dev *rt2x00dev,
struct ieee80211_vif *vif)
{
struct rt2x00_intf *intf = vif_to_intf(vif);
int ret;
mutex_lock(&intf->beacon_skb_mutex);
ret = rt2x00queue_update_beacon_locked(rt2x00dev, vif);
mutex_unlock(&intf->beacon_skb_mutex);
return ret;
}
bool rt2x00queue_for_each_entry(struct data_queue *queue,
enum queue_index start,
enum queue_index end,
void *data,
bool (*fn)(struct queue_entry *entry,
void *data))
{
unsigned long irqflags;
unsigned int index_start;
unsigned int index_end;
unsigned int i;
if (unlikely(start >= Q_INDEX_MAX || end >= Q_INDEX_MAX)) {
ERROR(queue->rt2x00dev,
"Entry requested from invalid index range (%d - %d)\n",
start, end);
return true;
}
spin_lock_irqsave(&queue->index_lock, irqflags);
index_start = queue->index[start];
index_end = queue->index[end];
spin_unlock_irqrestore(&queue->index_lock, irqflags);
if (index_start < index_end) {
for (i = index_start; i < index_end; i++) {
if (fn(&queue->entries[i], data))
return true;
}
} else {
for (i = index_start; i < queue->limit; i++) {
if (fn(&queue->entries[i], data))
return true;
}
for (i = 0; i < index_end; i++) {
if (fn(&queue->entries[i], data))
return true;
}
}
return false;
}
struct queue_entry *rt2x00queue_get_entry(struct data_queue *queue,
enum queue_index index)
{
struct queue_entry *entry;
unsigned long irqflags;
if (unlikely(index >= Q_INDEX_MAX)) {
ERROR(queue->rt2x00dev,
"Entry requested from invalid index type (%d)\n", index);
return NULL;
}
spin_lock_irqsave(&queue->index_lock, irqflags);
entry = &queue->entries[queue->index[index]];
spin_unlock_irqrestore(&queue->index_lock, irqflags);
return entry;
}
void rt2x00queue_index_inc(struct queue_entry *entry, enum queue_index index)
{
struct data_queue *queue = entry->queue;
unsigned long irqflags;
if (unlikely(index >= Q_INDEX_MAX)) {
ERROR(queue->rt2x00dev,
"Index change on invalid index type (%d)\n", index);
return;
}
spin_lock_irqsave(&queue->index_lock, irqflags);
queue->index[index]++;
if (queue->index[index] >= queue->limit)
queue->index[index] = 0;
entry->last_action = jiffies;
if (index == Q_INDEX) {
queue->length++;
} else if (index == Q_INDEX_DONE) {
queue->length--;
queue->count++;
}
spin_unlock_irqrestore(&queue->index_lock, irqflags);
}
void rt2x00queue_pause_queue(struct data_queue *queue)
{
if (!test_bit(DEVICE_STATE_PRESENT, &queue->rt2x00dev->flags) ||
!test_bit(QUEUE_STARTED, &queue->flags) ||
test_and_set_bit(QUEUE_PAUSED, &queue->flags))
return;
switch (queue->qid) {
case QID_AC_VO:
case QID_AC_VI:
case QID_AC_BE:
case QID_AC_BK:
ieee80211_stop_queue(queue->rt2x00dev->hw, queue->qid);
break;
default:
break;
}
}
void rt2x00queue_unpause_queue(struct data_queue *queue)
{
if (!test_bit(DEVICE_STATE_PRESENT, &queue->rt2x00dev->flags) ||
!test_bit(QUEUE_STARTED, &queue->flags) ||
!test_and_clear_bit(QUEUE_PAUSED, &queue->flags))
return;
switch (queue->qid) {
case QID_AC_VO:
case QID_AC_VI:
case QID_AC_BE:
case QID_AC_BK:
ieee80211_wake_queue(queue->rt2x00dev->hw, queue->qid);
break;
case QID_RX:
queue->rt2x00dev->ops->lib->kick_queue(queue);
default:
break;
}
}
void rt2x00queue_start_queue(struct data_queue *queue)
{
mutex_lock(&queue->status_lock);
if (!test_bit(DEVICE_STATE_PRESENT, &queue->rt2x00dev->flags) ||
test_and_set_bit(QUEUE_STARTED, &queue->flags)) {
mutex_unlock(&queue->status_lock);
return;
}
set_bit(QUEUE_PAUSED, &queue->flags);
queue->rt2x00dev->ops->lib->start_queue(queue);
rt2x00queue_unpause_queue(queue);
mutex_unlock(&queue->status_lock);
}
void rt2x00queue_stop_queue(struct data_queue *queue)
{
mutex_lock(&queue->status_lock);
if (!test_and_clear_bit(QUEUE_STARTED, &queue->flags)) {
mutex_unlock(&queue->status_lock);
return;
}
rt2x00queue_pause_queue(queue);
queue->rt2x00dev->ops->lib->stop_queue(queue);
mutex_unlock(&queue->status_lock);
}
void rt2x00queue_flush_queue(struct data_queue *queue, bool drop)
{
bool started;
bool tx_queue =
(queue->qid == QID_AC_VO) ||
(queue->qid == QID_AC_VI) ||
(queue->qid == QID_AC_BE) ||
(queue->qid == QID_AC_BK);
mutex_lock(&queue->status_lock);
started = test_bit(QUEUE_STARTED, &queue->flags);
if (started) {
rt2x00queue_pause_queue(queue);
if (!drop && tx_queue)
queue->rt2x00dev->ops->lib->kick_queue(queue);
}
if (likely(queue->rt2x00dev->ops->lib->flush_queue))
queue->rt2x00dev->ops->lib->flush_queue(queue, drop);
if (unlikely(!rt2x00queue_empty(queue)))
WARNING(queue->rt2x00dev, "Queue %d failed to flush\n", queue->qid);
if (started)
rt2x00queue_unpause_queue(queue);
mutex_unlock(&queue->status_lock);
}
void rt2x00queue_start_queues(struct rt2x00_dev *rt2x00dev)
{
struct data_queue *queue;
tx_queue_for_each(rt2x00dev, queue)
rt2x00queue_start_queue(queue);
rt2x00queue_start_queue(rt2x00dev->rx);
}
void rt2x00queue_stop_queues(struct rt2x00_dev *rt2x00dev)
{
struct data_queue *queue;
ieee80211_stop_queues(rt2x00dev->hw);
tx_queue_for_each(rt2x00dev, queue)
rt2x00queue_stop_queue(queue);
rt2x00queue_stop_queue(rt2x00dev->rx);
}
void rt2x00queue_flush_queues(struct rt2x00_dev *rt2x00dev, bool drop)
{
struct data_queue *queue;
tx_queue_for_each(rt2x00dev, queue)
rt2x00queue_flush_queue(queue, drop);
rt2x00queue_flush_queue(rt2x00dev->rx, drop);
}
static void rt2x00queue_reset(struct data_queue *queue)
{
unsigned long irqflags;
unsigned int i;
spin_lock_irqsave(&queue->index_lock, irqflags);
queue->count = 0;
queue->length = 0;
for (i = 0; i < Q_INDEX_MAX; i++)
queue->index[i] = 0;
spin_unlock_irqrestore(&queue->index_lock, irqflags);
}
void rt2x00queue_init_queues(struct rt2x00_dev *rt2x00dev)
{
struct data_queue *queue;
unsigned int i;
queue_for_each(rt2x00dev, queue) {
rt2x00queue_reset(queue);
for (i = 0; i < queue->limit; i++)
rt2x00dev->ops->lib->clear_entry(&queue->entries[i]);
}
}
static int rt2x00queue_alloc_entries(struct data_queue *queue,
const struct data_queue_desc *qdesc)
{
struct queue_entry *entries;
unsigned int entry_size;
unsigned int i;
rt2x00queue_reset(queue);
queue->limit = qdesc->entry_num;
queue->threshold = DIV_ROUND_UP(qdesc->entry_num, 10);
queue->data_size = qdesc->data_size;
queue->desc_size = qdesc->desc_size;
entry_size = sizeof(*entries) + qdesc->priv_size;
entries = kcalloc(queue->limit, entry_size, GFP_KERNEL);
if (!entries)
return -ENOMEM;
#define QUEUE_ENTRY_PRIV_OFFSET(__base, __index, __limit, __esize, __psize) \
(((char *)(__base)) + ((__limit) * (__esize)) + \
((__index) * (__psize)))
for (i = 0; i < queue->limit; i++) {
entries[i].flags = 0;
entries[i].queue = queue;
entries[i].skb = NULL;
entries[i].entry_idx = i;
entries[i].priv_data =
QUEUE_ENTRY_PRIV_OFFSET(entries, i, queue->limit,
sizeof(*entries), qdesc->priv_size);
}
#undef QUEUE_ENTRY_PRIV_OFFSET
queue->entries = entries;
return 0;
}
static void rt2x00queue_free_skbs(struct data_queue *queue)
{
unsigned int i;
if (!queue->entries)
return;
for (i = 0; i < queue->limit; i++) {
rt2x00queue_free_skb(&queue->entries[i]);
}
}
static int rt2x00queue_alloc_rxskbs(struct data_queue *queue)
{
unsigned int i;
struct sk_buff *skb;
for (i = 0; i < queue->limit; i++) {
skb = rt2x00queue_alloc_rxskb(&queue->entries[i], GFP_KERNEL);
if (!skb)
return -ENOMEM;
queue->entries[i].skb = skb;
}
return 0;
}
int rt2x00queue_initialize(struct rt2x00_dev *rt2x00dev)
{
struct data_queue *queue;
int status;
status = rt2x00queue_alloc_entries(rt2x00dev->rx, rt2x00dev->ops->rx);
if (status)
goto exit;
tx_queue_for_each(rt2x00dev, queue) {
status = rt2x00queue_alloc_entries(queue, rt2x00dev->ops->tx);
if (status)
goto exit;
}
status = rt2x00queue_alloc_entries(rt2x00dev->bcn, rt2x00dev->ops->bcn);
if (status)
goto exit;
if (test_bit(REQUIRE_ATIM_QUEUE, &rt2x00dev->cap_flags)) {
status = rt2x00queue_alloc_entries(rt2x00dev->atim,
rt2x00dev->ops->atim);
if (status)
goto exit;
}
status = rt2x00queue_alloc_rxskbs(rt2x00dev->rx);
if (status)
goto exit;
return 0;
exit:
ERROR(rt2x00dev, "Queue entries allocation failed.\n");
rt2x00queue_uninitialize(rt2x00dev);
return status;
}
void rt2x00queue_uninitialize(struct rt2x00_dev *rt2x00dev)
{
struct data_queue *queue;
rt2x00queue_free_skbs(rt2x00dev->rx);
queue_for_each(rt2x00dev, queue) {
kfree(queue->entries);
queue->entries = NULL;
}
}
static void rt2x00queue_init(struct rt2x00_dev *rt2x00dev,
struct data_queue *queue, enum data_queue_qid qid)
{
mutex_init(&queue->status_lock);
spin_lock_init(&queue->tx_lock);
spin_lock_init(&queue->index_lock);
queue->rt2x00dev = rt2x00dev;
queue->qid = qid;
queue->txop = 0;
queue->aifs = 2;
queue->cw_min = 5;
queue->cw_max = 10;
}
int rt2x00queue_allocate(struct rt2x00_dev *rt2x00dev)
{
struct data_queue *queue;
enum data_queue_qid qid;
unsigned int req_atim =
!!test_bit(REQUIRE_ATIM_QUEUE, &rt2x00dev->cap_flags);
rt2x00dev->data_queues = 2 + rt2x00dev->ops->tx_queues + req_atim;
queue = kcalloc(rt2x00dev->data_queues, sizeof(*queue), GFP_KERNEL);
if (!queue) {
ERROR(rt2x00dev, "Queue allocation failed.\n");
return -ENOMEM;
}
rt2x00dev->rx = queue;
rt2x00dev->tx = &queue[1];
rt2x00dev->bcn = &queue[1 + rt2x00dev->ops->tx_queues];
rt2x00dev->atim = req_atim ? &queue[2 + rt2x00dev->ops->tx_queues] : NULL;
rt2x00queue_init(rt2x00dev, rt2x00dev->rx, QID_RX);
qid = QID_AC_VO;
tx_queue_for_each(rt2x00dev, queue)
rt2x00queue_init(rt2x00dev, queue, qid++);
rt2x00queue_init(rt2x00dev, rt2x00dev->bcn, QID_BEACON);
if (req_atim)
rt2x00queue_init(rt2x00dev, rt2x00dev->atim, QID_ATIM);
return 0;
}
void rt2x00queue_free(struct rt2x00_dev *rt2x00dev)
{
kfree(rt2x00dev->rx);
rt2x00dev->rx = NULL;
rt2x00dev->tx = NULL;
rt2x00dev->bcn = NULL;
}
