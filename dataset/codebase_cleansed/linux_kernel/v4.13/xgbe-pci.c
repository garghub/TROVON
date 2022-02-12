static int xgbe_config_multi_msi(struct xgbe_prv_data *pdata)
{
unsigned int vector_count;
unsigned int i, j;
int ret;
vector_count = XGBE_MSI_BASE_COUNT;
vector_count += max(pdata->rx_ring_count,
pdata->tx_ring_count);
ret = pci_alloc_irq_vectors(pdata->pcidev, XGBE_MSI_MIN_COUNT,
vector_count, PCI_IRQ_MSI | PCI_IRQ_MSIX);
if (ret < 0) {
dev_info(pdata->dev, "multi MSI/MSI-X enablement failed\n");
return ret;
}
pdata->isr_as_tasklet = 1;
pdata->irq_count = ret;
pdata->dev_irq = pci_irq_vector(pdata->pcidev, 0);
pdata->ecc_irq = pci_irq_vector(pdata->pcidev, 1);
pdata->i2c_irq = pci_irq_vector(pdata->pcidev, 2);
pdata->an_irq = pci_irq_vector(pdata->pcidev, 3);
for (i = XGBE_MSI_BASE_COUNT, j = 0; i < ret; i++, j++)
pdata->channel_irq[j] = pci_irq_vector(pdata->pcidev, i);
pdata->channel_irq_count = j;
pdata->per_channel_irq = 1;
pdata->channel_irq_mode = XGBE_IRQ_MODE_LEVEL;
if (netif_msg_probe(pdata))
dev_dbg(pdata->dev, "multi %s interrupts enabled\n",
pdata->pcidev->msix_enabled ? "MSI-X" : "MSI");
return 0;
}
static int xgbe_config_irqs(struct xgbe_prv_data *pdata)
{
int ret;
ret = xgbe_config_multi_msi(pdata);
if (!ret)
goto out;
ret = pci_alloc_irq_vectors(pdata->pcidev, 1, 1,
PCI_IRQ_LEGACY | PCI_IRQ_MSI);
if (ret < 0) {
dev_info(pdata->dev, "single IRQ enablement failed\n");
return ret;
}
pdata->isr_as_tasklet = pdata->pcidev->msi_enabled ? 1 : 0;
pdata->irq_count = 1;
pdata->channel_irq_count = 1;
pdata->dev_irq = pci_irq_vector(pdata->pcidev, 0);
pdata->ecc_irq = pci_irq_vector(pdata->pcidev, 0);
pdata->i2c_irq = pci_irq_vector(pdata->pcidev, 0);
pdata->an_irq = pci_irq_vector(pdata->pcidev, 0);
if (netif_msg_probe(pdata))
dev_dbg(pdata->dev, "single %s interrupt enabled\n",
pdata->pcidev->msi_enabled ? "MSI" : "legacy");
out:
if (netif_msg_probe(pdata)) {
unsigned int i;
dev_dbg(pdata->dev, " dev irq=%d\n", pdata->dev_irq);
dev_dbg(pdata->dev, " ecc irq=%d\n", pdata->ecc_irq);
dev_dbg(pdata->dev, " i2c irq=%d\n", pdata->i2c_irq);
dev_dbg(pdata->dev, " an irq=%d\n", pdata->an_irq);
for (i = 0; i < pdata->channel_irq_count; i++)
dev_dbg(pdata->dev, " dma%u irq=%d\n",
i, pdata->channel_irq[i]);
}
return 0;
}
static int xgbe_pci_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
struct xgbe_prv_data *pdata;
struct device *dev = &pdev->dev;
void __iomem * const *iomap_table;
struct pci_dev *rdev;
unsigned int ma_lo, ma_hi;
unsigned int reg;
int bar_mask;
int ret;
pdata = xgbe_alloc_pdata(dev);
if (IS_ERR(pdata)) {
ret = PTR_ERR(pdata);
goto err_alloc;
}
pdata->pcidev = pdev;
pci_set_drvdata(pdev, pdata);
pdata->vdata = (struct xgbe_version_data *)id->driver_data;
ret = pcim_enable_device(pdev);
if (ret) {
dev_err(dev, "pcim_enable_device failed\n");
goto err_pci_enable;
}
bar_mask = pci_select_bars(pdev, IORESOURCE_MEM);
ret = pcim_iomap_regions(pdev, bar_mask, XGBE_DRV_NAME);
if (ret) {
dev_err(dev, "pcim_iomap_regions failed\n");
goto err_pci_enable;
}
iomap_table = pcim_iomap_table(pdev);
if (!iomap_table) {
dev_err(dev, "pcim_iomap_table failed\n");
ret = -ENOMEM;
goto err_pci_enable;
}
pdata->xgmac_regs = iomap_table[XGBE_XGMAC_BAR];
if (!pdata->xgmac_regs) {
dev_err(dev, "xgmac ioremap failed\n");
ret = -ENOMEM;
goto err_pci_enable;
}
pdata->xprop_regs = pdata->xgmac_regs + XGBE_MAC_PROP_OFFSET;
pdata->xi2c_regs = pdata->xgmac_regs + XGBE_I2C_CTRL_OFFSET;
if (netif_msg_probe(pdata)) {
dev_dbg(dev, "xgmac_regs = %p\n", pdata->xgmac_regs);
dev_dbg(dev, "xprop_regs = %p\n", pdata->xprop_regs);
dev_dbg(dev, "xi2c_regs = %p\n", pdata->xi2c_regs);
}
pdata->xpcs_regs = iomap_table[XGBE_XPCS_BAR];
if (!pdata->xpcs_regs) {
dev_err(dev, "xpcs ioremap failed\n");
ret = -ENOMEM;
goto err_pci_enable;
}
if (netif_msg_probe(pdata))
dev_dbg(dev, "xpcs_regs = %p\n", pdata->xpcs_regs);
rdev = pci_get_domain_bus_and_slot(0, 0, PCI_DEVFN(0, 0));
if (rdev &&
(rdev->vendor == PCI_VENDOR_ID_AMD) && (rdev->device == 0x15d0)) {
pdata->xpcs_window_def_reg = PCS_V2_RV_WINDOW_DEF;
pdata->xpcs_window_sel_reg = PCS_V2_RV_WINDOW_SELECT;
} else {
pdata->xpcs_window_def_reg = PCS_V2_WINDOW_DEF;
pdata->xpcs_window_sel_reg = PCS_V2_WINDOW_SELECT;
}
pci_dev_put(rdev);
reg = XPCS32_IOREAD(pdata, pdata->xpcs_window_def_reg);
pdata->xpcs_window = XPCS_GET_BITS(reg, PCS_V2_WINDOW_DEF, OFFSET);
pdata->xpcs_window <<= 6;
pdata->xpcs_window_size = XPCS_GET_BITS(reg, PCS_V2_WINDOW_DEF, SIZE);
pdata->xpcs_window_size = 1 << (pdata->xpcs_window_size + 7);
pdata->xpcs_window_mask = pdata->xpcs_window_size - 1;
if (netif_msg_probe(pdata)) {
dev_dbg(dev, "xpcs window = %#010x\n",
pdata->xpcs_window);
dev_dbg(dev, "xpcs window size = %#010x\n",
pdata->xpcs_window_size);
dev_dbg(dev, "xpcs window mask = %#010x\n",
pdata->xpcs_window_mask);
}
pci_set_master(pdev);
XP_IOWRITE(pdata, XP_INT_EN, 0x1fffff);
ma_lo = XP_IOREAD(pdata, XP_MAC_ADDR_LO);
ma_hi = XP_IOREAD(pdata, XP_MAC_ADDR_HI);
pdata->mac_addr[0] = ma_lo & 0xff;
pdata->mac_addr[1] = (ma_lo >> 8) & 0xff;
pdata->mac_addr[2] = (ma_lo >> 16) & 0xff;
pdata->mac_addr[3] = (ma_lo >> 24) & 0xff;
pdata->mac_addr[4] = ma_hi & 0xff;
pdata->mac_addr[5] = (ma_hi >> 8) & 0xff;
if (!XP_GET_BITS(ma_hi, XP_MAC_ADDR_HI, VALID) ||
!is_valid_ether_addr(pdata->mac_addr)) {
dev_err(dev, "invalid mac address\n");
ret = -EINVAL;
goto err_pci_enable;
}
pdata->sysclk_rate = XGBE_V2_DMA_CLOCK_FREQ;
pdata->ptpclk_rate = XGBE_V2_PTP_CLOCK_FREQ;
pdata->coherent = 1;
pdata->arcr = XGBE_DMA_PCI_ARCR;
pdata->awcr = XGBE_DMA_PCI_AWCR;
pdata->awarcr = XGBE_DMA_PCI_AWARCR;
reg = XP_IOREAD(pdata, XP_PROP_1);
pdata->tx_max_channel_count = XP_GET_BITS(reg, XP_PROP_1, MAX_TX_DMA);
pdata->rx_max_channel_count = XP_GET_BITS(reg, XP_PROP_1, MAX_RX_DMA);
pdata->tx_max_q_count = XP_GET_BITS(reg, XP_PROP_1, MAX_TX_QUEUES);
pdata->rx_max_q_count = XP_GET_BITS(reg, XP_PROP_1, MAX_RX_QUEUES);
if (netif_msg_probe(pdata)) {
dev_dbg(dev, "max tx/rx channel count = %u/%u\n",
pdata->tx_max_channel_count,
pdata->tx_max_channel_count);
dev_dbg(dev, "max tx/rx hw queue count = %u/%u\n",
pdata->tx_max_q_count, pdata->rx_max_q_count);
}
xgbe_set_counts(pdata);
reg = XP_IOREAD(pdata, XP_PROP_2);
pdata->tx_max_fifo_size = XP_GET_BITS(reg, XP_PROP_2, TX_FIFO_SIZE);
pdata->tx_max_fifo_size *= 16384;
pdata->tx_max_fifo_size = min(pdata->tx_max_fifo_size,
pdata->vdata->tx_max_fifo_size);
pdata->rx_max_fifo_size = XP_GET_BITS(reg, XP_PROP_2, RX_FIFO_SIZE);
pdata->rx_max_fifo_size *= 16384;
pdata->rx_max_fifo_size = min(pdata->rx_max_fifo_size,
pdata->vdata->rx_max_fifo_size);
if (netif_msg_probe(pdata))
dev_dbg(dev, "max tx/rx max fifo size = %u/%u\n",
pdata->tx_max_fifo_size, pdata->rx_max_fifo_size);
ret = xgbe_config_irqs(pdata);
if (ret)
goto err_pci_enable;
ret = xgbe_config_netdev(pdata);
if (ret)
goto err_irq_vectors;
netdev_notice(pdata->netdev, "net device enabled\n");
return 0;
err_irq_vectors:
pci_free_irq_vectors(pdata->pcidev);
err_pci_enable:
xgbe_free_pdata(pdata);
err_alloc:
dev_notice(dev, "net device not enabled\n");
return ret;
}
static void xgbe_pci_remove(struct pci_dev *pdev)
{
struct xgbe_prv_data *pdata = pci_get_drvdata(pdev);
xgbe_deconfig_netdev(pdata);
pci_free_irq_vectors(pdata->pcidev);
xgbe_free_pdata(pdata);
}
static int xgbe_pci_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct xgbe_prv_data *pdata = pci_get_drvdata(pdev);
struct net_device *netdev = pdata->netdev;
int ret = 0;
if (netif_running(netdev))
ret = xgbe_powerdown(netdev, XGMAC_DRIVER_CONTEXT);
pdata->lpm_ctrl = XMDIO_READ(pdata, MDIO_MMD_PCS, MDIO_CTRL1);
pdata->lpm_ctrl |= MDIO_CTRL1_LPOWER;
XMDIO_WRITE(pdata, MDIO_MMD_PCS, MDIO_CTRL1, pdata->lpm_ctrl);
return ret;
}
static int xgbe_pci_resume(struct pci_dev *pdev)
{
struct xgbe_prv_data *pdata = pci_get_drvdata(pdev);
struct net_device *netdev = pdata->netdev;
int ret = 0;
pdata->lpm_ctrl &= ~MDIO_CTRL1_LPOWER;
XMDIO_WRITE(pdata, MDIO_MMD_PCS, MDIO_CTRL1, pdata->lpm_ctrl);
if (netif_running(netdev)) {
ret = xgbe_powerup(netdev, XGMAC_DRIVER_CONTEXT);
schedule_work(&pdata->restart_work);
}
return ret;
}
int xgbe_pci_init(void)
{
return pci_register_driver(&xgbe_driver);
}
void xgbe_pci_exit(void)
{
pci_unregister_driver(&xgbe_driver);
}
