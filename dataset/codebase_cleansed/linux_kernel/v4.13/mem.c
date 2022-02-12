void __init prom_init_memory(void)
{
add_memory_region(0x0, (memsize << 20), BOOT_MEM_RAM);
add_memory_region(memsize << 20, LOONGSON_PCI_MEM_START - (memsize <<
20), BOOT_MEM_RESERVED);
#ifdef CONFIG_CPU_SUPPORTS_ADDRWINCFG
{
int bit;
bit = fls(memsize + highmemsize);
if (bit != ffs(memsize + highmemsize))
bit += 20;
else
bit = bit + 20 - 1;
LOONGSON_ADDRWIN_CPUTODDR(ADDRWIN_WIN3, 0x80000000ul,
0x80000000ul, (1 << bit));
mmiowb();
}
#endif
#ifdef CONFIG_64BIT
if (highmemsize > 0)
add_memory_region(LOONGSON_HIGHMEM_START,
highmemsize << 20, BOOT_MEM_RAM);
add_memory_region(LOONGSON_PCI_MEM_END + 1, LOONGSON_HIGHMEM_START -
LOONGSON_PCI_MEM_END - 1, BOOT_MEM_RESERVED);
#endif
}
void __init prom_init_memory(void)
{
int i;
u32 node_id;
u32 mem_type;
for (i = 0; i < loongson_memmap->nr_map; i++) {
node_id = loongson_memmap->map[i].node_id;
mem_type = loongson_memmap->map[i].mem_type;
if (node_id == 0) {
switch (mem_type) {
case SYSTEM_RAM_LOW:
add_memory_region(loongson_memmap->map[i].mem_start,
(u64)loongson_memmap->map[i].mem_size << 20,
BOOT_MEM_RAM);
break;
case SYSTEM_RAM_HIGH:
add_memory_region(loongson_memmap->map[i].mem_start,
(u64)loongson_memmap->map[i].mem_size << 20,
BOOT_MEM_RAM);
break;
case MEM_RESERVED:
add_memory_region(loongson_memmap->map[i].mem_start,
(u64)loongson_memmap->map[i].mem_size << 20,
BOOT_MEM_RESERVED);
break;
}
}
}
}
int __uncached_access(struct file *file, unsigned long addr)
{
if (file->f_flags & O_DSYNC)
return 1;
return addr >= __pa(high_memory) ||
((addr >= LOONGSON_MMIO_MEM_START) &&
(addr < LOONGSON_MMIO_MEM_END));
}
pgprot_t phys_mem_access_prot(struct file *file, unsigned long pfn,
unsigned long size, pgprot_t vma_prot)
{
unsigned long offset = pfn << PAGE_SHIFT;
unsigned long end = offset + size;
if (__uncached_access(file, offset)) {
if (uca_start && (offset >= uca_start) &&
(end <= uca_end))
return __pgprot((pgprot_val(vma_prot) &
~_CACHE_MASK) |
_CACHE_UNCACHED_ACCELERATED);
else
return pgprot_noncached(vma_prot);
}
return vma_prot;
}
static int __init find_vga_mem_init(void)
{
struct pci_dev *dev = 0;
struct resource *r;
int idx;
if (uca_start)
return 0;
for_each_pci_dev(dev) {
if ((dev->class >> 16) == PCI_BASE_CLASS_DISPLAY) {
for (idx = 0; idx < PCI_NUM_RESOURCES; idx++) {
r = &dev->resource[idx];
if (!r->start && r->end)
continue;
if (r->flags & IORESOURCE_IO)
continue;
if (r->flags & IORESOURCE_MEM) {
uca_start = r->start;
uca_end = r->end;
return 0;
}
}
}
}
return 0;
}
