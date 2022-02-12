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
ret = pcie_phy_poll_ack(dbi_base, 0);
if (ret)
return ret;
return 0;
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
ret = pcie_phy_poll_ack(dbi_base, 0);
if (ret)
return ret;
return 0;
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
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR1,
IMX6Q_GPR1_PCIE_TEST_PD, 1 << 18);
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR12,
IMX6Q_GPR12_PCIE_CTL_2, 1 << 10);
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR1,
IMX6Q_GPR1_PCIE_REF_CLK_EN, 0 << 16);
gpio_set_value(imx6_pcie->reset_gpio, 0);
msleep(100);
gpio_set_value(imx6_pcie->reset_gpio, 1);
return 0;
}
static int imx6_pcie_deassert_core_reset(struct pcie_port *pp)
{
struct imx6_pcie *imx6_pcie = to_imx6_pcie(pp);
int ret;
if (gpio_is_valid(imx6_pcie->power_on_gpio))
gpio_set_value(imx6_pcie->power_on_gpio, 1);
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR1,
IMX6Q_GPR1_PCIE_TEST_PD, 0 << 18);
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR1,
IMX6Q_GPR1_PCIE_REF_CLK_EN, 1 << 16);
ret = clk_prepare_enable(imx6_pcie->sata_ref_100m);
if (ret) {
dev_err(pp->dev, "unable to enable sata_ref_100m\n");
goto err_sata_ref;
}
ret = clk_prepare_enable(imx6_pcie->pcie_ref_125m);
if (ret) {
dev_err(pp->dev, "unable to enable pcie_ref_125m\n");
goto err_pcie_ref;
}
ret = clk_prepare_enable(imx6_pcie->lvds_gate);
if (ret) {
dev_err(pp->dev, "unable to enable lvds_gate\n");
goto err_lvds_gate;
}
ret = clk_prepare_enable(imx6_pcie->pcie_axi);
if (ret) {
dev_err(pp->dev, "unable to enable pcie_axi\n");
goto err_pcie_axi;
}
usleep_range(200, 500);
return 0;
err_pcie_axi:
clk_disable_unprepare(imx6_pcie->lvds_gate);
err_lvds_gate:
clk_disable_unprepare(imx6_pcie->pcie_ref_125m);
err_pcie_ref:
clk_disable_unprepare(imx6_pcie->sata_ref_100m);
err_sata_ref:
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
static void imx6_pcie_host_init(struct pcie_port *pp)
{
int count = 0;
struct imx6_pcie *imx6_pcie = to_imx6_pcie(pp);
imx6_pcie_assert_core_reset(pp);
imx6_pcie_init_phy(pp);
imx6_pcie_deassert_core_reset(pp);
dw_pcie_setup_rc(pp);
regmap_update_bits(imx6_pcie->iomuxc_gpr, IOMUXC_GPR12,
IMX6Q_GPR12_PCIE_CTL_2, 1 << 10);
while (!dw_pcie_link_up(pp)) {
usleep_range(100, 1000);
count++;
if (count >= 200) {
dev_err(pp->dev, "phy link never came up\n");
dev_dbg(pp->dev,
"DEBUG_R0: 0x%08x, DEBUG_R1: 0x%08x\n",
readl(pp->dbi_base + PCIE_PHY_DEBUG_R0),
readl(pp->dbi_base + PCIE_PHY_DEBUG_R1));
break;
}
}
return;
}
static int imx6_pcie_link_up(struct pcie_port *pp)
{
u32 rc, ltssm, rx_valid, temp;
rc = readl(pp->dbi_base + PCIE_PHY_DEBUG_R1) & (0x1 << (36 - 32));
if (rc)
return -EAGAIN;
pcie_phy_read(pp->dbi_base, PCIE_PHY_RX_ASIC_OUT, &rx_valid);
ltssm = readl(pp->dbi_base + PCIE_PHY_DEBUG_R0) & 0x3F;
if (rx_valid & 0x01)
return 0;
if (ltssm != 0x0d)
return 0;
dev_err(pp->dev, "transition to gen2 is stuck, reset PHY!\n");
pcie_phy_read(pp->dbi_base,
PHY_RX_OVRD_IN_LO, &temp);
temp |= (PHY_RX_OVRD_IN_LO_RX_DATA_EN
| PHY_RX_OVRD_IN_LO_RX_PLL_EN);
pcie_phy_write(pp->dbi_base,
PHY_RX_OVRD_IN_LO, temp);
usleep_range(2000, 3000);
pcie_phy_read(pp->dbi_base,
PHY_RX_OVRD_IN_LO, &temp);
temp &= ~(PHY_RX_OVRD_IN_LO_RX_DATA_EN
| PHY_RX_OVRD_IN_LO_RX_PLL_EN);
pcie_phy_write(pp->dbi_base,
PHY_RX_OVRD_IN_LO, temp);
return 0;
}
static int imx6_add_pcie_port(struct pcie_port *pp,
struct platform_device *pdev)
{
int ret;
pp->irq = platform_get_irq(pdev, 0);
if (!pp->irq) {
dev_err(&pdev->dev, "failed to get irq\n");
return -ENODEV;
}
pp->root_bus_nr = -1;
pp->ops = &imx6_pcie_host_ops;
spin_lock_init(&pp->conf_lock);
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
if (!dbi_base) {
dev_err(&pdev->dev, "dbi_base memory resource not found\n");
return -ENODEV;
}
pp->dbi_base = devm_ioremap_resource(&pdev->dev, dbi_base);
if (IS_ERR(pp->dbi_base)) {
ret = PTR_ERR(pp->dbi_base);
goto err;
}
imx6_pcie->reset_gpio = of_get_named_gpio(np, "reset-gpio", 0);
if (!gpio_is_valid(imx6_pcie->reset_gpio)) {
dev_err(&pdev->dev, "no reset-gpio defined\n");
ret = -ENODEV;
}
ret = devm_gpio_request_one(&pdev->dev,
imx6_pcie->reset_gpio,
GPIOF_OUT_INIT_LOW,
"PCIe reset");
if (ret) {
dev_err(&pdev->dev, "unable to get reset gpio\n");
goto err;
}
imx6_pcie->power_on_gpio = of_get_named_gpio(np, "power-on-gpio", 0);
if (gpio_is_valid(imx6_pcie->power_on_gpio)) {
ret = devm_gpio_request_one(&pdev->dev,
imx6_pcie->power_on_gpio,
GPIOF_OUT_INIT_LOW,
"PCIe power enable");
if (ret) {
dev_err(&pdev->dev, "unable to get power-on gpio\n");
goto err;
}
}
imx6_pcie->wake_up_gpio = of_get_named_gpio(np, "wake-up-gpio", 0);
if (gpio_is_valid(imx6_pcie->wake_up_gpio)) {
ret = devm_gpio_request_one(&pdev->dev,
imx6_pcie->wake_up_gpio,
GPIOF_IN,
"PCIe wake up");
if (ret) {
dev_err(&pdev->dev, "unable to get wake-up gpio\n");
goto err;
}
}
imx6_pcie->disable_gpio = of_get_named_gpio(np, "disable-gpio", 0);
if (gpio_is_valid(imx6_pcie->disable_gpio)) {
ret = devm_gpio_request_one(&pdev->dev,
imx6_pcie->disable_gpio,
GPIOF_OUT_INIT_HIGH,
"PCIe disable endpoint");
if (ret) {
dev_err(&pdev->dev, "unable to get disable-ep gpio\n");
goto err;
}
}
imx6_pcie->lvds_gate = devm_clk_get(&pdev->dev, "lvds_gate");
if (IS_ERR(imx6_pcie->lvds_gate)) {
dev_err(&pdev->dev,
"lvds_gate clock select missing or invalid\n");
ret = PTR_ERR(imx6_pcie->lvds_gate);
goto err;
}
imx6_pcie->sata_ref_100m = devm_clk_get(&pdev->dev, "sata_ref_100m");
if (IS_ERR(imx6_pcie->sata_ref_100m)) {
dev_err(&pdev->dev,
"sata_ref_100m clock source missing or invalid\n");
ret = PTR_ERR(imx6_pcie->sata_ref_100m);
goto err;
}
imx6_pcie->pcie_ref_125m = devm_clk_get(&pdev->dev, "pcie_ref_125m");
if (IS_ERR(imx6_pcie->pcie_ref_125m)) {
dev_err(&pdev->dev,
"pcie_ref_125m clock source missing or invalid\n");
ret = PTR_ERR(imx6_pcie->pcie_ref_125m);
goto err;
}
imx6_pcie->pcie_axi = devm_clk_get(&pdev->dev, "pcie_axi");
if (IS_ERR(imx6_pcie->pcie_axi)) {
dev_err(&pdev->dev,
"pcie_axi clock source missing or invalid\n");
ret = PTR_ERR(imx6_pcie->pcie_axi);
goto err;
}
imx6_pcie->iomuxc_gpr =
syscon_regmap_lookup_by_compatible("fsl,imx6q-iomuxc-gpr");
if (IS_ERR(imx6_pcie->iomuxc_gpr)) {
dev_err(&pdev->dev, "unable to find iomuxc registers\n");
ret = PTR_ERR(imx6_pcie->iomuxc_gpr);
goto err;
}
ret = imx6_add_pcie_port(pp, pdev);
if (ret < 0)
goto err;
platform_set_drvdata(pdev, imx6_pcie);
return 0;
err:
return ret;
}
static int __init imx6_pcie_init(void)
{
return platform_driver_probe(&imx6_pcie_driver, imx6_pcie_probe);
}
