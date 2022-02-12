static int ppc4xx_rng_data_present(struct hwrng *rng, int wait)
{
void __iomem *rng_regs = (void __iomem *) rng->priv;
int busy, i, present = 0;
for (i = 0; i < 20; i++) {
busy = (in_le32(rng_regs + PPC4XX_TRNG_STAT) & PPC4XX_TRNG_STAT_B);
if (!busy || !wait) {
present = 1;
break;
}
udelay(10);
}
return present;
}
static int ppc4xx_rng_data_read(struct hwrng *rng, u32 *data)
{
void __iomem *rng_regs = (void __iomem *) rng->priv;
*data = in_le32(rng_regs + PPC4XX_TRNG_DATA);
return 4;
}
static int ppc4xx_rng_enable(int enable)
{
struct device_node *ctrl;
void __iomem *ctrl_reg;
int err = 0;
u32 val;
ctrl = of_find_compatible_node(NULL, NULL, "amcc,ppc4xx-crypto");
if (!ctrl)
return -ENODEV;
ctrl_reg = of_iomap(ctrl, 0);
if (!ctrl_reg) {
err = -ENODEV;
goto out;
}
val = in_le32(ctrl_reg + PPC4XX_TRNG_DEV_CTRL);
if (enable)
val |= PPC4XX_TRNGE;
else
val = val & ~PPC4XX_TRNGE;
out_le32(ctrl_reg + PPC4XX_TRNG_DEV_CTRL, val);
iounmap(ctrl_reg);
out:
of_node_put(ctrl);
return err;
}
static int ppc4xx_rng_probe(struct platform_device *dev)
{
void __iomem *rng_regs;
int err = 0;
rng_regs = of_iomap(dev->dev.of_node, 0);
if (!rng_regs)
return -ENODEV;
err = ppc4xx_rng_enable(1);
if (err)
return err;
out_le32(rng_regs + PPC4XX_TRNG_CTRL, PPC4XX_TRNG_CTRL_DALM);
ppc4xx_rng.priv = (unsigned long) rng_regs;
err = hwrng_register(&ppc4xx_rng);
return err;
}
static int ppc4xx_rng_remove(struct platform_device *dev)
{
void __iomem *rng_regs = (void __iomem *) ppc4xx_rng.priv;
hwrng_unregister(&ppc4xx_rng);
ppc4xx_rng_enable(0);
iounmap(rng_regs);
return 0;
}
