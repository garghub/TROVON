static void memcpyw(volatile u_short *dest, u_short *src, int len)
{
while (len >= 2) {
*(dest++) = *(src++);
len -= 2;
}
if (len == 1)
*dest = (*(u_char *)src) << 8;
}
static void ariadne_init_ring(struct net_device *dev)
{
struct ariadne_private *priv = netdev_priv(dev);
volatile struct lancedata *lancedata = (struct lancedata *)dev->mem_start;
int i;
netif_stop_queue(dev);
priv->tx_full = 0;
priv->cur_rx = priv->cur_tx = 0;
priv->dirty_tx = 0;
for (i = 0; i < TX_RING_SIZE; i++) {
volatile struct TDRE *t = &lancedata->tx_ring[i];
t->TMD0 = swloww(ARIADNE_RAM +
offsetof(struct lancedata, tx_buff[i]));
t->TMD1 = swhighw(ARIADNE_RAM +
offsetof(struct lancedata, tx_buff[i])) |
TF_STP | TF_ENP;
t->TMD2 = swapw((u_short)-PKT_BUF_SIZE);
t->TMD3 = 0;
priv->tx_ring[i] = &lancedata->tx_ring[i];
priv->tx_buff[i] = lancedata->tx_buff[i];
netdev_dbg(dev, "TX Entry %2d at %p, Buf at %p\n",
i, &lancedata->tx_ring[i], lancedata->tx_buff[i]);
}
for (i = 0; i < RX_RING_SIZE; i++) {
volatile struct RDRE *r = &lancedata->rx_ring[i];
r->RMD0 = swloww(ARIADNE_RAM +
offsetof(struct lancedata, rx_buff[i]));
r->RMD1 = swhighw(ARIADNE_RAM +
offsetof(struct lancedata, rx_buff[i])) |
RF_OWN;
r->RMD2 = swapw((u_short)-PKT_BUF_SIZE);
r->RMD3 = 0x0000;
priv->rx_ring[i] = &lancedata->rx_ring[i];
priv->rx_buff[i] = lancedata->rx_buff[i];
netdev_dbg(dev, "RX Entry %2d at %p, Buf at %p\n",
i, &lancedata->rx_ring[i], lancedata->rx_buff[i]);
}
}
static int ariadne_rx(struct net_device *dev)
{
struct ariadne_private *priv = netdev_priv(dev);
int entry = priv->cur_rx % RX_RING_SIZE;
int i;
while (!(lowb(priv->rx_ring[entry]->RMD1) & RF_OWN)) {
int status = lowb(priv->rx_ring[entry]->RMD1);
if (status != (RF_STP | RF_ENP)) {
if (status & RF_ENP)
dev->stats.rx_errors++;
if (status & RF_FRAM)
dev->stats.rx_frame_errors++;
if (status & RF_OFLO)
dev->stats.rx_over_errors++;
if (status & RF_CRC)
dev->stats.rx_crc_errors++;
if (status & RF_BUFF)
dev->stats.rx_fifo_errors++;
priv->rx_ring[entry]->RMD1 &= 0xff00 | RF_STP | RF_ENP;
} else {
short pkt_len = swapw(priv->rx_ring[entry]->RMD3);
struct sk_buff *skb;
skb = netdev_alloc_skb(dev, pkt_len + 2);
if (skb == NULL) {
netdev_warn(dev, "Memory squeeze, deferring packet\n");
for (i = 0; i < RX_RING_SIZE; i++)
if (lowb(priv->rx_ring[(entry + i) % RX_RING_SIZE]->RMD1) & RF_OWN)
break;
if (i > RX_RING_SIZE - 2) {
dev->stats.rx_dropped++;
priv->rx_ring[entry]->RMD1 |= RF_OWN;
priv->cur_rx++;
}
break;
}
skb_reserve(skb, 2);
skb_put(skb, pkt_len);
skb_copy_to_linear_data(skb,
(const void *)priv->rx_buff[entry],
pkt_len);
skb->protocol = eth_type_trans(skb, dev);
netdev_dbg(dev, "RX pkt type 0x%04x from %pM to %pM data 0x%08x len %d\n",
((u_short *)skb->data)[6],
skb->data + 6, skb->data,
(int)skb->data, (int)skb->len);
netif_rx(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += pkt_len;
}
priv->rx_ring[entry]->RMD1 |= RF_OWN;
entry = (++priv->cur_rx) % RX_RING_SIZE;
}
priv->cur_rx = priv->cur_rx % RX_RING_SIZE;
return 0;
}
static irqreturn_t ariadne_interrupt(int irq, void *data)
{
struct net_device *dev = (struct net_device *)data;
volatile struct Am79C960 *lance = (struct Am79C960 *)dev->base_addr;
struct ariadne_private *priv;
int csr0, boguscnt;
int handled = 0;
lance->RAP = CSR0;
if (!(lance->RDP & INTR))
return IRQ_NONE;
priv = netdev_priv(dev);
boguscnt = 10;
while ((csr0 = lance->RDP) & (ERR | RINT | TINT) && --boguscnt >= 0) {
lance->RDP = csr0 & ~(INEA | TDMD | STOP | STRT | INIT);
#ifdef DEBUG
if (ariadne_debug > 5) {
netdev_dbg(dev, "interrupt csr0=%#02x new csr=%#02x [",
csr0, lance->RDP);
if (csr0 & INTR)
pr_cont(" INTR");
if (csr0 & INEA)
pr_cont(" INEA");
if (csr0 & RXON)
pr_cont(" RXON");
if (csr0 & TXON)
pr_cont(" TXON");
if (csr0 & TDMD)
pr_cont(" TDMD");
if (csr0 & STOP)
pr_cont(" STOP");
if (csr0 & STRT)
pr_cont(" STRT");
if (csr0 & INIT)
pr_cont(" INIT");
if (csr0 & ERR)
pr_cont(" ERR");
if (csr0 & BABL)
pr_cont(" BABL");
if (csr0 & CERR)
pr_cont(" CERR");
if (csr0 & MISS)
pr_cont(" MISS");
if (csr0 & MERR)
pr_cont(" MERR");
if (csr0 & RINT)
pr_cont(" RINT");
if (csr0 & TINT)
pr_cont(" TINT");
if (csr0 & IDON)
pr_cont(" IDON");
pr_cont(" ]\n");
}
#endif
if (csr0 & RINT) {
handled = 1;
ariadne_rx(dev);
}
if (csr0 & TINT) {
int dirty_tx = priv->dirty_tx;
handled = 1;
while (dirty_tx < priv->cur_tx) {
int entry = dirty_tx % TX_RING_SIZE;
int status = lowb(priv->tx_ring[entry]->TMD1);
if (status & TF_OWN)
break;
priv->tx_ring[entry]->TMD1 &= 0xff00;
if (status & TF_ERR) {
int err_status = priv->tx_ring[entry]->TMD3;
dev->stats.tx_errors++;
if (err_status & EF_RTRY)
dev->stats.tx_aborted_errors++;
if (err_status & EF_LCAR)
dev->stats.tx_carrier_errors++;
if (err_status & EF_LCOL)
dev->stats.tx_window_errors++;
if (err_status & EF_UFLO) {
dev->stats.tx_fifo_errors++;
netdev_err(dev, "Tx FIFO error! Status %04x\n",
csr0);
lance->RDP = STRT;
}
} else {
if (status & (TF_MORE | TF_ONE))
dev->stats.collisions++;
dev->stats.tx_packets++;
}
dirty_tx++;
}
#ifndef final_version
if (priv->cur_tx - dirty_tx >= TX_RING_SIZE) {
netdev_err(dev, "out-of-sync dirty pointer, %d vs. %d, full=%d\n",
dirty_tx, priv->cur_tx,
priv->tx_full);
dirty_tx += TX_RING_SIZE;
}
#endif
if (priv->tx_full && netif_queue_stopped(dev) &&
dirty_tx > priv->cur_tx - TX_RING_SIZE + 2) {
priv->tx_full = 0;
netif_wake_queue(dev);
}
priv->dirty_tx = dirty_tx;
}
if (csr0 & BABL) {
handled = 1;
dev->stats.tx_errors++;
}
if (csr0 & MISS) {
handled = 1;
dev->stats.rx_errors++;
}
if (csr0 & MERR) {
handled = 1;
netdev_err(dev, "Bus master arbitration failure, status %04x\n",
csr0);
lance->RDP = STRT;
}
}
lance->RAP = CSR0;
lance->RDP = INEA | BABL | CERR | MISS | MERR | IDON;
if (ariadne_debug > 4)
netdev_dbg(dev, "exiting interrupt, csr%d=%#04x\n",
lance->RAP, lance->RDP);
return IRQ_RETVAL(handled);
}
static int ariadne_open(struct net_device *dev)
{
volatile struct Am79C960 *lance = (struct Am79C960 *)dev->base_addr;
u_short in;
u_long version;
int i;
in = lance->Reset;
lance->RAP = CSR0;
lance->RDP = STOP;
lance->RAP = CSR88;
version = swapw(lance->RDP);
lance->RAP = CSR89;
version |= swapw(lance->RDP) << 16;
if ((version & 0x00000fff) != 0x00000003) {
pr_warn("Couldn't find AMD Ethernet Chip\n");
return -EAGAIN;
}
if ((version & 0x0ffff000) != 0x00003000) {
pr_warn("Couldn't find Am79C960 (Wrong part number = %ld)\n",
(version & 0x0ffff000) >> 12);
return -EAGAIN;
}
netdev_dbg(dev, "Am79C960 (PCnet-ISA) Revision %ld\n",
(version & 0xf0000000) >> 28);
ariadne_init_ring(dev);
lance->RAP = CSR3;
lance->RDP = 0x0000;
lance->RAP = CSR4;
lance->RDP = DPOLL | APAD_XMT | MFCOM | RCVCCOM | TXSTRTM | JABM;
lance->RAP = CSR8;
lance->RDP = 0x0000;
lance->RAP = CSR9;
lance->RDP = 0x0000;
lance->RAP = CSR10;
lance->RDP = 0x0000;
lance->RAP = CSR11;
lance->RDP = 0x0000;
lance->RAP = CSR12;
lance->RDP = ((u_short *)&dev->dev_addr[0])[0];
lance->RAP = CSR13;
lance->RDP = ((u_short *)&dev->dev_addr[0])[1];
lance->RAP = CSR14;
lance->RDP = ((u_short *)&dev->dev_addr[0])[2];
lance->RAP = CSR15;
lance->RDP = 0x0000;
lance->RAP = CSR30;
lance->RDP = swloww(ARIADNE_RAM + offsetof(struct lancedata, tx_ring));
lance->RAP = CSR31;
lance->RDP = swhighw(ARIADNE_RAM + offsetof(struct lancedata, tx_ring));
lance->RAP = CSR24;
lance->RDP = swloww(ARIADNE_RAM + offsetof(struct lancedata, rx_ring));
lance->RAP = CSR25;
lance->RDP = swhighw(ARIADNE_RAM + offsetof(struct lancedata, rx_ring));
lance->RAP = CSR76;
lance->RDP = swapw(((u_short)-RX_RING_SIZE));
lance->RAP = CSR78;
lance->RDP = swapw(((u_short)-TX_RING_SIZE));
lance->RAP = ISACSR2;
lance->IDP = ASEL;
lance->RAP = ISACSR5;
lance->IDP = PSE|XMTE;
lance->RAP = ISACSR6;
lance->IDP = PSE|COLE;
lance->RAP = ISACSR7;
lance->IDP = PSE|RCVE;
netif_start_queue(dev);
i = request_irq(IRQ_AMIGA_PORTS, ariadne_interrupt, IRQF_SHARED,
dev->name, dev);
if (i)
return i;
lance->RAP = CSR0;
lance->RDP = INEA | STRT;
return 0;
}
static int ariadne_close(struct net_device *dev)
{
volatile struct Am79C960 *lance = (struct Am79C960 *)dev->base_addr;
netif_stop_queue(dev);
lance->RAP = CSR112;
dev->stats.rx_missed_errors = swapw(lance->RDP);
lance->RAP = CSR0;
if (ariadne_debug > 1) {
netdev_dbg(dev, "Shutting down ethercard, status was %02x\n",
lance->RDP);
netdev_dbg(dev, "%lu packets missed\n",
dev->stats.rx_missed_errors);
}
lance->RDP = STOP;
free_irq(IRQ_AMIGA_PORTS, dev);
return 0;
}
static inline void ariadne_reset(struct net_device *dev)
{
volatile struct Am79C960 *lance = (struct Am79C960 *)dev->base_addr;
lance->RAP = CSR0;
lance->RDP = STOP;
ariadne_init_ring(dev);
lance->RDP = INEA | STRT;
netif_start_queue(dev);
}
static void ariadne_tx_timeout(struct net_device *dev)
{
volatile struct Am79C960 *lance = (struct Am79C960 *)dev->base_addr;
netdev_err(dev, "transmit timed out, status %04x, resetting\n",
lance->RDP);
ariadne_reset(dev);
netif_wake_queue(dev);
}
static netdev_tx_t ariadne_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct ariadne_private *priv = netdev_priv(dev);
volatile struct Am79C960 *lance = (struct Am79C960 *)dev->base_addr;
int entry;
unsigned long flags;
int len = skb->len;
#if 0
if (ariadne_debug > 3) {
lance->RAP = CSR0;
netdev_dbg(dev, "%s: csr0 %04x\n", __func__, lance->RDP);
lance->RDP = 0x0000;
}
#endif
if (skb->len < ETH_ZLEN) {
if (skb_padto(skb, ETH_ZLEN))
return NETDEV_TX_OK;
len = ETH_ZLEN;
}
netdev_dbg(dev, "TX pkt type 0x%04x from %pM to %pM data 0x%08x len %d\n",
((u_short *)skb->data)[6],
skb->data + 6, skb->data,
(int)skb->data, (int)skb->len);
local_irq_save(flags);
entry = priv->cur_tx % TX_RING_SIZE;
priv->tx_ring[entry]->TMD2 = swapw((u_short)-skb->len);
priv->tx_ring[entry]->TMD3 = 0x0000;
memcpyw(priv->tx_buff[entry], (u_short *)skb->data, len);
#ifdef DEBUG
print_hex_dump(KERN_DEBUG, "tx_buff: ", DUMP_PREFIX_OFFSET, 16, 1,
(void *)priv->tx_buff[entry],
skb->len > 64 ? 64 : skb->len, true);
#endif
priv->tx_ring[entry]->TMD1 = (priv->tx_ring[entry]->TMD1 & 0xff00)
| TF_OWN | TF_STP | TF_ENP;
dev_kfree_skb(skb);
priv->cur_tx++;
if ((priv->cur_tx >= TX_RING_SIZE) &&
(priv->dirty_tx >= TX_RING_SIZE)) {
netdev_dbg(dev, "*** Subtracting TX_RING_SIZE from cur_tx (%d) and dirty_tx (%d)\n",
priv->cur_tx, priv->dirty_tx);
priv->cur_tx -= TX_RING_SIZE;
priv->dirty_tx -= TX_RING_SIZE;
}
dev->stats.tx_bytes += len;
lance->RAP = CSR0;
lance->RDP = INEA | TDMD;
if (lowb(priv->tx_ring[(entry + 1) % TX_RING_SIZE]->TMD1) != 0) {
netif_stop_queue(dev);
priv->tx_full = 1;
}
local_irq_restore(flags);
return NETDEV_TX_OK;
}
static struct net_device_stats *ariadne_get_stats(struct net_device *dev)
{
volatile struct Am79C960 *lance = (struct Am79C960 *)dev->base_addr;
short saved_addr;
unsigned long flags;
local_irq_save(flags);
saved_addr = lance->RAP;
lance->RAP = CSR112;
dev->stats.rx_missed_errors = swapw(lance->RDP);
lance->RAP = saved_addr;
local_irq_restore(flags);
return &dev->stats;
}
static void set_multicast_list(struct net_device *dev)
{
volatile struct Am79C960 *lance = (struct Am79C960 *)dev->base_addr;
if (!netif_running(dev))
return;
netif_stop_queue(dev);
lance->RAP = CSR0;
lance->RDP = STOP;
ariadne_init_ring(dev);
if (dev->flags & IFF_PROMISC) {
lance->RAP = CSR15;
lance->RDP = PROM;
} else {
short multicast_table[4];
int num_addrs = netdev_mc_count(dev);
int i;
memset(multicast_table, (num_addrs == 0) ? 0 : -1,
sizeof(multicast_table));
for (i = 0; i < 4; i++) {
lance->RAP = CSR8 + (i << 8);
lance->RDP = swapw(multicast_table[i]);
}
lance->RAP = CSR15;
lance->RDP = 0x0000;
}
lance->RAP = CSR0;
lance->RDP = INEA | STRT | IDON;
netif_wake_queue(dev);
}
static void __devexit ariadne_remove_one(struct zorro_dev *z)
{
struct net_device *dev = zorro_get_drvdata(z);
unregister_netdev(dev);
release_mem_region(ZTWO_PADDR(dev->base_addr), sizeof(struct Am79C960));
release_mem_region(ZTWO_PADDR(dev->mem_start), ARIADNE_RAM_SIZE);
free_netdev(dev);
}
static int __devinit ariadne_init_one(struct zorro_dev *z,
const struct zorro_device_id *ent)
{
unsigned long board = z->resource.start;
unsigned long base_addr = board + ARIADNE_LANCE;
unsigned long mem_start = board + ARIADNE_RAM;
struct resource *r1, *r2;
struct net_device *dev;
struct ariadne_private *priv;
int err;
r1 = request_mem_region(base_addr, sizeof(struct Am79C960), "Am79C960");
if (!r1)
return -EBUSY;
r2 = request_mem_region(mem_start, ARIADNE_RAM_SIZE, "RAM");
if (!r2) {
release_mem_region(base_addr, sizeof(struct Am79C960));
return -EBUSY;
}
dev = alloc_etherdev(sizeof(struct ariadne_private));
if (dev == NULL) {
release_mem_region(base_addr, sizeof(struct Am79C960));
release_mem_region(mem_start, ARIADNE_RAM_SIZE);
return -ENOMEM;
}
priv = netdev_priv(dev);
r1->name = dev->name;
r2->name = dev->name;
dev->dev_addr[0] = 0x00;
dev->dev_addr[1] = 0x60;
dev->dev_addr[2] = 0x30;
dev->dev_addr[3] = (z->rom.er_SerialNumber >> 16) & 0xff;
dev->dev_addr[4] = (z->rom.er_SerialNumber >> 8) & 0xff;
dev->dev_addr[5] = z->rom.er_SerialNumber & 0xff;
dev->base_addr = ZTWO_VADDR(base_addr);
dev->mem_start = ZTWO_VADDR(mem_start);
dev->mem_end = dev->mem_start + ARIADNE_RAM_SIZE;
dev->netdev_ops = &ariadne_netdev_ops;
dev->watchdog_timeo = 5 * HZ;
err = register_netdev(dev);
if (err) {
release_mem_region(base_addr, sizeof(struct Am79C960));
release_mem_region(mem_start, ARIADNE_RAM_SIZE);
free_netdev(dev);
return err;
}
zorro_set_drvdata(z, dev);
netdev_info(dev, "Ariadne at 0x%08lx, Ethernet Address %pM\n",
board, dev->dev_addr);
return 0;
}
static int __init ariadne_init_module(void)
{
return zorro_register_driver(&ariadne_driver);
}
static void __exit ariadne_cleanup_module(void)
{
zorro_unregister_driver(&ariadne_driver);
}
