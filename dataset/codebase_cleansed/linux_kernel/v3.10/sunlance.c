static void load_csrs(struct lance_private *lp)
{
u32 leptr;
if (lp->pio_buffer)
leptr = 0;
else
leptr = LANCE_ADDR(lp->init_block_dvma);
sbus_writew(LE_CSR1, lp->lregs + RAP);
sbus_writew(leptr & 0xffff, lp->lregs + RDP);
sbus_writew(LE_CSR2, lp->lregs + RAP);
sbus_writew(leptr >> 16, lp->lregs + RDP);
sbus_writew(LE_CSR3, lp->lregs + RAP);
sbus_writew(lp->busmaster_regval, lp->lregs + RDP);
sbus_writew(LE_CSR0, lp->lregs + RAP);
}
static void lance_init_ring_dvma(struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
struct lance_init_block *ib = lp->init_block_mem;
dma_addr_t aib = lp->init_block_dvma;
__u32 leptr;
int i;
netif_stop_queue(dev);
lp->rx_new = lp->tx_new = 0;
lp->rx_old = lp->tx_old = 0;
ib->phys_addr [0] = dev->dev_addr [1];
ib->phys_addr [1] = dev->dev_addr [0];
ib->phys_addr [2] = dev->dev_addr [3];
ib->phys_addr [3] = dev->dev_addr [2];
ib->phys_addr [4] = dev->dev_addr [5];
ib->phys_addr [5] = dev->dev_addr [4];
for (i = 0; i < TX_RING_SIZE; i++) {
leptr = LANCE_ADDR(aib + libbuff_offset(tx_buf, i));
ib->btx_ring [i].tmd0 = leptr;
ib->btx_ring [i].tmd1_hadr = leptr >> 16;
ib->btx_ring [i].tmd1_bits = 0;
ib->btx_ring [i].length = 0xf000;
ib->btx_ring [i].misc = 0;
}
for (i = 0; i < RX_RING_SIZE; i++) {
leptr = LANCE_ADDR(aib + libbuff_offset(rx_buf, i));
ib->brx_ring [i].rmd0 = leptr;
ib->brx_ring [i].rmd1_hadr = leptr >> 16;
ib->brx_ring [i].rmd1_bits = LE_R1_OWN;
ib->brx_ring [i].length = -RX_BUFF_SIZE | 0xf000;
ib->brx_ring [i].mblength = 0;
}
leptr = LANCE_ADDR(aib + libdesc_offset(brx_ring, 0));
ib->rx_len = (LANCE_LOG_RX_BUFFERS << 13) | (leptr >> 16);
ib->rx_ptr = leptr;
leptr = LANCE_ADDR(aib + libdesc_offset(btx_ring, 0));
ib->tx_len = (LANCE_LOG_TX_BUFFERS << 13) | (leptr >> 16);
ib->tx_ptr = leptr;
}
static void lance_init_ring_pio(struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
struct lance_init_block __iomem *ib = lp->init_block_iomem;
u32 leptr;
int i;
netif_stop_queue(dev);
lp->rx_new = lp->tx_new = 0;
lp->rx_old = lp->tx_old = 0;
sbus_writeb(dev->dev_addr[1], &ib->phys_addr[0]);
sbus_writeb(dev->dev_addr[0], &ib->phys_addr[1]);
sbus_writeb(dev->dev_addr[3], &ib->phys_addr[2]);
sbus_writeb(dev->dev_addr[2], &ib->phys_addr[3]);
sbus_writeb(dev->dev_addr[5], &ib->phys_addr[4]);
sbus_writeb(dev->dev_addr[4], &ib->phys_addr[5]);
for (i = 0; i < TX_RING_SIZE; i++) {
leptr = libbuff_offset(tx_buf, i);
sbus_writew(leptr, &ib->btx_ring [i].tmd0);
sbus_writeb(leptr >> 16,&ib->btx_ring [i].tmd1_hadr);
sbus_writeb(0, &ib->btx_ring [i].tmd1_bits);
sbus_writew(0xf000, &ib->btx_ring [i].length);
sbus_writew(0, &ib->btx_ring [i].misc);
}
for (i = 0; i < RX_RING_SIZE; i++) {
leptr = libbuff_offset(rx_buf, i);
sbus_writew(leptr, &ib->brx_ring [i].rmd0);
sbus_writeb(leptr >> 16,&ib->brx_ring [i].rmd1_hadr);
sbus_writeb(LE_R1_OWN, &ib->brx_ring [i].rmd1_bits);
sbus_writew(-RX_BUFF_SIZE|0xf000,
&ib->brx_ring [i].length);
sbus_writew(0, &ib->brx_ring [i].mblength);
}
leptr = libdesc_offset(brx_ring, 0);
sbus_writew((LANCE_LOG_RX_BUFFERS << 13) | (leptr >> 16),
&ib->rx_len);
sbus_writew(leptr, &ib->rx_ptr);
leptr = libdesc_offset(btx_ring, 0);
sbus_writew((LANCE_LOG_TX_BUFFERS << 13) | (leptr >> 16),
&ib->tx_len);
sbus_writew(leptr, &ib->tx_ptr);
}
static void init_restart_ledma(struct lance_private *lp)
{
u32 csr = sbus_readl(lp->dregs + DMA_CSR);
if (!(csr & DMA_HNDL_ERROR)) {
while (sbus_readl(lp->dregs + DMA_CSR) & DMA_FIFO_ISDRAIN)
barrier();
}
csr = sbus_readl(lp->dregs + DMA_CSR);
csr &= ~DMA_E_BURSTS;
if (lp->burst_sizes & DMA_BURST32)
csr |= DMA_E_BURST32;
else
csr |= DMA_E_BURST16;
csr |= (DMA_DSBL_RD_DRN | DMA_DSBL_WR_INV | DMA_FIFO_INV);
if (lp->tpe)
csr |= DMA_EN_ENETAUI;
else
csr &= ~DMA_EN_ENETAUI;
udelay(20);
sbus_writel(csr, lp->dregs + DMA_CSR);
udelay(200);
}
static int init_restart_lance(struct lance_private *lp)
{
u16 regval = 0;
int i;
if (lp->dregs)
init_restart_ledma(lp);
sbus_writew(LE_CSR0, lp->lregs + RAP);
sbus_writew(LE_C0_INIT, lp->lregs + RDP);
for (i = 0; i < 100; i++) {
regval = sbus_readw(lp->lregs + RDP);
if (regval & (LE_C0_ERR | LE_C0_IDON))
break;
barrier();
}
if (i == 100 || (regval & LE_C0_ERR)) {
printk(KERN_ERR "LANCE unopened after %d ticks, csr0=%4.4x.\n",
i, regval);
if (lp->dregs)
printk("dcsr=%8.8x\n", sbus_readl(lp->dregs + DMA_CSR));
return -1;
}
sbus_writew(LE_C0_IDON, lp->lregs + RDP);
sbus_writew(LE_C0_INEA | LE_C0_STRT, lp->lregs + RDP);
if (lp->dregs) {
u32 csr = sbus_readl(lp->dregs + DMA_CSR);
csr |= DMA_INT_ENAB;
sbus_writel(csr, lp->dregs + DMA_CSR);
}
return 0;
}
static void lance_rx_dvma(struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
struct lance_init_block *ib = lp->init_block_mem;
struct lance_rx_desc *rd;
u8 bits;
int len, entry = lp->rx_new;
struct sk_buff *skb;
for (rd = &ib->brx_ring [entry];
!((bits = rd->rmd1_bits) & LE_R1_OWN);
rd = &ib->brx_ring [entry]) {
if ((bits & LE_R1_POK) != LE_R1_POK) {
dev->stats.rx_over_errors++;
dev->stats.rx_errors++;
} else if (bits & LE_R1_ERR) {
if (bits & LE_R1_BUF) dev->stats.rx_fifo_errors++;
if (bits & LE_R1_CRC) dev->stats.rx_crc_errors++;
if (bits & LE_R1_OFL) dev->stats.rx_over_errors++;
if (bits & LE_R1_FRA) dev->stats.rx_frame_errors++;
if (bits & LE_R1_EOP) dev->stats.rx_errors++;
} else {
len = (rd->mblength & 0xfff) - 4;
skb = netdev_alloc_skb(dev, len + 2);
if (skb == NULL) {
dev->stats.rx_dropped++;
rd->mblength = 0;
rd->rmd1_bits = LE_R1_OWN;
lp->rx_new = RX_NEXT(entry);
return;
}
dev->stats.rx_bytes += len;
skb_reserve(skb, 2);
skb_put(skb, len);
skb_copy_to_linear_data(skb,
(unsigned char *)&(ib->rx_buf [entry][0]),
len);
skb->protocol = eth_type_trans(skb, dev);
netif_rx(skb);
dev->stats.rx_packets++;
}
rd->mblength = 0;
rd->rmd1_bits = LE_R1_OWN;
entry = RX_NEXT(entry);
}
lp->rx_new = entry;
}
static void lance_tx_dvma(struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
struct lance_init_block *ib = lp->init_block_mem;
int i, j;
spin_lock(&lp->lock);
j = lp->tx_old;
for (i = j; i != lp->tx_new; i = j) {
struct lance_tx_desc *td = &ib->btx_ring [i];
u8 bits = td->tmd1_bits;
if (bits & LE_T1_OWN)
break;
if (bits & LE_T1_ERR) {
u16 status = td->misc;
dev->stats.tx_errors++;
if (status & LE_T3_RTY) dev->stats.tx_aborted_errors++;
if (status & LE_T3_LCOL) dev->stats.tx_window_errors++;
if (status & LE_T3_CLOS) {
dev->stats.tx_carrier_errors++;
if (lp->auto_select) {
lp->tpe = 1 - lp->tpe;
printk(KERN_NOTICE "%s: Carrier Lost, trying %s\n",
dev->name, lp->tpe?"TPE":"AUI");
STOP_LANCE(lp);
lp->init_ring(dev);
load_csrs(lp);
init_restart_lance(lp);
goto out;
}
}
if (status & (LE_T3_BUF|LE_T3_UFL)) {
dev->stats.tx_fifo_errors++;
printk(KERN_ERR "%s: Tx: ERR_BUF|ERR_UFL, restarting\n",
dev->name);
STOP_LANCE(lp);
lp->init_ring(dev);
load_csrs(lp);
init_restart_lance(lp);
goto out;
}
} else if ((bits & LE_T1_POK) == LE_T1_POK) {
td->tmd1_bits = bits & ~(LE_T1_POK);
if (bits & LE_T1_EONE)
dev->stats.collisions++;
if (bits & LE_T1_EMORE)
dev->stats.collisions += 2;
dev->stats.tx_packets++;
}
j = TX_NEXT(j);
}
lp->tx_old = j;
out:
if (netif_queue_stopped(dev) &&
TX_BUFFS_AVAIL > 0)
netif_wake_queue(dev);
spin_unlock(&lp->lock);
}
static void lance_piocopy_to_skb(struct sk_buff *skb, void __iomem *piobuf, int len)
{
u16 *p16 = (u16 *) skb->data;
u32 *p32;
u8 *p8;
void __iomem *pbuf = piobuf;
*p16++ = sbus_readw(pbuf);
p32 = (u32 *) p16;
pbuf += 2;
len -= 2;
while (len >= 4) {
*p32++ = sbus_readl(pbuf);
pbuf += 4;
len -= 4;
}
p8 = (u8 *) p32;
if (len >= 2) {
p16 = (u16 *) p32;
*p16++ = sbus_readw(pbuf);
pbuf += 2;
len -= 2;
p8 = (u8 *) p16;
}
if (len >= 1)
*p8 = sbus_readb(pbuf);
}
static void lance_rx_pio(struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
struct lance_init_block __iomem *ib = lp->init_block_iomem;
struct lance_rx_desc __iomem *rd;
unsigned char bits;
int len, entry;
struct sk_buff *skb;
entry = lp->rx_new;
for (rd = &ib->brx_ring [entry];
!((bits = sbus_readb(&rd->rmd1_bits)) & LE_R1_OWN);
rd = &ib->brx_ring [entry]) {
if ((bits & LE_R1_POK) != LE_R1_POK) {
dev->stats.rx_over_errors++;
dev->stats.rx_errors++;
} else if (bits & LE_R1_ERR) {
if (bits & LE_R1_BUF) dev->stats.rx_fifo_errors++;
if (bits & LE_R1_CRC) dev->stats.rx_crc_errors++;
if (bits & LE_R1_OFL) dev->stats.rx_over_errors++;
if (bits & LE_R1_FRA) dev->stats.rx_frame_errors++;
if (bits & LE_R1_EOP) dev->stats.rx_errors++;
} else {
len = (sbus_readw(&rd->mblength) & 0xfff) - 4;
skb = netdev_alloc_skb(dev, len + 2);
if (skb == NULL) {
dev->stats.rx_dropped++;
sbus_writew(0, &rd->mblength);
sbus_writeb(LE_R1_OWN, &rd->rmd1_bits);
lp->rx_new = RX_NEXT(entry);
return;
}
dev->stats.rx_bytes += len;
skb_reserve (skb, 2);
skb_put(skb, len);
lance_piocopy_to_skb(skb, &(ib->rx_buf[entry][0]), len);
skb->protocol = eth_type_trans(skb, dev);
netif_rx(skb);
dev->stats.rx_packets++;
}
sbus_writew(0, &rd->mblength);
sbus_writeb(LE_R1_OWN, &rd->rmd1_bits);
entry = RX_NEXT(entry);
}
lp->rx_new = entry;
}
static void lance_tx_pio(struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
struct lance_init_block __iomem *ib = lp->init_block_iomem;
int i, j;
spin_lock(&lp->lock);
j = lp->tx_old;
for (i = j; i != lp->tx_new; i = j) {
struct lance_tx_desc __iomem *td = &ib->btx_ring [i];
u8 bits = sbus_readb(&td->tmd1_bits);
if (bits & LE_T1_OWN)
break;
if (bits & LE_T1_ERR) {
u16 status = sbus_readw(&td->misc);
dev->stats.tx_errors++;
if (status & LE_T3_RTY) dev->stats.tx_aborted_errors++;
if (status & LE_T3_LCOL) dev->stats.tx_window_errors++;
if (status & LE_T3_CLOS) {
dev->stats.tx_carrier_errors++;
if (lp->auto_select) {
lp->tpe = 1 - lp->tpe;
printk(KERN_NOTICE "%s: Carrier Lost, trying %s\n",
dev->name, lp->tpe?"TPE":"AUI");
STOP_LANCE(lp);
lp->init_ring(dev);
load_csrs(lp);
init_restart_lance(lp);
goto out;
}
}
if (status & (LE_T3_BUF|LE_T3_UFL)) {
dev->stats.tx_fifo_errors++;
printk(KERN_ERR "%s: Tx: ERR_BUF|ERR_UFL, restarting\n",
dev->name);
STOP_LANCE(lp);
lp->init_ring(dev);
load_csrs(lp);
init_restart_lance(lp);
goto out;
}
} else if ((bits & LE_T1_POK) == LE_T1_POK) {
sbus_writeb(bits & ~(LE_T1_POK), &td->tmd1_bits);
if (bits & LE_T1_EONE)
dev->stats.collisions++;
if (bits & LE_T1_EMORE)
dev->stats.collisions += 2;
dev->stats.tx_packets++;
}
j = TX_NEXT(j);
}
lp->tx_old = j;
if (netif_queue_stopped(dev) &&
TX_BUFFS_AVAIL > 0)
netif_wake_queue(dev);
out:
spin_unlock(&lp->lock);
}
static irqreturn_t lance_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct lance_private *lp = netdev_priv(dev);
int csr0;
sbus_writew(LE_CSR0, lp->lregs + RAP);
csr0 = sbus_readw(lp->lregs + RDP);
sbus_writew(csr0 & (LE_C0_INTR | LE_C0_TINT | LE_C0_RINT),
lp->lregs + RDP);
if ((csr0 & LE_C0_ERR) != 0) {
sbus_writew((LE_C0_BABL | LE_C0_ERR | LE_C0_MISS |
LE_C0_CERR | LE_C0_MERR),
lp->lregs + RDP);
}
if (csr0 & LE_C0_RINT)
lp->rx(dev);
if (csr0 & LE_C0_TINT)
lp->tx(dev);
if (csr0 & LE_C0_BABL)
dev->stats.tx_errors++;
if (csr0 & LE_C0_MISS)
dev->stats.rx_errors++;
if (csr0 & LE_C0_MERR) {
if (lp->dregs) {
u32 addr = sbus_readl(lp->dregs + DMA_ADDR);
printk(KERN_ERR "%s: Memory error, status %04x, addr %06x\n",
dev->name, csr0, addr & 0xffffff);
} else {
printk(KERN_ERR "%s: Memory error, status %04x\n",
dev->name, csr0);
}
sbus_writew(LE_C0_STOP, lp->lregs + RDP);
if (lp->dregs) {
u32 dma_csr = sbus_readl(lp->dregs + DMA_CSR);
dma_csr |= DMA_FIFO_INV;
sbus_writel(dma_csr, lp->dregs + DMA_CSR);
}
lp->init_ring(dev);
load_csrs(lp);
init_restart_lance(lp);
netif_wake_queue(dev);
}
sbus_writew(LE_C0_INEA, lp->lregs + RDP);
return IRQ_HANDLED;
}
static void build_fake_packet(struct lance_private *lp)
{
struct net_device *dev = lp->dev;
int i, entry;
entry = lp->tx_new & TX_RING_MOD_MASK;
if (lp->pio_buffer) {
struct lance_init_block __iomem *ib = lp->init_block_iomem;
u16 __iomem *packet = (u16 __iomem *) &(ib->tx_buf[entry][0]);
struct ethhdr __iomem *eth = (struct ethhdr __iomem *) packet;
for (i = 0; i < (ETH_ZLEN / sizeof(u16)); i++)
sbus_writew(0, &packet[i]);
for (i = 0; i < 6; i++) {
sbus_writeb(dev->dev_addr[i], &eth->h_dest[i]);
sbus_writeb(dev->dev_addr[i], &eth->h_source[i]);
}
sbus_writew((-ETH_ZLEN) | 0xf000, &ib->btx_ring[entry].length);
sbus_writew(0, &ib->btx_ring[entry].misc);
sbus_writeb(LE_T1_POK|LE_T1_OWN, &ib->btx_ring[entry].tmd1_bits);
} else {
struct lance_init_block *ib = lp->init_block_mem;
u16 *packet = (u16 *) &(ib->tx_buf[entry][0]);
struct ethhdr *eth = (struct ethhdr *) packet;
memset(packet, 0, ETH_ZLEN);
for (i = 0; i < 6; i++) {
eth->h_dest[i] = dev->dev_addr[i];
eth->h_source[i] = dev->dev_addr[i];
}
ib->btx_ring[entry].length = (-ETH_ZLEN) | 0xf000;
ib->btx_ring[entry].misc = 0;
ib->btx_ring[entry].tmd1_bits = (LE_T1_POK|LE_T1_OWN);
}
lp->tx_new = TX_NEXT(entry);
}
static int lance_open(struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
int status = 0;
STOP_LANCE(lp);
if (request_irq(dev->irq, lance_interrupt, IRQF_SHARED,
lancestr, (void *) dev)) {
printk(KERN_ERR "Lance: Can't get irq %d\n", dev->irq);
return -EAGAIN;
}
if (lp->dregs) {
u32 regval = lp->init_block_dvma & 0xff000000;
sbus_writel(regval, lp->dregs + DMA_TEST);
}
if (lp->pio_buffer) {
struct lance_init_block __iomem *ib = lp->init_block_iomem;
sbus_writew(0, &ib->mode);
sbus_writel(0, &ib->filter[0]);
sbus_writel(0, &ib->filter[1]);
} else {
struct lance_init_block *ib = lp->init_block_mem;
ib->mode = 0;
ib->filter [0] = 0;
ib->filter [1] = 0;
}
lp->init_ring(dev);
load_csrs(lp);
netif_start_queue(dev);
status = init_restart_lance(lp);
if (!status && lp->auto_select) {
build_fake_packet(lp);
sbus_writew(LE_C0_INEA | LE_C0_TDMD, lp->lregs + RDP);
}
return status;
}
static int lance_close(struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
netif_stop_queue(dev);
del_timer_sync(&lp->multicast_timer);
STOP_LANCE(lp);
free_irq(dev->irq, (void *) dev);
return 0;
}
static int lance_reset(struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
int status;
STOP_LANCE(lp);
if (lp->dregs) {
u32 csr, addr;
printk(KERN_ERR "resetting ledma\n");
csr = sbus_readl(lp->dregs + DMA_CSR);
sbus_writel(csr | DMA_RST_ENET, lp->dregs + DMA_CSR);
udelay(200);
sbus_writel(csr & ~DMA_RST_ENET, lp->dregs + DMA_CSR);
addr = lp->init_block_dvma & 0xff000000;
sbus_writel(addr, lp->dregs + DMA_TEST);
}
lp->init_ring(dev);
load_csrs(lp);
dev->trans_start = jiffies;
status = init_restart_lance(lp);
return status;
}
static void lance_piocopy_from_skb(void __iomem *dest, unsigned char *src, int len)
{
void __iomem *piobuf = dest;
u32 *p32;
u16 *p16;
u8 *p8;
switch ((unsigned long)src & 0x3) {
case 0:
p32 = (u32 *) src;
while (len >= 4) {
sbus_writel(*p32, piobuf);
p32++;
piobuf += 4;
len -= 4;
}
src = (char *) p32;
break;
case 1:
case 3:
p8 = (u8 *) src;
while (len >= 4) {
u32 val;
val = p8[0] << 24;
val |= p8[1] << 16;
val |= p8[2] << 8;
val |= p8[3];
sbus_writel(val, piobuf);
p8 += 4;
piobuf += 4;
len -= 4;
}
src = (char *) p8;
break;
case 2:
p16 = (u16 *) src;
while (len >= 4) {
u32 val = p16[0]<<16 | p16[1];
sbus_writel(val, piobuf);
p16 += 2;
piobuf += 4;
len -= 4;
}
src = (char *) p16;
break;
}
if (len >= 2) {
u16 val = src[0] << 8 | src[1];
sbus_writew(val, piobuf);
src += 2;
piobuf += 2;
len -= 2;
}
if (len >= 1)
sbus_writeb(src[0], piobuf);
}
static void lance_piozero(void __iomem *dest, int len)
{
void __iomem *piobuf = dest;
if ((unsigned long)piobuf & 1) {
sbus_writeb(0, piobuf);
piobuf += 1;
len -= 1;
if (len == 0)
return;
}
if (len == 1) {
sbus_writeb(0, piobuf);
return;
}
if ((unsigned long)piobuf & 2) {
sbus_writew(0, piobuf);
piobuf += 2;
len -= 2;
if (len == 0)
return;
}
while (len >= 4) {
sbus_writel(0, piobuf);
piobuf += 4;
len -= 4;
}
if (len >= 2) {
sbus_writew(0, piobuf);
piobuf += 2;
len -= 2;
}
if (len >= 1)
sbus_writeb(0, piobuf);
}
static void lance_tx_timeout(struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
printk(KERN_ERR "%s: transmit timed out, status %04x, reset\n",
dev->name, sbus_readw(lp->lregs + RDP));
lance_reset(dev);
netif_wake_queue(dev);
}
static int lance_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
int entry, skblen, len;
skblen = skb->len;
len = (skblen <= ETH_ZLEN) ? ETH_ZLEN : skblen;
spin_lock_irq(&lp->lock);
dev->stats.tx_bytes += len;
entry = lp->tx_new & TX_RING_MOD_MASK;
if (lp->pio_buffer) {
struct lance_init_block __iomem *ib = lp->init_block_iomem;
sbus_writew((-len) | 0xf000, &ib->btx_ring[entry].length);
sbus_writew(0, &ib->btx_ring[entry].misc);
lance_piocopy_from_skb(&ib->tx_buf[entry][0], skb->data, skblen);
if (len != skblen)
lance_piozero(&ib->tx_buf[entry][skblen], len - skblen);
sbus_writeb(LE_T1_POK | LE_T1_OWN, &ib->btx_ring[entry].tmd1_bits);
} else {
struct lance_init_block *ib = lp->init_block_mem;
ib->btx_ring [entry].length = (-len) | 0xf000;
ib->btx_ring [entry].misc = 0;
skb_copy_from_linear_data(skb, &ib->tx_buf [entry][0], skblen);
if (len != skblen)
memset((char *) &ib->tx_buf [entry][skblen], 0, len - skblen);
ib->btx_ring [entry].tmd1_bits = (LE_T1_POK | LE_T1_OWN);
}
lp->tx_new = TX_NEXT(entry);
if (TX_BUFFS_AVAIL <= 0)
netif_stop_queue(dev);
sbus_writew(LE_C0_INEA | LE_C0_TDMD, lp->lregs + RDP);
if (lp->dregs)
sbus_readw(lp->lregs + RDP);
spin_unlock_irq(&lp->lock);
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static void lance_load_multicast(struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
struct netdev_hw_addr *ha;
u32 crc;
u32 val;
if (dev->flags & IFF_ALLMULTI)
val = ~0;
else
val = 0;
if (lp->pio_buffer) {
struct lance_init_block __iomem *ib = lp->init_block_iomem;
sbus_writel(val, &ib->filter[0]);
sbus_writel(val, &ib->filter[1]);
} else {
struct lance_init_block *ib = lp->init_block_mem;
ib->filter [0] = val;
ib->filter [1] = val;
}
if (dev->flags & IFF_ALLMULTI)
return;
netdev_for_each_mc_addr(ha, dev) {
crc = ether_crc_le(6, ha->addr);
crc = crc >> 26;
if (lp->pio_buffer) {
struct lance_init_block __iomem *ib = lp->init_block_iomem;
u16 __iomem *mcast_table = (u16 __iomem *) &ib->filter;
u16 tmp = sbus_readw(&mcast_table[crc>>4]);
tmp |= 1 << (crc & 0xf);
sbus_writew(tmp, &mcast_table[crc>>4]);
} else {
struct lance_init_block *ib = lp->init_block_mem;
u16 *mcast_table = (u16 *) &ib->filter;
mcast_table [crc >> 4] |= 1 << (crc & 0xf);
}
}
}
static void lance_set_multicast(struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
struct lance_init_block *ib_mem = lp->init_block_mem;
struct lance_init_block __iomem *ib_iomem = lp->init_block_iomem;
u16 mode;
if (!netif_running(dev))
return;
if (lp->tx_old != lp->tx_new) {
mod_timer(&lp->multicast_timer, jiffies + 4);
netif_wake_queue(dev);
return;
}
netif_stop_queue(dev);
STOP_LANCE(lp);
lp->init_ring(dev);
if (lp->pio_buffer)
mode = sbus_readw(&ib_iomem->mode);
else
mode = ib_mem->mode;
if (dev->flags & IFF_PROMISC) {
mode |= LE_MO_PROM;
if (lp->pio_buffer)
sbus_writew(mode, &ib_iomem->mode);
else
ib_mem->mode = mode;
} else {
mode &= ~LE_MO_PROM;
if (lp->pio_buffer)
sbus_writew(mode, &ib_iomem->mode);
else
ib_mem->mode = mode;
lance_load_multicast(dev);
}
load_csrs(lp);
init_restart_lance(lp);
netif_wake_queue(dev);
}
static void lance_set_multicast_retry(unsigned long _opaque)
{
struct net_device *dev = (struct net_device *) _opaque;
lance_set_multicast(dev);
}
static void lance_free_hwresources(struct lance_private *lp)
{
if (lp->lregs)
of_iounmap(&lp->op->resource[0], lp->lregs, LANCE_REG_SIZE);
if (lp->dregs) {
struct platform_device *ledma = lp->ledma;
of_iounmap(&ledma->resource[0], lp->dregs,
resource_size(&ledma->resource[0]));
}
if (lp->init_block_iomem) {
of_iounmap(&lp->lebuffer->resource[0], lp->init_block_iomem,
sizeof(struct lance_init_block));
} else if (lp->init_block_mem) {
dma_free_coherent(&lp->op->dev,
sizeof(struct lance_init_block),
lp->init_block_mem,
lp->init_block_dvma);
}
}
static void sparc_lance_get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *info)
{
strlcpy(info->driver, "sunlance", sizeof(info->driver));
strlcpy(info->version, "2.02", sizeof(info->version));
}
static int sparc_lance_probe_one(struct platform_device *op,
struct platform_device *ledma,
struct platform_device *lebuffer)
{
struct device_node *dp = op->dev.of_node;
static unsigned version_printed;
struct lance_private *lp;
struct net_device *dev;
int i;
dev = alloc_etherdev(sizeof(struct lance_private) + 8);
if (!dev)
return -ENOMEM;
lp = netdev_priv(dev);
if (sparc_lance_debug && version_printed++ == 0)
printk (KERN_INFO "%s", version);
spin_lock_init(&lp->lock);
for (i = 0; i < 6; i++)
dev->dev_addr[i] = idprom->id_ethaddr[i];
lp->lregs = of_ioremap(&op->resource[0], 0,
LANCE_REG_SIZE, lancestr);
if (!lp->lregs) {
printk(KERN_ERR "SunLance: Cannot map registers.\n");
goto fail;
}
lp->ledma = ledma;
if (lp->ledma) {
lp->dregs = of_ioremap(&ledma->resource[0], 0,
resource_size(&ledma->resource[0]),
"ledma");
if (!lp->dregs) {
printk(KERN_ERR "SunLance: Cannot map "
"ledma registers.\n");
goto fail;
}
}
lp->op = op;
lp->lebuffer = lebuffer;
if (lebuffer) {
if (lebuffer->resource[0].start & 7) {
printk(KERN_ERR "SunLance: ERROR: Rx and Tx rings not on even boundary.\n");
goto fail;
}
lp->init_block_iomem =
of_ioremap(&lebuffer->resource[0], 0,
sizeof(struct lance_init_block), "lebuffer");
if (!lp->init_block_iomem) {
printk(KERN_ERR "SunLance: Cannot map PIO buffer.\n");
goto fail;
}
lp->init_block_dvma = 0;
lp->pio_buffer = 1;
lp->init_ring = lance_init_ring_pio;
lp->rx = lance_rx_pio;
lp->tx = lance_tx_pio;
} else {
lp->init_block_mem =
dma_alloc_coherent(&op->dev,
sizeof(struct lance_init_block),
&lp->init_block_dvma, GFP_ATOMIC);
if (!lp->init_block_mem)
goto fail;
lp->pio_buffer = 0;
lp->init_ring = lance_init_ring_dvma;
lp->rx = lance_rx_dvma;
lp->tx = lance_tx_dvma;
}
lp->busmaster_regval = of_getintprop_default(dp, "busmaster-regval",
(LE_C3_BSWP |
LE_C3_ACON |
LE_C3_BCON));
lp->name = lancestr;
lp->burst_sizes = 0;
if (lp->ledma) {
struct device_node *ledma_dp = ledma->dev.of_node;
struct device_node *sbus_dp;
unsigned int sbmask;
const char *prop;
u32 csr;
lp->burst_sizes = of_getintprop_default(ledma_dp,
"burst-sizes", 0);
sbus_dp = ledma_dp->parent;
sbmask = of_getintprop_default(sbus_dp, "burst-sizes",
DMA_BURSTBITS);
lp->burst_sizes &= sbmask;
prop = of_get_property(ledma_dp, "cable-selection", NULL);
if (!prop || prop[0] == '\0') {
struct device_node *nd;
printk(KERN_INFO "SunLance: using "
"auto-carrier-detection.\n");
nd = of_find_node_by_path("/options");
if (!nd)
goto no_link_test;
prop = of_get_property(nd, "tpe-link-test?", NULL);
if (!prop)
goto no_link_test;
if (strcmp(prop, "true")) {
printk(KERN_NOTICE "SunLance: warning: overriding option "
"'tpe-link-test?'\n");
printk(KERN_NOTICE "SunLance: warning: mail any problems "
"to ecd@skynet.be\n");
auxio_set_lte(AUXIO_LTE_ON);
}
no_link_test:
lp->auto_select = 1;
lp->tpe = 0;
} else if (!strcmp(prop, "aui")) {
lp->auto_select = 0;
lp->tpe = 0;
} else {
lp->auto_select = 0;
lp->tpe = 1;
}
csr = sbus_readl(lp->dregs + DMA_CSR);
sbus_writel(csr | DMA_RST_ENET, lp->dregs + DMA_CSR);
udelay(200);
sbus_writel(csr & ~DMA_RST_ENET, lp->dregs + DMA_CSR);
} else
lp->dregs = NULL;
lp->dev = dev;
SET_NETDEV_DEV(dev, &op->dev);
dev->watchdog_timeo = 5*HZ;
dev->ethtool_ops = &sparc_lance_ethtool_ops;
dev->netdev_ops = &sparc_lance_ops;
dev->irq = op->archdata.irqs[0];
init_timer(&lp->multicast_timer);
lp->multicast_timer.data = (unsigned long) dev;
lp->multicast_timer.function = lance_set_multicast_retry;
if (register_netdev(dev)) {
printk(KERN_ERR "SunLance: Cannot register device.\n");
goto fail;
}
dev_set_drvdata(&op->dev, lp);
printk(KERN_INFO "%s: LANCE %pM\n",
dev->name, dev->dev_addr);
return 0;
fail:
lance_free_hwresources(lp);
free_netdev(dev);
return -ENODEV;
}
static int sunlance_sbus_probe(struct platform_device *op)
{
struct platform_device *parent = to_platform_device(op->dev.parent);
struct device_node *parent_dp = parent->dev.of_node;
int err;
if (!strcmp(parent_dp->name, "ledma")) {
err = sparc_lance_probe_one(op, parent, NULL);
} else if (!strcmp(parent_dp->name, "lebuffer")) {
err = sparc_lance_probe_one(op, NULL, parent);
} else
err = sparc_lance_probe_one(op, NULL, NULL);
return err;
}
static int sunlance_sbus_remove(struct platform_device *op)
{
struct lance_private *lp = dev_get_drvdata(&op->dev);
struct net_device *net_dev = lp->dev;
unregister_netdev(net_dev);
lance_free_hwresources(lp);
free_netdev(net_dev);
dev_set_drvdata(&op->dev, NULL);
return 0;
}
