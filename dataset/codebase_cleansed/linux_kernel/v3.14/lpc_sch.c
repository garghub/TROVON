static int lpc_sch_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
unsigned int base_addr_cfg;
unsigned short base_addr;
int i, cells = 0;
int ret;
pci_read_config_dword(dev, SMBASE, &base_addr_cfg);
base_addr = 0;
if (!(base_addr_cfg & (1 << 31)))
dev_warn(&dev->dev, "Decode of the SMBus I/O range disabled\n");
else
base_addr = (unsigned short)base_addr_cfg;
if (base_addr == 0) {
dev_warn(&dev->dev, "I/O space for SMBus uninitialized\n");
} else {
lpc_sch_cells[cells++] = isch_smbus_cell;
smbus_sch_resource.start = base_addr;
smbus_sch_resource.end = base_addr + SMBUS_IO_SIZE - 1;
}
pci_read_config_dword(dev, GPIOBASE, &base_addr_cfg);
base_addr = 0;
if (!(base_addr_cfg & (1 << 31)))
dev_warn(&dev->dev, "Decode of the GPIO I/O range disabled\n");
else
base_addr = (unsigned short)base_addr_cfg;
if (base_addr == 0) {
dev_warn(&dev->dev, "I/O space for GPIO uninitialized\n");
} else {
lpc_sch_cells[cells++] = sch_gpio_cell;
gpio_sch_resource.start = base_addr;
if (id->device == PCI_DEVICE_ID_INTEL_CENTERTON_ILB)
gpio_sch_resource.end = base_addr + GPIO_IO_SIZE_CENTERTON - 1;
else
gpio_sch_resource.end = base_addr + GPIO_IO_SIZE - 1;
}
if (id->device == PCI_DEVICE_ID_INTEL_ITC_LPC
|| id->device == PCI_DEVICE_ID_INTEL_CENTERTON_ILB) {
pci_read_config_dword(dev, WDTBASE, &base_addr_cfg);
base_addr = 0;
if (!(base_addr_cfg & (1 << 31)))
dev_warn(&dev->dev, "Decode of the WDT I/O range disabled\n");
else
base_addr = (unsigned short)base_addr_cfg;
if (base_addr == 0)
dev_warn(&dev->dev, "I/O space for WDT uninitialized\n");
else {
lpc_sch_cells[cells++] = wdt_sch_cell;
wdt_sch_resource.start = base_addr;
wdt_sch_resource.end = base_addr + WDT_IO_SIZE - 1;
}
}
if (WARN_ON(cells > ARRAY_SIZE(lpc_sch_cells))) {
dev_err(&dev->dev, "Cell count exceeds array size");
return -ENODEV;
}
if (cells == 0) {
dev_err(&dev->dev, "All decode registers disabled.\n");
return -ENODEV;
}
for (i = 0; i < cells; i++)
lpc_sch_cells[i].id = id->device;
ret = mfd_add_devices(&dev->dev, 0, lpc_sch_cells, cells, NULL, 0, NULL);
if (ret)
mfd_remove_devices(&dev->dev);
return ret;
}
static void lpc_sch_remove(struct pci_dev *dev)
{
mfd_remove_devices(&dev->dev);
}
