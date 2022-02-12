static void reset_mpidr(struct kvm_vcpu *vcpu, const struct coproc_reg *r)
{
vcpu->arch.cp15[c0_MPIDR] = (read_cpuid_mpidr() & ~MPIDR_LEVEL_MASK)
| (vcpu->vcpu_id & MPIDR_LEVEL_MASK);
}
static bool access_actlr(struct kvm_vcpu *vcpu,
const struct coproc_params *p,
const struct coproc_reg *r)
{
if (p->is_write)
return ignore_write(vcpu, p);
*vcpu_reg(vcpu, p->Rt1) = vcpu->arch.cp15[c1_ACTLR];
return true;
}
static bool access_cbar(struct kvm_vcpu *vcpu,
const struct coproc_params *p,
const struct coproc_reg *r)
{
if (p->is_write)
return write_to_read_only(vcpu, p);
return read_zero(vcpu, p);
}
static bool access_l2ctlr(struct kvm_vcpu *vcpu,
const struct coproc_params *p,
const struct coproc_reg *r)
{
if (p->is_write)
return ignore_write(vcpu, p);
*vcpu_reg(vcpu, p->Rt1) = vcpu->arch.cp15[c9_L2CTLR];
return true;
}
static void reset_l2ctlr(struct kvm_vcpu *vcpu, const struct coproc_reg *r)
{
u32 l2ctlr, ncores;
asm volatile("mrc p15, 1, %0, c9, c0, 2\n" : "=r" (l2ctlr));
l2ctlr &= ~(3 << 24);
ncores = atomic_read(&vcpu->kvm->online_vcpus) - 1;
l2ctlr |= (ncores & 3) << 24;
vcpu->arch.cp15[c9_L2CTLR] = l2ctlr;
}
static void reset_actlr(struct kvm_vcpu *vcpu, const struct coproc_reg *r)
{
u32 actlr;
asm volatile("mrc p15, 0, %0, c1, c0, 1\n" : "=r" (actlr));
if (atomic_read(&vcpu->kvm->online_vcpus) > 1)
actlr |= 1U << 6;
else
actlr &= ~(1U << 6);
vcpu->arch.cp15[c1_ACTLR] = actlr;
}
static bool access_l2ectlr(struct kvm_vcpu *vcpu,
const struct coproc_params *p,
const struct coproc_reg *r)
{
if (p->is_write)
return ignore_write(vcpu, p);
*vcpu_reg(vcpu, p->Rt1) = 0;
return true;
}
static int __init coproc_a15_init(void)
{
unsigned int i;
for (i = 1; i < ARRAY_SIZE(a15_regs); i++)
BUG_ON(cmp_reg(&a15_regs[i-1],
&a15_regs[i]) >= 0);
kvm_register_target_coproc_table(&a15_target_table);
return 0;
}
