static void meson6_dwmac_fix_mac_speed(void *priv, unsigned int speed)
{
struct meson_dwmac *dwmac = priv;
unsigned int val;
val = readl(dwmac->reg);
switch (speed) {
case SPEED_10:
val &= ~ETHMAC_SPEED_100;
break;
case SPEED_100:
val |= ETHMAC_SPEED_100;
break;
}
writel(val, dwmac->reg);
}
static int meson6_dwmac_probe(struct platform_device *pdev)
{
struct plat_stmmacenet_data *plat_dat;
struct stmmac_resources stmmac_res;
struct meson_dwmac *dwmac;
struct resource *res;
int ret;
ret = stmmac_get_platform_resources(pdev, &stmmac_res);
if (ret)
return ret;
plat_dat = stmmac_probe_config_dt(pdev, &stmmac_res.mac);
if (IS_ERR(plat_dat))
return PTR_ERR(plat_dat);
dwmac = devm_kzalloc(&pdev->dev, sizeof(*dwmac), GFP_KERNEL);
if (!dwmac)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
dwmac->reg = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(dwmac->reg))
return PTR_ERR(dwmac->reg);
plat_dat->bsp_priv = dwmac;
plat_dat->fix_mac_speed = meson6_dwmac_fix_mac_speed;
return stmmac_dvr_probe(&pdev->dev, plat_dat, &stmmac_res);
}
