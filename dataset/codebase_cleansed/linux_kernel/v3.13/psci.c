static void kvm_psci_vcpu_off(struct kvm_vcpu *vcpu)
{
vcpu->arch.pause = true;
}
static unsigned long kvm_psci_vcpu_on(struct kvm_vcpu *source_vcpu)
{
struct kvm *kvm = source_vcpu->kvm;
struct kvm_vcpu *vcpu = NULL, *tmp;
wait_queue_head_t *wq;
unsigned long cpu_id;
unsigned long mpidr;
phys_addr_t target_pc;
int i;
cpu_id = *vcpu_reg(source_vcpu, 1);
if (vcpu_mode_is_32bit(source_vcpu))
cpu_id &= ~((u32) 0);
kvm_for_each_vcpu(i, tmp, kvm) {
mpidr = kvm_vcpu_get_mpidr(tmp);
if ((mpidr & MPIDR_HWID_BITMASK) == (cpu_id & MPIDR_HWID_BITMASK)) {
vcpu = tmp;
break;
}
}
if (!vcpu)
return KVM_PSCI_RET_INVAL;
target_pc = *vcpu_reg(source_vcpu, 2);
wq = kvm_arch_vcpu_wq(vcpu);
if (!waitqueue_active(wq))
return KVM_PSCI_RET_INVAL;
kvm_reset_vcpu(vcpu);
if (vcpu_mode_is_32bit(vcpu) && (target_pc & 1)) {
target_pc &= ~((phys_addr_t) 1);
vcpu_set_thumb(vcpu);
}
if (kvm_vcpu_is_be(source_vcpu))
kvm_vcpu_set_be(vcpu);
*vcpu_pc(vcpu) = target_pc;
vcpu->arch.pause = false;
smp_mb();
wake_up_interruptible(wq);
return KVM_PSCI_RET_SUCCESS;
}
bool kvm_psci_call(struct kvm_vcpu *vcpu)
{
unsigned long psci_fn = *vcpu_reg(vcpu, 0) & ~((u32) 0);
unsigned long val;
switch (psci_fn) {
case KVM_PSCI_FN_CPU_OFF:
kvm_psci_vcpu_off(vcpu);
val = KVM_PSCI_RET_SUCCESS;
break;
case KVM_PSCI_FN_CPU_ON:
val = kvm_psci_vcpu_on(vcpu);
break;
case KVM_PSCI_FN_CPU_SUSPEND:
case KVM_PSCI_FN_MIGRATE:
val = KVM_PSCI_RET_NI;
break;
default:
return false;
}
*vcpu_reg(vcpu, 0) = val;
return true;
}
