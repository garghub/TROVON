static int __init find_dma_window(u64 *io_space_id, u64 *ioid,
u64 *base, u64 *size, u64 *io_page_size)
{
struct device_node *dn;
const unsigned long *dma_window;
for_each_node_by_type(dn, "ioif") {
dma_window = of_get_property(dn, "toshiba,dma-window", NULL);
if (dma_window) {
*io_space_id = (dma_window[0] >> 32) & 0xffffffffUL;
*ioid = dma_window[0] & 0x7ffUL;
*base = dma_window[1];
*size = dma_window[2];
*io_page_size = 1 << dma_window[3];
of_node_put(dn);
return 1;
}
}
return 0;
}
static void __init celleb_init_direct_mapping(void)
{
u64 lpar_addr, io_addr;
u64 io_space_id, ioid, dma_base, dma_size, io_page_size;
if (!find_dma_window(&io_space_id, &ioid, &dma_base, &dma_size,
&io_page_size)) {
pr_info("No dma window found !\n");
return;
}
for (lpar_addr = 0; lpar_addr < dma_size; lpar_addr += io_page_size) {
io_addr = lpar_addr + dma_base;
(void)beat_put_iopte(io_space_id, io_addr, lpar_addr,
ioid, DMA_FLAGS);
}
celleb_dma_direct_offset = dma_base;
}
static void celleb_dma_dev_setup(struct device *dev)
{
set_dma_ops(dev, &dma_direct_ops);
set_dma_offset(dev, celleb_dma_direct_offset);
}
static void celleb_pci_dma_dev_setup(struct pci_dev *pdev)
{
celleb_dma_dev_setup(&pdev->dev);
}
static int celleb_of_bus_notify(struct notifier_block *nb,
unsigned long action, void *data)
{
struct device *dev = data;
if (action != BUS_NOTIFY_ADD_DEVICE)
return 0;
celleb_dma_dev_setup(dev);
return 0;
}
static int __init celleb_init_iommu(void)
{
celleb_init_direct_mapping();
ppc_md.pci_dma_dev_setup = celleb_pci_dma_dev_setup;
bus_register_notifier(&platform_bus_type, &celleb_of_bus_notifier);
return 0;
}
