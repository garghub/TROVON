static u16 c_can_plat_read_reg_aligned_to_16bit(struct c_can_priv *priv,
enum reg index)
{
return readw(priv->base + priv->regs[index]);
}
static void c_can_plat_write_reg_aligned_to_16bit(struct c_can_priv *priv,
enum reg index, u16 val)
{
writew(val, priv->base + priv->regs[index]);
}
static u16 c_can_plat_read_reg_aligned_to_32bit(struct c_can_priv *priv,
enum reg index)
{
return readw(priv->base + 2 * priv->regs[index]);
}
static void c_can_plat_write_reg_aligned_to_32bit(struct c_can_priv *priv,
enum reg index, u16 val)
{
writew(val, priv->base + 2 * priv->regs[index]);
}
static int __devinit c_can_plat_probe(struct platform_device *pdev)
{
int ret;
void __iomem *addr;
struct net_device *dev;
struct c_can_priv *priv;
const struct platform_device_id *id;
struct resource *mem;
int irq;
struct clk *clk;
clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "no clock defined\n");
ret = -ENODEV;
goto exit;
}
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
id = platform_get_device_id(pdev);
switch (id->driver_data) {
case C_CAN_DEVTYPE:
priv->regs = reg_map_c_can;
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
break;
case D_CAN_DEVTYPE:
priv->regs = reg_map_d_can;
priv->can.ctrlmode_supported |= CAN_CTRLMODE_3_SAMPLES;
priv->read_reg = c_can_plat_read_reg_aligned_to_16bit;
priv->write_reg = c_can_plat_write_reg_aligned_to_16bit;
break;
default:
ret = -EINVAL;
goto exit_free_device;
}
dev->irq = irq;
priv->base = addr;
priv->can.clock.freq = clk_get_rate(clk);
priv->priv = clk;
platform_set_drvdata(pdev, dev);
SET_NETDEV_DEV(dev, &pdev->dev);
ret = register_c_can_dev(dev);
if (ret) {
dev_err(&pdev->dev, "registering %s failed (err=%d)\n",
KBUILD_MODNAME, ret);
goto exit_free_device;
}
dev_info(&pdev->dev, "%s device registered (regs=%p, irq=%d)\n",
KBUILD_MODNAME, priv->base, dev->irq);
return 0;
exit_free_device:
platform_set_drvdata(pdev, NULL);
free_c_can_dev(dev);
exit_iounmap:
iounmap(addr);
exit_release_mem:
release_mem_region(mem->start, resource_size(mem));
exit_free_clk:
clk_put(clk);
exit:
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
iounmap(priv->base);
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(mem->start, resource_size(mem));
clk_put(priv->priv);
return 0;
}
