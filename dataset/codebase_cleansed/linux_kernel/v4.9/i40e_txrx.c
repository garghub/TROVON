static inline __le64 build_ctob(u32 td_cmd, u32 td_offset, unsigned int size,
u32 td_tag)
{
return cpu_to_le64(I40E_TX_DESC_DTYPE_DATA |
((u64)td_cmd << I40E_TXD_QW1_CMD_SHIFT) |
((u64)td_offset << I40E_TXD_QW1_OFFSET_SHIFT) |
((u64)size << I40E_TXD_QW1_TX_BUF_SZ_SHIFT) |
((u64)td_tag << I40E_TXD_QW1_L2TAG1_SHIFT));
}
static void i40e_unmap_and_free_tx_resource(struct i40e_ring *ring,
struct i40e_tx_buffer *tx_buffer)
{
if (tx_buffer->skb) {
if (tx_buffer->tx_flags & I40E_TX_FLAGS_FD_SB)
kfree(tx_buffer->raw_buf);
else
dev_kfree_skb_any(tx_buffer->skb);
if (dma_unmap_len(tx_buffer, len))
dma_unmap_single(ring->dev,
dma_unmap_addr(tx_buffer, dma),
dma_unmap_len(tx_buffer, len),
DMA_TO_DEVICE);
} else if (dma_unmap_len(tx_buffer, len)) {
dma_unmap_page(ring->dev,
dma_unmap_addr(tx_buffer, dma),
dma_unmap_len(tx_buffer, len),
DMA_TO_DEVICE);
}
tx_buffer->next_to_watch = NULL;
tx_buffer->skb = NULL;
dma_unmap_len_set(tx_buffer, len, 0);
}
void i40evf_clean_tx_ring(struct i40e_ring *tx_ring)
{
unsigned long bi_size;
u16 i;
if (!tx_ring->tx_bi)
return;
for (i = 0; i < tx_ring->count; i++)
i40e_unmap_and_free_tx_resource(tx_ring, &tx_ring->tx_bi[i]);
bi_size = sizeof(struct i40e_tx_buffer) * tx_ring->count;
memset(tx_ring->tx_bi, 0, bi_size);
memset(tx_ring->desc, 0, tx_ring->size);
tx_ring->next_to_use = 0;
tx_ring->next_to_clean = 0;
if (!tx_ring->netdev)
return;
netdev_tx_reset_queue(txring_txq(tx_ring));
}
void i40evf_free_tx_resources(struct i40e_ring *tx_ring)
{
i40evf_clean_tx_ring(tx_ring);
kfree(tx_ring->tx_bi);
tx_ring->tx_bi = NULL;
if (tx_ring->desc) {
dma_free_coherent(tx_ring->dev, tx_ring->size,
tx_ring->desc, tx_ring->dma);
tx_ring->desc = NULL;
}
}
u32 i40evf_get_tx_pending(struct i40e_ring *ring, bool in_sw)
{
u32 head, tail;
if (!in_sw)
head = i40e_get_head(ring);
else
head = ring->next_to_clean;
tail = readl(ring->tail);
if (head != tail)
return (head < tail) ?
tail - head : (tail + ring->count - head);
return 0;
}
static bool i40e_clean_tx_irq(struct i40e_vsi *vsi,
struct i40e_ring *tx_ring, int napi_budget)
{
u16 i = tx_ring->next_to_clean;
struct i40e_tx_buffer *tx_buf;
struct i40e_tx_desc *tx_head;
struct i40e_tx_desc *tx_desc;
unsigned int total_bytes = 0, total_packets = 0;
unsigned int budget = vsi->work_limit;
tx_buf = &tx_ring->tx_bi[i];
tx_desc = I40E_TX_DESC(tx_ring, i);
i -= tx_ring->count;
tx_head = I40E_TX_DESC(tx_ring, i40e_get_head(tx_ring));
do {
struct i40e_tx_desc *eop_desc = tx_buf->next_to_watch;
if (!eop_desc)
break;
read_barrier_depends();
if (tx_head == tx_desc)
break;
tx_buf->next_to_watch = NULL;
total_bytes += tx_buf->bytecount;
total_packets += tx_buf->gso_segs;
napi_consume_skb(tx_buf->skb, napi_budget);
dma_unmap_single(tx_ring->dev,
dma_unmap_addr(tx_buf, dma),
dma_unmap_len(tx_buf, len),
DMA_TO_DEVICE);
tx_buf->skb = NULL;
dma_unmap_len_set(tx_buf, len, 0);
while (tx_desc != eop_desc) {
tx_buf++;
tx_desc++;
i++;
if (unlikely(!i)) {
i -= tx_ring->count;
tx_buf = tx_ring->tx_bi;
tx_desc = I40E_TX_DESC(tx_ring, 0);
}
if (dma_unmap_len(tx_buf, len)) {
dma_unmap_page(tx_ring->dev,
dma_unmap_addr(tx_buf, dma),
dma_unmap_len(tx_buf, len),
DMA_TO_DEVICE);
dma_unmap_len_set(tx_buf, len, 0);
}
}
tx_buf++;
tx_desc++;
i++;
if (unlikely(!i)) {
i -= tx_ring->count;
tx_buf = tx_ring->tx_bi;
tx_desc = I40E_TX_DESC(tx_ring, 0);
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
tx_ring->q_vector->tx.total_bytes += total_bytes;
tx_ring->q_vector->tx.total_packets += total_packets;
if (tx_ring->flags & I40E_TXR_FLAGS_WB_ON_ITR) {
unsigned int j = i40evf_get_tx_pending(tx_ring, false);
if (budget &&
((j / (WB_STRIDE + 1)) == 0) && (j > 0) &&
!test_bit(__I40E_DOWN, &vsi->state) &&
(I40E_DESC_UNUSED(tx_ring) != tx_ring->count))
tx_ring->arm_wb = true;
}
netdev_tx_completed_queue(txring_txq(tx_ring),
total_packets, total_bytes);
#define TX_WAKE_THRESHOLD (DESC_NEEDED * 2)
if (unlikely(total_packets && netif_carrier_ok(tx_ring->netdev) &&
(I40E_DESC_UNUSED(tx_ring) >= TX_WAKE_THRESHOLD))) {
smp_mb();
if (__netif_subqueue_stopped(tx_ring->netdev,
tx_ring->queue_index) &&
!test_bit(__I40E_DOWN, &vsi->state)) {
netif_wake_subqueue(tx_ring->netdev,
tx_ring->queue_index);
++tx_ring->tx_stats.restart_queue;
}
}
return !!budget;
}
static void i40e_enable_wb_on_itr(struct i40e_vsi *vsi,
struct i40e_q_vector *q_vector)
{
u16 flags = q_vector->tx.ring[0].flags;
u32 val;
if (!(flags & I40E_TXR_FLAGS_WB_ON_ITR))
return;
if (q_vector->arm_wb_state)
return;
val = I40E_VFINT_DYN_CTLN1_WB_ON_ITR_MASK |
I40E_VFINT_DYN_CTLN1_ITR_INDX_MASK;
wr32(&vsi->back->hw,
I40E_VFINT_DYN_CTLN1(q_vector->v_idx +
vsi->base_vector - 1), val);
q_vector->arm_wb_state = true;
}
void i40evf_force_wb(struct i40e_vsi *vsi, struct i40e_q_vector *q_vector)
{
u32 val = I40E_VFINT_DYN_CTLN1_INTENA_MASK |
I40E_VFINT_DYN_CTLN1_ITR_INDX_MASK |
I40E_VFINT_DYN_CTLN1_SWINT_TRIG_MASK |
I40E_VFINT_DYN_CTLN1_SW_ITR_INDX_ENA_MASK
;
wr32(&vsi->back->hw,
I40E_VFINT_DYN_CTLN1(q_vector->v_idx + vsi->base_vector - 1),
val);
}
static bool i40e_set_new_dynamic_itr(struct i40e_ring_container *rc)
{
enum i40e_latency_range new_latency_range = rc->latency_range;
struct i40e_q_vector *qv = rc->ring->q_vector;
u32 new_itr = rc->itr;
int bytes_per_int;
int usecs;
if (rc->total_packets == 0 || !rc->itr)
return false;
usecs = (rc->itr << 1) * ITR_COUNTDOWN_START;
bytes_per_int = rc->total_bytes / usecs;
switch (new_latency_range) {
case I40E_LOWEST_LATENCY:
if (bytes_per_int > 10)
new_latency_range = I40E_LOW_LATENCY;
break;
case I40E_LOW_LATENCY:
if (bytes_per_int > 20)
new_latency_range = I40E_BULK_LATENCY;
else if (bytes_per_int <= 10)
new_latency_range = I40E_LOWEST_LATENCY;
break;
case I40E_BULK_LATENCY:
case I40E_ULTRA_LATENCY:
default:
if (bytes_per_int <= 20)
new_latency_range = I40E_LOW_LATENCY;
break;
}
#define RX_ULTRA_PACKET_RATE 40000
if ((((rc->total_packets * 1000000) / usecs) > RX_ULTRA_PACKET_RATE) &&
(&qv->rx == rc))
new_latency_range = I40E_ULTRA_LATENCY;
rc->latency_range = new_latency_range;
switch (new_latency_range) {
case I40E_LOWEST_LATENCY:
new_itr = I40E_ITR_50K;
break;
case I40E_LOW_LATENCY:
new_itr = I40E_ITR_20K;
break;
case I40E_BULK_LATENCY:
new_itr = I40E_ITR_18K;
break;
case I40E_ULTRA_LATENCY:
new_itr = I40E_ITR_8K;
break;
default:
break;
}
rc->total_bytes = 0;
rc->total_packets = 0;
if (new_itr != rc->itr) {
rc->itr = new_itr;
return true;
}
return false;
}
int i40evf_setup_tx_descriptors(struct i40e_ring *tx_ring)
{
struct device *dev = tx_ring->dev;
int bi_size;
if (!dev)
return -ENOMEM;
WARN_ON(tx_ring->tx_bi);
bi_size = sizeof(struct i40e_tx_buffer) * tx_ring->count;
tx_ring->tx_bi = kzalloc(bi_size, GFP_KERNEL);
if (!tx_ring->tx_bi)
goto err;
tx_ring->size = tx_ring->count * sizeof(struct i40e_tx_desc);
tx_ring->size += sizeof(u32);
tx_ring->size = ALIGN(tx_ring->size, 4096);
tx_ring->desc = dma_alloc_coherent(dev, tx_ring->size,
&tx_ring->dma, GFP_KERNEL);
if (!tx_ring->desc) {
dev_info(dev, "Unable to allocate memory for the Tx descriptor ring, size=%d\n",
tx_ring->size);
goto err;
}
tx_ring->next_to_use = 0;
tx_ring->next_to_clean = 0;
return 0;
err:
kfree(tx_ring->tx_bi);
tx_ring->tx_bi = NULL;
return -ENOMEM;
}
void i40evf_clean_rx_ring(struct i40e_ring *rx_ring)
{
struct device *dev = rx_ring->dev;
unsigned long bi_size;
u16 i;
if (!rx_ring->rx_bi)
return;
for (i = 0; i < rx_ring->count; i++) {
struct i40e_rx_buffer *rx_bi = &rx_ring->rx_bi[i];
if (rx_bi->skb) {
dev_kfree_skb(rx_bi->skb);
rx_bi->skb = NULL;
}
if (!rx_bi->page)
continue;
dma_unmap_page(dev, rx_bi->dma, PAGE_SIZE, DMA_FROM_DEVICE);
__free_pages(rx_bi->page, 0);
rx_bi->page = NULL;
rx_bi->page_offset = 0;
}
bi_size = sizeof(struct i40e_rx_buffer) * rx_ring->count;
memset(rx_ring->rx_bi, 0, bi_size);
memset(rx_ring->desc, 0, rx_ring->size);
rx_ring->next_to_alloc = 0;
rx_ring->next_to_clean = 0;
rx_ring->next_to_use = 0;
}
void i40evf_free_rx_resources(struct i40e_ring *rx_ring)
{
i40evf_clean_rx_ring(rx_ring);
kfree(rx_ring->rx_bi);
rx_ring->rx_bi = NULL;
if (rx_ring->desc) {
dma_free_coherent(rx_ring->dev, rx_ring->size,
rx_ring->desc, rx_ring->dma);
rx_ring->desc = NULL;
}
}
int i40evf_setup_rx_descriptors(struct i40e_ring *rx_ring)
{
struct device *dev = rx_ring->dev;
int bi_size;
WARN_ON(rx_ring->rx_bi);
bi_size = sizeof(struct i40e_rx_buffer) * rx_ring->count;
rx_ring->rx_bi = kzalloc(bi_size, GFP_KERNEL);
if (!rx_ring->rx_bi)
goto err;
u64_stats_init(&rx_ring->syncp);
rx_ring->size = rx_ring->count * sizeof(union i40e_32byte_rx_desc);
rx_ring->size = ALIGN(rx_ring->size, 4096);
rx_ring->desc = dma_alloc_coherent(dev, rx_ring->size,
&rx_ring->dma, GFP_KERNEL);
if (!rx_ring->desc) {
dev_info(dev, "Unable to allocate memory for the Rx descriptor ring, size=%d\n",
rx_ring->size);
goto err;
}
rx_ring->next_to_alloc = 0;
rx_ring->next_to_clean = 0;
rx_ring->next_to_use = 0;
return 0;
err:
kfree(rx_ring->rx_bi);
rx_ring->rx_bi = NULL;
return -ENOMEM;
}
static inline void i40e_release_rx_desc(struct i40e_ring *rx_ring, u32 val)
{
rx_ring->next_to_use = val;
rx_ring->next_to_alloc = val;
wmb();
writel(val, rx_ring->tail);
}
static bool i40e_alloc_mapped_page(struct i40e_ring *rx_ring,
struct i40e_rx_buffer *bi)
{
struct page *page = bi->page;
dma_addr_t dma;
if (likely(page)) {
rx_ring->rx_stats.page_reuse_count++;
return true;
}
page = dev_alloc_page();
if (unlikely(!page)) {
rx_ring->rx_stats.alloc_page_failed++;
return false;
}
dma = dma_map_page(rx_ring->dev, page, 0, PAGE_SIZE, DMA_FROM_DEVICE);
if (dma_mapping_error(rx_ring->dev, dma)) {
__free_pages(page, 0);
rx_ring->rx_stats.alloc_page_failed++;
return false;
}
bi->dma = dma;
bi->page = page;
bi->page_offset = 0;
return true;
}
static void i40e_receive_skb(struct i40e_ring *rx_ring,
struct sk_buff *skb, u16 vlan_tag)
{
struct i40e_q_vector *q_vector = rx_ring->q_vector;
if ((rx_ring->netdev->features & NETIF_F_HW_VLAN_CTAG_RX) &&
(vlan_tag & VLAN_VID_MASK))
__vlan_hwaccel_put_tag(skb, htons(ETH_P_8021Q), vlan_tag);
napi_gro_receive(&q_vector->napi, skb);
}
bool i40evf_alloc_rx_buffers(struct i40e_ring *rx_ring, u16 cleaned_count)
{
u16 ntu = rx_ring->next_to_use;
union i40e_rx_desc *rx_desc;
struct i40e_rx_buffer *bi;
if (!rx_ring->netdev || !cleaned_count)
return false;
rx_desc = I40E_RX_DESC(rx_ring, ntu);
bi = &rx_ring->rx_bi[ntu];
do {
if (!i40e_alloc_mapped_page(rx_ring, bi))
goto no_buffers;
rx_desc->read.pkt_addr = cpu_to_le64(bi->dma + bi->page_offset);
rx_desc->read.hdr_addr = 0;
rx_desc++;
bi++;
ntu++;
if (unlikely(ntu == rx_ring->count)) {
rx_desc = I40E_RX_DESC(rx_ring, 0);
bi = rx_ring->rx_bi;
ntu = 0;
}
rx_desc->wb.qword1.status_error_len = 0;
cleaned_count--;
} while (cleaned_count);
if (rx_ring->next_to_use != ntu)
i40e_release_rx_desc(rx_ring, ntu);
return false;
no_buffers:
if (rx_ring->next_to_use != ntu)
i40e_release_rx_desc(rx_ring, ntu);
return true;
}
static inline void i40e_rx_checksum(struct i40e_vsi *vsi,
struct sk_buff *skb,
union i40e_rx_desc *rx_desc)
{
struct i40e_rx_ptype_decoded decoded;
u32 rx_error, rx_status;
bool ipv4, ipv6;
u8 ptype;
u64 qword;
qword = le64_to_cpu(rx_desc->wb.qword1.status_error_len);
ptype = (qword & I40E_RXD_QW1_PTYPE_MASK) >> I40E_RXD_QW1_PTYPE_SHIFT;
rx_error = (qword & I40E_RXD_QW1_ERROR_MASK) >>
I40E_RXD_QW1_ERROR_SHIFT;
rx_status = (qword & I40E_RXD_QW1_STATUS_MASK) >>
I40E_RXD_QW1_STATUS_SHIFT;
decoded = decode_rx_desc_ptype(ptype);
skb->ip_summed = CHECKSUM_NONE;
skb_checksum_none_assert(skb);
if (!(vsi->netdev->features & NETIF_F_RXCSUM))
return;
if (!(rx_status & BIT(I40E_RX_DESC_STATUS_L3L4P_SHIFT)))
return;
if (!(decoded.known && decoded.outer_ip))
return;
ipv4 = (decoded.outer_ip == I40E_RX_PTYPE_OUTER_IP) &&
(decoded.outer_ip_ver == I40E_RX_PTYPE_OUTER_IPV4);
ipv6 = (decoded.outer_ip == I40E_RX_PTYPE_OUTER_IP) &&
(decoded.outer_ip_ver == I40E_RX_PTYPE_OUTER_IPV6);
if (ipv4 &&
(rx_error & (BIT(I40E_RX_DESC_ERROR_IPE_SHIFT) |
BIT(I40E_RX_DESC_ERROR_EIPE_SHIFT))))
goto checksum_fail;
if (ipv6 &&
rx_status & BIT(I40E_RX_DESC_STATUS_IPV6EXADD_SHIFT))
return;
if (rx_error & BIT(I40E_RX_DESC_ERROR_L4E_SHIFT))
goto checksum_fail;
if (rx_error & BIT(I40E_RX_DESC_ERROR_PPRS_SHIFT))
return;
if (decoded.tunnel_type >= I40E_RX_PTYPE_TUNNEL_IP_GRENAT)
skb->csum_level = 1;
switch (decoded.inner_prot) {
case I40E_RX_PTYPE_INNER_PROT_TCP:
case I40E_RX_PTYPE_INNER_PROT_UDP:
case I40E_RX_PTYPE_INNER_PROT_SCTP:
skb->ip_summed = CHECKSUM_UNNECESSARY;
default:
break;
}
return;
checksum_fail:
vsi->back->hw_csum_rx_error++;
}
static inline int i40e_ptype_to_htype(u8 ptype)
{
struct i40e_rx_ptype_decoded decoded = decode_rx_desc_ptype(ptype);
if (!decoded.known)
return PKT_HASH_TYPE_NONE;
if (decoded.outer_ip == I40E_RX_PTYPE_OUTER_IP &&
decoded.payload_layer == I40E_RX_PTYPE_PAYLOAD_LAYER_PAY4)
return PKT_HASH_TYPE_L4;
else if (decoded.outer_ip == I40E_RX_PTYPE_OUTER_IP &&
decoded.payload_layer == I40E_RX_PTYPE_PAYLOAD_LAYER_PAY3)
return PKT_HASH_TYPE_L3;
else
return PKT_HASH_TYPE_L2;
}
static inline void i40e_rx_hash(struct i40e_ring *ring,
union i40e_rx_desc *rx_desc,
struct sk_buff *skb,
u8 rx_ptype)
{
u32 hash;
const __le64 rss_mask =
cpu_to_le64((u64)I40E_RX_DESC_FLTSTAT_RSS_HASH <<
I40E_RX_DESC_STATUS_FLTSTAT_SHIFT);
if (ring->netdev->features & NETIF_F_RXHASH)
return;
if ((rx_desc->wb.qword1.status_error_len & rss_mask) == rss_mask) {
hash = le32_to_cpu(rx_desc->wb.qword0.hi_dword.rss);
skb_set_hash(skb, hash, i40e_ptype_to_htype(rx_ptype));
}
}
static inline
void i40evf_process_skb_fields(struct i40e_ring *rx_ring,
union i40e_rx_desc *rx_desc, struct sk_buff *skb,
u8 rx_ptype)
{
i40e_rx_hash(rx_ring, rx_desc, skb, rx_ptype);
skb->protocol = eth_type_trans(skb, rx_ring->netdev);
i40e_rx_checksum(rx_ring->vsi, skb, rx_desc);
skb_record_rx_queue(skb, rx_ring->queue_index);
}
static void i40e_pull_tail(struct i40e_ring *rx_ring, struct sk_buff *skb)
{
struct skb_frag_struct *frag = &skb_shinfo(skb)->frags[0];
unsigned char *va;
unsigned int pull_len;
va = skb_frag_address(frag);
pull_len = eth_get_headlen(va, I40E_RX_HDR_SIZE);
skb_copy_to_linear_data(skb, va, ALIGN(pull_len, sizeof(long)));
skb_frag_size_sub(frag, pull_len);
frag->page_offset += pull_len;
skb->data_len -= pull_len;
skb->tail += pull_len;
}
static bool i40e_cleanup_headers(struct i40e_ring *rx_ring, struct sk_buff *skb)
{
if (skb_is_nonlinear(skb))
i40e_pull_tail(rx_ring, skb);
if (eth_skb_pad(skb))
return true;
return false;
}
static void i40e_reuse_rx_page(struct i40e_ring *rx_ring,
struct i40e_rx_buffer *old_buff)
{
struct i40e_rx_buffer *new_buff;
u16 nta = rx_ring->next_to_alloc;
new_buff = &rx_ring->rx_bi[nta];
nta++;
rx_ring->next_to_alloc = (nta < rx_ring->count) ? nta : 0;
*new_buff = *old_buff;
}
static inline bool i40e_page_is_reserved(struct page *page)
{
return (page_to_nid(page) != numa_mem_id()) || page_is_pfmemalloc(page);
}
static bool i40e_add_rx_frag(struct i40e_ring *rx_ring,
struct i40e_rx_buffer *rx_buffer,
union i40e_rx_desc *rx_desc,
struct sk_buff *skb)
{
struct page *page = rx_buffer->page;
u64 qword = le64_to_cpu(rx_desc->wb.qword1.status_error_len);
unsigned int size = (qword & I40E_RXD_QW1_LENGTH_PBUF_MASK) >>
I40E_RXD_QW1_LENGTH_PBUF_SHIFT;
#if (PAGE_SIZE < 8192)
unsigned int truesize = I40E_RXBUFFER_2048;
#else
unsigned int truesize = ALIGN(size, L1_CACHE_BYTES);
unsigned int last_offset = PAGE_SIZE - I40E_RXBUFFER_2048;
#endif
if ((size <= I40E_RX_HDR_SIZE) && !skb_is_nonlinear(skb)) {
unsigned char *va = page_address(page) + rx_buffer->page_offset;
memcpy(__skb_put(skb, size), va, ALIGN(size, sizeof(long)));
if (likely(!i40e_page_is_reserved(page)))
return true;
__free_pages(page, 0);
return false;
}
skb_add_rx_frag(skb, skb_shinfo(skb)->nr_frags, page,
rx_buffer->page_offset, size, truesize);
if (unlikely(i40e_page_is_reserved(page)))
return false;
#if (PAGE_SIZE < 8192)
if (unlikely(page_count(page) != 1))
return false;
rx_buffer->page_offset ^= truesize;
#else
rx_buffer->page_offset += truesize;
if (rx_buffer->page_offset > last_offset)
return false;
#endif
get_page(rx_buffer->page);
return true;
}
static inline
struct sk_buff *i40evf_fetch_rx_buffer(struct i40e_ring *rx_ring,
union i40e_rx_desc *rx_desc)
{
struct i40e_rx_buffer *rx_buffer;
struct sk_buff *skb;
struct page *page;
rx_buffer = &rx_ring->rx_bi[rx_ring->next_to_clean];
page = rx_buffer->page;
prefetchw(page);
skb = rx_buffer->skb;
if (likely(!skb)) {
void *page_addr = page_address(page) + rx_buffer->page_offset;
prefetch(page_addr);
#if L1_CACHE_BYTES < 128
prefetch(page_addr + L1_CACHE_BYTES);
#endif
skb = __napi_alloc_skb(&rx_ring->q_vector->napi,
I40E_RX_HDR_SIZE,
GFP_ATOMIC | __GFP_NOWARN);
if (unlikely(!skb)) {
rx_ring->rx_stats.alloc_buff_failed++;
return NULL;
}
prefetchw(skb->data);
} else {
rx_buffer->skb = NULL;
}
dma_sync_single_range_for_cpu(rx_ring->dev,
rx_buffer->dma,
rx_buffer->page_offset,
I40E_RXBUFFER_2048,
DMA_FROM_DEVICE);
if (i40e_add_rx_frag(rx_ring, rx_buffer, rx_desc, skb)) {
i40e_reuse_rx_page(rx_ring, rx_buffer);
rx_ring->rx_stats.page_reuse_count++;
} else {
dma_unmap_page(rx_ring->dev, rx_buffer->dma, PAGE_SIZE,
DMA_FROM_DEVICE);
}
rx_buffer->page = NULL;
return skb;
}
static bool i40e_is_non_eop(struct i40e_ring *rx_ring,
union i40e_rx_desc *rx_desc,
struct sk_buff *skb)
{
u32 ntc = rx_ring->next_to_clean + 1;
ntc = (ntc < rx_ring->count) ? ntc : 0;
rx_ring->next_to_clean = ntc;
prefetch(I40E_RX_DESC(rx_ring, ntc));
#define I40E_RXD_EOF BIT(I40E_RX_DESC_STATUS_EOF_SHIFT)
if (likely(i40e_test_staterr(rx_desc, I40E_RXD_EOF)))
return false;
rx_ring->rx_bi[ntc].skb = skb;
rx_ring->rx_stats.non_eop_descs++;
return true;
}
static int i40e_clean_rx_irq(struct i40e_ring *rx_ring, int budget)
{
unsigned int total_rx_bytes = 0, total_rx_packets = 0;
u16 cleaned_count = I40E_DESC_UNUSED(rx_ring);
bool failure = false;
while (likely(total_rx_packets < budget)) {
union i40e_rx_desc *rx_desc;
struct sk_buff *skb;
u32 rx_status;
u16 vlan_tag;
u8 rx_ptype;
u64 qword;
if (cleaned_count >= I40E_RX_BUFFER_WRITE) {
failure = failure ||
i40evf_alloc_rx_buffers(rx_ring, cleaned_count);
cleaned_count = 0;
}
rx_desc = I40E_RX_DESC(rx_ring, rx_ring->next_to_clean);
qword = le64_to_cpu(rx_desc->wb.qword1.status_error_len);
rx_ptype = (qword & I40E_RXD_QW1_PTYPE_MASK) >>
I40E_RXD_QW1_PTYPE_SHIFT;
rx_status = (qword & I40E_RXD_QW1_STATUS_MASK) >>
I40E_RXD_QW1_STATUS_SHIFT;
if (!(rx_status & BIT(I40E_RX_DESC_STATUS_DD_SHIFT)))
break;
if (!rx_desc->wb.qword1.status_error_len)
break;
dma_rmb();
skb = i40evf_fetch_rx_buffer(rx_ring, rx_desc);
if (!skb)
break;
cleaned_count++;
if (i40e_is_non_eop(rx_ring, rx_desc, skb))
continue;
if (unlikely(i40e_test_staterr(rx_desc, BIT(I40E_RXD_QW1_ERROR_SHIFT)))) {
dev_kfree_skb_any(skb);
continue;
}
if (i40e_cleanup_headers(rx_ring, skb))
continue;
total_rx_bytes += skb->len;
i40evf_process_skb_fields(rx_ring, rx_desc, skb, rx_ptype);
vlan_tag = (qword & BIT(I40E_RX_DESC_STATUS_L2TAG1P_SHIFT)) ?
le16_to_cpu(rx_desc->wb.qword0.lo_dword.l2tag1) : 0;
i40e_receive_skb(rx_ring, skb, vlan_tag);
total_rx_packets++;
}
u64_stats_update_begin(&rx_ring->syncp);
rx_ring->stats.packets += total_rx_packets;
rx_ring->stats.bytes += total_rx_bytes;
u64_stats_update_end(&rx_ring->syncp);
rx_ring->q_vector->rx.total_packets += total_rx_packets;
rx_ring->q_vector->rx.total_bytes += total_rx_bytes;
return failure ? budget : total_rx_packets;
}
static u32 i40e_buildreg_itr(const int type, const u16 itr)
{
u32 val;
val = I40E_VFINT_DYN_CTLN1_INTENA_MASK |
(type << I40E_VFINT_DYN_CTLN1_ITR_INDX_SHIFT) |
(itr << I40E_VFINT_DYN_CTLN1_INTERVAL_SHIFT);
return val;
}
static inline int get_rx_itr_enabled(struct i40e_vsi *vsi, int idx)
{
struct i40evf_adapter *adapter = vsi->back;
return !!(adapter->rx_rings[idx].rx_itr_setting);
}
static inline int get_tx_itr_enabled(struct i40e_vsi *vsi, int idx)
{
struct i40evf_adapter *adapter = vsi->back;
return !!(adapter->tx_rings[idx].tx_itr_setting);
}
static inline void i40e_update_enable_itr(struct i40e_vsi *vsi,
struct i40e_q_vector *q_vector)
{
struct i40e_hw *hw = &vsi->back->hw;
bool rx = false, tx = false;
u32 rxval, txval;
int vector;
int idx = q_vector->v_idx;
int rx_itr_setting, tx_itr_setting;
vector = (q_vector->v_idx + vsi->base_vector);
rxval = txval = i40e_buildreg_itr(I40E_ITR_NONE, 0);
rx_itr_setting = get_rx_itr_enabled(vsi, idx);
tx_itr_setting = get_tx_itr_enabled(vsi, idx);
if (q_vector->itr_countdown > 0 ||
(!ITR_IS_DYNAMIC(rx_itr_setting) &&
!ITR_IS_DYNAMIC(tx_itr_setting))) {
goto enable_int;
}
if (ITR_IS_DYNAMIC(rx_itr_setting)) {
rx = i40e_set_new_dynamic_itr(&q_vector->rx);
rxval = i40e_buildreg_itr(I40E_RX_ITR, q_vector->rx.itr);
}
if (ITR_IS_DYNAMIC(tx_itr_setting)) {
tx = i40e_set_new_dynamic_itr(&q_vector->tx);
txval = i40e_buildreg_itr(I40E_TX_ITR, q_vector->tx.itr);
}
if (rx || tx) {
u16 itr = max(q_vector->tx.itr, q_vector->rx.itr);
q_vector->tx.itr = q_vector->rx.itr = itr;
txval = i40e_buildreg_itr(I40E_TX_ITR, itr);
tx = true;
rxval = i40e_buildreg_itr(I40E_RX_ITR, itr);
rx = true;
}
if (rx) {
rxval |= BIT(31);
wr32(hw, INTREG(vector - 1), rxval);
}
enable_int:
if (!test_bit(__I40E_DOWN, &vsi->state))
wr32(hw, INTREG(vector - 1), txval);
if (q_vector->itr_countdown)
q_vector->itr_countdown--;
else
q_vector->itr_countdown = ITR_COUNTDOWN_START;
}
int i40evf_napi_poll(struct napi_struct *napi, int budget)
{
struct i40e_q_vector *q_vector =
container_of(napi, struct i40e_q_vector, napi);
struct i40e_vsi *vsi = q_vector->vsi;
struct i40e_ring *ring;
bool clean_complete = true;
bool arm_wb = false;
int budget_per_ring;
int work_done = 0;
if (test_bit(__I40E_DOWN, &vsi->state)) {
napi_complete(napi);
return 0;
}
i40e_for_each_ring(ring, q_vector->tx) {
if (!i40e_clean_tx_irq(vsi, ring, budget)) {
clean_complete = false;
continue;
}
arm_wb |= ring->arm_wb;
ring->arm_wb = false;
}
if (budget <= 0)
goto tx_only;
budget_per_ring = max(budget/q_vector->num_ringpairs, 1);
i40e_for_each_ring(ring, q_vector->rx) {
int cleaned = i40e_clean_rx_irq(ring, budget_per_ring);
work_done += cleaned;
if (cleaned >= budget_per_ring)
clean_complete = false;
}
if (!clean_complete) {
tx_only:
if (arm_wb) {
q_vector->tx.ring[0].tx_stats.tx_force_wb++;
i40e_enable_wb_on_itr(vsi, q_vector);
}
return budget;
}
if (vsi->back->flags & I40E_TXR_FLAGS_WB_ON_ITR)
q_vector->arm_wb_state = false;
napi_complete_done(napi, work_done);
i40e_update_enable_itr(vsi, q_vector);
return 0;
}
static inline int i40evf_tx_prepare_vlan_flags(struct sk_buff *skb,
struct i40e_ring *tx_ring,
u32 *flags)
{
__be16 protocol = skb->protocol;
u32 tx_flags = 0;
if (protocol == htons(ETH_P_8021Q) &&
!(tx_ring->netdev->features & NETIF_F_HW_VLAN_CTAG_TX)) {
skb->protocol = vlan_get_protocol(skb);
goto out;
}
if (skb_vlan_tag_present(skb)) {
tx_flags |= skb_vlan_tag_get(skb) << I40E_TX_FLAGS_VLAN_SHIFT;
tx_flags |= I40E_TX_FLAGS_HW_VLAN;
} else if (protocol == htons(ETH_P_8021Q)) {
struct vlan_hdr *vhdr, _vhdr;
vhdr = skb_header_pointer(skb, ETH_HLEN, sizeof(_vhdr), &_vhdr);
if (!vhdr)
return -EINVAL;
protocol = vhdr->h_vlan_encapsulated_proto;
tx_flags |= ntohs(vhdr->h_vlan_TCI) << I40E_TX_FLAGS_VLAN_SHIFT;
tx_flags |= I40E_TX_FLAGS_SW_VLAN;
}
out:
*flags = tx_flags;
return 0;
}
static int i40e_tso(struct sk_buff *skb, u8 *hdr_len, u64 *cd_type_cmd_tso_mss)
{
u64 cd_cmd, cd_tso_len, cd_mss;
union {
struct iphdr *v4;
struct ipv6hdr *v6;
unsigned char *hdr;
} ip;
union {
struct tcphdr *tcp;
struct udphdr *udp;
unsigned char *hdr;
} l4;
u32 paylen, l4_offset;
int err;
if (skb->ip_summed != CHECKSUM_PARTIAL)
return 0;
if (!skb_is_gso(skb))
return 0;
err = skb_cow_head(skb, 0);
if (err < 0)
return err;
ip.hdr = skb_network_header(skb);
l4.hdr = skb_transport_header(skb);
if (ip.v4->version == 4) {
ip.v4->tot_len = 0;
ip.v4->check = 0;
} else {
ip.v6->payload_len = 0;
}
if (skb_shinfo(skb)->gso_type & (SKB_GSO_GRE |
SKB_GSO_GRE_CSUM |
SKB_GSO_IPXIP4 |
SKB_GSO_IPXIP6 |
SKB_GSO_UDP_TUNNEL |
SKB_GSO_UDP_TUNNEL_CSUM)) {
if (!(skb_shinfo(skb)->gso_type & SKB_GSO_PARTIAL) &&
(skb_shinfo(skb)->gso_type & SKB_GSO_UDP_TUNNEL_CSUM)) {
l4.udp->len = 0;
l4_offset = l4.hdr - skb->data;
paylen = skb->len - l4_offset;
csum_replace_by_diff(&l4.udp->check, htonl(paylen));
}
ip.hdr = skb_inner_network_header(skb);
l4.hdr = skb_inner_transport_header(skb);
if (ip.v4->version == 4) {
ip.v4->tot_len = 0;
ip.v4->check = 0;
} else {
ip.v6->payload_len = 0;
}
}
l4_offset = l4.hdr - skb->data;
paylen = skb->len - l4_offset;
csum_replace_by_diff(&l4.tcp->check, htonl(paylen));
*hdr_len = (l4.tcp->doff * 4) + l4_offset;
cd_cmd = I40E_TX_CTX_DESC_TSO;
cd_tso_len = skb->len - *hdr_len;
cd_mss = skb_shinfo(skb)->gso_size;
*cd_type_cmd_tso_mss |= (cd_cmd << I40E_TXD_CTX_QW1_CMD_SHIFT) |
(cd_tso_len << I40E_TXD_CTX_QW1_TSO_LEN_SHIFT) |
(cd_mss << I40E_TXD_CTX_QW1_MSS_SHIFT);
return 1;
}
static int i40e_tx_enable_csum(struct sk_buff *skb, u32 *tx_flags,
u32 *td_cmd, u32 *td_offset,
struct i40e_ring *tx_ring,
u32 *cd_tunneling)
{
union {
struct iphdr *v4;
struct ipv6hdr *v6;
unsigned char *hdr;
} ip;
union {
struct tcphdr *tcp;
struct udphdr *udp;
unsigned char *hdr;
} l4;
unsigned char *exthdr;
u32 offset, cmd = 0;
__be16 frag_off;
u8 l4_proto = 0;
if (skb->ip_summed != CHECKSUM_PARTIAL)
return 0;
ip.hdr = skb_network_header(skb);
l4.hdr = skb_transport_header(skb);
offset = ((ip.hdr - skb->data) / 2) << I40E_TX_DESC_LENGTH_MACLEN_SHIFT;
if (skb->encapsulation) {
u32 tunnel = 0;
if (*tx_flags & I40E_TX_FLAGS_IPV4) {
tunnel |= (*tx_flags & I40E_TX_FLAGS_TSO) ?
I40E_TX_CTX_EXT_IP_IPV4 :
I40E_TX_CTX_EXT_IP_IPV4_NO_CSUM;
l4_proto = ip.v4->protocol;
} else if (*tx_flags & I40E_TX_FLAGS_IPV6) {
tunnel |= I40E_TX_CTX_EXT_IP_IPV6;
exthdr = ip.hdr + sizeof(*ip.v6);
l4_proto = ip.v6->nexthdr;
if (l4.hdr != exthdr)
ipv6_skip_exthdr(skb, exthdr - skb->data,
&l4_proto, &frag_off);
}
switch (l4_proto) {
case IPPROTO_UDP:
tunnel |= I40E_TXD_CTX_UDP_TUNNELING;
*tx_flags |= I40E_TX_FLAGS_VXLAN_TUNNEL;
break;
case IPPROTO_GRE:
tunnel |= I40E_TXD_CTX_GRE_TUNNELING;
*tx_flags |= I40E_TX_FLAGS_VXLAN_TUNNEL;
break;
case IPPROTO_IPIP:
case IPPROTO_IPV6:
*tx_flags |= I40E_TX_FLAGS_VXLAN_TUNNEL;
l4.hdr = skb_inner_network_header(skb);
break;
default:
if (*tx_flags & I40E_TX_FLAGS_TSO)
return -1;
skb_checksum_help(skb);
return 0;
}
tunnel |= ((l4.hdr - ip.hdr) / 4) <<
I40E_TXD_CTX_QW0_EXT_IPLEN_SHIFT;
ip.hdr = skb_inner_network_header(skb);
tunnel |= ((ip.hdr - l4.hdr) / 2) <<
I40E_TXD_CTX_QW0_NATLEN_SHIFT;
if ((*tx_flags & I40E_TX_FLAGS_TSO) &&
!(skb_shinfo(skb)->gso_type & SKB_GSO_PARTIAL) &&
(skb_shinfo(skb)->gso_type & SKB_GSO_UDP_TUNNEL_CSUM))
tunnel |= I40E_TXD_CTX_QW0_L4T_CS_MASK;
*cd_tunneling |= tunnel;
l4.hdr = skb_inner_transport_header(skb);
l4_proto = 0;
*tx_flags &= ~(I40E_TX_FLAGS_IPV4 | I40E_TX_FLAGS_IPV6);
if (ip.v4->version == 4)
*tx_flags |= I40E_TX_FLAGS_IPV4;
if (ip.v6->version == 6)
*tx_flags |= I40E_TX_FLAGS_IPV6;
}
if (*tx_flags & I40E_TX_FLAGS_IPV4) {
l4_proto = ip.v4->protocol;
cmd |= (*tx_flags & I40E_TX_FLAGS_TSO) ?
I40E_TX_DESC_CMD_IIPT_IPV4_CSUM :
I40E_TX_DESC_CMD_IIPT_IPV4;
} else if (*tx_flags & I40E_TX_FLAGS_IPV6) {
cmd |= I40E_TX_DESC_CMD_IIPT_IPV6;
exthdr = ip.hdr + sizeof(*ip.v6);
l4_proto = ip.v6->nexthdr;
if (l4.hdr != exthdr)
ipv6_skip_exthdr(skb, exthdr - skb->data,
&l4_proto, &frag_off);
}
offset |= ((l4.hdr - ip.hdr) / 4) << I40E_TX_DESC_LENGTH_IPLEN_SHIFT;
switch (l4_proto) {
case IPPROTO_TCP:
cmd |= I40E_TX_DESC_CMD_L4T_EOFT_TCP;
offset |= l4.tcp->doff << I40E_TX_DESC_LENGTH_L4_FC_LEN_SHIFT;
break;
case IPPROTO_SCTP:
cmd |= I40E_TX_DESC_CMD_L4T_EOFT_SCTP;
offset |= (sizeof(struct sctphdr) >> 2) <<
I40E_TX_DESC_LENGTH_L4_FC_LEN_SHIFT;
break;
case IPPROTO_UDP:
cmd |= I40E_TX_DESC_CMD_L4T_EOFT_UDP;
offset |= (sizeof(struct udphdr) >> 2) <<
I40E_TX_DESC_LENGTH_L4_FC_LEN_SHIFT;
break;
default:
if (*tx_flags & I40E_TX_FLAGS_TSO)
return -1;
skb_checksum_help(skb);
return 0;
}
*td_cmd |= cmd;
*td_offset |= offset;
return 1;
}
static void i40e_create_tx_ctx(struct i40e_ring *tx_ring,
const u64 cd_type_cmd_tso_mss,
const u32 cd_tunneling, const u32 cd_l2tag2)
{
struct i40e_tx_context_desc *context_desc;
int i = tx_ring->next_to_use;
if ((cd_type_cmd_tso_mss == I40E_TX_DESC_DTYPE_CONTEXT) &&
!cd_tunneling && !cd_l2tag2)
return;
context_desc = I40E_TX_CTXTDESC(tx_ring, i);
i++;
tx_ring->next_to_use = (i < tx_ring->count) ? i : 0;
context_desc->tunneling_params = cpu_to_le32(cd_tunneling);
context_desc->l2tag2 = cpu_to_le16(cd_l2tag2);
context_desc->rsvd = cpu_to_le16(0);
context_desc->type_cmd_tso_mss = cpu_to_le64(cd_type_cmd_tso_mss);
}
bool __i40evf_chk_linearize(struct sk_buff *skb)
{
const struct skb_frag_struct *frag, *stale;
int nr_frags, sum;
nr_frags = skb_shinfo(skb)->nr_frags;
if (nr_frags < (I40E_MAX_BUFFER_TXD - 1))
return false;
nr_frags -= I40E_MAX_BUFFER_TXD - 2;
frag = &skb_shinfo(skb)->frags[0];
sum = 1 - skb_shinfo(skb)->gso_size;
sum += skb_frag_size(frag++);
sum += skb_frag_size(frag++);
sum += skb_frag_size(frag++);
sum += skb_frag_size(frag++);
sum += skb_frag_size(frag++);
stale = &skb_shinfo(skb)->frags[0];
for (;;) {
sum += skb_frag_size(frag++);
if (sum < 0)
return true;
if (!nr_frags--)
break;
sum -= skb_frag_size(stale++);
}
return false;
}
int __i40evf_maybe_stop_tx(struct i40e_ring *tx_ring, int size)
{
netif_stop_subqueue(tx_ring->netdev, tx_ring->queue_index);
smp_mb();
if (likely(I40E_DESC_UNUSED(tx_ring) < size))
return -EBUSY;
netif_start_subqueue(tx_ring->netdev, tx_ring->queue_index);
++tx_ring->tx_stats.restart_queue;
return 0;
}
static inline void i40evf_tx_map(struct i40e_ring *tx_ring, struct sk_buff *skb,
struct i40e_tx_buffer *first, u32 tx_flags,
const u8 hdr_len, u32 td_cmd, u32 td_offset)
{
unsigned int data_len = skb->data_len;
unsigned int size = skb_headlen(skb);
struct skb_frag_struct *frag;
struct i40e_tx_buffer *tx_bi;
struct i40e_tx_desc *tx_desc;
u16 i = tx_ring->next_to_use;
u32 td_tag = 0;
dma_addr_t dma;
u16 gso_segs;
u16 desc_count = 0;
bool tail_bump = true;
bool do_rs = false;
if (tx_flags & I40E_TX_FLAGS_HW_VLAN) {
td_cmd |= I40E_TX_DESC_CMD_IL2TAG1;
td_tag = (tx_flags & I40E_TX_FLAGS_VLAN_MASK) >>
I40E_TX_FLAGS_VLAN_SHIFT;
}
if (tx_flags & (I40E_TX_FLAGS_TSO | I40E_TX_FLAGS_FSO))
gso_segs = skb_shinfo(skb)->gso_segs;
else
gso_segs = 1;
first->bytecount = skb->len - hdr_len + (gso_segs * hdr_len);
first->gso_segs = gso_segs;
first->skb = skb;
first->tx_flags = tx_flags;
dma = dma_map_single(tx_ring->dev, skb->data, size, DMA_TO_DEVICE);
tx_desc = I40E_TX_DESC(tx_ring, i);
tx_bi = first;
for (frag = &skb_shinfo(skb)->frags[0];; frag++) {
unsigned int max_data = I40E_MAX_DATA_PER_TXD_ALIGNED;
if (dma_mapping_error(tx_ring->dev, dma))
goto dma_error;
dma_unmap_len_set(tx_bi, len, size);
dma_unmap_addr_set(tx_bi, dma, dma);
max_data += -dma & (I40E_MAX_READ_REQ_SIZE - 1);
tx_desc->buffer_addr = cpu_to_le64(dma);
while (unlikely(size > I40E_MAX_DATA_PER_TXD)) {
tx_desc->cmd_type_offset_bsz =
build_ctob(td_cmd, td_offset,
max_data, td_tag);
tx_desc++;
i++;
desc_count++;
if (i == tx_ring->count) {
tx_desc = I40E_TX_DESC(tx_ring, 0);
i = 0;
}
dma += max_data;
size -= max_data;
max_data = I40E_MAX_DATA_PER_TXD_ALIGNED;
tx_desc->buffer_addr = cpu_to_le64(dma);
}
if (likely(!data_len))
break;
tx_desc->cmd_type_offset_bsz = build_ctob(td_cmd, td_offset,
size, td_tag);
tx_desc++;
i++;
desc_count++;
if (i == tx_ring->count) {
tx_desc = I40E_TX_DESC(tx_ring, 0);
i = 0;
}
size = skb_frag_size(frag);
data_len -= size;
dma = skb_frag_dma_map(tx_ring->dev, frag, 0, size,
DMA_TO_DEVICE);
tx_bi = &tx_ring->tx_bi[i];
}
first->next_to_watch = tx_desc;
i++;
if (i == tx_ring->count)
i = 0;
tx_ring->next_to_use = i;
netdev_tx_sent_queue(txring_txq(tx_ring), first->bytecount);
i40e_maybe_stop_tx(tx_ring, DESC_NEEDED);
if (skb->xmit_more &&
!netif_xmit_stopped(txring_txq(tx_ring))) {
tx_ring->flags |= I40E_TXR_FLAGS_LAST_XMIT_MORE_SET;
tail_bump = false;
} else if (!skb->xmit_more &&
!netif_xmit_stopped(txring_txq(tx_ring)) &&
(!(tx_ring->flags & I40E_TXR_FLAGS_LAST_XMIT_MORE_SET)) &&
(tx_ring->packet_stride < WB_STRIDE) &&
(desc_count < WB_STRIDE)) {
tx_ring->packet_stride++;
} else {
tx_ring->packet_stride = 0;
tx_ring->flags &= ~I40E_TXR_FLAGS_LAST_XMIT_MORE_SET;
do_rs = true;
}
if (do_rs)
tx_ring->packet_stride = 0;
tx_desc->cmd_type_offset_bsz =
build_ctob(td_cmd, td_offset, size, td_tag) |
cpu_to_le64((u64)(do_rs ? I40E_TXD_CMD :
I40E_TX_DESC_CMD_EOP) <<
I40E_TXD_QW1_CMD_SHIFT);
if (!tail_bump) {
prefetchw(tx_desc + 1);
} else {
wmb();
writel(i, tx_ring->tail);
}
return;
dma_error:
dev_info(tx_ring->dev, "TX DMA map failed\n");
for (;;) {
tx_bi = &tx_ring->tx_bi[i];
i40e_unmap_and_free_tx_resource(tx_ring, tx_bi);
if (tx_bi == first)
break;
if (i == 0)
i = tx_ring->count;
i--;
}
tx_ring->next_to_use = i;
}
static netdev_tx_t i40e_xmit_frame_ring(struct sk_buff *skb,
struct i40e_ring *tx_ring)
{
u64 cd_type_cmd_tso_mss = I40E_TX_DESC_DTYPE_CONTEXT;
u32 cd_tunneling = 0, cd_l2tag2 = 0;
struct i40e_tx_buffer *first;
u32 td_offset = 0;
u32 tx_flags = 0;
__be16 protocol;
u32 td_cmd = 0;
u8 hdr_len = 0;
int tso, count;
prefetch(skb->data);
count = i40e_xmit_descriptor_count(skb);
if (i40e_chk_linearize(skb, count)) {
if (__skb_linearize(skb))
goto out_drop;
count = i40e_txd_use_count(skb->len);
tx_ring->tx_stats.tx_linearize++;
}
if (i40e_maybe_stop_tx(tx_ring, count + 4 + 1)) {
tx_ring->tx_stats.tx_busy++;
return NETDEV_TX_BUSY;
}
if (i40evf_tx_prepare_vlan_flags(skb, tx_ring, &tx_flags))
goto out_drop;
protocol = vlan_get_protocol(skb);
first = &tx_ring->tx_bi[tx_ring->next_to_use];
if (protocol == htons(ETH_P_IP))
tx_flags |= I40E_TX_FLAGS_IPV4;
else if (protocol == htons(ETH_P_IPV6))
tx_flags |= I40E_TX_FLAGS_IPV6;
tso = i40e_tso(skb, &hdr_len, &cd_type_cmd_tso_mss);
if (tso < 0)
goto out_drop;
else if (tso)
tx_flags |= I40E_TX_FLAGS_TSO;
tso = i40e_tx_enable_csum(skb, &tx_flags, &td_cmd, &td_offset,
tx_ring, &cd_tunneling);
if (tso < 0)
goto out_drop;
skb_tx_timestamp(skb);
td_cmd |= I40E_TX_DESC_CMD_ICRC;
i40e_create_tx_ctx(tx_ring, cd_type_cmd_tso_mss,
cd_tunneling, cd_l2tag2);
i40evf_tx_map(tx_ring, skb, first, tx_flags, hdr_len,
td_cmd, td_offset);
return NETDEV_TX_OK;
out_drop:
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
}
netdev_tx_t i40evf_xmit_frame(struct sk_buff *skb, struct net_device *netdev)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
struct i40e_ring *tx_ring = &adapter->tx_rings[skb->queue_mapping];
if (unlikely(skb->len < I40E_MIN_TX_LEN)) {
if (skb_pad(skb, I40E_MIN_TX_LEN - skb->len))
return NETDEV_TX_OK;
skb->len = I40E_MIN_TX_LEN;
skb_set_tail_pointer(skb, I40E_MIN_TX_LEN);
}
return i40e_xmit_frame_ring(skb, tx_ring);
}
