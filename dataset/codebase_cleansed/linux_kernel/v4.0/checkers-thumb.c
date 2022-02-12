static enum probes_insn __kprobes t32_check_stack(probes_opcode_t insn,
struct arch_probes_insn *asi,
const struct decode_header *h)
{
static const union decode_item table[] = {
DECODE_CUSTOM (0x00100000, 0x00100000, STACK_USE_NONE),
DECODE_OR (0xff9f0fc0, 0xf80d0000),
DECODE_CUSTOM (0xff900fcf, 0xf800000d, STACK_USE_UNKNOWN),
DECODE_CUSTOM (0xff9f0e00, 0xf80d0c00, STACK_USE_FIXED_0XX),
DECODE_CUSTOM (0xffdf0000, 0xe94d0000, STACK_USE_T32STRD),
DECODE_CUSTOM (0xffdf0000, 0xe90d0000, STACK_USE_STMDX),
DECODE_CUSTOM (0, 0, STACK_USE_NONE),
DECODE_END
};
return probes_decode_insn(insn, asi, table, false, false, stack_check_actions, NULL);
}
static enum probes_insn __kprobes t16_check_stack(probes_opcode_t insn,
struct arch_probes_insn *asi,
const struct decode_header *h)
{
unsigned int reglist = insn & 0x1ff;
asi->stack_space = hweight32(reglist) * 4;
return INSN_GOOD;
}
