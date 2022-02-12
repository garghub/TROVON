void pci_dma_dev_setup_swiotlb(struct pci_dev *pdev)
{
struct pci_controller *hose;
struct dev_archdata *sd;
hose = pci_bus_to_host(pdev->bus);
sd = &pdev->dev.archdata;
sd->max_direct_dma_addr =
hose->dma_window_base_cur + hose->dma_window_size;
}
static int ppc_swiotlb_bus_notify(struct notifier_block *nb,
unsigned long action, void *data)
{
struct device *dev = data;
struct dev_archdata *sd;
if (action != BUS_NOTIFY_ADD_DEVICE)
return 0;
sd = &dev->archdata;
sd->max_direct_dma_addr = 0;
if ((dma_get_mask(dev) + 1) < memblock_end_of_DRAM())
set_dma_ops(dev, &swiotlb_dma_ops);
return NOTIFY_DONE;
}
int __init swiotlb_setup_bus_notifier(void)
{
bus_register_notifier(&platform_bus_type,
&ppc_swiotlb_plat_bus_notifier);
return 0;
}
