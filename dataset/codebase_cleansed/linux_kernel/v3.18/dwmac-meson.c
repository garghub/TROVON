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
static void *meson6_dwmac_setup(struct platform_device *pdev)
{
struct meson_dwmac *dwmac;
struct resource *res;
dwmac = devm_kzalloc(&pdev->dev, sizeof(*dwmac), GFP_KERNEL);
if (!dwmac)
return ERR_PTR(-ENOMEM);
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
dwmac->reg = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(dwmac->reg))
return dwmac->reg;
return dwmac;
}
