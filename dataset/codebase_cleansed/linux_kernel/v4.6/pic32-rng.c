static int pic32_rng_read(struct hwrng *rng, void *buf, size_t max,
bool wait)
{
struct pic32_rng *priv = container_of(rng, struct pic32_rng, rng);
u64 *data = buf;
u32 t;
unsigned int timeout = RNG_TIMEOUT;
if (max < 8)
return 0;
do {
t = readl(priv->base + RNGRCNT) & RCNT_MASK;
if (t == 64) {
*data = ((u64)readl(priv->base + RNGSEED2) << 32) +
readl(priv->base + RNGSEED1);
return 8;
}
} while (wait && --timeout);
return -EIO;
}
static int pic32_rng_probe(struct platform_device *pdev)
{
struct pic32_rng *priv;
struct resource *res;
u32 v;
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
if (ret)
return ret;
v = TRNGEN | TRNGMOD;
writel(v, priv->base + RNGCON);
priv->rng.name = pdev->name;
priv->rng.read = pic32_rng_read;
ret = hwrng_register(&priv->rng);
if (ret)
goto err_register;
platform_set_drvdata(pdev, priv);
return 0;
err_register:
clk_disable_unprepare(priv->clk);
return ret;
}
static int pic32_rng_remove(struct platform_device *pdev)
{
struct pic32_rng *rng = platform_get_drvdata(pdev);
hwrng_unregister(&rng->rng);
writel(0, rng->base + RNGCON);
clk_disable_unprepare(rng->clk);
return 0;
}
