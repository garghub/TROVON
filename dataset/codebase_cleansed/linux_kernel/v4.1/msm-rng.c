static int msm_rng_enable(struct hwrng *hwrng, int enable)
{
struct msm_rng *rng = to_msm_rng(hwrng);
u32 val;
int ret;
ret = clk_prepare_enable(rng->clk);
if (ret)
return ret;
if (enable) {
val = readl_relaxed(rng->base + PRNG_CONFIG);
if (val & PRNG_CONFIG_HW_ENABLE)
goto already_enabled;
val = readl_relaxed(rng->base + PRNG_LFSR_CFG);
val &= ~PRNG_LFSR_CFG_MASK;
val |= PRNG_LFSR_CFG_CLOCKS;
writel(val, rng->base + PRNG_LFSR_CFG);
val = readl_relaxed(rng->base + PRNG_CONFIG);
val |= PRNG_CONFIG_HW_ENABLE;
writel(val, rng->base + PRNG_CONFIG);
} else {
val = readl_relaxed(rng->base + PRNG_CONFIG);
val &= ~PRNG_CONFIG_HW_ENABLE;
writel(val, rng->base + PRNG_CONFIG);
}
already_enabled:
clk_disable_unprepare(rng->clk);
return 0;
}
static int msm_rng_read(struct hwrng *hwrng, void *data, size_t max, bool wait)
{
struct msm_rng *rng = to_msm_rng(hwrng);
size_t currsize = 0;
u32 *retdata = data;
size_t maxsize;
int ret;
u32 val;
maxsize = min_t(size_t, MAX_HW_FIFO_SIZE, max);
if (maxsize < WORD_SZ)
return 0;
ret = clk_prepare_enable(rng->clk);
if (ret)
return ret;
do {
val = readl_relaxed(rng->base + PRNG_STATUS);
if (!(val & PRNG_STATUS_DATA_AVAIL))
break;
val = readl_relaxed(rng->base + PRNG_DATA_OUT);
if (!val)
break;
*retdata++ = val;
currsize += WORD_SZ;
if ((maxsize - currsize) < WORD_SZ)
break;
} while (currsize < maxsize);
clk_disable_unprepare(rng->clk);
return currsize;
}
static int msm_rng_init(struct hwrng *hwrng)
{
return msm_rng_enable(hwrng, 1);
}
static void msm_rng_cleanup(struct hwrng *hwrng)
{
msm_rng_enable(hwrng, 0);
}
static int msm_rng_probe(struct platform_device *pdev)
{
struct resource *res;
struct msm_rng *rng;
int ret;
rng = devm_kzalloc(&pdev->dev, sizeof(*rng), GFP_KERNEL);
if (!rng)
return -ENOMEM;
platform_set_drvdata(pdev, rng);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
rng->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(rng->base))
return PTR_ERR(rng->base);
rng->clk = devm_clk_get(&pdev->dev, "core");
if (IS_ERR(rng->clk))
return PTR_ERR(rng->clk);
rng->hwrng.name = KBUILD_MODNAME,
rng->hwrng.init = msm_rng_init,
rng->hwrng.cleanup = msm_rng_cleanup,
rng->hwrng.read = msm_rng_read,
ret = devm_hwrng_register(&pdev->dev, &rng->hwrng);
if (ret) {
dev_err(&pdev->dev, "failed to register hwrng\n");
return ret;
}
return 0;
}
