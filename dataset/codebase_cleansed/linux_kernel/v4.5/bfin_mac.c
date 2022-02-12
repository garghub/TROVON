static void desc_list_free(void)
{
struct net_dma_desc_rx *r;
struct net_dma_desc_tx *t;
int i;
#if !defined(CONFIG_BFIN_MAC_USE_L1)
dma_addr_t dma_handle = 0;
#endif
if (tx_desc) {
t = tx_list_head;
for (i = 0; i < CONFIG_BFIN_TX_DESC_NUM; i++) {
if (t) {
if (t->skb) {
dev_kfree_skb(t->skb);
t->skb = NULL;
}
t = t->next;
}
}
bfin_mac_free(dma_handle, tx_desc, CONFIG_BFIN_TX_DESC_NUM);
}
if (rx_desc) {
r = rx_list_head;
for (i = 0; i < CONFIG_BFIN_RX_DESC_NUM; i++) {
if (r) {
if (r->skb) {
dev_kfree_skb(r->skb);
r->skb = NULL;
}
r = r->next;
}
}
bfin_mac_free(dma_handle, rx_desc, CONFIG_BFIN_RX_DESC_NUM);
}
}
static int desc_list_init(struct net_device *dev)
{
int i;
struct sk_buff *new_skb;
#if !defined(CONFIG_BFIN_MAC_USE_L1)
dma_addr_t dma_handle;
#endif
tx_desc = bfin_mac_alloc(&dma_handle,
sizeof(struct net_dma_desc_tx),
CONFIG_BFIN_TX_DESC_NUM);
if (tx_desc == NULL)
goto init_error;
rx_desc = bfin_mac_alloc(&dma_handle,
sizeof(struct net_dma_desc_rx),
CONFIG_BFIN_RX_DESC_NUM);
if (rx_desc == NULL)
goto init_error;
tx_list_head = tx_list_tail = tx_desc;
for (i = 0; i < CONFIG_BFIN_TX_DESC_NUM; i++) {
struct net_dma_desc_tx *t = tx_desc + i;
struct dma_descriptor *a = &(t->desc_a);
struct dma_descriptor *b = &(t->desc_b);
a->config = WDSIZE_32 | NDSIZE_6 | DMAFLOW_LARGE;
a->start_addr = (unsigned long)t->packet;
a->x_count = 0;
a->next_dma_desc = b;
b->config = DMAEN | WNR | WDSIZE_32 | NDSIZE_6 | DMAFLOW_LARGE;
b->start_addr = (unsigned long)(&(t->status));
b->x_count = 0;
t->skb = NULL;
tx_list_tail->desc_b.next_dma_desc = a;
tx_list_tail->next = t;
tx_list_tail = t;
}
tx_list_tail->next = tx_list_head;
tx_list_tail->desc_b.next_dma_desc = &(tx_list_head->desc_a);
current_tx_ptr = tx_list_head;
rx_list_head = rx_list_tail = rx_desc;
for (i = 0; i < CONFIG_BFIN_RX_DESC_NUM; i++) {
struct net_dma_desc_rx *r = rx_desc + i;
struct dma_descriptor *a = &(r->desc_a);
struct dma_descriptor *b = &(r->desc_b);
new_skb = netdev_alloc_skb(dev, PKT_BUF_SZ + NET_IP_ALIGN);
if (!new_skb)
goto init_error;
skb_reserve(new_skb, NET_IP_ALIGN);
blackfin_dcache_invalidate_range((unsigned long)new_skb->head,
(unsigned long)new_skb->end);
r->skb = new_skb;
a->config = DMAEN | WNR | WDSIZE_32 | NDSIZE_6 | DMAFLOW_LARGE;
a->start_addr = (unsigned long)new_skb->data - 2;
a->x_count = 0;
a->next_dma_desc = b;
b->config = DMAEN | WNR | WDSIZE_32 | DI_EN |
NDSIZE_6 | DMAFLOW_LARGE;
b->start_addr = (unsigned long)(&(r->status));
b->x_count = 0;
rx_list_tail->desc_b.next_dma_desc = a;
rx_list_tail->next = r;
rx_list_tail = r;
}
rx_list_tail->next = rx_list_head;
rx_list_tail->desc_b.next_dma_desc = &(rx_list_head->desc_a);
current_rx_ptr = rx_list_head;
return 0;
init_error:
desc_list_free();
pr_err("kmalloc failed\n");
return -ENOMEM;
}
static int bfin_mdio_poll(void)
{
int timeout_cnt = MAX_TIMEOUT_CNT;
while ((bfin_read_EMAC_STAADD()) & STABUSY) {
udelay(1);
if (timeout_cnt-- < 0) {
pr_err("wait MDC/MDIO transaction to complete timeout\n");
return -ETIMEDOUT;
}
}
return 0;
}
static int bfin_mdiobus_read(struct mii_bus *bus, int phy_addr, int regnum)
{
int ret;
ret = bfin_mdio_poll();
if (ret)
return ret;
bfin_write_EMAC_STAADD(SET_PHYAD((u16) phy_addr) |
SET_REGAD((u16) regnum) |
STABUSY);
ret = bfin_mdio_poll();
if (ret)
return ret;
return (int) bfin_read_EMAC_STADAT();
}
static int bfin_mdiobus_write(struct mii_bus *bus, int phy_addr, int regnum,
u16 value)
{
int ret;
ret = bfin_mdio_poll();
if (ret)
return ret;
bfin_write_EMAC_STADAT((u32) value);
bfin_write_EMAC_STAADD(SET_PHYAD((u16) phy_addr) |
SET_REGAD((u16) regnum) |
STAOP |
STABUSY);
return bfin_mdio_poll();
}
static void bfin_mac_adjust_link(struct net_device *dev)
{
struct bfin_mac_local *lp = netdev_priv(dev);
struct phy_device *phydev = lp->phydev;
unsigned long flags;
int new_state = 0;
spin_lock_irqsave(&lp->lock, flags);
if (phydev->link) {
if (phydev->duplex != lp->old_duplex) {
u32 opmode = bfin_read_EMAC_OPMODE();
new_state = 1;
if (phydev->duplex)
opmode |= FDMODE;
else
opmode &= ~(FDMODE);
bfin_write_EMAC_OPMODE(opmode);
lp->old_duplex = phydev->duplex;
}
if (phydev->speed != lp->old_speed) {
if (phydev->interface == PHY_INTERFACE_MODE_RMII) {
u32 opmode = bfin_read_EMAC_OPMODE();
switch (phydev->speed) {
case 10:
opmode |= RMII_10;
break;
case 100:
opmode &= ~RMII_10;
break;
default:
netdev_warn(dev,
"Ack! Speed (%d) is not 10/100!\n",
phydev->speed);
break;
}
bfin_write_EMAC_OPMODE(opmode);
}
new_state = 1;
lp->old_speed = phydev->speed;
}
if (!lp->old_link) {
new_state = 1;
lp->old_link = 1;
}
} else if (lp->old_link) {
new_state = 1;
lp->old_link = 0;
lp->old_speed = 0;
lp->old_duplex = -1;
}
if (new_state) {
u32 opmode = bfin_read_EMAC_OPMODE();
phy_print_status(phydev);
pr_debug("EMAC_OPMODE = 0x%08x\n", opmode);
}
spin_unlock_irqrestore(&lp->lock, flags);
}
static int mii_probe(struct net_device *dev, int phy_mode)
{
struct bfin_mac_local *lp = netdev_priv(dev);
struct phy_device *phydev;
unsigned short sysctl;
u32 sclk, mdc_div;
if (!(bfin_read_VR_CTL() & CLKBUFOE))
bfin_write_VR_CTL(bfin_read_VR_CTL() | CLKBUFOE);
sclk = get_sclk();
mdc_div = ((sclk / MDC_CLK) / 2) - 1;
sysctl = bfin_read_EMAC_SYSCTL();
sysctl = (sysctl & ~MDCDIV) | SET_MDCDIV(mdc_div);
bfin_write_EMAC_SYSCTL(sysctl);
phydev = phy_find_first(lp->mii_bus);
if (!phydev) {
netdev_err(dev, "no phy device found\n");
return -ENODEV;
}
if (phy_mode != PHY_INTERFACE_MODE_RMII &&
phy_mode != PHY_INTERFACE_MODE_MII) {
netdev_err(dev, "invalid phy interface mode\n");
return -EINVAL;
}
phydev = phy_connect(dev, phydev_name(phydev),
&bfin_mac_adjust_link, phy_mode);
if (IS_ERR(phydev)) {
netdev_err(dev, "could not attach PHY\n");
return PTR_ERR(phydev);
}
phydev->supported &= (SUPPORTED_10baseT_Half
| SUPPORTED_10baseT_Full
| SUPPORTED_100baseT_Half
| SUPPORTED_100baseT_Full
| SUPPORTED_Autoneg
| SUPPORTED_Pause | SUPPORTED_Asym_Pause
| SUPPORTED_MII
| SUPPORTED_TP);
phydev->advertising = phydev->supported;
lp->old_link = 0;
lp->old_speed = 0;
lp->old_duplex = -1;
lp->phydev = phydev;
phy_attached_print(phydev, "mdc_clk=%dHz(mdc_div=%d)@sclk=%dMHz)\n",
MDC_CLK, mdc_div, sclk / 1000000);
return 0;
}
static irqreturn_t bfin_mac_wake_interrupt(int irq, void *dev_id)
{
return IRQ_HANDLED;
}
static int
bfin_mac_ethtool_getsettings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct bfin_mac_local *lp = netdev_priv(dev);
if (lp->phydev)
return phy_ethtool_gset(lp->phydev, cmd);
return -EINVAL;
}
static int
bfin_mac_ethtool_setsettings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct bfin_mac_local *lp = netdev_priv(dev);
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if (lp->phydev)
return phy_ethtool_sset(lp->phydev, cmd);
return -EINVAL;
}
static void bfin_mac_ethtool_getdrvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
strlcpy(info->driver, KBUILD_MODNAME, sizeof(info->driver));
strlcpy(info->version, DRV_VERSION, sizeof(info->version));
strlcpy(info->fw_version, "N/A", sizeof(info->fw_version));
strlcpy(info->bus_info, dev_name(&dev->dev), sizeof(info->bus_info));
}
static void bfin_mac_ethtool_getwol(struct net_device *dev,
struct ethtool_wolinfo *wolinfo)
{
struct bfin_mac_local *lp = netdev_priv(dev);
wolinfo->supported = WAKE_MAGIC;
wolinfo->wolopts = lp->wol;
}
static int bfin_mac_ethtool_setwol(struct net_device *dev,
struct ethtool_wolinfo *wolinfo)
{
struct bfin_mac_local *lp = netdev_priv(dev);
int rc;
if (wolinfo->wolopts & (WAKE_MAGICSECURE |
WAKE_UCAST |
WAKE_MCAST |
WAKE_BCAST |
WAKE_ARP))
return -EOPNOTSUPP;
lp->wol = wolinfo->wolopts;
if (lp->wol && !lp->irq_wake_requested) {
rc = request_irq(IRQ_MAC_WAKEDET, bfin_mac_wake_interrupt,
0, "EMAC_WAKE", dev);
if (rc)
return rc;
lp->irq_wake_requested = true;
}
if (!lp->wol && lp->irq_wake_requested) {
free_irq(IRQ_MAC_WAKEDET, dev);
lp->irq_wake_requested = false;
}
device_init_wakeup(&dev->dev, lp->wol);
return 0;
}
static int bfin_mac_ethtool_get_ts_info(struct net_device *dev,
struct ethtool_ts_info *info)
{
struct bfin_mac_local *lp = netdev_priv(dev);
info->so_timestamping =
SOF_TIMESTAMPING_TX_HARDWARE |
SOF_TIMESTAMPING_RX_HARDWARE |
SOF_TIMESTAMPING_RAW_HARDWARE;
info->phc_index = lp->phc_index;
info->tx_types =
(1 << HWTSTAMP_TX_OFF) |
(1 << HWTSTAMP_TX_ON);
info->rx_filters =
(1 << HWTSTAMP_FILTER_NONE) |
(1 << HWTSTAMP_FILTER_PTP_V1_L4_EVENT) |
(1 << HWTSTAMP_FILTER_PTP_V2_L2_EVENT) |
(1 << HWTSTAMP_FILTER_PTP_V2_L4_EVENT);
return 0;
}
static void setup_system_regs(struct net_device *dev)
{
struct bfin_mac_local *lp = netdev_priv(dev);
int i;
unsigned short sysctl;
sysctl = bfin_read_EMAC_SYSCTL();
for (i = 0; i < PHY_MAX_ADDR; ++i)
if (lp->mii_bus->irq[i] != PHY_POLL)
break;
if (i < PHY_MAX_ADDR)
sysctl |= PHYIE;
sysctl |= RXDWA;
#if defined(BFIN_MAC_CSUM_OFFLOAD)
sysctl |= RXCKS;
#else
sysctl &= ~RXCKS;
#endif
bfin_write_EMAC_SYSCTL(sysctl);
bfin_write_EMAC_MMC_CTL(RSTC | CROLL);
bfin_write_EMAC_VLAN1(lp->vlan1_mask);
bfin_write_EMAC_VLAN2(lp->vlan2_mask);
bfin_write_DMA2_X_COUNT(0);
bfin_write_DMA2_X_MODIFY(4);
bfin_write_DMA2_Y_COUNT(0);
bfin_write_DMA2_Y_MODIFY(0);
bfin_write_DMA1_X_COUNT(0);
bfin_write_DMA1_X_MODIFY(4);
bfin_write_DMA1_Y_COUNT(0);
bfin_write_DMA1_Y_MODIFY(0);
}
static void setup_mac_addr(u8 *mac_addr)
{
u32 addr_low = le32_to_cpu(*(__le32 *) & mac_addr[0]);
u16 addr_hi = le16_to_cpu(*(__le16 *) & mac_addr[4]);
bfin_write_EMAC_ADDRLO(addr_low);
bfin_write_EMAC_ADDRHI(addr_hi);
}
static int bfin_mac_set_mac_address(struct net_device *dev, void *p)
{
struct sockaddr *addr = p;
if (netif_running(dev))
return -EBUSY;
memcpy(dev->dev_addr, addr->sa_data, dev->addr_len);
setup_mac_addr(dev->dev_addr);
return 0;
}
static u32 bfin_select_phc_clock(u32 input_clk, unsigned int *shift_result)
{
u32 ipn = 1000000000UL / input_clk;
u32 ppn = 1;
unsigned int shift = 0;
while (ppn <= ipn) {
ppn <<= 1;
shift++;
}
*shift_result = shift;
return 1000000000UL / ppn;
}
static int bfin_mac_hwtstamp_set(struct net_device *netdev,
struct ifreq *ifr)
{
struct hwtstamp_config config;
struct bfin_mac_local *lp = netdev_priv(netdev);
u16 ptpctl;
u32 ptpfv1, ptpfv2, ptpfv3, ptpfoff;
if (copy_from_user(&config, ifr->ifr_data, sizeof(config)))
return -EFAULT;
pr_debug("%s config flag:0x%x, tx_type:0x%x, rx_filter:0x%x\n",
__func__, config.flags, config.tx_type, config.rx_filter);
if (config.flags)
return -EINVAL;
if ((config.tx_type != HWTSTAMP_TX_OFF) &&
(config.tx_type != HWTSTAMP_TX_ON))
return -ERANGE;
ptpctl = bfin_read_EMAC_PTP_CTL();
switch (config.rx_filter) {
case HWTSTAMP_FILTER_NONE:
ptpfv3 = 0xFFFFFFFF;
bfin_write_EMAC_PTP_FV3(ptpfv3);
break;
case HWTSTAMP_FILTER_PTP_V1_L4_EVENT:
case HWTSTAMP_FILTER_PTP_V1_L4_SYNC:
case HWTSTAMP_FILTER_PTP_V1_L4_DELAY_REQ:
ptpctl &= ~0x1F00;
bfin_write_EMAC_PTP_CTL(ptpctl);
ptpfoff = 0x4A24170C;
bfin_write_EMAC_PTP_FOFF(ptpfoff);
ptpfv1 = 0x11040800;
bfin_write_EMAC_PTP_FV1(ptpfv1);
ptpfv2 = 0x0140013F;
bfin_write_EMAC_PTP_FV2(ptpfv2);
ptpfv3 = 0xFFFFFFFC;
bfin_write_EMAC_PTP_FV3(ptpfv3);
config.rx_filter = HWTSTAMP_FILTER_PTP_V1_L4_EVENT;
break;
case HWTSTAMP_FILTER_PTP_V2_L4_EVENT:
case HWTSTAMP_FILTER_PTP_V2_L4_SYNC:
case HWTSTAMP_FILTER_PTP_V2_DELAY_REQ:
ptpctl &= ~0x1F00;
bfin_write_EMAC_PTP_CTL(ptpctl);
ptpfoff = 0x2A24170C;
bfin_write_EMAC_PTP_FOFF(ptpfoff);
ptpfv1 = 0x11040800;
bfin_write_EMAC_PTP_FV1(ptpfv1);
ptpfv2 = 0x0140013F;
bfin_write_EMAC_PTP_FV2(ptpfv2);
ptpfv3 = 0xFFFFFFF0;
bfin_write_EMAC_PTP_FV3(ptpfv3);
config.rx_filter = HWTSTAMP_FILTER_PTP_V2_L4_EVENT;
break;
case HWTSTAMP_FILTER_PTP_V2_L2_EVENT:
case HWTSTAMP_FILTER_PTP_V2_L2_SYNC:
case HWTSTAMP_FILTER_PTP_V2_L2_DELAY_REQ:
ptpctl &= ~0x1100;
bfin_write_EMAC_PTP_CTL(ptpctl);
ptpfoff = 0x0E24170C;
bfin_write_EMAC_PTP_FOFF(ptpfoff);
ptpfv1 = 0x110488F7;
bfin_write_EMAC_PTP_FV1(ptpfv1);
ptpfv2 = 0x0140013F;
bfin_write_EMAC_PTP_FV2(ptpfv2);
ptpfv3 = 0xFFFFFFF0;
bfin_write_EMAC_PTP_FV3(ptpfv3);
config.rx_filter = HWTSTAMP_FILTER_PTP_V2_L2_EVENT;
break;
default:
return -ERANGE;
}
if (config.tx_type == HWTSTAMP_TX_OFF &&
bfin_mac_hwtstamp_is_none(config.rx_filter)) {
ptpctl &= ~PTP_EN;
bfin_write_EMAC_PTP_CTL(ptpctl);
SSYNC();
} else {
ptpctl |= PTP_EN;
bfin_write_EMAC_PTP_CTL(ptpctl);
bfin_read_EMAC_PTP_RXSNAPLO();
bfin_read_EMAC_PTP_RXSNAPHI();
bfin_read_EMAC_PTP_TXSNAPLO();
bfin_read_EMAC_PTP_TXSNAPHI();
SSYNC();
}
lp->stamp_cfg = config;
return copy_to_user(ifr->ifr_data, &config, sizeof(config)) ?
-EFAULT : 0;
}
static int bfin_mac_hwtstamp_get(struct net_device *netdev,
struct ifreq *ifr)
{
struct bfin_mac_local *lp = netdev_priv(netdev);
return copy_to_user(ifr->ifr_data, &lp->stamp_cfg,
sizeof(lp->stamp_cfg)) ?
-EFAULT : 0;
}
static void bfin_tx_hwtstamp(struct net_device *netdev, struct sk_buff *skb)
{
struct bfin_mac_local *lp = netdev_priv(netdev);
if (skb_shinfo(skb)->tx_flags & SKBTX_HW_TSTAMP) {
int timeout_cnt = MAX_TIMEOUT_CNT;
skb_shinfo(skb)->tx_flags |= SKBTX_IN_PROGRESS;
while ((!(bfin_read_EMAC_PTP_ISTAT() & TXTL)) && (--timeout_cnt))
udelay(1);
if (timeout_cnt == 0)
netdev_err(netdev, "timestamp the TX packet failed\n");
else {
struct skb_shared_hwtstamps shhwtstamps;
u64 ns;
u64 regval;
regval = bfin_read_EMAC_PTP_TXSNAPLO();
regval |= (u64)bfin_read_EMAC_PTP_TXSNAPHI() << 32;
memset(&shhwtstamps, 0, sizeof(shhwtstamps));
ns = regval << lp->shift;
shhwtstamps.hwtstamp = ns_to_ktime(ns);
skb_tstamp_tx(skb, &shhwtstamps);
}
}
}
static void bfin_rx_hwtstamp(struct net_device *netdev, struct sk_buff *skb)
{
struct bfin_mac_local *lp = netdev_priv(netdev);
u32 valid;
u64 regval, ns;
struct skb_shared_hwtstamps *shhwtstamps;
if (bfin_mac_hwtstamp_is_none(lp->stamp_cfg.rx_filter))
return;
valid = bfin_read_EMAC_PTP_ISTAT() & RXEL;
if (!valid)
return;
shhwtstamps = skb_hwtstamps(skb);
regval = bfin_read_EMAC_PTP_RXSNAPLO();
regval |= (u64)bfin_read_EMAC_PTP_RXSNAPHI() << 32;
ns = regval << lp->shift;
memset(shhwtstamps, 0, sizeof(*shhwtstamps));
shhwtstamps->hwtstamp = ns_to_ktime(ns);
}
static void bfin_mac_hwtstamp_init(struct net_device *netdev)
{
struct bfin_mac_local *lp = netdev_priv(netdev);
u64 addend, ppb;
u32 input_clk, phc_clk;
input_clk = get_sclk();
phc_clk = bfin_select_phc_clock(input_clk, &lp->shift);
addend = phc_clk * (1ULL << 32);
do_div(addend, input_clk);
bfin_write_EMAC_PTP_ADDEND((u32)addend);
lp->addend = addend;
ppb = 1000000000ULL * input_clk;
do_div(ppb, phc_clk);
lp->max_ppb = ppb - 1000000000ULL - 1ULL;
lp->stamp_cfg.rx_filter = HWTSTAMP_FILTER_NONE;
lp->stamp_cfg.tx_type = HWTSTAMP_TX_OFF;
}
static u64 bfin_ptp_time_read(struct bfin_mac_local *lp)
{
u64 ns;
u32 lo, hi;
lo = bfin_read_EMAC_PTP_TIMELO();
hi = bfin_read_EMAC_PTP_TIMEHI();
ns = ((u64) hi) << 32;
ns |= lo;
ns <<= lp->shift;
return ns;
}
static void bfin_ptp_time_write(struct bfin_mac_local *lp, u64 ns)
{
u32 hi, lo;
ns >>= lp->shift;
hi = ns >> 32;
lo = ns & 0xffffffff;
bfin_write_EMAC_PTP_TIMELO(lo);
bfin_write_EMAC_PTP_TIMEHI(hi);
}
static int bfin_ptp_adjfreq(struct ptp_clock_info *ptp, s32 ppb)
{
u64 adj;
u32 diff, addend;
int neg_adj = 0;
struct bfin_mac_local *lp =
container_of(ptp, struct bfin_mac_local, caps);
if (ppb < 0) {
neg_adj = 1;
ppb = -ppb;
}
addend = lp->addend;
adj = addend;
adj *= ppb;
diff = div_u64(adj, 1000000000ULL);
addend = neg_adj ? addend - diff : addend + diff;
bfin_write_EMAC_PTP_ADDEND(addend);
return 0;
}
static int bfin_ptp_adjtime(struct ptp_clock_info *ptp, s64 delta)
{
s64 now;
unsigned long flags;
struct bfin_mac_local *lp =
container_of(ptp, struct bfin_mac_local, caps);
spin_lock_irqsave(&lp->phc_lock, flags);
now = bfin_ptp_time_read(lp);
now += delta;
bfin_ptp_time_write(lp, now);
spin_unlock_irqrestore(&lp->phc_lock, flags);
return 0;
}
static int bfin_ptp_gettime(struct ptp_clock_info *ptp, struct timespec64 *ts)
{
u64 ns;
unsigned long flags;
struct bfin_mac_local *lp =
container_of(ptp, struct bfin_mac_local, caps);
spin_lock_irqsave(&lp->phc_lock, flags);
ns = bfin_ptp_time_read(lp);
spin_unlock_irqrestore(&lp->phc_lock, flags);
*ts = ns_to_timespec64(ns);
return 0;
}
static int bfin_ptp_settime(struct ptp_clock_info *ptp,
const struct timespec64 *ts)
{
u64 ns;
unsigned long flags;
struct bfin_mac_local *lp =
container_of(ptp, struct bfin_mac_local, caps);
ns = timespec64_to_ns(ts);
spin_lock_irqsave(&lp->phc_lock, flags);
bfin_ptp_time_write(lp, ns);
spin_unlock_irqrestore(&lp->phc_lock, flags);
return 0;
}
static int bfin_ptp_enable(struct ptp_clock_info *ptp,
struct ptp_clock_request *rq, int on)
{
return -EOPNOTSUPP;
}
static int bfin_phc_init(struct net_device *netdev, struct device *dev)
{
struct bfin_mac_local *lp = netdev_priv(netdev);
lp->caps = bfin_ptp_caps;
lp->caps.max_adj = lp->max_ppb;
lp->clock = ptp_clock_register(&lp->caps, dev);
if (IS_ERR(lp->clock))
return PTR_ERR(lp->clock);
lp->phc_index = ptp_clock_index(lp->clock);
spin_lock_init(&lp->phc_lock);
return 0;
}
static void bfin_phc_release(struct bfin_mac_local *lp)
{
ptp_clock_unregister(lp->clock);
}
static inline void _tx_reclaim_skb(void)
{
do {
tx_list_head->desc_a.config &= ~DMAEN;
tx_list_head->status.status_word = 0;
if (tx_list_head->skb) {
dev_consume_skb_any(tx_list_head->skb);
tx_list_head->skb = NULL;
}
tx_list_head = tx_list_head->next;
} while (tx_list_head->status.status_word != 0);
}
static void tx_reclaim_skb(struct bfin_mac_local *lp)
{
int timeout_cnt = MAX_TIMEOUT_CNT;
if (tx_list_head->status.status_word != 0)
_tx_reclaim_skb();
if (current_tx_ptr->next == tx_list_head) {
while (tx_list_head->status.status_word == 0) {
udelay(10);
if (!(bfin_read_DMA2_IRQ_STATUS() & DMA_RUN))
break;
if (timeout_cnt-- < 0)
break;
}
if (timeout_cnt >= 0)
_tx_reclaim_skb();
else
netif_stop_queue(lp->ndev);
}
if (current_tx_ptr->next != tx_list_head &&
netif_queue_stopped(lp->ndev))
netif_wake_queue(lp->ndev);
if (tx_list_head != current_tx_ptr) {
if (netif_queue_stopped(lp->ndev))
lp->tx_reclaim_timer.expires =
jiffies + (TX_RECLAIM_JIFFIES >> 4);
else
lp->tx_reclaim_timer.expires =
jiffies + TX_RECLAIM_JIFFIES;
mod_timer(&lp->tx_reclaim_timer,
lp->tx_reclaim_timer.expires);
}
return;
}
static void tx_reclaim_skb_timeout(unsigned long lp)
{
tx_reclaim_skb((struct bfin_mac_local *)lp);
}
static int bfin_mac_hard_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct bfin_mac_local *lp = netdev_priv(dev);
u16 *data;
u32 data_align = (unsigned long)(skb->data) & 0x3;
current_tx_ptr->skb = skb;
if (data_align == 0x2) {
data = (u16 *)(skb->data) - 1;
*data = (u16)(skb->len);
if (skb_shinfo(skb)->tx_flags & SKBTX_HW_TSTAMP)
*data |= 0x1000;
current_tx_ptr->desc_a.start_addr = (u32)data;
blackfin_dcache_flush_range((u32)data,
(u32)((u8 *)data + skb->len + 4));
} else {
*((u16 *)(current_tx_ptr->packet)) = (u16)(skb->len);
if (skb_shinfo(skb)->tx_flags & SKBTX_HW_TSTAMP)
*((u16 *)(current_tx_ptr->packet)) |= 0x1000;
memcpy((u8 *)(current_tx_ptr->packet + 2), skb->data,
skb->len);
current_tx_ptr->desc_a.start_addr =
(u32)current_tx_ptr->packet;
blackfin_dcache_flush_range(
(u32)current_tx_ptr->packet,
(u32)(current_tx_ptr->packet + skb->len + 2));
}
SSYNC();
current_tx_ptr->status.status_word = 0;
current_tx_ptr->desc_a.config |= DMAEN;
if (bfin_read_DMA2_IRQ_STATUS() & DMA_RUN)
goto out;
bfin_write_DMA2_NEXT_DESC_PTR(&(current_tx_ptr->desc_a));
bfin_write_DMA2_CONFIG(current_tx_ptr->desc_a.config);
bfin_write_EMAC_OPMODE(bfin_read_EMAC_OPMODE() | TE);
out:
bfin_tx_hwtstamp(dev, skb);
current_tx_ptr = current_tx_ptr->next;
dev->stats.tx_packets++;
dev->stats.tx_bytes += (skb->len);
tx_reclaim_skb(lp);
return NETDEV_TX_OK;
}
static void bfin_mac_rx(struct bfin_mac_local *lp)
{
struct net_device *dev = lp->ndev;
struct sk_buff *skb, *new_skb;
unsigned short len;
#if defined(BFIN_MAC_CSUM_OFFLOAD)
unsigned int i;
unsigned char fcs[ETH_FCS_LEN + 1];
#endif
if (current_rx_ptr->status.status_word & RX_ERROR_MASK) {
netdev_notice(dev, "rx: receive error - packet dropped\n");
dev->stats.rx_dropped++;
goto out;
}
skb = current_rx_ptr->skb;
new_skb = netdev_alloc_skb(dev, PKT_BUF_SZ + NET_IP_ALIGN);
if (!new_skb) {
dev->stats.rx_dropped++;
goto out;
}
skb_reserve(new_skb, NET_IP_ALIGN);
blackfin_dcache_invalidate_range((unsigned long)new_skb->head,
(unsigned long)new_skb->end);
current_rx_ptr->skb = new_skb;
current_rx_ptr->desc_a.start_addr = (unsigned long)new_skb->data - 2;
len = (unsigned short)(current_rx_ptr->status.status_word & RX_FRLEN);
len -= ETH_FCS_LEN;
skb_put(skb, len);
skb->protocol = eth_type_trans(skb, dev);
bfin_rx_hwtstamp(dev, skb);
#if defined(BFIN_MAC_CSUM_OFFLOAD)
if (skb->data[IP_HEADER_OFF] == 0x45) {
skb->csum = current_rx_ptr->status.ip_payload_csum;
if (skb->len % 2) {
fcs[0] = 0;
for (i = 0; i < ETH_FCS_LEN; i++)
fcs[i + 1] = ~skb->data[skb->len + i];
skb->csum = csum_partial(fcs, ETH_FCS_LEN + 1, skb->csum);
} else {
for (i = 0; i < ETH_FCS_LEN; i++)
fcs[i] = ~skb->data[skb->len + i];
skb->csum = csum_partial(fcs, ETH_FCS_LEN, skb->csum);
}
skb->ip_summed = CHECKSUM_COMPLETE;
}
#endif
napi_gro_receive(&lp->napi, skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += len;
out:
current_rx_ptr->status.status_word = 0x00000000;
current_rx_ptr = current_rx_ptr->next;
}
static int bfin_mac_poll(struct napi_struct *napi, int budget)
{
int i = 0;
struct bfin_mac_local *lp = container_of(napi,
struct bfin_mac_local,
napi);
while (current_rx_ptr->status.status_word != 0 && i < budget) {
bfin_mac_rx(lp);
i++;
}
if (i < budget) {
napi_complete(napi);
if (test_and_clear_bit(BFIN_MAC_RX_IRQ_DISABLED, &lp->flags))
enable_irq(IRQ_MAC_RX);
}
return i;
}
static irqreturn_t bfin_mac_interrupt(int irq, void *dev_id)
{
struct bfin_mac_local *lp = netdev_priv(dev_id);
u32 status;
status = bfin_read_DMA1_IRQ_STATUS();
bfin_write_DMA1_IRQ_STATUS(status | DMA_DONE | DMA_ERR);
if (status & DMA_DONE) {
disable_irq_nosync(IRQ_MAC_RX);
set_bit(BFIN_MAC_RX_IRQ_DISABLED, &lp->flags);
napi_schedule(&lp->napi);
}
return IRQ_HANDLED;
}
static void bfin_mac_poll_controller(struct net_device *dev)
{
struct bfin_mac_local *lp = netdev_priv(dev);
bfin_mac_interrupt(IRQ_MAC_RX, dev);
tx_reclaim_skb(lp);
}
static void bfin_mac_disable(void)
{
unsigned int opmode;
opmode = bfin_read_EMAC_OPMODE();
opmode &= (~RE);
opmode &= (~TE);
bfin_write_EMAC_OPMODE(opmode);
}
static int bfin_mac_enable(struct phy_device *phydev)
{
int ret;
u32 opmode;
pr_debug("%s\n", __func__);
bfin_write_DMA1_NEXT_DESC_PTR(&(rx_list_head->desc_a));
bfin_write_DMA1_CONFIG(rx_list_head->desc_a.config);
ret = bfin_mdio_poll();
if (ret)
return ret;
opmode = bfin_read_EMAC_OPMODE();
if (opmode & FDMODE)
opmode |= PSF;
else
opmode |= DRO | DC | PSF;
opmode |= RE;
if (phydev->interface == PHY_INTERFACE_MODE_RMII) {
opmode |= RMII;
#if defined(CONFIG_BF537) || defined(CONFIG_BF536)
if (__SILICON_REVISION__ < 3) {
opmode |= TE;
}
#endif
}
bfin_write_EMAC_OPMODE(opmode);
return 0;
}
static void bfin_mac_timeout(struct net_device *dev)
{
struct bfin_mac_local *lp = netdev_priv(dev);
pr_debug("%s: %s\n", dev->name, __func__);
bfin_mac_disable();
del_timer(&lp->tx_reclaim_timer);
while (tx_list_head != current_tx_ptr) {
tx_list_head->desc_a.config &= ~DMAEN;
tx_list_head->status.status_word = 0;
if (tx_list_head->skb) {
dev_kfree_skb(tx_list_head->skb);
tx_list_head->skb = NULL;
}
tx_list_head = tx_list_head->next;
}
if (netif_queue_stopped(dev))
netif_wake_queue(dev);
bfin_mac_enable(lp->phydev);
dev->trans_start = jiffies;
}
static void bfin_mac_multicast_hash(struct net_device *dev)
{
u32 emac_hashhi, emac_hashlo;
struct netdev_hw_addr *ha;
u32 crc;
emac_hashhi = emac_hashlo = 0;
netdev_for_each_mc_addr(ha, dev) {
crc = ether_crc(ETH_ALEN, ha->addr);
crc >>= 26;
if (crc & 0x20)
emac_hashhi |= 1 << (crc & 0x1f);
else
emac_hashlo |= 1 << (crc & 0x1f);
}
bfin_write_EMAC_HASHHI(emac_hashhi);
bfin_write_EMAC_HASHLO(emac_hashlo);
}
static void bfin_mac_set_multicast_list(struct net_device *dev)
{
u32 sysctl;
if (dev->flags & IFF_PROMISC) {
netdev_info(dev, "set promisc mode\n");
sysctl = bfin_read_EMAC_OPMODE();
sysctl |= PR;
bfin_write_EMAC_OPMODE(sysctl);
} else if (dev->flags & IFF_ALLMULTI) {
sysctl = bfin_read_EMAC_OPMODE();
sysctl |= PAM;
bfin_write_EMAC_OPMODE(sysctl);
} else if (!netdev_mc_empty(dev)) {
sysctl = bfin_read_EMAC_OPMODE();
sysctl |= HM;
bfin_write_EMAC_OPMODE(sysctl);
bfin_mac_multicast_hash(dev);
} else {
sysctl = bfin_read_EMAC_OPMODE();
sysctl &= ~(RAF | PAM);
bfin_write_EMAC_OPMODE(sysctl);
}
}
static int bfin_mac_ioctl(struct net_device *netdev, struct ifreq *ifr, int cmd)
{
struct bfin_mac_local *lp = netdev_priv(netdev);
if (!netif_running(netdev))
return -EINVAL;
switch (cmd) {
case SIOCSHWTSTAMP:
return bfin_mac_hwtstamp_set(netdev, ifr);
case SIOCGHWTSTAMP:
return bfin_mac_hwtstamp_get(netdev, ifr);
default:
if (lp->phydev)
return phy_mii_ioctl(lp->phydev, ifr, cmd);
else
return -EOPNOTSUPP;
}
}
static void bfin_mac_shutdown(struct net_device *dev)
{
bfin_write_EMAC_OPMODE(0x00000000);
bfin_write_DMA1_CONFIG(0x0000);
bfin_write_DMA2_CONFIG(0x0000);
}
static int bfin_mac_open(struct net_device *dev)
{
struct bfin_mac_local *lp = netdev_priv(dev);
int ret;
pr_debug("%s: %s\n", dev->name, __func__);
if (!is_valid_ether_addr(dev->dev_addr)) {
netdev_warn(dev, "no valid ethernet hw addr\n");
return -EINVAL;
}
ret = desc_list_init(dev);
if (ret)
return ret;
phy_start(lp->phydev);
setup_system_regs(dev);
setup_mac_addr(dev->dev_addr);
bfin_mac_disable();
ret = bfin_mac_enable(lp->phydev);
if (ret)
return ret;
pr_debug("hardware init finished\n");
napi_enable(&lp->napi);
netif_start_queue(dev);
netif_carrier_on(dev);
return 0;
}
static int bfin_mac_close(struct net_device *dev)
{
struct bfin_mac_local *lp = netdev_priv(dev);
pr_debug("%s: %s\n", dev->name, __func__);
netif_stop_queue(dev);
napi_disable(&lp->napi);
netif_carrier_off(dev);
phy_stop(lp->phydev);
phy_write(lp->phydev, MII_BMCR, BMCR_PDOWN);
bfin_mac_shutdown(dev);
desc_list_free();
return 0;
}
static int bfin_mac_probe(struct platform_device *pdev)
{
struct net_device *ndev;
struct bfin_mac_local *lp;
struct platform_device *pd;
struct bfin_mii_bus_platform_data *mii_bus_data;
int rc;
ndev = alloc_etherdev(sizeof(struct bfin_mac_local));
if (!ndev)
return -ENOMEM;
SET_NETDEV_DEV(ndev, &pdev->dev);
platform_set_drvdata(pdev, ndev);
lp = netdev_priv(ndev);
lp->ndev = ndev;
*(__le32 *) (&(ndev->dev_addr[0])) = cpu_to_le32(bfin_read_EMAC_ADDRLO());
*(__le16 *) (&(ndev->dev_addr[4])) = cpu_to_le16((u16) bfin_read_EMAC_ADDRHI());
bfin_write_EMAC_ADDRLO(0x12345678);
if (bfin_read_EMAC_ADDRLO() != 0x12345678) {
dev_err(&pdev->dev, "Cannot detect Blackfin on-chip ethernet MAC controller!\n");
rc = -ENODEV;
goto out_err_probe_mac;
}
if (!is_valid_ether_addr(ndev->dev_addr)) {
if (bfin_get_ether_addr(ndev->dev_addr) ||
!is_valid_ether_addr(ndev->dev_addr)) {
netdev_warn(ndev, "Setting Ethernet MAC to a random one\n");
eth_hw_addr_random(ndev);
}
}
setup_mac_addr(ndev->dev_addr);
if (!dev_get_platdata(&pdev->dev)) {
dev_err(&pdev->dev, "Cannot get platform device bfin_mii_bus!\n");
rc = -ENODEV;
goto out_err_probe_mac;
}
pd = dev_get_platdata(&pdev->dev);
lp->mii_bus = platform_get_drvdata(pd);
if (!lp->mii_bus) {
dev_err(&pdev->dev, "Cannot get mii_bus!\n");
rc = -ENODEV;
goto out_err_probe_mac;
}
lp->mii_bus->priv = ndev;
mii_bus_data = dev_get_platdata(&pd->dev);
rc = mii_probe(ndev, mii_bus_data->phy_mode);
if (rc) {
dev_err(&pdev->dev, "MII Probe failed!\n");
goto out_err_mii_probe;
}
lp->vlan1_mask = ETH_P_8021Q | mii_bus_data->vlan1_mask;
lp->vlan2_mask = ETH_P_8021Q | mii_bus_data->vlan2_mask;
ndev->netdev_ops = &bfin_mac_netdev_ops;
ndev->ethtool_ops = &bfin_mac_ethtool_ops;
init_timer(&lp->tx_reclaim_timer);
lp->tx_reclaim_timer.data = (unsigned long)lp;
lp->tx_reclaim_timer.function = tx_reclaim_skb_timeout;
lp->flags = 0;
netif_napi_add(ndev, &lp->napi, bfin_mac_poll, CONFIG_BFIN_RX_DESC_NUM);
spin_lock_init(&lp->lock);
rc = request_irq(IRQ_MAC_RX, bfin_mac_interrupt,
0, "EMAC_RX", ndev);
if (rc) {
dev_err(&pdev->dev, "Cannot request Blackfin MAC RX IRQ!\n");
rc = -EBUSY;
goto out_err_request_irq;
}
rc = register_netdev(ndev);
if (rc) {
dev_err(&pdev->dev, "Cannot register net device!\n");
goto out_err_reg_ndev;
}
bfin_mac_hwtstamp_init(ndev);
rc = bfin_phc_init(ndev, &pdev->dev);
if (rc) {
dev_err(&pdev->dev, "Cannot register PHC device!\n");
goto out_err_phc;
}
netdev_info(ndev, "%s, Version %s\n", DRV_DESC, DRV_VERSION);
return 0;
out_err_phc:
out_err_reg_ndev:
free_irq(IRQ_MAC_RX, ndev);
out_err_request_irq:
netif_napi_del(&lp->napi);
out_err_mii_probe:
mdiobus_unregister(lp->mii_bus);
mdiobus_free(lp->mii_bus);
out_err_probe_mac:
free_netdev(ndev);
return rc;
}
static int bfin_mac_remove(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct bfin_mac_local *lp = netdev_priv(ndev);
bfin_phc_release(lp);
lp->mii_bus->priv = NULL;
unregister_netdev(ndev);
netif_napi_del(&lp->napi);
free_irq(IRQ_MAC_RX, ndev);
free_netdev(ndev);
return 0;
}
static int bfin_mac_suspend(struct platform_device *pdev, pm_message_t mesg)
{
struct net_device *net_dev = platform_get_drvdata(pdev);
struct bfin_mac_local *lp = netdev_priv(net_dev);
if (lp->wol) {
bfin_write_EMAC_OPMODE((bfin_read_EMAC_OPMODE() & ~TE) | RE);
bfin_write_EMAC_WKUP_CTL(MPKE);
enable_irq_wake(IRQ_MAC_WAKEDET);
} else {
if (netif_running(net_dev))
bfin_mac_close(net_dev);
}
return 0;
}
static int bfin_mac_resume(struct platform_device *pdev)
{
struct net_device *net_dev = platform_get_drvdata(pdev);
struct bfin_mac_local *lp = netdev_priv(net_dev);
if (lp->wol) {
bfin_write_EMAC_OPMODE(bfin_read_EMAC_OPMODE() | TE);
bfin_write_EMAC_WKUP_CTL(0);
disable_irq_wake(IRQ_MAC_WAKEDET);
} else {
if (netif_running(net_dev))
bfin_mac_open(net_dev);
}
return 0;
}
static int bfin_mii_bus_probe(struct platform_device *pdev)
{
struct mii_bus *miibus;
struct bfin_mii_bus_platform_data *mii_bus_pd;
const unsigned short *pin_req;
int rc, i;
mii_bus_pd = dev_get_platdata(&pdev->dev);
if (!mii_bus_pd) {
dev_err(&pdev->dev, "No peripherals in platform data!\n");
return -EINVAL;
}
pin_req = mii_bus_pd->mac_peripherals;
rc = peripheral_request_list(pin_req, KBUILD_MODNAME);
if (rc) {
dev_err(&pdev->dev, "Requesting peripherals failed!\n");
return rc;
}
rc = -ENOMEM;
miibus = mdiobus_alloc();
if (miibus == NULL)
goto out_err_alloc;
miibus->read = bfin_mdiobus_read;
miibus->write = bfin_mdiobus_write;
miibus->parent = &pdev->dev;
miibus->name = "bfin_mii_bus";
miibus->phy_mask = mii_bus_pd->phy_mask;
snprintf(miibus->id, MII_BUS_ID_SIZE, "%s-%x",
pdev->name, pdev->id);
rc = clamp(mii_bus_pd->phydev_number, 0, PHY_MAX_ADDR);
if (rc != mii_bus_pd->phydev_number)
dev_err(&pdev->dev, "Invalid number (%i) of phydevs\n",
mii_bus_pd->phydev_number);
for (i = 0; i < rc; ++i) {
unsigned short phyaddr = mii_bus_pd->phydev_data[i].addr;
if (phyaddr < PHY_MAX_ADDR)
miibus->irq[phyaddr] = mii_bus_pd->phydev_data[i].irq;
else
dev_err(&pdev->dev,
"Invalid PHY address %i for phydev %i\n",
phyaddr, i);
}
rc = mdiobus_register(miibus);
if (rc) {
dev_err(&pdev->dev, "Cannot register MDIO bus!\n");
goto out_err_irq_alloc;
}
platform_set_drvdata(pdev, miibus);
return 0;
out_err_irq_alloc:
mdiobus_free(miibus);
out_err_alloc:
peripheral_free_list(pin_req);
return rc;
}
static int bfin_mii_bus_remove(struct platform_device *pdev)
{
struct mii_bus *miibus = platform_get_drvdata(pdev);
struct bfin_mii_bus_platform_data *mii_bus_pd =
dev_get_platdata(&pdev->dev);
mdiobus_unregister(miibus);
mdiobus_free(miibus);
peripheral_free_list(mii_bus_pd->mac_peripherals);
return 0;
}
static int __init bfin_mac_init(void)
{
return platform_register_drivers(drivers, ARRAY_SIZE(drivers));
}
static void __exit bfin_mac_cleanup(void)
{
platform_unregister_drivers(drivers, ARRAY_SIZE(drivers));
}
