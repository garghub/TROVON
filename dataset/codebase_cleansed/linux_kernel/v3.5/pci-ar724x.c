static int ar724x_pci_read(struct pci_bus *bus, unsigned int devfn, int where,
int size, uint32_t *value)
{
unsigned long flags;
void __iomem *base;
u32 data;
if (devfn)
return PCIBIOS_DEVICE_NOT_FOUND;
base = ar724x_pci_devcfg_base;
spin_lock_irqsave(&ar724x_pci_lock, flags);
data = __raw_readl(base + (where & ~3));
switch (size) {
case 1:
if (where & 1)
data >>= 8;
if (where & 2)
data >>= 16;
data &= 0xff;
break;
case 2:
if (where & 2)
data >>= 16;
data &= 0xffff;
break;
case 4:
break;
default:
spin_unlock_irqrestore(&ar724x_pci_lock, flags);
return PCIBIOS_BAD_REGISTER_NUMBER;
}
spin_unlock_irqrestore(&ar724x_pci_lock, flags);
if (where == PCI_BASE_ADDRESS_0 && size == 4 &&
ar724x_pci_bar0_is_cached) {
*value = ar724x_pci_bar0_value;
} else {
*value = data;
}
return PCIBIOS_SUCCESSFUL;
}
static int ar724x_pci_write(struct pci_bus *bus, unsigned int devfn, int where,
int size, uint32_t value)
{
unsigned long flags;
void __iomem *base;
u32 data;
int s;
if (devfn)
return PCIBIOS_DEVICE_NOT_FOUND;
if (soc_is_ar7240() && where == PCI_BASE_ADDRESS_0 && size == 4) {
if (value != 0xffffffff) {
ar724x_pci_bar0_is_cached = true;
ar724x_pci_bar0_value = value;
value = AR7240_BAR0_WAR_VALUE;
} else {
ar724x_pci_bar0_is_cached = false;
}
}
base = ar724x_pci_devcfg_base;
spin_lock_irqsave(&ar724x_pci_lock, flags);
data = __raw_readl(base + (where & ~3));
switch (size) {
case 1:
s = ((where & 3) * 8);
data &= ~(0xff << s);
data |= ((value & 0xff) << s);
break;
case 2:
s = ((where & 2) * 8);
data &= ~(0xffff << s);
data |= ((value & 0xffff) << s);
break;
case 4:
data = value;
break;
default:
spin_unlock_irqrestore(&ar724x_pci_lock, flags);
return PCIBIOS_BAD_REGISTER_NUMBER;
}
__raw_writel(data, base + (where & ~3));
__raw_readl(base + (where & ~3));
spin_unlock_irqrestore(&ar724x_pci_lock, flags);
return PCIBIOS_SUCCESSFUL;
}
static void ar724x_pci_irq_handler(unsigned int irq, struct irq_desc *desc)
{
void __iomem *base;
u32 pending;
base = ar724x_pci_ctrl_base;
pending = __raw_readl(base + AR724X_PCI_REG_INT_STATUS) &
__raw_readl(base + AR724X_PCI_REG_INT_MASK);
if (pending & AR724X_PCI_INT_DEV0)
generic_handle_irq(ATH79_PCI_IRQ(0));
else
spurious_interrupt();
}
static void ar724x_pci_irq_unmask(struct irq_data *d)
{
void __iomem *base;
u32 t;
base = ar724x_pci_ctrl_base;
switch (d->irq) {
case ATH79_PCI_IRQ(0):
t = __raw_readl(base + AR724X_PCI_REG_INT_MASK);
__raw_writel(t | AR724X_PCI_INT_DEV0,
base + AR724X_PCI_REG_INT_MASK);
__raw_readl(base + AR724X_PCI_REG_INT_MASK);
}
}
static void ar724x_pci_irq_mask(struct irq_data *d)
{
void __iomem *base;
u32 t;
base = ar724x_pci_ctrl_base;
switch (d->irq) {
case ATH79_PCI_IRQ(0):
t = __raw_readl(base + AR724X_PCI_REG_INT_MASK);
__raw_writel(t & ~AR724X_PCI_INT_DEV0,
base + AR724X_PCI_REG_INT_MASK);
__raw_readl(base + AR724X_PCI_REG_INT_MASK);
t = __raw_readl(base + AR724X_PCI_REG_INT_STATUS);
__raw_writel(t | AR724X_PCI_INT_DEV0,
base + AR724X_PCI_REG_INT_STATUS);
__raw_readl(base + AR724X_PCI_REG_INT_STATUS);
}
}
static void __init ar724x_pci_irq_init(int irq)
{
void __iomem *base;
int i;
base = ar724x_pci_ctrl_base;
__raw_writel(0, base + AR724X_PCI_REG_INT_MASK);
__raw_writel(0, base + AR724X_PCI_REG_INT_STATUS);
BUILD_BUG_ON(ATH79_PCI_IRQ_COUNT < AR724X_PCI_IRQ_COUNT);
for (i = ATH79_PCI_IRQ_BASE;
i < ATH79_PCI_IRQ_BASE + AR724X_PCI_IRQ_COUNT; i++)
irq_set_chip_and_handler(i, &ar724x_pci_irq_chip,
handle_level_irq);
irq_set_chained_handler(irq, ar724x_pci_irq_handler);
}
int __init ar724x_pcibios_init(int irq)
{
int ret;
ret = -ENOMEM;
ar724x_pci_devcfg_base = ioremap(AR724X_PCI_CFG_BASE,
AR724X_PCI_CFG_SIZE);
if (ar724x_pci_devcfg_base == NULL)
goto err;
ar724x_pci_ctrl_base = ioremap(AR724X_PCI_CTRL_BASE,
AR724X_PCI_CTRL_SIZE);
if (ar724x_pci_ctrl_base == NULL)
goto err_unmap_devcfg;
ar724x_pci_irq_init(irq);
register_pci_controller(&ar724x_pci_controller);
return PCIBIOS_SUCCESSFUL;
err_unmap_devcfg:
iounmap(ar724x_pci_devcfg_base);
err:
return ret;
}
