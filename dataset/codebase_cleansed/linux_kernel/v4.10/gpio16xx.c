static int __init omap16xx_gpio_init(void)
{
int i;
void __iomem *base;
struct resource *res;
struct platform_device *pdev;
struct omap_gpio_platform_data *pdata;
if (!cpu_is_omap16xx())
return -EINVAL;
omap_writel(omap_readl(ULPD_CAM_CLK_CTRL) | 0x04,
ULPD_CAM_CLK_CTRL);
for (i = 0; i < ARRAY_SIZE(omap16xx_gpio_dev); i++) {
pdev = omap16xx_gpio_dev[i];
pdata = pdev->dev.platform_data;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (unlikely(!res)) {
dev_err(&pdev->dev, "Invalid mem resource.\n");
return -ENODEV;
}
base = ioremap(res->start, resource_size(res));
if (unlikely(!base)) {
dev_err(&pdev->dev, "ioremap failed.\n");
return -ENOMEM;
}
__raw_writel(SYSCONFIG_WORD, base + OMAP1610_GPIO_SYSCONFIG);
iounmap(base);
platform_device_register(omap16xx_gpio_dev[i]);
}
return 0;
}
