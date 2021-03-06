static int uio_pdrv_genirq_open(struct uio_info *info, struct inode *inode)
{
struct uio_pdrv_genirq_platdata *priv = info->priv;
pm_runtime_get_sync(&priv->pdev->dev);
return 0;
}
static int uio_pdrv_genirq_release(struct uio_info *info, struct inode *inode)
{
struct uio_pdrv_genirq_platdata *priv = info->priv;
pm_runtime_put_sync(&priv->pdev->dev);
return 0;
}
static irqreturn_t uio_pdrv_genirq_handler(int irq, struct uio_info *dev_info)
{
struct uio_pdrv_genirq_platdata *priv = dev_info->priv;
if (!test_and_set_bit(0, &priv->flags))
disable_irq_nosync(irq);
return IRQ_HANDLED;
}
static int uio_pdrv_genirq_irqcontrol(struct uio_info *dev_info, s32 irq_on)
{
struct uio_pdrv_genirq_platdata *priv = dev_info->priv;
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
if (irq_on) {
if (test_and_clear_bit(0, &priv->flags))
enable_irq(dev_info->irq);
} else {
if (!test_and_set_bit(0, &priv->flags))
disable_irq(dev_info->irq);
}
spin_unlock_irqrestore(&priv->lock, flags);
return 0;
}
static int uio_pdrv_genirq_probe(struct platform_device *pdev)
{
struct uio_info *uioinfo = pdev->dev.platform_data;
struct uio_pdrv_genirq_platdata *priv;
struct uio_mem *uiomem;
int ret = -EINVAL;
int i;
if (!uioinfo) {
int irq;
uioinfo = kzalloc(sizeof(*uioinfo), GFP_KERNEL);
if (!uioinfo) {
ret = -ENOMEM;
dev_err(&pdev->dev, "unable to kmalloc\n");
goto bad2;
}
uioinfo->name = pdev->dev.of_node->name;
uioinfo->version = "devicetree";
irq = platform_get_irq(pdev, 0);
if (irq == -ENXIO)
uioinfo->irq = UIO_IRQ_NONE;
else
uioinfo->irq = irq;
}
if (!uioinfo || !uioinfo->name || !uioinfo->version) {
dev_err(&pdev->dev, "missing platform_data\n");
goto bad0;
}
if (uioinfo->handler || uioinfo->irqcontrol ||
uioinfo->irq_flags & IRQF_SHARED) {
dev_err(&pdev->dev, "interrupt configuration error\n");
goto bad0;
}
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv) {
ret = -ENOMEM;
dev_err(&pdev->dev, "unable to kmalloc\n");
goto bad0;
}
priv->uioinfo = uioinfo;
spin_lock_init(&priv->lock);
priv->flags = 0;
priv->pdev = pdev;
if (!uioinfo->irq) {
ret = platform_get_irq(pdev, 0);
if (ret < 0) {
dev_err(&pdev->dev, "failed to get IRQ\n");
goto bad0;
}
uioinfo->irq = ret;
}
uiomem = &uioinfo->mem[0];
for (i = 0; i < pdev->num_resources; ++i) {
struct resource *r = &pdev->resource[i];
if (r->flags != IORESOURCE_MEM)
continue;
if (uiomem >= &uioinfo->mem[MAX_UIO_MAPS]) {
dev_warn(&pdev->dev, "device has more than "
__stringify(MAX_UIO_MAPS)
" I/O memory resources.\n");
break;
}
uiomem->memtype = UIO_MEM_PHYS;
uiomem->addr = r->start;
uiomem->size = resource_size(r);
++uiomem;
}
while (uiomem < &uioinfo->mem[MAX_UIO_MAPS]) {
uiomem->size = 0;
++uiomem;
}
uioinfo->handler = uio_pdrv_genirq_handler;
uioinfo->irqcontrol = uio_pdrv_genirq_irqcontrol;
uioinfo->open = uio_pdrv_genirq_open;
uioinfo->release = uio_pdrv_genirq_release;
uioinfo->priv = priv;
pm_runtime_enable(&pdev->dev);
ret = uio_register_device(&pdev->dev, priv->uioinfo);
if (ret) {
dev_err(&pdev->dev, "unable to register uio device\n");
goto bad1;
}
platform_set_drvdata(pdev, priv);
return 0;
bad1:
kfree(priv);
pm_runtime_disable(&pdev->dev);
bad0:
if (pdev->dev.of_node)
kfree(uioinfo);
bad2:
return ret;
}
static int uio_pdrv_genirq_remove(struct platform_device *pdev)
{
struct uio_pdrv_genirq_platdata *priv = platform_get_drvdata(pdev);
uio_unregister_device(priv->uioinfo);
pm_runtime_disable(&pdev->dev);
priv->uioinfo->handler = NULL;
priv->uioinfo->irqcontrol = NULL;
if (pdev->dev.of_node)
kfree(priv->uioinfo);
kfree(priv);
return 0;
}
static int uio_pdrv_genirq_runtime_nop(struct device *dev)
{
return 0;
}
