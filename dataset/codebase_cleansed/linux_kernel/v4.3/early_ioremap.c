static int __init early_ioremap_debug_setup(char *str)
{
early_ioremap_debug = 1;
return 0;
}
void __init __weak early_ioremap_shutdown(void)
{
}
void __init early_ioremap_reset(void)
{
early_ioremap_shutdown();
after_paging_init = 1;
}
static inline void __init __late_set_fixmap(enum fixed_addresses idx,
phys_addr_t phys, pgprot_t prot)
{
BUG();
}
static inline void __init __late_clear_fixmap(enum fixed_addresses idx)
{
BUG();
}
void __init early_ioremap_setup(void)
{
int i;
for (i = 0; i < FIX_BTMAPS_SLOTS; i++)
if (WARN_ON(prev_map[i]))
break;
for (i = 0; i < FIX_BTMAPS_SLOTS; i++)
slot_virt[i] = __fix_to_virt(FIX_BTMAP_BEGIN - NR_FIX_BTMAPS*i);
}
static int __init check_early_ioremap_leak(void)
{
int count = 0;
int i;
for (i = 0; i < FIX_BTMAPS_SLOTS; i++)
if (prev_map[i])
count++;
if (WARN(count, KERN_WARNING
"Debug warning: early ioremap leak of %d areas detected.\n"
"please boot with early_ioremap_debug and report the dmesg.\n",
count))
return 1;
return 0;
}
static void __init __iomem *
__early_ioremap(resource_size_t phys_addr, unsigned long size, pgprot_t prot)
{
unsigned long offset;
resource_size_t last_addr;
unsigned int nrpages;
enum fixed_addresses idx;
int i, slot;
WARN_ON(system_state != SYSTEM_BOOTING);
slot = -1;
for (i = 0; i < FIX_BTMAPS_SLOTS; i++) {
if (!prev_map[i]) {
slot = i;
break;
}
}
if (WARN(slot < 0, "%s(%08llx, %08lx) not found slot\n",
__func__, (u64)phys_addr, size))
return NULL;
last_addr = phys_addr + size - 1;
if (WARN_ON(!size || last_addr < phys_addr))
return NULL;
prev_size[slot] = size;
offset = phys_addr & ~PAGE_MASK;
phys_addr &= PAGE_MASK;
size = PAGE_ALIGN(last_addr + 1) - phys_addr;
nrpages = size >> PAGE_SHIFT;
if (WARN_ON(nrpages > NR_FIX_BTMAPS))
return NULL;
idx = FIX_BTMAP_BEGIN - NR_FIX_BTMAPS*slot;
while (nrpages > 0) {
if (after_paging_init)
__late_set_fixmap(idx, phys_addr, prot);
else
__early_set_fixmap(idx, phys_addr, prot);
phys_addr += PAGE_SIZE;
--idx;
--nrpages;
}
WARN(early_ioremap_debug, "%s(%08llx, %08lx) [%d] => %08lx + %08lx\n",
__func__, (u64)phys_addr, size, slot, offset, slot_virt[slot]);
prev_map[slot] = (void __iomem *)(offset + slot_virt[slot]);
return prev_map[slot];
}
void __init early_iounmap(void __iomem *addr, unsigned long size)
{
unsigned long virt_addr;
unsigned long offset;
unsigned int nrpages;
enum fixed_addresses idx;
int i, slot;
slot = -1;
for (i = 0; i < FIX_BTMAPS_SLOTS; i++) {
if (prev_map[i] == addr) {
slot = i;
break;
}
}
if (WARN(slot < 0, "early_iounmap(%p, %08lx) not found slot\n",
addr, size))
return;
if (WARN(prev_size[slot] != size,
"early_iounmap(%p, %08lx) [%d] size not consistent %08lx\n",
addr, size, slot, prev_size[slot]))
return;
WARN(early_ioremap_debug, "early_iounmap(%p, %08lx) [%d]\n",
addr, size, slot);
virt_addr = (unsigned long)addr;
if (WARN_ON(virt_addr < fix_to_virt(FIX_BTMAP_BEGIN)))
return;
offset = virt_addr & ~PAGE_MASK;
nrpages = PAGE_ALIGN(offset + size) >> PAGE_SHIFT;
idx = FIX_BTMAP_BEGIN - NR_FIX_BTMAPS*slot;
while (nrpages > 0) {
if (after_paging_init)
__late_clear_fixmap(idx);
else
__early_set_fixmap(idx, 0, FIXMAP_PAGE_CLEAR);
--idx;
--nrpages;
}
prev_map[slot] = NULL;
}
void __init __iomem *
early_ioremap(resource_size_t phys_addr, unsigned long size)
{
return __early_ioremap(phys_addr, size, FIXMAP_PAGE_IO);
}
void __init *
early_memremap(resource_size_t phys_addr, unsigned long size)
{
return (__force void *)__early_ioremap(phys_addr, size,
FIXMAP_PAGE_NORMAL);
}
void __init *
early_memremap_ro(resource_size_t phys_addr, unsigned long size)
{
return (__force void *)__early_ioremap(phys_addr, size, FIXMAP_PAGE_RO);
}
void __init copy_from_early_mem(void *dest, phys_addr_t src, unsigned long size)
{
unsigned long slop, clen;
char *p;
while (size) {
slop = src & ~PAGE_MASK;
clen = size;
if (clen > MAX_MAP_CHUNK - slop)
clen = MAX_MAP_CHUNK - slop;
p = early_memremap(src & PAGE_MASK, clen + slop);
memcpy(dest, p + slop, clen);
early_memunmap(p, clen + slop);
dest += clen;
src += clen;
size -= clen;
}
}
void __init __iomem *
early_ioremap(resource_size_t phys_addr, unsigned long size)
{
return (__force void __iomem *)phys_addr;
}
void __init *
early_memremap(resource_size_t phys_addr, unsigned long size)
{
return (void *)phys_addr;
}
void __init *
early_memremap_ro(resource_size_t phys_addr, unsigned long size)
{
return (void *)phys_addr;
}
void __init early_iounmap(void __iomem *addr, unsigned long size)
{
}
void __init early_memunmap(void *addr, unsigned long size)
{
early_iounmap((__force void __iomem *)addr, size);
}
