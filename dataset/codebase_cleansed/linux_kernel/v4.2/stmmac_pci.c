static int stmmac_pci_find_phy_addr(struct stmmac_pci_info *info)
{
const char *name = dmi_get_system_info(DMI_BOARD_NAME);
unsigned int func = PCI_FUNC(info->pdev->devfn);
struct stmmac_pci_dmi_data *dmi;
if (!name)
return 1;
for (dmi = info->dmi; dmi->name && *dmi->name; dmi++) {
if (!strcmp(dmi->name, name) && dmi->func == func)
return dmi->phy_addr;
}
return -ENODEV;
}
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
static int quark_default_data(struct plat_stmmacenet_data *plat,
struct stmmac_pci_info *info)
{
struct pci_dev *pdev = info->pdev;
int ret;
ret = stmmac_pci_find_phy_addr(info);
if (ret < 0)
return ret;
plat->bus_id = PCI_DEVID(pdev->bus->number, pdev->devfn);
plat->phy_addr = ret;
plat->interface = PHY_INTERFACE_MODE_RMII;
plat->clk_csr = 2;
plat->has_gmac = 1;
plat->force_sf_dma_mode = 1;
plat->mdio_bus_data->phy_reset = NULL;
plat->mdio_bus_data->phy_mask = 0;
plat->dma_cfg->pbl = 16;
plat->dma_cfg->burst_len = DMA_AXI_BLEN_256;
plat->dma_cfg->fixed_burst = 1;
plat->multicast_filter_bins = HASH_TABLE_SIZE;
plat->unicast_filter_entries = 1;
return 0;
}
static int stmmac_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct stmmac_pci_info *info = (struct stmmac_pci_info *)id->driver_data;
struct plat_stmmacenet_data *plat;
struct stmmac_resources res;
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
if (info) {
info->pdev = pdev;
if (info->setup) {
ret = info->setup(plat, info);
if (ret)
return ret;
}
} else
stmmac_default_data(plat);
pci_enable_msi(pdev);
memset(&res, 0, sizeof(res));
res.addr = pcim_iomap_table(pdev)[i];
res.wol_irq = pdev->irq;
res.irq = pdev->irq;
return stmmac_dvr_probe(&pdev->dev, plat, &res);
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
