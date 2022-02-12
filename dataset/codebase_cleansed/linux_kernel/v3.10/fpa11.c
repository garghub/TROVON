static void resetFPA11(void)
{
int i;
FPA11 *fpa11 = GET_FPA11();
for (i = 0; i <= 7; i++) {
fpa11->fType[i] = typeNone;
}
fpa11->fpsr = FP_EMULATOR | BIT_AC;
}
int8 SetRoundingMode(const unsigned int opcode)
{
switch (opcode & MASK_ROUNDING_MODE) {
default:
case ROUND_TO_NEAREST:
return float_round_nearest_even;
case ROUND_TO_PLUS_INFINITY:
return float_round_up;
case ROUND_TO_MINUS_INFINITY:
return float_round_down;
case ROUND_TO_ZERO:
return float_round_to_zero;
}
}
int8 SetRoundingPrecision(const unsigned int opcode)
{
#ifdef CONFIG_FPE_NWFPE_XP
switch (opcode & MASK_ROUNDING_PRECISION) {
case ROUND_SINGLE:
return 32;
case ROUND_DOUBLE:
return 64;
case ROUND_EXTENDED:
return 80;
default:
return 80;
}
#endif
return 80;
}
void nwfpe_init_fpa(union fp_state *fp)
{
FPA11 *fpa11 = (FPA11 *)fp;
#ifdef NWFPE_DEBUG
printk("NWFPE: setting up state.\n");
#endif
memset(fpa11, 0, sizeof(FPA11));
resetFPA11();
fpa11->initflag = 1;
}
unsigned int EmulateAll(unsigned int opcode)
{
unsigned int code;
#ifdef NWFPE_DEBUG
printk("NWFPE: emulating opcode %08x\n", opcode);
#endif
code = opcode & 0x00000f00;
if (code == 0x00000100 || code == 0x00000200) {
code = opcode & 0x0e000000;
if (code == 0x0e000000) {
if (opcode & 0x00000010) {
return EmulateCPRT(opcode);
} else {
return EmulateCPDO(opcode);
}
} else if (code == 0x0c000000) {
return EmulateCPDT(opcode);
}
}
return 0;
}
