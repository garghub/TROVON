static int __devinit lpc_sch_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
unsigned int base_addr_cfg;
unsigned short base_addr;
int i;
int ret;
pci_read_config_dword(dev, SMBASE, &base_addr_cfg);
if (!(base_addr_cfg & (1 << 31))) {
dev_err(&dev->dev, "Decode of the SMBus I/O range disabled\n");
return -ENODEV;
}
base_addr = (unsigned short)base_addr_cfg;
if (base_addr == 0) {
dev_err(&dev->dev, "I/O space for SMBus uninitialized\n");
return -ENODEV;
}
smbus_sch_resource.start = base_addr;
smbus_sch_resource.end = base_addr + SMBUS_IO_SIZE - 1;
pci_read_config_dword(dev, GPIOBASE, &base_addr_cfg);
if (!(base_addr_cfg & (1 << 31))) {
dev_err(&dev->dev, "Decode of the GPIO I/O range disabled\n");
return -ENODEV;
}
base_addr = (unsigned short)base_addr_cfg;
if (base_addr == 0) {
dev_err(&dev->dev, "I/O space for GPIO uninitialized\n");
return -ENODEV;
}
gpio_sch_resource.start = base_addr;
if (id->device == PCI_DEVICE_ID_INTEL_CENTERTON_ILB)
gpio_sch_resource.end = base_addr + GPIO_IO_SIZE_CENTERTON - 1;
else
gpio_sch_resource.end = base_addr + GPIO_IO_SIZE - 1;
for (i=0; i < ARRAY_SIZE(lpc_sch_cells); i++)
lpc_sch_cells[i].id = id->device;
ret = mfd_add_devices(&dev->dev, 0,
lpc_sch_cells, ARRAY_SIZE(lpc_sch_cells), NULL,
0, NULL);
if (ret)
goto out_dev;
if (id->device == PCI_DEVICE_ID_INTEL_ITC_LPC
|| id->device == PCI_DEVICE_ID_INTEL_CENTERTON_ILB) {
pci_read_config_dword(dev, WDTBASE, &base_addr_cfg);
if (!(base_addr_cfg & (1 << 31))) {
dev_err(&dev->dev, "Decode of the WDT I/O range disabled\n");
ret = -ENODEV;
goto out_dev;
}
base_addr = (unsigned short)base_addr_cfg;
if (base_addr == 0) {
dev_err(&dev->dev, "I/O space for WDT uninitialized\n");
ret = -ENODEV;
goto out_dev;
}
wdt_sch_resource.start = base_addr;
wdt_sch_resource.end = base_addr + WDT_IO_SIZE - 1;
for (i = 0; i < ARRAY_SIZE(tunnelcreek_cells); i++)
tunnelcreek_cells[i].id = id->device;
ret = mfd_add_devices(&dev->dev, 0, tunnelcreek_cells,
ARRAY_SIZE(tunnelcreek_cells), NULL,
0, NULL);
}
return ret;
out_dev:
mfd_remove_devices(&dev->dev);
return ret;
}
static void __devexit lpc_sch_remove(struct pci_dev *dev)
{
mfd_remove_devices(&dev->dev);
}
