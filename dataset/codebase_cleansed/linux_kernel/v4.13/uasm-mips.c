static inline u32 build_bimm(s32 arg)
{
WARN(arg > 0x1ffff || arg < -0x20000,
KERN_WARNING "Micro-assembler field overflow\n");
WARN(arg & 0x3, KERN_WARNING "Invalid micro-assembler branch target\n");
return ((arg < 0) ? (1 << 15) : 0) | ((arg >> 2) & 0x7fff);
}
static inline u32 build_jimm(u32 arg)
{
WARN(arg & ~(JIMM_MASK << 2),
KERN_WARNING "Micro-assembler field overflow\n");
return (arg >> 2) & JIMM_MASK;
}
static void build_insn(u32 **buf, enum opcode opc, ...)
{
const struct insn *ip;
va_list ap;
u32 op;
if (opc < 0 || opc >= insn_invalid ||
(opc == insn_daddiu && r4k_daddiu_bug()) ||
(insn_table[opc].match == 0 && insn_table[opc].fields == 0))
panic("Unsupported Micro-assembler instruction %d", opc);
ip = &insn_table[opc];
op = ip->match;
va_start(ap, opc);
if (ip->fields & RS)
op |= build_rs(va_arg(ap, u32));
if (ip->fields & RT)
op |= build_rt(va_arg(ap, u32));
if (ip->fields & RD)
op |= build_rd(va_arg(ap, u32));
if (ip->fields & RE)
op |= build_re(va_arg(ap, u32));
if (ip->fields & SIMM)
op |= build_simm(va_arg(ap, s32));
if (ip->fields & UIMM)
op |= build_uimm(va_arg(ap, u32));
if (ip->fields & BIMM)
op |= build_bimm(va_arg(ap, s32));
if (ip->fields & JIMM)
op |= build_jimm(va_arg(ap, u32));
if (ip->fields & FUNC)
op |= build_func(va_arg(ap, u32));
if (ip->fields & SET)
op |= build_set(va_arg(ap, u32));
if (ip->fields & SCIMM)
op |= build_scimm(va_arg(ap, u32));
if (ip->fields & SIMM9)
op |= build_scimm9(va_arg(ap, u32));
va_end(ap);
**buf = op;
(*buf)++;
}
static inline void
__resolve_relocs(struct uasm_reloc *rel, struct uasm_label *lab)
{
long laddr = (long)lab->addr;
long raddr = (long)rel->addr;
switch (rel->type) {
case R_MIPS_PC16:
*rel->addr |= build_bimm(laddr - (raddr + 4));
break;
default:
panic("Unsupported Micro-assembler relocation %d",
rel->type);
}
}
