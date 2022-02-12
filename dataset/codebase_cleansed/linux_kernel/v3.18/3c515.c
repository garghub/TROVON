int init_module(void)
{
int found = 0;
if (debug >= 0)
corkscrew_debug = debug;
if (corkscrew_debug)
pr_debug("%s", version);
while (corkscrew_scan(-1))
found++;
return found ? 0 : -ENODEV;
}
struct net_device *tc515_probe(int unit)
{
struct net_device *dev = corkscrew_scan(unit);
static int printed;
if (!dev)
return ERR_PTR(-ENODEV);
if (corkscrew_debug > 0 && !printed) {
printed = 1;
pr_debug("%s", version);
}
return dev;
}
static int check_device(unsigned ioaddr)
{
int timer;
if (!request_region(ioaddr, CORKSCREW_TOTAL_SIZE, "3c515"))
return 0;
if ((inw(ioaddr + 0x2002) & 0x1f0) != (ioaddr & 0x1f0)) {
release_region(ioaddr, CORKSCREW_TOTAL_SIZE);
return 0;
}
outw(EEPROM_Read + 7, ioaddr + Wn0EepromCmd);
for (timer = 4; timer >= 0; timer--) {
udelay(162);
if ((inw(ioaddr + Wn0EepromCmd) & 0x0200) == 0)
break;
}
if (inw(ioaddr + Wn0EepromData) != 0x6d50) {
release_region(ioaddr, CORKSCREW_TOTAL_SIZE);
return 0;
}
return 1;
}
static void cleanup_card(struct net_device *dev)
{
struct corkscrew_private *vp = netdev_priv(dev);
list_del_init(&vp->list);
if (dev->dma)
free_dma(dev->dma);
outw(TotalReset, dev->base_addr + EL3_CMD);
release_region(dev->base_addr, CORKSCREW_TOTAL_SIZE);
if (vp->dev)
pnp_device_detach(to_pnp_dev(vp->dev));
}
static struct net_device *corkscrew_scan(int unit)
{
struct net_device *dev;
static int cards_found = 0;
static int ioaddr;
int err;
#ifdef __ISAPNP__
short i;
static int pnp_cards;
#endif
dev = alloc_etherdev(sizeof(struct corkscrew_private));
if (!dev)
return ERR_PTR(-ENOMEM);
if (unit >= 0) {
sprintf(dev->name, "eth%d", unit);
netdev_boot_setup_check(dev);
}
#ifdef __ISAPNP__
if(nopnp == 1)
goto no_pnp;
for(i=0; corkscrew_isapnp_adapters[i].vendor != 0; i++) {
struct pnp_dev *idev = NULL;
int irq;
while((idev = pnp_find_dev(NULL,
corkscrew_isapnp_adapters[i].vendor,
corkscrew_isapnp_adapters[i].function,
idev))) {
if (pnp_device_attach(idev) < 0)
continue;
if (pnp_activate_dev(idev) < 0) {
pr_warn("pnp activate failed (out of resources?)\n");
pnp_device_detach(idev);
continue;
}
if (!pnp_port_valid(idev, 0) || !pnp_irq_valid(idev, 0)) {
pnp_device_detach(idev);
continue;
}
ioaddr = pnp_port_start(idev, 0);
irq = pnp_irq(idev, 0);
if (!check_device(ioaddr)) {
pnp_device_detach(idev);
continue;
}
if(corkscrew_debug)
pr_debug("ISAPNP reports %s at i/o 0x%x, irq %d\n",
(char*) corkscrew_isapnp_adapters[i].driver_data, ioaddr, irq);
pr_info("3c515 Resource configuration register %#4.4x, DCR %4.4x.\n",
inl(ioaddr + 0x2002), inw(ioaddr + 0x2000));
SET_NETDEV_DEV(dev, &idev->dev);
pnp_cards++;
err = corkscrew_setup(dev, ioaddr, idev, cards_found++);
if (!err)
return dev;
cleanup_card(dev);
}
}
no_pnp:
#endif
for (ioaddr = 0x100; ioaddr < 0x400; ioaddr += 0x20) {
if (!check_device(ioaddr))
continue;
pr_info("3c515 Resource configuration register %#4.4x, DCR %4.4x.\n",
inl(ioaddr + 0x2002), inw(ioaddr + 0x2000));
err = corkscrew_setup(dev, ioaddr, NULL, cards_found++);
if (!err)
return dev;
cleanup_card(dev);
}
free_netdev(dev);
return NULL;
}
static int corkscrew_setup(struct net_device *dev, int ioaddr,
struct pnp_dev *idev, int card_number)
{
struct corkscrew_private *vp = netdev_priv(dev);
unsigned int eeprom[0x40], checksum = 0;
int i;
int irq;
#ifdef __ISAPNP__
if (idev) {
irq = pnp_irq(idev, 0);
vp->dev = &idev->dev;
} else {
irq = inw(ioaddr + 0x2002) & 15;
}
#else
irq = inw(ioaddr + 0x2002) & 15;
#endif
dev->base_addr = ioaddr;
dev->irq = irq;
dev->dma = inw(ioaddr + 0x2000) & 7;
vp->product_name = "3c515";
vp->options = dev->mem_start;
vp->our_dev = dev;
if (!vp->options) {
if (card_number >= MAX_UNITS)
vp->options = -1;
else
vp->options = options[card_number];
}
if (vp->options >= 0) {
vp->media_override = vp->options & 7;
if (vp->media_override == 2)
vp->media_override = 0;
vp->full_duplex = (vp->options & 8) ? 1 : 0;
vp->bus_master = (vp->options & 16) ? 1 : 0;
} else {
vp->media_override = 7;
vp->full_duplex = 0;
vp->bus_master = 0;
}
#ifdef MODULE
list_add(&vp->list, &root_corkscrew_dev);
#endif
pr_info("%s: 3Com %s at %#3x,", dev->name, vp->product_name, ioaddr);
spin_lock_init(&vp->lock);
EL3WINDOW(0);
for (i = 0; i < 0x18; i++) {
__be16 *phys_addr = (__be16 *) dev->dev_addr;
int timer;
outw(EEPROM_Read + i, ioaddr + Wn0EepromCmd);
for (timer = 4; timer >= 0; timer--) {
udelay(162);
if ((inw(ioaddr + Wn0EepromCmd) & 0x0200) == 0)
break;
}
eeprom[i] = inw(ioaddr + Wn0EepromData);
checksum ^= eeprom[i];
if (i < 3)
phys_addr[i] = htons(eeprom[i]);
}
checksum = (checksum ^ (checksum >> 8)) & 0xff;
if (checksum != 0x00)
pr_cont(" ***INVALID CHECKSUM %4.4x*** ", checksum);
pr_cont(" %pM", dev->dev_addr);
if (eeprom[16] == 0x11c7) {
if (request_dma(dev->dma, "3c515")) {
pr_cont(", DMA %d allocation failed", dev->dma);
dev->dma = 0;
} else
pr_cont(", DMA %d", dev->dma);
}
pr_cont(", IRQ %d\n", dev->irq);
if (corkscrew_debug && (dev->irq <= 0 || dev->irq > 15))
pr_warn(" *** Warning: this IRQ is unlikely to work! ***\n");
{
static const char * const ram_split[] = {
"5:3", "3:1", "1:1", "3:5"
};
__u32 config;
EL3WINDOW(3);
vp->available_media = inw(ioaddr + Wn3_Options);
config = inl(ioaddr + Wn3_Config);
if (corkscrew_debug > 1)
pr_info(" Internal config register is %4.4x, transceivers %#x.\n",
config, inw(ioaddr + Wn3_Options));
pr_info(" %dK %s-wide RAM %s Rx:Tx split, %s%s interface.\n",
8 << config & Ram_size,
config & Ram_width ? "word" : "byte",
ram_split[(config & Ram_split) >> Ram_split_shift],
config & Autoselect ? "autoselect/" : "",
media_tbl[(config & Xcvr) >> Xcvr_shift].name);
vp->default_media = (config & Xcvr) >> Xcvr_shift;
vp->autoselect = config & Autoselect ? 1 : 0;
dev->if_port = vp->default_media;
}
if (vp->media_override != 7) {
pr_info(" Media override to transceiver type %d (%s).\n",
vp->media_override,
media_tbl[vp->media_override].name);
dev->if_port = vp->media_override;
}
vp->capabilities = eeprom[16];
vp->full_bus_master_tx = (vp->capabilities & 0x20) ? 1 : 0;
vp->full_bus_master_rx = (vp->capabilities & 0x20) ? 1 : 0;
dev->netdev_ops = &netdev_ops;
dev->watchdog_timeo = (400 * HZ) / 1000;
dev->ethtool_ops = &netdev_ethtool_ops;
return register_netdev(dev);
}
static int corkscrew_open(struct net_device *dev)
{
int ioaddr = dev->base_addr;
struct corkscrew_private *vp = netdev_priv(dev);
__u32 config;
int i;
EL3WINDOW(3);
if (vp->full_duplex)
outb(0x20, ioaddr + Wn3_MAC_Ctrl);
config = inl(ioaddr + Wn3_Config);
if (vp->media_override != 7) {
if (corkscrew_debug > 1)
pr_info("%s: Media override to transceiver %d (%s).\n",
dev->name, vp->media_override,
media_tbl[vp->media_override].name);
dev->if_port = vp->media_override;
} else if (vp->autoselect) {
dev->if_port = 4;
while (!(vp->available_media & media_tbl[dev->if_port].mask))
dev->if_port = media_tbl[dev->if_port].next;
if (corkscrew_debug > 1)
pr_debug("%s: Initial media type %s.\n",
dev->name, media_tbl[dev->if_port].name);
init_timer(&vp->timer);
vp->timer.expires = jiffies + media_tbl[dev->if_port].wait;
vp->timer.data = (unsigned long) dev;
vp->timer.function = corkscrew_timer;
add_timer(&vp->timer);
} else
dev->if_port = vp->default_media;
config = (config & ~Xcvr) | (dev->if_port << Xcvr_shift);
outl(config, ioaddr + Wn3_Config);
if (corkscrew_debug > 1) {
pr_debug("%s: corkscrew_open() InternalConfig %8.8x.\n",
dev->name, config);
}
outw(TxReset, ioaddr + EL3_CMD);
for (i = 20; i >= 0; i--)
if (!(inw(ioaddr + EL3_STATUS) & CmdInProgress))
break;
outw(RxReset, ioaddr + EL3_CMD);
for (i = 20; i >= 0; i--)
if (!(inw(ioaddr + EL3_STATUS) & CmdInProgress))
break;
outw(SetStatusEnb | 0x00, ioaddr + EL3_CMD);
if (vp->capabilities == 0x11c7) {
if (dev->irq == 0 ||
dev->dma == 0 ||
request_irq(dev->irq, corkscrew_interrupt, 0,
vp->product_name, dev))
return -EAGAIN;
enable_dma(dev->dma);
set_dma_mode(dev->dma, DMA_MODE_CASCADE);
} else if (request_irq(dev->irq, corkscrew_interrupt, IRQF_SHARED,
vp->product_name, dev)) {
return -EAGAIN;
}
if (corkscrew_debug > 1) {
EL3WINDOW(4);
pr_debug("%s: corkscrew_open() irq %d media status %4.4x.\n",
dev->name, dev->irq, inw(ioaddr + Wn4_Media));
}
EL3WINDOW(2);
for (i = 0; i < 6; i++)
outb(dev->dev_addr[i], ioaddr + i);
for (; i < 12; i += 2)
outw(0, ioaddr + i);
if (dev->if_port == 3)
outw(StartCoax, ioaddr + EL3_CMD);
EL3WINDOW(4);
outw((inw(ioaddr + Wn4_Media) & ~(Media_10TP | Media_SQE)) |
media_tbl[dev->if_port].media_bits, ioaddr + Wn4_Media);
outw(StatsDisable, ioaddr + EL3_CMD);
EL3WINDOW(6);
for (i = 0; i < 10; i++)
inb(ioaddr + i);
inw(ioaddr + 10);
inw(ioaddr + 12);
EL3WINDOW(4);
inb(ioaddr + 12);
outw(0x0040, ioaddr + Wn4_NetDiag);
EL3WINDOW(7);
if (vp->full_bus_master_rx) {
vp->cur_rx = vp->dirty_rx = 0;
if (corkscrew_debug > 2)
pr_debug("%s: Filling in the Rx ring.\n", dev->name);
for (i = 0; i < RX_RING_SIZE; i++) {
struct sk_buff *skb;
if (i < (RX_RING_SIZE - 1))
vp->rx_ring[i].next =
isa_virt_to_bus(&vp->rx_ring[i + 1]);
else
vp->rx_ring[i].next = 0;
vp->rx_ring[i].status = 0;
vp->rx_ring[i].length = PKT_BUF_SZ | 0x80000000;
skb = netdev_alloc_skb(dev, PKT_BUF_SZ);
vp->rx_skbuff[i] = skb;
if (skb == NULL)
break;
skb_reserve(skb, 2);
vp->rx_ring[i].addr = isa_virt_to_bus(skb->data);
}
if (i != 0)
vp->rx_ring[i - 1].next =
isa_virt_to_bus(&vp->rx_ring[0]);
outl(isa_virt_to_bus(&vp->rx_ring[0]), ioaddr + UpListPtr);
}
if (vp->full_bus_master_tx) {
vp->cur_tx = vp->dirty_tx = 0;
outb(PKT_BUF_SZ >> 8, ioaddr + TxFreeThreshold);
for (i = 0; i < TX_RING_SIZE; i++)
vp->tx_skbuff[i] = NULL;
outl(0, ioaddr + DownListPtr);
}
set_rx_mode(dev);
outw(StatsEnable, ioaddr + EL3_CMD);
netif_start_queue(dev);
outw(RxEnable, ioaddr + EL3_CMD);
outw(TxEnable, ioaddr + EL3_CMD);
outw(SetStatusEnb | AdapterFailure | IntReq | StatsFull |
(vp->full_bus_master_tx ? DownComplete : TxAvailable) |
(vp->full_bus_master_rx ? UpComplete : RxComplete) |
(vp->bus_master ? DMADone : 0), ioaddr + EL3_CMD);
outw(AckIntr | IntLatch | TxAvailable | RxEarly | IntReq,
ioaddr + EL3_CMD);
outw(SetIntrEnb | IntLatch | TxAvailable | RxComplete | StatsFull
| (vp->bus_master ? DMADone : 0) | UpComplete | DownComplete,
ioaddr + EL3_CMD);
return 0;
}
static void corkscrew_timer(unsigned long data)
{
#ifdef AUTOMEDIA
struct net_device *dev = (struct net_device *) data;
struct corkscrew_private *vp = netdev_priv(dev);
int ioaddr = dev->base_addr;
unsigned long flags;
int ok = 0;
if (corkscrew_debug > 1)
pr_debug("%s: Media selection timer tick happened, %s.\n",
dev->name, media_tbl[dev->if_port].name);
spin_lock_irqsave(&vp->lock, flags);
{
int old_window = inw(ioaddr + EL3_CMD) >> 13;
int media_status;
EL3WINDOW(4);
media_status = inw(ioaddr + Wn4_Media);
switch (dev->if_port) {
case 0:
case 4:
case 5:
if (media_status & Media_LnkBeat) {
ok = 1;
if (corkscrew_debug > 1)
pr_debug("%s: Media %s has link beat, %x.\n",
dev->name,
media_tbl[dev->if_port].name,
media_status);
} else if (corkscrew_debug > 1)
pr_debug("%s: Media %s is has no link beat, %x.\n",
dev->name,
media_tbl[dev->if_port].name,
media_status);
break;
default:
if (corkscrew_debug > 1)
pr_debug("%s: Media %s is has no indication, %x.\n",
dev->name,
media_tbl[dev->if_port].name,
media_status);
ok = 1;
}
if (!ok) {
__u32 config;
do {
dev->if_port =
media_tbl[dev->if_port].next;
}
while (!(vp->available_media & media_tbl[dev->if_port].mask));
if (dev->if_port == 8) {
dev->if_port = vp->default_media;
if (corkscrew_debug > 1)
pr_debug("%s: Media selection failing, using default %s port.\n",
dev->name,
media_tbl[dev->if_port].name);
} else {
if (corkscrew_debug > 1)
pr_debug("%s: Media selection failed, now trying %s port.\n",
dev->name,
media_tbl[dev->if_port].name);
vp->timer.expires = jiffies + media_tbl[dev->if_port].wait;
add_timer(&vp->timer);
}
outw((media_status & ~(Media_10TP | Media_SQE)) |
media_tbl[dev->if_port].media_bits,
ioaddr + Wn4_Media);
EL3WINDOW(3);
config = inl(ioaddr + Wn3_Config);
config = (config & ~Xcvr) | (dev->if_port << Xcvr_shift);
outl(config, ioaddr + Wn3_Config);
outw(dev->if_port == 3 ? StartCoax : StopCoax,
ioaddr + EL3_CMD);
}
EL3WINDOW(old_window);
}
spin_unlock_irqrestore(&vp->lock, flags);
if (corkscrew_debug > 1)
pr_debug("%s: Media selection timer finished, %s.\n",
dev->name, media_tbl[dev->if_port].name);
#endif
}
static void corkscrew_timeout(struct net_device *dev)
{
int i;
struct corkscrew_private *vp = netdev_priv(dev);
int ioaddr = dev->base_addr;
pr_warn("%s: transmit timed out, tx_status %2.2x status %4.4x\n",
dev->name, inb(ioaddr + TxStatus),
inw(ioaddr + EL3_STATUS));
if ((inb(ioaddr + TxStatus) & 0x88) == 0x88)
pr_warn("%s: Transmitter encountered 16 collisions -- network cable problem?\n",
dev->name);
#ifndef final_version
pr_debug(" Flags; bus-master %d, full %d; dirty %d current %d.\n",
vp->full_bus_master_tx, vp->tx_full, vp->dirty_tx,
vp->cur_tx);
pr_debug(" Down list %8.8x vs. %p.\n", inl(ioaddr + DownListPtr),
&vp->tx_ring[0]);
for (i = 0; i < TX_RING_SIZE; i++) {
pr_debug(" %d: %p length %8.8x status %8.8x\n", i,
&vp->tx_ring[i],
vp->tx_ring[i].length, vp->tx_ring[i].status);
}
#endif
outw(TxReset, ioaddr + EL3_CMD);
for (i = 20; i >= 0; i--)
if (!(inw(ioaddr + EL3_STATUS) & CmdInProgress))
break;
outw(TxEnable, ioaddr + EL3_CMD);
dev->trans_start = jiffies;
dev->stats.tx_errors++;
dev->stats.tx_dropped++;
netif_wake_queue(dev);
}
static netdev_tx_t corkscrew_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct corkscrew_private *vp = netdev_priv(dev);
int ioaddr = dev->base_addr;
netif_stop_queue(dev);
if (vp->full_bus_master_tx) {
int entry = vp->cur_tx % TX_RING_SIZE;
struct boom_tx_desc *prev_entry;
unsigned long flags;
int i;
if (vp->tx_full)
return NETDEV_TX_BUSY;
if (vp->cur_tx != 0)
prev_entry = &vp->tx_ring[(vp->cur_tx - 1) % TX_RING_SIZE];
else
prev_entry = NULL;
if (corkscrew_debug > 3)
pr_debug("%s: Trying to send a packet, Tx index %d.\n",
dev->name, vp->cur_tx);
vp->tx_skbuff[entry] = skb;
vp->tx_ring[entry].next = 0;
vp->tx_ring[entry].addr = isa_virt_to_bus(skb->data);
vp->tx_ring[entry].length = skb->len | 0x80000000;
vp->tx_ring[entry].status = skb->len | 0x80000000;
spin_lock_irqsave(&vp->lock, flags);
outw(DownStall, ioaddr + EL3_CMD);
for (i = 20; i >= 0; i--)
if ((inw(ioaddr + EL3_STATUS) & CmdInProgress) == 0)
break;
if (prev_entry)
prev_entry->next = isa_virt_to_bus(&vp->tx_ring[entry]);
if (inl(ioaddr + DownListPtr) == 0) {
outl(isa_virt_to_bus(&vp->tx_ring[entry]),
ioaddr + DownListPtr);
queued_packet++;
}
outw(DownUnstall, ioaddr + EL3_CMD);
spin_unlock_irqrestore(&vp->lock, flags);
vp->cur_tx++;
if (vp->cur_tx - vp->dirty_tx > TX_RING_SIZE - 1)
vp->tx_full = 1;
else {
if (prev_entry)
prev_entry->status &= ~0x80000000;
netif_wake_queue(dev);
}
return NETDEV_TX_OK;
}
outl(skb->len, ioaddr + TX_FIFO);
dev->stats.tx_bytes += skb->len;
#ifdef VORTEX_BUS_MASTER
if (vp->bus_master) {
outl((int) (skb->data), ioaddr + Wn7_MasterAddr);
outw((skb->len + 3) & ~3, ioaddr + Wn7_MasterLen);
vp->tx_skb = skb;
outw(StartDMADown, ioaddr + EL3_CMD);
} else {
outsl(ioaddr + TX_FIFO, skb->data, (skb->len + 3) >> 2);
dev_kfree_skb(skb);
if (inw(ioaddr + TxFree) > 1536) {
netif_wake_queue(dev);
} else
outw(SetTxThreshold + (1536 >> 2),
ioaddr + EL3_CMD);
}
#else
outsl(ioaddr + TX_FIFO, skb->data, (skb->len + 3) >> 2);
dev_kfree_skb(skb);
if (inw(ioaddr + TxFree) > 1536) {
netif_wake_queue(dev);
} else
outw(SetTxThreshold + (1536 >> 2), ioaddr + EL3_CMD);
#endif
{
short tx_status;
int i = 4;
while (--i > 0 && (tx_status = inb(ioaddr + TxStatus)) > 0) {
if (tx_status & 0x3C) {
if (corkscrew_debug > 2)
pr_debug("%s: Tx error, status %2.2x.\n",
dev->name, tx_status);
if (tx_status & 0x04)
dev->stats.tx_fifo_errors++;
if (tx_status & 0x38)
dev->stats.tx_aborted_errors++;
if (tx_status & 0x30) {
int j;
outw(TxReset, ioaddr + EL3_CMD);
for (j = 20; j >= 0; j--)
if (!(inw(ioaddr + EL3_STATUS) & CmdInProgress))
break;
}
outw(TxEnable, ioaddr + EL3_CMD);
}
outb(0x00, ioaddr + TxStatus);
}
}
return NETDEV_TX_OK;
}
static irqreturn_t corkscrew_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct corkscrew_private *lp = netdev_priv(dev);
int ioaddr, status;
int latency;
int i = max_interrupt_work;
ioaddr = dev->base_addr;
latency = inb(ioaddr + Timer);
spin_lock(&lp->lock);
status = inw(ioaddr + EL3_STATUS);
if (corkscrew_debug > 4)
pr_debug("%s: interrupt, status %4.4x, timer %d.\n",
dev->name, status, latency);
if ((status & 0xE000) != 0xE000) {
static int donedidthis;
if (donedidthis++ > 100) {
pr_err("%s: Bogus interrupt, bailing. Status %4.4x, start=%d.\n",
dev->name, status, netif_running(dev));
free_irq(dev->irq, dev);
dev->irq = -1;
}
}
do {
if (corkscrew_debug > 5)
pr_debug("%s: In interrupt loop, status %4.4x.\n",
dev->name, status);
if (status & RxComplete)
corkscrew_rx(dev);
if (status & TxAvailable) {
if (corkscrew_debug > 5)
pr_debug(" TX room bit was handled.\n");
outw(AckIntr | TxAvailable, ioaddr + EL3_CMD);
netif_wake_queue(dev);
}
if (status & DownComplete) {
unsigned int dirty_tx = lp->dirty_tx;
while (lp->cur_tx - dirty_tx > 0) {
int entry = dirty_tx % TX_RING_SIZE;
if (inl(ioaddr + DownListPtr) == isa_virt_to_bus(&lp->tx_ring[entry]))
break;
if (lp->tx_skbuff[entry]) {
dev_kfree_skb_irq(lp->tx_skbuff[entry]);
lp->tx_skbuff[entry] = NULL;
}
dirty_tx++;
}
lp->dirty_tx = dirty_tx;
outw(AckIntr | DownComplete, ioaddr + EL3_CMD);
if (lp->tx_full && (lp->cur_tx - dirty_tx <= TX_RING_SIZE - 1)) {
lp->tx_full = 0;
netif_wake_queue(dev);
}
}
#ifdef VORTEX_BUS_MASTER
if (status & DMADone) {
outw(0x1000, ioaddr + Wn7_MasterStatus);
dev_kfree_skb_irq(lp->tx_skb);
netif_wake_queue(dev);
}
#endif
if (status & UpComplete) {
boomerang_rx(dev);
outw(AckIntr | UpComplete, ioaddr + EL3_CMD);
}
if (status & (AdapterFailure | RxEarly | StatsFull)) {
if (status & RxEarly) {
corkscrew_rx(dev);
outw(AckIntr | RxEarly, ioaddr + EL3_CMD);
}
if (status & StatsFull) {
static int DoneDidThat;
if (corkscrew_debug > 4)
pr_debug("%s: Updating stats.\n", dev->name);
update_stats(ioaddr, dev);
if (DoneDidThat == 0 && inw(ioaddr + EL3_STATUS) & StatsFull) {
int win, reg;
pr_notice("%s: Updating stats failed, disabling stats as an interrupt source.\n",
dev->name);
for (win = 0; win < 8; win++) {
EL3WINDOW(win);
pr_notice("Vortex window %d:", win);
for (reg = 0; reg < 16; reg++)
pr_cont(" %2.2x", inb(ioaddr + reg));
pr_cont("\n");
}
EL3WINDOW(7);
outw(SetIntrEnb | TxAvailable |
RxComplete | AdapterFailure |
UpComplete | DownComplete |
TxComplete, ioaddr + EL3_CMD);
DoneDidThat++;
}
}
if (status & AdapterFailure) {
outw(RxReset, ioaddr + EL3_CMD);
set_rx_mode(dev);
outw(RxEnable, ioaddr + EL3_CMD);
outw(AckIntr | AdapterFailure,
ioaddr + EL3_CMD);
}
}
if (--i < 0) {
pr_err("%s: Too much work in interrupt, status %4.4x. Disabling functions (%4.4x).\n",
dev->name, status, SetStatusEnb | ((~status) & 0x7FE));
outw(SetStatusEnb | ((~status) & 0x7FE), ioaddr + EL3_CMD);
outw(AckIntr | 0x7FF, ioaddr + EL3_CMD);
break;
}
outw(AckIntr | IntReq | IntLatch, ioaddr + EL3_CMD);
} while ((status = inw(ioaddr + EL3_STATUS)) & (IntLatch | RxComplete));
spin_unlock(&lp->lock);
if (corkscrew_debug > 4)
pr_debug("%s: exiting interrupt, status %4.4x.\n", dev->name, status);
return IRQ_HANDLED;
}
static int corkscrew_rx(struct net_device *dev)
{
int ioaddr = dev->base_addr;
int i;
short rx_status;
if (corkscrew_debug > 5)
pr_debug(" In rx_packet(), status %4.4x, rx_status %4.4x.\n",
inw(ioaddr + EL3_STATUS), inw(ioaddr + RxStatus));
while ((rx_status = inw(ioaddr + RxStatus)) > 0) {
if (rx_status & 0x4000) {
unsigned char rx_error = inb(ioaddr + RxErrors);
if (corkscrew_debug > 2)
pr_debug(" Rx error: status %2.2x.\n",
rx_error);
dev->stats.rx_errors++;
if (rx_error & 0x01)
dev->stats.rx_over_errors++;
if (rx_error & 0x02)
dev->stats.rx_length_errors++;
if (rx_error & 0x04)
dev->stats.rx_frame_errors++;
if (rx_error & 0x08)
dev->stats.rx_crc_errors++;
if (rx_error & 0x10)
dev->stats.rx_length_errors++;
} else {
short pkt_len = rx_status & 0x1fff;
struct sk_buff *skb;
skb = netdev_alloc_skb(dev, pkt_len + 5 + 2);
if (corkscrew_debug > 4)
pr_debug("Receiving packet size %d status %4.4x.\n",
pkt_len, rx_status);
if (skb != NULL) {
skb_reserve(skb, 2);
insl(ioaddr + RX_FIFO,
skb_put(skb, pkt_len),
(pkt_len + 3) >> 2);
outw(RxDiscard, ioaddr + EL3_CMD);
skb->protocol = eth_type_trans(skb, dev);
netif_rx(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += pkt_len;
for (i = 200; i >= 0; i--)
if (! (inw(ioaddr + EL3_STATUS) & CmdInProgress))
break;
continue;
} else if (corkscrew_debug)
pr_debug("%s: Couldn't allocate a sk_buff of size %d.\n", dev->name, pkt_len);
}
outw(RxDiscard, ioaddr + EL3_CMD);
dev->stats.rx_dropped++;
for (i = 200; i >= 0; i--)
if (!(inw(ioaddr + EL3_STATUS) & CmdInProgress))
break;
}
return 0;
}
static int boomerang_rx(struct net_device *dev)
{
struct corkscrew_private *vp = netdev_priv(dev);
int entry = vp->cur_rx % RX_RING_SIZE;
int ioaddr = dev->base_addr;
int rx_status;
if (corkscrew_debug > 5)
pr_debug(" In boomerang_rx(), status %4.4x, rx_status %4.4x.\n",
inw(ioaddr + EL3_STATUS), inw(ioaddr + RxStatus));
while ((rx_status = vp->rx_ring[entry].status) & RxDComplete) {
if (rx_status & RxDError) {
unsigned char rx_error = rx_status >> 16;
if (corkscrew_debug > 2)
pr_debug(" Rx error: status %2.2x.\n",
rx_error);
dev->stats.rx_errors++;
if (rx_error & 0x01)
dev->stats.rx_over_errors++;
if (rx_error & 0x02)
dev->stats.rx_length_errors++;
if (rx_error & 0x04)
dev->stats.rx_frame_errors++;
if (rx_error & 0x08)
dev->stats.rx_crc_errors++;
if (rx_error & 0x10)
dev->stats.rx_length_errors++;
} else {
short pkt_len = rx_status & 0x1fff;
struct sk_buff *skb;
dev->stats.rx_bytes += pkt_len;
if (corkscrew_debug > 4)
pr_debug("Receiving packet size %d status %4.4x.\n",
pkt_len, rx_status);
if (pkt_len < rx_copybreak &&
(skb = netdev_alloc_skb(dev, pkt_len + 4)) != NULL) {
skb_reserve(skb, 2);
memcpy(skb_put(skb, pkt_len),
isa_bus_to_virt(vp->rx_ring[entry].
addr), pkt_len);
rx_copy++;
} else {
void *temp;
skb = vp->rx_skbuff[entry];
vp->rx_skbuff[entry] = NULL;
temp = skb_put(skb, pkt_len);
if (isa_bus_to_virt(vp->rx_ring[entry].addr) != temp)
pr_warn("%s: Warning -- the skbuff addresses do not match in boomerang_rx: %p vs. %p / %p\n",
dev->name,
isa_bus_to_virt(vp->rx_ring[entry].addr),
skb->head, temp);
rx_nocopy++;
}
skb->protocol = eth_type_trans(skb, dev);
netif_rx(skb);
dev->stats.rx_packets++;
}
entry = (++vp->cur_rx) % RX_RING_SIZE;
}
for (; vp->cur_rx - vp->dirty_rx > 0; vp->dirty_rx++) {
struct sk_buff *skb;
entry = vp->dirty_rx % RX_RING_SIZE;
if (vp->rx_skbuff[entry] == NULL) {
skb = netdev_alloc_skb(dev, PKT_BUF_SZ);
if (skb == NULL)
break;
skb_reserve(skb, 2);
vp->rx_ring[entry].addr = isa_virt_to_bus(skb->data);
vp->rx_skbuff[entry] = skb;
}
vp->rx_ring[entry].status = 0;
}
return 0;
}
static int corkscrew_close(struct net_device *dev)
{
struct corkscrew_private *vp = netdev_priv(dev);
int ioaddr = dev->base_addr;
int i;
netif_stop_queue(dev);
if (corkscrew_debug > 1) {
pr_debug("%s: corkscrew_close() status %4.4x, Tx status %2.2x.\n",
dev->name, inw(ioaddr + EL3_STATUS),
inb(ioaddr + TxStatus));
pr_debug("%s: corkscrew close stats: rx_nocopy %d rx_copy %d tx_queued %d.\n",
dev->name, rx_nocopy, rx_copy, queued_packet);
}
del_timer(&vp->timer);
outw(StatsDisable, ioaddr + EL3_CMD);
outw(RxDisable, ioaddr + EL3_CMD);
outw(TxDisable, ioaddr + EL3_CMD);
if (dev->if_port == XCVR_10base2)
outw(StopCoax, ioaddr + EL3_CMD);
free_irq(dev->irq, dev);
outw(SetIntrEnb | 0x0000, ioaddr + EL3_CMD);
update_stats(ioaddr, dev);
if (vp->full_bus_master_rx) {
outl(0, ioaddr + UpListPtr);
for (i = 0; i < RX_RING_SIZE; i++)
if (vp->rx_skbuff[i]) {
dev_kfree_skb(vp->rx_skbuff[i]);
vp->rx_skbuff[i] = NULL;
}
}
if (vp->full_bus_master_tx) {
outl(0, ioaddr + DownListPtr);
for (i = 0; i < TX_RING_SIZE; i++)
if (vp->tx_skbuff[i]) {
dev_kfree_skb(vp->tx_skbuff[i]);
vp->tx_skbuff[i] = NULL;
}
}
return 0;
}
static struct net_device_stats *corkscrew_get_stats(struct net_device *dev)
{
struct corkscrew_private *vp = netdev_priv(dev);
unsigned long flags;
if (netif_running(dev)) {
spin_lock_irqsave(&vp->lock, flags);
update_stats(dev->base_addr, dev);
spin_unlock_irqrestore(&vp->lock, flags);
}
return &dev->stats;
}
static void update_stats(int ioaddr, struct net_device *dev)
{
EL3WINDOW(6);
dev->stats.tx_carrier_errors += inb(ioaddr + 0);
dev->stats.tx_heartbeat_errors += inb(ioaddr + 1);
inb(ioaddr + 2);
dev->stats.collisions += inb(ioaddr + 3);
dev->stats.tx_window_errors += inb(ioaddr + 4);
dev->stats.rx_fifo_errors += inb(ioaddr + 5);
dev->stats.tx_packets += inb(ioaddr + 6);
dev->stats.tx_packets += (inb(ioaddr + 9) & 0x30) << 4;
inb(ioaddr + 7);
inb(ioaddr + 8);
inw(ioaddr + 10);
inw(ioaddr + 12);
EL3WINDOW(4);
inb(ioaddr + 12);
EL3WINDOW(7);
}
static void set_rx_mode(struct net_device *dev)
{
int ioaddr = dev->base_addr;
short new_mode;
if (dev->flags & IFF_PROMISC) {
if (corkscrew_debug > 3)
pr_debug("%s: Setting promiscuous mode.\n",
dev->name);
new_mode = SetRxFilter | RxStation | RxMulticast | RxBroadcast | RxProm;
} else if (!netdev_mc_empty(dev) || dev->flags & IFF_ALLMULTI) {
new_mode = SetRxFilter | RxStation | RxMulticast | RxBroadcast;
} else
new_mode = SetRxFilter | RxStation | RxBroadcast;
outw(new_mode, ioaddr + EL3_CMD);
}
static void netdev_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
strlcpy(info->driver, DRV_NAME, sizeof(info->driver));
strlcpy(info->version, DRV_VERSION, sizeof(info->version));
snprintf(info->bus_info, sizeof(info->bus_info), "ISA 0x%lx",
dev->base_addr);
}
static u32 netdev_get_msglevel(struct net_device *dev)
{
return corkscrew_debug;
}
static void netdev_set_msglevel(struct net_device *dev, u32 level)
{
corkscrew_debug = level;
}
void cleanup_module(void)
{
while (!list_empty(&root_corkscrew_dev)) {
struct net_device *dev;
struct corkscrew_private *vp;
vp = list_entry(root_corkscrew_dev.next,
struct corkscrew_private, list);
dev = vp->our_dev;
unregister_netdev(dev);
cleanup_card(dev);
free_netdev(dev);
}
}
