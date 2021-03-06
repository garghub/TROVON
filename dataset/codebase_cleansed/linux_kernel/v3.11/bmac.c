static inline void
dbdma_st32(volatile __u32 __iomem *a, unsigned long x)
{
__asm__ volatile( "stwbrx %0,0,%1" : : "r" (x), "r" (a) : "memory");
}
static inline unsigned long
dbdma_ld32(volatile __u32 __iomem *a)
{
__u32 swap;
__asm__ volatile ("lwbrx %0,0,%1" : "=r" (swap) : "r" (a));
return swap;
}
static void
dbdma_continue(volatile struct dbdma_regs __iomem *dmap)
{
dbdma_st32(&dmap->control,
DBDMA_SET(RUN|WAKE) | DBDMA_CLEAR(PAUSE|DEAD));
eieio();
}
static void
dbdma_reset(volatile struct dbdma_regs __iomem *dmap)
{
dbdma_st32(&dmap->control,
DBDMA_CLEAR(ACTIVE|DEAD|WAKE|FLUSH|PAUSE|RUN));
eieio();
while (dbdma_ld32(&dmap->status) & RUN)
eieio();
}
static void
dbdma_setcmd(volatile struct dbdma_cmd *cp,
unsigned short cmd, unsigned count, unsigned long addr,
unsigned long cmd_dep)
{
out_le16(&cp->command, cmd);
out_le16(&cp->req_count, count);
out_le32(&cp->phy_addr, addr);
out_le32(&cp->cmd_dep, cmd_dep);
out_le16(&cp->xfer_status, 0);
out_le16(&cp->res_count, 0);
}
static inline
void bmwrite(struct net_device *dev, unsigned long reg_offset, unsigned data )
{
out_le16((void __iomem *)dev->base_addr + reg_offset, data);
}
static inline
unsigned short bmread(struct net_device *dev, unsigned long reg_offset )
{
return in_le16((void __iomem *)dev->base_addr + reg_offset);
}
static void
bmac_enable_and_reset_chip(struct net_device *dev)
{
struct bmac_data *bp = netdev_priv(dev);
volatile struct dbdma_regs __iomem *rd = bp->rx_dma;
volatile struct dbdma_regs __iomem *td = bp->tx_dma;
if (rd)
dbdma_reset(rd);
if (td)
dbdma_reset(td);
pmac_call_feature(PMAC_FTR_BMAC_ENABLE, macio_get_of_node(bp->mdev), 0, 1);
}
static unsigned int
bmac_mif_readbits(struct net_device *dev, int nb)
{
unsigned int val = 0;
while (--nb >= 0) {
bmwrite(dev, MIFCSR, 0);
MIFDELAY;
if (bmread(dev, MIFCSR) & 8)
val |= 1 << nb;
bmwrite(dev, MIFCSR, 1);
MIFDELAY;
}
bmwrite(dev, MIFCSR, 0);
MIFDELAY;
bmwrite(dev, MIFCSR, 1);
MIFDELAY;
return val;
}
static void
bmac_mif_writebits(struct net_device *dev, unsigned int val, int nb)
{
int b;
while (--nb >= 0) {
b = (val & (1 << nb))? 6: 4;
bmwrite(dev, MIFCSR, b);
MIFDELAY;
bmwrite(dev, MIFCSR, b|1);
MIFDELAY;
}
}
static unsigned int
bmac_mif_read(struct net_device *dev, unsigned int addr)
{
unsigned int val;
bmwrite(dev, MIFCSR, 4);
MIFDELAY;
bmac_mif_writebits(dev, ~0U, 32);
bmac_mif_writebits(dev, 6, 4);
bmac_mif_writebits(dev, addr, 10);
bmwrite(dev, MIFCSR, 2);
MIFDELAY;
bmwrite(dev, MIFCSR, 1);
MIFDELAY;
val = bmac_mif_readbits(dev, 17);
bmwrite(dev, MIFCSR, 4);
MIFDELAY;
return val;
}
static void
bmac_mif_write(struct net_device *dev, unsigned int addr, unsigned int val)
{
bmwrite(dev, MIFCSR, 4);
MIFDELAY;
bmac_mif_writebits(dev, ~0U, 32);
bmac_mif_writebits(dev, 5, 4);
bmac_mif_writebits(dev, addr, 10);
bmac_mif_writebits(dev, 2, 2);
bmac_mif_writebits(dev, val, 16);
bmac_mif_writebits(dev, 3, 2);
}
static void
bmac_init_registers(struct net_device *dev)
{
struct bmac_data *bp = netdev_priv(dev);
volatile unsigned short regValue;
unsigned short *pWord16;
int i;
bmwrite(dev, RXRST, RxResetValue);
bmwrite(dev, TXRST, TxResetBit);
i = 100;
do {
--i;
udelay(10000);
regValue = bmread(dev, TXRST);
} while ((regValue & TxResetBit) && i > 0);
if (!bp->is_bmac_plus) {
regValue = bmread(dev, XCVRIF);
regValue |= ClkBit | SerialMode | COLActiveLow;
bmwrite(dev, XCVRIF, regValue);
udelay(10000);
}
bmwrite(dev, RSEED, (unsigned short)0x1968);
regValue = bmread(dev, XIFC);
regValue |= TxOutputEnable;
bmwrite(dev, XIFC, regValue);
bmread(dev, PAREG);
bmwrite(dev, NCCNT, 0);
bmwrite(dev, NTCNT, 0);
bmwrite(dev, EXCNT, 0);
bmwrite(dev, LTCNT, 0);
bmwrite(dev, FRCNT, 0);
bmwrite(dev, LECNT, 0);
bmwrite(dev, AECNT, 0);
bmwrite(dev, FECNT, 0);
bmwrite(dev, RXCV, 0);
bmwrite(dev, TXTH, 4);
bmwrite(dev, TXFIFOCSR, 0);
bmwrite(dev, TXFIFOCSR, TxFIFOEnable );
bmwrite(dev, RXFIFOCSR, 0);
bmwrite(dev, RXFIFOCSR, RxFIFOEnable );
bmread(dev, STATUS);
for (i=0; i<4; i++) bp->hash_table_mask[i] = 0;
bmwrite(dev, BHASH3, bp->hash_table_mask[0]);
bmwrite(dev, BHASH2, bp->hash_table_mask[1]);
bmwrite(dev, BHASH1, bp->hash_table_mask[2]);
bmwrite(dev, BHASH0, bp->hash_table_mask[3]);
pWord16 = (unsigned short *)dev->dev_addr;
bmwrite(dev, MADD0, *pWord16++);
bmwrite(dev, MADD1, *pWord16++);
bmwrite(dev, MADD2, *pWord16);
bmwrite(dev, RXCFG, RxCRCNoStrip | RxHashFilterEnable | RxRejectOwnPackets);
bmwrite(dev, INTDISABLE, EnableNormal);
}
static void
bmac_start_chip(struct net_device *dev)
{
struct bmac_data *bp = netdev_priv(dev);
volatile struct dbdma_regs __iomem *rd = bp->rx_dma;
unsigned short oldConfig;
dbdma_continue(rd);
oldConfig = bmread(dev, TXCFG);
bmwrite(dev, TXCFG, oldConfig | TxMACEnable );
oldConfig = bmread(dev, RXCFG);
bmwrite(dev, RXCFG, oldConfig | RxMACEnable );
udelay(20000);
}
static void
bmac_init_phy(struct net_device *dev)
{
unsigned int addr;
struct bmac_data *bp = netdev_priv(dev);
printk(KERN_DEBUG "phy registers:");
for (addr = 0; addr < 32; ++addr) {
if ((addr & 7) == 0)
printk(KERN_DEBUG);
printk(KERN_CONT " %.4x", bmac_mif_read(dev, addr));
}
printk(KERN_CONT "\n");
if (bp->is_bmac_plus) {
unsigned int capable, ctrl;
ctrl = bmac_mif_read(dev, 0);
capable = ((bmac_mif_read(dev, 1) & 0xf800) >> 6) | 1;
if (bmac_mif_read(dev, 4) != capable ||
(ctrl & 0x1000) == 0) {
bmac_mif_write(dev, 4, capable);
bmac_mif_write(dev, 0, 0x1200);
} else
bmac_mif_write(dev, 0, 0x1000);
}
}
static void bmac_init_chip(struct net_device *dev)
{
bmac_init_phy(dev);
bmac_init_registers(dev);
}
static int bmac_suspend(struct macio_dev *mdev, pm_message_t state)
{
struct net_device* dev = macio_get_drvdata(mdev);
struct bmac_data *bp = netdev_priv(dev);
unsigned long flags;
unsigned short config;
int i;
netif_device_detach(dev);
spin_lock_irqsave(&bp->lock, flags);
if (bp->timeout_active) {
del_timer(&bp->tx_timeout);
bp->timeout_active = 0;
}
disable_irq(dev->irq);
disable_irq(bp->tx_dma_intr);
disable_irq(bp->rx_dma_intr);
bp->sleeping = 1;
spin_unlock_irqrestore(&bp->lock, flags);
if (bp->opened) {
volatile struct dbdma_regs __iomem *rd = bp->rx_dma;
volatile struct dbdma_regs __iomem *td = bp->tx_dma;
config = bmread(dev, RXCFG);
bmwrite(dev, RXCFG, (config & ~RxMACEnable));
config = bmread(dev, TXCFG);
bmwrite(dev, TXCFG, (config & ~TxMACEnable));
bmwrite(dev, INTDISABLE, DisableAll);
st_le32(&rd->control, DBDMA_CLEAR(RUN|PAUSE|FLUSH|WAKE));
st_le32(&td->control, DBDMA_CLEAR(RUN|PAUSE|FLUSH|WAKE));
for (i=0; i<N_RX_RING; i++) {
if (bp->rx_bufs[i] != NULL) {
dev_kfree_skb(bp->rx_bufs[i]);
bp->rx_bufs[i] = NULL;
}
}
for (i = 0; i<N_TX_RING; i++) {
if (bp->tx_bufs[i] != NULL) {
dev_kfree_skb(bp->tx_bufs[i]);
bp->tx_bufs[i] = NULL;
}
}
}
pmac_call_feature(PMAC_FTR_BMAC_ENABLE, macio_get_of_node(bp->mdev), 0, 0);
return 0;
}
static int bmac_resume(struct macio_dev *mdev)
{
struct net_device* dev = macio_get_drvdata(mdev);
struct bmac_data *bp = netdev_priv(dev);
if (bp->opened)
bmac_reset_and_enable(dev);
enable_irq(dev->irq);
enable_irq(bp->tx_dma_intr);
enable_irq(bp->rx_dma_intr);
netif_device_attach(dev);
return 0;
}
static int bmac_set_address(struct net_device *dev, void *addr)
{
struct bmac_data *bp = netdev_priv(dev);
unsigned char *p = addr;
unsigned short *pWord16;
unsigned long flags;
int i;
XXDEBUG(("bmac: enter set_address\n"));
spin_lock_irqsave(&bp->lock, flags);
for (i = 0; i < 6; ++i) {
dev->dev_addr[i] = p[i];
}
pWord16 = (unsigned short *)dev->dev_addr;
bmwrite(dev, MADD0, *pWord16++);
bmwrite(dev, MADD1, *pWord16++);
bmwrite(dev, MADD2, *pWord16);
spin_unlock_irqrestore(&bp->lock, flags);
XXDEBUG(("bmac: exit set_address\n"));
return 0;
}
static inline void bmac_set_timeout(struct net_device *dev)
{
struct bmac_data *bp = netdev_priv(dev);
unsigned long flags;
spin_lock_irqsave(&bp->lock, flags);
if (bp->timeout_active)
del_timer(&bp->tx_timeout);
bp->tx_timeout.expires = jiffies + TX_TIMEOUT;
bp->tx_timeout.function = bmac_tx_timeout;
bp->tx_timeout.data = (unsigned long) dev;
add_timer(&bp->tx_timeout);
bp->timeout_active = 1;
spin_unlock_irqrestore(&bp->lock, flags);
}
static void
bmac_construct_xmt(struct sk_buff *skb, volatile struct dbdma_cmd *cp)
{
void *vaddr;
unsigned long baddr;
unsigned long len;
len = skb->len;
vaddr = skb->data;
baddr = virt_to_bus(vaddr);
dbdma_setcmd(cp, (OUTPUT_LAST | INTR_ALWAYS | WAIT_IFCLR), len, baddr, 0);
}
static void
bmac_construct_rxbuff(struct sk_buff *skb, volatile struct dbdma_cmd *cp)
{
unsigned char *addr = skb? skb->data: bmac_emergency_rxbuf;
dbdma_setcmd(cp, (INPUT_LAST | INTR_ALWAYS), RX_BUFLEN,
virt_to_bus(addr), 0);
}
static void
bmac_init_tx_ring(struct bmac_data *bp)
{
volatile struct dbdma_regs __iomem *td = bp->tx_dma;
memset((char *)bp->tx_cmds, 0, (N_TX_RING+1) * sizeof(struct dbdma_cmd));
bp->tx_empty = 0;
bp->tx_fill = 0;
bp->tx_fullup = 0;
dbdma_setcmd(&bp->tx_cmds[N_TX_RING],
(DBDMA_NOP | BR_ALWAYS), 0, 0, virt_to_bus(bp->tx_cmds));
dbdma_reset(td);
out_le32(&td->wait_sel, 0x00200020);
out_le32(&td->cmdptr, virt_to_bus(bp->tx_cmds));
}
static int
bmac_init_rx_ring(struct net_device *dev)
{
struct bmac_data *bp = netdev_priv(dev);
volatile struct dbdma_regs __iomem *rd = bp->rx_dma;
int i;
struct sk_buff *skb;
memset((char *)bp->rx_cmds, 0,
(N_RX_RING + 1) * sizeof(struct dbdma_cmd));
for (i = 0; i < N_RX_RING; i++) {
if ((skb = bp->rx_bufs[i]) == NULL) {
bp->rx_bufs[i] = skb = netdev_alloc_skb(dev, RX_BUFLEN + 2);
if (skb != NULL)
skb_reserve(skb, 2);
}
bmac_construct_rxbuff(skb, &bp->rx_cmds[i]);
}
bp->rx_empty = 0;
bp->rx_fill = i;
dbdma_setcmd(&bp->rx_cmds[N_RX_RING],
(DBDMA_NOP | BR_ALWAYS), 0, 0, virt_to_bus(bp->rx_cmds));
dbdma_reset(rd);
out_le32(&rd->cmdptr, virt_to_bus(bp->rx_cmds));
return 1;
}
static int bmac_transmit_packet(struct sk_buff *skb, struct net_device *dev)
{
struct bmac_data *bp = netdev_priv(dev);
volatile struct dbdma_regs __iomem *td = bp->tx_dma;
int i;
i = bp->tx_fill + 1;
if (i >= N_TX_RING)
i = 0;
if (i == bp->tx_empty) {
netif_stop_queue(dev);
bp->tx_fullup = 1;
XXDEBUG(("bmac_transmit_packet: tx ring full\n"));
return -1;
}
dbdma_setcmd(&bp->tx_cmds[i], DBDMA_STOP, 0, 0, 0);
bmac_construct_xmt(skb, &bp->tx_cmds[bp->tx_fill]);
bp->tx_bufs[bp->tx_fill] = skb;
bp->tx_fill = i;
dev->stats.tx_bytes += skb->len;
dbdma_continue(td);
return 0;
}
static irqreturn_t bmac_rxdma_intr(int irq, void *dev_id)
{
struct net_device *dev = (struct net_device *) dev_id;
struct bmac_data *bp = netdev_priv(dev);
volatile struct dbdma_regs __iomem *rd = bp->rx_dma;
volatile struct dbdma_cmd *cp;
int i, nb, stat;
struct sk_buff *skb;
unsigned int residual;
int last;
unsigned long flags;
spin_lock_irqsave(&bp->lock, flags);
if (++rxintcount < 10) {
XXDEBUG(("bmac_rxdma_intr\n"));
}
last = -1;
i = bp->rx_empty;
while (1) {
cp = &bp->rx_cmds[i];
stat = ld_le16(&cp->xfer_status);
residual = ld_le16(&cp->res_count);
if ((stat & ACTIVE) == 0)
break;
nb = RX_BUFLEN - residual - 2;
if (nb < (ETHERMINPACKET - ETHERCRC)) {
skb = NULL;
dev->stats.rx_length_errors++;
dev->stats.rx_errors++;
} else {
skb = bp->rx_bufs[i];
bp->rx_bufs[i] = NULL;
}
if (skb != NULL) {
nb -= ETHERCRC;
skb_put(skb, nb);
skb->protocol = eth_type_trans(skb, dev);
netif_rx(skb);
++dev->stats.rx_packets;
dev->stats.rx_bytes += nb;
} else {
++dev->stats.rx_dropped;
}
if ((skb = bp->rx_bufs[i]) == NULL) {
bp->rx_bufs[i] = skb = netdev_alloc_skb(dev, RX_BUFLEN + 2);
if (skb != NULL)
skb_reserve(bp->rx_bufs[i], 2);
}
bmac_construct_rxbuff(skb, &bp->rx_cmds[i]);
st_le16(&cp->res_count, 0);
st_le16(&cp->xfer_status, 0);
last = i;
if (++i >= N_RX_RING) i = 0;
}
if (last != -1) {
bp->rx_fill = last;
bp->rx_empty = i;
}
dbdma_continue(rd);
spin_unlock_irqrestore(&bp->lock, flags);
if (rxintcount < 10) {
XXDEBUG(("bmac_rxdma_intr done\n"));
}
return IRQ_HANDLED;
}
static irqreturn_t bmac_txdma_intr(int irq, void *dev_id)
{
struct net_device *dev = (struct net_device *) dev_id;
struct bmac_data *bp = netdev_priv(dev);
volatile struct dbdma_cmd *cp;
int stat;
unsigned long flags;
spin_lock_irqsave(&bp->lock, flags);
if (txintcount++ < 10) {
XXDEBUG(("bmac_txdma_intr\n"));
}
while (1) {
cp = &bp->tx_cmds[bp->tx_empty];
stat = ld_le16(&cp->xfer_status);
if (txintcount < 10) {
XXDEBUG(("bmac_txdma_xfer_stat=%#0x\n", stat));
}
if (!(stat & ACTIVE)) {
if (cp == bus_to_virt(in_le32(&bp->tx_dma->cmdptr)))
break;
}
if (bp->tx_bufs[bp->tx_empty]) {
++dev->stats.tx_packets;
dev_kfree_skb_irq(bp->tx_bufs[bp->tx_empty]);
}
bp->tx_bufs[bp->tx_empty] = NULL;
bp->tx_fullup = 0;
netif_wake_queue(dev);
if (++bp->tx_empty >= N_TX_RING)
bp->tx_empty = 0;
if (bp->tx_empty == bp->tx_fill)
break;
}
spin_unlock_irqrestore(&bp->lock, flags);
if (txintcount < 10) {
XXDEBUG(("bmac_txdma_intr done->bmac_start\n"));
}
bmac_start(dev);
return IRQ_HANDLED;
}
static unsigned int
crc416(unsigned int curval, unsigned short nxtval)
{
register unsigned int counter, cur = curval, next = nxtval;
register int high_crc_set, low_data_set;
next = ((next & 0x00FF) << 8) | (next >> 8);
for (counter = 0; counter < 16; ++counter) {
if ((cur & 0x80000000) == 0) high_crc_set = 0;
else high_crc_set = 1;
cur = cur << 1;
if ((next & 0x0001) == 0) low_data_set = 0;
else low_data_set = 1;
next = next >> 1;
if (high_crc_set ^ low_data_set) cur = cur ^ ENET_CRCPOLY;
}
return cur;
}
static unsigned int
bmac_crc(unsigned short *address)
{
unsigned int newcrc;
XXDEBUG(("bmac_crc: addr=%#04x, %#04x, %#04x\n", *address, address[1], address[2]));
newcrc = crc416(0xffffffff, *address);
newcrc = crc416(newcrc, address[1]);
newcrc = crc416(newcrc, address[2]);
return(newcrc);
}
static void
bmac_addhash(struct bmac_data *bp, unsigned char *addr)
{
unsigned int crc;
unsigned short mask;
if (!(*addr)) return;
crc = bmac_crc((unsigned short *)addr) & 0x3f;
crc = reverse6[crc];
if (bp->hash_use_count[crc]++) return;
mask = crc % 16;
mask = (unsigned char)1 << mask;
bp->hash_use_count[crc/16] |= mask;
}
static void
bmac_removehash(struct bmac_data *bp, unsigned char *addr)
{
unsigned int crc;
unsigned char mask;
crc = bmac_crc((unsigned short *)addr) & 0x3f;
crc = reverse6[crc];
if (bp->hash_use_count[crc] == 0) return;
if (--bp->hash_use_count[crc]) return;
mask = crc % 16;
mask = ((unsigned char)1 << mask) ^ 0xffff;
bp->hash_table_mask[crc/16] &= mask;
}
static void
bmac_rx_off(struct net_device *dev)
{
unsigned short rx_cfg;
rx_cfg = bmread(dev, RXCFG);
rx_cfg &= ~RxMACEnable;
bmwrite(dev, RXCFG, rx_cfg);
do {
rx_cfg = bmread(dev, RXCFG);
} while (rx_cfg & RxMACEnable);
}
unsigned short
bmac_rx_on(struct net_device *dev, int hash_enable, int promisc_enable)
{
unsigned short rx_cfg;
rx_cfg = bmread(dev, RXCFG);
rx_cfg |= RxMACEnable;
if (hash_enable) rx_cfg |= RxHashFilterEnable;
else rx_cfg &= ~RxHashFilterEnable;
if (promisc_enable) rx_cfg |= RxPromiscEnable;
else rx_cfg &= ~RxPromiscEnable;
bmwrite(dev, RXRST, RxResetValue);
bmwrite(dev, RXFIFOCSR, 0);
bmwrite(dev, RXFIFOCSR, RxFIFOEnable );
bmwrite(dev, RXCFG, rx_cfg );
return rx_cfg;
}
static void
bmac_update_hash_table_mask(struct net_device *dev, struct bmac_data *bp)
{
bmwrite(dev, BHASH3, bp->hash_table_mask[0]);
bmwrite(dev, BHASH2, bp->hash_table_mask[1]);
bmwrite(dev, BHASH1, bp->hash_table_mask[2]);
bmwrite(dev, BHASH0, bp->hash_table_mask[3]);
}
static void bmac_set_multicast(struct net_device *dev)
{
struct netdev_hw_addr *ha;
struct bmac_data *bp = netdev_priv(dev);
int num_addrs = netdev_mc_count(dev);
unsigned short rx_cfg;
int i;
if (bp->sleeping)
return;
XXDEBUG(("bmac: enter bmac_set_multicast, n_addrs=%d\n", num_addrs));
if((dev->flags & IFF_ALLMULTI) || (netdev_mc_count(dev) > 64)) {
for (i=0; i<4; i++) bp->hash_table_mask[i] = 0xffff;
bmac_update_hash_table_mask(dev, bp);
rx_cfg = bmac_rx_on(dev, 1, 0);
XXDEBUG(("bmac: all multi, rx_cfg=%#08x\n"));
} else if ((dev->flags & IFF_PROMISC) || (num_addrs < 0)) {
rx_cfg = bmread(dev, RXCFG);
rx_cfg |= RxPromiscEnable;
bmwrite(dev, RXCFG, rx_cfg);
rx_cfg = bmac_rx_on(dev, 0, 1);
XXDEBUG(("bmac: promisc mode enabled, rx_cfg=%#08x\n", rx_cfg));
} else {
for (i=0; i<4; i++) bp->hash_table_mask[i] = 0;
for (i=0; i<64; i++) bp->hash_use_count[i] = 0;
if (num_addrs == 0) {
rx_cfg = bmac_rx_on(dev, 0, 0);
XXDEBUG(("bmac: multi disabled, rx_cfg=%#08x\n", rx_cfg));
} else {
netdev_for_each_mc_addr(ha, dev)
bmac_addhash(bp, ha->addr);
bmac_update_hash_table_mask(dev, bp);
rx_cfg = bmac_rx_on(dev, 1, 0);
XXDEBUG(("bmac: multi enabled, rx_cfg=%#08x\n", rx_cfg));
}
}
}
static void bmac_set_multicast(struct net_device *dev)
{
struct netdev_hw_addr *ha;
unsigned short rx_cfg;
u32 crc;
if((dev->flags & IFF_ALLMULTI) || (netdev_mc_count(dev) > 64)) {
bmwrite(dev, BHASH0, 0xffff);
bmwrite(dev, BHASH1, 0xffff);
bmwrite(dev, BHASH2, 0xffff);
bmwrite(dev, BHASH3, 0xffff);
} else if(dev->flags & IFF_PROMISC) {
rx_cfg = bmread(dev, RXCFG);
rx_cfg |= RxPromiscEnable;
bmwrite(dev, RXCFG, rx_cfg);
} else {
u16 hash_table[4] = { 0 };
rx_cfg = bmread(dev, RXCFG);
rx_cfg &= ~RxPromiscEnable;
bmwrite(dev, RXCFG, rx_cfg);
netdev_for_each_mc_addr(ha, dev) {
crc = ether_crc_le(6, ha->addr);
crc >>= 26;
hash_table[crc >> 4] |= 1 << (crc & 0xf);
}
bmwrite(dev, BHASH0, hash_table[0]);
bmwrite(dev, BHASH1, hash_table[1]);
bmwrite(dev, BHASH2, hash_table[2]);
bmwrite(dev, BHASH3, hash_table[3]);
}
}
static irqreturn_t bmac_misc_intr(int irq, void *dev_id)
{
struct net_device *dev = (struct net_device *) dev_id;
unsigned int status = bmread(dev, STATUS);
if (miscintcount++ < 10) {
XXDEBUG(("bmac_misc_intr\n"));
}
if (status & RxErrorMask) dev->stats.rx_errors++;
if (status & RxCRCCntExp) dev->stats.rx_crc_errors++;
if (status & RxLenCntExp) dev->stats.rx_length_errors++;
if (status & RxOverFlow) dev->stats.rx_over_errors++;
if (status & RxAlignCntExp) dev->stats.rx_frame_errors++;
if (status & TxErrorMask) dev->stats.tx_errors++;
if (status & TxUnderrun) dev->stats.tx_fifo_errors++;
if (status & TxNormalCollExp) dev->stats.collisions++;
return IRQ_HANDLED;
}
static unsigned char
bmac_clock_out_bit(struct net_device *dev)
{
unsigned short data;
unsigned short val;
bmwrite(dev, SROMCSR, ChipSelect | Clk);
udelay(DelayValue);
data = bmread(dev, SROMCSR);
udelay(DelayValue);
val = (data >> SD0ShiftCount) & 1;
bmwrite(dev, SROMCSR, ChipSelect);
udelay(DelayValue);
return val;
}
static void
bmac_clock_in_bit(struct net_device *dev, unsigned int val)
{
unsigned short data;
if (val != 0 && val != 1) return;
data = (val << SDIShiftCount);
bmwrite(dev, SROMCSR, data | ChipSelect );
udelay(DelayValue);
bmwrite(dev, SROMCSR, data | ChipSelect | Clk );
udelay(DelayValue);
bmwrite(dev, SROMCSR, data | ChipSelect);
udelay(DelayValue);
}
static void
reset_and_select_srom(struct net_device *dev)
{
bmwrite(dev, SROMCSR, 0);
udelay(DelayValue);
bmac_clock_in_bit(dev, 1);
bmac_clock_in_bit(dev, 1);
bmac_clock_in_bit(dev, 0);
}
static unsigned short
read_srom(struct net_device *dev, unsigned int addr, unsigned int addr_len)
{
unsigned short data, val;
int i;
for (i = 0; i < addr_len; i++) {
val = addr >> (addr_len-i-1);
bmac_clock_in_bit(dev, val & 1);
}
data = 0;
for (i = 0; i < 16; i++) {
val = bmac_clock_out_bit(dev);
data <<= 1;
data |= val;
}
bmwrite(dev, SROMCSR, 0);
return data;
}
static int
bmac_verify_checksum(struct net_device *dev)
{
unsigned short data, storedCS;
reset_and_select_srom(dev);
data = read_srom(dev, 3, SROMAddressBits);
storedCS = ((data >> 8) & 0x0ff) | ((data << 8) & 0xff00);
return 0;
}
static void
bmac_get_station_address(struct net_device *dev, unsigned char *ea)
{
int i;
unsigned short data;
for (i = 0; i < 6; i++)
{
reset_and_select_srom(dev);
data = read_srom(dev, i + EnetAddressOffset/2, SROMAddressBits);
ea[2*i] = bitrev8(data & 0x0ff);
ea[2*i+1] = bitrev8((data >> 8) & 0x0ff);
}
}
static void bmac_reset_and_enable(struct net_device *dev)
{
struct bmac_data *bp = netdev_priv(dev);
unsigned long flags;
struct sk_buff *skb;
unsigned char *data;
spin_lock_irqsave(&bp->lock, flags);
bmac_enable_and_reset_chip(dev);
bmac_init_tx_ring(bp);
bmac_init_rx_ring(dev);
bmac_init_chip(dev);
bmac_start_chip(dev);
bmwrite(dev, INTDISABLE, EnableNormal);
bp->sleeping = 0;
skb = netdev_alloc_skb(dev, ETHERMINPACKET);
if (skb != NULL) {
data = skb_put(skb, ETHERMINPACKET);
memset(data, 0, ETHERMINPACKET);
memcpy(data, dev->dev_addr, 6);
memcpy(data+6, dev->dev_addr, 6);
bmac_transmit_packet(skb, dev);
}
spin_unlock_irqrestore(&bp->lock, flags);
}
static int bmac_probe(struct macio_dev *mdev, const struct of_device_id *match)
{
int j, rev, ret;
struct bmac_data *bp;
const unsigned char *prop_addr;
unsigned char addr[6];
struct net_device *dev;
int is_bmac_plus = ((int)match->data) != 0;
if (macio_resource_count(mdev) != 3 || macio_irq_count(mdev) != 3) {
printk(KERN_ERR "BMAC: can't use, need 3 addrs and 3 intrs\n");
return -ENODEV;
}
prop_addr = of_get_property(macio_get_of_node(mdev),
"mac-address", NULL);
if (prop_addr == NULL) {
prop_addr = of_get_property(macio_get_of_node(mdev),
"local-mac-address", NULL);
if (prop_addr == NULL) {
printk(KERN_ERR "BMAC: Can't get mac-address\n");
return -ENODEV;
}
}
memcpy(addr, prop_addr, sizeof(addr));
dev = alloc_etherdev(PRIV_BYTES);
if (!dev)
return -ENOMEM;
bp = netdev_priv(dev);
SET_NETDEV_DEV(dev, &mdev->ofdev.dev);
macio_set_drvdata(mdev, dev);
bp->mdev = mdev;
spin_lock_init(&bp->lock);
if (macio_request_resources(mdev, "bmac")) {
printk(KERN_ERR "BMAC: can't request IO resource !\n");
goto out_free;
}
dev->base_addr = (unsigned long)
ioremap(macio_resource_start(mdev, 0), macio_resource_len(mdev, 0));
if (dev->base_addr == 0)
goto out_release;
dev->irq = macio_irq(mdev, 0);
bmac_enable_and_reset_chip(dev);
bmwrite(dev, INTDISABLE, DisableAll);
rev = addr[0] == 0 && addr[1] == 0xA0;
for (j = 0; j < 6; ++j)
dev->dev_addr[j] = rev ? bitrev8(addr[j]): addr[j];
bmac_enable_and_reset_chip(dev);
bmwrite(dev, INTDISABLE, DisableAll);
dev->netdev_ops = &bmac_netdev_ops;
dev->ethtool_ops = &bmac_ethtool_ops;
bmac_get_station_address(dev, addr);
if (bmac_verify_checksum(dev) != 0)
goto err_out_iounmap;
bp->is_bmac_plus = is_bmac_plus;
bp->tx_dma = ioremap(macio_resource_start(mdev, 1), macio_resource_len(mdev, 1));
if (!bp->tx_dma)
goto err_out_iounmap;
bp->tx_dma_intr = macio_irq(mdev, 1);
bp->rx_dma = ioremap(macio_resource_start(mdev, 2), macio_resource_len(mdev, 2));
if (!bp->rx_dma)
goto err_out_iounmap_tx;
bp->rx_dma_intr = macio_irq(mdev, 2);
bp->tx_cmds = (volatile struct dbdma_cmd *) DBDMA_ALIGN(bp + 1);
bp->rx_cmds = bp->tx_cmds + N_TX_RING + 1;
bp->queue = (struct sk_buff_head *)(bp->rx_cmds + N_RX_RING + 1);
skb_queue_head_init(bp->queue);
init_timer(&bp->tx_timeout);
ret = request_irq(dev->irq, bmac_misc_intr, 0, "BMAC-misc", dev);
if (ret) {
printk(KERN_ERR "BMAC: can't get irq %d\n", dev->irq);
goto err_out_iounmap_rx;
}
ret = request_irq(bp->tx_dma_intr, bmac_txdma_intr, 0, "BMAC-txdma", dev);
if (ret) {
printk(KERN_ERR "BMAC: can't get irq %d\n", bp->tx_dma_intr);
goto err_out_irq0;
}
ret = request_irq(bp->rx_dma_intr, bmac_rxdma_intr, 0, "BMAC-rxdma", dev);
if (ret) {
printk(KERN_ERR "BMAC: can't get irq %d\n", bp->rx_dma_intr);
goto err_out_irq1;
}
disable_irq(dev->irq);
pmac_call_feature(PMAC_FTR_BMAC_ENABLE, macio_get_of_node(bp->mdev), 0, 0);
if (register_netdev(dev) != 0) {
printk(KERN_ERR "BMAC: Ethernet registration failed\n");
goto err_out_irq2;
}
printk(KERN_INFO "%s: BMAC%s at %pM",
dev->name, (is_bmac_plus ? "+" : ""), dev->dev_addr);
XXDEBUG((", base_addr=%#0lx", dev->base_addr));
printk("\n");
return 0;
err_out_irq2:
free_irq(bp->rx_dma_intr, dev);
err_out_irq1:
free_irq(bp->tx_dma_intr, dev);
err_out_irq0:
free_irq(dev->irq, dev);
err_out_iounmap_rx:
iounmap(bp->rx_dma);
err_out_iounmap_tx:
iounmap(bp->tx_dma);
err_out_iounmap:
iounmap((void __iomem *)dev->base_addr);
out_release:
macio_release_resources(mdev);
out_free:
pmac_call_feature(PMAC_FTR_BMAC_ENABLE, macio_get_of_node(bp->mdev), 0, 0);
free_netdev(dev);
return -ENODEV;
}
static int bmac_open(struct net_device *dev)
{
struct bmac_data *bp = netdev_priv(dev);
bp->opened = 1;
bmac_reset_and_enable(dev);
enable_irq(dev->irq);
return 0;
}
static int bmac_close(struct net_device *dev)
{
struct bmac_data *bp = netdev_priv(dev);
volatile struct dbdma_regs __iomem *rd = bp->rx_dma;
volatile struct dbdma_regs __iomem *td = bp->tx_dma;
unsigned short config;
int i;
bp->sleeping = 1;
config = bmread(dev, RXCFG);
bmwrite(dev, RXCFG, (config & ~RxMACEnable));
config = bmread(dev, TXCFG);
bmwrite(dev, TXCFG, (config & ~TxMACEnable));
bmwrite(dev, INTDISABLE, DisableAll);
st_le32(&rd->control, DBDMA_CLEAR(RUN|PAUSE|FLUSH|WAKE));
st_le32(&td->control, DBDMA_CLEAR(RUN|PAUSE|FLUSH|WAKE));
XXDEBUG(("bmac: free rx bufs\n"));
for (i=0; i<N_RX_RING; i++) {
if (bp->rx_bufs[i] != NULL) {
dev_kfree_skb(bp->rx_bufs[i]);
bp->rx_bufs[i] = NULL;
}
}
XXDEBUG(("bmac: free tx bufs\n"));
for (i = 0; i<N_TX_RING; i++) {
if (bp->tx_bufs[i] != NULL) {
dev_kfree_skb(bp->tx_bufs[i]);
bp->tx_bufs[i] = NULL;
}
}
XXDEBUG(("bmac: all bufs freed\n"));
bp->opened = 0;
disable_irq(dev->irq);
pmac_call_feature(PMAC_FTR_BMAC_ENABLE, macio_get_of_node(bp->mdev), 0, 0);
return 0;
}
static void
bmac_start(struct net_device *dev)
{
struct bmac_data *bp = netdev_priv(dev);
int i;
struct sk_buff *skb;
unsigned long flags;
if (bp->sleeping)
return;
spin_lock_irqsave(&bp->lock, flags);
while (1) {
i = bp->tx_fill + 1;
if (i >= N_TX_RING)
i = 0;
if (i == bp->tx_empty)
break;
skb = skb_dequeue(bp->queue);
if (skb == NULL)
break;
bmac_transmit_packet(skb, dev);
}
spin_unlock_irqrestore(&bp->lock, flags);
}
static int
bmac_output(struct sk_buff *skb, struct net_device *dev)
{
struct bmac_data *bp = netdev_priv(dev);
skb_queue_tail(bp->queue, skb);
bmac_start(dev);
return NETDEV_TX_OK;
}
static void bmac_tx_timeout(unsigned long data)
{
struct net_device *dev = (struct net_device *) data;
struct bmac_data *bp = netdev_priv(dev);
volatile struct dbdma_regs __iomem *td = bp->tx_dma;
volatile struct dbdma_regs __iomem *rd = bp->rx_dma;
volatile struct dbdma_cmd *cp;
unsigned long flags;
unsigned short config, oldConfig;
int i;
XXDEBUG(("bmac: tx_timeout called\n"));
spin_lock_irqsave(&bp->lock, flags);
bp->timeout_active = 0;
cp = &bp->tx_cmds[bp->tx_empty];
config = bmread(dev, RXCFG);
bmwrite(dev, RXCFG, (config & ~RxMACEnable));
config = bmread(dev, TXCFG);
bmwrite(dev, TXCFG, (config & ~TxMACEnable));
out_le32(&td->control, DBDMA_CLEAR(RUN|PAUSE|FLUSH|WAKE|ACTIVE|DEAD));
printk(KERN_ERR "bmac: transmit timeout - resetting\n");
bmac_enable_and_reset_chip(dev);
cp = bus_to_virt(ld_le32(&rd->cmdptr));
out_le32(&rd->control, DBDMA_CLEAR(RUN|PAUSE|FLUSH|WAKE|ACTIVE|DEAD));
out_le16(&cp->xfer_status, 0);
out_le32(&rd->cmdptr, virt_to_bus(cp));
out_le32(&rd->control, DBDMA_SET(RUN|WAKE));
XXDEBUG((KERN_DEBUG "bmac: tx empty=%d fill=%d fullup=%d\n",
bp->tx_empty, bp->tx_fill, bp->tx_fullup));
i = bp->tx_empty;
++dev->stats.tx_errors;
if (i != bp->tx_fill) {
dev_kfree_skb(bp->tx_bufs[i]);
bp->tx_bufs[i] = NULL;
if (++i >= N_TX_RING) i = 0;
bp->tx_empty = i;
}
bp->tx_fullup = 0;
netif_wake_queue(dev);
if (i != bp->tx_fill) {
cp = &bp->tx_cmds[i];
out_le16(&cp->xfer_status, 0);
out_le16(&cp->command, OUTPUT_LAST);
out_le32(&td->cmdptr, virt_to_bus(cp));
out_le32(&td->control, DBDMA_SET(RUN));
XXDEBUG((KERN_DEBUG "bmac: starting %d\n", i));
}
oldConfig = bmread(dev, RXCFG);
bmwrite(dev, RXCFG, oldConfig | RxMACEnable );
oldConfig = bmread(dev, TXCFG);
bmwrite(dev, TXCFG, oldConfig | TxMACEnable );
spin_unlock_irqrestore(&bp->lock, flags);
}
static int bmac_remove(struct macio_dev *mdev)
{
struct net_device *dev = macio_get_drvdata(mdev);
struct bmac_data *bp = netdev_priv(dev);
unregister_netdev(dev);
free_irq(dev->irq, dev);
free_irq(bp->tx_dma_intr, dev);
free_irq(bp->rx_dma_intr, dev);
iounmap((void __iomem *)dev->base_addr);
iounmap(bp->tx_dma);
iounmap(bp->rx_dma);
macio_release_resources(mdev);
free_netdev(dev);
return 0;
}
static int __init bmac_init(void)
{
if (bmac_emergency_rxbuf == NULL) {
bmac_emergency_rxbuf = kmalloc(RX_BUFLEN, GFP_KERNEL);
if (bmac_emergency_rxbuf == NULL)
return -ENOMEM;
}
return macio_register_driver(&bmac_driver);
}
static void __exit bmac_exit(void)
{
macio_unregister_driver(&bmac_driver);
kfree(bmac_emergency_rxbuf);
bmac_emergency_rxbuf = NULL;
}
