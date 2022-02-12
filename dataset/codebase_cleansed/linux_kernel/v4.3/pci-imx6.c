static int pcie_phy_poll_ack(void __iomem *dbi_base, int exp_val)
{
u32 val;
u32 max_iterations = 10;
u32 wait_counter = 0;
do {
val = readl(dbi_base + PCIE_PHY_STAT);
val = (val >> PCIE_PHY_STAT_ACK_LOC) & 0x1;
wait_counter++;
if (val == exp_val)
return 0;
udelay(1);
} while (wait_counter < max_iterations);
return -ETIMEDOUT;
}
static int pcie_phy_wait_ack(void __iomem *dbi_base, int addr)
{
u32 val;
int ret;
val = addr << PCIE_PHY_CTRL_DATA_LOC;
writel(val, dbi_base + PCIE_PHY_CTRL);
val |= (0x1 << PCIE_PHY_CTRL_CAP_ADR_LOC);
writel(val, dbi_base + PCIE_PHY_CTRL);
ret = pcie_phy_poll_ack(dbi_base, 1);
if (ret)
return ret;
val = addr << PCIE_PHY_CTRL_DATA_LOC;
writel(val, dbi_base + PCIE_PHY_CTRL);
return pcie_phy_poll_ack(dbi_base, 0);
}
static int pcie_phy_read(void __iomem *dbi_base, int addr , int *data)
{
u32 val, phy_ctl;
int ret;
ret = pcie_phy_wait_ack(dbi_base, addr);
if (ret)
return ret;
phy_ctl = 0x1 << PCIE_PHY_CTRL_RD_LOC;
writel(phy_ctl, dbi_base + PCIE_PHY_CTRL);
ret = pcie_phy_poll_ack(dbi_base, 1);
if (ret)
return ret;
val = readl(dbi_base + PCIE_PHY_STAT);
*data = val & 0xffff;
writel(0x00, dbi_base + PCIE_PHY_CTRL);
return pcie_phy_poll_ack(dbi_base, 0);
}
static int pcie_phy_write(void __iomem *dbi_base, int addr, int data)
{
u32 var;
int ret;
ret = pcie_phy_wait_ack(dbi_base, addr);
if (ret)
return ret;
var = data << PCIE_PHY_CTRL_DATA_LOC;
writel(var, dbi_base + PCIE_PHY_CTRL);
var |= (0x1 << PCIE_PHY_CTRL_CAP_DAT_LOC);
writel(var, dbi_base + PCIE_PHY_CTRL);
ret = pcie_phy_poll_ack(dbi_base, 1);
if (ret)
return ret;
var = data << PCIE_PHY_CTRL_DATA_LOC;
writel(var, dbi_base + PCIE_PHY_CTRL);
ret = pcie_phy_poll_ack(dbi_base, 0);
if (ret)
return ret;
var = 0x1 << PCIE_PHY_CTRL_WR_LOC;
writel(var, dbi_base + PCIE_PHY_CTRL);
ret = pcie_phy_poll_ack(dbi_base, 1);
if (ret)
return ret;
var = data << PCIE_PHY_CTRL_DATA_LOC;
writel(var, dbi_base + PCIE_PHY_CTRL);
ret = pcie_phy_poll_ack(dbi_base, 0);
if (ret)
return ret;
writel(0x0, dbi_base + PCIE_PHY_CTRL);
return 0;
}
static int imx6q_pcie_abort_handler(unsigned long addr,
unsigned int fsr, struct pt_regs *regs)
{
return 0;
}
static int imx6_pcie_assert_core_reset(struct pcie_port *pp)
{
struct imx6_pcie *imx6_pcie = to_imx6_pcie(pp);
u32 val, gpr1, gpr12;
regmap_read(imx6_pcie->iomuxc_gpr, IOMUXC_GPR1, &gpr1);
regmap_read(imx6_pcie->iomuxc_gpr, IOMUXC_GPR12, &gpr12);
if ((gpr1 & IMX6Q_GPR1_PCIE_REF_CLK_EN) &&
(gpr12 & IMX6Q_GPR12_PCIE_CTL_2)) {
val = readl(pp->dbi_base + PCIE_PL_PFLR);
val &= ~PCIE_PL_PFLR_LINK_STATE_MASK;
val |= PCIE_PL_PFLR_FORCE_LINK;
writel(val, pp->dbi_base + PCIE_PL_PFLR);
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR12,
IMX6Q_GPR12_PCIE_CTL_2, 0 << 10);
}
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR1,
IMX6Q_GPR1_PCIE_TEST_PD, 1 << 18);
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR1,
IMX6Q_GPR1_PCIE_REF_CLK_EN, 0 << 16);
return 0;
}
static int imx6_pcie_deassert_core_reset(struct pcie_port *pp)
{
struct imx6_pcie *imx6_pcie = to_imx6_pcie(pp);
int ret;
ret = clk_prepare_enable(imx6_pcie->pcie_phy);
if (ret) {
dev_err(pp->dev, "unable to enable pcie_phy clock\n");
goto err_pcie_phy;
}
ret = clk_prepare_enable(imx6_pcie->pcie_bus);
if (ret) {
dev_err(pp->dev, "unable to enable pcie_bus clock\n");
goto err_pcie_bus;
}
ret = clk_prepare_enable(imx6_pcie->pcie);
if (ret) {
dev_err(pp->dev, "unable to enable pcie clock\n");
goto err_pcie;
}
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR1,
IMX6Q_GPR1_PCIE_TEST_PD, 0 << 18);
udelay(10);
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR1,
IMX6Q_GPR1_PCIE_REF_CLK_EN, 1 << 16);
usleep_range(200, 500);
if (gpio_is_valid(imx6_pcie->reset_gpio)) {
gpio_set_value(imx6_pcie->reset_gpio, 0);
msleep(100);
gpio_set_value(imx6_pcie->reset_gpio, 1);
}
return 0;
err_pcie:
clk_disable_unprepare(imx6_pcie->pcie_bus);
err_pcie_bus:
clk_disable_unprepare(imx6_pcie->pcie_phy);
err_pcie_phy:
return ret;
}
static void imx6_pcie_init_phy(struct pcie_port *pp)
{
struct imx6_pcie *imx6_pcie = to_imx6_pcie(pp);
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR12,
IMX6Q_GPR12_PCIE_CTL_2, 0 << 10);
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR12,
IMX6Q_GPR12_DEVICE_TYPE, PCI_EXP_TYPE_ROOT_PORT << 12);
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR12,
IMX6Q_GPR12_LOS_LEVEL, 9 << 4);
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR8,
IMX6Q_GPR8_TX_DEEMPH_GEN1, 0 << 0);
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR8,
IMX6Q_GPR8_TX_DEEMPH_GEN2_3P5DB, 0 << 6);
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR8,
IMX6Q_GPR8_TX_DEEMPH_GEN2_6DB, 20 << 12);
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR8,
IMX6Q_GPR8_TX_SWING_FULL, 127 << 18);
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR8,
IMX6Q_GPR8_TX_SWING_LOW, 127 << 25);
}
static int imx6_pcie_wait_for_link(struct pcie_port *pp)
{
unsigned int retries;
for (retries = 0; retries < 200; retries++) {
if (dw_pcie_link_up(pp))
return 0;
usleep_range(100, 1000);
}
dev_err(pp->dev, "phy link never came up\n");
dev_dbg(pp->dev, "DEBUG_R0: 0x%08x, DEBUG_R1: 0x%08x\n",
readl(pp->dbi_base + PCIE_PHY_DEBUG_R0),
readl(pp->dbi_base + PCIE_PHY_DEBUG_R1));
return -EINVAL;
}
static int imx6_pcie_wait_for_speed_change(struct pcie_port *pp)
{
u32 tmp;
unsigned int retries;
for (retries = 0; retries < 200; retries++) {
tmp = readl(pp->dbi_base + PCIE_LINK_WIDTH_SPEED_CONTROL);
if (!(tmp & PORT_LOGIC_SPEED_CHANGE))
return 0;
usleep_range(100, 1000);
}
dev_err(pp->dev, "Speed change timeout\n");
return -EINVAL;
}
static irqreturn_t imx6_pcie_msi_handler(int irq, void *arg)
{
struct pcie_port *pp = arg;
return dw_handle_msi_irq(pp);
}
static int imx6_pcie_establish_link(struct pcie_port *pp)
{
struct imx6_pcie *imx6_pcie = to_imx6_pcie(pp);
u32 tmp;
int ret;
tmp = readl(pp->dbi_base + PCIE_RC_LCR);
tmp &= ~PCIE_RC_LCR_MAX_LINK_SPEEDS_MASK;
tmp |= PCIE_RC_LCR_MAX_LINK_SPEEDS_GEN1;
writel(tmp, pp->dbi_base + PCIE_RC_LCR);
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR12,
IMX6Q_GPR12_PCIE_CTL_2, 1 << 10);
ret = imx6_pcie_wait_for_link(pp);
if (ret)
return ret;
tmp = readl(pp->dbi_base + PCIE_RC_LCR);
tmp &= ~PCIE_RC_LCR_MAX_LINK_SPEEDS_MASK;
tmp |= PCIE_RC_LCR_MAX_LINK_SPEEDS_GEN2;
writel(tmp, pp->dbi_base + PCIE_RC_LCR);
tmp = readl(pp->dbi_base + PCIE_LINK_WIDTH_SPEED_CONTROL);
tmp |= PORT_LOGIC_SPEED_CHANGE;
writel(tmp, pp->dbi_base + PCIE_LINK_WIDTH_SPEED_CONTROL);
ret = imx6_pcie_wait_for_speed_change(pp);
if (ret) {
dev_err(pp->dev, "Failed to bring link up!\n");
return ret;
}
ret = imx6_pcie_wait_for_link(pp);
if (ret) {
dev_err(pp->dev, "Failed to bring link up!\n");
return ret;
}
tmp = readl(pp->dbi_base + PCIE_RC_LCSR);
dev_dbg(pp->dev, "Link up, Gen=%i\n", (tmp >> 16) & 0xf);
return 0;
}
static void imx6_pcie_host_init(struct pcie_port *pp)
{
imx6_pcie_assert_core_reset(pp);
imx6_pcie_init_phy(pp);
imx6_pcie_deassert_core_reset(pp);
dw_pcie_setup_rc(pp);
imx6_pcie_establish_link(pp);
if (IS_ENABLED(CONFIG_PCI_MSI))
dw_pcie_msi_init(pp);
}
static void imx6_pcie_reset_phy(struct pcie_port *pp)
{
u32 tmp;
pcie_phy_read(pp->dbi_base, PHY_RX_OVRD_IN_LO, &tmp);
tmp |= (PHY_RX_OVRD_IN_LO_RX_DATA_EN |
PHY_RX_OVRD_IN_LO_RX_PLL_EN);
pcie_phy_write(pp->dbi_base, PHY_RX_OVRD_IN_LO, tmp);
usleep_range(2000, 3000);
pcie_phy_read(pp->dbi_base, PHY_RX_OVRD_IN_LO, &tmp);
tmp &= ~(PHY_RX_OVRD_IN_LO_RX_DATA_EN |
PHY_RX_OVRD_IN_LO_RX_PLL_EN);
pcie_phy_write(pp->dbi_base, PHY_RX_OVRD_IN_LO, tmp);
}
static int imx6_pcie_link_up(struct pcie_port *pp)
{
u32 rc, debug_r0, rx_valid;
int count = 5;
while (1) {
rc = readl(pp->dbi_base + PCIE_PHY_DEBUG_R1);
if (!(rc & PCIE_PHY_DEBUG_R1_XMLH_LINK_UP))
break;
if (!(rc & PCIE_PHY_DEBUG_R1_XMLH_LINK_IN_TRAINING))
return 1;
if (!count--)
break;
dev_dbg(pp->dev, "Link is up, but still in training\n");
usleep_range(1000, 2000);
}
pcie_phy_read(pp->dbi_base, PCIE_PHY_RX_ASIC_OUT, &rx_valid);
debug_r0 = readl(pp->dbi_base + PCIE_PHY_DEBUG_R0);
if (rx_valid & 0x01)
return 0;
if ((debug_r0 & 0x3f) != 0x0d)
return 0;
dev_err(pp->dev, "transition to gen2 is stuck, reset PHY!\n");
dev_dbg(pp->dev, "debug_r0=%08x debug_r1=%08x\n", debug_r0, rc);
imx6_pcie_reset_phy(pp);
return 0;
}
static int __init imx6_add_pcie_port(struct pcie_port *pp,
struct platform_device *pdev)
{
int ret;
if (IS_ENABLED(CONFIG_PCI_MSI)) {
pp->msi_irq = platform_get_irq_byname(pdev, "msi");
if (pp->msi_irq <= 0) {
dev_err(&pdev->dev, "failed to get MSI irq\n");
return -ENODEV;
}
ret = devm_request_irq(&pdev->dev, pp->msi_irq,
imx6_pcie_msi_handler,
IRQF_SHARED, "mx6-pcie-msi", pp);
if (ret) {
dev_err(&pdev->dev, "failed to request MSI irq\n");
return -ENODEV;
}
}
pp->root_bus_nr = -1;
pp->ops = &imx6_pcie_host_ops;
ret = dw_pcie_host_init(pp);
if (ret) {
dev_err(&pdev->dev, "failed to initialize host\n");
return ret;
}
return 0;
}
static int __init imx6_pcie_probe(struct platform_device *pdev)
{
struct imx6_pcie *imx6_pcie;
struct pcie_port *pp;
struct device_node *np = pdev->dev.of_node;
struct resource *dbi_base;
int ret;
imx6_pcie = devm_kzalloc(&pdev->dev, sizeof(*imx6_pcie), GFP_KERNEL);
if (!imx6_pcie)
return -ENOMEM;
pp = &imx6_pcie->pp;
pp->dev = &pdev->dev;
hook_fault_code(16 + 6, imx6q_pcie_abort_handler, SIGBUS, 0,
"imprecise external abort");
dbi_base = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pp->dbi_base = devm_ioremap_resource(&pdev->dev, dbi_base);
if (IS_ERR(pp->dbi_base))
return PTR_ERR(pp->dbi_base);
imx6_pcie->reset_gpio = of_get_named_gpio(np, "reset-gpio", 0);
if (gpio_is_valid(imx6_pcie->reset_gpio)) {
ret = devm_gpio_request_one(&pdev->dev, imx6_pcie->reset_gpio,
GPIOF_OUT_INIT_LOW, "PCIe reset");
if (ret) {
dev_err(&pdev->dev, "unable to get reset gpio\n");
return ret;
}
}
imx6_pcie->pcie_phy = devm_clk_get(&pdev->dev, "pcie_phy");
if (IS_ERR(imx6_pcie->pcie_phy)) {
dev_err(&pdev->dev,
"pcie_phy clock source missing or invalid\n");
return PTR_ERR(imx6_pcie->pcie_phy);
}
imx6_pcie->pcie_bus = devm_clk_get(&pdev->dev, "pcie_bus");
if (IS_ERR(imx6_pcie->pcie_bus)) {
dev_err(&pdev->dev,
"pcie_bus clock source missing or invalid\n");
return PTR_ERR(imx6_pcie->pcie_bus);
}
imx6_pcie->pcie = devm_clk_get(&pdev->dev, "pcie");
if (IS_ERR(imx6_pcie->pcie)) {
dev_err(&pdev->dev,
"pcie clock source missing or invalid\n");
return PTR_ERR(imx6_pcie->pcie);
}
imx6_pcie->iomuxc_gpr =
syscon_regmap_lookup_by_compatible("fsl,imx6q-iomuxc-gpr");
if (IS_ERR(imx6_pcie->iomuxc_gpr)) {
dev_err(&pdev->dev, "unable to find iomuxc registers\n");
return PTR_ERR(imx6_pcie->iomuxc_gpr);
}
ret = imx6_add_pcie_port(pp, pdev);
if (ret < 0)
return ret;
platform_set_drvdata(pdev, imx6_pcie);
return 0;
}
static void imx6_pcie_shutdown(struct platform_device *pdev)
{
struct imx6_pcie *imx6_pcie = platform_get_drvdata(pdev);
imx6_pcie_assert_core_reset(&imx6_pcie->pp);
}
static int __init imx6_pcie_init(void)
{
return platform_driver_probe(&imx6_pcie_driver, imx6_pcie_probe);
}
