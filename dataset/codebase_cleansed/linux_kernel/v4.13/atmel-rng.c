static int atmel_trng_read(struct hwrng *rng, void *buf, size_t max,
bool wait)
{
struct atmel_trng *trng = container_of(rng, struct atmel_trng, rng);
u32 *data = buf;
if (readl(trng->base + TRNG_ISR) & 1) {
*data = readl(trng->base + TRNG_ODATA);
readl(trng->base + TRNG_ISR);
return 4;
} else
return 0;
}
static void atmel_trng_enable(struct atmel_trng *trng)
{
writel(TRNG_KEY | 1, trng->base + TRNG_CR);
}
static void atmel_trng_disable(struct atmel_trng *trng)
{
writel(TRNG_KEY, trng->base + TRNG_CR);
}
static int atmel_trng_probe(struct platform_device *pdev)
{
struct atmel_trng *trng;
struct resource *res;
int ret;
trng = devm_kzalloc(&pdev->dev, sizeof(*trng), GFP_KERNEL);
if (!trng)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
trng->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(trng->base))
return PTR_ERR(trng->base);
trng->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(trng->clk))
return PTR_ERR(trng->clk);
ret = clk_prepare_enable(trng->clk);
if (ret)
return ret;
atmel_trng_enable(trng);
trng->rng.name = pdev->name;
trng->rng.read = atmel_trng_read;
ret = hwrng_register(&trng->rng);
if (ret)
goto err_register;
platform_set_drvdata(pdev, trng);
return 0;
err_register:
clk_disable_unprepare(trng->clk);
return ret;
}
static int atmel_trng_remove(struct platform_device *pdev)
{
struct atmel_trng *trng = platform_get_drvdata(pdev);
hwrng_unregister(&trng->rng);
atmel_trng_disable(trng);
clk_disable_unprepare(trng->clk);
return 0;
}
static int atmel_trng_suspend(struct device *dev)
{
struct atmel_trng *trng = dev_get_drvdata(dev);
atmel_trng_disable(trng);
clk_disable_unprepare(trng->clk);
return 0;
}
static int atmel_trng_resume(struct device *dev)
{
struct atmel_trng *trng = dev_get_drvdata(dev);
int ret;
ret = clk_prepare_enable(trng->clk);
if (ret)
return ret;
atmel_trng_enable(trng);
return 0;
}
