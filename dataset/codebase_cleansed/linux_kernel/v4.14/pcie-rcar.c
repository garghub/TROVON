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
static void rcar_pcie_setup_window(int win, struct rcar_pcie *pcie,
struct resource *res)
{
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
static int rcar_pcie_setup(struct list_head *resource, struct rcar_pcie *pci)
{
struct resource_entry *win;
int i = 0;
resource_list_for_each_entry(win, &pci->resources) {
struct resource *res = win->res;
if (!res->flags)
continue;
switch (resource_type(res)) {
case IORESOURCE_IO:
case IORESOURCE_MEM:
rcar_pcie_setup_window(i, pci, res);
i++;
break;
case IORESOURCE_BUS:
pci->root_bus_nr = res->start;
break;
default:
continue;
}
pci_add_resource(resource, res);
}
return 1;
}
static void rcar_pcie_force_speedup(struct rcar_pcie *pcie)
{
struct device *dev = pcie->dev;
unsigned int timeout = 1000;
u32 macsr;
if ((rcar_pci_read_reg(pcie, MACS2R) & LINK_SPEED) != LINK_SPEED_5_0GTS)
return;
if (rcar_pci_read_reg(pcie, MACCTLR) & SPEED_CHANGE) {
dev_err(dev, "Speed change already in progress\n");
return;
}
macsr = rcar_pci_read_reg(pcie, MACSR);
if ((macsr & LINK_SPEED) == LINK_SPEED_5_0GTS)
goto done;
rcar_rmw32(pcie, EXPCAP(12), PCI_EXP_LNKSTA_CLS,
PCI_EXP_LNKSTA_CLS_5_0GB);
rcar_rmw32(pcie, MACCGSPSETR, SPCNGRSN, 0);
if (macsr & (SPCHGFIN | SPCHGSUC | SPCHGFAIL))
rcar_pci_write_reg(pcie, macsr, MACSR);
rcar_rmw32(pcie, MACCTLR, SPEED_CHANGE, SPEED_CHANGE);
while (timeout--) {
macsr = rcar_pci_read_reg(pcie, MACSR);
if (macsr & SPCHGFIN) {
rcar_pci_write_reg(pcie, macsr, MACSR);
if (macsr & SPCHGFAIL)
dev_err(dev, "Speed change failed\n");
goto done;
}
msleep(1);
};
dev_err(dev, "Speed change timed out\n");
done:
dev_info(dev, "Current link speed is %s GT/s\n",
(macsr & LINK_SPEED) == LINK_SPEED_5_0GTS ? "5" : "2.5");
}
static int rcar_pcie_enable(struct rcar_pcie *pcie)
{
struct device *dev = pcie->dev;
struct pci_host_bridge *bridge = pci_host_bridge_from_priv(pcie);
struct pci_bus *bus, *child;
int ret;
rcar_pcie_force_speedup(pcie);
rcar_pcie_setup(&bridge->windows, pcie);
pci_add_flags(PCI_REASSIGN_ALL_RSRC | PCI_REASSIGN_ALL_BUS);
bridge->dev.parent = dev;
bridge->sysdata = pcie;
bridge->busnr = pcie->root_bus_nr;
bridge->ops = &rcar_pcie_ops;
bridge->map_irq = of_irq_parse_and_map_pci;
bridge->swizzle_irq = pci_common_swizzle;
if (IS_ENABLED(CONFIG_PCI_MSI))
bridge->msi = &pcie->msi.chip;
ret = pci_scan_root_bus_bridge(bridge);
if (ret < 0)
return ret;
bus = bridge->bus;
pci_bus_size_bridges(bus);
pci_bus_assign_resources(bus);
list_for_each_entry(child, &bus->children, node)
pcie_bus_configure_settings(child);
pci_bus_add_devices(bus);
return 0;
}
static int phy_wait_for_ack(struct rcar_pcie *pcie)
{
struct device *dev = pcie->dev;
unsigned int timeout = 100;
while (timeout--) {
if (rcar_pci_read_reg(pcie, H1_PCIEPHYADRR) & PHY_ACK)
return 0;
udelay(100);
}
dev_err(dev, "Access to PCIe phy timed out\n");
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
static int rcar_pcie_hw_init_gen2(struct rcar_pcie *pcie)
{
rcar_pci_write_reg(pcie, 0x000f0030, GEN2_PCIEPHYADDR);
rcar_pci_write_reg(pcie, 0x00381203, GEN2_PCIEPHYDATA);
rcar_pci_write_reg(pcie, 0x00000001, GEN2_PCIEPHYCTRL);
rcar_pci_write_reg(pcie, 0x00000006, GEN2_PCIEPHYCTRL);
rcar_pci_write_reg(pcie, 0x000f0054, GEN2_PCIEPHYADDR);
rcar_pci_write_reg(pcie, 0x13802007, GEN2_PCIEPHYDATA);
rcar_pci_write_reg(pcie, 0x00000001, GEN2_PCIEPHYCTRL);
rcar_pci_write_reg(pcie, 0x00000006, GEN2_PCIEPHYCTRL);
return rcar_pcie_hw_init(pcie);
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
static int rcar_msi_alloc_region(struct rcar_msi *chip, int no_irqs)
{
int msi;
mutex_lock(&chip->lock);
msi = bitmap_find_free_region(chip->used, INT_PCI_MSI_NR,
order_base_2(no_irqs));
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
struct device *dev = pcie->dev;
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
dev_info(dev, "unhandled MSI\n");
} else {
dev_dbg(dev, "unexpected MSI\n");
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
irq = irq_find_mapping(msi->domain, hwirq);
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
static int rcar_msi_setup_irqs(struct msi_controller *chip,
struct pci_dev *pdev, int nvec, int type)
{
struct rcar_pcie *pcie = container_of(chip, struct rcar_pcie, msi.chip);
struct rcar_msi *msi = to_rcar_msi(chip);
struct msi_desc *desc;
struct msi_msg msg;
unsigned int irq;
int hwirq;
int i;
if (type == PCI_CAP_ID_MSIX)
return -EINVAL;
WARN_ON(!list_is_singular(&pdev->dev.msi_list));
desc = list_entry(pdev->dev.msi_list.next, struct msi_desc, list);
hwirq = rcar_msi_alloc_region(msi, nvec);
if (hwirq < 0)
return -ENOSPC;
irq = irq_find_mapping(msi->domain, hwirq);
if (!irq)
return -ENOSPC;
for (i = 0; i < nvec; i++) {
if (irq_set_msi_desc_off(irq, i, desc)) {
return -EINVAL;
}
}
desc->nvec_used = nvec;
desc->msi_attrib.multiple = order_base_2(nvec);
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
struct device *dev = pcie->dev;
struct rcar_msi *msi = &pcie->msi;
unsigned long base;
int err, i;
mutex_init(&msi->lock);
msi->chip.dev = dev;
msi->chip.setup_irq = rcar_msi_setup_irq;
msi->chip.setup_irqs = rcar_msi_setup_irqs;
msi->chip.teardown_irq = rcar_msi_teardown_irq;
msi->domain = irq_domain_add_linear(dev->of_node, INT_PCI_MSI_NR,
&msi_domain_ops, &msi->chip);
if (!msi->domain) {
dev_err(dev, "failed to create IRQ domain\n");
return -ENOMEM;
}
for (i = 0; i < INT_PCI_MSI_NR; i++)
irq_create_mapping(msi->domain, i);
err = devm_request_irq(dev, msi->irq1, rcar_pcie_msi_irq,
IRQF_SHARED | IRQF_NO_THREAD,
rcar_msi_irq_chip.name, pcie);
if (err < 0) {
dev_err(dev, "failed to request IRQ: %d\n", err);
goto err;
}
err = devm_request_irq(dev, msi->irq2, rcar_pcie_msi_irq,
IRQF_SHARED | IRQF_NO_THREAD,
rcar_msi_irq_chip.name, pcie);
if (err < 0) {
dev_err(dev, "failed to request IRQ: %d\n", err);
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
static int rcar_pcie_get_resources(struct rcar_pcie *pcie)
{
struct device *dev = pcie->dev;
struct resource res;
int err, i;
err = of_address_to_resource(dev->of_node, 0, &res);
if (err)
return err;
pcie->base = devm_ioremap_resource(dev, &res);
if (IS_ERR(pcie->base))
return PTR_ERR(pcie->base);
pcie->clk = devm_clk_get(dev, "pcie");
if (IS_ERR(pcie->clk)) {
dev_err(dev, "cannot get platform clock\n");
return PTR_ERR(pcie->clk);
}
err = clk_prepare_enable(pcie->clk);
if (err)
return err;
pcie->bus_clk = devm_clk_get(dev, "pcie_bus");
if (IS_ERR(pcie->bus_clk)) {
dev_err(dev, "cannot get pcie bus clock\n");
err = PTR_ERR(pcie->bus_clk);
goto fail_clk;
}
err = clk_prepare_enable(pcie->bus_clk);
if (err)
goto fail_clk;
i = irq_of_parse_and_map(dev->of_node, 0);
if (!i) {
dev_err(dev, "cannot get platform resources for msi interrupt\n");
err = -ENOENT;
goto err_map_reg;
}
pcie->msi.irq1 = i;
i = irq_of_parse_and_map(dev->of_node, 1);
if (!i) {
dev_err(dev, "cannot get platform resources for msi interrupt\n");
err = -ENOENT;
goto err_map_reg;
}
pcie->msi.irq2 = i;
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
rcar_pci_write_reg(pcie, lower_32_bits(pci_addr),
PCIEPRAR(idx));
rcar_pci_write_reg(pcie, lower_32_bits(cpu_addr), PCIELAR(idx));
rcar_pci_write_reg(pcie, lower_32_bits(mask) | flags,
PCIELAMR(idx));
rcar_pci_write_reg(pcie, upper_32_bits(pci_addr),
PCIEPRAR(idx + 1));
rcar_pci_write_reg(pcie, upper_32_bits(cpu_addr),
PCIELAR(idx + 1));
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
static int rcar_pcie_parse_request_of_pci_ranges(struct rcar_pcie *pci)
{
int err;
struct device *dev = pci->dev;
struct device_node *np = dev->of_node;
resource_size_t iobase;
struct resource_entry *win, *tmp;
err = of_pci_get_host_bridge_resources(np, 0, 0xff, &pci->resources,
&iobase);
if (err)
return err;
err = devm_request_pci_bus_resources(dev, &pci->resources);
if (err)
goto out_release_res;
resource_list_for_each_entry_safe(win, tmp, &pci->resources) {
struct resource *res = win->res;
if (resource_type(res) == IORESOURCE_IO) {
err = pci_remap_iospace(res, iobase);
if (err) {
dev_warn(dev, "error %d: failed to map resource %pR\n",
err, res);
resource_list_destroy_entry(win);
}
}
}
return 0;
out_release_res:
pci_free_resource_list(&pci->resources);
return err;
}
static int rcar_pcie_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct rcar_pcie *pcie;
unsigned int data;
int err;
int (*hw_init_fn)(struct rcar_pcie *);
struct pci_host_bridge *bridge;
bridge = pci_alloc_host_bridge(sizeof(*pcie));
if (!bridge)
return -ENOMEM;
pcie = pci_host_bridge_priv(bridge);
pcie->dev = dev;
INIT_LIST_HEAD(&pcie->resources);
rcar_pcie_parse_request_of_pci_ranges(pcie);
err = rcar_pcie_get_resources(pcie);
if (err < 0) {
dev_err(dev, "failed to request resources: %d\n", err);
goto err_free_bridge;
}
err = rcar_pcie_parse_map_dma_ranges(pcie, dev->of_node);
if (err)
goto err_free_bridge;
pm_runtime_enable(dev);
err = pm_runtime_get_sync(dev);
if (err < 0) {
dev_err(dev, "pm_runtime_get_sync failed\n");
goto err_pm_disable;
}
hw_init_fn = of_device_get_match_data(dev);
err = hw_init_fn(pcie);
if (err) {
dev_info(dev, "PCIe link down\n");
err = -ENODEV;
goto err_pm_put;
}
data = rcar_pci_read_reg(pcie, MACSR);
dev_info(dev, "PCIe x%d: link up\n", (data >> 20) & 0x3f);
if (IS_ENABLED(CONFIG_PCI_MSI)) {
err = rcar_pcie_enable_msi(pcie);
if (err < 0) {
dev_err(dev,
"failed to enable MSI support: %d\n",
err);
goto err_pm_put;
}
}
err = rcar_pcie_enable(pcie);
if (err)
goto err_pm_put;
return 0;
err_pm_put:
pm_runtime_put(dev);
err_pm_disable:
pm_runtime_disable(dev);
err_free_bridge:
pci_free_host_bridge(bridge);
pci_free_resource_list(&pcie->resources);
return err;
}
