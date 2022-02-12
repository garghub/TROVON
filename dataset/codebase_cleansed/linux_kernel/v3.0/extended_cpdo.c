static floatx80 floatx80_rsf(struct roundingData *roundData, floatx80 rFn, floatx80 rFm)
{
return floatx80_sub(roundData, rFm, rFn);
}
static floatx80 floatx80_rdv(struct roundingData *roundData, floatx80 rFn, floatx80 rFm)
{
return floatx80_div(roundData, rFm, rFn);
}
static floatx80 floatx80_mvf(struct roundingData *roundData, floatx80 rFm)
{
return rFm;
}
static floatx80 floatx80_mnf(struct roundingData *roundData, floatx80 rFm)
{
rFm.high ^= 0x8000;
return rFm;
}
static floatx80 floatx80_abs(struct roundingData *roundData, floatx80 rFm)
{
rFm.high &= 0x7fff;
return rFm;
}
unsigned int ExtendedCPDO(struct roundingData *roundData, const unsigned int opcode, FPREG * rFd)
{
FPA11 *fpa11 = GET_FPA11();
floatx80 rFm;
unsigned int Fm, opc_mask_shift;
Fm = getFm(opcode);
if (CONSTANT_FM(opcode)) {
rFm = getExtendedConstant(Fm);
} else {
switch (fpa11->fType[Fm]) {
case typeSingle:
rFm = float32_to_floatx80(fpa11->fpreg[Fm].fSingle);
break;
case typeDouble:
rFm = float64_to_floatx80(fpa11->fpreg[Fm].fDouble);
break;
case typeExtended:
rFm = fpa11->fpreg[Fm].fExtended;
break;
default:
return 0;
}
}
opc_mask_shift = (opcode & MASK_ARITHMETIC_OPCODE) >> 20;
if (!MONADIC_INSTRUCTION(opcode)) {
unsigned int Fn = getFn(opcode);
floatx80 rFn;
switch (fpa11->fType[Fn]) {
case typeSingle:
rFn = float32_to_floatx80(fpa11->fpreg[Fn].fSingle);
break;
case typeDouble:
rFn = float64_to_floatx80(fpa11->fpreg[Fn].fDouble);
break;
case typeExtended:
rFn = fpa11->fpreg[Fn].fExtended;
break;
default:
return 0;
}
if (dyadic_extended[opc_mask_shift]) {
rFd->fExtended = dyadic_extended[opc_mask_shift](roundData, rFn, rFm);
} else {
return 0;
}
} else {
if (monadic_extended[opc_mask_shift]) {
rFd->fExtended = monadic_extended[opc_mask_shift](roundData, rFm);
} else {
return 0;
}
}
return 1;
}
