static void ixgbevf_service_event_schedule(struct ixgbevf_adapter *adapter)
{
if (!test_bit(__IXGBEVF_DOWN, &adapter->state) &&
!test_bit(__IXGBEVF_REMOVING, &adapter->state) &&
!test_and_set_bit(__IXGBEVF_SERVICE_SCHED, &adapter->state))
schedule_work(&adapter->service_task);
}
static void ixgbevf_service_event_complete(struct ixgbevf_adapter *adapter)
{
BUG_ON(!test_bit(__IXGBEVF_SERVICE_SCHED, &adapter->state));
smp_mb__before_atomic();
clear_bit(__IXGBEVF_SERVICE_SCHED, &adapter->state);
}
static void ixgbevf_remove_adapter(struct ixgbe_hw *hw)
{
struct ixgbevf_adapter *adapter = hw->back;
if (!hw->hw_addr)
return;
hw->hw_addr = NULL;
dev_err(&adapter->pdev->dev, "Adapter removed\n");
if (test_bit(__IXGBEVF_SERVICE_INITED, &adapter->state))
ixgbevf_service_event_schedule(adapter);
}
static void ixgbevf_check_remove(struct ixgbe_hw *hw, u32 reg)
{
u32 value;
if (reg == IXGBE_VFSTATUS) {
ixgbevf_remove_adapter(hw);
return;
}
value = ixgbevf_read_reg(hw, IXGBE_VFSTATUS);
if (value == IXGBE_FAILED_READ_REG)
ixgbevf_remove_adapter(hw);
}
u32 ixgbevf_read_reg(struct ixgbe_hw *hw, u32 reg)
{
u8 __iomem *reg_addr = ACCESS_ONCE(hw->hw_addr);
u32 value;
if (IXGBE_REMOVED(reg_addr))
return IXGBE_FAILED_READ_REG;
value = readl(reg_addr + reg);
if (unlikely(value == IXGBE_FAILED_READ_REG))
ixgbevf_check_remove(hw, reg);
return value;
}
static void ixgbevf_set_ivar(struct ixgbevf_adapter *adapter, s8 direction,
u8 queue, u8 msix_vector)
{
u32 ivar, index;
struct ixgbe_hw *hw = &adapter->hw;
if (direction == -1) {
msix_vector |= IXGBE_IVAR_ALLOC_VAL;
ivar = IXGBE_READ_REG(hw, IXGBE_VTIVAR_MISC);
ivar &= ~0xFF;
ivar |= msix_vector;
IXGBE_WRITE_REG(hw, IXGBE_VTIVAR_MISC, ivar);
} else {
msix_vector |= IXGBE_IVAR_ALLOC_VAL;
index = ((16 * (queue & 1)) + (8 * direction));
ivar = IXGBE_READ_REG(hw, IXGBE_VTIVAR(queue >> 1));
ivar &= ~(0xFF << index);
ivar |= (msix_vector << index);
IXGBE_WRITE_REG(hw, IXGBE_VTIVAR(queue >> 1), ivar);
}
}
static void ixgbevf_unmap_and_free_tx_resource(struct ixgbevf_ring *tx_ring,
struct ixgbevf_tx_buffer *tx_buffer)
{
if (tx_buffer->skb) {
dev_kfree_skb_any(tx_buffer->skb);
if (dma_unmap_len(tx_buffer, len))
dma_unmap_single(tx_ring->dev,
dma_unmap_addr(tx_buffer, dma),
dma_unmap_len(tx_buffer, len),
DMA_TO_DEVICE);
} else if (dma_unmap_len(tx_buffer, len)) {
dma_unmap_page(tx_ring->dev,
dma_unmap_addr(tx_buffer, dma),
dma_unmap_len(tx_buffer, len),
DMA_TO_DEVICE);
}
tx_buffer->next_to_watch = NULL;
tx_buffer->skb = NULL;
dma_unmap_len_set(tx_buffer, len, 0);
}
static u64 ixgbevf_get_tx_completed(struct ixgbevf_ring *ring)
{
return ring->stats.packets;
}
static u32 ixgbevf_get_tx_pending(struct ixgbevf_ring *ring)
{
struct ixgbevf_adapter *adapter = netdev_priv(ring->netdev);
struct ixgbe_hw *hw = &adapter->hw;
u32 head = IXGBE_READ_REG(hw, IXGBE_VFTDH(ring->reg_idx));
u32 tail = IXGBE_READ_REG(hw, IXGBE_VFTDT(ring->reg_idx));
if (head != tail)
return (head < tail) ?
tail - head : (tail + ring->count - head);
return 0;
}
static inline bool ixgbevf_check_tx_hang(struct ixgbevf_ring *tx_ring)
{
u32 tx_done = ixgbevf_get_tx_completed(tx_ring);
u32 tx_done_old = tx_ring->tx_stats.tx_done_old;
u32 tx_pending = ixgbevf_get_tx_pending(tx_ring);
clear_check_for_tx_hang(tx_ring);
if ((tx_done_old == tx_done) && tx_pending) {
return test_and_set_bit(__IXGBEVF_HANG_CHECK_ARMED,
&tx_ring->state);
}
clear_bit(__IXGBEVF_HANG_CHECK_ARMED, &tx_ring->state);
tx_ring->tx_stats.tx_done_old = tx_done;
return false;
}
static void ixgbevf_tx_timeout_reset(struct ixgbevf_adapter *adapter)
{
if (!test_bit(__IXGBEVF_DOWN, &adapter->state)) {
adapter->flags |= IXGBEVF_FLAG_RESET_REQUESTED;
ixgbevf_service_event_schedule(adapter);
}
}
static void ixgbevf_tx_timeout(struct net_device *netdev)
{
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
ixgbevf_tx_timeout_reset(adapter);
}
static bool ixgbevf_clean_tx_irq(struct ixgbevf_q_vector *q_vector,
struct ixgbevf_ring *tx_ring)
{
struct ixgbevf_adapter *adapter = q_vector->adapter;
struct ixgbevf_tx_buffer *tx_buffer;
union ixgbe_adv_tx_desc *tx_desc;
unsigned int total_bytes = 0, total_packets = 0;
unsigned int budget = tx_ring->count / 2;
unsigned int i = tx_ring->next_to_clean;
if (test_bit(__IXGBEVF_DOWN, &adapter->state))
return true;
tx_buffer = &tx_ring->tx_buffer_info[i];
tx_desc = IXGBEVF_TX_DESC(tx_ring, i);
i -= tx_ring->count;
do {
union ixgbe_adv_tx_desc *eop_desc = tx_buffer->next_to_watch;
if (!eop_desc)
break;
read_barrier_depends();
if (!(eop_desc->wb.status & cpu_to_le32(IXGBE_TXD_STAT_DD)))
break;
tx_buffer->next_to_watch = NULL;
total_bytes += tx_buffer->bytecount;
total_packets += tx_buffer->gso_segs;
dev_kfree_skb_any(tx_buffer->skb);
dma_unmap_single(tx_ring->dev,
dma_unmap_addr(tx_buffer, dma),
dma_unmap_len(tx_buffer, len),
DMA_TO_DEVICE);
tx_buffer->skb = NULL;
dma_unmap_len_set(tx_buffer, len, 0);
while (tx_desc != eop_desc) {
tx_buffer++;
tx_desc++;
i++;
if (unlikely(!i)) {
i -= tx_ring->count;
tx_buffer = tx_ring->tx_buffer_info;
tx_desc = IXGBEVF_TX_DESC(tx_ring, 0);
}
if (dma_unmap_len(tx_buffer, len)) {
dma_unmap_page(tx_ring->dev,
dma_unmap_addr(tx_buffer, dma),
dma_unmap_len(tx_buffer, len),
DMA_TO_DEVICE);
dma_unmap_len_set(tx_buffer, len, 0);
}
}
tx_buffer++;
tx_desc++;
i++;
if (unlikely(!i)) {
i -= tx_ring->count;
tx_buffer = tx_ring->tx_buffer_info;
tx_desc = IXGBEVF_TX_DESC(tx_ring, 0);
}
prefetch(tx_desc);
budget--;
} while (likely(budget));
i += tx_ring->count;
tx_ring->next_to_clean = i;
u64_stats_update_begin(&tx_ring->syncp);
tx_ring->stats.bytes += total_bytes;
tx_ring->stats.packets += total_packets;
u64_stats_update_end(&tx_ring->syncp);
q_vector->tx.total_bytes += total_bytes;
q_vector->tx.total_packets += total_packets;
if (check_for_tx_hang(tx_ring) && ixgbevf_check_tx_hang(tx_ring)) {
struct ixgbe_hw *hw = &adapter->hw;
union ixgbe_adv_tx_desc *eop_desc;
eop_desc = tx_ring->tx_buffer_info[i].next_to_watch;
pr_err("Detected Tx Unit Hang\n"
" Tx Queue <%d>\n"
" TDH, TDT <%x>, <%x>\n"
" next_to_use <%x>\n"
" next_to_clean <%x>\n"
"tx_buffer_info[next_to_clean]\n"
" next_to_watch <%p>\n"
" eop_desc->wb.status <%x>\n"
" time_stamp <%lx>\n"
" jiffies <%lx>\n",
tx_ring->queue_index,
IXGBE_READ_REG(hw, IXGBE_VFTDH(tx_ring->reg_idx)),
IXGBE_READ_REG(hw, IXGBE_VFTDT(tx_ring->reg_idx)),
tx_ring->next_to_use, i,
eop_desc, (eop_desc ? eop_desc->wb.status : 0),
tx_ring->tx_buffer_info[i].time_stamp, jiffies);
netif_stop_subqueue(tx_ring->netdev, tx_ring->queue_index);
ixgbevf_tx_timeout_reset(adapter);
return true;
}
#define TX_WAKE_THRESHOLD (DESC_NEEDED * 2)
if (unlikely(total_packets && netif_carrier_ok(tx_ring->netdev) &&
(ixgbevf_desc_unused(tx_ring) >= TX_WAKE_THRESHOLD))) {
smp_mb();
if (__netif_subqueue_stopped(tx_ring->netdev,
tx_ring->queue_index) &&
!test_bit(__IXGBEVF_DOWN, &adapter->state)) {
netif_wake_subqueue(tx_ring->netdev,
tx_ring->queue_index);
++tx_ring->tx_stats.restart_queue;
}
}
return !!budget;
}
static void ixgbevf_rx_skb(struct ixgbevf_q_vector *q_vector,
struct sk_buff *skb)
{
#ifdef CONFIG_NET_RX_BUSY_POLL
skb_mark_napi_id(skb, &q_vector->napi);
if (ixgbevf_qv_busy_polling(q_vector)) {
netif_receive_skb(skb);
return;
}
#endif
napi_gro_receive(&q_vector->napi, skb);
}
static inline void ixgbevf_rx_checksum(struct ixgbevf_ring *ring,
union ixgbe_adv_rx_desc *rx_desc,
struct sk_buff *skb)
{
skb_checksum_none_assert(skb);
if (!(ring->netdev->features & NETIF_F_RXCSUM))
return;
if (ixgbevf_test_staterr(rx_desc, IXGBE_RXD_STAT_IPCS) &&
ixgbevf_test_staterr(rx_desc, IXGBE_RXDADV_ERR_IPE)) {
ring->rx_stats.csum_err++;
return;
}
if (!ixgbevf_test_staterr(rx_desc, IXGBE_RXD_STAT_L4CS))
return;
if (ixgbevf_test_staterr(rx_desc, IXGBE_RXDADV_ERR_TCPE)) {
ring->rx_stats.csum_err++;
return;
}
skb->ip_summed = CHECKSUM_UNNECESSARY;
}
static void ixgbevf_process_skb_fields(struct ixgbevf_ring *rx_ring,
union ixgbe_adv_rx_desc *rx_desc,
struct sk_buff *skb)
{
ixgbevf_rx_checksum(rx_ring, rx_desc, skb);
if (ixgbevf_test_staterr(rx_desc, IXGBE_RXD_STAT_VP)) {
u16 vid = le16_to_cpu(rx_desc->wb.upper.vlan);
unsigned long *active_vlans = netdev_priv(rx_ring->netdev);
if (test_bit(vid & VLAN_VID_MASK, active_vlans))
__vlan_hwaccel_put_tag(skb, htons(ETH_P_8021Q), vid);
}
skb->protocol = eth_type_trans(skb, rx_ring->netdev);
}
static bool ixgbevf_is_non_eop(struct ixgbevf_ring *rx_ring,
union ixgbe_adv_rx_desc *rx_desc)
{
u32 ntc = rx_ring->next_to_clean + 1;
ntc = (ntc < rx_ring->count) ? ntc : 0;
rx_ring->next_to_clean = ntc;
prefetch(IXGBEVF_RX_DESC(rx_ring, ntc));
if (likely(ixgbevf_test_staterr(rx_desc, IXGBE_RXD_STAT_EOP)))
return false;
return true;
}
static bool ixgbevf_alloc_mapped_page(struct ixgbevf_ring *rx_ring,
struct ixgbevf_rx_buffer *bi)
{
struct page *page = bi->page;
dma_addr_t dma = bi->dma;
if (likely(page))
return true;
page = dev_alloc_page();
if (unlikely(!page)) {
rx_ring->rx_stats.alloc_rx_page_failed++;
return false;
}
dma = dma_map_page(rx_ring->dev, page, 0,
PAGE_SIZE, DMA_FROM_DEVICE);
if (dma_mapping_error(rx_ring->dev, dma)) {
__free_page(page);
rx_ring->rx_stats.alloc_rx_buff_failed++;
return false;
}
bi->dma = dma;
bi->page = page;
bi->page_offset = 0;
return true;
}
static void ixgbevf_alloc_rx_buffers(struct ixgbevf_ring *rx_ring,
u16 cleaned_count)
{
union ixgbe_adv_rx_desc *rx_desc;
struct ixgbevf_rx_buffer *bi;
unsigned int i = rx_ring->next_to_use;
if (!cleaned_count || !rx_ring->netdev)
return;
rx_desc = IXGBEVF_RX_DESC(rx_ring, i);
bi = &rx_ring->rx_buffer_info[i];
i -= rx_ring->count;
do {
if (!ixgbevf_alloc_mapped_page(rx_ring, bi))
break;
rx_desc->read.pkt_addr = cpu_to_le64(bi->dma + bi->page_offset);
rx_desc++;
bi++;
i++;
if (unlikely(!i)) {
rx_desc = IXGBEVF_RX_DESC(rx_ring, 0);
bi = rx_ring->rx_buffer_info;
i -= rx_ring->count;
}
rx_desc->read.hdr_addr = 0;
cleaned_count--;
} while (cleaned_count);
i += rx_ring->count;
if (rx_ring->next_to_use != i) {
rx_ring->next_to_use = i;
rx_ring->next_to_alloc = i;
wmb();
ixgbevf_write_tail(rx_ring, i);
}
}
static void ixgbevf_pull_tail(struct ixgbevf_ring *rx_ring,
struct sk_buff *skb)
{
struct skb_frag_struct *frag = &skb_shinfo(skb)->frags[0];
unsigned char *va;
unsigned int pull_len;
va = skb_frag_address(frag);
pull_len = eth_get_headlen(va, IXGBEVF_RX_HDR_SIZE);
skb_copy_to_linear_data(skb, va, ALIGN(pull_len, sizeof(long)));
skb_frag_size_sub(frag, pull_len);
frag->page_offset += pull_len;
skb->data_len -= pull_len;
skb->tail += pull_len;
}
static bool ixgbevf_cleanup_headers(struct ixgbevf_ring *rx_ring,
union ixgbe_adv_rx_desc *rx_desc,
struct sk_buff *skb)
{
if (unlikely(ixgbevf_test_staterr(rx_desc,
IXGBE_RXDADV_ERR_FRAME_ERR_MASK))) {
struct net_device *netdev = rx_ring->netdev;
if (!(netdev->features & NETIF_F_RXALL)) {
dev_kfree_skb_any(skb);
return true;
}
}
if (skb_is_nonlinear(skb))
ixgbevf_pull_tail(rx_ring, skb);
if (eth_skb_pad(skb))
return true;
return false;
}
static void ixgbevf_reuse_rx_page(struct ixgbevf_ring *rx_ring,
struct ixgbevf_rx_buffer *old_buff)
{
struct ixgbevf_rx_buffer *new_buff;
u16 nta = rx_ring->next_to_alloc;
new_buff = &rx_ring->rx_buffer_info[nta];
nta++;
rx_ring->next_to_alloc = (nta < rx_ring->count) ? nta : 0;
new_buff->page = old_buff->page;
new_buff->dma = old_buff->dma;
new_buff->page_offset = old_buff->page_offset;
dma_sync_single_range_for_device(rx_ring->dev, new_buff->dma,
new_buff->page_offset,
IXGBEVF_RX_BUFSZ,
DMA_FROM_DEVICE);
}
static inline bool ixgbevf_page_is_reserved(struct page *page)
{
return (page_to_nid(page) != numa_mem_id()) || page->pfmemalloc;
}
static bool ixgbevf_add_rx_frag(struct ixgbevf_ring *rx_ring,
struct ixgbevf_rx_buffer *rx_buffer,
union ixgbe_adv_rx_desc *rx_desc,
struct sk_buff *skb)
{
struct page *page = rx_buffer->page;
unsigned int size = le16_to_cpu(rx_desc->wb.upper.length);
#if (PAGE_SIZE < 8192)
unsigned int truesize = IXGBEVF_RX_BUFSZ;
#else
unsigned int truesize = ALIGN(size, L1_CACHE_BYTES);
#endif
if ((size <= IXGBEVF_RX_HDR_SIZE) && !skb_is_nonlinear(skb)) {
unsigned char *va = page_address(page) + rx_buffer->page_offset;
memcpy(__skb_put(skb, size), va, ALIGN(size, sizeof(long)));
if (likely(!ixgbevf_page_is_reserved(page)))
return true;
put_page(page);
return false;
}
skb_add_rx_frag(skb, skb_shinfo(skb)->nr_frags, page,
rx_buffer->page_offset, size, truesize);
if (unlikely(ixgbevf_page_is_reserved(page)))
return false;
#if (PAGE_SIZE < 8192)
if (unlikely(page_count(page) != 1))
return false;
rx_buffer->page_offset ^= IXGBEVF_RX_BUFSZ;
#else
rx_buffer->page_offset += truesize;
if (rx_buffer->page_offset > (PAGE_SIZE - IXGBEVF_RX_BUFSZ))
return false;
#endif
atomic_inc(&page->_count);
return true;
}
static struct sk_buff *ixgbevf_fetch_rx_buffer(struct ixgbevf_ring *rx_ring,
union ixgbe_adv_rx_desc *rx_desc,
struct sk_buff *skb)
{
struct ixgbevf_rx_buffer *rx_buffer;
struct page *page;
rx_buffer = &rx_ring->rx_buffer_info[rx_ring->next_to_clean];
page = rx_buffer->page;
prefetchw(page);
if (likely(!skb)) {
void *page_addr = page_address(page) +
rx_buffer->page_offset;
prefetch(page_addr);
#if L1_CACHE_BYTES < 128
prefetch(page_addr + L1_CACHE_BYTES);
#endif
skb = netdev_alloc_skb_ip_align(rx_ring->netdev,
IXGBEVF_RX_HDR_SIZE);
if (unlikely(!skb)) {
rx_ring->rx_stats.alloc_rx_buff_failed++;
return NULL;
}
prefetchw(skb->data);
}
dma_sync_single_range_for_cpu(rx_ring->dev,
rx_buffer->dma,
rx_buffer->page_offset,
IXGBEVF_RX_BUFSZ,
DMA_FROM_DEVICE);
if (ixgbevf_add_rx_frag(rx_ring, rx_buffer, rx_desc, skb)) {
ixgbevf_reuse_rx_page(rx_ring, rx_buffer);
} else {
dma_unmap_page(rx_ring->dev, rx_buffer->dma,
PAGE_SIZE, DMA_FROM_DEVICE);
}
rx_buffer->dma = 0;
rx_buffer->page = NULL;
return skb;
}
static inline void ixgbevf_irq_enable_queues(struct ixgbevf_adapter *adapter,
u32 qmask)
{
struct ixgbe_hw *hw = &adapter->hw;
IXGBE_WRITE_REG(hw, IXGBE_VTEIMS, qmask);
}
static int ixgbevf_clean_rx_irq(struct ixgbevf_q_vector *q_vector,
struct ixgbevf_ring *rx_ring,
int budget)
{
unsigned int total_rx_bytes = 0, total_rx_packets = 0;
u16 cleaned_count = ixgbevf_desc_unused(rx_ring);
struct sk_buff *skb = rx_ring->skb;
while (likely(total_rx_packets < budget)) {
union ixgbe_adv_rx_desc *rx_desc;
if (cleaned_count >= IXGBEVF_RX_BUFFER_WRITE) {
ixgbevf_alloc_rx_buffers(rx_ring, cleaned_count);
cleaned_count = 0;
}
rx_desc = IXGBEVF_RX_DESC(rx_ring, rx_ring->next_to_clean);
if (!ixgbevf_test_staterr(rx_desc, IXGBE_RXD_STAT_DD))
break;
rmb();
skb = ixgbevf_fetch_rx_buffer(rx_ring, rx_desc, skb);
if (!skb)
break;
cleaned_count++;
if (ixgbevf_is_non_eop(rx_ring, rx_desc))
continue;
if (ixgbevf_cleanup_headers(rx_ring, rx_desc, skb)) {
skb = NULL;
continue;
}
total_rx_bytes += skb->len;
if ((skb->pkt_type == PACKET_BROADCAST ||
skb->pkt_type == PACKET_MULTICAST) &&
ether_addr_equal(rx_ring->netdev->dev_addr,
eth_hdr(skb)->h_source)) {
dev_kfree_skb_irq(skb);
continue;
}
ixgbevf_process_skb_fields(rx_ring, rx_desc, skb);
ixgbevf_rx_skb(q_vector, skb);
skb = NULL;
total_rx_packets++;
}
rx_ring->skb = skb;
u64_stats_update_begin(&rx_ring->syncp);
rx_ring->stats.packets += total_rx_packets;
rx_ring->stats.bytes += total_rx_bytes;
u64_stats_update_end(&rx_ring->syncp);
q_vector->rx.total_packets += total_rx_packets;
q_vector->rx.total_bytes += total_rx_bytes;
return total_rx_packets;
}
static int ixgbevf_poll(struct napi_struct *napi, int budget)
{
struct ixgbevf_q_vector *q_vector =
container_of(napi, struct ixgbevf_q_vector, napi);
struct ixgbevf_adapter *adapter = q_vector->adapter;
struct ixgbevf_ring *ring;
int per_ring_budget;
bool clean_complete = true;
ixgbevf_for_each_ring(ring, q_vector->tx)
clean_complete &= ixgbevf_clean_tx_irq(q_vector, ring);
#ifdef CONFIG_NET_RX_BUSY_POLL
if (!ixgbevf_qv_lock_napi(q_vector))
return budget;
#endif
if (q_vector->rx.count > 1)
per_ring_budget = max(budget/q_vector->rx.count, 1);
else
per_ring_budget = budget;
ixgbevf_for_each_ring(ring, q_vector->rx)
clean_complete &= (ixgbevf_clean_rx_irq(q_vector, ring,
per_ring_budget)
< per_ring_budget);
#ifdef CONFIG_NET_RX_BUSY_POLL
ixgbevf_qv_unlock_napi(q_vector);
#endif
if (!clean_complete)
return budget;
napi_complete(napi);
if (adapter->rx_itr_setting & 1)
ixgbevf_set_itr(q_vector);
if (!test_bit(__IXGBEVF_DOWN, &adapter->state) &&
!test_bit(__IXGBEVF_REMOVING, &adapter->state))
ixgbevf_irq_enable_queues(adapter,
1 << q_vector->v_idx);
return 0;
}
void ixgbevf_write_eitr(struct ixgbevf_q_vector *q_vector)
{
struct ixgbevf_adapter *adapter = q_vector->adapter;
struct ixgbe_hw *hw = &adapter->hw;
int v_idx = q_vector->v_idx;
u32 itr_reg = q_vector->itr & IXGBE_MAX_EITR;
itr_reg |= IXGBE_EITR_CNT_WDIS;
IXGBE_WRITE_REG(hw, IXGBE_VTEITR(v_idx), itr_reg);
}
static int ixgbevf_busy_poll_recv(struct napi_struct *napi)
{
struct ixgbevf_q_vector *q_vector =
container_of(napi, struct ixgbevf_q_vector, napi);
struct ixgbevf_adapter *adapter = q_vector->adapter;
struct ixgbevf_ring *ring;
int found = 0;
if (test_bit(__IXGBEVF_DOWN, &adapter->state))
return LL_FLUSH_FAILED;
if (!ixgbevf_qv_lock_poll(q_vector))
return LL_FLUSH_BUSY;
ixgbevf_for_each_ring(ring, q_vector->rx) {
found = ixgbevf_clean_rx_irq(q_vector, ring, 4);
#ifdef BP_EXTENDED_STATS
if (found)
ring->stats.cleaned += found;
else
ring->stats.misses++;
#endif
if (found)
break;
}
ixgbevf_qv_unlock_poll(q_vector);
return found;
}
static void ixgbevf_configure_msix(struct ixgbevf_adapter *adapter)
{
struct ixgbevf_q_vector *q_vector;
int q_vectors, v_idx;
q_vectors = adapter->num_msix_vectors - NON_Q_VECTORS;
adapter->eims_enable_mask = 0;
for (v_idx = 0; v_idx < q_vectors; v_idx++) {
struct ixgbevf_ring *ring;
q_vector = adapter->q_vector[v_idx];
ixgbevf_for_each_ring(ring, q_vector->rx)
ixgbevf_set_ivar(adapter, 0, ring->reg_idx, v_idx);
ixgbevf_for_each_ring(ring, q_vector->tx)
ixgbevf_set_ivar(adapter, 1, ring->reg_idx, v_idx);
if (q_vector->tx.ring && !q_vector->rx.ring) {
if (adapter->tx_itr_setting == 1)
q_vector->itr = IXGBE_10K_ITR;
else
q_vector->itr = adapter->tx_itr_setting;
} else {
if (adapter->rx_itr_setting == 1)
q_vector->itr = IXGBE_20K_ITR;
else
q_vector->itr = adapter->rx_itr_setting;
}
adapter->eims_enable_mask |= 1 << v_idx;
ixgbevf_write_eitr(q_vector);
}
ixgbevf_set_ivar(adapter, -1, 1, v_idx);
adapter->eims_other = 1 << v_idx;
adapter->eims_enable_mask |= adapter->eims_other;
}
static void ixgbevf_update_itr(struct ixgbevf_q_vector *q_vector,
struct ixgbevf_ring_container *ring_container)
{
int bytes = ring_container->total_bytes;
int packets = ring_container->total_packets;
u32 timepassed_us;
u64 bytes_perint;
u8 itr_setting = ring_container->itr;
if (packets == 0)
return;
timepassed_us = q_vector->itr >> 2;
bytes_perint = bytes / timepassed_us;
switch (itr_setting) {
case lowest_latency:
if (bytes_perint > 10)
itr_setting = low_latency;
break;
case low_latency:
if (bytes_perint > 20)
itr_setting = bulk_latency;
else if (bytes_perint <= 10)
itr_setting = lowest_latency;
break;
case bulk_latency:
if (bytes_perint <= 20)
itr_setting = low_latency;
break;
}
ring_container->total_bytes = 0;
ring_container->total_packets = 0;
ring_container->itr = itr_setting;
}
static void ixgbevf_set_itr(struct ixgbevf_q_vector *q_vector)
{
u32 new_itr = q_vector->itr;
u8 current_itr;
ixgbevf_update_itr(q_vector, &q_vector->tx);
ixgbevf_update_itr(q_vector, &q_vector->rx);
current_itr = max(q_vector->rx.itr, q_vector->tx.itr);
switch (current_itr) {
case lowest_latency:
new_itr = IXGBE_100K_ITR;
break;
case low_latency:
new_itr = IXGBE_20K_ITR;
break;
case bulk_latency:
default:
new_itr = IXGBE_8K_ITR;
break;
}
if (new_itr != q_vector->itr) {
new_itr = (10 * new_itr * q_vector->itr) /
((9 * new_itr) + q_vector->itr);
q_vector->itr = new_itr;
ixgbevf_write_eitr(q_vector);
}
}
static irqreturn_t ixgbevf_msix_other(int irq, void *data)
{
struct ixgbevf_adapter *adapter = data;
struct ixgbe_hw *hw = &adapter->hw;
hw->mac.get_link_status = 1;
ixgbevf_service_event_schedule(adapter);
IXGBE_WRITE_REG(hw, IXGBE_VTEIMS, adapter->eims_other);
return IRQ_HANDLED;
}
static irqreturn_t ixgbevf_msix_clean_rings(int irq, void *data)
{
struct ixgbevf_q_vector *q_vector = data;
if (q_vector->rx.ring || q_vector->tx.ring)
napi_schedule(&q_vector->napi);
return IRQ_HANDLED;
}
static inline void map_vector_to_rxq(struct ixgbevf_adapter *a, int v_idx,
int r_idx)
{
struct ixgbevf_q_vector *q_vector = a->q_vector[v_idx];
a->rx_ring[r_idx]->next = q_vector->rx.ring;
q_vector->rx.ring = a->rx_ring[r_idx];
q_vector->rx.count++;
}
static inline void map_vector_to_txq(struct ixgbevf_adapter *a, int v_idx,
int t_idx)
{
struct ixgbevf_q_vector *q_vector = a->q_vector[v_idx];
a->tx_ring[t_idx]->next = q_vector->tx.ring;
q_vector->tx.ring = a->tx_ring[t_idx];
q_vector->tx.count++;
}
static int ixgbevf_map_rings_to_vectors(struct ixgbevf_adapter *adapter)
{
int q_vectors;
int v_start = 0;
int rxr_idx = 0, txr_idx = 0;
int rxr_remaining = adapter->num_rx_queues;
int txr_remaining = adapter->num_tx_queues;
int i, j;
int rqpv, tqpv;
int err = 0;
q_vectors = adapter->num_msix_vectors - NON_Q_VECTORS;
if (q_vectors == adapter->num_rx_queues + adapter->num_tx_queues) {
for (; rxr_idx < rxr_remaining; v_start++, rxr_idx++)
map_vector_to_rxq(adapter, v_start, rxr_idx);
for (; txr_idx < txr_remaining; v_start++, txr_idx++)
map_vector_to_txq(adapter, v_start, txr_idx);
goto out;
}
for (i = v_start; i < q_vectors; i++) {
rqpv = DIV_ROUND_UP(rxr_remaining, q_vectors - i);
for (j = 0; j < rqpv; j++) {
map_vector_to_rxq(adapter, i, rxr_idx);
rxr_idx++;
rxr_remaining--;
}
}
for (i = v_start; i < q_vectors; i++) {
tqpv = DIV_ROUND_UP(txr_remaining, q_vectors - i);
for (j = 0; j < tqpv; j++) {
map_vector_to_txq(adapter, i, txr_idx);
txr_idx++;
txr_remaining--;
}
}
out:
return err;
}
static int ixgbevf_request_msix_irqs(struct ixgbevf_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
int q_vectors = adapter->num_msix_vectors - NON_Q_VECTORS;
int vector, err;
int ri = 0, ti = 0;
for (vector = 0; vector < q_vectors; vector++) {
struct ixgbevf_q_vector *q_vector = adapter->q_vector[vector];
struct msix_entry *entry = &adapter->msix_entries[vector];
if (q_vector->tx.ring && q_vector->rx.ring) {
snprintf(q_vector->name, sizeof(q_vector->name) - 1,
"%s-%s-%d", netdev->name, "TxRx", ri++);
ti++;
} else if (q_vector->rx.ring) {
snprintf(q_vector->name, sizeof(q_vector->name) - 1,
"%s-%s-%d", netdev->name, "rx", ri++);
} else if (q_vector->tx.ring) {
snprintf(q_vector->name, sizeof(q_vector->name) - 1,
"%s-%s-%d", netdev->name, "tx", ti++);
} else {
continue;
}
err = request_irq(entry->vector, &ixgbevf_msix_clean_rings, 0,
q_vector->name, q_vector);
if (err) {
hw_dbg(&adapter->hw,
"request_irq failed for MSIX interrupt "
"Error: %d\n", err);
goto free_queue_irqs;
}
}
err = request_irq(adapter->msix_entries[vector].vector,
&ixgbevf_msix_other, 0, netdev->name, adapter);
if (err) {
hw_dbg(&adapter->hw,
"request_irq for msix_other failed: %d\n", err);
goto free_queue_irqs;
}
return 0;
free_queue_irqs:
while (vector) {
vector--;
free_irq(adapter->msix_entries[vector].vector,
adapter->q_vector[vector]);
}
adapter->num_msix_vectors = 0;
return err;
}
static inline void ixgbevf_reset_q_vectors(struct ixgbevf_adapter *adapter)
{
int i, q_vectors = adapter->num_msix_vectors - NON_Q_VECTORS;
for (i = 0; i < q_vectors; i++) {
struct ixgbevf_q_vector *q_vector = adapter->q_vector[i];
q_vector->rx.ring = NULL;
q_vector->tx.ring = NULL;
q_vector->rx.count = 0;
q_vector->tx.count = 0;
}
}
static int ixgbevf_request_irq(struct ixgbevf_adapter *adapter)
{
int err = 0;
err = ixgbevf_request_msix_irqs(adapter);
if (err)
hw_dbg(&adapter->hw,
"request_irq failed, Error %d\n", err);
return err;
}
static void ixgbevf_free_irq(struct ixgbevf_adapter *adapter)
{
int i, q_vectors;
q_vectors = adapter->num_msix_vectors;
i = q_vectors - 1;
free_irq(adapter->msix_entries[i].vector, adapter);
i--;
for (; i >= 0; i--) {
if (!adapter->q_vector[i]->rx.ring &&
!adapter->q_vector[i]->tx.ring)
continue;
free_irq(adapter->msix_entries[i].vector,
adapter->q_vector[i]);
}
ixgbevf_reset_q_vectors(adapter);
}
static inline void ixgbevf_irq_disable(struct ixgbevf_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
int i;
IXGBE_WRITE_REG(hw, IXGBE_VTEIAM, 0);
IXGBE_WRITE_REG(hw, IXGBE_VTEIMC, ~0);
IXGBE_WRITE_REG(hw, IXGBE_VTEIAC, 0);
IXGBE_WRITE_FLUSH(hw);
for (i = 0; i < adapter->num_msix_vectors; i++)
synchronize_irq(adapter->msix_entries[i].vector);
}
static inline void ixgbevf_irq_enable(struct ixgbevf_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
IXGBE_WRITE_REG(hw, IXGBE_VTEIAM, adapter->eims_enable_mask);
IXGBE_WRITE_REG(hw, IXGBE_VTEIAC, adapter->eims_enable_mask);
IXGBE_WRITE_REG(hw, IXGBE_VTEIMS, adapter->eims_enable_mask);
}
static void ixgbevf_configure_tx_ring(struct ixgbevf_adapter *adapter,
struct ixgbevf_ring *ring)
{
struct ixgbe_hw *hw = &adapter->hw;
u64 tdba = ring->dma;
int wait_loop = 10;
u32 txdctl = IXGBE_TXDCTL_ENABLE;
u8 reg_idx = ring->reg_idx;
IXGBE_WRITE_REG(hw, IXGBE_VFTXDCTL(reg_idx), IXGBE_TXDCTL_SWFLSH);
IXGBE_WRITE_FLUSH(hw);
IXGBE_WRITE_REG(hw, IXGBE_VFTDBAL(reg_idx), tdba & DMA_BIT_MASK(32));
IXGBE_WRITE_REG(hw, IXGBE_VFTDBAH(reg_idx), tdba >> 32);
IXGBE_WRITE_REG(hw, IXGBE_VFTDLEN(reg_idx),
ring->count * sizeof(union ixgbe_adv_tx_desc));
IXGBE_WRITE_REG(hw, IXGBE_VFTDWBAH(reg_idx), 0);
IXGBE_WRITE_REG(hw, IXGBE_VFTDWBAL(reg_idx), 0);
IXGBE_WRITE_REG(hw, IXGBE_VFDCA_TXCTRL(reg_idx),
(IXGBE_DCA_TXCTRL_DESC_RRO_EN |
IXGBE_DCA_TXCTRL_DATA_RRO_EN));
IXGBE_WRITE_REG(hw, IXGBE_VFTDH(reg_idx), 0);
IXGBE_WRITE_REG(hw, IXGBE_VFTDT(reg_idx), 0);
ring->tail = adapter->io_addr + IXGBE_VFTDT(reg_idx);
ring->next_to_clean = 0;
ring->next_to_use = 0;
txdctl |= (8 << 16);
txdctl |= (1 << 8) |
32;
clear_bit(__IXGBEVF_HANG_CHECK_ARMED, &ring->state);
IXGBE_WRITE_REG(hw, IXGBE_VFTXDCTL(reg_idx), txdctl);
do {
usleep_range(1000, 2000);
txdctl = IXGBE_READ_REG(hw, IXGBE_VFTXDCTL(reg_idx));
} while (--wait_loop && !(txdctl & IXGBE_TXDCTL_ENABLE));
if (!wait_loop)
pr_err("Could not enable Tx Queue %d\n", reg_idx);
}
static void ixgbevf_configure_tx(struct ixgbevf_adapter *adapter)
{
u32 i;
for (i = 0; i < adapter->num_tx_queues; i++)
ixgbevf_configure_tx_ring(adapter, adapter->tx_ring[i]);
}
static void ixgbevf_configure_srrctl(struct ixgbevf_adapter *adapter, int index)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 srrctl;
srrctl = IXGBE_SRRCTL_DROP_EN;
srrctl |= IXGBEVF_RX_HDR_SIZE << IXGBE_SRRCTL_BSIZEHDRSIZE_SHIFT;
srrctl |= IXGBEVF_RX_BUFSZ >> IXGBE_SRRCTL_BSIZEPKT_SHIFT;
srrctl |= IXGBE_SRRCTL_DESCTYPE_ADV_ONEBUF;
IXGBE_WRITE_REG(hw, IXGBE_VFSRRCTL(index), srrctl);
}
static void ixgbevf_setup_psrtype(struct ixgbevf_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 psrtype = IXGBE_PSRTYPE_TCPHDR | IXGBE_PSRTYPE_UDPHDR |
IXGBE_PSRTYPE_IPV4HDR | IXGBE_PSRTYPE_IPV6HDR |
IXGBE_PSRTYPE_L2HDR;
if (adapter->num_rx_queues > 1)
psrtype |= 1 << 29;
IXGBE_WRITE_REG(hw, IXGBE_VFPSRTYPE, psrtype);
}
static void ixgbevf_disable_rx_queue(struct ixgbevf_adapter *adapter,
struct ixgbevf_ring *ring)
{
struct ixgbe_hw *hw = &adapter->hw;
int wait_loop = IXGBEVF_MAX_RX_DESC_POLL;
u32 rxdctl;
u8 reg_idx = ring->reg_idx;
if (IXGBE_REMOVED(hw->hw_addr))
return;
rxdctl = IXGBE_READ_REG(hw, IXGBE_VFRXDCTL(reg_idx));
rxdctl &= ~IXGBE_RXDCTL_ENABLE;
IXGBE_WRITE_REG(hw, IXGBE_VFRXDCTL(reg_idx), rxdctl);
do {
udelay(10);
rxdctl = IXGBE_READ_REG(hw, IXGBE_VFRXDCTL(reg_idx));
} while (--wait_loop && (rxdctl & IXGBE_RXDCTL_ENABLE));
if (!wait_loop)
pr_err("RXDCTL.ENABLE queue %d not cleared while polling\n",
reg_idx);
}
static void ixgbevf_rx_desc_queue_enable(struct ixgbevf_adapter *adapter,
struct ixgbevf_ring *ring)
{
struct ixgbe_hw *hw = &adapter->hw;
int wait_loop = IXGBEVF_MAX_RX_DESC_POLL;
u32 rxdctl;
u8 reg_idx = ring->reg_idx;
if (IXGBE_REMOVED(hw->hw_addr))
return;
do {
usleep_range(1000, 2000);
rxdctl = IXGBE_READ_REG(hw, IXGBE_VFRXDCTL(reg_idx));
} while (--wait_loop && !(rxdctl & IXGBE_RXDCTL_ENABLE));
if (!wait_loop)
pr_err("RXDCTL.ENABLE queue %d not set while polling\n",
reg_idx);
}
static void ixgbevf_setup_vfmrqc(struct ixgbevf_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 vfmrqc = 0, vfreta = 0;
u32 rss_key[10];
u16 rss_i = adapter->num_rx_queues;
int i, j;
netdev_rss_key_fill(rss_key, sizeof(rss_key));
for (i = 0; i < 10; i++)
IXGBE_WRITE_REG(hw, IXGBE_VFRSSRK(i), rss_key[i]);
for (i = 0, j = 0; i < 64; i++, j++) {
if (j == rss_i)
j = 0;
vfreta = (vfreta << 8) | (j * 0x1);
if ((i & 3) == 3)
IXGBE_WRITE_REG(hw, IXGBE_VFRETA(i >> 2), vfreta);
}
vfmrqc |= IXGBE_VFMRQC_RSS_FIELD_IPV4 |
IXGBE_VFMRQC_RSS_FIELD_IPV4_TCP |
IXGBE_VFMRQC_RSS_FIELD_IPV6 |
IXGBE_VFMRQC_RSS_FIELD_IPV6_TCP;
vfmrqc |= IXGBE_VFMRQC_RSSEN;
IXGBE_WRITE_REG(hw, IXGBE_VFMRQC, vfmrqc);
}
static void ixgbevf_configure_rx_ring(struct ixgbevf_adapter *adapter,
struct ixgbevf_ring *ring)
{
struct ixgbe_hw *hw = &adapter->hw;
u64 rdba = ring->dma;
u32 rxdctl;
u8 reg_idx = ring->reg_idx;
rxdctl = IXGBE_READ_REG(hw, IXGBE_VFRXDCTL(reg_idx));
ixgbevf_disable_rx_queue(adapter, ring);
IXGBE_WRITE_REG(hw, IXGBE_VFRDBAL(reg_idx), rdba & DMA_BIT_MASK(32));
IXGBE_WRITE_REG(hw, IXGBE_VFRDBAH(reg_idx), rdba >> 32);
IXGBE_WRITE_REG(hw, IXGBE_VFRDLEN(reg_idx),
ring->count * sizeof(union ixgbe_adv_rx_desc));
IXGBE_WRITE_REG(hw, IXGBE_VFDCA_RXCTRL(reg_idx),
IXGBE_DCA_RXCTRL_DESC_RRO_EN);
IXGBE_WRITE_REG(hw, IXGBE_VFRDH(reg_idx), 0);
IXGBE_WRITE_REG(hw, IXGBE_VFRDT(reg_idx), 0);
ring->tail = adapter->io_addr + IXGBE_VFRDT(reg_idx);
ring->next_to_clean = 0;
ring->next_to_use = 0;
ring->next_to_alloc = 0;
ixgbevf_configure_srrctl(adapter, reg_idx);
rxdctl &= ~IXGBE_RXDCTL_RLPML_EN;
rxdctl |= IXGBE_RXDCTL_ENABLE | IXGBE_RXDCTL_VME;
IXGBE_WRITE_REG(hw, IXGBE_VFRXDCTL(reg_idx), rxdctl);
ixgbevf_rx_desc_queue_enable(adapter, ring);
ixgbevf_alloc_rx_buffers(ring, ixgbevf_desc_unused(ring));
}
static void ixgbevf_configure_rx(struct ixgbevf_adapter *adapter)
{
int i;
struct ixgbe_hw *hw = &adapter->hw;
struct net_device *netdev = adapter->netdev;
ixgbevf_setup_psrtype(adapter);
if (hw->mac.type >= ixgbe_mac_X550_vf)
ixgbevf_setup_vfmrqc(adapter);
ixgbevf_rlpml_set_vf(hw, netdev->mtu + ETH_HLEN + ETH_FCS_LEN);
for (i = 0; i < adapter->num_rx_queues; i++)
ixgbevf_configure_rx_ring(adapter, adapter->rx_ring[i]);
}
static int ixgbevf_vlan_rx_add_vid(struct net_device *netdev,
__be16 proto, u16 vid)
{
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
int err;
spin_lock_bh(&adapter->mbx_lock);
err = hw->mac.ops.set_vfta(hw, vid, 0, true);
spin_unlock_bh(&adapter->mbx_lock);
if (err == IXGBE_ERR_MBX)
return -EIO;
if (err == IXGBE_ERR_INVALID_ARGUMENT)
return -EACCES;
set_bit(vid, adapter->active_vlans);
return err;
}
static int ixgbevf_vlan_rx_kill_vid(struct net_device *netdev,
__be16 proto, u16 vid)
{
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
int err = -EOPNOTSUPP;
spin_lock_bh(&adapter->mbx_lock);
err = hw->mac.ops.set_vfta(hw, vid, 0, false);
spin_unlock_bh(&adapter->mbx_lock);
clear_bit(vid, adapter->active_vlans);
return err;
}
static void ixgbevf_restore_vlan(struct ixgbevf_adapter *adapter)
{
u16 vid;
for_each_set_bit(vid, adapter->active_vlans, VLAN_N_VID)
ixgbevf_vlan_rx_add_vid(adapter->netdev,
htons(ETH_P_8021Q), vid);
}
static int ixgbevf_write_uc_addr_list(struct net_device *netdev)
{
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
int count = 0;
if ((netdev_uc_count(netdev)) > 10) {
pr_err("Too many unicast filters - No Space\n");
return -ENOSPC;
}
if (!netdev_uc_empty(netdev)) {
struct netdev_hw_addr *ha;
netdev_for_each_uc_addr(ha, netdev) {
hw->mac.ops.set_uc_addr(hw, ++count, ha->addr);
udelay(200);
}
} else {
hw->mac.ops.set_uc_addr(hw, 0, NULL);
}
return count;
}
static void ixgbevf_set_rx_mode(struct net_device *netdev)
{
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
spin_lock_bh(&adapter->mbx_lock);
hw->mac.ops.update_mc_addr_list(hw, netdev);
ixgbevf_write_uc_addr_list(netdev);
spin_unlock_bh(&adapter->mbx_lock);
}
static void ixgbevf_napi_enable_all(struct ixgbevf_adapter *adapter)
{
int q_idx;
struct ixgbevf_q_vector *q_vector;
int q_vectors = adapter->num_msix_vectors - NON_Q_VECTORS;
for (q_idx = 0; q_idx < q_vectors; q_idx++) {
q_vector = adapter->q_vector[q_idx];
#ifdef CONFIG_NET_RX_BUSY_POLL
ixgbevf_qv_init_lock(adapter->q_vector[q_idx]);
#endif
napi_enable(&q_vector->napi);
}
}
static void ixgbevf_napi_disable_all(struct ixgbevf_adapter *adapter)
{
int q_idx;
struct ixgbevf_q_vector *q_vector;
int q_vectors = adapter->num_msix_vectors - NON_Q_VECTORS;
for (q_idx = 0; q_idx < q_vectors; q_idx++) {
q_vector = adapter->q_vector[q_idx];
napi_disable(&q_vector->napi);
#ifdef CONFIG_NET_RX_BUSY_POLL
while (!ixgbevf_qv_disable(adapter->q_vector[q_idx])) {
pr_info("QV %d locked\n", q_idx);
usleep_range(1000, 20000);
}
#endif
}
}
static int ixgbevf_configure_dcb(struct ixgbevf_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
unsigned int def_q = 0;
unsigned int num_tcs = 0;
unsigned int num_rx_queues = adapter->num_rx_queues;
unsigned int num_tx_queues = adapter->num_tx_queues;
int err;
spin_lock_bh(&adapter->mbx_lock);
err = ixgbevf_get_queues(hw, &num_tcs, &def_q);
spin_unlock_bh(&adapter->mbx_lock);
if (err)
return err;
if (num_tcs > 1) {
num_tx_queues = 1;
adapter->tx_ring[0]->reg_idx = def_q;
num_rx_queues = num_tcs;
}
if ((adapter->num_rx_queues != num_rx_queues) ||
(adapter->num_tx_queues != num_tx_queues)) {
hw->mbx.timeout = 0;
adapter->flags |= IXGBEVF_FLAG_QUEUE_RESET_REQUESTED;
}
return 0;
}
static void ixgbevf_configure(struct ixgbevf_adapter *adapter)
{
ixgbevf_configure_dcb(adapter);
ixgbevf_set_rx_mode(adapter->netdev);
ixgbevf_restore_vlan(adapter);
ixgbevf_configure_tx(adapter);
ixgbevf_configure_rx(adapter);
}
static void ixgbevf_save_reset_stats(struct ixgbevf_adapter *adapter)
{
if (adapter->stats.vfgprc || adapter->stats.vfgptc) {
adapter->stats.saved_reset_vfgprc += adapter->stats.vfgprc -
adapter->stats.base_vfgprc;
adapter->stats.saved_reset_vfgptc += adapter->stats.vfgptc -
adapter->stats.base_vfgptc;
adapter->stats.saved_reset_vfgorc += adapter->stats.vfgorc -
adapter->stats.base_vfgorc;
adapter->stats.saved_reset_vfgotc += adapter->stats.vfgotc -
adapter->stats.base_vfgotc;
adapter->stats.saved_reset_vfmprc += adapter->stats.vfmprc -
adapter->stats.base_vfmprc;
}
}
static void ixgbevf_init_last_counter_stats(struct ixgbevf_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
adapter->stats.last_vfgprc = IXGBE_READ_REG(hw, IXGBE_VFGPRC);
adapter->stats.last_vfgorc = IXGBE_READ_REG(hw, IXGBE_VFGORC_LSB);
adapter->stats.last_vfgorc |=
(((u64)(IXGBE_READ_REG(hw, IXGBE_VFGORC_MSB))) << 32);
adapter->stats.last_vfgptc = IXGBE_READ_REG(hw, IXGBE_VFGPTC);
adapter->stats.last_vfgotc = IXGBE_READ_REG(hw, IXGBE_VFGOTC_LSB);
adapter->stats.last_vfgotc |=
(((u64)(IXGBE_READ_REG(hw, IXGBE_VFGOTC_MSB))) << 32);
adapter->stats.last_vfmprc = IXGBE_READ_REG(hw, IXGBE_VFMPRC);
adapter->stats.base_vfgprc = adapter->stats.last_vfgprc;
adapter->stats.base_vfgorc = adapter->stats.last_vfgorc;
adapter->stats.base_vfgptc = adapter->stats.last_vfgptc;
adapter->stats.base_vfgotc = adapter->stats.last_vfgotc;
adapter->stats.base_vfmprc = adapter->stats.last_vfmprc;
}
static void ixgbevf_negotiate_api(struct ixgbevf_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
int api[] = { ixgbe_mbox_api_11,
ixgbe_mbox_api_10,
ixgbe_mbox_api_unknown };
int err = 0, idx = 0;
spin_lock_bh(&adapter->mbx_lock);
while (api[idx] != ixgbe_mbox_api_unknown) {
err = ixgbevf_negotiate_api_version(hw, api[idx]);
if (!err)
break;
idx++;
}
spin_unlock_bh(&adapter->mbx_lock);
}
static void ixgbevf_up_complete(struct ixgbevf_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
struct ixgbe_hw *hw = &adapter->hw;
ixgbevf_configure_msix(adapter);
spin_lock_bh(&adapter->mbx_lock);
if (is_valid_ether_addr(hw->mac.addr))
hw->mac.ops.set_rar(hw, 0, hw->mac.addr, 0);
else
hw->mac.ops.set_rar(hw, 0, hw->mac.perm_addr, 0);
spin_unlock_bh(&adapter->mbx_lock);
smp_mb__before_atomic();
clear_bit(__IXGBEVF_DOWN, &adapter->state);
ixgbevf_napi_enable_all(adapter);
IXGBE_READ_REG(hw, IXGBE_VTEICR);
ixgbevf_irq_enable(adapter);
netif_tx_start_all_queues(netdev);
ixgbevf_save_reset_stats(adapter);
ixgbevf_init_last_counter_stats(adapter);
hw->mac.get_link_status = 1;
mod_timer(&adapter->service_timer, jiffies);
}
void ixgbevf_up(struct ixgbevf_adapter *adapter)
{
ixgbevf_configure(adapter);
ixgbevf_up_complete(adapter);
}
static void ixgbevf_clean_rx_ring(struct ixgbevf_ring *rx_ring)
{
struct device *dev = rx_ring->dev;
unsigned long size;
unsigned int i;
if (rx_ring->skb) {
dev_kfree_skb(rx_ring->skb);
rx_ring->skb = NULL;
}
if (!rx_ring->rx_buffer_info)
return;
for (i = 0; i < rx_ring->count; i++) {
struct ixgbevf_rx_buffer *rx_buffer;
rx_buffer = &rx_ring->rx_buffer_info[i];
if (rx_buffer->dma)
dma_unmap_page(dev, rx_buffer->dma,
PAGE_SIZE, DMA_FROM_DEVICE);
rx_buffer->dma = 0;
if (rx_buffer->page)
__free_page(rx_buffer->page);
rx_buffer->page = NULL;
}
size = sizeof(struct ixgbevf_rx_buffer) * rx_ring->count;
memset(rx_ring->rx_buffer_info, 0, size);
memset(rx_ring->desc, 0, rx_ring->size);
}
static void ixgbevf_clean_tx_ring(struct ixgbevf_ring *tx_ring)
{
struct ixgbevf_tx_buffer *tx_buffer_info;
unsigned long size;
unsigned int i;
if (!tx_ring->tx_buffer_info)
return;
for (i = 0; i < tx_ring->count; i++) {
tx_buffer_info = &tx_ring->tx_buffer_info[i];
ixgbevf_unmap_and_free_tx_resource(tx_ring, tx_buffer_info);
}
size = sizeof(struct ixgbevf_tx_buffer) * tx_ring->count;
memset(tx_ring->tx_buffer_info, 0, size);
memset(tx_ring->desc, 0, tx_ring->size);
}
static void ixgbevf_clean_all_rx_rings(struct ixgbevf_adapter *adapter)
{
int i;
for (i = 0; i < adapter->num_rx_queues; i++)
ixgbevf_clean_rx_ring(adapter->rx_ring[i]);
}
static void ixgbevf_clean_all_tx_rings(struct ixgbevf_adapter *adapter)
{
int i;
for (i = 0; i < adapter->num_tx_queues; i++)
ixgbevf_clean_tx_ring(adapter->tx_ring[i]);
}
void ixgbevf_down(struct ixgbevf_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
struct ixgbe_hw *hw = &adapter->hw;
int i;
if (test_and_set_bit(__IXGBEVF_DOWN, &adapter->state))
return;
for (i = 0; i < adapter->num_rx_queues; i++)
ixgbevf_disable_rx_queue(adapter, adapter->rx_ring[i]);
usleep_range(10000, 20000);
netif_tx_stop_all_queues(netdev);
netif_carrier_off(netdev);
netif_tx_disable(netdev);
ixgbevf_irq_disable(adapter);
ixgbevf_napi_disable_all(adapter);
del_timer_sync(&adapter->service_timer);
for (i = 0; i < adapter->num_tx_queues; i++) {
u8 reg_idx = adapter->tx_ring[i]->reg_idx;
IXGBE_WRITE_REG(hw, IXGBE_VFTXDCTL(reg_idx),
IXGBE_TXDCTL_SWFLSH);
}
if (!pci_channel_offline(adapter->pdev))
ixgbevf_reset(adapter);
ixgbevf_clean_all_tx_rings(adapter);
ixgbevf_clean_all_rx_rings(adapter);
}
void ixgbevf_reinit_locked(struct ixgbevf_adapter *adapter)
{
WARN_ON(in_interrupt());
while (test_and_set_bit(__IXGBEVF_RESETTING, &adapter->state))
msleep(1);
ixgbevf_down(adapter);
ixgbevf_up(adapter);
clear_bit(__IXGBEVF_RESETTING, &adapter->state);
}
void ixgbevf_reset(struct ixgbevf_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
struct net_device *netdev = adapter->netdev;
if (hw->mac.ops.reset_hw(hw)) {
hw_dbg(hw, "PF still resetting\n");
} else {
hw->mac.ops.init_hw(hw);
ixgbevf_negotiate_api(adapter);
}
if (is_valid_ether_addr(adapter->hw.mac.addr)) {
memcpy(netdev->dev_addr, adapter->hw.mac.addr,
netdev->addr_len);
memcpy(netdev->perm_addr, adapter->hw.mac.addr,
netdev->addr_len);
}
adapter->last_reset = jiffies;
}
static int ixgbevf_acquire_msix_vectors(struct ixgbevf_adapter *adapter,
int vectors)
{
int vector_threshold;
vector_threshold = MIN_MSIX_COUNT;
vectors = pci_enable_msix_range(adapter->pdev, adapter->msix_entries,
vector_threshold, vectors);
if (vectors < 0) {
dev_err(&adapter->pdev->dev,
"Unable to allocate MSI-X interrupts\n");
kfree(adapter->msix_entries);
adapter->msix_entries = NULL;
return vectors;
}
adapter->num_msix_vectors = vectors;
return 0;
}
static void ixgbevf_set_num_queues(struct ixgbevf_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
unsigned int def_q = 0;
unsigned int num_tcs = 0;
int err;
adapter->num_rx_queues = 1;
adapter->num_tx_queues = 1;
spin_lock_bh(&adapter->mbx_lock);
err = ixgbevf_get_queues(hw, &num_tcs, &def_q);
spin_unlock_bh(&adapter->mbx_lock);
if (err)
return;
if (num_tcs > 1) {
adapter->num_rx_queues = num_tcs;
} else {
u16 rss = min_t(u16, num_online_cpus(), IXGBEVF_MAX_RSS_QUEUES);
switch (hw->api_version) {
case ixgbe_mbox_api_11:
adapter->num_rx_queues = rss;
adapter->num_tx_queues = rss;
default:
break;
}
}
}
static int ixgbevf_alloc_queues(struct ixgbevf_adapter *adapter)
{
struct ixgbevf_ring *ring;
int rx = 0, tx = 0;
for (; tx < adapter->num_tx_queues; tx++) {
ring = kzalloc(sizeof(*ring), GFP_KERNEL);
if (!ring)
goto err_allocation;
ring->dev = &adapter->pdev->dev;
ring->netdev = adapter->netdev;
ring->count = adapter->tx_ring_count;
ring->queue_index = tx;
ring->reg_idx = tx;
adapter->tx_ring[tx] = ring;
}
for (; rx < adapter->num_rx_queues; rx++) {
ring = kzalloc(sizeof(*ring), GFP_KERNEL);
if (!ring)
goto err_allocation;
ring->dev = &adapter->pdev->dev;
ring->netdev = adapter->netdev;
ring->count = adapter->rx_ring_count;
ring->queue_index = rx;
ring->reg_idx = rx;
adapter->rx_ring[rx] = ring;
}
return 0;
err_allocation:
while (tx) {
kfree(adapter->tx_ring[--tx]);
adapter->tx_ring[tx] = NULL;
}
while (rx) {
kfree(adapter->rx_ring[--rx]);
adapter->rx_ring[rx] = NULL;
}
return -ENOMEM;
}
static int ixgbevf_set_interrupt_capability(struct ixgbevf_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
int err = 0;
int vector, v_budget;
v_budget = max(adapter->num_rx_queues, adapter->num_tx_queues);
v_budget = min_t(int, v_budget, num_online_cpus());
v_budget += NON_Q_VECTORS;
adapter->msix_entries = kcalloc(v_budget,
sizeof(struct msix_entry), GFP_KERNEL);
if (!adapter->msix_entries) {
err = -ENOMEM;
goto out;
}
for (vector = 0; vector < v_budget; vector++)
adapter->msix_entries[vector].entry = vector;
err = ixgbevf_acquire_msix_vectors(adapter, v_budget);
if (err)
goto out;
err = netif_set_real_num_tx_queues(netdev, adapter->num_tx_queues);
if (err)
goto out;
err = netif_set_real_num_rx_queues(netdev, adapter->num_rx_queues);
out:
return err;
}
static int ixgbevf_alloc_q_vectors(struct ixgbevf_adapter *adapter)
{
int q_idx, num_q_vectors;
struct ixgbevf_q_vector *q_vector;
num_q_vectors = adapter->num_msix_vectors - NON_Q_VECTORS;
for (q_idx = 0; q_idx < num_q_vectors; q_idx++) {
q_vector = kzalloc(sizeof(struct ixgbevf_q_vector), GFP_KERNEL);
if (!q_vector)
goto err_out;
q_vector->adapter = adapter;
q_vector->v_idx = q_idx;
netif_napi_add(adapter->netdev, &q_vector->napi,
ixgbevf_poll, 64);
#ifdef CONFIG_NET_RX_BUSY_POLL
napi_hash_add(&q_vector->napi);
#endif
adapter->q_vector[q_idx] = q_vector;
}
return 0;
err_out:
while (q_idx) {
q_idx--;
q_vector = adapter->q_vector[q_idx];
#ifdef CONFIG_NET_RX_BUSY_POLL
napi_hash_del(&q_vector->napi);
#endif
netif_napi_del(&q_vector->napi);
kfree(q_vector);
adapter->q_vector[q_idx] = NULL;
}
return -ENOMEM;
}
static void ixgbevf_free_q_vectors(struct ixgbevf_adapter *adapter)
{
int q_idx, num_q_vectors = adapter->num_msix_vectors - NON_Q_VECTORS;
for (q_idx = 0; q_idx < num_q_vectors; q_idx++) {
struct ixgbevf_q_vector *q_vector = adapter->q_vector[q_idx];
adapter->q_vector[q_idx] = NULL;
#ifdef CONFIG_NET_RX_BUSY_POLL
napi_hash_del(&q_vector->napi);
#endif
netif_napi_del(&q_vector->napi);
kfree(q_vector);
}
}
static void ixgbevf_reset_interrupt_capability(struct ixgbevf_adapter *adapter)
{
pci_disable_msix(adapter->pdev);
kfree(adapter->msix_entries);
adapter->msix_entries = NULL;
}
static int ixgbevf_init_interrupt_scheme(struct ixgbevf_adapter *adapter)
{
int err;
ixgbevf_set_num_queues(adapter);
err = ixgbevf_set_interrupt_capability(adapter);
if (err) {
hw_dbg(&adapter->hw,
"Unable to setup interrupt capabilities\n");
goto err_set_interrupt;
}
err = ixgbevf_alloc_q_vectors(adapter);
if (err) {
hw_dbg(&adapter->hw, "Unable to allocate memory for queue "
"vectors\n");
goto err_alloc_q_vectors;
}
err = ixgbevf_alloc_queues(adapter);
if (err) {
pr_err("Unable to allocate memory for queues\n");
goto err_alloc_queues;
}
hw_dbg(&adapter->hw, "Multiqueue %s: Rx Queue count = %u, "
"Tx Queue count = %u\n",
(adapter->num_rx_queues > 1) ? "Enabled" :
"Disabled", adapter->num_rx_queues, adapter->num_tx_queues);
set_bit(__IXGBEVF_DOWN, &adapter->state);
return 0;
err_alloc_queues:
ixgbevf_free_q_vectors(adapter);
err_alloc_q_vectors:
ixgbevf_reset_interrupt_capability(adapter);
err_set_interrupt:
return err;
}
static void ixgbevf_clear_interrupt_scheme(struct ixgbevf_adapter *adapter)
{
int i;
for (i = 0; i < adapter->num_tx_queues; i++) {
kfree(adapter->tx_ring[i]);
adapter->tx_ring[i] = NULL;
}
for (i = 0; i < adapter->num_rx_queues; i++) {
kfree(adapter->rx_ring[i]);
adapter->rx_ring[i] = NULL;
}
adapter->num_tx_queues = 0;
adapter->num_rx_queues = 0;
ixgbevf_free_q_vectors(adapter);
ixgbevf_reset_interrupt_capability(adapter);
}
static int ixgbevf_sw_init(struct ixgbevf_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
struct pci_dev *pdev = adapter->pdev;
struct net_device *netdev = adapter->netdev;
int err;
hw->vendor_id = pdev->vendor;
hw->device_id = pdev->device;
hw->revision_id = pdev->revision;
hw->subsystem_vendor_id = pdev->subsystem_vendor;
hw->subsystem_device_id = pdev->subsystem_device;
hw->mbx.ops.init_params(hw);
hw->mac.max_tx_queues = 2;
hw->mac.max_rx_queues = 2;
spin_lock_init(&adapter->mbx_lock);
err = hw->mac.ops.reset_hw(hw);
if (err) {
dev_info(&pdev->dev,
"PF still in reset state. Is the PF interface up?\n");
} else {
err = hw->mac.ops.init_hw(hw);
if (err) {
pr_err("init_shared_code failed: %d\n", err);
goto out;
}
ixgbevf_negotiate_api(adapter);
err = hw->mac.ops.get_mac_addr(hw, hw->mac.addr);
if (err)
dev_info(&pdev->dev, "Error reading MAC address\n");
else if (is_zero_ether_addr(adapter->hw.mac.addr))
dev_info(&pdev->dev,
"MAC address not assigned by administrator.\n");
memcpy(netdev->dev_addr, hw->mac.addr, netdev->addr_len);
}
if (!is_valid_ether_addr(netdev->dev_addr)) {
dev_info(&pdev->dev, "Assigning random MAC address\n");
eth_hw_addr_random(netdev);
memcpy(hw->mac.addr, netdev->dev_addr, netdev->addr_len);
}
adapter->rx_itr_setting = 1;
adapter->tx_itr_setting = 1;
adapter->tx_ring_count = IXGBEVF_DEFAULT_TXD;
adapter->rx_ring_count = IXGBEVF_DEFAULT_RXD;
set_bit(__IXGBEVF_DOWN, &adapter->state);
return 0;
out:
return err;
}
void ixgbevf_update_stats(struct ixgbevf_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
int i;
if (test_bit(__IXGBEVF_DOWN, &adapter->state) ||
test_bit(__IXGBEVF_RESETTING, &adapter->state))
return;
UPDATE_VF_COUNTER_32bit(IXGBE_VFGPRC, adapter->stats.last_vfgprc,
adapter->stats.vfgprc);
UPDATE_VF_COUNTER_32bit(IXGBE_VFGPTC, adapter->stats.last_vfgptc,
adapter->stats.vfgptc);
UPDATE_VF_COUNTER_36bit(IXGBE_VFGORC_LSB, IXGBE_VFGORC_MSB,
adapter->stats.last_vfgorc,
adapter->stats.vfgorc);
UPDATE_VF_COUNTER_36bit(IXGBE_VFGOTC_LSB, IXGBE_VFGOTC_MSB,
adapter->stats.last_vfgotc,
adapter->stats.vfgotc);
UPDATE_VF_COUNTER_32bit(IXGBE_VFMPRC, adapter->stats.last_vfmprc,
adapter->stats.vfmprc);
for (i = 0; i < adapter->num_rx_queues; i++) {
adapter->hw_csum_rx_error +=
adapter->rx_ring[i]->hw_csum_rx_error;
adapter->rx_ring[i]->hw_csum_rx_error = 0;
}
}
static void ixgbevf_service_timer(unsigned long data)
{
struct ixgbevf_adapter *adapter = (struct ixgbevf_adapter *)data;
mod_timer(&adapter->service_timer, (HZ * 2) + jiffies);
ixgbevf_service_event_schedule(adapter);
}
static void ixgbevf_reset_subtask(struct ixgbevf_adapter *adapter)
{
if (!(adapter->flags & IXGBEVF_FLAG_RESET_REQUESTED))
return;
adapter->flags &= ~IXGBEVF_FLAG_RESET_REQUESTED;
if (test_bit(__IXGBEVF_DOWN, &adapter->state) ||
test_bit(__IXGBEVF_RESETTING, &adapter->state))
return;
adapter->tx_timeout_count++;
ixgbevf_reinit_locked(adapter);
}
static void ixgbevf_check_hang_subtask(struct ixgbevf_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 eics = 0;
int i;
if (test_bit(__IXGBEVF_DOWN, &adapter->state) ||
test_bit(__IXGBEVF_RESETTING, &adapter->state))
return;
if (netif_carrier_ok(adapter->netdev)) {
for (i = 0; i < adapter->num_tx_queues; i++)
set_check_for_tx_hang(adapter->tx_ring[i]);
}
for (i = 0; i < adapter->num_msix_vectors - NON_Q_VECTORS; i++) {
struct ixgbevf_q_vector *qv = adapter->q_vector[i];
if (qv->rx.ring || qv->tx.ring)
eics |= 1 << i;
}
IXGBE_WRITE_REG(hw, IXGBE_VTEICS, eics);
}
static void ixgbevf_watchdog_update_link(struct ixgbevf_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 link_speed = adapter->link_speed;
bool link_up = adapter->link_up;
s32 err;
spin_lock_bh(&adapter->mbx_lock);
err = hw->mac.ops.check_link(hw, &link_speed, &link_up, false);
spin_unlock_bh(&adapter->mbx_lock);
if (err && time_after(jiffies, adapter->last_reset + (10 * HZ))) {
adapter->flags |= IXGBEVF_FLAG_RESET_REQUESTED;
link_up = false;
}
adapter->link_up = link_up;
adapter->link_speed = link_speed;
}
static void ixgbevf_watchdog_link_is_up(struct ixgbevf_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
if (netif_carrier_ok(netdev))
return;
dev_info(&adapter->pdev->dev, "NIC Link is Up %s\n",
(adapter->link_speed == IXGBE_LINK_SPEED_10GB_FULL) ?
"10 Gbps" :
(adapter->link_speed == IXGBE_LINK_SPEED_1GB_FULL) ?
"1 Gbps" :
(adapter->link_speed == IXGBE_LINK_SPEED_100_FULL) ?
"100 Mbps" :
"unknown speed");
netif_carrier_on(netdev);
}
static void ixgbevf_watchdog_link_is_down(struct ixgbevf_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
adapter->link_speed = 0;
if (!netif_carrier_ok(netdev))
return;
dev_info(&adapter->pdev->dev, "NIC Link is Down\n");
netif_carrier_off(netdev);
}
static void ixgbevf_watchdog_subtask(struct ixgbevf_adapter *adapter)
{
if (test_bit(__IXGBEVF_DOWN, &adapter->state) ||
test_bit(__IXGBEVF_RESETTING, &adapter->state))
return;
ixgbevf_watchdog_update_link(adapter);
if (adapter->link_up)
ixgbevf_watchdog_link_is_up(adapter);
else
ixgbevf_watchdog_link_is_down(adapter);
ixgbevf_update_stats(adapter);
}
static void ixgbevf_service_task(struct work_struct *work)
{
struct ixgbevf_adapter *adapter = container_of(work,
struct ixgbevf_adapter,
service_task);
struct ixgbe_hw *hw = &adapter->hw;
if (IXGBE_REMOVED(hw->hw_addr)) {
if (!test_bit(__IXGBEVF_DOWN, &adapter->state)) {
rtnl_lock();
ixgbevf_down(adapter);
rtnl_unlock();
}
return;
}
ixgbevf_queue_reset_subtask(adapter);
ixgbevf_reset_subtask(adapter);
ixgbevf_watchdog_subtask(adapter);
ixgbevf_check_hang_subtask(adapter);
ixgbevf_service_event_complete(adapter);
}
void ixgbevf_free_tx_resources(struct ixgbevf_ring *tx_ring)
{
ixgbevf_clean_tx_ring(tx_ring);
vfree(tx_ring->tx_buffer_info);
tx_ring->tx_buffer_info = NULL;
if (!tx_ring->desc)
return;
dma_free_coherent(tx_ring->dev, tx_ring->size, tx_ring->desc,
tx_ring->dma);
tx_ring->desc = NULL;
}
static void ixgbevf_free_all_tx_resources(struct ixgbevf_adapter *adapter)
{
int i;
for (i = 0; i < adapter->num_tx_queues; i++)
if (adapter->tx_ring[i]->desc)
ixgbevf_free_tx_resources(adapter->tx_ring[i]);
}
int ixgbevf_setup_tx_resources(struct ixgbevf_ring *tx_ring)
{
int size;
size = sizeof(struct ixgbevf_tx_buffer) * tx_ring->count;
tx_ring->tx_buffer_info = vzalloc(size);
if (!tx_ring->tx_buffer_info)
goto err;
tx_ring->size = tx_ring->count * sizeof(union ixgbe_adv_tx_desc);
tx_ring->size = ALIGN(tx_ring->size, 4096);
tx_ring->desc = dma_alloc_coherent(tx_ring->dev, tx_ring->size,
&tx_ring->dma, GFP_KERNEL);
if (!tx_ring->desc)
goto err;
return 0;
err:
vfree(tx_ring->tx_buffer_info);
tx_ring->tx_buffer_info = NULL;
hw_dbg(&adapter->hw, "Unable to allocate memory for the transmit "
"descriptor ring\n");
return -ENOMEM;
}
static int ixgbevf_setup_all_tx_resources(struct ixgbevf_adapter *adapter)
{
int i, err = 0;
for (i = 0; i < adapter->num_tx_queues; i++) {
err = ixgbevf_setup_tx_resources(adapter->tx_ring[i]);
if (!err)
continue;
hw_dbg(&adapter->hw,
"Allocation for Tx Queue %u failed\n", i);
break;
}
return err;
}
int ixgbevf_setup_rx_resources(struct ixgbevf_ring *rx_ring)
{
int size;
size = sizeof(struct ixgbevf_rx_buffer) * rx_ring->count;
rx_ring->rx_buffer_info = vzalloc(size);
if (!rx_ring->rx_buffer_info)
goto err;
rx_ring->size = rx_ring->count * sizeof(union ixgbe_adv_rx_desc);
rx_ring->size = ALIGN(rx_ring->size, 4096);
rx_ring->desc = dma_alloc_coherent(rx_ring->dev, rx_ring->size,
&rx_ring->dma, GFP_KERNEL);
if (!rx_ring->desc)
goto err;
return 0;
err:
vfree(rx_ring->rx_buffer_info);
rx_ring->rx_buffer_info = NULL;
dev_err(rx_ring->dev, "Unable to allocate memory for the Rx descriptor ring\n");
return -ENOMEM;
}
static int ixgbevf_setup_all_rx_resources(struct ixgbevf_adapter *adapter)
{
int i, err = 0;
for (i = 0; i < adapter->num_rx_queues; i++) {
err = ixgbevf_setup_rx_resources(adapter->rx_ring[i]);
if (!err)
continue;
hw_dbg(&adapter->hw,
"Allocation for Rx Queue %u failed\n", i);
break;
}
return err;
}
void ixgbevf_free_rx_resources(struct ixgbevf_ring *rx_ring)
{
ixgbevf_clean_rx_ring(rx_ring);
vfree(rx_ring->rx_buffer_info);
rx_ring->rx_buffer_info = NULL;
dma_free_coherent(rx_ring->dev, rx_ring->size, rx_ring->desc,
rx_ring->dma);
rx_ring->desc = NULL;
}
static void ixgbevf_free_all_rx_resources(struct ixgbevf_adapter *adapter)
{
int i;
for (i = 0; i < adapter->num_rx_queues; i++)
if (adapter->rx_ring[i]->desc)
ixgbevf_free_rx_resources(adapter->rx_ring[i]);
}
static int ixgbevf_open(struct net_device *netdev)
{
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
int err;
if (!adapter->num_msix_vectors)
return -ENOMEM;
if (hw->adapter_stopped) {
ixgbevf_reset(adapter);
if (hw->adapter_stopped) {
err = IXGBE_ERR_MBX;
pr_err("Unable to start - perhaps the PF Driver isn't "
"up yet\n");
goto err_setup_reset;
}
}
if (test_bit(__IXGBEVF_TESTING, &adapter->state))
return -EBUSY;
netif_carrier_off(netdev);
err = ixgbevf_setup_all_tx_resources(adapter);
if (err)
goto err_setup_tx;
err = ixgbevf_setup_all_rx_resources(adapter);
if (err)
goto err_setup_rx;
ixgbevf_configure(adapter);
ixgbevf_map_rings_to_vectors(adapter);
err = ixgbevf_request_irq(adapter);
if (err)
goto err_req_irq;
ixgbevf_up_complete(adapter);
return 0;
err_req_irq:
ixgbevf_down(adapter);
err_setup_rx:
ixgbevf_free_all_rx_resources(adapter);
err_setup_tx:
ixgbevf_free_all_tx_resources(adapter);
ixgbevf_reset(adapter);
err_setup_reset:
return err;
}
static int ixgbevf_close(struct net_device *netdev)
{
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
ixgbevf_down(adapter);
ixgbevf_free_irq(adapter);
ixgbevf_free_all_tx_resources(adapter);
ixgbevf_free_all_rx_resources(adapter);
return 0;
}
static void ixgbevf_queue_reset_subtask(struct ixgbevf_adapter *adapter)
{
struct net_device *dev = adapter->netdev;
if (!(adapter->flags & IXGBEVF_FLAG_QUEUE_RESET_REQUESTED))
return;
adapter->flags &= ~IXGBEVF_FLAG_QUEUE_RESET_REQUESTED;
if (test_bit(__IXGBEVF_DOWN, &adapter->state) ||
test_bit(__IXGBEVF_RESETTING, &adapter->state))
return;
if (netif_running(dev))
ixgbevf_close(dev);
ixgbevf_clear_interrupt_scheme(adapter);
ixgbevf_init_interrupt_scheme(adapter);
if (netif_running(dev))
ixgbevf_open(dev);
}
static void ixgbevf_tx_ctxtdesc(struct ixgbevf_ring *tx_ring,
u32 vlan_macip_lens, u32 type_tucmd,
u32 mss_l4len_idx)
{
struct ixgbe_adv_tx_context_desc *context_desc;
u16 i = tx_ring->next_to_use;
context_desc = IXGBEVF_TX_CTXTDESC(tx_ring, i);
i++;
tx_ring->next_to_use = (i < tx_ring->count) ? i : 0;
type_tucmd |= IXGBE_TXD_CMD_DEXT | IXGBE_ADVTXD_DTYP_CTXT;
context_desc->vlan_macip_lens = cpu_to_le32(vlan_macip_lens);
context_desc->seqnum_seed = 0;
context_desc->type_tucmd_mlhl = cpu_to_le32(type_tucmd);
context_desc->mss_l4len_idx = cpu_to_le32(mss_l4len_idx);
}
static int ixgbevf_tso(struct ixgbevf_ring *tx_ring,
struct ixgbevf_tx_buffer *first,
u8 *hdr_len)
{
struct sk_buff *skb = first->skb;
u32 vlan_macip_lens, type_tucmd;
u32 mss_l4len_idx, l4len;
int err;
if (skb->ip_summed != CHECKSUM_PARTIAL)
return 0;
if (!skb_is_gso(skb))
return 0;
err = skb_cow_head(skb, 0);
if (err < 0)
return err;
type_tucmd = IXGBE_ADVTXD_TUCMD_L4T_TCP;
if (first->protocol == htons(ETH_P_IP)) {
struct iphdr *iph = ip_hdr(skb);
iph->tot_len = 0;
iph->check = 0;
tcp_hdr(skb)->check = ~csum_tcpudp_magic(iph->saddr,
iph->daddr, 0,
IPPROTO_TCP,
0);
type_tucmd |= IXGBE_ADVTXD_TUCMD_IPV4;
first->tx_flags |= IXGBE_TX_FLAGS_TSO |
IXGBE_TX_FLAGS_CSUM |
IXGBE_TX_FLAGS_IPV4;
} else if (skb_is_gso_v6(skb)) {
ipv6_hdr(skb)->payload_len = 0;
tcp_hdr(skb)->check =
~csum_ipv6_magic(&ipv6_hdr(skb)->saddr,
&ipv6_hdr(skb)->daddr,
0, IPPROTO_TCP, 0);
first->tx_flags |= IXGBE_TX_FLAGS_TSO |
IXGBE_TX_FLAGS_CSUM;
}
l4len = tcp_hdrlen(skb);
*hdr_len += l4len;
*hdr_len = skb_transport_offset(skb) + l4len;
first->gso_segs = skb_shinfo(skb)->gso_segs;
first->bytecount += (first->gso_segs - 1) * *hdr_len;
mss_l4len_idx = l4len << IXGBE_ADVTXD_L4LEN_SHIFT;
mss_l4len_idx |= skb_shinfo(skb)->gso_size << IXGBE_ADVTXD_MSS_SHIFT;
mss_l4len_idx |= 1 << IXGBE_ADVTXD_IDX_SHIFT;
vlan_macip_lens = skb_network_header_len(skb);
vlan_macip_lens |= skb_network_offset(skb) << IXGBE_ADVTXD_MACLEN_SHIFT;
vlan_macip_lens |= first->tx_flags & IXGBE_TX_FLAGS_VLAN_MASK;
ixgbevf_tx_ctxtdesc(tx_ring, vlan_macip_lens,
type_tucmd, mss_l4len_idx);
return 1;
}
static void ixgbevf_tx_csum(struct ixgbevf_ring *tx_ring,
struct ixgbevf_tx_buffer *first)
{
struct sk_buff *skb = first->skb;
u32 vlan_macip_lens = 0;
u32 mss_l4len_idx = 0;
u32 type_tucmd = 0;
if (skb->ip_summed == CHECKSUM_PARTIAL) {
u8 l4_hdr = 0;
switch (first->protocol) {
case htons(ETH_P_IP):
vlan_macip_lens |= skb_network_header_len(skb);
type_tucmd |= IXGBE_ADVTXD_TUCMD_IPV4;
l4_hdr = ip_hdr(skb)->protocol;
break;
case htons(ETH_P_IPV6):
vlan_macip_lens |= skb_network_header_len(skb);
l4_hdr = ipv6_hdr(skb)->nexthdr;
break;
default:
if (unlikely(net_ratelimit())) {
dev_warn(tx_ring->dev,
"partial checksum but proto=%x!\n",
first->protocol);
}
break;
}
switch (l4_hdr) {
case IPPROTO_TCP:
type_tucmd |= IXGBE_ADVTXD_TUCMD_L4T_TCP;
mss_l4len_idx = tcp_hdrlen(skb) <<
IXGBE_ADVTXD_L4LEN_SHIFT;
break;
case IPPROTO_SCTP:
type_tucmd |= IXGBE_ADVTXD_TUCMD_L4T_SCTP;
mss_l4len_idx = sizeof(struct sctphdr) <<
IXGBE_ADVTXD_L4LEN_SHIFT;
break;
case IPPROTO_UDP:
mss_l4len_idx = sizeof(struct udphdr) <<
IXGBE_ADVTXD_L4LEN_SHIFT;
break;
default:
if (unlikely(net_ratelimit())) {
dev_warn(tx_ring->dev,
"partial checksum but l4 proto=%x!\n",
l4_hdr);
}
break;
}
first->tx_flags |= IXGBE_TX_FLAGS_CSUM;
}
vlan_macip_lens |= skb_network_offset(skb) << IXGBE_ADVTXD_MACLEN_SHIFT;
vlan_macip_lens |= first->tx_flags & IXGBE_TX_FLAGS_VLAN_MASK;
ixgbevf_tx_ctxtdesc(tx_ring, vlan_macip_lens,
type_tucmd, mss_l4len_idx);
}
static __le32 ixgbevf_tx_cmd_type(u32 tx_flags)
{
__le32 cmd_type = cpu_to_le32(IXGBE_ADVTXD_DTYP_DATA |
IXGBE_ADVTXD_DCMD_IFCS |
IXGBE_ADVTXD_DCMD_DEXT);
if (tx_flags & IXGBE_TX_FLAGS_VLAN)
cmd_type |= cpu_to_le32(IXGBE_ADVTXD_DCMD_VLE);
if (tx_flags & IXGBE_TX_FLAGS_TSO)
cmd_type |= cpu_to_le32(IXGBE_ADVTXD_DCMD_TSE);
return cmd_type;
}
static void ixgbevf_tx_olinfo_status(union ixgbe_adv_tx_desc *tx_desc,
u32 tx_flags, unsigned int paylen)
{
__le32 olinfo_status = cpu_to_le32(paylen << IXGBE_ADVTXD_PAYLEN_SHIFT);
if (tx_flags & IXGBE_TX_FLAGS_CSUM)
olinfo_status |= cpu_to_le32(IXGBE_ADVTXD_POPTS_TXSM);
if (tx_flags & IXGBE_TX_FLAGS_IPV4)
olinfo_status |= cpu_to_le32(IXGBE_ADVTXD_POPTS_IXSM);
if (tx_flags & IXGBE_TX_FLAGS_TSO)
olinfo_status |= cpu_to_le32(1 << IXGBE_ADVTXD_IDX_SHIFT);
olinfo_status |= cpu_to_le32(IXGBE_ADVTXD_CC);
tx_desc->read.olinfo_status = olinfo_status;
}
static void ixgbevf_tx_map(struct ixgbevf_ring *tx_ring,
struct ixgbevf_tx_buffer *first,
const u8 hdr_len)
{
dma_addr_t dma;
struct sk_buff *skb = first->skb;
struct ixgbevf_tx_buffer *tx_buffer;
union ixgbe_adv_tx_desc *tx_desc;
struct skb_frag_struct *frag = &skb_shinfo(skb)->frags[0];
unsigned int data_len = skb->data_len;
unsigned int size = skb_headlen(skb);
unsigned int paylen = skb->len - hdr_len;
u32 tx_flags = first->tx_flags;
__le32 cmd_type;
u16 i = tx_ring->next_to_use;
tx_desc = IXGBEVF_TX_DESC(tx_ring, i);
ixgbevf_tx_olinfo_status(tx_desc, tx_flags, paylen);
cmd_type = ixgbevf_tx_cmd_type(tx_flags);
dma = dma_map_single(tx_ring->dev, skb->data, size, DMA_TO_DEVICE);
if (dma_mapping_error(tx_ring->dev, dma))
goto dma_error;
dma_unmap_len_set(first, len, size);
dma_unmap_addr_set(first, dma, dma);
tx_desc->read.buffer_addr = cpu_to_le64(dma);
for (;;) {
while (unlikely(size > IXGBE_MAX_DATA_PER_TXD)) {
tx_desc->read.cmd_type_len =
cmd_type | cpu_to_le32(IXGBE_MAX_DATA_PER_TXD);
i++;
tx_desc++;
if (i == tx_ring->count) {
tx_desc = IXGBEVF_TX_DESC(tx_ring, 0);
i = 0;
}
dma += IXGBE_MAX_DATA_PER_TXD;
size -= IXGBE_MAX_DATA_PER_TXD;
tx_desc->read.buffer_addr = cpu_to_le64(dma);
tx_desc->read.olinfo_status = 0;
}
if (likely(!data_len))
break;
tx_desc->read.cmd_type_len = cmd_type | cpu_to_le32(size);
i++;
tx_desc++;
if (i == tx_ring->count) {
tx_desc = IXGBEVF_TX_DESC(tx_ring, 0);
i = 0;
}
size = skb_frag_size(frag);
data_len -= size;
dma = skb_frag_dma_map(tx_ring->dev, frag, 0, size,
DMA_TO_DEVICE);
if (dma_mapping_error(tx_ring->dev, dma))
goto dma_error;
tx_buffer = &tx_ring->tx_buffer_info[i];
dma_unmap_len_set(tx_buffer, len, size);
dma_unmap_addr_set(tx_buffer, dma, dma);
tx_desc->read.buffer_addr = cpu_to_le64(dma);
tx_desc->read.olinfo_status = 0;
frag++;
}
cmd_type |= cpu_to_le32(size) | cpu_to_le32(IXGBE_TXD_CMD);
tx_desc->read.cmd_type_len = cmd_type;
first->time_stamp = jiffies;
wmb();
first->next_to_watch = tx_desc;
i++;
if (i == tx_ring->count)
i = 0;
tx_ring->next_to_use = i;
ixgbevf_write_tail(tx_ring, i);
return;
dma_error:
dev_err(tx_ring->dev, "TX DMA map failed\n");
for (;;) {
tx_buffer = &tx_ring->tx_buffer_info[i];
ixgbevf_unmap_and_free_tx_resource(tx_ring, tx_buffer);
if (tx_buffer == first)
break;
if (i == 0)
i = tx_ring->count;
i--;
}
tx_ring->next_to_use = i;
}
static int __ixgbevf_maybe_stop_tx(struct ixgbevf_ring *tx_ring, int size)
{
netif_stop_subqueue(tx_ring->netdev, tx_ring->queue_index);
smp_mb();
if (likely(ixgbevf_desc_unused(tx_ring) < size))
return -EBUSY;
netif_start_subqueue(tx_ring->netdev, tx_ring->queue_index);
++tx_ring->tx_stats.restart_queue;
return 0;
}
static int ixgbevf_maybe_stop_tx(struct ixgbevf_ring *tx_ring, int size)
{
if (likely(ixgbevf_desc_unused(tx_ring) >= size))
return 0;
return __ixgbevf_maybe_stop_tx(tx_ring, size);
}
static int ixgbevf_xmit_frame(struct sk_buff *skb, struct net_device *netdev)
{
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
struct ixgbevf_tx_buffer *first;
struct ixgbevf_ring *tx_ring;
int tso;
u32 tx_flags = 0;
u16 count = TXD_USE_COUNT(skb_headlen(skb));
#if PAGE_SIZE > IXGBE_MAX_DATA_PER_TXD
unsigned short f;
#endif
u8 hdr_len = 0;
u8 *dst_mac = skb_header_pointer(skb, 0, 0, NULL);
if (!dst_mac || is_link_local_ether_addr(dst_mac)) {
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
tx_ring = adapter->tx_ring[skb->queue_mapping];
#if PAGE_SIZE > IXGBE_MAX_DATA_PER_TXD
for (f = 0; f < skb_shinfo(skb)->nr_frags; f++)
count += TXD_USE_COUNT(skb_shinfo(skb)->frags[f].size);
#else
count += skb_shinfo(skb)->nr_frags;
#endif
if (ixgbevf_maybe_stop_tx(tx_ring, count + 3)) {
tx_ring->tx_stats.tx_busy++;
return NETDEV_TX_BUSY;
}
first = &tx_ring->tx_buffer_info[tx_ring->next_to_use];
first->skb = skb;
first->bytecount = skb->len;
first->gso_segs = 1;
if (skb_vlan_tag_present(skb)) {
tx_flags |= skb_vlan_tag_get(skb);
tx_flags <<= IXGBE_TX_FLAGS_VLAN_SHIFT;
tx_flags |= IXGBE_TX_FLAGS_VLAN;
}
first->tx_flags = tx_flags;
first->protocol = vlan_get_protocol(skb);
tso = ixgbevf_tso(tx_ring, first, &hdr_len);
if (tso < 0)
goto out_drop;
else if (!tso)
ixgbevf_tx_csum(tx_ring, first);
ixgbevf_tx_map(tx_ring, first, hdr_len);
ixgbevf_maybe_stop_tx(tx_ring, DESC_NEEDED);
return NETDEV_TX_OK;
out_drop:
dev_kfree_skb_any(first->skb);
first->skb = NULL;
return NETDEV_TX_OK;
}
static int ixgbevf_set_mac(struct net_device *netdev, void *p)
{
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
struct sockaddr *addr = p;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
memcpy(netdev->dev_addr, addr->sa_data, netdev->addr_len);
memcpy(hw->mac.addr, addr->sa_data, netdev->addr_len);
spin_lock_bh(&adapter->mbx_lock);
hw->mac.ops.set_rar(hw, 0, hw->mac.addr, 0);
spin_unlock_bh(&adapter->mbx_lock);
return 0;
}
static int ixgbevf_change_mtu(struct net_device *netdev, int new_mtu)
{
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
int max_frame = new_mtu + ETH_HLEN + ETH_FCS_LEN;
int max_possible_frame = MAXIMUM_ETHERNET_VLAN_SIZE;
switch (adapter->hw.api_version) {
case ixgbe_mbox_api_11:
max_possible_frame = IXGBE_MAX_JUMBO_FRAME_SIZE;
break;
default:
if (adapter->hw.mac.type != ixgbe_mac_82599_vf)
max_possible_frame = IXGBE_MAX_JUMBO_FRAME_SIZE;
break;
}
if ((new_mtu < 68) || (max_frame > max_possible_frame))
return -EINVAL;
hw_dbg(hw, "changing MTU from %d to %d\n",
netdev->mtu, new_mtu);
netdev->mtu = new_mtu;
ixgbevf_rlpml_set_vf(hw, max_frame);
return 0;
}
static void ixgbevf_netpoll(struct net_device *netdev)
{
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
int i;
if (test_bit(__IXGBEVF_DOWN, &adapter->state))
return;
for (i = 0; i < adapter->num_rx_queues; i++)
ixgbevf_msix_clean_rings(0, adapter->q_vector[i]);
}
static int ixgbevf_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
#ifdef CONFIG_PM
int retval = 0;
#endif
netif_device_detach(netdev);
if (netif_running(netdev)) {
rtnl_lock();
ixgbevf_down(adapter);
ixgbevf_free_irq(adapter);
ixgbevf_free_all_tx_resources(adapter);
ixgbevf_free_all_rx_resources(adapter);
rtnl_unlock();
}
ixgbevf_clear_interrupt_scheme(adapter);
#ifdef CONFIG_PM
retval = pci_save_state(pdev);
if (retval)
return retval;
#endif
if (!test_and_set_bit(__IXGBEVF_DISABLED, &adapter->state))
pci_disable_device(pdev);
return 0;
}
static int ixgbevf_resume(struct pci_dev *pdev)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
u32 err;
pci_restore_state(pdev);
pci_save_state(pdev);
err = pci_enable_device_mem(pdev);
if (err) {
dev_err(&pdev->dev, "Cannot enable PCI device from suspend\n");
return err;
}
smp_mb__before_atomic();
clear_bit(__IXGBEVF_DISABLED, &adapter->state);
pci_set_master(pdev);
ixgbevf_reset(adapter);
rtnl_lock();
err = ixgbevf_init_interrupt_scheme(adapter);
rtnl_unlock();
if (err) {
dev_err(&pdev->dev, "Cannot initialize interrupts\n");
return err;
}
if (netif_running(netdev)) {
err = ixgbevf_open(netdev);
if (err)
return err;
}
netif_device_attach(netdev);
return err;
}
static void ixgbevf_shutdown(struct pci_dev *pdev)
{
ixgbevf_suspend(pdev, PMSG_SUSPEND);
}
static struct rtnl_link_stats64 *ixgbevf_get_stats(struct net_device *netdev,
struct rtnl_link_stats64 *stats)
{
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
unsigned int start;
u64 bytes, packets;
const struct ixgbevf_ring *ring;
int i;
ixgbevf_update_stats(adapter);
stats->multicast = adapter->stats.vfmprc - adapter->stats.base_vfmprc;
for (i = 0; i < adapter->num_rx_queues; i++) {
ring = adapter->rx_ring[i];
do {
start = u64_stats_fetch_begin_irq(&ring->syncp);
bytes = ring->stats.bytes;
packets = ring->stats.packets;
} while (u64_stats_fetch_retry_irq(&ring->syncp, start));
stats->rx_bytes += bytes;
stats->rx_packets += packets;
}
for (i = 0; i < adapter->num_tx_queues; i++) {
ring = adapter->tx_ring[i];
do {
start = u64_stats_fetch_begin_irq(&ring->syncp);
bytes = ring->stats.bytes;
packets = ring->stats.packets;
} while (u64_stats_fetch_retry_irq(&ring->syncp, start));
stats->tx_bytes += bytes;
stats->tx_packets += packets;
}
return stats;
}
static void ixgbevf_assign_netdev_ops(struct net_device *dev)
{
dev->netdev_ops = &ixgbevf_netdev_ops;
ixgbevf_set_ethtool_ops(dev);
dev->watchdog_timeo = 5 * HZ;
}
static int ixgbevf_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct net_device *netdev;
struct ixgbevf_adapter *adapter = NULL;
struct ixgbe_hw *hw = NULL;
const struct ixgbevf_info *ii = ixgbevf_info_tbl[ent->driver_data];
int err, pci_using_dac;
bool disable_dev = false;
err = pci_enable_device(pdev);
if (err)
return err;
if (!dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(64))) {
pci_using_dac = 1;
} else {
err = dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32));
if (err) {
dev_err(&pdev->dev, "No usable DMA "
"configuration, aborting\n");
goto err_dma;
}
pci_using_dac = 0;
}
err = pci_request_regions(pdev, ixgbevf_driver_name);
if (err) {
dev_err(&pdev->dev, "pci_request_regions failed 0x%x\n", err);
goto err_pci_reg;
}
pci_set_master(pdev);
netdev = alloc_etherdev_mq(sizeof(struct ixgbevf_adapter),
MAX_TX_QUEUES);
if (!netdev) {
err = -ENOMEM;
goto err_alloc_etherdev;
}
SET_NETDEV_DEV(netdev, &pdev->dev);
adapter = netdev_priv(netdev);
adapter->netdev = netdev;
adapter->pdev = pdev;
hw = &adapter->hw;
hw->back = adapter;
adapter->msg_enable = netif_msg_init(debug, DEFAULT_MSG_ENABLE);
pci_save_state(pdev);
hw->hw_addr = ioremap(pci_resource_start(pdev, 0),
pci_resource_len(pdev, 0));
adapter->io_addr = hw->hw_addr;
if (!hw->hw_addr) {
err = -EIO;
goto err_ioremap;
}
ixgbevf_assign_netdev_ops(netdev);
memcpy(&hw->mac.ops, ii->mac_ops, sizeof(hw->mac.ops));
hw->mac.type = ii->mac;
memcpy(&hw->mbx.ops, &ixgbevf_mbx_ops,
sizeof(struct ixgbe_mbx_operations));
err = ixgbevf_sw_init(adapter);
if (err)
goto err_sw_init;
if (!is_valid_ether_addr(netdev->dev_addr)) {
pr_err("invalid MAC address\n");
err = -EIO;
goto err_sw_init;
}
netdev->hw_features = NETIF_F_SG |
NETIF_F_IP_CSUM |
NETIF_F_IPV6_CSUM |
NETIF_F_TSO |
NETIF_F_TSO6 |
NETIF_F_RXCSUM;
netdev->features = netdev->hw_features |
NETIF_F_HW_VLAN_CTAG_TX |
NETIF_F_HW_VLAN_CTAG_RX |
NETIF_F_HW_VLAN_CTAG_FILTER;
netdev->vlan_features |= NETIF_F_TSO |
NETIF_F_TSO6 |
NETIF_F_IP_CSUM |
NETIF_F_IPV6_CSUM |
NETIF_F_SG;
if (pci_using_dac)
netdev->features |= NETIF_F_HIGHDMA;
netdev->priv_flags |= IFF_UNICAST_FLT;
if (IXGBE_REMOVED(hw->hw_addr)) {
err = -EIO;
goto err_sw_init;
}
setup_timer(&adapter->service_timer, &ixgbevf_service_timer,
(unsigned long)adapter);
INIT_WORK(&adapter->service_task, ixgbevf_service_task);
set_bit(__IXGBEVF_SERVICE_INITED, &adapter->state);
clear_bit(__IXGBEVF_SERVICE_SCHED, &adapter->state);
err = ixgbevf_init_interrupt_scheme(adapter);
if (err)
goto err_sw_init;
strcpy(netdev->name, "eth%d");
err = register_netdev(netdev);
if (err)
goto err_register;
pci_set_drvdata(pdev, netdev);
netif_carrier_off(netdev);
ixgbevf_init_last_counter_stats(adapter);
dev_info(&pdev->dev, "%pM\n", netdev->dev_addr);
dev_info(&pdev->dev, "MAC: %d\n", hw->mac.type);
switch (hw->mac.type) {
case ixgbe_mac_X550_vf:
dev_info(&pdev->dev, "Intel(R) X550 Virtual Function\n");
break;
case ixgbe_mac_X540_vf:
dev_info(&pdev->dev, "Intel(R) X540 Virtual Function\n");
break;
case ixgbe_mac_82599_vf:
default:
dev_info(&pdev->dev, "Intel(R) 82599 Virtual Function\n");
break;
}
return 0;
err_register:
ixgbevf_clear_interrupt_scheme(adapter);
err_sw_init:
ixgbevf_reset_interrupt_capability(adapter);
iounmap(adapter->io_addr);
err_ioremap:
disable_dev = !test_and_set_bit(__IXGBEVF_DISABLED, &adapter->state);
free_netdev(netdev);
err_alloc_etherdev:
pci_release_regions(pdev);
err_pci_reg:
err_dma:
if (!adapter || disable_dev)
pci_disable_device(pdev);
return err;
}
static void ixgbevf_remove(struct pci_dev *pdev)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct ixgbevf_adapter *adapter;
bool disable_dev;
if (!netdev)
return;
adapter = netdev_priv(netdev);
set_bit(__IXGBEVF_REMOVING, &adapter->state);
cancel_work_sync(&adapter->service_task);
if (netdev->reg_state == NETREG_REGISTERED)
unregister_netdev(netdev);
ixgbevf_clear_interrupt_scheme(adapter);
ixgbevf_reset_interrupt_capability(adapter);
iounmap(adapter->io_addr);
pci_release_regions(pdev);
hw_dbg(&adapter->hw, "Remove complete\n");
disable_dev = !test_and_set_bit(__IXGBEVF_DISABLED, &adapter->state);
free_netdev(netdev);
if (disable_dev)
pci_disable_device(pdev);
}
static pci_ers_result_t ixgbevf_io_error_detected(struct pci_dev *pdev,
pci_channel_state_t state)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
if (!test_bit(__IXGBEVF_SERVICE_INITED, &adapter->state))
return PCI_ERS_RESULT_DISCONNECT;
rtnl_lock();
netif_device_detach(netdev);
if (state == pci_channel_io_perm_failure) {
rtnl_unlock();
return PCI_ERS_RESULT_DISCONNECT;
}
if (netif_running(netdev))
ixgbevf_down(adapter);
if (!test_and_set_bit(__IXGBEVF_DISABLED, &adapter->state))
pci_disable_device(pdev);
rtnl_unlock();
return PCI_ERS_RESULT_NEED_RESET;
}
static pci_ers_result_t ixgbevf_io_slot_reset(struct pci_dev *pdev)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
if (pci_enable_device_mem(pdev)) {
dev_err(&pdev->dev,
"Cannot re-enable PCI device after reset.\n");
return PCI_ERS_RESULT_DISCONNECT;
}
smp_mb__before_atomic();
clear_bit(__IXGBEVF_DISABLED, &adapter->state);
pci_set_master(pdev);
ixgbevf_reset(adapter);
return PCI_ERS_RESULT_RECOVERED;
}
static void ixgbevf_io_resume(struct pci_dev *pdev)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
if (netif_running(netdev))
ixgbevf_up(adapter);
netif_device_attach(netdev);
}
static int __init ixgbevf_init_module(void)
{
int ret;
pr_info("%s - version %s\n", ixgbevf_driver_string,
ixgbevf_driver_version);
pr_info("%s\n", ixgbevf_copyright);
ret = pci_register_driver(&ixgbevf_driver);
return ret;
}
static void __exit ixgbevf_exit_module(void)
{
pci_unregister_driver(&ixgbevf_driver);
}
char *ixgbevf_get_hw_dev_name(struct ixgbe_hw *hw)
{
struct ixgbevf_adapter *adapter = hw->back;
return adapter->netdev->name;
}
