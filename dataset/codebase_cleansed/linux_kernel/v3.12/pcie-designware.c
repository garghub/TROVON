static inline struct pcie_port *sys_to_pcie(struct pci_sys_data *sys)
{
return sys->private_data;
}
int cfg_read(void __iomem *addr, int where, int size, u32 *val)
{
*val = readl(addr);
if (size == 1)
*val = (*val >> (8 * (where & 3))) & 0xff;
else if (size == 2)
*val = (*val >> (8 * (where & 3))) & 0xffff;
else if (size != 4)
return PCIBIOS_BAD_REGISTER_NUMBER;
return PCIBIOS_SUCCESSFUL;
}
int cfg_write(void __iomem *addr, int where, int size, u32 val)
{
if (size == 4)
writel(val, addr);
else if (size == 2)
writew(val, addr + (where & 2));
else if (size == 1)
writeb(val, addr + (where & 3));
else
return PCIBIOS_BAD_REGISTER_NUMBER;
return PCIBIOS_SUCCESSFUL;
}
static inline void dw_pcie_readl_rc(struct pcie_port *pp, u32 reg, u32 *val)
{
if (pp->ops->readl_rc)
pp->ops->readl_rc(pp, pp->dbi_base + reg, val);
else
*val = readl(pp->dbi_base + reg);
}
static inline void dw_pcie_writel_rc(struct pcie_port *pp, u32 val, u32 reg)
{
if (pp->ops->writel_rc)
pp->ops->writel_rc(pp, val, pp->dbi_base + reg);
else
writel(val, pp->dbi_base + reg);
}
int dw_pcie_rd_own_conf(struct pcie_port *pp, int where, int size,
u32 *val)
{
int ret;
if (pp->ops->rd_own_conf)
ret = pp->ops->rd_own_conf(pp, where, size, val);
else
ret = cfg_read(pp->dbi_base + (where & ~0x3), where, size, val);
return ret;
}
int dw_pcie_wr_own_conf(struct pcie_port *pp, int where, int size,
u32 val)
{
int ret;
if (pp->ops->wr_own_conf)
ret = pp->ops->wr_own_conf(pp, where, size, val);
else
ret = cfg_write(pp->dbi_base + (where & ~0x3), where, size,
val);
return ret;
}
int dw_pcie_link_up(struct pcie_port *pp)
{
if (pp->ops->link_up)
return pp->ops->link_up(pp);
else
return 0;
}
int __init dw_pcie_host_init(struct pcie_port *pp)
{
struct device_node *np = pp->dev->of_node;
struct of_pci_range range;
struct of_pci_range_parser parser;
u32 val;
if (of_pci_range_parser_init(&parser, np)) {
dev_err(pp->dev, "missing ranges property\n");
return -EINVAL;
}
for_each_of_pci_range(&parser, &range) {
unsigned long restype = range.flags & IORESOURCE_TYPE_BITS;
if (restype == IORESOURCE_IO) {
of_pci_range_to_resource(&range, np, &pp->io);
pp->io.name = "I/O";
pp->io.start = max_t(resource_size_t,
PCIBIOS_MIN_IO,
range.pci_addr + global_io_offset);
pp->io.end = min_t(resource_size_t,
IO_SPACE_LIMIT,
range.pci_addr + range.size
+ global_io_offset);
pp->config.io_size = resource_size(&pp->io);
pp->config.io_bus_addr = range.pci_addr;
}
if (restype == IORESOURCE_MEM) {
of_pci_range_to_resource(&range, np, &pp->mem);
pp->mem.name = "MEM";
pp->config.mem_size = resource_size(&pp->mem);
pp->config.mem_bus_addr = range.pci_addr;
}
if (restype == 0) {
of_pci_range_to_resource(&range, np, &pp->cfg);
pp->config.cfg0_size = resource_size(&pp->cfg)/2;
pp->config.cfg1_size = resource_size(&pp->cfg)/2;
}
}
if (!pp->dbi_base) {
pp->dbi_base = devm_ioremap(pp->dev, pp->cfg.start,
resource_size(&pp->cfg));
if (!pp->dbi_base) {
dev_err(pp->dev, "error with ioremap\n");
return -ENOMEM;
}
}
pp->cfg0_base = pp->cfg.start;
pp->cfg1_base = pp->cfg.start + pp->config.cfg0_size;
pp->io_base = pp->io.start;
pp->mem_base = pp->mem.start;
pp->va_cfg0_base = devm_ioremap(pp->dev, pp->cfg0_base,
pp->config.cfg0_size);
if (!pp->va_cfg0_base) {
dev_err(pp->dev, "error with ioremap in function\n");
return -ENOMEM;
}
pp->va_cfg1_base = devm_ioremap(pp->dev, pp->cfg1_base,
pp->config.cfg1_size);
if (!pp->va_cfg1_base) {
dev_err(pp->dev, "error with ioremap\n");
return -ENOMEM;
}
if (of_property_read_u32(np, "num-lanes", &pp->lanes)) {
dev_err(pp->dev, "Failed to parse the number of lanes\n");
return -EINVAL;
}
if (pp->ops->host_init)
pp->ops->host_init(pp);
dw_pcie_wr_own_conf(pp, PCI_BASE_ADDRESS_0, 4, 0);
dw_pcie_wr_own_conf(pp, PCI_CLASS_DEVICE, 2, PCI_CLASS_BRIDGE_PCI);
dw_pcie_rd_own_conf(pp, PCIE_LINK_WIDTH_SPEED_CONTROL, 4, &val);
val |= PORT_LOGIC_SPEED_CHANGE;
dw_pcie_wr_own_conf(pp, PCIE_LINK_WIDTH_SPEED_CONTROL, 4, val);
dw_pci.nr_controllers = 1;
dw_pci.private_data = (void **)&pp;
pci_common_init(&dw_pci);
pci_assign_unassigned_resources();
#ifdef CONFIG_PCI_DOMAINS
dw_pci.domain++;
#endif
return 0;
}
static void dw_pcie_prog_viewport_cfg0(struct pcie_port *pp, u32 busdev)
{
dw_pcie_writel_rc(pp, PCIE_ATU_REGION_OUTBOUND | PCIE_ATU_REGION_INDEX0,
PCIE_ATU_VIEWPORT);
dw_pcie_writel_rc(pp, pp->cfg0_base, PCIE_ATU_LOWER_BASE);
dw_pcie_writel_rc(pp, (pp->cfg0_base >> 32), PCIE_ATU_UPPER_BASE);
dw_pcie_writel_rc(pp, pp->cfg0_base + pp->config.cfg0_size - 1,
PCIE_ATU_LIMIT);
dw_pcie_writel_rc(pp, busdev, PCIE_ATU_LOWER_TARGET);
dw_pcie_writel_rc(pp, 0, PCIE_ATU_UPPER_TARGET);
dw_pcie_writel_rc(pp, PCIE_ATU_TYPE_CFG0, PCIE_ATU_CR1);
dw_pcie_writel_rc(pp, PCIE_ATU_ENABLE, PCIE_ATU_CR2);
}
static void dw_pcie_prog_viewport_cfg1(struct pcie_port *pp, u32 busdev)
{
dw_pcie_writel_rc(pp, PCIE_ATU_REGION_OUTBOUND | PCIE_ATU_REGION_INDEX1,
PCIE_ATU_VIEWPORT);
dw_pcie_writel_rc(pp, PCIE_ATU_TYPE_CFG1, PCIE_ATU_CR1);
dw_pcie_writel_rc(pp, PCIE_ATU_ENABLE, PCIE_ATU_CR2);
dw_pcie_writel_rc(pp, pp->cfg1_base, PCIE_ATU_LOWER_BASE);
dw_pcie_writel_rc(pp, (pp->cfg1_base >> 32), PCIE_ATU_UPPER_BASE);
dw_pcie_writel_rc(pp, pp->cfg1_base + pp->config.cfg1_size - 1,
PCIE_ATU_LIMIT);
dw_pcie_writel_rc(pp, busdev, PCIE_ATU_LOWER_TARGET);
dw_pcie_writel_rc(pp, 0, PCIE_ATU_UPPER_TARGET);
}
static void dw_pcie_prog_viewport_mem_outbound(struct pcie_port *pp)
{
dw_pcie_writel_rc(pp, PCIE_ATU_REGION_OUTBOUND | PCIE_ATU_REGION_INDEX0,
PCIE_ATU_VIEWPORT);
dw_pcie_writel_rc(pp, PCIE_ATU_TYPE_MEM, PCIE_ATU_CR1);
dw_pcie_writel_rc(pp, PCIE_ATU_ENABLE, PCIE_ATU_CR2);
dw_pcie_writel_rc(pp, pp->mem_base, PCIE_ATU_LOWER_BASE);
dw_pcie_writel_rc(pp, (pp->mem_base >> 32), PCIE_ATU_UPPER_BASE);
dw_pcie_writel_rc(pp, pp->mem_base + pp->config.mem_size - 1,
PCIE_ATU_LIMIT);
dw_pcie_writel_rc(pp, pp->config.mem_bus_addr, PCIE_ATU_LOWER_TARGET);
dw_pcie_writel_rc(pp, upper_32_bits(pp->config.mem_bus_addr),
PCIE_ATU_UPPER_TARGET);
}
static void dw_pcie_prog_viewport_io_outbound(struct pcie_port *pp)
{
dw_pcie_writel_rc(pp, PCIE_ATU_REGION_OUTBOUND | PCIE_ATU_REGION_INDEX1,
PCIE_ATU_VIEWPORT);
dw_pcie_writel_rc(pp, PCIE_ATU_TYPE_IO, PCIE_ATU_CR1);
dw_pcie_writel_rc(pp, PCIE_ATU_ENABLE, PCIE_ATU_CR2);
dw_pcie_writel_rc(pp, pp->io_base, PCIE_ATU_LOWER_BASE);
dw_pcie_writel_rc(pp, (pp->io_base >> 32), PCIE_ATU_UPPER_BASE);
dw_pcie_writel_rc(pp, pp->io_base + pp->config.io_size - 1,
PCIE_ATU_LIMIT);
dw_pcie_writel_rc(pp, pp->config.io_bus_addr, PCIE_ATU_LOWER_TARGET);
dw_pcie_writel_rc(pp, upper_32_bits(pp->config.io_bus_addr),
PCIE_ATU_UPPER_TARGET);
}
static int dw_pcie_rd_other_conf(struct pcie_port *pp, struct pci_bus *bus,
u32 devfn, int where, int size, u32 *val)
{
int ret = PCIBIOS_SUCCESSFUL;
u32 address, busdev;
busdev = PCIE_ATU_BUS(bus->number) | PCIE_ATU_DEV(PCI_SLOT(devfn)) |
PCIE_ATU_FUNC(PCI_FUNC(devfn));
address = where & ~0x3;
if (bus->parent->number == pp->root_bus_nr) {
dw_pcie_prog_viewport_cfg0(pp, busdev);
ret = cfg_read(pp->va_cfg0_base + address, where, size, val);
dw_pcie_prog_viewport_mem_outbound(pp);
} else {
dw_pcie_prog_viewport_cfg1(pp, busdev);
ret = cfg_read(pp->va_cfg1_base + address, where, size, val);
dw_pcie_prog_viewport_io_outbound(pp);
}
return ret;
}
static int dw_pcie_wr_other_conf(struct pcie_port *pp, struct pci_bus *bus,
u32 devfn, int where, int size, u32 val)
{
int ret = PCIBIOS_SUCCESSFUL;
u32 address, busdev;
busdev = PCIE_ATU_BUS(bus->number) | PCIE_ATU_DEV(PCI_SLOT(devfn)) |
PCIE_ATU_FUNC(PCI_FUNC(devfn));
address = where & ~0x3;
if (bus->parent->number == pp->root_bus_nr) {
dw_pcie_prog_viewport_cfg0(pp, busdev);
ret = cfg_write(pp->va_cfg0_base + address, where, size, val);
dw_pcie_prog_viewport_mem_outbound(pp);
} else {
dw_pcie_prog_viewport_cfg1(pp, busdev);
ret = cfg_write(pp->va_cfg1_base + address, where, size, val);
dw_pcie_prog_viewport_io_outbound(pp);
}
return ret;
}
static int dw_pcie_valid_config(struct pcie_port *pp,
struct pci_bus *bus, int dev)
{
if (bus->number != pp->root_bus_nr) {
if (!dw_pcie_link_up(pp))
return 0;
}
if (bus->number == pp->root_bus_nr && dev > 0)
return 0;
if (bus->primary == pp->root_bus_nr && dev > 0)
return 0;
return 1;
}
static int dw_pcie_rd_conf(struct pci_bus *bus, u32 devfn, int where,
int size, u32 *val)
{
struct pcie_port *pp = sys_to_pcie(bus->sysdata);
unsigned long flags;
int ret;
if (!pp) {
BUG();
return -EINVAL;
}
if (dw_pcie_valid_config(pp, bus, PCI_SLOT(devfn)) == 0) {
*val = 0xffffffff;
return PCIBIOS_DEVICE_NOT_FOUND;
}
spin_lock_irqsave(&pp->conf_lock, flags);
if (bus->number != pp->root_bus_nr)
ret = dw_pcie_rd_other_conf(pp, bus, devfn,
where, size, val);
else
ret = dw_pcie_rd_own_conf(pp, where, size, val);
spin_unlock_irqrestore(&pp->conf_lock, flags);
return ret;
}
static int dw_pcie_wr_conf(struct pci_bus *bus, u32 devfn,
int where, int size, u32 val)
{
struct pcie_port *pp = sys_to_pcie(bus->sysdata);
unsigned long flags;
int ret;
if (!pp) {
BUG();
return -EINVAL;
}
if (dw_pcie_valid_config(pp, bus, PCI_SLOT(devfn)) == 0)
return PCIBIOS_DEVICE_NOT_FOUND;
spin_lock_irqsave(&pp->conf_lock, flags);
if (bus->number != pp->root_bus_nr)
ret = dw_pcie_wr_other_conf(pp, bus, devfn,
where, size, val);
else
ret = dw_pcie_wr_own_conf(pp, where, size, val);
spin_unlock_irqrestore(&pp->conf_lock, flags);
return ret;
}
int dw_pcie_setup(int nr, struct pci_sys_data *sys)
{
struct pcie_port *pp;
pp = sys_to_pcie(sys);
if (!pp)
return 0;
if (global_io_offset < SZ_1M && pp->config.io_size > 0) {
sys->io_offset = global_io_offset - pp->config.io_bus_addr;
pci_ioremap_io(sys->io_offset, pp->io.start);
global_io_offset += SZ_64K;
pci_add_resource_offset(&sys->resources, &pp->io,
sys->io_offset);
}
sys->mem_offset = pp->mem.start - pp->config.mem_bus_addr;
pci_add_resource_offset(&sys->resources, &pp->mem, sys->mem_offset);
return 1;
}
struct pci_bus *dw_pcie_scan_bus(int nr, struct pci_sys_data *sys)
{
struct pci_bus *bus;
struct pcie_port *pp = sys_to_pcie(sys);
if (pp) {
pp->root_bus_nr = sys->busnr;
bus = pci_scan_root_bus(NULL, sys->busnr, &dw_pcie_ops,
sys, &sys->resources);
} else {
bus = NULL;
BUG();
}
return bus;
}
int dw_pcie_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
struct pcie_port *pp = sys_to_pcie(dev->bus->sysdata);
return pp->irq;
}
void dw_pcie_setup_rc(struct pcie_port *pp)
{
struct pcie_port_info *config = &pp->config;
u32 val;
u32 membase;
u32 memlimit;
dw_pcie_readl_rc(pp, PCIE_PORT_LINK_CONTROL, &val);
val &= ~PORT_LINK_MODE_MASK;
switch (pp->lanes) {
case 1:
val |= PORT_LINK_MODE_1_LANES;
break;
case 2:
val |= PORT_LINK_MODE_2_LANES;
break;
case 4:
val |= PORT_LINK_MODE_4_LANES;
break;
}
dw_pcie_writel_rc(pp, val, PCIE_PORT_LINK_CONTROL);
dw_pcie_readl_rc(pp, PCIE_LINK_WIDTH_SPEED_CONTROL, &val);
val &= ~PORT_LOGIC_LINK_WIDTH_MASK;
switch (pp->lanes) {
case 1:
val |= PORT_LOGIC_LINK_WIDTH_1_LANES;
break;
case 2:
val |= PORT_LOGIC_LINK_WIDTH_2_LANES;
break;
case 4:
val |= PORT_LOGIC_LINK_WIDTH_4_LANES;
break;
}
dw_pcie_writel_rc(pp, val, PCIE_LINK_WIDTH_SPEED_CONTROL);
dw_pcie_writel_rc(pp, 0x00000004, PCI_BASE_ADDRESS_0);
dw_pcie_writel_rc(pp, 0x00000004, PCI_BASE_ADDRESS_1);
dw_pcie_readl_rc(pp, PCI_INTERRUPT_LINE, &val);
val &= 0xffff00ff;
val |= 0x00000100;
dw_pcie_writel_rc(pp, val, PCI_INTERRUPT_LINE);
dw_pcie_readl_rc(pp, PCI_PRIMARY_BUS, &val);
val &= 0xff000000;
val |= 0x00010100;
dw_pcie_writel_rc(pp, val, PCI_PRIMARY_BUS);
membase = ((u32)pp->mem_base & 0xfff00000) >> 16;
memlimit = (config->mem_size + (u32)pp->mem_base) & 0xfff00000;
val = memlimit | membase;
dw_pcie_writel_rc(pp, val, PCI_MEMORY_BASE);
dw_pcie_readl_rc(pp, PCI_COMMAND, &val);
val &= 0xffff0000;
val |= PCI_COMMAND_IO | PCI_COMMAND_MEMORY |
PCI_COMMAND_MASTER | PCI_COMMAND_SERR;
dw_pcie_writel_rc(pp, val, PCI_COMMAND);
}
