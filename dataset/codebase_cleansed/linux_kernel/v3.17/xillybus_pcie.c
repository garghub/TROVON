static int xilly_pci_direction(int direction)
{
switch (direction) {
case DMA_TO_DEVICE:
return PCI_DMA_TODEVICE;
case DMA_FROM_DEVICE:
return PCI_DMA_FROMDEVICE;
default:
return PCI_DMA_BIDIRECTIONAL;
}
}
static void xilly_dma_sync_single_for_cpu_pci(struct xilly_endpoint *ep,
dma_addr_t dma_handle,
size_t size,
int direction)
{
pci_dma_sync_single_for_cpu(ep->pdev,
dma_handle,
size,
xilly_pci_direction(direction));
}
static void xilly_dma_sync_single_for_device_pci(struct xilly_endpoint *ep,
dma_addr_t dma_handle,
size_t size,
int direction)
{
pci_dma_sync_single_for_device(ep->pdev,
dma_handle,
size,
xilly_pci_direction(direction));
}
static void xilly_pci_unmap(void *ptr)
{
struct xilly_mapping *data = ptr;
pci_unmap_single(data->device, data->dma_addr,
data->size, data->direction);
kfree(ptr);
}
static int xilly_map_single_pci(struct xilly_endpoint *ep,
void *ptr,
size_t size,
int direction,
dma_addr_t *ret_dma_handle
)
{
int pci_direction;
dma_addr_t addr;
struct xilly_mapping *this;
int rc = 0;
this = kzalloc(sizeof(*this), GFP_KERNEL);
if (!this)
return -ENOMEM;
pci_direction = xilly_pci_direction(direction);
addr = pci_map_single(ep->pdev, ptr, size, pci_direction);
if (pci_dma_mapping_error(ep->pdev, addr)) {
kfree(this);
return -ENODEV;
}
this->device = ep->pdev;
this->dma_addr = addr;
this->size = size;
this->direction = pci_direction;
*ret_dma_handle = addr;
rc = devm_add_action(ep->dev, xilly_pci_unmap, this);
if (rc) {
pci_unmap_single(ep->pdev, addr, size, pci_direction);
kfree(this);
}
return rc;
}
static int xilly_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct xilly_endpoint *endpoint;
int rc = 0;
endpoint = xillybus_init_endpoint(pdev, &pdev->dev, &pci_hw);
if (!endpoint)
return -ENOMEM;
pci_set_drvdata(pdev, endpoint);
rc = pcim_enable_device(pdev);
if (rc) {
dev_err(endpoint->dev,
"pcim_enable_device() failed. Aborting.\n");
return rc;
}
pci_disable_link_state(pdev, PCIE_LINK_STATE_L0S);
if (!(pci_resource_flags(pdev, 0) & IORESOURCE_MEM)) {
dev_err(endpoint->dev,
"Incorrect BAR configuration. Aborting.\n");
return -ENODEV;
}
rc = pcim_iomap_regions(pdev, 0x01, xillyname);
if (rc) {
dev_err(endpoint->dev,
"pcim_iomap_regions() failed. Aborting.\n");
return rc;
}
endpoint->registers = pcim_iomap_table(pdev)[0];
pci_set_master(pdev);
if (pci_enable_msi(pdev)) {
dev_err(endpoint->dev,
"Failed to enable MSI interrupts. Aborting.\n");
return -ENODEV;
}
rc = devm_request_irq(&pdev->dev, pdev->irq, xillybus_isr, 0,
xillyname, endpoint);
if (rc) {
dev_err(endpoint->dev,
"Failed to register MSI handler. Aborting.\n");
return -ENODEV;
}
if (!pci_set_dma_mask(pdev, DMA_BIT_MASK(32)))
endpoint->dma_using_dac = 0;
else {
dev_err(endpoint->dev, "Failed to set DMA mask. Aborting.\n");
return -ENODEV;
}
return xillybus_endpoint_discovery(endpoint);
}
static void xilly_remove(struct pci_dev *pdev)
{
struct xilly_endpoint *endpoint = pci_get_drvdata(pdev);
xillybus_endpoint_remove(endpoint);
}
