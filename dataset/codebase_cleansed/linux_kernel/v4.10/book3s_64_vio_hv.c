struct kvmppc_spapr_tce_table *kvmppc_find_table(struct kvm_vcpu *vcpu,
unsigned long liobn)
{
struct kvm *kvm = vcpu->kvm;
struct kvmppc_spapr_tce_table *stt;
list_for_each_entry_lockless(stt, &kvm->arch.spapr_tce_tables, list)
if (stt->liobn == liobn)
return stt;
return NULL;
}
long kvmppc_ioba_validate(struct kvmppc_spapr_tce_table *stt,
unsigned long ioba, unsigned long npages)
{
unsigned long mask = (1ULL << stt->page_shift) - 1;
unsigned long idx = ioba >> stt->page_shift;
if ((ioba & mask) || (idx < stt->offset) ||
(idx - stt->offset + npages > stt->size) ||
(idx + npages < idx))
return H_PARAMETER;
return H_SUCCESS;
}
long kvmppc_tce_validate(struct kvmppc_spapr_tce_table *stt, unsigned long tce)
{
unsigned long page_mask = ~((1ULL << stt->page_shift) - 1);
unsigned long mask = ~(page_mask | TCE_PCI_WRITE | TCE_PCI_READ);
if (tce & mask)
return H_PARAMETER;
return H_SUCCESS;
}
static u64 *kvmppc_page_address(struct page *page)
{
#if defined(HASHED_PAGE_VIRTUAL) || defined(WANT_PAGE_VIRTUAL)
#error TODO: fix to avoid page_address() here
#endif
return (u64 *) page_address(page);
}
void kvmppc_tce_put(struct kvmppc_spapr_tce_table *stt,
unsigned long idx, unsigned long tce)
{
struct page *page;
u64 *tbl;
idx -= stt->offset;
page = stt->pages[idx / TCES_PER_PAGE];
tbl = kvmppc_page_address(page);
tbl[idx % TCES_PER_PAGE] = tce;
}
long kvmppc_gpa_to_ua(struct kvm *kvm, unsigned long gpa,
unsigned long *ua, unsigned long **prmap)
{
unsigned long gfn = gpa >> PAGE_SHIFT;
struct kvm_memory_slot *memslot;
memslot = search_memslots(kvm_memslots(kvm), gfn);
if (!memslot)
return -EINVAL;
*ua = __gfn_to_hva_memslot(memslot, gfn) |
(gpa & ~(PAGE_MASK | TCE_PCI_READ | TCE_PCI_WRITE));
#ifdef CONFIG_KVM_BOOK3S_HV_POSSIBLE
if (prmap)
*prmap = &memslot->arch.rmap[gfn - memslot->base_gfn];
#endif
return 0;
}
long kvmppc_rm_h_put_tce(struct kvm_vcpu *vcpu, unsigned long liobn,
unsigned long ioba, unsigned long tce)
{
struct kvmppc_spapr_tce_table *stt = kvmppc_find_table(vcpu, liobn);
long ret;
if (!stt)
return H_TOO_HARD;
ret = kvmppc_ioba_validate(stt, ioba, 1);
if (ret != H_SUCCESS)
return ret;
ret = kvmppc_tce_validate(stt, tce);
if (ret != H_SUCCESS)
return ret;
kvmppc_tce_put(stt, ioba >> stt->page_shift, tce);
return H_SUCCESS;
}
static long kvmppc_rm_ua_to_hpa(struct kvm_vcpu *vcpu,
unsigned long ua, unsigned long *phpa)
{
pte_t *ptep, pte;
unsigned shift = 0;
ptep = __find_linux_pte_or_hugepte(vcpu->arch.pgdir, ua, NULL, &shift);
if (!ptep || !pte_present(*ptep))
return -ENXIO;
pte = *ptep;
if (!shift)
shift = PAGE_SHIFT;
if (shift > PAGE_SHIFT)
return -EAGAIN;
if (!pte_young(pte))
return -EAGAIN;
*phpa = (pte_pfn(pte) << PAGE_SHIFT) | (ua & ((1ULL << shift) - 1)) |
(ua & ~PAGE_MASK);
return 0;
}
long kvmppc_rm_h_put_tce_indirect(struct kvm_vcpu *vcpu,
unsigned long liobn, unsigned long ioba,
unsigned long tce_list, unsigned long npages)
{
struct kvmppc_spapr_tce_table *stt;
long i, ret = H_SUCCESS;
unsigned long tces, entry, ua = 0;
unsigned long *rmap = NULL;
stt = kvmppc_find_table(vcpu, liobn);
if (!stt)
return H_TOO_HARD;
entry = ioba >> stt->page_shift;
if (npages > 512)
return H_PARAMETER;
if (tce_list & (SZ_4K - 1))
return H_PARAMETER;
ret = kvmppc_ioba_validate(stt, ioba, npages);
if (ret != H_SUCCESS)
return ret;
if (kvmppc_gpa_to_ua(vcpu->kvm, tce_list, &ua, &rmap))
return H_TOO_HARD;
rmap = (void *) vmalloc_to_phys(rmap);
lock_rmap(rmap);
if (kvmppc_rm_ua_to_hpa(vcpu, ua, &tces)) {
ret = H_TOO_HARD;
goto unlock_exit;
}
for (i = 0; i < npages; ++i) {
unsigned long tce = be64_to_cpu(((u64 *)tces)[i]);
ret = kvmppc_tce_validate(stt, tce);
if (ret != H_SUCCESS)
goto unlock_exit;
kvmppc_tce_put(stt, entry + i, tce);
}
unlock_exit:
unlock_rmap(rmap);
return ret;
}
long kvmppc_rm_h_stuff_tce(struct kvm_vcpu *vcpu,
unsigned long liobn, unsigned long ioba,
unsigned long tce_value, unsigned long npages)
{
struct kvmppc_spapr_tce_table *stt;
long i, ret;
stt = kvmppc_find_table(vcpu, liobn);
if (!stt)
return H_TOO_HARD;
ret = kvmppc_ioba_validate(stt, ioba, npages);
if (ret != H_SUCCESS)
return ret;
if (tce_value & (TCE_PCI_WRITE | TCE_PCI_READ))
return H_PARAMETER;
for (i = 0; i < npages; ++i, ioba += (1ULL << stt->page_shift))
kvmppc_tce_put(stt, ioba >> stt->page_shift, tce_value);
return H_SUCCESS;
}
long kvmppc_h_get_tce(struct kvm_vcpu *vcpu, unsigned long liobn,
unsigned long ioba)
{
struct kvmppc_spapr_tce_table *stt = kvmppc_find_table(vcpu, liobn);
long ret;
unsigned long idx;
struct page *page;
u64 *tbl;
if (!stt)
return H_TOO_HARD;
ret = kvmppc_ioba_validate(stt, ioba, 1);
if (ret != H_SUCCESS)
return ret;
idx = (ioba >> stt->page_shift) - stt->offset;
page = stt->pages[idx / TCES_PER_PAGE];
tbl = (u64 *)page_address(page);
vcpu->arch.gpr[4] = tbl[idx % TCES_PER_PAGE];
return H_SUCCESS;
}
