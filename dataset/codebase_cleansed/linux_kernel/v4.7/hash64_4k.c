int __hash_page_4K(unsigned long ea, unsigned long access, unsigned long vsid,
pte_t *ptep, unsigned long trap, unsigned long flags,
int ssize, int subpg_prot)
{
unsigned long hpte_group;
unsigned long rflags, pa;
unsigned long old_pte, new_pte;
unsigned long vpn, hash, slot;
unsigned long shift = mmu_psize_defs[MMU_PAGE_4K].shift;
do {
pte_t pte = READ_ONCE(*ptep);
old_pte = pte_val(pte);
if (unlikely(old_pte & H_PAGE_BUSY))
return 0;
if (unlikely(!check_pte_access(access, old_pte)))
return 1;
new_pte = old_pte | H_PAGE_BUSY | _PAGE_ACCESSED;
if (access & _PAGE_WRITE)
new_pte |= _PAGE_DIRTY;
} while (!pte_xchg(ptep, __pte(old_pte), __pte(new_pte)));
rflags = htab_convert_pte_flags(new_pte);
if (!cpu_has_feature(CPU_FTR_NOEXECUTE) &&
!cpu_has_feature(CPU_FTR_COHERENT_ICACHE))
rflags = hash_page_do_lazy_icache(rflags, __pte(old_pte), trap);
vpn = hpt_vpn(ea, vsid, ssize);
if (unlikely(old_pte & H_PAGE_HASHPTE)) {
hash = hpt_hash(vpn, shift, ssize);
if (old_pte & H_PAGE_F_SECOND)
hash = ~hash;
slot = (hash & htab_hash_mask) * HPTES_PER_GROUP;
slot += (old_pte & H_PAGE_F_GIX) >> H_PAGE_F_GIX_SHIFT;
if (ppc_md.hpte_updatepp(slot, rflags, vpn, MMU_PAGE_4K,
MMU_PAGE_4K, ssize, flags) == -1)
old_pte &= ~_PAGE_HPTEFLAGS;
}
if (likely(!(old_pte & H_PAGE_HASHPTE))) {
pa = pte_pfn(__pte(old_pte)) << PAGE_SHIFT;
hash = hpt_hash(vpn, shift, ssize);
repeat:
hpte_group = ((hash & htab_hash_mask) * HPTES_PER_GROUP) & ~0x7UL;
slot = ppc_md.hpte_insert(hpte_group, vpn, pa, rflags, 0,
MMU_PAGE_4K, MMU_PAGE_4K, ssize);
if (unlikely(slot == -1)) {
hpte_group = ((~hash & htab_hash_mask) * HPTES_PER_GROUP) & ~0x7UL;
slot = ppc_md.hpte_insert(hpte_group, vpn, pa,
rflags, HPTE_V_SECONDARY,
MMU_PAGE_4K, MMU_PAGE_4K, ssize);
if (slot == -1) {
if (mftb() & 0x1)
hpte_group = ((hash & htab_hash_mask) *
HPTES_PER_GROUP) & ~0x7UL;
ppc_md.hpte_remove(hpte_group);
goto repeat;
}
}
if (unlikely(slot == -2)) {
*ptep = __pte(old_pte);
hash_failure_debug(ea, access, vsid, trap, ssize,
MMU_PAGE_4K, MMU_PAGE_4K, old_pte);
return -1;
}
new_pte = (new_pte & ~_PAGE_HPTEFLAGS) | H_PAGE_HASHPTE;
new_pte |= (slot << H_PAGE_F_GIX_SHIFT) &
(H_PAGE_F_SECOND | H_PAGE_F_GIX);
}
*ptep = __pte(new_pte & ~H_PAGE_BUSY);
return 0;
}
