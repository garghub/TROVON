static void PRINT_PKT(u_char *buf, int length)
{
int i;
int remainder;
int lines;
lines = length / 16;
remainder = length % 16;
for (i = 0; i < lines ; i ++) {
int cur;
printk(KERN_DEBUG);
for (cur = 0; cur < 8; cur++) {
u_char a, b;
a = *buf++;
b = *buf++;
pr_cont("%02x%02x ", a, b);
}
pr_cont("\n");
}
printk(KERN_DEBUG);
for (i = 0; i < remainder/2 ; i++) {
u_char a, b;
a = *buf++;
b = *buf++;
pr_cont("%02x%02x ", a, b);
}
pr_cont("\n");
}
static inline void PRINT_PKT(u_char *buf, int length) { }
static void smc_reset(struct net_device *dev)
{
struct smc_local *lp = netdev_priv(dev);
void __iomem *ioaddr = lp->base;
unsigned int ctl, cfg;
struct sk_buff *pending_skb;
DBG(2, dev, "%s\n", __func__);
spin_lock_irq(&lp->lock);
SMC_SELECT_BANK(lp, 2);
SMC_SET_INT_MASK(lp, 0);
pending_skb = lp->pending_tx_skb;
lp->pending_tx_skb = NULL;
spin_unlock_irq(&lp->lock);
if (pending_skb) {
dev_kfree_skb(pending_skb);
dev->stats.tx_errors++;
dev->stats.tx_aborted_errors++;
}
SMC_SELECT_BANK(lp, 0);
SMC_SET_RCR(lp, RCR_SOFTRST);
SMC_SELECT_BANK(lp, 1);
cfg = CONFIG_DEFAULT;
if (lp->cfg.flags & SMC91X_NOWAIT)
cfg |= CONFIG_NO_WAIT;
cfg |= CONFIG_EPH_POWER_EN;
SMC_SET_CONFIG(lp, cfg);
udelay(1);
SMC_SELECT_BANK(lp, 0);
SMC_SET_RCR(lp, RCR_CLEAR);
SMC_SET_TCR(lp, TCR_CLEAR);
SMC_SELECT_BANK(lp, 1);
ctl = SMC_GET_CTL(lp) | CTL_LE_ENABLE;
if(!THROTTLE_TX_PKTS)
ctl |= CTL_AUTO_RELEASE;
else
ctl &= ~CTL_AUTO_RELEASE;
SMC_SET_CTL(lp, ctl);
SMC_SELECT_BANK(lp, 2);
SMC_SET_MMU_CMD(lp, MC_RESET);
SMC_WAIT_MMU_BUSY(lp);
}
static void smc_enable(struct net_device *dev)
{
struct smc_local *lp = netdev_priv(dev);
void __iomem *ioaddr = lp->base;
int mask;
DBG(2, dev, "%s\n", __func__);
SMC_SELECT_BANK(lp, 0);
SMC_SET_TCR(lp, lp->tcr_cur_mode);
SMC_SET_RCR(lp, lp->rcr_cur_mode);
SMC_SELECT_BANK(lp, 1);
SMC_SET_MAC_ADDR(lp, dev->dev_addr);
mask = IM_EPH_INT|IM_RX_OVRN_INT|IM_RCV_INT;
if (lp->version >= (CHIP_91100 << 4))
mask |= IM_MDINT;
SMC_SELECT_BANK(lp, 2);
SMC_SET_INT_MASK(lp, mask);
}
static void smc_shutdown(struct net_device *dev)
{
struct smc_local *lp = netdev_priv(dev);
void __iomem *ioaddr = lp->base;
struct sk_buff *pending_skb;
DBG(2, dev, "%s: %s\n", CARDNAME, __func__);
spin_lock_irq(&lp->lock);
SMC_SELECT_BANK(lp, 2);
SMC_SET_INT_MASK(lp, 0);
pending_skb = lp->pending_tx_skb;
lp->pending_tx_skb = NULL;
spin_unlock_irq(&lp->lock);
if (pending_skb)
dev_kfree_skb(pending_skb);
SMC_SELECT_BANK(lp, 0);
SMC_SET_RCR(lp, RCR_CLEAR);
SMC_SET_TCR(lp, TCR_CLEAR);
#ifdef POWER_DOWN
SMC_SELECT_BANK(lp, 1);
SMC_SET_CONFIG(lp, SMC_GET_CONFIG(lp) & ~CONFIG_EPH_POWER_EN);
#endif
}
static inline void smc_rcv(struct net_device *dev)
{
struct smc_local *lp = netdev_priv(dev);
void __iomem *ioaddr = lp->base;
unsigned int packet_number, status, packet_len;
DBG(3, dev, "%s\n", __func__);
packet_number = SMC_GET_RXFIFO(lp);
if (unlikely(packet_number & RXFIFO_REMPTY)) {
PRINTK(dev, "smc_rcv with nothing on FIFO.\n");
return;
}
SMC_SET_PTR(lp, PTR_READ | PTR_RCV | PTR_AUTOINC);
SMC_GET_PKT_HDR(lp, status, packet_len);
packet_len &= 0x07ff;
DBG(2, dev, "RX PNR 0x%x STATUS 0x%04x LENGTH 0x%04x (%d)\n",
packet_number, status, packet_len, packet_len);
back:
if (unlikely(packet_len < 6 || status & RS_ERRORS)) {
if (status & RS_TOOLONG && packet_len <= (1514 + 4 + 6)) {
status &= ~RS_TOOLONG;
goto back;
}
if (packet_len < 6) {
netdev_err(dev, "fubar (rxlen %u status %x\n",
packet_len, status);
status |= RS_TOOSHORT;
}
SMC_WAIT_MMU_BUSY(lp);
SMC_SET_MMU_CMD(lp, MC_RELEASE);
dev->stats.rx_errors++;
if (status & RS_ALGNERR)
dev->stats.rx_frame_errors++;
if (status & (RS_TOOSHORT | RS_TOOLONG))
dev->stats.rx_length_errors++;
if (status & RS_BADCRC)
dev->stats.rx_crc_errors++;
} else {
struct sk_buff *skb;
unsigned char *data;
unsigned int data_len;
if (status & RS_MULTICAST)
dev->stats.multicast++;
skb = netdev_alloc_skb(dev, packet_len);
if (unlikely(skb == NULL)) {
SMC_WAIT_MMU_BUSY(lp);
SMC_SET_MMU_CMD(lp, MC_RELEASE);
dev->stats.rx_dropped++;
return;
}
skb_reserve(skb, 2);
if (lp->version == 0x90)
status |= RS_ODDFRAME;
data_len = packet_len - ((status & RS_ODDFRAME) ? 5 : 6);
data = skb_put(skb, data_len);
SMC_PULL_DATA(lp, data, packet_len - 4);
SMC_WAIT_MMU_BUSY(lp);
SMC_SET_MMU_CMD(lp, MC_RELEASE);
PRINT_PKT(data, packet_len - 4);
skb->protocol = eth_type_trans(skb, dev);
netif_rx(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += data_len;
}
}
static void smc_hardware_send_pkt(unsigned long data)
{
struct net_device *dev = (struct net_device *)data;
struct smc_local *lp = netdev_priv(dev);
void __iomem *ioaddr = lp->base;
struct sk_buff *skb;
unsigned int packet_no, len;
unsigned char *buf;
unsigned long flags;
DBG(3, dev, "%s\n", __func__);
if (!smc_special_trylock(&lp->lock, flags)) {
netif_stop_queue(dev);
tasklet_schedule(&lp->tx_task);
return;
}
skb = lp->pending_tx_skb;
if (unlikely(!skb)) {
smc_special_unlock(&lp->lock, flags);
return;
}
lp->pending_tx_skb = NULL;
packet_no = SMC_GET_AR(lp);
if (unlikely(packet_no & AR_FAILED)) {
netdev_err(dev, "Memory allocation failed.\n");
dev->stats.tx_errors++;
dev->stats.tx_fifo_errors++;
smc_special_unlock(&lp->lock, flags);
goto done;
}
SMC_SET_PN(lp, packet_no);
SMC_SET_PTR(lp, PTR_AUTOINC);
buf = skb->data;
len = skb->len;
DBG(2, dev, "TX PNR 0x%x LENGTH 0x%04x (%d) BUF 0x%p\n",
packet_no, len, len, buf);
PRINT_PKT(buf, len);
SMC_PUT_PKT_HDR(lp, 0, len + 6);
SMC_PUSH_DATA(lp, buf, len & ~1);
SMC_outw(((len & 1) ? (0x2000 | buf[len-1]) : 0), ioaddr, DATA_REG(lp));
if (THROTTLE_TX_PKTS)
netif_stop_queue(dev);
SMC_SET_MMU_CMD(lp, MC_ENQUEUE);
smc_special_unlock(&lp->lock, flags);
dev->trans_start = jiffies;
dev->stats.tx_packets++;
dev->stats.tx_bytes += len;
SMC_ENABLE_INT(lp, IM_TX_INT | IM_TX_EMPTY_INT);
done: if (!THROTTLE_TX_PKTS)
netif_wake_queue(dev);
dev_consume_skb_any(skb);
}
static int smc_hard_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct smc_local *lp = netdev_priv(dev);
void __iomem *ioaddr = lp->base;
unsigned int numPages, poll_count, status;
unsigned long flags;
DBG(3, dev, "%s\n", __func__);
BUG_ON(lp->pending_tx_skb != NULL);
numPages = ((skb->len & ~1) + (6 - 1)) >> 8;
if (unlikely(numPages > 7)) {
netdev_warn(dev, "Far too big packet error.\n");
dev->stats.tx_errors++;
dev->stats.tx_dropped++;
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
}
smc_special_lock(&lp->lock, flags);
SMC_SET_MMU_CMD(lp, MC_ALLOC | numPages);
poll_count = MEMORY_WAIT_TIME;
do {
status = SMC_GET_INT(lp);
if (status & IM_ALLOC_INT) {
SMC_ACK_INT(lp, IM_ALLOC_INT);
break;
}
} while (--poll_count);
smc_special_unlock(&lp->lock, flags);
lp->pending_tx_skb = skb;
if (!poll_count) {
netif_stop_queue(dev);
DBG(2, dev, "TX memory allocation deferred.\n");
SMC_ENABLE_INT(lp, IM_ALLOC_INT);
} else {
smc_hardware_send_pkt((unsigned long)dev);
}
return NETDEV_TX_OK;
}
static void smc_tx(struct net_device *dev)
{
struct smc_local *lp = netdev_priv(dev);
void __iomem *ioaddr = lp->base;
unsigned int saved_packet, packet_no, tx_status, pkt_len;
DBG(3, dev, "%s\n", __func__);
packet_no = SMC_GET_TXFIFO(lp);
if (unlikely(packet_no & TXFIFO_TEMPTY)) {
PRINTK(dev, "smc_tx with nothing on FIFO.\n");
return;
}
saved_packet = SMC_GET_PN(lp);
SMC_SET_PN(lp, packet_no);
SMC_SET_PTR(lp, PTR_AUTOINC | PTR_READ);
SMC_GET_PKT_HDR(lp, tx_status, pkt_len);
DBG(2, dev, "TX STATUS 0x%04x PNR 0x%02x\n",
tx_status, packet_no);
if (!(tx_status & ES_TX_SUC))
dev->stats.tx_errors++;
if (tx_status & ES_LOSTCARR)
dev->stats.tx_carrier_errors++;
if (tx_status & (ES_LATCOL | ES_16COL)) {
PRINTK(dev, "%s occurred on last xmit\n",
(tx_status & ES_LATCOL) ?
"late collision" : "too many collisions");
dev->stats.tx_window_errors++;
if (!(dev->stats.tx_window_errors & 63) && net_ratelimit()) {
netdev_info(dev, "unexpectedly large number of bad collisions. Please check duplex setting.\n");
}
}
SMC_WAIT_MMU_BUSY(lp);
SMC_SET_MMU_CMD(lp, MC_FREEPKT);
SMC_WAIT_MMU_BUSY(lp);
SMC_SET_PN(lp, saved_packet);
SMC_SELECT_BANK(lp, 0);
SMC_SET_TCR(lp, lp->tcr_cur_mode);
SMC_SELECT_BANK(lp, 2);
}
static void smc_mii_out(struct net_device *dev, unsigned int val, int bits)
{
struct smc_local *lp = netdev_priv(dev);
void __iomem *ioaddr = lp->base;
unsigned int mii_reg, mask;
mii_reg = SMC_GET_MII(lp) & ~(MII_MCLK | MII_MDOE | MII_MDO);
mii_reg |= MII_MDOE;
for (mask = 1 << (bits - 1); mask; mask >>= 1) {
if (val & mask)
mii_reg |= MII_MDO;
else
mii_reg &= ~MII_MDO;
SMC_SET_MII(lp, mii_reg);
udelay(MII_DELAY);
SMC_SET_MII(lp, mii_reg | MII_MCLK);
udelay(MII_DELAY);
}
}
static unsigned int smc_mii_in(struct net_device *dev, int bits)
{
struct smc_local *lp = netdev_priv(dev);
void __iomem *ioaddr = lp->base;
unsigned int mii_reg, mask, val;
mii_reg = SMC_GET_MII(lp) & ~(MII_MCLK | MII_MDOE | MII_MDO);
SMC_SET_MII(lp, mii_reg);
for (mask = 1 << (bits - 1), val = 0; mask; mask >>= 1) {
if (SMC_GET_MII(lp) & MII_MDI)
val |= mask;
SMC_SET_MII(lp, mii_reg);
udelay(MII_DELAY);
SMC_SET_MII(lp, mii_reg | MII_MCLK);
udelay(MII_DELAY);
}
return val;
}
static int smc_phy_read(struct net_device *dev, int phyaddr, int phyreg)
{
struct smc_local *lp = netdev_priv(dev);
void __iomem *ioaddr = lp->base;
unsigned int phydata;
SMC_SELECT_BANK(lp, 3);
smc_mii_out(dev, 0xffffffff, 32);
smc_mii_out(dev, 6 << 10 | phyaddr << 5 | phyreg, 14);
phydata = smc_mii_in(dev, 18);
SMC_SET_MII(lp, SMC_GET_MII(lp) & ~(MII_MCLK|MII_MDOE|MII_MDO));
DBG(3, dev, "%s: phyaddr=0x%x, phyreg=0x%x, phydata=0x%x\n",
__func__, phyaddr, phyreg, phydata);
SMC_SELECT_BANK(lp, 2);
return phydata;
}
static void smc_phy_write(struct net_device *dev, int phyaddr, int phyreg,
int phydata)
{
struct smc_local *lp = netdev_priv(dev);
void __iomem *ioaddr = lp->base;
SMC_SELECT_BANK(lp, 3);
smc_mii_out(dev, 0xffffffff, 32);
smc_mii_out(dev, 5 << 28 | phyaddr << 23 | phyreg << 18 | 2 << 16 | phydata, 32);
SMC_SET_MII(lp, SMC_GET_MII(lp) & ~(MII_MCLK|MII_MDOE|MII_MDO));
DBG(3, dev, "%s: phyaddr=0x%x, phyreg=0x%x, phydata=0x%x\n",
__func__, phyaddr, phyreg, phydata);
SMC_SELECT_BANK(lp, 2);
}
static void smc_phy_detect(struct net_device *dev)
{
struct smc_local *lp = netdev_priv(dev);
int phyaddr;
DBG(2, dev, "%s\n", __func__);
lp->phy_type = 0;
for (phyaddr = 1; phyaddr < 33; ++phyaddr) {
unsigned int id1, id2;
id1 = smc_phy_read(dev, phyaddr & 31, MII_PHYSID1);
id2 = smc_phy_read(dev, phyaddr & 31, MII_PHYSID2);
DBG(3, dev, "phy_id1=0x%x, phy_id2=0x%x\n",
id1, id2);
if (id1 != 0x0000 && id1 != 0xffff && id1 != 0x8000 &&
id2 != 0x0000 && id2 != 0xffff && id2 != 0x8000) {
lp->mii.phy_id = phyaddr & 31;
lp->phy_type = id1 << 16 | id2;
break;
}
}
}
static int smc_phy_fixed(struct net_device *dev)
{
struct smc_local *lp = netdev_priv(dev);
void __iomem *ioaddr = lp->base;
int phyaddr = lp->mii.phy_id;
int bmcr, cfg1;
DBG(3, dev, "%s\n", __func__);
cfg1 = smc_phy_read(dev, phyaddr, PHY_CFG1_REG);
cfg1 |= PHY_CFG1_LNKDIS;
smc_phy_write(dev, phyaddr, PHY_CFG1_REG, cfg1);
bmcr = 0;
if (lp->ctl_rfduplx)
bmcr |= BMCR_FULLDPLX;
if (lp->ctl_rspeed == 100)
bmcr |= BMCR_SPEED100;
smc_phy_write(dev, phyaddr, MII_BMCR, bmcr);
SMC_SELECT_BANK(lp, 0);
SMC_SET_RPC(lp, lp->rpc_cur_mode);
SMC_SELECT_BANK(lp, 2);
return 1;
}
static int smc_phy_reset(struct net_device *dev, int phy)
{
struct smc_local *lp = netdev_priv(dev);
unsigned int bmcr;
int timeout;
smc_phy_write(dev, phy, MII_BMCR, BMCR_RESET);
for (timeout = 2; timeout; timeout--) {
spin_unlock_irq(&lp->lock);
msleep(50);
spin_lock_irq(&lp->lock);
bmcr = smc_phy_read(dev, phy, MII_BMCR);
if (!(bmcr & BMCR_RESET))
break;
}
return bmcr & BMCR_RESET;
}
static void smc_phy_powerdown(struct net_device *dev)
{
struct smc_local *lp = netdev_priv(dev);
unsigned int bmcr;
int phy = lp->mii.phy_id;
if (lp->phy_type == 0)
return;
cancel_work_sync(&lp->phy_configure);
bmcr = smc_phy_read(dev, phy, MII_BMCR);
smc_phy_write(dev, phy, MII_BMCR, bmcr | BMCR_PDOWN);
}
static void smc_phy_check_media(struct net_device *dev, int init)
{
struct smc_local *lp = netdev_priv(dev);
void __iomem *ioaddr = lp->base;
if (mii_check_media(&lp->mii, netif_msg_link(lp), init)) {
if (lp->mii.full_duplex) {
lp->tcr_cur_mode |= TCR_SWFDUP;
} else {
lp->tcr_cur_mode &= ~TCR_SWFDUP;
}
SMC_SELECT_BANK(lp, 0);
SMC_SET_TCR(lp, lp->tcr_cur_mode);
}
}
static void smc_phy_configure(struct work_struct *work)
{
struct smc_local *lp =
container_of(work, struct smc_local, phy_configure);
struct net_device *dev = lp->dev;
void __iomem *ioaddr = lp->base;
int phyaddr = lp->mii.phy_id;
int my_phy_caps;
int my_ad_caps;
int status;
DBG(3, dev, "smc_program_phy()\n");
spin_lock_irq(&lp->lock);
if (lp->phy_type == 0)
goto smc_phy_configure_exit;
if (smc_phy_reset(dev, phyaddr)) {
netdev_info(dev, "PHY reset timed out\n");
goto smc_phy_configure_exit;
}
smc_phy_write(dev, phyaddr, PHY_MASK_REG,
PHY_INT_LOSSSYNC | PHY_INT_CWRD | PHY_INT_SSD |
PHY_INT_ESD | PHY_INT_RPOL | PHY_INT_JAB |
PHY_INT_SPDDET | PHY_INT_DPLXDET);
SMC_SELECT_BANK(lp, 0);
SMC_SET_RPC(lp, lp->rpc_cur_mode);
if (lp->mii.force_media) {
smc_phy_fixed(dev);
goto smc_phy_configure_exit;
}
my_phy_caps = smc_phy_read(dev, phyaddr, MII_BMSR);
if (!(my_phy_caps & BMSR_ANEGCAPABLE)) {
netdev_info(dev, "Auto negotiation NOT supported\n");
smc_phy_fixed(dev);
goto smc_phy_configure_exit;
}
my_ad_caps = ADVERTISE_CSMA;
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
smc_phy_write(dev, phyaddr, MII_ADVERTISE, my_ad_caps);
lp->mii.advertising = my_ad_caps;
status = smc_phy_read(dev, phyaddr, MII_ADVERTISE);
DBG(2, dev, "phy caps=%x\n", my_phy_caps);
DBG(2, dev, "phy advertised caps=%x\n", my_ad_caps);
smc_phy_write(dev, phyaddr, MII_BMCR, BMCR_ANENABLE | BMCR_ANRESTART);
smc_phy_check_media(dev, 1);
smc_phy_configure_exit:
SMC_SELECT_BANK(lp, 2);
spin_unlock_irq(&lp->lock);
}
static void smc_phy_interrupt(struct net_device *dev)
{
struct smc_local *lp = netdev_priv(dev);
int phyaddr = lp->mii.phy_id;
int phy18;
DBG(2, dev, "%s\n", __func__);
if (lp->phy_type == 0)
return;
for(;;) {
smc_phy_check_media(dev, 0);
phy18 = smc_phy_read(dev, phyaddr, PHY_INT_REG);
if ((phy18 & PHY_INT_INT) == 0)
break;
}
}
static void smc_10bt_check_media(struct net_device *dev, int init)
{
struct smc_local *lp = netdev_priv(dev);
void __iomem *ioaddr = lp->base;
unsigned int old_carrier, new_carrier;
old_carrier = netif_carrier_ok(dev) ? 1 : 0;
SMC_SELECT_BANK(lp, 0);
new_carrier = (SMC_GET_EPH_STATUS(lp) & ES_LINK_OK) ? 1 : 0;
SMC_SELECT_BANK(lp, 2);
if (init || (old_carrier != new_carrier)) {
if (!new_carrier) {
netif_carrier_off(dev);
} else {
netif_carrier_on(dev);
}
if (netif_msg_link(lp))
netdev_info(dev, "link %s\n",
new_carrier ? "up" : "down");
}
}
static void smc_eph_interrupt(struct net_device *dev)
{
struct smc_local *lp = netdev_priv(dev);
void __iomem *ioaddr = lp->base;
unsigned int ctl;
smc_10bt_check_media(dev, 0);
SMC_SELECT_BANK(lp, 1);
ctl = SMC_GET_CTL(lp);
SMC_SET_CTL(lp, ctl & ~CTL_LE_ENABLE);
SMC_SET_CTL(lp, ctl);
SMC_SELECT_BANK(lp, 2);
}
static irqreturn_t smc_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct smc_local *lp = netdev_priv(dev);
void __iomem *ioaddr = lp->base;
int status, mask, timeout, card_stats;
int saved_pointer;
DBG(3, dev, "%s\n", __func__);
spin_lock(&lp->lock);
SMC_INTERRUPT_PREAMBLE;
saved_pointer = SMC_GET_PTR(lp);
mask = SMC_GET_INT_MASK(lp);
SMC_SET_INT_MASK(lp, 0);
timeout = MAX_IRQ_LOOPS;
do {
status = SMC_GET_INT(lp);
DBG(2, dev, "INT 0x%02x MASK 0x%02x MEM 0x%04x FIFO 0x%04x\n",
status, mask,
({ int meminfo; SMC_SELECT_BANK(lp, 0);
meminfo = SMC_GET_MIR(lp);
SMC_SELECT_BANK(lp, 2); meminfo; }),
SMC_GET_FIFO(lp));
status &= mask;
if (!status)
break;
if (status & IM_TX_INT) {
DBG(3, dev, "TX int\n");
smc_tx(dev);
SMC_ACK_INT(lp, IM_TX_INT);
if (THROTTLE_TX_PKTS)
netif_wake_queue(dev);
} else if (status & IM_RCV_INT) {
DBG(3, dev, "RX irq\n");
smc_rcv(dev);
} else if (status & IM_ALLOC_INT) {
DBG(3, dev, "Allocation irq\n");
tasklet_hi_schedule(&lp->tx_task);
mask &= ~IM_ALLOC_INT;
} else if (status & IM_TX_EMPTY_INT) {
DBG(3, dev, "TX empty\n");
mask &= ~IM_TX_EMPTY_INT;
SMC_SELECT_BANK(lp, 0);
card_stats = SMC_GET_COUNTER(lp);
SMC_SELECT_BANK(lp, 2);
dev->stats.collisions += card_stats & 0xF;
card_stats >>= 4;
dev->stats.collisions += card_stats & 0xF;
} else if (status & IM_RX_OVRN_INT) {
DBG(1, dev, "RX overrun (EPH_ST 0x%04x)\n",
({ int eph_st; SMC_SELECT_BANK(lp, 0);
eph_st = SMC_GET_EPH_STATUS(lp);
SMC_SELECT_BANK(lp, 2); eph_st; }));
SMC_ACK_INT(lp, IM_RX_OVRN_INT);
dev->stats.rx_errors++;
dev->stats.rx_fifo_errors++;
} else if (status & IM_EPH_INT) {
smc_eph_interrupt(dev);
} else if (status & IM_MDINT) {
SMC_ACK_INT(lp, IM_MDINT);
smc_phy_interrupt(dev);
} else if (status & IM_ERCV_INT) {
SMC_ACK_INT(lp, IM_ERCV_INT);
PRINTK(dev, "UNSUPPORTED: ERCV INTERRUPT\n");
}
} while (--timeout);
SMC_SET_PTR(lp, saved_pointer);
SMC_SET_INT_MASK(lp, mask);
spin_unlock(&lp->lock);
#ifndef CONFIG_NET_POLL_CONTROLLER
if (timeout == MAX_IRQ_LOOPS)
PRINTK(dev, "spurious interrupt (mask = 0x%02x)\n",
mask);
#endif
DBG(3, dev, "Interrupt done (%d loops)\n",
MAX_IRQ_LOOPS - timeout);
return IRQ_HANDLED;
}
static void smc_poll_controller(struct net_device *dev)
{
disable_irq(dev->irq);
smc_interrupt(dev->irq, dev);
enable_irq(dev->irq);
}
static void smc_timeout(struct net_device *dev)
{
struct smc_local *lp = netdev_priv(dev);
void __iomem *ioaddr = lp->base;
int status, mask, eph_st, meminfo, fifo;
DBG(2, dev, "%s\n", __func__);
spin_lock_irq(&lp->lock);
status = SMC_GET_INT(lp);
mask = SMC_GET_INT_MASK(lp);
fifo = SMC_GET_FIFO(lp);
SMC_SELECT_BANK(lp, 0);
eph_st = SMC_GET_EPH_STATUS(lp);
meminfo = SMC_GET_MIR(lp);
SMC_SELECT_BANK(lp, 2);
spin_unlock_irq(&lp->lock);
PRINTK(dev, "TX timeout (INT 0x%02x INTMASK 0x%02x MEM 0x%04x FIFO 0x%04x EPH_ST 0x%04x)\n",
status, mask, meminfo, fifo, eph_st);
smc_reset(dev);
smc_enable(dev);
if (lp->phy_type != 0)
schedule_work(&lp->phy_configure);
dev->trans_start = jiffies;
netif_wake_queue(dev);
}
static void smc_set_multicast_list(struct net_device *dev)
{
struct smc_local *lp = netdev_priv(dev);
void __iomem *ioaddr = lp->base;
unsigned char multicast_table[8];
int update_multicast = 0;
DBG(2, dev, "%s\n", __func__);
if (dev->flags & IFF_PROMISC) {
DBG(2, dev, "RCR_PRMS\n");
lp->rcr_cur_mode |= RCR_PRMS;
}
else if (dev->flags & IFF_ALLMULTI || netdev_mc_count(dev) > 16) {
DBG(2, dev, "RCR_ALMUL\n");
lp->rcr_cur_mode |= RCR_ALMUL;
}
else if (!netdev_mc_empty(dev)) {
struct netdev_hw_addr *ha;
static const unsigned char invert3[] = {0, 4, 2, 6, 1, 5, 3, 7};
memset(multicast_table, 0, sizeof(multicast_table));
netdev_for_each_mc_addr(ha, dev) {
int position;
position = crc32_le(~0, ha->addr, 6) & 0x3f;
multicast_table[invert3[position&7]] |=
(1<<invert3[(position>>3)&7]);
}
lp->rcr_cur_mode &= ~(RCR_PRMS | RCR_ALMUL);
update_multicast = 1;
} else {
DBG(2, dev, "~(RCR_PRMS|RCR_ALMUL)\n");
lp->rcr_cur_mode &= ~(RCR_PRMS | RCR_ALMUL);
memset(multicast_table, 0, sizeof(multicast_table));
update_multicast = 1;
}
spin_lock_irq(&lp->lock);
SMC_SELECT_BANK(lp, 0);
SMC_SET_RCR(lp, lp->rcr_cur_mode);
if (update_multicast) {
SMC_SELECT_BANK(lp, 3);
SMC_SET_MCAST(lp, multicast_table);
}
SMC_SELECT_BANK(lp, 2);
spin_unlock_irq(&lp->lock);
}
static int
smc_open(struct net_device *dev)
{
struct smc_local *lp = netdev_priv(dev);
DBG(2, dev, "%s\n", __func__);
lp->tcr_cur_mode = TCR_DEFAULT;
lp->rcr_cur_mode = RCR_DEFAULT;
lp->rpc_cur_mode = RPC_DEFAULT |
lp->cfg.leda << RPC_LSXA_SHFT |
lp->cfg.ledb << RPC_LSXB_SHFT;
if (lp->phy_type == 0)
lp->tcr_cur_mode |= TCR_MON_CSN;
smc_reset(dev);
smc_enable(dev);
if (lp->phy_type != 0)
smc_phy_configure(&lp->phy_configure);
else {
spin_lock_irq(&lp->lock);
smc_10bt_check_media(dev, 1);
spin_unlock_irq(&lp->lock);
}
netif_start_queue(dev);
return 0;
}
static int smc_close(struct net_device *dev)
{
struct smc_local *lp = netdev_priv(dev);
DBG(2, dev, "%s\n", __func__);
netif_stop_queue(dev);
netif_carrier_off(dev);
smc_shutdown(dev);
tasklet_kill(&lp->tx_task);
smc_phy_powerdown(dev);
return 0;
}
static int
smc_ethtool_getsettings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct smc_local *lp = netdev_priv(dev);
int ret;
cmd->maxtxpkt = 1;
cmd->maxrxpkt = 1;
if (lp->phy_type != 0) {
spin_lock_irq(&lp->lock);
ret = mii_ethtool_gset(&lp->mii, cmd);
spin_unlock_irq(&lp->lock);
} else {
cmd->supported = SUPPORTED_10baseT_Half |
SUPPORTED_10baseT_Full |
SUPPORTED_TP | SUPPORTED_AUI;
if (lp->ctl_rspeed == 10)
ethtool_cmd_speed_set(cmd, SPEED_10);
else if (lp->ctl_rspeed == 100)
ethtool_cmd_speed_set(cmd, SPEED_100);
cmd->autoneg = AUTONEG_DISABLE;
cmd->transceiver = XCVR_INTERNAL;
cmd->port = 0;
cmd->duplex = lp->tcr_cur_mode & TCR_SWFDUP ? DUPLEX_FULL : DUPLEX_HALF;
ret = 0;
}
return ret;
}
static int
smc_ethtool_setsettings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct smc_local *lp = netdev_priv(dev);
int ret;
if (lp->phy_type != 0) {
spin_lock_irq(&lp->lock);
ret = mii_ethtool_sset(&lp->mii, cmd);
spin_unlock_irq(&lp->lock);
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
smc_ethtool_getdrvinfo(struct net_device *dev, struct ethtool_drvinfo *info)
{
strlcpy(info->driver, CARDNAME, sizeof(info->driver));
strlcpy(info->version, version, sizeof(info->version));
strlcpy(info->bus_info, dev_name(dev->dev.parent),
sizeof(info->bus_info));
}
static int smc_ethtool_nwayreset(struct net_device *dev)
{
struct smc_local *lp = netdev_priv(dev);
int ret = -EINVAL;
if (lp->phy_type != 0) {
spin_lock_irq(&lp->lock);
ret = mii_nway_restart(&lp->mii);
spin_unlock_irq(&lp->lock);
}
return ret;
}
static u32 smc_ethtool_getmsglevel(struct net_device *dev)
{
struct smc_local *lp = netdev_priv(dev);
return lp->msg_enable;
}
static void smc_ethtool_setmsglevel(struct net_device *dev, u32 level)
{
struct smc_local *lp = netdev_priv(dev);
lp->msg_enable = level;
}
static int smc_write_eeprom_word(struct net_device *dev, u16 addr, u16 word)
{
u16 ctl;
struct smc_local *lp = netdev_priv(dev);
void __iomem *ioaddr = lp->base;
spin_lock_irq(&lp->lock);
SMC_SELECT_BANK(lp, 1);
SMC_SET_GP(lp, word);
SMC_SELECT_BANK(lp, 2);
SMC_SET_PTR(lp, addr);
SMC_SELECT_BANK(lp, 1);
ctl = SMC_GET_CTL(lp);
SMC_SET_CTL(lp, ctl | (CTL_EEPROM_SELECT | CTL_STORE));
do {
udelay(1);
} while (SMC_GET_CTL(lp) & CTL_STORE);
SMC_SET_CTL(lp, ctl);
SMC_SELECT_BANK(lp, 2);
spin_unlock_irq(&lp->lock);
return 0;
}
static int smc_read_eeprom_word(struct net_device *dev, u16 addr, u16 *word)
{
u16 ctl;
struct smc_local *lp = netdev_priv(dev);
void __iomem *ioaddr = lp->base;
spin_lock_irq(&lp->lock);
SMC_SELECT_BANK(lp, 2);
SMC_SET_PTR(lp, addr | PTR_READ);
SMC_SELECT_BANK(lp, 1);
SMC_SET_GP(lp, 0xffff);
ctl = SMC_GET_CTL(lp);
SMC_SET_CTL(lp, ctl | (CTL_EEPROM_SELECT | CTL_RELOAD));
do {
udelay(1);
} while (SMC_GET_CTL(lp) & CTL_RELOAD);
*word = SMC_GET_GP(lp);
SMC_SET_CTL(lp, ctl);
SMC_SELECT_BANK(lp, 2);
spin_unlock_irq(&lp->lock);
return 0;
}
static int smc_ethtool_geteeprom_len(struct net_device *dev)
{
return 0x23 * 2;
}
static int smc_ethtool_geteeprom(struct net_device *dev,
struct ethtool_eeprom *eeprom, u8 *data)
{
int i;
int imax;
DBG(1, dev, "Reading %d bytes at %d(0x%x)\n",
eeprom->len, eeprom->offset, eeprom->offset);
imax = smc_ethtool_geteeprom_len(dev);
for (i = 0; i < eeprom->len; i += 2) {
int ret;
u16 wbuf;
int offset = i + eeprom->offset;
if (offset > imax)
break;
ret = smc_read_eeprom_word(dev, offset >> 1, &wbuf);
if (ret != 0)
return ret;
DBG(2, dev, "Read 0x%x from 0x%x\n", wbuf, offset >> 1);
data[i] = (wbuf >> 8) & 0xff;
data[i+1] = wbuf & 0xff;
}
return 0;
}
static int smc_ethtool_seteeprom(struct net_device *dev,
struct ethtool_eeprom *eeprom, u8 *data)
{
int i;
int imax;
DBG(1, dev, "Writing %d bytes to %d(0x%x)\n",
eeprom->len, eeprom->offset, eeprom->offset);
imax = smc_ethtool_geteeprom_len(dev);
for (i = 0; i < eeprom->len; i += 2) {
int ret;
u16 wbuf;
int offset = i + eeprom->offset;
if (offset > imax)
break;
wbuf = (data[i] << 8) | data[i + 1];
DBG(2, dev, "Writing 0x%x to 0x%x\n", wbuf, offset >> 1);
ret = smc_write_eeprom_word(dev, offset >> 1, wbuf);
if (ret != 0)
return ret;
}
return 0;
}
static int smc_findirq(struct smc_local *lp)
{
void __iomem *ioaddr = lp->base;
int timeout = 20;
unsigned long cookie;
DBG(2, lp->dev, "%s: %s\n", CARDNAME, __func__);
cookie = probe_irq_on();
SMC_SELECT_BANK(lp, 2);
SMC_SET_INT_MASK(lp, IM_ALLOC_INT);
SMC_SET_MMU_CMD(lp, MC_ALLOC | 1);
do {
int int_status;
udelay(10);
int_status = SMC_GET_INT(lp);
if (int_status & IM_ALLOC_INT)
break;
} while (--timeout);
SMC_SET_INT_MASK(lp, 0);
return probe_irq_off(cookie);
}
static int smc_probe(struct net_device *dev, void __iomem *ioaddr,
unsigned long irq_flags)
{
struct smc_local *lp = netdev_priv(dev);
int retval;
unsigned int val, revision_register;
const char *version_string;
DBG(2, dev, "%s: %s\n", CARDNAME, __func__);
val = SMC_CURRENT_BANK(lp);
DBG(2, dev, "%s: bank signature probe returned 0x%04x\n",
CARDNAME, val);
if ((val & 0xFF00) != 0x3300) {
if ((val & 0xFF) == 0x33) {
netdev_warn(dev,
"%s: Detected possible byte-swapped interface at IOADDR %p\n",
CARDNAME, ioaddr);
}
retval = -ENODEV;
goto err_out;
}
SMC_SELECT_BANK(lp, 0);
val = SMC_CURRENT_BANK(lp);
if ((val & 0xFF00) != 0x3300) {
retval = -ENODEV;
goto err_out;
}
SMC_SELECT_BANK(lp, 1);
val = SMC_GET_BASE(lp);
val = ((val & 0x1F00) >> 3) << SMC_IO_SHIFT;
if (((unsigned long)ioaddr & (0x3e0 << SMC_IO_SHIFT)) != val) {
netdev_warn(dev, "%s: IOADDR %p doesn't match configuration (%x).\n",
CARDNAME, ioaddr, val);
}
SMC_SELECT_BANK(lp, 3);
revision_register = SMC_GET_REV(lp);
DBG(2, dev, "%s: revision = 0x%04x\n", CARDNAME, revision_register);
version_string = chip_ids[ (revision_register >> 4) & 0xF];
if (!version_string || (revision_register & 0xff00) != 0x3300) {
netdev_warn(dev, "%s: IO %p: Unrecognized revision register 0x%04x, Contact author.\n",
CARDNAME, ioaddr, revision_register);
retval = -ENODEV;
goto err_out;
}
pr_info_once("%s\n", version);
dev->base_addr = (unsigned long)ioaddr;
lp->base = ioaddr;
lp->version = revision_register & 0xff;
spin_lock_init(&lp->lock);
SMC_SELECT_BANK(lp, 1);
SMC_GET_MAC_ADDR(lp, dev->dev_addr);
smc_reset(dev);
if (dev->irq < 1) {
int trials;
trials = 3;
while (trials--) {
dev->irq = smc_findirq(lp);
if (dev->irq)
break;
smc_reset(dev);
}
}
if (dev->irq == 0) {
netdev_warn(dev, "Couldn't autodetect your IRQ. Use irq=xx.\n");
retval = -ENODEV;
goto err_out;
}
dev->irq = irq_canonicalize(dev->irq);
ether_setup(dev);
dev->watchdog_timeo = msecs_to_jiffies(watchdog);
dev->netdev_ops = &smc_netdev_ops;
dev->ethtool_ops = &smc_ethtool_ops;
tasklet_init(&lp->tx_task, smc_hardware_send_pkt, (unsigned long)dev);
INIT_WORK(&lp->phy_configure, smc_phy_configure);
lp->dev = dev;
lp->mii.phy_id_mask = 0x1f;
lp->mii.reg_num_mask = 0x1f;
lp->mii.force_media = 0;
lp->mii.full_duplex = 0;
lp->mii.dev = dev;
lp->mii.mdio_read = smc_phy_read;
lp->mii.mdio_write = smc_phy_write;
if (lp->version >= (CHIP_91100 << 4))
smc_phy_detect(dev);
smc_shutdown(dev);
smc_phy_powerdown(dev);
lp->msg_enable = NETIF_MSG_LINK;
lp->ctl_rfduplx = 0;
lp->ctl_rspeed = 10;
if (lp->version >= (CHIP_91100 << 4)) {
lp->ctl_rfduplx = 1;
lp->ctl_rspeed = 100;
}
retval = request_irq(dev->irq, smc_interrupt, irq_flags, dev->name, dev);
if (retval)
goto err_out;
#ifdef CONFIG_ARCH_PXA
# ifdef SMC_USE_PXA_DMA
lp->cfg.flags |= SMC91X_USE_DMA;
# endif
if (lp->cfg.flags & SMC91X_USE_DMA) {
int dma = pxa_request_dma(dev->name, DMA_PRIO_LOW,
smc_pxa_dma_irq, NULL);
if (dma >= 0)
dev->dma = dma;
}
#endif
retval = register_netdev(dev);
if (retval == 0) {
netdev_info(dev, "%s (rev %d) at %p IRQ %d",
version_string, revision_register & 0x0f,
lp->base, dev->irq);
if (dev->dma != (unsigned char)-1)
pr_cont(" DMA %d", dev->dma);
pr_cont("%s%s\n",
lp->cfg.flags & SMC91X_NOWAIT ? " [nowait]" : "",
THROTTLE_TX_PKTS ? " [throttle_tx]" : "");
if (!is_valid_ether_addr(dev->dev_addr)) {
netdev_warn(dev, "Invalid ethernet MAC address. Please set using ifconfig\n");
} else {
netdev_info(dev, "Ethernet addr: %pM\n",
dev->dev_addr);
}
if (lp->phy_type == 0) {
PRINTK(dev, "No PHY found\n");
} else if ((lp->phy_type & 0xfffffff0) == 0x0016f840) {
PRINTK(dev, "PHY LAN83C183 (LAN91C111 Internal)\n");
} else if ((lp->phy_type & 0xfffffff0) == 0x02821c50) {
PRINTK(dev, "PHY LAN83C180\n");
}
}
err_out:
#ifdef CONFIG_ARCH_PXA
if (retval && dev->dma != (unsigned char)-1)
pxa_free_dma(dev->dma);
#endif
return retval;
}
static int smc_enable_device(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct smc_local *lp = netdev_priv(ndev);
unsigned long flags;
unsigned char ecor, ecsr;
void __iomem *addr;
struct resource * res;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "smc91x-attrib");
if (!res)
return 0;
addr = ioremap(res->start, ATTRIB_SIZE);
if (!addr)
return -ENOMEM;
local_irq_save(flags);
ecor = readb(addr + (ECOR << SMC_IO_SHIFT)) & ~ECOR_RESET;
writeb(ecor | ECOR_RESET, addr + (ECOR << SMC_IO_SHIFT));
readb(addr + (ECOR << SMC_IO_SHIFT));
udelay(100);
writeb(ecor, addr + (ECOR << SMC_IO_SHIFT));
writeb(ecor | ECOR_ENABLE, addr + (ECOR << SMC_IO_SHIFT));
ecsr = readb(addr + (ECSR << SMC_IO_SHIFT)) & ~ECSR_IOIS8;
if (!SMC_16BIT(lp))
ecsr |= ECSR_IOIS8;
writeb(ecsr, addr + (ECSR << SMC_IO_SHIFT));
local_irq_restore(flags);
iounmap(addr);
msleep(1);
return 0;
}
static int smc_request_attrib(struct platform_device *pdev,
struct net_device *ndev)
{
struct resource * res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "smc91x-attrib");
struct smc_local *lp __maybe_unused = netdev_priv(ndev);
if (!res)
return 0;
if (!request_mem_region(res->start, ATTRIB_SIZE, CARDNAME))
return -EBUSY;
return 0;
}
static void smc_release_attrib(struct platform_device *pdev,
struct net_device *ndev)
{
struct resource * res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "smc91x-attrib");
struct smc_local *lp __maybe_unused = netdev_priv(ndev);
if (res)
release_mem_region(res->start, ATTRIB_SIZE);
}
static inline void smc_request_datacs(struct platform_device *pdev, struct net_device *ndev)
{
if (SMC_CAN_USE_DATACS) {
struct resource * res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "smc91x-data32");
struct smc_local *lp = netdev_priv(ndev);
if (!res)
return;
if(!request_mem_region(res->start, SMC_DATA_EXTENT, CARDNAME)) {
netdev_info(ndev, "%s: failed to request datacs memory region.\n",
CARDNAME);
return;
}
lp->datacs = ioremap(res->start, SMC_DATA_EXTENT);
}
}
static void smc_release_datacs(struct platform_device *pdev, struct net_device *ndev)
{
if (SMC_CAN_USE_DATACS) {
struct smc_local *lp = netdev_priv(ndev);
struct resource * res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "smc91x-data32");
if (lp->datacs)
iounmap(lp->datacs);
lp->datacs = NULL;
if (res)
release_mem_region(res->start, SMC_DATA_EXTENT);
}
}
static int smc_drv_probe(struct platform_device *pdev)
{
struct smc91x_platdata *pd = dev_get_platdata(&pdev->dev);
const struct of_device_id *match = NULL;
struct smc_local *lp;
struct net_device *ndev;
struct resource *res, *ires;
unsigned int __iomem *addr;
unsigned long irq_flags = SMC_IRQ_FLAGS;
int ret;
ndev = alloc_etherdev(sizeof(struct smc_local));
if (!ndev) {
ret = -ENOMEM;
goto out;
}
SET_NETDEV_DEV(ndev, &pdev->dev);
lp = netdev_priv(ndev);
lp->cfg.flags = 0;
if (pd) {
memcpy(&lp->cfg, pd, sizeof(lp->cfg));
lp->io_shift = SMC91X_IO_SHIFT(lp->cfg.flags);
}
#if IS_BUILTIN(CONFIG_OF)
match = of_match_device(of_match_ptr(smc91x_match), &pdev->dev);
if (match) {
struct device_node *np = pdev->dev.of_node;
u32 val;
if (!of_property_read_u32(np, "reg-io-width", &val)) {
if (val & 1)
lp->cfg.flags |= SMC91X_USE_8BIT;
if ((val == 0) || (val & 2))
lp->cfg.flags |= SMC91X_USE_16BIT;
if (val & 4)
lp->cfg.flags |= SMC91X_USE_32BIT;
} else {
lp->cfg.flags |= SMC91X_USE_16BIT;
}
}
#endif
if (!pd && !match) {
lp->cfg.flags |= (SMC_CAN_USE_8BIT) ? SMC91X_USE_8BIT : 0;
lp->cfg.flags |= (SMC_CAN_USE_16BIT) ? SMC91X_USE_16BIT : 0;
lp->cfg.flags |= (SMC_CAN_USE_32BIT) ? SMC91X_USE_32BIT : 0;
lp->cfg.flags |= (nowait) ? SMC91X_NOWAIT : 0;
}
if (!lp->cfg.leda && !lp->cfg.ledb) {
lp->cfg.leda = RPC_LSA_DEFAULT;
lp->cfg.ledb = RPC_LSB_DEFAULT;
}
ndev->dma = (unsigned char)-1;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "smc91x-regs");
if (!res)
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
ret = -ENODEV;
goto out_free_netdev;
}
if (!request_mem_region(res->start, SMC_IO_EXTENT, CARDNAME)) {
ret = -EBUSY;
goto out_free_netdev;
}
ires = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!ires) {
ret = -ENODEV;
goto out_release_io;
}
ndev->irq = ires->start;
if (irq_flags == -1 || ires->flags & IRQF_TRIGGER_MASK)
irq_flags = ires->flags & IRQF_TRIGGER_MASK;
ret = smc_request_attrib(pdev, ndev);
if (ret)
goto out_release_io;
#if defined(CONFIG_SA1100_ASSABET)
neponset_ncr_set(NCR_ENET_OSC_EN);
#endif
platform_set_drvdata(pdev, ndev);
ret = smc_enable_device(pdev);
if (ret)
goto out_release_attrib;
addr = ioremap(res->start, SMC_IO_EXTENT);
if (!addr) {
ret = -ENOMEM;
goto out_release_attrib;
}
#ifdef CONFIG_ARCH_PXA
{
struct smc_local *lp = netdev_priv(ndev);
lp->device = &pdev->dev;
lp->physaddr = res->start;
}
#endif
ret = smc_probe(ndev, addr, irq_flags);
if (ret != 0)
goto out_iounmap;
smc_request_datacs(pdev, ndev);
return 0;
out_iounmap:
iounmap(addr);
out_release_attrib:
smc_release_attrib(pdev, ndev);
out_release_io:
release_mem_region(res->start, SMC_IO_EXTENT);
out_free_netdev:
free_netdev(ndev);
out:
pr_info("%s: not found (%d).\n", CARDNAME, ret);
return ret;
}
static int smc_drv_remove(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct smc_local *lp = netdev_priv(ndev);
struct resource *res;
unregister_netdev(ndev);
free_irq(ndev->irq, ndev);
#ifdef CONFIG_ARCH_PXA
if (ndev->dma != (unsigned char)-1)
pxa_free_dma(ndev->dma);
#endif
iounmap(lp->base);
smc_release_datacs(pdev,ndev);
smc_release_attrib(pdev,ndev);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "smc91x-regs");
if (!res)
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(res->start, SMC_IO_EXTENT);
free_netdev(ndev);
return 0;
}
static int smc_drv_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct net_device *ndev = platform_get_drvdata(pdev);
if (ndev) {
if (netif_running(ndev)) {
netif_device_detach(ndev);
smc_shutdown(ndev);
smc_phy_powerdown(ndev);
}
}
return 0;
}
static int smc_drv_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct net_device *ndev = platform_get_drvdata(pdev);
if (ndev) {
struct smc_local *lp = netdev_priv(ndev);
smc_enable_device(pdev);
if (netif_running(ndev)) {
smc_reset(ndev);
smc_enable(ndev);
if (lp->phy_type != 0)
smc_phy_configure(&lp->phy_configure);
netif_device_attach(ndev);
}
}
return 0;
}
