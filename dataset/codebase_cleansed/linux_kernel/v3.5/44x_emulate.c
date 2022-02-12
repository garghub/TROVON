int kvmppc_core_emulate_op(struct kvm_run *run, struct kvm_vcpu *vcpu,
unsigned int inst, int *advance)
{
int emulated = EMULATE_DONE;
int dcrn = get_dcrn(inst);
int ra = get_ra(inst);
int rb = get_rb(inst);
int rc = get_rc(inst);
int rs = get_rs(inst);
int rt = get_rt(inst);
int ws = get_ws(inst);
switch (get_op(inst)) {
case 31:
switch (get_xop(inst)) {
case XOP_MFDCR:
switch (dcrn) {
case DCRN_CPR0_CONFIG_ADDR:
kvmppc_set_gpr(vcpu, rt, vcpu->arch.cpr0_cfgaddr);
break;
case DCRN_CPR0_CONFIG_DATA:
local_irq_disable();
mtdcr(DCRN_CPR0_CONFIG_ADDR,
vcpu->arch.cpr0_cfgaddr);
kvmppc_set_gpr(vcpu, rt,
mfdcr(DCRN_CPR0_CONFIG_DATA));
local_irq_enable();
break;
default:
run->dcr.dcrn = dcrn;
run->dcr.data = 0;
run->dcr.is_write = 0;
vcpu->arch.io_gpr = rt;
vcpu->arch.dcr_needed = 1;
kvmppc_account_exit(vcpu, DCR_EXITS);
emulated = EMULATE_DO_DCR;
}
break;
case XOP_MTDCR:
switch (dcrn) {
case DCRN_CPR0_CONFIG_ADDR:
vcpu->arch.cpr0_cfgaddr = kvmppc_get_gpr(vcpu, rs);
break;
default:
run->dcr.dcrn = dcrn;
run->dcr.data = kvmppc_get_gpr(vcpu, rs);
run->dcr.is_write = 1;
vcpu->arch.dcr_needed = 1;
kvmppc_account_exit(vcpu, DCR_EXITS);
emulated = EMULATE_DO_DCR;
}
break;
case XOP_TLBWE:
emulated = kvmppc_44x_emul_tlbwe(vcpu, ra, rs, ws);
break;
case XOP_TLBSX:
emulated = kvmppc_44x_emul_tlbsx(vcpu, rt, ra, rb, rc);
break;
case XOP_ICCCI:
break;
default:
emulated = EMULATE_FAIL;
}
break;
default:
emulated = EMULATE_FAIL;
}
if (emulated == EMULATE_FAIL)
emulated = kvmppc_booke_emulate_op(run, vcpu, inst, advance);
return emulated;
}
int kvmppc_core_emulate_mtspr(struct kvm_vcpu *vcpu, int sprn, ulong spr_val)
{
int emulated = EMULATE_DONE;
switch (sprn) {
case SPRN_PID:
kvmppc_set_pid(vcpu, spr_val); break;
case SPRN_MMUCR:
vcpu->arch.mmucr = spr_val; break;
case SPRN_CCR0:
vcpu->arch.ccr0 = spr_val; break;
case SPRN_CCR1:
vcpu->arch.ccr1 = spr_val; break;
default:
emulated = kvmppc_booke_emulate_mtspr(vcpu, sprn, spr_val);
}
return emulated;
}
int kvmppc_core_emulate_mfspr(struct kvm_vcpu *vcpu, int sprn, ulong *spr_val)
{
int emulated = EMULATE_DONE;
switch (sprn) {
case SPRN_PID:
*spr_val = vcpu->arch.pid; break;
case SPRN_MMUCR:
*spr_val = vcpu->arch.mmucr; break;
case SPRN_CCR0:
*spr_val = vcpu->arch.ccr0; break;
case SPRN_CCR1:
*spr_val = vcpu->arch.ccr1; break;
default:
emulated = kvmppc_booke_emulate_mfspr(vcpu, sprn, spr_val);
}
return emulated;
}
