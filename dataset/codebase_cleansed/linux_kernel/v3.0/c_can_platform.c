static u16 c_can_plat_read_reg_aligned_to_16bit(struct c_can_priv *priv,
void *reg)
{
return readw(reg);
}
static void c_can_plat_write_reg_aligned_to_16bit(struct c_can_priv *priv,
void *reg, u16 val)
{
writew(val, reg);
}
static u16 c_can_plat_read_reg_aligned_to_32bit(struct c_can_priv *priv,
void *reg)
{
return readw(reg + (long)reg - (long)priv->regs);
}
static void c_can_plat_write_reg_aligned_to_32bit(struct c_can_priv *priv,
void *reg, u16 val)
{
writew(val, reg + (long)reg - (long)priv->regs);
}
static int __devinit c_can_plat_probe(struct platform_device *pdev)
{
int ret;
void __iomem *addr;
struct net_device *dev;
struct c_can_priv *priv;
struct resource *mem;
int irq;
#ifdef CONFIG_HAVE_CLK
struct clk *clk;
clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "no clock defined\n");
ret = -ENODEV;
goto exit;
}
#endif
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq = platform_get_irq(pdev, 0);
if (!mem || irq <= 0) {
ret = -ENODEV;
goto exit_free_clk;
}
if (!request_mem_region(mem->start, resource_size(mem),
KBUILD_MODNAME)) {
dev_err(&pdev->dev, "resource unavailable\n");
ret = -ENODEV;
goto exit_free_clk;
}
addr = ioremap(mem->start, resource_size(mem));
if (!addr) {
dev_err(&pdev->dev, "failed to map can port\n");
ret = -ENOMEM;
goto exit_release_mem;
}
dev = alloc_c_can_dev();
if (!dev) {
ret = -ENOMEM;
goto exit_iounmap;
}
priv = netdev_priv(dev);
dev->irq = irq;
priv->regs = addr;
#ifdef CONFIG_HAVE_CLK
priv->can.clock.freq = clk_get_rate(clk);
priv->priv = clk;
#endif
switch (mem->flags & IORESOURCE_MEM_TYPE_MASK) {
case IORESOURCE_MEM_32BIT:
priv->read_reg = c_can_plat_read_reg_aligned_to_32bit;
priv->write_reg = c_can_plat_write_reg_aligned_to_32bit;
break;
case IORESOURCE_MEM_16BIT:
default:
priv->read_reg = c_can_plat_read_reg_aligned_to_16bit;
priv->write_reg = c_can_plat_write_reg_aligned_to_16bit;
break;
}
platform_set_drvdata(pdev, dev);
SET_NETDEV_DEV(dev, &pdev->dev);
ret = register_c_can_dev(dev);
if (ret) {
dev_err(&pdev->dev, "registering %s failed (err=%d)\n",
KBUILD_MODNAME, ret);
goto exit_free_device;
}
dev_info(&pdev->dev, "%s device registered (regs=%p, irq=%d)\n",
KBUILD_MODNAME, priv->regs, dev->irq);
return 0;
exit_free_device:
platform_set_drvdata(pdev, NULL);
free_c_can_dev(dev);
exit_iounmap:
iounmap(addr);
exit_release_mem:
release_mem_region(mem->start, resource_size(mem));
exit_free_clk:
#ifdef CONFIG_HAVE_CLK
clk_put(clk);
exit:
#endif
dev_err(&pdev->dev, "probe failed\n");
return ret;
}
static int __devexit c_can_plat_remove(struct platform_device *pdev)
{
struct net_device *dev = platform_get_drvdata(pdev);
struct c_can_priv *priv = netdev_priv(dev);
struct resource *mem;
unregister_c_can_dev(dev);
platform_set_drvdata(pdev, NULL);
free_c_can_dev(dev);
iounmap(priv->regs);
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(mem->start, resource_size(mem));
#ifdef CONFIG_HAVE_CLK
clk_put(priv->priv);
#endif
return 0;
}
static int __init c_can_plat_init(void)
{
return platform_driver_register(&c_can_plat_driver);
}
static void __exit c_can_plat_exit(void)
{
platform_driver_unregister(&c_can_plat_driver);
}
