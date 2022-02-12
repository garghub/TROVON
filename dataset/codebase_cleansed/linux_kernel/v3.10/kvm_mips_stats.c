int kvm_mips_dump_stats(struct kvm_vcpu *vcpu)
{
#ifdef CONFIG_KVM_MIPS_DEBUG_COP0_COUNTERS
int i, j;
printk("\nKVM VCPU[%d] COP0 Access Profile:\n", vcpu->vcpu_id);
for (i = 0; i < N_MIPS_COPROC_REGS; i++) {
for (j = 0; j < N_MIPS_COPROC_SEL; j++) {
if (vcpu->arch.cop0->stat[i][j])
printk("%s[%d]: %lu\n", kvm_cop0_str[i], j,
vcpu->arch.cop0->stat[i][j]);
}
}
#endif
return 0;
}
