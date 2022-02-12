void __init nas100d_pci_preinit(void)
{
irq_set_irq_type(IXP4XX_GPIO_IRQ(INTA), IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(IXP4XX_GPIO_IRQ(INTB), IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(IXP4XX_GPIO_IRQ(INTC), IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(IXP4XX_GPIO_IRQ(INTD), IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(IXP4XX_GPIO_IRQ(INTE), IRQ_TYPE_LEVEL_LOW);
ixp4xx_pci_preinit();
}
static int __init nas100d_map_irq(struct pci_dev *dev, u8 slot, u8 pin)
{
static int pci_irq_table[MAX_DEV][IRQ_LINES] = {
{ IXP4XX_GPIO_IRQ(INTA), -1, -1 },
{ IXP4XX_GPIO_IRQ(INTB), -1, -1 },
{ IXP4XX_GPIO_IRQ(INTC), IXP4XX_GPIO_IRQ(INTD),
IXP4XX_GPIO_IRQ(INTE) },
};
if (slot >= 1 && slot <= MAX_DEV && pin >= 1 && pin <= IRQ_LINES)
return pci_irq_table[slot - 1][pin - 1];
return -1;
}
int __init nas100d_pci_init(void)
{
if (machine_is_nas100d())
pci_common_init(&nas100d_pci);
return 0;
}
