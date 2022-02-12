int vgic_v3_has_cpu_sysregs_attr(struct kvm_vcpu *vcpu, bool is_write, u64 id,
u64 *reg)
{
return -ENXIO;
}
int vgic_v3_cpu_sysregs_uaccess(struct kvm_vcpu *vcpu, bool is_write, u64 id,
u64 *reg)
{
return -ENXIO;
}
