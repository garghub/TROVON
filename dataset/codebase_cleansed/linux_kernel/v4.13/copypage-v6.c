static void v6_copy_user_highpage_nonaliasing(struct page *to,
struct page *from, unsigned long vaddr, struct vm_area_struct *vma)
{
void *kto, *kfrom;
kfrom = kmap_atomic(from);
kto = kmap_atomic(to);
copy_page(kto, kfrom);
kunmap_atomic(kto);
kunmap_atomic(kfrom);
}
static void v6_clear_user_highpage_nonaliasing(struct page *page, unsigned long vaddr)
{
void *kaddr = kmap_atomic(page);
clear_page(kaddr);
kunmap_atomic(kaddr);
}
static void discard_old_kernel_data(void *kto)
{
__asm__("mcrr p15, 0, %1, %0, c6 @ 0xec401f06"
:
: "r" (kto),
"r" ((unsigned long)kto + PAGE_SIZE - 1)
: "cc");
}
static void v6_copy_user_highpage_aliasing(struct page *to,
struct page *from, unsigned long vaddr, struct vm_area_struct *vma)
{
unsigned int offset = CACHE_COLOUR(vaddr);
unsigned long kfrom, kto;
if (!test_and_set_bit(PG_dcache_clean, &from->flags))
__flush_dcache_page(page_mapping(from), from);
discard_old_kernel_data(page_address(to));
raw_spin_lock(&v6_lock);
kfrom = COPYPAGE_V6_FROM + (offset << PAGE_SHIFT);
kto = COPYPAGE_V6_TO + (offset << PAGE_SHIFT);
set_top_pte(kfrom, mk_pte(from, PAGE_KERNEL));
set_top_pte(kto, mk_pte(to, PAGE_KERNEL));
copy_page((void *)kto, (void *)kfrom);
raw_spin_unlock(&v6_lock);
}
static void v6_clear_user_highpage_aliasing(struct page *page, unsigned long vaddr)
{
unsigned long to = COPYPAGE_V6_TO + (CACHE_COLOUR(vaddr) << PAGE_SHIFT);
discard_old_kernel_data(page_address(page));
raw_spin_lock(&v6_lock);
set_top_pte(to, mk_pte(page, PAGE_KERNEL));
clear_page((void *)to);
raw_spin_unlock(&v6_lock);
}
static int __init v6_userpage_init(void)
{
if (cache_is_vipt_aliasing()) {
cpu_user.cpu_clear_user_highpage = v6_clear_user_highpage_aliasing;
cpu_user.cpu_copy_user_highpage = v6_copy_user_highpage_aliasing;
}
return 0;
}
