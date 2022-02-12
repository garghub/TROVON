static int microMIPS32_to_MIPS32(union mips_instruction *insn_ptr)
{
union mips_instruction insn = *insn_ptr;
union mips_instruction mips32_insn = insn;
int func, fmt, op;
switch (insn.mm_i_format.opcode) {
case mm_ldc132_op:
mips32_insn.mm_i_format.opcode = ldc1_op;
mips32_insn.mm_i_format.rt = insn.mm_i_format.rs;
mips32_insn.mm_i_format.rs = insn.mm_i_format.rt;
break;
case mm_lwc132_op:
mips32_insn.mm_i_format.opcode = lwc1_op;
mips32_insn.mm_i_format.rt = insn.mm_i_format.rs;
mips32_insn.mm_i_format.rs = insn.mm_i_format.rt;
break;
case mm_sdc132_op:
mips32_insn.mm_i_format.opcode = sdc1_op;
mips32_insn.mm_i_format.rt = insn.mm_i_format.rs;
mips32_insn.mm_i_format.rs = insn.mm_i_format.rt;
break;
case mm_swc132_op:
mips32_insn.mm_i_format.opcode = swc1_op;
mips32_insn.mm_i_format.rt = insn.mm_i_format.rs;
mips32_insn.mm_i_format.rs = insn.mm_i_format.rt;
break;
case mm_pool32i_op:
if ((insn.mm_i_format.rt == mm_bc1f_op) ||
(insn.mm_i_format.rt == mm_bc1t_op)) {
mips32_insn.fb_format.opcode = cop1_op;
mips32_insn.fb_format.bc = bc_op;
mips32_insn.fb_format.flag =
(insn.mm_i_format.rt == mm_bc1t_op) ? 1 : 0;
} else
return SIGILL;
break;
case mm_pool32f_op:
switch (insn.mm_fp0_format.func) {
case mm_32f_01_op:
case mm_32f_11_op:
case mm_32f_02_op:
case mm_32f_12_op:
case mm_32f_41_op:
case mm_32f_51_op:
case mm_32f_42_op:
case mm_32f_52_op:
op = insn.mm_fp0_format.func;
if (op == mm_32f_01_op)
func = madd_s_op;
else if (op == mm_32f_11_op)
func = madd_d_op;
else if (op == mm_32f_02_op)
func = nmadd_s_op;
else if (op == mm_32f_12_op)
func = nmadd_d_op;
else if (op == mm_32f_41_op)
func = msub_s_op;
else if (op == mm_32f_51_op)
func = msub_d_op;
else if (op == mm_32f_42_op)
func = nmsub_s_op;
else
func = nmsub_d_op;
mips32_insn.fp6_format.opcode = cop1x_op;
mips32_insn.fp6_format.fr = insn.mm_fp6_format.fr;
mips32_insn.fp6_format.ft = insn.mm_fp6_format.ft;
mips32_insn.fp6_format.fs = insn.mm_fp6_format.fs;
mips32_insn.fp6_format.fd = insn.mm_fp6_format.fd;
mips32_insn.fp6_format.func = func;
break;
case mm_32f_10_op:
func = -1;
op = insn.mm_fp5_format.op & 0x7;
if (op == mm_ldxc1_op)
func = ldxc1_op;
else if (op == mm_sdxc1_op)
func = sdxc1_op;
else if (op == mm_lwxc1_op)
func = lwxc1_op;
else if (op == mm_swxc1_op)
func = swxc1_op;
if (func != -1) {
mips32_insn.r_format.opcode = cop1x_op;
mips32_insn.r_format.rs =
insn.mm_fp5_format.base;
mips32_insn.r_format.rt =
insn.mm_fp5_format.index;
mips32_insn.r_format.rd = 0;
mips32_insn.r_format.re = insn.mm_fp5_format.fd;
mips32_insn.r_format.func = func;
} else
return SIGILL;
break;
case mm_32f_40_op:
op = -1;
if (insn.mm_fp2_format.op == mm_fmovt_op)
op = 1;
else if (insn.mm_fp2_format.op == mm_fmovf_op)
op = 0;
if (op != -1) {
mips32_insn.fp0_format.opcode = cop1_op;
mips32_insn.fp0_format.fmt =
sdps_format[insn.mm_fp2_format.fmt];
mips32_insn.fp0_format.ft =
(insn.mm_fp2_format.cc<<2) + op;
mips32_insn.fp0_format.fs =
insn.mm_fp2_format.fs;
mips32_insn.fp0_format.fd =
insn.mm_fp2_format.fd;
mips32_insn.fp0_format.func = fmovc_op;
} else
return SIGILL;
break;
case mm_32f_60_op:
func = -1;
if (insn.mm_fp0_format.op == mm_fadd_op)
func = fadd_op;
else if (insn.mm_fp0_format.op == mm_fsub_op)
func = fsub_op;
else if (insn.mm_fp0_format.op == mm_fmul_op)
func = fmul_op;
else if (insn.mm_fp0_format.op == mm_fdiv_op)
func = fdiv_op;
if (func != -1) {
mips32_insn.fp0_format.opcode = cop1_op;
mips32_insn.fp0_format.fmt =
sdps_format[insn.mm_fp0_format.fmt];
mips32_insn.fp0_format.ft =
insn.mm_fp0_format.ft;
mips32_insn.fp0_format.fs =
insn.mm_fp0_format.fs;
mips32_insn.fp0_format.fd =
insn.mm_fp0_format.fd;
mips32_insn.fp0_format.func = func;
} else
return SIGILL;
break;
case mm_32f_70_op:
func = -1;
if (insn.mm_fp0_format.op == mm_fmovn_op)
func = fmovn_op;
else if (insn.mm_fp0_format.op == mm_fmovz_op)
func = fmovz_op;
if (func != -1) {
mips32_insn.fp0_format.opcode = cop1_op;
mips32_insn.fp0_format.fmt =
sdps_format[insn.mm_fp0_format.fmt];
mips32_insn.fp0_format.ft =
insn.mm_fp0_format.ft;
mips32_insn.fp0_format.fs =
insn.mm_fp0_format.fs;
mips32_insn.fp0_format.fd =
insn.mm_fp0_format.fd;
mips32_insn.fp0_format.func = func;
} else
return SIGILL;
break;
case mm_32f_73_op:
switch (insn.mm_fp1_format.op) {
case mm_movf0_op:
case mm_movf1_op:
case mm_movt0_op:
case mm_movt1_op:
if ((insn.mm_fp1_format.op & 0x7f) ==
mm_movf0_op)
op = 0;
else
op = 1;
mips32_insn.r_format.opcode = spec_op;
mips32_insn.r_format.rs = insn.mm_fp4_format.fs;
mips32_insn.r_format.rt =
(insn.mm_fp4_format.cc << 2) + op;
mips32_insn.r_format.rd = insn.mm_fp4_format.rt;
mips32_insn.r_format.re = 0;
mips32_insn.r_format.func = movc_op;
break;
case mm_fcvtd0_op:
case mm_fcvtd1_op:
case mm_fcvts0_op:
case mm_fcvts1_op:
if ((insn.mm_fp1_format.op & 0x7f) ==
mm_fcvtd0_op) {
func = fcvtd_op;
fmt = swl_format[insn.mm_fp3_format.fmt];
} else {
func = fcvts_op;
fmt = dwl_format[insn.mm_fp3_format.fmt];
}
mips32_insn.fp0_format.opcode = cop1_op;
mips32_insn.fp0_format.fmt = fmt;
mips32_insn.fp0_format.ft = 0;
mips32_insn.fp0_format.fs =
insn.mm_fp3_format.fs;
mips32_insn.fp0_format.fd =
insn.mm_fp3_format.rt;
mips32_insn.fp0_format.func = func;
break;
case mm_fmov0_op:
case mm_fmov1_op:
case mm_fabs0_op:
case mm_fabs1_op:
case mm_fneg0_op:
case mm_fneg1_op:
if ((insn.mm_fp1_format.op & 0x7f) ==
mm_fmov0_op)
func = fmov_op;
else if ((insn.mm_fp1_format.op & 0x7f) ==
mm_fabs0_op)
func = fabs_op;
else
func = fneg_op;
mips32_insn.fp0_format.opcode = cop1_op;
mips32_insn.fp0_format.fmt =
sdps_format[insn.mm_fp3_format.fmt];
mips32_insn.fp0_format.ft = 0;
mips32_insn.fp0_format.fs =
insn.mm_fp3_format.fs;
mips32_insn.fp0_format.fd =
insn.mm_fp3_format.rt;
mips32_insn.fp0_format.func = func;
break;
case mm_ffloorl_op:
case mm_ffloorw_op:
case mm_fceill_op:
case mm_fceilw_op:
case mm_ftruncl_op:
case mm_ftruncw_op:
case mm_froundl_op:
case mm_froundw_op:
case mm_fcvtl_op:
case mm_fcvtw_op:
if (insn.mm_fp1_format.op == mm_ffloorl_op)
func = ffloorl_op;
else if (insn.mm_fp1_format.op == mm_ffloorw_op)
func = ffloor_op;
else if (insn.mm_fp1_format.op == mm_fceill_op)
func = fceill_op;
else if (insn.mm_fp1_format.op == mm_fceilw_op)
func = fceil_op;
else if (insn.mm_fp1_format.op == mm_ftruncl_op)
func = ftruncl_op;
else if (insn.mm_fp1_format.op == mm_ftruncw_op)
func = ftrunc_op;
else if (insn.mm_fp1_format.op == mm_froundl_op)
func = froundl_op;
else if (insn.mm_fp1_format.op == mm_froundw_op)
func = fround_op;
else if (insn.mm_fp1_format.op == mm_fcvtl_op)
func = fcvtl_op;
else
func = fcvtw_op;
mips32_insn.fp0_format.opcode = cop1_op;
mips32_insn.fp0_format.fmt =
sd_format[insn.mm_fp1_format.fmt];
mips32_insn.fp0_format.ft = 0;
mips32_insn.fp0_format.fs =
insn.mm_fp1_format.fs;
mips32_insn.fp0_format.fd =
insn.mm_fp1_format.rt;
mips32_insn.fp0_format.func = func;
break;
case mm_frsqrt_op:
case mm_fsqrt_op:
case mm_frecip_op:
if (insn.mm_fp1_format.op == mm_frsqrt_op)
func = frsqrt_op;
else if (insn.mm_fp1_format.op == mm_fsqrt_op)
func = fsqrt_op;
else
func = frecip_op;
mips32_insn.fp0_format.opcode = cop1_op;
mips32_insn.fp0_format.fmt =
sdps_format[insn.mm_fp1_format.fmt];
mips32_insn.fp0_format.ft = 0;
mips32_insn.fp0_format.fs =
insn.mm_fp1_format.fs;
mips32_insn.fp0_format.fd =
insn.mm_fp1_format.rt;
mips32_insn.fp0_format.func = func;
break;
case mm_mfc1_op:
case mm_mtc1_op:
case mm_cfc1_op:
case mm_ctc1_op:
if (insn.mm_fp1_format.op == mm_mfc1_op)
op = mfc_op;
else if (insn.mm_fp1_format.op == mm_mtc1_op)
op = mtc_op;
else if (insn.mm_fp1_format.op == mm_cfc1_op)
op = cfc_op;
else
op = ctc_op;
mips32_insn.fp1_format.opcode = cop1_op;
mips32_insn.fp1_format.op = op;
mips32_insn.fp1_format.rt =
insn.mm_fp1_format.rt;
mips32_insn.fp1_format.fs =
insn.mm_fp1_format.fs;
mips32_insn.fp1_format.fd = 0;
mips32_insn.fp1_format.func = 0;
break;
default:
return SIGILL;
break;
}
break;
case mm_32f_74_op:
mips32_insn.fp0_format.opcode = cop1_op;
mips32_insn.fp0_format.fmt =
sdps_format[insn.mm_fp4_format.fmt];
mips32_insn.fp0_format.ft = insn.mm_fp4_format.rt;
mips32_insn.fp0_format.fs = insn.mm_fp4_format.fs;
mips32_insn.fp0_format.fd = insn.mm_fp4_format.cc << 2;
mips32_insn.fp0_format.func =
insn.mm_fp4_format.cond | MM_MIPS32_COND_FC;
break;
default:
return SIGILL;
break;
}
break;
default:
return SIGILL;
break;
}
*insn_ptr = mips32_insn;
return 0;
}
int mm_isBranchInstr(struct pt_regs *regs, struct mm_decoded_insn dec_insn,
unsigned long *contpc)
{
union mips_instruction insn = (union mips_instruction)dec_insn.insn;
int bc_false = 0;
unsigned int fcr31;
unsigned int bit;
switch (insn.mm_i_format.opcode) {
case mm_pool32a_op:
if ((insn.mm_i_format.simmediate & MM_POOL32A_MINOR_MASK) ==
mm_pool32axf_op) {
switch (insn.mm_i_format.simmediate >>
MM_POOL32A_MINOR_SHIFT) {
case mm_jalr_op:
case mm_jalrhb_op:
case mm_jalrs_op:
case mm_jalrshb_op:
if (insn.mm_i_format.rt != 0)
regs->regs[insn.mm_i_format.rt] =
regs->cp0_epc +
dec_insn.pc_inc +
dec_insn.next_pc_inc;
*contpc = regs->regs[insn.mm_i_format.rs];
return 1;
break;
}
}
break;
case mm_pool32i_op:
switch (insn.mm_i_format.rt) {
case mm_bltzals_op:
case mm_bltzal_op:
regs->regs[31] = regs->cp0_epc +
dec_insn.pc_inc +
dec_insn.next_pc_inc;
case mm_bltz_op:
if ((long)regs->regs[insn.mm_i_format.rs] < 0)
*contpc = regs->cp0_epc +
dec_insn.pc_inc +
(insn.mm_i_format.simmediate << 1);
else
*contpc = regs->cp0_epc +
dec_insn.pc_inc +
dec_insn.next_pc_inc;
return 1;
break;
case mm_bgezals_op:
case mm_bgezal_op:
regs->regs[31] = regs->cp0_epc +
dec_insn.pc_inc +
dec_insn.next_pc_inc;
case mm_bgez_op:
if ((long)regs->regs[insn.mm_i_format.rs] >= 0)
*contpc = regs->cp0_epc +
dec_insn.pc_inc +
(insn.mm_i_format.simmediate << 1);
else
*contpc = regs->cp0_epc +
dec_insn.pc_inc +
dec_insn.next_pc_inc;
return 1;
break;
case mm_blez_op:
if ((long)regs->regs[insn.mm_i_format.rs] <= 0)
*contpc = regs->cp0_epc +
dec_insn.pc_inc +
(insn.mm_i_format.simmediate << 1);
else
*contpc = regs->cp0_epc +
dec_insn.pc_inc +
dec_insn.next_pc_inc;
return 1;
break;
case mm_bgtz_op:
if ((long)regs->regs[insn.mm_i_format.rs] <= 0)
*contpc = regs->cp0_epc +
dec_insn.pc_inc +
(insn.mm_i_format.simmediate << 1);
else
*contpc = regs->cp0_epc +
dec_insn.pc_inc +
dec_insn.next_pc_inc;
return 1;
break;
case mm_bc2f_op:
case mm_bc1f_op:
bc_false = 1;
case mm_bc2t_op:
case mm_bc1t_op:
preempt_disable();
if (is_fpu_owner())
asm volatile("cfc1\t%0,$31" : "=r" (fcr31));
else
fcr31 = current->thread.fpu.fcr31;
preempt_enable();
if (bc_false)
fcr31 = ~fcr31;
bit = (insn.mm_i_format.rs >> 2);
bit += (bit != 0);
bit += 23;
if (fcr31 & (1 << bit))
*contpc = regs->cp0_epc +
dec_insn.pc_inc +
(insn.mm_i_format.simmediate << 1);
else
*contpc = regs->cp0_epc +
dec_insn.pc_inc + dec_insn.next_pc_inc;
return 1;
break;
}
break;
case mm_pool16c_op:
switch (insn.mm_i_format.rt) {
case mm_jalr16_op:
case mm_jalrs16_op:
regs->regs[31] = regs->cp0_epc +
dec_insn.pc_inc + dec_insn.next_pc_inc;
case mm_jr16_op:
*contpc = regs->regs[insn.mm_i_format.rs];
return 1;
break;
}
break;
case mm_beqz16_op:
if ((long)regs->regs[reg16to32map[insn.mm_b1_format.rs]] == 0)
*contpc = regs->cp0_epc +
dec_insn.pc_inc +
(insn.mm_b1_format.simmediate << 1);
else
*contpc = regs->cp0_epc +
dec_insn.pc_inc + dec_insn.next_pc_inc;
return 1;
break;
case mm_bnez16_op:
if ((long)regs->regs[reg16to32map[insn.mm_b1_format.rs]] != 0)
*contpc = regs->cp0_epc +
dec_insn.pc_inc +
(insn.mm_b1_format.simmediate << 1);
else
*contpc = regs->cp0_epc +
dec_insn.pc_inc + dec_insn.next_pc_inc;
return 1;
break;
case mm_b16_op:
*contpc = regs->cp0_epc + dec_insn.pc_inc +
(insn.mm_b0_format.simmediate << 1);
return 1;
break;
case mm_beq32_op:
if (regs->regs[insn.mm_i_format.rs] ==
regs->regs[insn.mm_i_format.rt])
*contpc = regs->cp0_epc +
dec_insn.pc_inc +
(insn.mm_i_format.simmediate << 1);
else
*contpc = regs->cp0_epc +
dec_insn.pc_inc +
dec_insn.next_pc_inc;
return 1;
break;
case mm_bne32_op:
if (regs->regs[insn.mm_i_format.rs] !=
regs->regs[insn.mm_i_format.rt])
*contpc = regs->cp0_epc +
dec_insn.pc_inc +
(insn.mm_i_format.simmediate << 1);
else
*contpc = regs->cp0_epc +
dec_insn.pc_inc + dec_insn.next_pc_inc;
return 1;
break;
case mm_jalx32_op:
regs->regs[31] = regs->cp0_epc +
dec_insn.pc_inc + dec_insn.next_pc_inc;
*contpc = regs->cp0_epc + dec_insn.pc_inc;
*contpc >>= 28;
*contpc <<= 28;
*contpc |= (insn.j_format.target << 2);
return 1;
break;
case mm_jals32_op:
case mm_jal32_op:
regs->regs[31] = regs->cp0_epc +
dec_insn.pc_inc + dec_insn.next_pc_inc;
case mm_j32_op:
*contpc = regs->cp0_epc + dec_insn.pc_inc;
*contpc >>= 27;
*contpc <<= 27;
*contpc |= (insn.j_format.target << 1);
set_isa16_mode(*contpc);
return 1;
break;
}
return 0;
}
static int isBranchInstr(struct pt_regs *regs, struct mm_decoded_insn dec_insn,
unsigned long *contpc)
{
union mips_instruction insn = (union mips_instruction)dec_insn.insn;
unsigned int fcr31;
unsigned int bit = 0;
switch (insn.i_format.opcode) {
case spec_op:
switch (insn.r_format.func) {
case jalr_op:
regs->regs[insn.r_format.rd] =
regs->cp0_epc + dec_insn.pc_inc +
dec_insn.next_pc_inc;
case jr_op:
*contpc = regs->regs[insn.r_format.rs];
return 1;
break;
}
break;
case bcond_op:
switch (insn.i_format.rt) {
case bltzal_op:
case bltzall_op:
regs->regs[31] = regs->cp0_epc +
dec_insn.pc_inc +
dec_insn.next_pc_inc;
case bltz_op:
case bltzl_op:
if ((long)regs->regs[insn.i_format.rs] < 0)
*contpc = regs->cp0_epc +
dec_insn.pc_inc +
(insn.i_format.simmediate << 2);
else
*contpc = regs->cp0_epc +
dec_insn.pc_inc +
dec_insn.next_pc_inc;
return 1;
break;
case bgezal_op:
case bgezall_op:
regs->regs[31] = regs->cp0_epc +
dec_insn.pc_inc +
dec_insn.next_pc_inc;
case bgez_op:
case bgezl_op:
if ((long)regs->regs[insn.i_format.rs] >= 0)
*contpc = regs->cp0_epc +
dec_insn.pc_inc +
(insn.i_format.simmediate << 2);
else
*contpc = regs->cp0_epc +
dec_insn.pc_inc +
dec_insn.next_pc_inc;
return 1;
break;
}
break;
case jalx_op:
set_isa16_mode(bit);
case jal_op:
regs->regs[31] = regs->cp0_epc +
dec_insn.pc_inc +
dec_insn.next_pc_inc;
case j_op:
*contpc = regs->cp0_epc + dec_insn.pc_inc;
*contpc >>= 28;
*contpc <<= 28;
*contpc |= (insn.j_format.target << 2);
*contpc ^= bit;
return 1;
break;
case beq_op:
case beql_op:
if (regs->regs[insn.i_format.rs] ==
regs->regs[insn.i_format.rt])
*contpc = regs->cp0_epc +
dec_insn.pc_inc +
(insn.i_format.simmediate << 2);
else
*contpc = regs->cp0_epc +
dec_insn.pc_inc +
dec_insn.next_pc_inc;
return 1;
break;
case bne_op:
case bnel_op:
if (regs->regs[insn.i_format.rs] !=
regs->regs[insn.i_format.rt])
*contpc = regs->cp0_epc +
dec_insn.pc_inc +
(insn.i_format.simmediate << 2);
else
*contpc = regs->cp0_epc +
dec_insn.pc_inc +
dec_insn.next_pc_inc;
return 1;
break;
case blez_op:
case blezl_op:
if ((long)regs->regs[insn.i_format.rs] <= 0)
*contpc = regs->cp0_epc +
dec_insn.pc_inc +
(insn.i_format.simmediate << 2);
else
*contpc = regs->cp0_epc +
dec_insn.pc_inc +
dec_insn.next_pc_inc;
return 1;
break;
case bgtz_op:
case bgtzl_op:
if ((long)regs->regs[insn.i_format.rs] > 0)
*contpc = regs->cp0_epc +
dec_insn.pc_inc +
(insn.i_format.simmediate << 2);
else
*contpc = regs->cp0_epc +
dec_insn.pc_inc +
dec_insn.next_pc_inc;
return 1;
break;
case cop0_op:
case cop1_op:
case cop2_op:
case cop1x_op:
if (insn.i_format.rs == bc_op) {
preempt_disable();
if (is_fpu_owner())
asm volatile("cfc1\t%0,$31" : "=r" (fcr31));
else
fcr31 = current->thread.fpu.fcr31;
preempt_enable();
bit = (insn.i_format.rt >> 2);
bit += (bit != 0);
bit += 23;
switch (insn.i_format.rt & 3) {
case 0:
case 2:
if (~fcr31 & (1 << bit))
*contpc = regs->cp0_epc +
dec_insn.pc_inc +
(insn.i_format.simmediate << 2);
else
*contpc = regs->cp0_epc +
dec_insn.pc_inc +
dec_insn.next_pc_inc;
return 1;
break;
case 1:
case 3:
if (fcr31 & (1 << bit))
*contpc = regs->cp0_epc +
dec_insn.pc_inc +
(insn.i_format.simmediate << 2);
else
*contpc = regs->cp0_epc +
dec_insn.pc_inc +
dec_insn.next_pc_inc;
return 1;
break;
}
}
break;
}
return 0;
}
static inline int cop1_64bit(struct pt_regs *xcp)
{
#if defined(CONFIG_64BIT) && !defined(CONFIG_MIPS32_O32)
return 1;
#elif defined(CONFIG_64BIT) && defined(CONFIG_MIPS32_O32)
return !test_thread_flag(TIF_32BIT_REGS);
#else
return 0;
#endif
}
static int cop1Emulate(struct pt_regs *xcp, struct mips_fpu_struct *ctx,
struct mm_decoded_insn dec_insn, void *__user *fault_addr)
{
mips_instruction ir;
unsigned long contpc = xcp->cp0_epc + dec_insn.pc_inc;
unsigned int cond;
int pc_inc;
if (xcp->cp0_cause & CAUSEF_BD) {
if (dec_insn.micro_mips_mode) {
if (!mm_isBranchInstr(xcp, dec_insn, &contpc))
xcp->cp0_cause &= ~CAUSEF_BD;
} else {
if (!isBranchInstr(xcp, dec_insn, &contpc))
xcp->cp0_cause &= ~CAUSEF_BD;
}
}
if (xcp->cp0_cause & CAUSEF_BD) {
ir = dec_insn.next_insn;
pc_inc = dec_insn.next_pc_inc;
} else {
ir = dec_insn.insn;
pc_inc = dec_insn.pc_inc;
}
if (dec_insn.micro_mips_mode) {
if ((pc_inc == 2) ||
(microMIPS32_to_MIPS32((union mips_instruction *)&ir)
== SIGILL))
return SIGILL;
}
emul:
perf_sw_event(PERF_COUNT_SW_EMULATION_FAULTS, 1, xcp, 0);
MIPS_FPU_EMU_INC_STATS(emulated);
switch (MIPSInst_OPCODE(ir)) {
case ldc1_op:{
u64 __user *va = (u64 __user *) (xcp->regs[MIPSInst_RS(ir)] +
MIPSInst_SIMM(ir));
u64 val;
MIPS_FPU_EMU_INC_STATS(loads);
if (!access_ok(VERIFY_READ, va, sizeof(u64))) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGBUS;
}
if (__get_user(val, va)) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGSEGV;
}
DITOREG(val, MIPSInst_RT(ir));
break;
}
case sdc1_op:{
u64 __user *va = (u64 __user *) (xcp->regs[MIPSInst_RS(ir)] +
MIPSInst_SIMM(ir));
u64 val;
MIPS_FPU_EMU_INC_STATS(stores);
DIFROMREG(val, MIPSInst_RT(ir));
if (!access_ok(VERIFY_WRITE, va, sizeof(u64))) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGBUS;
}
if (__put_user(val, va)) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGSEGV;
}
break;
}
case lwc1_op:{
u32 __user *va = (u32 __user *) (xcp->regs[MIPSInst_RS(ir)] +
MIPSInst_SIMM(ir));
u32 val;
MIPS_FPU_EMU_INC_STATS(loads);
if (!access_ok(VERIFY_READ, va, sizeof(u32))) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGBUS;
}
if (__get_user(val, va)) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGSEGV;
}
SITOREG(val, MIPSInst_RT(ir));
break;
}
case swc1_op:{
u32 __user *va = (u32 __user *) (xcp->regs[MIPSInst_RS(ir)] +
MIPSInst_SIMM(ir));
u32 val;
MIPS_FPU_EMU_INC_STATS(stores);
SIFROMREG(val, MIPSInst_RT(ir));
if (!access_ok(VERIFY_WRITE, va, sizeof(u32))) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGBUS;
}
if (__put_user(val, va)) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGSEGV;
}
break;
}
case cop1_op:
switch (MIPSInst_RS(ir)) {
#if defined(__mips64)
case dmfc_op:
if (MIPSInst_RT(ir) != 0) {
DIFROMREG(xcp->regs[MIPSInst_RT(ir)],
MIPSInst_RD(ir));
}
break;
case dmtc_op:
DITOREG(xcp->regs[MIPSInst_RT(ir)], MIPSInst_RD(ir));
break;
#endif
case mfc_op:
if (MIPSInst_RT(ir) != 0) {
SIFROMREG(xcp->regs[MIPSInst_RT(ir)],
MIPSInst_RD(ir));
}
break;
case mtc_op:
SITOREG(xcp->regs[MIPSInst_RT(ir)], MIPSInst_RD(ir));
break;
case cfc_op:{
u32 value;
if (MIPSInst_RD(ir) == FPCREG_CSR) {
value = ctx->fcr31;
value = (value & ~FPU_CSR_RM) |
mips_rm[modeindex(value)];
#ifdef CSRTRACE
printk("%p gpr[%d]<-csr=%08x\n",
(void *) (xcp->cp0_epc),
MIPSInst_RT(ir), value);
#endif
}
else if (MIPSInst_RD(ir) == FPCREG_RID)
value = 0;
else
value = 0;
if (MIPSInst_RT(ir))
xcp->regs[MIPSInst_RT(ir)] = value;
break;
}
case ctc_op:{
u32 value;
if (MIPSInst_RT(ir) == 0)
value = 0;
else
value = xcp->regs[MIPSInst_RT(ir)];
if (MIPSInst_RD(ir) == FPCREG_CSR) {
#ifdef CSRTRACE
printk("%p gpr[%d]->csr=%08x\n",
(void *) (xcp->cp0_epc),
MIPSInst_RT(ir), value);
#endif
ctx->fcr31 = (value &
~(FPU_CSR_RSVD | FPU_CSR_RM)) |
ieee_rm[modeindex(value)];
}
if ((ctx->fcr31 >> 5) & ctx->fcr31 & FPU_CSR_ALL_E) {
return SIGFPE;
}
break;
}
case bc_op:{
int likely = 0;
if (xcp->cp0_cause & CAUSEF_BD)
return SIGILL;
#if __mips >= 4
cond = ctx->fcr31 & fpucondbit[MIPSInst_RT(ir) >> 2];
#else
cond = ctx->fcr31 & FPU_CSR_COND;
#endif
switch (MIPSInst_RT(ir) & 3) {
case bcfl_op:
likely = 1;
case bcf_op:
cond = !cond;
break;
case bctl_op:
likely = 1;
case bct_op:
break;
default:
return SIGILL;
}
xcp->cp0_cause |= CAUSEF_BD;
if (cond) {
xcp->cp0_epc += dec_insn.pc_inc;
contpc = MIPSInst_SIMM(ir);
ir = dec_insn.next_insn;
if (dec_insn.micro_mips_mode) {
contpc = (xcp->cp0_epc + (contpc << 1));
if ((dec_insn.next_pc_inc == 2) ||
(microMIPS32_to_MIPS32((union mips_instruction *)&ir) == SIGILL)) {
if (dec_insn.next_pc_inc == 2)
ir = (ir & (~0xffff)) | MM_NOP16;
return mips_dsemul(xcp, ir, contpc);
}
} else
contpc = (xcp->cp0_epc + (contpc << 2));
switch (MIPSInst_OPCODE(ir)) {
case lwc1_op:
case swc1_op:
#if (__mips >= 2 || defined(__mips64))
case ldc1_op:
case sdc1_op:
#endif
case cop1_op:
#if __mips >= 4 && __mips != 32
case cop1x_op:
#endif
goto emul;
#if __mips >= 4
case spec_op:
if (MIPSInst_FUNC(ir) == movc_op)
goto emul;
break;
#endif
}
return mips_dsemul(xcp, ir, contpc);
}
else {
if (likely) {
xcp->cp0_epc += dec_insn.pc_inc;
contpc += dec_insn.pc_inc;
}
}
break;
}
default:
if (!(MIPSInst_RS(ir) & 0x10))
return SIGILL;
{
int sig;
if ((sig = fpu_emu(xcp, ctx, ir)))
return sig;
}
}
break;
#if __mips >= 4 && __mips != 32
case cop1x_op:{
int sig = fpux_emu(xcp, ctx, ir, fault_addr);
if (sig)
return sig;
break;
}
#endif
#if __mips >= 4
case spec_op:
if (MIPSInst_FUNC(ir) != movc_op)
return SIGILL;
cond = fpucondbit[MIPSInst_RT(ir) >> 2];
if (((ctx->fcr31 & cond) != 0) == ((MIPSInst_RT(ir) & 1) != 0))
xcp->regs[MIPSInst_RD(ir)] =
xcp->regs[MIPSInst_RS(ir)];
break;
#endif
default:
return SIGILL;
}
xcp->cp0_epc = contpc;
xcp->cp0_cause &= ~CAUSEF_BD;
return 0;
}
static ieee754dp fpemu_dp_recip(ieee754dp d)
{
return ieee754dp_div(ieee754dp_one(0), d);
}
static ieee754dp fpemu_dp_rsqrt(ieee754dp d)
{
return ieee754dp_div(ieee754dp_one(0), ieee754dp_sqrt(d));
}
static ieee754sp fpemu_sp_recip(ieee754sp s)
{
return ieee754sp_div(ieee754sp_one(0), s);
}
static ieee754sp fpemu_sp_rsqrt(ieee754sp s)
{
return ieee754sp_div(ieee754sp_one(0), ieee754sp_sqrt(s));
}
static int fpux_emu(struct pt_regs *xcp, struct mips_fpu_struct *ctx,
mips_instruction ir, void *__user *fault_addr)
{
unsigned rcsr = 0;
MIPS_FPU_EMU_INC_STATS(cp1xops);
switch (MIPSInst_FMA_FFMT(ir)) {
case s_fmt:{
ieee754sp(*handler) (ieee754sp, ieee754sp, ieee754sp);
ieee754sp fd, fr, fs, ft;
u32 __user *va;
u32 val;
switch (MIPSInst_FUNC(ir)) {
case lwxc1_op:
va = (void __user *) (xcp->regs[MIPSInst_FR(ir)] +
xcp->regs[MIPSInst_FT(ir)]);
MIPS_FPU_EMU_INC_STATS(loads);
if (!access_ok(VERIFY_READ, va, sizeof(u32))) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGBUS;
}
if (__get_user(val, va)) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGSEGV;
}
SITOREG(val, MIPSInst_FD(ir));
break;
case swxc1_op:
va = (void __user *) (xcp->regs[MIPSInst_FR(ir)] +
xcp->regs[MIPSInst_FT(ir)]);
MIPS_FPU_EMU_INC_STATS(stores);
SIFROMREG(val, MIPSInst_FS(ir));
if (!access_ok(VERIFY_WRITE, va, sizeof(u32))) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGBUS;
}
if (put_user(val, va)) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGSEGV;
}
break;
case madd_s_op:
handler = fpemu_sp_madd;
goto scoptop;
case msub_s_op:
handler = fpemu_sp_msub;
goto scoptop;
case nmadd_s_op:
handler = fpemu_sp_nmadd;
goto scoptop;
case nmsub_s_op:
handler = fpemu_sp_nmsub;
goto scoptop;
scoptop:
SPFROMREG(fr, MIPSInst_FR(ir));
SPFROMREG(fs, MIPSInst_FS(ir));
SPFROMREG(ft, MIPSInst_FT(ir));
fd = (*handler) (fr, fs, ft);
SPTOREG(fd, MIPSInst_FD(ir));
copcsr:
if (ieee754_cxtest(IEEE754_INEXACT))
rcsr |= FPU_CSR_INE_X | FPU_CSR_INE_S;
if (ieee754_cxtest(IEEE754_UNDERFLOW))
rcsr |= FPU_CSR_UDF_X | FPU_CSR_UDF_S;
if (ieee754_cxtest(IEEE754_OVERFLOW))
rcsr |= FPU_CSR_OVF_X | FPU_CSR_OVF_S;
if (ieee754_cxtest(IEEE754_INVALID_OPERATION))
rcsr |= FPU_CSR_INV_X | FPU_CSR_INV_S;
ctx->fcr31 = (ctx->fcr31 & ~FPU_CSR_ALL_X) | rcsr;
if ((ctx->fcr31 >> 5) & ctx->fcr31 & FPU_CSR_ALL_E) {
return SIGFPE;
}
break;
default:
return SIGILL;
}
break;
}
case d_fmt:{
ieee754dp(*handler) (ieee754dp, ieee754dp, ieee754dp);
ieee754dp fd, fr, fs, ft;
u64 __user *va;
u64 val;
switch (MIPSInst_FUNC(ir)) {
case ldxc1_op:
va = (void __user *) (xcp->regs[MIPSInst_FR(ir)] +
xcp->regs[MIPSInst_FT(ir)]);
MIPS_FPU_EMU_INC_STATS(loads);
if (!access_ok(VERIFY_READ, va, sizeof(u64))) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGBUS;
}
if (__get_user(val, va)) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGSEGV;
}
DITOREG(val, MIPSInst_FD(ir));
break;
case sdxc1_op:
va = (void __user *) (xcp->regs[MIPSInst_FR(ir)] +
xcp->regs[MIPSInst_FT(ir)]);
MIPS_FPU_EMU_INC_STATS(stores);
DIFROMREG(val, MIPSInst_FS(ir));
if (!access_ok(VERIFY_WRITE, va, sizeof(u64))) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGBUS;
}
if (__put_user(val, va)) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGSEGV;
}
break;
case madd_d_op:
handler = fpemu_dp_madd;
goto dcoptop;
case msub_d_op:
handler = fpemu_dp_msub;
goto dcoptop;
case nmadd_d_op:
handler = fpemu_dp_nmadd;
goto dcoptop;
case nmsub_d_op:
handler = fpemu_dp_nmsub;
goto dcoptop;
dcoptop:
DPFROMREG(fr, MIPSInst_FR(ir));
DPFROMREG(fs, MIPSInst_FS(ir));
DPFROMREG(ft, MIPSInst_FT(ir));
fd = (*handler) (fr, fs, ft);
DPTOREG(fd, MIPSInst_FD(ir));
goto copcsr;
default:
return SIGILL;
}
break;
}
case 0x7:
if (MIPSInst_FUNC(ir) != pfetch_op) {
return SIGILL;
}
break;
default:
return SIGILL;
}
return 0;
}
static int fpu_emu(struct pt_regs *xcp, struct mips_fpu_struct *ctx,
mips_instruction ir)
{
int rfmt;
unsigned rcsr = 0;
unsigned cond;
union {
ieee754dp d;
ieee754sp s;
int w;
#ifdef __mips64
s64 l;
#endif
} rv;
MIPS_FPU_EMU_INC_STATS(cp1ops);
switch (rfmt = (MIPSInst_FFMT(ir) & 0xf)) {
case s_fmt:{
union {
ieee754sp(*b) (ieee754sp, ieee754sp);
ieee754sp(*u) (ieee754sp);
} handler;
switch (MIPSInst_FUNC(ir)) {
case fadd_op:
handler.b = ieee754sp_add;
goto scopbop;
case fsub_op:
handler.b = ieee754sp_sub;
goto scopbop;
case fmul_op:
handler.b = ieee754sp_mul;
goto scopbop;
case fdiv_op:
handler.b = ieee754sp_div;
goto scopbop;
#if __mips >= 2 || defined(__mips64)
case fsqrt_op:
handler.u = ieee754sp_sqrt;
goto scopuop;
#endif
#if __mips >= 4 && __mips != 32
case frsqrt_op:
handler.u = fpemu_sp_rsqrt;
goto scopuop;
case frecip_op:
handler.u = fpemu_sp_recip;
goto scopuop;
#endif
#if __mips >= 4
case fmovc_op:
cond = fpucondbit[MIPSInst_FT(ir) >> 2];
if (((ctx->fcr31 & cond) != 0) !=
((MIPSInst_FT(ir) & 1) != 0))
return 0;
SPFROMREG(rv.s, MIPSInst_FS(ir));
break;
case fmovz_op:
if (xcp->regs[MIPSInst_FT(ir)] != 0)
return 0;
SPFROMREG(rv.s, MIPSInst_FS(ir));
break;
case fmovn_op:
if (xcp->regs[MIPSInst_FT(ir)] == 0)
return 0;
SPFROMREG(rv.s, MIPSInst_FS(ir));
break;
#endif
case fabs_op:
handler.u = ieee754sp_abs;
goto scopuop;
case fneg_op:
handler.u = ieee754sp_neg;
goto scopuop;
case fmov_op:
SPFROMREG(rv.s, MIPSInst_FS(ir));
goto copcsr;
scopbop:
{
ieee754sp fs, ft;
SPFROMREG(fs, MIPSInst_FS(ir));
SPFROMREG(ft, MIPSInst_FT(ir));
rv.s = (*handler.b) (fs, ft);
goto copcsr;
}
scopuop:
{
ieee754sp fs;
SPFROMREG(fs, MIPSInst_FS(ir));
rv.s = (*handler.u) (fs);
goto copcsr;
}
copcsr:
if (ieee754_cxtest(IEEE754_INEXACT))
rcsr |= FPU_CSR_INE_X | FPU_CSR_INE_S;
if (ieee754_cxtest(IEEE754_UNDERFLOW))
rcsr |= FPU_CSR_UDF_X | FPU_CSR_UDF_S;
if (ieee754_cxtest(IEEE754_OVERFLOW))
rcsr |= FPU_CSR_OVF_X | FPU_CSR_OVF_S;
if (ieee754_cxtest(IEEE754_ZERO_DIVIDE))
rcsr |= FPU_CSR_DIV_X | FPU_CSR_DIV_S;
if (ieee754_cxtest(IEEE754_INVALID_OPERATION))
rcsr |= FPU_CSR_INV_X | FPU_CSR_INV_S;
break;
case fcvts_op:
return SIGILL;
case fcvtd_op:{
ieee754sp fs;
SPFROMREG(fs, MIPSInst_FS(ir));
rv.d = ieee754dp_fsp(fs);
rfmt = d_fmt;
goto copcsr;
}
case fcvtw_op:{
ieee754sp fs;
SPFROMREG(fs, MIPSInst_FS(ir));
rv.w = ieee754sp_tint(fs);
rfmt = w_fmt;
goto copcsr;
}
#if __mips >= 2 || defined(__mips64)
case fround_op:
case ftrunc_op:
case fceil_op:
case ffloor_op:{
unsigned int oldrm = ieee754_csr.rm;
ieee754sp fs;
SPFROMREG(fs, MIPSInst_FS(ir));
ieee754_csr.rm = ieee_rm[modeindex(MIPSInst_FUNC(ir))];
rv.w = ieee754sp_tint(fs);
ieee754_csr.rm = oldrm;
rfmt = w_fmt;
goto copcsr;
}
#endif
#if defined(__mips64)
case fcvtl_op:{
ieee754sp fs;
SPFROMREG(fs, MIPSInst_FS(ir));
rv.l = ieee754sp_tlong(fs);
rfmt = l_fmt;
goto copcsr;
}
case froundl_op:
case ftruncl_op:
case fceill_op:
case ffloorl_op:{
unsigned int oldrm = ieee754_csr.rm;
ieee754sp fs;
SPFROMREG(fs, MIPSInst_FS(ir));
ieee754_csr.rm = ieee_rm[modeindex(MIPSInst_FUNC(ir))];
rv.l = ieee754sp_tlong(fs);
ieee754_csr.rm = oldrm;
rfmt = l_fmt;
goto copcsr;
}
#endif
default:
if (MIPSInst_FUNC(ir) >= fcmp_op) {
unsigned cmpop = MIPSInst_FUNC(ir) - fcmp_op;
ieee754sp fs, ft;
SPFROMREG(fs, MIPSInst_FS(ir));
SPFROMREG(ft, MIPSInst_FT(ir));
rv.w = ieee754sp_cmp(fs, ft,
cmptab[cmpop & 0x7], cmpop & 0x8);
rfmt = -1;
if ((cmpop & 0x8) && ieee754_cxtest
(IEEE754_INVALID_OPERATION))
rcsr = FPU_CSR_INV_X | FPU_CSR_INV_S;
else
goto copcsr;
}
else {
return SIGILL;
}
break;
}
break;
}
case d_fmt:{
union {
ieee754dp(*b) (ieee754dp, ieee754dp);
ieee754dp(*u) (ieee754dp);
} handler;
switch (MIPSInst_FUNC(ir)) {
case fadd_op:
handler.b = ieee754dp_add;
goto dcopbop;
case fsub_op:
handler.b = ieee754dp_sub;
goto dcopbop;
case fmul_op:
handler.b = ieee754dp_mul;
goto dcopbop;
case fdiv_op:
handler.b = ieee754dp_div;
goto dcopbop;
#if __mips >= 2 || defined(__mips64)
case fsqrt_op:
handler.u = ieee754dp_sqrt;
goto dcopuop;
#endif
#if __mips >= 4 && __mips != 32
case frsqrt_op:
handler.u = fpemu_dp_rsqrt;
goto dcopuop;
case frecip_op:
handler.u = fpemu_dp_recip;
goto dcopuop;
#endif
#if __mips >= 4
case fmovc_op:
cond = fpucondbit[MIPSInst_FT(ir) >> 2];
if (((ctx->fcr31 & cond) != 0) !=
((MIPSInst_FT(ir) & 1) != 0))
return 0;
DPFROMREG(rv.d, MIPSInst_FS(ir));
break;
case fmovz_op:
if (xcp->regs[MIPSInst_FT(ir)] != 0)
return 0;
DPFROMREG(rv.d, MIPSInst_FS(ir));
break;
case fmovn_op:
if (xcp->regs[MIPSInst_FT(ir)] == 0)
return 0;
DPFROMREG(rv.d, MIPSInst_FS(ir));
break;
#endif
case fabs_op:
handler.u = ieee754dp_abs;
goto dcopuop;
case fneg_op:
handler.u = ieee754dp_neg;
goto dcopuop;
case fmov_op:
DPFROMREG(rv.d, MIPSInst_FS(ir));
goto copcsr;
dcopbop:{
ieee754dp fs, ft;
DPFROMREG(fs, MIPSInst_FS(ir));
DPFROMREG(ft, MIPSInst_FT(ir));
rv.d = (*handler.b) (fs, ft);
goto copcsr;
}
dcopuop:{
ieee754dp fs;
DPFROMREG(fs, MIPSInst_FS(ir));
rv.d = (*handler.u) (fs);
goto copcsr;
}
case fcvts_op:{
ieee754dp fs;
DPFROMREG(fs, MIPSInst_FS(ir));
rv.s = ieee754sp_fdp(fs);
rfmt = s_fmt;
goto copcsr;
}
case fcvtd_op:
return SIGILL;
case fcvtw_op:{
ieee754dp fs;
DPFROMREG(fs, MIPSInst_FS(ir));
rv.w = ieee754dp_tint(fs);
rfmt = w_fmt;
goto copcsr;
}
#if __mips >= 2 || defined(__mips64)
case fround_op:
case ftrunc_op:
case fceil_op:
case ffloor_op:{
unsigned int oldrm = ieee754_csr.rm;
ieee754dp fs;
DPFROMREG(fs, MIPSInst_FS(ir));
ieee754_csr.rm = ieee_rm[modeindex(MIPSInst_FUNC(ir))];
rv.w = ieee754dp_tint(fs);
ieee754_csr.rm = oldrm;
rfmt = w_fmt;
goto copcsr;
}
#endif
#if defined(__mips64)
case fcvtl_op:{
ieee754dp fs;
DPFROMREG(fs, MIPSInst_FS(ir));
rv.l = ieee754dp_tlong(fs);
rfmt = l_fmt;
goto copcsr;
}
case froundl_op:
case ftruncl_op:
case fceill_op:
case ffloorl_op:{
unsigned int oldrm = ieee754_csr.rm;
ieee754dp fs;
DPFROMREG(fs, MIPSInst_FS(ir));
ieee754_csr.rm = ieee_rm[modeindex(MIPSInst_FUNC(ir))];
rv.l = ieee754dp_tlong(fs);
ieee754_csr.rm = oldrm;
rfmt = l_fmt;
goto copcsr;
}
#endif
default:
if (MIPSInst_FUNC(ir) >= fcmp_op) {
unsigned cmpop = MIPSInst_FUNC(ir) - fcmp_op;
ieee754dp fs, ft;
DPFROMREG(fs, MIPSInst_FS(ir));
DPFROMREG(ft, MIPSInst_FT(ir));
rv.w = ieee754dp_cmp(fs, ft,
cmptab[cmpop & 0x7], cmpop & 0x8);
rfmt = -1;
if ((cmpop & 0x8)
&&
ieee754_cxtest
(IEEE754_INVALID_OPERATION))
rcsr = FPU_CSR_INV_X | FPU_CSR_INV_S;
else
goto copcsr;
}
else {
return SIGILL;
}
break;
}
break;
}
case w_fmt:{
ieee754sp fs;
switch (MIPSInst_FUNC(ir)) {
case fcvts_op:
SPFROMREG(fs, MIPSInst_FS(ir));
rv.s = ieee754sp_fint(fs.bits);
rfmt = s_fmt;
goto copcsr;
case fcvtd_op:
SPFROMREG(fs, MIPSInst_FS(ir));
rv.d = ieee754dp_fint(fs.bits);
rfmt = d_fmt;
goto copcsr;
default:
return SIGILL;
}
break;
}
#if defined(__mips64)
case l_fmt:{
switch (MIPSInst_FUNC(ir)) {
case fcvts_op:
rv.s = ieee754sp_flong(ctx->fpr[MIPSInst_FS(ir)]);
rfmt = s_fmt;
goto copcsr;
case fcvtd_op:
rv.d = ieee754dp_flong(ctx->fpr[MIPSInst_FS(ir)]);
rfmt = d_fmt;
goto copcsr;
default:
return SIGILL;
}
break;
}
#endif
default:
return SIGILL;
}
ctx->fcr31 = (ctx->fcr31 & ~FPU_CSR_ALL_X) | rcsr;
if ((ctx->fcr31 >> 5) & ctx->fcr31 & FPU_CSR_ALL_E) {
return SIGFPE;
}
switch (rfmt) {
case -1:{
#if __mips >= 4
cond = fpucondbit[MIPSInst_FD(ir) >> 2];
#else
cond = FPU_CSR_COND;
#endif
if (rv.w)
ctx->fcr31 |= cond;
else
ctx->fcr31 &= ~cond;
break;
}
case d_fmt:
DPTOREG(rv.d, MIPSInst_FD(ir));
break;
case s_fmt:
SPTOREG(rv.s, MIPSInst_FD(ir));
break;
case w_fmt:
SITOREG(rv.w, MIPSInst_FD(ir));
break;
#if defined(__mips64)
case l_fmt:
DITOREG(rv.l, MIPSInst_FD(ir));
break;
#endif
default:
return SIGILL;
}
return 0;
}
int fpu_emulator_cop1Handler(struct pt_regs *xcp, struct mips_fpu_struct *ctx,
int has_fpu, void *__user *fault_addr)
{
unsigned long oldepc, prevepc;
struct mm_decoded_insn dec_insn;
u16 instr[4];
u16 *instr_ptr;
int sig = 0;
oldepc = xcp->cp0_epc;
do {
prevepc = xcp->cp0_epc;
if (get_isa16_mode(prevepc) && cpu_has_mmips) {
if ((get_user(instr[0], (u16 __user *)msk_isa16_mode(xcp->cp0_epc))) ||
(get_user(instr[1], (u16 __user *)msk_isa16_mode(xcp->cp0_epc + 2))) ||
(get_user(instr[2], (u16 __user *)msk_isa16_mode(xcp->cp0_epc + 4))) ||
(get_user(instr[3], (u16 __user *)msk_isa16_mode(xcp->cp0_epc + 6)))) {
MIPS_FPU_EMU_INC_STATS(errors);
return SIGBUS;
}
instr_ptr = instr;
if (mm_insn_16bit(*instr_ptr)) {
dec_insn.insn = (*instr_ptr << 16) |
(*instr_ptr);
dec_insn.pc_inc = 2;
instr_ptr += 1;
} else {
dec_insn.insn = (*instr_ptr << 16) |
*(instr_ptr+1);
dec_insn.pc_inc = 4;
instr_ptr += 2;
}
if (mm_insn_16bit(*instr_ptr)) {
dec_insn.next_insn = (*instr_ptr << 16) |
(*instr_ptr);
dec_insn.next_pc_inc = 2;
} else {
dec_insn.next_insn = (*instr_ptr << 16) |
*(instr_ptr+1);
dec_insn.next_pc_inc = 4;
}
dec_insn.micro_mips_mode = 1;
} else {
if ((get_user(dec_insn.insn,
(mips_instruction __user *) xcp->cp0_epc)) ||
(get_user(dec_insn.next_insn,
(mips_instruction __user *)(xcp->cp0_epc+4)))) {
MIPS_FPU_EMU_INC_STATS(errors);
return SIGBUS;
}
dec_insn.pc_inc = 4;
dec_insn.next_pc_inc = 4;
dec_insn.micro_mips_mode = 0;
}
if ((dec_insn.insn == 0) ||
((dec_insn.pc_inc == 2) &&
((dec_insn.insn & 0xffff) == MM_NOP16)))
xcp->cp0_epc += dec_insn.pc_inc;
else {
ieee754_csr.rm = ieee_rm[ieee754_csr.rm];
sig = cop1Emulate(xcp, ctx, dec_insn, fault_addr);
ieee754_csr.rm = mips_rm[ieee754_csr.rm];
}
if (has_fpu)
break;
if (sig)
break;
cond_resched();
} while (xcp->cp0_epc > prevepc);
if (sig == SIGILL && xcp->cp0_epc != oldepc)
sig = 0;
return sig;
}
static int fpuemu_stat_get(void *data, u64 *val)
{
int cpu;
unsigned long sum = 0;
for_each_online_cpu(cpu) {
struct mips_fpu_emulator_stats *ps;
local_t *pv;
ps = &per_cpu(fpuemustats, cpu);
pv = (void *)ps + (unsigned long)data;
sum += local_read(pv);
}
*val = sum;
return 0;
}
static int __init debugfs_fpuemu(void)
{
struct dentry *d, *dir;
if (!mips_debugfs_dir)
return -ENODEV;
dir = debugfs_create_dir("fpuemustats", mips_debugfs_dir);
if (!dir)
return -ENOMEM;
#define FPU_STAT_CREATE(M) \
do { \
d = debugfs_create_file(#M , S_IRUGO, dir, \
(void *)offsetof(struct mips_fpu_emulator_stats, M), \
&fops_fpuemu_stat); \
if (!d) \
return -ENOMEM; \
} while (0)
FPU_STAT_CREATE(emulated);
FPU_STAT_CREATE(loads);
FPU_STAT_CREATE(stores);
FPU_STAT_CREATE(cp1ops);
FPU_STAT_CREATE(cp1xops);
FPU_STAT_CREATE(errors);
return 0;
}
