static void xilly_dma_sync_single_for_cpu_of(struct xilly_endpoint *ep,
dma_addr_t dma_handle,
size_t size,
int direction)
{
dma_sync_single_for_cpu(ep->dev, dma_handle, size, direction);
}
static void xilly_dma_sync_single_for_device_of(struct xilly_endpoint *ep,
dma_addr_t dma_handle,
size_t size,
int direction)
{
dma_sync_single_for_device(ep->dev, dma_handle, size, direction);
}
static dma_addr_t xilly_map_single_of(struct xilly_cleanup *mem,
struct xilly_endpoint *ep,
void *ptr,
size_t size,
int direction
)
{
dma_addr_t addr = 0;
struct xilly_dma *this;
this = kmalloc(sizeof(struct xilly_dma), GFP_KERNEL);
if (!this)
return 0;
addr = dma_map_single(ep->dev, ptr, size, direction);
this->direction = direction;
if (dma_mapping_error(ep->dev, addr)) {
kfree(this);
return 0;
}
this->dma_addr = addr;
this->dev = ep->dev;
this->size = size;
list_add_tail(&this->node, &mem->to_unmap);
return addr;
}
static void xilly_unmap_single_of(struct xilly_dma *entry)
{
dma_unmap_single(entry->dev,
entry->dma_addr,
entry->size,
entry->direction);
}
static int xilly_drv_probe(struct platform_device *op)
{
struct device *dev = &op->dev;
struct xilly_endpoint *endpoint;
int rc = 0;
int irq;
endpoint = xillybus_init_endpoint(NULL, dev, &of_hw);
if (!endpoint)
return -ENOMEM;
dev_set_drvdata(dev, endpoint);
rc = of_address_to_resource(dev->of_node, 0, &endpoint->res);
if (rc) {
pr_warn("xillybus: Failed to obtain device tree "
"resource\n");
goto failed_request_regions;
}
if (!request_mem_region(endpoint->res.start,
resource_size(&endpoint->res), xillyname)) {
pr_err("xillybus: request_mem_region failed. Aborting.\n");
rc = -EBUSY;
goto failed_request_regions;
}
endpoint->registers = of_iomap(dev->of_node, 0);
if (!endpoint->registers) {
pr_err("xillybus: Failed to map I/O memory. Aborting.\n");
goto failed_iomap0;
}
irq = irq_of_parse_and_map(dev->of_node, 0);
rc = request_irq(irq, xillybus_isr, 0, xillyname, endpoint);
if (rc) {
pr_err("xillybus: Failed to register IRQ handler. "
"Aborting.\n");
rc = -ENODEV;
goto failed_register_irq;
}
rc = xillybus_endpoint_discovery(endpoint);
if (!rc)
return 0;
free_irq(irq, endpoint);
failed_register_irq:
iounmap(endpoint->registers);
failed_iomap0:
release_mem_region(endpoint->res.start,
resource_size(&endpoint->res));
failed_request_regions:
xillybus_do_cleanup(&endpoint->cleanup, endpoint);
kfree(endpoint);
return rc;
}
static int xilly_drv_remove(struct platform_device *op)
{
struct device *dev = &op->dev;
struct xilly_endpoint *endpoint = dev_get_drvdata(dev);
int irq = irq_of_parse_and_map(dev->of_node, 0);
xillybus_endpoint_remove(endpoint);
free_irq(irq, endpoint);
iounmap(endpoint->registers);
release_mem_region(endpoint->res.start,
resource_size(&endpoint->res));
xillybus_do_cleanup(&endpoint->cleanup, endpoint);
kfree(endpoint);
return 0;
}
static int __init xillybus_of_init(void)
{
return platform_driver_register(&xillybus_platform_driver);
}
static void __exit xillybus_of_exit(void)
{
platform_driver_unregister(&xillybus_platform_driver);
}
