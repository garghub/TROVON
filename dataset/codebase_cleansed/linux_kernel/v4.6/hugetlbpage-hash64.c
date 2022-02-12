int __hash_page_huge(unsigned long ea, unsigned long access, unsigned long vsid,
pte_t *ptep, unsigned long trap, unsigned long flags,
int ssize, unsigned int shift, unsigned int mmu_psize)
{
unsigned long vpn;
unsigned long old_pte, new_pte;
unsigned long rflags, pa, sz;
long slot;
BUG_ON(shift != mmu_psize_defs[mmu_psize].shift);
vpn = hpt_vpn(ea, vsid, ssize);
do {
old_pte = pte_val(*ptep);
if (unlikely(old_pte & _PAGE_BUSY))
return 0;
if (unlikely(access & ~old_pte))
return 1;
new_pte = old_pte | _PAGE_BUSY | _PAGE_ACCESSED;
if (access & _PAGE_RW)
new_pte |= _PAGE_DIRTY;
} while(old_pte != __cmpxchg_u64((unsigned long *)ptep,
old_pte, new_pte));
rflags = htab_convert_pte_flags(new_pte);
sz = ((1UL) << shift);
if (!cpu_has_feature(CPU_FTR_COHERENT_ICACHE))
rflags = hash_page_do_lazy_icache(rflags, __pte(old_pte), trap);
if (unlikely(old_pte & _PAGE_HASHPTE)) {
unsigned long hash, slot;
hash = hpt_hash(vpn, shift, ssize);
if (old_pte & _PAGE_F_SECOND)
hash = ~hash;
slot = (hash & htab_hash_mask) * HPTES_PER_GROUP;
slot += (old_pte & _PAGE_F_GIX) >> _PAGE_F_GIX_SHIFT;
if (ppc_md.hpte_updatepp(slot, rflags, vpn, mmu_psize,
mmu_psize, ssize, flags) == -1)
old_pte &= ~_PAGE_HPTEFLAGS;
}
if (likely(!(old_pte & _PAGE_HASHPTE))) {
unsigned long hash = hpt_hash(vpn, shift, ssize);
pa = pte_pfn(__pte(old_pte)) << PAGE_SHIFT;
new_pte = (new_pte & ~_PAGE_HPTEFLAGS) | _PAGE_HASHPTE;
slot = hpte_insert_repeating(hash, vpn, pa, rflags, 0,
mmu_psize, ssize);
if (unlikely(slot == -2)) {
*ptep = __pte(old_pte);
hash_failure_debug(ea, access, vsid, trap, ssize,
mmu_psize, mmu_psize, old_pte);
return -1;
}
new_pte |= (slot << _PAGE_F_GIX_SHIFT) &
(_PAGE_F_SECOND | _PAGE_F_GIX);
}
*ptep = __pte(new_pte & ~_PAGE_BUSY);
return 0;
}
int hugepd_ok(hugepd_t hpd)
{
bool is_hugepd;
is_hugepd = (((hpd.pd & 0x3) == 0x0) && ((hpd.pd & HUGEPD_SHIFT_MASK) != 0));
WARN(is_hugepd, "Found wrong page directory format\n");
return 0;
}
