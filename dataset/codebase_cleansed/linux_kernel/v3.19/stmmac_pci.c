static void stmmac_default_data(struct plat_stmmacenet_data *plat)
{
plat->bus_id = 1;
plat->phy_addr = 0;
plat->interface = PHY_INTERFACE_MODE_GMII;
plat->clk_csr = 2;
plat->has_gmac = 1;
plat->force_sf_dma_mode = 1;
plat->mdio_bus_data->phy_reset = NULL;
plat->mdio_bus_data->phy_mask = 0;
plat->dma_cfg->pbl = 32;
plat->dma_cfg->burst_len = DMA_AXI_BLEN_256;
plat->multicast_filter_bins = HASH_TABLE_SIZE;
plat->unicast_filter_entries = 1;
}
static int stmmac_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct plat_stmmacenet_data *plat;
struct stmmac_priv *priv;
int i;
int ret;
plat = devm_kzalloc(&pdev->dev, sizeof(*plat), GFP_KERNEL);
if (!plat)
return -ENOMEM;
plat->mdio_bus_data = devm_kzalloc(&pdev->dev,
sizeof(*plat->mdio_bus_data),
GFP_KERNEL);
if (!plat->mdio_bus_data)
return -ENOMEM;
plat->dma_cfg = devm_kzalloc(&pdev->dev, sizeof(*plat->dma_cfg),
GFP_KERNEL);
if (!plat->dma_cfg)
return -ENOMEM;
ret = pcim_enable_device(pdev);
if (ret) {
dev_err(&pdev->dev, "%s: ERROR: failed to enable device\n",
__func__);
return ret;
}
for (i = 0; i <= PCI_STD_RESOURCE_END; i++) {
if (pci_resource_len(pdev, i) == 0)
continue;
ret = pcim_iomap_regions(pdev, BIT(i), pci_name(pdev));
if (ret)
return ret;
break;
}
pci_set_master(pdev);
stmmac_default_data(plat);
priv = stmmac_dvr_probe(&pdev->dev, plat, pcim_iomap_table(pdev)[i]);
if (IS_ERR(priv)) {
dev_err(&pdev->dev, "%s: main driver probe failed\n", __func__);
return PTR_ERR(priv);
}
priv->dev->irq = pdev->irq;
priv->wol_irq = pdev->irq;
pci_set_drvdata(pdev, priv->dev);
dev_dbg(&pdev->dev, "STMMAC PCI driver registration completed\n");
return 0;
}
static void stmmac_pci_remove(struct pci_dev *pdev)
{
struct net_device *ndev = pci_get_drvdata(pdev);
stmmac_dvr_remove(ndev);
}
static int stmmac_pci_suspend(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct net_device *ndev = pci_get_drvdata(pdev);
return stmmac_suspend(ndev);
}
static int stmmac_pci_resume(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct net_device *ndev = pci_get_drvdata(pdev);
return stmmac_resume(ndev);
}
