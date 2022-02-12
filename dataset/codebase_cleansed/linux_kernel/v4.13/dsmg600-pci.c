void __init dsmg600_pci_preinit(void)
{
irq_set_irq_type(IXP4XX_GPIO_IRQ(INTA), IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(IXP4XX_GPIO_IRQ(INTB), IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(IXP4XX_GPIO_IRQ(INTC), IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(IXP4XX_GPIO_IRQ(INTD), IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(IXP4XX_GPIO_IRQ(INTE), IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(IXP4XX_GPIO_IRQ(INTF), IRQ_TYPE_LEVEL_LOW);
ixp4xx_pci_preinit();
}
static int __init dsmg600_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
static int pci_irq_table[MAX_DEV][IRQ_LINES] = {
{ IXP4XX_GPIO_IRQ(INTE), -1, -1 },
{ IXP4XX_GPIO_IRQ(INTA), -1, -1 },
{ IXP4XX_GPIO_IRQ(INTB), IXP4XX_GPIO_IRQ(INTC),
IXP4XX_GPIO_IRQ(INTD) },
{ IXP4XX_GPIO_IRQ(INTF), -1, -1 },
};
if (slot >= 1 && slot <= MAX_DEV && pin >= 1 && pin <= IRQ_LINES)
return pci_irq_table[slot - 1][pin - 1];
return -1;
}
int __init dsmg600_pci_init(void)
{
if (machine_is_dsmg600())
pci_common_init(&dsmg600_pci);
return 0;
}
