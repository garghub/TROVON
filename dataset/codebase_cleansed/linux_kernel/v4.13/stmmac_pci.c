static int stmmac_pci_find_phy_addr(struct pci_dev *pdev,
const struct dmi_system_id *dmi_list)
{
const struct stmmac_pci_func_data *func_data;
const struct stmmac_pci_dmi_data *dmi_data;
const struct dmi_system_id *dmi_id;
int func = PCI_FUNC(pdev->devfn);
size_t n;
dmi_id = dmi_first_match(dmi_list);
if (!dmi_id)
return -ENODEV;
dmi_data = dmi_id->driver_data;
func_data = dmi_data->func;
for (n = 0; n < dmi_data->nfuncs; n++, func_data++)
if (func_data->func == func)
return func_data->phy_addr;
return -ENODEV;
}
static void common_default_data(struct plat_stmmacenet_data *plat)
{
plat->clk_csr = 2;
plat->has_gmac = 1;
plat->force_sf_dma_mode = 1;
plat->mdio_bus_data->phy_reset = NULL;
plat->mdio_bus_data->phy_mask = 0;
plat->multicast_filter_bins = HASH_TABLE_SIZE;
plat->unicast_filter_entries = 1;
plat->maxmtu = JUMBO_LEN;
plat->tx_queues_to_use = 1;
plat->rx_queues_to_use = 1;
plat->tx_queues_cfg[0].use_prio = false;
plat->rx_queues_cfg[0].use_prio = false;
plat->rx_queues_cfg[0].pkt_route = 0x0;
}
static int stmmac_default_data(struct pci_dev *pdev,
struct plat_stmmacenet_data *plat)
{
common_default_data(plat);
plat->bus_id = 1;
plat->phy_addr = 0;
plat->interface = PHY_INTERFACE_MODE_GMII;
plat->dma_cfg->pbl = 32;
plat->dma_cfg->pblx8 = true;
return 0;
}
static int quark_default_data(struct pci_dev *pdev,
struct plat_stmmacenet_data *plat)
{
int ret;
common_default_data(plat);
ret = stmmac_pci_find_phy_addr(pdev, quark_pci_dmi);
if (ret < 0) {
if (dmi_get_system_info(DMI_BOARD_NAME))
return ret;
ret = 1;
}
plat->bus_id = PCI_DEVID(pdev->bus->number, pdev->devfn);
plat->phy_addr = ret;
plat->interface = PHY_INTERFACE_MODE_RMII;
plat->dma_cfg->pbl = 16;
plat->dma_cfg->pblx8 = true;
plat->dma_cfg->fixed_burst = 1;
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
ret = info->setup(pdev, plat);
if (ret)
return ret;
pci_enable_msi(pdev);
memset(&res, 0, sizeof(res));
res.addr = pcim_iomap_table(pdev)[i];
res.wol_irq = pdev->irq;
res.irq = pdev->irq;
return stmmac_dvr_probe(&pdev->dev, plat, &res);
}
static void stmmac_pci_remove(struct pci_dev *pdev)
{
stmmac_dvr_remove(&pdev->dev);
}
