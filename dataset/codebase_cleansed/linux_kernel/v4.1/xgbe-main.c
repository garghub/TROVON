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
pdata->phy_speed = SPEED_UNKNOWN;
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
static int xgbe_acpi_support(struct xgbe_prv_data *pdata)
{
struct acpi_device *adev = pdata->adev;
struct device *dev = pdata->dev;
u32 property;
acpi_handle handle;
acpi_status status;
unsigned long long data;
int cca;
int ret;
ret = device_property_read_u32(dev, XGBE_ACPI_DMA_FREQ, &property);
if (ret) {
dev_err(dev, "unable to obtain %s property\n",
XGBE_ACPI_DMA_FREQ);
return ret;
}
pdata->sysclk_rate = property;
ret = device_property_read_u32(dev, XGBE_ACPI_PTP_FREQ, &property);
if (ret) {
dev_err(dev, "unable to obtain %s property\n",
XGBE_ACPI_PTP_FREQ);
return ret;
}
pdata->ptpclk_rate = property;
handle = adev->handle;
do {
status = acpi_evaluate_integer(handle, "_CCA", NULL, &data);
if (!ACPI_FAILURE(status)) {
cca = data;
break;
}
status = acpi_get_parent(handle, &handle);
} while (!ACPI_FAILURE(status));
if (ACPI_FAILURE(status)) {
dev_err(dev, "error obtaining acpi coherency value\n");
return -EINVAL;
}
pdata->coherent = !!cca;
return 0;
}
static int xgbe_acpi_support(struct xgbe_prv_data *pdata)
{
return -EINVAL;
}
static int xgbe_of_support(struct xgbe_prv_data *pdata)
{
struct device *dev = pdata->dev;
pdata->sysclk = devm_clk_get(dev, XGBE_DMA_CLOCK);
if (IS_ERR(pdata->sysclk)) {
dev_err(dev, "dma devm_clk_get failed\n");
return PTR_ERR(pdata->sysclk);
}
pdata->sysclk_rate = clk_get_rate(pdata->sysclk);
pdata->ptpclk = devm_clk_get(dev, XGBE_PTP_CLOCK);
if (IS_ERR(pdata->ptpclk)) {
dev_err(dev, "ptp devm_clk_get failed\n");
return PTR_ERR(pdata->ptpclk);
}
pdata->ptpclk_rate = clk_get_rate(pdata->ptpclk);
pdata->coherent = of_dma_is_coherent(dev->of_node);
return 0;
}
static int xgbe_of_support(struct xgbe_prv_data *pdata)
{
return -EINVAL;
}
static int xgbe_probe(struct platform_device *pdev)
{
struct xgbe_prv_data *pdata;
struct xgbe_hw_if *hw_if;
struct xgbe_desc_if *desc_if;
struct net_device *netdev;
struct device *dev = &pdev->dev;
struct resource *res;
const char *phy_mode;
unsigned int i;
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
pdata->adev = ACPI_COMPANION(dev);
pdata->dev = dev;
platform_set_drvdata(pdev, netdev);
spin_lock_init(&pdata->lock);
mutex_init(&pdata->xpcs_mutex);
mutex_init(&pdata->rss_mutex);
spin_lock_init(&pdata->tstamp_lock);
pdata->use_acpi = (!pdata->adev || acpi_disabled) ? 0 : 1;
BUILD_BUG_ON_NOT_POWER_OF_2(XGBE_TX_DESC_CNT);
pdata->tx_desc_count = XGBE_TX_DESC_CNT;
if (pdata->tx_desc_count & (pdata->tx_desc_count - 1)) {
dev_err(dev, "tx descriptor count (%d) is not valid\n",
pdata->tx_desc_count);
ret = -EINVAL;
goto err_io;
}
BUILD_BUG_ON_NOT_POWER_OF_2(XGBE_RX_DESC_CNT);
pdata->rx_desc_count = XGBE_RX_DESC_CNT;
if (pdata->rx_desc_count & (pdata->rx_desc_count - 1)) {
dev_err(dev, "rx descriptor count (%d) is not valid\n",
pdata->rx_desc_count);
ret = -EINVAL;
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
ret = device_property_read_u8_array(dev, XGBE_MAC_ADDR_PROPERTY,
pdata->mac_addr,
sizeof(pdata->mac_addr));
if (ret || !is_valid_ether_addr(pdata->mac_addr)) {
dev_err(dev, "invalid %s property\n", XGBE_MAC_ADDR_PROPERTY);
if (!ret)
ret = -EINVAL;
goto err_io;
}
ret = device_property_read_string(dev, XGBE_PHY_MODE_PROPERTY,
&phy_mode);
if (ret || strcmp(phy_mode, phy_modes(PHY_INTERFACE_MODE_XGMII))) {
dev_err(dev, "invalid %s property\n", XGBE_PHY_MODE_PROPERTY);
if (!ret)
ret = -EINVAL;
goto err_io;
}
pdata->phy_mode = PHY_INTERFACE_MODE_XGMII;
if (device_property_present(dev, XGBE_DMA_IRQS_PROPERTY))
pdata->per_channel_irq = 1;
if (pdata->use_acpi)
ret = xgbe_acpi_support(pdata);
else
ret = xgbe_of_support(pdata);
if (ret)
goto err_io;
if (pdata->coherent) {
pdata->axdomain = XGBE_DMA_OS_AXDOMAIN;
pdata->arcache = XGBE_DMA_OS_ARCACHE;
pdata->awcache = XGBE_DMA_OS_AWCACHE;
} else {
pdata->axdomain = XGBE_DMA_SYS_AXDOMAIN;
pdata->arcache = XGBE_DMA_SYS_ARCACHE;
pdata->awcache = XGBE_DMA_SYS_AWCACHE;
}
ret = platform_get_irq(pdev, 0);
if (ret < 0) {
dev_err(dev, "platform_get_irq 0 failed\n");
goto err_io;
}
pdata->dev_irq = ret;
netdev->irq = pdata->dev_irq;
netdev->base_addr = (unsigned long)pdata->xgmac_regs;
memcpy(netdev->dev_addr, pdata->mac_addr, netdev->addr_len);
xgbe_init_all_fptrs(pdata);
hw_if = &pdata->hw_if;
desc_if = &pdata->desc_if;
hw_if->exit(pdata);
xgbe_get_all_hw_features(pdata);
xgbe_default_config(pdata);
if (!dev->dma_mask)
dev->dma_mask = &dev->coherent_dma_mask;
ret = dma_set_mask_and_coherent(dev,
DMA_BIT_MASK(pdata->hw_feat.dma_width));
if (ret) {
dev_err(dev, "dma_set_mask_and_coherent failed\n");
goto err_io;
}
pdata->tx_ring_count = min_t(unsigned int, num_online_cpus(),
pdata->hw_feat.tx_ch_cnt);
pdata->tx_q_count = pdata->tx_ring_count;
ret = netif_set_real_num_tx_queues(netdev, pdata->tx_ring_count);
if (ret) {
dev_err(dev, "error setting real tx queue count\n");
goto err_io;
}
pdata->rx_ring_count = min_t(unsigned int,
netif_get_num_default_rss_queues(),
pdata->hw_feat.rx_ch_cnt);
pdata->rx_q_count = pdata->hw_feat.rx_q_cnt;
ret = netif_set_real_num_rx_queues(netdev, pdata->rx_ring_count);
if (ret) {
dev_err(dev, "error setting real rx queue count\n");
goto err_io;
}
netdev_rss_key_fill(pdata->rss_key, sizeof(pdata->rss_key));
for (i = 0; i < XGBE_RSS_MAX_TABLE_SIZE; i++)
XGMAC_SET_BITS(pdata->rss_table[i], MAC_RSSDR, DMCH,
i % pdata->rx_ring_count);
XGMAC_SET_BITS(pdata->rss_options, MAC_RSSCR, IP2TE, 1);
XGMAC_SET_BITS(pdata->rss_options, MAC_RSSCR, TCP4TE, 1);
XGMAC_SET_BITS(pdata->rss_options, MAC_RSSCR, UDP4TE, 1);
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
#ifdef CONFIG_AMD_XGBE_DCB
netdev->dcbnl_ops = xgbe_get_dcbnl_ops();
#endif
netdev->hw_features = NETIF_F_SG |
NETIF_F_IP_CSUM |
NETIF_F_IPV6_CSUM |
NETIF_F_RXCSUM |
NETIF_F_TSO |
NETIF_F_TSO6 |
NETIF_F_GRO |
NETIF_F_HW_VLAN_CTAG_RX |
NETIF_F_HW_VLAN_CTAG_TX |
NETIF_F_HW_VLAN_CTAG_FILTER;
if (pdata->hw_feat.rss)
netdev->hw_features |= NETIF_F_RXHASH;
netdev->vlan_features |= NETIF_F_SG |
NETIF_F_IP_CSUM |
NETIF_F_IPV6_CSUM |
NETIF_F_TSO |
NETIF_F_TSO6;
netdev->features |= netdev->hw_features;
pdata->netdev_features = netdev->features;
netdev->priv_flags |= IFF_UNICAST_FLT;
netdev->watchdog_timeo = 0;
xgbe_init_rx_coalesce(pdata);
xgbe_init_tx_coalesce(pdata);
netif_carrier_off(netdev);
ret = register_netdev(netdev);
if (ret) {
dev_err(dev, "net device registration failed\n");
goto err_reg_netdev;
}
xgbe_ptp_register(pdata);
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
xgbe_ptp_unregister(pdata);
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
