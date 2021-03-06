static int pcie_phy_poll_ack(struct imx6_pcie *imx6_pcie, int exp_val)
{
struct dw_pcie *pci = imx6_pcie->pci;
u32 val;
u32 max_iterations = 10;
u32 wait_counter = 0;
do {
val = dw_pcie_readl_dbi(pci, PCIE_PHY_STAT);
val = (val >> PCIE_PHY_STAT_ACK_LOC) & 0x1;
wait_counter++;
if (val == exp_val)
return 0;
udelay(1);
} while (wait_counter < max_iterations);
return -ETIMEDOUT;
}
static int pcie_phy_wait_ack(struct imx6_pcie *imx6_pcie, int addr)
{
struct dw_pcie *pci = imx6_pcie->pci;
u32 val;
int ret;
val = addr << PCIE_PHY_CTRL_DATA_LOC;
dw_pcie_writel_dbi(pci, PCIE_PHY_CTRL, val);
val |= (0x1 << PCIE_PHY_CTRL_CAP_ADR_LOC);
dw_pcie_writel_dbi(pci, PCIE_PHY_CTRL, val);
ret = pcie_phy_poll_ack(imx6_pcie, 1);
if (ret)
return ret;
val = addr << PCIE_PHY_CTRL_DATA_LOC;
dw_pcie_writel_dbi(pci, PCIE_PHY_CTRL, val);
return pcie_phy_poll_ack(imx6_pcie, 0);
}
static int pcie_phy_read(struct imx6_pcie *imx6_pcie, int addr, int *data)
{
struct dw_pcie *pci = imx6_pcie->pci;
u32 val, phy_ctl;
int ret;
ret = pcie_phy_wait_ack(imx6_pcie, addr);
if (ret)
return ret;
phy_ctl = 0x1 << PCIE_PHY_CTRL_RD_LOC;
dw_pcie_writel_dbi(pci, PCIE_PHY_CTRL, phy_ctl);
ret = pcie_phy_poll_ack(imx6_pcie, 1);
if (ret)
return ret;
val = dw_pcie_readl_dbi(pci, PCIE_PHY_STAT);
*data = val & 0xffff;
dw_pcie_writel_dbi(pci, PCIE_PHY_CTRL, 0x00);
return pcie_phy_poll_ack(imx6_pcie, 0);
}
static int pcie_phy_write(struct imx6_pcie *imx6_pcie, int addr, int data)
{
struct dw_pcie *pci = imx6_pcie->pci;
u32 var;
int ret;
ret = pcie_phy_wait_ack(imx6_pcie, addr);
if (ret)
return ret;
var = data << PCIE_PHY_CTRL_DATA_LOC;
dw_pcie_writel_dbi(pci, PCIE_PHY_CTRL, var);
var |= (0x1 << PCIE_PHY_CTRL_CAP_DAT_LOC);
dw_pcie_writel_dbi(pci, PCIE_PHY_CTRL, var);
ret = pcie_phy_poll_ack(imx6_pcie, 1);
if (ret)
return ret;
var = data << PCIE_PHY_CTRL_DATA_LOC;
dw_pcie_writel_dbi(pci, PCIE_PHY_CTRL, var);
ret = pcie_phy_poll_ack(imx6_pcie, 0);
if (ret)
return ret;
var = 0x1 << PCIE_PHY_CTRL_WR_LOC;
dw_pcie_writel_dbi(pci, PCIE_PHY_CTRL, var);
ret = pcie_phy_poll_ack(imx6_pcie, 1);
if (ret)
return ret;
var = data << PCIE_PHY_CTRL_DATA_LOC;
dw_pcie_writel_dbi(pci, PCIE_PHY_CTRL, var);
ret = pcie_phy_poll_ack(imx6_pcie, 0);
if (ret)
return ret;
dw_pcie_writel_dbi(pci, PCIE_PHY_CTRL, 0x0);
return 0;
}
static void imx6_pcie_reset_phy(struct imx6_pcie *imx6_pcie)
{
u32 tmp;
pcie_phy_read(imx6_pcie, PHY_RX_OVRD_IN_LO, &tmp);
tmp |= (PHY_RX_OVRD_IN_LO_RX_DATA_EN |
PHY_RX_OVRD_IN_LO_RX_PLL_EN);
pcie_phy_write(imx6_pcie, PHY_RX_OVRD_IN_LO, tmp);
usleep_range(2000, 3000);
pcie_phy_read(imx6_pcie, PHY_RX_OVRD_IN_LO, &tmp);
tmp &= ~(PHY_RX_OVRD_IN_LO_RX_DATA_EN |
PHY_RX_OVRD_IN_LO_RX_PLL_EN);
pcie_phy_write(imx6_pcie, PHY_RX_OVRD_IN_LO, tmp);
}
static int imx6q_pcie_abort_handler(unsigned long addr,
unsigned int fsr, struct pt_regs *regs)
{
unsigned long pc = instruction_pointer(regs);
unsigned long instr = *(unsigned long *)pc;
int reg = (instr >> 12) & 15;
if ((instr & 0x0c100000) == 0x04100000) {
unsigned long val;
if (instr & 0x00400000)
val = 255;
else
val = -1;
regs->uregs[reg] = val;
regs->ARM_pc += 4;
return 0;
}
if ((instr & 0x0e100090) == 0x00100090) {
regs->uregs[reg] = -1;
regs->ARM_pc += 4;
return 0;
}
return 1;
}
static void imx6_pcie_assert_core_reset(struct imx6_pcie *imx6_pcie)
{
switch (imx6_pcie->variant) {
case IMX7D:
reset_control_assert(imx6_pcie->pciephy_reset);
reset_control_assert(imx6_pcie->apps_reset);
break;
case IMX6SX:
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR12,
IMX6SX_GPR12_PCIE_TEST_POWERDOWN,
IMX6SX_GPR12_PCIE_TEST_POWERDOWN);
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR5,
IMX6SX_GPR5_PCIE_BTNRST_RESET,
IMX6SX_GPR5_PCIE_BTNRST_RESET);
break;
case IMX6QP:
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR1,
IMX6Q_GPR1_PCIE_SW_RST,
IMX6Q_GPR1_PCIE_SW_RST);
break;
case IMX6Q:
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR1,
IMX6Q_GPR1_PCIE_TEST_PD, 1 << 18);
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR1,
IMX6Q_GPR1_PCIE_REF_CLK_EN, 0 << 16);
break;
}
}
static int imx6_pcie_enable_ref_clk(struct imx6_pcie *imx6_pcie)
{
struct dw_pcie *pci = imx6_pcie->pci;
struct device *dev = pci->dev;
int ret = 0;
switch (imx6_pcie->variant) {
case IMX6SX:
ret = clk_prepare_enable(imx6_pcie->pcie_inbound_axi);
if (ret) {
dev_err(dev, "unable to enable pcie_axi clock\n");
break;
}
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR12,
IMX6SX_GPR12_PCIE_TEST_POWERDOWN, 0);
break;
case IMX6QP:
case IMX6Q:
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR1,
IMX6Q_GPR1_PCIE_TEST_PD, 0 << 18);
udelay(10);
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR1,
IMX6Q_GPR1_PCIE_REF_CLK_EN, 1 << 16);
break;
case IMX7D:
break;
}
return ret;
}
static void imx7d_pcie_wait_for_phy_pll_lock(struct imx6_pcie *imx6_pcie)
{
u32 val;
unsigned int retries;
struct device *dev = imx6_pcie->pci->dev;
for (retries = 0; retries < PHY_PLL_LOCK_WAIT_MAX_RETRIES; retries++) {
regmap_read(imx6_pcie->iomuxc_gpr, IOMUXC_GPR22, &val);
if (val & IMX7D_GPR22_PCIE_PHY_PLL_LOCKED)
return;
usleep_range(PHY_PLL_LOCK_WAIT_USLEEP_MIN,
PHY_PLL_LOCK_WAIT_USLEEP_MAX);
}
dev_err(dev, "PCIe PLL lock timeout\n");
}
static void imx6_pcie_deassert_core_reset(struct imx6_pcie *imx6_pcie)
{
struct dw_pcie *pci = imx6_pcie->pci;
struct device *dev = pci->dev;
int ret;
ret = clk_prepare_enable(imx6_pcie->pcie_phy);
if (ret) {
dev_err(dev, "unable to enable pcie_phy clock\n");
return;
}
ret = clk_prepare_enable(imx6_pcie->pcie_bus);
if (ret) {
dev_err(dev, "unable to enable pcie_bus clock\n");
goto err_pcie_bus;
}
ret = clk_prepare_enable(imx6_pcie->pcie);
if (ret) {
dev_err(dev, "unable to enable pcie clock\n");
goto err_pcie;
}
ret = imx6_pcie_enable_ref_clk(imx6_pcie);
if (ret) {
dev_err(dev, "unable to enable pcie ref clock\n");
goto err_ref_clk;
}
usleep_range(200, 500);
if (gpio_is_valid(imx6_pcie->reset_gpio)) {
gpio_set_value_cansleep(imx6_pcie->reset_gpio,
imx6_pcie->gpio_active_high);
msleep(100);
gpio_set_value_cansleep(imx6_pcie->reset_gpio,
!imx6_pcie->gpio_active_high);
}
switch (imx6_pcie->variant) {
case IMX7D:
reset_control_deassert(imx6_pcie->pciephy_reset);
imx7d_pcie_wait_for_phy_pll_lock(imx6_pcie);
break;
case IMX6SX:
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR5,
IMX6SX_GPR5_PCIE_BTNRST_RESET, 0);
break;
case IMX6QP:
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR1,
IMX6Q_GPR1_PCIE_SW_RST, 0);
usleep_range(200, 500);
break;
case IMX6Q:
break;
}
return;
err_ref_clk:
clk_disable_unprepare(imx6_pcie->pcie);
err_pcie:
clk_disable_unprepare(imx6_pcie->pcie_bus);
err_pcie_bus:
clk_disable_unprepare(imx6_pcie->pcie_phy);
}
static void imx6_pcie_init_phy(struct imx6_pcie *imx6_pcie)
{
switch (imx6_pcie->variant) {
case IMX7D:
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR12,
IMX7D_GPR12_PCIE_PHY_REFCLK_SEL, 0);
break;
case IMX6SX:
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR12,
IMX6SX_GPR12_PCIE_RX_EQ_MASK,
IMX6SX_GPR12_PCIE_RX_EQ_2);
default:
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR12,
IMX6Q_GPR12_PCIE_CTL_2, 0 << 10);
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR12,
IMX6Q_GPR12_LOS_LEVEL, 9 << 4);
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR8,
IMX6Q_GPR8_TX_DEEMPH_GEN1,
imx6_pcie->tx_deemph_gen1 << 0);
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR8,
IMX6Q_GPR8_TX_DEEMPH_GEN2_3P5DB,
imx6_pcie->tx_deemph_gen2_3p5db << 6);
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR8,
IMX6Q_GPR8_TX_DEEMPH_GEN2_6DB,
imx6_pcie->tx_deemph_gen2_6db << 12);
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR8,
IMX6Q_GPR8_TX_SWING_FULL,
imx6_pcie->tx_swing_full << 18);
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR8,
IMX6Q_GPR8_TX_SWING_LOW,
imx6_pcie->tx_swing_low << 25);
break;
}
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR12,
IMX6Q_GPR12_DEVICE_TYPE, PCI_EXP_TYPE_ROOT_PORT << 12);
}
static int imx6_pcie_wait_for_link(struct imx6_pcie *imx6_pcie)
{
struct dw_pcie *pci = imx6_pcie->pci;
struct device *dev = pci->dev;
if (!dw_pcie_wait_for_link(pci))
return 0;
dev_dbg(dev, "DEBUG_R0: 0x%08x, DEBUG_R1: 0x%08x\n",
dw_pcie_readl_dbi(pci, PCIE_PHY_DEBUG_R0),
dw_pcie_readl_dbi(pci, PCIE_PHY_DEBUG_R1));
return -ETIMEDOUT;
}
static int imx6_pcie_wait_for_speed_change(struct imx6_pcie *imx6_pcie)
{
struct dw_pcie *pci = imx6_pcie->pci;
struct device *dev = pci->dev;
u32 tmp;
unsigned int retries;
for (retries = 0; retries < 200; retries++) {
tmp = dw_pcie_readl_dbi(pci, PCIE_LINK_WIDTH_SPEED_CONTROL);
if (!(tmp & PORT_LOGIC_SPEED_CHANGE))
return 0;
usleep_range(100, 1000);
}
dev_err(dev, "Speed change timeout\n");
return -EINVAL;
}
static irqreturn_t imx6_pcie_msi_handler(int irq, void *arg)
{
struct imx6_pcie *imx6_pcie = arg;
struct dw_pcie *pci = imx6_pcie->pci;
struct pcie_port *pp = &pci->pp;
return dw_handle_msi_irq(pp);
}
static int imx6_pcie_establish_link(struct imx6_pcie *imx6_pcie)
{
struct dw_pcie *pci = imx6_pcie->pci;
struct device *dev = pci->dev;
u32 tmp;
int ret;
tmp = dw_pcie_readl_dbi(pci, PCIE_RC_LCR);
tmp &= ~PCIE_RC_LCR_MAX_LINK_SPEEDS_MASK;
tmp |= PCIE_RC_LCR_MAX_LINK_SPEEDS_GEN1;
dw_pcie_writel_dbi(pci, PCIE_RC_LCR, tmp);
if (imx6_pcie->variant == IMX7D)
reset_control_deassert(imx6_pcie->apps_reset);
else
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR12,
IMX6Q_GPR12_PCIE_CTL_2, 1 << 10);
ret = imx6_pcie_wait_for_link(imx6_pcie);
if (ret)
goto err_reset_phy;
if (imx6_pcie->link_gen == 2) {
tmp = dw_pcie_readl_dbi(pci, PCIE_RC_LCR);
tmp &= ~PCIE_RC_LCR_MAX_LINK_SPEEDS_MASK;
tmp |= PCIE_RC_LCR_MAX_LINK_SPEEDS_GEN2;
dw_pcie_writel_dbi(pci, PCIE_RC_LCR, tmp);
tmp = dw_pcie_readl_dbi(pci, PCIE_LINK_WIDTH_SPEED_CONTROL);
tmp |= PORT_LOGIC_SPEED_CHANGE;
dw_pcie_writel_dbi(pci, PCIE_LINK_WIDTH_SPEED_CONTROL, tmp);
if (imx6_pcie->variant != IMX7D) {
ret = imx6_pcie_wait_for_speed_change(imx6_pcie);
if (ret) {
dev_err(dev, "Failed to bring link up!\n");
goto err_reset_phy;
}
}
ret = imx6_pcie_wait_for_link(imx6_pcie);
if (ret) {
dev_err(dev, "Failed to bring link up!\n");
goto err_reset_phy;
}
} else {
dev_info(dev, "Link: Gen2 disabled\n");
}
tmp = dw_pcie_readl_dbi(pci, PCIE_RC_LCSR);
dev_info(dev, "Link up, Gen%i\n", (tmp >> 16) & 0xf);
return 0;
err_reset_phy:
dev_dbg(dev, "PHY DEBUG_R0=0x%08x DEBUG_R1=0x%08x\n",
dw_pcie_readl_dbi(pci, PCIE_PHY_DEBUG_R0),
dw_pcie_readl_dbi(pci, PCIE_PHY_DEBUG_R1));
imx6_pcie_reset_phy(imx6_pcie);
return ret;
}
static void imx6_pcie_host_init(struct pcie_port *pp)
{
struct dw_pcie *pci = to_dw_pcie_from_pp(pp);
struct imx6_pcie *imx6_pcie = to_imx6_pcie(pci);
imx6_pcie_assert_core_reset(imx6_pcie);
imx6_pcie_init_phy(imx6_pcie);
imx6_pcie_deassert_core_reset(imx6_pcie);
dw_pcie_setup_rc(pp);
imx6_pcie_establish_link(imx6_pcie);
if (IS_ENABLED(CONFIG_PCI_MSI))
dw_pcie_msi_init(pp);
}
static int imx6_pcie_link_up(struct dw_pcie *pci)
{
return dw_pcie_readl_dbi(pci, PCIE_PHY_DEBUG_R1) &
PCIE_PHY_DEBUG_R1_XMLH_LINK_UP;
}
static int imx6_add_pcie_port(struct imx6_pcie *imx6_pcie,
struct platform_device *pdev)
{
struct dw_pcie *pci = imx6_pcie->pci;
struct pcie_port *pp = &pci->pp;
struct device *dev = &pdev->dev;
int ret;
if (IS_ENABLED(CONFIG_PCI_MSI)) {
pp->msi_irq = platform_get_irq_byname(pdev, "msi");
if (pp->msi_irq <= 0) {
dev_err(dev, "failed to get MSI irq\n");
return -ENODEV;
}
ret = devm_request_irq(dev, pp->msi_irq,
imx6_pcie_msi_handler,
IRQF_SHARED | IRQF_NO_THREAD,
"mx6-pcie-msi", imx6_pcie);
if (ret) {
dev_err(dev, "failed to request MSI irq\n");
return ret;
}
}
pp->root_bus_nr = -1;
pp->ops = &imx6_pcie_host_ops;
ret = dw_pcie_host_init(pp);
if (ret) {
dev_err(dev, "failed to initialize host\n");
return ret;
}
return 0;
}
static int imx6_pcie_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct dw_pcie *pci;
struct imx6_pcie *imx6_pcie;
struct resource *dbi_base;
struct device_node *node = dev->of_node;
int ret;
imx6_pcie = devm_kzalloc(dev, sizeof(*imx6_pcie), GFP_KERNEL);
if (!imx6_pcie)
return -ENOMEM;
pci = devm_kzalloc(dev, sizeof(*pci), GFP_KERNEL);
if (!pci)
return -ENOMEM;
pci->dev = dev;
pci->ops = &dw_pcie_ops;
imx6_pcie->pci = pci;
imx6_pcie->variant =
(enum imx6_pcie_variants)of_device_get_match_data(dev);
dbi_base = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pci->dbi_base = devm_ioremap_resource(dev, dbi_base);
if (IS_ERR(pci->dbi_base))
return PTR_ERR(pci->dbi_base);
imx6_pcie->reset_gpio = of_get_named_gpio(node, "reset-gpio", 0);
imx6_pcie->gpio_active_high = of_property_read_bool(node,
"reset-gpio-active-high");
if (gpio_is_valid(imx6_pcie->reset_gpio)) {
ret = devm_gpio_request_one(dev, imx6_pcie->reset_gpio,
imx6_pcie->gpio_active_high ?
GPIOF_OUT_INIT_HIGH :
GPIOF_OUT_INIT_LOW,
"PCIe reset");
if (ret) {
dev_err(dev, "unable to get reset gpio\n");
return ret;
}
} else if (imx6_pcie->reset_gpio == -EPROBE_DEFER) {
return imx6_pcie->reset_gpio;
}
imx6_pcie->pcie_phy = devm_clk_get(dev, "pcie_phy");
if (IS_ERR(imx6_pcie->pcie_phy)) {
dev_err(dev, "pcie_phy clock source missing or invalid\n");
return PTR_ERR(imx6_pcie->pcie_phy);
}
imx6_pcie->pcie_bus = devm_clk_get(dev, "pcie_bus");
if (IS_ERR(imx6_pcie->pcie_bus)) {
dev_err(dev, "pcie_bus clock source missing or invalid\n");
return PTR_ERR(imx6_pcie->pcie_bus);
}
imx6_pcie->pcie = devm_clk_get(dev, "pcie");
if (IS_ERR(imx6_pcie->pcie)) {
dev_err(dev, "pcie clock source missing or invalid\n");
return PTR_ERR(imx6_pcie->pcie);
}
switch (imx6_pcie->variant) {
case IMX6SX:
imx6_pcie->pcie_inbound_axi = devm_clk_get(dev,
"pcie_inbound_axi");
if (IS_ERR(imx6_pcie->pcie_inbound_axi)) {
dev_err(dev, "pcie_inbound_axi clock missing or invalid\n");
return PTR_ERR(imx6_pcie->pcie_inbound_axi);
}
break;
case IMX7D:
imx6_pcie->pciephy_reset = devm_reset_control_get(dev,
"pciephy");
if (IS_ERR(imx6_pcie->pciephy_reset)) {
dev_err(dev, "Failed to get PCIEPHY reset control\n");
return PTR_ERR(imx6_pcie->pciephy_reset);
}
imx6_pcie->apps_reset = devm_reset_control_get(dev, "apps");
if (IS_ERR(imx6_pcie->apps_reset)) {
dev_err(dev, "Failed to get PCIE APPS reset control\n");
return PTR_ERR(imx6_pcie->apps_reset);
}
break;
default:
break;
}
imx6_pcie->iomuxc_gpr =
syscon_regmap_lookup_by_compatible("fsl,imx6q-iomuxc-gpr");
if (IS_ERR(imx6_pcie->iomuxc_gpr)) {
dev_err(dev, "unable to find iomuxc registers\n");
return PTR_ERR(imx6_pcie->iomuxc_gpr);
}
if (of_property_read_u32(node, "fsl,tx-deemph-gen1",
&imx6_pcie->tx_deemph_gen1))
imx6_pcie->tx_deemph_gen1 = 0;
if (of_property_read_u32(node, "fsl,tx-deemph-gen2-3p5db",
&imx6_pcie->tx_deemph_gen2_3p5db))
imx6_pcie->tx_deemph_gen2_3p5db = 0;
if (of_property_read_u32(node, "fsl,tx-deemph-gen2-6db",
&imx6_pcie->tx_deemph_gen2_6db))
imx6_pcie->tx_deemph_gen2_6db = 20;
if (of_property_read_u32(node, "fsl,tx-swing-full",
&imx6_pcie->tx_swing_full))
imx6_pcie->tx_swing_full = 127;
if (of_property_read_u32(node, "fsl,tx-swing-low",
&imx6_pcie->tx_swing_low))
imx6_pcie->tx_swing_low = 127;
ret = of_property_read_u32(node, "fsl,max-link-speed",
&imx6_pcie->link_gen);
if (ret)
imx6_pcie->link_gen = 1;
platform_set_drvdata(pdev, imx6_pcie);
ret = imx6_add_pcie_port(imx6_pcie, pdev);
if (ret < 0)
return ret;
return 0;
}
static void imx6_pcie_shutdown(struct platform_device *pdev)
{
struct imx6_pcie *imx6_pcie = platform_get_drvdata(pdev);
imx6_pcie_assert_core_reset(imx6_pcie);
}
static int __init imx6_pcie_init(void)
{
hook_fault_code(8, imx6q_pcie_abort_handler, SIGBUS, 0,
"external abort on non-linefetch");
return platform_driver_register(&imx6_pcie_driver);
}
