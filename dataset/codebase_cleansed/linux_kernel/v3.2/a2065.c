static void load_csrs(struct lance_private *lp)
{
volatile struct lance_regs *ll = lp->ll;
volatile struct lance_init_block *aib = lp->lance_init_block;
int leptr = LANCE_ADDR(aib);
ll->rap = LE_CSR1;
ll->rdp = (leptr & 0xFFFF);
ll->rap = LE_CSR2;
ll->rdp = leptr >> 16;
ll->rap = LE_CSR3;
ll->rdp = lp->busmaster_regval;
ll->rap = LE_CSR0;
}
static void lance_init_ring(struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
volatile struct lance_init_block *ib = lp->init_block;
volatile struct lance_init_block *aib = lp->lance_init_block;
int leptr;
int i;
netif_stop_queue(dev);
lp->rx_new = lp->tx_new = 0;
lp->rx_old = lp->tx_old = 0;
ib->mode = 0;
ib->phys_addr[0] = dev->dev_addr[1];
ib->phys_addr[1] = dev->dev_addr[0];
ib->phys_addr[2] = dev->dev_addr[3];
ib->phys_addr[3] = dev->dev_addr[2];
ib->phys_addr[4] = dev->dev_addr[5];
ib->phys_addr[5] = dev->dev_addr[4];
netdev_dbg(dev, "TX rings:\n");
for (i = 0; i <= 1 << lp->lance_log_tx_bufs; i++) {
leptr = LANCE_ADDR(&aib->tx_buf[i][0]);
ib->btx_ring[i].tmd0 = leptr;
ib->btx_ring[i].tmd1_hadr = leptr >> 16;
ib->btx_ring[i].tmd1_bits = 0;
ib->btx_ring[i].length = 0xf000;
ib->btx_ring[i].misc = 0;
if (i < 3)
netdev_dbg(dev, "%d: 0x%08x\n", i, leptr);
}
netdev_dbg(dev, "RX rings:\n");
for (i = 0; i < 1 << lp->lance_log_rx_bufs; i++) {
leptr = LANCE_ADDR(&aib->rx_buf[i][0]);
ib->brx_ring[i].rmd0 = leptr;
ib->brx_ring[i].rmd1_hadr = leptr >> 16;
ib->brx_ring[i].rmd1_bits = LE_R1_OWN;
ib->brx_ring[i].length = -RX_BUFF_SIZE | 0xf000;
ib->brx_ring[i].mblength = 0;
if (i < 3)
netdev_dbg(dev, "%d: 0x%08x\n", i, leptr);
}
leptr = LANCE_ADDR(&aib->brx_ring);
ib->rx_len = (lp->lance_log_rx_bufs << 13) | (leptr >> 16);
ib->rx_ptr = leptr;
netdev_dbg(dev, "RX ptr: %08x\n", leptr);
leptr = LANCE_ADDR(&aib->btx_ring);
ib->tx_len = (lp->lance_log_tx_bufs << 13) | (leptr >> 16);
ib->tx_ptr = leptr;
netdev_dbg(dev, "TX ptr: %08x\n", leptr);
ib->filter[0] = 0;
ib->filter[1] = 0;
}
static int init_restart_lance(struct lance_private *lp)
{
volatile struct lance_regs *ll = lp->ll;
int i;
ll->rap = LE_CSR0;
ll->rdp = LE_C0_INIT;
for (i = 0; (i < 100) && !(ll->rdp & (LE_C0_ERR | LE_C0_IDON)); i++)
barrier();
if ((i == 100) || (ll->rdp & LE_C0_ERR)) {
pr_err("unopened after %d ticks, csr0=%04x\n", i, ll->rdp);
return -EIO;
}
ll->rdp = LE_C0_IDON;
ll->rdp = LE_C0_INEA | LE_C0_STRT;
return 0;
}
static int lance_rx(struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
volatile struct lance_init_block *ib = lp->init_block;
volatile struct lance_regs *ll = lp->ll;
volatile struct lance_rx_desc *rd;
unsigned char bits;
#ifdef TEST_HITS
int i;
char buf[RX_RING_SIZE + 1];
for (i = 0; i < RX_RING_SIZE; i++) {
char r1_own = ib->brx_ring[i].rmd1_bits & LE_R1_OWN;
if (i == lp->rx_new)
buf[i] = r1_own ? '_' : 'X';
else
buf[i] = r1_own ? '.' : '1';
}
buf[RX_RING_SIZE] = 0;
pr_debug("RxRing TestHits: [%s]\n", buf);
#endif
ll->rdp = LE_C0_RINT | LE_C0_INEA;
for (rd = &ib->brx_ring[lp->rx_new];
!((bits = rd->rmd1_bits) & LE_R1_OWN);
rd = &ib->brx_ring[lp->rx_new]) {
if ((bits & LE_R1_POK) != LE_R1_POK) {
dev->stats.rx_over_errors++;
dev->stats.rx_errors++;
continue;
} else if (bits & LE_R1_ERR) {
if (bits & LE_R1_BUF)
dev->stats.rx_fifo_errors++;
if (bits & LE_R1_CRC)
dev->stats.rx_crc_errors++;
if (bits & LE_R1_OFL)
dev->stats.rx_over_errors++;
if (bits & LE_R1_FRA)
dev->stats.rx_frame_errors++;
if (bits & LE_R1_EOP)
dev->stats.rx_errors++;
} else {
int len = (rd->mblength & 0xfff) - 4;
struct sk_buff *skb = dev_alloc_skb(len + 2);
if (!skb) {
netdev_warn(dev, "Memory squeeze, deferring packet\n");
dev->stats.rx_dropped++;
rd->mblength = 0;
rd->rmd1_bits = LE_R1_OWN;
lp->rx_new = (lp->rx_new + 1) & lp->rx_ring_mod_mask;
return 0;
}
skb_reserve(skb, 2);
skb_put(skb, len);
skb_copy_to_linear_data(skb,
(unsigned char *)&ib->rx_buf[lp->rx_new][0],
len);
skb->protocol = eth_type_trans(skb, dev);
netif_rx(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += len;
}
rd->mblength = 0;
rd->rmd1_bits = LE_R1_OWN;
lp->rx_new = (lp->rx_new + 1) & lp->rx_ring_mod_mask;
}
return 0;
}
static int lance_tx(struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
volatile struct lance_init_block *ib = lp->init_block;
volatile struct lance_regs *ll = lp->ll;
volatile struct lance_tx_desc *td;
int i, j;
int status;
ll->rdp = LE_C0_TINT | LE_C0_INEA;
j = lp->tx_old;
for (i = j; i != lp->tx_new; i = j) {
td = &ib->btx_ring[i];
if (td->tmd1_bits & LE_T1_OWN)
break;
if (td->tmd1_bits & LE_T1_ERR) {
status = td->misc;
dev->stats.tx_errors++;
if (status & LE_T3_RTY)
dev->stats.tx_aborted_errors++;
if (status & LE_T3_LCOL)
dev->stats.tx_window_errors++;
if (status & LE_T3_CLOS) {
dev->stats.tx_carrier_errors++;
if (lp->auto_select) {
lp->tpe = 1 - lp->tpe;
netdev_err(dev, "Carrier Lost, trying %s\n",
lp->tpe ? "TPE" : "AUI");
ll->rap = LE_CSR0;
ll->rdp = LE_C0_STOP;
lance_init_ring(dev);
load_csrs(lp);
init_restart_lance(lp);
return 0;
}
}
if (status & (LE_T3_BUF | LE_T3_UFL)) {
dev->stats.tx_fifo_errors++;
netdev_err(dev, "Tx: ERR_BUF|ERR_UFL, restarting\n");
ll->rap = LE_CSR0;
ll->rdp = LE_C0_STOP;
lance_init_ring(dev);
load_csrs(lp);
init_restart_lance(lp);
return 0;
}
} else if ((td->tmd1_bits & LE_T1_POK) == LE_T1_POK) {
td->tmd1_bits &= ~(LE_T1_POK);
if (td->tmd1_bits & LE_T1_EONE)
dev->stats.collisions++;
if (td->tmd1_bits & LE_T1_EMORE)
dev->stats.collisions += 2;
dev->stats.tx_packets++;
}
j = (j + 1) & lp->tx_ring_mod_mask;
}
lp->tx_old = j;
ll->rdp = LE_C0_TINT | LE_C0_INEA;
return 0;
}
static int lance_tx_buffs_avail(struct lance_private *lp)
{
if (lp->tx_old <= lp->tx_new)
return lp->tx_old + lp->tx_ring_mod_mask - lp->tx_new;
return lp->tx_old - lp->tx_new - 1;
}
static irqreturn_t lance_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct lance_private *lp = netdev_priv(dev);
volatile struct lance_regs *ll = lp->ll;
int csr0;
ll->rap = LE_CSR0;
csr0 = ll->rdp;
if (!(csr0 & LE_C0_INTR))
return IRQ_NONE;
ll->rdp = csr0 & ~(LE_C0_INEA | LE_C0_TDMD | LE_C0_STOP | LE_C0_STRT |
LE_C0_INIT);
if (csr0 & LE_C0_ERR) {
ll->rdp = LE_C0_BABL | LE_C0_ERR | LE_C0_MISS | LE_C0_INEA;
}
if (csr0 & LE_C0_RINT)
lance_rx(dev);
if (csr0 & LE_C0_TINT)
lance_tx(dev);
if (csr0 & LE_C0_BABL)
dev->stats.tx_errors++;
if (csr0 & LE_C0_MISS)
dev->stats.rx_errors++;
if (csr0 & LE_C0_MERR) {
netdev_err(dev, "Bus master arbitration failure, status %04x\n",
csr0);
ll->rdp = LE_C0_STRT;
}
if (netif_queue_stopped(dev) && lance_tx_buffs_avail(lp) > 0)
netif_wake_queue(dev);
ll->rap = LE_CSR0;
ll->rdp = (LE_C0_BABL | LE_C0_CERR | LE_C0_MISS | LE_C0_MERR |
LE_C0_IDON | LE_C0_INEA);
return IRQ_HANDLED;
}
static int lance_open(struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
volatile struct lance_regs *ll = lp->ll;
int ret;
ll->rap = LE_CSR0;
ll->rdp = LE_C0_STOP;
ret = request_irq(IRQ_AMIGA_PORTS, lance_interrupt, IRQF_SHARED,
dev->name, dev);
if (ret)
return ret;
load_csrs(lp);
lance_init_ring(dev);
netif_start_queue(dev);
return init_restart_lance(lp);
}
static int lance_close(struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
volatile struct lance_regs *ll = lp->ll;
netif_stop_queue(dev);
del_timer_sync(&lp->multicast_timer);
ll->rap = LE_CSR0;
ll->rdp = LE_C0_STOP;
free_irq(IRQ_AMIGA_PORTS, dev);
return 0;
}
static inline int lance_reset(struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
volatile struct lance_regs *ll = lp->ll;
int status;
ll->rap = LE_CSR0;
ll->rdp = LE_C0_STOP;
load_csrs(lp);
lance_init_ring(dev);
dev->trans_start = jiffies;
netif_start_queue(dev);
status = init_restart_lance(lp);
netdev_dbg(dev, "Lance restart=%d\n", status);
return status;
}
static void lance_tx_timeout(struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
volatile struct lance_regs *ll = lp->ll;
netdev_err(dev, "transmit timed out, status %04x, reset\n", ll->rdp);
lance_reset(dev);
netif_wake_queue(dev);
}
static netdev_tx_t lance_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
volatile struct lance_regs *ll = lp->ll;
volatile struct lance_init_block *ib = lp->init_block;
int entry, skblen;
int status = NETDEV_TX_OK;
unsigned long flags;
if (skb_padto(skb, ETH_ZLEN))
return NETDEV_TX_OK;
skblen = max_t(unsigned, skb->len, ETH_ZLEN);
local_irq_save(flags);
if (!lance_tx_buffs_avail(lp)) {
local_irq_restore(flags);
return NETDEV_TX_LOCKED;
}
#ifdef DEBUG
print_hex_dump(KERN_DEBUG, "skb->data: ", DUMP_PREFIX_NONE,
16, 1, skb->data, 64, true);
#endif
entry = lp->tx_new & lp->tx_ring_mod_mask;
ib->btx_ring[entry].length = (-skblen) | 0xf000;
ib->btx_ring[entry].misc = 0;
skb_copy_from_linear_data(skb, (void *)&ib->tx_buf[entry][0], skblen);
ib->btx_ring[entry].tmd1_bits = (LE_T1_POK | LE_T1_OWN);
lp->tx_new = (lp->tx_new+1) & lp->tx_ring_mod_mask;
dev->stats.tx_bytes += skblen;
if (lance_tx_buffs_avail(lp) <= 0)
netif_stop_queue(dev);
ll->rdp = LE_C0_INEA | LE_C0_TDMD;
dev_kfree_skb(skb);
local_irq_restore(flags);
return status;
}
static void lance_load_multicast(struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
volatile struct lance_init_block *ib = lp->init_block;
volatile u16 *mcast_table = (u16 *)&ib->filter;
struct netdev_hw_addr *ha;
u32 crc;
if (dev->flags & IFF_ALLMULTI) {
ib->filter[0] = 0xffffffff;
ib->filter[1] = 0xffffffff;
return;
}
ib->filter[0] = 0;
ib->filter[1] = 0;
netdev_for_each_mc_addr(ha, dev) {
crc = ether_crc_le(6, ha->addr);
crc = crc >> 26;
mcast_table[crc >> 4] |= 1 << (crc & 0xf);
}
}
static void lance_set_multicast(struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
volatile struct lance_init_block *ib = lp->init_block;
volatile struct lance_regs *ll = lp->ll;
if (!netif_running(dev))
return;
if (lp->tx_old != lp->tx_new) {
mod_timer(&lp->multicast_timer, jiffies + 4);
netif_wake_queue(dev);
return;
}
netif_stop_queue(dev);
ll->rap = LE_CSR0;
ll->rdp = LE_C0_STOP;
lance_init_ring(dev);
if (dev->flags & IFF_PROMISC) {
ib->mode |= LE_MO_PROM;
} else {
ib->mode &= ~LE_MO_PROM;
lance_load_multicast(dev);
}
load_csrs(lp);
init_restart_lance(lp);
netif_wake_queue(dev);
}
static int __devinit a2065_init_one(struct zorro_dev *z,
const struct zorro_device_id *ent)
{
struct net_device *dev;
struct lance_private *priv;
unsigned long board = z->resource.start;
unsigned long base_addr = board + A2065_LANCE;
unsigned long mem_start = board + A2065_RAM;
struct resource *r1, *r2;
int err;
r1 = request_mem_region(base_addr, sizeof(struct lance_regs),
"Am7990");
if (!r1)
return -EBUSY;
r2 = request_mem_region(mem_start, A2065_RAM_SIZE, "RAM");
if (!r2) {
release_mem_region(base_addr, sizeof(struct lance_regs));
return -EBUSY;
}
dev = alloc_etherdev(sizeof(struct lance_private));
if (dev == NULL) {
release_mem_region(base_addr, sizeof(struct lance_regs));
release_mem_region(mem_start, A2065_RAM_SIZE);
return -ENOMEM;
}
priv = netdev_priv(dev);
r1->name = dev->name;
r2->name = dev->name;
dev->dev_addr[0] = 0x00;
if (z->id != ZORRO_PROD_AMERISTAR_A2065) {
dev->dev_addr[1] = 0x80;
dev->dev_addr[2] = 0x10;
} else {
dev->dev_addr[1] = 0x00;
dev->dev_addr[2] = 0x9f;
}
dev->dev_addr[3] = (z->rom.er_SerialNumber >> 16) & 0xff;
dev->dev_addr[4] = (z->rom.er_SerialNumber >> 8) & 0xff;
dev->dev_addr[5] = z->rom.er_SerialNumber & 0xff;
dev->base_addr = ZTWO_VADDR(base_addr);
dev->mem_start = ZTWO_VADDR(mem_start);
dev->mem_end = dev->mem_start + A2065_RAM_SIZE;
priv->ll = (volatile struct lance_regs *)dev->base_addr;
priv->init_block = (struct lance_init_block *)dev->mem_start;
priv->lance_init_block = (struct lance_init_block *)A2065_RAM;
priv->auto_select = 0;
priv->busmaster_regval = LE_C3_BSWP;
priv->lance_log_rx_bufs = LANCE_LOG_RX_BUFFERS;
priv->lance_log_tx_bufs = LANCE_LOG_TX_BUFFERS;
priv->rx_ring_mod_mask = RX_RING_MOD_MASK;
priv->tx_ring_mod_mask = TX_RING_MOD_MASK;
dev->netdev_ops = &lance_netdev_ops;
dev->watchdog_timeo = 5*HZ;
dev->dma = 0;
init_timer(&priv->multicast_timer);
priv->multicast_timer.data = (unsigned long) dev;
priv->multicast_timer.function =
(void (*)(unsigned long))lance_set_multicast;
err = register_netdev(dev);
if (err) {
release_mem_region(base_addr, sizeof(struct lance_regs));
release_mem_region(mem_start, A2065_RAM_SIZE);
free_netdev(dev);
return err;
}
zorro_set_drvdata(z, dev);
netdev_info(dev, "A2065 at 0x%08lx, Ethernet Address %pM\n",
board, dev->dev_addr);
return 0;
}
static void __devexit a2065_remove_one(struct zorro_dev *z)
{
struct net_device *dev = zorro_get_drvdata(z);
unregister_netdev(dev);
release_mem_region(ZTWO_PADDR(dev->base_addr),
sizeof(struct lance_regs));
release_mem_region(ZTWO_PADDR(dev->mem_start), A2065_RAM_SIZE);
free_netdev(dev);
}
static int __init a2065_init_module(void)
{
return zorro_register_driver(&a2065_driver);
}
static void __exit a2065_cleanup_module(void)
{
zorro_unregister_driver(&a2065_driver);
}
