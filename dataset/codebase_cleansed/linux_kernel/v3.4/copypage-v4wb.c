static void __naked
v4wb_copy_user_page(void *kto, const void *kfrom)
{
asm("\
stmfd sp!, {r4, lr} @ 2\n\
mov r2, %2 @ 1\n\
ldmia r1!, {r3, r4, ip, lr} @ 4\n\
1: mcr p15, 0, r0, c7, c6, 1 @ 1 invalidate D line\n\
stmia r0!, {r3, r4, ip, lr} @ 4\n\
ldmia r1!, {r3, r4, ip, lr} @ 4+1\n\
stmia r0!, {r3, r4, ip, lr} @ 4\n\
ldmia r1!, {r3, r4, ip, lr} @ 4\n\
mcr p15, 0, r0, c7, c6, 1 @ 1 invalidate D line\n\
stmia r0!, {r3, r4, ip, lr} @ 4\n\
ldmia r1!, {r3, r4, ip, lr} @ 4\n\
subs r2, r2, #1 @ 1\n\
stmia r0!, {r3, r4, ip, lr} @ 4\n\
ldmneia r1!, {r3, r4, ip, lr} @ 4\n\
bne 1b @ 1\n\
mcr p15, 0, r1, c7, c10, 4 @ 1 drain WB\n\
ldmfd sp!, {r4, pc} @ 3"
:
: "r" (kto), "r" (kfrom), "I" (PAGE_SIZE / 64));
}
void v4wb_copy_user_highpage(struct page *to, struct page *from,
unsigned long vaddr, struct vm_area_struct *vma)
{
void *kto, *kfrom;
kto = kmap_atomic(to);
kfrom = kmap_atomic(from);
flush_cache_page(vma, vaddr, page_to_pfn(from));
v4wb_copy_user_page(kto, kfrom);
kunmap_atomic(kfrom);
kunmap_atomic(kto);
}
void v4wb_clear_user_highpage(struct page *page, unsigned long vaddr)
{
void *ptr, *kaddr = kmap_atomic(page);
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
bne 1b @ 1\n\
mcr p15, 0, r1, c7, c10, 4 @ 1 drain WB"
: "=r" (ptr)
: "0" (kaddr), "I" (PAGE_SIZE / 64)
: "r1", "r2", "r3", "ip", "lr");
kunmap_atomic(kaddr);
}
