static int tc574_probe(struct pcmcia_device *link)
{
struct el3_private *lp;
struct net_device *dev;
dev_dbg(&link->dev, "3c574_attach()\n");
dev = alloc_etherdev(sizeof(struct el3_private));
if (!dev)
return -ENOMEM;
lp = netdev_priv(dev);
link->priv = dev;
lp->p_dev = link;
spin_lock_init(&lp->window_lock);
link->resource[0]->end = 32;
link->resource[0]->flags |= IO_DATA_PATH_WIDTH_16;
link->config_flags |= CONF_ENABLE_IRQ;
link->config_index = 1;
dev->netdev_ops = &el3_netdev_ops;
dev->watchdog_timeo = TX_TIMEOUT;
return tc574_config(link);
}
static void tc574_detach(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
dev_dbg(&link->dev, "3c574_detach()\n");
unregister_netdev(dev);
tc574_release(link);
free_netdev(dev);
}
static int tc574_config(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
struct el3_private *lp = netdev_priv(dev);
int ret, i, j;
unsigned int ioaddr;
__be16 *phys_addr;
char *cardname;
__u32 config;
u8 *buf;
size_t len;
phys_addr = (__be16 *)dev->dev_addr;
dev_dbg(&link->dev, "3c574_config()\n");
link->io_lines = 16;
for (i = j = 0; j < 0x400; j += 0x20) {
link->resource[0]->start = j ^ 0x300;
i = pcmcia_request_io(link);
if (i == 0)
break;
}
if (i != 0)
goto failed;
ret = pcmcia_request_irq(link, el3_interrupt);
if (ret)
goto failed;
ret = pcmcia_enable_device(link);
if (ret)
goto failed;
dev->irq = link->irq;
dev->base_addr = link->resource[0]->start;
ioaddr = dev->base_addr;
len = pcmcia_get_tuple(link, 0x88, &buf);
if (buf && len >= 6) {
for (i = 0; i < 3; i++)
phys_addr[i] = htons(le16_to_cpu(buf[i * 2]));
kfree(buf);
} else {
kfree(buf);
EL3WINDOW(0);
for (i = 0; i < 3; i++)
phys_addr[i] = htons(read_eeprom(ioaddr, i + 10));
if (phys_addr[0] == htons(0x6060)) {
pr_notice("IO port conflict at 0x%03lx-0x%03lx\n",
dev->base_addr, dev->base_addr+15);
goto failed;
}
}
if (link->prod_id[1])
cardname = link->prod_id[1];
else
cardname = "3Com 3c574";
{
u_char mcr;
outw(2<<11, ioaddr + RunnerRdCtrl);
mcr = inb(ioaddr + 2);
outw(0<<11, ioaddr + RunnerRdCtrl);
pr_info(" ASIC rev %d,", mcr>>3);
EL3WINDOW(3);
config = inl(ioaddr + Wn3_Config);
lp->default_media = (config & Xcvr) >> Xcvr_shift;
lp->autoselect = config & Autoselect ? 1 : 0;
}
init_timer(&lp->media);
{
int phy;
outw(0x8040, ioaddr + Wn3_Options);
mdelay(1);
outw(0xc040, ioaddr + Wn3_Options);
tc574_wait_for_completion(dev, TxReset);
tc574_wait_for_completion(dev, RxReset);
mdelay(1);
outw(0x8040, ioaddr + Wn3_Options);
EL3WINDOW(4);
for (phy = 1; phy <= 32; phy++) {
int mii_status;
mdio_sync(ioaddr, 32);
mii_status = mdio_read(ioaddr, phy & 0x1f, 1);
if (mii_status != 0xffff) {
lp->phys = phy & 0x1f;
dev_dbg(&link->dev, " MII transceiver at "
"index %d, status %x.\n",
phy, mii_status);
if ((mii_status & 0x0040) == 0)
mii_preamble_required = 1;
break;
}
}
if (phy > 32) {
pr_notice(" No MII transceivers found!\n");
goto failed;
}
i = mdio_read(ioaddr, lp->phys, 16) | 0x40;
mdio_write(ioaddr, lp->phys, 16, i);
lp->advertising = mdio_read(ioaddr, lp->phys, 4);
if (full_duplex) {
lp->advertising &= ~0x02a0;
mdio_write(ioaddr, lp->phys, 4, lp->advertising);
}
}
SET_NETDEV_DEV(dev, &link->dev);
if (register_netdev(dev) != 0) {
pr_notice("register_netdev() failed\n");
goto failed;
}
netdev_info(dev, "%s at io %#3lx, irq %d, hw_addr %pM\n",
cardname, dev->base_addr, dev->irq, dev->dev_addr);
netdev_info(dev, " %dK FIFO split %s Rx:Tx, %sMII interface.\n",
8 << (config & Ram_size),
ram_split[(config & Ram_split) >> Ram_split_shift],
config & Autoselect ? "autoselect " : "");
return 0;
failed:
tc574_release(link);
return -ENODEV;
}
static void tc574_release(struct pcmcia_device *link)
{
pcmcia_disable_device(link);
}
static int tc574_suspend(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
if (link->open)
netif_device_detach(dev);
return 0;
}
static int tc574_resume(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
if (link->open) {
tc574_reset(dev);
netif_device_attach(dev);
}
return 0;
}
static void dump_status(struct net_device *dev)
{
unsigned int ioaddr = dev->base_addr;
EL3WINDOW(1);
netdev_info(dev, " irq status %04x, rx status %04x, tx status %02x, tx free %04x\n",
inw(ioaddr+EL3_STATUS),
inw(ioaddr+RxStatus), inb(ioaddr+TxStatus),
inw(ioaddr+TxFree));
EL3WINDOW(4);
netdev_info(dev, " diagnostics: fifo %04x net %04x ethernet %04x media %04x\n",
inw(ioaddr+0x04), inw(ioaddr+0x06),
inw(ioaddr+0x08), inw(ioaddr+0x0a));
EL3WINDOW(1);
}
static void tc574_wait_for_completion(struct net_device *dev, int cmd)
{
int i = 1500;
outw(cmd, dev->base_addr + EL3_CMD);
while (--i > 0)
if (!(inw(dev->base_addr + EL3_STATUS) & 0x1000)) break;
if (i == 0)
netdev_notice(dev, "command 0x%04x did not complete!\n", cmd);
}
static unsigned short read_eeprom(unsigned int ioaddr, int index)
{
int timer;
outw(EEPROM_Read + index, ioaddr + Wn0EepromCmd);
for (timer = 1620; timer >= 0; timer--) {
if ((inw(ioaddr + Wn0EepromCmd) & 0x8000) == 0)
break;
}
return inw(ioaddr + Wn0EepromData);
}
static void mdio_sync(unsigned int ioaddr, int bits)
{
unsigned int mdio_addr = ioaddr + Wn4_PhysicalMgmt;
while (-- bits >= 0) {
outw(MDIO_DATA_WRITE1, mdio_addr);
outw(MDIO_DATA_WRITE1 | MDIO_SHIFT_CLK, mdio_addr);
}
}
static int mdio_read(unsigned int ioaddr, int phy_id, int location)
{
int i;
int read_cmd = (0xf6 << 10) | (phy_id << 5) | location;
unsigned int retval = 0;
unsigned int mdio_addr = ioaddr + Wn4_PhysicalMgmt;
if (mii_preamble_required)
mdio_sync(ioaddr, 32);
for (i = 14; i >= 0; i--) {
int dataval = (read_cmd&(1<<i)) ? MDIO_DATA_WRITE1 : MDIO_DATA_WRITE0;
outw(dataval, mdio_addr);
outw(dataval | MDIO_SHIFT_CLK, mdio_addr);
}
for (i = 19; i > 0; i--) {
outw(MDIO_ENB_IN, mdio_addr);
retval = (retval << 1) | ((inw(mdio_addr) & MDIO_DATA_READ) ? 1 : 0);
outw(MDIO_ENB_IN | MDIO_SHIFT_CLK, mdio_addr);
}
return (retval>>1) & 0xffff;
}
static void mdio_write(unsigned int ioaddr, int phy_id, int location, int value)
{
int write_cmd = 0x50020000 | (phy_id << 23) | (location << 18) | value;
unsigned int mdio_addr = ioaddr + Wn4_PhysicalMgmt;
int i;
if (mii_preamble_required)
mdio_sync(ioaddr, 32);
for (i = 31; i >= 0; i--) {
int dataval = (write_cmd&(1<<i)) ? MDIO_DATA_WRITE1 : MDIO_DATA_WRITE0;
outw(dataval, mdio_addr);
outw(dataval | MDIO_SHIFT_CLK, mdio_addr);
}
for (i = 1; i >= 0; i--) {
outw(MDIO_ENB_IN, mdio_addr);
outw(MDIO_ENB_IN | MDIO_SHIFT_CLK, mdio_addr);
}
}
static void tc574_reset(struct net_device *dev)
{
struct el3_private *lp = netdev_priv(dev);
int i;
unsigned int ioaddr = dev->base_addr;
unsigned long flags;
tc574_wait_for_completion(dev, TotalReset|0x10);
spin_lock_irqsave(&lp->window_lock, flags);
outw(0, ioaddr + RunnerWrCtrl);
outw(0, ioaddr + RunnerRdCtrl);
EL3WINDOW(2);
for (i = 0; i < 6; i++)
outb(dev->dev_addr[i], ioaddr + i);
for (; i < 12; i+=2)
outw(0, ioaddr + i);
EL3WINDOW(3);
outb((dev->mtu > 1500 ? 0x40 : 0), ioaddr + Wn3_MAC_Ctrl);
outl((lp->autoselect ? 0x01000000 : 0) | 0x0062001b,
ioaddr + Wn3_Config);
outw(0x8040, ioaddr + Wn3_Options);
mdelay(1);
outw(0xc040, ioaddr + Wn3_Options);
EL3WINDOW(1);
spin_unlock_irqrestore(&lp->window_lock, flags);
tc574_wait_for_completion(dev, TxReset);
tc574_wait_for_completion(dev, RxReset);
mdelay(1);
spin_lock_irqsave(&lp->window_lock, flags);
EL3WINDOW(3);
outw(0x8040, ioaddr + Wn3_Options);
outw(StatsDisable, ioaddr + EL3_CMD);
EL3WINDOW(6);
for (i = 0; i < 10; i++)
inb(ioaddr + i);
inw(ioaddr + 10);
inw(ioaddr + 12);
EL3WINDOW(4);
inb(ioaddr + 12);
inb(ioaddr + 13);
outw(0x0040, ioaddr + Wn4_NetDiag);
EL3WINDOW(1);
spin_unlock_irqrestore(&lp->window_lock, flags);
mdio_sync(ioaddr, 32);
mdio_write(ioaddr, lp->phys, 4, lp->advertising);
if (!auto_polarity) {
i = mdio_read(ioaddr, lp->phys, 16) | 0x20;
mdio_write(ioaddr, lp->phys, 16, i);
}
spin_lock_irqsave(&lp->window_lock, flags);
set_rx_mode(dev);
spin_unlock_irqrestore(&lp->window_lock, flags);
outw(StatsEnable, ioaddr + EL3_CMD);
outw(RxEnable, ioaddr + EL3_CMD);
outw(TxEnable, ioaddr + EL3_CMD);
outw(SetStatusEnb | 0xff, ioaddr + EL3_CMD);
outw(AckIntr | IntLatch | TxAvailable | RxEarly | IntReq,
ioaddr + EL3_CMD);
outw(SetIntrEnb | IntLatch | TxAvailable | RxComplete | StatsFull
| AdapterFailure | RxEarly, ioaddr + EL3_CMD);
}
static int el3_open(struct net_device *dev)
{
struct el3_private *lp = netdev_priv(dev);
struct pcmcia_device *link = lp->p_dev;
if (!pcmcia_dev_present(link))
return -ENODEV;
link->open++;
netif_start_queue(dev);
tc574_reset(dev);
lp->media.function = media_check;
lp->media.data = (unsigned long) dev;
lp->media.expires = jiffies + HZ;
add_timer(&lp->media);
dev_dbg(&link->dev, "%s: opened, status %4.4x.\n",
dev->name, inw(dev->base_addr + EL3_STATUS));
return 0;
}
static void el3_tx_timeout(struct net_device *dev)
{
unsigned int ioaddr = dev->base_addr;
netdev_notice(dev, "Transmit timed out!\n");
dump_status(dev);
dev->stats.tx_errors++;
dev->trans_start = jiffies;
tc574_wait_for_completion(dev, TxReset);
outw(TxEnable, ioaddr + EL3_CMD);
netif_wake_queue(dev);
}
static void pop_tx_status(struct net_device *dev)
{
unsigned int ioaddr = dev->base_addr;
int i;
for (i = 32; i > 0; i--) {
u_char tx_status = inb(ioaddr + TxStatus);
if (!(tx_status & 0x84))
break;
if (tx_status & 0x30)
tc574_wait_for_completion(dev, TxReset);
if (tx_status & 0x38) {
pr_debug("%s: transmit error: status 0x%02x\n",
dev->name, tx_status);
outw(TxEnable, ioaddr + EL3_CMD);
dev->stats.tx_aborted_errors++;
}
outb(0x00, ioaddr + TxStatus);
}
}
static netdev_tx_t el3_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
unsigned int ioaddr = dev->base_addr;
struct el3_private *lp = netdev_priv(dev);
unsigned long flags;
pr_debug("%s: el3_start_xmit(length = %ld) called, "
"status %4.4x.\n", dev->name, (long)skb->len,
inw(ioaddr + EL3_STATUS));
spin_lock_irqsave(&lp->window_lock, flags);
dev->stats.tx_bytes += skb->len;
outw(skb->len, ioaddr + TX_FIFO);
outw(0, ioaddr + TX_FIFO);
outsl(ioaddr + TX_FIFO, skb->data, (skb->len+3)>>2);
if (inw(ioaddr + TxFree) <= 1536) {
netif_stop_queue(dev);
outw(SetTxThreshold + (1536>>2), ioaddr + EL3_CMD);
}
pop_tx_status(dev);
spin_unlock_irqrestore(&lp->window_lock, flags);
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static irqreturn_t el3_interrupt(int irq, void *dev_id)
{
struct net_device *dev = (struct net_device *) dev_id;
struct el3_private *lp = netdev_priv(dev);
unsigned int ioaddr;
unsigned status;
int work_budget = max_interrupt_work;
int handled = 0;
if (!netif_device_present(dev))
return IRQ_NONE;
ioaddr = dev->base_addr;
pr_debug("%s: interrupt, status %4.4x.\n",
dev->name, inw(ioaddr + EL3_STATUS));
spin_lock(&lp->window_lock);
while ((status = inw(ioaddr + EL3_STATUS)) &
(IntLatch | RxComplete | RxEarly | StatsFull)) {
if (!netif_device_present(dev) ||
((status & 0xe000) != 0x2000)) {
pr_debug("%s: Interrupt from dead card\n", dev->name);
break;
}
handled = 1;
if (status & RxComplete)
work_budget = el3_rx(dev, work_budget);
if (status & TxAvailable) {
pr_debug(" TX room bit was handled.\n");
outw(AckIntr | TxAvailable, ioaddr + EL3_CMD);
netif_wake_queue(dev);
}
if (status & TxComplete)
pop_tx_status(dev);
if (status & (AdapterFailure | RxEarly | StatsFull)) {
if (status & StatsFull)
update_stats(dev);
if (status & RxEarly) {
work_budget = el3_rx(dev, work_budget);
outw(AckIntr | RxEarly, ioaddr + EL3_CMD);
}
if (status & AdapterFailure) {
u16 fifo_diag;
EL3WINDOW(4);
fifo_diag = inw(ioaddr + Wn4_FIFODiag);
EL3WINDOW(1);
netdev_notice(dev, "adapter failure, FIFO diagnostic register %04x\n",
fifo_diag);
if (fifo_diag & 0x0400) {
tc574_wait_for_completion(dev, TxReset);
outw(TxEnable, ioaddr + EL3_CMD);
}
if (fifo_diag & 0x2000) {
tc574_wait_for_completion(dev, RxReset);
set_rx_mode(dev);
outw(RxEnable, ioaddr + EL3_CMD);
}
outw(AckIntr | AdapterFailure, ioaddr + EL3_CMD);
}
}
if (--work_budget < 0) {
pr_debug("%s: Too much work in interrupt, "
"status %4.4x.\n", dev->name, status);
outw(AckIntr | 0xFF, ioaddr + EL3_CMD);
break;
}
outw(AckIntr | IntReq | IntLatch, ioaddr + EL3_CMD);
}
pr_debug("%s: exiting interrupt, status %4.4x.\n",
dev->name, inw(ioaddr + EL3_STATUS));
spin_unlock(&lp->window_lock);
return IRQ_RETVAL(handled);
}
static void media_check(unsigned long arg)
{
struct net_device *dev = (struct net_device *) arg;
struct el3_private *lp = netdev_priv(dev);
unsigned int ioaddr = dev->base_addr;
unsigned long flags;
unsigned short media, partner;
if (!netif_device_present(dev))
goto reschedule;
if ((inw(ioaddr + EL3_STATUS) & IntLatch) && (inb(ioaddr + Timer) == 0xff)) {
if (!lp->fast_poll)
netdev_info(dev, "interrupt(s) dropped!\n");
local_irq_save(flags);
el3_interrupt(dev->irq, dev);
local_irq_restore(flags);
lp->fast_poll = HZ;
}
if (lp->fast_poll) {
lp->fast_poll--;
lp->media.expires = jiffies + 2*HZ/100;
add_timer(&lp->media);
return;
}
spin_lock_irqsave(&lp->window_lock, flags);
EL3WINDOW(4);
media = mdio_read(ioaddr, lp->phys, 1);
partner = mdio_read(ioaddr, lp->phys, 5);
EL3WINDOW(1);
if (media != lp->media_status) {
if ((media ^ lp->media_status) & 0x0004)
netdev_info(dev, "%s link beat\n",
(lp->media_status & 0x0004) ? "lost" : "found");
if ((media ^ lp->media_status) & 0x0020) {
lp->partner = 0;
if (lp->media_status & 0x0020) {
netdev_info(dev, "autonegotiation restarted\n");
} else if (partner) {
partner &= lp->advertising;
lp->partner = partner;
netdev_info(dev, "autonegotiation complete: "
"%dbaseT-%cD selected\n",
(partner & 0x0180) ? 100 : 10,
(partner & 0x0140) ? 'F' : 'H');
} else {
netdev_info(dev, "link partner did not autonegotiate\n");
}
EL3WINDOW(3);
outb((partner & 0x0140 ? 0x20 : 0) |
(dev->mtu > 1500 ? 0x40 : 0), ioaddr + Wn3_MAC_Ctrl);
EL3WINDOW(1);
}
if (media & 0x0010)
netdev_info(dev, "remote fault detected\n");
if (media & 0x0002)
netdev_info(dev, "jabber detected\n");
lp->media_status = media;
}
spin_unlock_irqrestore(&lp->window_lock, flags);
reschedule:
lp->media.expires = jiffies + HZ;
add_timer(&lp->media);
}
static struct net_device_stats *el3_get_stats(struct net_device *dev)
{
struct el3_private *lp = netdev_priv(dev);
if (netif_device_present(dev)) {
unsigned long flags;
spin_lock_irqsave(&lp->window_lock, flags);
update_stats(dev);
spin_unlock_irqrestore(&lp->window_lock, flags);
}
return &dev->stats;
}
static void update_stats(struct net_device *dev)
{
unsigned int ioaddr = dev->base_addr;
u8 rx, tx, up;
pr_debug("%s: updating the statistics.\n", dev->name);
if (inw(ioaddr+EL3_STATUS) == 0xffff)
return;
EL3WINDOW(6);
dev->stats.tx_carrier_errors += inb(ioaddr + 0);
dev->stats.tx_heartbeat_errors += inb(ioaddr + 1);
inb(ioaddr + 2);
dev->stats.collisions += inb(ioaddr + 3);
dev->stats.tx_window_errors += inb(ioaddr + 4);
dev->stats.rx_fifo_errors += inb(ioaddr + 5);
dev->stats.tx_packets += inb(ioaddr + 6);
up = inb(ioaddr + 9);
dev->stats.tx_packets += (up&0x30) << 4;
inb(ioaddr + 7);
inb(ioaddr + 8);
rx = inw(ioaddr + 10);
tx = inw(ioaddr + 12);
EL3WINDOW(4);
inb(ioaddr + 12);
up = inb(ioaddr + 13);
EL3WINDOW(1);
}
static int el3_rx(struct net_device *dev, int worklimit)
{
unsigned int ioaddr = dev->base_addr;
short rx_status;
pr_debug("%s: in rx_packet(), status %4.4x, rx_status %4.4x.\n",
dev->name, inw(ioaddr+EL3_STATUS), inw(ioaddr+RxStatus));
while (!((rx_status = inw(ioaddr + RxStatus)) & 0x8000) &&
worklimit > 0) {
worklimit--;
if (rx_status & 0x4000) {
short error = rx_status & 0x3800;
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
pr_debug(" Receiving packet size %d status %4.4x.\n",
pkt_len, rx_status);
if (skb != NULL) {
skb_reserve(skb, 2);
insl(ioaddr+RX_FIFO, skb_put(skb, pkt_len),
((pkt_len+3)>>2));
skb->protocol = eth_type_trans(skb, dev);
netif_rx(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += pkt_len;
} else {
pr_debug("%s: couldn't allocate a sk_buff of"
" size %d.\n", dev->name, pkt_len);
dev->stats.rx_dropped++;
}
}
tc574_wait_for_completion(dev, RxDiscard);
}
return worklimit;
}
static int el3_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
struct el3_private *lp = netdev_priv(dev);
unsigned int ioaddr = dev->base_addr;
struct mii_ioctl_data *data = if_mii(rq);
int phy = lp->phys & 0x1f;
pr_debug("%s: In ioct(%-.6s, %#4.4x) %4.4x %4.4x %4.4x %4.4x.\n",
dev->name, rq->ifr_ifrn.ifrn_name, cmd,
data->phy_id, data->reg_num, data->val_in, data->val_out);
switch(cmd) {
case SIOCGMIIPHY:
data->phy_id = phy;
case SIOCGMIIREG:
{
int saved_window;
unsigned long flags;
spin_lock_irqsave(&lp->window_lock, flags);
saved_window = inw(ioaddr + EL3_CMD) >> 13;
EL3WINDOW(4);
data->val_out = mdio_read(ioaddr, data->phy_id & 0x1f,
data->reg_num & 0x1f);
EL3WINDOW(saved_window);
spin_unlock_irqrestore(&lp->window_lock, flags);
return 0;
}
case SIOCSMIIREG:
{
int saved_window;
unsigned long flags;
spin_lock_irqsave(&lp->window_lock, flags);
saved_window = inw(ioaddr + EL3_CMD) >> 13;
EL3WINDOW(4);
mdio_write(ioaddr, data->phy_id & 0x1f,
data->reg_num & 0x1f, data->val_in);
EL3WINDOW(saved_window);
spin_unlock_irqrestore(&lp->window_lock, flags);
return 0;
}
default:
return -EOPNOTSUPP;
}
}
static void set_rx_mode(struct net_device *dev)
{
unsigned int ioaddr = dev->base_addr;
if (dev->flags & IFF_PROMISC)
outw(SetRxFilter | RxStation | RxMulticast | RxBroadcast | RxProm,
ioaddr + EL3_CMD);
else if (!netdev_mc_empty(dev) || (dev->flags & IFF_ALLMULTI))
outw(SetRxFilter|RxStation|RxMulticast|RxBroadcast, ioaddr + EL3_CMD);
else
outw(SetRxFilter | RxStation | RxBroadcast, ioaddr + EL3_CMD);
}
static void set_multicast_list(struct net_device *dev)
{
struct el3_private *lp = netdev_priv(dev);
unsigned long flags;
spin_lock_irqsave(&lp->window_lock, flags);
set_rx_mode(dev);
spin_unlock_irqrestore(&lp->window_lock, flags);
}
static int el3_close(struct net_device *dev)
{
unsigned int ioaddr = dev->base_addr;
struct el3_private *lp = netdev_priv(dev);
struct pcmcia_device *link = lp->p_dev;
dev_dbg(&link->dev, "%s: shutting down ethercard.\n", dev->name);
if (pcmcia_dev_present(link)) {
unsigned long flags;
outw(StatsDisable, ioaddr + EL3_CMD);
outw(RxDisable, ioaddr + EL3_CMD);
outw(TxDisable, ioaddr + EL3_CMD);
EL3WINDOW(0);
spin_lock_irqsave(&lp->window_lock, flags);
update_stats(dev);
spin_unlock_irqrestore(&lp->window_lock, flags);
outw(SetIntrEnb | 0x0000, ioaddr + EL3_CMD);
}
link->open--;
netif_stop_queue(dev);
del_timer_sync(&lp->media);
return 0;
}
static int __init init_tc574(void)
{
return pcmcia_register_driver(&tc574_driver);
}
static void __exit exit_tc574(void)
{
pcmcia_unregister_driver(&tc574_driver);
}
