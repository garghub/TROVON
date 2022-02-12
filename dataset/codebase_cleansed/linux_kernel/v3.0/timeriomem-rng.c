static int timeriomem_rng_data_present(struct hwrng *rng, int wait)
{
if (rng->priv == 0)
return 1;
if (!wait || timeriomem_rng_data->present)
return timeriomem_rng_data->present;
wait_for_completion(&timeriomem_rng_data->completion);
return 1;
}
static int timeriomem_rng_data_read(struct hwrng *rng, u32 *data)
{
unsigned long cur;
s32 delay;
*data = readl(timeriomem_rng_data->address);
if (rng->priv != 0) {
cur = jiffies;
delay = cur - timeriomem_rng_timer.expires;
delay = rng->priv - (delay % rng->priv);
timeriomem_rng_timer.expires = cur + delay;
timeriomem_rng_data->present = 0;
init_completion(&timeriomem_rng_data->completion);
add_timer(&timeriomem_rng_timer);
}
return 4;
}
static void timeriomem_rng_trigger(unsigned long dummy)
{
timeriomem_rng_data->present = 1;
complete(&timeriomem_rng_data->completion);
}
static int __devinit timeriomem_rng_probe(struct platform_device *pdev)
{
struct resource *res;
int ret;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENOENT;
timeriomem_rng_data = pdev->dev.platform_data;
timeriomem_rng_data->address = ioremap(res->start,
res->end - res->start + 1);
if (!timeriomem_rng_data->address)
return -EIO;
if (timeriomem_rng_data->period != 0
&& usecs_to_jiffies(timeriomem_rng_data->period) > 0) {
timeriomem_rng_timer.expires = jiffies;
timeriomem_rng_ops.priv = usecs_to_jiffies(
timeriomem_rng_data->period);
}
timeriomem_rng_data->present = 1;
ret = hwrng_register(&timeriomem_rng_ops);
if (ret)
goto failed;
dev_info(&pdev->dev, "32bits from 0x%p @ %dus\n",
timeriomem_rng_data->address,
timeriomem_rng_data->period);
return 0;
failed:
dev_err(&pdev->dev, "problem registering\n");
iounmap(timeriomem_rng_data->address);
return ret;
}
static int __devexit timeriomem_rng_remove(struct platform_device *pdev)
{
del_timer_sync(&timeriomem_rng_timer);
hwrng_unregister(&timeriomem_rng_ops);
iounmap(timeriomem_rng_data->address);
return 0;
}
static int __init timeriomem_rng_init(void)
{
return platform_driver_register(&timeriomem_rng_driver);
}
static void __exit timeriomem_rng_exit(void)
{
platform_driver_unregister(&timeriomem_rng_driver);
}
