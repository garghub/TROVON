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
static void stmmac_clk_csr_set(struct stmmac_priv *priv)
{
u32 clk_rate;
clk_rate = clk_get_rate(priv->stmmac_clk);
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
}
static void print_pkt(unsigned char *buf, int len)
{
pr_debug("len = %d byte, buf addr: 0x%p\n", len, buf);
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET, buf, len);
}
static inline u32 stmmac_tx_avail(struct stmmac_priv *priv)
{
unsigned avail;
if (priv->dirty_tx > priv->cur_tx)
avail = priv->dirty_tx - priv->cur_tx - 1;
else
avail = DMA_TX_SIZE - priv->cur_tx + priv->dirty_tx - 1;
return avail;
}
static inline u32 stmmac_rx_dirty(struct stmmac_priv *priv)
{
unsigned dirty;
if (priv->dirty_rx <= priv->cur_rx)
dirty = priv->cur_rx - priv->dirty_rx;
else
dirty = DMA_RX_SIZE - priv->dirty_rx + priv->cur_rx;
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
if ((priv->dirty_tx == priv->cur_tx) &&
(priv->tx_path_in_lpi_mode == false))
priv->hw->mac->set_eee_mode(priv->hw);
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
if (!priv->hw->desc->get_tx_timestamp_status(p)) {
ns = priv->hw->desc->get_timestamp(p, priv->adv_ts);
memset(&shhwtstamp, 0, sizeof(struct skb_shared_hwtstamps));
shhwtstamp.hwtstamp = ns_to_ktime(ns);
netdev_info(priv->dev, "get valid TX hw timestamp %llu\n", ns);
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
if (!priv->hw->desc->get_rx_timestamp_status(p, priv->adv_ts)) {
if (priv->plat->has_gmac4)
ns = priv->hw->desc->get_timestamp(np, priv->adv_ts);
else
ns = priv->hw->desc->get_timestamp(p, priv->adv_ts);
netdev_info(priv->dev, "get valid RX hw timestamp %llu\n", ns);
shhwtstamp = skb_hwtstamps(skb);
memset(shhwtstamp, 0, sizeof(struct skb_shared_hwtstamps));
shhwtstamp->hwtstamp = ns_to_ktime(ns);
} else {
netdev_err(priv->dev, "cannot get RX hw timestamp\n");
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
priv->ptpaddr, priv->clk_ptp_rate,
priv->plat->has_gmac4);
temp = div_u64(1000000000ULL, sec_inc);
temp = (u64)(temp << 32);
priv->default_addend = div_u64(temp, priv->clk_ptp_rate);
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
priv->clk_ptp_ref = devm_clk_get(priv->device, "clk_ptp_ref");
if (IS_ERR(priv->clk_ptp_ref)) {
priv->clk_ptp_rate = clk_get_rate(priv->stmmac_clk);
priv->clk_ptp_ref = NULL;
netdev_dbg(priv->dev, "PTP uses main clock\n");
} else {
clk_prepare_enable(priv->clk_ptp_ref);
priv->clk_ptp_rate = clk_get_rate(priv->clk_ptp_ref);
netdev_dbg(priv->dev, "PTP rate %d\n", priv->clk_ptp_rate);
}
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
if (priv->clk_ptp_ref)
clk_disable_unprepare(priv->clk_ptp_ref);
stmmac_ptp_unregister(priv);
}
static void stmmac_adjust_link(struct net_device *dev)
{
struct stmmac_priv *priv = netdev_priv(dev);
struct phy_device *phydev = dev->phydev;
unsigned long flags;
int new_state = 0;
unsigned int fc = priv->flow_ctrl, pause_time = priv->pause;
if (phydev == NULL)
return;
spin_lock_irqsave(&priv->lock, flags);
if (phydev->link) {
u32 ctrl = readl(priv->ioaddr + MAC_CTRL_REG);
if (phydev->duplex != priv->oldduplex) {
new_state = 1;
if (!(phydev->duplex))
ctrl &= ~priv->hw->link.duplex;
else
ctrl |= priv->hw->link.duplex;
priv->oldduplex = phydev->duplex;
}
if (phydev->pause)
priv->hw->mac->flow_ctrl(priv->hw, phydev->duplex,
fc, pause_time);
if (phydev->speed != priv->speed) {
new_state = 1;
switch (phydev->speed) {
case 1000:
if (likely((priv->plat->has_gmac) ||
(priv->plat->has_gmac4)))
ctrl &= ~priv->hw->link.port;
stmmac_hw_fix_mac_speed(priv);
break;
case 100:
case 10:
if (likely((priv->plat->has_gmac) ||
(priv->plat->has_gmac4))) {
ctrl |= priv->hw->link.port;
if (phydev->speed == SPEED_100) {
ctrl |= priv->hw->link.speed;
} else {
ctrl &= ~(priv->hw->link.speed);
}
} else {
ctrl &= ~priv->hw->link.port;
}
stmmac_hw_fix_mac_speed(priv);
break;
default:
netif_warn(priv, link, priv->dev,
"Speed (%d) not 10/100\n",
phydev->speed);
break;
}
priv->speed = phydev->speed;
}
writel(ctrl, priv->ioaddr + MAC_CTRL_REG);
if (!priv->oldlink) {
new_state = 1;
priv->oldlink = 1;
}
} else if (priv->oldlink) {
new_state = 1;
priv->oldlink = 0;
priv->speed = 0;
priv->oldduplex = -1;
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
priv->oldlink = 0;
priv->speed = 0;
priv->oldduplex = -1;
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
netdev_dbg(priv->dev, "%s: attached to PHY (UID 0x%x) Link = %d\n",
__func__, phydev->phy_id, phydev->link);
return 0;
}
static void stmmac_display_rings(struct stmmac_priv *priv)
{
void *head_rx, *head_tx;
if (priv->extend_desc) {
head_rx = (void *)priv->dma_erx;
head_tx = (void *)priv->dma_etx;
} else {
head_rx = (void *)priv->dma_rx;
head_tx = (void *)priv->dma_tx;
}
priv->hw->desc->display_ring(head_rx, DMA_RX_SIZE, true);
priv->hw->desc->display_ring(head_tx, DMA_TX_SIZE, false);
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
static void stmmac_clear_descriptors(struct stmmac_priv *priv)
{
int i;
for (i = 0; i < DMA_RX_SIZE; i++)
if (priv->extend_desc)
priv->hw->desc->init_rx_desc(&priv->dma_erx[i].basic,
priv->use_riwt, priv->mode,
(i == DMA_RX_SIZE - 1));
else
priv->hw->desc->init_rx_desc(&priv->dma_rx[i],
priv->use_riwt, priv->mode,
(i == DMA_RX_SIZE - 1));
for (i = 0; i < DMA_TX_SIZE; i++)
if (priv->extend_desc)
priv->hw->desc->init_tx_desc(&priv->dma_etx[i].basic,
priv->mode,
(i == DMA_TX_SIZE - 1));
else
priv->hw->desc->init_tx_desc(&priv->dma_tx[i],
priv->mode,
(i == DMA_TX_SIZE - 1));
}
static int stmmac_init_rx_buffers(struct stmmac_priv *priv, struct dma_desc *p,
int i, gfp_t flags)
{
struct sk_buff *skb;
skb = __netdev_alloc_skb_ip_align(priv->dev, priv->dma_buf_sz, flags);
if (!skb) {
netdev_err(priv->dev,
"%s: Rx init fails; skb is NULL\n", __func__);
return -ENOMEM;
}
priv->rx_skbuff[i] = skb;
priv->rx_skbuff_dma[i] = dma_map_single(priv->device, skb->data,
priv->dma_buf_sz,
DMA_FROM_DEVICE);
if (dma_mapping_error(priv->device, priv->rx_skbuff_dma[i])) {
netdev_err(priv->dev, "%s: DMA mapping error\n", __func__);
dev_kfree_skb_any(skb);
return -EINVAL;
}
if (priv->synopsys_id >= DWMAC_CORE_4_00)
p->des0 = cpu_to_le32(priv->rx_skbuff_dma[i]);
else
p->des2 = cpu_to_le32(priv->rx_skbuff_dma[i]);
if ((priv->hw->mode->init_desc3) &&
(priv->dma_buf_sz == BUF_SIZE_16KiB))
priv->hw->mode->init_desc3(p);
return 0;
}
static void stmmac_free_rx_buffers(struct stmmac_priv *priv, int i)
{
if (priv->rx_skbuff[i]) {
dma_unmap_single(priv->device, priv->rx_skbuff_dma[i],
priv->dma_buf_sz, DMA_FROM_DEVICE);
dev_kfree_skb_any(priv->rx_skbuff[i]);
}
priv->rx_skbuff[i] = NULL;
}
static int init_dma_desc_rings(struct net_device *dev, gfp_t flags)
{
int i;
struct stmmac_priv *priv = netdev_priv(dev);
unsigned int bfsize = 0;
int ret = -ENOMEM;
if (priv->hw->mode->set_16kib_bfsize)
bfsize = priv->hw->mode->set_16kib_bfsize(dev->mtu);
if (bfsize < BUF_SIZE_16KiB)
bfsize = stmmac_set_bfsize(dev->mtu, priv->dma_buf_sz);
priv->dma_buf_sz = bfsize;
netif_dbg(priv, probe, priv->dev,
"(%s) dma_rx_phy=0x%08x dma_tx_phy=0x%08x\n",
__func__, (u32)priv->dma_rx_phy, (u32)priv->dma_tx_phy);
netif_dbg(priv, probe, priv->dev,
"SKB addresses:\nskb\t\tskb data\tdma data\n");
for (i = 0; i < DMA_RX_SIZE; i++) {
struct dma_desc *p;
if (priv->extend_desc)
p = &((priv->dma_erx + i)->basic);
else
p = priv->dma_rx + i;
ret = stmmac_init_rx_buffers(priv, p, i, flags);
if (ret)
goto err_init_rx_buffers;
netif_dbg(priv, probe, priv->dev, "[%p]\t[%p]\t[%x]\n",
priv->rx_skbuff[i], priv->rx_skbuff[i]->data,
(unsigned int)priv->rx_skbuff_dma[i]);
}
priv->cur_rx = 0;
priv->dirty_rx = (unsigned int)(i - DMA_RX_SIZE);
buf_sz = bfsize;
if (priv->mode == STMMAC_CHAIN_MODE) {
if (priv->extend_desc) {
priv->hw->mode->init(priv->dma_erx, priv->dma_rx_phy,
DMA_RX_SIZE, 1);
priv->hw->mode->init(priv->dma_etx, priv->dma_tx_phy,
DMA_TX_SIZE, 1);
} else {
priv->hw->mode->init(priv->dma_rx, priv->dma_rx_phy,
DMA_RX_SIZE, 0);
priv->hw->mode->init(priv->dma_tx, priv->dma_tx_phy,
DMA_TX_SIZE, 0);
}
}
for (i = 0; i < DMA_TX_SIZE; i++) {
struct dma_desc *p;
if (priv->extend_desc)
p = &((priv->dma_etx + i)->basic);
else
p = priv->dma_tx + i;
if (priv->synopsys_id >= DWMAC_CORE_4_00) {
p->des0 = 0;
p->des1 = 0;
p->des2 = 0;
p->des3 = 0;
} else {
p->des2 = 0;
}
priv->tx_skbuff_dma[i].buf = 0;
priv->tx_skbuff_dma[i].map_as_page = false;
priv->tx_skbuff_dma[i].len = 0;
priv->tx_skbuff_dma[i].last_segment = false;
priv->tx_skbuff[i] = NULL;
}
priv->dirty_tx = 0;
priv->cur_tx = 0;
netdev_reset_queue(priv->dev);
stmmac_clear_descriptors(priv);
if (netif_msg_hw(priv))
stmmac_display_rings(priv);
return 0;
err_init_rx_buffers:
while (--i >= 0)
stmmac_free_rx_buffers(priv, i);
return ret;
}
static void dma_free_rx_skbufs(struct stmmac_priv *priv)
{
int i;
for (i = 0; i < DMA_RX_SIZE; i++)
stmmac_free_rx_buffers(priv, i);
}
static void dma_free_tx_skbufs(struct stmmac_priv *priv)
{
int i;
for (i = 0; i < DMA_TX_SIZE; i++) {
struct dma_desc *p;
if (priv->extend_desc)
p = &((priv->dma_etx + i)->basic);
else
p = priv->dma_tx + i;
if (priv->tx_skbuff_dma[i].buf) {
if (priv->tx_skbuff_dma[i].map_as_page)
dma_unmap_page(priv->device,
priv->tx_skbuff_dma[i].buf,
priv->tx_skbuff_dma[i].len,
DMA_TO_DEVICE);
else
dma_unmap_single(priv->device,
priv->tx_skbuff_dma[i].buf,
priv->tx_skbuff_dma[i].len,
DMA_TO_DEVICE);
}
if (priv->tx_skbuff[i] != NULL) {
dev_kfree_skb_any(priv->tx_skbuff[i]);
priv->tx_skbuff[i] = NULL;
priv->tx_skbuff_dma[i].buf = 0;
priv->tx_skbuff_dma[i].map_as_page = false;
}
}
}
static int alloc_dma_desc_resources(struct stmmac_priv *priv)
{
int ret = -ENOMEM;
priv->rx_skbuff_dma = kmalloc_array(DMA_RX_SIZE, sizeof(dma_addr_t),
GFP_KERNEL);
if (!priv->rx_skbuff_dma)
return -ENOMEM;
priv->rx_skbuff = kmalloc_array(DMA_RX_SIZE, sizeof(struct sk_buff *),
GFP_KERNEL);
if (!priv->rx_skbuff)
goto err_rx_skbuff;
priv->tx_skbuff_dma = kmalloc_array(DMA_TX_SIZE,
sizeof(*priv->tx_skbuff_dma),
GFP_KERNEL);
if (!priv->tx_skbuff_dma)
goto err_tx_skbuff_dma;
priv->tx_skbuff = kmalloc_array(DMA_TX_SIZE, sizeof(struct sk_buff *),
GFP_KERNEL);
if (!priv->tx_skbuff)
goto err_tx_skbuff;
if (priv->extend_desc) {
priv->dma_erx = dma_zalloc_coherent(priv->device, DMA_RX_SIZE *
sizeof(struct
dma_extended_desc),
&priv->dma_rx_phy,
GFP_KERNEL);
if (!priv->dma_erx)
goto err_dma;
priv->dma_etx = dma_zalloc_coherent(priv->device, DMA_TX_SIZE *
sizeof(struct
dma_extended_desc),
&priv->dma_tx_phy,
GFP_KERNEL);
if (!priv->dma_etx) {
dma_free_coherent(priv->device, DMA_RX_SIZE *
sizeof(struct dma_extended_desc),
priv->dma_erx, priv->dma_rx_phy);
goto err_dma;
}
} else {
priv->dma_rx = dma_zalloc_coherent(priv->device, DMA_RX_SIZE *
sizeof(struct dma_desc),
&priv->dma_rx_phy,
GFP_KERNEL);
if (!priv->dma_rx)
goto err_dma;
priv->dma_tx = dma_zalloc_coherent(priv->device, DMA_TX_SIZE *
sizeof(struct dma_desc),
&priv->dma_tx_phy,
GFP_KERNEL);
if (!priv->dma_tx) {
dma_free_coherent(priv->device, DMA_RX_SIZE *
sizeof(struct dma_desc),
priv->dma_rx, priv->dma_rx_phy);
goto err_dma;
}
}
return 0;
err_dma:
kfree(priv->tx_skbuff);
err_tx_skbuff:
kfree(priv->tx_skbuff_dma);
err_tx_skbuff_dma:
kfree(priv->rx_skbuff);
err_rx_skbuff:
kfree(priv->rx_skbuff_dma);
return ret;
}
static void free_dma_desc_resources(struct stmmac_priv *priv)
{
dma_free_rx_skbufs(priv);
dma_free_tx_skbufs(priv);
if (!priv->extend_desc) {
dma_free_coherent(priv->device,
DMA_TX_SIZE * sizeof(struct dma_desc),
priv->dma_tx, priv->dma_tx_phy);
dma_free_coherent(priv->device,
DMA_RX_SIZE * sizeof(struct dma_desc),
priv->dma_rx, priv->dma_rx_phy);
} else {
dma_free_coherent(priv->device, DMA_TX_SIZE *
sizeof(struct dma_extended_desc),
priv->dma_etx, priv->dma_tx_phy);
dma_free_coherent(priv->device, DMA_RX_SIZE *
sizeof(struct dma_extended_desc),
priv->dma_erx, priv->dma_rx_phy);
}
kfree(priv->rx_skbuff_dma);
kfree(priv->rx_skbuff);
kfree(priv->tx_skbuff_dma);
kfree(priv->tx_skbuff);
}
static void stmmac_dma_operation_mode(struct stmmac_priv *priv)
{
int rxfifosz = priv->plat->rx_fifo_size;
if (priv->plat->force_thresh_dma_mode)
priv->hw->dma->dma_mode(priv->ioaddr, tc, tc, rxfifosz);
else if (priv->plat->force_sf_dma_mode || priv->plat->tx_coe) {
priv->hw->dma->dma_mode(priv->ioaddr, SF_DMA_MODE, SF_DMA_MODE,
rxfifosz);
priv->xstats.threshold = SF_DMA_MODE;
} else
priv->hw->dma->dma_mode(priv->ioaddr, tc, SF_DMA_MODE,
rxfifosz);
}
static void stmmac_tx_clean(struct stmmac_priv *priv)
{
unsigned int bytes_compl = 0, pkts_compl = 0;
unsigned int entry = priv->dirty_tx;
netif_tx_lock(priv->dev);
priv->xstats.tx_clean++;
while (entry != priv->cur_tx) {
struct sk_buff *skb = priv->tx_skbuff[entry];
struct dma_desc *p;
int status;
if (priv->extend_desc)
p = (struct dma_desc *)(priv->dma_etx + entry);
else
p = priv->dma_tx + entry;
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
if (likely(priv->tx_skbuff_dma[entry].buf)) {
if (priv->tx_skbuff_dma[entry].map_as_page)
dma_unmap_page(priv->device,
priv->tx_skbuff_dma[entry].buf,
priv->tx_skbuff_dma[entry].len,
DMA_TO_DEVICE);
else
dma_unmap_single(priv->device,
priv->tx_skbuff_dma[entry].buf,
priv->tx_skbuff_dma[entry].len,
DMA_TO_DEVICE);
priv->tx_skbuff_dma[entry].buf = 0;
priv->tx_skbuff_dma[entry].len = 0;
priv->tx_skbuff_dma[entry].map_as_page = false;
}
if (priv->hw->mode->clean_desc3)
priv->hw->mode->clean_desc3(priv, p);
priv->tx_skbuff_dma[entry].last_segment = false;
priv->tx_skbuff_dma[entry].is_jumbo = false;
if (likely(skb != NULL)) {
pkts_compl++;
bytes_compl += skb->len;
dev_consume_skb_any(skb);
priv->tx_skbuff[entry] = NULL;
}
priv->hw->desc->release_tx_desc(p, priv->mode);
entry = STMMAC_GET_ENTRY(entry, DMA_TX_SIZE);
}
priv->dirty_tx = entry;
netdev_completed_queue(priv->dev, pkts_compl, bytes_compl);
if (unlikely(netif_queue_stopped(priv->dev) &&
stmmac_tx_avail(priv) > STMMAC_TX_THRESH)) {
netif_dbg(priv, tx_done, priv->dev,
"%s: restart transmit\n", __func__);
netif_wake_queue(priv->dev);
}
if ((priv->eee_enabled) && (!priv->tx_path_in_lpi_mode)) {
stmmac_enable_eee_mode(priv);
mod_timer(&priv->eee_ctrl_timer, STMMAC_LPI_T(eee_timer));
}
netif_tx_unlock(priv->dev);
}
static inline void stmmac_enable_dma_irq(struct stmmac_priv *priv)
{
priv->hw->dma->enable_dma_irq(priv->ioaddr);
}
static inline void stmmac_disable_dma_irq(struct stmmac_priv *priv)
{
priv->hw->dma->disable_dma_irq(priv->ioaddr);
}
static void stmmac_tx_err(struct stmmac_priv *priv)
{
int i;
netif_stop_queue(priv->dev);
priv->hw->dma->stop_tx(priv->ioaddr);
dma_free_tx_skbufs(priv);
for (i = 0; i < DMA_TX_SIZE; i++)
if (priv->extend_desc)
priv->hw->desc->init_tx_desc(&priv->dma_etx[i].basic,
priv->mode,
(i == DMA_TX_SIZE - 1));
else
priv->hw->desc->init_tx_desc(&priv->dma_tx[i],
priv->mode,
(i == DMA_TX_SIZE - 1));
priv->dirty_tx = 0;
priv->cur_tx = 0;
netdev_reset_queue(priv->dev);
priv->hw->dma->start_tx(priv->ioaddr);
priv->dev->stats.tx_errors++;
netif_wake_queue(priv->dev);
}
static void stmmac_dma_interrupt(struct stmmac_priv *priv)
{
int status;
int rxfifosz = priv->plat->rx_fifo_size;
status = priv->hw->dma->dma_interrupt(priv->ioaddr, &priv->xstats);
if (likely((status & handle_rx)) || (status & handle_tx)) {
if (likely(napi_schedule_prep(&priv->napi))) {
stmmac_disable_dma_irq(priv);
__napi_schedule(&priv->napi);
}
}
if (unlikely(status & tx_hard_error_bump_tc)) {
if (unlikely(priv->xstats.threshold != SF_DMA_MODE) &&
(tc <= 256)) {
tc += 64;
if (priv->plat->force_thresh_dma_mode)
priv->hw->dma->dma_mode(priv->ioaddr, tc, tc,
rxfifosz);
else
priv->hw->dma->dma_mode(priv->ioaddr, tc,
SF_DMA_MODE, rxfifosz);
priv->xstats.threshold = tc;
}
} else if (unlikely(status == tx_hard_error))
stmmac_tx_err(priv);
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
priv->hw->dma->init(priv->ioaddr, priv->plat->dma_cfg,
priv->dma_tx_phy, priv->dma_rx_phy, atds);
if (priv->synopsys_id >= DWMAC_CORE_4_00) {
priv->rx_tail_addr = priv->dma_rx_phy +
(DMA_RX_SIZE * sizeof(struct dma_desc));
priv->hw->dma->set_rx_tail_ptr(priv->ioaddr, priv->rx_tail_addr,
STMMAC_CHAN0);
priv->tx_tail_addr = priv->dma_tx_phy +
(DMA_TX_SIZE * sizeof(struct dma_desc));
priv->hw->dma->set_tx_tail_ptr(priv->ioaddr, priv->tx_tail_addr,
STMMAC_CHAN0);
}
if (priv->plat->axi && priv->hw->dma->axi)
priv->hw->dma->axi(priv->ioaddr, priv->plat->axi);
return ret;
}
static void stmmac_tx_timer(unsigned long data)
{
struct stmmac_priv *priv = (struct stmmac_priv *)data;
stmmac_tx_clean(priv);
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
static int stmmac_hw_setup(struct net_device *dev, bool init_ptp)
{
struct stmmac_priv *priv = netdev_priv(dev);
int ret;
ret = stmmac_init_dma_engine(priv);
if (ret < 0) {
netdev_err(priv->dev, "%s: DMA engine initialization failed\n",
__func__);
return ret;
}
priv->hw->mac->set_umac_addr(priv->hw, dev->dev_addr, 0);
if (priv->plat->bus_setup)
priv->plat->bus_setup(priv->ioaddr);
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
ret = priv->hw->mac->rx_ipc(priv->hw);
if (!ret) {
netdev_warn(priv->dev, "RX IPC Checksum Offload disabled\n");
priv->plat->rx_coe = STMMAC_RX_COE_NONE;
priv->hw->rx_csum = 0;
}
if (priv->synopsys_id >= DWMAC_CORE_4_00)
stmmac_dwmac4_set_mac(priv->ioaddr, true);
else
stmmac_set_mac(priv->ioaddr, true);
stmmac_dma_operation_mode(priv);
stmmac_mmc_setup(priv);
if (init_ptp) {
ret = stmmac_init_ptp(priv);
if (ret)
netdev_warn(priv->dev, "fail to init PTP.\n");
}
#ifdef CONFIG_DEBUG_FS
ret = stmmac_init_fs(dev);
if (ret < 0)
netdev_warn(priv->dev, "%s: failed debugFS registration\n",
__func__);
#endif
netdev_dbg(priv->dev, "DMA RX/TX processes started...\n");
priv->hw->dma->start_tx(priv->ioaddr);
priv->hw->dma->start_rx(priv->ioaddr);
if (netif_msg_hw(priv)) {
priv->hw->mac->dump_regs(priv->hw);
priv->hw->dma->dump_regs(priv->ioaddr);
}
priv->tx_lpi_timer = STMMAC_DEFAULT_TWT_LS;
if ((priv->use_riwt) && (priv->hw->dma->rx_watchdog)) {
priv->rx_riwt = MAX_DMA_RIWT;
priv->hw->dma->rx_watchdog(priv->ioaddr, MAX_DMA_RIWT);
}
if (priv->hw->pcs && priv->hw->mac->pcs_ctrl_ane)
priv->hw->mac->pcs_ctrl_ane(priv->hw, 1, priv->hw->ps, 0);
if (priv->hw->dma->set_tx_ring_len)
priv->hw->dma->set_tx_ring_len(priv->ioaddr,
(DMA_TX_SIZE - 1));
if (priv->hw->dma->set_rx_ring_len)
priv->hw->dma->set_rx_ring_len(priv->ioaddr,
(DMA_RX_SIZE - 1));
if (priv->tso)
priv->hw->dma->enable_tso(priv->ioaddr, 1, STMMAC_CHAN0);
return 0;
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
goto init_error;
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
napi_enable(&priv->napi);
netif_start_queue(dev);
return 0;
lpiirq_error:
if (priv->wol_irq != dev->irq)
free_irq(priv->wol_irq, dev);
wolirq_error:
free_irq(dev->irq, dev);
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
netif_stop_queue(dev);
napi_disable(&priv->napi);
del_timer_sync(&priv->txtimer);
free_irq(dev->irq, dev);
if (priv->wol_irq != dev->irq)
free_irq(priv->wol_irq, dev);
if (priv->lpi_irq > 0)
free_irq(priv->lpi_irq, dev);
priv->hw->dma->stop_tx(priv->ioaddr);
priv->hw->dma->stop_rx(priv->ioaddr);
free_dma_desc_resources(priv);
stmmac_set_mac(priv->ioaddr, false);
netif_carrier_off(dev);
#ifdef CONFIG_DEBUG_FS
stmmac_exit_fs(dev);
#endif
stmmac_release_ptp(priv);
return 0;
}
static void stmmac_tso_allocator(struct stmmac_priv *priv, unsigned int des,
int total_len, bool last_segment)
{
struct dma_desc *desc;
int tmp_len;
u32 buff_size;
tmp_len = total_len;
while (tmp_len > 0) {
priv->cur_tx = STMMAC_GET_ENTRY(priv->cur_tx, DMA_TX_SIZE);
desc = priv->dma_tx + priv->cur_tx;
desc->des0 = cpu_to_le32(des + (total_len - tmp_len));
buff_size = tmp_len >= TSO_MAX_BUFF_SIZE ?
TSO_MAX_BUFF_SIZE : tmp_len;
priv->hw->desc->prepare_tso_tx_desc(desc, 0, buff_size,
0, 1,
(last_segment) && (buff_size < TSO_MAX_BUFF_SIZE),
0, 0);
tmp_len -= TSO_MAX_BUFF_SIZE;
}
}
static netdev_tx_t stmmac_tso_xmit(struct sk_buff *skb, struct net_device *dev)
{
u32 pay_len, mss;
int tmp_pay_len = 0;
struct stmmac_priv *priv = netdev_priv(dev);
int nfrags = skb_shinfo(skb)->nr_frags;
unsigned int first_entry, des;
struct dma_desc *desc, *first, *mss_desc = NULL;
u8 proto_hdr_len;
int i;
proto_hdr_len = skb_transport_offset(skb) + tcp_hdrlen(skb);
if (unlikely(stmmac_tx_avail(priv) <
(((skb->len - proto_hdr_len) / TSO_MAX_BUFF_SIZE + 1)))) {
if (!netif_queue_stopped(dev)) {
netif_stop_queue(dev);
netdev_err(priv->dev,
"%s: Tx Ring full when queue awake\n",
__func__);
}
return NETDEV_TX_BUSY;
}
pay_len = skb_headlen(skb) - proto_hdr_len;
mss = skb_shinfo(skb)->gso_size;
if (mss != priv->mss) {
mss_desc = priv->dma_tx + priv->cur_tx;
priv->hw->desc->set_mss(mss_desc, mss);
priv->mss = mss;
priv->cur_tx = STMMAC_GET_ENTRY(priv->cur_tx, DMA_TX_SIZE);
}
if (netif_msg_tx_queued(priv)) {
pr_info("%s: tcphdrlen %d, hdr_len %d, pay_len %d, mss %d\n",
__func__, tcp_hdrlen(skb), proto_hdr_len, pay_len, mss);
pr_info("\tskb->len %d, skb->data_len %d\n", skb->len,
skb->data_len);
}
first_entry = priv->cur_tx;
desc = priv->dma_tx + first_entry;
first = desc;
des = dma_map_single(priv->device, skb->data, skb_headlen(skb),
DMA_TO_DEVICE);
if (dma_mapping_error(priv->device, des))
goto dma_map_err;
priv->tx_skbuff_dma[first_entry].buf = des;
priv->tx_skbuff_dma[first_entry].len = skb_headlen(skb);
priv->tx_skbuff[first_entry] = skb;
first->des0 = cpu_to_le32(des);
if (pay_len)
first->des1 = cpu_to_le32(des + proto_hdr_len);
tmp_pay_len = pay_len - TSO_MAX_BUFF_SIZE;
stmmac_tso_allocator(priv, des, tmp_pay_len, (nfrags == 0));
for (i = 0; i < nfrags; i++) {
const skb_frag_t *frag = &skb_shinfo(skb)->frags[i];
des = skb_frag_dma_map(priv->device, frag, 0,
skb_frag_size(frag),
DMA_TO_DEVICE);
stmmac_tso_allocator(priv, des, skb_frag_size(frag),
(i == nfrags - 1));
priv->tx_skbuff_dma[priv->cur_tx].buf = des;
priv->tx_skbuff_dma[priv->cur_tx].len = skb_frag_size(frag);
priv->tx_skbuff[priv->cur_tx] = NULL;
priv->tx_skbuff_dma[priv->cur_tx].map_as_page = true;
}
priv->tx_skbuff_dma[priv->cur_tx].last_segment = true;
priv->cur_tx = STMMAC_GET_ENTRY(priv->cur_tx, DMA_TX_SIZE);
if (unlikely(stmmac_tx_avail(priv) <= (MAX_SKB_FRAGS + 1))) {
netif_dbg(priv, hw, priv->dev, "%s: stop transmitted packets\n",
__func__);
netif_stop_queue(dev);
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
if (!priv->hwts_tx_en)
skb_tx_timestamp(skb);
if (unlikely((skb_shinfo(skb)->tx_flags & SKBTX_HW_TSTAMP) &&
priv->hwts_tx_en)) {
skb_shinfo(skb)->tx_flags |= SKBTX_IN_PROGRESS;
priv->hw->desc->enable_tx_timestamp(first);
}
priv->hw->desc->prepare_tso_tx_desc(first, 1,
proto_hdr_len,
pay_len,
1, priv->tx_skbuff_dma[first_entry].last_segment,
tcp_hdrlen(skb) / 4, (skb->len - proto_hdr_len));
if (mss_desc)
priv->hw->desc->set_tx_owner(mss_desc);
dma_wmb();
if (netif_msg_pktdata(priv)) {
pr_info("%s: curr=%d dirty=%d f=%d, e=%d, f_p=%p, nfrags %d\n",
__func__, priv->cur_tx, priv->dirty_tx, first_entry,
priv->cur_tx, first, nfrags);
priv->hw->desc->display_ring((void *)priv->dma_tx, DMA_TX_SIZE,
0);
pr_info(">>> frame to be transmitted: ");
print_pkt(skb->data, skb_headlen(skb));
}
netdev_sent_queue(dev, skb->len);
priv->hw->dma->set_tx_tail_ptr(priv->ioaddr, priv->tx_tail_addr,
STMMAC_CHAN0);
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
int nfrags = skb_shinfo(skb)->nr_frags;
unsigned int entry, first_entry;
struct dma_desc *desc, *first;
unsigned int enh_desc;
unsigned int des;
if (skb_is_gso(skb) && priv->tso) {
if (ip_hdr(skb)->protocol == IPPROTO_TCP)
return stmmac_tso_xmit(skb, dev);
}
if (unlikely(stmmac_tx_avail(priv) < nfrags + 1)) {
if (!netif_queue_stopped(dev)) {
netif_stop_queue(dev);
netdev_err(priv->dev,
"%s: Tx Ring full when queue awake\n",
__func__);
}
return NETDEV_TX_BUSY;
}
if (priv->tx_path_in_lpi_mode)
stmmac_disable_eee_mode(priv);
entry = priv->cur_tx;
first_entry = entry;
csum_insertion = (skb->ip_summed == CHECKSUM_PARTIAL);
if (likely(priv->extend_desc))
desc = (struct dma_desc *)(priv->dma_etx + entry);
else
desc = priv->dma_tx + entry;
first = desc;
priv->tx_skbuff[first_entry] = skb;
enh_desc = priv->plat->enh_desc;
if (enh_desc)
is_jumbo = priv->hw->mode->is_jumbo_frm(skb->len, enh_desc);
if (unlikely(is_jumbo) && likely(priv->synopsys_id <
DWMAC_CORE_4_00)) {
entry = priv->hw->mode->jumbo_frm(priv, skb, csum_insertion);
if (unlikely(entry < 0))
goto dma_map_err;
}
for (i = 0; i < nfrags; i++) {
const skb_frag_t *frag = &skb_shinfo(skb)->frags[i];
int len = skb_frag_size(frag);
bool last_segment = (i == (nfrags - 1));
entry = STMMAC_GET_ENTRY(entry, DMA_TX_SIZE);
if (likely(priv->extend_desc))
desc = (struct dma_desc *)(priv->dma_etx + entry);
else
desc = priv->dma_tx + entry;
des = skb_frag_dma_map(priv->device, frag, 0, len,
DMA_TO_DEVICE);
if (dma_mapping_error(priv->device, des))
goto dma_map_err;
priv->tx_skbuff[entry] = NULL;
priv->tx_skbuff_dma[entry].buf = des;
if (unlikely(priv->synopsys_id >= DWMAC_CORE_4_00))
desc->des0 = cpu_to_le32(des);
else
desc->des2 = cpu_to_le32(des);
priv->tx_skbuff_dma[entry].map_as_page = true;
priv->tx_skbuff_dma[entry].len = len;
priv->tx_skbuff_dma[entry].last_segment = last_segment;
priv->hw->desc->prepare_tx_desc(desc, 0, len, csum_insertion,
priv->mode, 1, last_segment);
}
entry = STMMAC_GET_ENTRY(entry, DMA_TX_SIZE);
priv->cur_tx = entry;
if (netif_msg_pktdata(priv)) {
void *tx_head;
netdev_dbg(priv->dev,
"%s: curr=%d dirty=%d f=%d, e=%d, first=%p, nfrags=%d",
__func__, priv->cur_tx, priv->dirty_tx, first_entry,
entry, first, nfrags);
if (priv->extend_desc)
tx_head = (void *)priv->dma_etx;
else
tx_head = (void *)priv->dma_tx;
priv->hw->desc->display_ring(tx_head, DMA_TX_SIZE, false);
netdev_dbg(priv->dev, ">>> frame to be transmitted: ");
print_pkt(skb->data, skb->len);
}
if (unlikely(stmmac_tx_avail(priv) <= (MAX_SKB_FRAGS + 1))) {
netif_dbg(priv, hw, priv->dev, "%s: stop transmitted packets\n",
__func__);
netif_stop_queue(dev);
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
if (!priv->hwts_tx_en)
skb_tx_timestamp(skb);
if (likely(!is_jumbo)) {
bool last_segment = (nfrags == 0);
des = dma_map_single(priv->device, skb->data,
nopaged_len, DMA_TO_DEVICE);
if (dma_mapping_error(priv->device, des))
goto dma_map_err;
priv->tx_skbuff_dma[first_entry].buf = des;
if (unlikely(priv->synopsys_id >= DWMAC_CORE_4_00))
first->des0 = cpu_to_le32(des);
else
first->des2 = cpu_to_le32(des);
priv->tx_skbuff_dma[first_entry].len = nopaged_len;
priv->tx_skbuff_dma[first_entry].last_segment = last_segment;
if (unlikely((skb_shinfo(skb)->tx_flags & SKBTX_HW_TSTAMP) &&
priv->hwts_tx_en)) {
skb_shinfo(skb)->tx_flags |= SKBTX_IN_PROGRESS;
priv->hw->desc->enable_tx_timestamp(first);
}
priv->hw->desc->prepare_tx_desc(first, 1, nopaged_len,
csum_insertion, priv->mode, 1,
last_segment);
dma_wmb();
}
netdev_sent_queue(dev, skb->len);
if (priv->synopsys_id < DWMAC_CORE_4_00)
priv->hw->dma->enable_dma_transmission(priv->ioaddr);
else
priv->hw->dma->set_tx_tail_ptr(priv->ioaddr, priv->tx_tail_addr,
STMMAC_CHAN0);
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
static inline int stmmac_rx_threshold_count(struct stmmac_priv *priv)
{
if (priv->rx_zeroc_thresh < STMMAC_RX_THRESH)
return 0;
return 1;
}
static inline void stmmac_rx_refill(struct stmmac_priv *priv)
{
int bfsize = priv->dma_buf_sz;
unsigned int entry = priv->dirty_rx;
int dirty = stmmac_rx_dirty(priv);
while (dirty-- > 0) {
struct dma_desc *p;
if (priv->extend_desc)
p = (struct dma_desc *)(priv->dma_erx + entry);
else
p = priv->dma_rx + entry;
if (likely(priv->rx_skbuff[entry] == NULL)) {
struct sk_buff *skb;
skb = netdev_alloc_skb_ip_align(priv->dev, bfsize);
if (unlikely(!skb)) {
priv->rx_zeroc_thresh = STMMAC_RX_THRESH;
if (unlikely(net_ratelimit()))
dev_err(priv->device,
"fail to alloc skb entry %d\n",
entry);
break;
}
priv->rx_skbuff[entry] = skb;
priv->rx_skbuff_dma[entry] =
dma_map_single(priv->device, skb->data, bfsize,
DMA_FROM_DEVICE);
if (dma_mapping_error(priv->device,
priv->rx_skbuff_dma[entry])) {
netdev_err(priv->dev, "Rx DMA map failed\n");
dev_kfree_skb(skb);
break;
}
if (unlikely(priv->synopsys_id >= DWMAC_CORE_4_00)) {
p->des0 = cpu_to_le32(priv->rx_skbuff_dma[entry]);
p->des1 = 0;
} else {
p->des2 = cpu_to_le32(priv->rx_skbuff_dma[entry]);
}
if (priv->hw->mode->refill_desc3)
priv->hw->mode->refill_desc3(priv, p);
if (priv->rx_zeroc_thresh > 0)
priv->rx_zeroc_thresh--;
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
priv->dirty_rx = entry;
}
static int stmmac_rx(struct stmmac_priv *priv, int limit)
{
unsigned int entry = priv->cur_rx;
unsigned int next_entry;
unsigned int count = 0;
int coe = priv->hw->rx_csum;
if (netif_msg_rx_status(priv)) {
void *rx_head;
netdev_dbg(priv->dev, "%s: descriptor ring:\n", __func__);
if (priv->extend_desc)
rx_head = (void *)priv->dma_erx;
else
rx_head = (void *)priv->dma_rx;
priv->hw->desc->display_ring(rx_head, DMA_RX_SIZE, true);
}
while (count < limit) {
int status;
struct dma_desc *p;
struct dma_desc *np;
if (priv->extend_desc)
p = (struct dma_desc *)(priv->dma_erx + entry);
else
p = priv->dma_rx + entry;
status = priv->hw->desc->rx_status(&priv->dev->stats,
&priv->xstats, p);
if (unlikely(status & dma_own))
break;
count++;
priv->cur_rx = STMMAC_GET_ENTRY(priv->cur_rx, DMA_RX_SIZE);
next_entry = priv->cur_rx;
if (priv->extend_desc)
np = (struct dma_desc *)(priv->dma_erx + next_entry);
else
np = priv->dma_rx + next_entry;
prefetch(np);
if ((priv->extend_desc) && (priv->hw->desc->rx_extended_status))
priv->hw->desc->rx_extended_status(&priv->dev->stats,
&priv->xstats,
priv->dma_erx +
entry);
if (unlikely(status == discard_frame)) {
priv->dev->stats.rx_errors++;
if (priv->hwts_rx_en && !priv->extend_desc) {
priv->rx_skbuff[entry] = NULL;
dma_unmap_single(priv->device,
priv->rx_skbuff_dma[entry],
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
stmmac_rx_threshold_count(priv)))) {
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
priv->rx_skbuff_dma
[entry], frame_len,
DMA_FROM_DEVICE);
skb_copy_to_linear_data(skb,
priv->
rx_skbuff[entry]->data,
frame_len);
skb_put(skb, frame_len);
dma_sync_single_for_device(priv->device,
priv->rx_skbuff_dma
[entry], frame_len,
DMA_FROM_DEVICE);
} else {
skb = priv->rx_skbuff[entry];
if (unlikely(!skb)) {
netdev_err(priv->dev,
"%s: Inconsistent Rx chain\n",
priv->dev->name);
priv->dev->stats.rx_dropped++;
break;
}
prefetch(skb->data - NET_IP_ALIGN);
priv->rx_skbuff[entry] = NULL;
priv->rx_zeroc_thresh++;
skb_put(skb, frame_len);
dma_unmap_single(priv->device,
priv->rx_skbuff_dma[entry],
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
napi_gro_receive(&priv->napi, skb);
priv->dev->stats.rx_packets++;
priv->dev->stats.rx_bytes += frame_len;
}
entry = next_entry;
}
stmmac_rx_refill(priv);
priv->xstats.rx_pkt_n += count;
return count;
}
static int stmmac_poll(struct napi_struct *napi, int budget)
{
struct stmmac_priv *priv = container_of(napi, struct stmmac_priv, napi);
int work_done = 0;
priv->xstats.napi_poll++;
stmmac_tx_clean(priv);
work_done = stmmac_rx(priv, budget);
if (work_done < budget) {
napi_complete(napi);
stmmac_enable_dma_irq(priv);
}
return work_done;
}
static void stmmac_tx_timeout(struct net_device *dev)
{
struct stmmac_priv *priv = netdev_priv(dev);
stmmac_tx_err(priv);
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
if (status & CORE_IRQ_MTL_RX_OVERFLOW && priv->hw->dma->set_rx_tail_ptr)
priv->hw->dma->set_rx_tail_ptr(priv->ioaddr,
priv->rx_tail_addr,
STMMAC_CHAN0);
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
u64 x;
if (extend_desc) {
x = *(u64 *) ep;
seq_printf(seq, "%d [0x%x]: 0x%x 0x%x 0x%x 0x%x\n",
i, (unsigned int)virt_to_phys(ep),
le32_to_cpu(ep->basic.des0),
le32_to_cpu(ep->basic.des1),
le32_to_cpu(ep->basic.des2),
le32_to_cpu(ep->basic.des3));
ep++;
} else {
x = *(u64 *) p;
seq_printf(seq, "%d [0x%x]: 0x%x 0x%x 0x%x 0x%x\n",
i, (unsigned int)virt_to_phys(ep),
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
if (priv->extend_desc) {
seq_printf(seq, "Extended RX descriptor ring:\n");
sysfs_display_ring((void *)priv->dma_erx, DMA_RX_SIZE, 1, seq);
seq_printf(seq, "Extended TX descriptor ring:\n");
sysfs_display_ring((void *)priv->dma_etx, DMA_TX_SIZE, 1, seq);
} else {
seq_printf(seq, "RX descriptor ring:\n");
sysfs_display_ring((void *)priv->dma_rx, DMA_RX_SIZE, 0, seq);
seq_printf(seq, "TX descriptor ring:\n");
sysfs_display_ring((void *)priv->dma_tx, DMA_TX_SIZE, 0, seq);
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
seq_printf(seq, "\tPCS (TBI/SGMII/RTBI PHY interfatces): %s\n",
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
if (priv->plat->has_gmac) {
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
int ret = 0;
struct net_device *ndev = NULL;
struct stmmac_priv *priv;
ndev = alloc_etherdev(sizeof(struct stmmac_priv));
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
priv->stmmac_clk = devm_clk_get(priv->device, STMMAC_RESOURCE_NAME);
if (IS_ERR(priv->stmmac_clk)) {
netdev_warn(priv->dev, "%s: warning: cannot get CSR clock\n",
__func__);
if (!priv->plat->clk_csr) {
ret = PTR_ERR(priv->stmmac_clk);
goto error_clk_get;
} else {
priv->stmmac_clk = NULL;
}
}
clk_prepare_enable(priv->stmmac_clk);
priv->pclk = devm_clk_get(priv->device, "pclk");
if (IS_ERR(priv->pclk)) {
if (PTR_ERR(priv->pclk) == -EPROBE_DEFER) {
ret = -EPROBE_DEFER;
goto error_pclk_get;
}
priv->pclk = NULL;
}
clk_prepare_enable(priv->pclk);
priv->stmmac_rst = devm_reset_control_get(priv->device,
STMMAC_RESOURCE_NAME);
if (IS_ERR(priv->stmmac_rst)) {
if (PTR_ERR(priv->stmmac_rst) == -EPROBE_DEFER) {
ret = -EPROBE_DEFER;
goto error_hw_init;
}
dev_info(priv->device, "no reset control found\n");
priv->stmmac_rst = NULL;
}
if (priv->stmmac_rst)
reset_control_deassert(priv->stmmac_rst);
ret = stmmac_hw_init(priv);
if (ret)
goto error_hw_init;
ndev->netdev_ops = &stmmac_netdev_ops;
ndev->hw_features = NETIF_F_SG | NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM |
NETIF_F_RXCSUM;
if ((priv->plat->tso_en) && (priv->dma_cap.tsoen)) {
ndev->hw_features |= NETIF_F_TSO;
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
netif_napi_add(ndev, &priv->napi, stmmac_poll, 64);
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
netif_napi_del(&priv->napi);
error_hw_init:
clk_disable_unprepare(priv->pclk);
error_pclk_get:
clk_disable_unprepare(priv->stmmac_clk);
error_clk_get:
free_netdev(ndev);
return ret;
}
int stmmac_dvr_remove(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
struct stmmac_priv *priv = netdev_priv(ndev);
netdev_info(priv->dev, "%s: removing driver", __func__);
priv->hw->dma->stop_rx(priv->ioaddr);
priv->hw->dma->stop_tx(priv->ioaddr);
stmmac_set_mac(priv->ioaddr, false);
netif_carrier_off(ndev);
unregister_netdev(ndev);
if (priv->stmmac_rst)
reset_control_assert(priv->stmmac_rst);
clk_disable_unprepare(priv->pclk);
clk_disable_unprepare(priv->stmmac_clk);
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
netif_stop_queue(ndev);
napi_disable(&priv->napi);
priv->hw->dma->stop_tx(priv->ioaddr);
priv->hw->dma->stop_rx(priv->ioaddr);
if (device_may_wakeup(priv->device)) {
priv->hw->mac->pmt(priv->hw, priv->wolopts);
priv->irq_wake = 1;
} else {
stmmac_set_mac(priv->ioaddr, false);
pinctrl_pm_select_sleep_state(priv->device);
clk_disable(priv->pclk);
clk_disable(priv->stmmac_clk);
}
spin_unlock_irqrestore(&priv->lock, flags);
priv->oldlink = 0;
priv->speed = 0;
priv->oldduplex = -1;
return 0;
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
clk_enable(priv->stmmac_clk);
clk_enable(priv->pclk);
if (priv->mii)
stmmac_mdio_reset(priv->mii);
}
netif_device_attach(ndev);
spin_lock_irqsave(&priv->lock, flags);
priv->cur_rx = 0;
priv->dirty_rx = 0;
priv->dirty_tx = 0;
priv->cur_tx = 0;
priv->mss = 0;
stmmac_clear_descriptors(priv);
stmmac_hw_setup(ndev, false);
stmmac_init_tx_coalesce(priv);
stmmac_set_rx_mode(ndev);
napi_enable(&priv->napi);
netif_start_queue(ndev);
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
