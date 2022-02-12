static int handle_svc_hyp(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
kvm_debug("SVC called from Hyp mode shouldn't go here\n");
BUG();
return -EINVAL;
}
static int handle_hvc(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
trace_kvm_hvc(*vcpu_pc(vcpu), *vcpu_reg(vcpu, 0),
kvm_vcpu_hvc_get_imm(vcpu));
if (kvm_psci_call(vcpu))
return 1;
kvm_inject_undefined(vcpu);
return 1;
}
static int handle_smc(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
kvm_inject_undefined(vcpu);
return 1;
}
static int handle_pabt_hyp(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
kvm_err("Prefetch Abort taken from Hyp mode at %#08lx (HSR: %#08x)\n",
kvm_vcpu_get_hfar(vcpu), kvm_vcpu_get_hsr(vcpu));
return -EFAULT;
}
static int handle_dabt_hyp(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
kvm_err("Data Abort taken from Hyp mode at %#08lx (HSR: %#08x)\n",
kvm_vcpu_get_hfar(vcpu), kvm_vcpu_get_hsr(vcpu));
return -EFAULT;
}
static int kvm_handle_wfi(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
trace_kvm_wfi(*vcpu_pc(vcpu));
kvm_vcpu_block(vcpu);
return 1;
}
static exit_handle_fn kvm_get_exit_handler(struct kvm_vcpu *vcpu)
{
u8 hsr_ec = kvm_vcpu_trap_get_class(vcpu);
if (hsr_ec >= ARRAY_SIZE(arm_exit_handlers) ||
!arm_exit_handlers[hsr_ec]) {
kvm_err("Unknown exception class: hsr: %#08x\n",
(unsigned int)kvm_vcpu_get_hsr(vcpu));
BUG();
}
return arm_exit_handlers[hsr_ec];
}
int handle_exit(struct kvm_vcpu *vcpu, struct kvm_run *run,
int exception_index)
{
exit_handle_fn exit_handler;
switch (exception_index) {
case ARM_EXCEPTION_IRQ:
return 1;
case ARM_EXCEPTION_UNDEFINED:
kvm_err("Undefined exception in Hyp mode at: %#08lx\n",
kvm_vcpu_get_hyp_pc(vcpu));
BUG();
panic("KVM: Hypervisor undefined exception!\n");
case ARM_EXCEPTION_DATA_ABORT:
case ARM_EXCEPTION_PREF_ABORT:
case ARM_EXCEPTION_HVC:
if (!kvm_condition_valid(vcpu)) {
kvm_skip_instr(vcpu, kvm_vcpu_trap_il_is32bit(vcpu));
return 1;
}
exit_handler = kvm_get_exit_handler(vcpu);
return exit_handler(vcpu, run);
default:
kvm_pr_unimpl("Unsupported exception type: %d",
exception_index);
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
return 0;
}
}
