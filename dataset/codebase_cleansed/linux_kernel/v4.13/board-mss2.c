static int __init mss2_pci_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
int irq;
irq = orion5x_pci_map_irq(dev, slot, pin);
if (irq != -1)
return irq;
return -1;
}
static int __init mss2_pci_init(void)
{
if (machine_is_mss2())
pci_common_init(&mss2_pci);
return 0;
}
static void mss2_power_off(void)
{
u32 reg;
reg = readl(RSTOUTn_MASK);
reg |= 1 << 2;
writel(reg, RSTOUTn_MASK);
reg = readl(CPU_SOFT_RESET);
reg |= 1;
writel(reg, CPU_SOFT_RESET);
}
void __init mss2_init(void)
{
pm_power_off = mss2_power_off;
}
