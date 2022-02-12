static bool lpss_dma_filter(struct dma_chan *chan, void *param)
{
struct dw_dma_slave *dws = param;
if (dws->dma_dev != chan->device->dev)
return false;
chan->private = dws;
return true;
}
static int lpss_spi_setup(struct pci_dev *dev, struct pxa_spi_info *c)
{
struct pci_dev *dma_dev;
c->num_chipselect = 1;
c->max_clk_rate = 50000000;
dma_dev = pci_get_slot(dev->bus, PCI_DEVFN(PCI_SLOT(dev->devfn), 0));
if (c->tx_param) {
struct dw_dma_slave *slave = c->tx_param;
slave->dma_dev = &dma_dev->dev;
slave->m_master = 0;
slave->p_master = 1;
}
if (c->rx_param) {
struct dw_dma_slave *slave = c->rx_param;
slave->dma_dev = &dma_dev->dev;
slave->m_master = 0;
slave->p_master = 1;
}
c->dma_filter = lpss_dma_filter;
return 0;
}
static int mrfld_spi_setup(struct pci_dev *dev, struct pxa_spi_info *c)
{
struct pci_dev *dma_dev = pci_get_slot(dev->bus, PCI_DEVFN(21, 0));
struct dw_dma_slave *tx, *rx;
switch (PCI_FUNC(dev->devfn)) {
case 0:
c->port_id = 3;
c->num_chipselect = 1;
c->tx_param = &mrfld3_tx_param;
c->rx_param = &mrfld3_rx_param;
break;
case 1:
c->port_id = 5;
c->num_chipselect = 4;
c->tx_param = &mrfld5_tx_param;
c->rx_param = &mrfld5_rx_param;
break;
case 2:
c->port_id = 6;
c->num_chipselect = 1;
c->tx_param = &mrfld6_tx_param;
c->rx_param = &mrfld6_rx_param;
break;
default:
return -ENODEV;
}
tx = c->tx_param;
tx->dma_dev = &dma_dev->dev;
rx = c->rx_param;
rx->dma_dev = &dma_dev->dev;
c->dma_filter = lpss_dma_filter;
return 0;
}
static int pxa2xx_spi_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
struct platform_device_info pi;
int ret;
struct platform_device *pdev;
struct pxa2xx_spi_master spi_pdata;
struct ssp_device *ssp;
struct pxa_spi_info *c;
char buf[40];
ret = pcim_enable_device(dev);
if (ret)
return ret;
ret = pcim_iomap_regions(dev, 1 << 0, "PXA2xx SPI");
if (ret)
return ret;
c = &spi_info_configs[ent->driver_data];
if (c->setup) {
ret = c->setup(dev, c);
if (ret)
return ret;
}
memset(&spi_pdata, 0, sizeof(spi_pdata));
spi_pdata.num_chipselect = (c->num_chipselect > 0) ? c->num_chipselect : dev->devfn;
spi_pdata.dma_filter = c->dma_filter;
spi_pdata.tx_param = c->tx_param;
spi_pdata.rx_param = c->rx_param;
spi_pdata.enable_dma = c->rx_param && c->tx_param;
ssp = &spi_pdata.ssp;
ssp->phys_base = pci_resource_start(dev, 0);
ssp->mmio_base = pcim_iomap_table(dev)[0];
ssp->port_id = (c->port_id >= 0) ? c->port_id : dev->devfn;
ssp->type = c->type;
pci_set_master(dev);
ret = pci_alloc_irq_vectors(dev, 1, 1, PCI_IRQ_ALL_TYPES);
if (ret < 0)
return ret;
ssp->irq = pci_irq_vector(dev, 0);
snprintf(buf, sizeof(buf), "pxa2xx-spi.%d", ssp->port_id);
ssp->clk = clk_register_fixed_rate(&dev->dev, buf , NULL, 0,
c->max_clk_rate);
if (IS_ERR(ssp->clk))
return PTR_ERR(ssp->clk);
memset(&pi, 0, sizeof(pi));
pi.fwnode = dev->dev.fwnode;
pi.parent = &dev->dev;
pi.name = "pxa2xx-spi";
pi.id = ssp->port_id;
pi.data = &spi_pdata;
pi.size_data = sizeof(spi_pdata);
pdev = platform_device_register_full(&pi);
if (IS_ERR(pdev)) {
clk_unregister(ssp->clk);
return PTR_ERR(pdev);
}
pci_set_drvdata(dev, pdev);
return 0;
}
static void pxa2xx_spi_pci_remove(struct pci_dev *dev)
{
struct platform_device *pdev = pci_get_drvdata(dev);
struct pxa2xx_spi_master *spi_pdata;
spi_pdata = dev_get_platdata(&pdev->dev);
platform_device_unregister(pdev);
clk_unregister(spi_pdata->ssp.clk);
}
