static int mxc_rnga_data_present(struct hwrng *rng)
{
int level;
void __iomem *rng_base = (void __iomem *)rng->priv;
level = ((__raw_readl(rng_base + RNGA_STATUS) &
RNGA_STATUS_LEVEL_MASK) >> 8);
return level > 0 ? 1 : 0;
}
static int mxc_rnga_data_read(struct hwrng *rng, u32 * data)
{
int err;
u32 ctrl;
void __iomem *rng_base = (void __iomem *)rng->priv;
*data = __raw_readl(rng_base + RNGA_OUTPUT_FIFO);
err = __raw_readl(rng_base + RNGA_STATUS) & RNGA_STATUS_ERROR_INT;
if (err) {
dev_dbg(&rng_dev->dev, "Error while reading random number!\n");
ctrl = __raw_readl(rng_base + RNGA_CONTROL);
__raw_writel(ctrl | RNGA_CONTROL_CLEAR_INT,
rng_base + RNGA_CONTROL);
return 0;
} else
return 4;
}
static int mxc_rnga_init(struct hwrng *rng)
{
u32 ctrl, osc;
void __iomem *rng_base = (void __iomem *)rng->priv;
ctrl = __raw_readl(rng_base + RNGA_CONTROL);
__raw_writel(ctrl & ~RNGA_CONTROL_SLEEP, rng_base + RNGA_CONTROL);
osc = __raw_readl(rng_base + RNGA_STATUS);
if (osc & RNGA_STATUS_OSC_DEAD) {
dev_err(&rng_dev->dev, "RNGA Oscillator is dead!\n");
return -ENODEV;
}
ctrl = __raw_readl(rng_base + RNGA_CONTROL);
__raw_writel(ctrl | RNGA_CONTROL_GO, rng_base + RNGA_CONTROL);
return 0;
}
static void mxc_rnga_cleanup(struct hwrng *rng)
{
u32 ctrl;
void __iomem *rng_base = (void __iomem *)rng->priv;
ctrl = __raw_readl(rng_base + RNGA_CONTROL);
__raw_writel(ctrl & ~RNGA_CONTROL_GO, rng_base + RNGA_CONTROL);
}
static int __init mxc_rnga_probe(struct platform_device *pdev)
{
int err = -ENODEV;
struct clk *clk;
struct resource *res, *mem;
void __iomem *rng_base = NULL;
if (rng_dev)
return -EBUSY;
clk = clk_get(&pdev->dev, "rng");
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "Could not get rng_clk!\n");
err = PTR_ERR(clk);
goto out;
}
clk_enable(clk);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
err = -ENOENT;
goto err_region;
}
mem = request_mem_region(res->start, resource_size(res), pdev->name);
if (mem == NULL) {
err = -EBUSY;
goto err_region;
}
rng_base = ioremap(res->start, resource_size(res));
if (!rng_base) {
err = -ENOMEM;
goto err_ioremap;
}
mxc_rnga.priv = (unsigned long)rng_base;
err = hwrng_register(&mxc_rnga);
if (err) {
dev_err(&pdev->dev, "MXC RNGA registering failed (%d)\n", err);
goto err_register;
}
rng_dev = pdev;
dev_info(&pdev->dev, "MXC RNGA Registered.\n");
return 0;
err_register:
iounmap(rng_base);
rng_base = NULL;
err_ioremap:
release_mem_region(res->start, resource_size(res));
err_region:
clk_disable(clk);
clk_put(clk);
out:
return err;
}
static int __exit mxc_rnga_remove(struct platform_device *pdev)
{
struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
void __iomem *rng_base = (void __iomem *)mxc_rnga.priv;
struct clk *clk = clk_get(&pdev->dev, "rng");
hwrng_unregister(&mxc_rnga);
iounmap(rng_base);
release_mem_region(res->start, resource_size(res));
clk_disable(clk);
clk_put(clk);
return 0;
}
static int __init mod_init(void)
{
return platform_driver_probe(&mxc_rnga_driver, mxc_rnga_probe);
}
static void __exit mod_exit(void)
{
platform_driver_unregister(&mxc_rnga_driver);
}
