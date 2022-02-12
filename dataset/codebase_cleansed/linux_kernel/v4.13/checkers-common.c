enum probes_insn checker_stack_use_none(probes_opcode_t insn,
struct arch_probes_insn *asi,
const struct decode_header *h)
{
asi->stack_space = 0;
return INSN_GOOD_NO_SLOT;
}
enum probes_insn checker_stack_use_unknown(probes_opcode_t insn,
struct arch_probes_insn *asi,
const struct decode_header *h)
{
asi->stack_space = -1;
return INSN_GOOD_NO_SLOT;
}
enum probes_insn checker_stack_use_imm_0xx(probes_opcode_t insn,
struct arch_probes_insn *asi,
const struct decode_header *h)
{
int imm = insn & 0xff;
asi->stack_space = imm;
return INSN_GOOD_NO_SLOT;
}
enum probes_insn checker_stack_use_t32strd(probes_opcode_t insn,
struct arch_probes_insn *asi,
const struct decode_header *h)
{
int imm = insn & 0xff;
asi->stack_space = imm << 2;
return INSN_GOOD_NO_SLOT;
}
enum probes_insn checker_stack_use_imm_x0x(probes_opcode_t insn,
struct arch_probes_insn *asi,
const struct decode_header *h)
{
int imm = ((insn & 0xf00) >> 4) + (insn & 0xf);
asi->stack_space = imm;
return INSN_GOOD_NO_SLOT;
}
enum probes_insn checker_stack_use_imm_xxx(probes_opcode_t insn,
struct arch_probes_insn *asi,
const struct decode_header *h)
{
int imm = insn & 0xfff;
asi->stack_space = imm;
return INSN_GOOD_NO_SLOT;
}
enum probes_insn checker_stack_use_stmdx(probes_opcode_t insn,
struct arch_probes_insn *asi,
const struct decode_header *h)
{
unsigned int reglist = insn & 0xffff;
int pbit = insn & (1 << 24);
asi->stack_space = (hweight32(reglist) - (!pbit ? 1 : 0)) * 4;
return INSN_GOOD_NO_SLOT;
}
