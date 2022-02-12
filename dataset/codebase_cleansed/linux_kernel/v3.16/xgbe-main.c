static struct xgbe_channel *xgbe_alloc_rings(struct xgbe_prv_data *pdata)
{
struct xgbe_channel *channel_mem, *channel;
struct xgbe_ring *tx_ring, *rx_ring;
unsigned int count, i;
DBGPR("-->xgbe_alloc_rings\n");
count = max_t(unsigned int, pdata->tx_ring_count, pdata->rx_ring_count);
channel_mem = devm_kcalloc(pdata->dev, count,
sizeof(struct xgbe_channel), GFP_KERNEL);
if (!channel_mem)
return NULL;
tx_ring = devm_kcalloc(pdata->dev, pdata->tx_ring_count,
sizeof(struct xgbe_ring), GFP_KERNEL);
if (!tx_ring)
return NULL;
rx_ring = devm_kcalloc(pdata->dev, pdata->rx_ring_count,
sizeof(struct xgbe_ring), GFP_KERNEL);
if (!rx_ring)
return NULL;
for (i = 0, channel = channel_mem; i < count; i++, channel++) {
snprintf(channel->name, sizeof(channel->name), "channel-%d", i);
channel->pdata = pdata;
channel->queue_index = i;
channel->dma_regs = pdata->xgmac_regs + DMA_CH_BASE +
(DMA_CH_INC * i);
if (i < pdata->tx_ring_count) {
spin_lock_init(&tx_ring->lock);
channel->tx_ring = tx_ring++;
}
if (i < pdata->rx_ring_count) {
spin_lock_init(&tx_ring->lock);
channel->rx_ring = rx_ring++;
}
DBGPR(" %s - queue_index=%u, dma_regs=%p, tx=%p, rx=%p\n",
channel->name, channel->queue_index, channel->dma_regs,
channel->tx_ring, channel->rx_ring);
}
pdata->channel_count = count;
DBGPR("<--xgbe_alloc_rings\n");
return channel_mem;
}
static void xgbe_default_config(struct xgbe_prv_data *pdata)
{
DBGPR("-->xgbe_default_config\n");
pdata->pblx8 = DMA_PBL_X8_ENABLE;
pdata->tx_sf_mode = MTL_TSF_ENABLE;
pdata->tx_threshold = MTL_TX_THRESHOLD_64;
pdata->tx_pbl = DMA_PBL_16;
pdata->tx_osp_mode = DMA_OSP_ENABLE;
pdata->rx_sf_mode = MTL_RSF_DISABLE;
pdata->rx_threshold = MTL_RX_THRESHOLD_64;
pdata->rx_pbl = DMA_PBL_16;
pdata->pause_autoneg = 1;
pdata->tx_pause = 1;
pdata->rx_pause = 1;
pdata->power_down = 0;
pdata->default_autoneg = AUTONEG_ENABLE;
pdata->default_speed = SPEED_10000;
DBGPR("<--xgbe_default_config\n");
}
static void xgbe_init_all_fptrs(struct xgbe_prv_data *pdata)
{
xgbe_init_function_ptrs_dev(&pdata->hw_if);
xgbe_init_function_ptrs_desc(&pdata->desc_if);
}
static int xgbe_probe(struct platform_device *pdev)
{
struct xgbe_prv_data *pdata;
struct xgbe_hw_if *hw_if;
struct xgbe_desc_if *desc_if;
struct net_device *netdev;
struct device *dev = &pdev->dev;
struct resource *res;
const u8 *mac_addr;
int ret;
DBGPR("--> xgbe_probe\n");
netdev = alloc_etherdev_mq(sizeof(struct xgbe_prv_data),
XGBE_MAX_DMA_CHANNELS);
if (!netdev) {
dev_err(dev, "alloc_etherdev failed\n");
ret = -ENOMEM;
goto err_alloc;
}
SET_NETDEV_DEV(netdev, dev);
pdata = netdev_priv(netdev);
pdata->netdev = netdev;
pdata->pdev = pdev;
pdata->dev = dev;
platform_set_drvdata(pdev, netdev);
spin_lock_init(&pdata->lock);
mutex_init(&pdata->xpcs_mutex);
BUILD_BUG_ON_NOT_POWER_OF_2(TX_DESC_CNT);
pdata->tx_desc_count = TX_DESC_CNT;
if (pdata->tx_desc_count & (pdata->tx_desc_count - 1)) {
dev_err(dev, "tx descriptor count (%d) is not valid\n",
pdata->tx_desc_count);
ret = -EINVAL;
goto err_io;
}
BUILD_BUG_ON_NOT_POWER_OF_2(RX_DESC_CNT);
pdata->rx_desc_count = RX_DESC_CNT;
if (pdata->rx_desc_count & (pdata->rx_desc_count - 1)) {
dev_err(dev, "rx descriptor count (%d) is not valid\n",
pdata->rx_desc_count);
ret = -EINVAL;
goto err_io;
}
pdata->sysclock = devm_clk_get(dev, NULL);
if (IS_ERR(pdata->sysclock)) {
dev_err(dev, "devm_clk_get failed\n");
ret = PTR_ERR(pdata->sysclock);
goto err_io;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pdata->xgmac_regs = devm_ioremap_resource(dev, res);
if (IS_ERR(pdata->xgmac_regs)) {
dev_err(dev, "xgmac ioremap failed\n");
ret = PTR_ERR(pdata->xgmac_regs);
goto err_io;
}
DBGPR(" xgmac_regs = %p\n", pdata->xgmac_regs);
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
pdata->xpcs_regs = devm_ioremap_resource(dev, res);
if (IS_ERR(pdata->xpcs_regs)) {
dev_err(dev, "xpcs ioremap failed\n");
ret = PTR_ERR(pdata->xpcs_regs);
goto err_io;
}
DBGPR(" xpcs_regs = %p\n", pdata->xpcs_regs);
if (!dev->dma_mask)
dev->dma_mask = &dev->coherent_dma_mask;
*(dev->dma_mask) = DMA_BIT_MASK(40);
dev->coherent_dma_mask = DMA_BIT_MASK(40);
ret = platform_get_irq(pdev, 0);
if (ret < 0) {
dev_err(dev, "platform_get_irq failed\n");
goto err_io;
}
netdev->irq = ret;
netdev->base_addr = (unsigned long)pdata->xgmac_regs;
xgbe_init_all_fptrs(pdata);
hw_if = &pdata->hw_if;
desc_if = &pdata->desc_if;
hw_if->exit(pdata);
xgbe_get_all_hw_features(pdata);
mac_addr = of_get_mac_address(dev->of_node);
if (!mac_addr) {
dev_err(dev, "invalid mac address for this device\n");
ret = -EINVAL;
goto err_io;
}
memcpy(netdev->dev_addr, mac_addr, netdev->addr_len);
pdata->phy_mode = of_get_phy_mode(dev->of_node);
if (pdata->phy_mode != PHY_INTERFACE_MODE_XGMII) {
dev_err(dev, "invalid phy-mode specified for this device\n");
ret = -EINVAL;
goto err_io;
}
xgbe_default_config(pdata);
pdata->tx_ring_count = min_t(unsigned int, num_online_cpus(),
pdata->hw_feat.tx_ch_cnt);
ret = netif_set_real_num_tx_queues(netdev, pdata->tx_ring_count);
if (ret) {
dev_err(dev, "error setting real tx queue count\n");
goto err_io;
}
pdata->rx_ring_count = min_t(unsigned int,
netif_get_num_default_rss_queues(),
pdata->hw_feat.rx_ch_cnt);
ret = netif_set_real_num_rx_queues(netdev, pdata->rx_ring_count);
if (ret) {
dev_err(dev, "error setting real rx queue count\n");
goto err_io;
}
pdata->channel = xgbe_alloc_rings(pdata);
if (!pdata->channel) {
dev_err(dev, "ring allocation failed\n");
ret = -ENOMEM;
goto err_io;
}
pdata->mii_bus_id = kasprintf(GFP_KERNEL, "%s", pdev->name);
if (!pdata->mii_bus_id) {
dev_err(dev, "failed to allocate mii bus id\n");
ret = -ENOMEM;
goto err_io;
}
ret = xgbe_mdio_register(pdata);
if (ret)
goto err_bus_id;
netdev->netdev_ops = xgbe_get_netdev_ops();
netdev->ethtool_ops = xgbe_get_ethtool_ops();
netdev->hw_features = NETIF_F_SG |
NETIF_F_IP_CSUM |
NETIF_F_IPV6_CSUM |
NETIF_F_RXCSUM |
NETIF_F_TSO |
NETIF_F_TSO6 |
NETIF_F_GRO |
NETIF_F_HW_VLAN_CTAG_RX |
NETIF_F_HW_VLAN_CTAG_TX;
netdev->vlan_features |= NETIF_F_SG |
NETIF_F_IP_CSUM |
NETIF_F_IPV6_CSUM |
NETIF_F_TSO |
NETIF_F_TSO6;
netdev->features |= netdev->hw_features;
pdata->netdev_features = netdev->features;
xgbe_init_rx_coalesce(pdata);
xgbe_init_tx_coalesce(pdata);
netif_carrier_off(netdev);
ret = register_netdev(netdev);
if (ret) {
dev_err(dev, "net device registration failed\n");
goto err_reg_netdev;
}
xgbe_debugfs_init(pdata);
netdev_notice(netdev, "net device enabled\n");
DBGPR("<-- xgbe_probe\n");
return 0;
err_reg_netdev:
xgbe_mdio_unregister(pdata);
err_bus_id:
kfree(pdata->mii_bus_id);
err_io:
free_netdev(netdev);
err_alloc:
dev_notice(dev, "net device not enabled\n");
return ret;
}
static int xgbe_remove(struct platform_device *pdev)
{
struct net_device *netdev = platform_get_drvdata(pdev);
struct xgbe_prv_data *pdata = netdev_priv(netdev);
DBGPR("-->xgbe_remove\n");
xgbe_debugfs_exit(pdata);
unregister_netdev(netdev);
xgbe_mdio_unregister(pdata);
kfree(pdata->mii_bus_id);
free_netdev(netdev);
DBGPR("<--xgbe_remove\n");
return 0;
}
static int xgbe_suspend(struct device *dev)
{
struct net_device *netdev = dev_get_drvdata(dev);
int ret;
DBGPR("-->xgbe_suspend\n");
if (!netif_running(netdev)) {
DBGPR("<--xgbe_dev_suspend\n");
return -EINVAL;
}
ret = xgbe_powerdown(netdev, XGMAC_DRIVER_CONTEXT);
DBGPR("<--xgbe_suspend\n");
return ret;
}
static int xgbe_resume(struct device *dev)
{
struct net_device *netdev = dev_get_drvdata(dev);
int ret;
DBGPR("-->xgbe_resume\n");
if (!netif_running(netdev)) {
DBGPR("<--xgbe_dev_resume\n");
return -EINVAL;
}
ret = xgbe_powerup(netdev, XGMAC_DRIVER_CONTEXT);
DBGPR("<--xgbe_resume\n");
return ret;
}
