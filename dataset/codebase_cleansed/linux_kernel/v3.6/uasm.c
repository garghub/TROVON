static inline __uasminit u32 build_rs(u32 arg)
{
WARN(arg & ~RS_MASK, KERN_WARNING "Micro-assembler field overflow\n");
return (arg & RS_MASK) << RS_SH;
}
static inline __uasminit u32 build_rt(u32 arg)
{
WARN(arg & ~RT_MASK, KERN_WARNING "Micro-assembler field overflow\n");
return (arg & RT_MASK) << RT_SH;
}
static inline __uasminit u32 build_rd(u32 arg)
{
WARN(arg & ~RD_MASK, KERN_WARNING "Micro-assembler field overflow\n");
return (arg & RD_MASK) << RD_SH;
}
static inline __uasminit u32 build_re(u32 arg)
{
WARN(arg & ~RE_MASK, KERN_WARNING "Micro-assembler field overflow\n");
return (arg & RE_MASK) << RE_SH;
}
static inline __uasminit u32 build_simm(s32 arg)
{
WARN(arg > 0x7fff || arg < -0x8000,
KERN_WARNING "Micro-assembler field overflow\n");
return arg & 0xffff;
}
static inline __uasminit u32 build_uimm(u32 arg)
{
WARN(arg & ~IMM_MASK, KERN_WARNING "Micro-assembler field overflow\n");
return arg & IMM_MASK;
}
static inline __uasminit u32 build_bimm(s32 arg)
{
WARN(arg > 0x1ffff || arg < -0x20000,
KERN_WARNING "Micro-assembler field overflow\n");
WARN(arg & 0x3, KERN_WARNING "Invalid micro-assembler branch target\n");
return ((arg < 0) ? (1 << 15) : 0) | ((arg >> 2) & 0x7fff);
}
static inline __uasminit u32 build_jimm(u32 arg)
{
WARN(arg & ~(JIMM_MASK << 2),
KERN_WARNING "Micro-assembler field overflow\n");
return (arg >> 2) & JIMM_MASK;
}
static inline __uasminit u32 build_scimm(u32 arg)
{
WARN(arg & ~SCIMM_MASK,
KERN_WARNING "Micro-assembler field overflow\n");
return (arg & SCIMM_MASK) << SCIMM_SH;
}
static inline __uasminit u32 build_func(u32 arg)
{
WARN(arg & ~FUNC_MASK, KERN_WARNING "Micro-assembler field overflow\n");
return arg & FUNC_MASK;
}
static inline __uasminit u32 build_set(u32 arg)
{
WARN(arg & ~SET_MASK, KERN_WARNING "Micro-assembler field overflow\n");
return arg & SET_MASK;
}
static void __uasminit build_insn(u32 **buf, enum opcode opc, ...)
{
struct insn *ip = NULL;
unsigned int i;
va_list ap;
u32 op;
for (i = 0; insn_table[i].opcode != insn_invalid; i++)
if (insn_table[i].opcode == opc) {
ip = &insn_table[i];
break;
}
if (!ip || (opc == insn_daddiu && r4k_daddiu_bug()))
panic("Unsupported Micro-assembler instruction %d", opc);
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
va_end(ap);
**buf = op;
(*buf)++;
}
void __uasminit uasm_i_pref(u32 **buf, unsigned int a, signed int b,
unsigned int c)
{
if (OCTEON_IS_MODEL(OCTEON_CN63XX_PASS1_X) && a <= 24 && a != 5)
build_insn(buf, insn_pref, c, 28, b);
else
build_insn(buf, insn_pref, c, a, b);
}
void __uasminit uasm_build_label(struct uasm_label **lab, u32 *addr, int lid)
{
(*lab)->addr = addr;
(*lab)->lab = lid;
(*lab)++;
}
int __uasminit uasm_in_compat_space_p(long addr)
{
#ifdef CONFIG_64BIT
return (((addr) & 0xffffffff00000000L) == 0xffffffff00000000L);
#else
return 1;
#endif
}
static int __uasminit uasm_rel_highest(long val)
{
#ifdef CONFIG_64BIT
return ((((val + 0x800080008000L) >> 48) & 0xffff) ^ 0x8000) - 0x8000;
#else
return 0;
#endif
}
static int __uasminit uasm_rel_higher(long val)
{
#ifdef CONFIG_64BIT
return ((((val + 0x80008000L) >> 32) & 0xffff) ^ 0x8000) - 0x8000;
#else
return 0;
#endif
}
int __uasminit uasm_rel_hi(long val)
{
return ((((val + 0x8000L) >> 16) & 0xffff) ^ 0x8000) - 0x8000;
}
int __uasminit uasm_rel_lo(long val)
{
return ((val & 0xffff) ^ 0x8000) - 0x8000;
}
void __uasminit UASM_i_LA_mostly(u32 **buf, unsigned int rs, long addr)
{
if (!uasm_in_compat_space_p(addr)) {
uasm_i_lui(buf, rs, uasm_rel_highest(addr));
if (uasm_rel_higher(addr))
uasm_i_daddiu(buf, rs, rs, uasm_rel_higher(addr));
if (uasm_rel_hi(addr)) {
uasm_i_dsll(buf, rs, rs, 16);
uasm_i_daddiu(buf, rs, rs, uasm_rel_hi(addr));
uasm_i_dsll(buf, rs, rs, 16);
} else
uasm_i_dsll32(buf, rs, rs, 0);
} else
uasm_i_lui(buf, rs, uasm_rel_hi(addr));
}
void __uasminit UASM_i_LA(u32 **buf, unsigned int rs, long addr)
{
UASM_i_LA_mostly(buf, rs, addr);
if (uasm_rel_lo(addr)) {
if (!uasm_in_compat_space_p(addr))
uasm_i_daddiu(buf, rs, rs, uasm_rel_lo(addr));
else
uasm_i_addiu(buf, rs, rs, uasm_rel_lo(addr));
}
}
void __uasminit
uasm_r_mips_pc16(struct uasm_reloc **rel, u32 *addr, int lid)
{
(*rel)->addr = addr;
(*rel)->type = R_MIPS_PC16;
(*rel)->lab = lid;
(*rel)++;
}
static inline void __uasminit
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
void __uasminit
uasm_resolve_relocs(struct uasm_reloc *rel, struct uasm_label *lab)
{
struct uasm_label *l;
for (; rel->lab != UASM_LABEL_INVALID; rel++)
for (l = lab; l->lab != UASM_LABEL_INVALID; l++)
if (rel->lab == l->lab)
__resolve_relocs(rel, l);
}
void __uasminit
uasm_move_relocs(struct uasm_reloc *rel, u32 *first, u32 *end, long off)
{
for (; rel->lab != UASM_LABEL_INVALID; rel++)
if (rel->addr >= first && rel->addr < end)
rel->addr += off;
}
void __uasminit
uasm_move_labels(struct uasm_label *lab, u32 *first, u32 *end, long off)
{
for (; lab->lab != UASM_LABEL_INVALID; lab++)
if (lab->addr >= first && lab->addr < end)
lab->addr += off;
}
void __uasminit
uasm_copy_handler(struct uasm_reloc *rel, struct uasm_label *lab, u32 *first,
u32 *end, u32 *target)
{
long off = (long)(target - first);
memcpy(target, first, (end - first) * sizeof(u32));
uasm_move_relocs(rel, first, end, off);
uasm_move_labels(lab, first, end, off);
}
int __uasminit uasm_insn_has_bdelay(struct uasm_reloc *rel, u32 *addr)
{
for (; rel->lab != UASM_LABEL_INVALID; rel++) {
if (rel->addr == addr
&& (rel->type == R_MIPS_PC16
|| rel->type == R_MIPS_26))
return 1;
}
return 0;
}
void __uasminit
uasm_il_bltz(u32 **p, struct uasm_reloc **r, unsigned int reg, int lid)
{
uasm_r_mips_pc16(r, *p, lid);
uasm_i_bltz(p, reg, 0);
}
void __uasminit
uasm_il_b(u32 **p, struct uasm_reloc **r, int lid)
{
uasm_r_mips_pc16(r, *p, lid);
uasm_i_b(p, 0);
}
void __uasminit
uasm_il_beqz(u32 **p, struct uasm_reloc **r, unsigned int reg, int lid)
{
uasm_r_mips_pc16(r, *p, lid);
uasm_i_beqz(p, reg, 0);
}
void __uasminit
uasm_il_beqzl(u32 **p, struct uasm_reloc **r, unsigned int reg, int lid)
{
uasm_r_mips_pc16(r, *p, lid);
uasm_i_beqzl(p, reg, 0);
}
void __uasminit
uasm_il_bne(u32 **p, struct uasm_reloc **r, unsigned int reg1,
unsigned int reg2, int lid)
{
uasm_r_mips_pc16(r, *p, lid);
uasm_i_bne(p, reg1, reg2, 0);
}
void __uasminit
uasm_il_bnez(u32 **p, struct uasm_reloc **r, unsigned int reg, int lid)
{
uasm_r_mips_pc16(r, *p, lid);
uasm_i_bnez(p, reg, 0);
}
void __uasminit
uasm_il_bgezl(u32 **p, struct uasm_reloc **r, unsigned int reg, int lid)
{
uasm_r_mips_pc16(r, *p, lid);
uasm_i_bgezl(p, reg, 0);
}
void __uasminit
uasm_il_bgez(u32 **p, struct uasm_reloc **r, unsigned int reg, int lid)
{
uasm_r_mips_pc16(r, *p, lid);
uasm_i_bgez(p, reg, 0);
}
void __uasminit
uasm_il_bbit0(u32 **p, struct uasm_reloc **r, unsigned int reg,
unsigned int bit, int lid)
{
uasm_r_mips_pc16(r, *p, lid);
uasm_i_bbit0(p, reg, bit, 0);
}
void __uasminit
uasm_il_bbit1(u32 **p, struct uasm_reloc **r, unsigned int reg,
unsigned int bit, int lid)
{
uasm_r_mips_pc16(r, *p, lid);
uasm_i_bbit1(p, reg, bit, 0);
}
