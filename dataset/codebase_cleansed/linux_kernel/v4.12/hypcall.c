enum emulation_result kvm_mips_emul_hypcall(struct kvm_vcpu *vcpu,
union mips_instruction inst)
{
unsigned int code = (inst.co_format.code >> 5) & 0x3ff;
kvm_debug("[%#lx] HYPCALL %#03x\n", vcpu->arch.pc, code);
switch (code) {
case 0:
return EMULATE_HYPERCALL;
default:
return EMULATE_FAIL;
};
}
static int kvm_mips_hypercall(struct kvm_vcpu *vcpu, unsigned long num,
const unsigned long *args, unsigned long *hret)
{
*hret = -KVM_ENOSYS;
return RESUME_GUEST;
}
int kvm_mips_handle_hypcall(struct kvm_vcpu *vcpu)
{
unsigned long num, args[MAX_HYPCALL_ARGS];
num = vcpu->arch.gprs[2];
args[0] = vcpu->arch.gprs[4];
args[1] = vcpu->arch.gprs[5];
args[2] = vcpu->arch.gprs[6];
args[3] = vcpu->arch.gprs[7];
return kvm_mips_hypercall(vcpu, num,
args, &vcpu->arch.gprs[2] );
}
