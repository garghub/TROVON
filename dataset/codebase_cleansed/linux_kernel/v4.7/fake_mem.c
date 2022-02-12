static int __init cmp_fake_mem(const void *x1, const void *x2)
{
const struct fake_mem *m1 = x1;
const struct fake_mem *m2 = x2;
if (m1->range.start < m2->range.start)
return -1;
if (m1->range.start > m2->range.start)
return 1;
return 0;
}
void __init efi_fake_memmap(void)
{
u64 start, end, m_start, m_end, m_attr;
int new_nr_map = efi.memmap.nr_map;
efi_memory_desc_t *md;
phys_addr_t new_memmap_phy;
void *new_memmap;
void *old, *new;
int i;
if (!nr_fake_mem || !efi_enabled(EFI_MEMMAP))
return;
for_each_efi_memory_desc(md) {
start = md->phys_addr;
end = start + (md->num_pages << EFI_PAGE_SHIFT) - 1;
for (i = 0; i < nr_fake_mem; i++) {
m_start = fake_mems[i].range.start;
m_end = fake_mems[i].range.end;
if (m_start <= start) {
if (start < m_end && m_end < end)
new_nr_map++;
}
if (start < m_start && m_start < end) {
if (m_end < end)
new_nr_map += 2;
if (end <= m_end)
new_nr_map++;
}
}
}
new_memmap_phy = memblock_alloc(efi.memmap.desc_size * new_nr_map,
PAGE_SIZE);
if (!new_memmap_phy)
return;
new_memmap = early_memremap(new_memmap_phy,
efi.memmap.desc_size * new_nr_map);
if (!new_memmap) {
memblock_free(new_memmap_phy, efi.memmap.desc_size * new_nr_map);
return;
}
for (old = efi.memmap.map, new = new_memmap;
old < efi.memmap.map_end;
old += efi.memmap.desc_size, new += efi.memmap.desc_size) {
memcpy(new, old, efi.memmap.desc_size);
md = new;
start = md->phys_addr;
end = md->phys_addr + (md->num_pages << EFI_PAGE_SHIFT) - 1;
for (i = 0; i < nr_fake_mem; i++) {
m_start = fake_mems[i].range.start;
m_end = fake_mems[i].range.end;
m_attr = fake_mems[i].attribute;
if (m_start <= start && end <= m_end)
md->attribute |= m_attr;
if (m_start <= start &&
(start < m_end && m_end < end)) {
md->attribute |= m_attr;
md->num_pages = (m_end - md->phys_addr + 1) >>
EFI_PAGE_SHIFT;
new += efi.memmap.desc_size;
memcpy(new, old, efi.memmap.desc_size);
md = new;
md->phys_addr = m_end + 1;
md->num_pages = (end - md->phys_addr + 1) >>
EFI_PAGE_SHIFT;
}
if ((start < m_start && m_start < end) && m_end < end) {
md->num_pages = (m_start - md->phys_addr) >>
EFI_PAGE_SHIFT;
new += efi.memmap.desc_size;
memcpy(new, old, efi.memmap.desc_size);
md = new;
md->attribute |= m_attr;
md->phys_addr = m_start;
md->num_pages = (m_end - m_start + 1) >>
EFI_PAGE_SHIFT;
new += efi.memmap.desc_size;
memcpy(new, old, efi.memmap.desc_size);
md = new;
md->phys_addr = m_end + 1;
md->num_pages = (end - m_end) >>
EFI_PAGE_SHIFT;
}
if ((start < m_start && m_start < end) &&
(end <= m_end)) {
md->num_pages = (m_start - md->phys_addr) >>
EFI_PAGE_SHIFT;
new += efi.memmap.desc_size;
memcpy(new, old, efi.memmap.desc_size);
md = new;
md->phys_addr = m_start;
md->num_pages = (end - md->phys_addr + 1) >>
EFI_PAGE_SHIFT;
md->attribute |= m_attr;
}
}
}
efi_unmap_memmap();
efi.memmap.map = new_memmap;
efi.memmap.phys_map = new_memmap_phy;
efi.memmap.nr_map = new_nr_map;
efi.memmap.map_end = efi.memmap.map + efi.memmap.nr_map * efi.memmap.desc_size;
set_bit(EFI_MEMMAP, &efi.flags);
efi_print_memmap();
}
static int __init setup_fake_mem(char *p)
{
u64 start = 0, mem_size = 0, attribute = 0;
int i;
if (!p)
return -EINVAL;
while (*p != '\0') {
mem_size = memparse(p, &p);
if (*p == '@')
start = memparse(p+1, &p);
else
break;
if (*p == ':')
attribute = simple_strtoull(p+1, &p, 0);
else
break;
if (nr_fake_mem >= EFI_MAX_FAKEMEM)
break;
fake_mems[nr_fake_mem].range.start = start;
fake_mems[nr_fake_mem].range.end = start + mem_size - 1;
fake_mems[nr_fake_mem].attribute = attribute;
nr_fake_mem++;
if (*p == ',')
p++;
}
sort(fake_mems, nr_fake_mem, sizeof(struct fake_mem),
cmp_fake_mem, NULL);
for (i = 0; i < nr_fake_mem; i++)
pr_info("efi_fake_mem: add attr=0x%016llx to [mem 0x%016llx-0x%016llx]",
fake_mems[i].attribute, fake_mems[i].range.start,
fake_mems[i].range.end);
return *p == '\0' ? 0 : -EINVAL;
}
