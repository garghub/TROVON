static void c2_print_macaddr(struct net_device *netdev)
{
pr_debug("%s: MAC %pM, IRQ %u\n", netdev->name, netdev->dev_addr, netdev->irq);
}
static void c2_set_rxbufsize(struct c2_port *c2_port)
{
struct net_device *netdev = c2_port->netdev;
if (netdev->mtu > RX_BUF_SIZE)
c2_port->rx_buf_size =
netdev->mtu + ETH_HLEN + sizeof(struct c2_rxp_hdr) +
NET_IP_ALIGN;
else
c2_port->rx_buf_size = sizeof(struct c2_rxp_hdr) + RX_BUF_SIZE;
}
static int c2_tx_ring_alloc(struct c2_ring *tx_ring, void *vaddr,
dma_addr_t base, void __iomem * mmio_txp_ring)
{
struct c2_tx_desc *tx_desc;
struct c2_txp_desc __iomem *txp_desc;
struct c2_element *elem;
int i;
tx_ring->start = kmalloc(sizeof(*elem) * tx_ring->count, GFP_KERNEL);
if (!tx_ring->start)
return -ENOMEM;
elem = tx_ring->start;
tx_desc = vaddr;
txp_desc = mmio_txp_ring;
for (i = 0; i < tx_ring->count; i++, elem++, tx_desc++, txp_desc++) {
tx_desc->len = 0;
tx_desc->status = 0;
__raw_writeq((__force u64) cpu_to_be64(0x1122334455667788ULL),
(void __iomem *) txp_desc + C2_TXP_ADDR);
__raw_writew(0, (void __iomem *) txp_desc + C2_TXP_LEN);
__raw_writew((__force u16) cpu_to_be16(TXP_HTXD_UNINIT),
(void __iomem *) txp_desc + C2_TXP_FLAGS);
elem->skb = NULL;
elem->ht_desc = tx_desc;
elem->hw_desc = txp_desc;
if (i == tx_ring->count - 1) {
elem->next = tx_ring->start;
tx_desc->next_offset = base;
} else {
elem->next = elem + 1;
tx_desc->next_offset =
base + (i + 1) * sizeof(*tx_desc);
}
}
tx_ring->to_use = tx_ring->to_clean = tx_ring->start;
return 0;
}
static int c2_rx_ring_alloc(struct c2_ring *rx_ring, void *vaddr,
dma_addr_t base, void __iomem * mmio_rxp_ring)
{
struct c2_rx_desc *rx_desc;
struct c2_rxp_desc __iomem *rxp_desc;
struct c2_element *elem;
int i;
rx_ring->start = kmalloc(sizeof(*elem) * rx_ring->count, GFP_KERNEL);
if (!rx_ring->start)
return -ENOMEM;
elem = rx_ring->start;
rx_desc = vaddr;
rxp_desc = mmio_rxp_ring;
for (i = 0; i < rx_ring->count; i++, elem++, rx_desc++, rxp_desc++) {
rx_desc->len = 0;
rx_desc->status = 0;
__raw_writew((__force u16) cpu_to_be16(RXP_HRXD_OK),
(void __iomem *) rxp_desc + C2_RXP_STATUS);
__raw_writew(0, (void __iomem *) rxp_desc + C2_RXP_COUNT);
__raw_writew(0, (void __iomem *) rxp_desc + C2_RXP_LEN);
__raw_writeq((__force u64) cpu_to_be64(0x99aabbccddeeffULL),
(void __iomem *) rxp_desc + C2_RXP_ADDR);
__raw_writew((__force u16) cpu_to_be16(RXP_HRXD_UNINIT),
(void __iomem *) rxp_desc + C2_RXP_FLAGS);
elem->skb = NULL;
elem->ht_desc = rx_desc;
elem->hw_desc = rxp_desc;
if (i == rx_ring->count - 1) {
elem->next = rx_ring->start;
rx_desc->next_offset = base;
} else {
elem->next = elem + 1;
rx_desc->next_offset =
base + (i + 1) * sizeof(*rx_desc);
}
}
rx_ring->to_use = rx_ring->to_clean = rx_ring->start;
return 0;
}
static inline int c2_rx_alloc(struct c2_port *c2_port, struct c2_element *elem)
{
struct c2_dev *c2dev = c2_port->c2dev;
struct c2_rx_desc *rx_desc = elem->ht_desc;
struct sk_buff *skb;
dma_addr_t mapaddr;
u32 maplen;
struct c2_rxp_hdr *rxp_hdr;
skb = dev_alloc_skb(c2_port->rx_buf_size);
if (unlikely(!skb)) {
pr_debug("%s: out of memory for receive\n",
c2_port->netdev->name);
return -ENOMEM;
}
memset(skb->data, 0, sizeof(*rxp_hdr));
skb->dev = c2_port->netdev;
maplen = c2_port->rx_buf_size;
mapaddr =
pci_map_single(c2dev->pcidev, skb->data, maplen,
PCI_DMA_FROMDEVICE);
rxp_hdr = (struct c2_rxp_hdr *) skb->data;
rxp_hdr->flags = RXP_HRXD_READY;
__raw_writew(0, elem->hw_desc + C2_RXP_STATUS);
__raw_writew((__force u16) cpu_to_be16((u16) maplen - sizeof(*rxp_hdr)),
elem->hw_desc + C2_RXP_LEN);
__raw_writeq((__force u64) cpu_to_be64(mapaddr), elem->hw_desc + C2_RXP_ADDR);
__raw_writew((__force u16) cpu_to_be16(RXP_HRXD_READY),
elem->hw_desc + C2_RXP_FLAGS);
elem->skb = skb;
elem->mapaddr = mapaddr;
elem->maplen = maplen;
rx_desc->len = maplen;
return 0;
}
static int c2_rx_fill(struct c2_port *c2_port)
{
struct c2_ring *rx_ring = &c2_port->rx_ring;
struct c2_element *elem;
int ret = 0;
elem = rx_ring->start;
do {
if (c2_rx_alloc(c2_port, elem)) {
ret = 1;
break;
}
} while ((elem = elem->next) != rx_ring->start);
rx_ring->to_clean = rx_ring->start;
return ret;
}
static void c2_rx_clean(struct c2_port *c2_port)
{
struct c2_dev *c2dev = c2_port->c2dev;
struct c2_ring *rx_ring = &c2_port->rx_ring;
struct c2_element *elem;
struct c2_rx_desc *rx_desc;
elem = rx_ring->start;
do {
rx_desc = elem->ht_desc;
rx_desc->len = 0;
__raw_writew(0, elem->hw_desc + C2_RXP_STATUS);
__raw_writew(0, elem->hw_desc + C2_RXP_COUNT);
__raw_writew(0, elem->hw_desc + C2_RXP_LEN);
__raw_writeq((__force u64) cpu_to_be64(0x99aabbccddeeffULL),
elem->hw_desc + C2_RXP_ADDR);
__raw_writew((__force u16) cpu_to_be16(RXP_HRXD_UNINIT),
elem->hw_desc + C2_RXP_FLAGS);
if (elem->skb) {
pci_unmap_single(c2dev->pcidev, elem->mapaddr,
elem->maplen, PCI_DMA_FROMDEVICE);
dev_kfree_skb(elem->skb);
elem->skb = NULL;
}
} while ((elem = elem->next) != rx_ring->start);
}
static inline int c2_tx_free(struct c2_dev *c2dev, struct c2_element *elem)
{
struct c2_tx_desc *tx_desc = elem->ht_desc;
tx_desc->len = 0;
pci_unmap_single(c2dev->pcidev, elem->mapaddr, elem->maplen,
PCI_DMA_TODEVICE);
if (elem->skb) {
dev_kfree_skb_any(elem->skb);
elem->skb = NULL;
}
return 0;
}
static void c2_tx_clean(struct c2_port *c2_port)
{
struct c2_ring *tx_ring = &c2_port->tx_ring;
struct c2_element *elem;
struct c2_txp_desc txp_htxd;
int retry;
unsigned long flags;
spin_lock_irqsave(&c2_port->tx_lock, flags);
elem = tx_ring->start;
do {
retry = 0;
do {
txp_htxd.flags =
readw(elem->hw_desc + C2_TXP_FLAGS);
if (txp_htxd.flags == TXP_HTXD_READY) {
retry = 1;
__raw_writew(0,
elem->hw_desc + C2_TXP_LEN);
__raw_writeq(0,
elem->hw_desc + C2_TXP_ADDR);
__raw_writew((__force u16) cpu_to_be16(TXP_HTXD_DONE),
elem->hw_desc + C2_TXP_FLAGS);
c2_port->netdev->stats.tx_dropped++;
break;
} else {
__raw_writew(0,
elem->hw_desc + C2_TXP_LEN);
__raw_writeq((__force u64) cpu_to_be64(0x1122334455667788ULL),
elem->hw_desc + C2_TXP_ADDR);
__raw_writew((__force u16) cpu_to_be16(TXP_HTXD_UNINIT),
elem->hw_desc + C2_TXP_FLAGS);
}
c2_tx_free(c2_port->c2dev, elem);
} while ((elem = elem->next) != tx_ring->start);
} while (retry);
c2_port->tx_avail = c2_port->tx_ring.count - 1;
c2_port->c2dev->cur_tx = tx_ring->to_use - tx_ring->start;
if (c2_port->tx_avail > MAX_SKB_FRAGS + 1)
netif_wake_queue(c2_port->netdev);
spin_unlock_irqrestore(&c2_port->tx_lock, flags);
}
static void c2_tx_interrupt(struct net_device *netdev)
{
struct c2_port *c2_port = netdev_priv(netdev);
struct c2_dev *c2dev = c2_port->c2dev;
struct c2_ring *tx_ring = &c2_port->tx_ring;
struct c2_element *elem;
struct c2_txp_desc txp_htxd;
spin_lock(&c2_port->tx_lock);
for (elem = tx_ring->to_clean; elem != tx_ring->to_use;
elem = elem->next) {
txp_htxd.flags =
be16_to_cpu((__force __be16) readw(elem->hw_desc + C2_TXP_FLAGS));
if (txp_htxd.flags != TXP_HTXD_DONE)
break;
if (netif_msg_tx_done(c2_port)) {
txp_htxd.len =
be16_to_cpu((__force __be16) readw(elem->hw_desc + C2_TXP_LEN));
pr_debug("%s: tx done slot %3Zu status 0x%x len "
"%5u bytes\n",
netdev->name, elem - tx_ring->start,
txp_htxd.flags, txp_htxd.len);
}
c2_tx_free(c2dev, elem);
++(c2_port->tx_avail);
}
tx_ring->to_clean = elem;
if (netif_queue_stopped(netdev)
&& c2_port->tx_avail > MAX_SKB_FRAGS + 1)
netif_wake_queue(netdev);
spin_unlock(&c2_port->tx_lock);
}
static void c2_rx_error(struct c2_port *c2_port, struct c2_element *elem)
{
struct c2_rx_desc *rx_desc = elem->ht_desc;
struct c2_rxp_hdr *rxp_hdr = (struct c2_rxp_hdr *) elem->skb->data;
if (rxp_hdr->status != RXP_HRXD_OK ||
rxp_hdr->len > (rx_desc->len - sizeof(*rxp_hdr))) {
pr_debug("BAD RXP_HRXD\n");
pr_debug(" rx_desc : %p\n", rx_desc);
pr_debug(" index : %Zu\n",
elem - c2_port->rx_ring.start);
pr_debug(" len : %u\n", rx_desc->len);
pr_debug(" rxp_hdr : %p [PA %p]\n", rxp_hdr,
(void *) __pa((unsigned long) rxp_hdr));
pr_debug(" flags : 0x%x\n", rxp_hdr->flags);
pr_debug(" status: 0x%x\n", rxp_hdr->status);
pr_debug(" len : %u\n", rxp_hdr->len);
pr_debug(" rsvd : 0x%x\n", rxp_hdr->rsvd);
}
elem->skb->data = elem->skb->head;
skb_reset_tail_pointer(elem->skb);
memset(elem->skb->data, 0, sizeof(*rxp_hdr));
__raw_writew(0, elem->hw_desc + C2_RXP_STATUS);
__raw_writew(0, elem->hw_desc + C2_RXP_COUNT);
__raw_writew((__force u16) cpu_to_be16((u16) elem->maplen - sizeof(*rxp_hdr)),
elem->hw_desc + C2_RXP_LEN);
__raw_writeq((__force u64) cpu_to_be64(elem->mapaddr),
elem->hw_desc + C2_RXP_ADDR);
__raw_writew((__force u16) cpu_to_be16(RXP_HRXD_READY),
elem->hw_desc + C2_RXP_FLAGS);
pr_debug("packet dropped\n");
c2_port->netdev->stats.rx_dropped++;
}
static void c2_rx_interrupt(struct net_device *netdev)
{
struct c2_port *c2_port = netdev_priv(netdev);
struct c2_dev *c2dev = c2_port->c2dev;
struct c2_ring *rx_ring = &c2_port->rx_ring;
struct c2_element *elem;
struct c2_rx_desc *rx_desc;
struct c2_rxp_hdr *rxp_hdr;
struct sk_buff *skb;
dma_addr_t mapaddr;
u32 maplen, buflen;
unsigned long flags;
spin_lock_irqsave(&c2dev->lock, flags);
rx_ring->to_clean = rx_ring->start + c2dev->cur_rx;
for (elem = rx_ring->to_clean; elem->next != rx_ring->to_clean;
elem = elem->next) {
rx_desc = elem->ht_desc;
mapaddr = elem->mapaddr;
maplen = elem->maplen;
skb = elem->skb;
rxp_hdr = (struct c2_rxp_hdr *) skb->data;
if (rxp_hdr->flags != RXP_HRXD_DONE)
break;
buflen = rxp_hdr->len;
if (rxp_hdr->status != RXP_HRXD_OK ||
buflen > (rx_desc->len - sizeof(*rxp_hdr))) {
c2_rx_error(c2_port, elem);
continue;
}
if (c2_rx_alloc(c2_port, elem)) {
c2_rx_error(c2_port, elem);
continue;
}
pci_unmap_single(c2dev->pcidev, mapaddr, maplen,
PCI_DMA_FROMDEVICE);
prefetch(skb->data);
skb->data += sizeof(*rxp_hdr);
skb_set_tail_pointer(skb, buflen);
skb->len = buflen;
skb->protocol = eth_type_trans(skb, netdev);
netif_rx(skb);
netdev->stats.rx_packets++;
netdev->stats.rx_bytes += buflen;
}
rx_ring->to_clean = elem;
c2dev->cur_rx = elem - rx_ring->start;
C2_SET_CUR_RX(c2dev, c2dev->cur_rx);
spin_unlock_irqrestore(&c2dev->lock, flags);
}
static irqreturn_t c2_interrupt(int irq, void *dev_id)
{
unsigned int netisr0, dmaisr;
int handled = 0;
struct c2_dev *c2dev = (struct c2_dev *) dev_id;
netisr0 = readl(c2dev->regs + C2_NISR0);
if (netisr0) {
c2_rx_interrupt(c2dev->netdev);
c2_tx_interrupt(c2dev->netdev);
writel(netisr0, c2dev->regs + C2_NISR0);
handled++;
}
dmaisr = readl(c2dev->regs + C2_DISR);
if (dmaisr) {
writel(dmaisr, c2dev->regs + C2_DISR);
c2_rnic_interrupt(c2dev);
handled++;
}
if (handled) {
return IRQ_HANDLED;
} else {
return IRQ_NONE;
}
}
static int c2_up(struct net_device *netdev)
{
struct c2_port *c2_port = netdev_priv(netdev);
struct c2_dev *c2dev = c2_port->c2dev;
struct c2_element *elem;
struct c2_rxp_hdr *rxp_hdr;
struct in_device *in_dev;
size_t rx_size, tx_size;
int ret, i;
unsigned int netimr0;
if (netif_msg_ifup(c2_port))
pr_debug("%s: enabling interface\n", netdev->name);
c2_set_rxbufsize(c2_port);
rx_size = c2_port->rx_ring.count * sizeof(struct c2_rx_desc);
tx_size = c2_port->tx_ring.count * sizeof(struct c2_tx_desc);
c2_port->mem_size = tx_size + rx_size;
c2_port->mem = pci_alloc_consistent(c2dev->pcidev, c2_port->mem_size,
&c2_port->dma);
if (c2_port->mem == NULL) {
pr_debug("Unable to allocate memory for "
"host descriptor rings\n");
return -ENOMEM;
}
memset(c2_port->mem, 0, c2_port->mem_size);
if ((ret =
c2_rx_ring_alloc(&c2_port->rx_ring, c2_port->mem, c2_port->dma,
c2dev->mmio_rxp_ring))) {
pr_debug("Unable to create RX ring\n");
goto bail0;
}
if (c2_rx_fill(c2_port)) {
pr_debug("Unable to fill RX ring\n");
goto bail1;
}
if ((ret = c2_tx_ring_alloc(&c2_port->tx_ring, c2_port->mem + rx_size,
c2_port->dma + rx_size,
c2dev->mmio_txp_ring))) {
pr_debug("Unable to create TX ring\n");
goto bail1;
}
c2_port->tx_avail = c2_port->tx_ring.count - 1;
c2_port->tx_ring.to_use = c2_port->tx_ring.to_clean =
c2_port->tx_ring.start + c2dev->cur_tx;
BUG_ON(c2_port->tx_ring.to_use != c2_port->tx_ring.to_clean);
c2_reset(c2_port);
for (i = 0, elem = c2_port->rx_ring.start; i < c2_port->rx_ring.count;
i++, elem++) {
rxp_hdr = (struct c2_rxp_hdr *) elem->skb->data;
rxp_hdr->flags = 0;
__raw_writew((__force u16) cpu_to_be16(RXP_HRXD_READY),
elem->hw_desc + C2_RXP_FLAGS);
}
netif_start_queue(netdev);
writel(0, c2dev->regs + C2_IDIS);
netimr0 = readl(c2dev->regs + C2_NIMR0);
netimr0 &= ~(C2_PCI_HTX_INT | C2_PCI_HRX_INT);
writel(netimr0, c2dev->regs + C2_NIMR0);
in_dev = in_dev_get(netdev);
IN_DEV_CONF_SET(in_dev, ARP_IGNORE, 1);
in_dev_put(in_dev);
return 0;
bail1:
c2_rx_clean(c2_port);
kfree(c2_port->rx_ring.start);
bail0:
pci_free_consistent(c2dev->pcidev, c2_port->mem_size, c2_port->mem,
c2_port->dma);
return ret;
}
static int c2_down(struct net_device *netdev)
{
struct c2_port *c2_port = netdev_priv(netdev);
struct c2_dev *c2dev = c2_port->c2dev;
if (netif_msg_ifdown(c2_port))
pr_debug("%s: disabling interface\n",
netdev->name);
c2_tx_interrupt(netdev);
netif_stop_queue(netdev);
writel(1, c2dev->regs + C2_IDIS);
writel(0, c2dev->regs + C2_NIMR0);
c2_reset(c2_port);
c2_tx_clean(c2_port);
c2_rx_clean(c2_port);
kfree(c2_port->rx_ring.start);
kfree(c2_port->tx_ring.start);
pci_free_consistent(c2dev->pcidev, c2_port->mem_size, c2_port->mem,
c2_port->dma);
return 0;
}
static void c2_reset(struct c2_port *c2_port)
{
struct c2_dev *c2dev = c2_port->c2dev;
unsigned int cur_rx = c2dev->cur_rx;
C2_SET_CUR_RX(c2dev, cur_rx | C2_PCI_HRX_QUI);
ssleep(2);
cur_rx = C2_GET_CUR_RX(c2dev);
if (cur_rx & C2_PCI_HRX_QUI)
pr_debug("c2_reset: failed to quiesce the hardware!\n");
cur_rx &= ~C2_PCI_HRX_QUI;
c2dev->cur_rx = cur_rx;
pr_debug("Current RX: %u\n", c2dev->cur_rx);
}
static int c2_xmit_frame(struct sk_buff *skb, struct net_device *netdev)
{
struct c2_port *c2_port = netdev_priv(netdev);
struct c2_dev *c2dev = c2_port->c2dev;
struct c2_ring *tx_ring = &c2_port->tx_ring;
struct c2_element *elem;
dma_addr_t mapaddr;
u32 maplen;
unsigned long flags;
unsigned int i;
spin_lock_irqsave(&c2_port->tx_lock, flags);
if (unlikely(c2_port->tx_avail < (skb_shinfo(skb)->nr_frags + 1))) {
netif_stop_queue(netdev);
spin_unlock_irqrestore(&c2_port->tx_lock, flags);
pr_debug("%s: Tx ring full when queue awake!\n",
netdev->name);
return NETDEV_TX_BUSY;
}
maplen = skb_headlen(skb);
mapaddr =
pci_map_single(c2dev->pcidev, skb->data, maplen, PCI_DMA_TODEVICE);
elem = tx_ring->to_use;
elem->skb = skb;
elem->mapaddr = mapaddr;
elem->maplen = maplen;
__raw_writeq((__force u64) cpu_to_be64(mapaddr),
elem->hw_desc + C2_TXP_ADDR);
__raw_writew((__force u16) cpu_to_be16(maplen),
elem->hw_desc + C2_TXP_LEN);
__raw_writew((__force u16) cpu_to_be16(TXP_HTXD_READY),
elem->hw_desc + C2_TXP_FLAGS);
netdev->stats.tx_packets++;
netdev->stats.tx_bytes += maplen;
if (skb_shinfo(skb)->nr_frags) {
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
const skb_frag_t *frag = &skb_shinfo(skb)->frags[i];
maplen = skb_frag_size(frag);
mapaddr = skb_frag_dma_map(&c2dev->pcidev->dev, frag,
0, maplen, DMA_TO_DEVICE);
elem = elem->next;
elem->skb = NULL;
elem->mapaddr = mapaddr;
elem->maplen = maplen;
__raw_writeq((__force u64) cpu_to_be64(mapaddr),
elem->hw_desc + C2_TXP_ADDR);
__raw_writew((__force u16) cpu_to_be16(maplen),
elem->hw_desc + C2_TXP_LEN);
__raw_writew((__force u16) cpu_to_be16(TXP_HTXD_READY),
elem->hw_desc + C2_TXP_FLAGS);
netdev->stats.tx_packets++;
netdev->stats.tx_bytes += maplen;
}
}
tx_ring->to_use = elem->next;
c2_port->tx_avail -= (skb_shinfo(skb)->nr_frags + 1);
if (c2_port->tx_avail <= MAX_SKB_FRAGS + 1) {
netif_stop_queue(netdev);
if (netif_msg_tx_queued(c2_port))
pr_debug("%s: transmit queue full\n",
netdev->name);
}
spin_unlock_irqrestore(&c2_port->tx_lock, flags);
netdev->trans_start = jiffies;
return NETDEV_TX_OK;
}
static void c2_tx_timeout(struct net_device *netdev)
{
struct c2_port *c2_port = netdev_priv(netdev);
if (netif_msg_timer(c2_port))
pr_debug("%s: tx timeout\n", netdev->name);
c2_tx_clean(c2_port);
}
static int c2_change_mtu(struct net_device *netdev, int new_mtu)
{
int ret = 0;
if (new_mtu < ETH_ZLEN || new_mtu > ETH_JUMBO_MTU)
return -EINVAL;
netdev->mtu = new_mtu;
if (netif_running(netdev)) {
c2_down(netdev);
c2_up(netdev);
}
return ret;
}
static struct net_device *c2_devinit(struct c2_dev *c2dev,
void __iomem * mmio_addr)
{
struct c2_port *c2_port = NULL;
struct net_device *netdev = alloc_etherdev(sizeof(*c2_port));
if (!netdev) {
pr_debug("c2_port etherdev alloc failed");
return NULL;
}
SET_NETDEV_DEV(netdev, &c2dev->pcidev->dev);
netdev->netdev_ops = &c2_netdev;
netdev->watchdog_timeo = C2_TX_TIMEOUT;
netdev->irq = c2dev->pcidev->irq;
c2_port = netdev_priv(netdev);
c2_port->netdev = netdev;
c2_port->c2dev = c2dev;
c2_port->msg_enable = netif_msg_init(debug, default_msg);
c2_port->tx_ring.count = C2_NUM_TX_DESC;
c2_port->rx_ring.count = C2_NUM_RX_DESC;
spin_lock_init(&c2_port->tx_lock);
memcpy_fromio(netdev->dev_addr, mmio_addr + C2_REGS_ENADDR, 6);
if (!is_valid_ether_addr(netdev->dev_addr)) {
pr_debug("Invalid MAC Address\n");
c2_print_macaddr(netdev);
free_netdev(netdev);
return NULL;
}
c2dev->netdev = netdev;
return netdev;
}
static int c2_probe(struct pci_dev *pcidev, const struct pci_device_id *ent)
{
int ret = 0, i;
unsigned long reg0_start, reg0_flags, reg0_len;
unsigned long reg2_start, reg2_flags, reg2_len;
unsigned long reg4_start, reg4_flags, reg4_len;
unsigned kva_map_size;
struct net_device *netdev = NULL;
struct c2_dev *c2dev = NULL;
void __iomem *mmio_regs = NULL;
printk(KERN_INFO PFX "AMSO1100 Gigabit Ethernet driver v%s loaded\n",
DRV_VERSION);
ret = pci_enable_device(pcidev);
if (ret) {
printk(KERN_ERR PFX "%s: Unable to enable PCI device\n",
pci_name(pcidev));
goto bail0;
}
reg0_start = pci_resource_start(pcidev, BAR_0);
reg0_len = pci_resource_len(pcidev, BAR_0);
reg0_flags = pci_resource_flags(pcidev, BAR_0);
reg2_start = pci_resource_start(pcidev, BAR_2);
reg2_len = pci_resource_len(pcidev, BAR_2);
reg2_flags = pci_resource_flags(pcidev, BAR_2);
reg4_start = pci_resource_start(pcidev, BAR_4);
reg4_len = pci_resource_len(pcidev, BAR_4);
reg4_flags = pci_resource_flags(pcidev, BAR_4);
pr_debug("BAR0 size = 0x%lX bytes\n", reg0_len);
pr_debug("BAR2 size = 0x%lX bytes\n", reg2_len);
pr_debug("BAR4 size = 0x%lX bytes\n", reg4_len);
if (!(reg0_flags & IORESOURCE_MEM) ||
!(reg2_flags & IORESOURCE_MEM) || !(reg4_flags & IORESOURCE_MEM)) {
printk(KERN_ERR PFX "PCI regions not an MMIO resource\n");
ret = -ENODEV;
goto bail1;
}
if ((reg0_len < C2_REG0_SIZE) ||
(reg2_len < C2_REG2_SIZE) || (reg4_len < C2_REG4_SIZE)) {
printk(KERN_ERR PFX "Invalid PCI region sizes\n");
ret = -ENODEV;
goto bail1;
}
ret = pci_request_regions(pcidev, DRV_NAME);
if (ret) {
printk(KERN_ERR PFX "%s: Unable to request regions\n",
pci_name(pcidev));
goto bail1;
}
if ((sizeof(dma_addr_t) > 4)) {
ret = pci_set_dma_mask(pcidev, DMA_BIT_MASK(64));
if (ret < 0) {
printk(KERN_ERR PFX "64b DMA configuration failed\n");
goto bail2;
}
} else {
ret = pci_set_dma_mask(pcidev, DMA_BIT_MASK(32));
if (ret < 0) {
printk(KERN_ERR PFX "32b DMA configuration failed\n");
goto bail2;
}
}
pci_set_master(pcidev);
mmio_regs = ioremap_nocache(reg4_start + C2_PCI_REGS_OFFSET,
sizeof(struct c2_adapter_pci_regs));
if (!mmio_regs) {
printk(KERN_ERR PFX
"Unable to remap adapter PCI registers in BAR4\n");
ret = -EIO;
goto bail2;
}
for (i = 0; i < sizeof(c2_magic); i++) {
if (c2_magic[i] != readb(mmio_regs + C2_REGS_MAGIC + i)) {
printk(KERN_ERR PFX "Downlevel Firmware boot loader "
"[%d/%Zd: got 0x%x, exp 0x%x]. Use the cc_flash "
"utility to update your boot loader\n",
i + 1, sizeof(c2_magic),
readb(mmio_regs + C2_REGS_MAGIC + i),
c2_magic[i]);
printk(KERN_ERR PFX "Adapter not claimed\n");
iounmap(mmio_regs);
ret = -EIO;
goto bail2;
}
}
if (be32_to_cpu((__force __be32) readl(mmio_regs + C2_REGS_VERS)) != C2_VERSION) {
printk(KERN_ERR PFX "Version mismatch "
"[fw=%u, c2=%u], Adapter not claimed\n",
be32_to_cpu((__force __be32) readl(mmio_regs + C2_REGS_VERS)),
C2_VERSION);
ret = -EINVAL;
iounmap(mmio_regs);
goto bail2;
}
if (be32_to_cpu((__force __be32) readl(mmio_regs + C2_REGS_IVN)) != C2_IVN) {
printk(KERN_ERR PFX "Downlevel FIrmware level. You should be using "
"the OpenIB device support kit. "
"[fw=0x%x, c2=0x%x], Adapter not claimed\n",
be32_to_cpu((__force __be32) readl(mmio_regs + C2_REGS_IVN)),
C2_IVN);
ret = -EINVAL;
iounmap(mmio_regs);
goto bail2;
}
c2dev = (struct c2_dev *) ib_alloc_device(sizeof(*c2dev));
if (!c2dev) {
printk(KERN_ERR PFX "%s: Unable to alloc hardware struct\n",
pci_name(pcidev));
ret = -ENOMEM;
iounmap(mmio_regs);
goto bail2;
}
memset(c2dev, 0, sizeof(*c2dev));
spin_lock_init(&c2dev->lock);
c2dev->pcidev = pcidev;
c2dev->cur_tx = 0;
c2dev->cur_rx =
(be32_to_cpu((__force __be32) readl(mmio_regs + C2_REGS_HRX_CUR)) -
0xffffc000) / sizeof(struct c2_rxp_desc);
ret = request_irq(pcidev->irq, c2_interrupt, IRQF_SHARED, DRV_NAME, c2dev);
if (ret) {
printk(KERN_ERR PFX "%s: requested IRQ %u is busy\n",
pci_name(pcidev), pcidev->irq);
iounmap(mmio_regs);
goto bail3;
}
pci_set_drvdata(pcidev, c2dev);
if ((netdev = c2_devinit(c2dev, mmio_regs)) == NULL) {
ret = -ENOMEM;
iounmap(mmio_regs);
goto bail4;
}
kva_map_size = be32_to_cpu((__force __be32) readl(mmio_regs + C2_REGS_PCI_WINSIZE));
iounmap(mmio_regs);
ret = register_netdev(netdev);
if (ret) {
printk(KERN_ERR PFX "Unable to register netdev, ret = %d\n",
ret);
goto bail5;
}
netif_stop_queue(netdev);
c2dev->mmio_rxp_ring = ioremap_nocache(reg4_start + C2_RXP_HRXDQ_OFFSET,
C2_RXP_HRXDQ_SIZE);
if (!c2dev->mmio_rxp_ring) {
printk(KERN_ERR PFX "Unable to remap MMIO HRXDQ region\n");
ret = -EIO;
goto bail6;
}
c2dev->mmio_txp_ring = ioremap_nocache(reg4_start + C2_TXP_HTXDQ_OFFSET,
C2_TXP_HTXDQ_SIZE);
if (!c2dev->mmio_txp_ring) {
printk(KERN_ERR PFX "Unable to remap MMIO HTXDQ region\n");
ret = -EIO;
goto bail7;
}
C2_SET_CUR_RX(c2dev, c2dev->cur_rx);
c2dev->regs = ioremap_nocache(reg0_start, reg0_len);
if (!c2dev->regs) {
printk(KERN_ERR PFX "Unable to remap BAR0\n");
ret = -EIO;
goto bail8;
}
c2dev->pa = reg4_start + C2_PCI_REGS_OFFSET;
c2dev->kva = ioremap_nocache(reg4_start + C2_PCI_REGS_OFFSET,
kva_map_size);
if (!c2dev->kva) {
printk(KERN_ERR PFX "Unable to remap BAR4\n");
ret = -EIO;
goto bail9;
}
c2_print_macaddr(netdev);
ret = c2_rnic_init(c2dev);
if (ret) {
printk(KERN_ERR PFX "c2_rnic_init failed: %d\n", ret);
goto bail10;
}
ret = c2_register_device(c2dev);
if (ret)
goto bail10;
return 0;
bail10:
iounmap(c2dev->kva);
bail9:
iounmap(c2dev->regs);
bail8:
iounmap(c2dev->mmio_txp_ring);
bail7:
iounmap(c2dev->mmio_rxp_ring);
bail6:
unregister_netdev(netdev);
bail5:
free_netdev(netdev);
bail4:
free_irq(pcidev->irq, c2dev);
bail3:
ib_dealloc_device(&c2dev->ibdev);
bail2:
pci_release_regions(pcidev);
bail1:
pci_disable_device(pcidev);
bail0:
return ret;
}
static void c2_remove(struct pci_dev *pcidev)
{
struct c2_dev *c2dev = pci_get_drvdata(pcidev);
struct net_device *netdev = c2dev->netdev;
c2_unregister_device(c2dev);
c2_rnic_term(c2dev);
unregister_netdev(netdev);
free_netdev(netdev);
free_irq(pcidev->irq, c2dev);
iounmap(c2dev->kva);
iounmap(c2dev->regs);
iounmap(c2dev->mmio_txp_ring);
iounmap(c2dev->mmio_rxp_ring);
ib_dealloc_device(&c2dev->ibdev);
pci_release_regions(pcidev);
pci_disable_device(pcidev);
pci_set_drvdata(pcidev, NULL);
}
