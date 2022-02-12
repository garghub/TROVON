static void invalidate_old_hpte(unsigned long vsid, unsigned long addr,
pmd_t *pmdp, unsigned int psize, int ssize)
{
int i, max_hpte_count, valid;
unsigned long s_addr;
unsigned char *hpte_slot_array;
unsigned long hidx, shift, vpn, hash, slot;
s_addr = addr & HPAGE_PMD_MASK;
hpte_slot_array = get_hpte_slot_array(pmdp);
if (!hpte_slot_array)
return;
if (ppc_md.hugepage_invalidate)
return ppc_md.hugepage_invalidate(vsid, s_addr, hpte_slot_array,
psize, ssize);
shift = mmu_psize_defs[psize].shift;
max_hpte_count = HPAGE_PMD_SIZE >> shift;
for (i = 0; i < max_hpte_count; i++) {
valid = hpte_valid(hpte_slot_array, i);
if (!valid)
continue;
hidx = hpte_hash_index(hpte_slot_array, i);
addr = s_addr + (i * (1ul << shift));
vpn = hpt_vpn(addr, vsid, ssize);
hash = hpt_hash(vpn, shift, ssize);
if (hidx & _PTEIDX_SECONDARY)
hash = ~hash;
slot = (hash & htab_hash_mask) * HPTES_PER_GROUP;
slot += hidx & _PTEIDX_GROUP_IX;
ppc_md.hpte_invalidate(slot, vpn, psize,
MMU_PAGE_16M, ssize, 0);
}
}
int __hash_page_thp(unsigned long ea, unsigned long access, unsigned long vsid,
pmd_t *pmdp, unsigned long trap, int local, int ssize,
unsigned int psize)
{
unsigned int index, valid;
unsigned char *hpte_slot_array;
unsigned long rflags, pa, hidx;
unsigned long old_pmd, new_pmd;
int ret, lpsize = MMU_PAGE_16M;
unsigned long vpn, hash, shift, slot;
do {
pmd_t pmd = ACCESS_ONCE(*pmdp);
old_pmd = pmd_val(pmd);
if (unlikely(old_pmd & _PAGE_BUSY))
return 0;
if (unlikely(old_pmd & _PAGE_SPLITTING))
return 0;
if (unlikely(access & ~old_pmd))
return 1;
new_pmd = old_pmd | _PAGE_BUSY | _PAGE_ACCESSED;
if (access & _PAGE_RW)
new_pmd |= _PAGE_DIRTY;
} while (old_pmd != __cmpxchg_u64((unsigned long *)pmdp,
old_pmd, new_pmd));
rflags = new_pmd & _PAGE_USER;
if ((new_pmd & _PAGE_USER) && !((new_pmd & _PAGE_RW) &&
(new_pmd & _PAGE_DIRTY)))
rflags |= 0x1;
rflags |= ((new_pmd & _PAGE_EXEC) ? 0 : HPTE_R_N);
#if 0
if (!cpu_has_feature(CPU_FTR_COHERENT_ICACHE)) {
rflags = hash_page_do_lazy_icache(rflags, __pte(old_pte), trap);
}
#endif
shift = mmu_psize_defs[psize].shift;
index = (ea & ~HPAGE_PMD_MASK) >> shift;
BUG_ON(index >= 4096);
vpn = hpt_vpn(ea, vsid, ssize);
hash = hpt_hash(vpn, shift, ssize);
hpte_slot_array = get_hpte_slot_array(pmdp);
if (psize == MMU_PAGE_4K) {
if ((old_pmd & _PAGE_HASHPTE) && !(old_pmd & _PAGE_COMBO))
invalidate_old_hpte(vsid, ea, pmdp, MMU_PAGE_64K, ssize);
}
valid = hpte_valid(hpte_slot_array, index);
if (valid) {
hidx = hpte_hash_index(hpte_slot_array, index);
if (hidx & _PTEIDX_SECONDARY)
hash = ~hash;
slot = (hash & htab_hash_mask) * HPTES_PER_GROUP;
slot += hidx & _PTEIDX_GROUP_IX;
ret = ppc_md.hpte_updatepp(slot, rflags, vpn,
psize, lpsize, ssize, local);
if (ret == -1) {
valid = 0;
hpte_slot_array[index] = 0;
}
}
if (!valid) {
unsigned long hpte_group;
pa = pmd_pfn(__pmd(old_pmd)) << PAGE_SHIFT;
new_pmd |= _PAGE_HASHPTE;
rflags |= (new_pmd & (_PAGE_WRITETHRU | _PAGE_NO_CACHE |
_PAGE_GUARDED));
rflags |= HPTE_R_M;
repeat:
hpte_group = ((hash & htab_hash_mask) * HPTES_PER_GROUP) & ~0x7UL;
slot = ppc_md.hpte_insert(hpte_group, vpn, pa, rflags, 0,
psize, lpsize, ssize);
if (unlikely(slot == -1)) {
hpte_group = ((~hash & htab_hash_mask) *
HPTES_PER_GROUP) & ~0x7UL;
slot = ppc_md.hpte_insert(hpte_group, vpn, pa,
rflags, HPTE_V_SECONDARY,
psize, lpsize, ssize);
if (slot == -1) {
if (mftb() & 0x1)
hpte_group = ((hash & htab_hash_mask) *
HPTES_PER_GROUP) & ~0x7UL;
ppc_md.hpte_remove(hpte_group);
goto repeat;
}
}
if (unlikely(slot == -2)) {
*pmdp = __pmd(old_pmd);
hash_failure_debug(ea, access, vsid, trap, ssize,
psize, lpsize, old_pmd);
return -1;
}
mark_hpte_slot_valid(hpte_slot_array, index, slot);
}
if (psize == MMU_PAGE_4K)
new_pmd |= _PAGE_COMBO;
smp_wmb();
*pmdp = __pmd(new_pmd & ~_PAGE_BUSY);
return 0;
}
