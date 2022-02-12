static bool xive_irq_trigger(struct xive_irq_data *xd)
{
if (WARN_ON(xd->flags & XIVE_IRQ_FLAG_LSI))
return false;
if (WARN_ON(!xd->trig_mmio))
return false;
out_be64(xd->trig_mmio, 0);
return true;
}
static irqreturn_t xive_esc_irq(int irq, void *data)
{
struct kvm_vcpu *vcpu = data;
vcpu->arch.prodded = 1;
smp_mb();
if (vcpu->arch.ceded)
kvmppc_fast_vcpu_kick(vcpu);
return IRQ_HANDLED;
}
static int xive_attach_escalation(struct kvm_vcpu *vcpu, u8 prio)
{
struct kvmppc_xive_vcpu *xc = vcpu->arch.xive_vcpu;
struct xive_q *q = &xc->queues[prio];
char *name = NULL;
int rc;
if (xc->esc_virq[prio])
return 0;
xc->esc_virq[prio] = irq_create_mapping(NULL, q->esc_irq);
if (!xc->esc_virq[prio]) {
pr_err("Failed to map escalation interrupt for queue %d of VCPU %d\n",
prio, xc->server_num);
return -EIO;
}
name = kasprintf(GFP_KERNEL, "kvm-%d-%d-%d",
vcpu->kvm->arch.lpid, xc->server_num, prio);
if (!name) {
pr_err("Failed to allocate escalation irq name for queue %d of VCPU %d\n",
prio, xc->server_num);
rc = -ENOMEM;
goto error;
}
rc = request_irq(xc->esc_virq[prio], xive_esc_irq,
IRQF_NO_THREAD, name, vcpu);
if (rc) {
pr_err("Failed to request escalation interrupt for queue %d of VCPU %d\n",
prio, xc->server_num);
goto error;
}
xc->esc_virq_names[prio] = name;
return 0;
error:
irq_dispose_mapping(xc->esc_virq[prio]);
xc->esc_virq[prio] = 0;
kfree(name);
return rc;
}
static int xive_provision_queue(struct kvm_vcpu *vcpu, u8 prio)
{
struct kvmppc_xive_vcpu *xc = vcpu->arch.xive_vcpu;
struct kvmppc_xive *xive = xc->xive;
struct xive_q *q = &xc->queues[prio];
void *qpage;
int rc;
if (WARN_ON(q->qpage))
return 0;
qpage = (__be32 *)__get_free_pages(GFP_KERNEL, xive->q_page_order);
if (!qpage) {
pr_err("Failed to allocate queue %d for VCPU %d\n",
prio, xc->server_num);
return -ENOMEM;;
}
memset(qpage, 0, 1 << xive->q_order);
rc = xive_native_configure_queue(xc->vp_id, q, prio, qpage,
xive->q_order, true);
if (rc)
pr_err("Failed to configure queue %d for VCPU %d\n",
prio, xc->server_num);
return rc;
}
static int xive_check_provisioning(struct kvm *kvm, u8 prio)
{
struct kvmppc_xive *xive = kvm->arch.xive;
struct kvm_vcpu *vcpu;
int i, rc;
lockdep_assert_held(&kvm->lock);
if (xive->qmap & (1 << prio))
return 0;
pr_devel("Provisioning prio... %d\n", prio);
kvm_for_each_vcpu(i, vcpu, kvm) {
if (!vcpu->arch.xive_vcpu)
continue;
rc = xive_provision_queue(vcpu, prio);
if (rc == 0)
xive_attach_escalation(vcpu, prio);
if (rc)
return rc;
}
mb();
xive->qmap |= (1 << prio);
return 0;
}
static void xive_inc_q_pending(struct kvm *kvm, u32 server, u8 prio)
{
struct kvm_vcpu *vcpu;
struct kvmppc_xive_vcpu *xc;
struct xive_q *q;
vcpu = kvmppc_xive_find_server(kvm, server);
if (!vcpu) {
pr_warn("%s: Can't find server %d\n", __func__, server);
return;
}
xc = vcpu->arch.xive_vcpu;
if (WARN_ON(!xc))
return;
q = &xc->queues[prio];
atomic_inc(&q->pending_count);
}
static int xive_try_pick_queue(struct kvm_vcpu *vcpu, u8 prio)
{
struct kvmppc_xive_vcpu *xc = vcpu->arch.xive_vcpu;
struct xive_q *q;
u32 max;
if (WARN_ON(!xc))
return -ENXIO;
if (!xc->valid)
return -ENXIO;
q = &xc->queues[prio];
if (WARN_ON(!q->qpage))
return -ENXIO;
max = (q->msk + 1) - XIVE_Q_GAP;
return atomic_add_unless(&q->count, 1, max) ? 0 : -EBUSY;
}
static int xive_select_target(struct kvm *kvm, u32 *server, u8 prio)
{
struct kvm_vcpu *vcpu;
int i, rc;
vcpu = kvmppc_xive_find_server(kvm, *server);
if (!vcpu) {
pr_devel("Can't find server %d\n", *server);
return -EINVAL;
}
pr_devel("Finding irq target on 0x%x/%d...\n", *server, prio);
rc = xive_try_pick_queue(vcpu, prio);
if (rc == 0)
return rc;
pr_devel(" .. failed, looking up candidate...\n");
kvm_for_each_vcpu(i, vcpu, kvm) {
if (!vcpu->arch.xive_vcpu)
continue;
rc = xive_try_pick_queue(vcpu, prio);
if (rc == 0) {
*server = vcpu->arch.xive_vcpu->server_num;
pr_devel(" found on 0x%x/%d\n", *server, prio);
return rc;
}
}
pr_devel(" no available target !\n");
return -EBUSY;
}
static u8 xive_lock_and_mask(struct kvmppc_xive *xive,
struct kvmppc_xive_src_block *sb,
struct kvmppc_xive_irq_state *state)
{
struct xive_irq_data *xd;
u32 hw_num;
u8 old_prio;
u64 val;
for (;;) {
arch_spin_lock(&sb->lock);
old_prio = state->guest_priority;
state->guest_priority = MASKED;
mb();
if (!state->in_eoi)
break;
state->guest_priority = old_prio;
arch_spin_unlock(&sb->lock);
}
if (old_prio == MASKED)
return old_prio;
kvmppc_xive_select_irq(state, &hw_num, &xd);
if (xd->flags & OPAL_XIVE_IRQ_MASK_VIA_FW) {
xive_native_configure_irq(hw_num,
xive->vp_base + state->act_server,
MASKED, state->number);
state->old_p = true;
state->old_q = false;
} else {
val = xive_vm_esb_load(xd, XIVE_ESB_SET_PQ_10);
state->old_p = !!(val & 2);
state->old_q = !!(val & 1);
xive_native_sync_source(hw_num);
}
return old_prio;
}
static void xive_lock_for_unmask(struct kvmppc_xive_src_block *sb,
struct kvmppc_xive_irq_state *state)
{
for (;;) {
arch_spin_lock(&sb->lock);
if (!state->in_eoi)
break;
arch_spin_unlock(&sb->lock);
}
}
static void xive_finish_unmask(struct kvmppc_xive *xive,
struct kvmppc_xive_src_block *sb,
struct kvmppc_xive_irq_state *state,
u8 prio)
{
struct xive_irq_data *xd;
u32 hw_num;
if (state->guest_priority != MASKED)
goto bail;
kvmppc_xive_select_irq(state, &hw_num, &xd);
if (xd->flags & OPAL_XIVE_IRQ_MASK_VIA_FW) {
xive_native_configure_irq(hw_num,
xive->vp_base + state->act_server,
state->act_priority, state->number);
if (!state->old_p)
xive_vm_source_eoi(hw_num, xd);
if (!(xd->flags & OPAL_XIVE_IRQ_LSI))
xive_irq_trigger(xd);
goto bail;
}
if (state->old_q)
xive_vm_esb_load(xd, XIVE_ESB_SET_PQ_11);
if (!state->old_p)
xive_vm_source_eoi(hw_num, xd);
mb();
bail:
state->guest_priority = prio;
}
static int xive_target_interrupt(struct kvm *kvm,
struct kvmppc_xive_irq_state *state,
u32 server, u8 prio)
{
struct kvmppc_xive *xive = kvm->arch.xive;
u32 hw_num;
int rc;
rc = xive_select_target(kvm, &server, prio);
if (rc)
return rc;
if (state->act_priority != MASKED)
xive_inc_q_pending(kvm,
state->act_server,
state->act_priority);
state->act_priority = prio;
state->act_server = server;
kvmppc_xive_select_irq(state, &hw_num, NULL);
return xive_native_configure_irq(hw_num,
xive->vp_base + server,
prio, state->number);
}
int kvmppc_xive_set_xive(struct kvm *kvm, u32 irq, u32 server,
u32 priority)
{
struct kvmppc_xive *xive = kvm->arch.xive;
struct kvmppc_xive_src_block *sb;
struct kvmppc_xive_irq_state *state;
u8 new_act_prio;
int rc = 0;
u16 idx;
if (!xive)
return -ENODEV;
pr_devel("set_xive ! irq 0x%x server 0x%x prio %d\n",
irq, server, priority);
if (priority != MASKED)
rc = xive_check_provisioning(xive->kvm,
xive_prio_from_guest(priority));
if (rc) {
pr_devel(" provisioning failure %d !\n", rc);
return rc;
}
sb = kvmppc_xive_find_source(xive, irq, &idx);
if (!sb)
return -EINVAL;
state = &sb->irq_state[idx];
if (priority == MASKED)
xive_lock_and_mask(xive, sb, state);
else
xive_lock_for_unmask(sb, state);
new_act_prio = state->act_priority;
if (priority != MASKED)
new_act_prio = xive_prio_from_guest(priority);
pr_devel(" new_act_prio=%x act_server=%x act_prio=%x\n",
new_act_prio, state->act_server, state->act_priority);
if (new_act_prio != MASKED &&
(state->act_server != server ||
state->act_priority != new_act_prio))
rc = xive_target_interrupt(kvm, state, server, new_act_prio);
if (priority != MASKED)
xive_finish_unmask(xive, sb, state, priority);
state->saved_priority = priority;
arch_spin_unlock(&sb->lock);
return rc;
}
int kvmppc_xive_get_xive(struct kvm *kvm, u32 irq, u32 *server,
u32 *priority)
{
struct kvmppc_xive *xive = kvm->arch.xive;
struct kvmppc_xive_src_block *sb;
struct kvmppc_xive_irq_state *state;
u16 idx;
if (!xive)
return -ENODEV;
sb = kvmppc_xive_find_source(xive, irq, &idx);
if (!sb)
return -EINVAL;
state = &sb->irq_state[idx];
arch_spin_lock(&sb->lock);
*server = state->act_server;
*priority = state->guest_priority;
arch_spin_unlock(&sb->lock);
return 0;
}
int kvmppc_xive_int_on(struct kvm *kvm, u32 irq)
{
struct kvmppc_xive *xive = kvm->arch.xive;
struct kvmppc_xive_src_block *sb;
struct kvmppc_xive_irq_state *state;
u16 idx;
if (!xive)
return -ENODEV;
sb = kvmppc_xive_find_source(xive, irq, &idx);
if (!sb)
return -EINVAL;
state = &sb->irq_state[idx];
pr_devel("int_on(irq=0x%x)\n", irq);
if (state->act_priority == MASKED) {
pr_devel("int_on on untargetted interrupt\n");
return -EINVAL;
}
if (state->saved_priority == MASKED)
return 0;
xive_lock_for_unmask(sb, state);
xive_finish_unmask(xive, sb, state, state->saved_priority);
arch_spin_unlock(&sb->lock);
return 0;
}
int kvmppc_xive_int_off(struct kvm *kvm, u32 irq)
{
struct kvmppc_xive *xive = kvm->arch.xive;
struct kvmppc_xive_src_block *sb;
struct kvmppc_xive_irq_state *state;
u16 idx;
if (!xive)
return -ENODEV;
sb = kvmppc_xive_find_source(xive, irq, &idx);
if (!sb)
return -EINVAL;
state = &sb->irq_state[idx];
pr_devel("int_off(irq=0x%x)\n", irq);
state->saved_priority = xive_lock_and_mask(xive, sb, state);
arch_spin_unlock(&sb->lock);
return 0;
}
static bool xive_restore_pending_irq(struct kvmppc_xive *xive, u32 irq)
{
struct kvmppc_xive_src_block *sb;
struct kvmppc_xive_irq_state *state;
u16 idx;
sb = kvmppc_xive_find_source(xive, irq, &idx);
if (!sb)
return false;
state = &sb->irq_state[idx];
if (!state->valid)
return false;
xive_irq_trigger(&state->ipi_data);
return true;
}
u64 kvmppc_xive_get_icp(struct kvm_vcpu *vcpu)
{
struct kvmppc_xive_vcpu *xc = vcpu->arch.xive_vcpu;
if (!xc)
return 0;
return (u64)xc->cppr << KVM_REG_PPC_ICP_CPPR_SHIFT |
(u64)xc->mfrr << KVM_REG_PPC_ICP_MFRR_SHIFT;
}
int kvmppc_xive_set_icp(struct kvm_vcpu *vcpu, u64 icpval)
{
struct kvmppc_xive_vcpu *xc = vcpu->arch.xive_vcpu;
struct kvmppc_xive *xive = vcpu->kvm->arch.xive;
u8 cppr, mfrr;
u32 xisr;
if (!xc || !xive)
return -ENOENT;
cppr = icpval >> KVM_REG_PPC_ICP_CPPR_SHIFT;
xisr = (icpval >> KVM_REG_PPC_ICP_XISR_SHIFT) &
KVM_REG_PPC_ICP_XISR_MASK;
mfrr = icpval >> KVM_REG_PPC_ICP_MFRR_SHIFT;
pr_devel("set_icp vcpu %d cppr=0x%x mfrr=0x%x xisr=0x%x\n",
xc->server_num, cppr, mfrr, xisr);
if (WARN_ON(vcpu->arch.xive_pushed))
return -EIO;
vcpu->arch.xive_saved_state.cppr = cppr;
xc->hw_cppr = xc->cppr = cppr;
xc->mfrr = mfrr;
if (mfrr < cppr)
xive_irq_trigger(&xc->vp_ipi_data);
if (xisr > XICS_IPI && !xive_restore_pending_irq(xive, xisr)) {
xc->delayed_irq = xisr;
xive->delayed_irqs++;
pr_devel(" xisr restore delayed\n");
}
return 0;
}
int kvmppc_xive_set_mapped(struct kvm *kvm, unsigned long guest_irq,
struct irq_desc *host_desc)
{
struct kvmppc_xive *xive = kvm->arch.xive;
struct kvmppc_xive_src_block *sb;
struct kvmppc_xive_irq_state *state;
struct irq_data *host_data = irq_desc_get_irq_data(host_desc);
unsigned int host_irq = irq_desc_get_irq(host_desc);
unsigned int hw_irq = (unsigned int)irqd_to_hwirq(host_data);
u16 idx;
u8 prio;
int rc;
if (!xive)
return -ENODEV;
pr_devel("set_mapped girq 0x%lx host HW irq 0x%x...\n",guest_irq, hw_irq);
sb = kvmppc_xive_find_source(xive, guest_irq, &idx);
if (!sb)
return -EINVAL;
state = &sb->irq_state[idx];
rc = irq_set_vcpu_affinity(host_irq, state);
if (rc) {
pr_err("Failed to set VCPU affinity for irq %d\n", host_irq);
return rc;
}
prio = xive_lock_and_mask(xive, sb, state);
pr_devel(" old IPI prio %02x P:%d Q:%d\n", prio,
state->old_p, state->old_q);
xive_vm_esb_load(&state->ipi_data, XIVE_ESB_SET_PQ_01);
state->pt_number = hw_irq;
state->pt_data = irq_data_get_irq_handler_data(host_data);
xive_native_configure_irq(hw_irq,
xive->vp_base + state->act_server,
state->act_priority, state->number);
if (prio != MASKED && !state->old_p)
xive_vm_source_eoi(hw_irq, state->pt_data);
state->old_p = state->old_q = false;
mb();
state->guest_priority = prio;
arch_spin_unlock(&sb->lock);
return 0;
}
int kvmppc_xive_clr_mapped(struct kvm *kvm, unsigned long guest_irq,
struct irq_desc *host_desc)
{
struct kvmppc_xive *xive = kvm->arch.xive;
struct kvmppc_xive_src_block *sb;
struct kvmppc_xive_irq_state *state;
unsigned int host_irq = irq_desc_get_irq(host_desc);
u16 idx;
u8 prio;
int rc;
if (!xive)
return -ENODEV;
pr_devel("clr_mapped girq 0x%lx...\n", guest_irq);
sb = kvmppc_xive_find_source(xive, guest_irq, &idx);
if (!sb)
return -EINVAL;
state = &sb->irq_state[idx];
prio = xive_lock_and_mask(xive, sb, state);
pr_devel(" old IRQ prio %02x P:%d Q:%d\n", prio,
state->old_p, state->old_q);
if (state->old_p)
xive_vm_esb_load(state->pt_data, XIVE_ESB_SET_PQ_11);
rc = irq_set_vcpu_affinity(host_irq, NULL);
if (rc) {
pr_err("Failed to clr VCPU affinity for irq %d\n", host_irq);
return rc;
}
state->pt_number = 0;
state->pt_data = NULL;
xive_native_configure_irq(state->ipi_number,
xive->vp_base + state->act_server,
state->act_priority, state->number);
if (prio == MASKED || state->old_p)
xive_vm_esb_load(&state->ipi_data, XIVE_ESB_SET_PQ_10);
else
xive_vm_esb_load(&state->ipi_data, XIVE_ESB_SET_PQ_00);
mb();
state->guest_priority = prio;
arch_spin_unlock(&sb->lock);
return 0;
}
static void kvmppc_xive_disable_vcpu_interrupts(struct kvm_vcpu *vcpu)
{
struct kvmppc_xive_vcpu *xc = vcpu->arch.xive_vcpu;
struct kvm *kvm = vcpu->kvm;
struct kvmppc_xive *xive = kvm->arch.xive;
int i, j;
for (i = 0; i <= xive->max_sbid; i++) {
struct kvmppc_xive_src_block *sb = xive->src_blocks[i];
if (!sb)
continue;
for (j = 0; j < KVMPPC_XICS_IRQ_PER_ICS; j++) {
struct kvmppc_xive_irq_state *state = &sb->irq_state[j];
if (!state->valid)
continue;
if (state->act_priority == MASKED)
continue;
if (state->act_server != xc->server_num)
continue;
arch_spin_lock(&sb->lock);
state->act_priority = MASKED;
xive_vm_esb_load(&state->ipi_data, XIVE_ESB_SET_PQ_01);
xive_native_configure_irq(state->ipi_number, 0, MASKED, 0);
if (state->pt_number) {
xive_vm_esb_load(state->pt_data, XIVE_ESB_SET_PQ_01);
xive_native_configure_irq(state->pt_number, 0, MASKED, 0);
}
arch_spin_unlock(&sb->lock);
}
}
}
void kvmppc_xive_cleanup_vcpu(struct kvm_vcpu *vcpu)
{
struct kvmppc_xive_vcpu *xc = vcpu->arch.xive_vcpu;
struct kvmppc_xive *xive = xc->xive;
int i;
pr_devel("cleanup_vcpu(cpu=%d)\n", xc->server_num);
xc->valid = false;
kvmppc_xive_disable_vcpu_interrupts(vcpu);
xive_vm_esb_load(&xc->vp_ipi_data, XIVE_ESB_SET_PQ_01);
xive_native_disable_vp(xc->vp_id);
for (i = 0; i < KVMPPC_XIVE_Q_COUNT; i++) {
struct xive_q *q = &xc->queues[i];
if (xc->esc_virq[i]) {
free_irq(xc->esc_virq[i], vcpu);
irq_dispose_mapping(xc->esc_virq[i]);
kfree(xc->esc_virq_names[i]);
}
xive_native_disable_queue(xc->vp_id, q, i);
if (q->qpage) {
free_pages((unsigned long)q->qpage,
xive->q_page_order);
q->qpage = NULL;
}
}
if (xc->vp_ipi) {
xive_cleanup_irq_data(&xc->vp_ipi_data);
xive_native_free_irq(xc->vp_ipi);
}
kfree(xc);
}
int kvmppc_xive_connect_vcpu(struct kvm_device *dev,
struct kvm_vcpu *vcpu, u32 cpu)
{
struct kvmppc_xive *xive = dev->private;
struct kvmppc_xive_vcpu *xc;
int i, r = -EBUSY;
pr_devel("connect_vcpu(cpu=%d)\n", cpu);
if (dev->ops != &kvm_xive_ops) {
pr_devel("Wrong ops !\n");
return -EPERM;
}
if (xive->kvm != vcpu->kvm)
return -EPERM;
if (vcpu->arch.irq_type)
return -EBUSY;
if (kvmppc_xive_find_server(vcpu->kvm, cpu)) {
pr_devel("Duplicate !\n");
return -EEXIST;
}
if (cpu >= KVM_MAX_VCPUS) {
pr_devel("Out of bounds !\n");
return -EINVAL;
}
xc = kzalloc(sizeof(*xc), GFP_KERNEL);
if (!xc)
return -ENOMEM;
mutex_lock(&vcpu->kvm->lock);
vcpu->arch.xive_vcpu = xc;
xc->xive = xive;
xc->vcpu = vcpu;
xc->server_num = cpu;
xc->vp_id = xive->vp_base + cpu;
xc->mfrr = 0xff;
xc->valid = true;
r = xive_native_get_vp_info(xc->vp_id, &xc->vp_cam, &xc->vp_chip_id);
if (r)
goto bail;
vcpu->arch.xive_saved_state.w01 = cpu_to_be64(0xff000000);
vcpu->arch.xive_cam_word = cpu_to_be32(xc->vp_cam | TM_QW1W2_VO);
xc->vp_ipi = xive_native_alloc_irq();
if (!xc->vp_ipi) {
r = -EIO;
goto bail;
}
pr_devel(" IPI=0x%x\n", xc->vp_ipi);
r = xive_native_populate_irq_data(xc->vp_ipi, &xc->vp_ipi_data);
if (r)
goto bail;
for (i = 0; i < KVMPPC_XIVE_Q_COUNT; i++) {
struct xive_q *q = &xc->queues[i];
if (xive->qmap & (1 << i)) {
r = xive_provision_queue(vcpu, i);
if (r == 0)
xive_attach_escalation(vcpu, i);
if (r)
goto bail;
} else {
r = xive_native_configure_queue(xc->vp_id,
q, i, NULL, 0, true);
if (r) {
pr_err("Failed to configure queue %d for VCPU %d\n",
i, cpu);
goto bail;
}
}
}
r = xive_attach_escalation(vcpu, 0);
if (r)
goto bail;
r = xive_native_enable_vp(xc->vp_id);
if (r)
goto bail;
r = xive_native_configure_irq(xc->vp_ipi, xc->vp_id, 0, XICS_IPI);
if (!r)
xive_vm_esb_load(&xc->vp_ipi_data, XIVE_ESB_SET_PQ_00);
bail:
mutex_unlock(&vcpu->kvm->lock);
if (r) {
kvmppc_xive_cleanup_vcpu(vcpu);
return r;
}
vcpu->arch.irq_type = KVMPPC_IRQ_XICS;
return 0;
}
static void xive_pre_save_set_queued(struct kvmppc_xive *xive, u32 irq)
{
struct kvmppc_xive_src_block *sb;
struct kvmppc_xive_irq_state *state;
u16 idx;
sb = kvmppc_xive_find_source(xive, irq, &idx);
if (!sb)
return;
state = &sb->irq_state[idx];
if (!state->valid) {
pr_err("invalid irq 0x%x in cpu queue!\n", irq);
return;
}
if (!state->saved_p)
pr_err("Interrupt 0x%x is marked in a queue but P not set !\n", irq);
state->in_queue = true;
}
static void xive_pre_save_mask_irq(struct kvmppc_xive *xive,
struct kvmppc_xive_src_block *sb,
u32 irq)
{
struct kvmppc_xive_irq_state *state = &sb->irq_state[irq];
if (!state->valid)
return;
state->saved_scan_prio = xive_lock_and_mask(xive, sb, state);
state->saved_p = state->old_p;
state->saved_q = state->old_q;
arch_spin_unlock(&sb->lock);
}
static void xive_pre_save_unmask_irq(struct kvmppc_xive *xive,
struct kvmppc_xive_src_block *sb,
u32 irq)
{
struct kvmppc_xive_irq_state *state = &sb->irq_state[irq];
if (!state->valid)
return;
xive_lock_for_unmask(sb, state);
if (state->saved_scan_prio != MASKED)
xive_finish_unmask(xive, sb, state, state->saved_scan_prio);
arch_spin_unlock(&sb->lock);
}
static void xive_pre_save_queue(struct kvmppc_xive *xive, struct xive_q *q)
{
u32 idx = q->idx;
u32 toggle = q->toggle;
u32 irq;
do {
irq = __xive_read_eq(q->qpage, q->msk, &idx, &toggle);
if (irq > XICS_IPI)
xive_pre_save_set_queued(xive, irq);
} while(irq);
}
static void xive_pre_save_scan(struct kvmppc_xive *xive)
{
struct kvm_vcpu *vcpu = NULL;
int i, j;
for (i = 0; i <= xive->max_sbid; i++) {
struct kvmppc_xive_src_block *sb = xive->src_blocks[i];
if (!sb)
continue;
for (j = 0; j < KVMPPC_XICS_IRQ_PER_ICS; j++)
xive_pre_save_mask_irq(xive, sb, j);
}
kvm_for_each_vcpu(i, vcpu, xive->kvm) {
struct kvmppc_xive_vcpu *xc = vcpu->arch.xive_vcpu;
if (!xc)
continue;
for (j = 0; j < KVMPPC_XIVE_Q_COUNT; j++) {
if (xc->queues[j].qpage)
xive_pre_save_queue(xive, &xc->queues[j]);
}
}
for (i = 0; i <= xive->max_sbid; i++) {
struct kvmppc_xive_src_block *sb = xive->src_blocks[i];
if (!sb)
continue;
for (j = 0; j < KVMPPC_XICS_IRQ_PER_ICS; j++)
xive_pre_save_unmask_irq(xive, sb, j);
}
}
static void xive_post_save_scan(struct kvmppc_xive *xive)
{
u32 i, j;
for (i = 0; i <= xive->max_sbid; i++) {
struct kvmppc_xive_src_block *sb = xive->src_blocks[i];
if (!sb)
continue;
for (j = 0; j < KVMPPC_XICS_IRQ_PER_ICS; j++)
sb->irq_state[j].in_queue = false;
}
xive->saved_src_count = 0;
}
static int xive_get_source(struct kvmppc_xive *xive, long irq, u64 addr)
{
struct kvmppc_xive_src_block *sb;
struct kvmppc_xive_irq_state *state;
u64 __user *ubufp = (u64 __user *) addr;
u64 val, prio;
u16 idx;
sb = kvmppc_xive_find_source(xive, irq, &idx);
if (!sb)
return -ENOENT;
state = &sb->irq_state[idx];
if (!state->valid)
return -ENOENT;
pr_devel("get_source(%ld)...\n", irq);
if (xive->saved_src_count == 0)
xive_pre_save_scan(xive);
xive->saved_src_count++;
val = state->act_server;
prio = state->saved_scan_prio;
if (prio == MASKED) {
val |= KVM_XICS_MASKED;
prio = state->saved_priority;
}
val |= prio << KVM_XICS_PRIORITY_SHIFT;
if (state->lsi) {
val |= KVM_XICS_LEVEL_SENSITIVE;
if (state->saved_p)
val |= KVM_XICS_PENDING;
} else {
if (state->saved_p)
val |= KVM_XICS_PRESENTED;
if (state->saved_q)
val |= KVM_XICS_QUEUED;
if (state->in_queue || (prio == MASKED && state->saved_q))
val |= KVM_XICS_PENDING;
}
if (xive->saved_src_count == xive->src_count)
xive_post_save_scan(xive);
if (put_user(val, ubufp))
return -EFAULT;
return 0;
}
static struct kvmppc_xive_src_block *xive_create_src_block(struct kvmppc_xive *xive,
int irq)
{
struct kvm *kvm = xive->kvm;
struct kvmppc_xive_src_block *sb;
int i, bid;
bid = irq >> KVMPPC_XICS_ICS_SHIFT;
mutex_lock(&kvm->lock);
if (xive->src_blocks[bid])
goto out;
sb = kzalloc(sizeof(*sb), GFP_KERNEL);
if (!sb)
goto out;
sb->id = bid;
for (i = 0; i < KVMPPC_XICS_IRQ_PER_ICS; i++) {
sb->irq_state[i].number = (bid << KVMPPC_XICS_ICS_SHIFT) | i;
sb->irq_state[i].guest_priority = MASKED;
sb->irq_state[i].saved_priority = MASKED;
sb->irq_state[i].act_priority = MASKED;
}
smp_wmb();
xive->src_blocks[bid] = sb;
if (bid > xive->max_sbid)
xive->max_sbid = bid;
out:
mutex_unlock(&kvm->lock);
return xive->src_blocks[bid];
}
static bool xive_check_delayed_irq(struct kvmppc_xive *xive, u32 irq)
{
struct kvm *kvm = xive->kvm;
struct kvm_vcpu *vcpu = NULL;
int i;
kvm_for_each_vcpu(i, vcpu, kvm) {
struct kvmppc_xive_vcpu *xc = vcpu->arch.xive_vcpu;
if (!xc)
continue;
if (xc->delayed_irq == irq) {
xc->delayed_irq = 0;
xive->delayed_irqs--;
return true;
}
}
return false;
}
static int xive_set_source(struct kvmppc_xive *xive, long irq, u64 addr)
{
struct kvmppc_xive_src_block *sb;
struct kvmppc_xive_irq_state *state;
u64 __user *ubufp = (u64 __user *) addr;
u16 idx;
u64 val;
u8 act_prio, guest_prio;
u32 server;
int rc = 0;
if (irq < KVMPPC_XICS_FIRST_IRQ || irq >= KVMPPC_XICS_NR_IRQS)
return -ENOENT;
pr_devel("set_source(irq=0x%lx)\n", irq);
sb = kvmppc_xive_find_source(xive, irq, &idx);
if (!sb) {
pr_devel("No source, creating source block...\n");
sb = xive_create_src_block(xive, irq);
if (!sb) {
pr_devel("Failed to create block...\n");
return -ENOMEM;
}
}
state = &sb->irq_state[idx];
if (get_user(val, ubufp)) {
pr_devel("fault getting user info !\n");
return -EFAULT;
}
server = val & KVM_XICS_DESTINATION_MASK;
guest_prio = val >> KVM_XICS_PRIORITY_SHIFT;
pr_devel(" val=0x016%llx (server=0x%x, guest_prio=%d)\n",
val, server, guest_prio);
if (!state->ipi_number) {
state->ipi_number = xive_native_alloc_irq();
if (state->ipi_number == 0) {
pr_devel("Failed to allocate IPI !\n");
return -ENOMEM;
}
xive_native_populate_irq_data(state->ipi_number, &state->ipi_data);
pr_devel(" src_ipi=0x%x\n", state->ipi_number);
}
state->guest_priority = 0;
xive_lock_and_mask(xive, sb, state);
act_prio = xive_prio_from_guest(guest_prio);
state->act_priority = MASKED;
arch_spin_unlock(&sb->lock);
if (act_prio != MASKED) {
mutex_lock(&xive->kvm->lock);
rc = xive_check_provisioning(xive->kvm, act_prio);
mutex_unlock(&xive->kvm->lock);
if (rc == 0)
rc = xive_target_interrupt(xive->kvm, state,
server, act_prio);
}
if (xive->delayed_irqs && xive_check_delayed_irq(xive, irq)) {
val |= KVM_XICS_PENDING;
pr_devel(" Found delayed ! forcing PENDING !\n");
}
state->old_p = false;
state->old_q = false;
state->lsi = false;
state->asserted = false;
if (val & KVM_XICS_LEVEL_SENSITIVE) {
state->lsi = true;
if (val & KVM_XICS_PENDING)
state->asserted = true;
pr_devel(" LSI ! Asserted=%d\n", state->asserted);
}
if (val & KVM_XICS_PRESENTED || val & KVM_XICS_PENDING)
state->old_p = true;
if (val & KVM_XICS_QUEUED || val & KVM_XICS_PENDING)
state->old_q = true;
pr_devel(" P=%d, Q=%d\n", state->old_p, state->old_q);
if (val & KVM_XICS_MASKED) {
pr_devel(" masked, saving prio\n");
state->guest_priority = MASKED;
state->saved_priority = guest_prio;
} else {
pr_devel(" unmasked, restoring to prio %d\n", guest_prio);
xive_finish_unmask(xive, sb, state, guest_prio);
state->saved_priority = guest_prio;
}
if (!state->valid)
xive->src_count++;
state->valid = true;
return 0;
}
int kvmppc_xive_set_irq(struct kvm *kvm, int irq_source_id, u32 irq, int level,
bool line_status)
{
struct kvmppc_xive *xive = kvm->arch.xive;
struct kvmppc_xive_src_block *sb;
struct kvmppc_xive_irq_state *state;
u16 idx;
if (!xive)
return -ENODEV;
sb = kvmppc_xive_find_source(xive, irq, &idx);
if (!sb)
return -EINVAL;
state = &sb->irq_state[idx];
if (!state->valid)
return -EINVAL;
if (state->pt_number)
return -EINVAL;
if ((level == 1 && state->lsi) || level == KVM_INTERRUPT_SET_LEVEL)
state->asserted = 1;
else if (level == 0 || level == KVM_INTERRUPT_UNSET) {
state->asserted = 0;
return 0;
}
xive_irq_trigger(&state->ipi_data);
return 0;
}
static int xive_set_attr(struct kvm_device *dev, struct kvm_device_attr *attr)
{
struct kvmppc_xive *xive = dev->private;
switch (attr->group) {
case KVM_DEV_XICS_GRP_SOURCES:
return xive_set_source(xive, attr->attr, attr->addr);
}
return -ENXIO;
}
static int xive_get_attr(struct kvm_device *dev, struct kvm_device_attr *attr)
{
struct kvmppc_xive *xive = dev->private;
switch (attr->group) {
case KVM_DEV_XICS_GRP_SOURCES:
return xive_get_source(xive, attr->attr, attr->addr);
}
return -ENXIO;
}
static int xive_has_attr(struct kvm_device *dev, struct kvm_device_attr *attr)
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
static void kvmppc_xive_cleanup_irq(u32 hw_num, struct xive_irq_data *xd)
{
xive_vm_esb_load(xd, XIVE_ESB_SET_PQ_01);
xive_native_configure_irq(hw_num, 0, MASKED, 0);
xive_cleanup_irq_data(xd);
}
static void kvmppc_xive_free_sources(struct kvmppc_xive_src_block *sb)
{
int i;
for (i = 0; i < KVMPPC_XICS_IRQ_PER_ICS; i++) {
struct kvmppc_xive_irq_state *state = &sb->irq_state[i];
if (!state->valid)
continue;
kvmppc_xive_cleanup_irq(state->ipi_number, &state->ipi_data);
xive_native_free_irq(state->ipi_number);
if (state->pt_number)
kvmppc_xive_cleanup_irq(state->pt_number, state->pt_data);
state->valid = false;
}
}
static void kvmppc_xive_free(struct kvm_device *dev)
{
struct kvmppc_xive *xive = dev->private;
struct kvm *kvm = xive->kvm;
int i;
debugfs_remove(xive->dentry);
if (kvm)
kvm->arch.xive = NULL;
for (i = 0; i <= xive->max_sbid; i++) {
if (xive->src_blocks[i])
kvmppc_xive_free_sources(xive->src_blocks[i]);
kfree(xive->src_blocks[i]);
xive->src_blocks[i] = NULL;
}
if (xive->vp_base != XIVE_INVALID_VP)
xive_native_free_vp_block(xive->vp_base);
kfree(xive);
kfree(dev);
}
static int kvmppc_xive_create(struct kvm_device *dev, u32 type)
{
struct kvmppc_xive *xive;
struct kvm *kvm = dev->kvm;
int ret = 0;
pr_devel("Creating xive for partition\n");
xive = kzalloc(sizeof(*xive), GFP_KERNEL);
if (!xive)
return -ENOMEM;
dev->private = xive;
xive->dev = dev;
xive->kvm = kvm;
if (kvm->arch.xive)
ret = -EEXIST;
else
kvm->arch.xive = xive;
xive->q_order = xive_native_default_eq_shift();
if (xive->q_order < PAGE_SHIFT)
xive->q_page_order = 0;
else
xive->q_page_order = xive->q_order - PAGE_SHIFT;
xive->vp_base = xive_native_alloc_vp_block(KVM_MAX_VCPUS);
pr_devel("VP_Base=%x\n", xive->vp_base);
if (xive->vp_base == XIVE_INVALID_VP)
ret = -ENOMEM;
if (ret) {
kfree(xive);
return ret;
}
return 0;
}
static int xive_debug_show(struct seq_file *m, void *private)
{
struct kvmppc_xive *xive = m->private;
struct kvm *kvm = xive->kvm;
struct kvm_vcpu *vcpu;
u64 t_rm_h_xirr = 0;
u64 t_rm_h_ipoll = 0;
u64 t_rm_h_cppr = 0;
u64 t_rm_h_eoi = 0;
u64 t_rm_h_ipi = 0;
u64 t_vm_h_xirr = 0;
u64 t_vm_h_ipoll = 0;
u64 t_vm_h_cppr = 0;
u64 t_vm_h_eoi = 0;
u64 t_vm_h_ipi = 0;
unsigned int i;
if (!kvm)
return 0;
seq_printf(m, "=========\nVCPU state\n=========\n");
kvm_for_each_vcpu(i, vcpu, kvm) {
struct kvmppc_xive_vcpu *xc = vcpu->arch.xive_vcpu;
if (!xc)
continue;
seq_printf(m, "cpu server %#x CPPR:%#x HWCPPR:%#x"
" MFRR:%#x PEND:%#x h_xirr: R=%lld V=%lld\n",
xc->server_num, xc->cppr, xc->hw_cppr,
xc->mfrr, xc->pending,
xc->stat_rm_h_xirr, xc->stat_vm_h_xirr);
t_rm_h_xirr += xc->stat_rm_h_xirr;
t_rm_h_ipoll += xc->stat_rm_h_ipoll;
t_rm_h_cppr += xc->stat_rm_h_cppr;
t_rm_h_eoi += xc->stat_rm_h_eoi;
t_rm_h_ipi += xc->stat_rm_h_ipi;
t_vm_h_xirr += xc->stat_vm_h_xirr;
t_vm_h_ipoll += xc->stat_vm_h_ipoll;
t_vm_h_cppr += xc->stat_vm_h_cppr;
t_vm_h_eoi += xc->stat_vm_h_eoi;
t_vm_h_ipi += xc->stat_vm_h_ipi;
}
seq_printf(m, "Hcalls totals\n");
seq_printf(m, " H_XIRR R=%10lld V=%10lld\n", t_rm_h_xirr, t_vm_h_xirr);
seq_printf(m, " H_IPOLL R=%10lld V=%10lld\n", t_rm_h_ipoll, t_vm_h_ipoll);
seq_printf(m, " H_CPPR R=%10lld V=%10lld\n", t_rm_h_cppr, t_vm_h_cppr);
seq_printf(m, " H_EOI R=%10lld V=%10lld\n", t_rm_h_eoi, t_vm_h_eoi);
seq_printf(m, " H_IPI R=%10lld V=%10lld\n", t_rm_h_ipi, t_vm_h_ipi);
return 0;
}
static int xive_debug_open(struct inode *inode, struct file *file)
{
return single_open(file, xive_debug_show, inode->i_private);
}
static void xive_debugfs_init(struct kvmppc_xive *xive)
{
char *name;
name = kasprintf(GFP_KERNEL, "kvm-xive-%p", xive);
if (!name) {
pr_err("%s: no memory for name\n", __func__);
return;
}
xive->dentry = debugfs_create_file(name, S_IRUGO, powerpc_debugfs_root,
xive, &xive_debug_fops);
pr_debug("%s: created %s\n", __func__, name);
kfree(name);
}
static void kvmppc_xive_init(struct kvm_device *dev)
{
struct kvmppc_xive *xive = (struct kvmppc_xive *)dev->private;
xive_debugfs_init(xive);
}
void kvmppc_xive_init_module(void)
{
__xive_vm_h_xirr = xive_vm_h_xirr;
__xive_vm_h_ipoll = xive_vm_h_ipoll;
__xive_vm_h_ipi = xive_vm_h_ipi;
__xive_vm_h_cppr = xive_vm_h_cppr;
__xive_vm_h_eoi = xive_vm_h_eoi;
}
void kvmppc_xive_exit_module(void)
{
__xive_vm_h_xirr = NULL;
__xive_vm_h_ipoll = NULL;
__xive_vm_h_ipi = NULL;
__xive_vm_h_cppr = NULL;
__xive_vm_h_eoi = NULL;
}
