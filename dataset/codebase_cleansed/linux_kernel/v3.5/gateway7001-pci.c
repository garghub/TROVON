void __init gateway7001_pci_preinit(void)
{
irq_set_irq_type(IRQ_IXP4XX_GPIO10, IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(IRQ_IXP4XX_GPIO11, IRQ_TYPE_LEVEL_LOW);
ixp4xx_pci_preinit();
}
static int __init gateway7001_map_irq(const struct pci_dev *dev, u8 slot,
u8 pin)
{
if (slot == 1)
return IRQ_IXP4XX_GPIO11;
else if (slot == 2)
return IRQ_IXP4XX_GPIO10;
else return -1;
}
int __init gateway7001_pci_init(void)
{
if (machine_is_gateway7001())
pci_common_init(&gateway7001_pci);
return 0;
}
