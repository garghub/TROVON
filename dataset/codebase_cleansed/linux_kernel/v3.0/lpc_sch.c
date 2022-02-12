static int __devinit lpc_sch_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
unsigned int base_addr_cfg;
unsigned short base_addr;
int i;
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
gpio_sch_resource.end = base_addr + GPIO_IO_SIZE - 1;
for (i=0; i < ARRAY_SIZE(lpc_sch_cells); i++)
lpc_sch_cells[i].id = id->device;
return mfd_add_devices(&dev->dev, 0,
lpc_sch_cells, ARRAY_SIZE(lpc_sch_cells), NULL, 0);
}
static void __devexit lpc_sch_remove(struct pci_dev *dev)
{
mfd_remove_devices(&dev->dev);
}
static int __init lpc_sch_init(void)
{
return pci_register_driver(&lpc_sch_driver);
}
static void __exit lpc_sch_exit(void)
{
pci_unregister_driver(&lpc_sch_driver);
}
