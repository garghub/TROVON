static inline void rm_writeb(unsigned long paddr, u8 val)
{
__asm__ __volatile__("sync; stbcix %0,0,%1"
: : "r" (val), "r" (paddr) : "memory");
}
static void icp_rm_set_vcpu_irq(struct kvm_vcpu *vcpu,
struct kvm_vcpu *this_vcpu)
{
struct kvmppc_icp *this_icp = this_vcpu->arch.icp;
unsigned long xics_phys;
int cpu;
vcpu->stat.queue_intr++;
set_bit(BOOK3S_IRQPRIO_EXTERNAL_LEVEL, &vcpu->arch.pending_exceptions);
if (vcpu == this_vcpu) {
mtspr(SPRN_LPCR, mfspr(SPRN_LPCR) | LPCR_MER);
return;
}
cpu = vcpu->cpu;
if (cpu < 0 || cpu >= nr_cpu_ids) {
this_icp->rm_action |= XICS_RM_KICK_VCPU;
this_icp->rm_kick_target = vcpu;
return;
}
cpu += vcpu->arch.ptid;
xics_phys = paca[cpu].kvm_hstate.xics_phys;
rm_writeb(xics_phys + XICS_MFRR, IPI_PRIORITY);
}
static void icp_rm_clr_vcpu_irq(struct kvm_vcpu *vcpu)
{
clear_bit(BOOK3S_IRQPRIO_EXTERNAL_LEVEL,
&vcpu->arch.pending_exceptions);
mtspr(SPRN_LPCR, mfspr(SPRN_LPCR) & ~LPCR_MER);
}
static inline bool icp_rm_try_update(struct kvmppc_icp *icp,
union kvmppc_icp_state old,
union kvmppc_icp_state new)
{
struct kvm_vcpu *this_vcpu = local_paca->kvm_hstate.kvm_vcpu;
bool success;
new.out_ee = (new.xisr && (new.pending_pri < new.cppr));
success = cmpxchg64(&icp->state.raw, old.raw, new.raw) == old.raw;
if (!success)
goto bail;
if (new.out_ee)
icp_rm_set_vcpu_irq(icp->vcpu, this_vcpu);
this_vcpu->arch.icp->rm_dbgstate = new;
this_vcpu->arch.icp->rm_dbgtgt = icp->vcpu;
bail:
return success;
}
static inline int check_too_hard(struct kvmppc_xics *xics,
struct kvmppc_icp *icp)
{
return (xics->real_mode_dbg || icp->rm_action) ? H_TOO_HARD : H_SUCCESS;
}
static void icp_rm_down_cppr(struct kvmppc_xics *xics, struct kvmppc_icp *icp,
u8 new_cppr)
{
union kvmppc_icp_state old_state, new_state;
bool resend;
do {
old_state = new_state = READ_ONCE(icp->state);
new_state.cppr = new_cppr;
if (new_state.mfrr < new_cppr &&
new_state.mfrr <= new_state.pending_pri) {
new_state.pending_pri = new_state.mfrr;
new_state.xisr = XICS_IPI;
}
resend = new_state.need_resend;
new_state.need_resend = 0;
} while (!icp_rm_try_update(icp, old_state, new_state));
if (resend) {
icp->rm_action |= XICS_RM_CHECK_RESEND;
icp->rm_resend_icp = icp;
}
}
unsigned long kvmppc_rm_h_xirr(struct kvm_vcpu *vcpu)
{
union kvmppc_icp_state old_state, new_state;
struct kvmppc_xics *xics = vcpu->kvm->arch.xics;
struct kvmppc_icp *icp = vcpu->arch.icp;
u32 xirr;
if (!xics || !xics->real_mode)
return H_TOO_HARD;
icp_rm_clr_vcpu_irq(icp->vcpu);
do {
old_state = new_state = READ_ONCE(icp->state);
xirr = old_state.xisr | (((u32)old_state.cppr) << 24);
if (!old_state.xisr)
break;
new_state.cppr = new_state.pending_pri;
new_state.pending_pri = 0xff;
new_state.xisr = 0;
} while (!icp_rm_try_update(icp, old_state, new_state));
vcpu->arch.gpr[4] = xirr;
return check_too_hard(xics, icp);
}
int kvmppc_rm_h_ipi(struct kvm_vcpu *vcpu, unsigned long server,
unsigned long mfrr)
{
union kvmppc_icp_state old_state, new_state;
struct kvmppc_xics *xics = vcpu->kvm->arch.xics;
struct kvmppc_icp *icp, *this_icp = vcpu->arch.icp;
u32 reject;
bool resend;
bool local;
if (!xics || !xics->real_mode)
return H_TOO_HARD;
local = this_icp->server_num == server;
if (local)
icp = this_icp;
else
icp = kvmppc_xics_find_server(vcpu->kvm, server);
if (!icp)
return H_PARAMETER;
do {
old_state = new_state = READ_ONCE(icp->state);
new_state.mfrr = mfrr;
reject = 0;
resend = false;
if (mfrr < new_state.cppr) {
if (mfrr <= new_state.pending_pri) {
reject = new_state.xisr;
new_state.pending_pri = mfrr;
new_state.xisr = XICS_IPI;
}
}
if (mfrr > old_state.mfrr) {
resend = new_state.need_resend;
new_state.need_resend = 0;
}
} while (!icp_rm_try_update(icp, old_state, new_state));
if (reject && reject != XICS_IPI) {
this_icp->rm_action |= XICS_RM_REJECT;
this_icp->rm_reject = reject;
}
if (resend) {
this_icp->rm_action |= XICS_RM_CHECK_RESEND;
this_icp->rm_resend_icp = icp;
}
return check_too_hard(xics, this_icp);
}
int kvmppc_rm_h_cppr(struct kvm_vcpu *vcpu, unsigned long cppr)
{
union kvmppc_icp_state old_state, new_state;
struct kvmppc_xics *xics = vcpu->kvm->arch.xics;
struct kvmppc_icp *icp = vcpu->arch.icp;
u32 reject;
if (!xics || !xics->real_mode)
return H_TOO_HARD;
if (cppr > icp->state.cppr) {
icp_rm_down_cppr(xics, icp, cppr);
goto bail;
} else if (cppr == icp->state.cppr)
return H_SUCCESS;
icp_rm_clr_vcpu_irq(icp->vcpu);
do {
old_state = new_state = READ_ONCE(icp->state);
reject = 0;
new_state.cppr = cppr;
if (cppr <= new_state.pending_pri) {
reject = new_state.xisr;
new_state.xisr = 0;
new_state.pending_pri = 0xff;
}
} while (!icp_rm_try_update(icp, old_state, new_state));
if (reject && reject != XICS_IPI) {
icp->rm_action |= XICS_RM_REJECT;
icp->rm_reject = reject;
}
bail:
return check_too_hard(xics, icp);
}
int kvmppc_rm_h_eoi(struct kvm_vcpu *vcpu, unsigned long xirr)
{
struct kvmppc_xics *xics = vcpu->kvm->arch.xics;
struct kvmppc_icp *icp = vcpu->arch.icp;
struct kvmppc_ics *ics;
struct ics_irq_state *state;
u32 irq = xirr & 0x00ffffff;
u16 src;
if (!xics || !xics->real_mode)
return H_TOO_HARD;
icp_rm_down_cppr(xics, icp, xirr >> 24);
if (irq == XICS_IPI)
goto bail;
ics = kvmppc_xics_find_ics(xics, irq, &src);
if (!ics)
goto bail;
state = &ics->irq_state[src];
if (state->asserted) {
icp->rm_action |= XICS_RM_REJECT;
icp->rm_reject = irq;
}
if (!hlist_empty(&vcpu->kvm->irq_ack_notifier_list)) {
icp->rm_action |= XICS_RM_NOTIFY_EOI;
icp->rm_eoied_irq = irq;
}
bail:
return check_too_hard(xics, icp);
}
