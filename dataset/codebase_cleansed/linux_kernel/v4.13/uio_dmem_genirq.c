static int uio_dmem_genirq_open(struct uio_info *info, struct inode *inode)
{
struct uio_dmem_genirq_platdata *priv = info->priv;
struct uio_mem *uiomem;
int ret = 0;
int dmem_region = priv->dmem_region_start;
uiomem = &priv->uioinfo->mem[priv->dmem_region_start];
mutex_lock(&priv->alloc_lock);
while (!priv->refcnt && uiomem < &priv->uioinfo->mem[MAX_UIO_MAPS]) {
void *addr;
if (!uiomem->size)
break;
addr = dma_alloc_coherent(&priv->pdev->dev, uiomem->size,
(dma_addr_t *)&uiomem->addr, GFP_KERNEL);
if (!addr) {
uiomem->addr = DMEM_MAP_ERROR;
}
priv->dmem_region_vaddr[dmem_region++] = addr;
++uiomem;
}
priv->refcnt++;
mutex_unlock(&priv->alloc_lock);
pm_runtime_get_sync(&priv->pdev->dev);
return ret;
}
static int uio_dmem_genirq_release(struct uio_info *info, struct inode *inode)
{
struct uio_dmem_genirq_platdata *priv = info->priv;
struct uio_mem *uiomem;
int dmem_region = priv->dmem_region_start;
pm_runtime_put_sync(&priv->pdev->dev);
uiomem = &priv->uioinfo->mem[priv->dmem_region_start];
mutex_lock(&priv->alloc_lock);
priv->refcnt--;
while (!priv->refcnt && uiomem < &priv->uioinfo->mem[MAX_UIO_MAPS]) {
if (!uiomem->size)
break;
if (priv->dmem_region_vaddr[dmem_region]) {
dma_free_coherent(&priv->pdev->dev, uiomem->size,
priv->dmem_region_vaddr[dmem_region],
uiomem->addr);
}
uiomem->addr = DMEM_MAP_ERROR;
++dmem_region;
++uiomem;
}
mutex_unlock(&priv->alloc_lock);
return 0;
}
static irqreturn_t uio_dmem_genirq_handler(int irq, struct uio_info *dev_info)
{
struct uio_dmem_genirq_platdata *priv = dev_info->priv;
if (!test_and_set_bit(0, &priv->flags))
disable_irq_nosync(irq);
return IRQ_HANDLED;
}
static int uio_dmem_genirq_irqcontrol(struct uio_info *dev_info, s32 irq_on)
{
struct uio_dmem_genirq_platdata *priv = dev_info->priv;
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
static int uio_dmem_genirq_probe(struct platform_device *pdev)
{
struct uio_dmem_genirq_pdata *pdata = dev_get_platdata(&pdev->dev);
struct uio_info *uioinfo = &pdata->uioinfo;
struct uio_dmem_genirq_platdata *priv;
struct uio_mem *uiomem;
int ret = -EINVAL;
int i;
if (pdev->dev.of_node) {
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
dma_set_coherent_mask(&pdev->dev, DMA_BIT_MASK(32));
priv->uioinfo = uioinfo;
spin_lock_init(&priv->lock);
priv->flags = 0;
priv->pdev = pdev;
mutex_init(&priv->alloc_lock);
if (!uioinfo->irq) {
ret = platform_get_irq(pdev, 0);
if (ret < 0) {
dev_err(&pdev->dev, "failed to get IRQ\n");
goto bad1;
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
priv->dmem_region_start = uiomem - &uioinfo->mem[0];
priv->num_dmem_regions = pdata->num_dynamic_regions;
for (i = 0; i < pdata->num_dynamic_regions; ++i) {
if (uiomem >= &uioinfo->mem[MAX_UIO_MAPS]) {
dev_warn(&pdev->dev, "device has more than "
__stringify(MAX_UIO_MAPS)
" dynamic and fixed memory regions.\n");
break;
}
uiomem->memtype = UIO_MEM_PHYS;
uiomem->addr = DMEM_MAP_ERROR;
uiomem->size = pdata->dynamic_region_sizes[i];
++uiomem;
}
while (uiomem < &uioinfo->mem[MAX_UIO_MAPS]) {
uiomem->size = 0;
++uiomem;
}
uioinfo->handler = uio_dmem_genirq_handler;
uioinfo->irqcontrol = uio_dmem_genirq_irqcontrol;
uioinfo->open = uio_dmem_genirq_open;
uioinfo->release = uio_dmem_genirq_release;
uioinfo->priv = priv;
pm_runtime_enable(&pdev->dev);
ret = uio_register_device(&pdev->dev, priv->uioinfo);
if (ret) {
dev_err(&pdev->dev, "unable to register uio device\n");
pm_runtime_disable(&pdev->dev);
goto bad1;
}
platform_set_drvdata(pdev, priv);
return 0;
bad1:
kfree(priv);
bad0:
if (pdev->dev.of_node)
kfree(uioinfo);
bad2:
return ret;
}
static int uio_dmem_genirq_remove(struct platform_device *pdev)
{
struct uio_dmem_genirq_platdata *priv = platform_get_drvdata(pdev);
uio_unregister_device(priv->uioinfo);
pm_runtime_disable(&pdev->dev);
priv->uioinfo->handler = NULL;
priv->uioinfo->irqcontrol = NULL;
if (pdev->dev.of_node)
kfree(priv->uioinfo);
kfree(priv);
return 0;
}
static int uio_dmem_genirq_runtime_nop(struct device *dev)
{
return 0;
}
