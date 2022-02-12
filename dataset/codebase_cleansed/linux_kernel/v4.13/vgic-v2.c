static inline void vgic_v2_write_lr(int lr, u32 val)
{
void __iomem *base = kvm_vgic_global_state.vctrl_base;
writel_relaxed(val, base + GICH_LR0 + (lr * 4));
}
void vgic_v2_init_lrs(void)
{
int i;
for (i = 0; i < kvm_vgic_global_state.nr_lr; i++)
vgic_v2_write_lr(i, 0);
}
void vgic_v2_set_underflow(struct kvm_vcpu *vcpu)
{
struct vgic_v2_cpu_if *cpuif = &vcpu->arch.vgic_cpu.vgic_v2;
cpuif->vgic_hcr |= GICH_HCR_UIE;
}
static bool lr_signals_eoi_mi(u32 lr_val)
{
return !(lr_val & GICH_LR_STATE) && (lr_val & GICH_LR_EOI) &&
!(lr_val & GICH_LR_HW);
}
void vgic_v2_fold_lr_state(struct kvm_vcpu *vcpu)
{
struct vgic_cpu *vgic_cpu = &vcpu->arch.vgic_cpu;
struct vgic_v2_cpu_if *cpuif = &vgic_cpu->vgic_v2;
int lr;
cpuif->vgic_hcr &= ~GICH_HCR_UIE;
for (lr = 0; lr < vgic_cpu->used_lrs; lr++) {
u32 val = cpuif->vgic_lr[lr];
u32 intid = val & GICH_LR_VIRTUALID;
struct vgic_irq *irq;
if (lr_signals_eoi_mi(val) && vgic_valid_spi(vcpu->kvm, intid))
kvm_notify_acked_irq(vcpu->kvm, 0,
intid - VGIC_NR_PRIVATE_IRQS);
irq = vgic_get_irq(vcpu->kvm, vcpu, intid);
spin_lock(&irq->irq_lock);
irq->active = !!(val & GICH_LR_ACTIVE_BIT);
if (irq->config == VGIC_CONFIG_EDGE &&
(val & GICH_LR_PENDING_BIT)) {
irq->pending_latch = true;
if (vgic_irq_is_sgi(intid)) {
u32 cpuid = val & GICH_LR_PHYSID_CPUID;
cpuid >>= GICH_LR_PHYSID_CPUID_SHIFT;
irq->source |= (1 << cpuid);
}
}
if (irq->config == VGIC_CONFIG_LEVEL) {
if (!(val & GICH_LR_PENDING_BIT))
irq->pending_latch = false;
}
spin_unlock(&irq->irq_lock);
vgic_put_irq(vcpu->kvm, irq);
}
vgic_cpu->used_lrs = 0;
}
void vgic_v2_populate_lr(struct kvm_vcpu *vcpu, struct vgic_irq *irq, int lr)
{
u32 val = irq->intid;
if (irq_is_pending(irq)) {
val |= GICH_LR_PENDING_BIT;
if (irq->config == VGIC_CONFIG_EDGE)
irq->pending_latch = false;
if (vgic_irq_is_sgi(irq->intid)) {
u32 src = ffs(irq->source);
BUG_ON(!src);
val |= (src - 1) << GICH_LR_PHYSID_CPUID_SHIFT;
irq->source &= ~(1 << (src - 1));
if (irq->source)
irq->pending_latch = true;
}
}
if (irq->active)
val |= GICH_LR_ACTIVE_BIT;
if (irq->hw) {
val |= GICH_LR_HW;
val |= irq->hwintid << GICH_LR_PHYSID_CPUID_SHIFT;
if (irq->active && irq_is_pending(irq))
val &= ~GICH_LR_PENDING_BIT;
} else {
if (irq->config == VGIC_CONFIG_LEVEL)
val |= GICH_LR_EOI;
}
val |= (irq->priority >> 3) << GICH_LR_PRIORITY_SHIFT;
vcpu->arch.vgic_cpu.vgic_v2.vgic_lr[lr] = val;
}
void vgic_v2_clear_lr(struct kvm_vcpu *vcpu, int lr)
{
vcpu->arch.vgic_cpu.vgic_v2.vgic_lr[lr] = 0;
}
void vgic_v2_set_vmcr(struct kvm_vcpu *vcpu, struct vgic_vmcr *vmcrp)
{
struct vgic_v2_cpu_if *cpu_if = &vcpu->arch.vgic_cpu.vgic_v2;
u32 vmcr;
vmcr = (vmcrp->grpen0 << GICH_VMCR_ENABLE_GRP0_SHIFT) &
GICH_VMCR_ENABLE_GRP0_MASK;
vmcr |= (vmcrp->grpen1 << GICH_VMCR_ENABLE_GRP1_SHIFT) &
GICH_VMCR_ENABLE_GRP1_MASK;
vmcr |= (vmcrp->ackctl << GICH_VMCR_ACK_CTL_SHIFT) &
GICH_VMCR_ACK_CTL_MASK;
vmcr |= (vmcrp->fiqen << GICH_VMCR_FIQ_EN_SHIFT) &
GICH_VMCR_FIQ_EN_MASK;
vmcr |= (vmcrp->cbpr << GICH_VMCR_CBPR_SHIFT) &
GICH_VMCR_CBPR_MASK;
vmcr |= (vmcrp->eoim << GICH_VMCR_EOI_MODE_SHIFT) &
GICH_VMCR_EOI_MODE_MASK;
vmcr |= (vmcrp->abpr << GICH_VMCR_ALIAS_BINPOINT_SHIFT) &
GICH_VMCR_ALIAS_BINPOINT_MASK;
vmcr |= (vmcrp->bpr << GICH_VMCR_BINPOINT_SHIFT) &
GICH_VMCR_BINPOINT_MASK;
vmcr |= ((vmcrp->pmr >> GICV_PMR_PRIORITY_SHIFT) <<
GICH_VMCR_PRIMASK_SHIFT) & GICH_VMCR_PRIMASK_MASK;
cpu_if->vgic_vmcr = vmcr;
}
void vgic_v2_get_vmcr(struct kvm_vcpu *vcpu, struct vgic_vmcr *vmcrp)
{
struct vgic_v2_cpu_if *cpu_if = &vcpu->arch.vgic_cpu.vgic_v2;
u32 vmcr;
vmcr = cpu_if->vgic_vmcr;
vmcrp->grpen0 = (vmcr & GICH_VMCR_ENABLE_GRP0_MASK) >>
GICH_VMCR_ENABLE_GRP0_SHIFT;
vmcrp->grpen1 = (vmcr & GICH_VMCR_ENABLE_GRP1_MASK) >>
GICH_VMCR_ENABLE_GRP1_SHIFT;
vmcrp->ackctl = (vmcr & GICH_VMCR_ACK_CTL_MASK) >>
GICH_VMCR_ACK_CTL_SHIFT;
vmcrp->fiqen = (vmcr & GICH_VMCR_FIQ_EN_MASK) >>
GICH_VMCR_FIQ_EN_SHIFT;
vmcrp->cbpr = (vmcr & GICH_VMCR_CBPR_MASK) >>
GICH_VMCR_CBPR_SHIFT;
vmcrp->eoim = (vmcr & GICH_VMCR_EOI_MODE_MASK) >>
GICH_VMCR_EOI_MODE_SHIFT;
vmcrp->abpr = (vmcr & GICH_VMCR_ALIAS_BINPOINT_MASK) >>
GICH_VMCR_ALIAS_BINPOINT_SHIFT;
vmcrp->bpr = (vmcr & GICH_VMCR_BINPOINT_MASK) >>
GICH_VMCR_BINPOINT_SHIFT;
vmcrp->pmr = ((vmcr & GICH_VMCR_PRIMASK_MASK) >>
GICH_VMCR_PRIMASK_SHIFT) << GICV_PMR_PRIORITY_SHIFT;
}
void vgic_v2_enable(struct kvm_vcpu *vcpu)
{
vcpu->arch.vgic_cpu.vgic_v2.vgic_vmcr = 0;
vcpu->arch.vgic_cpu.vgic_v2.vgic_elrsr = ~0;
vcpu->arch.vgic_cpu.vgic_v2.vgic_hcr = GICH_HCR_EN;
}
static bool vgic_v2_check_base(gpa_t dist_base, gpa_t cpu_base)
{
if (dist_base + KVM_VGIC_V2_DIST_SIZE < dist_base)
return false;
if (cpu_base + KVM_VGIC_V2_CPU_SIZE < cpu_base)
return false;
if (dist_base + KVM_VGIC_V2_DIST_SIZE <= cpu_base)
return true;
if (cpu_base + KVM_VGIC_V2_CPU_SIZE <= dist_base)
return true;
return false;
}
int vgic_v2_map_resources(struct kvm *kvm)
{
struct vgic_dist *dist = &kvm->arch.vgic;
int ret = 0;
if (vgic_ready(kvm))
goto out;
if (IS_VGIC_ADDR_UNDEF(dist->vgic_dist_base) ||
IS_VGIC_ADDR_UNDEF(dist->vgic_cpu_base)) {
kvm_err("Need to set vgic cpu and dist addresses first\n");
ret = -ENXIO;
goto out;
}
if (!vgic_v2_check_base(dist->vgic_dist_base, dist->vgic_cpu_base)) {
kvm_err("VGIC CPU and dist frames overlap\n");
ret = -EINVAL;
goto out;
}
ret = vgic_init(kvm);
if (ret) {
kvm_err("Unable to initialize VGIC dynamic data structures\n");
goto out;
}
ret = vgic_register_dist_iodev(kvm, dist->vgic_dist_base, VGIC_V2);
if (ret) {
kvm_err("Unable to register VGIC MMIO regions\n");
goto out;
}
if (!static_branch_unlikely(&vgic_v2_cpuif_trap)) {
ret = kvm_phys_addr_ioremap(kvm, dist->vgic_cpu_base,
kvm_vgic_global_state.vcpu_base,
KVM_VGIC_V2_CPU_SIZE, true);
if (ret) {
kvm_err("Unable to remap VGIC CPU to VCPU\n");
goto out;
}
}
dist->ready = true;
out:
return ret;
}
int vgic_v2_probe(const struct gic_kvm_info *info)
{
int ret;
u32 vtr;
if (!info->vctrl.start) {
kvm_err("GICH not present in the firmware table\n");
return -ENXIO;
}
if (!PAGE_ALIGNED(info->vcpu.start) ||
!PAGE_ALIGNED(resource_size(&info->vcpu))) {
kvm_info("GICV region size/alignment is unsafe, using trapping (reduced performance)\n");
kvm_vgic_global_state.vcpu_base_va = ioremap(info->vcpu.start,
resource_size(&info->vcpu));
if (!kvm_vgic_global_state.vcpu_base_va) {
kvm_err("Cannot ioremap GICV\n");
return -ENOMEM;
}
ret = create_hyp_io_mappings(kvm_vgic_global_state.vcpu_base_va,
kvm_vgic_global_state.vcpu_base_va + resource_size(&info->vcpu),
info->vcpu.start);
if (ret) {
kvm_err("Cannot map GICV into hyp\n");
goto out;
}
static_branch_enable(&vgic_v2_cpuif_trap);
}
kvm_vgic_global_state.vctrl_base = ioremap(info->vctrl.start,
resource_size(&info->vctrl));
if (!kvm_vgic_global_state.vctrl_base) {
kvm_err("Cannot ioremap GICH\n");
ret = -ENOMEM;
goto out;
}
vtr = readl_relaxed(kvm_vgic_global_state.vctrl_base + GICH_VTR);
kvm_vgic_global_state.nr_lr = (vtr & 0x3f) + 1;
ret = create_hyp_io_mappings(kvm_vgic_global_state.vctrl_base,
kvm_vgic_global_state.vctrl_base +
resource_size(&info->vctrl),
info->vctrl.start);
if (ret) {
kvm_err("Cannot map VCTRL into hyp\n");
goto out;
}
ret = kvm_register_vgic_device(KVM_DEV_TYPE_ARM_VGIC_V2);
if (ret) {
kvm_err("Cannot register GICv2 KVM device\n");
goto out;
}
kvm_vgic_global_state.can_emulate_gicv2 = true;
kvm_vgic_global_state.vcpu_base = info->vcpu.start;
kvm_vgic_global_state.type = VGIC_V2;
kvm_vgic_global_state.max_gic_vcpus = VGIC_V2_MAX_CPUS;
kvm_info("vgic-v2@%llx\n", info->vctrl.start);
return 0;
out:
if (kvm_vgic_global_state.vctrl_base)
iounmap(kvm_vgic_global_state.vctrl_base);
if (kvm_vgic_global_state.vcpu_base_va)
iounmap(kvm_vgic_global_state.vcpu_base_va);
return ret;
}
void vgic_v2_load(struct kvm_vcpu *vcpu)
{
struct vgic_v2_cpu_if *cpu_if = &vcpu->arch.vgic_cpu.vgic_v2;
struct vgic_dist *vgic = &vcpu->kvm->arch.vgic;
writel_relaxed(cpu_if->vgic_vmcr, vgic->vctrl_base + GICH_VMCR);
}
void vgic_v2_put(struct kvm_vcpu *vcpu)
{
struct vgic_v2_cpu_if *cpu_if = &vcpu->arch.vgic_cpu.vgic_v2;
struct vgic_dist *vgic = &vcpu->kvm->arch.vgic;
cpu_if->vgic_vmcr = readl_relaxed(vgic->vctrl_base + GICH_VMCR);
}
