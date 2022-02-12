void kvm_mips_commpage_init(struct kvm_vcpu *vcpu)\r\n{\r\nstruct kvm_mips_commpage *page = vcpu->arch.kseg0_commpage;\r\nvcpu->arch.cop0 = &page->cop0;\r\n}
