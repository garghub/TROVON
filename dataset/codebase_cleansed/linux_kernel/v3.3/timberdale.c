static ssize_t show_fw_ver(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct timberdale_device *priv = pci_get_drvdata(pdev);
return sprintf(buf, "%d.%d.%d\n", priv->fw.major, priv->fw.minor,
priv->fw.config);
}
static int __devinit timb_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
struct timberdale_device *priv;
int err, i;
resource_size_t mapbase;
struct msix_entry *msix_entries = NULL;
u8 ip_setup;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
pci_set_drvdata(dev, priv);
err = pci_enable_device(dev);
if (err)
goto err_enable;
mapbase = pci_resource_start(dev, 0);
if (!mapbase) {
dev_err(&dev->dev, "No resource\n");
goto err_start;
}
priv->ctl_mapbase = mapbase + CHIPCTLOFFSET;
if (!request_mem_region(priv->ctl_mapbase, CHIPCTLSIZE, "timb-ctl")) {
dev_err(&dev->dev, "Failed to request ctl mem\n");
goto err_request;
}
priv->ctl_membase = ioremap(priv->ctl_mapbase, CHIPCTLSIZE);
if (!priv->ctl_membase) {
dev_err(&dev->dev, "ioremap failed for ctl mem\n");
goto err_ioremap;
}
priv->fw.major = ioread32(priv->ctl_membase + TIMB_REV_MAJOR);
priv->fw.minor = ioread32(priv->ctl_membase + TIMB_REV_MINOR);
priv->fw.config = ioread32(priv->ctl_membase + TIMB_HW_CONFIG);
if (priv->fw.major > TIMB_SUPPORTED_MAJOR) {
dev_err(&dev->dev, "The driver supports an older "
"version of the FPGA, please update the driver to "
"support %d.%d\n", priv->fw.major, priv->fw.minor);
goto err_config;
}
if (priv->fw.major < TIMB_SUPPORTED_MAJOR ||
priv->fw.minor < TIMB_REQUIRED_MINOR) {
dev_err(&dev->dev, "The FPGA image is too old (%d.%d), "
"please upgrade the FPGA to at least: %d.%d\n",
priv->fw.major, priv->fw.minor,
TIMB_SUPPORTED_MAJOR, TIMB_REQUIRED_MINOR);
goto err_config;
}
msix_entries = kzalloc(TIMBERDALE_NR_IRQS * sizeof(*msix_entries),
GFP_KERNEL);
if (!msix_entries)
goto err_config;
for (i = 0; i < TIMBERDALE_NR_IRQS; i++)
msix_entries[i].entry = i;
err = pci_enable_msix(dev, msix_entries, TIMBERDALE_NR_IRQS);
if (err) {
dev_err(&dev->dev,
"MSI-X init failed: %d, expected entries: %d\n",
err, TIMBERDALE_NR_IRQS);
goto err_msix;
}
err = device_create_file(&dev->dev, &dev_attr_fw_ver);
if (err)
goto err_create_file;
iowrite32(0x1, priv->ctl_membase + TIMB_SW_RST);
for (i = 0; i < ARRAY_SIZE(timberdale_i2c_board_info); i++)
timberdale_i2c_board_info[i].irq =
msix_entries[timberdale_i2c_board_info[i].irq].vector;
if (priv->fw.config & TIMB_HW_CONFIG_SPI_8BIT) {
timberdale_xspi_platform_data.bits_per_word = 8;
timberdale_xspi_platform_data.devices =
timberdale_spi_8bit_board_info;
timberdale_xspi_platform_data.num_devices =
ARRAY_SIZE(timberdale_spi_8bit_board_info);
} else {
timberdale_xspi_platform_data.bits_per_word = 16;
timberdale_xspi_platform_data.devices =
timberdale_spi_16bit_board_info;
timberdale_xspi_platform_data.num_devices =
ARRAY_SIZE(timberdale_spi_16bit_board_info);
}
ip_setup = priv->fw.config & TIMB_HW_VER_MASK;
switch (ip_setup) {
case TIMB_HW_VER0:
err = mfd_add_devices(&dev->dev, -1,
timberdale_cells_bar0_cfg0,
ARRAY_SIZE(timberdale_cells_bar0_cfg0),
&dev->resource[0], msix_entries[0].vector);
break;
case TIMB_HW_VER1:
err = mfd_add_devices(&dev->dev, -1,
timberdale_cells_bar0_cfg1,
ARRAY_SIZE(timberdale_cells_bar0_cfg1),
&dev->resource[0], msix_entries[0].vector);
break;
case TIMB_HW_VER2:
err = mfd_add_devices(&dev->dev, -1,
timberdale_cells_bar0_cfg2,
ARRAY_SIZE(timberdale_cells_bar0_cfg2),
&dev->resource[0], msix_entries[0].vector);
break;
case TIMB_HW_VER3:
err = mfd_add_devices(&dev->dev, -1,
timberdale_cells_bar0_cfg3,
ARRAY_SIZE(timberdale_cells_bar0_cfg3),
&dev->resource[0], msix_entries[0].vector);
break;
default:
dev_err(&dev->dev, "Uknown IP setup: %d.%d.%d\n",
priv->fw.major, priv->fw.minor, ip_setup);
err = -ENODEV;
goto err_mfd;
break;
}
if (err) {
dev_err(&dev->dev, "mfd_add_devices failed: %d\n", err);
goto err_mfd;
}
err = mfd_add_devices(&dev->dev, 0,
timberdale_cells_bar1, ARRAY_SIZE(timberdale_cells_bar1),
&dev->resource[1], msix_entries[0].vector);
if (err) {
dev_err(&dev->dev, "mfd_add_devices failed: %d\n", err);
goto err_mfd2;
}
if (((priv->fw.config & TIMB_HW_VER_MASK) == TIMB_HW_VER0) ||
((priv->fw.config & TIMB_HW_VER_MASK) == TIMB_HW_VER3)) {
err = mfd_add_devices(&dev->dev, 1, timberdale_cells_bar2,
ARRAY_SIZE(timberdale_cells_bar2),
&dev->resource[2], msix_entries[0].vector);
if (err) {
dev_err(&dev->dev, "mfd_add_devices failed: %d\n", err);
goto err_mfd2;
}
}
kfree(msix_entries);
dev_info(&dev->dev,
"Found Timberdale Card. Rev: %d.%d, HW config: 0x%02x\n",
priv->fw.major, priv->fw.minor, priv->fw.config);
return 0;
err_mfd2:
mfd_remove_devices(&dev->dev);
err_mfd:
device_remove_file(&dev->dev, &dev_attr_fw_ver);
err_create_file:
pci_disable_msix(dev);
err_msix:
kfree(msix_entries);
err_config:
iounmap(priv->ctl_membase);
err_ioremap:
release_mem_region(priv->ctl_mapbase, CHIPCTLSIZE);
err_request:
pci_set_drvdata(dev, NULL);
err_start:
pci_disable_device(dev);
err_enable:
kfree(priv);
pci_set_drvdata(dev, NULL);
return -ENODEV;
}
static void __devexit timb_remove(struct pci_dev *dev)
{
struct timberdale_device *priv = pci_get_drvdata(dev);
mfd_remove_devices(&dev->dev);
device_remove_file(&dev->dev, &dev_attr_fw_ver);
iounmap(priv->ctl_membase);
release_mem_region(priv->ctl_mapbase, CHIPCTLSIZE);
pci_disable_msix(dev);
pci_disable_device(dev);
pci_set_drvdata(dev, NULL);
kfree(priv);
}
static int __init timberdale_init(void)
{
int err;
err = pci_register_driver(&timberdale_pci_driver);
if (err < 0) {
printk(KERN_ERR
"Failed to register PCI driver for %s device.\n",
timberdale_pci_driver.name);
return -ENODEV;
}
printk(KERN_INFO "Driver for %s has been successfully registered.\n",
timberdale_pci_driver.name);
return 0;
}
static void __exit timberdale_exit(void)
{
pci_unregister_driver(&timberdale_pci_driver);
printk(KERN_INFO "Driver for %s has been successfully unregistered.\n",
timberdale_pci_driver.name);
}
