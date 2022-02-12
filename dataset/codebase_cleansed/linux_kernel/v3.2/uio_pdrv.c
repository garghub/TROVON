static int uio_pdrv_probe(struct platform_device *pdev)
{
struct uio_info *uioinfo = pdev->dev.platform_data;
struct uio_platdata *pdata;
struct uio_mem *uiomem;
int ret = -ENODEV;
int i;
if (!uioinfo || !uioinfo->name || !uioinfo->version) {
dev_dbg(&pdev->dev, "%s: err_uioinfo\n", __func__);
goto err_uioinfo;
}
pdata = kzalloc(sizeof(*pdata), GFP_KERNEL);
if (!pdata) {
ret = -ENOMEM;
dev_dbg(&pdev->dev, "%s: err_alloc_pdata\n", __func__);
goto err_alloc_pdata;
}
pdata->uioinfo = uioinfo;
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
pdata->uioinfo->priv = pdata;
ret = uio_register_device(&pdev->dev, pdata->uioinfo);
if (ret) {
kfree(pdata);
err_alloc_pdata:
err_uioinfo:
return ret;
}
platform_set_drvdata(pdev, pdata);
return 0;
}
static int uio_pdrv_remove(struct platform_device *pdev)
{
struct uio_platdata *pdata = platform_get_drvdata(pdev);
uio_unregister_device(pdata->uioinfo);
kfree(pdata);
return 0;
}
static int __init uio_pdrv_init(void)
{
return platform_driver_register(&uio_pdrv);
}
static void __exit uio_pdrv_exit(void)
{
platform_driver_unregister(&uio_pdrv);
}
