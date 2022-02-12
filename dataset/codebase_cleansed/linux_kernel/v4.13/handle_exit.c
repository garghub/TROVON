static int handle_hvc(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
int ret;
trace_kvm_hvc_arm64(*vcpu_pc(vcpu), vcpu_get_reg(vcpu, 0),
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
static int handle_no_fpsimd(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
kvm_inject_undefined(vcpu);
return 1;
}
static int kvm_handle_wfx(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
if (kvm_vcpu_get_hsr(vcpu) & ESR_ELx_WFx_ISS_WFE) {
trace_kvm_wfx_arm64(*vcpu_pc(vcpu), true);
vcpu->stat.wfe_exit_stat++;
kvm_vcpu_on_spin(vcpu);
} else {
trace_kvm_wfx_arm64(*vcpu_pc(vcpu), false);
vcpu->stat.wfi_exit_stat++;
kvm_vcpu_block(vcpu);
kvm_clear_request(KVM_REQ_UNHALT, vcpu);
}
kvm_skip_instr(vcpu, kvm_vcpu_trap_il_is32bit(vcpu));
return 1;
}
static int kvm_handle_guest_debug(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
u32 hsr = kvm_vcpu_get_hsr(vcpu);
int ret = 0;
run->exit_reason = KVM_EXIT_DEBUG;
run->debug.arch.hsr = hsr;
switch (ESR_ELx_EC(hsr)) {
case ESR_ELx_EC_WATCHPT_LOW:
run->debug.arch.far = vcpu->arch.fault.far_el2;
case ESR_ELx_EC_SOFTSTP_LOW:
case ESR_ELx_EC_BREAKPT_LOW:
case ESR_ELx_EC_BKPT32:
case ESR_ELx_EC_BRK64:
break;
default:
kvm_err("%s: un-handled case hsr: %#08x\n",
__func__, (unsigned int) hsr);
ret = -1;
break;
}
return ret;
}
static int kvm_handle_unknown_ec(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
u32 hsr = kvm_vcpu_get_hsr(vcpu);
kvm_pr_unimpl("Unknown exception class: hsr: %#08x -- %s\n",
hsr, esr_get_class_string(hsr));
kvm_inject_undefined(vcpu);
return 1;
}
static exit_handle_fn kvm_get_exit_handler(struct kvm_vcpu *vcpu)
{
u32 hsr = kvm_vcpu_get_hsr(vcpu);
u8 hsr_ec = ESR_ELx_EC(hsr);
return arm_exit_handlers[hsr_ec];
}
int handle_exit(struct kvm_vcpu *vcpu, struct kvm_run *run,
int exception_index)
{
exit_handle_fn exit_handler;
if (ARM_SERROR_PENDING(exception_index)) {
u8 hsr_ec = ESR_ELx_EC(kvm_vcpu_get_hsr(vcpu));
if (hsr_ec == ESR_ELx_EC_HVC32 || hsr_ec == ESR_ELx_EC_HVC64 ||
hsr_ec == ESR_ELx_EC_SMC32 || hsr_ec == ESR_ELx_EC_SMC64) {
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
case ARM_EXCEPTION_EL1_SERROR:
kvm_inject_vabt(vcpu);
return 1;
case ARM_EXCEPTION_TRAP:
if (!kvm_condition_valid(vcpu)) {
kvm_skip_instr(vcpu, kvm_vcpu_trap_il_is32bit(vcpu));
return 1;
}
exit_handler = kvm_get_exit_handler(vcpu);
return exit_handler(vcpu, run);
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
