int kvmppc_emulate_loadstore(struct kvm_vcpu *vcpu)
{
struct kvm_run *run = vcpu->run;
u32 inst;
int ra, rs, rt;
enum emulation_result emulated;
int advance = 1;
kvmppc_set_exit_type(vcpu, EMULATED_INST_EXITS);
emulated = kvmppc_get_last_inst(vcpu, false, &inst);
if (emulated != EMULATE_DONE)
return emulated;
ra = get_ra(inst);
rs = get_rs(inst);
rt = get_rt(inst);
switch (get_op(inst)) {
case 31:
switch (get_xop(inst)) {
case OP_31_XOP_LWZX:
emulated = kvmppc_handle_load(run, vcpu, rt, 4, 1);
break;
case OP_31_XOP_LBZX:
emulated = kvmppc_handle_load(run, vcpu, rt, 1, 1);
break;
case OP_31_XOP_LBZUX:
emulated = kvmppc_handle_load(run, vcpu, rt, 1, 1);
kvmppc_set_gpr(vcpu, ra, vcpu->arch.vaddr_accessed);
break;
case OP_31_XOP_STWX:
emulated = kvmppc_handle_store(run, vcpu,
kvmppc_get_gpr(vcpu, rs),
4, 1);
break;
case OP_31_XOP_STBX:
emulated = kvmppc_handle_store(run, vcpu,
kvmppc_get_gpr(vcpu, rs),
1, 1);
break;
case OP_31_XOP_STBUX:
emulated = kvmppc_handle_store(run, vcpu,
kvmppc_get_gpr(vcpu, rs),
1, 1);
kvmppc_set_gpr(vcpu, ra, vcpu->arch.vaddr_accessed);
break;
case OP_31_XOP_LHAX:
emulated = kvmppc_handle_loads(run, vcpu, rt, 2, 1);
break;
case OP_31_XOP_LHZX:
emulated = kvmppc_handle_load(run, vcpu, rt, 2, 1);
break;
case OP_31_XOP_LHZUX:
emulated = kvmppc_handle_load(run, vcpu, rt, 2, 1);
kvmppc_set_gpr(vcpu, ra, vcpu->arch.vaddr_accessed);
break;
case OP_31_XOP_STHX:
emulated = kvmppc_handle_store(run, vcpu,
kvmppc_get_gpr(vcpu, rs),
2, 1);
break;
case OP_31_XOP_STHUX:
emulated = kvmppc_handle_store(run, vcpu,
kvmppc_get_gpr(vcpu, rs),
2, 1);
kvmppc_set_gpr(vcpu, ra, vcpu->arch.vaddr_accessed);
break;
case OP_31_XOP_DCBST:
case OP_31_XOP_DCBF:
case OP_31_XOP_DCBI:
break;
case OP_31_XOP_LWBRX:
emulated = kvmppc_handle_load(run, vcpu, rt, 4, 0);
break;
case OP_31_XOP_STWBRX:
emulated = kvmppc_handle_store(run, vcpu,
kvmppc_get_gpr(vcpu, rs),
4, 0);
break;
case OP_31_XOP_LHBRX:
emulated = kvmppc_handle_load(run, vcpu, rt, 2, 0);
break;
case OP_31_XOP_STHBRX:
emulated = kvmppc_handle_store(run, vcpu,
kvmppc_get_gpr(vcpu, rs),
2, 0);
break;
default:
emulated = EMULATE_FAIL;
break;
}
break;
case OP_LWZ:
emulated = kvmppc_handle_load(run, vcpu, rt, 4, 1);
break;
case OP_LD:
rt = get_rt(inst);
emulated = kvmppc_handle_load(run, vcpu, rt, 8, 1);
break;
case OP_LWZU:
emulated = kvmppc_handle_load(run, vcpu, rt, 4, 1);
kvmppc_set_gpr(vcpu, ra, vcpu->arch.vaddr_accessed);
break;
case OP_LBZ:
emulated = kvmppc_handle_load(run, vcpu, rt, 1, 1);
break;
case OP_LBZU:
emulated = kvmppc_handle_load(run, vcpu, rt, 1, 1);
kvmppc_set_gpr(vcpu, ra, vcpu->arch.vaddr_accessed);
break;
case OP_STW:
emulated = kvmppc_handle_store(run, vcpu,
kvmppc_get_gpr(vcpu, rs),
4, 1);
break;
case OP_STD:
rs = get_rs(inst);
emulated = kvmppc_handle_store(run, vcpu,
kvmppc_get_gpr(vcpu, rs),
8, 1);
break;
case OP_STWU:
emulated = kvmppc_handle_store(run, vcpu,
kvmppc_get_gpr(vcpu, rs),
4, 1);
kvmppc_set_gpr(vcpu, ra, vcpu->arch.vaddr_accessed);
break;
case OP_STB:
emulated = kvmppc_handle_store(run, vcpu,
kvmppc_get_gpr(vcpu, rs),
1, 1);
break;
case OP_STBU:
emulated = kvmppc_handle_store(run, vcpu,
kvmppc_get_gpr(vcpu, rs),
1, 1);
kvmppc_set_gpr(vcpu, ra, vcpu->arch.vaddr_accessed);
break;
case OP_LHZ:
emulated = kvmppc_handle_load(run, vcpu, rt, 2, 1);
break;
case OP_LHZU:
emulated = kvmppc_handle_load(run, vcpu, rt, 2, 1);
kvmppc_set_gpr(vcpu, ra, vcpu->arch.vaddr_accessed);
break;
case OP_LHA:
emulated = kvmppc_handle_loads(run, vcpu, rt, 2, 1);
break;
case OP_LHAU:
emulated = kvmppc_handle_loads(run, vcpu, rt, 2, 1);
kvmppc_set_gpr(vcpu, ra, vcpu->arch.vaddr_accessed);
break;
case OP_STH:
emulated = kvmppc_handle_store(run, vcpu,
kvmppc_get_gpr(vcpu, rs),
2, 1);
break;
case OP_STHU:
emulated = kvmppc_handle_store(run, vcpu,
kvmppc_get_gpr(vcpu, rs),
2, 1);
kvmppc_set_gpr(vcpu, ra, vcpu->arch.vaddr_accessed);
break;
default:
emulated = EMULATE_FAIL;
break;
}
if (emulated == EMULATE_FAIL) {
advance = 0;
kvmppc_core_queue_program(vcpu, 0);
}
trace_kvm_ppc_instr(inst, kvmppc_get_pc(vcpu), emulated);
if (advance)
kvmppc_set_pc(vcpu, kvmppc_get_pc(vcpu) + 4);
return emulated;
}
