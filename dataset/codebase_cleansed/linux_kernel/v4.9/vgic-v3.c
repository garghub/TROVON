void vgic_v3_process_maintenance(struct kvm_vcpu *vcpu)
{
struct vgic_v3_cpu_if *cpuif = &vcpu->arch.vgic_cpu.vgic_v3;
u32 model = vcpu->kvm->arch.vgic.vgic_model;
if (cpuif->vgic_misr & ICH_MISR_EOI) {
unsigned long eisr_bmap = cpuif->vgic_eisr;
int lr;
for_each_set_bit(lr, &eisr_bmap, kvm_vgic_global_state.nr_lr) {
u32 intid;
u64 val = cpuif->vgic_lr[lr];
if (model == KVM_DEV_TYPE_ARM_VGIC_V3)
intid = val & ICH_LR_VIRTUAL_ID_MASK;
else
intid = val & GICH_LR_VIRTUALID;
WARN_ON(cpuif->vgic_lr[lr] & ICH_LR_STATE);
if (vgic_valid_spi(vcpu->kvm, intid))
kvm_notify_acked_irq(vcpu->kvm, 0,
intid - VGIC_NR_PRIVATE_IRQS);
}
cpuif->vgic_eisr = 0;
}
cpuif->vgic_hcr &= ~ICH_HCR_UIE;
}
void vgic_v3_set_underflow(struct kvm_vcpu *vcpu)
{
struct vgic_v3_cpu_if *cpuif = &vcpu->arch.vgic_cpu.vgic_v3;
cpuif->vgic_hcr |= ICH_HCR_UIE;
}
void vgic_v3_fold_lr_state(struct kvm_vcpu *vcpu)
{
struct vgic_v3_cpu_if *cpuif = &vcpu->arch.vgic_cpu.vgic_v3;
u32 model = vcpu->kvm->arch.vgic.vgic_model;
int lr;
for (lr = 0; lr < vcpu->arch.vgic_cpu.used_lrs; lr++) {
u64 val = cpuif->vgic_lr[lr];
u32 intid;
struct vgic_irq *irq;
if (model == KVM_DEV_TYPE_ARM_VGIC_V3)
intid = val & ICH_LR_VIRTUAL_ID_MASK;
else
intid = val & GICH_LR_VIRTUALID;
irq = vgic_get_irq(vcpu->kvm, vcpu, intid);
if (!irq)
continue;
spin_lock(&irq->irq_lock);
irq->active = !!(val & ICH_LR_ACTIVE_BIT);
if (irq->config == VGIC_CONFIG_EDGE &&
(val & ICH_LR_PENDING_BIT)) {
irq->pending = true;
if (vgic_irq_is_sgi(intid) &&
model == KVM_DEV_TYPE_ARM_VGIC_V2) {
u32 cpuid = val & GICH_LR_PHYSID_CPUID;
cpuid >>= GICH_LR_PHYSID_CPUID_SHIFT;
irq->source |= (1 << cpuid);
}
}
if (irq->config == VGIC_CONFIG_LEVEL) {
if (!(val & ICH_LR_PENDING_BIT))
irq->soft_pending = false;
irq->pending = irq->line_level || irq->soft_pending;
}
spin_unlock(&irq->irq_lock);
vgic_put_irq(vcpu->kvm, irq);
}
}
void vgic_v3_populate_lr(struct kvm_vcpu *vcpu, struct vgic_irq *irq, int lr)
{
u32 model = vcpu->kvm->arch.vgic.vgic_model;
u64 val = irq->intid;
if (irq->pending) {
val |= ICH_LR_PENDING_BIT;
if (irq->config == VGIC_CONFIG_EDGE)
irq->pending = false;
if (vgic_irq_is_sgi(irq->intid) &&
model == KVM_DEV_TYPE_ARM_VGIC_V2) {
u32 src = ffs(irq->source);
BUG_ON(!src);
val |= (src - 1) << GICH_LR_PHYSID_CPUID_SHIFT;
irq->source &= ~(1 << (src - 1));
if (irq->source)
irq->pending = true;
}
}
if (irq->active)
val |= ICH_LR_ACTIVE_BIT;
if (irq->hw) {
val |= ICH_LR_HW;
val |= ((u64)irq->hwintid) << ICH_LR_PHYS_ID_SHIFT;
} else {
if (irq->config == VGIC_CONFIG_LEVEL)
val |= ICH_LR_EOI;
}
if (model == KVM_DEV_TYPE_ARM_VGIC_V3)
val |= ICH_LR_GROUP;
val |= (u64)irq->priority << ICH_LR_PRIORITY_SHIFT;
vcpu->arch.vgic_cpu.vgic_v3.vgic_lr[lr] = val;
}
void vgic_v3_clear_lr(struct kvm_vcpu *vcpu, int lr)
{
vcpu->arch.vgic_cpu.vgic_v3.vgic_lr[lr] = 0;
}
void vgic_v3_set_vmcr(struct kvm_vcpu *vcpu, struct vgic_vmcr *vmcrp)
{
u32 vmcr;
vmcr = (vmcrp->ctlr << ICH_VMCR_CTLR_SHIFT) & ICH_VMCR_CTLR_MASK;
vmcr |= (vmcrp->abpr << ICH_VMCR_BPR1_SHIFT) & ICH_VMCR_BPR1_MASK;
vmcr |= (vmcrp->bpr << ICH_VMCR_BPR0_SHIFT) & ICH_VMCR_BPR0_MASK;
vmcr |= (vmcrp->pmr << ICH_VMCR_PMR_SHIFT) & ICH_VMCR_PMR_MASK;
vcpu->arch.vgic_cpu.vgic_v3.vgic_vmcr = vmcr;
}
void vgic_v3_get_vmcr(struct kvm_vcpu *vcpu, struct vgic_vmcr *vmcrp)
{
u32 vmcr = vcpu->arch.vgic_cpu.vgic_v3.vgic_vmcr;
vmcrp->ctlr = (vmcr & ICH_VMCR_CTLR_MASK) >> ICH_VMCR_CTLR_SHIFT;
vmcrp->abpr = (vmcr & ICH_VMCR_BPR1_MASK) >> ICH_VMCR_BPR1_SHIFT;
vmcrp->bpr = (vmcr & ICH_VMCR_BPR0_MASK) >> ICH_VMCR_BPR0_SHIFT;
vmcrp->pmr = (vmcr & ICH_VMCR_PMR_MASK) >> ICH_VMCR_PMR_SHIFT;
}
void vgic_v3_enable(struct kvm_vcpu *vcpu)
{
struct vgic_v3_cpu_if *vgic_v3 = &vcpu->arch.vgic_cpu.vgic_v3;
vgic_v3->vgic_vmcr = 0;
vgic_v3->vgic_elrsr = ~0;
if (vcpu->kvm->arch.vgic.vgic_model == KVM_DEV_TYPE_ARM_VGIC_V3) {
vgic_v3->vgic_sre = ICC_SRE_EL1_SRE;
vcpu->arch.vgic_cpu.pendbaser = INITIAL_PENDBASER_VALUE;
} else {
vgic_v3->vgic_sre = 0;
}
vgic_v3->vgic_hcr = ICH_HCR_EN;
}
static bool vgic_v3_check_base(struct kvm *kvm)
{
struct vgic_dist *d = &kvm->arch.vgic;
gpa_t redist_size = KVM_VGIC_V3_REDIST_SIZE;
redist_size *= atomic_read(&kvm->online_vcpus);
if (d->vgic_dist_base + KVM_VGIC_V3_DIST_SIZE < d->vgic_dist_base)
return false;
if (d->vgic_redist_base + redist_size < d->vgic_redist_base)
return false;
if (d->vgic_dist_base + KVM_VGIC_V3_DIST_SIZE <= d->vgic_redist_base)
return true;
if (d->vgic_redist_base + redist_size <= d->vgic_dist_base)
return true;
return false;
}
int vgic_v3_map_resources(struct kvm *kvm)
{
int ret = 0;
struct vgic_dist *dist = &kvm->arch.vgic;
if (vgic_ready(kvm))
goto out;
if (IS_VGIC_ADDR_UNDEF(dist->vgic_dist_base) ||
IS_VGIC_ADDR_UNDEF(dist->vgic_redist_base)) {
kvm_err("Need to set vgic distributor addresses first\n");
ret = -ENXIO;
goto out;
}
if (!vgic_v3_check_base(kvm)) {
kvm_err("VGIC redist and dist frames overlap\n");
ret = -EINVAL;
goto out;
}
if (!vgic_initialized(kvm)) {
ret = -EBUSY;
goto out;
}
ret = vgic_register_dist_iodev(kvm, dist->vgic_dist_base, VGIC_V3);
if (ret) {
kvm_err("Unable to register VGICv3 dist MMIO regions\n");
goto out;
}
ret = vgic_register_redist_iodevs(kvm, dist->vgic_redist_base);
if (ret) {
kvm_err("Unable to register VGICv3 redist MMIO regions\n");
goto out;
}
if (vgic_has_its(kvm)) {
ret = vgic_register_its_iodevs(kvm);
if (ret) {
kvm_err("Unable to register VGIC ITS MMIO regions\n");
goto out;
}
}
dist->ready = true;
out:
if (ret)
kvm_vgic_destroy(kvm);
return ret;
}
int vgic_v3_probe(const struct gic_kvm_info *info)
{
u32 ich_vtr_el2 = kvm_call_hyp(__vgic_v3_get_ich_vtr_el2);
int ret;
kvm_vgic_global_state.nr_lr = (ich_vtr_el2 & 0xf) + 1;
kvm_vgic_global_state.can_emulate_gicv2 = false;
if (!info->vcpu.start) {
kvm_info("GICv3: no GICV resource entry\n");
kvm_vgic_global_state.vcpu_base = 0;
} else if (!PAGE_ALIGNED(info->vcpu.start)) {
pr_warn("GICV physical address 0x%llx not page aligned\n",
(unsigned long long)info->vcpu.start);
kvm_vgic_global_state.vcpu_base = 0;
} else if (!PAGE_ALIGNED(resource_size(&info->vcpu))) {
pr_warn("GICV size 0x%llx not a multiple of page size 0x%lx\n",
(unsigned long long)resource_size(&info->vcpu),
PAGE_SIZE);
kvm_vgic_global_state.vcpu_base = 0;
} else {
kvm_vgic_global_state.vcpu_base = info->vcpu.start;
kvm_vgic_global_state.can_emulate_gicv2 = true;
ret = kvm_register_vgic_device(KVM_DEV_TYPE_ARM_VGIC_V2);
if (ret) {
kvm_err("Cannot register GICv2 KVM device.\n");
return ret;
}
kvm_info("vgic-v2@%llx\n", info->vcpu.start);
}
ret = kvm_register_vgic_device(KVM_DEV_TYPE_ARM_VGIC_V3);
if (ret) {
kvm_err("Cannot register GICv3 KVM device.\n");
kvm_unregister_device_ops(KVM_DEV_TYPE_ARM_VGIC_V2);
return ret;
}
if (kvm_vgic_global_state.vcpu_base == 0)
kvm_info("disabling GICv2 emulation\n");
kvm_vgic_global_state.vctrl_base = NULL;
kvm_vgic_global_state.type = VGIC_V3;
kvm_vgic_global_state.max_gic_vcpus = VGIC_V3_MAX_CPUS;
return 0;
}
