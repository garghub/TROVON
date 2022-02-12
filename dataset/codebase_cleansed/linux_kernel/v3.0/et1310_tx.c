int et131x_tx_dma_memory_alloc(struct et131x_adapter *adapter)
{
int desc_size = 0;
struct tx_ring *tx_ring = &adapter->tx_ring;
adapter->tx_ring.tcb_ring =
kcalloc(NUM_TCB, sizeof(struct tcb), GFP_ATOMIC | GFP_DMA);
if (!adapter->tx_ring.tcb_ring) {
dev_err(&adapter->pdev->dev, "Cannot alloc memory for TCBs\n");
return -ENOMEM;
}
desc_size = (sizeof(struct tx_desc) * NUM_DESC_PER_RING_TX) + 4096 - 1;
tx_ring->tx_desc_ring =
(struct tx_desc *) pci_alloc_consistent(adapter->pdev, desc_size,
&tx_ring->tx_desc_ring_pa);
if (!adapter->tx_ring.tx_desc_ring) {
dev_err(&adapter->pdev->dev,
"Cannot alloc memory for Tx Ring\n");
return -ENOMEM;
}
tx_ring->tx_status = pci_alloc_consistent(adapter->pdev,
sizeof(u32),
&tx_ring->tx_status_pa);
if (!adapter->tx_ring.tx_status_pa) {
dev_err(&adapter->pdev->dev,
"Cannot alloc memory for Tx status block\n");
return -ENOMEM;
}
return 0;
}
void et131x_tx_dma_memory_free(struct et131x_adapter *adapter)
{
int desc_size = 0;
if (adapter->tx_ring.tx_desc_ring) {
desc_size = (sizeof(struct tx_desc) * NUM_DESC_PER_RING_TX)
+ 4096 - 1;
pci_free_consistent(adapter->pdev,
desc_size,
adapter->tx_ring.tx_desc_ring,
adapter->tx_ring.tx_desc_ring_pa);
adapter->tx_ring.tx_desc_ring = NULL;
}
if (adapter->tx_ring.tx_status) {
pci_free_consistent(adapter->pdev,
sizeof(u32),
adapter->tx_ring.tx_status,
adapter->tx_ring.tx_status_pa);
adapter->tx_ring.tx_status = NULL;
}
kfree(adapter->tx_ring.tcb_ring);
}
void ConfigTxDmaRegs(struct et131x_adapter *etdev)
{
struct txdma_regs __iomem *txdma = &etdev->regs->txdma;
writel((u32) ((u64)etdev->tx_ring.tx_desc_ring_pa >> 32),
&txdma->pr_base_hi);
writel((u32) etdev->tx_ring.tx_desc_ring_pa,
&txdma->pr_base_lo);
writel(NUM_DESC_PER_RING_TX - 1, &txdma->pr_num_des);
writel((u32)((u64)etdev->tx_ring.tx_status_pa >> 32),
&txdma->dma_wb_base_hi);
writel((u32)etdev->tx_ring.tx_status_pa, &txdma->dma_wb_base_lo);
*etdev->tx_ring.tx_status = 0;
writel(0, &txdma->service_request);
etdev->tx_ring.send_idx = 0;
}
void et131x_tx_dma_disable(struct et131x_adapter *etdev)
{
writel(ET_TXDMA_CSR_HALT|ET_TXDMA_SNGL_EPKT,
&etdev->regs->txdma.csr);
}
void et131x_tx_dma_enable(struct et131x_adapter *etdev)
{
writel(ET_TXDMA_SNGL_EPKT|(PARM_DMA_CACHE_DEF << ET_TXDMA_CACHE_SHIFT),
&etdev->regs->txdma.csr);
}
void et131x_init_send(struct et131x_adapter *adapter)
{
struct tcb *tcb;
u32 ct;
struct tx_ring *tx_ring;
tx_ring = &adapter->tx_ring;
tcb = adapter->tx_ring.tcb_ring;
tx_ring->tcb_qhead = tcb;
memset(tcb, 0, sizeof(struct tcb) * NUM_TCB);
for (ct = 0; ct++ < NUM_TCB; tcb++)
tcb->next = tcb + 1;
tcb--;
tx_ring->tcb_qtail = tcb;
tcb->next = NULL;
tx_ring->send_head = NULL;
tx_ring->send_tail = NULL;
}
int et131x_send_packets(struct sk_buff *skb, struct net_device *netdev)
{
int status = 0;
struct et131x_adapter *etdev = NULL;
etdev = netdev_priv(netdev);
if (etdev->tx_ring.used >= NUM_TCB) {
status = -ENOMEM;
} else {
if ((etdev->Flags & fMP_ADAPTER_FAIL_SEND_MASK) ||
!netif_carrier_ok(netdev)) {
dev_kfree_skb_any(skb);
skb = NULL;
etdev->net_stats.tx_dropped++;
} else {
status = et131x_send_packet(skb, etdev);
if (status != 0 && status != -ENOMEM) {
dev_kfree_skb_any(skb);
skb = NULL;
etdev->net_stats.tx_dropped++;
}
}
}
return status;
}
static int et131x_send_packet(struct sk_buff *skb,
struct et131x_adapter *etdev)
{
int status;
struct tcb *tcb = NULL;
u16 *shbufva;
unsigned long flags;
if (skb->len < ETH_HLEN)
return -EIO;
spin_lock_irqsave(&etdev->TCBReadyQLock, flags);
tcb = etdev->tx_ring.tcb_qhead;
if (tcb == NULL) {
spin_unlock_irqrestore(&etdev->TCBReadyQLock, flags);
return -ENOMEM;
}
etdev->tx_ring.tcb_qhead = tcb->next;
if (etdev->tx_ring.tcb_qhead == NULL)
etdev->tx_ring.tcb_qtail = NULL;
spin_unlock_irqrestore(&etdev->TCBReadyQLock, flags);
tcb->skb = skb;
if (skb->data != NULL && skb->len - skb->data_len >= 6) {
shbufva = (u16 *) skb->data;
if ((shbufva[0] == 0xffff) &&
(shbufva[1] == 0xffff) && (shbufva[2] == 0xffff)) {
tcb->flags |= fMP_DEST_BROAD;
} else if ((shbufva[0] & 0x3) == 0x0001) {
tcb->flags |= fMP_DEST_MULTI;
}
}
tcb->next = NULL;
status = nic_send_packet(etdev, tcb);
if (status != 0) {
spin_lock_irqsave(&etdev->TCBReadyQLock, flags);
if (etdev->tx_ring.tcb_qtail)
etdev->tx_ring.tcb_qtail->next = tcb;
else
etdev->tx_ring.tcb_qhead = tcb;
etdev->tx_ring.tcb_qtail = tcb;
spin_unlock_irqrestore(&etdev->TCBReadyQLock, flags);
return status;
}
WARN_ON(etdev->tx_ring.used > NUM_TCB);
return 0;
}
static int nic_send_packet(struct et131x_adapter *etdev, struct tcb *tcb)
{
u32 i;
struct tx_desc desc[24];
u32 frag = 0;
u32 thiscopy, remainder;
struct sk_buff *skb = tcb->skb;
u32 nr_frags = skb_shinfo(skb)->nr_frags + 1;
struct skb_frag_struct *frags = &skb_shinfo(skb)->frags[0];
unsigned long flags;
if (nr_frags > 23)
return -EIO;
memset(desc, 0, sizeof(struct tx_desc) * (nr_frags + 1));
for (i = 0; i < nr_frags; i++) {
if (i == 0) {
if ((skb->len - skb->data_len) <= 1514) {
desc[frag].addr_hi = 0;
desc[frag].len_vlan =
skb->len - skb->data_len;
desc[frag++].addr_lo =
pci_map_single(etdev->pdev,
skb->data,
skb->len -
skb->data_len,
PCI_DMA_TODEVICE);
} else {
desc[frag].addr_hi = 0;
desc[frag].len_vlan =
(skb->len - skb->data_len) / 2;
desc[frag++].addr_lo =
pci_map_single(etdev->pdev,
skb->data,
((skb->len -
skb->data_len) / 2),
PCI_DMA_TODEVICE);
desc[frag].addr_hi = 0;
desc[frag].len_vlan =
(skb->len - skb->data_len) / 2;
desc[frag++].addr_lo =
pci_map_single(etdev->pdev,
skb->data +
((skb->len -
skb->data_len) / 2),
((skb->len -
skb->data_len) / 2),
PCI_DMA_TODEVICE);
}
} else {
desc[frag].addr_hi = 0;
desc[frag].len_vlan =
frags[i - 1].size;
desc[frag++].addr_lo =
pci_map_page(etdev->pdev,
frags[i - 1].page,
frags[i - 1].page_offset,
frags[i - 1].size,
PCI_DMA_TODEVICE);
}
}
if (frag == 0)
return -EIO;
if (etdev->linkspeed == TRUEPHY_SPEED_1000MBPS) {
if (++etdev->tx_ring.since_irq == PARM_TX_NUM_BUFS_DEF) {
desc[frag - 1].flags = 0x5;
etdev->tx_ring.since_irq = 0;
} else {
desc[frag - 1].flags = 0x1;
}
} else
desc[frag - 1].flags = 0x5;
desc[0].flags |= 2;
tcb->index_start = etdev->tx_ring.send_idx;
tcb->stale = 0;
spin_lock_irqsave(&etdev->send_hw_lock, flags);
thiscopy = NUM_DESC_PER_RING_TX -
INDEX10(etdev->tx_ring.send_idx);
if (thiscopy >= frag) {
remainder = 0;
thiscopy = frag;
} else {
remainder = frag - thiscopy;
}
memcpy(etdev->tx_ring.tx_desc_ring +
INDEX10(etdev->tx_ring.send_idx), desc,
sizeof(struct tx_desc) * thiscopy);
add_10bit(&etdev->tx_ring.send_idx, thiscopy);
if (INDEX10(etdev->tx_ring.send_idx) == 0 ||
INDEX10(etdev->tx_ring.send_idx) == NUM_DESC_PER_RING_TX) {
etdev->tx_ring.send_idx &= ~ET_DMA10_MASK;
etdev->tx_ring.send_idx ^= ET_DMA10_WRAP;
}
if (remainder) {
memcpy(etdev->tx_ring.tx_desc_ring,
desc + thiscopy,
sizeof(struct tx_desc) * remainder);
add_10bit(&etdev->tx_ring.send_idx, remainder);
}
if (INDEX10(etdev->tx_ring.send_idx) == 0) {
if (etdev->tx_ring.send_idx)
tcb->index = NUM_DESC_PER_RING_TX - 1;
else
tcb->index = ET_DMA10_WRAP|(NUM_DESC_PER_RING_TX - 1);
} else
tcb->index = etdev->tx_ring.send_idx - 1;
spin_lock(&etdev->TCBSendQLock);
if (etdev->tx_ring.send_tail)
etdev->tx_ring.send_tail->next = tcb;
else
etdev->tx_ring.send_head = tcb;
etdev->tx_ring.send_tail = tcb;
WARN_ON(tcb->next != NULL);
etdev->tx_ring.used++;
spin_unlock(&etdev->TCBSendQLock);
writel(etdev->tx_ring.send_idx,
&etdev->regs->txdma.service_request);
if (etdev->linkspeed == TRUEPHY_SPEED_1000MBPS) {
writel(PARM_TX_TIME_INT_DEF * NANO_IN_A_MICRO,
&etdev->regs->global.watchdog_timer);
}
spin_unlock_irqrestore(&etdev->send_hw_lock, flags);
return 0;
}
inline void et131x_free_send_packet(struct et131x_adapter *etdev,
struct tcb *tcb)
{
unsigned long flags;
struct tx_desc *desc = NULL;
struct net_device_stats *stats = &etdev->net_stats;
if (tcb->flags & fMP_DEST_BROAD)
atomic_inc(&etdev->Stats.brdcstxmt);
else if (tcb->flags & fMP_DEST_MULTI)
atomic_inc(&etdev->Stats.multixmt);
else
atomic_inc(&etdev->Stats.unixmt);
if (tcb->skb) {
stats->tx_bytes += tcb->skb->len;
do {
desc = (struct tx_desc *)(etdev->tx_ring.tx_desc_ring +
INDEX10(tcb->index_start));
pci_unmap_single(etdev->pdev,
desc->addr_lo,
desc->len_vlan, PCI_DMA_TODEVICE);
add_10bit(&tcb->index_start, 1);
if (INDEX10(tcb->index_start) >=
NUM_DESC_PER_RING_TX) {
tcb->index_start &= ~ET_DMA10_MASK;
tcb->index_start ^= ET_DMA10_WRAP;
}
} while (desc != (etdev->tx_ring.tx_desc_ring +
INDEX10(tcb->index)));
dev_kfree_skb_any(tcb->skb);
}
memset(tcb, 0, sizeof(struct tcb));
spin_lock_irqsave(&etdev->TCBReadyQLock, flags);
etdev->Stats.opackets++;
if (etdev->tx_ring.tcb_qtail)
etdev->tx_ring.tcb_qtail->next = tcb;
else
etdev->tx_ring.tcb_qhead = tcb;
etdev->tx_ring.tcb_qtail = tcb;
spin_unlock_irqrestore(&etdev->TCBReadyQLock, flags);
WARN_ON(etdev->tx_ring.used < 0);
}
void et131x_free_busy_send_packets(struct et131x_adapter *etdev)
{
struct tcb *tcb;
unsigned long flags;
u32 freed = 0;
spin_lock_irqsave(&etdev->TCBSendQLock, flags);
tcb = etdev->tx_ring.send_head;
while (tcb != NULL && freed < NUM_TCB) {
struct tcb *next = tcb->next;
etdev->tx_ring.send_head = next;
if (next == NULL)
etdev->tx_ring.send_tail = NULL;
etdev->tx_ring.used--;
spin_unlock_irqrestore(&etdev->TCBSendQLock, flags);
freed++;
et131x_free_send_packet(etdev, tcb);
spin_lock_irqsave(&etdev->TCBSendQLock, flags);
tcb = etdev->tx_ring.send_head;
}
WARN_ON(freed == NUM_TCB);
spin_unlock_irqrestore(&etdev->TCBSendQLock, flags);
etdev->tx_ring.used = 0;
}
void et131x_handle_send_interrupt(struct et131x_adapter *etdev)
{
unsigned long flags;
u32 serviced;
struct tcb *tcb;
u32 index;
serviced = readl(&etdev->regs->txdma.NewServiceComplete);
index = INDEX10(serviced);
spin_lock_irqsave(&etdev->TCBSendQLock, flags);
tcb = etdev->tx_ring.send_head;
while (tcb &&
((serviced ^ tcb->index) & ET_DMA10_WRAP) &&
index < INDEX10(tcb->index)) {
etdev->tx_ring.used--;
etdev->tx_ring.send_head = tcb->next;
if (tcb->next == NULL)
etdev->tx_ring.send_tail = NULL;
spin_unlock_irqrestore(&etdev->TCBSendQLock, flags);
et131x_free_send_packet(etdev, tcb);
spin_lock_irqsave(&etdev->TCBSendQLock, flags);
tcb = etdev->tx_ring.send_head;
}
while (tcb &&
!((serviced ^ tcb->index) & ET_DMA10_WRAP)
&& index > (tcb->index & ET_DMA10_MASK)) {
etdev->tx_ring.used--;
etdev->tx_ring.send_head = tcb->next;
if (tcb->next == NULL)
etdev->tx_ring.send_tail = NULL;
spin_unlock_irqrestore(&etdev->TCBSendQLock, flags);
et131x_free_send_packet(etdev, tcb);
spin_lock_irqsave(&etdev->TCBSendQLock, flags);
tcb = etdev->tx_ring.send_head;
}
if (etdev->tx_ring.used <= NUM_TCB / 3)
netif_wake_queue(etdev->netdev);
spin_unlock_irqrestore(&etdev->TCBSendQLock, flags);
}
