static void stmmac_verify_args(void)
{
if (unlikely(watchdog < 0))
watchdog = TX_TIMEO;
if (unlikely((buf_sz < DEFAULT_BUFSIZE) || (buf_sz > BUF_SIZE_16KiB)))
buf_sz = DEFAULT_BUFSIZE;
if (unlikely(flow_ctrl > 1))
flow_ctrl = FLOW_AUTO;
else if (likely(flow_ctrl < 0))
flow_ctrl = FLOW_OFF;
if (unlikely((pause < 0) || (pause > 0xffff)))
pause = PAUSE_TIME;
if (eee_timer < 0)
eee_timer = STMMAC_DEFAULT_LPI_TIMER;
}
static void stmmac_disable_all_queues(struct stmmac_priv *priv)
{
u32 rx_queues_cnt = priv->plat->rx_queues_to_use;
u32 queue;
for (queue = 0; queue < rx_queues_cnt; queue++) {
struct stmmac_rx_queue *rx_q = &priv->rx_queue[queue];
napi_disable(&rx_q->napi);
}
}
static void stmmac_enable_all_queues(struct stmmac_priv *priv)
{
u32 rx_queues_cnt = priv->plat->rx_queues_to_use;
u32 queue;
for (queue = 0; queue < rx_queues_cnt; queue++) {
struct stmmac_rx_queue *rx_q = &priv->rx_queue[queue];
napi_enable(&rx_q->napi);
}
}
static void stmmac_stop_all_queues(struct stmmac_priv *priv)
{
u32 tx_queues_cnt = priv->plat->tx_queues_to_use;
u32 queue;
for (queue = 0; queue < tx_queues_cnt; queue++)
netif_tx_stop_queue(netdev_get_tx_queue(priv->dev, queue));
}
static void stmmac_start_all_queues(struct stmmac_priv *priv)
{
u32 tx_queues_cnt = priv->plat->tx_queues_to_use;
u32 queue;
for (queue = 0; queue < tx_queues_cnt; queue++)
netif_tx_start_queue(netdev_get_tx_queue(priv->dev, queue));
}
static void stmmac_clk_csr_set(struct stmmac_priv *priv)
{
u32 clk_rate;
clk_rate = clk_get_rate(priv->plat->stmmac_clk);
if (!(priv->clk_csr & MAC_CSR_H_FRQ_MASK)) {
if (clk_rate < CSR_F_35M)
priv->clk_csr = STMMAC_CSR_20_35M;
else if ((clk_rate >= CSR_F_35M) && (clk_rate < CSR_F_60M))
priv->clk_csr = STMMAC_CSR_35_60M;
else if ((clk_rate >= CSR_F_60M) && (clk_rate < CSR_F_100M))
priv->clk_csr = STMMAC_CSR_60_100M;
else if ((clk_rate >= CSR_F_100M) && (clk_rate < CSR_F_150M))
priv->clk_csr = STMMAC_CSR_100_150M;
else if ((clk_rate >= CSR_F_150M) && (clk_rate < CSR_F_250M))
priv->clk_csr = STMMAC_CSR_150_250M;
else if ((clk_rate >= CSR_F_250M) && (clk_rate < CSR_F_300M))
priv->clk_csr = STMMAC_CSR_250_300M;
}
if (priv->plat->has_sun8i) {
if (clk_rate > 160000000)
priv->clk_csr = 0x03;
else if (clk_rate > 80000000)
priv->clk_csr = 0x02;
else if (clk_rate > 40000000)
priv->clk_csr = 0x01;
else
priv->clk_csr = 0;
}
}
static void print_pkt(unsigned char *buf, int len)
{
pr_debug("len = %d byte, buf addr: 0x%p\n", len, buf);
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET, buf, len);
}
static inline u32 stmmac_tx_avail(struct stmmac_priv *priv, u32 queue)
{
struct stmmac_tx_queue *tx_q = &priv->tx_queue[queue];
u32 avail;
if (tx_q->dirty_tx > tx_q->cur_tx)
avail = tx_q->dirty_tx - tx_q->cur_tx - 1;
else
avail = DMA_TX_SIZE - tx_q->cur_tx + tx_q->dirty_tx - 1;
return avail;
}
static inline u32 stmmac_rx_dirty(struct stmmac_priv *priv, u32 queue)
{
struct stmmac_rx_queue *rx_q = &priv->rx_queue[queue];
u32 dirty;
if (rx_q->dirty_rx <= rx_q->cur_rx)
dirty = rx_q->cur_rx - rx_q->dirty_rx;
else
dirty = DMA_RX_SIZE - rx_q->dirty_rx + rx_q->cur_rx;
return dirty;
}
static inline void stmmac_hw_fix_mac_speed(struct stmmac_priv *priv)
{
struct net_device *ndev = priv->dev;
struct phy_device *phydev = ndev->phydev;
if (likely(priv->plat->fix_mac_speed))
priv->plat->fix_mac_speed(priv->plat->bsp_priv, phydev->speed);
}
static void stmmac_enable_eee_mode(struct stmmac_priv *priv)
{
u32 tx_cnt = priv->plat->tx_queues_to_use;
u32 queue;
for (queue = 0; queue < tx_cnt; queue++) {
struct stmmac_tx_queue *tx_q = &priv->tx_queue[queue];
if (tx_q->dirty_tx != tx_q->cur_tx)
return;
}
if (!priv->tx_path_in_lpi_mode)
priv->hw->mac->set_eee_mode(priv->hw,
priv->plat->en_tx_lpi_clockgating);
}
void stmmac_disable_eee_mode(struct stmmac_priv *priv)
{
priv->hw->mac->reset_eee_mode(priv->hw);
del_timer_sync(&priv->eee_ctrl_timer);
priv->tx_path_in_lpi_mode = false;
}
static void stmmac_eee_ctrl_timer(unsigned long arg)
{
struct stmmac_priv *priv = (struct stmmac_priv *)arg;
stmmac_enable_eee_mode(priv);
mod_timer(&priv->eee_ctrl_timer, STMMAC_LPI_T(eee_timer));
}
bool stmmac_eee_init(struct stmmac_priv *priv)
{
struct net_device *ndev = priv->dev;
unsigned long flags;
bool ret = false;
if ((priv->hw->pcs == STMMAC_PCS_RGMII) ||
(priv->hw->pcs == STMMAC_PCS_TBI) ||
(priv->hw->pcs == STMMAC_PCS_RTBI))
goto out;
if (priv->dma_cap.eee) {
int tx_lpi_timer = priv->tx_lpi_timer;
if (phy_init_eee(ndev->phydev, 1)) {
spin_lock_irqsave(&priv->lock, flags);
if (priv->eee_active) {
netdev_dbg(priv->dev, "disable EEE\n");
del_timer_sync(&priv->eee_ctrl_timer);
priv->hw->mac->set_eee_timer(priv->hw, 0,
tx_lpi_timer);
}
priv->eee_active = 0;
spin_unlock_irqrestore(&priv->lock, flags);
goto out;
}
spin_lock_irqsave(&priv->lock, flags);
if (!priv->eee_active) {
priv->eee_active = 1;
setup_timer(&priv->eee_ctrl_timer,
stmmac_eee_ctrl_timer,
(unsigned long)priv);
mod_timer(&priv->eee_ctrl_timer,
STMMAC_LPI_T(eee_timer));
priv->hw->mac->set_eee_timer(priv->hw,
STMMAC_DEFAULT_LIT_LS,
tx_lpi_timer);
}
priv->hw->mac->set_eee_pls(priv->hw, ndev->phydev->link);
ret = true;
spin_unlock_irqrestore(&priv->lock, flags);
netdev_dbg(priv->dev, "Energy-Efficient Ethernet initialized\n");
}
out:
return ret;
}
static void stmmac_get_tx_hwtstamp(struct stmmac_priv *priv,
struct dma_desc *p, struct sk_buff *skb)
{
struct skb_shared_hwtstamps shhwtstamp;
u64 ns;
if (!priv->hwts_tx_en)
return;
if (likely(!skb || !(skb_shinfo(skb)->tx_flags & SKBTX_IN_PROGRESS)))
return;
if (priv->hw->desc->get_tx_timestamp_status(p)) {
ns = priv->hw->desc->get_timestamp(p, priv->adv_ts);
memset(&shhwtstamp, 0, sizeof(struct skb_shared_hwtstamps));
shhwtstamp.hwtstamp = ns_to_ktime(ns);
netdev_dbg(priv->dev, "get valid TX hw timestamp %llu\n", ns);
skb_tstamp_tx(skb, &shhwtstamp);
}
return;
}
static void stmmac_get_rx_hwtstamp(struct stmmac_priv *priv, struct dma_desc *p,
struct dma_desc *np, struct sk_buff *skb)
{
struct skb_shared_hwtstamps *shhwtstamp = NULL;
u64 ns;
if (!priv->hwts_rx_en)
return;
if (priv->hw->desc->get_rx_timestamp_status(p, priv->adv_ts)) {
if (priv->plat->has_gmac4)
ns = priv->hw->desc->get_timestamp(np, priv->adv_ts);
else
ns = priv->hw->desc->get_timestamp(p, priv->adv_ts);
netdev_dbg(priv->dev, "get valid RX hw timestamp %llu\n", ns);
shhwtstamp = skb_hwtstamps(skb);
memset(shhwtstamp, 0, sizeof(struct skb_shared_hwtstamps));
shhwtstamp->hwtstamp = ns_to_ktime(ns);
} else {
netdev_dbg(priv->dev, "cannot get RX hw timestamp\n");
}
}
static int stmmac_hwtstamp_ioctl(struct net_device *dev, struct ifreq *ifr)
{
struct stmmac_priv *priv = netdev_priv(dev);
struct hwtstamp_config config;
struct timespec64 now;
u64 temp = 0;
u32 ptp_v2 = 0;
u32 tstamp_all = 0;
u32 ptp_over_ipv4_udp = 0;
u32 ptp_over_ipv6_udp = 0;
u32 ptp_over_ethernet = 0;
u32 snap_type_sel = 0;
u32 ts_master_en = 0;
u32 ts_event_en = 0;
u32 value = 0;
u32 sec_inc;
if (!(priv->dma_cap.time_stamp || priv->adv_ts)) {
netdev_alert(priv->dev, "No support for HW time stamping\n");
priv->hwts_tx_en = 0;
priv->hwts_rx_en = 0;
return -EOPNOTSUPP;
}
if (copy_from_user(&config, ifr->ifr_data,
sizeof(struct hwtstamp_config)))
return -EFAULT;
netdev_dbg(priv->dev, "%s config flags:0x%x, tx_type:0x%x, rx_filter:0x%x\n",
__func__, config.flags, config.tx_type, config.rx_filter);
if (config.flags)
return -EINVAL;
if (config.tx_type != HWTSTAMP_TX_OFF &&
config.tx_type != HWTSTAMP_TX_ON)
return -ERANGE;
if (priv->adv_ts) {
switch (config.rx_filter) {
case HWTSTAMP_FILTER_NONE:
config.rx_filter = HWTSTAMP_FILTER_NONE;
break;
case HWTSTAMP_FILTER_PTP_V1_L4_EVENT:
config.rx_filter = HWTSTAMP_FILTER_PTP_V1_L4_EVENT;
if (priv->plat->has_gmac4)
snap_type_sel = PTP_GMAC4_TCR_SNAPTYPSEL_1;
else
snap_type_sel = PTP_TCR_SNAPTYPSEL_1;
ptp_over_ipv4_udp = PTP_TCR_TSIPV4ENA;
ptp_over_ipv6_udp = PTP_TCR_TSIPV6ENA;
break;
case HWTSTAMP_FILTER_PTP_V1_L4_SYNC:
config.rx_filter = HWTSTAMP_FILTER_PTP_V1_L4_SYNC;
ts_event_en = PTP_TCR_TSEVNTENA;
ptp_over_ipv4_udp = PTP_TCR_TSIPV4ENA;
ptp_over_ipv6_udp = PTP_TCR_TSIPV6ENA;
break;
case HWTSTAMP_FILTER_PTP_V1_L4_DELAY_REQ:
config.rx_filter = HWTSTAMP_FILTER_PTP_V1_L4_DELAY_REQ;
ts_master_en = PTP_TCR_TSMSTRENA;
ts_event_en = PTP_TCR_TSEVNTENA;
ptp_over_ipv4_udp = PTP_TCR_TSIPV4ENA;
ptp_over_ipv6_udp = PTP_TCR_TSIPV6ENA;
break;
case HWTSTAMP_FILTER_PTP_V2_L4_EVENT:
config.rx_filter = HWTSTAMP_FILTER_PTP_V2_L4_EVENT;
ptp_v2 = PTP_TCR_TSVER2ENA;
if (priv->plat->has_gmac4)
snap_type_sel = PTP_GMAC4_TCR_SNAPTYPSEL_1;
else
snap_type_sel = PTP_TCR_SNAPTYPSEL_1;
ptp_over_ipv4_udp = PTP_TCR_TSIPV4ENA;
ptp_over_ipv6_udp = PTP_TCR_TSIPV6ENA;
break;
case HWTSTAMP_FILTER_PTP_V2_L4_SYNC:
config.rx_filter = HWTSTAMP_FILTER_PTP_V2_L4_SYNC;
ptp_v2 = PTP_TCR_TSVER2ENA;
ts_event_en = PTP_TCR_TSEVNTENA;
ptp_over_ipv4_udp = PTP_TCR_TSIPV4ENA;
ptp_over_ipv6_udp = PTP_TCR_TSIPV6ENA;
break;
case HWTSTAMP_FILTER_PTP_V2_L4_DELAY_REQ:
config.rx_filter = HWTSTAMP_FILTER_PTP_V2_L4_DELAY_REQ;
ptp_v2 = PTP_TCR_TSVER2ENA;
ts_master_en = PTP_TCR_TSMSTRENA;
ts_event_en = PTP_TCR_TSEVNTENA;
ptp_over_ipv4_udp = PTP_TCR_TSIPV4ENA;
ptp_over_ipv6_udp = PTP_TCR_TSIPV6ENA;
break;
case HWTSTAMP_FILTER_PTP_V2_EVENT:
config.rx_filter = HWTSTAMP_FILTER_PTP_V2_EVENT;
ptp_v2 = PTP_TCR_TSVER2ENA;
if (priv->plat->has_gmac4)
snap_type_sel = PTP_GMAC4_TCR_SNAPTYPSEL_1;
else
snap_type_sel = PTP_TCR_SNAPTYPSEL_1;
ptp_over_ipv4_udp = PTP_TCR_TSIPV4ENA;
ptp_over_ipv6_udp = PTP_TCR_TSIPV6ENA;
ptp_over_ethernet = PTP_TCR_TSIPENA;
break;
case HWTSTAMP_FILTER_PTP_V2_SYNC:
config.rx_filter = HWTSTAMP_FILTER_PTP_V2_SYNC;
ptp_v2 = PTP_TCR_TSVER2ENA;
ts_event_en = PTP_TCR_TSEVNTENA;
ptp_over_ipv4_udp = PTP_TCR_TSIPV4ENA;
ptp_over_ipv6_udp = PTP_TCR_TSIPV6ENA;
ptp_over_ethernet = PTP_TCR_TSIPENA;
break;
case HWTSTAMP_FILTER_PTP_V2_DELAY_REQ:
config.rx_filter = HWTSTAMP_FILTER_PTP_V2_DELAY_REQ;
ptp_v2 = PTP_TCR_TSVER2ENA;
ts_master_en = PTP_TCR_TSMSTRENA;
ts_event_en = PTP_TCR_TSEVNTENA;
ptp_over_ipv4_udp = PTP_TCR_TSIPV4ENA;
ptp_over_ipv6_udp = PTP_TCR_TSIPV6ENA;
ptp_over_ethernet = PTP_TCR_TSIPENA;
break;
case HWTSTAMP_FILTER_NTP_ALL:
case HWTSTAMP_FILTER_ALL:
config.rx_filter = HWTSTAMP_FILTER_ALL;
tstamp_all = PTP_TCR_TSENALL;
break;
default:
return -ERANGE;
}
} else {
switch (config.rx_filter) {
case HWTSTAMP_FILTER_NONE:
config.rx_filter = HWTSTAMP_FILTER_NONE;
break;
default:
config.rx_filter = HWTSTAMP_FILTER_PTP_V1_L4_EVENT;
break;
}
}
priv->hwts_rx_en = ((config.rx_filter == HWTSTAMP_FILTER_NONE) ? 0 : 1);
priv->hwts_tx_en = config.tx_type == HWTSTAMP_TX_ON;
if (!priv->hwts_tx_en && !priv->hwts_rx_en)
priv->hw->ptp->config_hw_tstamping(priv->ptpaddr, 0);
else {
value = (PTP_TCR_TSENA | PTP_TCR_TSCFUPDT | PTP_TCR_TSCTRLSSR |
tstamp_all | ptp_v2 | ptp_over_ethernet |
ptp_over_ipv6_udp | ptp_over_ipv4_udp | ts_event_en |
ts_master_en | snap_type_sel);
priv->hw->ptp->config_hw_tstamping(priv->ptpaddr, value);
sec_inc = priv->hw->ptp->config_sub_second_increment(
priv->ptpaddr, priv->plat->clk_ptp_rate,
priv->plat->has_gmac4);
temp = div_u64(1000000000ULL, sec_inc);
temp = (u64)(temp << 32);
priv->default_addend = div_u64(temp, priv->plat->clk_ptp_rate);
priv->hw->ptp->config_addend(priv->ptpaddr,
priv->default_addend);
ktime_get_real_ts64(&now);
priv->hw->ptp->init_systime(priv->ptpaddr, (u32)now.tv_sec,
now.tv_nsec);
}
return copy_to_user(ifr->ifr_data, &config,
sizeof(struct hwtstamp_config)) ? -EFAULT : 0;
}
static int stmmac_init_ptp(struct stmmac_priv *priv)
{
if (!(priv->dma_cap.time_stamp || priv->dma_cap.atime_stamp))
return -EOPNOTSUPP;
priv->adv_ts = 0;
if (priv->plat->has_gmac4 && priv->dma_cap.atime_stamp)
priv->adv_ts = 1;
else if (priv->extend_desc && priv->dma_cap.atime_stamp)
priv->adv_ts = 1;
if (priv->dma_cap.time_stamp)
netdev_info(priv->dev, "IEEE 1588-2002 Timestamp supported\n");
if (priv->adv_ts)
netdev_info(priv->dev,
"IEEE 1588-2008 Advanced Timestamp supported\n");
priv->hw->ptp = &stmmac_ptp;
priv->hwts_tx_en = 0;
priv->hwts_rx_en = 0;
stmmac_ptp_register(priv);
return 0;
}
static void stmmac_release_ptp(struct stmmac_priv *priv)
{
if (priv->plat->clk_ptp_ref)
clk_disable_unprepare(priv->plat->clk_ptp_ref);
stmmac_ptp_unregister(priv);
}
static void stmmac_mac_flow_ctrl(struct stmmac_priv *priv, u32 duplex)
{
u32 tx_cnt = priv->plat->tx_queues_to_use;
priv->hw->mac->flow_ctrl(priv->hw, duplex, priv->flow_ctrl,
priv->pause, tx_cnt);
}
static void stmmac_adjust_link(struct net_device *dev)
{
struct stmmac_priv *priv = netdev_priv(dev);
struct phy_device *phydev = dev->phydev;
unsigned long flags;
bool new_state = false;
if (!phydev)
return;
spin_lock_irqsave(&priv->lock, flags);
if (phydev->link) {
u32 ctrl = readl(priv->ioaddr + MAC_CTRL_REG);
if (phydev->duplex != priv->oldduplex) {
new_state = true;
if (!phydev->duplex)
ctrl &= ~priv->hw->link.duplex;
else
ctrl |= priv->hw->link.duplex;
priv->oldduplex = phydev->duplex;
}
if (phydev->pause)
stmmac_mac_flow_ctrl(priv, phydev->duplex);
if (phydev->speed != priv->speed) {
new_state = true;
ctrl &= ~priv->hw->link.speed_mask;
switch (phydev->speed) {
case SPEED_1000:
ctrl |= priv->hw->link.speed1000;
break;
case SPEED_100:
ctrl |= priv->hw->link.speed100;
break;
case SPEED_10:
ctrl |= priv->hw->link.speed10;
break;
default:
netif_warn(priv, link, priv->dev,
"broken speed: %d\n", phydev->speed);
phydev->speed = SPEED_UNKNOWN;
break;
}
if (phydev->speed != SPEED_UNKNOWN)
stmmac_hw_fix_mac_speed(priv);
priv->speed = phydev->speed;
}
writel(ctrl, priv->ioaddr + MAC_CTRL_REG);
if (!priv->oldlink) {
new_state = true;
priv->oldlink = true;
}
} else if (priv->oldlink) {
new_state = true;
priv->oldlink = false;
priv->speed = SPEED_UNKNOWN;
priv->oldduplex = DUPLEX_UNKNOWN;
}
if (new_state && netif_msg_link(priv))
phy_print_status(phydev);
spin_unlock_irqrestore(&priv->lock, flags);
if (phydev->is_pseudo_fixed_link)
phydev->irq = PHY_IGNORE_INTERRUPT;
else
priv->eee_enabled = stmmac_eee_init(priv);
}
static void stmmac_check_pcs_mode(struct stmmac_priv *priv)
{
int interface = priv->plat->interface;
if (priv->dma_cap.pcs) {
if ((interface == PHY_INTERFACE_MODE_RGMII) ||
(interface == PHY_INTERFACE_MODE_RGMII_ID) ||
(interface == PHY_INTERFACE_MODE_RGMII_RXID) ||
(interface == PHY_INTERFACE_MODE_RGMII_TXID)) {
netdev_dbg(priv->dev, "PCS RGMII support enabled\n");
priv->hw->pcs = STMMAC_PCS_RGMII;
} else if (interface == PHY_INTERFACE_MODE_SGMII) {
netdev_dbg(priv->dev, "PCS SGMII support enabled\n");
priv->hw->pcs = STMMAC_PCS_SGMII;
}
}
}
static int stmmac_init_phy(struct net_device *dev)
{
struct stmmac_priv *priv = netdev_priv(dev);
struct phy_device *phydev;
char phy_id_fmt[MII_BUS_ID_SIZE + 3];
char bus_id[MII_BUS_ID_SIZE];
int interface = priv->plat->interface;
int max_speed = priv->plat->max_speed;
priv->oldlink = false;
priv->speed = SPEED_UNKNOWN;
priv->oldduplex = DUPLEX_UNKNOWN;
if (priv->plat->phy_node) {
phydev = of_phy_connect(dev, priv->plat->phy_node,
&stmmac_adjust_link, 0, interface);
} else {
snprintf(bus_id, MII_BUS_ID_SIZE, "stmmac-%x",
priv->plat->bus_id);
snprintf(phy_id_fmt, MII_BUS_ID_SIZE + 3, PHY_ID_FMT, bus_id,
priv->plat->phy_addr);
netdev_dbg(priv->dev, "%s: trying to attach to %s\n", __func__,
phy_id_fmt);
phydev = phy_connect(dev, phy_id_fmt, &stmmac_adjust_link,
interface);
}
if (IS_ERR_OR_NULL(phydev)) {
netdev_err(priv->dev, "Could not attach to PHY\n");
if (!phydev)
return -ENODEV;
return PTR_ERR(phydev);
}
if ((interface == PHY_INTERFACE_MODE_MII) ||
(interface == PHY_INTERFACE_MODE_RMII) ||
(max_speed < 1000 && max_speed > 0))
phydev->advertising &= ~(SUPPORTED_1000baseT_Half |
SUPPORTED_1000baseT_Full);
if (!priv->plat->phy_node && phydev->phy_id == 0) {
phy_disconnect(phydev);
return -ENODEV;
}
if (phydev->is_pseudo_fixed_link)
phydev->irq = PHY_POLL;
phy_attached_info(phydev);
return 0;
}
static void stmmac_display_rx_rings(struct stmmac_priv *priv)
{
u32 rx_cnt = priv->plat->rx_queues_to_use;
void *head_rx;
u32 queue;
for (queue = 0; queue < rx_cnt; queue++) {
struct stmmac_rx_queue *rx_q = &priv->rx_queue[queue];
pr_info("\tRX Queue %u rings\n", queue);
if (priv->extend_desc)
head_rx = (void *)rx_q->dma_erx;
else
head_rx = (void *)rx_q->dma_rx;
priv->hw->desc->display_ring(head_rx, DMA_RX_SIZE, true);
}
}
static void stmmac_display_tx_rings(struct stmmac_priv *priv)
{
u32 tx_cnt = priv->plat->tx_queues_to_use;
void *head_tx;
u32 queue;
for (queue = 0; queue < tx_cnt; queue++) {
struct stmmac_tx_queue *tx_q = &priv->tx_queue[queue];
pr_info("\tTX Queue %d rings\n", queue);
if (priv->extend_desc)
head_tx = (void *)tx_q->dma_etx;
else
head_tx = (void *)tx_q->dma_tx;
priv->hw->desc->display_ring(head_tx, DMA_TX_SIZE, false);
}
}
static void stmmac_display_rings(struct stmmac_priv *priv)
{
stmmac_display_rx_rings(priv);
stmmac_display_tx_rings(priv);
}
static int stmmac_set_bfsize(int mtu, int bufsize)
{
int ret = bufsize;
if (mtu >= BUF_SIZE_4KiB)
ret = BUF_SIZE_8KiB;
else if (mtu >= BUF_SIZE_2KiB)
ret = BUF_SIZE_4KiB;
else if (mtu > DEFAULT_BUFSIZE)
ret = BUF_SIZE_2KiB;
else
ret = DEFAULT_BUFSIZE;
return ret;
}
static void stmmac_clear_rx_descriptors(struct stmmac_priv *priv, u32 queue)
{
struct stmmac_rx_queue *rx_q = &priv->rx_queue[queue];
int i;
for (i = 0; i < DMA_RX_SIZE; i++)
if (priv->extend_desc)
priv->hw->desc->init_rx_desc(&rx_q->dma_erx[i].basic,
priv->use_riwt, priv->mode,
(i == DMA_RX_SIZE - 1));
else
priv->hw->desc->init_rx_desc(&rx_q->dma_rx[i],
priv->use_riwt, priv->mode,
(i == DMA_RX_SIZE - 1));
}
static void stmmac_clear_tx_descriptors(struct stmmac_priv *priv, u32 queue)
{
struct stmmac_tx_queue *tx_q = &priv->tx_queue[queue];
int i;
for (i = 0; i < DMA_TX_SIZE; i++)
if (priv->extend_desc)
priv->hw->desc->init_tx_desc(&tx_q->dma_etx[i].basic,
priv->mode,
(i == DMA_TX_SIZE - 1));
else
priv->hw->desc->init_tx_desc(&tx_q->dma_tx[i],
priv->mode,
(i == DMA_TX_SIZE - 1));
}
static void stmmac_clear_descriptors(struct stmmac_priv *priv)
{
u32 rx_queue_cnt = priv->plat->rx_queues_to_use;
u32 tx_queue_cnt = priv->plat->tx_queues_to_use;
u32 queue;
for (queue = 0; queue < rx_queue_cnt; queue++)
stmmac_clear_rx_descriptors(priv, queue);
for (queue = 0; queue < tx_queue_cnt; queue++)
stmmac_clear_tx_descriptors(priv, queue);
}
static int stmmac_init_rx_buffers(struct stmmac_priv *priv, struct dma_desc *p,
int i, gfp_t flags, u32 queue)
{
struct stmmac_rx_queue *rx_q = &priv->rx_queue[queue];
struct sk_buff *skb;
skb = __netdev_alloc_skb_ip_align(priv->dev, priv->dma_buf_sz, flags);
if (!skb) {
netdev_err(priv->dev,
"%s: Rx init fails; skb is NULL\n", __func__);
return -ENOMEM;
}
rx_q->rx_skbuff[i] = skb;
rx_q->rx_skbuff_dma[i] = dma_map_single(priv->device, skb->data,
priv->dma_buf_sz,
DMA_FROM_DEVICE);
if (dma_mapping_error(priv->device, rx_q->rx_skbuff_dma[i])) {
netdev_err(priv->dev, "%s: DMA mapping error\n", __func__);
dev_kfree_skb_any(skb);
return -EINVAL;
}
if (priv->synopsys_id >= DWMAC_CORE_4_00)
p->des0 = cpu_to_le32(rx_q->rx_skbuff_dma[i]);
else
p->des2 = cpu_to_le32(rx_q->rx_skbuff_dma[i]);
if ((priv->hw->mode->init_desc3) &&
(priv->dma_buf_sz == BUF_SIZE_16KiB))
priv->hw->mode->init_desc3(p);
return 0;
}
static void stmmac_free_rx_buffer(struct stmmac_priv *priv, u32 queue, int i)
{
struct stmmac_rx_queue *rx_q = &priv->rx_queue[queue];
if (rx_q->rx_skbuff[i]) {
dma_unmap_single(priv->device, rx_q->rx_skbuff_dma[i],
priv->dma_buf_sz, DMA_FROM_DEVICE);
dev_kfree_skb_any(rx_q->rx_skbuff[i]);
}
rx_q->rx_skbuff[i] = NULL;
}
static void stmmac_free_tx_buffer(struct stmmac_priv *priv, u32 queue, int i)
{
struct stmmac_tx_queue *tx_q = &priv->tx_queue[queue];
if (tx_q->tx_skbuff_dma[i].buf) {
if (tx_q->tx_skbuff_dma[i].map_as_page)
dma_unmap_page(priv->device,
tx_q->tx_skbuff_dma[i].buf,
tx_q->tx_skbuff_dma[i].len,
DMA_TO_DEVICE);
else
dma_unmap_single(priv->device,
tx_q->tx_skbuff_dma[i].buf,
tx_q->tx_skbuff_dma[i].len,
DMA_TO_DEVICE);
}
if (tx_q->tx_skbuff[i]) {
dev_kfree_skb_any(tx_q->tx_skbuff[i]);
tx_q->tx_skbuff[i] = NULL;
tx_q->tx_skbuff_dma[i].buf = 0;
tx_q->tx_skbuff_dma[i].map_as_page = false;
}
}
static int init_dma_rx_desc_rings(struct net_device *dev, gfp_t flags)
{
struct stmmac_priv *priv = netdev_priv(dev);
u32 rx_count = priv->plat->rx_queues_to_use;
unsigned int bfsize = 0;
int ret = -ENOMEM;
int queue;
int i;
if (priv->hw->mode->set_16kib_bfsize)
bfsize = priv->hw->mode->set_16kib_bfsize(dev->mtu);
if (bfsize < BUF_SIZE_16KiB)
bfsize = stmmac_set_bfsize(dev->mtu, priv->dma_buf_sz);
priv->dma_buf_sz = bfsize;
netif_dbg(priv, probe, priv->dev,
"SKB addresses:\nskb\t\tskb data\tdma data\n");
for (queue = 0; queue < rx_count; queue++) {
struct stmmac_rx_queue *rx_q = &priv->rx_queue[queue];
netif_dbg(priv, probe, priv->dev,
"(%s) dma_rx_phy=0x%08x\n", __func__,
(u32)rx_q->dma_rx_phy);
for (i = 0; i < DMA_RX_SIZE; i++) {
struct dma_desc *p;
if (priv->extend_desc)
p = &((rx_q->dma_erx + i)->basic);
else
p = rx_q->dma_rx + i;
ret = stmmac_init_rx_buffers(priv, p, i, flags,
queue);
if (ret)
goto err_init_rx_buffers;
netif_dbg(priv, probe, priv->dev, "[%p]\t[%p]\t[%x]\n",
rx_q->rx_skbuff[i], rx_q->rx_skbuff[i]->data,
(unsigned int)rx_q->rx_skbuff_dma[i]);
}
rx_q->cur_rx = 0;
rx_q->dirty_rx = (unsigned int)(i - DMA_RX_SIZE);
stmmac_clear_rx_descriptors(priv, queue);
if (priv->mode == STMMAC_CHAIN_MODE) {
if (priv->extend_desc)
priv->hw->mode->init(rx_q->dma_erx,
rx_q->dma_rx_phy,
DMA_RX_SIZE, 1);
else
priv->hw->mode->init(rx_q->dma_rx,
rx_q->dma_rx_phy,
DMA_RX_SIZE, 0);
}
}
buf_sz = bfsize;
return 0;
err_init_rx_buffers:
while (queue >= 0) {
while (--i >= 0)
stmmac_free_rx_buffer(priv, queue, i);
if (queue == 0)
break;
i = DMA_RX_SIZE;
queue--;
}
return ret;
}
static int init_dma_tx_desc_rings(struct net_device *dev)
{
struct stmmac_priv *priv = netdev_priv(dev);
u32 tx_queue_cnt = priv->plat->tx_queues_to_use;
u32 queue;
int i;
for (queue = 0; queue < tx_queue_cnt; queue++) {
struct stmmac_tx_queue *tx_q = &priv->tx_queue[queue];
netif_dbg(priv, probe, priv->dev,
"(%s) dma_tx_phy=0x%08x\n", __func__,
(u32)tx_q->dma_tx_phy);
if (priv->mode == STMMAC_CHAIN_MODE) {
if (priv->extend_desc)
priv->hw->mode->init(tx_q->dma_etx,
tx_q->dma_tx_phy,
DMA_TX_SIZE, 1);
else
priv->hw->mode->init(tx_q->dma_tx,
tx_q->dma_tx_phy,
DMA_TX_SIZE, 0);
}
for (i = 0; i < DMA_TX_SIZE; i++) {
struct dma_desc *p;
if (priv->extend_desc)
p = &((tx_q->dma_etx + i)->basic);
else
p = tx_q->dma_tx + i;
if (priv->synopsys_id >= DWMAC_CORE_4_00) {
p->des0 = 0;
p->des1 = 0;
p->des2 = 0;
p->des3 = 0;
} else {
p->des2 = 0;
}
tx_q->tx_skbuff_dma[i].buf = 0;
tx_q->tx_skbuff_dma[i].map_as_page = false;
tx_q->tx_skbuff_dma[i].len = 0;
tx_q->tx_skbuff_dma[i].last_segment = false;
tx_q->tx_skbuff[i] = NULL;
}
tx_q->dirty_tx = 0;
tx_q->cur_tx = 0;
netdev_tx_reset_queue(netdev_get_tx_queue(priv->dev, queue));
}
return 0;
}
static int init_dma_desc_rings(struct net_device *dev, gfp_t flags)
{
struct stmmac_priv *priv = netdev_priv(dev);
int ret;
ret = init_dma_rx_desc_rings(dev, flags);
if (ret)
return ret;
ret = init_dma_tx_desc_rings(dev);
stmmac_clear_descriptors(priv);
if (netif_msg_hw(priv))
stmmac_display_rings(priv);
return ret;
}
static void dma_free_rx_skbufs(struct stmmac_priv *priv, u32 queue)
{
int i;
for (i = 0; i < DMA_RX_SIZE; i++)
stmmac_free_rx_buffer(priv, queue, i);
}
static void dma_free_tx_skbufs(struct stmmac_priv *priv, u32 queue)
{
int i;
for (i = 0; i < DMA_TX_SIZE; i++)
stmmac_free_tx_buffer(priv, queue, i);
}
static void free_dma_rx_desc_resources(struct stmmac_priv *priv)
{
u32 rx_count = priv->plat->rx_queues_to_use;
u32 queue;
for (queue = 0; queue < rx_count; queue++) {
struct stmmac_rx_queue *rx_q = &priv->rx_queue[queue];
dma_free_rx_skbufs(priv, queue);
if (!priv->extend_desc)
dma_free_coherent(priv->device,
DMA_RX_SIZE * sizeof(struct dma_desc),
rx_q->dma_rx, rx_q->dma_rx_phy);
else
dma_free_coherent(priv->device, DMA_RX_SIZE *
sizeof(struct dma_extended_desc),
rx_q->dma_erx, rx_q->dma_rx_phy);
kfree(rx_q->rx_skbuff_dma);
kfree(rx_q->rx_skbuff);
}
}
static void free_dma_tx_desc_resources(struct stmmac_priv *priv)
{
u32 tx_count = priv->plat->tx_queues_to_use;
u32 queue;
for (queue = 0; queue < tx_count; queue++) {
struct stmmac_tx_queue *tx_q = &priv->tx_queue[queue];
dma_free_tx_skbufs(priv, queue);
if (!priv->extend_desc)
dma_free_coherent(priv->device,
DMA_TX_SIZE * sizeof(struct dma_desc),
tx_q->dma_tx, tx_q->dma_tx_phy);
else
dma_free_coherent(priv->device, DMA_TX_SIZE *
sizeof(struct dma_extended_desc),
tx_q->dma_etx, tx_q->dma_tx_phy);
kfree(tx_q->tx_skbuff_dma);
kfree(tx_q->tx_skbuff);
}
}
static int alloc_dma_rx_desc_resources(struct stmmac_priv *priv)
{
u32 rx_count = priv->plat->rx_queues_to_use;
int ret = -ENOMEM;
u32 queue;
for (queue = 0; queue < rx_count; queue++) {
struct stmmac_rx_queue *rx_q = &priv->rx_queue[queue];
rx_q->queue_index = queue;
rx_q->priv_data = priv;
rx_q->rx_skbuff_dma = kmalloc_array(DMA_RX_SIZE,
sizeof(dma_addr_t),
GFP_KERNEL);
if (!rx_q->rx_skbuff_dma)
goto err_dma;
rx_q->rx_skbuff = kmalloc_array(DMA_RX_SIZE,
sizeof(struct sk_buff *),
GFP_KERNEL);
if (!rx_q->rx_skbuff)
goto err_dma;
if (priv->extend_desc) {
rx_q->dma_erx = dma_zalloc_coherent(priv->device,
DMA_RX_SIZE *
sizeof(struct
dma_extended_desc),
&rx_q->dma_rx_phy,
GFP_KERNEL);
if (!rx_q->dma_erx)
goto err_dma;
} else {
rx_q->dma_rx = dma_zalloc_coherent(priv->device,
DMA_RX_SIZE *
sizeof(struct
dma_desc),
&rx_q->dma_rx_phy,
GFP_KERNEL);
if (!rx_q->dma_rx)
goto err_dma;
}
}
return 0;
err_dma:
free_dma_rx_desc_resources(priv);
return ret;
}
static int alloc_dma_tx_desc_resources(struct stmmac_priv *priv)
{
u32 tx_count = priv->plat->tx_queues_to_use;
int ret = -ENOMEM;
u32 queue;
for (queue = 0; queue < tx_count; queue++) {
struct stmmac_tx_queue *tx_q = &priv->tx_queue[queue];
tx_q->queue_index = queue;
tx_q->priv_data = priv;
tx_q->tx_skbuff_dma = kmalloc_array(DMA_TX_SIZE,
sizeof(*tx_q->tx_skbuff_dma),
GFP_KERNEL);
if (!tx_q->tx_skbuff_dma)
goto err_dma;
tx_q->tx_skbuff = kmalloc_array(DMA_TX_SIZE,
sizeof(struct sk_buff *),
GFP_KERNEL);
if (!tx_q->tx_skbuff)
goto err_dma;
if (priv->extend_desc) {
tx_q->dma_etx = dma_zalloc_coherent(priv->device,
DMA_TX_SIZE *
sizeof(struct
dma_extended_desc),
&tx_q->dma_tx_phy,
GFP_KERNEL);
if (!tx_q->dma_etx)
goto err_dma;
} else {
tx_q->dma_tx = dma_zalloc_coherent(priv->device,
DMA_TX_SIZE *
sizeof(struct
dma_desc),
&tx_q->dma_tx_phy,
GFP_KERNEL);
if (!tx_q->dma_tx)
goto err_dma;
}
}
return 0;
err_dma:
free_dma_tx_desc_resources(priv);
return ret;
}
static int alloc_dma_desc_resources(struct stmmac_priv *priv)
{
int ret = alloc_dma_rx_desc_resources(priv);
if (ret)
return ret;
ret = alloc_dma_tx_desc_resources(priv);
return ret;
}
static void free_dma_desc_resources(struct stmmac_priv *priv)
{
free_dma_rx_desc_resources(priv);
free_dma_tx_desc_resources(priv);
}
static void stmmac_mac_enable_rx_queues(struct stmmac_priv *priv)
{
u32 rx_queues_count = priv->plat->rx_queues_to_use;
int queue;
u8 mode;
for (queue = 0; queue < rx_queues_count; queue++) {
mode = priv->plat->rx_queues_cfg[queue].mode_to_use;
priv->hw->mac->rx_queue_enable(priv->hw, mode, queue);
}
}
static void stmmac_start_rx_dma(struct stmmac_priv *priv, u32 chan)
{
netdev_dbg(priv->dev, "DMA RX processes started in channel %d\n", chan);
priv->hw->dma->start_rx(priv->ioaddr, chan);
}
static void stmmac_start_tx_dma(struct stmmac_priv *priv, u32 chan)
{
netdev_dbg(priv->dev, "DMA TX processes started in channel %d\n", chan);
priv->hw->dma->start_tx(priv->ioaddr, chan);
}
static void stmmac_stop_rx_dma(struct stmmac_priv *priv, u32 chan)
{
netdev_dbg(priv->dev, "DMA RX processes stopped in channel %d\n", chan);
priv->hw->dma->stop_rx(priv->ioaddr, chan);
}
static void stmmac_stop_tx_dma(struct stmmac_priv *priv, u32 chan)
{
netdev_dbg(priv->dev, "DMA TX processes stopped in channel %d\n", chan);
priv->hw->dma->stop_tx(priv->ioaddr, chan);
}
static void stmmac_start_all_dma(struct stmmac_priv *priv)
{
u32 rx_channels_count = priv->plat->rx_queues_to_use;
u32 tx_channels_count = priv->plat->tx_queues_to_use;
u32 chan = 0;
for (chan = 0; chan < rx_channels_count; chan++)
stmmac_start_rx_dma(priv, chan);
for (chan = 0; chan < tx_channels_count; chan++)
stmmac_start_tx_dma(priv, chan);
}
static void stmmac_stop_all_dma(struct stmmac_priv *priv)
{
u32 rx_channels_count = priv->plat->rx_queues_to_use;
u32 tx_channels_count = priv->plat->tx_queues_to_use;
u32 chan = 0;
for (chan = 0; chan < rx_channels_count; chan++)
stmmac_stop_rx_dma(priv, chan);
for (chan = 0; chan < tx_channels_count; chan++)
stmmac_stop_tx_dma(priv, chan);
}
static void stmmac_dma_operation_mode(struct stmmac_priv *priv)
{
u32 rx_channels_count = priv->plat->rx_queues_to_use;
u32 tx_channels_count = priv->plat->tx_queues_to_use;
int rxfifosz = priv->plat->rx_fifo_size;
u32 txmode = 0;
u32 rxmode = 0;
u32 chan = 0;
if (rxfifosz == 0)
rxfifosz = priv->dma_cap.rx_fifo_size;
if (priv->plat->force_thresh_dma_mode) {
txmode = tc;
rxmode = tc;
} else if (priv->plat->force_sf_dma_mode || priv->plat->tx_coe) {
txmode = SF_DMA_MODE;
rxmode = SF_DMA_MODE;
priv->xstats.threshold = SF_DMA_MODE;
} else {
txmode = tc;
rxmode = SF_DMA_MODE;
}
if (priv->synopsys_id >= DWMAC_CORE_4_00) {
for (chan = 0; chan < rx_channels_count; chan++)
priv->hw->dma->dma_rx_mode(priv->ioaddr, rxmode, chan,
rxfifosz);
for (chan = 0; chan < tx_channels_count; chan++)
priv->hw->dma->dma_tx_mode(priv->ioaddr, txmode, chan);
} else {
priv->hw->dma->dma_mode(priv->ioaddr, txmode, rxmode,
rxfifosz);
}
}
static void stmmac_tx_clean(struct stmmac_priv *priv, u32 queue)
{
struct stmmac_tx_queue *tx_q = &priv->tx_queue[queue];
unsigned int bytes_compl = 0, pkts_compl = 0;
unsigned int entry = tx_q->dirty_tx;
netif_tx_lock(priv->dev);
priv->xstats.tx_clean++;
while (entry != tx_q->cur_tx) {
struct sk_buff *skb = tx_q->tx_skbuff[entry];
struct dma_desc *p;
int status;
if (priv->extend_desc)
p = (struct dma_desc *)(tx_q->dma_etx + entry);
else
p = tx_q->dma_tx + entry;
status = priv->hw->desc->tx_status(&priv->dev->stats,
&priv->xstats, p,
priv->ioaddr);
if (unlikely(status & tx_dma_own))
break;
if (likely(!(status & tx_not_ls))) {
if (unlikely(status & tx_err)) {
priv->dev->stats.tx_errors++;
} else {
priv->dev->stats.tx_packets++;
priv->xstats.tx_pkt_n++;
}
stmmac_get_tx_hwtstamp(priv, p, skb);
}
if (likely(tx_q->tx_skbuff_dma[entry].buf)) {
if (tx_q->tx_skbuff_dma[entry].map_as_page)
dma_unmap_page(priv->device,
tx_q->tx_skbuff_dma[entry].buf,
tx_q->tx_skbuff_dma[entry].len,
DMA_TO_DEVICE);
else
dma_unmap_single(priv->device,
tx_q->tx_skbuff_dma[entry].buf,
tx_q->tx_skbuff_dma[entry].len,
DMA_TO_DEVICE);
tx_q->tx_skbuff_dma[entry].buf = 0;
tx_q->tx_skbuff_dma[entry].len = 0;
tx_q->tx_skbuff_dma[entry].map_as_page = false;
}
if (priv->hw->mode->clean_desc3)
priv->hw->mode->clean_desc3(tx_q, p);
tx_q->tx_skbuff_dma[entry].last_segment = false;
tx_q->tx_skbuff_dma[entry].is_jumbo = false;
if (likely(skb != NULL)) {
pkts_compl++;
bytes_compl += skb->len;
dev_consume_skb_any(skb);
tx_q->tx_skbuff[entry] = NULL;
}
priv->hw->desc->release_tx_desc(p, priv->mode);
entry = STMMAC_GET_ENTRY(entry, DMA_TX_SIZE);
}
tx_q->dirty_tx = entry;
netdev_tx_completed_queue(netdev_get_tx_queue(priv->dev, queue),
pkts_compl, bytes_compl);
if (unlikely(netif_tx_queue_stopped(netdev_get_tx_queue(priv->dev,
queue))) &&
stmmac_tx_avail(priv, queue) > STMMAC_TX_THRESH) {
netif_dbg(priv, tx_done, priv->dev,
"%s: restart transmit\n", __func__);
netif_tx_wake_queue(netdev_get_tx_queue(priv->dev, queue));
}
if ((priv->eee_enabled) && (!priv->tx_path_in_lpi_mode)) {
stmmac_enable_eee_mode(priv);
mod_timer(&priv->eee_ctrl_timer, STMMAC_LPI_T(eee_timer));
}
netif_tx_unlock(priv->dev);
}
static inline void stmmac_enable_dma_irq(struct stmmac_priv *priv, u32 chan)
{
priv->hw->dma->enable_dma_irq(priv->ioaddr, chan);
}
static inline void stmmac_disable_dma_irq(struct stmmac_priv *priv, u32 chan)
{
priv->hw->dma->disable_dma_irq(priv->ioaddr, chan);
}
static void stmmac_tx_err(struct stmmac_priv *priv, u32 chan)
{
struct stmmac_tx_queue *tx_q = &priv->tx_queue[chan];
int i;
netif_tx_stop_queue(netdev_get_tx_queue(priv->dev, chan));
stmmac_stop_tx_dma(priv, chan);
dma_free_tx_skbufs(priv, chan);
for (i = 0; i < DMA_TX_SIZE; i++)
if (priv->extend_desc)
priv->hw->desc->init_tx_desc(&tx_q->dma_etx[i].basic,
priv->mode,
(i == DMA_TX_SIZE - 1));
else
priv->hw->desc->init_tx_desc(&tx_q->dma_tx[i],
priv->mode,
(i == DMA_TX_SIZE - 1));
tx_q->dirty_tx = 0;
tx_q->cur_tx = 0;
netdev_tx_reset_queue(netdev_get_tx_queue(priv->dev, chan));
stmmac_start_tx_dma(priv, chan);
priv->dev->stats.tx_errors++;
netif_tx_wake_queue(netdev_get_tx_queue(priv->dev, chan));
}
static void stmmac_set_dma_operation_mode(struct stmmac_priv *priv, u32 txmode,
u32 rxmode, u32 chan)
{
int rxfifosz = priv->plat->rx_fifo_size;
if (rxfifosz == 0)
rxfifosz = priv->dma_cap.rx_fifo_size;
if (priv->synopsys_id >= DWMAC_CORE_4_00) {
priv->hw->dma->dma_rx_mode(priv->ioaddr, rxmode, chan,
rxfifosz);
priv->hw->dma->dma_tx_mode(priv->ioaddr, txmode, chan);
} else {
priv->hw->dma->dma_mode(priv->ioaddr, txmode, rxmode,
rxfifosz);
}
}
static void stmmac_dma_interrupt(struct stmmac_priv *priv)
{
u32 tx_channel_count = priv->plat->tx_queues_to_use;
int status;
u32 chan;
for (chan = 0; chan < tx_channel_count; chan++) {
struct stmmac_rx_queue *rx_q = &priv->rx_queue[chan];
status = priv->hw->dma->dma_interrupt(priv->ioaddr,
&priv->xstats, chan);
if (likely((status & handle_rx)) || (status & handle_tx)) {
if (likely(napi_schedule_prep(&rx_q->napi))) {
stmmac_disable_dma_irq(priv, chan);
__napi_schedule(&rx_q->napi);
}
}
if (unlikely(status & tx_hard_error_bump_tc)) {
if (unlikely(priv->xstats.threshold != SF_DMA_MODE) &&
(tc <= 256)) {
tc += 64;
if (priv->plat->force_thresh_dma_mode)
stmmac_set_dma_operation_mode(priv,
tc,
tc,
chan);
else
stmmac_set_dma_operation_mode(priv,
tc,
SF_DMA_MODE,
chan);
priv->xstats.threshold = tc;
}
} else if (unlikely(status == tx_hard_error)) {
stmmac_tx_err(priv, chan);
}
}
}
static void stmmac_mmc_setup(struct stmmac_priv *priv)
{
unsigned int mode = MMC_CNTRL_RESET_ON_READ | MMC_CNTRL_COUNTER_RESET |
MMC_CNTRL_PRESET | MMC_CNTRL_FULL_HALF_PRESET;
if (priv->synopsys_id >= DWMAC_CORE_4_00) {
priv->ptpaddr = priv->ioaddr + PTP_GMAC4_OFFSET;
priv->mmcaddr = priv->ioaddr + MMC_GMAC4_OFFSET;
} else {
priv->ptpaddr = priv->ioaddr + PTP_GMAC3_X_OFFSET;
priv->mmcaddr = priv->ioaddr + MMC_GMAC3_X_OFFSET;
}
dwmac_mmc_intr_all_mask(priv->mmcaddr);
if (priv->dma_cap.rmon) {
dwmac_mmc_ctrl(priv->mmcaddr, mode);
memset(&priv->mmc, 0, sizeof(struct stmmac_counters));
} else
netdev_info(priv->dev, "No MAC Management Counters available\n");
}
static void stmmac_selec_desc_mode(struct stmmac_priv *priv)
{
if (priv->plat->enh_desc) {
dev_info(priv->device, "Enhanced/Alternate descriptors\n");
if (priv->synopsys_id >= DWMAC_CORE_3_50) {
dev_info(priv->device, "Enabled extended descriptors\n");
priv->extend_desc = 1;
} else
dev_warn(priv->device, "Extended descriptors not supported\n");
priv->hw->desc = &enh_desc_ops;
} else {
dev_info(priv->device, "Normal descriptors\n");
priv->hw->desc = &ndesc_ops;
}
}
static int stmmac_get_hw_features(struct stmmac_priv *priv)
{
u32 ret = 0;
if (priv->hw->dma->get_hw_feature) {
priv->hw->dma->get_hw_feature(priv->ioaddr,
&priv->dma_cap);
ret = 1;
}
return ret;
}
static void stmmac_check_ether_addr(struct stmmac_priv *priv)
{
if (!is_valid_ether_addr(priv->dev->dev_addr)) {
priv->hw->mac->get_umac_addr(priv->hw,
priv->dev->dev_addr, 0);
if (!is_valid_ether_addr(priv->dev->dev_addr))
eth_hw_addr_random(priv->dev);
netdev_info(priv->dev, "device MAC address %pM\n",
priv->dev->dev_addr);
}
}
static int stmmac_init_dma_engine(struct stmmac_priv *priv)
{
u32 rx_channels_count = priv->plat->rx_queues_to_use;
u32 tx_channels_count = priv->plat->tx_queues_to_use;
struct stmmac_rx_queue *rx_q;
struct stmmac_tx_queue *tx_q;
u32 dummy_dma_rx_phy = 0;
u32 dummy_dma_tx_phy = 0;
u32 chan = 0;
int atds = 0;
int ret = 0;
if (!priv->plat->dma_cfg || !priv->plat->dma_cfg->pbl) {
dev_err(priv->device, "Invalid DMA configuration\n");
return -EINVAL;
}
if (priv->extend_desc && (priv->mode == STMMAC_RING_MODE))
atds = 1;
ret = priv->hw->dma->reset(priv->ioaddr);
if (ret) {
dev_err(priv->device, "Failed to reset the dma\n");
return ret;
}
if (priv->synopsys_id >= DWMAC_CORE_4_00) {
priv->hw->dma->init(priv->ioaddr, priv->plat->dma_cfg,
dummy_dma_tx_phy, dummy_dma_rx_phy, atds);
for (chan = 0; chan < rx_channels_count; chan++) {
rx_q = &priv->rx_queue[chan];
priv->hw->dma->init_rx_chan(priv->ioaddr,
priv->plat->dma_cfg,
rx_q->dma_rx_phy, chan);
rx_q->rx_tail_addr = rx_q->dma_rx_phy +
(DMA_RX_SIZE * sizeof(struct dma_desc));
priv->hw->dma->set_rx_tail_ptr(priv->ioaddr,
rx_q->rx_tail_addr,
chan);
}
for (chan = 0; chan < tx_channels_count; chan++) {
tx_q = &priv->tx_queue[chan];
priv->hw->dma->init_chan(priv->ioaddr,
priv->plat->dma_cfg,
chan);
priv->hw->dma->init_tx_chan(priv->ioaddr,
priv->plat->dma_cfg,
tx_q->dma_tx_phy, chan);
tx_q->tx_tail_addr = tx_q->dma_tx_phy +
(DMA_TX_SIZE * sizeof(struct dma_desc));
priv->hw->dma->set_tx_tail_ptr(priv->ioaddr,
tx_q->tx_tail_addr,
chan);
}
} else {
rx_q = &priv->rx_queue[chan];
tx_q = &priv->tx_queue[chan];
priv->hw->dma->init(priv->ioaddr, priv->plat->dma_cfg,
tx_q->dma_tx_phy, rx_q->dma_rx_phy, atds);
}
if (priv->plat->axi && priv->hw->dma->axi)
priv->hw->dma->axi(priv->ioaddr, priv->plat->axi);
return ret;
}
static void stmmac_tx_timer(unsigned long data)
{
struct stmmac_priv *priv = (struct stmmac_priv *)data;
u32 tx_queues_count = priv->plat->tx_queues_to_use;
u32 queue;
for (queue = 0; queue < tx_queues_count; queue++)
stmmac_tx_clean(priv, queue);
}
static void stmmac_init_tx_coalesce(struct stmmac_priv *priv)
{
priv->tx_coal_frames = STMMAC_TX_FRAMES;
priv->tx_coal_timer = STMMAC_COAL_TX_TIMER;
init_timer(&priv->txtimer);
priv->txtimer.expires = STMMAC_COAL_TIMER(priv->tx_coal_timer);
priv->txtimer.data = (unsigned long)priv;
priv->txtimer.function = stmmac_tx_timer;
add_timer(&priv->txtimer);
}
static void stmmac_set_rings_length(struct stmmac_priv *priv)
{
u32 rx_channels_count = priv->plat->rx_queues_to_use;
u32 tx_channels_count = priv->plat->tx_queues_to_use;
u32 chan;
if (priv->hw->dma->set_tx_ring_len) {
for (chan = 0; chan < tx_channels_count; chan++)
priv->hw->dma->set_tx_ring_len(priv->ioaddr,
(DMA_TX_SIZE - 1), chan);
}
if (priv->hw->dma->set_rx_ring_len) {
for (chan = 0; chan < rx_channels_count; chan++)
priv->hw->dma->set_rx_ring_len(priv->ioaddr,
(DMA_RX_SIZE - 1), chan);
}
}
static void stmmac_set_tx_queue_weight(struct stmmac_priv *priv)
{
u32 tx_queues_count = priv->plat->tx_queues_to_use;
u32 weight;
u32 queue;
for (queue = 0; queue < tx_queues_count; queue++) {
weight = priv->plat->tx_queues_cfg[queue].weight;
priv->hw->mac->set_mtl_tx_queue_weight(priv->hw, weight, queue);
}
}
static void stmmac_configure_cbs(struct stmmac_priv *priv)
{
u32 tx_queues_count = priv->plat->tx_queues_to_use;
u32 mode_to_use;
u32 queue;
for (queue = 1; queue < tx_queues_count; queue++) {
mode_to_use = priv->plat->tx_queues_cfg[queue].mode_to_use;
if (mode_to_use == MTL_QUEUE_DCB)
continue;
priv->hw->mac->config_cbs(priv->hw,
priv->plat->tx_queues_cfg[queue].send_slope,
priv->plat->tx_queues_cfg[queue].idle_slope,
priv->plat->tx_queues_cfg[queue].high_credit,
priv->plat->tx_queues_cfg[queue].low_credit,
queue);
}
}
static void stmmac_rx_queue_dma_chan_map(struct stmmac_priv *priv)
{
u32 rx_queues_count = priv->plat->rx_queues_to_use;
u32 queue;
u32 chan;
for (queue = 0; queue < rx_queues_count; queue++) {
chan = priv->plat->rx_queues_cfg[queue].chan;
priv->hw->mac->map_mtl_to_dma(priv->hw, queue, chan);
}
}
static void stmmac_mac_config_rx_queues_prio(struct stmmac_priv *priv)
{
u32 rx_queues_count = priv->plat->rx_queues_to_use;
u32 queue;
u32 prio;
for (queue = 0; queue < rx_queues_count; queue++) {
if (!priv->plat->rx_queues_cfg[queue].use_prio)
continue;
prio = priv->plat->rx_queues_cfg[queue].prio;
priv->hw->mac->rx_queue_prio(priv->hw, prio, queue);
}
}
static void stmmac_mac_config_tx_queues_prio(struct stmmac_priv *priv)
{
u32 tx_queues_count = priv->plat->tx_queues_to_use;
u32 queue;
u32 prio;
for (queue = 0; queue < tx_queues_count; queue++) {
if (!priv->plat->tx_queues_cfg[queue].use_prio)
continue;
prio = priv->plat->tx_queues_cfg[queue].prio;
priv->hw->mac->tx_queue_prio(priv->hw, prio, queue);
}
}
static void stmmac_mac_config_rx_queues_routing(struct stmmac_priv *priv)
{
u32 rx_queues_count = priv->plat->rx_queues_to_use;
u32 queue;
u8 packet;
for (queue = 0; queue < rx_queues_count; queue++) {
if (priv->plat->rx_queues_cfg[queue].pkt_route == 0x0)
continue;
packet = priv->plat->rx_queues_cfg[queue].pkt_route;
priv->hw->mac->rx_queue_prio(priv->hw, packet, queue);
}
}
static void stmmac_mtl_configuration(struct stmmac_priv *priv)
{
u32 rx_queues_count = priv->plat->rx_queues_to_use;
u32 tx_queues_count = priv->plat->tx_queues_to_use;
if (tx_queues_count > 1 && priv->hw->mac->set_mtl_tx_queue_weight)
stmmac_set_tx_queue_weight(priv);
if (rx_queues_count > 1 && priv->hw->mac->prog_mtl_rx_algorithms)
priv->hw->mac->prog_mtl_rx_algorithms(priv->hw,
priv->plat->rx_sched_algorithm);
if (tx_queues_count > 1 && priv->hw->mac->prog_mtl_tx_algorithms)
priv->hw->mac->prog_mtl_tx_algorithms(priv->hw,
priv->plat->tx_sched_algorithm);
if (tx_queues_count > 1 && priv->hw->mac->config_cbs)
stmmac_configure_cbs(priv);
if (priv->hw->mac->map_mtl_to_dma)
stmmac_rx_queue_dma_chan_map(priv);
if (priv->hw->mac->rx_queue_enable)
stmmac_mac_enable_rx_queues(priv);
if (rx_queues_count > 1 && priv->hw->mac->rx_queue_prio)
stmmac_mac_config_rx_queues_prio(priv);
if (tx_queues_count > 1 && priv->hw->mac->tx_queue_prio)
stmmac_mac_config_tx_queues_prio(priv);
if (rx_queues_count > 1 && priv->hw->mac->rx_queue_routing)
stmmac_mac_config_rx_queues_routing(priv);
}
static int stmmac_hw_setup(struct net_device *dev, bool init_ptp)
{
struct stmmac_priv *priv = netdev_priv(dev);
u32 rx_cnt = priv->plat->rx_queues_to_use;
u32 tx_cnt = priv->plat->tx_queues_to_use;
u32 chan;
int ret;
ret = stmmac_init_dma_engine(priv);
if (ret < 0) {
netdev_err(priv->dev, "%s: DMA engine initialization failed\n",
__func__);
return ret;
}
priv->hw->mac->set_umac_addr(priv->hw, dev->dev_addr, 0);
if (priv->hw->pcs) {
int speed = priv->plat->mac_port_sel_speed;
if ((speed == SPEED_10) || (speed == SPEED_100) ||
(speed == SPEED_1000)) {
priv->hw->ps = speed;
} else {
dev_warn(priv->device, "invalid port speed\n");
priv->hw->ps = 0;
}
}
priv->hw->mac->core_init(priv->hw, dev->mtu);
if (priv->synopsys_id >= DWMAC_CORE_4_00)
stmmac_mtl_configuration(priv);
ret = priv->hw->mac->rx_ipc(priv->hw);
if (!ret) {
netdev_warn(priv->dev, "RX IPC Checksum Offload disabled\n");
priv->plat->rx_coe = STMMAC_RX_COE_NONE;
priv->hw->rx_csum = 0;
}
priv->hw->mac->set_mac(priv->ioaddr, true);
stmmac_dma_operation_mode(priv);
stmmac_mmc_setup(priv);
if (init_ptp) {
ret = clk_prepare_enable(priv->plat->clk_ptp_ref);
if (ret < 0)
netdev_warn(priv->dev, "failed to enable PTP reference clock: %d\n", ret);
ret = stmmac_init_ptp(priv);
if (ret == -EOPNOTSUPP)
netdev_warn(priv->dev, "PTP not supported by HW\n");
else if (ret)
netdev_warn(priv->dev, "PTP init failed\n");
}
#ifdef CONFIG_DEBUG_FS
ret = stmmac_init_fs(dev);
if (ret < 0)
netdev_warn(priv->dev, "%s: failed debugFS registration\n",
__func__);
#endif
stmmac_start_all_dma(priv);
priv->tx_lpi_timer = STMMAC_DEFAULT_TWT_LS;
if ((priv->use_riwt) && (priv->hw->dma->rx_watchdog)) {
priv->rx_riwt = MAX_DMA_RIWT;
priv->hw->dma->rx_watchdog(priv->ioaddr, MAX_DMA_RIWT, rx_cnt);
}
if (priv->hw->pcs && priv->hw->mac->pcs_ctrl_ane)
priv->hw->mac->pcs_ctrl_ane(priv->hw, 1, priv->hw->ps, 0);
stmmac_set_rings_length(priv);
if (priv->tso) {
for (chan = 0; chan < tx_cnt; chan++)
priv->hw->dma->enable_tso(priv->ioaddr, 1, chan);
}
return 0;
}
static void stmmac_hw_teardown(struct net_device *dev)
{
struct stmmac_priv *priv = netdev_priv(dev);
clk_disable_unprepare(priv->plat->clk_ptp_ref);
}
static int stmmac_open(struct net_device *dev)
{
struct stmmac_priv *priv = netdev_priv(dev);
int ret;
stmmac_check_ether_addr(priv);
if (priv->hw->pcs != STMMAC_PCS_RGMII &&
priv->hw->pcs != STMMAC_PCS_TBI &&
priv->hw->pcs != STMMAC_PCS_RTBI) {
ret = stmmac_init_phy(dev);
if (ret) {
netdev_err(priv->dev,
"%s: Cannot attach to PHY (error: %d)\n",
__func__, ret);
return ret;
}
}
memset(&priv->xstats, 0, sizeof(struct stmmac_extra_stats));
priv->xstats.threshold = tc;
priv->dma_buf_sz = STMMAC_ALIGN(buf_sz);
priv->rx_copybreak = STMMAC_RX_COPYBREAK;
ret = alloc_dma_desc_resources(priv);
if (ret < 0) {
netdev_err(priv->dev, "%s: DMA descriptors allocation failed\n",
__func__);
goto dma_desc_error;
}
ret = init_dma_desc_rings(dev, GFP_KERNEL);
if (ret < 0) {
netdev_err(priv->dev, "%s: DMA descriptors initialization failed\n",
__func__);
goto init_error;
}
ret = stmmac_hw_setup(dev, true);
if (ret < 0) {
netdev_err(priv->dev, "%s: Hw setup failed\n", __func__);
goto init_error;
}
stmmac_init_tx_coalesce(priv);
if (dev->phydev)
phy_start(dev->phydev);
ret = request_irq(dev->irq, stmmac_interrupt,
IRQF_SHARED, dev->name, dev);
if (unlikely(ret < 0)) {
netdev_err(priv->dev,
"%s: ERROR: allocating the IRQ %d (error: %d)\n",
__func__, dev->irq, ret);
goto irq_error;
}
if (priv->wol_irq != dev->irq) {
ret = request_irq(priv->wol_irq, stmmac_interrupt,
IRQF_SHARED, dev->name, dev);
if (unlikely(ret < 0)) {
netdev_err(priv->dev,
"%s: ERROR: allocating the WoL IRQ %d (%d)\n",
__func__, priv->wol_irq, ret);
goto wolirq_error;
}
}
if (priv->lpi_irq > 0) {
ret = request_irq(priv->lpi_irq, stmmac_interrupt, IRQF_SHARED,
dev->name, dev);
if (unlikely(ret < 0)) {
netdev_err(priv->dev,
"%s: ERROR: allocating the LPI IRQ %d (%d)\n",
__func__, priv->lpi_irq, ret);
goto lpiirq_error;
}
}
stmmac_enable_all_queues(priv);
stmmac_start_all_queues(priv);
return 0;
lpiirq_error:
if (priv->wol_irq != dev->irq)
free_irq(priv->wol_irq, dev);
wolirq_error:
free_irq(dev->irq, dev);
irq_error:
if (dev->phydev)
phy_stop(dev->phydev);
del_timer_sync(&priv->txtimer);
stmmac_hw_teardown(dev);
init_error:
free_dma_desc_resources(priv);
dma_desc_error:
if (dev->phydev)
phy_disconnect(dev->phydev);
return ret;
}
static int stmmac_release(struct net_device *dev)
{
struct stmmac_priv *priv = netdev_priv(dev);
if (priv->eee_enabled)
del_timer_sync(&priv->eee_ctrl_timer);
if (dev->phydev) {
phy_stop(dev->phydev);
phy_disconnect(dev->phydev);
}
stmmac_stop_all_queues(priv);
stmmac_disable_all_queues(priv);
del_timer_sync(&priv->txtimer);
free_irq(dev->irq, dev);
if (priv->wol_irq != dev->irq)
free_irq(priv->wol_irq, dev);
if (priv->lpi_irq > 0)
free_irq(priv->lpi_irq, dev);
stmmac_stop_all_dma(priv);
free_dma_desc_resources(priv);
priv->hw->mac->set_mac(priv->ioaddr, false);
netif_carrier_off(dev);
#ifdef CONFIG_DEBUG_FS
stmmac_exit_fs(dev);
#endif
stmmac_release_ptp(priv);
return 0;
}
static void stmmac_tso_allocator(struct stmmac_priv *priv, unsigned int des,
int total_len, bool last_segment, u32 queue)
{
struct stmmac_tx_queue *tx_q = &priv->tx_queue[queue];
struct dma_desc *desc;
u32 buff_size;
int tmp_len;
tmp_len = total_len;
while (tmp_len > 0) {
tx_q->cur_tx = STMMAC_GET_ENTRY(tx_q->cur_tx, DMA_TX_SIZE);
desc = tx_q->dma_tx + tx_q->cur_tx;
desc->des0 = cpu_to_le32(des + (total_len - tmp_len));
buff_size = tmp_len >= TSO_MAX_BUFF_SIZE ?
TSO_MAX_BUFF_SIZE : tmp_len;
priv->hw->desc->prepare_tso_tx_desc(desc, 0, buff_size,
0, 1,
(last_segment) && (tmp_len <= TSO_MAX_BUFF_SIZE),
0, 0);
tmp_len -= TSO_MAX_BUFF_SIZE;
}
}
static netdev_tx_t stmmac_tso_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct dma_desc *desc, *first, *mss_desc = NULL;
struct stmmac_priv *priv = netdev_priv(dev);
int nfrags = skb_shinfo(skb)->nr_frags;
u32 queue = skb_get_queue_mapping(skb);
unsigned int first_entry, des;
struct stmmac_tx_queue *tx_q;
int tmp_pay_len = 0;
u32 pay_len, mss;
u8 proto_hdr_len;
int i;
tx_q = &priv->tx_queue[queue];
proto_hdr_len = skb_transport_offset(skb) + tcp_hdrlen(skb);
if (unlikely(stmmac_tx_avail(priv, queue) <
(((skb->len - proto_hdr_len) / TSO_MAX_BUFF_SIZE + 1)))) {
if (!netif_tx_queue_stopped(netdev_get_tx_queue(dev, queue))) {
netif_tx_stop_queue(netdev_get_tx_queue(priv->dev,
queue));
netdev_err(priv->dev,
"%s: Tx Ring full when queue awake\n",
__func__);
}
return NETDEV_TX_BUSY;
}
pay_len = skb_headlen(skb) - proto_hdr_len;
mss = skb_shinfo(skb)->gso_size;
if (mss != priv->mss) {
mss_desc = tx_q->dma_tx + tx_q->cur_tx;
priv->hw->desc->set_mss(mss_desc, mss);
priv->mss = mss;
tx_q->cur_tx = STMMAC_GET_ENTRY(tx_q->cur_tx, DMA_TX_SIZE);
}
if (netif_msg_tx_queued(priv)) {
pr_info("%s: tcphdrlen %d, hdr_len %d, pay_len %d, mss %d\n",
__func__, tcp_hdrlen(skb), proto_hdr_len, pay_len, mss);
pr_info("\tskb->len %d, skb->data_len %d\n", skb->len,
skb->data_len);
}
first_entry = tx_q->cur_tx;
desc = tx_q->dma_tx + first_entry;
first = desc;
des = dma_map_single(priv->device, skb->data, skb_headlen(skb),
DMA_TO_DEVICE);
if (dma_mapping_error(priv->device, des))
goto dma_map_err;
tx_q->tx_skbuff_dma[first_entry].buf = des;
tx_q->tx_skbuff_dma[first_entry].len = skb_headlen(skb);
first->des0 = cpu_to_le32(des);
if (pay_len)
first->des1 = cpu_to_le32(des + proto_hdr_len);
tmp_pay_len = pay_len - TSO_MAX_BUFF_SIZE;
stmmac_tso_allocator(priv, des, tmp_pay_len, (nfrags == 0), queue);
for (i = 0; i < nfrags; i++) {
const skb_frag_t *frag = &skb_shinfo(skb)->frags[i];
des = skb_frag_dma_map(priv->device, frag, 0,
skb_frag_size(frag),
DMA_TO_DEVICE);
if (dma_mapping_error(priv->device, des))
goto dma_map_err;
stmmac_tso_allocator(priv, des, skb_frag_size(frag),
(i == nfrags - 1), queue);
tx_q->tx_skbuff_dma[tx_q->cur_tx].buf = des;
tx_q->tx_skbuff_dma[tx_q->cur_tx].len = skb_frag_size(frag);
tx_q->tx_skbuff[tx_q->cur_tx] = NULL;
tx_q->tx_skbuff_dma[tx_q->cur_tx].map_as_page = true;
}
tx_q->tx_skbuff_dma[tx_q->cur_tx].last_segment = true;
tx_q->tx_skbuff[tx_q->cur_tx] = skb;
tx_q->cur_tx = STMMAC_GET_ENTRY(tx_q->cur_tx, DMA_TX_SIZE);
if (unlikely(stmmac_tx_avail(priv, queue) <= (MAX_SKB_FRAGS + 1))) {
netif_dbg(priv, hw, priv->dev, "%s: stop transmitted packets\n",
__func__);
netif_tx_stop_queue(netdev_get_tx_queue(priv->dev, queue));
}
dev->stats.tx_bytes += skb->len;
priv->xstats.tx_tso_frames++;
priv->xstats.tx_tso_nfrags += nfrags;
priv->tx_count_frames += nfrags + 1;
if (likely(priv->tx_coal_frames > priv->tx_count_frames)) {
mod_timer(&priv->txtimer,
STMMAC_COAL_TIMER(priv->tx_coal_timer));
} else {
priv->tx_count_frames = 0;
priv->hw->desc->set_tx_ic(desc);
priv->xstats.tx_set_ic_bit++;
}
skb_tx_timestamp(skb);
if (unlikely((skb_shinfo(skb)->tx_flags & SKBTX_HW_TSTAMP) &&
priv->hwts_tx_en)) {
skb_shinfo(skb)->tx_flags |= SKBTX_IN_PROGRESS;
priv->hw->desc->enable_tx_timestamp(first);
}
priv->hw->desc->prepare_tso_tx_desc(first, 1,
proto_hdr_len,
pay_len,
1, tx_q->tx_skbuff_dma[first_entry].last_segment,
tcp_hdrlen(skb) / 4, (skb->len - proto_hdr_len));
if (mss_desc)
priv->hw->desc->set_tx_owner(mss_desc);
dma_wmb();
if (netif_msg_pktdata(priv)) {
pr_info("%s: curr=%d dirty=%d f=%d, e=%d, f_p=%p, nfrags %d\n",
__func__, tx_q->cur_tx, tx_q->dirty_tx, first_entry,
tx_q->cur_tx, first, nfrags);
priv->hw->desc->display_ring((void *)tx_q->dma_tx, DMA_TX_SIZE,
0);
pr_info(">>> frame to be transmitted: ");
print_pkt(skb->data, skb_headlen(skb));
}
netdev_tx_sent_queue(netdev_get_tx_queue(dev, queue), skb->len);
priv->hw->dma->set_tx_tail_ptr(priv->ioaddr, tx_q->tx_tail_addr,
queue);
return NETDEV_TX_OK;
dma_map_err:
dev_err(priv->device, "Tx dma map failed\n");
dev_kfree_skb(skb);
priv->dev->stats.tx_dropped++;
return NETDEV_TX_OK;
}
static netdev_tx_t stmmac_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct stmmac_priv *priv = netdev_priv(dev);
unsigned int nopaged_len = skb_headlen(skb);
int i, csum_insertion = 0, is_jumbo = 0;
u32 queue = skb_get_queue_mapping(skb);
int nfrags = skb_shinfo(skb)->nr_frags;
int entry;
unsigned int first_entry;
struct dma_desc *desc, *first;
struct stmmac_tx_queue *tx_q;
unsigned int enh_desc;
unsigned int des;
tx_q = &priv->tx_queue[queue];
if (skb_is_gso(skb) && priv->tso) {
if (skb_shinfo(skb)->gso_type & (SKB_GSO_TCPV4 | SKB_GSO_TCPV6))
return stmmac_tso_xmit(skb, dev);
}
if (unlikely(stmmac_tx_avail(priv, queue) < nfrags + 1)) {
if (!netif_tx_queue_stopped(netdev_get_tx_queue(dev, queue))) {
netif_tx_stop_queue(netdev_get_tx_queue(priv->dev,
queue));
netdev_err(priv->dev,
"%s: Tx Ring full when queue awake\n",
__func__);
}
return NETDEV_TX_BUSY;
}
if (priv->tx_path_in_lpi_mode)
stmmac_disable_eee_mode(priv);
entry = tx_q->cur_tx;
first_entry = entry;
csum_insertion = (skb->ip_summed == CHECKSUM_PARTIAL);
if (likely(priv->extend_desc))
desc = (struct dma_desc *)(tx_q->dma_etx + entry);
else
desc = tx_q->dma_tx + entry;
first = desc;
enh_desc = priv->plat->enh_desc;
if (enh_desc)
is_jumbo = priv->hw->mode->is_jumbo_frm(skb->len, enh_desc);
if (unlikely(is_jumbo) && likely(priv->synopsys_id <
DWMAC_CORE_4_00)) {
entry = priv->hw->mode->jumbo_frm(tx_q, skb, csum_insertion);
if (unlikely(entry < 0))
goto dma_map_err;
}
for (i = 0; i < nfrags; i++) {
const skb_frag_t *frag = &skb_shinfo(skb)->frags[i];
int len = skb_frag_size(frag);
bool last_segment = (i == (nfrags - 1));
entry = STMMAC_GET_ENTRY(entry, DMA_TX_SIZE);
if (likely(priv->extend_desc))
desc = (struct dma_desc *)(tx_q->dma_etx + entry);
else
desc = tx_q->dma_tx + entry;
des = skb_frag_dma_map(priv->device, frag, 0, len,
DMA_TO_DEVICE);
if (dma_mapping_error(priv->device, des))
goto dma_map_err;
tx_q->tx_skbuff[entry] = NULL;
tx_q->tx_skbuff_dma[entry].buf = des;
if (unlikely(priv->synopsys_id >= DWMAC_CORE_4_00))
desc->des0 = cpu_to_le32(des);
else
desc->des2 = cpu_to_le32(des);
tx_q->tx_skbuff_dma[entry].map_as_page = true;
tx_q->tx_skbuff_dma[entry].len = len;
tx_q->tx_skbuff_dma[entry].last_segment = last_segment;
priv->hw->desc->prepare_tx_desc(desc, 0, len, csum_insertion,
priv->mode, 1, last_segment,
skb->len);
}
tx_q->tx_skbuff[entry] = skb;
entry = STMMAC_GET_ENTRY(entry, DMA_TX_SIZE);
tx_q->cur_tx = entry;
if (netif_msg_pktdata(priv)) {
void *tx_head;
netdev_dbg(priv->dev,
"%s: curr=%d dirty=%d f=%d, e=%d, first=%p, nfrags=%d",
__func__, tx_q->cur_tx, tx_q->dirty_tx, first_entry,
entry, first, nfrags);
if (priv->extend_desc)
tx_head = (void *)tx_q->dma_etx;
else
tx_head = (void *)tx_q->dma_tx;
priv->hw->desc->display_ring(tx_head, DMA_TX_SIZE, false);
netdev_dbg(priv->dev, ">>> frame to be transmitted: ");
print_pkt(skb->data, skb->len);
}
if (unlikely(stmmac_tx_avail(priv, queue) <= (MAX_SKB_FRAGS + 1))) {
netif_dbg(priv, hw, priv->dev, "%s: stop transmitted packets\n",
__func__);
netif_tx_stop_queue(netdev_get_tx_queue(priv->dev, queue));
}
dev->stats.tx_bytes += skb->len;
priv->tx_count_frames += nfrags + 1;
if (likely(priv->tx_coal_frames > priv->tx_count_frames)) {
mod_timer(&priv->txtimer,
STMMAC_COAL_TIMER(priv->tx_coal_timer));
} else {
priv->tx_count_frames = 0;
priv->hw->desc->set_tx_ic(desc);
priv->xstats.tx_set_ic_bit++;
}
skb_tx_timestamp(skb);
if (likely(!is_jumbo)) {
bool last_segment = (nfrags == 0);
des = dma_map_single(priv->device, skb->data,
nopaged_len, DMA_TO_DEVICE);
if (dma_mapping_error(priv->device, des))
goto dma_map_err;
tx_q->tx_skbuff_dma[first_entry].buf = des;
if (unlikely(priv->synopsys_id >= DWMAC_CORE_4_00))
first->des0 = cpu_to_le32(des);
else
first->des2 = cpu_to_le32(des);
tx_q->tx_skbuff_dma[first_entry].len = nopaged_len;
tx_q->tx_skbuff_dma[first_entry].last_segment = last_segment;
if (unlikely((skb_shinfo(skb)->tx_flags & SKBTX_HW_TSTAMP) &&
priv->hwts_tx_en)) {
skb_shinfo(skb)->tx_flags |= SKBTX_IN_PROGRESS;
priv->hw->desc->enable_tx_timestamp(first);
}
priv->hw->desc->prepare_tx_desc(first, 1, nopaged_len,
csum_insertion, priv->mode, 1,
last_segment, skb->len);
dma_wmb();
}
netdev_tx_sent_queue(netdev_get_tx_queue(dev, queue), skb->len);
if (priv->synopsys_id < DWMAC_CORE_4_00)
priv->hw->dma->enable_dma_transmission(priv->ioaddr);
else
priv->hw->dma->set_tx_tail_ptr(priv->ioaddr, tx_q->tx_tail_addr,
queue);
return NETDEV_TX_OK;
dma_map_err:
netdev_err(priv->dev, "Tx DMA map failed\n");
dev_kfree_skb(skb);
priv->dev->stats.tx_dropped++;
return NETDEV_TX_OK;
}
static void stmmac_rx_vlan(struct net_device *dev, struct sk_buff *skb)
{
struct ethhdr *ehdr;
u16 vlanid;
if ((dev->features & NETIF_F_HW_VLAN_CTAG_RX) ==
NETIF_F_HW_VLAN_CTAG_RX &&
!__vlan_get_tag(skb, &vlanid)) {
ehdr = (struct ethhdr *)skb->data;
memmove(skb->data + VLAN_HLEN, ehdr, ETH_ALEN * 2);
skb_pull(skb, VLAN_HLEN);
__vlan_hwaccel_put_tag(skb, htons(ETH_P_8021Q), vlanid);
}
}
static inline int stmmac_rx_threshold_count(struct stmmac_rx_queue *rx_q)
{
if (rx_q->rx_zeroc_thresh < STMMAC_RX_THRESH)
return 0;
return 1;
}
static inline void stmmac_rx_refill(struct stmmac_priv *priv, u32 queue)
{
struct stmmac_rx_queue *rx_q = &priv->rx_queue[queue];
int dirty = stmmac_rx_dirty(priv, queue);
unsigned int entry = rx_q->dirty_rx;
int bfsize = priv->dma_buf_sz;
while (dirty-- > 0) {
struct dma_desc *p;
if (priv->extend_desc)
p = (struct dma_desc *)(rx_q->dma_erx + entry);
else
p = rx_q->dma_rx + entry;
if (likely(!rx_q->rx_skbuff[entry])) {
struct sk_buff *skb;
skb = netdev_alloc_skb_ip_align(priv->dev, bfsize);
if (unlikely(!skb)) {
rx_q->rx_zeroc_thresh = STMMAC_RX_THRESH;
if (unlikely(net_ratelimit()))
dev_err(priv->device,
"fail to alloc skb entry %d\n",
entry);
break;
}
rx_q->rx_skbuff[entry] = skb;
rx_q->rx_skbuff_dma[entry] =
dma_map_single(priv->device, skb->data, bfsize,
DMA_FROM_DEVICE);
if (dma_mapping_error(priv->device,
rx_q->rx_skbuff_dma[entry])) {
netdev_err(priv->dev, "Rx DMA map failed\n");
dev_kfree_skb(skb);
break;
}
if (unlikely(priv->synopsys_id >= DWMAC_CORE_4_00)) {
p->des0 = cpu_to_le32(rx_q->rx_skbuff_dma[entry]);
p->des1 = 0;
} else {
p->des2 = cpu_to_le32(rx_q->rx_skbuff_dma[entry]);
}
if (priv->hw->mode->refill_desc3)
priv->hw->mode->refill_desc3(rx_q, p);
if (rx_q->rx_zeroc_thresh > 0)
rx_q->rx_zeroc_thresh--;
netif_dbg(priv, rx_status, priv->dev,
"refill entry #%d\n", entry);
}
dma_wmb();
if (unlikely(priv->synopsys_id >= DWMAC_CORE_4_00))
priv->hw->desc->init_rx_desc(p, priv->use_riwt, 0, 0);
else
priv->hw->desc->set_rx_owner(p);
dma_wmb();
entry = STMMAC_GET_ENTRY(entry, DMA_RX_SIZE);
}
rx_q->dirty_rx = entry;
}
static int stmmac_rx(struct stmmac_priv *priv, int limit, u32 queue)
{
struct stmmac_rx_queue *rx_q = &priv->rx_queue[queue];
unsigned int entry = rx_q->cur_rx;
int coe = priv->hw->rx_csum;
unsigned int next_entry;
unsigned int count = 0;
if (netif_msg_rx_status(priv)) {
void *rx_head;
netdev_dbg(priv->dev, "%s: descriptor ring:\n", __func__);
if (priv->extend_desc)
rx_head = (void *)rx_q->dma_erx;
else
rx_head = (void *)rx_q->dma_rx;
priv->hw->desc->display_ring(rx_head, DMA_RX_SIZE, true);
}
while (count < limit) {
int status;
struct dma_desc *p;
struct dma_desc *np;
if (priv->extend_desc)
p = (struct dma_desc *)(rx_q->dma_erx + entry);
else
p = rx_q->dma_rx + entry;
status = priv->hw->desc->rx_status(&priv->dev->stats,
&priv->xstats, p);
if (unlikely(status & dma_own))
break;
count++;
rx_q->cur_rx = STMMAC_GET_ENTRY(rx_q->cur_rx, DMA_RX_SIZE);
next_entry = rx_q->cur_rx;
if (priv->extend_desc)
np = (struct dma_desc *)(rx_q->dma_erx + next_entry);
else
np = rx_q->dma_rx + next_entry;
prefetch(np);
if ((priv->extend_desc) && (priv->hw->desc->rx_extended_status))
priv->hw->desc->rx_extended_status(&priv->dev->stats,
&priv->xstats,
rx_q->dma_erx +
entry);
if (unlikely(status == discard_frame)) {
priv->dev->stats.rx_errors++;
if (priv->hwts_rx_en && !priv->extend_desc) {
rx_q->rx_skbuff[entry] = NULL;
dma_unmap_single(priv->device,
rx_q->rx_skbuff_dma[entry],
priv->dma_buf_sz,
DMA_FROM_DEVICE);
}
} else {
struct sk_buff *skb;
int frame_len;
unsigned int des;
if (unlikely(priv->synopsys_id >= DWMAC_CORE_4_00))
des = le32_to_cpu(p->des0);
else
des = le32_to_cpu(p->des2);
frame_len = priv->hw->desc->get_rx_frame_len(p, coe);
if (frame_len > priv->dma_buf_sz) {
netdev_err(priv->dev,
"len %d larger than size (%d)\n",
frame_len, priv->dma_buf_sz);
priv->dev->stats.rx_length_errors++;
break;
}
if (unlikely(status != llc_snap))
frame_len -= ETH_FCS_LEN;
if (netif_msg_rx_status(priv)) {
netdev_dbg(priv->dev, "\tdesc: %p [entry %d] buff=0x%x\n",
p, entry, des);
if (frame_len > ETH_FRAME_LEN)
netdev_dbg(priv->dev, "frame size %d, COE: %d\n",
frame_len, status);
}
if (unlikely(!priv->plat->has_gmac4 &&
((frame_len < priv->rx_copybreak) ||
stmmac_rx_threshold_count(rx_q)))) {
skb = netdev_alloc_skb_ip_align(priv->dev,
frame_len);
if (unlikely(!skb)) {
if (net_ratelimit())
dev_warn(priv->device,
"packet dropped\n");
priv->dev->stats.rx_dropped++;
break;
}
dma_sync_single_for_cpu(priv->device,
rx_q->rx_skbuff_dma
[entry], frame_len,
DMA_FROM_DEVICE);
skb_copy_to_linear_data(skb,
rx_q->
rx_skbuff[entry]->data,
frame_len);
skb_put(skb, frame_len);
dma_sync_single_for_device(priv->device,
rx_q->rx_skbuff_dma
[entry], frame_len,
DMA_FROM_DEVICE);
} else {
skb = rx_q->rx_skbuff[entry];
if (unlikely(!skb)) {
netdev_err(priv->dev,
"%s: Inconsistent Rx chain\n",
priv->dev->name);
priv->dev->stats.rx_dropped++;
break;
}
prefetch(skb->data - NET_IP_ALIGN);
rx_q->rx_skbuff[entry] = NULL;
rx_q->rx_zeroc_thresh++;
skb_put(skb, frame_len);
dma_unmap_single(priv->device,
rx_q->rx_skbuff_dma[entry],
priv->dma_buf_sz,
DMA_FROM_DEVICE);
}
if (netif_msg_pktdata(priv)) {
netdev_dbg(priv->dev, "frame received (%dbytes)",
frame_len);
print_pkt(skb->data, frame_len);
}
stmmac_get_rx_hwtstamp(priv, p, np, skb);
stmmac_rx_vlan(priv->dev, skb);
skb->protocol = eth_type_trans(skb, priv->dev);
if (unlikely(!coe))
skb_checksum_none_assert(skb);
else
skb->ip_summed = CHECKSUM_UNNECESSARY;
napi_gro_receive(&rx_q->napi, skb);
priv->dev->stats.rx_packets++;
priv->dev->stats.rx_bytes += frame_len;
}
entry = next_entry;
}
stmmac_rx_refill(priv, queue);
priv->xstats.rx_pkt_n += count;
return count;
}
static int stmmac_poll(struct napi_struct *napi, int budget)
{
struct stmmac_rx_queue *rx_q =
container_of(napi, struct stmmac_rx_queue, napi);
struct stmmac_priv *priv = rx_q->priv_data;
u32 tx_count = priv->plat->tx_queues_to_use;
u32 chan = rx_q->queue_index;
int work_done = 0;
u32 queue;
priv->xstats.napi_poll++;
for (queue = 0; queue < tx_count; queue++)
stmmac_tx_clean(priv, queue);
work_done = stmmac_rx(priv, budget, rx_q->queue_index);
if (work_done < budget) {
napi_complete_done(napi, work_done);
stmmac_enable_dma_irq(priv, chan);
}
return work_done;
}
static void stmmac_tx_timeout(struct net_device *dev)
{
struct stmmac_priv *priv = netdev_priv(dev);
u32 tx_count = priv->plat->tx_queues_to_use;
u32 chan;
for (chan = 0; chan < tx_count; chan++)
stmmac_tx_err(priv, chan);
}
static void stmmac_set_rx_mode(struct net_device *dev)
{
struct stmmac_priv *priv = netdev_priv(dev);
priv->hw->mac->set_filter(priv->hw, dev);
}
static int stmmac_change_mtu(struct net_device *dev, int new_mtu)
{
struct stmmac_priv *priv = netdev_priv(dev);
if (netif_running(dev)) {
netdev_err(priv->dev, "must be stopped to change its MTU\n");
return -EBUSY;
}
dev->mtu = new_mtu;
netdev_update_features(dev);
return 0;
}
static netdev_features_t stmmac_fix_features(struct net_device *dev,
netdev_features_t features)
{
struct stmmac_priv *priv = netdev_priv(dev);
if (priv->plat->rx_coe == STMMAC_RX_COE_NONE)
features &= ~NETIF_F_RXCSUM;
if (!priv->plat->tx_coe)
features &= ~NETIF_F_CSUM_MASK;
if (priv->plat->bugged_jumbo && (dev->mtu > ETH_DATA_LEN))
features &= ~NETIF_F_CSUM_MASK;
if ((priv->plat->tso_en) && (priv->dma_cap.tsoen)) {
if (features & NETIF_F_TSO)
priv->tso = true;
else
priv->tso = false;
}
return features;
}
static int stmmac_set_features(struct net_device *netdev,
netdev_features_t features)
{
struct stmmac_priv *priv = netdev_priv(netdev);
if (features & NETIF_F_RXCSUM)
priv->hw->rx_csum = priv->plat->rx_coe;
else
priv->hw->rx_csum = 0;
priv->hw->mac->rx_ipc(priv->hw);
return 0;
}
static irqreturn_t stmmac_interrupt(int irq, void *dev_id)
{
struct net_device *dev = (struct net_device *)dev_id;
struct stmmac_priv *priv = netdev_priv(dev);
u32 rx_cnt = priv->plat->rx_queues_to_use;
u32 tx_cnt = priv->plat->tx_queues_to_use;
u32 queues_count;
u32 queue;
queues_count = (rx_cnt > tx_cnt) ? rx_cnt : tx_cnt;
if (priv->irq_wake)
pm_wakeup_event(priv->device, 0);
if (unlikely(!dev)) {
netdev_err(priv->dev, "%s: invalid dev pointer\n", __func__);
return IRQ_NONE;
}
if ((priv->plat->has_gmac) || (priv->plat->has_gmac4)) {
int status = priv->hw->mac->host_irq_status(priv->hw,
&priv->xstats);
if (unlikely(status)) {
if (status & CORE_IRQ_TX_PATH_IN_LPI_MODE)
priv->tx_path_in_lpi_mode = true;
if (status & CORE_IRQ_TX_PATH_EXIT_LPI_MODE)
priv->tx_path_in_lpi_mode = false;
}
if (priv->synopsys_id >= DWMAC_CORE_4_00) {
for (queue = 0; queue < queues_count; queue++) {
struct stmmac_rx_queue *rx_q =
&priv->rx_queue[queue];
status |=
priv->hw->mac->host_mtl_irq_status(priv->hw,
queue);
if (status & CORE_IRQ_MTL_RX_OVERFLOW &&
priv->hw->dma->set_rx_tail_ptr)
priv->hw->dma->set_rx_tail_ptr(priv->ioaddr,
rx_q->rx_tail_addr,
queue);
}
}
if (priv->hw->pcs) {
if (priv->xstats.pcs_link)
netif_carrier_on(dev);
else
netif_carrier_off(dev);
}
}
stmmac_dma_interrupt(priv);
return IRQ_HANDLED;
}
static void stmmac_poll_controller(struct net_device *dev)
{
disable_irq(dev->irq);
stmmac_interrupt(dev->irq, dev);
enable_irq(dev->irq);
}
static int stmmac_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
int ret = -EOPNOTSUPP;
if (!netif_running(dev))
return -EINVAL;
switch (cmd) {
case SIOCGMIIPHY:
case SIOCGMIIREG:
case SIOCSMIIREG:
if (!dev->phydev)
return -EINVAL;
ret = phy_mii_ioctl(dev->phydev, rq, cmd);
break;
case SIOCSHWTSTAMP:
ret = stmmac_hwtstamp_ioctl(dev, rq);
break;
default:
break;
}
return ret;
}
static void sysfs_display_ring(void *head, int size, int extend_desc,
struct seq_file *seq)
{
int i;
struct dma_extended_desc *ep = (struct dma_extended_desc *)head;
struct dma_desc *p = (struct dma_desc *)head;
for (i = 0; i < size; i++) {
if (extend_desc) {
seq_printf(seq, "%d [0x%x]: 0x%x 0x%x 0x%x 0x%x\n",
i, (unsigned int)virt_to_phys(ep),
le32_to_cpu(ep->basic.des0),
le32_to_cpu(ep->basic.des1),
le32_to_cpu(ep->basic.des2),
le32_to_cpu(ep->basic.des3));
ep++;
} else {
seq_printf(seq, "%d [0x%x]: 0x%x 0x%x 0x%x 0x%x\n",
i, (unsigned int)virt_to_phys(p),
le32_to_cpu(p->des0), le32_to_cpu(p->des1),
le32_to_cpu(p->des2), le32_to_cpu(p->des3));
p++;
}
seq_printf(seq, "\n");
}
}
static int stmmac_sysfs_ring_read(struct seq_file *seq, void *v)
{
struct net_device *dev = seq->private;
struct stmmac_priv *priv = netdev_priv(dev);
u32 rx_count = priv->plat->rx_queues_to_use;
u32 tx_count = priv->plat->tx_queues_to_use;
u32 queue;
for (queue = 0; queue < rx_count; queue++) {
struct stmmac_rx_queue *rx_q = &priv->rx_queue[queue];
seq_printf(seq, "RX Queue %d:\n", queue);
if (priv->extend_desc) {
seq_printf(seq, "Extended descriptor ring:\n");
sysfs_display_ring((void *)rx_q->dma_erx,
DMA_RX_SIZE, 1, seq);
} else {
seq_printf(seq, "Descriptor ring:\n");
sysfs_display_ring((void *)rx_q->dma_rx,
DMA_RX_SIZE, 0, seq);
}
}
for (queue = 0; queue < tx_count; queue++) {
struct stmmac_tx_queue *tx_q = &priv->tx_queue[queue];
seq_printf(seq, "TX Queue %d:\n", queue);
if (priv->extend_desc) {
seq_printf(seq, "Extended descriptor ring:\n");
sysfs_display_ring((void *)tx_q->dma_etx,
DMA_TX_SIZE, 1, seq);
} else {
seq_printf(seq, "Descriptor ring:\n");
sysfs_display_ring((void *)tx_q->dma_tx,
DMA_TX_SIZE, 0, seq);
}
}
return 0;
}
static int stmmac_sysfs_ring_open(struct inode *inode, struct file *file)
{
return single_open(file, stmmac_sysfs_ring_read, inode->i_private);
}
static int stmmac_sysfs_dma_cap_read(struct seq_file *seq, void *v)
{
struct net_device *dev = seq->private;
struct stmmac_priv *priv = netdev_priv(dev);
if (!priv->hw_cap_support) {
seq_printf(seq, "DMA HW features not supported\n");
return 0;
}
seq_printf(seq, "==============================\n");
seq_printf(seq, "\tDMA HW features\n");
seq_printf(seq, "==============================\n");
seq_printf(seq, "\t10/100 Mbps: %s\n",
(priv->dma_cap.mbps_10_100) ? "Y" : "N");
seq_printf(seq, "\t1000 Mbps: %s\n",
(priv->dma_cap.mbps_1000) ? "Y" : "N");
seq_printf(seq, "\tHalf duplex: %s\n",
(priv->dma_cap.half_duplex) ? "Y" : "N");
seq_printf(seq, "\tHash Filter: %s\n",
(priv->dma_cap.hash_filter) ? "Y" : "N");
seq_printf(seq, "\tMultiple MAC address registers: %s\n",
(priv->dma_cap.multi_addr) ? "Y" : "N");
seq_printf(seq, "\tPCS (TBI/SGMII/RTBI PHY interfaces): %s\n",
(priv->dma_cap.pcs) ? "Y" : "N");
seq_printf(seq, "\tSMA (MDIO) Interface: %s\n",
(priv->dma_cap.sma_mdio) ? "Y" : "N");
seq_printf(seq, "\tPMT Remote wake up: %s\n",
(priv->dma_cap.pmt_remote_wake_up) ? "Y" : "N");
seq_printf(seq, "\tPMT Magic Frame: %s\n",
(priv->dma_cap.pmt_magic_frame) ? "Y" : "N");
seq_printf(seq, "\tRMON module: %s\n",
(priv->dma_cap.rmon) ? "Y" : "N");
seq_printf(seq, "\tIEEE 1588-2002 Time Stamp: %s\n",
(priv->dma_cap.time_stamp) ? "Y" : "N");
seq_printf(seq, "\tIEEE 1588-2008 Advanced Time Stamp: %s\n",
(priv->dma_cap.atime_stamp) ? "Y" : "N");
seq_printf(seq, "\t802.3az - Energy-Efficient Ethernet (EEE): %s\n",
(priv->dma_cap.eee) ? "Y" : "N");
seq_printf(seq, "\tAV features: %s\n", (priv->dma_cap.av) ? "Y" : "N");
seq_printf(seq, "\tChecksum Offload in TX: %s\n",
(priv->dma_cap.tx_coe) ? "Y" : "N");
if (priv->synopsys_id >= DWMAC_CORE_4_00) {
seq_printf(seq, "\tIP Checksum Offload in RX: %s\n",
(priv->dma_cap.rx_coe) ? "Y" : "N");
} else {
seq_printf(seq, "\tIP Checksum Offload (type1) in RX: %s\n",
(priv->dma_cap.rx_coe_type1) ? "Y" : "N");
seq_printf(seq, "\tIP Checksum Offload (type2) in RX: %s\n",
(priv->dma_cap.rx_coe_type2) ? "Y" : "N");
}
seq_printf(seq, "\tRXFIFO > 2048bytes: %s\n",
(priv->dma_cap.rxfifo_over_2048) ? "Y" : "N");
seq_printf(seq, "\tNumber of Additional RX channel: %d\n",
priv->dma_cap.number_rx_channel);
seq_printf(seq, "\tNumber of Additional TX channel: %d\n",
priv->dma_cap.number_tx_channel);
seq_printf(seq, "\tEnhanced descriptors: %s\n",
(priv->dma_cap.enh_desc) ? "Y" : "N");
return 0;
}
static int stmmac_sysfs_dma_cap_open(struct inode *inode, struct file *file)
{
return single_open(file, stmmac_sysfs_dma_cap_read, inode->i_private);
}
static int stmmac_init_fs(struct net_device *dev)
{
struct stmmac_priv *priv = netdev_priv(dev);
priv->dbgfs_dir = debugfs_create_dir(dev->name, stmmac_fs_dir);
if (!priv->dbgfs_dir || IS_ERR(priv->dbgfs_dir)) {
netdev_err(priv->dev, "ERROR failed to create debugfs directory\n");
return -ENOMEM;
}
priv->dbgfs_rings_status =
debugfs_create_file("descriptors_status", S_IRUGO,
priv->dbgfs_dir, dev,
&stmmac_rings_status_fops);
if (!priv->dbgfs_rings_status || IS_ERR(priv->dbgfs_rings_status)) {
netdev_err(priv->dev, "ERROR creating stmmac ring debugfs file\n");
debugfs_remove_recursive(priv->dbgfs_dir);
return -ENOMEM;
}
priv->dbgfs_dma_cap = debugfs_create_file("dma_cap", S_IRUGO,
priv->dbgfs_dir,
dev, &stmmac_dma_cap_fops);
if (!priv->dbgfs_dma_cap || IS_ERR(priv->dbgfs_dma_cap)) {
netdev_err(priv->dev, "ERROR creating stmmac MMC debugfs file\n");
debugfs_remove_recursive(priv->dbgfs_dir);
return -ENOMEM;
}
return 0;
}
static void stmmac_exit_fs(struct net_device *dev)
{
struct stmmac_priv *priv = netdev_priv(dev);
debugfs_remove_recursive(priv->dbgfs_dir);
}
static int stmmac_hw_init(struct stmmac_priv *priv)
{
struct mac_device_info *mac;
if (priv->plat->setup) {
mac = priv->plat->setup(priv);
} else if (priv->plat->has_gmac) {
priv->dev->priv_flags |= IFF_UNICAST_FLT;
mac = dwmac1000_setup(priv->ioaddr,
priv->plat->multicast_filter_bins,
priv->plat->unicast_filter_entries,
&priv->synopsys_id);
} else if (priv->plat->has_gmac4) {
priv->dev->priv_flags |= IFF_UNICAST_FLT;
mac = dwmac4_setup(priv->ioaddr,
priv->plat->multicast_filter_bins,
priv->plat->unicast_filter_entries,
&priv->synopsys_id);
} else {
mac = dwmac100_setup(priv->ioaddr, &priv->synopsys_id);
}
if (!mac)
return -ENOMEM;
priv->hw = mac;
if (priv->plat->has_sun8i)
chain_mode = 1;
if (priv->synopsys_id >= DWMAC_CORE_4_00) {
priv->hw->mode = &dwmac4_ring_mode_ops;
} else {
if (chain_mode) {
priv->hw->mode = &chain_mode_ops;
dev_info(priv->device, "Chain mode enabled\n");
priv->mode = STMMAC_CHAIN_MODE;
} else {
priv->hw->mode = &ring_mode_ops;
dev_info(priv->device, "Ring mode enabled\n");
priv->mode = STMMAC_RING_MODE;
}
}
priv->hw_cap_support = stmmac_get_hw_features(priv);
if (priv->hw_cap_support) {
dev_info(priv->device, "DMA HW capability register supported\n");
priv->plat->enh_desc = priv->dma_cap.enh_desc;
priv->plat->pmt = priv->dma_cap.pmt_remote_wake_up;
priv->hw->pmt = priv->plat->pmt;
if (priv->plat->force_thresh_dma_mode)
priv->plat->tx_coe = 0;
else
priv->plat->tx_coe = priv->dma_cap.tx_coe;
priv->plat->rx_coe = priv->dma_cap.rx_coe;
if (priv->dma_cap.rx_coe_type2)
priv->plat->rx_coe = STMMAC_RX_COE_TYPE2;
else if (priv->dma_cap.rx_coe_type1)
priv->plat->rx_coe = STMMAC_RX_COE_TYPE1;
} else {
dev_info(priv->device, "No HW DMA feature register supported\n");
}
if (priv->synopsys_id >= DWMAC_CORE_4_00)
priv->hw->desc = &dwmac4_desc_ops;
else
stmmac_selec_desc_mode(priv);
if (priv->plat->rx_coe) {
priv->hw->rx_csum = priv->plat->rx_coe;
dev_info(priv->device, "RX Checksum Offload Engine supported\n");
if (priv->synopsys_id < DWMAC_CORE_4_00)
dev_info(priv->device, "COE Type %d\n", priv->hw->rx_csum);
}
if (priv->plat->tx_coe)
dev_info(priv->device, "TX Checksum insertion supported\n");
if (priv->plat->pmt) {
dev_info(priv->device, "Wake-Up On Lan supported\n");
device_set_wakeup_capable(priv->device, 1);
}
if (priv->dma_cap.tsoen)
dev_info(priv->device, "TSO supported\n");
return 0;
}
int stmmac_dvr_probe(struct device *device,
struct plat_stmmacenet_data *plat_dat,
struct stmmac_resources *res)
{
struct net_device *ndev = NULL;
struct stmmac_priv *priv;
int ret = 0;
u32 queue;
ndev = alloc_etherdev_mqs(sizeof(struct stmmac_priv),
MTL_MAX_TX_QUEUES,
MTL_MAX_RX_QUEUES);
if (!ndev)
return -ENOMEM;
SET_NETDEV_DEV(ndev, device);
priv = netdev_priv(ndev);
priv->device = device;
priv->dev = ndev;
stmmac_set_ethtool_ops(ndev);
priv->pause = pause;
priv->plat = plat_dat;
priv->ioaddr = res->addr;
priv->dev->base_addr = (unsigned long)res->addr;
priv->dev->irq = res->irq;
priv->wol_irq = res->wol_irq;
priv->lpi_irq = res->lpi_irq;
if (res->mac)
memcpy(priv->dev->dev_addr, res->mac, ETH_ALEN);
dev_set_drvdata(device, priv->dev);
stmmac_verify_args();
if ((phyaddr >= 0) && (phyaddr <= 31))
priv->plat->phy_addr = phyaddr;
if (priv->plat->stmmac_rst) {
ret = reset_control_assert(priv->plat->stmmac_rst);
reset_control_deassert(priv->plat->stmmac_rst);
if (ret == -ENOTSUPP)
reset_control_reset(priv->plat->stmmac_rst);
}
ret = stmmac_hw_init(priv);
if (ret)
goto error_hw_init;
netif_set_real_num_rx_queues(ndev, priv->plat->rx_queues_to_use);
netif_set_real_num_tx_queues(ndev, priv->plat->tx_queues_to_use);
ndev->netdev_ops = &stmmac_netdev_ops;
ndev->hw_features = NETIF_F_SG | NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM |
NETIF_F_RXCSUM;
if ((priv->plat->tso_en) && (priv->dma_cap.tsoen)) {
ndev->hw_features |= NETIF_F_TSO | NETIF_F_TSO6;
priv->tso = true;
dev_info(priv->device, "TSO feature enabled\n");
}
ndev->features |= ndev->hw_features | NETIF_F_HIGHDMA;
ndev->watchdog_timeo = msecs_to_jiffies(watchdog);
#ifdef STMMAC_VLAN_TAG_USED
ndev->features |= NETIF_F_HW_VLAN_CTAG_RX;
#endif
priv->msg_enable = netif_msg_init(debug, default_msg_level);
ndev->min_mtu = ETH_ZLEN - ETH_HLEN;
if ((priv->plat->enh_desc) || (priv->synopsys_id >= DWMAC_CORE_4_00))
ndev->max_mtu = JUMBO_LEN;
else
ndev->max_mtu = SKB_MAX_HEAD(NET_SKB_PAD + NET_IP_ALIGN);
if ((priv->plat->maxmtu < ndev->max_mtu) &&
(priv->plat->maxmtu >= ndev->min_mtu))
ndev->max_mtu = priv->plat->maxmtu;
else if (priv->plat->maxmtu < ndev->min_mtu)
dev_warn(priv->device,
"%s: warning: maxmtu having invalid value (%d)\n",
__func__, priv->plat->maxmtu);
if (flow_ctrl)
priv->flow_ctrl = FLOW_AUTO;
if ((priv->synopsys_id >= DWMAC_CORE_3_50) && (!priv->plat->riwt_off)) {
priv->use_riwt = 1;
dev_info(priv->device,
"Enable RX Mitigation via HW Watchdog Timer\n");
}
for (queue = 0; queue < priv->plat->rx_queues_to_use; queue++) {
struct stmmac_rx_queue *rx_q = &priv->rx_queue[queue];
netif_napi_add(ndev, &rx_q->napi, stmmac_poll,
(8 * priv->plat->rx_queues_to_use));
}
spin_lock_init(&priv->lock);
if (!priv->plat->clk_csr)
stmmac_clk_csr_set(priv);
else
priv->clk_csr = priv->plat->clk_csr;
stmmac_check_pcs_mode(priv);
if (priv->hw->pcs != STMMAC_PCS_RGMII &&
priv->hw->pcs != STMMAC_PCS_TBI &&
priv->hw->pcs != STMMAC_PCS_RTBI) {
ret = stmmac_mdio_register(ndev);
if (ret < 0) {
dev_err(priv->device,
"%s: MDIO bus (id: %d) registration failed",
__func__, priv->plat->bus_id);
goto error_mdio_register;
}
}
ret = register_netdev(ndev);
if (ret) {
dev_err(priv->device, "%s: ERROR %i registering the device\n",
__func__, ret);
goto error_netdev_register;
}
return ret;
error_netdev_register:
if (priv->hw->pcs != STMMAC_PCS_RGMII &&
priv->hw->pcs != STMMAC_PCS_TBI &&
priv->hw->pcs != STMMAC_PCS_RTBI)
stmmac_mdio_unregister(ndev);
error_mdio_register:
for (queue = 0; queue < priv->plat->rx_queues_to_use; queue++) {
struct stmmac_rx_queue *rx_q = &priv->rx_queue[queue];
netif_napi_del(&rx_q->napi);
}
error_hw_init:
free_netdev(ndev);
return ret;
}
int stmmac_dvr_remove(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
struct stmmac_priv *priv = netdev_priv(ndev);
netdev_info(priv->dev, "%s: removing driver", __func__);
stmmac_stop_all_dma(priv);
priv->hw->mac->set_mac(priv->ioaddr, false);
netif_carrier_off(ndev);
unregister_netdev(ndev);
if (priv->plat->stmmac_rst)
reset_control_assert(priv->plat->stmmac_rst);
clk_disable_unprepare(priv->plat->pclk);
clk_disable_unprepare(priv->plat->stmmac_clk);
if (priv->hw->pcs != STMMAC_PCS_RGMII &&
priv->hw->pcs != STMMAC_PCS_TBI &&
priv->hw->pcs != STMMAC_PCS_RTBI)
stmmac_mdio_unregister(ndev);
free_netdev(ndev);
return 0;
}
int stmmac_suspend(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
struct stmmac_priv *priv = netdev_priv(ndev);
unsigned long flags;
if (!ndev || !netif_running(ndev))
return 0;
if (ndev->phydev)
phy_stop(ndev->phydev);
spin_lock_irqsave(&priv->lock, flags);
netif_device_detach(ndev);
stmmac_stop_all_queues(priv);
stmmac_disable_all_queues(priv);
stmmac_stop_all_dma(priv);
if (device_may_wakeup(priv->device)) {
priv->hw->mac->pmt(priv->hw, priv->wolopts);
priv->irq_wake = 1;
} else {
priv->hw->mac->set_mac(priv->ioaddr, false);
pinctrl_pm_select_sleep_state(priv->device);
clk_disable(priv->plat->pclk);
clk_disable(priv->plat->stmmac_clk);
}
spin_unlock_irqrestore(&priv->lock, flags);
priv->oldlink = false;
priv->speed = SPEED_UNKNOWN;
priv->oldduplex = DUPLEX_UNKNOWN;
return 0;
}
static void stmmac_reset_queues_param(struct stmmac_priv *priv)
{
u32 rx_cnt = priv->plat->rx_queues_to_use;
u32 tx_cnt = priv->plat->tx_queues_to_use;
u32 queue;
for (queue = 0; queue < rx_cnt; queue++) {
struct stmmac_rx_queue *rx_q = &priv->rx_queue[queue];
rx_q->cur_rx = 0;
rx_q->dirty_rx = 0;
}
for (queue = 0; queue < tx_cnt; queue++) {
struct stmmac_tx_queue *tx_q = &priv->tx_queue[queue];
tx_q->cur_tx = 0;
tx_q->dirty_tx = 0;
}
}
int stmmac_resume(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
struct stmmac_priv *priv = netdev_priv(ndev);
unsigned long flags;
if (!netif_running(ndev))
return 0;
if (device_may_wakeup(priv->device)) {
spin_lock_irqsave(&priv->lock, flags);
priv->hw->mac->pmt(priv->hw, 0);
spin_unlock_irqrestore(&priv->lock, flags);
priv->irq_wake = 0;
} else {
pinctrl_pm_select_default_state(priv->device);
clk_enable(priv->plat->stmmac_clk);
clk_enable(priv->plat->pclk);
if (priv->mii)
stmmac_mdio_reset(priv->mii);
}
netif_device_attach(ndev);
spin_lock_irqsave(&priv->lock, flags);
stmmac_reset_queues_param(priv);
priv->mss = 0;
stmmac_clear_descriptors(priv);
stmmac_hw_setup(ndev, false);
stmmac_init_tx_coalesce(priv);
stmmac_set_rx_mode(ndev);
stmmac_enable_all_queues(priv);
stmmac_start_all_queues(priv);
spin_unlock_irqrestore(&priv->lock, flags);
if (ndev->phydev)
phy_start(ndev->phydev);
return 0;
}
static int __init stmmac_cmdline_opt(char *str)
{
char *opt;
if (!str || !*str)
return -EINVAL;
while ((opt = strsep(&str, ",")) != NULL) {
if (!strncmp(opt, "debug:", 6)) {
if (kstrtoint(opt + 6, 0, &debug))
goto err;
} else if (!strncmp(opt, "phyaddr:", 8)) {
if (kstrtoint(opt + 8, 0, &phyaddr))
goto err;
} else if (!strncmp(opt, "buf_sz:", 7)) {
if (kstrtoint(opt + 7, 0, &buf_sz))
goto err;
} else if (!strncmp(opt, "tc:", 3)) {
if (kstrtoint(opt + 3, 0, &tc))
goto err;
} else if (!strncmp(opt, "watchdog:", 9)) {
if (kstrtoint(opt + 9, 0, &watchdog))
goto err;
} else if (!strncmp(opt, "flow_ctrl:", 10)) {
if (kstrtoint(opt + 10, 0, &flow_ctrl))
goto err;
} else if (!strncmp(opt, "pause:", 6)) {
if (kstrtoint(opt + 6, 0, &pause))
goto err;
} else if (!strncmp(opt, "eee_timer:", 10)) {
if (kstrtoint(opt + 10, 0, &eee_timer))
goto err;
} else if (!strncmp(opt, "chain_mode:", 11)) {
if (kstrtoint(opt + 11, 0, &chain_mode))
goto err;
}
}
return 0;
err:
pr_err("%s: ERROR broken module parameter conversion", __func__);
return -EINVAL;
}
static int __init stmmac_init(void)
{
#ifdef CONFIG_DEBUG_FS
if (!stmmac_fs_dir) {
stmmac_fs_dir = debugfs_create_dir(STMMAC_RESOURCE_NAME, NULL);
if (!stmmac_fs_dir || IS_ERR(stmmac_fs_dir)) {
pr_err("ERROR %s, debugfs create directory failed\n",
STMMAC_RESOURCE_NAME);
return -ENOMEM;
}
}
#endif
return 0;
}
static void __exit stmmac_exit(void)
{
#ifdef CONFIG_DEBUG_FS
debugfs_remove_recursive(stmmac_fs_dir);
#endif
}
