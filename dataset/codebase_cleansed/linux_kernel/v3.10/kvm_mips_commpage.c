void kvm_mips_commpage_init(struct kvm_vcpu *vcpu)
{
struct kvm_mips_commpage *page = vcpu->arch.kseg0_commpage;
memset(page, 0, sizeof(struct kvm_mips_commpage));
vcpu->arch.cop0 = &page->cop0;
memset(vcpu->arch.cop0, 0, sizeof(struct mips_coproc));
return;
}
