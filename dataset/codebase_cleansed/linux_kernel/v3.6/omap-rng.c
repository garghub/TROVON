static inline u32 omap_rng_read_reg(int reg)
{
return __raw_readl(rng_base + reg);
}
static inline void omap_rng_write_reg(int reg, u32 val)
{
__raw_writel(val, rng_base + reg);
}
static int omap_rng_data_present(struct hwrng *rng, int wait)
{
int data, i;
for (i = 0; i < 20; i++) {
data = omap_rng_read_reg(RNG_STAT_REG) ? 0 : 1;
if (data || !wait)
break;
udelay(10);
}
return data;
}
static int omap_rng_data_read(struct hwrng *rng, u32 *data)
{
*data = omap_rng_read_reg(RNG_OUT_REG);
return 4;
}
static int __devinit omap_rng_probe(struct platform_device *pdev)
{
struct resource *res;
int ret;
if (rng_dev)
return -EBUSY;
if (cpu_is_omap24xx()) {
rng_ick = clk_get(&pdev->dev, "ick");
if (IS_ERR(rng_ick)) {
dev_err(&pdev->dev, "Could not get rng_ick\n");
ret = PTR_ERR(rng_ick);
return ret;
} else
clk_enable(rng_ick);
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
rng_base = devm_request_and_ioremap(&pdev->dev, res);
if (!rng_base) {
ret = -ENOMEM;
goto err_ioremap;
}
dev_set_drvdata(&pdev->dev, res);
ret = hwrng_register(&omap_rng_ops);
if (ret)
goto err_register;
dev_info(&pdev->dev, "OMAP Random Number Generator ver. %02x\n",
omap_rng_read_reg(RNG_REV_REG));
omap_rng_write_reg(RNG_MASK_REG, 0x1);
rng_dev = pdev;
return 0;
err_register:
rng_base = NULL;
err_ioremap:
if (cpu_is_omap24xx()) {
clk_disable(rng_ick);
clk_put(rng_ick);
}
return ret;
}
static int __exit omap_rng_remove(struct platform_device *pdev)
{
hwrng_unregister(&omap_rng_ops);
omap_rng_write_reg(RNG_MASK_REG, 0x0);
if (cpu_is_omap24xx()) {
clk_disable(rng_ick);
clk_put(rng_ick);
}
rng_base = NULL;
return 0;
}
static int omap_rng_suspend(struct device *dev)
{
omap_rng_write_reg(RNG_MASK_REG, 0x0);
return 0;
}
static int omap_rng_resume(struct device *dev)
{
omap_rng_write_reg(RNG_MASK_REG, 0x1);
return 0;
}
static int __init omap_rng_init(void)
{
if (!cpu_is_omap16xx() && !cpu_is_omap24xx())
return -ENODEV;
return platform_driver_register(&omap_rng_driver);
}
static void __exit omap_rng_exit(void)
{
platform_driver_unregister(&omap_rng_driver);
}
