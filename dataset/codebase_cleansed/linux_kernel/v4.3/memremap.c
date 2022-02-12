__weak void __iomem *ioremap_cache(resource_size_t offset, unsigned long size)
{
return ioremap(offset, size);
}
static void *try_ram_remap(resource_size_t offset, size_t size)
{
struct page *page = pfn_to_page(offset >> PAGE_SHIFT);
if (!PageHighMem(page))
return __va(offset);
return NULL;
}
void *memremap(resource_size_t offset, size_t size, unsigned long flags)
{
int is_ram = region_intersects(offset, size, "System RAM");
void *addr = NULL;
if (is_ram == REGION_MIXED) {
WARN_ONCE(1, "memremap attempted on mixed range %pa size: %#lx\n",
&offset, (unsigned long) size);
return NULL;
}
if (flags & MEMREMAP_WB) {
flags &= ~MEMREMAP_WB;
if (is_ram == REGION_INTERSECTS)
addr = try_ram_remap(offset, size);
if (!addr)
addr = ioremap_cache(offset, size);
}
if (!addr && is_ram == REGION_INTERSECTS && flags) {
WARN_ONCE(1, "memremap attempted on ram %pa size: %#lx\n",
&offset, (unsigned long) size);
return NULL;
}
if (!addr && (flags & MEMREMAP_WT)) {
flags &= ~MEMREMAP_WT;
addr = ioremap_wt(offset, size);
}
return addr;
}
void memunmap(void *addr)
{
if (is_vmalloc_addr(addr))
iounmap((void __iomem *) addr);
}
static void devm_memremap_release(struct device *dev, void *res)
{
memunmap(res);
}
static int devm_memremap_match(struct device *dev, void *res, void *match_data)
{
return *(void **)res == match_data;
}
void *devm_memremap(struct device *dev, resource_size_t offset,
size_t size, unsigned long flags)
{
void **ptr, *addr;
ptr = devres_alloc(devm_memremap_release, sizeof(*ptr), GFP_KERNEL);
if (!ptr)
return NULL;
addr = memremap(offset, size, flags);
if (addr) {
*ptr = addr;
devres_add(dev, ptr);
} else
devres_free(ptr);
return addr;
}
void devm_memunmap(struct device *dev, void *addr)
{
WARN_ON(devres_destroy(dev, devm_memremap_release, devm_memremap_match,
addr));
memunmap(addr);
}
static void devm_memremap_pages_release(struct device *dev, void *res)
{
struct page_map *page_map = res;
arch_remove_memory(page_map->res.start, resource_size(&page_map->res));
}
void *devm_memremap_pages(struct device *dev, struct resource *res)
{
int is_ram = region_intersects(res->start, resource_size(res),
"System RAM");
struct page_map *page_map;
int error, nid;
if (is_ram == REGION_MIXED) {
WARN_ONCE(1, "%s attempted on mixed region %pr\n",
__func__, res);
return ERR_PTR(-ENXIO);
}
if (is_ram == REGION_INTERSECTS)
return __va(res->start);
page_map = devres_alloc(devm_memremap_pages_release,
sizeof(*page_map), GFP_KERNEL);
if (!page_map)
return ERR_PTR(-ENOMEM);
memcpy(&page_map->res, res, sizeof(*res));
nid = dev_to_node(dev);
if (nid < 0)
nid = 0;
error = arch_add_memory(nid, res->start, resource_size(res), true);
if (error) {
devres_free(page_map);
return ERR_PTR(error);
}
devres_add(dev, page_map);
return __va(res->start);
}
