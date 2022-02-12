static uint32_t gmac_read_reg(struct anarion_gmac *gmac, uint8_t reg)
{
return readl((void *)(gmac->ctl_block + reg));
}
static void gmac_write_reg(struct anarion_gmac *gmac, uint8_t reg, uint32_t val)
{
writel(val, (void *)(gmac->ctl_block + reg));
}
static int anarion_gmac_init(struct platform_device *pdev, void *priv)
{
uint32_t sw_config;
struct anarion_gmac *gmac = priv;
gmac_write_reg(gmac, GMAC_RESET_CONTROL_REG, 1);
sw_config = gmac_read_reg(gmac, GMAC_SW_CONFIG_REG);
sw_config &= ~GMAC_CONFIG_INTF_SEL_MASK;
sw_config |= (gmac->phy_intf_sel & GMAC_CONFIG_INTF_SEL_MASK);
gmac_write_reg(gmac, GMAC_SW_CONFIG_REG, sw_config);
gmac_write_reg(gmac, GMAC_RESET_CONTROL_REG, 0);
return 0;
}
static void anarion_gmac_exit(struct platform_device *pdev, void *priv)
{
struct anarion_gmac *gmac = priv;
gmac_write_reg(gmac, GMAC_RESET_CONTROL_REG, 1);
}
static struct anarion_gmac *anarion_config_dt(struct platform_device *pdev)
{
int phy_mode;
struct resource *res;
void __iomem *ctl_block;
struct anarion_gmac *gmac;
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
ctl_block = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(ctl_block)) {
dev_err(&pdev->dev, "Cannot get reset region (%ld)!\n",
PTR_ERR(ctl_block));
return ctl_block;
}
gmac = devm_kzalloc(&pdev->dev, sizeof(*gmac), GFP_KERNEL);
if (!gmac)
return ERR_PTR(-ENOMEM);
gmac->ctl_block = (uintptr_t)ctl_block;
phy_mode = of_get_phy_mode(pdev->dev.of_node);
switch (phy_mode) {
case PHY_INTERFACE_MODE_RGMII:
case PHY_INTERFACE_MODE_RGMII_ID :
case PHY_INTERFACE_MODE_RGMII_RXID:
case PHY_INTERFACE_MODE_RGMII_TXID:
gmac->phy_intf_sel = GMAC_CONFIG_INTF_RGMII;
break;
default:
dev_err(&pdev->dev, "Unsupported phy-mode (%d)\n",
phy_mode);
return ERR_PTR(-ENOTSUPP);
}
return gmac;
}
static int anarion_dwmac_probe(struct platform_device *pdev)
{
int ret;
struct anarion_gmac *gmac;
struct plat_stmmacenet_data *plat_dat;
struct stmmac_resources stmmac_res;
ret = stmmac_get_platform_resources(pdev, &stmmac_res);
if (ret)
return ret;
gmac = anarion_config_dt(pdev);
if (IS_ERR(gmac))
return PTR_ERR(gmac);
plat_dat = stmmac_probe_config_dt(pdev, &stmmac_res.mac);
if (IS_ERR(plat_dat))
return PTR_ERR(plat_dat);
plat_dat->init = anarion_gmac_init;
plat_dat->exit = anarion_gmac_exit;
anarion_gmac_init(pdev, gmac);
plat_dat->bsp_priv = gmac;
ret = stmmac_dvr_probe(&pdev->dev, plat_dat, &stmmac_res);
if (ret) {
stmmac_remove_config_dt(pdev, plat_dat);
return ret;
}
return 0;
}
