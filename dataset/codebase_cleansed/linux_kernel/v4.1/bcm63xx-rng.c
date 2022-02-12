static int bcm63xx_rng_init(struct hwrng *rng)
{
struct bcm63xx_rng_priv *priv = to_rng_priv(rng);
u32 val;
int error;
error = clk_prepare_enable(priv->clk);
if (error)
return error;
val = __raw_readl(priv->regs + RNG_CTRL);
val |= RNG_EN;
__raw_writel(val, priv->regs + RNG_CTRL);
return 0;
}
static void bcm63xx_rng_cleanup(struct hwrng *rng)
{
struct bcm63xx_rng_priv *priv = to_rng_priv(rng);
u32 val;
val = __raw_readl(priv->regs + RNG_CTRL);
val &= ~RNG_EN;
__raw_writel(val, priv->regs + RNG_CTRL);
clk_disable_unprepare(priv->clk);
}
static int bcm63xx_rng_data_present(struct hwrng *rng, int wait)
{
struct bcm63xx_rng_priv *priv = to_rng_priv(rng);
return __raw_readl(priv->regs + RNG_STAT) & RNG_AVAIL_MASK;
}
static int bcm63xx_rng_data_read(struct hwrng *rng, u32 *data)
{
struct bcm63xx_rng_priv *priv = to_rng_priv(rng);
*data = __raw_readl(priv->regs + RNG_DATA);
return 4;
}
static int bcm63xx_rng_probe(struct platform_device *pdev)
{
struct resource *r;
struct clk *clk;
int ret;
struct bcm63xx_rng_priv *priv;
struct hwrng *rng;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r) {
dev_err(&pdev->dev, "no iomem resource\n");
return -ENXIO;
}
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->rng.name = pdev->name;
priv->rng.init = bcm63xx_rng_init;
priv->rng.cleanup = bcm63xx_rng_cleanup;
priv->rng.data_present = bcm63xx_rng_data_present;
priv->rng.data_read = bcm63xx_rng_data_read;
priv->clk = devm_clk_get(&pdev->dev, "ipsec");
if (IS_ERR(priv->clk)) {
ret = PTR_ERR(priv->clk);
dev_err(&pdev->dev, "no clock for device: %d\n", ret);
return ret;
}
if (!devm_request_mem_region(&pdev->dev, r->start,
resource_size(r), pdev->name)) {
dev_err(&pdev->dev, "request mem failed");
return -EBUSY;
}
priv->regs = devm_ioremap_nocache(&pdev->dev, r->start,
resource_size(r));
if (!priv->regs) {
dev_err(&pdev->dev, "ioremap failed");
return -ENOMEM;
}
ret = devm_hwrng_register(&pdev->dev, &priv->rng);
if (ret) {
dev_err(&pdev->dev, "failed to register rng device: %d\n",
ret);
return ret;
}
dev_info(&pdev->dev, "registered RNG driver\n");
return 0;
}
