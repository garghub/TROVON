static void cmx2xx_it8152_irq_demux(unsigned int irq, struct irq_desc *desc)
{
desc->irq_data.chip->irq_ack(&desc->irq_data);
it8152_irq_demux(irq, desc);
}
void __cmx2xx_pci_init_irq(int irq_gpio)
{
it8152_init_irq();
cmx2xx_it8152_irq_gpio = irq_gpio;
irq_set_irq_type(gpio_to_irq(irq_gpio), IRQ_TYPE_EDGE_RISING);
irq_set_chained_handler(gpio_to_irq(irq_gpio),
cmx2xx_it8152_irq_demux);
}
void __cmx2xx_pci_suspend(void)
{
sleep_save_ite[0] = __raw_readl(IT8152_INTC_PDCNIMR);
sleep_save_ite[1] = __raw_readl(IT8152_INTC_LPCNIMR);
sleep_save_ite[2] = __raw_readl(IT8152_INTC_LPNIAR);
__raw_writel((0), IT8152_INTC_PDCNIRR);
__raw_writel((0), IT8152_INTC_LPCNIRR);
}
void __cmx2xx_pci_resume(void)
{
__raw_writel((sleep_save_ite[0]), IT8152_INTC_PDCNIMR);
__raw_writel((sleep_save_ite[1]), IT8152_INTC_LPCNIMR);
__raw_writel((sleep_save_ite[2]), IT8152_INTC_LPNIAR);
}
void cmx2xx_pci_suspend(void) {}
void cmx2xx_pci_resume(void) {}
static int __init cmx2xx_pci_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
int irq;
dev_dbg(&dev->dev, "%s: slot=%x, pin=%x\n", __func__, slot, pin);
irq = it8152_pci_map_irq(dev, slot, pin);
if (irq)
return irq;
if (slot == 7)
return IT8152_PCI_INTA;
if (slot == 8 || slot == 0)
return IT8152_PCI_INTB;
if (slot == 9)
return IT8152_PCI_INTA;
if (slot == 15)
return IT8152_PCI_INTC;
if (slot == 16)
return IT8152_PCI_INTA;
if ((slot == 17) || (slot == 19))
return IT8152_PCI_INTA;
if ((slot == 18) || (slot == 20))
return IT8152_PCI_INTB;
return(0);
}
static void cmx2xx_pci_preinit(void)
{
pr_info("Initializing CM-X2XX PCI subsystem\n");
pcibios_min_io = 0;
pcibios_min_mem = 0;
__raw_writel(0x800, IT8152_PCI_CFG_ADDR);
if (__raw_readl(IT8152_PCI_CFG_DATA) == 0x81521283) {
pr_info("PCI Bridge found.\n");
writel(0x848, IT8152_PCI_CFG_ADDR);
writel(0, IT8152_PCI_CFG_DATA);
writel(0x840, IT8152_PCI_CFG_ADDR);
writel(0, IT8152_PCI_CFG_DATA);
writel(0x20, IT8152_GPIO_GPDR);
writel(0x4000, IT8152_PCI_CFG_ADDR);
if (readl(IT8152_PCI_CFG_DATA) == 0xAC51104C) {
pr_info("CardBus Bridge found.\n");
writel(0x408C, IT8152_PCI_CFG_ADDR);
writel(0x1022, IT8152_PCI_CFG_DATA);
writel(0x4080, IT8152_PCI_CFG_ADDR);
writel(0x3844d060, IT8152_PCI_CFG_DATA);
writel(0x4090, IT8152_PCI_CFG_ADDR);
writel(((readl(IT8152_PCI_CFG_DATA) & 0xffff) |
0x60440000),
IT8152_PCI_CFG_DATA);
writel(0x4018, IT8152_PCI_CFG_ADDR);
writel(0xb0000000, IT8152_PCI_CFG_DATA);
writel(0x418C, IT8152_PCI_CFG_ADDR);
writel(0x1022, IT8152_PCI_CFG_DATA);
writel(0x4180, IT8152_PCI_CFG_ADDR);
writel(0x3844d060, IT8152_PCI_CFG_DATA);
writel(0x4190, IT8152_PCI_CFG_ADDR);
writel(((readl(IT8152_PCI_CFG_DATA) & 0xffff) |
0x60440000),
IT8152_PCI_CFG_DATA);
writel(0x4118, IT8152_PCI_CFG_ADDR);
writel(0xb0000000, IT8152_PCI_CFG_DATA);
}
}
}
static int __init cmx2xx_init_pci(void)
{
if (machine_is_armcore())
pci_common_init(&cmx2xx_pci);
return 0;
}
