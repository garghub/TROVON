static inline void prefetch_ptr(struct efx_tx_queue *tx_queue)
{
unsigned int insert_ptr = efx_tx_queue_get_insert_index(tx_queue);
char *ptr;
ptr = (char *) (tx_queue->buffer + insert_ptr);
prefetch(ptr);
prefetch(ptr + 0x80);
ptr = (char *) (((efx_qword_t *)tx_queue->txd.buf.addr) + insert_ptr);
prefetch(ptr);
prefetch(ptr + 0x80);
}
static void efx_tx_queue_insert(struct efx_tx_queue *tx_queue,
dma_addr_t dma_addr, unsigned int len,
struct efx_tx_buffer **final_buffer)
{
struct efx_tx_buffer *buffer;
unsigned int dma_len;
EFX_WARN_ON_ONCE_PARANOID(len <= 0);
while (1) {
buffer = efx_tx_queue_get_insert_buffer(tx_queue);
++tx_queue->insert_count;
EFX_WARN_ON_ONCE_PARANOID(tx_queue->insert_count -
tx_queue->read_count >=
tx_queue->efx->txq_entries);
buffer->dma_addr = dma_addr;
dma_len = tx_queue->efx->type->tx_limit_len(tx_queue,
dma_addr, len);
if (dma_len >= len)
break;
buffer->len = dma_len;
buffer->flags = EFX_TX_BUF_CONT;
dma_addr += dma_len;
len -= dma_len;
}
EFX_WARN_ON_ONCE_PARANOID(!len);
buffer->len = len;
*final_buffer = buffer;
}
static __be16 efx_tso_check_protocol(struct sk_buff *skb)
{
__be16 protocol = skb->protocol;
EFX_WARN_ON_ONCE_PARANOID(((struct ethhdr *)skb->data)->h_proto !=
protocol);
if (protocol == htons(ETH_P_8021Q)) {
struct vlan_ethhdr *veh = (struct vlan_ethhdr *)skb->data;
protocol = veh->h_vlan_encapsulated_proto;
}
if (protocol == htons(ETH_P_IP)) {
EFX_WARN_ON_ONCE_PARANOID(ip_hdr(skb)->protocol != IPPROTO_TCP);
} else {
EFX_WARN_ON_ONCE_PARANOID(protocol != htons(ETH_P_IPV6));
EFX_WARN_ON_ONCE_PARANOID(ipv6_hdr(skb)->nexthdr != NEXTHDR_TCP);
}
EFX_WARN_ON_ONCE_PARANOID((PTR_DIFF(tcp_hdr(skb), skb->data) +
(tcp_hdr(skb)->doff << 2u)) >
skb_headlen(skb));
return protocol;
}
static int tso_start(struct tso_state *st, struct efx_nic *efx,
struct efx_tx_queue *tx_queue,
const struct sk_buff *skb)
{
struct device *dma_dev = &efx->pci_dev->dev;
unsigned int header_len, in_len;
dma_addr_t dma_addr;
st->ip_off = skb_network_header(skb) - skb->data;
st->tcp_off = skb_transport_header(skb) - skb->data;
header_len = st->tcp_off + (tcp_hdr(skb)->doff << 2u);
in_len = skb_headlen(skb) - header_len;
st->header_len = header_len;
st->in_len = in_len;
if (st->protocol == htons(ETH_P_IP)) {
st->ip_base_len = st->header_len - st->ip_off;
st->ipv4_id = ntohs(ip_hdr(skb)->id);
} else {
st->ip_base_len = st->header_len - st->tcp_off;
st->ipv4_id = 0;
}
st->seqnum = ntohl(tcp_hdr(skb)->seq);
EFX_WARN_ON_ONCE_PARANOID(tcp_hdr(skb)->urg);
EFX_WARN_ON_ONCE_PARANOID(tcp_hdr(skb)->syn);
EFX_WARN_ON_ONCE_PARANOID(tcp_hdr(skb)->rst);
st->out_len = skb->len - header_len;
dma_addr = dma_map_single(dma_dev, skb->data,
skb_headlen(skb), DMA_TO_DEVICE);
st->header_dma_addr = dma_addr;
st->header_unmap_len = skb_headlen(skb);
st->dma_addr = dma_addr + header_len;
st->unmap_len = 0;
return unlikely(dma_mapping_error(dma_dev, dma_addr)) ? -ENOMEM : 0;
}
static int tso_get_fragment(struct tso_state *st, struct efx_nic *efx,
skb_frag_t *frag)
{
st->unmap_addr = skb_frag_dma_map(&efx->pci_dev->dev, frag, 0,
skb_frag_size(frag), DMA_TO_DEVICE);
if (likely(!dma_mapping_error(&efx->pci_dev->dev, st->unmap_addr))) {
st->unmap_len = skb_frag_size(frag);
st->in_len = skb_frag_size(frag);
st->dma_addr = st->unmap_addr;
return 0;
}
return -ENOMEM;
}
static void tso_fill_packet_with_fragment(struct efx_tx_queue *tx_queue,
const struct sk_buff *skb,
struct tso_state *st)
{
struct efx_tx_buffer *buffer;
int n;
if (st->in_len == 0)
return;
if (st->packet_space == 0)
return;
EFX_WARN_ON_ONCE_PARANOID(st->in_len <= 0);
EFX_WARN_ON_ONCE_PARANOID(st->packet_space <= 0);
n = min(st->in_len, st->packet_space);
st->packet_space -= n;
st->out_len -= n;
st->in_len -= n;
efx_tx_queue_insert(tx_queue, st->dma_addr, n, &buffer);
if (st->out_len == 0) {
buffer->skb = skb;
buffer->flags = EFX_TX_BUF_SKB;
} else if (st->packet_space != 0) {
buffer->flags = EFX_TX_BUF_CONT;
}
if (st->in_len == 0) {
buffer->unmap_len = st->unmap_len;
buffer->dma_offset = buffer->unmap_len - buffer->len;
st->unmap_len = 0;
}
st->dma_addr += n;
}
static int tso_start_new_packet(struct efx_tx_queue *tx_queue,
const struct sk_buff *skb,
struct tso_state *st)
{
struct efx_tx_buffer *buffer =
efx_tx_queue_get_insert_buffer(tx_queue);
bool is_last = st->out_len <= skb_shinfo(skb)->gso_size;
u8 tcp_flags_mask, tcp_flags;
if (!is_last) {
st->packet_space = skb_shinfo(skb)->gso_size;
tcp_flags_mask = 0x09;
} else {
st->packet_space = st->out_len;
tcp_flags_mask = 0x00;
}
if (WARN_ON(!st->header_unmap_len))
return -EINVAL;
tcp_flags = ((u8 *)tcp_hdr(skb))[TCP_FLAGS_OFFSET] & ~tcp_flags_mask;
buffer->flags = EFX_TX_BUF_OPTION;
buffer->len = 0;
buffer->unmap_len = 0;
EFX_POPULATE_QWORD_5(buffer->option,
ESF_DZ_TX_DESC_IS_OPT, 1,
ESF_DZ_TX_OPTION_TYPE,
ESE_DZ_TX_OPTION_DESC_TSO,
ESF_DZ_TX_TSO_TCP_FLAGS, tcp_flags,
ESF_DZ_TX_TSO_IP_ID, st->ipv4_id,
ESF_DZ_TX_TSO_TCP_SEQNO, st->seqnum);
++tx_queue->insert_count;
buffer = efx_tx_queue_get_insert_buffer(tx_queue);
buffer->dma_addr = st->header_dma_addr;
buffer->len = st->header_len;
if (is_last) {
buffer->flags = EFX_TX_BUF_CONT | EFX_TX_BUF_MAP_SINGLE;
buffer->unmap_len = st->header_unmap_len;
buffer->dma_offset = 0;
st->header_unmap_len = 0;
} else {
buffer->flags = EFX_TX_BUF_CONT;
buffer->unmap_len = 0;
}
++tx_queue->insert_count;
st->seqnum += skb_shinfo(skb)->gso_size;
++st->ipv4_id;
return 0;
}
int efx_enqueue_skb_tso(struct efx_tx_queue *tx_queue,
struct sk_buff *skb,
bool *data_mapped)
{
struct efx_nic *efx = tx_queue->efx;
int frag_i, rc;
struct tso_state state;
if (tx_queue->tso_version != 1)
return -EINVAL;
prefetch(skb->data);
state.protocol = efx_tso_check_protocol(skb);
EFX_WARN_ON_ONCE_PARANOID(tx_queue->write_count != tx_queue->insert_count);
rc = tso_start(&state, efx, tx_queue, skb);
if (rc)
goto fail;
if (likely(state.in_len == 0)) {
EFX_WARN_ON_ONCE_PARANOID(skb_shinfo(skb)->nr_frags < 1);
frag_i = 0;
rc = tso_get_fragment(&state, efx,
skb_shinfo(skb)->frags + frag_i);
if (rc)
goto fail;
} else {
frag_i = -1;
}
rc = tso_start_new_packet(tx_queue, skb, &state);
if (rc)
goto fail;
prefetch_ptr(tx_queue);
while (1) {
tso_fill_packet_with_fragment(tx_queue, skb, &state);
if (state.in_len == 0) {
if (++frag_i >= skb_shinfo(skb)->nr_frags)
break;
rc = tso_get_fragment(&state, efx,
skb_shinfo(skb)->frags + frag_i);
if (rc)
goto fail;
}
if (state.packet_space == 0) {
rc = tso_start_new_packet(tx_queue, skb, &state);
if (rc)
goto fail;
}
}
*data_mapped = true;
return 0;
fail:
if (rc == -ENOMEM)
netif_err(efx, tx_err, efx->net_dev,
"Out of memory for TSO headers, or DMA mapping error\n");
else
netif_err(efx, tx_err, efx->net_dev, "TSO failed, rc = %d\n", rc);
if (state.unmap_len) {
dma_unmap_page(&efx->pci_dev->dev, state.unmap_addr,
state.unmap_len, DMA_TO_DEVICE);
}
if (state.header_unmap_len)
dma_unmap_single(&efx->pci_dev->dev, state.header_dma_addr,
state.header_unmap_len, DMA_TO_DEVICE);
return rc;
}
