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
static int dw_pcie_rd_own_conf(struct pcie_port *pp, int where, int size,
u32 *val)
{
int ret;
if (pp->ops->rd_own_conf)
ret = pp->ops->rd_own_conf(pp, where, size, val);
else
ret = cfg_read(pp->dbi_base + (where & ~0x3), where, size, val);
return ret;
}
static int dw_pcie_wr_own_conf(struct pcie_port *pp, int where, int size,
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
void dw_handle_msi_irq(struct pcie_port *pp)
{
unsigned long val;
int i, pos, irq;
for (i = 0; i < MAX_MSI_CTRLS; i++) {
dw_pcie_rd_own_conf(pp, PCIE_MSI_INTR0_STATUS + i * 12, 4,
(u32 *)&val);
if (val) {
pos = 0;
while ((pos = find_next_bit(&val, 32, pos)) != 32) {
irq = irq_find_mapping(pp->irq_domain,
i * 32 + pos);
generic_handle_irq(irq);
pos++;
}
}
dw_pcie_wr_own_conf(pp, PCIE_MSI_INTR0_STATUS + i * 12, 4, val);
}
}
void dw_pcie_msi_init(struct pcie_port *pp)
{
pp->msi_data = __get_free_pages(GFP_KERNEL, 0);
dw_pcie_wr_own_conf(pp, PCIE_MSI_ADDR_LO, 4,
virt_to_phys((void *)pp->msi_data));
dw_pcie_wr_own_conf(pp, PCIE_MSI_ADDR_HI, 4, 0);
}
static int find_valid_pos0(struct pcie_port *pp, int msgvec, int pos, int *pos0)
{
int flag = 1;
do {
pos = find_next_zero_bit(pp->msi_irq_in_use,
MAX_MSI_IRQS, pos);
if (pos == MAX_MSI_IRQS)
return -ENOSPC;
if (pos % msgvec)
pos += msgvec - (pos % msgvec);
else
flag = 0;
} while (flag);
*pos0 = pos;
return 0;
}
static int assign_irq(int no_irqs, struct msi_desc *desc, int *pos)
{
int res, bit, irq, pos0, pos1, i;
u32 val;
struct pcie_port *pp = sys_to_pcie(desc->dev->bus->sysdata);
if (!pp) {
BUG();
return -EINVAL;
}
pos0 = find_first_zero_bit(pp->msi_irq_in_use,
MAX_MSI_IRQS);
if (pos0 % no_irqs) {
if (find_valid_pos0(pp, no_irqs, pos0, &pos0))
goto no_valid_irq;
}
if (no_irqs > 1) {
pos1 = find_next_bit(pp->msi_irq_in_use,
MAX_MSI_IRQS, pos0);
while ((pos1 - pos0) < no_irqs) {
if (find_valid_pos0(pp, no_irqs, pos1, &pos0))
goto no_valid_irq;
pos1 = find_next_bit(pp->msi_irq_in_use,
MAX_MSI_IRQS, pos0);
}
}
irq = irq_find_mapping(pp->irq_domain, pos0);
if (!irq)
goto no_valid_irq;
i = 0;
while (i < no_irqs) {
set_bit(pos0 + i, pp->msi_irq_in_use);
irq_alloc_descs((irq + i), (irq + i), 1, 0);
irq_set_msi_desc(irq + i, desc);
res = ((pos0 + i) / 32) * 12;
bit = (pos0 + i) % 32;
dw_pcie_rd_own_conf(pp, PCIE_MSI_INTR0_ENABLE + res, 4, &val);
val |= 1 << bit;
dw_pcie_wr_own_conf(pp, PCIE_MSI_INTR0_ENABLE + res, 4, val);
i++;
}
*pos = pos0;
return irq;
no_valid_irq:
*pos = pos0;
return -ENOSPC;
}
static void clear_irq(unsigned int irq)
{
int res, bit, val, pos;
struct irq_desc *desc;
struct msi_desc *msi;
struct pcie_port *pp;
struct irq_data *data = irq_get_irq_data(irq);
desc = irq_to_desc(irq);
msi = irq_desc_get_msi_desc(desc);
pp = sys_to_pcie(msi->dev->bus->sysdata);
if (!pp) {
BUG();
return;
}
pos = data->hwirq;
irq_free_desc(irq);
clear_bit(pos, pp->msi_irq_in_use);
res = (pos / 32) * 12;
bit = pos % 32;
dw_pcie_rd_own_conf(pp, PCIE_MSI_INTR0_ENABLE + res, 4, &val);
val &= ~(1 << bit);
dw_pcie_wr_own_conf(pp, PCIE_MSI_INTR0_ENABLE + res, 4, val);
}
static int dw_msi_setup_irq(struct msi_chip *chip, struct pci_dev *pdev,
struct msi_desc *desc)
{
int irq, pos, msgvec;
u16 msg_ctr;
struct msi_msg msg;
struct pcie_port *pp = sys_to_pcie(pdev->bus->sysdata);
if (!pp) {
BUG();
return -EINVAL;
}
pci_read_config_word(pdev, desc->msi_attrib.pos+PCI_MSI_FLAGS,
&msg_ctr);
msgvec = (msg_ctr&PCI_MSI_FLAGS_QSIZE) >> 4;
if (msgvec == 0)
msgvec = (msg_ctr & PCI_MSI_FLAGS_QMASK) >> 1;
if (msgvec > 5)
msgvec = 0;
irq = assign_irq((1 << msgvec), desc, &pos);
if (irq < 0)
return irq;
msg_ctr &= ~PCI_MSI_FLAGS_QSIZE;
msg_ctr |= msgvec << 4;
pci_write_config_word(pdev, desc->msi_attrib.pos + PCI_MSI_FLAGS,
msg_ctr);
desc->msi_attrib.multiple = msgvec;
msg.address_lo = virt_to_phys((void *)pp->msi_data);
msg.address_hi = 0x0;
msg.data = pos;
write_msi_msg(irq, &msg);
return 0;
}
static void dw_msi_teardown_irq(struct msi_chip *chip, unsigned int irq)
{
clear_irq(irq);
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
struct of_pci_range range;
struct of_pci_range_parser parser;
u32 val;
int i;
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
if (IS_ENABLED(CONFIG_PCI_MSI)) {
pp->irq_domain = irq_domain_add_linear(pp->dev->of_node,
MAX_MSI_IRQS, &msi_domain_ops,
&dw_pcie_msi_chip);
if (!pp->irq_domain) {
dev_err(pp->dev, "irq domain init failed\n");
return -ENXIO;
}
for (i = 0; i < MAX_MSI_IRQS; i++)
irq_create_mapping(pp->irq_domain, i);
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
static int dw_pcie_setup(int nr, struct pci_sys_data *sys)
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
static struct pci_bus *dw_pcie_scan_bus(int nr, struct pci_sys_data *sys)
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
static int dw_pcie_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
struct pcie_port *pp = sys_to_pcie(dev->bus->sysdata);
return pp->irq;
}
static void dw_pcie_add_bus(struct pci_bus *bus)
{
if (IS_ENABLED(CONFIG_PCI_MSI)) {
struct pcie_port *pp = sys_to_pcie(bus->sysdata);
dw_pcie_msi_chip.dev = pp->dev;
bus->msi = &dw_pcie_msi_chip;
}
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
