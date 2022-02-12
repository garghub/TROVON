int set_cpu_coherent(unsigned int hw_cpu_id, int smp_group_id)
{
if (!coherency_base) {
pr_warn("Can't make CPU %d cache coherent.\n", hw_cpu_id);
pr_warn("Coherency fabric is not initialized\n");
return 1;
}
return ll_set_cpu_coherent(coherency_base, hw_cpu_id);
}
static inline void mvebu_hwcc_sync_io_barrier(void)
{
writel(0x1, coherency_cpu_base + IO_SYNC_BARRIER_CTL_OFFSET);
while (readl(coherency_cpu_base + IO_SYNC_BARRIER_CTL_OFFSET) & 0x1);
}
static dma_addr_t mvebu_hwcc_dma_map_page(struct device *dev, struct page *page,
unsigned long offset, size_t size,
enum dma_data_direction dir,
struct dma_attrs *attrs)
{
if (dir != DMA_TO_DEVICE)
mvebu_hwcc_sync_io_barrier();
return pfn_to_dma(dev, page_to_pfn(page)) + offset;
}
static void mvebu_hwcc_dma_unmap_page(struct device *dev, dma_addr_t dma_handle,
size_t size, enum dma_data_direction dir,
struct dma_attrs *attrs)
{
if (dir != DMA_TO_DEVICE)
mvebu_hwcc_sync_io_barrier();
}
static void mvebu_hwcc_dma_sync(struct device *dev, dma_addr_t dma_handle,
size_t size, enum dma_data_direction dir)
{
if (dir != DMA_TO_DEVICE)
mvebu_hwcc_sync_io_barrier();
}
static int mvebu_hwcc_platform_notifier(struct notifier_block *nb,
unsigned long event, void *__dev)
{
struct device *dev = __dev;
if (event != BUS_NOTIFY_ADD_DEVICE)
return NOTIFY_DONE;
set_dma_ops(dev, &mvebu_hwcc_dma_ops);
return NOTIFY_OK;
}
int __init coherency_init(void)
{
struct device_node *np;
np = of_find_matching_node(NULL, of_coherency_table);
if (np) {
struct resource res;
pr_info("Initializing Coherency fabric\n");
of_address_to_resource(np, 0, &res);
coherency_phys_base = res.start;
sync_cache_w(&coherency_phys_base);
coherency_base = of_iomap(np, 0);
coherency_cpu_base = of_iomap(np, 1);
set_cpu_coherent(cpu_logical_map(smp_processor_id()), 0);
of_node_put(np);
}
return 0;
}
static int __init coherency_late_init(void)
{
struct device_node *np;
np = of_find_matching_node(NULL, of_coherency_table);
if (np) {
bus_register_notifier(&platform_bus_type,
&mvebu_hwcc_platform_nb);
of_node_put(np);
}
return 0;
}
