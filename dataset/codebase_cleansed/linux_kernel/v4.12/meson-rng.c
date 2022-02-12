static int meson_rng_read(struct hwrng *rng, void *buf, size_t max, bool wait)
{
struct meson_rng_data *data =
container_of(rng, struct meson_rng_data, rng);
*(u32 *)buf = readl_relaxed(data->base + RNG_DATA);
return sizeof(u32);
}
static void meson_rng_clk_disable(void *data)
{
clk_disable_unprepare(data);
}
static int meson_rng_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct meson_rng_data *data;
struct resource *res;
int ret;
data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->pdev = pdev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
data->base = devm_ioremap_resource(dev, res);
if (IS_ERR(data->base))
return PTR_ERR(data->base);
data->core_clk = devm_clk_get(dev, "core");
if (IS_ERR(data->core_clk))
data->core_clk = NULL;
if (data->core_clk) {
ret = clk_prepare_enable(data->core_clk);
if (ret)
return ret;
ret = devm_add_action_or_reset(dev, meson_rng_clk_disable,
data->core_clk);
if (ret)
return ret;
}
data->rng.name = pdev->name;
data->rng.read = meson_rng_read;
platform_set_drvdata(pdev, data);
return devm_hwrng_register(dev, &data->rng);
}
