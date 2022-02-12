static void __hyp_text __debug_save_spe_vhe(u64 *pmscr_el1)
{
}
static void __hyp_text __debug_save_spe_nvhe(u64 *pmscr_el1)
{
u64 reg;
if (!cpuid_feature_extract_unsigned_field(read_sysreg(id_aa64dfr0_el1),
ID_AA64DFR0_PMSVER_SHIFT))
return;
reg = read_sysreg_s(PMBIDR_EL1);
if (reg & PMBIDR_EL1_P)
return;
reg = read_sysreg_s(PMBLIMITR_EL1);
if (!(reg & PMBLIMITR_EL1_E))
return;
*pmscr_el1 = read_sysreg_s(PMSCR_EL1);
write_sysreg_s(0, PMSCR_EL1);
isb();
psb_csync();
dsb(nsh);
}
static void __hyp_text __debug_restore_spe(u64 pmscr_el1)
{
if (!pmscr_el1)
return;
isb();
write_sysreg_s(pmscr_el1, PMSCR_EL1);
}
void __hyp_text __debug_save_state(struct kvm_vcpu *vcpu,
struct kvm_guest_debug_arch *dbg,
struct kvm_cpu_context *ctxt)
{
u64 aa64dfr0;
int brps, wrps;
if (!(vcpu->arch.debug_flags & KVM_ARM64_DEBUG_DIRTY))
return;
aa64dfr0 = read_sysreg(id_aa64dfr0_el1);
brps = (aa64dfr0 >> 12) & 0xf;
wrps = (aa64dfr0 >> 20) & 0xf;
save_debug(dbg->dbg_bcr, dbgbcr, brps);
save_debug(dbg->dbg_bvr, dbgbvr, brps);
save_debug(dbg->dbg_wcr, dbgwcr, wrps);
save_debug(dbg->dbg_wvr, dbgwvr, wrps);
ctxt->sys_regs[MDCCINT_EL1] = read_sysreg(mdccint_el1);
}
void __hyp_text __debug_restore_state(struct kvm_vcpu *vcpu,
struct kvm_guest_debug_arch *dbg,
struct kvm_cpu_context *ctxt)
{
u64 aa64dfr0;
int brps, wrps;
if (!(vcpu->arch.debug_flags & KVM_ARM64_DEBUG_DIRTY))
return;
aa64dfr0 = read_sysreg(id_aa64dfr0_el1);
brps = (aa64dfr0 >> 12) & 0xf;
wrps = (aa64dfr0 >> 20) & 0xf;
restore_debug(dbg->dbg_bcr, dbgbcr, brps);
restore_debug(dbg->dbg_bvr, dbgbvr, brps);
restore_debug(dbg->dbg_wcr, dbgwcr, wrps);
restore_debug(dbg->dbg_wvr, dbgwvr, wrps);
write_sysreg(ctxt->sys_regs[MDCCINT_EL1], mdccint_el1);
}
void __hyp_text __debug_cond_save_host_state(struct kvm_vcpu *vcpu)
{
if ((vcpu->arch.ctxt.sys_regs[MDSCR_EL1] & DBG_MDSCR_KDE) ||
(vcpu->arch.ctxt.sys_regs[MDSCR_EL1] & DBG_MDSCR_MDE))
vcpu->arch.debug_flags |= KVM_ARM64_DEBUG_DIRTY;
__debug_save_state(vcpu, &vcpu->arch.host_debug_state.regs,
kern_hyp_va(vcpu->arch.host_cpu_context));
__debug_save_spe()(&vcpu->arch.host_debug_state.pmscr_el1);
}
void __hyp_text __debug_cond_restore_host_state(struct kvm_vcpu *vcpu)
{
__debug_restore_spe(vcpu->arch.host_debug_state.pmscr_el1);
__debug_restore_state(vcpu, &vcpu->arch.host_debug_state.regs,
kern_hyp_va(vcpu->arch.host_cpu_context));
if (vcpu->arch.debug_flags & KVM_ARM64_DEBUG_DIRTY)
vcpu->arch.debug_flags &= ~KVM_ARM64_DEBUG_DIRTY;
}
u32 __hyp_text __kvm_get_mdcr_el2(void)
{
return read_sysreg(mdcr_el2);
}
