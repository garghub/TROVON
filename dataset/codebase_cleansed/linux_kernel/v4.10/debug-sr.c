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
__debug_save_state(vcpu, &vcpu->arch.host_debug_state,
kern_hyp_va(vcpu->arch.host_cpu_context));
}
void __hyp_text __debug_cond_restore_host_state(struct kvm_vcpu *vcpu)
{
__debug_restore_state(vcpu, &vcpu->arch.host_debug_state,
kern_hyp_va(vcpu->arch.host_cpu_context));
if (vcpu->arch.debug_flags & KVM_ARM64_DEBUG_DIRTY)
vcpu->arch.debug_flags &= ~KVM_ARM64_DEBUG_DIRTY;
}
u32 __hyp_text __kvm_get_mdcr_el2(void)
{
return read_sysreg(mdcr_el2);
}
