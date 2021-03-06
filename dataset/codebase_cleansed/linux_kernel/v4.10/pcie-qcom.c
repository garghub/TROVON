static void qcom_ep_reset_assert(struct qcom_pcie *pcie)
{
gpiod_set_value(pcie->reset, 1);
usleep_range(PERST_DELAY_US, PERST_DELAY_US + 500);
}
static void qcom_ep_reset_deassert(struct qcom_pcie *pcie)
{
gpiod_set_value(pcie->reset, 0);
usleep_range(PERST_DELAY_US, PERST_DELAY_US + 500);
}
static irqreturn_t qcom_pcie_msi_irq_handler(int irq, void *arg)
{
struct pcie_port *pp = arg;
return dw_handle_msi_irq(pp);
}
static void qcom_pcie_v0_v1_ltssm_enable(struct qcom_pcie *pcie)
{
u32 val;
val = readl(pcie->elbi + PCIE20_ELBI_SYS_CTRL);
val |= PCIE20_ELBI_SYS_CTRL_LT_ENABLE;
writel(val, pcie->elbi + PCIE20_ELBI_SYS_CTRL);
}
static void qcom_pcie_v2_ltssm_enable(struct qcom_pcie *pcie)
{
u32 val;
val = readl(pcie->parf + PCIE20_PARF_LTSSM);
val |= BIT(8);
writel(val, pcie->parf + PCIE20_PARF_LTSSM);
}
static int qcom_pcie_establish_link(struct qcom_pcie *pcie)
{
if (dw_pcie_link_up(&pcie->pp))
return 0;
if (pcie->ops->ltssm_enable)
pcie->ops->ltssm_enable(pcie);
return dw_pcie_wait_for_link(&pcie->pp);
}
static int qcom_pcie_get_resources_v0(struct qcom_pcie *pcie)
{
struct qcom_pcie_resources_v0 *res = &pcie->res.v0;
struct device *dev = pcie->pp.dev;
res->vdda = devm_regulator_get(dev, "vdda");
if (IS_ERR(res->vdda))
return PTR_ERR(res->vdda);
res->vdda_phy = devm_regulator_get(dev, "vdda_phy");
if (IS_ERR(res->vdda_phy))
return PTR_ERR(res->vdda_phy);
res->vdda_refclk = devm_regulator_get(dev, "vdda_refclk");
if (IS_ERR(res->vdda_refclk))
return PTR_ERR(res->vdda_refclk);
res->iface_clk = devm_clk_get(dev, "iface");
if (IS_ERR(res->iface_clk))
return PTR_ERR(res->iface_clk);
res->core_clk = devm_clk_get(dev, "core");
if (IS_ERR(res->core_clk))
return PTR_ERR(res->core_clk);
res->phy_clk = devm_clk_get(dev, "phy");
if (IS_ERR(res->phy_clk))
return PTR_ERR(res->phy_clk);
res->pci_reset = devm_reset_control_get(dev, "pci");
if (IS_ERR(res->pci_reset))
return PTR_ERR(res->pci_reset);
res->axi_reset = devm_reset_control_get(dev, "axi");
if (IS_ERR(res->axi_reset))
return PTR_ERR(res->axi_reset);
res->ahb_reset = devm_reset_control_get(dev, "ahb");
if (IS_ERR(res->ahb_reset))
return PTR_ERR(res->ahb_reset);
res->por_reset = devm_reset_control_get(dev, "por");
if (IS_ERR(res->por_reset))
return PTR_ERR(res->por_reset);
res->phy_reset = devm_reset_control_get(dev, "phy");
if (IS_ERR(res->phy_reset))
return PTR_ERR(res->phy_reset);
return 0;
}
static int qcom_pcie_get_resources_v1(struct qcom_pcie *pcie)
{
struct qcom_pcie_resources_v1 *res = &pcie->res.v1;
struct device *dev = pcie->pp.dev;
res->vdda = devm_regulator_get(dev, "vdda");
if (IS_ERR(res->vdda))
return PTR_ERR(res->vdda);
res->iface = devm_clk_get(dev, "iface");
if (IS_ERR(res->iface))
return PTR_ERR(res->iface);
res->aux = devm_clk_get(dev, "aux");
if (IS_ERR(res->aux))
return PTR_ERR(res->aux);
res->master_bus = devm_clk_get(dev, "master_bus");
if (IS_ERR(res->master_bus))
return PTR_ERR(res->master_bus);
res->slave_bus = devm_clk_get(dev, "slave_bus");
if (IS_ERR(res->slave_bus))
return PTR_ERR(res->slave_bus);
res->core = devm_reset_control_get(dev, "core");
if (IS_ERR(res->core))
return PTR_ERR(res->core);
return 0;
}
static void qcom_pcie_deinit_v0(struct qcom_pcie *pcie)
{
struct qcom_pcie_resources_v0 *res = &pcie->res.v0;
reset_control_assert(res->pci_reset);
reset_control_assert(res->axi_reset);
reset_control_assert(res->ahb_reset);
reset_control_assert(res->por_reset);
reset_control_assert(res->pci_reset);
clk_disable_unprepare(res->iface_clk);
clk_disable_unprepare(res->core_clk);
clk_disable_unprepare(res->phy_clk);
regulator_disable(res->vdda);
regulator_disable(res->vdda_phy);
regulator_disable(res->vdda_refclk);
}
static int qcom_pcie_init_v0(struct qcom_pcie *pcie)
{
struct qcom_pcie_resources_v0 *res = &pcie->res.v0;
struct device *dev = pcie->pp.dev;
u32 val;
int ret;
ret = regulator_enable(res->vdda);
if (ret) {
dev_err(dev, "cannot enable vdda regulator\n");
return ret;
}
ret = regulator_enable(res->vdda_refclk);
if (ret) {
dev_err(dev, "cannot enable vdda_refclk regulator\n");
goto err_refclk;
}
ret = regulator_enable(res->vdda_phy);
if (ret) {
dev_err(dev, "cannot enable vdda_phy regulator\n");
goto err_vdda_phy;
}
ret = reset_control_assert(res->ahb_reset);
if (ret) {
dev_err(dev, "cannot assert ahb reset\n");
goto err_assert_ahb;
}
ret = clk_prepare_enable(res->iface_clk);
if (ret) {
dev_err(dev, "cannot prepare/enable iface clock\n");
goto err_assert_ahb;
}
ret = clk_prepare_enable(res->phy_clk);
if (ret) {
dev_err(dev, "cannot prepare/enable phy clock\n");
goto err_clk_phy;
}
ret = clk_prepare_enable(res->core_clk);
if (ret) {
dev_err(dev, "cannot prepare/enable core clock\n");
goto err_clk_core;
}
ret = reset_control_deassert(res->ahb_reset);
if (ret) {
dev_err(dev, "cannot deassert ahb reset\n");
goto err_deassert_ahb;
}
val = readl(pcie->parf + PCIE20_PARF_PHY_CTRL);
val &= ~BIT(0);
writel(val, pcie->parf + PCIE20_PARF_PHY_CTRL);
val = readl(pcie->parf + PCIE20_PARF_PHY_REFCLK);
val |= BIT(16);
writel(val, pcie->parf + PCIE20_PARF_PHY_REFCLK);
ret = reset_control_deassert(res->phy_reset);
if (ret) {
dev_err(dev, "cannot deassert phy reset\n");
return ret;
}
ret = reset_control_deassert(res->pci_reset);
if (ret) {
dev_err(dev, "cannot deassert pci reset\n");
return ret;
}
ret = reset_control_deassert(res->por_reset);
if (ret) {
dev_err(dev, "cannot deassert por reset\n");
return ret;
}
ret = reset_control_deassert(res->axi_reset);
if (ret) {
dev_err(dev, "cannot deassert axi reset\n");
return ret;
}
usleep_range(1000, 1500);
return 0;
err_deassert_ahb:
clk_disable_unprepare(res->core_clk);
err_clk_core:
clk_disable_unprepare(res->phy_clk);
err_clk_phy:
clk_disable_unprepare(res->iface_clk);
err_assert_ahb:
regulator_disable(res->vdda_phy);
err_vdda_phy:
regulator_disable(res->vdda_refclk);
err_refclk:
regulator_disable(res->vdda);
return ret;
}
static void qcom_pcie_deinit_v1(struct qcom_pcie *pcie)
{
struct qcom_pcie_resources_v1 *res = &pcie->res.v1;
reset_control_assert(res->core);
clk_disable_unprepare(res->slave_bus);
clk_disable_unprepare(res->master_bus);
clk_disable_unprepare(res->iface);
clk_disable_unprepare(res->aux);
regulator_disable(res->vdda);
}
static int qcom_pcie_init_v1(struct qcom_pcie *pcie)
{
struct qcom_pcie_resources_v1 *res = &pcie->res.v1;
struct device *dev = pcie->pp.dev;
int ret;
ret = reset_control_deassert(res->core);
if (ret) {
dev_err(dev, "cannot deassert core reset\n");
return ret;
}
ret = clk_prepare_enable(res->aux);
if (ret) {
dev_err(dev, "cannot prepare/enable aux clock\n");
goto err_res;
}
ret = clk_prepare_enable(res->iface);
if (ret) {
dev_err(dev, "cannot prepare/enable iface clock\n");
goto err_aux;
}
ret = clk_prepare_enable(res->master_bus);
if (ret) {
dev_err(dev, "cannot prepare/enable master_bus clock\n");
goto err_iface;
}
ret = clk_prepare_enable(res->slave_bus);
if (ret) {
dev_err(dev, "cannot prepare/enable slave_bus clock\n");
goto err_master;
}
ret = regulator_enable(res->vdda);
if (ret) {
dev_err(dev, "cannot enable vdda regulator\n");
goto err_slave;
}
writel(0, pcie->parf + PCIE20_PARF_DBI_BASE_ADDR);
if (IS_ENABLED(CONFIG_PCI_MSI)) {
u32 val = readl(pcie->parf + PCIE20_PARF_AXI_MSTR_WR_ADDR_HALT);
val |= BIT(31);
writel(val, pcie->parf + PCIE20_PARF_AXI_MSTR_WR_ADDR_HALT);
}
return 0;
err_slave:
clk_disable_unprepare(res->slave_bus);
err_master:
clk_disable_unprepare(res->master_bus);
err_iface:
clk_disable_unprepare(res->iface);
err_aux:
clk_disable_unprepare(res->aux);
err_res:
reset_control_assert(res->core);
return ret;
}
static int qcom_pcie_get_resources_v2(struct qcom_pcie *pcie)
{
struct qcom_pcie_resources_v2 *res = &pcie->res.v2;
struct device *dev = pcie->pp.dev;
res->aux_clk = devm_clk_get(dev, "aux");
if (IS_ERR(res->aux_clk))
return PTR_ERR(res->aux_clk);
res->cfg_clk = devm_clk_get(dev, "cfg");
if (IS_ERR(res->cfg_clk))
return PTR_ERR(res->cfg_clk);
res->master_clk = devm_clk_get(dev, "bus_master");
if (IS_ERR(res->master_clk))
return PTR_ERR(res->master_clk);
res->slave_clk = devm_clk_get(dev, "bus_slave");
if (IS_ERR(res->slave_clk))
return PTR_ERR(res->slave_clk);
res->pipe_clk = devm_clk_get(dev, "pipe");
if (IS_ERR(res->pipe_clk))
return PTR_ERR(res->pipe_clk);
return 0;
}
static int qcom_pcie_init_v2(struct qcom_pcie *pcie)
{
struct qcom_pcie_resources_v2 *res = &pcie->res.v2;
struct device *dev = pcie->pp.dev;
u32 val;
int ret;
ret = clk_prepare_enable(res->aux_clk);
if (ret) {
dev_err(dev, "cannot prepare/enable aux clock\n");
return ret;
}
ret = clk_prepare_enable(res->cfg_clk);
if (ret) {
dev_err(dev, "cannot prepare/enable cfg clock\n");
goto err_cfg_clk;
}
ret = clk_prepare_enable(res->master_clk);
if (ret) {
dev_err(dev, "cannot prepare/enable master clock\n");
goto err_master_clk;
}
ret = clk_prepare_enable(res->slave_clk);
if (ret) {
dev_err(dev, "cannot prepare/enable slave clock\n");
goto err_slave_clk;
}
val = readl(pcie->parf + PCIE20_PARF_PHY_CTRL);
val &= ~BIT(0);
writel(val, pcie->parf + PCIE20_PARF_PHY_CTRL);
writel(0, pcie->parf + PCIE20_PARF_DBI_BASE_ADDR);
val = readl(pcie->parf + PCIE20_PARF_SYS_CTRL);
val &= ~BIT(29);
writel(val, pcie->parf + PCIE20_PARF_SYS_CTRL);
val = readl(pcie->parf + PCIE20_PARF_MHI_CLOCK_RESET_CTRL);
val |= BIT(4);
writel(val, pcie->parf + PCIE20_PARF_MHI_CLOCK_RESET_CTRL);
val = readl(pcie->parf + PCIE20_PARF_AXI_MSTR_WR_ADDR_HALT_V2);
val |= BIT(31);
writel(val, pcie->parf + PCIE20_PARF_AXI_MSTR_WR_ADDR_HALT_V2);
return 0;
err_slave_clk:
clk_disable_unprepare(res->master_clk);
err_master_clk:
clk_disable_unprepare(res->cfg_clk);
err_cfg_clk:
clk_disable_unprepare(res->aux_clk);
return ret;
}
static int qcom_pcie_post_init_v2(struct qcom_pcie *pcie)
{
struct qcom_pcie_resources_v2 *res = &pcie->res.v2;
struct device *dev = pcie->pp.dev;
int ret;
ret = clk_prepare_enable(res->pipe_clk);
if (ret) {
dev_err(dev, "cannot prepare/enable pipe clock\n");
return ret;
}
return 0;
}
static int qcom_pcie_link_up(struct pcie_port *pp)
{
struct qcom_pcie *pcie = to_qcom_pcie(pp);
u16 val = readw(pcie->pp.dbi_base + PCIE20_CAP + PCI_EXP_LNKSTA);
return !!(val & PCI_EXP_LNKSTA_DLLLA);
}
static void qcom_pcie_deinit_v2(struct qcom_pcie *pcie)
{
struct qcom_pcie_resources_v2 *res = &pcie->res.v2;
clk_disable_unprepare(res->pipe_clk);
clk_disable_unprepare(res->slave_clk);
clk_disable_unprepare(res->master_clk);
clk_disable_unprepare(res->cfg_clk);
clk_disable_unprepare(res->aux_clk);
}
static void qcom_pcie_host_init(struct pcie_port *pp)
{
struct qcom_pcie *pcie = to_qcom_pcie(pp);
int ret;
qcom_ep_reset_assert(pcie);
ret = pcie->ops->init(pcie);
if (ret)
goto err_deinit;
ret = phy_power_on(pcie->phy);
if (ret)
goto err_deinit;
if (pcie->ops->post_init)
pcie->ops->post_init(pcie);
dw_pcie_setup_rc(pp);
if (IS_ENABLED(CONFIG_PCI_MSI))
dw_pcie_msi_init(pp);
qcom_ep_reset_deassert(pcie);
ret = qcom_pcie_establish_link(pcie);
if (ret)
goto err;
return;
err:
qcom_ep_reset_assert(pcie);
phy_power_off(pcie->phy);
err_deinit:
pcie->ops->deinit(pcie);
}
static int qcom_pcie_rd_own_conf(struct pcie_port *pp, int where, int size,
u32 *val)
{
if (where == PCI_CLASS_REVISION && size == 4) {
*val = readl(pp->dbi_base + PCI_CLASS_REVISION);
*val &= 0xff;
*val |= PCI_CLASS_BRIDGE_PCI << 16;
return PCIBIOS_SUCCESSFUL;
}
return dw_pcie_cfg_read(pp->dbi_base + where, size, val);
}
static int qcom_pcie_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *res;
struct qcom_pcie *pcie;
struct pcie_port *pp;
int ret;
pcie = devm_kzalloc(dev, sizeof(*pcie), GFP_KERNEL);
if (!pcie)
return -ENOMEM;
pp = &pcie->pp;
pcie->ops = (struct qcom_pcie_ops *)of_device_get_match_data(dev);
pcie->reset = devm_gpiod_get_optional(dev, "perst", GPIOD_OUT_LOW);
if (IS_ERR(pcie->reset))
return PTR_ERR(pcie->reset);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "parf");
pcie->parf = devm_ioremap_resource(dev, res);
if (IS_ERR(pcie->parf))
return PTR_ERR(pcie->parf);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "dbi");
pp->dbi_base = devm_ioremap_resource(dev, res);
if (IS_ERR(pp->dbi_base))
return PTR_ERR(pp->dbi_base);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "elbi");
pcie->elbi = devm_ioremap_resource(dev, res);
if (IS_ERR(pcie->elbi))
return PTR_ERR(pcie->elbi);
pcie->phy = devm_phy_optional_get(dev, "pciephy");
if (IS_ERR(pcie->phy))
return PTR_ERR(pcie->phy);
pp->dev = dev;
ret = pcie->ops->get_resources(pcie);
if (ret)
return ret;
pp->root_bus_nr = -1;
pp->ops = &qcom_pcie_dw_ops;
if (IS_ENABLED(CONFIG_PCI_MSI)) {
pp->msi_irq = platform_get_irq_byname(pdev, "msi");
if (pp->msi_irq < 0)
return pp->msi_irq;
ret = devm_request_irq(dev, pp->msi_irq,
qcom_pcie_msi_irq_handler,
IRQF_SHARED, "qcom-pcie-msi", pp);
if (ret) {
dev_err(dev, "cannot request msi irq\n");
return ret;
}
}
ret = phy_init(pcie->phy);
if (ret)
return ret;
ret = dw_pcie_host_init(pp);
if (ret) {
dev_err(dev, "cannot initialize host\n");
return ret;
}
return 0;
}
