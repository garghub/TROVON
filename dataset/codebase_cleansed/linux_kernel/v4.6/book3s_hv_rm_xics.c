static void ics_rm_check_resend(struct kvmppc_xics *xics,
struct kvmppc_ics *ics, struct kvmppc_icp *icp)
{
int i;
arch_spin_lock(&ics->lock);
for (i = 0; i < KVMPPC_XICS_IRQ_PER_ICS; i++) {
struct ics_irq_state *state = &ics->irq_state[i];
if (!state->resend)
continue;
arch_spin_unlock(&ics->lock);
icp_rm_deliver_irq(xics, icp, state->number);
arch_spin_lock(&ics->lock);
}
arch_spin_unlock(&ics->lock);
}
static inline void icp_send_hcore_msg(int hcore, struct kvm_vcpu *vcpu)
{
int hcpu;
hcpu = hcore << threads_shift;
kvmppc_host_rm_ops_hv->rm_core[hcore].rm_data = vcpu;
smp_muxed_ipi_set_message(hcpu, PPC_MSG_RM_HOST_ACTION);
icp_native_cause_ipi_rm(hcpu);
}
static inline void icp_send_hcore_msg(int hcore, struct kvm_vcpu *vcpu) { }
static inline int grab_next_hostcore(int start,
struct kvmppc_host_rm_core *rm_core, int max, int action)
{
bool success;
int core;
union kvmppc_rm_state old, new;
for (core = start + 1; core < max; core++) {
old = new = READ_ONCE(rm_core[core].rm_state);
if (!old.in_host || old.rm_action)
continue;
new.rm_action = action;
success = cmpxchg64(&rm_core[core].rm_state.raw,
old.raw, new.raw) == old.raw;
if (success) {
smp_wmb();
return core;
}
}
return -1;
}
static inline int find_available_hostcore(int action)
{
int core;
int my_core = smp_processor_id() >> threads_shift;
struct kvmppc_host_rm_core *rm_core = kvmppc_host_rm_ops_hv->rm_core;
core = grab_next_hostcore(my_core, rm_core, cpu_nr_cores(), action);
if (core == -1)
core = grab_next_hostcore(core, rm_core, my_core, action);
return core;
}
static void icp_rm_set_vcpu_irq(struct kvm_vcpu *vcpu,
struct kvm_vcpu *this_vcpu)
{
struct kvmppc_icp *this_icp = this_vcpu->arch.icp;
int cpu;
int hcore;
vcpu->stat.queue_intr++;
set_bit(BOOK3S_IRQPRIO_EXTERNAL_LEVEL, &vcpu->arch.pending_exceptions);
if (vcpu == this_vcpu) {
mtspr(SPRN_LPCR, mfspr(SPRN_LPCR) | LPCR_MER);
return;
}
cpu = vcpu->arch.thread_cpu;
if (cpu < 0 || cpu >= nr_cpu_ids) {
hcore = -1;
if (kvmppc_host_rm_ops_hv && h_ipi_redirect)
hcore = find_available_hostcore(XICS_RM_KICK_VCPU);
if (hcore != -1) {
icp_send_hcore_msg(hcore, vcpu);
} else {
this_icp->rm_action |= XICS_RM_KICK_VCPU;
this_icp->rm_kick_target = vcpu;
}
return;
}
smp_mb();
kvmhv_rm_send_ipi(cpu);
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
static void icp_rm_check_resend(struct kvmppc_xics *xics,
struct kvmppc_icp *icp)
{
u32 icsid;
smp_rmb();
for_each_set_bit(icsid, icp->resend_map, xics->max_icsid + 1) {
struct kvmppc_ics *ics = xics->ics[icsid];
if (!test_and_clear_bit(icsid, icp->resend_map))
continue;
if (!ics)
continue;
ics_rm_check_resend(xics, ics, icp);
}
}
static bool icp_rm_try_to_deliver(struct kvmppc_icp *icp, u32 irq, u8 priority,
u32 *reject)
{
union kvmppc_icp_state old_state, new_state;
bool success;
do {
old_state = new_state = READ_ONCE(icp->state);
*reject = 0;
success = new_state.cppr > priority &&
new_state.mfrr > priority &&
new_state.pending_pri > priority;
if (success) {
*reject = new_state.xisr;
new_state.xisr = irq;
new_state.pending_pri = priority;
} else {
new_state.need_resend = true;
}
} while (!icp_rm_try_update(icp, old_state, new_state));
return success;
}
static void icp_rm_deliver_irq(struct kvmppc_xics *xics, struct kvmppc_icp *icp,
u32 new_irq)
{
struct ics_irq_state *state;
struct kvmppc_ics *ics;
u32 reject;
u16 src;
again:
ics = kvmppc_xics_find_ics(xics, new_irq, &src);
if (!ics) {
xics->err_noics++;
return;
}
state = &ics->irq_state[src];
arch_spin_lock(&ics->lock);
if (!icp || state->server != icp->server_num) {
icp = kvmppc_xics_find_server(xics->kvm, state->server);
if (!icp) {
xics->err_noicp++;
goto out;
}
}
state->resend = 0;
if (state->priority == MASKED) {
state->masked_pending = 1;
goto out;
}
if (icp_rm_try_to_deliver(icp, new_irq, state->priority, &reject)) {
if (reject && reject != XICS_IPI) {
arch_spin_unlock(&ics->lock);
new_irq = reject;
goto again;
}
} else {
set_bit(ics->icsid, icp->resend_map);
state->resend = 1;
smp_mb();
if (!icp->state.need_resend) {
arch_spin_unlock(&ics->lock);
goto again;
}
}
out:
arch_spin_unlock(&ics->lock);
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
icp->n_check_resend++;
icp_rm_check_resend(xics, icp);
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
this_icp->n_reject++;
icp_rm_deliver_irq(xics, icp, reject);
}
if (resend) {
this_icp->n_check_resend++;
icp_rm_check_resend(xics, icp);
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
icp->n_reject++;
icp_rm_deliver_irq(xics, icp, reject);
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
icp->n_reject++;
icp_rm_deliver_irq(xics, icp, irq);
}
if (!hlist_empty(&vcpu->kvm->irq_ack_notifier_list)) {
icp->rm_action |= XICS_RM_NOTIFY_EOI;
icp->rm_eoied_irq = irq;
}
bail:
return check_too_hard(xics, icp);
}
static void rm_host_ipi_action(int action, void *data)
{
switch (action) {
case XICS_RM_KICK_VCPU:
kvmppc_host_rm_ops_hv->vcpu_kick(data);
break;
default:
WARN(1, "Unexpected rm_action=%d data=%p\n", action, data);
break;
}
}
void kvmppc_xics_ipi_action(void)
{
int core;
unsigned int cpu = smp_processor_id();
struct kvmppc_host_rm_core *rm_corep;
core = cpu >> threads_shift;
rm_corep = &kvmppc_host_rm_ops_hv->rm_core[core];
if (rm_corep->rm_data) {
rm_host_ipi_action(rm_corep->rm_state.rm_action,
rm_corep->rm_data);
rm_corep->rm_data = NULL;
smp_wmb();
rm_corep->rm_state.rm_action = 0;
}
}
