static int
ci_hdrc_msm_por_reset(struct reset_controller_dev *r, unsigned long id)
{
struct ci_hdrc_msm *ci_msm = container_of(r, struct ci_hdrc_msm, rcdev);
void __iomem *addr = ci_msm->base;
u32 val;
if (id)
addr += HS_PHY_SEC_CTRL;
else
addr += HS_PHY_CTRL;
val = readl_relaxed(addr);
val |= HS_PHY_POR_ASSERT;
writel(val, addr);
udelay(12);
val &= ~HS_PHY_POR_ASSERT;
writel(val, addr);
return 0;
}
static int ci_hdrc_msm_notify_event(struct ci_hdrc *ci, unsigned event)
{
struct device *dev = ci->dev->parent;
struct ci_hdrc_msm *msm_ci = dev_get_drvdata(dev);
int ret;
switch (event) {
case CI_HDRC_CONTROLLER_RESET_EVENT:
dev_dbg(dev, "CI_HDRC_CONTROLLER_RESET_EVENT received\n");
hw_phymode_configure(ci);
if (msm_ci->secondary_phy) {
u32 val = readl_relaxed(msm_ci->base + HS_PHY_SEC_CTRL);
val |= HS_PHY_DIG_CLAMP_N;
writel_relaxed(val, msm_ci->base + HS_PHY_SEC_CTRL);
}
ret = phy_init(ci->phy);
if (ret)
return ret;
ret = phy_power_on(ci->phy);
if (ret) {
phy_exit(ci->phy);
return ret;
}
hw_write_id_reg(ci, HS_PHY_AHB_MODE, 0xffffffff, 0x8);
hw_write_id_reg(ci, HS_PHY_GENCONFIG,
HS_PHY_TXFIFO_IDLE_FORCE_DIS, 0);
if (!msm_ci->hsic)
hw_write_id_reg(ci, HS_PHY_GENCONFIG_2,
HS_PHY_ULPI_TX_PKT_EN_CLR_FIX, 0);
if (!IS_ERR(ci->platdata->vbus_extcon.edev)) {
hw_write_id_reg(ci, HS_PHY_GENCONFIG_2,
HS_PHY_SESS_VLD_CTRL_EN,
HS_PHY_SESS_VLD_CTRL_EN);
hw_write(ci, OP_USBCMD, HSPHY_SESS_VLD_CTRL,
HSPHY_SESS_VLD_CTRL);
}
break;
case CI_HDRC_CONTROLLER_STOPPED_EVENT:
dev_dbg(dev, "CI_HDRC_CONTROLLER_STOPPED_EVENT received\n");
phy_power_off(ci->phy);
phy_exit(ci->phy);
break;
default:
dev_dbg(dev, "unknown ci_hdrc event\n");
break;
}
return 0;
}
static int ci_hdrc_msm_mux_phy(struct ci_hdrc_msm *ci,
struct platform_device *pdev)
{
struct regmap *regmap;
struct device *dev = &pdev->dev;
struct of_phandle_args args;
u32 val;
int ret;
ret = of_parse_phandle_with_fixed_args(dev->of_node, "phy-select", 2, 0,
&args);
if (ret)
return 0;
regmap = syscon_node_to_regmap(args.np);
of_node_put(args.np);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
ret = regmap_write(regmap, args.args[0], args.args[1]);
if (ret)
return ret;
ci->secondary_phy = !!args.args[1];
if (ci->secondary_phy) {
val = readl_relaxed(ci->base + HS_PHY_SEC_CTRL);
val |= HS_PHY_DIG_CLAMP_N;
writel_relaxed(val, ci->base + HS_PHY_SEC_CTRL);
}
return 0;
}
static int ci_hdrc_msm_probe(struct platform_device *pdev)
{
struct ci_hdrc_msm *ci;
struct platform_device *plat_ci;
struct clk *clk;
struct reset_control *reset;
struct resource *res;
int ret;
struct device_node *ulpi_node, *phy_node;
dev_dbg(&pdev->dev, "ci_hdrc_msm_probe\n");
ci = devm_kzalloc(&pdev->dev, sizeof(*ci), GFP_KERNEL);
if (!ci)
return -ENOMEM;
platform_set_drvdata(pdev, ci);
ci->pdata.name = "ci_hdrc_msm";
ci->pdata.capoffset = DEF_CAPOFFSET;
ci->pdata.flags = CI_HDRC_REGS_SHARED | CI_HDRC_DISABLE_STREAMING |
CI_HDRC_OVERRIDE_AHB_BURST |
CI_HDRC_OVERRIDE_PHY_CONTROL;
ci->pdata.notify_event = ci_hdrc_msm_notify_event;
reset = devm_reset_control_get(&pdev->dev, "core");
if (IS_ERR(reset))
return PTR_ERR(reset);
ci->core_clk = clk = devm_clk_get(&pdev->dev, "core");
if (IS_ERR(clk))
return PTR_ERR(clk);
ci->iface_clk = clk = devm_clk_get(&pdev->dev, "iface");
if (IS_ERR(clk))
return PTR_ERR(clk);
ci->fs_clk = clk = devm_clk_get(&pdev->dev, "fs");
if (IS_ERR(clk)) {
if (PTR_ERR(clk) == -EPROBE_DEFER)
return -EPROBE_DEFER;
ci->fs_clk = NULL;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
ci->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(ci->base))
return PTR_ERR(ci->base);
ci->rcdev.owner = THIS_MODULE;
ci->rcdev.ops = &ci_hdrc_msm_reset_ops;
ci->rcdev.of_node = pdev->dev.of_node;
ci->rcdev.nr_resets = 2;
ret = reset_controller_register(&ci->rcdev);
if (ret)
return ret;
ret = clk_prepare_enable(ci->fs_clk);
if (ret)
goto err_fs;
reset_control_assert(reset);
usleep_range(10000, 12000);
reset_control_deassert(reset);
clk_disable_unprepare(ci->fs_clk);
ret = clk_prepare_enable(ci->core_clk);
if (ret)
goto err_fs;
ret = clk_prepare_enable(ci->iface_clk);
if (ret)
goto err_iface;
ret = ci_hdrc_msm_mux_phy(ci, pdev);
if (ret)
goto err_mux;
ulpi_node = of_find_node_by_name(pdev->dev.of_node, "ulpi");
if (ulpi_node) {
phy_node = of_get_next_available_child(ulpi_node, NULL);
ci->hsic = of_device_is_compatible(phy_node, "qcom,usb-hsic-phy");
of_node_put(phy_node);
}
of_node_put(ulpi_node);
plat_ci = ci_hdrc_add_device(&pdev->dev, pdev->resource,
pdev->num_resources, &ci->pdata);
if (IS_ERR(plat_ci)) {
ret = PTR_ERR(plat_ci);
if (ret != -EPROBE_DEFER)
dev_err(&pdev->dev, "ci_hdrc_add_device failed!\n");
goto err_mux;
}
ci->ci = plat_ci;
pm_runtime_set_active(&pdev->dev);
pm_runtime_no_callbacks(&pdev->dev);
pm_runtime_enable(&pdev->dev);
return 0;
err_mux:
clk_disable_unprepare(ci->iface_clk);
err_iface:
clk_disable_unprepare(ci->core_clk);
err_fs:
reset_controller_unregister(&ci->rcdev);
return ret;
}
static int ci_hdrc_msm_remove(struct platform_device *pdev)
{
struct ci_hdrc_msm *ci = platform_get_drvdata(pdev);
pm_runtime_disable(&pdev->dev);
ci_hdrc_remove_device(ci->ci);
clk_disable_unprepare(ci->iface_clk);
clk_disable_unprepare(ci->core_clk);
reset_controller_unregister(&ci->rcdev);
return 0;
}
