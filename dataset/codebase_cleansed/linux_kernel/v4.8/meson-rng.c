static int meson_rng_read(struct hwrng *rng, void *buf, size_t max, bool wait)
{
struct meson_rng_data *data =
container_of(rng, struct meson_rng_data, rng);
if (max < sizeof(u32))
return 0;
*(u32 *)buf = readl_relaxed(data->base + RNG_DATA);
return sizeof(u32);
}
static int meson_rng_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct meson_rng_data *data;
struct resource *res;
data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->pdev = pdev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
data->base = devm_ioremap_resource(dev, res);
if (IS_ERR(data->base))
return PTR_ERR(data->base);
data->rng.name = pdev->name;
data->rng.read = meson_rng_read;
platform_set_drvdata(pdev, data);
return devm_hwrng_register(dev, &data->rng);
}
