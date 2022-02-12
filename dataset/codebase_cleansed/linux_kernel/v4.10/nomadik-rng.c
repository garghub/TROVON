static int nmk_rng_read(struct hwrng *rng, void *data, size_t max, bool wait)
{
void __iomem *base = (void __iomem *)rng->priv;
*(u16 *)data = __raw_readl(base + 8) & 0xffff;
return 2;
}
static int nmk_rng_probe(struct amba_device *dev, const struct amba_id *id)
{
void __iomem *base;
int ret;
rng_clk = devm_clk_get(&dev->dev, NULL);
if (IS_ERR(rng_clk)) {
dev_err(&dev->dev, "could not get rng clock\n");
ret = PTR_ERR(rng_clk);
return ret;
}
clk_prepare_enable(rng_clk);
ret = amba_request_regions(dev, dev->dev.init_name);
if (ret)
goto out_clk;
ret = -ENOMEM;
base = devm_ioremap(&dev->dev, dev->res.start,
resource_size(&dev->res));
if (!base)
goto out_release;
nmk_rng.priv = (unsigned long)base;
ret = hwrng_register(&nmk_rng);
if (ret)
goto out_release;
return 0;
out_release:
amba_release_regions(dev);
out_clk:
clk_disable(rng_clk);
return ret;
}
static int nmk_rng_remove(struct amba_device *dev)
{
hwrng_unregister(&nmk_rng);
amba_release_regions(dev);
clk_disable(rng_clk);
return 0;
}
