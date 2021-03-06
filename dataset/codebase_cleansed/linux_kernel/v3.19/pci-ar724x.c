static inline bool ar724x_pci_check_link(struct ar724x_pci_controller *apc)
{
u32 reset;
reset = __raw_readl(apc->ctrl_base + AR724X_PCI_REG_RESET);
return reset & AR724X_PCI_RESET_LINK_UP;
}
static inline struct ar724x_pci_controller *
pci_bus_to_ar724x_controller(struct pci_bus *bus)
{
struct pci_controller *hose;
hose = (struct pci_controller *) bus->sysdata;
return container_of(hose, struct ar724x_pci_controller, pci_controller);
}
static int ar724x_pci_local_write(struct ar724x_pci_controller *apc,
int where, int size, u32 value)
{
void __iomem *base;
u32 data;
int s;
WARN_ON(where & (size - 1));
if (!apc->link_up)
return PCIBIOS_DEVICE_NOT_FOUND;
base = apc->crp_base;
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
return PCIBIOS_BAD_REGISTER_NUMBER;
}
__raw_writel(data, base + (where & ~3));
__raw_readl(base + (where & ~3));
return PCIBIOS_SUCCESSFUL;
}
static int ar724x_pci_read(struct pci_bus *bus, unsigned int devfn, int where,
int size, uint32_t *value)
{
struct ar724x_pci_controller *apc;
void __iomem *base;
u32 data;
apc = pci_bus_to_ar724x_controller(bus);
if (!apc->link_up)
return PCIBIOS_DEVICE_NOT_FOUND;
if (devfn)
return PCIBIOS_DEVICE_NOT_FOUND;
base = apc->devcfg_base;
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
return PCIBIOS_BAD_REGISTER_NUMBER;
}
if (where == PCI_BASE_ADDRESS_0 && size == 4 &&
apc->bar0_is_cached) {
*value = apc->bar0_value;
} else {
*value = data;
}
return PCIBIOS_SUCCESSFUL;
}
static int ar724x_pci_write(struct pci_bus *bus, unsigned int devfn, int where,
int size, uint32_t value)
{
struct ar724x_pci_controller *apc;
void __iomem *base;
u32 data;
int s;
apc = pci_bus_to_ar724x_controller(bus);
if (!apc->link_up)
return PCIBIOS_DEVICE_NOT_FOUND;
if (devfn)
return PCIBIOS_DEVICE_NOT_FOUND;
if (soc_is_ar7240() && where == PCI_BASE_ADDRESS_0 && size == 4) {
if (value != 0xffffffff) {
apc->bar0_is_cached = true;
apc->bar0_value = value;
value = AR7240_BAR0_WAR_VALUE;
} else {
apc->bar0_is_cached = false;
}
}
base = apc->devcfg_base;
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
return PCIBIOS_BAD_REGISTER_NUMBER;
}
__raw_writel(data, base + (where & ~3));
__raw_readl(base + (where & ~3));
return PCIBIOS_SUCCESSFUL;
}
static void ar724x_pci_irq_handler(unsigned int irq, struct irq_desc *desc)
{
struct ar724x_pci_controller *apc;
void __iomem *base;
u32 pending;
apc = irq_get_handler_data(irq);
base = apc->ctrl_base;
pending = __raw_readl(base + AR724X_PCI_REG_INT_STATUS) &
__raw_readl(base + AR724X_PCI_REG_INT_MASK);
if (pending & AR724X_PCI_INT_DEV0)
generic_handle_irq(apc->irq_base + 0);
else
spurious_interrupt();
}
static void ar724x_pci_irq_unmask(struct irq_data *d)
{
struct ar724x_pci_controller *apc;
void __iomem *base;
int offset;
u32 t;
apc = irq_data_get_irq_chip_data(d);
base = apc->ctrl_base;
offset = apc->irq_base - d->irq;
switch (offset) {
case 0:
t = __raw_readl(base + AR724X_PCI_REG_INT_MASK);
__raw_writel(t | AR724X_PCI_INT_DEV0,
base + AR724X_PCI_REG_INT_MASK);
__raw_readl(base + AR724X_PCI_REG_INT_MASK);
}
}
static void ar724x_pci_irq_mask(struct irq_data *d)
{
struct ar724x_pci_controller *apc;
void __iomem *base;
int offset;
u32 t;
apc = irq_data_get_irq_chip_data(d);
base = apc->ctrl_base;
offset = apc->irq_base - d->irq;
switch (offset) {
case 0:
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
static void ar724x_pci_irq_init(struct ar724x_pci_controller *apc,
int id)
{
void __iomem *base;
int i;
base = apc->ctrl_base;
__raw_writel(0, base + AR724X_PCI_REG_INT_MASK);
__raw_writel(0, base + AR724X_PCI_REG_INT_STATUS);
apc->irq_base = ATH79_PCI_IRQ_BASE + (id * AR724X_PCI_IRQ_COUNT);
for (i = apc->irq_base;
i < apc->irq_base + AR724X_PCI_IRQ_COUNT; i++) {
irq_set_chip_and_handler(i, &ar724x_pci_irq_chip,
handle_level_irq);
irq_set_chip_data(i, apc);
}
irq_set_handler_data(apc->irq, apc);
irq_set_chained_handler(apc->irq, ar724x_pci_irq_handler);
}
static int ar724x_pci_probe(struct platform_device *pdev)
{
struct ar724x_pci_controller *apc;
struct resource *res;
int id;
id = pdev->id;
if (id == -1)
id = 0;
apc = devm_kzalloc(&pdev->dev, sizeof(struct ar724x_pci_controller),
GFP_KERNEL);
if (!apc)
return -ENOMEM;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "ctrl_base");
apc->ctrl_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(apc->ctrl_base))
return PTR_ERR(apc->ctrl_base);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "cfg_base");
apc->devcfg_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(apc->devcfg_base))
return PTR_ERR(apc->devcfg_base);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "crp_base");
apc->crp_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(apc->crp_base))
return PTR_ERR(apc->crp_base);
apc->irq = platform_get_irq(pdev, 0);
if (apc->irq < 0)
return -EINVAL;
res = platform_get_resource_byname(pdev, IORESOURCE_IO, "io_base");
if (!res)
return -EINVAL;
apc->io_res.parent = res;
apc->io_res.name = "PCI IO space";
apc->io_res.start = res->start;
apc->io_res.end = res->end;
apc->io_res.flags = IORESOURCE_IO;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "mem_base");
if (!res)
return -EINVAL;
apc->mem_res.parent = res;
apc->mem_res.name = "PCI memory space";
apc->mem_res.start = res->start;
apc->mem_res.end = res->end;
apc->mem_res.flags = IORESOURCE_MEM;
apc->pci_controller.pci_ops = &ar724x_pci_ops;
apc->pci_controller.io_resource = &apc->io_res;
apc->pci_controller.mem_resource = &apc->mem_res;
apc->link_up = ar724x_pci_check_link(apc);
if (!apc->link_up)
dev_warn(&pdev->dev, "PCIe link is down\n");
ar724x_pci_irq_init(apc, id);
ar724x_pci_local_write(apc, PCI_COMMAND, 4, AR724X_PCI_CMD_INIT);
register_pci_controller(&apc->pci_controller);
return 0;
}
static int __init ar724x_pci_init(void)
{
return platform_driver_register(&ar724x_pci_driver);
}
