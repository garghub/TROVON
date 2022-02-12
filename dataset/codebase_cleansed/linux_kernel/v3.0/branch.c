int __compute_return_epc(struct pt_regs *regs)
{
unsigned int __user *addr;
unsigned int bit, fcr31, dspcontrol;
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
if ((long)regs->regs[insn.i_format.rs] < 0)
epc = epc + 4 + (insn.i_format.simmediate << 2);
else
epc += 8;
regs->cp0_epc = epc;
break;
case bgez_op:
case bgezl_op:
if ((long)regs->regs[insn.i_format.rs] >= 0)
epc = epc + 4 + (insn.i_format.simmediate << 2);
else
epc += 8;
regs->cp0_epc = epc;
break;
case bltzal_op:
case bltzall_op:
regs->regs[31] = epc + 8;
if ((long)regs->regs[insn.i_format.rs] < 0)
epc = epc + 4 + (insn.i_format.simmediate << 2);
else
epc += 8;
regs->cp0_epc = epc;
break;
case bgezal_op:
case bgezall_op:
regs->regs[31] = epc + 8;
if ((long)regs->regs[insn.i_format.rs] >= 0)
epc = epc + 4 + (insn.i_format.simmediate << 2);
else
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
break;
case beq_op:
case beql_op:
if (regs->regs[insn.i_format.rs] ==
regs->regs[insn.i_format.rt])
epc = epc + 4 + (insn.i_format.simmediate << 2);
else
epc += 8;
regs->cp0_epc = epc;
break;
case bne_op:
case bnel_op:
if (regs->regs[insn.i_format.rs] !=
regs->regs[insn.i_format.rt])
epc = epc + 4 + (insn.i_format.simmediate << 2);
else
epc += 8;
regs->cp0_epc = epc;
break;
case blez_op:
case blezl_op:
if ((long)regs->regs[insn.i_format.rs] <= 0)
epc = epc + 4 + (insn.i_format.simmediate << 2);
else
epc += 8;
regs->cp0_epc = epc;
break;
case bgtz_op:
case bgtzl_op:
if ((long)regs->regs[insn.i_format.rs] > 0)
epc = epc + 4 + (insn.i_format.simmediate << 2);
else
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
if (~fcr31 & (1 << bit))
epc = epc + 4 + (insn.i_format.simmediate << 2);
else
epc += 8;
regs->cp0_epc = epc;
break;
case 1:
case 3:
if (fcr31 & (1 << bit))
epc = epc + 4 + (insn.i_format.simmediate << 2);
else
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
return 0;
unaligned:
printk("%s: unaligned epc - sending SIGBUS.\n", current->comm);
force_sig(SIGBUS, current);
return -EFAULT;
sigill:
printk("%s: DSP branch but not DSP ASE - sending SIGBUS.\n", current->comm);
force_sig(SIGBUS, current);
return -EFAULT;
}
