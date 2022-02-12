void __init gtwx5715_pci_preinit(void)
{
irq_set_irq_type(IXP4XX_GPIO_IRQ(INTA), IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(IXP4XX_GPIO_IRQ(INTB), IRQ_TYPE_LEVEL_LOW);
ixp4xx_pci_preinit();
}
static int __init gtwx5715_map_irq(struct pci_dev *dev, u8 slot, u8 pin)
{
int rc = -1;
if ((slot == SLOT0_DEVID && pin == 1) ||
(slot == SLOT1_DEVID && pin == 2))
rc = IXP4XX_GPIO_IRQ(INTA);
else if ((slot == SLOT0_DEVID && pin == 2) ||
(slot == SLOT1_DEVID && pin == 1))
rc = IXP4XX_GPIO_IRQ(INTB);
printk(KERN_INFO "%s: Mapped slot %d pin %d to IRQ %d\n",
__func__, slot, pin, rc);
return rc;
}
int __init gtwx5715_pci_init(void)
{
if (machine_is_gtwx5715())
pci_common_init(&gtwx5715_pci);
return 0;
}
