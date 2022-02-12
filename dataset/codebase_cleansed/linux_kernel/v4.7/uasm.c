static inline u32 build_rs(u32 arg)
{
WARN(arg & ~RS_MASK, KERN_WARNING "Micro-assembler field overflow\n");
return (arg & RS_MASK) << RS_SH;
}
static inline u32 build_rt(u32 arg)
{
WARN(arg & ~RT_MASK, KERN_WARNING "Micro-assembler field overflow\n");
return (arg & RT_MASK) << RT_SH;
}
static inline u32 build_rd(u32 arg)
{
WARN(arg & ~RD_MASK, KERN_WARNING "Micro-assembler field overflow\n");
return (arg & RD_MASK) << RD_SH;
}
static inline u32 build_re(u32 arg)
{
WARN(arg & ~RE_MASK, KERN_WARNING "Micro-assembler field overflow\n");
return (arg & RE_MASK) << RE_SH;
}
static inline u32 build_simm(s32 arg)
{
WARN(arg > 0x7fff || arg < -0x8000,
KERN_WARNING "Micro-assembler field overflow\n");
return arg & 0xffff;
}
static inline u32 build_uimm(u32 arg)
{
WARN(arg & ~IMM_MASK, KERN_WARNING "Micro-assembler field overflow\n");
return arg & IMM_MASK;
}
static inline u32 build_scimm(u32 arg)
{
WARN(arg & ~SCIMM_MASK,
KERN_WARNING "Micro-assembler field overflow\n");
return (arg & SCIMM_MASK) << SCIMM_SH;
}
static inline u32 build_scimm9(s32 arg)
{
WARN((arg > 0xff || arg < -0x100),
KERN_WARNING "Micro-assembler field overflow\n");
return (arg & SIMM9_MASK) << SIMM9_SH;
}
static inline u32 build_func(u32 arg)
{
WARN(arg & ~FUNC_MASK, KERN_WARNING "Micro-assembler field overflow\n");
return arg & FUNC_MASK;
}
static inline u32 build_set(u32 arg)
{
WARN(arg & ~SET_MASK, KERN_WARNING "Micro-assembler field overflow\n");
return arg & SET_MASK;
}
void ISAFUNC(uasm_i_pref)(u32 **buf, unsigned int a, signed int b,
unsigned int c)
{
if (CAVIUM_OCTEON_DCACHE_PREFETCH_WAR && a <= 24 && a != 5)
build_insn(buf, insn_pref, c, 28, b);
else
build_insn(buf, insn_pref, c, a, b);
}
void ISAFUNC(uasm_build_label)(struct uasm_label **lab, u32 *addr, int lid)
{
(*lab)->addr = addr;
(*lab)->lab = lid;
(*lab)++;
}
int ISAFUNC(uasm_in_compat_space_p)(long addr)
{
#ifdef CONFIG_64BIT
return (((addr) & 0xffffffff00000000L) == 0xffffffff00000000L);
#else
return 1;
#endif
}
static int uasm_rel_highest(long val)
{
#ifdef CONFIG_64BIT
return ((((val + 0x800080008000L) >> 48) & 0xffff) ^ 0x8000) - 0x8000;
#else
return 0;
#endif
}
static int uasm_rel_higher(long val)
{
#ifdef CONFIG_64BIT
return ((((val + 0x80008000L) >> 32) & 0xffff) ^ 0x8000) - 0x8000;
#else
return 0;
#endif
}
int ISAFUNC(uasm_rel_hi)(long val)
{
return ((((val + 0x8000L) >> 16) & 0xffff) ^ 0x8000) - 0x8000;
}
int ISAFUNC(uasm_rel_lo)(long val)
{
return ((val & 0xffff) ^ 0x8000) - 0x8000;
}
void ISAFUNC(UASM_i_LA_mostly)(u32 **buf, unsigned int rs, long addr)
{
if (!ISAFUNC(uasm_in_compat_space_p)(addr)) {
ISAFUNC(uasm_i_lui)(buf, rs, uasm_rel_highest(addr));
if (uasm_rel_higher(addr))
ISAFUNC(uasm_i_daddiu)(buf, rs, rs, uasm_rel_higher(addr));
if (ISAFUNC(uasm_rel_hi(addr))) {
ISAFUNC(uasm_i_dsll)(buf, rs, rs, 16);
ISAFUNC(uasm_i_daddiu)(buf, rs, rs,
ISAFUNC(uasm_rel_hi)(addr));
ISAFUNC(uasm_i_dsll)(buf, rs, rs, 16);
} else
ISAFUNC(uasm_i_dsll32)(buf, rs, rs, 0);
} else
ISAFUNC(uasm_i_lui)(buf, rs, ISAFUNC(uasm_rel_hi(addr)));
}
void ISAFUNC(UASM_i_LA)(u32 **buf, unsigned int rs, long addr)
{
ISAFUNC(UASM_i_LA_mostly)(buf, rs, addr);
if (ISAFUNC(uasm_rel_lo(addr))) {
if (!ISAFUNC(uasm_in_compat_space_p)(addr))
ISAFUNC(uasm_i_daddiu)(buf, rs, rs,
ISAFUNC(uasm_rel_lo(addr)));
else
ISAFUNC(uasm_i_addiu)(buf, rs, rs,
ISAFUNC(uasm_rel_lo(addr)));
}
}
void ISAFUNC(uasm_r_mips_pc16)(struct uasm_reloc **rel, u32 *addr, int lid)
{
(*rel)->addr = addr;
(*rel)->type = R_MIPS_PC16;
(*rel)->lab = lid;
(*rel)++;
}
void ISAFUNC(uasm_resolve_relocs)(struct uasm_reloc *rel,
struct uasm_label *lab)
{
struct uasm_label *l;
for (; rel->lab != UASM_LABEL_INVALID; rel++)
for (l = lab; l->lab != UASM_LABEL_INVALID; l++)
if (rel->lab == l->lab)
__resolve_relocs(rel, l);
}
void ISAFUNC(uasm_move_relocs)(struct uasm_reloc *rel, u32 *first, u32 *end,
long off)
{
for (; rel->lab != UASM_LABEL_INVALID; rel++)
if (rel->addr >= first && rel->addr < end)
rel->addr += off;
}
void ISAFUNC(uasm_move_labels)(struct uasm_label *lab, u32 *first, u32 *end,
long off)
{
for (; lab->lab != UASM_LABEL_INVALID; lab++)
if (lab->addr >= first && lab->addr < end)
lab->addr += off;
}
void ISAFUNC(uasm_copy_handler)(struct uasm_reloc *rel, struct uasm_label *lab,
u32 *first, u32 *end, u32 *target)
{
long off = (long)(target - first);
memcpy(target, first, (end - first) * sizeof(u32));
ISAFUNC(uasm_move_relocs(rel, first, end, off));
ISAFUNC(uasm_move_labels(lab, first, end, off));
}
int ISAFUNC(uasm_insn_has_bdelay)(struct uasm_reloc *rel, u32 *addr)
{
for (; rel->lab != UASM_LABEL_INVALID; rel++) {
if (rel->addr == addr
&& (rel->type == R_MIPS_PC16
|| rel->type == R_MIPS_26))
return 1;
}
return 0;
}
void ISAFUNC(uasm_il_bltz)(u32 **p, struct uasm_reloc **r, unsigned int reg,
int lid)
{
uasm_r_mips_pc16(r, *p, lid);
ISAFUNC(uasm_i_bltz)(p, reg, 0);
}
void ISAFUNC(uasm_il_b)(u32 **p, struct uasm_reloc **r, int lid)
{
uasm_r_mips_pc16(r, *p, lid);
ISAFUNC(uasm_i_b)(p, 0);
}
void ISAFUNC(uasm_il_beq)(u32 **p, struct uasm_reloc **r, unsigned int r1,
unsigned int r2, int lid)
{
uasm_r_mips_pc16(r, *p, lid);
ISAFUNC(uasm_i_beq)(p, r1, r2, 0);
}
void ISAFUNC(uasm_il_beqz)(u32 **p, struct uasm_reloc **r, unsigned int reg,
int lid)
{
uasm_r_mips_pc16(r, *p, lid);
ISAFUNC(uasm_i_beqz)(p, reg, 0);
}
void ISAFUNC(uasm_il_beqzl)(u32 **p, struct uasm_reloc **r, unsigned int reg,
int lid)
{
uasm_r_mips_pc16(r, *p, lid);
ISAFUNC(uasm_i_beqzl)(p, reg, 0);
}
void ISAFUNC(uasm_il_bne)(u32 **p, struct uasm_reloc **r, unsigned int reg1,
unsigned int reg2, int lid)
{
uasm_r_mips_pc16(r, *p, lid);
ISAFUNC(uasm_i_bne)(p, reg1, reg2, 0);
}
void ISAFUNC(uasm_il_bnez)(u32 **p, struct uasm_reloc **r, unsigned int reg,
int lid)
{
uasm_r_mips_pc16(r, *p, lid);
ISAFUNC(uasm_i_bnez)(p, reg, 0);
}
void ISAFUNC(uasm_il_bgezl)(u32 **p, struct uasm_reloc **r, unsigned int reg,
int lid)
{
uasm_r_mips_pc16(r, *p, lid);
ISAFUNC(uasm_i_bgezl)(p, reg, 0);
}
void ISAFUNC(uasm_il_bgez)(u32 **p, struct uasm_reloc **r, unsigned int reg,
int lid)
{
uasm_r_mips_pc16(r, *p, lid);
ISAFUNC(uasm_i_bgez)(p, reg, 0);
}
void ISAFUNC(uasm_il_bbit0)(u32 **p, struct uasm_reloc **r, unsigned int reg,
unsigned int bit, int lid)
{
uasm_r_mips_pc16(r, *p, lid);
ISAFUNC(uasm_i_bbit0)(p, reg, bit, 0);
}
void ISAFUNC(uasm_il_bbit1)(u32 **p, struct uasm_reloc **r, unsigned int reg,
unsigned int bit, int lid)
{
uasm_r_mips_pc16(r, *p, lid);
ISAFUNC(uasm_i_bbit1)(p, reg, bit, 0);
}
