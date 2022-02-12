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
static dma_addr_t xilly_map_single_pci(struct xilly_cleanup *mem,
struct xilly_endpoint *ep,
void *ptr,
size_t size,
int direction
)
{
dma_addr_t addr = 0;
struct xilly_dma *this;
int pci_direction;
this = kmalloc(sizeof(struct xilly_dma), GFP_KERNEL);
if (!this)
return 0;
pci_direction = xilly_pci_direction(direction);
addr = pci_map_single(ep->pdev, ptr, size, pci_direction);
this->direction = pci_direction;
if (pci_dma_mapping_error(ep->pdev, addr)) {
kfree(this);
return 0;
}
this->dma_addr = addr;
this->pdev = ep->pdev;
this->size = size;
list_add_tail(&this->node, &mem->to_unmap);
return addr;
}
static void xilly_unmap_single_pci(struct xilly_dma *entry)
{
pci_unmap_single(entry->pdev,
entry->dma_addr,
entry->size,
entry->direction);
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
rc = pci_enable_device(pdev);
pci_disable_link_state(pdev, PCIE_LINK_STATE_L0S);
if (rc) {
dev_err(endpoint->dev,
"pci_enable_device() failed. Aborting.\n");
goto no_enable;
}
if (!(pci_resource_flags(pdev, 0) & IORESOURCE_MEM)) {
dev_err(endpoint->dev,
"Incorrect BAR configuration. Aborting.\n");
rc = -ENODEV;
goto bad_bar;
}
rc = pci_request_regions(pdev, xillyname);
if (rc) {
dev_err(endpoint->dev,
"pci_request_regions() failed. Aborting.\n");
goto failed_request_regions;
}
endpoint->registers = pci_iomap(pdev, 0, 128);
if (!endpoint->registers) {
dev_err(endpoint->dev, "Failed to map BAR 0. Aborting.\n");
goto failed_iomap0;
}
pci_set_master(pdev);
if (pci_enable_msi(pdev)) {
dev_err(endpoint->dev,
"Failed to enable MSI interrupts. Aborting.\n");
rc = -ENODEV;
goto failed_enable_msi;
}
rc = request_irq(pdev->irq, xillybus_isr, 0, xillyname, endpoint);
if (rc) {
dev_err(endpoint->dev,
"Failed to register MSI handler. Aborting.\n");
rc = -ENODEV;
goto failed_register_msi;
}
if (!pci_set_dma_mask(pdev, DMA_BIT_MASK(32)))
endpoint->dma_using_dac = 0;
else {
dev_err(endpoint->dev, "Failed to set DMA mask. Aborting.\n");
rc = -ENODEV;
goto failed_dmamask;
}
rc = xillybus_endpoint_discovery(endpoint);
if (!rc)
return 0;
failed_dmamask:
free_irq(pdev->irq, endpoint);
failed_register_msi:
pci_disable_msi(pdev);
failed_enable_msi:
pci_iounmap(pdev, endpoint->registers);
failed_iomap0:
pci_release_regions(pdev);
failed_request_regions:
bad_bar:
pci_disable_device(pdev);
no_enable:
xillybus_do_cleanup(&endpoint->cleanup, endpoint);
kfree(endpoint);
return rc;
}
static void xilly_remove(struct pci_dev *pdev)
{
struct xilly_endpoint *endpoint = pci_get_drvdata(pdev);
xillybus_endpoint_remove(endpoint);
free_irq(pdev->irq, endpoint);
pci_disable_msi(pdev);
pci_iounmap(pdev, endpoint->registers);
pci_release_regions(pdev);
pci_disable_device(pdev);
xillybus_do_cleanup(&endpoint->cleanup, endpoint);
kfree(endpoint);
}
