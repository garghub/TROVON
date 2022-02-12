void __hyp_text __timer_save_state(struct kvm_vcpu *vcpu)
{
struct kvm *kvm = kern_hyp_va(vcpu->kvm);
struct arch_timer_cpu *timer = &vcpu->arch.timer_cpu;
u64 val;
if (kvm->arch.timer.enabled) {
timer->cntv_ctl = read_sysreg(cntv_ctl_el0);
timer->cntv_cval = read_sysreg(cntv_cval_el0);
}
write_sysreg(0, cntv_ctl_el0);
val = read_sysreg(cnthctl_el2);
val |= CNTHCTL_EL1PCTEN | CNTHCTL_EL1PCEN;
write_sysreg(val, cnthctl_el2);
write_sysreg(0, cntvoff_el2);
}
void __hyp_text __timer_restore_state(struct kvm_vcpu *vcpu)
{
struct kvm *kvm = kern_hyp_va(vcpu->kvm);
struct arch_timer_cpu *timer = &vcpu->arch.timer_cpu;
u64 val;
val = read_sysreg(cnthctl_el2);
val &= ~CNTHCTL_EL1PCEN;
val |= CNTHCTL_EL1PCTEN;
write_sysreg(val, cnthctl_el2);
if (kvm->arch.timer.enabled) {
write_sysreg(kvm->arch.timer.cntvoff, cntvoff_el2);
write_sysreg(timer->cntv_cval, cntv_cval_el0);
isb();
write_sysreg(timer->cntv_ctl, cntv_ctl_el0);
}
}
