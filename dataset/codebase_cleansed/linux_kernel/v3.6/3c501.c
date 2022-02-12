struct net_device * __init el1_probe(int unit)
{
struct net_device *dev = alloc_etherdev(sizeof(struct net_local));
static const unsigned ports[] = { 0x280, 0x300, 0};
const unsigned *port;
int err = 0;
if (!dev)
return ERR_PTR(-ENOMEM);
if (unit >= 0) {
sprintf(dev->name, "eth%d", unit);
netdev_boot_setup_check(dev);
io = dev->base_addr;
irq = dev->irq;
mem_start = dev->mem_start & 7;
}
if (io > 0x1ff) {
err = el1_probe1(dev, io);
} else if (io != 0) {
err = -ENXIO;
} else {
for (port = ports; *port && el1_probe1(dev, *port); port++)
;
if (!*port)
err = -ENODEV;
}
if (err)
goto out;
err = register_netdev(dev);
if (err)
goto out1;
return dev;
out1:
release_region(dev->base_addr, EL1_IO_EXTENT);
out:
free_netdev(dev);
return ERR_PTR(err);
}
static int __init el1_probe1(struct net_device *dev, int ioaddr)
{
struct net_local *lp;
const char *mname;
unsigned char station_addr[6];
int autoirq = 0;
int i;
if (!request_region(ioaddr, EL1_IO_EXTENT, DRV_NAME))
return -ENODEV;
for (i = 0; i < 6; i++) {
outw(i, ioaddr + EL1_DATAPTR);
station_addr[i] = inb(ioaddr + EL1_SAPROM);
}
if (station_addr[0] == 0x02 && station_addr[1] == 0x60 &&
station_addr[2] == 0x8c)
mname = "3c501";
else if (station_addr[0] == 0x00 && station_addr[1] == 0x80 &&
station_addr[2] == 0xC8)
mname = "NP943";
else {
release_region(ioaddr, EL1_IO_EXTENT);
return -ENODEV;
}
dev->irq = irq;
if (dev->irq < 2) {
unsigned long irq_mask;
irq_mask = probe_irq_on();
inb(RX_STATUS);
inb(TX_STATUS);
outb(AX_LOOP + 1, AX_CMD);
outb(0x00, AX_CMD);
mdelay(20);
autoirq = probe_irq_off(irq_mask);
if (autoirq == 0) {
pr_warning("%s probe at %#x failed to detect IRQ line.\n",
mname, ioaddr);
release_region(ioaddr, EL1_IO_EXTENT);
return -EAGAIN;
}
}
outb(AX_RESET+AX_LOOP, AX_CMD);
dev->base_addr = ioaddr;
memcpy(dev->dev_addr, station_addr, ETH_ALEN);
if (mem_start & 0xf)
el_debug = mem_start & 0x7;
if (autoirq)
dev->irq = autoirq;
pr_info("%s: %s EtherLink at %#lx, using %sIRQ %d.\n",
dev->name, mname, dev->base_addr,
autoirq ? "auto":"assigned ", dev->irq);
#ifdef CONFIG_IP_MULTICAST
pr_warning("WARNING: Use of the 3c501 in a multicast kernel is NOT recommended.\n");
#endif
if (el_debug)
pr_debug("%s", version);
lp = netdev_priv(dev);
memset(lp, 0, sizeof(struct net_local));
spin_lock_init(&lp->lock);
dev->netdev_ops = &el_netdev_ops;
dev->watchdog_timeo = HZ;
dev->ethtool_ops = &netdev_ethtool_ops;
return 0;
}
static int el_open(struct net_device *dev)
{
int retval;
int ioaddr = dev->base_addr;
struct net_local *lp = netdev_priv(dev);
unsigned long flags;
if (el_debug > 2)
pr_debug("%s: Doing el_open()...\n", dev->name);
retval = request_irq(dev->irq, el_interrupt, 0, dev->name, dev);
if (retval)
return retval;
spin_lock_irqsave(&lp->lock, flags);
el_reset(dev);
spin_unlock_irqrestore(&lp->lock, flags);
lp->txing = 0;
outb(AX_RX, AX_CMD);
netif_start_queue(dev);
return 0;
}
static void el_timeout(struct net_device *dev)
{
struct net_local *lp = netdev_priv(dev);
int ioaddr = dev->base_addr;
if (el_debug)
pr_debug("%s: transmit timed out, txsr %#2x axsr=%02x rxsr=%02x.\n",
dev->name, inb(TX_STATUS),
inb(AX_STATUS), inb(RX_STATUS));
dev->stats.tx_errors++;
outb(TX_NORM, TX_CMD);
outb(RX_NORM, RX_CMD);
outb(AX_OFF, AX_CMD);
outb(AX_RX, AX_CMD);
lp->txing = 0;
netif_wake_queue(dev);
}
static netdev_tx_t el_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct net_local *lp = netdev_priv(dev);
int ioaddr = dev->base_addr;
unsigned long flags;
spin_lock_irqsave(&lp->lock, flags);
netif_stop_queue(dev);
do {
int len = skb->len;
int pad = 0;
int gp_start;
unsigned char *buf = skb->data;
if (len < ETH_ZLEN)
pad = ETH_ZLEN - len;
gp_start = 0x800 - (len + pad);
lp->tx_pkt_start = gp_start;
lp->collisions = 0;
dev->stats.tx_bytes += skb->len;
outb_p(AX_SYS, AX_CMD);
inb_p(RX_STATUS);
inb_p(TX_STATUS);
lp->loading = 1;
lp->txing = 1;
spin_unlock_irqrestore(&lp->lock, flags);
outw(0x00, RX_BUF_CLR);
outw(gp_start, GP_LOW);
outsb(DATAPORT, buf, len);
if (pad) {
while (pad--)
outb(0, DATAPORT);
}
outw(gp_start, GP_LOW);
if (lp->loading != 2) {
outb(AX_XMIT, AX_CMD);
lp->loading = 0;
if (el_debug > 2)
pr_debug(" queued xmit.\n");
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
if (el_debug > 2)
pr_debug("%s: burped during tx load.\n", dev->name);
spin_lock_irqsave(&lp->lock, flags);
} while (1);
}
static irqreturn_t el_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct net_local *lp;
int ioaddr;
int axsr;
ioaddr = dev->base_addr;
lp = netdev_priv(dev);
spin_lock(&lp->lock);
axsr = inb(AX_STATUS);
if (el_debug > 3)
pr_debug("%s: el_interrupt() aux=%#02x\n", dev->name, axsr);
if (lp->loading == 1 && !lp->txing)
pr_warning("%s: Inconsistent state loading while not in tx\n",
dev->name);
if (lp->txing) {
int txsr = inb(TX_STATUS);
if (lp->loading == 1) {
if (el_debug > 2)
pr_debug("%s: Interrupt while loading [txsr=%02x gp=%04x rp=%04x]\n",
dev->name, txsr, inw(GP_LOW), inw(RX_LOW));
lp->loading = 2;
spin_unlock(&lp->lock);
goto out;
}
if (el_debug > 6)
pr_debug("%s: txsr=%02x gp=%04x rp=%04x\n", dev->name,
txsr, inw(GP_LOW), inw(RX_LOW));
if ((axsr & 0x80) && (txsr & TX_READY) == 0) {
if (el_debug > 1)
pr_debug("%s: Unusual interrupt during Tx, txsr=%02x axsr=%02x gp=%03x rp=%03x.\n",
dev->name, txsr, axsr,
inw(ioaddr + EL1_DATAPTR),
inw(ioaddr + EL1_RXPTR));
lp->txing = 0;
netif_wake_queue(dev);
} else if (txsr & TX_16COLLISIONS) {
if (el_debug)
pr_debug("%s: Transmit failed 16 times, Ethernet jammed?\n", dev->name);
outb(AX_SYS, AX_CMD);
lp->txing = 0;
dev->stats.tx_aborted_errors++;
netif_wake_queue(dev);
} else if (txsr & TX_COLLISION) {
if (el_debug > 6)
pr_debug("%s: retransmitting after a collision.\n", dev->name);
outb(AX_SYS, AX_CMD);
outw(lp->tx_pkt_start, GP_LOW);
outb(AX_XMIT, AX_CMD);
dev->stats.collisions++;
spin_unlock(&lp->lock);
goto out;
} else {
dev->stats.tx_packets++;
if (el_debug > 6)
pr_debug("%s: Tx succeeded %s\n", dev->name,
(txsr & TX_RDY) ? "." : "but tx is busy!");
lp->txing = 0;
netif_wake_queue(dev);
}
} else {
int rxsr = inb(RX_STATUS);
if (el_debug > 5)
pr_debug("%s: rxsr=%02x txsr=%02x rp=%04x\n",
dev->name, rxsr, inb(TX_STATUS), inw(RX_LOW));
if (rxsr & RX_MISSED)
dev->stats.rx_missed_errors++;
else if (rxsr & RX_RUNT) {
dev->stats.rx_length_errors++;
if (el_debug > 5)
pr_debug("%s: runt.\n", dev->name);
} else if (rxsr & RX_GOOD) {
el_receive(dev);
} else {
if (el_debug > 2)
pr_debug("%s: No packet seen, rxsr=%02x **resetting 3c501***\n",
dev->name, rxsr);
el_reset(dev);
}
}
outb(AX_RX, AX_CMD);
outw(0x00, RX_BUF_CLR);
inb(RX_STATUS);
inb(TX_STATUS);
spin_unlock(&lp->lock);
out:
return IRQ_HANDLED;
}
static void el_receive(struct net_device *dev)
{
int ioaddr = dev->base_addr;
int pkt_len;
struct sk_buff *skb;
pkt_len = inw(RX_LOW);
if (el_debug > 4)
pr_debug(" el_receive %d.\n", pkt_len);
if (pkt_len < 60 || pkt_len > 1536) {
if (el_debug)
pr_debug("%s: bogus packet, length=%d\n",
dev->name, pkt_len);
dev->stats.rx_over_errors++;
return;
}
outb(AX_SYS, AX_CMD);
skb = netdev_alloc_skb(dev, pkt_len + 2);
outw(0x00, GP_LOW);
if (skb == NULL) {
pr_info("%s: Memory squeeze, dropping packet.\n", dev->name);
dev->stats.rx_dropped++;
return;
} else {
skb_reserve(skb, 2);
insb(DATAPORT, skb_put(skb, pkt_len), pkt_len);
skb->protocol = eth_type_trans(skb, dev);
netif_rx(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += pkt_len;
}
}
static void el_reset(struct net_device *dev)
{
struct net_local *lp = netdev_priv(dev);
int ioaddr = dev->base_addr;
if (el_debug > 2)
pr_info("3c501 reset...\n");
outb(AX_RESET, AX_CMD);
outb(AX_LOOP, AX_CMD);
{
int i;
for (i = 0; i < 6; i++)
outb(dev->dev_addr[i], ioaddr + i);
}
outw(0, RX_BUF_CLR);
outb(TX_NORM, TX_CMD);
outb(RX_NORM, RX_CMD);
inb(RX_STATUS);
inb(TX_STATUS);
lp->txing = 0;
}
static int el1_close(struct net_device *dev)
{
int ioaddr = dev->base_addr;
if (el_debug > 2)
pr_info("%s: Shutting down Ethernet card at %#x.\n",
dev->name, ioaddr);
netif_stop_queue(dev);
free_irq(dev->irq, dev);
outb(AX_RESET, AX_CMD);
return 0;
}
static void set_multicast_list(struct net_device *dev)
{
int ioaddr = dev->base_addr;
if (dev->flags & IFF_PROMISC) {
outb(RX_PROM, RX_CMD);
inb(RX_STATUS);
} else if (!netdev_mc_empty(dev) || dev->flags & IFF_ALLMULTI) {
outb(RX_MULT, RX_CMD);
inb(RX_STATUS);
} else {
outb(RX_NORM, RX_CMD);
inb(RX_STATUS);
}
}
static void netdev_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
strcpy(info->driver, DRV_NAME);
strcpy(info->version, DRV_VERSION);
sprintf(info->bus_info, "ISA 0x%lx", dev->base_addr);
}
static u32 netdev_get_msglevel(struct net_device *dev)
{
return debug;
}
static void netdev_set_msglevel(struct net_device *dev, u32 level)
{
debug = level;
}
int __init init_module(void)
{
dev_3c501 = el1_probe(-1);
if (IS_ERR(dev_3c501))
return PTR_ERR(dev_3c501);
return 0;
}
void __exit cleanup_module(void)
{
struct net_device *dev = dev_3c501;
unregister_netdev(dev);
release_region(dev->base_addr, EL1_IO_EXTENT);
free_netdev(dev);
}
