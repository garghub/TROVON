static inline struct rcar_msi *to_rcar_msi(struct msi_controller *chip)
{
return container_of(chip, struct rcar_msi, chip);
}
static void rcar_pci_write_reg(struct rcar_pcie *pcie, unsigned long val,
unsigned long reg)
{
writel(val, pcie->base + reg);
}
static unsigned long rcar_pci_read_reg(struct rcar_pcie *pcie,
unsigned long reg)
{
return readl(pcie->base + reg);
}
static void rcar_rmw32(struct rcar_pcie *pcie, int where, u32 mask, u32 data)
{
int shift = 8 * (where & 3);
u32 val = rcar_pci_read_reg(pcie, where & ~3);
val &= ~(mask << shift);
val |= data << shift;
rcar_pci_write_reg(pcie, val, where & ~3);
}
static u32 rcar_read_conf(struct rcar_pcie *pcie, int where)
{
int shift = 8 * (where & 3);
u32 val = rcar_pci_read_reg(pcie, where & ~3);
return val >> shift;
}
static int rcar_pcie_config_access(struct rcar_pcie *pcie,
unsigned char access_type, struct pci_bus *bus,
unsigned int devfn, int where, u32 *data)
{
int dev, func, reg, index;
dev = PCI_SLOT(devfn);
func = PCI_FUNC(devfn);
reg = where & ~3;
index = reg / 4;
if (pci_is_root_bus(bus)) {
if (dev != 0)
return PCIBIOS_DEVICE_NOT_FOUND;
if (access_type == RCAR_PCI_ACCESS_READ) {
*data = rcar_pci_read_reg(pcie, PCICONF(index));
} else {
if (pci_is_root_bus(bus) && (reg == PCI_PRIMARY_BUS))
pcie->root_bus_nr = *data & 0xff;
rcar_pci_write_reg(pcie, *data, PCICONF(index));
}
return PCIBIOS_SUCCESSFUL;
}
if (pcie->root_bus_nr < 0)
return PCIBIOS_DEVICE_NOT_FOUND;
rcar_pci_write_reg(pcie, rcar_pci_read_reg(pcie, PCIEERRFR), PCIEERRFR);
rcar_pci_write_reg(pcie, PCIE_CONF_BUS(bus->number) |
PCIE_CONF_DEV(dev) | PCIE_CONF_FUNC(func) | reg, PCIECAR);
if (bus->parent->number == pcie->root_bus_nr)
rcar_pci_write_reg(pcie, CONFIG_SEND_ENABLE | TYPE0, PCIECCTLR);
else
rcar_pci_write_reg(pcie, CONFIG_SEND_ENABLE | TYPE1, PCIECCTLR);
if (rcar_pci_read_reg(pcie, PCIEERRFR) & UNSUPPORTED_REQUEST)
return PCIBIOS_DEVICE_NOT_FOUND;
if (rcar_read_conf(pcie, RCONF(PCI_STATUS)) &
(PCI_STATUS_REC_MASTER_ABORT | PCI_STATUS_REC_TARGET_ABORT))
return PCIBIOS_DEVICE_NOT_FOUND;
if (access_type == RCAR_PCI_ACCESS_READ)
*data = rcar_pci_read_reg(pcie, PCIECDR);
else
rcar_pci_write_reg(pcie, *data, PCIECDR);
rcar_pci_write_reg(pcie, 0, PCIECCTLR);
return PCIBIOS_SUCCESSFUL;
}
static int rcar_pcie_read_conf(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 *val)
{
struct rcar_pcie *pcie = bus->sysdata;
int ret;
ret = rcar_pcie_config_access(pcie, RCAR_PCI_ACCESS_READ,
bus, devfn, where, val);
if (ret != PCIBIOS_SUCCESSFUL) {
*val = 0xffffffff;
return ret;
}
if (size == 1)
*val = (*val >> (8 * (where & 3))) & 0xff;
else if (size == 2)
*val = (*val >> (8 * (where & 2))) & 0xffff;
dev_dbg(&bus->dev, "pcie-config-read: bus=%3d devfn=0x%04x where=0x%04x size=%d val=0x%08lx\n",
bus->number, devfn, where, size, (unsigned long)*val);
return ret;
}
static int rcar_pcie_write_conf(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 val)
{
struct rcar_pcie *pcie = bus->sysdata;
int shift, ret;
u32 data;
ret = rcar_pcie_config_access(pcie, RCAR_PCI_ACCESS_READ,
bus, devfn, where, &data);
if (ret != PCIBIOS_SUCCESSFUL)
return ret;
dev_dbg(&bus->dev, "pcie-config-write: bus=%3d devfn=0x%04x where=0x%04x size=%d val=0x%08lx\n",
bus->number, devfn, where, size, (unsigned long)val);
if (size == 1) {
shift = 8 * (where & 3);
data &= ~(0xff << shift);
data |= ((val & 0xff) << shift);
} else if (size == 2) {
shift = 8 * (where & 2);
data &= ~(0xffff << shift);
data |= ((val & 0xffff) << shift);
} else
data = val;
ret = rcar_pcie_config_access(pcie, RCAR_PCI_ACCESS_WRITE,
bus, devfn, where, &data);
return ret;
}
static void rcar_pcie_setup_window(int win, struct rcar_pcie *pcie)
{
struct resource *res = &pcie->res[win];
resource_size_t size;
resource_size_t res_start;
u32 mask;
rcar_pci_write_reg(pcie, 0x00000000, PCIEPTCTLR(win));
size = resource_size(res);
mask = (roundup_pow_of_two(size) / SZ_128) - 1;
rcar_pci_write_reg(pcie, mask << 7, PCIEPAMR(win));
if (res->flags & IORESOURCE_IO)
res_start = pci_pio_to_address(res->start);
else
res_start = res->start;
rcar_pci_write_reg(pcie, upper_32_bits(res_start), PCIEPAUR(win));
rcar_pci_write_reg(pcie, lower_32_bits(res_start) & ~0x7F,
PCIEPALR(win));
mask = PAR_ENABLE;
if (res->flags & IORESOURCE_IO)
mask |= IO_SPACE;
rcar_pci_write_reg(pcie, mask, PCIEPTCTLR(win));
}
static int rcar_pcie_setup(struct list_head *resource, struct rcar_pcie *pcie)
{
struct resource *res;
int i;
pcie->root_bus_nr = pcie->busn.start;
for (i = 0; i < RCAR_PCI_MAX_RESOURCES; i++) {
res = &pcie->res[i];
if (!res->flags)
continue;
rcar_pcie_setup_window(i, pcie);
if (res->flags & IORESOURCE_IO) {
phys_addr_t io_start = pci_pio_to_address(res->start);
pci_ioremap_io(global_io_offset, io_start);
global_io_offset += SZ_64K;
}
pci_add_resource(resource, res);
}
pci_add_resource(resource, &pcie->busn);
return 1;
}
static int rcar_pcie_enable(struct rcar_pcie *pcie)
{
struct pci_bus *bus, *child;
LIST_HEAD(res);
rcar_pcie_setup(&res, pcie);
if (!pci_has_flag(PCI_PROBE_ONLY))
pci_add_flags(PCI_REASSIGN_ALL_RSRC | PCI_REASSIGN_ALL_BUS);
if (IS_ENABLED(CONFIG_PCI_MSI))
bus = pci_scan_root_bus_msi(pcie->dev, pcie->root_bus_nr,
&rcar_pcie_ops, pcie, &res, &pcie->msi.chip);
else
bus = pci_scan_root_bus(pcie->dev, pcie->root_bus_nr,
&rcar_pcie_ops, pcie, &res);
if (!bus) {
dev_err(pcie->dev, "Scanning rootbus failed");
return -ENODEV;
}
pci_fixup_irqs(pci_common_swizzle, of_irq_parse_and_map_pci);
if (!pci_has_flag(PCI_PROBE_ONLY)) {
pci_bus_size_bridges(bus);
pci_bus_assign_resources(bus);
list_for_each_entry(child, &bus->children, node)
pcie_bus_configure_settings(child);
}
pci_bus_add_devices(bus);
return 0;
}
static int phy_wait_for_ack(struct rcar_pcie *pcie)
{
unsigned int timeout = 100;
while (timeout--) {
if (rcar_pci_read_reg(pcie, H1_PCIEPHYADRR) & PHY_ACK)
return 0;
udelay(100);
}
dev_err(pcie->dev, "Access to PCIe phy timed out\n");
return -ETIMEDOUT;
}
static void phy_write_reg(struct rcar_pcie *pcie,
unsigned int rate, unsigned int addr,
unsigned int lane, unsigned int data)
{
unsigned long phyaddr;
phyaddr = WRITE_CMD |
((rate & 1) << RATE_POS) |
((lane & 0xf) << LANE_POS) |
((addr & 0xff) << ADR_POS);
rcar_pci_write_reg(pcie, data, H1_PCIEPHYDOUTR);
rcar_pci_write_reg(pcie, phyaddr, H1_PCIEPHYADRR);
phy_wait_for_ack(pcie);
rcar_pci_write_reg(pcie, 0, H1_PCIEPHYDOUTR);
rcar_pci_write_reg(pcie, 0, H1_PCIEPHYADRR);
phy_wait_for_ack(pcie);
}
static int rcar_pcie_wait_for_dl(struct rcar_pcie *pcie)
{
unsigned int timeout = 10;
while (timeout--) {
if ((rcar_pci_read_reg(pcie, PCIETSTR) & DATA_LINK_ACTIVE))
return 0;
msleep(5);
}
return -ETIMEDOUT;
}
static int rcar_pcie_hw_init(struct rcar_pcie *pcie)
{
int err;
rcar_pci_write_reg(pcie, 0, PCIETCTLR);
rcar_pci_write_reg(pcie, 1, PCIEMSR);
rcar_pci_write_reg(pcie, PCI_CLASS_BRIDGE_PCI << 16, IDSETR1);
rcar_rmw32(pcie, RCONF(PCI_SECONDARY_BUS), 0xff, 1);
rcar_rmw32(pcie, RCONF(PCI_SUBORDINATE_BUS), 0xff, 1);
rcar_rmw32(pcie, REXPCAP(0), 0xff, PCI_CAP_ID_EXP);
rcar_rmw32(pcie, REXPCAP(PCI_EXP_FLAGS),
PCI_EXP_FLAGS_TYPE, PCI_EXP_TYPE_ROOT_PORT << 4);
rcar_rmw32(pcie, RCONF(PCI_HEADER_TYPE), 0x7f,
PCI_HEADER_TYPE_BRIDGE);
rcar_rmw32(pcie, REXPCAP(PCI_EXP_LNKCAP), PCI_EXP_LNKCAP_DLLLARC,
PCI_EXP_LNKCAP_DLLLARC);
rcar_rmw32(pcie, REXPCAP(PCI_EXP_SLTCAP), PCI_EXP_SLTCAP_PSN, 0);
rcar_rmw32(pcie, TLCTLR + 1, 0x3f, 50);
rcar_rmw32(pcie, RVCCAP(0), 0xfff00000, 0);
if (IS_ENABLED(CONFIG_PCI_MSI))
rcar_pci_write_reg(pcie, 0x801f0000, PCIEMSITXR);
rcar_pci_write_reg(pcie, CFINIT, PCIETCTLR);
err = rcar_pcie_wait_for_dl(pcie);
if (err)
return err;
rcar_rmw32(pcie, PCIEINTXR, 0, 0xF << 8);
wmb();
return 0;
}
static int rcar_pcie_hw_init_h1(struct rcar_pcie *pcie)
{
unsigned int timeout = 10;
phy_write_reg(pcie, 0, 0x42, 0x1, 0x0EC34191);
phy_write_reg(pcie, 1, 0x42, 0x1, 0x0EC34180);
phy_write_reg(pcie, 0, 0x43, 0x1, 0x00210188);
phy_write_reg(pcie, 1, 0x43, 0x1, 0x00210188);
phy_write_reg(pcie, 0, 0x44, 0x1, 0x015C0014);
phy_write_reg(pcie, 1, 0x44, 0x1, 0x015C0014);
phy_write_reg(pcie, 1, 0x4C, 0x1, 0x786174A0);
phy_write_reg(pcie, 1, 0x4D, 0x1, 0x048000BB);
phy_write_reg(pcie, 0, 0x51, 0x1, 0x079EC062);
phy_write_reg(pcie, 0, 0x52, 0x1, 0x20000000);
phy_write_reg(pcie, 1, 0x52, 0x1, 0x20000000);
phy_write_reg(pcie, 1, 0x56, 0x1, 0x00003806);
phy_write_reg(pcie, 0, 0x60, 0x1, 0x004B03A5);
phy_write_reg(pcie, 0, 0x64, 0x1, 0x3F0F1F0F);
phy_write_reg(pcie, 0, 0x66, 0x1, 0x00008000);
while (timeout--) {
if (rcar_pci_read_reg(pcie, H1_PCIEPHYSR))
return rcar_pcie_hw_init(pcie);
msleep(5);
}
return -ETIMEDOUT;
}
static int rcar_msi_alloc(struct rcar_msi *chip)
{
int msi;
mutex_lock(&chip->lock);
msi = find_first_zero_bit(chip->used, INT_PCI_MSI_NR);
if (msi < INT_PCI_MSI_NR)
set_bit(msi, chip->used);
else
msi = -ENOSPC;
mutex_unlock(&chip->lock);
return msi;
}
static void rcar_msi_free(struct rcar_msi *chip, unsigned long irq)
{
mutex_lock(&chip->lock);
clear_bit(irq, chip->used);
mutex_unlock(&chip->lock);
}
static irqreturn_t rcar_pcie_msi_irq(int irq, void *data)
{
struct rcar_pcie *pcie = data;
struct rcar_msi *msi = &pcie->msi;
unsigned long reg;
reg = rcar_pci_read_reg(pcie, PCIEMSIFR);
if (!reg)
return IRQ_NONE;
while (reg) {
unsigned int index = find_first_bit(&reg, 32);
unsigned int irq;
rcar_pci_write_reg(pcie, 1 << index, PCIEMSIFR);
irq = irq_find_mapping(msi->domain, index);
if (irq) {
if (test_bit(index, msi->used))
generic_handle_irq(irq);
else
dev_info(pcie->dev, "unhandled MSI\n");
} else {
dev_dbg(pcie->dev, "unexpected MSI\n");
}
reg = rcar_pci_read_reg(pcie, PCIEMSIFR);
}
return IRQ_HANDLED;
}
static int rcar_msi_setup_irq(struct msi_controller *chip, struct pci_dev *pdev,
struct msi_desc *desc)
{
struct rcar_msi *msi = to_rcar_msi(chip);
struct rcar_pcie *pcie = container_of(chip, struct rcar_pcie, msi.chip);
struct msi_msg msg;
unsigned int irq;
int hwirq;
hwirq = rcar_msi_alloc(msi);
if (hwirq < 0)
return hwirq;
irq = irq_create_mapping(msi->domain, hwirq);
if (!irq) {
rcar_msi_free(msi, hwirq);
return -EINVAL;
}
irq_set_msi_desc(irq, desc);
msg.address_lo = rcar_pci_read_reg(pcie, PCIEMSIALR) & ~MSIFE;
msg.address_hi = rcar_pci_read_reg(pcie, PCIEMSIAUR);
msg.data = hwirq;
pci_write_msi_msg(irq, &msg);
return 0;
}
static void rcar_msi_teardown_irq(struct msi_controller *chip, unsigned int irq)
{
struct rcar_msi *msi = to_rcar_msi(chip);
struct irq_data *d = irq_get_irq_data(irq);
rcar_msi_free(msi, d->hwirq);
}
static int rcar_msi_map(struct irq_domain *domain, unsigned int irq,
irq_hw_number_t hwirq)
{
irq_set_chip_and_handler(irq, &rcar_msi_irq_chip, handle_simple_irq);
irq_set_chip_data(irq, domain->host_data);
return 0;
}
static int rcar_pcie_enable_msi(struct rcar_pcie *pcie)
{
struct platform_device *pdev = to_platform_device(pcie->dev);
struct rcar_msi *msi = &pcie->msi;
unsigned long base;
int err;
mutex_init(&msi->lock);
msi->chip.dev = pcie->dev;
msi->chip.setup_irq = rcar_msi_setup_irq;
msi->chip.teardown_irq = rcar_msi_teardown_irq;
msi->domain = irq_domain_add_linear(pcie->dev->of_node, INT_PCI_MSI_NR,
&msi_domain_ops, &msi->chip);
if (!msi->domain) {
dev_err(&pdev->dev, "failed to create IRQ domain\n");
return -ENOMEM;
}
err = devm_request_irq(&pdev->dev, msi->irq1, rcar_pcie_msi_irq,
IRQF_SHARED, rcar_msi_irq_chip.name, pcie);
if (err < 0) {
dev_err(&pdev->dev, "failed to request IRQ: %d\n", err);
goto err;
}
err = devm_request_irq(&pdev->dev, msi->irq2, rcar_pcie_msi_irq,
IRQF_SHARED, rcar_msi_irq_chip.name, pcie);
if (err < 0) {
dev_err(&pdev->dev, "failed to request IRQ: %d\n", err);
goto err;
}
msi->pages = __get_free_pages(GFP_KERNEL, 0);
base = virt_to_phys((void *)msi->pages);
rcar_pci_write_reg(pcie, base | MSIFE, PCIEMSIALR);
rcar_pci_write_reg(pcie, 0, PCIEMSIAUR);
rcar_pci_write_reg(pcie, 0xffffffff, PCIEMSIIER);
return 0;
err:
irq_domain_remove(msi->domain);
return err;
}
static int rcar_pcie_get_resources(struct platform_device *pdev,
struct rcar_pcie *pcie)
{
struct resource res;
int err, i;
err = of_address_to_resource(pdev->dev.of_node, 0, &res);
if (err)
return err;
pcie->clk = devm_clk_get(&pdev->dev, "pcie");
if (IS_ERR(pcie->clk)) {
dev_err(pcie->dev, "cannot get platform clock\n");
return PTR_ERR(pcie->clk);
}
err = clk_prepare_enable(pcie->clk);
if (err)
goto fail_clk;
pcie->bus_clk = devm_clk_get(&pdev->dev, "pcie_bus");
if (IS_ERR(pcie->bus_clk)) {
dev_err(pcie->dev, "cannot get pcie bus clock\n");
err = PTR_ERR(pcie->bus_clk);
goto fail_clk;
}
err = clk_prepare_enable(pcie->bus_clk);
if (err)
goto err_map_reg;
i = irq_of_parse_and_map(pdev->dev.of_node, 0);
if (!i) {
dev_err(pcie->dev, "cannot get platform resources for msi interrupt\n");
err = -ENOENT;
goto err_map_reg;
}
pcie->msi.irq1 = i;
i = irq_of_parse_and_map(pdev->dev.of_node, 1);
if (!i) {
dev_err(pcie->dev, "cannot get platform resources for msi interrupt\n");
err = -ENOENT;
goto err_map_reg;
}
pcie->msi.irq2 = i;
pcie->base = devm_ioremap_resource(&pdev->dev, &res);
if (IS_ERR(pcie->base)) {
err = PTR_ERR(pcie->base);
goto err_map_reg;
}
return 0;
err_map_reg:
clk_disable_unprepare(pcie->bus_clk);
fail_clk:
clk_disable_unprepare(pcie->clk);
return err;
}
static int rcar_pcie_inbound_ranges(struct rcar_pcie *pcie,
struct of_pci_range *range,
int *index)
{
u64 restype = range->flags;
u64 cpu_addr = range->cpu_addr;
u64 cpu_end = range->cpu_addr + range->size;
u64 pci_addr = range->pci_addr;
u32 flags = LAM_64BIT | LAR_ENABLE;
u64 mask;
u64 size;
int idx = *index;
if (restype & IORESOURCE_PREFETCH)
flags |= LAM_PREFETCH;
if (cpu_addr > 0) {
unsigned long nr_zeros = __ffs64(cpu_addr);
u64 alignment = 1ULL << nr_zeros;
size = min(range->size, alignment);
} else {
size = range->size;
}
size = min(size, 1ULL << 32);
mask = roundup_pow_of_two(size) - 1;
mask &= ~0xf;
while (cpu_addr < cpu_end) {
rcar_pci_write_reg(pcie, lower_32_bits(pci_addr), PCIEPRAR(idx));
rcar_pci_write_reg(pcie, lower_32_bits(cpu_addr), PCIELAR(idx));
rcar_pci_write_reg(pcie, lower_32_bits(mask) | flags, PCIELAMR(idx));
rcar_pci_write_reg(pcie, upper_32_bits(pci_addr), PCIEPRAR(idx+1));
rcar_pci_write_reg(pcie, upper_32_bits(cpu_addr), PCIELAR(idx+1));
rcar_pci_write_reg(pcie, 0, PCIELAMR(idx + 1));
pci_addr += size;
cpu_addr += size;
idx += 2;
if (idx > MAX_NR_INBOUND_MAPS) {
dev_err(pcie->dev, "Failed to map inbound regions!\n");
return -EINVAL;
}
}
*index = idx;
return 0;
}
static int pci_dma_range_parser_init(struct of_pci_range_parser *parser,
struct device_node *node)
{
const int na = 3, ns = 2;
int rlen;
parser->node = node;
parser->pna = of_n_addr_cells(node);
parser->np = parser->pna + na + ns;
parser->range = of_get_property(node, "dma-ranges", &rlen);
if (!parser->range)
return -ENOENT;
parser->end = parser->range + rlen / sizeof(__be32);
return 0;
}
static int rcar_pcie_parse_map_dma_ranges(struct rcar_pcie *pcie,
struct device_node *np)
{
struct of_pci_range range;
struct of_pci_range_parser parser;
int index = 0;
int err;
if (pci_dma_range_parser_init(&parser, np))
return -EINVAL;
for_each_of_pci_range(&parser, &range) {
u64 end = range.cpu_addr + range.size - 1;
dev_dbg(pcie->dev, "0x%08x 0x%016llx..0x%016llx -> 0x%016llx\n",
range.flags, range.cpu_addr, end, range.pci_addr);
err = rcar_pcie_inbound_ranges(pcie, &range, &index);
if (err)
return err;
}
return 0;
}
static int rcar_pcie_probe(struct platform_device *pdev)
{
struct rcar_pcie *pcie;
unsigned int data;
struct of_pci_range range;
struct of_pci_range_parser parser;
const struct of_device_id *of_id;
int err, win = 0;
int (*hw_init_fn)(struct rcar_pcie *);
pcie = devm_kzalloc(&pdev->dev, sizeof(*pcie), GFP_KERNEL);
if (!pcie)
return -ENOMEM;
pcie->dev = &pdev->dev;
platform_set_drvdata(pdev, pcie);
if (of_pci_parse_bus_range(pdev->dev.of_node, &pcie->busn)) {
dev_err(&pdev->dev, "failed to parse bus-range property\n");
return -EINVAL;
}
if (of_pci_range_parser_init(&parser, pdev->dev.of_node)) {
dev_err(&pdev->dev, "missing ranges property\n");
return -EINVAL;
}
err = rcar_pcie_get_resources(pdev, pcie);
if (err < 0) {
dev_err(&pdev->dev, "failed to request resources: %d\n", err);
return err;
}
for_each_of_pci_range(&parser, &range) {
err = of_pci_range_to_resource(&range, pdev->dev.of_node,
&pcie->res[win++]);
if (err < 0)
return err;
if (win > RCAR_PCI_MAX_RESOURCES)
break;
}
err = rcar_pcie_parse_map_dma_ranges(pcie, pdev->dev.of_node);
if (err)
return err;
if (IS_ENABLED(CONFIG_PCI_MSI)) {
err = rcar_pcie_enable_msi(pcie);
if (err < 0) {
dev_err(&pdev->dev,
"failed to enable MSI support: %d\n",
err);
return err;
}
}
of_id = of_match_device(rcar_pcie_of_match, pcie->dev);
if (!of_id || !of_id->data)
return -EINVAL;
hw_init_fn = of_id->data;
err = hw_init_fn(pcie);
if (err) {
dev_info(&pdev->dev, "PCIe link down\n");
return 0;
}
data = rcar_pci_read_reg(pcie, MACSR);
dev_info(&pdev->dev, "PCIe x%d: link up\n", (data >> 20) & 0x3f);
return rcar_pcie_enable(pcie);
}
