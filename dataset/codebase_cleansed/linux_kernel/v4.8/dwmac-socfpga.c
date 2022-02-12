static void socfpga_dwmac_fix_mac_speed(void *priv, unsigned int speed)
{
struct socfpga_dwmac *dwmac = (struct socfpga_dwmac *)priv;
void __iomem *splitter_base = dwmac->splitter_base;
void __iomem *tse_pcs_base = dwmac->pcs.tse_pcs_base;
void __iomem *sgmii_adapter_base = dwmac->pcs.sgmii_adapter_base;
struct device *dev = dwmac->dev;
struct net_device *ndev = dev_get_drvdata(dev);
struct phy_device *phy_dev = ndev->phydev;
u32 val;
if ((tse_pcs_base) && (sgmii_adapter_base))
writew(SGMII_ADAPTER_DISABLE,
sgmii_adapter_base + SGMII_ADAPTER_CTRL_REG);
if (splitter_base) {
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
if (tse_pcs_base && sgmii_adapter_base)
tse_pcs_fix_mac_speed(&dwmac->pcs, phy_dev, speed);
}
static int socfpga_dwmac_parse_data(struct socfpga_dwmac *dwmac, struct device *dev)
{
struct device_node *np = dev->of_node;
struct regmap *sys_mgr_base_addr;
u32 reg_offset, reg_shift;
int ret, index;
struct device_node *np_splitter = NULL;
struct device_node *np_sgmii_adapter = NULL;
struct resource res_splitter;
struct resource res_tse_pcs;
struct resource res_sgmii_adapter;
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
ret = of_address_to_resource(np_splitter, 0, &res_splitter);
of_node_put(np_splitter);
if (ret) {
dev_info(dev, "Missing emac splitter address\n");
return -EINVAL;
}
dwmac->splitter_base = devm_ioremap_resource(dev, &res_splitter);
if (IS_ERR(dwmac->splitter_base)) {
dev_info(dev, "Failed to mapping emac splitter\n");
return PTR_ERR(dwmac->splitter_base);
}
}
np_sgmii_adapter = of_parse_phandle(np,
"altr,gmii-to-sgmii-converter", 0);
if (np_sgmii_adapter) {
index = of_property_match_string(np_sgmii_adapter, "reg-names",
"hps_emac_interface_splitter_avalon_slave");
if (index >= 0) {
if (of_address_to_resource(np_sgmii_adapter, index,
&res_splitter)) {
dev_err(dev,
"%s: ERROR: missing emac splitter address\n",
__func__);
ret = -EINVAL;
goto err_node_put;
}
dwmac->splitter_base =
devm_ioremap_resource(dev, &res_splitter);
if (IS_ERR(dwmac->splitter_base)) {
ret = PTR_ERR(dwmac->splitter_base);
goto err_node_put;
}
}
index = of_property_match_string(np_sgmii_adapter, "reg-names",
"gmii_to_sgmii_adapter_avalon_slave");
if (index >= 0) {
if (of_address_to_resource(np_sgmii_adapter, index,
&res_sgmii_adapter)) {
dev_err(dev,
"%s: ERROR: failed mapping adapter\n",
__func__);
ret = -EINVAL;
goto err_node_put;
}
dwmac->pcs.sgmii_adapter_base =
devm_ioremap_resource(dev, &res_sgmii_adapter);
if (IS_ERR(dwmac->pcs.sgmii_adapter_base)) {
ret = PTR_ERR(dwmac->pcs.sgmii_adapter_base);
goto err_node_put;
}
}
index = of_property_match_string(np_sgmii_adapter, "reg-names",
"eth_tse_control_port");
if (index >= 0) {
if (of_address_to_resource(np_sgmii_adapter, index,
&res_tse_pcs)) {
dev_err(dev,
"%s: ERROR: failed mapping tse control port\n",
__func__);
ret = -EINVAL;
goto err_node_put;
}
dwmac->pcs.tse_pcs_base =
devm_ioremap_resource(dev, &res_tse_pcs);
if (IS_ERR(dwmac->pcs.tse_pcs_base)) {
ret = PTR_ERR(dwmac->pcs.tse_pcs_base);
goto err_node_put;
}
}
}
dwmac->reg_offset = reg_offset;
dwmac->reg_shift = reg_shift;
dwmac->sys_mgr_base_addr = sys_mgr_base_addr;
dwmac->dev = dev;
of_node_put(np_sgmii_adapter);
return 0;
err_node_put:
of_node_put(np_sgmii_adapter);
return ret;
}
static int socfpga_dwmac_set_phy_mode(struct socfpga_dwmac *dwmac)
{
struct regmap *sys_mgr_base_addr = dwmac->sys_mgr_base_addr;
int phymode = dwmac->interface;
u32 reg_offset = dwmac->reg_offset;
u32 reg_shift = dwmac->reg_shift;
u32 ctrl, val, module;
switch (phymode) {
case PHY_INTERFACE_MODE_RGMII:
case PHY_INTERFACE_MODE_RGMII_ID:
val = SYSMGR_EMACGRP_CTRL_PHYSEL_ENUM_RGMII;
break;
case PHY_INTERFACE_MODE_MII:
case PHY_INTERFACE_MODE_GMII:
case PHY_INTERFACE_MODE_SGMII:
val = SYSMGR_EMACGRP_CTRL_PHYSEL_ENUM_GMII_MII;
break;
default:
dev_err(dwmac->dev, "bad phy mode %d\n", phymode);
return -EINVAL;
}
if (dwmac->splitter_base)
val = SYSMGR_EMACGRP_CTRL_PHYSEL_ENUM_GMII_MII;
if (dwmac->stmmac_rst)
reset_control_assert(dwmac->stmmac_rst);
regmap_read(sys_mgr_base_addr, reg_offset, &ctrl);
ctrl &= ~(SYSMGR_EMACGRP_CTRL_PHYSEL_MASK << reg_shift);
ctrl |= val << reg_shift;
if (dwmac->f2h_ptp_ref_clk) {
ctrl |= SYSMGR_EMACGRP_CTRL_PTP_REF_CLK_MASK << (reg_shift / 2);
regmap_read(sys_mgr_base_addr, SYSMGR_FPGAGRP_MODULE_REG,
&module);
module |= (SYSMGR_FPGAGRP_MODULE_EMAC << (reg_shift / 2));
regmap_write(sys_mgr_base_addr, SYSMGR_FPGAGRP_MODULE_REG,
module);
} else {
ctrl &= ~(SYSMGR_EMACGRP_CTRL_PTP_REF_CLK_MASK << (reg_shift / 2));
}
regmap_write(sys_mgr_base_addr, reg_offset, ctrl);
if (dwmac->stmmac_rst)
reset_control_deassert(dwmac->stmmac_rst);
if (phymode == PHY_INTERFACE_MODE_SGMII) {
if (tse_pcs_init(dwmac->pcs.tse_pcs_base, &dwmac->pcs) != 0) {
dev_err(dwmac->dev, "Unable to initialize TSE PCS");
return -EINVAL;
}
}
return 0;
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
plat_dat->bsp_priv = dwmac;
plat_dat->fix_mac_speed = socfpga_dwmac_fix_mac_speed;
ret = stmmac_dvr_probe(&pdev->dev, plat_dat, &stmmac_res);
if (!ret) {
struct net_device *ndev = platform_get_drvdata(pdev);
struct stmmac_priv *stpriv = netdev_priv(ndev);
dwmac->stmmac_rst = stpriv->stmmac_rst;
ret = socfpga_dwmac_set_phy_mode(dwmac);
}
return ret;
}
static int socfpga_dwmac_resume(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
struct stmmac_priv *priv = netdev_priv(ndev);
socfpga_dwmac_set_phy_mode(priv->plat->bsp_priv);
if (priv->phydev)
phy_resume(priv->phydev);
return stmmac_resume(dev);
}
