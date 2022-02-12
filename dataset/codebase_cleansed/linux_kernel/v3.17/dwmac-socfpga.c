static int socfpga_dwmac_parse_data(struct socfpga_dwmac *dwmac, struct device *dev)
{
struct device_node *np = dev->of_node;
struct regmap *sys_mgr_base_addr;
u32 reg_offset, reg_shift;
int ret;
dwmac->stmmac_rst = devm_reset_control_get(dev,
STMMAC_RESOURCE_NAME);
if (IS_ERR(dwmac->stmmac_rst)) {
dev_info(dev, "Could not get reset control!\n");
return -EINVAL;
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
regmap_read(sys_mgr_base_addr, reg_offset, &ctrl);
ctrl &= ~(SYSMGR_EMACGRP_CTRL_PHYSEL_MASK << reg_shift);
ctrl |= val << reg_shift;
regmap_write(sys_mgr_base_addr, reg_offset, ctrl);
return 0;
}
static void *socfpga_dwmac_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
int ret;
struct socfpga_dwmac *dwmac;
dwmac = devm_kzalloc(dev, sizeof(*dwmac), GFP_KERNEL);
if (!dwmac)
return ERR_PTR(-ENOMEM);
ret = socfpga_dwmac_parse_data(dwmac, dev);
if (ret) {
dev_err(dev, "Unable to parse OF data\n");
return ERR_PTR(ret);
}
ret = socfpga_dwmac_setup(dwmac);
if (ret) {
dev_err(dev, "couldn't setup SoC glue (%d)\n", ret);
return ERR_PTR(ret);
}
return dwmac;
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
