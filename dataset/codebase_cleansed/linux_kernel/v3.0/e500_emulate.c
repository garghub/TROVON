int kvmppc_core_emulate_op(struct kvm_run *run, struct kvm_vcpu *vcpu,
unsigned int inst, int *advance)
{
int emulated = EMULATE_DONE;
int ra;
int rb;
switch (get_op(inst)) {
case 31:
switch (get_xop(inst)) {
case XOP_TLBRE:
emulated = kvmppc_e500_emul_tlbre(vcpu);
break;
case XOP_TLBWE:
emulated = kvmppc_e500_emul_tlbwe(vcpu);
break;
case XOP_TLBSX:
rb = get_rb(inst);
emulated = kvmppc_e500_emul_tlbsx(vcpu,rb);
break;
case XOP_TLBIVAX:
ra = get_ra(inst);
rb = get_rb(inst);
emulated = kvmppc_e500_emul_tlbivax(vcpu, ra, rb);
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
int kvmppc_core_emulate_mtspr(struct kvm_vcpu *vcpu, int sprn, int rs)
{
struct kvmppc_vcpu_e500 *vcpu_e500 = to_e500(vcpu);
int emulated = EMULATE_DONE;
ulong spr_val = kvmppc_get_gpr(vcpu, rs);
switch (sprn) {
case SPRN_PID:
kvmppc_set_pid(vcpu, spr_val);
break;
case SPRN_PID1:
vcpu_e500->pid[1] = spr_val; break;
case SPRN_PID2:
vcpu_e500->pid[2] = spr_val; break;
case SPRN_MAS0:
vcpu_e500->mas0 = spr_val; break;
case SPRN_MAS1:
vcpu_e500->mas1 = spr_val; break;
case SPRN_MAS2:
vcpu_e500->mas2 = spr_val; break;
case SPRN_MAS3:
vcpu_e500->mas3 = spr_val; break;
case SPRN_MAS4:
vcpu_e500->mas4 = spr_val; break;
case SPRN_MAS6:
vcpu_e500->mas6 = spr_val; break;
case SPRN_MAS7:
vcpu_e500->mas7 = spr_val; break;
case SPRN_L1CSR0:
vcpu_e500->l1csr0 = spr_val;
vcpu_e500->l1csr0 &= ~(L1CSR0_DCFI | L1CSR0_CLFC);
break;
case SPRN_L1CSR1:
vcpu_e500->l1csr1 = spr_val; break;
case SPRN_HID0:
vcpu_e500->hid0 = spr_val; break;
case SPRN_HID1:
vcpu_e500->hid1 = spr_val; break;
case SPRN_MMUCSR0:
emulated = kvmppc_e500_emul_mt_mmucsr0(vcpu_e500,
spr_val);
break;
case SPRN_IVOR32:
vcpu->arch.ivor[BOOKE_IRQPRIO_SPE_UNAVAIL] = spr_val;
break;
case SPRN_IVOR33:
vcpu->arch.ivor[BOOKE_IRQPRIO_SPE_FP_DATA] = spr_val;
break;
case SPRN_IVOR34:
vcpu->arch.ivor[BOOKE_IRQPRIO_SPE_FP_ROUND] = spr_val;
break;
case SPRN_IVOR35:
vcpu->arch.ivor[BOOKE_IRQPRIO_PERFORMANCE_MONITOR] = spr_val;
break;
default:
emulated = kvmppc_booke_emulate_mtspr(vcpu, sprn, rs);
}
return emulated;
}
int kvmppc_core_emulate_mfspr(struct kvm_vcpu *vcpu, int sprn, int rt)
{
struct kvmppc_vcpu_e500 *vcpu_e500 = to_e500(vcpu);
int emulated = EMULATE_DONE;
switch (sprn) {
case SPRN_PID:
kvmppc_set_gpr(vcpu, rt, vcpu_e500->pid[0]); break;
case SPRN_PID1:
kvmppc_set_gpr(vcpu, rt, vcpu_e500->pid[1]); break;
case SPRN_PID2:
kvmppc_set_gpr(vcpu, rt, vcpu_e500->pid[2]); break;
case SPRN_MAS0:
kvmppc_set_gpr(vcpu, rt, vcpu_e500->mas0); break;
case SPRN_MAS1:
kvmppc_set_gpr(vcpu, rt, vcpu_e500->mas1); break;
case SPRN_MAS2:
kvmppc_set_gpr(vcpu, rt, vcpu_e500->mas2); break;
case SPRN_MAS3:
kvmppc_set_gpr(vcpu, rt, vcpu_e500->mas3); break;
case SPRN_MAS4:
kvmppc_set_gpr(vcpu, rt, vcpu_e500->mas4); break;
case SPRN_MAS6:
kvmppc_set_gpr(vcpu, rt, vcpu_e500->mas6); break;
case SPRN_MAS7:
kvmppc_set_gpr(vcpu, rt, vcpu_e500->mas7); break;
case SPRN_TLB0CFG:
kvmppc_set_gpr(vcpu, rt, vcpu_e500->tlb0cfg); break;
case SPRN_TLB1CFG:
kvmppc_set_gpr(vcpu, rt, vcpu_e500->tlb1cfg); break;
case SPRN_L1CSR0:
kvmppc_set_gpr(vcpu, rt, vcpu_e500->l1csr0); break;
case SPRN_L1CSR1:
kvmppc_set_gpr(vcpu, rt, vcpu_e500->l1csr1); break;
case SPRN_HID0:
kvmppc_set_gpr(vcpu, rt, vcpu_e500->hid0); break;
case SPRN_HID1:
kvmppc_set_gpr(vcpu, rt, vcpu_e500->hid1); break;
case SPRN_SVR:
kvmppc_set_gpr(vcpu, rt, vcpu_e500->svr); break;
case SPRN_MMUCSR0:
kvmppc_set_gpr(vcpu, rt, 0); break;
case SPRN_MMUCFG:
kvmppc_set_gpr(vcpu, rt, mfspr(SPRN_MMUCFG)); break;
case SPRN_IVOR32:
kvmppc_set_gpr(vcpu, rt, vcpu->arch.ivor[BOOKE_IRQPRIO_SPE_UNAVAIL]);
break;
case SPRN_IVOR33:
kvmppc_set_gpr(vcpu, rt, vcpu->arch.ivor[BOOKE_IRQPRIO_SPE_FP_DATA]);
break;
case SPRN_IVOR34:
kvmppc_set_gpr(vcpu, rt, vcpu->arch.ivor[BOOKE_IRQPRIO_SPE_FP_ROUND]);
break;
case SPRN_IVOR35:
kvmppc_set_gpr(vcpu, rt, vcpu->arch.ivor[BOOKE_IRQPRIO_PERFORMANCE_MONITOR]);
break;
default:
emulated = kvmppc_booke_emulate_mfspr(vcpu, sprn, rt);
}
return emulated;
}
