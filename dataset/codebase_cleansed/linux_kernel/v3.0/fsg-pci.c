void __init fsg_pci_preinit(void)
{
irq_set_irq_type(IXP4XX_GPIO_IRQ(INTA), IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(IXP4XX_GPIO_IRQ(INTB), IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(IXP4XX_GPIO_IRQ(INTC), IRQ_TYPE_LEVEL_LOW);
ixp4xx_pci_preinit();
}
static int __init fsg_map_irq(struct pci_dev *dev, u8 slot, u8 pin)
{
static int pci_irq_table[IRQ_LINES] = {
IXP4XX_GPIO_IRQ(INTC),
IXP4XX_GPIO_IRQ(INTB),
IXP4XX_GPIO_IRQ(INTA),
};
int irq = -1;
slot -= 11;
if (slot >= 1 && slot <= MAX_DEV && pin >= 1 && pin <= IRQ_LINES)
irq = pci_irq_table[slot - 1];
printk(KERN_INFO "%s: Mapped slot %d pin %d to IRQ %d\n",
__func__, slot, pin, irq);
return irq;
}
int __init fsg_pci_init(void)
{
if (machine_is_fsg())
pci_common_init(&fsg_pci);
return 0;
}
