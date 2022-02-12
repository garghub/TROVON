void __init coyote_pci_preinit(void)
{
irq_set_irq_type(IXP4XX_GPIO_IRQ(SLOT0_INTA), IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(IXP4XX_GPIO_IRQ(SLOT1_INTA), IRQ_TYPE_LEVEL_LOW);
ixp4xx_pci_preinit();
}
static int __init coyote_map_irq(struct pci_dev *dev, u8 slot, u8 pin)
{
if (slot == SLOT0_DEVID)
return IXP4XX_GPIO_IRQ(SLOT0_INTA);
else if (slot == SLOT1_DEVID)
return IXP4XX_GPIO_IRQ(SLOT1_INTA);
else return -1;
}
int __init coyote_pci_init(void)
{
if (machine_is_adi_coyote())
pci_common_init(&coyote_pci);
return 0;
}
