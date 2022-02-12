static void __naked
fa_copy_user_page(void *kto, const void *kfrom)
{
asm("\
stmfd sp!, {r4, lr} @ 2\n\
mov r2, %0 @ 1\n\
1: ldmia r1!, {r3, r4, ip, lr} @ 4\n\
stmia r0, {r3, r4, ip, lr} @ 4\n\
mcr p15, 0, r0, c7, c14, 1 @ 1 clean and invalidate D line\n\
add r0, r0, #16 @ 1\n\
ldmia r1!, {r3, r4, ip, lr} @ 4\n\
stmia r0, {r3, r4, ip, lr} @ 4\n\
mcr p15, 0, r0, c7, c14, 1 @ 1 clean and invalidate D line\n\
add r0, r0, #16 @ 1\n\
subs r2, r2, #1 @ 1\n\
bne 1b @ 1\n\
mcr p15, 0, r2, c7, c10, 4 @ 1 drain WB\n\
ldmfd sp!, {r4, pc} @ 3"
:
: "I" (PAGE_SIZE / 32));
}
void fa_copy_user_highpage(struct page *to, struct page *from,
unsigned long vaddr, struct vm_area_struct *vma)
{
void *kto, *kfrom;
kto = kmap_atomic(to);
kfrom = kmap_atomic(from);
fa_copy_user_page(kto, kfrom);
kunmap_atomic(kfrom);
kunmap_atomic(kto);
}
void fa_clear_user_highpage(struct page *page, unsigned long vaddr)
{
void *ptr, *kaddr = kmap_atomic(page);
asm volatile("\
mov r1, %2 @ 1\n\
mov r2, #0 @ 1\n\
mov r3, #0 @ 1\n\
mov ip, #0 @ 1\n\
mov lr, #0 @ 1\n\
1: stmia %0, {r2, r3, ip, lr} @ 4\n\
mcr p15, 0, %0, c7, c14, 1 @ 1 clean and invalidate D line\n\
add %0, %0, #16 @ 1\n\
stmia %0, {r2, r3, ip, lr} @ 4\n\
mcr p15, 0, %0, c7, c14, 1 @ 1 clean and invalidate D line\n\
add %0, %0, #16 @ 1\n\
subs r1, r1, #1 @ 1\n\
bne 1b @ 1\n\
mcr p15, 0, r1, c7, c10, 4 @ 1 drain WB"
: "=r" (ptr)
: "0" (kaddr), "I" (PAGE_SIZE / 32)
: "r1", "r2", "r3", "ip", "lr");
kunmap_atomic(kaddr);
}
