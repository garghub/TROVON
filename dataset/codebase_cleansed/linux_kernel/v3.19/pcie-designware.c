static inline struct pcie_port *sys_to_pcie(struct pci_sys_data *sys)
{
BUG_ON(!sys->private_data);
return sys->private_data;
}
int dw_pcie_cfg_read(void __iomem *addr, int where, int size, u32 *val)
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
int dw_pcie_cfg_write(void __iomem *addr, int where, int size, u32 val)
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
static int dw_pcie_rd_own_conf(struct pcie_port *pp, int where, int size,
u32 *val)
{
int ret;
if (pp->ops->rd_own_conf)
ret = pp->ops->rd_own_conf(pp, where, size, val);
else
ret = dw_pcie_cfg_read(pp->dbi_base + (where & ~0x3), where,
size, val);
return ret;
}
static int dw_pcie_wr_own_conf(struct pcie_port *pp, int where, int size,
u32 val)
{
int ret;
if (pp->ops->wr_own_conf)
ret = pp->ops->wr_own_conf(pp, where, size, val);
else
ret = dw_pcie_cfg_write(pp->dbi_base + (where & ~0x3), where,
size, val);
return ret;
}
irqreturn_t dw_handle_msi_irq(struct pcie_port *pp)
{
unsigned long val;
int i, pos, irq;
irqreturn_t ret = IRQ_NONE;
for (i = 0; i < MAX_MSI_CTRLS; i++) {
dw_pcie_rd_own_conf(pp, PCIE_MSI_INTR0_STATUS + i * 12, 4,
(u32 *)&val);
if (val) {
ret = IRQ_HANDLED;
pos = 0;
while ((pos = find_next_bit(&val, 32, pos)) != 32) {
irq = irq_find_mapping(pp->irq_domain,
i * 32 + pos);
dw_pcie_wr_own_conf(pp,
PCIE_MSI_INTR0_STATUS + i * 12,
4, 1 << pos);
generic_handle_irq(irq);
pos++;
}
}
}
return ret;
}
void dw_pcie_msi_init(struct pcie_port *pp)
{
pp->msi_data = __get_free_pages(GFP_KERNEL, 0);
dw_pcie_wr_own_conf(pp, PCIE_MSI_ADDR_LO, 4,
virt_to_phys((void *)pp->msi_data));
dw_pcie_wr_own_conf(pp, PCIE_MSI_ADDR_HI, 4, 0);
}
static void dw_pcie_msi_clear_irq(struct pcie_port *pp, int irq)
{
unsigned int res, bit, val;
res = (irq / 32) * 12;
bit = irq % 32;
dw_pcie_rd_own_conf(pp, PCIE_MSI_INTR0_ENABLE + res, 4, &val);
val &= ~(1 << bit);
dw_pcie_wr_own_conf(pp, PCIE_MSI_INTR0_ENABLE + res, 4, val);
}
static void clear_irq_range(struct pcie_port *pp, unsigned int irq_base,
unsigned int nvec, unsigned int pos)
{
unsigned int i;
for (i = 0; i < nvec; i++) {
irq_set_msi_desc_off(irq_base, i, NULL);
if (pp->ops->msi_clear_irq)
pp->ops->msi_clear_irq(pp, pos + i);
else
dw_pcie_msi_clear_irq(pp, pos + i);
}
bitmap_release_region(pp->msi_irq_in_use, pos, order_base_2(nvec));
}
static void dw_pcie_msi_set_irq(struct pcie_port *pp, int irq)
{
unsigned int res, bit, val;
res = (irq / 32) * 12;
bit = irq % 32;
dw_pcie_rd_own_conf(pp, PCIE_MSI_INTR0_ENABLE + res, 4, &val);
val |= 1 << bit;
dw_pcie_wr_own_conf(pp, PCIE_MSI_INTR0_ENABLE + res, 4, val);
}
static int assign_irq(int no_irqs, struct msi_desc *desc, int *pos)
{
int irq, pos0, i;
struct pcie_port *pp = sys_to_pcie(desc->dev->bus->sysdata);
pos0 = bitmap_find_free_region(pp->msi_irq_in_use, MAX_MSI_IRQS,
order_base_2(no_irqs));
if (pos0 < 0)
goto no_valid_irq;
irq = irq_find_mapping(pp->irq_domain, pos0);
if (!irq)
goto no_valid_irq;
for (i = 0; i < no_irqs; i++) {
if (irq_set_msi_desc_off(irq, i, desc) != 0) {
clear_irq_range(pp, irq, i, pos0);
goto no_valid_irq;
}
if (pp->ops->msi_set_irq)
pp->ops->msi_set_irq(pp, pos0 + i);
else
dw_pcie_msi_set_irq(pp, pos0 + i);
}
*pos = pos0;
return irq;
no_valid_irq:
*pos = pos0;
return -ENOSPC;
}
static int dw_msi_setup_irq(struct msi_controller *chip, struct pci_dev *pdev,
struct msi_desc *desc)
{
int irq, pos;
struct msi_msg msg;
struct pcie_port *pp = sys_to_pcie(pdev->bus->sysdata);
if (desc->msi_attrib.is_msix)
return -EINVAL;
irq = assign_irq(1, desc, &pos);
if (irq < 0)
return irq;
if (pp->ops->get_msi_addr)
msg.address_lo = pp->ops->get_msi_addr(pp);
else
msg.address_lo = virt_to_phys((void *)pp->msi_data);
msg.address_hi = 0x0;
if (pp->ops->get_msi_data)
msg.data = pp->ops->get_msi_data(pp, pos);
else
msg.data = pos;
pci_write_msi_msg(irq, &msg);
return 0;
}
static void dw_msi_teardown_irq(struct msi_controller *chip, unsigned int irq)
{
struct irq_data *data = irq_get_irq_data(irq);
struct msi_desc *msi = irq_data_get_msi(data);
struct pcie_port *pp = sys_to_pcie(msi->dev->bus->sysdata);
clear_irq_range(pp, irq, 1, data->hwirq);
}
int dw_pcie_link_up(struct pcie_port *pp)
{
if (pp->ops->link_up)
return pp->ops->link_up(pp);
else
return 0;
}
static int dw_pcie_msi_map(struct irq_domain *domain, unsigned int irq,
irq_hw_number_t hwirq)
{
irq_set_chip_and_handler(irq, &dw_msi_irq_chip, handle_simple_irq);
irq_set_chip_data(irq, domain->host_data);
set_irq_flags(irq, IRQF_VALID);
return 0;
}
int __init dw_pcie_host_init(struct pcie_port *pp)
{
struct device_node *np = pp->dev->of_node;
struct platform_device *pdev = to_platform_device(pp->dev);
struct of_pci_range range;
struct of_pci_range_parser parser;
struct resource *cfg_res;
u32 val, na, ns;
const __be32 *addrp;
int i, index, ret;
of_property_read_u32(np, "#address-cells", &na);
ns = of_n_size_cells(np);
cfg_res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "config");
if (cfg_res) {
pp->cfg0_size = resource_size(cfg_res)/2;
pp->cfg1_size = resource_size(cfg_res)/2;
pp->cfg0_base = cfg_res->start;
pp->cfg1_base = cfg_res->start + pp->cfg0_size;
index = of_property_match_string(np, "reg-names", "config");
addrp = of_get_address(np, index, NULL, NULL);
pp->cfg0_mod_base = of_read_number(addrp, ns);
pp->cfg1_mod_base = pp->cfg0_mod_base + pp->cfg0_size;
} else {
dev_err(pp->dev, "missing *config* reg space\n");
}
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
+ global_io_offset - 1);
pp->io_size = resource_size(&pp->io);
pp->io_bus_addr = range.pci_addr;
pp->io_base = range.cpu_addr;
pp->io_mod_base = of_read_number(parser.range -
parser.np + na, ns);
}
if (restype == IORESOURCE_MEM) {
of_pci_range_to_resource(&range, np, &pp->mem);
pp->mem.name = "MEM";
pp->mem_size = resource_size(&pp->mem);
pp->mem_bus_addr = range.pci_addr;
pp->mem_mod_base = of_read_number(parser.range -
parser.np + na, ns);
}
if (restype == 0) {
of_pci_range_to_resource(&range, np, &pp->cfg);
pp->cfg0_size = resource_size(&pp->cfg)/2;
pp->cfg1_size = resource_size(&pp->cfg)/2;
pp->cfg0_base = pp->cfg.start;
pp->cfg1_base = pp->cfg.start + pp->cfg0_size;
pp->cfg0_mod_base = of_read_number(parser.range -
parser.np + na, ns);
pp->cfg1_mod_base = pp->cfg0_mod_base +
pp->cfg0_size;
}
}
ret = of_pci_parse_bus_range(np, &pp->busn);
if (ret < 0) {
pp->busn.name = np->name;
pp->busn.start = 0;
pp->busn.end = 0xff;
pp->busn.flags = IORESOURCE_BUS;
dev_dbg(pp->dev, "failed to parse bus-range property: %d, using default %pR\n",
ret, &pp->busn);
}
if (!pp->dbi_base) {
pp->dbi_base = devm_ioremap(pp->dev, pp->cfg.start,
resource_size(&pp->cfg));
if (!pp->dbi_base) {
dev_err(pp->dev, "error with ioremap\n");
return -ENOMEM;
}
}
pp->mem_base = pp->mem.start;
if (!pp->va_cfg0_base) {
pp->va_cfg0_base = devm_ioremap(pp->dev, pp->cfg0_base,
pp->cfg0_size);
if (!pp->va_cfg0_base) {
dev_err(pp->dev, "error with ioremap in function\n");
return -ENOMEM;
}
}
if (!pp->va_cfg1_base) {
pp->va_cfg1_base = devm_ioremap(pp->dev, pp->cfg1_base,
pp->cfg1_size);
if (!pp->va_cfg1_base) {
dev_err(pp->dev, "error with ioremap\n");
return -ENOMEM;
}
}
if (of_property_read_u32(np, "num-lanes", &pp->lanes)) {
dev_err(pp->dev, "Failed to parse the number of lanes\n");
return -EINVAL;
}
if (IS_ENABLED(CONFIG_PCI_MSI)) {
if (!pp->ops->msi_host_init) {
pp->irq_domain = irq_domain_add_linear(pp->dev->of_node,
MAX_MSI_IRQS, &msi_domain_ops,
&dw_pcie_msi_chip);
if (!pp->irq_domain) {
dev_err(pp->dev, "irq domain init failed\n");
return -ENXIO;
}
for (i = 0; i < MAX_MSI_IRQS; i++)
irq_create_mapping(pp->irq_domain, i);
} else {
ret = pp->ops->msi_host_init(pp, &dw_pcie_msi_chip);
if (ret < 0)
return ret;
}
}
if (pp->ops->host_init)
pp->ops->host_init(pp);
dw_pcie_wr_own_conf(pp, PCI_BASE_ADDRESS_0, 4, 0);
dw_pcie_wr_own_conf(pp, PCI_CLASS_DEVICE, 2, PCI_CLASS_BRIDGE_PCI);
dw_pcie_rd_own_conf(pp, PCIE_LINK_WIDTH_SPEED_CONTROL, 4, &val);
val |= PORT_LOGIC_SPEED_CHANGE;
dw_pcie_wr_own_conf(pp, PCIE_LINK_WIDTH_SPEED_CONTROL, 4, val);
#ifdef CONFIG_PCI_MSI
dw_pcie_msi_chip.dev = pp->dev;
dw_pci.msi_ctrl = &dw_pcie_msi_chip;
#endif
dw_pci.nr_controllers = 1;
dw_pci.private_data = (void **)&pp;
pci_common_init_dev(pp->dev, &dw_pci);
#ifdef CONFIG_PCI_DOMAINS
dw_pci.domain++;
#endif
return 0;
}
static void dw_pcie_prog_viewport_cfg0(struct pcie_port *pp, u32 busdev)
{
dw_pcie_writel_rc(pp, PCIE_ATU_REGION_OUTBOUND | PCIE_ATU_REGION_INDEX0,
PCIE_ATU_VIEWPORT);
dw_pcie_writel_rc(pp, pp->cfg0_mod_base, PCIE_ATU_LOWER_BASE);
dw_pcie_writel_rc(pp, (pp->cfg0_mod_base >> 32), PCIE_ATU_UPPER_BASE);
dw_pcie_writel_rc(pp, pp->cfg0_mod_base + pp->cfg0_size - 1,
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
dw_pcie_writel_rc(pp, pp->cfg1_mod_base, PCIE_ATU_LOWER_BASE);
dw_pcie_writel_rc(pp, (pp->cfg1_mod_base >> 32), PCIE_ATU_UPPER_BASE);
dw_pcie_writel_rc(pp, pp->cfg1_mod_base + pp->cfg1_size - 1,
PCIE_ATU_LIMIT);
dw_pcie_writel_rc(pp, busdev, PCIE_ATU_LOWER_TARGET);
dw_pcie_writel_rc(pp, 0, PCIE_ATU_UPPER_TARGET);
dw_pcie_writel_rc(pp, PCIE_ATU_ENABLE, PCIE_ATU_CR2);
}
static void dw_pcie_prog_viewport_mem_outbound(struct pcie_port *pp)
{
dw_pcie_writel_rc(pp, PCIE_ATU_REGION_OUTBOUND | PCIE_ATU_REGION_INDEX0,
PCIE_ATU_VIEWPORT);
dw_pcie_writel_rc(pp, PCIE_ATU_TYPE_MEM, PCIE_ATU_CR1);
dw_pcie_writel_rc(pp, pp->mem_mod_base, PCIE_ATU_LOWER_BASE);
dw_pcie_writel_rc(pp, (pp->mem_mod_base >> 32), PCIE_ATU_UPPER_BASE);
dw_pcie_writel_rc(pp, pp->mem_mod_base + pp->mem_size - 1,
PCIE_ATU_LIMIT);
dw_pcie_writel_rc(pp, pp->mem_bus_addr, PCIE_ATU_LOWER_TARGET);
dw_pcie_writel_rc(pp, upper_32_bits(pp->mem_bus_addr),
PCIE_ATU_UPPER_TARGET);
dw_pcie_writel_rc(pp, PCIE_ATU_ENABLE, PCIE_ATU_CR2);
}
static void dw_pcie_prog_viewport_io_outbound(struct pcie_port *pp)
{
dw_pcie_writel_rc(pp, PCIE_ATU_REGION_OUTBOUND | PCIE_ATU_REGION_INDEX1,
PCIE_ATU_VIEWPORT);
dw_pcie_writel_rc(pp, PCIE_ATU_TYPE_IO, PCIE_ATU_CR1);
dw_pcie_writel_rc(pp, pp->io_mod_base, PCIE_ATU_LOWER_BASE);
dw_pcie_writel_rc(pp, (pp->io_mod_base >> 32), PCIE_ATU_UPPER_BASE);
dw_pcie_writel_rc(pp, pp->io_mod_base + pp->io_size - 1,
PCIE_ATU_LIMIT);
dw_pcie_writel_rc(pp, pp->io_bus_addr, PCIE_ATU_LOWER_TARGET);
dw_pcie_writel_rc(pp, upper_32_bits(pp->io_bus_addr),
PCIE_ATU_UPPER_TARGET);
dw_pcie_writel_rc(pp, PCIE_ATU_ENABLE, PCIE_ATU_CR2);
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
ret = dw_pcie_cfg_read(pp->va_cfg0_base + address, where, size,
val);
dw_pcie_prog_viewport_mem_outbound(pp);
} else {
dw_pcie_prog_viewport_cfg1(pp, busdev);
ret = dw_pcie_cfg_read(pp->va_cfg1_base + address, where, size,
val);
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
ret = dw_pcie_cfg_write(pp->va_cfg0_base + address, where, size,
val);
dw_pcie_prog_viewport_mem_outbound(pp);
} else {
dw_pcie_prog_viewport_cfg1(pp, busdev);
ret = dw_pcie_cfg_write(pp->va_cfg1_base + address, where, size,
val);
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
int ret;
if (dw_pcie_valid_config(pp, bus, PCI_SLOT(devfn)) == 0) {
*val = 0xffffffff;
return PCIBIOS_DEVICE_NOT_FOUND;
}
if (bus->number != pp->root_bus_nr)
if (pp->ops->rd_other_conf)
ret = pp->ops->rd_other_conf(pp, bus, devfn,
where, size, val);
else
ret = dw_pcie_rd_other_conf(pp, bus, devfn,
where, size, val);
else
ret = dw_pcie_rd_own_conf(pp, where, size, val);
return ret;
}
static int dw_pcie_wr_conf(struct pci_bus *bus, u32 devfn,
int where, int size, u32 val)
{
struct pcie_port *pp = sys_to_pcie(bus->sysdata);
int ret;
if (dw_pcie_valid_config(pp, bus, PCI_SLOT(devfn)) == 0)
return PCIBIOS_DEVICE_NOT_FOUND;
if (bus->number != pp->root_bus_nr)
if (pp->ops->wr_other_conf)
ret = pp->ops->wr_other_conf(pp, bus, devfn,
where, size, val);
else
ret = dw_pcie_wr_other_conf(pp, bus, devfn,
where, size, val);
else
ret = dw_pcie_wr_own_conf(pp, where, size, val);
return ret;
}
static int dw_pcie_setup(int nr, struct pci_sys_data *sys)
{
struct pcie_port *pp;
pp = sys_to_pcie(sys);
if (global_io_offset < SZ_1M && pp->io_size > 0) {
sys->io_offset = global_io_offset - pp->io_bus_addr;
pci_ioremap_io(global_io_offset, pp->io_base);
global_io_offset += SZ_64K;
pci_add_resource_offset(&sys->resources, &pp->io,
sys->io_offset);
}
sys->mem_offset = pp->mem.start - pp->mem_bus_addr;
pci_add_resource_offset(&sys->resources, &pp->mem, sys->mem_offset);
pci_add_resource(&sys->resources, &pp->busn);
return 1;
}
static struct pci_bus *dw_pcie_scan_bus(int nr, struct pci_sys_data *sys)
{
struct pci_bus *bus;
struct pcie_port *pp = sys_to_pcie(sys);
pp->root_bus_nr = sys->busnr;
bus = pci_create_root_bus(pp->dev, sys->busnr,
&dw_pcie_ops, sys, &sys->resources);
if (!bus)
return NULL;
pci_scan_child_bus(bus);
if (bus && pp->ops->scan_bus)
pp->ops->scan_bus(pp);
return bus;
}
static int dw_pcie_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
struct pcie_port *pp = sys_to_pcie(dev->bus->sysdata);
int irq;
irq = of_irq_parse_and_map_pci(dev, slot, pin);
if (!irq)
irq = pp->irq;
return irq;
}
void dw_pcie_setup_rc(struct pcie_port *pp)
{
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
dw_pcie_writel_rc(pp, 0x00000000, PCI_BASE_ADDRESS_1);
dw_pcie_readl_rc(pp, PCI_INTERRUPT_LINE, &val);
val &= 0xffff00ff;
val |= 0x00000100;
dw_pcie_writel_rc(pp, val, PCI_INTERRUPT_LINE);
dw_pcie_readl_rc(pp, PCI_PRIMARY_BUS, &val);
val &= 0xff000000;
val |= 0x00010100;
dw_pcie_writel_rc(pp, val, PCI_PRIMARY_BUS);
membase = ((u32)pp->mem_base & 0xfff00000) >> 16;
memlimit = (pp->mem_size + (u32)pp->mem_base) & 0xfff00000;
val = memlimit | membase;
dw_pcie_writel_rc(pp, val, PCI_MEMORY_BASE);
dw_pcie_readl_rc(pp, PCI_COMMAND, &val);
val &= 0xffff0000;
val |= PCI_COMMAND_IO | PCI_COMMAND_MEMORY |
PCI_COMMAND_MASTER | PCI_COMMAND_SERR;
dw_pcie_writel_rc(pp, val, PCI_COMMAND);
}
