bool kvm_arch_has_vcpu_debugfs(void)
{
return true;
}
static int vcpu_get_tsc_offset(void *data, u64 *val)
{
struct kvm_vcpu *vcpu = (struct kvm_vcpu *) data;
*val = vcpu->arch.tsc_offset;
return 0;
}
static int vcpu_get_tsc_scaling_ratio(void *data, u64 *val)
{
struct kvm_vcpu *vcpu = (struct kvm_vcpu *) data;
*val = vcpu->arch.tsc_scaling_ratio;
return 0;
}
static int vcpu_get_tsc_scaling_frac_bits(void *data, u64 *val)
{
*val = kvm_tsc_scaling_ratio_frac_bits;
return 0;
}
int kvm_arch_create_vcpu_debugfs(struct kvm_vcpu *vcpu)
{
struct dentry *ret;
ret = debugfs_create_file("tsc-offset", 0444,
vcpu->debugfs_dentry,
vcpu, &vcpu_tsc_offset_fops);
if (!ret)
return -ENOMEM;
if (kvm_has_tsc_control) {
ret = debugfs_create_file("tsc-scaling-ratio", 0444,
vcpu->debugfs_dentry,
vcpu, &vcpu_tsc_scaling_fops);
if (!ret)
return -ENOMEM;
ret = debugfs_create_file("tsc-scaling-ratio-frac-bits", 0444,
vcpu->debugfs_dentry,
vcpu, &vcpu_tsc_scaling_frac_fops);
if (!ret)
return -ENOMEM;
}
return 0;
}
