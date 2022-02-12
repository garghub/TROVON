static float32 float32_rsf(struct roundingData *roundData, float32 rFn, float32 rFm)
{
return float32_sub(roundData, rFm, rFn);
}
static float32 float32_rdv(struct roundingData *roundData, float32 rFn, float32 rFm)
{
return float32_div(roundData, rFm, rFn);
}
static float32 float32_mvf(struct roundingData *roundData, float32 rFm)
{
return rFm;
}
static float32 float32_mnf(struct roundingData *roundData, float32 rFm)
{
return rFm ^ 0x80000000;
}
static float32 float32_abs(struct roundingData *roundData, float32 rFm)
{
return rFm & 0x7fffffff;
}
unsigned int SingleCPDO(struct roundingData *roundData, const unsigned int opcode, FPREG * rFd)
{
FPA11 *fpa11 = GET_FPA11();
float32 rFm;
unsigned int Fm, opc_mask_shift;
Fm = getFm(opcode);
if (CONSTANT_FM(opcode)) {
rFm = getSingleConstant(Fm);
} else if (fpa11->fType[Fm] == typeSingle) {
rFm = fpa11->fpreg[Fm].fSingle;
} else {
return 0;
}
opc_mask_shift = (opcode & MASK_ARITHMETIC_OPCODE) >> 20;
if (!MONADIC_INSTRUCTION(opcode)) {
unsigned int Fn = getFn(opcode);
float32 rFn;
if (fpa11->fType[Fn] == typeSingle &&
dyadic_single[opc_mask_shift]) {
rFn = fpa11->fpreg[Fn].fSingle;
rFd->fSingle = dyadic_single[opc_mask_shift](roundData, rFn, rFm);
} else {
return 0;
}
} else {
if (monadic_single[opc_mask_shift]) {
rFd->fSingle = monadic_single[opc_mask_shift](roundData, rFm);
} else {
return 0;
}
}
return 1;
}
