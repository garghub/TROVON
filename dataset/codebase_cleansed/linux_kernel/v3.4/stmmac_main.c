static void stmmac_verify_args(void)
{
if (unlikely(watchdog < 0))
watchdog = TX_TIMEO;
if (unlikely(dma_rxsize < 0))
dma_rxsize = DMA_RX_SIZE;
if (unlikely(dma_txsize < 0))
dma_txsize = DMA_TX_SIZE;
if (unlikely((buf_sz < DMA_BUFFER_SIZE) || (buf_sz > BUF_SIZE_16KiB)))
buf_sz = DMA_BUFFER_SIZE;
if (unlikely(flow_ctrl > 1))
flow_ctrl = FLOW_AUTO;
else if (likely(flow_ctrl < 0))
flow_ctrl = FLOW_OFF;
if (unlikely((pause < 0) || (pause > 0xffff)))
pause = PAUSE_TIME;
}
static void print_pkt(unsigned char *buf, int len)
{
int j;
pr_info("len = %d byte, buf addr: 0x%p", len, buf);
for (j = 0; j < len; j++) {
if ((j % 16) == 0)
pr_info("\n %03x:", j);
pr_info(" %02x", buf[j]);
}
pr_info("\n");
}
static inline u32 stmmac_tx_avail(struct stmmac_priv *priv)
{
return priv->dirty_tx + priv->dma_tx_size - priv->cur_tx - 1;
}
static inline void stmmac_hw_fix_mac_speed(struct stmmac_priv *priv)
{
struct phy_device *phydev = priv->phydev;
if (likely(priv->plat->fix_mac_speed))
priv->plat->fix_mac_speed(priv->plat->bsp_priv,
phydev->speed);
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
DBG(probe, DEBUG, "stmmac_adjust_link: called. address %d link %d\n",
phydev->addr, phydev->link);
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
pr_warning("%s: Speed (%d) is not 10"
" or 100!\n", dev->name, phydev->speed);
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
DBG(probe, DEBUG, "stmmac_adjust_link: exiting\n");
}
static int stmmac_init_phy(struct net_device *dev)
{
struct stmmac_priv *priv = netdev_priv(dev);
struct phy_device *phydev;
char phy_id[MII_BUS_ID_SIZE + 3];
char bus_id[MII_BUS_ID_SIZE];
int interface = priv->plat->interface;
priv->oldlink = 0;
priv->speed = 0;
priv->oldduplex = -1;
snprintf(bus_id, MII_BUS_ID_SIZE, "stmmac-%x", priv->plat->bus_id);
snprintf(phy_id, MII_BUS_ID_SIZE + 3, PHY_ID_FMT, bus_id,
priv->plat->phy_addr);
pr_debug("stmmac_init_phy: trying to attach to %s\n", phy_id);
phydev = phy_connect(dev, phy_id, &stmmac_adjust_link, 0, interface);
if (IS_ERR(phydev)) {
pr_err("%s: Could not attach to PHY\n", dev->name);
return PTR_ERR(phydev);
}
if ((interface == PHY_INTERFACE_MODE_MII) ||
(interface == PHY_INTERFACE_MODE_RMII))
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
static void display_ring(struct dma_desc *p, int size)
{
struct tmp_s {
u64 a;
unsigned int b;
unsigned int c;
};
int i;
for (i = 0; i < size; i++) {
struct tmp_s *x = (struct tmp_s *)(p + i);
pr_info("\t%d [0x%x]: DES0=0x%x DES1=0x%x BUF1=0x%x BUF2=0x%x",
i, (unsigned int)virt_to_phys(&p[i]),
(unsigned int)(x->a), (unsigned int)((x->a) >> 32),
x->b, x->c);
pr_info("\n");
}
}
static int stmmac_set_bfsize(int mtu, int bufsize)
{
int ret = bufsize;
if (mtu >= BUF_SIZE_4KiB)
ret = BUF_SIZE_8KiB;
else if (mtu >= BUF_SIZE_2KiB)
ret = BUF_SIZE_4KiB;
else if (mtu >= DMA_BUFFER_SIZE)
ret = BUF_SIZE_2KiB;
else
ret = DMA_BUFFER_SIZE;
return ret;
}
static void init_dma_desc_rings(struct net_device *dev)
{
int i;
struct stmmac_priv *priv = netdev_priv(dev);
struct sk_buff *skb;
unsigned int txsize = priv->dma_tx_size;
unsigned int rxsize = priv->dma_rx_size;
unsigned int bfsize;
int dis_ic = 0;
int des3_as_data_buf = 0;
bfsize = priv->hw->ring->set_16kib_bfsize(dev->mtu);
if (bfsize == BUF_SIZE_16KiB)
des3_as_data_buf = 1;
else
bfsize = stmmac_set_bfsize(dev->mtu, priv->dma_buf_sz);
#ifdef CONFIG_STMMAC_TIMER
if (likely(priv->tm->enable))
dis_ic = 1;
#endif
DBG(probe, INFO, "stmmac: txsize %d, rxsize %d, bfsize %d\n",
txsize, rxsize, bfsize);
priv->rx_skbuff_dma = kmalloc(rxsize * sizeof(dma_addr_t), GFP_KERNEL);
priv->rx_skbuff =
kmalloc(sizeof(struct sk_buff *) * rxsize, GFP_KERNEL);
priv->dma_rx =
(struct dma_desc *)dma_alloc_coherent(priv->device,
rxsize *
sizeof(struct dma_desc),
&priv->dma_rx_phy,
GFP_KERNEL);
priv->tx_skbuff = kmalloc(sizeof(struct sk_buff *) * txsize,
GFP_KERNEL);
priv->dma_tx =
(struct dma_desc *)dma_alloc_coherent(priv->device,
txsize *
sizeof(struct dma_desc),
&priv->dma_tx_phy,
GFP_KERNEL);
if ((priv->dma_rx == NULL) || (priv->dma_tx == NULL)) {
pr_err("%s:ERROR allocating the DMA Tx/Rx desc\n", __func__);
return;
}
DBG(probe, INFO, "stmmac (%s) DMA desc: virt addr (Rx %p, "
"Tx %p)\n\tDMA phy addr (Rx 0x%08x, Tx 0x%08x)\n",
dev->name, priv->dma_rx, priv->dma_tx,
(unsigned int)priv->dma_rx_phy, (unsigned int)priv->dma_tx_phy);
DBG(probe, INFO, "stmmac: SKB addresses:\n"
"skb\t\tskb data\tdma data\n");
for (i = 0; i < rxsize; i++) {
struct dma_desc *p = priv->dma_rx + i;
skb = __netdev_alloc_skb(dev, bfsize + NET_IP_ALIGN,
GFP_KERNEL);
if (unlikely(skb == NULL)) {
pr_err("%s: Rx init fails; skb is NULL\n", __func__);
break;
}
skb_reserve(skb, NET_IP_ALIGN);
priv->rx_skbuff[i] = skb;
priv->rx_skbuff_dma[i] = dma_map_single(priv->device, skb->data,
bfsize, DMA_FROM_DEVICE);
p->des2 = priv->rx_skbuff_dma[i];
priv->hw->ring->init_desc3(des3_as_data_buf, p);
DBG(probe, INFO, "[%p]\t[%p]\t[%x]\n", priv->rx_skbuff[i],
priv->rx_skbuff[i]->data, priv->rx_skbuff_dma[i]);
}
priv->cur_rx = 0;
priv->dirty_rx = (unsigned int)(i - rxsize);
priv->dma_buf_sz = bfsize;
buf_sz = bfsize;
for (i = 0; i < txsize; i++) {
priv->tx_skbuff[i] = NULL;
priv->dma_tx[i].des2 = 0;
}
priv->hw->ring->init_dma_chain(priv->dma_rx, priv->dma_rx_phy, rxsize);
priv->hw->ring->init_dma_chain(priv->dma_tx, priv->dma_tx_phy, txsize);
priv->dirty_tx = 0;
priv->cur_tx = 0;
priv->hw->desc->init_rx_desc(priv->dma_rx, rxsize, dis_ic);
priv->hw->desc->init_tx_desc(priv->dma_tx, txsize);
if (netif_msg_hw(priv)) {
pr_info("RX descriptor ring:\n");
display_ring(priv->dma_rx, rxsize);
pr_info("TX descriptor ring:\n");
display_ring(priv->dma_tx, txsize);
}
}
static void dma_free_rx_skbufs(struct stmmac_priv *priv)
{
int i;
for (i = 0; i < priv->dma_rx_size; i++) {
if (priv->rx_skbuff[i]) {
dma_unmap_single(priv->device, priv->rx_skbuff_dma[i],
priv->dma_buf_sz, DMA_FROM_DEVICE);
dev_kfree_skb_any(priv->rx_skbuff[i]);
}
priv->rx_skbuff[i] = NULL;
}
}
static void dma_free_tx_skbufs(struct stmmac_priv *priv)
{
int i;
for (i = 0; i < priv->dma_tx_size; i++) {
if (priv->tx_skbuff[i] != NULL) {
struct dma_desc *p = priv->dma_tx + i;
if (p->des2)
dma_unmap_single(priv->device, p->des2,
priv->hw->desc->get_tx_len(p),
DMA_TO_DEVICE);
dev_kfree_skb_any(priv->tx_skbuff[i]);
priv->tx_skbuff[i] = NULL;
}
}
}
static void free_dma_desc_resources(struct stmmac_priv *priv)
{
dma_free_rx_skbufs(priv);
dma_free_tx_skbufs(priv);
dma_free_coherent(priv->device,
priv->dma_tx_size * sizeof(struct dma_desc),
priv->dma_tx, priv->dma_tx_phy);
dma_free_coherent(priv->device,
priv->dma_rx_size * sizeof(struct dma_desc),
priv->dma_rx, priv->dma_rx_phy);
kfree(priv->rx_skbuff_dma);
kfree(priv->rx_skbuff);
kfree(priv->tx_skbuff);
}
static void stmmac_dma_operation_mode(struct stmmac_priv *priv)
{
if (likely(priv->plat->force_sf_dma_mode ||
((priv->plat->tx_coe) && (!priv->no_csum_insertion)))) {
priv->hw->dma->dma_mode(priv->ioaddr,
SF_DMA_MODE, SF_DMA_MODE);
tc = SF_DMA_MODE;
} else
priv->hw->dma->dma_mode(priv->ioaddr, tc, SF_DMA_MODE);
}
static void stmmac_tx(struct stmmac_priv *priv)
{
unsigned int txsize = priv->dma_tx_size;
spin_lock(&priv->tx_lock);
while (priv->dirty_tx != priv->cur_tx) {
int last;
unsigned int entry = priv->dirty_tx % txsize;
struct sk_buff *skb = priv->tx_skbuff[entry];
struct dma_desc *p = priv->dma_tx + entry;
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
}
TX_DBG("%s: curr %d, dirty %d\n", __func__,
priv->cur_tx, priv->dirty_tx);
if (likely(p->des2))
dma_unmap_single(priv->device, p->des2,
priv->hw->desc->get_tx_len(p),
DMA_TO_DEVICE);
priv->hw->ring->clean_desc3(p);
if (likely(skb != NULL)) {
if ((skb_queue_len(&priv->rx_recycle) <
priv->dma_rx_size) &&
skb_recycle_check(skb, priv->dma_buf_sz))
__skb_queue_head(&priv->rx_recycle, skb);
else
dev_kfree_skb(skb);
priv->tx_skbuff[entry] = NULL;
}
priv->hw->desc->release_tx_desc(p);
entry = (++priv->dirty_tx) % txsize;
}
if (unlikely(netif_queue_stopped(priv->dev) &&
stmmac_tx_avail(priv) > STMMAC_TX_THRESH(priv))) {
netif_tx_lock(priv->dev);
if (netif_queue_stopped(priv->dev) &&
stmmac_tx_avail(priv) > STMMAC_TX_THRESH(priv)) {
TX_DBG("%s: restart transmit\n", __func__);
netif_wake_queue(priv->dev);
}
netif_tx_unlock(priv->dev);
}
spin_unlock(&priv->tx_lock);
}
static inline void stmmac_enable_irq(struct stmmac_priv *priv)
{
#ifdef CONFIG_STMMAC_TIMER
if (likely(priv->tm->enable))
priv->tm->timer_start(tmrate);
else
#endif
priv->hw->dma->enable_dma_irq(priv->ioaddr);
}
static inline void stmmac_disable_irq(struct stmmac_priv *priv)
{
#ifdef CONFIG_STMMAC_TIMER
if (likely(priv->tm->enable))
priv->tm->timer_stop();
else
#endif
priv->hw->dma->disable_dma_irq(priv->ioaddr);
}
static int stmmac_has_work(struct stmmac_priv *priv)
{
unsigned int has_work = 0;
int rxret, tx_work = 0;
rxret = priv->hw->desc->get_rx_owner(priv->dma_rx +
(priv->cur_rx % priv->dma_rx_size));
if (priv->dirty_tx != priv->cur_tx)
tx_work = 1;
if (likely(!rxret || tx_work))
has_work = 1;
return has_work;
}
static inline void _stmmac_schedule(struct stmmac_priv *priv)
{
if (likely(stmmac_has_work(priv))) {
stmmac_disable_irq(priv);
napi_schedule(&priv->napi);
}
}
void stmmac_schedule(struct net_device *dev)
{
struct stmmac_priv *priv = netdev_priv(dev);
priv->xstats.sched_timer_n++;
_stmmac_schedule(priv);
}
static void stmmac_no_timer_started(unsigned int x)
{;
}
static void stmmac_no_timer_stopped(void)
{;
}
static void stmmac_tx_err(struct stmmac_priv *priv)
{
netif_stop_queue(priv->dev);
priv->hw->dma->stop_tx(priv->ioaddr);
dma_free_tx_skbufs(priv);
priv->hw->desc->init_tx_desc(priv->dma_tx, priv->dma_tx_size);
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
if (likely(status == handle_tx_rx))
_stmmac_schedule(priv);
else if (unlikely(status == tx_hard_error_bump_tc)) {
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
priv->dma_cap.multi_addr =
(hw_cap & DMA_HW_FEAT_ADDMACADRSEL) >> 5;
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
priv->dma_cap.enh_desc =
(hw_cap & DMA_HW_FEAT_ENHDESSEL) >> 24;
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
}
pr_warning("%s: device MAC address %pM\n", priv->dev->name,
priv->dev->dev_addr);
}
static int stmmac_open(struct net_device *dev)
{
struct stmmac_priv *priv = netdev_priv(dev);
int ret;
stmmac_check_ether_addr(priv);
ret = stmmac_mdio_register(dev);
if (ret < 0) {
pr_debug("%s: MDIO bus (id: %d) registration failed",
__func__, priv->plat->bus_id);
return ret;
}
#ifdef CONFIG_STMMAC_TIMER
priv->tm = kzalloc(sizeof(struct stmmac_timer *), GFP_KERNEL);
if (unlikely(priv->tm == NULL))
return -ENOMEM;
priv->tm->freq = tmrate;
if (unlikely((stmmac_open_ext_timer(dev, priv->tm)) < 0)) {
pr_warning("stmmaceth: cannot attach the external timer.\n");
priv->tm->freq = 0;
priv->tm->timer_start = stmmac_no_timer_started;
priv->tm->timer_stop = stmmac_no_timer_stopped;
} else
priv->tm->enable = 1;
#endif
ret = stmmac_init_phy(dev);
if (unlikely(ret)) {
pr_err("%s: Cannot attach to PHY (error: %d)\n", __func__, ret);
goto open_error;
}
priv->dma_tx_size = STMMAC_ALIGN(dma_txsize);
priv->dma_rx_size = STMMAC_ALIGN(dma_rxsize);
priv->dma_buf_sz = STMMAC_ALIGN(buf_sz);
init_dma_desc_rings(dev);
ret = priv->hw->dma->init(priv->ioaddr, priv->plat->pbl,
priv->dma_tx_phy, priv->dma_rx_phy);
if (ret < 0) {
pr_err("%s: DMA initialization failed\n", __func__);
goto open_error;
}
priv->hw->mac->set_umac_addr(priv->ioaddr, dev->dev_addr, 0);
if (priv->plat->bus_setup)
priv->plat->bus_setup(priv->ioaddr);
priv->hw->mac->core_init(priv->ioaddr);
ret = request_irq(dev->irq, stmmac_interrupt,
IRQF_SHARED, dev->name, dev);
if (unlikely(ret < 0)) {
pr_err("%s: ERROR: allocating the IRQ %d (error: %d)\n",
__func__, dev->irq, ret);
goto open_error;
}
if (priv->wol_irq != dev->irq) {
ret = request_irq(priv->wol_irq, stmmac_interrupt,
IRQF_SHARED, dev->name, dev);
if (unlikely(ret < 0)) {
pr_err("%s: ERROR: allocating the ext WoL IRQ %d "
"(error: %d)\n", __func__, priv->wol_irq, ret);
goto open_error_wolirq;
}
}
stmmac_set_mac(priv->ioaddr, true);
stmmac_dma_operation_mode(priv);
memset(&priv->xstats, 0, sizeof(struct stmmac_extra_stats));
priv->xstats.threshold = tc;
stmmac_mmc_setup(priv);
#ifdef CONFIG_STMMAC_DEBUG_FS
ret = stmmac_init_fs(dev);
if (ret < 0)
pr_warning("%s: failed debugFS registration\n", __func__);
#endif
DBG(probe, DEBUG, "%s: DMA RX/TX processes started...\n", dev->name);
priv->hw->dma->start_tx(priv->ioaddr);
priv->hw->dma->start_rx(priv->ioaddr);
#ifdef CONFIG_STMMAC_TIMER
priv->tm->timer_start(tmrate);
#endif
if (netif_msg_hw(priv)) {
priv->hw->mac->dump_regs(priv->ioaddr);
priv->hw->dma->dump_regs(priv->ioaddr);
}
if (priv->phydev)
phy_start(priv->phydev);
napi_enable(&priv->napi);
skb_queue_head_init(&priv->rx_recycle);
netif_start_queue(dev);
return 0;
open_error_wolirq:
free_irq(dev->irq, dev);
open_error:
#ifdef CONFIG_STMMAC_TIMER
kfree(priv->tm);
#endif
if (priv->phydev)
phy_disconnect(priv->phydev);
return ret;
}
static int stmmac_release(struct net_device *dev)
{
struct stmmac_priv *priv = netdev_priv(dev);
if (priv->phydev) {
phy_stop(priv->phydev);
phy_disconnect(priv->phydev);
priv->phydev = NULL;
}
netif_stop_queue(dev);
#ifdef CONFIG_STMMAC_TIMER
stmmac_close_ext_timer();
if (priv->tm != NULL)
kfree(priv->tm);
#endif
napi_disable(&priv->napi);
skb_queue_purge(&priv->rx_recycle);
free_irq(dev->irq, dev);
if (priv->wol_irq != dev->irq)
free_irq(priv->wol_irq, dev);
priv->hw->dma->stop_tx(priv->ioaddr);
priv->hw->dma->stop_rx(priv->ioaddr);
free_dma_desc_resources(priv);
stmmac_set_mac(priv->ioaddr, false);
netif_carrier_off(dev);
#ifdef CONFIG_STMMAC_DEBUG_FS
stmmac_exit_fs();
#endif
stmmac_mdio_unregister(dev);
return 0;
}
static netdev_tx_t stmmac_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct stmmac_priv *priv = netdev_priv(dev);
unsigned int txsize = priv->dma_tx_size;
unsigned int entry;
int i, csum_insertion = 0;
int nfrags = skb_shinfo(skb)->nr_frags;
struct dma_desc *desc, *first;
unsigned int nopaged_len = skb_headlen(skb);
if (unlikely(stmmac_tx_avail(priv) < nfrags + 1)) {
if (!netif_queue_stopped(dev)) {
netif_stop_queue(dev);
pr_err("%s: BUG! Tx Ring full when queue awake\n",
__func__);
}
return NETDEV_TX_BUSY;
}
spin_lock(&priv->tx_lock);
entry = priv->cur_tx % txsize;
#ifdef STMMAC_XMIT_DEBUG
if ((skb->len > ETH_FRAME_LEN) || nfrags)
pr_info("stmmac xmit:\n"
"\tskb addr %p - len: %d - nopaged_len: %d\n"
"\tn_frags: %d - ip_summed: %d - %s gso\n",
skb, skb->len, nopaged_len, nfrags, skb->ip_summed,
!skb_is_gso(skb) ? "isn't" : "is");
#endif
csum_insertion = (skb->ip_summed == CHECKSUM_PARTIAL);
desc = priv->dma_tx + entry;
first = desc;
#ifdef STMMAC_XMIT_DEBUG
if ((nfrags > 0) || (skb->len > ETH_FRAME_LEN))
pr_debug("stmmac xmit: skb len: %d, nopaged_len: %d,\n"
"\t\tn_frags: %d, ip_summed: %d\n",
skb->len, nopaged_len, nfrags, skb->ip_summed);
#endif
priv->tx_skbuff[entry] = skb;
if (priv->hw->ring->is_jumbo_frm(skb->len, priv->plat->enh_desc)) {
entry = priv->hw->ring->jumbo_frm(priv, skb, csum_insertion);
desc = priv->dma_tx + entry;
} else {
desc->des2 = dma_map_single(priv->device, skb->data,
nopaged_len, DMA_TO_DEVICE);
priv->hw->desc->prepare_tx_desc(desc, 1, nopaged_len,
csum_insertion);
}
for (i = 0; i < nfrags; i++) {
const skb_frag_t *frag = &skb_shinfo(skb)->frags[i];
int len = skb_frag_size(frag);
entry = (++priv->cur_tx) % txsize;
desc = priv->dma_tx + entry;
TX_DBG("\t[entry %d] segment len: %d\n", entry, len);
desc->des2 = skb_frag_dma_map(priv->device, frag, 0, len,
DMA_TO_DEVICE);
priv->tx_skbuff[entry] = NULL;
priv->hw->desc->prepare_tx_desc(desc, 0, len, csum_insertion);
wmb();
priv->hw->desc->set_tx_owner(desc);
}
priv->hw->desc->close_tx_desc(desc);
#ifdef CONFIG_STMMAC_TIMER
if (likely(priv->tm->enable))
priv->hw->desc->clear_tx_ic(desc);
#endif
wmb();
priv->hw->desc->set_tx_owner(first);
priv->cur_tx++;
#ifdef STMMAC_XMIT_DEBUG
if (netif_msg_pktdata(priv)) {
pr_info("stmmac xmit: current=%d, dirty=%d, entry=%d, "
"first=%p, nfrags=%d\n",
(priv->cur_tx % txsize), (priv->dirty_tx % txsize),
entry, first, nfrags);
display_ring(priv->dma_tx, txsize);
pr_info(">>> frame to be transmitted: ");
print_pkt(skb->data, skb->len);
}
#endif
if (unlikely(stmmac_tx_avail(priv) <= (MAX_SKB_FRAGS + 1))) {
TX_DBG("%s: stop transmitted packets\n", __func__);
netif_stop_queue(dev);
}
dev->stats.tx_bytes += skb->len;
skb_tx_timestamp(skb);
priv->hw->dma->enable_dma_transmission(priv->ioaddr);
spin_unlock(&priv->tx_lock);
return NETDEV_TX_OK;
}
static inline void stmmac_rx_refill(struct stmmac_priv *priv)
{
unsigned int rxsize = priv->dma_rx_size;
int bfsize = priv->dma_buf_sz;
struct dma_desc *p = priv->dma_rx;
for (; priv->cur_rx - priv->dirty_rx > 0; priv->dirty_rx++) {
unsigned int entry = priv->dirty_rx % rxsize;
if (likely(priv->rx_skbuff[entry] == NULL)) {
struct sk_buff *skb;
skb = __skb_dequeue(&priv->rx_recycle);
if (skb == NULL)
skb = netdev_alloc_skb_ip_align(priv->dev,
bfsize);
if (unlikely(skb == NULL))
break;
priv->rx_skbuff[entry] = skb;
priv->rx_skbuff_dma[entry] =
dma_map_single(priv->device, skb->data, bfsize,
DMA_FROM_DEVICE);
(p + entry)->des2 = priv->rx_skbuff_dma[entry];
if (unlikely(priv->plat->has_gmac))
priv->hw->ring->refill_desc3(bfsize, p + entry);
RX_DBG(KERN_INFO "\trefill entry #%d\n", entry);
}
wmb();
priv->hw->desc->set_rx_owner(p + entry);
}
}
static int stmmac_rx(struct stmmac_priv *priv, int limit)
{
unsigned int rxsize = priv->dma_rx_size;
unsigned int entry = priv->cur_rx % rxsize;
unsigned int next_entry;
unsigned int count = 0;
struct dma_desc *p = priv->dma_rx + entry;
struct dma_desc *p_next;
#ifdef STMMAC_RX_DEBUG
if (netif_msg_hw(priv)) {
pr_debug(">>> stmmac_rx: descriptor ring:\n");
display_ring(priv->dma_rx, rxsize);
}
#endif
count = 0;
while (!priv->hw->desc->get_rx_owner(p)) {
int status;
if (count >= limit)
break;
count++;
next_entry = (++priv->cur_rx) % rxsize;
p_next = priv->dma_rx + next_entry;
prefetch(p_next);
status = (priv->hw->desc->rx_status(&priv->dev->stats,
&priv->xstats, p));
if (unlikely(status == discard_frame))
priv->dev->stats.rx_errors++;
else {
struct sk_buff *skb;
int frame_len;
frame_len = priv->hw->desc->get_rx_frame_len(p);
if (unlikely(status != llc_snap))
frame_len -= ETH_FCS_LEN;
#ifdef STMMAC_RX_DEBUG
if (frame_len > ETH_FRAME_LEN)
pr_debug("\tRX frame size %d, COE status: %d\n",
frame_len, status);
if (netif_msg_hw(priv))
pr_debug("\tdesc: %p [entry %d] buff=0x%x\n",
p, entry, p->des2);
#endif
skb = priv->rx_skbuff[entry];
if (unlikely(!skb)) {
pr_err("%s: Inconsistent Rx descriptor chain\n",
priv->dev->name);
priv->dev->stats.rx_dropped++;
break;
}
prefetch(skb->data - NET_IP_ALIGN);
priv->rx_skbuff[entry] = NULL;
skb_put(skb, frame_len);
dma_unmap_single(priv->device,
priv->rx_skbuff_dma[entry],
priv->dma_buf_sz, DMA_FROM_DEVICE);
#ifdef STMMAC_RX_DEBUG
if (netif_msg_pktdata(priv)) {
pr_info(" frame received (%dbytes)", frame_len);
print_pkt(skb->data, frame_len);
}
#endif
skb->protocol = eth_type_trans(skb, priv->dev);
if (unlikely(!priv->rx_coe)) {
skb_checksum_none_assert(skb);
netif_receive_skb(skb);
} else {
skb->ip_summed = CHECKSUM_UNNECESSARY;
napi_gro_receive(&priv->napi, skb);
}
priv->dev->stats.rx_packets++;
priv->dev->stats.rx_bytes += frame_len;
}
entry = next_entry;
p = p_next;
}
stmmac_rx_refill(priv);
priv->xstats.rx_pkt_n += count;
return count;
}
static int stmmac_poll(struct napi_struct *napi, int budget)
{
struct stmmac_priv *priv = container_of(napi, struct stmmac_priv, napi);
int work_done = 0;
priv->xstats.poll_n++;
stmmac_tx(priv);
work_done = stmmac_rx(priv, budget);
if (work_done < budget) {
napi_complete(napi);
stmmac_enable_irq(priv);
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
pr_warning("%s: can't change I/O address\n", dev->name);
return -EOPNOTSUPP;
}
if (map->irq != dev->irq) {
pr_warning("%s: can't change IRQ number %d\n",
dev->name, dev->irq);
return -EOPNOTSUPP;
}
return 0;
}
static void stmmac_set_rx_mode(struct net_device *dev)
{
struct stmmac_priv *priv = netdev_priv(dev);
spin_lock(&priv->lock);
priv->hw->mac->set_filter(dev);
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
if (!priv->rx_coe)
features &= ~NETIF_F_RXCSUM;
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
if (unlikely(!dev)) {
pr_err("%s: invalid dev pointer\n", __func__);
return IRQ_NONE;
}
if (priv->plat->has_gmac)
priv->hw->mac->host_irq_status((void __iomem *) dev->base_addr);
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
int ret;
if (!netif_running(dev))
return -EINVAL;
if (!priv->phydev)
return -EINVAL;
ret = phy_mii_ioctl(priv->phydev, rq, cmd);
return ret;
}
static int stmmac_sysfs_ring_read(struct seq_file *seq, void *v)
{
struct tmp_s {
u64 a;
unsigned int b;
unsigned int c;
};
int i;
struct net_device *dev = seq->private;
struct stmmac_priv *priv = netdev_priv(dev);
seq_printf(seq, "=======================\n");
seq_printf(seq, " RX descriptor ring\n");
seq_printf(seq, "=======================\n");
for (i = 0; i < priv->dma_rx_size; i++) {
struct tmp_s *x = (struct tmp_s *)(priv->dma_rx + i);
seq_printf(seq, "[%d] DES0=0x%x DES1=0x%x BUF1=0x%x BUF2=0x%x",
i, (unsigned int)(x->a),
(unsigned int)((x->a) >> 32), x->b, x->c);
seq_printf(seq, "\n");
}
seq_printf(seq, "\n");
seq_printf(seq, "=======================\n");
seq_printf(seq, " TX descriptor ring\n");
seq_printf(seq, "=======================\n");
for (i = 0; i < priv->dma_tx_size; i++) {
struct tmp_s *x = (struct tmp_s *)(priv->dma_tx + i);
seq_printf(seq, "[%d] DES0=0x%x DES1=0x%x BUF1=0x%x BUF2=0x%x",
i, (unsigned int)(x->a),
(unsigned int)((x->a) >> 32), x->b, x->c);
seq_printf(seq, "\n");
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
int ret = 0;
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
priv->hw->ring = &ring_mode_ops;
stmmac_get_synopsys_id(priv);
priv->hw_cap_support = stmmac_get_hw_features(priv);
if (priv->hw_cap_support) {
pr_info(" DMA HW capability register supported");
priv->plat->enh_desc = priv->dma_cap.enh_desc;
priv->plat->tx_coe = priv->dma_cap.tx_coe;
priv->plat->pmt = priv->dma_cap.pmt_remote_wake_up;
} else
pr_info(" No HW DMA feature register supported");
stmmac_selec_desc_mode(priv);
priv->rx_coe = priv->hw->mac->rx_coe(priv->ioaddr);
if (priv->rx_coe)
pr_info(" RX Checksum Offload Engine supported\n");
if (priv->plat->tx_coe)
pr_info(" TX Checksum insertion supported\n");
if (priv->plat->pmt) {
pr_info(" Wake-Up On Lan supported\n");
device_set_wakeup_capable(priv->device, 1);
}
return ret;
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
stmmac_hw_init(priv);
ndev->netdev_ops = &stmmac_netdev_ops;
ndev->hw_features = NETIF_F_SG | NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM |
NETIF_F_RXCSUM;
ndev->features |= ndev->hw_features | NETIF_F_HIGHDMA;
ndev->watchdog_timeo = msecs_to_jiffies(watchdog);
#ifdef STMMAC_VLAN_TAG_USED
ndev->features |= NETIF_F_HW_VLAN_RX;
#endif
priv->msg_enable = netif_msg_init(debug, default_msg_level);
if (flow_ctrl)
priv->flow_ctrl = FLOW_AUTO;
netif_napi_add(ndev, &priv->napi, stmmac_poll, 64);
spin_lock_init(&priv->lock);
spin_lock_init(&priv->tx_lock);
ret = register_netdev(ndev);
if (ret) {
pr_err("%s: ERROR %i registering the device\n", __func__, ret);
goto error;
}
return priv;
error:
netif_napi_del(&priv->napi);
unregister_netdev(ndev);
free_netdev(ndev);
return NULL;
}
int stmmac_dvr_remove(struct net_device *ndev)
{
struct stmmac_priv *priv = netdev_priv(ndev);
pr_info("%s:\n\tremoving driver", __func__);
priv->hw->dma->stop_rx(priv->ioaddr);
priv->hw->dma->stop_tx(priv->ioaddr);
stmmac_set_mac(priv->ioaddr, false);
netif_carrier_off(ndev);
unregister_netdev(ndev);
free_netdev(ndev);
return 0;
}
int stmmac_suspend(struct net_device *ndev)
{
struct stmmac_priv *priv = netdev_priv(ndev);
int dis_ic = 0;
if (!ndev || !netif_running(ndev))
return 0;
if (priv->phydev)
phy_stop(priv->phydev);
spin_lock(&priv->lock);
netif_device_detach(ndev);
netif_stop_queue(ndev);
#ifdef CONFIG_STMMAC_TIMER
priv->tm->timer_stop();
if (likely(priv->tm->enable))
dis_ic = 1;
#endif
napi_disable(&priv->napi);
priv->hw->dma->stop_tx(priv->ioaddr);
priv->hw->dma->stop_rx(priv->ioaddr);
priv->hw->desc->init_rx_desc(priv->dma_rx, priv->dma_rx_size,
dis_ic);
priv->hw->desc->init_tx_desc(priv->dma_tx, priv->dma_tx_size);
if (device_may_wakeup(priv->device))
priv->hw->mac->pmt(priv->ioaddr, priv->wolopts);
else
stmmac_set_mac(priv->ioaddr, false);
spin_unlock(&priv->lock);
return 0;
}
int stmmac_resume(struct net_device *ndev)
{
struct stmmac_priv *priv = netdev_priv(ndev);
if (!netif_running(ndev))
return 0;
spin_lock(&priv->lock);
if (device_may_wakeup(priv->device))
priv->hw->mac->pmt(priv->ioaddr, 0);
netif_device_attach(ndev);
stmmac_set_mac(priv->ioaddr, true);
priv->hw->dma->start_tx(priv->ioaddr);
priv->hw->dma->start_rx(priv->ioaddr);
#ifdef CONFIG_STMMAC_TIMER
if (likely(priv->tm->enable))
priv->tm->timer_start(tmrate);
#endif
napi_enable(&priv->napi);
netif_start_queue(ndev);
spin_unlock(&priv->lock);
if (priv->phydev)
phy_start(priv->phydev);
return 0;
}
int stmmac_freeze(struct net_device *ndev)
{
if (!ndev || !netif_running(ndev))
return 0;
return stmmac_release(ndev);
}
int stmmac_restore(struct net_device *ndev)
{
if (!ndev || !netif_running(ndev))
return 0;
return stmmac_open(ndev);
}
static int __init stmmac_cmdline_opt(char *str)
{
char *opt;
if (!str || !*str)
return -EINVAL;
while ((opt = strsep(&str, ",")) != NULL) {
if (!strncmp(opt, "debug:", 6)) {
if (strict_strtoul(opt + 6, 0, (unsigned long *)&debug))
goto err;
} else if (!strncmp(opt, "phyaddr:", 8)) {
if (strict_strtoul(opt + 8, 0,
(unsigned long *)&phyaddr))
goto err;
} else if (!strncmp(opt, "dma_txsize:", 11)) {
if (strict_strtoul(opt + 11, 0,
(unsigned long *)&dma_txsize))
goto err;
} else if (!strncmp(opt, "dma_rxsize:", 11)) {
if (strict_strtoul(opt + 11, 0,
(unsigned long *)&dma_rxsize))
goto err;
} else if (!strncmp(opt, "buf_sz:", 7)) {
if (strict_strtoul(opt + 7, 0,
(unsigned long *)&buf_sz))
goto err;
} else if (!strncmp(opt, "tc:", 3)) {
if (strict_strtoul(opt + 3, 0, (unsigned long *)&tc))
goto err;
} else if (!strncmp(opt, "watchdog:", 9)) {
if (strict_strtoul(opt + 9, 0,
(unsigned long *)&watchdog))
goto err;
} else if (!strncmp(opt, "flow_ctrl:", 10)) {
if (strict_strtoul(opt + 10, 0,
(unsigned long *)&flow_ctrl))
goto err;
} else if (!strncmp(opt, "pause:", 6)) {
if (strict_strtoul(opt + 6, 0, (unsigned long *)&pause))
goto err;
#ifdef CONFIG_STMMAC_TIMER
} else if (!strncmp(opt, "tmrate:", 7)) {
if (strict_strtoul(opt + 7, 0,
(unsigned long *)&tmrate))
goto err;
#endif
}
}
return 0;
err:
pr_err("%s: ERROR broken module parameter conversion", __func__);
return -EINVAL;
}
