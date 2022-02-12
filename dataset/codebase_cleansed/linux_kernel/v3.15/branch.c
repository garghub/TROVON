int __isa_exception_epc(struct pt_regs *regs)
{
unsigned short inst;
long epc = regs->cp0_epc;
if (__get_user(inst, (u16 __user *) msk_isa16_mode(epc))) {
force_sig(SIGSEGV, current);
return epc;
}
if (cpu_has_mips16) {
if (((union mips16e_instruction)inst).ri.opcode
== MIPS16e_jal_op)
epc += 4;
else
epc += 2;
} else if (mm_insn_16bit(inst))
epc += 2;
else
epc += 4;
return epc;
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
unsigned int bit, fcr31, dspcontrol;
long epc = regs->cp0_epc;
int ret = 0;
switch (insn.i_format.opcode) {
case spec_op:
switch (insn.r_format.func) {
case jalr_op:
regs->regs[insn.r_format.rd] = epc + 8;
case jr_op:
regs->cp0_epc = regs->regs[insn.r_format.rs];
break;
}
break;
case bcond_op:
switch (insn.i_format.rt) {
case bltz_op:
case bltzl_op:
if ((long)regs->regs[insn.i_format.rs] < 0) {
epc = epc + 4 + (insn.i_format.simmediate << 2);
if (insn.i_format.rt == bltzl_op)
ret = BRANCH_LIKELY_TAKEN;
} else
epc += 8;
regs->cp0_epc = epc;
break;
case bgez_op:
case bgezl_op:
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
regs->regs[31] = epc + 8;
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
regs->regs[31] = epc + 8;
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
goto sigill;
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
case beq_op:
case beql_op:
if (regs->regs[insn.i_format.rs] ==
regs->regs[insn.i_format.rt]) {
epc = epc + 4 + (insn.i_format.simmediate << 2);
if (insn.i_format.opcode == beql_op)
ret = BRANCH_LIKELY_TAKEN;
} else
epc += 8;
regs->cp0_epc = epc;
break;
case bne_op:
case bnel_op:
if (regs->regs[insn.i_format.rs] !=
regs->regs[insn.i_format.rt]) {
epc = epc + 4 + (insn.i_format.simmediate << 2);
if (insn.i_format.opcode == bnel_op)
ret = BRANCH_LIKELY_TAKEN;
} else
epc += 8;
regs->cp0_epc = epc;
break;
case blez_op:
case blezl_op:
if ((long)regs->regs[insn.i_format.rs] <= 0) {
epc = epc + 4 + (insn.i_format.simmediate << 2);
if (insn.i_format.opcode == blezl_op)
ret = BRANCH_LIKELY_TAKEN;
} else
epc += 8;
regs->cp0_epc = epc;
break;
case bgtz_op:
case bgtzl_op:
if ((long)regs->regs[insn.i_format.rs] > 0) {
epc = epc + 4 + (insn.i_format.simmediate << 2);
if (insn.i_format.opcode == bgtzl_op)
ret = BRANCH_LIKELY_TAKEN;
} else
epc += 8;
regs->cp0_epc = epc;
break;
case cop1_op:
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
if (~fcr31 & (1 << bit)) {
epc = epc + 4 + (insn.i_format.simmediate << 2);
if (insn.i_format.rt == 2)
ret = BRANCH_LIKELY_TAKEN;
} else
epc += 8;
regs->cp0_epc = epc;
break;
case 1:
case 3:
if (fcr31 & (1 << bit)) {
epc = epc + 4 + (insn.i_format.simmediate << 2);
if (insn.i_format.rt == 3)
ret = BRANCH_LIKELY_TAKEN;
} else
epc += 8;
regs->cp0_epc = epc;
break;
}
break;
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
#endif
}
return ret;
sigill:
printk("%s: DSP branch but not DSP ASE - sending SIGBUS.\n", current->comm);
force_sig(SIGBUS, current);
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
