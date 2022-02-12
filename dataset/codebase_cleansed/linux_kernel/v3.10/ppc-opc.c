static unsigned long
insert_bat (unsigned long insn,
long value ATTRIBUTE_UNUSED,
int dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
return insn | (((insn >> 21) & 0x1f) << 16);
}
static long
extract_bat (unsigned long insn,
int dialect ATTRIBUTE_UNUSED,
int *invalid)
{
if (((insn >> 21) & 0x1f) != ((insn >> 16) & 0x1f))
*invalid = 1;
return 0;
}
static unsigned long
insert_bba (unsigned long insn,
long value ATTRIBUTE_UNUSED,
int dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
return insn | (((insn >> 16) & 0x1f) << 11);
}
static long
extract_bba (unsigned long insn,
int dialect ATTRIBUTE_UNUSED,
int *invalid)
{
if (((insn >> 16) & 0x1f) != ((insn >> 11) & 0x1f))
*invalid = 1;
return 0;
}
static unsigned long
insert_bd (unsigned long insn,
long value,
int dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
return insn | (value & 0xfffc);
}
static long
extract_bd (unsigned long insn,
int dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
return ((insn & 0xfffc) ^ 0x8000) - 0x8000;
}
static unsigned long
insert_bdm (unsigned long insn,
long value,
int dialect,
const char **errmsg ATTRIBUTE_UNUSED)
{
if ((dialect & PPC_OPCODE_POWER4) == 0)
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
int dialect,
int *invalid)
{
if ((dialect & PPC_OPCODE_POWER4) == 0)
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
int dialect,
const char **errmsg ATTRIBUTE_UNUSED)
{
if ((dialect & PPC_OPCODE_POWER4) == 0)
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
int dialect,
int *invalid)
{
if ((dialect & PPC_OPCODE_POWER4) == 0)
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
static int
valid_bo (long value, int dialect)
{
if ((dialect & PPC_OPCODE_POWER4) == 0)
{
switch (value & 0x14)
{
default:
case 0:
return 1;
case 0x4:
return (value & 0x2) == 0;
case 0x10:
return (value & 0x8) == 0;
case 0x14:
return value == 0x14;
}
}
else
{
if ((value & 0x14) == 0)
return (value & 0x1) == 0;
else if ((value & 0x14) == 0x14)
return value == 0x14;
else
return 1;
}
}
static unsigned long
insert_bo (unsigned long insn,
long value,
int dialect,
const char **errmsg)
{
if (!valid_bo (value, dialect))
*errmsg = _("invalid conditional option");
return insn | ((value & 0x1f) << 21);
}
static long
extract_bo (unsigned long insn,
int dialect,
int *invalid)
{
long value;
value = (insn >> 21) & 0x1f;
if (!valid_bo (value, dialect))
*invalid = 1;
return value;
}
static unsigned long
insert_boe (unsigned long insn,
long value,
int dialect,
const char **errmsg)
{
if (!valid_bo (value, dialect))
*errmsg = _("invalid conditional option");
else if ((value & 1) != 0)
*errmsg = _("attempt to set y bit when using + or - modifier");
return insn | ((value & 0x1f) << 21);
}
static long
extract_boe (unsigned long insn,
int dialect,
int *invalid)
{
long value;
value = (insn >> 21) & 0x1f;
if (!valid_bo (value, dialect))
*invalid = 1;
return value & 0x1e;
}
static unsigned long
insert_dq (unsigned long insn,
long value,
int dialect ATTRIBUTE_UNUSED,
const char **errmsg)
{
if ((value & 0xf) != 0)
*errmsg = _("offset not a multiple of 16");
return insn | (value & 0xfff0);
}
static long
extract_dq (unsigned long insn,
int dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
return ((insn & 0xfff0) ^ 0x8000) - 0x8000;
}
static unsigned long
insert_ev2 (unsigned long insn,
long value,
int dialect ATTRIBUTE_UNUSED,
const char **errmsg)
{
if ((value & 1) != 0)
*errmsg = _("offset not a multiple of 2");
if ((value > 62) != 0)
*errmsg = _("offset greater than 62");
return insn | ((value & 0x3e) << 10);
}
static long
extract_ev2 (unsigned long insn,
int dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
return (insn >> 10) & 0x3e;
}
static unsigned long
insert_ev4 (unsigned long insn,
long value,
int dialect ATTRIBUTE_UNUSED,
const char **errmsg)
{
if ((value & 3) != 0)
*errmsg = _("offset not a multiple of 4");
if ((value > 124) != 0)
*errmsg = _("offset greater than 124");
return insn | ((value & 0x7c) << 9);
}
static long
extract_ev4 (unsigned long insn,
int dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
return (insn >> 9) & 0x7c;
}
static unsigned long
insert_ev8 (unsigned long insn,
long value,
int dialect ATTRIBUTE_UNUSED,
const char **errmsg)
{
if ((value & 7) != 0)
*errmsg = _("offset not a multiple of 8");
if ((value > 248) != 0)
*errmsg = _("offset greater than 248");
return insn | ((value & 0xf8) << 8);
}
static long
extract_ev8 (unsigned long insn,
int dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
return (insn >> 8) & 0xf8;
}
static unsigned long
insert_ds (unsigned long insn,
long value,
int dialect ATTRIBUTE_UNUSED,
const char **errmsg)
{
if ((value & 3) != 0)
*errmsg = _("offset not a multiple of 4");
return insn | (value & 0xfffc);
}
static long
extract_ds (unsigned long insn,
int dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
return ((insn & 0xfffc) ^ 0x8000) - 0x8000;
}
static unsigned long
insert_de (unsigned long insn,
long value,
int dialect ATTRIBUTE_UNUSED,
const char **errmsg)
{
if (value > 2047 || value < -2048)
*errmsg = _("offset not between -2048 and 2047");
return insn | ((value << 4) & 0xfff0);
}
static long
extract_de (unsigned long insn,
int dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
return (insn & 0xfff0) >> 4;
}
static unsigned long
insert_des (unsigned long insn,
long value,
int dialect ATTRIBUTE_UNUSED,
const char **errmsg)
{
if (value > 8191 || value < -8192)
*errmsg = _("offset not between -8192 and 8191");
else if ((value & 3) != 0)
*errmsg = _("offset not a multiple of 4");
return insn | ((value << 2) & 0xfff0);
}
static long
extract_des (unsigned long insn,
int dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
return (((insn >> 2) & 0x3ffc) ^ 0x2000) - 0x2000;
}
static unsigned long
insert_fxm (unsigned long insn,
long value,
int dialect,
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
else if (value == 0)
;
else if ((value & -value) == value
&& ((dialect & PPC_OPCODE_POWER4) != 0
|| ((dialect & PPC_OPCODE_ANY) != 0
&& (insn & (0x3ff << 1)) == 19 << 1)))
insn |= 1 << 20;
else if ((insn & (0x3ff << 1)) == 19 << 1)
{
*errmsg = _("ignoring invalid mfcr mask");
value = 0;
}
return insn | ((value & 0xff) << 12);
}
static long
extract_fxm (unsigned long insn,
int dialect ATTRIBUTE_UNUSED,
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
}
return mask;
}
static unsigned long
insert_li (unsigned long insn,
long value,
int dialect ATTRIBUTE_UNUSED,
const char **errmsg)
{
if ((value & 3) != 0)
*errmsg = _("ignoring least significant bits in branch offset");
return insn | (value & 0x3fffffc);
}
static long
extract_li (unsigned long insn,
int dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
return ((insn & 0x3fffffc) ^ 0x2000000) - 0x2000000;
}
static unsigned long
insert_mbe (unsigned long insn,
long value,
int dialect ATTRIBUTE_UNUSED,
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
int dialect ATTRIBUTE_UNUSED,
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
int dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
return insn | ((value & 0x1f) << 6) | (value & 0x20);
}
static long
extract_mb6 (unsigned long insn,
int dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
return ((insn >> 6) & 0x1f) | (insn & 0x20);
}
static unsigned long
insert_nb (unsigned long insn,
long value,
int dialect ATTRIBUTE_UNUSED,
const char **errmsg)
{
if (value < 0 || value > 32)
*errmsg = _("value out of range");
if (value == 32)
value = 0;
return insn | ((value & 0x1f) << 11);
}
static long
extract_nb (unsigned long insn,
int dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
long ret;
ret = (insn >> 11) & 0x1f;
if (ret == 0)
ret = 32;
return ret;
}
static unsigned long
insert_nsi (unsigned long insn,
long value,
int dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
return insn | (-value & 0xffff);
}
static long
extract_nsi (unsigned long insn,
int dialect ATTRIBUTE_UNUSED,
int *invalid)
{
*invalid = 1;
return -(((insn & 0xffff) ^ 0x8000) - 0x8000);
}
static unsigned long
insert_ral (unsigned long insn,
long value,
int dialect ATTRIBUTE_UNUSED,
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
int dialect ATTRIBUTE_UNUSED,
const char **errmsg)
{
if ((unsigned long) value >= ((insn >> 21) & 0x1f))
*errmsg = _("index register in load range");
return insn | ((value & 0x1f) << 16);
}
static unsigned long
insert_raq (unsigned long insn,
long value,
int dialect ATTRIBUTE_UNUSED,
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
int dialect ATTRIBUTE_UNUSED,
const char **errmsg)
{
if (value == 0)
*errmsg = _("invalid register operand when updating");
return insn | ((value & 0x1f) << 16);
}
static unsigned long
insert_rbs (unsigned long insn,
long value ATTRIBUTE_UNUSED,
int dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
return insn | (((insn >> 21) & 0x1f) << 11);
}
static long
extract_rbs (unsigned long insn,
int dialect ATTRIBUTE_UNUSED,
int *invalid)
{
if (((insn >> 21) & 0x1f) != ((insn >> 11) & 0x1f))
*invalid = 1;
return 0;
}
static unsigned long
insert_rtq (unsigned long insn,
long value,
int dialect ATTRIBUTE_UNUSED,
const char **errmsg)
{
if ((value & 1) != 0)
*errmsg = _("target register operand must be even");
return insn | ((value & 0x1f) << 21);
}
static unsigned long
insert_rsq (unsigned long insn,
long value ATTRIBUTE_UNUSED,
int dialect ATTRIBUTE_UNUSED,
const char **errmsg)
{
if ((value & 1) != 0)
*errmsg = _("source register operand must be even");
return insn | ((value & 0x1f) << 21);
}
static unsigned long
insert_sh6 (unsigned long insn,
long value,
int dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
return insn | ((value & 0x1f) << 11) | ((value & 0x20) >> 4);
}
static long
extract_sh6 (unsigned long insn,
int dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
return ((insn >> 11) & 0x1f) | ((insn << 4) & 0x20);
}
static unsigned long
insert_spr (unsigned long insn,
long value,
int dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
return insn | ((value & 0x1f) << 16) | ((value & 0x3e0) << 6);
}
static long
extract_spr (unsigned long insn,
int dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
return ((insn >> 16) & 0x1f) | ((insn >> 6) & 0x3e0);
}
static unsigned long
insert_sprg (unsigned long insn,
long value,
int dialect,
const char **errmsg)
{
if (value > 7
|| (value > 3
&& (dialect & (PPC_OPCODE_BOOKE | PPC_OPCODE_403)) == 0))
*errmsg = _("invalid sprg number");
if (value <= 3 || (insn & 0x100) != 0)
value |= 0x10;
return insn | ((value & 0x17) << 16);
}
static long
extract_sprg (unsigned long insn,
int dialect,
int *invalid)
{
unsigned long val = (insn >> 16) & 0x1f;
if (val <= 3
|| (val < 0x10 && (insn & 0x100) != 0)
|| (val - 0x10 > 3
&& (dialect & (PPC_OPCODE_BOOKE | PPC_OPCODE_403)) == 0))
*invalid = 1;
return val & 7;
}
static unsigned long
insert_tbr (unsigned long insn,
long value,
int dialect ATTRIBUTE_UNUSED,
const char **errmsg ATTRIBUTE_UNUSED)
{
if (value == 0)
value = TB;
return insn | ((value & 0x1f) << 16) | ((value & 0x3e0) << 6);
}
static long
extract_tbr (unsigned long insn,
int dialect ATTRIBUTE_UNUSED,
int *invalid ATTRIBUTE_UNUSED)
{
long ret;
ret = ((insn >> 16) & 0x1f) | ((insn >> 6) & 0x3e0);
if (ret == TB)
ret = 0;
return ret;
}
