u32 anatop_read_reg(struct anatop *adata, u32 addr)
{
return readl(adata->ioreg + addr);
}
void anatop_write_reg(struct anatop *adata, u32 addr, u32 data, u32 mask)
{
u32 val;
data &= mask;
spin_lock(&adata->reglock);
val = readl(adata->ioreg + addr);
val &= ~mask;
val |= data;
writel(val, adata->ioreg + addr);
spin_unlock(&adata->reglock);
}
static int __devinit of_anatop_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
void *ioreg;
struct anatop *drvdata;
ioreg = of_iomap(np, 0);
if (!ioreg)
return -EADDRNOTAVAIL;
drvdata = devm_kzalloc(dev, sizeof(*drvdata), GFP_KERNEL);
if (!drvdata)
return -ENOMEM;
drvdata->ioreg = ioreg;
spin_lock_init(&drvdata->reglock);
platform_set_drvdata(pdev, drvdata);
of_platform_populate(np, of_anatop_match, NULL, dev);
return 0;
}
static int __devexit of_anatop_remove(struct platform_device *pdev)
{
struct anatop *drvdata;
drvdata = platform_get_drvdata(pdev);
iounmap(drvdata->ioreg);
return 0;
}
static int __init anatop_init(void)
{
return platform_driver_register(&anatop_of_driver);
}
static void __exit anatop_exit(void)
{
platform_driver_unregister(&anatop_of_driver);
}
