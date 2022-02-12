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
static void xilly_dma_sync_single_nop(struct xilly_endpoint *ep,
dma_addr_t dma_handle,
size_t size,
int direction)
{
}
static void xilly_of_unmap(void *ptr)
{
struct xilly_mapping *data = ptr;
dma_unmap_single(data->device, data->dma_addr,
data->size, data->direction);
kfree(ptr);
}
static int xilly_map_single_of(struct xilly_endpoint *ep,
void *ptr,
size_t size,
int direction,
dma_addr_t *ret_dma_handle
)
{
dma_addr_t addr;
struct xilly_mapping *this;
int rc;
this = kzalloc(sizeof(*this), GFP_KERNEL);
if (!this)
return -ENOMEM;
addr = dma_map_single(ep->dev, ptr, size, direction);
if (dma_mapping_error(ep->dev, addr)) {
kfree(this);
return -ENODEV;
}
this->device = ep->dev;
this->dma_addr = addr;
this->size = size;
this->direction = direction;
*ret_dma_handle = addr;
rc = devm_add_action(ep->dev, xilly_of_unmap, this);
if (rc) {
dma_unmap_single(ep->dev, addr, size, direction);
kfree(this);
return rc;
}
return 0;
}
static int xilly_drv_probe(struct platform_device *op)
{
struct device *dev = &op->dev;
struct xilly_endpoint *endpoint;
int rc;
int irq;
struct resource res;
struct xilly_endpoint_hardware *ephw = &of_hw;
if (of_property_read_bool(dev->of_node, "dma-coherent"))
ephw = &of_hw_coherent;
endpoint = xillybus_init_endpoint(NULL, dev, ephw);
if (!endpoint)
return -ENOMEM;
dev_set_drvdata(dev, endpoint);
rc = of_address_to_resource(dev->of_node, 0, &res);
endpoint->registers = devm_ioremap_resource(dev, &res);
if (IS_ERR(endpoint->registers))
return PTR_ERR(endpoint->registers);
irq = irq_of_parse_and_map(dev->of_node, 0);
rc = devm_request_irq(dev, irq, xillybus_isr, 0, xillyname, endpoint);
if (rc) {
dev_err(endpoint->dev,
"Failed to register IRQ handler. Aborting.\n");
return -ENODEV;
}
return xillybus_endpoint_discovery(endpoint);
}
static int xilly_drv_remove(struct platform_device *op)
{
struct device *dev = &op->dev;
struct xilly_endpoint *endpoint = dev_get_drvdata(dev);
xillybus_endpoint_remove(endpoint);
return 0;
}
