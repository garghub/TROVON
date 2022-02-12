static int sxgbe_probe_config_dt(struct platform_device *pdev,
struct sxgbe_plat_data *plat,
const char **mac)
{
struct device_node *np = pdev->dev.of_node;
struct sxgbe_dma_cfg *dma_cfg;
if (!np)
return -ENODEV;
*mac = of_get_mac_address(np);
plat->interface = of_get_phy_mode(np);
plat->bus_id = of_alias_get_id(np, "ethernet");
if (plat->bus_id < 0)
plat->bus_id = 0;
plat->mdio_bus_data = devm_kzalloc(&pdev->dev,
sizeof(*plat->mdio_bus_data),
GFP_KERNEL);
dma_cfg = devm_kzalloc(&pdev->dev, sizeof(*dma_cfg), GFP_KERNEL);
if (!dma_cfg)
return -ENOMEM;
plat->dma_cfg = dma_cfg;
of_property_read_u32(np, "samsung,pbl", &dma_cfg->pbl);
if (of_property_read_u32(np, "samsung,burst-map", &dma_cfg->burst_map) == 0)
dma_cfg->fixed_burst = true;
return 0;
}
static int sxgbe_probe_config_dt(struct platform_device *pdev,
struct sxgbe_plat_data *plat,
const char **mac)
{
return -ENOSYS;
}
static int sxgbe_platform_probe(struct platform_device *pdev)
{
int ret;
int i, chan;
struct resource *res;
struct device *dev = &pdev->dev;
void __iomem *addr;
struct sxgbe_priv_data *priv = NULL;
struct sxgbe_plat_data *plat_dat = NULL;
const char *mac = NULL;
struct net_device *ndev = platform_get_drvdata(pdev);
struct device_node *node = dev->of_node;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
addr = devm_ioremap_resource(dev, res);
if (IS_ERR(addr))
return PTR_ERR(addr);
if (pdev->dev.of_node) {
plat_dat = devm_kzalloc(&pdev->dev,
sizeof(struct sxgbe_plat_data),
GFP_KERNEL);
if (!plat_dat)
return -ENOMEM;
ret = sxgbe_probe_config_dt(pdev, plat_dat, &mac);
if (ret) {
pr_err("%s: main dt probe failed\n", __func__);
return ret;
}
}
priv = sxgbe_drv_probe(&(pdev->dev), plat_dat, addr);
if (!priv) {
pr_err("%s: main driver probe failed\n", __func__);
goto err_out;
}
priv->irq = irq_of_parse_and_map(node, 0);
if (priv->irq <= 0) {
dev_err(dev, "sxgbe common irq parsing failed\n");
goto err_drv_remove;
}
if (mac)
ether_addr_copy(priv->dev->dev_addr, mac);
for (i = 0, chan = 1; i < SXGBE_TX_QUEUES; i++) {
priv->txq[i]->irq_no = irq_of_parse_and_map(node, chan++);
if (priv->txq[i]->irq_no <= 0) {
dev_err(dev, "sxgbe tx irq parsing failed\n");
goto err_tx_irq_unmap;
}
}
for (i = 0; i < SXGBE_RX_QUEUES; i++) {
priv->rxq[i]->irq_no = irq_of_parse_and_map(node, chan++);
if (priv->rxq[i]->irq_no <= 0) {
dev_err(dev, "sxgbe rx irq parsing failed\n");
goto err_rx_irq_unmap;
}
}
priv->lpi_irq = irq_of_parse_and_map(node, chan);
if (priv->lpi_irq <= 0) {
dev_err(dev, "sxgbe lpi irq parsing failed\n");
goto err_rx_irq_unmap;
}
platform_set_drvdata(pdev, priv->dev);
pr_debug("platform driver registration completed\n");
return 0;
err_rx_irq_unmap:
while (i--)
irq_dispose_mapping(priv->rxq[i]->irq_no);
i = SXGBE_TX_QUEUES;
err_tx_irq_unmap:
while (i--)
irq_dispose_mapping(priv->txq[i]->irq_no);
irq_dispose_mapping(priv->irq);
err_drv_remove:
sxgbe_drv_remove(ndev);
err_out:
return -ENODEV;
}
static int sxgbe_platform_remove(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
int ret = sxgbe_drv_remove(ndev);
return ret;
}
static int sxgbe_platform_suspend(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
return sxgbe_suspend(ndev);
}
static int sxgbe_platform_resume(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
return sxgbe_resume(ndev);
}
static int sxgbe_platform_freeze(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
return sxgbe_freeze(ndev);
}
static int sxgbe_platform_restore(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
return sxgbe_restore(ndev);
}
int sxgbe_register_platform(void)
{
int err;
err = platform_driver_register(&sxgbe_platform_driver);
if (err)
pr_err("failed to register the platform driver\n");
return err;
}
void sxgbe_unregister_platform(void)
{
platform_driver_unregister(&sxgbe_platform_driver);
}
