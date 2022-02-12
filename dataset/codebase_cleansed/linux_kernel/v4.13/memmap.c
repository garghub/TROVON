static phys_addr_t __init __efi_memmap_alloc_early(unsigned long size)
{
return memblock_alloc(size, 0);
}
static phys_addr_t __init __efi_memmap_alloc_late(unsigned long size)
{
unsigned int order = get_order(size);
struct page *p = alloc_pages(GFP_KERNEL, order);
if (!p)
return 0;
return PFN_PHYS(page_to_pfn(p));
}
phys_addr_t __init efi_memmap_alloc(unsigned int num_entries)
{
unsigned long size = num_entries * efi.memmap.desc_size;
if (slab_is_available())
return __efi_memmap_alloc_late(size);
return __efi_memmap_alloc_early(size);
}
static int __init
__efi_memmap_init(struct efi_memory_map_data *data, bool late)
{
struct efi_memory_map map;
phys_addr_t phys_map;
if (efi_enabled(EFI_PARAVIRT))
return 0;
phys_map = data->phys_map;
if (late)
map.map = memremap(phys_map, data->size, MEMREMAP_WB);
else
map.map = early_memremap(phys_map, data->size);
if (!map.map) {
pr_err("Could not map the memory map!\n");
return -ENOMEM;
}
map.phys_map = data->phys_map;
map.nr_map = data->size / data->desc_size;
map.map_end = map.map + data->size;
map.desc_version = data->desc_version;
map.desc_size = data->desc_size;
map.late = late;
set_bit(EFI_MEMMAP, &efi.flags);
efi.memmap = map;
return 0;
}
int __init efi_memmap_init_early(struct efi_memory_map_data *data)
{
WARN_ON(efi.memmap.late);
return __efi_memmap_init(data, false);
}
void __init efi_memmap_unmap(void)
{
if (!efi.memmap.late) {
unsigned long size;
size = efi.memmap.desc_size * efi.memmap.nr_map;
early_memunmap(efi.memmap.map, size);
} else {
memunmap(efi.memmap.map);
}
efi.memmap.map = NULL;
clear_bit(EFI_MEMMAP, &efi.flags);
}
int __init efi_memmap_init_late(phys_addr_t addr, unsigned long size)
{
struct efi_memory_map_data data = {
.phys_map = addr,
.size = size,
};
WARN_ON(efi.memmap.map);
WARN_ON(efi.memmap.late);
data.desc_version = efi.memmap.desc_version;
data.desc_size = efi.memmap.desc_size;
return __efi_memmap_init(&data, true);
}
int __init efi_memmap_install(phys_addr_t addr, unsigned int nr_map)
{
struct efi_memory_map_data data;
efi_memmap_unmap();
data.phys_map = addr;
data.size = efi.memmap.desc_size * nr_map;
data.desc_version = efi.memmap.desc_version;
data.desc_size = efi.memmap.desc_size;
return __efi_memmap_init(&data, efi.memmap.late);
}
int __init efi_memmap_split_count(efi_memory_desc_t *md, struct range *range)
{
u64 m_start, m_end;
u64 start, end;
int count = 0;
start = md->phys_addr;
end = start + (md->num_pages << EFI_PAGE_SHIFT) - 1;
m_start = range->start;
m_end = range->end;
if (m_start <= start) {
if (start < m_end && m_end < end)
count++;
}
if (start < m_start && m_start < end) {
if (m_end < end)
count += 2;
if (end <= m_end)
count++;
}
return count;
}
void __init efi_memmap_insert(struct efi_memory_map *old_memmap, void *buf,
struct efi_mem_range *mem)
{
u64 m_start, m_end, m_attr;
efi_memory_desc_t *md;
u64 start, end;
void *old, *new;
m_start = mem->range.start;
m_end = mem->range.end;
m_attr = mem->attribute;
if (!IS_ALIGNED(m_start, EFI_PAGE_SIZE) ||
!IS_ALIGNED(m_end + 1, EFI_PAGE_SIZE)) {
WARN_ON(1);
return;
}
for (old = old_memmap->map, new = buf;
old < old_memmap->map_end;
old += old_memmap->desc_size, new += old_memmap->desc_size) {
memcpy(new, old, old_memmap->desc_size);
md = new;
start = md->phys_addr;
end = md->phys_addr + (md->num_pages << EFI_PAGE_SHIFT) - 1;
if (m_start <= start && end <= m_end)
md->attribute |= m_attr;
if (m_start <= start &&
(start < m_end && m_end < end)) {
md->attribute |= m_attr;
md->num_pages = (m_end - md->phys_addr + 1) >>
EFI_PAGE_SHIFT;
new += old_memmap->desc_size;
memcpy(new, old, old_memmap->desc_size);
md = new;
md->phys_addr = m_end + 1;
md->num_pages = (end - md->phys_addr + 1) >>
EFI_PAGE_SHIFT;
}
if ((start < m_start && m_start < end) && m_end < end) {
md->num_pages = (m_start - md->phys_addr) >>
EFI_PAGE_SHIFT;
new += old_memmap->desc_size;
memcpy(new, old, old_memmap->desc_size);
md = new;
md->attribute |= m_attr;
md->phys_addr = m_start;
md->num_pages = (m_end - m_start + 1) >>
EFI_PAGE_SHIFT;
new += old_memmap->desc_size;
memcpy(new, old, old_memmap->desc_size);
md = new;
md->phys_addr = m_end + 1;
md->num_pages = (end - m_end) >>
EFI_PAGE_SHIFT;
}
if ((start < m_start && m_start < end) &&
(end <= m_end)) {
md->num_pages = (m_start - md->phys_addr) >>
EFI_PAGE_SHIFT;
new += old_memmap->desc_size;
memcpy(new, old, old_memmap->desc_size);
md = new;
md->phys_addr = m_start;
md->num_pages = (end - md->phys_addr + 1) >>
EFI_PAGE_SHIFT;
md->attribute |= m_attr;
}
}
}
