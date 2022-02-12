void __init vulcan_pci_preinit(void)
{
#ifndef CONFIG_IXP4XX_INDIRECT_PCI
pci_cardbus_mem_size = SZ_8M;
pr_info("Vulcan PCI: limiting CardBus memory size to %dMB\n",
(int)(pci_cardbus_mem_size >> 20));
#endif
irq_set_irq_type(IXP4XX_GPIO_IRQ(INTA), IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(IXP4XX_GPIO_IRQ(INTB), IRQ_TYPE_LEVEL_LOW);
ixp4xx_pci_preinit();
}
static int __init vulcan_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
if (slot == 1)
return IXP4XX_GPIO_IRQ(INTA);
if (slot == 2)
return IXP4XX_GPIO_IRQ(INTB);
return -1;
}
int __init vulcan_pci_init(void)
{
if (machine_is_arcom_vulcan())
pci_common_init(&vulcan_pci);
return 0;
}
