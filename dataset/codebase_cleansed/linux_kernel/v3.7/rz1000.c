static int __devinit rz1000_disable_readahead(struct pci_dev *dev)
{
u16 reg;
if (!pci_read_config_word (dev, 0x40, &reg) &&
!pci_write_config_word(dev, 0x40, reg & 0xdfff)) {
printk(KERN_INFO "%s: disabled chipset read-ahead "
"(buggy RZ1000/RZ1001)\n", pci_name(dev));
return 0;
} else {
printk(KERN_INFO "%s: serialized, disabled unmasking "
"(buggy RZ1000/RZ1001)\n", pci_name(dev));
return 1;
}
}
static int __devinit rz1000_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
struct ide_port_info d = rz1000_chipset;
int rc;
rc = pci_enable_device(dev);
if (rc)
return rc;
if (rz1000_disable_readahead(dev)) {
d.host_flags |= IDE_HFLAG_SERIALIZE;
d.host_flags |= IDE_HFLAG_NO_UNMASK_IRQS;
}
return ide_pci_init_one(dev, &d, NULL);
}
static void rz1000_remove(struct pci_dev *dev)
{
ide_pci_remove(dev);
pci_disable_device(dev);
}
static int __init rz1000_ide_init(void)
{
return ide_pci_register_driver(&rz1000_pci_driver);
}
static void __exit rz1000_ide_exit(void)
{
pci_unregister_driver(&rz1000_pci_driver);
}
