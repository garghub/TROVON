static int pxa2xx_spi_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
struct platform_device_info pi;
int ret;
struct platform_device *pdev;
struct pxa2xx_spi_master spi_pdata;
struct ssp_device *ssp;
struct pxa_spi_info *c;
ret = pcim_enable_device(dev);
if (ret)
return ret;
ret = pcim_iomap_regions(dev, 1 << 0, "PXA2xx SPI");
if (ret)
return ret;
c = &spi_info_configs[ent->driver_data];
memset(&spi_pdata, 0, sizeof(spi_pdata));
spi_pdata.num_chipselect = (c->num_chipselect > 0) ?
c->num_chipselect : dev->devfn;
spi_pdata.tx_slave_id = c->tx_slave_id;
spi_pdata.tx_chan_id = c->tx_chan_id;
spi_pdata.rx_slave_id = c->rx_slave_id;
spi_pdata.rx_chan_id = c->rx_chan_id;
spi_pdata.enable_dma = c->rx_slave_id >= 0 && c->tx_slave_id >= 0;
ssp = &spi_pdata.ssp;
ssp->phys_base = pci_resource_start(dev, 0);
ssp->mmio_base = pcim_iomap_table(dev)[0];
if (!ssp->mmio_base) {
dev_err(&dev->dev, "failed to ioremap() registers\n");
return -EIO;
}
ssp->irq = dev->irq;
ssp->port_id = (c->port_id >= 0) ? c->port_id : dev->devfn;
ssp->type = c->type;
memset(&pi, 0, sizeof(pi));
pi.parent = &dev->dev;
pi.name = "pxa2xx-spi";
pi.id = ssp->port_id;
pi.data = &spi_pdata;
pi.size_data = sizeof(spi_pdata);
pdev = platform_device_register_full(&pi);
if (IS_ERR(pdev))
return PTR_ERR(pdev);
pci_set_drvdata(dev, pdev);
return 0;
}
static void pxa2xx_spi_pci_remove(struct pci_dev *dev)
{
struct platform_device *pdev = pci_get_drvdata(dev);
platform_device_unregister(pdev);
}
