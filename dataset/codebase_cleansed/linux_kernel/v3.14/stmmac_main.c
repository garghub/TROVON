static void stmmac_verify_args(void)
{
if (unlikely(watchdog < 0))
watchdog = TX_TIMEO;
if (unlikely(dma_rxsize < 0))
dma_rxsize = DMA_RX_SIZE;
if (unlikely(dma_txsize < 0))
dma_txsize = DMA_TX_SIZE;
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
int j;
pr_debug("len = %d byte, buf addr: 0x%p", len, buf);
for (j = 0; j < len; j++) {
if ((j % 16) == 0)
pr_debug("\n %03x:", j);
pr_debug(" %02x", buf[j]);
}
pr_debug("\n");
}
static inline u32 stmmac_tx_avail(struct stmmac_priv *priv)
{
return priv->dirty_tx + priv->dma_tx_size - priv->cur_tx - 1;
}
static inline void stmmac_hw_fix_mac_speed(struct stmmac_priv *priv)
{
struct phy_device *phydev = priv->phydev;
if (likely(priv->plat->fix_mac_speed))
priv->plat->fix_mac_speed(priv->plat->bsp_priv, phydev->speed);
}
static void stmmac_enable_eee_mode(struct stmmac_priv *priv)
{
if ((priv->dirty_tx == priv->cur_tx) &&
(priv->tx_path_in_lpi_mode == false))
priv->hw->mac->set_eee_mode(priv->ioaddr);
}
void stmmac_disable_eee_mode(struct stmmac_priv *priv)
{
priv->hw->mac->reset_eee_mode(priv->ioaddr);
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
bool ret = false;
if ((priv->pcs == STMMAC_PCS_RGMII) || (priv->pcs == STMMAC_PCS_TBI) ||
(priv->pcs == STMMAC_PCS_RTBI))
goto out;
if (priv->dma_cap.eee) {
int tx_lpi_timer = priv->tx_lpi_timer;
if (phy_init_eee(priv->phydev, 1)) {
if (priv->eee_active) {
pr_debug("stmmac: disable EEE\n");
del_timer_sync(&priv->eee_ctrl_timer);
priv->hw->mac->set_eee_timer(priv->ioaddr, 0,
tx_lpi_timer);
}
priv->eee_active = 0;
goto out;
}
if (!priv->eee_active) {
priv->eee_active = 1;
init_timer(&priv->eee_ctrl_timer);
priv->eee_ctrl_timer.function = stmmac_eee_ctrl_timer;
priv->eee_ctrl_timer.data = (unsigned long)priv;
priv->eee_ctrl_timer.expires = STMMAC_LPI_T(eee_timer);
add_timer(&priv->eee_ctrl_timer);
priv->hw->mac->set_eee_timer(priv->ioaddr,
STMMAC_DEFAULT_LIT_LS,
tx_lpi_timer);
} else
priv->hw->mac->set_eee_pls(priv->ioaddr,
priv->phydev->link);
pr_debug("stmmac: Energy-Efficient Ethernet initialized\n");
ret = true;
}
out:
return ret;
}
static void stmmac_get_tx_hwtstamp(struct stmmac_priv *priv,
unsigned int entry, struct sk_buff *skb)
{
struct skb_shared_hwtstamps shhwtstamp;
u64 ns;
void *desc = NULL;
if (!priv->hwts_tx_en)
return;
if (likely(!skb || !(skb_shinfo(skb)->tx_flags & SKBTX_IN_PROGRESS)))
return;
if (priv->adv_ts)
desc = (priv->dma_etx + entry);
else
desc = (priv->dma_tx + entry);
if (!priv->hw->desc->get_tx_timestamp_status((struct dma_desc *)desc))
return;
ns = priv->hw->desc->get_timestamp(desc, priv->adv_ts);
memset(&shhwtstamp, 0, sizeof(struct skb_shared_hwtstamps));
shhwtstamp.hwtstamp = ns_to_ktime(ns);
skb_tstamp_tx(skb, &shhwtstamp);
return;
}
static void stmmac_get_rx_hwtstamp(struct stmmac_priv *priv,
unsigned int entry, struct sk_buff *skb)
{
struct skb_shared_hwtstamps *shhwtstamp = NULL;
u64 ns;
void *desc = NULL;
if (!priv->hwts_rx_en)
return;
if (priv->adv_ts)
desc = (priv->dma_erx + entry);
else
desc = (priv->dma_rx + entry);
if (!priv->hw->desc->get_rx_timestamp_status(desc, priv->adv_ts))
return;
ns = priv->hw->desc->get_timestamp(desc, priv->adv_ts);
shhwtstamp = skb_hwtstamps(skb);
memset(shhwtstamp, 0, sizeof(struct skb_shared_hwtstamps));
shhwtstamp->hwtstamp = ns_to_ktime(ns);
}
static int stmmac_hwtstamp_ioctl(struct net_device *dev, struct ifreq *ifr)
{
struct stmmac_priv *priv = netdev_priv(dev);
struct hwtstamp_config config;
struct timespec now;
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
if (!(priv->dma_cap.time_stamp || priv->adv_ts)) {
netdev_alert(priv->dev, "No support for HW time stamping\n");
priv->hwts_tx_en = 0;
priv->hwts_rx_en = 0;
return -EOPNOTSUPP;
}
if (copy_from_user(&config, ifr->ifr_data,
sizeof(struct hwtstamp_config)))
return -EFAULT;
pr_debug("%s config flags:0x%x, tx_type:0x%x, rx_filter:0x%x\n",
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
priv->hw->ptp->config_hw_tstamping(priv->ioaddr, 0);
else {
value = (PTP_TCR_TSENA | PTP_TCR_TSCFUPDT | PTP_TCR_TSCTRLSSR |
tstamp_all | ptp_v2 | ptp_over_ethernet |
ptp_over_ipv6_udp | ptp_over_ipv4_udp | ts_event_en |
ts_master_en | snap_type_sel);
priv->hw->ptp->config_hw_tstamping(priv->ioaddr, value);
priv->hw->ptp->config_sub_second_increment(priv->ioaddr);
temp = (u64) (50000000ULL << 32);
priv->default_addend = div_u64(temp, STMMAC_SYSCLOCK);
priv->hw->ptp->config_addend(priv->ioaddr,
priv->default_addend);
getnstimeofday(&now);
priv->hw->ptp->init_systime(priv->ioaddr, now.tv_sec,
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
if (priv->dma_cap.atime_stamp && priv->extend_desc)
priv->adv_ts = 1;
if (netif_msg_hw(priv) && priv->dma_cap.time_stamp)
pr_debug("IEEE 1588-2002 Time Stamp supported\n");
if (netif_msg_hw(priv) && priv->adv_ts)
pr_debug("IEEE 1588-2008 Advanced Time Stamp supported\n");
priv->hw->ptp = &stmmac_ptp;
priv->hwts_tx_en = 0;
priv->hwts_rx_en = 0;
return stmmac_ptp_register(priv);
}
static void stmmac_release_ptp(struct stmmac_priv *priv)
{
stmmac_ptp_unregister(priv);
}
static void stmmac_adjust_link(struct net_device *dev)
{
struct stmmac_priv *priv = netdev_priv(dev);
struct phy_device *phydev = priv->phydev;
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
priv->hw->mac->flow_ctrl(priv->ioaddr, phydev->duplex,
fc, pause_time);
if (phydev->speed != priv->speed) {
new_state = 1;
switch (phydev->speed) {
case 1000:
if (likely(priv->plat->has_gmac))
ctrl &= ~priv->hw->link.port;
stmmac_hw_fix_mac_speed(priv);
break;
case 100:
case 10:
if (priv->plat->has_gmac) {
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
if (netif_msg_link(priv))
pr_warn("%s: Speed (%d) not 10/100\n",
dev->name, phydev->speed);
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
priv->eee_enabled = stmmac_eee_init(priv);
spin_unlock_irqrestore(&priv->lock, flags);
}
static void stmmac_check_pcs_mode(struct stmmac_priv *priv)
{
int interface = priv->plat->interface;
if (priv->dma_cap.pcs) {
if ((interface == PHY_INTERFACE_MODE_RGMII) ||
(interface == PHY_INTERFACE_MODE_RGMII_ID) ||
(interface == PHY_INTERFACE_MODE_RGMII_RXID) ||
(interface == PHY_INTERFACE_MODE_RGMII_TXID)) {
pr_debug("STMMAC: PCS RGMII support enable\n");
priv->pcs = STMMAC_PCS_RGMII;
} else if (interface == PHY_INTERFACE_MODE_SGMII) {
pr_debug("STMMAC: PCS SGMII support enable\n");
priv->pcs = STMMAC_PCS_SGMII;
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
if (priv->plat->phy_bus_name)
snprintf(bus_id, MII_BUS_ID_SIZE, "%s-%x",
priv->plat->phy_bus_name, priv->plat->bus_id);
else
snprintf(bus_id, MII_BUS_ID_SIZE, "stmmac-%x",
priv->plat->bus_id);
snprintf(phy_id_fmt, MII_BUS_ID_SIZE + 3, PHY_ID_FMT, bus_id,
priv->plat->phy_addr);
pr_debug("stmmac_init_phy: trying to attach to %s\n", phy_id_fmt);
phydev = phy_connect(dev, phy_id_fmt, &stmmac_adjust_link, interface);
if (IS_ERR(phydev)) {
pr_err("%s: Could not attach to PHY\n", dev->name);
return PTR_ERR(phydev);
}
if ((interface == PHY_INTERFACE_MODE_MII) ||
(interface == PHY_INTERFACE_MODE_RMII) ||
(max_speed < 1000 && max_speed > 0))
phydev->advertising &= ~(SUPPORTED_1000baseT_Half |
SUPPORTED_1000baseT_Full);
if (phydev->phy_id == 0) {
phy_disconnect(phydev);
return -ENODEV;
}
pr_debug("stmmac_init_phy: %s: attached to PHY (UID 0x%x)"
" Link = %d\n", dev->name, phydev->phy_id, phydev->link);
priv->phydev = phydev;
return 0;
}
static void stmmac_display_ring(void *head, int size, int extend_desc)
{
int i;
struct dma_extended_desc *ep = (struct dma_extended_desc *)head;
struct dma_desc *p = (struct dma_desc *)head;
for (i = 0; i < size; i++) {
u64 x;
if (extend_desc) {
x = *(u64 *) ep;
pr_info("%d [0x%x]: 0x%x 0x%x 0x%x 0x%x\n",
i, (unsigned int)virt_to_phys(ep),
(unsigned int)x, (unsigned int)(x >> 32),
ep->basic.des2, ep->basic.des3);
ep++;
} else {
x = *(u64 *) p;
pr_info("%d [0x%x]: 0x%x 0x%x 0x%x 0x%x",
i, (unsigned int)virt_to_phys(p),
(unsigned int)x, (unsigned int)(x >> 32),
p->des2, p->des3);
p++;
}
pr_info("\n");
}
}
static void stmmac_display_rings(struct stmmac_priv *priv)
{
unsigned int txsize = priv->dma_tx_size;
unsigned int rxsize = priv->dma_rx_size;
if (priv->extend_desc) {
pr_info("Extended RX descriptor ring:\n");
stmmac_display_ring((void *)priv->dma_erx, rxsize, 1);
pr_info("Extended TX descriptor ring:\n");
stmmac_display_ring((void *)priv->dma_etx, txsize, 1);
} else {
pr_info("RX descriptor ring:\n");
stmmac_display_ring((void *)priv->dma_rx, rxsize, 0);
pr_info("TX descriptor ring:\n");
stmmac_display_ring((void *)priv->dma_tx, txsize, 0);
}
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
unsigned int txsize = priv->dma_tx_size;
unsigned int rxsize = priv->dma_rx_size;
for (i = 0; i < rxsize; i++)
if (priv->extend_desc)
priv->hw->desc->init_rx_desc(&priv->dma_erx[i].basic,
priv->use_riwt, priv->mode,
(i == rxsize - 1));
else
priv->hw->desc->init_rx_desc(&priv->dma_rx[i],
priv->use_riwt, priv->mode,
(i == rxsize - 1));
for (i = 0; i < txsize; i++)
if (priv->extend_desc)
priv->hw->desc->init_tx_desc(&priv->dma_etx[i].basic,
priv->mode,
(i == txsize - 1));
else
priv->hw->desc->init_tx_desc(&priv->dma_tx[i],
priv->mode,
(i == txsize - 1));
}
static int stmmac_init_rx_buffers(struct stmmac_priv *priv, struct dma_desc *p,
int i)
{
struct sk_buff *skb;
skb = __netdev_alloc_skb(priv->dev, priv->dma_buf_sz + NET_IP_ALIGN,
GFP_KERNEL);
if (!skb) {
pr_err("%s: Rx init fails; skb is NULL\n", __func__);
return -ENOMEM;
}
skb_reserve(skb, NET_IP_ALIGN);
priv->rx_skbuff[i] = skb;
priv->rx_skbuff_dma[i] = dma_map_single(priv->device, skb->data,
priv->dma_buf_sz,
DMA_FROM_DEVICE);
if (dma_mapping_error(priv->device, priv->rx_skbuff_dma[i])) {
pr_err("%s: DMA mapping error\n", __func__);
dev_kfree_skb_any(skb);
return -EINVAL;
}
p->des2 = priv->rx_skbuff_dma[i];
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
static int init_dma_desc_rings(struct net_device *dev)
{
int i;
struct stmmac_priv *priv = netdev_priv(dev);
unsigned int txsize = priv->dma_tx_size;
unsigned int rxsize = priv->dma_rx_size;
unsigned int bfsize = 0;
int ret = -ENOMEM;
if (priv->hw->mode->set_16kib_bfsize)
bfsize = priv->hw->mode->set_16kib_bfsize(dev->mtu);
if (bfsize < BUF_SIZE_16KiB)
bfsize = stmmac_set_bfsize(dev->mtu, priv->dma_buf_sz);
priv->dma_buf_sz = bfsize;
if (netif_msg_probe(priv))
pr_debug("%s: txsize %d, rxsize %d, bfsize %d\n", __func__,
txsize, rxsize, bfsize);
if (netif_msg_probe(priv)) {
pr_debug("(%s) dma_rx_phy=0x%08x dma_tx_phy=0x%08x\n", __func__,
(u32) priv->dma_rx_phy, (u32) priv->dma_tx_phy);
pr_debug("\tSKB addresses:\nskb\t\tskb data\tdma data\n");
}
for (i = 0; i < rxsize; i++) {
struct dma_desc *p;
if (priv->extend_desc)
p = &((priv->dma_erx + i)->basic);
else
p = priv->dma_rx + i;
ret = stmmac_init_rx_buffers(priv, p, i);
if (ret)
goto err_init_rx_buffers;
if (netif_msg_probe(priv))
pr_debug("[%p]\t[%p]\t[%x]\n", priv->rx_skbuff[i],
priv->rx_skbuff[i]->data,
(unsigned int)priv->rx_skbuff_dma[i]);
}
priv->cur_rx = 0;
priv->dirty_rx = (unsigned int)(i - rxsize);
buf_sz = bfsize;
if (priv->mode == STMMAC_CHAIN_MODE) {
if (priv->extend_desc) {
priv->hw->mode->init(priv->dma_erx, priv->dma_rx_phy,
rxsize, 1);
priv->hw->mode->init(priv->dma_etx, priv->dma_tx_phy,
txsize, 1);
} else {
priv->hw->mode->init(priv->dma_rx, priv->dma_rx_phy,
rxsize, 0);
priv->hw->mode->init(priv->dma_tx, priv->dma_tx_phy,
txsize, 0);
}
}
for (i = 0; i < txsize; i++) {
struct dma_desc *p;
if (priv->extend_desc)
p = &((priv->dma_etx + i)->basic);
else
p = priv->dma_tx + i;
p->des2 = 0;
priv->tx_skbuff_dma[i] = 0;
priv->tx_skbuff[i] = NULL;
}
priv->dirty_tx = 0;
priv->cur_tx = 0;
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
for (i = 0; i < priv->dma_rx_size; i++)
stmmac_free_rx_buffers(priv, i);
}
static void dma_free_tx_skbufs(struct stmmac_priv *priv)
{
int i;
for (i = 0; i < priv->dma_tx_size; i++) {
struct dma_desc *p;
if (priv->extend_desc)
p = &((priv->dma_etx + i)->basic);
else
p = priv->dma_tx + i;
if (priv->tx_skbuff_dma[i]) {
dma_unmap_single(priv->device,
priv->tx_skbuff_dma[i],
priv->hw->desc->get_tx_len(p),
DMA_TO_DEVICE);
priv->tx_skbuff_dma[i] = 0;
}
if (priv->tx_skbuff[i] != NULL) {
dev_kfree_skb_any(priv->tx_skbuff[i]);
priv->tx_skbuff[i] = NULL;
}
}
}
static int alloc_dma_desc_resources(struct stmmac_priv *priv)
{
unsigned int txsize = priv->dma_tx_size;
unsigned int rxsize = priv->dma_rx_size;
int ret = -ENOMEM;
priv->rx_skbuff_dma = kmalloc_array(rxsize, sizeof(dma_addr_t),
GFP_KERNEL);
if (!priv->rx_skbuff_dma)
return -ENOMEM;
priv->rx_skbuff = kmalloc_array(rxsize, sizeof(struct sk_buff *),
GFP_KERNEL);
if (!priv->rx_skbuff)
goto err_rx_skbuff;
priv->tx_skbuff_dma = kmalloc_array(txsize, sizeof(dma_addr_t),
GFP_KERNEL);
if (!priv->tx_skbuff_dma)
goto err_tx_skbuff_dma;
priv->tx_skbuff = kmalloc_array(txsize, sizeof(struct sk_buff *),
GFP_KERNEL);
if (!priv->tx_skbuff)
goto err_tx_skbuff;
if (priv->extend_desc) {
priv->dma_erx = dma_alloc_coherent(priv->device, rxsize *
sizeof(struct
dma_extended_desc),
&priv->dma_rx_phy,
GFP_KERNEL);
if (!priv->dma_erx)
goto err_dma;
priv->dma_etx = dma_alloc_coherent(priv->device, txsize *
sizeof(struct
dma_extended_desc),
&priv->dma_tx_phy,
GFP_KERNEL);
if (!priv->dma_etx) {
dma_free_coherent(priv->device, priv->dma_rx_size *
sizeof(struct dma_extended_desc),
priv->dma_erx, priv->dma_rx_phy);
goto err_dma;
}
} else {
priv->dma_rx = dma_alloc_coherent(priv->device, rxsize *
sizeof(struct dma_desc),
&priv->dma_rx_phy,
GFP_KERNEL);
if (!priv->dma_rx)
goto err_dma;
priv->dma_tx = dma_alloc_coherent(priv->device, txsize *
sizeof(struct dma_desc),
&priv->dma_tx_phy,
GFP_KERNEL);
if (!priv->dma_tx) {
dma_free_coherent(priv->device, priv->dma_rx_size *
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
priv->dma_tx_size * sizeof(struct dma_desc),
priv->dma_tx, priv->dma_tx_phy);
dma_free_coherent(priv->device,
priv->dma_rx_size * sizeof(struct dma_desc),
priv->dma_rx, priv->dma_rx_phy);
} else {
dma_free_coherent(priv->device, priv->dma_tx_size *
sizeof(struct dma_extended_desc),
priv->dma_etx, priv->dma_tx_phy);
dma_free_coherent(priv->device, priv->dma_rx_size *
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
if (priv->plat->force_thresh_dma_mode)
priv->hw->dma->dma_mode(priv->ioaddr, tc, tc);
else if (priv->plat->force_sf_dma_mode || priv->plat->tx_coe) {
priv->hw->dma->dma_mode(priv->ioaddr, SF_DMA_MODE, SF_DMA_MODE);
tc = SF_DMA_MODE;
} else
priv->hw->dma->dma_mode(priv->ioaddr, tc, SF_DMA_MODE);
}
static void stmmac_tx_clean(struct stmmac_priv *priv)
{
unsigned int txsize = priv->dma_tx_size;
spin_lock(&priv->tx_lock);
priv->xstats.tx_clean++;
while (priv->dirty_tx != priv->cur_tx) {
int last;
unsigned int entry = priv->dirty_tx % txsize;
struct sk_buff *skb = priv->tx_skbuff[entry];
struct dma_desc *p;
if (priv->extend_desc)
p = (struct dma_desc *)(priv->dma_etx + entry);
else
p = priv->dma_tx + entry;
if (priv->hw->desc->get_tx_owner(p))
break;
last = priv->hw->desc->get_tx_ls(p);
if (likely(last)) {
int tx_error =
priv->hw->desc->tx_status(&priv->dev->stats,
&priv->xstats, p,
priv->ioaddr);
if (likely(tx_error == 0)) {
priv->dev->stats.tx_packets++;
priv->xstats.tx_pkt_n++;
} else
priv->dev->stats.tx_errors++;
stmmac_get_tx_hwtstamp(priv, entry, skb);
}
if (netif_msg_tx_done(priv))
pr_debug("%s: curr %d, dirty %d\n", __func__,
priv->cur_tx, priv->dirty_tx);
if (likely(priv->tx_skbuff_dma[entry])) {
dma_unmap_single(priv->device,
priv->tx_skbuff_dma[entry],
priv->hw->desc->get_tx_len(p),
DMA_TO_DEVICE);
priv->tx_skbuff_dma[entry] = 0;
}
priv->hw->mode->clean_desc3(priv, p);
if (likely(skb != NULL)) {
dev_kfree_skb(skb);
priv->tx_skbuff[entry] = NULL;
}
priv->hw->desc->release_tx_desc(p, priv->mode);
priv->dirty_tx++;
}
if (unlikely(netif_queue_stopped(priv->dev) &&
stmmac_tx_avail(priv) > STMMAC_TX_THRESH(priv))) {
netif_tx_lock(priv->dev);
if (netif_queue_stopped(priv->dev) &&
stmmac_tx_avail(priv) > STMMAC_TX_THRESH(priv)) {
if (netif_msg_tx_done(priv))
pr_debug("%s: restart transmit\n", __func__);
netif_wake_queue(priv->dev);
}
netif_tx_unlock(priv->dev);
}
if ((priv->eee_enabled) && (!priv->tx_path_in_lpi_mode)) {
stmmac_enable_eee_mode(priv);
mod_timer(&priv->eee_ctrl_timer, STMMAC_LPI_T(eee_timer));
}
spin_unlock(&priv->tx_lock);
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
int txsize = priv->dma_tx_size;
netif_stop_queue(priv->dev);
priv->hw->dma->stop_tx(priv->ioaddr);
dma_free_tx_skbufs(priv);
for (i = 0; i < txsize; i++)
if (priv->extend_desc)
priv->hw->desc->init_tx_desc(&priv->dma_etx[i].basic,
priv->mode,
(i == txsize - 1));
else
priv->hw->desc->init_tx_desc(&priv->dma_tx[i],
priv->mode,
(i == txsize - 1));
priv->dirty_tx = 0;
priv->cur_tx = 0;
priv->hw->dma->start_tx(priv->ioaddr);
priv->dev->stats.tx_errors++;
netif_wake_queue(priv->dev);
}
static void stmmac_dma_interrupt(struct stmmac_priv *priv)
{
int status;
status = priv->hw->dma->dma_interrupt(priv->ioaddr, &priv->xstats);
if (likely((status & handle_rx)) || (status & handle_tx)) {
if (likely(napi_schedule_prep(&priv->napi))) {
stmmac_disable_dma_irq(priv);
__napi_schedule(&priv->napi);
}
}
if (unlikely(status & tx_hard_error_bump_tc)) {
if (unlikely(tc != SF_DMA_MODE) && (tc <= 256)) {
tc += 64;
priv->hw->dma->dma_mode(priv->ioaddr, tc, SF_DMA_MODE);
priv->xstats.threshold = tc;
}
} else if (unlikely(status == tx_hard_error))
stmmac_tx_err(priv);
}
static void stmmac_mmc_setup(struct stmmac_priv *priv)
{
unsigned int mode = MMC_CNTRL_RESET_ON_READ | MMC_CNTRL_COUNTER_RESET |
MMC_CNTRL_PRESET | MMC_CNTRL_FULL_HALF_PRESET;
dwmac_mmc_intr_all_mask(priv->ioaddr);
if (priv->dma_cap.rmon) {
dwmac_mmc_ctrl(priv->ioaddr, mode);
memset(&priv->mmc, 0, sizeof(struct stmmac_counters));
} else
pr_info(" No MAC Management Counters available\n");
}
static u32 stmmac_get_synopsys_id(struct stmmac_priv *priv)
{
u32 hwid = priv->hw->synopsys_uid;
if (likely(hwid)) {
u32 uid = ((hwid & 0x0000ff00) >> 8);
u32 synid = (hwid & 0x000000ff);
pr_info("stmmac - user ID: 0x%x, Synopsys ID: 0x%x\n",
uid, synid);
return synid;
}
return 0;
}
static void stmmac_selec_desc_mode(struct stmmac_priv *priv)
{
if (priv->plat->enh_desc) {
pr_info(" Enhanced/Alternate descriptors\n");
if (priv->synopsys_id >= DWMAC_CORE_3_50) {
pr_info("\tEnabled extended descriptors\n");
priv->extend_desc = 1;
} else
pr_warn("Extended descriptors not supported\n");
priv->hw->desc = &enh_desc_ops;
} else {
pr_info(" Normal descriptors\n");
priv->hw->desc = &ndesc_ops;
}
}
static int stmmac_get_hw_features(struct stmmac_priv *priv)
{
u32 hw_cap = 0;
if (priv->hw->dma->get_hw_feature) {
hw_cap = priv->hw->dma->get_hw_feature(priv->ioaddr);
priv->dma_cap.mbps_10_100 = (hw_cap & DMA_HW_FEAT_MIISEL);
priv->dma_cap.mbps_1000 = (hw_cap & DMA_HW_FEAT_GMIISEL) >> 1;
priv->dma_cap.half_duplex = (hw_cap & DMA_HW_FEAT_HDSEL) >> 2;
priv->dma_cap.hash_filter = (hw_cap & DMA_HW_FEAT_HASHSEL) >> 4;
priv->dma_cap.multi_addr = (hw_cap & DMA_HW_FEAT_ADDMAC) >> 5;
priv->dma_cap.pcs = (hw_cap & DMA_HW_FEAT_PCSSEL) >> 6;
priv->dma_cap.sma_mdio = (hw_cap & DMA_HW_FEAT_SMASEL) >> 8;
priv->dma_cap.pmt_remote_wake_up =
(hw_cap & DMA_HW_FEAT_RWKSEL) >> 9;
priv->dma_cap.pmt_magic_frame =
(hw_cap & DMA_HW_FEAT_MGKSEL) >> 10;
priv->dma_cap.rmon = (hw_cap & DMA_HW_FEAT_MMCSEL) >> 11;
priv->dma_cap.time_stamp =
(hw_cap & DMA_HW_FEAT_TSVER1SEL) >> 12;
priv->dma_cap.atime_stamp =
(hw_cap & DMA_HW_FEAT_TSVER2SEL) >> 13;
priv->dma_cap.eee = (hw_cap & DMA_HW_FEAT_EEESEL) >> 14;
priv->dma_cap.av = (hw_cap & DMA_HW_FEAT_AVSEL) >> 15;
priv->dma_cap.tx_coe = (hw_cap & DMA_HW_FEAT_TXCOESEL) >> 16;
priv->dma_cap.rx_coe_type1 =
(hw_cap & DMA_HW_FEAT_RXTYP1COE) >> 17;
priv->dma_cap.rx_coe_type2 =
(hw_cap & DMA_HW_FEAT_RXTYP2COE) >> 18;
priv->dma_cap.rxfifo_over_2048 =
(hw_cap & DMA_HW_FEAT_RXFIFOSIZE) >> 19;
priv->dma_cap.number_rx_channel =
(hw_cap & DMA_HW_FEAT_RXCHCNT) >> 20;
priv->dma_cap.number_tx_channel =
(hw_cap & DMA_HW_FEAT_TXCHCNT) >> 22;
priv->dma_cap.enh_desc = (hw_cap & DMA_HW_FEAT_ENHDESSEL) >> 24;
}
return hw_cap;
}
static void stmmac_check_ether_addr(struct stmmac_priv *priv)
{
if (!is_valid_ether_addr(priv->dev->dev_addr)) {
priv->hw->mac->get_umac_addr((void __iomem *)
priv->dev->base_addr,
priv->dev->dev_addr, 0);
if (!is_valid_ether_addr(priv->dev->dev_addr))
eth_hw_addr_random(priv->dev);
pr_info("%s: device MAC address %pM\n", priv->dev->name,
priv->dev->dev_addr);
}
}
static int stmmac_init_dma_engine(struct stmmac_priv *priv)
{
int pbl = DEFAULT_DMA_PBL, fixed_burst = 0, burst_len = 0;
int mixed_burst = 0;
int atds = 0;
if (priv->plat->dma_cfg) {
pbl = priv->plat->dma_cfg->pbl;
fixed_burst = priv->plat->dma_cfg->fixed_burst;
mixed_burst = priv->plat->dma_cfg->mixed_burst;
burst_len = priv->plat->dma_cfg->burst_len;
}
if (priv->extend_desc && (priv->mode == STMMAC_RING_MODE))
atds = 1;
return priv->hw->dma->init(priv->ioaddr, pbl, fixed_burst, mixed_burst,
burst_len, priv->dma_tx_phy,
priv->dma_rx_phy, atds);
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
static int stmmac_hw_setup(struct net_device *dev)
{
struct stmmac_priv *priv = netdev_priv(dev);
int ret;
ret = init_dma_desc_rings(dev);
if (ret < 0) {
pr_err("%s: DMA descriptors initialization failed\n", __func__);
return ret;
}
ret = stmmac_init_dma_engine(priv);
if (ret < 0) {
pr_err("%s: DMA engine initialization failed\n", __func__);
return ret;
}
priv->hw->mac->set_umac_addr(priv->ioaddr, dev->dev_addr, 0);
if (priv->plat->bus_setup)
priv->plat->bus_setup(priv->ioaddr);
priv->hw->mac->core_init(priv->ioaddr, dev->mtu);
stmmac_set_mac(priv->ioaddr, true);
stmmac_dma_operation_mode(priv);
stmmac_mmc_setup(priv);
ret = stmmac_init_ptp(priv);
if (ret && ret != -EOPNOTSUPP)
pr_warn("%s: failed PTP initialisation\n", __func__);
#ifdef CONFIG_STMMAC_DEBUG_FS
ret = stmmac_init_fs(dev);
if (ret < 0)
pr_warn("%s: failed debugFS registration\n", __func__);
#endif
pr_debug("%s: DMA RX/TX processes started...\n", dev->name);
priv->hw->dma->start_tx(priv->ioaddr);
priv->hw->dma->start_rx(priv->ioaddr);
if (netif_msg_hw(priv)) {
priv->hw->mac->dump_regs(priv->ioaddr);
priv->hw->dma->dump_regs(priv->ioaddr);
}
priv->tx_lpi_timer = STMMAC_DEFAULT_TWT_LS;
priv->eee_enabled = stmmac_eee_init(priv);
stmmac_init_tx_coalesce(priv);
if ((priv->use_riwt) && (priv->hw->dma->rx_watchdog)) {
priv->rx_riwt = MAX_DMA_RIWT;
priv->hw->dma->rx_watchdog(priv->ioaddr, MAX_DMA_RIWT);
}
if (priv->pcs && priv->hw->mac->ctrl_ane)
priv->hw->mac->ctrl_ane(priv->ioaddr, 0);
return 0;
}
static int stmmac_open(struct net_device *dev)
{
struct stmmac_priv *priv = netdev_priv(dev);
int ret;
stmmac_check_ether_addr(priv);
if (priv->pcs != STMMAC_PCS_RGMII && priv->pcs != STMMAC_PCS_TBI &&
priv->pcs != STMMAC_PCS_RTBI) {
ret = stmmac_init_phy(dev);
if (ret) {
pr_err("%s: Cannot attach to PHY (error: %d)\n",
__func__, ret);
goto phy_error;
}
}
memset(&priv->xstats, 0, sizeof(struct stmmac_extra_stats));
priv->xstats.threshold = tc;
priv->dma_tx_size = STMMAC_ALIGN(dma_txsize);
priv->dma_rx_size = STMMAC_ALIGN(dma_rxsize);
priv->dma_buf_sz = STMMAC_ALIGN(buf_sz);
ret = alloc_dma_desc_resources(priv);
if (ret < 0) {
pr_err("%s: DMA descriptors allocation failed\n", __func__);
goto dma_desc_error;
}
ret = stmmac_hw_setup(dev);
if (ret < 0) {
pr_err("%s: Hw setup failed\n", __func__);
goto init_error;
}
if (priv->phydev)
phy_start(priv->phydev);
ret = request_irq(dev->irq, stmmac_interrupt,
IRQF_SHARED, dev->name, dev);
if (unlikely(ret < 0)) {
pr_err("%s: ERROR: allocating the IRQ %d (error: %d)\n",
__func__, dev->irq, ret);
goto init_error;
}
if (priv->wol_irq != dev->irq) {
ret = request_irq(priv->wol_irq, stmmac_interrupt,
IRQF_SHARED, dev->name, dev);
if (unlikely(ret < 0)) {
pr_err("%s: ERROR: allocating the WoL IRQ %d (%d)\n",
__func__, priv->wol_irq, ret);
goto wolirq_error;
}
}
if (priv->lpi_irq != -ENXIO) {
ret = request_irq(priv->lpi_irq, stmmac_interrupt, IRQF_SHARED,
dev->name, dev);
if (unlikely(ret < 0)) {
pr_err("%s: ERROR: allocating the LPI IRQ %d (%d)\n",
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
if (priv->phydev)
phy_disconnect(priv->phydev);
phy_error:
clk_disable_unprepare(priv->stmmac_clk);
return ret;
}
static int stmmac_release(struct net_device *dev)
{
struct stmmac_priv *priv = netdev_priv(dev);
if (priv->eee_enabled)
del_timer_sync(&priv->eee_ctrl_timer);
if (priv->phydev) {
phy_stop(priv->phydev);
phy_disconnect(priv->phydev);
priv->phydev = NULL;
}
netif_stop_queue(dev);
napi_disable(&priv->napi);
del_timer_sync(&priv->txtimer);
free_irq(dev->irq, dev);
if (priv->wol_irq != dev->irq)
free_irq(priv->wol_irq, dev);
if (priv->lpi_irq != -ENXIO)
free_irq(priv->lpi_irq, dev);
priv->hw->dma->stop_tx(priv->ioaddr);
priv->hw->dma->stop_rx(priv->ioaddr);
free_dma_desc_resources(priv);
stmmac_set_mac(priv->ioaddr, false);
netif_carrier_off(dev);
#ifdef CONFIG_STMMAC_DEBUG_FS
stmmac_exit_fs();
#endif
stmmac_release_ptp(priv);
return 0;
}
static netdev_tx_t stmmac_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct stmmac_priv *priv = netdev_priv(dev);
unsigned int txsize = priv->dma_tx_size;
unsigned int entry;
int i, csum_insertion = 0, is_jumbo = 0;
int nfrags = skb_shinfo(skb)->nr_frags;
struct dma_desc *desc, *first;
unsigned int nopaged_len = skb_headlen(skb);
unsigned int enh_desc = priv->plat->enh_desc;
if (unlikely(stmmac_tx_avail(priv) < nfrags + 1)) {
if (!netif_queue_stopped(dev)) {
netif_stop_queue(dev);
pr_err("%s: Tx Ring full when queue awake\n", __func__);
}
return NETDEV_TX_BUSY;
}
spin_lock(&priv->tx_lock);
if (priv->tx_path_in_lpi_mode)
stmmac_disable_eee_mode(priv);
entry = priv->cur_tx % txsize;
csum_insertion = (skb->ip_summed == CHECKSUM_PARTIAL);
if (priv->extend_desc)
desc = (struct dma_desc *)(priv->dma_etx + entry);
else
desc = priv->dma_tx + entry;
first = desc;
if (enh_desc)
is_jumbo = priv->hw->mode->is_jumbo_frm(skb->len, enh_desc);
if (likely(!is_jumbo)) {
desc->des2 = dma_map_single(priv->device, skb->data,
nopaged_len, DMA_TO_DEVICE);
priv->tx_skbuff_dma[entry] = desc->des2;
priv->hw->desc->prepare_tx_desc(desc, 1, nopaged_len,
csum_insertion, priv->mode);
} else {
desc = first;
entry = priv->hw->mode->jumbo_frm(priv, skb, csum_insertion);
}
for (i = 0; i < nfrags; i++) {
const skb_frag_t *frag = &skb_shinfo(skb)->frags[i];
int len = skb_frag_size(frag);
priv->tx_skbuff[entry] = NULL;
entry = (++priv->cur_tx) % txsize;
if (priv->extend_desc)
desc = (struct dma_desc *)(priv->dma_etx + entry);
else
desc = priv->dma_tx + entry;
desc->des2 = skb_frag_dma_map(priv->device, frag, 0, len,
DMA_TO_DEVICE);
priv->tx_skbuff_dma[entry] = desc->des2;
priv->hw->desc->prepare_tx_desc(desc, 0, len, csum_insertion,
priv->mode);
wmb();
priv->hw->desc->set_tx_owner(desc);
wmb();
}
priv->tx_skbuff[entry] = skb;
priv->hw->desc->close_tx_desc(desc);
wmb();
priv->tx_count_frames += nfrags + 1;
if (priv->tx_coal_frames > priv->tx_count_frames) {
priv->hw->desc->clear_tx_ic(desc);
priv->xstats.tx_reset_ic_bit++;
mod_timer(&priv->txtimer,
STMMAC_COAL_TIMER(priv->tx_coal_timer));
} else
priv->tx_count_frames = 0;
priv->hw->desc->set_tx_owner(first);
wmb();
priv->cur_tx++;
if (netif_msg_pktdata(priv)) {
pr_debug("%s: curr %d dirty=%d entry=%d, first=%p, nfrags=%d",
__func__, (priv->cur_tx % txsize),
(priv->dirty_tx % txsize), entry, first, nfrags);
if (priv->extend_desc)
stmmac_display_ring((void *)priv->dma_etx, txsize, 1);
else
stmmac_display_ring((void *)priv->dma_tx, txsize, 0);
pr_debug(">>> frame to be transmitted: ");
print_pkt(skb->data, skb->len);
}
if (unlikely(stmmac_tx_avail(priv) <= (MAX_SKB_FRAGS + 1))) {
if (netif_msg_hw(priv))
pr_debug("%s: stop transmitted packets\n", __func__);
netif_stop_queue(dev);
}
dev->stats.tx_bytes += skb->len;
if (unlikely((skb_shinfo(skb)->tx_flags & SKBTX_HW_TSTAMP) &&
priv->hwts_tx_en)) {
skb_shinfo(skb)->tx_flags |= SKBTX_IN_PROGRESS;
priv->hw->desc->enable_tx_timestamp(first);
}
if (!priv->hwts_tx_en)
skb_tx_timestamp(skb);
priv->hw->dma->enable_dma_transmission(priv->ioaddr);
spin_unlock(&priv->tx_lock);
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
static inline void stmmac_rx_refill(struct stmmac_priv *priv)
{
unsigned int rxsize = priv->dma_rx_size;
int bfsize = priv->dma_buf_sz;
for (; priv->cur_rx - priv->dirty_rx > 0; priv->dirty_rx++) {
unsigned int entry = priv->dirty_rx % rxsize;
struct dma_desc *p;
if (priv->extend_desc)
p = (struct dma_desc *)(priv->dma_erx + entry);
else
p = priv->dma_rx + entry;
if (likely(priv->rx_skbuff[entry] == NULL)) {
struct sk_buff *skb;
skb = netdev_alloc_skb_ip_align(priv->dev, bfsize);
if (unlikely(skb == NULL))
break;
priv->rx_skbuff[entry] = skb;
priv->rx_skbuff_dma[entry] =
dma_map_single(priv->device, skb->data, bfsize,
DMA_FROM_DEVICE);
p->des2 = priv->rx_skbuff_dma[entry];
priv->hw->mode->refill_desc3(priv, p);
if (netif_msg_rx_status(priv))
pr_debug("\trefill entry #%d\n", entry);
}
wmb();
priv->hw->desc->set_rx_owner(p);
wmb();
}
}
static int stmmac_rx(struct stmmac_priv *priv, int limit)
{
unsigned int rxsize = priv->dma_rx_size;
unsigned int entry = priv->cur_rx % rxsize;
unsigned int next_entry;
unsigned int count = 0;
int coe = priv->plat->rx_coe;
if (netif_msg_rx_status(priv)) {
pr_debug("%s: descriptor ring:\n", __func__);
if (priv->extend_desc)
stmmac_display_ring((void *)priv->dma_erx, rxsize, 1);
else
stmmac_display_ring((void *)priv->dma_rx, rxsize, 0);
}
while (count < limit) {
int status;
struct dma_desc *p;
if (priv->extend_desc)
p = (struct dma_desc *)(priv->dma_erx + entry);
else
p = priv->dma_rx + entry;
if (priv->hw->desc->get_rx_owner(p))
break;
count++;
next_entry = (++priv->cur_rx) % rxsize;
if (priv->extend_desc)
prefetch(priv->dma_erx + next_entry);
else
prefetch(priv->dma_rx + next_entry);
status = priv->hw->desc->rx_status(&priv->dev->stats,
&priv->xstats, p);
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
frame_len = priv->hw->desc->get_rx_frame_len(p, coe);
if (unlikely(status != llc_snap))
frame_len -= ETH_FCS_LEN;
if (netif_msg_rx_status(priv)) {
pr_debug("\tdesc: %p [entry %d] buff=0x%x\n",
p, entry, p->des2);
if (frame_len > ETH_FRAME_LEN)
pr_debug("\tframe size %d, COE: %d\n",
frame_len, status);
}
skb = priv->rx_skbuff[entry];
if (unlikely(!skb)) {
pr_err("%s: Inconsistent Rx descriptor chain\n",
priv->dev->name);
priv->dev->stats.rx_dropped++;
break;
}
prefetch(skb->data - NET_IP_ALIGN);
priv->rx_skbuff[entry] = NULL;
stmmac_get_rx_hwtstamp(priv, entry, skb);
skb_put(skb, frame_len);
dma_unmap_single(priv->device,
priv->rx_skbuff_dma[entry],
priv->dma_buf_sz, DMA_FROM_DEVICE);
if (netif_msg_pktdata(priv)) {
pr_debug("frame received (%dbytes)", frame_len);
print_pkt(skb->data, frame_len);
}
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
static int stmmac_config(struct net_device *dev, struct ifmap *map)
{
if (dev->flags & IFF_UP)
return -EBUSY;
if (map->base_addr != dev->base_addr) {
pr_warn("%s: can't change I/O address\n", dev->name);
return -EOPNOTSUPP;
}
if (map->irq != dev->irq) {
pr_warn("%s: not change IRQ number %d\n", dev->name, dev->irq);
return -EOPNOTSUPP;
}
return 0;
}
static void stmmac_set_rx_mode(struct net_device *dev)
{
struct stmmac_priv *priv = netdev_priv(dev);
spin_lock(&priv->lock);
priv->hw->mac->set_filter(dev, priv->synopsys_id);
spin_unlock(&priv->lock);
}
static int stmmac_change_mtu(struct net_device *dev, int new_mtu)
{
struct stmmac_priv *priv = netdev_priv(dev);
int max_mtu;
if (netif_running(dev)) {
pr_err("%s: must be stopped to change its MTU\n", dev->name);
return -EBUSY;
}
if (priv->plat->enh_desc)
max_mtu = JUMBO_LEN;
else
max_mtu = SKB_MAX_HEAD(NET_SKB_PAD + NET_IP_ALIGN);
if (priv->plat->maxmtu < max_mtu)
max_mtu = priv->plat->maxmtu;
if ((new_mtu < 46) || (new_mtu > max_mtu)) {
pr_err("%s: invalid MTU, max MTU is: %d\n", dev->name, max_mtu);
return -EINVAL;
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
else if (priv->plat->rx_coe == STMMAC_RX_COE_TYPE1)
features &= ~NETIF_F_IPV6_CSUM;
if (!priv->plat->tx_coe)
features &= ~NETIF_F_ALL_CSUM;
if (priv->plat->bugged_jumbo && (dev->mtu > ETH_DATA_LEN))
features &= ~NETIF_F_ALL_CSUM;
return features;
}
static irqreturn_t stmmac_interrupt(int irq, void *dev_id)
{
struct net_device *dev = (struct net_device *)dev_id;
struct stmmac_priv *priv = netdev_priv(dev);
if (priv->irq_wake)
pm_wakeup_event(priv->device, 0);
if (unlikely(!dev)) {
pr_err("%s: invalid dev pointer\n", __func__);
return IRQ_NONE;
}
if (priv->plat->has_gmac) {
int status = priv->hw->mac->host_irq_status((void __iomem *)
dev->base_addr,
&priv->xstats);
if (unlikely(status)) {
if (status & CORE_IRQ_TX_PATH_IN_LPI_MODE)
priv->tx_path_in_lpi_mode = true;
if (status & CORE_IRQ_TX_PATH_EXIT_LPI_MODE)
priv->tx_path_in_lpi_mode = false;
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
struct stmmac_priv *priv = netdev_priv(dev);
int ret = -EOPNOTSUPP;
if (!netif_running(dev))
return -EINVAL;
switch (cmd) {
case SIOCGMIIPHY:
case SIOCGMIIREG:
case SIOCSMIIREG:
if (!priv->phydev)
return -EINVAL;
ret = phy_mii_ioctl(priv->phydev, rq, cmd);
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
(unsigned int)x, (unsigned int)(x >> 32),
ep->basic.des2, ep->basic.des3);
ep++;
} else {
x = *(u64 *) p;
seq_printf(seq, "%d [0x%x]: 0x%x 0x%x 0x%x 0x%x\n",
i, (unsigned int)virt_to_phys(ep),
(unsigned int)x, (unsigned int)(x >> 32),
p->des2, p->des3);
p++;
}
seq_printf(seq, "\n");
}
}
static int stmmac_sysfs_ring_read(struct seq_file *seq, void *v)
{
struct net_device *dev = seq->private;
struct stmmac_priv *priv = netdev_priv(dev);
unsigned int txsize = priv->dma_tx_size;
unsigned int rxsize = priv->dma_rx_size;
if (priv->extend_desc) {
seq_printf(seq, "Extended RX descriptor ring:\n");
sysfs_display_ring((void *)priv->dma_erx, rxsize, 1, seq);
seq_printf(seq, "Extended TX descriptor ring:\n");
sysfs_display_ring((void *)priv->dma_etx, txsize, 1, seq);
} else {
seq_printf(seq, "RX descriptor ring:\n");
sysfs_display_ring((void *)priv->dma_rx, rxsize, 0, seq);
seq_printf(seq, "TX descriptor ring:\n");
sysfs_display_ring((void *)priv->dma_tx, txsize, 0, seq);
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
seq_printf(seq, "\t10/100 Mbps %s\n",
(priv->dma_cap.mbps_10_100) ? "Y" : "N");
seq_printf(seq, "\t1000 Mbps %s\n",
(priv->dma_cap.mbps_1000) ? "Y" : "N");
seq_printf(seq, "\tHalf duple %s\n",
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
seq_printf(seq, "\tIEEE 1588-2008 Advanced Time Stamp:%s\n",
(priv->dma_cap.atime_stamp) ? "Y" : "N");
seq_printf(seq, "\t802.3az - Energy-Efficient Ethernet (EEE) %s\n",
(priv->dma_cap.eee) ? "Y" : "N");
seq_printf(seq, "\tAV features: %s\n", (priv->dma_cap.av) ? "Y" : "N");
seq_printf(seq, "\tChecksum Offload in TX: %s\n",
(priv->dma_cap.tx_coe) ? "Y" : "N");
seq_printf(seq, "\tIP Checksum Offload (type1) in RX: %s\n",
(priv->dma_cap.rx_coe_type1) ? "Y" : "N");
seq_printf(seq, "\tIP Checksum Offload (type2) in RX: %s\n",
(priv->dma_cap.rx_coe_type2) ? "Y" : "N");
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
stmmac_fs_dir = debugfs_create_dir(STMMAC_RESOURCE_NAME, NULL);
if (!stmmac_fs_dir || IS_ERR(stmmac_fs_dir)) {
pr_err("ERROR %s, debugfs create directory failed\n",
STMMAC_RESOURCE_NAME);
return -ENOMEM;
}
stmmac_rings_status = debugfs_create_file("descriptors_status",
S_IRUGO, stmmac_fs_dir, dev,
&stmmac_rings_status_fops);
if (!stmmac_rings_status || IS_ERR(stmmac_rings_status)) {
pr_info("ERROR creating stmmac ring debugfs file\n");
debugfs_remove(stmmac_fs_dir);
return -ENOMEM;
}
stmmac_dma_cap = debugfs_create_file("dma_cap", S_IRUGO, stmmac_fs_dir,
dev, &stmmac_dma_cap_fops);
if (!stmmac_dma_cap || IS_ERR(stmmac_dma_cap)) {
pr_info("ERROR creating stmmac MMC debugfs file\n");
debugfs_remove(stmmac_rings_status);
debugfs_remove(stmmac_fs_dir);
return -ENOMEM;
}
return 0;
}
static void stmmac_exit_fs(void)
{
debugfs_remove(stmmac_rings_status);
debugfs_remove(stmmac_dma_cap);
debugfs_remove(stmmac_fs_dir);
}
static int stmmac_hw_init(struct stmmac_priv *priv)
{
int ret;
struct mac_device_info *mac;
if (priv->plat->has_gmac) {
priv->dev->priv_flags |= IFF_UNICAST_FLT;
mac = dwmac1000_setup(priv->ioaddr);
} else {
mac = dwmac100_setup(priv->ioaddr);
}
if (!mac)
return -ENOMEM;
priv->hw = mac;
priv->synopsys_id = stmmac_get_synopsys_id(priv);
if (chain_mode) {
priv->hw->mode = &chain_mode_ops;
pr_info(" Chain mode enabled\n");
priv->mode = STMMAC_CHAIN_MODE;
} else {
priv->hw->mode = &ring_mode_ops;
pr_info(" Ring mode enabled\n");
priv->mode = STMMAC_RING_MODE;
}
priv->hw_cap_support = stmmac_get_hw_features(priv);
if (priv->hw_cap_support) {
pr_info(" DMA HW capability register supported");
priv->plat->enh_desc = priv->dma_cap.enh_desc;
priv->plat->pmt = priv->dma_cap.pmt_remote_wake_up;
priv->plat->tx_coe = priv->dma_cap.tx_coe;
if (priv->dma_cap.rx_coe_type2)
priv->plat->rx_coe = STMMAC_RX_COE_TYPE2;
else if (priv->dma_cap.rx_coe_type1)
priv->plat->rx_coe = STMMAC_RX_COE_TYPE1;
} else
pr_info(" No HW DMA feature register supported");
stmmac_selec_desc_mode(priv);
ret = priv->hw->mac->rx_ipc(priv->ioaddr);
if (!ret) {
pr_warn(" RX IPC Checksum Offload not configured.\n");
priv->plat->rx_coe = STMMAC_RX_COE_NONE;
}
if (priv->plat->rx_coe)
pr_info(" RX Checksum Offload Engine supported (type %d)\n",
priv->plat->rx_coe);
if (priv->plat->tx_coe)
pr_info(" TX Checksum insertion supported\n");
if (priv->plat->pmt) {
pr_info(" Wake-Up On Lan supported\n");
device_set_wakeup_capable(priv->device, 1);
}
return 0;
}
struct stmmac_priv *stmmac_dvr_probe(struct device *device,
struct plat_stmmacenet_data *plat_dat,
void __iomem *addr)
{
int ret = 0;
struct net_device *ndev = NULL;
struct stmmac_priv *priv;
ndev = alloc_etherdev(sizeof(struct stmmac_priv));
if (!ndev)
return NULL;
SET_NETDEV_DEV(ndev, device);
priv = netdev_priv(ndev);
priv->device = device;
priv->dev = ndev;
ether_setup(ndev);
stmmac_set_ethtool_ops(ndev);
priv->pause = pause;
priv->plat = plat_dat;
priv->ioaddr = addr;
priv->dev->base_addr = (unsigned long)addr;
stmmac_verify_args();
if ((phyaddr >= 0) && (phyaddr <= 31))
priv->plat->phy_addr = phyaddr;
priv->stmmac_clk = devm_clk_get(priv->device, STMMAC_RESOURCE_NAME);
if (IS_ERR(priv->stmmac_clk)) {
dev_warn(priv->device, "%s: warning: cannot get CSR clock\n",
__func__);
ret = PTR_ERR(priv->stmmac_clk);
goto error_clk_get;
}
clk_prepare_enable(priv->stmmac_clk);
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
ndev->features |= ndev->hw_features | NETIF_F_HIGHDMA;
ndev->watchdog_timeo = msecs_to_jiffies(watchdog);
#ifdef STMMAC_VLAN_TAG_USED
ndev->features |= NETIF_F_HW_VLAN_CTAG_RX;
#endif
priv->msg_enable = netif_msg_init(debug, default_msg_level);
if (flow_ctrl)
priv->flow_ctrl = FLOW_AUTO;
if ((priv->synopsys_id >= DWMAC_CORE_3_50) && (!priv->plat->riwt_off)) {
priv->use_riwt = 1;
pr_info(" Enable RX Mitigation via HW Watchdog Timer\n");
}
netif_napi_add(ndev, &priv->napi, stmmac_poll, 64);
spin_lock_init(&priv->lock);
spin_lock_init(&priv->tx_lock);
ret = register_netdev(ndev);
if (ret) {
pr_err("%s: ERROR %i registering the device\n", __func__, ret);
goto error_netdev_register;
}
if (!priv->plat->clk_csr)
stmmac_clk_csr_set(priv);
else
priv->clk_csr = priv->plat->clk_csr;
stmmac_check_pcs_mode(priv);
if (priv->pcs != STMMAC_PCS_RGMII && priv->pcs != STMMAC_PCS_TBI &&
priv->pcs != STMMAC_PCS_RTBI) {
ret = stmmac_mdio_register(ndev);
if (ret < 0) {
pr_debug("%s: MDIO bus (id: %d) registration failed",
__func__, priv->plat->bus_id);
goto error_mdio_register;
}
}
return priv;
error_mdio_register:
unregister_netdev(ndev);
error_netdev_register:
netif_napi_del(&priv->napi);
error_hw_init:
clk_disable_unprepare(priv->stmmac_clk);
error_clk_get:
free_netdev(ndev);
return ERR_PTR(ret);
}
int stmmac_dvr_remove(struct net_device *ndev)
{
struct stmmac_priv *priv = netdev_priv(ndev);
pr_info("%s:\n\tremoving driver", __func__);
priv->hw->dma->stop_rx(priv->ioaddr);
priv->hw->dma->stop_tx(priv->ioaddr);
stmmac_set_mac(priv->ioaddr, false);
if (priv->pcs != STMMAC_PCS_RGMII && priv->pcs != STMMAC_PCS_TBI &&
priv->pcs != STMMAC_PCS_RTBI)
stmmac_mdio_unregister(ndev);
netif_carrier_off(ndev);
unregister_netdev(ndev);
if (priv->stmmac_rst)
reset_control_assert(priv->stmmac_rst);
clk_disable_unprepare(priv->stmmac_clk);
free_netdev(ndev);
return 0;
}
int stmmac_suspend(struct net_device *ndev)
{
struct stmmac_priv *priv = netdev_priv(ndev);
unsigned long flags;
if (!ndev || !netif_running(ndev))
return 0;
if (priv->phydev)
phy_stop(priv->phydev);
spin_lock_irqsave(&priv->lock, flags);
netif_device_detach(ndev);
netif_stop_queue(ndev);
napi_disable(&priv->napi);
priv->hw->dma->stop_tx(priv->ioaddr);
priv->hw->dma->stop_rx(priv->ioaddr);
stmmac_clear_descriptors(priv);
if (device_may_wakeup(priv->device)) {
priv->hw->mac->pmt(priv->ioaddr, priv->wolopts);
priv->irq_wake = 1;
} else {
stmmac_set_mac(priv->ioaddr, false);
pinctrl_pm_select_sleep_state(priv->device);
clk_disable_unprepare(priv->stmmac_clk);
}
spin_unlock_irqrestore(&priv->lock, flags);
return 0;
}
int stmmac_resume(struct net_device *ndev)
{
struct stmmac_priv *priv = netdev_priv(ndev);
unsigned long flags;
if (!netif_running(ndev))
return 0;
spin_lock_irqsave(&priv->lock, flags);
if (device_may_wakeup(priv->device)) {
priv->hw->mac->pmt(priv->ioaddr, 0);
priv->irq_wake = 0;
} else {
pinctrl_pm_select_default_state(priv->device);
clk_prepare_enable(priv->stmmac_clk);
if (priv->mii)
stmmac_mdio_reset(priv->mii);
}
netif_device_attach(ndev);
stmmac_hw_setup(ndev);
napi_enable(&priv->napi);
netif_start_queue(ndev);
spin_unlock_irqrestore(&priv->lock, flags);
if (priv->phydev)
phy_start(priv->phydev);
return 0;
}
static int __init stmmac_init(void)
{
int ret;
ret = stmmac_register_platform();
if (ret)
goto err;
ret = stmmac_register_pci();
if (ret)
goto err_pci;
return 0;
err_pci:
stmmac_unregister_platform();
err:
pr_err("stmmac: driver registration failed\n");
return ret;
}
static void __exit stmmac_exit(void)
{
stmmac_unregister_platform();
stmmac_unregister_pci();
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
} else if (!strncmp(opt, "dma_txsize:", 11)) {
if (kstrtoint(opt + 11, 0, &dma_txsize))
goto err;
} else if (!strncmp(opt, "dma_rxsize:", 11)) {
if (kstrtoint(opt + 11, 0, &dma_rxsize))
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
