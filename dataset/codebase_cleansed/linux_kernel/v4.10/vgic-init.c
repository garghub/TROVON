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
if (irqchip_in_kernel(kvm))
return -EEXIST;
if (type == KVM_DEV_TYPE_ARM_VGIC_V2 &&
!kvm_vgic_global_state.can_emulate_gicv2)
return -ENODEV;
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
return ret;
}
static int kvm_vgic_dist_init(struct kvm *kvm, unsigned int nr_spis)
{
struct vgic_dist *dist = &kvm->arch.vgic;
struct kvm_vcpu *vcpu0 = kvm_get_vcpu(kvm, 0);
int i;
INIT_LIST_HEAD(&dist->lpi_list_head);
spin_lock_init(&dist->lpi_list_lock);
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
kref_init(&irq->refcount);
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
kref_init(&irq->refcount);
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
if (vgic_has_its(kvm))
dist->msis_require_devid = true;
kvm_for_each_vcpu(i, vcpu, kvm)
kvm_vgic_vcpu_init(vcpu);
ret = kvm_vgic_setup_default_irq_routing(kvm);
if (ret)
goto out;
dist->initialized = true;
out:
return ret;
}
static void kvm_vgic_dist_destroy(struct kvm *kvm)
{
struct vgic_dist *dist = &kvm->arch.vgic;
dist->ready = false;
dist->initialized = false;
kfree(dist->spis);
dist->nr_spis = 0;
}
void kvm_vgic_vcpu_destroy(struct kvm_vcpu *vcpu)
{
struct vgic_cpu *vgic_cpu = &vcpu->arch.vgic_cpu;
INIT_LIST_HEAD(&vgic_cpu->ap_list_head);
}
static void __kvm_vgic_destroy(struct kvm *kvm)
{
struct kvm_vcpu *vcpu;
int i;
kvm_vgic_dist_destroy(kvm);
kvm_for_each_vcpu(i, vcpu, kvm)
kvm_vgic_vcpu_destroy(vcpu);
}
void kvm_vgic_destroy(struct kvm *kvm)
{
mutex_lock(&kvm->lock);
__kvm_vgic_destroy(kvm);
mutex_unlock(&kvm->lock);
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
if (ret)
__kvm_vgic_destroy(kvm);
out:
mutex_unlock(&kvm->lock);
return ret;
}
static int vgic_init_cpu_starting(unsigned int cpu)
{
enable_percpu_irq(kvm_vgic_global_state.maint_irq, 0);
return 0;
}
static int vgic_init_cpu_dying(unsigned int cpu)
{
disable_percpu_irq(kvm_vgic_global_state.maint_irq);
return 0;
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
if (!ret) {
static_branch_enable(&kvm_vgic_global_state.gicv3_cpuif);
kvm_info("GIC system register CPU interface enabled\n");
}
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
ret = cpuhp_setup_state(CPUHP_AP_KVM_ARM_VGIC_INIT_STARTING,
"kvm/arm/vgic:starting",
vgic_init_cpu_starting, vgic_init_cpu_dying);
if (ret) {
kvm_err("Cannot register vgic CPU notifier\n");
goto out_free_irq;
}
kvm_info("vgic interrupt IRQ%d\n", kvm_vgic_global_state.maint_irq);
return 0;
out_free_irq:
free_percpu_irq(kvm_vgic_global_state.maint_irq,
kvm_get_running_vcpus());
return ret;
}
