__weak void __iomem *ioremap_cache(resource_size_t offset, unsigned long size)
{
return ioremap(offset, size);
}
static void *arch_memremap_wb(resource_size_t offset, unsigned long size)
{
return (__force void *)ioremap_cache(offset, size);
}
static bool arch_memremap_can_ram_remap(resource_size_t offset, size_t size,
unsigned long flags)
{
return true;
}
static void *try_ram_remap(resource_size_t offset, size_t size,
unsigned long flags)
{
unsigned long pfn = PHYS_PFN(offset);
if (pfn_valid(pfn) && !PageHighMem(pfn_to_page(pfn)) &&
arch_memremap_can_ram_remap(offset, size, flags))
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
addr = try_ram_remap(offset, size, flags);
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
static unsigned long order_at(struct resource *res, unsigned long pgoff)
{
unsigned long phys_pgoff = PHYS_PFN(res->start) + pgoff;
unsigned long nr_pages, mask;
nr_pages = PHYS_PFN(resource_size(res));
if (nr_pages == pgoff)
return ULONG_MAX;
mask = phys_pgoff | rounddown_pow_of_two(nr_pages - pgoff);
if (!mask)
return ULONG_MAX;
return find_first_bit(&mask, BITS_PER_LONG);
}
int device_private_entry_fault(struct vm_area_struct *vma,
unsigned long addr,
swp_entry_t entry,
unsigned int flags,
pmd_t *pmdp)
{
struct page *page = device_private_entry_to_page(entry);
return page->pgmap->page_fault(vma, addr, page, flags, pmdp);
}
static void pgmap_radix_release(struct resource *res)
{
unsigned long pgoff, order;
mutex_lock(&pgmap_lock);
foreach_order_pgoff(res, order, pgoff)
radix_tree_delete(&pgmap_radix, PHYS_PFN(res->start) + pgoff);
mutex_unlock(&pgmap_lock);
synchronize_rcu();
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
unsigned long pfn;
for_each_device_pfn(pfn, page_map)
put_page(pfn_to_page(pfn));
if (percpu_ref_tryget_live(pgmap->ref)) {
dev_WARN(dev, "%s: page mapping is still live!\n", __func__);
percpu_ref_put(pgmap->ref);
}
align_start = res->start & ~(SECTION_SIZE - 1);
align_size = ALIGN(resource_size(res), SECTION_SIZE);
mem_hotplug_begin();
arch_remove_memory(align_start, align_size);
mem_hotplug_done();
untrack_pfn(NULL, PHYS_PFN(align_start), align_size);
pgmap_radix_release(res);
dev_WARN_ONCE(dev, pgmap->altmap && pgmap->altmap->alloc,
"%s: failed to free all reserved pages\n", __func__);
}
struct dev_pagemap *find_dev_pagemap(resource_size_t phys)
{
struct page_map *page_map;
WARN_ON_ONCE(!rcu_read_lock_held());
page_map = radix_tree_lookup(&pgmap_radix, PHYS_PFN(phys));
return page_map ? &page_map->pgmap : NULL;
}
void *devm_memremap_pages(struct device *dev, struct resource *res,
struct percpu_ref *ref, struct vmem_altmap *altmap)
{
resource_size_t align_start, align_size, align_end;
unsigned long pfn, pgoff, order;
pgprot_t pgprot = PAGE_KERNEL;
struct dev_pagemap *pgmap;
struct page_map *page_map;
int error, nid, is_ram, i = 0;
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
pgmap->type = MEMORY_DEVICE_HOST;
pgmap->page_fault = NULL;
pgmap->page_free = NULL;
pgmap->data = NULL;
mutex_lock(&pgmap_lock);
error = 0;
align_end = align_start + align_size - 1;
foreach_order_pgoff(res, order, pgoff) {
struct dev_pagemap *dup;
rcu_read_lock();
dup = find_dev_pagemap(res->start + PFN_PHYS(pgoff));
rcu_read_unlock();
if (dup) {
dev_err(dev, "%s: %pr collides with mapping for %s\n",
__func__, res, dev_name(dup->dev));
error = -EBUSY;
break;
}
error = __radix_tree_insert(&pgmap_radix,
PHYS_PFN(res->start) + pgoff, order, page_map);
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
error = track_pfn_remap(NULL, &pgprot, PHYS_PFN(align_start), 0,
align_size);
if (error)
goto err_pfn_remap;
mem_hotplug_begin();
error = arch_add_memory(nid, align_start, align_size, false);
if (!error)
move_pfn_range_to_zone(&NODE_DATA(nid)->node_zones[ZONE_DEVICE],
align_start >> PAGE_SHIFT,
align_size >> PAGE_SHIFT);
mem_hotplug_done();
if (error)
goto err_add_memory;
for_each_device_pfn(pfn, page_map) {
struct page *page = pfn_to_page(pfn);
list_del(&page->lru);
page->pgmap = pgmap;
percpu_ref_get(ref);
if (!(++i % 1024))
cond_resched();
}
devres_add(dev, page_map);
return __va(res->start);
err_add_memory:
untrack_pfn(NULL, PHYS_PFN(align_start), align_size);
err_pfn_remap:
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
void put_zone_device_private_or_public_page(struct page *page)
{
int count = page_ref_dec_return(page);
if (count == 1) {
__ClearPageActive(page);
__ClearPageWaiters(page);
page->mapping = NULL;
mem_cgroup_uncharge(page);
page->pgmap->page_free(page, page->pgmap->data);
} else if (!count)
__put_page(page);
}
