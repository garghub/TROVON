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
static struct stmmac_axi *stmmac_axi_setup(struct platform_device *pdev)
{
struct device_node *np;
struct stmmac_axi *axi;
np = of_parse_phandle(pdev->dev.of_node, "snps,axi-config", 0);
if (!np)
return NULL;
axi = kzalloc(sizeof(*axi), GFP_KERNEL);
if (!axi) {
of_node_put(np);
return ERR_PTR(-ENOMEM);
}
axi->axi_lpi_en = of_property_read_bool(np, "snps,lpi_en");
axi->axi_xit_frm = of_property_read_bool(np, "snps,xit_frm");
axi->axi_kbbe = of_property_read_bool(np, "snps,axi_kbbe");
axi->axi_axi_all = of_property_read_bool(np, "snps,axi_all");
axi->axi_fb = of_property_read_bool(np, "snps,axi_fb");
axi->axi_mb = of_property_read_bool(np, "snps,axi_mb");
axi->axi_rb = of_property_read_bool(np, "snps,axi_rb");
if (of_property_read_u32(np, "snps,wr_osr_lmt", &axi->axi_wr_osr_lmt))
axi->axi_wr_osr_lmt = 1;
if (of_property_read_u32(np, "snps,rd_osr_lmt", &axi->axi_rd_osr_lmt))
axi->axi_rd_osr_lmt = 1;
of_property_read_u32_array(np, "snps,blen", axi->axi_blen, AXI_BLEN);
of_node_put(np);
return axi;
}
static int stmmac_dt_phy(struct plat_stmmacenet_data *plat,
struct device_node *np, struct device *dev)
{
bool mdio = true;
plat->phy_node = of_parse_phandle(np, "phy-handle", 0);
if (plat->phy_node)
dev_dbg(dev, "Found phy-handle subnode\n");
if (!plat->phy_node && of_phy_is_fixed_link(np)) {
if ((of_phy_register_fixed_link(np) < 0))
return -ENODEV;
dev_dbg(dev, "Found fixed-link subnode\n");
plat->phy_node = of_node_get(np);
mdio = false;
}
for_each_child_of_node(np, plat->mdio_node) {
if (of_device_is_compatible(plat->mdio_node, "snps,dwmac-mdio"))
break;
}
if (plat->mdio_node) {
dev_dbg(dev, "Found MDIO subnode\n");
mdio = true;
}
if (mdio)
plat->mdio_bus_data =
devm_kzalloc(dev, sizeof(struct stmmac_mdio_bus_data),
GFP_KERNEL);
return 0;
}
struct plat_stmmacenet_data *
stmmac_probe_config_dt(struct platform_device *pdev, const char **mac)
{
struct device_node *np = pdev->dev.of_node;
struct plat_stmmacenet_data *plat;
struct stmmac_dma_cfg *dma_cfg;
plat = devm_kzalloc(&pdev->dev, sizeof(*plat), GFP_KERNEL);
if (!plat)
return ERR_PTR(-ENOMEM);
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
if (stmmac_dt_phy(plat, np, &pdev->dev))
return ERR_PTR(-ENODEV);
of_property_read_u32(np, "tx-fifo-depth", &plat->tx_fifo_size);
of_property_read_u32(np, "rx-fifo-depth", &plat->rx_fifo_size);
plat->force_sf_dma_mode =
of_property_read_bool(np, "snps,force_sf_dma_mode");
plat->maxmtu = JUMBO_LEN;
plat->multicast_filter_bins = HASH_TABLE_SIZE;
plat->unicast_filter_entries = 1;
if (of_device_is_compatible(np, "st,spear600-gmac") ||
of_device_is_compatible(np, "snps,dwmac-3.50a") ||
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
if (of_device_is_compatible(np, "snps,dwmac-4.00") ||
of_device_is_compatible(np, "snps,dwmac-4.10a")) {
plat->has_gmac4 = 1;
plat->pmt = 1;
plat->tso_en = of_property_read_bool(np, "snps,tso");
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
if (!dma_cfg) {
stmmac_remove_config_dt(pdev, plat);
return ERR_PTR(-ENOMEM);
}
plat->dma_cfg = dma_cfg;
of_property_read_u32(np, "snps,pbl", &dma_cfg->pbl);
dma_cfg->aal = of_property_read_bool(np, "snps,aal");
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
of_property_read_u32(np, "snps,ps-speed", &plat->mac_port_sel_speed);
plat->axi = stmmac_axi_setup(pdev);
return plat;
}
void stmmac_remove_config_dt(struct platform_device *pdev,
struct plat_stmmacenet_data *plat)
{
struct device_node *np = pdev->dev.of_node;
if (of_phy_is_fixed_link(np))
of_phy_deregister_fixed_link(np);
of_node_put(plat->phy_node);
}
struct plat_stmmacenet_data *
stmmac_probe_config_dt(struct platform_device *pdev, const char **mac)
{
return ERR_PTR(-ENOSYS);
}
void stmmac_remove_config_dt(struct platform_device *pdev,
struct plat_stmmacenet_data *plat)
{
}
int stmmac_get_platform_resources(struct platform_device *pdev,
struct stmmac_resources *stmmac_res)
{
struct resource *res;
memset(stmmac_res, 0, sizeof(*stmmac_res));
stmmac_res->irq = platform_get_irq_byname(pdev, "macirq");
if (stmmac_res->irq < 0) {
if (stmmac_res->irq != -EPROBE_DEFER) {
dev_err(&pdev->dev,
"MAC IRQ configuration information not found\n");
}
return stmmac_res->irq;
}
stmmac_res->wol_irq = platform_get_irq_byname(pdev, "eth_wake_irq");
if (stmmac_res->wol_irq < 0) {
if (stmmac_res->wol_irq == -EPROBE_DEFER)
return -EPROBE_DEFER;
stmmac_res->wol_irq = stmmac_res->irq;
}
stmmac_res->lpi_irq = platform_get_irq_byname(pdev, "eth_lpi");
if (stmmac_res->lpi_irq == -EPROBE_DEFER)
return -EPROBE_DEFER;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
stmmac_res->addr = devm_ioremap_resource(&pdev->dev, res);
return PTR_ERR_OR_ZERO(stmmac_res->addr);
}
int stmmac_pltfr_remove(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct stmmac_priv *priv = netdev_priv(ndev);
struct plat_stmmacenet_data *plat = priv->plat;
int ret = stmmac_dvr_remove(&pdev->dev);
if (plat->exit)
plat->exit(pdev, plat->bsp_priv);
stmmac_remove_config_dt(pdev, plat);
return ret;
}
static int stmmac_pltfr_suspend(struct device *dev)
{
int ret;
struct net_device *ndev = dev_get_drvdata(dev);
struct stmmac_priv *priv = netdev_priv(ndev);
struct platform_device *pdev = to_platform_device(dev);
ret = stmmac_suspend(dev);
if (priv->plat->suspend)
priv->plat->suspend(pdev, priv->plat->bsp_priv);
else if (priv->plat->exit)
priv->plat->exit(pdev, priv->plat->bsp_priv);
return ret;
}
static int stmmac_pltfr_resume(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
struct stmmac_priv *priv = netdev_priv(ndev);
struct platform_device *pdev = to_platform_device(dev);
if (priv->plat->resume)
priv->plat->resume(pdev, priv->plat->bsp_priv);
else if (priv->plat->init)
priv->plat->init(pdev, priv->plat->bsp_priv);
return stmmac_resume(dev);
}
