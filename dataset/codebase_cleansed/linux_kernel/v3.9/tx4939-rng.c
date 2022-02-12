static void rng_io_start(void)
{
#ifndef CONFIG_64BIT
local_irq_disable();
#endif
}
static void rng_io_end(void)
{
#ifndef CONFIG_64BIT
local_irq_enable();
#endif
}
static u64 read_rng(void __iomem *base, unsigned int offset)
{
return ____raw_readq(base + offset);
}
static void write_rng(u64 val, void __iomem *base, unsigned int offset)
{
return ____raw_writeq(val, base + offset);
}
static int tx4939_rng_data_present(struct hwrng *rng, int wait)
{
struct tx4939_rng *rngdev = container_of(rng, struct tx4939_rng, rng);
int i;
if (rngdev->data_avail)
return rngdev->data_avail;
for (i = 0; i < 20; i++) {
rng_io_start();
if (!(read_rng(rngdev->base, TX4939_RNG_RCSR)
& TX4939_RNG_RCSR_ST)) {
rngdev->databuf[0] =
read_rng(rngdev->base, TX4939_RNG_ROR(0));
rngdev->databuf[1] =
read_rng(rngdev->base, TX4939_RNG_ROR(1));
rngdev->databuf[2] =
read_rng(rngdev->base, TX4939_RNG_ROR(2));
rngdev->data_avail =
sizeof(rngdev->databuf) / sizeof(u32);
write_rng(TX4939_RNG_RCSR_ST,
rngdev->base, TX4939_RNG_RCSR);
wait = 0;
}
rng_io_end();
if (!wait)
break;
ndelay(90 * 5);
}
return rngdev->data_avail;
}
static int tx4939_rng_data_read(struct hwrng *rng, u32 *buffer)
{
struct tx4939_rng *rngdev = container_of(rng, struct tx4939_rng, rng);
rngdev->data_avail--;
*buffer = *((u32 *)&rngdev->databuf + rngdev->data_avail);
return sizeof(u32);
}
static int __init tx4939_rng_probe(struct platform_device *dev)
{
struct tx4939_rng *rngdev;
struct resource *r;
int i;
r = platform_get_resource(dev, IORESOURCE_MEM, 0);
if (!r)
return -EBUSY;
rngdev = devm_kzalloc(&dev->dev, sizeof(*rngdev), GFP_KERNEL);
if (!rngdev)
return -ENOMEM;
rngdev->base = devm_ioremap_resource(&dev->dev, r);
if (IS_ERR(rngdev->base))
return PTR_ERR(rngdev->base);
rngdev->rng.name = dev_name(&dev->dev);
rngdev->rng.data_present = tx4939_rng_data_present;
rngdev->rng.data_read = tx4939_rng_data_read;
rng_io_start();
write_rng(TX4939_RNG_RCSR_RST, rngdev->base, TX4939_RNG_RCSR);
write_rng(0, rngdev->base, TX4939_RNG_RCSR);
write_rng(TX4939_RNG_RCSR_ST, rngdev->base, TX4939_RNG_RCSR);
rng_io_end();
for (i = 0; i < 2; i++) {
rngdev->data_avail = 0;
if (!tx4939_rng_data_present(&rngdev->rng, 1))
return -EIO;
}
platform_set_drvdata(dev, rngdev);
return hwrng_register(&rngdev->rng);
}
static int __exit tx4939_rng_remove(struct platform_device *dev)
{
struct tx4939_rng *rngdev = platform_get_drvdata(dev);
hwrng_unregister(&rngdev->rng);
platform_set_drvdata(dev, NULL);
return 0;
}
static int __init tx4939rng_init(void)
{
return platform_driver_probe(&tx4939_rng_driver, tx4939_rng_probe);
}
static void __exit tx4939rng_exit(void)
{
platform_driver_unregister(&tx4939_rng_driver);
}
