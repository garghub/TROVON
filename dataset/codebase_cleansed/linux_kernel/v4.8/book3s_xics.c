static int ics_deliver_irq(struct kvmppc_xics *xics, u32 irq, u32 level)
{
struct ics_irq_state *state;
struct kvmppc_ics *ics;
u16 src;
XICS_DBG("ics deliver %#x (level: %d)\n", irq, level);
ics = kvmppc_xics_find_ics(xics, irq, &src);
if (!ics) {
XICS_DBG("ics_deliver_irq: IRQ 0x%06x not found !\n", irq);
return -EINVAL;
}
state = &ics->irq_state[src];
if (!state->exists)
return -EINVAL;
if ((level == 1 && state->lsi) || level == KVM_INTERRUPT_SET_LEVEL)
state->asserted = 1;
else if (level == 0 || level == KVM_INTERRUPT_UNSET) {
state->asserted = 0;
return 0;
}
icp_deliver_irq(xics, NULL, irq);
return 0;
}
static void ics_check_resend(struct kvmppc_xics *xics, struct kvmppc_ics *ics,
struct kvmppc_icp *icp)
{
int i;
unsigned long flags;
local_irq_save(flags);
arch_spin_lock(&ics->lock);
for (i = 0; i < KVMPPC_XICS_IRQ_PER_ICS; i++) {
struct ics_irq_state *state = &ics->irq_state[i];
if (!state->resend)
continue;
XICS_DBG("resend %#x prio %#x\n", state->number,
state->priority);
arch_spin_unlock(&ics->lock);
local_irq_restore(flags);
icp_deliver_irq(xics, icp, state->number);
local_irq_save(flags);
arch_spin_lock(&ics->lock);
}
arch_spin_unlock(&ics->lock);
local_irq_restore(flags);
}
static bool write_xive(struct kvmppc_xics *xics, struct kvmppc_ics *ics,
struct ics_irq_state *state,
u32 server, u32 priority, u32 saved_priority)
{
bool deliver;
unsigned long flags;
local_irq_save(flags);
arch_spin_lock(&ics->lock);
state->server = server;
state->priority = priority;
state->saved_priority = saved_priority;
deliver = false;
if ((state->masked_pending || state->resend) && priority != MASKED) {
state->masked_pending = 0;
deliver = true;
}
arch_spin_unlock(&ics->lock);
local_irq_restore(flags);
return deliver;
}
int kvmppc_xics_set_xive(struct kvm *kvm, u32 irq, u32 server, u32 priority)
{
struct kvmppc_xics *xics = kvm->arch.xics;
struct kvmppc_icp *icp;
struct kvmppc_ics *ics;
struct ics_irq_state *state;
u16 src;
if (!xics)
return -ENODEV;
ics = kvmppc_xics_find_ics(xics, irq, &src);
if (!ics)
return -EINVAL;
state = &ics->irq_state[src];
icp = kvmppc_xics_find_server(kvm, server);
if (!icp)
return -EINVAL;
XICS_DBG("set_xive %#x server %#x prio %#x MP:%d RS:%d\n",
irq, server, priority,
state->masked_pending, state->resend);
if (write_xive(xics, ics, state, server, priority, priority))
icp_deliver_irq(xics, icp, irq);
return 0;
}
int kvmppc_xics_get_xive(struct kvm *kvm, u32 irq, u32 *server, u32 *priority)
{
struct kvmppc_xics *xics = kvm->arch.xics;
struct kvmppc_ics *ics;
struct ics_irq_state *state;
u16 src;
unsigned long flags;
if (!xics)
return -ENODEV;
ics = kvmppc_xics_find_ics(xics, irq, &src);
if (!ics)
return -EINVAL;
state = &ics->irq_state[src];
local_irq_save(flags);
arch_spin_lock(&ics->lock);
*server = state->server;
*priority = state->priority;
arch_spin_unlock(&ics->lock);
local_irq_restore(flags);
return 0;
}
int kvmppc_xics_int_on(struct kvm *kvm, u32 irq)
{
struct kvmppc_xics *xics = kvm->arch.xics;
struct kvmppc_icp *icp;
struct kvmppc_ics *ics;
struct ics_irq_state *state;
u16 src;
if (!xics)
return -ENODEV;
ics = kvmppc_xics_find_ics(xics, irq, &src);
if (!ics)
return -EINVAL;
state = &ics->irq_state[src];
icp = kvmppc_xics_find_server(kvm, state->server);
if (!icp)
return -EINVAL;
if (write_xive(xics, ics, state, state->server, state->saved_priority,
state->saved_priority))
icp_deliver_irq(xics, icp, irq);
return 0;
}
int kvmppc_xics_int_off(struct kvm *kvm, u32 irq)
{
struct kvmppc_xics *xics = kvm->arch.xics;
struct kvmppc_ics *ics;
struct ics_irq_state *state;
u16 src;
if (!xics)
return -ENODEV;
ics = kvmppc_xics_find_ics(xics, irq, &src);
if (!ics)
return -EINVAL;
state = &ics->irq_state[src];
write_xive(xics, ics, state, state->server, MASKED, state->priority);
return 0;
}
static inline bool icp_try_update(struct kvmppc_icp *icp,
union kvmppc_icp_state old,
union kvmppc_icp_state new,
bool change_self)
{
bool success;
new.out_ee = (new.xisr && (new.pending_pri < new.cppr));
success = cmpxchg64(&icp->state.raw, old.raw, new.raw) == old.raw;
if (!success)
goto bail;
XICS_DBG("UPD [%04lx] - C:%02x M:%02x PP: %02x PI:%06x R:%d O:%d\n",
icp->server_num,
old.cppr, old.mfrr, old.pending_pri, old.xisr,
old.need_resend, old.out_ee);
XICS_DBG("UPD - C:%02x M:%02x PP: %02x PI:%06x R:%d O:%d\n",
new.cppr, new.mfrr, new.pending_pri, new.xisr,
new.need_resend, new.out_ee);
if (new.out_ee) {
kvmppc_book3s_queue_irqprio(icp->vcpu,
BOOK3S_INTERRUPT_EXTERNAL_LEVEL);
if (!change_self)
kvmppc_fast_vcpu_kick(icp->vcpu);
}
bail:
return success;
}
static void icp_check_resend(struct kvmppc_xics *xics,
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
ics_check_resend(xics, ics, icp);
}
}
static bool icp_try_to_deliver(struct kvmppc_icp *icp, u32 irq, u8 priority,
u32 *reject)
{
union kvmppc_icp_state old_state, new_state;
bool success;
XICS_DBG("try deliver %#x(P:%#x) to server %#lx\n", irq, priority,
icp->server_num);
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
} while (!icp_try_update(icp, old_state, new_state, false));
return success;
}
static void icp_deliver_irq(struct kvmppc_xics *xics, struct kvmppc_icp *icp,
u32 new_irq)
{
struct ics_irq_state *state;
struct kvmppc_ics *ics;
u32 reject;
u16 src;
unsigned long flags;
again:
ics = kvmppc_xics_find_ics(xics, new_irq, &src);
if (!ics) {
XICS_DBG("icp_deliver_irq: IRQ 0x%06x not found !\n", new_irq);
return;
}
state = &ics->irq_state[src];
local_irq_save(flags);
arch_spin_lock(&ics->lock);
if (!icp || state->server != icp->server_num) {
icp = kvmppc_xics_find_server(xics->kvm, state->server);
if (!icp) {
pr_warn("icp_deliver_irq: IRQ 0x%06x server 0x%x not found !\n",
new_irq, state->server);
goto out;
}
}
state->resend = 0;
if (state->priority == MASKED) {
XICS_DBG("irq %#x masked pending\n", new_irq);
state->masked_pending = 1;
goto out;
}
if (icp_try_to_deliver(icp, new_irq, state->priority, &reject)) {
if (reject && reject != XICS_IPI) {
arch_spin_unlock(&ics->lock);
local_irq_restore(flags);
new_irq = reject;
goto again;
}
} else {
set_bit(ics->icsid, icp->resend_map);
state->resend = 1;
smp_mb();
if (!icp->state.need_resend) {
arch_spin_unlock(&ics->lock);
local_irq_restore(flags);
goto again;
}
}
out:
arch_spin_unlock(&ics->lock);
local_irq_restore(flags);
}
static void icp_down_cppr(struct kvmppc_xics *xics, struct kvmppc_icp *icp,
u8 new_cppr)
{
union kvmppc_icp_state old_state, new_state;
bool resend;
do {
old_state = new_state = READ_ONCE(icp->state);
new_state.cppr = new_cppr;
if (new_state.mfrr < new_cppr &&
new_state.mfrr <= new_state.pending_pri) {
WARN_ON(new_state.xisr != XICS_IPI &&
new_state.xisr != 0);
new_state.pending_pri = new_state.mfrr;
new_state.xisr = XICS_IPI;
}
resend = new_state.need_resend;
new_state.need_resend = 0;
} while (!icp_try_update(icp, old_state, new_state, true));
if (resend)
icp_check_resend(xics, icp);
}
static noinline unsigned long kvmppc_h_xirr(struct kvm_vcpu *vcpu)
{
union kvmppc_icp_state old_state, new_state;
struct kvmppc_icp *icp = vcpu->arch.icp;
u32 xirr;
kvmppc_book3s_dequeue_irqprio(icp->vcpu,
BOOK3S_INTERRUPT_EXTERNAL_LEVEL);
do {
old_state = new_state = READ_ONCE(icp->state);
xirr = old_state.xisr | (((u32)old_state.cppr) << 24);
if (!old_state.xisr)
break;
new_state.cppr = new_state.pending_pri;
new_state.pending_pri = 0xff;
new_state.xisr = 0;
} while (!icp_try_update(icp, old_state, new_state, true));
XICS_DBG("h_xirr vcpu %d xirr %#x\n", vcpu->vcpu_id, xirr);
return xirr;
}
static noinline int kvmppc_h_ipi(struct kvm_vcpu *vcpu, unsigned long server,
unsigned long mfrr)
{
union kvmppc_icp_state old_state, new_state;
struct kvmppc_xics *xics = vcpu->kvm->arch.xics;
struct kvmppc_icp *icp;
u32 reject;
bool resend;
bool local;
XICS_DBG("h_ipi vcpu %d to server %lu mfrr %#lx\n",
vcpu->vcpu_id, server, mfrr);
icp = vcpu->arch.icp;
local = icp->server_num == server;
if (!local) {
icp = kvmppc_xics_find_server(vcpu->kvm, server);
if (!icp)
return H_PARAMETER;
}
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
} while (!icp_try_update(icp, old_state, new_state, local));
if (reject && reject != XICS_IPI)
icp_deliver_irq(xics, icp, reject);
if (resend)
icp_check_resend(xics, icp);
return H_SUCCESS;
}
static int kvmppc_h_ipoll(struct kvm_vcpu *vcpu, unsigned long server)
{
union kvmppc_icp_state state;
struct kvmppc_icp *icp;
icp = vcpu->arch.icp;
if (icp->server_num != server) {
icp = kvmppc_xics_find_server(vcpu->kvm, server);
if (!icp)
return H_PARAMETER;
}
state = READ_ONCE(icp->state);
kvmppc_set_gpr(vcpu, 4, ((u32)state.cppr << 24) | state.xisr);
kvmppc_set_gpr(vcpu, 5, state.mfrr);
return H_SUCCESS;
}
static noinline void kvmppc_h_cppr(struct kvm_vcpu *vcpu, unsigned long cppr)
{
union kvmppc_icp_state old_state, new_state;
struct kvmppc_xics *xics = vcpu->kvm->arch.xics;
struct kvmppc_icp *icp = vcpu->arch.icp;
u32 reject;
XICS_DBG("h_cppr vcpu %d cppr %#lx\n", vcpu->vcpu_id, cppr);
if (cppr > icp->state.cppr)
icp_down_cppr(xics, icp, cppr);
else if (cppr == icp->state.cppr)
return;
kvmppc_book3s_dequeue_irqprio(icp->vcpu,
BOOK3S_INTERRUPT_EXTERNAL_LEVEL);
do {
old_state = new_state = READ_ONCE(icp->state);
reject = 0;
new_state.cppr = cppr;
if (cppr <= new_state.pending_pri) {
reject = new_state.xisr;
new_state.xisr = 0;
new_state.pending_pri = 0xff;
}
} while (!icp_try_update(icp, old_state, new_state, true));
if (reject && reject != XICS_IPI)
icp_deliver_irq(xics, icp, reject);
}
static noinline int kvmppc_h_eoi(struct kvm_vcpu *vcpu, unsigned long xirr)
{
struct kvmppc_xics *xics = vcpu->kvm->arch.xics;
struct kvmppc_icp *icp = vcpu->arch.icp;
struct kvmppc_ics *ics;
struct ics_irq_state *state;
u32 irq = xirr & 0x00ffffff;
u16 src;
XICS_DBG("h_eoi vcpu %d eoi %#lx\n", vcpu->vcpu_id, xirr);
icp_down_cppr(xics, icp, xirr >> 24);
if (irq == XICS_IPI)
return H_SUCCESS;
ics = kvmppc_xics_find_ics(xics, irq, &src);
if (!ics) {
XICS_DBG("h_eoi: IRQ 0x%06x not found !\n", irq);
return H_PARAMETER;
}
state = &ics->irq_state[src];
if (state->asserted)
icp_deliver_irq(xics, icp, irq);
kvm_notify_acked_irq(vcpu->kvm, 0, irq);
return H_SUCCESS;
}
static noinline int kvmppc_xics_rm_complete(struct kvm_vcpu *vcpu, u32 hcall)
{
struct kvmppc_xics *xics = vcpu->kvm->arch.xics;
struct kvmppc_icp *icp = vcpu->arch.icp;
XICS_DBG("XICS_RM: H_%x completing, act: %x state: %lx tgt: %p\n",
hcall, icp->rm_action, icp->rm_dbgstate.raw, icp->rm_dbgtgt);
if (icp->rm_action & XICS_RM_KICK_VCPU) {
icp->n_rm_kick_vcpu++;
kvmppc_fast_vcpu_kick(icp->rm_kick_target);
}
if (icp->rm_action & XICS_RM_CHECK_RESEND) {
icp->n_rm_check_resend++;
icp_check_resend(xics, icp->rm_resend_icp);
}
if (icp->rm_action & XICS_RM_REJECT) {
icp->n_rm_reject++;
icp_deliver_irq(xics, icp, icp->rm_reject);
}
if (icp->rm_action & XICS_RM_NOTIFY_EOI) {
icp->n_rm_notify_eoi++;
kvm_notify_acked_irq(vcpu->kvm, 0, icp->rm_eoied_irq);
}
icp->rm_action = 0;
return H_SUCCESS;
}
int kvmppc_xics_hcall(struct kvm_vcpu *vcpu, u32 req)
{
struct kvmppc_xics *xics = vcpu->kvm->arch.xics;
unsigned long res;
int rc = H_SUCCESS;
if (!xics || !vcpu->arch.icp)
return H_HARDWARE;
switch (req) {
case H_XIRR_X:
res = kvmppc_h_xirr(vcpu);
kvmppc_set_gpr(vcpu, 4, res);
kvmppc_set_gpr(vcpu, 5, get_tb());
return rc;
case H_IPOLL:
rc = kvmppc_h_ipoll(vcpu, kvmppc_get_gpr(vcpu, 4));
return rc;
}
if (xics->real_mode && is_kvmppc_hv_enabled(vcpu->kvm))
return kvmppc_xics_rm_complete(vcpu, req);
switch (req) {
case H_XIRR:
res = kvmppc_h_xirr(vcpu);
kvmppc_set_gpr(vcpu, 4, res);
break;
case H_CPPR:
kvmppc_h_cppr(vcpu, kvmppc_get_gpr(vcpu, 4));
break;
case H_EOI:
rc = kvmppc_h_eoi(vcpu, kvmppc_get_gpr(vcpu, 4));
break;
case H_IPI:
rc = kvmppc_h_ipi(vcpu, kvmppc_get_gpr(vcpu, 4),
kvmppc_get_gpr(vcpu, 5));
break;
}
return rc;
}
static int xics_debug_show(struct seq_file *m, void *private)
{
struct kvmppc_xics *xics = m->private;
struct kvm *kvm = xics->kvm;
struct kvm_vcpu *vcpu;
int icsid, i;
unsigned long flags;
unsigned long t_rm_kick_vcpu, t_rm_check_resend;
unsigned long t_rm_reject, t_rm_notify_eoi;
unsigned long t_reject, t_check_resend;
if (!kvm)
return 0;
t_rm_kick_vcpu = 0;
t_rm_notify_eoi = 0;
t_rm_check_resend = 0;
t_rm_reject = 0;
t_check_resend = 0;
t_reject = 0;
seq_printf(m, "=========\nICP state\n=========\n");
kvm_for_each_vcpu(i, vcpu, kvm) {
struct kvmppc_icp *icp = vcpu->arch.icp;
union kvmppc_icp_state state;
if (!icp)
continue;
state.raw = READ_ONCE(icp->state.raw);
seq_printf(m, "cpu server %#lx XIRR:%#x PPRI:%#x CPPR:%#x MFRR:%#x OUT:%d NR:%d\n",
icp->server_num, state.xisr,
state.pending_pri, state.cppr, state.mfrr,
state.out_ee, state.need_resend);
t_rm_kick_vcpu += icp->n_rm_kick_vcpu;
t_rm_notify_eoi += icp->n_rm_notify_eoi;
t_rm_check_resend += icp->n_rm_check_resend;
t_rm_reject += icp->n_rm_reject;
t_check_resend += icp->n_check_resend;
t_reject += icp->n_reject;
}
seq_printf(m, "ICP Guest->Host totals: kick_vcpu=%lu check_resend=%lu reject=%lu notify_eoi=%lu\n",
t_rm_kick_vcpu, t_rm_check_resend,
t_rm_reject, t_rm_notify_eoi);
seq_printf(m, "ICP Real Mode totals: check_resend=%lu resend=%lu\n",
t_check_resend, t_reject);
for (icsid = 0; icsid <= KVMPPC_XICS_MAX_ICS_ID; icsid++) {
struct kvmppc_ics *ics = xics->ics[icsid];
if (!ics)
continue;
seq_printf(m, "=========\nICS state for ICS 0x%x\n=========\n",
icsid);
local_irq_save(flags);
arch_spin_lock(&ics->lock);
for (i = 0; i < KVMPPC_XICS_IRQ_PER_ICS; i++) {
struct ics_irq_state *irq = &ics->irq_state[i];
seq_printf(m, "irq 0x%06x: server %#x prio %#x save prio %#x asserted %d resend %d masked pending %d\n",
irq->number, irq->server, irq->priority,
irq->saved_priority, irq->asserted,
irq->resend, irq->masked_pending);
}
arch_spin_unlock(&ics->lock);
local_irq_restore(flags);
}
return 0;
}
static int xics_debug_open(struct inode *inode, struct file *file)
{
return single_open(file, xics_debug_show, inode->i_private);
}
static void xics_debugfs_init(struct kvmppc_xics *xics)
{
char *name;
name = kasprintf(GFP_KERNEL, "kvm-xics-%p", xics);
if (!name) {
pr_err("%s: no memory for name\n", __func__);
return;
}
xics->dentry = debugfs_create_file(name, S_IRUGO, powerpc_debugfs_root,
xics, &xics_debug_fops);
pr_debug("%s: created %s\n", __func__, name);
kfree(name);
}
static struct kvmppc_ics *kvmppc_xics_create_ics(struct kvm *kvm,
struct kvmppc_xics *xics, int irq)
{
struct kvmppc_ics *ics;
int i, icsid;
icsid = irq >> KVMPPC_XICS_ICS_SHIFT;
mutex_lock(&kvm->lock);
if (xics->ics[icsid])
goto out;
ics = kzalloc(sizeof(struct kvmppc_ics), GFP_KERNEL);
if (!ics)
goto out;
ics->icsid = icsid;
for (i = 0; i < KVMPPC_XICS_IRQ_PER_ICS; i++) {
ics->irq_state[i].number = (icsid << KVMPPC_XICS_ICS_SHIFT) | i;
ics->irq_state[i].priority = MASKED;
ics->irq_state[i].saved_priority = MASKED;
}
smp_wmb();
xics->ics[icsid] = ics;
if (icsid > xics->max_icsid)
xics->max_icsid = icsid;
out:
mutex_unlock(&kvm->lock);
return xics->ics[icsid];
}
int kvmppc_xics_create_icp(struct kvm_vcpu *vcpu, unsigned long server_num)
{
struct kvmppc_icp *icp;
if (!vcpu->kvm->arch.xics)
return -ENODEV;
if (kvmppc_xics_find_server(vcpu->kvm, server_num))
return -EEXIST;
icp = kzalloc(sizeof(struct kvmppc_icp), GFP_KERNEL);
if (!icp)
return -ENOMEM;
icp->vcpu = vcpu;
icp->server_num = server_num;
icp->state.mfrr = MASKED;
icp->state.pending_pri = MASKED;
vcpu->arch.icp = icp;
XICS_DBG("created server for vcpu %d\n", vcpu->vcpu_id);
return 0;
}
u64 kvmppc_xics_get_icp(struct kvm_vcpu *vcpu)
{
struct kvmppc_icp *icp = vcpu->arch.icp;
union kvmppc_icp_state state;
if (!icp)
return 0;
state = icp->state;
return ((u64)state.cppr << KVM_REG_PPC_ICP_CPPR_SHIFT) |
((u64)state.xisr << KVM_REG_PPC_ICP_XISR_SHIFT) |
((u64)state.mfrr << KVM_REG_PPC_ICP_MFRR_SHIFT) |
((u64)state.pending_pri << KVM_REG_PPC_ICP_PPRI_SHIFT);
}
int kvmppc_xics_set_icp(struct kvm_vcpu *vcpu, u64 icpval)
{
struct kvmppc_icp *icp = vcpu->arch.icp;
struct kvmppc_xics *xics = vcpu->kvm->arch.xics;
union kvmppc_icp_state old_state, new_state;
struct kvmppc_ics *ics;
u8 cppr, mfrr, pending_pri;
u32 xisr;
u16 src;
bool resend;
if (!icp || !xics)
return -ENOENT;
cppr = icpval >> KVM_REG_PPC_ICP_CPPR_SHIFT;
xisr = (icpval >> KVM_REG_PPC_ICP_XISR_SHIFT) &
KVM_REG_PPC_ICP_XISR_MASK;
mfrr = icpval >> KVM_REG_PPC_ICP_MFRR_SHIFT;
pending_pri = icpval >> KVM_REG_PPC_ICP_PPRI_SHIFT;
if (xisr == 0) {
if (pending_pri != 0xff)
return -EINVAL;
} else if (xisr == XICS_IPI) {
if (pending_pri != mfrr || pending_pri >= cppr)
return -EINVAL;
} else {
if (pending_pri >= mfrr || pending_pri >= cppr)
return -EINVAL;
ics = kvmppc_xics_find_ics(xics, xisr, &src);
if (!ics)
return -EINVAL;
}
new_state.raw = 0;
new_state.cppr = cppr;
new_state.xisr = xisr;
new_state.mfrr = mfrr;
new_state.pending_pri = pending_pri;
kvmppc_book3s_dequeue_irqprio(icp->vcpu,
BOOK3S_INTERRUPT_EXTERNAL_LEVEL);
do {
old_state = READ_ONCE(icp->state);
if (new_state.mfrr <= old_state.mfrr) {
resend = false;
new_state.need_resend = old_state.need_resend;
} else {
resend = old_state.need_resend;
new_state.need_resend = 0;
}
} while (!icp_try_update(icp, old_state, new_state, false));
if (resend)
icp_check_resend(xics, icp);
return 0;
}
static int xics_get_source(struct kvmppc_xics *xics, long irq, u64 addr)
{
int ret;
struct kvmppc_ics *ics;
struct ics_irq_state *irqp;
u64 __user *ubufp = (u64 __user *) addr;
u16 idx;
u64 val, prio;
unsigned long flags;
ics = kvmppc_xics_find_ics(xics, irq, &idx);
if (!ics)
return -ENOENT;
irqp = &ics->irq_state[idx];
local_irq_save(flags);
arch_spin_lock(&ics->lock);
ret = -ENOENT;
if (irqp->exists) {
val = irqp->server;
prio = irqp->priority;
if (prio == MASKED) {
val |= KVM_XICS_MASKED;
prio = irqp->saved_priority;
}
val |= prio << KVM_XICS_PRIORITY_SHIFT;
if (irqp->lsi) {
val |= KVM_XICS_LEVEL_SENSITIVE;
if (irqp->asserted)
val |= KVM_XICS_PENDING;
} else if (irqp->masked_pending || irqp->resend)
val |= KVM_XICS_PENDING;
ret = 0;
}
arch_spin_unlock(&ics->lock);
local_irq_restore(flags);
if (!ret && put_user(val, ubufp))
ret = -EFAULT;
return ret;
}
static int xics_set_source(struct kvmppc_xics *xics, long irq, u64 addr)
{
struct kvmppc_ics *ics;
struct ics_irq_state *irqp;
u64 __user *ubufp = (u64 __user *) addr;
u16 idx;
u64 val;
u8 prio;
u32 server;
unsigned long flags;
if (irq < KVMPPC_XICS_FIRST_IRQ || irq >= KVMPPC_XICS_NR_IRQS)
return -ENOENT;
ics = kvmppc_xics_find_ics(xics, irq, &idx);
if (!ics) {
ics = kvmppc_xics_create_ics(xics->kvm, xics, irq);
if (!ics)
return -ENOMEM;
}
irqp = &ics->irq_state[idx];
if (get_user(val, ubufp))
return -EFAULT;
server = val & KVM_XICS_DESTINATION_MASK;
prio = val >> KVM_XICS_PRIORITY_SHIFT;
if (prio != MASKED &&
kvmppc_xics_find_server(xics->kvm, server) == NULL)
return -EINVAL;
local_irq_save(flags);
arch_spin_lock(&ics->lock);
irqp->server = server;
irqp->saved_priority = prio;
if (val & KVM_XICS_MASKED)
prio = MASKED;
irqp->priority = prio;
irqp->resend = 0;
irqp->masked_pending = 0;
irqp->lsi = 0;
irqp->asserted = 0;
if (val & KVM_XICS_LEVEL_SENSITIVE) {
irqp->lsi = 1;
if (val & KVM_XICS_PENDING)
irqp->asserted = 1;
}
irqp->exists = 1;
arch_spin_unlock(&ics->lock);
local_irq_restore(flags);
if (val & KVM_XICS_PENDING)
icp_deliver_irq(xics, NULL, irqp->number);
return 0;
}
int kvm_set_irq(struct kvm *kvm, int irq_source_id, u32 irq, int level,
bool line_status)
{
struct kvmppc_xics *xics = kvm->arch.xics;
return ics_deliver_irq(xics, irq, level);
}
int kvm_arch_set_irq_inatomic(struct kvm_kernel_irq_routing_entry *irq_entry,
struct kvm *kvm, int irq_source_id,
int level, bool line_status)
{
return kvm_set_irq(kvm, irq_source_id, irq_entry->gsi,
level, line_status);
}
static int xics_set_attr(struct kvm_device *dev, struct kvm_device_attr *attr)
{
struct kvmppc_xics *xics = dev->private;
switch (attr->group) {
case KVM_DEV_XICS_GRP_SOURCES:
return xics_set_source(xics, attr->attr, attr->addr);
}
return -ENXIO;
}
static int xics_get_attr(struct kvm_device *dev, struct kvm_device_attr *attr)
{
struct kvmppc_xics *xics = dev->private;
switch (attr->group) {
case KVM_DEV_XICS_GRP_SOURCES:
return xics_get_source(xics, attr->attr, attr->addr);
}
return -ENXIO;
}
static int xics_has_attr(struct kvm_device *dev, struct kvm_device_attr *attr)
{
switch (attr->group) {
case KVM_DEV_XICS_GRP_SOURCES:
if (attr->attr >= KVMPPC_XICS_FIRST_IRQ &&
attr->attr < KVMPPC_XICS_NR_IRQS)
return 0;
break;
}
return -ENXIO;
}
static void kvmppc_xics_free(struct kvm_device *dev)
{
struct kvmppc_xics *xics = dev->private;
int i;
struct kvm *kvm = xics->kvm;
debugfs_remove(xics->dentry);
if (kvm)
kvm->arch.xics = NULL;
for (i = 0; i <= xics->max_icsid; i++)
kfree(xics->ics[i]);
kfree(xics);
kfree(dev);
}
static int kvmppc_xics_create(struct kvm_device *dev, u32 type)
{
struct kvmppc_xics *xics;
struct kvm *kvm = dev->kvm;
int ret = 0;
xics = kzalloc(sizeof(*xics), GFP_KERNEL);
if (!xics)
return -ENOMEM;
dev->private = xics;
xics->dev = dev;
xics->kvm = kvm;
if (kvm->arch.xics)
ret = -EEXIST;
else
kvm->arch.xics = xics;
if (ret) {
kfree(xics);
return ret;
}
#ifdef CONFIG_KVM_BOOK3S_HV_POSSIBLE
if (cpu_has_feature(CPU_FTR_ARCH_206)) {
xics->real_mode = ENABLE_REALMODE;
xics->real_mode_dbg = DEBUG_REALMODE;
}
#endif
return 0;
}
static void kvmppc_xics_init(struct kvm_device *dev)
{
struct kvmppc_xics *xics = (struct kvmppc_xics *)dev->private;
xics_debugfs_init(xics);
}
int kvmppc_xics_connect_vcpu(struct kvm_device *dev, struct kvm_vcpu *vcpu,
u32 xcpu)
{
struct kvmppc_xics *xics = dev->private;
int r = -EBUSY;
if (dev->ops != &kvm_xics_ops)
return -EPERM;
if (xics->kvm != vcpu->kvm)
return -EPERM;
if (vcpu->arch.irq_type)
return -EBUSY;
r = kvmppc_xics_create_icp(vcpu, xcpu);
if (!r)
vcpu->arch.irq_type = KVMPPC_IRQ_XICS;
return r;
}
void kvmppc_xics_free_icp(struct kvm_vcpu *vcpu)
{
if (!vcpu->arch.icp)
return;
kfree(vcpu->arch.icp);
vcpu->arch.icp = NULL;
vcpu->arch.irq_type = KVMPPC_IRQ_DEFAULT;
}
static int xics_set_irq(struct kvm_kernel_irq_routing_entry *e,
struct kvm *kvm, int irq_source_id, int level,
bool line_status)
{
return kvm_set_irq(kvm, irq_source_id, e->gsi, level, line_status);
}
int kvm_irq_map_gsi(struct kvm *kvm,
struct kvm_kernel_irq_routing_entry *entries, int gsi)
{
entries->gsi = gsi;
entries->type = KVM_IRQ_ROUTING_IRQCHIP;
entries->set = xics_set_irq;
entries->irqchip.irqchip = 0;
entries->irqchip.pin = gsi;
return 1;
}
int kvm_irq_map_chip_pin(struct kvm *kvm, unsigned irqchip, unsigned pin)
{
return pin;
}
