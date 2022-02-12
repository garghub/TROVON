static int dwmac1000_validate_mcast_bins(int mcast_bins)
{
int x = mcast_bins;
switch (x) {
case HASH_TABLE_SIZE:
case 128:
case 256:
break;
default:
x = 0;
pr_info("Hash table entries set to unexpected value %d",
mcast_bins);
break;
}
return x;
}
static int dwmac1000_validate_ucast_entries(int ucast_entries)
{
int x = ucast_entries;
switch (x) {
case 1:
case 32:
case 64:
case 128:
break;
default:
x = 1;
pr_info("Unicast table entries set to unexpected value %d\n",
ucast_entries);
break;
}
return x;
}
static int stmmac_probe_config_dt(struct platform_device *pdev,
struct plat_stmmacenet_data *plat,
const char **mac)
{
struct device_node *np = pdev->dev.of_node;
struct stmmac_dma_cfg *dma_cfg;
const struct of_device_id *device;
if (!np)
return -ENODEV;
device = of_match_device(stmmac_dt_ids, &pdev->dev);
if (!device)
return -ENODEV;
if (device->data) {
const struct stmmac_of_data *data = device->data;
plat->has_gmac = data->has_gmac;
plat->enh_desc = data->enh_desc;
plat->tx_coe = data->tx_coe;
plat->rx_coe = data->rx_coe;
plat->bugged_jumbo = data->bugged_jumbo;
plat->pmt = data->pmt;
plat->riwt_off = data->riwt_off;
plat->fix_mac_speed = data->fix_mac_speed;
plat->bus_setup = data->bus_setup;
plat->setup = data->setup;
plat->free = data->free;
plat->init = data->init;
plat->exit = data->exit;
}
*mac = of_get_mac_address(np);
plat->interface = of_get_phy_mode(np);
if (of_property_read_u32(np, "max-speed", &plat->max_speed))
plat->max_speed = -1;
plat->bus_id = of_alias_get_id(np, "ethernet");
if (plat->bus_id < 0)
plat->bus_id = 0;
plat->phy_addr = -1;
if (of_property_read_u32(np, "snps,phy-addr", &plat->phy_addr) == 0)
dev_warn(&pdev->dev, "snps,phy-addr property is deprecated\n");
plat->mdio_bus_data = devm_kzalloc(&pdev->dev,
sizeof(struct stmmac_mdio_bus_data),
GFP_KERNEL);
plat->force_sf_dma_mode = of_property_read_bool(np, "snps,force_sf_dma_mode");
plat->maxmtu = JUMBO_LEN;
plat->multicast_filter_bins = HASH_TABLE_SIZE;
plat->unicast_filter_entries = 1;
if (of_device_is_compatible(np, "st,spear600-gmac") ||
of_device_is_compatible(np, "snps,dwmac-3.70a") ||
of_device_is_compatible(np, "snps,dwmac")) {
of_property_read_u32(np, "max-frame-size", &plat->maxmtu);
of_property_read_u32(np, "snps,multicast-filter-bins",
&plat->multicast_filter_bins);
of_property_read_u32(np, "snps,perfect-filter-entries",
&plat->unicast_filter_entries);
plat->unicast_filter_entries = dwmac1000_validate_ucast_entries(
plat->unicast_filter_entries);
plat->multicast_filter_bins = dwmac1000_validate_mcast_bins(
plat->multicast_filter_bins);
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
plat->force_thresh_dma_mode = of_property_read_bool(np, "snps,force_thresh_dma_mode");
if (plat->force_thresh_dma_mode) {
plat->force_sf_dma_mode = 0;
pr_warn("force_sf_dma_mode is ignored if force_thresh_dma_mode is set.");
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
addr = devm_ioremap_resource(dev, res);
if (IS_ERR(addr))
return PTR_ERR(addr);
plat_dat = dev_get_platdata(&pdev->dev);
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
if (plat_dat->setup) {
plat_dat->bsp_priv = plat_dat->setup(pdev);
if (IS_ERR(plat_dat->bsp_priv))
return PTR_ERR(plat_dat->bsp_priv);
}
if (plat_dat->init) {
ret = plat_dat->init(pdev, plat_dat->bsp_priv);
if (unlikely(ret))
return ret;
}
priv = stmmac_dvr_probe(&(pdev->dev), plat_dat, addr);
if (IS_ERR(priv)) {
pr_err("%s: main driver probe failed", __func__);
return PTR_ERR(priv);
}
if (mac)
memcpy(priv->dev->dev_addr, mac, ETH_ALEN);
priv->dev->irq = platform_get_irq_byname(pdev, "macirq");
if (priv->dev->irq < 0) {
if (priv->dev->irq != -EPROBE_DEFER) {
netdev_err(priv->dev,
"MAC IRQ configuration information not found\n");
}
return priv->dev->irq;
}
priv->wol_irq = platform_get_irq_byname(pdev, "eth_wake_irq");
if (priv->wol_irq < 0) {
if (priv->wol_irq == -EPROBE_DEFER)
return -EPROBE_DEFER;
priv->wol_irq = priv->dev->irq;
}
priv->lpi_irq = platform_get_irq_byname(pdev, "eth_lpi");
if (priv->lpi_irq == -EPROBE_DEFER)
return -EPROBE_DEFER;
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
priv->plat->exit(pdev, priv->plat->bsp_priv);
if (priv->plat->free)
priv->plat->free(pdev, priv->plat->bsp_priv);
return ret;
}
static int stmmac_pltfr_suspend(struct device *dev)
{
int ret;
struct net_device *ndev = dev_get_drvdata(dev);
struct stmmac_priv *priv = netdev_priv(ndev);
struct platform_device *pdev = to_platform_device(dev);
ret = stmmac_suspend(ndev);
if (priv->plat->exit)
priv->plat->exit(pdev, priv->plat->bsp_priv);
return ret;
}
static int stmmac_pltfr_resume(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
struct stmmac_priv *priv = netdev_priv(ndev);
struct platform_device *pdev = to_platform_device(dev);
if (priv->plat->init)
priv->plat->init(pdev, priv->plat->bsp_priv);
return stmmac_resume(ndev);
}
