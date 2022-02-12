void __init wg302v2_pci_preinit(void)
{
irq_set_irq_type(IRQ_IXP4XX_GPIO8, IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(IRQ_IXP4XX_GPIO9, IRQ_TYPE_LEVEL_LOW);
ixp4xx_pci_preinit();
}
static int __init wg302v2_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
if (slot == 1)
return IRQ_IXP4XX_GPIO8;
else if (slot == 2)
return IRQ_IXP4XX_GPIO9;
else return -1;
}
int __init wg302v2_pci_init(void)
{
if (machine_is_wg302v2())
pci_common_init(&wg302v2_pci);
return 0;
}
