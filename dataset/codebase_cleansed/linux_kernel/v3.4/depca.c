static int __devexit depca_isa_remove(struct platform_device *pdev)
{
return depca_device_remove(&pdev->dev);
}
static int __init depca_hw_init (struct net_device *dev, struct device *device)
{
struct depca_private *lp;
int i, j, offset, netRAM, mem_len, status = 0;
s16 nicsr;
u_long ioaddr;
u_long mem_start;
ioaddr = dev->base_addr;
STOP_DEPCA;
nicsr = inb(DEPCA_NICSR);
nicsr = ((nicsr & ~SHE & ~RBE & ~IEN) | IM);
outb(nicsr, DEPCA_NICSR);
if (inw(DEPCA_DATA) != STOP) {
return -ENXIO;
}
lp = netdev_priv(dev);
mem_start = lp->mem_start;
if (!mem_start || lp->adapter < DEPCA || lp->adapter >=unknown)
return -ENXIO;
printk("%s: %s at 0x%04lx",
dev_name(device), depca_signature[lp->adapter], ioaddr);
switch (lp->depca_bus) {
#ifdef CONFIG_MCA
case DEPCA_BUS_MCA:
printk(" (MCA slot %d)", to_mca_device(device)->slot + 1);
break;
#endif
#ifdef CONFIG_EISA
case DEPCA_BUS_EISA:
printk(" (EISA slot %d)", to_eisa_device(device)->slot);
break;
#endif
case DEPCA_BUS_ISA:
break;
default:
printk("Unknown DEPCA bus %d\n", lp->depca_bus);
return -ENXIO;
}
printk(", h/w address ");
status = get_hw_addr(dev);
printk("%pM", dev->dev_addr);
if (status != 0) {
printk(" which has an Ethernet PROM CRC error.\n");
return -ENXIO;
}
netRAM = ((lp->adapter != DEPCA) ? 64 : 48);
if ((nicsr & _128KB) && (lp->adapter == de422))
netRAM = 128;
if (nicsr & BUF) {
nicsr &= ~BS;
netRAM -= 32;
if (lp->depca_bus != DEPCA_BUS_MCA)
mem_start += 0x8000;
}
if ((mem_len = (NUM_RX_DESC * (sizeof(struct depca_rx_desc) + RX_BUFF_SZ) + NUM_TX_DESC * (sizeof(struct depca_tx_desc) + TX_BUFF_SZ) + sizeof(struct depca_init)))
> (netRAM << 10)) {
printk(",\n requests %dkB RAM: only %dkB is available!\n", (mem_len >> 10), netRAM);
return -ENXIO;
}
printk(",\n has %dkB RAM at 0x%.5lx", netRAM, mem_start);
if (lp->adapter != DEPCA) {
nicsr |= SHE;
outb(nicsr, DEPCA_NICSR);
}
spin_lock_init(&lp->lock);
sprintf(lp->adapter_name, "%s (%s)",
depca_signature[lp->adapter], dev_name(device));
status = -EBUSY;
if (!request_mem_region (mem_start, mem_len, lp->adapter_name)) {
printk(KERN_ERR "depca: cannot request ISA memory, aborting\n");
goto out_priv;
}
status = -EIO;
lp->sh_mem = ioremap(mem_start, mem_len);
if (lp->sh_mem == NULL) {
printk(KERN_ERR "depca: cannot remap ISA memory, aborting\n");
goto out1;
}
lp->mem_start = mem_start;
lp->mem_len = mem_len;
lp->device_ram_start = mem_start & LA_MASK;
offset = 0;
offset += sizeof(struct depca_init);
offset = (offset + DEPCA_ALIGN) & ~DEPCA_ALIGN;
lp->rx_ring = lp->sh_mem + offset;
lp->rx_ring_offset = offset;
offset += (sizeof(struct depca_rx_desc) * NUM_RX_DESC);
lp->tx_ring = lp->sh_mem + offset;
lp->tx_ring_offset = offset;
offset += (sizeof(struct depca_tx_desc) * NUM_TX_DESC);
lp->buffs_offset = offset;
lp->rxRingMask = NUM_RX_DESC - 1;
lp->txRingMask = NUM_TX_DESC - 1;
for (i = 0, j = lp->rxRingMask; j > 0; i++) {
j >>= 1;
}
lp->rx_rlen = (s32) (i << 29);
for (i = 0, j = lp->txRingMask; j > 0; i++) {
j >>= 1;
}
lp->tx_rlen = (s32) (i << 29);
depca_init_ring(dev);
LoadCSRs(dev);
nicsr = ((nicsr & ~IM) | IEN);
outb(nicsr, DEPCA_NICSR);
if (dev->irq < 2) {
unsigned char irqnum;
unsigned long irq_mask, delay;
irq_mask = probe_irq_on();
switch (lp->adapter) {
case DEPCA:
case de100:
case de101:
depca_irq = de1xx_irq;
break;
case de200:
case de201:
case de202:
case de210:
case de212:
depca_irq = de2xx_irq;
break;
case de422:
depca_irq = de422_irq;
break;
default:
break;
}
outw(INEA | INIT, DEPCA_DATA);
delay = jiffies + HZ/50;
while (time_before(jiffies, delay))
yield();
irqnum = probe_irq_off(irq_mask);
status = -ENXIO;
if (!irqnum) {
printk(" and failed to detect IRQ line.\n");
goto out2;
} else {
for (dev->irq = 0, i = 0; (depca_irq[i]) && (!dev->irq); i++)
if (irqnum == depca_irq[i]) {
dev->irq = irqnum;
printk(" and uses IRQ%d.\n", dev->irq);
}
if (!dev->irq) {
printk(" but incorrect IRQ line detected.\n");
goto out2;
}
}
} else {
printk(" and assigned IRQ%d.\n", dev->irq);
}
if (depca_debug > 1) {
printk(version);
}
dev->netdev_ops = &depca_netdev_ops;
dev->watchdog_timeo = TX_TIMEOUT;
dev->mem_start = 0;
dev_set_drvdata(device, dev);
SET_NETDEV_DEV (dev, device);
status = register_netdev(dev);
if (status == 0)
return 0;
out2:
iounmap(lp->sh_mem);
out1:
release_mem_region (mem_start, mem_len);
out_priv:
return status;
}
static int depca_open(struct net_device *dev)
{
struct depca_private *lp = netdev_priv(dev);
u_long ioaddr = dev->base_addr;
s16 nicsr;
int status = 0;
STOP_DEPCA;
nicsr = inb(DEPCA_NICSR);
if (lp->adapter != DEPCA) {
nicsr |= SHE;
outb(nicsr, DEPCA_NICSR);
}
depca_init_ring(dev);
LoadCSRs(dev);
depca_dbg_open(dev);
if (request_irq(dev->irq, depca_interrupt, 0, lp->adapter_name, dev)) {
printk("depca_open(): Requested IRQ%d is busy\n", dev->irq);
status = -EAGAIN;
} else {
nicsr = ((nicsr & ~IM & ~LED) | IEN);
outb(nicsr, DEPCA_NICSR);
outw(CSR0, DEPCA_ADDR);
netif_start_queue(dev);
status = InitRestartDepca(dev);
if (depca_debug > 1) {
printk("CSR0: 0x%4.4x\n", inw(DEPCA_DATA));
printk("nicsr: 0x%02x\n", inb(DEPCA_NICSR));
}
}
return status;
}
static void depca_init_ring(struct net_device *dev)
{
struct depca_private *lp = netdev_priv(dev);
u_int i;
u_long offset;
netif_stop_queue(dev);
lp->rx_new = lp->tx_new = 0;
lp->rx_old = lp->tx_old = 0;
for (i = 0; i <= lp->rxRingMask; i++) {
offset = lp->buffs_offset + i * RX_BUFF_SZ;
writel((lp->device_ram_start + offset) | R_OWN, &lp->rx_ring[i].base);
writew(-RX_BUFF_SZ, &lp->rx_ring[i].buf_length);
lp->rx_buff[i] = lp->sh_mem + offset;
}
for (i = 0; i <= lp->txRingMask; i++) {
offset = lp->buffs_offset + (i + lp->rxRingMask + 1) * TX_BUFF_SZ;
writel((lp->device_ram_start + offset) & 0x00ffffff, &lp->tx_ring[i].base);
lp->tx_buff[i] = lp->sh_mem + offset;
}
lp->init_block.rx_ring = (lp->device_ram_start + lp->rx_ring_offset) | lp->rx_rlen;
lp->init_block.tx_ring = (lp->device_ram_start + lp->tx_ring_offset) | lp->tx_rlen;
SetMulticastFilter(dev);
for (i = 0; i < ETH_ALEN; i++) {
lp->init_block.phys_addr[i] = dev->dev_addr[i];
}
lp->init_block.mode = 0x0000;
}
static void depca_tx_timeout(struct net_device *dev)
{
u_long ioaddr = dev->base_addr;
printk("%s: transmit timed out, status %04x, resetting.\n", dev->name, inw(DEPCA_DATA));
STOP_DEPCA;
depca_init_ring(dev);
LoadCSRs(dev);
dev->trans_start = jiffies;
netif_wake_queue(dev);
InitRestartDepca(dev);
}
static netdev_tx_t depca_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct depca_private *lp = netdev_priv(dev);
u_long ioaddr = dev->base_addr;
int status = 0;
if (skb->len < 1)
goto out;
if (skb_padto(skb, ETH_ZLEN))
goto out;
netif_stop_queue(dev);
if (TX_BUFFS_AVAIL) {
status = load_packet(dev, skb);
if (!status) {
outw(CSR0, DEPCA_ADDR);
outw(INEA | TDMD, DEPCA_DATA);
dev_kfree_skb(skb);
}
if (TX_BUFFS_AVAIL)
netif_start_queue(dev);
} else
status = NETDEV_TX_LOCKED;
out:
return status;
}
static irqreturn_t depca_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct depca_private *lp;
s16 csr0, nicsr;
u_long ioaddr;
if (dev == NULL) {
printk("depca_interrupt(): irq %d for unknown device.\n", irq);
return IRQ_NONE;
}
lp = netdev_priv(dev);
ioaddr = dev->base_addr;
spin_lock(&lp->lock);
nicsr = inb(DEPCA_NICSR);
nicsr |= (IM | LED);
outb(nicsr, DEPCA_NICSR);
outw(CSR0, DEPCA_ADDR);
csr0 = inw(DEPCA_DATA);
outw(csr0 & INTE, DEPCA_DATA);
if (csr0 & RINT)
depca_rx(dev);
if (csr0 & TINT)
depca_tx(dev);
if ((TX_BUFFS_AVAIL >= 0) && netif_queue_stopped(dev)) {
netif_wake_queue(dev);
}
nicsr = (nicsr & ~IM & ~LED);
outb(nicsr, DEPCA_NICSR);
spin_unlock(&lp->lock);
return IRQ_HANDLED;
}
static int depca_rx(struct net_device *dev)
{
struct depca_private *lp = netdev_priv(dev);
int i, entry;
s32 status;
for (entry = lp->rx_new; !(readl(&lp->rx_ring[entry].base) & R_OWN); entry = lp->rx_new) {
status = readl(&lp->rx_ring[entry].base) >> 16;
if (status & R_STP) {
lp->rx_old = entry;
}
if (status & R_ENP) {
if (status & R_ERR) {
dev->stats.rx_errors++;
if (status & R_FRAM)
dev->stats.rx_frame_errors++;
if (status & R_OFLO)
dev->stats.rx_over_errors++;
if (status & R_CRC)
dev->stats.rx_crc_errors++;
if (status & R_BUFF)
dev->stats.rx_fifo_errors++;
} else {
short len, pkt_len = readw(&lp->rx_ring[entry].msg_length) - 4;
struct sk_buff *skb;
skb = netdev_alloc_skb(dev, pkt_len + 2);
if (skb != NULL) {
unsigned char *buf;
skb_reserve(skb, 2);
buf = skb_put(skb, pkt_len);
if (entry < lp->rx_old) {
len = (lp->rxRingMask - lp->rx_old + 1) * RX_BUFF_SZ;
memcpy_fromio(buf, lp->rx_buff[lp->rx_old], len);
memcpy_fromio(buf + len, lp->rx_buff[0], pkt_len - len);
} else {
memcpy_fromio(buf, lp->rx_buff[lp->rx_old], pkt_len);
}
skb->protocol = eth_type_trans(skb, dev);
netif_rx(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += pkt_len;
for (i = 1; i < DEPCA_PKT_STAT_SZ - 1; i++) {
if (pkt_len < (i * DEPCA_PKT_BIN_SZ)) {
lp->pktStats.bins[i]++;
i = DEPCA_PKT_STAT_SZ;
}
}
if (is_multicast_ether_addr(buf)) {
if (is_broadcast_ether_addr(buf)) {
lp->pktStats.broadcast++;
} else {
lp->pktStats.multicast++;
}
} else if (compare_ether_addr(buf, dev->dev_addr) == 0) {
lp->pktStats.unicast++;
}
lp->pktStats.bins[0]++;
if (lp->pktStats.bins[0] == 0) {
memset((char *) &lp->pktStats, 0, sizeof(lp->pktStats));
}
} else {
printk("%s: Memory squeeze, deferring packet.\n", dev->name);
dev->stats.rx_dropped++;
break;
}
}
for (; lp->rx_old != entry; lp->rx_old = (lp->rx_old + 1) & lp->rxRingMask) {
writel(readl(&lp->rx_ring[lp->rx_old].base) | R_OWN, &lp->rx_ring[lp->rx_old].base);
}
writel(readl(&lp->rx_ring[entry].base) | R_OWN, &lp->rx_ring[entry].base);
}
lp->rx_new = (lp->rx_new + 1) & lp->rxRingMask;
}
return 0;
}
static int depca_tx(struct net_device *dev)
{
struct depca_private *lp = netdev_priv(dev);
int entry;
s32 status;
u_long ioaddr = dev->base_addr;
for (entry = lp->tx_old; entry != lp->tx_new; entry = lp->tx_old) {
status = readl(&lp->tx_ring[entry].base) >> 16;
if (status < 0) {
break;
} else if (status & T_ERR) {
status = readl(&lp->tx_ring[entry].misc);
dev->stats.tx_errors++;
if (status & TMD3_RTRY)
dev->stats.tx_aborted_errors++;
if (status & TMD3_LCAR)
dev->stats.tx_carrier_errors++;
if (status & TMD3_LCOL)
dev->stats.tx_window_errors++;
if (status & TMD3_UFLO)
dev->stats.tx_fifo_errors++;
if (status & (TMD3_BUFF | TMD3_UFLO)) {
outw(CSR0, DEPCA_ADDR);
outw(INEA | TDMD, DEPCA_DATA);
}
} else if (status & (T_MORE | T_ONE)) {
dev->stats.collisions++;
} else {
dev->stats.tx_packets++;
}
lp->tx_old = (lp->tx_old + 1) & lp->txRingMask;
}
return 0;
}
static int depca_close(struct net_device *dev)
{
struct depca_private *lp = netdev_priv(dev);
s16 nicsr;
u_long ioaddr = dev->base_addr;
netif_stop_queue(dev);
outw(CSR0, DEPCA_ADDR);
if (depca_debug > 1) {
printk("%s: Shutting down ethercard, status was %2.2x.\n", dev->name, inw(DEPCA_DATA));
}
outw(STOP, DEPCA_DATA);
if (lp->adapter != DEPCA) {
nicsr = inb(DEPCA_NICSR);
nicsr &= ~SHE;
outb(nicsr, DEPCA_NICSR);
}
free_irq(dev->irq, dev);
return 0;
}
static void LoadCSRs(struct net_device *dev)
{
struct depca_private *lp = netdev_priv(dev);
u_long ioaddr = dev->base_addr;
outw(CSR1, DEPCA_ADDR);
outw((u16) lp->device_ram_start, DEPCA_DATA);
outw(CSR2, DEPCA_ADDR);
outw((u16) (lp->device_ram_start >> 16), DEPCA_DATA);
outw(CSR3, DEPCA_ADDR);
outw(ACON, DEPCA_DATA);
outw(CSR0, DEPCA_ADDR);
}
static int InitRestartDepca(struct net_device *dev)
{
struct depca_private *lp = netdev_priv(dev);
u_long ioaddr = dev->base_addr;
int i, status = 0;
memcpy_toio(lp->sh_mem, &lp->init_block, sizeof(struct depca_init));
outw(CSR0, DEPCA_ADDR);
outw(INIT, DEPCA_DATA);
for (i = 0; (i < 100) && !(inw(DEPCA_DATA) & IDON); i++);
if (i != 100) {
outw(IDON | INEA | STRT, DEPCA_DATA);
if (depca_debug > 2) {
printk("%s: DEPCA open after %d ticks, init block 0x%08lx csr0 %4.4x.\n", dev->name, i, lp->mem_start, inw(DEPCA_DATA));
}
} else {
printk("%s: DEPCA unopen after %d ticks, init block 0x%08lx csr0 %4.4x.\n", dev->name, i, lp->mem_start, inw(DEPCA_DATA));
status = -1;
}
return status;
}
static void set_multicast_list(struct net_device *dev)
{
struct depca_private *lp = netdev_priv(dev);
u_long ioaddr = dev->base_addr;
netif_stop_queue(dev);
while (lp->tx_old != lp->tx_new);
STOP_DEPCA;
depca_init_ring(dev);
if (dev->flags & IFF_PROMISC) {
lp->init_block.mode |= PROM;
} else {
SetMulticastFilter(dev);
lp->init_block.mode &= ~PROM;
}
LoadCSRs(dev);
InitRestartDepca(dev);
netif_start_queue(dev);
}
static void SetMulticastFilter(struct net_device *dev)
{
struct depca_private *lp = netdev_priv(dev);
struct netdev_hw_addr *ha;
int i, j, bit, byte;
u16 hashcode;
u32 crc;
if (dev->flags & IFF_ALLMULTI) {
for (i = 0; i < (HASH_TABLE_LEN >> 3); i++) {
lp->init_block.mcast_table[i] = (char) 0xff;
}
} else {
for (i = 0; i < (HASH_TABLE_LEN >> 3); i++) {
lp->init_block.mcast_table[i] = 0;
}
netdev_for_each_mc_addr(ha, dev) {
crc = ether_crc(ETH_ALEN, ha->addr);
hashcode = (crc & 1);
for (j = 0; j < 5; j++) {
hashcode = (hashcode << 1) | ((crc >>= 1) & 1);
}
byte = hashcode >> 3;
bit = 1 << (hashcode & 0x07);
lp->init_block.mcast_table[byte] |= bit;
}
}
}
static int __init depca_common_init (u_long ioaddr, struct net_device **devp)
{
int status = 0;
if (!request_region (ioaddr, DEPCA_TOTAL_SIZE, depca_string)) {
status = -EBUSY;
goto out;
}
if (DevicePresent(ioaddr)) {
status = -ENODEV;
goto out_release;
}
if (!(*devp = alloc_etherdev (sizeof (struct depca_private)))) {
status = -ENOMEM;
goto out_release;
}
return 0;
out_release:
release_region (ioaddr, DEPCA_TOTAL_SIZE);
out:
return status;
}
static int __init depca_mca_probe(struct device *device)
{
unsigned char pos[2];
unsigned char where;
unsigned long iobase, mem_start;
int irq, err;
struct mca_device *mdev = to_mca_device (device);
struct net_device *dev;
struct depca_private *lp;
pos[0] = mca_device_read_stored_pos(mdev, 2);
pos[1] = mca_device_read_stored_pos(mdev, 3);
where = (pos[0] & 6) >> 1;
iobase = 0x2c00 + (0x10 * where);
where = pos[1] & 0x0f;
switch (where) {
case 1:
irq = 9;
break;
case 2:
irq = 5;
break;
case 4:
irq = 10;
break;
case 8:
irq = 11;
break;
default:
printk("%s: mca_probe IRQ error. You should never get here (%d).\n", mdev->name, where);
return -EINVAL;
}
where = (pos[0] & 0x18) >> 3;
mem_start = 0xc0000 + (where * 0x10000);
if (pos[0] & 0x20) {
mem_start += 0x8000;
}
strncpy(mdev->name, depca_mca_adapter_name[mdev->index],
sizeof(mdev->name));
mca_device_set_claim(mdev, 1);
irq = mca_device_transform_irq(mdev, irq);
iobase = mca_device_transform_ioport(mdev, iobase);
if ((err = depca_common_init (iobase, &dev)))
goto out_unclaim;
dev->irq = irq;
dev->base_addr = iobase;
lp = netdev_priv(dev);
lp->depca_bus = DEPCA_BUS_MCA;
lp->adapter = depca_mca_adapter_type[mdev->index];
lp->mem_start = mem_start;
if ((err = depca_hw_init(dev, device)))
goto out_free;
return 0;
out_free:
free_netdev (dev);
release_region (iobase, DEPCA_TOTAL_SIZE);
out_unclaim:
mca_device_set_claim(mdev, 0);
return err;
}
static void __init depca_platform_probe (void)
{
int i;
struct platform_device *pldev;
for (i = 0; depca_io_ports[i].iobase; i++) {
depca_io_ports[i].device = NULL;
if (io && io != depca_io_ports[i].iobase)
continue;
pldev = platform_device_alloc(depca_string, i);
if (!pldev)
continue;
pldev->dev.platform_data = (void *) depca_io_ports[i].iobase;
depca_io_ports[i].device = pldev;
if (platform_device_add(pldev)) {
depca_io_ports[i].device = NULL;
pldev->dev.platform_data = NULL;
platform_device_put(pldev);
continue;
}
if (!pldev->dev.driver) {
depca_io_ports[i].device = NULL;
pldev->dev.platform_data = NULL;
platform_device_unregister (pldev);
}
}
}
static enum depca_type __init depca_shmem_probe (ulong *mem_start)
{
u_long mem_base[] = DEPCA_RAM_BASE_ADDRESSES;
enum depca_type adapter = unknown;
int i;
for (i = 0; mem_base[i]; i++) {
*mem_start = mem ? mem : mem_base[i];
adapter = DepcaSignature (adapter_name, *mem_start);
if (adapter != unknown)
break;
}
return adapter;
}
static int __devinit depca_isa_probe (struct platform_device *device)
{
struct net_device *dev;
struct depca_private *lp;
u_long ioaddr, mem_start = 0;
enum depca_type adapter = unknown;
int status = 0;
ioaddr = (u_long) device->dev.platform_data;
if ((status = depca_common_init (ioaddr, &dev)))
goto out;
adapter = depca_shmem_probe (&mem_start);
if (adapter == unknown) {
status = -ENODEV;
goto out_free;
}
dev->base_addr = ioaddr;
dev->irq = irq;
lp = netdev_priv(dev);
lp->depca_bus = DEPCA_BUS_ISA;
lp->adapter = adapter;
lp->mem_start = mem_start;
if ((status = depca_hw_init(dev, &device->dev)))
goto out_free;
return 0;
out_free:
free_netdev (dev);
release_region (ioaddr, DEPCA_TOTAL_SIZE);
out:
return status;
}
static int __init depca_eisa_probe (struct device *device)
{
enum depca_type adapter = unknown;
struct eisa_device *edev;
struct net_device *dev;
struct depca_private *lp;
u_long ioaddr, mem_start;
int status = 0;
edev = to_eisa_device (device);
ioaddr = edev->base_addr + DEPCA_EISA_IO_PORTS;
if ((status = depca_common_init (ioaddr, &dev)))
goto out;
adapter = depca_shmem_probe (&mem_start);
if (adapter == unknown) {
status = -ENODEV;
goto out_free;
}
dev->base_addr = ioaddr;
dev->irq = irq;
lp = netdev_priv(dev);
lp->depca_bus = DEPCA_BUS_EISA;
lp->adapter = edev->id.driver_data;
lp->mem_start = mem_start;
if ((status = depca_hw_init(dev, device)))
goto out_free;
return 0;
out_free:
free_netdev (dev);
release_region (ioaddr, DEPCA_TOTAL_SIZE);
out:
return status;
}
static int __devexit depca_device_remove (struct device *device)
{
struct net_device *dev;
struct depca_private *lp;
int bus;
dev = dev_get_drvdata(device);
lp = netdev_priv(dev);
unregister_netdev (dev);
iounmap (lp->sh_mem);
release_mem_region (lp->mem_start, lp->mem_len);
release_region (dev->base_addr, DEPCA_TOTAL_SIZE);
bus = lp->depca_bus;
free_netdev (dev);
return 0;
}
static int __init DepcaSignature(char *name, u_long base_addr)
{
u_int i, j, k;
void __iomem *ptr;
char tmpstr[16];
u_long prom_addr = base_addr + 0xc000;
u_long mem_addr = base_addr + 0x8000;
if (!request_mem_region (mem_addr, 16, depca_string))
return unknown;
ptr = ioremap(prom_addr, 16);
if (ptr == NULL) {
printk(KERN_ERR "depca: I/O remap failed at %lx\n", prom_addr);
return unknown;
}
for (i = 0; i < 16; i++) {
tmpstr[i] = readb(ptr + i);
}
iounmap(ptr);
release_mem_region (mem_addr, 16);
for (i = 0; *depca_signature[i] != '\0'; i++) {
for (j = 0, k = 0; j < 16 && k < strlen(depca_signature[i]); j++) {
if (depca_signature[i][k] == tmpstr[j]) {
k++;
} else {
k = 0;
}
}
if (k == strlen(depca_signature[i]))
break;
}
if (name && *name && (i == unknown)) {
for (i = 0; *depca_signature[i] != '\0'; i++) {
if (strcmp(name, depca_signature[i]) == 0)
break;
}
}
return i;
}
static int __init DevicePresent(u_long ioaddr)
{
union {
struct {
u32 a;
u32 b;
} llsig;
char Sig[sizeof(u32) << 1];
}
dev;
short sigLength = 0;
s8 data;
s16 nicsr;
int i, j, status = 0;
data = inb(DEPCA_PROM);
data = inb(DEPCA_PROM);
if (data == 0x08) {
nicsr = inb(DEPCA_NICSR);
nicsr |= AAC;
outb(nicsr, DEPCA_NICSR);
}
dev.llsig.a = ETH_PROM_SIG;
dev.llsig.b = ETH_PROM_SIG;
sigLength = sizeof(u32) << 1;
for (i = 0, j = 0; j < sigLength && i < PROBE_LENGTH + sigLength - 1; i++) {
data = inb(DEPCA_PROM);
if (dev.Sig[j] == data) {
j++;
} else {
if (data == dev.Sig[0]) {
j = 1;
} else {
j = 0;
}
}
}
if (j != sigLength) {
status = -ENODEV;
}
return status;
}
static int __init get_hw_addr(struct net_device *dev)
{
u_long ioaddr = dev->base_addr;
struct depca_private *lp = netdev_priv(dev);
int i, k, tmp, status = 0;
u_short j, x, chksum;
x = (((lp->adapter == de100) || (lp->adapter == de101)) ? 1 : 0);
for (i = 0, k = 0, j = 0; j < 3; j++) {
k <<= 1;
if (k > 0xffff)
k -= 0xffff;
k += (u_char) (tmp = inb(DEPCA_PROM + x));
dev->dev_addr[i++] = (u_char) tmp;
k += (u_short) ((tmp = inb(DEPCA_PROM + x)) << 8);
dev->dev_addr[i++] = (u_char) tmp;
if (k > 0xffff)
k -= 0xffff;
}
if (k == 0xffff)
k = 0;
chksum = (u_char) inb(DEPCA_PROM + x);
chksum |= (u_short) (inb(DEPCA_PROM + x) << 8);
if (k != chksum)
status = -1;
return status;
}
static int load_packet(struct net_device *dev, struct sk_buff *skb)
{
struct depca_private *lp = netdev_priv(dev);
int i, entry, end, len, status = NETDEV_TX_OK;
entry = lp->tx_new;
end = (entry + (skb->len - 1) / TX_BUFF_SZ) & lp->txRingMask;
if (!(readl(&lp->tx_ring[end].base) & T_OWN)) {
if (end < entry) {
len = (lp->txRingMask - entry + 1) * TX_BUFF_SZ;
memcpy_toio(lp->tx_buff[entry], skb->data, len);
memcpy_toio(lp->tx_buff[0], skb->data + len, skb->len - len);
} else {
memcpy_toio(lp->tx_buff[entry], skb->data, skb->len);
}
len = (skb->len < ETH_ZLEN) ? ETH_ZLEN : skb->len;
for (i = entry; i != end; i = (i+1) & lp->txRingMask) {
writel(readl(&lp->tx_ring[i].base) & ~T_FLAGS, &lp->tx_ring[i].base);
writew(0x0000, &lp->tx_ring[i].misc);
writew(-TX_BUFF_SZ, &lp->tx_ring[i].length);
len -= TX_BUFF_SZ;
}
writel(readl(&lp->tx_ring[end].base) & ~T_FLAGS, &lp->tx_ring[end].base);
writew(0x0000, &lp->tx_ring[end].misc);
writew(-len, &lp->tx_ring[end].length);
writel(readl(&lp->tx_ring[entry].base) | T_STP, &lp->tx_ring[entry].base);
writel(readl(&lp->tx_ring[end].base) | T_ENP, &lp->tx_ring[end].base);
for (i = end; i != entry; --i) {
writel(readl(&lp->tx_ring[i].base) | T_OWN, &lp->tx_ring[i].base);
if (i == 0)
i = lp->txRingMask + 1;
}
writel(readl(&lp->tx_ring[entry].base) | T_OWN, &lp->tx_ring[entry].base);
lp->tx_new = (++end) & lp->txRingMask;
} else {
status = NETDEV_TX_LOCKED;
}
return status;
}
static void depca_dbg_open(struct net_device *dev)
{
struct depca_private *lp = netdev_priv(dev);
u_long ioaddr = dev->base_addr;
struct depca_init *p = &lp->init_block;
int i;
if (depca_debug > 1) {
printk("%s: depca open with irq %d\n", dev->name, dev->irq);
printk("Descriptor head addresses (CPU):\n");
printk(" 0x%lx 0x%lx\n", (u_long) lp->rx_ring, (u_long) lp->tx_ring);
printk("Descriptor addresses (CPU):\nRX: ");
for (i = 0; i < lp->rxRingMask; i++) {
if (i < 3) {
printk("%p ", &lp->rx_ring[i].base);
}
}
printk("...%p\n", &lp->rx_ring[i].base);
printk("TX: ");
for (i = 0; i < lp->txRingMask; i++) {
if (i < 3) {
printk("%p ", &lp->tx_ring[i].base);
}
}
printk("...%p\n", &lp->tx_ring[i].base);
printk("\nDescriptor buffers (Device):\nRX: ");
for (i = 0; i < lp->rxRingMask; i++) {
if (i < 3) {
printk("0x%8.8x ", readl(&lp->rx_ring[i].base));
}
}
printk("...0x%8.8x\n", readl(&lp->rx_ring[i].base));
printk("TX: ");
for (i = 0; i < lp->txRingMask; i++) {
if (i < 3) {
printk("0x%8.8x ", readl(&lp->tx_ring[i].base));
}
}
printk("...0x%8.8x\n", readl(&lp->tx_ring[i].base));
printk("Initialisation block at 0x%8.8lx(Phys)\n", lp->mem_start);
printk(" mode: 0x%4.4x\n", p->mode);
printk(" physical address: %pM\n", p->phys_addr);
printk(" multicast hash table: ");
for (i = 0; i < (HASH_TABLE_LEN >> 3) - 1; i++) {
printk("%2.2x:", p->mcast_table[i]);
}
printk("%2.2x\n", p->mcast_table[i]);
printk(" rx_ring at: 0x%8.8x\n", p->rx_ring);
printk(" tx_ring at: 0x%8.8x\n", p->tx_ring);
printk("buffers (Phys): 0x%8.8lx\n", lp->mem_start + lp->buffs_offset);
printk("Ring size:\nRX: %d Log2(rxRingMask): 0x%8.8x\n", (int) lp->rxRingMask + 1, lp->rx_rlen);
printk("TX: %d Log2(txRingMask): 0x%8.8x\n", (int) lp->txRingMask + 1, lp->tx_rlen);
outw(CSR2, DEPCA_ADDR);
printk("CSR2&1: 0x%4.4x", inw(DEPCA_DATA));
outw(CSR1, DEPCA_ADDR);
printk("%4.4x\n", inw(DEPCA_DATA));
outw(CSR3, DEPCA_ADDR);
printk("CSR3: 0x%4.4x\n", inw(DEPCA_DATA));
}
}
static int depca_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
struct depca_private *lp = netdev_priv(dev);
struct depca_ioctl *ioc = (struct depca_ioctl *) &rq->ifr_ifru;
int i, status = 0;
u_long ioaddr = dev->base_addr;
union {
u8 addr[(HASH_TABLE_LEN * ETH_ALEN)];
u16 sval[(HASH_TABLE_LEN * ETH_ALEN) >> 1];
u32 lval[(HASH_TABLE_LEN * ETH_ALEN) >> 2];
} tmp;
unsigned long flags;
void *buf;
switch (ioc->cmd) {
case DEPCA_GET_HWADDR:
for (i = 0; i < ETH_ALEN; i++) {
tmp.addr[i] = dev->dev_addr[i];
}
ioc->len = ETH_ALEN;
if (copy_to_user(ioc->data, tmp.addr, ioc->len))
return -EFAULT;
break;
case DEPCA_SET_HWADDR:
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if (copy_from_user(tmp.addr, ioc->data, ETH_ALEN))
return -EFAULT;
for (i = 0; i < ETH_ALEN; i++) {
dev->dev_addr[i] = tmp.addr[i];
}
netif_stop_queue(dev);
while (lp->tx_old != lp->tx_new)
cpu_relax();
STOP_DEPCA;
depca_init_ring(dev);
LoadCSRs(dev);
InitRestartDepca(dev);
netif_start_queue(dev);
break;
case DEPCA_SET_PROM:
if (!capable(CAP_NET_ADMIN))
return -EPERM;
netif_stop_queue(dev);
while (lp->tx_old != lp->tx_new)
cpu_relax();
STOP_DEPCA;
depca_init_ring(dev);
lp->init_block.mode |= PROM;
LoadCSRs(dev);
InitRestartDepca(dev);
netif_start_queue(dev);
break;
case DEPCA_CLR_PROM:
if (!capable(CAP_NET_ADMIN))
return -EPERM;
netif_stop_queue(dev);
while (lp->tx_old != lp->tx_new)
cpu_relax();
STOP_DEPCA;
depca_init_ring(dev);
lp->init_block.mode &= ~PROM;
LoadCSRs(dev);
InitRestartDepca(dev);
netif_start_queue(dev);
break;
case DEPCA_SAY_BOO:
if(!capable(CAP_NET_ADMIN))
return -EPERM;
printk("%s: Boo!\n", dev->name);
break;
case DEPCA_GET_MCA:
ioc->len = (HASH_TABLE_LEN >> 3);
if (copy_to_user(ioc->data, lp->init_block.mcast_table, ioc->len))
return -EFAULT;
break;
case DEPCA_SET_MCA:
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if (ioc->len >= HASH_TABLE_LEN)
return -EINVAL;
if (copy_from_user(tmp.addr, ioc->data, ETH_ALEN * ioc->len))
return -EFAULT;
set_multicast_list(dev);
break;
case DEPCA_CLR_MCA:
if (!capable(CAP_NET_ADMIN))
return -EPERM;
set_multicast_list(dev);
break;
case DEPCA_MCA_EN:
if (!capable(CAP_NET_ADMIN))
return -EPERM;
set_multicast_list(dev);
break;
case DEPCA_GET_STATS:
ioc->len = sizeof(lp->pktStats);
buf = kmalloc(ioc->len, GFP_KERNEL);
if(!buf)
return -ENOMEM;
spin_lock_irqsave(&lp->lock, flags);
memcpy(buf, &lp->pktStats, ioc->len);
spin_unlock_irqrestore(&lp->lock, flags);
if (copy_to_user(ioc->data, buf, ioc->len))
status = -EFAULT;
kfree(buf);
break;
case DEPCA_CLR_STATS:
if (!capable(CAP_NET_ADMIN))
return -EPERM;
spin_lock_irqsave(&lp->lock, flags);
memset(&lp->pktStats, 0, sizeof(lp->pktStats));
spin_unlock_irqrestore(&lp->lock, flags);
break;
case DEPCA_GET_REG:
i = 0;
tmp.sval[i++] = inw(DEPCA_NICSR);
outw(CSR0, DEPCA_ADDR);
tmp.sval[i++] = inw(DEPCA_DATA);
memcpy(&tmp.sval[i], &lp->init_block, sizeof(struct depca_init));
ioc->len = i + sizeof(struct depca_init);
if (copy_to_user(ioc->data, tmp.addr, ioc->len))
return -EFAULT;
break;
default:
return -EOPNOTSUPP;
}
return status;
}
static int __init depca_module_init (void)
{
int err = 0;
#ifdef CONFIG_MCA
err = mca_register_driver(&depca_mca_driver);
if (err)
goto err;
#endif
#ifdef CONFIG_EISA
err = eisa_driver_register(&depca_eisa_driver);
if (err)
goto err_mca;
#endif
err = platform_driver_register(&depca_isa_driver);
if (err)
goto err_eisa;
depca_platform_probe();
return 0;
err_eisa:
#ifdef CONFIG_EISA
eisa_driver_unregister(&depca_eisa_driver);
err_mca:
#endif
#ifdef CONFIG_MCA
mca_unregister_driver(&depca_mca_driver);
err:
#endif
return err;
}
static void __exit depca_module_exit (void)
{
int i;
#ifdef CONFIG_MCA
mca_unregister_driver (&depca_mca_driver);
#endif
#ifdef CONFIG_EISA
eisa_driver_unregister (&depca_eisa_driver);
#endif
platform_driver_unregister (&depca_isa_driver);
for (i = 0; depca_io_ports[i].iobase; i++) {
if (depca_io_ports[i].device) {
depca_io_ports[i].device->dev.platform_data = NULL;
platform_device_unregister (depca_io_ports[i].device);
depca_io_ports[i].device = NULL;
}
}
}
