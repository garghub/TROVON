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
netdev_tx_reset_queue(netdev_get_tx_queue(tx_ring->netdev,
tx_ring->queue_index));
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
static u32 i40e_get_tx_pending(struct i40e_ring *ring)
{
u32 ntu = ((ring->next_to_clean <= ring->next_to_use)
? ring->next_to_use
: ring->next_to_use + ring->count);
return ntu - ring->next_to_clean;
}
static bool i40e_check_tx_hang(struct i40e_ring *tx_ring)
{
u32 tx_pending = i40e_get_tx_pending(tx_ring);
bool ret = false;
clear_check_for_tx_hang(tx_ring);
if ((tx_ring->tx_stats.tx_done_old == tx_ring->stats.packets) &&
tx_pending) {
ret = test_and_set_bit(__I40E_HANG_CHECK_ARMED,
&tx_ring->state);
} else {
tx_ring->tx_stats.tx_done_old = tx_ring->stats.packets;
clear_bit(__I40E_HANG_CHECK_ARMED, &tx_ring->state);
}
return ret;
}
static inline u32 i40e_get_head(struct i40e_ring *tx_ring)
{
void *head = (struct i40e_tx_desc *)tx_ring->desc + tx_ring->count;
return le32_to_cpu(*(volatile __le32 *)head);
}
static bool i40e_clean_tx_irq(struct i40e_ring *tx_ring, int budget)
{
u16 i = tx_ring->next_to_clean;
struct i40e_tx_buffer *tx_buf;
struct i40e_tx_desc *tx_head;
struct i40e_tx_desc *tx_desc;
unsigned int total_packets = 0;
unsigned int total_bytes = 0;
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
dev_kfree_skb_any(tx_buf->skb);
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
if (check_for_tx_hang(tx_ring) && i40e_check_tx_hang(tx_ring)) {
dev_info(tx_ring->dev, "Detected Tx Unit Hang\n"
" VSI <%d>\n"
" Tx Queue <%d>\n"
" next_to_use <%x>\n"
" next_to_clean <%x>\n",
tx_ring->vsi->seid,
tx_ring->queue_index,
tx_ring->next_to_use, i);
dev_info(tx_ring->dev, "tx_bi[next_to_clean]\n"
" time_stamp <%lx>\n"
" jiffies <%lx>\n",
tx_ring->tx_bi[i].time_stamp, jiffies);
netif_stop_subqueue(tx_ring->netdev, tx_ring->queue_index);
dev_info(tx_ring->dev,
"tx hang detected on queue %d, resetting adapter\n",
tx_ring->queue_index);
tx_ring->netdev->netdev_ops->ndo_tx_timeout(tx_ring->netdev);
return true;
}
netdev_tx_completed_queue(netdev_get_tx_queue(tx_ring->netdev,
tx_ring->queue_index),
total_packets, total_bytes);
#define TX_WAKE_THRESHOLD (DESC_NEEDED * 2)
if (unlikely(total_packets && netif_carrier_ok(tx_ring->netdev) &&
(I40E_DESC_UNUSED(tx_ring) >= TX_WAKE_THRESHOLD))) {
smp_mb();
if (__netif_subqueue_stopped(tx_ring->netdev,
tx_ring->queue_index) &&
!test_bit(__I40E_DOWN, &tx_ring->vsi->state)) {
netif_wake_subqueue(tx_ring->netdev,
tx_ring->queue_index);
++tx_ring->tx_stats.restart_queue;
}
}
return budget > 0;
}
static void i40e_set_new_dynamic_itr(struct i40e_ring_container *rc)
{
enum i40e_latency_range new_latency_range = rc->latency_range;
u32 new_itr = rc->itr;
int bytes_per_int;
if (rc->total_packets == 0 || !rc->itr)
return;
bytes_per_int = rc->total_bytes / rc->itr;
switch (rc->itr) {
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
if (bytes_per_int <= 20)
rc->latency_range = I40E_LOW_LATENCY;
break;
}
switch (new_latency_range) {
case I40E_LOWEST_LATENCY:
new_itr = I40E_ITR_100K;
break;
case I40E_LOW_LATENCY:
new_itr = I40E_ITR_20K;
break;
case I40E_BULK_LATENCY:
new_itr = I40E_ITR_8K;
break;
default:
break;
}
if (new_itr != rc->itr) {
new_itr = (10 * new_itr * rc->itr) /
((9 * new_itr) + rc->itr);
rc->itr = new_itr & I40E_MAX_ITR;
}
rc->total_bytes = 0;
rc->total_packets = 0;
}
static void i40e_update_dynamic_itr(struct i40e_q_vector *q_vector)
{
u16 vector = q_vector->vsi->base_vector + q_vector->v_idx;
struct i40e_hw *hw = &q_vector->vsi->back->hw;
u32 reg_addr;
u16 old_itr;
reg_addr = I40E_VFINT_ITRN1(I40E_RX_ITR, vector - 1);
old_itr = q_vector->rx.itr;
i40e_set_new_dynamic_itr(&q_vector->rx);
if (old_itr != q_vector->rx.itr)
wr32(hw, reg_addr, q_vector->rx.itr);
reg_addr = I40E_VFINT_ITRN1(I40E_TX_ITR, vector - 1);
old_itr = q_vector->tx.itr;
i40e_set_new_dynamic_itr(&q_vector->tx);
if (old_itr != q_vector->tx.itr)
wr32(hw, reg_addr, q_vector->tx.itr);
}
int i40evf_setup_tx_descriptors(struct i40e_ring *tx_ring)
{
struct device *dev = tx_ring->dev;
int bi_size;
if (!dev)
return -ENOMEM;
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
struct i40e_rx_buffer *rx_bi;
unsigned long bi_size;
u16 i;
if (!rx_ring->rx_bi)
return;
for (i = 0; i < rx_ring->count; i++) {
rx_bi = &rx_ring->rx_bi[i];
if (rx_bi->dma) {
dma_unmap_single(dev,
rx_bi->dma,
rx_ring->rx_buf_len,
DMA_FROM_DEVICE);
rx_bi->dma = 0;
}
if (rx_bi->skb) {
dev_kfree_skb(rx_bi->skb);
rx_bi->skb = NULL;
}
if (rx_bi->page) {
if (rx_bi->page_dma) {
dma_unmap_page(dev,
rx_bi->page_dma,
PAGE_SIZE / 2,
DMA_FROM_DEVICE);
rx_bi->page_dma = 0;
}
__free_page(rx_bi->page);
rx_bi->page = NULL;
rx_bi->page_offset = 0;
}
}
bi_size = sizeof(struct i40e_rx_buffer) * rx_ring->count;
memset(rx_ring->rx_bi, 0, bi_size);
memset(rx_ring->desc, 0, rx_ring->size);
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
bi_size = sizeof(struct i40e_rx_buffer) * rx_ring->count;
rx_ring->rx_bi = kzalloc(bi_size, GFP_KERNEL);
if (!rx_ring->rx_bi)
goto err;
rx_ring->size = ring_is_16byte_desc_enabled(rx_ring)
? rx_ring->count * sizeof(union i40e_16byte_rx_desc)
: rx_ring->count * sizeof(union i40e_32byte_rx_desc);
rx_ring->size = ALIGN(rx_ring->size, 4096);
rx_ring->desc = dma_alloc_coherent(dev, rx_ring->size,
&rx_ring->dma, GFP_KERNEL);
if (!rx_ring->desc) {
dev_info(dev, "Unable to allocate memory for the Rx descriptor ring, size=%d\n",
rx_ring->size);
goto err;
}
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
wmb();
writel(val, rx_ring->tail);
}
void i40evf_alloc_rx_buffers(struct i40e_ring *rx_ring, u16 cleaned_count)
{
u16 i = rx_ring->next_to_use;
union i40e_rx_desc *rx_desc;
struct i40e_rx_buffer *bi;
struct sk_buff *skb;
if (!rx_ring->netdev || !cleaned_count)
return;
while (cleaned_count--) {
rx_desc = I40E_RX_DESC(rx_ring, i);
bi = &rx_ring->rx_bi[i];
skb = bi->skb;
if (!skb) {
skb = netdev_alloc_skb_ip_align(rx_ring->netdev,
rx_ring->rx_buf_len);
if (!skb) {
rx_ring->rx_stats.alloc_buff_failed++;
goto no_buffers;
}
skb_record_rx_queue(skb, rx_ring->queue_index);
bi->skb = skb;
}
if (!bi->dma) {
bi->dma = dma_map_single(rx_ring->dev,
skb->data,
rx_ring->rx_buf_len,
DMA_FROM_DEVICE);
if (dma_mapping_error(rx_ring->dev, bi->dma)) {
rx_ring->rx_stats.alloc_buff_failed++;
bi->dma = 0;
goto no_buffers;
}
}
if (ring_is_ps_enabled(rx_ring)) {
if (!bi->page) {
bi->page = alloc_page(GFP_ATOMIC);
if (!bi->page) {
rx_ring->rx_stats.alloc_page_failed++;
goto no_buffers;
}
}
if (!bi->page_dma) {
bi->page_offset ^= PAGE_SIZE / 2;
bi->page_dma = dma_map_page(rx_ring->dev,
bi->page,
bi->page_offset,
PAGE_SIZE / 2,
DMA_FROM_DEVICE);
if (dma_mapping_error(rx_ring->dev,
bi->page_dma)) {
rx_ring->rx_stats.alloc_page_failed++;
bi->page_dma = 0;
goto no_buffers;
}
}
rx_desc->read.pkt_addr = cpu_to_le64(bi->page_dma);
rx_desc->read.hdr_addr = cpu_to_le64(bi->dma);
} else {
rx_desc->read.pkt_addr = cpu_to_le64(bi->dma);
rx_desc->read.hdr_addr = 0;
}
i++;
if (i == rx_ring->count)
i = 0;
}
no_buffers:
if (rx_ring->next_to_use != i)
i40e_release_rx_desc(rx_ring, i);
}
static void i40e_receive_skb(struct i40e_ring *rx_ring,
struct sk_buff *skb, u16 vlan_tag)
{
struct i40e_q_vector *q_vector = rx_ring->q_vector;
struct i40e_vsi *vsi = rx_ring->vsi;
u64 flags = vsi->back->flags;
if (vlan_tag & VLAN_VID_MASK)
__vlan_hwaccel_put_tag(skb, htons(ETH_P_8021Q), vlan_tag);
if (flags & I40E_FLAG_IN_NETPOLL)
netif_rx(skb);
else
napi_gro_receive(&q_vector->napi, skb);
}
static inline void i40e_rx_checksum(struct i40e_vsi *vsi,
struct sk_buff *skb,
u32 rx_status,
u32 rx_error,
u16 rx_ptype)
{
bool ipv4_tunnel, ipv6_tunnel;
__wsum rx_udp_csum;
__sum16 csum;
struct iphdr *iph;
ipv4_tunnel = (rx_ptype > I40E_RX_PTYPE_GRENAT4_MAC_PAY3) &&
(rx_ptype < I40E_RX_PTYPE_GRENAT4_MACVLAN_IPV6_ICMP_PAY4);
ipv6_tunnel = (rx_ptype > I40E_RX_PTYPE_GRENAT6_MAC_PAY3) &&
(rx_ptype < I40E_RX_PTYPE_GRENAT6_MACVLAN_IPV6_ICMP_PAY4);
skb->encapsulation = ipv4_tunnel || ipv6_tunnel;
skb->ip_summed = CHECKSUM_NONE;
if (!(vsi->netdev->features & NETIF_F_RXCSUM &&
rx_status & (1 << I40E_RX_DESC_STATUS_L3L4P_SHIFT)))
return;
if (rx_status & (1 << I40E_RX_DESC_STATUS_IPV6EXADD_SHIFT))
return;
if (rx_error & ((1 << I40E_RX_DESC_ERROR_IPE_SHIFT) |
(1 << I40E_RX_DESC_ERROR_L4E_SHIFT) |
(1 << I40E_RX_DESC_ERROR_EIPE_SHIFT))) {
vsi->back->hw_csum_rx_error++;
return;
}
if (ipv4_tunnel &&
!(rx_status & (1 << I40E_RX_DESC_STATUS_UDP_0_SHIFT))) {
skb->transport_header = skb->mac_header +
sizeof(struct ethhdr) +
(ip_hdr(skb)->ihl * 4);
skb->transport_header += (skb->protocol == htons(ETH_P_8021Q) ||
skb->protocol == htons(ETH_P_8021AD))
? VLAN_HLEN : 0;
rx_udp_csum = udp_csum(skb);
iph = ip_hdr(skb);
csum = csum_tcpudp_magic(
iph->saddr, iph->daddr,
(skb->len - skb_transport_offset(skb)),
IPPROTO_UDP, rx_udp_csum);
if (udp_hdr(skb)->check != csum) {
vsi->back->hw_csum_rx_error++;
return;
}
}
skb->ip_summed = CHECKSUM_UNNECESSARY;
}
static inline u32 i40e_rx_hash(struct i40e_ring *ring,
union i40e_rx_desc *rx_desc)
{
const __le64 rss_mask =
cpu_to_le64((u64)I40E_RX_DESC_FLTSTAT_RSS_HASH <<
I40E_RX_DESC_STATUS_FLTSTAT_SHIFT);
if ((ring->netdev->features & NETIF_F_RXHASH) &&
(rx_desc->wb.qword1.status_error_len & rss_mask) == rss_mask)
return le32_to_cpu(rx_desc->wb.qword0.hi_dword.rss);
else
return 0;
}
static inline enum pkt_hash_types i40e_ptype_to_hash(u8 ptype)
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
static int i40e_clean_rx_irq(struct i40e_ring *rx_ring, int budget)
{
unsigned int total_rx_bytes = 0, total_rx_packets = 0;
u16 rx_packet_len, rx_header_len, rx_sph, rx_hbo;
u16 cleaned_count = I40E_DESC_UNUSED(rx_ring);
const int current_node = numa_node_id();
struct i40e_vsi *vsi = rx_ring->vsi;
u16 i = rx_ring->next_to_clean;
union i40e_rx_desc *rx_desc;
u32 rx_error, rx_status;
u8 rx_ptype;
u64 qword;
rx_desc = I40E_RX_DESC(rx_ring, i);
qword = le64_to_cpu(rx_desc->wb.qword1.status_error_len);
rx_status = (qword & I40E_RXD_QW1_STATUS_MASK) >>
I40E_RXD_QW1_STATUS_SHIFT;
while (rx_status & (1 << I40E_RX_DESC_STATUS_DD_SHIFT)) {
union i40e_rx_desc *next_rxd;
struct i40e_rx_buffer *rx_bi;
struct sk_buff *skb;
u16 vlan_tag;
rx_bi = &rx_ring->rx_bi[i];
skb = rx_bi->skb;
prefetch(skb->data);
rx_packet_len = (qword & I40E_RXD_QW1_LENGTH_PBUF_MASK) >>
I40E_RXD_QW1_LENGTH_PBUF_SHIFT;
rx_header_len = (qword & I40E_RXD_QW1_LENGTH_HBUF_MASK) >>
I40E_RXD_QW1_LENGTH_HBUF_SHIFT;
rx_sph = (qword & I40E_RXD_QW1_LENGTH_SPH_MASK) >>
I40E_RXD_QW1_LENGTH_SPH_SHIFT;
rx_error = (qword & I40E_RXD_QW1_ERROR_MASK) >>
I40E_RXD_QW1_ERROR_SHIFT;
rx_hbo = rx_error & (1 << I40E_RX_DESC_ERROR_HBO_SHIFT);
rx_error &= ~(1 << I40E_RX_DESC_ERROR_HBO_SHIFT);
rx_ptype = (qword & I40E_RXD_QW1_PTYPE_MASK) >>
I40E_RXD_QW1_PTYPE_SHIFT;
rx_bi->skb = NULL;
rmb();
if (rx_bi->dma) {
u16 len;
if (rx_hbo)
len = I40E_RX_HDR_SIZE;
else if (rx_sph)
len = rx_header_len;
else if (rx_packet_len)
len = rx_packet_len;
else
len = rx_header_len;
skb_put(skb, len);
dma_unmap_single(rx_ring->dev,
rx_bi->dma,
rx_ring->rx_buf_len,
DMA_FROM_DEVICE);
rx_bi->dma = 0;
}
if (ring_is_ps_enabled(rx_ring) && rx_packet_len) {
skb_fill_page_desc(skb, skb_shinfo(skb)->nr_frags,
rx_bi->page,
rx_bi->page_offset,
rx_packet_len);
skb->len += rx_packet_len;
skb->data_len += rx_packet_len;
skb->truesize += rx_packet_len;
if ((page_count(rx_bi->page) == 1) &&
(page_to_nid(rx_bi->page) == current_node))
get_page(rx_bi->page);
else
rx_bi->page = NULL;
dma_unmap_page(rx_ring->dev,
rx_bi->page_dma,
PAGE_SIZE / 2,
DMA_FROM_DEVICE);
rx_bi->page_dma = 0;
}
I40E_RX_NEXT_DESC_PREFETCH(rx_ring, i, next_rxd);
if (unlikely(
!(rx_status & (1 << I40E_RX_DESC_STATUS_EOF_SHIFT)))) {
struct i40e_rx_buffer *next_buffer;
next_buffer = &rx_ring->rx_bi[i];
if (ring_is_ps_enabled(rx_ring)) {
rx_bi->skb = next_buffer->skb;
rx_bi->dma = next_buffer->dma;
next_buffer->skb = skb;
next_buffer->dma = 0;
}
rx_ring->rx_stats.non_eop_descs++;
goto next_desc;
}
if (unlikely(rx_error & (1 << I40E_RX_DESC_ERROR_RXE_SHIFT))) {
dev_kfree_skb_any(skb);
goto next_desc;
}
skb_set_hash(skb, i40e_rx_hash(rx_ring, rx_desc),
i40e_ptype_to_hash(rx_ptype));
total_rx_bytes += skb->len;
total_rx_packets++;
skb->protocol = eth_type_trans(skb, rx_ring->netdev);
i40e_rx_checksum(vsi, skb, rx_status, rx_error, rx_ptype);
vlan_tag = rx_status & (1 << I40E_RX_DESC_STATUS_L2TAG1P_SHIFT)
? le16_to_cpu(rx_desc->wb.qword0.lo_dword.l2tag1)
: 0;
i40e_receive_skb(rx_ring, skb, vlan_tag);
rx_ring->netdev->last_rx = jiffies;
budget--;
next_desc:
rx_desc->wb.qword1.status_error_len = 0;
if (!budget)
break;
cleaned_count++;
if (cleaned_count >= I40E_RX_BUFFER_WRITE) {
i40evf_alloc_rx_buffers(rx_ring, cleaned_count);
cleaned_count = 0;
}
rx_desc = next_rxd;
qword = le64_to_cpu(rx_desc->wb.qword1.status_error_len);
rx_status = (qword & I40E_RXD_QW1_STATUS_MASK) >>
I40E_RXD_QW1_STATUS_SHIFT;
}
rx_ring->next_to_clean = i;
u64_stats_update_begin(&rx_ring->syncp);
rx_ring->stats.packets += total_rx_packets;
rx_ring->stats.bytes += total_rx_bytes;
u64_stats_update_end(&rx_ring->syncp);
rx_ring->q_vector->rx.total_packets += total_rx_packets;
rx_ring->q_vector->rx.total_bytes += total_rx_bytes;
if (cleaned_count)
i40evf_alloc_rx_buffers(rx_ring, cleaned_count);
return budget > 0;
}
int i40evf_napi_poll(struct napi_struct *napi, int budget)
{
struct i40e_q_vector *q_vector =
container_of(napi, struct i40e_q_vector, napi);
struct i40e_vsi *vsi = q_vector->vsi;
struct i40e_ring *ring;
bool clean_complete = true;
int budget_per_ring;
if (test_bit(__I40E_DOWN, &vsi->state)) {
napi_complete(napi);
return 0;
}
i40e_for_each_ring(ring, q_vector->tx)
clean_complete &= i40e_clean_tx_irq(ring, vsi->work_limit);
budget_per_ring = max(budget/q_vector->num_ringpairs, 1);
i40e_for_each_ring(ring, q_vector->rx)
clean_complete &= i40e_clean_rx_irq(ring, budget_per_ring);
if (!clean_complete)
return budget;
napi_complete(napi);
if (ITR_IS_DYNAMIC(vsi->rx_itr_setting) ||
ITR_IS_DYNAMIC(vsi->tx_itr_setting))
i40e_update_dynamic_itr(q_vector);
if (!test_bit(__I40E_DOWN, &vsi->state))
i40evf_irq_enable_queues(vsi->back, 1 << q_vector->v_idx);
return 0;
}
static int i40e_tx_prepare_vlan_flags(struct sk_buff *skb,
struct i40e_ring *tx_ring,
u32 *flags)
{
__be16 protocol = skb->protocol;
u32 tx_flags = 0;
if (vlan_tx_tag_present(skb)) {
tx_flags |= vlan_tx_tag_get(skb) << I40E_TX_FLAGS_VLAN_SHIFT;
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
*flags = tx_flags;
return 0;
}
static int i40e_tso(struct i40e_ring *tx_ring, struct sk_buff *skb,
u32 tx_flags, __be16 protocol, u8 *hdr_len,
u64 *cd_type_cmd_tso_mss, u32 *cd_tunneling)
{
u32 cd_cmd, cd_tso_len, cd_mss;
struct ipv6hdr *ipv6h;
struct tcphdr *tcph;
struct iphdr *iph;
u32 l4len;
int err;
if (!skb_is_gso(skb))
return 0;
err = skb_cow_head(skb, 0);
if (err < 0)
return err;
if (protocol == htons(ETH_P_IP)) {
iph = skb->encapsulation ? inner_ip_hdr(skb) : ip_hdr(skb);
tcph = skb->encapsulation ? inner_tcp_hdr(skb) : tcp_hdr(skb);
iph->tot_len = 0;
iph->check = 0;
tcph->check = ~csum_tcpudp_magic(iph->saddr, iph->daddr,
0, IPPROTO_TCP, 0);
} else if (skb_is_gso_v6(skb)) {
ipv6h = skb->encapsulation ? inner_ipv6_hdr(skb)
: ipv6_hdr(skb);
tcph = skb->encapsulation ? inner_tcp_hdr(skb) : tcp_hdr(skb);
ipv6h->payload_len = 0;
tcph->check = ~csum_ipv6_magic(&ipv6h->saddr, &ipv6h->daddr,
0, IPPROTO_TCP, 0);
}
l4len = skb->encapsulation ? inner_tcp_hdrlen(skb) : tcp_hdrlen(skb);
*hdr_len = (skb->encapsulation
? (skb_inner_transport_header(skb) - skb->data)
: skb_transport_offset(skb)) + l4len;
cd_cmd = I40E_TX_CTX_DESC_TSO;
cd_tso_len = skb->len - *hdr_len;
cd_mss = skb_shinfo(skb)->gso_size;
*cd_type_cmd_tso_mss |= ((u64)cd_cmd << I40E_TXD_CTX_QW1_CMD_SHIFT) |
((u64)cd_tso_len <<
I40E_TXD_CTX_QW1_TSO_LEN_SHIFT) |
((u64)cd_mss << I40E_TXD_CTX_QW1_MSS_SHIFT);
return 1;
}
static void i40e_tx_enable_csum(struct sk_buff *skb, u32 tx_flags,
u32 *td_cmd, u32 *td_offset,
struct i40e_ring *tx_ring,
u32 *cd_tunneling)
{
struct ipv6hdr *this_ipv6_hdr;
unsigned int this_tcp_hdrlen;
struct iphdr *this_ip_hdr;
u32 network_hdr_len;
u8 l4_hdr = 0;
if (skb->encapsulation) {
network_hdr_len = skb_inner_network_header_len(skb);
this_ip_hdr = inner_ip_hdr(skb);
this_ipv6_hdr = inner_ipv6_hdr(skb);
this_tcp_hdrlen = inner_tcp_hdrlen(skb);
if (tx_flags & I40E_TX_FLAGS_IPV4) {
if (tx_flags & I40E_TX_FLAGS_TSO) {
*cd_tunneling |= I40E_TX_CTX_EXT_IP_IPV4;
ip_hdr(skb)->check = 0;
} else {
*cd_tunneling |=
I40E_TX_CTX_EXT_IP_IPV4_NO_CSUM;
}
} else if (tx_flags & I40E_TX_FLAGS_IPV6) {
if (tx_flags & I40E_TX_FLAGS_TSO) {
*cd_tunneling |= I40E_TX_CTX_EXT_IP_IPV6;
ip_hdr(skb)->check = 0;
} else {
*cd_tunneling |=
I40E_TX_CTX_EXT_IP_IPV4_NO_CSUM;
}
}
*cd_tunneling |= (skb_network_header_len(skb) >> 2) <<
I40E_TXD_CTX_QW0_EXT_IPLEN_SHIFT |
I40E_TXD_CTX_UDP_TUNNELING |
((skb_inner_network_offset(skb) -
skb_transport_offset(skb)) >> 1) <<
I40E_TXD_CTX_QW0_NATLEN_SHIFT;
} else {
network_hdr_len = skb_network_header_len(skb);
this_ip_hdr = ip_hdr(skb);
this_ipv6_hdr = ipv6_hdr(skb);
this_tcp_hdrlen = tcp_hdrlen(skb);
}
if (tx_flags & I40E_TX_FLAGS_IPV4) {
l4_hdr = this_ip_hdr->protocol;
if (tx_flags & I40E_TX_FLAGS_TSO) {
*td_cmd |= I40E_TX_DESC_CMD_IIPT_IPV4_CSUM;
this_ip_hdr->check = 0;
} else {
*td_cmd |= I40E_TX_DESC_CMD_IIPT_IPV4;
}
*td_offset = (network_hdr_len >> 2) <<
I40E_TX_DESC_LENGTH_IPLEN_SHIFT;
} else if (tx_flags & I40E_TX_FLAGS_IPV6) {
l4_hdr = this_ipv6_hdr->nexthdr;
*td_cmd |= I40E_TX_DESC_CMD_IIPT_IPV6;
*td_offset = (network_hdr_len >> 2) <<
I40E_TX_DESC_LENGTH_IPLEN_SHIFT;
}
*td_offset |= (skb_network_offset(skb) >> 1) <<
I40E_TX_DESC_LENGTH_MACLEN_SHIFT;
switch (l4_hdr) {
case IPPROTO_TCP:
*td_cmd |= I40E_TX_DESC_CMD_L4T_EOFT_TCP;
*td_offset |= (this_tcp_hdrlen >> 2) <<
I40E_TX_DESC_LENGTH_L4_FC_LEN_SHIFT;
break;
case IPPROTO_SCTP:
*td_cmd |= I40E_TX_DESC_CMD_L4T_EOFT_SCTP;
*td_offset |= (sizeof(struct sctphdr) >> 2) <<
I40E_TX_DESC_LENGTH_L4_FC_LEN_SHIFT;
break;
case IPPROTO_UDP:
*td_cmd |= I40E_TX_DESC_CMD_L4T_EOFT_UDP;
*td_offset |= (sizeof(struct udphdr) >> 2) <<
I40E_TX_DESC_LENGTH_L4_FC_LEN_SHIFT;
break;
default:
break;
}
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
context_desc->type_cmd_tso_mss = cpu_to_le64(cd_type_cmd_tso_mss);
}
static void i40e_tx_map(struct i40e_ring *tx_ring, struct sk_buff *skb,
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
if (dma_mapping_error(tx_ring->dev, dma))
goto dma_error;
dma_unmap_len_set(tx_bi, len, size);
dma_unmap_addr_set(tx_bi, dma, dma);
tx_desc->buffer_addr = cpu_to_le64(dma);
while (unlikely(size > I40E_MAX_DATA_PER_TXD)) {
tx_desc->cmd_type_offset_bsz =
build_ctob(td_cmd, td_offset,
I40E_MAX_DATA_PER_TXD, td_tag);
tx_desc++;
i++;
if (i == tx_ring->count) {
tx_desc = I40E_TX_DESC(tx_ring, 0);
i = 0;
}
dma += I40E_MAX_DATA_PER_TXD;
size -= I40E_MAX_DATA_PER_TXD;
tx_desc->buffer_addr = cpu_to_le64(dma);
}
if (likely(!data_len))
break;
tx_desc->cmd_type_offset_bsz = build_ctob(td_cmd, td_offset,
size, td_tag);
tx_desc++;
i++;
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
#define WB_STRIDE 0x3
if (((i & WB_STRIDE) != WB_STRIDE) &&
(first <= &tx_ring->tx_bi[i]) &&
(first >= &tx_ring->tx_bi[i & ~WB_STRIDE])) {
tx_desc->cmd_type_offset_bsz =
build_ctob(td_cmd, td_offset, size, td_tag) |
cpu_to_le64((u64)I40E_TX_DESC_CMD_EOP <<
I40E_TXD_QW1_CMD_SHIFT);
} else {
tx_desc->cmd_type_offset_bsz =
build_ctob(td_cmd, td_offset, size, td_tag) |
cpu_to_le64((u64)I40E_TXD_CMD <<
I40E_TXD_QW1_CMD_SHIFT);
}
netdev_tx_sent_queue(netdev_get_tx_queue(tx_ring->netdev,
tx_ring->queue_index),
first->bytecount);
first->time_stamp = jiffies;
wmb();
first->next_to_watch = tx_desc;
i++;
if (i == tx_ring->count)
i = 0;
tx_ring->next_to_use = i;
writel(i, tx_ring->tail);
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
static inline int __i40e_maybe_stop_tx(struct i40e_ring *tx_ring, int size)
{
netif_stop_subqueue(tx_ring->netdev, tx_ring->queue_index);
smp_mb();
if (likely(I40E_DESC_UNUSED(tx_ring) < size))
return -EBUSY;
netif_start_subqueue(tx_ring->netdev, tx_ring->queue_index);
++tx_ring->tx_stats.restart_queue;
return 0;
}
static int i40e_maybe_stop_tx(struct i40e_ring *tx_ring, int size)
{
if (likely(I40E_DESC_UNUSED(tx_ring) >= size))
return 0;
return __i40e_maybe_stop_tx(tx_ring, size);
}
static int i40e_xmit_descriptor_count(struct sk_buff *skb,
struct i40e_ring *tx_ring)
{
#if PAGE_SIZE > I40E_MAX_DATA_PER_TXD
unsigned int f;
#endif
int count = 0;
#if PAGE_SIZE > I40E_MAX_DATA_PER_TXD
for (f = 0; f < skb_shinfo(skb)->nr_frags; f++)
count += TXD_USE_COUNT(skb_shinfo(skb)->frags[f].size);
#else
count += skb_shinfo(skb)->nr_frags;
#endif
count += TXD_USE_COUNT(skb_headlen(skb));
if (i40e_maybe_stop_tx(tx_ring, count + 4 + 1)) {
tx_ring->tx_stats.tx_busy++;
return 0;
}
return count;
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
int tso;
if (0 == i40e_xmit_descriptor_count(skb, tx_ring))
return NETDEV_TX_BUSY;
if (i40e_tx_prepare_vlan_flags(skb, tx_ring, &tx_flags))
goto out_drop;
protocol = skb->protocol;
first = &tx_ring->tx_bi[tx_ring->next_to_use];
if (protocol == htons(ETH_P_IP))
tx_flags |= I40E_TX_FLAGS_IPV4;
else if (protocol == htons(ETH_P_IPV6))
tx_flags |= I40E_TX_FLAGS_IPV6;
tso = i40e_tso(tx_ring, skb, tx_flags, protocol, &hdr_len,
&cd_type_cmd_tso_mss, &cd_tunneling);
if (tso < 0)
goto out_drop;
else if (tso)
tx_flags |= I40E_TX_FLAGS_TSO;
skb_tx_timestamp(skb);
td_cmd |= I40E_TX_DESC_CMD_ICRC;
if (skb->ip_summed == CHECKSUM_PARTIAL) {
tx_flags |= I40E_TX_FLAGS_CSUM;
i40e_tx_enable_csum(skb, tx_flags, &td_cmd, &td_offset,
tx_ring, &cd_tunneling);
}
i40e_create_tx_ctx(tx_ring, cd_type_cmd_tso_mss,
cd_tunneling, cd_l2tag2);
i40e_tx_map(tx_ring, skb, first, tx_flags, hdr_len,
td_cmd, td_offset);
i40e_maybe_stop_tx(tx_ring, DESC_NEEDED);
return NETDEV_TX_OK;
out_drop:
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
}
netdev_tx_t i40evf_xmit_frame(struct sk_buff *skb, struct net_device *netdev)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
struct i40e_ring *tx_ring = adapter->tx_rings[skb->queue_mapping];
if (unlikely(skb->len < I40E_MIN_TX_LEN)) {
if (skb_pad(skb, I40E_MIN_TX_LEN - skb->len))
return NETDEV_TX_OK;
skb->len = I40E_MIN_TX_LEN;
skb_set_tail_pointer(skb, I40E_MIN_TX_LEN);
}
return i40e_xmit_frame_ring(skb, tx_ring);
}
