static u8 sp_read_reg8(const struct sja1000_priv *priv, int reg)
{
return ioread8(priv->reg_base + reg);
}
static void sp_write_reg8(const struct sja1000_priv *priv, int reg, u8 val)
{
iowrite8(val, priv->reg_base + reg);
}
static u8 sp_read_reg16(const struct sja1000_priv *priv, int reg)
{
return ioread8(priv->reg_base + reg * 2);
}
static void sp_write_reg16(const struct sja1000_priv *priv, int reg, u8 val)
{
iowrite8(val, priv->reg_base + reg * 2);
}
static u8 sp_read_reg32(const struct sja1000_priv *priv, int reg)
{
return ioread8(priv->reg_base + reg * 4);
}
static void sp_write_reg32(const struct sja1000_priv *priv, int reg, u8 val)
{
iowrite8(val, priv->reg_base + reg * 4);
}
static int sp_probe(struct platform_device *pdev)
{
int err;
void __iomem *addr;
struct net_device *dev;
struct sja1000_priv *priv;
struct resource *res_mem, *res_irq;
struct sja1000_platform_data *pdata;
pdata = pdev->dev.platform_data;
if (!pdata) {
dev_err(&pdev->dev, "No platform data provided!\n");
err = -ENODEV;
goto exit;
}
res_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
res_irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res_mem || !res_irq) {
err = -ENODEV;
goto exit;
}
if (!request_mem_region(res_mem->start, resource_size(res_mem),
DRV_NAME)) {
err = -EBUSY;
goto exit;
}
addr = ioremap_nocache(res_mem->start, resource_size(res_mem));
if (!addr) {
err = -ENOMEM;
goto exit_release;
}
dev = alloc_sja1000dev(0);
if (!dev) {
err = -ENOMEM;
goto exit_iounmap;
}
priv = netdev_priv(dev);
dev->irq = res_irq->start;
priv->irq_flags = res_irq->flags & (IRQF_TRIGGER_MASK | IRQF_SHARED);
priv->reg_base = addr;
priv->can.clock.freq = pdata->osc_freq / 2;
priv->ocr = pdata->ocr;
priv->cdr = pdata->cdr;
switch (res_mem->flags & IORESOURCE_MEM_TYPE_MASK) {
case IORESOURCE_MEM_32BIT:
priv->read_reg = sp_read_reg32;
priv->write_reg = sp_write_reg32;
break;
case IORESOURCE_MEM_16BIT:
priv->read_reg = sp_read_reg16;
priv->write_reg = sp_write_reg16;
break;
case IORESOURCE_MEM_8BIT:
default:
priv->read_reg = sp_read_reg8;
priv->write_reg = sp_write_reg8;
break;
}
dev_set_drvdata(&pdev->dev, dev);
SET_NETDEV_DEV(dev, &pdev->dev);
err = register_sja1000dev(dev);
if (err) {
dev_err(&pdev->dev, "registering %s failed (err=%d)\n",
DRV_NAME, err);
goto exit_free;
}
dev_info(&pdev->dev, "%s device registered (reg_base=%p, irq=%d)\n",
DRV_NAME, priv->reg_base, dev->irq);
return 0;
exit_free:
free_sja1000dev(dev);
exit_iounmap:
iounmap(addr);
exit_release:
release_mem_region(res_mem->start, resource_size(res_mem));
exit:
return err;
}
static int sp_remove(struct platform_device *pdev)
{
struct net_device *dev = dev_get_drvdata(&pdev->dev);
struct sja1000_priv *priv = netdev_priv(dev);
struct resource *res;
unregister_sja1000dev(dev);
dev_set_drvdata(&pdev->dev, NULL);
if (priv->reg_base)
iounmap(priv->reg_base);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(res->start, resource_size(res));
free_sja1000dev(dev);
return 0;
}
static int __init sp_init(void)
{
return platform_driver_register(&sp_driver);
}
static void __exit sp_exit(void)
{
platform_driver_unregister(&sp_driver);
}
