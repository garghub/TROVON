static void
vmxnet3_enable_intr(struct vmxnet3_adapter *adapter, unsigned intr_idx)
{
VMXNET3_WRITE_BAR0_REG(adapter, VMXNET3_REG_IMR + intr_idx * 8, 0);
}
static void
vmxnet3_disable_intr(struct vmxnet3_adapter *adapter, unsigned intr_idx)
{
VMXNET3_WRITE_BAR0_REG(adapter, VMXNET3_REG_IMR + intr_idx * 8, 1);
}
static void
vmxnet3_enable_all_intrs(struct vmxnet3_adapter *adapter)
{
int i;
for (i = 0; i < adapter->intr.num_intrs; i++)
vmxnet3_enable_intr(adapter, i);
adapter->shared->devRead.intrConf.intrCtrl &=
cpu_to_le32(~VMXNET3_IC_DISABLE_ALL);
}
static void
vmxnet3_disable_all_intrs(struct vmxnet3_adapter *adapter)
{
int i;
adapter->shared->devRead.intrConf.intrCtrl |=
cpu_to_le32(VMXNET3_IC_DISABLE_ALL);
for (i = 0; i < adapter->intr.num_intrs; i++)
vmxnet3_disable_intr(adapter, i);
}
static void
vmxnet3_ack_events(struct vmxnet3_adapter *adapter, u32 events)
{
VMXNET3_WRITE_BAR1_REG(adapter, VMXNET3_REG_ECR, events);
}
static bool
vmxnet3_tq_stopped(struct vmxnet3_tx_queue *tq, struct vmxnet3_adapter *adapter)
{
return tq->stopped;
}
static void
vmxnet3_tq_start(struct vmxnet3_tx_queue *tq, struct vmxnet3_adapter *adapter)
{
tq->stopped = false;
netif_start_subqueue(adapter->netdev, tq - adapter->tx_queue);
}
static void
vmxnet3_tq_wake(struct vmxnet3_tx_queue *tq, struct vmxnet3_adapter *adapter)
{
tq->stopped = false;
netif_wake_subqueue(adapter->netdev, (tq - adapter->tx_queue));
}
static void
vmxnet3_tq_stop(struct vmxnet3_tx_queue *tq, struct vmxnet3_adapter *adapter)
{
tq->stopped = true;
tq->num_stop++;
netif_stop_subqueue(adapter->netdev, (tq - adapter->tx_queue));
}
static void
vmxnet3_check_link(struct vmxnet3_adapter *adapter, bool affectTxQueue)
{
u32 ret;
int i;
unsigned long flags;
spin_lock_irqsave(&adapter->cmd_lock, flags);
VMXNET3_WRITE_BAR1_REG(adapter, VMXNET3_REG_CMD, VMXNET3_CMD_GET_LINK);
ret = VMXNET3_READ_BAR1_REG(adapter, VMXNET3_REG_CMD);
spin_unlock_irqrestore(&adapter->cmd_lock, flags);
adapter->link_speed = ret >> 16;
if (ret & 1) {
printk(KERN_INFO "%s: NIC Link is Up %d Mbps\n",
adapter->netdev->name, adapter->link_speed);
if (!netif_carrier_ok(adapter->netdev))
netif_carrier_on(adapter->netdev);
if (affectTxQueue) {
for (i = 0; i < adapter->num_tx_queues; i++)
vmxnet3_tq_start(&adapter->tx_queue[i],
adapter);
}
} else {
printk(KERN_INFO "%s: NIC Link is Down\n",
adapter->netdev->name);
if (netif_carrier_ok(adapter->netdev))
netif_carrier_off(adapter->netdev);
if (affectTxQueue) {
for (i = 0; i < adapter->num_tx_queues; i++)
vmxnet3_tq_stop(&adapter->tx_queue[i], adapter);
}
}
}
static void
vmxnet3_process_events(struct vmxnet3_adapter *adapter)
{
int i;
unsigned long flags;
u32 events = le32_to_cpu(adapter->shared->ecr);
if (!events)
return;
vmxnet3_ack_events(adapter, events);
if (events & VMXNET3_ECR_LINK)
vmxnet3_check_link(adapter, true);
if (events & (VMXNET3_ECR_TQERR | VMXNET3_ECR_RQERR)) {
spin_lock_irqsave(&adapter->cmd_lock, flags);
VMXNET3_WRITE_BAR1_REG(adapter, VMXNET3_REG_CMD,
VMXNET3_CMD_GET_QUEUE_STATUS);
spin_unlock_irqrestore(&adapter->cmd_lock, flags);
for (i = 0; i < adapter->num_tx_queues; i++)
if (adapter->tqd_start[i].status.stopped)
dev_err(&adapter->netdev->dev,
"%s: tq[%d] error 0x%x\n",
adapter->netdev->name, i, le32_to_cpu(
adapter->tqd_start[i].status.error));
for (i = 0; i < adapter->num_rx_queues; i++)
if (adapter->rqd_start[i].status.stopped)
dev_err(&adapter->netdev->dev,
"%s: rq[%d] error 0x%x\n",
adapter->netdev->name, i,
adapter->rqd_start[i].status.error);
schedule_work(&adapter->work);
}
}
static void vmxnet3_RxDescToCPU(const struct Vmxnet3_RxDesc *srcDesc,
struct Vmxnet3_RxDesc *dstDesc)
{
u32 *src = (u32 *)srcDesc + 2;
u32 *dst = (u32 *)dstDesc + 2;
dstDesc->addr = le64_to_cpu(srcDesc->addr);
*dst = le32_to_cpu(*src);
dstDesc->ext1 = le32_to_cpu(srcDesc->ext1);
}
static void vmxnet3_TxDescToLe(const struct Vmxnet3_TxDesc *srcDesc,
struct Vmxnet3_TxDesc *dstDesc)
{
int i;
u32 *src = (u32 *)(srcDesc + 1);
u32 *dst = (u32 *)(dstDesc + 1);
for (i = 2; i > 0; i--) {
src--;
dst--;
*dst = cpu_to_le32(*src);
}
}
static void vmxnet3_RxCompToCPU(const struct Vmxnet3_RxCompDesc *srcDesc,
struct Vmxnet3_RxCompDesc *dstDesc)
{
int i = 0;
u32 *src = (u32 *)srcDesc;
u32 *dst = (u32 *)dstDesc;
for (i = 0; i < sizeof(struct Vmxnet3_RxCompDesc) / sizeof(u32); i++) {
*dst = le32_to_cpu(*src);
src++;
dst++;
}
}
static u32 get_bitfield32(const __le32 *bitfield, u32 pos, u32 size)
{
u32 temp = le32_to_cpu(*bitfield);
u32 mask = ((1 << size) - 1) << pos;
temp &= mask;
temp >>= pos;
return temp;
}
static void
vmxnet3_unmap_tx_buf(struct vmxnet3_tx_buf_info *tbi,
struct pci_dev *pdev)
{
if (tbi->map_type == VMXNET3_MAP_SINGLE)
pci_unmap_single(pdev, tbi->dma_addr, tbi->len,
PCI_DMA_TODEVICE);
else if (tbi->map_type == VMXNET3_MAP_PAGE)
pci_unmap_page(pdev, tbi->dma_addr, tbi->len,
PCI_DMA_TODEVICE);
else
BUG_ON(tbi->map_type != VMXNET3_MAP_NONE);
tbi->map_type = VMXNET3_MAP_NONE;
}
static int
vmxnet3_unmap_pkt(u32 eop_idx, struct vmxnet3_tx_queue *tq,
struct pci_dev *pdev, struct vmxnet3_adapter *adapter)
{
struct sk_buff *skb;
int entries = 0;
BUG_ON(tq->buf_info[eop_idx].sop_idx != tq->tx_ring.next2comp);
BUG_ON(VMXNET3_TXDESC_GET_EOP(&(tq->tx_ring.base[eop_idx].txd)) != 1);
skb = tq->buf_info[eop_idx].skb;
BUG_ON(skb == NULL);
tq->buf_info[eop_idx].skb = NULL;
VMXNET3_INC_RING_IDX_ONLY(eop_idx, tq->tx_ring.size);
while (tq->tx_ring.next2comp != eop_idx) {
vmxnet3_unmap_tx_buf(tq->buf_info + tq->tx_ring.next2comp,
pdev);
vmxnet3_cmd_ring_adv_next2comp(&tq->tx_ring);
entries++;
}
dev_kfree_skb_any(skb);
return entries;
}
static int
vmxnet3_tq_tx_complete(struct vmxnet3_tx_queue *tq,
struct vmxnet3_adapter *adapter)
{
int completed = 0;
union Vmxnet3_GenericDesc *gdesc;
gdesc = tq->comp_ring.base + tq->comp_ring.next2proc;
while (VMXNET3_TCD_GET_GEN(&gdesc->tcd) == tq->comp_ring.gen) {
completed += vmxnet3_unmap_pkt(VMXNET3_TCD_GET_TXIDX(
&gdesc->tcd), tq, adapter->pdev,
adapter);
vmxnet3_comp_ring_adv_next2proc(&tq->comp_ring);
gdesc = tq->comp_ring.base + tq->comp_ring.next2proc;
}
if (completed) {
spin_lock(&tq->tx_lock);
if (unlikely(vmxnet3_tq_stopped(tq, adapter) &&
vmxnet3_cmd_ring_desc_avail(&tq->tx_ring) >
VMXNET3_WAKE_QUEUE_THRESHOLD(tq) &&
netif_carrier_ok(adapter->netdev))) {
vmxnet3_tq_wake(tq, adapter);
}
spin_unlock(&tq->tx_lock);
}
return completed;
}
static void
vmxnet3_tq_cleanup(struct vmxnet3_tx_queue *tq,
struct vmxnet3_adapter *adapter)
{
int i;
while (tq->tx_ring.next2comp != tq->tx_ring.next2fill) {
struct vmxnet3_tx_buf_info *tbi;
tbi = tq->buf_info + tq->tx_ring.next2comp;
vmxnet3_unmap_tx_buf(tbi, adapter->pdev);
if (tbi->skb) {
dev_kfree_skb_any(tbi->skb);
tbi->skb = NULL;
}
vmxnet3_cmd_ring_adv_next2comp(&tq->tx_ring);
}
for (i = 0; i < tq->tx_ring.size; i++) {
BUG_ON(tq->buf_info[i].skb != NULL ||
tq->buf_info[i].map_type != VMXNET3_MAP_NONE);
}
tq->tx_ring.gen = VMXNET3_INIT_GEN;
tq->tx_ring.next2fill = tq->tx_ring.next2comp = 0;
tq->comp_ring.gen = VMXNET3_INIT_GEN;
tq->comp_ring.next2proc = 0;
}
static void
vmxnet3_tq_destroy(struct vmxnet3_tx_queue *tq,
struct vmxnet3_adapter *adapter)
{
if (tq->tx_ring.base) {
pci_free_consistent(adapter->pdev, tq->tx_ring.size *
sizeof(struct Vmxnet3_TxDesc),
tq->tx_ring.base, tq->tx_ring.basePA);
tq->tx_ring.base = NULL;
}
if (tq->data_ring.base) {
pci_free_consistent(adapter->pdev, tq->data_ring.size *
sizeof(struct Vmxnet3_TxDataDesc),
tq->data_ring.base, tq->data_ring.basePA);
tq->data_ring.base = NULL;
}
if (tq->comp_ring.base) {
pci_free_consistent(adapter->pdev, tq->comp_ring.size *
sizeof(struct Vmxnet3_TxCompDesc),
tq->comp_ring.base, tq->comp_ring.basePA);
tq->comp_ring.base = NULL;
}
kfree(tq->buf_info);
tq->buf_info = NULL;
}
void
vmxnet3_tq_destroy_all(struct vmxnet3_adapter *adapter)
{
int i;
for (i = 0; i < adapter->num_tx_queues; i++)
vmxnet3_tq_destroy(&adapter->tx_queue[i], adapter);
}
static void
vmxnet3_tq_init(struct vmxnet3_tx_queue *tq,
struct vmxnet3_adapter *adapter)
{
int i;
memset(tq->tx_ring.base, 0, tq->tx_ring.size *
sizeof(struct Vmxnet3_TxDesc));
tq->tx_ring.next2fill = tq->tx_ring.next2comp = 0;
tq->tx_ring.gen = VMXNET3_INIT_GEN;
memset(tq->data_ring.base, 0, tq->data_ring.size *
sizeof(struct Vmxnet3_TxDataDesc));
memset(tq->comp_ring.base, 0, tq->comp_ring.size *
sizeof(struct Vmxnet3_TxCompDesc));
tq->comp_ring.next2proc = 0;
tq->comp_ring.gen = VMXNET3_INIT_GEN;
memset(tq->buf_info, 0, sizeof(tq->buf_info[0]) * tq->tx_ring.size);
for (i = 0; i < tq->tx_ring.size; i++)
tq->buf_info[i].map_type = VMXNET3_MAP_NONE;
}
static int
vmxnet3_tq_create(struct vmxnet3_tx_queue *tq,
struct vmxnet3_adapter *adapter)
{
BUG_ON(tq->tx_ring.base || tq->data_ring.base ||
tq->comp_ring.base || tq->buf_info);
tq->tx_ring.base = pci_alloc_consistent(adapter->pdev, tq->tx_ring.size
* sizeof(struct Vmxnet3_TxDesc),
&tq->tx_ring.basePA);
if (!tq->tx_ring.base) {
printk(KERN_ERR "%s: failed to allocate tx ring\n",
adapter->netdev->name);
goto err;
}
tq->data_ring.base = pci_alloc_consistent(adapter->pdev,
tq->data_ring.size *
sizeof(struct Vmxnet3_TxDataDesc),
&tq->data_ring.basePA);
if (!tq->data_ring.base) {
printk(KERN_ERR "%s: failed to allocate data ring\n",
adapter->netdev->name);
goto err;
}
tq->comp_ring.base = pci_alloc_consistent(adapter->pdev,
tq->comp_ring.size *
sizeof(struct Vmxnet3_TxCompDesc),
&tq->comp_ring.basePA);
if (!tq->comp_ring.base) {
printk(KERN_ERR "%s: failed to allocate tx comp ring\n",
adapter->netdev->name);
goto err;
}
tq->buf_info = kcalloc(tq->tx_ring.size, sizeof(tq->buf_info[0]),
GFP_KERNEL);
if (!tq->buf_info)
goto err;
return 0;
err:
vmxnet3_tq_destroy(tq, adapter);
return -ENOMEM;
}
static void
vmxnet3_tq_cleanup_all(struct vmxnet3_adapter *adapter)
{
int i;
for (i = 0; i < adapter->num_tx_queues; i++)
vmxnet3_tq_cleanup(&adapter->tx_queue[i], adapter);
}
static int
vmxnet3_rq_alloc_rx_buf(struct vmxnet3_rx_queue *rq, u32 ring_idx,
int num_to_alloc, struct vmxnet3_adapter *adapter)
{
int num_allocated = 0;
struct vmxnet3_rx_buf_info *rbi_base = rq->buf_info[ring_idx];
struct vmxnet3_cmd_ring *ring = &rq->rx_ring[ring_idx];
u32 val;
while (num_allocated <= num_to_alloc) {
struct vmxnet3_rx_buf_info *rbi;
union Vmxnet3_GenericDesc *gd;
rbi = rbi_base + ring->next2fill;
gd = ring->base + ring->next2fill;
if (rbi->buf_type == VMXNET3_RX_BUF_SKB) {
if (rbi->skb == NULL) {
rbi->skb = dev_alloc_skb(rbi->len +
NET_IP_ALIGN);
if (unlikely(rbi->skb == NULL)) {
rq->stats.rx_buf_alloc_failure++;
break;
}
rbi->skb->dev = adapter->netdev;
skb_reserve(rbi->skb, NET_IP_ALIGN);
rbi->dma_addr = pci_map_single(adapter->pdev,
rbi->skb->data, rbi->len,
PCI_DMA_FROMDEVICE);
} else {
}
val = VMXNET3_RXD_BTYPE_HEAD << VMXNET3_RXD_BTYPE_SHIFT;
} else {
BUG_ON(rbi->buf_type != VMXNET3_RX_BUF_PAGE ||
rbi->len != PAGE_SIZE);
if (rbi->page == NULL) {
rbi->page = alloc_page(GFP_ATOMIC);
if (unlikely(rbi->page == NULL)) {
rq->stats.rx_buf_alloc_failure++;
break;
}
rbi->dma_addr = pci_map_page(adapter->pdev,
rbi->page, 0, PAGE_SIZE,
PCI_DMA_FROMDEVICE);
} else {
}
val = VMXNET3_RXD_BTYPE_BODY << VMXNET3_RXD_BTYPE_SHIFT;
}
BUG_ON(rbi->dma_addr == 0);
gd->rxd.addr = cpu_to_le64(rbi->dma_addr);
gd->dword[2] = cpu_to_le32((!ring->gen << VMXNET3_RXD_GEN_SHIFT)
| val | rbi->len);
if (num_allocated == num_to_alloc)
break;
gd->dword[2] |= cpu_to_le32(ring->gen << VMXNET3_RXD_GEN_SHIFT);
num_allocated++;
vmxnet3_cmd_ring_adv_next2fill(ring);
}
rq->uncommitted[ring_idx] += num_allocated;
dev_dbg(&adapter->netdev->dev,
"alloc_rx_buf: %d allocated, next2fill %u, next2comp "
"%u, uncommitted %u\n", num_allocated, ring->next2fill,
ring->next2comp, rq->uncommitted[ring_idx]);
BUG_ON(num_allocated != 0 && ring->next2fill == ring->next2comp);
return num_allocated;
}
static void
vmxnet3_append_frag(struct sk_buff *skb, struct Vmxnet3_RxCompDesc *rcd,
struct vmxnet3_rx_buf_info *rbi)
{
struct skb_frag_struct *frag = skb_shinfo(skb)->frags +
skb_shinfo(skb)->nr_frags;
BUG_ON(skb_shinfo(skb)->nr_frags >= MAX_SKB_FRAGS);
__skb_frag_set_page(frag, rbi->page);
frag->page_offset = 0;
skb_frag_size_set(frag, rcd->len);
skb->data_len += rcd->len;
skb->truesize += PAGE_SIZE;
skb_shinfo(skb)->nr_frags++;
}
static void
vmxnet3_map_pkt(struct sk_buff *skb, struct vmxnet3_tx_ctx *ctx,
struct vmxnet3_tx_queue *tq, struct pci_dev *pdev,
struct vmxnet3_adapter *adapter)
{
u32 dw2, len;
unsigned long buf_offset;
int i;
union Vmxnet3_GenericDesc *gdesc;
struct vmxnet3_tx_buf_info *tbi = NULL;
BUG_ON(ctx->copy_size > skb_headlen(skb));
dw2 = (tq->tx_ring.gen ^ 0x1) << VMXNET3_TXD_GEN_SHIFT;
ctx->sop_txd = tq->tx_ring.base + tq->tx_ring.next2fill;
gdesc = ctx->sop_txd;
if (ctx->copy_size) {
ctx->sop_txd->txd.addr = cpu_to_le64(tq->data_ring.basePA +
tq->tx_ring.next2fill *
sizeof(struct Vmxnet3_TxDataDesc));
ctx->sop_txd->dword[2] = cpu_to_le32(dw2 | ctx->copy_size);
ctx->sop_txd->dword[3] = 0;
tbi = tq->buf_info + tq->tx_ring.next2fill;
tbi->map_type = VMXNET3_MAP_NONE;
dev_dbg(&adapter->netdev->dev,
"txd[%u]: 0x%Lx 0x%x 0x%x\n",
tq->tx_ring.next2fill,
le64_to_cpu(ctx->sop_txd->txd.addr),
ctx->sop_txd->dword[2], ctx->sop_txd->dword[3]);
vmxnet3_cmd_ring_adv_next2fill(&tq->tx_ring);
dw2 = tq->tx_ring.gen << VMXNET3_TXD_GEN_SHIFT;
}
len = skb_headlen(skb) - ctx->copy_size;
buf_offset = ctx->copy_size;
while (len) {
u32 buf_size;
if (len < VMXNET3_MAX_TX_BUF_SIZE) {
buf_size = len;
dw2 |= len;
} else {
buf_size = VMXNET3_MAX_TX_BUF_SIZE;
}
tbi = tq->buf_info + tq->tx_ring.next2fill;
tbi->map_type = VMXNET3_MAP_SINGLE;
tbi->dma_addr = pci_map_single(adapter->pdev,
skb->data + buf_offset, buf_size,
PCI_DMA_TODEVICE);
tbi->len = buf_size;
gdesc = tq->tx_ring.base + tq->tx_ring.next2fill;
BUG_ON(gdesc->txd.gen == tq->tx_ring.gen);
gdesc->txd.addr = cpu_to_le64(tbi->dma_addr);
gdesc->dword[2] = cpu_to_le32(dw2);
gdesc->dword[3] = 0;
dev_dbg(&adapter->netdev->dev,
"txd[%u]: 0x%Lx 0x%x 0x%x\n",
tq->tx_ring.next2fill, le64_to_cpu(gdesc->txd.addr),
le32_to_cpu(gdesc->dword[2]), gdesc->dword[3]);
vmxnet3_cmd_ring_adv_next2fill(&tq->tx_ring);
dw2 = tq->tx_ring.gen << VMXNET3_TXD_GEN_SHIFT;
len -= buf_size;
buf_offset += buf_size;
}
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
const struct skb_frag_struct *frag = &skb_shinfo(skb)->frags[i];
u32 buf_size;
buf_offset = 0;
len = skb_frag_size(frag);
while (len) {
tbi = tq->buf_info + tq->tx_ring.next2fill;
if (len < VMXNET3_MAX_TX_BUF_SIZE) {
buf_size = len;
dw2 |= len;
} else {
buf_size = VMXNET3_MAX_TX_BUF_SIZE;
}
tbi->map_type = VMXNET3_MAP_PAGE;
tbi->dma_addr = skb_frag_dma_map(&adapter->pdev->dev, frag,
buf_offset, buf_size,
DMA_TO_DEVICE);
tbi->len = buf_size;
gdesc = tq->tx_ring.base + tq->tx_ring.next2fill;
BUG_ON(gdesc->txd.gen == tq->tx_ring.gen);
gdesc->txd.addr = cpu_to_le64(tbi->dma_addr);
gdesc->dword[2] = cpu_to_le32(dw2);
gdesc->dword[3] = 0;
dev_dbg(&adapter->netdev->dev,
"txd[%u]: 0x%llu %u %u\n",
tq->tx_ring.next2fill, le64_to_cpu(gdesc->txd.addr),
le32_to_cpu(gdesc->dword[2]), gdesc->dword[3]);
vmxnet3_cmd_ring_adv_next2fill(&tq->tx_ring);
dw2 = tq->tx_ring.gen << VMXNET3_TXD_GEN_SHIFT;
len -= buf_size;
buf_offset += buf_size;
}
}
ctx->eop_txd = gdesc;
tbi->skb = skb;
tbi->sop_idx = ctx->sop_txd - tq->tx_ring.base;
}
static void
vmxnet3_tq_init_all(struct vmxnet3_adapter *adapter)
{
int i;
for (i = 0; i < adapter->num_tx_queues; i++)
vmxnet3_tq_init(&adapter->tx_queue[i], adapter);
}
static int
vmxnet3_parse_and_copy_hdr(struct sk_buff *skb, struct vmxnet3_tx_queue *tq,
struct vmxnet3_tx_ctx *ctx,
struct vmxnet3_adapter *adapter)
{
struct Vmxnet3_TxDataDesc *tdd;
if (ctx->mss) {
ctx->eth_ip_hdr_size = skb_transport_offset(skb);
ctx->l4_hdr_size = tcp_hdrlen(skb);
ctx->copy_size = ctx->eth_ip_hdr_size + ctx->l4_hdr_size;
} else {
if (skb->ip_summed == CHECKSUM_PARTIAL) {
ctx->eth_ip_hdr_size = skb_checksum_start_offset(skb);
if (ctx->ipv4) {
const struct iphdr *iph = ip_hdr(skb);
if (iph->protocol == IPPROTO_TCP)
ctx->l4_hdr_size = tcp_hdrlen(skb);
else if (iph->protocol == IPPROTO_UDP)
ctx->l4_hdr_size = sizeof(struct udphdr);
else
ctx->l4_hdr_size = 0;
} else {
ctx->l4_hdr_size = 0;
}
ctx->copy_size = min(ctx->eth_ip_hdr_size +
ctx->l4_hdr_size, skb->len);
} else {
ctx->eth_ip_hdr_size = 0;
ctx->l4_hdr_size = 0;
ctx->copy_size = min((unsigned int)VMXNET3_HDR_COPY_SIZE
, skb_headlen(skb));
}
if (unlikely(!pskb_may_pull(skb, ctx->copy_size)))
goto err;
}
if (unlikely(ctx->copy_size > VMXNET3_HDR_COPY_SIZE)) {
tq->stats.oversized_hdr++;
ctx->copy_size = 0;
return 0;
}
tdd = tq->data_ring.base + tq->tx_ring.next2fill;
memcpy(tdd->data, skb->data, ctx->copy_size);
dev_dbg(&adapter->netdev->dev,
"copy %u bytes to dataRing[%u]\n",
ctx->copy_size, tq->tx_ring.next2fill);
return 1;
err:
return -1;
}
static void
vmxnet3_prepare_tso(struct sk_buff *skb,
struct vmxnet3_tx_ctx *ctx)
{
struct tcphdr *tcph = tcp_hdr(skb);
if (ctx->ipv4) {
struct iphdr *iph = ip_hdr(skb);
iph->check = 0;
tcph->check = ~csum_tcpudp_magic(iph->saddr, iph->daddr, 0,
IPPROTO_TCP, 0);
} else {
struct ipv6hdr *iph = ipv6_hdr(skb);
tcph->check = ~csum_ipv6_magic(&iph->saddr, &iph->daddr, 0,
IPPROTO_TCP, 0);
}
}
static int txd_estimate(const struct sk_buff *skb)
{
int count = VMXNET3_TXD_NEEDED(skb_headlen(skb)) + 1;
int i;
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
const struct skb_frag_struct *frag = &skb_shinfo(skb)->frags[i];
count += VMXNET3_TXD_NEEDED(skb_frag_size(frag));
}
return count;
}
static int
vmxnet3_tq_xmit(struct sk_buff *skb, struct vmxnet3_tx_queue *tq,
struct vmxnet3_adapter *adapter, struct net_device *netdev)
{
int ret;
u32 count;
unsigned long flags;
struct vmxnet3_tx_ctx ctx;
union Vmxnet3_GenericDesc *gdesc;
#ifdef __BIG_ENDIAN_BITFIELD
union Vmxnet3_GenericDesc tempTxDesc;
#endif
count = txd_estimate(skb);
ctx.ipv4 = (vlan_get_protocol(skb) == cpu_to_be16(ETH_P_IP));
ctx.mss = skb_shinfo(skb)->gso_size;
if (ctx.mss) {
if (skb_header_cloned(skb)) {
if (unlikely(pskb_expand_head(skb, 0, 0,
GFP_ATOMIC) != 0)) {
tq->stats.drop_tso++;
goto drop_pkt;
}
tq->stats.copy_skb_header++;
}
vmxnet3_prepare_tso(skb, &ctx);
} else {
if (unlikely(count > VMXNET3_MAX_TXD_PER_PKT)) {
if (skb_linearize(skb) != 0) {
tq->stats.drop_too_many_frags++;
goto drop_pkt;
}
tq->stats.linearized++;
count = VMXNET3_TXD_NEEDED(skb_headlen(skb)) + 1;
}
}
spin_lock_irqsave(&tq->tx_lock, flags);
if (count > vmxnet3_cmd_ring_desc_avail(&tq->tx_ring)) {
tq->stats.tx_ring_full++;
dev_dbg(&adapter->netdev->dev,
"tx queue stopped on %s, next2comp %u"
" next2fill %u\n", adapter->netdev->name,
tq->tx_ring.next2comp, tq->tx_ring.next2fill);
vmxnet3_tq_stop(tq, adapter);
spin_unlock_irqrestore(&tq->tx_lock, flags);
return NETDEV_TX_BUSY;
}
ret = vmxnet3_parse_and_copy_hdr(skb, tq, &ctx, adapter);
if (ret >= 0) {
BUG_ON(ret <= 0 && ctx.copy_size != 0);
if (ctx.mss) {
if (unlikely(ctx.eth_ip_hdr_size + ctx.l4_hdr_size >
VMXNET3_MAX_TX_BUF_SIZE)) {
goto hdr_too_big;
}
} else {
if (skb->ip_summed == CHECKSUM_PARTIAL) {
if (unlikely(ctx.eth_ip_hdr_size +
skb->csum_offset >
VMXNET3_MAX_CSUM_OFFSET)) {
goto hdr_too_big;
}
}
}
} else {
tq->stats.drop_hdr_inspect_err++;
goto unlock_drop_pkt;
}
vmxnet3_map_pkt(skb, &ctx, tq, adapter->pdev, adapter);
ctx.eop_txd->dword[3] = cpu_to_le32(VMXNET3_TXD_CQ | VMXNET3_TXD_EOP);
#ifdef __BIG_ENDIAN_BITFIELD
gdesc = &tempTxDesc;
gdesc->dword[2] = ctx.sop_txd->dword[2];
gdesc->dword[3] = ctx.sop_txd->dword[3];
#else
gdesc = ctx.sop_txd;
#endif
if (ctx.mss) {
gdesc->txd.hlen = ctx.eth_ip_hdr_size + ctx.l4_hdr_size;
gdesc->txd.om = VMXNET3_OM_TSO;
gdesc->txd.msscof = ctx.mss;
le32_add_cpu(&tq->shared->txNumDeferred, (skb->len -
gdesc->txd.hlen + ctx.mss - 1) / ctx.mss);
} else {
if (skb->ip_summed == CHECKSUM_PARTIAL) {
gdesc->txd.hlen = ctx.eth_ip_hdr_size;
gdesc->txd.om = VMXNET3_OM_CSUM;
gdesc->txd.msscof = ctx.eth_ip_hdr_size +
skb->csum_offset;
} else {
gdesc->txd.om = 0;
gdesc->txd.msscof = 0;
}
le32_add_cpu(&tq->shared->txNumDeferred, 1);
}
if (vlan_tx_tag_present(skb)) {
gdesc->txd.ti = 1;
gdesc->txd.tci = vlan_tx_tag_get(skb);
}
gdesc->dword[2] = cpu_to_le32(le32_to_cpu(gdesc->dword[2]) ^
VMXNET3_TXD_GEN);
#ifdef __BIG_ENDIAN_BITFIELD
vmxnet3_TxDescToLe((struct Vmxnet3_TxDesc *)gdesc,
(struct Vmxnet3_TxDesc *)ctx.sop_txd);
gdesc = ctx.sop_txd;
#endif
dev_dbg(&adapter->netdev->dev,
"txd[%u]: SOP 0x%Lx 0x%x 0x%x\n",
(u32)(ctx.sop_txd -
tq->tx_ring.base), le64_to_cpu(gdesc->txd.addr),
le32_to_cpu(gdesc->dword[2]), le32_to_cpu(gdesc->dword[3]));
spin_unlock_irqrestore(&tq->tx_lock, flags);
if (le32_to_cpu(tq->shared->txNumDeferred) >=
le32_to_cpu(tq->shared->txThreshold)) {
tq->shared->txNumDeferred = 0;
VMXNET3_WRITE_BAR0_REG(adapter,
VMXNET3_REG_TXPROD + tq->qid * 8,
tq->tx_ring.next2fill);
}
return NETDEV_TX_OK;
hdr_too_big:
tq->stats.drop_oversized_hdr++;
unlock_drop_pkt:
spin_unlock_irqrestore(&tq->tx_lock, flags);
drop_pkt:
tq->stats.drop_total++;
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static netdev_tx_t
vmxnet3_xmit_frame(struct sk_buff *skb, struct net_device *netdev)
{
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
BUG_ON(skb->queue_mapping > adapter->num_tx_queues);
return vmxnet3_tq_xmit(skb,
&adapter->tx_queue[skb->queue_mapping],
adapter, netdev);
}
static void
vmxnet3_rx_csum(struct vmxnet3_adapter *adapter,
struct sk_buff *skb,
union Vmxnet3_GenericDesc *gdesc)
{
if (!gdesc->rcd.cnc && adapter->netdev->features & NETIF_F_RXCSUM) {
if ((le32_to_cpu(gdesc->dword[3]) & VMXNET3_RCD_CSUM_OK) ==
VMXNET3_RCD_CSUM_OK) {
skb->ip_summed = CHECKSUM_UNNECESSARY;
BUG_ON(!(gdesc->rcd.tcp || gdesc->rcd.udp));
BUG_ON(!(gdesc->rcd.v4 || gdesc->rcd.v6));
BUG_ON(gdesc->rcd.frg);
} else {
if (gdesc->rcd.csum) {
skb->csum = htons(gdesc->rcd.csum);
skb->ip_summed = CHECKSUM_PARTIAL;
} else {
skb_checksum_none_assert(skb);
}
}
} else {
skb_checksum_none_assert(skb);
}
}
static void
vmxnet3_rx_error(struct vmxnet3_rx_queue *rq, struct Vmxnet3_RxCompDesc *rcd,
struct vmxnet3_rx_ctx *ctx, struct vmxnet3_adapter *adapter)
{
rq->stats.drop_err++;
if (!rcd->fcs)
rq->stats.drop_fcs++;
rq->stats.drop_total++;
if (ctx->skb)
dev_kfree_skb_irq(ctx->skb);
ctx->skb = NULL;
}
static int
vmxnet3_rq_rx_complete(struct vmxnet3_rx_queue *rq,
struct vmxnet3_adapter *adapter, int quota)
{
static const u32 rxprod_reg[2] = {
VMXNET3_REG_RXPROD, VMXNET3_REG_RXPROD2
};
u32 num_rxd = 0;
bool skip_page_frags = false;
struct Vmxnet3_RxCompDesc *rcd;
struct vmxnet3_rx_ctx *ctx = &rq->rx_ctx;
#ifdef __BIG_ENDIAN_BITFIELD
struct Vmxnet3_RxDesc rxCmdDesc;
struct Vmxnet3_RxCompDesc rxComp;
#endif
vmxnet3_getRxComp(rcd, &rq->comp_ring.base[rq->comp_ring.next2proc].rcd,
&rxComp);
while (rcd->gen == rq->comp_ring.gen) {
struct vmxnet3_rx_buf_info *rbi;
struct sk_buff *skb, *new_skb = NULL;
struct page *new_page = NULL;
int num_to_alloc;
struct Vmxnet3_RxDesc *rxd;
u32 idx, ring_idx;
struct vmxnet3_cmd_ring *ring = NULL;
if (num_rxd >= quota) {
break;
}
num_rxd++;
BUG_ON(rcd->rqID != rq->qid && rcd->rqID != rq->qid2);
idx = rcd->rxdIdx;
ring_idx = rcd->rqID < adapter->num_rx_queues ? 0 : 1;
ring = rq->rx_ring + ring_idx;
vmxnet3_getRxDesc(rxd, &rq->rx_ring[ring_idx].base[idx].rxd,
&rxCmdDesc);
rbi = rq->buf_info[ring_idx] + idx;
BUG_ON(rxd->addr != rbi->dma_addr ||
rxd->len != rbi->len);
if (unlikely(rcd->eop && rcd->err)) {
vmxnet3_rx_error(rq, rcd, ctx, adapter);
goto rcd_done;
}
if (rcd->sop) {
BUG_ON(rxd->btype != VMXNET3_RXD_BTYPE_HEAD ||
rcd->rqID != rq->qid);
BUG_ON(rbi->buf_type != VMXNET3_RX_BUF_SKB);
BUG_ON(ctx->skb != NULL || rbi->skb == NULL);
if (unlikely(rcd->len == 0)) {
BUG_ON(!(rcd->sop && rcd->eop));
dev_dbg(&adapter->netdev->dev,
"rxRing[%u][%u] 0 length\n",
ring_idx, idx);
goto rcd_done;
}
skip_page_frags = false;
ctx->skb = rbi->skb;
new_skb = dev_alloc_skb(rbi->len + NET_IP_ALIGN);
if (new_skb == NULL) {
rq->stats.rx_buf_alloc_failure++;
ctx->skb = NULL;
rq->stats.drop_total++;
skip_page_frags = true;
goto rcd_done;
}
pci_unmap_single(adapter->pdev, rbi->dma_addr, rbi->len,
PCI_DMA_FROMDEVICE);
skb_put(ctx->skb, rcd->len);
new_skb->dev = adapter->netdev;
skb_reserve(new_skb, NET_IP_ALIGN);
rbi->skb = new_skb;
rbi->dma_addr = pci_map_single(adapter->pdev,
rbi->skb->data, rbi->len,
PCI_DMA_FROMDEVICE);
rxd->addr = cpu_to_le64(rbi->dma_addr);
rxd->len = rbi->len;
} else {
BUG_ON(ctx->skb == NULL && !skip_page_frags);
BUG_ON(rbi->buf_type != VMXNET3_RX_BUF_PAGE);
BUG_ON(rxd->btype != VMXNET3_RXD_BTYPE_BODY);
if (skip_page_frags)
goto rcd_done;
new_page = alloc_page(GFP_ATOMIC);
if (unlikely(new_page == NULL)) {
rq->stats.rx_buf_alloc_failure++;
dev_kfree_skb(ctx->skb);
ctx->skb = NULL;
skip_page_frags = true;
goto rcd_done;
}
if (rcd->len) {
pci_unmap_page(adapter->pdev,
rbi->dma_addr, rbi->len,
PCI_DMA_FROMDEVICE);
vmxnet3_append_frag(ctx->skb, rcd, rbi);
}
rbi->page = new_page;
rbi->dma_addr = pci_map_page(adapter->pdev, rbi->page,
0, PAGE_SIZE,
PCI_DMA_FROMDEVICE);
rxd->addr = cpu_to_le64(rbi->dma_addr);
rxd->len = rbi->len;
}
skb = ctx->skb;
if (rcd->eop) {
skb->len += skb->data_len;
vmxnet3_rx_csum(adapter, skb,
(union Vmxnet3_GenericDesc *)rcd);
skb->protocol = eth_type_trans(skb, adapter->netdev);
if (unlikely(rcd->ts))
__vlan_hwaccel_put_tag(skb, rcd->tci);
if (adapter->netdev->features & NETIF_F_LRO)
netif_receive_skb(skb);
else
napi_gro_receive(&rq->napi, skb);
ctx->skb = NULL;
}
rcd_done:
ring->next2comp = idx;
num_to_alloc = vmxnet3_cmd_ring_desc_avail(ring);
ring = rq->rx_ring + ring_idx;
while (num_to_alloc) {
vmxnet3_getRxDesc(rxd, &ring->base[ring->next2fill].rxd,
&rxCmdDesc);
BUG_ON(!rxd->addr);
rxd->gen = ring->gen;
vmxnet3_cmd_ring_adv_next2fill(ring);
num_to_alloc--;
}
if (unlikely(rq->shared->updateRxProd)) {
VMXNET3_WRITE_BAR0_REG(adapter,
rxprod_reg[ring_idx] + rq->qid * 8,
ring->next2fill);
rq->uncommitted[ring_idx] = 0;
}
vmxnet3_comp_ring_adv_next2proc(&rq->comp_ring);
vmxnet3_getRxComp(rcd,
&rq->comp_ring.base[rq->comp_ring.next2proc].rcd, &rxComp);
}
return num_rxd;
}
static void
vmxnet3_rq_cleanup(struct vmxnet3_rx_queue *rq,
struct vmxnet3_adapter *adapter)
{
u32 i, ring_idx;
struct Vmxnet3_RxDesc *rxd;
for (ring_idx = 0; ring_idx < 2; ring_idx++) {
for (i = 0; i < rq->rx_ring[ring_idx].size; i++) {
#ifdef __BIG_ENDIAN_BITFIELD
struct Vmxnet3_RxDesc rxDesc;
#endif
vmxnet3_getRxDesc(rxd,
&rq->rx_ring[ring_idx].base[i].rxd, &rxDesc);
if (rxd->btype == VMXNET3_RXD_BTYPE_HEAD &&
rq->buf_info[ring_idx][i].skb) {
pci_unmap_single(adapter->pdev, rxd->addr,
rxd->len, PCI_DMA_FROMDEVICE);
dev_kfree_skb(rq->buf_info[ring_idx][i].skb);
rq->buf_info[ring_idx][i].skb = NULL;
} else if (rxd->btype == VMXNET3_RXD_BTYPE_BODY &&
rq->buf_info[ring_idx][i].page) {
pci_unmap_page(adapter->pdev, rxd->addr,
rxd->len, PCI_DMA_FROMDEVICE);
put_page(rq->buf_info[ring_idx][i].page);
rq->buf_info[ring_idx][i].page = NULL;
}
}
rq->rx_ring[ring_idx].gen = VMXNET3_INIT_GEN;
rq->rx_ring[ring_idx].next2fill =
rq->rx_ring[ring_idx].next2comp = 0;
rq->uncommitted[ring_idx] = 0;
}
rq->comp_ring.gen = VMXNET3_INIT_GEN;
rq->comp_ring.next2proc = 0;
}
static void
vmxnet3_rq_cleanup_all(struct vmxnet3_adapter *adapter)
{
int i;
for (i = 0; i < adapter->num_rx_queues; i++)
vmxnet3_rq_cleanup(&adapter->rx_queue[i], adapter);
}
void vmxnet3_rq_destroy(struct vmxnet3_rx_queue *rq,
struct vmxnet3_adapter *adapter)
{
int i;
int j;
for (i = 0; i < 2; i++) {
if (rq->buf_info[i]) {
for (j = 0; j < rq->rx_ring[i].size; j++)
BUG_ON(rq->buf_info[i][j].page != NULL);
}
}
kfree(rq->buf_info[0]);
for (i = 0; i < 2; i++) {
if (rq->rx_ring[i].base) {
pci_free_consistent(adapter->pdev, rq->rx_ring[i].size
* sizeof(struct Vmxnet3_RxDesc),
rq->rx_ring[i].base,
rq->rx_ring[i].basePA);
rq->rx_ring[i].base = NULL;
}
rq->buf_info[i] = NULL;
}
if (rq->comp_ring.base) {
pci_free_consistent(adapter->pdev, rq->comp_ring.size *
sizeof(struct Vmxnet3_RxCompDesc),
rq->comp_ring.base, rq->comp_ring.basePA);
rq->comp_ring.base = NULL;
}
}
static int
vmxnet3_rq_init(struct vmxnet3_rx_queue *rq,
struct vmxnet3_adapter *adapter)
{
int i;
for (i = 0; i < rq->rx_ring[0].size; i++) {
if (i % adapter->rx_buf_per_pkt == 0) {
rq->buf_info[0][i].buf_type = VMXNET3_RX_BUF_SKB;
rq->buf_info[0][i].len = adapter->skb_buf_size;
} else {
rq->buf_info[0][i].buf_type = VMXNET3_RX_BUF_PAGE;
rq->buf_info[0][i].len = PAGE_SIZE;
}
}
for (i = 0; i < rq->rx_ring[1].size; i++) {
rq->buf_info[1][i].buf_type = VMXNET3_RX_BUF_PAGE;
rq->buf_info[1][i].len = PAGE_SIZE;
}
for (i = 0; i < 2; i++) {
rq->rx_ring[i].next2fill = rq->rx_ring[i].next2comp = 0;
rq->uncommitted[i] = 0;
memset(rq->rx_ring[i].base, 0, rq->rx_ring[i].size *
sizeof(struct Vmxnet3_RxDesc));
rq->rx_ring[i].gen = VMXNET3_INIT_GEN;
}
if (vmxnet3_rq_alloc_rx_buf(rq, 0, rq->rx_ring[0].size - 1,
adapter) == 0) {
return -ENOMEM;
}
vmxnet3_rq_alloc_rx_buf(rq, 1, rq->rx_ring[1].size - 1, adapter);
rq->comp_ring.next2proc = 0;
memset(rq->comp_ring.base, 0, rq->comp_ring.size *
sizeof(struct Vmxnet3_RxCompDesc));
rq->comp_ring.gen = VMXNET3_INIT_GEN;
rq->rx_ctx.skb = NULL;
return 0;
}
static int
vmxnet3_rq_init_all(struct vmxnet3_adapter *adapter)
{
int i, err = 0;
for (i = 0; i < adapter->num_rx_queues; i++) {
err = vmxnet3_rq_init(&adapter->rx_queue[i], adapter);
if (unlikely(err)) {
dev_err(&adapter->netdev->dev, "%s: failed to "
"initialize rx queue%i\n",
adapter->netdev->name, i);
break;
}
}
return err;
}
static int
vmxnet3_rq_create(struct vmxnet3_rx_queue *rq, struct vmxnet3_adapter *adapter)
{
int i;
size_t sz;
struct vmxnet3_rx_buf_info *bi;
for (i = 0; i < 2; i++) {
sz = rq->rx_ring[i].size * sizeof(struct Vmxnet3_RxDesc);
rq->rx_ring[i].base = pci_alloc_consistent(adapter->pdev, sz,
&rq->rx_ring[i].basePA);
if (!rq->rx_ring[i].base) {
printk(KERN_ERR "%s: failed to allocate rx ring %d\n",
adapter->netdev->name, i);
goto err;
}
}
sz = rq->comp_ring.size * sizeof(struct Vmxnet3_RxCompDesc);
rq->comp_ring.base = pci_alloc_consistent(adapter->pdev, sz,
&rq->comp_ring.basePA);
if (!rq->comp_ring.base) {
printk(KERN_ERR "%s: failed to allocate rx comp ring\n",
adapter->netdev->name);
goto err;
}
sz = sizeof(struct vmxnet3_rx_buf_info) * (rq->rx_ring[0].size +
rq->rx_ring[1].size);
bi = kzalloc(sz, GFP_KERNEL);
if (!bi)
goto err;
rq->buf_info[0] = bi;
rq->buf_info[1] = bi + rq->rx_ring[0].size;
return 0;
err:
vmxnet3_rq_destroy(rq, adapter);
return -ENOMEM;
}
static int
vmxnet3_rq_create_all(struct vmxnet3_adapter *adapter)
{
int i, err = 0;
for (i = 0; i < adapter->num_rx_queues; i++) {
err = vmxnet3_rq_create(&adapter->rx_queue[i], adapter);
if (unlikely(err)) {
dev_err(&adapter->netdev->dev,
"%s: failed to create rx queue%i\n",
adapter->netdev->name, i);
goto err_out;
}
}
return err;
err_out:
vmxnet3_rq_destroy_all(adapter);
return err;
}
static int
vmxnet3_do_poll(struct vmxnet3_adapter *adapter, int budget)
{
int rcd_done = 0, i;
if (unlikely(adapter->shared->ecr))
vmxnet3_process_events(adapter);
for (i = 0; i < adapter->num_tx_queues; i++)
vmxnet3_tq_tx_complete(&adapter->tx_queue[i], adapter);
for (i = 0; i < adapter->num_rx_queues; i++)
rcd_done += vmxnet3_rq_rx_complete(&adapter->rx_queue[i],
adapter, budget);
return rcd_done;
}
static int
vmxnet3_poll(struct napi_struct *napi, int budget)
{
struct vmxnet3_rx_queue *rx_queue = container_of(napi,
struct vmxnet3_rx_queue, napi);
int rxd_done;
rxd_done = vmxnet3_do_poll(rx_queue->adapter, budget);
if (rxd_done < budget) {
napi_complete(napi);
vmxnet3_enable_all_intrs(rx_queue->adapter);
}
return rxd_done;
}
static int
vmxnet3_poll_rx_only(struct napi_struct *napi, int budget)
{
struct vmxnet3_rx_queue *rq = container_of(napi,
struct vmxnet3_rx_queue, napi);
struct vmxnet3_adapter *adapter = rq->adapter;
int rxd_done;
if (adapter->share_intr == VMXNET3_INTR_BUDDYSHARE) {
struct vmxnet3_tx_queue *tq =
&adapter->tx_queue[rq - adapter->rx_queue];
vmxnet3_tq_tx_complete(tq, adapter);
}
rxd_done = vmxnet3_rq_rx_complete(rq, adapter, budget);
if (rxd_done < budget) {
napi_complete(napi);
vmxnet3_enable_intr(adapter, rq->comp_ring.intr_idx);
}
return rxd_done;
}
static irqreturn_t
vmxnet3_msix_tx(int irq, void *data)
{
struct vmxnet3_tx_queue *tq = data;
struct vmxnet3_adapter *adapter = tq->adapter;
if (adapter->intr.mask_mode == VMXNET3_IMM_ACTIVE)
vmxnet3_disable_intr(adapter, tq->comp_ring.intr_idx);
if (adapter->share_intr == VMXNET3_INTR_TXSHARE) {
int i;
for (i = 0; i < adapter->num_tx_queues; i++) {
struct vmxnet3_tx_queue *txq = &adapter->tx_queue[i];
vmxnet3_tq_tx_complete(txq, adapter);
}
} else {
vmxnet3_tq_tx_complete(tq, adapter);
}
vmxnet3_enable_intr(adapter, tq->comp_ring.intr_idx);
return IRQ_HANDLED;
}
static irqreturn_t
vmxnet3_msix_rx(int irq, void *data)
{
struct vmxnet3_rx_queue *rq = data;
struct vmxnet3_adapter *adapter = rq->adapter;
if (adapter->intr.mask_mode == VMXNET3_IMM_ACTIVE)
vmxnet3_disable_intr(adapter, rq->comp_ring.intr_idx);
napi_schedule(&rq->napi);
return IRQ_HANDLED;
}
static irqreturn_t
vmxnet3_msix_event(int irq, void *data)
{
struct net_device *dev = data;
struct vmxnet3_adapter *adapter = netdev_priv(dev);
if (adapter->intr.mask_mode == VMXNET3_IMM_ACTIVE)
vmxnet3_disable_intr(adapter, adapter->intr.event_intr_idx);
if (adapter->shared->ecr)
vmxnet3_process_events(adapter);
vmxnet3_enable_intr(adapter, adapter->intr.event_intr_idx);
return IRQ_HANDLED;
}
static irqreturn_t
vmxnet3_intr(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct vmxnet3_adapter *adapter = netdev_priv(dev);
if (adapter->intr.type == VMXNET3_IT_INTX) {
u32 icr = VMXNET3_READ_BAR1_REG(adapter, VMXNET3_REG_ICR);
if (unlikely(icr == 0))
return IRQ_NONE;
}
if (adapter->intr.mask_mode == VMXNET3_IMM_ACTIVE)
vmxnet3_disable_all_intrs(adapter);
napi_schedule(&adapter->rx_queue[0].napi);
return IRQ_HANDLED;
}
static void
vmxnet3_netpoll(struct net_device *netdev)
{
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
if (adapter->intr.mask_mode == VMXNET3_IMM_ACTIVE)
vmxnet3_disable_all_intrs(adapter);
vmxnet3_do_poll(adapter, adapter->rx_queue[0].rx_ring[0].size);
vmxnet3_enable_all_intrs(adapter);
}
static int
vmxnet3_request_irqs(struct vmxnet3_adapter *adapter)
{
struct vmxnet3_intr *intr = &adapter->intr;
int err = 0, i;
int vector = 0;
#ifdef CONFIG_PCI_MSI
if (adapter->intr.type == VMXNET3_IT_MSIX) {
for (i = 0; i < adapter->num_tx_queues; i++) {
if (adapter->share_intr != VMXNET3_INTR_BUDDYSHARE) {
sprintf(adapter->tx_queue[i].name, "%s-tx-%d",
adapter->netdev->name, vector);
err = request_irq(
intr->msix_entries[vector].vector,
vmxnet3_msix_tx, 0,
adapter->tx_queue[i].name,
&adapter->tx_queue[i]);
} else {
sprintf(adapter->tx_queue[i].name, "%s-rxtx-%d",
adapter->netdev->name, vector);
}
if (err) {
dev_err(&adapter->netdev->dev,
"Failed to request irq for MSIX, %s, "
"error %d\n",
adapter->tx_queue[i].name, err);
return err;
}
if (adapter->share_intr == VMXNET3_INTR_TXSHARE) {
for (; i < adapter->num_tx_queues; i++)
adapter->tx_queue[i].comp_ring.intr_idx
= vector;
vector++;
break;
} else {
adapter->tx_queue[i].comp_ring.intr_idx
= vector++;
}
}
if (adapter->share_intr == VMXNET3_INTR_BUDDYSHARE)
vector = 0;
for (i = 0; i < adapter->num_rx_queues; i++) {
if (adapter->share_intr != VMXNET3_INTR_BUDDYSHARE)
sprintf(adapter->rx_queue[i].name, "%s-rx-%d",
adapter->netdev->name, vector);
else
sprintf(adapter->rx_queue[i].name, "%s-rxtx-%d",
adapter->netdev->name, vector);
err = request_irq(intr->msix_entries[vector].vector,
vmxnet3_msix_rx, 0,
adapter->rx_queue[i].name,
&(adapter->rx_queue[i]));
if (err) {
printk(KERN_ERR "Failed to request irq for MSIX"
", %s, error %d\n",
adapter->rx_queue[i].name, err);
return err;
}
adapter->rx_queue[i].comp_ring.intr_idx = vector++;
}
sprintf(intr->event_msi_vector_name, "%s-event-%d",
adapter->netdev->name, vector);
err = request_irq(intr->msix_entries[vector].vector,
vmxnet3_msix_event, 0,
intr->event_msi_vector_name, adapter->netdev);
intr->event_intr_idx = vector;
} else if (intr->type == VMXNET3_IT_MSI) {
adapter->num_rx_queues = 1;
err = request_irq(adapter->pdev->irq, vmxnet3_intr, 0,
adapter->netdev->name, adapter->netdev);
} else {
#endif
adapter->num_rx_queues = 1;
err = request_irq(adapter->pdev->irq, vmxnet3_intr,
IRQF_SHARED, adapter->netdev->name,
adapter->netdev);
#ifdef CONFIG_PCI_MSI
}
#endif
intr->num_intrs = vector + 1;
if (err) {
printk(KERN_ERR "Failed to request irq %s (intr type:%d), error"
":%d\n", adapter->netdev->name, intr->type, err);
} else {
for (i = 0; i < adapter->num_rx_queues; i++) {
struct vmxnet3_rx_queue *rq = &adapter->rx_queue[i];
rq->qid = i;
rq->qid2 = i + adapter->num_rx_queues;
}
for (i = 0; i < intr->num_intrs; i++)
intr->mod_levels[i] = UPT1_IML_ADAPTIVE;
if (adapter->intr.type != VMXNET3_IT_MSIX) {
adapter->intr.event_intr_idx = 0;
for (i = 0; i < adapter->num_tx_queues; i++)
adapter->tx_queue[i].comp_ring.intr_idx = 0;
adapter->rx_queue[0].comp_ring.intr_idx = 0;
}
printk(KERN_INFO "%s: intr type %u, mode %u, %u vectors "
"allocated\n", adapter->netdev->name, intr->type,
intr->mask_mode, intr->num_intrs);
}
return err;
}
static void
vmxnet3_free_irqs(struct vmxnet3_adapter *adapter)
{
struct vmxnet3_intr *intr = &adapter->intr;
BUG_ON(intr->type == VMXNET3_IT_AUTO || intr->num_intrs <= 0);
switch (intr->type) {
#ifdef CONFIG_PCI_MSI
case VMXNET3_IT_MSIX:
{
int i, vector = 0;
if (adapter->share_intr != VMXNET3_INTR_BUDDYSHARE) {
for (i = 0; i < adapter->num_tx_queues; i++) {
free_irq(intr->msix_entries[vector++].vector,
&(adapter->tx_queue[i]));
if (adapter->share_intr == VMXNET3_INTR_TXSHARE)
break;
}
}
for (i = 0; i < adapter->num_rx_queues; i++) {
free_irq(intr->msix_entries[vector++].vector,
&(adapter->rx_queue[i]));
}
free_irq(intr->msix_entries[vector].vector,
adapter->netdev);
BUG_ON(vector >= intr->num_intrs);
break;
}
#endif
case VMXNET3_IT_MSI:
free_irq(adapter->pdev->irq, adapter->netdev);
break;
case VMXNET3_IT_INTX:
free_irq(adapter->pdev->irq, adapter->netdev);
break;
default:
BUG_ON(true);
}
}
static void
vmxnet3_restore_vlan(struct vmxnet3_adapter *adapter)
{
u32 *vfTable = adapter->shared->devRead.rxFilterConf.vfTable;
u16 vid;
VMXNET3_SET_VFTABLE_ENTRY(vfTable, 0);
for_each_set_bit(vid, adapter->active_vlans, VLAN_N_VID)
VMXNET3_SET_VFTABLE_ENTRY(vfTable, vid);
}
static int
vmxnet3_vlan_rx_add_vid(struct net_device *netdev, u16 vid)
{
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
if (!(netdev->flags & IFF_PROMISC)) {
u32 *vfTable = adapter->shared->devRead.rxFilterConf.vfTable;
unsigned long flags;
VMXNET3_SET_VFTABLE_ENTRY(vfTable, vid);
spin_lock_irqsave(&adapter->cmd_lock, flags);
VMXNET3_WRITE_BAR1_REG(adapter, VMXNET3_REG_CMD,
VMXNET3_CMD_UPDATE_VLAN_FILTERS);
spin_unlock_irqrestore(&adapter->cmd_lock, flags);
}
set_bit(vid, adapter->active_vlans);
return 0;
}
static int
vmxnet3_vlan_rx_kill_vid(struct net_device *netdev, u16 vid)
{
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
if (!(netdev->flags & IFF_PROMISC)) {
u32 *vfTable = adapter->shared->devRead.rxFilterConf.vfTable;
unsigned long flags;
VMXNET3_CLEAR_VFTABLE_ENTRY(vfTable, vid);
spin_lock_irqsave(&adapter->cmd_lock, flags);
VMXNET3_WRITE_BAR1_REG(adapter, VMXNET3_REG_CMD,
VMXNET3_CMD_UPDATE_VLAN_FILTERS);
spin_unlock_irqrestore(&adapter->cmd_lock, flags);
}
clear_bit(vid, adapter->active_vlans);
return 0;
}
static u8 *
vmxnet3_copy_mc(struct net_device *netdev)
{
u8 *buf = NULL;
u32 sz = netdev_mc_count(netdev) * ETH_ALEN;
if (sz <= 0xffff) {
buf = kmalloc(sz, GFP_ATOMIC);
if (buf) {
struct netdev_hw_addr *ha;
int i = 0;
netdev_for_each_mc_addr(ha, netdev)
memcpy(buf + i++ * ETH_ALEN, ha->addr,
ETH_ALEN);
}
}
return buf;
}
static void
vmxnet3_set_mc(struct net_device *netdev)
{
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
unsigned long flags;
struct Vmxnet3_RxFilterConf *rxConf =
&adapter->shared->devRead.rxFilterConf;
u8 *new_table = NULL;
u32 new_mode = VMXNET3_RXM_UCAST;
if (netdev->flags & IFF_PROMISC) {
u32 *vfTable = adapter->shared->devRead.rxFilterConf.vfTable;
memset(vfTable, 0, VMXNET3_VFT_SIZE * sizeof(*vfTable));
new_mode |= VMXNET3_RXM_PROMISC;
} else {
vmxnet3_restore_vlan(adapter);
}
if (netdev->flags & IFF_BROADCAST)
new_mode |= VMXNET3_RXM_BCAST;
if (netdev->flags & IFF_ALLMULTI)
new_mode |= VMXNET3_RXM_ALL_MULTI;
else
if (!netdev_mc_empty(netdev)) {
new_table = vmxnet3_copy_mc(netdev);
if (new_table) {
new_mode |= VMXNET3_RXM_MCAST;
rxConf->mfTableLen = cpu_to_le16(
netdev_mc_count(netdev) * ETH_ALEN);
rxConf->mfTablePA = cpu_to_le64(virt_to_phys(
new_table));
} else {
printk(KERN_INFO "%s: failed to copy mcast list"
", setting ALL_MULTI\n", netdev->name);
new_mode |= VMXNET3_RXM_ALL_MULTI;
}
}
if (!(new_mode & VMXNET3_RXM_MCAST)) {
rxConf->mfTableLen = 0;
rxConf->mfTablePA = 0;
}
spin_lock_irqsave(&adapter->cmd_lock, flags);
if (new_mode != rxConf->rxMode) {
rxConf->rxMode = cpu_to_le32(new_mode);
VMXNET3_WRITE_BAR1_REG(adapter, VMXNET3_REG_CMD,
VMXNET3_CMD_UPDATE_RX_MODE);
VMXNET3_WRITE_BAR1_REG(adapter, VMXNET3_REG_CMD,
VMXNET3_CMD_UPDATE_VLAN_FILTERS);
}
VMXNET3_WRITE_BAR1_REG(adapter, VMXNET3_REG_CMD,
VMXNET3_CMD_UPDATE_MAC_FILTERS);
spin_unlock_irqrestore(&adapter->cmd_lock, flags);
kfree(new_table);
}
void
vmxnet3_rq_destroy_all(struct vmxnet3_adapter *adapter)
{
int i;
for (i = 0; i < adapter->num_rx_queues; i++)
vmxnet3_rq_destroy(&adapter->rx_queue[i], adapter);
}
static void
vmxnet3_setup_driver_shared(struct vmxnet3_adapter *adapter)
{
struct Vmxnet3_DriverShared *shared = adapter->shared;
struct Vmxnet3_DSDevRead *devRead = &shared->devRead;
struct Vmxnet3_TxQueueConf *tqc;
struct Vmxnet3_RxQueueConf *rqc;
int i;
memset(shared, 0, sizeof(*shared));
shared->magic = cpu_to_le32(VMXNET3_REV1_MAGIC);
devRead->misc.driverInfo.version = cpu_to_le32(
VMXNET3_DRIVER_VERSION_NUM);
devRead->misc.driverInfo.gos.gosBits = (sizeof(void *) == 4 ?
VMXNET3_GOS_BITS_32 : VMXNET3_GOS_BITS_64);
devRead->misc.driverInfo.gos.gosType = VMXNET3_GOS_TYPE_LINUX;
*((u32 *)&devRead->misc.driverInfo.gos) = cpu_to_le32(
*((u32 *)&devRead->misc.driverInfo.gos));
devRead->misc.driverInfo.vmxnet3RevSpt = cpu_to_le32(1);
devRead->misc.driverInfo.uptVerSpt = cpu_to_le32(1);
devRead->misc.ddPA = cpu_to_le64(virt_to_phys(adapter));
devRead->misc.ddLen = cpu_to_le32(sizeof(struct vmxnet3_adapter));
if (adapter->netdev->features & NETIF_F_RXCSUM)
devRead->misc.uptFeatures |= UPT1_F_RXCSUM;
if (adapter->netdev->features & NETIF_F_LRO) {
devRead->misc.uptFeatures |= UPT1_F_LRO;
devRead->misc.maxNumRxSG = cpu_to_le16(1 + MAX_SKB_FRAGS);
}
if (adapter->netdev->features & NETIF_F_HW_VLAN_RX)
devRead->misc.uptFeatures |= UPT1_F_RXVLAN;
devRead->misc.mtu = cpu_to_le32(adapter->netdev->mtu);
devRead->misc.queueDescPA = cpu_to_le64(adapter->queue_desc_pa);
devRead->misc.queueDescLen = cpu_to_le32(
adapter->num_tx_queues * sizeof(struct Vmxnet3_TxQueueDesc) +
adapter->num_rx_queues * sizeof(struct Vmxnet3_RxQueueDesc));
devRead->misc.numTxQueues = adapter->num_tx_queues;
for (i = 0; i < adapter->num_tx_queues; i++) {
struct vmxnet3_tx_queue *tq = &adapter->tx_queue[i];
BUG_ON(adapter->tx_queue[i].tx_ring.base == NULL);
tqc = &adapter->tqd_start[i].conf;
tqc->txRingBasePA = cpu_to_le64(tq->tx_ring.basePA);
tqc->dataRingBasePA = cpu_to_le64(tq->data_ring.basePA);
tqc->compRingBasePA = cpu_to_le64(tq->comp_ring.basePA);
tqc->ddPA = cpu_to_le64(virt_to_phys(tq->buf_info));
tqc->txRingSize = cpu_to_le32(tq->tx_ring.size);
tqc->dataRingSize = cpu_to_le32(tq->data_ring.size);
tqc->compRingSize = cpu_to_le32(tq->comp_ring.size);
tqc->ddLen = cpu_to_le32(
sizeof(struct vmxnet3_tx_buf_info) *
tqc->txRingSize);
tqc->intrIdx = tq->comp_ring.intr_idx;
}
devRead->misc.numRxQueues = adapter->num_rx_queues;
for (i = 0; i < adapter->num_rx_queues; i++) {
struct vmxnet3_rx_queue *rq = &adapter->rx_queue[i];
rqc = &adapter->rqd_start[i].conf;
rqc->rxRingBasePA[0] = cpu_to_le64(rq->rx_ring[0].basePA);
rqc->rxRingBasePA[1] = cpu_to_le64(rq->rx_ring[1].basePA);
rqc->compRingBasePA = cpu_to_le64(rq->comp_ring.basePA);
rqc->ddPA = cpu_to_le64(virt_to_phys(
rq->buf_info));
rqc->rxRingSize[0] = cpu_to_le32(rq->rx_ring[0].size);
rqc->rxRingSize[1] = cpu_to_le32(rq->rx_ring[1].size);
rqc->compRingSize = cpu_to_le32(rq->comp_ring.size);
rqc->ddLen = cpu_to_le32(
sizeof(struct vmxnet3_rx_buf_info) *
(rqc->rxRingSize[0] +
rqc->rxRingSize[1]));
rqc->intrIdx = rq->comp_ring.intr_idx;
}
#ifdef VMXNET3_RSS
memset(adapter->rss_conf, 0, sizeof(*adapter->rss_conf));
if (adapter->rss) {
struct UPT1_RSSConf *rssConf = adapter->rss_conf;
devRead->misc.uptFeatures |= UPT1_F_RSS;
devRead->misc.numRxQueues = adapter->num_rx_queues;
rssConf->hashType = UPT1_RSS_HASH_TYPE_TCP_IPV4 |
UPT1_RSS_HASH_TYPE_IPV4 |
UPT1_RSS_HASH_TYPE_TCP_IPV6 |
UPT1_RSS_HASH_TYPE_IPV6;
rssConf->hashFunc = UPT1_RSS_HASH_FUNC_TOEPLITZ;
rssConf->hashKeySize = UPT1_RSS_MAX_KEY_SIZE;
rssConf->indTableSize = VMXNET3_RSS_IND_TABLE_SIZE;
get_random_bytes(&rssConf->hashKey[0], rssConf->hashKeySize);
for (i = 0; i < rssConf->indTableSize; i++)
rssConf->indTable[i] = ethtool_rxfh_indir_default(
i, adapter->num_rx_queues);
devRead->rssConfDesc.confVer = 1;
devRead->rssConfDesc.confLen = sizeof(*rssConf);
devRead->rssConfDesc.confPA = virt_to_phys(rssConf);
}
#endif
devRead->intrConf.autoMask = adapter->intr.mask_mode ==
VMXNET3_IMM_AUTO;
devRead->intrConf.numIntrs = adapter->intr.num_intrs;
for (i = 0; i < adapter->intr.num_intrs; i++)
devRead->intrConf.modLevels[i] = adapter->intr.mod_levels[i];
devRead->intrConf.eventIntrIdx = adapter->intr.event_intr_idx;
devRead->intrConf.intrCtrl |= cpu_to_le32(VMXNET3_IC_DISABLE_ALL);
devRead->rxFilterConf.rxMode = 0;
vmxnet3_restore_vlan(adapter);
vmxnet3_write_mac_addr(adapter, adapter->netdev->dev_addr);
}
int
vmxnet3_activate_dev(struct vmxnet3_adapter *adapter)
{
int err, i;
u32 ret;
unsigned long flags;
dev_dbg(&adapter->netdev->dev, "%s: skb_buf_size %d, rx_buf_per_pkt %d,"
" ring sizes %u %u %u\n", adapter->netdev->name,
adapter->skb_buf_size, adapter->rx_buf_per_pkt,
adapter->tx_queue[0].tx_ring.size,
adapter->rx_queue[0].rx_ring[0].size,
adapter->rx_queue[0].rx_ring[1].size);
vmxnet3_tq_init_all(adapter);
err = vmxnet3_rq_init_all(adapter);
if (err) {
printk(KERN_ERR "Failed to init rx queue for %s: error %d\n",
adapter->netdev->name, err);
goto rq_err;
}
err = vmxnet3_request_irqs(adapter);
if (err) {
printk(KERN_ERR "Failed to setup irq for %s: error %d\n",
adapter->netdev->name, err);
goto irq_err;
}
vmxnet3_setup_driver_shared(adapter);
VMXNET3_WRITE_BAR1_REG(adapter, VMXNET3_REG_DSAL, VMXNET3_GET_ADDR_LO(
adapter->shared_pa));
VMXNET3_WRITE_BAR1_REG(adapter, VMXNET3_REG_DSAH, VMXNET3_GET_ADDR_HI(
adapter->shared_pa));
spin_lock_irqsave(&adapter->cmd_lock, flags);
VMXNET3_WRITE_BAR1_REG(adapter, VMXNET3_REG_CMD,
VMXNET3_CMD_ACTIVATE_DEV);
ret = VMXNET3_READ_BAR1_REG(adapter, VMXNET3_REG_CMD);
spin_unlock_irqrestore(&adapter->cmd_lock, flags);
if (ret != 0) {
printk(KERN_ERR "Failed to activate dev %s: error %u\n",
adapter->netdev->name, ret);
err = -EINVAL;
goto activate_err;
}
for (i = 0; i < adapter->num_rx_queues; i++) {
VMXNET3_WRITE_BAR0_REG(adapter,
VMXNET3_REG_RXPROD + i * VMXNET3_REG_ALIGN,
adapter->rx_queue[i].rx_ring[0].next2fill);
VMXNET3_WRITE_BAR0_REG(adapter, (VMXNET3_REG_RXPROD2 +
(i * VMXNET3_REG_ALIGN)),
adapter->rx_queue[i].rx_ring[1].next2fill);
}
vmxnet3_set_mc(adapter->netdev);
vmxnet3_check_link(adapter, true);
for (i = 0; i < adapter->num_rx_queues; i++)
napi_enable(&adapter->rx_queue[i].napi);
vmxnet3_enable_all_intrs(adapter);
clear_bit(VMXNET3_STATE_BIT_QUIESCED, &adapter->state);
return 0;
activate_err:
VMXNET3_WRITE_BAR1_REG(adapter, VMXNET3_REG_DSAL, 0);
VMXNET3_WRITE_BAR1_REG(adapter, VMXNET3_REG_DSAH, 0);
vmxnet3_free_irqs(adapter);
irq_err:
rq_err:
vmxnet3_rq_cleanup_all(adapter);
return err;
}
void
vmxnet3_reset_dev(struct vmxnet3_adapter *adapter)
{
unsigned long flags;
spin_lock_irqsave(&adapter->cmd_lock, flags);
VMXNET3_WRITE_BAR1_REG(adapter, VMXNET3_REG_CMD, VMXNET3_CMD_RESET_DEV);
spin_unlock_irqrestore(&adapter->cmd_lock, flags);
}
int
vmxnet3_quiesce_dev(struct vmxnet3_adapter *adapter)
{
int i;
unsigned long flags;
if (test_and_set_bit(VMXNET3_STATE_BIT_QUIESCED, &adapter->state))
return 0;
spin_lock_irqsave(&adapter->cmd_lock, flags);
VMXNET3_WRITE_BAR1_REG(adapter, VMXNET3_REG_CMD,
VMXNET3_CMD_QUIESCE_DEV);
spin_unlock_irqrestore(&adapter->cmd_lock, flags);
vmxnet3_disable_all_intrs(adapter);
for (i = 0; i < adapter->num_rx_queues; i++)
napi_disable(&adapter->rx_queue[i].napi);
netif_tx_disable(adapter->netdev);
adapter->link_speed = 0;
netif_carrier_off(adapter->netdev);
vmxnet3_tq_cleanup_all(adapter);
vmxnet3_rq_cleanup_all(adapter);
vmxnet3_free_irqs(adapter);
return 0;
}
static void
vmxnet3_write_mac_addr(struct vmxnet3_adapter *adapter, u8 *mac)
{
u32 tmp;
tmp = *(u32 *)mac;
VMXNET3_WRITE_BAR1_REG(adapter, VMXNET3_REG_MACL, tmp);
tmp = (mac[5] << 8) | mac[4];
VMXNET3_WRITE_BAR1_REG(adapter, VMXNET3_REG_MACH, tmp);
}
static int
vmxnet3_set_mac_addr(struct net_device *netdev, void *p)
{
struct sockaddr *addr = p;
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
memcpy(netdev->dev_addr, addr->sa_data, netdev->addr_len);
vmxnet3_write_mac_addr(adapter, addr->sa_data);
return 0;
}
static int
vmxnet3_alloc_pci_resources(struct vmxnet3_adapter *adapter, bool *dma64)
{
int err;
unsigned long mmio_start, mmio_len;
struct pci_dev *pdev = adapter->pdev;
err = pci_enable_device(pdev);
if (err) {
printk(KERN_ERR "Failed to enable adapter %s: error %d\n",
pci_name(pdev), err);
return err;
}
if (pci_set_dma_mask(pdev, DMA_BIT_MASK(64)) == 0) {
if (pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(64)) != 0) {
printk(KERN_ERR "pci_set_consistent_dma_mask failed "
"for adapter %s\n", pci_name(pdev));
err = -EIO;
goto err_set_mask;
}
*dma64 = true;
} else {
if (pci_set_dma_mask(pdev, DMA_BIT_MASK(32)) != 0) {
printk(KERN_ERR "pci_set_dma_mask failed for adapter "
"%s\n", pci_name(pdev));
err = -EIO;
goto err_set_mask;
}
*dma64 = false;
}
err = pci_request_selected_regions(pdev, (1 << 2) - 1,
vmxnet3_driver_name);
if (err) {
printk(KERN_ERR "Failed to request region for adapter %s: "
"error %d\n", pci_name(pdev), err);
goto err_set_mask;
}
pci_set_master(pdev);
mmio_start = pci_resource_start(pdev, 0);
mmio_len = pci_resource_len(pdev, 0);
adapter->hw_addr0 = ioremap(mmio_start, mmio_len);
if (!adapter->hw_addr0) {
printk(KERN_ERR "Failed to map bar0 for adapter %s\n",
pci_name(pdev));
err = -EIO;
goto err_ioremap;
}
mmio_start = pci_resource_start(pdev, 1);
mmio_len = pci_resource_len(pdev, 1);
adapter->hw_addr1 = ioremap(mmio_start, mmio_len);
if (!adapter->hw_addr1) {
printk(KERN_ERR "Failed to map bar1 for adapter %s\n",
pci_name(pdev));
err = -EIO;
goto err_bar1;
}
return 0;
err_bar1:
iounmap(adapter->hw_addr0);
err_ioremap:
pci_release_selected_regions(pdev, (1 << 2) - 1);
err_set_mask:
pci_disable_device(pdev);
return err;
}
static void
vmxnet3_free_pci_resources(struct vmxnet3_adapter *adapter)
{
BUG_ON(!adapter->pdev);
iounmap(adapter->hw_addr0);
iounmap(adapter->hw_addr1);
pci_release_selected_regions(adapter->pdev, (1 << 2) - 1);
pci_disable_device(adapter->pdev);
}
static void
vmxnet3_adjust_rx_ring_size(struct vmxnet3_adapter *adapter)
{
size_t sz, i, ring0_size, ring1_size, comp_size;
struct vmxnet3_rx_queue *rq = &adapter->rx_queue[0];
if (adapter->netdev->mtu <= VMXNET3_MAX_SKB_BUF_SIZE -
VMXNET3_MAX_ETH_HDR_SIZE) {
adapter->skb_buf_size = adapter->netdev->mtu +
VMXNET3_MAX_ETH_HDR_SIZE;
if (adapter->skb_buf_size < VMXNET3_MIN_T0_BUF_SIZE)
adapter->skb_buf_size = VMXNET3_MIN_T0_BUF_SIZE;
adapter->rx_buf_per_pkt = 1;
} else {
adapter->skb_buf_size = VMXNET3_MAX_SKB_BUF_SIZE;
sz = adapter->netdev->mtu - VMXNET3_MAX_SKB_BUF_SIZE +
VMXNET3_MAX_ETH_HDR_SIZE;
adapter->rx_buf_per_pkt = 1 + (sz + PAGE_SIZE - 1) / PAGE_SIZE;
}
sz = adapter->rx_buf_per_pkt * VMXNET3_RING_SIZE_ALIGN;
ring0_size = adapter->rx_queue[0].rx_ring[0].size;
ring0_size = (ring0_size + sz - 1) / sz * sz;
ring0_size = min_t(u32, ring0_size, VMXNET3_RX_RING_MAX_SIZE /
sz * sz);
ring1_size = adapter->rx_queue[0].rx_ring[1].size;
comp_size = ring0_size + ring1_size;
for (i = 0; i < adapter->num_rx_queues; i++) {
rq = &adapter->rx_queue[i];
rq->rx_ring[0].size = ring0_size;
rq->rx_ring[1].size = ring1_size;
rq->comp_ring.size = comp_size;
}
}
int
vmxnet3_create_queues(struct vmxnet3_adapter *adapter, u32 tx_ring_size,
u32 rx_ring_size, u32 rx_ring2_size)
{
int err = 0, i;
for (i = 0; i < adapter->num_tx_queues; i++) {
struct vmxnet3_tx_queue *tq = &adapter->tx_queue[i];
tq->tx_ring.size = tx_ring_size;
tq->data_ring.size = tx_ring_size;
tq->comp_ring.size = tx_ring_size;
tq->shared = &adapter->tqd_start[i].ctrl;
tq->stopped = true;
tq->adapter = adapter;
tq->qid = i;
err = vmxnet3_tq_create(tq, adapter);
if (err)
goto queue_err;
}
adapter->rx_queue[0].rx_ring[0].size = rx_ring_size;
adapter->rx_queue[0].rx_ring[1].size = rx_ring2_size;
vmxnet3_adjust_rx_ring_size(adapter);
for (i = 0; i < adapter->num_rx_queues; i++) {
struct vmxnet3_rx_queue *rq = &adapter->rx_queue[i];
rq->shared = &adapter->rqd_start[i].ctrl;
rq->adapter = adapter;
err = vmxnet3_rq_create(rq, adapter);
if (err) {
if (i == 0) {
printk(KERN_ERR "Could not allocate any rx"
"queues. Aborting.\n");
goto queue_err;
} else {
printk(KERN_INFO "Number of rx queues changed "
"to : %d.\n", i);
adapter->num_rx_queues = i;
err = 0;
break;
}
}
}
return err;
queue_err:
vmxnet3_tq_destroy_all(adapter);
return err;
}
static int
vmxnet3_open(struct net_device *netdev)
{
struct vmxnet3_adapter *adapter;
int err, i;
adapter = netdev_priv(netdev);
for (i = 0; i < adapter->num_tx_queues; i++)
spin_lock_init(&adapter->tx_queue[i].tx_lock);
err = vmxnet3_create_queues(adapter, VMXNET3_DEF_TX_RING_SIZE,
VMXNET3_DEF_RX_RING_SIZE,
VMXNET3_DEF_RX_RING_SIZE);
if (err)
goto queue_err;
err = vmxnet3_activate_dev(adapter);
if (err)
goto activate_err;
return 0;
activate_err:
vmxnet3_rq_destroy_all(adapter);
vmxnet3_tq_destroy_all(adapter);
queue_err:
return err;
}
static int
vmxnet3_close(struct net_device *netdev)
{
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
while (test_and_set_bit(VMXNET3_STATE_BIT_RESETTING, &adapter->state))
msleep(1);
vmxnet3_quiesce_dev(adapter);
vmxnet3_rq_destroy_all(adapter);
vmxnet3_tq_destroy_all(adapter);
clear_bit(VMXNET3_STATE_BIT_RESETTING, &adapter->state);
return 0;
}
void
vmxnet3_force_close(struct vmxnet3_adapter *adapter)
{
int i;
BUG_ON(test_bit(VMXNET3_STATE_BIT_RESETTING, &adapter->state));
for (i = 0; i < adapter->num_rx_queues; i++)
napi_enable(&adapter->rx_queue[i].napi);
dev_close(adapter->netdev);
}
static int
vmxnet3_change_mtu(struct net_device *netdev, int new_mtu)
{
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
int err = 0;
if (new_mtu < VMXNET3_MIN_MTU || new_mtu > VMXNET3_MAX_MTU)
return -EINVAL;
netdev->mtu = new_mtu;
while (test_and_set_bit(VMXNET3_STATE_BIT_RESETTING, &adapter->state))
msleep(1);
if (netif_running(netdev)) {
vmxnet3_quiesce_dev(adapter);
vmxnet3_reset_dev(adapter);
vmxnet3_rq_destroy_all(adapter);
vmxnet3_adjust_rx_ring_size(adapter);
err = vmxnet3_rq_create_all(adapter);
if (err) {
printk(KERN_ERR "%s: failed to re-create rx queues,"
" error %d. Closing it.\n", netdev->name, err);
goto out;
}
err = vmxnet3_activate_dev(adapter);
if (err) {
printk(KERN_ERR "%s: failed to re-activate, error %d. "
"Closing it\n", netdev->name, err);
goto out;
}
}
out:
clear_bit(VMXNET3_STATE_BIT_RESETTING, &adapter->state);
if (err)
vmxnet3_force_close(adapter);
return err;
}
static void
vmxnet3_declare_features(struct vmxnet3_adapter *adapter, bool dma64)
{
struct net_device *netdev = adapter->netdev;
netdev->hw_features = NETIF_F_SG | NETIF_F_RXCSUM |
NETIF_F_HW_CSUM | NETIF_F_HW_VLAN_TX |
NETIF_F_HW_VLAN_RX | NETIF_F_TSO | NETIF_F_TSO6 |
NETIF_F_LRO;
if (dma64)
netdev->hw_features |= NETIF_F_HIGHDMA;
netdev->vlan_features = netdev->hw_features &
~(NETIF_F_HW_VLAN_TX | NETIF_F_HW_VLAN_RX);
netdev->features = netdev->hw_features | NETIF_F_HW_VLAN_FILTER;
netdev_info(adapter->netdev,
"features: sg csum vlan jf tso tsoIPv6 lro%s\n",
dma64 ? " highDMA" : "");
}
static void
vmxnet3_read_mac_addr(struct vmxnet3_adapter *adapter, u8 *mac)
{
u32 tmp;
tmp = VMXNET3_READ_BAR1_REG(adapter, VMXNET3_REG_MACL);
*(u32 *)mac = tmp;
tmp = VMXNET3_READ_BAR1_REG(adapter, VMXNET3_REG_MACH);
mac[4] = tmp & 0xff;
mac[5] = (tmp >> 8) & 0xff;
}
static int
vmxnet3_acquire_msix_vectors(struct vmxnet3_adapter *adapter,
int vectors)
{
int err = 0, vector_threshold;
vector_threshold = VMXNET3_LINUX_MIN_MSIX_VECT;
while (vectors >= vector_threshold) {
err = pci_enable_msix(adapter->pdev, adapter->intr.msix_entries,
vectors);
if (!err) {
adapter->intr.num_intrs = vectors;
return 0;
} else if (err < 0) {
netdev_err(adapter->netdev,
"Failed to enable MSI-X, error: %d\n", err);
vectors = 0;
} else if (err < vector_threshold) {
break;
} else {
netdev_err(adapter->netdev,
"Failed to enable %d MSI-X, trying %d instead\n",
vectors, vector_threshold);
vectors = vector_threshold;
}
}
netdev_info(adapter->netdev,
"Number of MSI-X interrupts which can be allocated are lower than min threshold required.\n");
return err;
}
static void
vmxnet3_alloc_intr_resources(struct vmxnet3_adapter *adapter)
{
u32 cfg;
unsigned long flags;
spin_lock_irqsave(&adapter->cmd_lock, flags);
VMXNET3_WRITE_BAR1_REG(adapter, VMXNET3_REG_CMD,
VMXNET3_CMD_GET_CONF_INTR);
cfg = VMXNET3_READ_BAR1_REG(adapter, VMXNET3_REG_CMD);
spin_unlock_irqrestore(&adapter->cmd_lock, flags);
adapter->intr.type = cfg & 0x3;
adapter->intr.mask_mode = (cfg >> 2) & 0x3;
if (adapter->intr.type == VMXNET3_IT_AUTO) {
adapter->intr.type = VMXNET3_IT_MSIX;
}
#ifdef CONFIG_PCI_MSI
if (adapter->intr.type == VMXNET3_IT_MSIX) {
int vector, err = 0;
adapter->intr.num_intrs = (adapter->share_intr ==
VMXNET3_INTR_TXSHARE) ? 1 :
adapter->num_tx_queues;
adapter->intr.num_intrs += (adapter->share_intr ==
VMXNET3_INTR_BUDDYSHARE) ? 0 :
adapter->num_rx_queues;
adapter->intr.num_intrs += 1;
adapter->intr.num_intrs = (adapter->intr.num_intrs >
VMXNET3_LINUX_MIN_MSIX_VECT
? adapter->intr.num_intrs :
VMXNET3_LINUX_MIN_MSIX_VECT);
for (vector = 0; vector < adapter->intr.num_intrs; vector++)
adapter->intr.msix_entries[vector].entry = vector;
err = vmxnet3_acquire_msix_vectors(adapter,
adapter->intr.num_intrs);
if (err == VMXNET3_LINUX_MIN_MSIX_VECT) {
if (adapter->share_intr != VMXNET3_INTR_BUDDYSHARE
|| adapter->num_rx_queues != 1) {
adapter->share_intr = VMXNET3_INTR_TXSHARE;
printk(KERN_ERR "Number of rx queues : 1\n");
adapter->num_rx_queues = 1;
adapter->intr.num_intrs =
VMXNET3_LINUX_MIN_MSIX_VECT;
}
return;
}
if (!err)
return;
netdev_info(adapter->netdev,
"Failed to enable MSI-X, error %d . Limiting #rx queues to 1, try MSI.\n",
err);
adapter->intr.type = VMXNET3_IT_MSI;
}
if (adapter->intr.type == VMXNET3_IT_MSI) {
int err;
err = pci_enable_msi(adapter->pdev);
if (!err) {
adapter->num_rx_queues = 1;
adapter->intr.num_intrs = 1;
return;
}
}
#endif
adapter->num_rx_queues = 1;
printk(KERN_INFO "Using INTx interrupt, #Rx queues: 1.\n");
adapter->intr.type = VMXNET3_IT_INTX;
adapter->intr.num_intrs = 1;
}
static void
vmxnet3_free_intr_resources(struct vmxnet3_adapter *adapter)
{
if (adapter->intr.type == VMXNET3_IT_MSIX)
pci_disable_msix(adapter->pdev);
else if (adapter->intr.type == VMXNET3_IT_MSI)
pci_disable_msi(adapter->pdev);
else
BUG_ON(adapter->intr.type != VMXNET3_IT_INTX);
}
static void
vmxnet3_tx_timeout(struct net_device *netdev)
{
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
adapter->tx_timeout_count++;
printk(KERN_ERR "%s: tx hang\n", adapter->netdev->name);
schedule_work(&adapter->work);
netif_wake_queue(adapter->netdev);
}
static void
vmxnet3_reset_work(struct work_struct *data)
{
struct vmxnet3_adapter *adapter;
adapter = container_of(data, struct vmxnet3_adapter, work);
if (test_and_set_bit(VMXNET3_STATE_BIT_RESETTING, &adapter->state))
return;
rtnl_lock();
if (netif_running(adapter->netdev)) {
printk(KERN_INFO "%s: resetting\n", adapter->netdev->name);
vmxnet3_quiesce_dev(adapter);
vmxnet3_reset_dev(adapter);
vmxnet3_activate_dev(adapter);
} else {
printk(KERN_INFO "%s: already closed\n", adapter->netdev->name);
}
rtnl_unlock();
clear_bit(VMXNET3_STATE_BIT_RESETTING, &adapter->state);
}
static int __devinit
vmxnet3_probe_device(struct pci_dev *pdev,
const struct pci_device_id *id)
{
static const struct net_device_ops vmxnet3_netdev_ops = {
.ndo_open = vmxnet3_open,
.ndo_stop = vmxnet3_close,
.ndo_start_xmit = vmxnet3_xmit_frame,
.ndo_set_mac_address = vmxnet3_set_mac_addr,
.ndo_change_mtu = vmxnet3_change_mtu,
.ndo_set_features = vmxnet3_set_features,
.ndo_get_stats64 = vmxnet3_get_stats64,
.ndo_tx_timeout = vmxnet3_tx_timeout,
.ndo_set_rx_mode = vmxnet3_set_mc,
.ndo_vlan_rx_add_vid = vmxnet3_vlan_rx_add_vid,
.ndo_vlan_rx_kill_vid = vmxnet3_vlan_rx_kill_vid,
#ifdef CONFIG_NET_POLL_CONTROLLER
.ndo_poll_controller = vmxnet3_netpoll,
#endif
};
int err;
bool dma64 = false;
u32 ver;
struct net_device *netdev;
struct vmxnet3_adapter *adapter;
u8 mac[ETH_ALEN];
int size;
int num_tx_queues;
int num_rx_queues;
if (!pci_msi_enabled())
enable_mq = 0;
#ifdef VMXNET3_RSS
if (enable_mq)
num_rx_queues = min(VMXNET3_DEVICE_MAX_RX_QUEUES,
(int)num_online_cpus());
else
#endif
num_rx_queues = 1;
num_rx_queues = rounddown_pow_of_two(num_rx_queues);
if (enable_mq)
num_tx_queues = min(VMXNET3_DEVICE_MAX_TX_QUEUES,
(int)num_online_cpus());
else
num_tx_queues = 1;
num_tx_queues = rounddown_pow_of_two(num_tx_queues);
netdev = alloc_etherdev_mq(sizeof(struct vmxnet3_adapter),
max(num_tx_queues, num_rx_queues));
printk(KERN_INFO "# of Tx queues : %d, # of Rx queues : %d\n",
num_tx_queues, num_rx_queues);
if (!netdev)
return -ENOMEM;
pci_set_drvdata(pdev, netdev);
adapter = netdev_priv(netdev);
adapter->netdev = netdev;
adapter->pdev = pdev;
spin_lock_init(&adapter->cmd_lock);
adapter->shared = pci_alloc_consistent(adapter->pdev,
sizeof(struct Vmxnet3_DriverShared),
&adapter->shared_pa);
if (!adapter->shared) {
printk(KERN_ERR "Failed to allocate memory for %s\n",
pci_name(pdev));
err = -ENOMEM;
goto err_alloc_shared;
}
adapter->num_rx_queues = num_rx_queues;
adapter->num_tx_queues = num_tx_queues;
size = sizeof(struct Vmxnet3_TxQueueDesc) * adapter->num_tx_queues;
size += sizeof(struct Vmxnet3_RxQueueDesc) * adapter->num_rx_queues;
adapter->tqd_start = pci_alloc_consistent(adapter->pdev, size,
&adapter->queue_desc_pa);
if (!adapter->tqd_start) {
printk(KERN_ERR "Failed to allocate memory for %s\n",
pci_name(pdev));
err = -ENOMEM;
goto err_alloc_queue_desc;
}
adapter->rqd_start = (struct Vmxnet3_RxQueueDesc *)(adapter->tqd_start +
adapter->num_tx_queues);
adapter->pm_conf = kmalloc(sizeof(struct Vmxnet3_PMConf), GFP_KERNEL);
if (adapter->pm_conf == NULL) {
err = -ENOMEM;
goto err_alloc_pm;
}
#ifdef VMXNET3_RSS
adapter->rss_conf = kmalloc(sizeof(struct UPT1_RSSConf), GFP_KERNEL);
if (adapter->rss_conf == NULL) {
err = -ENOMEM;
goto err_alloc_rss;
}
#endif
err = vmxnet3_alloc_pci_resources(adapter, &dma64);
if (err < 0)
goto err_alloc_pci;
ver = VMXNET3_READ_BAR1_REG(adapter, VMXNET3_REG_VRRS);
if (ver & 1) {
VMXNET3_WRITE_BAR1_REG(adapter, VMXNET3_REG_VRRS, 1);
} else {
printk(KERN_ERR "Incompatible h/w version (0x%x) for adapter"
" %s\n", ver, pci_name(pdev));
err = -EBUSY;
goto err_ver;
}
ver = VMXNET3_READ_BAR1_REG(adapter, VMXNET3_REG_UVRS);
if (ver & 1) {
VMXNET3_WRITE_BAR1_REG(adapter, VMXNET3_REG_UVRS, 1);
} else {
printk(KERN_ERR "Incompatible upt version (0x%x) for "
"adapter %s\n", ver, pci_name(pdev));
err = -EBUSY;
goto err_ver;
}
SET_NETDEV_DEV(netdev, &pdev->dev);
vmxnet3_declare_features(adapter, dma64);
adapter->dev_number = atomic_read(&devices_found);
adapter->share_intr = irq_share_mode;
if (adapter->share_intr == VMXNET3_INTR_BUDDYSHARE &&
adapter->num_tx_queues != adapter->num_rx_queues)
adapter->share_intr = VMXNET3_INTR_DONTSHARE;
vmxnet3_alloc_intr_resources(adapter);
#ifdef VMXNET3_RSS
if (adapter->num_rx_queues > 1 &&
adapter->intr.type == VMXNET3_IT_MSIX) {
adapter->rss = true;
printk(KERN_INFO "RSS is enabled.\n");
} else {
adapter->rss = false;
}
#endif
vmxnet3_read_mac_addr(adapter, mac);
memcpy(netdev->dev_addr, mac, netdev->addr_len);
netdev->netdev_ops = &vmxnet3_netdev_ops;
vmxnet3_set_ethtool_ops(netdev);
netdev->watchdog_timeo = 5 * HZ;
INIT_WORK(&adapter->work, vmxnet3_reset_work);
set_bit(VMXNET3_STATE_BIT_QUIESCED, &adapter->state);
if (adapter->intr.type == VMXNET3_IT_MSIX) {
int i;
for (i = 0; i < adapter->num_rx_queues; i++) {
netif_napi_add(adapter->netdev,
&adapter->rx_queue[i].napi,
vmxnet3_poll_rx_only, 64);
}
} else {
netif_napi_add(adapter->netdev, &adapter->rx_queue[0].napi,
vmxnet3_poll, 64);
}
netif_set_real_num_tx_queues(adapter->netdev, adapter->num_tx_queues);
netif_set_real_num_rx_queues(adapter->netdev, adapter->num_rx_queues);
err = register_netdev(netdev);
if (err) {
printk(KERN_ERR "Failed to register adapter %s\n",
pci_name(pdev));
goto err_register;
}
vmxnet3_check_link(adapter, false);
atomic_inc(&devices_found);
return 0;
err_register:
vmxnet3_free_intr_resources(adapter);
err_ver:
vmxnet3_free_pci_resources(adapter);
err_alloc_pci:
#ifdef VMXNET3_RSS
kfree(adapter->rss_conf);
err_alloc_rss:
#endif
kfree(adapter->pm_conf);
err_alloc_pm:
pci_free_consistent(adapter->pdev, size, adapter->tqd_start,
adapter->queue_desc_pa);
err_alloc_queue_desc:
pci_free_consistent(adapter->pdev, sizeof(struct Vmxnet3_DriverShared),
adapter->shared, adapter->shared_pa);
err_alloc_shared:
pci_set_drvdata(pdev, NULL);
free_netdev(netdev);
return err;
}
static void __devexit
vmxnet3_remove_device(struct pci_dev *pdev)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
int size = 0;
int num_rx_queues;
#ifdef VMXNET3_RSS
if (enable_mq)
num_rx_queues = min(VMXNET3_DEVICE_MAX_RX_QUEUES,
(int)num_online_cpus());
else
#endif
num_rx_queues = 1;
num_rx_queues = rounddown_pow_of_two(num_rx_queues);
cancel_work_sync(&adapter->work);
unregister_netdev(netdev);
vmxnet3_free_intr_resources(adapter);
vmxnet3_free_pci_resources(adapter);
#ifdef VMXNET3_RSS
kfree(adapter->rss_conf);
#endif
kfree(adapter->pm_conf);
size = sizeof(struct Vmxnet3_TxQueueDesc) * adapter->num_tx_queues;
size += sizeof(struct Vmxnet3_RxQueueDesc) * num_rx_queues;
pci_free_consistent(adapter->pdev, size, adapter->tqd_start,
adapter->queue_desc_pa);
pci_free_consistent(adapter->pdev, sizeof(struct Vmxnet3_DriverShared),
adapter->shared, adapter->shared_pa);
free_netdev(netdev);
}
static int
vmxnet3_suspend(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct net_device *netdev = pci_get_drvdata(pdev);
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
struct Vmxnet3_PMConf *pmConf;
struct ethhdr *ehdr;
struct arphdr *ahdr;
u8 *arpreq;
struct in_device *in_dev;
struct in_ifaddr *ifa;
unsigned long flags;
int i = 0;
if (!netif_running(netdev))
return 0;
for (i = 0; i < adapter->num_rx_queues; i++)
napi_disable(&adapter->rx_queue[i].napi);
vmxnet3_disable_all_intrs(adapter);
vmxnet3_free_irqs(adapter);
vmxnet3_free_intr_resources(adapter);
netif_device_detach(netdev);
netif_tx_stop_all_queues(netdev);
pmConf = adapter->pm_conf;
memset(pmConf, 0, sizeof(*pmConf));
if (adapter->wol & WAKE_UCAST) {
pmConf->filters[i].patternSize = ETH_ALEN;
pmConf->filters[i].maskSize = 1;
memcpy(pmConf->filters[i].pattern, netdev->dev_addr, ETH_ALEN);
pmConf->filters[i].mask[0] = 0x3F;
pmConf->wakeUpEvents |= VMXNET3_PM_WAKEUP_FILTER;
i++;
}
if (adapter->wol & WAKE_ARP) {
in_dev = in_dev_get(netdev);
if (!in_dev)
goto skip_arp;
ifa = (struct in_ifaddr *)in_dev->ifa_list;
if (!ifa)
goto skip_arp;
pmConf->filters[i].patternSize = ETH_HLEN +
sizeof(struct arphdr) +
2 * ETH_ALEN +
2 * sizeof(u32);
pmConf->filters[i].maskSize =
(pmConf->filters[i].patternSize - 1) / 8 + 1;
ehdr = (struct ethhdr *)pmConf->filters[i].pattern;
ehdr->h_proto = htons(ETH_P_ARP);
ahdr = (struct arphdr *)&pmConf->filters[i].pattern[ETH_HLEN];
ahdr->ar_op = htons(ARPOP_REQUEST);
arpreq = (u8 *)(ahdr + 1);
arpreq += 2 * ETH_ALEN + sizeof(u32);
*(u32 *)arpreq = ifa->ifa_address;
pmConf->filters[i].mask[0] = 0x00;
pmConf->filters[i].mask[1] = 0x30;
pmConf->filters[i].mask[2] = 0x30;
pmConf->filters[i].mask[3] = 0x00;
pmConf->filters[i].mask[4] = 0xC0;
pmConf->filters[i].mask[5] = 0x03;
in_dev_put(in_dev);
pmConf->wakeUpEvents |= VMXNET3_PM_WAKEUP_FILTER;
i++;
}
skip_arp:
if (adapter->wol & WAKE_MAGIC)
pmConf->wakeUpEvents |= VMXNET3_PM_WAKEUP_MAGIC;
pmConf->numFilters = i;
adapter->shared->devRead.pmConfDesc.confVer = cpu_to_le32(1);
adapter->shared->devRead.pmConfDesc.confLen = cpu_to_le32(sizeof(
*pmConf));
adapter->shared->devRead.pmConfDesc.confPA = cpu_to_le64(virt_to_phys(
pmConf));
spin_lock_irqsave(&adapter->cmd_lock, flags);
VMXNET3_WRITE_BAR1_REG(adapter, VMXNET3_REG_CMD,
VMXNET3_CMD_UPDATE_PMCFG);
spin_unlock_irqrestore(&adapter->cmd_lock, flags);
pci_save_state(pdev);
pci_enable_wake(pdev, pci_choose_state(pdev, PMSG_SUSPEND),
adapter->wol);
pci_disable_device(pdev);
pci_set_power_state(pdev, pci_choose_state(pdev, PMSG_SUSPEND));
return 0;
}
static int
vmxnet3_resume(struct device *device)
{
int err, i = 0;
unsigned long flags;
struct pci_dev *pdev = to_pci_dev(device);
struct net_device *netdev = pci_get_drvdata(pdev);
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
struct Vmxnet3_PMConf *pmConf;
if (!netif_running(netdev))
return 0;
pmConf = adapter->pm_conf;
memset(pmConf, 0, sizeof(*pmConf));
adapter->shared->devRead.pmConfDesc.confVer = cpu_to_le32(1);
adapter->shared->devRead.pmConfDesc.confLen = cpu_to_le32(sizeof(
*pmConf));
adapter->shared->devRead.pmConfDesc.confPA = cpu_to_le64(virt_to_phys(
pmConf));
netif_device_attach(netdev);
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
err = pci_enable_device_mem(pdev);
if (err != 0)
return err;
pci_enable_wake(pdev, PCI_D0, 0);
spin_lock_irqsave(&adapter->cmd_lock, flags);
VMXNET3_WRITE_BAR1_REG(adapter, VMXNET3_REG_CMD,
VMXNET3_CMD_UPDATE_PMCFG);
spin_unlock_irqrestore(&adapter->cmd_lock, flags);
vmxnet3_alloc_intr_resources(adapter);
vmxnet3_request_irqs(adapter);
for (i = 0; i < adapter->num_rx_queues; i++)
napi_enable(&adapter->rx_queue[i].napi);
vmxnet3_enable_all_intrs(adapter);
return 0;
}
static int __init
vmxnet3_init_module(void)
{
printk(KERN_INFO "%s - version %s\n", VMXNET3_DRIVER_DESC,
VMXNET3_DRIVER_VERSION_REPORT);
return pci_register_driver(&vmxnet3_driver);
}
static void
vmxnet3_exit_module(void)
{
pci_unregister_driver(&vmxnet3_driver);
}
