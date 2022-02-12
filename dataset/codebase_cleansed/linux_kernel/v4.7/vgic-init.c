void kvm_vgic_early_init(struct kvm *kvm)
{
}
void kvm_vgic_vcpu_early_init(struct kvm_vcpu *vcpu)
{
}
int kvm_vgic_create(struct kvm *kvm, u32 type)
{
int i, vcpu_lock_idx = -1, ret;
struct kvm_vcpu *vcpu;
mutex_lock(&kvm->lock);
if (irqchip_in_kernel(kvm)) {
ret = -EEXIST;
goto out;
}
if (type == KVM_DEV_TYPE_ARM_VGIC_V2 &&
!kvm_vgic_global_state.can_emulate_gicv2) {
ret = -ENODEV;
goto out;
}
ret = -EBUSY;
kvm_for_each_vcpu(i, vcpu, kvm) {
if (!mutex_trylock(&vcpu->mutex))
goto out_unlock;
vcpu_lock_idx = i;
}
kvm_for_each_vcpu(i, vcpu, kvm) {
if (vcpu->arch.has_run_once)
goto out_unlock;
}
ret = 0;
if (type == KVM_DEV_TYPE_ARM_VGIC_V2)
kvm->arch.max_vcpus = VGIC_V2_MAX_CPUS;
else
kvm->arch.max_vcpus = VGIC_V3_MAX_CPUS;
if (atomic_read(&kvm->online_vcpus) > kvm->arch.max_vcpus) {
ret = -E2BIG;
goto out_unlock;
}
kvm->arch.vgic.in_kernel = true;
kvm->arch.vgic.vgic_model = type;
kvm->arch.vgic.vctrl_base = kvm_vgic_global_state.vctrl_base;
kvm->arch.vgic.vgic_dist_base = VGIC_ADDR_UNDEF;
kvm->arch.vgic.vgic_cpu_base = VGIC_ADDR_UNDEF;
kvm->arch.vgic.vgic_redist_base = VGIC_ADDR_UNDEF;
out_unlock:
for (; vcpu_lock_idx >= 0; vcpu_lock_idx--) {
vcpu = kvm_get_vcpu(kvm, vcpu_lock_idx);
mutex_unlock(&vcpu->mutex);
}
out:
mutex_unlock(&kvm->lock);
return ret;
}
static int kvm_vgic_dist_init(struct kvm *kvm, unsigned int nr_spis)
{
struct vgic_dist *dist = &kvm->arch.vgic;
struct kvm_vcpu *vcpu0 = kvm_get_vcpu(kvm, 0);
int i;
dist->spis = kcalloc(nr_spis, sizeof(struct vgic_irq), GFP_KERNEL);
if (!dist->spis)
return -ENOMEM;
for (i = 0; i < nr_spis; i++) {
struct vgic_irq *irq = &dist->spis[i];
irq->intid = i + VGIC_NR_PRIVATE_IRQS;
INIT_LIST_HEAD(&irq->ap_list);
spin_lock_init(&irq->irq_lock);
irq->vcpu = NULL;
irq->target_vcpu = vcpu0;
if (dist->vgic_model == KVM_DEV_TYPE_ARM_VGIC_V2)
irq->targets = 0;
else
irq->mpidr = 0;
}
return 0;
}
static void kvm_vgic_vcpu_init(struct kvm_vcpu *vcpu)
{
struct vgic_cpu *vgic_cpu = &vcpu->arch.vgic_cpu;
int i;
INIT_LIST_HEAD(&vgic_cpu->ap_list_head);
spin_lock_init(&vgic_cpu->ap_list_lock);
for (i = 0; i < VGIC_NR_PRIVATE_IRQS; i++) {
struct vgic_irq *irq = &vgic_cpu->private_irqs[i];
INIT_LIST_HEAD(&irq->ap_list);
spin_lock_init(&irq->irq_lock);
irq->intid = i;
irq->vcpu = NULL;
irq->target_vcpu = vcpu;
irq->targets = 1U << vcpu->vcpu_id;
if (vgic_irq_is_sgi(i)) {
irq->enabled = 1;
irq->config = VGIC_CONFIG_EDGE;
} else {
irq->config = VGIC_CONFIG_LEVEL;
}
}
if (kvm_vgic_global_state.type == VGIC_V2)
vgic_v2_enable(vcpu);
else
vgic_v3_enable(vcpu);
}
int vgic_init(struct kvm *kvm)
{
struct vgic_dist *dist = &kvm->arch.vgic;
struct kvm_vcpu *vcpu;
int ret = 0, i;
if (vgic_initialized(kvm))
return 0;
if (!dist->nr_spis)
dist->nr_spis = VGIC_NR_IRQS_LEGACY - VGIC_NR_PRIVATE_IRQS;
ret = kvm_vgic_dist_init(kvm, dist->nr_spis);
if (ret)
goto out;
kvm_for_each_vcpu(i, vcpu, kvm)
kvm_vgic_vcpu_init(vcpu);
dist->initialized = true;
out:
return ret;
}
static void kvm_vgic_dist_destroy(struct kvm *kvm)
{
struct vgic_dist *dist = &kvm->arch.vgic;
mutex_lock(&kvm->lock);
dist->ready = false;
dist->initialized = false;
kfree(dist->spis);
kfree(dist->redist_iodevs);
dist->nr_spis = 0;
mutex_unlock(&kvm->lock);
}
void kvm_vgic_vcpu_destroy(struct kvm_vcpu *vcpu)
{
struct vgic_cpu *vgic_cpu = &vcpu->arch.vgic_cpu;
INIT_LIST_HEAD(&vgic_cpu->ap_list_head);
}
void kvm_vgic_destroy(struct kvm *kvm)
{
struct kvm_vcpu *vcpu;
int i;
kvm_vgic_dist_destroy(kvm);
kvm_for_each_vcpu(i, vcpu, kvm)
kvm_vgic_vcpu_destroy(vcpu);
}
int vgic_lazy_init(struct kvm *kvm)
{
int ret = 0;
if (unlikely(!vgic_initialized(kvm))) {
if (kvm->arch.vgic.vgic_model != KVM_DEV_TYPE_ARM_VGIC_V2)
return -EBUSY;
mutex_lock(&kvm->lock);
ret = vgic_init(kvm);
mutex_unlock(&kvm->lock);
}
return ret;
}
int kvm_vgic_map_resources(struct kvm *kvm)
{
struct vgic_dist *dist = &kvm->arch.vgic;
int ret = 0;
mutex_lock(&kvm->lock);
if (!irqchip_in_kernel(kvm))
goto out;
if (dist->vgic_model == KVM_DEV_TYPE_ARM_VGIC_V2)
ret = vgic_v2_map_resources(kvm);
else
ret = vgic_v3_map_resources(kvm);
out:
mutex_unlock(&kvm->lock);
return ret;
}
static void vgic_init_maintenance_interrupt(void *info)
{
enable_percpu_irq(kvm_vgic_global_state.maint_irq, 0);
}
static int vgic_cpu_notify(struct notifier_block *self,
unsigned long action, void *cpu)
{
switch (action) {
case CPU_STARTING:
case CPU_STARTING_FROZEN:
vgic_init_maintenance_interrupt(NULL);
break;
case CPU_DYING:
case CPU_DYING_FROZEN:
disable_percpu_irq(kvm_vgic_global_state.maint_irq);
break;
}
return NOTIFY_OK;
}
static irqreturn_t vgic_maintenance_handler(int irq, void *data)
{
return IRQ_HANDLED;
}
int kvm_vgic_hyp_init(void)
{
const struct gic_kvm_info *gic_kvm_info;
int ret;
gic_kvm_info = gic_get_kvm_info();
if (!gic_kvm_info)
return -ENODEV;
if (!gic_kvm_info->maint_irq) {
kvm_err("No vgic maintenance irq\n");
return -ENXIO;
}
switch (gic_kvm_info->type) {
case GIC_V2:
ret = vgic_v2_probe(gic_kvm_info);
break;
case GIC_V3:
ret = vgic_v3_probe(gic_kvm_info);
break;
default:
ret = -ENODEV;
};
if (ret)
return ret;
kvm_vgic_global_state.maint_irq = gic_kvm_info->maint_irq;
ret = request_percpu_irq(kvm_vgic_global_state.maint_irq,
vgic_maintenance_handler,
"vgic", kvm_get_running_vcpus());
if (ret) {
kvm_err("Cannot register interrupt %d\n",
kvm_vgic_global_state.maint_irq);
return ret;
}
ret = __register_cpu_notifier(&vgic_cpu_nb);
if (ret) {
kvm_err("Cannot register vgic CPU notifier\n");
goto out_free_irq;
}
on_each_cpu(vgic_init_maintenance_interrupt, NULL, 1);
kvm_info("vgic interrupt IRQ%d\n", kvm_vgic_global_state.maint_irq);
return 0;
out_free_irq:
free_percpu_irq(kvm_vgic_global_state.maint_irq,
kvm_get_running_vcpus());
return ret;
}
