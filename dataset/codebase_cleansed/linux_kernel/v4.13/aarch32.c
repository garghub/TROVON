bool __hyp_text kvm_condition_valid32(const struct kvm_vcpu *vcpu)
{
unsigned long cpsr;
u32 cpsr_cond;
int cond;
if (kvm_vcpu_get_hsr(vcpu) >> 30)
return true;
cond = kvm_vcpu_get_condition(vcpu);
if (cond == 0xE)
return true;
cpsr = *vcpu_cpsr(vcpu);
if (cond < 0) {
unsigned long it;
it = ((cpsr >> 8) & 0xFC) | ((cpsr >> 25) & 0x3);
if (it == 0)
return true;
cond = (it >> 4);
}
cpsr_cond = cpsr >> 28;
if (!((cc_map[cond] >> cpsr_cond) & 1))
return false;
return true;
}
static void __hyp_text kvm_adjust_itstate(struct kvm_vcpu *vcpu)
{
unsigned long itbits, cond;
unsigned long cpsr = *vcpu_cpsr(vcpu);
bool is_arm = !(cpsr & COMPAT_PSR_T_BIT);
if (is_arm || !(cpsr & COMPAT_PSR_IT_MASK))
return;
cond = (cpsr & 0xe000) >> 13;
itbits = (cpsr & 0x1c00) >> (10 - 2);
itbits |= (cpsr & (0x3 << 25)) >> 25;
if ((itbits & 0x7) == 0)
itbits = cond = 0;
else
itbits = (itbits << 1) & 0x1f;
cpsr &= ~COMPAT_PSR_IT_MASK;
cpsr |= cond << 13;
cpsr |= (itbits & 0x1c) << (10 - 2);
cpsr |= (itbits & 0x3) << 25;
*vcpu_cpsr(vcpu) = cpsr;
}
void __hyp_text kvm_skip_instr32(struct kvm_vcpu *vcpu, bool is_wide_instr)
{
bool is_thumb;
is_thumb = !!(*vcpu_cpsr(vcpu) & COMPAT_PSR_T_BIT);
if (is_thumb && !is_wide_instr)
*vcpu_pc(vcpu) += 2;
else
*vcpu_pc(vcpu) += 4;
kvm_adjust_itstate(vcpu);
}
