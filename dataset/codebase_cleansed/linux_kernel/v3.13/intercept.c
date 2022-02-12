static int handle_noop(struct kvm_vcpu *vcpu)
{
switch (vcpu->arch.sie_block->icptcode) {
case 0x0:
vcpu->stat.exit_null++;
break;
case 0x10:
vcpu->stat.exit_external_request++;
break;
case 0x14:
vcpu->stat.exit_external_interrupt++;
break;
default:
break;
}
return 0;
}
static int handle_stop(struct kvm_vcpu *vcpu)
{
int rc = 0;
vcpu->stat.exit_stop_request++;
spin_lock_bh(&vcpu->arch.local_int.lock);
trace_kvm_s390_stop_request(vcpu->arch.local_int.action_bits);
if (vcpu->arch.local_int.action_bits & ACTION_STOP_ON_STOP) {
atomic_set_mask(CPUSTAT_STOPPED,
&vcpu->arch.sie_block->cpuflags);
vcpu->arch.local_int.action_bits &= ~ACTION_STOP_ON_STOP;
VCPU_EVENT(vcpu, 3, "%s", "cpu stopped");
rc = -EOPNOTSUPP;
}
if (vcpu->arch.local_int.action_bits & ACTION_STORE_ON_STOP) {
vcpu->arch.local_int.action_bits &= ~ACTION_STORE_ON_STOP;
spin_unlock_bh(&vcpu->arch.local_int.lock);
rc = kvm_s390_vcpu_store_status(vcpu,
KVM_S390_STORE_STATUS_NOADDR);
if (rc >= 0)
rc = -EOPNOTSUPP;
} else
spin_unlock_bh(&vcpu->arch.local_int.lock);
return rc;
}
static int handle_validity(struct kvm_vcpu *vcpu)
{
int viwhy = vcpu->arch.sie_block->ipb >> 16;
vcpu->stat.exit_validity++;
trace_kvm_s390_intercept_validity(vcpu, viwhy);
WARN_ONCE(true, "kvm: unhandled validity intercept 0x%x\n", viwhy);
return -EOPNOTSUPP;
}
static int handle_instruction(struct kvm_vcpu *vcpu)
{
intercept_handler_t handler;
vcpu->stat.exit_instruction++;
trace_kvm_s390_intercept_instruction(vcpu,
vcpu->arch.sie_block->ipa,
vcpu->arch.sie_block->ipb);
handler = instruction_handlers[vcpu->arch.sie_block->ipa >> 8];
if (handler)
return handler(vcpu);
return -EOPNOTSUPP;
}
static int handle_prog(struct kvm_vcpu *vcpu)
{
vcpu->stat.exit_program_interruption++;
trace_kvm_s390_intercept_prog(vcpu, vcpu->arch.sie_block->iprcc);
return kvm_s390_inject_program_int(vcpu, vcpu->arch.sie_block->iprcc);
}
static int handle_instruction_and_prog(struct kvm_vcpu *vcpu)
{
int rc, rc2;
vcpu->stat.exit_instr_and_program++;
rc = handle_instruction(vcpu);
rc2 = handle_prog(vcpu);
if (rc == -EOPNOTSUPP)
vcpu->arch.sie_block->icptcode = 0x04;
if (rc)
return rc;
return rc2;
}
int kvm_handle_sie_intercept(struct kvm_vcpu *vcpu)
{
intercept_handler_t func;
u8 code = vcpu->arch.sie_block->icptcode;
if (code & 3 || (code >> 2) >= ARRAY_SIZE(intercept_funcs))
return -EOPNOTSUPP;
func = intercept_funcs[code >> 2];
if (func)
return func(vcpu);
return -EOPNOTSUPP;
}
