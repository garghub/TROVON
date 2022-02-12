static int handle_hvc(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
int ret;
trace_kvm_hvc(*vcpu_pc(vcpu), *vcpu_reg(vcpu, 0),
kvm_vcpu_hvc_get_imm(vcpu));
vcpu->stat.hvc_exit_stat++;
ret = kvm_psci_call(vcpu);
if (ret < 0) {
kvm_inject_undefined(vcpu);
return 1;
}
return ret;
}
static int handle_smc(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
kvm_inject_undefined(vcpu);
return 1;
}
static int kvm_handle_wfx(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
if (kvm_vcpu_get_hsr(vcpu) & HSR_WFI_IS_WFE) {
trace_kvm_wfx(*vcpu_pc(vcpu), true);
vcpu->stat.wfe_exit_stat++;
kvm_vcpu_on_spin(vcpu);
} else {
trace_kvm_wfx(*vcpu_pc(vcpu), false);
vcpu->stat.wfi_exit_stat++;
kvm_vcpu_block(vcpu);
}
kvm_skip_instr(vcpu, kvm_vcpu_trap_il_is32bit(vcpu));
return 1;
}
static int kvm_handle_unknown_ec(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
u32 hsr = kvm_vcpu_get_hsr(vcpu);
kvm_pr_unimpl("Unknown exception class: hsr: %#08x\n",
hsr);
kvm_inject_undefined(vcpu);
return 1;
}
static exit_handle_fn kvm_get_exit_handler(struct kvm_vcpu *vcpu)
{
u8 hsr_ec = kvm_vcpu_trap_get_class(vcpu);
return arm_exit_handlers[hsr_ec];
}
int handle_exit(struct kvm_vcpu *vcpu, struct kvm_run *run,
int exception_index)
{
exit_handle_fn exit_handler;
if (ARM_ABORT_PENDING(exception_index)) {
u8 hsr_ec = kvm_vcpu_trap_get_class(vcpu);
if (hsr_ec == HSR_EC_HVC || hsr_ec == HSR_EC_SMC) {
u32 adj = kvm_vcpu_trap_il_is32bit(vcpu) ? 4 : 2;
*vcpu_pc(vcpu) -= adj;
}
kvm_inject_vabt(vcpu);
return 1;
}
exception_index = ARM_EXCEPTION_CODE(exception_index);
switch (exception_index) {
case ARM_EXCEPTION_IRQ:
return 1;
case ARM_EXCEPTION_HVC:
if (!kvm_condition_valid(vcpu)) {
kvm_skip_instr(vcpu, kvm_vcpu_trap_il_is32bit(vcpu));
return 1;
}
exit_handler = kvm_get_exit_handler(vcpu);
return exit_handler(vcpu, run);
case ARM_EXCEPTION_DATA_ABORT:
kvm_inject_vabt(vcpu);
return 1;
case ARM_EXCEPTION_HYP_GONE:
run->exit_reason = KVM_EXIT_FAIL_ENTRY;
return 0;
default:
kvm_pr_unimpl("Unsupported exception type: %d",
exception_index);
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
return 0;
}
}
