long kvmppc_h_put_tce(struct kvm_vcpu *vcpu, unsigned long liobn,
unsigned long ioba, unsigned long tce)
{
struct kvm *kvm = vcpu->kvm;
struct kvmppc_spapr_tce_table *stt;
list_for_each_entry(stt, &kvm->arch.spapr_tce_tables, list) {
if (stt->liobn == liobn) {
unsigned long idx = ioba >> SPAPR_TCE_SHIFT;
struct page *page;
u64 *tbl;
if (ioba >= stt->window_size)
return H_PARAMETER;
page = stt->pages[idx / TCES_PER_PAGE];
tbl = (u64 *)page_address(page);
tbl[idx % TCES_PER_PAGE] = tce;
return H_SUCCESS;
}
}
return H_TOO_HARD;
}
