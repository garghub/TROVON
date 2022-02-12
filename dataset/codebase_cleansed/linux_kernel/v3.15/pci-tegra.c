static inline struct tegra_msi *to_tegra_msi(struct msi_chip *chip)
{
return container_of(chip, struct tegra_msi, chip);
}
static inline struct tegra_pcie *sys_to_pcie(struct pci_sys_data *sys)
{
return sys->private_data;
}
static inline void afi_writel(struct tegra_pcie *pcie, u32 value,
unsigned long offset)
{
writel(value, pcie->afi + offset);
}
static inline u32 afi_readl(struct tegra_pcie *pcie, unsigned long offset)
{
return readl(pcie->afi + offset);
}
static inline void pads_writel(struct tegra_pcie *pcie, u32 value,
unsigned long offset)
{
writel(value, pcie->pads + offset);
}
static inline u32 pads_readl(struct tegra_pcie *pcie, unsigned long offset)
{
return readl(pcie->pads + offset);
}
static unsigned long tegra_pcie_conf_offset(unsigned int devfn, int where)
{
return ((where & 0xf00) << 8) | (PCI_SLOT(devfn) << 11) |
(PCI_FUNC(devfn) << 8) | (where & 0xfc);
}
static struct tegra_pcie_bus *tegra_pcie_bus_alloc(struct tegra_pcie *pcie,
unsigned int busnr)
{
pgprot_t prot = L_PTE_PRESENT | L_PTE_YOUNG | L_PTE_DIRTY | L_PTE_XN |
L_PTE_MT_DEV_SHARED | L_PTE_SHARED;
phys_addr_t cs = pcie->cs->start;
struct tegra_pcie_bus *bus;
unsigned int i;
int err;
bus = kzalloc(sizeof(*bus), GFP_KERNEL);
if (!bus)
return ERR_PTR(-ENOMEM);
INIT_LIST_HEAD(&bus->list);
bus->nr = busnr;
bus->area = get_vm_area(SZ_1M, VM_IOREMAP);
if (!bus->area) {
err = -ENOMEM;
goto free;
}
for (i = 0; i < 16; i++) {
unsigned long virt = (unsigned long)bus->area->addr +
i * SZ_64K;
phys_addr_t phys = cs + i * SZ_1M + busnr * SZ_64K;
err = ioremap_page_range(virt, virt + SZ_64K, phys, prot);
if (err < 0) {
dev_err(pcie->dev, "ioremap_page_range() failed: %d\n",
err);
goto unmap;
}
}
return bus;
unmap:
vunmap(bus->area->addr);
free:
kfree(bus);
return ERR_PTR(err);
}
static void __iomem *tegra_pcie_bus_map(struct tegra_pcie *pcie,
unsigned int busnr)
{
struct tegra_pcie_bus *bus;
list_for_each_entry(bus, &pcie->buses, list)
if (bus->nr == busnr)
return (void __iomem *)bus->area->addr;
bus = tegra_pcie_bus_alloc(pcie, busnr);
if (IS_ERR(bus))
return NULL;
list_add_tail(&bus->list, &pcie->buses);
return (void __iomem *)bus->area->addr;
}
static void __iomem *tegra_pcie_conf_address(struct pci_bus *bus,
unsigned int devfn,
int where)
{
struct tegra_pcie *pcie = sys_to_pcie(bus->sysdata);
void __iomem *addr = NULL;
if (bus->number == 0) {
unsigned int slot = PCI_SLOT(devfn);
struct tegra_pcie_port *port;
list_for_each_entry(port, &pcie->ports, list) {
if (port->index + 1 == slot) {
addr = port->base + (where & ~3);
break;
}
}
} else {
addr = tegra_pcie_bus_map(pcie, bus->number);
if (!addr) {
dev_err(pcie->dev,
"failed to map cfg. space for bus %u\n",
bus->number);
return NULL;
}
addr += tegra_pcie_conf_offset(devfn, where);
}
return addr;
}
static int tegra_pcie_read_conf(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 *value)
{
void __iomem *addr;
addr = tegra_pcie_conf_address(bus, devfn, where);
if (!addr) {
*value = 0xffffffff;
return PCIBIOS_DEVICE_NOT_FOUND;
}
*value = readl(addr);
if (size == 1)
*value = (*value >> (8 * (where & 3))) & 0xff;
else if (size == 2)
*value = (*value >> (8 * (where & 3))) & 0xffff;
return PCIBIOS_SUCCESSFUL;
}
static int tegra_pcie_write_conf(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 value)
{
void __iomem *addr;
u32 mask, tmp;
addr = tegra_pcie_conf_address(bus, devfn, where);
if (!addr)
return PCIBIOS_DEVICE_NOT_FOUND;
if (size == 4) {
writel(value, addr);
return PCIBIOS_SUCCESSFUL;
}
if (size == 2)
mask = ~(0xffff << ((where & 0x3) * 8));
else if (size == 1)
mask = ~(0xff << ((where & 0x3) * 8));
else
return PCIBIOS_BAD_REGISTER_NUMBER;
tmp = readl(addr) & mask;
tmp |= value << ((where & 0x3) * 8);
writel(tmp, addr);
return PCIBIOS_SUCCESSFUL;
}
static unsigned long tegra_pcie_port_get_pex_ctrl(struct tegra_pcie_port *port)
{
unsigned long ret = 0;
switch (port->index) {
case 0:
ret = AFI_PEX0_CTRL;
break;
case 1:
ret = AFI_PEX1_CTRL;
break;
case 2:
ret = AFI_PEX2_CTRL;
break;
}
return ret;
}
static void tegra_pcie_port_reset(struct tegra_pcie_port *port)
{
unsigned long ctrl = tegra_pcie_port_get_pex_ctrl(port);
unsigned long value;
value = afi_readl(port->pcie, ctrl);
value &= ~AFI_PEX_CTRL_RST;
afi_writel(port->pcie, value, ctrl);
usleep_range(1000, 2000);
value = afi_readl(port->pcie, ctrl);
value |= AFI_PEX_CTRL_RST;
afi_writel(port->pcie, value, ctrl);
}
static void tegra_pcie_port_enable(struct tegra_pcie_port *port)
{
const struct tegra_pcie_soc_data *soc = port->pcie->soc_data;
unsigned long ctrl = tegra_pcie_port_get_pex_ctrl(port);
unsigned long value;
value = afi_readl(port->pcie, ctrl);
value |= AFI_PEX_CTRL_REFCLK_EN;
if (soc->has_pex_clkreq_en)
value |= AFI_PEX_CTRL_CLKREQ_EN;
afi_writel(port->pcie, value, ctrl);
tegra_pcie_port_reset(port);
}
static void tegra_pcie_port_disable(struct tegra_pcie_port *port)
{
unsigned long ctrl = tegra_pcie_port_get_pex_ctrl(port);
unsigned long value;
value = afi_readl(port->pcie, ctrl);
value &= ~AFI_PEX_CTRL_RST;
afi_writel(port->pcie, value, ctrl);
value = afi_readl(port->pcie, ctrl);
value &= ~AFI_PEX_CTRL_REFCLK_EN;
afi_writel(port->pcie, value, ctrl);
}
static void tegra_pcie_port_free(struct tegra_pcie_port *port)
{
struct tegra_pcie *pcie = port->pcie;
devm_iounmap(pcie->dev, port->base);
devm_release_mem_region(pcie->dev, port->regs.start,
resource_size(&port->regs));
list_del(&port->list);
devm_kfree(pcie->dev, port);
}
static void tegra_pcie_fixup_bridge(struct pci_dev *dev)
{
u16 reg;
if ((dev->class >> 16) == PCI_BASE_CLASS_BRIDGE) {
pci_read_config_word(dev, PCI_COMMAND, &reg);
reg |= (PCI_COMMAND_IO | PCI_COMMAND_MEMORY |
PCI_COMMAND_MASTER | PCI_COMMAND_SERR);
pci_write_config_word(dev, PCI_COMMAND, reg);
}
}
static void tegra_pcie_fixup_class(struct pci_dev *dev)
{
dev->class = PCI_CLASS_BRIDGE_PCI << 8;
}
static void tegra_pcie_relax_enable(struct pci_dev *dev)
{
pcie_capability_set_word(dev, PCI_EXP_DEVCTL, PCI_EXP_DEVCTL_RELAX_EN);
}
static int tegra_pcie_setup(int nr, struct pci_sys_data *sys)
{
struct tegra_pcie *pcie = sys_to_pcie(sys);
pci_add_resource_offset(&sys->resources, &pcie->mem, sys->mem_offset);
pci_add_resource_offset(&sys->resources, &pcie->prefetch,
sys->mem_offset);
pci_add_resource(&sys->resources, &pcie->busn);
pci_ioremap_io(nr * SZ_64K, pcie->io.start);
return 1;
}
static int tegra_pcie_map_irq(const struct pci_dev *pdev, u8 slot, u8 pin)
{
struct tegra_pcie *pcie = sys_to_pcie(pdev->bus->sysdata);
int irq;
tegra_cpuidle_pcie_irqs_in_use();
irq = of_irq_parse_and_map_pci(pdev, slot, pin);
if (!irq)
irq = pcie->irq;
return irq;
}
static void tegra_pcie_add_bus(struct pci_bus *bus)
{
if (IS_ENABLED(CONFIG_PCI_MSI)) {
struct tegra_pcie *pcie = sys_to_pcie(bus->sysdata);
bus->msi = &pcie->msi.chip;
}
}
static struct pci_bus *tegra_pcie_scan_bus(int nr, struct pci_sys_data *sys)
{
struct tegra_pcie *pcie = sys_to_pcie(sys);
struct pci_bus *bus;
bus = pci_create_root_bus(pcie->dev, sys->busnr, &tegra_pcie_ops, sys,
&sys->resources);
if (!bus)
return NULL;
pci_scan_child_bus(bus);
return bus;
}
static irqreturn_t tegra_pcie_isr(int irq, void *arg)
{
const char *err_msg[] = {
"Unknown",
"AXI slave error",
"AXI decode error",
"Target abort",
"Master abort",
"Invalid write",
"Response decoding error",
"AXI response decoding error",
"Transaction timeout",
};
struct tegra_pcie *pcie = arg;
u32 code, signature;
code = afi_readl(pcie, AFI_INTR_CODE) & AFI_INTR_CODE_MASK;
signature = afi_readl(pcie, AFI_INTR_SIGNATURE);
afi_writel(pcie, 0, AFI_INTR_CODE);
if (code == AFI_INTR_LEGACY)
return IRQ_NONE;
if (code >= ARRAY_SIZE(err_msg))
code = 0;
if (code == AFI_INTR_MASTER_ABORT)
dev_dbg(pcie->dev, "%s, signature: %08x\n", err_msg[code],
signature);
else
dev_err(pcie->dev, "%s, signature: %08x\n", err_msg[code],
signature);
if (code == AFI_INTR_TARGET_ABORT || code == AFI_INTR_MASTER_ABORT ||
code == AFI_INTR_FPCI_DECODE_ERROR) {
u32 fpci = afi_readl(pcie, AFI_UPPER_FPCI_ADDRESS) & 0xff;
u64 address = (u64)fpci << 32 | (signature & 0xfffffffc);
if (code == AFI_INTR_MASTER_ABORT)
dev_dbg(pcie->dev, " FPCI address: %10llx\n", address);
else
dev_err(pcie->dev, " FPCI address: %10llx\n", address);
}
return IRQ_HANDLED;
}
static void tegra_pcie_setup_translations(struct tegra_pcie *pcie)
{
u32 fpci_bar, size, axi_address;
fpci_bar = 0xfe100000;
size = resource_size(pcie->cs);
axi_address = pcie->cs->start;
afi_writel(pcie, axi_address, AFI_AXI_BAR0_START);
afi_writel(pcie, size >> 12, AFI_AXI_BAR0_SZ);
afi_writel(pcie, fpci_bar, AFI_FPCI_BAR0);
fpci_bar = 0xfdfc0000;
size = resource_size(&pcie->io);
axi_address = pcie->io.start;
afi_writel(pcie, axi_address, AFI_AXI_BAR1_START);
afi_writel(pcie, size >> 12, AFI_AXI_BAR1_SZ);
afi_writel(pcie, fpci_bar, AFI_FPCI_BAR1);
fpci_bar = (((pcie->prefetch.start >> 12) & 0x0fffffff) << 4) | 0x1;
size = resource_size(&pcie->prefetch);
axi_address = pcie->prefetch.start;
afi_writel(pcie, axi_address, AFI_AXI_BAR2_START);
afi_writel(pcie, size >> 12, AFI_AXI_BAR2_SZ);
afi_writel(pcie, fpci_bar, AFI_FPCI_BAR2);
fpci_bar = (((pcie->mem.start >> 12) & 0x0fffffff) << 4) | 0x1;
size = resource_size(&pcie->mem);
axi_address = pcie->mem.start;
afi_writel(pcie, axi_address, AFI_AXI_BAR3_START);
afi_writel(pcie, size >> 12, AFI_AXI_BAR3_SZ);
afi_writel(pcie, fpci_bar, AFI_FPCI_BAR3);
afi_writel(pcie, 0, AFI_AXI_BAR4_START);
afi_writel(pcie, 0, AFI_AXI_BAR4_SZ);
afi_writel(pcie, 0, AFI_FPCI_BAR4);
afi_writel(pcie, 0, AFI_AXI_BAR5_START);
afi_writel(pcie, 0, AFI_AXI_BAR5_SZ);
afi_writel(pcie, 0, AFI_FPCI_BAR5);
afi_writel(pcie, PHYS_OFFSET, AFI_CACHE_BAR0_ST);
afi_writel(pcie, 0, AFI_CACHE_BAR0_SZ);
afi_writel(pcie, 0, AFI_CACHE_BAR1_ST);
afi_writel(pcie, 0, AFI_CACHE_BAR1_SZ);
afi_writel(pcie, 0, AFI_MSI_FPCI_BAR_ST);
afi_writel(pcie, 0, AFI_MSI_BAR_SZ);
afi_writel(pcie, 0, AFI_MSI_AXI_BAR_ST);
afi_writel(pcie, 0, AFI_MSI_BAR_SZ);
}
static int tegra_pcie_enable_controller(struct tegra_pcie *pcie)
{
const struct tegra_pcie_soc_data *soc = pcie->soc_data;
struct tegra_pcie_port *port;
unsigned int timeout;
unsigned long value;
if (soc->has_pex_bias_ctrl)
afi_writel(pcie, 0, AFI_PEXBIAS_CTRL_0);
value = afi_readl(pcie, AFI_PCIE_CONFIG);
value &= ~AFI_PCIE_CONFIG_SM2TMS0_XBAR_CONFIG_MASK;
value |= AFI_PCIE_CONFIG_PCIE_DISABLE_ALL | pcie->xbar_config;
list_for_each_entry(port, &pcie->ports, list)
value &= ~AFI_PCIE_CONFIG_PCIE_DISABLE(port->index);
afi_writel(pcie, value, AFI_PCIE_CONFIG);
value = afi_readl(pcie, AFI_FUSE);
value |= AFI_FUSE_PCIE_T0_GEN2_DIS;
afi_writel(pcie, value, AFI_FUSE);
pads_writel(pcie, 0x0, PADS_CTL_SEL);
value = pads_readl(pcie, PADS_CTL);
value |= PADS_CTL_IDDQ_1L;
pads_writel(pcie, value, PADS_CTL);
value = pads_readl(pcie, soc->pads_pll_ctl);
value &= ~(PADS_PLL_CTL_REFCLK_MASK | PADS_PLL_CTL_TXCLKREF_MASK);
value |= PADS_PLL_CTL_REFCLK_INTERNAL_CML | soc->tx_ref_sel;
pads_writel(pcie, value, soc->pads_pll_ctl);
value = pads_readl(pcie, soc->pads_pll_ctl);
value |= PADS_PLL_CTL_RST_B4SM;
pads_writel(pcie, value, soc->pads_pll_ctl);
value = PADS_REFCLK_CFG_VALUE | (PADS_REFCLK_CFG_VALUE << 16);
pads_writel(pcie, value, PADS_REFCLK_CFG0);
if (soc->num_ports > 2)
pads_writel(pcie, PADS_REFCLK_CFG_VALUE, PADS_REFCLK_CFG1);
timeout = 300;
do {
value = pads_readl(pcie, soc->pads_pll_ctl);
usleep_range(1000, 2000);
if (--timeout == 0) {
pr_err("Tegra PCIe error: timeout waiting for PLL\n");
return -EBUSY;
}
} while (!(value & PADS_PLL_CTL_LOCKDET));
value = pads_readl(pcie, PADS_CTL);
value &= ~PADS_CTL_IDDQ_1L;
pads_writel(pcie, value, PADS_CTL);
value = pads_readl(pcie, PADS_CTL);
value |= PADS_CTL_TX_DATA_EN_1L | PADS_CTL_RX_DATA_EN_1L;
pads_writel(pcie, value, PADS_CTL);
reset_control_deassert(pcie->pcie_xrst);
value = afi_readl(pcie, AFI_CONFIGURATION);
value |= AFI_CONFIGURATION_EN_FPCI;
afi_writel(pcie, value, AFI_CONFIGURATION);
value = AFI_INTR_EN_INI_SLVERR | AFI_INTR_EN_INI_DECERR |
AFI_INTR_EN_TGT_SLVERR | AFI_INTR_EN_TGT_DECERR |
AFI_INTR_EN_TGT_WRERR | AFI_INTR_EN_DFPCI_DECERR;
if (soc->has_intr_prsnt_sense)
value |= AFI_INTR_EN_PRSNT_SENSE;
afi_writel(pcie, value, AFI_AFI_INTR_ENABLE);
afi_writel(pcie, 0xffffffff, AFI_SM_INTR_ENABLE);
afi_writel(pcie, AFI_INTR_MASK_INT_MASK, AFI_INTR_MASK);
afi_writel(pcie, 0, AFI_FPCI_ERROR_MASKS);
return 0;
}
static void tegra_pcie_power_off(struct tegra_pcie *pcie)
{
const struct tegra_pcie_soc_data *soc = pcie->soc_data;
int err;
reset_control_assert(pcie->pcie_xrst);
reset_control_assert(pcie->afi_rst);
reset_control_assert(pcie->pex_rst);
tegra_powergate_power_off(TEGRA_POWERGATE_PCIE);
if (soc->has_avdd_supply) {
err = regulator_disable(pcie->avdd_supply);
if (err < 0)
dev_warn(pcie->dev,
"failed to disable AVDD regulator: %d\n",
err);
}
err = regulator_disable(pcie->pex_clk_supply);
if (err < 0)
dev_warn(pcie->dev, "failed to disable pex-clk regulator: %d\n",
err);
err = regulator_disable(pcie->vdd_supply);
if (err < 0)
dev_warn(pcie->dev, "failed to disable VDD regulator: %d\n",
err);
}
static int tegra_pcie_power_on(struct tegra_pcie *pcie)
{
const struct tegra_pcie_soc_data *soc = pcie->soc_data;
int err;
reset_control_assert(pcie->pcie_xrst);
reset_control_assert(pcie->afi_rst);
reset_control_assert(pcie->pex_rst);
tegra_powergate_power_off(TEGRA_POWERGATE_PCIE);
err = regulator_enable(pcie->vdd_supply);
if (err < 0) {
dev_err(pcie->dev, "failed to enable VDD regulator: %d\n", err);
return err;
}
err = regulator_enable(pcie->pex_clk_supply);
if (err < 0) {
dev_err(pcie->dev, "failed to enable pex-clk regulator: %d\n",
err);
return err;
}
if (soc->has_avdd_supply) {
err = regulator_enable(pcie->avdd_supply);
if (err < 0) {
dev_err(pcie->dev,
"failed to enable AVDD regulator: %d\n",
err);
return err;
}
}
err = tegra_powergate_sequence_power_up(TEGRA_POWERGATE_PCIE,
pcie->pex_clk,
pcie->pex_rst);
if (err) {
dev_err(pcie->dev, "powerup sequence failed: %d\n", err);
return err;
}
reset_control_deassert(pcie->afi_rst);
err = clk_prepare_enable(pcie->afi_clk);
if (err < 0) {
dev_err(pcie->dev, "failed to enable AFI clock: %d\n", err);
return err;
}
if (soc->has_cml_clk) {
err = clk_prepare_enable(pcie->cml_clk);
if (err < 0) {
dev_err(pcie->dev, "failed to enable CML clock: %d\n",
err);
return err;
}
}
err = clk_prepare_enable(pcie->pll_e);
if (err < 0) {
dev_err(pcie->dev, "failed to enable PLLE clock: %d\n", err);
return err;
}
return 0;
}
static int tegra_pcie_clocks_get(struct tegra_pcie *pcie)
{
const struct tegra_pcie_soc_data *soc = pcie->soc_data;
pcie->pex_clk = devm_clk_get(pcie->dev, "pex");
if (IS_ERR(pcie->pex_clk))
return PTR_ERR(pcie->pex_clk);
pcie->afi_clk = devm_clk_get(pcie->dev, "afi");
if (IS_ERR(pcie->afi_clk))
return PTR_ERR(pcie->afi_clk);
pcie->pll_e = devm_clk_get(pcie->dev, "pll_e");
if (IS_ERR(pcie->pll_e))
return PTR_ERR(pcie->pll_e);
if (soc->has_cml_clk) {
pcie->cml_clk = devm_clk_get(pcie->dev, "cml");
if (IS_ERR(pcie->cml_clk))
return PTR_ERR(pcie->cml_clk);
}
return 0;
}
static int tegra_pcie_resets_get(struct tegra_pcie *pcie)
{
pcie->pex_rst = devm_reset_control_get(pcie->dev, "pex");
if (IS_ERR(pcie->pex_rst))
return PTR_ERR(pcie->pex_rst);
pcie->afi_rst = devm_reset_control_get(pcie->dev, "afi");
if (IS_ERR(pcie->afi_rst))
return PTR_ERR(pcie->afi_rst);
pcie->pcie_xrst = devm_reset_control_get(pcie->dev, "pcie_x");
if (IS_ERR(pcie->pcie_xrst))
return PTR_ERR(pcie->pcie_xrst);
return 0;
}
static int tegra_pcie_get_resources(struct tegra_pcie *pcie)
{
struct platform_device *pdev = to_platform_device(pcie->dev);
struct resource *pads, *afi, *res;
int err;
err = tegra_pcie_clocks_get(pcie);
if (err) {
dev_err(&pdev->dev, "failed to get clocks: %d\n", err);
return err;
}
err = tegra_pcie_resets_get(pcie);
if (err) {
dev_err(&pdev->dev, "failed to get resets: %d\n", err);
return err;
}
err = tegra_pcie_power_on(pcie);
if (err) {
dev_err(&pdev->dev, "failed to power up: %d\n", err);
return err;
}
pads = platform_get_resource_byname(pdev, IORESOURCE_MEM, "pads");
pcie->pads = devm_ioremap_resource(&pdev->dev, pads);
if (IS_ERR(pcie->pads)) {
err = PTR_ERR(pcie->pads);
goto poweroff;
}
afi = platform_get_resource_byname(pdev, IORESOURCE_MEM, "afi");
pcie->afi = devm_ioremap_resource(&pdev->dev, afi);
if (IS_ERR(pcie->afi)) {
err = PTR_ERR(pcie->afi);
goto poweroff;
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "cs");
if (!res) {
err = -EADDRNOTAVAIL;
goto poweroff;
}
pcie->cs = devm_request_mem_region(pcie->dev, res->start,
resource_size(res), res->name);
if (!pcie->cs) {
err = -EADDRNOTAVAIL;
goto poweroff;
}
err = platform_get_irq_byname(pdev, "intr");
if (err < 0) {
dev_err(&pdev->dev, "failed to get IRQ: %d\n", err);
goto poweroff;
}
pcie->irq = err;
err = request_irq(pcie->irq, tegra_pcie_isr, IRQF_SHARED, "PCIE", pcie);
if (err) {
dev_err(&pdev->dev, "failed to register IRQ: %d\n", err);
goto poweroff;
}
return 0;
poweroff:
tegra_pcie_power_off(pcie);
return err;
}
static int tegra_pcie_put_resources(struct tegra_pcie *pcie)
{
if (pcie->irq > 0)
free_irq(pcie->irq, pcie);
tegra_pcie_power_off(pcie);
return 0;
}
static int tegra_msi_alloc(struct tegra_msi *chip)
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
static void tegra_msi_free(struct tegra_msi *chip, unsigned long irq)
{
struct device *dev = chip->chip.dev;
mutex_lock(&chip->lock);
if (!test_bit(irq, chip->used))
dev_err(dev, "trying to free unused MSI#%lu\n", irq);
else
clear_bit(irq, chip->used);
mutex_unlock(&chip->lock);
}
static irqreturn_t tegra_pcie_msi_irq(int irq, void *data)
{
struct tegra_pcie *pcie = data;
struct tegra_msi *msi = &pcie->msi;
unsigned int i, processed = 0;
for (i = 0; i < 8; i++) {
unsigned long reg = afi_readl(pcie, AFI_MSI_VEC0 + i * 4);
while (reg) {
unsigned int offset = find_first_bit(&reg, 32);
unsigned int index = i * 32 + offset;
unsigned int irq;
afi_writel(pcie, 1 << offset, AFI_MSI_VEC0 + i * 4);
irq = irq_find_mapping(msi->domain, index);
if (irq) {
if (test_bit(index, msi->used))
generic_handle_irq(irq);
else
dev_info(pcie->dev, "unhandled MSI\n");
} else {
dev_info(pcie->dev, "unexpected MSI\n");
}
reg = afi_readl(pcie, AFI_MSI_VEC0 + i * 4);
processed++;
}
}
return processed > 0 ? IRQ_HANDLED : IRQ_NONE;
}
static int tegra_msi_setup_irq(struct msi_chip *chip, struct pci_dev *pdev,
struct msi_desc *desc)
{
struct tegra_msi *msi = to_tegra_msi(chip);
struct msi_msg msg;
unsigned int irq;
int hwirq;
hwirq = tegra_msi_alloc(msi);
if (hwirq < 0)
return hwirq;
irq = irq_create_mapping(msi->domain, hwirq);
if (!irq)
return -EINVAL;
irq_set_msi_desc(irq, desc);
msg.address_lo = virt_to_phys((void *)msi->pages);
msg.address_hi = 0;
msg.data = hwirq;
write_msi_msg(irq, &msg);
return 0;
}
static void tegra_msi_teardown_irq(struct msi_chip *chip, unsigned int irq)
{
struct tegra_msi *msi = to_tegra_msi(chip);
struct irq_data *d = irq_get_irq_data(irq);
tegra_msi_free(msi, d->hwirq);
}
static int tegra_msi_map(struct irq_domain *domain, unsigned int irq,
irq_hw_number_t hwirq)
{
irq_set_chip_and_handler(irq, &tegra_msi_irq_chip, handle_simple_irq);
irq_set_chip_data(irq, domain->host_data);
set_irq_flags(irq, IRQF_VALID);
tegra_cpuidle_pcie_irqs_in_use();
return 0;
}
static int tegra_pcie_enable_msi(struct tegra_pcie *pcie)
{
struct platform_device *pdev = to_platform_device(pcie->dev);
const struct tegra_pcie_soc_data *soc = pcie->soc_data;
struct tegra_msi *msi = &pcie->msi;
unsigned long base;
int err;
u32 reg;
mutex_init(&msi->lock);
msi->chip.dev = pcie->dev;
msi->chip.setup_irq = tegra_msi_setup_irq;
msi->chip.teardown_irq = tegra_msi_teardown_irq;
msi->domain = irq_domain_add_linear(pcie->dev->of_node, INT_PCI_MSI_NR,
&msi_domain_ops, &msi->chip);
if (!msi->domain) {
dev_err(&pdev->dev, "failed to create IRQ domain\n");
return -ENOMEM;
}
err = platform_get_irq_byname(pdev, "msi");
if (err < 0) {
dev_err(&pdev->dev, "failed to get IRQ: %d\n", err);
goto err;
}
msi->irq = err;
err = request_irq(msi->irq, tegra_pcie_msi_irq, 0,
tegra_msi_irq_chip.name, pcie);
if (err < 0) {
dev_err(&pdev->dev, "failed to request IRQ: %d\n", err);
goto err;
}
msi->pages = __get_free_pages(GFP_KERNEL, 0);
base = virt_to_phys((void *)msi->pages);
afi_writel(pcie, base >> soc->msi_base_shift, AFI_MSI_FPCI_BAR_ST);
afi_writel(pcie, base, AFI_MSI_AXI_BAR_ST);
afi_writel(pcie, 1, AFI_MSI_BAR_SZ);
afi_writel(pcie, 0xffffffff, AFI_MSI_EN_VEC0);
afi_writel(pcie, 0xffffffff, AFI_MSI_EN_VEC1);
afi_writel(pcie, 0xffffffff, AFI_MSI_EN_VEC2);
afi_writel(pcie, 0xffffffff, AFI_MSI_EN_VEC3);
afi_writel(pcie, 0xffffffff, AFI_MSI_EN_VEC4);
afi_writel(pcie, 0xffffffff, AFI_MSI_EN_VEC5);
afi_writel(pcie, 0xffffffff, AFI_MSI_EN_VEC6);
afi_writel(pcie, 0xffffffff, AFI_MSI_EN_VEC7);
reg = afi_readl(pcie, AFI_INTR_MASK);
reg |= AFI_INTR_MASK_MSI_MASK;
afi_writel(pcie, reg, AFI_INTR_MASK);
return 0;
err:
irq_domain_remove(msi->domain);
return err;
}
static int tegra_pcie_disable_msi(struct tegra_pcie *pcie)
{
struct tegra_msi *msi = &pcie->msi;
unsigned int i, irq;
u32 value;
value = afi_readl(pcie, AFI_INTR_MASK);
value &= ~AFI_INTR_MASK_MSI_MASK;
afi_writel(pcie, value, AFI_INTR_MASK);
afi_writel(pcie, 0, AFI_MSI_EN_VEC0);
afi_writel(pcie, 0, AFI_MSI_EN_VEC1);
afi_writel(pcie, 0, AFI_MSI_EN_VEC2);
afi_writel(pcie, 0, AFI_MSI_EN_VEC3);
afi_writel(pcie, 0, AFI_MSI_EN_VEC4);
afi_writel(pcie, 0, AFI_MSI_EN_VEC5);
afi_writel(pcie, 0, AFI_MSI_EN_VEC6);
afi_writel(pcie, 0, AFI_MSI_EN_VEC7);
free_pages(msi->pages, 0);
if (msi->irq > 0)
free_irq(msi->irq, pcie);
for (i = 0; i < INT_PCI_MSI_NR; i++) {
irq = irq_find_mapping(msi->domain, i);
if (irq > 0)
irq_dispose_mapping(irq);
}
irq_domain_remove(msi->domain);
return 0;
}
static int tegra_pcie_get_xbar_config(struct tegra_pcie *pcie, u32 lanes,
u32 *xbar)
{
struct device_node *np = pcie->dev->of_node;
if (of_device_is_compatible(np, "nvidia,tegra30-pcie")) {
switch (lanes) {
case 0x00000204:
dev_info(pcie->dev, "4x1, 2x1 configuration\n");
*xbar = AFI_PCIE_CONFIG_SM2TMS0_XBAR_CONFIG_420;
return 0;
case 0x00020202:
dev_info(pcie->dev, "2x3 configuration\n");
*xbar = AFI_PCIE_CONFIG_SM2TMS0_XBAR_CONFIG_222;
return 0;
case 0x00010104:
dev_info(pcie->dev, "4x1, 1x2 configuration\n");
*xbar = AFI_PCIE_CONFIG_SM2TMS0_XBAR_CONFIG_411;
return 0;
}
} else if (of_device_is_compatible(np, "nvidia,tegra20-pcie")) {
switch (lanes) {
case 0x00000004:
dev_info(pcie->dev, "single-mode configuration\n");
*xbar = AFI_PCIE_CONFIG_SM2TMS0_XBAR_CONFIG_SINGLE;
return 0;
case 0x00000202:
dev_info(pcie->dev, "dual-mode configuration\n");
*xbar = AFI_PCIE_CONFIG_SM2TMS0_XBAR_CONFIG_DUAL;
return 0;
}
}
return -EINVAL;
}
static int tegra_pcie_parse_dt(struct tegra_pcie *pcie)
{
const struct tegra_pcie_soc_data *soc = pcie->soc_data;
struct device_node *np = pcie->dev->of_node, *port;
struct of_pci_range_parser parser;
struct of_pci_range range;
struct resource res;
u32 lanes = 0;
int err;
if (of_pci_range_parser_init(&parser, np)) {
dev_err(pcie->dev, "missing \"ranges\" property\n");
return -EINVAL;
}
pcie->vdd_supply = devm_regulator_get(pcie->dev, "vdd");
if (IS_ERR(pcie->vdd_supply))
return PTR_ERR(pcie->vdd_supply);
pcie->pex_clk_supply = devm_regulator_get(pcie->dev, "pex-clk");
if (IS_ERR(pcie->pex_clk_supply))
return PTR_ERR(pcie->pex_clk_supply);
if (soc->has_avdd_supply) {
pcie->avdd_supply = devm_regulator_get(pcie->dev, "avdd");
if (IS_ERR(pcie->avdd_supply))
return PTR_ERR(pcie->avdd_supply);
}
for_each_of_pci_range(&parser, &range) {
of_pci_range_to_resource(&range, np, &res);
switch (res.flags & IORESOURCE_TYPE_BITS) {
case IORESOURCE_IO:
memcpy(&pcie->io, &res, sizeof(res));
pcie->io.name = "I/O";
break;
case IORESOURCE_MEM:
if (res.flags & IORESOURCE_PREFETCH) {
memcpy(&pcie->prefetch, &res, sizeof(res));
pcie->prefetch.name = "PREFETCH";
} else {
memcpy(&pcie->mem, &res, sizeof(res));
pcie->mem.name = "MEM";
}
break;
}
}
err = of_pci_parse_bus_range(np, &pcie->busn);
if (err < 0) {
dev_err(pcie->dev, "failed to parse ranges property: %d\n",
err);
pcie->busn.name = np->name;
pcie->busn.start = 0;
pcie->busn.end = 0xff;
pcie->busn.flags = IORESOURCE_BUS;
}
for_each_child_of_node(np, port) {
struct tegra_pcie_port *rp;
unsigned int index;
u32 value;
err = of_pci_get_devfn(port);
if (err < 0) {
dev_err(pcie->dev, "failed to parse address: %d\n",
err);
return err;
}
index = PCI_SLOT(err);
if (index < 1 || index > soc->num_ports) {
dev_err(pcie->dev, "invalid port number: %d\n", index);
return -EINVAL;
}
index--;
err = of_property_read_u32(port, "nvidia,num-lanes", &value);
if (err < 0) {
dev_err(pcie->dev, "failed to parse # of lanes: %d\n",
err);
return err;
}
if (value > 16) {
dev_err(pcie->dev, "invalid # of lanes: %u\n", value);
return -EINVAL;
}
lanes |= value << (index << 3);
if (!of_device_is_available(port))
continue;
rp = devm_kzalloc(pcie->dev, sizeof(*rp), GFP_KERNEL);
if (!rp)
return -ENOMEM;
err = of_address_to_resource(port, 0, &rp->regs);
if (err < 0) {
dev_err(pcie->dev, "failed to parse address: %d\n",
err);
return err;
}
INIT_LIST_HEAD(&rp->list);
rp->index = index;
rp->lanes = value;
rp->pcie = pcie;
rp->base = devm_ioremap_resource(pcie->dev, &rp->regs);
if (IS_ERR(rp->base))
return PTR_ERR(rp->base);
list_add_tail(&rp->list, &pcie->ports);
}
err = tegra_pcie_get_xbar_config(pcie, lanes, &pcie->xbar_config);
if (err < 0) {
dev_err(pcie->dev, "invalid lane configuration\n");
return err;
}
return 0;
}
static bool tegra_pcie_port_check_link(struct tegra_pcie_port *port)
{
unsigned int retries = 3;
unsigned long value;
do {
unsigned int timeout = TEGRA_PCIE_LINKUP_TIMEOUT;
do {
value = readl(port->base + RP_VEND_XP);
if (value & RP_VEND_XP_DL_UP)
break;
usleep_range(1000, 2000);
} while (--timeout);
if (!timeout) {
dev_err(port->pcie->dev, "link %u down, retrying\n",
port->index);
goto retry;
}
timeout = TEGRA_PCIE_LINKUP_TIMEOUT;
do {
value = readl(port->base + RP_LINK_CONTROL_STATUS);
if (value & RP_LINK_CONTROL_STATUS_DL_LINK_ACTIVE)
return true;
usleep_range(1000, 2000);
} while (--timeout);
retry:
tegra_pcie_port_reset(port);
} while (--retries);
return false;
}
static int tegra_pcie_enable(struct tegra_pcie *pcie)
{
struct tegra_pcie_port *port, *tmp;
struct hw_pci hw;
list_for_each_entry_safe(port, tmp, &pcie->ports, list) {
dev_info(pcie->dev, "probing port %u, using %u lanes\n",
port->index, port->lanes);
tegra_pcie_port_enable(port);
if (tegra_pcie_port_check_link(port))
continue;
dev_info(pcie->dev, "link %u down, ignoring\n", port->index);
tegra_pcie_port_disable(port);
tegra_pcie_port_free(port);
}
memset(&hw, 0, sizeof(hw));
hw.nr_controllers = 1;
hw.private_data = (void **)&pcie;
hw.setup = tegra_pcie_setup;
hw.map_irq = tegra_pcie_map_irq;
hw.add_bus = tegra_pcie_add_bus;
hw.scan = tegra_pcie_scan_bus;
hw.ops = &tegra_pcie_ops;
pci_common_init_dev(pcie->dev, &hw);
return 0;
}
static int tegra_pcie_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
struct tegra_pcie *pcie;
int err;
match = of_match_device(tegra_pcie_of_match, &pdev->dev);
if (!match)
return -ENODEV;
pcie = devm_kzalloc(&pdev->dev, sizeof(*pcie), GFP_KERNEL);
if (!pcie)
return -ENOMEM;
INIT_LIST_HEAD(&pcie->buses);
INIT_LIST_HEAD(&pcie->ports);
pcie->soc_data = match->data;
pcie->dev = &pdev->dev;
err = tegra_pcie_parse_dt(pcie);
if (err < 0)
return err;
pcibios_min_mem = 0;
err = tegra_pcie_get_resources(pcie);
if (err < 0) {
dev_err(&pdev->dev, "failed to request resources: %d\n", err);
return err;
}
err = tegra_pcie_enable_controller(pcie);
if (err)
goto put_resources;
tegra_pcie_setup_translations(pcie);
if (IS_ENABLED(CONFIG_PCI_MSI)) {
err = tegra_pcie_enable_msi(pcie);
if (err < 0) {
dev_err(&pdev->dev,
"failed to enable MSI support: %d\n",
err);
goto put_resources;
}
}
err = tegra_pcie_enable(pcie);
if (err < 0) {
dev_err(&pdev->dev, "failed to enable PCIe ports: %d\n", err);
goto disable_msi;
}
platform_set_drvdata(pdev, pcie);
return 0;
disable_msi:
if (IS_ENABLED(CONFIG_PCI_MSI))
tegra_pcie_disable_msi(pcie);
put_resources:
tegra_pcie_put_resources(pcie);
return err;
}
