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
static int rng_probe(struct platform_device *pdev)
{
void __iomem *rng_regs;
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
rng_regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(rng_regs))
return PTR_ERR(rng_regs);
pasemi_rng.priv = (unsigned long)rng_regs;
pr_info("Registering PA Semi RNG\n");
return devm_hwrng_register(&pdev->dev, &pasemi_rng);
}
