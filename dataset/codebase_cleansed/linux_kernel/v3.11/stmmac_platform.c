static int stmmac_probe_config_dt(struct platform_device *pdev,
struct plat_stmmacenet_data *plat,
const char **mac)
{
struct device_node *np = pdev->dev.of_node;
struct stmmac_dma_cfg *dma_cfg;
if (!np)
return -ENODEV;
*mac = of_get_mac_address(np);
plat->interface = of_get_phy_mode(np);
plat->bus_id = of_alias_get_id(np, "ethernet");
if (plat->bus_id < 0)
plat->bus_id = 0;
of_property_read_u32(np, "snps,phy-addr", &plat->phy_addr);
plat->mdio_bus_data = devm_kzalloc(&pdev->dev,
sizeof(struct stmmac_mdio_bus_data),
GFP_KERNEL);
if (of_device_is_compatible(np, "st,spear600-gmac") ||
of_device_is_compatible(np, "snps,dwmac-3.70a") ||
of_device_is_compatible(np, "snps,dwmac")) {
plat->has_gmac = 1;
plat->pmt = 1;
}
if (of_device_is_compatible(np, "snps,dwmac-3.610") ||
of_device_is_compatible(np, "snps,dwmac-3.710")) {
plat->enh_desc = 1;
plat->bugged_jumbo = 1;
plat->force_sf_dma_mode = 1;
}
if (of_find_property(np, "snps,pbl", NULL)) {
dma_cfg = devm_kzalloc(&pdev->dev, sizeof(*dma_cfg),
GFP_KERNEL);
if (!dma_cfg)
return -ENOMEM;
plat->dma_cfg = dma_cfg;
of_property_read_u32(np, "snps,pbl", &dma_cfg->pbl);
dma_cfg->fixed_burst =
of_property_read_bool(np, "snps,fixed-burst");
dma_cfg->mixed_burst =
of_property_read_bool(np, "snps,mixed-burst");
}
return 0;
}
static int stmmac_probe_config_dt(struct platform_device *pdev,
struct plat_stmmacenet_data *plat,
const char **mac)
{
return -ENOSYS;
}
static int stmmac_pltfr_probe(struct platform_device *pdev)
{
int ret = 0;
struct resource *res;
struct device *dev = &pdev->dev;
void __iomem *addr = NULL;
struct stmmac_priv *priv = NULL;
struct plat_stmmacenet_data *plat_dat = NULL;
const char *mac = NULL;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
addr = devm_ioremap_resource(dev, res);
if (IS_ERR(addr))
return PTR_ERR(addr);
plat_dat = pdev->dev.platform_data;
if (pdev->dev.of_node) {
if (!plat_dat)
plat_dat = devm_kzalloc(&pdev->dev,
sizeof(struct plat_stmmacenet_data),
GFP_KERNEL);
if (!plat_dat) {
pr_err("%s: ERROR: no memory", __func__);
return -ENOMEM;
}
ret = stmmac_probe_config_dt(pdev, plat_dat, &mac);
if (ret) {
pr_err("%s: main dt probe failed", __func__);
return ret;
}
}
if (plat_dat->init) {
ret = plat_dat->init(pdev);
if (unlikely(ret))
return ret;
}
priv = stmmac_dvr_probe(&(pdev->dev), plat_dat, addr);
if (!priv) {
pr_err("%s: main driver probe failed", __func__);
return -ENODEV;
}
if (mac)
memcpy(priv->dev->dev_addr, mac, ETH_ALEN);
priv->dev->irq = platform_get_irq_byname(pdev, "macirq");
if (priv->dev->irq == -ENXIO) {
pr_err("%s: ERROR: MAC IRQ configuration "
"information not found\n", __func__);
return -ENXIO;
}
priv->wol_irq = platform_get_irq_byname(pdev, "eth_wake_irq");
if (priv->wol_irq == -ENXIO)
priv->wol_irq = priv->dev->irq;
priv->lpi_irq = platform_get_irq_byname(pdev, "eth_lpi");
platform_set_drvdata(pdev, priv->dev);
pr_debug("STMMAC platform driver registration completed");
return 0;
}
static int stmmac_pltfr_remove(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct stmmac_priv *priv = netdev_priv(ndev);
int ret = stmmac_dvr_remove(ndev);
if (priv->plat->exit)
priv->plat->exit(pdev);
return ret;
}
static int stmmac_pltfr_suspend(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
return stmmac_suspend(ndev);
}
static int stmmac_pltfr_resume(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
return stmmac_resume(ndev);
}
int stmmac_pltfr_freeze(struct device *dev)
{
int ret;
struct plat_stmmacenet_data *plat_dat = dev_get_platdata(dev);
struct net_device *ndev = dev_get_drvdata(dev);
struct platform_device *pdev = to_platform_device(dev);
ret = stmmac_freeze(ndev);
if (plat_dat->exit)
plat_dat->exit(pdev);
return ret;
}
int stmmac_pltfr_restore(struct device *dev)
{
struct plat_stmmacenet_data *plat_dat = dev_get_platdata(dev);
struct net_device *ndev = dev_get_drvdata(dev);
struct platform_device *pdev = to_platform_device(dev);
if (plat_dat->init)
plat_dat->init(pdev);
return stmmac_restore(ndev);
}
