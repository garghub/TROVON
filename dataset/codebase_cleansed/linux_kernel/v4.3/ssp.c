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
struct ssp_device *pxa_ssp_request_of(const struct device_node *of_node,
const char *label)
{
struct ssp_device *ssp = NULL;
mutex_lock(&ssp_lock);
list_for_each_entry(ssp, &ssp_list, node) {
if (ssp->of_node == of_node && ssp->use_count == 0) {
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
struct resource *res;
struct ssp_device *ssp;
struct device *dev = &pdev->dev;
ssp = devm_kzalloc(dev, sizeof(struct ssp_device), GFP_KERNEL);
if (ssp == NULL)
return -ENOMEM;
ssp->pdev = pdev;
ssp->clk = devm_clk_get(dev, NULL);
if (IS_ERR(ssp->clk))
return PTR_ERR(ssp->clk);
if (dev->of_node) {
struct of_phandle_args dma_spec;
struct device_node *np = dev->of_node;
int ret;
ret = of_parse_phandle_with_args(np, "dmas", "#dma-cells",
0, &dma_spec);
if (ret) {
dev_err(dev, "Can't parse dmas property\n");
return -ENODEV;
}
ssp->drcmr_rx = dma_spec.args[0];
of_node_put(dma_spec.np);
ret = of_parse_phandle_with_args(np, "dmas", "#dma-cells",
1, &dma_spec);
if (ret) {
dev_err(dev, "Can't parse dmas property\n");
return -ENODEV;
}
ssp->drcmr_tx = dma_spec.args[0];
of_node_put(dma_spec.np);
} else {
res = platform_get_resource(pdev, IORESOURCE_DMA, 0);
if (res == NULL) {
dev_err(dev, "no SSP RX DRCMR defined\n");
return -ENODEV;
}
ssp->drcmr_rx = res->start;
res = platform_get_resource(pdev, IORESOURCE_DMA, 1);
if (res == NULL) {
dev_err(dev, "no SSP TX DRCMR defined\n");
return -ENODEV;
}
ssp->drcmr_tx = res->start;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res == NULL) {
dev_err(dev, "no memory resource defined\n");
return -ENODEV;
}
res = devm_request_mem_region(dev, res->start, resource_size(res),
pdev->name);
if (res == NULL) {
dev_err(dev, "failed to request memory resource\n");
return -EBUSY;
}
ssp->phys_base = res->start;
ssp->mmio_base = devm_ioremap(dev, res->start, resource_size(res));
if (ssp->mmio_base == NULL) {
dev_err(dev, "failed to ioremap() registers\n");
return -ENODEV;
}
ssp->irq = platform_get_irq(pdev, 0);
if (ssp->irq < 0) {
dev_err(dev, "no IRQ resource defined\n");
return -ENODEV;
}
if (dev->of_node) {
const struct of_device_id *id =
of_match_device(of_match_ptr(pxa_ssp_of_ids), dev);
ssp->type = (int) id->data;
} else {
const struct platform_device_id *id =
platform_get_device_id(pdev);
ssp->type = (int) id->driver_data;
ssp->port_id = pdev->id + 1;
}
ssp->use_count = 0;
ssp->of_node = dev->of_node;
mutex_lock(&ssp_lock);
list_add(&ssp->node, &ssp_list);
mutex_unlock(&ssp_lock);
platform_set_drvdata(pdev, ssp);
return 0;
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
