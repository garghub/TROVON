static int __init fm10k_init_module(void)
{
pr_info("%s - version %s\n", fm10k_driver_string, fm10k_driver_version);
pr_info("%s\n", fm10k_copyright);
fm10k_workqueue = create_workqueue("fm10k");
fm10k_dbg_init();
return fm10k_register_pci_driver();
}
static void __exit fm10k_exit_module(void)
{
fm10k_unregister_pci_driver();
fm10k_dbg_exit();
flush_workqueue(fm10k_workqueue);
destroy_workqueue(fm10k_workqueue);
}
static bool fm10k_alloc_mapped_page(struct fm10k_ring *rx_ring,
struct fm10k_rx_buffer *bi)
{
struct page *page = bi->page;
dma_addr_t dma;
if (likely(page))
return true;
page = dev_alloc_page();
if (unlikely(!page)) {
rx_ring->rx_stats.alloc_failed++;
return false;
}
dma = dma_map_page(rx_ring->dev, page, 0, PAGE_SIZE, DMA_FROM_DEVICE);
if (dma_mapping_error(rx_ring->dev, dma)) {
__free_page(page);
rx_ring->rx_stats.alloc_failed++;
return false;
}
bi->dma = dma;
bi->page = page;
bi->page_offset = 0;
return true;
}
void fm10k_alloc_rx_buffers(struct fm10k_ring *rx_ring, u16 cleaned_count)
{
union fm10k_rx_desc *rx_desc;
struct fm10k_rx_buffer *bi;
u16 i = rx_ring->next_to_use;
if (!cleaned_count)
return;
rx_desc = FM10K_RX_DESC(rx_ring, i);
bi = &rx_ring->rx_buffer[i];
i -= rx_ring->count;
do {
if (!fm10k_alloc_mapped_page(rx_ring, bi))
break;
rx_desc->q.pkt_addr = cpu_to_le64(bi->dma + bi->page_offset);
rx_desc++;
bi++;
i++;
if (unlikely(!i)) {
rx_desc = FM10K_RX_DESC(rx_ring, 0);
bi = rx_ring->rx_buffer;
i -= rx_ring->count;
}
rx_desc->d.staterr = 0;
cleaned_count--;
} while (cleaned_count);
i += rx_ring->count;
if (rx_ring->next_to_use != i) {
rx_ring->next_to_use = i;
rx_ring->next_to_alloc = i;
wmb();
writel(i, rx_ring->tail);
}
}
static void fm10k_reuse_rx_page(struct fm10k_ring *rx_ring,
struct fm10k_rx_buffer *old_buff)
{
struct fm10k_rx_buffer *new_buff;
u16 nta = rx_ring->next_to_alloc;
new_buff = &rx_ring->rx_buffer[nta];
nta++;
rx_ring->next_to_alloc = (nta < rx_ring->count) ? nta : 0;
*new_buff = *old_buff;
dma_sync_single_range_for_device(rx_ring->dev, old_buff->dma,
old_buff->page_offset,
FM10K_RX_BUFSZ,
DMA_FROM_DEVICE);
}
static inline bool fm10k_page_is_reserved(struct page *page)
{
return (page_to_nid(page) != numa_mem_id()) || page_is_pfmemalloc(page);
}
static bool fm10k_can_reuse_rx_page(struct fm10k_rx_buffer *rx_buffer,
struct page *page,
unsigned int __maybe_unused truesize)
{
if (unlikely(fm10k_page_is_reserved(page)))
return false;
#if (PAGE_SIZE < 8192)
if (unlikely(page_count(page) != 1))
return false;
rx_buffer->page_offset ^= FM10K_RX_BUFSZ;
#else
rx_buffer->page_offset += truesize;
if (rx_buffer->page_offset > (PAGE_SIZE - FM10K_RX_BUFSZ))
return false;
#endif
page_ref_inc(page);
return true;
}
static bool fm10k_add_rx_frag(struct fm10k_rx_buffer *rx_buffer,
union fm10k_rx_desc *rx_desc,
struct sk_buff *skb)
{
struct page *page = rx_buffer->page;
unsigned char *va = page_address(page) + rx_buffer->page_offset;
unsigned int size = le16_to_cpu(rx_desc->w.length);
#if (PAGE_SIZE < 8192)
unsigned int truesize = FM10K_RX_BUFSZ;
#else
unsigned int truesize = SKB_DATA_ALIGN(size);
#endif
unsigned int pull_len;
if (unlikely(skb_is_nonlinear(skb)))
goto add_tail_frag;
if (likely(size <= FM10K_RX_HDR_LEN)) {
memcpy(__skb_put(skb, size), va, ALIGN(size, sizeof(long)));
if (likely(!fm10k_page_is_reserved(page)))
return true;
__free_page(page);
return false;
}
pull_len = eth_get_headlen(va, FM10K_RX_HDR_LEN);
memcpy(__skb_put(skb, pull_len), va, ALIGN(pull_len, sizeof(long)));
va += pull_len;
size -= pull_len;
add_tail_frag:
skb_add_rx_frag(skb, skb_shinfo(skb)->nr_frags, page,
(unsigned long)va & ~PAGE_MASK, size, truesize);
return fm10k_can_reuse_rx_page(rx_buffer, page, truesize);
}
static struct sk_buff *fm10k_fetch_rx_buffer(struct fm10k_ring *rx_ring,
union fm10k_rx_desc *rx_desc,
struct sk_buff *skb)
{
struct fm10k_rx_buffer *rx_buffer;
struct page *page;
rx_buffer = &rx_ring->rx_buffer[rx_ring->next_to_clean];
page = rx_buffer->page;
prefetchw(page);
if (likely(!skb)) {
void *page_addr = page_address(page) +
rx_buffer->page_offset;
prefetch(page_addr);
#if L1_CACHE_BYTES < 128
prefetch(page_addr + L1_CACHE_BYTES);
#endif
skb = napi_alloc_skb(&rx_ring->q_vector->napi,
FM10K_RX_HDR_LEN);
if (unlikely(!skb)) {
rx_ring->rx_stats.alloc_failed++;
return NULL;
}
prefetchw(skb->data);
}
dma_sync_single_range_for_cpu(rx_ring->dev,
rx_buffer->dma,
rx_buffer->page_offset,
FM10K_RX_BUFSZ,
DMA_FROM_DEVICE);
if (fm10k_add_rx_frag(rx_buffer, rx_desc, skb)) {
fm10k_reuse_rx_page(rx_ring, rx_buffer);
} else {
dma_unmap_page(rx_ring->dev, rx_buffer->dma,
PAGE_SIZE, DMA_FROM_DEVICE);
}
rx_buffer->page = NULL;
return skb;
}
static inline void fm10k_rx_checksum(struct fm10k_ring *ring,
union fm10k_rx_desc *rx_desc,
struct sk_buff *skb)
{
skb_checksum_none_assert(skb);
if (!(ring->netdev->features & NETIF_F_RXCSUM))
return;
if (fm10k_test_staterr(rx_desc,
FM10K_RXD_STATUS_L4E |
FM10K_RXD_STATUS_L4E2 |
FM10K_RXD_STATUS_IPE |
FM10K_RXD_STATUS_IPE2)) {
ring->rx_stats.csum_err++;
return;
}
if (fm10k_test_staterr(rx_desc, FM10K_RXD_STATUS_L4CS2))
skb->encapsulation = true;
else if (!fm10k_test_staterr(rx_desc, FM10K_RXD_STATUS_L4CS))
return;
skb->ip_summed = CHECKSUM_UNNECESSARY;
ring->rx_stats.csum_good++;
}
static inline void fm10k_rx_hash(struct fm10k_ring *ring,
union fm10k_rx_desc *rx_desc,
struct sk_buff *skb)
{
u16 rss_type;
if (!(ring->netdev->features & NETIF_F_RXHASH))
return;
rss_type = le16_to_cpu(rx_desc->w.pkt_info) & FM10K_RXD_RSSTYPE_MASK;
if (!rss_type)
return;
skb_set_hash(skb, le32_to_cpu(rx_desc->d.rss),
(FM10K_RSS_L4_TYPES_MASK & (1ul << rss_type)) ?
PKT_HASH_TYPE_L4 : PKT_HASH_TYPE_L3);
}
static void fm10k_rx_hwtstamp(struct fm10k_ring *rx_ring,
union fm10k_rx_desc *rx_desc,
struct sk_buff *skb)
{
struct fm10k_intfc *interface = rx_ring->q_vector->interface;
FM10K_CB(skb)->tstamp = rx_desc->q.timestamp;
if (unlikely(interface->flags & FM10K_FLAG_RX_TS_ENABLED))
fm10k_systime_to_hwtstamp(interface, skb_hwtstamps(skb),
le64_to_cpu(rx_desc->q.timestamp));
}
static void fm10k_type_trans(struct fm10k_ring *rx_ring,
union fm10k_rx_desc __maybe_unused *rx_desc,
struct sk_buff *skb)
{
struct net_device *dev = rx_ring->netdev;
struct fm10k_l2_accel *l2_accel = rcu_dereference_bh(rx_ring->l2_accel);
if (l2_accel) {
u16 idx = le16_to_cpu(FM10K_CB(skb)->fi.w.dglort) - 1;
idx -= l2_accel->dglort;
if (idx < l2_accel->size && l2_accel->macvlan[idx])
dev = l2_accel->macvlan[idx];
else
l2_accel = NULL;
}
skb->protocol = eth_type_trans(skb, dev);
if (!l2_accel)
return;
macvlan_count_rx(netdev_priv(dev), skb->len + ETH_HLEN, 1,
!!(rx_desc->w.hdr_info &
cpu_to_le16(FM10K_RXD_HDR_INFO_XC_MASK)));
}
static unsigned int fm10k_process_skb_fields(struct fm10k_ring *rx_ring,
union fm10k_rx_desc *rx_desc,
struct sk_buff *skb)
{
unsigned int len = skb->len;
fm10k_rx_hash(rx_ring, rx_desc, skb);
fm10k_rx_checksum(rx_ring, rx_desc, skb);
fm10k_rx_hwtstamp(rx_ring, rx_desc, skb);
FM10K_CB(skb)->fi.w.vlan = rx_desc->w.vlan;
skb_record_rx_queue(skb, rx_ring->queue_index);
FM10K_CB(skb)->fi.d.glort = rx_desc->d.glort;
if (rx_desc->w.vlan) {
u16 vid = le16_to_cpu(rx_desc->w.vlan);
if ((vid & VLAN_VID_MASK) != rx_ring->vid)
__vlan_hwaccel_put_tag(skb, htons(ETH_P_8021Q), vid);
else if (vid & VLAN_PRIO_MASK)
__vlan_hwaccel_put_tag(skb, htons(ETH_P_8021Q),
vid & VLAN_PRIO_MASK);
}
fm10k_type_trans(rx_ring, rx_desc, skb);
return len;
}
static bool fm10k_is_non_eop(struct fm10k_ring *rx_ring,
union fm10k_rx_desc *rx_desc)
{
u32 ntc = rx_ring->next_to_clean + 1;
ntc = (ntc < rx_ring->count) ? ntc : 0;
rx_ring->next_to_clean = ntc;
prefetch(FM10K_RX_DESC(rx_ring, ntc));
if (likely(fm10k_test_staterr(rx_desc, FM10K_RXD_STATUS_EOP)))
return false;
return true;
}
static bool fm10k_cleanup_headers(struct fm10k_ring *rx_ring,
union fm10k_rx_desc *rx_desc,
struct sk_buff *skb)
{
if (unlikely((fm10k_test_staterr(rx_desc,
FM10K_RXD_STATUS_RXE)))) {
#define FM10K_TEST_RXD_BIT(rxd, bit) \
((rxd)->w.csum_err & cpu_to_le16(bit))
if (FM10K_TEST_RXD_BIT(rx_desc, FM10K_RXD_ERR_SWITCH_ERROR))
rx_ring->rx_stats.switch_errors++;
if (FM10K_TEST_RXD_BIT(rx_desc, FM10K_RXD_ERR_NO_DESCRIPTOR))
rx_ring->rx_stats.drops++;
if (FM10K_TEST_RXD_BIT(rx_desc, FM10K_RXD_ERR_PP_ERROR))
rx_ring->rx_stats.pp_errors++;
if (FM10K_TEST_RXD_BIT(rx_desc, FM10K_RXD_ERR_SWITCH_READY))
rx_ring->rx_stats.link_errors++;
if (FM10K_TEST_RXD_BIT(rx_desc, FM10K_RXD_ERR_TOO_BIG))
rx_ring->rx_stats.length_errors++;
dev_kfree_skb_any(skb);
rx_ring->rx_stats.errors++;
return true;
}
if (eth_skb_pad(skb))
return true;
return false;
}
static void fm10k_receive_skb(struct fm10k_q_vector *q_vector,
struct sk_buff *skb)
{
napi_gro_receive(&q_vector->napi, skb);
}
static int fm10k_clean_rx_irq(struct fm10k_q_vector *q_vector,
struct fm10k_ring *rx_ring,
int budget)
{
struct sk_buff *skb = rx_ring->skb;
unsigned int total_bytes = 0, total_packets = 0;
u16 cleaned_count = fm10k_desc_unused(rx_ring);
while (likely(total_packets < budget)) {
union fm10k_rx_desc *rx_desc;
if (cleaned_count >= FM10K_RX_BUFFER_WRITE) {
fm10k_alloc_rx_buffers(rx_ring, cleaned_count);
cleaned_count = 0;
}
rx_desc = FM10K_RX_DESC(rx_ring, rx_ring->next_to_clean);
if (!rx_desc->d.staterr)
break;
dma_rmb();
skb = fm10k_fetch_rx_buffer(rx_ring, rx_desc, skb);
if (!skb)
break;
cleaned_count++;
if (fm10k_is_non_eop(rx_ring, rx_desc))
continue;
if (fm10k_cleanup_headers(rx_ring, rx_desc, skb)) {
skb = NULL;
continue;
}
total_bytes += fm10k_process_skb_fields(rx_ring, rx_desc, skb);
fm10k_receive_skb(q_vector, skb);
skb = NULL;
total_packets++;
}
rx_ring->skb = skb;
u64_stats_update_begin(&rx_ring->syncp);
rx_ring->stats.packets += total_packets;
rx_ring->stats.bytes += total_bytes;
u64_stats_update_end(&rx_ring->syncp);
q_vector->rx.total_packets += total_packets;
q_vector->rx.total_bytes += total_bytes;
return total_packets;
}
static struct ethhdr *fm10k_port_is_vxlan(struct sk_buff *skb)
{
struct fm10k_intfc *interface = netdev_priv(skb->dev);
struct fm10k_vxlan_port *vxlan_port;
vxlan_port = list_first_entry_or_null(&interface->vxlan_port,
struct fm10k_vxlan_port, list);
if (!vxlan_port)
return NULL;
if (vxlan_port->port != udp_hdr(skb)->dest)
return NULL;
return (struct ethhdr *)(skb_transport_header(skb) + VXLAN_HLEN);
}
static struct ethhdr *fm10k_gre_is_nvgre(struct sk_buff *skb)
{
struct fm10k_nvgre_hdr *nvgre_hdr;
int hlen = ip_hdrlen(skb);
if (vlan_get_protocol(skb) != htons(ETH_P_IP))
return NULL;
nvgre_hdr = (struct fm10k_nvgre_hdr *)(skb_network_header(skb) + hlen);
if (nvgre_hdr->flags & FM10K_NVGRE_RESERVED0_FLAGS)
return NULL;
if (nvgre_hdr->flags & NVGRE_TNI)
return (struct ethhdr *)(nvgre_hdr + 1);
return (struct ethhdr *)(&nvgre_hdr->tni);
}
__be16 fm10k_tx_encap_offload(struct sk_buff *skb)
{
u8 l4_hdr = 0, inner_l4_hdr = 0, inner_l4_hlen;
struct ethhdr *eth_hdr;
if (skb->inner_protocol_type != ENCAP_TYPE_ETHER ||
skb->inner_protocol != htons(ETH_P_TEB))
return 0;
switch (vlan_get_protocol(skb)) {
case htons(ETH_P_IP):
l4_hdr = ip_hdr(skb)->protocol;
break;
case htons(ETH_P_IPV6):
l4_hdr = ipv6_hdr(skb)->nexthdr;
break;
default:
return 0;
}
switch (l4_hdr) {
case IPPROTO_UDP:
eth_hdr = fm10k_port_is_vxlan(skb);
break;
case IPPROTO_GRE:
eth_hdr = fm10k_gre_is_nvgre(skb);
break;
default:
return 0;
}
if (!eth_hdr)
return 0;
switch (eth_hdr->h_proto) {
case htons(ETH_P_IP):
inner_l4_hdr = inner_ip_hdr(skb)->protocol;
break;
case htons(ETH_P_IPV6):
inner_l4_hdr = inner_ipv6_hdr(skb)->nexthdr;
break;
default:
return 0;
}
switch (inner_l4_hdr) {
case IPPROTO_TCP:
inner_l4_hlen = inner_tcp_hdrlen(skb);
break;
case IPPROTO_UDP:
inner_l4_hlen = 8;
break;
default:
return 0;
}
if (skb_inner_transport_header(skb) + inner_l4_hlen -
skb_mac_header(skb) > FM10K_TUNNEL_HEADER_LENGTH)
return 0;
return eth_hdr->h_proto;
}
static int fm10k_tso(struct fm10k_ring *tx_ring,
struct fm10k_tx_buffer *first)
{
struct sk_buff *skb = first->skb;
struct fm10k_tx_desc *tx_desc;
unsigned char *th;
u8 hdrlen;
if (skb->ip_summed != CHECKSUM_PARTIAL)
return 0;
if (!skb_is_gso(skb))
return 0;
if (skb->encapsulation) {
if (!fm10k_tx_encap_offload(skb))
goto err_vxlan;
th = skb_inner_transport_header(skb);
} else {
th = skb_transport_header(skb);
}
hdrlen = (th - skb->data) + (((struct tcphdr *)th)->doff << 2);
first->tx_flags |= FM10K_TX_FLAGS_CSUM;
first->gso_segs = skb_shinfo(skb)->gso_segs;
first->bytecount += (first->gso_segs - 1) * hdrlen;
tx_desc = FM10K_TX_DESC(tx_ring, tx_ring->next_to_use);
tx_desc->hdrlen = hdrlen;
tx_desc->mss = cpu_to_le16(skb_shinfo(skb)->gso_size);
return 1;
err_vxlan:
tx_ring->netdev->features &= ~NETIF_F_GSO_UDP_TUNNEL;
if (!net_ratelimit())
netdev_err(tx_ring->netdev,
"TSO requested for unsupported tunnel, disabling offload\n");
return -1;
}
static void fm10k_tx_csum(struct fm10k_ring *tx_ring,
struct fm10k_tx_buffer *first)
{
struct sk_buff *skb = first->skb;
struct fm10k_tx_desc *tx_desc;
union {
struct iphdr *ipv4;
struct ipv6hdr *ipv6;
u8 *raw;
} network_hdr;
__be16 protocol;
u8 l4_hdr = 0;
if (skb->ip_summed != CHECKSUM_PARTIAL)
goto no_csum;
if (skb->encapsulation) {
protocol = fm10k_tx_encap_offload(skb);
if (!protocol) {
if (skb_checksum_help(skb)) {
dev_warn(tx_ring->dev,
"failed to offload encap csum!\n");
tx_ring->tx_stats.csum_err++;
}
goto no_csum;
}
network_hdr.raw = skb_inner_network_header(skb);
} else {
protocol = vlan_get_protocol(skb);
network_hdr.raw = skb_network_header(skb);
}
switch (protocol) {
case htons(ETH_P_IP):
l4_hdr = network_hdr.ipv4->protocol;
break;
case htons(ETH_P_IPV6):
l4_hdr = network_hdr.ipv6->nexthdr;
break;
default:
if (unlikely(net_ratelimit())) {
dev_warn(tx_ring->dev,
"partial checksum but ip version=%x!\n",
protocol);
}
tx_ring->tx_stats.csum_err++;
goto no_csum;
}
switch (l4_hdr) {
case IPPROTO_TCP:
case IPPROTO_UDP:
break;
case IPPROTO_GRE:
if (skb->encapsulation)
break;
default:
if (unlikely(net_ratelimit())) {
dev_warn(tx_ring->dev,
"partial checksum but l4 proto=%x!\n",
l4_hdr);
}
tx_ring->tx_stats.csum_err++;
goto no_csum;
}
first->tx_flags |= FM10K_TX_FLAGS_CSUM;
tx_ring->tx_stats.csum_good++;
no_csum:
tx_desc = FM10K_TX_DESC(tx_ring, tx_ring->next_to_use);
tx_desc->hdrlen = 0;
tx_desc->mss = 0;
}
static u8 fm10k_tx_desc_flags(struct sk_buff *skb, u32 tx_flags)
{
u32 desc_flags = 0;
if (unlikely(skb_shinfo(skb)->tx_flags & SKBTX_HW_TSTAMP) &&
likely(skb_shinfo(skb)->tx_flags & SKBTX_IN_PROGRESS))
desc_flags |= FM10K_TXD_FLAG_TIME;
desc_flags |= FM10K_SET_FLAG(tx_flags, FM10K_TX_FLAGS_CSUM,
FM10K_TXD_FLAG_CSUM);
return desc_flags;
}
static bool fm10k_tx_desc_push(struct fm10k_ring *tx_ring,
struct fm10k_tx_desc *tx_desc, u16 i,
dma_addr_t dma, unsigned int size, u8 desc_flags)
{
if ((++i & (FM10K_TXD_WB_FIFO_SIZE - 1)) == 0)
desc_flags |= FM10K_TXD_FLAG_RS | FM10K_TXD_FLAG_INT;
tx_desc->buffer_addr = cpu_to_le64(dma);
tx_desc->flags = desc_flags;
tx_desc->buflen = cpu_to_le16(size);
return i == tx_ring->count;
}
static int __fm10k_maybe_stop_tx(struct fm10k_ring *tx_ring, u16 size)
{
netif_stop_subqueue(tx_ring->netdev, tx_ring->queue_index);
smp_mb();
if (likely(fm10k_desc_unused(tx_ring) < size))
return -EBUSY;
netif_start_subqueue(tx_ring->netdev, tx_ring->queue_index);
++tx_ring->tx_stats.restart_queue;
return 0;
}
static inline int fm10k_maybe_stop_tx(struct fm10k_ring *tx_ring, u16 size)
{
if (likely(fm10k_desc_unused(tx_ring) >= size))
return 0;
return __fm10k_maybe_stop_tx(tx_ring, size);
}
static void fm10k_tx_map(struct fm10k_ring *tx_ring,
struct fm10k_tx_buffer *first)
{
struct sk_buff *skb = first->skb;
struct fm10k_tx_buffer *tx_buffer;
struct fm10k_tx_desc *tx_desc;
struct skb_frag_struct *frag;
unsigned char *data;
dma_addr_t dma;
unsigned int data_len, size;
u32 tx_flags = first->tx_flags;
u16 i = tx_ring->next_to_use;
u8 flags = fm10k_tx_desc_flags(skb, tx_flags);
tx_desc = FM10K_TX_DESC(tx_ring, i);
if (skb_vlan_tag_present(skb))
tx_desc->vlan = cpu_to_le16(skb_vlan_tag_get(skb));
else
tx_desc->vlan = 0;
size = skb_headlen(skb);
data = skb->data;
dma = dma_map_single(tx_ring->dev, data, size, DMA_TO_DEVICE);
data_len = skb->data_len;
tx_buffer = first;
for (frag = &skb_shinfo(skb)->frags[0];; frag++) {
if (dma_mapping_error(tx_ring->dev, dma))
goto dma_error;
dma_unmap_len_set(tx_buffer, len, size);
dma_unmap_addr_set(tx_buffer, dma, dma);
while (unlikely(size > FM10K_MAX_DATA_PER_TXD)) {
if (fm10k_tx_desc_push(tx_ring, tx_desc++, i++, dma,
FM10K_MAX_DATA_PER_TXD, flags)) {
tx_desc = FM10K_TX_DESC(tx_ring, 0);
i = 0;
}
dma += FM10K_MAX_DATA_PER_TXD;
size -= FM10K_MAX_DATA_PER_TXD;
}
if (likely(!data_len))
break;
if (fm10k_tx_desc_push(tx_ring, tx_desc++, i++,
dma, size, flags)) {
tx_desc = FM10K_TX_DESC(tx_ring, 0);
i = 0;
}
size = skb_frag_size(frag);
data_len -= size;
dma = skb_frag_dma_map(tx_ring->dev, frag, 0, size,
DMA_TO_DEVICE);
tx_buffer = &tx_ring->tx_buffer[i];
}
flags |= FM10K_TXD_FLAG_LAST;
if (fm10k_tx_desc_push(tx_ring, tx_desc, i++, dma, size, flags))
i = 0;
netdev_tx_sent_queue(txring_txq(tx_ring), first->bytecount);
skb_tx_timestamp(first->skb);
wmb();
first->next_to_watch = tx_desc;
tx_ring->next_to_use = i;
fm10k_maybe_stop_tx(tx_ring, DESC_NEEDED);
if (netif_xmit_stopped(txring_txq(tx_ring)) || !skb->xmit_more) {
writel(i, tx_ring->tail);
mmiowb();
}
return;
dma_error:
dev_err(tx_ring->dev, "TX DMA map failed\n");
for (;;) {
tx_buffer = &tx_ring->tx_buffer[i];
fm10k_unmap_and_free_tx_resource(tx_ring, tx_buffer);
if (tx_buffer == first)
break;
if (i == 0)
i = tx_ring->count;
i--;
}
tx_ring->next_to_use = i;
}
netdev_tx_t fm10k_xmit_frame_ring(struct sk_buff *skb,
struct fm10k_ring *tx_ring)
{
u16 count = TXD_USE_COUNT(skb_headlen(skb));
struct fm10k_tx_buffer *first;
unsigned short f;
u32 tx_flags = 0;
int tso;
for (f = 0; f < skb_shinfo(skb)->nr_frags; f++)
count += TXD_USE_COUNT(skb_shinfo(skb)->frags[f].size);
if (fm10k_maybe_stop_tx(tx_ring, count + 3)) {
tx_ring->tx_stats.tx_busy++;
return NETDEV_TX_BUSY;
}
first = &tx_ring->tx_buffer[tx_ring->next_to_use];
first->skb = skb;
first->bytecount = max_t(unsigned int, skb->len, ETH_ZLEN);
first->gso_segs = 1;
first->tx_flags = tx_flags;
tso = fm10k_tso(tx_ring, first);
if (tso < 0)
goto out_drop;
else if (!tso)
fm10k_tx_csum(tx_ring, first);
fm10k_tx_map(tx_ring, first);
return NETDEV_TX_OK;
out_drop:
dev_kfree_skb_any(first->skb);
first->skb = NULL;
return NETDEV_TX_OK;
}
static u64 fm10k_get_tx_completed(struct fm10k_ring *ring)
{
return ring->stats.packets;
}
static u64 fm10k_get_tx_pending(struct fm10k_ring *ring)
{
u32 head = ring->next_to_clean;
u32 tail = ring->next_to_use;
return ((head <= tail) ? tail : tail + ring->count) - head;
}
bool fm10k_check_tx_hang(struct fm10k_ring *tx_ring)
{
u32 tx_done = fm10k_get_tx_completed(tx_ring);
u32 tx_done_old = tx_ring->tx_stats.tx_done_old;
u32 tx_pending = fm10k_get_tx_pending(tx_ring);
clear_check_for_tx_hang(tx_ring);
if (!tx_pending || (tx_done_old != tx_done)) {
tx_ring->tx_stats.tx_done_old = tx_done;
clear_bit(__FM10K_HANG_CHECK_ARMED, &tx_ring->state);
return false;
}
return test_and_set_bit(__FM10K_HANG_CHECK_ARMED, &tx_ring->state);
}
void fm10k_tx_timeout_reset(struct fm10k_intfc *interface)
{
if (!test_bit(__FM10K_DOWN, &interface->state)) {
interface->tx_timeout_count++;
interface->flags |= FM10K_FLAG_RESET_REQUESTED;
fm10k_service_event_schedule(interface);
}
}
static bool fm10k_clean_tx_irq(struct fm10k_q_vector *q_vector,
struct fm10k_ring *tx_ring)
{
struct fm10k_intfc *interface = q_vector->interface;
struct fm10k_tx_buffer *tx_buffer;
struct fm10k_tx_desc *tx_desc;
unsigned int total_bytes = 0, total_packets = 0;
unsigned int budget = q_vector->tx.work_limit;
unsigned int i = tx_ring->next_to_clean;
if (test_bit(__FM10K_DOWN, &interface->state))
return true;
tx_buffer = &tx_ring->tx_buffer[i];
tx_desc = FM10K_TX_DESC(tx_ring, i);
i -= tx_ring->count;
do {
struct fm10k_tx_desc *eop_desc = tx_buffer->next_to_watch;
if (!eop_desc)
break;
read_barrier_depends();
if (!(eop_desc->flags & FM10K_TXD_FLAG_DONE))
break;
tx_buffer->next_to_watch = NULL;
total_bytes += tx_buffer->bytecount;
total_packets += tx_buffer->gso_segs;
dev_consume_skb_any(tx_buffer->skb);
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
tx_buffer = tx_ring->tx_buffer;
tx_desc = FM10K_TX_DESC(tx_ring, 0);
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
tx_buffer = tx_ring->tx_buffer;
tx_desc = FM10K_TX_DESC(tx_ring, 0);
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
if (check_for_tx_hang(tx_ring) && fm10k_check_tx_hang(tx_ring)) {
struct fm10k_hw *hw = &interface->hw;
netif_err(interface, drv, tx_ring->netdev,
"Detected Tx Unit Hang\n"
" Tx Queue <%d>\n"
" TDH, TDT <%x>, <%x>\n"
" next_to_use <%x>\n"
" next_to_clean <%x>\n",
tx_ring->queue_index,
fm10k_read_reg(hw, FM10K_TDH(tx_ring->reg_idx)),
fm10k_read_reg(hw, FM10K_TDT(tx_ring->reg_idx)),
tx_ring->next_to_use, i);
netif_stop_subqueue(tx_ring->netdev,
tx_ring->queue_index);
netif_info(interface, probe, tx_ring->netdev,
"tx hang %d detected on queue %d, resetting interface\n",
interface->tx_timeout_count + 1,
tx_ring->queue_index);
fm10k_tx_timeout_reset(interface);
return true;
}
netdev_tx_completed_queue(txring_txq(tx_ring),
total_packets, total_bytes);
#define TX_WAKE_THRESHOLD min_t(u16, FM10K_MIN_TXD - 1, DESC_NEEDED * 2)
if (unlikely(total_packets && netif_carrier_ok(tx_ring->netdev) &&
(fm10k_desc_unused(tx_ring) >= TX_WAKE_THRESHOLD))) {
smp_mb();
if (__netif_subqueue_stopped(tx_ring->netdev,
tx_ring->queue_index) &&
!test_bit(__FM10K_DOWN, &interface->state)) {
netif_wake_subqueue(tx_ring->netdev,
tx_ring->queue_index);
++tx_ring->tx_stats.restart_queue;
}
}
return !!budget;
}
static void fm10k_update_itr(struct fm10k_ring_container *ring_container)
{
unsigned int avg_wire_size, packets, itr_round;
if (!ITR_IS_ADAPTIVE(ring_container->itr))
goto clear_counts;
packets = ring_container->total_packets;
if (!packets)
goto clear_counts;
avg_wire_size = ring_container->total_bytes / packets;
if (avg_wire_size <= 360) {
avg_wire_size *= 8;
avg_wire_size += 376;
} else if (avg_wire_size <= 1152) {
avg_wire_size *= 3;
avg_wire_size += 2176;
} else if (avg_wire_size <= 1920) {
avg_wire_size += 4480;
} else {
avg_wire_size = 6656;
}
itr_round = ACCESS_ONCE(ring_container->itr_scale) + 8;
avg_wire_size += (1 << itr_round) - 1;
avg_wire_size >>= itr_round;
ring_container->itr = avg_wire_size | FM10K_ITR_ADAPTIVE;
clear_counts:
ring_container->total_bytes = 0;
ring_container->total_packets = 0;
}
static void fm10k_qv_enable(struct fm10k_q_vector *q_vector)
{
u32 itr = FM10K_ITR_ENABLE;
fm10k_update_itr(&q_vector->tx);
fm10k_update_itr(&q_vector->rx);
itr |= (q_vector->tx.itr & FM10K_ITR_MAX);
itr |= (q_vector->rx.itr & FM10K_ITR_MAX) << FM10K_ITR_INTERVAL1_SHIFT;
writel(itr, q_vector->itr);
}
static int fm10k_poll(struct napi_struct *napi, int budget)
{
struct fm10k_q_vector *q_vector =
container_of(napi, struct fm10k_q_vector, napi);
struct fm10k_ring *ring;
int per_ring_budget, work_done = 0;
bool clean_complete = true;
fm10k_for_each_ring(ring, q_vector->tx)
clean_complete &= fm10k_clean_tx_irq(q_vector, ring);
if (budget <= 0)
return budget;
if (q_vector->rx.count > 1)
per_ring_budget = max(budget / q_vector->rx.count, 1);
else
per_ring_budget = budget;
fm10k_for_each_ring(ring, q_vector->rx) {
int work = fm10k_clean_rx_irq(q_vector, ring, per_ring_budget);
work_done += work;
clean_complete &= !!(work < per_ring_budget);
}
if (!clean_complete)
return budget;
napi_complete_done(napi, work_done);
fm10k_qv_enable(q_vector);
return 0;
}
static bool fm10k_set_qos_queues(struct fm10k_intfc *interface)
{
struct net_device *dev = interface->netdev;
struct fm10k_ring_feature *f;
int rss_i, i;
int pcs;
pcs = netdev_get_num_tc(dev);
if (pcs <= 1)
return false;
f = &interface->ring_feature[RING_F_QOS];
f->indices = pcs;
f->mask = (1 << fls(pcs - 1)) - 1;
rss_i = interface->hw.mac.max_queues / pcs;
rss_i = 1 << (fls(rss_i) - 1);
f = &interface->ring_feature[RING_F_RSS];
rss_i = min_t(u16, rss_i, f->limit);
f->indices = rss_i;
f->mask = (1 << fls(rss_i - 1)) - 1;
for (i = 0; i < pcs; i++)
netdev_set_tc_queue(dev, i, rss_i, rss_i * i);
interface->num_rx_queues = rss_i * pcs;
interface->num_tx_queues = rss_i * pcs;
return true;
}
static bool fm10k_set_rss_queues(struct fm10k_intfc *interface)
{
struct fm10k_ring_feature *f;
u16 rss_i;
f = &interface->ring_feature[RING_F_RSS];
rss_i = min_t(u16, interface->hw.mac.max_queues, f->limit);
f->indices = rss_i;
f->mask = (1 << fls(rss_i - 1)) - 1;
interface->num_rx_queues = rss_i;
interface->num_tx_queues = rss_i;
return true;
}
static void fm10k_set_num_queues(struct fm10k_intfc *interface)
{
interface->num_rx_queues = 1;
interface->num_tx_queues = 1;
if (fm10k_set_qos_queues(interface))
return;
fm10k_set_rss_queues(interface);
}
static int fm10k_alloc_q_vector(struct fm10k_intfc *interface,
unsigned int v_count, unsigned int v_idx,
unsigned int txr_count, unsigned int txr_idx,
unsigned int rxr_count, unsigned int rxr_idx)
{
struct fm10k_q_vector *q_vector;
struct fm10k_ring *ring;
int ring_count, size;
ring_count = txr_count + rxr_count;
size = sizeof(struct fm10k_q_vector) +
(sizeof(struct fm10k_ring) * ring_count);
q_vector = kzalloc(size, GFP_KERNEL);
if (!q_vector)
return -ENOMEM;
netif_napi_add(interface->netdev, &q_vector->napi,
fm10k_poll, NAPI_POLL_WEIGHT);
interface->q_vector[v_idx] = q_vector;
q_vector->interface = interface;
q_vector->v_idx = v_idx;
ring = q_vector->ring;
q_vector->tx.ring = ring;
q_vector->tx.work_limit = FM10K_DEFAULT_TX_WORK;
q_vector->tx.itr = interface->tx_itr;
q_vector->tx.itr_scale = interface->hw.mac.itr_scale;
q_vector->tx.count = txr_count;
while (txr_count) {
ring->dev = &interface->pdev->dev;
ring->netdev = interface->netdev;
ring->q_vector = q_vector;
ring->count = interface->tx_ring_count;
ring->queue_index = txr_idx;
interface->tx_ring[txr_idx] = ring;
txr_count--;
txr_idx += v_count;
ring++;
}
q_vector->rx.ring = ring;
q_vector->rx.itr = interface->rx_itr;
q_vector->rx.itr_scale = interface->hw.mac.itr_scale;
q_vector->rx.count = rxr_count;
while (rxr_count) {
ring->dev = &interface->pdev->dev;
ring->netdev = interface->netdev;
rcu_assign_pointer(ring->l2_accel, interface->l2_accel);
ring->q_vector = q_vector;
ring->count = interface->rx_ring_count;
ring->queue_index = rxr_idx;
interface->rx_ring[rxr_idx] = ring;
rxr_count--;
rxr_idx += v_count;
ring++;
}
fm10k_dbg_q_vector_init(q_vector);
return 0;
}
static void fm10k_free_q_vector(struct fm10k_intfc *interface, int v_idx)
{
struct fm10k_q_vector *q_vector = interface->q_vector[v_idx];
struct fm10k_ring *ring;
fm10k_dbg_q_vector_exit(q_vector);
fm10k_for_each_ring(ring, q_vector->tx)
interface->tx_ring[ring->queue_index] = NULL;
fm10k_for_each_ring(ring, q_vector->rx)
interface->rx_ring[ring->queue_index] = NULL;
interface->q_vector[v_idx] = NULL;
netif_napi_del(&q_vector->napi);
kfree_rcu(q_vector, rcu);
}
static int fm10k_alloc_q_vectors(struct fm10k_intfc *interface)
{
unsigned int q_vectors = interface->num_q_vectors;
unsigned int rxr_remaining = interface->num_rx_queues;
unsigned int txr_remaining = interface->num_tx_queues;
unsigned int rxr_idx = 0, txr_idx = 0, v_idx = 0;
int err;
if (q_vectors >= (rxr_remaining + txr_remaining)) {
for (; rxr_remaining; v_idx++) {
err = fm10k_alloc_q_vector(interface, q_vectors, v_idx,
0, 0, 1, rxr_idx);
if (err)
goto err_out;
rxr_remaining--;
rxr_idx++;
}
}
for (; v_idx < q_vectors; v_idx++) {
int rqpv = DIV_ROUND_UP(rxr_remaining, q_vectors - v_idx);
int tqpv = DIV_ROUND_UP(txr_remaining, q_vectors - v_idx);
err = fm10k_alloc_q_vector(interface, q_vectors, v_idx,
tqpv, txr_idx,
rqpv, rxr_idx);
if (err)
goto err_out;
rxr_remaining -= rqpv;
txr_remaining -= tqpv;
rxr_idx++;
txr_idx++;
}
return 0;
err_out:
interface->num_tx_queues = 0;
interface->num_rx_queues = 0;
interface->num_q_vectors = 0;
while (v_idx--)
fm10k_free_q_vector(interface, v_idx);
return -ENOMEM;
}
static void fm10k_free_q_vectors(struct fm10k_intfc *interface)
{
int v_idx = interface->num_q_vectors;
interface->num_tx_queues = 0;
interface->num_rx_queues = 0;
interface->num_q_vectors = 0;
while (v_idx--)
fm10k_free_q_vector(interface, v_idx);
}
static void fm10k_reset_msix_capability(struct fm10k_intfc *interface)
{
pci_disable_msix(interface->pdev);
kfree(interface->msix_entries);
interface->msix_entries = NULL;
}
static int fm10k_init_msix_capability(struct fm10k_intfc *interface)
{
struct fm10k_hw *hw = &interface->hw;
int v_budget, vector;
v_budget = max(interface->num_rx_queues, interface->num_tx_queues);
v_budget = min_t(u16, v_budget, num_online_cpus());
v_budget += NON_Q_VECTORS(hw);
v_budget = min_t(int, v_budget, hw->mac.max_msix_vectors);
interface->msix_entries = kcalloc(v_budget, sizeof(struct msix_entry),
GFP_KERNEL);
if (!interface->msix_entries)
return -ENOMEM;
for (vector = 0; vector < v_budget; vector++)
interface->msix_entries[vector].entry = vector;
v_budget = pci_enable_msix_range(interface->pdev,
interface->msix_entries,
MIN_MSIX_COUNT(hw),
v_budget);
if (v_budget < 0) {
kfree(interface->msix_entries);
interface->msix_entries = NULL;
return -ENOMEM;
}
interface->num_q_vectors = v_budget - NON_Q_VECTORS(hw);
return 0;
}
static bool fm10k_cache_ring_qos(struct fm10k_intfc *interface)
{
struct net_device *dev = interface->netdev;
int pc, offset, rss_i, i, q_idx;
u16 pc_stride = interface->ring_feature[RING_F_QOS].mask + 1;
u8 num_pcs = netdev_get_num_tc(dev);
if (num_pcs <= 1)
return false;
rss_i = interface->ring_feature[RING_F_RSS].indices;
for (pc = 0, offset = 0; pc < num_pcs; pc++, offset += rss_i) {
q_idx = pc;
for (i = 0; i < rss_i; i++) {
interface->tx_ring[offset + i]->reg_idx = q_idx;
interface->tx_ring[offset + i]->qos_pc = pc;
interface->rx_ring[offset + i]->reg_idx = q_idx;
interface->rx_ring[offset + i]->qos_pc = pc;
q_idx += pc_stride;
}
}
return true;
}
static void fm10k_cache_ring_rss(struct fm10k_intfc *interface)
{
int i;
for (i = 0; i < interface->num_rx_queues; i++)
interface->rx_ring[i]->reg_idx = i;
for (i = 0; i < interface->num_tx_queues; i++)
interface->tx_ring[i]->reg_idx = i;
}
static void fm10k_assign_rings(struct fm10k_intfc *interface)
{
if (fm10k_cache_ring_qos(interface))
return;
fm10k_cache_ring_rss(interface);
}
static void fm10k_init_reta(struct fm10k_intfc *interface)
{
u16 i, rss_i = interface->ring_feature[RING_F_RSS].indices;
u32 reta, base;
if (netif_is_rxfh_configured(interface->netdev)) {
for (i = FM10K_RETA_SIZE; i--;) {
reta = interface->reta[i];
if ((((reta << 24) >> 24) < rss_i) &&
(((reta << 16) >> 24) < rss_i) &&
(((reta << 8) >> 24) < rss_i) &&
(((reta) >> 24) < rss_i))
continue;
dev_err(&interface->pdev->dev,
"RSS indirection table assigned flows out of queue bounds. Reconfiguring.\n");
goto repopulate_reta;
}
return;
}
repopulate_reta:
for (i = FM10K_RETA_SIZE; i--;) {
base = ((i * 0x00040004) + 0x00020000) * rss_i;
reta = (base & 0x3F803F80) >> 7;
base += 0x00010001 * rss_i;
reta |= (base & 0x3F803F80) << 1;
interface->reta[i] = reta;
}
}
int fm10k_init_queueing_scheme(struct fm10k_intfc *interface)
{
int err;
fm10k_set_num_queues(interface);
err = fm10k_init_msix_capability(interface);
if (err) {
dev_err(&interface->pdev->dev,
"Unable to initialize MSI-X capability\n");
return err;
}
err = fm10k_alloc_q_vectors(interface);
if (err) {
fm10k_reset_msix_capability(interface);
return err;
}
fm10k_assign_rings(interface);
fm10k_init_reta(interface);
return 0;
}
void fm10k_clear_queueing_scheme(struct fm10k_intfc *interface)
{
fm10k_free_q_vectors(interface);
fm10k_reset_msix_capability(interface);
}
