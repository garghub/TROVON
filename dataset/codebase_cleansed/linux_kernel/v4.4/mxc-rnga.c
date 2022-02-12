static int mxc_rnga_data_present(struct hwrng *rng, int wait)
{
int i;
struct mxc_rng *mxc_rng = container_of(rng, struct mxc_rng, rng);
for (i = 0; i < 20; i++) {
int level = (__raw_readl(mxc_rng->mem + RNGA_STATUS) &
RNGA_STATUS_LEVEL_MASK) >> 8;
if (level || !wait)
return !!level;
udelay(10);
}
return 0;
}
static int mxc_rnga_data_read(struct hwrng *rng, u32 * data)
{
int err;
u32 ctrl;
struct mxc_rng *mxc_rng = container_of(rng, struct mxc_rng, rng);
*data = __raw_readl(mxc_rng->mem + RNGA_OUTPUT_FIFO);
err = __raw_readl(mxc_rng->mem + RNGA_STATUS) & RNGA_STATUS_ERROR_INT;
if (err) {
dev_dbg(mxc_rng->dev, "Error while reading random number!\n");
ctrl = __raw_readl(mxc_rng->mem + RNGA_CONTROL);
__raw_writel(ctrl | RNGA_CONTROL_CLEAR_INT,
mxc_rng->mem + RNGA_CONTROL);
return 0;
} else
return 4;
}
static int mxc_rnga_init(struct hwrng *rng)
{
u32 ctrl, osc;
struct mxc_rng *mxc_rng = container_of(rng, struct mxc_rng, rng);
ctrl = __raw_readl(mxc_rng->mem + RNGA_CONTROL);
__raw_writel(ctrl & ~RNGA_CONTROL_SLEEP, mxc_rng->mem + RNGA_CONTROL);
osc = __raw_readl(mxc_rng->mem + RNGA_STATUS);
if (osc & RNGA_STATUS_OSC_DEAD) {
dev_err(mxc_rng->dev, "RNGA Oscillator is dead!\n");
return -ENODEV;
}
ctrl = __raw_readl(mxc_rng->mem + RNGA_CONTROL);
__raw_writel(ctrl | RNGA_CONTROL_GO, mxc_rng->mem + RNGA_CONTROL);
return 0;
}
static void mxc_rnga_cleanup(struct hwrng *rng)
{
u32 ctrl;
struct mxc_rng *mxc_rng = container_of(rng, struct mxc_rng, rng);
ctrl = __raw_readl(mxc_rng->mem + RNGA_CONTROL);
__raw_writel(ctrl & ~RNGA_CONTROL_GO, mxc_rng->mem + RNGA_CONTROL);
}
static int __init mxc_rnga_probe(struct platform_device *pdev)
{
int err;
struct resource *res;
struct mxc_rng *mxc_rng;
mxc_rng = devm_kzalloc(&pdev->dev, sizeof(*mxc_rng), GFP_KERNEL);
if (!mxc_rng)
return -ENOMEM;
mxc_rng->dev = &pdev->dev;
mxc_rng->rng.name = "mxc-rnga";
mxc_rng->rng.init = mxc_rnga_init;
mxc_rng->rng.cleanup = mxc_rnga_cleanup,
mxc_rng->rng.data_present = mxc_rnga_data_present,
mxc_rng->rng.data_read = mxc_rnga_data_read,
mxc_rng->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(mxc_rng->clk)) {
dev_err(&pdev->dev, "Could not get rng_clk!\n");
return PTR_ERR(mxc_rng->clk);
}
err = clk_prepare_enable(mxc_rng->clk);
if (err)
return err;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mxc_rng->mem = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(mxc_rng->mem)) {
err = PTR_ERR(mxc_rng->mem);
goto err_ioremap;
}
err = hwrng_register(&mxc_rng->rng);
if (err) {
dev_err(&pdev->dev, "MXC RNGA registering failed (%d)\n", err);
goto err_ioremap;
}
return 0;
err_ioremap:
clk_disable_unprepare(mxc_rng->clk);
return err;
}
static int __exit mxc_rnga_remove(struct platform_device *pdev)
{
struct mxc_rng *mxc_rng = platform_get_drvdata(pdev);
hwrng_unregister(&mxc_rng->rng);
clk_disable_unprepare(mxc_rng->clk);
return 0;
}
