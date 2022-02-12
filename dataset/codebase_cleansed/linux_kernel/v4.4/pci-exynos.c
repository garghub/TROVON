static inline void exynos_elb_writel(struct exynos_pcie *pcie, u32 val, u32 reg)
{
writel(val, pcie->elbi_base + reg);
}
static inline u32 exynos_elb_readl(struct exynos_pcie *pcie, u32 reg)
{
return readl(pcie->elbi_base + reg);
}
static inline void exynos_phy_writel(struct exynos_pcie *pcie, u32 val, u32 reg)
{
writel(val, pcie->phy_base + reg);
}
static inline u32 exynos_phy_readl(struct exynos_pcie *pcie, u32 reg)
{
return readl(pcie->phy_base + reg);
}
static inline void exynos_blk_writel(struct exynos_pcie *pcie, u32 val, u32 reg)
{
writel(val, pcie->block_base + reg);
}
static inline u32 exynos_blk_readl(struct exynos_pcie *pcie, u32 reg)
{
return readl(pcie->block_base + reg);
}
static void exynos_pcie_sideband_dbi_w_mode(struct pcie_port *pp, bool on)
{
u32 val;
struct exynos_pcie *exynos_pcie = to_exynos_pcie(pp);
if (on) {
val = exynos_elb_readl(exynos_pcie, PCIE_ELBI_SLV_AWMISC);
val |= PCIE_ELBI_SLV_DBI_ENABLE;
exynos_elb_writel(exynos_pcie, val, PCIE_ELBI_SLV_AWMISC);
} else {
val = exynos_elb_readl(exynos_pcie, PCIE_ELBI_SLV_AWMISC);
val &= ~PCIE_ELBI_SLV_DBI_ENABLE;
exynos_elb_writel(exynos_pcie, val, PCIE_ELBI_SLV_AWMISC);
}
}
static void exynos_pcie_sideband_dbi_r_mode(struct pcie_port *pp, bool on)
{
u32 val;
struct exynos_pcie *exynos_pcie = to_exynos_pcie(pp);
if (on) {
val = exynos_elb_readl(exynos_pcie, PCIE_ELBI_SLV_ARMISC);
val |= PCIE_ELBI_SLV_DBI_ENABLE;
exynos_elb_writel(exynos_pcie, val, PCIE_ELBI_SLV_ARMISC);
} else {
val = exynos_elb_readl(exynos_pcie, PCIE_ELBI_SLV_ARMISC);
val &= ~PCIE_ELBI_SLV_DBI_ENABLE;
exynos_elb_writel(exynos_pcie, val, PCIE_ELBI_SLV_ARMISC);
}
}
static void exynos_pcie_assert_core_reset(struct pcie_port *pp)
{
u32 val;
struct exynos_pcie *exynos_pcie = to_exynos_pcie(pp);
val = exynos_elb_readl(exynos_pcie, PCIE_CORE_RESET);
val &= ~PCIE_CORE_RESET_ENABLE;
exynos_elb_writel(exynos_pcie, val, PCIE_CORE_RESET);
exynos_elb_writel(exynos_pcie, 0, PCIE_PWR_RESET);
exynos_elb_writel(exynos_pcie, 0, PCIE_STICKY_RESET);
exynos_elb_writel(exynos_pcie, 0, PCIE_NONSTICKY_RESET);
}
static void exynos_pcie_deassert_core_reset(struct pcie_port *pp)
{
u32 val;
struct exynos_pcie *exynos_pcie = to_exynos_pcie(pp);
val = exynos_elb_readl(exynos_pcie, PCIE_CORE_RESET);
val |= PCIE_CORE_RESET_ENABLE;
exynos_elb_writel(exynos_pcie, val, PCIE_CORE_RESET);
exynos_elb_writel(exynos_pcie, 1, PCIE_STICKY_RESET);
exynos_elb_writel(exynos_pcie, 1, PCIE_NONSTICKY_RESET);
exynos_elb_writel(exynos_pcie, 1, PCIE_APP_INIT_RESET);
exynos_elb_writel(exynos_pcie, 0, PCIE_APP_INIT_RESET);
exynos_blk_writel(exynos_pcie, 1, PCIE_PHY_MAC_RESET);
}
static void exynos_pcie_assert_phy_reset(struct pcie_port *pp)
{
struct exynos_pcie *exynos_pcie = to_exynos_pcie(pp);
exynos_blk_writel(exynos_pcie, 0, PCIE_PHY_MAC_RESET);
exynos_blk_writel(exynos_pcie, 1, PCIE_PHY_GLOBAL_RESET);
}
static void exynos_pcie_deassert_phy_reset(struct pcie_port *pp)
{
struct exynos_pcie *exynos_pcie = to_exynos_pcie(pp);
exynos_blk_writel(exynos_pcie, 0, PCIE_PHY_GLOBAL_RESET);
exynos_elb_writel(exynos_pcie, 1, PCIE_PWR_RESET);
exynos_blk_writel(exynos_pcie, 0, PCIE_PHY_COMMON_RESET);
exynos_blk_writel(exynos_pcie, 0, PCIE_PHY_CMN_REG);
exynos_blk_writel(exynos_pcie, 0, PCIE_PHY_TRSVREG_RESET);
exynos_blk_writel(exynos_pcie, 0, PCIE_PHY_TRSV_RESET);
}
static void exynos_pcie_power_on_phy(struct pcie_port *pp)
{
u32 val;
struct exynos_pcie *exynos_pcie = to_exynos_pcie(pp);
val = exynos_phy_readl(exynos_pcie, PCIE_PHY_COMMON_POWER);
val &= ~PCIE_PHY_COMMON_PD_CMN;
exynos_phy_writel(exynos_pcie, val, PCIE_PHY_COMMON_POWER);
val = exynos_phy_readl(exynos_pcie, PCIE_PHY_TRSV0_POWER);
val &= ~PCIE_PHY_TRSV0_PD_TSV;
exynos_phy_writel(exynos_pcie, val, PCIE_PHY_TRSV0_POWER);
val = exynos_phy_readl(exynos_pcie, PCIE_PHY_TRSV1_POWER);
val &= ~PCIE_PHY_TRSV1_PD_TSV;
exynos_phy_writel(exynos_pcie, val, PCIE_PHY_TRSV1_POWER);
val = exynos_phy_readl(exynos_pcie, PCIE_PHY_TRSV2_POWER);
val &= ~PCIE_PHY_TRSV2_PD_TSV;
exynos_phy_writel(exynos_pcie, val, PCIE_PHY_TRSV2_POWER);
val = exynos_phy_readl(exynos_pcie, PCIE_PHY_TRSV3_POWER);
val &= ~PCIE_PHY_TRSV3_PD_TSV;
exynos_phy_writel(exynos_pcie, val, PCIE_PHY_TRSV3_POWER);
}
static void exynos_pcie_power_off_phy(struct pcie_port *pp)
{
u32 val;
struct exynos_pcie *exynos_pcie = to_exynos_pcie(pp);
val = exynos_phy_readl(exynos_pcie, PCIE_PHY_COMMON_POWER);
val |= PCIE_PHY_COMMON_PD_CMN;
exynos_phy_writel(exynos_pcie, val, PCIE_PHY_COMMON_POWER);
val = exynos_phy_readl(exynos_pcie, PCIE_PHY_TRSV0_POWER);
val |= PCIE_PHY_TRSV0_PD_TSV;
exynos_phy_writel(exynos_pcie, val, PCIE_PHY_TRSV0_POWER);
val = exynos_phy_readl(exynos_pcie, PCIE_PHY_TRSV1_POWER);
val |= PCIE_PHY_TRSV1_PD_TSV;
exynos_phy_writel(exynos_pcie, val, PCIE_PHY_TRSV1_POWER);
val = exynos_phy_readl(exynos_pcie, PCIE_PHY_TRSV2_POWER);
val |= PCIE_PHY_TRSV2_PD_TSV;
exynos_phy_writel(exynos_pcie, val, PCIE_PHY_TRSV2_POWER);
val = exynos_phy_readl(exynos_pcie, PCIE_PHY_TRSV3_POWER);
val |= PCIE_PHY_TRSV3_PD_TSV;
exynos_phy_writel(exynos_pcie, val, PCIE_PHY_TRSV3_POWER);
}
static void exynos_pcie_init_phy(struct pcie_port *pp)
{
struct exynos_pcie *exynos_pcie = to_exynos_pcie(pp);
exynos_phy_writel(exynos_pcie, 0x29, PCIE_PHY_DCC_FEEDBACK);
exynos_phy_writel(exynos_pcie, 0xd5, PCIE_PHY_IMPEDANCE);
exynos_phy_writel(exynos_pcie, 0x14, PCIE_PHY_PLL_DIV_0);
exynos_phy_writel(exynos_pcie, 0x12, PCIE_PHY_PLL_DIV_1);
exynos_phy_writel(exynos_pcie, 0x7f, PCIE_PHY_TRSV0_DRV_LVL);
exynos_phy_writel(exynos_pcie, 0x0, PCIE_PHY_TRSV0_EMP_LVL);
exynos_phy_writel(exynos_pcie, 0xe7, PCIE_PHY_PLL_BIAS);
exynos_phy_writel(exynos_pcie, 0x82, PCIE_PHY_TRSV0_RXCDR);
exynos_phy_writel(exynos_pcie, 0x82, PCIE_PHY_TRSV1_RXCDR);
exynos_phy_writel(exynos_pcie, 0x82, PCIE_PHY_TRSV2_RXCDR);
exynos_phy_writel(exynos_pcie, 0x82, PCIE_PHY_TRSV3_RXCDR);
exynos_phy_writel(exynos_pcie, 0x39, PCIE_PHY_TRSV0_EMP_LVL);
exynos_phy_writel(exynos_pcie, 0x39, PCIE_PHY_TRSV1_EMP_LVL);
exynos_phy_writel(exynos_pcie, 0x39, PCIE_PHY_TRSV2_EMP_LVL);
exynos_phy_writel(exynos_pcie, 0x39, PCIE_PHY_TRSV3_EMP_LVL);
exynos_phy_writel(exynos_pcie, 0x20, PCIE_PHY_TRSV0_LVCC);
exynos_phy_writel(exynos_pcie, 0xa0, PCIE_PHY_TRSV1_LVCC);
exynos_phy_writel(exynos_pcie, 0xa0, PCIE_PHY_TRSV2_LVCC);
exynos_phy_writel(exynos_pcie, 0xa0, PCIE_PHY_TRSV3_LVCC);
}
static void exynos_pcie_assert_reset(struct pcie_port *pp)
{
struct exynos_pcie *exynos_pcie = to_exynos_pcie(pp);
if (exynos_pcie->reset_gpio >= 0)
devm_gpio_request_one(pp->dev, exynos_pcie->reset_gpio,
GPIOF_OUT_INIT_HIGH, "RESET");
}
static int exynos_pcie_establish_link(struct pcie_port *pp)
{
struct exynos_pcie *exynos_pcie = to_exynos_pcie(pp);
u32 val;
unsigned int retries;
if (dw_pcie_link_up(pp)) {
dev_err(pp->dev, "Link already up\n");
return 0;
}
exynos_pcie_assert_core_reset(pp);
exynos_pcie_assert_phy_reset(pp);
exynos_pcie_deassert_phy_reset(pp);
exynos_pcie_power_on_phy(pp);
exynos_pcie_init_phy(pp);
exynos_blk_writel(exynos_pcie, 1, PCIE_PHY_COMMON_RESET);
udelay(500);
exynos_blk_writel(exynos_pcie, 0, PCIE_PHY_COMMON_RESET);
exynos_pcie_deassert_core_reset(pp);
dw_pcie_setup_rc(pp);
exynos_pcie_assert_reset(pp);
exynos_elb_writel(exynos_pcie, PCIE_ELBI_LTSSM_ENABLE,
PCIE_APP_LTSSM_ENABLE);
for (retries = 0; retries < 10; retries++) {
if (dw_pcie_link_up(pp)) {
dev_info(pp->dev, "Link up\n");
return 0;
}
mdelay(100);
}
while (exynos_phy_readl(exynos_pcie, PCIE_PHY_PLL_LOCKED) == 0) {
val = exynos_blk_readl(exynos_pcie, PCIE_PHY_PLL_LOCKED);
dev_info(pp->dev, "PLL Locked: 0x%x\n", val);
}
exynos_pcie_power_off_phy(pp);
dev_err(pp->dev, "PCIe Link Fail\n");
return -EINVAL;
}
static void exynos_pcie_clear_irq_pulse(struct pcie_port *pp)
{
u32 val;
struct exynos_pcie *exynos_pcie = to_exynos_pcie(pp);
val = exynos_elb_readl(exynos_pcie, PCIE_IRQ_PULSE);
exynos_elb_writel(exynos_pcie, val, PCIE_IRQ_PULSE);
}
static void exynos_pcie_enable_irq_pulse(struct pcie_port *pp)
{
u32 val;
struct exynos_pcie *exynos_pcie = to_exynos_pcie(pp);
val = IRQ_INTA_ASSERT | IRQ_INTB_ASSERT |
IRQ_INTC_ASSERT | IRQ_INTD_ASSERT;
exynos_elb_writel(exynos_pcie, val, PCIE_IRQ_EN_PULSE);
}
static irqreturn_t exynos_pcie_irq_handler(int irq, void *arg)
{
struct pcie_port *pp = arg;
exynos_pcie_clear_irq_pulse(pp);
return IRQ_HANDLED;
}
static irqreturn_t exynos_pcie_msi_irq_handler(int irq, void *arg)
{
struct pcie_port *pp = arg;
return dw_handle_msi_irq(pp);
}
static void exynos_pcie_msi_init(struct pcie_port *pp)
{
u32 val;
struct exynos_pcie *exynos_pcie = to_exynos_pcie(pp);
dw_pcie_msi_init(pp);
val = exynos_elb_readl(exynos_pcie, PCIE_IRQ_EN_LEVEL);
val |= IRQ_MSI_ENABLE;
exynos_elb_writel(exynos_pcie, val, PCIE_IRQ_EN_LEVEL);
}
static void exynos_pcie_enable_interrupts(struct pcie_port *pp)
{
exynos_pcie_enable_irq_pulse(pp);
if (IS_ENABLED(CONFIG_PCI_MSI))
exynos_pcie_msi_init(pp);
}
static inline void exynos_pcie_readl_rc(struct pcie_port *pp,
void __iomem *dbi_base, u32 *val)
{
exynos_pcie_sideband_dbi_r_mode(pp, true);
*val = readl(dbi_base);
exynos_pcie_sideband_dbi_r_mode(pp, false);
}
static inline void exynos_pcie_writel_rc(struct pcie_port *pp,
u32 val, void __iomem *dbi_base)
{
exynos_pcie_sideband_dbi_w_mode(pp, true);
writel(val, dbi_base);
exynos_pcie_sideband_dbi_w_mode(pp, false);
}
static int exynos_pcie_rd_own_conf(struct pcie_port *pp, int where, int size,
u32 *val)
{
int ret;
exynos_pcie_sideband_dbi_r_mode(pp, true);
ret = dw_pcie_cfg_read(pp->dbi_base + where, size, val);
exynos_pcie_sideband_dbi_r_mode(pp, false);
return ret;
}
static int exynos_pcie_wr_own_conf(struct pcie_port *pp, int where, int size,
u32 val)
{
int ret;
exynos_pcie_sideband_dbi_w_mode(pp, true);
ret = dw_pcie_cfg_write(pp->dbi_base + where, size, val);
exynos_pcie_sideband_dbi_w_mode(pp, false);
return ret;
}
static int exynos_pcie_link_up(struct pcie_port *pp)
{
struct exynos_pcie *exynos_pcie = to_exynos_pcie(pp);
u32 val = exynos_elb_readl(exynos_pcie, PCIE_ELBI_RDLH_LINKUP);
if (val == PCIE_ELBI_LTSSM_ENABLE)
return 1;
return 0;
}
static void exynos_pcie_host_init(struct pcie_port *pp)
{
exynos_pcie_establish_link(pp);
exynos_pcie_enable_interrupts(pp);
}
static int __init exynos_add_pcie_port(struct pcie_port *pp,
struct platform_device *pdev)
{
int ret;
pp->irq = platform_get_irq(pdev, 1);
if (!pp->irq) {
dev_err(&pdev->dev, "failed to get irq\n");
return -ENODEV;
}
ret = devm_request_irq(&pdev->dev, pp->irq, exynos_pcie_irq_handler,
IRQF_SHARED, "exynos-pcie", pp);
if (ret) {
dev_err(&pdev->dev, "failed to request irq\n");
return ret;
}
if (IS_ENABLED(CONFIG_PCI_MSI)) {
pp->msi_irq = platform_get_irq(pdev, 0);
if (!pp->msi_irq) {
dev_err(&pdev->dev, "failed to get msi irq\n");
return -ENODEV;
}
ret = devm_request_irq(&pdev->dev, pp->msi_irq,
exynos_pcie_msi_irq_handler,
IRQF_SHARED, "exynos-pcie", pp);
if (ret) {
dev_err(&pdev->dev, "failed to request msi irq\n");
return ret;
}
}
pp->root_bus_nr = -1;
pp->ops = &exynos_pcie_host_ops;
ret = dw_pcie_host_init(pp);
if (ret) {
dev_err(&pdev->dev, "failed to initialize host\n");
return ret;
}
return 0;
}
static int __init exynos_pcie_probe(struct platform_device *pdev)
{
struct exynos_pcie *exynos_pcie;
struct pcie_port *pp;
struct device_node *np = pdev->dev.of_node;
struct resource *elbi_base;
struct resource *phy_base;
struct resource *block_base;
int ret;
exynos_pcie = devm_kzalloc(&pdev->dev, sizeof(*exynos_pcie),
GFP_KERNEL);
if (!exynos_pcie)
return -ENOMEM;
pp = &exynos_pcie->pp;
pp->dev = &pdev->dev;
exynos_pcie->reset_gpio = of_get_named_gpio(np, "reset-gpio", 0);
exynos_pcie->clk = devm_clk_get(&pdev->dev, "pcie");
if (IS_ERR(exynos_pcie->clk)) {
dev_err(&pdev->dev, "Failed to get pcie rc clock\n");
return PTR_ERR(exynos_pcie->clk);
}
ret = clk_prepare_enable(exynos_pcie->clk);
if (ret)
return ret;
exynos_pcie->bus_clk = devm_clk_get(&pdev->dev, "pcie_bus");
if (IS_ERR(exynos_pcie->bus_clk)) {
dev_err(&pdev->dev, "Failed to get pcie bus clock\n");
ret = PTR_ERR(exynos_pcie->bus_clk);
goto fail_clk;
}
ret = clk_prepare_enable(exynos_pcie->bus_clk);
if (ret)
goto fail_clk;
elbi_base = platform_get_resource(pdev, IORESOURCE_MEM, 0);
exynos_pcie->elbi_base = devm_ioremap_resource(&pdev->dev, elbi_base);
if (IS_ERR(exynos_pcie->elbi_base)) {
ret = PTR_ERR(exynos_pcie->elbi_base);
goto fail_bus_clk;
}
phy_base = platform_get_resource(pdev, IORESOURCE_MEM, 1);
exynos_pcie->phy_base = devm_ioremap_resource(&pdev->dev, phy_base);
if (IS_ERR(exynos_pcie->phy_base)) {
ret = PTR_ERR(exynos_pcie->phy_base);
goto fail_bus_clk;
}
block_base = platform_get_resource(pdev, IORESOURCE_MEM, 2);
exynos_pcie->block_base = devm_ioremap_resource(&pdev->dev, block_base);
if (IS_ERR(exynos_pcie->block_base)) {
ret = PTR_ERR(exynos_pcie->block_base);
goto fail_bus_clk;
}
ret = exynos_add_pcie_port(pp, pdev);
if (ret < 0)
goto fail_bus_clk;
platform_set_drvdata(pdev, exynos_pcie);
return 0;
fail_bus_clk:
clk_disable_unprepare(exynos_pcie->bus_clk);
fail_clk:
clk_disable_unprepare(exynos_pcie->clk);
return ret;
}
static int __exit exynos_pcie_remove(struct platform_device *pdev)
{
struct exynos_pcie *exynos_pcie = platform_get_drvdata(pdev);
clk_disable_unprepare(exynos_pcie->bus_clk);
clk_disable_unprepare(exynos_pcie->clk);
return 0;
}
static int __init exynos_pcie_init(void)
{
return platform_driver_probe(&exynos_pcie_driver, exynos_pcie_probe);
}
