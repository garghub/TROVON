int __isa_exception_epc(struct pt_regs *regs)
{
unsigned short inst;
long epc = regs->cp0_epc;
if (__get_user(inst, (u16 __user *) msk_isa16_mode(epc))) {
force_sig(SIGSEGV, current);
return epc;
}
if (cpu_has_mips16) {
union mips16e_instruction inst_mips16e;
inst_mips16e.full = inst;
if (inst_mips16e.ri.opcode == MIPS16e_jal_op)
epc += 4;
else
epc += 2;
} else if (mm_insn_16bit(inst))
epc += 2;
else
epc += 4;
return epc;
}
int __mm_isBranchInstr(struct pt_regs *regs, struct mm_decoded_insn dec_insn,
unsigned long *contpc)
{
union mips_instruction insn = (union mips_instruction)dec_insn.insn;
int bc_false = 0;
unsigned int fcr31;
unsigned int bit;
if (!cpu_has_mmips)
return 0;
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
case mm_bc2f_op:
case mm_bc1f_op:
bc_false = 1;
case mm_bc2t_op:
case mm_bc1t_op:
preempt_disable();
if (is_fpu_owner())
fcr31 = read_32bit_cp1_register(CP1_STATUS);
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
case mm_bnez16_op:
if ((long)regs->regs[reg16to32map[insn.mm_b1_format.rs]] != 0)
*contpc = regs->cp0_epc +
dec_insn.pc_inc +
(insn.mm_b1_format.simmediate << 1);
else
*contpc = regs->cp0_epc +
dec_insn.pc_inc + dec_insn.next_pc_inc;
return 1;
case mm_b16_op:
*contpc = regs->cp0_epc + dec_insn.pc_inc +
(insn.mm_b0_format.simmediate << 1);
return 1;
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
case mm_jalx32_op:
regs->regs[31] = regs->cp0_epc +
dec_insn.pc_inc + dec_insn.next_pc_inc;
*contpc = regs->cp0_epc + dec_insn.pc_inc;
*contpc >>= 28;
*contpc <<= 28;
*contpc |= (insn.j_format.target << 2);
return 1;
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
}
return 0;
}
int __microMIPS_compute_return_epc(struct pt_regs *regs)
{
u16 __user *pc16;
u16 halfword;
unsigned int word;
unsigned long contpc;
struct mm_decoded_insn mminsn = { 0 };
mminsn.micro_mips_mode = 1;
pc16 = (unsigned short __user *)msk_isa16_mode(regs->cp0_epc);
__get_user(halfword, pc16);
pc16++;
contpc = regs->cp0_epc + 2;
word = ((unsigned int)halfword << 16);
mminsn.pc_inc = 2;
if (!mm_insn_16bit(halfword)) {
__get_user(halfword, pc16);
pc16++;
contpc = regs->cp0_epc + 4;
mminsn.pc_inc = 4;
word |= halfword;
}
mminsn.insn = word;
if (get_user(halfword, pc16))
goto sigsegv;
mminsn.next_pc_inc = 2;
word = ((unsigned int)halfword << 16);
if (!mm_insn_16bit(halfword)) {
pc16++;
if (get_user(halfword, pc16))
goto sigsegv;
mminsn.next_pc_inc = 4;
word |= halfword;
}
mminsn.next_insn = word;
mm_isBranchInstr(regs, mminsn, &contpc);
regs->cp0_epc = contpc;
return 0;
sigsegv:
force_sig(SIGSEGV, current);
return -EFAULT;
}
int __MIPS16e_compute_return_epc(struct pt_regs *regs)
{
u16 __user *addr;
union mips16e_instruction inst;
u16 inst2;
u32 fullinst;
long epc;
epc = regs->cp0_epc;
addr = (u16 __user *)msk_isa16_mode(epc);
if (__get_user(inst.full, addr)) {
force_sig(SIGSEGV, current);
return -EFAULT;
}
switch (inst.ri.opcode) {
case MIPS16e_extend_op:
regs->cp0_epc += 4;
return 0;
case MIPS16e_jal_op:
addr += 1;
if (__get_user(inst2, addr)) {
force_sig(SIGSEGV, current);
return -EFAULT;
}
fullinst = ((unsigned)inst.full << 16) | inst2;
regs->regs[31] = epc + 6;
epc += 4;
epc >>= 28;
epc <<= 28;
epc |=
((fullinst & 0xffff) << 2) | ((fullinst & 0x3e00000) >> 3) |
((fullinst & 0x1f0000) << 7);
if (!inst.jal.x)
set_isa16_mode(epc);
regs->cp0_epc = epc;
return 0;
case MIPS16e_rr_op:
if (inst.rr.func == MIPS16e_jr_func) {
if (inst.rr.ra)
regs->cp0_epc = regs->regs[31];
else
regs->cp0_epc =
regs->regs[reg16to32[inst.rr.rx]];
if (inst.rr.l) {
if (inst.rr.nd)
regs->regs[31] = epc + 2;
else
regs->regs[31] = epc + 4;
}
return 0;
}
break;
}
regs->cp0_epc += 2;
return 0;
}
int __compute_return_epc_for_insn(struct pt_regs *regs,
union mips_instruction insn)
{
unsigned int bit, fcr31, dspcontrol, reg;
long epc = regs->cp0_epc;
int ret = 0;
switch (insn.i_format.opcode) {
case spec_op:
switch (insn.r_format.func) {
case jalr_op:
regs->regs[insn.r_format.rd] = epc + 8;
case jr_op:
if (NO_R6EMU && insn.r_format.func == jr_op)
goto sigill_r6;
regs->cp0_epc = regs->regs[insn.r_format.rs];
break;
}
break;
case bcond_op:
switch (insn.i_format.rt) {
case bltzl_op:
if (NO_R6EMU)
goto sigill_r6;
case bltz_op:
if ((long)regs->regs[insn.i_format.rs] < 0) {
epc = epc + 4 + (insn.i_format.simmediate << 2);
if (insn.i_format.rt == bltzl_op)
ret = BRANCH_LIKELY_TAKEN;
} else
epc += 8;
regs->cp0_epc = epc;
break;
case bgezl_op:
if (NO_R6EMU)
goto sigill_r6;
case bgez_op:
if ((long)regs->regs[insn.i_format.rs] >= 0) {
epc = epc + 4 + (insn.i_format.simmediate << 2);
if (insn.i_format.rt == bgezl_op)
ret = BRANCH_LIKELY_TAKEN;
} else
epc += 8;
regs->cp0_epc = epc;
break;
case bltzal_op:
case bltzall_op:
if (NO_R6EMU && (insn.i_format.rs ||
insn.i_format.rt == bltzall_op)) {
ret = -SIGILL;
break;
}
regs->regs[31] = epc + 8;
if (!insn.i_format.rs) {
regs->cp0_epc += 4 +
(insn.i_format.simmediate << 2);
break;
}
if ((long)regs->regs[insn.i_format.rs] < 0) {
epc = epc + 4 + (insn.i_format.simmediate << 2);
if (insn.i_format.rt == bltzall_op)
ret = BRANCH_LIKELY_TAKEN;
} else
epc += 8;
regs->cp0_epc = epc;
break;
case bgezal_op:
case bgezall_op:
if (NO_R6EMU && (insn.i_format.rs ||
insn.i_format.rt == bgezall_op)) {
ret = -SIGILL;
break;
}
regs->regs[31] = epc + 8;
if (!insn.i_format.rs) {
regs->cp0_epc += 4 +
(insn.i_format.simmediate << 2);
break;
}
if ((long)regs->regs[insn.i_format.rs] >= 0) {
epc = epc + 4 + (insn.i_format.simmediate << 2);
if (insn.i_format.rt == bgezall_op)
ret = BRANCH_LIKELY_TAKEN;
} else
epc += 8;
regs->cp0_epc = epc;
break;
case bposge32_op:
if (!cpu_has_dsp)
goto sigill_dsp;
dspcontrol = rddsp(0x01);
if (dspcontrol >= 32) {
epc = epc + 4 + (insn.i_format.simmediate << 2);
} else
epc += 8;
regs->cp0_epc = epc;
break;
}
break;
case jal_op:
regs->regs[31] = regs->cp0_epc + 8;
case j_op:
epc += 4;
epc >>= 28;
epc <<= 28;
epc |= (insn.j_format.target << 2);
regs->cp0_epc = epc;
if (insn.i_format.opcode == jalx_op)
set_isa16_mode(regs->cp0_epc);
break;
case beql_op:
if (NO_R6EMU)
goto sigill_r6;
case beq_op:
if (regs->regs[insn.i_format.rs] ==
regs->regs[insn.i_format.rt]) {
epc = epc + 4 + (insn.i_format.simmediate << 2);
if (insn.i_format.opcode == beql_op)
ret = BRANCH_LIKELY_TAKEN;
} else
epc += 8;
regs->cp0_epc = epc;
break;
case bnel_op:
if (NO_R6EMU)
goto sigill_r6;
case bne_op:
if (regs->regs[insn.i_format.rs] !=
regs->regs[insn.i_format.rt]) {
epc = epc + 4 + (insn.i_format.simmediate << 2);
if (insn.i_format.opcode == bnel_op)
ret = BRANCH_LIKELY_TAKEN;
} else
epc += 8;
regs->cp0_epc = epc;
break;
case blezl_op:
if (NO_R6EMU)
goto sigill_r6;
case blez_op:
if (cpu_has_mips_r6 && insn.i_format.rt) {
if ((insn.i_format.opcode == blez_op) &&
((!insn.i_format.rs && insn.i_format.rt) ||
(insn.i_format.rs == insn.i_format.rt)))
regs->regs[31] = epc + 4;
regs->cp0_epc += 8;
break;
}
if ((long)regs->regs[insn.i_format.rs] <= 0) {
epc = epc + 4 + (insn.i_format.simmediate << 2);
if (insn.i_format.opcode == blezl_op)
ret = BRANCH_LIKELY_TAKEN;
} else
epc += 8;
regs->cp0_epc = epc;
break;
case bgtzl_op:
if (NO_R6EMU)
goto sigill_r6;
case bgtz_op:
if (cpu_has_mips_r6 && insn.i_format.rt) {
if ((insn.i_format.opcode == blez_op) &&
((!insn.i_format.rs && insn.i_format.rt) ||
(insn.i_format.rs == insn.i_format.rt)))
regs->regs[31] = epc + 4;
regs->cp0_epc += 8;
break;
}
if ((long)regs->regs[insn.i_format.rs] > 0) {
epc = epc + 4 + (insn.i_format.simmediate << 2);
if (insn.i_format.opcode == bgtzl_op)
ret = BRANCH_LIKELY_TAKEN;
} else
epc += 8;
regs->cp0_epc = epc;
break;
case cop1_op:
if (cpu_has_mips_r6 &&
((insn.i_format.rs == bc1eqz_op) ||
(insn.i_format.rs == bc1nez_op))) {
if (!used_math()) {
ret = init_fpu();
if (ret && NO_R6EMU) {
ret = -ret;
break;
}
ret = 0;
set_used_math();
}
lose_fpu(1);
reg = insn.i_format.rt;
bit = 0;
switch (insn.i_format.rs) {
case bc1eqz_op:
if (get_fpr32(&current->thread.fpu.fpr[reg], 0)
& 0x1)
bit = 1;
break;
case bc1nez_op:
if (!(get_fpr32(&current->thread.fpu.fpr[reg], 0)
& 0x1))
bit = 1;
break;
}
own_fpu(1);
if (bit)
epc = epc + 4 +
(insn.i_format.simmediate << 2);
else
epc += 8;
regs->cp0_epc = epc;
break;
} else {
preempt_disable();
if (is_fpu_owner())
fcr31 = read_32bit_cp1_register(CP1_STATUS);
else
fcr31 = current->thread.fpu.fcr31;
preempt_enable();
bit = (insn.i_format.rt >> 2);
bit += (bit != 0);
bit += 23;
switch (insn.i_format.rt & 3) {
case 0:
case 2:
if (~fcr31 & (1 << bit)) {
epc = epc + 4 +
(insn.i_format.simmediate << 2);
if (insn.i_format.rt == 2)
ret = BRANCH_LIKELY_TAKEN;
} else
epc += 8;
regs->cp0_epc = epc;
break;
case 1:
case 3:
if (fcr31 & (1 << bit)) {
epc = epc + 4 +
(insn.i_format.simmediate << 2);
if (insn.i_format.rt == 3)
ret = BRANCH_LIKELY_TAKEN;
} else
epc += 8;
regs->cp0_epc = epc;
break;
}
break;
}
#ifdef CONFIG_CPU_CAVIUM_OCTEON
case lwc2_op:
if ((regs->regs[insn.i_format.rs] & (1ull<<insn.i_format.rt))
== 0)
epc = epc + 4 + (insn.i_format.simmediate << 2);
else
epc += 8;
regs->cp0_epc = epc;
break;
case ldc2_op:
if ((regs->regs[insn.i_format.rs] &
(1ull<<(insn.i_format.rt+32))) == 0)
epc = epc + 4 + (insn.i_format.simmediate << 2);
else
epc += 8;
regs->cp0_epc = epc;
break;
case swc2_op:
if (regs->regs[insn.i_format.rs] & (1ull<<insn.i_format.rt))
epc = epc + 4 + (insn.i_format.simmediate << 2);
else
epc += 8;
regs->cp0_epc = epc;
break;
case sdc2_op:
if (regs->regs[insn.i_format.rs] &
(1ull<<(insn.i_format.rt+32)))
epc = epc + 4 + (insn.i_format.simmediate << 2);
else
epc += 8;
regs->cp0_epc = epc;
break;
#else
case bc6_op:
if (!cpu_has_mips_r6) {
ret = -SIGILL;
break;
}
regs->cp0_epc += 8;
break;
case balc6_op:
if (!cpu_has_mips_r6) {
ret = -SIGILL;
break;
}
regs->regs[31] = epc + 4;
epc += 4 + (insn.i_format.simmediate << 2);
regs->cp0_epc = epc;
break;
case beqzcjic_op:
if (!cpu_has_mips_r6) {
ret = -SIGILL;
break;
}
regs->cp0_epc += 8;
break;
case bnezcjialc_op:
if (!cpu_has_mips_r6) {
ret = -SIGILL;
break;
}
if (insn.i_format.rs)
regs->regs[31] = epc + 4;
regs->cp0_epc += 8;
break;
#endif
case cbcond0_op:
case cbcond1_op:
if (!cpu_has_mips_r6) {
ret = -SIGILL;
break;
}
if (insn.i_format.rt && !insn.i_format.rs)
regs->regs[31] = epc + 4;
regs->cp0_epc += 8;
break;
}
return ret;
sigill_dsp:
printk("%s: DSP branch but not DSP ASE - sending SIGBUS.\n", current->comm);
force_sig(SIGBUS, current);
return -EFAULT;
sigill_r6:
pr_info("%s: R2 branch but r2-to-r6 emulator is not preset - sending SIGILL.\n",
current->comm);
force_sig(SIGILL, current);
return -EFAULT;
}
int __compute_return_epc(struct pt_regs *regs)
{
unsigned int __user *addr;
long epc;
union mips_instruction insn;
epc = regs->cp0_epc;
if (epc & 3)
goto unaligned;
addr = (unsigned int __user *) epc;
if (__get_user(insn.word, addr)) {
force_sig(SIGSEGV, current);
return -EFAULT;
}
return __compute_return_epc_for_insn(regs, insn);
unaligned:
printk("%s: unaligned epc - sending SIGBUS.\n", current->comm);
force_sig(SIGBUS, current);
return -EFAULT;
}
