static int dsm320_pci_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
switch (slot) {
case 0:
return KS8695_IRQ_EXTERN0;
case 18:
return KS8695_IRQ_EXTERN2;
case 20:
return KS8695_IRQ_EXTERN0;
}
BUG();
}
static void __init dsm320_register_pci(void)
{
ks8695_gpio_interrupt(KS8695_GPIO_0, IRQ_TYPE_LEVEL_LOW);
ks8695_gpio_interrupt(KS8695_GPIO_2, IRQ_TYPE_LEVEL_LOW);
ks8695_init_pci(&dsm320_pci);
}
static inline void __init dsm320_register_pci(void) { }
void __init dsm320_register_nor(void)
{
int ret;
ret = platform_device_register(&dsm320_device_nor);
if (ret < 0)
printk(KERN_ERR "failed to register physmap-flash device\n");
}
static void __init dsm320_init(void)
{
ks8695_register_gpios();
dsm320_register_pci();
ks8695_add_device_lan();
dsm320_register_nor();
}
