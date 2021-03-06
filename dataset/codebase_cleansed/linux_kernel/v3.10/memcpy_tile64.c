static void memcpy_multicache(void *dest, const void *source,
pte_t dst_pte, pte_t src_pte, int len)
{
int idx;
unsigned long flags, newsrc, newdst;
pmd_t *pmdp;
pte_t *ptep;
int type0, type1;
int cpu = get_cpu();
local_irq_save(flags);
sim_allow_multiple_caching(1);
type0 = kmap_atomic_idx_push();
idx = FIX_KMAP_BEGIN + (KM_TYPE_NR * cpu) + type0;
newdst = __fix_to_virt(idx) + ((unsigned long)dest & (PAGE_SIZE-1));
pmdp = pmd_offset(pud_offset(pgd_offset_k(newdst), newdst), newdst);
ptep = pte_offset_kernel(pmdp, newdst);
if (pte_val(*ptep) != pte_val(dst_pte)) {
set_pte(ptep, dst_pte);
local_flush_tlb_page(NULL, newdst, PAGE_SIZE);
}
type1 = kmap_atomic_idx_push();
idx += (type0 - type1);
src_pte = hv_pte_set_nc(src_pte);
src_pte = hv_pte_clear_writable(src_pte);
newsrc = __fix_to_virt(idx) + ((unsigned long)source & (PAGE_SIZE-1));
pmdp = pmd_offset(pud_offset(pgd_offset_k(newsrc), newsrc), newsrc);
ptep = pte_offset_kernel(pmdp, newsrc);
__set_pte(ptep, src_pte);
local_flush_tlb_page(NULL, newsrc, PAGE_SIZE);
__memcpy_asm((void *)newdst, (const void *)newsrc, len);
src_pte = hv_pte_set_mode(src_pte, HV_PTE_MODE_CACHE_NO_L3);
src_pte = hv_pte_set_writable(src_pte);
__set_pte(ptep, src_pte);
local_flush_tlb_page(NULL, newsrc, PAGE_SIZE);
__inv_buffer((void *)newsrc, len);
kmap_atomic_idx_pop();
kmap_atomic_idx_pop();
sim_allow_multiple_caching(0);
local_irq_restore(flags);
put_cpu();
}
static unsigned long fast_copy(void *dest, const void *source, int len,
memcpy_t func)
{
while (len >= LARGE_COPY_CUTOFF) {
int copy_size, bytes_left_on_page;
pte_t *src_ptep, *dst_ptep;
pte_t src_pte, dst_pte;
struct page *src_page, *dst_page;
retry_source:
src_ptep = virt_to_pte(current->mm, (unsigned long)source);
if (src_ptep == NULL)
break;
src_pte = *src_ptep;
if (!hv_pte_get_present(src_pte) ||
!hv_pte_get_readable(src_pte) ||
hv_pte_get_mode(src_pte) != HV_PTE_MODE_CACHE_TILE_L3)
break;
if (get_remote_cache_cpu(src_pte) == smp_processor_id())
break;
src_page = pfn_to_page(pte_pfn(src_pte));
get_page(src_page);
if (pte_val(src_pte) != pte_val(*src_ptep)) {
put_page(src_page);
goto retry_source;
}
if (pte_huge(src_pte)) {
int pfn = pte_pfn(src_pte);
pfn += (((unsigned long)source & (HPAGE_SIZE-1))
>> PAGE_SHIFT);
src_pte = pfn_pte(pfn, src_pte);
src_pte = pte_mksmall(src_pte);
}
retry_dest:
dst_ptep = virt_to_pte(current->mm, (unsigned long)dest);
if (dst_ptep == NULL) {
put_page(src_page);
break;
}
dst_pte = *dst_ptep;
if (!hv_pte_get_present(dst_pte) ||
!hv_pte_get_writable(dst_pte)) {
put_page(src_page);
break;
}
dst_page = pfn_to_page(pte_pfn(dst_pte));
if (dst_page == src_page) {
put_page(src_page);
break;
}
get_page(dst_page);
if (pte_val(dst_pte) != pte_val(*dst_ptep)) {
put_page(dst_page);
goto retry_dest;
}
if (pte_huge(dst_pte)) {
int pfn = pte_pfn(dst_pte);
pfn += (((unsigned long)dest & (HPAGE_SIZE-1))
>> PAGE_SHIFT);
dst_pte = pfn_pte(pfn, dst_pte);
dst_pte = pte_mksmall(dst_pte);
}
copy_size = len;
bytes_left_on_page =
PAGE_SIZE - (((int)source) & (PAGE_SIZE-1));
if (copy_size > bytes_left_on_page)
copy_size = bytes_left_on_page;
bytes_left_on_page =
PAGE_SIZE - (((int)dest) & (PAGE_SIZE-1));
if (copy_size > bytes_left_on_page)
copy_size = bytes_left_on_page;
memcpy_multicache(dest, source, dst_pte, src_pte, copy_size);
put_page(dst_page);
put_page(src_page);
dest += copy_size;
source += copy_size;
len -= copy_size;
}
return func(dest, source, len);
}
void *memcpy(void *to, const void *from, __kernel_size_t n)
{
if (n < LARGE_COPY_CUTOFF)
return (void *)__memcpy_asm(to, from, n);
else
return (void *)fast_copy(to, from, n, __memcpy_asm);
}
unsigned long __copy_to_user_inatomic(void __user *to, const void *from,
unsigned long n)
{
if (n < LARGE_COPY_CUTOFF)
return __copy_to_user_inatomic_asm(to, from, n);
else
return fast_copy(to, from, n, __copy_to_user_inatomic_asm);
}
unsigned long __copy_from_user_inatomic(void *to, const void __user *from,
unsigned long n)
{
if (n < LARGE_COPY_CUTOFF)
return __copy_from_user_inatomic_asm(to, from, n);
else
return fast_copy(to, from, n, __copy_from_user_inatomic_asm);
}
unsigned long __copy_from_user_zeroing(void *to, const void __user *from,
unsigned long n)
{
if (n < LARGE_COPY_CUTOFF)
return __copy_from_user_zeroing_asm(to, from, n);
else
return fast_copy(to, from, n, __copy_from_user_zeroing_asm);
}
