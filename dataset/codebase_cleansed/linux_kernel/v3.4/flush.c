static void flush_pfn_alias(unsigned long pfn, unsigned long vaddr)
{
unsigned long to = FLUSH_ALIAS_START + (CACHE_COLOUR(vaddr) << PAGE_SHIFT);
const int zero = 0;
set_top_pte(to, pfn_pte(pfn, PAGE_KERNEL));
asm( "mcrr p15, 0, %1, %0, c14\n"
" mcr p15, 0, %2, c7, c10, 4"
:
: "r" (to), "r" (to + PAGE_SIZE - L1_CACHE_BYTES), "r" (zero)
: "cc");
}
static void flush_icache_alias(unsigned long pfn, unsigned long vaddr, unsigned long len)
{
unsigned long va = FLUSH_ALIAS_START + (CACHE_COLOUR(vaddr) << PAGE_SHIFT);
unsigned long offset = vaddr & (PAGE_SIZE - 1);
unsigned long to;
set_top_pte(va, pfn_pte(pfn, PAGE_KERNEL));
to = va + offset;
flush_icache_range(to, to + len);
}
void flush_cache_mm(struct mm_struct *mm)
{
if (cache_is_vivt()) {
vivt_flush_cache_mm(mm);
return;
}
if (cache_is_vipt_aliasing()) {
asm( "mcr p15, 0, %0, c7, c14, 0\n"
" mcr p15, 0, %0, c7, c10, 4"
:
: "r" (0)
: "cc");
}
}
void flush_cache_range(struct vm_area_struct *vma, unsigned long start, unsigned long end)
{
if (cache_is_vivt()) {
vivt_flush_cache_range(vma, start, end);
return;
}
if (cache_is_vipt_aliasing()) {
asm( "mcr p15, 0, %0, c7, c14, 0\n"
" mcr p15, 0, %0, c7, c10, 4"
:
: "r" (0)
: "cc");
}
if (vma->vm_flags & VM_EXEC)
__flush_icache_all();
}
void flush_cache_page(struct vm_area_struct *vma, unsigned long user_addr, unsigned long pfn)
{
if (cache_is_vivt()) {
vivt_flush_cache_page(vma, user_addr, pfn);
return;
}
if (cache_is_vipt_aliasing()) {
flush_pfn_alias(pfn, user_addr);
__flush_icache_all();
}
if (vma->vm_flags & VM_EXEC && icache_is_vivt_asid_tagged())
__flush_icache_all();
}
static void flush_ptrace_access_other(void *args)
{
__flush_icache_all();
}
static
void flush_ptrace_access(struct vm_area_struct *vma, struct page *page,
unsigned long uaddr, void *kaddr, unsigned long len)
{
if (cache_is_vivt()) {
if (cpumask_test_cpu(smp_processor_id(), mm_cpumask(vma->vm_mm))) {
unsigned long addr = (unsigned long)kaddr;
__cpuc_coherent_kern_range(addr, addr + len);
}
return;
}
if (cache_is_vipt_aliasing()) {
flush_pfn_alias(page_to_pfn(page), uaddr);
__flush_icache_all();
return;
}
if (vma->vm_flags & VM_EXEC) {
unsigned long addr = (unsigned long)kaddr;
if (icache_is_vipt_aliasing())
flush_icache_alias(page_to_pfn(page), uaddr, len);
else
__cpuc_coherent_kern_range(addr, addr + len);
if (cache_ops_need_broadcast())
smp_call_function(flush_ptrace_access_other,
NULL, 1);
}
}
void copy_to_user_page(struct vm_area_struct *vma, struct page *page,
unsigned long uaddr, void *dst, const void *src,
unsigned long len)
{
#ifdef CONFIG_SMP
preempt_disable();
#endif
memcpy(dst, src, len);
flush_ptrace_access(vma, page, uaddr, dst, len);
#ifdef CONFIG_SMP
preempt_enable();
#endif
}
void __flush_dcache_page(struct address_space *mapping, struct page *page)
{
if (!PageHighMem(page)) {
__cpuc_flush_dcache_area(page_address(page), PAGE_SIZE);
} else {
void *addr = kmap_high_get(page);
if (addr) {
__cpuc_flush_dcache_area(addr, PAGE_SIZE);
kunmap_high(page);
} else if (cache_is_vipt()) {
addr = kmap_atomic(page);
__cpuc_flush_dcache_area(addr, PAGE_SIZE);
kunmap_atomic(addr);
}
}
if (mapping && cache_is_vipt_aliasing())
flush_pfn_alias(page_to_pfn(page),
page->index << PAGE_CACHE_SHIFT);
}
static void __flush_dcache_aliases(struct address_space *mapping, struct page *page)
{
struct mm_struct *mm = current->active_mm;
struct vm_area_struct *mpnt;
struct prio_tree_iter iter;
pgoff_t pgoff;
pgoff = page->index << (PAGE_CACHE_SHIFT - PAGE_SHIFT);
flush_dcache_mmap_lock(mapping);
vma_prio_tree_foreach(mpnt, &iter, &mapping->i_mmap, pgoff, pgoff) {
unsigned long offset;
if (mpnt->vm_mm != mm)
continue;
if (!(mpnt->vm_flags & VM_MAYSHARE))
continue;
offset = (pgoff - mpnt->vm_pgoff) << PAGE_SHIFT;
flush_cache_page(mpnt, mpnt->vm_start + offset, page_to_pfn(page));
}
flush_dcache_mmap_unlock(mapping);
}
void __sync_icache_dcache(pte_t pteval)
{
unsigned long pfn;
struct page *page;
struct address_space *mapping;
if (!pte_present_user(pteval))
return;
if (cache_is_vipt_nonaliasing() && !pte_exec(pteval))
return;
pfn = pte_pfn(pteval);
if (!pfn_valid(pfn))
return;
page = pfn_to_page(pfn);
if (cache_is_vipt_aliasing())
mapping = page_mapping(page);
else
mapping = NULL;
if (!test_and_set_bit(PG_dcache_clean, &page->flags))
__flush_dcache_page(mapping, page);
if (pte_exec(pteval))
__flush_icache_all();
}
void flush_dcache_page(struct page *page)
{
struct address_space *mapping;
if (page == ZERO_PAGE(0))
return;
mapping = page_mapping(page);
if (!cache_ops_need_broadcast() &&
mapping && !mapping_mapped(mapping))
clear_bit(PG_dcache_clean, &page->flags);
else {
__flush_dcache_page(mapping, page);
if (mapping && cache_is_vivt())
__flush_dcache_aliases(mapping, page);
else if (mapping)
__flush_icache_all();
set_bit(PG_dcache_clean, &page->flags);
}
}
void __flush_anon_page(struct vm_area_struct *vma, struct page *page, unsigned long vmaddr)
{
unsigned long pfn;
if (cache_is_vipt_nonaliasing())
return;
pfn = page_to_pfn(page);
if (cache_is_vivt()) {
flush_cache_page(vma, vmaddr, pfn);
} else {
flush_pfn_alias(pfn, vmaddr);
__flush_icache_all();
}
__cpuc_flush_dcache_area(page_address(page), PAGE_SIZE);
}
