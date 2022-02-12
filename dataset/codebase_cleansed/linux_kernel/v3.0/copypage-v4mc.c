static void __naked
mc_copy_user_page(void *from, void *to)
{
asm volatile(
"stmfd sp!, {r4, lr} @ 2\n\
mov r4, %2 @ 1\n\
ldmia %0!, {r2, r3, ip, lr} @ 4\n\
1: mcr p15, 0, %1, c7, c6, 1 @ 1 invalidate D line\n\
stmia %1!, {r2, r3, ip, lr} @ 4\n\
ldmia %0!, {r2, r3, ip, lr} @ 4+1\n\
stmia %1!, {r2, r3, ip, lr} @ 4\n\
ldmia %0!, {r2, r3, ip, lr} @ 4\n\
mcr p15, 0, %1, c7, c6, 1 @ 1 invalidate D line\n\
stmia %1!, {r2, r3, ip, lr} @ 4\n\
ldmia %0!, {r2, r3, ip, lr} @ 4\n\
subs r4, r4, #1 @ 1\n\
stmia %1!, {r2, r3, ip, lr} @ 4\n\
ldmneia %0!, {r2, r3, ip, lr} @ 4\n\
bne 1b @ 1\n\
ldmfd sp!, {r4, pc} @ 3"
:
: "r" (from), "r" (to), "I" (PAGE_SIZE / 64));
}
void v4_mc_copy_user_highpage(struct page *to, struct page *from,
unsigned long vaddr, struct vm_area_struct *vma)
{
void *kto = kmap_atomic(to, KM_USER1);
if (!test_and_set_bit(PG_dcache_clean, &from->flags))
__flush_dcache_page(page_mapping(from), from);
spin_lock(&minicache_lock);
set_pte_ext(TOP_PTE(0xffff8000), pfn_pte(page_to_pfn(from), minicache_pgprot), 0);
flush_tlb_kernel_page(0xffff8000);
mc_copy_user_page((void *)0xffff8000, kto);
spin_unlock(&minicache_lock);
kunmap_atomic(kto, KM_USER1);
}
void v4_mc_clear_user_highpage(struct page *page, unsigned long vaddr)
{
void *ptr, *kaddr = kmap_atomic(page, KM_USER0);
asm volatile("\
mov r1, %2 @ 1\n\
mov r2, #0 @ 1\n\
mov r3, #0 @ 1\n\
mov ip, #0 @ 1\n\
mov lr, #0 @ 1\n\
1: mcr p15, 0, %0, c7, c6, 1 @ 1 invalidate D line\n\
stmia %0!, {r2, r3, ip, lr} @ 4\n\
stmia %0!, {r2, r3, ip, lr} @ 4\n\
mcr p15, 0, %0, c7, c6, 1 @ 1 invalidate D line\n\
stmia %0!, {r2, r3, ip, lr} @ 4\n\
stmia %0!, {r2, r3, ip, lr} @ 4\n\
subs r1, r1, #1 @ 1\n\
bne 1b @ 1"
: "=r" (ptr)
: "0" (kaddr), "I" (PAGE_SIZE / 64)
: "r1", "r2", "r3", "ip", "lr");
kunmap_atomic(kaddr, KM_USER0);
}
