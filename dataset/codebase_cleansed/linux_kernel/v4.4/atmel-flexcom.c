static int atmel_flexcom_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct clk *clk;
struct resource *res;
void __iomem *base;
u32 opmode;
int err;
err = of_property_read_u32(np, "atmel,flexcom-mode", &opmode);
if (err)
return err;
if (opmode < ATMEL_FLEXCOM_MODE_USART ||
opmode > ATMEL_FLEXCOM_MODE_TWI)
return -EINVAL;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(clk))
return PTR_ERR(clk);
err = clk_prepare_enable(clk);
if (err)
return err;
writel(FLEX_MR_OPMODE(opmode), base + FLEX_MR);
clk_disable_unprepare(clk);
return of_platform_populate(np, NULL, NULL, &pdev->dev);
}
