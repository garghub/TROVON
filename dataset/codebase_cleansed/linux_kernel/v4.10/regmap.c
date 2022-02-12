unsigned long *vcpu_reg32(const struct kvm_vcpu *vcpu, u8 reg_num)
{
unsigned long *reg_array = (unsigned long *)&vcpu->arch.ctxt.gp_regs.regs;
unsigned long mode = *vcpu_cpsr(vcpu) & COMPAT_PSR_MODE_MASK;
switch (mode) {
case COMPAT_PSR_MODE_USR ... COMPAT_PSR_MODE_SVC:
mode &= ~PSR_MODE32_BIT;
break;
case COMPAT_PSR_MODE_ABT:
mode = 4;
break;
case COMPAT_PSR_MODE_UND:
mode = 5;
break;
case COMPAT_PSR_MODE_SYS:
mode = 0;
break;
default:
BUG();
}
return reg_array + vcpu_reg_offsets[mode][reg_num];
}
unsigned long *vcpu_spsr32(const struct kvm_vcpu *vcpu)
{
unsigned long mode = *vcpu_cpsr(vcpu) & COMPAT_PSR_MODE_MASK;
switch (mode) {
case COMPAT_PSR_MODE_SVC:
mode = KVM_SPSR_SVC;
break;
case COMPAT_PSR_MODE_ABT:
mode = KVM_SPSR_ABT;
break;
case COMPAT_PSR_MODE_UND:
mode = KVM_SPSR_UND;
break;
case COMPAT_PSR_MODE_IRQ:
mode = KVM_SPSR_IRQ;
break;
case COMPAT_PSR_MODE_FIQ:
mode = KVM_SPSR_FIQ;
break;
default:
BUG();
}
return (unsigned long *)&vcpu_gp_regs(vcpu)->spsr[mode];
}
