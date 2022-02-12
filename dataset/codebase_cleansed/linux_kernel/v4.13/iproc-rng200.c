static void iproc_rng200_restart(void __iomem *rng_base)
{
uint32_t val;
val = ioread32(rng_base + RNG_CTRL_OFFSET);
val &= ~RNG_CTRL_RNG_RBGEN_MASK;
val |= RNG_CTRL_RNG_RBGEN_DISABLE;
iowrite32(val, rng_base + RNG_CTRL_OFFSET);
iowrite32(0xFFFFFFFFUL, rng_base + RNG_INT_STATUS_OFFSET);
val = ioread32(rng_base + RBG_SOFT_RESET_OFFSET);
val |= RBG_SOFT_RESET;
iowrite32(val, rng_base + RBG_SOFT_RESET_OFFSET);
val = ioread32(rng_base + RNG_SOFT_RESET_OFFSET);
val |= RNG_SOFT_RESET;
iowrite32(val, rng_base + RNG_SOFT_RESET_OFFSET);
val = ioread32(rng_base + RNG_SOFT_RESET_OFFSET);
val &= ~RNG_SOFT_RESET;
iowrite32(val, rng_base + RNG_SOFT_RESET_OFFSET);
val = ioread32(rng_base + RBG_SOFT_RESET_OFFSET);
val &= ~RBG_SOFT_RESET;
iowrite32(val, rng_base + RBG_SOFT_RESET_OFFSET);
val = ioread32(rng_base + RNG_CTRL_OFFSET);
val &= ~RNG_CTRL_RNG_RBGEN_MASK;
val |= RNG_CTRL_RNG_RBGEN_ENABLE;
iowrite32(val, rng_base + RNG_CTRL_OFFSET);
}
static int iproc_rng200_read(struct hwrng *rng, void *buf, size_t max,
bool wait)
{
struct iproc_rng200_dev *priv = to_rng_priv(rng);
uint32_t num_remaining = max;
uint32_t status;
#define MAX_RESETS_PER_READ 1
uint32_t num_resets = 0;
#define MAX_IDLE_TIME (1 * HZ)
unsigned long idle_endtime = jiffies + MAX_IDLE_TIME;
while ((num_remaining > 0) && time_before(jiffies, idle_endtime)) {
status = ioread32(priv->base + RNG_INT_STATUS_OFFSET);
if ((status & (RNG_INT_STATUS_MASTER_FAIL_LOCKOUT_IRQ_MASK |
RNG_INT_STATUS_NIST_FAIL_IRQ_MASK)) != 0) {
if (num_resets >= MAX_RESETS_PER_READ)
return max - num_remaining;
iproc_rng200_restart(priv->base);
num_resets++;
}
if ((ioread32(priv->base + RNG_FIFO_COUNT_OFFSET) &
RNG_FIFO_COUNT_RNG_FIFO_COUNT_MASK) > 0) {
if (num_remaining >= sizeof(uint32_t)) {
*(uint32_t *)buf = ioread32(priv->base +
RNG_FIFO_DATA_OFFSET);
buf += sizeof(uint32_t);
num_remaining -= sizeof(uint32_t);
} else {
uint32_t rnd_number = ioread32(priv->base +
RNG_FIFO_DATA_OFFSET);
memcpy(buf, &rnd_number, num_remaining);
buf += num_remaining;
num_remaining = 0;
}
idle_endtime = jiffies + MAX_IDLE_TIME;
} else {
if (!wait)
return max - num_remaining;
usleep_range(min(num_remaining * 10, 500U), 500);
}
}
return max - num_remaining;
}
static int iproc_rng200_init(struct hwrng *rng)
{
struct iproc_rng200_dev *priv = to_rng_priv(rng);
uint32_t val;
val = ioread32(priv->base + RNG_CTRL_OFFSET);
val &= ~RNG_CTRL_RNG_RBGEN_MASK;
val |= RNG_CTRL_RNG_RBGEN_ENABLE;
iowrite32(val, priv->base + RNG_CTRL_OFFSET);
return 0;
}
static void iproc_rng200_cleanup(struct hwrng *rng)
{
struct iproc_rng200_dev *priv = to_rng_priv(rng);
uint32_t val;
val = ioread32(priv->base + RNG_CTRL_OFFSET);
val &= ~RNG_CTRL_RNG_RBGEN_MASK;
val |= RNG_CTRL_RNG_RBGEN_DISABLE;
iowrite32(val, priv->base + RNG_CTRL_OFFSET);
}
static int iproc_rng200_probe(struct platform_device *pdev)
{
struct iproc_rng200_dev *priv;
struct resource *res;
struct device *dev = &pdev->dev;
int ret;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(dev, "failed to get rng resources\n");
return -EINVAL;
}
priv->base = devm_ioremap_resource(dev, res);
if (IS_ERR(priv->base)) {
dev_err(dev, "failed to remap rng regs\n");
return PTR_ERR(priv->base);
}
priv->rng.name = "iproc-rng200",
priv->rng.read = iproc_rng200_read,
priv->rng.init = iproc_rng200_init,
priv->rng.cleanup = iproc_rng200_cleanup,
ret = devm_hwrng_register(dev, &priv->rng);
if (ret) {
dev_err(dev, "hwrng registration failed\n");
return ret;
}
dev_info(dev, "hwrng registered\n");
return 0;
}
