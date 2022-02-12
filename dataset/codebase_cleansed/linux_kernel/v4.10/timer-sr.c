void __hyp_text __timer_save_state(struct kvm_vcpu *vcpu)
{
struct arch_timer_cpu *timer = &vcpu->arch.timer_cpu;
u64 val;
if (timer->enabled) {
timer->cntv_ctl = read_sysreg_el0(cntv_ctl);
timer->cntv_cval = read_sysreg_el0(cntv_cval);
}
write_sysreg_el0(0, cntv_ctl);
if (!has_vhe()) {
val = read_sysreg(cnthctl_el2);
val |= CNTHCTL_EL1PCTEN | CNTHCTL_EL1PCEN;
write_sysreg(val, cnthctl_el2);
}
write_sysreg(0, cntvoff_el2);
}
void __hyp_text __timer_restore_state(struct kvm_vcpu *vcpu)
{
struct kvm *kvm = kern_hyp_va(vcpu->kvm);
struct arch_timer_cpu *timer = &vcpu->arch.timer_cpu;
u64 val;
if (!has_vhe()) {
val = read_sysreg(cnthctl_el2);
val &= ~CNTHCTL_EL1PCEN;
val |= CNTHCTL_EL1PCTEN;
write_sysreg(val, cnthctl_el2);
}
if (timer->enabled) {
write_sysreg(kvm->arch.timer.cntvoff, cntvoff_el2);
write_sysreg_el0(timer->cntv_cval, cntv_cval);
isb();
write_sysreg_el0(timer->cntv_ctl, cntv_ctl);
}
}
