static inline void WRITERAP(struct lance_private *lp, __u16 value)
{
do {
out_be16(lp->base + HPLANCE_REGOFF + LANCE_RAP, value);
} while ((in_8(lp->base + HPLANCE_STATUS) & LE_ACK) == 0);
}
static inline void WRITERDP(struct lance_private *lp, __u16 value)
{
do {
out_be16(lp->base + HPLANCE_REGOFF + LANCE_RDP, value);
} while ((in_8(lp->base + HPLANCE_STATUS) & LE_ACK) == 0);
}
static inline __u16 READRDP(struct lance_private *lp)
{
__u16 value;
do {
value = in_be16(lp->base + HPLANCE_REGOFF + LANCE_RDP);
} while ((in_8(lp->base + HPLANCE_STATUS) & LE_ACK) == 0);
return value;
}
static void load_csrs (struct lance_private *lp)
{
volatile struct lance_init_block *aib = lp->lance_init_block;
int leptr;
leptr = LANCE_ADDR (aib);
WRITERAP(lp, LE_CSR1);
WRITERDP(lp, leptr & 0xFFFF);
WRITERAP(lp, LE_CSR2);
WRITERDP(lp, leptr >> 16);
WRITERAP(lp, LE_CSR3);
WRITERDP(lp, lp->busmaster_regval);
WRITERAP(lp, LE_CSR0);
}
static void lance_init_ring (struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
volatile struct lance_init_block *ib = lp->init_block;
volatile struct lance_init_block *aib;
int leptr;
int i;
aib = lp->lance_init_block;
lp->rx_new = lp->tx_new = 0;
lp->rx_old = lp->tx_old = 0;
ib->mode = LE_MO_PROM;
#ifdef __BIG_ENDIAN
ib->phys_addr [0] = dev->dev_addr [1];
ib->phys_addr [1] = dev->dev_addr [0];
ib->phys_addr [2] = dev->dev_addr [3];
ib->phys_addr [3] = dev->dev_addr [2];
ib->phys_addr [4] = dev->dev_addr [5];
ib->phys_addr [5] = dev->dev_addr [4];
#else
for (i=0; i<6; i++)
ib->phys_addr[i] = dev->dev_addr[i];
#endif
if (DEBUG_IRING)
printk ("TX rings:\n");
lp->tx_full = 0;
for (i = 0; i < (1<<lp->lance_log_tx_bufs); i++) {
leptr = LANCE_ADDR(&aib->tx_buf[i][0]);
ib->btx_ring [i].tmd0 = leptr;
ib->btx_ring [i].tmd1_hadr = leptr >> 16;
ib->btx_ring [i].tmd1_bits = 0;
ib->btx_ring [i].length = 0xf000;
ib->btx_ring [i].misc = 0;
if (DEBUG_IRING)
printk ("%d: 0x%8.8x\n", i, leptr);
}
if (DEBUG_IRING)
printk ("RX rings:\n");
for (i = 0; i < (1<<lp->lance_log_rx_bufs); i++) {
leptr = LANCE_ADDR(&aib->rx_buf[i][0]);
ib->brx_ring [i].rmd0 = leptr;
ib->brx_ring [i].rmd1_hadr = leptr >> 16;
ib->brx_ring [i].rmd1_bits = LE_R1_OWN;
ib->brx_ring [i].length = -RX_BUFF_SIZE | 0xf000;
ib->brx_ring [i].mblength = 0;
if (DEBUG_IRING)
printk ("%d: 0x%8.8x\n", i, leptr);
}
leptr = LANCE_ADDR(&aib->brx_ring);
ib->rx_len = (lp->lance_log_rx_bufs << 13) | (leptr >> 16);
ib->rx_ptr = leptr;
if (DEBUG_IRING)
printk ("RX ptr: %8.8x\n", leptr);
leptr = LANCE_ADDR(&aib->btx_ring);
ib->tx_len = (lp->lance_log_tx_bufs << 13) | (leptr >> 16);
ib->tx_ptr = leptr;
if (DEBUG_IRING)
printk ("TX ptr: %8.8x\n", leptr);
ib->filter [0] = 0;
ib->filter [1] = 0;
PRINT_RINGS();
}
static int init_restart_lance (struct lance_private *lp)
{
int i;
WRITERAP(lp, LE_CSR0);
WRITERDP(lp, LE_C0_INIT);
for (i = 0; (i < 100) && !(READRDP(lp) & (LE_C0_ERR | LE_C0_IDON)); i++)
barrier();
if ((i == 100) || (READRDP(lp) & LE_C0_ERR)) {
printk ("LANCE unopened after %d ticks, csr0=%4.4x.\n", i, READRDP(lp));
return -1;
}
WRITERDP(lp, LE_C0_IDON);
WRITERDP(lp, LE_C0_INEA | LE_C0_STRT);
return 0;
}
static int lance_reset (struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
int status;
WRITERAP(lp, LE_CSR0);
WRITERDP(lp, LE_C0_STOP);
load_csrs (lp);
lance_init_ring (dev);
dev->trans_start = jiffies;
status = init_restart_lance (lp);
#ifdef DEBUG_DRIVER
printk ("Lance restart=%d\n", status);
#endif
return status;
}
static int lance_rx (struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
volatile struct lance_init_block *ib = lp->init_block;
volatile struct lance_rx_desc *rd;
unsigned char bits;
#ifdef TEST_HITS
int i;
#endif
#ifdef TEST_HITS
printk ("[");
for (i = 0; i < RX_RING_SIZE; i++) {
if (i == lp->rx_new)
printk ("%s",
ib->brx_ring [i].rmd1_bits & LE_R1_OWN ? "_" : "X");
else
printk ("%s",
ib->brx_ring [i].rmd1_bits & LE_R1_OWN ? "." : "1");
}
printk ("]");
#endif
#ifdef CONFIG_HP300
blinken_leds(0x40, 0);
#endif
WRITERDP(lp, LE_C0_RINT | LE_C0_INEA);
for (rd = &ib->brx_ring [lp->rx_new];
!((bits = rd->rmd1_bits) & LE_R1_OWN);
rd = &ib->brx_ring [lp->rx_new]) {
if ((bits & LE_R1_POK) != LE_R1_POK) {
dev->stats.rx_over_errors++;
dev->stats.rx_errors++;
continue;
} else if (bits & LE_R1_ERR) {
if (bits & LE_R1_BUF) dev->stats.rx_fifo_errors++;
if (bits & LE_R1_CRC) dev->stats.rx_crc_errors++;
if (bits & LE_R1_OFL) dev->stats.rx_over_errors++;
if (bits & LE_R1_FRA) dev->stats.rx_frame_errors++;
if (bits & LE_R1_EOP) dev->stats.rx_errors++;
} else {
int len = (rd->mblength & 0xfff) - 4;
struct sk_buff *skb = netdev_alloc_skb(dev, len + 2);
if (!skb) {
printk ("%s: Memory squeeze, deferring packet.\n",
dev->name);
dev->stats.rx_dropped++;
rd->mblength = 0;
rd->rmd1_bits = LE_R1_OWN;
lp->rx_new = (lp->rx_new + 1) & lp->rx_ring_mod_mask;
return 0;
}
skb_reserve (skb, 2);
skb_put (skb, len);
skb_copy_to_linear_data(skb,
(unsigned char *)&(ib->rx_buf [lp->rx_new][0]),
len);
skb->protocol = eth_type_trans (skb, dev);
netif_rx (skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += len;
}
rd->mblength = 0;
rd->rmd1_bits = LE_R1_OWN;
lp->rx_new = (lp->rx_new + 1) & lp->rx_ring_mod_mask;
}
return 0;
}
static int lance_tx (struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
volatile struct lance_init_block *ib = lp->init_block;
volatile struct lance_tx_desc *td;
int i, j;
int status;
#ifdef CONFIG_HP300
blinken_leds(0x80, 0);
#endif
WRITERDP(lp, LE_C0_TINT | LE_C0_INEA);
j = lp->tx_old;
for (i = j; i != lp->tx_new; i = j) {
td = &ib->btx_ring [i];
if (td->tmd1_bits & LE_T1_OWN)
break;
if (td->tmd1_bits & LE_T1_ERR) {
status = td->misc;
dev->stats.tx_errors++;
if (status & LE_T3_RTY) dev->stats.tx_aborted_errors++;
if (status & LE_T3_LCOL) dev->stats.tx_window_errors++;
if (status & LE_T3_CLOS) {
dev->stats.tx_carrier_errors++;
if (lp->auto_select) {
lp->tpe = 1 - lp->tpe;
printk("%s: Carrier Lost, trying %s\n",
dev->name, lp->tpe?"TPE":"AUI");
WRITERAP(lp, LE_CSR0);
WRITERDP(lp, LE_C0_STOP);
lance_init_ring (dev);
load_csrs (lp);
init_restart_lance (lp);
return 0;
}
}
if (status & (LE_T3_BUF|LE_T3_UFL)) {
dev->stats.tx_fifo_errors++;
printk ("%s: Tx: ERR_BUF|ERR_UFL, restarting\n",
dev->name);
WRITERAP(lp, LE_CSR0);
WRITERDP(lp, LE_C0_STOP);
lance_init_ring (dev);
load_csrs (lp);
init_restart_lance (lp);
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
WRITERDP(lp, LE_C0_TINT | LE_C0_INEA);
return 0;
}
static irqreturn_t
lance_interrupt (int irq, void *dev_id)
{
struct net_device *dev = (struct net_device *)dev_id;
struct lance_private *lp = netdev_priv(dev);
int csr0;
spin_lock (&lp->devlock);
WRITERAP(lp, LE_CSR0);
csr0 = READRDP(lp);
PRINT_RINGS();
if (!(csr0 & LE_C0_INTR)) {
spin_unlock (&lp->devlock);
return IRQ_NONE;
}
WRITERDP(lp, csr0 & ~(LE_C0_INEA|LE_C0_TDMD|LE_C0_STOP|LE_C0_STRT|LE_C0_INIT));
if ((csr0 & LE_C0_ERR)) {
WRITERDP(lp, LE_C0_BABL|LE_C0_ERR|LE_C0_MISS|LE_C0_INEA);
}
if (csr0 & LE_C0_RINT)
lance_rx (dev);
if (csr0 & LE_C0_TINT)
lance_tx (dev);
if (csr0 & LE_C0_BABL)
dev->stats.tx_errors++;
if (csr0 & LE_C0_MISS)
dev->stats.rx_errors++;
if (csr0 & LE_C0_MERR) {
printk("%s: Bus master arbitration failure, status %4.4x.\n",
dev->name, csr0);
WRITERDP(lp, LE_C0_STRT);
}
if (lp->tx_full && netif_queue_stopped(dev) && (TX_BUFFS_AVAIL >= 0)) {
lp->tx_full = 0;
netif_wake_queue (dev);
}
WRITERAP(lp, LE_CSR0);
WRITERDP(lp, LE_C0_BABL|LE_C0_CERR|LE_C0_MISS|LE_C0_MERR|LE_C0_IDON|LE_C0_INEA);
spin_unlock (&lp->devlock);
return IRQ_HANDLED;
}
int lance_open (struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
int res;
if (request_irq(lp->irq, lance_interrupt, IRQF_SHARED, lp->name, dev))
return -EAGAIN;
res = lance_reset(dev);
spin_lock_init(&lp->devlock);
netif_start_queue (dev);
return res;
}
int lance_close (struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
netif_stop_queue (dev);
WRITERAP(lp, LE_CSR0);
WRITERDP(lp, LE_C0_STOP);
free_irq(lp->irq, dev);
return 0;
}
void lance_tx_timeout(struct net_device *dev)
{
printk("lance_tx_timeout\n");
lance_reset(dev);
dev->trans_start = jiffies;
netif_wake_queue (dev);
}
int lance_start_xmit (struct sk_buff *skb, struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
volatile struct lance_init_block *ib = lp->init_block;
int entry, skblen, len;
static int outs;
unsigned long flags;
if (!TX_BUFFS_AVAIL)
return NETDEV_TX_LOCKED;
netif_stop_queue (dev);
skblen = skb->len;
#ifdef DEBUG_DRIVER
{
int i;
for (i = 0; i < 64; i++) {
if ((i % 16) == 0)
printk ("\n");
printk ("%2.2x ", skb->data [i]);
}
}
#endif
len = (skblen <= ETH_ZLEN) ? ETH_ZLEN : skblen;
entry = lp->tx_new & lp->tx_ring_mod_mask;
ib->btx_ring [entry].length = (-len) | 0xf000;
ib->btx_ring [entry].misc = 0;
if (skb->len < ETH_ZLEN)
memset((void *)&ib->tx_buf[entry][0], 0, ETH_ZLEN);
skb_copy_from_linear_data(skb, (void *)&ib->tx_buf[entry][0], skblen);
ib->btx_ring [entry].tmd1_bits = (LE_T1_POK|LE_T1_OWN);
lp->tx_new = (lp->tx_new+1) & lp->tx_ring_mod_mask;
outs++;
WRITERDP(lp, LE_C0_INEA | LE_C0_TDMD);
dev_kfree_skb (skb);
spin_lock_irqsave (&lp->devlock, flags);
if (TX_BUFFS_AVAIL)
netif_start_queue (dev);
else
lp->tx_full = 1;
spin_unlock_irqrestore (&lp->devlock, flags);
return NETDEV_TX_OK;
}
static void lance_load_multicast (struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
volatile struct lance_init_block *ib = lp->init_block;
volatile u16 *mcast_table = (u16 *)&ib->filter;
struct netdev_hw_addr *ha;
u32 crc;
if (dev->flags & IFF_ALLMULTI){
ib->filter [0] = 0xffffffff;
ib->filter [1] = 0xffffffff;
return;
}
ib->filter [0] = 0;
ib->filter [1] = 0;
netdev_for_each_mc_addr(ha, dev) {
crc = ether_crc_le(6, ha->addr);
crc = crc >> 26;
mcast_table [crc >> 4] |= 1 << (crc & 0xf);
}
}
void lance_set_multicast (struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
volatile struct lance_init_block *ib = lp->init_block;
int stopped;
stopped = netif_queue_stopped(dev);
if (!stopped)
netif_stop_queue (dev);
while (lp->tx_old != lp->tx_new)
schedule();
WRITERAP(lp, LE_CSR0);
WRITERDP(lp, LE_C0_STOP);
lance_init_ring (dev);
if (dev->flags & IFF_PROMISC) {
ib->mode |= LE_MO_PROM;
} else {
ib->mode &= ~LE_MO_PROM;
lance_load_multicast (dev);
}
load_csrs (lp);
init_restart_lance (lp);
if (!stopped)
netif_start_queue (dev);
}
void lance_poll(struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
spin_lock (&lp->devlock);
WRITERAP(lp, LE_CSR0);
WRITERDP(lp, LE_C0_STRT);
spin_unlock (&lp->devlock);
lance_interrupt(dev->irq, dev);
}
