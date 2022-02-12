static unw_word
unw_decode_uleb128 (unsigned char **dpp)
{
unsigned shift = 0;
unw_word byte, result = 0;
unsigned char *bp = *dpp;
while (1)
{
byte = *bp++;
result |= (byte & 0x7f) << shift;
if ((byte & 0x80) == 0)
break;
shift += 7;
}
*dpp = bp;
return result;
}
static unsigned char *
unw_decode_x1 (unsigned char *dp, unsigned char code, void *arg)
{
unsigned char byte1, abreg;
unw_word t, off;
byte1 = *dp++;
t = unw_decode_uleb128 (&dp);
off = unw_decode_uleb128 (&dp);
abreg = (byte1 & 0x7f);
if (byte1 & 0x80)
UNW_DEC_SPILL_SPREL(X1, t, abreg, off, arg);
else
UNW_DEC_SPILL_PSPREL(X1, t, abreg, off, arg);
return dp;
}
static unsigned char *
unw_decode_x2 (unsigned char *dp, unsigned char code, void *arg)
{
unsigned char byte1, byte2, abreg, x, ytreg;
unw_word t;
byte1 = *dp++; byte2 = *dp++;
t = unw_decode_uleb128 (&dp);
abreg = (byte1 & 0x7f);
ytreg = byte2;
x = (byte1 >> 7) & 1;
if ((byte1 & 0x80) == 0 && ytreg == 0)
UNW_DEC_RESTORE(X2, t, abreg, arg);
else
UNW_DEC_SPILL_REG(X2, t, abreg, x, ytreg, arg);
return dp;
}
static unsigned char *
unw_decode_x3 (unsigned char *dp, unsigned char code, void *arg)
{
unsigned char byte1, byte2, abreg, qp;
unw_word t, off;
byte1 = *dp++; byte2 = *dp++;
t = unw_decode_uleb128 (&dp);
off = unw_decode_uleb128 (&dp);
qp = (byte1 & 0x3f);
abreg = (byte2 & 0x7f);
if (byte1 & 0x80)
UNW_DEC_SPILL_SPREL_P(X3, qp, t, abreg, off, arg);
else
UNW_DEC_SPILL_PSPREL_P(X3, qp, t, abreg, off, arg);
return dp;
}
static unsigned char *
unw_decode_x4 (unsigned char *dp, unsigned char code, void *arg)
{
unsigned char byte1, byte2, byte3, qp, abreg, x, ytreg;
unw_word t;
byte1 = *dp++; byte2 = *dp++; byte3 = *dp++;
t = unw_decode_uleb128 (&dp);
qp = (byte1 & 0x3f);
abreg = (byte2 & 0x7f);
x = (byte2 >> 7) & 1;
ytreg = byte3;
if ((byte2 & 0x80) == 0 && byte3 == 0)
UNW_DEC_RESTORE_P(X4, qp, t, abreg, arg);
else
UNW_DEC_SPILL_REG_P(X4, qp, t, abreg, x, ytreg, arg);
return dp;
}
static unsigned char *
unw_decode_r1 (unsigned char *dp, unsigned char code, void *arg)
{
int body = (code & 0x20) != 0;
unw_word rlen;
rlen = (code & 0x1f);
UNW_DEC_PROLOGUE(R1, body, rlen, arg);
return dp;
}
static unsigned char *
unw_decode_r2 (unsigned char *dp, unsigned char code, void *arg)
{
unsigned char byte1, mask, grsave;
unw_word rlen;
byte1 = *dp++;
mask = ((code & 0x7) << 1) | ((byte1 >> 7) & 1);
grsave = (byte1 & 0x7f);
rlen = unw_decode_uleb128 (&dp);
UNW_DEC_PROLOGUE_GR(R2, rlen, mask, grsave, arg);
return dp;
}
static unsigned char *
unw_decode_r3 (unsigned char *dp, unsigned char code, void *arg)
{
unw_word rlen;
rlen = unw_decode_uleb128 (&dp);
UNW_DEC_PROLOGUE(R3, ((code & 0x3) == 1), rlen, arg);
return dp;
}
static unsigned char *
unw_decode_p1 (unsigned char *dp, unsigned char code, void *arg)
{
unsigned char brmask = (code & 0x1f);
UNW_DEC_BR_MEM(P1, brmask, arg);
return dp;
}
static unsigned char *
unw_decode_p2_p5 (unsigned char *dp, unsigned char code, void *arg)
{
if ((code & 0x10) == 0)
{
unsigned char byte1 = *dp++;
UNW_DEC_BR_GR(P2, ((code & 0xf) << 1) | ((byte1 >> 7) & 1),
(byte1 & 0x7f), arg);
}
else if ((code & 0x08) == 0)
{
unsigned char byte1 = *dp++, r, dst;
r = ((code & 0x7) << 1) | ((byte1 >> 7) & 1);
dst = (byte1 & 0x7f);
switch (r)
{
case 0: UNW_DEC_REG_GR(P3, UNW_REG_PSP, dst, arg); break;
case 1: UNW_DEC_REG_GR(P3, UNW_REG_RP, dst, arg); break;
case 2: UNW_DEC_REG_GR(P3, UNW_REG_PFS, dst, arg); break;
case 3: UNW_DEC_REG_GR(P3, UNW_REG_PR, dst, arg); break;
case 4: UNW_DEC_REG_GR(P3, UNW_REG_UNAT, dst, arg); break;
case 5: UNW_DEC_REG_GR(P3, UNW_REG_LC, dst, arg); break;
case 6: UNW_DEC_RP_BR(P3, dst, arg); break;
case 7: UNW_DEC_REG_GR(P3, UNW_REG_RNAT, dst, arg); break;
case 8: UNW_DEC_REG_GR(P3, UNW_REG_BSP, dst, arg); break;
case 9: UNW_DEC_REG_GR(P3, UNW_REG_BSPSTORE, dst, arg); break;
case 10: UNW_DEC_REG_GR(P3, UNW_REG_FPSR, dst, arg); break;
case 11: UNW_DEC_PRIUNAT_GR(P3, dst, arg); break;
default: UNW_DEC_BAD_CODE(r); break;
}
}
else if ((code & 0x7) == 0)
UNW_DEC_SPILL_MASK(P4, dp, arg);
else if ((code & 0x7) == 1)
{
unw_word grmask, frmask, byte1, byte2, byte3;
byte1 = *dp++; byte2 = *dp++; byte3 = *dp++;
grmask = ((byte1 >> 4) & 0xf);
frmask = ((byte1 & 0xf) << 16) | (byte2 << 8) | byte3;
UNW_DEC_FRGR_MEM(P5, grmask, frmask, arg);
}
else
UNW_DEC_BAD_CODE(code);
return dp;
}
static unsigned char *
unw_decode_p6 (unsigned char *dp, unsigned char code, void *arg)
{
int gregs = (code & 0x10) != 0;
unsigned char mask = (code & 0x0f);
if (gregs)
UNW_DEC_GR_MEM(P6, mask, arg);
else
UNW_DEC_FR_MEM(P6, mask, arg);
return dp;
}
static unsigned char *
unw_decode_p7_p10 (unsigned char *dp, unsigned char code, void *arg)
{
unsigned char r, byte1, byte2;
unw_word t, size;
if ((code & 0x10) == 0)
{
r = (code & 0xf);
t = unw_decode_uleb128 (&dp);
switch (r)
{
case 0:
size = unw_decode_uleb128 (&dp);
UNW_DEC_MEM_STACK_F(P7, t, size, arg);
break;
case 1: UNW_DEC_MEM_STACK_V(P7, t, arg); break;
case 2: UNW_DEC_SPILL_BASE(P7, t, arg); break;
case 3: UNW_DEC_REG_SPREL(P7, UNW_REG_PSP, t, arg); break;
case 4: UNW_DEC_REG_WHEN(P7, UNW_REG_RP, t, arg); break;
case 5: UNW_DEC_REG_PSPREL(P7, UNW_REG_RP, t, arg); break;
case 6: UNW_DEC_REG_WHEN(P7, UNW_REG_PFS, t, arg); break;
case 7: UNW_DEC_REG_PSPREL(P7, UNW_REG_PFS, t, arg); break;
case 8: UNW_DEC_REG_WHEN(P7, UNW_REG_PR, t, arg); break;
case 9: UNW_DEC_REG_PSPREL(P7, UNW_REG_PR, t, arg); break;
case 10: UNW_DEC_REG_WHEN(P7, UNW_REG_LC, t, arg); break;
case 11: UNW_DEC_REG_PSPREL(P7, UNW_REG_LC, t, arg); break;
case 12: UNW_DEC_REG_WHEN(P7, UNW_REG_UNAT, t, arg); break;
case 13: UNW_DEC_REG_PSPREL(P7, UNW_REG_UNAT, t, arg); break;
case 14: UNW_DEC_REG_WHEN(P7, UNW_REG_FPSR, t, arg); break;
case 15: UNW_DEC_REG_PSPREL(P7, UNW_REG_FPSR, t, arg); break;
default: UNW_DEC_BAD_CODE(r); break;
}
}
else
{
switch (code & 0xf)
{
case 0x0:
{
r = *dp++;
t = unw_decode_uleb128 (&dp);
switch (r)
{
case 1: UNW_DEC_REG_SPREL(P8, UNW_REG_RP, t, arg); break;
case 2: UNW_DEC_REG_SPREL(P8, UNW_REG_PFS, t, arg); break;
case 3: UNW_DEC_REG_SPREL(P8, UNW_REG_PR, t, arg); break;
case 4: UNW_DEC_REG_SPREL(P8, UNW_REG_LC, t, arg); break;
case 5: UNW_DEC_REG_SPREL(P8, UNW_REG_UNAT, t, arg); break;
case 6: UNW_DEC_REG_SPREL(P8, UNW_REG_FPSR, t, arg); break;
case 7: UNW_DEC_REG_WHEN(P8, UNW_REG_BSP, t, arg); break;
case 8: UNW_DEC_REG_PSPREL(P8, UNW_REG_BSP, t, arg); break;
case 9: UNW_DEC_REG_SPREL(P8, UNW_REG_BSP, t, arg); break;
case 10: UNW_DEC_REG_WHEN(P8, UNW_REG_BSPSTORE, t, arg); break;
case 11: UNW_DEC_REG_PSPREL(P8, UNW_REG_BSPSTORE, t, arg); break;
case 12: UNW_DEC_REG_SPREL(P8, UNW_REG_BSPSTORE, t, arg); break;
case 13: UNW_DEC_REG_WHEN(P8, UNW_REG_RNAT, t, arg); break;
case 14: UNW_DEC_REG_PSPREL(P8, UNW_REG_RNAT, t, arg); break;
case 15: UNW_DEC_REG_SPREL(P8, UNW_REG_RNAT, t, arg); break;
case 16: UNW_DEC_PRIUNAT_WHEN_GR(P8, t, arg); break;
case 17: UNW_DEC_PRIUNAT_PSPREL(P8, t, arg); break;
case 18: UNW_DEC_PRIUNAT_SPREL(P8, t, arg); break;
case 19: UNW_DEC_PRIUNAT_WHEN_MEM(P8, t, arg); break;
default: UNW_DEC_BAD_CODE(r); break;
}
}
break;
case 0x1:
byte1 = *dp++; byte2 = *dp++;
UNW_DEC_GR_GR(P9, (byte1 & 0xf), (byte2 & 0x7f), arg);
break;
case 0xf:
byte1 = *dp++; byte2 = *dp++;
UNW_DEC_ABI(P10, byte1, byte2, arg);
break;
case 0x9:
return unw_decode_x1 (dp, code, arg);
case 0xa:
return unw_decode_x2 (dp, code, arg);
case 0xb:
return unw_decode_x3 (dp, code, arg);
case 0xc:
return unw_decode_x4 (dp, code, arg);
default:
UNW_DEC_BAD_CODE(code);
break;
}
}
return dp;
}
static unsigned char *
unw_decode_b1 (unsigned char *dp, unsigned char code, void *arg)
{
unw_word label = (code & 0x1f);
if ((code & 0x20) != 0)
UNW_DEC_COPY_STATE(B1, label, arg);
else
UNW_DEC_LABEL_STATE(B1, label, arg);
return dp;
}
static unsigned char *
unw_decode_b2 (unsigned char *dp, unsigned char code, void *arg)
{
unw_word t;
t = unw_decode_uleb128 (&dp);
UNW_DEC_EPILOGUE(B2, t, (code & 0x1f), arg);
return dp;
}
static unsigned char *
unw_decode_b3_x4 (unsigned char *dp, unsigned char code, void *arg)
{
unw_word t, ecount, label;
if ((code & 0x10) == 0)
{
t = unw_decode_uleb128 (&dp);
ecount = unw_decode_uleb128 (&dp);
UNW_DEC_EPILOGUE(B3, t, ecount, arg);
}
else if ((code & 0x07) == 0)
{
label = unw_decode_uleb128 (&dp);
if ((code & 0x08) != 0)
UNW_DEC_COPY_STATE(B4, label, arg);
else
UNW_DEC_LABEL_STATE(B4, label, arg);
}
else
switch (code & 0x7)
{
case 1: return unw_decode_x1 (dp, code, arg);
case 2: return unw_decode_x2 (dp, code, arg);
case 3: return unw_decode_x3 (dp, code, arg);
case 4: return unw_decode_x4 (dp, code, arg);
default: UNW_DEC_BAD_CODE(code); break;
}
return dp;
}
static inline unsigned char *
unw_decode (unsigned char *dp, int inside_body, void *arg)
{
unw_decoder decoder;
unsigned char code;
code = *dp++;
decoder = unw_decode_table[inside_body][code >> 5];
dp = (*decoder) (dp, code, arg);
return dp;
}
