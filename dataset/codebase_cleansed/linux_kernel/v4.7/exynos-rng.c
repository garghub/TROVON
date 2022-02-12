static u32 exynos_rng_readl(struct exynos_rng *rng, u32 offset)
{
return __raw_readl(rng->mem + offset);
}
static void exynos_rng_writel(struct exynos_rng *rng, u32 val, u32 offset)
{
__raw_writel(val, rng->mem + offset);
}
static int exynos_rng_configure(struct exynos_rng *exynos_rng)
{
int i;
int ret = 0;
for (i = 0 ; i < 5 ; i++)
exynos_rng_writel(exynos_rng, jiffies,
EXYNOS_PRNG_SEED_OFFSET + 4*i);
if (!(exynos_rng_readl(exynos_rng, EXYNOS_PRNG_STATUS_OFFSET)
& SEED_SETTING_DONE))
ret = -EIO;
return ret;
}
static int exynos_init(struct hwrng *rng)
{
struct exynos_rng *exynos_rng = container_of(rng,
struct exynos_rng, rng);
int ret = 0;
pm_runtime_get_sync(exynos_rng->dev);
ret = exynos_rng_configure(exynos_rng);
pm_runtime_mark_last_busy(exynos_rng->dev);
pm_runtime_put_autosuspend(exynos_rng->dev);
return ret;
}
static int exynos_read(struct hwrng *rng, void *buf,
size_t max, bool wait)
{
struct exynos_rng *exynos_rng = container_of(rng,
struct exynos_rng, rng);
u32 *data = buf;
int retry = 100;
int ret = 4;
pm_runtime_get_sync(exynos_rng->dev);
exynos_rng_writel(exynos_rng, PRNG_START, 0);
while (!(exynos_rng_readl(exynos_rng,
EXYNOS_PRNG_STATUS_OFFSET) & PRNG_DONE) && --retry)
cpu_relax();
if (!retry) {
ret = -ETIMEDOUT;
goto out;
}
exynos_rng_writel(exynos_rng, PRNG_DONE, EXYNOS_PRNG_STATUS_OFFSET);
*data = exynos_rng_readl(exynos_rng, EXYNOS_PRNG_OUT1_OFFSET);
out:
pm_runtime_mark_last_busy(exynos_rng->dev);
pm_runtime_put_sync_autosuspend(exynos_rng->dev);
return ret;
}
static int exynos_rng_probe(struct platform_device *pdev)
{
struct exynos_rng *exynos_rng;
struct resource *res;
int ret;
exynos_rng = devm_kzalloc(&pdev->dev, sizeof(struct exynos_rng),
GFP_KERNEL);
if (!exynos_rng)
return -ENOMEM;
exynos_rng->dev = &pdev->dev;
exynos_rng->rng.name = "exynos";
exynos_rng->rng.init = exynos_init;
exynos_rng->rng.read = exynos_read;
exynos_rng->clk = devm_clk_get(&pdev->dev, "secss");
if (IS_ERR(exynos_rng->clk)) {
dev_err(&pdev->dev, "Couldn't get clock.\n");
return -ENOENT;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
exynos_rng->mem = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(exynos_rng->mem))
return PTR_ERR(exynos_rng->mem);
platform_set_drvdata(pdev, exynos_rng);
pm_runtime_set_autosuspend_delay(&pdev->dev, EXYNOS_AUTOSUSPEND_DELAY);
pm_runtime_use_autosuspend(&pdev->dev);
pm_runtime_enable(&pdev->dev);
ret = devm_hwrng_register(&pdev->dev, &exynos_rng->rng);
if (ret) {
pm_runtime_dont_use_autosuspend(&pdev->dev);
pm_runtime_disable(&pdev->dev);
}
return ret;
}
static int exynos_rng_remove(struct platform_device *pdev)
{
pm_runtime_dont_use_autosuspend(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return 0;
}
static int __maybe_unused exynos_rng_runtime_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct exynos_rng *exynos_rng = platform_get_drvdata(pdev);
clk_disable_unprepare(exynos_rng->clk);
return 0;
}
static int __maybe_unused exynos_rng_runtime_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct exynos_rng *exynos_rng = platform_get_drvdata(pdev);
return clk_prepare_enable(exynos_rng->clk);
}
static int __maybe_unused exynos_rng_suspend(struct device *dev)
{
return pm_runtime_force_suspend(dev);
}
static int __maybe_unused exynos_rng_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct exynos_rng *exynos_rng = platform_get_drvdata(pdev);
int ret;
ret = pm_runtime_force_resume(dev);
if (ret)
return ret;
return exynos_rng_configure(exynos_rng);
}
