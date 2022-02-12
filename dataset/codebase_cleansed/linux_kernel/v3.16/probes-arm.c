void __kprobes simulate_bbl(probes_opcode_t insn,
struct arch_probes_insn *asi, struct pt_regs *regs)
{
long iaddr = (long) regs->ARM_pc - 4;
int disp = branch_displacement(insn);
if (insn & (1 << 24))
regs->ARM_lr = iaddr + 4;
regs->ARM_pc = iaddr + 8 + disp;
}
void __kprobes simulate_blx1(probes_opcode_t insn,
struct arch_probes_insn *asi, struct pt_regs *regs)
{
long iaddr = (long) regs->ARM_pc - 4;
int disp = branch_displacement(insn);
regs->ARM_lr = iaddr + 4;
regs->ARM_pc = iaddr + 8 + disp + ((insn >> 23) & 0x2);
regs->ARM_cpsr |= PSR_T_BIT;
}
void __kprobes simulate_blx2bx(probes_opcode_t insn,
struct arch_probes_insn *asi, struct pt_regs *regs)
{
int rm = insn & 0xf;
long rmv = regs->uregs[rm];
if (insn & (1 << 5))
regs->ARM_lr = (long) regs->ARM_pc;
regs->ARM_pc = rmv & ~0x1;
regs->ARM_cpsr &= ~PSR_T_BIT;
if (rmv & 0x1)
regs->ARM_cpsr |= PSR_T_BIT;
}
void __kprobes simulate_mrs(probes_opcode_t insn,
struct arch_probes_insn *asi, struct pt_regs *regs)
{
int rd = (insn >> 12) & 0xf;
unsigned long mask = 0xf8ff03df;
regs->uregs[rd] = regs->ARM_cpsr & mask;
}
void __kprobes simulate_mov_ipsp(probes_opcode_t insn,
struct arch_probes_insn *asi, struct pt_regs *regs)
{
regs->uregs[12] = regs->uregs[13];
}
static void __kprobes arm_singlestep(probes_opcode_t insn,
struct arch_probes_insn *asi, struct pt_regs *regs)
{
regs->ARM_pc += 4;
asi->insn_handler(insn, asi, regs);
}
enum probes_insn __kprobes
arm_probes_decode_insn(probes_opcode_t insn, struct arch_probes_insn *asi,
bool emulate, const union decode_action *actions)
{
asi->insn_singlestep = arm_singlestep;
asi->insn_check_cc = probes_condition_checks[insn>>28];
return probes_decode_insn(insn, asi, probes_decode_arm_table, false,
emulate, actions);
}
