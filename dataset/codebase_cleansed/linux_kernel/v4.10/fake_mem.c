static int __init cmp_fake_mem(const void *x1, const void *x2)
{
const struct efi_mem_range *m1 = x1;
const struct efi_mem_range *m2 = x2;
if (m1->range.start < m2->range.start)
return -1;
if (m1->range.start > m2->range.start)
return 1;
return 0;
}
void __init efi_fake_memmap(void)
{
int new_nr_map = efi.memmap.nr_map;
efi_memory_desc_t *md;
phys_addr_t new_memmap_phy;
void *new_memmap;
int i;
if (!nr_fake_mem)
return;
for (i = 0; i < nr_fake_mem; i++) {
for_each_efi_memory_desc(md) {
struct range *r = &fake_mems[i].range;
new_nr_map += efi_memmap_split_count(md, r);
}
}
new_memmap_phy = efi_memmap_alloc(new_nr_map);
if (!new_memmap_phy)
return;
new_memmap = early_memremap(new_memmap_phy,
efi.memmap.desc_size * new_nr_map);
if (!new_memmap) {
memblock_free(new_memmap_phy, efi.memmap.desc_size * new_nr_map);
return;
}
for (i = 0; i < nr_fake_mem; i++)
efi_memmap_insert(&efi.memmap, new_memmap, &fake_mems[i]);
early_memunmap(new_memmap, efi.memmap.desc_size * new_nr_map);
efi_memmap_install(new_memmap_phy, new_nr_map);
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
sort(fake_mems, nr_fake_mem, sizeof(struct efi_mem_range),
cmp_fake_mem, NULL);
for (i = 0; i < nr_fake_mem; i++)
pr_info("efi_fake_mem: add attr=0x%016llx to [mem 0x%016llx-0x%016llx]",
fake_mems[i].attribute, fake_mems[i].range.start,
fake_mems[i].range.end);
return *p == '\0' ? 0 : -EINVAL;
}
