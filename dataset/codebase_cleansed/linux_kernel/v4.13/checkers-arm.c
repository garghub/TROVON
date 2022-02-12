static enum probes_insn __kprobes arm_check_stack(probes_opcode_t insn,
struct arch_probes_insn *asi,
const struct decode_header *h)
{
static const union decode_item table[] = {
DECODE_OR (0x0e10000f, 0x0600000d),
DECODE_OR (0x0e1f0000, 0x060d0000),
DECODE_OR (0x0e5000bf, 0x000000bd),
DECODE_CUSTOM (0x0e5f00b0, 0x000d00b0, STACK_USE_UNKNOWN),
DECODE_CUSTOM (0x0edf0000, 0x080d0000, STACK_USE_STMDX),
DECODE_CUSTOM (0x0f9f0000, 0x050d0000, STACK_USE_FIXED_XXX),
DECODE_CUSTOM (0x0fdf00b0, 0x014d00b0, STACK_USE_FIXED_X0X),
DECODE_CUSTOM (0, 0, STACK_USE_NONE),
DECODE_END
};
return probes_decode_insn(insn, asi, table, false, false, stack_check_actions, NULL);
}
static enum probes_insn __kprobes arm_check_regs_nouse(probes_opcode_t insn,
struct arch_probes_insn *asi,
const struct decode_header *h)
{
asi->register_usage_flags = 0;
return INSN_GOOD;
}
static enum probes_insn arm_check_regs_normal(probes_opcode_t insn,
struct arch_probes_insn *asi,
const struct decode_header *h)
{
u32 regs = h->type_regs.bits >> DECODE_TYPE_BITS;
int i;
asi->register_usage_flags = 0;
for (i = 0; i < 5; regs >>= 4, insn >>= 4, i++)
if (regs & 0xf)
asi->register_usage_flags |= 1 << (insn & 0xf);
return INSN_GOOD;
}
static enum probes_insn arm_check_regs_ldmstm(probes_opcode_t insn,
struct arch_probes_insn *asi,
const struct decode_header *h)
{
unsigned int reglist = insn & 0xffff;
unsigned int rn = (insn >> 16) & 0xf;
asi->register_usage_flags = reglist | (1 << rn);
return INSN_GOOD;
}
static enum probes_insn arm_check_regs_mov_ip_sp(probes_opcode_t insn,
struct arch_probes_insn *asi,
const struct decode_header *h)
{
asi->register_usage_flags = (1 << 12) | (1<< 13);
return INSN_GOOD;
}
static enum probes_insn arm_check_regs_ldrdstrd(probes_opcode_t insn,
struct arch_probes_insn *asi,
const struct decode_header *h)
{
int rdt = (insn >> 12) & 0xf;
arm_check_regs_normal(insn, asi, h);
asi->register_usage_flags |= 1 << (rdt + 1);
return INSN_GOOD;
}
