static void PRINT_PKT(u_char *buf, int length)
{
int i;
int remainder;
int lines;
lines = length / 16;
remainder = length % 16;
for (i = 0; i < lines ; i ++) {
int cur;
for (cur = 0; cur < 8; cur++) {
u_char a, b;
a = *buf++;
b = *buf++;
printk("%02x%02x ", a, b);
}
printk("\n");
}
for (i = 0; i < remainder/2 ; i++) {
u_char a, b;
a = *buf++;
b = *buf++;
printk("%02x%02x ", a, b);
}
printk("\n");
}
static void smc911x_reset(struct net_device *dev)
{
struct smc911x_local *lp = netdev_priv(dev);
unsigned int reg, timeout=0, resets=1, irq_cfg;
unsigned long flags;
DBG(SMC_DEBUG_FUNC, "%s: --> %s\n", dev->name, __func__);
if ((SMC_GET_PMT_CTRL(lp) & PMT_CTRL_READY_) == 0) {
SMC_SET_BYTE_TEST(lp, 0);
timeout=10;
do {
udelay(10);
reg = SMC_GET_PMT_CTRL(lp) & PMT_CTRL_READY_;
} while (--timeout && !reg);
if (timeout == 0) {
PRINTK("%s: smc911x_reset timeout waiting for PM restore\n", dev->name);
return;
}
}
spin_lock_irqsave(&lp->lock, flags);
SMC_SET_INT_EN(lp, 0);
spin_unlock_irqrestore(&lp->lock, flags);
while (resets--) {
SMC_SET_HW_CFG(lp, HW_CFG_SRST_);
timeout=10;
do {
udelay(10);
reg = SMC_GET_HW_CFG(lp);
if (reg & HW_CFG_SRST_TO_) {
PRINTK("%s: chip reset timeout, retrying...\n", dev->name);
resets++;
break;
}
} while (--timeout && (reg & HW_CFG_SRST_));
}
if (timeout == 0) {
PRINTK("%s: smc911x_reset timeout waiting for reset\n", dev->name);
return;
}
timeout=1000;
while (--timeout && (SMC_GET_E2P_CMD(lp) & E2P_CMD_EPC_BUSY_))
udelay(10);
if (timeout == 0){
PRINTK("%s: smc911x_reset timeout waiting for EEPROM busy\n", dev->name);
return;
}
SMC_SET_INT_EN(lp, 0);
SMC_ACK_INT(lp, -1);
SMC_SET_HW_CFG(lp, (lp->tx_fifo_kb & 0xF) << 16);
SMC_SET_FLOW(lp, FLOW_FCPT_ | FLOW_FCEN_);
SMC_SET_AFC_CFG(lp, lp->afc_cfg);
SMC_SET_GPIO_CFG(lp, 0x70070000);
irq_cfg = (1 << 24) | INT_CFG_IRQ_EN_ | INT_CFG_IRQ_TYPE_;
#ifdef SMC_DYNAMIC_BUS_CONFIG
if (lp->cfg.irq_polarity)
irq_cfg |= INT_CFG_IRQ_POL_;
#endif
SMC_SET_IRQ_CFG(lp, irq_cfg);
if (lp->pending_tx_skb != NULL) {
dev_kfree_skb (lp->pending_tx_skb);
lp->pending_tx_skb = NULL;
dev->stats.tx_errors++;
dev->stats.tx_aborted_errors++;
}
}
static void smc911x_enable(struct net_device *dev)
{
struct smc911x_local *lp = netdev_priv(dev);
unsigned mask, cfg, cr;
unsigned long flags;
DBG(SMC_DEBUG_FUNC, "%s: --> %s\n", dev->name, __func__);
spin_lock_irqsave(&lp->lock, flags);
SMC_SET_MAC_ADDR(lp, dev->dev_addr);
cfg = SMC_GET_HW_CFG(lp);
cfg &= HW_CFG_TX_FIF_SZ_ | 0xFFF;
cfg |= HW_CFG_SF_;
SMC_SET_HW_CFG(lp, cfg);
SMC_SET_FIFO_TDA(lp, 0xFF);
SMC_SET_FIFO_TSL(lp, 64);
SMC_SET_GPT_CFG(lp, GPT_CFG_TIMER_EN_ | 10000);
SMC_GET_MAC_CR(lp, cr);
cr |= MAC_CR_TXEN_ | MAC_CR_HBDIS_;
SMC_SET_MAC_CR(lp, cr);
SMC_SET_TX_CFG(lp, TX_CFG_TX_ON_);
SMC_SET_RX_CFG(lp, (2<<8) & RX_CFG_RXDOFF_);
if (cr & MAC_CR_RXEN_)
DBG(SMC_DEBUG_RX, "%s: Receiver already enabled\n", dev->name);
SMC_SET_MAC_CR(lp, cr | MAC_CR_RXEN_);
SMC_SET_FIFO_RSA(lp, 0x01);
SMC_SET_FIFO_RSL(lp, 0x00);
mask = INT_EN_TDFA_EN_ | INT_EN_TSFL_EN_ | INT_EN_RSFL_EN_ |
INT_EN_GPT_INT_EN_ | INT_EN_RXDFH_INT_EN_ | INT_EN_RXE_EN_ |
INT_EN_PHY_INT_EN_;
if (IS_REV_A(lp->revision))
mask|=INT_EN_RDFL_EN_;
else {
mask|=INT_EN_RDFO_EN_;
}
SMC_ENABLE_INT(lp, mask);
spin_unlock_irqrestore(&lp->lock, flags);
}
static void smc911x_shutdown(struct net_device *dev)
{
struct smc911x_local *lp = netdev_priv(dev);
unsigned cr;
unsigned long flags;
DBG(SMC_DEBUG_FUNC, "%s: --> %s\n", CARDNAME, __func__);
SMC_SET_INT_EN(lp, 0);
spin_lock_irqsave(&lp->lock, flags);
SMC_GET_MAC_CR(lp, cr);
cr &= ~(MAC_CR_TXEN_ | MAC_CR_RXEN_ | MAC_CR_HBDIS_);
SMC_SET_MAC_CR(lp, cr);
SMC_SET_TX_CFG(lp, TX_CFG_STOP_TX_);
spin_unlock_irqrestore(&lp->lock, flags);
}
static inline void smc911x_drop_pkt(struct net_device *dev)
{
struct smc911x_local *lp = netdev_priv(dev);
unsigned int fifo_count, timeout, reg;
DBG(SMC_DEBUG_FUNC | SMC_DEBUG_RX, "%s: --> %s\n", CARDNAME, __func__);
fifo_count = SMC_GET_RX_FIFO_INF(lp) & 0xFFFF;
if (fifo_count <= 4) {
while (fifo_count--)
SMC_GET_RX_FIFO(lp);
} else {
SMC_SET_RX_DP_CTRL(lp, RX_DP_CTRL_FFWD_BUSY_);
timeout=50;
do {
udelay(10);
reg = SMC_GET_RX_DP_CTRL(lp) & RX_DP_CTRL_FFWD_BUSY_;
} while (--timeout && reg);
if (timeout == 0) {
PRINTK("%s: timeout waiting for RX fast forward\n", dev->name);
}
}
}
static inline void smc911x_rcv(struct net_device *dev)
{
struct smc911x_local *lp = netdev_priv(dev);
unsigned int pkt_len, status;
struct sk_buff *skb;
unsigned char *data;
DBG(SMC_DEBUG_FUNC | SMC_DEBUG_RX, "%s: --> %s\n",
dev->name, __func__);
status = SMC_GET_RX_STS_FIFO(lp);
DBG(SMC_DEBUG_RX, "%s: Rx pkt len %d status 0x%08x\n",
dev->name, (status & 0x3fff0000) >> 16, status & 0xc000ffff);
pkt_len = (status & RX_STS_PKT_LEN_) >> 16;
if (status & RX_STS_ES_) {
dev->stats.rx_errors++;
if (status & RX_STS_CRC_ERR_)
dev->stats.rx_crc_errors++;
else {
if (status & RX_STS_LEN_ERR_)
dev->stats.rx_length_errors++;
if (status & RX_STS_MCAST_)
dev->stats.multicast++;
}
smc911x_drop_pkt(dev);
} else {
skb=dev_alloc_skb(pkt_len+32);
if (unlikely(skb == NULL)) {
PRINTK( "%s: Low memory, rcvd packet dropped.\n",
dev->name);
dev->stats.rx_dropped++;
smc911x_drop_pkt(dev);
return;
}
data = skb->data;
skb_reserve(skb, 2);
skb_put(skb,pkt_len-4);
#ifdef SMC_USE_DMA
{
unsigned int fifo;
fifo = SMC_GET_FIFO_INT(lp);
if (fifo & 0xFF) fifo--;
DBG(SMC_DEBUG_RX, "%s: Setting RX stat FIFO threshold to %d\n",
dev->name, fifo & 0xff);
SMC_SET_FIFO_INT(lp, fifo);
SMC_SET_RX_CFG(lp, RX_CFG_RX_END_ALGN16_ | ((2<<8) & RX_CFG_RXDOFF_));
lp->rxdma_active = 1;
lp->current_rx_skb = skb;
SMC_PULL_DATA(lp, data, (pkt_len+2+15) & ~15);
}
#else
SMC_SET_RX_CFG(lp, RX_CFG_RX_END_ALGN4_ | ((2<<8) & RX_CFG_RXDOFF_));
SMC_PULL_DATA(lp, data, pkt_len+2+3);
DBG(SMC_DEBUG_PKTS, "%s: Received packet\n", dev->name);
PRINT_PKT(data, ((pkt_len - 4) <= 64) ? pkt_len - 4 : 64);
skb->protocol = eth_type_trans(skb, dev);
netif_rx(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += pkt_len-4;
#endif
}
}
static void smc911x_hardware_send_pkt(struct net_device *dev)
{
struct smc911x_local *lp = netdev_priv(dev);
struct sk_buff *skb;
unsigned int cmdA, cmdB, len;
unsigned char *buf;
DBG(SMC_DEBUG_FUNC | SMC_DEBUG_TX, "%s: --> %s\n", dev->name, __func__);
BUG_ON(lp->pending_tx_skb == NULL);
skb = lp->pending_tx_skb;
lp->pending_tx_skb = NULL;
#ifdef SMC_USE_DMA
buf = (char*)((u32)(skb->data) & ~0xF);
len = (skb->len + 0xF + ((u32)skb->data & 0xF)) & ~0xF;
cmdA = (1<<24) | (((u32)skb->data & 0xF)<<16) |
TX_CMD_A_INT_FIRST_SEG_ | TX_CMD_A_INT_LAST_SEG_ |
skb->len;
#else
buf = (char*)((u32)skb->data & ~0x3);
len = (skb->len + 3 + ((u32)skb->data & 3)) & ~0x3;
cmdA = (((u32)skb->data & 0x3) << 16) |
TX_CMD_A_INT_FIRST_SEG_ | TX_CMD_A_INT_LAST_SEG_ |
skb->len;
#endif
cmdB = (skb->len << 16) | (skb->len & 0x7FF);
DBG(SMC_DEBUG_TX, "%s: TX PKT LENGTH 0x%04x (%d) BUF 0x%p CMDA 0x%08x CMDB 0x%08x\n",
dev->name, len, len, buf, cmdA, cmdB);
SMC_SET_TX_FIFO(lp, cmdA);
SMC_SET_TX_FIFO(lp, cmdB);
DBG(SMC_DEBUG_PKTS, "%s: Transmitted packet\n", dev->name);
PRINT_PKT(buf, len <= 64 ? len : 64);
#ifdef SMC_USE_DMA
lp->current_tx_skb = skb;
SMC_PUSH_DATA(lp, buf, len);
#else
SMC_PUSH_DATA(lp, buf, len);
dev->trans_start = jiffies;
dev_kfree_skb_irq(skb);
#endif
if (!lp->tx_throttle) {
netif_wake_queue(dev);
}
SMC_ENABLE_INT(lp, INT_EN_TDFA_EN_ | INT_EN_TSFL_EN_);
}
static int smc911x_hard_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct smc911x_local *lp = netdev_priv(dev);
unsigned int free;
unsigned long flags;
DBG(SMC_DEBUG_FUNC | SMC_DEBUG_TX, "%s: --> %s\n",
dev->name, __func__);
spin_lock_irqsave(&lp->lock, flags);
BUG_ON(lp->pending_tx_skb != NULL);
free = SMC_GET_TX_FIFO_INF(lp) & TX_FIFO_INF_TDFREE_;
DBG(SMC_DEBUG_TX, "%s: TX free space %d\n", dev->name, free);
if (free <= SMC911X_TX_FIFO_LOW_THRESHOLD) {
DBG(SMC_DEBUG_TX, "%s: Disabling data flow due to low FIFO space (%d)\n",
dev->name, free);
SMC_SET_FIFO_TDA(lp, (SMC911X_TX_FIFO_LOW_THRESHOLD)/64);
lp->tx_throttle = 1;
netif_stop_queue(dev);
}
if (unlikely(free < (skb->len + 8 + 15 + 15))) {
printk("%s: No Tx free space %d < %d\n",
dev->name, free, skb->len);
lp->pending_tx_skb = NULL;
dev->stats.tx_errors++;
dev->stats.tx_dropped++;
spin_unlock_irqrestore(&lp->lock, flags);
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
#ifdef SMC_USE_DMA
{
if (lp->txdma_active) {
DBG(SMC_DEBUG_TX | SMC_DEBUG_DMA, "%s: Tx DMA running, deferring packet\n", dev->name);
lp->pending_tx_skb = skb;
netif_stop_queue(dev);
spin_unlock_irqrestore(&lp->lock, flags);
return NETDEV_TX_OK;
} else {
DBG(SMC_DEBUG_TX | SMC_DEBUG_DMA, "%s: Activating Tx DMA\n", dev->name);
lp->txdma_active = 1;
}
}
#endif
lp->pending_tx_skb = skb;
smc911x_hardware_send_pkt(dev);
spin_unlock_irqrestore(&lp->lock, flags);
return NETDEV_TX_OK;
}
static void smc911x_tx(struct net_device *dev)
{
struct smc911x_local *lp = netdev_priv(dev);
unsigned int tx_status;
DBG(SMC_DEBUG_FUNC | SMC_DEBUG_TX, "%s: --> %s\n",
dev->name, __func__);
while (((SMC_GET_TX_FIFO_INF(lp) & TX_FIFO_INF_TSUSED_) >> 16) != 0) {
DBG(SMC_DEBUG_TX, "%s: Tx stat FIFO used 0x%04x\n",
dev->name,
(SMC_GET_TX_FIFO_INF(lp) & TX_FIFO_INF_TSUSED_) >> 16);
tx_status = SMC_GET_TX_STS_FIFO(lp);
dev->stats.tx_packets++;
dev->stats.tx_bytes+=tx_status>>16;
DBG(SMC_DEBUG_TX, "%s: Tx FIFO tag 0x%04x status 0x%04x\n",
dev->name, (tx_status & 0xffff0000) >> 16,
tx_status & 0x0000ffff);
if ((tx_status & TX_STS_ES_) && !(lp->ctl_rfduplx &&
!(tx_status & 0x00000306))) {
dev->stats.tx_errors++;
}
if (tx_status & TX_STS_MANY_COLL_) {
dev->stats.collisions+=16;
dev->stats.tx_aborted_errors++;
} else {
dev->stats.collisions+=(tx_status & TX_STS_COLL_CNT_) >> 3;
}
if ((tx_status & (TX_STS_LOC_ | TX_STS_NO_CARR_)) &&
!lp->ctl_rfduplx) {
dev->stats.tx_carrier_errors++;
}
if (tx_status & TX_STS_LATE_COLL_) {
dev->stats.collisions++;
dev->stats.tx_aborted_errors++;
}
}
}
static int smc911x_phy_read(struct net_device *dev, int phyaddr, int phyreg)
{
struct smc911x_local *lp = netdev_priv(dev);
unsigned int phydata;
SMC_GET_MII(lp, phyreg, phyaddr, phydata);
DBG(SMC_DEBUG_MISC, "%s: phyaddr=0x%x, phyreg=0x%02x, phydata=0x%04x\n",
__func__, phyaddr, phyreg, phydata);
return phydata;
}
static void smc911x_phy_write(struct net_device *dev, int phyaddr, int phyreg,
int phydata)
{
struct smc911x_local *lp = netdev_priv(dev);
DBG(SMC_DEBUG_MISC, "%s: phyaddr=0x%x, phyreg=0x%x, phydata=0x%x\n",
__func__, phyaddr, phyreg, phydata);
SMC_SET_MII(lp, phyreg, phyaddr, phydata);
}
static void smc911x_phy_detect(struct net_device *dev)
{
struct smc911x_local *lp = netdev_priv(dev);
int phyaddr;
unsigned int cfg, id1, id2;
DBG(SMC_DEBUG_FUNC, "%s: --> %s\n", dev->name, __func__);
lp->phy_type = 0;
switch(lp->version) {
case CHIP_9115:
case CHIP_9117:
case CHIP_9215:
case CHIP_9217:
cfg = SMC_GET_HW_CFG(lp);
if (cfg & HW_CFG_EXT_PHY_DET_) {
cfg &= ~HW_CFG_PHY_CLK_SEL_;
cfg |= HW_CFG_PHY_CLK_SEL_CLK_DIS_;
SMC_SET_HW_CFG(lp, cfg);
udelay(10);
cfg |= HW_CFG_EXT_PHY_EN_;
SMC_SET_HW_CFG(lp, cfg);
udelay(10);
cfg &= ~HW_CFG_PHY_CLK_SEL_;
cfg |= HW_CFG_PHY_CLK_SEL_EXT_PHY_;
SMC_SET_HW_CFG(lp, cfg);
udelay(10);
cfg |= HW_CFG_SMI_SEL_;
SMC_SET_HW_CFG(lp, cfg);
for (phyaddr = 1; phyaddr < 32; ++phyaddr) {
SMC_GET_PHY_ID1(lp, phyaddr & 31, id1);
SMC_GET_PHY_ID2(lp, phyaddr & 31, id2);
if (id1 != 0x0000 && id1 != 0xffff &&
id1 != 0x8000 && id2 != 0x0000 &&
id2 != 0xffff && id2 != 0x8000) {
lp->mii.phy_id = phyaddr & 31;
lp->phy_type = id1 << 16 | id2;
break;
}
}
if (phyaddr < 32)
break;
}
default:
SMC_GET_PHY_ID1(lp, 1, id1);
SMC_GET_PHY_ID2(lp, 1, id2);
lp->mii.phy_id = 1;
lp->phy_type = id1 << 16 | id2;
}
DBG(SMC_DEBUG_MISC, "%s: phy_id1=0x%x, phy_id2=0x%x phyaddr=0x%d\n",
dev->name, id1, id2, lp->mii.phy_id);
}
static int smc911x_phy_fixed(struct net_device *dev)
{
struct smc911x_local *lp = netdev_priv(dev);
int phyaddr = lp->mii.phy_id;
int bmcr;
DBG(SMC_DEBUG_FUNC, "%s: --> %s\n", dev->name, __func__);
SMC_GET_PHY_BMCR(lp, phyaddr, bmcr);
bmcr |= BMCR_PDOWN;
SMC_SET_PHY_BMCR(lp, phyaddr, bmcr);
bmcr &= ~BMCR_ANENABLE;
if (lp->ctl_rfduplx)
bmcr |= BMCR_FULLDPLX;
if (lp->ctl_rspeed == 100)
bmcr |= BMCR_SPEED100;
SMC_SET_PHY_BMCR(lp, phyaddr, bmcr);
bmcr &= ~BMCR_PDOWN;
SMC_SET_PHY_BMCR(lp, phyaddr, bmcr);
return 1;
}
static int smc911x_phy_reset(struct net_device *dev, int phy)
{
struct smc911x_local *lp = netdev_priv(dev);
int timeout;
unsigned long flags;
unsigned int reg;
DBG(SMC_DEBUG_FUNC, "%s: --> %s()\n", dev->name, __func__);
spin_lock_irqsave(&lp->lock, flags);
reg = SMC_GET_PMT_CTRL(lp);
reg &= ~0xfffff030;
reg |= PMT_CTRL_PHY_RST_;
SMC_SET_PMT_CTRL(lp, reg);
spin_unlock_irqrestore(&lp->lock, flags);
for (timeout = 2; timeout; timeout--) {
msleep(50);
spin_lock_irqsave(&lp->lock, flags);
reg = SMC_GET_PMT_CTRL(lp);
spin_unlock_irqrestore(&lp->lock, flags);
if (!(reg & PMT_CTRL_PHY_RST_)) {
udelay(500);
break;
}
}
return reg & PMT_CTRL_PHY_RST_;
}
static void smc911x_phy_powerdown(struct net_device *dev, int phy)
{
struct smc911x_local *lp = netdev_priv(dev);
unsigned int bmcr;
SMC_GET_PHY_BMCR(lp, phy, bmcr);
bmcr |= BMCR_PDOWN;
SMC_SET_PHY_BMCR(lp, phy, bmcr);
}
static void smc911x_phy_check_media(struct net_device *dev, int init)
{
struct smc911x_local *lp = netdev_priv(dev);
int phyaddr = lp->mii.phy_id;
unsigned int bmcr, cr;
DBG(SMC_DEBUG_FUNC, "%s: --> %s\n", dev->name, __func__);
if (mii_check_media(&lp->mii, netif_msg_link(lp), init)) {
SMC_GET_PHY_BMCR(lp, phyaddr, bmcr);
SMC_GET_MAC_CR(lp, cr);
if (lp->mii.full_duplex) {
DBG(SMC_DEBUG_MISC, "%s: Configuring for full-duplex mode\n", dev->name);
bmcr |= BMCR_FULLDPLX;
cr |= MAC_CR_RCVOWN_;
} else {
DBG(SMC_DEBUG_MISC, "%s: Configuring for half-duplex mode\n", dev->name);
bmcr &= ~BMCR_FULLDPLX;
cr &= ~MAC_CR_RCVOWN_;
}
SMC_SET_PHY_BMCR(lp, phyaddr, bmcr);
SMC_SET_MAC_CR(lp, cr);
}
}
static void smc911x_phy_configure(struct work_struct *work)
{
struct smc911x_local *lp = container_of(work, struct smc911x_local,
phy_configure);
struct net_device *dev = lp->netdev;
int phyaddr = lp->mii.phy_id;
int my_phy_caps;
int my_ad_caps;
int status;
unsigned long flags;
DBG(SMC_DEBUG_FUNC, "%s: --> %s()\n", dev->name, __func__);
if (lp->phy_type == 0)
return;
if (smc911x_phy_reset(dev, phyaddr)) {
printk("%s: PHY reset timed out\n", dev->name);
return;
}
spin_lock_irqsave(&lp->lock, flags);
SMC_SET_PHY_INT_MASK(lp, phyaddr, PHY_INT_MASK_ENERGY_ON_ |
PHY_INT_MASK_ANEG_COMP_ | PHY_INT_MASK_REMOTE_FAULT_ |
PHY_INT_MASK_LINK_DOWN_);
if (lp->mii.force_media) {
smc911x_phy_fixed(dev);
goto smc911x_phy_configure_exit;
}
SMC_GET_PHY_BMSR(lp, phyaddr, my_phy_caps);
if (!(my_phy_caps & BMSR_ANEGCAPABLE)) {
printk(KERN_INFO "Auto negotiation NOT supported\n");
smc911x_phy_fixed(dev);
goto smc911x_phy_configure_exit;
}
my_ad_caps = ADVERTISE_CSMA | ADVERTISE_PAUSE_CAP | ADVERTISE_PAUSE_ASYM;
if (my_phy_caps & BMSR_100BASE4)
my_ad_caps |= ADVERTISE_100BASE4;
if (my_phy_caps & BMSR_100FULL)
my_ad_caps |= ADVERTISE_100FULL;
if (my_phy_caps & BMSR_100HALF)
my_ad_caps |= ADVERTISE_100HALF;
if (my_phy_caps & BMSR_10FULL)
my_ad_caps |= ADVERTISE_10FULL;
if (my_phy_caps & BMSR_10HALF)
my_ad_caps |= ADVERTISE_10HALF;
if (lp->ctl_rspeed != 100)
my_ad_caps &= ~(ADVERTISE_100BASE4|ADVERTISE_100FULL|ADVERTISE_100HALF);
if (!lp->ctl_rfduplx)
my_ad_caps &= ~(ADVERTISE_100FULL|ADVERTISE_10FULL);
SMC_SET_PHY_MII_ADV(lp, phyaddr, my_ad_caps);
lp->mii.advertising = my_ad_caps;
udelay(10);
SMC_GET_PHY_MII_ADV(lp, phyaddr, status);
DBG(SMC_DEBUG_MISC, "%s: phy caps=0x%04x\n", dev->name, my_phy_caps);
DBG(SMC_DEBUG_MISC, "%s: phy advertised caps=0x%04x\n", dev->name, my_ad_caps);
SMC_SET_PHY_BMCR(lp, phyaddr, BMCR_ANENABLE | BMCR_ANRESTART);
smc911x_phy_check_media(dev, 1);
smc911x_phy_configure_exit:
spin_unlock_irqrestore(&lp->lock, flags);
}
static void smc911x_phy_interrupt(struct net_device *dev)
{
struct smc911x_local *lp = netdev_priv(dev);
int phyaddr = lp->mii.phy_id;
int status;
DBG(SMC_DEBUG_FUNC, "%s: --> %s\n", dev->name, __func__);
if (lp->phy_type == 0)
return;
smc911x_phy_check_media(dev, 0);
SMC_GET_PHY_INT_SRC(lp, phyaddr,status);
DBG(SMC_DEBUG_MISC, "%s: PHY interrupt status 0x%04x\n",
dev->name, status & 0xffff);
DBG(SMC_DEBUG_MISC, "%s: AFC_CFG 0x%08x\n",
dev->name, SMC_GET_AFC_CFG(lp));
}
static irqreturn_t smc911x_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct smc911x_local *lp = netdev_priv(dev);
unsigned int status, mask, timeout;
unsigned int rx_overrun=0, cr, pkts;
unsigned long flags;
DBG(SMC_DEBUG_FUNC, "%s: --> %s\n", dev->name, __func__);
spin_lock_irqsave(&lp->lock, flags);
if ((SMC_GET_IRQ_CFG(lp) & (INT_CFG_IRQ_INT_ | INT_CFG_IRQ_EN_)) !=
(INT_CFG_IRQ_INT_ | INT_CFG_IRQ_EN_)) {
spin_unlock_irqrestore(&lp->lock, flags);
return IRQ_NONE;
}
mask = SMC_GET_INT_EN(lp);
SMC_SET_INT_EN(lp, 0);
timeout = 8;
do {
status = SMC_GET_INT(lp);
DBG(SMC_DEBUG_MISC, "%s: INT 0x%08x MASK 0x%08x OUTSIDE MASK 0x%08x\n",
dev->name, status, mask, status & ~mask);
status &= mask;
if (!status)
break;
if (status & INT_STS_SW_INT_) {
SMC_ACK_INT(lp, INT_STS_SW_INT_);
mask &= ~INT_EN_SW_INT_EN_;
}
if (status & INT_STS_RXE_) {
SMC_ACK_INT(lp, INT_STS_RXE_);
dev->stats.rx_errors++;
}
if (status & INT_STS_RXDFH_INT_) {
SMC_ACK_INT(lp, INT_STS_RXDFH_INT_);
dev->stats.rx_dropped+=SMC_GET_RX_DROP(lp);
}
if (status & INT_STS_RXDF_INT_) {
SMC_ACK_INT(lp, INT_STS_RXDF_INT_);
}
if (status & INT_STS_RDFL_) {
if (IS_REV_A(lp->revision)) {
rx_overrun=1;
SMC_GET_MAC_CR(lp, cr);
cr &= ~MAC_CR_RXEN_;
SMC_SET_MAC_CR(lp, cr);
DBG(SMC_DEBUG_RX, "%s: RX overrun\n", dev->name);
dev->stats.rx_errors++;
dev->stats.rx_fifo_errors++;
}
SMC_ACK_INT(lp, INT_STS_RDFL_);
}
if (status & INT_STS_RDFO_) {
if (!IS_REV_A(lp->revision)) {
SMC_GET_MAC_CR(lp, cr);
cr &= ~MAC_CR_RXEN_;
SMC_SET_MAC_CR(lp, cr);
rx_overrun=1;
DBG(SMC_DEBUG_RX, "%s: RX overrun\n", dev->name);
dev->stats.rx_errors++;
dev->stats.rx_fifo_errors++;
}
SMC_ACK_INT(lp, INT_STS_RDFO_);
}
if ((status & INT_STS_RSFL_) || rx_overrun) {
unsigned int fifo;
DBG(SMC_DEBUG_RX, "%s: RX irq\n", dev->name);
fifo = SMC_GET_RX_FIFO_INF(lp);
pkts = (fifo & RX_FIFO_INF_RXSUSED_) >> 16;
DBG(SMC_DEBUG_RX, "%s: Rx FIFO pkts %d, bytes %d\n",
dev->name, pkts, fifo & 0xFFFF );
if (pkts != 0) {
#ifdef SMC_USE_DMA
unsigned int fifo;
if (lp->rxdma_active){
DBG(SMC_DEBUG_RX | SMC_DEBUG_DMA,
"%s: RX DMA active\n", dev->name);
fifo = SMC_GET_FIFO_INT(lp) & ~0xFF;
fifo |= pkts & 0xFF;
DBG(SMC_DEBUG_RX,
"%s: Setting RX stat FIFO threshold to %d\n",
dev->name, fifo & 0xff);
SMC_SET_FIFO_INT(lp, fifo);
} else
#endif
smc911x_rcv(dev);
}
SMC_ACK_INT(lp, INT_STS_RSFL_);
}
if (status & INT_STS_TDFA_) {
DBG(SMC_DEBUG_TX, "%s: TX data FIFO space available irq\n", dev->name);
SMC_SET_FIFO_TDA(lp, 0xFF);
lp->tx_throttle = 0;
#ifdef SMC_USE_DMA
if (!lp->txdma_active)
#endif
netif_wake_queue(dev);
SMC_ACK_INT(lp, INT_STS_TDFA_);
}
#if 1
if (status & (INT_STS_TSFL_ | INT_STS_GPT_INT_)) {
DBG(SMC_DEBUG_TX | SMC_DEBUG_MISC,
"%s: Tx stat FIFO limit (%d) /GPT irq\n",
dev->name, (SMC_GET_FIFO_INT(lp) & 0x00ff0000) >> 16);
smc911x_tx(dev);
SMC_SET_GPT_CFG(lp, GPT_CFG_TIMER_EN_ | 10000);
SMC_ACK_INT(lp, INT_STS_TSFL_);
SMC_ACK_INT(lp, INT_STS_TSFL_ | INT_STS_GPT_INT_);
}
#else
if (status & INT_STS_TSFL_) {
DBG(SMC_DEBUG_TX, "%s: TX status FIFO limit (%d) irq\n", dev->name, );
smc911x_tx(dev);
SMC_ACK_INT(lp, INT_STS_TSFL_);
}
if (status & INT_STS_GPT_INT_) {
DBG(SMC_DEBUG_RX, "%s: IRQ_CFG 0x%08x FIFO_INT 0x%08x RX_CFG 0x%08x\n",
dev->name,
SMC_GET_IRQ_CFG(lp),
SMC_GET_FIFO_INT(lp),
SMC_GET_RX_CFG(lp));
DBG(SMC_DEBUG_RX, "%s: Rx Stat FIFO Used 0x%02x "
"Data FIFO Used 0x%04x Stat FIFO 0x%08x\n",
dev->name,
(SMC_GET_RX_FIFO_INF(lp) & 0x00ff0000) >> 16,
SMC_GET_RX_FIFO_INF(lp) & 0xffff,
SMC_GET_RX_STS_FIFO_PEEK(lp));
SMC_SET_GPT_CFG(lp, GPT_CFG_TIMER_EN_ | 10000);
SMC_ACK_INT(lp, INT_STS_GPT_INT_);
}
#endif
if (status & INT_STS_PHY_INT_) {
DBG(SMC_DEBUG_MISC, "%s: PHY irq\n", dev->name);
smc911x_phy_interrupt(dev);
SMC_ACK_INT(lp, INT_STS_PHY_INT_);
}
} while (--timeout);
SMC_SET_INT_EN(lp, mask);
DBG(SMC_DEBUG_MISC, "%s: Interrupt done (%d loops)\n",
dev->name, 8-timeout);
spin_unlock_irqrestore(&lp->lock, flags);
return IRQ_HANDLED;
}
static void
smc911x_tx_dma_irq(int dma, void *data)
{
struct net_device *dev = (struct net_device *)data;
struct smc911x_local *lp = netdev_priv(dev);
struct sk_buff *skb = lp->current_tx_skb;
unsigned long flags;
DBG(SMC_DEBUG_FUNC, "%s: --> %s\n", dev->name, __func__);
DBG(SMC_DEBUG_TX | SMC_DEBUG_DMA, "%s: TX DMA irq handler\n", dev->name);
SMC_DMA_ACK_IRQ(dev, dma);
BUG_ON(skb == NULL);
dma_unmap_single(NULL, tx_dmabuf, tx_dmalen, DMA_TO_DEVICE);
dev->trans_start = jiffies;
dev_kfree_skb_irq(skb);
lp->current_tx_skb = NULL;
if (lp->pending_tx_skb != NULL)
smc911x_hardware_send_pkt(dev);
else {
DBG(SMC_DEBUG_TX | SMC_DEBUG_DMA,
"%s: No pending Tx packets. DMA disabled\n", dev->name);
spin_lock_irqsave(&lp->lock, flags);
lp->txdma_active = 0;
if (!lp->tx_throttle) {
netif_wake_queue(dev);
}
spin_unlock_irqrestore(&lp->lock, flags);
}
DBG(SMC_DEBUG_TX | SMC_DEBUG_DMA,
"%s: TX DMA irq completed\n", dev->name);
}
static void
smc911x_rx_dma_irq(int dma, void *data)
{
struct net_device *dev = (struct net_device *)data;
unsigned long ioaddr = dev->base_addr;
struct smc911x_local *lp = netdev_priv(dev);
struct sk_buff *skb = lp->current_rx_skb;
unsigned long flags;
unsigned int pkts;
DBG(SMC_DEBUG_FUNC, "%s: --> %s\n", dev->name, __func__);
DBG(SMC_DEBUG_RX | SMC_DEBUG_DMA, "%s: RX DMA irq handler\n", dev->name);
SMC_DMA_ACK_IRQ(dev, dma);
dma_unmap_single(NULL, rx_dmabuf, rx_dmalen, DMA_FROM_DEVICE);
BUG_ON(skb == NULL);
lp->current_rx_skb = NULL;
PRINT_PKT(skb->data, skb->len);
skb->protocol = eth_type_trans(skb, dev);
dev->stats.rx_packets++;
dev->stats.rx_bytes += skb->len;
netif_rx(skb);
spin_lock_irqsave(&lp->lock, flags);
pkts = (SMC_GET_RX_FIFO_INF(lp) & RX_FIFO_INF_RXSUSED_) >> 16;
if (pkts != 0) {
smc911x_rcv(dev);
}else {
lp->rxdma_active = 0;
}
spin_unlock_irqrestore(&lp->lock, flags);
DBG(SMC_DEBUG_RX | SMC_DEBUG_DMA,
"%s: RX DMA irq completed. DMA RX FIFO PKTS %d\n",
dev->name, pkts);
}
static void smc911x_poll_controller(struct net_device *dev)
{
disable_irq(dev->irq);
smc911x_interrupt(dev->irq, dev);
enable_irq(dev->irq);
}
static void smc911x_timeout(struct net_device *dev)
{
struct smc911x_local *lp = netdev_priv(dev);
int status, mask;
unsigned long flags;
DBG(SMC_DEBUG_FUNC, "%s: --> %s\n", dev->name, __func__);
spin_lock_irqsave(&lp->lock, flags);
status = SMC_GET_INT(lp);
mask = SMC_GET_INT_EN(lp);
spin_unlock_irqrestore(&lp->lock, flags);
DBG(SMC_DEBUG_MISC, "%s: INT 0x%02x MASK 0x%02x\n",
dev->name, status, mask);
mask = SMC_GET_TX_CFG(lp);
SMC_SET_TX_CFG(lp, mask | TX_CFG_TXS_DUMP_ | TX_CFG_TXD_DUMP_);
if (lp->phy_type != 0)
schedule_work(&lp->phy_configure);
dev->trans_start = jiffies;
netif_wake_queue(dev);
}
static void smc911x_set_multicast_list(struct net_device *dev)
{
struct smc911x_local *lp = netdev_priv(dev);
unsigned int multicast_table[2];
unsigned int mcr, update_multicast = 0;
unsigned long flags;
DBG(SMC_DEBUG_FUNC, "%s: --> %s\n", dev->name, __func__);
spin_lock_irqsave(&lp->lock, flags);
SMC_GET_MAC_CR(lp, mcr);
spin_unlock_irqrestore(&lp->lock, flags);
if (dev->flags & IFF_PROMISC) {
DBG(SMC_DEBUG_MISC, "%s: RCR_PRMS\n", dev->name);
mcr |= MAC_CR_PRMS_;
}
else if (dev->flags & IFF_ALLMULTI || netdev_mc_count(dev) > 16) {
DBG(SMC_DEBUG_MISC, "%s: RCR_ALMUL\n", dev->name);
mcr |= MAC_CR_MCPAS_;
}
else if (!netdev_mc_empty(dev)) {
struct netdev_hw_addr *ha;
mcr |= MAC_CR_HPFILT_;
memset(multicast_table, 0, sizeof(multicast_table));
netdev_for_each_mc_addr(ha, dev) {
u32 position;
if (!(*ha->addr & 1))
continue;
position = ether_crc(ETH_ALEN, ha->addr)>>26;
multicast_table[position>>5] |= 1 << (position&0x1f);
}
mcr &= ~(MAC_CR_PRMS_ | MAC_CR_MCPAS_);
update_multicast = 1;
} else {
DBG(SMC_DEBUG_MISC, "%s: ~(MAC_CR_PRMS_|MAC_CR_MCPAS_)\n",
dev->name);
mcr &= ~(MAC_CR_PRMS_ | MAC_CR_MCPAS_);
memset(multicast_table, 0, sizeof(multicast_table));
update_multicast = 1;
}
spin_lock_irqsave(&lp->lock, flags);
SMC_SET_MAC_CR(lp, mcr);
if (update_multicast) {
DBG(SMC_DEBUG_MISC,
"%s: update mcast hash table 0x%08x 0x%08x\n",
dev->name, multicast_table[0], multicast_table[1]);
SMC_SET_HASHL(lp, multicast_table[0]);
SMC_SET_HASHH(lp, multicast_table[1]);
}
spin_unlock_irqrestore(&lp->lock, flags);
}
static int
smc911x_open(struct net_device *dev)
{
struct smc911x_local *lp = netdev_priv(dev);
DBG(SMC_DEBUG_FUNC, "%s: --> %s\n", dev->name, __func__);
if (!is_valid_ether_addr(dev->dev_addr)) {
PRINTK("%s: no valid ethernet hw addr\n", __func__);
return -EINVAL;
}
smc911x_reset(dev);
smc911x_phy_configure(&lp->phy_configure);
smc911x_enable(dev);
netif_start_queue(dev);
return 0;
}
static int smc911x_close(struct net_device *dev)
{
struct smc911x_local *lp = netdev_priv(dev);
DBG(SMC_DEBUG_FUNC, "%s: --> %s\n", dev->name, __func__);
netif_stop_queue(dev);
netif_carrier_off(dev);
smc911x_shutdown(dev);
if (lp->phy_type != 0) {
cancel_work_sync(&lp->phy_configure);
smc911x_phy_powerdown(dev, lp->mii.phy_id);
}
if (lp->pending_tx_skb) {
dev_kfree_skb(lp->pending_tx_skb);
lp->pending_tx_skb = NULL;
}
return 0;
}
static int
smc911x_ethtool_getsettings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct smc911x_local *lp = netdev_priv(dev);
int ret, status;
unsigned long flags;
DBG(SMC_DEBUG_FUNC, "%s: --> %s\n", dev->name, __func__);
cmd->maxtxpkt = 1;
cmd->maxrxpkt = 1;
if (lp->phy_type != 0) {
spin_lock_irqsave(&lp->lock, flags);
ret = mii_ethtool_gset(&lp->mii, cmd);
spin_unlock_irqrestore(&lp->lock, flags);
} else {
cmd->supported = SUPPORTED_10baseT_Half |
SUPPORTED_10baseT_Full |
SUPPORTED_TP | SUPPORTED_AUI;
if (lp->ctl_rspeed == 10)
ethtool_cmd_speed_set(cmd, SPEED_10);
else if (lp->ctl_rspeed == 100)
ethtool_cmd_speed_set(cmd, SPEED_100);
cmd->autoneg = AUTONEG_DISABLE;
if (lp->mii.phy_id==1)
cmd->transceiver = XCVR_INTERNAL;
else
cmd->transceiver = XCVR_EXTERNAL;
cmd->port = 0;
SMC_GET_PHY_SPECIAL(lp, lp->mii.phy_id, status);
cmd->duplex =
(status & (PHY_SPECIAL_SPD_10FULL_ | PHY_SPECIAL_SPD_100FULL_)) ?
DUPLEX_FULL : DUPLEX_HALF;
ret = 0;
}
return ret;
}
static int
smc911x_ethtool_setsettings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct smc911x_local *lp = netdev_priv(dev);
int ret;
unsigned long flags;
if (lp->phy_type != 0) {
spin_lock_irqsave(&lp->lock, flags);
ret = mii_ethtool_sset(&lp->mii, cmd);
spin_unlock_irqrestore(&lp->lock, flags);
} else {
if (cmd->autoneg != AUTONEG_DISABLE ||
cmd->speed != SPEED_10 ||
(cmd->duplex != DUPLEX_HALF && cmd->duplex != DUPLEX_FULL) ||
(cmd->port != PORT_TP && cmd->port != PORT_AUI))
return -EINVAL;
lp->ctl_rfduplx = cmd->duplex == DUPLEX_FULL;
ret = 0;
}
return ret;
}
static void
smc911x_ethtool_getdrvinfo(struct net_device *dev, struct ethtool_drvinfo *info)
{
strncpy(info->driver, CARDNAME, sizeof(info->driver));
strncpy(info->version, version, sizeof(info->version));
strncpy(info->bus_info, dev_name(dev->dev.parent), sizeof(info->bus_info));
}
static int smc911x_ethtool_nwayreset(struct net_device *dev)
{
struct smc911x_local *lp = netdev_priv(dev);
int ret = -EINVAL;
unsigned long flags;
if (lp->phy_type != 0) {
spin_lock_irqsave(&lp->lock, flags);
ret = mii_nway_restart(&lp->mii);
spin_unlock_irqrestore(&lp->lock, flags);
}
return ret;
}
static u32 smc911x_ethtool_getmsglevel(struct net_device *dev)
{
struct smc911x_local *lp = netdev_priv(dev);
return lp->msg_enable;
}
static void smc911x_ethtool_setmsglevel(struct net_device *dev, u32 level)
{
struct smc911x_local *lp = netdev_priv(dev);
lp->msg_enable = level;
}
static int smc911x_ethtool_getregslen(struct net_device *dev)
{
return (((E2P_CMD - ID_REV)/4 + 1) +
(WUCSR - MAC_CR)+1 + 32) * sizeof(u32);
}
static void smc911x_ethtool_getregs(struct net_device *dev,
struct ethtool_regs* regs, void *buf)
{
struct smc911x_local *lp = netdev_priv(dev);
unsigned long flags;
u32 reg,i,j=0;
u32 *data = (u32*)buf;
regs->version = lp->version;
for(i=ID_REV;i<=E2P_CMD;i+=4) {
data[j++] = SMC_inl(lp, i);
}
for(i=MAC_CR;i<=WUCSR;i++) {
spin_lock_irqsave(&lp->lock, flags);
SMC_GET_MAC_CSR(lp, i, reg);
spin_unlock_irqrestore(&lp->lock, flags);
data[j++] = reg;
}
for(i=0;i<=31;i++) {
spin_lock_irqsave(&lp->lock, flags);
SMC_GET_MII(lp, i, lp->mii.phy_id, reg);
spin_unlock_irqrestore(&lp->lock, flags);
data[j++] = reg & 0xFFFF;
}
}
static int smc911x_ethtool_wait_eeprom_ready(struct net_device *dev)
{
struct smc911x_local *lp = netdev_priv(dev);
unsigned int timeout;
int e2p_cmd;
e2p_cmd = SMC_GET_E2P_CMD(lp);
for(timeout=10;(e2p_cmd & E2P_CMD_EPC_BUSY_) && timeout; timeout--) {
if (e2p_cmd & E2P_CMD_EPC_TIMEOUT_) {
PRINTK("%s: %s timeout waiting for EEPROM to respond\n",
dev->name, __func__);
return -EFAULT;
}
mdelay(1);
e2p_cmd = SMC_GET_E2P_CMD(lp);
}
if (timeout == 0) {
PRINTK("%s: %s timeout waiting for EEPROM CMD not busy\n",
dev->name, __func__);
return -ETIMEDOUT;
}
return 0;
}
static inline int smc911x_ethtool_write_eeprom_cmd(struct net_device *dev,
int cmd, int addr)
{
struct smc911x_local *lp = netdev_priv(dev);
int ret;
if ((ret = smc911x_ethtool_wait_eeprom_ready(dev))!=0)
return ret;
SMC_SET_E2P_CMD(lp, E2P_CMD_EPC_BUSY_ |
((cmd) & (0x7<<28)) |
((addr) & 0xFF));
return 0;
}
static inline int smc911x_ethtool_read_eeprom_byte(struct net_device *dev,
u8 *data)
{
struct smc911x_local *lp = netdev_priv(dev);
int ret;
if ((ret = smc911x_ethtool_wait_eeprom_ready(dev))!=0)
return ret;
*data = SMC_GET_E2P_DATA(lp);
return 0;
}
static inline int smc911x_ethtool_write_eeprom_byte(struct net_device *dev,
u8 data)
{
struct smc911x_local *lp = netdev_priv(dev);
int ret;
if ((ret = smc911x_ethtool_wait_eeprom_ready(dev))!=0)
return ret;
SMC_SET_E2P_DATA(lp, data);
return 0;
}
static int smc911x_ethtool_geteeprom(struct net_device *dev,
struct ethtool_eeprom *eeprom, u8 *data)
{
u8 eebuf[SMC911X_EEPROM_LEN];
int i, ret;
for(i=0;i<SMC911X_EEPROM_LEN;i++) {
if ((ret=smc911x_ethtool_write_eeprom_cmd(dev, E2P_CMD_EPC_CMD_READ_, i ))!=0)
return ret;
if ((ret=smc911x_ethtool_read_eeprom_byte(dev, &eebuf[i]))!=0)
return ret;
}
memcpy(data, eebuf+eeprom->offset, eeprom->len);
return 0;
}
static int smc911x_ethtool_seteeprom(struct net_device *dev,
struct ethtool_eeprom *eeprom, u8 *data)
{
int i, ret;
if ((ret=smc911x_ethtool_write_eeprom_cmd(dev, E2P_CMD_EPC_CMD_EWEN_, 0 ))!=0)
return ret;
for(i=eeprom->offset;i<(eeprom->offset+eeprom->len);i++) {
if ((ret=smc911x_ethtool_write_eeprom_cmd(dev, E2P_CMD_EPC_CMD_ERASE_, i ))!=0)
return ret;
if ((ret=smc911x_ethtool_write_eeprom_byte(dev, *data))!=0)
return ret;
if ((ret=smc911x_ethtool_write_eeprom_cmd(dev, E2P_CMD_EPC_CMD_WRITE_, i ))!=0)
return ret;
}
return 0;
}
static int smc911x_ethtool_geteeprom_len(struct net_device *dev)
{
return SMC911X_EEPROM_LEN;
}
static int __devinit smc911x_findirq(struct net_device *dev)
{
struct smc911x_local *lp = netdev_priv(dev);
int timeout = 20;
unsigned long cookie;
DBG(SMC_DEBUG_FUNC, "--> %s\n", __func__);
cookie = probe_irq_on();
SMC_SET_INT_EN(lp, INT_EN_SW_INT_EN_);
do {
int int_status;
udelay(10);
int_status = SMC_GET_INT_EN(lp);
if (int_status & INT_EN_SW_INT_EN_)
break;
} while (--timeout);
SMC_SET_INT_EN(lp, 0);
return probe_irq_off(cookie);
}
static int __devinit smc911x_probe(struct net_device *dev)
{
struct smc911x_local *lp = netdev_priv(dev);
int i, retval;
unsigned int val, chip_id, revision;
const char *version_string;
unsigned long irq_flags;
DBG(SMC_DEBUG_FUNC, "%s: --> %s\n", dev->name, __func__);
val = SMC_GET_BYTE_TEST(lp);
DBG(SMC_DEBUG_MISC, "%s: endian probe returned 0x%04x\n", CARDNAME, val);
if (val != 0x87654321) {
printk(KERN_ERR "Invalid chip endian 0x%08x\n",val);
retval = -ENODEV;
goto err_out;
}
chip_id = SMC_GET_PN(lp);
DBG(SMC_DEBUG_MISC, "%s: id probe returned 0x%04x\n", CARDNAME, chip_id);
for(i=0;chip_ids[i].id != 0; i++) {
if (chip_ids[i].id == chip_id) break;
}
if (!chip_ids[i].id) {
printk(KERN_ERR "Unknown chip ID %04x\n", chip_id);
retval = -ENODEV;
goto err_out;
}
version_string = chip_ids[i].name;
revision = SMC_GET_REV(lp);
DBG(SMC_DEBUG_MISC, "%s: revision = 0x%04x\n", CARDNAME, revision);
DBG(SMC_DEBUG_MISC, "%s: Found a %s\n", CARDNAME, chip_ids[i].name);
if ((tx_fifo_kb < 2) || (tx_fifo_kb > 14)) {
printk(KERN_ERR "Invalid TX FIFO size requested %d\n", tx_fifo_kb);
retval = -EINVAL;
goto err_out;
}
lp->version = chip_ids[i].id;
lp->revision = revision;
lp->tx_fifo_kb = tx_fifo_kb;
lp->tx_fifo_size=(lp->tx_fifo_kb<<10) - 512;
lp->rx_fifo_size= ((0x4000 - 512 - lp->tx_fifo_size) / 16) * 15;
switch(lp->tx_fifo_kb) {
case 2:
lp->afc_cfg=0x008C46AF;break;
case 3:
lp->afc_cfg=0x0082419F;break;
case 4:
lp->afc_cfg=0x00783C9F;break;
case 5:
lp->afc_cfg=0x006E374F;break;
case 6:
lp->afc_cfg=0x0064328F;break;
case 7:
lp->afc_cfg=0x005A2D7F;break;
case 8:
lp->afc_cfg=0x0050287F;break;
case 9:
lp->afc_cfg=0x0046236F;break;
case 10:
lp->afc_cfg=0x003C1E6F;break;
case 11:
lp->afc_cfg=0x0032195F;break;
case 12:
lp->afc_cfg=0x0024124F;break;
case 13:
lp->afc_cfg=0x0015073F;break;
case 14:
lp->afc_cfg=0x0006032F;break;
default:
PRINTK("%s: ERROR -- no AFC_CFG setting found",
dev->name);
break;
}
DBG(SMC_DEBUG_MISC | SMC_DEBUG_TX | SMC_DEBUG_RX,
"%s: tx_fifo %d rx_fifo %d afc_cfg 0x%08x\n", CARDNAME,
lp->tx_fifo_size, lp->rx_fifo_size, lp->afc_cfg);
spin_lock_init(&lp->lock);
SMC_GET_MAC_ADDR(lp, dev->dev_addr);
smc911x_reset(dev);
if (dev->irq < 1) {
int trials;
trials = 3;
while (trials--) {
dev->irq = smc911x_findirq(dev);
if (dev->irq)
break;
smc911x_reset(dev);
}
}
if (dev->irq == 0) {
printk("%s: Couldn't autodetect your IRQ. Use irq=xx.\n",
dev->name);
retval = -ENODEV;
goto err_out;
}
dev->irq = irq_canonicalize(dev->irq);
ether_setup(dev);
dev->netdev_ops = &smc911x_netdev_ops;
dev->watchdog_timeo = msecs_to_jiffies(watchdog);
dev->ethtool_ops = &smc911x_ethtool_ops;
INIT_WORK(&lp->phy_configure, smc911x_phy_configure);
lp->mii.phy_id_mask = 0x1f;
lp->mii.reg_num_mask = 0x1f;
lp->mii.force_media = 0;
lp->mii.full_duplex = 0;
lp->mii.dev = dev;
lp->mii.mdio_read = smc911x_phy_read;
lp->mii.mdio_write = smc911x_phy_write;
smc911x_phy_detect(dev);
lp->msg_enable = NETIF_MSG_LINK;
lp->ctl_rfduplx = 1;
lp->ctl_rspeed = 100;
#ifdef SMC_DYNAMIC_BUS_CONFIG
irq_flags = lp->cfg.irq_flags;
#else
irq_flags = IRQF_SHARED | SMC_IRQ_SENSE;
#endif
retval = request_irq(dev->irq, smc911x_interrupt,
irq_flags, dev->name, dev);
if (retval)
goto err_out;
#ifdef SMC_USE_DMA
lp->rxdma = SMC_DMA_REQUEST(dev, smc911x_rx_dma_irq);
lp->txdma = SMC_DMA_REQUEST(dev, smc911x_tx_dma_irq);
lp->rxdma_active = 0;
lp->txdma_active = 0;
dev->dma = lp->rxdma;
#endif
retval = register_netdev(dev);
if (retval == 0) {
printk("%s: %s (rev %d) at %#lx IRQ %d",
dev->name, version_string, lp->revision,
dev->base_addr, dev->irq);
#ifdef SMC_USE_DMA
if (lp->rxdma != -1)
printk(" RXDMA %d ", lp->rxdma);
if (lp->txdma != -1)
printk("TXDMA %d", lp->txdma);
#endif
printk("\n");
if (!is_valid_ether_addr(dev->dev_addr)) {
printk("%s: Invalid ethernet MAC address. Please "
"set using ifconfig\n", dev->name);
} else {
printk("%s: Ethernet addr: %pM\n",
dev->name, dev->dev_addr);
}
if (lp->phy_type == 0) {
PRINTK("%s: No PHY found\n", dev->name);
} else if ((lp->phy_type & ~0xff) == LAN911X_INTERNAL_PHY_ID) {
PRINTK("%s: LAN911x Internal PHY\n", dev->name);
} else {
PRINTK("%s: External PHY 0x%08x\n", dev->name, lp->phy_type);
}
}
err_out:
#ifdef SMC_USE_DMA
if (retval) {
if (lp->rxdma != -1) {
SMC_DMA_FREE(dev, lp->rxdma);
}
if (lp->txdma != -1) {
SMC_DMA_FREE(dev, lp->txdma);
}
}
#endif
return retval;
}
static int __devinit smc911x_drv_probe(struct platform_device *pdev)
{
struct net_device *ndev;
struct resource *res;
struct smc911x_local *lp;
unsigned int *addr;
int ret;
DBG(SMC_DEBUG_FUNC, "--> %s\n", __func__);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
ret = -ENODEV;
goto out;
}
if (!request_mem_region(res->start, SMC911X_IO_EXTENT, CARDNAME)) {
ret = -EBUSY;
goto out;
}
ndev = alloc_etherdev(sizeof(struct smc911x_local));
if (!ndev) {
printk("%s: could not allocate device.\n", CARDNAME);
ret = -ENOMEM;
goto release_1;
}
SET_NETDEV_DEV(ndev, &pdev->dev);
ndev->dma = (unsigned char)-1;
ndev->irq = platform_get_irq(pdev, 0);
lp = netdev_priv(ndev);
lp->netdev = ndev;
#ifdef SMC_DYNAMIC_BUS_CONFIG
{
struct smc911x_platdata *pd = pdev->dev.platform_data;
if (!pd) {
ret = -EINVAL;
goto release_both;
}
memcpy(&lp->cfg, pd, sizeof(lp->cfg));
}
#endif
addr = ioremap(res->start, SMC911X_IO_EXTENT);
if (!addr) {
ret = -ENOMEM;
goto release_both;
}
platform_set_drvdata(pdev, ndev);
lp->base = addr;
ndev->base_addr = res->start;
ret = smc911x_probe(ndev);
if (ret != 0) {
platform_set_drvdata(pdev, NULL);
iounmap(addr);
release_both:
free_netdev(ndev);
release_1:
release_mem_region(res->start, SMC911X_IO_EXTENT);
out:
printk("%s: not found (%d).\n", CARDNAME, ret);
}
#ifdef SMC_USE_DMA
else {
lp->physaddr = res->start;
lp->dev = &pdev->dev;
}
#endif
return ret;
}
static int __devexit smc911x_drv_remove(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct smc911x_local *lp = netdev_priv(ndev);
struct resource *res;
DBG(SMC_DEBUG_FUNC, "--> %s\n", __func__);
platform_set_drvdata(pdev, NULL);
unregister_netdev(ndev);
free_irq(ndev->irq, ndev);
#ifdef SMC_USE_DMA
{
if (lp->rxdma != -1) {
SMC_DMA_FREE(dev, lp->rxdma);
}
if (lp->txdma != -1) {
SMC_DMA_FREE(dev, lp->txdma);
}
}
#endif
iounmap(lp->base);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(res->start, SMC911X_IO_EXTENT);
free_netdev(ndev);
return 0;
}
static int smc911x_drv_suspend(struct platform_device *dev, pm_message_t state)
{
struct net_device *ndev = platform_get_drvdata(dev);
struct smc911x_local *lp = netdev_priv(ndev);
DBG(SMC_DEBUG_FUNC, "--> %s\n", __func__);
if (ndev) {
if (netif_running(ndev)) {
netif_device_detach(ndev);
smc911x_shutdown(ndev);
#if POWER_DOWN
SMC_SET_PMT_CTRL(lp, 2<<12);
#endif
}
}
return 0;
}
static int smc911x_drv_resume(struct platform_device *dev)
{
struct net_device *ndev = platform_get_drvdata(dev);
DBG(SMC_DEBUG_FUNC, "--> %s\n", __func__);
if (ndev) {
struct smc911x_local *lp = netdev_priv(ndev);
if (netif_running(ndev)) {
smc911x_reset(ndev);
if (lp->phy_type != 0)
smc911x_phy_configure(&lp->phy_configure);
smc911x_enable(ndev);
netif_device_attach(ndev);
}
}
return 0;
}
static int __init smc911x_init(void)
{
return platform_driver_register(&smc911x_driver);
}
static void __exit smc911x_cleanup(void)
{
platform_driver_unregister(&smc911x_driver);
}
