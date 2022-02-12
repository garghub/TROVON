void __init ixdpg425_pci_preinit(void)
{
irq_set_irq_type(IRQ_IXP4XX_GPIO6, IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(IRQ_IXP4XX_GPIO7, IRQ_TYPE_LEVEL_LOW);
ixp4xx_pci_preinit();
}
static int __init ixdpg425_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
if (slot == 12 || slot == 13)
return IRQ_IXP4XX_GPIO7;
else if (slot == 14)
return IRQ_IXP4XX_GPIO6;
else return -1;
}
int __init ixdpg425_pci_init(void)
{
if (machine_is_ixdpg425())
pci_common_init(&ixdpg425_pci);
return 0;
}
