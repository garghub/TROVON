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
*vcpu_reg32(vcpu, 14) = *vcpu_pc(vcpu) + return_offset;
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
static u64 get_except_vector(struct kvm_vcpu *vcpu, enum exception_type type)
{
u64 exc_offset;
switch (*vcpu_cpsr(vcpu) & (PSR_MODE_MASK | PSR_MODE32_BIT)) {
case PSR_MODE_EL1t:
exc_offset = CURRENT_EL_SP_EL0_VECTOR;
break;
case PSR_MODE_EL1h:
exc_offset = CURRENT_EL_SP_ELx_VECTOR;
break;
case PSR_MODE_EL0t:
exc_offset = LOWER_EL_AArch64_VECTOR;
break;
default:
exc_offset = LOWER_EL_AArch32_VECTOR;
}
return vcpu_sys_reg(vcpu, VBAR_EL1) + exc_offset + type;
}
static void inject_abt64(struct kvm_vcpu *vcpu, bool is_iabt, unsigned long addr)
{
unsigned long cpsr = *vcpu_cpsr(vcpu);
bool is_aarch32 = vcpu_mode_is_32bit(vcpu);
u32 esr = 0;
*vcpu_elr_el1(vcpu) = *vcpu_pc(vcpu);
*vcpu_pc(vcpu) = get_except_vector(vcpu, except_type_sync);
*vcpu_cpsr(vcpu) = PSTATE_FAULT_BITS_64;
*vcpu_spsr(vcpu) = cpsr;
vcpu_sys_reg(vcpu, FAR_EL1) = addr;
if (kvm_vcpu_trap_il_is32bit(vcpu))
esr |= ESR_ELx_IL;
if (is_aarch32 || (cpsr & PSR_MODE_MASK) == PSR_MODE_EL0t)
esr |= (ESR_ELx_EC_IABT_LOW << ESR_ELx_EC_SHIFT);
else
esr |= (ESR_ELx_EC_IABT_CUR << ESR_ELx_EC_SHIFT);
if (!is_iabt)
esr |= ESR_ELx_EC_DABT_LOW << ESR_ELx_EC_SHIFT;
vcpu_sys_reg(vcpu, ESR_EL1) = esr | ESR_ELx_FSC_EXTABT;
}
static void inject_undef64(struct kvm_vcpu *vcpu)
{
unsigned long cpsr = *vcpu_cpsr(vcpu);
u32 esr = (ESR_ELx_EC_UNKNOWN << ESR_ELx_EC_SHIFT);
*vcpu_elr_el1(vcpu) = *vcpu_pc(vcpu);
*vcpu_pc(vcpu) = get_except_vector(vcpu, except_type_sync);
*vcpu_cpsr(vcpu) = PSTATE_FAULT_BITS_64;
*vcpu_spsr(vcpu) = cpsr;
if (kvm_vcpu_trap_il_is32bit(vcpu))
esr |= ESR_ELx_IL;
vcpu_sys_reg(vcpu, ESR_EL1) = esr;
}
void kvm_inject_dabt(struct kvm_vcpu *vcpu, unsigned long addr)
{
if (!(vcpu->arch.hcr_el2 & HCR_RW))
inject_abt32(vcpu, false, addr);
else
inject_abt64(vcpu, false, addr);
}
void kvm_inject_pabt(struct kvm_vcpu *vcpu, unsigned long addr)
{
if (!(vcpu->arch.hcr_el2 & HCR_RW))
inject_abt32(vcpu, true, addr);
else
inject_abt64(vcpu, true, addr);
}
void kvm_inject_undefined(struct kvm_vcpu *vcpu)
{
if (!(vcpu->arch.hcr_el2 & HCR_RW))
inject_undef32(vcpu);
else
inject_undef64(vcpu);
}
