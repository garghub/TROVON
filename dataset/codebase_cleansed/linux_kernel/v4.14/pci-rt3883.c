static inline struct rt3883_pci_controller *
pci_bus_to_rt3883_controller(struct pci_bus *bus)
{
struct pci_controller *hose;
hose = (struct pci_controller *) bus->sysdata;
return container_of(hose, struct rt3883_pci_controller, pci_controller);
}
static inline u32 rt3883_pci_r32(struct rt3883_pci_controller *rpc,
unsigned reg)
{
return ioread32(rpc->base + reg);
}
static inline void rt3883_pci_w32(struct rt3883_pci_controller *rpc,
u32 val, unsigned reg)
{
iowrite32(val, rpc->base + reg);
}
static inline u32 rt3883_pci_get_cfgaddr(unsigned int bus, unsigned int slot,
unsigned int func, unsigned int where)
{
return (bus << 16) | (slot << 11) | (func << 8) | (where & 0xfc) |
0x80000000;
}
static u32 rt3883_pci_read_cfg32(struct rt3883_pci_controller *rpc,
unsigned bus, unsigned slot,
unsigned func, unsigned reg)
{
unsigned long flags;
u32 address;
u32 ret;
address = rt3883_pci_get_cfgaddr(bus, slot, func, reg);
rt3883_pci_w32(rpc, address, RT3883_PCI_REG_CFGADDR);
ret = rt3883_pci_r32(rpc, RT3883_PCI_REG_CFGDATA);
return ret;
}
static void rt3883_pci_write_cfg32(struct rt3883_pci_controller *rpc,
unsigned bus, unsigned slot,
unsigned func, unsigned reg, u32 val)
{
unsigned long flags;
u32 address;
address = rt3883_pci_get_cfgaddr(bus, slot, func, reg);
rt3883_pci_w32(rpc, address, RT3883_PCI_REG_CFGADDR);
rt3883_pci_w32(rpc, val, RT3883_PCI_REG_CFGDATA);
}
static void rt3883_pci_irq_handler(struct irq_desc *desc)
{
struct rt3883_pci_controller *rpc;
u32 pending;
rpc = irq_desc_get_handler_data(desc);
pending = rt3883_pci_r32(rpc, RT3883_PCI_REG_PCIINT) &
rt3883_pci_r32(rpc, RT3883_PCI_REG_PCIENA);
if (!pending) {
spurious_interrupt();
return;
}
while (pending) {
unsigned irq, bit = __ffs(pending);
irq = irq_find_mapping(rpc->irq_domain, bit);
generic_handle_irq(irq);
pending &= ~BIT(bit);
}
}
static void rt3883_pci_irq_unmask(struct irq_data *d)
{
struct rt3883_pci_controller *rpc;
u32 t;
rpc = irq_data_get_irq_chip_data(d);
t = rt3883_pci_r32(rpc, RT3883_PCI_REG_PCIENA);
rt3883_pci_w32(rpc, t | BIT(d->hwirq), RT3883_PCI_REG_PCIENA);
rt3883_pci_r32(rpc, RT3883_PCI_REG_PCIENA);
}
static void rt3883_pci_irq_mask(struct irq_data *d)
{
struct rt3883_pci_controller *rpc;
u32 t;
rpc = irq_data_get_irq_chip_data(d);
t = rt3883_pci_r32(rpc, RT3883_PCI_REG_PCIENA);
rt3883_pci_w32(rpc, t & ~BIT(d->hwirq), RT3883_PCI_REG_PCIENA);
rt3883_pci_r32(rpc, RT3883_PCI_REG_PCIENA);
}
static int rt3883_pci_irq_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hw)
{
irq_set_chip_and_handler(irq, &rt3883_pci_irq_chip, handle_level_irq);
irq_set_chip_data(irq, d->host_data);
return 0;
}
static int rt3883_pci_irq_init(struct device *dev,
struct rt3883_pci_controller *rpc)
{
int irq;
irq = irq_of_parse_and_map(rpc->intc_of_node, 0);
if (irq == 0) {
dev_err(dev, "%pOF has no IRQ", rpc->intc_of_node);
return -EINVAL;
}
rt3883_pci_w32(rpc, 0, RT3883_PCI_REG_PCIENA);
rpc->irq_domain =
irq_domain_add_linear(rpc->intc_of_node, RT3883_PCI_IRQ_COUNT,
&rt3883_pci_irq_domain_ops,
rpc);
if (!rpc->irq_domain) {
dev_err(dev, "unable to add IRQ domain\n");
return -ENODEV;
}
irq_set_chained_handler_and_data(irq, rt3883_pci_irq_handler, rpc);
return 0;
}
static int rt3883_pci_config_read(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 *val)
{
struct rt3883_pci_controller *rpc;
unsigned long flags;
u32 address;
u32 data;
rpc = pci_bus_to_rt3883_controller(bus);
if (!rpc->pcie_ready && bus->number == 1)
return PCIBIOS_DEVICE_NOT_FOUND;
address = rt3883_pci_get_cfgaddr(bus->number, PCI_SLOT(devfn),
PCI_FUNC(devfn), where);
rt3883_pci_w32(rpc, address, RT3883_PCI_REG_CFGADDR);
data = rt3883_pci_r32(rpc, RT3883_PCI_REG_CFGDATA);
switch (size) {
case 1:
*val = (data >> ((where & 3) << 3)) & 0xff;
break;
case 2:
*val = (data >> ((where & 3) << 3)) & 0xffff;
break;
case 4:
*val = data;
break;
}
return PCIBIOS_SUCCESSFUL;
}
static int rt3883_pci_config_write(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 val)
{
struct rt3883_pci_controller *rpc;
unsigned long flags;
u32 address;
u32 data;
rpc = pci_bus_to_rt3883_controller(bus);
if (!rpc->pcie_ready && bus->number == 1)
return PCIBIOS_DEVICE_NOT_FOUND;
address = rt3883_pci_get_cfgaddr(bus->number, PCI_SLOT(devfn),
PCI_FUNC(devfn), where);
rt3883_pci_w32(rpc, address, RT3883_PCI_REG_CFGADDR);
data = rt3883_pci_r32(rpc, RT3883_PCI_REG_CFGDATA);
switch (size) {
case 1:
data = (data & ~(0xff << ((where & 3) << 3))) |
(val << ((where & 3) << 3));
break;
case 2:
data = (data & ~(0xffff << ((where & 3) << 3))) |
(val << ((where & 3) << 3));
break;
case 4:
data = val;
break;
}
rt3883_pci_w32(rpc, data, RT3883_PCI_REG_CFGDATA);
return PCIBIOS_SUCCESSFUL;
}
static void rt3883_pci_preinit(struct rt3883_pci_controller *rpc, unsigned mode)
{
u32 syscfg1;
u32 rstctrl;
u32 clkcfg1;
u32 t;
rstctrl = rt_sysc_r32(RT3883_SYSC_REG_RSTCTRL);
syscfg1 = rt_sysc_r32(RT3883_SYSC_REG_SYSCFG1);
clkcfg1 = rt_sysc_r32(RT3883_SYSC_REG_CLKCFG1);
if (mode & RT3883_PCI_MODE_PCIE) {
rstctrl |= RT3883_RSTCTRL_PCIE;
rt_sysc_w32(rstctrl, RT3883_SYSC_REG_RSTCTRL);
syscfg1 &= ~(0x30);
syscfg1 |= (2 << 4);
rt_sysc_w32(syscfg1, RT3883_SYSC_REG_SYSCFG1);
t = rt_sysc_r32(RT3883_SYSC_REG_PCIE_CLK_GEN0);
t &= ~BIT(31);
rt_sysc_w32(t, RT3883_SYSC_REG_PCIE_CLK_GEN0);
t = rt_sysc_r32(RT3883_SYSC_REG_PCIE_CLK_GEN1);
t &= 0x80ffffff;
rt_sysc_w32(t, RT3883_SYSC_REG_PCIE_CLK_GEN1);
t = rt_sysc_r32(RT3883_SYSC_REG_PCIE_CLK_GEN1);
t |= 0xa << 24;
rt_sysc_w32(t, RT3883_SYSC_REG_PCIE_CLK_GEN1);
t = rt_sysc_r32(RT3883_SYSC_REG_PCIE_CLK_GEN0);
t |= BIT(31);
rt_sysc_w32(t, RT3883_SYSC_REG_PCIE_CLK_GEN0);
msleep(50);
rstctrl &= ~RT3883_RSTCTRL_PCIE;
rt_sysc_w32(rstctrl, RT3883_SYSC_REG_RSTCTRL);
}
syscfg1 |= (RT3883_SYSCFG1_PCIE_RC_MODE | RT3883_SYSCFG1_PCI_HOST_MODE);
clkcfg1 &= ~(RT3883_CLKCFG1_PCI_CLK_EN | RT3883_CLKCFG1_PCIE_CLK_EN);
if (mode & RT3883_PCI_MODE_PCI) {
clkcfg1 |= RT3883_CLKCFG1_PCI_CLK_EN;
rstctrl &= ~RT3883_RSTCTRL_PCI;
}
if (mode & RT3883_PCI_MODE_PCIE) {
clkcfg1 |= RT3883_CLKCFG1_PCIE_CLK_EN;
rstctrl &= ~RT3883_RSTCTRL_PCIE;
}
rt_sysc_w32(syscfg1, RT3883_SYSC_REG_SYSCFG1);
rt_sysc_w32(rstctrl, RT3883_SYSC_REG_RSTCTRL);
rt_sysc_w32(clkcfg1, RT3883_SYSC_REG_CLKCFG1);
msleep(500);
t = (RT3883_P2P_BR_DEVNUM << RT3883_PCICFG_P2P_BR_DEVNUM_S);
rt3883_pci_w32(rpc, t, RT3883_PCI_REG_PCICFG);
rt3883_pci_r32(rpc, RT3883_PCI_REG_PCICFG);
msleep(500);
if (mode & RT3883_PCI_MODE_PCIE) {
msleep(500);
t = rt3883_pci_r32(rpc, RT3883_PCI_REG_STATUS(1));
rpc->pcie_ready = t & BIT(0);
if (!rpc->pcie_ready) {
t = rt_sysc_r32(RT3883_SYSC_REG_RSTCTRL);
t |= RT3883_RSTCTRL_PCIE;
rt_sysc_w32(t, RT3883_SYSC_REG_RSTCTRL);
t &= ~RT3883_RSTCTRL_PCIE;
rt_sysc_w32(t, RT3883_SYSC_REG_RSTCTRL);
t = rt_sysc_r32(RT3883_SYSC_REG_CLKCFG1);
t &= ~RT3883_CLKCFG1_PCIE_CLK_EN;
rt_sysc_w32(t, RT3883_SYSC_REG_CLKCFG1);
t = rt_sysc_r32(RT3883_SYSC_REG_PCIE_CLK_GEN0);
t &= ~0xf000c080;
rt_sysc_w32(t, RT3883_SYSC_REG_PCIE_CLK_GEN0);
}
}
rt3883_pci_w32(rpc, 0x79, RT3883_PCI_REG_ARBCTL);
}
static int rt3883_pci_probe(struct platform_device *pdev)
{
struct rt3883_pci_controller *rpc;
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct resource *res;
struct device_node *child;
u32 val;
int err;
int mode;
rpc = devm_kzalloc(dev, sizeof(*rpc), GFP_KERNEL);
if (!rpc)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
rpc->base = devm_ioremap_resource(dev, res);
if (IS_ERR(rpc->base))
return PTR_ERR(rpc->base);
for_each_child_of_node(np, child) {
if (of_get_property(child, "interrupt-controller", NULL)) {
rpc->intc_of_node = child;
break;
}
}
if (!rpc->intc_of_node) {
dev_err(dev, "%pOF has no %s child node",
rpc->intc_of_node,
"interrupt controller");
return -EINVAL;
}
for_each_child_of_node(np, child) {
if (child->type &&
of_node_cmp(child->type, "pci") == 0) {
rpc->pci_controller.of_node = child;
break;
}
}
if (!rpc->pci_controller.of_node) {
dev_err(dev, "%pOF has no %s child node",
rpc->intc_of_node,
"PCI host bridge");
err = -EINVAL;
goto err_put_intc_node;
}
mode = RT3883_PCI_MODE_NONE;
for_each_available_child_of_node(rpc->pci_controller.of_node, child) {
int devfn;
if (!child->type ||
of_node_cmp(child->type, "pci") != 0)
continue;
devfn = of_pci_get_devfn(child);
if (devfn < 0)
continue;
switch (PCI_SLOT(devfn)) {
case 1:
mode |= RT3883_PCI_MODE_PCIE;
break;
case 17:
case 18:
mode |= RT3883_PCI_MODE_PCI;
break;
}
}
if (mode == RT3883_PCI_MODE_NONE) {
dev_err(dev, "unable to determine PCI mode\n");
err = -EINVAL;
goto err_put_hb_node;
}
dev_info(dev, "mode:%s%s\n",
(mode & RT3883_PCI_MODE_PCI) ? " PCI" : "",
(mode & RT3883_PCI_MODE_PCIE) ? " PCIe" : "");
rt3883_pci_preinit(rpc, mode);
rpc->pci_controller.pci_ops = &rt3883_pci_ops;
rpc->pci_controller.io_resource = &rpc->io_res;
rpc->pci_controller.mem_resource = &rpc->mem_res;
pci_load_of_ranges(&rpc->pci_controller,
rpc->pci_controller.of_node);
rt3883_pci_w32(rpc, rpc->mem_res.start, RT3883_PCI_REG_MEMBASE);
rt3883_pci_w32(rpc, rpc->io_res.start, RT3883_PCI_REG_IOBASE);
ioport_resource.start = rpc->io_res.start;
ioport_resource.end = rpc->io_res.end;
rt3883_pci_w32(rpc, 0x03ff0000, RT3883_PCI_REG_BAR0SETUP(0));
rt3883_pci_w32(rpc, RT3883_MEMORY_BASE, RT3883_PCI_REG_IMBASEBAR0(0));
rt3883_pci_w32(rpc, 0x08021814, RT3883_PCI_REG_ID(0));
rt3883_pci_w32(rpc, 0x00800001, RT3883_PCI_REG_CLASS(0));
rt3883_pci_w32(rpc, 0x28801814, RT3883_PCI_REG_SUBID(0));
rt3883_pci_w32(rpc, 0x03ff0000, RT3883_PCI_REG_BAR0SETUP(1));
rt3883_pci_w32(rpc, RT3883_MEMORY_BASE, RT3883_PCI_REG_IMBASEBAR0(1));
rt3883_pci_w32(rpc, 0x08021814, RT3883_PCI_REG_ID(1));
rt3883_pci_w32(rpc, 0x06040001, RT3883_PCI_REG_CLASS(1));
rt3883_pci_w32(rpc, 0x28801814, RT3883_PCI_REG_SUBID(1));
err = rt3883_pci_irq_init(dev, rpc);
if (err)
goto err_put_hb_node;
val = rt3883_pci_read_cfg32(rpc, 0, 0x01, 0, PCI_COMMAND);
val |= PCI_COMMAND_IO | PCI_COMMAND_MEMORY | PCI_COMMAND_MASTER;
rt3883_pci_write_cfg32(rpc, 0, 0x01, 0, PCI_COMMAND, val);
val = rt3883_pci_read_cfg32(rpc, 0, 0x00, 0, PCI_COMMAND);
val |= PCI_COMMAND_IO | PCI_COMMAND_MEMORY | PCI_COMMAND_MASTER;
rt3883_pci_write_cfg32(rpc, 0, 0x00, 0, PCI_COMMAND, val);
if (mode == RT3883_PCI_MODE_PCIE) {
rt3883_pci_w32(rpc, 0x03ff0001, RT3883_PCI_REG_BAR0SETUP(0));
rt3883_pci_w32(rpc, 0x03ff0001, RT3883_PCI_REG_BAR0SETUP(1));
rt3883_pci_write_cfg32(rpc, 0, RT3883_P2P_BR_DEVNUM, 0,
PCI_BASE_ADDRESS_0,
RT3883_MEMORY_BASE);
rt3883_pci_read_cfg32(rpc, 0, RT3883_P2P_BR_DEVNUM, 0,
PCI_BASE_ADDRESS_0);
} else {
rt3883_pci_write_cfg32(rpc, 0, RT3883_P2P_BR_DEVNUM, 0,
PCI_IO_BASE, 0x00000101);
}
register_pci_controller(&rpc->pci_controller);
return 0;
err_put_hb_node:
of_node_put(rpc->pci_controller.of_node);
err_put_intc_node:
of_node_put(rpc->intc_of_node);
return err;
}
int pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
return of_irq_parse_and_map_pci(dev, slot, pin);
}
int pcibios_plat_dev_init(struct pci_dev *dev)
{
return 0;
}
static int __init rt3883_pci_init(void)
{
return platform_driver_register(&rt3883_pci_driver);
}
