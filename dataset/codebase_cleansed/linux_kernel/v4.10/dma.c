static dma_addr_t bmips_phys_to_dma(struct device *dev, phys_addr_t pa)
{
struct bmips_dma_range *r;
for (r = bmips_dma_ranges; r && r->size; r++) {
if (pa >= r->child_addr &&
pa < (r->child_addr + r->size))
return pa - r->child_addr + r->parent_addr;
}
return pa;
}
dma_addr_t plat_map_dma_mem(struct device *dev, void *addr, size_t size)
{
return bmips_phys_to_dma(dev, virt_to_phys(addr));
}
dma_addr_t plat_map_dma_mem_page(struct device *dev, struct page *page)
{
return bmips_phys_to_dma(dev, page_to_phys(page));
}
unsigned long plat_dma_addr_to_phys(struct device *dev, dma_addr_t dma_addr)
{
struct bmips_dma_range *r;
for (r = bmips_dma_ranges; r && r->size; r++) {
if (dma_addr >= r->parent_addr &&
dma_addr < (r->parent_addr + r->size))
return dma_addr - r->parent_addr + r->child_addr;
}
return dma_addr;
}
static int __init bmips_init_dma_ranges(void)
{
struct device_node *np =
of_find_compatible_node(NULL, NULL, "brcm,ubus");
const __be32 *data;
struct bmips_dma_range *r;
int len;
if (!np)
return 0;
data = of_get_property(np, "dma-ranges", &len);
if (!data)
goto out_good;
len /= sizeof(*data) * 3;
if (!len)
goto out_bad;
bmips_dma_ranges = kzalloc(sizeof(struct bmips_dma_range) * (len + 1),
GFP_KERNEL);
if (!bmips_dma_ranges)
goto out_bad;
for (r = bmips_dma_ranges; len; len--, r++) {
r->child_addr = be32_to_cpup(data++);
r->parent_addr = be32_to_cpup(data++);
r->size = be32_to_cpup(data++);
}
out_good:
of_node_put(np);
return 0;
out_bad:
pr_err("error parsing dma-ranges property\n");
of_node_put(np);
return -EINVAL;
}
