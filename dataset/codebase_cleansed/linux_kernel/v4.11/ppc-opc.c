static unsigned long
insert_arx (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
if (value >= 8 && value < 24)
return insn | ((value - 8) & 0xf);
else
{
*errmsg = _("invalid register");
return 0;
}
}
static long
extract_arx (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
return (insn & 0xf) + 8;
}
static unsigned long
insert_ary (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
if (value >= 8 && value < 24)
return insn | (((value - 8) & 0xf) << 4);
else
{
*errmsg = _("invalid register");
return 0;
}
}
static long
extract_ary (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
return ((insn >> 4) & 0xf) + 8;
}
static unsigned long
insert_rx (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg)
{
if (value >= 0 && value < 8)
return insn | value;
else if (value >= 24 && value <= 31)
return insn | (value - 16);
else
{
*errmsg = _("invalid register");
return 0;
}
}
static long
extract_rx (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
int value = insn & 0xf;
if (value >= 0 && value < 8)
return value;
else
return value + 16;
}
static unsigned long
insert_ry (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg)
{
if (value >= 0 && value < 8)
return insn | (value << 4);
else if (value >= 24 && value <= 31)
return insn | ((value - 16) << 4);
else
{
*errmsg = _("invalid register");
return 0;
}
}
static long
extract_ry (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
int value = (insn >> 4) & 0xf;
if (value >= 0 && value < 8)
return value;
else
return value + 16;
}
static unsigned long
insert_bat (unsigned long insn,
long value ATTRIBUTE_UNUSED,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
return insn | (((insn >> 21) & 0x1f) << 16);
}
static long
extract_bat (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid)
{
if (((insn >> 21) & 0x1f) != ((insn >> 16) & 0x1f))
*invalid = 1;
return 0;
}
static unsigned long
insert_bba (unsigned long insn,
long value ATTRIBUTE_UNUSED,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
return insn | (((insn >> 16) & 0x1f) << 11);
}
static long
extract_bba (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid)
{
if (((insn >> 16) & 0x1f) != ((insn >> 11) & 0x1f))
*invalid = 1;
return 0;
}
static unsigned long
insert_bdm (unsigned long insn,
long value,
ppc_cpu_t dialect,
const char **errmsg ATTRIBUTE_UNUSED)
{
if ((dialect & ISA_V2) == 0)
{
if ((value & 0x8000) != 0)
insn |= 1 << 21;
}
else
{
if ((insn & (0x14 << 21)) == (0x04 << 21))
insn |= 0x02 << 21;
else if ((insn & (0x14 << 21)) == (0x10 << 21))
insn |= 0x08 << 21;
}
return insn | (value & 0xfffc);
}
static long
extract_bdm (unsigned long insn,
ppc_cpu_t dialect,
int *invalid)
{
if ((dialect & ISA_V2) == 0)
{
if (((insn & (1 << 21)) == 0) != ((insn & (1 << 15)) == 0))
*invalid = 1;
}
else
{
if ((insn & (0x17 << 21)) != (0x06 << 21)
&& (insn & (0x1d << 21)) != (0x18 << 21))
*invalid = 1;
}
return ((insn & 0xfffc) ^ 0x8000) - 0x8000;
}
static unsigned long
insert_bdp (unsigned long insn,
long value,
ppc_cpu_t dialect,
const char **errmsg ATTRIBUTE_UNUSED)
{
if ((dialect & ISA_V2) == 0)
{
if ((value & 0x8000) == 0)
insn |= 1 << 21;
}
else
{
if ((insn & (0x14 << 21)) == (0x04 << 21))
insn |= 0x03 << 21;
else if ((insn & (0x14 << 21)) == (0x10 << 21))
insn |= 0x09 << 21;
}
return insn | (value & 0xfffc);
}
static long
extract_bdp (unsigned long insn,
ppc_cpu_t dialect,
int *invalid)
{
if ((dialect & ISA_V2) == 0)
{
if (((insn & (1 << 21)) == 0) == ((insn & (1 << 15)) == 0))
*invalid = 1;
}
else
{
if ((insn & (0x17 << 21)) != (0x07 << 21)
&& (insn & (0x1d << 21)) != (0x19 << 21))
*invalid = 1;
}
return ((insn & 0xfffc) ^ 0x8000) - 0x8000;
}
static inline int
valid_bo_pre_v2 (long value)
{
if ((value & 0x14) == 0)
return 1;
else if ((value & 0x14) == 0x4)
return (value & 0x2) == 0;
else if ((value & 0x14) == 0x10)
return (value & 0x8) == 0;
else
return value == 0x14;
}
static inline int
valid_bo_post_v2 (long value)
{
if ((value & 0x14) == 0)
return (value & 0x1) == 0;
else if ((value & 0x14) == 0x14)
return value == 0x14;
else
return 1;
}
static int
valid_bo (long value, ppc_cpu_t dialect, int extract)
{
int valid_y = valid_bo_pre_v2 (value);
int valid_at = valid_bo_post_v2 (value);
if (extract && dialect == ~(ppc_cpu_t) PPC_OPCODE_ANY)
return valid_y || valid_at;
if ((dialect & ISA_V2) == 0)
return valid_y;
else
return valid_at;
}
static unsigned long
insert_bo (unsigned long insn,
long value,
ppc_cpu_t dialect,
const char **errmsg)
{
if (!valid_bo (value, dialect, 0))
*errmsg = _("invalid conditional option");
else if (PPC_OP (insn) == 19 && (insn & 0x400) && ! (value & 4))
*errmsg = _("invalid counter access");
return insn | ((value & 0x1f) << 21);
}
static long
extract_bo (unsigned long insn,
ppc_cpu_t dialect,
int *invalid)
{
long value;
value = (insn >> 21) & 0x1f;
if (!valid_bo (value, dialect, 1))
*invalid = 1;
return value;
}
static unsigned long
insert_boe (unsigned long insn,
long value,
ppc_cpu_t dialect,
const char **errmsg)
{
if (!valid_bo (value, dialect, 0))
*errmsg = _("invalid conditional option");
else if (PPC_OP (insn) == 19 && (insn & 0x400) && ! (value & 4))
*errmsg = _("invalid counter access");
else if ((value & 1) != 0)
*errmsg = _("attempt to set y bit when using + or - modifier");
return insn | ((value & 0x1f) << 21);
}
static long
extract_boe (unsigned long insn,
ppc_cpu_t dialect,
int *invalid)
{
long value;
value = (insn >> 21) & 0x1f;
if (!valid_bo (value, dialect, 1))
*invalid = 1;
return value & 0x1e;
}
static unsigned long
insert_dcmxs (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
return insn | ((value & 0x1f) << 16) | ((value & 0x20) >> 3) | (value & 0x40);
}
static long
extract_dcmxs (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
return (insn & 0x40) | ((insn << 3) & 0x20) | ((insn >> 16) & 0x1f);
}
static unsigned long
insert_dxd (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
return insn | (value & 0xffc1) | ((value & 0x3e) << 15);
}
static long
extract_dxd (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
unsigned long dxd = (insn & 0xffc1) | ((insn >> 15) & 0x3e);
return (dxd ^ 0x8000) - 0x8000;
}
static unsigned long
insert_dxdn (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
return insert_dxd (insn, -value, dialect, errmsg);
}
static long
extract_dxdn (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
return -extract_dxd (insn, dialect, invalid);
}
static unsigned long
insert_fxm (unsigned long insn,
long value,
ppc_cpu_t dialect,
const char **errmsg)
{
if ((insn & (1 << 20)) != 0)
{
if (value == 0 || (value & -value) != value)
{
*errmsg = _("invalid mask field");
value = 0;
}
}
else if (value > 0
&& (value & -value) == value
&& ((dialect & PPC_OPCODE_POWER4) != 0
|| ((dialect & PPC_OPCODE_ANY) != 0
&& (insn & (0x3ff << 1)) == 19 << 1)))
insn |= 1 << 20;
else if ((insn & (0x3ff << 1)) == 19 << 1)
{
if (value != -1)
*errmsg = _("invalid mfcr mask");
value = 0;
}
return insn | ((value & 0xff) << 12);
}
static long
extract_fxm (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid)
{
long mask = (insn >> 12) & 0xff;
if ((insn & (1 << 20)) != 0)
{
if (mask == 0 || (mask & -mask) != mask)
*invalid = 1;
}
else if ((insn & (0x3ff << 1)) == 19 << 1)
{
if (mask != 0)
*invalid = 1;
else
mask = -1;
}
return mask;
}
static unsigned long
insert_li20 (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
return insn | ((value & 0xf0000) >> 5) | ((value & 0x0f800) << 5) | (value & 0x7ff);
}
static long
extract_li20 (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
long ext = ((insn & 0x4000) == 0x4000) ? 0xfff00000 : 0x00000000;
return ext
| (((insn >> 11) & 0xf) << 16)
| (((insn >> 17) & 0xf) << 12)
| (((insn >> 16) & 0x1) << 11)
| (insn & 0x7ff);
}
static unsigned long
insert_ls (unsigned long insn,
long value,
ppc_cpu_t dialect,
const char **errmsg)
{
if (((insn >> 1) & 0x3ff) == 598)
{
long max_lvalue = (dialect & PPC_OPCODE_POWER4) ? 2 : 1;
if (value > max_lvalue)
{
*errmsg = _("illegal L operand value");
return insn;
}
}
return insn | ((value & 0x3) << 21);
}
static unsigned long
insert_esync (unsigned long insn,
long value,
ppc_cpu_t dialect,
const char **errmsg)
{
unsigned long ls = (insn >> 21) & 0x03;
if (value == 0)
{
if (((dialect & PPC_OPCODE_E6500) != 0 && ls > 1)
|| ((dialect & PPC_OPCODE_POWER9) != 0 && ls > 2))
*errmsg = _("illegal L operand value");
return insn;
}
if ((ls & ~0x1)
|| (((value >> 1) & 0x1) ^ ls) == 0)
*errmsg = _("incompatible L operand value");
return insn | ((value & 0xf) << 16);
}
static unsigned long
insert_mbe (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg)
{
unsigned long uval, mask;
int mb, me, mx, count, last;
uval = value;
if (uval == 0)
{
*errmsg = _("illegal bitmask");
return insn;
}
mb = 0;
me = 32;
if ((uval & 1) != 0)
last = 1;
else
last = 0;
count = 0;
for (mx = 0, mask = 1L << 31; mx < 32; ++mx, mask >>= 1)
{
if ((uval & mask) && !last)
{
++count;
mb = mx;
last = 1;
}
else if (!(uval & mask) && last)
{
++count;
me = mx;
last = 0;
}
}
if (me == 0)
me = 32;
if (count != 2 && (count != 0 || ! last))
*errmsg = _("illegal bitmask");
return insn | (mb << 6) | ((me - 1) << 1);
}
static long
extract_mbe (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid)
{
long ret;
int mb, me;
int i;
*invalid = 1;
mb = (insn >> 6) & 0x1f;
me = (insn >> 1) & 0x1f;
if (mb < me + 1)
{
ret = 0;
for (i = mb; i <= me; i++)
ret |= 1L << (31 - i);
}
else if (mb == me + 1)
ret = ~0;
else
{
ret = ~0;
for (i = me + 1; i < mb; i++)
ret &= ~(1L << (31 - i));
}
return ret;
}
static unsigned long
insert_mb6 (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
return insn | ((value & 0x1f) << 6) | (value & 0x20);
}
static long
extract_mb6 (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
return ((insn >> 6) & 0x1f) | (insn & 0x20);
}
static long
extract_nb (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
long ret;
ret = (insn >> 11) & 0x1f;
if (ret == 0)
ret = 32;
return ret;
}
static unsigned long
insert_nbi (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
long rtvalue = (insn & RT_MASK) >> 21;
long ravalue = (insn & RA_MASK) >> 16;
if (value == 0)
value = 32;
if (rtvalue + (value + 3) / 4 > (rtvalue > ravalue ? ravalue + 32
: ravalue))
*errmsg = _("address register in load range");
return insn | ((value & 0x1f) << 11);
}
static unsigned long
insert_nsi (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
return insn | (-value & 0xffff);
}
static long
extract_nsi (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid)
{
*invalid = 1;
return -(((insn & 0xffff) ^ 0x8000) - 0x8000);
}
static unsigned long
insert_ral (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg)
{
if (value == 0
|| (unsigned long) value == ((insn >> 21) & 0x1f))
*errmsg = "invalid register operand when updating";
return insn | ((value & 0x1f) << 16);
}
static unsigned long
insert_ram (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg)
{
if ((unsigned long) value >= ((insn >> 21) & 0x1f))
*errmsg = _("index register in load range");
return insn | ((value & 0x1f) << 16);
}
static unsigned long
insert_raq (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg)
{
long rtvalue = (insn & RT_MASK) >> 21;
if (value == rtvalue)
*errmsg = _("source and target register operands must be different");
return insn | ((value & 0x1f) << 16);
}
static unsigned long
insert_ras (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg)
{
if (value == 0)
*errmsg = _("invalid register operand when updating");
return insn | ((value & 0x1f) << 16);
}
static unsigned long
insert_rbs (unsigned long insn,
long value ATTRIBUTE_UNUSED,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
return insn | (((insn >> 21) & 0x1f) << 11);
}
static long
extract_rbs (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid)
{
if (((insn >> 21) & 0x1f) != ((insn >> 11) & 0x1f))
*invalid = 1;
return 0;
}
static unsigned long
insert_rbx (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg)
{
long rtvalue = (insn & RT_MASK) >> 21;
if (value == rtvalue)
*errmsg = _("source and target register operands must be different");
return insn | ((value & 0x1f) << 11);
}
static unsigned long
insert_sci8 (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg)
{
unsigned int fill_scale = 0;
unsigned long ui8 = value;
if ((ui8 & 0xffffff00) == 0)
;
else if ((ui8 & 0xffffff00) == 0xffffff00)
fill_scale = 0x400;
else if ((ui8 & 0xffff00ff) == 0)
{
fill_scale = 1 << 8;
ui8 >>= 8;
}
else if ((ui8 & 0xffff00ff) == 0xffff00ff)
{
fill_scale = 0x400 | (1 << 8);
ui8 >>= 8;
}
else if ((ui8 & 0xff00ffff) == 0)
{
fill_scale = 2 << 8;
ui8 >>= 16;
}
else if ((ui8 & 0xff00ffff) == 0xff00ffff)
{
fill_scale = 0x400 | (2 << 8);
ui8 >>= 16;
}
else if ((ui8 & 0x00ffffff) == 0)
{
fill_scale = 3 << 8;
ui8 >>= 24;
}
else if ((ui8 & 0x00ffffff) == 0x00ffffff)
{
fill_scale = 0x400 | (3 << 8);
ui8 >>= 24;
}
else
{
*errmsg = _("illegal immediate value");
ui8 = 0;
}
return insn | fill_scale | (ui8 & 0xff);
}
static long
extract_sci8 (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
int fill = insn & 0x400;
int scale_factor = (insn & 0x300) >> 5;
long value = (insn & 0xff) << scale_factor;
if (fill != 0)
value |= ~((long) 0xff << scale_factor);
return value;
}
static unsigned long
insert_sci8n (unsigned long insn,
long value,
ppc_cpu_t dialect,
const char **errmsg)
{
return insert_sci8 (insn, -value, dialect, errmsg);
}
static long
extract_sci8n (unsigned long insn,
ppc_cpu_t dialect,
int *invalid)
{
return -extract_sci8 (insn, dialect, invalid);
}
static unsigned long
insert_sd4h (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
return insn | ((value & 0x1e) << 7);
}
static long
extract_sd4h (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
return ((insn >> 8) & 0xf) << 1;
}
static unsigned long
insert_sd4w (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
return insn | ((value & 0x3c) << 6);
}
static long
extract_sd4w (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
return ((insn >> 8) & 0xf) << 2;
}
static unsigned long
insert_oimm (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
return insn | (((value - 1) & 0x1f) << 4);
}
static long
extract_oimm (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
return ((insn >> 4) & 0x1f) + 1;
}
static unsigned long
insert_sh6 (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
if (PPC_OP (insn) == 4)
return insn | ((value & 0x1f) << 6) | ((value & 0x20) >> 5);
else
return insn | ((value & 0x1f) << 11) | ((value & 0x20) >> 4);
}
static long
extract_sh6 (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
if (PPC_OP (insn) == 4)
return ((insn >> 6) & 0x1f) | ((insn << 5) & 0x20);
else
return ((insn >> 11) & 0x1f) | ((insn << 4) & 0x20);
}
static unsigned long
insert_spr (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
return insn | ((value & 0x1f) << 16) | ((value & 0x3e0) << 6);
}
static long
extract_spr (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
return ((insn >> 16) & 0x1f) | ((insn >> 6) & 0x3e0);
}
static unsigned long
insert_sprg (unsigned long insn,
long value,
ppc_cpu_t dialect,
const char **errmsg)
{
if (value > 7
|| (value > 3 && (dialect & ALLOW8_SPRG) == 0))
*errmsg = _("invalid sprg number");
if (value <= 3 || (insn & 0x100) != 0)
value |= 0x10;
return insn | ((value & 0x17) << 16);
}
static long
extract_sprg (unsigned long insn,
ppc_cpu_t dialect,
int *invalid)
{
unsigned long val = (insn >> 16) & 0x1f;
if ((val - 0x10 > 3 && (dialect & ALLOW8_SPRG) == 0)
|| (val - 0x10 > 7 && (insn & 0x100) != 0)
|| val <= 3
|| (val & 8) != 0)
*invalid = 1;
return val & 7;
}
static unsigned long
insert_tbr (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg)
{
if (value != 268 && value != 269)
*errmsg = _("invalid tbr number");
return insn | ((value & 0x1f) << 16) | ((value & 0x3e0) << 6);
}
static long
extract_tbr (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid)
{
long ret;
ret = ((insn >> 16) & 0x1f) | ((insn >> 6) & 0x3e0);
if (ret != 268 && ret != 269)
*invalid = 1;
return ret;
}
static unsigned long
insert_xt6 (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
return insn | ((value & 0x1f) << 21) | ((value & 0x20) >> 5);
}
static long
extract_xt6 (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
return ((insn << 5) & 0x20) | ((insn >> 21) & 0x1f);
}
static unsigned long
insert_xtq6 (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
return insn | ((value & 0x1f) << 21) | ((value & 0x20) >> 2);
}
static long
extract_xtq6 (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
return ((insn << 2) & 0x20) | ((insn >> 21) & 0x1f);
}
static unsigned long
insert_xa6 (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
return insn | ((value & 0x1f) << 16) | ((value & 0x20) >> 3);
}
static long
extract_xa6 (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
return ((insn << 3) & 0x20) | ((insn >> 16) & 0x1f);
}
static unsigned long
insert_xb6 (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
return insn | ((value & 0x1f) << 11) | ((value & 0x20) >> 4);
}
static long
extract_xb6 (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
return ((insn << 4) & 0x20) | ((insn >> 11) & 0x1f);
}
static unsigned long
insert_xb6s (unsigned long insn,
long value ATTRIBUTE_UNUSED,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
return insn | (((insn >> 16) & 0x1f) << 11) | (((insn >> 2) & 0x1) << 1);
}
static long
extract_xb6s (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid)
{
if ((((insn >> 16) & 0x1f) != ((insn >> 11) & 0x1f))
|| (((insn >> 2) & 0x1) != ((insn >> 1) & 0x1)))
*invalid = 1;
return 0;
}
static unsigned long
insert_xc6 (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
return insn | ((value & 0x1f) << 6) | ((value & 0x20) >> 2);
}
static long
extract_xc6 (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
return ((insn << 2) & 0x20) | ((insn >> 6) & 0x1f);
}
static unsigned long
insert_dm (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg)
{
if (value != 0 && value != 1)
*errmsg = _("invalid constant");
return insn | (((value) ? 3 : 0) << 8);
}
static long
extract_dm (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid)
{
long value;
value = (insn >> 8) & 3;
if (value != 0 && value != 3)
*invalid = 1;
return (value) ? 1 : 0;
}
static unsigned long
insert_vlesi (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
return insn | ((value & 0xf800) << 10) | (value & 0x7ff);
}
static long
extract_vlesi (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
long value = ((insn >> 10) & 0xf800) | (insn & 0x7ff);
value = (value ^ 0x8000) - 0x8000;
return value;
}
static unsigned long
insert_vlensi (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
value = -value;
return insn | ((value & 0xf800) << 10) | (value & 0x7ff);
}
static long
extract_vlensi (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
long value = ((insn >> 10) & 0xf800) | (insn & 0x7ff);
value = (value ^ 0x8000) - 0x8000;
*invalid = 1;
return -value;
}
static unsigned long
insert_vleui (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
return insn | ((value & 0xf800) << 10) | (value & 0x7ff);
}
static long
extract_vleui (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
return ((insn >> 10) & 0xf800) | (insn & 0x7ff);
}
static unsigned long
insert_vleil (unsigned long insn,
long value,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
return insn | ((value & 0xf800) << 5) | (value & 0x7ff);
}
static long
extract_vleil (unsigned long insn,
ppc_cpu_t dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
return ((insn >> 5) & 0xf800) | (insn & 0x7ff);
}
