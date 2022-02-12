void kvm_mips_commpage_init(struct kvm_vcpu *vcpu)
{
struct kvm_mips_commpage *page = vcpu->arch.kseg0_commpage;
vcpu->arch.cop0 = &page->cop0;
}
