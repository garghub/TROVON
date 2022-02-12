static int el3_isa_id_sequence(__be16 *phys_addr)
{
short lrs_state = 0xff;
int i;
outb(0x00, id_port);
outb(0x00, id_port);
for (i = 0; i < 255; i++) {
outb(lrs_state, id_port);
lrs_state <<= 1;
lrs_state = lrs_state & 0x100 ? lrs_state ^ 0xcf : lrs_state;
}
if (current_tag == 0)
outb(0xd0, id_port);
else
outb(0xd8, id_port);
if (id_read_eeprom(7) != 0x6d50)
return 1;
for (i = 0; i < 3; i++)
phys_addr[i] = htons(id_read_eeprom(i));
#ifdef CONFIG_PNP
if (!nopnp) {
for (i = 0; i < el3_cards; i++) {
struct el3_private *lp = netdev_priv(el3_devs[i]);
if (lp->type == EL3_PNP &&
!memcmp(phys_addr, el3_devs[i]->dev_addr,
ETH_ALEN)) {
if (el3_debug > 3)
pr_debug("3c509 with address %02x %02x %02x %02x %02x %02x was found by ISAPnP\n",
phys_addr[0] & 0xff, phys_addr[0] >> 8,
phys_addr[1] & 0xff, phys_addr[1] >> 8,
phys_addr[2] & 0xff, phys_addr[2] >> 8);
outb(0xd0 + ++current_tag, id_port);
return 2;
}
}
}
#endif
return 0;
}
static void __devinit el3_dev_fill(struct net_device *dev, __be16 *phys_addr,
int ioaddr, int irq, int if_port,
enum el3_cardtype type)
{
struct el3_private *lp = netdev_priv(dev);
memcpy(dev->dev_addr, phys_addr, ETH_ALEN);
dev->base_addr = ioaddr;
dev->irq = irq;
dev->if_port = if_port;
lp->type = type;
}
static int __devinit el3_isa_match(struct device *pdev,
unsigned int ndev)
{
struct net_device *dev;
int ioaddr, isa_irq, if_port, err;
unsigned int iobase;
__be16 phys_addr[3];
while ((err = el3_isa_id_sequence(phys_addr)) == 2)
;
if (err == 1)
return 0;
iobase = id_read_eeprom(8);
if_port = iobase >> 14;
ioaddr = 0x200 + ((iobase & 0x1f) << 4);
if (irq[el3_cards] > 1 && irq[el3_cards] < 16)
isa_irq = irq[el3_cards];
else
isa_irq = id_read_eeprom(9) >> 12;
dev = alloc_etherdev(sizeof(struct el3_private));
if (!dev)
return -ENOMEM;
netdev_boot_setup_check(dev);
if (!request_region(ioaddr, EL3_IO_EXTENT, "3c509-isa")) {
free_netdev(dev);
return 0;
}
outb(0xd0 + ++current_tag, id_port);
outb((ioaddr >> 4) | 0xe0, id_port);
EL3WINDOW(0);
if (inw(ioaddr) != 0x6d50) {
free_netdev(dev);
return 0;
}
outw(0x0f00, ioaddr + WN0_IRQ);
el3_dev_fill(dev, phys_addr, ioaddr, isa_irq, if_port, EL3_ISA);
dev_set_drvdata(pdev, dev);
if (el3_common_init(dev)) {
free_netdev(dev);
return 0;
}
el3_devs[el3_cards++] = dev;
return 1;
}
static int __devexit el3_isa_remove(struct device *pdev,
unsigned int ndev)
{
el3_device_remove(pdev);
dev_set_drvdata(pdev, NULL);
return 0;
}
static int el3_isa_suspend(struct device *dev, unsigned int n,
pm_message_t state)
{
current_tag = 0;
return el3_suspend(dev, state);
}
static int el3_isa_resume(struct device *dev, unsigned int n)
{
struct net_device *ndev = dev_get_drvdata(dev);
int ioaddr = ndev->base_addr, err;
__be16 phys_addr[3];
while ((err = el3_isa_id_sequence(phys_addr)) == 2)
;
if (err == 1)
return 0;
outb(0xd0 + ++current_tag, id_port);
outb((ioaddr >> 4) | 0xe0, id_port);
EL3WINDOW(0);
if (inw(ioaddr) != 0x6d50)
return 1;
outw(0x0f00, ioaddr + WN0_IRQ);
return el3_resume(dev);
}
static int __devinit el3_pnp_probe(struct pnp_dev *pdev,
const struct pnp_device_id *id)
{
short i;
int ioaddr, irq, if_port;
__be16 phys_addr[3];
struct net_device *dev = NULL;
int err;
ioaddr = pnp_port_start(pdev, 0);
if (!request_region(ioaddr, EL3_IO_EXTENT, "3c509-pnp"))
return -EBUSY;
irq = pnp_irq(pdev, 0);
EL3WINDOW(0);
for (i = 0; i < 3; i++)
phys_addr[i] = htons(read_eeprom(ioaddr, i));
if_port = read_eeprom(ioaddr, 8) >> 14;
dev = alloc_etherdev(sizeof(struct el3_private));
if (!dev) {
release_region(ioaddr, EL3_IO_EXTENT);
return -ENOMEM;
}
SET_NETDEV_DEV(dev, &pdev->dev);
netdev_boot_setup_check(dev);
el3_dev_fill(dev, phys_addr, ioaddr, irq, if_port, EL3_PNP);
pnp_set_drvdata(pdev, dev);
err = el3_common_init(dev);
if (err) {
pnp_set_drvdata(pdev, NULL);
free_netdev(dev);
return err;
}
el3_devs[el3_cards++] = dev;
return 0;
}
static void __devexit el3_pnp_remove(struct pnp_dev *pdev)
{
el3_common_remove(pnp_get_drvdata(pdev));
pnp_set_drvdata(pdev, NULL);
}
static int el3_pnp_suspend(struct pnp_dev *pdev, pm_message_t state)
{
return el3_suspend(&pdev->dev, state);
}
static int el3_pnp_resume(struct pnp_dev *pdev)
{
return el3_resume(&pdev->dev);
}
static int __devinit el3_common_init(struct net_device *dev)
{
struct el3_private *lp = netdev_priv(dev);
int err;
const char *if_names[] = {"10baseT", "AUI", "undefined", "BNC"};
spin_lock_init(&lp->lock);
if (dev->mem_start & 0x05) {
dev->if_port = (dev->mem_start & 0x0f);
} else {
dev->if_port |= (dev->mem_start & 0x08);
}
dev->netdev_ops = &netdev_ops;
dev->watchdog_timeo = TX_TIMEOUT;
SET_ETHTOOL_OPS(dev, &ethtool_ops);
err = register_netdev(dev);
if (err) {
pr_err("Failed to register 3c5x9 at %#3.3lx, IRQ %d.\n",
dev->base_addr, dev->irq);
release_region(dev->base_addr, EL3_IO_EXTENT);
return err;
}
pr_info("%s: 3c5x9 found at %#3.3lx, %s port, address %pM, IRQ %d.\n",
dev->name, dev->base_addr, if_names[(dev->if_port & 0x03)],
dev->dev_addr, dev->irq);
if (el3_debug > 0)
pr_info("%s", version);
return 0;
}
static void el3_common_remove (struct net_device *dev)
{
unregister_netdev (dev);
release_region(dev->base_addr, EL3_IO_EXTENT);
free_netdev (dev);
}
static int __init el3_mca_probe(struct device *device)
{
short i;
int ioaddr, irq, if_port;
__be16 phys_addr[3];
struct net_device *dev = NULL;
u_char pos4, pos5;
struct mca_device *mdev = to_mca_device(device);
int slot = mdev->slot;
int err;
pos4 = mca_device_read_stored_pos(mdev, 4);
pos5 = mca_device_read_stored_pos(mdev, 5);
ioaddr = ((short)((pos4&0xfc)|0x02)) << 8;
irq = pos5 & 0x0f;
pr_info("3c529: found %s at slot %d\n",
el3_mca_adapter_names[mdev->index], slot + 1);
strncpy(mdev->name, el3_mca_adapter_names[mdev->index],
sizeof(mdev->name));
mca_device_set_claim(mdev, 1);
if_port = pos4 & 0x03;
irq = mca_device_transform_irq(mdev, irq);
ioaddr = mca_device_transform_ioport(mdev, ioaddr);
if (el3_debug > 2) {
pr_debug("3c529: irq %d ioaddr 0x%x ifport %d\n", irq, ioaddr, if_port);
}
EL3WINDOW(0);
for (i = 0; i < 3; i++)
phys_addr[i] = htons(read_eeprom(ioaddr, i));
dev = alloc_etherdev(sizeof (struct el3_private));
if (dev == NULL) {
release_region(ioaddr, EL3_IO_EXTENT);
return -ENOMEM;
}
netdev_boot_setup_check(dev);
el3_dev_fill(dev, phys_addr, ioaddr, irq, if_port, EL3_MCA);
dev_set_drvdata(device, dev);
err = el3_common_init(dev);
if (err) {
dev_set_drvdata(device, NULL);
free_netdev(dev);
return -ENOMEM;
}
el3_devs[el3_cards++] = dev;
return 0;
}
static int __init el3_eisa_probe (struct device *device)
{
short i;
int ioaddr, irq, if_port;
__be16 phys_addr[3];
struct net_device *dev = NULL;
struct eisa_device *edev;
int err;
edev = to_eisa_device (device);
ioaddr = edev->base_addr;
if (!request_region(ioaddr, EL3_IO_EXTENT, "3c579-eisa"))
return -EBUSY;
outw(SelectWindow | 0, ioaddr + 0xC80 + EL3_CMD);
irq = inw(ioaddr + WN0_IRQ) >> 12;
if_port = inw(ioaddr + 6)>>14;
for (i = 0; i < 3; i++)
phys_addr[i] = htons(read_eeprom(ioaddr, i));
read_eeprom(ioaddr, 3);
dev = alloc_etherdev(sizeof (struct el3_private));
if (dev == NULL) {
release_region(ioaddr, EL3_IO_EXTENT);
return -ENOMEM;
}
netdev_boot_setup_check(dev);
el3_dev_fill(dev, phys_addr, ioaddr, irq, if_port, EL3_EISA);
eisa_set_drvdata (edev, dev);
err = el3_common_init(dev);
if (err) {
eisa_set_drvdata (edev, NULL);
free_netdev(dev);
return err;
}
el3_devs[el3_cards++] = dev;
return 0;
}
static int __devexit el3_device_remove (struct device *device)
{
struct net_device *dev;
dev = dev_get_drvdata(device);
el3_common_remove (dev);
return 0;
}
static ushort read_eeprom(int ioaddr, int index)
{
outw(EEPROM_READ + index, ioaddr + 10);
mdelay(2);
return inw(ioaddr + 12);
}
static ushort id_read_eeprom(int index)
{
int bit, word = 0;
outb(EEPROM_READ + index, id_port);
mdelay(4);
for (bit = 15; bit >= 0; bit--)
word = (word << 1) + (inb(id_port) & 0x01);
if (el3_debug > 3)
pr_debug(" 3c509 EEPROM word %d %#4.4x.\n", index, word);
return word;
}
static int
el3_open(struct net_device *dev)
{
int ioaddr = dev->base_addr;
int i;
outw(TxReset, ioaddr + EL3_CMD);
outw(RxReset, ioaddr + EL3_CMD);
outw(SetStatusEnb | 0x00, ioaddr + EL3_CMD);
i = request_irq(dev->irq, el3_interrupt, 0, dev->name, dev);
if (i)
return i;
EL3WINDOW(0);
if (el3_debug > 3)
pr_debug("%s: Opening, IRQ %d status@%x %4.4x.\n", dev->name,
dev->irq, ioaddr + EL3_STATUS, inw(ioaddr + EL3_STATUS));
el3_up(dev);
if (el3_debug > 3)
pr_debug("%s: Opened 3c509 IRQ %d status %4.4x.\n",
dev->name, dev->irq, inw(ioaddr + EL3_STATUS));
return 0;
}
static void
el3_tx_timeout (struct net_device *dev)
{
int ioaddr = dev->base_addr;
pr_warning("%s: transmit timed out, Tx_status %2.2x status %4.4x Tx FIFO room %d.\n",
dev->name, inb(ioaddr + TX_STATUS), inw(ioaddr + EL3_STATUS),
inw(ioaddr + TX_FREE));
dev->stats.tx_errors++;
dev->trans_start = jiffies;
outw(TxReset, ioaddr + EL3_CMD);
outw(TxEnable, ioaddr + EL3_CMD);
netif_wake_queue(dev);
}
static netdev_tx_t
el3_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct el3_private *lp = netdev_priv(dev);
int ioaddr = dev->base_addr;
unsigned long flags;
netif_stop_queue (dev);
dev->stats.tx_bytes += skb->len;
if (el3_debug > 4) {
pr_debug("%s: el3_start_xmit(length = %u) called, status %4.4x.\n",
dev->name, skb->len, inw(ioaddr + EL3_STATUS));
}
#if 0
#ifndef final_version
{
ushort status = inw(ioaddr + EL3_STATUS);
if (status & 0x0001 &&
inw(ioaddr + EL3_STATUS) & 1) {
pr_debug("%s: Missed interrupt, status then %04x now %04x"
" Tx %2.2x Rx %4.4x.\n", dev->name, status,
inw(ioaddr + EL3_STATUS), inb(ioaddr + TX_STATUS),
inw(ioaddr + RX_STATUS));
outw(SetStatusEnb | 0x00, ioaddr + EL3_CMD);
outw(AckIntr | IntLatch | TxAvailable | RxEarly | IntReq,
ioaddr + EL3_CMD);
outw(SetStatusEnb | 0xff, ioaddr + EL3_CMD);
}
}
#endif
#endif
spin_lock_irqsave(&lp->lock, flags);
outw(skb->len, ioaddr + TX_FIFO);
outw(0x00, ioaddr + TX_FIFO);
outsl(ioaddr + TX_FIFO, skb->data, (skb->len + 3) >> 2);
if (inw(ioaddr + TX_FREE) > 1536)
netif_start_queue(dev);
else
outw(SetTxThreshold + 1536, ioaddr + EL3_CMD);
spin_unlock_irqrestore(&lp->lock, flags);
dev_kfree_skb (skb);
{
short tx_status;
int i = 4;
while (--i > 0 && (tx_status = inb(ioaddr + TX_STATUS)) > 0) {
if (tx_status & 0x38) dev->stats.tx_aborted_errors++;
if (tx_status & 0x30) outw(TxReset, ioaddr + EL3_CMD);
if (tx_status & 0x3C) outw(TxEnable, ioaddr + EL3_CMD);
outb(0x00, ioaddr + TX_STATUS);
}
}
return NETDEV_TX_OK;
}
static irqreturn_t
el3_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct el3_private *lp;
int ioaddr, status;
int i = max_interrupt_work;
lp = netdev_priv(dev);
spin_lock(&lp->lock);
ioaddr = dev->base_addr;
if (el3_debug > 4) {
status = inw(ioaddr + EL3_STATUS);
pr_debug("%s: interrupt, status %4.4x.\n", dev->name, status);
}
while ((status = inw(ioaddr + EL3_STATUS)) &
(IntLatch | RxComplete | StatsFull)) {
if (status & RxComplete)
el3_rx(dev);
if (status & TxAvailable) {
if (el3_debug > 5)
pr_debug(" TX room bit was handled.\n");
outw(AckIntr | TxAvailable, ioaddr + EL3_CMD);
netif_wake_queue (dev);
}
if (status & (AdapterFailure | RxEarly | StatsFull | TxComplete)) {
if (status & StatsFull)
update_stats(dev);
if (status & RxEarly) {
el3_rx(dev);
outw(AckIntr | RxEarly, ioaddr + EL3_CMD);
}
if (status & TxComplete) {
short tx_status;
int i = 4;
while (--i>0 && (tx_status = inb(ioaddr + TX_STATUS)) > 0) {
if (tx_status & 0x38) dev->stats.tx_aborted_errors++;
if (tx_status & 0x30) outw(TxReset, ioaddr + EL3_CMD);
if (tx_status & 0x3C) outw(TxEnable, ioaddr + EL3_CMD);
outb(0x00, ioaddr + TX_STATUS);
}
}
if (status & AdapterFailure) {
outw(RxReset, ioaddr + EL3_CMD);
outw(SetRxFilter | RxStation | RxBroadcast
| (dev->flags & IFF_ALLMULTI ? RxMulticast : 0)
| (dev->flags & IFF_PROMISC ? RxProm : 0),
ioaddr + EL3_CMD);
outw(RxEnable, ioaddr + EL3_CMD);
outw(AckIntr | AdapterFailure, ioaddr + EL3_CMD);
}
}
if (--i < 0) {
pr_err("%s: Infinite loop in interrupt, status %4.4x.\n",
dev->name, status);
outw(AckIntr | 0xFF, ioaddr + EL3_CMD);
break;
}
outw(AckIntr | IntReq | IntLatch, ioaddr + EL3_CMD);
}
if (el3_debug > 4) {
pr_debug("%s: exiting interrupt, status %4.4x.\n", dev->name,
inw(ioaddr + EL3_STATUS));
}
spin_unlock(&lp->lock);
return IRQ_HANDLED;
}
static void el3_poll_controller(struct net_device *dev)
{
disable_irq(dev->irq);
el3_interrupt(dev->irq, dev);
enable_irq(dev->irq);
}
static struct net_device_stats *
el3_get_stats(struct net_device *dev)
{
struct el3_private *lp = netdev_priv(dev);
unsigned long flags;
spin_lock_irqsave(&lp->lock, flags);
update_stats(dev);
spin_unlock_irqrestore(&lp->lock, flags);
return &dev->stats;
}
static void update_stats(struct net_device *dev)
{
int ioaddr = dev->base_addr;
if (el3_debug > 5)
pr_debug(" Updating the statistics.\n");
outw(StatsDisable, ioaddr + EL3_CMD);
EL3WINDOW(6);
dev->stats.tx_carrier_errors += inb(ioaddr + 0);
dev->stats.tx_heartbeat_errors += inb(ioaddr + 1);
inb(ioaddr + 2);
dev->stats.collisions += inb(ioaddr + 3);
dev->stats.tx_window_errors += inb(ioaddr + 4);
dev->stats.rx_fifo_errors += inb(ioaddr + 5);
dev->stats.tx_packets += inb(ioaddr + 6);
inb(ioaddr + 7);
inb(ioaddr + 8);
inw(ioaddr + 10);
inw(ioaddr + 12);
EL3WINDOW(1);
outw(StatsEnable, ioaddr + EL3_CMD);
}
static int
el3_rx(struct net_device *dev)
{
int ioaddr = dev->base_addr;
short rx_status;
if (el3_debug > 5)
pr_debug(" In rx_packet(), status %4.4x, rx_status %4.4x.\n",
inw(ioaddr+EL3_STATUS), inw(ioaddr+RX_STATUS));
while ((rx_status = inw(ioaddr + RX_STATUS)) > 0) {
if (rx_status & 0x4000) {
short error = rx_status & 0x3800;
outw(RxDiscard, ioaddr + EL3_CMD);
dev->stats.rx_errors++;
switch (error) {
case 0x0000: dev->stats.rx_over_errors++; break;
case 0x0800: dev->stats.rx_length_errors++; break;
case 0x1000: dev->stats.rx_frame_errors++; break;
case 0x1800: dev->stats.rx_length_errors++; break;
case 0x2000: dev->stats.rx_frame_errors++; break;
case 0x2800: dev->stats.rx_crc_errors++; break;
}
} else {
short pkt_len = rx_status & 0x7ff;
struct sk_buff *skb;
skb = netdev_alloc_skb(dev, pkt_len + 5);
if (el3_debug > 4)
pr_debug("Receiving packet size %d status %4.4x.\n",
pkt_len, rx_status);
if (skb != NULL) {
skb_reserve(skb, 2);
insl(ioaddr + RX_FIFO, skb_put(skb,pkt_len),
(pkt_len + 3) >> 2);
outw(RxDiscard, ioaddr + EL3_CMD);
skb->protocol = eth_type_trans(skb,dev);
netif_rx(skb);
dev->stats.rx_bytes += pkt_len;
dev->stats.rx_packets++;
continue;
}
outw(RxDiscard, ioaddr + EL3_CMD);
dev->stats.rx_dropped++;
if (el3_debug)
pr_debug("%s: Couldn't allocate a sk_buff of size %d.\n",
dev->name, pkt_len);
}
inw(ioaddr + EL3_STATUS);
while (inw(ioaddr + EL3_STATUS) & 0x1000)
pr_debug(" Waiting for 3c509 to discard packet, status %x.\n",
inw(ioaddr + EL3_STATUS) );
}
return 0;
}
static void
set_multicast_list(struct net_device *dev)
{
unsigned long flags;
struct el3_private *lp = netdev_priv(dev);
int ioaddr = dev->base_addr;
int mc_count = netdev_mc_count(dev);
if (el3_debug > 1) {
static int old;
if (old != mc_count) {
old = mc_count;
pr_debug("%s: Setting Rx mode to %d addresses.\n",
dev->name, mc_count);
}
}
spin_lock_irqsave(&lp->lock, flags);
if (dev->flags&IFF_PROMISC) {
outw(SetRxFilter | RxStation | RxMulticast | RxBroadcast | RxProm,
ioaddr + EL3_CMD);
}
else if (mc_count || (dev->flags&IFF_ALLMULTI)) {
outw(SetRxFilter | RxStation | RxMulticast | RxBroadcast, ioaddr + EL3_CMD);
}
else
outw(SetRxFilter | RxStation | RxBroadcast, ioaddr + EL3_CMD);
spin_unlock_irqrestore(&lp->lock, flags);
}
static int
el3_close(struct net_device *dev)
{
int ioaddr = dev->base_addr;
struct el3_private *lp = netdev_priv(dev);
if (el3_debug > 2)
pr_debug("%s: Shutting down ethercard.\n", dev->name);
el3_down(dev);
free_irq(dev->irq, dev);
EL3WINDOW(0);
if (lp->type != EL3_EISA) {
outw(0x0f00, ioaddr + WN0_IRQ);
}
return 0;
}
static int
el3_link_ok(struct net_device *dev)
{
int ioaddr = dev->base_addr;
u16 tmp;
EL3WINDOW(4);
tmp = inw(ioaddr + WN4_MEDIA);
EL3WINDOW(1);
return tmp & (1<<11);
}
static int
el3_netdev_get_ecmd(struct net_device *dev, struct ethtool_cmd *ecmd)
{
u16 tmp;
int ioaddr = dev->base_addr;
EL3WINDOW(0);
tmp = inw(ioaddr + WN0_ADDR_CONF);
ecmd->transceiver = XCVR_INTERNAL;
switch (tmp >> 14) {
case 0:
ecmd->port = PORT_TP;
break;
case 1:
ecmd->port = PORT_AUI;
ecmd->transceiver = XCVR_EXTERNAL;
break;
case 3:
ecmd->port = PORT_BNC;
default:
break;
}
ecmd->duplex = DUPLEX_HALF;
ecmd->supported = 0;
tmp = inw(ioaddr + WN0_CONF_CTRL);
if (tmp & (1<<13))
ecmd->supported |= SUPPORTED_AUI;
if (tmp & (1<<12))
ecmd->supported |= SUPPORTED_BNC;
if (tmp & (1<<9)) {
ecmd->supported |= SUPPORTED_TP | SUPPORTED_10baseT_Half |
SUPPORTED_10baseT_Full;
EL3WINDOW(4);
tmp = inw(ioaddr + WN4_NETDIAG);
if (tmp & FD_ENABLE)
ecmd->duplex = DUPLEX_FULL;
}
ethtool_cmd_speed_set(ecmd, SPEED_10);
EL3WINDOW(1);
return 0;
}
static int
el3_netdev_set_ecmd(struct net_device *dev, struct ethtool_cmd *ecmd)
{
u16 tmp;
int ioaddr = dev->base_addr;
if (ecmd->speed != SPEED_10)
return -EINVAL;
if ((ecmd->duplex != DUPLEX_HALF) && (ecmd->duplex != DUPLEX_FULL))
return -EINVAL;
if ((ecmd->transceiver != XCVR_INTERNAL) && (ecmd->transceiver != XCVR_EXTERNAL))
return -EINVAL;
EL3WINDOW(0);
tmp = inw(ioaddr + WN0_ADDR_CONF);
switch (ecmd->port) {
case PORT_TP:
tmp &= ~(3<<14);
dev->if_port = 0;
break;
case PORT_AUI:
tmp |= (1<<14);
dev->if_port = 1;
break;
case PORT_BNC:
tmp |= (3<<14);
dev->if_port = 3;
break;
default:
return -EINVAL;
}
outw(tmp, ioaddr + WN0_ADDR_CONF);
if (dev->if_port == 3) {
tmp = inw(ioaddr + WN0_ADDR_CONF);
if (tmp & (3 << 14)) {
outw(StartCoax, ioaddr + EL3_CMD);
udelay(800);
} else
return -EIO;
}
EL3WINDOW(4);
tmp = inw(ioaddr + WN4_NETDIAG);
if (ecmd->duplex == DUPLEX_FULL)
tmp |= FD_ENABLE;
else
tmp &= ~FD_ENABLE;
outw(tmp, ioaddr + WN4_NETDIAG);
EL3WINDOW(1);
return 0;
}
static void el3_get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *info)
{
strcpy(info->driver, DRV_NAME);
strcpy(info->version, DRV_VERSION);
}
static int el3_get_settings(struct net_device *dev, struct ethtool_cmd *ecmd)
{
struct el3_private *lp = netdev_priv(dev);
int ret;
spin_lock_irq(&lp->lock);
ret = el3_netdev_get_ecmd(dev, ecmd);
spin_unlock_irq(&lp->lock);
return ret;
}
static int el3_set_settings(struct net_device *dev, struct ethtool_cmd *ecmd)
{
struct el3_private *lp = netdev_priv(dev);
int ret;
spin_lock_irq(&lp->lock);
ret = el3_netdev_set_ecmd(dev, ecmd);
spin_unlock_irq(&lp->lock);
return ret;
}
static u32 el3_get_link(struct net_device *dev)
{
struct el3_private *lp = netdev_priv(dev);
u32 ret;
spin_lock_irq(&lp->lock);
ret = el3_link_ok(dev);
spin_unlock_irq(&lp->lock);
return ret;
}
static u32 el3_get_msglevel(struct net_device *dev)
{
return el3_debug;
}
static void el3_set_msglevel(struct net_device *dev, u32 v)
{
el3_debug = v;
}
static void
el3_down(struct net_device *dev)
{
int ioaddr = dev->base_addr;
netif_stop_queue(dev);
outw(StatsDisable, ioaddr + EL3_CMD);
outw(RxDisable, ioaddr + EL3_CMD);
outw(TxDisable, ioaddr + EL3_CMD);
if (dev->if_port == 3)
outw(StopCoax, ioaddr + EL3_CMD);
else if (dev->if_port == 0) {
EL3WINDOW(4);
outw(inw(ioaddr + WN4_MEDIA) & ~MEDIA_TP, ioaddr + WN4_MEDIA);
}
outw(SetIntrEnb | 0x0000, ioaddr + EL3_CMD);
update_stats(dev);
}
static void
el3_up(struct net_device *dev)
{
int i, sw_info, net_diag;
int ioaddr = dev->base_addr;
outw(0x0001, ioaddr + 4);
outw((dev->irq << 12) | 0x0f00, ioaddr + WN0_IRQ);
EL3WINDOW(2);
for (i = 0; i < 6; i++)
outb(dev->dev_addr[i], ioaddr + i);
if ((dev->if_port & 0x03) == 3)
outw(StartCoax, ioaddr + EL3_CMD);
else if ((dev->if_port & 0x03) == 0) {
EL3WINDOW(0);
sw_info = (read_eeprom(ioaddr, 0x14) & 0x400f) |
(read_eeprom(ioaddr, 0x0d) & 0xBff0);
EL3WINDOW(4);
net_diag = inw(ioaddr + WN4_NETDIAG);
net_diag = (net_diag | FD_ENABLE);
pr_info("%s: ", dev->name);
switch (dev->if_port & 0x0c) {
case 12:
if (sw_info & 0x000f) {
pr_cont("Forcing 3c5x9b full-duplex mode");
break;
}
case 8:
if ((sw_info & 0x000f) && (sw_info & 0x8000)) {
pr_cont("Setting 3c5x9b full-duplex mode (from EEPROM configuration bit)");
break;
}
default:
pr_cont("Setting 3c5x9/3c5x9B half-duplex mode");
net_diag = (net_diag & ~FD_ENABLE);
}
outw(net_diag, ioaddr + WN4_NETDIAG);
pr_cont(" if_port: %d, sw_info: %4.4x\n", dev->if_port, sw_info);
if (el3_debug > 3)
pr_debug("%s: 3c5x9 net diag word is now: %4.4x.\n", dev->name, net_diag);
outw(inw(ioaddr + WN4_MEDIA) | MEDIA_TP, ioaddr + WN4_MEDIA);
}
outw(StatsDisable, ioaddr + EL3_CMD);
EL3WINDOW(6);
for (i = 0; i < 9; i++)
inb(ioaddr + i);
inw(ioaddr + 10);
inw(ioaddr + 12);
EL3WINDOW(1);
outw(SetRxFilter | RxStation | RxBroadcast, ioaddr + EL3_CMD);
outw(StatsEnable, ioaddr + EL3_CMD);
outw(RxEnable, ioaddr + EL3_CMD);
outw(TxEnable, ioaddr + EL3_CMD);
outw(SetStatusEnb | 0xff, ioaddr + EL3_CMD);
outw(AckIntr | IntLatch | TxAvailable | RxEarly | IntReq,
ioaddr + EL3_CMD);
outw(SetIntrEnb | IntLatch|TxAvailable|TxComplete|RxComplete|StatsFull,
ioaddr + EL3_CMD);
netif_start_queue(dev);
}
static int
el3_suspend(struct device *pdev, pm_message_t state)
{
unsigned long flags;
struct net_device *dev;
struct el3_private *lp;
int ioaddr;
dev = dev_get_drvdata(pdev);
lp = netdev_priv(dev);
ioaddr = dev->base_addr;
spin_lock_irqsave(&lp->lock, flags);
if (netif_running(dev))
netif_device_detach(dev);
el3_down(dev);
outw(PowerDown, ioaddr + EL3_CMD);
spin_unlock_irqrestore(&lp->lock, flags);
return 0;
}
static int
el3_resume(struct device *pdev)
{
unsigned long flags;
struct net_device *dev;
struct el3_private *lp;
int ioaddr;
dev = dev_get_drvdata(pdev);
lp = netdev_priv(dev);
ioaddr = dev->base_addr;
spin_lock_irqsave(&lp->lock, flags);
outw(PowerUp, ioaddr + EL3_CMD);
EL3WINDOW(0);
el3_up(dev);
if (netif_running(dev))
netif_device_attach(dev);
spin_unlock_irqrestore(&lp->lock, flags);
return 0;
}
static int __init el3_init_module(void)
{
int ret = 0;
if (debug >= 0)
el3_debug = debug;
#ifdef CONFIG_PNP
if (!nopnp) {
ret = pnp_register_driver(&el3_pnp_driver);
if (!ret)
pnp_registered = 1;
}
#endif
for (id_port = 0x110 ; id_port < 0x200; id_port += 0x10) {
if (!request_region(id_port, 1, "3c509-control"))
continue;
outb(0x00, id_port);
outb(0xff, id_port);
if (inb(id_port) & 0x01)
break;
else
release_region(id_port, 1);
}
if (id_port >= 0x200) {
id_port = 0;
pr_err("No I/O port available for 3c509 activation.\n");
} else {
ret = isa_register_driver(&el3_isa_driver, EL3_MAX_CARDS);
if (!ret)
isa_registered = 1;
}
#ifdef CONFIG_EISA
ret = eisa_driver_register(&el3_eisa_driver);
if (!ret)
eisa_registered = 1;
#endif
#ifdef CONFIG_MCA
ret = mca_register_driver(&el3_mca_driver);
if (!ret)
mca_registered = 1;
#endif
#ifdef CONFIG_PNP
if (pnp_registered)
ret = 0;
#endif
if (isa_registered)
ret = 0;
#ifdef CONFIG_EISA
if (eisa_registered)
ret = 0;
#endif
#ifdef CONFIG_MCA
if (mca_registered)
ret = 0;
#endif
return ret;
}
static void __exit el3_cleanup_module(void)
{
#ifdef CONFIG_PNP
if (pnp_registered)
pnp_unregister_driver(&el3_pnp_driver);
#endif
if (isa_registered)
isa_unregister_driver(&el3_isa_driver);
if (id_port)
release_region(id_port, 1);
#ifdef CONFIG_EISA
if (eisa_registered)
eisa_driver_unregister(&el3_eisa_driver);
#endif
#ifdef CONFIG_MCA
if (mca_registered)
mca_unregister_driver(&el3_mca_driver);
#endif
}
