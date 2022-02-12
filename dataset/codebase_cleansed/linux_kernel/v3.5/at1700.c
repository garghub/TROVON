static void cleanup_card(struct net_device *dev)
{
free_irq(dev->irq, NULL);
release_region(dev->base_addr, AT1700_IO_EXTENT);
}
struct net_device * __init at1700_probe(int unit)
{
struct net_device *dev = alloc_etherdev(sizeof(struct net_local));
unsigned *port;
int err = 0;
if (!dev)
return ERR_PTR(-ENODEV);
if (unit >= 0) {
sprintf(dev->name, "eth%d", unit);
netdev_boot_setup_check(dev);
io = dev->base_addr;
irq = dev->irq;
} else {
dev->base_addr = io;
dev->irq = irq;
}
if (io > 0x1ff) {
err = at1700_probe1(dev, io);
} else if (io != 0) {
err = -ENXIO;
} else {
for (port = at1700_probe_list; *port; port++) {
if (at1700_probe1(dev, *port) == 0)
break;
dev->irq = irq;
}
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
cleanup_card(dev);
out:
free_netdev(dev);
return ERR_PTR(err);
}
static int __init at1700_probe1(struct net_device *dev, int ioaddr)
{
static const char fmv_irqmap[4] = {3, 7, 10, 15};
static const char fmv_irqmap_pnp[8] = {3, 4, 5, 7, 9, 10, 11, 15};
static const char at1700_irqmap[8] = {3, 4, 5, 9, 10, 11, 14, 15};
unsigned int i, irq, is_fmv18x = 0, is_at1700 = 0;
int ret = -ENODEV;
struct net_local *lp = netdev_priv(dev);
if (!request_region(ioaddr, AT1700_IO_EXTENT, DRV_NAME))
return -EBUSY;
#ifdef notdef
printk("at1700 probe at %#x, eeprom is %4.4x %4.4x %4.4x ctrl %4.4x.\n",
ioaddr, read_eeprom(ioaddr, 4), read_eeprom(ioaddr, 5),
read_eeprom(ioaddr, 6), inw(ioaddr + EEPROM_Ctrl));
#endif
if (at1700_probe_list[inb(ioaddr + IOCONFIG1) & 0x07] == ioaddr &&
read_eeprom(ioaddr, 4) == 0x0000 &&
(read_eeprom(ioaddr, 5) & 0xff00) == 0xF400)
is_at1700 = 1;
else if (inb(ioaddr + SAPROM ) == 0x00 &&
inb(ioaddr + SAPROM + 1) == 0x00 &&
inb(ioaddr + SAPROM + 2) == 0x0e)
is_fmv18x = 1;
else {
goto err_out;
}
outb(0, ioaddr + RESET);
if (is_at1700) {
irq = at1700_irqmap[(read_eeprom(ioaddr, 12)&0x04)
| (read_eeprom(ioaddr, 0)>>14)];
} else {
if (inb(ioaddr + CARDSTATUS1) & 0x20) {
irq = dev->irq;
for (i = 0; i < 8; i++) {
if (irq == fmv_irqmap_pnp[i])
break;
}
if (i == 8) {
goto err_out;
}
} else {
if (fmv18x_probe_list[inb(ioaddr + IOCONFIG) & 0x07] != ioaddr)
goto err_out;
irq = fmv_irqmap[(inb(ioaddr + IOCONFIG)>>6) & 0x03];
}
}
printk("%s: %s found at %#3x, IRQ %d, address ", dev->name,
is_at1700 ? "AT1700" : "FMV-18X", ioaddr, irq);
dev->base_addr = ioaddr;
dev->irq = irq;
if (is_at1700) {
for(i = 0; i < 3; i++) {
unsigned short eeprom_val = read_eeprom(ioaddr, 4+i);
((unsigned short *)dev->dev_addr)[i] = ntohs(eeprom_val);
}
} else {
for(i = 0; i < 6; i++) {
unsigned char val = inb(ioaddr + SAPROM + i);
dev->dev_addr[i] = val;
}
}
printk("%pM", dev->dev_addr);
{
const char *porttype[] = {"auto-sense", "10baseT", "auto-sense", "10base2"};
if (is_at1700) {
ushort setup_value = read_eeprom(ioaddr, 12);
dev->if_port = setup_value >> 8;
} else {
ushort setup_value = inb(ioaddr + CARDSTATUS);
switch (setup_value & 0x07) {
case 0x01:
case 0x02:
dev->if_port = 0x18; break;
case 0x04:
dev->if_port = 0x08; break;
default:
dev->if_port = 0x00; break;
}
}
printk(" %s interface.\n", porttype[(dev->if_port>>3) & 3]);
}
outb(0xda, ioaddr + CONFIG_0);
outb(0x00, ioaddr + CONFIG_1);
for (i = 0; i < 6; i++)
outb(dev->dev_addr[i], ioaddr + PORT_OFFSET(8 + i));
outb(0x04, ioaddr + CONFIG_1);
for (i = 0; i < 8; i++)
outb(0x00, ioaddr + PORT_OFFSET(8 + i));
outb(0x08, ioaddr + CONFIG_1);
outb(dev->if_port, ioaddr + MODE13);
outb(0x00, ioaddr + COL16CNTL);
if (net_debug)
printk(version);
dev->netdev_ops = &at1700_netdev_ops;
dev->watchdog_timeo = TX_TIMEOUT;
spin_lock_init(&lp->lock);
lp->jumpered = is_fmv18x;
ret = request_irq(irq, net_interrupt, 0, DRV_NAME, dev);
if (ret) {
printk(KERN_ERR "AT1700 at %#3x is unusable due to a "
"conflict on IRQ %d.\n",
ioaddr, irq);
goto err_out;
}
return 0;
err_out:
release_region(ioaddr, AT1700_IO_EXTENT);
return ret;
}
static int __init read_eeprom(long ioaddr, int location)
{
int i;
unsigned short retval = 0;
long ee_addr = ioaddr + EEPROM_Ctrl;
long ee_daddr = ioaddr + EEPROM_Data;
int read_cmd = location | EE_READ_CMD;
for (i = 9; i >= 0; i--) {
short dataval = (read_cmd & (1 << i)) ? EE_DATA_WRITE : 0;
outb(EE_CS, ee_addr);
outb(dataval, ee_daddr);
outb(EE_CS | EE_SHIFT_CLK, ee_addr);
}
outb(EE_DATA_WRITE, ee_daddr);
for (i = 16; i > 0; i--) {
outb(EE_CS, ee_addr);
outb(EE_CS | EE_SHIFT_CLK, ee_addr);
retval = (retval << 1) | ((inb(ee_daddr) & EE_DATA_READ) ? 1 : 0);
}
outb(EE_CS, ee_addr);
outb(EE_SHIFT_CLK, ee_addr);
outb(0, ee_addr);
return retval;
}
static int net_open(struct net_device *dev)
{
struct net_local *lp = netdev_priv(dev);
int ioaddr = dev->base_addr;
outb(0x5a, ioaddr + CONFIG_0);
outb(0xe8, ioaddr + CONFIG_1);
lp->tx_started = 0;
lp->tx_queue_ready = 1;
lp->rx_started = 0;
lp->tx_queue = 0;
lp->tx_queue_len = 0;
outb(0x82, ioaddr + TX_INTR);
outb(0x81, ioaddr + RX_INTR);
if (lp->jumpered) {
outb(0x80, ioaddr + IOCONFIG1);
}
netif_start_queue(dev);
return 0;
}
static void net_tx_timeout (struct net_device *dev)
{
struct net_local *lp = netdev_priv(dev);
int ioaddr = dev->base_addr;
printk ("%s: transmit timed out with status %04x, %s?\n", dev->name,
inw (ioaddr + STATUS), inb (ioaddr + TX_STATUS) & 0x80
? "IRQ conflict" : "network cable problem");
printk ("%s: timeout registers: %04x %04x %04x %04x %04x %04x %04x %04x.\n",
dev->name, inw(ioaddr + TX_STATUS), inw(ioaddr + TX_INTR), inw(ioaddr + TX_MODE),
inw(ioaddr + CONFIG_0), inw(ioaddr + DATAPORT), inw(ioaddr + TX_START),
inw(ioaddr + MODE13 - 1), inw(ioaddr + RX_CTRL));
dev->stats.tx_errors++;
outw(0xffff, ioaddr + MODE24);
outw (0xffff, ioaddr + TX_STATUS);
outb (0x5a, ioaddr + CONFIG_0);
outb (0xe8, ioaddr + CONFIG_1);
outw (0x8182, ioaddr + TX_INTR);
outb (0x00, ioaddr + TX_START);
outb (0x03, ioaddr + COL16CNTL);
dev->trans_start = jiffies;
lp->tx_started = 0;
lp->tx_queue_ready = 1;
lp->rx_started = 0;
lp->tx_queue = 0;
lp->tx_queue_len = 0;
netif_wake_queue(dev);
}
static netdev_tx_t net_send_packet (struct sk_buff *skb,
struct net_device *dev)
{
struct net_local *lp = netdev_priv(dev);
int ioaddr = dev->base_addr;
short length = ETH_ZLEN < skb->len ? skb->len : ETH_ZLEN;
short len = skb->len;
unsigned char *buf = skb->data;
static u8 pad[ETH_ZLEN];
netif_stop_queue (dev);
lp->tx_queue_ready = 0;
{
outw (length, ioaddr + DATAPORT);
outsw (ioaddr + DATAPORT, buf, len >> 1);
if (len & 1) {
outw(skb->data[skb->len-1], ioaddr + DATAPORT);
len++;
}
if (length != skb->len)
outsw(ioaddr + DATAPORT, pad, (length - len + 1) >> 1);
lp->tx_queue++;
lp->tx_queue_len += length + 2;
}
lp->tx_queue_ready = 1;
if (lp->tx_started == 0) {
outb (0x80 | lp->tx_queue, ioaddr + TX_START);
lp->tx_queue = 0;
lp->tx_queue_len = 0;
lp->tx_started = 1;
netif_start_queue (dev);
} else if (lp->tx_queue_len < 4096 - 1502)
netif_start_queue (dev);
dev_kfree_skb (skb);
return NETDEV_TX_OK;
}
static irqreturn_t net_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct net_local *lp;
int ioaddr, status;
int handled = 0;
if (dev == NULL) {
printk ("at1700_interrupt(): irq %d for unknown device.\n", irq);
return IRQ_NONE;
}
ioaddr = dev->base_addr;
lp = netdev_priv(dev);
spin_lock (&lp->lock);
status = inw(ioaddr + TX_STATUS);
outw(status, ioaddr + TX_STATUS);
if (net_debug > 4)
printk("%s: Interrupt with status %04x.\n", dev->name, status);
if (lp->rx_started == 0 &&
(status & 0xff00 || (inb(ioaddr + RX_MODE) & 0x40) == 0)) {
handled = 1;
lp->rx_started = 1;
outb(0x00, ioaddr + RX_INTR);
net_rx(dev);
outb(0x81, ioaddr + RX_INTR);
lp->rx_started = 0;
}
if (status & 0x00ff) {
handled = 1;
if (status & 0x02) {
if (net_debug > 4)
printk("%s: 16 Collision occur during Txing.\n", dev->name);
outb(0x03, ioaddr + COL16CNTL);
dev->stats.collisions++;
}
if (status & 0x82) {
dev->stats.tx_packets++;
if (lp->tx_queue && lp->tx_queue_ready) {
outb(0x80 | lp->tx_queue, ioaddr + TX_START);
lp->tx_queue = 0;
lp->tx_queue_len = 0;
dev->trans_start = jiffies;
netif_wake_queue (dev);
} else {
lp->tx_started = 0;
netif_wake_queue (dev);
}
}
}
spin_unlock (&lp->lock);
return IRQ_RETVAL(handled);
}
static void
net_rx(struct net_device *dev)
{
int ioaddr = dev->base_addr;
int boguscount = 5;
while ((inb(ioaddr + RX_MODE) & 0x40) == 0) {
ushort status = inw(ioaddr + DATAPORT);
ushort pkt_len = inw(ioaddr + DATAPORT);
if (net_debug > 4)
printk("%s: Rxing packet mode %02x status %04x.\n",
dev->name, inb(ioaddr + RX_MODE), status);
#ifndef final_version
if (status == 0) {
outb(0x05, ioaddr + RX_CTRL);
break;
}
#endif
if ((status & 0xF0) != 0x20) {
dev->stats.rx_errors++;
if (status & 0x08) dev->stats.rx_length_errors++;
if (status & 0x04) dev->stats.rx_frame_errors++;
if (status & 0x02) dev->stats.rx_crc_errors++;
if (status & 0x01) dev->stats.rx_over_errors++;
} else {
struct sk_buff *skb;
if (pkt_len > 1550) {
printk("%s: The AT1700 claimed a very large packet, size %d.\n",
dev->name, pkt_len);
inw(ioaddr + DATAPORT); inw(ioaddr + DATAPORT);
outb(0x05, ioaddr + RX_CTRL);
dev->stats.rx_errors++;
break;
}
skb = netdev_alloc_skb(dev, pkt_len + 3);
if (skb == NULL) {
printk("%s: Memory squeeze, dropping packet (len %d).\n",
dev->name, pkt_len);
inw(ioaddr + DATAPORT); inw(ioaddr + DATAPORT);
outb(0x05, ioaddr + RX_CTRL);
dev->stats.rx_dropped++;
break;
}
skb_reserve(skb,2);
insw(ioaddr + DATAPORT, skb_put(skb,pkt_len), (pkt_len + 1) >> 1);
skb->protocol=eth_type_trans(skb, dev);
netif_rx(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += pkt_len;
}
if (--boguscount <= 0)
break;
}
{
int i;
for (i = 0; i < 20; i++) {
if ((inb(ioaddr + RX_MODE) & 0x40) == 0x40)
break;
inw(ioaddr + DATAPORT);
outb(0x05, ioaddr + RX_CTRL);
}
if (net_debug > 5)
printk("%s: Exint Rx packet with mode %02x after %d ticks.\n",
dev->name, inb(ioaddr + RX_MODE), i);
}
}
static int net_close(struct net_device *dev)
{
struct net_local *lp = netdev_priv(dev);
int ioaddr = dev->base_addr;
netif_stop_queue(dev);
outb(0xda, ioaddr + CONFIG_0);
if (lp->jumpered)
outb(0x00, ioaddr + IOCONFIG1);
outb(0x00, ioaddr + CONFIG_1);
return 0;
}
static void
set_rx_mode(struct net_device *dev)
{
int ioaddr = dev->base_addr;
struct net_local *lp = netdev_priv(dev);
unsigned char mc_filter[8];
unsigned long flags;
if (dev->flags & IFF_PROMISC) {
memset(mc_filter, 0xff, sizeof(mc_filter));
outb(3, ioaddr + RX_MODE);
} else if (netdev_mc_count(dev) > MC_FILTERBREAK ||
(dev->flags & IFF_ALLMULTI)) {
memset(mc_filter, 0xff, sizeof(mc_filter));
outb(2, ioaddr + RX_MODE);
} else if (netdev_mc_empty(dev)) {
memset(mc_filter, 0x00, sizeof(mc_filter));
outb(1, ioaddr + RX_MODE);
} else {
struct netdev_hw_addr *ha;
memset(mc_filter, 0, sizeof(mc_filter));
netdev_for_each_mc_addr(ha, dev) {
unsigned int bit =
ether_crc_le(ETH_ALEN, ha->addr) >> 26;
mc_filter[bit >> 3] |= (1 << bit);
}
outb(0x02, ioaddr + RX_MODE);
}
spin_lock_irqsave (&lp->lock, flags);
if (memcmp(mc_filter, lp->mc_filter, sizeof(mc_filter))) {
int i;
int saved_bank = inw(ioaddr + CONFIG_0);
outw((saved_bank & ~0x0C00) | 0x0480, ioaddr + CONFIG_0);
for (i = 0; i < 8; i++)
outb(mc_filter[i], ioaddr + PORT_OFFSET(8 + i));
memcpy(lp->mc_filter, mc_filter, sizeof(mc_filter));
outw(saved_bank, ioaddr + CONFIG_0);
}
spin_unlock_irqrestore (&lp->lock, flags);
}
static int __init at1700_module_init(void)
{
if (io == 0)
printk("at1700: You should not use auto-probing with insmod!\n");
dev_at1700 = at1700_probe(-1);
if (IS_ERR(dev_at1700))
return PTR_ERR(dev_at1700);
return 0;
}
static void __exit at1700_module_exit(void)
{
unregister_netdev(dev_at1700);
cleanup_card(dev_at1700);
free_netdev(dev_at1700);
}
