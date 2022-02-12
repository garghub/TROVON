static void reload_slb(struct kvm_vcpu *vcpu)
{
struct slb_shadow *slb;
unsigned long i, n;
asm volatile("slbmte %0,%0; slbia" : : "r" (0));
slb = vcpu->arch.slb_shadow.pinned_addr;
if (!slb)
return;
n = min_t(u32, be32_to_cpu(slb->persistent), SLB_MIN_SIZE);
if ((void *) &slb->save_area[n] > vcpu->arch.slb_shadow.pinned_end)
return;
for (i = 0; i < n; ++i) {
unsigned long rb = be64_to_cpu(slb->save_area[i].esid);
unsigned long rs = be64_to_cpu(slb->save_area[i].vsid);
rb = (rb & ~0xFFFul) | i;
asm volatile("slbmte %0,%1" : : "r" (rs), "r" (rb));
}
}
static long kvmppc_realmode_mc_power7(struct kvm_vcpu *vcpu)
{
unsigned long srr1 = vcpu->arch.shregs.msr;
struct machine_check_event mce_evt;
long handled = 1;
if (srr1 & SRR1_MC_LDSTERR) {
unsigned long dsisr = vcpu->arch.shregs.dsisr;
if (dsisr & (DSISR_MC_SLB_PARMULTI | DSISR_MC_SLB_MULTI |
DSISR_MC_SLB_PARITY | DSISR_MC_DERAT_MULTI)) {
reload_slb(vcpu);
dsisr &= ~(DSISR_MC_SLB_PARMULTI | DSISR_MC_SLB_MULTI |
DSISR_MC_SLB_PARITY | DSISR_MC_DERAT_MULTI);
}
if (dsisr & DSISR_MC_TLB_MULTI) {
if (cur_cpu_spec && cur_cpu_spec->flush_tlb)
cur_cpu_spec->flush_tlb(TLB_INVAL_SCOPE_LPID);
dsisr &= ~DSISR_MC_TLB_MULTI;
}
if (dsisr & 0xffffffffUL)
handled = 0;
}
switch ((srr1 >> SRR1_MC_IFETCH_SH) & SRR1_MC_IFETCH_MASK) {
case 0:
break;
case SRR1_MC_IFETCH_SLBPAR:
case SRR1_MC_IFETCH_SLBMULTI:
case SRR1_MC_IFETCH_SLBPARMULTI:
reload_slb(vcpu);
break;
case SRR1_MC_IFETCH_TLBMULTI:
if (cur_cpu_spec && cur_cpu_spec->flush_tlb)
cur_cpu_spec->flush_tlb(TLB_INVAL_SCOPE_LPID);
break;
default:
handled = 0;
}
if (!get_mce_event(&mce_evt, MCE_EVENT_DONTRELEASE))
goto out;
if (mce_evt.version == MCE_V1 &&
(mce_evt.severity == MCE_SEV_NO_ERROR ||
mce_evt.disposition == MCE_DISPOSITION_RECOVERED))
handled = 1;
out:
if (vcpu->kvm->arch.fwnmi_enabled) {
memset(&vcpu->arch.mce_evt, 0, sizeof(vcpu->arch.mce_evt));
if (get_mce_event(&mce_evt, MCE_EVENT_RELEASE)) {
vcpu->arch.mce_evt = mce_evt;
}
} else
machine_check_queue_event();
return handled;
}
long kvmppc_realmode_machine_check(struct kvm_vcpu *vcpu)
{
return kvmppc_realmode_mc_power7(vcpu);
}
static inline int kvmppc_cur_subcore_size(void)
{
if (local_paca->kvm_hstate.kvm_split_mode)
return local_paca->kvm_hstate.kvm_split_mode->subcore_size;
return threads_per_subcore;
}
void kvmppc_subcore_enter_guest(void)
{
int thread_id, subcore_id;
thread_id = cpu_thread_in_core(local_paca->paca_index);
subcore_id = thread_id / kvmppc_cur_subcore_size();
local_paca->sibling_subcore_state->in_guest[subcore_id] = 1;
}
void kvmppc_subcore_exit_guest(void)
{
int thread_id, subcore_id;
thread_id = cpu_thread_in_core(local_paca->paca_index);
subcore_id = thread_id / kvmppc_cur_subcore_size();
local_paca->sibling_subcore_state->in_guest[subcore_id] = 0;
}
static bool kvmppc_tb_resync_required(void)
{
if (test_and_set_bit(CORE_TB_RESYNC_REQ_BIT,
&local_paca->sibling_subcore_state->flags))
return false;
return true;
}
static void kvmppc_tb_resync_done(void)
{
clear_bit(CORE_TB_RESYNC_REQ_BIT,
&local_paca->sibling_subcore_state->flags);
}
long kvmppc_realmode_hmi_handler(void)
{
int ptid = local_paca->kvm_hstate.ptid;
bool resync_req;
BUG_ON(ptid != 0);
__this_cpu_inc(irq_stat.hmi_exceptions);
resync_req = kvmppc_tb_resync_required();
kvmppc_subcore_exit_guest();
wait_for_subcore_guest_exit();
if (ppc_md.hmi_exception_early)
ppc_md.hmi_exception_early(NULL);
if (resync_req) {
opal_resync_timebase();
kvmppc_tb_resync_done();
} else {
wait_for_tb_resync();
}
return 0;
}
