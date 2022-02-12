static bool access_actlr(struct kvm_vcpu *vcpu,
struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
if (p->is_write)
return ignore_write(vcpu, p);
p->regval = vcpu_sys_reg(vcpu, ACTLR_EL1);
return true;
}
static void reset_actlr(struct kvm_vcpu *vcpu, const struct sys_reg_desc *r)
{
vcpu_sys_reg(vcpu, ACTLR_EL1) = read_sysreg(actlr_el1);
}
static int __init sys_reg_genericv8_init(void)
{
unsigned int i;
for (i = 1; i < ARRAY_SIZE(genericv8_sys_regs); i++)
BUG_ON(cmp_sys_reg(&genericv8_sys_regs[i-1],
&genericv8_sys_regs[i]) >= 0);
kvm_register_target_sys_reg_table(KVM_ARM_TARGET_AEM_V8,
&genericv8_target_table);
kvm_register_target_sys_reg_table(KVM_ARM_TARGET_FOUNDATION_V8,
&genericv8_target_table);
kvm_register_target_sys_reg_table(KVM_ARM_TARGET_CORTEX_A53,
&genericv8_target_table);
kvm_register_target_sys_reg_table(KVM_ARM_TARGET_CORTEX_A57,
&genericv8_target_table);
kvm_register_target_sys_reg_table(KVM_ARM_TARGET_XGENE_POTENZA,
&genericv8_target_table);
kvm_register_target_sys_reg_table(KVM_ARM_TARGET_GENERIC_V8,
&genericv8_target_table);
return 0;
}
