static unsigned int macb_tx_ring_wrap(unsigned int index)
{
return index & (TX_RING_SIZE - 1);
}
static struct macb_dma_desc *macb_tx_desc(struct macb_queue *queue,
unsigned int index)
{
return &queue->tx_ring[macb_tx_ring_wrap(index)];
}
static struct macb_tx_skb *macb_tx_skb(struct macb_queue *queue,
unsigned int index)
{
return &queue->tx_skb[macb_tx_ring_wrap(index)];
}
static dma_addr_t macb_tx_dma(struct macb_queue *queue, unsigned int index)
{
dma_addr_t offset;
offset = macb_tx_ring_wrap(index) * sizeof(struct macb_dma_desc);
return queue->tx_ring_dma + offset;
}
static unsigned int macb_rx_ring_wrap(unsigned int index)
{
return index & (RX_RING_SIZE - 1);
}
static struct macb_dma_desc *macb_rx_desc(struct macb *bp, unsigned int index)
{
return &bp->rx_ring[macb_rx_ring_wrap(index)];
}
static void *macb_rx_buffer(struct macb *bp, unsigned int index)
{
return bp->rx_buffers + bp->rx_buffer_size * macb_rx_ring_wrap(index);
}
static void macb_set_hwaddr(struct macb *bp)
{
u32 bottom;
u16 top;
bottom = cpu_to_le32(*((u32 *)bp->dev->dev_addr));
macb_or_gem_writel(bp, SA1B, bottom);
top = cpu_to_le16(*((u16 *)(bp->dev->dev_addr + 4)));
macb_or_gem_writel(bp, SA1T, top);
macb_or_gem_writel(bp, SA2B, 0);
macb_or_gem_writel(bp, SA2T, 0);
macb_or_gem_writel(bp, SA3B, 0);
macb_or_gem_writel(bp, SA3T, 0);
macb_or_gem_writel(bp, SA4B, 0);
macb_or_gem_writel(bp, SA4T, 0);
}
static void macb_get_hwaddr(struct macb *bp)
{
struct macb_platform_data *pdata;
u32 bottom;
u16 top;
u8 addr[6];
int i;
pdata = dev_get_platdata(&bp->pdev->dev);
for (i = 0; i < 4; i++) {
bottom = macb_or_gem_readl(bp, SA1B + i * 8);
top = macb_or_gem_readl(bp, SA1T + i * 8);
if (pdata && pdata->rev_eth_addr) {
addr[5] = bottom & 0xff;
addr[4] = (bottom >> 8) & 0xff;
addr[3] = (bottom >> 16) & 0xff;
addr[2] = (bottom >> 24) & 0xff;
addr[1] = top & 0xff;
addr[0] = (top & 0xff00) >> 8;
} else {
addr[0] = bottom & 0xff;
addr[1] = (bottom >> 8) & 0xff;
addr[2] = (bottom >> 16) & 0xff;
addr[3] = (bottom >> 24) & 0xff;
addr[4] = top & 0xff;
addr[5] = (top >> 8) & 0xff;
}
if (is_valid_ether_addr(addr)) {
memcpy(bp->dev->dev_addr, addr, sizeof(addr));
return;
}
}
netdev_info(bp->dev, "invalid hw address, using random\n");
eth_hw_addr_random(bp->dev);
}
static int macb_mdio_read(struct mii_bus *bus, int mii_id, int regnum)
{
struct macb *bp = bus->priv;
int value;
macb_writel(bp, MAN, (MACB_BF(SOF, MACB_MAN_SOF)
| MACB_BF(RW, MACB_MAN_READ)
| MACB_BF(PHYA, mii_id)
| MACB_BF(REGA, regnum)
| MACB_BF(CODE, MACB_MAN_CODE)));
while (!MACB_BFEXT(IDLE, macb_readl(bp, NSR)))
cpu_relax();
value = MACB_BFEXT(DATA, macb_readl(bp, MAN));
return value;
}
static int macb_mdio_write(struct mii_bus *bus, int mii_id, int regnum,
u16 value)
{
struct macb *bp = bus->priv;
macb_writel(bp, MAN, (MACB_BF(SOF, MACB_MAN_SOF)
| MACB_BF(RW, MACB_MAN_WRITE)
| MACB_BF(PHYA, mii_id)
| MACB_BF(REGA, regnum)
| MACB_BF(CODE, MACB_MAN_CODE)
| MACB_BF(DATA, value)));
while (!MACB_BFEXT(IDLE, macb_readl(bp, NSR)))
cpu_relax();
return 0;
}
static void macb_set_tx_clk(struct clk *clk, int speed, struct net_device *dev)
{
long ferr, rate, rate_rounded;
if (!clk)
return;
switch (speed) {
case SPEED_10:
rate = 2500000;
break;
case SPEED_100:
rate = 25000000;
break;
case SPEED_1000:
rate = 125000000;
break;
default:
return;
}
rate_rounded = clk_round_rate(clk, rate);
if (rate_rounded < 0)
return;
ferr = abs(rate_rounded - rate);
ferr = DIV_ROUND_UP(ferr, rate / 100000);
if (ferr > 5)
netdev_warn(dev, "unable to generate target frequency: %ld Hz\n",
rate);
if (clk_set_rate(clk, rate_rounded))
netdev_err(dev, "adjusting tx_clk failed.\n");
}
static void macb_handle_link_change(struct net_device *dev)
{
struct macb *bp = netdev_priv(dev);
struct phy_device *phydev = bp->phy_dev;
unsigned long flags;
int status_change = 0;
spin_lock_irqsave(&bp->lock, flags);
if (phydev->link) {
if ((bp->speed != phydev->speed) ||
(bp->duplex != phydev->duplex)) {
u32 reg;
reg = macb_readl(bp, NCFGR);
reg &= ~(MACB_BIT(SPD) | MACB_BIT(FD));
if (macb_is_gem(bp))
reg &= ~GEM_BIT(GBE);
if (phydev->duplex)
reg |= MACB_BIT(FD);
if (phydev->speed == SPEED_100)
reg |= MACB_BIT(SPD);
if (phydev->speed == SPEED_1000 &&
bp->caps & MACB_CAPS_GIGABIT_MODE_AVAILABLE)
reg |= GEM_BIT(GBE);
macb_or_gem_writel(bp, NCFGR, reg);
bp->speed = phydev->speed;
bp->duplex = phydev->duplex;
status_change = 1;
}
}
if (phydev->link != bp->link) {
if (!phydev->link) {
bp->speed = 0;
bp->duplex = -1;
}
bp->link = phydev->link;
status_change = 1;
}
spin_unlock_irqrestore(&bp->lock, flags);
if (status_change) {
if (phydev->link) {
macb_set_tx_clk(bp->tx_clk, phydev->speed, dev);
netif_carrier_on(dev);
netdev_info(dev, "link up (%d/%s)\n",
phydev->speed,
phydev->duplex == DUPLEX_FULL ?
"Full" : "Half");
} else {
netif_carrier_off(dev);
netdev_info(dev, "link down\n");
}
}
}
static int macb_mii_probe(struct net_device *dev)
{
struct macb *bp = netdev_priv(dev);
struct macb_platform_data *pdata;
struct phy_device *phydev;
int phy_irq;
int ret;
phydev = phy_find_first(bp->mii_bus);
if (!phydev) {
netdev_err(dev, "no PHY found\n");
return -ENXIO;
}
pdata = dev_get_platdata(&bp->pdev->dev);
if (pdata && gpio_is_valid(pdata->phy_irq_pin)) {
ret = devm_gpio_request(&bp->pdev->dev, pdata->phy_irq_pin, "phy int");
if (!ret) {
phy_irq = gpio_to_irq(pdata->phy_irq_pin);
phydev->irq = (phy_irq < 0) ? PHY_POLL : phy_irq;
}
}
ret = phy_connect_direct(dev, phydev, &macb_handle_link_change,
bp->phy_interface);
if (ret) {
netdev_err(dev, "Could not attach to PHY\n");
return ret;
}
if (macb_is_gem(bp) && bp->caps & MACB_CAPS_GIGABIT_MODE_AVAILABLE)
phydev->supported &= PHY_GBIT_FEATURES;
else
phydev->supported &= PHY_BASIC_FEATURES;
if (bp->caps & MACB_CAPS_NO_GIGABIT_HALF)
phydev->supported &= ~SUPPORTED_1000baseT_Half;
phydev->advertising = phydev->supported;
bp->link = 0;
bp->speed = 0;
bp->duplex = -1;
bp->phy_dev = phydev;
return 0;
}
static int macb_mii_init(struct macb *bp)
{
struct macb_platform_data *pdata;
struct device_node *np;
int err = -ENXIO, i;
macb_writel(bp, NCR, MACB_BIT(MPE));
bp->mii_bus = mdiobus_alloc();
if (bp->mii_bus == NULL) {
err = -ENOMEM;
goto err_out;
}
bp->mii_bus->name = "MACB_mii_bus";
bp->mii_bus->read = &macb_mdio_read;
bp->mii_bus->write = &macb_mdio_write;
snprintf(bp->mii_bus->id, MII_BUS_ID_SIZE, "%s-%x",
bp->pdev->name, bp->pdev->id);
bp->mii_bus->priv = bp;
bp->mii_bus->parent = &bp->dev->dev;
pdata = dev_get_platdata(&bp->pdev->dev);
bp->mii_bus->irq = kmalloc(sizeof(int)*PHY_MAX_ADDR, GFP_KERNEL);
if (!bp->mii_bus->irq) {
err = -ENOMEM;
goto err_out_free_mdiobus;
}
dev_set_drvdata(&bp->dev->dev, bp->mii_bus);
np = bp->pdev->dev.of_node;
if (np) {
err = of_mdiobus_register(bp->mii_bus, np);
if (!err && !phy_find_first(bp->mii_bus)) {
for (i = 0; i < PHY_MAX_ADDR; i++) {
struct phy_device *phydev;
phydev = mdiobus_scan(bp->mii_bus, i);
if (IS_ERR(phydev)) {
err = PTR_ERR(phydev);
break;
}
}
if (err)
goto err_out_unregister_bus;
}
} else {
for (i = 0; i < PHY_MAX_ADDR; i++)
bp->mii_bus->irq[i] = PHY_POLL;
if (pdata)
bp->mii_bus->phy_mask = pdata->phy_mask;
err = mdiobus_register(bp->mii_bus);
}
if (err)
goto err_out_free_mdio_irq;
err = macb_mii_probe(bp->dev);
if (err)
goto err_out_unregister_bus;
return 0;
err_out_unregister_bus:
mdiobus_unregister(bp->mii_bus);
err_out_free_mdio_irq:
kfree(bp->mii_bus->irq);
err_out_free_mdiobus:
mdiobus_free(bp->mii_bus);
err_out:
return err;
}
static void macb_update_stats(struct macb *bp)
{
u32 __iomem *reg = bp->regs + MACB_PFR;
u32 *p = &bp->hw_stats.macb.rx_pause_frames;
u32 *end = &bp->hw_stats.macb.tx_pause_frames + 1;
WARN_ON((unsigned long)(end - p - 1) != (MACB_TPF - MACB_PFR) / 4);
for(; p < end; p++, reg++)
*p += readl_relaxed(reg);
}
static int macb_halt_tx(struct macb *bp)
{
unsigned long halt_time, timeout;
u32 status;
macb_writel(bp, NCR, macb_readl(bp, NCR) | MACB_BIT(THALT));
timeout = jiffies + usecs_to_jiffies(MACB_HALT_TIMEOUT);
do {
halt_time = jiffies;
status = macb_readl(bp, TSR);
if (!(status & MACB_BIT(TGO)))
return 0;
usleep_range(10, 250);
} while (time_before(halt_time, timeout));
return -ETIMEDOUT;
}
static void macb_tx_unmap(struct macb *bp, struct macb_tx_skb *tx_skb)
{
if (tx_skb->mapping) {
if (tx_skb->mapped_as_page)
dma_unmap_page(&bp->pdev->dev, tx_skb->mapping,
tx_skb->size, DMA_TO_DEVICE);
else
dma_unmap_single(&bp->pdev->dev, tx_skb->mapping,
tx_skb->size, DMA_TO_DEVICE);
tx_skb->mapping = 0;
}
if (tx_skb->skb) {
dev_kfree_skb_any(tx_skb->skb);
tx_skb->skb = NULL;
}
}
static void macb_tx_error_task(struct work_struct *work)
{
struct macb_queue *queue = container_of(work, struct macb_queue,
tx_error_task);
struct macb *bp = queue->bp;
struct macb_tx_skb *tx_skb;
struct macb_dma_desc *desc;
struct sk_buff *skb;
unsigned int tail;
unsigned long flags;
netdev_vdbg(bp->dev, "macb_tx_error_task: q = %u, t = %u, h = %u\n",
(unsigned int)(queue - bp->queues),
queue->tx_tail, queue->tx_head);
spin_lock_irqsave(&bp->lock, flags);
netif_tx_stop_all_queues(bp->dev);
if (macb_halt_tx(bp))
netdev_err(bp->dev, "BUG: halt tx timed out\n");
for (tail = queue->tx_tail; tail != queue->tx_head; tail++) {
u32 ctrl;
desc = macb_tx_desc(queue, tail);
ctrl = desc->ctrl;
tx_skb = macb_tx_skb(queue, tail);
skb = tx_skb->skb;
if (ctrl & MACB_BIT(TX_USED)) {
while (!skb) {
macb_tx_unmap(bp, tx_skb);
tail++;
tx_skb = macb_tx_skb(queue, tail);
skb = tx_skb->skb;
}
if (!(ctrl & MACB_BIT(TX_BUF_EXHAUSTED))) {
netdev_vdbg(bp->dev, "txerr skb %u (data %p) TX complete\n",
macb_tx_ring_wrap(tail), skb->data);
bp->stats.tx_packets++;
bp->stats.tx_bytes += skb->len;
}
} else {
if (ctrl & MACB_BIT(TX_BUF_EXHAUSTED))
netdev_err(bp->dev,
"BUG: TX buffers exhausted mid-frame\n");
desc->ctrl = ctrl | MACB_BIT(TX_USED);
}
macb_tx_unmap(bp, tx_skb);
}
desc = macb_tx_desc(queue, 0);
desc->addr = 0;
desc->ctrl = MACB_BIT(TX_USED);
wmb();
queue_writel(queue, TBQP, queue->tx_ring_dma);
queue->tx_head = 0;
queue->tx_tail = 0;
macb_writel(bp, TSR, macb_readl(bp, TSR));
queue_writel(queue, IER, MACB_TX_INT_FLAGS);
netif_tx_start_all_queues(bp->dev);
macb_writel(bp, NCR, macb_readl(bp, NCR) | MACB_BIT(TSTART));
spin_unlock_irqrestore(&bp->lock, flags);
}
static void macb_tx_interrupt(struct macb_queue *queue)
{
unsigned int tail;
unsigned int head;
u32 status;
struct macb *bp = queue->bp;
u16 queue_index = queue - bp->queues;
status = macb_readl(bp, TSR);
macb_writel(bp, TSR, status);
if (bp->caps & MACB_CAPS_ISR_CLEAR_ON_WRITE)
queue_writel(queue, ISR, MACB_BIT(TCOMP));
netdev_vdbg(bp->dev, "macb_tx_interrupt status = 0x%03lx\n",
(unsigned long)status);
head = queue->tx_head;
for (tail = queue->tx_tail; tail != head; tail++) {
struct macb_tx_skb *tx_skb;
struct sk_buff *skb;
struct macb_dma_desc *desc;
u32 ctrl;
desc = macb_tx_desc(queue, tail);
rmb();
ctrl = desc->ctrl;
if (!(ctrl & MACB_BIT(TX_USED)))
break;
for (;; tail++) {
tx_skb = macb_tx_skb(queue, tail);
skb = tx_skb->skb;
if (skb) {
netdev_vdbg(bp->dev, "skb %u (data %p) TX complete\n",
macb_tx_ring_wrap(tail), skb->data);
bp->stats.tx_packets++;
bp->stats.tx_bytes += skb->len;
}
macb_tx_unmap(bp, tx_skb);
if (skb)
break;
}
}
queue->tx_tail = tail;
if (__netif_subqueue_stopped(bp->dev, queue_index) &&
CIRC_CNT(queue->tx_head, queue->tx_tail,
TX_RING_SIZE) <= MACB_TX_WAKEUP_THRESH)
netif_wake_subqueue(bp->dev, queue_index);
}
static void gem_rx_refill(struct macb *bp)
{
unsigned int entry;
struct sk_buff *skb;
dma_addr_t paddr;
while (CIRC_SPACE(bp->rx_prepared_head, bp->rx_tail, RX_RING_SIZE) > 0) {
entry = macb_rx_ring_wrap(bp->rx_prepared_head);
rmb();
bp->rx_prepared_head++;
if (bp->rx_skbuff[entry] == NULL) {
skb = netdev_alloc_skb(bp->dev, bp->rx_buffer_size);
if (unlikely(skb == NULL)) {
netdev_err(bp->dev,
"Unable to allocate sk_buff\n");
break;
}
paddr = dma_map_single(&bp->pdev->dev, skb->data,
bp->rx_buffer_size, DMA_FROM_DEVICE);
if (dma_mapping_error(&bp->pdev->dev, paddr)) {
dev_kfree_skb(skb);
break;
}
bp->rx_skbuff[entry] = skb;
if (entry == RX_RING_SIZE - 1)
paddr |= MACB_BIT(RX_WRAP);
bp->rx_ring[entry].addr = paddr;
bp->rx_ring[entry].ctrl = 0;
skb_reserve(skb, NET_IP_ALIGN);
} else {
bp->rx_ring[entry].addr &= ~MACB_BIT(RX_USED);
bp->rx_ring[entry].ctrl = 0;
}
}
wmb();
netdev_vdbg(bp->dev, "rx ring: prepared head %d, tail %d\n",
bp->rx_prepared_head, bp->rx_tail);
}
static void discard_partial_frame(struct macb *bp, unsigned int begin,
unsigned int end)
{
unsigned int frag;
for (frag = begin; frag != end; frag++) {
struct macb_dma_desc *desc = macb_rx_desc(bp, frag);
desc->addr &= ~MACB_BIT(RX_USED);
}
wmb();
}
static int gem_rx(struct macb *bp, int budget)
{
unsigned int len;
unsigned int entry;
struct sk_buff *skb;
struct macb_dma_desc *desc;
int count = 0;
while (count < budget) {
u32 addr, ctrl;
entry = macb_rx_ring_wrap(bp->rx_tail);
desc = &bp->rx_ring[entry];
rmb();
addr = desc->addr;
ctrl = desc->ctrl;
if (!(addr & MACB_BIT(RX_USED)))
break;
bp->rx_tail++;
count++;
if (!(ctrl & MACB_BIT(RX_SOF) && ctrl & MACB_BIT(RX_EOF))) {
netdev_err(bp->dev,
"not whole frame pointed by descriptor\n");
bp->stats.rx_dropped++;
break;
}
skb = bp->rx_skbuff[entry];
if (unlikely(!skb)) {
netdev_err(bp->dev,
"inconsistent Rx descriptor chain\n");
bp->stats.rx_dropped++;
break;
}
bp->rx_skbuff[entry] = NULL;
len = MACB_BFEXT(RX_FRMLEN, ctrl);
netdev_vdbg(bp->dev, "gem_rx %u (len %u)\n", entry, len);
skb_put(skb, len);
addr = MACB_BF(RX_WADDR, MACB_BFEXT(RX_WADDR, addr));
dma_unmap_single(&bp->pdev->dev, addr,
bp->rx_buffer_size, DMA_FROM_DEVICE);
skb->protocol = eth_type_trans(skb, bp->dev);
skb_checksum_none_assert(skb);
if (bp->dev->features & NETIF_F_RXCSUM &&
!(bp->dev->flags & IFF_PROMISC) &&
GEM_BFEXT(RX_CSUM, ctrl) & GEM_RX_CSUM_CHECKED_MASK)
skb->ip_summed = CHECKSUM_UNNECESSARY;
bp->stats.rx_packets++;
bp->stats.rx_bytes += skb->len;
#if defined(DEBUG) && defined(VERBOSE_DEBUG)
netdev_vdbg(bp->dev, "received skb of length %u, csum: %08x\n",
skb->len, skb->csum);
print_hex_dump(KERN_DEBUG, " mac: ", DUMP_PREFIX_ADDRESS, 16, 1,
skb_mac_header(skb), 16, true);
print_hex_dump(KERN_DEBUG, "data: ", DUMP_PREFIX_ADDRESS, 16, 1,
skb->data, 32, true);
#endif
netif_receive_skb(skb);
}
gem_rx_refill(bp);
return count;
}
static int macb_rx_frame(struct macb *bp, unsigned int first_frag,
unsigned int last_frag)
{
unsigned int len;
unsigned int frag;
unsigned int offset;
struct sk_buff *skb;
struct macb_dma_desc *desc;
desc = macb_rx_desc(bp, last_frag);
len = MACB_BFEXT(RX_FRMLEN, desc->ctrl);
netdev_vdbg(bp->dev, "macb_rx_frame frags %u - %u (len %u)\n",
macb_rx_ring_wrap(first_frag),
macb_rx_ring_wrap(last_frag), len);
skb = netdev_alloc_skb(bp->dev, len + NET_IP_ALIGN);
if (!skb) {
bp->stats.rx_dropped++;
for (frag = first_frag; ; frag++) {
desc = macb_rx_desc(bp, frag);
desc->addr &= ~MACB_BIT(RX_USED);
if (frag == last_frag)
break;
}
wmb();
return 1;
}
offset = 0;
len += NET_IP_ALIGN;
skb_checksum_none_assert(skb);
skb_put(skb, len);
for (frag = first_frag; ; frag++) {
unsigned int frag_len = bp->rx_buffer_size;
if (offset + frag_len > len) {
BUG_ON(frag != last_frag);
frag_len = len - offset;
}
skb_copy_to_linear_data_offset(skb, offset,
macb_rx_buffer(bp, frag), frag_len);
offset += bp->rx_buffer_size;
desc = macb_rx_desc(bp, frag);
desc->addr &= ~MACB_BIT(RX_USED);
if (frag == last_frag)
break;
}
wmb();
__skb_pull(skb, NET_IP_ALIGN);
skb->protocol = eth_type_trans(skb, bp->dev);
bp->stats.rx_packets++;
bp->stats.rx_bytes += skb->len;
netdev_vdbg(bp->dev, "received skb of length %u, csum: %08x\n",
skb->len, skb->csum);
netif_receive_skb(skb);
return 0;
}
static int macb_rx(struct macb *bp, int budget)
{
int received = 0;
unsigned int tail;
int first_frag = -1;
for (tail = bp->rx_tail; budget > 0; tail++) {
struct macb_dma_desc *desc = macb_rx_desc(bp, tail);
u32 addr, ctrl;
rmb();
addr = desc->addr;
ctrl = desc->ctrl;
if (!(addr & MACB_BIT(RX_USED)))
break;
if (ctrl & MACB_BIT(RX_SOF)) {
if (first_frag != -1)
discard_partial_frame(bp, first_frag, tail);
first_frag = tail;
}
if (ctrl & MACB_BIT(RX_EOF)) {
int dropped;
BUG_ON(first_frag == -1);
dropped = macb_rx_frame(bp, first_frag, tail);
first_frag = -1;
if (!dropped) {
received++;
budget--;
}
}
}
if (first_frag != -1)
bp->rx_tail = first_frag;
else
bp->rx_tail = tail;
return received;
}
static int macb_poll(struct napi_struct *napi, int budget)
{
struct macb *bp = container_of(napi, struct macb, napi);
int work_done;
u32 status;
status = macb_readl(bp, RSR);
macb_writel(bp, RSR, status);
work_done = 0;
netdev_vdbg(bp->dev, "poll: status = %08lx, budget = %d\n",
(unsigned long)status, budget);
work_done = bp->macbgem_ops.mog_rx(bp, budget);
if (work_done < budget) {
napi_complete(napi);
status = macb_readl(bp, RSR);
if (status) {
if (bp->caps & MACB_CAPS_ISR_CLEAR_ON_WRITE)
macb_writel(bp, ISR, MACB_BIT(RCOMP));
napi_reschedule(napi);
} else {
macb_writel(bp, IER, MACB_RX_INT_FLAGS);
}
}
return work_done;
}
static irqreturn_t macb_interrupt(int irq, void *dev_id)
{
struct macb_queue *queue = dev_id;
struct macb *bp = queue->bp;
struct net_device *dev = bp->dev;
u32 status, ctrl;
status = queue_readl(queue, ISR);
if (unlikely(!status))
return IRQ_NONE;
spin_lock(&bp->lock);
while (status) {
if (unlikely(!netif_running(dev))) {
queue_writel(queue, IDR, -1);
break;
}
netdev_vdbg(bp->dev, "queue = %u, isr = 0x%08lx\n",
(unsigned int)(queue - bp->queues),
(unsigned long)status);
if (status & MACB_RX_INT_FLAGS) {
queue_writel(queue, IDR, MACB_RX_INT_FLAGS);
if (bp->caps & MACB_CAPS_ISR_CLEAR_ON_WRITE)
queue_writel(queue, ISR, MACB_BIT(RCOMP));
if (napi_schedule_prep(&bp->napi)) {
netdev_vdbg(bp->dev, "scheduling RX softirq\n");
__napi_schedule(&bp->napi);
}
}
if (unlikely(status & (MACB_TX_ERR_FLAGS))) {
queue_writel(queue, IDR, MACB_TX_INT_FLAGS);
schedule_work(&queue->tx_error_task);
if (bp->caps & MACB_CAPS_ISR_CLEAR_ON_WRITE)
queue_writel(queue, ISR, MACB_TX_ERR_FLAGS);
break;
}
if (status & MACB_BIT(TCOMP))
macb_tx_interrupt(queue);
if (status & MACB_BIT(RXUBR)) {
ctrl = macb_readl(bp, NCR);
macb_writel(bp, NCR, ctrl & ~MACB_BIT(RE));
macb_writel(bp, NCR, ctrl | MACB_BIT(RE));
if (bp->caps & MACB_CAPS_ISR_CLEAR_ON_WRITE)
macb_writel(bp, ISR, MACB_BIT(RXUBR));
}
if (status & MACB_BIT(ISR_ROVR)) {
if (macb_is_gem(bp))
bp->hw_stats.gem.rx_overruns++;
else
bp->hw_stats.macb.rx_overruns++;
if (bp->caps & MACB_CAPS_ISR_CLEAR_ON_WRITE)
queue_writel(queue, ISR, MACB_BIT(ISR_ROVR));
}
if (status & MACB_BIT(HRESP)) {
netdev_err(dev, "DMA bus error: HRESP not OK\n");
if (bp->caps & MACB_CAPS_ISR_CLEAR_ON_WRITE)
queue_writel(queue, ISR, MACB_BIT(HRESP));
}
status = queue_readl(queue, ISR);
}
spin_unlock(&bp->lock);
return IRQ_HANDLED;
}
static void macb_poll_controller(struct net_device *dev)
{
struct macb *bp = netdev_priv(dev);
struct macb_queue *queue;
unsigned long flags;
unsigned int q;
local_irq_save(flags);
for (q = 0, queue = bp->queues; q < bp->num_queues; ++q, ++queue)
macb_interrupt(dev->irq, queue);
local_irq_restore(flags);
}
static inline unsigned int macb_count_tx_descriptors(struct macb *bp,
unsigned int len)
{
return (len + bp->max_tx_length - 1) / bp->max_tx_length;
}
static unsigned int macb_tx_map(struct macb *bp,
struct macb_queue *queue,
struct sk_buff *skb)
{
dma_addr_t mapping;
unsigned int len, entry, i, tx_head = queue->tx_head;
struct macb_tx_skb *tx_skb = NULL;
struct macb_dma_desc *desc;
unsigned int offset, size, count = 0;
unsigned int f, nr_frags = skb_shinfo(skb)->nr_frags;
unsigned int eof = 1;
u32 ctrl;
len = skb_headlen(skb);
offset = 0;
while (len) {
size = min(len, bp->max_tx_length);
entry = macb_tx_ring_wrap(tx_head);
tx_skb = &queue->tx_skb[entry];
mapping = dma_map_single(&bp->pdev->dev,
skb->data + offset,
size, DMA_TO_DEVICE);
if (dma_mapping_error(&bp->pdev->dev, mapping))
goto dma_error;
tx_skb->skb = NULL;
tx_skb->mapping = mapping;
tx_skb->size = size;
tx_skb->mapped_as_page = false;
len -= size;
offset += size;
count++;
tx_head++;
}
for (f = 0; f < nr_frags; f++) {
const skb_frag_t *frag = &skb_shinfo(skb)->frags[f];
len = skb_frag_size(frag);
offset = 0;
while (len) {
size = min(len, bp->max_tx_length);
entry = macb_tx_ring_wrap(tx_head);
tx_skb = &queue->tx_skb[entry];
mapping = skb_frag_dma_map(&bp->pdev->dev, frag,
offset, size, DMA_TO_DEVICE);
if (dma_mapping_error(&bp->pdev->dev, mapping))
goto dma_error;
tx_skb->skb = NULL;
tx_skb->mapping = mapping;
tx_skb->size = size;
tx_skb->mapped_as_page = true;
len -= size;
offset += size;
count++;
tx_head++;
}
}
if (unlikely(tx_skb == NULL)) {
netdev_err(bp->dev, "BUG! empty skb!\n");
return 0;
}
tx_skb->skb = skb;
i = tx_head;
entry = macb_tx_ring_wrap(i);
ctrl = MACB_BIT(TX_USED);
desc = &queue->tx_ring[entry];
desc->ctrl = ctrl;
do {
i--;
entry = macb_tx_ring_wrap(i);
tx_skb = &queue->tx_skb[entry];
desc = &queue->tx_ring[entry];
ctrl = (u32)tx_skb->size;
if (eof) {
ctrl |= MACB_BIT(TX_LAST);
eof = 0;
}
if (unlikely(entry == (TX_RING_SIZE - 1)))
ctrl |= MACB_BIT(TX_WRAP);
desc->addr = tx_skb->mapping;
wmb();
desc->ctrl = ctrl;
} while (i != queue->tx_head);
queue->tx_head = tx_head;
return count;
dma_error:
netdev_err(bp->dev, "TX DMA map failed\n");
for (i = queue->tx_head; i != tx_head; i++) {
tx_skb = macb_tx_skb(queue, i);
macb_tx_unmap(bp, tx_skb);
}
return 0;
}
static int macb_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
u16 queue_index = skb_get_queue_mapping(skb);
struct macb *bp = netdev_priv(dev);
struct macb_queue *queue = &bp->queues[queue_index];
unsigned long flags;
unsigned int count, nr_frags, frag_size, f;
#if defined(DEBUG) && defined(VERBOSE_DEBUG)
netdev_vdbg(bp->dev,
"start_xmit: queue %hu len %u head %p data %p tail %p end %p\n",
queue_index, skb->len, skb->head, skb->data,
skb_tail_pointer(skb), skb_end_pointer(skb));
print_hex_dump(KERN_DEBUG, "data: ", DUMP_PREFIX_OFFSET, 16, 1,
skb->data, 16, true);
#endif
count = macb_count_tx_descriptors(bp, skb_headlen(skb));
nr_frags = skb_shinfo(skb)->nr_frags;
for (f = 0; f < nr_frags; f++) {
frag_size = skb_frag_size(&skb_shinfo(skb)->frags[f]);
count += macb_count_tx_descriptors(bp, frag_size);
}
spin_lock_irqsave(&bp->lock, flags);
if (CIRC_SPACE(queue->tx_head, queue->tx_tail, TX_RING_SIZE) < count) {
netif_stop_subqueue(dev, queue_index);
spin_unlock_irqrestore(&bp->lock, flags);
netdev_dbg(bp->dev, "tx_head = %u, tx_tail = %u\n",
queue->tx_head, queue->tx_tail);
return NETDEV_TX_BUSY;
}
if (!macb_tx_map(bp, queue, skb)) {
dev_kfree_skb_any(skb);
goto unlock;
}
wmb();
skb_tx_timestamp(skb);
macb_writel(bp, NCR, macb_readl(bp, NCR) | MACB_BIT(TSTART));
if (CIRC_SPACE(queue->tx_head, queue->tx_tail, TX_RING_SIZE) < 1)
netif_stop_subqueue(dev, queue_index);
unlock:
spin_unlock_irqrestore(&bp->lock, flags);
return NETDEV_TX_OK;
}
static void macb_init_rx_buffer_size(struct macb *bp, size_t size)
{
if (!macb_is_gem(bp)) {
bp->rx_buffer_size = MACB_RX_BUFFER_SIZE;
} else {
bp->rx_buffer_size = size;
if (bp->rx_buffer_size % RX_BUFFER_MULTIPLE) {
netdev_dbg(bp->dev,
"RX buffer must be multiple of %d bytes, expanding\n",
RX_BUFFER_MULTIPLE);
bp->rx_buffer_size =
roundup(bp->rx_buffer_size, RX_BUFFER_MULTIPLE);
}
}
netdev_dbg(bp->dev, "mtu [%u] rx_buffer_size [%Zu]\n",
bp->dev->mtu, bp->rx_buffer_size);
}
static void gem_free_rx_buffers(struct macb *bp)
{
struct sk_buff *skb;
struct macb_dma_desc *desc;
dma_addr_t addr;
int i;
if (!bp->rx_skbuff)
return;
for (i = 0; i < RX_RING_SIZE; i++) {
skb = bp->rx_skbuff[i];
if (skb == NULL)
continue;
desc = &bp->rx_ring[i];
addr = MACB_BF(RX_WADDR, MACB_BFEXT(RX_WADDR, desc->addr));
dma_unmap_single(&bp->pdev->dev, addr, bp->rx_buffer_size,
DMA_FROM_DEVICE);
dev_kfree_skb_any(skb);
skb = NULL;
}
kfree(bp->rx_skbuff);
bp->rx_skbuff = NULL;
}
static void macb_free_rx_buffers(struct macb *bp)
{
if (bp->rx_buffers) {
dma_free_coherent(&bp->pdev->dev,
RX_RING_SIZE * bp->rx_buffer_size,
bp->rx_buffers, bp->rx_buffers_dma);
bp->rx_buffers = NULL;
}
}
static void macb_free_consistent(struct macb *bp)
{
struct macb_queue *queue;
unsigned int q;
bp->macbgem_ops.mog_free_rx_buffers(bp);
if (bp->rx_ring) {
dma_free_coherent(&bp->pdev->dev, RX_RING_BYTES,
bp->rx_ring, bp->rx_ring_dma);
bp->rx_ring = NULL;
}
for (q = 0, queue = bp->queues; q < bp->num_queues; ++q, ++queue) {
kfree(queue->tx_skb);
queue->tx_skb = NULL;
if (queue->tx_ring) {
dma_free_coherent(&bp->pdev->dev, TX_RING_BYTES,
queue->tx_ring, queue->tx_ring_dma);
queue->tx_ring = NULL;
}
}
}
static int gem_alloc_rx_buffers(struct macb *bp)
{
int size;
size = RX_RING_SIZE * sizeof(struct sk_buff *);
bp->rx_skbuff = kzalloc(size, GFP_KERNEL);
if (!bp->rx_skbuff)
return -ENOMEM;
else
netdev_dbg(bp->dev,
"Allocated %d RX struct sk_buff entries at %p\n",
RX_RING_SIZE, bp->rx_skbuff);
return 0;
}
static int macb_alloc_rx_buffers(struct macb *bp)
{
int size;
size = RX_RING_SIZE * bp->rx_buffer_size;
bp->rx_buffers = dma_alloc_coherent(&bp->pdev->dev, size,
&bp->rx_buffers_dma, GFP_KERNEL);
if (!bp->rx_buffers)
return -ENOMEM;
else
netdev_dbg(bp->dev,
"Allocated RX buffers of %d bytes at %08lx (mapped %p)\n",
size, (unsigned long)bp->rx_buffers_dma, bp->rx_buffers);
return 0;
}
static int macb_alloc_consistent(struct macb *bp)
{
struct macb_queue *queue;
unsigned int q;
int size;
for (q = 0, queue = bp->queues; q < bp->num_queues; ++q, ++queue) {
size = TX_RING_BYTES;
queue->tx_ring = dma_alloc_coherent(&bp->pdev->dev, size,
&queue->tx_ring_dma,
GFP_KERNEL);
if (!queue->tx_ring)
goto out_err;
netdev_dbg(bp->dev,
"Allocated TX ring for queue %u of %d bytes at %08lx (mapped %p)\n",
q, size, (unsigned long)queue->tx_ring_dma,
queue->tx_ring);
size = TX_RING_SIZE * sizeof(struct macb_tx_skb);
queue->tx_skb = kmalloc(size, GFP_KERNEL);
if (!queue->tx_skb)
goto out_err;
}
size = RX_RING_BYTES;
bp->rx_ring = dma_alloc_coherent(&bp->pdev->dev, size,
&bp->rx_ring_dma, GFP_KERNEL);
if (!bp->rx_ring)
goto out_err;
netdev_dbg(bp->dev,
"Allocated RX ring of %d bytes at %08lx (mapped %p)\n",
size, (unsigned long)bp->rx_ring_dma, bp->rx_ring);
if (bp->macbgem_ops.mog_alloc_rx_buffers(bp))
goto out_err;
return 0;
out_err:
macb_free_consistent(bp);
return -ENOMEM;
}
static void gem_init_rings(struct macb *bp)
{
struct macb_queue *queue;
unsigned int q;
int i;
for (q = 0, queue = bp->queues; q < bp->num_queues; ++q, ++queue) {
for (i = 0; i < TX_RING_SIZE; i++) {
queue->tx_ring[i].addr = 0;
queue->tx_ring[i].ctrl = MACB_BIT(TX_USED);
}
queue->tx_ring[TX_RING_SIZE - 1].ctrl |= MACB_BIT(TX_WRAP);
queue->tx_head = 0;
queue->tx_tail = 0;
}
bp->rx_tail = 0;
bp->rx_prepared_head = 0;
gem_rx_refill(bp);
}
static void macb_init_rings(struct macb *bp)
{
int i;
dma_addr_t addr;
addr = bp->rx_buffers_dma;
for (i = 0; i < RX_RING_SIZE; i++) {
bp->rx_ring[i].addr = addr;
bp->rx_ring[i].ctrl = 0;
addr += bp->rx_buffer_size;
}
bp->rx_ring[RX_RING_SIZE - 1].addr |= MACB_BIT(RX_WRAP);
for (i = 0; i < TX_RING_SIZE; i++) {
bp->queues[0].tx_ring[i].addr = 0;
bp->queues[0].tx_ring[i].ctrl = MACB_BIT(TX_USED);
}
bp->queues[0].tx_head = 0;
bp->queues[0].tx_tail = 0;
bp->queues[0].tx_ring[TX_RING_SIZE - 1].ctrl |= MACB_BIT(TX_WRAP);
bp->rx_tail = 0;
}
static void macb_reset_hw(struct macb *bp)
{
struct macb_queue *queue;
unsigned int q;
macb_writel(bp, NCR, 0);
macb_writel(bp, NCR, MACB_BIT(CLRSTAT));
macb_writel(bp, TSR, -1);
macb_writel(bp, RSR, -1);
for (q = 0, queue = bp->queues; q < bp->num_queues; ++q, ++queue) {
queue_writel(queue, IDR, -1);
queue_readl(queue, ISR);
}
}
static u32 gem_mdc_clk_div(struct macb *bp)
{
u32 config;
unsigned long pclk_hz = clk_get_rate(bp->pclk);
if (pclk_hz <= 20000000)
config = GEM_BF(CLK, GEM_CLK_DIV8);
else if (pclk_hz <= 40000000)
config = GEM_BF(CLK, GEM_CLK_DIV16);
else if (pclk_hz <= 80000000)
config = GEM_BF(CLK, GEM_CLK_DIV32);
else if (pclk_hz <= 120000000)
config = GEM_BF(CLK, GEM_CLK_DIV48);
else if (pclk_hz <= 160000000)
config = GEM_BF(CLK, GEM_CLK_DIV64);
else
config = GEM_BF(CLK, GEM_CLK_DIV96);
return config;
}
static u32 macb_mdc_clk_div(struct macb *bp)
{
u32 config;
unsigned long pclk_hz;
if (macb_is_gem(bp))
return gem_mdc_clk_div(bp);
pclk_hz = clk_get_rate(bp->pclk);
if (pclk_hz <= 20000000)
config = MACB_BF(CLK, MACB_CLK_DIV8);
else if (pclk_hz <= 40000000)
config = MACB_BF(CLK, MACB_CLK_DIV16);
else if (pclk_hz <= 80000000)
config = MACB_BF(CLK, MACB_CLK_DIV32);
else
config = MACB_BF(CLK, MACB_CLK_DIV64);
return config;
}
static u32 macb_dbw(struct macb *bp)
{
if (!macb_is_gem(bp))
return 0;
switch (GEM_BFEXT(DBWDEF, gem_readl(bp, DCFG1))) {
case 4:
return GEM_BF(DBW, GEM_DBW128);
case 2:
return GEM_BF(DBW, GEM_DBW64);
case 1:
default:
return GEM_BF(DBW, GEM_DBW32);
}
}
static void macb_configure_dma(struct macb *bp)
{
u32 dmacfg;
u32 tmp, ncr;
if (macb_is_gem(bp)) {
dmacfg = gem_readl(bp, DMACFG) & ~GEM_BF(RXBS, -1L);
dmacfg |= GEM_BF(RXBS, bp->rx_buffer_size / RX_BUFFER_MULTIPLE);
if (bp->dma_burst_length)
dmacfg = GEM_BFINS(FBLDO, bp->dma_burst_length, dmacfg);
dmacfg |= GEM_BIT(TXPBMS) | GEM_BF(RXBMS, -1L);
dmacfg &= ~GEM_BIT(ENDIA_PKT);
ncr = macb_readl(bp, NCR);
__raw_writel(MACB_BIT(LLB), bp->regs + MACB_NCR);
tmp = __raw_readl(bp->regs + MACB_NCR);
if (tmp == MACB_BIT(LLB))
dmacfg &= ~GEM_BIT(ENDIA_DESC);
else
dmacfg |= GEM_BIT(ENDIA_DESC);
macb_writel(bp, NCR, ncr);
if (bp->dev->features & NETIF_F_HW_CSUM)
dmacfg |= GEM_BIT(TXCOEN);
else
dmacfg &= ~GEM_BIT(TXCOEN);
netdev_dbg(bp->dev, "Cadence configure DMA with 0x%08x\n",
dmacfg);
gem_writel(bp, DMACFG, dmacfg);
}
}
static void macb_init_hw(struct macb *bp)
{
struct macb_queue *queue;
unsigned int q;
u32 config;
macb_reset_hw(bp);
macb_set_hwaddr(bp);
config = macb_mdc_clk_div(bp);
config |= MACB_BF(RBOF, NET_IP_ALIGN);
config |= MACB_BIT(PAE);
config |= MACB_BIT(DRFCS);
config |= MACB_BIT(BIG);
if (bp->dev->flags & IFF_PROMISC)
config |= MACB_BIT(CAF);
else if (macb_is_gem(bp) && bp->dev->features & NETIF_F_RXCSUM)
config |= GEM_BIT(RXCOEN);
if (!(bp->dev->flags & IFF_BROADCAST))
config |= MACB_BIT(NBC);
config |= macb_dbw(bp);
macb_writel(bp, NCFGR, config);
bp->speed = SPEED_10;
bp->duplex = DUPLEX_HALF;
macb_configure_dma(bp);
macb_writel(bp, RBQP, bp->rx_ring_dma);
for (q = 0, queue = bp->queues; q < bp->num_queues; ++q, ++queue) {
queue_writel(queue, TBQP, queue->tx_ring_dma);
queue_writel(queue, IER,
MACB_RX_INT_FLAGS |
MACB_TX_INT_FLAGS |
MACB_BIT(HRESP));
}
macb_writel(bp, NCR, MACB_BIT(RE) | MACB_BIT(TE) | MACB_BIT(MPE));
}
static inline int hash_bit_value(int bitnr, __u8 *addr)
{
if (addr[bitnr / 8] & (1 << (bitnr % 8)))
return 1;
return 0;
}
static int hash_get_index(__u8 *addr)
{
int i, j, bitval;
int hash_index = 0;
for (j = 0; j < 6; j++) {
for (i = 0, bitval = 0; i < 8; i++)
bitval ^= hash_bit_value(i * 6 + j, addr);
hash_index |= (bitval << j);
}
return hash_index;
}
static void macb_sethashtable(struct net_device *dev)
{
struct netdev_hw_addr *ha;
unsigned long mc_filter[2];
unsigned int bitnr;
struct macb *bp = netdev_priv(dev);
mc_filter[0] = mc_filter[1] = 0;
netdev_for_each_mc_addr(ha, dev) {
bitnr = hash_get_index(ha->addr);
mc_filter[bitnr >> 5] |= 1 << (bitnr & 31);
}
macb_or_gem_writel(bp, HRB, mc_filter[0]);
macb_or_gem_writel(bp, HRT, mc_filter[1]);
}
static void macb_set_rx_mode(struct net_device *dev)
{
unsigned long cfg;
struct macb *bp = netdev_priv(dev);
cfg = macb_readl(bp, NCFGR);
if (dev->flags & IFF_PROMISC) {
cfg |= MACB_BIT(CAF);
if (macb_is_gem(bp))
cfg &= ~GEM_BIT(RXCOEN);
} else {
cfg &= ~MACB_BIT(CAF);
if (macb_is_gem(bp) && dev->features & NETIF_F_RXCSUM)
cfg |= GEM_BIT(RXCOEN);
}
if (dev->flags & IFF_ALLMULTI) {
macb_or_gem_writel(bp, HRB, -1);
macb_or_gem_writel(bp, HRT, -1);
cfg |= MACB_BIT(NCFGR_MTI);
} else if (!netdev_mc_empty(dev)) {
macb_sethashtable(dev);
cfg |= MACB_BIT(NCFGR_MTI);
} else if (dev->flags & (~IFF_ALLMULTI)) {
macb_or_gem_writel(bp, HRB, 0);
macb_or_gem_writel(bp, HRT, 0);
cfg &= ~MACB_BIT(NCFGR_MTI);
}
macb_writel(bp, NCFGR, cfg);
}
static int macb_open(struct net_device *dev)
{
struct macb *bp = netdev_priv(dev);
size_t bufsz = dev->mtu + ETH_HLEN + ETH_FCS_LEN + NET_IP_ALIGN;
int err;
netdev_dbg(bp->dev, "open\n");
netif_carrier_off(dev);
if (!bp->phy_dev)
return -EAGAIN;
macb_init_rx_buffer_size(bp, bufsz);
err = macb_alloc_consistent(bp);
if (err) {
netdev_err(dev, "Unable to allocate DMA memory (error %d)\n",
err);
return err;
}
napi_enable(&bp->napi);
bp->macbgem_ops.mog_init_rings(bp);
macb_init_hw(bp);
phy_start(bp->phy_dev);
netif_tx_start_all_queues(dev);
return 0;
}
static int macb_close(struct net_device *dev)
{
struct macb *bp = netdev_priv(dev);
unsigned long flags;
netif_tx_stop_all_queues(dev);
napi_disable(&bp->napi);
if (bp->phy_dev)
phy_stop(bp->phy_dev);
spin_lock_irqsave(&bp->lock, flags);
macb_reset_hw(bp);
netif_carrier_off(dev);
spin_unlock_irqrestore(&bp->lock, flags);
macb_free_consistent(bp);
return 0;
}
static void gem_update_stats(struct macb *bp)
{
int i;
u32 *p = &bp->hw_stats.gem.tx_octets_31_0;
for (i = 0; i < GEM_STATS_LEN; ++i, ++p) {
u32 offset = gem_statistics[i].offset;
u64 val = readl_relaxed(bp->regs + offset);
bp->ethtool_stats[i] += val;
*p += val;
if (offset == GEM_OCTTXL || offset == GEM_OCTRXL) {
val = readl_relaxed(bp->regs + offset + 4);
bp->ethtool_stats[i] += ((u64)val) << 32;
*(++p) += val;
}
}
}
static struct net_device_stats *gem_get_stats(struct macb *bp)
{
struct gem_stats *hwstat = &bp->hw_stats.gem;
struct net_device_stats *nstat = &bp->stats;
gem_update_stats(bp);
nstat->rx_errors = (hwstat->rx_frame_check_sequence_errors +
hwstat->rx_alignment_errors +
hwstat->rx_resource_errors +
hwstat->rx_overruns +
hwstat->rx_oversize_frames +
hwstat->rx_jabbers +
hwstat->rx_undersized_frames +
hwstat->rx_length_field_frame_errors);
nstat->tx_errors = (hwstat->tx_late_collisions +
hwstat->tx_excessive_collisions +
hwstat->tx_underrun +
hwstat->tx_carrier_sense_errors);
nstat->multicast = hwstat->rx_multicast_frames;
nstat->collisions = (hwstat->tx_single_collision_frames +
hwstat->tx_multiple_collision_frames +
hwstat->tx_excessive_collisions);
nstat->rx_length_errors = (hwstat->rx_oversize_frames +
hwstat->rx_jabbers +
hwstat->rx_undersized_frames +
hwstat->rx_length_field_frame_errors);
nstat->rx_over_errors = hwstat->rx_resource_errors;
nstat->rx_crc_errors = hwstat->rx_frame_check_sequence_errors;
nstat->rx_frame_errors = hwstat->rx_alignment_errors;
nstat->rx_fifo_errors = hwstat->rx_overruns;
nstat->tx_aborted_errors = hwstat->tx_excessive_collisions;
nstat->tx_carrier_errors = hwstat->tx_carrier_sense_errors;
nstat->tx_fifo_errors = hwstat->tx_underrun;
return nstat;
}
static void gem_get_ethtool_stats(struct net_device *dev,
struct ethtool_stats *stats, u64 *data)
{
struct macb *bp;
bp = netdev_priv(dev);
gem_update_stats(bp);
memcpy(data, &bp->ethtool_stats, sizeof(u64) * GEM_STATS_LEN);
}
static int gem_get_sset_count(struct net_device *dev, int sset)
{
switch (sset) {
case ETH_SS_STATS:
return GEM_STATS_LEN;
default:
return -EOPNOTSUPP;
}
}
static void gem_get_ethtool_strings(struct net_device *dev, u32 sset, u8 *p)
{
int i;
switch (sset) {
case ETH_SS_STATS:
for (i = 0; i < GEM_STATS_LEN; i++, p += ETH_GSTRING_LEN)
memcpy(p, gem_statistics[i].stat_string,
ETH_GSTRING_LEN);
break;
}
}
static struct net_device_stats *macb_get_stats(struct net_device *dev)
{
struct macb *bp = netdev_priv(dev);
struct net_device_stats *nstat = &bp->stats;
struct macb_stats *hwstat = &bp->hw_stats.macb;
if (macb_is_gem(bp))
return gem_get_stats(bp);
macb_update_stats(bp);
nstat->rx_errors = (hwstat->rx_fcs_errors +
hwstat->rx_align_errors +
hwstat->rx_resource_errors +
hwstat->rx_overruns +
hwstat->rx_oversize_pkts +
hwstat->rx_jabbers +
hwstat->rx_undersize_pkts +
hwstat->rx_length_mismatch);
nstat->tx_errors = (hwstat->tx_late_cols +
hwstat->tx_excessive_cols +
hwstat->tx_underruns +
hwstat->tx_carrier_errors +
hwstat->sqe_test_errors);
nstat->collisions = (hwstat->tx_single_cols +
hwstat->tx_multiple_cols +
hwstat->tx_excessive_cols);
nstat->rx_length_errors = (hwstat->rx_oversize_pkts +
hwstat->rx_jabbers +
hwstat->rx_undersize_pkts +
hwstat->rx_length_mismatch);
nstat->rx_over_errors = hwstat->rx_resource_errors +
hwstat->rx_overruns;
nstat->rx_crc_errors = hwstat->rx_fcs_errors;
nstat->rx_frame_errors = hwstat->rx_align_errors;
nstat->rx_fifo_errors = hwstat->rx_overruns;
nstat->tx_aborted_errors = hwstat->tx_excessive_cols;
nstat->tx_carrier_errors = hwstat->tx_carrier_errors;
nstat->tx_fifo_errors = hwstat->tx_underruns;
return nstat;
}
static int macb_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct macb *bp = netdev_priv(dev);
struct phy_device *phydev = bp->phy_dev;
if (!phydev)
return -ENODEV;
return phy_ethtool_gset(phydev, cmd);
}
static int macb_set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct macb *bp = netdev_priv(dev);
struct phy_device *phydev = bp->phy_dev;
if (!phydev)
return -ENODEV;
return phy_ethtool_sset(phydev, cmd);
}
static int macb_get_regs_len(struct net_device *netdev)
{
return MACB_GREGS_NBR * sizeof(u32);
}
static void macb_get_regs(struct net_device *dev, struct ethtool_regs *regs,
void *p)
{
struct macb *bp = netdev_priv(dev);
unsigned int tail, head;
u32 *regs_buff = p;
regs->version = (macb_readl(bp, MID) & ((1 << MACB_REV_SIZE) - 1))
| MACB_GREGS_VERSION;
tail = macb_tx_ring_wrap(bp->queues[0].tx_tail);
head = macb_tx_ring_wrap(bp->queues[0].tx_head);
regs_buff[0] = macb_readl(bp, NCR);
regs_buff[1] = macb_or_gem_readl(bp, NCFGR);
regs_buff[2] = macb_readl(bp, NSR);
regs_buff[3] = macb_readl(bp, TSR);
regs_buff[4] = macb_readl(bp, RBQP);
regs_buff[5] = macb_readl(bp, TBQP);
regs_buff[6] = macb_readl(bp, RSR);
regs_buff[7] = macb_readl(bp, IMR);
regs_buff[8] = tail;
regs_buff[9] = head;
regs_buff[10] = macb_tx_dma(&bp->queues[0], tail);
regs_buff[11] = macb_tx_dma(&bp->queues[0], head);
regs_buff[12] = macb_or_gem_readl(bp, USRIO);
if (macb_is_gem(bp)) {
regs_buff[13] = gem_readl(bp, DMACFG);
}
}
static int macb_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
struct macb *bp = netdev_priv(dev);
struct phy_device *phydev = bp->phy_dev;
if (!netif_running(dev))
return -EINVAL;
if (!phydev)
return -ENODEV;
return phy_mii_ioctl(phydev, rq, cmd);
}
static int macb_set_features(struct net_device *netdev,
netdev_features_t features)
{
struct macb *bp = netdev_priv(netdev);
netdev_features_t changed = features ^ netdev->features;
if ((changed & NETIF_F_HW_CSUM) && macb_is_gem(bp)) {
u32 dmacfg;
dmacfg = gem_readl(bp, DMACFG);
if (features & NETIF_F_HW_CSUM)
dmacfg |= GEM_BIT(TXCOEN);
else
dmacfg &= ~GEM_BIT(TXCOEN);
gem_writel(bp, DMACFG, dmacfg);
}
if ((changed & NETIF_F_RXCSUM) && macb_is_gem(bp)) {
u32 netcfg;
netcfg = gem_readl(bp, NCFGR);
if (features & NETIF_F_RXCSUM &&
!(netdev->flags & IFF_PROMISC))
netcfg |= GEM_BIT(RXCOEN);
else
netcfg &= ~GEM_BIT(RXCOEN);
gem_writel(bp, NCFGR, netcfg);
}
return 0;
}
static void macb_configure_caps(struct macb *bp, const struct macb_config *dt_conf)
{
u32 dcfg;
if (dt_conf)
bp->caps = dt_conf->caps;
if (macb_is_gem_hw(bp->regs)) {
bp->caps |= MACB_CAPS_MACB_IS_GEM;
dcfg = gem_readl(bp, DCFG1);
if (GEM_BFEXT(IRQCOR, dcfg) == 0)
bp->caps |= MACB_CAPS_ISR_CLEAR_ON_WRITE;
dcfg = gem_readl(bp, DCFG2);
if ((dcfg & (GEM_BIT(RX_PKT_BUFF) | GEM_BIT(TX_PKT_BUFF))) == 0)
bp->caps |= MACB_CAPS_FIFO_MODE;
}
netdev_dbg(bp->dev, "Cadence caps 0x%08x\n", bp->caps);
}
static void macb_probe_queues(void __iomem *mem,
unsigned int *queue_mask,
unsigned int *num_queues)
{
unsigned int hw_q;
*queue_mask = 0x1;
*num_queues = 1;
if (!macb_is_gem_hw(mem))
return;
*queue_mask = readl_relaxed(mem + GEM_DCFG6) & 0xff;
*queue_mask |= 0x1;
for (hw_q = 1; hw_q < MACB_MAX_QUEUES; ++hw_q)
if (*queue_mask & (1 << hw_q))
(*num_queues)++;
}
static int macb_clk_init(struct platform_device *pdev, struct clk **pclk,
struct clk **hclk, struct clk **tx_clk)
{
int err;
*pclk = devm_clk_get(&pdev->dev, "pclk");
if (IS_ERR(*pclk)) {
err = PTR_ERR(*pclk);
dev_err(&pdev->dev, "failed to get macb_clk (%u)\n", err);
return err;
}
*hclk = devm_clk_get(&pdev->dev, "hclk");
if (IS_ERR(*hclk)) {
err = PTR_ERR(*hclk);
dev_err(&pdev->dev, "failed to get hclk (%u)\n", err);
return err;
}
*tx_clk = devm_clk_get(&pdev->dev, "tx_clk");
if (IS_ERR(*tx_clk))
*tx_clk = NULL;
err = clk_prepare_enable(*pclk);
if (err) {
dev_err(&pdev->dev, "failed to enable pclk (%u)\n", err);
return err;
}
err = clk_prepare_enable(*hclk);
if (err) {
dev_err(&pdev->dev, "failed to enable hclk (%u)\n", err);
goto err_disable_pclk;
}
err = clk_prepare_enable(*tx_clk);
if (err) {
dev_err(&pdev->dev, "failed to enable tx_clk (%u)\n", err);
goto err_disable_hclk;
}
return 0;
err_disable_hclk:
clk_disable_unprepare(*hclk);
err_disable_pclk:
clk_disable_unprepare(*pclk);
return err;
}
static int macb_init(struct platform_device *pdev)
{
struct net_device *dev = platform_get_drvdata(pdev);
unsigned int hw_q, q;
struct macb *bp = netdev_priv(dev);
struct macb_queue *queue;
int err;
u32 val;
for (hw_q = 0, q = 0; hw_q < MACB_MAX_QUEUES; ++hw_q) {
if (!(bp->queue_mask & (1 << hw_q)))
continue;
queue = &bp->queues[q];
queue->bp = bp;
if (hw_q) {
queue->ISR = GEM_ISR(hw_q - 1);
queue->IER = GEM_IER(hw_q - 1);
queue->IDR = GEM_IDR(hw_q - 1);
queue->IMR = GEM_IMR(hw_q - 1);
queue->TBQP = GEM_TBQP(hw_q - 1);
} else {
queue->ISR = MACB_ISR;
queue->IER = MACB_IER;
queue->IDR = MACB_IDR;
queue->IMR = MACB_IMR;
queue->TBQP = MACB_TBQP;
}
queue->irq = platform_get_irq(pdev, q);
err = devm_request_irq(&pdev->dev, queue->irq, macb_interrupt,
IRQF_SHARED, dev->name, queue);
if (err) {
dev_err(&pdev->dev,
"Unable to request IRQ %d (error %d)\n",
queue->irq, err);
return err;
}
INIT_WORK(&queue->tx_error_task, macb_tx_error_task);
q++;
}
dev->netdev_ops = &macb_netdev_ops;
netif_napi_add(dev, &bp->napi, macb_poll, 64);
if (macb_is_gem(bp)) {
bp->max_tx_length = GEM_MAX_TX_LEN;
bp->macbgem_ops.mog_alloc_rx_buffers = gem_alloc_rx_buffers;
bp->macbgem_ops.mog_free_rx_buffers = gem_free_rx_buffers;
bp->macbgem_ops.mog_init_rings = gem_init_rings;
bp->macbgem_ops.mog_rx = gem_rx;
dev->ethtool_ops = &gem_ethtool_ops;
} else {
bp->max_tx_length = MACB_MAX_TX_LEN;
bp->macbgem_ops.mog_alloc_rx_buffers = macb_alloc_rx_buffers;
bp->macbgem_ops.mog_free_rx_buffers = macb_free_rx_buffers;
bp->macbgem_ops.mog_init_rings = macb_init_rings;
bp->macbgem_ops.mog_rx = macb_rx;
dev->ethtool_ops = &macb_ethtool_ops;
}
dev->hw_features = NETIF_F_SG;
if (macb_is_gem(bp) && !(bp->caps & MACB_CAPS_FIFO_MODE))
dev->hw_features |= NETIF_F_HW_CSUM | NETIF_F_RXCSUM;
if (bp->caps & MACB_CAPS_SG_DISABLED)
dev->hw_features &= ~NETIF_F_SG;
dev->features = dev->hw_features;
val = 0;
if (bp->phy_interface == PHY_INTERFACE_MODE_RGMII)
val = GEM_BIT(RGMII);
else if (bp->phy_interface == PHY_INTERFACE_MODE_RMII &&
(bp->caps & MACB_CAPS_USRIO_DEFAULT_IS_MII))
val = MACB_BIT(RMII);
else if (!(bp->caps & MACB_CAPS_USRIO_DEFAULT_IS_MII))
val = MACB_BIT(MII);
if (bp->caps & MACB_CAPS_USRIO_HAS_CLKEN)
val |= MACB_BIT(CLKEN);
macb_or_gem_writel(bp, USRIO, val);
val = macb_mdc_clk_div(bp);
val |= macb_dbw(bp);
macb_writel(bp, NCFGR, val);
return 0;
}
static int at91ether_start(struct net_device *dev)
{
struct macb *lp = netdev_priv(dev);
dma_addr_t addr;
u32 ctl;
int i;
lp->rx_ring = dma_alloc_coherent(&lp->pdev->dev,
(AT91ETHER_MAX_RX_DESCR *
sizeof(struct macb_dma_desc)),
&lp->rx_ring_dma, GFP_KERNEL);
if (!lp->rx_ring)
return -ENOMEM;
lp->rx_buffers = dma_alloc_coherent(&lp->pdev->dev,
AT91ETHER_MAX_RX_DESCR *
AT91ETHER_MAX_RBUFF_SZ,
&lp->rx_buffers_dma, GFP_KERNEL);
if (!lp->rx_buffers) {
dma_free_coherent(&lp->pdev->dev,
AT91ETHER_MAX_RX_DESCR *
sizeof(struct macb_dma_desc),
lp->rx_ring, lp->rx_ring_dma);
lp->rx_ring = NULL;
return -ENOMEM;
}
addr = lp->rx_buffers_dma;
for (i = 0; i < AT91ETHER_MAX_RX_DESCR; i++) {
lp->rx_ring[i].addr = addr;
lp->rx_ring[i].ctrl = 0;
addr += AT91ETHER_MAX_RBUFF_SZ;
}
lp->rx_ring[AT91ETHER_MAX_RX_DESCR - 1].addr |= MACB_BIT(RX_WRAP);
lp->rx_tail = 0;
macb_writel(lp, RBQP, lp->rx_ring_dma);
ctl = macb_readl(lp, NCR);
macb_writel(lp, NCR, ctl | MACB_BIT(RE) | MACB_BIT(TE));
return 0;
}
static int at91ether_open(struct net_device *dev)
{
struct macb *lp = netdev_priv(dev);
u32 ctl;
int ret;
ctl = macb_readl(lp, NCR);
macb_writel(lp, NCR, ctl | MACB_BIT(CLRSTAT));
macb_set_hwaddr(lp);
ret = at91ether_start(dev);
if (ret)
return ret;
macb_writel(lp, IER, MACB_BIT(RCOMP) |
MACB_BIT(RXUBR) |
MACB_BIT(ISR_TUND) |
MACB_BIT(ISR_RLE) |
MACB_BIT(TCOMP) |
MACB_BIT(ISR_ROVR) |
MACB_BIT(HRESP));
phy_start(lp->phy_dev);
netif_start_queue(dev);
return 0;
}
static int at91ether_close(struct net_device *dev)
{
struct macb *lp = netdev_priv(dev);
u32 ctl;
ctl = macb_readl(lp, NCR);
macb_writel(lp, NCR, ctl & ~(MACB_BIT(TE) | MACB_BIT(RE)));
macb_writel(lp, IDR, MACB_BIT(RCOMP) |
MACB_BIT(RXUBR) |
MACB_BIT(ISR_TUND) |
MACB_BIT(ISR_RLE) |
MACB_BIT(TCOMP) |
MACB_BIT(ISR_ROVR) |
MACB_BIT(HRESP));
netif_stop_queue(dev);
dma_free_coherent(&lp->pdev->dev,
AT91ETHER_MAX_RX_DESCR *
sizeof(struct macb_dma_desc),
lp->rx_ring, lp->rx_ring_dma);
lp->rx_ring = NULL;
dma_free_coherent(&lp->pdev->dev,
AT91ETHER_MAX_RX_DESCR * AT91ETHER_MAX_RBUFF_SZ,
lp->rx_buffers, lp->rx_buffers_dma);
lp->rx_buffers = NULL;
return 0;
}
static int at91ether_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct macb *lp = netdev_priv(dev);
if (macb_readl(lp, TSR) & MACB_BIT(RM9200_BNQ)) {
netif_stop_queue(dev);
lp->skb = skb;
lp->skb_length = skb->len;
lp->skb_physaddr = dma_map_single(NULL, skb->data, skb->len,
DMA_TO_DEVICE);
macb_writel(lp, TAR, lp->skb_physaddr);
macb_writel(lp, TCR, skb->len);
} else {
netdev_err(dev, "%s called, but device is busy!\n", __func__);
return NETDEV_TX_BUSY;
}
return NETDEV_TX_OK;
}
static void at91ether_rx(struct net_device *dev)
{
struct macb *lp = netdev_priv(dev);
unsigned char *p_recv;
struct sk_buff *skb;
unsigned int pktlen;
while (lp->rx_ring[lp->rx_tail].addr & MACB_BIT(RX_USED)) {
p_recv = lp->rx_buffers + lp->rx_tail * AT91ETHER_MAX_RBUFF_SZ;
pktlen = MACB_BF(RX_FRMLEN, lp->rx_ring[lp->rx_tail].ctrl);
skb = netdev_alloc_skb(dev, pktlen + 2);
if (skb) {
skb_reserve(skb, 2);
memcpy(skb_put(skb, pktlen), p_recv, pktlen);
skb->protocol = eth_type_trans(skb, dev);
lp->stats.rx_packets++;
lp->stats.rx_bytes += pktlen;
netif_rx(skb);
} else {
lp->stats.rx_dropped++;
}
if (lp->rx_ring[lp->rx_tail].ctrl & MACB_BIT(RX_MHASH_MATCH))
lp->stats.multicast++;
lp->rx_ring[lp->rx_tail].addr &= ~MACB_BIT(RX_USED);
if (lp->rx_tail == AT91ETHER_MAX_RX_DESCR - 1)
lp->rx_tail = 0;
else
lp->rx_tail++;
}
}
static irqreturn_t at91ether_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct macb *lp = netdev_priv(dev);
u32 intstatus, ctl;
intstatus = macb_readl(lp, ISR);
if (intstatus & MACB_BIT(RCOMP))
at91ether_rx(dev);
if (intstatus & MACB_BIT(TCOMP)) {
if (intstatus & (MACB_BIT(ISR_TUND) | MACB_BIT(ISR_RLE)))
lp->stats.tx_errors++;
if (lp->skb) {
dev_kfree_skb_irq(lp->skb);
lp->skb = NULL;
dma_unmap_single(NULL, lp->skb_physaddr,
lp->skb_length, DMA_TO_DEVICE);
lp->stats.tx_packets++;
lp->stats.tx_bytes += lp->skb_length;
}
netif_wake_queue(dev);
}
if (intstatus & MACB_BIT(RXUBR)) {
ctl = macb_readl(lp, NCR);
macb_writel(lp, NCR, ctl & ~MACB_BIT(RE));
macb_writel(lp, NCR, ctl | MACB_BIT(RE));
}
if (intstatus & MACB_BIT(ISR_ROVR))
netdev_err(dev, "ROVR error\n");
return IRQ_HANDLED;
}
static void at91ether_poll_controller(struct net_device *dev)
{
unsigned long flags;
local_irq_save(flags);
at91ether_interrupt(dev->irq, dev);
local_irq_restore(flags);
}
static int at91ether_clk_init(struct platform_device *pdev, struct clk **pclk,
struct clk **hclk, struct clk **tx_clk)
{
int err;
*hclk = NULL;
*tx_clk = NULL;
*pclk = devm_clk_get(&pdev->dev, "ether_clk");
if (IS_ERR(*pclk))
return PTR_ERR(*pclk);
err = clk_prepare_enable(*pclk);
if (err) {
dev_err(&pdev->dev, "failed to enable pclk (%u)\n", err);
return err;
}
return 0;
}
static int at91ether_init(struct platform_device *pdev)
{
struct net_device *dev = platform_get_drvdata(pdev);
struct macb *bp = netdev_priv(dev);
int err;
u32 reg;
dev->netdev_ops = &at91ether_netdev_ops;
dev->ethtool_ops = &macb_ethtool_ops;
err = devm_request_irq(&pdev->dev, dev->irq, at91ether_interrupt,
0, dev->name, dev);
if (err)
return err;
macb_writel(bp, NCR, 0);
reg = MACB_BF(CLK, MACB_CLK_DIV32) | MACB_BIT(BIG);
if (bp->phy_interface == PHY_INTERFACE_MODE_RMII)
reg |= MACB_BIT(RM9200_RMII);
macb_writel(bp, NCFGR, reg);
return 0;
}
static int macb_probe(struct platform_device *pdev)
{
int (*clk_init)(struct platform_device *, struct clk **,
struct clk **, struct clk **)
= macb_clk_init;
int (*init)(struct platform_device *) = macb_init;
struct device_node *np = pdev->dev.of_node;
const struct macb_config *macb_config = NULL;
struct clk *pclk, *hclk, *tx_clk;
unsigned int queue_mask, num_queues;
struct macb_platform_data *pdata;
struct phy_device *phydev;
struct net_device *dev;
struct resource *regs;
void __iomem *mem;
const char *mac;
struct macb *bp;
int err;
if (np) {
const struct of_device_id *match;
match = of_match_node(macb_dt_ids, np);
if (match && match->data) {
macb_config = match->data;
clk_init = macb_config->clk_init;
init = macb_config->init;
}
}
err = clk_init(pdev, &pclk, &hclk, &tx_clk);
if (err)
return err;
regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mem = devm_ioremap_resource(&pdev->dev, regs);
if (IS_ERR(mem)) {
err = PTR_ERR(mem);
goto err_disable_clocks;
}
macb_probe_queues(mem, &queue_mask, &num_queues);
dev = alloc_etherdev_mq(sizeof(*bp), num_queues);
if (!dev) {
err = -ENOMEM;
goto err_disable_clocks;
}
dev->base_addr = regs->start;
SET_NETDEV_DEV(dev, &pdev->dev);
bp = netdev_priv(dev);
bp->pdev = pdev;
bp->dev = dev;
bp->regs = mem;
bp->num_queues = num_queues;
bp->queue_mask = queue_mask;
if (macb_config)
bp->dma_burst_length = macb_config->dma_burst_length;
bp->pclk = pclk;
bp->hclk = hclk;
bp->tx_clk = tx_clk;
spin_lock_init(&bp->lock);
macb_configure_caps(bp, macb_config);
platform_set_drvdata(pdev, dev);
dev->irq = platform_get_irq(pdev, 0);
if (dev->irq < 0) {
err = dev->irq;
goto err_disable_clocks;
}
mac = of_get_mac_address(np);
if (mac)
memcpy(bp->dev->dev_addr, mac, ETH_ALEN);
else
macb_get_hwaddr(bp);
err = of_get_phy_mode(np);
if (err < 0) {
pdata = dev_get_platdata(&pdev->dev);
if (pdata && pdata->is_rmii)
bp->phy_interface = PHY_INTERFACE_MODE_RMII;
else
bp->phy_interface = PHY_INTERFACE_MODE_MII;
} else {
bp->phy_interface = err;
}
err = init(pdev);
if (err)
goto err_out_free_netdev;
err = register_netdev(dev);
if (err) {
dev_err(&pdev->dev, "Cannot register net device, aborting.\n");
goto err_out_unregister_netdev;
}
err = macb_mii_init(bp);
if (err)
goto err_out_unregister_netdev;
netif_carrier_off(dev);
netdev_info(dev, "Cadence %s rev 0x%08x at 0x%08lx irq %d (%pM)\n",
macb_is_gem(bp) ? "GEM" : "MACB", macb_readl(bp, MID),
dev->base_addr, dev->irq, dev->dev_addr);
phydev = bp->phy_dev;
netdev_info(dev, "attached PHY driver [%s] (mii_bus:phy_addr=%s, irq=%d)\n",
phydev->drv->name, dev_name(&phydev->dev), phydev->irq);
return 0;
err_out_unregister_netdev:
unregister_netdev(dev);
err_out_free_netdev:
free_netdev(dev);
err_disable_clocks:
clk_disable_unprepare(tx_clk);
clk_disable_unprepare(hclk);
clk_disable_unprepare(pclk);
return err;
}
static int macb_remove(struct platform_device *pdev)
{
struct net_device *dev;
struct macb *bp;
dev = platform_get_drvdata(pdev);
if (dev) {
bp = netdev_priv(dev);
if (bp->phy_dev)
phy_disconnect(bp->phy_dev);
mdiobus_unregister(bp->mii_bus);
kfree(bp->mii_bus->irq);
mdiobus_free(bp->mii_bus);
unregister_netdev(dev);
clk_disable_unprepare(bp->tx_clk);
clk_disable_unprepare(bp->hclk);
clk_disable_unprepare(bp->pclk);
free_netdev(dev);
}
return 0;
}
static int __maybe_unused macb_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct net_device *netdev = platform_get_drvdata(pdev);
struct macb *bp = netdev_priv(netdev);
netif_carrier_off(netdev);
netif_device_detach(netdev);
clk_disable_unprepare(bp->tx_clk);
clk_disable_unprepare(bp->hclk);
clk_disable_unprepare(bp->pclk);
return 0;
}
static int __maybe_unused macb_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct net_device *netdev = platform_get_drvdata(pdev);
struct macb *bp = netdev_priv(netdev);
clk_prepare_enable(bp->pclk);
clk_prepare_enable(bp->hclk);
clk_prepare_enable(bp->tx_clk);
netif_device_attach(netdev);
return 0;
}
