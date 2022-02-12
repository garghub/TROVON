static void socfpga_dwmac_fix_mac_speed(void *priv, unsigned int speed)
{
struct socfpga_dwmac *dwmac = (struct socfpga_dwmac *)priv;
void __iomem *splitter_base = dwmac->splitter_base;
u32 val;
if (!splitter_base)
return;
val = readl(splitter_base + EMAC_SPLITTER_CTRL_REG);
val &= ~EMAC_SPLITTER_CTRL_SPEED_MASK;
switch (speed) {
case 1000:
val |= EMAC_SPLITTER_CTRL_SPEED_1000;
break;
case 100:
val |= EMAC_SPLITTER_CTRL_SPEED_100;
break;
case 10:
val |= EMAC_SPLITTER_CTRL_SPEED_10;
break;
default:
return;
}
writel(val, splitter_base + EMAC_SPLITTER_CTRL_REG);
}
static int socfpga_dwmac_parse_data(struct socfpga_dwmac *dwmac, struct device *dev)
{
struct device_node *np = dev->of_node;
struct regmap *sys_mgr_base_addr;
u32 reg_offset, reg_shift;
int ret;
struct device_node *np_splitter;
struct resource res_splitter;
dwmac->stmmac_rst = devm_reset_control_get(dev,
STMMAC_RESOURCE_NAME);
if (IS_ERR(dwmac->stmmac_rst)) {
dev_info(dev, "Could not get reset control!\n");
if (PTR_ERR(dwmac->stmmac_rst) == -EPROBE_DEFER)
return -EPROBE_DEFER;
dwmac->stmmac_rst = NULL;
}
dwmac->interface = of_get_phy_mode(np);
sys_mgr_base_addr = syscon_regmap_lookup_by_phandle(np, "altr,sysmgr-syscon");
if (IS_ERR(sys_mgr_base_addr)) {
dev_info(dev, "No sysmgr-syscon node found\n");
return PTR_ERR(sys_mgr_base_addr);
}
ret = of_property_read_u32_index(np, "altr,sysmgr-syscon", 1, &reg_offset);
if (ret) {
dev_info(dev, "Could not read reg_offset from sysmgr-syscon!\n");
return -EINVAL;
}
ret = of_property_read_u32_index(np, "altr,sysmgr-syscon", 2, &reg_shift);
if (ret) {
dev_info(dev, "Could not read reg_shift from sysmgr-syscon!\n");
return -EINVAL;
}
dwmac->f2h_ptp_ref_clk = of_property_read_bool(np, "altr,f2h_ptp_ref_clk");
np_splitter = of_parse_phandle(np, "altr,emac-splitter", 0);
if (np_splitter) {
if (of_address_to_resource(np_splitter, 0, &res_splitter)) {
dev_info(dev, "Missing emac splitter address\n");
return -EINVAL;
}
dwmac->splitter_base = devm_ioremap_resource(dev, &res_splitter);
if (IS_ERR(dwmac->splitter_base)) {
dev_info(dev, "Failed to mapping emac splitter\n");
return PTR_ERR(dwmac->splitter_base);
}
}
dwmac->reg_offset = reg_offset;
dwmac->reg_shift = reg_shift;
dwmac->sys_mgr_base_addr = sys_mgr_base_addr;
dwmac->dev = dev;
return 0;
}
static int socfpga_dwmac_setup(struct socfpga_dwmac *dwmac)
{
struct regmap *sys_mgr_base_addr = dwmac->sys_mgr_base_addr;
int phymode = dwmac->interface;
u32 reg_offset = dwmac->reg_offset;
u32 reg_shift = dwmac->reg_shift;
u32 ctrl, val;
switch (phymode) {
case PHY_INTERFACE_MODE_RGMII:
case PHY_INTERFACE_MODE_RGMII_ID:
val = SYSMGR_EMACGRP_CTRL_PHYSEL_ENUM_RGMII;
break;
case PHY_INTERFACE_MODE_MII:
case PHY_INTERFACE_MODE_GMII:
val = SYSMGR_EMACGRP_CTRL_PHYSEL_ENUM_GMII_MII;
break;
default:
dev_err(dwmac->dev, "bad phy mode %d\n", phymode);
return -EINVAL;
}
if (dwmac->splitter_base)
val = SYSMGR_EMACGRP_CTRL_PHYSEL_ENUM_GMII_MII;
regmap_read(sys_mgr_base_addr, reg_offset, &ctrl);
ctrl &= ~(SYSMGR_EMACGRP_CTRL_PHYSEL_MASK << reg_shift);
ctrl |= val << reg_shift;
if (dwmac->f2h_ptp_ref_clk)
ctrl |= SYSMGR_EMACGRP_CTRL_PTP_REF_CLK_MASK << (reg_shift / 2);
else
ctrl &= ~(SYSMGR_EMACGRP_CTRL_PTP_REF_CLK_MASK << (reg_shift / 2));
regmap_write(sys_mgr_base_addr, reg_offset, ctrl);
return 0;
}
static void socfpga_dwmac_exit(struct platform_device *pdev, void *priv)
{
struct socfpga_dwmac *dwmac = priv;
if (dwmac->stmmac_rst)
reset_control_assert(dwmac->stmmac_rst);
}
static int socfpga_dwmac_init(struct platform_device *pdev, void *priv)
{
struct socfpga_dwmac *dwmac = priv;
struct net_device *ndev = platform_get_drvdata(pdev);
struct stmmac_priv *stpriv = NULL;
int ret = 0;
if (ndev)
stpriv = netdev_priv(ndev);
if (dwmac->stmmac_rst)
reset_control_assert(dwmac->stmmac_rst);
ret = socfpga_dwmac_setup(dwmac);
if (dwmac->stmmac_rst)
reset_control_deassert(dwmac->stmmac_rst);
if (stpriv && stpriv->phydev)
phy_resume(stpriv->phydev);
return ret;
}
static int socfpga_dwmac_probe(struct platform_device *pdev)
{
struct plat_stmmacenet_data *plat_dat;
struct stmmac_resources stmmac_res;
struct device *dev = &pdev->dev;
int ret;
struct socfpga_dwmac *dwmac;
ret = stmmac_get_platform_resources(pdev, &stmmac_res);
if (ret)
return ret;
plat_dat = stmmac_probe_config_dt(pdev, &stmmac_res.mac);
if (IS_ERR(plat_dat))
return PTR_ERR(plat_dat);
dwmac = devm_kzalloc(dev, sizeof(*dwmac), GFP_KERNEL);
if (!dwmac)
return -ENOMEM;
ret = socfpga_dwmac_parse_data(dwmac, dev);
if (ret) {
dev_err(dev, "Unable to parse OF data\n");
return ret;
}
ret = socfpga_dwmac_setup(dwmac);
if (ret) {
dev_err(dev, "couldn't setup SoC glue (%d)\n", ret);
return ret;
}
plat_dat->bsp_priv = dwmac;
plat_dat->init = socfpga_dwmac_init;
plat_dat->exit = socfpga_dwmac_exit;
plat_dat->fix_mac_speed = socfpga_dwmac_fix_mac_speed;
ret = socfpga_dwmac_init(pdev, plat_dat->bsp_priv);
if (ret)
return ret;
return stmmac_dvr_probe(&pdev->dev, plat_dat, &stmmac_res);
}
