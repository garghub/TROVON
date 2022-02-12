static int pxa25x_pinctrl_probe(struct platform_device *pdev)
{
int ret, i;
void __iomem *base_af[8];
void __iomem *base_dir[4];
void __iomem *base_sleep[4];
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base_af[0] = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base_af[0]))
return PTR_ERR(base_af[0]);
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
base_dir[0] = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base_dir[0]))
return PTR_ERR(base_dir[0]);
res = platform_get_resource(pdev, IORESOURCE_MEM, 2);
base_dir[3] = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base_dir[3]))
return PTR_ERR(base_dir[3]);
res = platform_get_resource(pdev, IORESOURCE_MEM, 3);
base_sleep[0] = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base_sleep[0]))
return PTR_ERR(base_sleep[0]);
for (i = 0; i < ARRAY_SIZE(base_af); i++)
base_af[i] = base_af[0] + sizeof(base_af[0]) * i;
for (i = 0; i < 3; i++)
base_dir[i] = base_dir[0] + sizeof(base_dir[0]) * i;
for (i = 0; i < ARRAY_SIZE(base_sleep); i++)
base_sleep[i] = base_sleep[0] + sizeof(base_af[0]) * i;
ret = pxa2xx_pinctrl_init(pdev, pxa25x_pins, ARRAY_SIZE(pxa25x_pins),
base_af, base_dir, base_sleep);
return ret;
}
