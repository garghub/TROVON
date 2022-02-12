unsigned int EmulateCPDO(const unsigned int opcode)
{
FPA11 *fpa11 = GET_FPA11();
FPREG *rFd;
unsigned int nType, nDest, nRc;
struct roundingData roundData;
nDest = getDestinationSize(opcode);
if (typeNone == nDest)
return 0;
roundData.mode = SetRoundingMode(opcode);
roundData.precision = SetRoundingPrecision(opcode);
roundData.exception = 0;
if (MONADIC_INSTRUCTION(opcode))
nType = nDest;
else
nType = fpa11->fType[getFn(opcode)];
if (!CONSTANT_FM(opcode)) {
register unsigned int Fm = getFm(opcode);
if (nType < fpa11->fType[Fm]) {
nType = fpa11->fType[Fm];
}
}
rFd = &fpa11->fpreg[getFd(opcode)];
switch (nType) {
case typeSingle:
nRc = SingleCPDO(&roundData, opcode, rFd);
break;
case typeDouble:
nRc = DoubleCPDO(&roundData, opcode, rFd);
break;
#ifdef CONFIG_FPE_NWFPE_XP
case typeExtended:
nRc = ExtendedCPDO(&roundData, opcode, rFd);
break;
#endif
default:
nRc = 0;
}
if (nRc != 0) {
fpa11->fType[getFd(opcode)] = nDest;
#ifdef CONFIG_FPE_NWFPE_XP
if (nDest != nType) {
switch (nDest) {
case typeSingle:
{
if (typeDouble == nType)
rFd->fSingle = float64_to_float32(&roundData, rFd->fDouble);
else
rFd->fSingle = floatx80_to_float32(&roundData, rFd->fExtended);
}
break;
case typeDouble:
{
if (typeSingle == nType)
rFd->fDouble = float32_to_float64(rFd->fSingle);
else
rFd->fDouble = floatx80_to_float64(&roundData, rFd->fExtended);
}
break;
case typeExtended:
{
if (typeSingle == nType)
rFd->fExtended = float32_to_floatx80(rFd->fSingle);
else
rFd->fExtended = float64_to_floatx80(rFd->fDouble);
}
break;
}
}
#else
if (nDest != nType) {
if (nDest == typeSingle)
rFd->fSingle = float64_to_float32(&roundData, rFd->fDouble);
else
rFd->fDouble = float32_to_float64(rFd->fSingle);
}
#endif
}
if (roundData.exception)
float_raise(roundData.exception);
return nRc;
}
