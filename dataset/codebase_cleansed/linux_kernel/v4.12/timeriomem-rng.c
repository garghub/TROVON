static int timeriomem_rng_read(struct hwrng *hwrng, void *data,
size_t max, bool wait)
{
struct timeriomem_rng_private *priv =
container_of(hwrng, struct timeriomem_rng_private, rng_ops);
int retval = 0;
int period_us = ktime_to_us(priv->period);
if (max < sizeof(u32))
return 0;
if (!wait && !priv->present)
return 0;
wait_for_completion(&priv->completion);
do {
if (retval > 0)
usleep_range(period_us,
period_us + min(1, period_us / 100));
*(u32 *)data = readl(priv->io_base);
retval += sizeof(u32);
data += sizeof(u32);
max -= sizeof(u32);
} while (wait && max > sizeof(u32));
priv->present = 0;
reinit_completion(&priv->completion);
hrtimer_forward_now(&priv->timer, priv->period);
hrtimer_restart(&priv->timer);
return retval;
}
static enum hrtimer_restart timeriomem_rng_trigger(struct hrtimer *timer)
{
struct timeriomem_rng_private *priv
= container_of(timer, struct timeriomem_rng_private, timer);
priv->present = 1;
complete(&priv->completion);
return HRTIMER_NORESTART;
}
static int timeriomem_rng_probe(struct platform_device *pdev)
{
struct timeriomem_rng_data *pdata = pdev->dev.platform_data;
struct timeriomem_rng_private *priv;
struct resource *res;
int err = 0;
int period;
if (!pdev->dev.of_node && !pdata) {
dev_err(&pdev->dev, "timeriomem_rng_data is missing\n");
return -EINVAL;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENXIO;
if (res->start % 4 != 0 || resource_size(res) != 4) {
dev_err(&pdev->dev,
"address must be four bytes wide and aligned\n");
return -EINVAL;
}
priv = devm_kzalloc(&pdev->dev,
sizeof(struct timeriomem_rng_private), GFP_KERNEL);
if (!priv)
return -ENOMEM;
platform_set_drvdata(pdev, priv);
if (pdev->dev.of_node) {
int i;
if (!of_property_read_u32(pdev->dev.of_node,
"period", &i))
period = i;
else {
dev_err(&pdev->dev, "missing period\n");
return -EINVAL;
}
} else {
period = pdata->period;
}
priv->period = ns_to_ktime(period * NSEC_PER_USEC);
init_completion(&priv->completion);
hrtimer_init(&priv->timer, CLOCK_MONOTONIC, HRTIMER_MODE_ABS);
priv->timer.function = timeriomem_rng_trigger;
priv->rng_ops.name = dev_name(&pdev->dev);
priv->rng_ops.read = timeriomem_rng_read;
priv->io_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(priv->io_base)) {
return PTR_ERR(priv->io_base);
}
priv->present = 1;
complete(&priv->completion);
err = hwrng_register(&priv->rng_ops);
if (err) {
dev_err(&pdev->dev, "problem registering\n");
return err;
}
dev_info(&pdev->dev, "32bits from 0x%p @ %dus\n",
priv->io_base, period);
return 0;
}
static int timeriomem_rng_remove(struct platform_device *pdev)
{
struct timeriomem_rng_private *priv = platform_get_drvdata(pdev);
hwrng_unregister(&priv->rng_ops);
hrtimer_cancel(&priv->timer);
return 0;
}
