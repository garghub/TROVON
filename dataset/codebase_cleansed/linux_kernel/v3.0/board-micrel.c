static int micrel_pci_map_irq(struct pci_dev *dev, u8 slot, u8 pin)
{
return KS8695_IRQ_EXTERN0;
}
static void __init micrel_init(void)
{
printk(KERN_INFO "Micrel KS8695 Development Board initializing\n");
ks8695_register_gpios();
#ifdef CONFIG_PCI
ks8695_init_pci(&micrel_pci);
#endif
ks8695_add_device_wan();
ks8695_add_device_lan();
}
