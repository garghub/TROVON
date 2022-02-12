static void prepare_fault32(struct kvm_vcpu *vcpu, u32 mode, u32 vect_offset)
{
unsigned long cpsr;
unsigned long new_spsr_value = *vcpu_cpsr(vcpu);
bool is_thumb = (new_spsr_value & COMPAT_PSR_T_BIT);
u32 return_offset = (is_thumb) ? 4 : 0;
u32 sctlr = vcpu_cp15(vcpu, c1_SCTLR);
cpsr = mode | COMPAT_PSR_I_BIT;
if (sctlr & (1 << 30))
cpsr |= COMPAT_PSR_T_BIT;
if (sctlr & (1 << 25))
cpsr |= COMPAT_PSR_E_BIT;
*vcpu_cpsr(vcpu) = cpsr;
*vcpu_spsr(vcpu) = new_spsr_value;
*vcpu_reg(vcpu, 14) = *vcpu_pc(vcpu) + return_offset;
if (sctlr & (1 << 13))
vect_offset += 0xffff0000;
else
vect_offset += vcpu_cp15(vcpu, c12_VBAR);
*vcpu_pc(vcpu) = vect_offset;
}
static void inject_undef32(struct kvm_vcpu *vcpu)
{
prepare_fault32(vcpu, COMPAT_PSR_MODE_UND, 4);
}
static void inject_abt32(struct kvm_vcpu *vcpu, bool is_pabt,
unsigned long addr)
{
u32 vect_offset;
u32 *far, *fsr;
bool is_lpae;
if (is_pabt) {
vect_offset = 12;
far = &vcpu_cp15(vcpu, c6_IFAR);
fsr = &vcpu_cp15(vcpu, c5_IFSR);
} else {
vect_offset = 16;
far = &vcpu_cp15(vcpu, c6_DFAR);
fsr = &vcpu_cp15(vcpu, c5_DFSR);
}
prepare_fault32(vcpu, COMPAT_PSR_MODE_ABT | COMPAT_PSR_A_BIT, vect_offset);
*far = addr;
is_lpae = (vcpu_cp15(vcpu, c2_TTBCR) >> 31);
if (is_lpae)
*fsr = 1 << 9 | 0x34;
else
*fsr = 0x14;
}
static void inject_abt64(struct kvm_vcpu *vcpu, bool is_iabt, unsigned long addr)
{
unsigned long cpsr = *vcpu_cpsr(vcpu);
bool is_aarch32;
u32 esr = 0;
is_aarch32 = vcpu_mode_is_32bit(vcpu);
*vcpu_spsr(vcpu) = cpsr;
*vcpu_elr_el1(vcpu) = *vcpu_pc(vcpu);
*vcpu_cpsr(vcpu) = PSTATE_FAULT_BITS_64;
*vcpu_pc(vcpu) = vcpu_sys_reg(vcpu, VBAR_EL1) + EL1_EXCEPT_SYNC_OFFSET;
vcpu_sys_reg(vcpu, FAR_EL1) = addr;
if (kvm_vcpu_trap_il_is32bit(vcpu))
esr |= ESR_EL1_IL;
if (is_aarch32 || (cpsr & PSR_MODE_MASK) == PSR_MODE_EL0t)
esr |= (ESR_EL1_EC_IABT_EL0 << ESR_EL1_EC_SHIFT);
else
esr |= (ESR_EL1_EC_IABT_EL1 << ESR_EL1_EC_SHIFT);
if (!is_iabt)
esr |= ESR_EL1_EC_DABT_EL0;
vcpu_sys_reg(vcpu, ESR_EL1) = esr | ESR_EL2_EC_xABT_xFSR_EXTABT;
}
static void inject_undef64(struct kvm_vcpu *vcpu)
{
unsigned long cpsr = *vcpu_cpsr(vcpu);
u32 esr = (ESR_EL1_EC_UNKNOWN << ESR_EL1_EC_SHIFT);
*vcpu_spsr(vcpu) = cpsr;
*vcpu_elr_el1(vcpu) = *vcpu_pc(vcpu);
*vcpu_cpsr(vcpu) = PSTATE_FAULT_BITS_64;
*vcpu_pc(vcpu) = vcpu_sys_reg(vcpu, VBAR_EL1) + EL1_EXCEPT_SYNC_OFFSET;
if (kvm_vcpu_trap_il_is32bit(vcpu))
esr |= ESR_EL1_IL;
vcpu_sys_reg(vcpu, ESR_EL1) = esr;
}
void kvm_inject_dabt(struct kvm_vcpu *vcpu, unsigned long addr)
{
if (!(vcpu->arch.hcr_el2 & HCR_RW))
inject_abt32(vcpu, false, addr);
inject_abt64(vcpu, false, addr);
}
void kvm_inject_pabt(struct kvm_vcpu *vcpu, unsigned long addr)
{
if (!(vcpu->arch.hcr_el2 & HCR_RW))
inject_abt32(vcpu, true, addr);
inject_abt64(vcpu, true, addr);
}
void kvm_inject_undefined(struct kvm_vcpu *vcpu)
{
if (!(vcpu->arch.hcr_el2 & HCR_RW))
inject_undef32(vcpu);
inject_undef64(vcpu);
}
