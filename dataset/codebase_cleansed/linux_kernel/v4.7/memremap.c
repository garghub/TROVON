__weak void __iomem *ioremap_cache(resource_size_t offset, unsigned long size)
{
return ioremap(offset, size);
}
static void *arch_memremap_wb(resource_size_t offset, unsigned long size)
{
return (__force void *)ioremap_cache(offset, size);
}
static void *try_ram_remap(resource_size_t offset, size_t size)
{
unsigned long pfn = PHYS_PFN(offset);
if (pfn_valid(pfn) && !PageHighMem(pfn_to_page(pfn)))
return __va(offset);
return NULL;
}
void *memremap(resource_size_t offset, size_t size, unsigned long flags)
{
int is_ram = region_intersects(offset, size,
IORESOURCE_SYSTEM_RAM, IORES_DESC_NONE);
void *addr = NULL;
if (!flags)
return NULL;
if (is_ram == REGION_MIXED) {
WARN_ONCE(1, "memremap attempted on mixed range %pa size: %#lx\n",
&offset, (unsigned long) size);
return NULL;
}
if (flags & MEMREMAP_WB) {
if (is_ram == REGION_INTERSECTS)
addr = try_ram_remap(offset, size);
if (!addr)
addr = arch_memremap_wb(offset, size);
}
if (!addr && is_ram == REGION_INTERSECTS && flags != MEMREMAP_WB) {
WARN_ONCE(1, "memremap attempted on ram %pa size: %#lx\n",
&offset, (unsigned long) size);
return NULL;
}
if (!addr && (flags & MEMREMAP_WT))
addr = ioremap_wt(offset, size);
if (!addr && (flags & MEMREMAP_WC))
addr = ioremap_wc(offset, size);
return addr;
}
void memunmap(void *addr)
{
if (is_vmalloc_addr(addr))
iounmap((void __iomem *) addr);
}
static void devm_memremap_release(struct device *dev, void *res)
{
memunmap(*(void **)res);
}
static int devm_memremap_match(struct device *dev, void *res, void *match_data)
{
return *(void **)res == match_data;
}
void *devm_memremap(struct device *dev, resource_size_t offset,
size_t size, unsigned long flags)
{
void **ptr, *addr;
ptr = devres_alloc_node(devm_memremap_release, sizeof(*ptr), GFP_KERNEL,
dev_to_node(dev));
if (!ptr)
return ERR_PTR(-ENOMEM);
addr = memremap(offset, size, flags);
if (addr) {
*ptr = addr;
devres_add(dev, ptr);
} else {
devres_free(ptr);
return ERR_PTR(-ENXIO);
}
return addr;
}
void devm_memunmap(struct device *dev, void *addr)
{
WARN_ON(devres_release(dev, devm_memremap_release,
devm_memremap_match, addr));
}
pfn_t phys_to_pfn_t(phys_addr_t addr, u64 flags)
{
return __pfn_to_pfn_t(addr >> PAGE_SHIFT, flags);
}
void get_zone_device_page(struct page *page)
{
percpu_ref_get(page->pgmap->ref);
}
void put_zone_device_page(struct page *page)
{
put_dev_pagemap(page->pgmap);
}
static void pgmap_radix_release(struct resource *res)
{
resource_size_t key, align_start, align_size, align_end;
align_start = res->start & ~(SECTION_SIZE - 1);
align_size = ALIGN(resource_size(res), SECTION_SIZE);
align_end = align_start + align_size - 1;
mutex_lock(&pgmap_lock);
for (key = res->start; key <= res->end; key += SECTION_SIZE)
radix_tree_delete(&pgmap_radix, key >> PA_SECTION_SHIFT);
mutex_unlock(&pgmap_lock);
}
static unsigned long pfn_first(struct page_map *page_map)
{
struct dev_pagemap *pgmap = &page_map->pgmap;
const struct resource *res = &page_map->res;
struct vmem_altmap *altmap = pgmap->altmap;
unsigned long pfn;
pfn = res->start >> PAGE_SHIFT;
if (altmap)
pfn += vmem_altmap_offset(altmap);
return pfn;
}
static unsigned long pfn_end(struct page_map *page_map)
{
const struct resource *res = &page_map->res;
return (res->start + resource_size(res)) >> PAGE_SHIFT;
}
static void devm_memremap_pages_release(struct device *dev, void *data)
{
struct page_map *page_map = data;
struct resource *res = &page_map->res;
resource_size_t align_start, align_size;
struct dev_pagemap *pgmap = &page_map->pgmap;
if (percpu_ref_tryget_live(pgmap->ref)) {
dev_WARN(dev, "%s: page mapping is still live!\n", __func__);
percpu_ref_put(pgmap->ref);
}
align_start = res->start & ~(SECTION_SIZE - 1);
align_size = ALIGN(resource_size(res), SECTION_SIZE);
arch_remove_memory(align_start, align_size);
pgmap_radix_release(res);
dev_WARN_ONCE(dev, pgmap->altmap && pgmap->altmap->alloc,
"%s: failed to free all reserved pages\n", __func__);
}
struct dev_pagemap *find_dev_pagemap(resource_size_t phys)
{
struct page_map *page_map;
WARN_ON_ONCE(!rcu_read_lock_held());
page_map = radix_tree_lookup(&pgmap_radix, phys >> PA_SECTION_SHIFT);
return page_map ? &page_map->pgmap : NULL;
}
void *devm_memremap_pages(struct device *dev, struct resource *res,
struct percpu_ref *ref, struct vmem_altmap *altmap)
{
resource_size_t key, align_start, align_size, align_end;
struct dev_pagemap *pgmap;
struct page_map *page_map;
int error, nid, is_ram;
unsigned long pfn;
align_start = res->start & ~(SECTION_SIZE - 1);
align_size = ALIGN(res->start + resource_size(res), SECTION_SIZE)
- align_start;
is_ram = region_intersects(align_start, align_size,
IORESOURCE_SYSTEM_RAM, IORES_DESC_NONE);
if (is_ram == REGION_MIXED) {
WARN_ONCE(1, "%s attempted on mixed region %pr\n",
__func__, res);
return ERR_PTR(-ENXIO);
}
if (is_ram == REGION_INTERSECTS)
return __va(res->start);
if (altmap && !IS_ENABLED(CONFIG_SPARSEMEM_VMEMMAP)) {
dev_err(dev, "%s: altmap requires CONFIG_SPARSEMEM_VMEMMAP=y\n",
__func__);
return ERR_PTR(-ENXIO);
}
if (!ref)
return ERR_PTR(-EINVAL);
page_map = devres_alloc_node(devm_memremap_pages_release,
sizeof(*page_map), GFP_KERNEL, dev_to_node(dev));
if (!page_map)
return ERR_PTR(-ENOMEM);
pgmap = &page_map->pgmap;
memcpy(&page_map->res, res, sizeof(*res));
pgmap->dev = dev;
if (altmap) {
memcpy(&page_map->altmap, altmap, sizeof(*altmap));
pgmap->altmap = &page_map->altmap;
}
pgmap->ref = ref;
pgmap->res = &page_map->res;
mutex_lock(&pgmap_lock);
error = 0;
align_end = align_start + align_size - 1;
for (key = align_start; key <= align_end; key += SECTION_SIZE) {
struct dev_pagemap *dup;
rcu_read_lock();
dup = find_dev_pagemap(key);
rcu_read_unlock();
if (dup) {
dev_err(dev, "%s: %pr collides with mapping for %s\n",
__func__, res, dev_name(dup->dev));
error = -EBUSY;
break;
}
error = radix_tree_insert(&pgmap_radix, key >> PA_SECTION_SHIFT,
page_map);
if (error) {
dev_err(dev, "%s: failed: %d\n", __func__, error);
break;
}
}
mutex_unlock(&pgmap_lock);
if (error)
goto err_radix;
nid = dev_to_node(dev);
if (nid < 0)
nid = numa_mem_id();
error = arch_add_memory(nid, align_start, align_size, true);
if (error)
goto err_add_memory;
for_each_device_pfn(pfn, page_map) {
struct page *page = pfn_to_page(pfn);
list_del(&page->lru);
page->pgmap = pgmap;
}
devres_add(dev, page_map);
return __va(res->start);
err_add_memory:
err_radix:
pgmap_radix_release(res);
devres_free(page_map);
return ERR_PTR(error);
}
unsigned long vmem_altmap_offset(struct vmem_altmap *altmap)
{
return altmap->reserve + altmap->free;
}
void vmem_altmap_free(struct vmem_altmap *altmap, unsigned long nr_pfns)
{
altmap->alloc -= nr_pfns;
}
struct vmem_altmap *to_vmem_altmap(unsigned long memmap_start)
{
struct page *page = (struct page *) memmap_start;
struct dev_pagemap *pgmap;
rcu_read_lock();
pgmap = find_dev_pagemap(__pfn_to_phys(page_to_pfn(page)));
rcu_read_unlock();
return pgmap ? pgmap->altmap : NULL;
}
