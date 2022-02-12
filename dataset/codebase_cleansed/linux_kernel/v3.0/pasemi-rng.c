static int pasemi_rng_data_present(struct hwrng *rng, int wait)
{
void __iomem *rng_regs = (void __iomem *)rng->priv;
int data, i;
for (i = 0; i < 20; i++) {
data = (in_le32(rng_regs + SDCRNG_CTL_REG)
& SDCRNG_CTL_FVLD_M) ? 1 : 0;
if (data || !wait)
break;
udelay(10);
}
return data;
}
static int pasemi_rng_data_read(struct hwrng *rng, u32 *data)
{
void __iomem *rng_regs = (void __iomem *)rng->priv;
*data = in_le32(rng_regs + SDCRNG_VAL_REG);
return 4;
}
static int pasemi_rng_init(struct hwrng *rng)
{
void __iomem *rng_regs = (void __iomem *)rng->priv;
u32 ctl;
ctl = SDCRNG_CTL_DR | SDCRNG_CTL_SELECT_RRG_RNG | SDCRNG_CTL_KSZ;
out_le32(rng_regs + SDCRNG_CTL_REG, ctl);
out_le32(rng_regs + SDCRNG_CTL_REG, ctl & ~SDCRNG_CTL_DR);
return 0;
}
static void pasemi_rng_cleanup(struct hwrng *rng)
{
void __iomem *rng_regs = (void __iomem *)rng->priv;
u32 ctl;
ctl = SDCRNG_CTL_RE | SDCRNG_CTL_CE;
out_le32(rng_regs + SDCRNG_CTL_REG,
in_le32(rng_regs + SDCRNG_CTL_REG) & ~ctl);
}
static int __devinit rng_probe(struct platform_device *ofdev)
{
void __iomem *rng_regs;
struct device_node *rng_np = ofdev->dev.of_node;
struct resource res;
int err = 0;
err = of_address_to_resource(rng_np, 0, &res);
if (err)
return -ENODEV;
rng_regs = ioremap(res.start, 0x100);
if (!rng_regs)
return -ENOMEM;
pasemi_rng.priv = (unsigned long)rng_regs;
printk(KERN_INFO "Registering PA Semi RNG\n");
err = hwrng_register(&pasemi_rng);
if (err)
iounmap(rng_regs);
return err;
}
static int __devexit rng_remove(struct platform_device *dev)
{
void __iomem *rng_regs = (void __iomem *)pasemi_rng.priv;
hwrng_unregister(&pasemi_rng);
iounmap(rng_regs);
return 0;
}
static int __init rng_init(void)
{
return platform_driver_register(&rng_driver);
}
static void __exit rng_exit(void)
{
platform_driver_unregister(&rng_driver);
}
