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
priv->oldlink = 0;
priv->speed = 0;
priv->oldduplex = -1;
snprintf(bus_id, MII_BUS_ID_SIZE, "%x", priv->plat->bus_id);
snprintf(phy_id, MII_BUS_ID_SIZE + 3, PHY_ID_FMT, bus_id,
priv->plat->phy_addr);
pr_debug("stmmac_init_phy: trying to attach to %s\n", phy_id);
phydev = phy_connect(dev, phy_id, &stmmac_adjust_link, 0,
priv->plat->interface);
if (IS_ERR(phydev)) {
pr_err("%s: Could not attach to PHY\n", dev->name);
return PTR_ERR(phydev);
}
if (phydev->phy_id == 0) {
phy_disconnect(phydev);
return -ENODEV;
}
pr_debug("stmmac_init_phy: %s: attached to PHY (UID 0x%x)"
" Link = %d\n", dev->name, phydev->phy_id, phydev->link);
priv->phydev = phydev;
return 0;
}
static inline void stmmac_enable_mac(void __iomem *ioaddr)
{
u32 value = readl(ioaddr + MAC_CTRL_REG);
value |= MAC_RNABLE_RX | MAC_ENABLE_TX;
writel(value, ioaddr + MAC_CTRL_REG);
}
static inline void stmmac_disable_mac(void __iomem *ioaddr)
{
u32 value = readl(ioaddr + MAC_CTRL_REG);
value &= ~(MAC_ENABLE_TX | MAC_RNABLE_RX);
writel(value, ioaddr + MAC_CTRL_REG);
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
static void init_dma_desc_rings(struct net_device *dev)
{
int i;
struct stmmac_priv *priv = netdev_priv(dev);
struct sk_buff *skb;
unsigned int txsize = priv->dma_tx_size;
unsigned int rxsize = priv->dma_rx_size;
unsigned int bfsize = priv->dma_buf_sz;
int buff2_needed = 0, dis_ic = 0;
if (unlikely(dev->mtu >= BUF_SIZE_8KiB))
bfsize = BUF_SIZE_16KiB;
else if (unlikely(dev->mtu >= BUF_SIZE_4KiB))
bfsize = BUF_SIZE_8KiB;
else if (unlikely(dev->mtu >= BUF_SIZE_2KiB))
bfsize = BUF_SIZE_4KiB;
else if (unlikely(dev->mtu >= DMA_BUFFER_SIZE))
bfsize = BUF_SIZE_2KiB;
else
bfsize = DMA_BUFFER_SIZE;
#ifdef CONFIG_STMMAC_TIMER
if (likely(priv->tm->enable))
dis_ic = 1;
#endif
if (bfsize >= BUF_SIZE_8KiB)
buff2_needed = 1;
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
DBG(probe, INFO, "stmmac (%s) DMA desc rings: virt addr (Rx %p, "
"Tx %p)\n\tDMA phy addr (Rx 0x%08x, Tx 0x%08x)\n",
dev->name, priv->dma_rx, priv->dma_tx,
(unsigned int)priv->dma_rx_phy, (unsigned int)priv->dma_tx_phy);
DBG(probe, INFO, "stmmac: SKB addresses:\n"
"skb\t\tskb data\tdma data\n");
for (i = 0; i < rxsize; i++) {
struct dma_desc *p = priv->dma_rx + i;
skb = netdev_alloc_skb_ip_align(dev, bfsize);
if (unlikely(skb == NULL)) {
pr_err("%s: Rx init fails; skb is NULL\n", __func__);
break;
}
priv->rx_skbuff[i] = skb;
priv->rx_skbuff_dma[i] = dma_map_single(priv->device, skb->data,
bfsize, DMA_FROM_DEVICE);
p->des2 = priv->rx_skbuff_dma[i];
if (unlikely(buff2_needed))
p->des3 = p->des2 + BUF_SIZE_8KiB;
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
if (unlikely(p->des3))
p->des3 = 0;
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
static int stmmac_open(struct net_device *dev)
{
struct stmmac_priv *priv = netdev_priv(dev);
int ret;
if (!is_valid_ether_addr(dev->dev_addr)) {
random_ether_addr(dev->dev_addr);
pr_warning("%s: generated random MAC address %pM\n", dev->name,
dev->dev_addr);
}
stmmac_verify_args();
#ifdef CONFIG_STMMAC_TIMER
priv->tm = kzalloc(sizeof(struct stmmac_timer *), GFP_KERNEL);
if (unlikely(priv->tm == NULL)) {
pr_err("%s: ERROR: timer memory alloc failed\n", __func__);
return -ENOMEM;
}
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
priv->rx_coe = priv->hw->mac->rx_coe(priv->ioaddr);
if (priv->rx_coe)
pr_info("stmmac: Rx Checksum Offload Engine supported\n");
if (priv->plat->tx_coe)
pr_info("\tTX Checksum insertion supported\n");
netdev_update_features(dev);
writel(0xffffffff, priv->ioaddr + MMC_HIGH_INTR_MASK);
writel(0xffffffff, priv->ioaddr + MMC_LOW_INTR_MASK);
ret = request_irq(dev->irq, stmmac_interrupt,
IRQF_SHARED, dev->name, dev);
if (unlikely(ret < 0)) {
pr_err("%s: ERROR: allocating the IRQ %d (error: %d)\n",
__func__, dev->irq, ret);
goto open_error;
}
stmmac_enable_mac(priv->ioaddr);
stmmac_dma_operation_mode(priv);
memset(&priv->xstats, 0, sizeof(struct stmmac_extra_stats));
priv->xstats.threshold = tc;
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
priv->hw->dma->stop_tx(priv->ioaddr);
priv->hw->dma->stop_rx(priv->ioaddr);
free_dma_desc_resources(priv);
stmmac_disable_mac(priv->ioaddr);
netif_carrier_off(dev);
return 0;
}
static unsigned int stmmac_handle_jumbo_frames(struct sk_buff *skb,
struct net_device *dev,
int csum_insertion)
{
struct stmmac_priv *priv = netdev_priv(dev);
unsigned int nopaged_len = skb_headlen(skb);
unsigned int txsize = priv->dma_tx_size;
unsigned int entry = priv->cur_tx % txsize;
struct dma_desc *desc = priv->dma_tx + entry;
if (nopaged_len > BUF_SIZE_8KiB) {
int buf2_size = nopaged_len - BUF_SIZE_8KiB;
desc->des2 = dma_map_single(priv->device, skb->data,
BUF_SIZE_8KiB, DMA_TO_DEVICE);
desc->des3 = desc->des2 + BUF_SIZE_4KiB;
priv->hw->desc->prepare_tx_desc(desc, 1, BUF_SIZE_8KiB,
csum_insertion);
entry = (++priv->cur_tx) % txsize;
desc = priv->dma_tx + entry;
desc->des2 = dma_map_single(priv->device,
skb->data + BUF_SIZE_8KiB,
buf2_size, DMA_TO_DEVICE);
desc->des3 = desc->des2 + BUF_SIZE_4KiB;
priv->hw->desc->prepare_tx_desc(desc, 0, buf2_size,
csum_insertion);
priv->hw->desc->set_tx_owner(desc);
priv->tx_skbuff[entry] = NULL;
} else {
desc->des2 = dma_map_single(priv->device, skb->data,
nopaged_len, DMA_TO_DEVICE);
desc->des3 = desc->des2 + BUF_SIZE_4KiB;
priv->hw->desc->prepare_tx_desc(desc, 1, nopaged_len,
csum_insertion);
}
return entry;
}
static netdev_tx_t stmmac_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct stmmac_priv *priv = netdev_priv(dev);
unsigned int txsize = priv->dma_tx_size;
unsigned int entry;
int i, csum_insertion = 0;
int nfrags = skb_shinfo(skb)->nr_frags;
struct dma_desc *desc, *first;
if (unlikely(stmmac_tx_avail(priv) < nfrags + 1)) {
if (!netif_queue_stopped(dev)) {
netif_stop_queue(dev);
pr_err("%s: BUG! Tx Ring full when queue awake\n",
__func__);
}
return NETDEV_TX_BUSY;
}
entry = priv->cur_tx % txsize;
#ifdef STMMAC_XMIT_DEBUG
if ((skb->len > ETH_FRAME_LEN) || nfrags)
pr_info("stmmac xmit:\n"
"\tskb addr %p - len: %d - nopaged_len: %d\n"
"\tn_frags: %d - ip_summed: %d - %s gso\n",
skb, skb->len, skb_headlen(skb), nfrags, skb->ip_summed,
!skb_is_gso(skb) ? "isn't" : "is");
#endif
csum_insertion = (skb->ip_summed == CHECKSUM_PARTIAL);
desc = priv->dma_tx + entry;
first = desc;
#ifdef STMMAC_XMIT_DEBUG
if ((nfrags > 0) || (skb->len > ETH_FRAME_LEN))
pr_debug("stmmac xmit: skb len: %d, nopaged_len: %d,\n"
"\t\tn_frags: %d, ip_summed: %d\n",
skb->len, skb_headlen(skb), nfrags, skb->ip_summed);
#endif
priv->tx_skbuff[entry] = skb;
if (unlikely(skb->len >= BUF_SIZE_4KiB)) {
entry = stmmac_handle_jumbo_frames(skb, dev, csum_insertion);
desc = priv->dma_tx + entry;
} else {
unsigned int nopaged_len = skb_headlen(skb);
desc->des2 = dma_map_single(priv->device, skb->data,
nopaged_len, DMA_TO_DEVICE);
priv->hw->desc->prepare_tx_desc(desc, 1, nopaged_len,
csum_insertion);
}
for (i = 0; i < nfrags; i++) {
skb_frag_t *frag = &skb_shinfo(skb)->frags[i];
int len = frag->size;
entry = (++priv->cur_tx) % txsize;
desc = priv->dma_tx + entry;
TX_DBG("\t[entry %d] segment len: %d\n", entry, len);
desc->des2 = dma_map_page(priv->device, frag->page,
frag->page_offset,
len, DMA_TO_DEVICE);
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
if (unlikely(priv->plat->has_gmac)) {
if (bfsize >= BUF_SIZE_8KiB)
(p + entry)->des3 =
(p + entry)->des2 + BUF_SIZE_8KiB;
}
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
if (unlikely(status == csum_none)) {
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
static void stmmac_multicast_list(struct net_device *dev)
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
if (priv->plat->has_gmac)
max_mtu = JUMBO_LEN;
else
max_mtu = ETH_DATA_LEN;
if ((new_mtu < 46) || (new_mtu > max_mtu)) {
pr_err("%s: invalid MTU, max MTU is: %d\n", dev->name, max_mtu);
return -EINVAL;
}
dev->mtu = new_mtu;
netdev_update_features(dev);
return 0;
}
static u32 stmmac_fix_features(struct net_device *dev, u32 features)
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
spin_lock(&priv->lock);
ret = phy_mii_ioctl(priv->phydev, rq, cmd);
spin_unlock(&priv->lock);
return ret;
}
static int stmmac_probe(struct net_device *dev)
{
int ret = 0;
struct stmmac_priv *priv = netdev_priv(dev);
ether_setup(dev);
dev->netdev_ops = &stmmac_netdev_ops;
stmmac_set_ethtool_ops(dev);
dev->hw_features = NETIF_F_SG | NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM;
dev->features |= dev->hw_features | NETIF_F_HIGHDMA;
dev->watchdog_timeo = msecs_to_jiffies(watchdog);
#ifdef STMMAC_VLAN_TAG_USED
dev->features |= NETIF_F_HW_VLAN_RX;
#endif
priv->msg_enable = netif_msg_init(debug, default_msg_level);
if (flow_ctrl)
priv->flow_ctrl = FLOW_AUTO;
priv->pause = pause;
netif_napi_add(dev, &priv->napi, stmmac_poll, 64);
priv->hw->mac->get_umac_addr((void __iomem *) dev->base_addr,
dev->dev_addr, 0);
if (!is_valid_ether_addr(dev->dev_addr))
pr_warning("\tno valid MAC address;"
"please, use ifconfig or nwhwconfig!\n");
spin_lock_init(&priv->lock);
ret = register_netdev(dev);
if (ret) {
pr_err("%s: ERROR %i registering the device\n",
__func__, ret);
return -ENODEV;
}
DBG(probe, DEBUG, "%s: Scatter/Gather: %s - HW checksums: %s\n",
dev->name, (dev->features & NETIF_F_SG) ? "on" : "off",
(dev->features & NETIF_F_IP_CSUM) ? "on" : "off");
return ret;
}
static int stmmac_mac_device_setup(struct net_device *dev)
{
struct stmmac_priv *priv = netdev_priv(dev);
struct mac_device_info *device;
if (priv->plat->has_gmac)
device = dwmac1000_setup(priv->ioaddr);
else
device = dwmac100_setup(priv->ioaddr);
if (!device)
return -ENOMEM;
if (priv->plat->enh_desc) {
device->desc = &enh_desc_ops;
pr_info("\tEnhanced descriptor structure\n");
} else
device->desc = &ndesc_ops;
priv->hw = device;
if (device_can_wakeup(priv->device)) {
priv->wolopts = WAKE_MAGIC;
enable_irq_wake(dev->irq);
}
return 0;
}
static int stmmac_dvr_probe(struct platform_device *pdev)
{
int ret = 0;
struct resource *res;
void __iomem *addr = NULL;
struct net_device *ndev = NULL;
struct stmmac_priv *priv = NULL;
struct plat_stmmacenet_data *plat_dat;
pr_info("STMMAC driver:\n\tplatform registration... ");
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
pr_info("\tdone!\n");
if (!request_mem_region(res->start, resource_size(res),
pdev->name)) {
pr_err("%s: ERROR: memory allocation failed"
"cannot get the I/O addr 0x%x\n",
__func__, (unsigned int)res->start);
return -EBUSY;
}
addr = ioremap(res->start, resource_size(res));
if (!addr) {
pr_err("%s: ERROR: memory mapping failed\n", __func__);
ret = -ENOMEM;
goto out_release_region;
}
ndev = alloc_etherdev(sizeof(struct stmmac_priv));
if (!ndev) {
pr_err("%s: ERROR: allocating the device\n", __func__);
ret = -ENOMEM;
goto out_unmap;
}
SET_NETDEV_DEV(ndev, &pdev->dev);
ndev->irq = platform_get_irq_byname(pdev, "macirq");
if (ndev->irq == -ENXIO) {
pr_err("%s: ERROR: MAC IRQ configuration "
"information not found\n", __func__);
ret = -ENXIO;
goto out_free_ndev;
}
priv = netdev_priv(ndev);
priv->device = &(pdev->dev);
priv->dev = ndev;
plat_dat = pdev->dev.platform_data;
priv->plat = plat_dat;
priv->ioaddr = addr;
if (plat_dat->pmt) {
pr_info("\tPMT module supported\n");
device_set_wakeup_capable(&pdev->dev, 1);
}
platform_set_drvdata(pdev, ndev);
ndev->base_addr = (unsigned long)addr;
if (priv->plat->init) {
ret = priv->plat->init(pdev);
if (unlikely(ret))
goto out_free_ndev;
}
ret = stmmac_mac_device_setup(ndev);
if (ret < 0)
goto out_plat_exit;
ret = stmmac_probe(ndev);
if (ret < 0)
goto out_plat_exit;
if ((phyaddr >= 0) && (phyaddr <= 31))
priv->plat->phy_addr = phyaddr;
pr_info("\t%s - (dev. name: %s - id: %d, IRQ #%d\n"
"\tIO base addr: 0x%p)\n", ndev->name, pdev->name,
pdev->id, ndev->irq, addr);
pr_debug("\tMDIO bus (id: %d)...", priv->plat->bus_id);
ret = stmmac_mdio_register(ndev);
if (ret < 0)
goto out_unregister;
pr_debug("registered!\n");
return 0;
out_unregister:
unregister_netdev(ndev);
out_plat_exit:
if (priv->plat->exit)
priv->plat->exit(pdev);
out_free_ndev:
free_netdev(ndev);
platform_set_drvdata(pdev, NULL);
out_unmap:
iounmap(addr);
out_release_region:
release_mem_region(res->start, resource_size(res));
return ret;
}
static int stmmac_dvr_remove(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct stmmac_priv *priv = netdev_priv(ndev);
struct resource *res;
pr_info("%s:\n\tremoving driver", __func__);
priv->hw->dma->stop_rx(priv->ioaddr);
priv->hw->dma->stop_tx(priv->ioaddr);
stmmac_disable_mac(priv->ioaddr);
netif_carrier_off(ndev);
stmmac_mdio_unregister(ndev);
if (priv->plat->exit)
priv->plat->exit(pdev);
platform_set_drvdata(pdev, NULL);
unregister_netdev(ndev);
iounmap((void *)priv->ioaddr);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(res->start, resource_size(res));
free_netdev(ndev);
return 0;
}
static int stmmac_suspend(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
struct stmmac_priv *priv = netdev_priv(ndev);
int dis_ic = 0;
if (!ndev || !netif_running(ndev))
return 0;
spin_lock(&priv->lock);
netif_device_detach(ndev);
netif_stop_queue(ndev);
if (priv->phydev)
phy_stop(priv->phydev);
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
stmmac_disable_mac(priv->ioaddr);
spin_unlock(&priv->lock);
return 0;
}
static int stmmac_resume(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
struct stmmac_priv *priv = netdev_priv(ndev);
if (!netif_running(ndev))
return 0;
spin_lock(&priv->lock);
if (device_may_wakeup(priv->device))
priv->hw->mac->pmt(priv->ioaddr, 0);
netif_device_attach(ndev);
stmmac_enable_mac(priv->ioaddr);
priv->hw->dma->start_tx(priv->ioaddr);
priv->hw->dma->start_rx(priv->ioaddr);
#ifdef CONFIG_STMMAC_TIMER
if (likely(priv->tm->enable))
priv->tm->timer_start(tmrate);
#endif
napi_enable(&priv->napi);
if (priv->phydev)
phy_start(priv->phydev);
netif_start_queue(ndev);
spin_unlock(&priv->lock);
return 0;
}
static int stmmac_freeze(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
if (!ndev || !netif_running(ndev))
return 0;
return stmmac_release(ndev);
}
static int stmmac_restore(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
if (!ndev || !netif_running(ndev))
return 0;
return stmmac_open(ndev);
}
static int __init stmmac_init_module(void)
{
int ret;
ret = platform_driver_register(&stmmac_driver);
return ret;
}
static void __exit stmmac_cleanup_module(void)
{
platform_driver_unregister(&stmmac_driver);
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
