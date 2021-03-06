struct platform_device *__init imx_add_ipu_core(
const struct imx_ipu_core_data *data)
{
struct resource res[] = {
{
.start = data->iobase,
.end = data->iobase + 0x5f,
.flags = IORESOURCE_MEM,
}, {
.start = data->iobase + 0x88,
.end = data->iobase + 0xb3,
.flags = IORESOURCE_MEM,
}, {
.start = data->synirq,
.end = data->synirq,
.flags = IORESOURCE_IRQ,
}, {
.start = data->errirq,
.end = data->errirq,
.flags = IORESOURCE_IRQ,
},
};
return imx_ipu_coredev = imx_add_platform_device("ipu-core", -1,
res, ARRAY_SIZE(res), NULL, 0);
}
struct platform_device *__init imx_alloc_mx3_camera(
const struct imx_ipu_core_data *data,
const struct mx3_camera_pdata *pdata)
{
struct resource res[] = {
{
.start = data->iobase + 0x60,
.end = data->iobase + 0x87,
.flags = IORESOURCE_MEM,
},
};
int ret = -ENOMEM;
struct platform_device *pdev;
if (IS_ERR_OR_NULL(imx_ipu_coredev))
return ERR_PTR(-ENODEV);
pdev = platform_device_alloc("mx3-camera", 0);
if (!pdev)
return ERR_PTR(-ENOMEM);
pdev->dev.dma_mask = kmalloc(sizeof(*pdev->dev.dma_mask), GFP_KERNEL);
if (!pdev->dev.dma_mask)
goto err;
*pdev->dev.dma_mask = DMA_BIT_MASK(32);
pdev->dev.coherent_dma_mask = DMA_BIT_MASK(32);
ret = platform_device_add_resources(pdev, res, ARRAY_SIZE(res));
if (ret)
goto err;
if (pdata) {
struct mx3_camera_pdata *copied_pdata;
ret = platform_device_add_data(pdev, pdata, sizeof(*pdata));
if (ret) {
err:
kfree(pdev->dev.dma_mask);
platform_device_put(pdev);
return ERR_PTR(-ENODEV);
}
copied_pdata = dev_get_platdata(&pdev->dev);
copied_pdata->dma_dev = &imx_ipu_coredev->dev;
}
return pdev;
}
struct platform_device *__init imx_add_mx3_sdc_fb(
const struct imx_ipu_core_data *data,
struct mx3fb_platform_data *pdata)
{
struct resource res[] = {
{
.start = data->iobase + 0xb4,
.end = data->iobase + 0x1bf,
.flags = IORESOURCE_MEM,
},
};
if (IS_ERR_OR_NULL(imx_ipu_coredev))
return ERR_PTR(-ENODEV);
pdata->dma_dev = &imx_ipu_coredev->dev;
return imx_add_platform_device_dmamask("mx3_sdc_fb", -1,
res, ARRAY_SIZE(res), pdata, sizeof(*pdata),
DMA_BIT_MASK(32));
}
