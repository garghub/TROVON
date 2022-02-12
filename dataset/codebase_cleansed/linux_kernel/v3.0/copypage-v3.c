static void __naked
v3_copy_user_page(void *kto, const void *kfrom)
{
asm("\n\
stmfd sp!, {r4, lr} @ 2\n\
mov r2, %2 @ 1\n\
ldmia %0!, {r3, r4, ip, lr} @ 4+1\n\
1: stmia %1!, {r3, r4, ip, lr} @ 4\n\
ldmia %0!, {r3, r4, ip, lr} @ 4+1\n\
stmia %1!, {r3, r4, ip, lr} @ 4\n\
ldmia %0!, {r3, r4, ip, lr} @ 4+1\n\
stmia %1!, {r3, r4, ip, lr} @ 4\n\
ldmia %0!, {r3, r4, ip, lr} @ 4\n\
subs r2, r2, #1 @ 1\n\
stmia %1!, {r3, r4, ip, lr} @ 4\n\
ldmneia %0!, {r3, r4, ip, lr} @ 4\n\
bne 1b @ 1\n\
ldmfd sp!, {r4, pc} @ 3"
:
: "r" (kfrom), "r" (kto), "I" (PAGE_SIZE / 64));
}
void v3_copy_user_highpage(struct page *to, struct page *from,
unsigned long vaddr, struct vm_area_struct *vma)
{
void *kto, *kfrom;
kto = kmap_atomic(to, KM_USER0);
kfrom = kmap_atomic(from, KM_USER1);
v3_copy_user_page(kto, kfrom);
kunmap_atomic(kfrom, KM_USER1);
kunmap_atomic(kto, KM_USER0);
}
void v3_clear_user_highpage(struct page *page, unsigned long vaddr)
{
void *ptr, *kaddr = kmap_atomic(page, KM_USER0);
asm volatile("\n\
mov r1, %2 @ 1\n\
mov r2, #0 @ 1\n\
mov r3, #0 @ 1\n\
mov ip, #0 @ 1\n\
mov lr, #0 @ 1\n\
1: stmia %0!, {r2, r3, ip, lr} @ 4\n\
stmia %0!, {r2, r3, ip, lr} @ 4\n\
stmia %0!, {r2, r3, ip, lr} @ 4\n\
stmia %0!, {r2, r3, ip, lr} @ 4\n\
subs r1, r1, #1 @ 1\n\
bne 1b @ 1"
: "=r" (ptr)
: "0" (kaddr), "I" (PAGE_SIZE / 64)
: "r1", "r2", "r3", "ip", "lr");
kunmap_atomic(kaddr, KM_USER0);
}
