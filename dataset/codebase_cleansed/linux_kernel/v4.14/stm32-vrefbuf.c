static int stm32_vrefbuf_enable(struct regulator_dev *rdev)
{
struct stm32_vrefbuf *priv = rdev_get_drvdata(rdev);
u32 val = readl_relaxed(priv->base + STM32_VREFBUF_CSR);
int ret;
val = (val & ~STM32_HIZ) | STM32_ENVR;
writel_relaxed(val, priv->base + STM32_VREFBUF_CSR);
ret = readl_poll_timeout(priv->base + STM32_VREFBUF_CSR, val,
!(val & STM32_VRR), 650, 10000);
if (ret) {
dev_err(&rdev->dev, "stm32 vrefbuf timed out!\n");
val = readl_relaxed(priv->base + STM32_VREFBUF_CSR);
val = (val & ~STM32_ENVR) | STM32_HIZ;
writel_relaxed(val, priv->base + STM32_VREFBUF_CSR);
}
return ret;
}
static int stm32_vrefbuf_disable(struct regulator_dev *rdev)
{
struct stm32_vrefbuf *priv = rdev_get_drvdata(rdev);
u32 val = readl_relaxed(priv->base + STM32_VREFBUF_CSR);
val = (val & ~STM32_ENVR) | STM32_HIZ;
writel_relaxed(val, priv->base + STM32_VREFBUF_CSR);
return 0;
}
static int stm32_vrefbuf_is_enabled(struct regulator_dev *rdev)
{
struct stm32_vrefbuf *priv = rdev_get_drvdata(rdev);
return readl_relaxed(priv->base + STM32_VREFBUF_CSR) & STM32_ENVR;
}
static int stm32_vrefbuf_set_voltage_sel(struct regulator_dev *rdev,
unsigned sel)
{
struct stm32_vrefbuf *priv = rdev_get_drvdata(rdev);
u32 val = readl_relaxed(priv->base + STM32_VREFBUF_CSR);
val = (val & ~STM32_VRS) | FIELD_PREP(STM32_VRS, sel);
writel_relaxed(val, priv->base + STM32_VREFBUF_CSR);
return 0;
}
static int stm32_vrefbuf_get_voltage_sel(struct regulator_dev *rdev)
{
struct stm32_vrefbuf *priv = rdev_get_drvdata(rdev);
u32 val = readl_relaxed(priv->base + STM32_VREFBUF_CSR);
return FIELD_GET(STM32_VRS, val);
}
static int stm32_vrefbuf_probe(struct platform_device *pdev)
{
struct resource *res;
struct stm32_vrefbuf *priv;
struct regulator_config config = { };
struct regulator_dev *rdev;
int ret;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(priv->base))
return PTR_ERR(priv->base);
priv->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(priv->clk))
return PTR_ERR(priv->clk);
ret = clk_prepare_enable(priv->clk);
if (ret) {
dev_err(&pdev->dev, "clk prepare failed with error %d\n", ret);
return ret;
}
config.dev = &pdev->dev;
config.driver_data = priv;
config.of_node = pdev->dev.of_node;
config.init_data = of_get_regulator_init_data(&pdev->dev,
pdev->dev.of_node,
&stm32_vrefbuf_regu);
rdev = regulator_register(&stm32_vrefbuf_regu, &config);
if (IS_ERR(rdev)) {
ret = PTR_ERR(rdev);
dev_err(&pdev->dev, "register failed with error %d\n", ret);
goto err_clk_dis;
}
platform_set_drvdata(pdev, rdev);
return 0;
err_clk_dis:
clk_disable_unprepare(priv->clk);
return ret;
}
static int stm32_vrefbuf_remove(struct platform_device *pdev)
{
struct regulator_dev *rdev = platform_get_drvdata(pdev);
struct stm32_vrefbuf *priv = rdev_get_drvdata(rdev);
regulator_unregister(rdev);
clk_disable_unprepare(priv->clk);
return 0;
}
