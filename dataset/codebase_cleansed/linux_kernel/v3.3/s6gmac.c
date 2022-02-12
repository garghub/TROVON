static void s6gmac_rx_fillfifo(struct s6gmac *pd)
{
struct sk_buff *skb;
while ((((u8)(pd->rx_skb_i - pd->rx_skb_o)) < S6_NUM_RX_SKB) &&
(!s6dmac_fifo_full(pd->rx_dma, pd->rx_chan)) &&
(skb = dev_alloc_skb(S6_MAX_FRLEN + 2))) {
pd->rx_skb[(pd->rx_skb_i++) % S6_NUM_RX_SKB] = skb;
s6dmac_put_fifo_cache(pd->rx_dma, pd->rx_chan,
pd->io, (u32)skb->data, S6_MAX_FRLEN);
}
}
static void s6gmac_rx_interrupt(struct net_device *dev)
{
struct s6gmac *pd = netdev_priv(dev);
u32 pfx;
struct sk_buff *skb;
while (((u8)(pd->rx_skb_i - pd->rx_skb_o)) >
s6dmac_pending_count(pd->rx_dma, pd->rx_chan)) {
skb = pd->rx_skb[(pd->rx_skb_o++) % S6_NUM_RX_SKB];
pfx = readl(pd->reg + S6_GMAC_BURST_POSTRD);
if (pfx & (1 << S6_GMAC_BURST_POSTRD_DROP)) {
dev_kfree_skb_irq(skb);
} else {
skb_put(skb, (pfx >> S6_GMAC_BURST_POSTRD_LEN)
& S6_GMAC_BURST_POSTRD_LEN_MASK);
skb->protocol = eth_type_trans(skb, dev);
skb->ip_summed = CHECKSUM_UNNECESSARY;
netif_rx(skb);
}
}
}
static void s6gmac_tx_interrupt(struct net_device *dev)
{
struct s6gmac *pd = netdev_priv(dev);
while (((u8)(pd->tx_skb_i - pd->tx_skb_o)) >
s6dmac_pending_count(pd->tx_dma, pd->tx_chan)) {
dev_kfree_skb_irq(pd->tx_skb[(pd->tx_skb_o++) % S6_NUM_TX_SKB]);
}
if (!s6dmac_fifo_full(pd->tx_dma, pd->tx_chan))
netif_wake_queue(dev);
}
static void s6gmac_stats_collect(struct s6gmac *pd,
const struct s6gmac_statinf *inf)
{
int b;
for (b = 0; b < S6_STATS_B; b++) {
if (inf[b].reg_size) {
pd->stats[inf[b].net_index] +=
readl(pd->reg + S6_GMAC_STAT_REGS
+ sizeof(u32) * inf[b].reg_off);
}
}
}
static void s6gmac_stats_carry(struct s6gmac *pd,
const struct s6gmac_statinf *inf, u32 mask)
{
int b;
while (mask) {
b = fls(mask) - 1;
mask &= ~(1 << b);
pd->carry[inf[b].net_index] += (1 << inf[b].reg_size);
}
}
static inline u32 s6gmac_stats_pending(struct s6gmac *pd, int carry)
{
int r = readl(pd->reg + S6_GMAC_STATCARRY(carry)) &
~readl(pd->reg + S6_GMAC_STATCARRYMSK(carry));
return r;
}
static inline void s6gmac_stats_interrupt(struct s6gmac *pd, int carry)
{
u32 mask;
mask = s6gmac_stats_pending(pd, carry);
if (mask) {
writel(mask, pd->reg + S6_GMAC_STATCARRY(carry));
s6gmac_stats_carry(pd, &statinf[carry][0], mask);
}
}
static irqreturn_t s6gmac_interrupt(int irq, void *dev_id)
{
struct net_device *dev = (struct net_device *)dev_id;
struct s6gmac *pd = netdev_priv(dev);
if (!dev)
return IRQ_NONE;
spin_lock(&pd->lock);
if (s6dmac_termcnt_irq(pd->rx_dma, pd->rx_chan))
s6gmac_rx_interrupt(dev);
s6gmac_rx_fillfifo(pd);
if (s6dmac_termcnt_irq(pd->tx_dma, pd->tx_chan))
s6gmac_tx_interrupt(dev);
s6gmac_stats_interrupt(pd, 0);
s6gmac_stats_interrupt(pd, 1);
spin_unlock(&pd->lock);
return IRQ_HANDLED;
}
static inline void s6gmac_set_dstaddr(struct s6gmac *pd, int n,
u32 addrlo, u32 addrhi, u32 masklo, u32 maskhi)
{
writel(addrlo, pd->reg + S6_GMAC_HOST_DSTADDRLO(n));
writel(addrhi, pd->reg + S6_GMAC_HOST_DSTADDRHI(n));
writel(masklo, pd->reg + S6_GMAC_HOST_DSTMASKLO(n));
writel(maskhi, pd->reg + S6_GMAC_HOST_DSTMASKHI(n));
}
static inline void s6gmac_stop_device(struct net_device *dev)
{
struct s6gmac *pd = netdev_priv(dev);
writel(0, pd->reg + S6_GMAC_MACCONF1);
}
static inline void s6gmac_init_device(struct net_device *dev)
{
struct s6gmac *pd = netdev_priv(dev);
int is_rgmii = !!(pd->phydev->supported
& (SUPPORTED_1000baseT_Full | SUPPORTED_1000baseT_Half));
#if 0
writel(1 << S6_GMAC_MACCONF1_SYNCTX |
1 << S6_GMAC_MACCONF1_SYNCRX |
1 << S6_GMAC_MACCONF1_TXFLOWCTRL |
1 << S6_GMAC_MACCONF1_RXFLOWCTRL |
1 << S6_GMAC_MACCONF1_RESTXFUNC |
1 << S6_GMAC_MACCONF1_RESRXFUNC |
1 << S6_GMAC_MACCONF1_RESTXMACCTRL |
1 << S6_GMAC_MACCONF1_RESRXMACCTRL,
pd->reg + S6_GMAC_MACCONF1);
#endif
writel(1 << S6_GMAC_MACCONF1_SOFTRES, pd->reg + S6_GMAC_MACCONF1);
udelay(1000);
writel(1 << S6_GMAC_MACCONF1_TXENA | 1 << S6_GMAC_MACCONF1_RXENA,
pd->reg + S6_GMAC_MACCONF1);
writel(1 << S6_GMAC_HOST_PBLKCTRL_TXSRES |
1 << S6_GMAC_HOST_PBLKCTRL_RXSRES,
pd->reg + S6_GMAC_HOST_PBLKCTRL);
writel(S6_GMAC_HOST_PBLKCTRL_SIZ_128 << S6_GMAC_HOST_PBLKCTRL_TXBSIZ |
S6_GMAC_HOST_PBLKCTRL_SIZ_128 << S6_GMAC_HOST_PBLKCTRL_RXBSIZ |
1 << S6_GMAC_HOST_PBLKCTRL_STATENA |
1 << S6_GMAC_HOST_PBLKCTRL_STATCLEAR |
is_rgmii << S6_GMAC_HOST_PBLKCTRL_RGMII,
pd->reg + S6_GMAC_HOST_PBLKCTRL);
writel(1 << S6_GMAC_MACCONF1_TXENA |
1 << S6_GMAC_MACCONF1_RXENA |
(dev->flags & IFF_LOOPBACK ? 1 : 0)
<< S6_GMAC_MACCONF1_LOOPBACK,
pd->reg + S6_GMAC_MACCONF1);
writel(dev->mtu && (dev->mtu < (S6_MAX_FRLEN - ETH_HLEN-ETH_FCS_LEN)) ?
dev->mtu+ETH_HLEN+ETH_FCS_LEN : S6_MAX_FRLEN,
pd->reg + S6_GMAC_MACMAXFRAMELEN);
writel((pd->link.full ? 1 : 0) << S6_GMAC_MACCONF2_FULL |
1 << S6_GMAC_MACCONF2_PADCRCENA |
1 << S6_GMAC_MACCONF2_LENGTHFCHK |
(pd->link.giga ?
S6_GMAC_MACCONF2_IFMODE_BYTE :
S6_GMAC_MACCONF2_IFMODE_NIBBLE)
<< S6_GMAC_MACCONF2_IFMODE |
7 << S6_GMAC_MACCONF2_PREAMBLELEN,
pd->reg + S6_GMAC_MACCONF2);
writel(0, pd->reg + S6_GMAC_MACSTATADDR1);
writel(0, pd->reg + S6_GMAC_MACSTATADDR2);
writel(1 << S6_GMAC_FIFOCONF0_WTMENREQ |
1 << S6_GMAC_FIFOCONF0_SRFENREQ |
1 << S6_GMAC_FIFOCONF0_FRFENREQ |
1 << S6_GMAC_FIFOCONF0_STFENREQ |
1 << S6_GMAC_FIFOCONF0_FTFENREQ,
pd->reg + S6_GMAC_FIFOCONF0);
writel(128 << S6_GMAC_FIFOCONF3_CFGFTTH |
128 << S6_GMAC_FIFOCONF3_CFGHWMFT,
pd->reg + S6_GMAC_FIFOCONF3);
writel((S6_GMAC_FIFOCONF_RSV_MASK & ~(
1 << S6_GMAC_FIFOCONF_RSV_RUNT |
1 << S6_GMAC_FIFOCONF_RSV_CRCERR |
1 << S6_GMAC_FIFOCONF_RSV_OK |
1 << S6_GMAC_FIFOCONF_RSV_DRIBBLE |
1 << S6_GMAC_FIFOCONF_RSV_CTRLFRAME |
1 << S6_GMAC_FIFOCONF_RSV_PAUSECTRL |
1 << S6_GMAC_FIFOCONF_RSV_UNOPCODE |
1 << S6_GMAC_FIFOCONF_RSV_TRUNCATED)) |
1 << S6_GMAC_FIFOCONF5_DROPLT64 |
pd->link.giga << S6_GMAC_FIFOCONF5_CFGBYTM |
1 << S6_GMAC_FIFOCONF5_RXDROPSIZE,
pd->reg + S6_GMAC_FIFOCONF5);
writel(1 << S6_GMAC_FIFOCONF_RSV_RUNT |
1 << S6_GMAC_FIFOCONF_RSV_CRCERR |
1 << S6_GMAC_FIFOCONF_RSV_DRIBBLE |
1 << S6_GMAC_FIFOCONF_RSV_CTRLFRAME |
1 << S6_GMAC_FIFOCONF_RSV_PAUSECTRL |
1 << S6_GMAC_FIFOCONF_RSV_UNOPCODE |
1 << S6_GMAC_FIFOCONF_RSV_TRUNCATED,
pd->reg + S6_GMAC_FIFOCONF4);
s6gmac_set_dstaddr(pd, 0,
0xFFFFFFFF, 0x0000FFFF, 0xFFFFFFFF, 0x0000FFFF);
s6gmac_set_dstaddr(pd, 1,
dev->dev_addr[5] |
dev->dev_addr[4] << 8 |
dev->dev_addr[3] << 16 |
dev->dev_addr[2] << 24,
dev->dev_addr[1] |
dev->dev_addr[0] << 8,
0xFFFFFFFF, 0x0000FFFF);
s6gmac_set_dstaddr(pd, 2,
0x00000000, 0x00000100, 0x00000000, 0x00000100);
s6gmac_set_dstaddr(pd, 3,
0x00000000, 0x00000000, 0x00000000, 0x00000000);
writel(1 << S6_GMAC_HOST_PBLKCTRL_TXENA |
1 << S6_GMAC_HOST_PBLKCTRL_RXENA |
S6_GMAC_HOST_PBLKCTRL_SIZ_128 << S6_GMAC_HOST_PBLKCTRL_TXBSIZ |
S6_GMAC_HOST_PBLKCTRL_SIZ_128 << S6_GMAC_HOST_PBLKCTRL_RXBSIZ |
1 << S6_GMAC_HOST_PBLKCTRL_STATENA |
1 << S6_GMAC_HOST_PBLKCTRL_STATCLEAR |
is_rgmii << S6_GMAC_HOST_PBLKCTRL_RGMII,
pd->reg + S6_GMAC_HOST_PBLKCTRL);
}
static void s6mii_enable(struct s6gmac *pd)
{
writel(readl(pd->reg + S6_GMAC_MACCONF1) &
~(1 << S6_GMAC_MACCONF1_SOFTRES),
pd->reg + S6_GMAC_MACCONF1);
writel((readl(pd->reg + S6_GMAC_MACMIICONF)
& ~(S6_GMAC_MACMIICONF_CSEL_MASK << S6_GMAC_MACMIICONF_CSEL))
| (S6_GMAC_MACMIICONF_CSEL_DIV168 << S6_GMAC_MACMIICONF_CSEL),
pd->reg + S6_GMAC_MACMIICONF);
}
static int s6mii_busy(struct s6gmac *pd, int tmo)
{
while (readl(pd->reg + S6_GMAC_MACMIIINDI)) {
if (--tmo == 0)
return -ETIME;
udelay(64);
}
return 0;
}
static int s6mii_read(struct mii_bus *bus, int phy_addr, int regnum)
{
struct s6gmac *pd = bus->priv;
s6mii_enable(pd);
if (s6mii_busy(pd, 256))
return -ETIME;
writel(phy_addr << S6_GMAC_MACMIIADDR_PHY |
regnum << S6_GMAC_MACMIIADDR_REG,
pd->reg + S6_GMAC_MACMIIADDR);
writel(1 << S6_GMAC_MACMIICMD_READ, pd->reg + S6_GMAC_MACMIICMD);
writel(0, pd->reg + S6_GMAC_MACMIICMD);
if (s6mii_busy(pd, 256))
return -ETIME;
return (u16)readl(pd->reg + S6_GMAC_MACMIISTAT);
}
static int s6mii_write(struct mii_bus *bus, int phy_addr, int regnum, u16 value)
{
struct s6gmac *pd = bus->priv;
s6mii_enable(pd);
if (s6mii_busy(pd, 256))
return -ETIME;
writel(phy_addr << S6_GMAC_MACMIIADDR_PHY |
regnum << S6_GMAC_MACMIIADDR_REG,
pd->reg + S6_GMAC_MACMIIADDR);
writel(value, pd->reg + S6_GMAC_MACMIICTRL);
if (s6mii_busy(pd, 256))
return -ETIME;
return 0;
}
static int s6mii_reset(struct mii_bus *bus)
{
struct s6gmac *pd = bus->priv;
s6mii_enable(pd);
if (s6mii_busy(pd, PHY_INIT_TIMEOUT))
return -ETIME;
return 0;
}
static void s6gmac_set_rgmii_txclock(struct s6gmac *pd)
{
u32 pllsel = readl(S6_REG_GREG1 + S6_GREG1_PLLSEL);
pllsel &= ~(S6_GREG1_PLLSEL_GMAC_MASK << S6_GREG1_PLLSEL_GMAC);
switch (pd->link.mbit) {
case 10:
pllsel |= S6_GREG1_PLLSEL_GMAC_2500KHZ << S6_GREG1_PLLSEL_GMAC;
break;
case 100:
pllsel |= S6_GREG1_PLLSEL_GMAC_25MHZ << S6_GREG1_PLLSEL_GMAC;
break;
case 1000:
pllsel |= S6_GREG1_PLLSEL_GMAC_125MHZ << S6_GREG1_PLLSEL_GMAC;
break;
default:
return;
}
writel(pllsel, S6_REG_GREG1 + S6_GREG1_PLLSEL);
}
static inline void s6gmac_linkisup(struct net_device *dev, int isup)
{
struct s6gmac *pd = netdev_priv(dev);
struct phy_device *phydev = pd->phydev;
pd->link.full = phydev->duplex;
pd->link.giga = (phydev->speed == 1000);
if (pd->link.mbit != phydev->speed) {
pd->link.mbit = phydev->speed;
s6gmac_set_rgmii_txclock(pd);
}
pd->link.isup = isup;
if (isup)
netif_carrier_on(dev);
phy_print_status(phydev);
}
static void s6gmac_adjust_link(struct net_device *dev)
{
struct s6gmac *pd = netdev_priv(dev);
struct phy_device *phydev = pd->phydev;
if (pd->link.isup &&
(!phydev->link ||
(pd->link.mbit != phydev->speed) ||
(pd->link.full != phydev->duplex))) {
pd->link.isup = 0;
netif_tx_disable(dev);
if (!phydev->link) {
netif_carrier_off(dev);
phy_print_status(phydev);
}
}
if (!pd->link.isup && phydev->link) {
if (pd->link.full != phydev->duplex) {
u32 maccfg = readl(pd->reg + S6_GMAC_MACCONF2);
if (phydev->duplex)
maccfg |= 1 << S6_GMAC_MACCONF2_FULL;
else
maccfg &= ~(1 << S6_GMAC_MACCONF2_FULL);
writel(maccfg, pd->reg + S6_GMAC_MACCONF2);
}
if (pd->link.giga != (phydev->speed == 1000)) {
u32 fifocfg = readl(pd->reg + S6_GMAC_FIFOCONF5);
u32 maccfg = readl(pd->reg + S6_GMAC_MACCONF2);
maccfg &= ~(S6_GMAC_MACCONF2_IFMODE_MASK
<< S6_GMAC_MACCONF2_IFMODE);
if (phydev->speed == 1000) {
fifocfg |= 1 << S6_GMAC_FIFOCONF5_CFGBYTM;
maccfg |= S6_GMAC_MACCONF2_IFMODE_BYTE
<< S6_GMAC_MACCONF2_IFMODE;
} else {
fifocfg &= ~(1 << S6_GMAC_FIFOCONF5_CFGBYTM);
maccfg |= S6_GMAC_MACCONF2_IFMODE_NIBBLE
<< S6_GMAC_MACCONF2_IFMODE;
}
writel(fifocfg, pd->reg + S6_GMAC_FIFOCONF5);
writel(maccfg, pd->reg + S6_GMAC_MACCONF2);
}
if (!s6dmac_fifo_full(pd->tx_dma, pd->tx_chan))
netif_wake_queue(dev);
s6gmac_linkisup(dev, 1);
}
}
static inline int s6gmac_phy_start(struct net_device *dev)
{
struct s6gmac *pd = netdev_priv(dev);
int i = 0;
struct phy_device *p = NULL;
while ((i < PHY_MAX_ADDR) && (!(p = pd->mii.bus->phy_map[i])))
i++;
p = phy_connect(dev, dev_name(&p->dev), &s6gmac_adjust_link, 0,
PHY_INTERFACE_MODE_RGMII);
if (IS_ERR(p)) {
printk(KERN_ERR "%s: Could not attach to PHY\n", dev->name);
return PTR_ERR(p);
}
p->supported &= PHY_GBIT_FEATURES;
p->advertising = p->supported;
pd->phydev = p;
return 0;
}
static inline void s6gmac_init_stats(struct net_device *dev)
{
struct s6gmac *pd = netdev_priv(dev);
u32 mask;
mask = 1 << S6_GMAC_STATCARRY1_RDRP |
1 << S6_GMAC_STATCARRY1_RJBR |
1 << S6_GMAC_STATCARRY1_RFRG |
1 << S6_GMAC_STATCARRY1_ROVR |
1 << S6_GMAC_STATCARRY1_RUND |
1 << S6_GMAC_STATCARRY1_RCDE |
1 << S6_GMAC_STATCARRY1_RFLR |
1 << S6_GMAC_STATCARRY1_RALN |
1 << S6_GMAC_STATCARRY1_RMCA |
1 << S6_GMAC_STATCARRY1_RFCS |
1 << S6_GMAC_STATCARRY1_RPKT |
1 << S6_GMAC_STATCARRY1_RBYT;
writel(mask, pd->reg + S6_GMAC_STATCARRY(0));
writel(~mask, pd->reg + S6_GMAC_STATCARRYMSK(0));
mask = 1 << S6_GMAC_STATCARRY2_TDRP |
1 << S6_GMAC_STATCARRY2_TNCL |
1 << S6_GMAC_STATCARRY2_TXCL |
1 << S6_GMAC_STATCARRY2_TEDF |
1 << S6_GMAC_STATCARRY2_TPKT |
1 << S6_GMAC_STATCARRY2_TBYT |
1 << S6_GMAC_STATCARRY2_TFRG |
1 << S6_GMAC_STATCARRY2_TUND |
1 << S6_GMAC_STATCARRY2_TOVR |
1 << S6_GMAC_STATCARRY2_TFCS |
1 << S6_GMAC_STATCARRY2_TJBR;
writel(mask, pd->reg + S6_GMAC_STATCARRY(1));
writel(~mask, pd->reg + S6_GMAC_STATCARRYMSK(1));
}
static inline void s6gmac_init_dmac(struct net_device *dev)
{
struct s6gmac *pd = netdev_priv(dev);
s6dmac_disable_chan(pd->tx_dma, pd->tx_chan);
s6dmac_disable_chan(pd->rx_dma, pd->rx_chan);
s6dmac_disable_error_irqs(pd->tx_dma, 1 << S6_HIFDMA_GMACTX);
s6dmac_disable_error_irqs(pd->rx_dma, 1 << S6_HIFDMA_GMACRX);
}
static int s6gmac_tx(struct sk_buff *skb, struct net_device *dev)
{
struct s6gmac *pd = netdev_priv(dev);
unsigned long flags;
spin_lock_irqsave(&pd->lock, flags);
writel(skb->len << S6_GMAC_BURST_PREWR_LEN |
0 << S6_GMAC_BURST_PREWR_CFE |
1 << S6_GMAC_BURST_PREWR_PPE |
1 << S6_GMAC_BURST_PREWR_FCS |
((skb->len < ETH_ZLEN) ? 1 : 0) << S6_GMAC_BURST_PREWR_PAD,
pd->reg + S6_GMAC_BURST_PREWR);
s6dmac_put_fifo_cache(pd->tx_dma, pd->tx_chan,
(u32)skb->data, pd->io, skb->len);
if (s6dmac_fifo_full(pd->tx_dma, pd->tx_chan))
netif_stop_queue(dev);
if (((u8)(pd->tx_skb_i - pd->tx_skb_o)) >= S6_NUM_TX_SKB) {
printk(KERN_ERR "GMAC BUG: skb tx ring overflow [%x, %x]\n",
pd->tx_skb_o, pd->tx_skb_i);
BUG();
}
pd->tx_skb[(pd->tx_skb_i++) % S6_NUM_TX_SKB] = skb;
spin_unlock_irqrestore(&pd->lock, flags);
return 0;
}
static void s6gmac_tx_timeout(struct net_device *dev)
{
struct s6gmac *pd = netdev_priv(dev);
unsigned long flags;
spin_lock_irqsave(&pd->lock, flags);
s6gmac_tx_interrupt(dev);
spin_unlock_irqrestore(&pd->lock, flags);
}
static int s6gmac_open(struct net_device *dev)
{
struct s6gmac *pd = netdev_priv(dev);
unsigned long flags;
phy_read_status(pd->phydev);
spin_lock_irqsave(&pd->lock, flags);
pd->link.mbit = 0;
s6gmac_linkisup(dev, pd->phydev->link);
s6gmac_init_device(dev);
s6gmac_init_stats(dev);
s6gmac_init_dmac(dev);
s6gmac_rx_fillfifo(pd);
s6dmac_enable_chan(pd->rx_dma, pd->rx_chan,
2, 1, 0, 1, 0, 0, 0, 7, -1, 2, 0, 1);
s6dmac_enable_chan(pd->tx_dma, pd->tx_chan,
2, 0, 1, 0, 0, 0, 0, 7, -1, 2, 0, 1);
writel(0 << S6_GMAC_HOST_INT_TXBURSTOVER |
0 << S6_GMAC_HOST_INT_TXPREWOVER |
0 << S6_GMAC_HOST_INT_RXBURSTUNDER |
0 << S6_GMAC_HOST_INT_RXPOSTRFULL |
0 << S6_GMAC_HOST_INT_RXPOSTRUNDER,
pd->reg + S6_GMAC_HOST_INTMASK);
spin_unlock_irqrestore(&pd->lock, flags);
phy_start(pd->phydev);
netif_start_queue(dev);
return 0;
}
static int s6gmac_stop(struct net_device *dev)
{
struct s6gmac *pd = netdev_priv(dev);
unsigned long flags;
netif_stop_queue(dev);
phy_stop(pd->phydev);
spin_lock_irqsave(&pd->lock, flags);
s6gmac_init_dmac(dev);
s6gmac_stop_device(dev);
while (pd->tx_skb_i != pd->tx_skb_o)
dev_kfree_skb(pd->tx_skb[(pd->tx_skb_o++) % S6_NUM_TX_SKB]);
while (pd->rx_skb_i != pd->rx_skb_o)
dev_kfree_skb(pd->rx_skb[(pd->rx_skb_o++) % S6_NUM_RX_SKB]);
spin_unlock_irqrestore(&pd->lock, flags);
return 0;
}
static struct net_device_stats *s6gmac_stats(struct net_device *dev)
{
struct s6gmac *pd = netdev_priv(dev);
struct net_device_stats *st = (struct net_device_stats *)&pd->stats;
int i;
do {
unsigned long flags;
spin_lock_irqsave(&pd->lock, flags);
for (i = 0; i < sizeof(pd->stats) / sizeof(unsigned long); i++)
pd->stats[i] =
pd->carry[i] << (S6_GMAC_STAT_SIZE_MIN - 1);
s6gmac_stats_collect(pd, &statinf[0][0]);
s6gmac_stats_collect(pd, &statinf[1][0]);
i = s6gmac_stats_pending(pd, 0) |
s6gmac_stats_pending(pd, 1);
spin_unlock_irqrestore(&pd->lock, flags);
} while (i);
st->rx_errors = st->rx_crc_errors +
st->rx_frame_errors +
st->rx_length_errors +
st->rx_missed_errors;
st->tx_errors += st->tx_aborted_errors;
return st;
}
static int __devinit s6gmac_probe(struct platform_device *pdev)
{
struct net_device *dev;
struct s6gmac *pd;
int res;
unsigned long i;
struct mii_bus *mb;
dev = alloc_etherdev(sizeof(*pd));
if (!dev) {
printk(KERN_ERR DRV_PRMT "etherdev alloc failed, aborting.\n");
return -ENOMEM;
}
dev->open = s6gmac_open;
dev->stop = s6gmac_stop;
dev->hard_start_xmit = s6gmac_tx;
dev->tx_timeout = s6gmac_tx_timeout;
dev->watchdog_timeo = HZ;
dev->get_stats = s6gmac_stats;
dev->irq = platform_get_irq(pdev, 0);
pd = netdev_priv(dev);
memset(pd, 0, sizeof(*pd));
spin_lock_init(&pd->lock);
pd->reg = platform_get_resource(pdev, IORESOURCE_MEM, 0)->start;
i = platform_get_resource(pdev, IORESOURCE_DMA, 0)->start;
pd->tx_dma = DMA_MASK_DMAC(i);
pd->tx_chan = DMA_INDEX_CHNL(i);
i = platform_get_resource(pdev, IORESOURCE_DMA, 1)->start;
pd->rx_dma = DMA_MASK_DMAC(i);
pd->rx_chan = DMA_INDEX_CHNL(i);
pd->io = platform_get_resource(pdev, IORESOURCE_IO, 0)->start;
res = request_irq(dev->irq, s6gmac_interrupt, 0, dev->name, dev);
if (res) {
printk(KERN_ERR DRV_PRMT "irq request failed: %d\n", dev->irq);
goto errirq;
}
res = register_netdev(dev);
if (res) {
printk(KERN_ERR DRV_PRMT "error registering device %s\n",
dev->name);
goto errdev;
}
mb = mdiobus_alloc();
if (!mb) {
printk(KERN_ERR DRV_PRMT "error allocating mii bus\n");
goto errmii;
}
mb->name = "s6gmac_mii";
mb->read = s6mii_read;
mb->write = s6mii_write;
mb->reset = s6mii_reset;
mb->priv = pd;
snprintf(mb->id, MII_BUS_ID_SIZE, "%s-%x", pdev->name, pdev->id);
mb->phy_mask = ~(1 << 0);
mb->irq = &pd->mii.irq[0];
for (i = 0; i < PHY_MAX_ADDR; i++) {
int n = platform_get_irq(pdev, i + 1);
if (n < 0)
n = PHY_POLL;
pd->mii.irq[i] = n;
}
mdiobus_register(mb);
pd->mii.bus = mb;
res = s6gmac_phy_start(dev);
if (res)
return res;
platform_set_drvdata(pdev, dev);
return 0;
errmii:
unregister_netdev(dev);
errdev:
free_irq(dev->irq, dev);
errirq:
free_netdev(dev);
return res;
}
static int __devexit s6gmac_remove(struct platform_device *pdev)
{
struct net_device *dev = platform_get_drvdata(pdev);
if (dev) {
struct s6gmac *pd = netdev_priv(dev);
mdiobus_unregister(pd->mii.bus);
unregister_netdev(dev);
free_irq(dev->irq, dev);
free_netdev(dev);
platform_set_drvdata(pdev, NULL);
}
return 0;
}
static int __init s6gmac_init(void)
{
printk(KERN_INFO DRV_PRMT "S6 GMAC ethernet driver\n");
return platform_driver_register(&s6gmac_driver);
}
static void __exit s6gmac_exit(void)
{
platform_driver_unregister(&s6gmac_driver);
}
