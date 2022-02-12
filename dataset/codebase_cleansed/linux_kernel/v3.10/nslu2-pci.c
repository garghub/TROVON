void __init nslu2_pci_preinit(void)
{
irq_set_irq_type(IXP4XX_GPIO_IRQ(INTA), IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(IXP4XX_GPIO_IRQ(INTB), IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(IXP4XX_GPIO_IRQ(INTC), IRQ_TYPE_LEVEL_LOW);
ixp4xx_pci_preinit();
}
static int __init nslu2_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
static int pci_irq_table[IRQ_LINES] = {
IXP4XX_GPIO_IRQ(INTA),
IXP4XX_GPIO_IRQ(INTB),
IXP4XX_GPIO_IRQ(INTC),
};
if (slot >= 1 && slot <= MAX_DEV && pin >= 1 && pin <= IRQ_LINES)
return pci_irq_table[(slot + pin - 2) % IRQ_LINES];
return -1;
}
int __init nslu2_pci_init(void)
{
if (machine_is_nslu2())
pci_common_init(&nslu2_pci);
return 0;
}
