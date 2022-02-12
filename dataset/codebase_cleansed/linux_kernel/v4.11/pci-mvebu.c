static inline void mvebu_writel(struct mvebu_pcie_port *port, u32 val, u32 reg)
{
writel(val, port->base + reg);
}
static inline u32 mvebu_readl(struct mvebu_pcie_port *port, u32 reg)
{
return readl(port->base + reg);
}
static inline bool mvebu_has_ioport(struct mvebu_pcie_port *port)
{
return port->io_target != -1 && port->io_attr != -1;
}
static bool mvebu_pcie_link_up(struct mvebu_pcie_port *port)
{
return !(mvebu_readl(port, PCIE_STAT_OFF) & PCIE_STAT_LINK_DOWN);
}
static void mvebu_pcie_set_local_bus_nr(struct mvebu_pcie_port *port, int nr)
{
u32 stat;
stat = mvebu_readl(port, PCIE_STAT_OFF);
stat &= ~PCIE_STAT_BUS;
stat |= nr << 8;
mvebu_writel(port, stat, PCIE_STAT_OFF);
}
static void mvebu_pcie_set_local_dev_nr(struct mvebu_pcie_port *port, int nr)
{
u32 stat;
stat = mvebu_readl(port, PCIE_STAT_OFF);
stat &= ~PCIE_STAT_DEV;
stat |= nr << 16;
mvebu_writel(port, stat, PCIE_STAT_OFF);
}
static void mvebu_pcie_setup_wins(struct mvebu_pcie_port *port)
{
const struct mbus_dram_target_info *dram;
u32 size;
int i;
dram = mv_mbus_dram_info();
for (i = 1; i < 3; i++) {
mvebu_writel(port, 0, PCIE_BAR_CTRL_OFF(i));
mvebu_writel(port, 0, PCIE_BAR_LO_OFF(i));
mvebu_writel(port, 0, PCIE_BAR_HI_OFF(i));
}
for (i = 0; i < 5; i++) {
mvebu_writel(port, 0, PCIE_WIN04_CTRL_OFF(i));
mvebu_writel(port, 0, PCIE_WIN04_BASE_OFF(i));
mvebu_writel(port, 0, PCIE_WIN04_REMAP_OFF(i));
}
mvebu_writel(port, 0, PCIE_WIN5_CTRL_OFF);
mvebu_writel(port, 0, PCIE_WIN5_BASE_OFF);
mvebu_writel(port, 0, PCIE_WIN5_REMAP_OFF);
size = 0;
for (i = 0; i < dram->num_cs; i++) {
const struct mbus_dram_window *cs = dram->cs + i;
mvebu_writel(port, cs->base & 0xffff0000,
PCIE_WIN04_BASE_OFF(i));
mvebu_writel(port, 0, PCIE_WIN04_REMAP_OFF(i));
mvebu_writel(port,
((cs->size - 1) & 0xffff0000) |
(cs->mbus_attr << 8) |
(dram->mbus_dram_target_id << 4) | 1,
PCIE_WIN04_CTRL_OFF(i));
size += cs->size;
}
if ((size & (size - 1)) != 0)
size = 1 << fls(size);
mvebu_writel(port, dram->cs[0].base, PCIE_BAR_LO_OFF(1));
mvebu_writel(port, 0, PCIE_BAR_HI_OFF(1));
mvebu_writel(port, ((size - 1) & 0xffff0000) | 1,
PCIE_BAR_CTRL_OFF(1));
}
static void mvebu_pcie_setup_hw(struct mvebu_pcie_port *port)
{
u32 cmd, mask;
mvebu_pcie_setup_wins(port);
cmd = mvebu_readl(port, PCIE_CMD_OFF);
cmd |= PCI_COMMAND_IO;
cmd |= PCI_COMMAND_MEMORY;
cmd |= PCI_COMMAND_MASTER;
mvebu_writel(port, cmd, PCIE_CMD_OFF);
mask = mvebu_readl(port, PCIE_MASK_OFF);
mask |= PCIE_MASK_ENABLE_INTS;
mvebu_writel(port, mask, PCIE_MASK_OFF);
}
static int mvebu_pcie_hw_rd_conf(struct mvebu_pcie_port *port,
struct pci_bus *bus,
u32 devfn, int where, int size, u32 *val)
{
void __iomem *conf_data = port->base + PCIE_CONF_DATA_OFF;
mvebu_writel(port, PCIE_CONF_ADDR(bus->number, devfn, where),
PCIE_CONF_ADDR_OFF);
switch (size) {
case 1:
*val = readb_relaxed(conf_data + (where & 3));
break;
case 2:
*val = readw_relaxed(conf_data + (where & 2));
break;
case 4:
*val = readl_relaxed(conf_data);
break;
}
return PCIBIOS_SUCCESSFUL;
}
static int mvebu_pcie_hw_wr_conf(struct mvebu_pcie_port *port,
struct pci_bus *bus,
u32 devfn, int where, int size, u32 val)
{
void __iomem *conf_data = port->base + PCIE_CONF_DATA_OFF;
mvebu_writel(port, PCIE_CONF_ADDR(bus->number, devfn, where),
PCIE_CONF_ADDR_OFF);
switch (size) {
case 1:
writeb(val, conf_data + (where & 3));
break;
case 2:
writew(val, conf_data + (where & 2));
break;
case 4:
writel(val, conf_data);
break;
default:
return PCIBIOS_BAD_REGISTER_NUMBER;
}
return PCIBIOS_SUCCESSFUL;
}
static void mvebu_pcie_del_windows(struct mvebu_pcie_port *port,
phys_addr_t base, size_t size)
{
while (size) {
size_t sz = 1 << (fls(size) - 1);
mvebu_mbus_del_window(base, sz);
base += sz;
size -= sz;
}
}
static void mvebu_pcie_add_windows(struct mvebu_pcie_port *port,
unsigned int target, unsigned int attribute,
phys_addr_t base, size_t size,
phys_addr_t remap)
{
size_t size_mapped = 0;
while (size) {
size_t sz = 1 << (fls(size) - 1);
int ret;
ret = mvebu_mbus_add_window_remap_by_id(target, attribute, base,
sz, remap);
if (ret) {
phys_addr_t end = base + sz - 1;
dev_err(&port->pcie->pdev->dev,
"Could not create MBus window at [mem %pa-%pa]: %d\n",
&base, &end, ret);
mvebu_pcie_del_windows(port, base - size_mapped,
size_mapped);
return;
}
size -= sz;
size_mapped += sz;
base += sz;
if (remap != MVEBU_MBUS_NO_REMAP)
remap += sz;
}
}
static void mvebu_pcie_set_window(struct mvebu_pcie_port *port,
unsigned int target, unsigned int attribute,
const struct mvebu_pcie_window *desired,
struct mvebu_pcie_window *cur)
{
if (desired->base == cur->base && desired->remap == cur->remap &&
desired->size == cur->size)
return;
if (cur->size != 0) {
mvebu_pcie_del_windows(port, cur->base, cur->size);
cur->size = 0;
cur->base = 0;
}
if (desired->size == 0)
return;
mvebu_pcie_add_windows(port, target, attribute, desired->base,
desired->size, desired->remap);
*cur = *desired;
}
static void mvebu_pcie_handle_iobase_change(struct mvebu_pcie_port *port)
{
struct mvebu_pcie_window desired = {};
if (port->bridge.iolimit < port->bridge.iobase ||
port->bridge.iolimitupper < port->bridge.iobaseupper ||
!(port->bridge.command & PCI_COMMAND_IO)) {
mvebu_pcie_set_window(port, port->io_target, port->io_attr,
&desired, &port->iowin);
return;
}
if (!mvebu_has_ioport(port)) {
dev_WARN(&port->pcie->pdev->dev,
"Attempt to set IO when IO is disabled\n");
return;
}
desired.remap = ((port->bridge.iobase & 0xF0) << 8) |
(port->bridge.iobaseupper << 16);
desired.base = port->pcie->io.start + desired.remap;
desired.size = ((0xFFF | ((port->bridge.iolimit & 0xF0) << 8) |
(port->bridge.iolimitupper << 16)) -
desired.remap) +
1;
mvebu_pcie_set_window(port, port->io_target, port->io_attr, &desired,
&port->iowin);
}
static void mvebu_pcie_handle_membase_change(struct mvebu_pcie_port *port)
{
struct mvebu_pcie_window desired = {.remap = MVEBU_MBUS_NO_REMAP};
if (port->bridge.memlimit < port->bridge.membase ||
!(port->bridge.command & PCI_COMMAND_MEMORY)) {
mvebu_pcie_set_window(port, port->mem_target, port->mem_attr,
&desired, &port->memwin);
return;
}
desired.base = ((port->bridge.membase & 0xFFF0) << 16);
desired.size = (((port->bridge.memlimit & 0xFFF0) << 16) | 0xFFFFF) -
desired.base + 1;
mvebu_pcie_set_window(port, port->mem_target, port->mem_attr, &desired,
&port->memwin);
}
static void mvebu_sw_pci_bridge_init(struct mvebu_pcie_port *port)
{
struct mvebu_sw_pci_bridge *bridge = &port->bridge;
memset(bridge, 0, sizeof(struct mvebu_sw_pci_bridge));
bridge->class = PCI_CLASS_BRIDGE_PCI;
bridge->vendor = PCI_VENDOR_ID_MARVELL;
bridge->device = mvebu_readl(port, PCIE_DEV_ID_OFF) >> 16;
bridge->revision = mvebu_readl(port, PCIE_DEV_REV_OFF) & 0xff;
bridge->header_type = PCI_HEADER_TYPE_BRIDGE;
bridge->cache_line_size = 0x10;
bridge->iobase = PCI_IO_RANGE_TYPE_32;
bridge->iolimit = PCI_IO_RANGE_TYPE_32;
bridge->status = PCI_STATUS_CAP_LIST;
}
static int mvebu_sw_pci_bridge_read(struct mvebu_pcie_port *port,
unsigned int where, int size, u32 *value)
{
struct mvebu_sw_pci_bridge *bridge = &port->bridge;
switch (where & ~3) {
case PCI_VENDOR_ID:
*value = bridge->device << 16 | bridge->vendor;
break;
case PCI_COMMAND:
*value = bridge->command | bridge->status << 16;
break;
case PCI_CLASS_REVISION:
*value = bridge->class << 16 | bridge->interface << 8 |
bridge->revision;
break;
case PCI_CACHE_LINE_SIZE:
*value = bridge->bist << 24 | bridge->header_type << 16 |
bridge->latency_timer << 8 | bridge->cache_line_size;
break;
case PCI_BASE_ADDRESS_0 ... PCI_BASE_ADDRESS_1:
*value = bridge->bar[((where & ~3) - PCI_BASE_ADDRESS_0) / 4];
break;
case PCI_PRIMARY_BUS:
*value = (bridge->secondary_latency_timer << 24 |
bridge->subordinate_bus << 16 |
bridge->secondary_bus << 8 |
bridge->primary_bus);
break;
case PCI_IO_BASE:
if (!mvebu_has_ioport(port))
*value = bridge->secondary_status << 16;
else
*value = (bridge->secondary_status << 16 |
bridge->iolimit << 8 |
bridge->iobase);
break;
case PCI_MEMORY_BASE:
*value = (bridge->memlimit << 16 | bridge->membase);
break;
case PCI_PREF_MEMORY_BASE:
*value = 0;
break;
case PCI_IO_BASE_UPPER16:
*value = (bridge->iolimitupper << 16 | bridge->iobaseupper);
break;
case PCI_CAPABILITY_LIST:
*value = PCISWCAP;
break;
case PCI_ROM_ADDRESS1:
*value = 0;
break;
case PCI_INTERRUPT_LINE:
*value = 0;
break;
case PCISWCAP_EXP_LIST_ID:
*value = (PCI_EXP_TYPE_ROOT_PORT << 4 | 2 |
PCI_EXP_FLAGS_SLOT) << 16 | PCI_CAP_ID_EXP;
break;
case PCISWCAP_EXP_DEVCAP:
*value = mvebu_readl(port, PCIE_CAP_PCIEXP + PCI_EXP_DEVCAP);
break;
case PCISWCAP_EXP_DEVCTL:
*value = mvebu_readl(port, PCIE_CAP_PCIEXP + PCI_EXP_DEVCTL) &
~(PCI_EXP_DEVCTL_URRE | PCI_EXP_DEVCTL_FERE |
PCI_EXP_DEVCTL_NFERE | PCI_EXP_DEVCTL_CERE);
*value |= bridge->pcie_devctl;
break;
case PCISWCAP_EXP_LNKCAP:
*value = mvebu_readl(port, PCIE_CAP_PCIEXP + PCI_EXP_LNKCAP) &
~PCI_EXP_LNKCAP_CLKPM;
break;
case PCISWCAP_EXP_LNKCTL:
*value = mvebu_readl(port, PCIE_CAP_PCIEXP + PCI_EXP_LNKCTL);
break;
case PCISWCAP_EXP_SLTCAP:
*value = bridge->pcie_sltcap;
break;
case PCISWCAP_EXP_SLTCTL:
*value = PCI_EXP_SLTSTA_PDS << 16;
break;
case PCISWCAP_EXP_RTCTL:
*value = bridge->pcie_rtctl;
break;
case PCISWCAP_EXP_RTSTA:
*value = mvebu_readl(port, PCIE_RC_RTSTA);
break;
case PCISWCAP_EXP_DEVCAP2:
case PCISWCAP_EXP_DEVCTL2:
case PCISWCAP_EXP_LNKCAP2:
case PCISWCAP_EXP_LNKCTL2:
case PCISWCAP_EXP_SLTCAP2:
case PCISWCAP_EXP_SLTCTL2:
default:
*value = 0;
return PCIBIOS_SUCCESSFUL;
}
if (size == 2)
*value = (*value >> (8 * (where & 3))) & 0xffff;
else if (size == 1)
*value = (*value >> (8 * (where & 3))) & 0xff;
return PCIBIOS_SUCCESSFUL;
}
static int mvebu_sw_pci_bridge_write(struct mvebu_pcie_port *port,
unsigned int where, int size, u32 value)
{
struct mvebu_sw_pci_bridge *bridge = &port->bridge;
u32 mask, reg;
int err;
if (size == 4)
mask = 0x0;
else if (size == 2)
mask = ~(0xffff << ((where & 3) * 8));
else if (size == 1)
mask = ~(0xff << ((where & 3) * 8));
else
return PCIBIOS_BAD_REGISTER_NUMBER;
err = mvebu_sw_pci_bridge_read(port, where & ~3, 4, &reg);
if (err)
return err;
value = (reg & mask) | value << ((where & 3) * 8);
switch (where & ~3) {
case PCI_COMMAND:
{
u32 old = bridge->command;
if (!mvebu_has_ioport(port))
value &= ~PCI_COMMAND_IO;
bridge->command = value & 0xffff;
if ((old ^ bridge->command) & PCI_COMMAND_IO)
mvebu_pcie_handle_iobase_change(port);
if ((old ^ bridge->command) & PCI_COMMAND_MEMORY)
mvebu_pcie_handle_membase_change(port);
break;
}
case PCI_BASE_ADDRESS_0 ... PCI_BASE_ADDRESS_1:
bridge->bar[((where & ~3) - PCI_BASE_ADDRESS_0) / 4] = value;
break;
case PCI_IO_BASE:
bridge->iobase = (value & 0xff) | PCI_IO_RANGE_TYPE_32;
bridge->iolimit = ((value >> 8) & 0xff) | PCI_IO_RANGE_TYPE_32;
mvebu_pcie_handle_iobase_change(port);
break;
case PCI_MEMORY_BASE:
bridge->membase = value & 0xffff;
bridge->memlimit = value >> 16;
mvebu_pcie_handle_membase_change(port);
break;
case PCI_IO_BASE_UPPER16:
bridge->iobaseupper = value & 0xffff;
bridge->iolimitupper = value >> 16;
mvebu_pcie_handle_iobase_change(port);
break;
case PCI_PRIMARY_BUS:
bridge->primary_bus = value & 0xff;
bridge->secondary_bus = (value >> 8) & 0xff;
bridge->subordinate_bus = (value >> 16) & 0xff;
bridge->secondary_latency_timer = (value >> 24) & 0xff;
mvebu_pcie_set_local_bus_nr(port, bridge->secondary_bus);
break;
case PCISWCAP_EXP_DEVCTL:
value &= ~(PCI_EXP_DEVCTL_URRE | PCI_EXP_DEVCTL_FERE |
PCI_EXP_DEVCTL_NFERE | PCI_EXP_DEVCTL_CERE);
if (mask == 0xffff0000)
value &= 0xffff;
mvebu_writel(port, value, PCIE_CAP_PCIEXP + PCI_EXP_DEVCTL);
break;
case PCISWCAP_EXP_LNKCTL:
value &= ~PCI_EXP_LNKCTL_CLKREQ_EN;
if (mask == 0xffff0000)
value &= 0xffff;
mvebu_writel(port, value, PCIE_CAP_PCIEXP + PCI_EXP_LNKCTL);
break;
case PCISWCAP_EXP_RTSTA:
mvebu_writel(port, value, PCIE_RC_RTSTA);
break;
default:
break;
}
return PCIBIOS_SUCCESSFUL;
}
static inline struct mvebu_pcie *sys_to_pcie(struct pci_sys_data *sys)
{
return sys->private_data;
}
static struct mvebu_pcie_port *mvebu_pcie_find_port(struct mvebu_pcie *pcie,
struct pci_bus *bus,
int devfn)
{
int i;
for (i = 0; i < pcie->nports; i++) {
struct mvebu_pcie_port *port = &pcie->ports[i];
if (bus->number == 0 && port->devfn == devfn)
return port;
if (bus->number != 0 &&
bus->number >= port->bridge.secondary_bus &&
bus->number <= port->bridge.subordinate_bus)
return port;
}
return NULL;
}
static int mvebu_pcie_wr_conf(struct pci_bus *bus, u32 devfn,
int where, int size, u32 val)
{
struct mvebu_pcie *pcie = sys_to_pcie(bus->sysdata);
struct mvebu_pcie_port *port;
int ret;
port = mvebu_pcie_find_port(pcie, bus, devfn);
if (!port)
return PCIBIOS_DEVICE_NOT_FOUND;
if (bus->number == 0)
return mvebu_sw_pci_bridge_write(port, where, size, val);
if (!mvebu_pcie_link_up(port))
return PCIBIOS_DEVICE_NOT_FOUND;
ret = mvebu_pcie_hw_wr_conf(port, bus, devfn,
where, size, val);
return ret;
}
static int mvebu_pcie_rd_conf(struct pci_bus *bus, u32 devfn, int where,
int size, u32 *val)
{
struct mvebu_pcie *pcie = sys_to_pcie(bus->sysdata);
struct mvebu_pcie_port *port;
int ret;
port = mvebu_pcie_find_port(pcie, bus, devfn);
if (!port) {
*val = 0xffffffff;
return PCIBIOS_DEVICE_NOT_FOUND;
}
if (bus->number == 0)
return mvebu_sw_pci_bridge_read(port, where, size, val);
if (!mvebu_pcie_link_up(port)) {
*val = 0xffffffff;
return PCIBIOS_DEVICE_NOT_FOUND;
}
ret = mvebu_pcie_hw_rd_conf(port, bus, devfn,
where, size, val);
return ret;
}
static int mvebu_pcie_setup(int nr, struct pci_sys_data *sys)
{
struct mvebu_pcie *pcie = sys_to_pcie(sys);
int err, i;
pcie->mem.name = "PCI MEM";
pcie->realio.name = "PCI I/O";
if (resource_size(&pcie->realio) != 0)
pci_add_resource_offset(&sys->resources, &pcie->realio,
sys->io_offset);
pci_add_resource_offset(&sys->resources, &pcie->mem, sys->mem_offset);
pci_add_resource(&sys->resources, &pcie->busn);
err = devm_request_pci_bus_resources(&pcie->pdev->dev, &sys->resources);
if (err)
return 0;
for (i = 0; i < pcie->nports; i++) {
struct mvebu_pcie_port *port = &pcie->ports[i];
if (!port->base)
continue;
mvebu_pcie_setup_hw(port);
}
return 1;
}
static resource_size_t mvebu_pcie_align_resource(struct pci_dev *dev,
const struct resource *res,
resource_size_t start,
resource_size_t size,
resource_size_t align)
{
if (dev->bus->number != 0)
return start;
if (res->flags & IORESOURCE_IO)
return round_up(start, max_t(resource_size_t, SZ_64K,
rounddown_pow_of_two(size)));
else if (res->flags & IORESOURCE_MEM)
return round_up(start, max_t(resource_size_t, SZ_1M,
rounddown_pow_of_two(size)));
else
return start;
}
static void mvebu_pcie_enable(struct mvebu_pcie *pcie)
{
struct hw_pci hw;
memset(&hw, 0, sizeof(hw));
#ifdef CONFIG_PCI_MSI
hw.msi_ctrl = pcie->msi;
#endif
hw.nr_controllers = 1;
hw.private_data = (void **)&pcie;
hw.setup = mvebu_pcie_setup;
hw.map_irq = of_irq_parse_and_map_pci;
hw.ops = &mvebu_pcie_ops;
hw.align_resource = mvebu_pcie_align_resource;
pci_common_init_dev(&pcie->pdev->dev, &hw);
}
static void __iomem *mvebu_pcie_map_registers(struct platform_device *pdev,
struct device_node *np,
struct mvebu_pcie_port *port)
{
struct resource regs;
int ret = 0;
ret = of_address_to_resource(np, 0, &regs);
if (ret)
return ERR_PTR(ret);
return devm_ioremap_resource(&pdev->dev, &regs);
}
static int mvebu_get_tgt_attr(struct device_node *np, int devfn,
unsigned long type,
unsigned int *tgt,
unsigned int *attr)
{
const int na = 3, ns = 2;
const __be32 *range;
int rlen, nranges, rangesz, pna, i;
*tgt = -1;
*attr = -1;
range = of_get_property(np, "ranges", &rlen);
if (!range)
return -EINVAL;
pna = of_n_addr_cells(np);
rangesz = pna + na + ns;
nranges = rlen / sizeof(__be32) / rangesz;
for (i = 0; i < nranges; i++, range += rangesz) {
u32 flags = of_read_number(range, 1);
u32 slot = of_read_number(range + 1, 1);
u64 cpuaddr = of_read_number(range + na, pna);
unsigned long rtype;
if (DT_FLAGS_TO_TYPE(flags) == DT_TYPE_IO)
rtype = IORESOURCE_IO;
else if (DT_FLAGS_TO_TYPE(flags) == DT_TYPE_MEM32)
rtype = IORESOURCE_MEM;
else
continue;
if (slot == PCI_SLOT(devfn) && type == rtype) {
*tgt = DT_CPUADDR_TO_TARGET(cpuaddr);
*attr = DT_CPUADDR_TO_ATTR(cpuaddr);
return 0;
}
}
return -ENOENT;
}
static void mvebu_pcie_msi_enable(struct mvebu_pcie *pcie)
{
struct device_node *msi_node;
msi_node = of_parse_phandle(pcie->pdev->dev.of_node,
"msi-parent", 0);
if (!msi_node)
return;
pcie->msi = of_pci_find_msi_chip_by_node(msi_node);
of_node_put(msi_node);
if (pcie->msi)
pcie->msi->dev = &pcie->pdev->dev;
}
static int mvebu_pcie_suspend(struct device *dev)
{
struct mvebu_pcie *pcie;
int i;
pcie = dev_get_drvdata(dev);
for (i = 0; i < pcie->nports; i++) {
struct mvebu_pcie_port *port = pcie->ports + i;
port->saved_pcie_stat = mvebu_readl(port, PCIE_STAT_OFF);
}
return 0;
}
static int mvebu_pcie_resume(struct device *dev)
{
struct mvebu_pcie *pcie;
int i;
pcie = dev_get_drvdata(dev);
for (i = 0; i < pcie->nports; i++) {
struct mvebu_pcie_port *port = pcie->ports + i;
mvebu_writel(port, port->saved_pcie_stat, PCIE_STAT_OFF);
mvebu_pcie_setup_hw(port);
}
return 0;
}
static void mvebu_pcie_port_clk_put(void *data)
{
struct mvebu_pcie_port *port = data;
clk_put(port->clk);
}
static int mvebu_pcie_parse_port(struct mvebu_pcie *pcie,
struct mvebu_pcie_port *port, struct device_node *child)
{
struct device *dev = &pcie->pdev->dev;
enum of_gpio_flags flags;
int reset_gpio, ret;
port->pcie = pcie;
if (of_property_read_u32(child, "marvell,pcie-port", &port->port)) {
dev_warn(dev, "ignoring %s, missing pcie-port property\n",
of_node_full_name(child));
goto skip;
}
if (of_property_read_u32(child, "marvell,pcie-lane", &port->lane))
port->lane = 0;
port->name = devm_kasprintf(dev, GFP_KERNEL, "pcie%d.%d", port->port,
port->lane);
if (!port->name) {
ret = -ENOMEM;
goto err;
}
port->devfn = of_pci_get_devfn(child);
if (port->devfn < 0)
goto skip;
ret = mvebu_get_tgt_attr(dev->of_node, port->devfn, IORESOURCE_MEM,
&port->mem_target, &port->mem_attr);
if (ret < 0) {
dev_err(dev, "%s: cannot get tgt/attr for mem window\n",
port->name);
goto skip;
}
if (resource_size(&pcie->io) != 0) {
mvebu_get_tgt_attr(dev->of_node, port->devfn, IORESOURCE_IO,
&port->io_target, &port->io_attr);
} else {
port->io_target = -1;
port->io_attr = -1;
}
reset_gpio = of_get_named_gpio_flags(child, "reset-gpios", 0, &flags);
if (reset_gpio == -EPROBE_DEFER) {
ret = reset_gpio;
goto err;
}
if (gpio_is_valid(reset_gpio)) {
unsigned long gpio_flags;
port->reset_name = devm_kasprintf(dev, GFP_KERNEL, "%s-reset",
port->name);
if (!port->reset_name) {
ret = -ENOMEM;
goto err;
}
if (flags & OF_GPIO_ACTIVE_LOW) {
dev_info(dev, "%s: reset gpio is active low\n",
of_node_full_name(child));
gpio_flags = GPIOF_ACTIVE_LOW |
GPIOF_OUT_INIT_LOW;
} else {
gpio_flags = GPIOF_OUT_INIT_HIGH;
}
ret = devm_gpio_request_one(dev, reset_gpio, gpio_flags,
port->reset_name);
if (ret) {
if (ret == -EPROBE_DEFER)
goto err;
goto skip;
}
port->reset_gpio = gpio_to_desc(reset_gpio);
}
port->clk = of_clk_get_by_name(child, NULL);
if (IS_ERR(port->clk)) {
dev_err(dev, "%s: cannot get clock\n", port->name);
goto skip;
}
ret = devm_add_action(dev, mvebu_pcie_port_clk_put, port);
if (ret < 0) {
clk_put(port->clk);
goto err;
}
return 1;
skip:
ret = 0;
devm_kfree(dev, port->reset_name);
port->reset_name = NULL;
devm_kfree(dev, port->name);
port->name = NULL;
err:
return ret;
}
static int mvebu_pcie_powerup(struct mvebu_pcie_port *port)
{
int ret;
ret = clk_prepare_enable(port->clk);
if (ret < 0)
return ret;
if (port->reset_gpio) {
u32 reset_udelay = PCI_PM_D3COLD_WAIT * 1000;
of_property_read_u32(port->dn, "reset-delay-us",
&reset_udelay);
udelay(100);
gpiod_set_value_cansleep(port->reset_gpio, 0);
msleep(reset_udelay / 1000);
}
return 0;
}
static void mvebu_pcie_powerdown(struct mvebu_pcie_port *port)
{
if (port->reset_gpio)
gpiod_set_value_cansleep(port->reset_gpio, 1);
clk_disable_unprepare(port->clk);
}
static int mvebu_pcie_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct mvebu_pcie *pcie;
struct device_node *np = dev->of_node;
struct device_node *child;
int num, i, ret;
pcie = devm_kzalloc(dev, sizeof(*pcie), GFP_KERNEL);
if (!pcie)
return -ENOMEM;
pcie->pdev = pdev;
platform_set_drvdata(pdev, pcie);
mvebu_mbus_get_pcie_mem_aperture(&pcie->mem);
if (resource_size(&pcie->mem) == 0) {
dev_err(dev, "invalid memory aperture size\n");
return -EINVAL;
}
mvebu_mbus_get_pcie_io_aperture(&pcie->io);
if (resource_size(&pcie->io) != 0) {
pcie->realio.flags = pcie->io.flags;
pcie->realio.start = PCIBIOS_MIN_IO;
pcie->realio.end = min_t(resource_size_t,
IO_SPACE_LIMIT,
resource_size(&pcie->io));
} else
pcie->realio = pcie->io;
ret = of_pci_parse_bus_range(np, &pcie->busn);
if (ret) {
dev_err(dev, "failed to parse bus-range property: %d\n", ret);
return ret;
}
num = of_get_available_child_count(np);
pcie->ports = devm_kcalloc(dev, num, sizeof(*pcie->ports), GFP_KERNEL);
if (!pcie->ports)
return -ENOMEM;
i = 0;
for_each_available_child_of_node(np, child) {
struct mvebu_pcie_port *port = &pcie->ports[i];
ret = mvebu_pcie_parse_port(pcie, port, child);
if (ret < 0) {
of_node_put(child);
return ret;
} else if (ret == 0) {
continue;
}
port->dn = child;
i++;
}
pcie->nports = i;
for (i = 0; i < pcie->nports; i++) {
struct mvebu_pcie_port *port = &pcie->ports[i];
child = port->dn;
if (!child)
continue;
ret = mvebu_pcie_powerup(port);
if (ret < 0)
continue;
port->base = mvebu_pcie_map_registers(pdev, child, port);
if (IS_ERR(port->base)) {
dev_err(dev, "%s: cannot map registers\n", port->name);
port->base = NULL;
mvebu_pcie_powerdown(port);
continue;
}
mvebu_pcie_set_local_dev_nr(port, 1);
mvebu_sw_pci_bridge_init(port);
}
pcie->nports = i;
for (i = 0; i < (IO_SPACE_LIMIT - SZ_64K); i += SZ_64K)
pci_ioremap_io(i, pcie->io.start + i);
mvebu_pcie_msi_enable(pcie);
mvebu_pcie_enable(pcie);
platform_set_drvdata(pdev, pcie);
return 0;
}
