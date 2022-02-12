long kvmppc_alloc_hpt(struct kvm *kvm)
{
unsigned long hpt;
unsigned long lpid;
hpt = __get_free_pages(GFP_KERNEL|__GFP_ZERO|__GFP_REPEAT|__GFP_NOWARN,
HPT_ORDER - PAGE_SHIFT);
if (!hpt) {
pr_err("kvm_alloc_hpt: Couldn't alloc HPT\n");
return -ENOMEM;
}
kvm->arch.hpt_virt = hpt;
do {
lpid = find_first_zero_bit(lpid_inuse, NR_LPIDS);
if (lpid >= NR_LPIDS) {
pr_err("kvm_alloc_hpt: No LPIDs free\n");
free_pages(hpt, HPT_ORDER - PAGE_SHIFT);
return -ENOMEM;
}
} while (test_and_set_bit(lpid, lpid_inuse));
kvm->arch.sdr1 = __pa(hpt) | (HPT_ORDER - 18);
kvm->arch.lpid = lpid;
pr_info("KVM guest htab at %lx, LPID %lx\n", hpt, lpid);
return 0;
}
void kvmppc_free_hpt(struct kvm *kvm)
{
clear_bit(kvm->arch.lpid, lpid_inuse);
free_pages(kvm->arch.hpt_virt, HPT_ORDER - PAGE_SHIFT);
}
void kvmppc_map_vrma(struct kvm *kvm, struct kvm_userspace_memory_region *mem)
{
unsigned long i;
unsigned long npages = kvm->arch.ram_npages;
unsigned long pfn;
unsigned long *hpte;
unsigned long hash;
struct kvmppc_pginfo *pginfo = kvm->arch.ram_pginfo;
if (!pginfo)
return;
if (npages > 1ul << (40 - kvm->arch.ram_porder))
npages = 1ul << (40 - kvm->arch.ram_porder);
if (npages > HPT_NPTEG)
npages = HPT_NPTEG;
for (i = 0; i < npages; ++i) {
pfn = pginfo[i].pfn;
if (!pfn)
break;
hash = (i ^ (VRMA_VSID ^ (VRMA_VSID << 25))) & HPT_HASH_MASK;
hpte = (unsigned long *) (kvm->arch.hpt_virt + (hash << 7));
hpte += 7 * 2;
hpte[1] = (pfn << PAGE_SHIFT) | HPTE_R_R | HPTE_R_C |
HPTE_R_M | PP_RWXX;
wmb();
hpte[0] = HPTE_V_1TB_SEG | (VRMA_VSID << (40 - 16)) |
(i << (VRMA_PAGE_ORDER - 16)) | HPTE_V_BOLTED |
HPTE_V_LARGE | HPTE_V_VALID;
}
}
int kvmppc_mmu_hv_init(void)
{
unsigned long host_lpid, rsvd_lpid;
if (!cpu_has_feature(CPU_FTR_HVMODE))
return -EINVAL;
memset(lpid_inuse, 0, sizeof(lpid_inuse));
if (cpu_has_feature(CPU_FTR_ARCH_206)) {
host_lpid = mfspr(SPRN_LPID);
rsvd_lpid = LPID_RSVD;
} else {
host_lpid = 0;
rsvd_lpid = MAX_LPID_970;
}
set_bit(host_lpid, lpid_inuse);
set_bit(rsvd_lpid, lpid_inuse);
return 0;
}
void kvmppc_mmu_destroy(struct kvm_vcpu *vcpu)
{
}
static void kvmppc_mmu_book3s_64_hv_reset_msr(struct kvm_vcpu *vcpu)
{
kvmppc_set_msr(vcpu, MSR_SF | MSR_ME);
}
static int kvmppc_mmu_book3s_64_hv_xlate(struct kvm_vcpu *vcpu, gva_t eaddr,
struct kvmppc_pte *gpte, bool data)
{
return -ENOENT;
}
void kvmppc_mmu_book3s_hv_init(struct kvm_vcpu *vcpu)
{
struct kvmppc_mmu *mmu = &vcpu->arch.mmu;
if (cpu_has_feature(CPU_FTR_ARCH_206))
vcpu->arch.slb_nr = 32;
else
vcpu->arch.slb_nr = 64;
mmu->xlate = kvmppc_mmu_book3s_64_hv_xlate;
mmu->reset_msr = kvmppc_mmu_book3s_64_hv_reset_msr;
vcpu->arch.hflags |= BOOK3S_HFLAG_SLB;
}
