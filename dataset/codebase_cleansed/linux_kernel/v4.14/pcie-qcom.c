static void qcom_ep_reset_assert(struct qcom_pcie *pcie)
{
gpiod_set_value_cansleep(pcie->reset, 1);
usleep_range(PERST_DELAY_US, PERST_DELAY_US + 500);
}
static void qcom_ep_reset_deassert(struct qcom_pcie *pcie)
{
gpiod_set_value_cansleep(pcie->reset, 0);
usleep_range(PERST_DELAY_US, PERST_DELAY_US + 500);
}
static irqreturn_t qcom_pcie_msi_irq_handler(int irq, void *arg)
{
struct pcie_port *pp = arg;
return dw_handle_msi_irq(pp);
}
static int qcom_pcie_establish_link(struct qcom_pcie *pcie)
{
struct dw_pcie *pci = pcie->pci;
if (dw_pcie_link_up(pci))
return 0;
if (pcie->ops->ltssm_enable)
pcie->ops->ltssm_enable(pcie);
return dw_pcie_wait_for_link(pci);
}
static void qcom_pcie_2_1_0_ltssm_enable(struct qcom_pcie *pcie)
{
u32 val;
val = readl(pcie->elbi + PCIE20_ELBI_SYS_CTRL);
val |= PCIE20_ELBI_SYS_CTRL_LT_ENABLE;
writel(val, pcie->elbi + PCIE20_ELBI_SYS_CTRL);
}
static int qcom_pcie_get_resources_2_1_0(struct qcom_pcie *pcie)
{
struct qcom_pcie_resources_2_1_0 *res = &pcie->res.v2_1_0;
struct dw_pcie *pci = pcie->pci;
struct device *dev = pci->dev;
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
res->pci_reset = devm_reset_control_get_exclusive(dev, "pci");
if (IS_ERR(res->pci_reset))
return PTR_ERR(res->pci_reset);
res->axi_reset = devm_reset_control_get_exclusive(dev, "axi");
if (IS_ERR(res->axi_reset))
return PTR_ERR(res->axi_reset);
res->ahb_reset = devm_reset_control_get_exclusive(dev, "ahb");
if (IS_ERR(res->ahb_reset))
return PTR_ERR(res->ahb_reset);
res->por_reset = devm_reset_control_get_exclusive(dev, "por");
if (IS_ERR(res->por_reset))
return PTR_ERR(res->por_reset);
res->phy_reset = devm_reset_control_get_exclusive(dev, "phy");
return PTR_ERR_OR_ZERO(res->phy_reset);
}
static void qcom_pcie_deinit_2_1_0(struct qcom_pcie *pcie)
{
struct qcom_pcie_resources_2_1_0 *res = &pcie->res.v2_1_0;
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
static int qcom_pcie_init_2_1_0(struct qcom_pcie *pcie)
{
struct qcom_pcie_resources_2_1_0 *res = &pcie->res.v2_1_0;
struct dw_pcie *pci = pcie->pci;
struct device *dev = pci->dev;
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
writel(CFG_REMOTE_RD_REQ_BRIDGE_SIZE_2K,
pci->dbi_base + PCIE20_AXI_MSTR_RESP_COMP_CTRL0);
writel(CFG_BRIDGE_SB_INIT,
pci->dbi_base + PCIE20_AXI_MSTR_RESP_COMP_CTRL1);
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
static int qcom_pcie_get_resources_1_0_0(struct qcom_pcie *pcie)
{
struct qcom_pcie_resources_1_0_0 *res = &pcie->res.v1_0_0;
struct dw_pcie *pci = pcie->pci;
struct device *dev = pci->dev;
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
res->core = devm_reset_control_get_exclusive(dev, "core");
return PTR_ERR_OR_ZERO(res->core);
}
static void qcom_pcie_deinit_1_0_0(struct qcom_pcie *pcie)
{
struct qcom_pcie_resources_1_0_0 *res = &pcie->res.v1_0_0;
reset_control_assert(res->core);
clk_disable_unprepare(res->slave_bus);
clk_disable_unprepare(res->master_bus);
clk_disable_unprepare(res->iface);
clk_disable_unprepare(res->aux);
regulator_disable(res->vdda);
}
static int qcom_pcie_init_1_0_0(struct qcom_pcie *pcie)
{
struct qcom_pcie_resources_1_0_0 *res = &pcie->res.v1_0_0;
struct dw_pcie *pci = pcie->pci;
struct device *dev = pci->dev;
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
static void qcom_pcie_2_3_2_ltssm_enable(struct qcom_pcie *pcie)
{
u32 val;
val = readl(pcie->parf + PCIE20_PARF_LTSSM);
val |= BIT(8);
writel(val, pcie->parf + PCIE20_PARF_LTSSM);
}
static int qcom_pcie_get_resources_2_3_2(struct qcom_pcie *pcie)
{
struct qcom_pcie_resources_2_3_2 *res = &pcie->res.v2_3_2;
struct dw_pcie *pci = pcie->pci;
struct device *dev = pci->dev;
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
return PTR_ERR_OR_ZERO(res->pipe_clk);
}
static void qcom_pcie_deinit_2_3_2(struct qcom_pcie *pcie)
{
struct qcom_pcie_resources_2_3_2 *res = &pcie->res.v2_3_2;
clk_disable_unprepare(res->slave_clk);
clk_disable_unprepare(res->master_clk);
clk_disable_unprepare(res->cfg_clk);
clk_disable_unprepare(res->aux_clk);
}
static void qcom_pcie_post_deinit_2_3_2(struct qcom_pcie *pcie)
{
struct qcom_pcie_resources_2_3_2 *res = &pcie->res.v2_3_2;
clk_disable_unprepare(res->pipe_clk);
}
static int qcom_pcie_init_2_3_2(struct qcom_pcie *pcie)
{
struct qcom_pcie_resources_2_3_2 *res = &pcie->res.v2_3_2;
struct dw_pcie *pci = pcie->pci;
struct device *dev = pci->dev;
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
static int qcom_pcie_post_init_2_3_2(struct qcom_pcie *pcie)
{
struct qcom_pcie_resources_2_3_2 *res = &pcie->res.v2_3_2;
struct dw_pcie *pci = pcie->pci;
struct device *dev = pci->dev;
int ret;
ret = clk_prepare_enable(res->pipe_clk);
if (ret) {
dev_err(dev, "cannot prepare/enable pipe clock\n");
return ret;
}
return 0;
}
static int qcom_pcie_get_resources_2_4_0(struct qcom_pcie *pcie)
{
struct qcom_pcie_resources_2_4_0 *res = &pcie->res.v2_4_0;
struct dw_pcie *pci = pcie->pci;
struct device *dev = pci->dev;
res->aux_clk = devm_clk_get(dev, "aux");
if (IS_ERR(res->aux_clk))
return PTR_ERR(res->aux_clk);
res->master_clk = devm_clk_get(dev, "master_bus");
if (IS_ERR(res->master_clk))
return PTR_ERR(res->master_clk);
res->slave_clk = devm_clk_get(dev, "slave_bus");
if (IS_ERR(res->slave_clk))
return PTR_ERR(res->slave_clk);
res->axi_m_reset = devm_reset_control_get_exclusive(dev, "axi_m");
if (IS_ERR(res->axi_m_reset))
return PTR_ERR(res->axi_m_reset);
res->axi_s_reset = devm_reset_control_get_exclusive(dev, "axi_s");
if (IS_ERR(res->axi_s_reset))
return PTR_ERR(res->axi_s_reset);
res->pipe_reset = devm_reset_control_get_exclusive(dev, "pipe");
if (IS_ERR(res->pipe_reset))
return PTR_ERR(res->pipe_reset);
res->axi_m_vmid_reset = devm_reset_control_get_exclusive(dev,
"axi_m_vmid");
if (IS_ERR(res->axi_m_vmid_reset))
return PTR_ERR(res->axi_m_vmid_reset);
res->axi_s_xpu_reset = devm_reset_control_get_exclusive(dev,
"axi_s_xpu");
if (IS_ERR(res->axi_s_xpu_reset))
return PTR_ERR(res->axi_s_xpu_reset);
res->parf_reset = devm_reset_control_get_exclusive(dev, "parf");
if (IS_ERR(res->parf_reset))
return PTR_ERR(res->parf_reset);
res->phy_reset = devm_reset_control_get_exclusive(dev, "phy");
if (IS_ERR(res->phy_reset))
return PTR_ERR(res->phy_reset);
res->axi_m_sticky_reset = devm_reset_control_get_exclusive(dev,
"axi_m_sticky");
if (IS_ERR(res->axi_m_sticky_reset))
return PTR_ERR(res->axi_m_sticky_reset);
res->pipe_sticky_reset = devm_reset_control_get_exclusive(dev,
"pipe_sticky");
if (IS_ERR(res->pipe_sticky_reset))
return PTR_ERR(res->pipe_sticky_reset);
res->pwr_reset = devm_reset_control_get_exclusive(dev, "pwr");
if (IS_ERR(res->pwr_reset))
return PTR_ERR(res->pwr_reset);
res->ahb_reset = devm_reset_control_get_exclusive(dev, "ahb");
if (IS_ERR(res->ahb_reset))
return PTR_ERR(res->ahb_reset);
res->phy_ahb_reset = devm_reset_control_get_exclusive(dev, "phy_ahb");
if (IS_ERR(res->phy_ahb_reset))
return PTR_ERR(res->phy_ahb_reset);
return 0;
}
static void qcom_pcie_deinit_2_4_0(struct qcom_pcie *pcie)
{
struct qcom_pcie_resources_2_4_0 *res = &pcie->res.v2_4_0;
reset_control_assert(res->axi_m_reset);
reset_control_assert(res->axi_s_reset);
reset_control_assert(res->pipe_reset);
reset_control_assert(res->pipe_sticky_reset);
reset_control_assert(res->phy_reset);
reset_control_assert(res->phy_ahb_reset);
reset_control_assert(res->axi_m_sticky_reset);
reset_control_assert(res->pwr_reset);
reset_control_assert(res->ahb_reset);
clk_disable_unprepare(res->aux_clk);
clk_disable_unprepare(res->master_clk);
clk_disable_unprepare(res->slave_clk);
}
static int qcom_pcie_init_2_4_0(struct qcom_pcie *pcie)
{
struct qcom_pcie_resources_2_4_0 *res = &pcie->res.v2_4_0;
struct dw_pcie *pci = pcie->pci;
struct device *dev = pci->dev;
u32 val;
int ret;
ret = reset_control_assert(res->axi_m_reset);
if (ret) {
dev_err(dev, "cannot assert axi master reset\n");
return ret;
}
ret = reset_control_assert(res->axi_s_reset);
if (ret) {
dev_err(dev, "cannot assert axi slave reset\n");
return ret;
}
usleep_range(10000, 12000);
ret = reset_control_assert(res->pipe_reset);
if (ret) {
dev_err(dev, "cannot assert pipe reset\n");
return ret;
}
ret = reset_control_assert(res->pipe_sticky_reset);
if (ret) {
dev_err(dev, "cannot assert pipe sticky reset\n");
return ret;
}
ret = reset_control_assert(res->phy_reset);
if (ret) {
dev_err(dev, "cannot assert phy reset\n");
return ret;
}
ret = reset_control_assert(res->phy_ahb_reset);
if (ret) {
dev_err(dev, "cannot assert phy ahb reset\n");
return ret;
}
usleep_range(10000, 12000);
ret = reset_control_assert(res->axi_m_sticky_reset);
if (ret) {
dev_err(dev, "cannot assert axi master sticky reset\n");
return ret;
}
ret = reset_control_assert(res->pwr_reset);
if (ret) {
dev_err(dev, "cannot assert power reset\n");
return ret;
}
ret = reset_control_assert(res->ahb_reset);
if (ret) {
dev_err(dev, "cannot assert ahb reset\n");
return ret;
}
usleep_range(10000, 12000);
ret = reset_control_deassert(res->phy_ahb_reset);
if (ret) {
dev_err(dev, "cannot deassert phy ahb reset\n");
return ret;
}
ret = reset_control_deassert(res->phy_reset);
if (ret) {
dev_err(dev, "cannot deassert phy reset\n");
goto err_rst_phy;
}
ret = reset_control_deassert(res->pipe_reset);
if (ret) {
dev_err(dev, "cannot deassert pipe reset\n");
goto err_rst_pipe;
}
ret = reset_control_deassert(res->pipe_sticky_reset);
if (ret) {
dev_err(dev, "cannot deassert pipe sticky reset\n");
goto err_rst_pipe_sticky;
}
usleep_range(10000, 12000);
ret = reset_control_deassert(res->axi_m_reset);
if (ret) {
dev_err(dev, "cannot deassert axi master reset\n");
goto err_rst_axi_m;
}
ret = reset_control_deassert(res->axi_m_sticky_reset);
if (ret) {
dev_err(dev, "cannot deassert axi master sticky reset\n");
goto err_rst_axi_m_sticky;
}
ret = reset_control_deassert(res->axi_s_reset);
if (ret) {
dev_err(dev, "cannot deassert axi slave reset\n");
goto err_rst_axi_s;
}
ret = reset_control_deassert(res->pwr_reset);
if (ret) {
dev_err(dev, "cannot deassert power reset\n");
goto err_rst_pwr;
}
ret = reset_control_deassert(res->ahb_reset);
if (ret) {
dev_err(dev, "cannot deassert ahb reset\n");
goto err_rst_ahb;
}
usleep_range(10000, 12000);
ret = clk_prepare_enable(res->aux_clk);
if (ret) {
dev_err(dev, "cannot prepare/enable iface clock\n");
goto err_clk_aux;
}
ret = clk_prepare_enable(res->master_clk);
if (ret) {
dev_err(dev, "cannot prepare/enable core clock\n");
goto err_clk_axi_m;
}
ret = clk_prepare_enable(res->slave_clk);
if (ret) {
dev_err(dev, "cannot prepare/enable phy clock\n");
goto err_clk_axi_s;
}
val = readl(pcie->parf + PCIE20_PARF_PHY_CTRL);
val &= !BIT(0);
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
err_clk_axi_s:
clk_disable_unprepare(res->master_clk);
err_clk_axi_m:
clk_disable_unprepare(res->aux_clk);
err_clk_aux:
reset_control_assert(res->ahb_reset);
err_rst_ahb:
reset_control_assert(res->pwr_reset);
err_rst_pwr:
reset_control_assert(res->axi_s_reset);
err_rst_axi_s:
reset_control_assert(res->axi_m_sticky_reset);
err_rst_axi_m_sticky:
reset_control_assert(res->axi_m_reset);
err_rst_axi_m:
reset_control_assert(res->pipe_sticky_reset);
err_rst_pipe_sticky:
reset_control_assert(res->pipe_reset);
err_rst_pipe:
reset_control_assert(res->phy_reset);
err_rst_phy:
reset_control_assert(res->phy_ahb_reset);
return ret;
}
static int qcom_pcie_get_resources_2_3_3(struct qcom_pcie *pcie)
{
struct qcom_pcie_resources_2_3_3 *res = &pcie->res.v2_3_3;
struct dw_pcie *pci = pcie->pci;
struct device *dev = pci->dev;
int i;
const char *rst_names[] = { "axi_m", "axi_s", "pipe",
"axi_m_sticky", "sticky",
"ahb", "sleep", };
res->iface = devm_clk_get(dev, "iface");
if (IS_ERR(res->iface))
return PTR_ERR(res->iface);
res->axi_m_clk = devm_clk_get(dev, "axi_m");
if (IS_ERR(res->axi_m_clk))
return PTR_ERR(res->axi_m_clk);
res->axi_s_clk = devm_clk_get(dev, "axi_s");
if (IS_ERR(res->axi_s_clk))
return PTR_ERR(res->axi_s_clk);
res->ahb_clk = devm_clk_get(dev, "ahb");
if (IS_ERR(res->ahb_clk))
return PTR_ERR(res->ahb_clk);
res->aux_clk = devm_clk_get(dev, "aux");
if (IS_ERR(res->aux_clk))
return PTR_ERR(res->aux_clk);
for (i = 0; i < ARRAY_SIZE(rst_names); i++) {
res->rst[i] = devm_reset_control_get(dev, rst_names[i]);
if (IS_ERR(res->rst[i]))
return PTR_ERR(res->rst[i]);
}
return 0;
}
static void qcom_pcie_deinit_2_3_3(struct qcom_pcie *pcie)
{
struct qcom_pcie_resources_2_3_3 *res = &pcie->res.v2_3_3;
clk_disable_unprepare(res->iface);
clk_disable_unprepare(res->axi_m_clk);
clk_disable_unprepare(res->axi_s_clk);
clk_disable_unprepare(res->ahb_clk);
clk_disable_unprepare(res->aux_clk);
}
static int qcom_pcie_init_2_3_3(struct qcom_pcie *pcie)
{
struct qcom_pcie_resources_2_3_3 *res = &pcie->res.v2_3_3;
struct dw_pcie *pci = pcie->pci;
struct device *dev = pci->dev;
int i, ret;
u32 val;
for (i = 0; i < ARRAY_SIZE(res->rst); i++) {
ret = reset_control_assert(res->rst[i]);
if (ret) {
dev_err(dev, "reset #%d assert failed (%d)\n", i, ret);
return ret;
}
}
usleep_range(2000, 2500);
for (i = 0; i < ARRAY_SIZE(res->rst); i++) {
ret = reset_control_deassert(res->rst[i]);
if (ret) {
dev_err(dev, "reset #%d deassert failed (%d)\n", i,
ret);
return ret;
}
}
usleep_range(2000, 2500);
ret = clk_prepare_enable(res->iface);
if (ret) {
dev_err(dev, "cannot prepare/enable core clock\n");
goto err_clk_iface;
}
ret = clk_prepare_enable(res->axi_m_clk);
if (ret) {
dev_err(dev, "cannot prepare/enable core clock\n");
goto err_clk_axi_m;
}
ret = clk_prepare_enable(res->axi_s_clk);
if (ret) {
dev_err(dev, "cannot prepare/enable axi slave clock\n");
goto err_clk_axi_s;
}
ret = clk_prepare_enable(res->ahb_clk);
if (ret) {
dev_err(dev, "cannot prepare/enable ahb clock\n");
goto err_clk_ahb;
}
ret = clk_prepare_enable(res->aux_clk);
if (ret) {
dev_err(dev, "cannot prepare/enable aux clock\n");
goto err_clk_aux;
}
writel(SLV_ADDR_SPACE_SZ,
pcie->parf + PCIE20_v3_PARF_SLV_ADDR_SPACE_SIZE);
val = readl(pcie->parf + PCIE20_PARF_PHY_CTRL);
val &= ~BIT(0);
writel(val, pcie->parf + PCIE20_PARF_PHY_CTRL);
writel(0, pcie->parf + PCIE20_PARF_DBI_BASE_ADDR);
writel(MST_WAKEUP_EN | SLV_WAKEUP_EN | MSTR_ACLK_CGC_DIS
| SLV_ACLK_CGC_DIS | CORE_CLK_CGC_DIS |
AUX_PWR_DET | L23_CLK_RMV_DIS | L1_CLK_RMV_DIS,
pcie->parf + PCIE20_PARF_SYS_CTRL);
writel(0, pcie->parf + PCIE20_PARF_Q2A_FLUSH);
writel(CMD_BME_VAL, pci->dbi_base + PCIE20_COMMAND_STATUS);
writel(DBI_RO_WR_EN, pci->dbi_base + PCIE20_MISC_CONTROL_1_REG);
writel(PCIE_CAP_LINK1_VAL, pci->dbi_base + PCIE20_CAP_LINK_1);
val = readl(pci->dbi_base + PCIE20_CAP_LINK_CAPABILITIES);
val &= ~PCIE20_CAP_ACTIVE_STATE_LINK_PM_SUPPORT;
writel(val, pci->dbi_base + PCIE20_CAP_LINK_CAPABILITIES);
writel(PCIE_CAP_CPL_TIMEOUT_DISABLE, pci->dbi_base +
PCIE20_DEVICE_CONTROL2_STATUS2);
return 0;
err_clk_aux:
clk_disable_unprepare(res->ahb_clk);
err_clk_ahb:
clk_disable_unprepare(res->axi_s_clk);
err_clk_axi_s:
clk_disable_unprepare(res->axi_m_clk);
err_clk_axi_m:
clk_disable_unprepare(res->iface);
err_clk_iface:
for (i = 0; i < ARRAY_SIZE(res->rst); i++)
reset_control_assert(res->rst[i]);
return ret;
}
static int qcom_pcie_link_up(struct dw_pcie *pci)
{
u16 val = readw(pci->dbi_base + PCIE20_CAP + PCI_EXP_LNKSTA);
return !!(val & PCI_EXP_LNKSTA_DLLLA);
}
static int qcom_pcie_host_init(struct pcie_port *pp)
{
struct dw_pcie *pci = to_dw_pcie_from_pp(pp);
struct qcom_pcie *pcie = to_qcom_pcie(pci);
int ret;
qcom_ep_reset_assert(pcie);
ret = pcie->ops->init(pcie);
if (ret)
return ret;
ret = phy_power_on(pcie->phy);
if (ret)
goto err_deinit;
if (pcie->ops->post_init) {
ret = pcie->ops->post_init(pcie);
if (ret)
goto err_disable_phy;
}
dw_pcie_setup_rc(pp);
if (IS_ENABLED(CONFIG_PCI_MSI))
dw_pcie_msi_init(pp);
qcom_ep_reset_deassert(pcie);
ret = qcom_pcie_establish_link(pcie);
if (ret)
goto err;
return 0;
err:
qcom_ep_reset_assert(pcie);
if (pcie->ops->post_deinit)
pcie->ops->post_deinit(pcie);
err_disable_phy:
phy_power_off(pcie->phy);
err_deinit:
pcie->ops->deinit(pcie);
return ret;
}
static int qcom_pcie_rd_own_conf(struct pcie_port *pp, int where, int size,
u32 *val)
{
struct dw_pcie *pci = to_dw_pcie_from_pp(pp);
if (where == PCI_CLASS_REVISION && size == 4) {
*val = readl(pci->dbi_base + PCI_CLASS_REVISION);
*val &= 0xff;
*val |= PCI_CLASS_BRIDGE_PCI << 16;
return PCIBIOS_SUCCESSFUL;
}
return dw_pcie_read(pci->dbi_base + where, size, val);
}
static int qcom_pcie_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *res;
struct pcie_port *pp;
struct dw_pcie *pci;
struct qcom_pcie *pcie;
int ret;
pcie = devm_kzalloc(dev, sizeof(*pcie), GFP_KERNEL);
if (!pcie)
return -ENOMEM;
pci = devm_kzalloc(dev, sizeof(*pci), GFP_KERNEL);
if (!pci)
return -ENOMEM;
pci->dev = dev;
pci->ops = &dw_pcie_ops;
pp = &pci->pp;
pcie->pci = pci;
pcie->ops = (struct qcom_pcie_ops *)of_device_get_match_data(dev);
pcie->reset = devm_gpiod_get_optional(dev, "perst", GPIOD_OUT_LOW);
if (IS_ERR(pcie->reset))
return PTR_ERR(pcie->reset);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "parf");
pcie->parf = devm_ioremap_resource(dev, res);
if (IS_ERR(pcie->parf))
return PTR_ERR(pcie->parf);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "dbi");
pci->dbi_base = devm_pci_remap_cfg_resource(dev, res);
if (IS_ERR(pci->dbi_base))
return PTR_ERR(pci->dbi_base);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "elbi");
pcie->elbi = devm_ioremap_resource(dev, res);
if (IS_ERR(pcie->elbi))
return PTR_ERR(pcie->elbi);
pcie->phy = devm_phy_optional_get(dev, "pciephy");
if (IS_ERR(pcie->phy))
return PTR_ERR(pcie->phy);
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
IRQF_SHARED | IRQF_NO_THREAD,
"qcom-pcie-msi", pp);
if (ret) {
dev_err(dev, "cannot request msi irq\n");
return ret;
}
}
ret = phy_init(pcie->phy);
if (ret)
return ret;
platform_set_drvdata(pdev, pcie);
ret = dw_pcie_host_init(pp);
if (ret) {
dev_err(dev, "cannot initialize host\n");
return ret;
}
return 0;
}
