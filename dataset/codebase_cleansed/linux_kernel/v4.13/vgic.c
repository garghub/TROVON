static struct vgic_irq *vgic_get_lpi(struct kvm *kvm, u32 intid)
{
struct vgic_dist *dist = &kvm->arch.vgic;
struct vgic_irq *irq = NULL;
spin_lock(&dist->lpi_list_lock);
list_for_each_entry(irq, &dist->lpi_list_head, lpi_list) {
if (irq->intid != intid)
continue;
vgic_get_irq_kref(irq);
goto out_unlock;
}
irq = NULL;
out_unlock:
spin_unlock(&dist->lpi_list_lock);
return irq;
}
struct vgic_irq *vgic_get_irq(struct kvm *kvm, struct kvm_vcpu *vcpu,
u32 intid)
{
if (intid <= VGIC_MAX_PRIVATE)
return &vcpu->arch.vgic_cpu.private_irqs[intid];
if (intid <= VGIC_MAX_SPI)
return &kvm->arch.vgic.spis[intid - VGIC_NR_PRIVATE_IRQS];
if (intid >= VGIC_MIN_LPI)
return vgic_get_lpi(kvm, intid);
WARN(1, "Looking up struct vgic_irq for reserved INTID");
return NULL;
}
static void vgic_irq_release(struct kref *ref)
{
}
void vgic_put_irq(struct kvm *kvm, struct vgic_irq *irq)
{
struct vgic_dist *dist = &kvm->arch.vgic;
if (irq->intid < VGIC_MIN_LPI)
return;
spin_lock(&dist->lpi_list_lock);
if (!kref_put(&irq->refcount, vgic_irq_release)) {
spin_unlock(&dist->lpi_list_lock);
return;
};
list_del(&irq->lpi_list);
dist->lpi_list_count--;
spin_unlock(&dist->lpi_list_lock);
kfree(irq);
}
static struct kvm_vcpu *vgic_target_oracle(struct vgic_irq *irq)
{
DEBUG_SPINLOCK_BUG_ON(!spin_is_locked(&irq->irq_lock));
if (irq->active)
return irq->vcpu ? : irq->target_vcpu;
if (irq->enabled && irq_is_pending(irq)) {
if (unlikely(irq->target_vcpu &&
!irq->target_vcpu->kvm->arch.vgic.enabled))
return NULL;
return irq->target_vcpu;
}
return NULL;
}
static int vgic_irq_cmp(void *priv, struct list_head *a, struct list_head *b)
{
struct vgic_irq *irqa = container_of(a, struct vgic_irq, ap_list);
struct vgic_irq *irqb = container_of(b, struct vgic_irq, ap_list);
bool penda, pendb;
int ret;
spin_lock(&irqa->irq_lock);
spin_lock_nested(&irqb->irq_lock, SINGLE_DEPTH_NESTING);
if (irqa->active || irqb->active) {
ret = (int)irqb->active - (int)irqa->active;
goto out;
}
penda = irqa->enabled && irq_is_pending(irqa);
pendb = irqb->enabled && irq_is_pending(irqb);
if (!penda || !pendb) {
ret = (int)pendb - (int)penda;
goto out;
}
ret = irqa->priority - irqb->priority;
out:
spin_unlock(&irqb->irq_lock);
spin_unlock(&irqa->irq_lock);
return ret;
}
static void vgic_sort_ap_list(struct kvm_vcpu *vcpu)
{
struct vgic_cpu *vgic_cpu = &vcpu->arch.vgic_cpu;
DEBUG_SPINLOCK_BUG_ON(!spin_is_locked(&vgic_cpu->ap_list_lock));
list_sort(NULL, &vgic_cpu->ap_list_head, vgic_irq_cmp);
}
static bool vgic_validate_injection(struct vgic_irq *irq, bool level, void *owner)
{
if (irq->owner != owner)
return false;
switch (irq->config) {
case VGIC_CONFIG_LEVEL:
return irq->line_level != level;
case VGIC_CONFIG_EDGE:
return level;
}
return false;
}
bool vgic_queue_irq_unlock(struct kvm *kvm, struct vgic_irq *irq)
{
struct kvm_vcpu *vcpu;
DEBUG_SPINLOCK_BUG_ON(!spin_is_locked(&irq->irq_lock));
retry:
vcpu = vgic_target_oracle(irq);
if (irq->vcpu || !vcpu) {
spin_unlock(&irq->irq_lock);
if (vcpu) {
kvm_make_request(KVM_REQ_IRQ_PENDING, vcpu);
kvm_vcpu_kick(vcpu);
}
return false;
}
spin_unlock(&irq->irq_lock);
spin_lock(&vcpu->arch.vgic_cpu.ap_list_lock);
spin_lock(&irq->irq_lock);
if (unlikely(irq->vcpu || vcpu != vgic_target_oracle(irq))) {
spin_unlock(&irq->irq_lock);
spin_unlock(&vcpu->arch.vgic_cpu.ap_list_lock);
spin_lock(&irq->irq_lock);
goto retry;
}
vgic_get_irq_kref(irq);
list_add_tail(&irq->ap_list, &vcpu->arch.vgic_cpu.ap_list_head);
irq->vcpu = vcpu;
spin_unlock(&irq->irq_lock);
spin_unlock(&vcpu->arch.vgic_cpu.ap_list_lock);
kvm_make_request(KVM_REQ_IRQ_PENDING, vcpu);
kvm_vcpu_kick(vcpu);
return true;
}
int kvm_vgic_inject_irq(struct kvm *kvm, int cpuid, unsigned int intid,
bool level, void *owner)
{
struct kvm_vcpu *vcpu;
struct vgic_irq *irq;
int ret;
trace_vgic_update_irq_pending(cpuid, intid, level);
ret = vgic_lazy_init(kvm);
if (ret)
return ret;
vcpu = kvm_get_vcpu(kvm, cpuid);
if (!vcpu && intid < VGIC_NR_PRIVATE_IRQS)
return -EINVAL;
irq = vgic_get_irq(kvm, vcpu, intid);
if (!irq)
return -EINVAL;
spin_lock(&irq->irq_lock);
if (!vgic_validate_injection(irq, level, owner)) {
spin_unlock(&irq->irq_lock);
vgic_put_irq(kvm, irq);
return 0;
}
if (irq->config == VGIC_CONFIG_LEVEL)
irq->line_level = level;
else
irq->pending_latch = true;
vgic_queue_irq_unlock(kvm, irq);
vgic_put_irq(kvm, irq);
return 0;
}
int kvm_vgic_map_phys_irq(struct kvm_vcpu *vcpu, u32 virt_irq, u32 phys_irq)
{
struct vgic_irq *irq = vgic_get_irq(vcpu->kvm, vcpu, virt_irq);
BUG_ON(!irq);
spin_lock(&irq->irq_lock);
irq->hw = true;
irq->hwintid = phys_irq;
spin_unlock(&irq->irq_lock);
vgic_put_irq(vcpu->kvm, irq);
return 0;
}
int kvm_vgic_unmap_phys_irq(struct kvm_vcpu *vcpu, unsigned int virt_irq)
{
struct vgic_irq *irq;
if (!vgic_initialized(vcpu->kvm))
return -EAGAIN;
irq = vgic_get_irq(vcpu->kvm, vcpu, virt_irq);
BUG_ON(!irq);
spin_lock(&irq->irq_lock);
irq->hw = false;
irq->hwintid = 0;
spin_unlock(&irq->irq_lock);
vgic_put_irq(vcpu->kvm, irq);
return 0;
}
int kvm_vgic_set_owner(struct kvm_vcpu *vcpu, unsigned int intid, void *owner)
{
struct vgic_irq *irq;
int ret = 0;
if (!vgic_initialized(vcpu->kvm))
return -EAGAIN;
if (!irq_is_ppi(intid) && !vgic_valid_spi(vcpu->kvm, intid))
return -EINVAL;
irq = vgic_get_irq(vcpu->kvm, vcpu, intid);
spin_lock(&irq->irq_lock);
if (irq->owner && irq->owner != owner)
ret = -EEXIST;
else
irq->owner = owner;
spin_unlock(&irq->irq_lock);
return ret;
}
static void vgic_prune_ap_list(struct kvm_vcpu *vcpu)
{
struct vgic_cpu *vgic_cpu = &vcpu->arch.vgic_cpu;
struct vgic_irq *irq, *tmp;
retry:
spin_lock(&vgic_cpu->ap_list_lock);
list_for_each_entry_safe(irq, tmp, &vgic_cpu->ap_list_head, ap_list) {
struct kvm_vcpu *target_vcpu, *vcpuA, *vcpuB;
spin_lock(&irq->irq_lock);
BUG_ON(vcpu != irq->vcpu);
target_vcpu = vgic_target_oracle(irq);
if (!target_vcpu) {
list_del(&irq->ap_list);
irq->vcpu = NULL;
spin_unlock(&irq->irq_lock);
vgic_put_irq(vcpu->kvm, irq);
continue;
}
if (target_vcpu == vcpu) {
spin_unlock(&irq->irq_lock);
continue;
}
spin_unlock(&irq->irq_lock);
spin_unlock(&vgic_cpu->ap_list_lock);
if (vcpu->vcpu_id < target_vcpu->vcpu_id) {
vcpuA = vcpu;
vcpuB = target_vcpu;
} else {
vcpuA = target_vcpu;
vcpuB = vcpu;
}
spin_lock(&vcpuA->arch.vgic_cpu.ap_list_lock);
spin_lock_nested(&vcpuB->arch.vgic_cpu.ap_list_lock,
SINGLE_DEPTH_NESTING);
spin_lock(&irq->irq_lock);
if (target_vcpu == vgic_target_oracle(irq)) {
struct vgic_cpu *new_cpu = &target_vcpu->arch.vgic_cpu;
list_del(&irq->ap_list);
irq->vcpu = target_vcpu;
list_add_tail(&irq->ap_list, &new_cpu->ap_list_head);
}
spin_unlock(&irq->irq_lock);
spin_unlock(&vcpuB->arch.vgic_cpu.ap_list_lock);
spin_unlock(&vcpuA->arch.vgic_cpu.ap_list_lock);
goto retry;
}
spin_unlock(&vgic_cpu->ap_list_lock);
}
static inline void vgic_fold_lr_state(struct kvm_vcpu *vcpu)
{
if (kvm_vgic_global_state.type == VGIC_V2)
vgic_v2_fold_lr_state(vcpu);
else
vgic_v3_fold_lr_state(vcpu);
}
static inline void vgic_populate_lr(struct kvm_vcpu *vcpu,
struct vgic_irq *irq, int lr)
{
DEBUG_SPINLOCK_BUG_ON(!spin_is_locked(&irq->irq_lock));
if (kvm_vgic_global_state.type == VGIC_V2)
vgic_v2_populate_lr(vcpu, irq, lr);
else
vgic_v3_populate_lr(vcpu, irq, lr);
}
static inline void vgic_clear_lr(struct kvm_vcpu *vcpu, int lr)
{
if (kvm_vgic_global_state.type == VGIC_V2)
vgic_v2_clear_lr(vcpu, lr);
else
vgic_v3_clear_lr(vcpu, lr);
}
static inline void vgic_set_underflow(struct kvm_vcpu *vcpu)
{
if (kvm_vgic_global_state.type == VGIC_V2)
vgic_v2_set_underflow(vcpu);
else
vgic_v3_set_underflow(vcpu);
}
static int compute_ap_list_depth(struct kvm_vcpu *vcpu)
{
struct vgic_cpu *vgic_cpu = &vcpu->arch.vgic_cpu;
struct vgic_irq *irq;
int count = 0;
DEBUG_SPINLOCK_BUG_ON(!spin_is_locked(&vgic_cpu->ap_list_lock));
list_for_each_entry(irq, &vgic_cpu->ap_list_head, ap_list) {
spin_lock(&irq->irq_lock);
if (vgic_irq_is_sgi(irq->intid) && irq->source)
count += hweight8(irq->source);
else
count++;
spin_unlock(&irq->irq_lock);
}
return count;
}
static void vgic_flush_lr_state(struct kvm_vcpu *vcpu)
{
struct vgic_cpu *vgic_cpu = &vcpu->arch.vgic_cpu;
struct vgic_irq *irq;
int count = 0;
DEBUG_SPINLOCK_BUG_ON(!spin_is_locked(&vgic_cpu->ap_list_lock));
if (compute_ap_list_depth(vcpu) > kvm_vgic_global_state.nr_lr)
vgic_sort_ap_list(vcpu);
list_for_each_entry(irq, &vgic_cpu->ap_list_head, ap_list) {
spin_lock(&irq->irq_lock);
if (unlikely(vgic_target_oracle(irq) != vcpu))
goto next;
do {
vgic_populate_lr(vcpu, irq, count++);
} while (irq->source && count < kvm_vgic_global_state.nr_lr);
next:
spin_unlock(&irq->irq_lock);
if (count == kvm_vgic_global_state.nr_lr) {
if (!list_is_last(&irq->ap_list,
&vgic_cpu->ap_list_head))
vgic_set_underflow(vcpu);
break;
}
}
vcpu->arch.vgic_cpu.used_lrs = count;
for ( ; count < kvm_vgic_global_state.nr_lr; count++)
vgic_clear_lr(vcpu, count);
}
void kvm_vgic_sync_hwstate(struct kvm_vcpu *vcpu)
{
struct vgic_cpu *vgic_cpu = &vcpu->arch.vgic_cpu;
if (list_empty(&vcpu->arch.vgic_cpu.ap_list_head))
return;
if (vgic_cpu->used_lrs)
vgic_fold_lr_state(vcpu);
vgic_prune_ap_list(vcpu);
}
void kvm_vgic_flush_hwstate(struct kvm_vcpu *vcpu)
{
if (list_empty(&vcpu->arch.vgic_cpu.ap_list_head))
return;
spin_lock(&vcpu->arch.vgic_cpu.ap_list_lock);
vgic_flush_lr_state(vcpu);
spin_unlock(&vcpu->arch.vgic_cpu.ap_list_lock);
}
void kvm_vgic_load(struct kvm_vcpu *vcpu)
{
if (unlikely(!vgic_initialized(vcpu->kvm)))
return;
if (kvm_vgic_global_state.type == VGIC_V2)
vgic_v2_load(vcpu);
else
vgic_v3_load(vcpu);
}
void kvm_vgic_put(struct kvm_vcpu *vcpu)
{
if (unlikely(!vgic_initialized(vcpu->kvm)))
return;
if (kvm_vgic_global_state.type == VGIC_V2)
vgic_v2_put(vcpu);
else
vgic_v3_put(vcpu);
}
int kvm_vgic_vcpu_pending_irq(struct kvm_vcpu *vcpu)
{
struct vgic_cpu *vgic_cpu = &vcpu->arch.vgic_cpu;
struct vgic_irq *irq;
bool pending = false;
if (!vcpu->kvm->arch.vgic.enabled)
return false;
spin_lock(&vgic_cpu->ap_list_lock);
list_for_each_entry(irq, &vgic_cpu->ap_list_head, ap_list) {
spin_lock(&irq->irq_lock);
pending = irq_is_pending(irq) && irq->enabled;
spin_unlock(&irq->irq_lock);
if (pending)
break;
}
spin_unlock(&vgic_cpu->ap_list_lock);
return pending;
}
void vgic_kick_vcpus(struct kvm *kvm)
{
struct kvm_vcpu *vcpu;
int c;
kvm_for_each_vcpu(c, vcpu, kvm) {
if (kvm_vgic_vcpu_pending_irq(vcpu)) {
kvm_make_request(KVM_REQ_IRQ_PENDING, vcpu);
kvm_vcpu_kick(vcpu);
}
}
}
bool kvm_vgic_map_is_active(struct kvm_vcpu *vcpu, unsigned int virt_irq)
{
struct vgic_irq *irq = vgic_get_irq(vcpu->kvm, vcpu, virt_irq);
bool map_is_active;
spin_lock(&irq->irq_lock);
map_is_active = irq->hw && irq->active;
spin_unlock(&irq->irq_lock);
vgic_put_irq(vcpu->kvm, irq);
return map_is_active;
}
