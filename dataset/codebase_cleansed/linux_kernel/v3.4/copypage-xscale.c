static void __naked
mc_copy_user_page(void *from, void *to)
{
asm volatile(
"stmfd sp!, {r4, r5, lr} \n\
mov lr, %2 \n\
pld [r0, #0] \n\
pld [r0, #32] \n\
pld [r1, #0] \n\
pld [r1, #32] \n\
1: pld [r0, #64] \n\
pld [r0, #96] \n\
pld [r1, #64] \n\
pld [r1, #96] \n\
2: ldrd r2, [r0], #8 \n\
ldrd r4, [r0], #8 \n\
mov ip, r1 \n\
strd r2, [r1], #8 \n\
ldrd r2, [r0], #8 \n\
strd r4, [r1], #8 \n\
ldrd r4, [r0], #8 \n\
strd r2, [r1], #8 \n\
strd r4, [r1], #8 \n\
mcr p15, 0, ip, c7, c10, 1 @ clean D line\n\
ldrd r2, [r0], #8 \n\
mcr p15, 0, ip, c7, c6, 1 @ invalidate D line\n\
ldrd r4, [r0], #8 \n\
mov ip, r1 \n\
strd r2, [r1], #8 \n\
ldrd r2, [r0], #8 \n\
strd r4, [r1], #8 \n\
ldrd r4, [r0], #8 \n\
strd r2, [r1], #8 \n\
strd r4, [r1], #8 \n\
mcr p15, 0, ip, c7, c10, 1 @ clean D line\n\
subs lr, lr, #1 \n\
mcr p15, 0, ip, c7, c6, 1 @ invalidate D line\n\
bgt 1b \n\
beq 2b \n\
ldmfd sp!, {r4, r5, pc} "
:
: "r" (from), "r" (to), "I" (PAGE_SIZE / 64 - 1));
}
void xscale_mc_copy_user_highpage(struct page *to, struct page *from,
unsigned long vaddr, struct vm_area_struct *vma)
{
void *kto = kmap_atomic(to);
if (!test_and_set_bit(PG_dcache_clean, &from->flags))
__flush_dcache_page(page_mapping(from), from);
raw_spin_lock(&minicache_lock);
set_top_pte(COPYPAGE_MINICACHE, mk_pte(from, minicache_pgprot));
mc_copy_user_page((void *)COPYPAGE_MINICACHE, kto);
raw_spin_unlock(&minicache_lock);
kunmap_atomic(kto);
}
void
xscale_mc_clear_user_highpage(struct page *page, unsigned long vaddr)
{
void *ptr, *kaddr = kmap_atomic(page);
asm volatile(
"mov r1, %2 \n\
mov r2, #0 \n\
mov r3, #0 \n\
1: mov ip, %0 \n\
strd r2, [%0], #8 \n\
strd r2, [%0], #8 \n\
strd r2, [%0], #8 \n\
strd r2, [%0], #8 \n\
mcr p15, 0, ip, c7, c10, 1 @ clean D line\n\
subs r1, r1, #1 \n\
mcr p15, 0, ip, c7, c6, 1 @ invalidate D line\n\
bne 1b"
: "=r" (ptr)
: "0" (kaddr), "I" (PAGE_SIZE / 32)
: "r1", "r2", "r3", "ip");
kunmap_atomic(kaddr);
}
