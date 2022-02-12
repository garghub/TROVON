static int hisi_rng_init(struct hwrng *rng)
{
struct hisi_rng *hrng = to_hisi_rng(rng);
int val = RNG_EN;
u32 seed;
get_random_bytes(&seed, sizeof(seed));
writel_relaxed(seed, hrng->base + RNG_SEED);
if (seed_sel == 1)
val |= RNG_RING_EN | RNG_SEED_SEL;
writel_relaxed(val, hrng->base + RNG_CTRL);
return 0;
}
static void hisi_rng_cleanup(struct hwrng *rng)
{
struct hisi_rng *hrng = to_hisi_rng(rng);
writel_relaxed(0, hrng->base + RNG_CTRL);
}
static int hisi_rng_read(struct hwrng *rng, void *buf, size_t max, bool wait)
{
struct hisi_rng *hrng = to_hisi_rng(rng);
u32 *data = buf;
*data = readl_relaxed(hrng->base + RNG_RAN_NUM);
return 4;
}
static int hisi_rng_probe(struct platform_device *pdev)
{
struct hisi_rng *rng;
struct resource *res;
int ret;
rng = devm_kzalloc(&pdev->dev, sizeof(*rng), GFP_KERNEL);
if (!rng)
return -ENOMEM;
platform_set_drvdata(pdev, rng);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
rng->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(rng->base))
return PTR_ERR(rng->base);
rng->rng.name = pdev->name;
rng->rng.init = hisi_rng_init;
rng->rng.cleanup = hisi_rng_cleanup;
rng->rng.read = hisi_rng_read;
ret = devm_hwrng_register(&pdev->dev, &rng->rng);
if (ret) {
dev_err(&pdev->dev, "failed to register hwrng\n");
return ret;
}
return 0;
}
