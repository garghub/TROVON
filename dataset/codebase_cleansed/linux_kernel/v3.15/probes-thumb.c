static unsigned long __kprobes thumb_check_cc(unsigned long cpsr)
{
if (unlikely(in_it_block(cpsr)))
return probes_condition_checks[current_cond(cpsr)](cpsr);
return true;
}
static void __kprobes thumb16_singlestep(probes_opcode_t opcode,
struct arch_probes_insn *asi,
struct pt_regs *regs)
{
regs->ARM_pc += 2;
asi->insn_handler(opcode, asi, regs);
regs->ARM_cpsr = it_advance(regs->ARM_cpsr);
}
static void __kprobes thumb32_singlestep(probes_opcode_t opcode,
struct arch_probes_insn *asi,
struct pt_regs *regs)
{
regs->ARM_pc += 4;
asi->insn_handler(opcode, asi, regs);
regs->ARM_cpsr = it_advance(regs->ARM_cpsr);
}
enum probes_insn __kprobes
thumb16_probes_decode_insn(probes_opcode_t insn, struct arch_probes_insn *asi,
bool emulate, const union decode_action *actions)
{
asi->insn_singlestep = thumb16_singlestep;
asi->insn_check_cc = thumb_check_cc;
return probes_decode_insn(insn, asi, probes_decode_thumb16_table, true,
emulate, actions);
}
enum probes_insn __kprobes
thumb32_probes_decode_insn(probes_opcode_t insn, struct arch_probes_insn *asi,
bool emulate, const union decode_action *actions)
{
asi->insn_singlestep = thumb32_singlestep;
asi->insn_check_cc = thumb_check_cc;
return probes_decode_insn(insn, asi, probes_decode_thumb32_table, true,
emulate, actions);
}
