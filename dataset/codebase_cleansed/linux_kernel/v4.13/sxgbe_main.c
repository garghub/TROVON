static void sxgbe_verify_args(void)
{
if (unlikely(eee_timer < 0))
eee_timer = SXGBE_DEFAULT_LPI_TIMER;
}
static void sxgbe_enable_eee_mode(const struct sxgbe_priv_data *priv)
{
if (!priv->tx_path_in_lpi_mode)
priv->hw->mac->set_eee_mode(priv->ioaddr);
}
void sxgbe_disable_eee_mode(struct sxgbe_priv_data * const priv)
{
priv->hw->mac->reset_eee_mode(priv->ioaddr);
del_timer_sync(&priv->eee_ctrl_timer);
priv->tx_path_in_lpi_mode = false;
}
static void sxgbe_eee_ctrl_timer(unsigned long arg)
{
struct sxgbe_priv_data *priv = (struct sxgbe_priv_data *)arg;
sxgbe_enable_eee_mode(priv);
mod_timer(&priv->eee_ctrl_timer, SXGBE_LPI_TIMER(eee_timer));
}
bool sxgbe_eee_init(struct sxgbe_priv_data * const priv)
{
struct net_device *ndev = priv->dev;
bool ret = false;
if (priv->hw_cap.eee) {
if (phy_init_eee(ndev->phydev, 1))
return false;
priv->eee_active = 1;
setup_timer(&priv->eee_ctrl_timer, sxgbe_eee_ctrl_timer,
(unsigned long)priv);
priv->eee_ctrl_timer.expires = SXGBE_LPI_TIMER(eee_timer);
add_timer(&priv->eee_ctrl_timer);
priv->hw->mac->set_eee_timer(priv->ioaddr,
SXGBE_DEFAULT_LPI_TIMER,
priv->tx_lpi_timer);
pr_info("Energy-Efficient Ethernet initialized\n");
ret = true;
}
return ret;
}
static void sxgbe_eee_adjust(const struct sxgbe_priv_data *priv)
{
struct net_device *ndev = priv->dev;
if (priv->eee_enabled)
priv->hw->mac->set_eee_pls(priv->ioaddr, ndev->phydev->link);
}
static void sxgbe_clk_csr_set(struct sxgbe_priv_data *priv)
{
u32 clk_rate = clk_get_rate(priv->sxgbe_clk);
if (clk_rate < SXGBE_CSR_F_150M)
priv->clk_csr = SXGBE_CSR_100_150M;
else if (clk_rate <= SXGBE_CSR_F_250M)
priv->clk_csr = SXGBE_CSR_150_250M;
else if (clk_rate <= SXGBE_CSR_F_300M)
priv->clk_csr = SXGBE_CSR_250_300M;
else if (clk_rate <= SXGBE_CSR_F_350M)
priv->clk_csr = SXGBE_CSR_300_350M;
else if (clk_rate <= SXGBE_CSR_F_400M)
priv->clk_csr = SXGBE_CSR_350_400M;
else if (clk_rate <= SXGBE_CSR_F_500M)
priv->clk_csr = SXGBE_CSR_400_500M;
}
static inline u32 sxgbe_tx_avail(struct sxgbe_tx_queue *queue, int tx_qsize)
{
return queue->dirty_tx + tx_qsize - queue->cur_tx - 1;
}
static void sxgbe_adjust_link(struct net_device *dev)
{
struct sxgbe_priv_data *priv = netdev_priv(dev);
struct phy_device *phydev = dev->phydev;
u8 new_state = 0;
u8 speed = 0xff;
if (!phydev)
return;
if (phydev->link) {
if (phydev->speed != priv->speed) {
new_state = 1;
switch (phydev->speed) {
case SPEED_10000:
speed = SXGBE_SPEED_10G;
break;
case SPEED_2500:
speed = SXGBE_SPEED_2_5G;
break;
case SPEED_1000:
speed = SXGBE_SPEED_1G;
break;
default:
netif_err(priv, link, dev,
"Speed (%d) not supported\n",
phydev->speed);
}
priv->speed = phydev->speed;
priv->hw->mac->set_speed(priv->ioaddr, speed);
}
if (!priv->oldlink) {
new_state = 1;
priv->oldlink = 1;
}
} else if (priv->oldlink) {
new_state = 1;
priv->oldlink = 0;
priv->speed = SPEED_UNKNOWN;
}
if (new_state & netif_msg_link(priv))
phy_print_status(phydev);
sxgbe_eee_adjust(priv);
}
static int sxgbe_init_phy(struct net_device *ndev)
{
char phy_id_fmt[MII_BUS_ID_SIZE + 3];
char bus_id[MII_BUS_ID_SIZE];
struct phy_device *phydev;
struct sxgbe_priv_data *priv = netdev_priv(ndev);
int phy_iface = priv->plat->interface;
priv->oldlink = 0;
priv->speed = SPEED_UNKNOWN;
priv->oldduplex = DUPLEX_UNKNOWN;
if (priv->plat->phy_bus_name)
snprintf(bus_id, MII_BUS_ID_SIZE, "%s-%x",
priv->plat->phy_bus_name, priv->plat->bus_id);
else
snprintf(bus_id, MII_BUS_ID_SIZE, "sxgbe-%x",
priv->plat->bus_id);
snprintf(phy_id_fmt, MII_BUS_ID_SIZE + 3, PHY_ID_FMT, bus_id,
priv->plat->phy_addr);
netdev_dbg(ndev, "%s: trying to attach to %s\n", __func__, phy_id_fmt);
phydev = phy_connect(ndev, phy_id_fmt, &sxgbe_adjust_link, phy_iface);
if (IS_ERR(phydev)) {
netdev_err(ndev, "Could not attach to PHY\n");
return PTR_ERR(phydev);
}
if ((phy_iface == PHY_INTERFACE_MODE_MII) ||
(phy_iface == PHY_INTERFACE_MODE_RMII))
phydev->advertising &= ~(SUPPORTED_1000baseT_Half |
SUPPORTED_1000baseT_Full);
if (phydev->phy_id == 0) {
phy_disconnect(phydev);
return -ENODEV;
}
netdev_dbg(ndev, "%s: attached to PHY (UID 0x%x) Link = %d\n",
__func__, phydev->phy_id, phydev->link);
return 0;
}
static void sxgbe_clear_descriptors(struct sxgbe_priv_data *priv)
{
int i, j;
unsigned int txsize = priv->dma_tx_size;
unsigned int rxsize = priv->dma_rx_size;
for (j = 0; j < SXGBE_RX_QUEUES; j++) {
for (i = 0; i < rxsize; i++)
priv->hw->desc->init_rx_desc(&priv->rxq[j]->dma_rx[i],
priv->use_riwt, priv->mode,
(i == rxsize - 1));
}
for (j = 0; j < SXGBE_TX_QUEUES; j++) {
for (i = 0; i < txsize; i++)
priv->hw->desc->init_tx_desc(&priv->txq[j]->dma_tx[i]);
}
}
static int sxgbe_init_rx_buffers(struct net_device *dev,
struct sxgbe_rx_norm_desc *p, int i,
unsigned int dma_buf_sz,
struct sxgbe_rx_queue *rx_ring)
{
struct sxgbe_priv_data *priv = netdev_priv(dev);
struct sk_buff *skb;
skb = __netdev_alloc_skb_ip_align(dev, dma_buf_sz, GFP_KERNEL);
if (!skb)
return -ENOMEM;
rx_ring->rx_skbuff[i] = skb;
rx_ring->rx_skbuff_dma[i] = dma_map_single(priv->device, skb->data,
dma_buf_sz, DMA_FROM_DEVICE);
if (dma_mapping_error(priv->device, rx_ring->rx_skbuff_dma[i])) {
netdev_err(dev, "%s: DMA mapping error\n", __func__);
dev_kfree_skb_any(skb);
return -EINVAL;
}
p->rdes23.rx_rd_des23.buf2_addr = rx_ring->rx_skbuff_dma[i];
return 0;
}
static void sxgbe_free_rx_buffers(struct net_device *dev,
struct sxgbe_rx_norm_desc *p, int i,
unsigned int dma_buf_sz,
struct sxgbe_rx_queue *rx_ring)
{
struct sxgbe_priv_data *priv = netdev_priv(dev);
kfree_skb(rx_ring->rx_skbuff[i]);
dma_unmap_single(priv->device, rx_ring->rx_skbuff_dma[i],
dma_buf_sz, DMA_FROM_DEVICE);
}
static int init_tx_ring(struct device *dev, u8 queue_no,
struct sxgbe_tx_queue *tx_ring, int tx_rsize)
{
if (!tx_ring) {
dev_err(dev, "No memory for TX queue of SXGBE\n");
return -ENOMEM;
}
tx_ring->dma_tx = dma_zalloc_coherent(dev,
tx_rsize * sizeof(struct sxgbe_tx_norm_desc),
&tx_ring->dma_tx_phy, GFP_KERNEL);
if (!tx_ring->dma_tx)
return -ENOMEM;
tx_ring->tx_skbuff_dma = devm_kcalloc(dev, tx_rsize,
sizeof(dma_addr_t), GFP_KERNEL);
if (!tx_ring->tx_skbuff_dma)
goto dmamem_err;
tx_ring->tx_skbuff = devm_kcalloc(dev, tx_rsize,
sizeof(struct sk_buff *), GFP_KERNEL);
if (!tx_ring->tx_skbuff)
goto dmamem_err;
tx_ring->queue_no = queue_no;
tx_ring->dirty_tx = 0;
tx_ring->cur_tx = 0;
return 0;
dmamem_err:
dma_free_coherent(dev, tx_rsize * sizeof(struct sxgbe_tx_norm_desc),
tx_ring->dma_tx, tx_ring->dma_tx_phy);
return -ENOMEM;
}
static void free_rx_ring(struct device *dev, struct sxgbe_rx_queue *rx_ring,
int rx_rsize)
{
dma_free_coherent(dev, rx_rsize * sizeof(struct sxgbe_rx_norm_desc),
rx_ring->dma_rx, rx_ring->dma_rx_phy);
kfree(rx_ring->rx_skbuff_dma);
kfree(rx_ring->rx_skbuff);
}
static int init_rx_ring(struct net_device *dev, u8 queue_no,
struct sxgbe_rx_queue *rx_ring, int rx_rsize)
{
struct sxgbe_priv_data *priv = netdev_priv(dev);
int desc_index;
unsigned int bfsize = 0;
unsigned int ret = 0;
bfsize = ALIGN(dev->mtu + ETH_HLEN + ETH_FCS_LEN + NET_IP_ALIGN, 8);
netif_dbg(priv, probe, dev, "%s: bfsize %d\n", __func__, bfsize);
if (rx_ring == NULL) {
netdev_err(dev, "No memory for RX queue\n");
return -ENOMEM;
}
rx_ring->queue_no = queue_no;
rx_ring->dma_rx = dma_zalloc_coherent(priv->device,
rx_rsize * sizeof(struct sxgbe_rx_norm_desc),
&rx_ring->dma_rx_phy, GFP_KERNEL);
if (rx_ring->dma_rx == NULL)
return -ENOMEM;
rx_ring->rx_skbuff_dma = kmalloc_array(rx_rsize,
sizeof(dma_addr_t), GFP_KERNEL);
if (!rx_ring->rx_skbuff_dma) {
ret = -ENOMEM;
goto err_free_dma_rx;
}
rx_ring->rx_skbuff = kmalloc_array(rx_rsize,
sizeof(struct sk_buff *), GFP_KERNEL);
if (!rx_ring->rx_skbuff) {
ret = -ENOMEM;
goto err_free_skbuff_dma;
}
for (desc_index = 0; desc_index < rx_rsize; desc_index++) {
struct sxgbe_rx_norm_desc *p;
p = rx_ring->dma_rx + desc_index;
ret = sxgbe_init_rx_buffers(dev, p, desc_index,
bfsize, rx_ring);
if (ret)
goto err_free_rx_buffers;
}
rx_ring->cur_rx = 0;
rx_ring->dirty_rx = (unsigned int)(desc_index - rx_rsize);
priv->dma_buf_sz = bfsize;
return 0;
err_free_rx_buffers:
while (--desc_index >= 0) {
struct sxgbe_rx_norm_desc *p;
p = rx_ring->dma_rx + desc_index;
sxgbe_free_rx_buffers(dev, p, desc_index, bfsize, rx_ring);
}
kfree(rx_ring->rx_skbuff);
err_free_skbuff_dma:
kfree(rx_ring->rx_skbuff_dma);
err_free_dma_rx:
dma_free_coherent(priv->device,
rx_rsize * sizeof(struct sxgbe_rx_norm_desc),
rx_ring->dma_rx, rx_ring->dma_rx_phy);
return ret;
}
static void free_tx_ring(struct device *dev, struct sxgbe_tx_queue *tx_ring,
int tx_rsize)
{
dma_free_coherent(dev, tx_rsize * sizeof(struct sxgbe_tx_norm_desc),
tx_ring->dma_tx, tx_ring->dma_tx_phy);
}
static int init_dma_desc_rings(struct net_device *netd)
{
int queue_num, ret;
struct sxgbe_priv_data *priv = netdev_priv(netd);
int tx_rsize = priv->dma_tx_size;
int rx_rsize = priv->dma_rx_size;
SXGBE_FOR_EACH_QUEUE(SXGBE_TX_QUEUES, queue_num) {
ret = init_tx_ring(priv->device, queue_num,
priv->txq[queue_num], tx_rsize);
if (ret) {
dev_err(&netd->dev, "TX DMA ring allocation failed!\n");
goto txalloc_err;
}
priv->txq[queue_num]->priv_ptr = priv;
}
SXGBE_FOR_EACH_QUEUE(SXGBE_RX_QUEUES, queue_num) {
ret = init_rx_ring(netd, queue_num,
priv->rxq[queue_num], rx_rsize);
if (ret) {
netdev_err(netd, "RX DMA ring allocation failed!!\n");
goto rxalloc_err;
}
priv->rxq[queue_num]->priv_ptr = priv;
}
sxgbe_clear_descriptors(priv);
return 0;
txalloc_err:
while (queue_num--)
free_tx_ring(priv->device, priv->txq[queue_num], tx_rsize);
return ret;
rxalloc_err:
while (queue_num--)
free_rx_ring(priv->device, priv->rxq[queue_num], rx_rsize);
return ret;
}
static void tx_free_ring_skbufs(struct sxgbe_tx_queue *txqueue)
{
int dma_desc;
struct sxgbe_priv_data *priv = txqueue->priv_ptr;
int tx_rsize = priv->dma_tx_size;
for (dma_desc = 0; dma_desc < tx_rsize; dma_desc++) {
struct sxgbe_tx_norm_desc *tdesc = txqueue->dma_tx + dma_desc;
if (txqueue->tx_skbuff_dma[dma_desc])
dma_unmap_single(priv->device,
txqueue->tx_skbuff_dma[dma_desc],
priv->hw->desc->get_tx_len(tdesc),
DMA_TO_DEVICE);
dev_kfree_skb_any(txqueue->tx_skbuff[dma_desc]);
txqueue->tx_skbuff[dma_desc] = NULL;
txqueue->tx_skbuff_dma[dma_desc] = 0;
}
}
static void dma_free_tx_skbufs(struct sxgbe_priv_data *priv)
{
int queue_num;
SXGBE_FOR_EACH_QUEUE(SXGBE_TX_QUEUES, queue_num) {
struct sxgbe_tx_queue *tqueue = priv->txq[queue_num];
tx_free_ring_skbufs(tqueue);
}
}
static void free_dma_desc_resources(struct sxgbe_priv_data *priv)
{
int queue_num;
int tx_rsize = priv->dma_tx_size;
int rx_rsize = priv->dma_rx_size;
dma_free_tx_skbufs(priv);
SXGBE_FOR_EACH_QUEUE(SXGBE_TX_QUEUES, queue_num) {
free_tx_ring(priv->device, priv->txq[queue_num], tx_rsize);
}
SXGBE_FOR_EACH_QUEUE(SXGBE_RX_QUEUES, queue_num) {
free_rx_ring(priv->device, priv->rxq[queue_num], rx_rsize);
}
}
static int txring_mem_alloc(struct sxgbe_priv_data *priv)
{
int queue_num;
SXGBE_FOR_EACH_QUEUE(SXGBE_TX_QUEUES, queue_num) {
priv->txq[queue_num] = devm_kmalloc(priv->device,
sizeof(struct sxgbe_tx_queue), GFP_KERNEL);
if (!priv->txq[queue_num])
return -ENOMEM;
}
return 0;
}
static int rxring_mem_alloc(struct sxgbe_priv_data *priv)
{
int queue_num;
SXGBE_FOR_EACH_QUEUE(SXGBE_RX_QUEUES, queue_num) {
priv->rxq[queue_num] = devm_kmalloc(priv->device,
sizeof(struct sxgbe_rx_queue), GFP_KERNEL);
if (!priv->rxq[queue_num])
return -ENOMEM;
}
return 0;
}
static void sxgbe_mtl_operation_mode(struct sxgbe_priv_data *priv)
{
int queue_num;
if (likely(priv->plat->force_sf_dma_mode)) {
SXGBE_FOR_EACH_QUEUE(priv->hw_cap.tx_mtl_queues, queue_num)
priv->hw->mtl->set_tx_mtl_mode(priv->ioaddr, queue_num,
SXGBE_MTL_SFMODE);
priv->tx_tc = SXGBE_MTL_SFMODE;
SXGBE_FOR_EACH_QUEUE(priv->hw_cap.rx_mtl_queues, queue_num)
priv->hw->mtl->set_rx_mtl_mode(priv->ioaddr, queue_num,
SXGBE_MTL_SFMODE);
priv->rx_tc = SXGBE_MTL_SFMODE;
} else if (unlikely(priv->plat->force_thresh_dma_mode)) {
SXGBE_FOR_EACH_QUEUE(priv->hw_cap.tx_mtl_queues, queue_num)
priv->hw->mtl->set_tx_mtl_mode(priv->ioaddr, queue_num,
priv->tx_tc);
SXGBE_FOR_EACH_QUEUE(priv->hw_cap.rx_mtl_queues, queue_num)
priv->hw->mtl->set_rx_mtl_mode(priv->ioaddr, queue_num,
priv->rx_tc);
} else {
pr_err("ERROR: %s: Invalid TX threshold mode\n", __func__);
}
}
static void sxgbe_tx_queue_clean(struct sxgbe_tx_queue *tqueue)
{
struct sxgbe_priv_data *priv = tqueue->priv_ptr;
unsigned int tx_rsize = priv->dma_tx_size;
struct netdev_queue *dev_txq;
u8 queue_no = tqueue->queue_no;
dev_txq = netdev_get_tx_queue(priv->dev, queue_no);
__netif_tx_lock(dev_txq, smp_processor_id());
priv->xstats.tx_clean++;
while (tqueue->dirty_tx != tqueue->cur_tx) {
unsigned int entry = tqueue->dirty_tx % tx_rsize;
struct sk_buff *skb = tqueue->tx_skbuff[entry];
struct sxgbe_tx_norm_desc *p;
p = tqueue->dma_tx + entry;
if (priv->hw->desc->get_tx_owner(p))
break;
if (netif_msg_tx_done(priv))
pr_debug("%s: curr %d, dirty %d\n",
__func__, tqueue->cur_tx, tqueue->dirty_tx);
if (likely(tqueue->tx_skbuff_dma[entry])) {
dma_unmap_single(priv->device,
tqueue->tx_skbuff_dma[entry],
priv->hw->desc->get_tx_len(p),
DMA_TO_DEVICE);
tqueue->tx_skbuff_dma[entry] = 0;
}
if (likely(skb)) {
dev_kfree_skb(skb);
tqueue->tx_skbuff[entry] = NULL;
}
priv->hw->desc->release_tx_desc(p);
tqueue->dirty_tx++;
}
if (unlikely(netif_tx_queue_stopped(dev_txq) &&
sxgbe_tx_avail(tqueue, tx_rsize) > SXGBE_TX_THRESH(priv))) {
if (netif_msg_tx_done(priv))
pr_debug("%s: restart transmit\n", __func__);
netif_tx_wake_queue(dev_txq);
}
__netif_tx_unlock(dev_txq);
}
static void sxgbe_tx_all_clean(struct sxgbe_priv_data * const priv)
{
u8 queue_num;
SXGBE_FOR_EACH_QUEUE(SXGBE_TX_QUEUES, queue_num) {
struct sxgbe_tx_queue *tqueue = priv->txq[queue_num];
sxgbe_tx_queue_clean(tqueue);
}
if ((priv->eee_enabled) && (!priv->tx_path_in_lpi_mode)) {
sxgbe_enable_eee_mode(priv);
mod_timer(&priv->eee_ctrl_timer, SXGBE_LPI_TIMER(eee_timer));
}
}
static void sxgbe_restart_tx_queue(struct sxgbe_priv_data *priv, int queue_num)
{
struct sxgbe_tx_queue *tx_ring = priv->txq[queue_num];
struct netdev_queue *dev_txq = netdev_get_tx_queue(priv->dev,
queue_num);
netif_tx_stop_queue(dev_txq);
priv->hw->dma->stop_tx_queue(priv->ioaddr, queue_num);
tx_free_ring_skbufs(tx_ring);
tx_ring->cur_tx = 0;
tx_ring->dirty_tx = 0;
priv->hw->dma->start_tx_queue(priv->ioaddr, queue_num);
priv->dev->stats.tx_errors++;
netif_tx_wake_queue(dev_txq);
}
static void sxgbe_reset_all_tx_queues(struct sxgbe_priv_data *priv)
{
int queue_num;
SXGBE_FOR_EACH_QUEUE(SXGBE_TX_QUEUES, queue_num)
sxgbe_restart_tx_queue(priv, queue_num);
}
static int sxgbe_get_hw_features(struct sxgbe_priv_data * const priv)
{
int rval = 0;
struct sxgbe_hw_features *features = &priv->hw_cap;
rval = priv->hw->mac->get_hw_feature(priv->ioaddr, 0);
if (rval) {
features->pmt_remote_wake_up =
SXGBE_HW_FEAT_PMT_TEMOTE_WOP(rval);
features->pmt_magic_frame = SXGBE_HW_FEAT_PMT_MAGIC_PKT(rval);
features->atime_stamp = SXGBE_HW_FEAT_IEEE1500_2008(rval);
features->tx_csum_offload =
SXGBE_HW_FEAT_TX_CSUM_OFFLOAD(rval);
features->rx_csum_offload =
SXGBE_HW_FEAT_RX_CSUM_OFFLOAD(rval);
features->multi_macaddr = SXGBE_HW_FEAT_MACADDR_COUNT(rval);
features->tstamp_srcselect = SXGBE_HW_FEAT_TSTMAP_SRC(rval);
features->sa_vlan_insert = SXGBE_HW_FEAT_SRCADDR_VLAN(rval);
features->eee = SXGBE_HW_FEAT_EEE(rval);
}
rval = priv->hw->mac->get_hw_feature(priv->ioaddr, 1);
if (rval) {
features->rxfifo_size = SXGBE_HW_FEAT_RX_FIFO_SIZE(rval);
features->txfifo_size = SXGBE_HW_FEAT_TX_FIFO_SIZE(rval);
features->atstmap_hword = SXGBE_HW_FEAT_TX_FIFO_SIZE(rval);
features->dcb_enable = SXGBE_HW_FEAT_DCB(rval);
features->splithead_enable = SXGBE_HW_FEAT_SPLIT_HDR(rval);
features->tcpseg_offload = SXGBE_HW_FEAT_TSO(rval);
features->debug_mem = SXGBE_HW_FEAT_DEBUG_MEM_IFACE(rval);
features->rss_enable = SXGBE_HW_FEAT_RSS(rval);
features->hash_tsize = SXGBE_HW_FEAT_HASH_TABLE_SIZE(rval);
features->l3l4_filer_size = SXGBE_HW_FEAT_L3L4_FILTER_NUM(rval);
}
rval = priv->hw->mac->get_hw_feature(priv->ioaddr, 2);
if (rval) {
features->rx_mtl_queues = SXGBE_HW_FEAT_RX_MTL_QUEUES(rval);
features->tx_mtl_queues = SXGBE_HW_FEAT_TX_MTL_QUEUES(rval);
features->rx_dma_channels = SXGBE_HW_FEAT_RX_DMA_CHANNELS(rval);
features->tx_dma_channels = SXGBE_HW_FEAT_TX_DMA_CHANNELS(rval);
features->pps_output_count = SXGBE_HW_FEAT_PPS_OUTPUTS(rval);
features->aux_input_count = SXGBE_HW_FEAT_AUX_SNAPSHOTS(rval);
}
return rval;
}
static void sxgbe_check_ether_addr(struct sxgbe_priv_data *priv)
{
if (!is_valid_ether_addr(priv->dev->dev_addr)) {
priv->hw->mac->get_umac_addr((void __iomem *)
priv->ioaddr,
priv->dev->dev_addr, 0);
if (!is_valid_ether_addr(priv->dev->dev_addr))
eth_hw_addr_random(priv->dev);
}
dev_info(priv->device, "device MAC address %pM\n",
priv->dev->dev_addr);
}
static int sxgbe_init_dma_engine(struct sxgbe_priv_data *priv)
{
int pbl = DEFAULT_DMA_PBL, fixed_burst = 0, burst_map = 0;
int queue_num;
if (priv->plat->dma_cfg) {
pbl = priv->plat->dma_cfg->pbl;
fixed_burst = priv->plat->dma_cfg->fixed_burst;
burst_map = priv->plat->dma_cfg->burst_map;
}
SXGBE_FOR_EACH_QUEUE(SXGBE_TX_QUEUES, queue_num)
priv->hw->dma->cha_init(priv->ioaddr, queue_num,
fixed_burst, pbl,
(priv->txq[queue_num])->dma_tx_phy,
(priv->rxq[queue_num])->dma_rx_phy,
priv->dma_tx_size, priv->dma_rx_size);
return priv->hw->dma->init(priv->ioaddr, fixed_burst, burst_map);
}
static void sxgbe_init_mtl_engine(struct sxgbe_priv_data *priv)
{
int queue_num;
SXGBE_FOR_EACH_QUEUE(SXGBE_TX_QUEUES, queue_num) {
priv->hw->mtl->mtl_set_txfifosize(priv->ioaddr, queue_num,
priv->hw_cap.tx_mtl_qsize);
priv->hw->mtl->mtl_enable_txqueue(priv->ioaddr, queue_num);
}
}
static void sxgbe_disable_mtl_engine(struct sxgbe_priv_data *priv)
{
int queue_num;
SXGBE_FOR_EACH_QUEUE(SXGBE_TX_QUEUES, queue_num)
priv->hw->mtl->mtl_disable_txqueue(priv->ioaddr, queue_num);
}
static void sxgbe_tx_timer(unsigned long data)
{
struct sxgbe_tx_queue *p = (struct sxgbe_tx_queue *)data;
sxgbe_tx_queue_clean(p);
}
static void sxgbe_tx_init_coalesce(struct sxgbe_priv_data *priv)
{
u8 queue_num;
SXGBE_FOR_EACH_QUEUE(SXGBE_TX_QUEUES, queue_num) {
struct sxgbe_tx_queue *p = priv->txq[queue_num];
p->tx_coal_frames = SXGBE_TX_FRAMES;
p->tx_coal_timer = SXGBE_COAL_TX_TIMER;
setup_timer(&p->txtimer, sxgbe_tx_timer,
(unsigned long)&priv->txq[queue_num]);
p->txtimer.expires = SXGBE_COAL_TIMER(p->tx_coal_timer);
add_timer(&p->txtimer);
}
}
static void sxgbe_tx_del_timer(struct sxgbe_priv_data *priv)
{
u8 queue_num;
SXGBE_FOR_EACH_QUEUE(SXGBE_TX_QUEUES, queue_num) {
struct sxgbe_tx_queue *p = priv->txq[queue_num];
del_timer_sync(&p->txtimer);
}
}
static int sxgbe_open(struct net_device *dev)
{
struct sxgbe_priv_data *priv = netdev_priv(dev);
int ret, queue_num;
clk_prepare_enable(priv->sxgbe_clk);
sxgbe_check_ether_addr(priv);
ret = sxgbe_init_phy(dev);
if (ret) {
netdev_err(dev, "%s: Cannot attach to PHY (error: %d)\n",
__func__, ret);
goto phy_error;
}
priv->dma_tx_size = SXGBE_ALIGN(DMA_TX_SIZE);
priv->dma_rx_size = SXGBE_ALIGN(DMA_RX_SIZE);
priv->dma_buf_sz = SXGBE_ALIGN(DMA_BUFFER_SIZE);
priv->tx_tc = TC_DEFAULT;
priv->rx_tc = TC_DEFAULT;
init_dma_desc_rings(dev);
ret = sxgbe_init_dma_engine(priv);
if (ret < 0) {
netdev_err(dev, "%s: DMA initialization failed\n", __func__);
goto init_error;
}
sxgbe_init_mtl_engine(priv);
priv->hw->mac->set_umac_addr(priv->ioaddr, dev->dev_addr, 0);
priv->hw->mac->core_init(priv->ioaddr);
SXGBE_FOR_EACH_QUEUE(SXGBE_RX_QUEUES, queue_num) {
priv->hw->mac->enable_rxqueue(priv->ioaddr, queue_num);
}
ret = devm_request_irq(priv->device, priv->irq, sxgbe_common_interrupt,
IRQF_SHARED, dev->name, dev);
if (unlikely(ret < 0)) {
netdev_err(dev, "%s: ERROR: allocating the IRQ %d (error: %d)\n",
__func__, priv->irq, ret);
goto init_error;
}
if (priv->lpi_irq != dev->irq) {
ret = devm_request_irq(priv->device, priv->lpi_irq,
sxgbe_common_interrupt,
IRQF_SHARED, dev->name, dev);
if (unlikely(ret < 0)) {
netdev_err(dev, "%s: ERROR: allocating the LPI IRQ %d (%d)\n",
__func__, priv->lpi_irq, ret);
goto init_error;
}
}
SXGBE_FOR_EACH_QUEUE(SXGBE_TX_QUEUES, queue_num) {
ret = devm_request_irq(priv->device,
(priv->txq[queue_num])->irq_no,
sxgbe_tx_interrupt, 0,
dev->name, priv->txq[queue_num]);
if (unlikely(ret < 0)) {
netdev_err(dev, "%s: ERROR: allocating TX IRQ %d (error: %d)\n",
__func__, priv->irq, ret);
goto init_error;
}
}
SXGBE_FOR_EACH_QUEUE(SXGBE_RX_QUEUES, queue_num) {
ret = devm_request_irq(priv->device,
(priv->rxq[queue_num])->irq_no,
sxgbe_rx_interrupt, 0,
dev->name, priv->rxq[queue_num]);
if (unlikely(ret < 0)) {
netdev_err(dev, "%s: ERROR: allocating TX IRQ %d (error: %d)\n",
__func__, priv->irq, ret);
goto init_error;
}
}
priv->hw->mac->enable_tx(priv->ioaddr, true);
priv->hw->mac->enable_rx(priv->ioaddr, true);
sxgbe_mtl_operation_mode(priv);
memset(&priv->xstats, 0, sizeof(struct sxgbe_extra_stats));
priv->xstats.tx_threshold = priv->tx_tc;
priv->xstats.rx_threshold = priv->rx_tc;
netdev_dbg(dev, "DMA RX/TX processes started...\n");
priv->hw->dma->start_tx(priv->ioaddr, SXGBE_TX_QUEUES);
priv->hw->dma->start_rx(priv->ioaddr, SXGBE_RX_QUEUES);
if (dev->phydev)
phy_start(dev->phydev);
sxgbe_tx_init_coalesce(priv);
if ((priv->use_riwt) && (priv->hw->dma->rx_watchdog)) {
priv->rx_riwt = SXGBE_MAX_DMA_RIWT;
priv->hw->dma->rx_watchdog(priv->ioaddr, SXGBE_MAX_DMA_RIWT);
}
priv->tx_lpi_timer = SXGBE_DEFAULT_LPI_TIMER;
priv->eee_enabled = sxgbe_eee_init(priv);
napi_enable(&priv->napi);
netif_start_queue(dev);
return 0;
init_error:
free_dma_desc_resources(priv);
if (dev->phydev)
phy_disconnect(dev->phydev);
phy_error:
clk_disable_unprepare(priv->sxgbe_clk);
return ret;
}
static int sxgbe_release(struct net_device *dev)
{
struct sxgbe_priv_data *priv = netdev_priv(dev);
if (priv->eee_enabled)
del_timer_sync(&priv->eee_ctrl_timer);
if (dev->phydev) {
phy_stop(dev->phydev);
phy_disconnect(dev->phydev);
}
netif_tx_stop_all_queues(dev);
napi_disable(&priv->napi);
sxgbe_tx_del_timer(priv);
priv->hw->dma->stop_tx(priv->ioaddr, SXGBE_TX_QUEUES);
priv->hw->dma->stop_rx(priv->ioaddr, SXGBE_RX_QUEUES);
sxgbe_disable_mtl_engine(priv);
free_dma_desc_resources(priv);
priv->hw->mac->enable_tx(priv->ioaddr, false);
priv->hw->mac->enable_rx(priv->ioaddr, false);
clk_disable_unprepare(priv->sxgbe_clk);
return 0;
}
static void sxgbe_tso_prepare(struct sxgbe_priv_data *priv,
struct sxgbe_tx_norm_desc *first_desc,
struct sk_buff *skb)
{
unsigned int total_hdr_len, tcp_hdr_len;
tcp_hdr_len = tcp_hdrlen(skb);
total_hdr_len = skb_transport_offset(skb) + tcp_hdr_len;
first_desc->tdes01 = dma_map_single(priv->device, skb->data,
total_hdr_len, DMA_TO_DEVICE);
if (dma_mapping_error(priv->device, first_desc->tdes01))
pr_err("%s: TX dma mapping failed!!\n", __func__);
first_desc->tdes23.tx_rd_des23.first_desc = 1;
priv->hw->desc->tx_desc_enable_tse(first_desc, 1, total_hdr_len,
tcp_hdr_len,
skb->len - total_hdr_len);
}
static netdev_tx_t sxgbe_xmit(struct sk_buff *skb, struct net_device *dev)
{
unsigned int entry, frag_num;
int cksum_flag = 0;
struct netdev_queue *dev_txq;
unsigned txq_index = skb_get_queue_mapping(skb);
struct sxgbe_priv_data *priv = netdev_priv(dev);
unsigned int tx_rsize = priv->dma_tx_size;
struct sxgbe_tx_queue *tqueue = priv->txq[txq_index];
struct sxgbe_tx_norm_desc *tx_desc, *first_desc;
struct sxgbe_tx_ctxt_desc *ctxt_desc = NULL;
int nr_frags = skb_shinfo(skb)->nr_frags;
int no_pagedlen = skb_headlen(skb);
int is_jumbo = 0;
u16 cur_mss = skb_shinfo(skb)->gso_size;
u32 ctxt_desc_req = 0;
dev_txq = netdev_get_tx_queue(dev, txq_index);
if (unlikely(skb_is_gso(skb) && tqueue->prev_mss != cur_mss))
ctxt_desc_req = 1;
if (unlikely(skb_vlan_tag_present(skb) ||
((skb_shinfo(skb)->tx_flags & SKBTX_HW_TSTAMP) &&
tqueue->hwts_tx_en)))
ctxt_desc_req = 1;
if (priv->tx_path_in_lpi_mode)
sxgbe_disable_eee_mode(priv);
if (unlikely(sxgbe_tx_avail(tqueue, tx_rsize) < nr_frags + 1)) {
if (!netif_tx_queue_stopped(dev_txq)) {
netif_tx_stop_queue(dev_txq);
netdev_err(dev, "%s: Tx Ring is full when %d queue is awake\n",
__func__, txq_index);
}
return NETDEV_TX_BUSY;
}
entry = tqueue->cur_tx % tx_rsize;
tx_desc = tqueue->dma_tx + entry;
first_desc = tx_desc;
if (ctxt_desc_req)
ctxt_desc = (struct sxgbe_tx_ctxt_desc *)first_desc;
tqueue->tx_skbuff[entry] = skb;
if (!is_jumbo) {
if (likely(skb_is_gso(skb))) {
if (unlikely(tqueue->prev_mss != cur_mss)) {
priv->hw->desc->tx_ctxt_desc_set_mss(
ctxt_desc, cur_mss);
priv->hw->desc->tx_ctxt_desc_set_tcmssv(
ctxt_desc);
priv->hw->desc->tx_ctxt_desc_reset_ostc(
ctxt_desc);
priv->hw->desc->tx_ctxt_desc_set_ctxt(
ctxt_desc);
priv->hw->desc->tx_ctxt_desc_set_owner(
ctxt_desc);
entry = (++tqueue->cur_tx) % tx_rsize;
first_desc = tqueue->dma_tx + entry;
tqueue->prev_mss = cur_mss;
}
sxgbe_tso_prepare(priv, first_desc, skb);
} else {
tx_desc->tdes01 = dma_map_single(priv->device,
skb->data, no_pagedlen, DMA_TO_DEVICE);
if (dma_mapping_error(priv->device, tx_desc->tdes01))
netdev_err(dev, "%s: TX dma mapping failed!!\n",
__func__);
priv->hw->desc->prepare_tx_desc(tx_desc, 1, no_pagedlen,
no_pagedlen, cksum_flag);
}
}
for (frag_num = 0; frag_num < nr_frags; frag_num++) {
const skb_frag_t *frag = &skb_shinfo(skb)->frags[frag_num];
int len = skb_frag_size(frag);
entry = (++tqueue->cur_tx) % tx_rsize;
tx_desc = tqueue->dma_tx + entry;
tx_desc->tdes01 = skb_frag_dma_map(priv->device, frag, 0, len,
DMA_TO_DEVICE);
tqueue->tx_skbuff_dma[entry] = tx_desc->tdes01;
tqueue->tx_skbuff[entry] = NULL;
priv->hw->desc->prepare_tx_desc(tx_desc, 0, len,
len, cksum_flag);
wmb();
priv->hw->desc->set_tx_owner(tx_desc);
}
priv->hw->desc->close_tx_desc(tx_desc);
wmb();
tqueue->tx_count_frames += nr_frags + 1;
if (tqueue->tx_count_frames > tqueue->tx_coal_frames) {
priv->hw->desc->clear_tx_ic(tx_desc);
priv->xstats.tx_reset_ic_bit++;
mod_timer(&tqueue->txtimer,
SXGBE_COAL_TIMER(tqueue->tx_coal_timer));
} else {
tqueue->tx_count_frames = 0;
}
priv->hw->desc->set_tx_owner(first_desc);
wmb();
tqueue->cur_tx++;
netif_dbg(priv, pktdata, dev, "%s: curr %d dirty=%d entry=%d, first=%p, nfrags=%d\n",
__func__, tqueue->cur_tx % tx_rsize,
tqueue->dirty_tx % tx_rsize, entry,
first_desc, nr_frags);
if (unlikely(sxgbe_tx_avail(tqueue, tx_rsize) <= (MAX_SKB_FRAGS + 1))) {
netif_dbg(priv, hw, dev, "%s: stop transmitted packets\n",
__func__);
netif_tx_stop_queue(dev_txq);
}
dev->stats.tx_bytes += skb->len;
if (unlikely((skb_shinfo(skb)->tx_flags & SKBTX_HW_TSTAMP) &&
tqueue->hwts_tx_en)) {
skb_shinfo(skb)->tx_flags |= SKBTX_IN_PROGRESS;
priv->hw->desc->tx_enable_tstamp(first_desc);
}
skb_tx_timestamp(skb);
priv->hw->dma->enable_dma_transmission(priv->ioaddr, txq_index);
return NETDEV_TX_OK;
}
static void sxgbe_rx_refill(struct sxgbe_priv_data *priv)
{
unsigned int rxsize = priv->dma_rx_size;
int bfsize = priv->dma_buf_sz;
u8 qnum = priv->cur_rx_qnum;
for (; priv->rxq[qnum]->cur_rx - priv->rxq[qnum]->dirty_rx > 0;
priv->rxq[qnum]->dirty_rx++) {
unsigned int entry = priv->rxq[qnum]->dirty_rx % rxsize;
struct sxgbe_rx_norm_desc *p;
p = priv->rxq[qnum]->dma_rx + entry;
if (likely(priv->rxq[qnum]->rx_skbuff[entry] == NULL)) {
struct sk_buff *skb;
skb = netdev_alloc_skb_ip_align(priv->dev, bfsize);
if (unlikely(skb == NULL))
break;
priv->rxq[qnum]->rx_skbuff[entry] = skb;
priv->rxq[qnum]->rx_skbuff_dma[entry] =
dma_map_single(priv->device, skb->data, bfsize,
DMA_FROM_DEVICE);
p->rdes23.rx_rd_des23.buf2_addr =
priv->rxq[qnum]->rx_skbuff_dma[entry];
}
wmb();
priv->hw->desc->set_rx_owner(p);
priv->hw->desc->set_rx_int_on_com(p);
wmb();
}
}
static int sxgbe_rx(struct sxgbe_priv_data *priv, int limit)
{
u8 qnum = priv->cur_rx_qnum;
unsigned int rxsize = priv->dma_rx_size;
unsigned int entry = priv->rxq[qnum]->cur_rx;
unsigned int next_entry = 0;
unsigned int count = 0;
int checksum;
int status;
while (count < limit) {
struct sxgbe_rx_norm_desc *p;
struct sk_buff *skb;
int frame_len;
p = priv->rxq[qnum]->dma_rx + entry;
if (priv->hw->desc->get_rx_owner(p))
break;
count++;
next_entry = (++priv->rxq[qnum]->cur_rx) % rxsize;
prefetch(priv->rxq[qnum]->dma_rx + next_entry);
status = priv->hw->desc->rx_wbstatus(p, &priv->xstats,
&checksum);
if (unlikely(status < 0)) {
entry = next_entry;
continue;
}
if (unlikely(!priv->rxcsum_insertion))
checksum = CHECKSUM_NONE;
skb = priv->rxq[qnum]->rx_skbuff[entry];
if (unlikely(!skb))
netdev_err(priv->dev, "rx descriptor is not consistent\n");
prefetch(skb->data - NET_IP_ALIGN);
priv->rxq[qnum]->rx_skbuff[entry] = NULL;
frame_len = priv->hw->desc->get_rx_frame_len(p);
skb_put(skb, frame_len);
skb->ip_summed = checksum;
if (checksum == CHECKSUM_NONE)
netif_receive_skb(skb);
else
napi_gro_receive(&priv->napi, skb);
entry = next_entry;
}
sxgbe_rx_refill(priv);
return count;
}
static int sxgbe_poll(struct napi_struct *napi, int budget)
{
struct sxgbe_priv_data *priv = container_of(napi,
struct sxgbe_priv_data, napi);
int work_done = 0;
u8 qnum = priv->cur_rx_qnum;
priv->xstats.napi_poll++;
sxgbe_tx_all_clean(priv);
work_done = sxgbe_rx(priv, budget);
if (work_done < budget) {
napi_complete_done(napi, work_done);
priv->hw->dma->enable_dma_irq(priv->ioaddr, qnum);
}
return work_done;
}
static void sxgbe_tx_timeout(struct net_device *dev)
{
struct sxgbe_priv_data *priv = netdev_priv(dev);
sxgbe_reset_all_tx_queues(priv);
}
static irqreturn_t sxgbe_common_interrupt(int irq, void *dev_id)
{
struct net_device *netdev = (struct net_device *)dev_id;
struct sxgbe_priv_data *priv = netdev_priv(netdev);
int status;
status = priv->hw->mac->host_irq_status(priv->ioaddr, &priv->xstats);
if (status & TX_ENTRY_LPI_MODE) {
priv->xstats.tx_lpi_entry_n++;
priv->tx_path_in_lpi_mode = true;
}
if (status & TX_EXIT_LPI_MODE) {
priv->xstats.tx_lpi_exit_n++;
priv->tx_path_in_lpi_mode = false;
}
if (status & RX_ENTRY_LPI_MODE)
priv->xstats.rx_lpi_entry_n++;
if (status & RX_EXIT_LPI_MODE)
priv->xstats.rx_lpi_exit_n++;
return IRQ_HANDLED;
}
static irqreturn_t sxgbe_tx_interrupt(int irq, void *dev_id)
{
int status;
struct sxgbe_tx_queue *txq = (struct sxgbe_tx_queue *)dev_id;
struct sxgbe_priv_data *priv = txq->priv_ptr;
status = priv->hw->dma->tx_dma_int_status(priv->ioaddr, txq->queue_no,
&priv->xstats);
if (likely((status & handle_tx)))
napi_schedule(&priv->napi);
if (unlikely((status & tx_hard_error)))
sxgbe_restart_tx_queue(priv, txq->queue_no);
if (unlikely((status & tx_bump_tc) &&
(priv->tx_tc != SXGBE_MTL_SFMODE) &&
(priv->tx_tc < 512))) {
priv->tx_tc += (priv->tx_tc < 128) ? 32 : 64;
priv->hw->mtl->set_tx_mtl_mode(priv->ioaddr,
txq->queue_no, priv->tx_tc);
priv->xstats.tx_threshold = priv->tx_tc;
}
return IRQ_HANDLED;
}
static irqreturn_t sxgbe_rx_interrupt(int irq, void *dev_id)
{
int status;
struct sxgbe_rx_queue *rxq = (struct sxgbe_rx_queue *)dev_id;
struct sxgbe_priv_data *priv = rxq->priv_ptr;
status = priv->hw->dma->rx_dma_int_status(priv->ioaddr, rxq->queue_no,
&priv->xstats);
if (likely((status & handle_rx) && (napi_schedule_prep(&priv->napi)))) {
priv->hw->dma->disable_dma_irq(priv->ioaddr, rxq->queue_no);
__napi_schedule(&priv->napi);
}
if (unlikely((status & rx_bump_tc) &&
(priv->rx_tc != SXGBE_MTL_SFMODE) &&
(priv->rx_tc < 128))) {
priv->rx_tc += 32;
priv->hw->mtl->set_rx_mtl_mode(priv->ioaddr,
rxq->queue_no, priv->rx_tc);
priv->xstats.rx_threshold = priv->rx_tc;
}
return IRQ_HANDLED;
}
static inline u64 sxgbe_get_stat64(void __iomem *ioaddr, int reg_lo, int reg_hi)
{
u64 val = readl(ioaddr + reg_lo);
val |= ((u64)readl(ioaddr + reg_hi)) << 32;
return val;
}
static void sxgbe_get_stats64(struct net_device *dev,
struct rtnl_link_stats64 *stats)
{
struct sxgbe_priv_data *priv = netdev_priv(dev);
void __iomem *ioaddr = priv->ioaddr;
u64 count;
spin_lock(&priv->stats_lock);
writel(SXGBE_MMC_CTRL_CNT_FRZ, ioaddr + SXGBE_MMC_CTL_REG);
stats->rx_bytes = sxgbe_get_stat64(ioaddr,
SXGBE_MMC_RXOCTETLO_GCNT_REG,
SXGBE_MMC_RXOCTETHI_GCNT_REG);
stats->rx_packets = sxgbe_get_stat64(ioaddr,
SXGBE_MMC_RXFRAMELO_GBCNT_REG,
SXGBE_MMC_RXFRAMEHI_GBCNT_REG);
stats->multicast = sxgbe_get_stat64(ioaddr,
SXGBE_MMC_RXMULTILO_GCNT_REG,
SXGBE_MMC_RXMULTIHI_GCNT_REG);
stats->rx_crc_errors = sxgbe_get_stat64(ioaddr,
SXGBE_MMC_RXCRCERRLO_REG,
SXGBE_MMC_RXCRCERRHI_REG);
stats->rx_length_errors = sxgbe_get_stat64(ioaddr,
SXGBE_MMC_RXLENERRLO_REG,
SXGBE_MMC_RXLENERRHI_REG);
stats->rx_missed_errors = sxgbe_get_stat64(ioaddr,
SXGBE_MMC_RXFIFOOVERFLOWLO_GBCNT_REG,
SXGBE_MMC_RXFIFOOVERFLOWHI_GBCNT_REG);
stats->tx_bytes = sxgbe_get_stat64(ioaddr,
SXGBE_MMC_TXOCTETLO_GCNT_REG,
SXGBE_MMC_TXOCTETHI_GCNT_REG);
count = sxgbe_get_stat64(ioaddr, SXGBE_MMC_TXFRAMELO_GBCNT_REG,
SXGBE_MMC_TXFRAMEHI_GBCNT_REG);
stats->tx_errors = sxgbe_get_stat64(ioaddr, SXGBE_MMC_TXFRAMELO_GCNT_REG,
SXGBE_MMC_TXFRAMEHI_GCNT_REG);
stats->tx_errors = count - stats->tx_errors;
stats->tx_packets = count;
stats->tx_fifo_errors = sxgbe_get_stat64(ioaddr, SXGBE_MMC_TXUFLWLO_GBCNT_REG,
SXGBE_MMC_TXUFLWHI_GBCNT_REG);
writel(0, ioaddr + SXGBE_MMC_CTL_REG);
spin_unlock(&priv->stats_lock);
}
static int sxgbe_set_features(struct net_device *dev,
netdev_features_t features)
{
struct sxgbe_priv_data *priv = netdev_priv(dev);
netdev_features_t changed = dev->features ^ features;
if (changed & NETIF_F_RXCSUM) {
if (features & NETIF_F_RXCSUM) {
priv->hw->mac->enable_rx_csum(priv->ioaddr);
priv->rxcsum_insertion = true;
} else {
priv->hw->mac->disable_rx_csum(priv->ioaddr);
priv->rxcsum_insertion = false;
}
}
return 0;
}
static int sxgbe_change_mtu(struct net_device *dev, int new_mtu)
{
dev->mtu = new_mtu;
if (!netif_running(dev))
return 0;
sxgbe_release(dev);
return sxgbe_open(dev);
}
static void sxgbe_set_umac_addr(void __iomem *ioaddr, unsigned char *addr,
unsigned int reg_n)
{
unsigned long data;
data = (addr[5] << 8) | addr[4];
writel(data | SXGBE_HI_REG_AE, ioaddr + SXGBE_ADDR_HIGH(reg_n));
data = (addr[3] << 24) | (addr[2] << 16) | (addr[1] << 8) | addr[0];
writel(data, ioaddr + SXGBE_ADDR_LOW(reg_n));
}
static void sxgbe_set_rx_mode(struct net_device *dev)
{
struct sxgbe_priv_data *priv = netdev_priv(dev);
void __iomem *ioaddr = (void __iomem *)priv->ioaddr;
unsigned int value = 0;
u32 mc_filter[2];
struct netdev_hw_addr *ha;
int reg = 1;
netdev_dbg(dev, "%s: # mcasts %d, # unicast %d\n",
__func__, netdev_mc_count(dev), netdev_uc_count(dev));
if (dev->flags & IFF_PROMISC) {
value = SXGBE_FRAME_FILTER_PR;
} else if ((netdev_mc_count(dev) > SXGBE_HASH_TABLE_SIZE) ||
(dev->flags & IFF_ALLMULTI)) {
value = SXGBE_FRAME_FILTER_PM;
writel(0xffffffff, ioaddr + SXGBE_HASH_HIGH);
writel(0xffffffff, ioaddr + SXGBE_HASH_LOW);
} else if (!netdev_mc_empty(dev)) {
value = SXGBE_FRAME_FILTER_HMC;
memset(mc_filter, 0, sizeof(mc_filter));
netdev_for_each_mc_addr(ha, dev) {
int bit_nr = bitrev32(~crc32_le(~0, ha->addr, 6)) >> 26;
mc_filter[bit_nr >> 5] |= 1 << (bit_nr & 31);
}
writel(mc_filter[0], ioaddr + SXGBE_HASH_LOW);
writel(mc_filter[1], ioaddr + SXGBE_HASH_HIGH);
}
if (netdev_uc_count(dev) > SXGBE_MAX_PERFECT_ADDRESSES)
value |= SXGBE_FRAME_FILTER_PR;
else {
netdev_for_each_uc_addr(ha, dev) {
sxgbe_set_umac_addr(ioaddr, ha->addr, reg);
reg++;
}
}
#ifdef FRAME_FILTER_DEBUG
value |= SXGBE_FRAME_FILTER_RA;
#endif
writel(value, ioaddr + SXGBE_FRAME_FILTER);
netdev_dbg(dev, "Filter: 0x%08x\n\tHash: HI 0x%08x, LO 0x%08x\n",
readl(ioaddr + SXGBE_FRAME_FILTER),
readl(ioaddr + SXGBE_HASH_HIGH),
readl(ioaddr + SXGBE_HASH_LOW));
}
static void sxgbe_poll_controller(struct net_device *dev)
{
struct sxgbe_priv_data *priv = netdev_priv(dev);
disable_irq(priv->irq);
sxgbe_rx_interrupt(priv->irq, dev);
enable_irq(priv->irq);
}
static int sxgbe_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
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
default:
break;
}
return ret;
}
static void sxgbe_get_ops(struct sxgbe_ops * const ops_ptr)
{
ops_ptr->mac = sxgbe_get_core_ops();
ops_ptr->desc = sxgbe_get_desc_ops();
ops_ptr->dma = sxgbe_get_dma_ops();
ops_ptr->mtl = sxgbe_get_mtl_ops();
ops_ptr->mii.addr = SXGBE_MDIO_SCMD_ADD_REG;
ops_ptr->mii.data = SXGBE_MDIO_SCMD_DATA_REG;
ops_ptr->link.port = 0;
ops_ptr->link.duplex = 0;
ops_ptr->link.speed = SXGBE_SPEED_10G;
}
static int sxgbe_hw_init(struct sxgbe_priv_data * const priv)
{
u32 ctrl_ids;
priv->hw = kmalloc(sizeof(*priv->hw), GFP_KERNEL);
if(!priv->hw)
return -ENOMEM;
sxgbe_get_ops(priv->hw);
ctrl_ids = priv->hw->mac->get_controller_version(priv->ioaddr);
priv->hw->ctrl_uid = (ctrl_ids & 0x00ff0000) >> 16;
priv->hw->ctrl_id = (ctrl_ids & 0x000000ff);
pr_info("user ID: 0x%x, Controller ID: 0x%x\n",
priv->hw->ctrl_uid, priv->hw->ctrl_id);
if (!sxgbe_get_hw_features(priv))
pr_info("Hardware features not found\n");
if (priv->hw_cap.tx_csum_offload)
pr_info("TX Checksum offload supported\n");
if (priv->hw_cap.rx_csum_offload)
pr_info("RX Checksum offload supported\n");
return 0;
}
static int sxgbe_sw_reset(void __iomem *addr)
{
int retry_count = 10;
writel(SXGBE_DMA_SOFT_RESET, addr + SXGBE_DMA_MODE_REG);
while (retry_count--) {
if (!(readl(addr + SXGBE_DMA_MODE_REG) &
SXGBE_DMA_SOFT_RESET))
break;
mdelay(10);
}
if (retry_count < 0)
return -EBUSY;
return 0;
}
struct sxgbe_priv_data *sxgbe_drv_probe(struct device *device,
struct sxgbe_plat_data *plat_dat,
void __iomem *addr)
{
struct sxgbe_priv_data *priv;
struct net_device *ndev;
int ret;
u8 queue_num;
ndev = alloc_etherdev_mqs(sizeof(struct sxgbe_priv_data),
SXGBE_TX_QUEUES, SXGBE_RX_QUEUES);
if (!ndev)
return NULL;
SET_NETDEV_DEV(ndev, device);
priv = netdev_priv(ndev);
priv->device = device;
priv->dev = ndev;
sxgbe_set_ethtool_ops(ndev);
priv->plat = plat_dat;
priv->ioaddr = addr;
ret = sxgbe_sw_reset(priv->ioaddr);
if (ret)
goto error_free_netdev;
sxgbe_verify_args();
ret = sxgbe_hw_init(priv);
if (ret)
goto error_free_netdev;
ret = txring_mem_alloc(priv);
if (ret)
goto error_free_hw;
ret = rxring_mem_alloc(priv);
if (ret)
goto error_free_hw;
ndev->netdev_ops = &sxgbe_netdev_ops;
ndev->hw_features = NETIF_F_SG | NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM |
NETIF_F_RXCSUM | NETIF_F_TSO | NETIF_F_TSO6 |
NETIF_F_GRO;
ndev->features |= ndev->hw_features | NETIF_F_HIGHDMA;
ndev->watchdog_timeo = msecs_to_jiffies(TX_TIMEO);
ndev->priv_flags |= IFF_UNICAST_FLT;
ndev->min_mtu = MIN_MTU;
ndev->max_mtu = MAX_MTU;
priv->msg_enable = netif_msg_init(debug, default_msg_level);
if (priv->hw_cap.tcpseg_offload) {
SXGBE_FOR_EACH_QUEUE(SXGBE_TX_QUEUES, queue_num) {
priv->hw->dma->enable_tso(priv->ioaddr, queue_num);
}
}
if (priv->hw_cap.rx_csum_offload) {
priv->hw->mac->enable_rx_csum(priv->ioaddr);
priv->rxcsum_insertion = true;
}
priv->rx_pause = 1;
priv->tx_pause = 1;
if (!priv->plat->riwt_off) {
priv->use_riwt = 1;
pr_info("Enable RX Mitigation via HW Watchdog Timer\n");
}
netif_napi_add(ndev, &priv->napi, sxgbe_poll, 64);
spin_lock_init(&priv->stats_lock);
priv->sxgbe_clk = clk_get(priv->device, SXGBE_RESOURCE_NAME);
if (IS_ERR(priv->sxgbe_clk)) {
netdev_warn(ndev, "%s: warning: cannot get CSR clock\n",
__func__);
goto error_napi_del;
}
if (!priv->plat->clk_csr)
sxgbe_clk_csr_set(priv);
else
priv->clk_csr = priv->plat->clk_csr;
ret = sxgbe_mdio_register(ndev);
if (ret < 0) {
netdev_dbg(ndev, "%s: MDIO bus (id: %d) registration failed\n",
__func__, priv->plat->bus_id);
goto error_clk_put;
}
ret = register_netdev(ndev);
if (ret) {
pr_err("%s: ERROR %i registering the device\n", __func__, ret);
goto error_mdio_unregister;
}
sxgbe_check_ether_addr(priv);
return priv;
error_mdio_unregister:
sxgbe_mdio_unregister(ndev);
error_clk_put:
clk_put(priv->sxgbe_clk);
error_napi_del:
netif_napi_del(&priv->napi);
error_free_hw:
kfree(priv->hw);
error_free_netdev:
free_netdev(ndev);
return NULL;
}
int sxgbe_drv_remove(struct net_device *ndev)
{
struct sxgbe_priv_data *priv = netdev_priv(ndev);
u8 queue_num;
netdev_info(ndev, "%s: removing driver\n", __func__);
SXGBE_FOR_EACH_QUEUE(SXGBE_RX_QUEUES, queue_num) {
priv->hw->mac->disable_rxqueue(priv->ioaddr, queue_num);
}
priv->hw->dma->stop_rx(priv->ioaddr, SXGBE_RX_QUEUES);
priv->hw->dma->stop_tx(priv->ioaddr, SXGBE_TX_QUEUES);
priv->hw->mac->enable_tx(priv->ioaddr, false);
priv->hw->mac->enable_rx(priv->ioaddr, false);
unregister_netdev(ndev);
sxgbe_mdio_unregister(ndev);
clk_put(priv->sxgbe_clk);
netif_napi_del(&priv->napi);
kfree(priv->hw);
free_netdev(ndev);
return 0;
}
int sxgbe_suspend(struct net_device *ndev)
{
return 0;
}
int sxgbe_resume(struct net_device *ndev)
{
return 0;
}
int sxgbe_freeze(struct net_device *ndev)
{
return -ENOSYS;
}
int sxgbe_restore(struct net_device *ndev)
{
return -ENOSYS;
}
static int __init sxgbe_init(void)
{
int ret;
ret = sxgbe_register_platform();
if (ret)
goto err;
return 0;
err:
pr_err("driver registration failed\n");
return ret;
}
static void __exit sxgbe_exit(void)
{
sxgbe_unregister_platform();
}
static int __init sxgbe_cmdline_opt(char *str)
{
char *opt;
if (!str || !*str)
return -EINVAL;
while ((opt = strsep(&str, ",")) != NULL) {
if (!strncmp(opt, "eee_timer:", 6)) {
if (kstrtoint(opt + 10, 0, &eee_timer))
goto err;
}
}
return 0;
err:
pr_err("%s: ERROR broken module parameter conversion\n", __func__);
return -EINVAL;
}
