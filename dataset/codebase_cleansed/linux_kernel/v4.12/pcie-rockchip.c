static u32 rockchip_pcie_read(struct rockchip_pcie *rockchip, u32 reg)
{
return readl(rockchip->apb_base + reg);
}
static void rockchip_pcie_write(struct rockchip_pcie *rockchip, u32 val,
u32 reg)
{
writel(val, rockchip->apb_base + reg);
}
static void rockchip_pcie_enable_bw_int(struct rockchip_pcie *rockchip)
{
u32 status;
status = rockchip_pcie_read(rockchip, PCIE_RC_CONFIG_LCS);
status |= (PCI_EXP_LNKCTL_LBMIE | PCI_EXP_LNKCTL_LABIE);
rockchip_pcie_write(rockchip, status, PCIE_RC_CONFIG_LCS);
}
static void rockchip_pcie_clr_bw_int(struct rockchip_pcie *rockchip)
{
u32 status;
status = rockchip_pcie_read(rockchip, PCIE_RC_CONFIG_LCS);
status |= (PCI_EXP_LNKSTA_LBMS | PCI_EXP_LNKSTA_LABS) << 16;
rockchip_pcie_write(rockchip, status, PCIE_RC_CONFIG_LCS);
}
static void rockchip_pcie_update_txcredit_mui(struct rockchip_pcie *rockchip)
{
u32 val;
val = rockchip_pcie_read(rockchip, PCIE_CORE_TXCREDIT_CFG1);
val &= ~PCIE_CORE_TXCREDIT_CFG1_MUI_MASK;
val |= PCIE_CORE_TXCREDIT_CFG1_MUI_ENCODE(24000);
rockchip_pcie_write(rockchip, val, PCIE_CORE_TXCREDIT_CFG1);
}
static int rockchip_pcie_valid_device(struct rockchip_pcie *rockchip,
struct pci_bus *bus, int dev)
{
if (bus->number == rockchip->root_bus_nr && dev > 0)
return 0;
if (bus->primary == rockchip->root_bus_nr && dev > 0)
return 0;
return 1;
}
static int rockchip_pcie_rd_own_conf(struct rockchip_pcie *rockchip,
int where, int size, u32 *val)
{
void __iomem *addr = rockchip->apb_base + PCIE_RC_CONFIG_BASE + where;
if (!IS_ALIGNED((uintptr_t)addr, size)) {
*val = 0;
return PCIBIOS_BAD_REGISTER_NUMBER;
}
if (size == 4) {
*val = readl(addr);
} else if (size == 2) {
*val = readw(addr);
} else if (size == 1) {
*val = readb(addr);
} else {
*val = 0;
return PCIBIOS_BAD_REGISTER_NUMBER;
}
return PCIBIOS_SUCCESSFUL;
}
static int rockchip_pcie_wr_own_conf(struct rockchip_pcie *rockchip,
int where, int size, u32 val)
{
u32 mask, tmp, offset;
offset = where & ~0x3;
if (size == 4) {
writel(val, rockchip->apb_base + PCIE_RC_CONFIG_BASE + offset);
return PCIBIOS_SUCCESSFUL;
}
mask = ~(((1 << (size * 8)) - 1) << ((where & 0x3) * 8));
tmp = readl(rockchip->apb_base + PCIE_RC_CONFIG_BASE + offset) & mask;
tmp |= val << ((where & 0x3) * 8);
writel(tmp, rockchip->apb_base + PCIE_RC_CONFIG_BASE + offset);
return PCIBIOS_SUCCESSFUL;
}
static int rockchip_pcie_rd_other_conf(struct rockchip_pcie *rockchip,
struct pci_bus *bus, u32 devfn,
int where, int size, u32 *val)
{
u32 busdev;
busdev = PCIE_ECAM_ADDR(bus->number, PCI_SLOT(devfn),
PCI_FUNC(devfn), where);
if (!IS_ALIGNED(busdev, size)) {
*val = 0;
return PCIBIOS_BAD_REGISTER_NUMBER;
}
if (size == 4) {
*val = readl(rockchip->reg_base + busdev);
} else if (size == 2) {
*val = readw(rockchip->reg_base + busdev);
} else if (size == 1) {
*val = readb(rockchip->reg_base + busdev);
} else {
*val = 0;
return PCIBIOS_BAD_REGISTER_NUMBER;
}
return PCIBIOS_SUCCESSFUL;
}
static int rockchip_pcie_wr_other_conf(struct rockchip_pcie *rockchip,
struct pci_bus *bus, u32 devfn,
int where, int size, u32 val)
{
u32 busdev;
busdev = PCIE_ECAM_ADDR(bus->number, PCI_SLOT(devfn),
PCI_FUNC(devfn), where);
if (!IS_ALIGNED(busdev, size))
return PCIBIOS_BAD_REGISTER_NUMBER;
if (size == 4)
writel(val, rockchip->reg_base + busdev);
else if (size == 2)
writew(val, rockchip->reg_base + busdev);
else if (size == 1)
writeb(val, rockchip->reg_base + busdev);
else
return PCIBIOS_BAD_REGISTER_NUMBER;
return PCIBIOS_SUCCESSFUL;
}
static int rockchip_pcie_rd_conf(struct pci_bus *bus, u32 devfn, int where,
int size, u32 *val)
{
struct rockchip_pcie *rockchip = bus->sysdata;
if (!rockchip_pcie_valid_device(rockchip, bus, PCI_SLOT(devfn))) {
*val = 0xffffffff;
return PCIBIOS_DEVICE_NOT_FOUND;
}
if (bus->number == rockchip->root_bus_nr)
return rockchip_pcie_rd_own_conf(rockchip, where, size, val);
return rockchip_pcie_rd_other_conf(rockchip, bus, devfn, where, size, val);
}
static int rockchip_pcie_wr_conf(struct pci_bus *bus, u32 devfn,
int where, int size, u32 val)
{
struct rockchip_pcie *rockchip = bus->sysdata;
if (!rockchip_pcie_valid_device(rockchip, bus, PCI_SLOT(devfn)))
return PCIBIOS_DEVICE_NOT_FOUND;
if (bus->number == rockchip->root_bus_nr)
return rockchip_pcie_wr_own_conf(rockchip, where, size, val);
return rockchip_pcie_wr_other_conf(rockchip, bus, devfn, where, size, val);
}
static void rockchip_pcie_set_power_limit(struct rockchip_pcie *rockchip)
{
int curr;
u32 status, scale, power;
if (IS_ERR(rockchip->vpcie3v3))
return;
curr = regulator_get_current_limit(rockchip->vpcie3v3);
if (curr <= 0)
return;
scale = 3;
curr = curr / 1000;
power = (curr * 3300) / 1000;
while (power > PCIE_RC_CONFIG_DCR_CSPL_LIMIT) {
if (!scale) {
dev_warn(rockchip->dev, "invalid power supply\n");
return;
}
scale--;
power = power / 10;
}
status = rockchip_pcie_read(rockchip, PCIE_RC_CONFIG_DCR);
status |= (power << PCIE_RC_CONFIG_DCR_CSPL_SHIFT) |
(scale << PCIE_RC_CONFIG_DCR_CPLS_SHIFT);
rockchip_pcie_write(rockchip, status, PCIE_RC_CONFIG_DCR);
}
static int rockchip_pcie_init_port(struct rockchip_pcie *rockchip)
{
struct device *dev = rockchip->dev;
int err;
u32 status;
gpiod_set_value(rockchip->ep_gpio, 0);
err = reset_control_assert(rockchip->aclk_rst);
if (err) {
dev_err(dev, "assert aclk_rst err %d\n", err);
return err;
}
err = reset_control_assert(rockchip->pclk_rst);
if (err) {
dev_err(dev, "assert pclk_rst err %d\n", err);
return err;
}
err = reset_control_assert(rockchip->pm_rst);
if (err) {
dev_err(dev, "assert pm_rst err %d\n", err);
return err;
}
err = phy_init(rockchip->phy);
if (err < 0) {
dev_err(dev, "fail to init phy, err %d\n", err);
return err;
}
err = reset_control_assert(rockchip->core_rst);
if (err) {
dev_err(dev, "assert core_rst err %d\n", err);
return err;
}
err = reset_control_assert(rockchip->mgmt_rst);
if (err) {
dev_err(dev, "assert mgmt_rst err %d\n", err);
return err;
}
err = reset_control_assert(rockchip->mgmt_sticky_rst);
if (err) {
dev_err(dev, "assert mgmt_sticky_rst err %d\n", err);
return err;
}
err = reset_control_assert(rockchip->pipe_rst);
if (err) {
dev_err(dev, "assert pipe_rst err %d\n", err);
return err;
}
udelay(10);
err = reset_control_deassert(rockchip->pm_rst);
if (err) {
dev_err(dev, "deassert pm_rst err %d\n", err);
return err;
}
err = reset_control_deassert(rockchip->aclk_rst);
if (err) {
dev_err(dev, "deassert aclk_rst err %d\n", err);
return err;
}
err = reset_control_deassert(rockchip->pclk_rst);
if (err) {
dev_err(dev, "deassert pclk_rst err %d\n", err);
return err;
}
if (rockchip->link_gen == 2)
rockchip_pcie_write(rockchip, PCIE_CLIENT_GEN_SEL_2,
PCIE_CLIENT_CONFIG);
else
rockchip_pcie_write(rockchip, PCIE_CLIENT_GEN_SEL_1,
PCIE_CLIENT_CONFIG);
rockchip_pcie_write(rockchip,
PCIE_CLIENT_CONF_ENABLE |
PCIE_CLIENT_LINK_TRAIN_ENABLE |
PCIE_CLIENT_ARI_ENABLE |
PCIE_CLIENT_CONF_LANE_NUM(rockchip->lanes) |
PCIE_CLIENT_MODE_RC,
PCIE_CLIENT_CONFIG);
err = phy_power_on(rockchip->phy);
if (err) {
dev_err(dev, "fail to power on phy, err %d\n", err);
return err;
}
err = reset_control_deassert(rockchip->mgmt_sticky_rst);
if (err) {
dev_err(dev, "deassert mgmt_sticky_rst err %d\n", err);
return err;
}
err = reset_control_deassert(rockchip->core_rst);
if (err) {
dev_err(dev, "deassert core_rst err %d\n", err);
return err;
}
err = reset_control_deassert(rockchip->mgmt_rst);
if (err) {
dev_err(dev, "deassert mgmt_rst err %d\n", err);
return err;
}
err = reset_control_deassert(rockchip->pipe_rst);
if (err) {
dev_err(dev, "deassert pipe_rst err %d\n", err);
return err;
}
status = rockchip_pcie_read(rockchip, PCIE_CORE_CTRL_PLC1);
status = (status & ~PCIE_CORE_CTRL_PLC1_FTS_MASK) |
(PCIE_CORE_CTRL_PLC1_FTS_CNT << PCIE_CORE_CTRL_PLC1_FTS_SHIFT);
rockchip_pcie_write(rockchip, status, PCIE_CORE_CTRL_PLC1);
rockchip_pcie_set_power_limit(rockchip);
status = rockchip_pcie_read(rockchip, PCIE_RC_CONFIG_LCS);
status |= PCI_EXP_LNKSTA_SLC << 16;
rockchip_pcie_write(rockchip, status, PCIE_RC_CONFIG_LCS);
status = rockchip_pcie_read(rockchip, PCIE_RC_CONFIG_LCS);
status |= PCI_EXP_LNKCTL_RCB;
rockchip_pcie_write(rockchip, status, PCIE_RC_CONFIG_LCS);
rockchip_pcie_write(rockchip, PCIE_CLIENT_LINK_TRAIN_ENABLE,
PCIE_CLIENT_CONFIG);
gpiod_set_value(rockchip->ep_gpio, 1);
err = readl_poll_timeout(rockchip->apb_base + PCIE_CLIENT_BASIC_STATUS1,
status, PCIE_LINK_UP(status), 20,
500 * USEC_PER_MSEC);
if (err) {
dev_err(dev, "PCIe link training gen1 timeout!\n");
return -ETIMEDOUT;
}
if (rockchip->link_gen == 2) {
status = rockchip_pcie_read(rockchip, PCIE_RC_CONFIG_LCS);
status |= PCI_EXP_LNKCTL_RL;
rockchip_pcie_write(rockchip, status, PCIE_RC_CONFIG_LCS);
err = readl_poll_timeout(rockchip->apb_base + PCIE_CORE_CTRL,
status, PCIE_LINK_IS_GEN2(status), 20,
500 * USEC_PER_MSEC);
if (err)
dev_dbg(dev, "PCIe link training gen2 timeout, fall back to gen1!\n");
}
status = rockchip_pcie_read(rockchip, PCIE_CORE_CTRL);
status = 0x1 << ((status & PCIE_CORE_PL_CONF_LANE_MASK) >>
PCIE_CORE_PL_CONF_LANE_SHIFT);
dev_dbg(dev, "current link width is x%d\n", status);
rockchip_pcie_write(rockchip, ROCKCHIP_VENDOR_ID,
PCIE_CORE_CONFIG_VENDOR);
rockchip_pcie_write(rockchip,
PCI_CLASS_BRIDGE_PCI << PCIE_RC_CONFIG_SCC_SHIFT,
PCIE_RC_CONFIG_RID_CCR);
status = rockchip_pcie_read(rockchip, PCIE_RC_CONFIG_THP_CAP);
status &= ~PCIE_RC_CONFIG_THP_CAP_NEXT_MASK;
rockchip_pcie_write(rockchip, status, PCIE_RC_CONFIG_THP_CAP);
if (of_property_read_bool(dev->of_node, "aspm-no-l0s")) {
status = rockchip_pcie_read(rockchip, PCIE_RC_CONFIG_LINK_CAP);
status &= ~PCIE_RC_CONFIG_LINK_CAP_L0S;
rockchip_pcie_write(rockchip, status, PCIE_RC_CONFIG_LINK_CAP);
}
rockchip_pcie_write(rockchip, 0x0, PCIE_RC_BAR_CONF);
rockchip_pcie_write(rockchip,
(RC_REGION_0_ADDR_TRANS_L + RC_REGION_0_PASS_BITS),
PCIE_CORE_OB_REGION_ADDR0);
rockchip_pcie_write(rockchip, RC_REGION_0_ADDR_TRANS_H,
PCIE_CORE_OB_REGION_ADDR1);
rockchip_pcie_write(rockchip, 0x0080000a, PCIE_CORE_OB_REGION_DESC0);
rockchip_pcie_write(rockchip, 0x0, PCIE_CORE_OB_REGION_DESC1);
return 0;
}
static irqreturn_t rockchip_pcie_subsys_irq_handler(int irq, void *arg)
{
struct rockchip_pcie *rockchip = arg;
struct device *dev = rockchip->dev;
u32 reg;
u32 sub_reg;
reg = rockchip_pcie_read(rockchip, PCIE_CLIENT_INT_STATUS);
if (reg & PCIE_CLIENT_INT_LOCAL) {
dev_dbg(dev, "local interrupt received\n");
sub_reg = rockchip_pcie_read(rockchip, PCIE_CORE_INT_STATUS);
if (sub_reg & PCIE_CORE_INT_PRFPE)
dev_dbg(dev, "parity error detected while reading from the PNP receive FIFO RAM\n");
if (sub_reg & PCIE_CORE_INT_CRFPE)
dev_dbg(dev, "parity error detected while reading from the Completion Receive FIFO RAM\n");
if (sub_reg & PCIE_CORE_INT_RRPE)
dev_dbg(dev, "parity error detected while reading from replay buffer RAM\n");
if (sub_reg & PCIE_CORE_INT_PRFO)
dev_dbg(dev, "overflow occurred in the PNP receive FIFO\n");
if (sub_reg & PCIE_CORE_INT_CRFO)
dev_dbg(dev, "overflow occurred in the completion receive FIFO\n");
if (sub_reg & PCIE_CORE_INT_RT)
dev_dbg(dev, "replay timer timed out\n");
if (sub_reg & PCIE_CORE_INT_RTR)
dev_dbg(dev, "replay timer rolled over after 4 transmissions of the same TLP\n");
if (sub_reg & PCIE_CORE_INT_PE)
dev_dbg(dev, "phy error detected on receive side\n");
if (sub_reg & PCIE_CORE_INT_MTR)
dev_dbg(dev, "malformed TLP received from the link\n");
if (sub_reg & PCIE_CORE_INT_UCR)
dev_dbg(dev, "malformed TLP received from the link\n");
if (sub_reg & PCIE_CORE_INT_FCE)
dev_dbg(dev, "an error was observed in the flow control advertisements from the other side\n");
if (sub_reg & PCIE_CORE_INT_CT)
dev_dbg(dev, "a request timed out waiting for completion\n");
if (sub_reg & PCIE_CORE_INT_UTC)
dev_dbg(dev, "unmapped TC error\n");
if (sub_reg & PCIE_CORE_INT_MMVC)
dev_dbg(dev, "MSI mask register changes\n");
rockchip_pcie_write(rockchip, sub_reg, PCIE_CORE_INT_STATUS);
} else if (reg & PCIE_CLIENT_INT_PHY) {
dev_dbg(dev, "phy link changes\n");
rockchip_pcie_update_txcredit_mui(rockchip);
rockchip_pcie_clr_bw_int(rockchip);
}
rockchip_pcie_write(rockchip, reg & PCIE_CLIENT_INT_LOCAL,
PCIE_CLIENT_INT_STATUS);
return IRQ_HANDLED;
}
static irqreturn_t rockchip_pcie_client_irq_handler(int irq, void *arg)
{
struct rockchip_pcie *rockchip = arg;
struct device *dev = rockchip->dev;
u32 reg;
reg = rockchip_pcie_read(rockchip, PCIE_CLIENT_INT_STATUS);
if (reg & PCIE_CLIENT_INT_LEGACY_DONE)
dev_dbg(dev, "legacy done interrupt received\n");
if (reg & PCIE_CLIENT_INT_MSG)
dev_dbg(dev, "message done interrupt received\n");
if (reg & PCIE_CLIENT_INT_HOT_RST)
dev_dbg(dev, "hot reset interrupt received\n");
if (reg & PCIE_CLIENT_INT_DPA)
dev_dbg(dev, "dpa interrupt received\n");
if (reg & PCIE_CLIENT_INT_FATAL_ERR)
dev_dbg(dev, "fatal error interrupt received\n");
if (reg & PCIE_CLIENT_INT_NFATAL_ERR)
dev_dbg(dev, "no fatal error interrupt received\n");
if (reg & PCIE_CLIENT_INT_CORR_ERR)
dev_dbg(dev, "correctable error interrupt received\n");
if (reg & PCIE_CLIENT_INT_PHY)
dev_dbg(dev, "phy interrupt received\n");
rockchip_pcie_write(rockchip, reg & (PCIE_CLIENT_INT_LEGACY_DONE |
PCIE_CLIENT_INT_MSG | PCIE_CLIENT_INT_HOT_RST |
PCIE_CLIENT_INT_DPA | PCIE_CLIENT_INT_FATAL_ERR |
PCIE_CLIENT_INT_NFATAL_ERR |
PCIE_CLIENT_INT_CORR_ERR |
PCIE_CLIENT_INT_PHY),
PCIE_CLIENT_INT_STATUS);
return IRQ_HANDLED;
}
static void rockchip_pcie_legacy_int_handler(struct irq_desc *desc)
{
struct irq_chip *chip = irq_desc_get_chip(desc);
struct rockchip_pcie *rockchip = irq_desc_get_handler_data(desc);
struct device *dev = rockchip->dev;
u32 reg;
u32 hwirq;
u32 virq;
chained_irq_enter(chip, desc);
reg = rockchip_pcie_read(rockchip, PCIE_CLIENT_INT_STATUS);
reg = (reg & PCIE_CLIENT_INTR_MASK) >> PCIE_CLIENT_INTR_SHIFT;
while (reg) {
hwirq = ffs(reg) - 1;
reg &= ~BIT(hwirq);
virq = irq_find_mapping(rockchip->irq_domain, hwirq);
if (virq)
generic_handle_irq(virq);
else
dev_err(dev, "unexpected IRQ, INT%d\n", hwirq);
}
chained_irq_exit(chip, desc);
}
static int rockchip_pcie_parse_dt(struct rockchip_pcie *rockchip)
{
struct device *dev = rockchip->dev;
struct platform_device *pdev = to_platform_device(dev);
struct device_node *node = dev->of_node;
struct resource *regs;
int irq;
int err;
regs = platform_get_resource_byname(pdev,
IORESOURCE_MEM,
"axi-base");
rockchip->reg_base = devm_pci_remap_cfg_resource(dev, regs);
if (IS_ERR(rockchip->reg_base))
return PTR_ERR(rockchip->reg_base);
regs = platform_get_resource_byname(pdev,
IORESOURCE_MEM,
"apb-base");
rockchip->apb_base = devm_ioremap_resource(dev, regs);
if (IS_ERR(rockchip->apb_base))
return PTR_ERR(rockchip->apb_base);
rockchip->phy = devm_phy_get(dev, "pcie-phy");
if (IS_ERR(rockchip->phy)) {
if (PTR_ERR(rockchip->phy) != -EPROBE_DEFER)
dev_err(dev, "missing phy\n");
return PTR_ERR(rockchip->phy);
}
rockchip->lanes = 1;
err = of_property_read_u32(node, "num-lanes", &rockchip->lanes);
if (!err && (rockchip->lanes == 0 ||
rockchip->lanes == 3 ||
rockchip->lanes > 4)) {
dev_warn(dev, "invalid num-lanes, default to use one lane\n");
rockchip->lanes = 1;
}
rockchip->link_gen = of_pci_get_max_link_speed(node);
if (rockchip->link_gen < 0 || rockchip->link_gen > 2)
rockchip->link_gen = 2;
rockchip->core_rst = devm_reset_control_get(dev, "core");
if (IS_ERR(rockchip->core_rst)) {
if (PTR_ERR(rockchip->core_rst) != -EPROBE_DEFER)
dev_err(dev, "missing core reset property in node\n");
return PTR_ERR(rockchip->core_rst);
}
rockchip->mgmt_rst = devm_reset_control_get(dev, "mgmt");
if (IS_ERR(rockchip->mgmt_rst)) {
if (PTR_ERR(rockchip->mgmt_rst) != -EPROBE_DEFER)
dev_err(dev, "missing mgmt reset property in node\n");
return PTR_ERR(rockchip->mgmt_rst);
}
rockchip->mgmt_sticky_rst = devm_reset_control_get(dev, "mgmt-sticky");
if (IS_ERR(rockchip->mgmt_sticky_rst)) {
if (PTR_ERR(rockchip->mgmt_sticky_rst) != -EPROBE_DEFER)
dev_err(dev, "missing mgmt-sticky reset property in node\n");
return PTR_ERR(rockchip->mgmt_sticky_rst);
}
rockchip->pipe_rst = devm_reset_control_get(dev, "pipe");
if (IS_ERR(rockchip->pipe_rst)) {
if (PTR_ERR(rockchip->pipe_rst) != -EPROBE_DEFER)
dev_err(dev, "missing pipe reset property in node\n");
return PTR_ERR(rockchip->pipe_rst);
}
rockchip->pm_rst = devm_reset_control_get(dev, "pm");
if (IS_ERR(rockchip->pm_rst)) {
if (PTR_ERR(rockchip->pm_rst) != -EPROBE_DEFER)
dev_err(dev, "missing pm reset property in node\n");
return PTR_ERR(rockchip->pm_rst);
}
rockchip->pclk_rst = devm_reset_control_get(dev, "pclk");
if (IS_ERR(rockchip->pclk_rst)) {
if (PTR_ERR(rockchip->pclk_rst) != -EPROBE_DEFER)
dev_err(dev, "missing pclk reset property in node\n");
return PTR_ERR(rockchip->pclk_rst);
}
rockchip->aclk_rst = devm_reset_control_get(dev, "aclk");
if (IS_ERR(rockchip->aclk_rst)) {
if (PTR_ERR(rockchip->aclk_rst) != -EPROBE_DEFER)
dev_err(dev, "missing aclk reset property in node\n");
return PTR_ERR(rockchip->aclk_rst);
}
rockchip->ep_gpio = devm_gpiod_get(dev, "ep", GPIOD_OUT_HIGH);
if (IS_ERR(rockchip->ep_gpio)) {
dev_err(dev, "missing ep-gpios property in node\n");
return PTR_ERR(rockchip->ep_gpio);
}
rockchip->aclk_pcie = devm_clk_get(dev, "aclk");
if (IS_ERR(rockchip->aclk_pcie)) {
dev_err(dev, "aclk clock not found\n");
return PTR_ERR(rockchip->aclk_pcie);
}
rockchip->aclk_perf_pcie = devm_clk_get(dev, "aclk-perf");
if (IS_ERR(rockchip->aclk_perf_pcie)) {
dev_err(dev, "aclk_perf clock not found\n");
return PTR_ERR(rockchip->aclk_perf_pcie);
}
rockchip->hclk_pcie = devm_clk_get(dev, "hclk");
if (IS_ERR(rockchip->hclk_pcie)) {
dev_err(dev, "hclk clock not found\n");
return PTR_ERR(rockchip->hclk_pcie);
}
rockchip->clk_pcie_pm = devm_clk_get(dev, "pm");
if (IS_ERR(rockchip->clk_pcie_pm)) {
dev_err(dev, "pm clock not found\n");
return PTR_ERR(rockchip->clk_pcie_pm);
}
irq = platform_get_irq_byname(pdev, "sys");
if (irq < 0) {
dev_err(dev, "missing sys IRQ resource\n");
return -EINVAL;
}
err = devm_request_irq(dev, irq, rockchip_pcie_subsys_irq_handler,
IRQF_SHARED, "pcie-sys", rockchip);
if (err) {
dev_err(dev, "failed to request PCIe subsystem IRQ\n");
return err;
}
irq = platform_get_irq_byname(pdev, "legacy");
if (irq < 0) {
dev_err(dev, "missing legacy IRQ resource\n");
return -EINVAL;
}
irq_set_chained_handler_and_data(irq,
rockchip_pcie_legacy_int_handler,
rockchip);
irq = platform_get_irq_byname(pdev, "client");
if (irq < 0) {
dev_err(dev, "missing client IRQ resource\n");
return -EINVAL;
}
err = devm_request_irq(dev, irq, rockchip_pcie_client_irq_handler,
IRQF_SHARED, "pcie-client", rockchip);
if (err) {
dev_err(dev, "failed to request PCIe client IRQ\n");
return err;
}
rockchip->vpcie3v3 = devm_regulator_get_optional(dev, "vpcie3v3");
if (IS_ERR(rockchip->vpcie3v3)) {
if (PTR_ERR(rockchip->vpcie3v3) == -EPROBE_DEFER)
return -EPROBE_DEFER;
dev_info(dev, "no vpcie3v3 regulator found\n");
}
rockchip->vpcie1v8 = devm_regulator_get_optional(dev, "vpcie1v8");
if (IS_ERR(rockchip->vpcie1v8)) {
if (PTR_ERR(rockchip->vpcie1v8) == -EPROBE_DEFER)
return -EPROBE_DEFER;
dev_info(dev, "no vpcie1v8 regulator found\n");
}
rockchip->vpcie0v9 = devm_regulator_get_optional(dev, "vpcie0v9");
if (IS_ERR(rockchip->vpcie0v9)) {
if (PTR_ERR(rockchip->vpcie0v9) == -EPROBE_DEFER)
return -EPROBE_DEFER;
dev_info(dev, "no vpcie0v9 regulator found\n");
}
return 0;
}
static int rockchip_pcie_set_vpcie(struct rockchip_pcie *rockchip)
{
struct device *dev = rockchip->dev;
int err;
if (!IS_ERR(rockchip->vpcie3v3)) {
err = regulator_enable(rockchip->vpcie3v3);
if (err) {
dev_err(dev, "fail to enable vpcie3v3 regulator\n");
goto err_out;
}
}
if (!IS_ERR(rockchip->vpcie1v8)) {
err = regulator_enable(rockchip->vpcie1v8);
if (err) {
dev_err(dev, "fail to enable vpcie1v8 regulator\n");
goto err_disable_3v3;
}
}
if (!IS_ERR(rockchip->vpcie0v9)) {
err = regulator_enable(rockchip->vpcie0v9);
if (err) {
dev_err(dev, "fail to enable vpcie0v9 regulator\n");
goto err_disable_1v8;
}
}
return 0;
err_disable_1v8:
if (!IS_ERR(rockchip->vpcie1v8))
regulator_disable(rockchip->vpcie1v8);
err_disable_3v3:
if (!IS_ERR(rockchip->vpcie3v3))
regulator_disable(rockchip->vpcie3v3);
err_out:
return err;
}
static void rockchip_pcie_enable_interrupts(struct rockchip_pcie *rockchip)
{
rockchip_pcie_write(rockchip, (PCIE_CLIENT_INT_CLI << 16) &
(~PCIE_CLIENT_INT_CLI), PCIE_CLIENT_INT_MASK);
rockchip_pcie_write(rockchip, (u32)(~PCIE_CORE_INT),
PCIE_CORE_INT_MASK);
rockchip_pcie_enable_bw_int(rockchip);
}
static int rockchip_pcie_intx_map(struct irq_domain *domain, unsigned int irq,
irq_hw_number_t hwirq)
{
irq_set_chip_and_handler(irq, &dummy_irq_chip, handle_simple_irq);
irq_set_chip_data(irq, domain->host_data);
return 0;
}
static int rockchip_pcie_init_irq_domain(struct rockchip_pcie *rockchip)
{
struct device *dev = rockchip->dev;
struct device_node *intc = of_get_next_child(dev->of_node, NULL);
if (!intc) {
dev_err(dev, "missing child interrupt-controller node\n");
return -EINVAL;
}
rockchip->irq_domain = irq_domain_add_linear(intc, 4,
&intx_domain_ops, rockchip);
if (!rockchip->irq_domain) {
dev_err(dev, "failed to get a INTx IRQ domain\n");
return -EINVAL;
}
return 0;
}
static int rockchip_pcie_prog_ob_atu(struct rockchip_pcie *rockchip,
int region_no, int type, u8 num_pass_bits,
u32 lower_addr, u32 upper_addr)
{
u32 ob_addr_0;
u32 ob_addr_1;
u32 ob_desc_0;
u32 aw_offset;
if (region_no >= MAX_AXI_WRAPPER_REGION_NUM)
return -EINVAL;
if (num_pass_bits + 1 < 8)
return -EINVAL;
if (num_pass_bits > 63)
return -EINVAL;
if (region_no == 0) {
if (AXI_REGION_0_SIZE < (2ULL << num_pass_bits))
return -EINVAL;
}
if (region_no != 0) {
if (AXI_REGION_SIZE < (2ULL << num_pass_bits))
return -EINVAL;
}
aw_offset = (region_no << OB_REG_SIZE_SHIFT);
ob_addr_0 = num_pass_bits & PCIE_CORE_OB_REGION_ADDR0_NUM_BITS;
ob_addr_0 |= lower_addr & PCIE_CORE_OB_REGION_ADDR0_LO_ADDR;
ob_addr_1 = upper_addr;
ob_desc_0 = (1 << 23 | type);
rockchip_pcie_write(rockchip, ob_addr_0,
PCIE_CORE_OB_REGION_ADDR0 + aw_offset);
rockchip_pcie_write(rockchip, ob_addr_1,
PCIE_CORE_OB_REGION_ADDR1 + aw_offset);
rockchip_pcie_write(rockchip, ob_desc_0,
PCIE_CORE_OB_REGION_DESC0 + aw_offset);
rockchip_pcie_write(rockchip, 0,
PCIE_CORE_OB_REGION_DESC1 + aw_offset);
return 0;
}
static int rockchip_pcie_prog_ib_atu(struct rockchip_pcie *rockchip,
int region_no, u8 num_pass_bits,
u32 lower_addr, u32 upper_addr)
{
u32 ib_addr_0;
u32 ib_addr_1;
u32 aw_offset;
if (region_no > MAX_AXI_IB_ROOTPORT_REGION_NUM)
return -EINVAL;
if (num_pass_bits + 1 < MIN_AXI_ADDR_BITS_PASSED)
return -EINVAL;
if (num_pass_bits > 63)
return -EINVAL;
aw_offset = (region_no << IB_ROOT_PORT_REG_SIZE_SHIFT);
ib_addr_0 = num_pass_bits & PCIE_CORE_IB_REGION_ADDR0_NUM_BITS;
ib_addr_0 |= (lower_addr << 8) & PCIE_CORE_IB_REGION_ADDR0_LO_ADDR;
ib_addr_1 = upper_addr;
rockchip_pcie_write(rockchip, ib_addr_0, PCIE_RP_IB_ADDR0 + aw_offset);
rockchip_pcie_write(rockchip, ib_addr_1, PCIE_RP_IB_ADDR1 + aw_offset);
return 0;
}
static int rockchip_cfg_atu(struct rockchip_pcie *rockchip)
{
struct device *dev = rockchip->dev;
int offset;
int err;
int reg_no;
for (reg_no = 0; reg_no < (rockchip->mem_size >> 20); reg_no++) {
err = rockchip_pcie_prog_ob_atu(rockchip, reg_no + 1,
AXI_WRAPPER_MEM_WRITE,
20 - 1,
rockchip->mem_bus_addr +
(reg_no << 20),
0);
if (err) {
dev_err(dev, "program RC mem outbound ATU failed\n");
return err;
}
}
err = rockchip_pcie_prog_ib_atu(rockchip, 2, 32 - 1, 0x0, 0);
if (err) {
dev_err(dev, "program RC mem inbound ATU failed\n");
return err;
}
offset = rockchip->mem_size >> 20;
for (reg_no = 0; reg_no < (rockchip->io_size >> 20); reg_no++) {
err = rockchip_pcie_prog_ob_atu(rockchip,
reg_no + 1 + offset,
AXI_WRAPPER_IO_WRITE,
20 - 1,
rockchip->io_bus_addr +
(reg_no << 20),
0);
if (err) {
dev_err(dev, "program RC io outbound ATU failed\n");
return err;
}
}
rockchip_pcie_prog_ob_atu(rockchip, reg_no + 1 + offset,
AXI_WRAPPER_NOR_MSG,
20 - 1, 0, 0);
rockchip->msg_bus_addr = rockchip->mem_bus_addr +
((reg_no + offset) << 20);
return err;
}
static int rockchip_pcie_wait_l2(struct rockchip_pcie *rockchip)
{
u32 value;
int err;
writel(0x0, rockchip->msg_region + PCIE_RC_SEND_PME_OFF);
err = readl_poll_timeout(rockchip->apb_base + PCIE_CLIENT_DEBUG_OUT_0,
value, PCIE_LINK_IS_L2(value), 20,
jiffies_to_usecs(5 * HZ));
if (err) {
dev_err(rockchip->dev, "PCIe link enter L2 timeout!\n");
return err;
}
return 0;
}
static int __maybe_unused rockchip_pcie_suspend_noirq(struct device *dev)
{
struct rockchip_pcie *rockchip = dev_get_drvdata(dev);
int ret;
rockchip_pcie_write(rockchip, (PCIE_CLIENT_INT_CLI << 16) |
PCIE_CLIENT_INT_CLI, PCIE_CLIENT_INT_MASK);
rockchip_pcie_write(rockchip, (u32)PCIE_CORE_INT, PCIE_CORE_INT_MASK);
ret = rockchip_pcie_wait_l2(rockchip);
if (ret) {
rockchip_pcie_enable_interrupts(rockchip);
return ret;
}
phy_power_off(rockchip->phy);
phy_exit(rockchip->phy);
clk_disable_unprepare(rockchip->clk_pcie_pm);
clk_disable_unprepare(rockchip->hclk_pcie);
clk_disable_unprepare(rockchip->aclk_perf_pcie);
clk_disable_unprepare(rockchip->aclk_pcie);
return ret;
}
static int __maybe_unused rockchip_pcie_resume_noirq(struct device *dev)
{
struct rockchip_pcie *rockchip = dev_get_drvdata(dev);
int err;
clk_prepare_enable(rockchip->clk_pcie_pm);
clk_prepare_enable(rockchip->hclk_pcie);
clk_prepare_enable(rockchip->aclk_perf_pcie);
clk_prepare_enable(rockchip->aclk_pcie);
err = rockchip_pcie_init_port(rockchip);
if (err)
return err;
err = rockchip_cfg_atu(rockchip);
if (err)
return err;
rockchip_pcie_update_txcredit_mui(rockchip);
rockchip_pcie_enable_interrupts(rockchip);
return 0;
}
static int rockchip_pcie_probe(struct platform_device *pdev)
{
struct rockchip_pcie *rockchip;
struct device *dev = &pdev->dev;
struct pci_bus *bus, *child;
struct resource_entry *win;
resource_size_t io_base;
struct resource *mem;
struct resource *io;
int err;
LIST_HEAD(res);
if (!dev->of_node)
return -ENODEV;
rockchip = devm_kzalloc(dev, sizeof(*rockchip), GFP_KERNEL);
if (!rockchip)
return -ENOMEM;
platform_set_drvdata(pdev, rockchip);
rockchip->dev = dev;
err = rockchip_pcie_parse_dt(rockchip);
if (err)
return err;
err = clk_prepare_enable(rockchip->aclk_pcie);
if (err) {
dev_err(dev, "unable to enable aclk_pcie clock\n");
goto err_aclk_pcie;
}
err = clk_prepare_enable(rockchip->aclk_perf_pcie);
if (err) {
dev_err(dev, "unable to enable aclk_perf_pcie clock\n");
goto err_aclk_perf_pcie;
}
err = clk_prepare_enable(rockchip->hclk_pcie);
if (err) {
dev_err(dev, "unable to enable hclk_pcie clock\n");
goto err_hclk_pcie;
}
err = clk_prepare_enable(rockchip->clk_pcie_pm);
if (err) {
dev_err(dev, "unable to enable hclk_pcie clock\n");
goto err_pcie_pm;
}
err = rockchip_pcie_set_vpcie(rockchip);
if (err) {
dev_err(dev, "failed to set vpcie regulator\n");
goto err_set_vpcie;
}
err = rockchip_pcie_init_port(rockchip);
if (err)
goto err_vpcie;
rockchip_pcie_enable_interrupts(rockchip);
err = rockchip_pcie_init_irq_domain(rockchip);
if (err < 0)
goto err_vpcie;
err = of_pci_get_host_bridge_resources(dev->of_node, 0, 0xff,
&res, &io_base);
if (err)
goto err_vpcie;
err = devm_request_pci_bus_resources(dev, &res);
if (err)
goto err_free_res;
resource_list_for_each_entry(win, &res) {
switch (resource_type(win->res)) {
case IORESOURCE_IO:
io = win->res;
io->name = "I/O";
rockchip->io_size = resource_size(io);
rockchip->io_bus_addr = io->start - win->offset;
err = pci_remap_iospace(io, io_base);
if (err) {
dev_warn(dev, "error %d: failed to map resource %pR\n",
err, io);
continue;
}
rockchip->io = io;
break;
case IORESOURCE_MEM:
mem = win->res;
mem->name = "MEM";
rockchip->mem_size = resource_size(mem);
rockchip->mem_bus_addr = mem->start - win->offset;
break;
case IORESOURCE_BUS:
rockchip->root_bus_nr = win->res->start;
break;
default:
continue;
}
}
err = rockchip_cfg_atu(rockchip);
if (err)
goto err_free_res;
rockchip->msg_region = devm_ioremap(rockchip->dev,
rockchip->msg_bus_addr, SZ_1M);
if (!rockchip->msg_region) {
err = -ENOMEM;
goto err_free_res;
}
bus = pci_scan_root_bus(&pdev->dev, 0, &rockchip_pcie_ops, rockchip, &res);
if (!bus) {
err = -ENOMEM;
goto err_free_res;
}
rockchip->root_bus = bus;
pci_bus_size_bridges(bus);
pci_bus_assign_resources(bus);
list_for_each_entry(child, &bus->children, node)
pcie_bus_configure_settings(child);
pci_bus_add_devices(bus);
return 0;
err_free_res:
pci_free_resource_list(&res);
err_vpcie:
if (!IS_ERR(rockchip->vpcie3v3))
regulator_disable(rockchip->vpcie3v3);
if (!IS_ERR(rockchip->vpcie1v8))
regulator_disable(rockchip->vpcie1v8);
if (!IS_ERR(rockchip->vpcie0v9))
regulator_disable(rockchip->vpcie0v9);
err_set_vpcie:
clk_disable_unprepare(rockchip->clk_pcie_pm);
err_pcie_pm:
clk_disable_unprepare(rockchip->hclk_pcie);
err_hclk_pcie:
clk_disable_unprepare(rockchip->aclk_perf_pcie);
err_aclk_perf_pcie:
clk_disable_unprepare(rockchip->aclk_pcie);
err_aclk_pcie:
return err;
}
static int rockchip_pcie_remove(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct rockchip_pcie *rockchip = dev_get_drvdata(dev);
pci_stop_root_bus(rockchip->root_bus);
pci_remove_root_bus(rockchip->root_bus);
pci_unmap_iospace(rockchip->io);
irq_domain_remove(rockchip->irq_domain);
phy_power_off(rockchip->phy);
phy_exit(rockchip->phy);
clk_disable_unprepare(rockchip->clk_pcie_pm);
clk_disable_unprepare(rockchip->hclk_pcie);
clk_disable_unprepare(rockchip->aclk_perf_pcie);
clk_disable_unprepare(rockchip->aclk_pcie);
if (!IS_ERR(rockchip->vpcie3v3))
regulator_disable(rockchip->vpcie3v3);
if (!IS_ERR(rockchip->vpcie1v8))
regulator_disable(rockchip->vpcie1v8);
if (!IS_ERR(rockchip->vpcie0v9))
regulator_disable(rockchip->vpcie0v9);
return 0;
}
