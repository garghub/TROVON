static int mvebu_hwcc_notifier(struct notifier_block *nb,
unsigned long event, void *__dev)
{
struct device *dev = __dev;
if (event != BUS_NOTIFY_ADD_DEVICE)
return NOTIFY_DONE;
set_dma_ops(dev, &arm_coherent_dma_ops);
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
if (!coherency_available())
return;
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
int type;
if (!is_smp())
return COHERENCY_FABRIC_TYPE_NONE;
np = of_find_matching_node_and_match(NULL, of_coherency_table, &match);
if (!np)
return COHERENCY_FABRIC_TYPE_NONE;
type = (int) match->data;
of_node_put(np);
return type;
}
int set_cpu_coherent(void)
{
int type = coherency_type();
if (type == COHERENCY_FABRIC_TYPE_ARMADA_370_XP) {
if (!coherency_base) {
pr_warn("Can't make current CPU cache coherent.\n");
pr_warn("Coherency fabric is not initialized\n");
return 1;
}
ll_add_cpu_to_smp_group();
return ll_enable_coherency();
}
return 0;
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
of_node_put(np);
return 0;
}
static int __init coherency_late_init(void)
{
if (coherency_available())
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
