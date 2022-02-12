static int stm32_rng_read(struct hwrng *rng, void *data, size_t max, bool wait)
{
struct stm32_rng_private *priv =
container_of(rng, struct stm32_rng_private, rng);
u32 sr;
int retval = 0;
pm_runtime_get_sync((struct device *) priv->rng.priv);
while (max > sizeof(u32)) {
sr = readl_relaxed(priv->base + RNG_SR);
if (!sr && wait) {
unsigned int timeout = RNG_TIMEOUT;
do {
cpu_relax();
sr = readl_relaxed(priv->base + RNG_SR);
} while (!sr && --timeout);
}
if (sr != RNG_SR_DRDY) {
if (WARN_ONCE(sr & (RNG_SR_SEIS | RNG_SR_CEIS),
"bad RNG status - %x\n", sr))
writel_relaxed(0, priv->base + RNG_SR);
break;
}
*(u32 *)data = readl_relaxed(priv->base + RNG_DR);
retval += sizeof(u32);
data += sizeof(u32);
max -= sizeof(u32);
}
pm_runtime_mark_last_busy((struct device *) priv->rng.priv);
pm_runtime_put_sync_autosuspend((struct device *) priv->rng.priv);
return retval || !wait ? retval : -EIO;
}
static int stm32_rng_init(struct hwrng *rng)
{
struct stm32_rng_private *priv =
container_of(rng, struct stm32_rng_private, rng);
int err;
err = clk_prepare_enable(priv->clk);
if (err)
return err;
writel_relaxed(RNG_CR_RNGEN, priv->base + RNG_CR);
writel_relaxed(0, priv->base + RNG_SR);
return 0;
}
static void stm32_rng_cleanup(struct hwrng *rng)
{
struct stm32_rng_private *priv =
container_of(rng, struct stm32_rng_private, rng);
writel_relaxed(0, priv->base + RNG_CR);
clk_disable_unprepare(priv->clk);
}
static int stm32_rng_probe(struct platform_device *ofdev)
{
struct device *dev = &ofdev->dev;
struct device_node *np = ofdev->dev.of_node;
struct stm32_rng_private *priv;
struct resource res;
int err;
priv = devm_kzalloc(dev, sizeof(struct stm32_rng_private), GFP_KERNEL);
if (!priv)
return -ENOMEM;
err = of_address_to_resource(np, 0, &res);
if (err)
return err;
priv->base = devm_ioremap_resource(dev, &res);
if (IS_ERR(priv->base))
return PTR_ERR(priv->base);
priv->clk = devm_clk_get(&ofdev->dev, NULL);
if (IS_ERR(priv->clk))
return PTR_ERR(priv->clk);
dev_set_drvdata(dev, priv);
priv->rng.name = dev_driver_string(dev),
#ifndef CONFIG_PM
priv->rng.init = stm32_rng_init,
priv->rng.cleanup = stm32_rng_cleanup,
#endif
priv->rng.read = stm32_rng_read,
priv->rng.priv = (unsigned long) dev;
pm_runtime_set_autosuspend_delay(dev, 100);
pm_runtime_use_autosuspend(dev);
pm_runtime_enable(dev);
return devm_hwrng_register(dev, &priv->rng);
}
static int stm32_rng_runtime_suspend(struct device *dev)
{
struct stm32_rng_private *priv = dev_get_drvdata(dev);
stm32_rng_cleanup(&priv->rng);
return 0;
}
static int stm32_rng_runtime_resume(struct device *dev)
{
struct stm32_rng_private *priv = dev_get_drvdata(dev);
return stm32_rng_init(&priv->rng);
}
