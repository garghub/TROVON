static int bcm2835_rng_read(struct hwrng *rng, void *buf, size_t max,
bool wait)
{
void __iomem *rng_base = (void __iomem *)rng->priv;
while ((__raw_readl(rng_base + RNG_STATUS) >> 24) == 0) {
if (!wait)
return 0;
cpu_relax();
}
*(u32 *)buf = __raw_readl(rng_base + RNG_DATA);
return sizeof(u32);
}
static int bcm2835_rng_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
void __iomem *rng_base;
int err;
rng_base = of_iomap(np, 0);
if (!rng_base) {
dev_err(dev, "failed to remap rng regs");
return -ENODEV;
}
bcm2835_rng_ops.priv = (unsigned long)rng_base;
err = hwrng_register(&bcm2835_rng_ops);
if (err) {
dev_err(dev, "hwrng registration failed\n");
iounmap(rng_base);
} else {
dev_info(dev, "hwrng registered\n");
__raw_writel(RNG_WARMUP_COUNT, rng_base + RNG_STATUS);
__raw_writel(RNG_RBGEN, rng_base + RNG_CTRL);
}
return err;
}
static int bcm2835_rng_remove(struct platform_device *pdev)
{
void __iomem *rng_base = (void __iomem *)bcm2835_rng_ops.priv;
__raw_writel(0, rng_base + RNG_CTRL);
hwrng_unregister(&bcm2835_rng_ops);
iounmap(rng_base);
return 0;
}
