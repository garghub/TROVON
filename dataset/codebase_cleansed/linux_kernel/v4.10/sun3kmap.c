static inline void do_page_mapin(unsigned long phys, unsigned long virt,
unsigned long type)
{
unsigned long pte;
pte_t ptep;
ptep = pfn_pte(phys >> PAGE_SHIFT, PAGE_KERNEL);
pte = pte_val(ptep);
pte |= type;
sun3_put_pte(virt, pte);
#ifdef SUN3_KMAP_DEBUG
print_pte_vaddr(virt);
#endif
}
static inline void do_pmeg_mapin(unsigned long phys, unsigned long virt,
unsigned long type, int pages)
{
if(sun3_get_segmap(virt & ~SUN3_PMEG_MASK) == SUN3_INVALID_PMEG)
mmu_emu_map_pmeg(sun3_get_context(), virt);
while(pages) {
do_page_mapin(phys, virt, type);
phys += PAGE_SIZE;
virt += PAGE_SIZE;
pages--;
}
}
void __iomem *sun3_ioremap(unsigned long phys, unsigned long size,
unsigned long type)
{
struct vm_struct *area;
unsigned long offset, virt, ret;
int pages;
if(!size)
return NULL;
offset = phys & (PAGE_SIZE-1);
phys &= ~(PAGE_SIZE-1);
size += offset;
size = PAGE_ALIGN(size);
if((area = get_vm_area(size, VM_IOREMAP)) == NULL)
return NULL;
#ifdef SUN3_KMAP_DEBUG
printk("ioremap: got virt %p size %lx(%lx)\n",
area->addr, size, area->size);
#endif
pages = size / PAGE_SIZE;
virt = (unsigned long)area->addr;
ret = virt + offset;
while(pages) {
int seg_pages;
seg_pages = (SUN3_PMEG_SIZE - (virt & SUN3_PMEG_MASK)) / PAGE_SIZE;
if(seg_pages > pages)
seg_pages = pages;
do_pmeg_mapin(phys, virt, type, seg_pages);
pages -= seg_pages;
phys += seg_pages * PAGE_SIZE;
virt += seg_pages * PAGE_SIZE;
}
return (void __iomem *)ret;
}
void __iomem *__ioremap(unsigned long phys, unsigned long size, int cache)
{
return sun3_ioremap(phys, size, SUN3_PAGE_TYPE_IO);
}
void iounmap(void __iomem *addr)
{
vfree((void *)(PAGE_MASK & (unsigned long)addr));
}
int sun3_map_test(unsigned long addr, char *val)
{
int ret = 0;
__asm__ __volatile__
(".globl _sun3_map_test_start\n"
"_sun3_map_test_start:\n"
"1: moveb (%2), (%0)\n"
" moveq #1, %1\n"
"2:\n"
".section .fixup,\"ax\"\n"
".even\n"
"3: moveq #0, %1\n"
" jmp 2b\n"
".previous\n"
".section __ex_table,\"a\"\n"
".align 4\n"
".long 1b,3b\n"
".previous\n"
".globl _sun3_map_test_end\n"
"_sun3_map_test_end:\n"
: "=a"(val), "=r"(ret)
: "a"(addr));
return ret;
}
