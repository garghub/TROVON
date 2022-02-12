static inline u32 omap_rng_read_reg(struct omap_rng_private_data *priv, int reg)
{
return __raw_readl(priv->base + reg);
}
static inline void omap_rng_write_reg(struct omap_rng_private_data *priv,
int reg, u32 val)
{
__raw_writel(val, priv->base + reg);
}
static int omap_rng_data_present(struct hwrng *rng, int wait)
{
struct omap_rng_private_data *priv;
int data, i;
priv = (struct omap_rng_private_data *)rng->priv;
for (i = 0; i < 20; i++) {
data = omap_rng_read_reg(priv, RNG_STAT_REG) ? 0 : 1;
if (data || !wait)
break;
udelay(10);
}
return data;
}
static int omap_rng_data_read(struct hwrng *rng, u32 *data)
{
struct omap_rng_private_data *priv;
priv = (struct omap_rng_private_data *)rng->priv;
*data = omap_rng_read_reg(priv, RNG_OUT_REG);
return sizeof(u32);
}
static int omap_rng_probe(struct platform_device *pdev)
{
struct omap_rng_private_data *priv;
int ret;
priv = kzalloc(sizeof(struct omap_rng_private_data), GFP_KERNEL);
if (!priv) {
dev_err(&pdev->dev, "could not allocate memory\n");
return -ENOMEM;
};
omap_rng_ops.priv = (unsigned long)priv;
platform_set_drvdata(pdev, priv);
priv->mem_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->base = devm_ioremap_resource(&pdev->dev, priv->mem_res);
if (IS_ERR(priv->base)) {
ret = PTR_ERR(priv->base);
goto err_ioremap;
}
platform_set_drvdata(pdev, priv);
pm_runtime_enable(&pdev->dev);
pm_runtime_get_sync(&pdev->dev);
ret = hwrng_register(&omap_rng_ops);
if (ret)
goto err_register;
dev_info(&pdev->dev, "OMAP Random Number Generator ver. %02x\n",
omap_rng_read_reg(priv, RNG_REV_REG));
omap_rng_write_reg(priv, RNG_MASK_REG, 0x1);
return 0;
err_register:
priv->base = NULL;
pm_runtime_disable(&pdev->dev);
err_ioremap:
kfree(priv);
return ret;
}
static int __exit omap_rng_remove(struct platform_device *pdev)
{
struct omap_rng_private_data *priv = platform_get_drvdata(pdev);
hwrng_unregister(&omap_rng_ops);
omap_rng_write_reg(priv, RNG_MASK_REG, 0x0);
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
release_mem_region(priv->mem_res->start, resource_size(priv->mem_res));
kfree(priv);
return 0;
}
static int omap_rng_suspend(struct device *dev)
{
struct omap_rng_private_data *priv = dev_get_drvdata(dev);
omap_rng_write_reg(priv, RNG_MASK_REG, 0x0);
pm_runtime_put_sync(dev);
return 0;
}
static int omap_rng_resume(struct device *dev)
{
struct omap_rng_private_data *priv = dev_get_drvdata(dev);
pm_runtime_get_sync(dev);
omap_rng_write_reg(priv, RNG_MASK_REG, 0x1);
return 0;
}
static int __init omap_rng_init(void)
{
return platform_driver_register(&omap_rng_driver);
}
static void __exit omap_rng_exit(void)
{
platform_driver_unregister(&omap_rng_driver);
}
