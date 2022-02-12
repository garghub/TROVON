static int ixp4xx_rng_data_read(struct hwrng *rng, u32 *buffer)
{
void __iomem * rng_base = (void __iomem *)rng->priv;
*buffer = __raw_readl(rng_base);
return 4;
}
static int __init ixp4xx_rng_init(void)
{
void __iomem * rng_base;
int err;
rng_base = ioremap(0x70002100, 4);
if (!rng_base)
return -ENOMEM;
ixp4xx_rng_ops.priv = (unsigned long)rng_base;
err = hwrng_register(&ixp4xx_rng_ops);
if (err)
iounmap(rng_base);
return err;
}
static void __exit ixp4xx_rng_exit(void)
{
void __iomem * rng_base = (void __iomem *)ixp4xx_rng_ops.priv;
hwrng_unregister(&ixp4xx_rng_ops);
iounmap(rng_base);
}
