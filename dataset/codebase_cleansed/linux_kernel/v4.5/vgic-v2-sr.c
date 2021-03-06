void __hyp_text __vgic_v2_save_state(struct kvm_vcpu *vcpu)
{
struct kvm *kvm = kern_hyp_va(vcpu->kvm);
struct vgic_v2_cpu_if *cpu_if = &vcpu->arch.vgic_cpu.vgic_v2;
struct vgic_dist *vgic = &kvm->arch.vgic;
void __iomem *base = kern_hyp_va(vgic->vctrl_base);
u32 eisr0, eisr1, elrsr0, elrsr1;
int i, nr_lr;
if (!base)
return;
nr_lr = vcpu->arch.vgic_cpu.nr_lr;
cpu_if->vgic_vmcr = readl_relaxed(base + GICH_VMCR);
cpu_if->vgic_misr = readl_relaxed(base + GICH_MISR);
eisr0 = readl_relaxed(base + GICH_EISR0);
elrsr0 = readl_relaxed(base + GICH_ELRSR0);
if (unlikely(nr_lr > 32)) {
eisr1 = readl_relaxed(base + GICH_EISR1);
elrsr1 = readl_relaxed(base + GICH_ELRSR1);
} else {
eisr1 = elrsr1 = 0;
}
#ifdef CONFIG_CPU_BIG_ENDIAN
cpu_if->vgic_eisr = ((u64)eisr0 << 32) | eisr1;
cpu_if->vgic_elrsr = ((u64)elrsr0 << 32) | elrsr1;
#else
cpu_if->vgic_eisr = ((u64)eisr1 << 32) | eisr0;
cpu_if->vgic_elrsr = ((u64)elrsr1 << 32) | elrsr0;
#endif
cpu_if->vgic_apr = readl_relaxed(base + GICH_APR);
writel_relaxed(0, base + GICH_HCR);
for (i = 0; i < nr_lr; i++)
cpu_if->vgic_lr[i] = readl_relaxed(base + GICH_LR0 + (i * 4));
}
void __hyp_text __vgic_v2_restore_state(struct kvm_vcpu *vcpu)
{
struct kvm *kvm = kern_hyp_va(vcpu->kvm);
struct vgic_v2_cpu_if *cpu_if = &vcpu->arch.vgic_cpu.vgic_v2;
struct vgic_dist *vgic = &kvm->arch.vgic;
void __iomem *base = kern_hyp_va(vgic->vctrl_base);
int i, nr_lr;
if (!base)
return;
writel_relaxed(cpu_if->vgic_hcr, base + GICH_HCR);
writel_relaxed(cpu_if->vgic_vmcr, base + GICH_VMCR);
writel_relaxed(cpu_if->vgic_apr, base + GICH_APR);
nr_lr = vcpu->arch.vgic_cpu.nr_lr;
for (i = 0; i < nr_lr; i++)
writel_relaxed(cpu_if->vgic_lr[i], base + GICH_LR0 + (i * 4));
}
