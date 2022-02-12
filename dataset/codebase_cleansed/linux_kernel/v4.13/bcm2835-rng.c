static void __init nsp_rng_init(void __iomem *base)
{
u32 val;
val = readl(base + RNG_INT_MASK);
val |= RNG_INT_OFF;
writel(val, base + RNG_INT_MASK);
}
static int bcm2835_rng_read(struct hwrng *rng, void *buf, size_t max,
bool wait)
{
void __iomem *rng_base = (void __iomem *)rng->priv;
u32 max_words = max / sizeof(u32);
u32 num_words, count;
while ((__raw_readl(rng_base + RNG_STATUS) >> 24) == 0) {
if (!wait)
return 0;
cpu_relax();
}
num_words = readl(rng_base + RNG_STATUS) >> 24;
if (num_words > max_words)
num_words = max_words;
for (count = 0; count < num_words; count++)
((u32 *)buf)[count] = readl(rng_base + RNG_DATA);
return num_words * sizeof(u32);
}
static int bcm2835_rng_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
void (*rng_setup)(void __iomem *base);
const struct of_device_id *rng_id;
void __iomem *rng_base;
int err;
rng_base = of_iomap(np, 0);
if (!rng_base) {
dev_err(dev, "failed to remap rng regs");
return -ENODEV;
}
bcm2835_rng_ops.priv = (unsigned long)rng_base;
rng_id = of_match_node(bcm2835_rng_of_match, np);
if (!rng_id) {
iounmap(rng_base);
return -EINVAL;
}
rng_setup = rng_id->data;
if (rng_setup)
rng_setup(rng_base);
__raw_writel(RNG_WARMUP_COUNT, rng_base + RNG_STATUS);
__raw_writel(RNG_RBGEN, rng_base + RNG_CTRL);
err = hwrng_register(&bcm2835_rng_ops);
if (err) {
dev_err(dev, "hwrng registration failed\n");
iounmap(rng_base);
} else
dev_info(dev, "hwrng registered\n");
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
