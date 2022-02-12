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
static int atmel_trng_probe(struct platform_device *pdev)
{
struct atmel_trng *trng;
struct resource *res;
int ret;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -EINVAL;
trng = devm_kzalloc(&pdev->dev, sizeof(*trng), GFP_KERNEL);
if (!trng)
return -ENOMEM;
if (!devm_request_mem_region(&pdev->dev, res->start,
resource_size(res), pdev->name))
return -EBUSY;
trng->base = devm_ioremap(&pdev->dev, res->start, resource_size(res));
if (!trng->base)
return -EBUSY;
trng->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(trng->clk))
return PTR_ERR(trng->clk);
ret = clk_enable(trng->clk);
if (ret)
goto err_enable;
writel(TRNG_KEY | 1, trng->base + TRNG_CR);
trng->rng.name = pdev->name;
trng->rng.read = atmel_trng_read;
ret = hwrng_register(&trng->rng);
if (ret)
goto err_register;
platform_set_drvdata(pdev, trng);
return 0;
err_register:
clk_disable(trng->clk);
err_enable:
clk_put(trng->clk);
return ret;
}
static int atmel_trng_remove(struct platform_device *pdev)
{
struct atmel_trng *trng = platform_get_drvdata(pdev);
hwrng_unregister(&trng->rng);
writel(TRNG_KEY, trng->base + TRNG_CR);
clk_disable(trng->clk);
clk_put(trng->clk);
return 0;
}
static int atmel_trng_suspend(struct device *dev)
{
struct atmel_trng *trng = dev_get_drvdata(dev);
clk_disable(trng->clk);
return 0;
}
static int atmel_trng_resume(struct device *dev)
{
struct atmel_trng *trng = dev_get_drvdata(dev);
return clk_enable(trng->clk);
}
