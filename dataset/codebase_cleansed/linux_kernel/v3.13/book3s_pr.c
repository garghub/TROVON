static void kvmppc_core_vcpu_load_pr(struct kvm_vcpu *vcpu, int cpu)
{
#ifdef CONFIG_PPC_BOOK3S_64
struct kvmppc_book3s_shadow_vcpu *svcpu = svcpu_get(vcpu);
memcpy(svcpu->slb, to_book3s(vcpu)->slb_shadow, sizeof(svcpu->slb));
svcpu->slb_max = to_book3s(vcpu)->slb_shadow_max;
svcpu->in_use = 0;
svcpu_put(svcpu);
#endif
vcpu->cpu = smp_processor_id();
#ifdef CONFIG_PPC_BOOK3S_32
current->thread.kvm_shadow_vcpu = vcpu->arch.shadow_vcpu;
#endif
}
static void kvmppc_core_vcpu_put_pr(struct kvm_vcpu *vcpu)
{
#ifdef CONFIG_PPC_BOOK3S_64
struct kvmppc_book3s_shadow_vcpu *svcpu = svcpu_get(vcpu);
if (svcpu->in_use) {
kvmppc_copy_from_svcpu(vcpu, svcpu);
}
memcpy(to_book3s(vcpu)->slb_shadow, svcpu->slb, sizeof(svcpu->slb));
to_book3s(vcpu)->slb_shadow_max = svcpu->slb_max;
svcpu_put(svcpu);
#endif
kvmppc_giveup_ext(vcpu, MSR_FP | MSR_VEC | MSR_VSX);
vcpu->cpu = -1;
}
void kvmppc_copy_to_svcpu(struct kvmppc_book3s_shadow_vcpu *svcpu,
struct kvm_vcpu *vcpu)
{
svcpu->gpr[0] = vcpu->arch.gpr[0];
svcpu->gpr[1] = vcpu->arch.gpr[1];
svcpu->gpr[2] = vcpu->arch.gpr[2];
svcpu->gpr[3] = vcpu->arch.gpr[3];
svcpu->gpr[4] = vcpu->arch.gpr[4];
svcpu->gpr[5] = vcpu->arch.gpr[5];
svcpu->gpr[6] = vcpu->arch.gpr[6];
svcpu->gpr[7] = vcpu->arch.gpr[7];
svcpu->gpr[8] = vcpu->arch.gpr[8];
svcpu->gpr[9] = vcpu->arch.gpr[9];
svcpu->gpr[10] = vcpu->arch.gpr[10];
svcpu->gpr[11] = vcpu->arch.gpr[11];
svcpu->gpr[12] = vcpu->arch.gpr[12];
svcpu->gpr[13] = vcpu->arch.gpr[13];
svcpu->cr = vcpu->arch.cr;
svcpu->xer = vcpu->arch.xer;
svcpu->ctr = vcpu->arch.ctr;
svcpu->lr = vcpu->arch.lr;
svcpu->pc = vcpu->arch.pc;
svcpu->in_use = true;
}
void kvmppc_copy_from_svcpu(struct kvm_vcpu *vcpu,
struct kvmppc_book3s_shadow_vcpu *svcpu)
{
preempt_disable();
if (!svcpu->in_use)
goto out;
vcpu->arch.gpr[0] = svcpu->gpr[0];
vcpu->arch.gpr[1] = svcpu->gpr[1];
vcpu->arch.gpr[2] = svcpu->gpr[2];
vcpu->arch.gpr[3] = svcpu->gpr[3];
vcpu->arch.gpr[4] = svcpu->gpr[4];
vcpu->arch.gpr[5] = svcpu->gpr[5];
vcpu->arch.gpr[6] = svcpu->gpr[6];
vcpu->arch.gpr[7] = svcpu->gpr[7];
vcpu->arch.gpr[8] = svcpu->gpr[8];
vcpu->arch.gpr[9] = svcpu->gpr[9];
vcpu->arch.gpr[10] = svcpu->gpr[10];
vcpu->arch.gpr[11] = svcpu->gpr[11];
vcpu->arch.gpr[12] = svcpu->gpr[12];
vcpu->arch.gpr[13] = svcpu->gpr[13];
vcpu->arch.cr = svcpu->cr;
vcpu->arch.xer = svcpu->xer;
vcpu->arch.ctr = svcpu->ctr;
vcpu->arch.lr = svcpu->lr;
vcpu->arch.pc = svcpu->pc;
vcpu->arch.shadow_srr1 = svcpu->shadow_srr1;
vcpu->arch.fault_dar = svcpu->fault_dar;
vcpu->arch.fault_dsisr = svcpu->fault_dsisr;
vcpu->arch.last_inst = svcpu->last_inst;
svcpu->in_use = false;
out:
preempt_enable();
}
static int kvmppc_core_check_requests_pr(struct kvm_vcpu *vcpu)
{
int r = 1;
if (kvm_check_request(KVM_REQ_TLB_FLUSH, vcpu))
kvmppc_mmu_pte_flush(vcpu, 0, 0);
return r;
}
static void do_kvm_unmap_hva(struct kvm *kvm, unsigned long start,
unsigned long end)
{
long i;
struct kvm_vcpu *vcpu;
struct kvm_memslots *slots;
struct kvm_memory_slot *memslot;
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
kvm_for_each_vcpu(i, vcpu, kvm)
kvmppc_mmu_pte_pflush(vcpu, gfn << PAGE_SHIFT,
gfn_end << PAGE_SHIFT);
}
}
static int kvm_unmap_hva_pr(struct kvm *kvm, unsigned long hva)
{
trace_kvm_unmap_hva(hva);
do_kvm_unmap_hva(kvm, hva, hva + PAGE_SIZE);
return 0;
}
static int kvm_unmap_hva_range_pr(struct kvm *kvm, unsigned long start,
unsigned long end)
{
do_kvm_unmap_hva(kvm, start, end);
return 0;
}
static int kvm_age_hva_pr(struct kvm *kvm, unsigned long hva)
{
return 0;
}
static int kvm_test_age_hva_pr(struct kvm *kvm, unsigned long hva)
{
return 0;
}
static void kvm_set_spte_hva_pr(struct kvm *kvm, unsigned long hva, pte_t pte)
{
do_kvm_unmap_hva(kvm, hva, hva + PAGE_SIZE);
}
static void kvmppc_recalc_shadow_msr(struct kvm_vcpu *vcpu)
{
ulong smsr = vcpu->arch.shared->msr;
smsr &= MSR_FE0 | MSR_FE1 | MSR_SF | MSR_SE | MSR_BE;
smsr |= MSR_ME | MSR_RI | MSR_IR | MSR_DR | MSR_PR | MSR_EE;
smsr |= (vcpu->arch.shared->msr & vcpu->arch.guest_owned_ext);
#ifdef CONFIG_PPC_BOOK3S_64
smsr |= MSR_ISF | MSR_HV;
#endif
vcpu->arch.shadow_msr = smsr;
}
static void kvmppc_set_msr_pr(struct kvm_vcpu *vcpu, u64 msr)
{
ulong old_msr = vcpu->arch.shared->msr;
#ifdef EXIT_DEBUG
printk(KERN_INFO "KVM: Set MSR to 0x%llx\n", msr);
#endif
msr &= to_book3s(vcpu)->msr_mask;
vcpu->arch.shared->msr = msr;
kvmppc_recalc_shadow_msr(vcpu);
if (msr & MSR_POW) {
if (!vcpu->arch.pending_exceptions) {
kvm_vcpu_block(vcpu);
clear_bit(KVM_REQ_UNHALT, &vcpu->requests);
vcpu->stat.halt_wakeup++;
msr &= ~MSR_POW;
vcpu->arch.shared->msr = msr;
}
}
if ((vcpu->arch.shared->msr & (MSR_PR|MSR_IR|MSR_DR)) !=
(old_msr & (MSR_PR|MSR_IR|MSR_DR))) {
kvmppc_mmu_flush_segments(vcpu);
kvmppc_mmu_map_segment(vcpu, kvmppc_get_pc(vcpu));
if (!(msr & MSR_PR) && vcpu->arch.magic_page_pa) {
struct kvm_vcpu_arch *a = &vcpu->arch;
if (msr & MSR_DR)
kvmppc_mmu_map_segment(vcpu, a->magic_page_ea);
else
kvmppc_mmu_map_segment(vcpu, a->magic_page_pa);
}
}
if (vcpu->arch.magic_page_pa &&
!(old_msr & MSR_PR) && !(old_msr & MSR_SF) && (msr & MSR_SF)) {
kvmppc_mmu_pte_flush(vcpu, (uint32_t)vcpu->arch.magic_page_pa,
~0xFFFUL);
}
if (vcpu->arch.shared->msr & MSR_FP)
kvmppc_handle_ext(vcpu, BOOK3S_INTERRUPT_FP_UNAVAIL, MSR_FP);
}
void kvmppc_set_pvr_pr(struct kvm_vcpu *vcpu, u32 pvr)
{
u32 host_pvr;
vcpu->arch.hflags &= ~BOOK3S_HFLAG_SLB;
vcpu->arch.pvr = pvr;
#ifdef CONFIG_PPC_BOOK3S_64
if ((pvr >= 0x330000) && (pvr < 0x70330000)) {
kvmppc_mmu_book3s_64_init(vcpu);
if (!to_book3s(vcpu)->hior_explicit)
to_book3s(vcpu)->hior = 0xfff00000;
to_book3s(vcpu)->msr_mask = 0xffffffffffffffffULL;
vcpu->arch.cpu_type = KVM_CPU_3S_64;
} else
#endif
{
kvmppc_mmu_book3s_32_init(vcpu);
if (!to_book3s(vcpu)->hior_explicit)
to_book3s(vcpu)->hior = 0;
to_book3s(vcpu)->msr_mask = 0xffffffffULL;
vcpu->arch.cpu_type = KVM_CPU_3S_32;
}
kvmppc_sanity_check(vcpu);
vcpu->arch.hflags &= ~BOOK3S_HFLAG_DCBZ32;
if (vcpu->arch.mmu.is_dcbz32(vcpu) && (mfmsr() & MSR_HV) &&
!strcmp(cur_cpu_spec->platform, "ppc970"))
vcpu->arch.hflags |= BOOK3S_HFLAG_DCBZ32;
if (!strcmp(cur_cpu_spec->platform, "ppc-cell-be"))
to_book3s(vcpu)->msr_mask &= ~(MSR_FE0 | MSR_FE1);
switch (PVR_VER(pvr)) {
case PVR_POWER6:
case PVR_POWER7:
case PVR_POWER7p:
case PVR_POWER8:
vcpu->arch.hflags |= BOOK3S_HFLAG_MULTI_PGSIZE |
BOOK3S_HFLAG_NEW_TLBIE;
break;
}
#ifdef CONFIG_PPC_BOOK3S_32
vcpu->arch.hflags |= BOOK3S_HFLAG_DCBZ32;
#endif
asm ( "mfpvr %0" : "=r"(host_pvr));
switch (host_pvr) {
case 0x00080200:
case 0x00088202:
case 0x70000100:
case 0x00080100:
case 0x00083203:
case 0x00083213:
case 0x00083204:
case 0x00083214:
case 0x00087200:
vcpu->arch.hflags |= BOOK3S_HFLAG_NATIVE_PS;
mtspr(SPRN_HID2_GEKKO, mfspr(SPRN_HID2_GEKKO) | (1 << 29));
}
}
static void kvmppc_patch_dcbz(struct kvm_vcpu *vcpu, struct kvmppc_pte *pte)
{
struct page *hpage;
u64 hpage_offset;
u32 *page;
int i;
hpage = gfn_to_page(vcpu->kvm, pte->raddr >> PAGE_SHIFT);
if (is_error_page(hpage))
return;
hpage_offset = pte->raddr & ~PAGE_MASK;
hpage_offset &= ~0xFFFULL;
hpage_offset /= 4;
get_page(hpage);
page = kmap_atomic(hpage);
for (i=hpage_offset; i < hpage_offset + (HW_PAGE_SIZE / 4); i++)
if ((page[i] & 0xff0007ff) == INS_DCBZ)
page[i] &= 0xfffffff7;
kunmap_atomic(page);
put_page(hpage);
}
static int kvmppc_visible_gfn(struct kvm_vcpu *vcpu, gfn_t gfn)
{
ulong mp_pa = vcpu->arch.magic_page_pa;
if (!(vcpu->arch.shared->msr & MSR_SF))
mp_pa = (uint32_t)mp_pa;
if (unlikely(mp_pa) &&
unlikely((mp_pa & KVM_PAM) >> PAGE_SHIFT == gfn)) {
return 1;
}
return kvm_is_visible_gfn(vcpu->kvm, gfn);
}
int kvmppc_handle_pagefault(struct kvm_run *run, struct kvm_vcpu *vcpu,
ulong eaddr, int vec)
{
bool data = (vec == BOOK3S_INTERRUPT_DATA_STORAGE);
bool iswrite = false;
int r = RESUME_GUEST;
int relocated;
int page_found = 0;
struct kvmppc_pte pte;
bool is_mmio = false;
bool dr = (vcpu->arch.shared->msr & MSR_DR) ? true : false;
bool ir = (vcpu->arch.shared->msr & MSR_IR) ? true : false;
u64 vsid;
relocated = data ? dr : ir;
if (data && (vcpu->arch.fault_dsisr & DSISR_ISSTORE))
iswrite = true;
if (relocated) {
page_found = vcpu->arch.mmu.xlate(vcpu, eaddr, &pte, data, iswrite);
} else {
pte.may_execute = true;
pte.may_read = true;
pte.may_write = true;
pte.raddr = eaddr & KVM_PAM;
pte.eaddr = eaddr;
pte.vpage = eaddr >> 12;
pte.page_size = MMU_PAGE_64K;
}
switch (vcpu->arch.shared->msr & (MSR_DR|MSR_IR)) {
case 0:
pte.vpage |= ((u64)VSID_REAL << (SID_SHIFT - 12));
break;
case MSR_DR:
case MSR_IR:
vcpu->arch.mmu.esid_to_vsid(vcpu, eaddr >> SID_SHIFT, &vsid);
if ((vcpu->arch.shared->msr & (MSR_DR|MSR_IR)) == MSR_DR)
pte.vpage |= ((u64)VSID_REAL_DR << (SID_SHIFT - 12));
else
pte.vpage |= ((u64)VSID_REAL_IR << (SID_SHIFT - 12));
pte.vpage |= vsid;
if (vsid == -1)
page_found = -EINVAL;
break;
}
if (vcpu->arch.mmu.is_dcbz32(vcpu) &&
(!(vcpu->arch.hflags & BOOK3S_HFLAG_DCBZ32))) {
pte.may_execute = !data;
}
if (page_found == -ENOENT) {
vcpu->arch.shared->dar = kvmppc_get_fault_dar(vcpu);
vcpu->arch.shared->dsisr = vcpu->arch.fault_dsisr;
vcpu->arch.shared->msr |=
vcpu->arch.shadow_srr1 & 0x00000000f8000000ULL;
kvmppc_book3s_queue_irqprio(vcpu, vec);
} else if (page_found == -EPERM) {
vcpu->arch.shared->dar = kvmppc_get_fault_dar(vcpu);
vcpu->arch.shared->dsisr = vcpu->arch.fault_dsisr & ~DSISR_NOHPTE;
vcpu->arch.shared->dsisr |= DSISR_PROTFAULT;
vcpu->arch.shared->msr |=
vcpu->arch.shadow_srr1 & 0x00000000f8000000ULL;
kvmppc_book3s_queue_irqprio(vcpu, vec);
} else if (page_found == -EINVAL) {
vcpu->arch.shared->dar = kvmppc_get_fault_dar(vcpu);
kvmppc_book3s_queue_irqprio(vcpu, vec + 0x80);
} else if (!is_mmio &&
kvmppc_visible_gfn(vcpu, pte.raddr >> PAGE_SHIFT)) {
if (data && !(vcpu->arch.fault_dsisr & DSISR_NOHPTE)) {
kvmppc_mmu_unmap_page(vcpu, &pte);
}
kvmppc_mmu_map_page(vcpu, &pte, iswrite);
if (data)
vcpu->stat.sp_storage++;
else if (vcpu->arch.mmu.is_dcbz32(vcpu) &&
(!(vcpu->arch.hflags & BOOK3S_HFLAG_DCBZ32)))
kvmppc_patch_dcbz(vcpu, &pte);
} else {
vcpu->stat.mmio_exits++;
vcpu->arch.paddr_accessed = pte.raddr;
vcpu->arch.vaddr_accessed = pte.eaddr;
r = kvmppc_emulate_mmio(run, vcpu);
if ( r == RESUME_HOST_NV )
r = RESUME_HOST;
}
return r;
}
static inline int get_fpr_index(int i)
{
return i * TS_FPRWIDTH;
}
void kvmppc_giveup_ext(struct kvm_vcpu *vcpu, ulong msr)
{
struct thread_struct *t = &current->thread;
u64 *vcpu_fpr = vcpu->arch.fpr;
#ifdef CONFIG_VSX
u64 *vcpu_vsx = vcpu->arch.vsr;
#endif
u64 *thread_fpr = &t->fp_state.fpr[0][0];
int i;
if (msr & MSR_VSX)
msr |= MSR_FP | MSR_VEC;
msr &= vcpu->arch.guest_owned_ext;
if (!msr)
return;
#ifdef DEBUG_EXT
printk(KERN_INFO "Giving up ext 0x%lx\n", msr);
#endif
if (msr & MSR_FP) {
if (current->thread.regs->msr & MSR_FP)
giveup_fpu(current);
for (i = 0; i < ARRAY_SIZE(vcpu->arch.fpr); i++)
vcpu_fpr[i] = thread_fpr[get_fpr_index(i)];
vcpu->arch.fpscr = t->fp_state.fpscr;
#ifdef CONFIG_VSX
if (cpu_has_feature(CPU_FTR_VSX))
for (i = 0; i < ARRAY_SIZE(vcpu->arch.vsr) / 2; i++)
vcpu_vsx[i] = thread_fpr[get_fpr_index(i) + 1];
#endif
}
#ifdef CONFIG_ALTIVEC
if (msr & MSR_VEC) {
if (current->thread.regs->msr & MSR_VEC)
giveup_altivec(current);
memcpy(vcpu->arch.vr, t->vr_state.vr, sizeof(vcpu->arch.vr));
vcpu->arch.vscr = t->vr_state.vscr;
}
#endif
vcpu->arch.guest_owned_ext &= ~(msr | MSR_VSX);
kvmppc_recalc_shadow_msr(vcpu);
}
static int kvmppc_read_inst(struct kvm_vcpu *vcpu)
{
ulong srr0 = kvmppc_get_pc(vcpu);
u32 last_inst = kvmppc_get_last_inst(vcpu);
int ret;
ret = kvmppc_ld(vcpu, &srr0, sizeof(u32), &last_inst, false);
if (ret == -ENOENT) {
ulong msr = vcpu->arch.shared->msr;
msr = kvmppc_set_field(msr, 33, 33, 1);
msr = kvmppc_set_field(msr, 34, 36, 0);
vcpu->arch.shared->msr = kvmppc_set_field(msr, 42, 47, 0);
kvmppc_book3s_queue_irqprio(vcpu, BOOK3S_INTERRUPT_INST_STORAGE);
return EMULATE_AGAIN;
}
return EMULATE_DONE;
}
static int kvmppc_check_ext(struct kvm_vcpu *vcpu, unsigned int exit_nr)
{
if (!(vcpu->arch.hflags & BOOK3S_HFLAG_PAIRED_SINGLE))
return EMULATE_DONE;
if (kvmppc_read_inst(vcpu) == EMULATE_DONE)
return EMULATE_FAIL;
return EMULATE_AGAIN;
}
static int kvmppc_handle_ext(struct kvm_vcpu *vcpu, unsigned int exit_nr,
ulong msr)
{
struct thread_struct *t = &current->thread;
u64 *vcpu_fpr = vcpu->arch.fpr;
#ifdef CONFIG_VSX
u64 *vcpu_vsx = vcpu->arch.vsr;
#endif
u64 *thread_fpr = &t->fp_state.fpr[0][0];
int i;
if (vcpu->arch.hflags & BOOK3S_HFLAG_PAIRED_SINGLE)
return RESUME_GUEST;
if (!(vcpu->arch.shared->msr & msr)) {
kvmppc_book3s_queue_irqprio(vcpu, exit_nr);
return RESUME_GUEST;
}
if (msr == MSR_VSX) {
#ifdef CONFIG_VSX
if (!cpu_has_feature(CPU_FTR_VSX))
#endif
{
kvmppc_core_queue_program(vcpu, SRR1_PROGILL);
return RESUME_GUEST;
}
msr = MSR_FP | MSR_VEC | MSR_VSX;
}
msr &= ~vcpu->arch.guest_owned_ext;
if (!msr)
return RESUME_GUEST;
#ifdef DEBUG_EXT
printk(KERN_INFO "Loading up ext 0x%lx\n", msr);
#endif
if (msr & MSR_FP) {
for (i = 0; i < ARRAY_SIZE(vcpu->arch.fpr); i++)
thread_fpr[get_fpr_index(i)] = vcpu_fpr[i];
#ifdef CONFIG_VSX
for (i = 0; i < ARRAY_SIZE(vcpu->arch.vsr) / 2; i++)
thread_fpr[get_fpr_index(i) + 1] = vcpu_vsx[i];
#endif
t->fp_state.fpscr = vcpu->arch.fpscr;
t->fpexc_mode = 0;
kvmppc_load_up_fpu();
}
if (msr & MSR_VEC) {
#ifdef CONFIG_ALTIVEC
memcpy(t->vr_state.vr, vcpu->arch.vr, sizeof(vcpu->arch.vr));
t->vr_state.vscr = vcpu->arch.vscr;
t->vrsave = -1;
kvmppc_load_up_altivec();
#endif
}
current->thread.regs->msr |= msr;
vcpu->arch.guest_owned_ext |= msr;
kvmppc_recalc_shadow_msr(vcpu);
return RESUME_GUEST;
}
static void kvmppc_handle_lost_ext(struct kvm_vcpu *vcpu)
{
unsigned long lost_ext;
lost_ext = vcpu->arch.guest_owned_ext & ~current->thread.regs->msr;
if (!lost_ext)
return;
if (lost_ext & MSR_FP)
kvmppc_load_up_fpu();
#ifdef CONFIG_ALTIVEC
if (lost_ext & MSR_VEC)
kvmppc_load_up_altivec();
#endif
current->thread.regs->msr |= lost_ext;
}
int kvmppc_handle_exit_pr(struct kvm_run *run, struct kvm_vcpu *vcpu,
unsigned int exit_nr)
{
int r = RESUME_HOST;
int s;
vcpu->stat.sum_exits++;
run->exit_reason = KVM_EXIT_UNKNOWN;
run->ready_for_interrupt_injection = 1;
trace_kvm_exit(exit_nr, vcpu);
kvm_guest_exit();
switch (exit_nr) {
case BOOK3S_INTERRUPT_INST_STORAGE:
{
ulong shadow_srr1 = vcpu->arch.shadow_srr1;
vcpu->stat.pf_instruc++;
#ifdef CONFIG_PPC_BOOK3S_32
{
struct kvmppc_book3s_shadow_vcpu *svcpu;
u32 sr;
svcpu = svcpu_get(vcpu);
sr = svcpu->sr[kvmppc_get_pc(vcpu) >> SID_SHIFT];
svcpu_put(svcpu);
if (sr == SR_INVALID) {
kvmppc_mmu_map_segment(vcpu, kvmppc_get_pc(vcpu));
r = RESUME_GUEST;
break;
}
}
#endif
if (shadow_srr1 & 0x40000000) {
int idx = srcu_read_lock(&vcpu->kvm->srcu);
r = kvmppc_handle_pagefault(run, vcpu, kvmppc_get_pc(vcpu), exit_nr);
srcu_read_unlock(&vcpu->kvm->srcu, idx);
vcpu->stat.sp_instruc++;
} else if (vcpu->arch.mmu.is_dcbz32(vcpu) &&
(!(vcpu->arch.hflags & BOOK3S_HFLAG_DCBZ32))) {
kvmppc_mmu_pte_flush(vcpu, kvmppc_get_pc(vcpu), ~0xFFFUL);
r = RESUME_GUEST;
} else {
vcpu->arch.shared->msr |= shadow_srr1 & 0x58000000;
kvmppc_book3s_queue_irqprio(vcpu, exit_nr);
r = RESUME_GUEST;
}
break;
}
case BOOK3S_INTERRUPT_DATA_STORAGE:
{
ulong dar = kvmppc_get_fault_dar(vcpu);
u32 fault_dsisr = vcpu->arch.fault_dsisr;
vcpu->stat.pf_storage++;
#ifdef CONFIG_PPC_BOOK3S_32
{
struct kvmppc_book3s_shadow_vcpu *svcpu;
u32 sr;
svcpu = svcpu_get(vcpu);
sr = svcpu->sr[dar >> SID_SHIFT];
svcpu_put(svcpu);
if (sr == SR_INVALID) {
kvmppc_mmu_map_segment(vcpu, dar);
r = RESUME_GUEST;
break;
}
}
#endif
if (fault_dsisr & (DSISR_NOHPTE | DSISR_PROTFAULT)) {
int idx = srcu_read_lock(&vcpu->kvm->srcu);
r = kvmppc_handle_pagefault(run, vcpu, dar, exit_nr);
srcu_read_unlock(&vcpu->kvm->srcu, idx);
} else {
vcpu->arch.shared->dar = dar;
vcpu->arch.shared->dsisr = fault_dsisr;
kvmppc_book3s_queue_irqprio(vcpu, exit_nr);
r = RESUME_GUEST;
}
break;
}
case BOOK3S_INTERRUPT_DATA_SEGMENT:
if (kvmppc_mmu_map_segment(vcpu, kvmppc_get_fault_dar(vcpu)) < 0) {
vcpu->arch.shared->dar = kvmppc_get_fault_dar(vcpu);
kvmppc_book3s_queue_irqprio(vcpu,
BOOK3S_INTERRUPT_DATA_SEGMENT);
}
r = RESUME_GUEST;
break;
case BOOK3S_INTERRUPT_INST_SEGMENT:
if (kvmppc_mmu_map_segment(vcpu, kvmppc_get_pc(vcpu)) < 0) {
kvmppc_book3s_queue_irqprio(vcpu,
BOOK3S_INTERRUPT_INST_SEGMENT);
}
r = RESUME_GUEST;
break;
case BOOK3S_INTERRUPT_DECREMENTER:
case BOOK3S_INTERRUPT_HV_DECREMENTER:
vcpu->stat.dec_exits++;
r = RESUME_GUEST;
break;
case BOOK3S_INTERRUPT_EXTERNAL:
case BOOK3S_INTERRUPT_EXTERNAL_LEVEL:
case BOOK3S_INTERRUPT_EXTERNAL_HV:
vcpu->stat.ext_intr_exits++;
r = RESUME_GUEST;
break;
case BOOK3S_INTERRUPT_PERFMON:
r = RESUME_GUEST;
break;
case BOOK3S_INTERRUPT_PROGRAM:
case BOOK3S_INTERRUPT_H_EMUL_ASSIST:
{
enum emulation_result er;
ulong flags;
program_interrupt:
flags = vcpu->arch.shadow_srr1 & 0x1f0000ull;
if (vcpu->arch.shared->msr & MSR_PR) {
#ifdef EXIT_DEBUG
printk(KERN_INFO "Userspace triggered 0x700 exception at 0x%lx (0x%x)\n", kvmppc_get_pc(vcpu), kvmppc_get_last_inst(vcpu));
#endif
if ((kvmppc_get_last_inst(vcpu) & 0xff0007ff) !=
(INS_DCBZ & 0xfffffff7)) {
kvmppc_core_queue_program(vcpu, flags);
r = RESUME_GUEST;
break;
}
}
vcpu->stat.emulated_inst_exits++;
er = kvmppc_emulate_instruction(run, vcpu);
switch (er) {
case EMULATE_DONE:
r = RESUME_GUEST_NV;
break;
case EMULATE_AGAIN:
r = RESUME_GUEST;
break;
case EMULATE_FAIL:
printk(KERN_CRIT "%s: emulation at %lx failed (%08x)\n",
__func__, kvmppc_get_pc(vcpu), kvmppc_get_last_inst(vcpu));
kvmppc_core_queue_program(vcpu, flags);
r = RESUME_GUEST;
break;
case EMULATE_DO_MMIO:
run->exit_reason = KVM_EXIT_MMIO;
r = RESUME_HOST_NV;
break;
case EMULATE_EXIT_USER:
r = RESUME_HOST_NV;
break;
default:
BUG();
}
break;
}
case BOOK3S_INTERRUPT_SYSCALL:
if (vcpu->arch.papr_enabled &&
(kvmppc_get_last_sc(vcpu) == 0x44000022) &&
!(vcpu->arch.shared->msr & MSR_PR)) {
ulong cmd = kvmppc_get_gpr(vcpu, 3);
int i;
#ifdef CONFIG_PPC_BOOK3S_64
if (kvmppc_h_pr(vcpu, cmd) == EMULATE_DONE) {
r = RESUME_GUEST;
break;
}
#endif
run->papr_hcall.nr = cmd;
for (i = 0; i < 9; ++i) {
ulong gpr = kvmppc_get_gpr(vcpu, 4 + i);
run->papr_hcall.args[i] = gpr;
}
run->exit_reason = KVM_EXIT_PAPR_HCALL;
vcpu->arch.hcall_needed = 1;
r = RESUME_HOST;
} else if (vcpu->arch.osi_enabled &&
(((u32)kvmppc_get_gpr(vcpu, 3)) == OSI_SC_MAGIC_R3) &&
(((u32)kvmppc_get_gpr(vcpu, 4)) == OSI_SC_MAGIC_R4)) {
u64 *gprs = run->osi.gprs;
int i;
run->exit_reason = KVM_EXIT_OSI;
for (i = 0; i < 32; i++)
gprs[i] = kvmppc_get_gpr(vcpu, i);
vcpu->arch.osi_needed = 1;
r = RESUME_HOST_NV;
} else if (!(vcpu->arch.shared->msr & MSR_PR) &&
(((u32)kvmppc_get_gpr(vcpu, 0)) == KVM_SC_MAGIC_R0)) {
kvmppc_set_gpr(vcpu, 3, kvmppc_kvm_pv(vcpu));
r = RESUME_GUEST;
} else {
vcpu->stat.syscall_exits++;
kvmppc_book3s_queue_irqprio(vcpu, exit_nr);
r = RESUME_GUEST;
}
break;
case BOOK3S_INTERRUPT_FP_UNAVAIL:
case BOOK3S_INTERRUPT_ALTIVEC:
case BOOK3S_INTERRUPT_VSX:
{
int ext_msr = 0;
switch (exit_nr) {
case BOOK3S_INTERRUPT_FP_UNAVAIL: ext_msr = MSR_FP; break;
case BOOK3S_INTERRUPT_ALTIVEC: ext_msr = MSR_VEC; break;
case BOOK3S_INTERRUPT_VSX: ext_msr = MSR_VSX; break;
}
switch (kvmppc_check_ext(vcpu, exit_nr)) {
case EMULATE_DONE:
r = kvmppc_handle_ext(vcpu, exit_nr, ext_msr);
break;
case EMULATE_FAIL:
goto program_interrupt;
break;
default:
break;
}
break;
}
case BOOK3S_INTERRUPT_ALIGNMENT:
if (kvmppc_read_inst(vcpu) == EMULATE_DONE) {
vcpu->arch.shared->dsisr = kvmppc_alignment_dsisr(vcpu,
kvmppc_get_last_inst(vcpu));
vcpu->arch.shared->dar = kvmppc_alignment_dar(vcpu,
kvmppc_get_last_inst(vcpu));
kvmppc_book3s_queue_irqprio(vcpu, exit_nr);
}
r = RESUME_GUEST;
break;
case BOOK3S_INTERRUPT_MACHINE_CHECK:
case BOOK3S_INTERRUPT_TRACE:
kvmppc_book3s_queue_irqprio(vcpu, exit_nr);
r = RESUME_GUEST;
break;
default:
{
ulong shadow_srr1 = vcpu->arch.shadow_srr1;
printk(KERN_EMERG "exit_nr=0x%x | pc=0x%lx | msr=0x%lx\n",
exit_nr, kvmppc_get_pc(vcpu), shadow_srr1);
r = RESUME_HOST;
BUG();
break;
}
}
if (!(r & RESUME_HOST)) {
local_irq_disable();
s = kvmppc_prepare_to_enter(vcpu);
if (s <= 0) {
local_irq_enable();
r = s;
} else {
kvmppc_fix_ee_before_entry();
}
kvmppc_handle_lost_ext(vcpu);
}
trace_kvm_book3s_reenter(r, vcpu);
return r;
}
static int kvm_arch_vcpu_ioctl_get_sregs_pr(struct kvm_vcpu *vcpu,
struct kvm_sregs *sregs)
{
struct kvmppc_vcpu_book3s *vcpu3s = to_book3s(vcpu);
int i;
sregs->pvr = vcpu->arch.pvr;
sregs->u.s.sdr1 = to_book3s(vcpu)->sdr1;
if (vcpu->arch.hflags & BOOK3S_HFLAG_SLB) {
for (i = 0; i < 64; i++) {
sregs->u.s.ppc64.slb[i].slbe = vcpu->arch.slb[i].orige | i;
sregs->u.s.ppc64.slb[i].slbv = vcpu->arch.slb[i].origv;
}
} else {
for (i = 0; i < 16; i++)
sregs->u.s.ppc32.sr[i] = vcpu->arch.shared->sr[i];
for (i = 0; i < 8; i++) {
sregs->u.s.ppc32.ibat[i] = vcpu3s->ibat[i].raw;
sregs->u.s.ppc32.dbat[i] = vcpu3s->dbat[i].raw;
}
}
return 0;
}
static int kvm_arch_vcpu_ioctl_set_sregs_pr(struct kvm_vcpu *vcpu,
struct kvm_sregs *sregs)
{
struct kvmppc_vcpu_book3s *vcpu3s = to_book3s(vcpu);
int i;
kvmppc_set_pvr_pr(vcpu, sregs->pvr);
vcpu3s->sdr1 = sregs->u.s.sdr1;
if (vcpu->arch.hflags & BOOK3S_HFLAG_SLB) {
for (i = 0; i < 64; i++) {
vcpu->arch.mmu.slbmte(vcpu, sregs->u.s.ppc64.slb[i].slbv,
sregs->u.s.ppc64.slb[i].slbe);
}
} else {
for (i = 0; i < 16; i++) {
vcpu->arch.mmu.mtsrin(vcpu, i, sregs->u.s.ppc32.sr[i]);
}
for (i = 0; i < 8; i++) {
kvmppc_set_bat(vcpu, &(vcpu3s->ibat[i]), false,
(u32)sregs->u.s.ppc32.ibat[i]);
kvmppc_set_bat(vcpu, &(vcpu3s->ibat[i]), true,
(u32)(sregs->u.s.ppc32.ibat[i] >> 32));
kvmppc_set_bat(vcpu, &(vcpu3s->dbat[i]), false,
(u32)sregs->u.s.ppc32.dbat[i]);
kvmppc_set_bat(vcpu, &(vcpu3s->dbat[i]), true,
(u32)(sregs->u.s.ppc32.dbat[i] >> 32));
}
}
kvmppc_mmu_pte_flush(vcpu, 0, 0);
return 0;
}
static int kvmppc_get_one_reg_pr(struct kvm_vcpu *vcpu, u64 id,
union kvmppc_one_reg *val)
{
int r = 0;
switch (id) {
case KVM_REG_PPC_HIOR:
*val = get_reg_val(id, to_book3s(vcpu)->hior);
break;
#ifdef CONFIG_VSX
case KVM_REG_PPC_VSR0 ... KVM_REG_PPC_VSR31: {
long int i = id - KVM_REG_PPC_VSR0;
if (!cpu_has_feature(CPU_FTR_VSX)) {
r = -ENXIO;
break;
}
val->vsxval[0] = vcpu->arch.fpr[i];
val->vsxval[1] = vcpu->arch.vsr[i];
break;
}
#endif
default:
r = -EINVAL;
break;
}
return r;
}
static int kvmppc_set_one_reg_pr(struct kvm_vcpu *vcpu, u64 id,
union kvmppc_one_reg *val)
{
int r = 0;
switch (id) {
case KVM_REG_PPC_HIOR:
to_book3s(vcpu)->hior = set_reg_val(id, *val);
to_book3s(vcpu)->hior_explicit = true;
break;
#ifdef CONFIG_VSX
case KVM_REG_PPC_VSR0 ... KVM_REG_PPC_VSR31: {
long int i = id - KVM_REG_PPC_VSR0;
if (!cpu_has_feature(CPU_FTR_VSX)) {
r = -ENXIO;
break;
}
vcpu->arch.fpr[i] = val->vsxval[0];
vcpu->arch.vsr[i] = val->vsxval[1];
break;
}
#endif
default:
r = -EINVAL;
break;
}
return r;
}
static struct kvm_vcpu *kvmppc_core_vcpu_create_pr(struct kvm *kvm,
unsigned int id)
{
struct kvmppc_vcpu_book3s *vcpu_book3s;
struct kvm_vcpu *vcpu;
int err = -ENOMEM;
unsigned long p;
vcpu = kmem_cache_zalloc(kvm_vcpu_cache, GFP_KERNEL);
if (!vcpu)
goto out;
vcpu_book3s = vzalloc(sizeof(struct kvmppc_vcpu_book3s));
if (!vcpu_book3s)
goto free_vcpu;
vcpu->arch.book3s = vcpu_book3s;
#ifdef CONFIG_KVM_BOOK3S_32
vcpu->arch.shadow_vcpu =
kzalloc(sizeof(*vcpu->arch.shadow_vcpu), GFP_KERNEL);
if (!vcpu->arch.shadow_vcpu)
goto free_vcpu3s;
#endif
err = kvm_vcpu_init(vcpu, kvm, id);
if (err)
goto free_shadow_vcpu;
err = -ENOMEM;
p = __get_free_page(GFP_KERNEL|__GFP_ZERO);
if (!p)
goto uninit_vcpu;
vcpu->arch.shared = (void *)(p + PAGE_SIZE - 4096);
#ifdef CONFIG_PPC_BOOK3S_64
vcpu->arch.pvr = 0x3C0301;
if (mmu_has_feature(MMU_FTR_1T_SEGMENT))
vcpu->arch.pvr = mfspr(SPRN_PVR);
#else
vcpu->arch.pvr = 0x84202;
#endif
kvmppc_set_pvr_pr(vcpu, vcpu->arch.pvr);
vcpu->arch.slb_nr = 64;
vcpu->arch.shadow_msr = MSR_USER64;
err = kvmppc_mmu_init(vcpu);
if (err < 0)
goto uninit_vcpu;
return vcpu;
uninit_vcpu:
kvm_vcpu_uninit(vcpu);
free_shadow_vcpu:
#ifdef CONFIG_KVM_BOOK3S_32
kfree(vcpu->arch.shadow_vcpu);
free_vcpu3s:
#endif
vfree(vcpu_book3s);
free_vcpu:
kmem_cache_free(kvm_vcpu_cache, vcpu);
out:
return ERR_PTR(err);
}
static void kvmppc_core_vcpu_free_pr(struct kvm_vcpu *vcpu)
{
struct kvmppc_vcpu_book3s *vcpu_book3s = to_book3s(vcpu);
free_page((unsigned long)vcpu->arch.shared & PAGE_MASK);
kvm_vcpu_uninit(vcpu);
#ifdef CONFIG_KVM_BOOK3S_32
kfree(vcpu->arch.shadow_vcpu);
#endif
vfree(vcpu_book3s);
kmem_cache_free(kvm_vcpu_cache, vcpu);
}
static int kvmppc_vcpu_run_pr(struct kvm_run *kvm_run, struct kvm_vcpu *vcpu)
{
int ret;
struct thread_fp_state fp;
int fpexc_mode;
#ifdef CONFIG_ALTIVEC
struct thread_vr_state vr;
unsigned long uninitialized_var(vrsave);
int used_vr;
#endif
#ifdef CONFIG_VSX
int used_vsr;
#endif
ulong ext_msr;
if (!vcpu->arch.sane) {
kvm_run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = -EINVAL;
goto out;
}
local_irq_disable();
ret = kvmppc_prepare_to_enter(vcpu);
if (ret <= 0) {
local_irq_enable();
goto out;
}
if (current->thread.regs->msr & MSR_FP)
giveup_fpu(current);
fp = current->thread.fp_state;
fpexc_mode = current->thread.fpexc_mode;
#ifdef CONFIG_ALTIVEC
used_vr = current->thread.used_vr;
if (used_vr) {
if (current->thread.regs->msr & MSR_VEC)
giveup_altivec(current);
vr = current->thread.vr_state;
vrsave = current->thread.vrsave;
}
#endif
#ifdef CONFIG_VSX
used_vsr = current->thread.used_vsr;
if (used_vsr && (current->thread.regs->msr & MSR_VSX))
__giveup_vsx(current);
#endif
ext_msr = current->thread.regs->msr;
if (vcpu->arch.shared->msr & MSR_FP)
kvmppc_handle_ext(vcpu, BOOK3S_INTERRUPT_FP_UNAVAIL, MSR_FP);
kvmppc_fix_ee_before_entry();
ret = __kvmppc_vcpu_run(kvm_run, vcpu);
kvmppc_giveup_ext(vcpu, MSR_FP | MSR_VEC | MSR_VSX);
current->thread.regs->msr = ext_msr;
current->thread.fp_state = fp;
current->thread.fpexc_mode = fpexc_mode;
#ifdef CONFIG_ALTIVEC
if (used_vr && current->thread.used_vr) {
current->thread.vr_state = vr;
current->thread.vrsave = vrsave;
}
current->thread.used_vr = used_vr;
#endif
#ifdef CONFIG_VSX
current->thread.used_vsr = used_vsr;
#endif
out:
vcpu->mode = OUTSIDE_GUEST_MODE;
return ret;
}
static int kvm_vm_ioctl_get_dirty_log_pr(struct kvm *kvm,
struct kvm_dirty_log *log)
{
struct kvm_memory_slot *memslot;
struct kvm_vcpu *vcpu;
ulong ga, ga_end;
int is_dirty = 0;
int r;
unsigned long n;
mutex_lock(&kvm->slots_lock);
r = kvm_get_dirty_log(kvm, log, &is_dirty);
if (r)
goto out;
if (is_dirty) {
memslot = id_to_memslot(kvm->memslots, log->slot);
ga = memslot->base_gfn << PAGE_SHIFT;
ga_end = ga + (memslot->npages << PAGE_SHIFT);
kvm_for_each_vcpu(n, vcpu, kvm)
kvmppc_mmu_pte_pflush(vcpu, ga, ga_end);
n = kvm_dirty_bitmap_bytes(memslot);
memset(memslot->dirty_bitmap, 0, n);
}
r = 0;
out:
mutex_unlock(&kvm->slots_lock);
return r;
}
static void kvmppc_core_flush_memslot_pr(struct kvm *kvm,
struct kvm_memory_slot *memslot)
{
return;
}
static int kvmppc_core_prepare_memory_region_pr(struct kvm *kvm,
struct kvm_memory_slot *memslot,
struct kvm_userspace_memory_region *mem)
{
return 0;
}
static void kvmppc_core_commit_memory_region_pr(struct kvm *kvm,
struct kvm_userspace_memory_region *mem,
const struct kvm_memory_slot *old)
{
return;
}
static void kvmppc_core_free_memslot_pr(struct kvm_memory_slot *free,
struct kvm_memory_slot *dont)
{
return;
}
static int kvmppc_core_create_memslot_pr(struct kvm_memory_slot *slot,
unsigned long npages)
{
return 0;
}
static int kvm_vm_ioctl_get_smmu_info_pr(struct kvm *kvm,
struct kvm_ppc_smmu_info *info)
{
long int i;
struct kvm_vcpu *vcpu;
info->flags = 0;
info->slb_size = 64;
info->sps[0].page_shift = 12;
info->sps[0].slb_enc = 0;
info->sps[0].enc[0].page_shift = 12;
info->sps[0].enc[0].pte_enc = 0;
i = 1;
vcpu = kvm_get_vcpu(kvm, 0);
if (vcpu && (vcpu->arch.hflags & BOOK3S_HFLAG_MULTI_PGSIZE)) {
info->flags = KVM_PPC_1T_SEGMENTS;
info->sps[i].page_shift = 16;
info->sps[i].slb_enc = SLB_VSID_L | SLB_VSID_LP_01;
info->sps[i].enc[0].page_shift = 16;
info->sps[i].enc[0].pte_enc = 1;
++i;
}
info->sps[i].page_shift = 24;
info->sps[i].slb_enc = SLB_VSID_L;
info->sps[i].enc[0].page_shift = 24;
info->sps[i].enc[0].pte_enc = 0;
return 0;
}
static int kvm_vm_ioctl_get_smmu_info_pr(struct kvm *kvm,
struct kvm_ppc_smmu_info *info)
{
BUG();
}
static int kvmppc_core_init_vm_pr(struct kvm *kvm)
{
mutex_init(&kvm->arch.hpt_mutex);
if (firmware_has_feature(FW_FEATURE_SET_MODE)) {
spin_lock(&kvm_global_user_count_lock);
if (++kvm_global_user_count == 1)
pSeries_disable_reloc_on_exc();
spin_unlock(&kvm_global_user_count_lock);
}
return 0;
}
static void kvmppc_core_destroy_vm_pr(struct kvm *kvm)
{
#ifdef CONFIG_PPC64
WARN_ON(!list_empty(&kvm->arch.spapr_tce_tables));
#endif
if (firmware_has_feature(FW_FEATURE_SET_MODE)) {
spin_lock(&kvm_global_user_count_lock);
BUG_ON(kvm_global_user_count == 0);
if (--kvm_global_user_count == 0)
pSeries_enable_reloc_on_exc();
spin_unlock(&kvm_global_user_count_lock);
}
}
static int kvmppc_core_check_processor_compat_pr(void)
{
return 0;
}
static long kvm_arch_vm_ioctl_pr(struct file *filp,
unsigned int ioctl, unsigned long arg)
{
return -ENOTTY;
}
int kvmppc_book3s_init_pr(void)
{
int r;
r = kvmppc_core_check_processor_compat_pr();
if (r < 0)
return r;
kvm_ops_pr.owner = THIS_MODULE;
kvmppc_pr_ops = &kvm_ops_pr;
r = kvmppc_mmu_hpte_sysinit();
return r;
}
void kvmppc_book3s_exit_pr(void)
{
kvmppc_pr_ops = NULL;
kvmppc_mmu_hpte_sysexit();
}
