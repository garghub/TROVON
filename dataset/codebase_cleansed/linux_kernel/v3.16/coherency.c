int set_cpu_coherent(void)
{
if (!coherency_base) {
pr_warn("Can't make current CPU cache coherent.\n");
pr_warn("Coherency fabric is not initialized\n");
return 1;
}
ll_add_cpu_to_smp_group();
return ll_enable_coherency();
}
static inline void mvebu_hwcc_armada375_sync_io_barrier_wa(void)
{
int idx = smp_processor_id();
writel(0x1, coherency_wa_buf[idx]);
while ((readl(xor_base + XOR_ACTIVATION(idx)) >> 4) & 0x3)
;
dmb();
writel(0x1, xor_base + XOR_ACTIVATION(idx));
while (readl(coherency_wa_buf[idx]))
;
}
static void __init armada_375_coherency_init_wa(void)
{
const struct mbus_dram_target_info *dram;
struct device_node *xor_node;
struct property *xor_status;
struct clk *xor_clk;
u32 win_enable = 0;
int i;
pr_warn("enabling coherency workaround for Armada 375 Z1, one XOR engine disabled\n");
xor_node = of_find_compatible_node(NULL, NULL, "marvell,orion-xor");
BUG_ON(!xor_node);
xor_status = kzalloc(sizeof(struct property), GFP_KERNEL);
BUG_ON(!xor_status);
xor_status->value = kstrdup("disabled", GFP_KERNEL);
BUG_ON(!xor_status->value);
xor_status->length = 8;
xor_status->name = kstrdup("status", GFP_KERNEL);
BUG_ON(!xor_status->name);
of_update_property(xor_node, xor_status);
xor_base = of_iomap(xor_node, 0);
xor_high_base = of_iomap(xor_node, 1);
xor_clk = of_clk_get_by_name(xor_node, NULL);
BUG_ON(!xor_clk);
clk_prepare_enable(xor_clk);
dram = mv_mbus_dram_info();
for (i = 0; i < 8; i++) {
writel(0, xor_base + WINDOW_BASE(i));
writel(0, xor_base + WINDOW_SIZE(i));
if (i < 4)
writel(0, xor_base + WINDOW_REMAP_HIGH(i));
}
for (i = 0; i < dram->num_cs; i++) {
const struct mbus_dram_window *cs = dram->cs + i;
writel((cs->base & 0xffff0000) |
(cs->mbus_attr << 8) |
dram->mbus_dram_target_id, xor_base + WINDOW_BASE(i));
writel((cs->size - 1) & 0xffff0000, xor_base + WINDOW_SIZE(i));
win_enable |= (1 << i);
win_enable |= 3 << (16 + (2 * i));
}
writel(win_enable, xor_base + WINDOW_BAR_ENABLE(0));
writel(win_enable, xor_base + WINDOW_BAR_ENABLE(1));
writel(0, xor_base + WINDOW_OVERRIDE_CTRL(0));
writel(0, xor_base + WINDOW_OVERRIDE_CTRL(1));
for (i = 0; i < CONFIG_NR_CPUS; i++) {
coherency_wa_buf[i] = kzalloc(PAGE_SIZE, GFP_KERNEL);
BUG_ON(!coherency_wa_buf[i]);
coherency_wa_buf_phys[i] =
virt_to_phys(coherency_wa_buf[i]);
BUG_ON(!coherency_wa_buf_phys[i]);
writel(0x444, xor_base + XOR_CONFIG(i));
writel(128, xor_base + XOR_BLOCK_SIZE(i));
writel(coherency_wa_buf_phys[i],
xor_base + XOR_DEST_POINTER(i));
}
writel(0x0, xor_base + XOR_INIT_VALUE_LOW);
writel(0x0, xor_base + XOR_INIT_VALUE_HIGH);
coherency_wa_enabled = true;
}
static inline void mvebu_hwcc_sync_io_barrier(void)
{
if (coherency_wa_enabled) {
mvebu_hwcc_armada375_sync_io_barrier_wa();
return;
}
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
static int mvebu_hwcc_notifier(struct notifier_block *nb,
unsigned long event, void *__dev)
{
struct device *dev = __dev;
if (event != BUS_NOTIFY_ADD_DEVICE)
return NOTIFY_DONE;
set_dma_ops(dev, &mvebu_hwcc_dma_ops);
return NOTIFY_OK;
}
static void __init armada_370_coherency_init(struct device_node *np)
{
struct resource res;
of_address_to_resource(np, 0, &res);
coherency_phys_base = res.start;
sync_cache_w(&coherency_phys_base);
coherency_base = of_iomap(np, 0);
coherency_cpu_base = of_iomap(np, 1);
set_cpu_coherent();
}
static void __iomem *
armada_pcie_wa_ioremap_caller(phys_addr_t phys_addr, size_t size,
unsigned int mtype, void *caller)
{
struct resource pcie_mem;
mvebu_mbus_get_pcie_mem_aperture(&pcie_mem);
if (pcie_mem.start <= phys_addr && (phys_addr + size) <= pcie_mem.end)
mtype = MT_UNCACHED;
return __arm_ioremap_caller(phys_addr, size, mtype, caller);
}
static void __init armada_375_380_coherency_init(struct device_node *np)
{
struct device_node *cache_dn;
coherency_cpu_base = of_iomap(np, 0);
arch_ioremap_caller = armada_pcie_wa_ioremap_caller;
for_each_compatible_node(cache_dn, NULL, "arm,pl310-cache") {
struct property *p;
p = kzalloc(sizeof(*p), GFP_KERNEL);
p->name = kstrdup("arm,io-coherent", GFP_KERNEL);
of_add_property(cache_dn, p);
}
}
static int coherency_type(void)
{
struct device_node *np;
const struct of_device_id *match;
np = of_find_matching_node_and_match(NULL, of_coherency_table, &match);
if (np) {
int type = (int) match->data;
if (type == COHERENCY_FABRIC_TYPE_ARMADA_370_XP)
return type;
else if (type == COHERENCY_FABRIC_TYPE_ARMADA_375 && is_smp())
return type;
else if (type == COHERENCY_FABRIC_TYPE_ARMADA_380 && is_smp())
return type;
}
return COHERENCY_FABRIC_TYPE_NONE;
}
int coherency_available(void)
{
return coherency_type() != COHERENCY_FABRIC_TYPE_NONE;
}
int __init coherency_init(void)
{
int type = coherency_type();
struct device_node *np;
np = of_find_matching_node(NULL, of_coherency_table);
if (type == COHERENCY_FABRIC_TYPE_ARMADA_370_XP)
armada_370_coherency_init(np);
else if (type == COHERENCY_FABRIC_TYPE_ARMADA_375 ||
type == COHERENCY_FABRIC_TYPE_ARMADA_380)
armada_375_380_coherency_init(np);
return 0;
}
static int __init coherency_late_init(void)
{
int type = coherency_type();
if (type == COHERENCY_FABRIC_TYPE_NONE)
return 0;
if (type == COHERENCY_FABRIC_TYPE_ARMADA_375) {
u32 dev, rev;
if (mvebu_get_soc_id(&dev, &rev) == 0 &&
rev == ARMADA_375_Z1_REV)
armada_375_coherency_init_wa();
}
bus_register_notifier(&platform_bus_type,
&mvebu_hwcc_nb);
return 0;
}
static int __init coherency_pci_init(void)
{
if (coherency_available())
bus_register_notifier(&pci_bus_type,
&mvebu_hwcc_pci_nb);
return 0;
}
