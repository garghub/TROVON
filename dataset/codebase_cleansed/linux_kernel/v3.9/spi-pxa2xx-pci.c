static int ce4100_spi_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
struct platform_device_info pi;
int ret;
struct platform_device *pdev;
struct pxa2xx_spi_master spi_pdata;
struct ssp_device *ssp;
ret = pcim_enable_device(dev);
if (ret)
return ret;
ret = pcim_iomap_regions(dev, 1 << 0, "PXA2xx SPI");
if (!ret)
return ret;
memset(&spi_pdata, 0, sizeof(spi_pdata));
spi_pdata.num_chipselect = dev->devfn;
ssp = &spi_pdata.ssp;
ssp->phys_base = pci_resource_start(dev, 0);
ssp->mmio_base = pcim_iomap_table(dev)[0];
if (!ssp->mmio_base) {
dev_err(&dev->dev, "failed to ioremap() registers\n");
return -EIO;
}
ssp->irq = dev->irq;
ssp->port_id = dev->devfn;
ssp->type = PXA25x_SSP;
memset(&pi, 0, sizeof(pi));
pi.parent = &dev->dev;
pi.name = "pxa2xx-spi";
pi.id = ssp->port_id;
pi.data = &spi_pdata;
pi.size_data = sizeof(spi_pdata);
pdev = platform_device_register_full(&pi);
if (!pdev)
return -ENOMEM;
pci_set_drvdata(dev, pdev);
return 0;
}
static void ce4100_spi_remove(struct pci_dev *dev)
{
struct platform_device *pdev = pci_get_drvdata(dev);
platform_device_unregister(pdev);
}
