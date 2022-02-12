struct ssp_device *pxa_ssp_request(int port, const char *label)
{
struct ssp_device *ssp = NULL;
mutex_lock(&ssp_lock);
list_for_each_entry(ssp, &ssp_list, node) {
if (ssp->port_id == port && ssp->use_count == 0) {
ssp->use_count++;
ssp->label = label;
break;
}
}
mutex_unlock(&ssp_lock);
if (&ssp->node == &ssp_list)
return NULL;
return ssp;
}
void pxa_ssp_free(struct ssp_device *ssp)
{
mutex_lock(&ssp_lock);
if (ssp->use_count) {
ssp->use_count--;
ssp->label = NULL;
} else
dev_err(&ssp->pdev->dev, "device already free\n");
mutex_unlock(&ssp_lock);
}
static int pxa_ssp_probe(struct platform_device *pdev)
{
const struct platform_device_id *id = platform_get_device_id(pdev);
struct resource *res;
struct ssp_device *ssp;
int ret = 0;
ssp = kzalloc(sizeof(struct ssp_device), GFP_KERNEL);
if (ssp == NULL) {
dev_err(&pdev->dev, "failed to allocate memory");
return -ENOMEM;
}
ssp->pdev = pdev;
ssp->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(ssp->clk)) {
ret = PTR_ERR(ssp->clk);
goto err_free;
}
res = platform_get_resource(pdev, IORESOURCE_DMA, 0);
if (res == NULL) {
dev_err(&pdev->dev, "no SSP RX DRCMR defined\n");
ret = -ENODEV;
goto err_free_clk;
}
ssp->drcmr_rx = res->start;
res = platform_get_resource(pdev, IORESOURCE_DMA, 1);
if (res == NULL) {
dev_err(&pdev->dev, "no SSP TX DRCMR defined\n");
ret = -ENODEV;
goto err_free_clk;
}
ssp->drcmr_tx = res->start;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res == NULL) {
dev_err(&pdev->dev, "no memory resource defined\n");
ret = -ENODEV;
goto err_free_clk;
}
res = request_mem_region(res->start, resource_size(res),
pdev->name);
if (res == NULL) {
dev_err(&pdev->dev, "failed to request memory resource\n");
ret = -EBUSY;
goto err_free_clk;
}
ssp->phys_base = res->start;
ssp->mmio_base = ioremap(res->start, resource_size(res));
if (ssp->mmio_base == NULL) {
dev_err(&pdev->dev, "failed to ioremap() registers\n");
ret = -ENODEV;
goto err_free_mem;
}
ssp->irq = platform_get_irq(pdev, 0);
if (ssp->irq < 0) {
dev_err(&pdev->dev, "no IRQ resource defined\n");
ret = -ENODEV;
goto err_free_io;
}
ssp->port_id = pdev->id + 1;
ssp->use_count = 0;
ssp->type = (int)id->driver_data;
mutex_lock(&ssp_lock);
list_add(&ssp->node, &ssp_list);
mutex_unlock(&ssp_lock);
platform_set_drvdata(pdev, ssp);
return 0;
err_free_io:
iounmap(ssp->mmio_base);
err_free_mem:
release_mem_region(res->start, resource_size(res));
err_free_clk:
clk_put(ssp->clk);
err_free:
kfree(ssp);
return ret;
}
static int pxa_ssp_remove(struct platform_device *pdev)
{
struct resource *res;
struct ssp_device *ssp;
ssp = platform_get_drvdata(pdev);
if (ssp == NULL)
return -ENODEV;
iounmap(ssp->mmio_base);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(res->start, resource_size(res));
clk_put(ssp->clk);
mutex_lock(&ssp_lock);
list_del(&ssp->node);
mutex_unlock(&ssp_lock);
kfree(ssp);
return 0;
}
static int __init pxa_ssp_init(void)
{
return platform_driver_register(&pxa_ssp_driver);
}
static void __exit pxa_ssp_exit(void)
{
platform_driver_unregister(&pxa_ssp_driver);
}
