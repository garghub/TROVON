static int mmu_topup_memory_cache(struct kvm_mmu_memory_cache *cache,
int min, int max)
{
void *page;
BUG_ON(max > KVM_NR_MEM_OBJS);
if (cache->nobjs >= min)
return 0;
while (cache->nobjs < max) {
page = (void *)__get_free_page(GFP_KERNEL);
if (!page)
return -ENOMEM;
cache->objects[cache->nobjs++] = page;
}
return 0;
}
static void mmu_free_memory_cache(struct kvm_mmu_memory_cache *mc)
{
while (mc->nobjs)
free_page((unsigned long)mc->objects[--mc->nobjs]);
}
static void *mmu_memory_cache_alloc(struct kvm_mmu_memory_cache *mc)
{
void *p;
BUG_ON(!mc || !mc->nobjs);
p = mc->objects[--mc->nobjs];
return p;
}
void kvm_mmu_free_memory_caches(struct kvm_vcpu *vcpu)
{
mmu_free_memory_cache(&vcpu->arch.mmu_page_cache);
}
static void kvm_pgd_init(void *page)
{
unsigned long *p, *end;
unsigned long entry;
#ifdef __PAGETABLE_PMD_FOLDED
entry = (unsigned long)invalid_pte_table;
#else
entry = (unsigned long)invalid_pmd_table;
#endif
p = (unsigned long *)page;
end = p + PTRS_PER_PGD;
do {
p[0] = entry;
p[1] = entry;
p[2] = entry;
p[3] = entry;
p[4] = entry;
p += 8;
p[-3] = entry;
p[-2] = entry;
p[-1] = entry;
} while (p != end);
}
pgd_t *kvm_pgd_alloc(void)
{
pgd_t *ret;
ret = (pgd_t *)__get_free_pages(GFP_KERNEL, PGD_ORDER);
if (ret)
kvm_pgd_init(ret);
return ret;
}
static pte_t *kvm_mips_walk_pgd(pgd_t *pgd, struct kvm_mmu_memory_cache *cache,
unsigned long addr)
{
pud_t *pud;
pmd_t *pmd;
pgd += pgd_index(addr);
if (pgd_none(*pgd)) {
BUG();
return NULL;
}
pud = pud_offset(pgd, addr);
if (pud_none(*pud)) {
pmd_t *new_pmd;
if (!cache)
return NULL;
new_pmd = mmu_memory_cache_alloc(cache);
pmd_init((unsigned long)new_pmd,
(unsigned long)invalid_pte_table);
pud_populate(NULL, pud, new_pmd);
}
pmd = pmd_offset(pud, addr);
if (pmd_none(*pmd)) {
pte_t *new_pte;
if (!cache)
return NULL;
new_pte = mmu_memory_cache_alloc(cache);
clear_page(new_pte);
pmd_populate_kernel(NULL, pmd, new_pte);
}
return pte_offset(pmd, addr);
}
static pte_t *kvm_mips_pte_for_gpa(struct kvm *kvm,
struct kvm_mmu_memory_cache *cache,
unsigned long addr)
{
return kvm_mips_walk_pgd(kvm->arch.gpa_mm.pgd, cache, addr);
}
static bool kvm_mips_flush_gpa_pte(pte_t *pte, unsigned long start_gpa,
unsigned long end_gpa)
{
int i_min = __pte_offset(start_gpa);
int i_max = __pte_offset(end_gpa);
bool safe_to_remove = (i_min == 0 && i_max == PTRS_PER_PTE - 1);
int i;
for (i = i_min; i <= i_max; ++i) {
if (!pte_present(pte[i]))
continue;
set_pte(pte + i, __pte(0));
}
return safe_to_remove;
}
static bool kvm_mips_flush_gpa_pmd(pmd_t *pmd, unsigned long start_gpa,
unsigned long end_gpa)
{
pte_t *pte;
unsigned long end = ~0ul;
int i_min = __pmd_offset(start_gpa);
int i_max = __pmd_offset(end_gpa);
bool safe_to_remove = (i_min == 0 && i_max == PTRS_PER_PMD - 1);
int i;
for (i = i_min; i <= i_max; ++i, start_gpa = 0) {
if (!pmd_present(pmd[i]))
continue;
pte = pte_offset(pmd + i, 0);
if (i == i_max)
end = end_gpa;
if (kvm_mips_flush_gpa_pte(pte, start_gpa, end)) {
pmd_clear(pmd + i);
pte_free_kernel(NULL, pte);
} else {
safe_to_remove = false;
}
}
return safe_to_remove;
}
static bool kvm_mips_flush_gpa_pud(pud_t *pud, unsigned long start_gpa,
unsigned long end_gpa)
{
pmd_t *pmd;
unsigned long end = ~0ul;
int i_min = __pud_offset(start_gpa);
int i_max = __pud_offset(end_gpa);
bool safe_to_remove = (i_min == 0 && i_max == PTRS_PER_PUD - 1);
int i;
for (i = i_min; i <= i_max; ++i, start_gpa = 0) {
if (!pud_present(pud[i]))
continue;
pmd = pmd_offset(pud + i, 0);
if (i == i_max)
end = end_gpa;
if (kvm_mips_flush_gpa_pmd(pmd, start_gpa, end)) {
pud_clear(pud + i);
pmd_free(NULL, pmd);
} else {
safe_to_remove = false;
}
}
return safe_to_remove;
}
static bool kvm_mips_flush_gpa_pgd(pgd_t *pgd, unsigned long start_gpa,
unsigned long end_gpa)
{
pud_t *pud;
unsigned long end = ~0ul;
int i_min = pgd_index(start_gpa);
int i_max = pgd_index(end_gpa);
bool safe_to_remove = (i_min == 0 && i_max == PTRS_PER_PGD - 1);
int i;
for (i = i_min; i <= i_max; ++i, start_gpa = 0) {
if (!pgd_present(pgd[i]))
continue;
pud = pud_offset(pgd + i, 0);
if (i == i_max)
end = end_gpa;
if (kvm_mips_flush_gpa_pud(pud, start_gpa, end)) {
pgd_clear(pgd + i);
pud_free(NULL, pud);
} else {
safe_to_remove = false;
}
}
return safe_to_remove;
}
bool kvm_mips_flush_gpa_pt(struct kvm *kvm, gfn_t start_gfn, gfn_t end_gfn)
{
return kvm_mips_flush_gpa_pgd(kvm->arch.gpa_mm.pgd,
start_gfn << PAGE_SHIFT,
end_gfn << PAGE_SHIFT);
}
int kvm_mips_mkclean_gpa_pt(struct kvm *kvm, gfn_t start_gfn, gfn_t end_gfn)
{
return kvm_mips_mkclean_pgd(kvm->arch.gpa_mm.pgd,
start_gfn << PAGE_SHIFT,
end_gfn << PAGE_SHIFT);
}
void kvm_arch_mmu_enable_log_dirty_pt_masked(struct kvm *kvm,
struct kvm_memory_slot *slot,
gfn_t gfn_offset, unsigned long mask)
{
gfn_t base_gfn = slot->base_gfn + gfn_offset;
gfn_t start = base_gfn + __ffs(mask);
gfn_t end = base_gfn + __fls(mask);
kvm_mips_mkclean_gpa_pt(kvm, start, end);
}
static int kvm_mips_mkold_gpa_pt(struct kvm *kvm, gfn_t start_gfn,
gfn_t end_gfn)
{
return kvm_mips_mkold_pgd(kvm->arch.gpa_mm.pgd,
start_gfn << PAGE_SHIFT,
end_gfn << PAGE_SHIFT);
}
static int handle_hva_to_gpa(struct kvm *kvm,
unsigned long start,
unsigned long end,
int (*handler)(struct kvm *kvm, gfn_t gfn,
gpa_t gfn_end,
struct kvm_memory_slot *memslot,
void *data),
void *data)
{
struct kvm_memslots *slots;
struct kvm_memory_slot *memslot;
int ret = 0;
slots = kvm_memslots(kvm);
kvm_for_each_memslot(memslot, slots) {
unsigned long hva_start, hva_end;
gfn_t gfn, gfn_end;
hva_start = max(start, memslot->userspace_addr);
hva_end = min(end, memslot->userspace_addr +
(memslot->npages << PAGE_SHIFT));
if (hva_start >= hva_end)
continue;
gfn = hva_to_gfn_memslot(hva_start, memslot);
gfn_end = hva_to_gfn_memslot(hva_end + PAGE_SIZE - 1, memslot);
ret |= handler(kvm, gfn, gfn_end, memslot, data);
}
return ret;
}
static int kvm_unmap_hva_handler(struct kvm *kvm, gfn_t gfn, gfn_t gfn_end,
struct kvm_memory_slot *memslot, void *data)
{
kvm_mips_flush_gpa_pt(kvm, gfn, gfn_end);
return 1;
}
int kvm_unmap_hva(struct kvm *kvm, unsigned long hva)
{
unsigned long end = hva + PAGE_SIZE;
handle_hva_to_gpa(kvm, hva, end, &kvm_unmap_hva_handler, NULL);
kvm_mips_callbacks->flush_shadow_all(kvm);
return 0;
}
int kvm_unmap_hva_range(struct kvm *kvm, unsigned long start, unsigned long end)
{
handle_hva_to_gpa(kvm, start, end, &kvm_unmap_hva_handler, NULL);
kvm_mips_callbacks->flush_shadow_all(kvm);
return 0;
}
static int kvm_set_spte_handler(struct kvm *kvm, gfn_t gfn, gfn_t gfn_end,
struct kvm_memory_slot *memslot, void *data)
{
gpa_t gpa = gfn << PAGE_SHIFT;
pte_t hva_pte = *(pte_t *)data;
pte_t *gpa_pte = kvm_mips_pte_for_gpa(kvm, NULL, gpa);
pte_t old_pte;
if (!gpa_pte)
return 0;
old_pte = *gpa_pte;
if (memslot->flags & KVM_MEM_LOG_DIRTY_PAGES && !pte_dirty(old_pte))
hva_pte = pte_mkclean(hva_pte);
else if (memslot->flags & KVM_MEM_READONLY)
hva_pte = pte_wrprotect(hva_pte);
set_pte(gpa_pte, hva_pte);
if (!pte_present(old_pte) || !pte_young(old_pte))
return 0;
return !pte_present(hva_pte) ||
!pte_young(hva_pte) ||
pte_pfn(old_pte) != pte_pfn(hva_pte) ||
(pte_dirty(old_pte) && !pte_dirty(hva_pte));
}
void kvm_set_spte_hva(struct kvm *kvm, unsigned long hva, pte_t pte)
{
unsigned long end = hva + PAGE_SIZE;
int ret;
ret = handle_hva_to_gpa(kvm, hva, end, &kvm_set_spte_handler, &pte);
if (ret)
kvm_mips_callbacks->flush_shadow_all(kvm);
}
static int kvm_age_hva_handler(struct kvm *kvm, gfn_t gfn, gfn_t gfn_end,
struct kvm_memory_slot *memslot, void *data)
{
return kvm_mips_mkold_gpa_pt(kvm, gfn, gfn_end);
}
static int kvm_test_age_hva_handler(struct kvm *kvm, gfn_t gfn, gfn_t gfn_end,
struct kvm_memory_slot *memslot, void *data)
{
gpa_t gpa = gfn << PAGE_SHIFT;
pte_t *gpa_pte = kvm_mips_pte_for_gpa(kvm, NULL, gpa);
if (!gpa_pte)
return 0;
return pte_young(*gpa_pte);
}
int kvm_age_hva(struct kvm *kvm, unsigned long start, unsigned long end)
{
return handle_hva_to_gpa(kvm, start, end, kvm_age_hva_handler, NULL);
}
int kvm_test_age_hva(struct kvm *kvm, unsigned long hva)
{
return handle_hva_to_gpa(kvm, hva, hva, kvm_test_age_hva_handler, NULL);
}
static int _kvm_mips_map_page_fast(struct kvm_vcpu *vcpu, unsigned long gpa,
bool write_fault,
pte_t *out_entry, pte_t *out_buddy)
{
struct kvm *kvm = vcpu->kvm;
gfn_t gfn = gpa >> PAGE_SHIFT;
pte_t *ptep;
kvm_pfn_t pfn = 0;
bool pfn_valid = false;
int ret = 0;
spin_lock(&kvm->mmu_lock);
ptep = kvm_mips_pte_for_gpa(kvm, NULL, gpa);
if (!ptep || !pte_present(*ptep)) {
ret = -EFAULT;
goto out;
}
if (!pte_young(*ptep)) {
set_pte(ptep, pte_mkyoung(*ptep));
pfn = pte_pfn(*ptep);
pfn_valid = true;
}
if (write_fault && !pte_dirty(*ptep)) {
if (!pte_write(*ptep)) {
ret = -EFAULT;
goto out;
}
set_pte(ptep, pte_mkdirty(*ptep));
pfn = pte_pfn(*ptep);
mark_page_dirty(kvm, gfn);
kvm_set_pfn_dirty(pfn);
}
if (out_entry)
*out_entry = *ptep;
if (out_buddy)
*out_buddy = *ptep_buddy(ptep);
out:
spin_unlock(&kvm->mmu_lock);
if (pfn_valid)
kvm_set_pfn_accessed(pfn);
return ret;
}
static int kvm_mips_map_page(struct kvm_vcpu *vcpu, unsigned long gpa,
bool write_fault,
pte_t *out_entry, pte_t *out_buddy)
{
struct kvm *kvm = vcpu->kvm;
struct kvm_mmu_memory_cache *memcache = &vcpu->arch.mmu_page_cache;
gfn_t gfn = gpa >> PAGE_SHIFT;
int srcu_idx, err;
kvm_pfn_t pfn;
pte_t *ptep, entry, old_pte;
bool writeable;
unsigned long prot_bits;
unsigned long mmu_seq;
srcu_idx = srcu_read_lock(&kvm->srcu);
err = _kvm_mips_map_page_fast(vcpu, gpa, write_fault, out_entry,
out_buddy);
if (!err)
goto out;
err = mmu_topup_memory_cache(memcache, KVM_MMU_CACHE_MIN_PAGES,
KVM_NR_MEM_OBJS);
if (err)
goto out;
retry:
mmu_seq = kvm->mmu_notifier_seq;
smp_rmb();
pfn = gfn_to_pfn_prot(kvm, gfn, write_fault, &writeable);
if (is_error_noslot_pfn(pfn)) {
err = -EFAULT;
goto out;
}
spin_lock(&kvm->mmu_lock);
if (mmu_notifier_retry(kvm, mmu_seq)) {
spin_unlock(&kvm->mmu_lock);
kvm_release_pfn_clean(pfn);
goto retry;
}
ptep = kvm_mips_pte_for_gpa(kvm, memcache, gpa);
prot_bits = _PAGE_PRESENT | __READABLE | _page_cachable_default;
if (writeable) {
prot_bits |= _PAGE_WRITE;
if (write_fault) {
prot_bits |= __WRITEABLE;
mark_page_dirty(kvm, gfn);
kvm_set_pfn_dirty(pfn);
}
}
entry = pfn_pte(pfn, __pgprot(prot_bits));
old_pte = *ptep;
set_pte(ptep, entry);
err = 0;
if (out_entry)
*out_entry = *ptep;
if (out_buddy)
*out_buddy = *ptep_buddy(ptep);
spin_unlock(&kvm->mmu_lock);
kvm_release_pfn_clean(pfn);
kvm_set_pfn_accessed(pfn);
out:
srcu_read_unlock(&kvm->srcu, srcu_idx);
return err;
}
static pte_t *kvm_trap_emul_pte_for_gva(struct kvm_vcpu *vcpu,
unsigned long addr)
{
struct kvm_mmu_memory_cache *memcache = &vcpu->arch.mmu_page_cache;
pgd_t *pgdp;
int ret;
ret = mmu_topup_memory_cache(memcache, KVM_MMU_CACHE_MIN_PAGES,
KVM_NR_MEM_OBJS);
if (ret)
return NULL;
if (KVM_GUEST_KERNEL_MODE(vcpu))
pgdp = vcpu->arch.guest_kernel_mm.pgd;
else
pgdp = vcpu->arch.guest_user_mm.pgd;
return kvm_mips_walk_pgd(pgdp, memcache, addr);
}
void kvm_trap_emul_invalidate_gva(struct kvm_vcpu *vcpu, unsigned long addr,
bool user)
{
pgd_t *pgdp;
pte_t *ptep;
addr &= PAGE_MASK << 1;
pgdp = vcpu->arch.guest_kernel_mm.pgd;
ptep = kvm_mips_walk_pgd(pgdp, NULL, addr);
if (ptep) {
ptep[0] = pfn_pte(0, __pgprot(0));
ptep[1] = pfn_pte(0, __pgprot(0));
}
if (user) {
pgdp = vcpu->arch.guest_user_mm.pgd;
ptep = kvm_mips_walk_pgd(pgdp, NULL, addr);
if (ptep) {
ptep[0] = pfn_pte(0, __pgprot(0));
ptep[1] = pfn_pte(0, __pgprot(0));
}
}
}
static bool kvm_mips_flush_gva_pte(pte_t *pte, unsigned long start_gva,
unsigned long end_gva)
{
int i_min = __pte_offset(start_gva);
int i_max = __pte_offset(end_gva);
bool safe_to_remove = (i_min == 0 && i_max == PTRS_PER_PTE - 1);
int i;
if (safe_to_remove)
return true;
for (i = i_min; i <= i_max; ++i) {
if (!pte_present(pte[i]))
continue;
set_pte(pte + i, __pte(0));
}
return false;
}
static bool kvm_mips_flush_gva_pmd(pmd_t *pmd, unsigned long start_gva,
unsigned long end_gva)
{
pte_t *pte;
unsigned long end = ~0ul;
int i_min = __pmd_offset(start_gva);
int i_max = __pmd_offset(end_gva);
bool safe_to_remove = (i_min == 0 && i_max == PTRS_PER_PMD - 1);
int i;
for (i = i_min; i <= i_max; ++i, start_gva = 0) {
if (!pmd_present(pmd[i]))
continue;
pte = pte_offset(pmd + i, 0);
if (i == i_max)
end = end_gva;
if (kvm_mips_flush_gva_pte(pte, start_gva, end)) {
pmd_clear(pmd + i);
pte_free_kernel(NULL, pte);
} else {
safe_to_remove = false;
}
}
return safe_to_remove;
}
static bool kvm_mips_flush_gva_pud(pud_t *pud, unsigned long start_gva,
unsigned long end_gva)
{
pmd_t *pmd;
unsigned long end = ~0ul;
int i_min = __pud_offset(start_gva);
int i_max = __pud_offset(end_gva);
bool safe_to_remove = (i_min == 0 && i_max == PTRS_PER_PUD - 1);
int i;
for (i = i_min; i <= i_max; ++i, start_gva = 0) {
if (!pud_present(pud[i]))
continue;
pmd = pmd_offset(pud + i, 0);
if (i == i_max)
end = end_gva;
if (kvm_mips_flush_gva_pmd(pmd, start_gva, end)) {
pud_clear(pud + i);
pmd_free(NULL, pmd);
} else {
safe_to_remove = false;
}
}
return safe_to_remove;
}
static bool kvm_mips_flush_gva_pgd(pgd_t *pgd, unsigned long start_gva,
unsigned long end_gva)
{
pud_t *pud;
unsigned long end = ~0ul;
int i_min = pgd_index(start_gva);
int i_max = pgd_index(end_gva);
bool safe_to_remove = (i_min == 0 && i_max == PTRS_PER_PGD - 1);
int i;
for (i = i_min; i <= i_max; ++i, start_gva = 0) {
if (!pgd_present(pgd[i]))
continue;
pud = pud_offset(pgd + i, 0);
if (i == i_max)
end = end_gva;
if (kvm_mips_flush_gva_pud(pud, start_gva, end)) {
pgd_clear(pgd + i);
pud_free(NULL, pud);
} else {
safe_to_remove = false;
}
}
return safe_to_remove;
}
void kvm_mips_flush_gva_pt(pgd_t *pgd, enum kvm_mips_flush flags)
{
if (flags & KMF_GPA) {
if (flags & KMF_KERN)
kvm_mips_flush_gva_pgd(pgd, 0, 0x7fffffff);
else
kvm_mips_flush_gva_pgd(pgd, 0, 0x3fffffff);
} else {
kvm_mips_flush_gva_pgd(pgd, 0, 0x3fffffff);
if (flags & KMF_KERN)
kvm_mips_flush_gva_pgd(pgd, 0x60000000, 0x7fffffff);
}
}
static pte_t kvm_mips_gpa_pte_to_gva_unmapped(pte_t pte)
{
if (!pte_dirty(pte))
pte = pte_wrprotect(pte);
return pte;
}
static pte_t kvm_mips_gpa_pte_to_gva_mapped(pte_t pte, long entrylo)
{
if (!(entrylo & ENTRYLO_D))
pte = pte_mkclean(pte);
return kvm_mips_gpa_pte_to_gva_unmapped(pte);
}
int kvm_mips_handle_vz_root_tlb_fault(unsigned long badvaddr,
struct kvm_vcpu *vcpu,
bool write_fault)
{
int ret;
ret = kvm_mips_map_page(vcpu, badvaddr, write_fault, NULL, NULL);
if (ret)
return ret;
return kvm_vz_host_tlb_inv(vcpu, badvaddr);
}
int kvm_mips_handle_kseg0_tlb_fault(unsigned long badvaddr,
struct kvm_vcpu *vcpu,
bool write_fault)
{
unsigned long gpa;
pte_t pte_gpa[2], *ptep_gva;
int idx;
if (KVM_GUEST_KSEGX(badvaddr) != KVM_GUEST_KSEG0) {
kvm_err("%s: Invalid BadVaddr: %#lx\n", __func__, badvaddr);
kvm_mips_dump_host_tlbs();
return -1;
}
gpa = KVM_GUEST_CPHYSADDR(badvaddr);
idx = (badvaddr >> PAGE_SHIFT) & 1;
if (kvm_mips_map_page(vcpu, gpa, write_fault, &pte_gpa[idx],
&pte_gpa[!idx]) < 0)
return -1;
ptep_gva = kvm_trap_emul_pte_for_gva(vcpu, badvaddr & ~PAGE_SIZE);
if (!ptep_gva) {
kvm_err("No ptep for gva %lx\n", badvaddr);
return -1;
}
ptep_gva[0] = kvm_mips_gpa_pte_to_gva_unmapped(pte_gpa[0]);
ptep_gva[1] = kvm_mips_gpa_pte_to_gva_unmapped(pte_gpa[1]);
kvm_mips_host_tlb_inv(vcpu, badvaddr, false, true);
return 0;
}
int kvm_mips_handle_mapped_seg_tlb_fault(struct kvm_vcpu *vcpu,
struct kvm_mips_tlb *tlb,
unsigned long gva,
bool write_fault)
{
struct kvm *kvm = vcpu->kvm;
long tlb_lo[2];
pte_t pte_gpa[2], *ptep_buddy, *ptep_gva;
unsigned int idx = TLB_LO_IDX(*tlb, gva);
bool kernel = KVM_GUEST_KERNEL_MODE(vcpu);
tlb_lo[0] = tlb->tlb_lo[0];
tlb_lo[1] = tlb->tlb_lo[1];
if (!((gva ^ KVM_GUEST_COMMPAGE_ADDR) & VPN2_MASK & (PAGE_MASK << 1)))
tlb_lo[TLB_LO_IDX(*tlb, KVM_GUEST_COMMPAGE_ADDR)] = 0;
if (kvm_mips_map_page(vcpu, mips3_tlbpfn_to_paddr(tlb_lo[idx]),
write_fault, &pte_gpa[idx], NULL) < 0)
return -1;
pte_gpa[!idx] = pfn_pte(0, __pgprot(0));
if (tlb_lo[!idx] & ENTRYLO_V) {
spin_lock(&kvm->mmu_lock);
ptep_buddy = kvm_mips_pte_for_gpa(kvm, NULL,
mips3_tlbpfn_to_paddr(tlb_lo[!idx]));
if (ptep_buddy)
pte_gpa[!idx] = *ptep_buddy;
spin_unlock(&kvm->mmu_lock);
}
ptep_gva = kvm_trap_emul_pte_for_gva(vcpu, gva & ~PAGE_SIZE);
if (!ptep_gva) {
kvm_err("No ptep for gva %lx\n", gva);
return -1;
}
ptep_gva[0] = kvm_mips_gpa_pte_to_gva_mapped(pte_gpa[0], tlb_lo[0]);
ptep_gva[1] = kvm_mips_gpa_pte_to_gva_mapped(pte_gpa[1], tlb_lo[1]);
kvm_mips_host_tlb_inv(vcpu, gva, !kernel, kernel);
kvm_debug("@ %#lx tlb_lo0: 0x%08lx tlb_lo1: 0x%08lx\n", vcpu->arch.pc,
tlb->tlb_lo[0], tlb->tlb_lo[1]);
return 0;
}
int kvm_mips_handle_commpage_tlb_fault(unsigned long badvaddr,
struct kvm_vcpu *vcpu)
{
kvm_pfn_t pfn;
pte_t *ptep;
ptep = kvm_trap_emul_pte_for_gva(vcpu, badvaddr);
if (!ptep) {
kvm_err("No ptep for commpage %lx\n", badvaddr);
return -1;
}
pfn = PFN_DOWN(virt_to_phys(vcpu->arch.kseg0_commpage));
*ptep = pte_mkyoung(pte_mkdirty(pfn_pte(pfn, PAGE_SHARED)));
kvm_mips_host_tlb_inv(vcpu, badvaddr, false, true);
return 0;
}
static void kvm_mips_migrate_count(struct kvm_vcpu *vcpu)
{
if (hrtimer_cancel(&vcpu->arch.comparecount_timer))
hrtimer_restart(&vcpu->arch.comparecount_timer);
}
void kvm_arch_vcpu_load(struct kvm_vcpu *vcpu, int cpu)
{
unsigned long flags;
kvm_debug("%s: vcpu %p, cpu: %d\n", __func__, vcpu, cpu);
local_irq_save(flags);
vcpu->cpu = cpu;
if (vcpu->arch.last_sched_cpu != cpu) {
kvm_debug("[%d->%d]KVM VCPU[%d] switch\n",
vcpu->arch.last_sched_cpu, cpu, vcpu->vcpu_id);
kvm_mips_migrate_count(vcpu);
}
kvm_mips_callbacks->vcpu_load(vcpu, cpu);
local_irq_restore(flags);
}
void kvm_arch_vcpu_put(struct kvm_vcpu *vcpu)
{
unsigned long flags;
int cpu;
local_irq_save(flags);
cpu = smp_processor_id();
vcpu->arch.last_sched_cpu = cpu;
vcpu->cpu = -1;
kvm_mips_callbacks->vcpu_put(vcpu, cpu);
local_irq_restore(flags);
}
enum kvm_mips_fault_result kvm_trap_emul_gva_fault(struct kvm_vcpu *vcpu,
unsigned long gva,
bool write)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
struct kvm_mips_tlb *tlb;
int index;
if (KVM_GUEST_KSEGX(gva) == KVM_GUEST_KSEG0) {
if (kvm_mips_handle_kseg0_tlb_fault(gva, vcpu, write) < 0)
return KVM_MIPS_GPA;
} else if ((KVM_GUEST_KSEGX(gva) < KVM_GUEST_KSEG0) ||
KVM_GUEST_KSEGX(gva) == KVM_GUEST_KSEG23) {
index = kvm_mips_guest_tlb_lookup(vcpu, (gva & VPN2_MASK) |
(kvm_read_c0_guest_entryhi(cop0) & KVM_ENTRYHI_ASID));
if (index < 0)
return KVM_MIPS_TLB;
tlb = &vcpu->arch.guest_tlb[index];
if (!TLB_IS_VALID(*tlb, gva))
return KVM_MIPS_TLBINV;
if (write && !TLB_IS_DIRTY(*tlb, gva))
return KVM_MIPS_TLBMOD;
if (kvm_mips_handle_mapped_seg_tlb_fault(vcpu, tlb, gva, write))
return KVM_MIPS_GPA;
} else {
return KVM_MIPS_GVA;
}
return KVM_MIPS_MAPPED;
}
int kvm_get_inst(u32 *opc, struct kvm_vcpu *vcpu, u32 *out)
{
int err;
if (WARN(IS_ENABLED(CONFIG_KVM_MIPS_VZ),
"Expect BadInstr/BadInstrP registers to be used with VZ\n"))
return -EINVAL;
retry:
kvm_trap_emul_gva_lockless_begin(vcpu);
err = get_user(*out, opc);
kvm_trap_emul_gva_lockless_end(vcpu);
if (unlikely(err)) {
err = kvm_trap_emul_gva_fault(vcpu, (unsigned long)opc,
false);
if (unlikely(err)) {
kvm_err("%s: illegal address: %p\n",
__func__, opc);
return -EFAULT;
}
goto retry;
}
return 0;
}
